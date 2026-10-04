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
int vf3_tenpp_large_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08e920u: goto P_0c08e920;
case 0x0c08e922u: goto P_0c08e922;
case 0x0c08e924u: goto P_0c08e924;
case 0x0c08e926u: goto P_0c08e926;
case 0x0c08e928u: goto P_0c08e928;
case 0x0c08e92au: goto P_0c08e92a;
case 0x0c08e92cu: goto P_0c08e92c;
case 0x0c08e92eu: goto P_0c08e92e;
case 0x0c08e930u: goto P_0c08e930;
case 0x0c08e932u: goto P_0c08e932;
case 0x0c08e934u: goto P_0c08e934;
case 0x0c08e936u: goto P_0c08e936;
case 0x0c08e938u: goto P_0c08e938;
case 0x0c08e93au: goto P_0c08e93a;
case 0x0c08e93cu: goto P_0c08e93c;
case 0x0c08e93eu: goto P_0c08e93e;
case 0x0c08e940u: goto P_0c08e940;
case 0x0c08e942u: goto P_0c08e942;
case 0x0c08e944u: goto P_0c08e944;
case 0x0c08e946u: goto P_0c08e946;
case 0x0c08e948u: goto P_0c08e948;
case 0x0c08e94au: goto P_0c08e94a;
case 0x0c08e94cu: goto P_0c08e94c;
case 0x0c08e94eu: goto P_0c08e94e;
case 0x0c08e950u: goto P_0c08e950;
case 0x0c08e952u: goto P_0c08e952;
case 0x0c08e954u: goto P_0c08e954;
case 0x0c08e956u: goto P_0c08e956;
case 0x0c08e958u: goto P_0c08e958;
case 0x0c08e95au: goto P_0c08e95a;
case 0x0c08e95cu: goto P_0c08e95c;
case 0x0c08e95eu: goto P_0c08e95e;
case 0x0c08e960u: goto P_0c08e960;
case 0x0c08e962u: goto P_0c08e962;
case 0x0c08e964u: goto P_0c08e964;
case 0x0c08e966u: goto P_0c08e966;
case 0x0c08e968u: goto P_0c08e968;
case 0x0c08e96au: goto P_0c08e96a;
case 0x0c08e96cu: goto P_0c08e96c;
case 0x0c08e96eu: goto P_0c08e96e;
case 0x0c08e970u: goto P_0c08e970;
case 0x0c08e972u: goto P_0c08e972;
case 0x0c08e974u: goto P_0c08e974;
case 0x0c08e976u: goto P_0c08e976;
case 0x0c08e978u: goto P_0c08e978;
case 0x0c08e97au: goto P_0c08e97a;
case 0x0c08e97cu: goto P_0c08e97c;
case 0x0c08e97eu: goto P_0c08e97e;
case 0x0c08e980u: goto P_0c08e980;
case 0x0c08e982u: goto P_0c08e982;
case 0x0c08e984u: goto P_0c08e984;
case 0x0c08e986u: goto P_0c08e986;
case 0x0c08e988u: goto P_0c08e988;
case 0x0c08e98au: goto P_0c08e98a;
case 0x0c08e98cu: goto P_0c08e98c;
case 0x0c08e98eu: goto P_0c08e98e;
case 0x0c08e990u: goto P_0c08e990;
case 0x0c08e992u: goto P_0c08e992;
case 0x0c08e994u: goto P_0c08e994;
case 0x0c08e996u: goto P_0c08e996;
case 0x0c08e998u: goto P_0c08e998;
case 0x0c08e99au: goto P_0c08e99a;
case 0x0c08e99cu: goto P_0c08e99c;
case 0x0c08e99eu: goto P_0c08e99e;
case 0x0c08e9a0u: goto P_0c08e9a0;
case 0x0c08e9a2u: goto P_0c08e9a2;
case 0x0c08e9a4u: goto P_0c08e9a4;
case 0x0c08e9a6u: goto P_0c08e9a6;
case 0x0c08e9a8u: goto P_0c08e9a8;
case 0x0c08e9aau: goto P_0c08e9aa;
case 0x0c08e9acu: goto P_0c08e9ac;
case 0x0c08e9aeu: goto P_0c08e9ae;
case 0x0c08e9b0u: goto P_0c08e9b0;
case 0x0c08e9b2u: goto P_0c08e9b2;
case 0x0c08e9b4u: goto P_0c08e9b4;
case 0x0c08e9b6u: goto P_0c08e9b6;
case 0x0c08e9b8u: goto P_0c08e9b8;
case 0x0c08e9bau: goto P_0c08e9ba;
case 0x0c08e9bcu: goto P_0c08e9bc;
case 0x0c08e9beu: goto P_0c08e9be;
case 0x0c08e9c0u: goto P_0c08e9c0;
case 0x0c08e9c2u: goto P_0c08e9c2;
case 0x0c08e9c4u: goto P_0c08e9c4;
case 0x0c08e9c6u: goto P_0c08e9c6;
case 0x0c08e9c8u: goto P_0c08e9c8;
case 0x0c08e9cau: goto P_0c08e9ca;
case 0x0c08e9ccu: goto P_0c08e9cc;
case 0x0c08e9ceu: goto P_0c08e9ce;
case 0x0c08e9d0u: goto P_0c08e9d0;
case 0x0c08e9d2u: goto P_0c08e9d2;
case 0x0c08e9d4u: goto P_0c08e9d4;
case 0x0c08e9d6u: goto P_0c08e9d6;
case 0x0c08e9d8u: goto P_0c08e9d8;
case 0x0c08e9dau: goto P_0c08e9da;
case 0x0c08e9dcu: goto P_0c08e9dc;
case 0x0c08e9deu: goto P_0c08e9de;
case 0x0c08e9e0u: goto P_0c08e9e0;
case 0x0c08e9e2u: goto P_0c08e9e2;
case 0x0c08e9e4u: goto P_0c08e9e4;
case 0x0c08e9e6u: goto P_0c08e9e6;
case 0x0c08e9e8u: goto P_0c08e9e8;
case 0x0c08e9eau: goto P_0c08e9ea;
case 0x0c08e9ecu: goto P_0c08e9ec;
case 0x0c08e9eeu: goto P_0c08e9ee;
case 0x0c08e9f0u: goto P_0c08e9f0;
case 0x0c08e9f2u: goto P_0c08e9f2;
case 0x0c08e9f4u: goto P_0c08e9f4;
case 0x0c08e9f6u: goto P_0c08e9f6;
case 0x0c08e9f8u: goto P_0c08e9f8;
case 0x0c08e9fau: goto P_0c08e9fa;
case 0x0c08e9fcu: goto P_0c08e9fc;
case 0x0c08e9feu: goto P_0c08e9fe;
case 0x0c08ea00u: goto P_0c08ea00;
case 0x0c08ea02u: goto P_0c08ea02;
case 0x0c08ea04u: goto P_0c08ea04;
case 0x0c08ea06u: goto P_0c08ea06;
case 0x0c08ea08u: goto P_0c08ea08;
case 0x0c08ea0au: goto P_0c08ea0a;
case 0x0c08ea0cu: goto P_0c08ea0c;
case 0x0c08ea0eu: goto P_0c08ea0e;
case 0x0c08ea10u: goto P_0c08ea10;
case 0x0c08ea12u: goto P_0c08ea12;
case 0x0c08ea14u: goto P_0c08ea14;
case 0x0c08ea16u: goto P_0c08ea16;
case 0x0c08ea18u: goto P_0c08ea18;
case 0x0c08ea1au: goto P_0c08ea1a;
case 0x0c08ea1cu: goto P_0c08ea1c;
case 0x0c08ea1eu: goto P_0c08ea1e;
case 0x0c08ea20u: goto P_0c08ea20;
case 0x0c08ea22u: goto P_0c08ea22;
case 0x0c08ea24u: goto P_0c08ea24;
case 0x0c08ea26u: goto P_0c08ea26;
case 0x0c08ea28u: goto P_0c08ea28;
case 0x0c08ea2au: goto P_0c08ea2a;
case 0x0c08ea2cu: goto P_0c08ea2c;
case 0x0c08ea2eu: goto P_0c08ea2e;
case 0x0c08ea30u: goto P_0c08ea30;
case 0x0c08ea32u: goto P_0c08ea32;
case 0x0c08ea34u: goto P_0c08ea34;
case 0x0c08ea36u: goto P_0c08ea36;
case 0x0c08ea38u: goto P_0c08ea38;
case 0x0c08ea3au: goto P_0c08ea3a;
case 0x0c08ea3cu: goto P_0c08ea3c;
case 0x0c08ea3eu: goto P_0c08ea3e;
case 0x0c08ea40u: goto P_0c08ea40;
case 0x0c08ea42u: goto P_0c08ea42;
case 0x0c08ea44u: goto P_0c08ea44;
case 0x0c08ea46u: goto P_0c08ea46;
case 0x0c08ea48u: goto P_0c08ea48;
case 0x0c08ea4au: goto P_0c08ea4a;
case 0x0c08ea4cu: goto P_0c08ea4c;
case 0x0c08ea4eu: goto P_0c08ea4e;
case 0x0c08ea50u: goto P_0c08ea50;
case 0x0c08ea52u: goto P_0c08ea52;
case 0x0c08ea54u: goto P_0c08ea54;
case 0x0c08ea56u: goto P_0c08ea56;
case 0x0c08ea58u: goto P_0c08ea58;
case 0x0c08ea5au: goto P_0c08ea5a;
case 0x0c08ea5cu: goto P_0c08ea5c;
case 0x0c08ea5eu: goto P_0c08ea5e;
case 0x0c08ea60u: goto P_0c08ea60;
case 0x0c08ea62u: goto P_0c08ea62;
case 0x0c08ea64u: goto P_0c08ea64;
case 0x0c08ea66u: goto P_0c08ea66;
case 0x0c08ea68u: goto P_0c08ea68;
case 0x0c08ea6au: goto P_0c08ea6a;
case 0x0c08ea6cu: goto P_0c08ea6c;
case 0x0c08ea6eu: goto P_0c08ea6e;
case 0x0c08ea70u: goto P_0c08ea70;
case 0x0c08ea72u: goto P_0c08ea72;
case 0x0c08ea74u: goto P_0c08ea74;
case 0x0c08ea76u: goto P_0c08ea76;
case 0x0c08ea78u: goto P_0c08ea78;
case 0x0c08ea7au: goto P_0c08ea7a;
case 0x0c08ea7cu: goto P_0c08ea7c;
case 0x0c08ea7eu: goto P_0c08ea7e;
case 0x0c08ea80u: goto P_0c08ea80;
case 0x0c08ea82u: goto P_0c08ea82;
case 0x0c08ea84u: goto P_0c08ea84;
case 0x0c08ea86u: goto P_0c08ea86;
case 0x0c08ea88u: goto P_0c08ea88;
case 0x0c08ea8au: goto P_0c08ea8a;
case 0x0c08ea8cu: goto P_0c08ea8c;
case 0x0c08ea8eu: goto P_0c08ea8e;
case 0x0c08ea90u: goto P_0c08ea90;
case 0x0c08ea92u: goto P_0c08ea92;
case 0x0c08ea94u: goto P_0c08ea94;
case 0x0c08ea96u: goto P_0c08ea96;
case 0x0c08ea98u: goto P_0c08ea98;
case 0x0c08ea9au: goto P_0c08ea9a;
case 0x0c08ea9cu: goto P_0c08ea9c;
case 0x0c08ea9eu: goto P_0c08ea9e;
case 0x0c08eaa0u: goto P_0c08eaa0;
case 0x0c08eaa2u: goto P_0c08eaa2;
case 0x0c08eaa4u: goto P_0c08eaa4;
case 0x0c08eaa6u: goto P_0c08eaa6;
case 0x0c08eaa8u: goto P_0c08eaa8;
case 0x0c08eaaau: goto P_0c08eaaa;
case 0x0c08eaacu: goto P_0c08eaac;
case 0x0c08eaaeu: goto P_0c08eaae;
case 0x0c08eab0u: goto P_0c08eab0;
case 0x0c08eab2u: goto P_0c08eab2;
case 0x0c08eab4u: goto P_0c08eab4;
case 0x0c08eab6u: goto P_0c08eab6;
case 0x0c08eab8u: goto P_0c08eab8;
case 0x0c08eabau: goto P_0c08eaba;
case 0x0c08eabcu: goto P_0c08eabc;
case 0x0c08eabeu: goto P_0c08eabe;
case 0x0c08eac0u: goto P_0c08eac0;
case 0x0c08eac2u: goto P_0c08eac2;
case 0x0c08eac4u: goto P_0c08eac4;
case 0x0c08eac6u: goto P_0c08eac6;
case 0x0c08eac8u: goto P_0c08eac8;
case 0x0c08eacau: goto P_0c08eaca;
case 0x0c08eaccu: goto P_0c08eacc;
case 0x0c08eaceu: goto P_0c08eace;
case 0x0c08ead0u: goto P_0c08ead0;
case 0x0c08ead2u: goto P_0c08ead2;
case 0x0c08ead4u: goto P_0c08ead4;
case 0x0c08ead6u: goto P_0c08ead6;
case 0x0c08ead8u: goto P_0c08ead8;
case 0x0c08eadau: goto P_0c08eada;
case 0x0c08eadcu: goto P_0c08eadc;
case 0x0c08eadeu: goto P_0c08eade;
case 0x0c08eae0u: goto P_0c08eae0;
case 0x0c08eae2u: goto P_0c08eae2;
case 0x0c08eae4u: goto P_0c08eae4;
case 0x0c08eae6u: goto P_0c08eae6;
case 0x0c08eae8u: goto P_0c08eae8;
case 0x0c08eaeau: goto P_0c08eaea;
case 0x0c08eaecu: goto P_0c08eaec;
case 0x0c08eaeeu: goto P_0c08eaee;
case 0x0c08eaf0u: goto P_0c08eaf0;
case 0x0c08eaf2u: goto P_0c08eaf2;
case 0x0c08eaf4u: goto P_0c08eaf4;
case 0x0c08eaf6u: goto P_0c08eaf6;
case 0x0c08eaf8u: goto P_0c08eaf8;
case 0x0c08eafau: goto P_0c08eafa;
case 0x0c08eafcu: goto P_0c08eafc;
case 0x0c08eafeu: goto P_0c08eafe;
case 0x0c08eb00u: goto P_0c08eb00;
case 0x0c08eb02u: goto P_0c08eb02;
case 0x0c08eb04u: goto P_0c08eb04;
case 0x0c08eb06u: goto P_0c08eb06;
case 0x0c08eb08u: goto P_0c08eb08;
case 0x0c08eb0au: goto P_0c08eb0a;
case 0x0c08eb0cu: goto P_0c08eb0c;
case 0x0c08eb0eu: goto P_0c08eb0e;
case 0x0c08eb10u: goto P_0c08eb10;
case 0x0c08eb12u: goto P_0c08eb12;
case 0x0c08eb14u: goto P_0c08eb14;
case 0x0c08eb16u: goto P_0c08eb16;
case 0x0c08eb18u: goto P_0c08eb18;
case 0x0c08eb1au: goto P_0c08eb1a;
case 0x0c08eb1cu: goto P_0c08eb1c;
case 0x0c08eb1eu: goto P_0c08eb1e;
case 0x0c08eb20u: goto P_0c08eb20;
case 0x0c08eb22u: goto P_0c08eb22;
case 0x0c08eb24u: goto P_0c08eb24;
case 0x0c08eb26u: goto P_0c08eb26;
case 0x0c08eb28u: goto P_0c08eb28;
case 0x0c08eb2au: goto P_0c08eb2a;
case 0x0c08eb2cu: goto P_0c08eb2c;
case 0x0c08eb2eu: goto P_0c08eb2e;
case 0x0c08eb30u: goto P_0c08eb30;
case 0x0c08eb32u: goto P_0c08eb32;
case 0x0c08eb34u: goto P_0c08eb34;
case 0x0c08eb36u: goto P_0c08eb36;
case 0x0c08eb38u: goto P_0c08eb38;
case 0x0c08eb3au: goto P_0c08eb3a;
case 0x0c08eb3cu: goto P_0c08eb3c;
case 0x0c08eb3eu: goto P_0c08eb3e;
case 0x0c08eb40u: goto P_0c08eb40;
case 0x0c08eb42u: goto P_0c08eb42;
case 0x0c08eb44u: goto P_0c08eb44;
case 0x0c08eb46u: goto P_0c08eb46;
case 0x0c08eb48u: goto P_0c08eb48;
case 0x0c08eb4au: goto P_0c08eb4a;
case 0x0c08eb4cu: goto P_0c08eb4c;
case 0x0c08eb4eu: goto P_0c08eb4e;
case 0x0c08eb50u: goto P_0c08eb50;
case 0x0c08eb52u: goto P_0c08eb52;
case 0x0c08eb54u: goto P_0c08eb54;
case 0x0c08eb56u: goto P_0c08eb56;
case 0x0c08eb58u: goto P_0c08eb58;
case 0x0c08eb5au: goto P_0c08eb5a;
case 0x0c08eb5cu: goto P_0c08eb5c;
case 0x0c08eb5eu: goto P_0c08eb5e;
case 0x0c08eb60u: goto P_0c08eb60;
case 0x0c08eb62u: goto P_0c08eb62;
case 0x0c08eb64u: goto P_0c08eb64;
case 0x0c08eb66u: goto P_0c08eb66;
case 0x0c08eb68u: goto P_0c08eb68;
case 0x0c08eb6au: goto P_0c08eb6a;
case 0x0c08eb6cu: goto P_0c08eb6c;
case 0x0c08eb6eu: goto P_0c08eb6e;
case 0x0c08eb70u: goto P_0c08eb70;
case 0x0c08eb72u: goto P_0c08eb72;
case 0x0c08eb74u: goto P_0c08eb74;
case 0x0c08eb76u: goto P_0c08eb76;
case 0x0c08eb78u: goto P_0c08eb78;
case 0x0c08eb7au: goto P_0c08eb7a;
case 0x0c08eb7cu: goto P_0c08eb7c;
case 0x0c08eb7eu: goto P_0c08eb7e;
case 0x0c08eb80u: goto P_0c08eb80;
case 0x0c08eb82u: goto P_0c08eb82;
case 0x0c08eb84u: goto P_0c08eb84;
case 0x0c08eb86u: goto P_0c08eb86;
case 0x0c08eb88u: goto P_0c08eb88;
case 0x0c08eb8au: goto P_0c08eb8a;
case 0x0c08eb8cu: goto P_0c08eb8c;
case 0x0c08eb8eu: goto P_0c08eb8e;
case 0x0c08eb90u: goto P_0c08eb90;
case 0x0c08eb92u: goto P_0c08eb92;
case 0x0c08eb94u: goto P_0c08eb94;
case 0x0c08eb96u: goto P_0c08eb96;
case 0x0c08eb98u: goto P_0c08eb98;
case 0x0c08eb9au: goto P_0c08eb9a;
case 0x0c08eb9cu: goto P_0c08eb9c;
case 0x0c08eb9eu: goto P_0c08eb9e;
case 0x0c08eba0u: goto P_0c08eba0;
case 0x0c08eba2u: goto P_0c08eba2;
case 0x0c08eba4u: goto P_0c08eba4;
case 0x0c08eba6u: goto P_0c08eba6;
case 0x0c08eba8u: goto P_0c08eba8;
case 0x0c08ebaau: goto P_0c08ebaa;
case 0x0c08ebacu: goto P_0c08ebac;
case 0x0c08ebaeu: goto P_0c08ebae;
case 0x0c08ebb0u: goto P_0c08ebb0;
case 0x0c08ebb2u: goto P_0c08ebb2;
case 0x0c08ebb4u: goto P_0c08ebb4;
case 0x0c08ebb6u: goto P_0c08ebb6;
case 0x0c08ebb8u: goto P_0c08ebb8;
case 0x0c091f60u: goto P_0c091f60;
case 0x0c091f62u: goto P_0c091f62;
case 0x0c091f64u: goto P_0c091f64;
case 0x0c091f66u: goto P_0c091f66;
case 0x0c091f68u: goto P_0c091f68;
case 0x0c091f6au: goto P_0c091f6a;
case 0x0c091f6cu: goto P_0c091f6c;
case 0x0c091f6eu: goto P_0c091f6e;
case 0x0c091f70u: goto P_0c091f70;
case 0x0c091f72u: goto P_0c091f72;
case 0x0c091f74u: goto P_0c091f74;
case 0x0c091f76u: goto P_0c091f76;
case 0x0c091f78u: goto P_0c091f78;
case 0x0c091f7au: goto P_0c091f7a;
case 0x0c091f7cu: goto P_0c091f7c;
case 0x0c091f7eu: goto P_0c091f7e;
case 0x0c091f80u: goto P_0c091f80;
case 0x0c091f82u: goto P_0c091f82;
case 0x0c091f84u: goto P_0c091f84;
case 0x0c091f86u: goto P_0c091f86;
case 0x0c091f88u: goto P_0c091f88;
case 0x0c091f8au: goto P_0c091f8a;
case 0x0c091f8cu: goto P_0c091f8c;
case 0x0c091f8eu: goto P_0c091f8e;
case 0x0c091f90u: goto P_0c091f90;
case 0x0c091f92u: goto P_0c091f92;
case 0x0c091f94u: goto P_0c091f94;
case 0x0c091f96u: goto P_0c091f96;
case 0x0c091f98u: goto P_0c091f98;
case 0x0c091f9au: goto P_0c091f9a;
case 0x0c091f9cu: goto P_0c091f9c;
case 0x0c091f9eu: goto P_0c091f9e;
case 0x0c091fa0u: goto P_0c091fa0;
case 0x0c091fa2u: goto P_0c091fa2;
case 0x0c091fa4u: goto P_0c091fa4;
case 0x0c091fa6u: goto P_0c091fa6;
case 0x0c091fa8u: goto P_0c091fa8;
case 0x0c091faau: goto P_0c091faa;
case 0x0c091facu: goto P_0c091fac;
case 0x0c091faeu: goto P_0c091fae;
case 0x0c091fb0u: goto P_0c091fb0;
case 0x0c091fb2u: goto P_0c091fb2;
case 0x0c091fb4u: goto P_0c091fb4;
case 0x0c091fb6u: goto P_0c091fb6;
case 0x0c091fb8u: goto P_0c091fb8;
case 0x0c091fbau: goto P_0c091fba;
case 0x0c091fbcu: goto P_0c091fbc;
case 0x0c091fbeu: goto P_0c091fbe;
case 0x0c091fc0u: goto P_0c091fc0;
case 0x0c091fc2u: goto P_0c091fc2;
case 0x0c091fc4u: goto P_0c091fc4;
case 0x0c091fc6u: goto P_0c091fc6;
case 0x0c091fc8u: goto P_0c091fc8;
case 0x0c091fcau: goto P_0c091fca;
case 0x0c091fccu: goto P_0c091fcc;
case 0x0c091fceu: goto P_0c091fce;
case 0x0c091fd0u: goto P_0c091fd0;
case 0x0c091fd2u: goto P_0c091fd2;
case 0x0c091fd4u: goto P_0c091fd4;
case 0x0c091fd6u: goto P_0c091fd6;
case 0x0c091fd8u: goto P_0c091fd8;
case 0x0c091fdau: goto P_0c091fda;
case 0x0c091fdcu: goto P_0c091fdc;
case 0x0c091fdeu: goto P_0c091fde;
case 0x0c091fe0u: goto P_0c091fe0;
case 0x0c091fe2u: goto P_0c091fe2;
case 0x0c091fe4u: goto P_0c091fe4;
case 0x0c091fe6u: goto P_0c091fe6;
case 0x0c091fe8u: goto P_0c091fe8;
case 0x0c091feau: goto P_0c091fea;
case 0x0c091fecu: goto P_0c091fec;
case 0x0c091feeu: goto P_0c091fee;
case 0x0c091ff0u: goto P_0c091ff0;
case 0x0c091ff2u: goto P_0c091ff2;
case 0x0c091ff4u: goto P_0c091ff4;
case 0x0c091ff6u: goto P_0c091ff6;
case 0x0c091ff8u: goto P_0c091ff8;
case 0x0c091ffau: goto P_0c091ffa;
case 0x0c091ffcu: goto P_0c091ffc;
case 0x0c091ffeu: goto P_0c091ffe;
case 0x0c092000u: goto P_0c092000;
case 0x0c092002u: goto P_0c092002;
case 0x0c092004u: goto P_0c092004;
case 0x0c092006u: goto P_0c092006;
case 0x0c092008u: goto P_0c092008;
case 0x0c09200au: goto P_0c09200a;
case 0x0c09200cu: goto P_0c09200c;
case 0x0c09200eu: goto P_0c09200e;
case 0x0c092010u: goto P_0c092010;
case 0x0c092012u: goto P_0c092012;
case 0x0c092014u: goto P_0c092014;
case 0x0c092016u: goto P_0c092016;
case 0x0c092018u: goto P_0c092018;
case 0x0c09201au: goto P_0c09201a;
case 0x0c09201cu: goto P_0c09201c;
case 0x0c09201eu: goto P_0c09201e;
case 0x0c092020u: goto P_0c092020;
case 0x0c092022u: goto P_0c092022;
case 0x0c092024u: goto P_0c092024;
case 0x0c092026u: goto P_0c092026;
case 0x0c092028u: goto P_0c092028;
case 0x0c092070u: goto P_0c092070;
case 0x0c092072u: goto P_0c092072;
case 0x0c092074u: goto P_0c092074;
case 0x0c092076u: goto P_0c092076;
case 0x0c092078u: goto P_0c092078;
case 0x0c09207au: goto P_0c09207a;
case 0x0c09207cu: goto P_0c09207c;
case 0x0c09207eu: goto P_0c09207e;
case 0x0c092080u: goto P_0c092080;
case 0x0c092082u: goto P_0c092082;
case 0x0c092084u: goto P_0c092084;
case 0x0c092086u: goto P_0c092086;
case 0x0c092088u: goto P_0c092088;
case 0x0c09208au: goto P_0c09208a;
case 0x0c09208cu: goto P_0c09208c;
case 0x0c09208eu: goto P_0c09208e;
case 0x0c092090u: goto P_0c092090;
case 0x0c092092u: goto P_0c092092;
case 0x0c092094u: goto P_0c092094;
case 0x0c092096u: goto P_0c092096;
case 0x0c092098u: goto P_0c092098;
case 0x0c09209au: goto P_0c09209a;
case 0x0c09209cu: goto P_0c09209c;
case 0x0c09209eu: goto P_0c09209e;
case 0x0c0920a0u: goto P_0c0920a0;
case 0x0c0920a2u: goto P_0c0920a2;
case 0x0c0920a4u: goto P_0c0920a4;
case 0x0c0920a6u: goto P_0c0920a6;
case 0x0c0920a8u: goto P_0c0920a8;
case 0x0c0920aau: goto P_0c0920aa;
case 0x0c0920acu: goto P_0c0920ac;
case 0x0c0920aeu: goto P_0c0920ae;
case 0x0c0920b0u: goto P_0c0920b0;
case 0x0c0920b2u: goto P_0c0920b2;
case 0x0c0920b4u: goto P_0c0920b4;
case 0x0c0920b6u: goto P_0c0920b6;
case 0x0c0920b8u: goto P_0c0920b8;
case 0x0c0920bau: goto P_0c0920ba;
case 0x0c0920bcu: goto P_0c0920bc;
case 0x0c0920beu: goto P_0c0920be;
case 0x0c0920c0u: goto P_0c0920c0;
case 0x0c0920c2u: goto P_0c0920c2;
case 0x0c0920c4u: goto P_0c0920c4;
case 0x0c0920c6u: goto P_0c0920c6;
case 0x0c0920c8u: goto P_0c0920c8;
case 0x0c0920cau: goto P_0c0920ca;
case 0x0c0920ccu: goto P_0c0920cc;
case 0x0c0920ceu: goto P_0c0920ce;
case 0x0c0920d0u: goto P_0c0920d0;
case 0x0c0920d2u: goto P_0c0920d2;
case 0x0c0920d4u: goto P_0c0920d4;
case 0x0c0920d6u: goto P_0c0920d6;
case 0x0c0920d8u: goto P_0c0920d8;
case 0x0c0920dau: goto P_0c0920da;
case 0x0c0920dcu: goto P_0c0920dc;
case 0x0c0920deu: goto P_0c0920de;
case 0x0c0920e0u: goto P_0c0920e0;
case 0x0c0920e2u: goto P_0c0920e2;
case 0x0c0920e4u: goto P_0c0920e4;
case 0x0c0920e6u: goto P_0c0920e6;
case 0x0c0920e8u: goto P_0c0920e8;
case 0x0c0920eau: goto P_0c0920ea;
case 0x0c0920ecu: goto P_0c0920ec;
case 0x0c0920eeu: goto P_0c0920ee;
case 0x0c0920f0u: goto P_0c0920f0;
case 0x0c0920f2u: goto P_0c0920f2;
case 0x0c0920f4u: goto P_0c0920f4;
case 0x0c0920f6u: goto P_0c0920f6;
case 0x0c0920f8u: goto P_0c0920f8;
case 0x0c0920fau: goto P_0c0920fa;
case 0x0c0920fcu: goto P_0c0920fc;
case 0x0c0920feu: goto P_0c0920fe;
case 0x0c092100u: goto P_0c092100;
case 0x0c092102u: goto P_0c092102;
case 0x0c092104u: goto P_0c092104;
case 0x0c092106u: goto P_0c092106;
case 0x0c092108u: goto P_0c092108;
case 0x0c09210au: goto P_0c09210a;
case 0x0c09210cu: goto P_0c09210c;
case 0x0c09210eu: goto P_0c09210e;
case 0x0c092110u: goto P_0c092110;
case 0x0c092112u: goto P_0c092112;
case 0x0c092114u: goto P_0c092114;
case 0x0c092116u: goto P_0c092116;
case 0x0c092118u: goto P_0c092118;
case 0x0c09211au: goto P_0c09211a;
case 0x0c09211cu: goto P_0c09211c;
case 0x0c09211eu: goto P_0c09211e;
case 0x0c092120u: goto P_0c092120;
case 0x0c092122u: goto P_0c092122;
case 0x0c092124u: goto P_0c092124;
case 0x0c092126u: goto P_0c092126;
case 0x0c092128u: goto P_0c092128;
case 0x0c09212au: goto P_0c09212a;
case 0x0c09212cu: goto P_0c09212c;
case 0x0c09212eu: goto P_0c09212e;
case 0x0c092130u: goto P_0c092130;
case 0x0c092132u: goto P_0c092132;
case 0x0c092134u: goto P_0c092134;
case 0x0c092136u: goto P_0c092136;
case 0x0c092138u: goto P_0c092138;
case 0x0c09213au: goto P_0c09213a;
case 0x0c09213cu: goto P_0c09213c;
case 0x0c09213eu: goto P_0c09213e;
case 0x0c092140u: goto P_0c092140;
case 0x0c092142u: goto P_0c092142;
case 0x0c092144u: goto P_0c092144;
case 0x0c092146u: goto P_0c092146;
case 0x0c092148u: goto P_0c092148;
case 0x0c09214au: goto P_0c09214a;
case 0x0c09214cu: goto P_0c09214c;
case 0x0c09214eu: goto P_0c09214e;
case 0x0c092150u: goto P_0c092150;
case 0x0c092152u: goto P_0c092152;
case 0x0c092154u: goto P_0c092154;
case 0x0c092156u: goto P_0c092156;
case 0x0c092158u: goto P_0c092158;
case 0x0c09215au: goto P_0c09215a;
case 0x0c092180u: goto P_0c092180;
case 0x0c092182u: goto P_0c092182;
case 0x0c092184u: goto P_0c092184;
case 0x0c092186u: goto P_0c092186;
case 0x0c092188u: goto P_0c092188;
case 0x0c09218au: goto P_0c09218a;
case 0x0c09218cu: goto P_0c09218c;
case 0x0c09218eu: goto P_0c09218e;
case 0x0c092190u: goto P_0c092190;
case 0x0c092192u: goto P_0c092192;
case 0x0c092194u: goto P_0c092194;
case 0x0c092196u: goto P_0c092196;
case 0x0c092198u: goto P_0c092198;
case 0x0c09219au: goto P_0c09219a;
case 0x0c09219cu: goto P_0c09219c;
case 0x0c09219eu: goto P_0c09219e;
case 0x0c0921a0u: goto P_0c0921a0;
case 0x0c0921a2u: goto P_0c0921a2;
case 0x0c0921a4u: goto P_0c0921a4;
case 0x0c0921a6u: goto P_0c0921a6;
case 0x0c0921a8u: goto P_0c0921a8;
case 0x0c0921aau: goto P_0c0921aa;
case 0x0c0921acu: goto P_0c0921ac;
case 0x0c0921aeu: goto P_0c0921ae;
case 0x0c0921b0u: goto P_0c0921b0;
case 0x0c0921b2u: goto P_0c0921b2;
case 0x0c0921b4u: goto P_0c0921b4;
case 0x0c0921b6u: goto P_0c0921b6;
case 0x0c0921b8u: goto P_0c0921b8;
case 0x0c0921bau: goto P_0c0921ba;
case 0x0c0921bcu: goto P_0c0921bc;
case 0x0c0921beu: goto P_0c0921be;
case 0x0c0921c0u: goto P_0c0921c0;
case 0x0c0921c2u: goto P_0c0921c2;
case 0x0c0921c4u: goto P_0c0921c4;
case 0x0c0921c6u: goto P_0c0921c6;
case 0x0c0921c8u: goto P_0c0921c8;
case 0x0c0921cau: goto P_0c0921ca;
case 0x0c0921ccu: goto P_0c0921cc;
case 0x0c0921ceu: goto P_0c0921ce;
case 0x0c0921d0u: goto P_0c0921d0;
case 0x0c0921d2u: goto P_0c0921d2;
case 0x0c0921d4u: goto P_0c0921d4;
case 0x0c0921d6u: goto P_0c0921d6;
case 0x0c0921d8u: goto P_0c0921d8;
case 0x0c0921dau: goto P_0c0921da;
case 0x0c0921dcu: goto P_0c0921dc;
case 0x0c0921deu: goto P_0c0921de;
case 0x0c0921e0u: goto P_0c0921e0;
case 0x0c0921e2u: goto P_0c0921e2;
case 0x0c0921e4u: goto P_0c0921e4;
case 0x0c0921e6u: goto P_0c0921e6;
case 0x0c0921e8u: goto P_0c0921e8;
case 0x0c0921eau: goto P_0c0921ea;
case 0x0c0921ecu: goto P_0c0921ec;
case 0x0c0921eeu: goto P_0c0921ee;
case 0x0c0921f0u: goto P_0c0921f0;
case 0x0c0921f2u: goto P_0c0921f2;
case 0x0c0921f4u: goto P_0c0921f4;
case 0x0c0921f6u: goto P_0c0921f6;
case 0x0c0921f8u: goto P_0c0921f8;
case 0x0c0921fau: goto P_0c0921fa;
case 0x0c0921fcu: goto P_0c0921fc;
case 0x0c0921feu: goto P_0c0921fe;
case 0x0c09460au: goto P_0c09460a;
case 0x0c09460cu: goto P_0c09460c;
case 0x0c09460eu: goto P_0c09460e;
case 0x0c094610u: goto P_0c094610;
case 0x0c094612u: goto P_0c094612;
case 0x0c094614u: goto P_0c094614;
case 0x0c094616u: goto P_0c094616;
case 0x0c094618u: goto P_0c094618;
case 0x0c09461au: goto P_0c09461a;
case 0x0c09461cu: goto P_0c09461c;
case 0x0c09461eu: goto P_0c09461e;
case 0x0c094620u: goto P_0c094620;
case 0x0c094622u: goto P_0c094622;
case 0x0c094624u: goto P_0c094624;
case 0x0c094626u: goto P_0c094626;
case 0x0c094628u: goto P_0c094628;
case 0x0c09462au: goto P_0c09462a;
case 0x0c09462cu: goto P_0c09462c;
case 0x0c09462eu: goto P_0c09462e;
case 0x0c094630u: goto P_0c094630;
case 0x0c094632u: goto P_0c094632;
case 0x0c094634u: goto P_0c094634;
case 0x0c094636u: goto P_0c094636;
case 0x0c094638u: goto P_0c094638;
case 0x0c09463au: goto P_0c09463a;
case 0x0c09463cu: goto P_0c09463c;
case 0x0c09463eu: goto P_0c09463e;
case 0x0c094640u: goto P_0c094640;
case 0x0c094642u: goto P_0c094642;
case 0x0c094644u: goto P_0c094644;
case 0x0c094646u: goto P_0c094646;
case 0x0c094648u: goto P_0c094648;
case 0x0c09464au: goto P_0c09464a;
case 0x0c09464cu: goto P_0c09464c;
case 0x0c09464eu: goto P_0c09464e;
case 0x0c094650u: goto P_0c094650;
case 0x0c094652u: goto P_0c094652;
case 0x0c094654u: goto P_0c094654;
case 0x0c094656u: goto P_0c094656;
case 0x0c094658u: goto P_0c094658;
case 0x0c09465au: goto P_0c09465a;
case 0x0c09465cu: goto P_0c09465c;
case 0x0c094688u: goto P_0c094688;
case 0x0c09468au: goto P_0c09468a;
case 0x0c09468cu: goto P_0c09468c;
case 0x0c09468eu: goto P_0c09468e;
case 0x0c094690u: goto P_0c094690;
case 0x0c094692u: goto P_0c094692;
case 0x0c094694u: goto P_0c094694;
case 0x0c094696u: goto P_0c094696;
case 0x0c094698u: goto P_0c094698;
case 0x0c09469au: goto P_0c09469a;
case 0x0c09469cu: goto P_0c09469c;
case 0x0c09469eu: goto P_0c09469e;
case 0x0c0946a0u: goto P_0c0946a0;
case 0x0c0946a2u: goto P_0c0946a2;
case 0x0c0946a4u: goto P_0c0946a4;
case 0x0c0946a6u: goto P_0c0946a6;
case 0x0c0946a8u: goto P_0c0946a8;
case 0x0c0946aau: goto P_0c0946aa;
case 0x0c0946acu: goto P_0c0946ac;
case 0x0c0946aeu: goto P_0c0946ae;
case 0x0c0946b0u: goto P_0c0946b0;
case 0x0c0946b2u: goto P_0c0946b2;
case 0x0c0946b4u: goto P_0c0946b4;
case 0x0c0946b6u: goto P_0c0946b6;
case 0x0c0946b8u: goto P_0c0946b8;
case 0x0c0946bau: goto P_0c0946ba;
case 0x0c0946bcu: goto P_0c0946bc;
case 0x0c0946beu: goto P_0c0946be;
case 0x0c0946c0u: goto P_0c0946c0;
case 0x0c0946c2u: goto P_0c0946c2;
case 0x0c0946c4u: goto P_0c0946c4;
case 0x0c0946c6u: goto P_0c0946c6;
case 0x0c0946c8u: goto P_0c0946c8;
case 0x0c0946cau: goto P_0c0946ca;
case 0x0c0946ccu: goto P_0c0946cc;
case 0x0c0946ceu: goto P_0c0946ce;
case 0x0c0946d0u: goto P_0c0946d0;
case 0x0c0946d2u: goto P_0c0946d2;
case 0x0c0946d4u: goto P_0c0946d4;
case 0x0c0946d6u: goto P_0c0946d6;
case 0x0c0946d8u: goto P_0c0946d8;
case 0x0c0946dau: goto P_0c0946da;
case 0x0c0946dcu: goto P_0c0946dc;
case 0x0c0946deu: goto P_0c0946de;
case 0x0c0946e0u: goto P_0c0946e0;
case 0x0c0946e2u: goto P_0c0946e2;
case 0x0c0946e4u: goto P_0c0946e4;
case 0x0c0946e6u: goto P_0c0946e6;
case 0x0c0946e8u: goto P_0c0946e8;
case 0x0c0946eau: goto P_0c0946ea;
case 0x0c0946ecu: goto P_0c0946ec;
case 0x0c0946eeu: goto P_0c0946ee;
case 0x0c0946f0u: goto P_0c0946f0;
case 0x0c0946f2u: goto P_0c0946f2;
case 0x0c0946f4u: goto P_0c0946f4;
case 0x0c0946f6u: goto P_0c0946f6;
case 0x0c0946f8u: goto P_0c0946f8;
case 0x0c0946fau: goto P_0c0946fa;
case 0x0c0946fcu: goto P_0c0946fc;
case 0x0c0946feu: goto P_0c0946fe;
case 0x0c094700u: goto P_0c094700;
case 0x0c094702u: goto P_0c094702;
case 0x0c094704u: goto P_0c094704;
case 0x0c094706u: goto P_0c094706;
case 0x0c094708u: goto P_0c094708;
case 0x0c09470au: goto P_0c09470a;
case 0x0c09470cu: goto P_0c09470c;
case 0x0c09470eu: goto P_0c09470e;
case 0x0c094710u: goto P_0c094710;
case 0x0c094712u: goto P_0c094712;
case 0x0c094714u: goto P_0c094714;
case 0x0c094716u: goto P_0c094716;
case 0x0c094718u: goto P_0c094718;
case 0x0c09471au: goto P_0c09471a;
case 0x0c09471cu: goto P_0c09471c;
case 0x0c09471eu: goto P_0c09471e;
case 0x0c094720u: goto P_0c094720;
case 0x0c094722u: goto P_0c094722;
case 0x0c094724u: goto P_0c094724;
case 0x0c094726u: goto P_0c094726;
case 0x0c094728u: goto P_0c094728;
case 0x0c09472au: goto P_0c09472a;
case 0x0c09472cu: goto P_0c09472c;
case 0x0c09472eu: goto P_0c09472e;
case 0x0c094730u: goto P_0c094730;
case 0x0c094732u: goto P_0c094732;
case 0x0c094734u: goto P_0c094734;
case 0x0c094736u: goto P_0c094736;
case 0x0c094738u: goto P_0c094738;
case 0x0c09473au: goto P_0c09473a;
case 0x0c09473cu: goto P_0c09473c;
case 0x0c09473eu: goto P_0c09473e;
case 0x0c094740u: goto P_0c094740;
case 0x0c094742u: goto P_0c094742;
case 0x0c094744u: goto P_0c094744;
case 0x0c094746u: goto P_0c094746;
case 0x0c094748u: goto P_0c094748;
case 0x0c09474au: goto P_0c09474a;
case 0x0c09474cu: goto P_0c09474c;
case 0x0c09474eu: goto P_0c09474e;
case 0x0c094750u: goto P_0c094750;
case 0x0c094752u: goto P_0c094752;
case 0x0c094754u: goto P_0c094754;
case 0x0c094756u: goto P_0c094756;
case 0x0c094758u: goto P_0c094758;
case 0x0c09477cu: goto P_0c09477c;
case 0x0c09477eu: goto P_0c09477e;
case 0x0c094780u: goto P_0c094780;
case 0x0c094782u: goto P_0c094782;
case 0x0c094784u: goto P_0c094784;
case 0x0c094786u: goto P_0c094786;
case 0x0c094788u: goto P_0c094788;
case 0x0c09478au: goto P_0c09478a;
case 0x0c09478cu: goto P_0c09478c;
case 0x0c09478eu: goto P_0c09478e;
case 0x0c094790u: goto P_0c094790;
case 0x0c094792u: goto P_0c094792;
case 0x0c094794u: goto P_0c094794;
case 0x0c094796u: goto P_0c094796;
case 0x0c094798u: goto P_0c094798;
case 0x0c09479au: goto P_0c09479a;
case 0x0c09479cu: goto P_0c09479c;
case 0x0c09479eu: goto P_0c09479e;
case 0x0c0947a0u: goto P_0c0947a0;
case 0x0c0947a2u: goto P_0c0947a2;
case 0x0c0947a4u: goto P_0c0947a4;
case 0x0c0947a6u: goto P_0c0947a6;
case 0x0c0947a8u: goto P_0c0947a8;
case 0x0c0947aau: goto P_0c0947aa;
case 0x0c0947acu: goto P_0c0947ac;
case 0x0c0947aeu: goto P_0c0947ae;
case 0x0c0947b0u: goto P_0c0947b0;
case 0x0c0947b2u: goto P_0c0947b2;
case 0x0c0947b4u: goto P_0c0947b4;
case 0x0c0947b6u: goto P_0c0947b6;
case 0x0c0947b8u: goto P_0c0947b8;
case 0x0c0947bau: goto P_0c0947ba;
case 0x0c0947bcu: goto P_0c0947bc;
case 0x0c0947beu: goto P_0c0947be;
case 0x0c0947c0u: goto P_0c0947c0;
case 0x0c0947c2u: goto P_0c0947c2;
case 0x0c0947c4u: goto P_0c0947c4;
case 0x0c0947c6u: goto P_0c0947c6;
case 0x0c0947c8u: goto P_0c0947c8;
case 0x0c0947cau: goto P_0c0947ca;
case 0x0c0947ccu: goto P_0c0947cc;
case 0x0c0947ceu: goto P_0c0947ce;
case 0x0c0947d0u: goto P_0c0947d0;
case 0x0c0947d2u: goto P_0c0947d2;
case 0x0c0947d4u: goto P_0c0947d4;
case 0x0c0947d6u: goto P_0c0947d6;
case 0x0c0947d8u: goto P_0c0947d8;
case 0x0c0947dau: goto P_0c0947da;
case 0x0c0947dcu: goto P_0c0947dc;
case 0x0c0947deu: goto P_0c0947de;
case 0x0c0947e0u: goto P_0c0947e0;
case 0x0c0947e2u: goto P_0c0947e2;
case 0x0c0947e4u: goto P_0c0947e4;
case 0x0c0947e6u: goto P_0c0947e6;
case 0x0c0947e8u: goto P_0c0947e8;
case 0x0c0947eau: goto P_0c0947ea;
case 0x0c0947ecu: goto P_0c0947ec;
case 0x0c0947eeu: goto P_0c0947ee;
case 0x0c0947f0u: goto P_0c0947f0;
case 0x0c0947f2u: goto P_0c0947f2;
case 0x0c0947f4u: goto P_0c0947f4;
case 0x0c0947f6u: goto P_0c0947f6;
case 0x0c0947f8u: goto P_0c0947f8;
case 0x0c0947fau: goto P_0c0947fa;
case 0x0c0947fcu: goto P_0c0947fc;
case 0x0c0947feu: goto P_0c0947fe;
case 0x0c094800u: goto P_0c094800;
case 0x0c094802u: goto P_0c094802;
case 0x0c094804u: goto P_0c094804;
case 0x0c094806u: goto P_0c094806;
case 0x0c094808u: goto P_0c094808;
case 0x0c09480au: goto P_0c09480a;
case 0x0c09480cu: goto P_0c09480c;
case 0x0c09480eu: goto P_0c09480e;
case 0x0c094810u: goto P_0c094810;
case 0x0c094812u: goto P_0c094812;
case 0x0c094814u: goto P_0c094814;
case 0x0c094816u: goto P_0c094816;
case 0x0c094818u: goto P_0c094818;
case 0x0c09481au: goto P_0c09481a;
case 0x0c09481cu: goto P_0c09481c;
case 0x0c09481eu: goto P_0c09481e;
case 0x0c094820u: goto P_0c094820;
case 0x0c094822u: goto P_0c094822;
case 0x0c094824u: goto P_0c094824;
case 0x0c094826u: goto P_0c094826;
case 0x0c094828u: goto P_0c094828;
case 0x0c09482au: goto P_0c09482a;
case 0x0c09482cu: goto P_0c09482c;
case 0x0c09482eu: goto P_0c09482e;
case 0x0c094830u: goto P_0c094830;
case 0x0c094832u: goto P_0c094832;
case 0x0c094834u: goto P_0c094834;
case 0x0c094836u: goto P_0c094836;
case 0x0c094838u: goto P_0c094838;
case 0x0c09483au: goto P_0c09483a;
case 0x0c09483cu: goto P_0c09483c;
case 0x0c09483eu: goto P_0c09483e;
case 0x0c094840u: goto P_0c094840;
case 0x0c094842u: goto P_0c094842;
case 0x0c094844u: goto P_0c094844;
case 0x0c094846u: goto P_0c094846;
case 0x0c094848u: goto P_0c094848;
case 0x0c09484au: goto P_0c09484a;
case 0x0c09484cu: goto P_0c09484c;
case 0x0c09484eu: goto P_0c09484e;
case 0x0c094850u: goto P_0c094850;
case 0x0c094852u: goto P_0c094852;
case 0x0c094854u: goto P_0c094854;
case 0x0c094856u: goto P_0c094856;
case 0x0c094858u: goto P_0c094858;
case 0x0c09485au: goto P_0c09485a;
case 0x0c09485cu: goto P_0c09485c;
case 0x0c0ae2dcu: goto P_0c0ae2dc;
case 0x0c0ae2deu: goto P_0c0ae2de;
case 0x0c0ae2e0u: goto P_0c0ae2e0;
case 0x0c0ae2e2u: goto P_0c0ae2e2;
case 0x0c0ae2e4u: goto P_0c0ae2e4;
case 0x0c0ae2e6u: goto P_0c0ae2e6;
case 0x0c0ae2e8u: goto P_0c0ae2e8;
case 0x0c0ae2eau: goto P_0c0ae2ea;
case 0x0c0ae2ecu: goto P_0c0ae2ec;
case 0x0c0ae2eeu: goto P_0c0ae2ee;
case 0x0c0ae2f0u: goto P_0c0ae2f0;
case 0x0c0ae2f2u: goto P_0c0ae2f2;
case 0x0c0ae2f4u: goto P_0c0ae2f4;
case 0x0c0ae2f6u: goto P_0c0ae2f6;
case 0x0c0ae2f8u: goto P_0c0ae2f8;
case 0x0c0ae2fau: goto P_0c0ae2fa;
case 0x0c0ae2fcu: goto P_0c0ae2fc;
case 0x0c0ae2feu: goto P_0c0ae2fe;
case 0x0c0ae300u: goto P_0c0ae300;
case 0x0c0ae318u: goto P_0c0ae318;
case 0x0c0ae31au: goto P_0c0ae31a;
case 0x0c0ae31cu: goto P_0c0ae31c;
case 0x0c0ae31eu: goto P_0c0ae31e;
case 0x0c0ae320u: goto P_0c0ae320;
case 0x0c0ae322u: goto P_0c0ae322;
case 0x0c0ae324u: goto P_0c0ae324;
case 0x0c0ae326u: goto P_0c0ae326;
case 0x0c0ae328u: goto P_0c0ae328;
case 0x0c0ae32au: goto P_0c0ae32a;
case 0x0c0ae32cu: goto P_0c0ae32c;
case 0x0c0ae32eu: goto P_0c0ae32e;
case 0x0c0ae330u: goto P_0c0ae330;
case 0x0c0ae332u: goto P_0c0ae332;
case 0x0c0ae334u: goto P_0c0ae334;
case 0x0c0ae336u: goto P_0c0ae336;
case 0x0c0ae338u: goto P_0c0ae338;
case 0x0c0ae33au: goto P_0c0ae33a;
case 0x0c0ae33cu: goto P_0c0ae33c;
case 0x0c0ae33eu: goto P_0c0ae33e;
case 0x0c0ae340u: goto P_0c0ae340;
case 0x0c0ae342u: goto P_0c0ae342;
case 0x0c0ae344u: goto P_0c0ae344;
case 0x0c0ae346u: goto P_0c0ae346;
case 0x0c0ae348u: goto P_0c0ae348;
case 0x0c0ae34au: goto P_0c0ae34a;
case 0x0c0ae34cu: goto P_0c0ae34c;
case 0x0c0ae34eu: goto P_0c0ae34e;
case 0x0c0ae350u: goto P_0c0ae350;
case 0x0c0ae352u: goto P_0c0ae352;
case 0x0c0ae354u: goto P_0c0ae354;
case 0x0c0ae356u: goto P_0c0ae356;
case 0x0c0ae358u: goto P_0c0ae358;
case 0x0c0ae35au: goto P_0c0ae35a;
case 0x0c0ae35cu: goto P_0c0ae35c;
case 0x0c0ae35eu: goto P_0c0ae35e;
case 0x0c0ae360u: goto P_0c0ae360;
case 0x0c0ae362u: goto P_0c0ae362;
case 0x0c0ae364u: goto P_0c0ae364;
case 0x0c0ae366u: goto P_0c0ae366;
case 0x0c0ae368u: goto P_0c0ae368;
case 0x0c0ae36au: goto P_0c0ae36a;
case 0x0c0ae36cu: goto P_0c0ae36c;
case 0x0c0ae36eu: goto P_0c0ae36e;
case 0x0c0ae370u: goto P_0c0ae370;
case 0x0c0ae372u: goto P_0c0ae372;
case 0x0c0ae374u: goto P_0c0ae374;
case 0x0c0ae376u: goto P_0c0ae376;
case 0x0c0ae378u: goto P_0c0ae378;
case 0x0c0ae37au: goto P_0c0ae37a;
case 0x0c0ae37cu: goto P_0c0ae37c;
case 0x0c0ae37eu: goto P_0c0ae37e;
case 0x0c0ae380u: goto P_0c0ae380;
case 0x0c0ae382u: goto P_0c0ae382;
case 0x0c0ae384u: goto P_0c0ae384;
case 0x0c0ae386u: goto P_0c0ae386;
case 0x0c0ae388u: goto P_0c0ae388;
case 0x0c0ae38au: goto P_0c0ae38a;
case 0x0c0ae38cu: goto P_0c0ae38c;
case 0x0c0ae38eu: goto P_0c0ae38e;
case 0x0c0ae390u: goto P_0c0ae390;
case 0x0c0ae392u: goto P_0c0ae392;
case 0x0c0ae394u: goto P_0c0ae394;
case 0x0c0ae396u: goto P_0c0ae396;
case 0x0c0ae398u: goto P_0c0ae398;
case 0x0c0ae39au: goto P_0c0ae39a;
case 0x0c0ae39cu: goto P_0c0ae39c;
case 0x0c0ae39eu: goto P_0c0ae39e;
case 0x0c0ae3a0u: goto P_0c0ae3a0;
case 0x0c0ae3a2u: goto P_0c0ae3a2;
case 0x0c0ae3a4u: goto P_0c0ae3a4;
case 0x0c0ae3a6u: goto P_0c0ae3a6;
case 0x0c0ae3a8u: goto P_0c0ae3a8;
case 0x0c0ae3aau: goto P_0c0ae3aa;
case 0x0c0ae3acu: goto P_0c0ae3ac;
case 0x0c0ae3aeu: goto P_0c0ae3ae;
case 0x0c0ae3b0u: goto P_0c0ae3b0;
case 0x0c0ae3b2u: goto P_0c0ae3b2;
case 0x0c0ae3b4u: goto P_0c0ae3b4;
case 0x0c0ae3b6u: goto P_0c0ae3b6;
case 0x0c0ae3b8u: goto P_0c0ae3b8;
case 0x0c0ae3bau: goto P_0c0ae3ba;
case 0x0c0ae3bcu: goto P_0c0ae3bc;
case 0x0c0ae3beu: goto P_0c0ae3be;
case 0x0c0ae3c0u: goto P_0c0ae3c0;
case 0x0c0ae3c2u: goto P_0c0ae3c2;
case 0x0c0ae3c4u: goto P_0c0ae3c4;
case 0x0c0ae3c6u: goto P_0c0ae3c6;
case 0x0c0ae3c8u: goto P_0c0ae3c8;
case 0x0c0ae3cau: goto P_0c0ae3ca;
case 0x0c0ae3ccu: goto P_0c0ae3cc;
case 0x0c0ae3ceu: goto P_0c0ae3ce;
case 0x0c0ae3d0u: goto P_0c0ae3d0;
case 0x0c0ae3d2u: goto P_0c0ae3d2;
case 0x0c0ae3d4u: goto P_0c0ae3d4;
case 0x0c0ae3d6u: goto P_0c0ae3d6;
case 0x0c0ae3d8u: goto P_0c0ae3d8;
case 0x0c0ae3dau: goto P_0c0ae3da;
case 0x0c0ae3dcu: goto P_0c0ae3dc;
case 0x0c0ae3deu: goto P_0c0ae3de;
case 0x0c0ae3e0u: goto P_0c0ae3e0;
case 0x0c0ae3e2u: goto P_0c0ae3e2;
case 0x0c0ae3e4u: goto P_0c0ae3e4;
case 0x0c0ae3e6u: goto P_0c0ae3e6;
case 0x0c0ae3e8u: goto P_0c0ae3e8;
case 0x0c0ae3eau: goto P_0c0ae3ea;
case 0x0c0ae3ecu: goto P_0c0ae3ec;
case 0x0c0ae3eeu: goto P_0c0ae3ee;
case 0x0c0ae3f0u: goto P_0c0ae3f0;
case 0x0c0ae3f2u: goto P_0c0ae3f2;
case 0x0c0ae3f4u: goto P_0c0ae3f4;
case 0x0c0ae3f6u: goto P_0c0ae3f6;
case 0x0c0ae3f8u: goto P_0c0ae3f8;
case 0x0c0ae3fau: goto P_0c0ae3fa;
case 0x0c0ae3fcu: goto P_0c0ae3fc;
case 0x0c0ae3feu: goto P_0c0ae3fe;
case 0x0c0ae400u: goto P_0c0ae400;
case 0x0c0ae402u: goto P_0c0ae402;
case 0x0c0ae404u: goto P_0c0ae404;
case 0x0c0ae406u: goto P_0c0ae406;
case 0x0c0ae408u: goto P_0c0ae408;
case 0x0c0ae40au: goto P_0c0ae40a;
case 0x0c0ae40cu: goto P_0c0ae40c;
case 0x0c0ae40eu: goto P_0c0ae40e;
case 0x0c0ae410u: goto P_0c0ae410;
case 0x0c0ae412u: goto P_0c0ae412;
case 0x0c0ae414u: goto P_0c0ae414;
case 0x0c0ae416u: goto P_0c0ae416;
case 0x0c0ae418u: goto P_0c0ae418;
case 0x0c0ae41au: goto P_0c0ae41a;
case 0x0c0ae41cu: goto P_0c0ae41c;
case 0x0c0ae41eu: goto P_0c0ae41e;
case 0x0c0ae420u: goto P_0c0ae420;
case 0x0c0ae422u: goto P_0c0ae422;
case 0x0c0ae424u: goto P_0c0ae424;
case 0x0c0ae52cu: goto P_0c0ae52c;
case 0x0c0ae52eu: goto P_0c0ae52e;
case 0x0c0ae530u: goto P_0c0ae530;
case 0x0c0ae532u: goto P_0c0ae532;
case 0x0c0ae534u: goto P_0c0ae534;
case 0x0c0ae536u: goto P_0c0ae536;
case 0x0c0ae538u: goto P_0c0ae538;
case 0x0c0ae53au: goto P_0c0ae53a;
case 0x0c0ae53cu: goto P_0c0ae53c;
case 0x0c0ae53eu: goto P_0c0ae53e;
case 0x0c0ae540u: goto P_0c0ae540;
case 0x0c0ae542u: goto P_0c0ae542;
case 0x0c0ae544u: goto P_0c0ae544;
case 0x0c0ae546u: goto P_0c0ae546;
case 0x0c0ae548u: goto P_0c0ae548;
case 0x0c0ae54au: goto P_0c0ae54a;
case 0x0c0ae54cu: goto P_0c0ae54c;
case 0x0c0ae54eu: goto P_0c0ae54e;
case 0x0c0ae550u: goto P_0c0ae550;
case 0x0c0ae552u: goto P_0c0ae552;
case 0x0c0ae554u: goto P_0c0ae554;
case 0x0c0ae556u: goto P_0c0ae556;
case 0x0c0ae558u: goto P_0c0ae558;
case 0x0c0ae55au: goto P_0c0ae55a;
case 0x0c0ae55cu: goto P_0c0ae55c;
case 0x0c0ae55eu: goto P_0c0ae55e;
case 0x0c0ae560u: goto P_0c0ae560;
case 0x0c0ae562u: goto P_0c0ae562;
case 0x0c0ae564u: goto P_0c0ae564;
case 0x0c0ae566u: goto P_0c0ae566;
case 0x0c0ae568u: goto P_0c0ae568;
case 0x0c0ae56au: goto P_0c0ae56a;
case 0x0c0ae56cu: goto P_0c0ae56c;
case 0x0c0ae5a0u: goto P_0c0ae5a0;
case 0x0c0ae5a2u: goto P_0c0ae5a2;
case 0x0c0ae5a4u: goto P_0c0ae5a4;
case 0x0c0ae5a6u: goto P_0c0ae5a6;
case 0x0c0ae5a8u: goto P_0c0ae5a8;
case 0x0c0ae5aau: goto P_0c0ae5aa;
case 0x0c0ae5acu: goto P_0c0ae5ac;
case 0x0c0ae5aeu: goto P_0c0ae5ae;
case 0x0c0ae5b0u: goto P_0c0ae5b0;
case 0x0c0ae5b2u: goto P_0c0ae5b2;
case 0x0c0ae5b4u: goto P_0c0ae5b4;
case 0x0c0ae5b6u: goto P_0c0ae5b6;
case 0x0c0ae5b8u: goto P_0c0ae5b8;
case 0x0c0ae5bau: goto P_0c0ae5ba;
case 0x0c0ae5bcu: goto P_0c0ae5bc;
case 0x0c0ae5beu: goto P_0c0ae5be;
case 0x0c0ae5c0u: goto P_0c0ae5c0;
case 0x0c0ae5c2u: goto P_0c0ae5c2;
case 0x0c0ae5c4u: goto P_0c0ae5c4;
case 0x0c0ae5c6u: goto P_0c0ae5c6;
case 0x0c0ae5c8u: goto P_0c0ae5c8;
case 0x0c0ae5cau: goto P_0c0ae5ca;
case 0x0c0ae5ccu: goto P_0c0ae5cc;
case 0x0c0ae5ceu: goto P_0c0ae5ce;
case 0x0c0ae5d0u: goto P_0c0ae5d0;
case 0x0c0ae5d2u: goto P_0c0ae5d2;
case 0x0c0ae5d4u: goto P_0c0ae5d4;
case 0x0c0ae5d6u: goto P_0c0ae5d6;
case 0x0c0ae5d8u: goto P_0c0ae5d8;
case 0x0c0ae5dau: goto P_0c0ae5da;
case 0x0c0ae5dcu: goto P_0c0ae5dc;
case 0x0c0ae5deu: goto P_0c0ae5de;
case 0x0c0ae5e0u: goto P_0c0ae5e0;
case 0x0c0ae5e2u: goto P_0c0ae5e2;
case 0x0c0ae5e4u: goto P_0c0ae5e4;
case 0x0c0ae5e6u: goto P_0c0ae5e6;
case 0x0c0ae5e8u: goto P_0c0ae5e8;
case 0x0c0ae5eau: goto P_0c0ae5ea;
case 0x0c0ae5ecu: goto P_0c0ae5ec;
case 0x0c0ae5eeu: goto P_0c0ae5ee;
case 0x0c0ae5f0u: goto P_0c0ae5f0;
case 0x0c0ae5f2u: goto P_0c0ae5f2;
case 0x0c0ae5f4u: goto P_0c0ae5f4;
case 0x0c0ae5f6u: goto P_0c0ae5f6;
case 0x0c0ae5f8u: goto P_0c0ae5f8;
case 0x0c0ae5fau: goto P_0c0ae5fa;
case 0x0c0ae5fcu: goto P_0c0ae5fc;
case 0x0c0ae5feu: goto P_0c0ae5fe;
case 0x0c0ae600u: goto P_0c0ae600;
case 0x0c0ae602u: goto P_0c0ae602;
case 0x0c0ae604u: goto P_0c0ae604;
case 0x0c0ae606u: goto P_0c0ae606;
case 0x0c0ae608u: goto P_0c0ae608;
case 0x0c0ae60au: goto P_0c0ae60a;
case 0x0c0ae60cu: goto P_0c0ae60c;
case 0x0c0ae60eu: goto P_0c0ae60e;
case 0x0c0ae610u: goto P_0c0ae610;
case 0x0c0ae612u: goto P_0c0ae612;
case 0x0c0ae614u: goto P_0c0ae614;
case 0x0c0ae616u: goto P_0c0ae616;
case 0x0c0ae618u: goto P_0c0ae618;
case 0x0c0ae61au: goto P_0c0ae61a;
case 0x0c0ae61cu: goto P_0c0ae61c;
case 0x0c0ae61eu: goto P_0c0ae61e;
case 0x0c0ae620u: goto P_0c0ae620;
case 0x0c0ae622u: goto P_0c0ae622;
case 0x0c0ae624u: goto P_0c0ae624;
case 0x0c0ae626u: goto P_0c0ae626;
case 0x0c0ae628u: goto P_0c0ae628;
case 0x0c0ae62au: goto P_0c0ae62a;
case 0x0c0ae62cu: goto P_0c0ae62c;
case 0x0c0ae62eu: goto P_0c0ae62e;
case 0x0c0ae630u: goto P_0c0ae630;
case 0x0c0ae632u: goto P_0c0ae632;
case 0x0c0ae634u: goto P_0c0ae634;
case 0x0c0ae636u: goto P_0c0ae636;
case 0x0c0ae638u: goto P_0c0ae638;
case 0x0c0ae63au: goto P_0c0ae63a;
case 0x0c0ae63cu: goto P_0c0ae63c;
case 0x0c0ae63eu: goto P_0c0ae63e;
case 0x0c0ae640u: goto P_0c0ae640;
case 0x0c0ae642u: goto P_0c0ae642;
case 0x0c0ae644u: goto P_0c0ae644;
case 0x0c0ae646u: goto P_0c0ae646;
case 0x0c0ae648u: goto P_0c0ae648;
case 0x0c0ae64au: goto P_0c0ae64a;
case 0x0c0ae64cu: goto P_0c0ae64c;
case 0x0c0ae64eu: goto P_0c0ae64e;
case 0x0c0ae650u: goto P_0c0ae650;
case 0x0c0ae652u: goto P_0c0ae652;
case 0x0c0ae654u: goto P_0c0ae654;
case 0x0c0ae656u: goto P_0c0ae656;
case 0x0c0ae658u: goto P_0c0ae658;
case 0x0c0ae65au: goto P_0c0ae65a;
case 0x0c0ae65cu: goto P_0c0ae65c;
case 0x0c0ae65eu: goto P_0c0ae65e;
case 0x0c0ae660u: goto P_0c0ae660;
case 0x0c0ae662u: goto P_0c0ae662;
case 0x0c0ae664u: goto P_0c0ae664;
case 0x0c0ae666u: goto P_0c0ae666;
case 0x0c0ae668u: goto P_0c0ae668;
case 0x0c0ae66au: goto P_0c0ae66a;
case 0x0c0ae66cu: goto P_0c0ae66c;
case 0x0c0ae66eu: goto P_0c0ae66e;
case 0x0c0ae670u: goto P_0c0ae670;
case 0x0c0ae672u: goto P_0c0ae672;
case 0x0c0ae674u: goto P_0c0ae674;
case 0x0c0ae676u: goto P_0c0ae676;
case 0x0c0ae678u: goto P_0c0ae678;
case 0x0c0ae67au: goto P_0c0ae67a;
case 0x0c0ae67cu: goto P_0c0ae67c;
case 0x0c0ae67eu: goto P_0c0ae67e;
case 0x0c0ae680u: goto P_0c0ae680;
case 0x0c0ae682u: goto P_0c0ae682;
case 0x0c0ae684u: goto P_0c0ae684;
case 0x0c0ae686u: goto P_0c0ae686;
case 0x0c0ae688u: goto P_0c0ae688;
case 0x0c0ae68au: goto P_0c0ae68a;
case 0x0c0ae68cu: goto P_0c0ae68c;
case 0x0c0ae68eu: goto P_0c0ae68e;
case 0x0c0ae690u: goto P_0c0ae690;
case 0x0c0ae692u: goto P_0c0ae692;
case 0x0c0ae694u: goto P_0c0ae694;
case 0x0c0ae696u: goto P_0c0ae696;
case 0x0c0ae698u: goto P_0c0ae698;
case 0x0c0ae69au: goto P_0c0ae69a;
case 0x0c0ae69cu: goto P_0c0ae69c;
case 0x0c0ae69eu: goto P_0c0ae69e;
case 0x0c0ae6a0u: goto P_0c0ae6a0;
case 0x0c0ae6a2u: goto P_0c0ae6a2;
case 0x0c0ae6a4u: goto P_0c0ae6a4;
case 0x0c0ae6a6u: goto P_0c0ae6a6;
case 0x0c0ae6a8u: goto P_0c0ae6a8;
case 0x0c0ae6aau: goto P_0c0ae6aa;
case 0x0c0ae6acu: goto P_0c0ae6ac;
case 0x0c0ae9ecu: goto P_0c0ae9ec;
case 0x0c0ae9eeu: goto P_0c0ae9ee;
case 0x0c0ae9f0u: goto P_0c0ae9f0;
case 0x0c0ae9f2u: goto P_0c0ae9f2;
case 0x0c0ae9f4u: goto P_0c0ae9f4;
case 0x0c0ae9f6u: goto P_0c0ae9f6;
case 0x0c0ae9f8u: goto P_0c0ae9f8;
case 0x0c0ae9fau: goto P_0c0ae9fa;
case 0x0c0ae9fcu: goto P_0c0ae9fc;
case 0x0c0ae9feu: goto P_0c0ae9fe;
case 0x0c0aea00u: goto P_0c0aea00;
case 0x0c0aea02u: goto P_0c0aea02;
case 0x0c0aea04u: goto P_0c0aea04;
case 0x0c0aea06u: goto P_0c0aea06;
case 0x0c0aea08u: goto P_0c0aea08;
case 0x0c0aea0au: goto P_0c0aea0a;
case 0x0c0aea0cu: goto P_0c0aea0c;
case 0x0c0aea0eu: goto P_0c0aea0e;
case 0x0c0aea10u: goto P_0c0aea10;
case 0x0c0aea12u: goto P_0c0aea12;
case 0x0c0aea14u: goto P_0c0aea14;
case 0x0c0aea16u: goto P_0c0aea16;
case 0x0c0aea18u: goto P_0c0aea18;
case 0x0c0aea1au: goto P_0c0aea1a;
case 0x0c0aea1cu: goto P_0c0aea1c;
case 0x0c0aea1eu: goto P_0c0aea1e;
case 0x0c0aea20u: goto P_0c0aea20;
case 0x0c0aea22u: goto P_0c0aea22;
case 0x0c0aea24u: goto P_0c0aea24;
case 0x0c0aea26u: goto P_0c0aea26;
case 0x0c0aea28u: goto P_0c0aea28;
case 0x0c0aea2au: goto P_0c0aea2a;
case 0x0c0aea2cu: goto P_0c0aea2c;
case 0x0c0aea2eu: goto P_0c0aea2e;
case 0x0c0aea30u: goto P_0c0aea30;
case 0x0c0aea32u: goto P_0c0aea32;
case 0x0c0aea34u: goto P_0c0aea34;
case 0x0c0aea36u: goto P_0c0aea36;
case 0x0c0aea38u: goto P_0c0aea38;
case 0x0c0aea3au: goto P_0c0aea3a;
case 0x0c0aea3cu: goto P_0c0aea3c;
case 0x0c0aea3eu: goto P_0c0aea3e;
case 0x0c0aea40u: goto P_0c0aea40;
case 0x0c0aea42u: goto P_0c0aea42;
case 0x0c0aea44u: goto P_0c0aea44;
case 0x0c0aea46u: goto P_0c0aea46;
case 0x0c0aea48u: goto P_0c0aea48;
case 0x0c0aea4au: goto P_0c0aea4a;
case 0x0c0aea4cu: goto P_0c0aea4c;
case 0x0c0aea4eu: goto P_0c0aea4e;
case 0x0c0aea50u: goto P_0c0aea50;
case 0x0c0aea52u: goto P_0c0aea52;
case 0x0c0aea54u: goto P_0c0aea54;
case 0x0c0aea56u: goto P_0c0aea56;
case 0x0c0aea58u: goto P_0c0aea58;
case 0x0c0aea5au: goto P_0c0aea5a;
case 0x0c0aed4au: goto P_0c0aed4a;
case 0x0c0aed4cu: goto P_0c0aed4c;
case 0x0c0aed4eu: goto P_0c0aed4e;
case 0x0c0aed50u: goto P_0c0aed50;
case 0x0c0aed52u: goto P_0c0aed52;
case 0x0c0aed54u: goto P_0c0aed54;
case 0x0c0aed56u: goto P_0c0aed56;
case 0x0c0aed58u: goto P_0c0aed58;
case 0x0c0aed5au: goto P_0c0aed5a;
case 0x0c0aed5cu: goto P_0c0aed5c;
case 0x0c0aed5eu: goto P_0c0aed5e;
case 0x0c0aed60u: goto P_0c0aed60;
case 0x0c0aed62u: goto P_0c0aed62;
case 0x0c0aed64u: goto P_0c0aed64;
case 0x0c0aed66u: goto P_0c0aed66;
case 0x0c0aed68u: goto P_0c0aed68;
case 0x0c0aed6au: goto P_0c0aed6a;
case 0x0c0aed6cu: goto P_0c0aed6c;
case 0x0c0aed6eu: goto P_0c0aed6e;
case 0x0c0aed70u: goto P_0c0aed70;
case 0x0c0aed72u: goto P_0c0aed72;
case 0x0c0aed74u: goto P_0c0aed74;
case 0x0c0aed76u: goto P_0c0aed76;
case 0x0c0aed78u: goto P_0c0aed78;
case 0x0c0aed7au: goto P_0c0aed7a;
case 0x0c0aed7cu: goto P_0c0aed7c;
case 0x0c0aed7eu: goto P_0c0aed7e;
case 0x0c0aed80u: goto P_0c0aed80;
case 0x0c0aed82u: goto P_0c0aed82;
case 0x0c0aed84u: goto P_0c0aed84;
case 0x0c0aed86u: goto P_0c0aed86;
case 0x0c0aed88u: goto P_0c0aed88;
case 0x0c0aed8au: goto P_0c0aed8a;
case 0x0c0aed8cu: goto P_0c0aed8c;
case 0x0c0aed8eu: goto P_0c0aed8e;
case 0x0c0aed90u: goto P_0c0aed90;
case 0x0c0aed92u: goto P_0c0aed92;
case 0x0c0aed94u: goto P_0c0aed94;
case 0x0c0aed96u: goto P_0c0aed96;
case 0x0c0aed98u: goto P_0c0aed98;
case 0x0c0aed9au: goto P_0c0aed9a;
case 0x0c0aed9cu: goto P_0c0aed9c;
case 0x0c0aed9eu: goto P_0c0aed9e;
case 0x0c0aeda0u: goto P_0c0aeda0;
case 0x0c0aeda2u: goto P_0c0aeda2;
case 0x0c0aeda4u: goto P_0c0aeda4;
case 0x0c0aeda6u: goto P_0c0aeda6;
case 0x0c0aeda8u: goto P_0c0aeda8;
case 0x0c0aedaau: goto P_0c0aedaa;
case 0x0c0aedacu: goto P_0c0aedac;
case 0x0c0aedaeu: goto P_0c0aedae;
case 0x0c0aedb0u: goto P_0c0aedb0;
case 0x0c0aedb2u: goto P_0c0aedb2;
case 0x0c0aedb4u: goto P_0c0aedb4;
case 0x0c0aedb6u: goto P_0c0aedb6;
case 0x0c0aedb8u: goto P_0c0aedb8;
case 0x0c0aedbau: goto P_0c0aedba;
case 0x0c0aedbcu: goto P_0c0aedbc;
case 0x0c0aedbeu: goto P_0c0aedbe;
case 0x0c0aedc0u: goto P_0c0aedc0;
case 0x0c0aedc2u: goto P_0c0aedc2;
case 0x0c0aedc4u: goto P_0c0aedc4;
case 0x0c0aedc6u: goto P_0c0aedc6;
case 0x0c0aedc8u: goto P_0c0aedc8;
case 0x0c0aedcau: goto P_0c0aedca;
case 0x0c0aedccu: goto P_0c0aedcc;
case 0x0c0aedceu: goto P_0c0aedce;
case 0x0c0aedd0u: goto P_0c0aedd0;
case 0x0c0aedd2u: goto P_0c0aedd2;
case 0x0c0aedd4u: goto P_0c0aedd4;
case 0x0c0aedd6u: goto P_0c0aedd6;
case 0x0c0aedd8u: goto P_0c0aedd8;
case 0x0c0aeddau: goto P_0c0aedda;
case 0x0c0aeddcu: goto P_0c0aeddc;
case 0x0c0aeddeu: goto P_0c0aedde;
case 0x0c0aede0u: goto P_0c0aede0;
case 0x0c0aede2u: goto P_0c0aede2;
case 0x0c0aede4u: goto P_0c0aede4;
case 0x0c0aede6u: goto P_0c0aede6;
case 0x0c0aede8u: goto P_0c0aede8;
case 0x0c0aedeau: goto P_0c0aedea;
case 0x0c0aedecu: goto P_0c0aedec;
case 0x0c0aedeeu: goto P_0c0aedee;
case 0x0c0aedf0u: goto P_0c0aedf0;
case 0x0c0aedf2u: goto P_0c0aedf2;
case 0x0c0aedf4u: goto P_0c0aedf4;
case 0x0c0aedf6u: goto P_0c0aedf6;
case 0x0c0aedf8u: goto P_0c0aedf8;
case 0x0c0aedfau: goto P_0c0aedfa;
case 0x0c0aedfcu: goto P_0c0aedfc;
case 0x0c0aedfeu: goto P_0c0aedfe;
case 0x0c0aee00u: goto P_0c0aee00;
case 0x0c0aee02u: goto P_0c0aee02;
case 0x0c0aee04u: goto P_0c0aee04;
case 0x0c0aee06u: goto P_0c0aee06;
case 0x0c0aee08u: goto P_0c0aee08;
case 0x0c0aee0au: goto P_0c0aee0a;
case 0x0c0aee0cu: goto P_0c0aee0c;
case 0x0c0aee0eu: goto P_0c0aee0e;
case 0x0c0aee10u: goto P_0c0aee10;
case 0x0c0aee12u: goto P_0c0aee12;
case 0x0c0aee14u: goto P_0c0aee14;
case 0x0c0aee16u: goto P_0c0aee16;
case 0x0c0aee18u: goto P_0c0aee18;
case 0x0c0aee1au: goto P_0c0aee1a;
case 0x0c0aee1cu: goto P_0c0aee1c;
case 0x0c0aee1eu: goto P_0c0aee1e;
case 0x0c0aee20u: goto P_0c0aee20;
case 0x0c0aee22u: goto P_0c0aee22;
case 0x0c0aee24u: goto P_0c0aee24;
case 0x0c0aee26u: goto P_0c0aee26;
case 0x0c0aee28u: goto P_0c0aee28;
case 0x0c0aee2au: goto P_0c0aee2a;
case 0x0c0aee2cu: goto P_0c0aee2c;
case 0x0c0aee2eu: goto P_0c0aee2e;
case 0x0c0aee30u: goto P_0c0aee30;
case 0x0c0aee32u: goto P_0c0aee32;
case 0x0c0aee34u: goto P_0c0aee34;
case 0x0c0aee36u: goto P_0c0aee36;
case 0x0c0aee38u: goto P_0c0aee38;
case 0x0c0aee3au: goto P_0c0aee3a;
case 0x0c0aee3cu: goto P_0c0aee3c;
case 0x0c0aee3eu: goto P_0c0aee3e;
case 0x0c0aee40u: goto P_0c0aee40;
case 0x0c0aee42u: goto P_0c0aee42;
case 0x0c0aee44u: goto P_0c0aee44;
case 0x0c0aee46u: goto P_0c0aee46;
case 0x0c0aee48u: goto P_0c0aee48;
case 0x0c0aee4au: goto P_0c0aee4a;
case 0x0c0aee4cu: goto P_0c0aee4c;
case 0x0c0aee4eu: goto P_0c0aee4e;
case 0x0c0aee50u: goto P_0c0aee50;
case 0x0c0aee52u: goto P_0c0aee52;
case 0x0c0aee54u: goto P_0c0aee54;
case 0x0c0aee56u: goto P_0c0aee56;
case 0x0c0aee58u: goto P_0c0aee58;
case 0x0c0aee5au: goto P_0c0aee5a;
case 0x0c0aee5cu: goto P_0c0aee5c;
case 0x0c0aee5eu: goto P_0c0aee5e;
case 0x0c0aee60u: goto P_0c0aee60;
case 0x0c0aee62u: goto P_0c0aee62;
case 0x0c0aee64u: goto P_0c0aee64;
case 0x0c0aee66u: goto P_0c0aee66;
case 0x0c0aee68u: goto P_0c0aee68;
case 0x0c0aee6au: goto P_0c0aee6a;
case 0x0c0aee6cu: goto P_0c0aee6c;
case 0x0c0aee6eu: goto P_0c0aee6e;
case 0x0c0aee70u: goto P_0c0aee70;
case 0x0c0aee72u: goto P_0c0aee72;
case 0x0c0aee74u: goto P_0c0aee74;
case 0x0c0aee76u: goto P_0c0aee76;
case 0x0c0aee78u: goto P_0c0aee78;
case 0x0c0aee7au: goto P_0c0aee7a;
case 0x0c0aee7cu: goto P_0c0aee7c;
case 0x0c0aee7eu: goto P_0c0aee7e;
case 0x0c0aee80u: goto P_0c0aee80;
case 0x0c0aee82u: goto P_0c0aee82;
case 0x0c0aee84u: goto P_0c0aee84;
case 0x0c0aee86u: goto P_0c0aee86;
case 0x0c0aee88u: goto P_0c0aee88;
case 0x0c0aee8au: goto P_0c0aee8a;
case 0x0c0aee8cu: goto P_0c0aee8c;
case 0x0c0aee8eu: goto P_0c0aee8e;
case 0x0c0aee90u: goto P_0c0aee90;
case 0x0c0aee92u: goto P_0c0aee92;
case 0x0c0aee94u: goto P_0c0aee94;
case 0x0c0aee96u: goto P_0c0aee96;
case 0x0c0aee98u: goto P_0c0aee98;
case 0x0c0aee9au: goto P_0c0aee9a;
case 0x0c0aee9cu: goto P_0c0aee9c;
case 0x0c0aee9eu: goto P_0c0aee9e;
case 0x0c0aeea0u: goto P_0c0aeea0;
case 0x0c0aeea2u: goto P_0c0aeea2;
case 0x0c0aeea4u: goto P_0c0aeea4;
case 0x0c0aeea6u: goto P_0c0aeea6;
case 0x0c0aeea8u: goto P_0c0aeea8;
case 0x0c0aeeaau: goto P_0c0aeeaa;
case 0x0c0aeeccu: goto P_0c0aeecc;
case 0x0c0aeeceu: goto P_0c0aeece;
case 0x0c0aeed0u: goto P_0c0aeed0;
case 0x0c0aeed2u: goto P_0c0aeed2;
case 0x0c0aeed4u: goto P_0c0aeed4;
case 0x0c0aeed6u: goto P_0c0aeed6;
case 0x0c0aeed8u: goto P_0c0aeed8;
case 0x0c0aeedau: goto P_0c0aeeda;
case 0x0c0aeedcu: goto P_0c0aeedc;
case 0x0c0aeedeu: goto P_0c0aeede;
case 0x0c0aeee0u: goto P_0c0aeee0;
case 0x0c0aeee2u: goto P_0c0aeee2;
case 0x0c0aeee4u: goto P_0c0aeee4;
case 0x0c0aeee6u: goto P_0c0aeee6;
case 0x0c0aeee8u: goto P_0c0aeee8;
case 0x0c0aeeeau: goto P_0c0aeeea;
case 0x0c0aeeecu: goto P_0c0aeeec;
case 0x0c0aeeeeu: goto P_0c0aeeee;
case 0x0c0aeef0u: goto P_0c0aeef0;
case 0x0c0aeef2u: goto P_0c0aeef2;
case 0x0c0aeef4u: goto P_0c0aeef4;
case 0x0c0aeef6u: goto P_0c0aeef6;
case 0x0c0aeef8u: goto P_0c0aeef8;
case 0x0c0aeefau: goto P_0c0aeefa;
case 0x0c0aeefcu: goto P_0c0aeefc;
case 0x0c0aeefeu: goto P_0c0aeefe;
case 0x0c0aef00u: goto P_0c0aef00;
case 0x0c0aef02u: goto P_0c0aef02;
case 0x0c0aef04u: goto P_0c0aef04;
case 0x0c0aef06u: goto P_0c0aef06;
case 0x0c0aef08u: goto P_0c0aef08;
case 0x0c0aef0au: goto P_0c0aef0a;
case 0x0c0aef0cu: goto P_0c0aef0c;
case 0x0c0aef0eu: goto P_0c0aef0e;
case 0x0c0aef10u: goto P_0c0aef10;
case 0x0c0aef12u: goto P_0c0aef12;
case 0x0c0aef14u: goto P_0c0aef14;
case 0x0c0aef16u: goto P_0c0aef16;
case 0x0c0aef18u: goto P_0c0aef18;
case 0x0c0aef1au: goto P_0c0aef1a;
case 0x0c0aef1cu: goto P_0c0aef1c;
case 0x0c0aef1eu: goto P_0c0aef1e;
case 0x0c0aef20u: goto P_0c0aef20;
case 0x0c0aef22u: goto P_0c0aef22;
case 0x0c0aef24u: goto P_0c0aef24;
case 0x0c0aef26u: goto P_0c0aef26;
case 0x0c0aef28u: goto P_0c0aef28;
case 0x0c0aef2au: goto P_0c0aef2a;
case 0x0c0aef2cu: goto P_0c0aef2c;
case 0x0c0aef2eu: goto P_0c0aef2e;
case 0x0c0aef30u: goto P_0c0aef30;
case 0x0c0aef32u: goto P_0c0aef32;
case 0x0c0aef34u: goto P_0c0aef34;
case 0x0c0aef36u: goto P_0c0aef36;
case 0x0c0aef38u: goto P_0c0aef38;
case 0x0c0aef3au: goto P_0c0aef3a;
case 0x0c0aef3cu: goto P_0c0aef3c;
case 0x0c0aef3eu: goto P_0c0aef3e;
case 0x0c0aef40u: goto P_0c0aef40;
case 0x0c0aef42u: goto P_0c0aef42;
case 0x0c0aef44u: goto P_0c0aef44;
case 0x0c0aef46u: goto P_0c0aef46;
case 0x0c0aef48u: goto P_0c0aef48;
case 0x0c0aef4au: goto P_0c0aef4a;
case 0x0c0aef4cu: goto P_0c0aef4c;
case 0x0c0aef4eu: goto P_0c0aef4e;
case 0x0c0aef50u: goto P_0c0aef50;
case 0x0c0aef52u: goto P_0c0aef52;
case 0x0c0aef54u: goto P_0c0aef54;
case 0x0c0aef56u: goto P_0c0aef56;
case 0x0c0aef58u: goto P_0c0aef58;
case 0x0c0aef5au: goto P_0c0aef5a;
case 0x0c0aef5cu: goto P_0c0aef5c;
case 0x0c0aef5eu: goto P_0c0aef5e;
case 0x0c0aef60u: goto P_0c0aef60;
case 0x0c0aef62u: goto P_0c0aef62;
case 0x0c0aef64u: goto P_0c0aef64;
case 0x0c0aef66u: goto P_0c0aef66;
case 0x0c0aef68u: goto P_0c0aef68;
case 0x0c0aef6au: goto P_0c0aef6a;
case 0x0c0aef6cu: goto P_0c0aef6c;
case 0x0c0aef6eu: goto P_0c0aef6e;
case 0x0c0aef70u: goto P_0c0aef70;
case 0x0c0aef72u: goto P_0c0aef72;
case 0x0c0aef74u: goto P_0c0aef74;
case 0x0c0aef76u: goto P_0c0aef76;
case 0x0c0aef78u: goto P_0c0aef78;
case 0x0c0aef7au: goto P_0c0aef7a;
case 0x0c0aef7cu: goto P_0c0aef7c;
case 0x0c0aef7eu: goto P_0c0aef7e;
case 0x0c0aef80u: goto P_0c0aef80;
case 0x0c0aef82u: goto P_0c0aef82;
case 0x0c0aef84u: goto P_0c0aef84;
case 0x0c0aef86u: goto P_0c0aef86;
case 0x0c0aef88u: goto P_0c0aef88;
case 0x0c0aef8au: goto P_0c0aef8a;
case 0x0c0aef8cu: goto P_0c0aef8c;
case 0x0c0aef8eu: goto P_0c0aef8e;
case 0x0c0aef90u: goto P_0c0aef90;
case 0x0c0aef92u: goto P_0c0aef92;
case 0x0c0aef94u: goto P_0c0aef94;
case 0x0c0aef96u: goto P_0c0aef96;
case 0x0c0aef98u: goto P_0c0aef98;
case 0x0c0aef9au: goto P_0c0aef9a;
case 0x0c0aef9cu: goto P_0c0aef9c;
case 0x0c0aef9eu: goto P_0c0aef9e;
case 0x0c0aefa0u: goto P_0c0aefa0;
case 0x0c0aefa2u: goto P_0c0aefa2;
case 0x0c0aefa4u: goto P_0c0aefa4;
case 0x0c0aefa6u: goto P_0c0aefa6;
case 0x0c0aefa8u: goto P_0c0aefa8;
case 0x0c0aefaau: goto P_0c0aefaa;
case 0x0c0aefacu: goto P_0c0aefac;
case 0x0c0aefaeu: goto P_0c0aefae;
case 0x0c0aefb0u: goto P_0c0aefb0;
case 0x0c0aefb2u: goto P_0c0aefb2;
case 0x0c0aefb4u: goto P_0c0aefb4;
case 0x0c0aefb6u: goto P_0c0aefb6;
case 0x0c0aefb8u: goto P_0c0aefb8;
case 0x0c0aefbau: goto P_0c0aefba;
case 0x0c0aefbcu: goto P_0c0aefbc;
case 0x0c0aefbeu: goto P_0c0aefbe;
case 0x0c0aefc0u: goto P_0c0aefc0;
case 0x0c0aefc2u: goto P_0c0aefc2;
case 0x0c0aefc4u: goto P_0c0aefc4;
case 0x0c0aefc6u: goto P_0c0aefc6;
case 0x0c0aefc8u: goto P_0c0aefc8;
case 0x0c0aefcau: goto P_0c0aefca;
case 0x0c0aefccu: goto P_0c0aefcc;
case 0x0c0aefceu: goto P_0c0aefce;
case 0x0c0aefd0u: goto P_0c0aefd0;
case 0x0c0aefd2u: goto P_0c0aefd2;
case 0x0c0aefd4u: goto P_0c0aefd4;
case 0x0c0aefd6u: goto P_0c0aefd6;
case 0x0c0aefd8u: goto P_0c0aefd8;
case 0x0c0aefdau: goto P_0c0aefda;
case 0x0c0aefdcu: goto P_0c0aefdc;
case 0x0c0aefdeu: goto P_0c0aefde;
case 0x0c0aefe0u: goto P_0c0aefe0;
case 0x0c0aefe2u: goto P_0c0aefe2;
case 0x0c0aefe4u: goto P_0c0aefe4;
case 0x0c0aefe6u: goto P_0c0aefe6;
case 0x0c0aefe8u: goto P_0c0aefe8;
case 0x0c0aefeau: goto P_0c0aefea;
case 0x0c0aefecu: goto P_0c0aefec;
case 0x0c0aefeeu: goto P_0c0aefee;
case 0x0c0aeff0u: goto P_0c0aeff0;
case 0x0c0aeff2u: goto P_0c0aeff2;
case 0x0c0aeff4u: goto P_0c0aeff4;
case 0x0c0aeff6u: goto P_0c0aeff6;
case 0x0c0aeff8u: goto P_0c0aeff8;
case 0x0c0aeffau: goto P_0c0aeffa;
case 0x0c0aeffcu: goto P_0c0aeffc;
case 0x0c0aeffeu: goto P_0c0aeffe;
case 0x0c0af000u: goto P_0c0af000;
case 0x0c0af002u: goto P_0c0af002;
case 0x0c0af004u: goto P_0c0af004;
case 0x0c0af006u: goto P_0c0af006;
case 0x0c0af008u: goto P_0c0af008;
case 0x0c0af00au: goto P_0c0af00a;
case 0x0c0af00cu: goto P_0c0af00c;
case 0x0c0af00eu: goto P_0c0af00e;
case 0x0c0af010u: goto P_0c0af010;
case 0x0c0af012u: goto P_0c0af012;
case 0x0c0af014u: goto P_0c0af014;
case 0x0c0af016u: goto P_0c0af016;
case 0x0c0af018u: goto P_0c0af018;
case 0x0c0af01au: goto P_0c0af01a;
case 0x0c0af01cu: goto P_0c0af01c;
case 0x0c0af01eu: goto P_0c0af01e;
case 0x0c0af020u: goto P_0c0af020;
case 0x0c0af022u: goto P_0c0af022;
case 0x0c0af024u: goto P_0c0af024;
case 0x0c0af026u: goto P_0c0af026;
case 0x0c0af028u: goto P_0c0af028;
case 0x0c0af02au: goto P_0c0af02a;
case 0x0c0af02cu: goto P_0c0af02c;
case 0x0c0af02eu: goto P_0c0af02e;
case 0x0c0af030u: goto P_0c0af030;
case 0x0c0af032u: goto P_0c0af032;
case 0x0c0af034u: goto P_0c0af034;
case 0x0c0af036u: goto P_0c0af036;
case 0x0c0af038u: goto P_0c0af038;
case 0x0c0af03au: goto P_0c0af03a;
case 0x0c0af03cu: goto P_0c0af03c;
case 0x0c0af03eu: goto P_0c0af03e;
case 0x0c0af040u: goto P_0c0af040;
case 0x0c0af042u: goto P_0c0af042;
case 0x0c0af044u: goto P_0c0af044;
case 0x0c0af046u: goto P_0c0af046;
case 0x0c0af048u: goto P_0c0af048;
case 0x0c0af04au: goto P_0c0af04a;
case 0x0c0c12f0u: goto P_0c0c12f0;
case 0x0c0c12f2u: goto P_0c0c12f2;
case 0x0c0c12f4u: goto P_0c0c12f4;
case 0x0c0c12f6u: goto P_0c0c12f6;
case 0x0c0c12f8u: goto P_0c0c12f8;
case 0x0c0c12fau: goto P_0c0c12fa;
case 0x0c0c12fcu: goto P_0c0c12fc;
case 0x0c0c12feu: goto P_0c0c12fe;
case 0x0c0c1300u: goto P_0c0c1300;
case 0x0c0c1302u: goto P_0c0c1302;
case 0x0c0c1304u: goto P_0c0c1304;
case 0x0c0c1306u: goto P_0c0c1306;
case 0x0c0c1308u: goto P_0c0c1308;
case 0x0c0c130au: goto P_0c0c130a;
case 0x0c0c130cu: goto P_0c0c130c;
case 0x0c0c130eu: goto P_0c0c130e;
case 0x0c0c1310u: goto P_0c0c1310;
case 0x0c0c1312u: goto P_0c0c1312;
case 0x0c0c1314u: goto P_0c0c1314;
case 0x0c0c1316u: goto P_0c0c1316;
case 0x0c0c1318u: goto P_0c0c1318;
case 0x0c0c131au: goto P_0c0c131a;
case 0x0c0c131cu: goto P_0c0c131c;
case 0x0c0c131eu: goto P_0c0c131e;
case 0x0c0c1320u: goto P_0c0c1320;
case 0x0c0c1322u: goto P_0c0c1322;
case 0x0c0c1324u: goto P_0c0c1324;
case 0x0c0c1326u: goto P_0c0c1326;
case 0x0c0c1328u: goto P_0c0c1328;
case 0x0c0c132au: goto P_0c0c132a;
case 0x0c0c132cu: goto P_0c0c132c;
case 0x0c0c132eu: goto P_0c0c132e;
case 0x0c0c1330u: goto P_0c0c1330;
case 0x0c0c1332u: goto P_0c0c1332;
case 0x0c0c1334u: goto P_0c0c1334;
case 0x0c0c1336u: goto P_0c0c1336;
case 0x0c0c1338u: goto P_0c0c1338;
case 0x0c0c133au: goto P_0c0c133a;
case 0x0c0c133cu: goto P_0c0c133c;
case 0x0c0c133eu: goto P_0c0c133e;
case 0x0c0c1340u: goto P_0c0c1340;
case 0x0c0c1342u: goto P_0c0c1342;
case 0x0c0c1344u: goto P_0c0c1344;
case 0x0c0c1346u: goto P_0c0c1346;
case 0x0c0c1348u: goto P_0c0c1348;
case 0x0c0c134au: goto P_0c0c134a;
case 0x0c0c134cu: goto P_0c0c134c;
case 0x0c0c134eu: goto P_0c0c134e;
case 0x0c0c1350u: goto P_0c0c1350;
case 0x0c0c1352u: goto P_0c0c1352;
case 0x0c0c1354u: goto P_0c0c1354;
case 0x0c0c1356u: goto P_0c0c1356;
case 0x0c0c1358u: goto P_0c0c1358;
case 0x0c0c135au: goto P_0c0c135a;
case 0x0c0c135cu: goto P_0c0c135c;
case 0x0c0c135eu: goto P_0c0c135e;
case 0x0c0c1360u: goto P_0c0c1360;
case 0x0c0c1362u: goto P_0c0c1362;
case 0x0c0c1364u: goto P_0c0c1364;
case 0x0c0c1366u: goto P_0c0c1366;
case 0x0c0c1368u: goto P_0c0c1368;
case 0x0c0c136au: goto P_0c0c136a;
case 0x0c0c136cu: goto P_0c0c136c;
case 0x0c0c136eu: goto P_0c0c136e;
case 0x0c0c1370u: goto P_0c0c1370;
case 0x0c0c1372u: goto P_0c0c1372;
case 0x0c0c1374u: goto P_0c0c1374;
case 0x0c0c1376u: goto P_0c0c1376;
case 0x0c0c1378u: goto P_0c0c1378;
case 0x0c0c137au: goto P_0c0c137a;
case 0x0c0c137cu: goto P_0c0c137c;
case 0x0c0c137eu: goto P_0c0c137e;
case 0x0c0c1380u: goto P_0c0c1380;
case 0x0c0c1382u: goto P_0c0c1382;
case 0x0c0c1384u: goto P_0c0c1384;
case 0x0c0c1386u: goto P_0c0c1386;
case 0x0c0c1388u: goto P_0c0c1388;
case 0x0c0c138au: goto P_0c0c138a;
case 0x0c0c138cu: goto P_0c0c138c;
case 0x0c0c138eu: goto P_0c0c138e;
case 0x0c0c1390u: goto P_0c0c1390;
case 0x0c0c1392u: goto P_0c0c1392;
case 0x0c0c1394u: goto P_0c0c1394;
case 0x0c0c1396u: goto P_0c0c1396;
case 0x0c0c1398u: goto P_0c0c1398;
case 0x0c0c139au: goto P_0c0c139a;
case 0x0c0c139cu: goto P_0c0c139c;
case 0x0c0c139eu: goto P_0c0c139e;
case 0x0c0c13a0u: goto P_0c0c13a0;
case 0x0c0c13a2u: goto P_0c0c13a2;
case 0x0c0c13a4u: goto P_0c0c13a4;
case 0x0c0c13a6u: goto P_0c0c13a6;
case 0x0c0c13a8u: goto P_0c0c13a8;
case 0x0c0c13aau: goto P_0c0c13aa;
case 0x0c0c13acu: goto P_0c0c13ac;
case 0x0c0c13aeu: goto P_0c0c13ae;
case 0x0c0c13b0u: goto P_0c0c13b0;
case 0x0c0c13b2u: goto P_0c0c13b2;
case 0x0c0c13b4u: goto P_0c0c13b4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08e920: /* original 4f22, guest PC 0x0c08e920 */
if(!s->budget--) { s->failed_pc=0x0c08e920u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08e922;
P_0c08e922: /* original 7fbc, guest PC 0x0c08e922 */
if(!s->budget--) { s->failed_pc=0x0c08e922u; return 0; }
r[15]+=0xffffffbcu;
goto P_0c08e924;
P_0c08e924: /* original 1f5c, guest PC 0x0c08e924 */
if(!s->budget--) { s->failed_pc=0x0c08e924u; return 0; }
write(ram,r[15]+48,r[5],4);
goto P_0c08e926;
P_0c08e926: /* original 5c4c, guest PC 0x0c08e926 */
if(!s->budget--) { s->failed_pc=0x0c08e926u; return 0; }
r[12]=read(ram,r[4]+48,4);
goto P_0c08e928;
P_0c08e928: /* original 6453, guest PC 0x0c08e928 */
if(!s->budget--) { s->failed_pc=0x0c08e928u; return 0; }
r[4]=r[5];
goto P_0c08e92a;
P_0c08e92a: /* original 740c, guest PC 0x0c08e92a */
if(!s->budget--) { s->failed_pc=0x0c08e92au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08e92c;
P_0c08e92c: /* original f449, guest PC 0x0c08e92c */
if(!s->budget--) { s->failed_pc=0x0c08e92cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e92e;
P_0c08e92e: /* original f549, guest PC 0x0c08e92e */
if(!s->budget--) { s->failed_pc=0x0c08e92eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e930;
P_0c08e930: /* original f649, guest PC 0x0c08e930 */
if(!s->budget--) { s->failed_pc=0x0c08e930u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e932;
P_0c08e932: /* original f349, guest PC 0x0c08e932 */
if(!s->budget--) { s->failed_pc=0x0c08e932u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e934;
P_0c08e934: /* original ff37, guest PC 0x0c08e934 */
if(!s->budget--) { s->failed_pc=0x0c08e934u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e936;
P_0c08e936: /* original e01c, guest PC 0x0c08e936 */
if(!s->budget--) { s->failed_pc=0x0c08e936u; return 0; }
r[0]=0x0000001cu;
goto P_0c08e938;
P_0c08e938: /* original f349, guest PC 0x0c08e938 */
if(!s->budget--) { s->failed_pc=0x0c08e938u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e93a;
P_0c08e93a: /* original ff37, guest PC 0x0c08e93a */
if(!s->budget--) { s->failed_pc=0x0c08e93au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e93c;
P_0c08e93c: /* original e024, guest PC 0x0c08e93c */
if(!s->budget--) { s->failed_pc=0x0c08e93cu; return 0; }
r[0]=0x00000024u;
goto P_0c08e93e;
P_0c08e93e: /* original f349, guest PC 0x0c08e93e */
if(!s->budget--) { s->failed_pc=0x0c08e93eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e940;
P_0c08e940: /* original ff37, guest PC 0x0c08e940 */
if(!s->budget--) { s->failed_pc=0x0c08e940u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e942;
P_0c08e942: /* original e004, guest PC 0x0c08e942 */
if(!s->budget--) { s->failed_pc=0x0c08e942u; return 0; }
r[0]=0x00000004u;
goto P_0c08e944;
P_0c08e944: /* original ff49, guest PC 0x0c08e944 */
if(!s->budget--) { s->failed_pc=0x0c08e944u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e946;
P_0c08e946: /* original fd49, guest PC 0x0c08e946 */
if(!s->budget--) { s->failed_pc=0x0c08e946u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e948;
P_0c08e948: /* original f349, guest PC 0x0c08e948 */
if(!s->budget--) { s->failed_pc=0x0c08e948u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e94a;
P_0c08e94a: /* original ff37, guest PC 0x0c08e94a */
if(!s->budget--) { s->failed_pc=0x0c08e94au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e94c;
P_0c08e94c: /* original e010, guest PC 0x0c08e94c */
if(!s->budget--) { s->failed_pc=0x0c08e94cu; return 0; }
r[0]=0x00000010u;
goto P_0c08e94e;
P_0c08e94e: /* original f349, guest PC 0x0c08e94e */
if(!s->budget--) { s->failed_pc=0x0c08e94eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e950;
P_0c08e950: /* original ff37, guest PC 0x0c08e950 */
if(!s->budget--) { s->failed_pc=0x0c08e950u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e952;
P_0c08e952: /* original e038, guest PC 0x0c08e952 */
if(!s->budget--) { s->failed_pc=0x0c08e952u; return 0; }
r[0]=0x00000038u;
goto P_0c08e954;
P_0c08e954: /* original f349, guest PC 0x0c08e954 */
if(!s->budget--) { s->failed_pc=0x0c08e954u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e956;
P_0c08e956: /* original e304, guest PC 0x0c08e956 */
if(!s->budget--) { s->failed_pc=0x0c08e956u; return 0; }
r[3]=0x00000004u;
goto P_0c08e958;
P_0c08e958: /* original 23c8, guest PC 0x0c08e958 */
if(!s->budget--) { s->failed_pc=0x0c08e958u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c08e95a;
P_0c08e95a: /* original ff37, guest PC 0x0c08e95a */
if(!s->budget--) { s->failed_pc=0x0c08e95au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e95c;
P_0c08e95c: /* original e018, guest PC 0x0c08e95c */
if(!s->budget--) { s->failed_pc=0x0c08e95cu; return 0; }
r[0]=0x00000018u;
goto P_0c08e95e;
P_0c08e95e: /* original f349, guest PC 0x0c08e95e */
if(!s->budget--) { s->failed_pc=0x0c08e95eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e960;
P_0c08e960: /* original ff37, guest PC 0x0c08e960 */
if(!s->budget--) { s->failed_pc=0x0c08e960u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e962;
P_0c08e962: /* original e00c, guest PC 0x0c08e962 */
if(!s->budget--) { s->failed_pc=0x0c08e962u; return 0; }
r[0]=0x0000000cu;
goto P_0c08e964;
P_0c08e964: /* original f349, guest PC 0x0c08e964 */
if(!s->budget--) { s->failed_pc=0x0c08e964u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e966;
P_0c08e966: /* original ff37, guest PC 0x0c08e966 */
if(!s->budget--) { s->failed_pc=0x0c08e966u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e968;
P_0c08e968: /* original e02c, guest PC 0x0c08e968 */
if(!s->budget--) { s->failed_pc=0x0c08e968u; return 0; }
r[0]=0x0000002cu;
goto P_0c08e96a;
P_0c08e96a: /* original f349, guest PC 0x0c08e96a */
if(!s->budget--) { s->failed_pc=0x0c08e96au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08e96c;
P_0c08e96c: /* original ff37, guest PC 0x0c08e96c */
if(!s->budget--) { s->failed_pc=0x0c08e96cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e96e;
P_0c08e96e: /* original e028, guest PC 0x0c08e96e */
if(!s->budget--) { s->failed_pc=0x0c08e96eu; return 0; }
r[0]=0x00000028u;
goto P_0c08e970;
P_0c08e970: /* original f348, guest PC 0x0c08e970 */
if(!s->budget--) { s->failed_pc=0x0c08e970u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c08e972;
P_0c08e972: /* original 8f03, guest PC 0x0c08e972 */
if(!s->budget--) { s->failed_pc=0x0c08e972u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c08e97c; }
goto P_0c08e976;
P_0c08e974: /* original ff37, guest PC 0x0c08e974 */
if(!s->budget--) { s->failed_pc=0x0c08e974u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08e976;
P_0c08e976: /* original e202, guest PC 0x0c08e976 */
if(!s->budget--) { s->failed_pc=0x0c08e976u; return 0; }
r[2]=0x00000002u;
goto P_0c08e978;
P_0c08e978: /* original 22c8, guest PC 0x0c08e978 */
if(!s->budget--) { s->failed_pc=0x0c08e978u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c08e97a;
P_0c08e97a: /* original 8905, guest PC 0x0c08e97a */
if(!s->budget--) { s->failed_pc=0x0c08e97au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08e988; }
goto P_0c08e97c;
P_0c08e97c: /* original e020, guest PC 0x0c08e97c */
if(!s->budget--) { s->failed_pc=0x0c08e97cu; return 0; }
r[0]=0x00000020u;
goto P_0c08e97e;
P_0c08e97e: /* original ff47, guest PC 0x0c08e97e */
if(!s->budget--) { s->failed_pc=0x0c08e97eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08e980;
P_0c08e980: /* original e01c, guest PC 0x0c08e980 */
if(!s->budget--) { s->failed_pc=0x0c08e980u; return 0; }
r[0]=0x0000001cu;
goto P_0c08e982;
P_0c08e982: /* original ff57, guest PC 0x0c08e982 */
if(!s->budget--) { s->failed_pc=0x0c08e982u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08e984;
P_0c08e984: /* original e024, guest PC 0x0c08e984 */
if(!s->budget--) { s->failed_pc=0x0c08e984u; return 0; }
r[0]=0x00000024u;
goto P_0c08e986;
P_0c08e986: /* original ff67, guest PC 0x0c08e986 */
if(!s->budget--) { s->failed_pc=0x0c08e986u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08e988;
P_0c08e988: /* original e020, guest PC 0x0c08e988 */
if(!s->budget--) { s->failed_pc=0x0c08e988u; return 0; }
r[0]=0x00000020u;
goto P_0c08e98a;
P_0c08e98a: /* original f3f6, guest PC 0x0c08e98a */
if(!s->budget--) { s->failed_pc=0x0c08e98au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08e98c;
P_0c08e98c: /* original e008, guest PC 0x0c08e98c */
if(!s->budget--) { s->failed_pc=0x0c08e98cu; return 0; }
r[0]=0x00000008u;
goto P_0c08e98e;
P_0c08e98e: /* original f431, guest PC 0x0c08e98e */
if(!s->budget--) { s->failed_pc=0x0c08e98eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08e990;
P_0c08e990: /* original ff47, guest PC 0x0c08e990 */
if(!s->budget--) { s->failed_pc=0x0c08e990u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08e992;
P_0c08e992: /* original e01c, guest PC 0x0c08e992 */
if(!s->budget--) { s->failed_pc=0x0c08e992u; return 0; }
r[0]=0x0000001cu;
goto P_0c08e994;
P_0c08e994: /* original f2f6, guest PC 0x0c08e994 */
if(!s->budget--) { s->failed_pc=0x0c08e994u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08e996;
P_0c08e996: /* original e024, guest PC 0x0c08e996 */
if(!s->budget--) { s->failed_pc=0x0c08e996u; return 0; }
r[0]=0x00000024u;
goto P_0c08e998;
P_0c08e998: /* original f1f6, guest PC 0x0c08e998 */
if(!s->budget--) { s->failed_pc=0x0c08e998u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08e99a;
P_0c08e99a: /* original fe6c, guest PC 0x0c08e99a */
if(!s->budget--) { s->failed_pc=0x0c08e99au; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c08e99c;
P_0c08e99c: /* original fc5c, guest PC 0x0c08e99c */
if(!s->budget--) { s->failed_pc=0x0c08e99cu; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c08e99e;
P_0c08e99e: /* original fe11, guest PC 0x0c08e99e */
if(!s->budget--) { s->failed_pc=0x0c08e99eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[1],r[18],'-');
goto P_0c08e9a0;
P_0c08e9a0: /* original fc21, guest PC 0x0c08e9a0 */
if(!s->budget--) { s->failed_pc=0x0c08e9a0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c08e9a2;
P_0c08e9a2: /* original dd86, guest PC 0x0c08e9a2 */
if(!s->budget--) { s->failed_pc=0x0c08e9a2u; return 0; }
r[13]=read(ram,0x0c08ebbcu,4);
goto P_0c08e9a4;
P_0c08e9a4: /* original f6ec, guest PC 0x0c08e9a4 */
if(!s->budget--) { s->failed_pc=0x0c08e9a4u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08e9a6;
P_0c08e9a6: /* original f5cc, guest PC 0x0c08e9a6 */
if(!s->budget--) { s->failed_pc=0x0c08e9a6u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08e9a8;
P_0c08e9a8: /* original 4d0b, guest PC 0x0c08e9a8 */
if(!s->budget--) { s->failed_pc=0x0c08e9a8u; return 0; }
target=r[13];
r[16]=0x0c08e9acu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08e9acu) { target=s->pc; goto dispatch; }
goto P_0c08e9ac;
P_0c08e9aa: /* original 64f3, guest PC 0x0c08e9aa */
if(!s->budget--) { s->failed_pc=0x0c08e9aau; return 0; }
r[4]=r[15];
goto P_0c08e9ac;
P_0c08e9ac: /* original e014, guest PC 0x0c08e9ac */
if(!s->budget--) { s->failed_pc=0x0c08e9acu; return 0; }
r[0]=0x00000014u;
goto P_0c08e9ae;
P_0c08e9ae: /* original ff07, guest PC 0x0c08e9ae */
if(!s->budget--) { s->failed_pc=0x0c08e9aeu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c08e9b0;
P_0c08e9b0: /* original e010, guest PC 0x0c08e9b0 */
if(!s->budget--) { s->failed_pc=0x0c08e9b0u; return 0; }
r[0]=0x00000010u;
goto P_0c08e9b2;
P_0c08e9b2: /* original f3f6, guest PC 0x0c08e9b2 */
if(!s->budget--) { s->failed_pc=0x0c08e9b2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08e9b4;
P_0c08e9b4: /* original ee20, guest PC 0x0c08e9b4 */
if(!s->budget--) { s->failed_pc=0x0c08e9b4u; return 0; }
r[14]=0x00000020u;
goto P_0c08e9b6;
P_0c08e9b6: /* original f035, guest PC 0x0c08e9b6 */
if(!s->budget--) { s->failed_pc=0x0c08e9b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c08e9b8;
P_0c08e9b8: /* original 8d02, guest PC 0x0c08e9b8 */
if(!s->budget--) { s->failed_pc=0x0c08e9b8u; return 0; }
cond=r[17]&1u;
r[14]&=r[12];
if(cond) { goto P_0c08e9c0; }
goto P_0c08e9bc;
P_0c08e9ba: /* original 2ec9, guest PC 0x0c08e9ba */
if(!s->budget--) { s->failed_pc=0x0c08e9bau; return 0; }
r[14]&=r[12];
goto P_0c08e9bc;
P_0c08e9bc: /* original a0b9, guest PC 0x0c08e9bc */
if(!s->budget--) { s->failed_pc=0x0c08e9bcu; return 0; }
goto P_0c08eb32;
P_0c08e9be: /* original 0009, guest PC 0x0c08e9be */
if(!s->budget--) { s->failed_pc=0x0c08e9beu; return 0; }
goto P_0c08e9c0;
P_0c08e9c0: /* original e008, guest PC 0x0c08e9c0 */
if(!s->budget--) { s->failed_pc=0x0c08e9c0u; return 0; }
r[0]=0x00000008u;
goto P_0c08e9c2;
P_0c08e9c2: /* original f2f8, guest PC 0x0c08e9c2 */
if(!s->budget--) { s->failed_pc=0x0c08e9c2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08e9c4;
P_0c08e9c4: /* original f3f6, guest PC 0x0c08e9c4 */
if(!s->budget--) { s->failed_pc=0x0c08e9c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08e9c6;
P_0c08e9c6: /* original e008, guest PC 0x0c08e9c6 */
if(!s->budget--) { s->failed_pc=0x0c08e9c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08e9c8;
P_0c08e9c8: /* original 2ee8, guest PC 0x0c08e9c8 */
if(!s->budget--) { s->failed_pc=0x0c08e9c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08e9ca;
P_0c08e9ca: /* original f232, guest PC 0x0c08e9ca */
if(!s->budget--) { s->failed_pc=0x0c08e9cau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08e9cc;
P_0c08e9cc: /* original ff27, guest PC 0x0c08e9cc */
if(!s->budget--) { s->failed_pc=0x0c08e9ccu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08e9ce;
P_0c08e9ce: /* original e010, guest PC 0x0c08e9ce */
if(!s->budget--) { s->failed_pc=0x0c08e9ceu; return 0; }
r[0]=0x00000010u;
goto P_0c08e9d0;
P_0c08e9d0: /* original f3cc, guest PC 0x0c08e9d0 */
if(!s->budget--) { s->failed_pc=0x0c08e9d0u; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c08e9d2;
P_0c08e9d2: /* original fcf8, guest PC 0x0c08e9d2 */
if(!s->budget--) { s->failed_pc=0x0c08e9d2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c08e9d4;
P_0c08e9d4: /* original fc32, guest PC 0x0c08e9d4 */
if(!s->budget--) { s->failed_pc=0x0c08e9d4u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c08e9d6;
P_0c08e9d6: /* original f3ec, guest PC 0x0c08e9d6 */
if(!s->budget--) { s->failed_pc=0x0c08e9d6u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c08e9d8;
P_0c08e9d8: /* original fef8, guest PC 0x0c08e9d8 */
if(!s->budget--) { s->failed_pc=0x0c08e9d8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
goto P_0c08e9da;
P_0c08e9da: /* original fe32, guest PC 0x0c08e9da */
if(!s->budget--) { s->failed_pc=0x0c08e9dau; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c08e9dc;
P_0c08e9dc: /* original f3f6, guest PC 0x0c08e9dc */
if(!s->budget--) { s->failed_pc=0x0c08e9dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08e9de;
P_0c08e9de: /* original e014, guest PC 0x0c08e9de */
if(!s->budget--) { s->failed_pc=0x0c08e9deu; return 0; }
r[0]=0x00000014u;
goto P_0c08e9e0;
P_0c08e9e0: /* original f4f6, guest PC 0x0c08e9e0 */
if(!s->budget--) { s->failed_pc=0x0c08e9e0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08e9e2;
P_0c08e9e2: /* original e008, guest PC 0x0c08e9e2 */
if(!s->budget--) { s->failed_pc=0x0c08e9e2u; return 0; }
r[0]=0x00000008u;
goto P_0c08e9e4;
P_0c08e9e4: /* original f431, guest PC 0x0c08e9e4 */
if(!s->budget--) { s->failed_pc=0x0c08e9e4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08e9e6;
P_0c08e9e6: /* original f242, guest PC 0x0c08e9e6 */
if(!s->budget--) { s->failed_pc=0x0c08e9e6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c08e9e8;
P_0c08e9e8: /* original fc42, guest PC 0x0c08e9e8 */
if(!s->budget--) { s->failed_pc=0x0c08e9e8u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c08e9ea;
P_0c08e9ea: /* original fe42, guest PC 0x0c08e9ea */
if(!s->budget--) { s->failed_pc=0x0c08e9eau; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c08e9ec;
P_0c08e9ec: /* original f2f1, guest PC 0x0c08e9ec */
if(!s->budget--) { s->failed_pc=0x0c08e9ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'-');
goto P_0c08e9ee;
P_0c08e9ee: /* original fcd1, guest PC 0x0c08e9ee */
if(!s->budget--) { s->failed_pc=0x0c08e9eeu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'-');
goto P_0c08e9f0;
P_0c08e9f0: /* original ff27, guest PC 0x0c08e9f0 */
if(!s->budget--) { s->failed_pc=0x0c08e9f0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08e9f2;
P_0c08e9f2: /* original e004, guest PC 0x0c08e9f2 */
if(!s->budget--) { s->failed_pc=0x0c08e9f2u; return 0; }
r[0]=0x00000004u;
goto P_0c08e9f4;
P_0c08e9f4: /* original f1f6, guest PC 0x0c08e9f4 */
if(!s->budget--) { s->failed_pc=0x0c08e9f4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08e9f6;
P_0c08e9f6: /* original 8f6b, guest PC 0x0c08e9f6 */
if(!s->budget--) { s->failed_pc=0x0c08e9f6u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[1],r[18],'-');
if(!cond) { goto P_0c08ead0; }
goto P_0c08e9fa;
P_0c08e9f8: /* original fe11, guest PC 0x0c08e9f8 */
if(!s->budget--) { s->failed_pc=0x0c08e9f8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[1],r[18],'-');
goto P_0c08e9fa;
P_0c08e9fa: /* original e004, guest PC 0x0c08e9fa */
if(!s->budget--) { s->failed_pc=0x0c08e9fau; return 0; }
r[0]=0x00000004u;
goto P_0c08e9fc;
P_0c08e9fc: /* original f4fc, guest PC 0x0c08e9fc */
if(!s->budget--) { s->failed_pc=0x0c08e9fcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08e9fe;
P_0c08e9fe: /* original f6f6, guest PC 0x0c08e9fe */
if(!s->budget--) { s->failed_pc=0x0c08e9feu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08ea00;
P_0c08ea00: /* original f5dc, guest PC 0x0c08ea00 */
if(!s->budget--) { s->failed_pc=0x0c08ea00u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c08ea02;
P_0c08ea02: /* original 4d0b, guest PC 0x0c08ea02 */
if(!s->budget--) { s->failed_pc=0x0c08ea02u; return 0; }
target=r[13];
r[16]=0x0c08ea06u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ea06u) { target=s->pc; goto dispatch; }
goto P_0c08ea06;
P_0c08ea04: /* original 64f3, guest PC 0x0c08ea04 */
if(!s->budget--) { s->failed_pc=0x0c08ea04u; return 0; }
r[4]=r[15];
goto P_0c08ea06;
P_0c08ea06: /* original f3f8, guest PC 0x0c08ea06 */
if(!s->budget--) { s->failed_pc=0x0c08ea06u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08ea08;
P_0c08ea08: /* original e034, guest PC 0x0c08ea08 */
if(!s->budget--) { s->failed_pc=0x0c08ea08u; return 0; }
r[0]=0x00000034u;
goto P_0c08ea0a;
P_0c08ea0a: /* original f3f2, guest PC 0x0c08ea0a */
if(!s->budget--) { s->failed_pc=0x0c08ea0au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c08ea0c;
P_0c08ea0c: /* original ff37, guest PC 0x0c08ea0c */
if(!s->budget--) { s->failed_pc=0x0c08ea0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ea0e;
P_0c08ea0e: /* original e03c, guest PC 0x0c08ea0e */
if(!s->budget--) { s->failed_pc=0x0c08ea0eu; return 0; }
r[0]=0x0000003cu;
goto P_0c08ea10;
P_0c08ea10: /* original f2f8, guest PC 0x0c08ea10 */
if(!s->budget--) { s->failed_pc=0x0c08ea10u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08ea12;
P_0c08ea12: /* original f2d2, guest PC 0x0c08ea12 */
if(!s->budget--) { s->failed_pc=0x0c08ea12u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c08ea14;
P_0c08ea14: /* original ff27, guest PC 0x0c08ea14 */
if(!s->budget--) { s->failed_pc=0x0c08ea14u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08ea16;
P_0c08ea16: /* original e004, guest PC 0x0c08ea16 */
if(!s->budget--) { s->failed_pc=0x0c08ea16u; return 0; }
r[0]=0x00000004u;
goto P_0c08ea18;
P_0c08ea18: /* original f0f8, guest PC 0x0c08ea18 */
if(!s->budget--) { s->failed_pc=0x0c08ea18u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c08ea1a;
P_0c08ea1a: /* original f1f6, guest PC 0x0c08ea1a */
if(!s->budget--) { s->failed_pc=0x0c08ea1au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08ea1c;
P_0c08ea1c: /* original e040, guest PC 0x0c08ea1c */
if(!s->budget--) { s->failed_pc=0x0c08ea1cu; return 0; }
r[0]=0x00000040u;
goto P_0c08ea1e;
P_0c08ea1e: /* original f012, guest PC 0x0c08ea1e */
if(!s->budget--) { s->failed_pc=0x0c08ea1eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c08ea20;
P_0c08ea20: /* original ff07, guest PC 0x0c08ea20 */
if(!s->budget--) { s->failed_pc=0x0c08ea20u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c08ea22;
P_0c08ea22: /* original e008, guest PC 0x0c08ea22 */
if(!s->budget--) { s->failed_pc=0x0c08ea22u; return 0; }
r[0]=0x00000008u;
goto P_0c08ea24;
P_0c08ea24: /* original f4f6, guest PC 0x0c08ea24 */
if(!s->budget--) { s->failed_pc=0x0c08ea24u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ea26;
P_0c08ea26: /* original f6ec, guest PC 0x0c08ea26 */
if(!s->budget--) { s->failed_pc=0x0c08ea26u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08ea28;
P_0c08ea28: /* original f5cc, guest PC 0x0c08ea28 */
if(!s->budget--) { s->failed_pc=0x0c08ea28u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ea2a;
P_0c08ea2a: /* original 4d0b, guest PC 0x0c08ea2a */
if(!s->budget--) { s->failed_pc=0x0c08ea2au; return 0; }
target=r[13];
r[16]=0x0c08ea2eu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ea2eu) { target=s->pc; goto dispatch; }
goto P_0c08ea2e;
P_0c08ea2c: /* original 64f3, guest PC 0x0c08ea2c */
if(!s->budget--) { s->failed_pc=0x0c08ea2cu; return 0; }
r[4]=r[15];
goto P_0c08ea2e;
P_0c08ea2e: /* original e008, guest PC 0x0c08ea2e */
if(!s->budget--) { s->failed_pc=0x0c08ea2eu; return 0; }
r[0]=0x00000008u;
goto P_0c08ea30;
P_0c08ea30: /* original f2f8, guest PC 0x0c08ea30 */
if(!s->budget--) { s->failed_pc=0x0c08ea30u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08ea32;
P_0c08ea32: /* original f3f6, guest PC 0x0c08ea32 */
if(!s->budget--) { s->failed_pc=0x0c08ea32u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ea34;
P_0c08ea34: /* original e008, guest PC 0x0c08ea34 */
if(!s->budget--) { s->failed_pc=0x0c08ea34u; return 0; }
r[0]=0x00000008u;
goto P_0c08ea36;
P_0c08ea36: /* original f50c, guest PC 0x0c08ea36 */
if(!s->budget--) { s->failed_pc=0x0c08ea36u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c08ea38;
P_0c08ea38: /* original f232, guest PC 0x0c08ea38 */
if(!s->budget--) { s->failed_pc=0x0c08ea38u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08ea3a;
P_0c08ea3a: /* original ff27, guest PC 0x0c08ea3a */
if(!s->budget--) { s->failed_pc=0x0c08ea3au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08ea3c;
P_0c08ea3c: /* original e034, guest PC 0x0c08ea3c */
if(!s->budget--) { s->failed_pc=0x0c08ea3cu; return 0; }
r[0]=0x00000034u;
goto P_0c08ea3e;
P_0c08ea3e: /* original f3cc, guest PC 0x0c08ea3e */
if(!s->budget--) { s->failed_pc=0x0c08ea3eu; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c08ea40;
P_0c08ea40: /* original fcf8, guest PC 0x0c08ea40 */
if(!s->budget--) { s->failed_pc=0x0c08ea40u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c08ea42;
P_0c08ea42: /* original f4f6, guest PC 0x0c08ea42 */
if(!s->budget--) { s->failed_pc=0x0c08ea42u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ea44;
P_0c08ea44: /* original e03c, guest PC 0x0c08ea44 */
if(!s->budget--) { s->failed_pc=0x0c08ea44u; return 0; }
r[0]=0x0000003cu;
goto P_0c08ea46;
P_0c08ea46: /* original fc32, guest PC 0x0c08ea46 */
if(!s->budget--) { s->failed_pc=0x0c08ea46u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c08ea48;
P_0c08ea48: /* original f3ec, guest PC 0x0c08ea48 */
if(!s->budget--) { s->failed_pc=0x0c08ea48u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c08ea4a;
P_0c08ea4a: /* original f422, guest PC 0x0c08ea4a */
if(!s->budget--) { s->failed_pc=0x0c08ea4au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c08ea4c;
P_0c08ea4c: /* original fef8, guest PC 0x0c08ea4c */
if(!s->budget--) { s->failed_pc=0x0c08ea4cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
goto P_0c08ea4e;
P_0c08ea4e: /* original f2f6, guest PC 0x0c08ea4e */
if(!s->budget--) { s->failed_pc=0x0c08ea4eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08ea50;
P_0c08ea50: /* original e040, guest PC 0x0c08ea50 */
if(!s->budget--) { s->failed_pc=0x0c08ea50u; return 0; }
r[0]=0x00000040u;
goto P_0c08ea52;
P_0c08ea52: /* original fe32, guest PC 0x0c08ea52 */
if(!s->budget--) { s->failed_pc=0x0c08ea52u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c08ea54;
P_0c08ea54: /* original f0cc, guest PC 0x0c08ea54 */
if(!s->budget--) { s->failed_pc=0x0c08ea54u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c08ea56;
P_0c08ea56: /* original f34c, guest PC 0x0c08ea56 */
if(!s->budget--) { s->failed_pc=0x0c08ea56u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08ea58;
P_0c08ea58: /* original f32e, guest PC 0x0c08ea58 */
if(!s->budget--) { s->failed_pc=0x0c08ea58u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c08ea5a;
P_0c08ea5a: /* original f2f6, guest PC 0x0c08ea5a */
if(!s->budget--) { s->failed_pc=0x0c08ea5au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08ea5c;
P_0c08ea5c: /* original c758, guest PC 0x0c08ea5c */
if(!s->budget--) { s->failed_pc=0x0c08ea5cu; return 0; }
r[0]=0x0c08ebc0u;
goto P_0c08ea5e;
P_0c08ea5e: /* original f0ec, guest PC 0x0c08ea5e */
if(!s->budget--) { s->failed_pc=0x0c08ea5eu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c08ea60;
P_0c08ea60: /* original f708, guest PC 0x0c08ea60 */
if(!s->budget--) { s->failed_pc=0x0c08ea60u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08ea62;
P_0c08ea62: /* original e028, guest PC 0x0c08ea62 */
if(!s->budget--) { s->failed_pc=0x0c08ea62u; return 0; }
r[0]=0x00000028u;
goto P_0c08ea64;
P_0c08ea64: /* original f32e, guest PC 0x0c08ea64 */
if(!s->budget--) { s->failed_pc=0x0c08ea64u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c08ea66;
P_0c08ea66: /* original f43c, guest PC 0x0c08ea66 */
if(!s->budget--) { s->failed_pc=0x0c08ea66u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08ea68;
P_0c08ea68: /* original f3f6, guest PC 0x0c08ea68 */
if(!s->budget--) { s->failed_pc=0x0c08ea68u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ea6a;
P_0c08ea6a: /* original e02c, guest PC 0x0c08ea6a */
if(!s->budget--) { s->failed_pc=0x0c08ea6au; return 0; }
r[0]=0x0000002cu;
goto P_0c08ea6c;
P_0c08ea6c: /* original f6f6, guest PC 0x0c08ea6c */
if(!s->budget--) { s->failed_pc=0x0c08ea6cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08ea6e;
P_0c08ea6e: /* original f28d, guest PC 0x0c08ea6e */
if(!s->budget--) { s->failed_pc=0x0c08ea6eu; return 0; }
fr[2]=0;
goto P_0c08ea70;
P_0c08ea70: /* original f245, guest PC 0x0c08ea70 */
if(!s->budget--) { s->failed_pc=0x0c08ea70u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c08ea72;
P_0c08ea72: /* original f630, guest PC 0x0c08ea72 */
if(!s->budget--) { s->failed_pc=0x0c08ea72u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c08ea74;
P_0c08ea74: /* original 8d03, guest PC 0x0c08ea74 */
if(!s->budget--) { s->failed_pc=0x0c08ea74u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
if(cond) { goto P_0c08ea7e; }
goto P_0c08ea78;
P_0c08ea76: /* original f672, guest PC 0x0c08ea76 */
if(!s->budget--) { s->failed_pc=0x0c08ea76u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c08ea78;
P_0c08ea78: /* original e02c, guest PC 0x0c08ea78 */
if(!s->budget--) { s->failed_pc=0x0c08ea78u; return 0; }
r[0]=0x0000002cu;
goto P_0c08ea7a;
P_0c08ea7a: /* original a001, guest PC 0x0c08ea7a */
if(!s->budget--) { s->failed_pc=0x0c08ea7au; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c08ea80;
P_0c08ea7c: /* original f8f6, guest PC 0x0c08ea7c */
if(!s->budget--) { s->failed_pc=0x0c08ea7cu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c08ea7e;
P_0c08ea7e: /* original f83c, guest PC 0x0c08ea7e */
if(!s->budget--) { s->failed_pc=0x0c08ea7eu; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c08ea80;
P_0c08ea80: /* original f45d, guest PC 0x0c08ea80 */
if(!s->budget--) { s->failed_pc=0x0c08ea80u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c08ea82;
P_0c08ea82: /* original c750, guest PC 0x0c08ea82 */
if(!s->budget--) { s->failed_pc=0x0c08ea82u; return 0; }
r[0]=0x0c08ebc4u;
goto P_0c08ea84;
P_0c08ea84: /* original f79d, guest PC 0x0c08ea84 */
if(!s->budget--) { s->failed_pc=0x0c08ea84u; return 0; }
fr[7]=0x3f800000u;
goto P_0c08ea86;
P_0c08ea86: /* original f741, guest PC 0x0c08ea86 */
if(!s->budget--) { s->failed_pc=0x0c08ea86u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c08ea88;
P_0c08ea88: /* original f482, guest PC 0x0c08ea88 */
if(!s->budget--) { s->failed_pc=0x0c08ea88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c08ea8a;
P_0c08ea8a: /* original f07c, guest PC 0x0c08ea8a */
if(!s->budget--) { s->failed_pc=0x0c08ea8au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08ea8c;
P_0c08ea8c: /* original f708, guest PC 0x0c08ea8c */
if(!s->budget--) { s->failed_pc=0x0c08ea8cu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08ea8e;
P_0c08ea8e: /* original c74e, guest PC 0x0c08ea8e */
if(!s->budget--) { s->failed_pc=0x0c08ea8eu; return 0; }
r[0]=0x0c08ebc8u;
goto P_0c08ea90;
P_0c08ea90: /* original f34c, guest PC 0x0c08ea90 */
if(!s->budget--) { s->failed_pc=0x0c08ea90u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08ea92;
P_0c08ea92: /* original f36e, guest PC 0x0c08ea92 */
if(!s->budget--) { s->failed_pc=0x0c08ea92u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c08ea94;
P_0c08ea94: /* original f572, guest PC 0x0c08ea94 */
if(!s->budget--) { s->failed_pc=0x0c08ea94u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c08ea96;
P_0c08ea96: /* original f608, guest PC 0x0c08ea96 */
if(!s->budget--) { s->failed_pc=0x0c08ea96u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08ea98;
P_0c08ea98: /* original c74c, guest PC 0x0c08ea98 */
if(!s->budget--) { s->failed_pc=0x0c08ea98u; return 0; }
r[0]=0x0c08ebccu;
goto P_0c08ea9a;
P_0c08ea9a: /* original f208, guest PC 0x0c08ea9a */
if(!s->budget--) { s->failed_pc=0x0c08ea9au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08ea9c;
P_0c08ea9c: /* original f255, guest PC 0x0c08ea9c */
if(!s->budget--) { s->failed_pc=0x0c08ea9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
goto P_0c08ea9e;
P_0c08ea9e: /* original 8f02, guest PC 0x0c08ea9e */
if(!s->budget--) { s->failed_pc=0x0c08ea9eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c08eaa6; }
goto P_0c08eaa2;
P_0c08eaa0: /* original f43c, guest PC 0x0c08eaa0 */
if(!s->budget--) { s->failed_pc=0x0c08eaa0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08eaa2;
P_0c08eaa2: /* original a002, guest PC 0x0c08eaa2 */
if(!s->budget--) { s->failed_pc=0x0c08eaa2u; return 0; }
fr[3]=0;
goto P_0c08eaaa;
P_0c08eaa4: /* original f38d, guest PC 0x0c08eaa4 */
if(!s->budget--) { s->failed_pc=0x0c08eaa4u; return 0; }
fr[3]=0;
goto P_0c08eaa6;
P_0c08eaa6: /* original f35c, guest PC 0x0c08eaa6 */
if(!s->budget--) { s->failed_pc=0x0c08eaa6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08eaa8;
P_0c08eaa8: /* original f37d, guest PC 0x0c08eaa8 */
if(!s->budget--) { s->failed_pc=0x0c08eaa8u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08eaaa;
P_0c08eaaa: /* original f75c, guest PC 0x0c08eaaa */
if(!s->budget--) { s->failed_pc=0x0c08eaaau; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c08eaac;
P_0c08eaac: /* original f732, guest PC 0x0c08eaac */
if(!s->budget--) { s->failed_pc=0x0c08eaacu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08eaae;
P_0c08eaae: /* original f34c, guest PC 0x0c08eaae */
if(!s->budget--) { s->failed_pc=0x0c08eaaeu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08eab0;
P_0c08eab0: /* original f25c, guest PC 0x0c08eab0 */
if(!s->budget--) { s->failed_pc=0x0c08eab0u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c08eab2;
P_0c08eab2: /* original f47c, guest PC 0x0c08eab2 */
if(!s->budget--) { s->failed_pc=0x0c08eab2u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c08eab4;
P_0c08eab4: /* original f432, guest PC 0x0c08eab4 */
if(!s->budget--) { s->failed_pc=0x0c08eab4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c08eab6;
P_0c08eab6: /* original f38d, guest PC 0x0c08eab6 */
if(!s->budget--) { s->failed_pc=0x0c08eab6u; return 0; }
fr[3]=0;
goto P_0c08eab8;
P_0c08eab8: /* original f241, guest PC 0x0c08eab8 */
if(!s->budget--) { s->failed_pc=0x0c08eab8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c08eaba;
P_0c08eaba: /* original f325, guest PC 0x0c08eaba */
if(!s->budget--) { s->failed_pc=0x0c08eabau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c08eabc;
P_0c08eabc: /* original 8b00, guest PC 0x0c08eabc */
if(!s->budget--) { s->failed_pc=0x0c08eabcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08eac0; }
goto P_0c08eabe;
P_0c08eabe: /* original f45c, guest PC 0x0c08eabe */
if(!s->budget--) { s->failed_pc=0x0c08eabeu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08eac0;
P_0c08eac0: /* original f462, guest PC 0x0c08eac0 */
if(!s->budget--) { s->failed_pc=0x0c08eac0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c08eac2;
P_0c08eac2: /* original e008, guest PC 0x0c08eac2 */
if(!s->budget--) { s->failed_pc=0x0c08eac2u; return 0; }
r[0]=0x00000008u;
goto P_0c08eac4;
P_0c08eac4: /* original f3f6, guest PC 0x0c08eac4 */
if(!s->budget--) { s->failed_pc=0x0c08eac4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eac6;
P_0c08eac6: /* original e008, guest PC 0x0c08eac6 */
if(!s->budget--) { s->failed_pc=0x0c08eac6u; return 0; }
r[0]=0x00000008u;
goto P_0c08eac8;
P_0c08eac8: /* original f342, guest PC 0x0c08eac8 */
if(!s->budget--) { s->failed_pc=0x0c08eac8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08eaca;
P_0c08eaca: /* original fc42, guest PC 0x0c08eaca */
if(!s->budget--) { s->failed_pc=0x0c08eacau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c08eacc;
P_0c08eacc: /* original fe42, guest PC 0x0c08eacc */
if(!s->budget--) { s->failed_pc=0x0c08eaccu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c08eace;
P_0c08eace: /* original ff37, guest PC 0x0c08eace */
if(!s->budget--) { s->failed_pc=0x0c08eaceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ead0;
P_0c08ead0: /* original e008, guest PC 0x0c08ead0 */
if(!s->budget--) { s->failed_pc=0x0c08ead0u; return 0; }
r[0]=0x00000008u;
goto P_0c08ead2;
P_0c08ead2: /* original fdc0, guest PC 0x0c08ead2 */
if(!s->budget--) { s->failed_pc=0x0c08ead2u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[12],r[18],'+');
goto P_0c08ead4;
P_0c08ead4: /* original f3f6, guest PC 0x0c08ead4 */
if(!s->budget--) { s->failed_pc=0x0c08ead4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ead6;
P_0c08ead6: /* original e004, guest PC 0x0c08ead6 */
if(!s->budget--) { s->failed_pc=0x0c08ead6u; return 0; }
r[0]=0x00000004u;
goto P_0c08ead8;
P_0c08ead8: /* original f2f6, guest PC 0x0c08ead8 */
if(!s->budget--) { s->failed_pc=0x0c08ead8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08eada;
P_0c08eada: /* original 2ee8, guest PC 0x0c08eada */
if(!s->budget--) { s->failed_pc=0x0c08eadau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08eadc;
P_0c08eadc: /* original ff30, guest PC 0x0c08eadc */
if(!s->budget--) { s->failed_pc=0x0c08eadcu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c08eade;
P_0c08eade: /* original e004, guest PC 0x0c08eade */
if(!s->budget--) { s->failed_pc=0x0c08eadeu; return 0; }
r[0]=0x00000004u;
goto P_0c08eae0;
P_0c08eae0: /* original f2e0, guest PC 0x0c08eae0 */
if(!s->budget--) { s->failed_pc=0x0c08eae0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c08eae2;
P_0c08eae2: /* original 8f3f, guest PC 0x0c08eae2 */
if(!s->budget--) { s->failed_pc=0x0c08eae2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[15]+r[0]);
if(!cond) { goto P_0c08eb64; }
goto P_0c08eae6;
P_0c08eae4: /* original ff27, guest PC 0x0c08eae4 */
if(!s->budget--) { s->failed_pc=0x0c08eae4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eae6;
P_0c08eae6: /* original e00c, guest PC 0x0c08eae6 */
if(!s->budget--) { s->failed_pc=0x0c08eae6u; return 0; }
r[0]=0x0000000cu;
goto P_0c08eae8;
P_0c08eae8: /* original f3f6, guest PC 0x0c08eae8 */
if(!s->budget--) { s->failed_pc=0x0c08eae8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eaea;
P_0c08eaea: /* original e014, guest PC 0x0c08eaea */
if(!s->budget--) { s->failed_pc=0x0c08eaeau; return 0; }
r[0]=0x00000014u;
goto P_0c08eaec;
P_0c08eaec: /* original f2f6, guest PC 0x0c08eaec */
if(!s->budget--) { s->failed_pc=0x0c08eaecu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08eaee;
P_0c08eaee: /* original e00c, guest PC 0x0c08eaee */
if(!s->budget--) { s->failed_pc=0x0c08eaeeu; return 0; }
r[0]=0x0000000cu;
goto P_0c08eaf0;
P_0c08eaf0: /* original f232, guest PC 0x0c08eaf0 */
if(!s->budget--) { s->failed_pc=0x0c08eaf0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08eaf2;
P_0c08eaf2: /* original ff27, guest PC 0x0c08eaf2 */
if(!s->budget--) { s->failed_pc=0x0c08eaf2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eaf4;
P_0c08eaf4: /* original e004, guest PC 0x0c08eaf4 */
if(!s->budget--) { s->failed_pc=0x0c08eaf4u; return 0; }
r[0]=0x00000004u;
goto P_0c08eaf6;
P_0c08eaf6: /* original f6f6, guest PC 0x0c08eaf6 */
if(!s->budget--) { s->failed_pc=0x0c08eaf6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08eaf8;
P_0c08eaf8: /* original f4fc, guest PC 0x0c08eaf8 */
if(!s->budget--) { s->failed_pc=0x0c08eaf8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08eafa;
P_0c08eafa: /* original f5dc, guest PC 0x0c08eafa */
if(!s->budget--) { s->failed_pc=0x0c08eafau; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c08eafc;
P_0c08eafc: /* original 4d0b, guest PC 0x0c08eafc */
if(!s->budget--) { s->failed_pc=0x0c08eafcu; return 0; }
target=r[13];
r[16]=0x0c08eb00u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08eb00u) { target=s->pc; goto dispatch; }
goto P_0c08eb00;
P_0c08eafe: /* original 64f3, guest PC 0x0c08eafe */
if(!s->budget--) { s->failed_pc=0x0c08eafeu; return 0; }
r[4]=r[15];
goto P_0c08eb00;
P_0c08eb00: /* original e00c, guest PC 0x0c08eb00 */
if(!s->budget--) { s->failed_pc=0x0c08eb00u; return 0; }
r[0]=0x0000000cu;
goto P_0c08eb02;
P_0c08eb02: /* original f40c, guest PC 0x0c08eb02 */
if(!s->budget--) { s->failed_pc=0x0c08eb02u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08eb04;
P_0c08eb04: /* original f3f6, guest PC 0x0c08eb04 */
if(!s->budget--) { s->failed_pc=0x0c08eb04u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb06;
P_0c08eb06: /* original f435, guest PC 0x0c08eb06 */
if(!s->budget--) { s->failed_pc=0x0c08eb06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c08eb08;
P_0c08eb08: /* original 8b2c, guest PC 0x0c08eb08 */
if(!s->budget--) { s->failed_pc=0x0c08eb08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08eb64; }
goto P_0c08eb0a;
P_0c08eb0a: /* original f3fc, guest PC 0x0c08eb0a */
if(!s->budget--) { s->failed_pc=0x0c08eb0au; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08eb0c;
P_0c08eb0c: /* original e004, guest PC 0x0c08eb0c */
if(!s->budget--) { s->failed_pc=0x0c08eb0cu; return 0; }
r[0]=0x00000004u;
goto P_0c08eb0e;
P_0c08eb0e: /* original fff8, guest PC 0x0c08eb0e */
if(!s->budget--) { s->failed_pc=0x0c08eb0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c08eb10;
P_0c08eb10: /* original f2f8, guest PC 0x0c08eb10 */
if(!s->budget--) { s->failed_pc=0x0c08eb10u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08eb12;
P_0c08eb12: /* original ff32, guest PC 0x0c08eb12 */
if(!s->budget--) { s->failed_pc=0x0c08eb12u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08eb14;
P_0c08eb14: /* original f3dc, guest PC 0x0c08eb14 */
if(!s->budget--) { s->failed_pc=0x0c08eb14u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c08eb16;
P_0c08eb16: /* original fdf8, guest PC 0x0c08eb16 */
if(!s->budget--) { s->failed_pc=0x0c08eb16u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
goto P_0c08eb18;
P_0c08eb18: /* original fd32, guest PC 0x0c08eb18 */
if(!s->budget--) { s->failed_pc=0x0c08eb18u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c08eb1a;
P_0c08eb1a: /* original f3f6, guest PC 0x0c08eb1a */
if(!s->budget--) { s->failed_pc=0x0c08eb1au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb1c;
P_0c08eb1c: /* original e004, guest PC 0x0c08eb1c */
if(!s->budget--) { s->failed_pc=0x0c08eb1cu; return 0; }
r[0]=0x00000004u;
goto P_0c08eb1e;
P_0c08eb1e: /* original f232, guest PC 0x0c08eb1e */
if(!s->budget--) { s->failed_pc=0x0c08eb1eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08eb20;
P_0c08eb20: /* original ff27, guest PC 0x0c08eb20 */
if(!s->budget--) { s->failed_pc=0x0c08eb20u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eb22;
P_0c08eb22: /* original e00c, guest PC 0x0c08eb22 */
if(!s->budget--) { s->failed_pc=0x0c08eb22u; return 0; }
r[0]=0x0000000cu;
goto P_0c08eb24;
P_0c08eb24: /* original f4f6, guest PC 0x0c08eb24 */
if(!s->budget--) { s->failed_pc=0x0c08eb24u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08eb26;
P_0c08eb26: /* original e004, guest PC 0x0c08eb26 */
if(!s->budget--) { s->failed_pc=0x0c08eb26u; return 0; }
r[0]=0x00000004u;
goto P_0c08eb28;
P_0c08eb28: /* original f242, guest PC 0x0c08eb28 */
if(!s->budget--) { s->failed_pc=0x0c08eb28u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c08eb2a;
P_0c08eb2a: /* original fd42, guest PC 0x0c08eb2a */
if(!s->budget--) { s->failed_pc=0x0c08eb2au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c08eb2c;
P_0c08eb2c: /* original ff42, guest PC 0x0c08eb2c */
if(!s->budget--) { s->failed_pc=0x0c08eb2cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c08eb2e;
P_0c08eb2e: /* original a019, guest PC 0x0c08eb2e */
if(!s->budget--) { s->failed_pc=0x0c08eb2eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eb64;
P_0c08eb30: /* original ff27, guest PC 0x0c08eb30 */
if(!s->budget--) { s->failed_pc=0x0c08eb30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eb32;
P_0c08eb32: /* original 2ee8, guest PC 0x0c08eb32 */
if(!s->budget--) { s->failed_pc=0x0c08eb32u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08eb34;
P_0c08eb34: /* original 8b0a, guest PC 0x0c08eb34 */
if(!s->budget--) { s->failed_pc=0x0c08eb34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08eb4c; }
goto P_0c08eb36;
P_0c08eb36: /* original e038, guest PC 0x0c08eb36 */
if(!s->budget--) { s->failed_pc=0x0c08eb36u; return 0; }
r[0]=0x00000038u;
goto P_0c08eb38;
P_0c08eb38: /* original f3f6, guest PC 0x0c08eb38 */
if(!s->budget--) { s->failed_pc=0x0c08eb38u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb3a;
P_0c08eb3a: /* original e010, guest PC 0x0c08eb3a */
if(!s->budget--) { s->failed_pc=0x0c08eb3au; return 0; }
r[0]=0x00000010u;
goto P_0c08eb3c;
P_0c08eb3c: /* original f2f6, guest PC 0x0c08eb3c */
if(!s->budget--) { s->failed_pc=0x0c08eb3cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08eb3e;
P_0c08eb3e: /* original e010, guest PC 0x0c08eb3e */
if(!s->budget--) { s->failed_pc=0x0c08eb3eu; return 0; }
r[0]=0x00000010u;
goto P_0c08eb40;
P_0c08eb40: /* original f232, guest PC 0x0c08eb40 */
if(!s->budget--) { s->failed_pc=0x0c08eb40u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08eb42;
P_0c08eb42: /* original ff27, guest PC 0x0c08eb42 */
if(!s->budget--) { s->failed_pc=0x0c08eb42u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eb44;
P_0c08eb44: /* original e014, guest PC 0x0c08eb44 */
if(!s->budget--) { s->failed_pc=0x0c08eb44u; return 0; }
r[0]=0x00000014u;
goto P_0c08eb46;
P_0c08eb46: /* original f1f6, guest PC 0x0c08eb46 */
if(!s->budget--) { s->failed_pc=0x0c08eb46u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08eb48;
P_0c08eb48: /* original f125, guest PC 0x0c08eb48 */
if(!s->budget--) { s->failed_pc=0x0c08eb48u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c08eb4a;
P_0c08eb4a: /* original 8902, guest PC 0x0c08eb4a */
if(!s->budget--) { s->failed_pc=0x0c08eb4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08eb52; }
goto P_0c08eb4c;
P_0c08eb4c: /* original e018, guest PC 0x0c08eb4c */
if(!s->budget--) { s->failed_pc=0x0c08eb4cu; return 0; }
r[0]=0x00000018u;
goto P_0c08eb4e;
P_0c08eb4e: /* original f38d, guest PC 0x0c08eb4e */
if(!s->budget--) { s->failed_pc=0x0c08eb4eu; return 0; }
fr[3]=0;
goto P_0c08eb50;
P_0c08eb50: /* original ff37, guest PC 0x0c08eb50 */
if(!s->budget--) { s->failed_pc=0x0c08eb50u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08eb52;
P_0c08eb52: /* original e018, guest PC 0x0c08eb52 */
if(!s->budget--) { s->failed_pc=0x0c08eb52u; return 0; }
r[0]=0x00000018u;
goto P_0c08eb54;
P_0c08eb54: /* original f4f6, guest PC 0x0c08eb54 */
if(!s->budget--) { s->failed_pc=0x0c08eb54u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08eb56;
P_0c08eb56: /* original e004, guest PC 0x0c08eb56 */
if(!s->budget--) { s->failed_pc=0x0c08eb56u; return 0; }
r[0]=0x00000004u;
goto P_0c08eb58;
P_0c08eb58: /* original f3f6, guest PC 0x0c08eb58 */
if(!s->budget--) { s->failed_pc=0x0c08eb58u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb5a;
P_0c08eb5a: /* original e004, guest PC 0x0c08eb5a */
if(!s->budget--) { s->failed_pc=0x0c08eb5au; return 0; }
r[0]=0x00000004u;
goto P_0c08eb5c;
P_0c08eb5c: /* original ff42, guest PC 0x0c08eb5c */
if(!s->budget--) { s->failed_pc=0x0c08eb5cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c08eb5e;
P_0c08eb5e: /* original f342, guest PC 0x0c08eb5e */
if(!s->budget--) { s->failed_pc=0x0c08eb5eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08eb60;
P_0c08eb60: /* original fd42, guest PC 0x0c08eb60 */
if(!s->budget--) { s->failed_pc=0x0c08eb60u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c08eb62;
P_0c08eb62: /* original ff37, guest PC 0x0c08eb62 */
if(!s->budget--) { s->failed_pc=0x0c08eb62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08eb64;
P_0c08eb64: /* original e020, guest PC 0x0c08eb64 */
if(!s->budget--) { s->failed_pc=0x0c08eb64u; return 0; }
r[0]=0x00000020u;
goto P_0c08eb66;
P_0c08eb66: /* original f3f6, guest PC 0x0c08eb66 */
if(!s->budget--) { s->failed_pc=0x0c08eb66u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb68;
P_0c08eb68: /* original e020, guest PC 0x0c08eb68 */
if(!s->budget--) { s->failed_pc=0x0c08eb68u; return 0; }
r[0]=0x00000020u;
goto P_0c08eb6a;
P_0c08eb6a: /* original f3f0, guest PC 0x0c08eb6a */
if(!s->budget--) { s->failed_pc=0x0c08eb6au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c08eb6c;
P_0c08eb6c: /* original ff37, guest PC 0x0c08eb6c */
if(!s->budget--) { s->failed_pc=0x0c08eb6cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08eb6e;
P_0c08eb6e: /* original e01c, guest PC 0x0c08eb6e */
if(!s->budget--) { s->failed_pc=0x0c08eb6eu; return 0; }
r[0]=0x0000001cu;
goto P_0c08eb70;
P_0c08eb70: /* original f2f6, guest PC 0x0c08eb70 */
if(!s->budget--) { s->failed_pc=0x0c08eb70u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08eb72;
P_0c08eb72: /* original e01c, guest PC 0x0c08eb72 */
if(!s->budget--) { s->failed_pc=0x0c08eb72u; return 0; }
r[0]=0x0000001cu;
goto P_0c08eb74;
P_0c08eb74: /* original f2d0, guest PC 0x0c08eb74 */
if(!s->budget--) { s->failed_pc=0x0c08eb74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c08eb76;
P_0c08eb76: /* original ff27, guest PC 0x0c08eb76 */
if(!s->budget--) { s->failed_pc=0x0c08eb76u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08eb78;
P_0c08eb78: /* original e004, guest PC 0x0c08eb78 */
if(!s->budget--) { s->failed_pc=0x0c08eb78u; return 0; }
r[0]=0x00000004u;
goto P_0c08eb7a;
P_0c08eb7a: /* original f1f6, guest PC 0x0c08eb7a */
if(!s->budget--) { s->failed_pc=0x0c08eb7au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08eb7c;
P_0c08eb7c: /* original e024, guest PC 0x0c08eb7c */
if(!s->budget--) { s->failed_pc=0x0c08eb7cu; return 0; }
r[0]=0x00000024u;
goto P_0c08eb7e;
P_0c08eb7e: /* original f0f6, guest PC 0x0c08eb7e */
if(!s->budget--) { s->failed_pc=0x0c08eb7eu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c08eb80;
P_0c08eb80: /* original e024, guest PC 0x0c08eb80 */
if(!s->budget--) { s->failed_pc=0x0c08eb80u; return 0; }
r[0]=0x00000024u;
goto P_0c08eb82;
P_0c08eb82: /* original f010, guest PC 0x0c08eb82 */
if(!s->budget--) { s->failed_pc=0x0c08eb82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'+');
goto P_0c08eb84;
P_0c08eb84: /* original ff07, guest PC 0x0c08eb84 */
if(!s->budget--) { s->failed_pc=0x0c08eb84u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c08eb86;
P_0c08eb86: /* original e004, guest PC 0x0c08eb86 */
if(!s->budget--) { s->failed_pc=0x0c08eb86u; return 0; }
r[0]=0x00000004u;
goto P_0c08eb88;
P_0c08eb88: /* original 54fc, guest PC 0x0c08eb88 */
if(!s->budget--) { s->failed_pc=0x0c08eb88u; return 0; }
r[4]=read(ram,r[15]+48,4);
goto P_0c08eb8a;
P_0c08eb8a: /* original f3f6, guest PC 0x0c08eb8a */
if(!s->budget--) { s->failed_pc=0x0c08eb8au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb8c;
P_0c08eb8c: /* original e024, guest PC 0x0c08eb8c */
if(!s->budget--) { s->failed_pc=0x0c08eb8cu; return 0; }
r[0]=0x00000024u;
goto P_0c08eb8e;
P_0c08eb8e: /* original 742c, guest PC 0x0c08eb8e */
if(!s->budget--) { s->failed_pc=0x0c08eb8eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c08eb90;
P_0c08eb90: /* original f43a, guest PC 0x0c08eb90 */
if(!s->budget--) { s->failed_pc=0x0c08eb90u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c08eb92;
P_0c08eb92: /* original f4db, guest PC 0x0c08eb92 */
if(!s->budget--) { s->failed_pc=0x0c08eb92u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[4]);
goto P_0c08eb94;
P_0c08eb94: /* original f4fb, guest PC 0x0c08eb94 */
if(!s->budget--) { s->failed_pc=0x0c08eb94u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[4]);
goto P_0c08eb96;
P_0c08eb96: /* original f3f6, guest PC 0x0c08eb96 */
if(!s->budget--) { s->failed_pc=0x0c08eb96u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb98;
P_0c08eb98: /* original e01c, guest PC 0x0c08eb98 */
if(!s->budget--) { s->failed_pc=0x0c08eb98u; return 0; }
r[0]=0x0000001cu;
goto P_0c08eb9a;
P_0c08eb9a: /* original f43b, guest PC 0x0c08eb9a */
if(!s->budget--) { s->failed_pc=0x0c08eb9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c08eb9c;
P_0c08eb9c: /* original f3f6, guest PC 0x0c08eb9c */
if(!s->budget--) { s->failed_pc=0x0c08eb9cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eb9e;
P_0c08eb9e: /* original e020, guest PC 0x0c08eb9e */
if(!s->budget--) { s->failed_pc=0x0c08eb9eu; return 0; }
r[0]=0x00000020u;
goto P_0c08eba0;
P_0c08eba0: /* original f43b, guest PC 0x0c08eba0 */
if(!s->budget--) { s->failed_pc=0x0c08eba0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c08eba2;
P_0c08eba2: /* original f3f6, guest PC 0x0c08eba2 */
if(!s->budget--) { s->failed_pc=0x0c08eba2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08eba4;
P_0c08eba4: /* original 7f44, guest PC 0x0c08eba4 */
if(!s->budget--) { s->failed_pc=0x0c08eba4u; return 0; }
r[15]+=0x00000044u;
goto P_0c08eba6;
P_0c08eba6: /* original f43b, guest PC 0x0c08eba6 */
if(!s->budget--) { s->failed_pc=0x0c08eba6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c08eba8;
P_0c08eba8: /* original 4f26, guest PC 0x0c08eba8 */
if(!s->budget--) { s->failed_pc=0x0c08eba8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ebaa;
P_0c08ebaa: /* original fcf9, guest PC 0x0c08ebaa */
if(!s->budget--) { s->failed_pc=0x0c08ebaau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ebac;
P_0c08ebac: /* original fdf9, guest PC 0x0c08ebac */
if(!s->budget--) { s->failed_pc=0x0c08ebacu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ebae;
P_0c08ebae: /* original fef9, guest PC 0x0c08ebae */
if(!s->budget--) { s->failed_pc=0x0c08ebaeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ebb0;
P_0c08ebb0: /* original fff9, guest PC 0x0c08ebb0 */
if(!s->budget--) { s->failed_pc=0x0c08ebb0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ebb2;
P_0c08ebb2: /* original 6cf6, guest PC 0x0c08ebb2 */
if(!s->budget--) { s->failed_pc=0x0c08ebb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ebb4;
P_0c08ebb4: /* original 6df6, guest PC 0x0c08ebb4 */
if(!s->budget--) { s->failed_pc=0x0c08ebb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ebb6;
P_0c08ebb6: /* original 000b, guest PC 0x0c08ebb6 */
if(!s->budget--) { s->failed_pc=0x0c08ebb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ebb8: /* original 6ef6, guest PC 0x0c08ebb8 */
if(!s->budget--) { s->failed_pc=0x0c08ebb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08ebbau,s,ram);
P_0c091f60: /* original 4f22, guest PC 0x0c091f60 */
if(!s->budget--) { s->failed_pc=0x0c091f60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091f62;
P_0c091f62: /* original d138, guest PC 0x0c091f62 */
if(!s->budget--) { s->failed_pc=0x0c091f62u; return 0; }
r[1]=read(ram,0x0c092044u,4);
goto P_0c091f64;
P_0c091f64: /* original d336, guest PC 0x0c091f64 */
if(!s->budget--) { s->failed_pc=0x0c091f64u; return 0; }
r[3]=read(ram,0x0c092040u,4);
goto P_0c091f66;
P_0c091f66: /* original 4f12, guest PC 0x0c091f66 */
if(!s->budget--) { s->failed_pc=0x0c091f66u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c091f68;
P_0c091f68: /* original 6212, guest PC 0x0c091f68 */
if(!s->budget--) { s->failed_pc=0x0c091f68u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091f6a;
P_0c091f6a: /* original de34, guest PC 0x0c091f6a */
if(!s->budget--) { s->failed_pc=0x0c091f6au; return 0; }
r[14]=read(ram,0x0c09203cu,4);
goto P_0c091f6c;
P_0c091f6c: /* original d931, guest PC 0x0c091f6c */
if(!s->budget--) { s->failed_pc=0x0c091f6cu; return 0; }
r[9]=read(ram,0x0c092034u,4);
goto P_0c091f6e;
P_0c091f6e: /* original 2238, guest PC 0x0c091f6e */
if(!s->budget--) { s->failed_pc=0x0c091f6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091f70;
P_0c091f70: /* original dc31, guest PC 0x0c091f70 */
if(!s->budget--) { s->failed_pc=0x0c091f70u; return 0; }
r[12]=read(ram,0x0c092038u,4);
goto P_0c091f72;
P_0c091f72: /* original 7ff4, guest PC 0x0c091f72 */
if(!s->budget--) { s->failed_pc=0x0c091f72u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091f74;
P_0c091f74: /* original 8d02, guest PC 0x0c091f74 */
if(!s->budget--) { s->failed_pc=0x0c091f74u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c091f7c; }
goto P_0c091f78;
P_0c091f76: /* original ed00, guest PC 0x0c091f76 */
if(!s->budget--) { s->failed_pc=0x0c091f76u; return 0; }
r[13]=0x00000000u;
goto P_0c091f78;
P_0c091f78: /* original a137, guest PC 0x0c091f78 */
if(!s->budget--) { s->failed_pc=0x0c091f78u; return 0; }
goto P_0c0921ea;
P_0c091f7a: /* original 0009, guest PC 0x0c091f7a */
if(!s->budget--) { s->failed_pc=0x0c091f7au; return 0; }
goto P_0c091f7c;
P_0c091f7c: /* original d632, guest PC 0x0c091f7c */
if(!s->budget--) { s->failed_pc=0x0c091f7cu; return 0; }
r[6]=read(ram,0x0c092048u,4);
goto P_0c091f7e;
P_0c091f7e: /* original 6043, guest PC 0x0c091f7e */
if(!s->budget--) { s->failed_pc=0x0c091f7eu; return 0; }
r[0]=r[4];
goto P_0c091f80;
P_0c091f80: /* original 8801, guest PC 0x0c091f80 */
if(!s->budget--) { s->failed_pc=0x0c091f80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c091f82;
P_0c091f82: /* original 5564, guest PC 0x0c091f82 */
if(!s->budget--) { s->failed_pc=0x0c091f82u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c091f84;
P_0c091f84: /* original 8d01, guest PC 0x0c091f84 */
if(!s->budget--) { s->failed_pc=0x0c091f84u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(cond) { goto P_0c091f8a; }
goto P_0c091f88;
P_0c091f86: /* original 5665, guest PC 0x0c091f86 */
if(!s->budget--) { s->failed_pc=0x0c091f86u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c091f88;
P_0c091f88: /* original 6563, guest PC 0x0c091f88 */
if(!s->budget--) { s->failed_pc=0x0c091f88u; return 0; }
r[5]=r[6];
goto P_0c091f8a;
P_0c091f8a: /* original 8454, guest PC 0x0c091f8a */
if(!s->budget--) { s->failed_pc=0x0c091f8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c091f8c;
P_0c091f8c: /* original da2f, guest PC 0x0c091f8c */
if(!s->budget--) { s->failed_pc=0x0c091f8cu; return 0; }
r[10]=read(ram,0x0c09204cu,4);
goto P_0c091f8e;
P_0c091f8e: /* original 640c, guest PC 0x0c091f8e */
if(!s->budget--) { s->failed_pc=0x0c091f8eu; return 0; }
r[4]=r[0]&255u;
goto P_0c091f90;
P_0c091f90: /* original 6343, guest PC 0x0c091f90 */
if(!s->budget--) { s->failed_pc=0x0c091f90u; return 0; }
r[3]=r[4];
goto P_0c091f92;
P_0c091f92: /* original 4300, guest PC 0x0c091f92 */
if(!s->budget--) { s->failed_pc=0x0c091f92u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c091f94;
P_0c091f94: /* original 6243, guest PC 0x0c091f94 */
if(!s->budget--) { s->failed_pc=0x0c091f94u; return 0; }
r[2]=r[4];
goto P_0c091f96;
P_0c091f96: /* original 332c, guest PC 0x0c091f96 */
if(!s->budget--) { s->failed_pc=0x0c091f96u; return 0; }
r[3]+=r[2];
goto P_0c091f98;
P_0c091f98: /* original 4308, guest PC 0x0c091f98 */
if(!s->budget--) { s->failed_pc=0x0c091f98u; return 0; }
r[3]<<=2;
goto P_0c091f9a;
P_0c091f9a: /* original 6b43, guest PC 0x0c091f9a */
if(!s->budget--) { s->failed_pc=0x0c091f9au; return 0; }
r[11]=r[4];
goto P_0c091f9c;
P_0c091f9c: /* original 4308, guest PC 0x0c091f9c */
if(!s->budget--) { s->failed_pc=0x0c091f9cu; return 0; }
r[3]<<=2;
goto P_0c091f9e;
P_0c091f9e: /* original 4300, guest PC 0x0c091f9e */
if(!s->budget--) { s->failed_pc=0x0c091f9eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c091fa0;
P_0c091fa0: /* original 3a3c, guest PC 0x0c091fa0 */
if(!s->budget--) { s->failed_pc=0x0c091fa0u; return 0; }
r[10]+=r[3];
goto P_0c091fa2;
P_0c091fa2: /* original 63a3, guest PC 0x0c091fa2 */
if(!s->budget--) { s->failed_pc=0x0c091fa2u; return 0; }
r[3]=r[10];
goto P_0c091fa4;
P_0c091fa4: /* original 7320, guest PC 0x0c091fa4 */
if(!s->budget--) { s->failed_pc=0x0c091fa4u; return 0; }
r[3]+=0x00000020u;
goto P_0c091fa6;
P_0c091fa6: /* original 1f32, guest PC 0x0c091fa6 */
if(!s->budget--) { s->failed_pc=0x0c091fa6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091fa8;
P_0c091fa8: /* original e32a, guest PC 0x0c091fa8 */
if(!s->budget--) { s->failed_pc=0x0c091fa8u; return 0; }
r[3]=0x0000002au;
goto P_0c091faa;
P_0c091faa: /* original 903e, guest PC 0x0c091faa */
if(!s->budget--) { s->failed_pc=0x0c091faau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202au,2);
goto P_0c091fac;
P_0c091fac: /* original 0b37, guest PC 0x0c091fac */
if(!s->budget--) { s->failed_pc=0x0c091facu; return 0; }
r[19]=r[11]*r[3];
goto P_0c091fae;
P_0c091fae: /* original 025d, guest PC 0x0c091fae */
if(!s->budget--) { s->failed_pc=0x0c091faeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091fb0;
P_0c091fb0: /* original 2f22, guest PC 0x0c091fb0 */
if(!s->budget--) { s->failed_pc=0x0c091fb0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091fb2;
P_0c091fb2: /* original 903b, guest PC 0x0c091fb2 */
if(!s->budget--) { s->failed_pc=0x0c091fb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202cu,2);
goto P_0c091fb4;
P_0c091fb4: /* original 0b1a, guest PC 0x0c091fb4 */
if(!s->budget--) { s->failed_pc=0x0c091fb4u; return 0; }
r[11]=r[19];
goto P_0c091fb6;
P_0c091fb6: /* original 045d, guest PC 0x0c091fb6 */
if(!s->budget--) { s->failed_pc=0x0c091fb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091fb8;
P_0c091fb8: /* original d125, guest PC 0x0c091fb8 */
if(!s->budget--) { s->failed_pc=0x0c091fb8u; return 0; }
r[1]=read(ram,0x0c092050u,4);
goto P_0c091fba;
P_0c091fba: /* original 3248, guest PC 0x0c091fba */
if(!s->budget--) { s->failed_pc=0x0c091fbau; return 0; }
r[2]-=r[4];
goto P_0c091fbc;
P_0c091fbc: /* original 6612, guest PC 0x0c091fbc */
if(!s->budget--) { s->failed_pc=0x0c091fbcu; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c091fbe;
P_0c091fbe: /* original 6423, guest PC 0x0c091fbe */
if(!s->budget--) { s->failed_pc=0x0c091fbeu; return 0; }
r[4]=r[2];
goto P_0c091fc0;
P_0c091fc0: /* original e204, guest PC 0x0c091fc0 */
if(!s->budget--) { s->failed_pc=0x0c091fc0u; return 0; }
r[2]=0x00000004u;
goto P_0c091fc2;
P_0c091fc2: /* original 7b02, guest PC 0x0c091fc2 */
if(!s->budget--) { s->failed_pc=0x0c091fc2u; return 0; }
r[11]+=0x00000002u;
goto P_0c091fc4;
P_0c091fc4: /* original 2628, guest PC 0x0c091fc4 */
if(!s->budget--) { s->failed_pc=0x0c091fc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c091fc6;
P_0c091fc6: /* original 65b3, guest PC 0x0c091fc6 */
if(!s->budget--) { s->failed_pc=0x0c091fc6u; return 0; }
r[5]=r[11];
goto P_0c091fc8;
P_0c091fc8: /* original 8d20, guest PC 0x0c091fc8 */
if(!s->budget--) { s->failed_pc=0x0c091fc8u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffd4u;
if(cond) { goto P_0c09200c; }
goto P_0c091fcc;
P_0c091fca: /* original 75d4, guest PC 0x0c091fca */
if(!s->budget--) { s->failed_pc=0x0c091fcau; return 0; }
r[5]+=0xffffffd4u;
goto P_0c091fcc;
P_0c091fcc: /* original 2558, guest PC 0x0c091fcc */
if(!s->budget--) { s->failed_pc=0x0c091fccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c091fce;
P_0c091fce: /* original 890c, guest PC 0x0c091fce */
if(!s->budget--) { s->failed_pc=0x0c091fceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091fea; }
goto P_0c091fd0;
P_0c091fd0: /* original 2448, guest PC 0x0c091fd0 */
if(!s->budget--) { s->failed_pc=0x0c091fd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091fd2;
P_0c091fd2: /* original 895c, guest PC 0x0c091fd2 */
if(!s->budget--) { s->failed_pc=0x0c091fd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c091fd4;
P_0c091fd4: /* original e320, guest PC 0x0c091fd4 */
if(!s->budget--) { s->failed_pc=0x0c091fd4u; return 0; }
r[3]=0x00000020u;
goto P_0c091fd6;
P_0c091fd6: /* original e610, guest PC 0x0c091fd6 */
if(!s->budget--) { s->failed_pc=0x0c091fd6u; return 0; }
r[6]=0x00000010u;
goto P_0c091fd8;
P_0c091fd8: /* original 2f36, guest PC 0x0c091fd8 */
if(!s->budget--) { s->failed_pc=0x0c091fd8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091fda;
P_0c091fda: /* original 9528, guest PC 0x0c091fda */
if(!s->budget--) { s->failed_pc=0x0c091fdau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09202eu,2);
goto P_0c091fdc;
P_0c091fdc: /* original e702, guest PC 0x0c091fdc */
if(!s->budget--) { s->failed_pc=0x0c091fdcu; return 0; }
r[7]=0x00000002u;
goto P_0c091fde;
P_0c091fde: /* original 490b, guest PC 0x0c091fde */
if(!s->budget--) { s->failed_pc=0x0c091fdeu; return 0; }
target=r[9];
r[16]=0x0c091fe2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091fe2u) { target=s->pc; goto dispatch; }
goto P_0c091fe2;
P_0c091fe0: /* original 64e3, guest PC 0x0c091fe0 */
if(!s->budget--) { s->failed_pc=0x0c091fe0u; return 0; }
r[4]=r[14];
goto P_0c091fe2;
P_0c091fe2: /* original d51d, guest PC 0x0c091fe2 */
if(!s->budget--) { s->failed_pc=0x0c091fe2u; return 0; }
r[5]=read(ram,0x0c092058u,4);
goto P_0c091fe4;
P_0c091fe4: /* original d61b, guest PC 0x0c091fe4 */
if(!s->budget--) { s->failed_pc=0x0c091fe4u; return 0; }
r[6]=read(ram,0x0c092054u,4);
goto P_0c091fe6;
P_0c091fe6: /* original a04f, guest PC 0x0c091fe6 */
if(!s->budget--) { s->failed_pc=0x0c091fe6u; return 0; }
r[15]+=0x00000004u;
goto P_0c092088;
P_0c091fe8: /* original 7f04, guest PC 0x0c091fe8 */
if(!s->budget--) { s->failed_pc=0x0c091fe8u; return 0; }
r[15]+=0x00000004u;
goto P_0c091fea;
P_0c091fea: /* original 2448, guest PC 0x0c091fea */
if(!s->budget--) { s->failed_pc=0x0c091feau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c091fec;
P_0c091fec: /* original 894f, guest PC 0x0c091fec */
if(!s->budget--) { s->failed_pc=0x0c091fecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c091fee;
P_0c091fee: /* original e320, guest PC 0x0c091fee */
if(!s->budget--) { s->failed_pc=0x0c091feeu; return 0; }
r[3]=0x00000020u;
goto P_0c091ff0;
P_0c091ff0: /* original e610, guest PC 0x0c091ff0 */
if(!s->budget--) { s->failed_pc=0x0c091ff0u; return 0; }
r[6]=0x00000010u;
goto P_0c091ff2;
P_0c091ff2: /* original 2f36, guest PC 0x0c091ff2 */
if(!s->budget--) { s->failed_pc=0x0c091ff2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091ff4;
P_0c091ff4: /* original 951c, guest PC 0x0c091ff4 */
if(!s->budget--) { s->failed_pc=0x0c091ff4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092030u,2);
goto P_0c091ff6;
P_0c091ff6: /* original e702, guest PC 0x0c091ff6 */
if(!s->budget--) { s->failed_pc=0x0c091ff6u; return 0; }
r[7]=0x00000002u;
goto P_0c091ff8;
P_0c091ff8: /* original 490b, guest PC 0x0c091ff8 */
if(!s->budget--) { s->failed_pc=0x0c091ff8u; return 0; }
target=r[9];
r[16]=0x0c091ffcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ffcu) { target=s->pc; goto dispatch; }
goto P_0c091ffc;
P_0c091ffa: /* original 64e3, guest PC 0x0c091ffa */
if(!s->budget--) { s->failed_pc=0x0c091ffau; return 0; }
r[4]=r[14];
goto P_0c091ffc;
P_0c091ffc: /* original d518, guest PC 0x0c091ffc */
if(!s->budget--) { s->failed_pc=0x0c091ffcu; return 0; }
r[5]=read(ram,0x0c092060u,4);
goto P_0c091ffe;
P_0c091ffe: /* original 7f04, guest PC 0x0c091ffe */
if(!s->budget--) { s->failed_pc=0x0c091ffeu; return 0; }
r[15]+=0x00000004u;
goto P_0c092000;
P_0c092000: /* original d616, guest PC 0x0c092000 */
if(!s->budget--) { s->failed_pc=0x0c092000u; return 0; }
r[6]=read(ram,0x0c09205cu,4);
goto P_0c092002;
P_0c092002: /* original d218, guest PC 0x0c092002 */
if(!s->budget--) { s->failed_pc=0x0c092002u; return 0; }
r[2]=read(ram,0x0c092064u,4);
goto P_0c092004;
P_0c092004: /* original 420b, guest PC 0x0c092004 */
if(!s->budget--) { s->failed_pc=0x0c092004u; return 0; }
target=r[2];
r[16]=0x0c092008u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092008u) { target=s->pc; goto dispatch; }
goto P_0c092008;
P_0c092006: /* original 64e3, guest PC 0x0c092006 */
if(!s->budget--) { s->failed_pc=0x0c092006u; return 0; }
r[4]=r[14];
goto P_0c092008;
P_0c092008: /* original a041, guest PC 0x0c092008 */
if(!s->budget--) { s->failed_pc=0x0c092008u; return 0; }
goto P_0c09208e;
P_0c09200a: /* original 0009, guest PC 0x0c09200a */
if(!s->budget--) { s->failed_pc=0x0c09200au; return 0; }
goto P_0c09200c;
P_0c09200c: /* original 2558, guest PC 0x0c09200c */
if(!s->budget--) { s->failed_pc=0x0c09200cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09200e;
P_0c09200e: /* original 892f, guest PC 0x0c09200e */
if(!s->budget--) { s->failed_pc=0x0c09200eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092070; }
goto P_0c092010;
P_0c092010: /* original 2448, guest PC 0x0c092010 */
if(!s->budget--) { s->failed_pc=0x0c092010u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092012;
P_0c092012: /* original 893c, guest PC 0x0c092012 */
if(!s->budget--) { s->failed_pc=0x0c092012u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c092014;
P_0c092014: /* original e320, guest PC 0x0c092014 */
if(!s->budget--) { s->failed_pc=0x0c092014u; return 0; }
r[3]=0x00000020u;
goto P_0c092016;
P_0c092016: /* original e610, guest PC 0x0c092016 */
if(!s->budget--) { s->failed_pc=0x0c092016u; return 0; }
r[6]=0x00000010u;
goto P_0c092018;
P_0c092018: /* original 2f36, guest PC 0x0c092018 */
if(!s->budget--) { s->failed_pc=0x0c092018u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09201a;
P_0c09201a: /* original 950a, guest PC 0x0c09201a */
if(!s->budget--) { s->failed_pc=0x0c09201au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092032u,2);
goto P_0c09201c;
P_0c09201c: /* original e702, guest PC 0x0c09201c */
if(!s->budget--) { s->failed_pc=0x0c09201cu; return 0; }
r[7]=0x00000002u;
goto P_0c09201e;
P_0c09201e: /* original 490b, guest PC 0x0c09201e */
if(!s->budget--) { s->failed_pc=0x0c09201eu; return 0; }
target=r[9];
r[16]=0x0c092022u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092022u) { target=s->pc; goto dispatch; }
goto P_0c092022;
P_0c092020: /* original 64e3, guest PC 0x0c092020 */
if(!s->budget--) { s->failed_pc=0x0c092020u; return 0; }
r[4]=r[14];
goto P_0c092022;
P_0c092022: /* original d512, guest PC 0x0c092022 */
if(!s->budget--) { s->failed_pc=0x0c092022u; return 0; }
r[5]=read(ram,0x0c09206cu,4);
goto P_0c092024;
P_0c092024: /* original d610, guest PC 0x0c092024 */
if(!s->budget--) { s->failed_pc=0x0c092024u; return 0; }
r[6]=read(ram,0x0c092068u,4);
goto P_0c092026;
P_0c092026: /* original afec, guest PC 0x0c092026 */
if(!s->budget--) { s->failed_pc=0x0c092026u; return 0; }
r[15]+=0x00000004u;
goto P_0c092002;
P_0c092028: /* original 7f04, guest PC 0x0c092028 */
if(!s->budget--) { s->failed_pc=0x0c092028u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c09202au,s,ram);
P_0c092070: /* original 2448, guest PC 0x0c092070 */
if(!s->budget--) { s->failed_pc=0x0c092070u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092072;
P_0c092072: /* original 890c, guest PC 0x0c092072 */
if(!s->budget--) { s->failed_pc=0x0c092072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09208e; }
goto P_0c092074;
P_0c092074: /* original e320, guest PC 0x0c092074 */
if(!s->budget--) { s->failed_pc=0x0c092074u; return 0; }
r[3]=0x00000020u;
goto P_0c092076;
P_0c092076: /* original e610, guest PC 0x0c092076 */
if(!s->budget--) { s->failed_pc=0x0c092076u; return 0; }
r[6]=0x00000010u;
goto P_0c092078;
P_0c092078: /* original 2f36, guest PC 0x0c092078 */
if(!s->budget--) { s->failed_pc=0x0c092078u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09207a;
P_0c09207a: /* original 956f, guest PC 0x0c09207a */
if(!s->budget--) { s->failed_pc=0x0c09207au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09215cu,2);
goto P_0c09207c;
P_0c09207c: /* original e702, guest PC 0x0c09207c */
if(!s->budget--) { s->failed_pc=0x0c09207cu; return 0; }
r[7]=0x00000002u;
goto P_0c09207e;
P_0c09207e: /* original 490b, guest PC 0x0c09207e */
if(!s->budget--) { s->failed_pc=0x0c09207eu; return 0; }
target=r[9];
r[16]=0x0c092082u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092082u) { target=s->pc; goto dispatch; }
goto P_0c092082;
P_0c092080: /* original 64e3, guest PC 0x0c092080 */
if(!s->budget--) { s->failed_pc=0x0c092080u; return 0; }
r[4]=r[14];
goto P_0c092082;
P_0c092082: /* original d53a, guest PC 0x0c092082 */
if(!s->budget--) { s->failed_pc=0x0c092082u; return 0; }
r[5]=read(ram,0x0c09216cu,4);
goto P_0c092084;
P_0c092084: /* original 7f04, guest PC 0x0c092084 */
if(!s->budget--) { s->failed_pc=0x0c092084u; return 0; }
r[15]+=0x00000004u;
goto P_0c092086;
P_0c092086: /* original d638, guest PC 0x0c092086 */
if(!s->budget--) { s->failed_pc=0x0c092086u; return 0; }
r[6]=read(ram,0x0c092168u,4);
goto P_0c092088;
P_0c092088: /* original d239, guest PC 0x0c092088 */
if(!s->budget--) { s->failed_pc=0x0c092088u; return 0; }
r[2]=read(ram,0x0c092170u,4);
goto P_0c09208a;
P_0c09208a: /* original 420b, guest PC 0x0c09208a */
if(!s->budget--) { s->failed_pc=0x0c09208au; return 0; }
target=r[2];
r[16]=0x0c09208eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09208eu) { target=s->pc; goto dispatch; }
goto P_0c09208e;
P_0c09208c: /* original 64e3, guest PC 0x0c09208c */
if(!s->budget--) { s->failed_pc=0x0c09208cu; return 0; }
r[4]=r[14];
goto P_0c09208e;
P_0c09208e: /* original 9266, guest PC 0x0c09208e */
if(!s->budget--) { s->failed_pc=0x0c09208eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09215eu,2);
goto P_0c092090;
P_0c092090: /* original 4b00, guest PC 0x0c092090 */
if(!s->budget--) { s->failed_pc=0x0c092090u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c092092;
P_0c092092: /* original e320, guest PC 0x0c092092 */
if(!s->budget--) { s->failed_pc=0x0c092092u; return 0; }
r[3]=0x00000020u;
goto P_0c092094;
P_0c092094: /* original 2b2b, guest PC 0x0c092094 */
if(!s->budget--) { s->failed_pc=0x0c092094u; return 0; }
r[11]|=r[2];
goto P_0c092096;
P_0c092096: /* original 1fb1, guest PC 0x0c092096 */
if(!s->budget--) { s->failed_pc=0x0c092096u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c092098;
P_0c092098: /* original e60a, guest PC 0x0c092098 */
if(!s->budget--) { s->failed_pc=0x0c092098u; return 0; }
r[6]=0x0000000au;
goto P_0c09209a;
P_0c09209a: /* original 2f36, guest PC 0x0c09209a */
if(!s->budget--) { s->failed_pc=0x0c09209au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09209c;
P_0c09209c: /* original e702, guest PC 0x0c09209c */
if(!s->budget--) { s->failed_pc=0x0c09209cu; return 0; }
r[7]=0x00000002u;
goto P_0c09209e;
P_0c09209e: /* original 55f2, guest PC 0x0c09209e */
if(!s->budget--) { s->failed_pc=0x0c09209eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0920a0;
P_0c0920a0: /* original 490b, guest PC 0x0c0920a0 */
if(!s->budget--) { s->failed_pc=0x0c0920a0u; return 0; }
target=r[9];
r[16]=0x0c0920a4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0920a4u) { target=s->pc; goto dispatch; }
goto P_0c0920a4;
P_0c0920a2: /* original 64e3, guest PC 0x0c0920a2 */
if(!s->budget--) { s->failed_pc=0x0c0920a2u; return 0; }
r[4]=r[14];
goto P_0c0920a4;
P_0c0920a4: /* original 7f04, guest PC 0x0c0920a4 */
if(!s->budget--) { s->failed_pc=0x0c0920a4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0920a6;
P_0c0920a6: /* original 60f2, guest PC 0x0c0920a6 */
if(!s->budget--) { s->failed_pc=0x0c0920a6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0920a8;
P_0c0920a8: /* original e2fc, guest PC 0x0c0920a8 */
if(!s->budget--) { s->failed_pc=0x0c0920a8u; return 0; }
r[2]=0xfffffffcu;
goto P_0c0920aa;
P_0c0920aa: /* original c91f, guest PC 0x0c0920aa */
if(!s->budget--) { s->failed_pc=0x0c0920aau; return 0; }
r[0]&=31u;
goto P_0c0920ac;
P_0c0920ac: /* original 2f02, guest PC 0x0c0920ac */
if(!s->budget--) { s->failed_pc=0x0c0920acu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0920ae;
P_0c0920ae: /* original 53f2, guest PC 0x0c0920ae */
if(!s->budget--) { s->failed_pc=0x0c0920aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0920b0;
P_0c0920b0: /* original 05ac, guest PC 0x0c0920b0 */
if(!s->budget--) { s->failed_pc=0x0c0920b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0920b2;
P_0c0920b2: /* original 4000, guest PC 0x0c0920b2 */
if(!s->budget--) { s->failed_pc=0x0c0920b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0920b4;
P_0c0920b4: /* original 003d, guest PC 0x0c0920b4 */
if(!s->budget--) { s->failed_pc=0x0c0920b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0920b6;
P_0c0920b6: /* original 655c, guest PC 0x0c0920b6 */
if(!s->budget--) { s->failed_pc=0x0c0920b6u; return 0; }
r[5]=r[5]&255u;
goto P_0c0920b8;
P_0c0920b8: /* original 675d, guest PC 0x0c0920b8 */
if(!s->budget--) { s->failed_pc=0x0c0920b8u; return 0; }
r[7]=r[5]&65535u;
goto P_0c0920ba;
P_0c0920ba: /* original 81f4, guest PC 0x0c0920ba */
if(!s->budget--) { s->failed_pc=0x0c0920bau; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0920bc;
P_0c0920bc: /* original 5bf1, guest PC 0x0c0920bc */
if(!s->budget--) { s->failed_pc=0x0c0920bcu; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c0920be;
P_0c0920be: /* original 2f72, guest PC 0x0c0920be */
if(!s->budget--) { s->failed_pc=0x0c0920beu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0920c0;
P_0c0920c0: /* original 472c, guest PC 0x0c0920c0 */
if(!s->budget--) { s->failed_pc=0x0c0920c0u; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[7]>>((-r[2])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[2]&31u);
goto P_0c0920c2;
P_0c0920c2: /* original d02c, guest PC 0x0c0920c2 */
if(!s->budget--) { s->failed_pc=0x0c0920c2u; return 0; }
r[0]=read(ram,0x0c092174u,4);
goto P_0c0920c4;
P_0c0920c4: /* original 2789, guest PC 0x0c0920c4 */
if(!s->budget--) { s->failed_pc=0x0c0920c4u; return 0; }
r[7]&=r[8];
goto P_0c0920c6;
P_0c0920c6: /* original 924b, guest PC 0x0c0920c6 */
if(!s->budget--) { s->failed_pc=0x0c0920c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092160u,2);
goto P_0c0920c8;
P_0c0920c8: /* original 077c, guest PC 0x0c0920c8 */
if(!s->budget--) { s->failed_pc=0x0c0920c8u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0920ca;
P_0c0920ca: /* original 9a4a, guest PC 0x0c0920ca */
if(!s->budget--) { s->failed_pc=0x0c0920cau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092162u,2);
goto P_0c0920cc;
P_0c0920cc: /* original 4728, guest PC 0x0c0920cc */
if(!s->budget--) { s->failed_pc=0x0c0920ccu; return 0; }
r[7]<<=16;
goto P_0c0920ce;
P_0c0920ce: /* original 4718, guest PC 0x0c0920ce */
if(!s->budget--) { s->failed_pc=0x0c0920ceu; return 0; }
r[7]<<=8;
goto P_0c0920d0;
P_0c0920d0: /* original 6473, guest PC 0x0c0920d0 */
if(!s->budget--) { s->failed_pc=0x0c0920d0u; return 0; }
r[4]=r[7];
goto P_0c0920d2;
P_0c0920d2: /* original 2448, guest PC 0x0c0920d2 */
if(!s->budget--) { s->failed_pc=0x0c0920d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0920d4;
P_0c0920d4: /* original 8d06, guest PC 0x0c0920d4 */
if(!s->budget--) { s->failed_pc=0x0c0920d4u; return 0; }
cond=r[17]&1u;
r[7]|=r[2];
if(cond) { goto P_0c0920e4; }
goto P_0c0920d8;
P_0c0920d6: /* original 272b, guest PC 0x0c0920d6 */
if(!s->budget--) { s->failed_pc=0x0c0920d6u; return 0; }
r[7]|=r[2];
goto P_0c0920d8;
P_0c0920d8: /* original 65a3, guest PC 0x0c0920d8 */
if(!s->budget--) { s->failed_pc=0x0c0920d8u; return 0; }
r[5]=r[10];
goto P_0c0920da;
P_0c0920da: /* original 66e3, guest PC 0x0c0920da */
if(!s->budget--) { s->failed_pc=0x0c0920dau; return 0; }
r[6]=r[14];
goto P_0c0920dc;
P_0c0920dc: /* original 2fd6, guest PC 0x0c0920dc */
if(!s->budget--) { s->failed_pc=0x0c0920dcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0920de;
P_0c0920de: /* original 4c0b, guest PC 0x0c0920de */
if(!s->budget--) { s->failed_pc=0x0c0920deu; return 0; }
target=r[12];
r[16]=0x0c0920e2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0920e2u) { target=s->pc; goto dispatch; }
goto P_0c0920e2;
P_0c0920e0: /* original 64b3, guest PC 0x0c0920e0 */
if(!s->budget--) { s->failed_pc=0x0c0920e0u; return 0; }
r[4]=r[11];
goto P_0c0920e2;
P_0c0920e2: /* original 7f04, guest PC 0x0c0920e2 */
if(!s->budget--) { s->failed_pc=0x0c0920e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0920e4;
P_0c0920e4: /* original 60f2, guest PC 0x0c0920e4 */
if(!s->budget--) { s->failed_pc=0x0c0920e4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0920e6;
P_0c0920e6: /* original e478, guest PC 0x0c0920e6 */
if(!s->budget--) { s->failed_pc=0x0c0920e6u; return 0; }
r[4]=0x00000078u;
goto P_0c0920e8;
P_0c0920e8: /* original d323, guest PC 0x0c0920e8 */
if(!s->budget--) { s->failed_pc=0x0c0920e8u; return 0; }
r[3]=read(ram,0x0c092178u,4);
goto P_0c0920ea;
P_0c0920ea: /* original e204, guest PC 0x0c0920ea */
if(!s->budget--) { s->failed_pc=0x0c0920eau; return 0; }
r[2]=0x00000004u;
goto P_0c0920ec;
P_0c0920ec: /* original 4008, guest PC 0x0c0920ec */
if(!s->budget--) { s->failed_pc=0x0c0920ecu; return 0; }
r[0]<<=2;
goto P_0c0920ee;
P_0c0920ee: /* original 4000, guest PC 0x0c0920ee */
if(!s->budget--) { s->failed_pc=0x0c0920eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0920f0;
P_0c0920f0: /* original 2409, guest PC 0x0c0920f0 */
if(!s->budget--) { s->failed_pc=0x0c0920f0u; return 0; }
r[4]&=r[0];
goto P_0c0920f2;
P_0c0920f2: /* original 4421, guest PC 0x0c0920f2 */
if(!s->budget--) { s->failed_pc=0x0c0920f2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0920f4;
P_0c0920f4: /* original 4400, guest PC 0x0c0920f4 */
if(!s->budget--) { s->failed_pc=0x0c0920f4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0920f6;
P_0c0920f6: /* original 343c, guest PC 0x0c0920f6 */
if(!s->budget--) { s->failed_pc=0x0c0920f6u; return 0; }
r[4]+=r[3];
goto P_0c0920f8;
P_0c0920f8: /* original 1f41, guest PC 0x0c0920f8 */
if(!s->budget--) { s->failed_pc=0x0c0920f8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0920fa;
P_0c0920fa: /* original a015, guest PC 0x0c0920fa */
if(!s->budget--) { s->failed_pc=0x0c0920fau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c092128;
P_0c0920fc: /* original 2f22, guest PC 0x0c0920fc */
if(!s->budget--) { s->failed_pc=0x0c0920fcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0920fe;
P_0c0920fe: /* original 57f1, guest PC 0x0c0920fe */
if(!s->budget--) { s->failed_pc=0x0c0920feu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c092100;
P_0c092100: /* original 6b43, guest PC 0x0c092100 */
if(!s->budget--) { s->failed_pc=0x0c092100u; return 0; }
r[11]=r[4];
goto P_0c092102;
P_0c092102: /* original 7702, guest PC 0x0c092102 */
if(!s->budget--) { s->failed_pc=0x0c092102u; return 0; }
r[7]+=0x00000002u;
goto P_0c092104;
P_0c092104: /* original 1f71, guest PC 0x0c092104 */
if(!s->budget--) { s->failed_pc=0x0c092104u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c092106;
P_0c092106: /* original 77fe, guest PC 0x0c092106 */
if(!s->budget--) { s->failed_pc=0x0c092106u; return 0; }
r[7]+=0xfffffffeu;
goto P_0c092108;
P_0c092108: /* original 6771, guest PC 0x0c092108 */
if(!s->budget--) { s->failed_pc=0x0c092108u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c09210a;
P_0c09210a: /* original 9329, guest PC 0x0c09210a */
if(!s->budget--) { s->failed_pc=0x0c09210au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092160u,2);
goto P_0c09210c;
P_0c09210c: /* original 4728, guest PC 0x0c09210c */
if(!s->budget--) { s->failed_pc=0x0c09210cu; return 0; }
r[7]<<=16;
goto P_0c09210e;
P_0c09210e: /* original 6473, guest PC 0x0c09210e */
if(!s->budget--) { s->failed_pc=0x0c09210eu; return 0; }
r[4]=r[7];
goto P_0c092110;
P_0c092110: /* original 2448, guest PC 0x0c092110 */
if(!s->budget--) { s->failed_pc=0x0c092110u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c092112;
P_0c092112: /* original 8d06, guest PC 0x0c092112 */
if(!s->budget--) { s->failed_pc=0x0c092112u; return 0; }
cond=r[17]&1u;
r[7]|=r[3];
if(cond) { goto P_0c092122; }
goto P_0c092116;
P_0c092114: /* original 273b, guest PC 0x0c092114 */
if(!s->budget--) { s->failed_pc=0x0c092114u; return 0; }
r[7]|=r[3];
goto P_0c092116;
P_0c092116: /* original 65a3, guest PC 0x0c092116 */
if(!s->budget--) { s->failed_pc=0x0c092116u; return 0; }
r[5]=r[10];
goto P_0c092118;
P_0c092118: /* original 66e3, guest PC 0x0c092118 */
if(!s->budget--) { s->failed_pc=0x0c092118u; return 0; }
r[6]=r[14];
goto P_0c09211a;
P_0c09211a: /* original 2fd6, guest PC 0x0c09211a */
if(!s->budget--) { s->failed_pc=0x0c09211au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09211c;
P_0c09211c: /* original 4c0b, guest PC 0x0c09211c */
if(!s->budget--) { s->failed_pc=0x0c09211cu; return 0; }
target=r[12];
r[16]=0x0c092120u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092120u) { target=s->pc; goto dispatch; }
goto P_0c092120;
P_0c09211e: /* original 64b3, guest PC 0x0c09211e */
if(!s->budget--) { s->failed_pc=0x0c09211eu; return 0; }
r[4]=r[11];
goto P_0c092120;
P_0c092120: /* original 7f04, guest PC 0x0c092120 */
if(!s->budget--) { s->failed_pc=0x0c092120u; return 0; }
r[15]+=0x00000004u;
goto P_0c092122;
P_0c092122: /* original 63f2, guest PC 0x0c092122 */
if(!s->budget--) { s->failed_pc=0x0c092122u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092124;
P_0c092124: /* original 73ff, guest PC 0x0c092124 */
if(!s->budget--) { s->failed_pc=0x0c092124u; return 0; }
r[3]+=0xffffffffu;
goto P_0c092126;
P_0c092126: /* original 2f32, guest PC 0x0c092126 */
if(!s->budget--) { s->failed_pc=0x0c092126u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c092128;
P_0c092128: /* original 63f2, guest PC 0x0c092128 */
if(!s->budget--) { s->failed_pc=0x0c092128u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09212a;
P_0c09212a: /* original 64b3, guest PC 0x0c09212a */
if(!s->budget--) { s->failed_pc=0x0c09212au; return 0; }
r[4]=r[11];
goto P_0c09212c;
P_0c09212c: /* original 4315, guest PC 0x0c09212c */
if(!s->budget--) { s->failed_pc=0x0c09212cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09212e;
P_0c09212e: /* original 8de6, guest PC 0x0c09212e */
if(!s->budget--) { s->failed_pc=0x0c09212eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c0920fe; }
goto P_0c092132;
P_0c092130: /* original 7404, guest PC 0x0c092130 */
if(!s->budget--) { s->failed_pc=0x0c092130u; return 0; }
r[4]+=0x00000004u;
goto P_0c092132;
P_0c092132: /* original 1fd1, guest PC 0x0c092132 */
if(!s->budget--) { s->failed_pc=0x0c092132u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c092134;
P_0c092134: /* original 66e3, guest PC 0x0c092134 */
if(!s->budget--) { s->failed_pc=0x0c092134u; return 0; }
r[6]=r[14];
goto P_0c092136;
P_0c092136: /* original d711, guest PC 0x0c092136 */
if(!s->budget--) { s->failed_pc=0x0c092136u; return 0; }
r[7]=read(ram,0x0c09217cu,4);
goto P_0c092138;
P_0c092138: /* original e500, guest PC 0x0c092138 */
if(!s->budget--) { s->failed_pc=0x0c092138u; return 0; }
r[5]=0x00000000u;
goto P_0c09213a;
P_0c09213a: /* original 6a43, guest PC 0x0c09213a */
if(!s->budget--) { s->failed_pc=0x0c09213au; return 0; }
r[10]=r[4];
goto P_0c09213c;
P_0c09213c: /* original 2fd6, guest PC 0x0c09213c */
if(!s->budget--) { s->failed_pc=0x0c09213cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09213e;
P_0c09213e: /* original 4c0b, guest PC 0x0c09213e */
if(!s->budget--) { s->failed_pc=0x0c09213eu; return 0; }
target=r[12];
r[16]=0x0c092142u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092142u) { target=s->pc; goto dispatch; }
goto P_0c092142;
P_0c092140: /* original 64a3, guest PC 0x0c092140 */
if(!s->budget--) { s->failed_pc=0x0c092140u; return 0; }
r[4]=r[10];
goto P_0c092142;
P_0c092142: /* original 85f6, guest PC 0x0c092142 */
if(!s->budget--) { s->failed_pc=0x0c092142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c092144;
P_0c092144: /* original 7a02, guest PC 0x0c092144 */
if(!s->budget--) { s->failed_pc=0x0c092144u; return 0; }
r[10]+=0x00000002u;
goto P_0c092146;
P_0c092146: /* original e605, guest PC 0x0c092146 */
if(!s->budget--) { s->failed_pc=0x0c092146u; return 0; }
r[6]=0x00000005u;
goto P_0c092148;
P_0c092148: /* original 65a3, guest PC 0x0c092148 */
if(!s->budget--) { s->failed_pc=0x0c092148u; return 0; }
r[5]=r[10];
goto P_0c09214a;
P_0c09214a: /* original 81f2, guest PC 0x0c09214a */
if(!s->budget--) { s->failed_pc=0x0c09214au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09214c;
P_0c09214c: /* original e702, guest PC 0x0c09214c */
if(!s->budget--) { s->failed_pc=0x0c09214cu; return 0; }
r[7]=0x00000002u;
goto P_0c09214e;
P_0c09214e: /* original 9b09, guest PC 0x0c09214e */
if(!s->budget--) { s->failed_pc=0x0c09214eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092164u,2);
goto P_0c092150;
P_0c092150: /* original 2fd6, guest PC 0x0c092150 */
if(!s->budget--) { s->failed_pc=0x0c092150u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092152;
P_0c092152: /* original 490b, guest PC 0x0c092152 */
if(!s->budget--) { s->failed_pc=0x0c092152u; return 0; }
target=r[9];
r[16]=0x0c092156u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092156u) { target=s->pc; goto dispatch; }
goto P_0c092156;
P_0c092154: /* original 64e3, guest PC 0x0c092154 */
if(!s->budget--) { s->failed_pc=0x0c092154u; return 0; }
r[4]=r[14];
goto P_0c092156;
P_0c092156: /* original 7f08, guest PC 0x0c092156 */
if(!s->budget--) { s->failed_pc=0x0c092156u; return 0; }
r[15]+=0x00000008u;
goto P_0c092158;
P_0c092158: /* original a043, guest PC 0x0c092158 */
if(!s->budget--) { s->failed_pc=0x0c092158u; return 0; }
r[3]=0x00000005u;
goto P_0c0921e2;
P_0c09215a: /* original e305, guest PC 0x0c09215a */
if(!s->budget--) { s->failed_pc=0x0c09215au; return 0; }
r[3]=0x00000005u;
return vf3_matrix_family(0x0c09215cu,s,ram);
P_0c092180: /* original 61f1, guest PC 0x0c092180 */
if(!s->budget--) { s->failed_pc=0x0c092180u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[1]=tmp;
goto P_0c092182;
P_0c092182: /* original d320, guest PC 0x0c092182 */
if(!s->budget--) { s->failed_pc=0x0c092182u; return 0; }
r[3]=read(ram,0x0c092204u,4);
goto P_0c092184;
P_0c092184: /* original 611d, guest PC 0x0c092184 */
if(!s->budget--) { s->failed_pc=0x0c092184u; return 0; }
r[1]=r[1]&65535u;
goto P_0c092186;
P_0c092186: /* original 430b, guest PC 0x0c092186 */
if(!s->budget--) { s->failed_pc=0x0c092186u; return 0; }
target=r[3];
r[16]=0x0c09218au;
r[0]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09218au) { target=s->pc; goto dispatch; }
goto P_0c09218a;
P_0c092188: /* original 60b3, guest PC 0x0c092188 */
if(!s->budget--) { s->failed_pc=0x0c092188u; return 0; }
r[0]=r[11];
goto P_0c09218a;
P_0c09218a: /* original 6403, guest PC 0x0c09218a */
if(!s->budget--) { s->failed_pc=0x0c09218au; return 0; }
r[4]=r[0];
goto P_0c09218c;
P_0c09218c: /* original 63f1, guest PC 0x0c09218c */
if(!s->budget--) { s->failed_pc=0x0c09218cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c09218e;
P_0c09218e: /* original 24be, guest PC 0x0c09218e */
if(!s->budget--) { s->failed_pc=0x0c09218eu; return 0; }
r[19]=(r[4]&65535u)*(r[11]&65535u);
goto P_0c092190;
P_0c092190: /* original 61b3, guest PC 0x0c092190 */
if(!s->budget--) { s->failed_pc=0x0c092190u; return 0; }
r[1]=r[11];
goto P_0c092192;
P_0c092192: /* original e50a, guest PC 0x0c092192 */
if(!s->budget--) { s->failed_pc=0x0c092192u; return 0; }
r[5]=0x0000000au;
goto P_0c092194;
P_0c092194: /* original 021a, guest PC 0x0c092194 */
if(!s->budget--) { s->failed_pc=0x0c092194u; return 0; }
r[2]=r[19];
goto P_0c092196;
P_0c092196: /* original 3328, guest PC 0x0c092196 */
if(!s->budget--) { s->failed_pc=0x0c092196u; return 0; }
r[3]-=r[2];
goto P_0c092198;
P_0c092198: /* original 2f31, guest PC 0x0c092198 */
if(!s->budget--) { s->failed_pc=0x0c092198u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c09219a;
P_0c09219a: /* original d21a, guest PC 0x0c09219a */
if(!s->budget--) { s->failed_pc=0x0c09219au; return 0; }
r[2]=read(ram,0x0c092204u,4);
goto P_0c09219c;
P_0c09219c: /* original 420b, guest PC 0x0c09219c */
if(!s->budget--) { s->failed_pc=0x0c09219cu; return 0; }
target=r[2];
r[16]=0x0c0921a0u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0921a0u) { target=s->pc; goto dispatch; }
goto P_0c0921a0;
P_0c09219e: /* original 6053, guest PC 0x0c09219e */
if(!s->budget--) { s->failed_pc=0x0c09219eu; return 0; }
r[0]=r[5];
goto P_0c0921a0;
P_0c0921a0: /* original 2448, guest PC 0x0c0921a0 */
if(!s->budget--) { s->failed_pc=0x0c0921a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0921a2;
P_0c0921a2: /* original 8f03, guest PC 0x0c0921a2 */
if(!s->budget--) { s->failed_pc=0x0c0921a2u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c0921ac; }
goto P_0c0921a6;
P_0c0921a4: /* original 6b03, guest PC 0x0c0921a4 */
if(!s->budget--) { s->failed_pc=0x0c0921a4u; return 0; }
r[11]=r[0];
goto P_0c0921a6;
P_0c0921a6: /* original 52f1, guest PC 0x0c0921a6 */
if(!s->budget--) { s->failed_pc=0x0c0921a6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0921a8;
P_0c0921a8: /* original 2228, guest PC 0x0c0921a8 */
if(!s->budget--) { s->failed_pc=0x0c0921a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0921aa;
P_0c0921aa: /* original 8917, guest PC 0x0c0921aa */
if(!s->budget--) { s->failed_pc=0x0c0921aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0921dc; }
goto P_0c0921ac;
P_0c0921ac: /* original e501, guest PC 0x0c0921ac */
if(!s->budget--) { s->failed_pc=0x0c0921acu; return 0; }
r[5]=0x00000001u;
goto P_0c0921ae;
P_0c0921ae: /* original 1f51, guest PC 0x0c0921ae */
if(!s->budget--) { s->failed_pc=0x0c0921aeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0921b0;
P_0c0921b0: /* original 7430, guest PC 0x0c0921b0 */
if(!s->budget--) { s->failed_pc=0x0c0921b0u; return 0; }
r[4]+=0x00000030u;
goto P_0c0921b2;
P_0c0921b2: /* original 9525, guest PC 0x0c0921b2 */
if(!s->budget--) { s->failed_pc=0x0c0921b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092200u,2);
goto P_0c0921b4;
P_0c0921b4: /* original 6643, guest PC 0x0c0921b4 */
if(!s->budget--) { s->failed_pc=0x0c0921b4u; return 0; }
r[6]=r[4];
goto P_0c0921b6;
P_0c0921b6: /* original 2689, guest PC 0x0c0921b6 */
if(!s->budget--) { s->failed_pc=0x0c0921b6u; return 0; }
r[6]&=r[8];
goto P_0c0921b8;
P_0c0921b8: /* original 2459, guest PC 0x0c0921b8 */
if(!s->budget--) { s->failed_pc=0x0c0921b8u; return 0; }
r[4]&=r[5];
goto P_0c0921ba;
P_0c0921ba: /* original 6543, guest PC 0x0c0921ba */
if(!s->budget--) { s->failed_pc=0x0c0921bau; return 0; }
r[5]=r[4];
goto P_0c0921bc;
P_0c0921bc: /* original 4521, guest PC 0x0c0921bc */
if(!s->budget--) { s->failed_pc=0x0c0921bcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921be;
P_0c0921be: /* original 4628, guest PC 0x0c0921be */
if(!s->budget--) { s->failed_pc=0x0c0921beu; return 0; }
r[6]<<=16;
goto P_0c0921c0;
P_0c0921c0: /* original 941f, guest PC 0x0c0921c0 */
if(!s->budget--) { s->failed_pc=0x0c0921c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092202u,2);
goto P_0c0921c2;
P_0c0921c2: /* original 4521, guest PC 0x0c0921c2 */
if(!s->budget--) { s->failed_pc=0x0c0921c2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921c4;
P_0c0921c4: /* original 2fd6, guest PC 0x0c0921c4 */
if(!s->budget--) { s->failed_pc=0x0c0921c4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0921c6;
P_0c0921c6: /* original 4618, guest PC 0x0c0921c6 */
if(!s->budget--) { s->failed_pc=0x0c0921c6u; return 0; }
r[6]<<=8;
goto P_0c0921c8;
P_0c0921c8: /* original 4521, guest PC 0x0c0921c8 */
if(!s->budget--) { s->failed_pc=0x0c0921c8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0921ca;
P_0c0921ca: /* original 6763, guest PC 0x0c0921ca */
if(!s->budget--) { s->failed_pc=0x0c0921cau; return 0; }
r[7]=r[6];
goto P_0c0921cc;
P_0c0921cc: /* original 4528, guest PC 0x0c0921cc */
if(!s->budget--) { s->failed_pc=0x0c0921ccu; return 0; }
r[5]<<=16;
goto P_0c0921ce;
P_0c0921ce: /* original 66e3, guest PC 0x0c0921ce */
if(!s->budget--) { s->failed_pc=0x0c0921ceu; return 0; }
r[6]=r[14];
goto P_0c0921d0;
P_0c0921d0: /* original 275b, guest PC 0x0c0921d0 */
if(!s->budget--) { s->failed_pc=0x0c0921d0u; return 0; }
r[7]|=r[5];
goto P_0c0921d2;
P_0c0921d2: /* original e500, guest PC 0x0c0921d2 */
if(!s->budget--) { s->failed_pc=0x0c0921d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0921d4;
P_0c0921d4: /* original 274b, guest PC 0x0c0921d4 */
if(!s->budget--) { s->failed_pc=0x0c0921d4u; return 0; }
r[7]|=r[4];
goto P_0c0921d6;
P_0c0921d6: /* original 4c0b, guest PC 0x0c0921d6 */
if(!s->budget--) { s->failed_pc=0x0c0921d6u; return 0; }
target=r[12];
r[16]=0x0c0921dau;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0921dau) { target=s->pc; goto dispatch; }
goto P_0c0921da;
P_0c0921d8: /* original 64a3, guest PC 0x0c0921d8 */
if(!s->budget--) { s->failed_pc=0x0c0921d8u; return 0; }
r[4]=r[10];
goto P_0c0921da;
P_0c0921da: /* original 7f04, guest PC 0x0c0921da */
if(!s->budget--) { s->failed_pc=0x0c0921dau; return 0; }
r[15]+=0x00000004u;
goto P_0c0921dc;
P_0c0921dc: /* original 53f2, guest PC 0x0c0921dc */
if(!s->budget--) { s->failed_pc=0x0c0921dcu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0921de;
P_0c0921de: /* original 7a02, guest PC 0x0c0921de */
if(!s->budget--) { s->failed_pc=0x0c0921deu; return 0; }
r[10]+=0x00000002u;
goto P_0c0921e0;
P_0c0921e0: /* original 73ff, guest PC 0x0c0921e0 */
if(!s->budget--) { s->failed_pc=0x0c0921e0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0921e2;
P_0c0921e2: /* original 6233, guest PC 0x0c0921e2 */
if(!s->budget--) { s->failed_pc=0x0c0921e2u; return 0; }
r[2]=r[3];
goto P_0c0921e4;
P_0c0921e4: /* original 4215, guest PC 0x0c0921e4 */
if(!s->budget--) { s->failed_pc=0x0c0921e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0921e6;
P_0c0921e6: /* original 1f32, guest PC 0x0c0921e6 */
if(!s->budget--) { s->failed_pc=0x0c0921e6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0921e8;
P_0c0921e8: /* original 89ca, guest PC 0x0c0921e8 */
if(!s->budget--) { s->failed_pc=0x0c0921e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092180; }
goto P_0c0921ea;
P_0c0921ea: /* original 7f0c, guest PC 0x0c0921ea */
if(!s->budget--) { s->failed_pc=0x0c0921eau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0921ec;
P_0c0921ec: /* original 4f16, guest PC 0x0c0921ec */
if(!s->budget--) { s->failed_pc=0x0c0921ecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0921ee;
P_0c0921ee: /* original 4f26, guest PC 0x0c0921ee */
if(!s->budget--) { s->failed_pc=0x0c0921eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0921f0;
P_0c0921f0: /* original 68f6, guest PC 0x0c0921f0 */
if(!s->budget--) { s->failed_pc=0x0c0921f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0921f2;
P_0c0921f2: /* original 69f6, guest PC 0x0c0921f2 */
if(!s->budget--) { s->failed_pc=0x0c0921f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0921f4;
P_0c0921f4: /* original 6af6, guest PC 0x0c0921f4 */
if(!s->budget--) { s->failed_pc=0x0c0921f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0921f6;
P_0c0921f6: /* original 6bf6, guest PC 0x0c0921f6 */
if(!s->budget--) { s->failed_pc=0x0c0921f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0921f8;
P_0c0921f8: /* original 6cf6, guest PC 0x0c0921f8 */
if(!s->budget--) { s->failed_pc=0x0c0921f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0921fa;
P_0c0921fa: /* original 6df6, guest PC 0x0c0921fa */
if(!s->budget--) { s->failed_pc=0x0c0921fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0921fc;
P_0c0921fc: /* original 000b, guest PC 0x0c0921fc */
if(!s->budget--) { s->failed_pc=0x0c0921fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0921fe: /* original 6ef6, guest PC 0x0c0921fe */
if(!s->budget--) { s->failed_pc=0x0c0921feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092200u,s,ram);
P_0c09460a: /* original 4f22, guest PC 0x0c09460a */
if(!s->budget--) { s->failed_pc=0x0c09460au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09460c;
P_0c09460c: /* original d31b, guest PC 0x0c09460c */
if(!s->budget--) { s->failed_pc=0x0c09460cu; return 0; }
r[3]=read(ram,0x0c09467cu,4);
goto P_0c09460e;
P_0c09460e: /* original 6212, guest PC 0x0c09460e */
if(!s->budget--) { s->failed_pc=0x0c09460eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c094610;
P_0c094610: /* original 7fd8, guest PC 0x0c094610 */
if(!s->budget--) { s->failed_pc=0x0c094610u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094612;
P_0c094612: /* original 2238, guest PC 0x0c094612 */
if(!s->budget--) { s->failed_pc=0x0c094612u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c094614;
P_0c094614: /* original 8901, guest PC 0x0c094614 */
if(!s->budget--) { s->failed_pc=0x0c094614u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09461a; }
goto P_0c094616;
P_0c094616: /* original a114, guest PC 0x0c094616 */
if(!s->budget--) { s->failed_pc=0x0c094616u; return 0; }
goto P_0c094842;
P_0c094618: /* original 0009, guest PC 0x0c094618 */
if(!s->budget--) { s->failed_pc=0x0c094618u; return 0; }
goto P_0c09461a;
P_0c09461a: /* original d61a, guest PC 0x0c09461a */
if(!s->budget--) { s->failed_pc=0x0c09461au; return 0; }
r[6]=read(ram,0x0c094684u,4);
goto P_0c09461c;
P_0c09461c: /* original e061, guest PC 0x0c09461c */
if(!s->budget--) { s->failed_pc=0x0c09461cu; return 0; }
r[0]=0x00000061u;
goto P_0c09461e;
P_0c09461e: /* original 5564, guest PC 0x0c09461e */
if(!s->budget--) { s->failed_pc=0x0c09461eu; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c094620;
P_0c094620: /* original 005c, guest PC 0x0c094620 */
if(!s->budget--) { s->failed_pc=0x0c094620u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c094622;
P_0c094622: /* original 600c, guest PC 0x0c094622 */
if(!s->budget--) { s->failed_pc=0x0c094622u; return 0; }
r[0]=r[0]&255u;
goto P_0c094624;
P_0c094624: /* original 880b, guest PC 0x0c094624 */
if(!s->budget--) { s->failed_pc=0x0c094624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c094626;
P_0c094626: /* original 8f07, guest PC 0x0c094626 */
if(!s->budget--) { s->failed_pc=0x0c094626u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[6]+20,4);
if(!cond) { goto P_0c094638; }
goto P_0c09462a;
P_0c094628: /* original 5665, guest PC 0x0c094628 */
if(!s->budget--) { s->failed_pc=0x0c094628u; return 0; }
r[6]=read(ram,r[6]+20,4);
goto P_0c09462a;
P_0c09462a: /* original e061, guest PC 0x0c09462a */
if(!s->budget--) { s->failed_pc=0x0c09462au; return 0; }
r[0]=0x00000061u;
goto P_0c09462c;
P_0c09462c: /* original 006c, guest PC 0x0c09462c */
if(!s->budget--) { s->failed_pc=0x0c09462cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c09462e;
P_0c09462e: /* original 600c, guest PC 0x0c09462e */
if(!s->budget--) { s->failed_pc=0x0c09462eu; return 0; }
r[0]=r[0]&255u;
goto P_0c094630;
P_0c094630: /* original 8806, guest PC 0x0c094630 */
if(!s->budget--) { s->failed_pc=0x0c094630u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c094632;
P_0c094632: /* original 8b01, guest PC 0x0c094632 */
if(!s->budget--) { s->failed_pc=0x0c094632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094638; }
goto P_0c094634;
P_0c094634: /* original a105, guest PC 0x0c094634 */
if(!s->budget--) { s->failed_pc=0x0c094634u; return 0; }
goto P_0c094842;
P_0c094636: /* original 0009, guest PC 0x0c094636 */
if(!s->budget--) { s->failed_pc=0x0c094636u; return 0; }
goto P_0c094638;
P_0c094638: /* original 9011, guest PC 0x0c094638 */
if(!s->budget--) { s->failed_pc=0x0c094638u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09465eu,2);
goto P_0c09463a;
P_0c09463a: /* original 6e43, guest PC 0x0c09463a */
if(!s->budget--) { s->failed_pc=0x0c09463au; return 0; }
r[14]=r[4];
goto P_0c09463c;
P_0c09463c: /* original f356, guest PC 0x0c09463c */
if(!s->budget--) { s->failed_pc=0x0c09463cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09463e;
P_0c09463e: /* original e020, guest PC 0x0c09463e */
if(!s->budget--) { s->failed_pc=0x0c09463eu; return 0; }
r[0]=0x00000020u;
goto P_0c094640;
P_0c094640: /* original ff37, guest PC 0x0c094640 */
if(!s->budget--) { s->failed_pc=0x0c094640u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094642;
P_0c094642: /* original 900d, guest PC 0x0c094642 */
if(!s->budget--) { s->failed_pc=0x0c094642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094660u,2);
goto P_0c094644;
P_0c094644: /* original f356, guest PC 0x0c094644 */
if(!s->budget--) { s->failed_pc=0x0c094644u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c094646;
P_0c094646: /* original e018, guest PC 0x0c094646 */
if(!s->budget--) { s->failed_pc=0x0c094646u; return 0; }
r[0]=0x00000018u;
goto P_0c094648;
P_0c094648: /* original ff37, guest PC 0x0c094648 */
if(!s->budget--) { s->failed_pc=0x0c094648u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09464a;
P_0c09464a: /* original 9008, guest PC 0x0c09464a */
if(!s->budget--) { s->failed_pc=0x0c09464au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09465eu,2);
goto P_0c09464c;
P_0c09464c: /* original f366, guest PC 0x0c09464c */
if(!s->budget--) { s->failed_pc=0x0c09464cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c09464e;
P_0c09464e: /* original e01c, guest PC 0x0c09464e */
if(!s->budget--) { s->failed_pc=0x0c09464eu; return 0; }
r[0]=0x0000001cu;
goto P_0c094650;
P_0c094650: /* original ff37, guest PC 0x0c094650 */
if(!s->budget--) { s->failed_pc=0x0c094650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094652;
P_0c094652: /* original 9005, guest PC 0x0c094652 */
if(!s->budget--) { s->failed_pc=0x0c094652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094660u,2);
goto P_0c094654;
P_0c094654: /* original f366, guest PC 0x0c094654 */
if(!s->budget--) { s->failed_pc=0x0c094654u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c094656;
P_0c094656: /* original e024, guest PC 0x0c094656 */
if(!s->budget--) { s->failed_pc=0x0c094656u; return 0; }
r[0]=0x00000024u;
goto P_0c094658;
P_0c094658: /* original ff37, guest PC 0x0c094658 */
if(!s->budget--) { s->failed_pc=0x0c094658u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09465a;
P_0c09465a: /* original a0ec, guest PC 0x0c09465a */
if(!s->budget--) { s->failed_pc=0x0c09465au; return 0; }
r[3]=0x00000000u;
goto P_0c094836;
P_0c09465c: /* original e300, guest PC 0x0c09465c */
if(!s->budget--) { s->failed_pc=0x0c09465cu; return 0; }
r[3]=0x00000000u;
return vf3_matrix_family(0x0c09465eu,s,ram);
P_0c094688: /* original e004, guest PC 0x0c094688 */
if(!s->budget--) { s->failed_pc=0x0c094688u; return 0; }
r[0]=0x00000004u;
goto P_0c09468a;
P_0c09468a: /* original d934, guest PC 0x0c09468a */
if(!s->budget--) { s->failed_pc=0x0c09468au; return 0; }
r[9]=read(ram,0x0c09475cu,4);
goto P_0c09468c;
P_0c09468c: /* original fce6, guest PC 0x0c09468c */
if(!s->budget--) { s->failed_pc=0x0c09468cu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c09468e;
P_0c09468e: /* original e008, guest PC 0x0c09468e */
if(!s->budget--) { s->failed_pc=0x0c09468eu; return 0; }
r[0]=0x00000008u;
goto P_0c094690;
P_0c094690: /* original fee6, guest PC 0x0c094690 */
if(!s->budget--) { s->failed_pc=0x0c094690u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c094692;
P_0c094692: /* original e00c, guest PC 0x0c094692 */
if(!s->budget--) { s->failed_pc=0x0c094692u; return 0; }
r[0]=0x0000000cu;
goto P_0c094694;
P_0c094694: /* original fde6, guest PC 0x0c094694 */
if(!s->budget--) { s->failed_pc=0x0c094694u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c094696;
P_0c094696: /* original e401, guest PC 0x0c094696 */
if(!s->budget--) { s->failed_pc=0x0c094696u; return 0; }
r[4]=0x00000001u;
goto P_0c094698;
P_0c094698: /* original 85e8, guest PC 0x0c094698 */
if(!s->budget--) { s->failed_pc=0x0c094698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c09469a;
P_0c09469a: /* original 6b03, guest PC 0x0c09469a */
if(!s->budget--) { s->failed_pc=0x0c09469au; return 0; }
r[11]=r[0];
goto P_0c09469c;
P_0c09469c: /* original 85e9, guest PC 0x0c09469c */
if(!s->budget--) { s->failed_pc=0x0c09469cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+18,2);
goto P_0c09469e;
P_0c09469e: /* original 6803, guest PC 0x0c09469e */
if(!s->budget--) { s->failed_pc=0x0c09469eu; return 0; }
r[8]=r[0];
goto P_0c0946a0;
P_0c0946a0: /* original 85ea, guest PC 0x0c0946a0 */
if(!s->budget--) { s->failed_pc=0x0c0946a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0946a2;
P_0c0946a2: /* original 6d03, guest PC 0x0c0946a2 */
if(!s->budget--) { s->failed_pc=0x0c0946a2u; return 0; }
r[13]=r[0];
goto P_0c0946a4;
P_0c0946a4: /* original e016, guest PC 0x0c0946a4 */
if(!s->budget--) { s->failed_pc=0x0c0946a4u; return 0; }
r[0]=0x00000016u;
goto P_0c0946a6;
P_0c0946a6: /* original 0aec, guest PC 0x0c0946a6 */
if(!s->budget--) { s->failed_pc=0x0c0946a6u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0946a8;
P_0c0946a8: /* original e017, guest PC 0x0c0946a8 */
if(!s->budget--) { s->failed_pc=0x0c0946a8u; return 0; }
r[0]=0x00000017u;
goto P_0c0946aa;
P_0c0946aa: /* original 0cec, guest PC 0x0c0946aa */
if(!s->budget--) { s->failed_pc=0x0c0946aau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0946ac;
P_0c0946ac: /* original 63ce, guest PC 0x0c0946ac */
if(!s->budget--) { s->failed_pc=0x0c0946acu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c0946ae;
P_0c0946ae: /* original 2348, guest PC 0x0c0946ae */
if(!s->budget--) { s->failed_pc=0x0c0946aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0946b0;
P_0c0946b0: /* original 8d64, guest PC 0x0c0946b0 */
if(!s->budget--) { s->failed_pc=0x0c0946b0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(cond) { goto P_0c09477c; }
goto P_0c0946b4;
P_0c0946b2: /* original ffe8, guest PC 0x0c0946b2 */
if(!s->budget--) { s->failed_pc=0x0c0946b2u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c0946b4;
P_0c0946b4: /* original c72a, guest PC 0x0c0946b4 */
if(!s->budget--) { s->failed_pc=0x0c0946b4u; return 0; }
r[0]=0x0c094760u;
goto P_0c0946b6;
P_0c0946b6: /* original f408, guest PC 0x0c0946b6 */
if(!s->budget--) { s->failed_pc=0x0c0946b6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946b8;
P_0c0946b8: /* original e004, guest PC 0x0c0946b8 */
if(!s->budget--) { s->failed_pc=0x0c0946b8u; return 0; }
r[0]=0x00000004u;
goto P_0c0946ba;
P_0c0946ba: /* original 3b8c, guest PC 0x0c0946ba */
if(!s->budget--) { s->failed_pc=0x0c0946bau; return 0; }
r[11]+=r[8];
goto P_0c0946bc;
P_0c0946bc: /* original 6abf, guest PC 0x0c0946bc */
if(!s->budget--) { s->failed_pc=0x0c0946bcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0946be;
P_0c0946be: /* original ff47, guest PC 0x0c0946be */
if(!s->budget--) { s->failed_pc=0x0c0946beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0946c0;
P_0c0946c0: /* original d328, guest PC 0x0c0946c0 */
if(!s->budget--) { s->failed_pc=0x0c0946c0u; return 0; }
r[3]=read(ram,0x0c094764u,4);
goto P_0c0946c2;
P_0c0946c2: /* original 430b, guest PC 0x0c0946c2 */
if(!s->budget--) { s->failed_pc=0x0c0946c2u; return 0; }
target=r[3];
r[16]=0x0c0946c6u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0946c6u) { target=s->pc; goto dispatch; }
goto P_0c0946c6;
P_0c0946c4: /* original 64a3, guest PC 0x0c0946c4 */
if(!s->budget--) { s->failed_pc=0x0c0946c4u; return 0; }
r[4]=r[10];
goto P_0c0946c6;
P_0c0946c6: /* original e010, guest PC 0x0c0946c6 */
if(!s->budget--) { s->failed_pc=0x0c0946c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0946c8;
P_0c0946c8: /* original ff07, guest PC 0x0c0946c8 */
if(!s->budget--) { s->failed_pc=0x0c0946c8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0946ca;
P_0c0946ca: /* original d327, guest PC 0x0c0946ca */
if(!s->budget--) { s->failed_pc=0x0c0946cau; return 0; }
r[3]=read(ram,0x0c094768u,4);
goto P_0c0946cc;
P_0c0946cc: /* original 430b, guest PC 0x0c0946cc */
if(!s->budget--) { s->failed_pc=0x0c0946ccu; return 0; }
target=r[3];
r[16]=0x0c0946d0u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0946d0u) { target=s->pc; goto dispatch; }
goto P_0c0946d0;
P_0c0946ce: /* original 64a3, guest PC 0x0c0946ce */
if(!s->budget--) { s->failed_pc=0x0c0946ceu; return 0; }
r[4]=r[10];
goto P_0c0946d0;
P_0c0946d0: /* original e004, guest PC 0x0c0946d0 */
if(!s->budget--) { s->failed_pc=0x0c0946d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0946d2;
P_0c0946d2: /* original f40c, guest PC 0x0c0946d2 */
if(!s->budget--) { s->failed_pc=0x0c0946d2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0946d4;
P_0c0946d4: /* original f0f6, guest PC 0x0c0946d4 */
if(!s->budget--) { s->failed_pc=0x0c0946d4u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0946d6;
P_0c0946d6: /* original e010, guest PC 0x0c0946d6 */
if(!s->budget--) { s->failed_pc=0x0c0946d6u; return 0; }
r[0]=0x00000010u;
goto P_0c0946d8;
P_0c0946d8: /* original f3fc, guest PC 0x0c0946d8 */
if(!s->budget--) { s->failed_pc=0x0c0946d8u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0946da;
P_0c0946da: /* original f2f6, guest PC 0x0c0946da */
if(!s->budget--) { s->failed_pc=0x0c0946dau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0946dc;
P_0c0946dc: /* original f34e, guest PC 0x0c0946dc */
if(!s->budget--) { s->failed_pc=0x0c0946dcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0946de;
P_0c0946de: /* original c723, guest PC 0x0c0946de */
if(!s->budget--) { s->failed_pc=0x0c0946deu; return 0; }
r[0]=0x0c09476cu;
goto P_0c0946e0;
P_0c0946e0: /* original f408, guest PC 0x0c0946e0 */
if(!s->budget--) { s->failed_pc=0x0c0946e0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946e2;
P_0c0946e2: /* original c723, guest PC 0x0c0946e2 */
if(!s->budget--) { s->failed_pc=0x0c0946e2u; return 0; }
r[0]=0x0c094770u;
goto P_0c0946e4;
P_0c0946e4: /* original fd41, guest PC 0x0c0946e4 */
if(!s->budget--) { s->failed_pc=0x0c0946e4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'-');
goto P_0c0946e6;
P_0c0946e6: /* original ff3c, guest PC 0x0c0946e6 */
if(!s->budget--) { s->failed_pc=0x0c0946e6u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0946e8;
P_0c0946e8: /* original f408, guest PC 0x0c0946e8 */
if(!s->budget--) { s->failed_pc=0x0c0946e8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0946ea;
P_0c0946ea: /* original f3ec, guest PC 0x0c0946ea */
if(!s->budget--) { s->failed_pc=0x0c0946eau; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0946ec;
P_0c0946ec: /* original f32e, guest PC 0x0c0946ec */
if(!s->budget--) { s->failed_pc=0x0c0946ecu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0946ee;
P_0c0946ee: /* original f4d5, guest PC 0x0c0946ee */
if(!s->budget--) { s->failed_pc=0x0c0946eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[13]))!=0);
goto P_0c0946f0;
P_0c0946f0: /* original 8f01, guest PC 0x0c0946f0 */
if(!s->budget--) { s->failed_pc=0x0c0946f0u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,14,3);
if(!cond) { goto P_0c0946f6; }
goto P_0c0946f4;
P_0c0946f2: /* original fe3c, guest PC 0x0c0946f2 */
if(!s->budget--) { s->failed_pc=0x0c0946f2u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0946f4;
P_0c0946f4: /* original fd4c, guest PC 0x0c0946f4 */
if(!s->budget--) { s->failed_pc=0x0c0946f4u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0946f6;
P_0c0946f6: /* original e020, guest PC 0x0c0946f6 */
if(!s->budget--) { s->failed_pc=0x0c0946f6u; return 0; }
r[0]=0x00000020u;
goto P_0c0946f8;
P_0c0946f8: /* original f2fc, guest PC 0x0c0946f8 */
if(!s->budget--) { s->failed_pc=0x0c0946f8u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0946fa;
P_0c0946fa: /* original f3f6, guest PC 0x0c0946fa */
if(!s->budget--) { s->failed_pc=0x0c0946fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0946fc;
P_0c0946fc: /* original e018, guest PC 0x0c0946fc */
if(!s->budget--) { s->failed_pc=0x0c0946fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0946fe;
P_0c0946fe: /* original f1ec, guest PC 0x0c0946fe */
if(!s->budget--) { s->failed_pc=0x0c0946feu; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c094700;
P_0c094700: /* original f231, guest PC 0x0c094700 */
if(!s->budget--) { s->failed_pc=0x0c094700u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c094702;
P_0c094702: /* original f0fc, guest PC 0x0c094702 */
if(!s->budget--) { s->failed_pc=0x0c094702u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c094704;
P_0c094704: /* original f25d, guest PC 0x0c094704 */
if(!s->budget--) { s->failed_pc=0x0c094704u; return 0; }
fr[2]&=0x7fffffffu;
goto P_0c094706;
P_0c094706: /* original f52c, guest PC 0x0c094706 */
if(!s->budget--) { s->failed_pc=0x0c094706u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c094708;
P_0c094708: /* original f2f6, guest PC 0x0c094708 */
if(!s->budget--) { s->failed_pc=0x0c094708u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09470a;
P_0c09470a: /* original e01c, guest PC 0x0c09470a */
if(!s->budget--) { s->failed_pc=0x0c09470au; return 0; }
r[0]=0x0000001cu;
goto P_0c09470c;
P_0c09470c: /* original f121, guest PC 0x0c09470c */
if(!s->budget--) { s->failed_pc=0x0c09470cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c09470e;
P_0c09470e: /* original f15d, guest PC 0x0c09470e */
if(!s->budget--) { s->failed_pc=0x0c09470eu; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c094710;
P_0c094710: /* original f71c, guest PC 0x0c094710 */
if(!s->budget--) { s->failed_pc=0x0c094710u; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c094712;
P_0c094712: /* original f570, guest PC 0x0c094712 */
if(!s->budget--) { s->failed_pc=0x0c094712u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c094714;
P_0c094714: /* original f1f6, guest PC 0x0c094714 */
if(!s->budget--) { s->failed_pc=0x0c094714u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c094716;
P_0c094716: /* original e024, guest PC 0x0c094716 */
if(!s->budget--) { s->failed_pc=0x0c094716u; return 0; }
r[0]=0x00000024u;
goto P_0c094718;
P_0c094718: /* original f3f6, guest PC 0x0c094718 */
if(!s->budget--) { s->failed_pc=0x0c094718u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09471a;
P_0c09471a: /* original c716, guest PC 0x0c09471a */
if(!s->budget--) { s->failed_pc=0x0c09471au; return 0; }
r[0]=0x0c094774u;
goto P_0c09471c;
P_0c09471c: /* original f011, guest PC 0x0c09471c */
if(!s->budget--) { s->failed_pc=0x0c09471cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c09471e;
P_0c09471e: /* original f05d, guest PC 0x0c09471e */
if(!s->budget--) { s->failed_pc=0x0c09471eu; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c094720;
P_0c094720: /* original f60c, guest PC 0x0c094720 */
if(!s->budget--) { s->failed_pc=0x0c094720u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c094722;
P_0c094722: /* original f0ec, guest PC 0x0c094722 */
if(!s->budget--) { s->failed_pc=0x0c094722u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c094724;
P_0c094724: /* original f031, guest PC 0x0c094724 */
if(!s->budget--) { s->failed_pc=0x0c094724u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c094726;
P_0c094726: /* original f05d, guest PC 0x0c094726 */
if(!s->budget--) { s->failed_pc=0x0c094726u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c094728;
P_0c094728: /* original f40c, guest PC 0x0c094728 */
if(!s->budget--) { s->failed_pc=0x0c094728u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09472a;
P_0c09472a: /* original f640, guest PC 0x0c09472a */
if(!s->budget--) { s->failed_pc=0x0c09472au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c09472c;
P_0c09472c: /* original f408, guest PC 0x0c09472c */
if(!s->budget--) { s->failed_pc=0x0c09472cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09472e;
P_0c09472e: /* original f455, guest PC 0x0c09472e */
if(!s->budget--) { s->failed_pc=0x0c09472eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c094730;
P_0c094730: /* original 8d09, guest PC 0x0c094730 */
if(!s->budget--) { s->failed_pc=0x0c094730u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
if(cond) { goto P_0c094746; }
goto P_0c094734;
P_0c094732: /* original fcd0, guest PC 0x0c094732 */
if(!s->budget--) { s->failed_pc=0x0c094732u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
goto P_0c094734;
P_0c094734: /* original f465, guest PC 0x0c094734 */
if(!s->budget--) { s->failed_pc=0x0c094734u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c094736;
P_0c094736: /* original 8906, guest PC 0x0c094736 */
if(!s->budget--) { s->failed_pc=0x0c094736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094746; }
goto P_0c094738;
P_0c094738: /* original 63df, guest PC 0x0c094738 */
if(!s->budget--) { s->failed_pc=0x0c094738u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c09473a;
P_0c09473a: /* original 2338, guest PC 0x0c09473a */
if(!s->budget--) { s->failed_pc=0x0c09473au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09473c;
P_0c09473c: /* original 8903, guest PC 0x0c09473c */
if(!s->budget--) { s->failed_pc=0x0c09473cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094746; }
goto P_0c09473e;
P_0c09473e: /* original c70e, guest PC 0x0c09473e */
if(!s->budget--) { s->failed_pc=0x0c09473eu; return 0; }
r[0]=0x0c094778u;
goto P_0c094740;
P_0c094740: /* original f208, guest PC 0x0c094740 */
if(!s->budget--) { s->failed_pc=0x0c094740u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c094742;
P_0c094742: /* original f2c5, guest PC 0x0c094742 */
if(!s->budget--) { s->failed_pc=0x0c094742u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[12]))!=0);
goto P_0c094744;
P_0c094744: /* original 8b06, guest PC 0x0c094744 */
if(!s->budget--) { s->failed_pc=0x0c094744u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094754; }
goto P_0c094746;
P_0c094746: /* original e2fe, guest PC 0x0c094746 */
if(!s->budget--) { s->failed_pc=0x0c094746u; return 0; }
r[2]=0xfffffffeu;
goto P_0c094748;
P_0c094748: /* original e302, guest PC 0x0c094748 */
if(!s->budget--) { s->failed_pc=0x0c094748u; return 0; }
r[3]=0x00000002u;
goto P_0c09474a;
P_0c09474a: /* original 2c29, guest PC 0x0c09474a */
if(!s->budget--) { s->failed_pc=0x0c09474au; return 0; }
r[12]&=r[2];
goto P_0c09474c;
P_0c09474c: /* original 490b, guest PC 0x0c09474c */
if(!s->budget--) { s->failed_pc=0x0c09474cu; return 0; }
target=r[9];
r[16]=0x0c094750u;
r[12]|=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094750u) { target=s->pc; goto dispatch; }
goto P_0c094750;
P_0c09474e: /* original 2c3b, guest PC 0x0c09474e */
if(!s->budget--) { s->failed_pc=0x0c09474eu; return 0; }
r[12]|=r[3];
goto P_0c094750;
P_0c094750: /* original 9d03, guest PC 0x0c094750 */
if(!s->budget--) { s->failed_pc=0x0c094750u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09475au,2);
goto P_0c094752;
P_0c094752: /* original 2d09, guest PC 0x0c094752 */
if(!s->budget--) { s->failed_pc=0x0c094752u; return 0; }
r[13]&=r[0];
goto P_0c094754;
P_0c094754: /* original e407, guest PC 0x0c094754 */
if(!s->budget--) { s->failed_pc=0x0c094754u; return 0; }
r[4]=0x00000007u;
goto P_0c094756;
P_0c094756: /* original a048, guest PC 0x0c094756 */
if(!s->budget--) { s->failed_pc=0x0c094756u; return 0; }
r[10]=r[4];
goto P_0c0947ea;
P_0c094758: /* original 6a43, guest PC 0x0c094758 */
if(!s->budget--) { s->failed_pc=0x0c094758u; return 0; }
r[10]=r[4];
return vf3_matrix_family(0x0c09475au,s,ram);
P_0c09477c: /* original c739, guest PC 0x0c09477c */
if(!s->budget--) { s->failed_pc=0x0c09477cu; return 0; }
r[0]=0x0c094864u;
goto P_0c09477e;
P_0c09477e: /* original f308, guest PC 0x0c09477e */
if(!s->budget--) { s->failed_pc=0x0c09477eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c094780;
P_0c094780: /* original e30f, guest PC 0x0c094780 */
if(!s->budget--) { s->failed_pc=0x0c094780u; return 0; }
r[3]=0x0000000fu;
goto P_0c094782;
P_0c094782: /* original 7a01, guest PC 0x0c094782 */
if(!s->budget--) { s->failed_pc=0x0c094782u; return 0; }
r[10]+=0x00000001u;
goto P_0c094784;
P_0c094784: /* original 2a39, guest PC 0x0c094784 */
if(!s->budget--) { s->failed_pc=0x0c094784u; return 0; }
r[10]&=r[3];
goto P_0c094786;
P_0c094786: /* original ff3a, guest PC 0x0c094786 */
if(!s->budget--) { s->failed_pc=0x0c094786u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c094788;
P_0c094788: /* original d237, guest PC 0x0c094788 */
if(!s->budget--) { s->failed_pc=0x0c094788u; return 0; }
r[2]=read(ram,0x0c094868u,4);
goto P_0c09478a;
P_0c09478a: /* original 64bf, guest PC 0x0c09478a */
if(!s->budget--) { s->failed_pc=0x0c09478au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09478c;
P_0c09478c: /* original 420b, guest PC 0x0c09478c */
if(!s->budget--) { s->failed_pc=0x0c09478cu; return 0; }
target=r[2];
r[16]=0x0c094790u;
write(ram,r[15]+12,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094790u) { target=s->pc; goto dispatch; }
goto P_0c094790;
P_0c09478e: /* original 1f43, guest PC 0x0c09478e */
if(!s->budget--) { s->failed_pc=0x0c09478eu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c094790;
P_0c094790: /* original e014, guest PC 0x0c094790 */
if(!s->budget--) { s->failed_pc=0x0c094790u; return 0; }
r[0]=0x00000014u;
goto P_0c094792;
P_0c094792: /* original ff07, guest PC 0x0c094792 */
if(!s->budget--) { s->failed_pc=0x0c094792u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c094794;
P_0c094794: /* original d335, guest PC 0x0c094794 */
if(!s->budget--) { s->failed_pc=0x0c094794u; return 0; }
r[3]=read(ram,0x0c09486cu,4);
goto P_0c094796;
P_0c094796: /* original 430b, guest PC 0x0c094796 */
if(!s->budget--) { s->failed_pc=0x0c094796u; return 0; }
target=r[3];
r[16]=0x0c09479au;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09479au) { target=s->pc; goto dispatch; }
goto P_0c09479a;
P_0c094798: /* original 54f3, guest PC 0x0c094798 */
if(!s->budget--) { s->failed_pc=0x0c094798u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09479a;
P_0c09479a: /* original f40c, guest PC 0x0c09479a */
if(!s->budget--) { s->failed_pc=0x0c09479au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09479c;
P_0c09479c: /* original e014, guest PC 0x0c09479c */
if(!s->budget--) { s->failed_pc=0x0c09479cu; return 0; }
r[0]=0x00000014u;
goto P_0c09479e;
P_0c09479e: /* original f0f8, guest PC 0x0c09479e */
if(!s->budget--) { s->failed_pc=0x0c09479eu; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0947a0;
P_0c0947a0: /* original f3fc, guest PC 0x0c0947a0 */
if(!s->budget--) { s->failed_pc=0x0c0947a0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0947a2;
P_0c0947a2: /* original f34e, guest PC 0x0c0947a2 */
if(!s->budget--) { s->failed_pc=0x0c0947a2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0947a4;
P_0c0947a4: /* original f2f6, guest PC 0x0c0947a4 */
if(!s->budget--) { s->failed_pc=0x0c0947a4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0947a6;
P_0c0947a6: /* original c732, guest PC 0x0c0947a6 */
if(!s->budget--) { s->failed_pc=0x0c0947a6u; return 0; }
r[0]=0x0c094870u;
goto P_0c0947a8;
P_0c0947a8: /* original f408, guest PC 0x0c0947a8 */
if(!s->budget--) { s->failed_pc=0x0c0947a8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0947aa;
P_0c0947aa: /* original c72e, guest PC 0x0c0947aa */
if(!s->budget--) { s->failed_pc=0x0c0947aau; return 0; }
r[0]=0x0c094864u;
goto P_0c0947ac;
P_0c0947ac: /* original ff3c, guest PC 0x0c0947ac */
if(!s->budget--) { s->failed_pc=0x0c0947acu; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0947ae;
P_0c0947ae: /* original fd40, guest PC 0x0c0947ae */
if(!s->budget--) { s->failed_pc=0x0c0947aeu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c0947b0;
P_0c0947b0: /* original f3ec, guest PC 0x0c0947b0 */
if(!s->budget--) { s->failed_pc=0x0c0947b0u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0947b2;
P_0c0947b2: /* original f32e, guest PC 0x0c0947b2 */
if(!s->budget--) { s->failed_pc=0x0c0947b2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0947b4;
P_0c0947b4: /* original fe3c, guest PC 0x0c0947b4 */
if(!s->budget--) { s->failed_pc=0x0c0947b4u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0947b6;
P_0c0947b6: /* original f308, guest PC 0x0c0947b6 */
if(!s->budget--) { s->failed_pc=0x0c0947b6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947b8;
P_0c0947b8: /* original fd35, guest PC 0x0c0947b8 */
if(!s->budget--) { s->failed_pc=0x0c0947b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c0947ba;
P_0c0947ba: /* original 8b01, guest PC 0x0c0947ba */
if(!s->budget--) { s->failed_pc=0x0c0947bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0947c0; }
goto P_0c0947bc;
P_0c0947bc: /* original c729, guest PC 0x0c0947bc */
if(!s->budget--) { s->failed_pc=0x0c0947bcu; return 0; }
r[0]=0x0c094864u;
goto P_0c0947be;
P_0c0947be: /* original fd08, guest PC 0x0c0947be */
if(!s->budget--) { s->failed_pc=0x0c0947beu; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0947c0;
P_0c0947c0: /* original 7dff, guest PC 0x0c0947c0 */
if(!s->budget--) { s->failed_pc=0x0c0947c0u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0947c2;
P_0c0947c2: /* original 63df, guest PC 0x0c0947c2 */
if(!s->budget--) { s->failed_pc=0x0c0947c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0947c4;
P_0c0947c4: /* original 2338, guest PC 0x0c0947c4 */
if(!s->budget--) { s->failed_pc=0x0c0947c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0947c6;
P_0c0947c6: /* original 8d04, guest PC 0x0c0947c6 */
if(!s->budget--) { s->failed_pc=0x0c0947c6u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
if(cond) { goto P_0c0947d2; }
goto P_0c0947ca;
P_0c0947c8: /* original fcd0, guest PC 0x0c0947c8 */
if(!s->budget--) { s->failed_pc=0x0c0947c8u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[13],r[18],'+');
goto P_0c0947ca;
P_0c0947ca: /* original c72a, guest PC 0x0c0947ca */
if(!s->budget--) { s->failed_pc=0x0c0947cau; return 0; }
r[0]=0x0c094874u;
goto P_0c0947cc;
P_0c0947cc: /* original f308, guest PC 0x0c0947cc */
if(!s->budget--) { s->failed_pc=0x0c0947ccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947ce;
P_0c0947ce: /* original fc35, guest PC 0x0c0947ce */
if(!s->budget--) { s->failed_pc=0x0c0947ceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c0947d0;
P_0c0947d0: /* original 8b0b, guest PC 0x0c0947d0 */
if(!s->budget--) { s->failed_pc=0x0c0947d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0947ea; }
goto P_0c0947d2;
P_0c0947d2: /* original 9844, guest PC 0x0c0947d2 */
if(!s->budget--) { s->failed_pc=0x0c0947d2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09485eu,2);
goto P_0c0947d4;
P_0c0947d4: /* original e2fd, guest PC 0x0c0947d4 */
if(!s->budget--) { s->failed_pc=0x0c0947d4u; return 0; }
r[2]=0xfffffffdu;
goto P_0c0947d6;
P_0c0947d6: /* original 9d43, guest PC 0x0c0947d6 */
if(!s->budget--) { s->failed_pc=0x0c0947d6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094860u,2);
goto P_0c0947d8;
P_0c0947d8: /* original 2c29, guest PC 0x0c0947d8 */
if(!s->budget--) { s->failed_pc=0x0c0947d8u; return 0; }
r[12]&=r[2];
goto P_0c0947da;
P_0c0947da: /* original e301, guest PC 0x0c0947da */
if(!s->budget--) { s->failed_pc=0x0c0947dau; return 0; }
r[3]=0x00000001u;
goto P_0c0947dc;
P_0c0947dc: /* original 490b, guest PC 0x0c0947dc */
if(!s->budget--) { s->failed_pc=0x0c0947dcu; return 0; }
target=r[9];
r[16]=0x0c0947e0u;
r[12]|=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0947e0u) { target=s->pc; goto dispatch; }
goto P_0c0947e0;
P_0c0947de: /* original 2c3b, guest PC 0x0c0947de */
if(!s->budget--) { s->failed_pc=0x0c0947deu; return 0; }
r[12]|=r[3];
goto P_0c0947e0;
P_0c0947e0: /* original 20d9, guest PC 0x0c0947e0 */
if(!s->budget--) { s->failed_pc=0x0c0947e0u; return 0; }
r[0]&=r[13];
goto P_0c0947e2;
P_0c0947e2: /* original 490b, guest PC 0x0c0947e2 */
if(!s->budget--) { s->failed_pc=0x0c0947e2u; return 0; }
target=r[9];
r[16]=0x0c0947e6u;
r[8]+=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0947e6u) { target=s->pc; goto dispatch; }
goto P_0c0947e6;
P_0c0947e4: /* original 380c, guest PC 0x0c0947e4 */
if(!s->budget--) { s->failed_pc=0x0c0947e4u; return 0; }
r[8]+=r[0];
goto P_0c0947e6;
P_0c0947e6: /* original 7dff, guest PC 0x0c0947e6 */
if(!s->budget--) { s->failed_pc=0x0c0947e6u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0947e8;
P_0c0947e8: /* original 2d09, guest PC 0x0c0947e8 */
if(!s->budget--) { s->failed_pc=0x0c0947e8u; return 0; }
r[13]&=r[0];
goto P_0c0947ea;
P_0c0947ea: /* original c723, guest PC 0x0c0947ea */
if(!s->budget--) { s->failed_pc=0x0c0947eau; return 0; }
r[0]=0x0c094878u;
goto P_0c0947ec;
P_0c0947ec: /* original f508, guest PC 0x0c0947ec */
if(!s->budget--) { s->failed_pc=0x0c0947ecu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0947ee;
P_0c0947ee: /* original c723, guest PC 0x0c0947ee */
if(!s->budget--) { s->failed_pc=0x0c0947eeu; return 0; }
r[0]=0x0c09487cu;
goto P_0c0947f0;
P_0c0947f0: /* original f5f5, guest PC 0x0c0947f0 */
if(!s->budget--) { s->failed_pc=0x0c0947f0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[15]))!=0);
goto P_0c0947f2;
P_0c0947f2: /* original 8d04, guest PC 0x0c0947f2 */
if(!s->budget--) { s->failed_pc=0x0c0947f2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0947fe; }
goto P_0c0947f6;
P_0c0947f4: /* original f408, guest PC 0x0c0947f4 */
if(!s->budget--) { s->failed_pc=0x0c0947f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0947f6;
P_0c0947f6: /* original c722, guest PC 0x0c0947f6 */
if(!s->budget--) { s->failed_pc=0x0c0947f6u; return 0; }
r[0]=0x0c094880u;
goto P_0c0947f8;
P_0c0947f8: /* original f308, guest PC 0x0c0947f8 */
if(!s->budget--) { s->failed_pc=0x0c0947f8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0947fa;
P_0c0947fa: /* original ff35, guest PC 0x0c0947fa */
if(!s->budget--) { s->failed_pc=0x0c0947fau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0947fc;
P_0c0947fc: /* original 8b00, guest PC 0x0c0947fc */
if(!s->budget--) { s->failed_pc=0x0c0947fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094800; }
goto P_0c0947fe;
P_0c0947fe: /* original ff42, guest PC 0x0c0947fe */
if(!s->budget--) { s->failed_pc=0x0c0947feu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c094800;
P_0c094800: /* original f5e5, guest PC 0x0c094800 */
if(!s->budget--) { s->failed_pc=0x0c094800u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[14]))!=0);
goto P_0c094802;
P_0c094802: /* original 8903, guest PC 0x0c094802 */
if(!s->budget--) { s->failed_pc=0x0c094802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09480c; }
goto P_0c094804;
P_0c094804: /* original c71e, guest PC 0x0c094804 */
if(!s->budget--) { s->failed_pc=0x0c094804u; return 0; }
r[0]=0x0c094880u;
goto P_0c094806;
P_0c094806: /* original f308, guest PC 0x0c094806 */
if(!s->budget--) { s->failed_pc=0x0c094806u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c094808;
P_0c094808: /* original fe35, guest PC 0x0c094808 */
if(!s->budget--) { s->failed_pc=0x0c094808u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c09480a;
P_0c09480a: /* original 8b00, guest PC 0x0c09480a */
if(!s->budget--) { s->failed_pc=0x0c09480au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09480e; }
goto P_0c09480c;
P_0c09480c: /* original fe42, guest PC 0x0c09480c */
if(!s->budget--) { s->failed_pc=0x0c09480cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c09480e;
P_0c09480e: /* original e004, guest PC 0x0c09480e */
if(!s->budget--) { s->failed_pc=0x0c09480eu; return 0; }
r[0]=0x00000004u;
goto P_0c094810;
P_0c094810: /* original fefa, guest PC 0x0c094810 */
if(!s->budget--) { s->failed_pc=0x0c094810u; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c094812;
P_0c094812: /* original fec7, guest PC 0x0c094812 */
if(!s->budget--) { s->failed_pc=0x0c094812u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c094814;
P_0c094814: /* original e008, guest PC 0x0c094814 */
if(!s->budget--) { s->failed_pc=0x0c094814u; return 0; }
r[0]=0x00000008u;
goto P_0c094816;
P_0c094816: /* original fee7, guest PC 0x0c094816 */
if(!s->budget--) { s->failed_pc=0x0c094816u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c094818;
P_0c094818: /* original e00c, guest PC 0x0c094818 */
if(!s->budget--) { s->failed_pc=0x0c094818u; return 0; }
r[0]=0x0000000cu;
goto P_0c09481a;
P_0c09481a: /* original fed7, guest PC 0x0c09481a */
if(!s->budget--) { s->failed_pc=0x0c09481au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c09481c;
P_0c09481c: /* original 60b3, guest PC 0x0c09481c */
if(!s->budget--) { s->failed_pc=0x0c09481cu; return 0; }
r[0]=r[11];
goto P_0c09481e;
P_0c09481e: /* original 81e8, guest PC 0x0c09481e */
if(!s->budget--) { s->failed_pc=0x0c09481eu; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c094820;
P_0c094820: /* original 6083, guest PC 0x0c094820 */
if(!s->budget--) { s->failed_pc=0x0c094820u; return 0; }
r[0]=r[8];
goto P_0c094822;
P_0c094822: /* original 81e9, guest PC 0x0c094822 */
if(!s->budget--) { s->failed_pc=0x0c094822u; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c094824;
P_0c094824: /* original 60d3, guest PC 0x0c094824 */
if(!s->budget--) { s->failed_pc=0x0c094824u; return 0; }
r[0]=r[13];
goto P_0c094826;
P_0c094826: /* original 81ea, guest PC 0x0c094826 */
if(!s->budget--) { s->failed_pc=0x0c094826u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c094828;
P_0c094828: /* original e016, guest PC 0x0c094828 */
if(!s->budget--) { s->failed_pc=0x0c094828u; return 0; }
r[0]=0x00000016u;
goto P_0c09482a;
P_0c09482a: /* original 0ea4, guest PC 0x0c09482a */
if(!s->budget--) { s->failed_pc=0x0c09482au; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c09482c;
P_0c09482c: /* original e017, guest PC 0x0c09482c */
if(!s->budget--) { s->failed_pc=0x0c09482cu; return 0; }
r[0]=0x00000017u;
goto P_0c09482e;
P_0c09482e: /* original 0ec4, guest PC 0x0c09482e */
if(!s->budget--) { s->failed_pc=0x0c09482eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c094830;
P_0c094830: /* original 7e18, guest PC 0x0c094830 */
if(!s->budget--) { s->failed_pc=0x0c094830u; return 0; }
r[14]+=0x00000018u;
goto P_0c094832;
P_0c094832: /* original 53f2, guest PC 0x0c094832 */
if(!s->budget--) { s->failed_pc=0x0c094832u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c094834;
P_0c094834: /* original 7301, guest PC 0x0c094834 */
if(!s->budget--) { s->failed_pc=0x0c094834u; return 0; }
r[3]+=0x00000001u;
goto P_0c094836;
P_0c094836: /* original e432, guest PC 0x0c094836 */
if(!s->budget--) { s->failed_pc=0x0c094836u; return 0; }
r[4]=0x00000032u;
goto P_0c094838;
P_0c094838: /* original 3343, guest PC 0x0c094838 */
if(!s->budget--) { s->failed_pc=0x0c094838u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c09483a;
P_0c09483a: /* original 8d02, guest PC 0x0c09483a */
if(!s->budget--) { s->failed_pc=0x0c09483au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(cond) { goto P_0c094842; }
goto P_0c09483e;
P_0c09483c: /* original 1f32, guest PC 0x0c09483c */
if(!s->budget--) { s->failed_pc=0x0c09483cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c09483e;
P_0c09483e: /* original af23, guest PC 0x0c09483e */
if(!s->budget--) { s->failed_pc=0x0c09483eu; return 0; }
goto P_0c094688;
P_0c094840: /* original 0009, guest PC 0x0c094840 */
if(!s->budget--) { s->failed_pc=0x0c094840u; return 0; }
goto P_0c094842;
P_0c094842: /* original 7f28, guest PC 0x0c094842 */
if(!s->budget--) { s->failed_pc=0x0c094842u; return 0; }
r[15]+=0x00000028u;
goto P_0c094844;
P_0c094844: /* original 4f26, guest PC 0x0c094844 */
if(!s->budget--) { s->failed_pc=0x0c094844u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094846;
P_0c094846: /* original fcf9, guest PC 0x0c094846 */
if(!s->budget--) { s->failed_pc=0x0c094846u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c094848;
P_0c094848: /* original fdf9, guest PC 0x0c094848 */
if(!s->budget--) { s->failed_pc=0x0c094848u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484a;
P_0c09484a: /* original fef9, guest PC 0x0c09484a */
if(!s->budget--) { s->failed_pc=0x0c09484au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484c;
P_0c09484c: /* original fff9, guest PC 0x0c09484c */
if(!s->budget--) { s->failed_pc=0x0c09484cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09484e;
P_0c09484e: /* original 68f6, guest PC 0x0c09484e */
if(!s->budget--) { s->failed_pc=0x0c09484eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c094850;
P_0c094850: /* original 69f6, guest PC 0x0c094850 */
if(!s->budget--) { s->failed_pc=0x0c094850u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c094852;
P_0c094852: /* original 6af6, guest PC 0x0c094852 */
if(!s->budget--) { s->failed_pc=0x0c094852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c094854;
P_0c094854: /* original 6bf6, guest PC 0x0c094854 */
if(!s->budget--) { s->failed_pc=0x0c094854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094856;
P_0c094856: /* original 6cf6, guest PC 0x0c094856 */
if(!s->budget--) { s->failed_pc=0x0c094856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094858;
P_0c094858: /* original 6df6, guest PC 0x0c094858 */
if(!s->budget--) { s->failed_pc=0x0c094858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09485a;
P_0c09485a: /* original 000b, guest PC 0x0c09485a */
if(!s->budget--) { s->failed_pc=0x0c09485au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09485c: /* original 6ef6, guest PC 0x0c09485c */
if(!s->budget--) { s->failed_pc=0x0c09485cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09485eu,s,ram);
P_0c0ae2dc: /* original 5263, guest PC 0x0c0ae2dc */
if(!s->budget--) { s->failed_pc=0x0c0ae2dcu; return 0; }
r[2]=read(ram,r[6]+12,4);
goto P_0c0ae2de;
P_0c0ae2de: /* original 9310, guest PC 0x0c0ae2de */
if(!s->budget--) { s->failed_pc=0x0c0ae2deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae302u,2);
goto P_0c0ae2e0;
P_0c0ae2e0: /* original 223a, guest PC 0x0c0ae2e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2e0u; return 0; }
r[2]^=r[3];
goto P_0c0ae2e2;
P_0c0ae2e2: /* original 1623, guest PC 0x0c0ae2e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2e2u; return 0; }
write(ram,r[6]+12,r[2],4);
goto P_0c0ae2e4;
P_0c0ae2e4: /* original 5162, guest PC 0x0c0ae2e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2e4u; return 0; }
r[1]=read(ram,r[6]+8,4);
goto P_0c0ae2e6;
P_0c0ae2e6: /* original 7103, guest PC 0x0c0ae2e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2e6u; return 0; }
r[1]+=0x00000003u;
goto P_0c0ae2e8;
P_0c0ae2e8: /* original afd8, guest PC 0x0c0ae2e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2e8u; return 0; }
write(ram,r[6]+8,r[1],4);
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae2ea: /* original 1612, guest PC 0x0c0ae2ea */
if(!s->budget--) { s->failed_pc=0x0c0ae2eau; return 0; }
write(ram,r[6]+8,r[1],4);
goto P_0c0ae2ec;
P_0c0ae2ec: /* original d309, guest PC 0x0c0ae2ec */
if(!s->budget--) { s->failed_pc=0x0c0ae2ecu; return 0; }
r[3]=read(ram,0x0c0ae314u,4);
goto P_0c0ae2ee;
P_0c0ae2ee: /* original e700, guest PC 0x0c0ae2ee */
if(!s->budget--) { s->failed_pc=0x0c0ae2eeu; return 0; }
r[7]=0x00000000u;
goto P_0c0ae2f0;
P_0c0ae2f0: /* original e066, guest PC 0x0c0ae2f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2f0u; return 0; }
r[0]=0x00000066u;
goto P_0c0ae2f2;
P_0c0ae2f2: /* original 143d, guest PC 0x0c0ae2f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2f2u; return 0; }
write(ram,r[4]+52,r[3],4);
goto P_0c0ae2f4;
P_0c0ae2f4: /* original 0475, guest PC 0x0c0ae2f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2f4u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ae2f6;
P_0c0ae2f6: /* original 9005, guest PC 0x0c0ae2f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae304u,2);
goto P_0c0ae2f8;
P_0c0ae2f8: /* original 0475, guest PC 0x0c0ae2f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2f8u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0ae2fa;
P_0c0ae2fa: /* original 5362, guest PC 0x0c0ae2fa */
if(!s->budget--) { s->failed_pc=0x0c0ae2fau; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2fc;
P_0c0ae2fc: /* original 7303, guest PC 0x0c0ae2fc */
if(!s->budget--) { s->failed_pc=0x0c0ae2fcu; return 0; }
r[3]+=0x00000003u;
goto P_0c0ae2fe;
P_0c0ae2fe: /* original afcd, guest PC 0x0c0ae2fe */
if(!s->budget--) { s->failed_pc=0x0c0ae2feu; return 0; }
write(ram,r[6]+8,r[3],4);
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae300: /* original 1632, guest PC 0x0c0ae300 */
if(!s->budget--) { s->failed_pc=0x0c0ae300u; return 0; }
write(ram,r[6]+8,r[3],4);
return vf3_matrix_family(0x0c0ae302u,s,ram);
P_0c0ae318: /* original 2fe6, guest PC 0x0c0ae318 */
if(!s->budget--) { s->failed_pc=0x0c0ae318u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae31a;
P_0c0ae31a: /* original 6e43, guest PC 0x0c0ae31a */
if(!s->budget--) { s->failed_pc=0x0c0ae31au; return 0; }
r[14]=r[4];
goto P_0c0ae31c;
P_0c0ae31c: /* original 2fd6, guest PC 0x0c0ae31c */
if(!s->budget--) { s->failed_pc=0x0c0ae31cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae31e;
P_0c0ae31e: /* original 6d63, guest PC 0x0c0ae31e */
if(!s->budget--) { s->failed_pc=0x0c0ae31eu; return 0; }
r[13]=r[6];
goto P_0c0ae320;
P_0c0ae320: /* original 2fc6, guest PC 0x0c0ae320 */
if(!s->budget--) { s->failed_pc=0x0c0ae320u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae322;
P_0c0ae322: /* original fffb, guest PC 0x0c0ae322 */
if(!s->budget--) { s->failed_pc=0x0c0ae322u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ae324;
P_0c0ae324: /* original 4f22, guest PC 0x0c0ae324 */
if(!s->budget--) { s->failed_pc=0x0c0ae324u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae326;
P_0c0ae326: /* original 7fe4, guest PC 0x0c0ae326 */
if(!s->budget--) { s->failed_pc=0x0c0ae326u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0ae328;
P_0c0ae328: /* original 1f51, guest PC 0x0c0ae328 */
if(!s->budget--) { s->failed_pc=0x0c0ae328u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0ae32a;
P_0c0ae32a: /* original d340, guest PC 0x0c0ae32a */
if(!s->budget--) { s->failed_pc=0x0c0ae32au; return 0; }
r[3]=read(ram,0x0c0ae42cu,4);
goto P_0c0ae32c;
P_0c0ae32c: /* original d43e, guest PC 0x0c0ae32c */
if(!s->budget--) { s->failed_pc=0x0c0ae32cu; return 0; }
r[4]=read(ram,0x0c0ae428u,4);
goto P_0c0ae32e;
P_0c0ae32e: /* original 1f32, guest PC 0x0c0ae32e */
if(!s->budget--) { s->failed_pc=0x0c0ae32eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ae330;
P_0c0ae330: /* original 52d1, guest PC 0x0c0ae330 */
if(!s->budget--) { s->failed_pc=0x0c0ae330u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ae332;
P_0c0ae332: /* original 61d2, guest PC 0x0c0ae332 */
if(!s->budget--) { s->failed_pc=0x0c0ae332u; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c0ae334;
P_0c0ae334: /* original 3120, guest PC 0x0c0ae334 */
if(!s->budget--) { s->failed_pc=0x0c0ae334u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0ae336;
P_0c0ae336: /* original 8b68, guest PC 0x0c0ae336 */
if(!s->budget--) { s->failed_pc=0x0c0ae336u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae338;
P_0c0ae338: /* original 5341, guest PC 0x0c0ae338 */
if(!s->budget--) { s->failed_pc=0x0c0ae338u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0ae33a;
P_0c0ae33a: /* original d53d, guest PC 0x0c0ae33a */
if(!s->budget--) { s->failed_pc=0x0c0ae33au; return 0; }
r[5]=read(ram,0x0c0ae430u,4);
goto P_0c0ae33c;
P_0c0ae33c: /* original 2358, guest PC 0x0c0ae33c */
if(!s->budget--) { s->failed_pc=0x0c0ae33cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0ae33e;
P_0c0ae33e: /* original 8b64, guest PC 0x0c0ae33e */
if(!s->budget--) { s->failed_pc=0x0c0ae33eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae340;
P_0c0ae340: /* original 6242, guest PC 0x0c0ae340 */
if(!s->budget--) { s->failed_pc=0x0c0ae340u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ae342;
P_0c0ae342: /* original 2528, guest PC 0x0c0ae342 */
if(!s->budget--) { s->failed_pc=0x0c0ae342u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0ae344;
P_0c0ae344: /* original 8b61, guest PC 0x0c0ae344 */
if(!s->budget--) { s->failed_pc=0x0c0ae344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae346;
P_0c0ae346: /* original 54d2, guest PC 0x0c0ae346 */
if(!s->budget--) { s->failed_pc=0x0c0ae346u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0ae348;
P_0c0ae348: /* original 9c6d, guest PC 0x0c0ae348 */
if(!s->budget--) { s->failed_pc=0x0c0ae348u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae426u,2);
goto P_0c0ae34a;
P_0c0ae34a: /* original 8444, guest PC 0x0c0ae34a */
if(!s->budget--) { s->failed_pc=0x0c0ae34au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0ae34c;
P_0c0ae34c: /* original d339, guest PC 0x0c0ae34c */
if(!s->budget--) { s->failed_pc=0x0c0ae34cu; return 0; }
r[3]=read(ram,0x0c0ae434u,4);
goto P_0c0ae34e;
P_0c0ae34e: /* original 600c, guest PC 0x0c0ae34e */
if(!s->budget--) { s->failed_pc=0x0c0ae34eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae350;
P_0c0ae350: /* original 62e2, guest PC 0x0c0ae350 */
if(!s->budget--) { s->failed_pc=0x0c0ae350u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ae352;
P_0c0ae352: /* original 4018, guest PC 0x0c0ae352 */
if(!s->budget--) { s->failed_pc=0x0c0ae352u; return 0; }
r[0]<<=8;
goto P_0c0ae354;
P_0c0ae354: /* original 2c09, guest PC 0x0c0ae354 */
if(!s->budget--) { s->failed_pc=0x0c0ae354u; return 0; }
r[12]&=r[0];
goto P_0c0ae356;
P_0c0ae356: /* original 8443, guest PC 0x0c0ae356 */
if(!s->budget--) { s->failed_pc=0x0c0ae356u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0ae358;
P_0c0ae358: /* original 2238, guest PC 0x0c0ae358 */
if(!s->budget--) { s->failed_pc=0x0c0ae358u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ae35a;
P_0c0ae35a: /* original 600c, guest PC 0x0c0ae35a */
if(!s->budget--) { s->failed_pc=0x0c0ae35au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae35c;
P_0c0ae35c: /* original 8d01, guest PC 0x0c0ae35c */
if(!s->budget--) { s->failed_pc=0x0c0ae35cu; return 0; }
cond=r[17]&1u;
r[12]|=r[0];
if(cond) { goto P_0c0ae362; }
goto P_0c0ae360;
P_0c0ae35e: /* original 2c0b, guest PC 0x0c0ae35e */
if(!s->budget--) { s->failed_pc=0x0c0ae35eu; return 0; }
r[12]|=r[0];
goto P_0c0ae360;
P_0c0ae360: /* original 6ccb, guest PC 0x0c0ae360 */
if(!s->budget--) { s->failed_pc=0x0c0ae360u; return 0; }
r[12]=0u-r[12];
goto P_0c0ae362;
P_0c0ae362: /* original 85ef, guest PC 0x0c0ae362 */
if(!s->budget--) { s->failed_pc=0x0c0ae362u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ae364;
P_0c0ae364: /* original d334, guest PC 0x0c0ae364 */
if(!s->budget--) { s->failed_pc=0x0c0ae364u; return 0; }
r[3]=read(ram,0x0c0ae438u,4);
goto P_0c0ae366;
P_0c0ae366: /* original 3c0c, guest PC 0x0c0ae366 */
if(!s->budget--) { s->failed_pc=0x0c0ae366u; return 0; }
r[12]+=r[0];
goto P_0c0ae368;
P_0c0ae368: /* original 64cb, guest PC 0x0c0ae368 */
if(!s->budget--) { s->failed_pc=0x0c0ae368u; return 0; }
r[4]=0u-r[12];
goto P_0c0ae36a;
P_0c0ae36a: /* original 644f, guest PC 0x0c0ae36a */
if(!s->budget--) { s->failed_pc=0x0c0ae36au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ae36c;
P_0c0ae36c: /* original 430b, guest PC 0x0c0ae36c */
if(!s->budget--) { s->failed_pc=0x0c0ae36cu; return 0; }
target=r[3];
r[16]=0x0c0ae370u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae370u) { target=s->pc; goto dispatch; }
goto P_0c0ae370;
P_0c0ae36e: /* original 2f42, guest PC 0x0c0ae36e */
if(!s->budget--) { s->failed_pc=0x0c0ae36eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0ae370;
P_0c0ae370: /* original d332, guest PC 0x0c0ae370 */
if(!s->budget--) { s->failed_pc=0x0c0ae370u; return 0; }
r[3]=read(ram,0x0c0ae43cu,4);
goto P_0c0ae372;
P_0c0ae372: /* original ff0c, guest PC 0x0c0ae372 */
if(!s->budget--) { s->failed_pc=0x0c0ae372u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0ae374;
P_0c0ae374: /* original 430b, guest PC 0x0c0ae374 */
if(!s->budget--) { s->failed_pc=0x0c0ae374u; return 0; }
target=r[3];
r[16]=0x0c0ae378u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae378u) { target=s->pc; goto dispatch; }
goto P_0c0ae378;
P_0c0ae376: /* original 64f2, guest PC 0x0c0ae376 */
if(!s->budget--) { s->failed_pc=0x0c0ae376u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ae378;
P_0c0ae378: /* original 64f3, guest PC 0x0c0ae378 */
if(!s->budget--) { s->failed_pc=0x0c0ae378u; return 0; }
r[4]=r[15];
goto P_0c0ae37a;
P_0c0ae37a: /* original 740c, guest PC 0x0c0ae37a */
if(!s->budget--) { s->failed_pc=0x0c0ae37au; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ae37c;
P_0c0ae37c: /* original 6543, guest PC 0x0c0ae37c */
if(!s->budget--) { s->failed_pc=0x0c0ae37cu; return 0; }
r[5]=r[4];
goto P_0c0ae37e;
P_0c0ae37e: /* original 6643, guest PC 0x0c0ae37e */
if(!s->budget--) { s->failed_pc=0x0c0ae37eu; return 0; }
r[6]=r[4];
goto P_0c0ae380;
P_0c0ae380: /* original 54d2, guest PC 0x0c0ae380 */
if(!s->budget--) { s->failed_pc=0x0c0ae380u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0ae382;
P_0c0ae382: /* original d330, guest PC 0x0c0ae382 */
if(!s->budget--) { s->failed_pc=0x0c0ae382u; return 0; }
r[3]=read(ram,0x0c0ae444u,4);
goto P_0c0ae384;
P_0c0ae384: /* original 8448, guest PC 0x0c0ae384 */
if(!s->budget--) { s->failed_pc=0x0c0ae384u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0ae386;
P_0c0ae386: /* original d230, guest PC 0x0c0ae386 */
if(!s->budget--) { s->failed_pc=0x0c0ae386u; return 0; }
r[2]=read(ram,0x0c0ae448u,4);
goto P_0c0ae388;
P_0c0ae388: /* original 600c, guest PC 0x0c0ae388 */
if(!s->budget--) { s->failed_pc=0x0c0ae388u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae38a;
P_0c0ae38a: /* original d72d, guest PC 0x0c0ae38a */
if(!s->budget--) { s->failed_pc=0x0c0ae38au; return 0; }
r[7]=read(ram,0x0c0ae440u,4);
goto P_0c0ae38c;
P_0c0ae38c: /* original 4028, guest PC 0x0c0ae38c */
if(!s->budget--) { s->failed_pc=0x0c0ae38cu; return 0; }
r[0]<<=16;
goto P_0c0ae38e;
P_0c0ae38e: /* original f50c, guest PC 0x0c0ae38e */
if(!s->budget--) { s->failed_pc=0x0c0ae38eu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0ae390;
P_0c0ae390: /* original 4018, guest PC 0x0c0ae390 */
if(!s->budget--) { s->failed_pc=0x0c0ae390u; return 0; }
r[0]<<=8;
goto P_0c0ae392;
P_0c0ae392: /* original 2039, guest PC 0x0c0ae392 */
if(!s->budget--) { s->failed_pc=0x0c0ae392u; return 0; }
r[0]&=r[3];
goto P_0c0ae394;
P_0c0ae394: /* original 6103, guest PC 0x0c0ae394 */
if(!s->budget--) { s->failed_pc=0x0c0ae394u; return 0; }
r[1]=r[0];
goto P_0c0ae396;
P_0c0ae396: /* original 8447, guest PC 0x0c0ae396 */
if(!s->budget--) { s->failed_pc=0x0c0ae396u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c0ae398;
P_0c0ae398: /* original 600c, guest PC 0x0c0ae398 */
if(!s->budget--) { s->failed_pc=0x0c0ae398u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae39a;
P_0c0ae39a: /* original 4028, guest PC 0x0c0ae39a */
if(!s->budget--) { s->failed_pc=0x0c0ae39au; return 0; }
r[0]<<=16;
goto P_0c0ae39c;
P_0c0ae39c: /* original 2029, guest PC 0x0c0ae39c */
if(!s->budget--) { s->failed_pc=0x0c0ae39cu; return 0; }
r[0]&=r[2];
goto P_0c0ae39e;
P_0c0ae39e: /* original 210b, guest PC 0x0c0ae39e */
if(!s->budget--) { s->failed_pc=0x0c0ae39eu; return 0; }
r[1]|=r[0];
goto P_0c0ae3a0;
P_0c0ae3a0: /* original 8446, guest PC 0x0c0ae3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0ae3a2;
P_0c0ae3a2: /* original 600c, guest PC 0x0c0ae3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3a4;
P_0c0ae3a4: /* original 4018, guest PC 0x0c0ae3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a4u; return 0; }
r[0]<<=8;
goto P_0c0ae3a6;
P_0c0ae3a6: /* original 2079, guest PC 0x0c0ae3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a6u; return 0; }
r[0]&=r[7];
goto P_0c0ae3a8;
P_0c0ae3a8: /* original 210b, guest PC 0x0c0ae3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a8u; return 0; }
r[1]|=r[0];
goto P_0c0ae3aa;
P_0c0ae3aa: /* original 8445, guest PC 0x0c0ae3aa */
if(!s->budget--) { s->failed_pc=0x0c0ae3aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0ae3ac;
P_0c0ae3ac: /* original 600c, guest PC 0x0c0ae3ac */
if(!s->budget--) { s->failed_pc=0x0c0ae3acu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3ae;
P_0c0ae3ae: /* original 210b, guest PC 0x0c0ae3ae */
if(!s->budget--) { s->failed_pc=0x0c0ae3aeu; return 0; }
r[1]|=r[0];
goto P_0c0ae3b0;
P_0c0ae3b0: /* original 2f12, guest PC 0x0c0ae3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b0u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ae3b2;
P_0c0ae3b2: /* original 844c, guest PC 0x0c0ae3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+12,1);
goto P_0c0ae3b4;
P_0c0ae3b4: /* original 600c, guest PC 0x0c0ae3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3b6;
P_0c0ae3b6: /* original 4028, guest PC 0x0c0ae3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b6u; return 0; }
r[0]<<=16;
goto P_0c0ae3b8;
P_0c0ae3b8: /* original 4018, guest PC 0x0c0ae3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b8u; return 0; }
r[0]<<=8;
goto P_0c0ae3ba;
P_0c0ae3ba: /* original 2039, guest PC 0x0c0ae3ba */
if(!s->budget--) { s->failed_pc=0x0c0ae3bau; return 0; }
r[0]&=r[3];
goto P_0c0ae3bc;
P_0c0ae3bc: /* original 6103, guest PC 0x0c0ae3bc */
if(!s->budget--) { s->failed_pc=0x0c0ae3bcu; return 0; }
r[1]=r[0];
goto P_0c0ae3be;
P_0c0ae3be: /* original 844b, guest PC 0x0c0ae3be */
if(!s->budget--) { s->failed_pc=0x0c0ae3beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c0ae3c0;
P_0c0ae3c0: /* original 600c, guest PC 0x0c0ae3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3c2;
P_0c0ae3c2: /* original 4028, guest PC 0x0c0ae3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c2u; return 0; }
r[0]<<=16;
goto P_0c0ae3c4;
P_0c0ae3c4: /* original 2029, guest PC 0x0c0ae3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c4u; return 0; }
r[0]&=r[2];
goto P_0c0ae3c6;
P_0c0ae3c6: /* original 210b, guest PC 0x0c0ae3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c6u; return 0; }
r[1]|=r[0];
goto P_0c0ae3c8;
P_0c0ae3c8: /* original 844a, guest PC 0x0c0ae3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0ae3ca;
P_0c0ae3ca: /* original 600c, guest PC 0x0c0ae3ca */
if(!s->budget--) { s->failed_pc=0x0c0ae3cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3cc;
P_0c0ae3cc: /* original 4018, guest PC 0x0c0ae3cc */
if(!s->budget--) { s->failed_pc=0x0c0ae3ccu; return 0; }
r[0]<<=8;
goto P_0c0ae3ce;
P_0c0ae3ce: /* original 2079, guest PC 0x0c0ae3ce */
if(!s->budget--) { s->failed_pc=0x0c0ae3ceu; return 0; }
r[0]&=r[7];
goto P_0c0ae3d0;
P_0c0ae3d0: /* original 210b, guest PC 0x0c0ae3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d0u; return 0; }
r[1]|=r[0];
goto P_0c0ae3d2;
P_0c0ae3d2: /* original 8449, guest PC 0x0c0ae3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c0ae3d4;
P_0c0ae3d4: /* original 6413, guest PC 0x0c0ae3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d4u; return 0; }
r[4]=r[1];
goto P_0c0ae3d6;
P_0c0ae3d6: /* original 61f2, guest PC 0x0c0ae3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d6u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0ae3d8;
P_0c0ae3d8: /* original 600c, guest PC 0x0c0ae3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3da;
P_0c0ae3da: /* original 2612, guest PC 0x0c0ae3da */
if(!s->budget--) { s->failed_pc=0x0c0ae3dau; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0ae3dc;
P_0c0ae3dc: /* original 240b, guest PC 0x0c0ae3dc */
if(!s->budget--) { s->failed_pc=0x0c0ae3dcu; return 0; }
r[4]|=r[0];
goto P_0c0ae3de;
P_0c0ae3de: /* original e004, guest PC 0x0c0ae3de */
if(!s->budget--) { s->failed_pc=0x0c0ae3deu; return 0; }
r[0]=0x00000004u;
goto P_0c0ae3e0;
P_0c0ae3e0: /* original 1641, guest PC 0x0c0ae3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e0u; return 0; }
write(ram,r[6]+4,r[4],4);
goto P_0c0ae3e2;
P_0c0ae3e2: /* original f658, guest PC 0x0c0ae3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e2u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c0ae3e4;
P_0c0ae3e4: /* original 51f2, guest PC 0x0c0ae3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e4u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0ae3e6;
P_0c0ae3e6: /* original ff62, guest PC 0x0c0ae3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c0ae3e8;
P_0c0ae3e8: /* original f456, guest PC 0x0c0ae3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0ae3ea;
P_0c0ae3ea: /* original f562, guest PC 0x0c0ae3ea */
if(!s->budget--) { s->failed_pc=0x0c0ae3eau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ae3ec;
P_0c0ae3ec: /* original f618, guest PC 0x0c0ae3ec */
if(!s->budget--) { s->failed_pc=0x0c0ae3ecu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0ae3ee;
P_0c0ae3ee: /* original e024, guest PC 0x0c0ae3ee */
if(!s->budget--) { s->failed_pc=0x0c0ae3eeu; return 0; }
r[0]=0x00000024u;
goto P_0c0ae3f0;
P_0c0ae3f0: /* original f462, guest PC 0x0c0ae3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ae3f2;
P_0c0ae3f2: /* original fef7, guest PC 0x0c0ae3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0ae3f4;
P_0c0ae3f4: /* original e028, guest PC 0x0c0ae3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f4u; return 0; }
r[0]=0x00000028u;
goto P_0c0ae3f6;
P_0c0ae3f6: /* original fe47, guest PC 0x0c0ae3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ae3f8;
P_0c0ae3f8: /* original 66d3, guest PC 0x0c0ae3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f8u; return 0; }
r[6]=r[13];
goto P_0c0ae3fa;
P_0c0ae3fa: /* original e02c, guest PC 0x0c0ae3fa */
if(!s->budget--) { s->failed_pc=0x0c0ae3fau; return 0; }
r[0]=0x0000002cu;
goto P_0c0ae3fc;
P_0c0ae3fc: /* original f54d, guest PC 0x0c0ae3fc */
if(!s->budget--) { s->failed_pc=0x0c0ae3fcu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0ae3fe;
P_0c0ae3fe: /* original 65e3, guest PC 0x0c0ae3fe */
if(!s->budget--) { s->failed_pc=0x0c0ae3feu; return 0; }
r[5]=r[14];
goto P_0c0ae400;
P_0c0ae400: /* original fe57, guest PC 0x0c0ae400 */
if(!s->budget--) { s->failed_pc=0x0c0ae400u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ae402;
P_0c0ae402: /* original 760c, guest PC 0x0c0ae402 */
if(!s->budget--) { s->failed_pc=0x0c0ae402u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ae404;
P_0c0ae404: /* original d111, guest PC 0x0c0ae404 */
if(!s->budget--) { s->failed_pc=0x0c0ae404u; return 0; }
r[1]=read(ram,0x0c0ae44cu,4);
goto P_0c0ae406;
P_0c0ae406: /* original 410b, guest PC 0x0c0ae406 */
if(!s->budget--) { s->failed_pc=0x0c0ae406u; return 0; }
target=r[1];
r[16]=0x0c0ae40au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae40au) { target=s->pc; goto dispatch; }
goto P_0c0ae40a;
P_0c0ae408: /* original 64e3, guest PC 0x0c0ae408 */
if(!s->budget--) { s->failed_pc=0x0c0ae408u; return 0; }
r[4]=r[14];
goto P_0c0ae40a;
P_0c0ae40a: /* original 53d2, guest PC 0x0c0ae40a */
if(!s->budget--) { s->failed_pc=0x0c0ae40au; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0ae40c;
P_0c0ae40c: /* original 66d3, guest PC 0x0c0ae40c */
if(!s->budget--) { s->failed_pc=0x0c0ae40cu; return 0; }
r[6]=r[13];
goto P_0c0ae40e;
P_0c0ae40e: /* original 730d, guest PC 0x0c0ae40e */
if(!s->budget--) { s->failed_pc=0x0c0ae40eu; return 0; }
r[3]+=0x0000000du;
goto P_0c0ae410;
P_0c0ae410: /* original 1d32, guest PC 0x0c0ae410 */
if(!s->budget--) { s->failed_pc=0x0c0ae410u; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0ae412;
P_0c0ae412: /* original 55f1, guest PC 0x0c0ae412 */
if(!s->budget--) { s->failed_pc=0x0c0ae412u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0ae414;
P_0c0ae414: /* original bf42, guest PC 0x0c0ae414 */
if(!s->budget--) { s->failed_pc=0x0c0ae414u; return 0; }
target=0x0c0ae29cu; r[16]=0x0c0ae418u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae418u) { target=s->pc; goto dispatch; }
goto P_0c0ae418;
P_0c0ae416: /* original 64e3, guest PC 0x0c0ae416 */
if(!s->budget--) { s->failed_pc=0x0c0ae416u; return 0; }
r[4]=r[14];
goto P_0c0ae418;
P_0c0ae418: /* original 7f1c, guest PC 0x0c0ae418 */
if(!s->budget--) { s->failed_pc=0x0c0ae418u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ae41a;
P_0c0ae41a: /* original 4f26, guest PC 0x0c0ae41a */
if(!s->budget--) { s->failed_pc=0x0c0ae41au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae41c;
P_0c0ae41c: /* original fff9, guest PC 0x0c0ae41c */
if(!s->budget--) { s->failed_pc=0x0c0ae41cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ae41e;
P_0c0ae41e: /* original 6cf6, guest PC 0x0c0ae41e */
if(!s->budget--) { s->failed_pc=0x0c0ae41eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae420;
P_0c0ae420: /* original 6df6, guest PC 0x0c0ae420 */
if(!s->budget--) { s->failed_pc=0x0c0ae420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae422;
P_0c0ae422: /* original 000b, guest PC 0x0c0ae422 */
if(!s->budget--) { s->failed_pc=0x0c0ae422u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ae424: /* original 6ef6, guest PC 0x0c0ae424 */
if(!s->budget--) { s->failed_pc=0x0c0ae424u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ae426u,s,ram);
P_0c0ae52c: /* original 5362, guest PC 0x0c0ae52c */
if(!s->budget--) { s->failed_pc=0x0c0ae52cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae52e;
P_0c0ae52e: /* original 7ffc, guest PC 0x0c0ae52e */
if(!s->budget--) { s->failed_pc=0x0c0ae52eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae530;
P_0c0ae530: /* original 7303, guest PC 0x0c0ae530 */
if(!s->budget--) { s->failed_pc=0x0c0ae530u; return 0; }
r[3]+=0x00000003u;
goto P_0c0ae532;
P_0c0ae532: /* original 6230, guest PC 0x0c0ae532 */
if(!s->budget--) { s->failed_pc=0x0c0ae532u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0ae534;
P_0c0ae534: /* original 2f22, guest PC 0x0c0ae534 */
if(!s->budget--) { s->failed_pc=0x0c0ae534u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae536;
P_0c0ae536: /* original 622b, guest PC 0x0c0ae536 */
if(!s->budget--) { s->failed_pc=0x0c0ae536u; return 0; }
r[2]=0u-r[2];
goto P_0c0ae538;
P_0c0ae538: /* original d718, guest PC 0x0c0ae538 */
if(!s->budget--) { s->failed_pc=0x0c0ae538u; return 0; }
r[7]=read(ram,0x0c0ae59cu,4);
goto P_0c0ae53a;
P_0c0ae53a: /* original 5363, guest PC 0x0c0ae53a */
if(!s->budget--) { s->failed_pc=0x0c0ae53au; return 0; }
r[3]=read(ram,r[6]+12,4);
goto P_0c0ae53c;
P_0c0ae53c: /* original 472d, guest PC 0x0c0ae53c */
if(!s->budget--) { s->failed_pc=0x0c0ae53cu; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?r[7]>>((-r[2])&31u):0):r[7]<<(r[2]&31u);
goto P_0c0ae53e;
P_0c0ae53e: /* original 6777, guest PC 0x0c0ae53e */
if(!s->budget--) { s->failed_pc=0x0c0ae53eu; return 0; }
r[7]=~r[7];
goto P_0c0ae540;
P_0c0ae540: /* original 2739, guest PC 0x0c0ae540 */
if(!s->budget--) { s->failed_pc=0x0c0ae540u; return 0; }
r[7]&=r[3];
goto P_0c0ae542;
P_0c0ae542: /* original 1673, guest PC 0x0c0ae542 */
if(!s->budget--) { s->failed_pc=0x0c0ae542u; return 0; }
write(ram,r[6]+12,r[7],4);
goto P_0c0ae544;
P_0c0ae544: /* original 5262, guest PC 0x0c0ae544 */
if(!s->budget--) { s->failed_pc=0x0c0ae544u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0ae546;
P_0c0ae546: /* original 7204, guest PC 0x0c0ae546 */
if(!s->budget--) { s->failed_pc=0x0c0ae546u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae548;
P_0c0ae548: /* original 1622, guest PC 0x0c0ae548 */
if(!s->budget--) { s->failed_pc=0x0c0ae548u; return 0; }
write(ram,r[6]+8,r[2],4);
goto P_0c0ae54a;
P_0c0ae54a: /* original aea7, guest PC 0x0c0ae54a */
if(!s->budget--) { s->failed_pc=0x0c0ae54au; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae54c: /* original 7f04, guest PC 0x0c0ae54c */
if(!s->budget--) { s->failed_pc=0x0c0ae54cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae54e;
P_0c0ae54e: /* original 5362, guest PC 0x0c0ae54e */
if(!s->budget--) { s->failed_pc=0x0c0ae54eu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae550;
P_0c0ae550: /* original 7ffc, guest PC 0x0c0ae550 */
if(!s->budget--) { s->failed_pc=0x0c0ae550u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae552;
P_0c0ae552: /* original 7303, guest PC 0x0c0ae552 */
if(!s->budget--) { s->failed_pc=0x0c0ae552u; return 0; }
r[3]+=0x00000003u;
goto P_0c0ae554;
P_0c0ae554: /* original 6230, guest PC 0x0c0ae554 */
if(!s->budget--) { s->failed_pc=0x0c0ae554u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0ae556;
P_0c0ae556: /* original 2f22, guest PC 0x0c0ae556 */
if(!s->budget--) { s->failed_pc=0x0c0ae556u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae558;
P_0c0ae558: /* original 622b, guest PC 0x0c0ae558 */
if(!s->budget--) { s->failed_pc=0x0c0ae558u; return 0; }
r[2]=0u-r[2];
goto P_0c0ae55a;
P_0c0ae55a: /* original d710, guest PC 0x0c0ae55a */
if(!s->budget--) { s->failed_pc=0x0c0ae55au; return 0; }
r[7]=read(ram,0x0c0ae59cu,4);
goto P_0c0ae55c;
P_0c0ae55c: /* original 5363, guest PC 0x0c0ae55c */
if(!s->budget--) { s->failed_pc=0x0c0ae55cu; return 0; }
r[3]=read(ram,r[6]+12,4);
goto P_0c0ae55e;
P_0c0ae55e: /* original 472d, guest PC 0x0c0ae55e */
if(!s->budget--) { s->failed_pc=0x0c0ae55eu; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?r[7]>>((-r[2])&31u):0):r[7]<<(r[2]&31u);
goto P_0c0ae560;
P_0c0ae560: /* original 273a, guest PC 0x0c0ae560 */
if(!s->budget--) { s->failed_pc=0x0c0ae560u; return 0; }
r[7]^=r[3];
goto P_0c0ae562;
P_0c0ae562: /* original 1673, guest PC 0x0c0ae562 */
if(!s->budget--) { s->failed_pc=0x0c0ae562u; return 0; }
write(ram,r[6]+12,r[7],4);
goto P_0c0ae564;
P_0c0ae564: /* original 5262, guest PC 0x0c0ae564 */
if(!s->budget--) { s->failed_pc=0x0c0ae564u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0ae566;
P_0c0ae566: /* original 7204, guest PC 0x0c0ae566 */
if(!s->budget--) { s->failed_pc=0x0c0ae566u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae568;
P_0c0ae568: /* original 1622, guest PC 0x0c0ae568 */
if(!s->budget--) { s->failed_pc=0x0c0ae568u; return 0; }
write(ram,r[6]+8,r[2],4);
goto P_0c0ae56a;
P_0c0ae56a: /* original ae97, guest PC 0x0c0ae56a */
if(!s->budget--) { s->failed_pc=0x0c0ae56au; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae56c: /* original 7f04, guest PC 0x0c0ae56c */
if(!s->budget--) { s->failed_pc=0x0c0ae56cu; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae56eu,s,ram);
P_0c0ae5a0: /* original 2fe6, guest PC 0x0c0ae5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a2;
P_0c0ae5a2: /* original 6e43, guest PC 0x0c0ae5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a2u; return 0; }
r[14]=r[4];
goto P_0c0ae5a4;
P_0c0ae5a4: /* original 2fd6, guest PC 0x0c0ae5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a6;
P_0c0ae5a6: /* original 2fc6, guest PC 0x0c0ae5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5a8;
P_0c0ae5a8: /* original 6c53, guest PC 0x0c0ae5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5a8u; return 0; }
r[12]=r[5];
goto P_0c0ae5aa;
P_0c0ae5aa: /* original 2fb6, guest PC 0x0c0ae5aa */
if(!s->budget--) { s->failed_pc=0x0c0ae5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5ac;
P_0c0ae5ac: /* original 2fa6, guest PC 0x0c0ae5ac */
if(!s->budget--) { s->failed_pc=0x0c0ae5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5ae;
P_0c0ae5ae: /* original 2f96, guest PC 0x0c0ae5ae */
if(!s->budget--) { s->failed_pc=0x0c0ae5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae5b0;
P_0c0ae5b0: /* original 4f22, guest PC 0x0c0ae5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae5b2;
P_0c0ae5b2: /* original d444, guest PC 0x0c0ae5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b2u; return 0; }
r[4]=read(ram,0x0c0ae6c4u,4);
goto P_0c0ae5b4;
P_0c0ae5b4: /* original d942, guest PC 0x0c0ae5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b4u; return 0; }
r[9]=read(ram,0x0c0ae6c0u,4);
goto P_0c0ae5b6;
P_0c0ae5b6: /* original 5345, guest PC 0x0c0ae5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b6u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0ae5b8;
P_0c0ae5b8: /* original 4f12, guest PC 0x0c0ae5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5b8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0ae5ba;
P_0c0ae5ba: /* original 4315, guest PC 0x0c0ae5ba */
if(!s->budget--) { s->failed_pc=0x0c0ae5bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0ae5bc;
P_0c0ae5bc: /* original 8f68, guest PC 0x0c0ae5bc */
if(!s->budget--) { s->failed_pc=0x0c0ae5bcu; return 0; }
cond=r[17]&1u;
r[10]=r[6];
if(!cond) { goto P_0c0ae690; }
goto P_0c0ae5c0;
P_0c0ae5be: /* original 6a63, guest PC 0x0c0ae5be */
if(!s->budget--) { s->failed_pc=0x0c0ae5beu; return 0; }
r[10]=r[6];
goto P_0c0ae5c0;
P_0c0ae5c0: /* original 9075, guest PC 0x0c0ae5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6aeu,2);
goto P_0c0ae5c2;
P_0c0ae5c2: /* original 5ba2, guest PC 0x0c0ae5c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c2u; return 0; }
r[11]=read(ram,r[10]+8,4);
goto P_0c0ae5c4;
P_0c0ae5c4: /* original 03cc, guest PC 0x0c0ae5c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae5c6;
P_0c0ae5c6: /* original e064, guest PC 0x0c0ae5c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c6u; return 0; }
r[0]=0x00000064u;
goto P_0c0ae5c8;
P_0c0ae5c8: /* original 7b03, guest PC 0x0c0ae5c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5c8u; return 0; }
r[11]+=0x00000003u;
goto P_0c0ae5ca;
P_0c0ae5ca: /* original 6bb0, guest PC 0x0c0ae5ca */
if(!s->budget--) { s->failed_pc=0x0c0ae5cau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0ae5cc;
P_0c0ae5cc: /* original 633c, guest PC 0x0c0ae5cc */
if(!s->budget--) { s->failed_pc=0x0c0ae5ccu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae5ce;
P_0c0ae5ce: /* original 7364, guest PC 0x0c0ae5ce */
if(!s->budget--) { s->failed_pc=0x0c0ae5ceu; return 0; }
r[3]+=0x00000064u;
goto P_0c0ae5d0;
P_0c0ae5d0: /* original 6bbc, guest PC 0x0c0ae5d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d0u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae5d2;
P_0c0ae5d2: /* original 0b37, guest PC 0x0c0ae5d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d2u; return 0; }
r[19]=r[11]*r[3];
goto P_0c0ae5d4;
P_0c0ae5d4: /* original d33c, guest PC 0x0c0ae5d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d4u; return 0; }
r[3]=read(ram,0x0c0ae6c8u,4);
goto P_0c0ae5d6;
P_0c0ae5d6: /* original 0b1a, guest PC 0x0c0ae5d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d6u; return 0; }
r[11]=r[19];
goto P_0c0ae5d8;
P_0c0ae5d8: /* original 430b, guest PC 0x0c0ae5d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5d8u; return 0; }
target=r[3];
r[16]=0x0c0ae5dcu;
r[1]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae5dcu) { target=s->pc; goto dispatch; }
goto P_0c0ae5dc;
P_0c0ae5da: /* original 61b3, guest PC 0x0c0ae5da */
if(!s->budget--) { s->failed_pc=0x0c0ae5dau; return 0; }
r[1]=r[11];
goto P_0c0ae5dc;
P_0c0ae5dc: /* original 6b03, guest PC 0x0c0ae5dc */
if(!s->budget--) { s->failed_pc=0x0c0ae5dcu; return 0; }
r[11]=r[0];
goto P_0c0ae5de;
P_0c0ae5de: /* original 9067, guest PC 0x0c0ae5de */
if(!s->budget--) { s->failed_pc=0x0c0ae5deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b0u,2);
goto P_0c0ae5e0;
P_0c0ae5e0: /* original 65c3, guest PC 0x0c0ae5e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e0u; return 0; }
r[5]=r[12];
goto P_0c0ae5e2;
P_0c0ae5e2: /* original 66b3, guest PC 0x0c0ae5e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e2u; return 0; }
r[6]=r[11];
goto P_0c0ae5e4;
P_0c0ae5e4: /* original 04ed, guest PC 0x0c0ae5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ae5e6;
P_0c0ae5e6: /* original 34bc, guest PC 0x0c0ae5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e6u; return 0; }
r[4]+=r[11];
goto P_0c0ae5e8;
P_0c0ae5e8: /* original 0e45, guest PC 0x0c0ae5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5e8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ae5ea;
P_0c0ae5ea: /* original d338, guest PC 0x0c0ae5ea */
if(!s->budget--) { s->failed_pc=0x0c0ae5eau; return 0; }
r[3]=read(ram,0x0c0ae6ccu,4);
goto P_0c0ae5ec;
P_0c0ae5ec: /* original 430b, guest PC 0x0c0ae5ec */
if(!s->budget--) { s->failed_pc=0x0c0ae5ecu; return 0; }
target=r[3];
r[16]=0x0c0ae5f0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae5f0u) { target=s->pc; goto dispatch; }
goto P_0c0ae5f0;
P_0c0ae5ee: /* original 64e3, guest PC 0x0c0ae5ee */
if(!s->budget--) { s->failed_pc=0x0c0ae5eeu; return 0; }
r[4]=r[14];
goto P_0c0ae5f0;
P_0c0ae5f0: /* original 905f, guest PC 0x0c0ae5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b2u,2);
goto P_0c0ae5f2;
P_0c0ae5f2: /* original e401, guest PC 0x0c0ae5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f2u; return 0; }
r[4]=0x00000001u;
goto P_0c0ae5f4;
P_0c0ae5f4: /* original 02ec, guest PC 0x0c0ae5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae5f6;
P_0c0ae5f6: /* original 7201, guest PC 0x0c0ae5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae5f8;
P_0c0ae5f8: /* original 0e24, guest PC 0x0c0ae5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae5f8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ae5fa;
P_0c0ae5fa: /* original 905b, guest PC 0x0c0ae5fa */
if(!s->budget--) { s->failed_pc=0x0c0ae5fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b4u,2);
goto P_0c0ae5fc;
P_0c0ae5fc: /* original 06ec, guest PC 0x0c0ae5fc */
if(!s->budget--) { s->failed_pc=0x0c0ae5fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae5fe;
P_0c0ae5fe: /* original 905a, guest PC 0x0c0ae5fe */
if(!s->budget--) { s->failed_pc=0x0c0ae5feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b6u,2);
goto P_0c0ae600;
P_0c0ae600: /* original 666c, guest PC 0x0c0ae600 */
if(!s->budget--) { s->failed_pc=0x0c0ae600u; return 0; }
r[6]=r[6]&255u;
goto P_0c0ae602;
P_0c0ae602: /* original 05ec, guest PC 0x0c0ae602 */
if(!s->budget--) { s->failed_pc=0x0c0ae602u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae604;
P_0c0ae604: /* original 3643, guest PC 0x0c0ae604 */
if(!s->budget--) { s->failed_pc=0x0c0ae604u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c0ae606;
P_0c0ae606: /* original 655c, guest PC 0x0c0ae606 */
if(!s->budget--) { s->failed_pc=0x0c0ae606u; return 0; }
r[5]=r[5]&255u;
goto P_0c0ae608;
P_0c0ae608: /* original 8d02, guest PC 0x0c0ae608 */
if(!s->budget--) { s->failed_pc=0x0c0ae608u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c0ae610; }
goto P_0c0ae60c;
P_0c0ae60a: /* original 6db3, guest PC 0x0c0ae60a */
if(!s->budget--) { s->failed_pc=0x0c0ae60au; return 0; }
r[13]=r[11];
goto P_0c0ae60c;
P_0c0ae60c: /* original 3543, guest PC 0x0c0ae60c */
if(!s->budget--) { s->failed_pc=0x0c0ae60cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[4])!=0);
goto P_0c0ae60e;
P_0c0ae60e: /* original 8b03, guest PC 0x0c0ae60e */
if(!s->budget--) { s->failed_pc=0x0c0ae60eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae618; }
goto P_0c0ae610;
P_0c0ae610: /* original 9052, guest PC 0x0c0ae610 */
if(!s->budget--) { s->failed_pc=0x0c0ae610u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b8u,2);
goto P_0c0ae612;
P_0c0ae612: /* original 0dcd, guest PC 0x0c0ae612 */
if(!s->budget--) { s->failed_pc=0x0c0ae612u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0ae614;
P_0c0ae614: /* original 6ddd, guest PC 0x0c0ae614 */
if(!s->budget--) { s->failed_pc=0x0c0ae614u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0ae616;
P_0c0ae616: /* original 3dbc, guest PC 0x0c0ae616 */
if(!s->budget--) { s->failed_pc=0x0c0ae616u; return 0; }
r[13]+=r[11];
goto P_0c0ae618;
P_0c0ae618: /* original 904e, guest PC 0x0c0ae618 */
if(!s->budget--) { s->failed_pc=0x0c0ae618u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b8u,2);
goto P_0c0ae61a;
P_0c0ae61a: /* original 0cd5, guest PC 0x0c0ae61a */
if(!s->budget--) { s->failed_pc=0x0c0ae61au; return 0; }
write(ram,r[12]+r[0],r[13],2);
goto P_0c0ae61c;
P_0c0ae61c: /* original 6492, guest PC 0x0c0ae61c */
if(!s->budget--) { s->failed_pc=0x0c0ae61cu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0ae61e;
P_0c0ae61e: /* original 934c, guest PC 0x0c0ae61e */
if(!s->budget--) { s->failed_pc=0x0c0ae61eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6bau,2);
goto P_0c0ae620;
P_0c0ae620: /* original 2348, guest PC 0x0c0ae620 */
if(!s->budget--) { s->failed_pc=0x0c0ae620u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ae622;
P_0c0ae622: /* original 8f06, guest PC 0x0c0ae622 */
if(!s->budget--) { s->failed_pc=0x0c0ae622u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[9]+4,4);
if(!cond) { goto P_0c0ae632; }
goto P_0c0ae626;
P_0c0ae624: /* original 5591, guest PC 0x0c0ae624 */
if(!s->budget--) { s->failed_pc=0x0c0ae624u; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0ae626;
P_0c0ae626: /* original d22a, guest PC 0x0c0ae626 */
if(!s->budget--) { s->failed_pc=0x0c0ae626u; return 0; }
r[2]=read(ram,0x0c0ae6d0u,4);
goto P_0c0ae628;
P_0c0ae628: /* original 2428, guest PC 0x0c0ae628 */
if(!s->budget--) { s->failed_pc=0x0c0ae628u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ae62a;
P_0c0ae62a: /* original 8931, guest PC 0x0c0ae62a */
if(!s->budget--) { s->failed_pc=0x0c0ae62au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae62c;
P_0c0ae62c: /* original d329, guest PC 0x0c0ae62c */
if(!s->budget--) { s->failed_pc=0x0c0ae62cu; return 0; }
r[3]=read(ram,0x0c0ae6d4u,4);
goto P_0c0ae62e;
P_0c0ae62e: /* original 2538, guest PC 0x0c0ae62e */
if(!s->budget--) { s->failed_pc=0x0c0ae62eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0ae630;
P_0c0ae630: /* original 892e, guest PC 0x0c0ae630 */
if(!s->budget--) { s->failed_pc=0x0c0ae630u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae632;
P_0c0ae632: /* original d229, guest PC 0x0c0ae632 */
if(!s->budget--) { s->failed_pc=0x0c0ae632u; return 0; }
r[2]=read(ram,0x0c0ae6d8u,4);
goto P_0c0ae634;
P_0c0ae634: /* original 6020, guest PC 0x0c0ae634 */
if(!s->budget--) { s->failed_pc=0x0c0ae634u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0ae636;
P_0c0ae636: /* original 600c, guest PC 0x0c0ae636 */
if(!s->budget--) { s->failed_pc=0x0c0ae636u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae638;
P_0c0ae638: /* original 8803, guest PC 0x0c0ae638 */
if(!s->budget--) { s->failed_pc=0x0c0ae638u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ae63a;
P_0c0ae63a: /* original 8b29, guest PC 0x0c0ae63a */
if(!s->budget--) { s->failed_pc=0x0c0ae63au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae690; }
goto P_0c0ae63c;
P_0c0ae63c: /* original e061, guest PC 0x0c0ae63c */
if(!s->budget--) { s->failed_pc=0x0c0ae63cu; return 0; }
r[0]=0x00000061u;
goto P_0c0ae63e;
P_0c0ae63e: /* original db27, guest PC 0x0c0ae63e */
if(!s->budget--) { s->failed_pc=0x0c0ae63eu; return 0; }
r[11]=read(ram,0x0c0ae6dcu,4);
goto P_0c0ae640;
P_0c0ae640: /* original 04cc, guest PC 0x0c0ae640 */
if(!s->budget--) { s->failed_pc=0x0c0ae640u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae642;
P_0c0ae642: /* original 933b, guest PC 0x0c0ae642 */
if(!s->budget--) { s->failed_pc=0x0c0ae642u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6bcu,2);
goto P_0c0ae644;
P_0c0ae644: /* original 694c, guest PC 0x0c0ae644 */
if(!s->budget--) { s->failed_pc=0x0c0ae644u; return 0; }
r[9]=r[4]&255u;
goto P_0c0ae646;
P_0c0ae646: /* original d126, guest PC 0x0c0ae646 */
if(!s->budget--) { s->failed_pc=0x0c0ae646u; return 0; }
r[1]=read(ram,0x0c0ae6e0u,4);
goto P_0c0ae648;
P_0c0ae648: /* original 33bc, guest PC 0x0c0ae648 */
if(!s->budget--) { s->failed_pc=0x0c0ae648u; return 0; }
r[3]+=r[11];
goto P_0c0ae64a;
P_0c0ae64a: /* original 4908, guest PC 0x0c0ae64a */
if(!s->budget--) { s->failed_pc=0x0c0ae64au; return 0; }
r[9]<<=2;
goto P_0c0ae64c;
P_0c0ae64c: /* original 393c, guest PC 0x0c0ae64c */
if(!s->budget--) { s->failed_pc=0x0c0ae64cu; return 0; }
r[9]+=r[3];
goto P_0c0ae64e;
P_0c0ae64e: /* original 410b, guest PC 0x0c0ae64e */
if(!s->budget--) { s->failed_pc=0x0c0ae64eu; return 0; }
target=r[1];
r[16]=0x0c0ae652u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae652u) { target=s->pc; goto dispatch; }
goto P_0c0ae652;
P_0c0ae650: /* original 6493, guest PC 0x0c0ae650 */
if(!s->budget--) { s->failed_pc=0x0c0ae650u; return 0; }
r[4]=r[9];
goto P_0c0ae652;
P_0c0ae652: /* original 6403, guest PC 0x0c0ae652 */
if(!s->budget--) { s->failed_pc=0x0c0ae652u; return 0; }
r[4]=r[0];
goto P_0c0ae654;
P_0c0ae654: /* original 34d3, guest PC 0x0c0ae654 */
if(!s->budget--) { s->failed_pc=0x0c0ae654u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[13])!=0);
goto P_0c0ae656;
P_0c0ae656: /* original 8903, guest PC 0x0c0ae656 */
if(!s->budget--) { s->failed_pc=0x0c0ae656u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae660; }
goto P_0c0ae658;
P_0c0ae658: /* original d322, guest PC 0x0c0ae658 */
if(!s->budget--) { s->failed_pc=0x0c0ae658u; return 0; }
r[3]=read(ram,0x0c0ae6e4u,4);
goto P_0c0ae65a;
P_0c0ae65a: /* original 65d3, guest PC 0x0c0ae65a */
if(!s->budget--) { s->failed_pc=0x0c0ae65au; return 0; }
r[5]=r[13];
goto P_0c0ae65c;
P_0c0ae65c: /* original 430b, guest PC 0x0c0ae65c */
if(!s->budget--) { s->failed_pc=0x0c0ae65cu; return 0; }
target=r[3];
r[16]=0x0c0ae660u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae660u) { target=s->pc; goto dispatch; }
goto P_0c0ae660;
P_0c0ae65e: /* original 6493, guest PC 0x0c0ae65e */
if(!s->budget--) { s->failed_pc=0x0c0ae65eu; return 0; }
r[4]=r[9];
goto P_0c0ae660;
P_0c0ae660: /* original 9028, guest PC 0x0c0ae660 */
if(!s->budget--) { s->failed_pc=0x0c0ae660u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b4u,2);
goto P_0c0ae662;
P_0c0ae662: /* original 922c, guest PC 0x0c0ae662 */
if(!s->budget--) { s->failed_pc=0x0c0ae662u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6beu,2);
goto P_0c0ae664;
P_0c0ae664: /* original 0dec, guest PC 0x0c0ae664 */
if(!s->budget--) { s->failed_pc=0x0c0ae664u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae666;
P_0c0ae666: /* original 9026, guest PC 0x0c0ae666 */
if(!s->budget--) { s->failed_pc=0x0c0ae666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae6b6u,2);
goto P_0c0ae668;
P_0c0ae668: /* original 3b2c, guest PC 0x0c0ae668 */
if(!s->budget--) { s->failed_pc=0x0c0ae668u; return 0; }
r[11]+=r[2];
goto P_0c0ae66a;
P_0c0ae66a: /* original 6ddc, guest PC 0x0c0ae66a */
if(!s->budget--) { s->failed_pc=0x0c0ae66au; return 0; }
r[13]=r[13]&255u;
goto P_0c0ae66c;
P_0c0ae66c: /* original 04ec, guest PC 0x0c0ae66c */
if(!s->budget--) { s->failed_pc=0x0c0ae66cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ae66e;
P_0c0ae66e: /* original e061, guest PC 0x0c0ae66e */
if(!s->budget--) { s->failed_pc=0x0c0ae66eu; return 0; }
r[0]=0x00000061u;
goto P_0c0ae670;
P_0c0ae670: /* original 03cc, guest PC 0x0c0ae670 */
if(!s->budget--) { s->failed_pc=0x0c0ae670u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae672;
P_0c0ae672: /* original 644c, guest PC 0x0c0ae672 */
if(!s->budget--) { s->failed_pc=0x0c0ae672u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae674;
P_0c0ae674: /* original 633c, guest PC 0x0c0ae674 */
if(!s->budget--) { s->failed_pc=0x0c0ae674u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae676;
P_0c0ae676: /* original 4308, guest PC 0x0c0ae676 */
if(!s->budget--) { s->failed_pc=0x0c0ae676u; return 0; }
r[3]<<=2;
goto P_0c0ae678;
P_0c0ae678: /* original 3b3c, guest PC 0x0c0ae678 */
if(!s->budget--) { s->failed_pc=0x0c0ae678u; return 0; }
r[11]+=r[3];
goto P_0c0ae67a;
P_0c0ae67a: /* original d319, guest PC 0x0c0ae67a */
if(!s->budget--) { s->failed_pc=0x0c0ae67au; return 0; }
r[3]=read(ram,0x0c0ae6e0u,4);
goto P_0c0ae67c;
P_0c0ae67c: /* original 3d4c, guest PC 0x0c0ae67c */
if(!s->budget--) { s->failed_pc=0x0c0ae67cu; return 0; }
r[13]+=r[4];
goto P_0c0ae67e;
P_0c0ae67e: /* original 430b, guest PC 0x0c0ae67e */
if(!s->budget--) { s->failed_pc=0x0c0ae67eu; return 0; }
target=r[3];
r[16]=0x0c0ae682u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae682u) { target=s->pc; goto dispatch; }
goto P_0c0ae682;
P_0c0ae680: /* original 64b3, guest PC 0x0c0ae680 */
if(!s->budget--) { s->failed_pc=0x0c0ae680u; return 0; }
r[4]=r[11];
goto P_0c0ae682;
P_0c0ae682: /* original 6403, guest PC 0x0c0ae682 */
if(!s->budget--) { s->failed_pc=0x0c0ae682u; return 0; }
r[4]=r[0];
goto P_0c0ae684;
P_0c0ae684: /* original 34d3, guest PC 0x0c0ae684 */
if(!s->budget--) { s->failed_pc=0x0c0ae684u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[13])!=0);
goto P_0c0ae686;
P_0c0ae686: /* original 8903, guest PC 0x0c0ae686 */
if(!s->budget--) { s->failed_pc=0x0c0ae686u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae690; }
goto P_0c0ae688;
P_0c0ae688: /* original d216, guest PC 0x0c0ae688 */
if(!s->budget--) { s->failed_pc=0x0c0ae688u; return 0; }
r[2]=read(ram,0x0c0ae6e4u,4);
goto P_0c0ae68a;
P_0c0ae68a: /* original 65d3, guest PC 0x0c0ae68a */
if(!s->budget--) { s->failed_pc=0x0c0ae68au; return 0; }
r[5]=r[13];
goto P_0c0ae68c;
P_0c0ae68c: /* original 420b, guest PC 0x0c0ae68c */
if(!s->budget--) { s->failed_pc=0x0c0ae68cu; return 0; }
target=r[2];
r[16]=0x0c0ae690u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae690u) { target=s->pc; goto dispatch; }
goto P_0c0ae690;
P_0c0ae68e: /* original 64b3, guest PC 0x0c0ae68e */
if(!s->budget--) { s->failed_pc=0x0c0ae68eu; return 0; }
r[4]=r[11];
goto P_0c0ae690;
P_0c0ae690: /* original 4f16, guest PC 0x0c0ae690 */
if(!s->budget--) { s->failed_pc=0x0c0ae690u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae692;
P_0c0ae692: /* original 53a2, guest PC 0x0c0ae692 */
if(!s->budget--) { s->failed_pc=0x0c0ae692u; return 0; }
r[3]=read(ram,r[10]+8,4);
goto P_0c0ae694;
P_0c0ae694: /* original 66a3, guest PC 0x0c0ae694 */
if(!s->budget--) { s->failed_pc=0x0c0ae694u; return 0; }
r[6]=r[10];
goto P_0c0ae696;
P_0c0ae696: /* original 65c3, guest PC 0x0c0ae696 */
if(!s->budget--) { s->failed_pc=0x0c0ae696u; return 0; }
r[5]=r[12];
goto P_0c0ae698;
P_0c0ae698: /* original 64e3, guest PC 0x0c0ae698 */
if(!s->budget--) { s->failed_pc=0x0c0ae698u; return 0; }
r[4]=r[14];
goto P_0c0ae69a;
P_0c0ae69a: /* original 4f26, guest PC 0x0c0ae69a */
if(!s->budget--) { s->failed_pc=0x0c0ae69au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae69c;
P_0c0ae69c: /* original 7304, guest PC 0x0c0ae69c */
if(!s->budget--) { s->failed_pc=0x0c0ae69cu; return 0; }
r[3]+=0x00000004u;
goto P_0c0ae69e;
P_0c0ae69e: /* original 1a32, guest PC 0x0c0ae69e */
if(!s->budget--) { s->failed_pc=0x0c0ae69eu; return 0; }
write(ram,r[10]+8,r[3],4);
goto P_0c0ae6a0;
P_0c0ae6a0: /* original 69f6, guest PC 0x0c0ae6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae6a2;
P_0c0ae6a2: /* original 6af6, guest PC 0x0c0ae6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae6a4;
P_0c0ae6a4: /* original 6bf6, guest PC 0x0c0ae6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae6a6;
P_0c0ae6a6: /* original 6cf6, guest PC 0x0c0ae6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae6a8;
P_0c0ae6a8: /* original 6df6, guest PC 0x0c0ae6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae6aa;
P_0c0ae6aa: /* original adf7, guest PC 0x0c0ae6aa */
if(!s->budget--) { s->failed_pc=0x0c0ae6aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ae29cu,s,ram);
P_0c0ae6ac: /* original 6ef6, guest PC 0x0c0ae6ac */
if(!s->budget--) { s->failed_pc=0x0c0ae6acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ae6aeu,s,ram);
P_0c0ae9ec: /* original 2fe6, guest PC 0x0c0ae9ec */
if(!s->budget--) { s->failed_pc=0x0c0ae9ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9ee;
P_0c0ae9ee: /* original 6e63, guest PC 0x0c0ae9ee */
if(!s->budget--) { s->failed_pc=0x0c0ae9eeu; return 0; }
r[14]=r[6];
goto P_0c0ae9f0;
P_0c0ae9f0: /* original 2fd6, guest PC 0x0c0ae9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9f2;
P_0c0ae9f2: /* original 2fc6, guest PC 0x0c0ae9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae9f4;
P_0c0ae9f4: /* original 6c43, guest PC 0x0c0ae9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f4u; return 0; }
r[12]=r[4];
goto P_0c0ae9f6;
P_0c0ae9f6: /* original 4f22, guest PC 0x0c0ae9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae9f8;
P_0c0ae9f8: /* original 7fdc, guest PC 0x0c0ae9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae9f8u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c0ae9fa;
P_0c0ae9fa: /* original 2f52, guest PC 0x0c0ae9fa */
if(!s->budget--) { s->failed_pc=0x0c0ae9fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae9fc;
P_0c0ae9fc: /* original 53e1, guest PC 0x0c0ae9fc */
if(!s->budget--) { s->failed_pc=0x0c0ae9fcu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0ae9fe;
P_0c0ae9fe: /* original 62e2, guest PC 0x0c0ae9fe */
if(!s->budget--) { s->failed_pc=0x0c0ae9feu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aea00;
P_0c0aea00: /* original d439, guest PC 0x0c0aea00 */
if(!s->budget--) { s->failed_pc=0x0c0aea00u; return 0; }
r[4]=read(ram,0x0c0aeae8u,4);
goto P_0c0aea02;
P_0c0aea02: /* original dd38, guest PC 0x0c0aea02 */
if(!s->budget--) { s->failed_pc=0x0c0aea02u; return 0; }
r[13]=read(ram,0x0c0aeae4u,4);
goto P_0c0aea04;
P_0c0aea04: /* original 3230, guest PC 0x0c0aea04 */
if(!s->budget--) { s->failed_pc=0x0c0aea04u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aea06;
P_0c0aea06: /* original 8b1c, guest PC 0x0c0aea06 */
if(!s->budget--) { s->failed_pc=0x0c0aea06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea08;
P_0c0aea08: /* original 51d1, guest PC 0x0c0aea08 */
if(!s->budget--) { s->failed_pc=0x0c0aea08u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0aea0a;
P_0c0aea0a: /* original d338, guest PC 0x0c0aea0a */
if(!s->budget--) { s->failed_pc=0x0c0aea0au; return 0; }
r[3]=read(ram,0x0c0aeaecu,4);
goto P_0c0aea0c;
P_0c0aea0c: /* original 2138, guest PC 0x0c0aea0c */
if(!s->budget--) { s->failed_pc=0x0c0aea0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aea0e;
P_0c0aea0e: /* original 8b18, guest PC 0x0c0aea0e */
if(!s->budget--) { s->failed_pc=0x0c0aea0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea10;
P_0c0aea10: /* original 5245, guest PC 0x0c0aea10 */
if(!s->budget--) { s->failed_pc=0x0c0aea10u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c0aea12;
P_0c0aea12: /* original 4215, guest PC 0x0c0aea12 */
if(!s->budget--) { s->failed_pc=0x0c0aea12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0aea14;
P_0c0aea14: /* original 8b15, guest PC 0x0c0aea14 */
if(!s->budget--) { s->failed_pc=0x0c0aea14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea16;
P_0c0aea16: /* original 54e2, guest PC 0x0c0aea16 */
if(!s->budget--) { s->failed_pc=0x0c0aea16u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0aea18;
P_0c0aea18: /* original 9063, guest PC 0x0c0aea18 */
if(!s->budget--) { s->failed_pc=0x0c0aea18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aeae2u,2);
goto P_0c0aea1a;
P_0c0aea1a: /* original 7403, guest PC 0x0c0aea1a */
if(!s->budget--) { s->failed_pc=0x0c0aea1au; return 0; }
r[4]+=0x00000003u;
goto P_0c0aea1c;
P_0c0aea1c: /* original 05cc, guest PC 0x0c0aea1c */
if(!s->budget--) { s->failed_pc=0x0c0aea1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0aea1e;
P_0c0aea1e: /* original 6440, guest PC 0x0c0aea1e */
if(!s->budget--) { s->failed_pc=0x0c0aea1eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aea20;
P_0c0aea20: /* original 655c, guest PC 0x0c0aea20 */
if(!s->budget--) { s->failed_pc=0x0c0aea20u; return 0; }
r[5]=r[5]&255u;
goto P_0c0aea22;
P_0c0aea22: /* original 354c, guest PC 0x0c0aea22 */
if(!s->budget--) { s->failed_pc=0x0c0aea22u; return 0; }
r[5]+=r[4];
goto P_0c0aea24;
P_0c0aea24: /* original e428, guest PC 0x0c0aea24 */
if(!s->budget--) { s->failed_pc=0x0c0aea24u; return 0; }
r[4]=0x00000028u;
goto P_0c0aea26;
P_0c0aea26: /* original 3547, guest PC 0x0c0aea26 */
if(!s->budget--) { s->failed_pc=0x0c0aea26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[4])!=0);
goto P_0c0aea28;
P_0c0aea28: /* original 8b00, guest PC 0x0c0aea28 */
if(!s->budget--) { s->failed_pc=0x0c0aea28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea2c; }
goto P_0c0aea2a;
P_0c0aea2a: /* original 6543, guest PC 0x0c0aea2a */
if(!s->budget--) { s->failed_pc=0x0c0aea2au; return 0; }
r[5]=r[4];
goto P_0c0aea2c;
P_0c0aea2c: /* original 0c54, guest PC 0x0c0aea2c */
if(!s->budget--) { s->failed_pc=0x0c0aea2cu; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0aea2e;
P_0c0aea2e: /* original d330, guest PC 0x0c0aea2e */
if(!s->budget--) { s->failed_pc=0x0c0aea2eu; return 0; }
r[3]=read(ram,0x0c0aeaf0u,4);
goto P_0c0aea30;
P_0c0aea30: /* original 430b, guest PC 0x0c0aea30 */
if(!s->budget--) { s->failed_pc=0x0c0aea30u; return 0; }
target=r[3];
r[16]=0x0c0aea34u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aea34u) { target=s->pc; goto dispatch; }
goto P_0c0aea34;
P_0c0aea32: /* original 64c3, guest PC 0x0c0aea32 */
if(!s->budget--) { s->failed_pc=0x0c0aea32u; return 0; }
r[4]=r[12];
goto P_0c0aea34;
P_0c0aea34: /* original 84d8, guest PC 0x0c0aea34 */
if(!s->budget--) { s->failed_pc=0x0c0aea34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+8,1);
goto P_0c0aea36;
P_0c0aea36: /* original 600c, guest PC 0x0c0aea36 */
if(!s->budget--) { s->failed_pc=0x0c0aea36u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aea38;
P_0c0aea38: /* original 8807, guest PC 0x0c0aea38 */
if(!s->budget--) { s->failed_pc=0x0c0aea38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0aea3a;
P_0c0aea3a: /* original 8b02, guest PC 0x0c0aea3a */
if(!s->budget--) { s->failed_pc=0x0c0aea3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aea42; }
goto P_0c0aea3c;
P_0c0aea3c: /* original 62d2, guest PC 0x0c0aea3c */
if(!s->budget--) { s->failed_pc=0x0c0aea3cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aea3e;
P_0c0aea3e: /* original d32d, guest PC 0x0c0aea3e */
if(!s->budget--) { s->failed_pc=0x0c0aea3eu; return 0; }
r[3]=read(ram,0x0c0aeaf4u,4);
goto P_0c0aea40;
P_0c0aea40: /* original 2238, guest PC 0x0c0aea40 */
if(!s->budget--) { s->failed_pc=0x0c0aea40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aea42;
P_0c0aea42: /* original 51e2, guest PC 0x0c0aea42 */
if(!s->budget--) { s->failed_pc=0x0c0aea42u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0aea44;
P_0c0aea44: /* original 66e3, guest PC 0x0c0aea44 */
if(!s->budget--) { s->failed_pc=0x0c0aea44u; return 0; }
r[6]=r[14];
goto P_0c0aea46;
P_0c0aea46: /* original 7104, guest PC 0x0c0aea46 */
if(!s->budget--) { s->failed_pc=0x0c0aea46u; return 0; }
r[1]+=0x00000004u;
goto P_0c0aea48;
P_0c0aea48: /* original 1e12, guest PC 0x0c0aea48 */
if(!s->budget--) { s->failed_pc=0x0c0aea48u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c0aea4a;
P_0c0aea4a: /* original 65f2, guest PC 0x0c0aea4a */
if(!s->budget--) { s->failed_pc=0x0c0aea4au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aea4c;
P_0c0aea4c: /* original bc26, guest PC 0x0c0aea4c */
if(!s->budget--) { s->failed_pc=0x0c0aea4cu; return 0; }
target=0x0c0ae29cu; r[16]=0x0c0aea50u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aea50u) { target=s->pc; goto dispatch; }
goto P_0c0aea50;
P_0c0aea4e: /* original 64c3, guest PC 0x0c0aea4e */
if(!s->budget--) { s->failed_pc=0x0c0aea4eu; return 0; }
r[4]=r[12];
goto P_0c0aea50;
P_0c0aea50: /* original 7f24, guest PC 0x0c0aea50 */
if(!s->budget--) { s->failed_pc=0x0c0aea50u; return 0; }
r[15]+=0x00000024u;
goto P_0c0aea52;
P_0c0aea52: /* original 4f26, guest PC 0x0c0aea52 */
if(!s->budget--) { s->failed_pc=0x0c0aea52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aea54;
P_0c0aea54: /* original 6cf6, guest PC 0x0c0aea54 */
if(!s->budget--) { s->failed_pc=0x0c0aea54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aea56;
P_0c0aea56: /* original 6df6, guest PC 0x0c0aea56 */
if(!s->budget--) { s->failed_pc=0x0c0aea56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aea58;
P_0c0aea58: /* original 000b, guest PC 0x0c0aea58 */
if(!s->budget--) { s->failed_pc=0x0c0aea58u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aea5a: /* original 6ef6, guest PC 0x0c0aea5a */
if(!s->budget--) { s->failed_pc=0x0c0aea5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aea5cu,s,ram);
P_0c0aed4a: /* original 4f22, guest PC 0x0c0aed4a */
if(!s->budget--) { s->failed_pc=0x0c0aed4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aed4c;
P_0c0aed4c: /* original d558, guest PC 0x0c0aed4c */
if(!s->budget--) { s->failed_pc=0x0c0aed4cu; return 0; }
r[5]=read(ram,0x0c0aeeb0u,4);
goto P_0c0aed4e;
P_0c0aed4e: /* original 5341, guest PC 0x0c0aed4e */
if(!s->budget--) { s->failed_pc=0x0c0aed4eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0aed50;
P_0c0aed50: /* original 7fcc, guest PC 0x0c0aed50 */
if(!s->budget--) { s->failed_pc=0x0c0aed50u; return 0; }
r[15]+=0xffffffccu;
goto P_0c0aed52;
P_0c0aed52: /* original 2358, guest PC 0x0c0aed52 */
if(!s->budget--) { s->failed_pc=0x0c0aed52u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0aed54;
P_0c0aed54: /* original 8d02, guest PC 0x0c0aed54 */
if(!s->budget--) { s->failed_pc=0x0c0aed54u; return 0; }
cond=r[17]&1u;
r[12]=r[6];
if(cond) { goto P_0c0aed5c; }
goto P_0c0aed58;
P_0c0aed56: /* original 6c63, guest PC 0x0c0aed56 */
if(!s->budget--) { s->failed_pc=0x0c0aed56u; return 0; }
r[12]=r[6];
goto P_0c0aed58;
P_0c0aed58: /* original a166, guest PC 0x0c0aed58 */
if(!s->budget--) { s->failed_pc=0x0c0aed58u; return 0; }
goto P_0c0af028;
P_0c0aed5a: /* original 0009, guest PC 0x0c0aed5a */
if(!s->budget--) { s->failed_pc=0x0c0aed5au; return 0; }
goto P_0c0aed5c;
P_0c0aed5c: /* original 6242, guest PC 0x0c0aed5c */
if(!s->budget--) { s->failed_pc=0x0c0aed5cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0aed5e;
P_0c0aed5e: /* original 2528, guest PC 0x0c0aed5e */
if(!s->budget--) { s->failed_pc=0x0c0aed5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0aed60;
P_0c0aed60: /* original 8901, guest PC 0x0c0aed60 */
if(!s->budget--) { s->failed_pc=0x0c0aed60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aed66; }
goto P_0c0aed62;
P_0c0aed62: /* original a161, guest PC 0x0c0aed62 */
if(!s->budget--) { s->failed_pc=0x0c0aed62u; return 0; }
goto P_0c0af028;
P_0c0aed64: /* original 0009, guest PC 0x0c0aed64 */
if(!s->budget--) { s->failed_pc=0x0c0aed64u; return 0; }
goto P_0c0aed66;
P_0c0aed66: /* original 56c2, guest PC 0x0c0aed66 */
if(!s->budget--) { s->failed_pc=0x0c0aed66u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aed68;
P_0c0aed68: /* original 65f3, guest PC 0x0c0aed68 */
if(!s->budget--) { s->failed_pc=0x0c0aed68u; return 0; }
r[5]=r[15];
goto P_0c0aed6a;
P_0c0aed6a: /* original db53, guest PC 0x0c0aed6a */
if(!s->budget--) { s->failed_pc=0x0c0aed6au; return 0; }
r[11]=read(ram,0x0c0aeeb8u,4);
goto P_0c0aed6c;
P_0c0aed6c: /* original 7514, guest PC 0x0c0aed6c */
if(!s->budget--) { s->failed_pc=0x0c0aed6cu; return 0; }
r[5]+=0x00000014u;
goto P_0c0aed6e;
P_0c0aed6e: /* original 6363, guest PC 0x0c0aed6e */
if(!s->budget--) { s->failed_pc=0x0c0aed6eu; return 0; }
r[3]=r[6];
goto P_0c0aed70;
P_0c0aed70: /* original 7313, guest PC 0x0c0aed70 */
if(!s->budget--) { s->failed_pc=0x0c0aed70u; return 0; }
r[3]+=0x00000013u;
goto P_0c0aed72;
P_0c0aed72: /* original 6163, guest PC 0x0c0aed72 */
if(!s->budget--) { s->failed_pc=0x0c0aed72u; return 0; }
r[1]=r[6];
goto P_0c0aed74;
P_0c0aed74: /* original 7112, guest PC 0x0c0aed74 */
if(!s->budget--) { s->failed_pc=0x0c0aed74u; return 0; }
r[1]+=0x00000012u;
goto P_0c0aed76;
P_0c0aed76: /* original 6230, guest PC 0x0c0aed76 */
if(!s->budget--) { s->failed_pc=0x0c0aed76u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0aed78;
P_0c0aed78: /* original 6453, guest PC 0x0c0aed78 */
if(!s->budget--) { s->failed_pc=0x0c0aed78u; return 0; }
r[4]=r[5];
goto P_0c0aed7a;
P_0c0aed7a: /* original 6010, guest PC 0x0c0aed7a */
if(!s->budget--) { s->failed_pc=0x0c0aed7au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aed7c;
P_0c0aed7c: /* original 6163, guest PC 0x0c0aed7c */
if(!s->budget--) { s->failed_pc=0x0c0aed7cu; return 0; }
r[1]=r[6];
goto P_0c0aed7e;
P_0c0aed7e: /* original 622c, guest PC 0x0c0aed7e */
if(!s->budget--) { s->failed_pc=0x0c0aed7eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0aed80;
P_0c0aed80: /* original d34e, guest PC 0x0c0aed80 */
if(!s->budget--) { s->failed_pc=0x0c0aed80u; return 0; }
r[3]=read(ram,0x0c0aeebcu,4);
goto P_0c0aed82;
P_0c0aed82: /* original 4228, guest PC 0x0c0aed82 */
if(!s->budget--) { s->failed_pc=0x0c0aed82u; return 0; }
r[2]<<=16;
goto P_0c0aed84;
P_0c0aed84: /* original d94b, guest PC 0x0c0aed84 */
if(!s->budget--) { s->failed_pc=0x0c0aed84u; return 0; }
r[9]=read(ram,0x0c0aeeb4u,4);
goto P_0c0aed86;
P_0c0aed86: /* original 600c, guest PC 0x0c0aed86 */
if(!s->budget--) { s->failed_pc=0x0c0aed86u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aed88;
P_0c0aed88: /* original 4028, guest PC 0x0c0aed88 */
if(!s->budget--) { s->failed_pc=0x0c0aed88u; return 0; }
r[0]<<=16;
goto P_0c0aed8a;
P_0c0aed8a: /* original 4218, guest PC 0x0c0aed8a */
if(!s->budget--) { s->failed_pc=0x0c0aed8au; return 0; }
r[2]<<=8;
goto P_0c0aed8c;
P_0c0aed8c: /* original 20b9, guest PC 0x0c0aed8c */
if(!s->budget--) { s->failed_pc=0x0c0aed8cu; return 0; }
r[0]&=r[11];
goto P_0c0aed8e;
P_0c0aed8e: /* original 2239, guest PC 0x0c0aed8e */
if(!s->budget--) { s->failed_pc=0x0c0aed8eu; return 0; }
r[2]&=r[3];
goto P_0c0aed90;
P_0c0aed90: /* original 220b, guest PC 0x0c0aed90 */
if(!s->budget--) { s->failed_pc=0x0c0aed90u; return 0; }
r[2]|=r[0];
goto P_0c0aed92;
P_0c0aed92: /* original 7111, guest PC 0x0c0aed92 */
if(!s->budget--) { s->failed_pc=0x0c0aed92u; return 0; }
r[1]+=0x00000011u;
goto P_0c0aed94;
P_0c0aed94: /* original 6010, guest PC 0x0c0aed94 */
if(!s->budget--) { s->failed_pc=0x0c0aed94u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aed96;
P_0c0aed96: /* original 6163, guest PC 0x0c0aed96 */
if(!s->budget--) { s->failed_pc=0x0c0aed96u; return 0; }
r[1]=r[6];
goto P_0c0aed98;
P_0c0aed98: /* original 7110, guest PC 0x0c0aed98 */
if(!s->budget--) { s->failed_pc=0x0c0aed98u; return 0; }
r[1]+=0x00000010u;
goto P_0c0aed9a;
P_0c0aed9a: /* original 600c, guest PC 0x0c0aed9a */
if(!s->budget--) { s->failed_pc=0x0c0aed9au; return 0; }
r[0]=r[0]&255u;
goto P_0c0aed9c;
P_0c0aed9c: /* original 4018, guest PC 0x0c0aed9c */
if(!s->budget--) { s->failed_pc=0x0c0aed9cu; return 0; }
r[0]<<=8;
goto P_0c0aed9e;
P_0c0aed9e: /* original 2099, guest PC 0x0c0aed9e */
if(!s->budget--) { s->failed_pc=0x0c0aed9eu; return 0; }
r[0]&=r[9];
goto P_0c0aeda0;
P_0c0aeda0: /* original 220b, guest PC 0x0c0aeda0 */
if(!s->budget--) { s->failed_pc=0x0c0aeda0u; return 0; }
r[2]|=r[0];
goto P_0c0aeda2;
P_0c0aeda2: /* original 6010, guest PC 0x0c0aeda2 */
if(!s->budget--) { s->failed_pc=0x0c0aeda2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aeda4;
P_0c0aeda4: /* original 600c, guest PC 0x0c0aeda4 */
if(!s->budget--) { s->failed_pc=0x0c0aeda4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeda6;
P_0c0aeda6: /* original 220b, guest PC 0x0c0aeda6 */
if(!s->budget--) { s->failed_pc=0x0c0aeda6u; return 0; }
r[2]|=r[0];
goto P_0c0aeda8;
P_0c0aeda8: /* original 2422, guest PC 0x0c0aeda8 */
if(!s->budget--) { s->failed_pc=0x0c0aeda8u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0aedaa;
P_0c0aedaa: /* original 56c2, guest PC 0x0c0aedaa */
if(!s->budget--) { s->failed_pc=0x0c0aedaau; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aedac;
P_0c0aedac: /* original 6263, guest PC 0x0c0aedac */
if(!s->budget--) { s->failed_pc=0x0c0aedacu; return 0; }
r[2]=r[6];
goto P_0c0aedae;
P_0c0aedae: /* original 7217, guest PC 0x0c0aedae */
if(!s->budget--) { s->failed_pc=0x0c0aedaeu; return 0; }
r[2]+=0x00000017u;
goto P_0c0aedb0;
P_0c0aedb0: /* original 6120, guest PC 0x0c0aedb0 */
if(!s->budget--) { s->failed_pc=0x0c0aedb0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0aedb2;
P_0c0aedb2: /* original 6263, guest PC 0x0c0aedb2 */
if(!s->budget--) { s->failed_pc=0x0c0aedb2u; return 0; }
r[2]=r[6];
goto P_0c0aedb4;
P_0c0aedb4: /* original 7216, guest PC 0x0c0aedb4 */
if(!s->budget--) { s->failed_pc=0x0c0aedb4u; return 0; }
r[2]+=0x00000016u;
goto P_0c0aedb6;
P_0c0aedb6: /* original 6020, guest PC 0x0c0aedb6 */
if(!s->budget--) { s->failed_pc=0x0c0aedb6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aedb8;
P_0c0aedb8: /* original 611c, guest PC 0x0c0aedb8 */
if(!s->budget--) { s->failed_pc=0x0c0aedb8u; return 0; }
r[1]=r[1]&255u;
goto P_0c0aedba;
P_0c0aedba: /* original 4128, guest PC 0x0c0aedba */
if(!s->budget--) { s->failed_pc=0x0c0aedbau; return 0; }
r[1]<<=16;
goto P_0c0aedbc;
P_0c0aedbc: /* original 6263, guest PC 0x0c0aedbc */
if(!s->budget--) { s->failed_pc=0x0c0aedbcu; return 0; }
r[2]=r[6];
goto P_0c0aedbe;
P_0c0aedbe: /* original 600c, guest PC 0x0c0aedbe */
if(!s->budget--) { s->failed_pc=0x0c0aedbeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedc0;
P_0c0aedc0: /* original 4028, guest PC 0x0c0aedc0 */
if(!s->budget--) { s->failed_pc=0x0c0aedc0u; return 0; }
r[0]<<=16;
goto P_0c0aedc2;
P_0c0aedc2: /* original 4118, guest PC 0x0c0aedc2 */
if(!s->budget--) { s->failed_pc=0x0c0aedc2u; return 0; }
r[1]<<=8;
goto P_0c0aedc4;
P_0c0aedc4: /* original 20b9, guest PC 0x0c0aedc4 */
if(!s->budget--) { s->failed_pc=0x0c0aedc4u; return 0; }
r[0]&=r[11];
goto P_0c0aedc6;
P_0c0aedc6: /* original 2139, guest PC 0x0c0aedc6 */
if(!s->budget--) { s->failed_pc=0x0c0aedc6u; return 0; }
r[1]&=r[3];
goto P_0c0aedc8;
P_0c0aedc8: /* original 7215, guest PC 0x0c0aedc8 */
if(!s->budget--) { s->failed_pc=0x0c0aedc8u; return 0; }
r[2]+=0x00000015u;
goto P_0c0aedca;
P_0c0aedca: /* original 210b, guest PC 0x0c0aedca */
if(!s->budget--) { s->failed_pc=0x0c0aedcau; return 0; }
r[1]|=r[0];
goto P_0c0aedcc;
P_0c0aedcc: /* original 6020, guest PC 0x0c0aedcc */
if(!s->budget--) { s->failed_pc=0x0c0aedccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aedce;
P_0c0aedce: /* original 6263, guest PC 0x0c0aedce */
if(!s->budget--) { s->failed_pc=0x0c0aedceu; return 0; }
r[2]=r[6];
goto P_0c0aedd0;
P_0c0aedd0: /* original 7214, guest PC 0x0c0aedd0 */
if(!s->budget--) { s->failed_pc=0x0c0aedd0u; return 0; }
r[2]+=0x00000014u;
goto P_0c0aedd2;
P_0c0aedd2: /* original 600c, guest PC 0x0c0aedd2 */
if(!s->budget--) { s->failed_pc=0x0c0aedd2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedd4;
P_0c0aedd4: /* original 4018, guest PC 0x0c0aedd4 */
if(!s->budget--) { s->failed_pc=0x0c0aedd4u; return 0; }
r[0]<<=8;
goto P_0c0aedd6;
P_0c0aedd6: /* original 2099, guest PC 0x0c0aedd6 */
if(!s->budget--) { s->failed_pc=0x0c0aedd6u; return 0; }
r[0]&=r[9];
goto P_0c0aedd8;
P_0c0aedd8: /* original 210b, guest PC 0x0c0aedd8 */
if(!s->budget--) { s->failed_pc=0x0c0aedd8u; return 0; }
r[1]|=r[0];
goto P_0c0aedda;
P_0c0aedda: /* original 6020, guest PC 0x0c0aedda */
if(!s->budget--) { s->failed_pc=0x0c0aeddau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0aeddc;
P_0c0aeddc: /* original 600c, guest PC 0x0c0aeddc */
if(!s->budget--) { s->failed_pc=0x0c0aeddcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedde;
P_0c0aedde: /* original 210b, guest PC 0x0c0aedde */
if(!s->budget--) { s->failed_pc=0x0c0aeddeu; return 0; }
r[1]|=r[0];
goto P_0c0aede0;
P_0c0aede0: /* original 1411, guest PC 0x0c0aede0 */
if(!s->budget--) { s->failed_pc=0x0c0aede0u; return 0; }
write(ram,r[4]+4,r[1],4);
goto P_0c0aede2;
P_0c0aede2: /* original 56c2, guest PC 0x0c0aede2 */
if(!s->budget--) { s->failed_pc=0x0c0aede2u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aede4;
P_0c0aede4: /* original 846b, guest PC 0x0c0aede4 */
if(!s->budget--) { s->failed_pc=0x0c0aede4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0aede6;
P_0c0aede6: /* original 600c, guest PC 0x0c0aede6 */
if(!s->budget--) { s->failed_pc=0x0c0aede6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aede8;
P_0c0aede8: /* original 4028, guest PC 0x0c0aede8 */
if(!s->budget--) { s->failed_pc=0x0c0aede8u; return 0; }
r[0]<<=16;
goto P_0c0aedea;
P_0c0aedea: /* original 4018, guest PC 0x0c0aedea */
if(!s->budget--) { s->failed_pc=0x0c0aedeau; return 0; }
r[0]<<=8;
goto P_0c0aedec;
P_0c0aedec: /* original 2039, guest PC 0x0c0aedec */
if(!s->budget--) { s->failed_pc=0x0c0aedecu; return 0; }
r[0]&=r[3];
goto P_0c0aedee;
P_0c0aedee: /* original 6203, guest PC 0x0c0aedee */
if(!s->budget--) { s->failed_pc=0x0c0aedeeu; return 0; }
r[2]=r[0];
goto P_0c0aedf0;
P_0c0aedf0: /* original 846a, guest PC 0x0c0aedf0 */
if(!s->budget--) { s->failed_pc=0x0c0aedf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0aedf2;
P_0c0aedf2: /* original 600c, guest PC 0x0c0aedf2 */
if(!s->budget--) { s->failed_pc=0x0c0aedf2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedf4;
P_0c0aedf4: /* original 4028, guest PC 0x0c0aedf4 */
if(!s->budget--) { s->failed_pc=0x0c0aedf4u; return 0; }
r[0]<<=16;
goto P_0c0aedf6;
P_0c0aedf6: /* original 20b9, guest PC 0x0c0aedf6 */
if(!s->budget--) { s->failed_pc=0x0c0aedf6u; return 0; }
r[0]&=r[11];
goto P_0c0aedf8;
P_0c0aedf8: /* original 220b, guest PC 0x0c0aedf8 */
if(!s->budget--) { s->failed_pc=0x0c0aedf8u; return 0; }
r[2]|=r[0];
goto P_0c0aedfa;
P_0c0aedfa: /* original 8469, guest PC 0x0c0aedfa */
if(!s->budget--) { s->failed_pc=0x0c0aedfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0aedfc;
P_0c0aedfc: /* original 600c, guest PC 0x0c0aedfc */
if(!s->budget--) { s->failed_pc=0x0c0aedfcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aedfe;
P_0c0aedfe: /* original 4018, guest PC 0x0c0aedfe */
if(!s->budget--) { s->failed_pc=0x0c0aedfeu; return 0; }
r[0]<<=8;
goto P_0c0aee00;
P_0c0aee00: /* original 2099, guest PC 0x0c0aee00 */
if(!s->budget--) { s->failed_pc=0x0c0aee00u; return 0; }
r[0]&=r[9];
goto P_0c0aee02;
P_0c0aee02: /* original 220b, guest PC 0x0c0aee02 */
if(!s->budget--) { s->failed_pc=0x0c0aee02u; return 0; }
r[2]|=r[0];
goto P_0c0aee04;
P_0c0aee04: /* original 8468, guest PC 0x0c0aee04 */
if(!s->budget--) { s->failed_pc=0x0c0aee04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0aee06;
P_0c0aee06: /* original 600c, guest PC 0x0c0aee06 */
if(!s->budget--) { s->failed_pc=0x0c0aee06u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee08;
P_0c0aee08: /* original 220b, guest PC 0x0c0aee08 */
if(!s->budget--) { s->failed_pc=0x0c0aee08u; return 0; }
r[2]|=r[0];
goto P_0c0aee0a;
P_0c0aee0a: /* original 1422, guest PC 0x0c0aee0a */
if(!s->budget--) { s->failed_pc=0x0c0aee0au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0aee0c;
P_0c0aee0c: /* original 56c2, guest PC 0x0c0aee0c */
if(!s->budget--) { s->failed_pc=0x0c0aee0cu; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c0aee0e;
P_0c0aee0e: /* original 846f, guest PC 0x0c0aee0e */
if(!s->budget--) { s->failed_pc=0x0c0aee0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+15,1);
goto P_0c0aee10;
P_0c0aee10: /* original 600c, guest PC 0x0c0aee10 */
if(!s->budget--) { s->failed_pc=0x0c0aee10u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee12;
P_0c0aee12: /* original 4028, guest PC 0x0c0aee12 */
if(!s->budget--) { s->failed_pc=0x0c0aee12u; return 0; }
r[0]<<=16;
goto P_0c0aee14;
P_0c0aee14: /* original 4018, guest PC 0x0c0aee14 */
if(!s->budget--) { s->failed_pc=0x0c0aee14u; return 0; }
r[0]<<=8;
goto P_0c0aee16;
P_0c0aee16: /* original 2039, guest PC 0x0c0aee16 */
if(!s->budget--) { s->failed_pc=0x0c0aee16u; return 0; }
r[0]&=r[3];
goto P_0c0aee18;
P_0c0aee18: /* original 6203, guest PC 0x0c0aee18 */
if(!s->budget--) { s->failed_pc=0x0c0aee18u; return 0; }
r[2]=r[0];
goto P_0c0aee1a;
P_0c0aee1a: /* original 846e, guest PC 0x0c0aee1a */
if(!s->budget--) { s->failed_pc=0x0c0aee1au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0aee1c;
P_0c0aee1c: /* original 600c, guest PC 0x0c0aee1c */
if(!s->budget--) { s->failed_pc=0x0c0aee1cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee1e;
P_0c0aee1e: /* original 4028, guest PC 0x0c0aee1e */
if(!s->budget--) { s->failed_pc=0x0c0aee1eu; return 0; }
r[0]<<=16;
goto P_0c0aee20;
P_0c0aee20: /* original 20b9, guest PC 0x0c0aee20 */
if(!s->budget--) { s->failed_pc=0x0c0aee20u; return 0; }
r[0]&=r[11];
goto P_0c0aee22;
P_0c0aee22: /* original 220b, guest PC 0x0c0aee22 */
if(!s->budget--) { s->failed_pc=0x0c0aee22u; return 0; }
r[2]|=r[0];
goto P_0c0aee24;
P_0c0aee24: /* original 846d, guest PC 0x0c0aee24 */
if(!s->budget--) { s->failed_pc=0x0c0aee24u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0aee26;
P_0c0aee26: /* original 600c, guest PC 0x0c0aee26 */
if(!s->budget--) { s->failed_pc=0x0c0aee26u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee28;
P_0c0aee28: /* original 4018, guest PC 0x0c0aee28 */
if(!s->budget--) { s->failed_pc=0x0c0aee28u; return 0; }
r[0]<<=8;
goto P_0c0aee2a;
P_0c0aee2a: /* original 2099, guest PC 0x0c0aee2a */
if(!s->budget--) { s->failed_pc=0x0c0aee2au; return 0; }
r[0]&=r[9];
goto P_0c0aee2c;
P_0c0aee2c: /* original 220b, guest PC 0x0c0aee2c */
if(!s->budget--) { s->failed_pc=0x0c0aee2cu; return 0; }
r[2]|=r[0];
goto P_0c0aee2e;
P_0c0aee2e: /* original 846c, guest PC 0x0c0aee2e */
if(!s->budget--) { s->failed_pc=0x0c0aee2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0aee30;
P_0c0aee30: /* original e310, guest PC 0x0c0aee30 */
if(!s->budget--) { s->failed_pc=0x0c0aee30u; return 0; }
r[3]=0x00000010u;
goto P_0c0aee32;
P_0c0aee32: /* original 600c, guest PC 0x0c0aee32 */
if(!s->budget--) { s->failed_pc=0x0c0aee32u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aee34;
P_0c0aee34: /* original 220b, guest PC 0x0c0aee34 */
if(!s->budget--) { s->failed_pc=0x0c0aee34u; return 0; }
r[2]|=r[0];
goto P_0c0aee36;
P_0c0aee36: /* original 1423, guest PC 0x0c0aee36 */
if(!s->budget--) { s->failed_pc=0x0c0aee36u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0aee38;
P_0c0aee38: /* original e008, guest PC 0x0c0aee38 */
if(!s->budget--) { s->failed_pc=0x0c0aee38u; return 0; }
r[0]=0x00000008u;
goto P_0c0aee3a;
P_0c0aee3a: /* original 54c2, guest PC 0x0c0aee3a */
if(!s->budget--) { s->failed_pc=0x0c0aee3au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aee3c;
P_0c0aee3c: /* original f656, guest PC 0x0c0aee3c */
if(!s->budget--) { s->failed_pc=0x0c0aee3cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0aee3e;
P_0c0aee3e: /* original e00c, guest PC 0x0c0aee3e */
if(!s->budget--) { s->failed_pc=0x0c0aee3eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0aee40;
P_0c0aee40: /* original 7407, guest PC 0x0c0aee40 */
if(!s->budget--) { s->failed_pc=0x0c0aee40u; return 0; }
r[4]+=0x00000007u;
goto P_0c0aee42;
P_0c0aee42: /* original 61e2, guest PC 0x0c0aee42 */
if(!s->budget--) { s->failed_pc=0x0c0aee42u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0aee44;
P_0c0aee44: /* original 6440, guest PC 0x0c0aee44 */
if(!s->budget--) { s->failed_pc=0x0c0aee44u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aee46;
P_0c0aee46: /* original d21e, guest PC 0x0c0aee46 */
if(!s->budget--) { s->failed_pc=0x0c0aee46u; return 0; }
r[2]=read(ram,0x0c0aeec0u,4);
goto P_0c0aee48;
P_0c0aee48: /* original f556, guest PC 0x0c0aee48 */
if(!s->budget--) { s->failed_pc=0x0c0aee48u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0aee4a;
P_0c0aee4a: /* original 644c, guest PC 0x0c0aee4a */
if(!s->budget--) { s->failed_pc=0x0c0aee4au; return 0; }
r[4]=r[4]&255u;
goto P_0c0aee4c;
P_0c0aee4c: /* original 2128, guest PC 0x0c0aee4c */
if(!s->budget--) { s->failed_pc=0x0c0aee4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aee4e;
P_0c0aee4e: /* original 85ef, guest PC 0x0c0aee4e */
if(!s->budget--) { s->failed_pc=0x0c0aee4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0aee50;
P_0c0aee50: /* original 2349, guest PC 0x0c0aee50 */
if(!s->budget--) { s->failed_pc=0x0c0aee50u; return 0; }
r[3]&=r[4];
goto P_0c0aee52;
P_0c0aee52: /* original da1c, guest PC 0x0c0aee52 */
if(!s->budget--) { s->failed_pc=0x0c0aee52u; return 0; }
r[10]=read(ram,0x0c0aeec4u,4);
goto P_0c0aee54;
P_0c0aee54: /* original e202, guest PC 0x0c0aee54 */
if(!s->budget--) { s->failed_pc=0x0c0aee54u; return 0; }
r[2]=0x00000002u;
goto P_0c0aee56;
P_0c0aee56: /* original ff9d, guest PC 0x0c0aee56 */
if(!s->budget--) { s->failed_pc=0x0c0aee56u; return 0; }
fr[15]=0x3f800000u;
goto P_0c0aee58;
P_0c0aee58: /* original 2248, guest PC 0x0c0aee58 */
if(!s->budget--) { s->failed_pc=0x0c0aee58u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0aee5a;
P_0c0aee5a: /* original 6503, guest PC 0x0c0aee5a */
if(!s->budget--) { s->failed_pc=0x0c0aee5au; return 0; }
r[5]=r[0];
goto P_0c0aee5c;
P_0c0aee5c: /* original 1f33, guest PC 0x0c0aee5c */
if(!s->budget--) { s->failed_pc=0x0c0aee5cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0aee5e;
P_0c0aee5e: /* original 8f35, guest PC 0x0c0aee5e */
if(!s->budget--) { s->failed_pc=0x0c0aee5eu; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)r[5];
if(!cond) { goto P_0c0aeecc; }
goto P_0c0aee62;
P_0c0aee60: /* original 6d5f, guest PC 0x0c0aee60 */
if(!s->budget--) { s->failed_pc=0x0c0aee60u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0aee62;
P_0c0aee62: /* original e304, guest PC 0x0c0aee62 */
if(!s->budget--) { s->failed_pc=0x0c0aee62u; return 0; }
r[3]=0x00000004u;
goto P_0c0aee64;
P_0c0aee64: /* original 2438, guest PC 0x0c0aee64 */
if(!s->budget--) { s->failed_pc=0x0c0aee64u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0aee66;
P_0c0aee66: /* original 8b31, guest PC 0x0c0aee66 */
if(!s->budget--) { s->failed_pc=0x0c0aee66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeecc; }
goto P_0c0aee68;
P_0c0aee68: /* original e05c, guest PC 0x0c0aee68 */
if(!s->budget--) { s->failed_pc=0x0c0aee68u; return 0; }
r[0]=0x0000005cu;
goto P_0c0aee6a;
P_0c0aee6a: /* original f38d, guest PC 0x0c0aee6a */
if(!s->budget--) { s->failed_pc=0x0c0aee6au; return 0; }
fr[3]=0;
goto P_0c0aee6c;
P_0c0aee6c: /* original f4e6, guest PC 0x0c0aee6c */
if(!s->budget--) { s->failed_pc=0x0c0aee6cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aee6e;
P_0c0aee6e: /* original f434, guest PC 0x0c0aee6e */
if(!s->budget--) { s->failed_pc=0x0c0aee6eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c0aee70;
P_0c0aee70: /* original 8b01, guest PC 0x0c0aee70 */
if(!s->budget--) { s->failed_pc=0x0c0aee70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aee76; }
goto P_0c0aee72;
P_0c0aee72: /* original a0d9, guest PC 0x0c0aee72 */
if(!s->budget--) { s->failed_pc=0x0c0aee72u; return 0; }
goto P_0c0af028;
P_0c0aee74: /* original 0009, guest PC 0x0c0aee74 */
if(!s->budget--) { s->failed_pc=0x0c0aee74u; return 0; }
goto P_0c0aee76;
P_0c0aee76: /* original 53f3, guest PC 0x0c0aee76 */
if(!s->budget--) { s->failed_pc=0x0c0aee76u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0aee78;
P_0c0aee78: /* original 2338, guest PC 0x0c0aee78 */
if(!s->budget--) { s->failed_pc=0x0c0aee78u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0aee7a;
P_0c0aee7a: /* original 8900, guest PC 0x0c0aee7a */
if(!s->budget--) { s->failed_pc=0x0c0aee7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aee7e; }
goto P_0c0aee7c;
P_0c0aee7c: /* original f44d, guest PC 0x0c0aee7c */
if(!s->budget--) { s->failed_pc=0x0c0aee7cu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0aee7e;
P_0c0aee7e: /* original f455, guest PC 0x0c0aee7e */
if(!s->budget--) { s->failed_pc=0x0c0aee7eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0aee80;
P_0c0aee80: /* original 8d01, guest PC 0x0c0aee80 */
if(!s->budget--) { s->failed_pc=0x0c0aee80u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c0aee86; }
goto P_0c0aee84;
P_0c0aee82: /* original 64d3, guest PC 0x0c0aee82 */
if(!s->budget--) { s->failed_pc=0x0c0aee82u; return 0; }
r[4]=r[13];
goto P_0c0aee84;
P_0c0aee84: /* original f465, guest PC 0x0c0aee84 */
if(!s->budget--) { s->failed_pc=0x0c0aee84u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0aee86;
P_0c0aee86: /* original d210, guest PC 0x0c0aee86 */
if(!s->budget--) { s->failed_pc=0x0c0aee86u; return 0; }
r[2]=read(ram,0x0c0aeec8u,4);
goto P_0c0aee88;
P_0c0aee88: /* original 420b, guest PC 0x0c0aee88 */
if(!s->budget--) { s->failed_pc=0x0c0aee88u; return 0; }
target=r[2];
r[16]=0x0c0aee8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aee8cu) { target=s->pc; goto dispatch; }
goto P_0c0aee8c;
P_0c0aee8a: /* original 0009, guest PC 0x0c0aee8a */
if(!s->budget--) { s->failed_pc=0x0c0aee8au; return 0; }
goto P_0c0aee8c;
P_0c0aee8c: /* original ff0a, guest PC 0x0c0aee8c */
if(!s->budget--) { s->failed_pc=0x0c0aee8cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aee8e;
P_0c0aee8e: /* original 4a0b, guest PC 0x0c0aee8e */
if(!s->budget--) { s->failed_pc=0x0c0aee8eu; return 0; }
target=r[10];
r[16]=0x0c0aee92u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aee92u) { target=s->pc; goto dispatch; }
goto P_0c0aee92;
P_0c0aee90: /* original 64d3, guest PC 0x0c0aee90 */
if(!s->budget--) { s->failed_pc=0x0c0aee90u; return 0; }
r[4]=r[13];
goto P_0c0aee92;
P_0c0aee92: /* original f0f2, guest PC 0x0c0aee92 */
if(!s->budget--) { s->failed_pc=0x0c0aee92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aee94;
P_0c0aee94: /* original f04d, guest PC 0x0c0aee94 */
if(!s->budget--) { s->failed_pc=0x0c0aee94u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aee96;
P_0c0aee96: /* original ff0a, guest PC 0x0c0aee96 */
if(!s->budget--) { s->failed_pc=0x0c0aee96u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aee98;
P_0c0aee98: /* original 4a0b, guest PC 0x0c0aee98 */
if(!s->budget--) { s->failed_pc=0x0c0aee98u; return 0; }
target=r[10];
r[16]=0x0c0aee9cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aee9cu) { target=s->pc; goto dispatch; }
goto P_0c0aee9c;
P_0c0aee9a: /* original 64d3, guest PC 0x0c0aee9a */
if(!s->budget--) { s->failed_pc=0x0c0aee9au; return 0; }
r[4]=r[13];
goto P_0c0aee9c;
P_0c0aee9c: /* original f0f2, guest PC 0x0c0aee9c */
if(!s->budget--) { s->failed_pc=0x0c0aee9cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aee9e;
P_0c0aee9e: /* original f04d, guest PC 0x0c0aee9e */
if(!s->budget--) { s->failed_pc=0x0c0aee9eu; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeea0;
P_0c0aeea0: /* original ff0a, guest PC 0x0c0aeea0 */
if(!s->budget--) { s->failed_pc=0x0c0aeea0u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeea2;
P_0c0aeea2: /* original d309, guest PC 0x0c0aeea2 */
if(!s->budget--) { s->failed_pc=0x0c0aeea2u; return 0; }
r[3]=read(ram,0x0c0aeec8u,4);
goto P_0c0aeea4;
P_0c0aeea4: /* original 430b, guest PC 0x0c0aeea4 */
if(!s->budget--) { s->failed_pc=0x0c0aeea4u; return 0; }
target=r[3];
r[16]=0x0c0aeea8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeea8u) { target=s->pc; goto dispatch; }
goto P_0c0aeea8;
P_0c0aeea6: /* original 64d3, guest PC 0x0c0aeea6 */
if(!s->budget--) { s->failed_pc=0x0c0aeea6u; return 0; }
r[4]=r[13];
goto P_0c0aeea8;
P_0c0aeea8: /* original a05d, guest PC 0x0c0aeea8 */
if(!s->budget--) { s->failed_pc=0x0c0aeea8u; return 0; }
goto P_0c0aef66;
P_0c0aeeaa: /* original 0009, guest PC 0x0c0aeeaa */
if(!s->budget--) { s->failed_pc=0x0c0aeeaau; return 0; }
return vf3_matrix_family(0x0c0aeeacu,s,ram);
P_0c0aeecc: /* original 52f3, guest PC 0x0c0aeecc */
if(!s->budget--) { s->failed_pc=0x0c0aeeccu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0aeece;
P_0c0aeece: /* original 2228, guest PC 0x0c0aeece */
if(!s->budget--) { s->failed_pc=0x0c0aeeceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aeed0;
P_0c0aeed0: /* original 8f04, guest PC 0x0c0aeed0 */
if(!s->budget--) { s->failed_pc=0x0c0aeed0u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(!cond) { goto P_0c0aeedc; }
goto P_0c0aeed4;
P_0c0aeed2: /* original 64d3, guest PC 0x0c0aeed2 */
if(!s->budget--) { s->failed_pc=0x0c0aeed2u; return 0; }
r[4]=r[13];
goto P_0c0aeed4;
P_0c0aeed4: /* original 90ba, guest PC 0x0c0aeed4 */
if(!s->budget--) { s->failed_pc=0x0c0aeed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04cu,2);
goto P_0c0aeed6;
P_0c0aeed6: /* original e200, guest PC 0x0c0aeed6 */
if(!s->budget--) { s->failed_pc=0x0c0aeed6u; return 0; }
r[2]=0x00000000u;
goto P_0c0aeed8;
P_0c0aeed8: /* original a003, guest PC 0x0c0aeed8 */
if(!s->budget--) { s->failed_pc=0x0c0aeed8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aeee2;
P_0c0aeeda: /* original 0e24, guest PC 0x0c0aeeda */
if(!s->budget--) { s->failed_pc=0x0c0aeedau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aeedc;
P_0c0aeedc: /* original 90b6, guest PC 0x0c0aeedc */
if(!s->budget--) { s->failed_pc=0x0c0aeedcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04cu,2);
goto P_0c0aeede;
P_0c0aeede: /* original e101, guest PC 0x0c0aeede */
if(!s->budget--) { s->failed_pc=0x0c0aeedeu; return 0; }
r[1]=0x00000001u;
goto P_0c0aeee0;
P_0c0aeee0: /* original 0e14, guest PC 0x0c0aeee0 */
if(!s->budget--) { s->failed_pc=0x0c0aeee0u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0aeee2;
P_0c0aeee2: /* original d35b, guest PC 0x0c0aeee2 */
if(!s->budget--) { s->failed_pc=0x0c0aeee2u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aeee4;
P_0c0aeee4: /* original 430b, guest PC 0x0c0aeee4 */
if(!s->budget--) { s->failed_pc=0x0c0aeee4u; return 0; }
target=r[3];
r[16]=0x0c0aeee8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeee8u) { target=s->pc; goto dispatch; }
goto P_0c0aeee8;
P_0c0aeee6: /* original 0009, guest PC 0x0c0aeee6 */
if(!s->budget--) { s->failed_pc=0x0c0aeee6u; return 0; }
goto P_0c0aeee8;
P_0c0aeee8: /* original ff0a, guest PC 0x0c0aeee8 */
if(!s->budget--) { s->failed_pc=0x0c0aeee8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeeea;
P_0c0aeeea: /* original 4a0b, guest PC 0x0c0aeeea */
if(!s->budget--) { s->failed_pc=0x0c0aeeeau; return 0; }
target=r[10];
r[16]=0x0c0aeeeeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeeeeu) { target=s->pc; goto dispatch; }
goto P_0c0aeeee;
P_0c0aeeec: /* original 64d3, guest PC 0x0c0aeeec */
if(!s->budget--) { s->failed_pc=0x0c0aeeecu; return 0; }
r[4]=r[13];
goto P_0c0aeeee;
P_0c0aeeee: /* original f0f2, guest PC 0x0c0aeeee */
if(!s->budget--) { s->failed_pc=0x0c0aeeeeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aeef0;
P_0c0aeef0: /* original f04d, guest PC 0x0c0aeef0 */
if(!s->budget--) { s->failed_pc=0x0c0aeef0u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeef2;
P_0c0aeef2: /* original ff0a, guest PC 0x0c0aeef2 */
if(!s->budget--) { s->failed_pc=0x0c0aeef2u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeef4;
P_0c0aeef4: /* original 4a0b, guest PC 0x0c0aeef4 */
if(!s->budget--) { s->failed_pc=0x0c0aeef4u; return 0; }
target=r[10];
r[16]=0x0c0aeef8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeef8u) { target=s->pc; goto dispatch; }
goto P_0c0aeef8;
P_0c0aeef6: /* original 64d3, guest PC 0x0c0aeef6 */
if(!s->budget--) { s->failed_pc=0x0c0aeef6u; return 0; }
r[4]=r[13];
goto P_0c0aeef8;
P_0c0aeef8: /* original f0f2, guest PC 0x0c0aeef8 */
if(!s->budget--) { s->failed_pc=0x0c0aeef8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aeefa;
P_0c0aeefa: /* original f04d, guest PC 0x0c0aeefa */
if(!s->budget--) { s->failed_pc=0x0c0aeefau; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aeefc;
P_0c0aeefc: /* original ff0a, guest PC 0x0c0aeefc */
if(!s->budget--) { s->failed_pc=0x0c0aeefcu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aeefe;
P_0c0aeefe: /* original d354, guest PC 0x0c0aeefe */
if(!s->budget--) { s->failed_pc=0x0c0aeefeu; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef00;
P_0c0aef00: /* original 430b, guest PC 0x0c0aef00 */
if(!s->budget--) { s->failed_pc=0x0c0aef00u; return 0; }
target=r[3];
r[16]=0x0c0aef04u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef04u) { target=s->pc; goto dispatch; }
goto P_0c0aef04;
P_0c0aef02: /* original 64d3, guest PC 0x0c0aef02 */
if(!s->budget--) { s->failed_pc=0x0c0aef02u; return 0; }
r[4]=r[13];
goto P_0c0aef04;
P_0c0aef04: /* original 65f3, guest PC 0x0c0aef04 */
if(!s->budget--) { s->failed_pc=0x0c0aef04u; return 0; }
r[5]=r[15];
goto P_0c0aef06;
P_0c0aef06: /* original 752c, guest PC 0x0c0aef06 */
if(!s->budget--) { s->failed_pc=0x0c0aef06u; return 0; }
r[5]+=0x0000002cu;
goto P_0c0aef08;
P_0c0aef08: /* original ff0a, guest PC 0x0c0aef08 */
if(!s->budget--) { s->failed_pc=0x0c0aef08u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef0a;
P_0c0aef0a: /* original 54c2, guest PC 0x0c0aef0a */
if(!s->budget--) { s->failed_pc=0x0c0aef0au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aef0c;
P_0c0aef0c: /* original 6343, guest PC 0x0c0aef0c */
if(!s->budget--) { s->failed_pc=0x0c0aef0cu; return 0; }
r[3]=r[4];
goto P_0c0aef0e;
P_0c0aef0e: /* original 731b, guest PC 0x0c0aef0e */
if(!s->budget--) { s->failed_pc=0x0c0aef0eu; return 0; }
r[3]+=0x0000001bu;
goto P_0c0aef10;
P_0c0aef10: /* original 6143, guest PC 0x0c0aef10 */
if(!s->budget--) { s->failed_pc=0x0c0aef10u; return 0; }
r[1]=r[4];
goto P_0c0aef12;
P_0c0aef12: /* original 6230, guest PC 0x0c0aef12 */
if(!s->budget--) { s->failed_pc=0x0c0aef12u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0aef14;
P_0c0aef14: /* original 711a, guest PC 0x0c0aef14 */
if(!s->budget--) { s->failed_pc=0x0c0aef14u; return 0; }
r[1]+=0x0000001au;
goto P_0c0aef16;
P_0c0aef16: /* original d34f, guest PC 0x0c0aef16 */
if(!s->budget--) { s->failed_pc=0x0c0aef16u; return 0; }
r[3]=read(ram,0x0c0af054u,4);
goto P_0c0aef18;
P_0c0aef18: /* original 6010, guest PC 0x0c0aef18 */
if(!s->budget--) { s->failed_pc=0x0c0aef18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef1a;
P_0c0aef1a: /* original 622c, guest PC 0x0c0aef1a */
if(!s->budget--) { s->failed_pc=0x0c0aef1au; return 0; }
r[2]=r[2]&255u;
goto P_0c0aef1c;
P_0c0aef1c: /* original 4228, guest PC 0x0c0aef1c */
if(!s->budget--) { s->failed_pc=0x0c0aef1cu; return 0; }
r[2]<<=16;
goto P_0c0aef1e;
P_0c0aef1e: /* original 6143, guest PC 0x0c0aef1e */
if(!s->budget--) { s->failed_pc=0x0c0aef1eu; return 0; }
r[1]=r[4];
goto P_0c0aef20;
P_0c0aef20: /* original 600c, guest PC 0x0c0aef20 */
if(!s->budget--) { s->failed_pc=0x0c0aef20u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef22;
P_0c0aef22: /* original 4218, guest PC 0x0c0aef22 */
if(!s->budget--) { s->failed_pc=0x0c0aef22u; return 0; }
r[2]<<=8;
goto P_0c0aef24;
P_0c0aef24: /* original 4028, guest PC 0x0c0aef24 */
if(!s->budget--) { s->failed_pc=0x0c0aef24u; return 0; }
r[0]<<=16;
goto P_0c0aef26;
P_0c0aef26: /* original 2239, guest PC 0x0c0aef26 */
if(!s->budget--) { s->failed_pc=0x0c0aef26u; return 0; }
r[2]&=r[3];
goto P_0c0aef28;
P_0c0aef28: /* original 20b9, guest PC 0x0c0aef28 */
if(!s->budget--) { s->failed_pc=0x0c0aef28u; return 0; }
r[0]&=r[11];
goto P_0c0aef2a;
P_0c0aef2a: /* original 7119, guest PC 0x0c0aef2a */
if(!s->budget--) { s->failed_pc=0x0c0aef2au; return 0; }
r[1]+=0x00000019u;
goto P_0c0aef2c;
P_0c0aef2c: /* original 220b, guest PC 0x0c0aef2c */
if(!s->budget--) { s->failed_pc=0x0c0aef2cu; return 0; }
r[2]|=r[0];
goto P_0c0aef2e;
P_0c0aef2e: /* original 6010, guest PC 0x0c0aef2e */
if(!s->budget--) { s->failed_pc=0x0c0aef2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef30;
P_0c0aef30: /* original 6143, guest PC 0x0c0aef30 */
if(!s->budget--) { s->failed_pc=0x0c0aef30u; return 0; }
r[1]=r[4];
goto P_0c0aef32;
P_0c0aef32: /* original 7118, guest PC 0x0c0aef32 */
if(!s->budget--) { s->failed_pc=0x0c0aef32u; return 0; }
r[1]+=0x00000018u;
goto P_0c0aef34;
P_0c0aef34: /* original 600c, guest PC 0x0c0aef34 */
if(!s->budget--) { s->failed_pc=0x0c0aef34u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef36;
P_0c0aef36: /* original 4018, guest PC 0x0c0aef36 */
if(!s->budget--) { s->failed_pc=0x0c0aef36u; return 0; }
r[0]<<=8;
goto P_0c0aef38;
P_0c0aef38: /* original 2099, guest PC 0x0c0aef38 */
if(!s->budget--) { s->failed_pc=0x0c0aef38u; return 0; }
r[0]&=r[9];
goto P_0c0aef3a;
P_0c0aef3a: /* original 220b, guest PC 0x0c0aef3a */
if(!s->budget--) { s->failed_pc=0x0c0aef3au; return 0; }
r[2]|=r[0];
goto P_0c0aef3c;
P_0c0aef3c: /* original 6010, guest PC 0x0c0aef3c */
if(!s->budget--) { s->failed_pc=0x0c0aef3cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0aef3e;
P_0c0aef3e: /* original 600c, guest PC 0x0c0aef3e */
if(!s->budget--) { s->failed_pc=0x0c0aef3eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aef40;
P_0c0aef40: /* original 220b, guest PC 0x0c0aef40 */
if(!s->budget--) { s->failed_pc=0x0c0aef40u; return 0; }
r[2]|=r[0];
goto P_0c0aef42;
P_0c0aef42: /* original 2522, guest PC 0x0c0aef42 */
if(!s->budget--) { s->failed_pc=0x0c0aef42u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0aef44;
P_0c0aef44: /* original d242, guest PC 0x0c0aef44 */
if(!s->budget--) { s->failed_pc=0x0c0aef44u; return 0; }
r[2]=read(ram,0x0c0af050u,4);
goto P_0c0aef46;
P_0c0aef46: /* original 420b, guest PC 0x0c0aef46 */
if(!s->budget--) { s->failed_pc=0x0c0aef46u; return 0; }
target=r[2];
r[16]=0x0c0aef4au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef4au) { target=s->pc; goto dispatch; }
goto P_0c0aef4a;
P_0c0aef48: /* original 64d3, guest PC 0x0c0aef48 */
if(!s->budget--) { s->failed_pc=0x0c0aef48u; return 0; }
r[4]=r[13];
goto P_0c0aef4a;
P_0c0aef4a: /* original ff0a, guest PC 0x0c0aef4a */
if(!s->budget--) { s->failed_pc=0x0c0aef4au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef4c;
P_0c0aef4c: /* original 4a0b, guest PC 0x0c0aef4c */
if(!s->budget--) { s->failed_pc=0x0c0aef4cu; return 0; }
target=r[10];
r[16]=0x0c0aef50u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef50u) { target=s->pc; goto dispatch; }
goto P_0c0aef50;
P_0c0aef4e: /* original 64d3, guest PC 0x0c0aef4e */
if(!s->budget--) { s->failed_pc=0x0c0aef4eu; return 0; }
r[4]=r[13];
goto P_0c0aef50;
P_0c0aef50: /* original f0f2, guest PC 0x0c0aef50 */
if(!s->budget--) { s->failed_pc=0x0c0aef50u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aef52;
P_0c0aef52: /* original f04d, guest PC 0x0c0aef52 */
if(!s->budget--) { s->failed_pc=0x0c0aef52u; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aef54;
P_0c0aef54: /* original ff0a, guest PC 0x0c0aef54 */
if(!s->budget--) { s->failed_pc=0x0c0aef54u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef56;
P_0c0aef56: /* original 4a0b, guest PC 0x0c0aef56 */
if(!s->budget--) { s->failed_pc=0x0c0aef56u; return 0; }
target=r[10];
r[16]=0x0c0aef5au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef5au) { target=s->pc; goto dispatch; }
goto P_0c0aef5a;
P_0c0aef58: /* original 64d3, guest PC 0x0c0aef58 */
if(!s->budget--) { s->failed_pc=0x0c0aef58u; return 0; }
r[4]=r[13];
goto P_0c0aef5a;
P_0c0aef5a: /* original f0f2, guest PC 0x0c0aef5a */
if(!s->budget--) { s->failed_pc=0x0c0aef5au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0aef5c;
P_0c0aef5c: /* original f04d, guest PC 0x0c0aef5c */
if(!s->budget--) { s->failed_pc=0x0c0aef5cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c0aef5e;
P_0c0aef5e: /* original ff0a, guest PC 0x0c0aef5e */
if(!s->budget--) { s->failed_pc=0x0c0aef5eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef60;
P_0c0aef60: /* original d33b, guest PC 0x0c0aef60 */
if(!s->budget--) { s->failed_pc=0x0c0aef60u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef62;
P_0c0aef62: /* original 430b, guest PC 0x0c0aef62 */
if(!s->budget--) { s->failed_pc=0x0c0aef62u; return 0; }
target=r[3];
r[16]=0x0c0aef66u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef66u) { target=s->pc; goto dispatch; }
goto P_0c0aef66;
P_0c0aef64: /* original 64d3, guest PC 0x0c0aef64 */
if(!s->budget--) { s->failed_pc=0x0c0aef64u; return 0; }
r[4]=r[13];
goto P_0c0aef66;
P_0c0aef66: /* original ff0a, guest PC 0x0c0aef66 */
if(!s->budget--) { s->failed_pc=0x0c0aef66u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef68;
P_0c0aef68: /* original d339, guest PC 0x0c0aef68 */
if(!s->budget--) { s->failed_pc=0x0c0aef68u; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef6a;
P_0c0aef6a: /* original 430b, guest PC 0x0c0aef6a */
if(!s->budget--) { s->failed_pc=0x0c0aef6au; return 0; }
target=r[3];
r[16]=0x0c0aef6eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef6eu) { target=s->pc; goto dispatch; }
goto P_0c0aef6e;
P_0c0aef6c: /* original 64d3, guest PC 0x0c0aef6c */
if(!s->budget--) { s->failed_pc=0x0c0aef6cu; return 0; }
r[4]=r[13];
goto P_0c0aef6e;
P_0c0aef6e: /* original ff0a, guest PC 0x0c0aef6e */
if(!s->budget--) { s->failed_pc=0x0c0aef6eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef70;
P_0c0aef70: /* original 4a0b, guest PC 0x0c0aef70 */
if(!s->budget--) { s->failed_pc=0x0c0aef70u; return 0; }
target=r[10];
r[16]=0x0c0aef74u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef74u) { target=s->pc; goto dispatch; }
goto P_0c0aef74;
P_0c0aef72: /* original 64d3, guest PC 0x0c0aef72 */
if(!s->budget--) { s->failed_pc=0x0c0aef72u; return 0; }
r[4]=r[13];
goto P_0c0aef74;
P_0c0aef74: /* original ff0a, guest PC 0x0c0aef74 */
if(!s->budget--) { s->failed_pc=0x0c0aef74u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef76;
P_0c0aef76: /* original 4a0b, guest PC 0x0c0aef76 */
if(!s->budget--) { s->failed_pc=0x0c0aef76u; return 0; }
target=r[10];
r[16]=0x0c0aef7au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef7au) { target=s->pc; goto dispatch; }
goto P_0c0aef7a;
P_0c0aef78: /* original 64d3, guest PC 0x0c0aef78 */
if(!s->budget--) { s->failed_pc=0x0c0aef78u; return 0; }
r[4]=r[13];
goto P_0c0aef7a;
P_0c0aef7a: /* original ff0a, guest PC 0x0c0aef7a */
if(!s->budget--) { s->failed_pc=0x0c0aef7au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef7c;
P_0c0aef7c: /* original d334, guest PC 0x0c0aef7c */
if(!s->budget--) { s->failed_pc=0x0c0aef7cu; return 0; }
r[3]=read(ram,0x0c0af050u,4);
goto P_0c0aef7e;
P_0c0aef7e: /* original 430b, guest PC 0x0c0aef7e */
if(!s->budget--) { s->failed_pc=0x0c0aef7eu; return 0; }
target=r[3];
r[16]=0x0c0aef82u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef82u) { target=s->pc; goto dispatch; }
goto P_0c0aef82;
P_0c0aef80: /* original 64d3, guest PC 0x0c0aef80 */
if(!s->budget--) { s->failed_pc=0x0c0aef80u; return 0; }
r[4]=r[13];
goto P_0c0aef82;
P_0c0aef82: /* original 63f3, guest PC 0x0c0aef82 */
if(!s->budget--) { s->failed_pc=0x0c0aef82u; return 0; }
r[3]=r[15];
goto P_0c0aef84;
P_0c0aef84: /* original 7308, guest PC 0x0c0aef84 */
if(!s->budget--) { s->failed_pc=0x0c0aef84u; return 0; }
r[3]+=0x00000008u;
goto P_0c0aef86;
P_0c0aef86: /* original ff0a, guest PC 0x0c0aef86 */
if(!s->budget--) { s->failed_pc=0x0c0aef86u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0aef88;
P_0c0aef88: /* original 2f36, guest PC 0x0c0aef88 */
if(!s->budget--) { s->failed_pc=0x0c0aef88u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aef8a;
P_0c0aef8a: /* original 66f3, guest PC 0x0c0aef8a */
if(!s->budget--) { s->failed_pc=0x0c0aef8au; return 0; }
r[6]=r[15];
goto P_0c0aef8c;
P_0c0aef8c: /* original 65f3, guest PC 0x0c0aef8c */
if(!s->budget--) { s->failed_pc=0x0c0aef8cu; return 0; }
r[5]=r[15];
goto P_0c0aef8e;
P_0c0aef8e: /* original 67f3, guest PC 0x0c0aef8e */
if(!s->budget--) { s->failed_pc=0x0c0aef8eu; return 0; }
r[7]=r[15];
goto P_0c0aef90;
P_0c0aef90: /* original d231, guest PC 0x0c0aef90 */
if(!s->budget--) { s->failed_pc=0x0c0aef90u; return 0; }
r[2]=read(ram,0x0c0af058u,4);
goto P_0c0aef92;
P_0c0aef92: /* original 7504, guest PC 0x0c0aef92 */
if(!s->budget--) { s->failed_pc=0x0c0aef92u; return 0; }
r[5]+=0x00000004u;
goto P_0c0aef94;
P_0c0aef94: /* original 7714, guest PC 0x0c0aef94 */
if(!s->budget--) { s->failed_pc=0x0c0aef94u; return 0; }
r[7]+=0x00000014u;
goto P_0c0aef96;
P_0c0aef96: /* original 7608, guest PC 0x0c0aef96 */
if(!s->budget--) { s->failed_pc=0x0c0aef96u; return 0; }
r[6]+=0x00000008u;
goto P_0c0aef98;
P_0c0aef98: /* original 420b, guest PC 0x0c0aef98 */
if(!s->budget--) { s->failed_pc=0x0c0aef98u; return 0; }
target=r[2];
r[16]=0x0c0aef9cu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aef9cu) { target=s->pc; goto dispatch; }
goto P_0c0aef9c;
P_0c0aef9a: /* original 6483, guest PC 0x0c0aef9a */
if(!s->budget--) { s->failed_pc=0x0c0aef9au; return 0; }
r[4]=r[8];
goto P_0c0aef9c;
P_0c0aef9c: /* original 7f04, guest PC 0x0c0aef9c */
if(!s->budget--) { s->failed_pc=0x0c0aef9cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aef9e;
P_0c0aef9e: /* original 53f3, guest PC 0x0c0aef9e */
if(!s->budget--) { s->failed_pc=0x0c0aef9eu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0aefa0;
P_0c0aefa0: /* original 2338, guest PC 0x0c0aefa0 */
if(!s->budget--) { s->failed_pc=0x0c0aefa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0aefa2;
P_0c0aefa2: /* original 8903, guest PC 0x0c0aefa2 */
if(!s->budget--) { s->failed_pc=0x0c0aefa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aefac; }
goto P_0c0aefa4;
P_0c0aefa4: /* original 52f2, guest PC 0x0c0aefa4 */
if(!s->budget--) { s->failed_pc=0x0c0aefa4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0aefa6;
P_0c0aefa6: /* original d32d, guest PC 0x0c0aefa6 */
if(!s->budget--) { s->failed_pc=0x0c0aefa6u; return 0; }
r[3]=read(ram,0x0c0af05cu,4);
goto P_0c0aefa8;
P_0c0aefa8: /* original 223a, guest PC 0x0c0aefa8 */
if(!s->budget--) { s->failed_pc=0x0c0aefa8u; return 0; }
r[2]^=r[3];
goto P_0c0aefaa;
P_0c0aefaa: /* original 1f22, guest PC 0x0c0aefaa */
if(!s->budget--) { s->failed_pc=0x0c0aefaau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0aefac;
P_0c0aefac: /* original 904f, guest PC 0x0c0aefac */
if(!s->budget--) { s->failed_pc=0x0c0aefacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af04eu,2);
goto P_0c0aefae;
P_0c0aefae: /* original 64f3, guest PC 0x0c0aefae */
if(!s->budget--) { s->failed_pc=0x0c0aefaeu; return 0; }
r[4]=r[15];
goto P_0c0aefb0;
P_0c0aefb0: /* original 53f2, guest PC 0x0c0aefb0 */
if(!s->budget--) { s->failed_pc=0x0c0aefb0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0aefb2;
P_0c0aefb2: /* original 742c, guest PC 0x0c0aefb2 */
if(!s->budget--) { s->failed_pc=0x0c0aefb2u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0aefb4;
P_0c0aefb4: /* original 6543, guest PC 0x0c0aefb4 */
if(!s->budget--) { s->failed_pc=0x0c0aefb4u; return 0; }
r[5]=r[4];
goto P_0c0aefb6;
P_0c0aefb6: /* original 6643, guest PC 0x0c0aefb6 */
if(!s->budget--) { s->failed_pc=0x0c0aefb6u; return 0; }
r[6]=r[4];
goto P_0c0aefb8;
P_0c0aefb8: /* original 3038, guest PC 0x0c0aefb8 */
if(!s->budget--) { s->failed_pc=0x0c0aefb8u; return 0; }
r[0]-=r[3];
goto P_0c0aefba;
P_0c0aefba: /* original 81ef, guest PC 0x0c0aefba */
if(!s->budget--) { s->failed_pc=0x0c0aefbau; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0aefbc;
P_0c0aefbc: /* original e010, guest PC 0x0c0aefbc */
if(!s->budget--) { s->failed_pc=0x0c0aefbcu; return 0; }
r[0]=0x00000010u;
goto P_0c0aefbe;
P_0c0aefbe: /* original f586, guest PC 0x0c0aefbe */
if(!s->budget--) { s->failed_pc=0x0c0aefbeu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c0aefc0;
P_0c0aefc0: /* original e018, guest PC 0x0c0aefc0 */
if(!s->budget--) { s->failed_pc=0x0c0aefc0u; return 0; }
r[0]=0x00000018u;
goto P_0c0aefc2;
P_0c0aefc2: /* original f486, guest PC 0x0c0aefc2 */
if(!s->budget--) { s->failed_pc=0x0c0aefc2u; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c0aefc4;
P_0c0aefc4: /* original e004, guest PC 0x0c0aefc4 */
if(!s->budget--) { s->failed_pc=0x0c0aefc4u; return 0; }
r[0]=0x00000004u;
goto P_0c0aefc6;
P_0c0aefc6: /* original f3f8, guest PC 0x0c0aefc6 */
if(!s->budget--) { s->failed_pc=0x0c0aefc6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0aefc8;
P_0c0aefc8: /* original f351, guest PC 0x0c0aefc8 */
if(!s->budget--) { s->failed_pc=0x0c0aefc8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0aefca;
P_0c0aefca: /* original ff3a, guest PC 0x0c0aefca */
if(!s->budget--) { s->failed_pc=0x0c0aefcau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0aefcc;
P_0c0aefcc: /* original f2f6, guest PC 0x0c0aefcc */
if(!s->budget--) { s->failed_pc=0x0c0aefccu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0aefce;
P_0c0aefce: /* original e004, guest PC 0x0c0aefce */
if(!s->budget--) { s->failed_pc=0x0c0aefceu; return 0; }
r[0]=0x00000004u;
goto P_0c0aefd0;
P_0c0aefd0: /* original f44d, guest PC 0x0c0aefd0 */
if(!s->budget--) { s->failed_pc=0x0c0aefd0u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0aefd2;
P_0c0aefd2: /* original f421, guest PC 0x0c0aefd2 */
if(!s->budget--) { s->failed_pc=0x0c0aefd2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0aefd4;
P_0c0aefd4: /* original ff47, guest PC 0x0c0aefd4 */
if(!s->budget--) { s->failed_pc=0x0c0aefd4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0aefd6;
P_0c0aefd6: /* original 54c2, guest PC 0x0c0aefd6 */
if(!s->budget--) { s->failed_pc=0x0c0aefd6u; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c0aefd8;
P_0c0aefd8: /* original d31e, guest PC 0x0c0aefd8 */
if(!s->budget--) { s->failed_pc=0x0c0aefd8u; return 0; }
r[3]=read(ram,0x0c0af054u,4);
goto P_0c0aefda;
P_0c0aefda: /* original 8446, guest PC 0x0c0aefda */
if(!s->budget--) { s->failed_pc=0x0c0aefdau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0aefdc;
P_0c0aefdc: /* original 600c, guest PC 0x0c0aefdc */
if(!s->budget--) { s->failed_pc=0x0c0aefdcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aefde;
P_0c0aefde: /* original 4028, guest PC 0x0c0aefde */
if(!s->budget--) { s->failed_pc=0x0c0aefdeu; return 0; }
r[0]<<=16;
goto P_0c0aefe0;
P_0c0aefe0: /* original 4018, guest PC 0x0c0aefe0 */
if(!s->budget--) { s->failed_pc=0x0c0aefe0u; return 0; }
r[0]<<=8;
goto P_0c0aefe2;
P_0c0aefe2: /* original 2039, guest PC 0x0c0aefe2 */
if(!s->budget--) { s->failed_pc=0x0c0aefe2u; return 0; }
r[0]&=r[3];
goto P_0c0aefe4;
P_0c0aefe4: /* original 6203, guest PC 0x0c0aefe4 */
if(!s->budget--) { s->failed_pc=0x0c0aefe4u; return 0; }
r[2]=r[0];
goto P_0c0aefe6;
P_0c0aefe6: /* original 8445, guest PC 0x0c0aefe6 */
if(!s->budget--) { s->failed_pc=0x0c0aefe6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0aefe8;
P_0c0aefe8: /* original 600c, guest PC 0x0c0aefe8 */
if(!s->budget--) { s->failed_pc=0x0c0aefe8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aefea;
P_0c0aefea: /* original 4028, guest PC 0x0c0aefea */
if(!s->budget--) { s->failed_pc=0x0c0aefeau; return 0; }
r[0]<<=16;
goto P_0c0aefec;
P_0c0aefec: /* original 20b9, guest PC 0x0c0aefec */
if(!s->budget--) { s->failed_pc=0x0c0aefecu; return 0; }
r[0]&=r[11];
goto P_0c0aefee;
P_0c0aefee: /* original 220b, guest PC 0x0c0aefee */
if(!s->budget--) { s->failed_pc=0x0c0aefeeu; return 0; }
r[2]|=r[0];
goto P_0c0aeff0;
P_0c0aeff0: /* original 8444, guest PC 0x0c0aeff0 */
if(!s->budget--) { s->failed_pc=0x0c0aeff0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aeff2;
P_0c0aeff2: /* original 600c, guest PC 0x0c0aeff2 */
if(!s->budget--) { s->failed_pc=0x0c0aeff2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeff4;
P_0c0aeff4: /* original 4018, guest PC 0x0c0aeff4 */
if(!s->budget--) { s->failed_pc=0x0c0aeff4u; return 0; }
r[0]<<=8;
goto P_0c0aeff6;
P_0c0aeff6: /* original 2099, guest PC 0x0c0aeff6 */
if(!s->budget--) { s->failed_pc=0x0c0aeff6u; return 0; }
r[0]&=r[9];
goto P_0c0aeff8;
P_0c0aeff8: /* original 220b, guest PC 0x0c0aeff8 */
if(!s->budget--) { s->failed_pc=0x0c0aeff8u; return 0; }
r[2]|=r[0];
goto P_0c0aeffa;
P_0c0aeffa: /* original 8443, guest PC 0x0c0aeffa */
if(!s->budget--) { s->failed_pc=0x0c0aeffau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0aeffc;
P_0c0aeffc: /* original 600c, guest PC 0x0c0aeffc */
if(!s->budget--) { s->failed_pc=0x0c0aeffcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeffe;
P_0c0aeffe: /* original 220b, guest PC 0x0c0aeffe */
if(!s->budget--) { s->failed_pc=0x0c0aeffeu; return 0; }
r[2]|=r[0];
goto P_0c0af000;
P_0c0af000: /* original e004, guest PC 0x0c0af000 */
if(!s->budget--) { s->failed_pc=0x0c0af000u; return 0; }
r[0]=0x00000004u;
goto P_0c0af002;
P_0c0af002: /* original 2522, guest PC 0x0c0af002 */
if(!s->budget--) { s->failed_pc=0x0c0af002u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0af004;
P_0c0af004: /* original f368, guest PC 0x0c0af004 */
if(!s->budget--) { s->failed_pc=0x0c0af004u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c0af006;
P_0c0af006: /* original f4fc, guest PC 0x0c0af006 */
if(!s->budget--) { s->failed_pc=0x0c0af006u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0af008;
P_0c0af008: /* original f433, guest PC 0x0c0af008 */
if(!s->budget--) { s->failed_pc=0x0c0af008u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0af00a;
P_0c0af00a: /* original f3f8, guest PC 0x0c0af00a */
if(!s->budget--) { s->failed_pc=0x0c0af00au; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0af00c;
P_0c0af00c: /* original f24c, guest PC 0x0c0af00c */
if(!s->budget--) { s->failed_pc=0x0c0af00cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0af00e;
P_0c0af00e: /* original f232, guest PC 0x0c0af00e */
if(!s->budget--) { s->failed_pc=0x0c0af00eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0af010;
P_0c0af010: /* original ff2a, guest PC 0x0c0af010 */
if(!s->budget--) { s->failed_pc=0x0c0af010u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0af012;
P_0c0af012: /* original f3f6, guest PC 0x0c0af012 */
if(!s->budget--) { s->failed_pc=0x0c0af012u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af014;
P_0c0af014: /* original e004, guest PC 0x0c0af014 */
if(!s->budget--) { s->failed_pc=0x0c0af014u; return 0; }
r[0]=0x00000004u;
goto P_0c0af016;
P_0c0af016: /* original f432, guest PC 0x0c0af016 */
if(!s->budget--) { s->failed_pc=0x0c0af016u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0af018;
P_0c0af018: /* original ff47, guest PC 0x0c0af018 */
if(!s->budget--) { s->failed_pc=0x0c0af018u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0af01a;
P_0c0af01a: /* original e024, guest PC 0x0c0af01a */
if(!s->budget--) { s->failed_pc=0x0c0af01au; return 0; }
r[0]=0x00000024u;
goto P_0c0af01c;
P_0c0af01c: /* original f3f8, guest PC 0x0c0af01c */
if(!s->budget--) { s->failed_pc=0x0c0af01cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0af01e;
P_0c0af01e: /* original fe37, guest PC 0x0c0af01e */
if(!s->budget--) { s->failed_pc=0x0c0af01eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0af020;
P_0c0af020: /* original e004, guest PC 0x0c0af020 */
if(!s->budget--) { s->failed_pc=0x0c0af020u; return 0; }
r[0]=0x00000004u;
goto P_0c0af022;
P_0c0af022: /* original f3f6, guest PC 0x0c0af022 */
if(!s->budget--) { s->failed_pc=0x0c0af022u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af024;
P_0c0af024: /* original e02c, guest PC 0x0c0af024 */
if(!s->budget--) { s->failed_pc=0x0c0af024u; return 0; }
r[0]=0x0000002cu;
goto P_0c0af026;
P_0c0af026: /* original fe37, guest PC 0x0c0af026 */
if(!s->budget--) { s->failed_pc=0x0c0af026u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0af028;
P_0c0af028: /* original 53c2, guest PC 0x0c0af028 */
if(!s->budget--) { s->failed_pc=0x0c0af028u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0af02a;
P_0c0af02a: /* original 6583, guest PC 0x0c0af02a */
if(!s->budget--) { s->failed_pc=0x0c0af02au; return 0; }
r[5]=r[8];
goto P_0c0af02c;
P_0c0af02c: /* original 66c3, guest PC 0x0c0af02c */
if(!s->budget--) { s->failed_pc=0x0c0af02cu; return 0; }
r[6]=r[12];
goto P_0c0af02e;
P_0c0af02e: /* original 731c, guest PC 0x0c0af02e */
if(!s->budget--) { s->failed_pc=0x0c0af02eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0af030;
P_0c0af030: /* original 1c32, guest PC 0x0c0af030 */
if(!s->budget--) { s->failed_pc=0x0c0af030u; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c0af032;
P_0c0af032: /* original b933, guest PC 0x0c0af032 */
if(!s->budget--) { s->failed_pc=0x0c0af032u; return 0; }
target=0x0c0ae29cu; r[16]=0x0c0af036u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0af036u) { target=s->pc; goto dispatch; }
goto P_0c0af036;
P_0c0af034: /* original 64e3, guest PC 0x0c0af034 */
if(!s->budget--) { s->failed_pc=0x0c0af034u; return 0; }
r[4]=r[14];
goto P_0c0af036;
P_0c0af036: /* original 7f34, guest PC 0x0c0af036 */
if(!s->budget--) { s->failed_pc=0x0c0af036u; return 0; }
r[15]+=0x00000034u;
goto P_0c0af038;
P_0c0af038: /* original 4f26, guest PC 0x0c0af038 */
if(!s->budget--) { s->failed_pc=0x0c0af038u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af03a;
P_0c0af03a: /* original fff9, guest PC 0x0c0af03a */
if(!s->budget--) { s->failed_pc=0x0c0af03au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0af03c;
P_0c0af03c: /* original 68f6, guest PC 0x0c0af03c */
if(!s->budget--) { s->failed_pc=0x0c0af03cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0af03e;
P_0c0af03e: /* original 69f6, guest PC 0x0c0af03e */
if(!s->budget--) { s->failed_pc=0x0c0af03eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0af040;
P_0c0af040: /* original 6af6, guest PC 0x0c0af040 */
if(!s->budget--) { s->failed_pc=0x0c0af040u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0af042;
P_0c0af042: /* original 6bf6, guest PC 0x0c0af042 */
if(!s->budget--) { s->failed_pc=0x0c0af042u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0af044;
P_0c0af044: /* original 6cf6, guest PC 0x0c0af044 */
if(!s->budget--) { s->failed_pc=0x0c0af044u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0af046;
P_0c0af046: /* original 6df6, guest PC 0x0c0af046 */
if(!s->budget--) { s->failed_pc=0x0c0af046u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af048;
P_0c0af048: /* original 000b, guest PC 0x0c0af048 */
if(!s->budget--) { s->failed_pc=0x0c0af048u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af04a: /* original 6ef6, guest PC 0x0c0af04a */
if(!s->budget--) { s->failed_pc=0x0c0af04au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0af04cu,s,ram);
P_0c0c12f0: /* original 2fe6, guest PC 0x0c0c12f0 */
if(!s->budget--) { s->failed_pc=0x0c0c12f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f2;
P_0c0c12f2: /* original 6353, guest PC 0x0c0c12f2 */
if(!s->budget--) { s->failed_pc=0x0c0c12f2u; return 0; }
r[3]=r[5];
goto P_0c0c12f4;
P_0c0c12f4: /* original 2fc6, guest PC 0x0c0c12f4 */
if(!s->budget--) { s->failed_pc=0x0c0c12f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f6;
P_0c0c12f6: /* original 6c53, guest PC 0x0c0c12f6 */
if(!s->budget--) { s->failed_pc=0x0c0c12f6u; return 0; }
r[12]=r[5];
goto P_0c0c12f8;
P_0c0c12f8: /* original 2fb6, guest PC 0x0c0c12f8 */
if(!s->budget--) { s->failed_pc=0x0c0c12f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fa;
P_0c0c12fa: /* original 6b53, guest PC 0x0c0c12fa */
if(!s->budget--) { s->failed_pc=0x0c0c12fau; return 0; }
r[11]=r[5];
goto P_0c0c12fc;
P_0c0c12fc: /* original 2fa6, guest PC 0x0c0c12fc */
if(!s->budget--) { s->failed_pc=0x0c0c12fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fe;
P_0c0c12fe: /* original 4c29, guest PC 0x0c0c12fe */
if(!s->budget--) { s->failed_pc=0x0c0c12feu; return 0; }
r[12]>>=16;
goto P_0c0c1300;
P_0c0c1300: /* original 2f96, guest PC 0x0c0c1300 */
if(!s->budget--) { s->failed_pc=0x0c0c1300u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1302;
P_0c0c1302: /* original 6ccc, guest PC 0x0c0c1302 */
if(!s->budget--) { s->failed_pc=0x0c0c1302u; return 0; }
r[12]=r[12]&255u;
goto P_0c0c1304;
P_0c0c1304: /* original 2f86, guest PC 0x0c0c1304 */
if(!s->budget--) { s->failed_pc=0x0c0c1304u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1306;
P_0c0c1306: /* original 655c, guest PC 0x0c0c1306 */
if(!s->budget--) { s->failed_pc=0x0c0c1306u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c1308;
P_0c0c1308: /* original 35cc, guest PC 0x0c0c1308 */
if(!s->budget--) { s->failed_pc=0x0c0c1308u; return 0; }
r[5]+=r[12];
goto P_0c0c130a;
P_0c0c130a: /* original 5743, guest PC 0x0c0c130a */
if(!s->budget--) { s->failed_pc=0x0c0c130au; return 0; }
r[7]=read(ram,r[4]+12,4);
goto P_0c0c130c;
P_0c0c130c: /* original 7ff8, guest PC 0x0c0c130c */
if(!s->budget--) { s->failed_pc=0x0c0c130cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c130e;
P_0c0c130e: /* original 4b29, guest PC 0x0c0c130e */
if(!s->budget--) { s->failed_pc=0x0c0c130eu; return 0; }
r[11]>>=16;
goto P_0c0c1310;
P_0c0c1310: /* original 4319, guest PC 0x0c0c1310 */
if(!s->budget--) { s->failed_pc=0x0c0c1310u; return 0; }
r[3]>>=8;
goto P_0c0c1312;
P_0c0c1312: /* original 4b19, guest PC 0x0c0c1312 */
if(!s->budget--) { s->failed_pc=0x0c0c1312u; return 0; }
r[11]>>=8;
goto P_0c0c1314;
P_0c0c1314: /* original 6bbc, guest PC 0x0c0c1314 */
if(!s->budget--) { s->failed_pc=0x0c0c1314u; return 0; }
r[11]=r[11]&255u;
goto P_0c0c1316;
P_0c0c1316: /* original 633c, guest PC 0x0c0c1316 */
if(!s->budget--) { s->failed_pc=0x0c0c1316u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c1318;
P_0c0c1318: /* original 33bc, guest PC 0x0c0c1318 */
if(!s->budget--) { s->failed_pc=0x0c0c1318u; return 0; }
r[3]+=r[11];
goto P_0c0c131a;
P_0c0c131a: /* original c727, guest PC 0x0c0c131a */
if(!s->budget--) { s->failed_pc=0x0c0c131au; return 0; }
r[0]=0x0c0c13b8u;
goto P_0c0c131c;
P_0c0c131c: /* original 1f31, guest PC 0x0c0c131c */
if(!s->budget--) { s->failed_pc=0x0c0c131cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c131e;
P_0c0c131e: /* original 2f52, guest PC 0x0c0c131e */
if(!s->budget--) { s->failed_pc=0x0c0c131eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1320;
P_0c0c1320: /* original 6563, guest PC 0x0c0c1320 */
if(!s->budget--) { s->failed_pc=0x0c0c1320u; return 0; }
r[5]=r[6];
goto P_0c0c1322;
P_0c0c1322: /* original 4529, guest PC 0x0c0c1322 */
if(!s->budget--) { s->failed_pc=0x0c0c1322u; return 0; }
r[5]>>=16;
goto P_0c0c1324;
P_0c0c1324: /* original 4629, guest PC 0x0c0c1324 */
if(!s->budget--) { s->failed_pc=0x0c0c1324u; return 0; }
r[6]>>=16;
goto P_0c0c1326;
P_0c0c1326: /* original 4519, guest PC 0x0c0c1326 */
if(!s->budget--) { s->failed_pc=0x0c0c1326u; return 0; }
r[5]>>=8;
goto P_0c0c1328;
P_0c0c1328: /* original 666c, guest PC 0x0c0c1328 */
if(!s->budget--) { s->failed_pc=0x0c0c1328u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c132a;
P_0c0c132a: /* original 655c, guest PC 0x0c0c132a */
if(!s->budget--) { s->failed_pc=0x0c0c132au; return 0; }
r[5]=r[5]&255u;
goto P_0c0c132c;
P_0c0c132c: /* original 36c8, guest PC 0x0c0c132c */
if(!s->budget--) { s->failed_pc=0x0c0c132cu; return 0; }
r[6]-=r[12];
goto P_0c0c132e;
P_0c0c132e: /* original 35b8, guest PC 0x0c0c132e */
if(!s->budget--) { s->failed_pc=0x0c0c132eu; return 0; }
r[5]-=r[11];
goto P_0c0c1330;
P_0c0c1330: /* original 455a, guest PC 0x0c0c1330 */
if(!s->budget--) { s->failed_pc=0x0c0c1330u; return 0; }
r[53]=r[5];
goto P_0c0c1332;
P_0c0c1332: /* original ea00, guest PC 0x0c0c1332 */
if(!s->budget--) { s->failed_pc=0x0c0c1332u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1334;
P_0c0c1334: /* original d221, guest PC 0x0c0c1334 */
if(!s->budget--) { s->failed_pc=0x0c0c1334u; return 0; }
r[2]=read(ram,0x0c0c13bcu,4);
goto P_0c0c1336;
P_0c0c1336: /* original e901, guest PC 0x0c0c1336 */
if(!s->budget--) { s->failed_pc=0x0c0c1336u; return 0; }
r[9]=0x00000001u;
goto P_0c0c1338;
P_0c0c1338: /* original d121, guest PC 0x0c0c1338 */
if(!s->budget--) { s->failed_pc=0x0c0c1338u; return 0; }
r[1]=read(ram,0x0c0c13c0u,4);
goto P_0c0c133a;
P_0c0c133a: /* original e878, guest PC 0x0c0c133a */
if(!s->budget--) { s->failed_pc=0x0c0c133au; return 0; }
r[8]=0x00000078u;
goto P_0c0c133c;
P_0c0c133c: /* original f32d, guest PC 0x0c0c133c */
if(!s->budget--) { s->failed_pc=0x0c0c133cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c133e;
P_0c0c133e: /* original f228, guest PC 0x0c0c133e */
if(!s->budget--) { s->failed_pc=0x0c0c133eu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1340;
P_0c0c1340: /* original 465a, guest PC 0x0c0c1340 */
if(!s->budget--) { s->failed_pc=0x0c0c1340u; return 0; }
r[53]=r[6];
goto P_0c0c1342;
P_0c0c1342: /* original f118, guest PC 0x0c0c1342 */
if(!s->budget--) { s->failed_pc=0x0c0c1342u; return 0; }
vf3_matrix_load(s,ram,1,r[1]);
goto P_0c0c1344;
P_0c0c1344: /* original f608, guest PC 0x0c0c1344 */
if(!s->budget--) { s->failed_pc=0x0c0c1344u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c1346;
P_0c0c1346: /* original f322, guest PC 0x0c0c1346 */
if(!s->budget--) { s->failed_pc=0x0c0c1346u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1348;
P_0c0c1348: /* original f53c, guest PC 0x0c0c1348 */
if(!s->budget--) { s->failed_pc=0x0c0c1348u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c134a;
P_0c0c134a: /* original f32d, guest PC 0x0c0c134a */
if(!s->budget--) { s->failed_pc=0x0c0c134au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c134c;
P_0c0c134c: /* original f562, guest PC 0x0c0c134c */
if(!s->budget--) { s->failed_pc=0x0c0c134cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0c134e;
P_0c0c134e: /* original f312, guest PC 0x0c0c134e */
if(!s->budget--) { s->failed_pc=0x0c0c134eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0c1350;
P_0c0c1350: /* original f43c, guest PC 0x0c0c1350 */
if(!s->budget--) { s->failed_pc=0x0c0c1350u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c1352;
P_0c0c1352: /* original f462, guest PC 0x0c0c1352 */
if(!s->budget--) { s->failed_pc=0x0c0c1352u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0c1354;
P_0c0c1354: /* original 6371, guest PC 0x0c0c1354 */
if(!s->budget--) { s->failed_pc=0x0c0c1354u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[3]=tmp;
goto P_0c0c1356;
P_0c0c1356: /* original 633d, guest PC 0x0c0c1356 */
if(!s->budget--) { s->failed_pc=0x0c0c1356u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1358;
P_0c0c1358: /* original 2398, guest PC 0x0c0c1358 */
if(!s->budget--) { s->failed_pc=0x0c0c1358u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c135a;
P_0c0c135a: /* original 891b, guest PC 0x0c0c135a */
if(!s->budget--) { s->failed_pc=0x0c0c135au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c135c;
P_0c0c135c: /* original 8573, guest PC 0x0c0c135c */
if(!s->budget--) { s->failed_pc=0x0c0c135cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c135e;
P_0c0c135e: /* original 610d, guest PC 0x0c0c135e */
if(!s->budget--) { s->failed_pc=0x0c0c135eu; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c1360;
P_0c0c1360: /* original 8574, guest PC 0x0c0c1360 */
if(!s->budget--) { s->failed_pc=0x0c0c1360u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1362;
P_0c0c1362: /* original 31b3, guest PC 0x0c0c1362 */
if(!s->budget--) { s->failed_pc=0x0c0c1362u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[11])!=0);
goto P_0c0c1364;
P_0c0c1364: /* original 8f16, guest PC 0x0c0c1364 */
if(!s->budget--) { s->failed_pc=0x0c0c1364u; return 0; }
cond=r[17]&1u;
r[14]=r[0]&65535u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1368;
P_0c0c1366: /* original 6e0d, guest PC 0x0c0c1366 */
if(!s->budget--) { s->failed_pc=0x0c0c1366u; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c1368;
P_0c0c1368: /* original 52f1, guest PC 0x0c0c1368 */
if(!s->budget--) { s->failed_pc=0x0c0c1368u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c136a;
P_0c0c136a: /* original 3127, guest PC 0x0c0c136a */
if(!s->budget--) { s->failed_pc=0x0c0c136au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0c136c;
P_0c0c136c: /* original 8912, guest PC 0x0c0c136c */
if(!s->budget--) { s->failed_pc=0x0c0c136cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c136e;
P_0c0c136e: /* original 3ec3, guest PC 0x0c0c136e */
if(!s->budget--) { s->failed_pc=0x0c0c136eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c0c1370;
P_0c0c1370: /* original 8b10, guest PC 0x0c0c1370 */
if(!s->budget--) { s->failed_pc=0x0c0c1370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1372;
P_0c0c1372: /* original 63f2, guest PC 0x0c0c1372 */
if(!s->budget--) { s->failed_pc=0x0c0c1372u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1374;
P_0c0c1374: /* original 3e37, guest PC 0x0c0c1374 */
if(!s->budget--) { s->failed_pc=0x0c0c1374u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c0c1376;
P_0c0c1376: /* original 890d, guest PC 0x0c0c1376 */
if(!s->budget--) { s->failed_pc=0x0c0c1376u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c1378;
P_0c0c1378: /* original 8573, guest PC 0x0c0c1378 */
if(!s->budget--) { s->failed_pc=0x0c0c1378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c137a;
P_0c0c137a: /* original 305c, guest PC 0x0c0c137a */
if(!s->budget--) { s->failed_pc=0x0c0c137au; return 0; }
r[0]+=r[5];
goto P_0c0c137c;
P_0c0c137c: /* original 8173, guest PC 0x0c0c137c */
if(!s->budget--) { s->failed_pc=0x0c0c137cu; return 0; }
write(ram,r[7]+6,r[0],2);
goto P_0c0c137e;
P_0c0c137e: /* original 8574, guest PC 0x0c0c137e */
if(!s->budget--) { s->failed_pc=0x0c0c137eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1380;
P_0c0c1380: /* original 306c, guest PC 0x0c0c1380 */
if(!s->budget--) { s->failed_pc=0x0c0c1380u; return 0; }
r[0]+=r[6];
goto P_0c0c1382;
P_0c0c1382: /* original 8174, guest PC 0x0c0c1382 */
if(!s->budget--) { s->failed_pc=0x0c0c1382u; return 0; }
write(ram,r[7]+8,r[0],2);
goto P_0c0c1384;
P_0c0c1384: /* original e014, guest PC 0x0c0c1384 */
if(!s->budget--) { s->failed_pc=0x0c0c1384u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1386;
P_0c0c1386: /* original f376, guest PC 0x0c0c1386 */
if(!s->budget--) { s->failed_pc=0x0c0c1386u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0c1388;
P_0c0c1388: /* original f350, guest PC 0x0c0c1388 */
if(!s->budget--) { s->failed_pc=0x0c0c1388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0c138a;
P_0c0c138a: /* original f737, guest PC 0x0c0c138a */
if(!s->budget--) { s->failed_pc=0x0c0c138au; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c0c138c;
P_0c0c138c: /* original e018, guest PC 0x0c0c138c */
if(!s->budget--) { s->failed_pc=0x0c0c138cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c138e;
P_0c0c138e: /* original f276, guest PC 0x0c0c138e */
if(!s->budget--) { s->failed_pc=0x0c0c138eu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0c1390;
P_0c0c1390: /* original f240, guest PC 0x0c0c1390 */
if(!s->budget--) { s->failed_pc=0x0c0c1390u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1392;
P_0c0c1392: /* original f727, guest PC 0x0c0c1392 */
if(!s->budget--) { s->failed_pc=0x0c0c1392u; return 0; }
vf3_matrix_store(s,ram,2,r[7]+r[0]);
goto P_0c0c1394;
P_0c0c1394: /* original 7a01, guest PC 0x0c0c1394 */
if(!s->budget--) { s->failed_pc=0x0c0c1394u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c1396;
P_0c0c1396: /* original 3a82, guest PC 0x0c0c1396 */
if(!s->budget--) { s->failed_pc=0x0c0c1396u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[8])!=0);
goto P_0c0c1398;
P_0c0c1398: /* original 8fdc, guest PC 0x0c0c1398 */
if(!s->budget--) { s->failed_pc=0x0c0c1398u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000044u;
if(!cond) { goto P_0c0c1354; }
goto P_0c0c139c;
P_0c0c139a: /* original 7744, guest PC 0x0c0c139a */
if(!s->budget--) { s->failed_pc=0x0c0c139au; return 0; }
r[7]+=0x00000044u;
goto P_0c0c139c;
P_0c0c139c: /* original 7f08, guest PC 0x0c0c139c */
if(!s->budget--) { s->failed_pc=0x0c0c139cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c139e;
P_0c0c139e: /* original e022, guest PC 0x0c0c139e */
if(!s->budget--) { s->failed_pc=0x0c0c139eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c13a0;
P_0c0c13a0: /* original 024d, guest PC 0x0c0c13a0 */
if(!s->budget--) { s->failed_pc=0x0c0c13a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c13a2;
P_0c0c13a2: /* original e301, guest PC 0x0c0c13a2 */
if(!s->budget--) { s->failed_pc=0x0c0c13a2u; return 0; }
r[3]=0x00000001u;
goto P_0c0c13a4;
P_0c0c13a4: /* original 223b, guest PC 0x0c0c13a4 */
if(!s->budget--) { s->failed_pc=0x0c0c13a4u; return 0; }
r[2]|=r[3];
goto P_0c0c13a6;
P_0c0c13a6: /* original 0425, guest PC 0x0c0c13a6 */
if(!s->budget--) { s->failed_pc=0x0c0c13a6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c13a8;
P_0c0c13a8: /* original 68f6, guest PC 0x0c0c13a8 */
if(!s->budget--) { s->failed_pc=0x0c0c13a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c13aa;
P_0c0c13aa: /* original 69f6, guest PC 0x0c0c13aa */
if(!s->budget--) { s->failed_pc=0x0c0c13aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c13ac;
P_0c0c13ac: /* original 6af6, guest PC 0x0c0c13ac */
if(!s->budget--) { s->failed_pc=0x0c0c13acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c13ae;
P_0c0c13ae: /* original 6bf6, guest PC 0x0c0c13ae */
if(!s->budget--) { s->failed_pc=0x0c0c13aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c13b0;
P_0c0c13b0: /* original 6cf6, guest PC 0x0c0c13b0 */
if(!s->budget--) { s->failed_pc=0x0c0c13b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c13b2;
P_0c0c13b2: /* original 000b, guest PC 0x0c0c13b2 */
if(!s->budget--) { s->failed_pc=0x0c0c13b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c13b4: /* original 6ef6, guest PC 0x0c0c13b4 */
if(!s->budget--) { s->failed_pc=0x0c0c13b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c13b6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c08e920u,0x0c08e922u,0x0c08e924u,0x0c08e926u,0x0c08e928u,0x0c08e92au,0x0c08e92cu,0x0c08e92eu,0x0c08e930u,0x0c08e932u,0x0c08e934u,0x0c08e936u,0x0c08e938u,0x0c08e93au,0x0c08e93cu,0x0c08e93eu,
0x0c08e940u,0x0c08e942u,0x0c08e944u,0x0c08e946u,0x0c08e948u,0x0c08e94au,0x0c08e94cu,0x0c08e94eu,0x0c08e950u,0x0c08e952u,0x0c08e954u,0x0c08e956u,0x0c08e958u,0x0c08e95au,0x0c08e95cu,0x0c08e95eu,
0x0c08e960u,0x0c08e962u,0x0c08e964u,0x0c08e966u,0x0c08e968u,0x0c08e96au,0x0c08e96cu,0x0c08e96eu,0x0c08e970u,0x0c08e972u,0x0c08e974u,0x0c08e976u,0x0c08e978u,0x0c08e97au,0x0c08e97cu,0x0c08e97eu,
0x0c08e980u,0x0c08e982u,0x0c08e984u,0x0c08e986u,0x0c08e988u,0x0c08e98au,0x0c08e98cu,0x0c08e98eu,0x0c08e990u,0x0c08e992u,0x0c08e994u,0x0c08e996u,0x0c08e998u,0x0c08e99au,0x0c08e99cu,0x0c08e99eu,
0x0c08e9a0u,0x0c08e9a2u,0x0c08e9a4u,0x0c08e9a6u,0x0c08e9a8u,0x0c08e9aau,0x0c08e9acu,0x0c08e9aeu,0x0c08e9b0u,0x0c08e9b2u,0x0c08e9b4u,0x0c08e9b6u,0x0c08e9b8u,0x0c08e9bau,0x0c08e9bcu,0x0c08e9beu,
0x0c08e9c0u,0x0c08e9c2u,0x0c08e9c4u,0x0c08e9c6u,0x0c08e9c8u,0x0c08e9cau,0x0c08e9ccu,0x0c08e9ceu,0x0c08e9d0u,0x0c08e9d2u,0x0c08e9d4u,0x0c08e9d6u,0x0c08e9d8u,0x0c08e9dau,0x0c08e9dcu,0x0c08e9deu,
0x0c08e9e0u,0x0c08e9e2u,0x0c08e9e4u,0x0c08e9e6u,0x0c08e9e8u,0x0c08e9eau,0x0c08e9ecu,0x0c08e9eeu,0x0c08e9f0u,0x0c08e9f2u,0x0c08e9f4u,0x0c08e9f6u,0x0c08e9f8u,0x0c08e9fau,0x0c08e9fcu,0x0c08e9feu,
0x0c08ea00u,0x0c08ea02u,0x0c08ea04u,0x0c08ea06u,0x0c08ea08u,0x0c08ea0au,0x0c08ea0cu,0x0c08ea0eu,0x0c08ea10u,0x0c08ea12u,0x0c08ea14u,0x0c08ea16u,0x0c08ea18u,0x0c08ea1au,0x0c08ea1cu,0x0c08ea1eu,
0x0c08ea20u,0x0c08ea22u,0x0c08ea24u,0x0c08ea26u,0x0c08ea28u,0x0c08ea2au,0x0c08ea2cu,0x0c08ea2eu,0x0c08ea30u,0x0c08ea32u,0x0c08ea34u,0x0c08ea36u,0x0c08ea38u,0x0c08ea3au,0x0c08ea3cu,0x0c08ea3eu,
0x0c08ea40u,0x0c08ea42u,0x0c08ea44u,0x0c08ea46u,0x0c08ea48u,0x0c08ea4au,0x0c08ea4cu,0x0c08ea4eu,0x0c08ea50u,0x0c08ea52u,0x0c08ea54u,0x0c08ea56u,0x0c08ea58u,0x0c08ea5au,0x0c08ea5cu,0x0c08ea5eu,
0x0c08ea60u,0x0c08ea62u,0x0c08ea64u,0x0c08ea66u,0x0c08ea68u,0x0c08ea6au,0x0c08ea6cu,0x0c08ea6eu,0x0c08ea70u,0x0c08ea72u,0x0c08ea74u,0x0c08ea76u,0x0c08ea78u,0x0c08ea7au,0x0c08ea7cu,0x0c08ea7eu,
0x0c08ea80u,0x0c08ea82u,0x0c08ea84u,0x0c08ea86u,0x0c08ea88u,0x0c08ea8au,0x0c08ea8cu,0x0c08ea8eu,0x0c08ea90u,0x0c08ea92u,0x0c08ea94u,0x0c08ea96u,0x0c08ea98u,0x0c08ea9au,0x0c08ea9cu,0x0c08ea9eu,
0x0c08eaa0u,0x0c08eaa2u,0x0c08eaa4u,0x0c08eaa6u,0x0c08eaa8u,0x0c08eaaau,0x0c08eaacu,0x0c08eaaeu,0x0c08eab0u,0x0c08eab2u,0x0c08eab4u,0x0c08eab6u,0x0c08eab8u,0x0c08eabau,0x0c08eabcu,0x0c08eabeu,
0x0c08eac0u,0x0c08eac2u,0x0c08eac4u,0x0c08eac6u,0x0c08eac8u,0x0c08eacau,0x0c08eaccu,0x0c08eaceu,0x0c08ead0u,0x0c08ead2u,0x0c08ead4u,0x0c08ead6u,0x0c08ead8u,0x0c08eadau,0x0c08eadcu,0x0c08eadeu,
0x0c08eae0u,0x0c08eae2u,0x0c08eae4u,0x0c08eae6u,0x0c08eae8u,0x0c08eaeau,0x0c08eaecu,0x0c08eaeeu,0x0c08eaf0u,0x0c08eaf2u,0x0c08eaf4u,0x0c08eaf6u,0x0c08eaf8u,0x0c08eafau,0x0c08eafcu,0x0c08eafeu,
0x0c08eb00u,0x0c08eb02u,0x0c08eb04u,0x0c08eb06u,0x0c08eb08u,0x0c08eb0au,0x0c08eb0cu,0x0c08eb0eu,0x0c08eb10u,0x0c08eb12u,0x0c08eb14u,0x0c08eb16u,0x0c08eb18u,0x0c08eb1au,0x0c08eb1cu,0x0c08eb1eu,
0x0c08eb20u,0x0c08eb22u,0x0c08eb24u,0x0c08eb26u,0x0c08eb28u,0x0c08eb2au,0x0c08eb2cu,0x0c08eb2eu,0x0c08eb30u,0x0c08eb32u,0x0c08eb34u,0x0c08eb36u,0x0c08eb38u,0x0c08eb3au,0x0c08eb3cu,0x0c08eb3eu,
0x0c08eb40u,0x0c08eb42u,0x0c08eb44u,0x0c08eb46u,0x0c08eb48u,0x0c08eb4au,0x0c08eb4cu,0x0c08eb4eu,0x0c08eb50u,0x0c08eb52u,0x0c08eb54u,0x0c08eb56u,0x0c08eb58u,0x0c08eb5au,0x0c08eb5cu,0x0c08eb5eu,
0x0c08eb60u,0x0c08eb62u,0x0c08eb64u,0x0c08eb66u,0x0c08eb68u,0x0c08eb6au,0x0c08eb6cu,0x0c08eb6eu,0x0c08eb70u,0x0c08eb72u,0x0c08eb74u,0x0c08eb76u,0x0c08eb78u,0x0c08eb7au,0x0c08eb7cu,0x0c08eb7eu,
0x0c08eb80u,0x0c08eb82u,0x0c08eb84u,0x0c08eb86u,0x0c08eb88u,0x0c08eb8au,0x0c08eb8cu,0x0c08eb8eu,0x0c08eb90u,0x0c08eb92u,0x0c08eb94u,0x0c08eb96u,0x0c08eb98u,0x0c08eb9au,0x0c08eb9cu,0x0c08eb9eu,
0x0c08eba0u,0x0c08eba2u,0x0c08eba4u,0x0c08eba6u,0x0c08eba8u,0x0c08ebaau,0x0c08ebacu,0x0c08ebaeu,0x0c08ebb0u,0x0c08ebb2u,0x0c08ebb4u,0x0c08ebb6u,0x0c08ebb8u,0x0c091f60u,0x0c091f62u,0x0c091f64u,
0x0c091f66u,0x0c091f68u,0x0c091f6au,0x0c091f6cu,0x0c091f6eu,0x0c091f70u,0x0c091f72u,0x0c091f74u,0x0c091f76u,0x0c091f78u,0x0c091f7au,0x0c091f7cu,0x0c091f7eu,0x0c091f80u,0x0c091f82u,0x0c091f84u,
0x0c091f86u,0x0c091f88u,0x0c091f8au,0x0c091f8cu,0x0c091f8eu,0x0c091f90u,0x0c091f92u,0x0c091f94u,0x0c091f96u,0x0c091f98u,0x0c091f9au,0x0c091f9cu,0x0c091f9eu,0x0c091fa0u,0x0c091fa2u,0x0c091fa4u,
0x0c091fa6u,0x0c091fa8u,0x0c091faau,0x0c091facu,0x0c091faeu,0x0c091fb0u,0x0c091fb2u,0x0c091fb4u,0x0c091fb6u,0x0c091fb8u,0x0c091fbau,0x0c091fbcu,0x0c091fbeu,0x0c091fc0u,0x0c091fc2u,0x0c091fc4u,
0x0c091fc6u,0x0c091fc8u,0x0c091fcau,0x0c091fccu,0x0c091fceu,0x0c091fd0u,0x0c091fd2u,0x0c091fd4u,0x0c091fd6u,0x0c091fd8u,0x0c091fdau,0x0c091fdcu,0x0c091fdeu,0x0c091fe0u,0x0c091fe2u,0x0c091fe4u,
0x0c091fe6u,0x0c091fe8u,0x0c091feau,0x0c091fecu,0x0c091feeu,0x0c091ff0u,0x0c091ff2u,0x0c091ff4u,0x0c091ff6u,0x0c091ff8u,0x0c091ffau,0x0c091ffcu,0x0c091ffeu,0x0c092000u,0x0c092002u,0x0c092004u,
0x0c092006u,0x0c092008u,0x0c09200au,0x0c09200cu,0x0c09200eu,0x0c092010u,0x0c092012u,0x0c092014u,0x0c092016u,0x0c092018u,0x0c09201au,0x0c09201cu,0x0c09201eu,0x0c092020u,0x0c092022u,0x0c092024u,
0x0c092026u,0x0c092028u,0x0c092070u,0x0c092072u,0x0c092074u,0x0c092076u,0x0c092078u,0x0c09207au,0x0c09207cu,0x0c09207eu,0x0c092080u,0x0c092082u,0x0c092084u,0x0c092086u,0x0c092088u,0x0c09208au,
0x0c09208cu,0x0c09208eu,0x0c092090u,0x0c092092u,0x0c092094u,0x0c092096u,0x0c092098u,0x0c09209au,0x0c09209cu,0x0c09209eu,0x0c0920a0u,0x0c0920a2u,0x0c0920a4u,0x0c0920a6u,0x0c0920a8u,0x0c0920aau,
0x0c0920acu,0x0c0920aeu,0x0c0920b0u,0x0c0920b2u,0x0c0920b4u,0x0c0920b6u,0x0c0920b8u,0x0c0920bau,0x0c0920bcu,0x0c0920beu,0x0c0920c0u,0x0c0920c2u,0x0c0920c4u,0x0c0920c6u,0x0c0920c8u,0x0c0920cau,
0x0c0920ccu,0x0c0920ceu,0x0c0920d0u,0x0c0920d2u,0x0c0920d4u,0x0c0920d6u,0x0c0920d8u,0x0c0920dau,0x0c0920dcu,0x0c0920deu,0x0c0920e0u,0x0c0920e2u,0x0c0920e4u,0x0c0920e6u,0x0c0920e8u,0x0c0920eau,
0x0c0920ecu,0x0c0920eeu,0x0c0920f0u,0x0c0920f2u,0x0c0920f4u,0x0c0920f6u,0x0c0920f8u,0x0c0920fau,0x0c0920fcu,0x0c0920feu,0x0c092100u,0x0c092102u,0x0c092104u,0x0c092106u,0x0c092108u,0x0c09210au,
0x0c09210cu,0x0c09210eu,0x0c092110u,0x0c092112u,0x0c092114u,0x0c092116u,0x0c092118u,0x0c09211au,0x0c09211cu,0x0c09211eu,0x0c092120u,0x0c092122u,0x0c092124u,0x0c092126u,0x0c092128u,0x0c09212au,
0x0c09212cu,0x0c09212eu,0x0c092130u,0x0c092132u,0x0c092134u,0x0c092136u,0x0c092138u,0x0c09213au,0x0c09213cu,0x0c09213eu,0x0c092140u,0x0c092142u,0x0c092144u,0x0c092146u,0x0c092148u,0x0c09214au,
0x0c09214cu,0x0c09214eu,0x0c092150u,0x0c092152u,0x0c092154u,0x0c092156u,0x0c092158u,0x0c09215au,0x0c092180u,0x0c092182u,0x0c092184u,0x0c092186u,0x0c092188u,0x0c09218au,0x0c09218cu,0x0c09218eu,
0x0c092190u,0x0c092192u,0x0c092194u,0x0c092196u,0x0c092198u,0x0c09219au,0x0c09219cu,0x0c09219eu,0x0c0921a0u,0x0c0921a2u,0x0c0921a4u,0x0c0921a6u,0x0c0921a8u,0x0c0921aau,0x0c0921acu,0x0c0921aeu,
0x0c0921b0u,0x0c0921b2u,0x0c0921b4u,0x0c0921b6u,0x0c0921b8u,0x0c0921bau,0x0c0921bcu,0x0c0921beu,0x0c0921c0u,0x0c0921c2u,0x0c0921c4u,0x0c0921c6u,0x0c0921c8u,0x0c0921cau,0x0c0921ccu,0x0c0921ceu,
0x0c0921d0u,0x0c0921d2u,0x0c0921d4u,0x0c0921d6u,0x0c0921d8u,0x0c0921dau,0x0c0921dcu,0x0c0921deu,0x0c0921e0u,0x0c0921e2u,0x0c0921e4u,0x0c0921e6u,0x0c0921e8u,0x0c0921eau,0x0c0921ecu,0x0c0921eeu,
0x0c0921f0u,0x0c0921f2u,0x0c0921f4u,0x0c0921f6u,0x0c0921f8u,0x0c0921fau,0x0c0921fcu,0x0c0921feu,0x0c09460au,0x0c09460cu,0x0c09460eu,0x0c094610u,0x0c094612u,0x0c094614u,0x0c094616u,0x0c094618u,
0x0c09461au,0x0c09461cu,0x0c09461eu,0x0c094620u,0x0c094622u,0x0c094624u,0x0c094626u,0x0c094628u,0x0c09462au,0x0c09462cu,0x0c09462eu,0x0c094630u,0x0c094632u,0x0c094634u,0x0c094636u,0x0c094638u,
0x0c09463au,0x0c09463cu,0x0c09463eu,0x0c094640u,0x0c094642u,0x0c094644u,0x0c094646u,0x0c094648u,0x0c09464au,0x0c09464cu,0x0c09464eu,0x0c094650u,0x0c094652u,0x0c094654u,0x0c094656u,0x0c094658u,
0x0c09465au,0x0c09465cu,0x0c094688u,0x0c09468au,0x0c09468cu,0x0c09468eu,0x0c094690u,0x0c094692u,0x0c094694u,0x0c094696u,0x0c094698u,0x0c09469au,0x0c09469cu,0x0c09469eu,0x0c0946a0u,0x0c0946a2u,
0x0c0946a4u,0x0c0946a6u,0x0c0946a8u,0x0c0946aau,0x0c0946acu,0x0c0946aeu,0x0c0946b0u,0x0c0946b2u,0x0c0946b4u,0x0c0946b6u,0x0c0946b8u,0x0c0946bau,0x0c0946bcu,0x0c0946beu,0x0c0946c0u,0x0c0946c2u,
0x0c0946c4u,0x0c0946c6u,0x0c0946c8u,0x0c0946cau,0x0c0946ccu,0x0c0946ceu,0x0c0946d0u,0x0c0946d2u,0x0c0946d4u,0x0c0946d6u,0x0c0946d8u,0x0c0946dau,0x0c0946dcu,0x0c0946deu,0x0c0946e0u,0x0c0946e2u,
0x0c0946e4u,0x0c0946e6u,0x0c0946e8u,0x0c0946eau,0x0c0946ecu,0x0c0946eeu,0x0c0946f0u,0x0c0946f2u,0x0c0946f4u,0x0c0946f6u,0x0c0946f8u,0x0c0946fau,0x0c0946fcu,0x0c0946feu,0x0c094700u,0x0c094702u,
0x0c094704u,0x0c094706u,0x0c094708u,0x0c09470au,0x0c09470cu,0x0c09470eu,0x0c094710u,0x0c094712u,0x0c094714u,0x0c094716u,0x0c094718u,0x0c09471au,0x0c09471cu,0x0c09471eu,0x0c094720u,0x0c094722u,
0x0c094724u,0x0c094726u,0x0c094728u,0x0c09472au,0x0c09472cu,0x0c09472eu,0x0c094730u,0x0c094732u,0x0c094734u,0x0c094736u,0x0c094738u,0x0c09473au,0x0c09473cu,0x0c09473eu,0x0c094740u,0x0c094742u,
0x0c094744u,0x0c094746u,0x0c094748u,0x0c09474au,0x0c09474cu,0x0c09474eu,0x0c094750u,0x0c094752u,0x0c094754u,0x0c094756u,0x0c094758u,0x0c09477cu,0x0c09477eu,0x0c094780u,0x0c094782u,0x0c094784u,
0x0c094786u,0x0c094788u,0x0c09478au,0x0c09478cu,0x0c09478eu,0x0c094790u,0x0c094792u,0x0c094794u,0x0c094796u,0x0c094798u,0x0c09479au,0x0c09479cu,0x0c09479eu,0x0c0947a0u,0x0c0947a2u,0x0c0947a4u,
0x0c0947a6u,0x0c0947a8u,0x0c0947aau,0x0c0947acu,0x0c0947aeu,0x0c0947b0u,0x0c0947b2u,0x0c0947b4u,0x0c0947b6u,0x0c0947b8u,0x0c0947bau,0x0c0947bcu,0x0c0947beu,0x0c0947c0u,0x0c0947c2u,0x0c0947c4u,
0x0c0947c6u,0x0c0947c8u,0x0c0947cau,0x0c0947ccu,0x0c0947ceu,0x0c0947d0u,0x0c0947d2u,0x0c0947d4u,0x0c0947d6u,0x0c0947d8u,0x0c0947dau,0x0c0947dcu,0x0c0947deu,0x0c0947e0u,0x0c0947e2u,0x0c0947e4u,
0x0c0947e6u,0x0c0947e8u,0x0c0947eau,0x0c0947ecu,0x0c0947eeu,0x0c0947f0u,0x0c0947f2u,0x0c0947f4u,0x0c0947f6u,0x0c0947f8u,0x0c0947fau,0x0c0947fcu,0x0c0947feu,0x0c094800u,0x0c094802u,0x0c094804u,
0x0c094806u,0x0c094808u,0x0c09480au,0x0c09480cu,0x0c09480eu,0x0c094810u,0x0c094812u,0x0c094814u,0x0c094816u,0x0c094818u,0x0c09481au,0x0c09481cu,0x0c09481eu,0x0c094820u,0x0c094822u,0x0c094824u,
0x0c094826u,0x0c094828u,0x0c09482au,0x0c09482cu,0x0c09482eu,0x0c094830u,0x0c094832u,0x0c094834u,0x0c094836u,0x0c094838u,0x0c09483au,0x0c09483cu,0x0c09483eu,0x0c094840u,0x0c094842u,0x0c094844u,
0x0c094846u,0x0c094848u,0x0c09484au,0x0c09484cu,0x0c09484eu,0x0c094850u,0x0c094852u,0x0c094854u,0x0c094856u,0x0c094858u,0x0c09485au,0x0c09485cu,0x0c0ae2dcu,0x0c0ae2deu,0x0c0ae2e0u,0x0c0ae2e2u,
0x0c0ae2e4u,0x0c0ae2e6u,0x0c0ae2e8u,0x0c0ae2eau,0x0c0ae2ecu,0x0c0ae2eeu,0x0c0ae2f0u,0x0c0ae2f2u,0x0c0ae2f4u,0x0c0ae2f6u,0x0c0ae2f8u,0x0c0ae2fau,0x0c0ae2fcu,0x0c0ae2feu,0x0c0ae300u,0x0c0ae318u,
0x0c0ae31au,0x0c0ae31cu,0x0c0ae31eu,0x0c0ae320u,0x0c0ae322u,0x0c0ae324u,0x0c0ae326u,0x0c0ae328u,0x0c0ae32au,0x0c0ae32cu,0x0c0ae32eu,0x0c0ae330u,0x0c0ae332u,0x0c0ae334u,0x0c0ae336u,0x0c0ae338u,
0x0c0ae33au,0x0c0ae33cu,0x0c0ae33eu,0x0c0ae340u,0x0c0ae342u,0x0c0ae344u,0x0c0ae346u,0x0c0ae348u,0x0c0ae34au,0x0c0ae34cu,0x0c0ae34eu,0x0c0ae350u,0x0c0ae352u,0x0c0ae354u,0x0c0ae356u,0x0c0ae358u,
0x0c0ae35au,0x0c0ae35cu,0x0c0ae35eu,0x0c0ae360u,0x0c0ae362u,0x0c0ae364u,0x0c0ae366u,0x0c0ae368u,0x0c0ae36au,0x0c0ae36cu,0x0c0ae36eu,0x0c0ae370u,0x0c0ae372u,0x0c0ae374u,0x0c0ae376u,0x0c0ae378u,
0x0c0ae37au,0x0c0ae37cu,0x0c0ae37eu,0x0c0ae380u,0x0c0ae382u,0x0c0ae384u,0x0c0ae386u,0x0c0ae388u,0x0c0ae38au,0x0c0ae38cu,0x0c0ae38eu,0x0c0ae390u,0x0c0ae392u,0x0c0ae394u,0x0c0ae396u,0x0c0ae398u,
0x0c0ae39au,0x0c0ae39cu,0x0c0ae39eu,0x0c0ae3a0u,0x0c0ae3a2u,0x0c0ae3a4u,0x0c0ae3a6u,0x0c0ae3a8u,0x0c0ae3aau,0x0c0ae3acu,0x0c0ae3aeu,0x0c0ae3b0u,0x0c0ae3b2u,0x0c0ae3b4u,0x0c0ae3b6u,0x0c0ae3b8u,
0x0c0ae3bau,0x0c0ae3bcu,0x0c0ae3beu,0x0c0ae3c0u,0x0c0ae3c2u,0x0c0ae3c4u,0x0c0ae3c6u,0x0c0ae3c8u,0x0c0ae3cau,0x0c0ae3ccu,0x0c0ae3ceu,0x0c0ae3d0u,0x0c0ae3d2u,0x0c0ae3d4u,0x0c0ae3d6u,0x0c0ae3d8u,
0x0c0ae3dau,0x0c0ae3dcu,0x0c0ae3deu,0x0c0ae3e0u,0x0c0ae3e2u,0x0c0ae3e4u,0x0c0ae3e6u,0x0c0ae3e8u,0x0c0ae3eau,0x0c0ae3ecu,0x0c0ae3eeu,0x0c0ae3f0u,0x0c0ae3f2u,0x0c0ae3f4u,0x0c0ae3f6u,0x0c0ae3f8u,
0x0c0ae3fau,0x0c0ae3fcu,0x0c0ae3feu,0x0c0ae400u,0x0c0ae402u,0x0c0ae404u,0x0c0ae406u,0x0c0ae408u,0x0c0ae40au,0x0c0ae40cu,0x0c0ae40eu,0x0c0ae410u,0x0c0ae412u,0x0c0ae414u,0x0c0ae416u,0x0c0ae418u,
0x0c0ae41au,0x0c0ae41cu,0x0c0ae41eu,0x0c0ae420u,0x0c0ae422u,0x0c0ae424u,0x0c0ae52cu,0x0c0ae52eu,0x0c0ae530u,0x0c0ae532u,0x0c0ae534u,0x0c0ae536u,0x0c0ae538u,0x0c0ae53au,0x0c0ae53cu,0x0c0ae53eu,
0x0c0ae540u,0x0c0ae542u,0x0c0ae544u,0x0c0ae546u,0x0c0ae548u,0x0c0ae54au,0x0c0ae54cu,0x0c0ae54eu,0x0c0ae550u,0x0c0ae552u,0x0c0ae554u,0x0c0ae556u,0x0c0ae558u,0x0c0ae55au,0x0c0ae55cu,0x0c0ae55eu,
0x0c0ae560u,0x0c0ae562u,0x0c0ae564u,0x0c0ae566u,0x0c0ae568u,0x0c0ae56au,0x0c0ae56cu,0x0c0ae5a0u,0x0c0ae5a2u,0x0c0ae5a4u,0x0c0ae5a6u,0x0c0ae5a8u,0x0c0ae5aau,0x0c0ae5acu,0x0c0ae5aeu,0x0c0ae5b0u,
0x0c0ae5b2u,0x0c0ae5b4u,0x0c0ae5b6u,0x0c0ae5b8u,0x0c0ae5bau,0x0c0ae5bcu,0x0c0ae5beu,0x0c0ae5c0u,0x0c0ae5c2u,0x0c0ae5c4u,0x0c0ae5c6u,0x0c0ae5c8u,0x0c0ae5cau,0x0c0ae5ccu,0x0c0ae5ceu,0x0c0ae5d0u,
0x0c0ae5d2u,0x0c0ae5d4u,0x0c0ae5d6u,0x0c0ae5d8u,0x0c0ae5dau,0x0c0ae5dcu,0x0c0ae5deu,0x0c0ae5e0u,0x0c0ae5e2u,0x0c0ae5e4u,0x0c0ae5e6u,0x0c0ae5e8u,0x0c0ae5eau,0x0c0ae5ecu,0x0c0ae5eeu,0x0c0ae5f0u,
0x0c0ae5f2u,0x0c0ae5f4u,0x0c0ae5f6u,0x0c0ae5f8u,0x0c0ae5fau,0x0c0ae5fcu,0x0c0ae5feu,0x0c0ae600u,0x0c0ae602u,0x0c0ae604u,0x0c0ae606u,0x0c0ae608u,0x0c0ae60au,0x0c0ae60cu,0x0c0ae60eu,0x0c0ae610u,
0x0c0ae612u,0x0c0ae614u,0x0c0ae616u,0x0c0ae618u,0x0c0ae61au,0x0c0ae61cu,0x0c0ae61eu,0x0c0ae620u,0x0c0ae622u,0x0c0ae624u,0x0c0ae626u,0x0c0ae628u,0x0c0ae62au,0x0c0ae62cu,0x0c0ae62eu,0x0c0ae630u,
0x0c0ae632u,0x0c0ae634u,0x0c0ae636u,0x0c0ae638u,0x0c0ae63au,0x0c0ae63cu,0x0c0ae63eu,0x0c0ae640u,0x0c0ae642u,0x0c0ae644u,0x0c0ae646u,0x0c0ae648u,0x0c0ae64au,0x0c0ae64cu,0x0c0ae64eu,0x0c0ae650u,
0x0c0ae652u,0x0c0ae654u,0x0c0ae656u,0x0c0ae658u,0x0c0ae65au,0x0c0ae65cu,0x0c0ae65eu,0x0c0ae660u,0x0c0ae662u,0x0c0ae664u,0x0c0ae666u,0x0c0ae668u,0x0c0ae66au,0x0c0ae66cu,0x0c0ae66eu,0x0c0ae670u,
0x0c0ae672u,0x0c0ae674u,0x0c0ae676u,0x0c0ae678u,0x0c0ae67au,0x0c0ae67cu,0x0c0ae67eu,0x0c0ae680u,0x0c0ae682u,0x0c0ae684u,0x0c0ae686u,0x0c0ae688u,0x0c0ae68au,0x0c0ae68cu,0x0c0ae68eu,0x0c0ae690u,
0x0c0ae692u,0x0c0ae694u,0x0c0ae696u,0x0c0ae698u,0x0c0ae69au,0x0c0ae69cu,0x0c0ae69eu,0x0c0ae6a0u,0x0c0ae6a2u,0x0c0ae6a4u,0x0c0ae6a6u,0x0c0ae6a8u,0x0c0ae6aau,0x0c0ae6acu,0x0c0ae9ecu,0x0c0ae9eeu,
0x0c0ae9f0u,0x0c0ae9f2u,0x0c0ae9f4u,0x0c0ae9f6u,0x0c0ae9f8u,0x0c0ae9fau,0x0c0ae9fcu,0x0c0ae9feu,0x0c0aea00u,0x0c0aea02u,0x0c0aea04u,0x0c0aea06u,0x0c0aea08u,0x0c0aea0au,0x0c0aea0cu,0x0c0aea0eu,
0x0c0aea10u,0x0c0aea12u,0x0c0aea14u,0x0c0aea16u,0x0c0aea18u,0x0c0aea1au,0x0c0aea1cu,0x0c0aea1eu,0x0c0aea20u,0x0c0aea22u,0x0c0aea24u,0x0c0aea26u,0x0c0aea28u,0x0c0aea2au,0x0c0aea2cu,0x0c0aea2eu,
0x0c0aea30u,0x0c0aea32u,0x0c0aea34u,0x0c0aea36u,0x0c0aea38u,0x0c0aea3au,0x0c0aea3cu,0x0c0aea3eu,0x0c0aea40u,0x0c0aea42u,0x0c0aea44u,0x0c0aea46u,0x0c0aea48u,0x0c0aea4au,0x0c0aea4cu,0x0c0aea4eu,
0x0c0aea50u,0x0c0aea52u,0x0c0aea54u,0x0c0aea56u,0x0c0aea58u,0x0c0aea5au,0x0c0aed4au,0x0c0aed4cu,0x0c0aed4eu,0x0c0aed50u,0x0c0aed52u,0x0c0aed54u,0x0c0aed56u,0x0c0aed58u,0x0c0aed5au,0x0c0aed5cu,
0x0c0aed5eu,0x0c0aed60u,0x0c0aed62u,0x0c0aed64u,0x0c0aed66u,0x0c0aed68u,0x0c0aed6au,0x0c0aed6cu,0x0c0aed6eu,0x0c0aed70u,0x0c0aed72u,0x0c0aed74u,0x0c0aed76u,0x0c0aed78u,0x0c0aed7au,0x0c0aed7cu,
0x0c0aed7eu,0x0c0aed80u,0x0c0aed82u,0x0c0aed84u,0x0c0aed86u,0x0c0aed88u,0x0c0aed8au,0x0c0aed8cu,0x0c0aed8eu,0x0c0aed90u,0x0c0aed92u,0x0c0aed94u,0x0c0aed96u,0x0c0aed98u,0x0c0aed9au,0x0c0aed9cu,
0x0c0aed9eu,0x0c0aeda0u,0x0c0aeda2u,0x0c0aeda4u,0x0c0aeda6u,0x0c0aeda8u,0x0c0aedaau,0x0c0aedacu,0x0c0aedaeu,0x0c0aedb0u,0x0c0aedb2u,0x0c0aedb4u,0x0c0aedb6u,0x0c0aedb8u,0x0c0aedbau,0x0c0aedbcu,
0x0c0aedbeu,0x0c0aedc0u,0x0c0aedc2u,0x0c0aedc4u,0x0c0aedc6u,0x0c0aedc8u,0x0c0aedcau,0x0c0aedccu,0x0c0aedceu,0x0c0aedd0u,0x0c0aedd2u,0x0c0aedd4u,0x0c0aedd6u,0x0c0aedd8u,0x0c0aeddau,0x0c0aeddcu,
0x0c0aeddeu,0x0c0aede0u,0x0c0aede2u,0x0c0aede4u,0x0c0aede6u,0x0c0aede8u,0x0c0aedeau,0x0c0aedecu,0x0c0aedeeu,0x0c0aedf0u,0x0c0aedf2u,0x0c0aedf4u,0x0c0aedf6u,0x0c0aedf8u,0x0c0aedfau,0x0c0aedfcu,
0x0c0aedfeu,0x0c0aee00u,0x0c0aee02u,0x0c0aee04u,0x0c0aee06u,0x0c0aee08u,0x0c0aee0au,0x0c0aee0cu,0x0c0aee0eu,0x0c0aee10u,0x0c0aee12u,0x0c0aee14u,0x0c0aee16u,0x0c0aee18u,0x0c0aee1au,0x0c0aee1cu,
0x0c0aee1eu,0x0c0aee20u,0x0c0aee22u,0x0c0aee24u,0x0c0aee26u,0x0c0aee28u,0x0c0aee2au,0x0c0aee2cu,0x0c0aee2eu,0x0c0aee30u,0x0c0aee32u,0x0c0aee34u,0x0c0aee36u,0x0c0aee38u,0x0c0aee3au,0x0c0aee3cu,
0x0c0aee3eu,0x0c0aee40u,0x0c0aee42u,0x0c0aee44u,0x0c0aee46u,0x0c0aee48u,0x0c0aee4au,0x0c0aee4cu,0x0c0aee4eu,0x0c0aee50u,0x0c0aee52u,0x0c0aee54u,0x0c0aee56u,0x0c0aee58u,0x0c0aee5au,0x0c0aee5cu,
0x0c0aee5eu,0x0c0aee60u,0x0c0aee62u,0x0c0aee64u,0x0c0aee66u,0x0c0aee68u,0x0c0aee6au,0x0c0aee6cu,0x0c0aee6eu,0x0c0aee70u,0x0c0aee72u,0x0c0aee74u,0x0c0aee76u,0x0c0aee78u,0x0c0aee7au,0x0c0aee7cu,
0x0c0aee7eu,0x0c0aee80u,0x0c0aee82u,0x0c0aee84u,0x0c0aee86u,0x0c0aee88u,0x0c0aee8au,0x0c0aee8cu,0x0c0aee8eu,0x0c0aee90u,0x0c0aee92u,0x0c0aee94u,0x0c0aee96u,0x0c0aee98u,0x0c0aee9au,0x0c0aee9cu,
0x0c0aee9eu,0x0c0aeea0u,0x0c0aeea2u,0x0c0aeea4u,0x0c0aeea6u,0x0c0aeea8u,0x0c0aeeaau,0x0c0aeeccu,0x0c0aeeceu,0x0c0aeed0u,0x0c0aeed2u,0x0c0aeed4u,0x0c0aeed6u,0x0c0aeed8u,0x0c0aeedau,0x0c0aeedcu,
0x0c0aeedeu,0x0c0aeee0u,0x0c0aeee2u,0x0c0aeee4u,0x0c0aeee6u,0x0c0aeee8u,0x0c0aeeeau,0x0c0aeeecu,0x0c0aeeeeu,0x0c0aeef0u,0x0c0aeef2u,0x0c0aeef4u,0x0c0aeef6u,0x0c0aeef8u,0x0c0aeefau,0x0c0aeefcu,
0x0c0aeefeu,0x0c0aef00u,0x0c0aef02u,0x0c0aef04u,0x0c0aef06u,0x0c0aef08u,0x0c0aef0au,0x0c0aef0cu,0x0c0aef0eu,0x0c0aef10u,0x0c0aef12u,0x0c0aef14u,0x0c0aef16u,0x0c0aef18u,0x0c0aef1au,0x0c0aef1cu,
0x0c0aef1eu,0x0c0aef20u,0x0c0aef22u,0x0c0aef24u,0x0c0aef26u,0x0c0aef28u,0x0c0aef2au,0x0c0aef2cu,0x0c0aef2eu,0x0c0aef30u,0x0c0aef32u,0x0c0aef34u,0x0c0aef36u,0x0c0aef38u,0x0c0aef3au,0x0c0aef3cu,
0x0c0aef3eu,0x0c0aef40u,0x0c0aef42u,0x0c0aef44u,0x0c0aef46u,0x0c0aef48u,0x0c0aef4au,0x0c0aef4cu,0x0c0aef4eu,0x0c0aef50u,0x0c0aef52u,0x0c0aef54u,0x0c0aef56u,0x0c0aef58u,0x0c0aef5au,0x0c0aef5cu,
0x0c0aef5eu,0x0c0aef60u,0x0c0aef62u,0x0c0aef64u,0x0c0aef66u,0x0c0aef68u,0x0c0aef6au,0x0c0aef6cu,0x0c0aef6eu,0x0c0aef70u,0x0c0aef72u,0x0c0aef74u,0x0c0aef76u,0x0c0aef78u,0x0c0aef7au,0x0c0aef7cu,
0x0c0aef7eu,0x0c0aef80u,0x0c0aef82u,0x0c0aef84u,0x0c0aef86u,0x0c0aef88u,0x0c0aef8au,0x0c0aef8cu,0x0c0aef8eu,0x0c0aef90u,0x0c0aef92u,0x0c0aef94u,0x0c0aef96u,0x0c0aef98u,0x0c0aef9au,0x0c0aef9cu,
0x0c0aef9eu,0x0c0aefa0u,0x0c0aefa2u,0x0c0aefa4u,0x0c0aefa6u,0x0c0aefa8u,0x0c0aefaau,0x0c0aefacu,0x0c0aefaeu,0x0c0aefb0u,0x0c0aefb2u,0x0c0aefb4u,0x0c0aefb6u,0x0c0aefb8u,0x0c0aefbau,0x0c0aefbcu,
0x0c0aefbeu,0x0c0aefc0u,0x0c0aefc2u,0x0c0aefc4u,0x0c0aefc6u,0x0c0aefc8u,0x0c0aefcau,0x0c0aefccu,0x0c0aefceu,0x0c0aefd0u,0x0c0aefd2u,0x0c0aefd4u,0x0c0aefd6u,0x0c0aefd8u,0x0c0aefdau,0x0c0aefdcu,
0x0c0aefdeu,0x0c0aefe0u,0x0c0aefe2u,0x0c0aefe4u,0x0c0aefe6u,0x0c0aefe8u,0x0c0aefeau,0x0c0aefecu,0x0c0aefeeu,0x0c0aeff0u,0x0c0aeff2u,0x0c0aeff4u,0x0c0aeff6u,0x0c0aeff8u,0x0c0aeffau,0x0c0aeffcu,
0x0c0aeffeu,0x0c0af000u,0x0c0af002u,0x0c0af004u,0x0c0af006u,0x0c0af008u,0x0c0af00au,0x0c0af00cu,0x0c0af00eu,0x0c0af010u,0x0c0af012u,0x0c0af014u,0x0c0af016u,0x0c0af018u,0x0c0af01au,0x0c0af01cu,
0x0c0af01eu,0x0c0af020u,0x0c0af022u,0x0c0af024u,0x0c0af026u,0x0c0af028u,0x0c0af02au,0x0c0af02cu,0x0c0af02eu,0x0c0af030u,0x0c0af032u,0x0c0af034u,0x0c0af036u,0x0c0af038u,0x0c0af03au,0x0c0af03cu,
0x0c0af03eu,0x0c0af040u,0x0c0af042u,0x0c0af044u,0x0c0af046u,0x0c0af048u,0x0c0af04au,0x0c0c12f0u,0x0c0c12f2u,0x0c0c12f4u,0x0c0c12f6u,0x0c0c12f8u,0x0c0c12fau,0x0c0c12fcu,0x0c0c12feu,0x0c0c1300u,
0x0c0c1302u,0x0c0c1304u,0x0c0c1306u,0x0c0c1308u,0x0c0c130au,0x0c0c130cu,0x0c0c130eu,0x0c0c1310u,0x0c0c1312u,0x0c0c1314u,0x0c0c1316u,0x0c0c1318u,0x0c0c131au,0x0c0c131cu,0x0c0c131eu,0x0c0c1320u,
0x0c0c1322u,0x0c0c1324u,0x0c0c1326u,0x0c0c1328u,0x0c0c132au,0x0c0c132cu,0x0c0c132eu,0x0c0c1330u,0x0c0c1332u,0x0c0c1334u,0x0c0c1336u,0x0c0c1338u,0x0c0c133au,0x0c0c133cu,0x0c0c133eu,0x0c0c1340u,
0x0c0c1342u,0x0c0c1344u,0x0c0c1346u,0x0c0c1348u,0x0c0c134au,0x0c0c134cu,0x0c0c134eu,0x0c0c1350u,0x0c0c1352u,0x0c0c1354u,0x0c0c1356u,0x0c0c1358u,0x0c0c135au,0x0c0c135cu,0x0c0c135eu,0x0c0c1360u,
0x0c0c1362u,0x0c0c1364u,0x0c0c1366u,0x0c0c1368u,0x0c0c136au,0x0c0c136cu,0x0c0c136eu,0x0c0c1370u,0x0c0c1372u,0x0c0c1374u,0x0c0c1376u,0x0c0c1378u,0x0c0c137au,0x0c0c137cu,0x0c0c137eu,0x0c0c1380u,
0x0c0c1382u,0x0c0c1384u,0x0c0c1386u,0x0c0c1388u,0x0c0c138au,0x0c0c138cu,0x0c0c138eu,0x0c0c1390u,0x0c0c1392u,0x0c0c1394u,0x0c0c1396u,0x0c0c1398u,0x0c0c139au,0x0c0c139cu,0x0c0c139eu,0x0c0c13a0u,
0x0c0c13a2u,0x0c0c13a4u,0x0c0c13a6u,0x0c0c13a8u,0x0c0c13aau,0x0c0c13acu,0x0c0c13aeu,0x0c0c13b0u,0x0c0c13b2u,0x0c0c13b4u,
};
int vf3_tenpp_large_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
