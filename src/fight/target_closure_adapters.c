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
int vf3_target_closure_step(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03b8f4u: goto P_0c03b8f4;
case 0x0c03b8f6u: goto P_0c03b8f6;
case 0x0c03b8f8u: goto P_0c03b8f8;
case 0x0c03b8fau: goto P_0c03b8fa;
case 0x0c03b8fcu: goto P_0c03b8fc;
case 0x0c03b8feu: goto P_0c03b8fe;
case 0x0c03b900u: goto P_0c03b900;
case 0x0c03b902u: goto P_0c03b902;
case 0x0c03b904u: goto P_0c03b904;
case 0x0c03b906u: goto P_0c03b906;
case 0x0c03b908u: goto P_0c03b908;
case 0x0c03b90au: goto P_0c03b90a;
case 0x0c03b90cu: goto P_0c03b90c;
case 0x0c03b90eu: goto P_0c03b90e;
case 0x0c03b910u: goto P_0c03b910;
case 0x0c03b912u: goto P_0c03b912;
case 0x0c03b914u: goto P_0c03b914;
case 0x0c03b916u: goto P_0c03b916;
case 0x0c03b918u: goto P_0c03b918;
case 0x0c03b91au: goto P_0c03b91a;
case 0x0c03b91cu: goto P_0c03b91c;
case 0x0c03b91eu: goto P_0c03b91e;
case 0x0c03b920u: goto P_0c03b920;
case 0x0c03b922u: goto P_0c03b922;
case 0x0c03b924u: goto P_0c03b924;
case 0x0c03b926u: goto P_0c03b926;
case 0x0c03b928u: goto P_0c03b928;
case 0x0c03b92au: goto P_0c03b92a;
case 0x0c03b92cu: goto P_0c03b92c;
case 0x0c03b92eu: goto P_0c03b92e;
case 0x0c03b930u: goto P_0c03b930;
case 0x0c03b932u: goto P_0c03b932;
case 0x0c03b934u: goto P_0c03b934;
case 0x0c03b936u: goto P_0c03b936;
case 0x0c03b938u: goto P_0c03b938;
case 0x0c03b93au: goto P_0c03b93a;
case 0x0c03b93cu: goto P_0c03b93c;
case 0x0c03b93eu: goto P_0c03b93e;
case 0x0c03b940u: goto P_0c03b940;
case 0x0c03b942u: goto P_0c03b942;
case 0x0c03b944u: goto P_0c03b944;
case 0x0c03b946u: goto P_0c03b946;
case 0x0c03b948u: goto P_0c03b948;
case 0x0c03b94au: goto P_0c03b94a;
case 0x0c03b94cu: goto P_0c03b94c;
case 0x0c03b94eu: goto P_0c03b94e;
case 0x0c03b950u: goto P_0c03b950;
case 0x0c03b952u: goto P_0c03b952;
case 0x0c03b954u: goto P_0c03b954;
case 0x0c03b956u: goto P_0c03b956;
case 0x0c03b958u: goto P_0c03b958;
case 0x0c03b95au: goto P_0c03b95a;
case 0x0c03b95cu: goto P_0c03b95c;
case 0x0c03b95eu: goto P_0c03b95e;
case 0x0c03b960u: goto P_0c03b960;
case 0x0c03b962u: goto P_0c03b962;
case 0x0c03b964u: goto P_0c03b964;
case 0x0c03b966u: goto P_0c03b966;
case 0x0c03b968u: goto P_0c03b968;
case 0x0c03b96au: goto P_0c03b96a;
case 0x0c03b96cu: goto P_0c03b96c;
case 0x0c03b96eu: goto P_0c03b96e;
case 0x0c03b970u: goto P_0c03b970;
case 0x0c03b972u: goto P_0c03b972;
case 0x0c03b974u: goto P_0c03b974;
case 0x0c03b976u: goto P_0c03b976;
case 0x0c03b978u: goto P_0c03b978;
case 0x0c03b97au: goto P_0c03b97a;
case 0x0c03b97cu: goto P_0c03b97c;
case 0x0c03b97eu: goto P_0c03b97e;
case 0x0c03b980u: goto P_0c03b980;
case 0x0c03b982u: goto P_0c03b982;
case 0x0c03b984u: goto P_0c03b984;
case 0x0c03b986u: goto P_0c03b986;
case 0x0c03b988u: goto P_0c03b988;
case 0x0c03b98au: goto P_0c03b98a;
case 0x0c03b98cu: goto P_0c03b98c;
case 0x0c03b98eu: goto P_0c03b98e;
case 0x0c03b990u: goto P_0c03b990;
case 0x0c03b992u: goto P_0c03b992;
case 0x0c03b994u: goto P_0c03b994;
case 0x0c03b996u: goto P_0c03b996;
case 0x0c03b998u: goto P_0c03b998;
case 0x0c03b99au: goto P_0c03b99a;
case 0x0c03b99cu: goto P_0c03b99c;
case 0x0c03b99eu: goto P_0c03b99e;
case 0x0c03b9a0u: goto P_0c03b9a0;
case 0x0c03b9a2u: goto P_0c03b9a2;
case 0x0c03b9a4u: goto P_0c03b9a4;
case 0x0c03b9a6u: goto P_0c03b9a6;
case 0x0c03b9a8u: goto P_0c03b9a8;
case 0x0c03b9aau: goto P_0c03b9aa;
case 0x0c03b9acu: goto P_0c03b9ac;
case 0x0c03b9aeu: goto P_0c03b9ae;
case 0x0c03b9b0u: goto P_0c03b9b0;
case 0x0c03b9b2u: goto P_0c03b9b2;
case 0x0c03b9b4u: goto P_0c03b9b4;
case 0x0c03b9b6u: goto P_0c03b9b6;
case 0x0c03b9b8u: goto P_0c03b9b8;
case 0x0c03b9bau: goto P_0c03b9ba;
case 0x0c03b9bcu: goto P_0c03b9bc;
case 0x0c03b9beu: goto P_0c03b9be;
case 0x0c03b9c0u: goto P_0c03b9c0;
case 0x0c03b9c2u: goto P_0c03b9c2;
case 0x0c03b9c4u: goto P_0c03b9c4;
case 0x0c03b9c6u: goto P_0c03b9c6;
case 0x0c03b9c8u: goto P_0c03b9c8;
case 0x0c03b9cau: goto P_0c03b9ca;
case 0x0c03b9ccu: goto P_0c03b9cc;
case 0x0c03b9ceu: goto P_0c03b9ce;
case 0x0c03b9d0u: goto P_0c03b9d0;
case 0x0c03b9d2u: goto P_0c03b9d2;
case 0x0c03b9d4u: goto P_0c03b9d4;
case 0x0c03b9d6u: goto P_0c03b9d6;
case 0x0c03b9d8u: goto P_0c03b9d8;
case 0x0c03b9dau: goto P_0c03b9da;
case 0x0c03b9dcu: goto P_0c03b9dc;
case 0x0c03b9deu: goto P_0c03b9de;
case 0x0c03b9e0u: goto P_0c03b9e0;
case 0x0c03b9e2u: goto P_0c03b9e2;
case 0x0c03b9e4u: goto P_0c03b9e4;
case 0x0c03b9e6u: goto P_0c03b9e6;
case 0x0c03b9e8u: goto P_0c03b9e8;
case 0x0c03b9eau: goto P_0c03b9ea;
case 0x0c03b9ecu: goto P_0c03b9ec;
case 0x0c03b9eeu: goto P_0c03b9ee;
case 0x0c03b9f0u: goto P_0c03b9f0;
case 0x0c03b9f2u: goto P_0c03b9f2;
case 0x0c03b9f4u: goto P_0c03b9f4;
case 0x0c03b9f6u: goto P_0c03b9f6;
case 0x0c03b9f8u: goto P_0c03b9f8;
case 0x0c03b9fau: goto P_0c03b9fa;
case 0x0c03b9fcu: goto P_0c03b9fc;
case 0x0c03b9feu: goto P_0c03b9fe;
case 0x0c03ba00u: goto P_0c03ba00;
case 0x0c03ba02u: goto P_0c03ba02;
case 0x0c03ba04u: goto P_0c03ba04;
case 0x0c03ba06u: goto P_0c03ba06;
case 0x0c03ba08u: goto P_0c03ba08;
case 0x0c03ba0au: goto P_0c03ba0a;
case 0x0c03ba0cu: goto P_0c03ba0c;
case 0x0c03ba0eu: goto P_0c03ba0e;
case 0x0c03ba10u: goto P_0c03ba10;
case 0x0c03ba12u: goto P_0c03ba12;
case 0x0c03ba14u: goto P_0c03ba14;
case 0x0c03ba16u: goto P_0c03ba16;
case 0x0c03ba18u: goto P_0c03ba18;
case 0x0c03ba1au: goto P_0c03ba1a;
case 0x0c03ba1cu: goto P_0c03ba1c;
case 0x0c03ba1eu: goto P_0c03ba1e;
case 0x0c03ba20u: goto P_0c03ba20;
case 0x0c03ba22u: goto P_0c03ba22;
case 0x0c03ba24u: goto P_0c03ba24;
case 0x0c03ba26u: goto P_0c03ba26;
case 0x0c03ba28u: goto P_0c03ba28;
case 0x0c03ba2au: goto P_0c03ba2a;
case 0x0c03ba2cu: goto P_0c03ba2c;
case 0x0c03ba2eu: goto P_0c03ba2e;
case 0x0c03ba30u: goto P_0c03ba30;
case 0x0c03ba32u: goto P_0c03ba32;
case 0x0c054b84u: goto P_0c054b84;
case 0x0c054b86u: goto P_0c054b86;
case 0x0c054b88u: goto P_0c054b88;
case 0x0c054b8au: goto P_0c054b8a;
case 0x0c054b8cu: goto P_0c054b8c;
case 0x0c054b8eu: goto P_0c054b8e;
case 0x0c054b90u: goto P_0c054b90;
case 0x0c054b92u: goto P_0c054b92;
case 0x0c054b94u: goto P_0c054b94;
case 0x0c054b96u: goto P_0c054b96;
case 0x0c054b98u: goto P_0c054b98;
case 0x0c054b9au: goto P_0c054b9a;
case 0x0c054b9cu: goto P_0c054b9c;
case 0x0c054b9eu: goto P_0c054b9e;
case 0x0c054ba0u: goto P_0c054ba0;
case 0x0c054ba2u: goto P_0c054ba2;
case 0x0c054ba4u: goto P_0c054ba4;
case 0x0c054ba6u: goto P_0c054ba6;
case 0x0c054ba8u: goto P_0c054ba8;
case 0x0c054baau: goto P_0c054baa;
case 0x0c054bacu: goto P_0c054bac;
case 0x0c054baeu: goto P_0c054bae;
case 0x0c054bb0u: goto P_0c054bb0;
case 0x0c054bb2u: goto P_0c054bb2;
case 0x0c054bb4u: goto P_0c054bb4;
case 0x0c054bb6u: goto P_0c054bb6;
case 0x0c054bb8u: goto P_0c054bb8;
case 0x0c054bbau: goto P_0c054bba;
case 0x0c054bbcu: goto P_0c054bbc;
case 0x0c054bbeu: goto P_0c054bbe;
case 0x0c054bc0u: goto P_0c054bc0;
case 0x0c054bc2u: goto P_0c054bc2;
case 0x0c054bc4u: goto P_0c054bc4;
case 0x0c054bc6u: goto P_0c054bc6;
case 0x0c054bc8u: goto P_0c054bc8;
case 0x0c054bcau: goto P_0c054bca;
case 0x0c054bccu: goto P_0c054bcc;
case 0x0c054bceu: goto P_0c054bce;
case 0x0c054bd0u: goto P_0c054bd0;
case 0x0c054bd2u: goto P_0c054bd2;
case 0x0c054bd4u: goto P_0c054bd4;
case 0x0c054bd6u: goto P_0c054bd6;
case 0x0c054bd8u: goto P_0c054bd8;
case 0x0c054bdau: goto P_0c054bda;
case 0x0c054bdcu: goto P_0c054bdc;
case 0x0c054bdeu: goto P_0c054bde;
case 0x0c054be0u: goto P_0c054be0;
case 0x0c054be2u: goto P_0c054be2;
case 0x0c054be4u: goto P_0c054be4;
case 0x0c054be6u: goto P_0c054be6;
case 0x0c054be8u: goto P_0c054be8;
case 0x0c054beau: goto P_0c054bea;
case 0x0c054becu: goto P_0c054bec;
case 0x0c054beeu: goto P_0c054bee;
case 0x0c054bf0u: goto P_0c054bf0;
case 0x0c054bf2u: goto P_0c054bf2;
case 0x0c054bf4u: goto P_0c054bf4;
case 0x0c054bf6u: goto P_0c054bf6;
case 0x0c06d638u: goto P_0c06d638;
case 0x0c06d63au: goto P_0c06d63a;
case 0x0c06d63cu: goto P_0c06d63c;
case 0x0c06d63eu: goto P_0c06d63e;
case 0x0c06d640u: goto P_0c06d640;
case 0x0c06d642u: goto P_0c06d642;
case 0x0c06d644u: goto P_0c06d644;
case 0x0c06d646u: goto P_0c06d646;
case 0x0c06d648u: goto P_0c06d648;
case 0x0c06d64au: goto P_0c06d64a;
case 0x0c06d64cu: goto P_0c06d64c;
case 0x0c06d64eu: goto P_0c06d64e;
case 0x0c06d650u: goto P_0c06d650;
case 0x0c06d652u: goto P_0c06d652;
case 0x0c06d654u: goto P_0c06d654;
case 0x0c06d656u: goto P_0c06d656;
case 0x0c06d658u: goto P_0c06d658;
case 0x0c06d65au: goto P_0c06d65a;
case 0x0c06d65cu: goto P_0c06d65c;
case 0x0c06d65eu: goto P_0c06d65e;
case 0x0c06d660u: goto P_0c06d660;
case 0x0c06d662u: goto P_0c06d662;
case 0x0c06d664u: goto P_0c06d664;
case 0x0c06d666u: goto P_0c06d666;
case 0x0c06d668u: goto P_0c06d668;
case 0x0c06d66au: goto P_0c06d66a;
case 0x0c06d66cu: goto P_0c06d66c;
case 0x0c06d66eu: goto P_0c06d66e;
case 0x0c06d670u: goto P_0c06d670;
case 0x0c06d672u: goto P_0c06d672;
case 0x0c06d674u: goto P_0c06d674;
case 0x0c06d676u: goto P_0c06d676;
case 0x0c06d678u: goto P_0c06d678;
case 0x0c06d67au: goto P_0c06d67a;
case 0x0c06d67cu: goto P_0c06d67c;
case 0x0c06d67eu: goto P_0c06d67e;
case 0x0c06d680u: goto P_0c06d680;
case 0x0c06d682u: goto P_0c06d682;
case 0x0c06d684u: goto P_0c06d684;
case 0x0c06d686u: goto P_0c06d686;
case 0x0c06d688u: goto P_0c06d688;
case 0x0c06d68au: goto P_0c06d68a;
case 0x0c06d68cu: goto P_0c06d68c;
case 0x0c06d68eu: goto P_0c06d68e;
case 0x0c06d690u: goto P_0c06d690;
case 0x0c06d692u: goto P_0c06d692;
case 0x0c06d694u: goto P_0c06d694;
case 0x0c06d696u: goto P_0c06d696;
case 0x0c06d698u: goto P_0c06d698;
case 0x0c06d69au: goto P_0c06d69a;
case 0x0c06d69cu: goto P_0c06d69c;
case 0x0c06d69eu: goto P_0c06d69e;
case 0x0c06d6a0u: goto P_0c06d6a0;
case 0x0c06d6a2u: goto P_0c06d6a2;
case 0x0c06d6a4u: goto P_0c06d6a4;
case 0x0c06d6a6u: goto P_0c06d6a6;
case 0x0c06d6a8u: goto P_0c06d6a8;
case 0x0c06d6aau: goto P_0c06d6aa;
case 0x0c06d6acu: goto P_0c06d6ac;
case 0x0c06d6aeu: goto P_0c06d6ae;
case 0x0c06d6b0u: goto P_0c06d6b0;
case 0x0c06d6b2u: goto P_0c06d6b2;
case 0x0c06d6b4u: goto P_0c06d6b4;
case 0x0c06d6b6u: goto P_0c06d6b6;
case 0x0c06d6b8u: goto P_0c06d6b8;
case 0x0c06d6bau: goto P_0c06d6ba;
case 0x0c06d6bcu: goto P_0c06d6bc;
case 0x0c06d6beu: goto P_0c06d6be;
case 0x0c06d6c0u: goto P_0c06d6c0;
case 0x0c06d6c2u: goto P_0c06d6c2;
case 0x0c06d6c4u: goto P_0c06d6c4;
case 0x0c06d6c6u: goto P_0c06d6c6;
case 0x0c06d6c8u: goto P_0c06d6c8;
case 0x0c06d6cau: goto P_0c06d6ca;
case 0x0c06d6ccu: goto P_0c06d6cc;
case 0x0c06d6ceu: goto P_0c06d6ce;
case 0x0c06d6d0u: goto P_0c06d6d0;
case 0x0c06d6d2u: goto P_0c06d6d2;
case 0x0c06d6d4u: goto P_0c06d6d4;
case 0x0c06d6d6u: goto P_0c06d6d6;
case 0x0c06d6d8u: goto P_0c06d6d8;
case 0x0c06d6dau: goto P_0c06d6da;
case 0x0c06d6dcu: goto P_0c06d6dc;
case 0x0c06d6deu: goto P_0c06d6de;
case 0x0c06d6e0u: goto P_0c06d6e0;
case 0x0c06d6e2u: goto P_0c06d6e2;
case 0x0c06d6e4u: goto P_0c06d6e4;
case 0x0c06d6e6u: goto P_0c06d6e6;
case 0x0c06d6e8u: goto P_0c06d6e8;
case 0x0c06d6eau: goto P_0c06d6ea;
case 0x0c06d6ecu: goto P_0c06d6ec;
case 0x0c06d6eeu: goto P_0c06d6ee;
case 0x0c06d6f0u: goto P_0c06d6f0;
case 0x0c06d6f2u: goto P_0c06d6f2;
case 0x0c06d6f4u: goto P_0c06d6f4;
case 0x0c06d6f6u: goto P_0c06d6f6;
case 0x0c06d6f8u: goto P_0c06d6f8;
case 0x0c06d6fau: goto P_0c06d6fa;
case 0x0c06d6fcu: goto P_0c06d6fc;
case 0x0c06d6feu: goto P_0c06d6fe;
case 0x0c06d700u: goto P_0c06d700;
case 0x0c06d702u: goto P_0c06d702;
case 0x0c06d704u: goto P_0c06d704;
case 0x0c06d706u: goto P_0c06d706;
case 0x0c06d708u: goto P_0c06d708;
case 0x0c07e104u: goto P_0c07e104;
case 0x0c07e106u: goto P_0c07e106;
case 0x0c07e108u: goto P_0c07e108;
case 0x0c07e10au: goto P_0c07e10a;
case 0x0c07e10cu: goto P_0c07e10c;
case 0x0c07e10eu: goto P_0c07e10e;
case 0x0c07e110u: goto P_0c07e110;
case 0x0c07e112u: goto P_0c07e112;
case 0x0c07e114u: goto P_0c07e114;
case 0x0c07e116u: goto P_0c07e116;
case 0x0c07e118u: goto P_0c07e118;
case 0x0c07e11au: goto P_0c07e11a;
case 0x0c07e11cu: goto P_0c07e11c;
case 0x0c07e11eu: goto P_0c07e11e;
case 0x0c07e120u: goto P_0c07e120;
case 0x0c07e122u: goto P_0c07e122;
case 0x0c07e124u: goto P_0c07e124;
case 0x0c07e126u: goto P_0c07e126;
case 0x0c07e128u: goto P_0c07e128;
case 0x0c07e12au: goto P_0c07e12a;
case 0x0c07e12cu: goto P_0c07e12c;
case 0x0c07e12eu: goto P_0c07e12e;
case 0x0c07e130u: goto P_0c07e130;
case 0x0c07e132u: goto P_0c07e132;
case 0x0c07e134u: goto P_0c07e134;
case 0x0c07e136u: goto P_0c07e136;
case 0x0c07e138u: goto P_0c07e138;
case 0x0c07e13au: goto P_0c07e13a;
case 0x0c07e13cu: goto P_0c07e13c;
case 0x0c07e13eu: goto P_0c07e13e;
case 0x0c07e140u: goto P_0c07e140;
case 0x0c07e142u: goto P_0c07e142;
case 0x0c07e144u: goto P_0c07e144;
case 0x0c07e146u: goto P_0c07e146;
case 0x0c07e148u: goto P_0c07e148;
case 0x0c07e14au: goto P_0c07e14a;
case 0x0c07e14cu: goto P_0c07e14c;
case 0x0c07e14eu: goto P_0c07e14e;
case 0x0c07e150u: goto P_0c07e150;
case 0x0c07e152u: goto P_0c07e152;
case 0x0c07e154u: goto P_0c07e154;
case 0x0c07e156u: goto P_0c07e156;
case 0x0c07e158u: goto P_0c07e158;
case 0x0c07e15au: goto P_0c07e15a;
case 0x0c07e15cu: goto P_0c07e15c;
case 0x0c07e15eu: goto P_0c07e15e;
case 0x0c07e160u: goto P_0c07e160;
case 0x0c07e162u: goto P_0c07e162;
case 0x0c07e164u: goto P_0c07e164;
case 0x0c07e166u: goto P_0c07e166;
case 0x0c07e168u: goto P_0c07e168;
case 0x0c07e16au: goto P_0c07e16a;
case 0x0c07e16cu: goto P_0c07e16c;
case 0x0c07e16eu: goto P_0c07e16e;
case 0x0c07e170u: goto P_0c07e170;
case 0x0c07e172u: goto P_0c07e172;
case 0x0c07e174u: goto P_0c07e174;
case 0x0c07e176u: goto P_0c07e176;
case 0x0c07e178u: goto P_0c07e178;
case 0x0c07e17au: goto P_0c07e17a;
case 0x0c07e17cu: goto P_0c07e17c;
case 0x0c07e17eu: goto P_0c07e17e;
case 0x0c07e180u: goto P_0c07e180;
case 0x0c07e182u: goto P_0c07e182;
case 0x0c07e184u: goto P_0c07e184;
case 0x0c07e186u: goto P_0c07e186;
case 0x0c07e188u: goto P_0c07e188;
case 0x0c07e18au: goto P_0c07e18a;
case 0x0c07e18cu: goto P_0c07e18c;
case 0x0c07e18eu: goto P_0c07e18e;
case 0x0c07e190u: goto P_0c07e190;
case 0x0c07e192u: goto P_0c07e192;
case 0x0c07e194u: goto P_0c07e194;
case 0x0c0806e4u: goto P_0c0806e4;
case 0x0c0806e6u: goto P_0c0806e6;
case 0x0c0806e8u: goto P_0c0806e8;
case 0x0c0806eau: goto P_0c0806ea;
case 0x0c0806ecu: goto P_0c0806ec;
case 0x0c0806eeu: goto P_0c0806ee;
case 0x0c0806f0u: goto P_0c0806f0;
case 0x0c0806f2u: goto P_0c0806f2;
case 0x0c0806f4u: goto P_0c0806f4;
case 0x0c0806f6u: goto P_0c0806f6;
case 0x0c0806f8u: goto P_0c0806f8;
case 0x0c0806fau: goto P_0c0806fa;
case 0x0c0806fcu: goto P_0c0806fc;
case 0x0c0806feu: goto P_0c0806fe;
case 0x0c080700u: goto P_0c080700;
case 0x0c080702u: goto P_0c080702;
case 0x0c080704u: goto P_0c080704;
case 0x0c080706u: goto P_0c080706;
case 0x0c080708u: goto P_0c080708;
case 0x0c08070au: goto P_0c08070a;
case 0x0c08070cu: goto P_0c08070c;
case 0x0c08070eu: goto P_0c08070e;
case 0x0c080710u: goto P_0c080710;
case 0x0c080712u: goto P_0c080712;
case 0x0c080714u: goto P_0c080714;
case 0x0c080716u: goto P_0c080716;
case 0x0c080718u: goto P_0c080718;
case 0x0c08071au: goto P_0c08071a;
case 0x0c08071cu: goto P_0c08071c;
case 0x0c08071eu: goto P_0c08071e;
case 0x0c080720u: goto P_0c080720;
case 0x0c080722u: goto P_0c080722;
case 0x0c080724u: goto P_0c080724;
case 0x0c080726u: goto P_0c080726;
case 0x0c080728u: goto P_0c080728;
case 0x0c08072au: goto P_0c08072a;
case 0x0c08072cu: goto P_0c08072c;
case 0x0c08072eu: goto P_0c08072e;
case 0x0c080730u: goto P_0c080730;
case 0x0c080732u: goto P_0c080732;
case 0x0c080734u: goto P_0c080734;
case 0x0c080736u: goto P_0c080736;
case 0x0c080738u: goto P_0c080738;
case 0x0c08073au: goto P_0c08073a;
case 0x0c08073cu: goto P_0c08073c;
case 0x0c08073eu: goto P_0c08073e;
case 0x0c080740u: goto P_0c080740;
case 0x0c080742u: goto P_0c080742;
case 0x0c080744u: goto P_0c080744;
case 0x0c080746u: goto P_0c080746;
case 0x0c080748u: goto P_0c080748;
case 0x0c08074au: goto P_0c08074a;
case 0x0c08074cu: goto P_0c08074c;
case 0x0c08074eu: goto P_0c08074e;
case 0x0c080750u: goto P_0c080750;
case 0x0c080752u: goto P_0c080752;
case 0x0c080754u: goto P_0c080754;
case 0x0c080756u: goto P_0c080756;
case 0x0c080758u: goto P_0c080758;
case 0x0c08075au: goto P_0c08075a;
case 0x0c08075cu: goto P_0c08075c;
case 0x0c08075eu: goto P_0c08075e;
case 0x0c080760u: goto P_0c080760;
case 0x0c080762u: goto P_0c080762;
case 0x0c080764u: goto P_0c080764;
case 0x0c080766u: goto P_0c080766;
case 0x0c080768u: goto P_0c080768;
case 0x0c08076au: goto P_0c08076a;
case 0x0c080d2cu: goto P_0c080d2c;
case 0x0c080d2eu: goto P_0c080d2e;
case 0x0c080d30u: goto P_0c080d30;
case 0x0c080d32u: goto P_0c080d32;
case 0x0c080d34u: goto P_0c080d34;
case 0x0c080d36u: goto P_0c080d36;
case 0x0c080d38u: goto P_0c080d38;
case 0x0c080d3au: goto P_0c080d3a;
case 0x0c080d3cu: goto P_0c080d3c;
case 0x0c080d3eu: goto P_0c080d3e;
case 0x0c080d40u: goto P_0c080d40;
case 0x0c080d42u: goto P_0c080d42;
case 0x0c080d44u: goto P_0c080d44;
case 0x0c080d46u: goto P_0c080d46;
case 0x0c080d48u: goto P_0c080d48;
case 0x0c080d4au: goto P_0c080d4a;
case 0x0c080d4cu: goto P_0c080d4c;
case 0x0c080d4eu: goto P_0c080d4e;
case 0x0c080d50u: goto P_0c080d50;
case 0x0c080d52u: goto P_0c080d52;
case 0x0c080d54u: goto P_0c080d54;
case 0x0c080d56u: goto P_0c080d56;
case 0x0c080d58u: goto P_0c080d58;
case 0x0c080d5au: goto P_0c080d5a;
case 0x0c080d5cu: goto P_0c080d5c;
case 0x0c080d5eu: goto P_0c080d5e;
case 0x0c080d60u: goto P_0c080d60;
case 0x0c080d62u: goto P_0c080d62;
case 0x0c080d64u: goto P_0c080d64;
case 0x0c080d66u: goto P_0c080d66;
case 0x0c080d68u: goto P_0c080d68;
case 0x0c080d6au: goto P_0c080d6a;
case 0x0c080d6cu: goto P_0c080d6c;
case 0x0c080d6eu: goto P_0c080d6e;
case 0x0c080d70u: goto P_0c080d70;
case 0x0c080d72u: goto P_0c080d72;
case 0x0c080d74u: goto P_0c080d74;
case 0x0c080d76u: goto P_0c080d76;
case 0x0c080d78u: goto P_0c080d78;
case 0x0c080d7au: goto P_0c080d7a;
case 0x0c080d7cu: goto P_0c080d7c;
case 0x0c080d7eu: goto P_0c080d7e;
case 0x0c080d80u: goto P_0c080d80;
case 0x0c080d82u: goto P_0c080d82;
case 0x0c080d84u: goto P_0c080d84;
case 0x0c080d86u: goto P_0c080d86;
case 0x0c080d88u: goto P_0c080d88;
case 0x0c080d8au: goto P_0c080d8a;
case 0x0c080d8cu: goto P_0c080d8c;
case 0x0c080d8eu: goto P_0c080d8e;
case 0x0c080d90u: goto P_0c080d90;
case 0x0c080d92u: goto P_0c080d92;
case 0x0c080d94u: goto P_0c080d94;
case 0x0c080d96u: goto P_0c080d96;
case 0x0c080d98u: goto P_0c080d98;
case 0x0c080d9au: goto P_0c080d9a;
case 0x0c080d9cu: goto P_0c080d9c;
case 0x0c080d9eu: goto P_0c080d9e;
case 0x0c080da0u: goto P_0c080da0;
case 0x0c080da2u: goto P_0c080da2;
case 0x0c080da4u: goto P_0c080da4;
case 0x0c080da6u: goto P_0c080da6;
case 0x0c080da8u: goto P_0c080da8;
case 0x0c080daau: goto P_0c080daa;
case 0x0c080dacu: goto P_0c080dac;
case 0x0c080daeu: goto P_0c080dae;
case 0x0c080db0u: goto P_0c080db0;
case 0x0c080db2u: goto P_0c080db2;
case 0x0c080db4u: goto P_0c080db4;
case 0x0c080db6u: goto P_0c080db6;
case 0x0c080db8u: goto P_0c080db8;
case 0x0c080dbau: goto P_0c080dba;
case 0x0c080dbcu: goto P_0c080dbc;
case 0x0c080dbeu: goto P_0c080dbe;
case 0x0c080dc0u: goto P_0c080dc0;
case 0x0c080dc2u: goto P_0c080dc2;
case 0x0c080dc4u: goto P_0c080dc4;
case 0x0c080dc6u: goto P_0c080dc6;
case 0x0c080dc8u: goto P_0c080dc8;
case 0x0c080dcau: goto P_0c080dca;
case 0x0c080dccu: goto P_0c080dcc;
case 0x0c080dceu: goto P_0c080dce;
case 0x0c080dd0u: goto P_0c080dd0;
case 0x0c080dd2u: goto P_0c080dd2;
case 0x0c080dd4u: goto P_0c080dd4;
case 0x0c080dd6u: goto P_0c080dd6;
case 0x0c080dd8u: goto P_0c080dd8;
case 0x0c080ddau: goto P_0c080dda;
case 0x0c080ddcu: goto P_0c080ddc;
case 0x0c089c9cu: goto P_0c089c9c;
case 0x0c089c9eu: goto P_0c089c9e;
case 0x0c089ca0u: goto P_0c089ca0;
case 0x0c089ca2u: goto P_0c089ca2;
case 0x0c089ca4u: goto P_0c089ca4;
case 0x0c089ca6u: goto P_0c089ca6;
case 0x0c089ca8u: goto P_0c089ca8;
case 0x0c089caau: goto P_0c089caa;
case 0x0c089cacu: goto P_0c089cac;
case 0x0c089caeu: goto P_0c089cae;
case 0x0c089cb0u: goto P_0c089cb0;
case 0x0c089cb2u: goto P_0c089cb2;
case 0x0c089cb4u: goto P_0c089cb4;
case 0x0c089cb6u: goto P_0c089cb6;
case 0x0c089cb8u: goto P_0c089cb8;
case 0x0c089cbau: goto P_0c089cba;
case 0x0c089cbcu: goto P_0c089cbc;
case 0x0c089cbeu: goto P_0c089cbe;
case 0x0c089cc0u: goto P_0c089cc0;
case 0x0c089cc2u: goto P_0c089cc2;
case 0x0c089cc4u: goto P_0c089cc4;
case 0x0c089cc6u: goto P_0c089cc6;
case 0x0c089cc8u: goto P_0c089cc8;
case 0x0c089ccau: goto P_0c089cca;
case 0x0c089cccu: goto P_0c089ccc;
case 0x0c089cceu: goto P_0c089cce;
case 0x0c089cd0u: goto P_0c089cd0;
case 0x0c089cd2u: goto P_0c089cd2;
case 0x0c089cd4u: goto P_0c089cd4;
case 0x0c089cd6u: goto P_0c089cd6;
case 0x0c089cd8u: goto P_0c089cd8;
case 0x0c089cdau: goto P_0c089cda;
case 0x0c089cdcu: goto P_0c089cdc;
case 0x0c089cdeu: goto P_0c089cde;
case 0x0c089ce0u: goto P_0c089ce0;
case 0x0c089ce2u: goto P_0c089ce2;
case 0x0c089ce4u: goto P_0c089ce4;
case 0x0c089ce6u: goto P_0c089ce6;
case 0x0c089ce8u: goto P_0c089ce8;
case 0x0c089ceau: goto P_0c089cea;
case 0x0c089cecu: goto P_0c089cec;
case 0x0c089ceeu: goto P_0c089cee;
case 0x0c089cf0u: goto P_0c089cf0;
case 0x0c089cf2u: goto P_0c089cf2;
case 0x0c089cf4u: goto P_0c089cf4;
case 0x0c089cf6u: goto P_0c089cf6;
case 0x0c089cf8u: goto P_0c089cf8;
case 0x0c089cfau: goto P_0c089cfa;
case 0x0c089cfcu: goto P_0c089cfc;
case 0x0c089cfeu: goto P_0c089cfe;
case 0x0c089d00u: goto P_0c089d00;
case 0x0c089d02u: goto P_0c089d02;
case 0x0c089d04u: goto P_0c089d04;
case 0x0c089d06u: goto P_0c089d06;
case 0x0c089d08u: goto P_0c089d08;
case 0x0c089d0au: goto P_0c089d0a;
case 0x0c089d0cu: goto P_0c089d0c;
case 0x0c089d0eu: goto P_0c089d0e;
case 0x0c089d10u: goto P_0c089d10;
case 0x0c089d12u: goto P_0c089d12;
case 0x0c089d14u: goto P_0c089d14;
case 0x0c089d16u: goto P_0c089d16;
case 0x0c089d18u: goto P_0c089d18;
case 0x0c089d1au: goto P_0c089d1a;
case 0x0c089d1cu: goto P_0c089d1c;
case 0x0c089d1eu: goto P_0c089d1e;
case 0x0c089d20u: goto P_0c089d20;
case 0x0c089d22u: goto P_0c089d22;
case 0x0c089d24u: goto P_0c089d24;
case 0x0c089d26u: goto P_0c089d26;
case 0x0c0aca18u: goto P_0c0aca18;
case 0x0c0aca1au: goto P_0c0aca1a;
case 0x0c0aca1cu: goto P_0c0aca1c;
case 0x0c0aca1eu: goto P_0c0aca1e;
case 0x0c0aca20u: goto P_0c0aca20;
case 0x0c0aca22u: goto P_0c0aca22;
case 0x0c0aca24u: goto P_0c0aca24;
case 0x0c0aca26u: goto P_0c0aca26;
case 0x0c0aca28u: goto P_0c0aca28;
case 0x0c0aca2au: goto P_0c0aca2a;
case 0x0c0aca2cu: goto P_0c0aca2c;
case 0x0c0aca2eu: goto P_0c0aca2e;
case 0x0c0aca30u: goto P_0c0aca30;
case 0x0c0aca32u: goto P_0c0aca32;
case 0x0c0aca34u: goto P_0c0aca34;
case 0x0c0aca36u: goto P_0c0aca36;
case 0x0c0aca38u: goto P_0c0aca38;
case 0x0c0aca3au: goto P_0c0aca3a;
case 0x0c0aca3cu: goto P_0c0aca3c;
case 0x0c0aca3eu: goto P_0c0aca3e;
case 0x0c0aca40u: goto P_0c0aca40;
case 0x0c0aca42u: goto P_0c0aca42;
case 0x0c0aca44u: goto P_0c0aca44;
case 0x0c0aca46u: goto P_0c0aca46;
case 0x0c0aca48u: goto P_0c0aca48;
case 0x0c0aca4au: goto P_0c0aca4a;
case 0x0c0aca4cu: goto P_0c0aca4c;
case 0x0c0aca4eu: goto P_0c0aca4e;
case 0x0c0aca50u: goto P_0c0aca50;
case 0x0c0aca52u: goto P_0c0aca52;
case 0x0c0aca54u: goto P_0c0aca54;
case 0x0c0aca56u: goto P_0c0aca56;
case 0x0c0aca58u: goto P_0c0aca58;
case 0x0c0aca5au: goto P_0c0aca5a;
case 0x0c0aca5cu: goto P_0c0aca5c;
case 0x0c0aca5eu: goto P_0c0aca5e;
case 0x0c0aca60u: goto P_0c0aca60;
case 0x0c0aca62u: goto P_0c0aca62;
case 0x0c0aca64u: goto P_0c0aca64;
case 0x0c0aca66u: goto P_0c0aca66;
case 0x0c0aca68u: goto P_0c0aca68;
case 0x0c0aca6au: goto P_0c0aca6a;
case 0x0c0aca6cu: goto P_0c0aca6c;
case 0x0c0acf68u: goto P_0c0acf68;
case 0x0c0acf6au: goto P_0c0acf6a;
case 0x0c0acf6cu: goto P_0c0acf6c;
case 0x0c0acf6eu: goto P_0c0acf6e;
case 0x0c0acf70u: goto P_0c0acf70;
case 0x0c0acf72u: goto P_0c0acf72;
case 0x0c0acf74u: goto P_0c0acf74;
case 0x0c0acf76u: goto P_0c0acf76;
case 0x0c0acf78u: goto P_0c0acf78;
case 0x0c0acf7au: goto P_0c0acf7a;
case 0x0c0acf7cu: goto P_0c0acf7c;
case 0x0c0acf7eu: goto P_0c0acf7e;
case 0x0c0acf80u: goto P_0c0acf80;
case 0x0c0acf82u: goto P_0c0acf82;
case 0x0c0acf84u: goto P_0c0acf84;
case 0x0c0acf86u: goto P_0c0acf86;
case 0x0c0acf88u: goto P_0c0acf88;
case 0x0c0acf8au: goto P_0c0acf8a;
case 0x0c0acf8cu: goto P_0c0acf8c;
case 0x0c0acf8eu: goto P_0c0acf8e;
case 0x0c0acf90u: goto P_0c0acf90;
case 0x0c0acf92u: goto P_0c0acf92;
case 0x0c0acf94u: goto P_0c0acf94;
case 0x0c0acf96u: goto P_0c0acf96;
case 0x0c0acf98u: goto P_0c0acf98;
case 0x0c0acf9au: goto P_0c0acf9a;
case 0x0c0acf9cu: goto P_0c0acf9c;
case 0x0c0acf9eu: goto P_0c0acf9e;
case 0x0c0acfa0u: goto P_0c0acfa0;
case 0x0c0acfa2u: goto P_0c0acfa2;
case 0x0c0acfa4u: goto P_0c0acfa4;
case 0x0c0acfa6u: goto P_0c0acfa6;
case 0x0c0acfa8u: goto P_0c0acfa8;
case 0x0c0acfaau: goto P_0c0acfaa;
case 0x0c0acfacu: goto P_0c0acfac;
case 0x0c0acfaeu: goto P_0c0acfae;
case 0x0c0acfb0u: goto P_0c0acfb0;
case 0x0c0acfb2u: goto P_0c0acfb2;
case 0x0c0acfb4u: goto P_0c0acfb4;
case 0x0c0acfb6u: goto P_0c0acfb6;
case 0x0c0acfb8u: goto P_0c0acfb8;
case 0x0c0acfbau: goto P_0c0acfba;
case 0x0c0acfbcu: goto P_0c0acfbc;
case 0x0c0acfbeu: goto P_0c0acfbe;
case 0x0c0acfc0u: goto P_0c0acfc0;
case 0x0c0acfc2u: goto P_0c0acfc2;
case 0x0c0acfc4u: goto P_0c0acfc4;
case 0x0c0acfc6u: goto P_0c0acfc6;
case 0x0c0acfc8u: goto P_0c0acfc8;
case 0x0c0acfcau: goto P_0c0acfca;
case 0x0c0acfccu: goto P_0c0acfcc;
case 0x0c0acfceu: goto P_0c0acfce;
case 0x0c0acfd0u: goto P_0c0acfd0;
case 0x0c0acfd2u: goto P_0c0acfd2;
case 0x0c0acfd4u: goto P_0c0acfd4;
case 0x0c0acfd6u: goto P_0c0acfd6;
case 0x0c0acfd8u: goto P_0c0acfd8;
case 0x0c0acfdau: goto P_0c0acfda;
case 0x0c0acfdcu: goto P_0c0acfdc;
case 0x0c0acfdeu: goto P_0c0acfde;
case 0x0c0acfe0u: goto P_0c0acfe0;
case 0x0c0acfe2u: goto P_0c0acfe2;
case 0x0c0acfe4u: goto P_0c0acfe4;
case 0x0c0acfe6u: goto P_0c0acfe6;
case 0x0c0acfe8u: goto P_0c0acfe8;
case 0x0c0acfeau: goto P_0c0acfea;
case 0x0c0acfecu: goto P_0c0acfec;
case 0x0c0acfeeu: goto P_0c0acfee;
case 0x0c0acff0u: goto P_0c0acff0;
case 0x0c0acff2u: goto P_0c0acff2;
case 0x0c0acff4u: goto P_0c0acff4;
case 0x0c0acff6u: goto P_0c0acff6;
case 0x0c0acff8u: goto P_0c0acff8;
case 0x0c0c4d2cu: goto P_0c0c4d2c;
case 0x0c0c4d2eu: goto P_0c0c4d2e;
case 0x0c0c4d30u: goto P_0c0c4d30;
case 0x0c0c4d32u: goto P_0c0c4d32;
case 0x0c0c4d34u: goto P_0c0c4d34;
case 0x0c0c4d36u: goto P_0c0c4d36;
case 0x0c0c4d38u: goto P_0c0c4d38;
case 0x0c0c4d3au: goto P_0c0c4d3a;
case 0x0c0c4d3cu: goto P_0c0c4d3c;
case 0x0c0c4d3eu: goto P_0c0c4d3e;
case 0x0c0c4d40u: goto P_0c0c4d40;
case 0x0c0c4d42u: goto P_0c0c4d42;
case 0x0c0c4d44u: goto P_0c0c4d44;
case 0x0c0c4d46u: goto P_0c0c4d46;
case 0x0c0c4d48u: goto P_0c0c4d48;
case 0x0c0c4d4au: goto P_0c0c4d4a;
case 0x0c0c4d4cu: goto P_0c0c4d4c;
case 0x0c0c4d4eu: goto P_0c0c4d4e;
case 0x0c0c4d50u: goto P_0c0c4d50;
case 0x0c0c4d52u: goto P_0c0c4d52;
case 0x0c0c4d54u: goto P_0c0c4d54;
case 0x0c0c4d56u: goto P_0c0c4d56;
case 0x0c0c4d58u: goto P_0c0c4d58;
case 0x0c0c4d5au: goto P_0c0c4d5a;
case 0x0c0c4d5cu: goto P_0c0c4d5c;
case 0x0c0c4d5eu: goto P_0c0c4d5e;
case 0x0c0c4d60u: goto P_0c0c4d60;
case 0x0c0c4d62u: goto P_0c0c4d62;
case 0x0c0c4d64u: goto P_0c0c4d64;
case 0x0c0c4d66u: goto P_0c0c4d66;
case 0x0c0c4d68u: goto P_0c0c4d68;
case 0x0c0c4d6au: goto P_0c0c4d6a;
case 0x0c0c4d6cu: goto P_0c0c4d6c;
case 0x0c0c4d6eu: goto P_0c0c4d6e;
case 0x0c0c4d70u: goto P_0c0c4d70;
case 0x0c0c4d72u: goto P_0c0c4d72;
case 0x0c0c4d74u: goto P_0c0c4d74;
case 0x0c0c4d76u: goto P_0c0c4d76;
case 0x0c0c4d78u: goto P_0c0c4d78;
case 0x0c0c4d7au: goto P_0c0c4d7a;
case 0x0c0c4d7cu: goto P_0c0c4d7c;
case 0x0c0c4d7eu: goto P_0c0c4d7e;
case 0x0c0c4d80u: goto P_0c0c4d80;
case 0x0c0c4d82u: goto P_0c0c4d82;
case 0x0c0c4d84u: goto P_0c0c4d84;
case 0x0c0c4d86u: goto P_0c0c4d86;
case 0x0c0c4d88u: goto P_0c0c4d88;
case 0x0c0c4d8au: goto P_0c0c4d8a;
case 0x0c0c4d8cu: goto P_0c0c4d8c;
case 0x0c0c4d8eu: goto P_0c0c4d8e;
case 0x0c0c4d90u: goto P_0c0c4d90;
case 0x0c0c4d92u: goto P_0c0c4d92;
case 0x0c0c4d94u: goto P_0c0c4d94;
case 0x0c0c4d96u: goto P_0c0c4d96;
case 0x0c0c4d98u: goto P_0c0c4d98;
case 0x0c0c4d9au: goto P_0c0c4d9a;
case 0x0c0c4d9cu: goto P_0c0c4d9c;
case 0x0c0c4d9eu: goto P_0c0c4d9e;
case 0x0c0c4da0u: goto P_0c0c4da0;
case 0x0c0c4da2u: goto P_0c0c4da2;
case 0x0c0c4da4u: goto P_0c0c4da4;
case 0x0c0c4da6u: goto P_0c0c4da6;
case 0x0c0c4da8u: goto P_0c0c4da8;
case 0x0c0c4daau: goto P_0c0c4daa;
case 0x0c0c4e4au: goto P_0c0c4e4a;
case 0x0c0c4e4cu: goto P_0c0c4e4c;
case 0x0c0c4e4eu: goto P_0c0c4e4e;
case 0x0c0c4e50u: goto P_0c0c4e50;
case 0x0c0c4e52u: goto P_0c0c4e52;
case 0x0c0c4e54u: goto P_0c0c4e54;
case 0x0c0c4e56u: goto P_0c0c4e56;
case 0x0c0c4e58u: goto P_0c0c4e58;
case 0x0c0c4e5au: goto P_0c0c4e5a;
case 0x0c0c4e5cu: goto P_0c0c4e5c;
case 0x0c0c4e5eu: goto P_0c0c4e5e;
case 0x0c0c4e60u: goto P_0c0c4e60;
case 0x0c0c4e62u: goto P_0c0c4e62;
case 0x0c0c4e64u: goto P_0c0c4e64;
case 0x0c0c4e66u: goto P_0c0c4e66;
case 0x0c0c4e68u: goto P_0c0c4e68;
case 0x0c0c4e6au: goto P_0c0c4e6a;
case 0x0c0c4e6cu: goto P_0c0c4e6c;
case 0x0c0c4e6eu: goto P_0c0c4e6e;
case 0x0c0c4e70u: goto P_0c0c4e70;
case 0x0c0c4e72u: goto P_0c0c4e72;
case 0x0c0c4e74u: goto P_0c0c4e74;
case 0x0c0c4e76u: goto P_0c0c4e76;
case 0x0c0c4e78u: goto P_0c0c4e78;
case 0x0c0c4e7au: goto P_0c0c4e7a;
case 0x0c0c4e7cu: goto P_0c0c4e7c;
case 0x0c0c4e7eu: goto P_0c0c4e7e;
case 0x0c0c4e80u: goto P_0c0c4e80;
case 0x0c0c4e82u: goto P_0c0c4e82;
case 0x0c0c4e84u: goto P_0c0c4e84;
case 0x0c0c4e86u: goto P_0c0c4e86;
case 0x0c0c4e88u: goto P_0c0c4e88;
case 0x0c0c4e8au: goto P_0c0c4e8a;
case 0x0c0c4e8cu: goto P_0c0c4e8c;
case 0x0c0c4e8eu: goto P_0c0c4e8e;
case 0x0c0c4e90u: goto P_0c0c4e90;
case 0x0c0c4e92u: goto P_0c0c4e92;
case 0x0c0c4e94u: goto P_0c0c4e94;
case 0x0c0c4e96u: goto P_0c0c4e96;
case 0x0c0c4e98u: goto P_0c0c4e98;
case 0x0c0c4e9au: goto P_0c0c4e9a;
case 0x0c0c4e9cu: goto P_0c0c4e9c;
case 0x0c0c4e9eu: goto P_0c0c4e9e;
case 0x0c0c4ea0u: goto P_0c0c4ea0;
case 0x0c0c4ea2u: goto P_0c0c4ea2;
case 0x0c0c4ea4u: goto P_0c0c4ea4;
case 0x0c0c4ea6u: goto P_0c0c4ea6;
case 0x0c0c4ea8u: goto P_0c0c4ea8;
case 0x0c0c4eaau: goto P_0c0c4eaa;
case 0x0c0c4eacu: goto P_0c0c4eac;
case 0x0c0c4eaeu: goto P_0c0c4eae;
case 0x0c0c6104u: goto P_0c0c6104;
case 0x0c0c6106u: goto P_0c0c6106;
case 0x0c0c6108u: goto P_0c0c6108;
case 0x0c0c610au: goto P_0c0c610a;
case 0x0c0c610cu: goto P_0c0c610c;
case 0x0c0c610eu: goto P_0c0c610e;
case 0x0c0c6110u: goto P_0c0c6110;
case 0x0c0c6112u: goto P_0c0c6112;
case 0x0c0c6114u: goto P_0c0c6114;
case 0x0c0c6116u: goto P_0c0c6116;
case 0x0c0c6118u: goto P_0c0c6118;
case 0x0c0c611au: goto P_0c0c611a;
case 0x0c0c611cu: goto P_0c0c611c;
case 0x0c0c611eu: goto P_0c0c611e;
case 0x0c0c6120u: goto P_0c0c6120;
case 0x0c0c6122u: goto P_0c0c6122;
case 0x0c0c6124u: goto P_0c0c6124;
case 0x0c0c6126u: goto P_0c0c6126;
case 0x0c0c6128u: goto P_0c0c6128;
case 0x0c0c612au: goto P_0c0c612a;
case 0x0c0c612cu: goto P_0c0c612c;
case 0x0c0c612eu: goto P_0c0c612e;
case 0x0c0c6130u: goto P_0c0c6130;
case 0x0c0c6132u: goto P_0c0c6132;
case 0x0c0c6134u: goto P_0c0c6134;
case 0x0c0c6136u: goto P_0c0c6136;
case 0x0c0c6138u: goto P_0c0c6138;
case 0x0c0c613au: goto P_0c0c613a;
case 0x0c0c613cu: goto P_0c0c613c;
case 0x0c0c613eu: goto P_0c0c613e;
case 0x0c0c6140u: goto P_0c0c6140;
case 0x0c0c6142u: goto P_0c0c6142;
case 0x0c0c6144u: goto P_0c0c6144;
case 0x0c0c6146u: goto P_0c0c6146;
case 0x0c0c6148u: goto P_0c0c6148;
case 0x0c0c614au: goto P_0c0c614a;
case 0x0c0c614cu: goto P_0c0c614c;
case 0x0c0c614eu: goto P_0c0c614e;
case 0x0c0c6150u: goto P_0c0c6150;
case 0x0c0c6152u: goto P_0c0c6152;
case 0x0c0c6154u: goto P_0c0c6154;
case 0x0c0c6156u: goto P_0c0c6156;
case 0x0c0c6158u: goto P_0c0c6158;
case 0x0c0c615au: goto P_0c0c615a;
case 0x0c0c615cu: goto P_0c0c615c;
case 0x0c0c615eu: goto P_0c0c615e;
case 0x0c0c6160u: goto P_0c0c6160;
case 0x0c0c6162u: goto P_0c0c6162;
case 0x0c0c6164u: goto P_0c0c6164;
case 0x0c0c6166u: goto P_0c0c6166;
case 0x0c0c6168u: goto P_0c0c6168;
case 0x0c0c616au: goto P_0c0c616a;
case 0x0c0c616cu: goto P_0c0c616c;
case 0x0c0c616eu: goto P_0c0c616e;
case 0x0c0c6170u: goto P_0c0c6170;
case 0x0c0c6172u: goto P_0c0c6172;
case 0x0c0c6174u: goto P_0c0c6174;
case 0x0c0c6176u: goto P_0c0c6176;
case 0x0c0c6178u: goto P_0c0c6178;
case 0x0c0c8274u: goto P_0c0c8274;
case 0x0c0c8276u: goto P_0c0c8276;
case 0x0c0c8278u: goto P_0c0c8278;
case 0x0c0c827au: goto P_0c0c827a;
case 0x0c0c827cu: goto P_0c0c827c;
case 0x0c0c827eu: goto P_0c0c827e;
case 0x0c0c8280u: goto P_0c0c8280;
case 0x0c0c8282u: goto P_0c0c8282;
case 0x0c0c8284u: goto P_0c0c8284;
case 0x0c0c8286u: goto P_0c0c8286;
case 0x0c0c8288u: goto P_0c0c8288;
case 0x0c0c828au: goto P_0c0c828a;
case 0x0c0c828cu: goto P_0c0c828c;
case 0x0c0c828eu: goto P_0c0c828e;
case 0x0c0c8290u: goto P_0c0c8290;
case 0x0c0c8292u: goto P_0c0c8292;
case 0x0c0c8294u: goto P_0c0c8294;
case 0x0c0c8296u: goto P_0c0c8296;
case 0x0c0c8298u: goto P_0c0c8298;
case 0x0c0c829au: goto P_0c0c829a;
case 0x0c0c829cu: goto P_0c0c829c;
case 0x0c0c829eu: goto P_0c0c829e;
case 0x0c0c82a0u: goto P_0c0c82a0;
case 0x0c0c82a2u: goto P_0c0c82a2;
case 0x0c0c82a4u: goto P_0c0c82a4;
case 0x0c0c82a6u: goto P_0c0c82a6;
case 0x0c0c82a8u: goto P_0c0c82a8;
case 0x0c0c82aau: goto P_0c0c82aa;
case 0x0c0c82acu: goto P_0c0c82ac;
case 0x0c0c82aeu: goto P_0c0c82ae;
case 0x0c0c82b0u: goto P_0c0c82b0;
case 0x0c0c82b2u: goto P_0c0c82b2;
case 0x0c0c82b4u: goto P_0c0c82b4;
case 0x0c0c82b6u: goto P_0c0c82b6;
case 0x0c0c82b8u: goto P_0c0c82b8;
case 0x0c0c82bau: goto P_0c0c82ba;
case 0x0c0c82bcu: goto P_0c0c82bc;
case 0x0c0c82beu: goto P_0c0c82be;
case 0x0c0c82c0u: goto P_0c0c82c0;
case 0x0c0c82c2u: goto P_0c0c82c2;
case 0x0c0c82c4u: goto P_0c0c82c4;
case 0x0c0c82c6u: goto P_0c0c82c6;
case 0x0c0c82c8u: goto P_0c0c82c8;
case 0x0c0c82cau: goto P_0c0c82ca;
case 0x0c0c82ccu: goto P_0c0c82cc;
case 0x0c0c82ceu: goto P_0c0c82ce;
case 0x0c0c82d0u: goto P_0c0c82d0;
case 0x0c0c82d2u: goto P_0c0c82d2;
case 0x0c0c82d4u: goto P_0c0c82d4;
case 0x0c0c82d6u: goto P_0c0c82d6;
case 0x0c0c82d8u: goto P_0c0c82d8;
case 0x0c0c82dau: goto P_0c0c82da;
case 0x0c0c82dcu: goto P_0c0c82dc;
case 0x0c0c82deu: goto P_0c0c82de;
case 0x0c0c82e0u: goto P_0c0c82e0;
case 0x0c0c82e2u: goto P_0c0c82e2;
case 0x0c0c8324u: goto P_0c0c8324;
case 0x0c0c8326u: goto P_0c0c8326;
case 0x0c0c8328u: goto P_0c0c8328;
case 0x0c0c832au: goto P_0c0c832a;
case 0x0c0c832cu: goto P_0c0c832c;
case 0x0c0c832eu: goto P_0c0c832e;
case 0x0c0c8330u: goto P_0c0c8330;
case 0x0c0c8332u: goto P_0c0c8332;
case 0x0c0c8334u: goto P_0c0c8334;
case 0x0c0c8336u: goto P_0c0c8336;
case 0x0c0c8338u: goto P_0c0c8338;
case 0x0c0c833au: goto P_0c0c833a;
case 0x0c0c833cu: goto P_0c0c833c;
case 0x0c0c833eu: goto P_0c0c833e;
case 0x0c0c8340u: goto P_0c0c8340;
case 0x0c0c8342u: goto P_0c0c8342;
case 0x0c0c8344u: goto P_0c0c8344;
case 0x0c0c8346u: goto P_0c0c8346;
case 0x0c0c8348u: goto P_0c0c8348;
case 0x0c0c834au: goto P_0c0c834a;
case 0x0c0c834cu: goto P_0c0c834c;
case 0x0c0c834eu: goto P_0c0c834e;
case 0x0c0c8350u: goto P_0c0c8350;
case 0x0c0c8352u: goto P_0c0c8352;
case 0x0c0c8354u: goto P_0c0c8354;
case 0x0c0c8356u: goto P_0c0c8356;
case 0x0c0c8358u: goto P_0c0c8358;
case 0x0c0c835au: goto P_0c0c835a;
case 0x0c0c835cu: goto P_0c0c835c;
case 0x0c0c835eu: goto P_0c0c835e;
case 0x0c0c8394u: goto P_0c0c8394;
case 0x0c0c8396u: goto P_0c0c8396;
case 0x0c0c8398u: goto P_0c0c8398;
case 0x0c0c839au: goto P_0c0c839a;
case 0x0c0c839cu: goto P_0c0c839c;
case 0x0c0c839eu: goto P_0c0c839e;
case 0x0c0c83a0u: goto P_0c0c83a0;
case 0x0c0c83a2u: goto P_0c0c83a2;
case 0x0c0c83a4u: goto P_0c0c83a4;
case 0x0c0c83a6u: goto P_0c0c83a6;
case 0x0c0c83a8u: goto P_0c0c83a8;
case 0x0c0c83aau: goto P_0c0c83aa;
case 0x0c0c83acu: goto P_0c0c83ac;
case 0x0c0c83aeu: goto P_0c0c83ae;
case 0x0c0c83b0u: goto P_0c0c83b0;
case 0x0c0c83b2u: goto P_0c0c83b2;
case 0x0c0c83b4u: goto P_0c0c83b4;
case 0x0c0c83b6u: goto P_0c0c83b6;
case 0x0c0c83b8u: goto P_0c0c83b8;
case 0x0c0c83bau: goto P_0c0c83ba;
case 0x0c0c83bcu: goto P_0c0c83bc;
case 0x0c0c83beu: goto P_0c0c83be;
case 0x0c0c83c0u: goto P_0c0c83c0;
case 0x0c0c83c2u: goto P_0c0c83c2;
case 0x0c0c83c4u: goto P_0c0c83c4;
case 0x0c0c83c6u: goto P_0c0c83c6;
case 0x0c0c83c8u: goto P_0c0c83c8;
case 0x0c0c83cau: goto P_0c0c83ca;
case 0x0c0c83ccu: goto P_0c0c83cc;
case 0x0c0c83ceu: goto P_0c0c83ce;
case 0x0c0c83d0u: goto P_0c0c83d0;
case 0x0c0c83d2u: goto P_0c0c83d2;
case 0x0c0c83d4u: goto P_0c0c83d4;
case 0x0c0c83d6u: goto P_0c0c83d6;
case 0x0c0c83d8u: goto P_0c0c83d8;
case 0x0c0c83dau: goto P_0c0c83da;
case 0x0c0c83dcu: goto P_0c0c83dc;
case 0x0c0c83deu: goto P_0c0c83de;
case 0x0c0c83e0u: goto P_0c0c83e0;
case 0x0c0c83e2u: goto P_0c0c83e2;
case 0x0c0c83e4u: goto P_0c0c83e4;
case 0x0c0c83e6u: goto P_0c0c83e6;
case 0x0c0c83e8u: goto P_0c0c83e8;
case 0x0c0c83eau: goto P_0c0c83ea;
case 0x0c0c83ecu: goto P_0c0c83ec;
case 0x0c0c83eeu: goto P_0c0c83ee;
case 0x0c0c83f0u: goto P_0c0c83f0;
case 0x0c0c83f2u: goto P_0c0c83f2;
case 0x0c0c83f4u: goto P_0c0c83f4;
case 0x0c0c83f6u: goto P_0c0c83f6;
case 0x0c0c83f8u: goto P_0c0c83f8;
case 0x0c0c83fau: goto P_0c0c83fa;
case 0x0c0c83fcu: goto P_0c0c83fc;
case 0x0c0c83feu: goto P_0c0c83fe;
case 0x0c0c8400u: goto P_0c0c8400;
case 0x0c0c8402u: goto P_0c0c8402;
case 0x0c0c8404u: goto P_0c0c8404;
case 0x0c0c8406u: goto P_0c0c8406;
case 0x0c0c8408u: goto P_0c0c8408;
case 0x0c0c840au: goto P_0c0c840a;
case 0x0c0c840cu: goto P_0c0c840c;
case 0x0c0c840eu: goto P_0c0c840e;
case 0x0c0c8410u: goto P_0c0c8410;
case 0x0c0c8412u: goto P_0c0c8412;
case 0x0c0c8414u: goto P_0c0c8414;
case 0x0c0c8416u: goto P_0c0c8416;
case 0x0c0c8418u: goto P_0c0c8418;
case 0x0c0c841au: goto P_0c0c841a;
case 0x0c0c841cu: goto P_0c0c841c;
case 0x0c0c841eu: goto P_0c0c841e;
case 0x0c0c8420u: goto P_0c0c8420;
case 0x0c0c8422u: goto P_0c0c8422;
case 0x0c0c8424u: goto P_0c0c8424;
case 0x0c0c8426u: goto P_0c0c8426;
case 0x0c0c8428u: goto P_0c0c8428;
case 0x0c0c842au: goto P_0c0c842a;
case 0x0c0c842cu: goto P_0c0c842c;
case 0x0c0c842eu: goto P_0c0c842e;
case 0x0c0c8430u: goto P_0c0c8430;
case 0x0c0c8432u: goto P_0c0c8432;
case 0x0c0c8434u: goto P_0c0c8434;
case 0x0c0c8436u: goto P_0c0c8436;
case 0x0c0c8438u: goto P_0c0c8438;
case 0x0c0c843au: goto P_0c0c843a;
case 0x0c0c843cu: goto P_0c0c843c;
case 0x0c0c843eu: goto P_0c0c843e;
case 0x0c0c8440u: goto P_0c0c8440;
case 0x0c0c8442u: goto P_0c0c8442;
case 0x0c0c8444u: goto P_0c0c8444;
case 0x0c0c8446u: goto P_0c0c8446;
case 0x0c0c8448u: goto P_0c0c8448;
case 0x0c0c844au: goto P_0c0c844a;
case 0x0c0c844cu: goto P_0c0c844c;
case 0x0c0c844eu: goto P_0c0c844e;
case 0x0c0c8450u: goto P_0c0c8450;
case 0x0c0c8452u: goto P_0c0c8452;
case 0x0c0c8454u: goto P_0c0c8454;
case 0x0c0c8456u: goto P_0c0c8456;
case 0x0c0c8458u: goto P_0c0c8458;
case 0x0c0c845au: goto P_0c0c845a;
case 0x0c0c845cu: goto P_0c0c845c;
case 0x0c0c845eu: goto P_0c0c845e;
case 0x0c0c8460u: goto P_0c0c8460;
case 0x0c0c8462u: goto P_0c0c8462;
case 0x0c0c8464u: goto P_0c0c8464;
case 0x0c0c8466u: goto P_0c0c8466;
case 0x0c0c8468u: goto P_0c0c8468;
case 0x0c0c846au: goto P_0c0c846a;
case 0x0c0c846cu: goto P_0c0c846c;
case 0x0c0c846eu: goto P_0c0c846e;
case 0x0c0c8470u: goto P_0c0c8470;
case 0x0c0c8472u: goto P_0c0c8472;
case 0x0c0c8494u: goto P_0c0c8494;
case 0x0c0c8496u: goto P_0c0c8496;
case 0x0c0c8498u: goto P_0c0c8498;
case 0x0c0c849au: goto P_0c0c849a;
case 0x0c0c849cu: goto P_0c0c849c;
case 0x0c0c849eu: goto P_0c0c849e;
case 0x0c0c84a0u: goto P_0c0c84a0;
case 0x0c0c84a2u: goto P_0c0c84a2;
case 0x0c0c84a4u: goto P_0c0c84a4;
case 0x0c0c84a6u: goto P_0c0c84a6;
case 0x0c0c84a8u: goto P_0c0c84a8;
case 0x0c0c84aau: goto P_0c0c84aa;
case 0x0c0c84acu: goto P_0c0c84ac;
case 0x0c0c84aeu: goto P_0c0c84ae;
case 0x0c0c84b0u: goto P_0c0c84b0;
case 0x0c0c84b2u: goto P_0c0c84b2;
case 0x0c0c84b4u: goto P_0c0c84b4;
case 0x0c0c84b6u: goto P_0c0c84b6;
case 0x0c0c84b8u: goto P_0c0c84b8;
case 0x0c0c84bau: goto P_0c0c84ba;
case 0x0c0c84bcu: goto P_0c0c84bc;
case 0x0c0c84beu: goto P_0c0c84be;
case 0x0c0c84c0u: goto P_0c0c84c0;
case 0x0c0c84c2u: goto P_0c0c84c2;
case 0x0c0c84c4u: goto P_0c0c84c4;
case 0x0c0c84c6u: goto P_0c0c84c6;
case 0x0c0c84c8u: goto P_0c0c84c8;
case 0x0c0c84cau: goto P_0c0c84ca;
case 0x0c0c84ccu: goto P_0c0c84cc;
case 0x0c0c84ceu: goto P_0c0c84ce;
case 0x0c0c84d0u: goto P_0c0c84d0;
case 0x0c0c84d2u: goto P_0c0c84d2;
case 0x0c0c84d4u: goto P_0c0c84d4;
case 0x0c0c84d6u: goto P_0c0c84d6;
case 0x0c0c84d8u: goto P_0c0c84d8;
case 0x0c0c84dau: goto P_0c0c84da;
case 0x0c0c84dcu: goto P_0c0c84dc;
case 0x0c0c84deu: goto P_0c0c84de;
case 0x0c0c84e0u: goto P_0c0c84e0;
case 0x0c0c84e2u: goto P_0c0c84e2;
case 0x0c0c84e4u: goto P_0c0c84e4;
case 0x0c0c84e6u: goto P_0c0c84e6;
case 0x0c0c84e8u: goto P_0c0c84e8;
case 0x0c0c84eau: goto P_0c0c84ea;
case 0x0c0c84ecu: goto P_0c0c84ec;
case 0x0c0c84eeu: goto P_0c0c84ee;
case 0x0c0c84f0u: goto P_0c0c84f0;
case 0x0c0c84f2u: goto P_0c0c84f2;
case 0x0c0c84f4u: goto P_0c0c84f4;
case 0x0c0c84f6u: goto P_0c0c84f6;
case 0x0c0c84f8u: goto P_0c0c84f8;
case 0x0c0c84fau: goto P_0c0c84fa;
case 0x0c0c84fcu: goto P_0c0c84fc;
case 0x0c0c84feu: goto P_0c0c84fe;
case 0x0c0c8500u: goto P_0c0c8500;
case 0x0c0c8502u: goto P_0c0c8502;
case 0x0c0c8504u: goto P_0c0c8504;
case 0x0c0c8506u: goto P_0c0c8506;
case 0x0c0c8508u: goto P_0c0c8508;
case 0x0c0c850au: goto P_0c0c850a;
case 0x0c0c850cu: goto P_0c0c850c;
case 0x0c0c850eu: goto P_0c0c850e;
case 0x0c0c8510u: goto P_0c0c8510;
case 0x0c0c8512u: goto P_0c0c8512;
case 0x0c0c8514u: goto P_0c0c8514;
case 0x0c0c8516u: goto P_0c0c8516;
case 0x0c0c8518u: goto P_0c0c8518;
case 0x0c0c851au: goto P_0c0c851a;
case 0x0c0c851cu: goto P_0c0c851c;
case 0x0c0c851eu: goto P_0c0c851e;
case 0x0c0c8520u: goto P_0c0c8520;
case 0x0c0c8522u: goto P_0c0c8522;
case 0x0c0c8524u: goto P_0c0c8524;
case 0x0c0c8526u: goto P_0c0c8526;
case 0x0c0c8528u: goto P_0c0c8528;
case 0x0c0c852au: goto P_0c0c852a;
case 0x0c0c852cu: goto P_0c0c852c;
case 0x0c0c852eu: goto P_0c0c852e;
case 0x0c0c8530u: goto P_0c0c8530;
case 0x0c0c8532u: goto P_0c0c8532;
case 0x0c0c8534u: goto P_0c0c8534;
case 0x0c0c8536u: goto P_0c0c8536;
case 0x0c0c8538u: goto P_0c0c8538;
case 0x0c0c853au: goto P_0c0c853a;
case 0x0c0c853cu: goto P_0c0c853c;
case 0x0c0c853eu: goto P_0c0c853e;
case 0x0c0c8540u: goto P_0c0c8540;
case 0x0c0c8542u: goto P_0c0c8542;
case 0x0c0c8544u: goto P_0c0c8544;
case 0x0c0c8546u: goto P_0c0c8546;
case 0x0c0c8548u: goto P_0c0c8548;
case 0x0c0c854au: goto P_0c0c854a;
case 0x0c0c854cu: goto P_0c0c854c;
case 0x0c0c854eu: goto P_0c0c854e;
case 0x0c0c8550u: goto P_0c0c8550;
case 0x0c0c8552u: goto P_0c0c8552;
case 0x0c0c8554u: goto P_0c0c8554;
case 0x0c0c8574u: goto P_0c0c8574;
case 0x0c0c8576u: goto P_0c0c8576;
case 0x0c0c8578u: goto P_0c0c8578;
case 0x0c0c857au: goto P_0c0c857a;
case 0x0c0c857cu: goto P_0c0c857c;
case 0x0c0c857eu: goto P_0c0c857e;
case 0x0c0c8580u: goto P_0c0c8580;
case 0x0c0c8582u: goto P_0c0c8582;
case 0x0c0c8584u: goto P_0c0c8584;
case 0x0c0c8586u: goto P_0c0c8586;
case 0x0c0c8588u: goto P_0c0c8588;
case 0x0c0c858au: goto P_0c0c858a;
case 0x0c0c858cu: goto P_0c0c858c;
case 0x0c0c858eu: goto P_0c0c858e;
case 0x0c0c8590u: goto P_0c0c8590;
case 0x0c0c8592u: goto P_0c0c8592;
case 0x0c0c8594u: goto P_0c0c8594;
case 0x0c0c8596u: goto P_0c0c8596;
case 0x0c0c8598u: goto P_0c0c8598;
case 0x0c0c859au: goto P_0c0c859a;
case 0x0c0c859cu: goto P_0c0c859c;
case 0x0c0c859eu: goto P_0c0c859e;
case 0x0c0c85a0u: goto P_0c0c85a0;
case 0x0c0c85a2u: goto P_0c0c85a2;
case 0x0c0c85a4u: goto P_0c0c85a4;
case 0x0c0c85a6u: goto P_0c0c85a6;
case 0x0c0c85a8u: goto P_0c0c85a8;
case 0x0c0c85aau: goto P_0c0c85aa;
case 0x0c0c85acu: goto P_0c0c85ac;
case 0x0c0c85aeu: goto P_0c0c85ae;
case 0x0c0c85b0u: goto P_0c0c85b0;
case 0x0c0c85b2u: goto P_0c0c85b2;
case 0x0c0c85b4u: goto P_0c0c85b4;
case 0x0c0c85b6u: goto P_0c0c85b6;
case 0x0c0c85b8u: goto P_0c0c85b8;
case 0x0c0c85bau: goto P_0c0c85ba;
case 0x0c0c85bcu: goto P_0c0c85bc;
case 0x0c0c85beu: goto P_0c0c85be;
case 0x0c0c85c0u: goto P_0c0c85c0;
case 0x0c0c85c2u: goto P_0c0c85c2;
case 0x0c0c85c4u: goto P_0c0c85c4;
case 0x0c0c85c6u: goto P_0c0c85c6;
case 0x0c0c85c8u: goto P_0c0c85c8;
case 0x0c0c85cau: goto P_0c0c85ca;
case 0x0c0c85ccu: goto P_0c0c85cc;
case 0x0c0c85ceu: goto P_0c0c85ce;
case 0x0c0c85d0u: goto P_0c0c85d0;
case 0x0c0c85d2u: goto P_0c0c85d2;
case 0x0c0c85d4u: goto P_0c0c85d4;
case 0x0c0c85d6u: goto P_0c0c85d6;
case 0x0c0c85d8u: goto P_0c0c85d8;
case 0x0c0c85dau: goto P_0c0c85da;
case 0x0c0c85dcu: goto P_0c0c85dc;
case 0x0c0c85deu: goto P_0c0c85de;
case 0x0c0c85e0u: goto P_0c0c85e0;
case 0x0c0c85e2u: goto P_0c0c85e2;
case 0x0c0c85e4u: goto P_0c0c85e4;
case 0x0c0c85e6u: goto P_0c0c85e6;
case 0x0c0c85e8u: goto P_0c0c85e8;
case 0x0c0c85eau: goto P_0c0c85ea;
case 0x0c0c85ecu: goto P_0c0c85ec;
case 0x0c0c85eeu: goto P_0c0c85ee;
case 0x0c0c85f0u: goto P_0c0c85f0;
case 0x0c0c85f2u: goto P_0c0c85f2;
case 0x0c0c85f4u: goto P_0c0c85f4;
case 0x0c0c85f6u: goto P_0c0c85f6;
case 0x0c0c85f8u: goto P_0c0c85f8;
case 0x0c0c85fau: goto P_0c0c85fa;
case 0x0c0c85fcu: goto P_0c0c85fc;
case 0x0c0c85feu: goto P_0c0c85fe;
case 0x0c0c8600u: goto P_0c0c8600;
case 0x0c0c8602u: goto P_0c0c8602;
case 0x0c0c8604u: goto P_0c0c8604;
case 0x0c0c8606u: goto P_0c0c8606;
case 0x0c0c8608u: goto P_0c0c8608;
case 0x0c0c860au: goto P_0c0c860a;
case 0x0c0c860cu: goto P_0c0c860c;
case 0x0c0c860eu: goto P_0c0c860e;
case 0x0c0c8610u: goto P_0c0c8610;
case 0x0c0c8612u: goto P_0c0c8612;
case 0x0c0c8614u: goto P_0c0c8614;
case 0x0c0c8616u: goto P_0c0c8616;
case 0x0c0c8618u: goto P_0c0c8618;
case 0x0c0c861au: goto P_0c0c861a;
case 0x0c0c861cu: goto P_0c0c861c;
case 0x0c0c861eu: goto P_0c0c861e;
case 0x0c0c8620u: goto P_0c0c8620;
case 0x0c0c8622u: goto P_0c0c8622;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03b8f4: /* original 4f22, guest PC 0x0c03b8f4 */
if(!s->budget--) { s->failed_pc=0x0c03b8f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b8f6;
P_0c03b8f6: /* original 7fb0, guest PC 0x0c03b8f6 */
if(!s->budget--) { s->failed_pc=0x0c03b8f6u; return 0; }
r[15]+=0xffffffb0u;
goto P_0c03b8f8;
P_0c03b8f8: /* original 8f04, guest PC 0x0c03b8f8 */
if(!s->budget--) { s->failed_pc=0x0c03b8f8u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[13],4);
if(!cond) { goto P_0c03b904; }
goto P_0c03b8fc;
P_0c03b8fa: /* original 1fd2, guest PC 0x0c03b8fa */
if(!s->budget--) { s->failed_pc=0x0c03b8fau; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c03b8fc;
P_0c03b8fc: /* original d254, guest PC 0x0c03b8fc */
if(!s->budget--) { s->failed_pc=0x0c03b8fcu; return 0; }
r[2]=read(ram,0x0c03ba50u,4);
goto P_0c03b8fe;
P_0c03b8fe: /* original 420b, guest PC 0x0c03b8fe */
if(!s->budget--) { s->failed_pc=0x0c03b8feu; return 0; }
target=r[2];
r[16]=0x0c03b902u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b902u) { target=s->pc; goto dispatch; }
goto P_0c03b902;
P_0c03b900: /* original e400, guest PC 0x0c03b900 */
if(!s->budget--) { s->failed_pc=0x0c03b900u; return 0; }
r[4]=0x00000000u;
goto P_0c03b902;
P_0c03b902: /* original 6d03, guest PC 0x0c03b902 */
if(!s->budget--) { s->failed_pc=0x0c03b902u; return 0; }
r[13]=r[0];
goto P_0c03b904;
P_0c03b904: /* original d353, guest PC 0x0c03b904 */
if(!s->budget--) { s->failed_pc=0x0c03b904u; return 0; }
r[3]=read(ram,0x0c03ba54u,4);
goto P_0c03b906;
P_0c03b906: /* original 65f3, guest PC 0x0c03b906 */
if(!s->budget--) { s->failed_pc=0x0c03b906u; return 0; }
r[5]=r[15];
goto P_0c03b908;
P_0c03b908: /* original 754c, guest PC 0x0c03b908 */
if(!s->budget--) { s->failed_pc=0x0c03b908u; return 0; }
r[5]+=0x0000004cu;
goto P_0c03b90a;
P_0c03b90a: /* original 430b, guest PC 0x0c03b90a */
if(!s->budget--) { s->failed_pc=0x0c03b90au; return 0; }
target=r[3];
r[16]=0x0c03b90eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b90eu) { target=s->pc; goto dispatch; }
goto P_0c03b90e;
P_0c03b90c: /* original 64d3, guest PC 0x0c03b90c */
if(!s->budget--) { s->failed_pc=0x0c03b90cu; return 0; }
r[4]=r[13];
goto P_0c03b90e;
P_0c03b90e: /* original f38d, guest PC 0x0c03b90e */
if(!s->budget--) { s->failed_pc=0x0c03b90eu; return 0; }
fr[3]=0;
goto P_0c03b910;
P_0c03b910: /* original ff0c, guest PC 0x0c03b910 */
if(!s->budget--) { s->failed_pc=0x0c03b910u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c03b912;
P_0c03b912: /* original ff34, guest PC 0x0c03b912 */
if(!s->budget--) { s->failed_pc=0x0c03b912u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c03b914;
P_0c03b914: /* original 8b01, guest PC 0x0c03b914 */
if(!s->budget--) { s->failed_pc=0x0c03b914u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b91a; }
goto P_0c03b916;
P_0c03b916: /* original a081, guest PC 0x0c03b916 */
if(!s->budget--) { s->failed_pc=0x0c03b916u; return 0; }
goto P_0c03ba1c;
P_0c03b918: /* original 0009, guest PC 0x0c03b918 */
if(!s->budget--) { s->failed_pc=0x0c03b918u; return 0; }
goto P_0c03b91a;
P_0c03b91a: /* original ec00, guest PC 0x0c03b91a */
if(!s->budget--) { s->failed_pc=0x0c03b91au; return 0; }
r[12]=0x00000000u;
goto P_0c03b91c;
P_0c03b91c: /* original 2fc0, guest PC 0x0c03b91c */
if(!s->budget--) { s->failed_pc=0x0c03b91cu; return 0; }
write(ram,r[15],r[12],1);
goto P_0c03b91e;
P_0c03b91e: /* original e404, guest PC 0x0c03b91e */
if(!s->budget--) { s->failed_pc=0x0c03b91eu; return 0; }
r[4]=0x00000004u;
goto P_0c03b920;
P_0c03b920: /* original 6ef0, guest PC 0x0c03b920 */
if(!s->budget--) { s->failed_pc=0x0c03b920u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[14]=tmp;
goto P_0c03b922;
P_0c03b922: /* original 65c3, guest PC 0x0c03b922 */
if(!s->budget--) { s->failed_pc=0x0c03b922u; return 0; }
r[5]=r[12];
goto P_0c03b924;
P_0c03b924: /* original 4e08, guest PC 0x0c03b924 */
if(!s->budget--) { s->failed_pc=0x0c03b924u; return 0; }
r[14]<<=2;
goto P_0c03b926;
P_0c03b926: /* original 63f3, guest PC 0x0c03b926 */
if(!s->budget--) { s->failed_pc=0x0c03b926u; return 0; }
r[3]=r[15];
goto P_0c03b928;
P_0c03b928: /* original 734c, guest PC 0x0c03b928 */
if(!s->budget--) { s->failed_pc=0x0c03b928u; return 0; }
r[3]+=0x0000004cu;
goto P_0c03b92a;
P_0c03b92a: /* original 675e, guest PC 0x0c03b92a */
if(!s->budget--) { s->failed_pc=0x0c03b92au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b92c;
P_0c03b92c: /* original 61f0, guest PC 0x0c03b92c */
if(!s->budget--) { s->failed_pc=0x0c03b92cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[1]=tmp;
goto P_0c03b92e;
P_0c03b92e: /* original 373c, guest PC 0x0c03b92e */
if(!s->budget--) { s->failed_pc=0x0c03b92eu; return 0; }
r[7]+=r[3];
goto P_0c03b930;
P_0c03b930: /* original 6bc3, guest PC 0x0c03b930 */
if(!s->budget--) { s->failed_pc=0x0c03b930u; return 0; }
r[11]=r[12];
goto P_0c03b932;
P_0c03b932: /* original 6770, guest PC 0x0c03b932 */
if(!s->budget--) { s->failed_pc=0x0c03b932u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c03b934;
P_0c03b934: /* original 627e, guest PC 0x0c03b934 */
if(!s->budget--) { s->failed_pc=0x0c03b934u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b936;
P_0c03b936: /* original 3210, guest PC 0x0c03b936 */
if(!s->budget--) { s->failed_pc=0x0c03b936u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c03b938;
P_0c03b938: /* original 677e, guest PC 0x0c03b938 */
if(!s->budget--) { s->failed_pc=0x0c03b938u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c03b93a;
P_0c03b93a: /* original 0029, guest PC 0x0c03b93a */
if(!s->budget--) { s->failed_pc=0x0c03b93au; return 0; }
r[0]=r[17]&1u;
goto P_0c03b93c;
P_0c03b93c: /* original 62d3, guest PC 0x0c03b93c */
if(!s->budget--) { s->failed_pc=0x0c03b93cu; return 0; }
r[2]=r[13];
goto P_0c03b93e;
P_0c03b93e: /* original 405a, guest PC 0x0c03b93e */
if(!s->budget--) { s->failed_pc=0x0c03b93eu; return 0; }
r[53]=r[0];
goto P_0c03b940;
P_0c03b940: /* original 4708, guest PC 0x0c03b940 */
if(!s->budget--) { s->failed_pc=0x0c03b940u; return 0; }
r[7]<<=2;
goto P_0c03b942;
P_0c03b942: /* original 615e, guest PC 0x0c03b942 */
if(!s->budget--) { s->failed_pc=0x0c03b942u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b944;
P_0c03b944: /* original 4708, guest PC 0x0c03b944 */
if(!s->budget--) { s->failed_pc=0x0c03b944u; return 0; }
r[7]<<=2;
goto P_0c03b946;
P_0c03b946: /* original 4115, guest PC 0x0c03b946 */
if(!s->budget--) { s->failed_pc=0x0c03b946u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c03b948;
P_0c03b948: /* original f32d, guest PC 0x0c03b948 */
if(!s->budget--) { s->failed_pc=0x0c03b948u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03b94a;
P_0c03b94a: /* original 372c, guest PC 0x0c03b94a */
if(!s->budget--) { s->failed_pc=0x0c03b94au; return 0; }
r[7]+=r[2];
goto P_0c03b94c;
P_0c03b94c: /* original f43c, guest PC 0x0c03b94c */
if(!s->budget--) { s->failed_pc=0x0c03b94cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03b94e;
P_0c03b94e: /* original 8f0d, guest PC 0x0c03b94e */
if(!s->budget--) { s->failed_pc=0x0c03b94eu; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c03b96c; }
goto P_0c03b952;
P_0c03b950: /* original 66c3, guest PC 0x0c03b950 */
if(!s->budget--) { s->failed_pc=0x0c03b950u; return 0; }
r[6]=r[12];
goto P_0c03b952;
P_0c03b952: /* original 60f3, guest PC 0x0c03b952 */
if(!s->budget--) { s->failed_pc=0x0c03b952u; return 0; }
r[0]=r[15];
goto P_0c03b954;
P_0c03b954: /* original 700c, guest PC 0x0c03b954 */
if(!s->budget--) { s->failed_pc=0x0c03b954u; return 0; }
r[0]+=0x0000000cu;
goto P_0c03b956;
P_0c03b956: /* original 306c, guest PC 0x0c03b956 */
if(!s->budget--) { s->failed_pc=0x0c03b956u; return 0; }
r[0]+=r[6];
goto P_0c03b958;
P_0c03b958: /* original f279, guest PC 0x0c03b958 */
if(!s->budget--) { s->failed_pc=0x0c03b958u; return 0; }
vf3_matrix_load(s,ram,2,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03b95a;
P_0c03b95a: /* original f3e6, guest PC 0x0c03b95a */
if(!s->budget--) { s->failed_pc=0x0c03b95au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03b95c;
P_0c03b95c: /* original 7b01, guest PC 0x0c03b95c */
if(!s->budget--) { s->failed_pc=0x0c03b95cu; return 0; }
r[11]+=0x00000001u;
goto P_0c03b95e;
P_0c03b95e: /* original 625e, guest PC 0x0c03b95e */
if(!s->budget--) { s->failed_pc=0x0c03b95eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b960;
P_0c03b960: /* original f232, guest PC 0x0c03b960 */
if(!s->budget--) { s->failed_pc=0x0c03b960u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03b962;
P_0c03b962: /* original 63be, guest PC 0x0c03b962 */
if(!s->budget--) { s->failed_pc=0x0c03b962u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c03b964;
P_0c03b964: /* original 3323, guest PC 0x0c03b964 */
if(!s->budget--) { s->failed_pc=0x0c03b964u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c03b966;
P_0c03b966: /* original f421, guest PC 0x0c03b966 */
if(!s->budget--) { s->failed_pc=0x0c03b966u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c03b968;
P_0c03b968: /* original 8ff3, guest PC 0x0c03b968 */
if(!s->budget--) { s->failed_pc=0x0c03b968u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000010u;
if(!cond) { goto P_0c03b952; }
goto P_0c03b96c;
P_0c03b96a: /* original 7610, guest PC 0x0c03b96a */
if(!s->budget--) { s->failed_pc=0x0c03b96au; return 0; }
r[6]+=0x00000010u;
goto P_0c03b96c;
P_0c03b96c: /* original 605e, guest PC 0x0c03b96c */
if(!s->budget--) { s->failed_pc=0x0c03b96cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b96e;
P_0c03b96e: /* original 63f3, guest PC 0x0c03b96e */
if(!s->budget--) { s->failed_pc=0x0c03b96eu; return 0; }
r[3]=r[15];
goto P_0c03b970;
P_0c03b970: /* original 7501, guest PC 0x0c03b970 */
if(!s->budget--) { s->failed_pc=0x0c03b970u; return 0; }
r[5]+=0x00000001u;
goto P_0c03b972;
P_0c03b972: /* original 4008, guest PC 0x0c03b972 */
if(!s->budget--) { s->failed_pc=0x0c03b972u; return 0; }
r[0]<<=2;
goto P_0c03b974;
P_0c03b974: /* original 625e, guest PC 0x0c03b974 */
if(!s->budget--) { s->failed_pc=0x0c03b974u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b976;
P_0c03b976: /* original 4008, guest PC 0x0c03b976 */
if(!s->budget--) { s->failed_pc=0x0c03b976u; return 0; }
r[0]<<=2;
goto P_0c03b978;
P_0c03b978: /* original 3243, guest PC 0x0c03b978 */
if(!s->budget--) { s->failed_pc=0x0c03b978u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c03b97a;
P_0c03b97a: /* original 730c, guest PC 0x0c03b97a */
if(!s->budget--) { s->failed_pc=0x0c03b97au; return 0; }
r[3]+=0x0000000cu;
goto P_0c03b97c;
P_0c03b97c: /* original 303c, guest PC 0x0c03b97c */
if(!s->budget--) { s->failed_pc=0x0c03b97cu; return 0; }
r[0]+=r[3];
goto P_0c03b97e;
P_0c03b97e: /* original 8fd2, guest PC 0x0c03b97e */
if(!s->budget--) { s->failed_pc=0x0c03b97eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[14]+r[0]);
if(!cond) { goto P_0c03b926; }
goto P_0c03b982;
P_0c03b980: /* original fe47, guest PC 0x0c03b980 */
if(!s->budget--) { s->failed_pc=0x0c03b980u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03b982;
P_0c03b982: /* original e830, guest PC 0x0c03b982 */
if(!s->budget--) { s->failed_pc=0x0c03b982u; return 0; }
r[8]=0x00000030u;
goto P_0c03b984;
P_0c03b984: /* original 6a43, guest PC 0x0c03b984 */
if(!s->budget--) { s->failed_pc=0x0c03b984u; return 0; }
r[10]=r[4];
goto P_0c03b986;
P_0c03b986: /* original eb03, guest PC 0x0c03b986 */
if(!s->budget--) { s->failed_pc=0x0c03b986u; return 0; }
r[11]=0x00000003u;
goto P_0c03b988;
P_0c03b988: /* original e90c, guest PC 0x0c03b988 */
if(!s->budget--) { s->failed_pc=0x0c03b988u; return 0; }
r[9]=0x0000000cu;
goto P_0c03b98a;
P_0c03b98a: /* original 60be, guest PC 0x0c03b98a */
if(!s->budget--) { s->failed_pc=0x0c03b98au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c03b98c;
P_0c03b98c: /* original 63f3, guest PC 0x0c03b98c */
if(!s->budget--) { s->failed_pc=0x0c03b98cu; return 0; }
r[3]=r[15];
goto P_0c03b98e;
P_0c03b98e: /* original 4008, guest PC 0x0c03b98e */
if(!s->budget--) { s->failed_pc=0x0c03b98eu; return 0; }
r[0]<<=2;
goto P_0c03b990;
P_0c03b990: /* original 62d3, guest PC 0x0c03b990 */
if(!s->budget--) { s->failed_pc=0x0c03b990u; return 0; }
r[2]=r[13];
goto P_0c03b992;
P_0c03b992: /* original 730c, guest PC 0x0c03b992 */
if(!s->budget--) { s->failed_pc=0x0c03b992u; return 0; }
r[3]+=0x0000000cu;
goto P_0c03b994;
P_0c03b994: /* original 65a3, guest PC 0x0c03b994 */
if(!s->budget--) { s->failed_pc=0x0c03b994u; return 0; }
r[5]=r[10];
goto P_0c03b996;
P_0c03b996: /* original 4008, guest PC 0x0c03b996 */
if(!s->budget--) { s->failed_pc=0x0c03b996u; return 0; }
r[0]<<=2;
goto P_0c03b998;
P_0c03b998: /* original 303c, guest PC 0x0c03b998 */
if(!s->budget--) { s->failed_pc=0x0c03b998u; return 0; }
r[0]+=r[3];
goto P_0c03b99a;
P_0c03b99a: /* original 63f3, guest PC 0x0c03b99a */
if(!s->budget--) { s->failed_pc=0x0c03b99au; return 0; }
r[3]=r[15];
goto P_0c03b99c;
P_0c03b99c: /* original 734c, guest PC 0x0c03b99c */
if(!s->budget--) { s->failed_pc=0x0c03b99cu; return 0; }
r[3]+=0x0000004cu;
goto P_0c03b99e;
P_0c03b99e: /* original f4e6, guest PC 0x0c03b99e */
if(!s->budget--) { s->failed_pc=0x0c03b99eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c03b9a0;
P_0c03b9a0: /* original 66be, guest PC 0x0c03b9a0 */
if(!s->budget--) { s->failed_pc=0x0c03b9a0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c03b9a2;
P_0c03b9a2: /* original 363c, guest PC 0x0c03b9a2 */
if(!s->budget--) { s->failed_pc=0x0c03b9a2u; return 0; }
r[6]+=r[3];
goto P_0c03b9a4;
P_0c03b9a4: /* original 6660, guest PC 0x0c03b9a4 */
if(!s->budget--) { s->failed_pc=0x0c03b9a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c03b9a6;
P_0c03b9a6: /* original 615e, guest PC 0x0c03b9a6 */
if(!s->budget--) { s->failed_pc=0x0c03b9a6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b9a8;
P_0c03b9a8: /* original 4108, guest PC 0x0c03b9a8 */
if(!s->budget--) { s->failed_pc=0x0c03b9a8u; return 0; }
r[1]<<=2;
goto P_0c03b9aa;
P_0c03b9aa: /* original 4608, guest PC 0x0c03b9aa */
if(!s->budget--) { s->failed_pc=0x0c03b9aau; return 0; }
r[6]<<=2;
goto P_0c03b9ac;
P_0c03b9ac: /* original 4608, guest PC 0x0c03b9ac */
if(!s->budget--) { s->failed_pc=0x0c03b9acu; return 0; }
r[6]<<=2;
goto P_0c03b9ae;
P_0c03b9ae: /* original 1f61, guest PC 0x0c03b9ae */
if(!s->budget--) { s->failed_pc=0x0c03b9aeu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c03b9b0;
P_0c03b9b0: /* original 362c, guest PC 0x0c03b9b0 */
if(!s->budget--) { s->failed_pc=0x0c03b9b0u; return 0; }
r[6]+=r[2];
goto P_0c03b9b2;
P_0c03b9b2: /* original 625e, guest PC 0x0c03b9b2 */
if(!s->budget--) { s->failed_pc=0x0c03b9b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b9b4;
P_0c03b9b4: /* original 675e, guest PC 0x0c03b9b4 */
if(!s->budget--) { s->failed_pc=0x0c03b9b4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b9b6;
P_0c03b9b6: /* original 3243, guest PC 0x0c03b9b6 */
if(!s->budget--) { s->failed_pc=0x0c03b9b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c03b9b8;
P_0c03b9b8: /* original 4708, guest PC 0x0c03b9b8 */
if(!s->budget--) { s->failed_pc=0x0c03b9b8u; return 0; }
r[7]<<=2;
goto P_0c03b9ba;
P_0c03b9ba: /* original 361c, guest PC 0x0c03b9ba */
if(!s->budget--) { s->failed_pc=0x0c03b9bau; return 0; }
r[6]+=r[1];
goto P_0c03b9bc;
P_0c03b9bc: /* original 8d0c, guest PC 0x0c03b9bc */
if(!s->budget--) { s->failed_pc=0x0c03b9bcu; return 0; }
cond=r[17]&1u;
r[7]<<=2;
if(cond) { goto P_0c03b9d8; }
goto P_0c03b9c0;
P_0c03b9be: /* original 4708, guest PC 0x0c03b9be */
if(!s->budget--) { s->failed_pc=0x0c03b9beu; return 0; }
r[7]<<=2;
goto P_0c03b9c0;
P_0c03b9c0: /* original 60f3, guest PC 0x0c03b9c0 */
if(!s->budget--) { s->failed_pc=0x0c03b9c0u; return 0; }
r[0]=r[15];
goto P_0c03b9c2;
P_0c03b9c2: /* original 700c, guest PC 0x0c03b9c2 */
if(!s->budget--) { s->failed_pc=0x0c03b9c2u; return 0; }
r[0]+=0x0000000cu;
goto P_0c03b9c4;
P_0c03b9c4: /* original 307c, guest PC 0x0c03b9c4 */
if(!s->budget--) { s->failed_pc=0x0c03b9c4u; return 0; }
r[0]+=r[7];
goto P_0c03b9c6;
P_0c03b9c6: /* original f269, guest PC 0x0c03b9c6 */
if(!s->budget--) { s->failed_pc=0x0c03b9c6u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c03b9c8;
P_0c03b9c8: /* original f3e6, guest PC 0x0c03b9c8 */
if(!s->budget--) { s->failed_pc=0x0c03b9c8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03b9ca;
P_0c03b9ca: /* original 7501, guest PC 0x0c03b9ca */
if(!s->budget--) { s->failed_pc=0x0c03b9cau; return 0; }
r[5]+=0x00000001u;
goto P_0c03b9cc;
P_0c03b9cc: /* original 635e, guest PC 0x0c03b9cc */
if(!s->budget--) { s->failed_pc=0x0c03b9ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c03b9ce;
P_0c03b9ce: /* original f232, guest PC 0x0c03b9ce */
if(!s->budget--) { s->failed_pc=0x0c03b9ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03b9d0;
P_0c03b9d0: /* original 3343, guest PC 0x0c03b9d0 */
if(!s->budget--) { s->failed_pc=0x0c03b9d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c03b9d2;
P_0c03b9d2: /* original f421, guest PC 0x0c03b9d2 */
if(!s->budget--) { s->failed_pc=0x0c03b9d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c03b9d4;
P_0c03b9d4: /* original 8ff4, guest PC 0x0c03b9d4 */
if(!s->budget--) { s->failed_pc=0x0c03b9d4u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000010u;
if(!cond) { goto P_0c03b9c0; }
goto P_0c03b9d8;
P_0c03b9d6: /* original 7710, guest PC 0x0c03b9d6 */
if(!s->budget--) { s->failed_pc=0x0c03b9d6u; return 0; }
r[7]+=0x00000010u;
goto P_0c03b9d8;
P_0c03b9d8: /* original 53f1, guest PC 0x0c03b9d8 */
if(!s->budget--) { s->failed_pc=0x0c03b9d8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c03b9da;
P_0c03b9da: /* original 62d3, guest PC 0x0c03b9da */
if(!s->budget--) { s->failed_pc=0x0c03b9dau; return 0; }
r[2]=r[13];
goto P_0c03b9dc;
P_0c03b9dc: /* original 60f3, guest PC 0x0c03b9dc */
if(!s->budget--) { s->failed_pc=0x0c03b9dcu; return 0; }
r[0]=r[15];
goto P_0c03b9de;
P_0c03b9de: /* original 7bff, guest PC 0x0c03b9de */
if(!s->budget--) { s->failed_pc=0x0c03b9deu; return 0; }
r[11]+=0xffffffffu;
goto P_0c03b9e0;
P_0c03b9e0: /* original 323c, guest PC 0x0c03b9e0 */
if(!s->budget--) { s->failed_pc=0x0c03b9e0u; return 0; }
r[2]+=r[3];
goto P_0c03b9e2;
P_0c03b9e2: /* original 329c, guest PC 0x0c03b9e2 */
if(!s->budget--) { s->failed_pc=0x0c03b9e2u; return 0; }
r[2]+=r[9];
goto P_0c03b9e4;
P_0c03b9e4: /* original f328, guest PC 0x0c03b9e4 */
if(!s->budget--) { s->failed_pc=0x0c03b9e4u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c03b9e6;
P_0c03b9e6: /* original 700c, guest PC 0x0c03b9e6 */
if(!s->budget--) { s->failed_pc=0x0c03b9e6u; return 0; }
r[0]+=0x0000000cu;
goto P_0c03b9e8;
P_0c03b9e8: /* original 63be, guest PC 0x0c03b9e8 */
if(!s->budget--) { s->failed_pc=0x0c03b9e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c03b9ea;
P_0c03b9ea: /* original f433, guest PC 0x0c03b9ea */
if(!s->budget--) { s->failed_pc=0x0c03b9eau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03b9ec;
P_0c03b9ec: /* original 308c, guest PC 0x0c03b9ec */
if(!s->budget--) { s->failed_pc=0x0c03b9ecu; return 0; }
r[0]+=r[8];
goto P_0c03b9ee;
P_0c03b9ee: /* original 4311, guest PC 0x0c03b9ee */
if(!s->budget--) { s->failed_pc=0x0c03b9eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03b9f0;
P_0c03b9f0: /* original 78f0, guest PC 0x0c03b9f0 */
if(!s->budget--) { s->failed_pc=0x0c03b9f0u; return 0; }
r[8]+=0xfffffff0u;
goto P_0c03b9f2;
P_0c03b9f2: /* original 79fc, guest PC 0x0c03b9f2 */
if(!s->budget--) { s->failed_pc=0x0c03b9f2u; return 0; }
r[9]+=0xfffffffcu;
goto P_0c03b9f4;
P_0c03b9f4: /* original fe47, guest PC 0x0c03b9f4 */
if(!s->budget--) { s->failed_pc=0x0c03b9f4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03b9f6;
P_0c03b9f6: /* original 8dc8, guest PC 0x0c03b9f6 */
if(!s->budget--) { s->failed_pc=0x0c03b9f6u; return 0; }
cond=r[17]&1u;
r[10]+=0xffffffffu;
if(cond) { goto P_0c03b98a; }
goto P_0c03b9fa;
P_0c03b9f8: /* original 7aff, guest PC 0x0c03b9f8 */
if(!s->budget--) { s->failed_pc=0x0c03b9f8u; return 0; }
r[10]+=0xffffffffu;
goto P_0c03b9fa;
P_0c03b9fa: /* original 63f0, guest PC 0x0c03b9fa */
if(!s->budget--) { s->failed_pc=0x0c03b9fau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c03b9fc;
P_0c03b9fc: /* original 7301, guest PC 0x0c03b9fc */
if(!s->budget--) { s->failed_pc=0x0c03b9fcu; return 0; }
r[3]+=0x00000001u;
goto P_0c03b9fe;
P_0c03b9fe: /* original 2f30, guest PC 0x0c03b9fe */
if(!s->budget--) { s->failed_pc=0x0c03b9feu; return 0; }
write(ram,r[15],r[3],1);
goto P_0c03ba00;
P_0c03ba00: /* original 633e, guest PC 0x0c03ba00 */
if(!s->budget--) { s->failed_pc=0x0c03ba00u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c03ba02;
P_0c03ba02: /* original 3343, guest PC 0x0c03ba02 */
if(!s->budget--) { s->failed_pc=0x0c03ba02u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c03ba04;
P_0c03ba04: /* original 8b8c, guest PC 0x0c03ba04 */
if(!s->budget--) { s->failed_pc=0x0c03ba04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b920; }
goto P_0c03ba06;
P_0c03ba06: /* original d214, guest PC 0x0c03ba06 */
if(!s->budget--) { s->failed_pc=0x0c03ba06u; return 0; }
r[2]=read(ram,0x0c03ba58u,4);
goto P_0c03ba08;
P_0c03ba08: /* original 65f3, guest PC 0x0c03ba08 */
if(!s->budget--) { s->failed_pc=0x0c03ba08u; return 0; }
r[5]=r[15];
goto P_0c03ba0a;
P_0c03ba0a: /* original 750c, guest PC 0x0c03ba0a */
if(!s->budget--) { s->failed_pc=0x0c03ba0au; return 0; }
r[5]+=0x0000000cu;
goto P_0c03ba0c;
P_0c03ba0c: /* original 420b, guest PC 0x0c03ba0c */
if(!s->budget--) { s->failed_pc=0x0c03ba0cu; return 0; }
target=r[2];
r[16]=0x0c03ba10u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ba10u) { target=s->pc; goto dispatch; }
goto P_0c03ba10;
P_0c03ba0e: /* original 64d3, guest PC 0x0c03ba0e */
if(!s->budget--) { s->failed_pc=0x0c03ba0eu; return 0; }
r[4]=r[13];
goto P_0c03ba10;
P_0c03ba10: /* original 53f2, guest PC 0x0c03ba10 */
if(!s->budget--) { s->failed_pc=0x0c03ba10u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c03ba12;
P_0c03ba12: /* original 2338, guest PC 0x0c03ba12 */
if(!s->budget--) { s->failed_pc=0x0c03ba12u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03ba14;
P_0c03ba14: /* original 8b02, guest PC 0x0c03ba14 */
if(!s->budget--) { s->failed_pc=0x0c03ba14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03ba1c; }
goto P_0c03ba16;
P_0c03ba16: /* original d311, guest PC 0x0c03ba16 */
if(!s->budget--) { s->failed_pc=0x0c03ba16u; return 0; }
r[3]=read(ram,0x0c03ba5cu,4);
goto P_0c03ba18;
P_0c03ba18: /* original 430b, guest PC 0x0c03ba18 */
if(!s->budget--) { s->failed_pc=0x0c03ba18u; return 0; }
target=r[3];
r[16]=0x0c03ba1cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ba1cu) { target=s->pc; goto dispatch; }
goto P_0c03ba1c;
P_0c03ba1a: /* original 64d3, guest PC 0x0c03ba1a */
if(!s->budget--) { s->failed_pc=0x0c03ba1au; return 0; }
r[4]=r[13];
goto P_0c03ba1c;
P_0c03ba1c: /* original 7f50, guest PC 0x0c03ba1c */
if(!s->budget--) { s->failed_pc=0x0c03ba1cu; return 0; }
r[15]+=0x00000050u;
goto P_0c03ba1e;
P_0c03ba1e: /* original f0fc, guest PC 0x0c03ba1e */
if(!s->budget--) { s->failed_pc=0x0c03ba1eu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c03ba20;
P_0c03ba20: /* original 4f26, guest PC 0x0c03ba20 */
if(!s->budget--) { s->failed_pc=0x0c03ba20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ba22;
P_0c03ba22: /* original fff9, guest PC 0x0c03ba22 */
if(!s->budget--) { s->failed_pc=0x0c03ba22u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03ba24;
P_0c03ba24: /* original 68f6, guest PC 0x0c03ba24 */
if(!s->budget--) { s->failed_pc=0x0c03ba24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03ba26;
P_0c03ba26: /* original 69f6, guest PC 0x0c03ba26 */
if(!s->budget--) { s->failed_pc=0x0c03ba26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03ba28;
P_0c03ba28: /* original 6af6, guest PC 0x0c03ba28 */
if(!s->budget--) { s->failed_pc=0x0c03ba28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03ba2a;
P_0c03ba2a: /* original 6bf6, guest PC 0x0c03ba2a */
if(!s->budget--) { s->failed_pc=0x0c03ba2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03ba2c;
P_0c03ba2c: /* original 6cf6, guest PC 0x0c03ba2c */
if(!s->budget--) { s->failed_pc=0x0c03ba2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03ba2e;
P_0c03ba2e: /* original 6df6, guest PC 0x0c03ba2e */
if(!s->budget--) { s->failed_pc=0x0c03ba2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03ba30;
P_0c03ba30: /* original 000b, guest PC 0x0c03ba30 */
if(!s->budget--) { s->failed_pc=0x0c03ba30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03ba32: /* original 6ef6, guest PC 0x0c03ba32 */
if(!s->budget--) { s->failed_pc=0x0c03ba32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ba34u,s,ram);
P_0c054b84: /* original 4f22, guest PC 0x0c054b84 */
if(!s->budget--) { s->failed_pc=0x0c054b84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054b86;
P_0c054b86: /* original 430b, guest PC 0x0c054b86 */
if(!s->budget--) { s->failed_pc=0x0c054b86u; return 0; }
target=r[3];
r[16]=0x0c054b8au;
r[1]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c054b8au) { target=s->pc; goto dispatch; }
goto P_0c054b8a;
P_0c054b88: /* original 6163, guest PC 0x0c054b88 */
if(!s->budget--) { s->failed_pc=0x0c054b88u; return 0; }
r[1]=r[6];
goto P_0c054b8a;
P_0c054b8a: /* original 6e03, guest PC 0x0c054b8a */
if(!s->budget--) { s->failed_pc=0x0c054b8au; return 0; }
r[14]=r[0];
goto P_0c054b8c;
P_0c054b8c: /* original d21c, guest PC 0x0c054b8c */
if(!s->budget--) { s->failed_pc=0x0c054b8cu; return 0; }
r[2]=read(ram,0x0c054c00u,4);
goto P_0c054b8e;
P_0c054b8e: /* original 6163, guest PC 0x0c054b8e */
if(!s->budget--) { s->failed_pc=0x0c054b8eu; return 0; }
r[1]=r[6];
goto P_0c054b90;
P_0c054b90: /* original 3e4c, guest PC 0x0c054b90 */
if(!s->budget--) { s->failed_pc=0x0c054b90u; return 0; }
r[14]+=r[4];
goto P_0c054b92;
P_0c054b92: /* original 67e3, guest PC 0x0c054b92 */
if(!s->budget--) { s->failed_pc=0x0c054b92u; return 0; }
r[7]=r[14];
goto P_0c054b94;
P_0c054b94: /* original 420b, guest PC 0x0c054b94 */
if(!s->budget--) { s->failed_pc=0x0c054b94u; return 0; }
target=r[2];
r[16]=0x0c054b98u;
r[0]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c054b98u) { target=s->pc; goto dispatch; }
goto P_0c054b98;
P_0c054b96: /* original e008, guest PC 0x0c054b96 */
if(!s->budget--) { s->failed_pc=0x0c054b96u; return 0; }
r[0]=0x00000008u;
goto P_0c054b98;
P_0c054b98: /* original 9d2e, guest PC 0x0c054b98 */
if(!s->budget--) { s->failed_pc=0x0c054b98u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054bf8u,2);
goto P_0c054b9a;
P_0c054b9a: /* original 600b, guest PC 0x0c054b9a */
if(!s->budget--) { s->failed_pc=0x0c054b9au; return 0; }
r[0]=0u-r[0];
goto P_0c054b9c;
P_0c054b9c: /* original 0009, guest PC 0x0c054b9c */
if(!s->budget--) { s->failed_pc=0x0c054b9cu; return 0; }
goto P_0c054b9e;
P_0c054b9e: /* original 4d0c, guest PC 0x0c054b9e */
if(!s->budget--) { s->failed_pc=0x0c054b9eu; return 0; }
r[13]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[13]>>((-r[0])&31u)):((int32_t)r[13]<0?0xffffffffu:0)):r[13]<<(r[0]&31u);
goto P_0c054ba0;
P_0c054ba0: /* original 6370, guest PC 0x0c054ba0 */
if(!s->budget--) { s->failed_pc=0x0c054ba0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c054ba2;
P_0c054ba2: /* original 62dc, guest PC 0x0c054ba2 */
if(!s->budget--) { s->failed_pc=0x0c054ba2u; return 0; }
r[2]=r[13]&255u;
goto P_0c054ba4;
P_0c054ba4: /* original 633c, guest PC 0x0c054ba4 */
if(!s->budget--) { s->failed_pc=0x0c054ba4u; return 0; }
r[3]=r[3]&255u;
goto P_0c054ba6;
P_0c054ba6: /* original 2328, guest PC 0x0c054ba6 */
if(!s->budget--) { s->failed_pc=0x0c054ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c054ba8;
P_0c054ba8: /* original 8f22, guest PC 0x0c054ba8 */
if(!s->budget--) { s->failed_pc=0x0c054ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bf0; }
goto P_0c054bac;
P_0c054baa: /* original 0009, guest PC 0x0c054baa */
if(!s->budget--) { s->failed_pc=0x0c054baau; return 0; }
goto P_0c054bac;
P_0c054bac: /* original 66d3, guest PC 0x0c054bac */
if(!s->budget--) { s->failed_pc=0x0c054bacu; return 0; }
r[6]=r[13];
goto P_0c054bae;
P_0c054bae: /* original a003, guest PC 0x0c054bae */
if(!s->budget--) { s->failed_pc=0x0c054baeu; return 0; }
r[0]=0x00000000u;
goto P_0c054bb8;
P_0c054bb0: /* original e000, guest PC 0x0c054bb0 */
if(!s->budget--) { s->failed_pc=0x0c054bb0u; return 0; }
r[0]=0x00000000u;
goto P_0c054bb2;
P_0c054bb2: /* original 206b, guest PC 0x0c054bb2 */
if(!s->budget--) { s->failed_pc=0x0c054bb2u; return 0; }
r[0]|=r[6];
goto P_0c054bb4;
P_0c054bb4: /* original 666c, guest PC 0x0c054bb4 */
if(!s->budget--) { s->failed_pc=0x0c054bb4u; return 0; }
r[6]=r[6]&255u;
goto P_0c054bb6;
P_0c054bb6: /* original 4601, guest PC 0x0c054bb6 */
if(!s->budget--) { s->failed_pc=0x0c054bb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c054bb8;
P_0c054bb8: /* original 626c, guest PC 0x0c054bb8 */
if(!s->budget--) { s->failed_pc=0x0c054bb8u; return 0; }
r[2]=r[6]&255u;
goto P_0c054bba;
P_0c054bba: /* original 2228, guest PC 0x0c054bba */
if(!s->budget--) { s->failed_pc=0x0c054bbau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054bbc;
P_0c054bbc: /* original 8ff9, guest PC 0x0c054bbc */
if(!s->budget--) { s->failed_pc=0x0c054bbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bb2; }
goto P_0c054bc0;
P_0c054bbe: /* original 0009, guest PC 0x0c054bbe */
if(!s->budget--) { s->failed_pc=0x0c054bbeu; return 0; }
goto P_0c054bc0;
P_0c054bc0: /* original 6170, guest PC 0x0c054bc0 */
if(!s->budget--) { s->failed_pc=0x0c054bc0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[1]=tmp;
goto P_0c054bc2;
P_0c054bc2: /* original 600c, guest PC 0x0c054bc2 */
if(!s->budget--) { s->failed_pc=0x0c054bc2u; return 0; }
r[0]=r[0]&255u;
goto P_0c054bc4;
P_0c054bc4: /* original 611c, guest PC 0x0c054bc4 */
if(!s->budget--) { s->failed_pc=0x0c054bc4u; return 0; }
r[1]=r[1]&255u;
goto P_0c054bc6;
P_0c054bc6: /* original 2108, guest PC 0x0c054bc6 */
if(!s->budget--) { s->failed_pc=0x0c054bc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c054bc8;
P_0c054bc8: /* original 8d04, guest PC 0x0c054bc8 */
if(!s->budget--) { s->failed_pc=0x0c054bc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054bd4; }
goto P_0c054bcc;
P_0c054bca: /* original 0009, guest PC 0x0c054bca */
if(!s->budget--) { s->failed_pc=0x0c054bcau; return 0; }
goto P_0c054bcc;
P_0c054bcc: /* original 6270, guest PC 0x0c054bcc */
if(!s->budget--) { s->failed_pc=0x0c054bccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[2]=tmp;
goto P_0c054bce;
P_0c054bce: /* original 22db, guest PC 0x0c054bce */
if(!s->budget--) { s->failed_pc=0x0c054bceu; return 0; }
r[2]|=r[13];
goto P_0c054bd0;
P_0c054bd0: /* original a00e, guest PC 0x0c054bd0 */
if(!s->budget--) { s->failed_pc=0x0c054bd0u; return 0; }
write(ram,r[7],r[2],1);
goto P_0c054bf0;
P_0c054bd2: /* original 2720, guest PC 0x0c054bd2 */
if(!s->budget--) { s->failed_pc=0x0c054bd2u; return 0; }
write(ram,r[7],r[2],1);
goto P_0c054bd4;
P_0c054bd4: /* original a008, guest PC 0x0c054bd4 */
if(!s->budget--) { s->failed_pc=0x0c054bd4u; return 0; }
r[4]+=r[5];
goto P_0c054be8;
P_0c054bd6: /* original 345c, guest PC 0x0c054bd6 */
if(!s->budget--) { s->failed_pc=0x0c054bd6u; return 0; }
r[4]+=r[5];
goto P_0c054bd8;
P_0c054bd8: /* original 6370, guest PC 0x0c054bd8 */
if(!s->budget--) { s->failed_pc=0x0c054bd8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c054bda;
P_0c054bda: /* original 2338, guest PC 0x0c054bda */
if(!s->budget--) { s->failed_pc=0x0c054bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c054bdc;
P_0c054bdc: /* original 8d04, guest PC 0x0c054bdc */
if(!s->budget--) { s->failed_pc=0x0c054bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054be8; }
goto P_0c054be0;
P_0c054bde: /* original 0009, guest PC 0x0c054bde */
if(!s->budget--) { s->failed_pc=0x0c054bdeu; return 0; }
goto P_0c054be0;
P_0c054be0: /* original 61e0, guest PC 0x0c054be0 */
if(!s->budget--) { s->failed_pc=0x0c054be0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[1]=tmp;
goto P_0c054be2;
P_0c054be2: /* original 21db, guest PC 0x0c054be2 */
if(!s->budget--) { s->failed_pc=0x0c054be2u; return 0; }
r[1]|=r[13];
goto P_0c054be4;
P_0c054be4: /* original a004, guest PC 0x0c054be4 */
if(!s->budget--) { s->failed_pc=0x0c054be4u; return 0; }
write(ram,r[14],r[1],1);
goto P_0c054bf0;
P_0c054be6: /* original 2e10, guest PC 0x0c054be6 */
if(!s->budget--) { s->failed_pc=0x0c054be6u; return 0; }
write(ram,r[14],r[1],1);
goto P_0c054be8;
P_0c054be8: /* original 7701, guest PC 0x0c054be8 */
if(!s->budget--) { s->failed_pc=0x0c054be8u; return 0; }
r[7]+=0x00000001u;
goto P_0c054bea;
P_0c054bea: /* original 3742, guest PC 0x0c054bea */
if(!s->budget--) { s->failed_pc=0x0c054beau; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[4])!=0);
goto P_0c054bec;
P_0c054bec: /* original 8ff4, guest PC 0x0c054bec */
if(!s->budget--) { s->failed_pc=0x0c054becu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bd8; }
goto P_0c054bf0;
P_0c054bee: /* original 0009, guest PC 0x0c054bee */
if(!s->budget--) { s->failed_pc=0x0c054beeu; return 0; }
goto P_0c054bf0;
P_0c054bf0: /* original 4f26, guest PC 0x0c054bf0 */
if(!s->budget--) { s->failed_pc=0x0c054bf0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054bf2;
P_0c054bf2: /* original 6df6, guest PC 0x0c054bf2 */
if(!s->budget--) { s->failed_pc=0x0c054bf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054bf4;
P_0c054bf4: /* original 000b, guest PC 0x0c054bf4 */
if(!s->budget--) { s->failed_pc=0x0c054bf4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054bf6: /* original 6ef6, guest PC 0x0c054bf6 */
if(!s->budget--) { s->failed_pc=0x0c054bf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c054bf8u,s,ram);
P_0c06d638: /* original 4f22, guest PC 0x0c06d638 */
if(!s->budget--) { s->failed_pc=0x0c06d638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d63a;
P_0c06d63a: /* original f346, guest PC 0x0c06d63a */
if(!s->budget--) { s->failed_pc=0x0c06d63au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d63c;
P_0c06d63c: /* original e004, guest PC 0x0c06d63c */
if(!s->budget--) { s->failed_pc=0x0c06d63cu; return 0; }
r[0]=0x00000004u;
goto P_0c06d63e;
P_0c06d63e: /* original 7ff4, guest PC 0x0c06d63e */
if(!s->budget--) { s->failed_pc=0x0c06d63eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06d640;
P_0c06d640: /* original ff37, guest PC 0x0c06d640 */
if(!s->budget--) { s->failed_pc=0x0c06d640u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d642;
P_0c06d642: /* original 906c, guest PC 0x0c06d642 */
if(!s->budget--) { s->failed_pc=0x0c06d642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d71eu,2);
goto P_0c06d644;
P_0c06d644: /* original f346, guest PC 0x0c06d644 */
if(!s->budget--) { s->failed_pc=0x0c06d644u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d646;
P_0c06d646: /* original ff3a, guest PC 0x0c06d646 */
if(!s->budget--) { s->failed_pc=0x0c06d646u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06d648;
P_0c06d648: /* original 906a, guest PC 0x0c06d648 */
if(!s->budget--) { s->failed_pc=0x0c06d648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d720u,2);
goto P_0c06d64a;
P_0c06d64a: /* original f346, guest PC 0x0c06d64a */
if(!s->budget--) { s->failed_pc=0x0c06d64au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06d64c;
P_0c06d64c: /* original e008, guest PC 0x0c06d64c */
if(!s->budget--) { s->failed_pc=0x0c06d64cu; return 0; }
r[0]=0x00000008u;
goto P_0c06d64e;
P_0c06d64e: /* original f34d, guest PC 0x0c06d64e */
if(!s->budget--) { s->failed_pc=0x0c06d64eu; return 0; }
fr[3]^=0x80000000u;
goto P_0c06d650;
P_0c06d650: /* original ff37, guest PC 0x0c06d650 */
if(!s->budget--) { s->failed_pc=0x0c06d650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06d652;
P_0c06d652: /* original f68d, guest PC 0x0c06d652 */
if(!s->budget--) { s->failed_pc=0x0c06d652u; return 0; }
fr[6]=0;
goto P_0c06d654;
P_0c06d654: /* original f76c, guest PC 0x0c06d654 */
if(!s->budget--) { s->failed_pc=0x0c06d654u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c06d656;
P_0c06d656: /* original f56c, guest PC 0x0c06d656 */
if(!s->budget--) { s->failed_pc=0x0c06d656u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c06d658;
P_0c06d658: /* original e004, guest PC 0x0c06d658 */
if(!s->budget--) { s->failed_pc=0x0c06d658u; return 0; }
r[0]=0x00000004u;
goto P_0c06d65a;
P_0c06d65a: /* original faf8, guest PC 0x0c06d65a */
if(!s->budget--) { s->failed_pc=0x0c06d65au; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
goto P_0c06d65c;
P_0c06d65c: /* original f356, guest PC 0x0c06d65c */
if(!s->budget--) { s->failed_pc=0x0c06d65cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d65e;
P_0c06d65e: /* original e004, guest PC 0x0c06d65e */
if(!s->budget--) { s->failed_pc=0x0c06d65eu; return 0; }
r[0]=0x00000004u;
goto P_0c06d660;
P_0c06d660: /* original fbf6, guest PC 0x0c06d660 */
if(!s->budget--) { s->failed_pc=0x0c06d660u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c06d662;
P_0c06d662: /* original e008, guest PC 0x0c06d662 */
if(!s->budget--) { s->failed_pc=0x0c06d662u; return 0; }
r[0]=0x00000008u;
goto P_0c06d664;
P_0c06d664: /* original fe9d, guest PC 0x0c06d664 */
if(!s->budget--) { s->failed_pc=0x0c06d664u; return 0; }
fr[14]=0x3f800000u;
goto P_0c06d666;
P_0c06d666: /* original fb31, guest PC 0x0c06d666 */
if(!s->budget--) { s->failed_pc=0x0c06d666u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c06d668;
P_0c06d668: /* original f356, guest PC 0x0c06d668 */
if(!s->budget--) { s->failed_pc=0x0c06d668u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d66a;
P_0c06d66a: /* original e00c, guest PC 0x0c06d66a */
if(!s->budget--) { s->failed_pc=0x0c06d66au; return 0; }
r[0]=0x0000000cu;
goto P_0c06d66c;
P_0c06d66c: /* original f858, guest PC 0x0c06d66c */
if(!s->budget--) { s->failed_pc=0x0c06d66cu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
goto P_0c06d66e;
P_0c06d66e: /* original fa31, guest PC 0x0c06d66e */
if(!s->budget--) { s->failed_pc=0x0c06d66eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c06d670;
P_0c06d670: /* original f356, guest PC 0x0c06d670 */
if(!s->budget--) { s->failed_pc=0x0c06d670u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c06d672;
P_0c06d672: /* original e008, guest PC 0x0c06d672 */
if(!s->budget--) { s->failed_pc=0x0c06d672u; return 0; }
r[0]=0x00000008u;
goto P_0c06d674;
P_0c06d674: /* original f4bc, guest PC 0x0c06d674 */
if(!s->budget--) { s->failed_pc=0x0c06d674u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c06d676;
P_0c06d676: /* original f4b2, guest PC 0x0c06d676 */
if(!s->budget--) { s->failed_pc=0x0c06d676u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'*');
goto P_0c06d678;
P_0c06d678: /* original f9f6, guest PC 0x0c06d678 */
if(!s->budget--) { s->failed_pc=0x0c06d678u; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c06d67a;
P_0c06d67a: /* original f0ac, guest PC 0x0c06d67a */
if(!s->budget--) { s->failed_pc=0x0c06d67au; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06d67c;
P_0c06d67c: /* original f931, guest PC 0x0c06d67c */
if(!s->budget--) { s->failed_pc=0x0c06d67cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c06d67e;
P_0c06d67e: /* original f34c, guest PC 0x0c06d67e */
if(!s->budget--) { s->failed_pc=0x0c06d67eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d680;
P_0c06d680: /* original f3ae, guest PC 0x0c06d680 */
if(!s->budget--) { s->failed_pc=0x0c06d680u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c06d682;
P_0c06d682: /* original f09c, guest PC 0x0c06d682 */
if(!s->budget--) { s->failed_pc=0x0c06d682u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d684;
P_0c06d684: /* original f23c, guest PC 0x0c06d684 */
if(!s->budget--) { s->failed_pc=0x0c06d684u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c06d686;
P_0c06d686: /* original f29e, guest PC 0x0c06d686 */
if(!s->budget--) { s->failed_pc=0x0c06d686u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c06d688;
P_0c06d688: /* original f0bc, guest PC 0x0c06d688 */
if(!s->budget--) { s->failed_pc=0x0c06d688u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c06d68a;
P_0c06d68a: /* original f42c, guest PC 0x0c06d68a */
if(!s->budget--) { s->failed_pc=0x0c06d68au; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06d68c;
P_0c06d68c: /* original f4e0, guest PC 0x0c06d68c */
if(!s->budget--) { s->failed_pc=0x0c06d68cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'+');
goto P_0c06d68e;
P_0c06d68e: /* original f25c, guest PC 0x0c06d68e */
if(!s->budget--) { s->failed_pc=0x0c06d68eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c06d690;
P_0c06d690: /* original f34c, guest PC 0x0c06d690 */
if(!s->budget--) { s->failed_pc=0x0c06d690u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d692;
P_0c06d692: /* original f432, guest PC 0x0c06d692 */
if(!s->budget--) { s->failed_pc=0x0c06d692u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06d694;
P_0c06d694: /* original f843, guest PC 0x0c06d694 */
if(!s->budget--) { s->failed_pc=0x0c06d694u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c06d696;
P_0c06d696: /* original f28e, guest PC 0x0c06d696 */
if(!s->budget--) { s->failed_pc=0x0c06d696u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c06d698;
P_0c06d698: /* original f0ac, guest PC 0x0c06d698 */
if(!s->budget--) { s->failed_pc=0x0c06d698u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c06d69a;
P_0c06d69a: /* original 7510, guest PC 0x0c06d69a */
if(!s->budget--) { s->failed_pc=0x0c06d69au; return 0; }
r[5]+=0x00000010u;
goto P_0c06d69c;
P_0c06d69c: /* original f37c, guest PC 0x0c06d69c */
if(!s->budget--) { s->failed_pc=0x0c06d69cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06d69e;
P_0c06d69e: /* original f38e, guest PC 0x0c06d69e */
if(!s->budget--) { s->failed_pc=0x0c06d69eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c06d6a0;
P_0c06d6a0: /* original f52c, guest PC 0x0c06d6a0 */
if(!s->budget--) { s->failed_pc=0x0c06d6a0u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c06d6a2;
P_0c06d6a2: /* original f09c, guest PC 0x0c06d6a2 */
if(!s->budget--) { s->failed_pc=0x0c06d6a2u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d6a4;
P_0c06d6a4: /* original f26c, guest PC 0x0c06d6a4 */
if(!s->budget--) { s->failed_pc=0x0c06d6a4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c06d6a6;
P_0c06d6a6: /* original f28e, guest PC 0x0c06d6a6 */
if(!s->budget--) { s->failed_pc=0x0c06d6a6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c06d6a8;
P_0c06d6a8: /* original 6052, guest PC 0x0c06d6a8 */
if(!s->budget--) { s->failed_pc=0x0c06d6a8u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c06d6aa;
P_0c06d6aa: /* original f73c, guest PC 0x0c06d6aa */
if(!s->budget--) { s->failed_pc=0x0c06d6aau; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c06d6ac;
P_0c06d6ac: /* original 88ff, guest PC 0x0c06d6ac */
if(!s->budget--) { s->failed_pc=0x0c06d6acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06d6ae;
P_0c06d6ae: /* original 8fd3, guest PC 0x0c06d6ae */
if(!s->budget--) { s->failed_pc=0x0c06d6aeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,2);
if(!cond) { goto P_0c06d658; }
goto P_0c06d6b2;
P_0c06d6b0: /* original f62c, guest PC 0x0c06d6b0 */
if(!s->budget--) { s->failed_pc=0x0c06d6b0u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c06d6b2;
P_0c06d6b2: /* original ff5c, guest PC 0x0c06d6b2 */
if(!s->budget--) { s->failed_pc=0x0c06d6b2u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c06d6b4;
P_0c06d6b4: /* original ff52, guest PC 0x0c06d6b4 */
if(!s->budget--) { s->failed_pc=0x0c06d6b4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c06d6b6;
P_0c06d6b6: /* original f07c, guest PC 0x0c06d6b6 */
if(!s->budget--) { s->failed_pc=0x0c06d6b6u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06d6b8;
P_0c06d6b8: /* original c71d, guest PC 0x0c06d6b8 */
if(!s->budget--) { s->failed_pc=0x0c06d6b8u; return 0; }
r[0]=0x0c06d730u;
goto P_0c06d6ba;
P_0c06d6ba: /* original f3fc, guest PC 0x0c06d6ba */
if(!s->budget--) { s->failed_pc=0x0c06d6bau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06d6bc;
P_0c06d6bc: /* original f37e, guest PC 0x0c06d6bc */
if(!s->budget--) { s->failed_pc=0x0c06d6bcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06d6be;
P_0c06d6be: /* original f06c, guest PC 0x0c06d6be */
if(!s->budget--) { s->failed_pc=0x0c06d6beu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c06d6c0;
P_0c06d6c0: /* original f23c, guest PC 0x0c06d6c0 */
if(!s->budget--) { s->failed_pc=0x0c06d6c0u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c06d6c2;
P_0c06d6c2: /* original f26e, guest PC 0x0c06d6c2 */
if(!s->budget--) { s->failed_pc=0x0c06d6c2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c06d6c4;
P_0c06d6c4: /* original f308, guest PC 0x0c06d6c4 */
if(!s->budget--) { s->failed_pc=0x0c06d6c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06d6c6;
P_0c06d6c6: /* original ff2c, guest PC 0x0c06d6c6 */
if(!s->budget--) { s->failed_pc=0x0c06d6c6u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c06d6c8;
P_0c06d6c8: /* original f3f5, guest PC 0x0c06d6c8 */
if(!s->budget--) { s->failed_pc=0x0c06d6c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c06d6ca;
P_0c06d6ca: /* original 8b01, guest PC 0x0c06d6ca */
if(!s->budget--) { s->failed_pc=0x0c06d6cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6d0; }
goto P_0c06d6cc;
P_0c06d6cc: /* original a002, guest PC 0x0c06d6cc */
if(!s->budget--) { s->failed_pc=0x0c06d6ccu; return 0; }
fr[4]=0;
goto P_0c06d6d4;
P_0c06d6ce: /* original f48d, guest PC 0x0c06d6ce */
if(!s->budget--) { s->failed_pc=0x0c06d6ceu; return 0; }
fr[4]=0;
goto P_0c06d6d0;
P_0c06d6d0: /* original f4fc, guest PC 0x0c06d6d0 */
if(!s->budget--) { s->failed_pc=0x0c06d6d0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06d6d2;
P_0c06d6d2: /* original f47d, guest PC 0x0c06d6d2 */
if(!s->budget--) { s->failed_pc=0x0c06d6d2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06d6d4;
P_0c06d6d4: /* original f742, guest PC 0x0c06d6d4 */
if(!s->budget--) { s->failed_pc=0x0c06d6d4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06d6d6;
P_0c06d6d6: /* original e004, guest PC 0x0c06d6d6 */
if(!s->budget--) { s->failed_pc=0x0c06d6d6u; return 0; }
r[0]=0x00000004u;
goto P_0c06d6d8;
P_0c06d6d8: /* original f642, guest PC 0x0c06d6d8 */
if(!s->budget--) { s->failed_pc=0x0c06d6d8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c06d6da;
P_0c06d6da: /* original f542, guest PC 0x0c06d6da */
if(!s->budget--) { s->failed_pc=0x0c06d6dau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c06d6dc;
P_0c06d6dc: /* original fe5a, guest PC 0x0c06d6dc */
if(!s->budget--) { s->failed_pc=0x0c06d6dcu; return 0; }
vf3_matrix_store(s,ram,5,r[14]);
goto P_0c06d6de;
P_0c06d6de: /* original fe77, guest PC 0x0c06d6de */
if(!s->budget--) { s->failed_pc=0x0c06d6deu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06d6e0;
P_0c06d6e0: /* original e008, guest PC 0x0c06d6e0 */
if(!s->budget--) { s->failed_pc=0x0c06d6e0u; return 0; }
r[0]=0x00000008u;
goto P_0c06d6e2;
P_0c06d6e2: /* original fe67, guest PC 0x0c06d6e2 */
if(!s->budget--) { s->failed_pc=0x0c06d6e2u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06d6e4;
P_0c06d6e4: /* original d313, guest PC 0x0c06d6e4 */
if(!s->budget--) { s->failed_pc=0x0c06d6e4u; return 0; }
r[3]=read(ram,0x0c06d734u,4);
goto P_0c06d6e6;
P_0c06d6e6: /* original 430b, guest PC 0x0c06d6e6 */
if(!s->budget--) { s->failed_pc=0x0c06d6e6u; return 0; }
target=r[3];
r[16]=0x0c06d6eau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06d6eau) { target=s->pc; goto dispatch; }
goto P_0c06d6ea;
P_0c06d6e8: /* original 64e3, guest PC 0x0c06d6e8 */
if(!s->budget--) { s->failed_pc=0x0c06d6e8u; return 0; }
r[4]=r[14];
goto P_0c06d6ea;
P_0c06d6ea: /* original ffe5, guest PC 0x0c06d6ea */
if(!s->budget--) { s->failed_pc=0x0c06d6eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c06d6ec;
P_0c06d6ec: /* original 8b01, guest PC 0x0c06d6ec */
if(!s->budget--) { s->failed_pc=0x0c06d6ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6f2; }
goto P_0c06d6ee;
P_0c06d6ee: /* original a005, guest PC 0x0c06d6ee */
if(!s->budget--) { s->failed_pc=0x0c06d6eeu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c06d6fc;
P_0c06d6f0: /* original ffec, guest PC 0x0c06d6f0 */
if(!s->budget--) { s->failed_pc=0x0c06d6f0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c06d6f2;
P_0c06d6f2: /* original c711, guest PC 0x0c06d6f2 */
if(!s->budget--) { s->failed_pc=0x0c06d6f2u; return 0; }
r[0]=0x0c06d738u;
goto P_0c06d6f4;
P_0c06d6f4: /* original f408, guest PC 0x0c06d6f4 */
if(!s->budget--) { s->failed_pc=0x0c06d6f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06d6f6;
P_0c06d6f6: /* original f4f5, guest PC 0x0c06d6f6 */
if(!s->budget--) { s->failed_pc=0x0c06d6f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c06d6f8;
P_0c06d6f8: /* original 8b00, guest PC 0x0c06d6f8 */
if(!s->budget--) { s->failed_pc=0x0c06d6f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d6fc; }
goto P_0c06d6fa;
P_0c06d6fa: /* original ff4c, guest PC 0x0c06d6fa */
if(!s->budget--) { s->failed_pc=0x0c06d6fau; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c06d6fc;
P_0c06d6fc: /* original 7f0c, guest PC 0x0c06d6fc */
if(!s->budget--) { s->failed_pc=0x0c06d6fcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06d6fe;
P_0c06d6fe: /* original f0fc, guest PC 0x0c06d6fe */
if(!s->budget--) { s->failed_pc=0x0c06d6feu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c06d700;
P_0c06d700: /* original 4f26, guest PC 0x0c06d700 */
if(!s->budget--) { s->failed_pc=0x0c06d700u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d702;
P_0c06d702: /* original fef9, guest PC 0x0c06d702 */
if(!s->budget--) { s->failed_pc=0x0c06d702u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d704;
P_0c06d704: /* original fff9, guest PC 0x0c06d704 */
if(!s->budget--) { s->failed_pc=0x0c06d704u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06d706;
P_0c06d706: /* original 000b, guest PC 0x0c06d706 */
if(!s->budget--) { s->failed_pc=0x0c06d706u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06d708: /* original 6ef6, guest PC 0x0c06d708 */
if(!s->budget--) { s->failed_pc=0x0c06d708u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06d70au,s,ram);
P_0c07e104: /* original 4f22, guest PC 0x0c07e104 */
if(!s->budget--) { s->failed_pc=0x0c07e104u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e106;
P_0c07e106: /* original 7ff8, guest PC 0x0c07e106 */
if(!s->budget--) { s->failed_pc=0x0c07e106u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e108;
P_0c07e108: /* original 2f52, guest PC 0x0c07e108 */
if(!s->budget--) { s->failed_pc=0x0c07e108u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c07e10a;
P_0c07e10a: /* original 6231, guest PC 0x0c07e10a */
if(!s->budget--) { s->failed_pc=0x0c07e10au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c07e10c;
P_0c07e10c: /* original d929, guest PC 0x0c07e10c */
if(!s->budget--) { s->failed_pc=0x0c07e10cu; return 0; }
r[9]=read(ram,0x0c07e1b4u,4);
goto P_0c07e10e;
P_0c07e10e: /* original 622d, guest PC 0x0c07e10e */
if(!s->budget--) { s->failed_pc=0x0c07e10eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c07e110;
P_0c07e110: /* original 1f21, guest PC 0x0c07e110 */
if(!s->budget--) { s->failed_pc=0x0c07e110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07e112;
P_0c07e112: /* original d329, guest PC 0x0c07e112 */
if(!s->budget--) { s->failed_pc=0x0c07e112u; return 0; }
r[3]=read(ram,0x0c07e1b8u,4);
goto P_0c07e114;
P_0c07e114: /* original 430b, guest PC 0x0c07e114 */
if(!s->budget--) { s->failed_pc=0x0c07e114u; return 0; }
target=r[3];
r[16]=0x0c07e118u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e118u) { target=s->pc; goto dispatch; }
goto P_0c07e118;
P_0c07e116: /* original 6493, guest PC 0x0c07e116 */
if(!s->budget--) { s->failed_pc=0x0c07e116u; return 0; }
r[4]=r[9];
goto P_0c07e118;
P_0c07e118: /* original dc28, guest PC 0x0c07e118 */
if(!s->budget--) { s->failed_pc=0x0c07e118u; return 0; }
r[12]=read(ram,0x0c07e1bcu,4);
goto P_0c07e11a;
P_0c07e11a: /* original e804, guest PC 0x0c07e11a */
if(!s->budget--) { s->failed_pc=0x0c07e11au; return 0; }
r[8]=0x00000004u;
goto P_0c07e11c;
P_0c07e11c: /* original 7e44, guest PC 0x0c07e11c */
if(!s->budget--) { s->failed_pc=0x0c07e11cu; return 0; }
r[14]+=0x00000044u;
goto P_0c07e11e;
P_0c07e11e: /* original eb00, guest PC 0x0c07e11e */
if(!s->budget--) { s->failed_pc=0x0c07e11eu; return 0; }
r[11]=0x00000000u;
goto P_0c07e120;
P_0c07e120: /* original ea04, guest PC 0x0c07e120 */
if(!s->budget--) { s->failed_pc=0x0c07e120u; return 0; }
r[10]=0x00000004u;
goto P_0c07e122;
P_0c07e122: /* original ed00, guest PC 0x0c07e122 */
if(!s->budget--) { s->failed_pc=0x0c07e122u; return 0; }
r[13]=0x00000000u;
goto P_0c07e124;
P_0c07e124: /* original e004, guest PC 0x0c07e124 */
if(!s->budget--) { s->failed_pc=0x0c07e124u; return 0; }
r[0]=0x00000004u;
goto P_0c07e126;
P_0c07e126: /* original f5e8, guest PC 0x0c07e126 */
if(!s->budget--) { s->failed_pc=0x0c07e126u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c07e128;
P_0c07e128: /* original f4e6, guest PC 0x0c07e128 */
if(!s->budget--) { s->failed_pc=0x0c07e128u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c07e12a;
P_0c07e12a: /* original e008, guest PC 0x0c07e12a */
if(!s->budget--) { s->failed_pc=0x0c07e12au; return 0; }
r[0]=0x00000008u;
goto P_0c07e12c;
P_0c07e12c: /* original f6e6, guest PC 0x0c07e12c */
if(!s->budget--) { s->failed_pc=0x0c07e12cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c07e12e;
P_0c07e12e: /* original e00c, guest PC 0x0c07e12e */
if(!s->budget--) { s->failed_pc=0x0c07e12eu; return 0; }
r[0]=0x0000000cu;
goto P_0c07e130;
P_0c07e130: /* original f7e6, guest PC 0x0c07e130 */
if(!s->budget--) { s->failed_pc=0x0c07e130u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c07e132;
P_0c07e132: /* original e004, guest PC 0x0c07e132 */
if(!s->budget--) { s->failed_pc=0x0c07e132u; return 0; }
r[0]=0x00000004u;
goto P_0c07e134;
P_0c07e134: /* original f560, guest PC 0x0c07e134 */
if(!s->budget--) { s->failed_pc=0x0c07e134u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c07e136;
P_0c07e136: /* original f470, guest PC 0x0c07e136 */
if(!s->budget--) { s->failed_pc=0x0c07e136u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c07e138;
P_0c07e138: /* original f53d, guest PC 0x0c07e138 */
if(!s->budget--) { s->failed_pc=0x0c07e138u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c07e13a;
P_0c07e13a: /* original fe5a, guest PC 0x0c07e13a */
if(!s->budget--) { s->failed_pc=0x0c07e13au; return 0; }
vf3_matrix_store(s,ram,5,r[14]);
goto P_0c07e13c;
P_0c07e13c: /* original fe47, guest PC 0x0c07e13c */
if(!s->budget--) { s->failed_pc=0x0c07e13cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07e13e;
P_0c07e13e: /* original 60d3, guest PC 0x0c07e13e */
if(!s->budget--) { s->failed_pc=0x0c07e13eu; return 0; }
r[0]=r[13];
goto P_0c07e140;
P_0c07e140: /* original 8830, guest PC 0x0c07e140 */
if(!s->budget--) { s->failed_pc=0x0c07e140u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000030u)!=0);
goto P_0c07e142;
P_0c07e142: /* original 075a, guest PC 0x0c07e142 */
if(!s->budget--) { s->failed_pc=0x0c07e142u; return 0; }
r[7]=r[53];
goto P_0c07e144;
P_0c07e144: /* original f43d, guest PC 0x0c07e144 */
if(!s->budget--) { s->failed_pc=0x0c07e144u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c07e146;
P_0c07e146: /* original 27c9, guest PC 0x0c07e146 */
if(!s->budget--) { s->failed_pc=0x0c07e146u; return 0; }
r[7]&=r[12];
goto P_0c07e148;
P_0c07e148: /* original 045a, guest PC 0x0c07e148 */
if(!s->budget--) { s->failed_pc=0x0c07e148u; return 0; }
r[4]=r[53];
goto P_0c07e14a;
P_0c07e14a: /* original 24c9, guest PC 0x0c07e14a */
if(!s->budget--) { s->failed_pc=0x0c07e14au; return 0; }
r[4]&=r[12];
goto P_0c07e14c;
P_0c07e14c: /* original 4428, guest PC 0x0c07e14c */
if(!s->budget--) { s->failed_pc=0x0c07e14cu; return 0; }
r[4]<<=16;
goto P_0c07e14e;
P_0c07e14e: /* original 274b, guest PC 0x0c07e14e */
if(!s->budget--) { s->failed_pc=0x0c07e14eu; return 0; }
r[7]|=r[4];
goto P_0c07e150;
P_0c07e150: /* original 9421, guest PC 0x0c07e150 */
if(!s->budget--) { s->failed_pc=0x0c07e150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e196u,2);
goto P_0c07e152;
P_0c07e152: /* original 8f01, guest PC 0x0c07e152 */
if(!s->budget--) { s->failed_pc=0x0c07e152u; return 0; }
cond=r[17]&1u;
r[2]=r[13];
if(!cond) { goto P_0c07e158; }
goto P_0c07e156;
P_0c07e154: /* original 62d3, guest PC 0x0c07e154 */
if(!s->budget--) { s->failed_pc=0x0c07e154u; return 0; }
r[2]=r[13];
goto P_0c07e156;
P_0c07e156: /* original 941f, guest PC 0x0c07e156 */
if(!s->budget--) { s->failed_pc=0x0c07e156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e198u,2);
goto P_0c07e158;
P_0c07e158: /* original 4228, guest PC 0x0c07e158 */
if(!s->budget--) { s->failed_pc=0x0c07e158u; return 0; }
r[2]<<=16;
goto P_0c07e15a;
P_0c07e15a: /* original 6693, guest PC 0x0c07e15a */
if(!s->budget--) { s->failed_pc=0x0c07e15au; return 0; }
r[6]=r[9];
goto P_0c07e15c;
P_0c07e15c: /* original 4218, guest PC 0x0c07e15c */
if(!s->budget--) { s->failed_pc=0x0c07e15cu; return 0; }
r[2]<<=8;
goto P_0c07e15e;
P_0c07e15e: /* original e341, guest PC 0x0c07e15e */
if(!s->budget--) { s->failed_pc=0x0c07e15eu; return 0; }
r[3]=0x00000041u;
goto P_0c07e160;
P_0c07e160: /* original 22bb, guest PC 0x0c07e160 */
if(!s->budget--) { s->failed_pc=0x0c07e160u; return 0; }
r[2]|=r[11];
goto P_0c07e162;
P_0c07e162: /* original 2f36, guest PC 0x0c07e162 */
if(!s->budget--) { s->failed_pc=0x0c07e162u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e164;
P_0c07e164: /* original 242b, guest PC 0x0c07e164 */
if(!s->budget--) { s->failed_pc=0x0c07e164u; return 0; }
r[4]|=r[2];
goto P_0c07e166;
P_0c07e166: /* original 2f46, guest PC 0x0c07e166 */
if(!s->budget--) { s->failed_pc=0x0c07e166u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e168;
P_0c07e168: /* original d215, guest PC 0x0c07e168 */
if(!s->budget--) { s->failed_pc=0x0c07e168u; return 0; }
r[2]=read(ram,0x0c07e1c0u,4);
goto P_0c07e16a;
P_0c07e16a: /* original 55f3, guest PC 0x0c07e16a */
if(!s->budget--) { s->failed_pc=0x0c07e16au; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07e16c;
P_0c07e16c: /* original 420b, guest PC 0x0c07e16c */
if(!s->budget--) { s->failed_pc=0x0c07e16cu; return 0; }
target=r[2];
r[16]=0x0c07e170u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e170u) { target=s->pc; goto dispatch; }
goto P_0c07e170;
P_0c07e16e: /* original 54f2, guest PC 0x0c07e16e */
if(!s->budget--) { s->failed_pc=0x0c07e16eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07e170;
P_0c07e170: /* original 4a10, guest PC 0x0c07e170 */
if(!s->budget--) { s->failed_pc=0x0c07e170u; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c07e172;
P_0c07e172: /* original 7e10, guest PC 0x0c07e172 */
if(!s->budget--) { s->failed_pc=0x0c07e172u; return 0; }
r[14]+=0x00000010u;
goto P_0c07e174;
P_0c07e174: /* original 7f08, guest PC 0x0c07e174 */
if(!s->budget--) { s->failed_pc=0x0c07e174u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e176;
P_0c07e176: /* original 8fd5, guest PC 0x0c07e176 */
if(!s->budget--) { s->failed_pc=0x0c07e176u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000010u;
if(!cond) { goto P_0c07e124; }
goto P_0c07e17a;
P_0c07e178: /* original 7d10, guest PC 0x0c07e178 */
if(!s->budget--) { s->failed_pc=0x0c07e178u; return 0; }
r[13]+=0x00000010u;
goto P_0c07e17a;
P_0c07e17a: /* original d212, guest PC 0x0c07e17a */
if(!s->budget--) { s->failed_pc=0x0c07e17au; return 0; }
r[2]=read(ram,0x0c07e1c4u,4);
goto P_0c07e17c;
P_0c07e17c: /* original 4810, guest PC 0x0c07e17c */
if(!s->budget--) { s->failed_pc=0x0c07e17cu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c07e17e;
P_0c07e17e: /* original 8fcf, guest PC 0x0c07e17e */
if(!s->budget--) { s->failed_pc=0x0c07e17eu; return 0; }
cond=r[17]&1u;
r[11]+=r[2];
if(!cond) { goto P_0c07e120; }
goto P_0c07e182;
P_0c07e180: /* original 3b2c, guest PC 0x0c07e180 */
if(!s->budget--) { s->failed_pc=0x0c07e180u; return 0; }
r[11]+=r[2];
goto P_0c07e182;
P_0c07e182: /* original 7f08, guest PC 0x0c07e182 */
if(!s->budget--) { s->failed_pc=0x0c07e182u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e184;
P_0c07e184: /* original 4f26, guest PC 0x0c07e184 */
if(!s->budget--) { s->failed_pc=0x0c07e184u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e186;
P_0c07e186: /* original 68f6, guest PC 0x0c07e186 */
if(!s->budget--) { s->failed_pc=0x0c07e186u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07e188;
P_0c07e188: /* original 69f6, guest PC 0x0c07e188 */
if(!s->budget--) { s->failed_pc=0x0c07e188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07e18a;
P_0c07e18a: /* original 6af6, guest PC 0x0c07e18a */
if(!s->budget--) { s->failed_pc=0x0c07e18au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07e18c;
P_0c07e18c: /* original 6bf6, guest PC 0x0c07e18c */
if(!s->budget--) { s->failed_pc=0x0c07e18cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07e18e;
P_0c07e18e: /* original 6cf6, guest PC 0x0c07e18e */
if(!s->budget--) { s->failed_pc=0x0c07e18eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07e190;
P_0c07e190: /* original 6df6, guest PC 0x0c07e190 */
if(!s->budget--) { s->failed_pc=0x0c07e190u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07e192;
P_0c07e192: /* original 000b, guest PC 0x0c07e192 */
if(!s->budget--) { s->failed_pc=0x0c07e192u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07e194: /* original 6ef6, guest PC 0x0c07e194 */
if(!s->budget--) { s->failed_pc=0x0c07e194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07e196u,s,ram);
P_0c0806e4: /* original 4f22, guest PC 0x0c0806e4 */
if(!s->budget--) { s->failed_pc=0x0c0806e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0806e6;
P_0c0806e6: /* original 6c0d, guest PC 0x0c0806e6 */
if(!s->budget--) { s->failed_pc=0x0c0806e6u; return 0; }
r[12]=r[0]&65535u;
goto P_0c0806e8;
P_0c0806e8: /* original 63e3, guest PC 0x0c0806e8 */
if(!s->budget--) { s->failed_pc=0x0c0806e8u; return 0; }
r[3]=r[14];
goto P_0c0806ea;
P_0c0806ea: /* original 4300, guest PC 0x0c0806ea */
if(!s->budget--) { s->failed_pc=0x0c0806eau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0806ec;
P_0c0806ec: /* original 8542, guest PC 0x0c0806ec */
if(!s->budget--) { s->failed_pc=0x0c0806ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c0806ee;
P_0c0806ee: /* original 4c2d, guest PC 0x0c0806ee */
if(!s->budget--) { s->failed_pc=0x0c0806eeu; return 0; }
r[12]=(r[2]&0x80000000u)?((r[2]&31u)?r[12]>>((-r[2])&31u):0):r[12]<<(r[2]&31u);
goto P_0c0806f0;
P_0c0806f0: /* original 23cb, guest PC 0x0c0806f0 */
if(!s->budget--) { s->failed_pc=0x0c0806f0u; return 0; }
r[3]|=r[12];
goto P_0c0806f2;
P_0c0806f2: /* original 7ffc, guest PC 0x0c0806f2 */
if(!s->budget--) { s->failed_pc=0x0c0806f2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0806f4;
P_0c0806f4: /* original 6d0d, guest PC 0x0c0806f4 */
if(!s->budget--) { s->failed_pc=0x0c0806f4u; return 0; }
r[13]=r[0]&65535u;
goto P_0c0806f6;
P_0c0806f6: /* original 2f32, guest PC 0x0c0806f6 */
if(!s->budget--) { s->failed_pc=0x0c0806f6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0806f8;
P_0c0806f8: /* original db22, guest PC 0x0c0806f8 */
if(!s->budget--) { s->failed_pc=0x0c0806f8u; return 0; }
r[11]=read(ram,0x0c080784u,4);
goto P_0c0806fa;
P_0c0806fa: /* original 65d3, guest PC 0x0c0806fa */
if(!s->budget--) { s->failed_pc=0x0c0806fau; return 0; }
r[5]=r[13];
goto P_0c0806fc;
P_0c0806fc: /* original da23, guest PC 0x0c0806fc */
if(!s->budget--) { s->failed_pc=0x0c0806fcu; return 0; }
r[10]=read(ram,0x0c08078cu,4);
goto P_0c0806fe;
P_0c0806fe: /* original 66b3, guest PC 0x0c0806fe */
if(!s->budget--) { s->failed_pc=0x0c0806feu; return 0; }
r[6]=r[11];
goto P_0c080700;
P_0c080700: /* original 2f96, guest PC 0x0c080700 */
if(!s->budget--) { s->failed_pc=0x0c080700u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080702;
P_0c080702: /* original 4a0b, guest PC 0x0c080702 */
if(!s->budget--) { s->failed_pc=0x0c080702u; return 0; }
target=r[10];
r[16]=0x0c080706u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080706u) { target=s->pc; goto dispatch; }
goto P_0c080706;
P_0c080704: /* original 54f1, guest PC 0x0c080704 */
if(!s->budget--) { s->failed_pc=0x0c080704u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080706;
P_0c080706: /* original 9334, guest PC 0x0c080706 */
if(!s->budget--) { s->failed_pc=0x0c080706u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080772u,2);
goto P_0c080708;
P_0c080708: /* original 3d30, guest PC 0x0c080708 */
if(!s->budget--) { s->failed_pc=0x0c080708u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c08070a;
P_0c08070a: /* original 8f09, guest PC 0x0c08070a */
if(!s->budget--) { s->failed_pc=0x0c08070au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c080720; }
goto P_0c08070e;
P_0c08070c: /* original 7f04, guest PC 0x0c08070c */
if(!s->budget--) { s->failed_pc=0x0c08070cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08070e;
P_0c08070e: /* original 7e0d, guest PC 0x0c08070e */
if(!s->budget--) { s->failed_pc=0x0c08070eu; return 0; }
r[14]+=0x0000000du;
goto P_0c080710;
P_0c080710: /* original 4e00, guest PC 0x0c080710 */
if(!s->budget--) { s->failed_pc=0x0c080710u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c080712;
P_0c080712: /* original 2ecb, guest PC 0x0c080712 */
if(!s->budget--) { s->failed_pc=0x0c080712u; return 0; }
r[14]|=r[12];
goto P_0c080714;
P_0c080714: /* original 2fe2, guest PC 0x0c080714 */
if(!s->budget--) { s->failed_pc=0x0c080714u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c080716;
P_0c080716: /* original e700, guest PC 0x0c080716 */
if(!s->budget--) { s->failed_pc=0x0c080716u; return 0; }
r[7]=0x00000000u;
goto P_0c080718;
P_0c080718: /* original 2f96, guest PC 0x0c080718 */
if(!s->budget--) { s->failed_pc=0x0c080718u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08071a;
P_0c08071a: /* original 952b, guest PC 0x0c08071a */
if(!s->budget--) { s->failed_pc=0x0c08071au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080774u,2);
goto P_0c08071c;
P_0c08071c: /* original a00b, guest PC 0x0c08071c */
if(!s->budget--) { s->failed_pc=0x0c08071cu; return 0; }
r[6]=r[11];
goto P_0c080736;
P_0c08071e: /* original 66b3, guest PC 0x0c08071e */
if(!s->budget--) { s->failed_pc=0x0c08071eu; return 0; }
r[6]=r[11];
goto P_0c080720;
P_0c080720: /* original 9229, guest PC 0x0c080720 */
if(!s->budget--) { s->failed_pc=0x0c080720u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080776u,2);
goto P_0c080722;
P_0c080722: /* original 3d20, guest PC 0x0c080722 */
if(!s->budget--) { s->failed_pc=0x0c080722u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c080724;
P_0c080724: /* original 8b0b, guest PC 0x0c080724 */
if(!s->budget--) { s->failed_pc=0x0c080724u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08073e; }
goto P_0c080726;
P_0c080726: /* original 7e0c, guest PC 0x0c080726 */
if(!s->budget--) { s->failed_pc=0x0c080726u; return 0; }
r[14]+=0x0000000cu;
goto P_0c080728;
P_0c080728: /* original 66b3, guest PC 0x0c080728 */
if(!s->budget--) { s->failed_pc=0x0c080728u; return 0; }
r[6]=r[11];
goto P_0c08072a;
P_0c08072a: /* original 4e00, guest PC 0x0c08072a */
if(!s->budget--) { s->failed_pc=0x0c08072au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c08072c;
P_0c08072c: /* original 2ecb, guest PC 0x0c08072c */
if(!s->budget--) { s->failed_pc=0x0c08072cu; return 0; }
r[14]|=r[12];
goto P_0c08072e;
P_0c08072e: /* original 2fe2, guest PC 0x0c08072e */
if(!s->budget--) { s->failed_pc=0x0c08072eu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c080730;
P_0c080730: /* original e700, guest PC 0x0c080730 */
if(!s->budget--) { s->failed_pc=0x0c080730u; return 0; }
r[7]=0x00000000u;
goto P_0c080732;
P_0c080732: /* original 2f96, guest PC 0x0c080732 */
if(!s->budget--) { s->failed_pc=0x0c080732u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080734;
P_0c080734: /* original 9520, guest PC 0x0c080734 */
if(!s->budget--) { s->failed_pc=0x0c080734u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080778u,2);
goto P_0c080736;
P_0c080736: /* original 4a0b, guest PC 0x0c080736 */
if(!s->budget--) { s->failed_pc=0x0c080736u; return 0; }
target=r[10];
r[16]=0x0c08073au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08073au) { target=s->pc; goto dispatch; }
goto P_0c08073a;
P_0c080738: /* original 54f1, guest PC 0x0c080738 */
if(!s->budget--) { s->failed_pc=0x0c080738u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08073a;
P_0c08073a: /* original a00e, guest PC 0x0c08073a */
if(!s->budget--) { s->failed_pc=0x0c08073au; return 0; }
r[15]+=0x00000004u;
goto P_0c08075a;
P_0c08073c: /* original 7f04, guest PC 0x0c08073c */
if(!s->budget--) { s->failed_pc=0x0c08073cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08073e;
P_0c08073e: /* original 911c, guest PC 0x0c08073e */
if(!s->budget--) { s->failed_pc=0x0c08073eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08077au,2);
goto P_0c080740;
P_0c080740: /* original 3d10, guest PC 0x0c080740 */
if(!s->budget--) { s->failed_pc=0x0c080740u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c080742;
P_0c080742: /* original 8b0a, guest PC 0x0c080742 */
if(!s->budget--) { s->failed_pc=0x0c080742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08075a; }
goto P_0c080744;
P_0c080744: /* original 7e0c, guest PC 0x0c080744 */
if(!s->budget--) { s->failed_pc=0x0c080744u; return 0; }
r[14]+=0x0000000cu;
goto P_0c080746;
P_0c080746: /* original 66b3, guest PC 0x0c080746 */
if(!s->budget--) { s->failed_pc=0x0c080746u; return 0; }
r[6]=r[11];
goto P_0c080748;
P_0c080748: /* original 4e00, guest PC 0x0c080748 */
if(!s->budget--) { s->failed_pc=0x0c080748u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c08074a;
P_0c08074a: /* original 2ecb, guest PC 0x0c08074a */
if(!s->budget--) { s->failed_pc=0x0c08074au; return 0; }
r[14]|=r[12];
goto P_0c08074c;
P_0c08074c: /* original 2fe2, guest PC 0x0c08074c */
if(!s->budget--) { s->failed_pc=0x0c08074cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08074e;
P_0c08074e: /* original e700, guest PC 0x0c08074e */
if(!s->budget--) { s->failed_pc=0x0c08074eu; return 0; }
r[7]=0x00000000u;
goto P_0c080750;
P_0c080750: /* original 2f96, guest PC 0x0c080750 */
if(!s->budget--) { s->failed_pc=0x0c080750u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080752;
P_0c080752: /* original 9513, guest PC 0x0c080752 */
if(!s->budget--) { s->failed_pc=0x0c080752u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08077cu,2);
goto P_0c080754;
P_0c080754: /* original 4a0b, guest PC 0x0c080754 */
if(!s->budget--) { s->failed_pc=0x0c080754u; return 0; }
target=r[10];
r[16]=0x0c080758u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080758u) { target=s->pc; goto dispatch; }
goto P_0c080758;
P_0c080756: /* original 54f1, guest PC 0x0c080756 */
if(!s->budget--) { s->failed_pc=0x0c080756u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080758;
P_0c080758: /* original 7f04, guest PC 0x0c080758 */
if(!s->budget--) { s->failed_pc=0x0c080758u; return 0; }
r[15]+=0x00000004u;
goto P_0c08075a;
P_0c08075a: /* original 7f04, guest PC 0x0c08075a */
if(!s->budget--) { s->failed_pc=0x0c08075au; return 0; }
r[15]+=0x00000004u;
goto P_0c08075c;
P_0c08075c: /* original 4f26, guest PC 0x0c08075c */
if(!s->budget--) { s->failed_pc=0x0c08075cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08075e;
P_0c08075e: /* original 69f6, guest PC 0x0c08075e */
if(!s->budget--) { s->failed_pc=0x0c08075eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080760;
P_0c080760: /* original 6af6, guest PC 0x0c080760 */
if(!s->budget--) { s->failed_pc=0x0c080760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080762;
P_0c080762: /* original 6bf6, guest PC 0x0c080762 */
if(!s->budget--) { s->failed_pc=0x0c080762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080764;
P_0c080764: /* original 6cf6, guest PC 0x0c080764 */
if(!s->budget--) { s->failed_pc=0x0c080764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080766;
P_0c080766: /* original 6df6, guest PC 0x0c080766 */
if(!s->budget--) { s->failed_pc=0x0c080766u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080768;
P_0c080768: /* original 000b, guest PC 0x0c080768 */
if(!s->budget--) { s->failed_pc=0x0c080768u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08076a: /* original 6ef6, guest PC 0x0c08076a */
if(!s->budget--) { s->failed_pc=0x0c08076au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08076cu,s,ram);
P_0c080d2c: /* original 4f22, guest PC 0x0c080d2c */
if(!s->budget--) { s->failed_pc=0x0c080d2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080d2e;
P_0c080d2e: /* original d332, guest PC 0x0c080d2e */
if(!s->budget--) { s->failed_pc=0x0c080d2eu; return 0; }
r[3]=read(ram,0x0c080df8u,4);
goto P_0c080d30;
P_0c080d30: /* original 7fe4, guest PC 0x0c080d30 */
if(!s->budget--) { s->failed_pc=0x0c080d30u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c080d32;
P_0c080d32: /* original 1f32, guest PC 0x0c080d32 */
if(!s->budget--) { s->failed_pc=0x0c080d32u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c080d34;
P_0c080d34: /* original d431, guest PC 0x0c080d34 */
if(!s->budget--) { s->failed_pc=0x0c080d34u; return 0; }
r[4]=read(ram,0x0c080dfcu,4);
goto P_0c080d36;
P_0c080d36: /* original 534f, guest PC 0x0c080d36 */
if(!s->budget--) { s->failed_pc=0x0c080d36u; return 0; }
r[3]=read(ram,r[4]+60,4);
goto P_0c080d38;
P_0c080d38: /* original 1f34, guest PC 0x0c080d38 */
if(!s->budget--) { s->failed_pc=0x0c080d38u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c080d3a;
P_0c080d3a: /* original 024c, guest PC 0x0c080d3a */
if(!s->budget--) { s->failed_pc=0x0c080d3au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080d3c;
P_0c080d3c: /* original e014, guest PC 0x0c080d3c */
if(!s->budget--) { s->failed_pc=0x0c080d3cu; return 0; }
r[0]=0x00000014u;
goto P_0c080d3e;
P_0c080d3e: /* original 0f24, guest PC 0x0c080d3e */
if(!s->budget--) { s->failed_pc=0x0c080d3eu; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c080d40;
P_0c080d40: /* original e01b, guest PC 0x0c080d40 */
if(!s->budget--) { s->failed_pc=0x0c080d40u; return 0; }
r[0]=0x0000001bu;
goto P_0c080d42;
P_0c080d42: /* original 034c, guest PC 0x0c080d42 */
if(!s->budget--) { s->failed_pc=0x0c080d42u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080d44;
P_0c080d44: /* original e018, guest PC 0x0c080d44 */
if(!s->budget--) { s->failed_pc=0x0c080d44u; return 0; }
r[0]=0x00000018u;
goto P_0c080d46;
P_0c080d46: /* original e207, guest PC 0x0c080d46 */
if(!s->budget--) { s->failed_pc=0x0c080d46u; return 0; }
r[2]=0x00000007u;
goto P_0c080d48;
P_0c080d48: /* original 0f34, guest PC 0x0c080d48 */
if(!s->budget--) { s->failed_pc=0x0c080d48u; return 0; }
write(ram,r[15]+r[0],r[3],1);
goto P_0c080d4a;
P_0c080d4a: /* original d329, guest PC 0x0c080d4a */
if(!s->budget--) { s->failed_pc=0x0c080d4au; return 0; }
r[3]=read(ram,0x0c080df0u,4);
goto P_0c080d4c;
P_0c080d4c: /* original 6432, guest PC 0x0c080d4c */
if(!s->budget--) { s->failed_pc=0x0c080d4cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080d4e;
P_0c080d4e: /* original 1fe1, guest PC 0x0c080d4e */
if(!s->budget--) { s->failed_pc=0x0c080d4eu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c080d50;
P_0c080d50: /* original 7406, guest PC 0x0c080d50 */
if(!s->budget--) { s->failed_pc=0x0c080d50u; return 0; }
r[4]+=0x00000006u;
goto P_0c080d52;
P_0c080d52: /* original 6b43, guest PC 0x0c080d52 */
if(!s->budget--) { s->failed_pc=0x0c080d52u; return 0; }
r[11]=r[4];
goto P_0c080d54;
P_0c080d54: /* original 51f4, guest PC 0x0c080d54 */
if(!s->budget--) { s->failed_pc=0x0c080d54u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c080d56;
P_0c080d56: /* original 4b2c, guest PC 0x0c080d56 */
if(!s->budget--) { s->failed_pc=0x0c080d56u; return 0; }
r[11]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[11]>>((-r[2])&31u)):((int32_t)r[11]<0?0xffffffffu:0)):r[11]<<(r[2]&31u);
goto P_0c080d58;
P_0c080d58: /* original ec81, guest PC 0x0c080d58 */
if(!s->budget--) { s->failed_pc=0x0c080d58u; return 0; }
r[12]=0xffffff81u;
goto P_0c080d5a;
P_0c080d5a: /* original 4115, guest PC 0x0c080d5a */
if(!s->budget--) { s->failed_pc=0x0c080d5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c080d5c;
P_0c080d5c: /* original 8f35, guest PC 0x0c080d5c */
if(!s->budget--) { s->failed_pc=0x0c080d5cu; return 0; }
cond=r[17]&1u;
r[13]=0x0000007eu;
if(!cond) { goto P_0c080dca; }
goto P_0c080d60;
P_0c080d5e: /* original ed7e, guest PC 0x0c080d5e */
if(!s->budget--) { s->failed_pc=0x0c080d5eu; return 0; }
r[13]=0x0000007eu;
goto P_0c080d60;
P_0c080d60: /* original 62b3, guest PC 0x0c080d60 */
if(!s->budget--) { s->failed_pc=0x0c080d60u; return 0; }
r[2]=r[11];
goto P_0c080d62;
P_0c080d62: /* original 63a3, guest PC 0x0c080d62 */
if(!s->budget--) { s->failed_pc=0x0c080d62u; return 0; }
r[3]=r[10];
goto P_0c080d64;
P_0c080d64: /* original 22c9, guest PC 0x0c080d64 */
if(!s->budget--) { s->failed_pc=0x0c080d64u; return 0; }
r[2]&=r[12];
goto P_0c080d66;
P_0c080d66: /* original 23d9, guest PC 0x0c080d66 */
if(!s->budget--) { s->failed_pc=0x0c080d66u; return 0; }
r[3]&=r[13];
goto P_0c080d68;
P_0c080d68: /* original e014, guest PC 0x0c080d68 */
if(!s->budget--) { s->failed_pc=0x0c080d68u; return 0; }
r[0]=0x00000014u;
goto P_0c080d6a;
P_0c080d6a: /* original 232b, guest PC 0x0c080d6a */
if(!s->budget--) { s->failed_pc=0x0c080d6au; return 0; }
r[3]|=r[2];
goto P_0c080d6c;
P_0c080d6c: /* original 2f32, guest PC 0x0c080d6c */
if(!s->budget--) { s->failed_pc=0x0c080d6cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080d6e;
P_0c080d6e: /* original 9237, guest PC 0x0c080d6e */
if(!s->budget--) { s->failed_pc=0x0c080d6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de0u,2);
goto P_0c080d70;
P_0c080d70: /* original 1f23, guest PC 0x0c080d70 */
if(!s->budget--) { s->failed_pc=0x0c080d70u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c080d72;
P_0c080d72: /* original 01fc, guest PC 0x0c080d72 */
if(!s->budget--) { s->failed_pc=0x0c080d72u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c080d74;
P_0c080d74: /* original 3183, guest PC 0x0c080d74 */
if(!s->budget--) { s->failed_pc=0x0c080d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[8])!=0);
goto P_0c080d76;
P_0c080d76: /* original 8f02, guest PC 0x0c080d76 */
if(!s->budget--) { s->failed_pc=0x0c080d76u; return 0; }
cond=r[17]&1u;
r[10]+=0xfffffffcu;
if(!cond) { goto P_0c080d7e; }
goto P_0c080d7a;
P_0c080d78: /* original 7afc, guest PC 0x0c080d78 */
if(!s->budget--) { s->failed_pc=0x0c080d78u; return 0; }
r[10]+=0xfffffffcu;
goto P_0c080d7a;
P_0c080d7a: /* original 9132, guest PC 0x0c080d7a */
if(!s->budget--) { s->failed_pc=0x0c080d7au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de2u,2);
goto P_0c080d7c;
P_0c080d7c: /* original 1f13, guest PC 0x0c080d7c */
if(!s->budget--) { s->failed_pc=0x0c080d7cu; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c080d7e;
P_0c080d7e: /* original 2fe6, guest PC 0x0c080d7e */
if(!s->budget--) { s->failed_pc=0x0c080d7eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d80;
P_0c080d80: /* original e700, guest PC 0x0c080d80 */
if(!s->budget--) { s->failed_pc=0x0c080d80u; return 0; }
r[7]=0x00000000u;
goto P_0c080d82;
P_0c080d82: /* original 55f4, guest PC 0x0c080d82 */
if(!s->budget--) { s->failed_pc=0x0c080d82u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c080d84;
P_0c080d84: /* original d31e, guest PC 0x0c080d84 */
if(!s->budget--) { s->failed_pc=0x0c080d84u; return 0; }
r[3]=read(ram,0x0c080e00u,4);
goto P_0c080d86;
P_0c080d86: /* original 56f3, guest PC 0x0c080d86 */
if(!s->budget--) { s->failed_pc=0x0c080d86u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080d88;
P_0c080d88: /* original 430b, guest PC 0x0c080d88 */
if(!s->budget--) { s->failed_pc=0x0c080d88u; return 0; }
target=r[3];
r[16]=0x0c080d8cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080d8cu) { target=s->pc; goto dispatch; }
goto P_0c080d8c;
P_0c080d8a: /* original 54f1, guest PC 0x0c080d8a */
if(!s->budget--) { s->failed_pc=0x0c080d8au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080d8c;
P_0c080d8c: /* original 63b3, guest PC 0x0c080d8c */
if(!s->budget--) { s->failed_pc=0x0c080d8cu; return 0; }
r[3]=r[11];
goto P_0c080d8e;
P_0c080d8e: /* original 6293, guest PC 0x0c080d8e */
if(!s->budget--) { s->failed_pc=0x0c080d8eu; return 0; }
r[2]=r[9];
goto P_0c080d90;
P_0c080d90: /* original 23c9, guest PC 0x0c080d90 */
if(!s->budget--) { s->failed_pc=0x0c080d90u; return 0; }
r[3]&=r[12];
goto P_0c080d92;
P_0c080d92: /* original 22d9, guest PC 0x0c080d92 */
if(!s->budget--) { s->failed_pc=0x0c080d92u; return 0; }
r[2]&=r[13];
goto P_0c080d94;
P_0c080d94: /* original e018, guest PC 0x0c080d94 */
if(!s->budget--) { s->failed_pc=0x0c080d94u; return 0; }
r[0]=0x00000018u;
goto P_0c080d96;
P_0c080d96: /* original 223b, guest PC 0x0c080d96 */
if(!s->budget--) { s->failed_pc=0x0c080d96u; return 0; }
r[2]|=r[3];
goto P_0c080d98;
P_0c080d98: /* original 7f04, guest PC 0x0c080d98 */
if(!s->budget--) { s->failed_pc=0x0c080d98u; return 0; }
r[15]+=0x00000004u;
goto P_0c080d9a;
P_0c080d9a: /* original 2f22, guest PC 0x0c080d9a */
if(!s->budget--) { s->failed_pc=0x0c080d9au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c080d9c;
P_0c080d9c: /* original 9322, guest PC 0x0c080d9c */
if(!s->budget--) { s->failed_pc=0x0c080d9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de4u,2);
goto P_0c080d9e;
P_0c080d9e: /* original 1f33, guest PC 0x0c080d9e */
if(!s->budget--) { s->failed_pc=0x0c080d9eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c080da0;
P_0c080da0: /* original 01fc, guest PC 0x0c080da0 */
if(!s->budget--) { s->failed_pc=0x0c080da0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c080da2;
P_0c080da2: /* original 3183, guest PC 0x0c080da2 */
if(!s->budget--) { s->failed_pc=0x0c080da2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[8])!=0);
goto P_0c080da4;
P_0c080da4: /* original 8f02, guest PC 0x0c080da4 */
if(!s->budget--) { s->failed_pc=0x0c080da4u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000004u;
if(!cond) { goto P_0c080dac; }
goto P_0c080da8;
P_0c080da6: /* original 7904, guest PC 0x0c080da6 */
if(!s->budget--) { s->failed_pc=0x0c080da6u; return 0; }
r[9]+=0x00000004u;
goto P_0c080da8;
P_0c080da8: /* original 911d, guest PC 0x0c080da8 */
if(!s->budget--) { s->failed_pc=0x0c080da8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de6u,2);
goto P_0c080daa;
P_0c080daa: /* original 1f13, guest PC 0x0c080daa */
if(!s->budget--) { s->failed_pc=0x0c080daau; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c080dac;
P_0c080dac: /* original 2fe6, guest PC 0x0c080dac */
if(!s->budget--) { s->failed_pc=0x0c080dacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080dae;
P_0c080dae: /* original e700, guest PC 0x0c080dae */
if(!s->budget--) { s->failed_pc=0x0c080daeu; return 0; }
r[7]=0x00000000u;
goto P_0c080db0;
P_0c080db0: /* original 55f4, guest PC 0x0c080db0 */
if(!s->budget--) { s->failed_pc=0x0c080db0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c080db2;
P_0c080db2: /* original d313, guest PC 0x0c080db2 */
if(!s->budget--) { s->failed_pc=0x0c080db2u; return 0; }
r[3]=read(ram,0x0c080e00u,4);
goto P_0c080db4;
P_0c080db4: /* original 56f3, guest PC 0x0c080db4 */
if(!s->budget--) { s->failed_pc=0x0c080db4u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080db6;
P_0c080db6: /* original 430b, guest PC 0x0c080db6 */
if(!s->budget--) { s->failed_pc=0x0c080db6u; return 0; }
target=r[3];
r[16]=0x0c080dbau;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080dbau) { target=s->pc; goto dispatch; }
goto P_0c080dba;
P_0c080db8: /* original 54f1, guest PC 0x0c080db8 */
if(!s->budget--) { s->failed_pc=0x0c080db8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080dba;
P_0c080dba: /* original 7f04, guest PC 0x0c080dba */
if(!s->budget--) { s->failed_pc=0x0c080dbau; return 0; }
r[15]+=0x00000004u;
goto P_0c080dbc;
P_0c080dbc: /* original 52f1, guest PC 0x0c080dbc */
if(!s->budget--) { s->failed_pc=0x0c080dbcu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c080dbe;
P_0c080dbe: /* original 7201, guest PC 0x0c080dbe */
if(!s->budget--) { s->failed_pc=0x0c080dbeu; return 0; }
r[2]+=0x00000001u;
goto P_0c080dc0;
P_0c080dc0: /* original 1f21, guest PC 0x0c080dc0 */
if(!s->budget--) { s->failed_pc=0x0c080dc0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c080dc2;
P_0c080dc2: /* original 53f4, guest PC 0x0c080dc2 */
if(!s->budget--) { s->failed_pc=0x0c080dc2u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c080dc4;
P_0c080dc4: /* original 3233, guest PC 0x0c080dc4 */
if(!s->budget--) { s->failed_pc=0x0c080dc4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c080dc6;
P_0c080dc6: /* original 8fcb, guest PC 0x0c080dc6 */
if(!s->budget--) { s->failed_pc=0x0c080dc6u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(!cond) { goto P_0c080d60; }
goto P_0c080dca;
P_0c080dc8: /* original 7801, guest PC 0x0c080dc8 */
if(!s->budget--) { s->failed_pc=0x0c080dc8u; return 0; }
r[8]+=0x00000001u;
goto P_0c080dca;
P_0c080dca: /* original 7f1c, guest PC 0x0c080dca */
if(!s->budget--) { s->failed_pc=0x0c080dcau; return 0; }
r[15]+=0x0000001cu;
goto P_0c080dcc;
P_0c080dcc: /* original 4f26, guest PC 0x0c080dcc */
if(!s->budget--) { s->failed_pc=0x0c080dccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080dce;
P_0c080dce: /* original 68f6, guest PC 0x0c080dce */
if(!s->budget--) { s->failed_pc=0x0c080dceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c080dd0;
P_0c080dd0: /* original 69f6, guest PC 0x0c080dd0 */
if(!s->budget--) { s->failed_pc=0x0c080dd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080dd2;
P_0c080dd2: /* original 6af6, guest PC 0x0c080dd2 */
if(!s->budget--) { s->failed_pc=0x0c080dd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080dd4;
P_0c080dd4: /* original 6bf6, guest PC 0x0c080dd4 */
if(!s->budget--) { s->failed_pc=0x0c080dd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080dd6;
P_0c080dd6: /* original 6cf6, guest PC 0x0c080dd6 */
if(!s->budget--) { s->failed_pc=0x0c080dd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080dd8;
P_0c080dd8: /* original 6df6, guest PC 0x0c080dd8 */
if(!s->budget--) { s->failed_pc=0x0c080dd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080dda;
P_0c080dda: /* original 000b, guest PC 0x0c080dda */
if(!s->budget--) { s->failed_pc=0x0c080ddau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080ddc: /* original 6ef6, guest PC 0x0c080ddc */
if(!s->budget--) { s->failed_pc=0x0c080ddcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c080ddeu,s,ram);
P_0c089c9c: /* original 4f22, guest PC 0x0c089c9c */
if(!s->budget--) { s->failed_pc=0x0c089c9cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089c9e;
P_0c089c9e: /* original 7ff8, guest PC 0x0c089c9e */
if(!s->budget--) { s->failed_pc=0x0c089c9eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c089ca0;
P_0c089ca0: /* original 5cf9, guest PC 0x0c089ca0 */
if(!s->budget--) { s->failed_pc=0x0c089ca0u; return 0; }
r[12]=read(ram,r[15]+36,4);
goto P_0c089ca2;
P_0c089ca2: /* original 0d35, guest PC 0x0c089ca2 */
if(!s->budget--) { s->failed_pc=0x0c089ca2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c089ca4;
P_0c089ca4: /* original e031, guest PC 0x0c089ca4 */
if(!s->budget--) { s->failed_pc=0x0c089ca4u; return 0; }
r[0]=0x00000031u;
goto P_0c089ca6;
P_0c089ca6: /* original 0edc, guest PC 0x0c089ca6 */
if(!s->budget--) { s->failed_pc=0x0c089ca6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c089ca8;
P_0c089ca8: /* original 2ee8, guest PC 0x0c089ca8 */
if(!s->budget--) { s->failed_pc=0x0c089ca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c089caa;
P_0c089caa: /* original 8f05, guest PC 0x0c089caa */
if(!s->budget--) { s->failed_pc=0x0c089caau; return 0; }
cond=r[17]&1u;
r[11]=r[7];
if(!cond) { goto P_0c089cb8; }
goto P_0c089cae;
P_0c089cac: /* original 6b73, guest PC 0x0c089cac */
if(!s->budget--) { s->failed_pc=0x0c089cacu; return 0; }
r[11]=r[7];
goto P_0c089cae;
P_0c089cae: /* original d221, guest PC 0x0c089cae */
if(!s->budget--) { s->failed_pc=0x0c089caeu; return 0; }
r[2]=read(ram,0x0c089d34u,4);
goto P_0c089cb0;
P_0c089cb0: /* original 420b, guest PC 0x0c089cb0 */
if(!s->budget--) { s->failed_pc=0x0c089cb0u; return 0; }
target=r[2];
r[16]=0x0c089cb4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089cb4u) { target=s->pc; goto dispatch; }
goto P_0c089cb4;
P_0c089cb2: /* original 0009, guest PC 0x0c089cb2 */
if(!s->budget--) { s->failed_pc=0x0c089cb2u; return 0; }
goto P_0c089cb4;
P_0c089cb4: /* original ee07, guest PC 0x0c089cb4 */
if(!s->budget--) { s->failed_pc=0x0c089cb4u; return 0; }
r[14]=0x00000007u;
goto P_0c089cb6;
P_0c089cb6: /* original 2e09, guest PC 0x0c089cb6 */
if(!s->budget--) { s->failed_pc=0x0c089cb6u; return 0; }
r[14]&=r[0];
goto P_0c089cb8;
P_0c089cb8: /* original e030, guest PC 0x0c089cb8 */
if(!s->budget--) { s->failed_pc=0x0c089cb8u; return 0; }
r[0]=0x00000030u;
goto P_0c089cba;
P_0c089cba: /* original 0de4, guest PC 0x0c089cba */
if(!s->budget--) { s->failed_pc=0x0c089cbau; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c089cbc;
P_0c089cbc: /* original e038, guest PC 0x0c089cbc */
if(!s->budget--) { s->failed_pc=0x0c089cbcu; return 0; }
r[0]=0x00000038u;
goto P_0c089cbe;
P_0c089cbe: /* original 03dd, guest PC 0x0c089cbe */
if(!s->budget--) { s->failed_pc=0x0c089cbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089cc0;
P_0c089cc0: /* original c71d, guest PC 0x0c089cc0 */
if(!s->budget--) { s->failed_pc=0x0c089cc0u; return 0; }
r[0]=0x0c089d38u;
goto P_0c089cc2;
P_0c089cc2: /* original 2c32, guest PC 0x0c089cc2 */
if(!s->budget--) { s->failed_pc=0x0c089cc2u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089cc4;
P_0c089cc4: /* original e301, guest PC 0x0c089cc4 */
if(!s->budget--) { s->failed_pc=0x0c089cc4u; return 0; }
r[3]=0x00000001u;
goto P_0c089cc6;
P_0c089cc6: /* original f48d, guest PC 0x0c089cc6 */
if(!s->budget--) { s->failed_pc=0x0c089cc6u; return 0; }
fr[4]=0;
goto P_0c089cc8;
P_0c089cc8: /* original 23e8, guest PC 0x0c089cc8 */
if(!s->budget--) { s->failed_pc=0x0c089cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c089cca;
P_0c089cca: /* original fb4a, guest PC 0x0c089cca */
if(!s->budget--) { s->failed_pc=0x0c089ccau; return 0; }
vf3_matrix_store(s,ram,4,r[11]);
goto P_0c089ccc;
P_0c089ccc: /* original f308, guest PC 0x0c089ccc */
if(!s->budget--) { s->failed_pc=0x0c089cccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cce;
P_0c089cce: /* original fa3a, guest PC 0x0c089cce */
if(!s->budget--) { s->failed_pc=0x0c089cceu; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cd0;
P_0c089cd0: /* original f3b8, guest PC 0x0c089cd0 */
if(!s->budget--) { s->failed_pc=0x0c089cd0u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c089cd2;
P_0c089cd2: /* original 8d19, guest PC 0x0c089cd2 */
if(!s->budget--) { s->failed_pc=0x0c089cd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[9]);
if(cond) { goto P_0c089d08; }
goto P_0c089cd6;
P_0c089cd4: /* original f93a, guest PC 0x0c089cd4 */
if(!s->budget--) { s->failed_pc=0x0c089cd4u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cd6;
P_0c089cd6: /* original 60e3, guest PC 0x0c089cd6 */
if(!s->budget--) { s->failed_pc=0x0c089cd6u; return 0; }
r[0]=r[14];
goto P_0c089cd8;
P_0c089cd8: /* original 8803, guest PC 0x0c089cd8 */
if(!s->budget--) { s->failed_pc=0x0c089cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c089cda;
P_0c089cda: /* original 891b, guest PC 0x0c089cda */
if(!s->budget--) { s->failed_pc=0x0c089cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c089d14; }
goto P_0c089cdc;
P_0c089cdc: /* original e028, guest PC 0x0c089cdc */
if(!s->budget--) { s->failed_pc=0x0c089cdcu; return 0; }
r[0]=0x00000028u;
goto P_0c089cde;
P_0c089cde: /* original 6693, guest PC 0x0c089cde */
if(!s->budget--) { s->failed_pc=0x0c089cdeu; return 0; }
r[6]=r[9];
goto P_0c089ce0;
P_0c089ce0: /* original 02dd, guest PC 0x0c089ce0 */
if(!s->budget--) { s->failed_pc=0x0c089ce0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c089ce2;
P_0c089ce2: /* original c716, guest PC 0x0c089ce2 */
if(!s->budget--) { s->failed_pc=0x0c089ce2u; return 0; }
r[0]=0x0c089d3cu;
goto P_0c089ce4;
P_0c089ce4: /* original e300, guest PC 0x0c089ce4 */
if(!s->budget--) { s->failed_pc=0x0c089ce4u; return 0; }
r[3]=0x00000000u;
goto P_0c089ce6;
P_0c089ce6: /* original 65f3, guest PC 0x0c089ce6 */
if(!s->budget--) { s->failed_pc=0x0c089ce6u; return 0; }
r[5]=r[15];
goto P_0c089ce8;
P_0c089ce8: /* original 2c22, guest PC 0x0c089ce8 */
if(!s->budget--) { s->failed_pc=0x0c089ce8u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c089cea;
P_0c089cea: /* original 1f31, guest PC 0x0c089cea */
if(!s->budget--) { s->failed_pc=0x0c089ceau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c089cec;
P_0c089cec: /* original f308, guest PC 0x0c089cec */
if(!s->budget--) { s->failed_pc=0x0c089cecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cee;
P_0c089cee: /* original c714, guest PC 0x0c089cee */
if(!s->budget--) { s->failed_pc=0x0c089ceeu; return 0; }
r[0]=0x0c089d40u;
goto P_0c089cf0;
P_0c089cf0: /* original f93a, guest PC 0x0c089cf0 */
if(!s->budget--) { s->failed_pc=0x0c089cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c089cf2;
P_0c089cf2: /* original ff4a, guest PC 0x0c089cf2 */
if(!s->budget--) { s->failed_pc=0x0c089cf2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c089cf4;
P_0c089cf4: /* original f308, guest PC 0x0c089cf4 */
if(!s->budget--) { s->failed_pc=0x0c089cf4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089cf6;
P_0c089cf6: /* original fa3a, guest PC 0x0c089cf6 */
if(!s->budget--) { s->failed_pc=0x0c089cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089cf8;
P_0c089cf8: /* original d312, guest PC 0x0c089cf8 */
if(!s->budget--) { s->failed_pc=0x0c089cf8u; return 0; }
r[3]=read(ram,0x0c089d44u,4);
goto P_0c089cfa;
P_0c089cfa: /* original 430b, guest PC 0x0c089cfa */
if(!s->budget--) { s->failed_pc=0x0c089cfau; return 0; }
target=r[3];
r[16]=0x0c089cfeu;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c089cfeu) { target=s->pc; goto dispatch; }
goto P_0c089cfe;
P_0c089cfc: /* original 64c2, guest PC 0x0c089cfc */
if(!s->budget--) { s->failed_pc=0x0c089cfcu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c089cfe;
P_0c089cfe: /* original f3f8, guest PC 0x0c089cfe */
if(!s->budget--) { s->failed_pc=0x0c089cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089d00;
P_0c089d00: /* original fb3a, guest PC 0x0c089d00 */
if(!s->budget--) { s->failed_pc=0x0c089d00u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c089d02;
P_0c089d02: /* original 53f1, guest PC 0x0c089d02 */
if(!s->budget--) { s->failed_pc=0x0c089d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c089d04;
P_0c089d04: /* original a006, guest PC 0x0c089d04 */
if(!s->budget--) { s->failed_pc=0x0c089d04u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d14;
P_0c089d06: /* original 2c32, guest PC 0x0c089d06 */
if(!s->budget--) { s->failed_pc=0x0c089d06u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c089d08;
P_0c089d08: /* original 60e3, guest PC 0x0c089d08 */
if(!s->budget--) { s->failed_pc=0x0c089d08u; return 0; }
r[0]=r[14];
goto P_0c089d0a;
P_0c089d0a: /* original 8802, guest PC 0x0c089d0a */
if(!s->budget--) { s->failed_pc=0x0c089d0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c089d0c;
P_0c089d0c: /* original 8b02, guest PC 0x0c089d0c */
if(!s->budget--) { s->failed_pc=0x0c089d0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089d14; }
goto P_0c089d0e;
P_0c089d0e: /* original c70e, guest PC 0x0c089d0e */
if(!s->budget--) { s->failed_pc=0x0c089d0eu; return 0; }
r[0]=0x0c089d48u;
goto P_0c089d10;
P_0c089d10: /* original f308, guest PC 0x0c089d10 */
if(!s->budget--) { s->failed_pc=0x0c089d10u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089d12;
P_0c089d12: /* original fa3a, guest PC 0x0c089d12 */
if(!s->budget--) { s->failed_pc=0x0c089d12u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c089d14;
P_0c089d14: /* original 7f08, guest PC 0x0c089d14 */
if(!s->budget--) { s->failed_pc=0x0c089d14u; return 0; }
r[15]+=0x00000008u;
goto P_0c089d16;
P_0c089d16: /* original 60e3, guest PC 0x0c089d16 */
if(!s->budget--) { s->failed_pc=0x0c089d16u; return 0; }
r[0]=r[14];
goto P_0c089d18;
P_0c089d18: /* original 4f26, guest PC 0x0c089d18 */
if(!s->budget--) { s->failed_pc=0x0c089d18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089d1a;
P_0c089d1a: /* original 69f6, guest PC 0x0c089d1a */
if(!s->budget--) { s->failed_pc=0x0c089d1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089d1c;
P_0c089d1c: /* original 6af6, guest PC 0x0c089d1c */
if(!s->budget--) { s->failed_pc=0x0c089d1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089d1e;
P_0c089d1e: /* original 6bf6, guest PC 0x0c089d1e */
if(!s->budget--) { s->failed_pc=0x0c089d1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089d20;
P_0c089d20: /* original 6cf6, guest PC 0x0c089d20 */
if(!s->budget--) { s->failed_pc=0x0c089d20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089d22;
P_0c089d22: /* original 6df6, guest PC 0x0c089d22 */
if(!s->budget--) { s->failed_pc=0x0c089d22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089d24;
P_0c089d24: /* original 000b, guest PC 0x0c089d24 */
if(!s->budget--) { s->failed_pc=0x0c089d24u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089d26: /* original 6ef6, guest PC 0x0c089d26 */
if(!s->budget--) { s->failed_pc=0x0c089d26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089d28u,s,ram);
P_0c0aca18: /* original 902b, guest PC 0x0c0aca18 */
if(!s->budget--) { s->failed_pc=0x0c0aca18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca72u,2);
goto P_0c0aca1a;
P_0c0aca1a: /* original f38d, guest PC 0x0c0aca1a */
if(!s->budget--) { s->failed_pc=0x0c0aca1au; return 0; }
fr[3]=0;
goto P_0c0aca1c;
P_0c0aca1c: /* original f437, guest PC 0x0c0aca1c */
if(!s->budget--) { s->failed_pc=0x0c0aca1cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca1e;
P_0c0aca1e: /* original 70fc, guest PC 0x0c0aca1e */
if(!s->budget--) { s->failed_pc=0x0c0aca1eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aca20;
P_0c0aca20: /* original f437, guest PC 0x0c0aca20 */
if(!s->budget--) { s->failed_pc=0x0c0aca20u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca22;
P_0c0aca22: /* original 70fc, guest PC 0x0c0aca22 */
if(!s->budget--) { s->failed_pc=0x0c0aca22u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aca24;
P_0c0aca24: /* original f437, guest PC 0x0c0aca24 */
if(!s->budget--) { s->failed_pc=0x0c0aca24u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca26;
P_0c0aca26: /* original e02c, guest PC 0x0c0aca26 */
if(!s->budget--) { s->failed_pc=0x0c0aca26u; return 0; }
r[0]=0x0000002cu;
goto P_0c0aca28;
P_0c0aca28: /* original f437, guest PC 0x0c0aca28 */
if(!s->budget--) { s->failed_pc=0x0c0aca28u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca2a;
P_0c0aca2a: /* original e028, guest PC 0x0c0aca2a */
if(!s->budget--) { s->failed_pc=0x0c0aca2au; return 0; }
r[0]=0x00000028u;
goto P_0c0aca2c;
P_0c0aca2c: /* original f437, guest PC 0x0c0aca2c */
if(!s->budget--) { s->failed_pc=0x0c0aca2cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca2e;
P_0c0aca2e: /* original e024, guest PC 0x0c0aca2e */
if(!s->budget--) { s->failed_pc=0x0c0aca2eu; return 0; }
r[0]=0x00000024u;
goto P_0c0aca30;
P_0c0aca30: /* original f437, guest PC 0x0c0aca30 */
if(!s->budget--) { s->failed_pc=0x0c0aca30u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca32;
P_0c0aca32: /* original e062, guest PC 0x0c0aca32 */
if(!s->budget--) { s->failed_pc=0x0c0aca32u; return 0; }
r[0]=0x00000062u;
goto P_0c0aca34;
P_0c0aca34: /* original 5361, guest PC 0x0c0aca34 */
if(!s->budget--) { s->failed_pc=0x0c0aca34u; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c0aca36;
P_0c0aca36: /* original 7301, guest PC 0x0c0aca36 */
if(!s->budget--) { s->failed_pc=0x0c0aca36u; return 0; }
r[3]+=0x00000001u;
goto P_0c0aca38;
P_0c0aca38: /* original 6233, guest PC 0x0c0aca38 */
if(!s->budget--) { s->failed_pc=0x0c0aca38u; return 0; }
r[2]=r[3];
goto P_0c0aca3a;
P_0c0aca3a: /* original 1631, guest PC 0x0c0aca3a */
if(!s->budget--) { s->failed_pc=0x0c0aca3au; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c0aca3c;
P_0c0aca3c: /* original 0424, guest PC 0x0c0aca3c */
if(!s->budget--) { s->failed_pc=0x0c0aca3cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0aca3e;
P_0c0aca3e: /* original e04c, guest PC 0x0c0aca3e */
if(!s->budget--) { s->failed_pc=0x0c0aca3eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0aca40;
P_0c0aca40: /* original 014e, guest PC 0x0c0aca40 */
if(!s->budget--) { s->failed_pc=0x0c0aca40u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0aca42;
P_0c0aca42: /* original 9317, guest PC 0x0c0aca42 */
if(!s->budget--) { s->failed_pc=0x0c0aca42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca74u,2);
goto P_0c0aca44;
P_0c0aca44: /* original 2138, guest PC 0x0c0aca44 */
if(!s->budget--) { s->failed_pc=0x0c0aca44u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aca46;
P_0c0aca46: /* original 890e, guest PC 0x0c0aca46 */
if(!s->budget--) { s->failed_pc=0x0c0aca46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aca66; }
goto P_0c0aca48;
P_0c0aca48: /* original e06a, guest PC 0x0c0aca48 */
if(!s->budget--) { s->failed_pc=0x0c0aca48u; return 0; }
r[0]=0x0000006au;
goto P_0c0aca4a;
P_0c0aca4a: /* original d211, guest PC 0x0c0aca4a */
if(!s->budget--) { s->failed_pc=0x0c0aca4au; return 0; }
r[2]=read(ram,0x0c0aca90u,4);
goto P_0c0aca4c;
P_0c0aca4c: /* original 065d, guest PC 0x0c0aca4c */
if(!s->budget--) { s->failed_pc=0x0c0aca4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aca4e;
P_0c0aca4e: /* original 9013, guest PC 0x0c0aca4e */
if(!s->budget--) { s->failed_pc=0x0c0aca4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca78u,2);
goto P_0c0aca50;
P_0c0aca50: /* original 6363, guest PC 0x0c0aca50 */
if(!s->budget--) { s->failed_pc=0x0c0aca50u; return 0; }
r[3]=r[6];
goto P_0c0aca52;
P_0c0aca52: /* original 9710, guest PC 0x0c0aca52 */
if(!s->budget--) { s->failed_pc=0x0c0aca52u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca76u,2);
goto P_0c0aca54;
P_0c0aca54: /* original 055d, guest PC 0x0c0aca54 */
if(!s->budget--) { s->failed_pc=0x0c0aca54u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aca56;
P_0c0aca56: /* original 3358, guest PC 0x0c0aca56 */
if(!s->budget--) { s->failed_pc=0x0c0aca56u; return 0; }
r[3]-=r[5];
goto P_0c0aca58;
P_0c0aca58: /* original 6533, guest PC 0x0c0aca58 */
if(!s->budget--) { s->failed_pc=0x0c0aca58u; return 0; }
r[5]=r[3];
goto P_0c0aca5a;
P_0c0aca5a: /* original 2528, guest PC 0x0c0aca5a */
if(!s->budget--) { s->failed_pc=0x0c0aca5au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0aca5c;
P_0c0aca5c: /* original 8b00, guest PC 0x0c0aca5c */
if(!s->budget--) { s->failed_pc=0x0c0aca5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aca60; }
goto P_0c0aca5e;
P_0c0aca5e: /* original 970c, guest PC 0x0c0aca5e */
if(!s->budget--) { s->failed_pc=0x0c0aca5eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7au,2);
goto P_0c0aca60;
P_0c0aca60: /* original 367c, guest PC 0x0c0aca60 */
if(!s->budget--) { s->failed_pc=0x0c0aca60u; return 0; }
r[6]+=r[7];
goto P_0c0aca62;
P_0c0aca62: /* original 6063, guest PC 0x0c0aca62 */
if(!s->budget--) { s->failed_pc=0x0c0aca62u; return 0; }
r[0]=r[6];
goto P_0c0aca64;
P_0c0aca64: /* original 814f, guest PC 0x0c0aca64 */
if(!s->budget--) { s->failed_pc=0x0c0aca64u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0aca66;
P_0c0aca66: /* original 900a, guest PC 0x0c0aca66 */
if(!s->budget--) { s->failed_pc=0x0c0aca66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7eu,2);
goto P_0c0aca68;
P_0c0aca68: /* original 9308, guest PC 0x0c0aca68 */
if(!s->budget--) { s->failed_pc=0x0c0aca68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7cu,2);
goto P_0c0aca6a;
P_0c0aca6a: /* original 000b, guest PC 0x0c0aca6a */
if(!s->budget--) { s->failed_pc=0x0c0aca6au; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],4);
s->pc=target; return ram->oob==0;
P_0c0aca6c: /* original 0436, guest PC 0x0c0aca6c */
if(!s->budget--) { s->failed_pc=0x0c0aca6cu; return 0; }
write(ram,r[4]+r[0],r[3],4);
return vf3_matrix_family(0x0c0aca6eu,s,ram);
P_0c0acf68: /* original 4f22, guest PC 0x0c0acf68 */
if(!s->budget--) { s->failed_pc=0x0c0acf68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0acf6a;
P_0c0acf6a: /* original 7738, guest PC 0x0c0acf6a */
if(!s->budget--) { s->failed_pc=0x0c0acf6au; return 0; }
r[7]+=0x00000038u;
goto P_0c0acf6c;
P_0c0acf6c: /* original 8473, guest PC 0x0c0acf6c */
if(!s->budget--) { s->failed_pc=0x0c0acf6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0acf6e;
P_0c0acf6e: /* original 4f12, guest PC 0x0c0acf6e */
if(!s->budget--) { s->failed_pc=0x0c0acf6eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0acf70;
P_0c0acf70: /* original 600c, guest PC 0x0c0acf70 */
if(!s->budget--) { s->failed_pc=0x0c0acf70u; return 0; }
r[0]=r[0]&255u;
goto P_0c0acf72;
P_0c0acf72: /* original 880d, guest PC 0x0c0acf72 */
if(!s->budget--) { s->failed_pc=0x0c0acf72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0acf74;
P_0c0acf74: /* original 8d21, guest PC 0x0c0acf74 */
if(!s->budget--) { s->failed_pc=0x0c0acf74u; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(cond) { goto P_0c0acfba; }
goto P_0c0acf78;
P_0c0acf76: /* original 6703, guest PC 0x0c0acf76 */
if(!s->budget--) { s->failed_pc=0x0c0acf76u; return 0; }
r[7]=r[0];
goto P_0c0acf78;
P_0c0acf78: /* original e03e, guest PC 0x0c0acf78 */
if(!s->budget--) { s->failed_pc=0x0c0acf78u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acf7a;
P_0c0acf7a: /* original 075d, guest PC 0x0c0acf7a */
if(!s->budget--) { s->failed_pc=0x0c0acf7au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0acf7c;
P_0c0acf7c: /* original 8454, guest PC 0x0c0acf7c */
if(!s->budget--) { s->failed_pc=0x0c0acf7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c0acf7e;
P_0c0acf7e: /* original 677d, guest PC 0x0c0acf7e */
if(!s->budget--) { s->failed_pc=0x0c0acf7eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c0acf80;
P_0c0acf80: /* original 600c, guest PC 0x0c0acf80 */
if(!s->budget--) { s->failed_pc=0x0c0acf80u; return 0; }
r[0]=r[0]&255u;
goto P_0c0acf82;
P_0c0acf82: /* original 370c, guest PC 0x0c0acf82 */
if(!s->budget--) { s->failed_pc=0x0c0acf82u; return 0; }
r[7]+=r[0];
goto P_0c0acf84;
P_0c0acf84: /* original 903a, guest PC 0x0c0acf84 */
if(!s->budget--) { s->failed_pc=0x0c0acf84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acffcu,2);
goto P_0c0acf86;
P_0c0acf86: /* original 024d, guest PC 0x0c0acf86 */
if(!s->budget--) { s->failed_pc=0x0c0acf86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0acf88;
P_0c0acf88: /* original e044, guest PC 0x0c0acf88 */
if(!s->budget--) { s->failed_pc=0x0c0acf88u; return 0; }
r[0]=0x00000044u;
goto P_0c0acf8a;
P_0c0acf8a: /* original 014d, guest PC 0x0c0acf8a */
if(!s->budget--) { s->failed_pc=0x0c0acf8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0acf8c;
P_0c0acf8c: /* original 3278, guest PC 0x0c0acf8c */
if(!s->budget--) { s->failed_pc=0x0c0acf8cu; return 0; }
r[2]-=r[7];
goto P_0c0acf8e;
P_0c0acf8e: /* original 7101, guest PC 0x0c0acf8e */
if(!s->budget--) { s->failed_pc=0x0c0acf8eu; return 0; }
r[1]+=0x00000001u;
goto P_0c0acf90;
P_0c0acf90: /* original 6723, guest PC 0x0c0acf90 */
if(!s->budget--) { s->failed_pc=0x0c0acf90u; return 0; }
r[7]=r[2];
goto P_0c0acf92;
P_0c0acf92: /* original 371c, guest PC 0x0c0acf92 */
if(!s->budget--) { s->failed_pc=0x0c0acf92u; return 0; }
r[7]+=r[1];
goto P_0c0acf94;
P_0c0acf94: /* original 4715, guest PC 0x0c0acf94 */
if(!s->budget--) { s->failed_pc=0x0c0acf94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0acf96;
P_0c0acf96: /* original 8900, guest PC 0x0c0acf96 */
if(!s->budget--) { s->failed_pc=0x0c0acf96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acf9a; }
goto P_0c0acf98;
P_0c0acf98: /* original e701, guest PC 0x0c0acf98 */
if(!s->budget--) { s->failed_pc=0x0c0acf98u; return 0; }
r[7]=0x00000001u;
goto P_0c0acf9a;
P_0c0acf9a: /* original 9030, guest PC 0x0c0acf9a */
if(!s->budget--) { s->failed_pc=0x0c0acf9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acffeu,2);
goto P_0c0acf9c;
P_0c0acf9c: /* original d31d, guest PC 0x0c0acf9c */
if(!s->budget--) { s->failed_pc=0x0c0acf9cu; return 0; }
r[3]=read(ram,0x0c0ad014u,4);
goto P_0c0acf9e;
P_0c0acf9e: /* original 024d, guest PC 0x0c0acf9e */
if(!s->budget--) { s->failed_pc=0x0c0acf9eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0acfa0;
P_0c0acfa0: /* original 6073, guest PC 0x0c0acfa0 */
if(!s->budget--) { s->failed_pc=0x0c0acfa0u; return 0; }
r[0]=r[7];
goto P_0c0acfa2;
P_0c0acfa2: /* original 6e23, guest PC 0x0c0acfa2 */
if(!s->budget--) { s->failed_pc=0x0c0acfa2u; return 0; }
r[14]=r[2];
goto P_0c0acfa4;
P_0c0acfa4: /* original 7eff, guest PC 0x0c0acfa4 */
if(!s->budget--) { s->failed_pc=0x0c0acfa4u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0acfa6;
P_0c0acfa6: /* original 0e17, guest PC 0x0c0acfa6 */
if(!s->budget--) { s->failed_pc=0x0c0acfa6u; return 0; }
r[19]=r[14]*r[1];
goto P_0c0acfa8;
P_0c0acfa8: /* original 0e1a, guest PC 0x0c0acfa8 */
if(!s->budget--) { s->failed_pc=0x0c0acfa8u; return 0; }
r[14]=r[19];
goto P_0c0acfaa;
P_0c0acfaa: /* original 430b, guest PC 0x0c0acfaa */
if(!s->budget--) { s->failed_pc=0x0c0acfaau; return 0; }
target=r[3];
r[16]=0x0c0acfaeu;
r[1]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acfaeu) { target=s->pc; goto dispatch; }
goto P_0c0acfae;
P_0c0acfac: /* original 61e3, guest PC 0x0c0acfac */
if(!s->budget--) { s->failed_pc=0x0c0acfacu; return 0; }
r[1]=r[14];
goto P_0c0acfae;
P_0c0acfae: /* original 6e03, guest PC 0x0c0acfae */
if(!s->budget--) { s->failed_pc=0x0c0acfaeu; return 0; }
r[14]=r[0];
goto P_0c0acfb0;
P_0c0acfb0: /* original 7e01, guest PC 0x0c0acfb0 */
if(!s->budget--) { s->failed_pc=0x0c0acfb0u; return 0; }
r[14]+=0x00000001u;
goto P_0c0acfb2;
P_0c0acfb2: /* original 3e23, guest PC 0x0c0acfb2 */
if(!s->budget--) { s->failed_pc=0x0c0acfb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0acfb4;
P_0c0acfb4: /* original e03e, guest PC 0x0c0acfb4 */
if(!s->budget--) { s->failed_pc=0x0c0acfb4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acfb6;
P_0c0acfb6: /* original 8f1c, guest PC 0x0c0acfb6 */
if(!s->budget--) { s->failed_pc=0x0c0acfb6u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[14],2);
if(!cond) { goto P_0c0acff2; }
goto P_0c0acfba;
P_0c0acfb8: /* original 04e5, guest PC 0x0c0acfb8 */
if(!s->budget--) { s->failed_pc=0x0c0acfb8u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c0acfba;
P_0c0acfba: /* original 9020, guest PC 0x0c0acfba */
if(!s->budget--) { s->failed_pc=0x0c0acfbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acffeu,2);
goto P_0c0acfbc;
P_0c0acfbc: /* original 024d, guest PC 0x0c0acfbc */
if(!s->budget--) { s->failed_pc=0x0c0acfbcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0acfbe;
P_0c0acfbe: /* original e03e, guest PC 0x0c0acfbe */
if(!s->budget--) { s->failed_pc=0x0c0acfbeu; return 0; }
r[0]=0x0000003eu;
goto P_0c0acfc0;
P_0c0acfc0: /* original 0425, guest PC 0x0c0acfc0 */
if(!s->budget--) { s->failed_pc=0x0c0acfc0u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0acfc2;
P_0c0acfc2: /* original e048, guest PC 0x0c0acfc2 */
if(!s->budget--) { s->failed_pc=0x0c0acfc2u; return 0; }
r[0]=0x00000048u;
goto P_0c0acfc4;
P_0c0acfc4: /* original 024e, guest PC 0x0c0acfc4 */
if(!s->budget--) { s->failed_pc=0x0c0acfc4u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0acfc6;
P_0c0acfc6: /* original 931b, guest PC 0x0c0acfc6 */
if(!s->budget--) { s->failed_pc=0x0c0acfc6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad000u,2);
goto P_0c0acfc8;
P_0c0acfc8: /* original 223b, guest PC 0x0c0acfc8 */
if(!s->budget--) { s->failed_pc=0x0c0acfc8u; return 0; }
r[2]|=r[3];
goto P_0c0acfca;
P_0c0acfca: /* original 0426, guest PC 0x0c0acfca */
if(!s->budget--) { s->failed_pc=0x0c0acfcau; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c0acfcc;
P_0c0acfcc: /* original e200, guest PC 0x0c0acfcc */
if(!s->budget--) { s->failed_pc=0x0c0acfccu; return 0; }
r[2]=0x00000000u;
goto P_0c0acfce;
P_0c0acfce: /* original e062, guest PC 0x0c0acfce */
if(!s->budget--) { s->failed_pc=0x0c0acfceu; return 0; }
r[0]=0x00000062u;
goto P_0c0acfd0;
P_0c0acfd0: /* original d111, guest PC 0x0c0acfd0 */
if(!s->budget--) { s->failed_pc=0x0c0acfd0u; return 0; }
r[1]=read(ram,0x0c0ad018u,4);
goto P_0c0acfd2;
P_0c0acfd2: /* original 141e, guest PC 0x0c0acfd2 */
if(!s->budget--) { s->failed_pc=0x0c0acfd2u; return 0; }
write(ram,r[4]+56,r[1],4);
goto P_0c0acfd4;
P_0c0acfd4: /* original 0424, guest PC 0x0c0acfd4 */
if(!s->budget--) { s->failed_pc=0x0c0acfd4u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0acfd6;
P_0c0acfd6: /* original 9014, guest PC 0x0c0acfd6 */
if(!s->budget--) { s->failed_pc=0x0c0acfd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad002u,2);
goto P_0c0acfd8;
P_0c0acfd8: /* original 074c, guest PC 0x0c0acfd8 */
if(!s->budget--) { s->failed_pc=0x0c0acfd8u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0acfda;
P_0c0acfda: /* original 677c, guest PC 0x0c0acfda */
if(!s->budget--) { s->failed_pc=0x0c0acfdau; return 0; }
r[7]=r[7]&255u;
goto P_0c0acfdc;
P_0c0acfdc: /* original 2778, guest PC 0x0c0acfdc */
if(!s->budget--) { s->failed_pc=0x0c0acfdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0acfde;
P_0c0acfde: /* original 8903, guest PC 0x0c0acfde */
if(!s->budget--) { s->failed_pc=0x0c0acfdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acfe8; }
goto P_0c0acfe0;
P_0c0acfe0: /* original 0e5c, guest PC 0x0c0acfe0 */
if(!s->budget--) { s->failed_pc=0x0c0acfe0u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0acfe2;
P_0c0acfe2: /* original 6eec, guest PC 0x0c0acfe2 */
if(!s->budget--) { s->failed_pc=0x0c0acfe2u; return 0; }
r[14]=r[14]&255u;
goto P_0c0acfe4;
P_0c0acfe4: /* original 4e21, guest PC 0x0c0acfe4 */
if(!s->budget--) { s->failed_pc=0x0c0acfe4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]=(uint32_t)((int32_t)r[14]>>1);
goto P_0c0acfe6;
P_0c0acfe6: /* original 37ec, guest PC 0x0c0acfe6 */
if(!s->budget--) { s->failed_pc=0x0c0acfe6u; return 0; }
r[7]+=r[14];
goto P_0c0acfe8;
P_0c0acfe8: /* original 4f16, guest PC 0x0c0acfe8 */
if(!s->budget--) { s->failed_pc=0x0c0acfe8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0acfea;
P_0c0acfea: /* original 0574, guest PC 0x0c0acfea */
if(!s->budget--) { s->failed_pc=0x0c0acfeau; return 0; }
write(ram,r[5]+r[0],r[7],1);
goto P_0c0acfec;
P_0c0acfec: /* original 4f26, guest PC 0x0c0acfec */
if(!s->budget--) { s->failed_pc=0x0c0acfecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0acfee;
P_0c0acfee: /* original ad13, guest PC 0x0c0acfee */
if(!s->budget--) { s->failed_pc=0x0c0acfeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aca18;
P_0c0acff0: /* original 6ef6, guest PC 0x0c0acff0 */
if(!s->budget--) { s->failed_pc=0x0c0acff0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0acff2;
P_0c0acff2: /* original 4f16, guest PC 0x0c0acff2 */
if(!s->budget--) { s->failed_pc=0x0c0acff2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0acff4;
P_0c0acff4: /* original 4f26, guest PC 0x0c0acff4 */
if(!s->budget--) { s->failed_pc=0x0c0acff4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0acff6;
P_0c0acff6: /* original 000b, guest PC 0x0c0acff6 */
if(!s->budget--) { s->failed_pc=0x0c0acff6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0acff8: /* original 6ef6, guest PC 0x0c0acff8 */
if(!s->budget--) { s->failed_pc=0x0c0acff8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0acffau,s,ram);
P_0c0c4d2c: /* original 4f22, guest PC 0x0c0c4d2c */
if(!s->budget--) { s->failed_pc=0x0c0c4d2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4d2e;
P_0c0c4d2e: /* original 6053, guest PC 0x0c0c4d2e */
if(!s->budget--) { s->failed_pc=0x0c0c4d2eu; return 0; }
r[0]=r[5];
goto P_0c0c4d30;
P_0c0c4d30: /* original 4001, guest PC 0x0c0c4d30 */
if(!s->budget--) { s->failed_pc=0x0c0c4d30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c4d32;
P_0c0c4d32: /* original 4000, guest PC 0x0c0c4d32 */
if(!s->budget--) { s->failed_pc=0x0c0c4d32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4d34;
P_0c0c4d34: /* original 006d, guest PC 0x0c0c4d34 */
if(!s->budget--) { s->failed_pc=0x0c0c4d34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c4d36;
P_0c0c4d36: /* original 88ff, guest PC 0x0c0c4d36 */
if(!s->budget--) { s->failed_pc=0x0c0c4d36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4d38;
P_0c0c4d38: /* original 8d05, guest PC 0x0c0c4d38 */
if(!s->budget--) { s->failed_pc=0x0c0c4d38u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c0c4d46; }
goto P_0c0c4d3c;
P_0c0c4d3a: /* original 6d03, guest PC 0x0c0c4d3a */
if(!s->budget--) { s->failed_pc=0x0c0c4d3au; return 0; }
r[13]=r[0];
goto P_0c0c4d3c;
P_0c0c4d3c: /* original e052, guest PC 0x0c0c4d3c */
if(!s->budget--) { s->failed_pc=0x0c0c4d3cu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4d3e;
P_0c0c4d3e: /* original 7502, guest PC 0x0c0c4d3e */
if(!s->budget--) { s->failed_pc=0x0c0c4d3eu; return 0; }
r[5]+=0x00000002u;
goto P_0c0c4d40;
P_0c0c4d40: /* original 0454, guest PC 0x0c0c4d40 */
if(!s->budget--) { s->failed_pc=0x0c0c4d40u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4d42;
P_0c0c4d42: /* original a02c, guest PC 0x0c0c4d42 */
if(!s->budget--) { s->failed_pc=0x0c0c4d42u; return 0; }
r[4]=r[13];
goto P_0c0c4d9e;
P_0c0c4d44: /* original 64d3, guest PC 0x0c0c4d44 */
if(!s->budget--) { s->failed_pc=0x0c0c4d44u; return 0; }
r[4]=r[13];
goto P_0c0c4d46;
P_0c0c4d46: /* original e050, guest PC 0x0c0c4d46 */
if(!s->budget--) { s->failed_pc=0x0c0c4d46u; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d48;
P_0c0c4d48: /* original 064c, guest PC 0x0c0c4d48 */
if(!s->budget--) { s->failed_pc=0x0c0c4d48u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d4a;
P_0c0c4d4a: /* original 636c, guest PC 0x0c0c4d4a */
if(!s->budget--) { s->failed_pc=0x0c0c4d4au; return 0; }
r[3]=r[6]&255u;
goto P_0c0c4d4c;
P_0c0c4d4c: /* original 2338, guest PC 0x0c0c4d4c */
if(!s->budget--) { s->failed_pc=0x0c0c4d4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4d4e;
P_0c0c4d4e: /* original 8b1a, guest PC 0x0c0c4d4e */
if(!s->budget--) { s->failed_pc=0x0c0c4d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d50;
P_0c0c4d50: /* original e060, guest PC 0x0c0c4d50 */
if(!s->budget--) { s->failed_pc=0x0c0c4d50u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d52;
P_0c0c4d52: /* original 05ec, guest PC 0x0c0c4d52 */
if(!s->budget--) { s->failed_pc=0x0c0c4d52u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d54;
P_0c0c4d54: /* original 605c, guest PC 0x0c0c4d54 */
if(!s->budget--) { s->failed_pc=0x0c0c4d54u; return 0; }
r[0]=r[5]&255u;
goto P_0c0c4d56;
P_0c0c4d56: /* original 8803, guest PC 0x0c0c4d56 */
if(!s->budget--) { s->failed_pc=0x0c0c4d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c4d58;
P_0c0c4d58: /* original 8d16, guest PC 0x0c0c4d58 */
if(!s->budget--) { s->failed_pc=0x0c0c4d58u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d5c;
P_0c0c4d5a: /* original 6503, guest PC 0x0c0c4d5a */
if(!s->budget--) { s->failed_pc=0x0c0c4d5au; return 0; }
r[5]=r[0];
goto P_0c0c4d5c;
P_0c0c4d5c: /* original 6053, guest PC 0x0c0c4d5c */
if(!s->budget--) { s->failed_pc=0x0c0c4d5cu; return 0; }
r[0]=r[5];
goto P_0c0c4d5e;
P_0c0c4d5e: /* original 8810, guest PC 0x0c0c4d5e */
if(!s->budget--) { s->failed_pc=0x0c0c4d5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0c4d60;
P_0c0c4d60: /* original 8912, guest PC 0x0c0c4d60 */
if(!s->budget--) { s->failed_pc=0x0c0c4d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d62;
P_0c0c4d62: /* original 6053, guest PC 0x0c0c4d62 */
if(!s->budget--) { s->failed_pc=0x0c0c4d62u; return 0; }
r[0]=r[5];
goto P_0c0c4d64;
P_0c0c4d64: /* original 8807, guest PC 0x0c0c4d64 */
if(!s->budget--) { s->failed_pc=0x0c0c4d64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c4d66;
P_0c0c4d66: /* original 890f, guest PC 0x0c0c4d66 */
if(!s->budget--) { s->failed_pc=0x0c0c4d66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d68;
P_0c0c4d68: /* original 6053, guest PC 0x0c0c4d68 */
if(!s->budget--) { s->failed_pc=0x0c0c4d68u; return 0; }
r[0]=r[5];
goto P_0c0c4d6a;
P_0c0c4d6a: /* original 8814, guest PC 0x0c0c4d6a */
if(!s->budget--) { s->failed_pc=0x0c0c4d6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0c4d6c;
P_0c0c4d6c: /* original 890c, guest PC 0x0c0c4d6c */
if(!s->budget--) { s->failed_pc=0x0c0c4d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d6e;
P_0c0c4d6e: /* original e057, guest PC 0x0c0c4d6e */
if(!s->budget--) { s->failed_pc=0x0c0c4d6eu; return 0; }
r[0]=0x00000057u;
goto P_0c0c4d70;
P_0c0c4d70: /* original 024c, guest PC 0x0c0c4d70 */
if(!s->budget--) { s->failed_pc=0x0c0c4d70u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d72;
P_0c0c4d72: /* original 2228, guest PC 0x0c0c4d72 */
if(!s->budget--) { s->failed_pc=0x0c0c4d72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4d74;
P_0c0c4d74: /* original 8f07, guest PC 0x0c0c4d74 */
if(!s->budget--) { s->failed_pc=0x0c0c4d74u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d78;
P_0c0c4d76: /* original e601, guest PC 0x0c0c4d76 */
if(!s->budget--) { s->failed_pc=0x0c0c4d76u; return 0; }
r[6]=0x00000001u;
goto P_0c0c4d78;
P_0c0c4d78: /* original 904e, guest PC 0x0c0c4d78 */
if(!s->budget--) { s->failed_pc=0x0c0c4d78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e18u,2);
goto P_0c0c4d7a;
P_0c0c4d7a: /* original 655b, guest PC 0x0c0c4d7a */
if(!s->budget--) { s->failed_pc=0x0c0c4d7au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4d7c;
P_0c0c4d7c: /* original d329, guest PC 0x0c0c4d7c */
if(!s->budget--) { s->failed_pc=0x0c0c4d7cu; return 0; }
r[3]=read(ram,0x0c0c4e24u,4);
goto P_0c0c4d7e;
P_0c0c4d7e: /* original 0d7e, guest PC 0x0c0c4d7e */
if(!s->budget--) { s->failed_pc=0x0c0c4d7eu; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c0c4d80;
P_0c0c4d80: /* original 435d, guest PC 0x0c0c4d80 */
if(!s->budget--) { s->failed_pc=0x0c0c4d80u; return 0; }
r[3]=(r[5]&0x80000000u)?((r[5]&31u)?r[3]>>((-r[5])&31u):0):r[3]<<(r[5]&31u);
goto P_0c0c4d82;
P_0c0c4d82: /* original 2d3b, guest PC 0x0c0c4d82 */
if(!s->budget--) { s->failed_pc=0x0c0c4d82u; return 0; }
r[13]|=r[3];
goto P_0c0c4d84;
P_0c0c4d84: /* original 07d6, guest PC 0x0c0c4d84 */
if(!s->budget--) { s->failed_pc=0x0c0c4d84u; return 0; }
write(ram,r[7]+r[0],r[13],4);
goto P_0c0c4d86;
P_0c0c4d86: /* original 76ff, guest PC 0x0c0c4d86 */
if(!s->budget--) { s->failed_pc=0x0c0c4d86u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0c4d88;
P_0c0c4d88: /* original 9047, guest PC 0x0c0c4d88 */
if(!s->budget--) { s->failed_pc=0x0c0c4d88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e1au,2);
goto P_0c0c4d8a;
P_0c0c4d8a: /* original e303, guest PC 0x0c0c4d8a */
if(!s->budget--) { s->failed_pc=0x0c0c4d8au; return 0; }
r[3]=0x00000003u;
goto P_0c0c4d8c;
P_0c0c4d8c: /* original 0e34, guest PC 0x0c0c4d8c */
if(!s->budget--) { s->failed_pc=0x0c0c4d8cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4d8e;
P_0c0c4d8e: /* original e050, guest PC 0x0c0c4d8e */
if(!s->budget--) { s->failed_pc=0x0c0c4d8eu; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d90;
P_0c0c4d90: /* original 0464, guest PC 0x0c0c4d90 */
if(!s->budget--) { s->failed_pc=0x0c0c4d90u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c4d92;
P_0c0c4d92: /* original e060, guest PC 0x0c0c4d92 */
if(!s->budget--) { s->failed_pc=0x0c0c4d92u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d94;
P_0c0c4d94: /* original 04ec, guest PC 0x0c0c4d94 */
if(!s->budget--) { s->failed_pc=0x0c0c4d94u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d96;
P_0c0c4d96: /* original d024, guest PC 0x0c0c4d96 */
if(!s->budget--) { s->failed_pc=0x0c0c4d96u; return 0; }
r[0]=read(ram,0x0c0c4e28u,4);
goto P_0c0c4d98;
P_0c0c4d98: /* original 644c, guest PC 0x0c0c4d98 */
if(!s->budget--) { s->failed_pc=0x0c0c4d98u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c4d9a;
P_0c0c4d9a: /* original 4400, guest PC 0x0c0c4d9a */
if(!s->budget--) { s->failed_pc=0x0c0c4d9au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c4d9c;
P_0c0c4d9c: /* original 044d, guest PC 0x0c0c4d9c */
if(!s->budget--) { s->failed_pc=0x0c0c4d9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4d9e;
P_0c0c4d9e: /* original d323, guest PC 0x0c0c4d9e */
if(!s->budget--) { s->failed_pc=0x0c0c4d9eu; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4da0;
P_0c0c4da0: /* original 430b, guest PC 0x0c0c4da0 */
if(!s->budget--) { s->failed_pc=0x0c0c4da0u; return 0; }
target=r[3];
r[16]=0x0c0c4da4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4da4u) { target=s->pc; goto dispatch; }
goto P_0c0c4da4;
P_0c0c4da2: /* original 0009, guest PC 0x0c0c4da2 */
if(!s->budget--) { s->failed_pc=0x0c0c4da2u; return 0; }
goto P_0c0c4da4;
P_0c0c4da4: /* original 4f26, guest PC 0x0c0c4da4 */
if(!s->budget--) { s->failed_pc=0x0c0c4da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4da6;
P_0c0c4da6: /* original 6df6, guest PC 0x0c0c4da6 */
if(!s->budget--) { s->failed_pc=0x0c0c4da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4da8;
P_0c0c4da8: /* original 000b, guest PC 0x0c0c4da8 */
if(!s->budget--) { s->failed_pc=0x0c0c4da8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4daa: /* original 6ef6, guest PC 0x0c0c4daa */
if(!s->budget--) { s->failed_pc=0x0c0c4daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c4dacu,s,ram);
P_0c0c4e4a: /* original 4f22, guest PC 0x0c0c4e4a */
if(!s->budget--) { s->failed_pc=0x0c0c4e4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4e4c;
P_0c0c4e4c: /* original 7ff8, guest PC 0x0c0c4e4c */
if(!s->budget--) { s->failed_pc=0x0c0c4e4cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c4e4e;
P_0c0c4e4e: /* original 2f42, guest PC 0x0c0c4e4e */
if(!s->budget--) { s->failed_pc=0x0c0c4e4eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c4e50;
P_0c0c4e50: /* original 9078, guest PC 0x0c0c4e50 */
if(!s->budget--) { s->failed_pc=0x0c0c4e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f44u,2);
goto P_0c0c4e52;
P_0c0c4e52: /* original 9876, guest PC 0x0c0c4e52 */
if(!s->budget--) { s->failed_pc=0x0c0c4e52u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f42u,2);
goto P_0c0c4e54;
P_0c0c4e54: /* original 81f2, guest PC 0x0c0c4e54 */
if(!s->budget--) { s->failed_pc=0x0c0c4e54u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4e56;
P_0c0c4e56: /* original c740, guest PC 0x0c0c4e56 */
if(!s->budget--) { s->failed_pc=0x0c0c4e56u; return 0; }
r[0]=0x0c0c4f58u;
goto P_0c0c4e58;
P_0c0c4e58: /* original fe08, guest PC 0x0c0c4e58 */
if(!s->budget--) { s->failed_pc=0x0c0c4e58u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c4e5a;
P_0c0c4e5a: /* original c740, guest PC 0x0c0c4e5a */
if(!s->budget--) { s->failed_pc=0x0c0c4e5au; return 0; }
r[0]=0x0c0c4f5cu;
goto P_0c0c4e5c;
P_0c0c4e5c: /* original 69f2, guest PC 0x0c0c4e5c */
if(!s->budget--) { s->failed_pc=0x0c0c4e5cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0c4e5e;
P_0c0c4e5e: /* original 9b72, guest PC 0x0c0c4e5e */
if(!s->budget--) { s->failed_pc=0x0c0c4e5eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f46u,2);
goto P_0c0c4e60;
P_0c0c4e60: /* original dc3f, guest PC 0x0c0c4e60 */
if(!s->budget--) { s->failed_pc=0x0c0c4e60u; return 0; }
r[12]=read(ram,0x0c0c4f60u,4);
goto P_0c0c4e62;
P_0c0c4e62: /* original 7904, guest PC 0x0c0c4e62 */
if(!s->budget--) { s->failed_pc=0x0c0c4e62u; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e64;
P_0c0c4e64: /* original ff08, guest PC 0x0c0c4e64 */
if(!s->budget--) { s->failed_pc=0x0c0c4e64u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c4e66;
P_0c0c4e66: /* original 85f2, guest PC 0x0c0c4e66 */
if(!s->budget--) { s->failed_pc=0x0c0c4e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c4e68;
P_0c0c4e68: /* original 3d8c, guest PC 0x0c0c4e68 */
if(!s->budget--) { s->failed_pc=0x0c0c4e68u; return 0; }
r[13]+=r[8];
goto P_0c0c4e6a;
P_0c0c4e6a: /* original 3e0c, guest PC 0x0c0c4e6a */
if(!s->budget--) { s->failed_pc=0x0c0c4e6au; return 0; }
r[14]+=r[0];
goto P_0c0c4e6c;
P_0c0c4e6c: /* original 4c0b, guest PC 0x0c0c4e6c */
if(!s->budget--) { s->failed_pc=0x0c0c4e6cu; return 0; }
target=r[12];
r[16]=0x0c0c4e70u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4e70u) { target=s->pc; goto dispatch; }
goto P_0c0c4e70;
P_0c0c4e6e: /* original 64ef, guest PC 0x0c0c4e6e */
if(!s->budget--) { s->failed_pc=0x0c0c4e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c4e70;
P_0c0c4e70: /* original f4fc, guest PC 0x0c0c4e70 */
if(!s->budget--) { s->failed_pc=0x0c0c4e70u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c4e72;
P_0c0c4e72: /* original 6add, guest PC 0x0c0c4e72 */
if(!s->budget--) { s->failed_pc=0x0c0c4e72u; return 0; }
r[10]=r[13]&65535u;
goto P_0c0c4e74;
P_0c0c4e74: /* original f30c, guest PC 0x0c0c4e74 */
if(!s->budget--) { s->failed_pc=0x0c0c4e74u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e76;
P_0c0c4e76: /* original f432, guest PC 0x0c0c4e76 */
if(!s->budget--) { s->failed_pc=0x0c0c4e76u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e78;
P_0c0c4e78: /* original f43d, guest PC 0x0c0c4e78 */
if(!s->budget--) { s->failed_pc=0x0c0c4e78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c4e7a;
P_0c0c4e7a: /* original 045a, guest PC 0x0c0c4e7a */
if(!s->budget--) { s->failed_pc=0x0c0c4e7au; return 0; }
r[4]=r[53];
goto P_0c0c4e7c;
P_0c0c4e7c: /* original 3a4c, guest PC 0x0c0c4e7c */
if(!s->budget--) { s->failed_pc=0x0c0c4e7cu; return 0; }
r[10]+=r[4];
goto P_0c0c4e7e;
P_0c0c4e7e: /* original 4c0b, guest PC 0x0c0c4e7e */
if(!s->budget--) { s->failed_pc=0x0c0c4e7eu; return 0; }
target=r[12];
r[16]=0x0c0c4e82u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4e82u) { target=s->pc; goto dispatch; }
goto P_0c0c4e82;
P_0c0c4e80: /* original 64af, guest PC 0x0c0c4e80 */
if(!s->budget--) { s->failed_pc=0x0c0c4e80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c4e82;
P_0c0c4e82: /* original f4ec, guest PC 0x0c0c4e82 */
if(!s->budget--) { s->failed_pc=0x0c0c4e82u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4e84;
P_0c0c4e84: /* original 4b10, guest PC 0x0c0c4e84 */
if(!s->budget--) { s->failed_pc=0x0c0c4e84u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0c4e86;
P_0c0c4e86: /* original f30c, guest PC 0x0c0c4e86 */
if(!s->budget--) { s->failed_pc=0x0c0c4e86u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e88;
P_0c0c4e88: /* original f432, guest PC 0x0c0c4e88 */
if(!s->budget--) { s->failed_pc=0x0c0c4e88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e8a;
P_0c0c4e8a: /* original 7904, guest PC 0x0c0c4e8a */
if(!s->budget--) { s->failed_pc=0x0c0c4e8au; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e8c;
P_0c0c4e8c: /* original 8feb, guest PC 0x0c0c4e8c */
if(!s->budget--) { s->failed_pc=0x0c0c4e8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[9]);
if(!cond) { goto P_0c0c4e66; }
goto P_0c0c4e90;
P_0c0c4e8e: /* original f94a, guest PC 0x0c0c4e8e */
if(!s->budget--) { s->failed_pc=0x0c0c4e8eu; return 0; }
vf3_matrix_store(s,ram,4,r[9]);
goto P_0c0c4e90;
P_0c0c4e90: /* original 62f2, guest PC 0x0c0c4e90 */
if(!s->budget--) { s->failed_pc=0x0c0c4e90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c4e92;
P_0c0c4e92: /* original 7f08, guest PC 0x0c0c4e92 */
if(!s->budget--) { s->failed_pc=0x0c0c4e92u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c4e94;
P_0c0c4e94: /* original 4f26, guest PC 0x0c0c4e94 */
if(!s->budget--) { s->failed_pc=0x0c0c4e94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e96;
P_0c0c4e96: /* original 9057, guest PC 0x0c0c4e96 */
if(!s->budget--) { s->failed_pc=0x0c0c4e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f48u,2);
goto P_0c0c4e98;
P_0c0c4e98: /* original e300, guest PC 0x0c0c4e98 */
if(!s->budget--) { s->failed_pc=0x0c0c4e98u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4e9a;
P_0c0c4e9a: /* original 0236, guest PC 0x0c0c4e9a */
if(!s->budget--) { s->failed_pc=0x0c0c4e9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c4e9c;
P_0c0c4e9c: /* original fef9, guest PC 0x0c0c4e9c */
if(!s->budget--) { s->failed_pc=0x0c0c4e9cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4e9e;
P_0c0c4e9e: /* original fff9, guest PC 0x0c0c4e9e */
if(!s->budget--) { s->failed_pc=0x0c0c4e9eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4ea0;
P_0c0c4ea0: /* original 68f6, guest PC 0x0c0c4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4ea2;
P_0c0c4ea2: /* original 69f6, guest PC 0x0c0c4ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4ea4;
P_0c0c4ea4: /* original 6af6, guest PC 0x0c0c4ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4ea6;
P_0c0c4ea6: /* original 6bf6, guest PC 0x0c0c4ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4ea8;
P_0c0c4ea8: /* original 6cf6, guest PC 0x0c0c4ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4eaa;
P_0c0c4eaa: /* original 6df6, guest PC 0x0c0c4eaa */
if(!s->budget--) { s->failed_pc=0x0c0c4eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4eac;
P_0c0c4eac: /* original 000b, guest PC 0x0c0c4eac */
if(!s->budget--) { s->failed_pc=0x0c0c4eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4eae: /* original 6ef6, guest PC 0x0c0c4eae */
if(!s->budget--) { s->failed_pc=0x0c0c4eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c4eb0u,s,ram);
P_0c0c6104: /* original 4f22, guest PC 0x0c0c6104 */
if(!s->budget--) { s->failed_pc=0x0c0c6104u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6106;
P_0c0c6106: /* original 8b2f, guest PC 0x0c0c6106 */
if(!s->budget--) { s->failed_pc=0x0c0c6106u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6168; }
goto P_0c0c6108;
P_0c0c6108: /* original 9237, guest PC 0x0c0c6108 */
if(!s->budget--) { s->failed_pc=0x0c0c6108u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c617au,2);
goto P_0c0c610a;
P_0c0c610a: /* original 3423, guest PC 0x0c0c610a */
if(!s->budget--) { s->failed_pc=0x0c0c610au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c610c;
P_0c0c610c: /* original 892c, guest PC 0x0c0c610c */
if(!s->budget--) { s->failed_pc=0x0c0c610cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6168; }
goto P_0c0c610e;
P_0c0c610e: /* original d01c, guest PC 0x0c0c610e */
if(!s->budget--) { s->failed_pc=0x0c0c610eu; return 0; }
r[0]=read(ram,0x0c0c6180u,4);
goto P_0c0c6110;
P_0c0c6110: /* original 6143, guest PC 0x0c0c6110 */
if(!s->budget--) { s->failed_pc=0x0c0c6110u; return 0; }
r[1]=r[4];
goto P_0c0c6112;
P_0c0c6112: /* original 4108, guest PC 0x0c0c6112 */
if(!s->budget--) { s->failed_pc=0x0c0c6112u; return 0; }
r[1]<<=2;
goto P_0c0c6114;
P_0c0c6114: /* original 031e, guest PC 0x0c0c6114 */
if(!s->budget--) { s->failed_pc=0x0c0c6114u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0c6116;
P_0c0c6116: /* original 4311, guest PC 0x0c0c6116 */
if(!s->budget--) { s->failed_pc=0x0c0c6116u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c6118;
P_0c0c6118: /* original 8b26, guest PC 0x0c0c6118 */
if(!s->budget--) { s->failed_pc=0x0c0c6118u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6168; }
goto P_0c0c611a;
P_0c0c611a: /* original da1b, guest PC 0x0c0c611a */
if(!s->budget--) { s->failed_pc=0x0c0c611au; return 0; }
r[10]=read(ram,0x0c0c6188u,4);
goto P_0c0c611c;
P_0c0c611c: /* original e500, guest PC 0x0c0c611c */
if(!s->budget--) { s->failed_pc=0x0c0c611cu; return 0; }
r[5]=0x00000000u;
goto P_0c0c611e;
P_0c0c611e: /* original d91d, guest PC 0x0c0c611e */
if(!s->budget--) { s->failed_pc=0x0c0c611eu; return 0; }
r[9]=read(ram,0x0c0c6194u,4);
goto P_0c0c6120;
P_0c0c6120: /* original d81b, guest PC 0x0c0c6120 */
if(!s->budget--) { s->failed_pc=0x0c0c6120u; return 0; }
r[8]=read(ram,0x0c0c6190u,4);
goto P_0c0c6122;
P_0c0c6122: /* original 2a4b, guest PC 0x0c0c6122 */
if(!s->budget--) { s->failed_pc=0x0c0c6122u; return 0; }
r[10]|=r[4];
goto P_0c0c6124;
P_0c0c6124: /* original db1c, guest PC 0x0c0c6124 */
if(!s->budget--) { s->failed_pc=0x0c0c6124u; return 0; }
r[11]=read(ram,0x0c0c6198u,4);
goto P_0c0c6126;
P_0c0c6126: /* original 9d29, guest PC 0x0c0c6126 */
if(!s->budget--) { s->failed_pc=0x0c0c6126u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c617cu,2);
goto P_0c0c6128;
P_0c0c6128: /* original dc16, guest PC 0x0c0c6128 */
if(!s->budget--) { s->failed_pc=0x0c0c6128u; return 0; }
r[12]=read(ram,0x0c0c6184u,4);
goto P_0c0c612a;
P_0c0c612a: /* original d618, guest PC 0x0c0c612a */
if(!s->budget--) { s->failed_pc=0x0c0c612au; return 0; }
r[6]=read(ram,0x0c0c618cu,4);
goto P_0c0c612c;
P_0c0c612c: /* original 6e53, guest PC 0x0c0c612c */
if(!s->budget--) { s->failed_pc=0x0c0c612cu; return 0; }
r[14]=r[5];
goto P_0c0c612e;
P_0c0c612e: /* original 4e08, guest PC 0x0c0c612e */
if(!s->budget--) { s->failed_pc=0x0c0c612eu; return 0; }
r[14]<<=2;
goto P_0c0c6130;
P_0c0c6130: /* original 4e00, guest PC 0x0c0c6130 */
if(!s->budget--) { s->failed_pc=0x0c0c6130u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c6132;
P_0c0c6132: /* original 3e6c, guest PC 0x0c0c6132 */
if(!s->budget--) { s->failed_pc=0x0c0c6132u; return 0; }
r[14]+=r[6];
goto P_0c0c6134;
P_0c0c6134: /* original 53e1, guest PC 0x0c0c6134 */
if(!s->budget--) { s->failed_pc=0x0c0c6134u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c6136;
P_0c0c6136: /* original 2338, guest PC 0x0c0c6136 */
if(!s->budget--) { s->failed_pc=0x0c0c6136u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c6138;
P_0c0c6138: /* original 8916, guest PC 0x0c0c6138 */
if(!s->budget--) { s->failed_pc=0x0c0c6138u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6168; }
goto P_0c0c613a;
P_0c0c613a: /* original 52e1, guest PC 0x0c0c613a */
if(!s->budget--) { s->failed_pc=0x0c0c613au; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c613c;
P_0c0c613c: /* original 3420, guest PC 0x0c0c613c */
if(!s->budget--) { s->failed_pc=0x0c0c613cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c613e;
P_0c0c613e: /* original 8b11, guest PC 0x0c0c613e */
if(!s->budget--) { s->failed_pc=0x0c0c613eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6164; }
goto P_0c0c6140;
P_0c0c6140: /* original 63c2, guest PC 0x0c0c6140 */
if(!s->budget--) { s->failed_pc=0x0c0c6140u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6142;
P_0c0c6142: /* original 61e2, guest PC 0x0c0c6142 */
if(!s->budget--) { s->failed_pc=0x0c0c6142u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c6144;
P_0c0c6144: /* original 3310, guest PC 0x0c0c6144 */
if(!s->budget--) { s->failed_pc=0x0c0c6144u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c6146;
P_0c0c6146: /* original 890f, guest PC 0x0c0c6146 */
if(!s->budget--) { s->failed_pc=0x0c0c6146u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6168; }
goto P_0c0c6148;
P_0c0c6148: /* original 2fd6, guest PC 0x0c0c6148 */
if(!s->budget--) { s->failed_pc=0x0c0c6148u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c614a;
P_0c0c614a: /* original 2f86, guest PC 0x0c0c614a */
if(!s->budget--) { s->failed_pc=0x0c0c614au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c614c;
P_0c0c614c: /* original 2fa6, guest PC 0x0c0c614c */
if(!s->budget--) { s->failed_pc=0x0c0c614cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c614e;
P_0c0c614e: /* original d315, guest PC 0x0c0c614e */
if(!s->budget--) { s->failed_pc=0x0c0c614eu; return 0; }
r[3]=read(ram,0x0c0c61a4u,4);
goto P_0c0c6150;
P_0c0c6150: /* original d613, guest PC 0x0c0c6150 */
if(!s->budget--) { s->failed_pc=0x0c0c6150u; return 0; }
r[6]=read(ram,0x0c0c61a0u,4);
goto P_0c0c6152;
P_0c0c6152: /* original 6532, guest PC 0x0c0c6152 */
if(!s->budget--) { s->failed_pc=0x0c0c6152u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c6154;
P_0c0c6154: /* original d711, guest PC 0x0c0c6154 */
if(!s->budget--) { s->failed_pc=0x0c0c6154u; return 0; }
r[7]=read(ram,0x0c0c619cu,4);
goto P_0c0c6156;
P_0c0c6156: /* original 35bc, guest PC 0x0c0c6156 */
if(!s->budget--) { s->failed_pc=0x0c0c6156u; return 0; }
r[5]+=r[11];
goto P_0c0c6158;
P_0c0c6158: /* original 490b, guest PC 0x0c0c6158 */
if(!s->budget--) { s->failed_pc=0x0c0c6158u; return 0; }
target=r[9];
r[16]=0x0c0c615cu;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c615cu) { target=s->pc; goto dispatch; }
goto P_0c0c615c;
P_0c0c615a: /* original 64e2, guest PC 0x0c0c615a */
if(!s->budget--) { s->failed_pc=0x0c0c615au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c615c;
P_0c0c615c: /* original 62e2, guest PC 0x0c0c615c */
if(!s->budget--) { s->failed_pc=0x0c0c615cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c615e;
P_0c0c615e: /* original 7f0c, guest PC 0x0c0c615e */
if(!s->budget--) { s->failed_pc=0x0c0c615eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c6160;
P_0c0c6160: /* original a002, guest PC 0x0c0c6160 */
if(!s->budget--) { s->failed_pc=0x0c0c6160u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0c6168;
P_0c0c6162: /* original 2c22, guest PC 0x0c0c6162 */
if(!s->budget--) { s->failed_pc=0x0c0c6162u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0c6164;
P_0c0c6164: /* original afe2, guest PC 0x0c0c6164 */
if(!s->budget--) { s->failed_pc=0x0c0c6164u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c612c;
P_0c0c6166: /* original 7501, guest PC 0x0c0c6166 */
if(!s->budget--) { s->failed_pc=0x0c0c6166u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c6168;
P_0c0c6168: /* original 4f26, guest PC 0x0c0c6168 */
if(!s->budget--) { s->failed_pc=0x0c0c6168u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c616a;
P_0c0c616a: /* original 68f6, guest PC 0x0c0c616a */
if(!s->budget--) { s->failed_pc=0x0c0c616au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c616c;
P_0c0c616c: /* original 69f6, guest PC 0x0c0c616c */
if(!s->budget--) { s->failed_pc=0x0c0c616cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c616e;
P_0c0c616e: /* original 6af6, guest PC 0x0c0c616e */
if(!s->budget--) { s->failed_pc=0x0c0c616eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c6170;
P_0c0c6170: /* original 6bf6, guest PC 0x0c0c6170 */
if(!s->budget--) { s->failed_pc=0x0c0c6170u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c6172;
P_0c0c6172: /* original 6cf6, guest PC 0x0c0c6172 */
if(!s->budget--) { s->failed_pc=0x0c0c6172u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6174;
P_0c0c6174: /* original 6df6, guest PC 0x0c0c6174 */
if(!s->budget--) { s->failed_pc=0x0c0c6174u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6176;
P_0c0c6176: /* original 000b, guest PC 0x0c0c6176 */
if(!s->budget--) { s->failed_pc=0x0c0c6176u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6178: /* original 6ef6, guest PC 0x0c0c6178 */
if(!s->budget--) { s->failed_pc=0x0c0c6178u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c617au,s,ram);
P_0c0c8274: /* original 4f22, guest PC 0x0c0c8274 */
if(!s->budget--) { s->failed_pc=0x0c0c8274u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8276;
P_0c0c8276: /* original d340, guest PC 0x0c0c8276 */
if(!s->budget--) { s->failed_pc=0x0c0c8276u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8278;
P_0c0c8278: /* original 67b3, guest PC 0x0c0c8278 */
if(!s->budget--) { s->failed_pc=0x0c0c8278u; return 0; }
r[7]=r[11];
goto P_0c0c827a;
P_0c0c827a: /* original de3e, guest PC 0x0c0c827a */
if(!s->budget--) { s->failed_pc=0x0c0c827au; return 0; }
r[14]=read(ram,0x0c0c8374u,4);
goto P_0c0c827c;
P_0c0c827c: /* original 7ff4, guest PC 0x0c0c827c */
if(!s->budget--) { s->failed_pc=0x0c0c827cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c827e;
P_0c0c827e: /* original 1f32, guest PC 0x0c0c827e */
if(!s->budget--) { s->failed_pc=0x0c0c827eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c8280;
P_0c0c8280: /* original 66e3, guest PC 0x0c0c8280 */
if(!s->budget--) { s->failed_pc=0x0c0c8280u; return 0; }
r[6]=r[14];
goto P_0c0c8282;
P_0c0c8282: /* original d53e, guest PC 0x0c0c8282 */
if(!s->budget--) { s->failed_pc=0x0c0c8282u; return 0; }
r[5]=read(ram,0x0c0c837cu,4);
goto P_0c0c8284;
P_0c0c8284: /* original 7658, guest PC 0x0c0c8284 */
if(!s->budget--) { s->failed_pc=0x0c0c8284u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c8286;
P_0c0c8286: /* original 5454, guest PC 0x0c0c8286 */
if(!s->budget--) { s->failed_pc=0x0c0c8286u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c8288;
P_0c0c8288: /* original 034c, guest PC 0x0c0c8288 */
if(!s->budget--) { s->failed_pc=0x0c0c8288u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c828a;
P_0c0c828a: /* original e061, guest PC 0x0c0c828a */
if(!s->budget--) { s->failed_pc=0x0c0c828au; return 0; }
r[0]=0x00000061u;
goto P_0c0c828c;
P_0c0c828c: /* original 633c, guest PC 0x0c0c828c */
if(!s->budget--) { s->failed_pc=0x0c0c828cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c828e;
P_0c0c828e: /* original 2f32, guest PC 0x0c0c828e */
if(!s->budget--) { s->failed_pc=0x0c0c828eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8290;
P_0c0c8290: /* original 5455, guest PC 0x0c0c8290 */
if(!s->budget--) { s->failed_pc=0x0c0c8290u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c8292;
P_0c0c8292: /* original 034c, guest PC 0x0c0c8292 */
if(!s->budget--) { s->failed_pc=0x0c0c8292u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8294;
P_0c0c8294: /* original 633c, guest PC 0x0c0c8294 */
if(!s->budget--) { s->failed_pc=0x0c0c8294u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c8296;
P_0c0c8296: /* original 1f31, guest PC 0x0c0c8296 */
if(!s->budget--) { s->failed_pc=0x0c0c8296u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c8298;
P_0c0c8298: /* original dc39, guest PC 0x0c0c8298 */
if(!s->budget--) { s->failed_pc=0x0c0c8298u; return 0; }
r[12]=read(ram,0x0c0c8380u,4);
goto P_0c0c829a;
P_0c0c829a: /* original 2fb6, guest PC 0x0c0c829a */
if(!s->budget--) { s->failed_pc=0x0c0c829au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c829c;
P_0c0c829c: /* original 9360, guest PC 0x0c0c829c */
if(!s->budget--) { s->failed_pc=0x0c0c829cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c829e;
P_0c0c829e: /* original 55f1, guest PC 0x0c0c829e */
if(!s->budget--) { s->failed_pc=0x0c0c829eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c82a0;
P_0c0c82a0: /* original 945f, guest PC 0x0c0c82a0 */
if(!s->budget--) { s->failed_pc=0x0c0c82a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8362u,2);
goto P_0c0c82a2;
P_0c0c82a2: /* original 4c0b, guest PC 0x0c0c82a2 */
if(!s->budget--) { s->failed_pc=0x0c0c82a2u; return 0; }
target=r[12];
r[16]=0x0c0c82a6u;
r[5]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c82a6u) { target=s->pc; goto dispatch; }
goto P_0c0c82a6;
P_0c0c82a4: /* original 353c, guest PC 0x0c0c82a4 */
if(!s->budget--) { s->failed_pc=0x0c0c82a4u; return 0; }
r[5]+=r[3];
goto P_0c0c82a6;
P_0c0c82a6: /* original 2fb6, guest PC 0x0c0c82a6 */
if(!s->budget--) { s->failed_pc=0x0c0c82a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82a8;
P_0c0c82a8: /* original 66e3, guest PC 0x0c0c82a8 */
if(!s->budget--) { s->failed_pc=0x0c0c82a8u; return 0; }
r[6]=r[14];
goto P_0c0c82aa;
P_0c0c82aa: /* original 55f3, guest PC 0x0c0c82aa */
if(!s->budget--) { s->failed_pc=0x0c0c82aau; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c0c82ac;
P_0c0c82ac: /* original 67b3, guest PC 0x0c0c82ac */
if(!s->budget--) { s->failed_pc=0x0c0c82acu; return 0; }
r[7]=r[11];
goto P_0c0c82ae;
P_0c0c82ae: /* original 9357, guest PC 0x0c0c82ae */
if(!s->budget--) { s->failed_pc=0x0c0c82aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8360u,2);
goto P_0c0c82b0;
P_0c0c82b0: /* original 7658, guest PC 0x0c0c82b0 */
if(!s->budget--) { s->failed_pc=0x0c0c82b0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c82b2;
P_0c0c82b2: /* original 9457, guest PC 0x0c0c82b2 */
if(!s->budget--) { s->failed_pc=0x0c0c82b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8364u,2);
goto P_0c0c82b4;
P_0c0c82b4: /* original 4c0b, guest PC 0x0c0c82b4 */
if(!s->budget--) { s->failed_pc=0x0c0c82b4u; return 0; }
target=r[12];
r[16]=0x0c0c82b8u;
r[5]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c82b8u) { target=s->pc; goto dispatch; }
goto P_0c0c82b8;
P_0c0c82b6: /* original 353c, guest PC 0x0c0c82b6 */
if(!s->budget--) { s->failed_pc=0x0c0c82b6u; return 0; }
r[5]+=r[3];
goto P_0c0c82b8;
P_0c0c82b8: /* original 7f08, guest PC 0x0c0c82b8 */
if(!s->budget--) { s->failed_pc=0x0c0c82b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c82ba;
P_0c0c82ba: /* original 9155, guest PC 0x0c0c82ba */
if(!s->budget--) { s->failed_pc=0x0c0c82bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8368u,2);
goto P_0c0c82bc;
P_0c0c82bc: /* original 50f2, guest PC 0x0c0c82bc */
if(!s->budget--) { s->failed_pc=0x0c0c82bcu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0c82be;
P_0c0c82be: /* original 9d52, guest PC 0x0c0c82be */
if(!s->budget--) { s->failed_pc=0x0c0c82beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8366u,2);
goto P_0c0c82c0;
P_0c0c82c0: /* original 001c, guest PC 0x0c0c82c0 */
if(!s->budget--) { s->failed_pc=0x0c0c82c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c82c2;
P_0c0c82c2: /* original 8801, guest PC 0x0c0c82c2 */
if(!s->budget--) { s->failed_pc=0x0c0c82c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c82c4;
P_0c0c82c4: /* original 8f01, guest PC 0x0c0c82c4 */
if(!s->budget--) { s->failed_pc=0x0c0c82c4u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c0c82ca; }
goto P_0c0c82c8;
P_0c0c82c6: /* original 2fb6, guest PC 0x0c0c82c6 */
if(!s->budget--) { s->failed_pc=0x0c0c82c6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82c8;
P_0c0c82c8: /* original 9d4f, guest PC 0x0c0c82c8 */
if(!s->budget--) { s->failed_pc=0x0c0c82c8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836au,2);
goto P_0c0c82ca;
P_0c0c82ca: /* original 954f, guest PC 0x0c0c82ca */
if(!s->budget--) { s->failed_pc=0x0c0c82cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836cu,2);
goto P_0c0c82cc;
P_0c0c82cc: /* original 66e3, guest PC 0x0c0c82cc */
if(!s->budget--) { s->failed_pc=0x0c0c82ccu; return 0; }
r[6]=r[14];
goto P_0c0c82ce;
P_0c0c82ce: /* original e700, guest PC 0x0c0c82ce */
if(!s->budget--) { s->failed_pc=0x0c0c82ceu; return 0; }
r[7]=0x00000000u;
goto P_0c0c82d0;
P_0c0c82d0: /* original 4c0b, guest PC 0x0c0c82d0 */
if(!s->budget--) { s->failed_pc=0x0c0c82d0u; return 0; }
target=r[12];
r[16]=0x0c0c82d4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c82d4u) { target=s->pc; goto dispatch; }
goto P_0c0c82d4;
P_0c0c82d2: /* original 64d3, guest PC 0x0c0c82d2 */
if(!s->budget--) { s->failed_pc=0x0c0c82d2u; return 0; }
r[4]=r[13];
goto P_0c0c82d4;
P_0c0c82d4: /* original 7f10, guest PC 0x0c0c82d4 */
if(!s->budget--) { s->failed_pc=0x0c0c82d4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c82d6;
P_0c0c82d6: /* original 64d3, guest PC 0x0c0c82d6 */
if(!s->budget--) { s->failed_pc=0x0c0c82d6u; return 0; }
r[4]=r[13];
goto P_0c0c82d8;
P_0c0c82d8: /* original 4f26, guest PC 0x0c0c82d8 */
if(!s->budget--) { s->failed_pc=0x0c0c82d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c82da;
P_0c0c82da: /* original 6bf6, guest PC 0x0c0c82da */
if(!s->budget--) { s->failed_pc=0x0c0c82dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c82dc;
P_0c0c82dc: /* original 6cf6, guest PC 0x0c0c82dc */
if(!s->budget--) { s->failed_pc=0x0c0c82dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c82de;
P_0c0c82de: /* original 6df6, guest PC 0x0c0c82de */
if(!s->budget--) { s->failed_pc=0x0c0c82deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c82e0;
P_0c0c82e0: /* original a020, guest PC 0x0c0c82e0 */
if(!s->budget--) { s->failed_pc=0x0c0c82e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c82e2: /* original 6ef6, guest PC 0x0c0c82e2 */
if(!s->budget--) { s->failed_pc=0x0c0c82e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c82e4u,s,ram);
P_0c0c8324: /* original 2fe6, guest PC 0x0c0c8324 */
if(!s->budget--) { s->failed_pc=0x0c0c8324u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8326;
P_0c0c8326: /* original 2fd6, guest PC 0x0c0c8326 */
if(!s->budget--) { s->failed_pc=0x0c0c8326u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8328;
P_0c0c8328: /* original 2fc6, guest PC 0x0c0c8328 */
if(!s->budget--) { s->failed_pc=0x0c0c8328u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832a;
P_0c0c832a: /* original 2fb6, guest PC 0x0c0c832a */
if(!s->budget--) { s->failed_pc=0x0c0c832au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832c;
P_0c0c832c: /* original 2fa6, guest PC 0x0c0c832c */
if(!s->budget--) { s->failed_pc=0x0c0c832cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832e;
P_0c0c832e: /* original 2f96, guest PC 0x0c0c832e */
if(!s->budget--) { s->failed_pc=0x0c0c832eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8330;
P_0c0c8330: /* original 2f86, guest PC 0x0c0c8330 */
if(!s->budget--) { s->failed_pc=0x0c0c8330u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8332;
P_0c0c8332: /* original de14, guest PC 0x0c0c8332 */
if(!s->budget--) { s->failed_pc=0x0c0c8332u; return 0; }
r[14]=read(ram,0x0c0c8384u,4);
goto P_0c0c8334;
P_0c0c8334: /* original 4f22, guest PC 0x0c0c8334 */
if(!s->budget--) { s->failed_pc=0x0c0c8334u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8336;
P_0c0c8336: /* original d310, guest PC 0x0c0c8336 */
if(!s->budget--) { s->failed_pc=0x0c0c8336u; return 0; }
r[3]=read(ram,0x0c0c8378u,4);
goto P_0c0c8338;
P_0c0c8338: /* original dd0e, guest PC 0x0c0c8338 */
if(!s->budget--) { s->failed_pc=0x0c0c8338u; return 0; }
r[13]=read(ram,0x0c0c8374u,4);
goto P_0c0c833a;
P_0c0c833a: /* original 7fe8, guest PC 0x0c0c833a */
if(!s->budget--) { s->failed_pc=0x0c0c833au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0c833c;
P_0c0c833c: /* original 1f35, guest PC 0x0c0c833c */
if(!s->budget--) { s->failed_pc=0x0c0c833cu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0c833e;
P_0c0c833e: /* original d213, guest PC 0x0c0c833e */
if(!s->budget--) { s->failed_pc=0x0c0c833eu; return 0; }
r[2]=read(ram,0x0c0c838cu,4);
goto P_0c0c8340;
P_0c0c8340: /* original 1f24, guest PC 0x0c0c8340 */
if(!s->budget--) { s->failed_pc=0x0c0c8340u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0c8342;
P_0c0c8342: /* original 9016, guest PC 0x0c0c8342 */
if(!s->budget--) { s->failed_pc=0x0c0c8342u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8372u,2);
goto P_0c0c8344;
P_0c0c8344: /* original d912, guest PC 0x0c0c8344 */
if(!s->budget--) { s->failed_pc=0x0c0c8344u; return 0; }
r[9]=read(ram,0x0c0c8390u,4);
goto P_0c0c8346;
P_0c0c8346: /* original 04ec, guest PC 0x0c0c8346 */
if(!s->budget--) { s->failed_pc=0x0c0c8346u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8348;
P_0c0c8348: /* original 7001, guest PC 0x0c0c8348 */
if(!s->budget--) { s->failed_pc=0x0c0c8348u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c834a;
P_0c0c834a: /* original 06ec, guest PC 0x0c0c834a */
if(!s->budget--) { s->failed_pc=0x0c0c834au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c834c;
P_0c0c834c: /* original 644c, guest PC 0x0c0c834c */
if(!s->budget--) { s->failed_pc=0x0c0c834cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c834e;
P_0c0c834e: /* original 666c, guest PC 0x0c0c834e */
if(!s->budget--) { s->failed_pc=0x0c0c834eu; return 0; }
r[6]=r[6]&255u;
goto P_0c0c8350;
P_0c0c8350: /* original 6763, guest PC 0x0c0c8350 */
if(!s->budget--) { s->failed_pc=0x0c0c8350u; return 0; }
r[7]=r[6];
goto P_0c0c8352;
P_0c0c8352: /* original 4708, guest PC 0x0c0c8352 */
if(!s->budget--) { s->failed_pc=0x0c0c8352u; return 0; }
r[7]<<=2;
goto P_0c0c8354;
P_0c0c8354: /* original 4700, guest PC 0x0c0c8354 */
if(!s->budget--) { s->failed_pc=0x0c0c8354u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c8356;
P_0c0c8356: /* original 2448, guest PC 0x0c0c8356 */
if(!s->budget--) { s->failed_pc=0x0c0c8356u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c8358;
P_0c0c8358: /* original 891c, guest PC 0x0c0c8358 */
if(!s->budget--) { s->failed_pc=0x0c0c8358u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8394; }
goto P_0c0c835a;
P_0c0c835a: /* original 6573, guest PC 0x0c0c835a */
if(!s->budget--) { s->failed_pc=0x0c0c835au; return 0; }
r[5]=r[7];
goto P_0c0c835c;
P_0c0c835c: /* original a01c, guest PC 0x0c0c835c */
if(!s->budget--) { s->failed_pc=0x0c0c835cu; return 0; }
r[5]+=0x00000003u;
goto P_0c0c8398;
P_0c0c835e: /* original 7503, guest PC 0x0c0c835e */
if(!s->budget--) { s->failed_pc=0x0c0c835eu; return 0; }
r[5]+=0x00000003u;
return vf3_matrix_family(0x0c0c8360u,s,ram);
P_0c0c8394: /* original 6573, guest PC 0x0c0c8394 */
if(!s->budget--) { s->failed_pc=0x0c0c8394u; return 0; }
r[5]=r[7];
goto P_0c0c8396;
P_0c0c8396: /* original 7507, guest PC 0x0c0c8396 */
if(!s->budget--) { s->failed_pc=0x0c0c8396u; return 0; }
r[5]+=0x00000007u;
goto P_0c0c8398;
P_0c0c8398: /* original 6243, guest PC 0x0c0c8398 */
if(!s->budget--) { s->failed_pc=0x0c0c8398u; return 0; }
r[2]=r[4];
goto P_0c0c839a;
P_0c0c839a: /* original 6343, guest PC 0x0c0c839a */
if(!s->budget--) { s->failed_pc=0x0c0c839au; return 0; }
r[3]=r[4];
goto P_0c0c839c;
P_0c0c839c: /* original 6743, guest PC 0x0c0c839c */
if(!s->budget--) { s->failed_pc=0x0c0c839cu; return 0; }
r[7]=r[4];
goto P_0c0c839e;
P_0c0c839e: /* original 4208, guest PC 0x0c0c839e */
if(!s->budget--) { s->failed_pc=0x0c0c839eu; return 0; }
r[2]<<=2;
goto P_0c0c83a0;
P_0c0c83a0: /* original 4708, guest PC 0x0c0c83a0 */
if(!s->budget--) { s->failed_pc=0x0c0c83a0u; return 0; }
r[7]<<=2;
goto P_0c0c83a2;
P_0c0c83a2: /* original 4700, guest PC 0x0c0c83a2 */
if(!s->budget--) { s->failed_pc=0x0c0c83a2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c83a4;
P_0c0c83a4: /* original 4400, guest PC 0x0c0c83a4 */
if(!s->budget--) { s->failed_pc=0x0c0c83a4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c83a6;
P_0c0c83a6: /* original 342c, guest PC 0x0c0c83a6 */
if(!s->budget--) { s->failed_pc=0x0c0c83a6u; return 0; }
r[4]+=r[2];
goto P_0c0c83a8;
P_0c0c83a8: /* original 3738, guest PC 0x0c0c83a8 */
if(!s->budget--) { s->failed_pc=0x0c0c83a8u; return 0; }
r[7]-=r[3];
goto P_0c0c83aa;
P_0c0c83aa: /* original 346c, guest PC 0x0c0c83aa */
if(!s->budget--) { s->failed_pc=0x0c0c83aau; return 0; }
r[4]+=r[6];
goto P_0c0c83ac;
P_0c0c83ac: /* original 6343, guest PC 0x0c0c83ac */
if(!s->budget--) { s->failed_pc=0x0c0c83acu; return 0; }
r[3]=r[4];
goto P_0c0c83ae;
P_0c0c83ae: /* original 4300, guest PC 0x0c0c83ae */
if(!s->budget--) { s->failed_pc=0x0c0c83aeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c83b0;
P_0c0c83b0: /* original e107, guest PC 0x0c0c83b0 */
if(!s->budget--) { s->failed_pc=0x0c0c83b0u; return 0; }
r[1]=0x00000007u;
goto P_0c0c83b2;
P_0c0c83b2: /* original 1f42, guest PC 0x0c0c83b2 */
if(!s->budget--) { s->failed_pc=0x0c0c83b2u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0c83b4;
P_0c0c83b4: /* original 4500, guest PC 0x0c0c83b4 */
if(!s->budget--) { s->failed_pc=0x0c0c83b4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c83b6;
P_0c0c83b6: /* original 1f31, guest PC 0x0c0c83b6 */
if(!s->budget--) { s->failed_pc=0x0c0c83b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c83b8;
P_0c0c83b8: /* original d031, guest PC 0x0c0c83b8 */
if(!s->budget--) { s->failed_pc=0x0c0c83b8u; return 0; }
r[0]=read(ram,0x0c0c8480u,4);
goto P_0c0c83ba;
P_0c0c83ba: /* original 7721, guest PC 0x0c0c83ba */
if(!s->budget--) { s->failed_pc=0x0c0c83bau; return 0; }
r[7]+=0x00000021u;
goto P_0c0c83bc;
P_0c0c83bc: /* original 6a53, guest PC 0x0c0c83bc */
if(!s->budget--) { s->failed_pc=0x0c0c83bcu; return 0; }
r[10]=r[5];
goto P_0c0c83be;
P_0c0c83be: /* original 471c, guest PC 0x0c0c83be */
if(!s->budget--) { s->failed_pc=0x0c0c83beu; return 0; }
r[7]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[7]>>((-r[1])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[1]&31u);
goto P_0c0c83c0;
P_0c0c83c0: /* original 023d, guest PC 0x0c0c83c0 */
if(!s->budget--) { s->failed_pc=0x0c0c83c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c83c2;
P_0c0c83c2: /* original 2a7b, guest PC 0x0c0c83c2 */
if(!s->budget--) { s->failed_pc=0x0c0c83c2u; return 0; }
r[10]|=r[7];
goto P_0c0c83c4;
P_0c0c83c4: /* original 622d, guest PC 0x0c0c83c4 */
if(!s->budget--) { s->failed_pc=0x0c0c83c4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c83c6;
P_0c0c83c6: /* original 1f23, guest PC 0x0c0c83c6 */
if(!s->budget--) { s->failed_pc=0x0c0c83c6u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c83c8;
P_0c0c83c8: /* original 9054, guest PC 0x0c0c83c8 */
if(!s->budget--) { s->failed_pc=0x0c0c83c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8474u,2);
goto P_0c0c83ca;
P_0c0c83ca: /* original 0ea6, guest PC 0x0c0c83ca */
if(!s->budget--) { s->failed_pc=0x0c0c83cau; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c0c83cc;
P_0c0c83cc: /* original 9353, guest PC 0x0c0c83cc */
if(!s->budget--) { s->failed_pc=0x0c0c83ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8476u,2);
goto P_0c0c83ce;
P_0c0c83ce: /* original 2f32, guest PC 0x0c0c83ce */
if(!s->budget--) { s->failed_pc=0x0c0c83ceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c83d0;
P_0c0c83d0: /* original 50f5, guest PC 0x0c0c83d0 */
if(!s->budget--) { s->failed_pc=0x0c0c83d0u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c0c83d2;
P_0c0c83d2: /* original 9251, guest PC 0x0c0c83d2 */
if(!s->budget--) { s->failed_pc=0x0c0c83d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8478u,2);
goto P_0c0c83d4;
P_0c0c83d4: /* original 002c, guest PC 0x0c0c83d4 */
if(!s->budget--) { s->failed_pc=0x0c0c83d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0c83d6;
P_0c0c83d6: /* original 8801, guest PC 0x0c0c83d6 */
if(!s->budget--) { s->failed_pc=0x0c0c83d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83d8;
P_0c0c83d8: /* original 8b01, guest PC 0x0c0c83d8 */
if(!s->budget--) { s->failed_pc=0x0c0c83d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c83de; }
goto P_0c0c83da;
P_0c0c83da: /* original 904e, guest PC 0x0c0c83da */
if(!s->budget--) { s->failed_pc=0x0c0c83dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847au,2);
goto P_0c0c83dc;
P_0c0c83dc: /* original 2f02, guest PC 0x0c0c83dc */
if(!s->budget--) { s->failed_pc=0x0c0c83dcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c83de;
P_0c0c83de: /* original 904d, guest PC 0x0c0c83de */
if(!s->budget--) { s->failed_pc=0x0c0c83deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847cu,2);
goto P_0c0c83e0;
P_0c0c83e0: /* original db29, guest PC 0x0c0c83e0 */
if(!s->budget--) { s->failed_pc=0x0c0c83e0u; return 0; }
r[11]=read(ram,0x0c0c8488u,4);
goto P_0c0c83e2;
P_0c0c83e2: /* original 00ec, guest PC 0x0c0c83e2 */
if(!s->budget--) { s->failed_pc=0x0c0c83e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c83e4;
P_0c0c83e4: /* original d827, guest PC 0x0c0c83e4 */
if(!s->budget--) { s->failed_pc=0x0c0c83e4u; return 0; }
r[8]=read(ram,0x0c0c8484u,4);
goto P_0c0c83e6;
P_0c0c83e6: /* original 600c, guest PC 0x0c0c83e6 */
if(!s->budget--) { s->failed_pc=0x0c0c83e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c83e8;
P_0c0c83e8: /* original 8801, guest PC 0x0c0c83e8 */
if(!s->budget--) { s->failed_pc=0x0c0c83e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c83ea;
P_0c0c83ea: /* original 8d04, guest PC 0x0c0c83ea */
if(!s->budget--) { s->failed_pc=0x0c0c83eau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c0c83f6; }
goto P_0c0c83ee;
P_0c0c83ec: /* original ec00, guest PC 0x0c0c83ec */
if(!s->budget--) { s->failed_pc=0x0c0c83ecu; return 0; }
r[12]=0x00000000u;
goto P_0c0c83ee;
P_0c0c83ee: /* original 50f4, guest PC 0x0c0c83ee */
if(!s->budget--) { s->failed_pc=0x0c0c83eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c83f0;
P_0c0c83f0: /* original 6002, guest PC 0x0c0c83f0 */
if(!s->budget--) { s->failed_pc=0x0c0c83f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c83f2;
P_0c0c83f2: /* original c808, guest PC 0x0c0c83f2 */
if(!s->budget--) { s->failed_pc=0x0c0c83f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0c83f4;
P_0c0c83f4: /* original 8b0d, guest PC 0x0c0c83f4 */
if(!s->budget--) { s->failed_pc=0x0c0c83f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8412; }
goto P_0c0c83f6;
P_0c0c83f6: /* original 2fc6, guest PC 0x0c0c83f6 */
if(!s->budget--) { s->failed_pc=0x0c0c83f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c83f8;
P_0c0c83f8: /* original 66d3, guest PC 0x0c0c83f8 */
if(!s->budget--) { s->failed_pc=0x0c0c83f8u; return 0; }
r[6]=r[13];
goto P_0c0c83fa;
P_0c0c83fa: /* original 55f1, guest PC 0x0c0c83fa */
if(!s->budget--) { s->failed_pc=0x0c0c83fau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c83fc;
P_0c0c83fc: /* original e700, guest PC 0x0c0c83fc */
if(!s->budget--) { s->failed_pc=0x0c0c83fcu; return 0; }
r[7]=0x00000000u;
goto P_0c0c83fe;
P_0c0c83fe: /* original 4b0b, guest PC 0x0c0c83fe */
if(!s->budget--) { s->failed_pc=0x0c0c83feu; return 0; }
target=r[11];
r[16]=0x0c0c8402u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8402u) { target=s->pc; goto dispatch; }
goto P_0c0c8402;
P_0c0c8400: /* original 64a3, guest PC 0x0c0c8400 */
if(!s->budget--) { s->failed_pc=0x0c0c8400u; return 0; }
r[4]=r[10];
goto P_0c0c8402;
P_0c0c8402: /* original 2fc6, guest PC 0x0c0c8402 */
if(!s->budget--) { s->failed_pc=0x0c0c8402u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8404;
P_0c0c8404: /* original 66d3, guest PC 0x0c0c8404 */
if(!s->budget--) { s->failed_pc=0x0c0c8404u; return 0; }
r[6]=r[13];
goto P_0c0c8406;
P_0c0c8406: /* original 55f5, guest PC 0x0c0c8406 */
if(!s->budget--) { s->failed_pc=0x0c0c8406u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8408;
P_0c0c8408: /* original e700, guest PC 0x0c0c8408 */
if(!s->budget--) { s->failed_pc=0x0c0c8408u; return 0; }
r[7]=0x00000000u;
goto P_0c0c840a;
P_0c0c840a: /* original 480b, guest PC 0x0c0c840a */
if(!s->budget--) { s->failed_pc=0x0c0c840au; return 0; }
target=r[8];
r[16]=0x0c0c840eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c840eu) { target=s->pc; goto dispatch; }
goto P_0c0c840e;
P_0c0c840c: /* original 64a3, guest PC 0x0c0c840c */
if(!s->budget--) { s->failed_pc=0x0c0c840cu; return 0; }
r[4]=r[10];
goto P_0c0c840e;
P_0c0c840e: /* original a00c, guest PC 0x0c0c840e */
if(!s->budget--) { s->failed_pc=0x0c0c840eu; return 0; }
goto P_0c0c842a;
P_0c0c8410: /* original 0009, guest PC 0x0c0c8410 */
if(!s->budget--) { s->failed_pc=0x0c0c8410u; return 0; }
goto P_0c0c8412;
P_0c0c8412: /* original 2fc6, guest PC 0x0c0c8412 */
if(!s->budget--) { s->failed_pc=0x0c0c8412u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8414;
P_0c0c8414: /* original 66d3, guest PC 0x0c0c8414 */
if(!s->budget--) { s->failed_pc=0x0c0c8414u; return 0; }
r[6]=r[13];
goto P_0c0c8416;
P_0c0c8416: /* original 55f1, guest PC 0x0c0c8416 */
if(!s->budget--) { s->failed_pc=0x0c0c8416u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c8418;
P_0c0c8418: /* original e700, guest PC 0x0c0c8418 */
if(!s->budget--) { s->failed_pc=0x0c0c8418u; return 0; }
r[7]=0x00000000u;
goto P_0c0c841a;
P_0c0c841a: /* original 480b, guest PC 0x0c0c841a */
if(!s->budget--) { s->failed_pc=0x0c0c841au; return 0; }
target=r[8];
r[16]=0x0c0c841eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c841eu) { target=s->pc; goto dispatch; }
goto P_0c0c841e;
P_0c0c841c: /* original 64a3, guest PC 0x0c0c841c */
if(!s->budget--) { s->failed_pc=0x0c0c841cu; return 0; }
r[4]=r[10];
goto P_0c0c841e;
P_0c0c841e: /* original 2fc6, guest PC 0x0c0c841e */
if(!s->budget--) { s->failed_pc=0x0c0c841eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8420;
P_0c0c8420: /* original 66d3, guest PC 0x0c0c8420 */
if(!s->budget--) { s->failed_pc=0x0c0c8420u; return 0; }
r[6]=r[13];
goto P_0c0c8422;
P_0c0c8422: /* original 55f5, guest PC 0x0c0c8422 */
if(!s->budget--) { s->failed_pc=0x0c0c8422u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0c8424;
P_0c0c8424: /* original e700, guest PC 0x0c0c8424 */
if(!s->budget--) { s->failed_pc=0x0c0c8424u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8426;
P_0c0c8426: /* original 4b0b, guest PC 0x0c0c8426 */
if(!s->budget--) { s->failed_pc=0x0c0c8426u; return 0; }
target=r[11];
r[16]=0x0c0c842au;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c842au) { target=s->pc; goto dispatch; }
goto P_0c0c842a;
P_0c0c8428: /* original 64a3, guest PC 0x0c0c8428 */
if(!s->budget--) { s->failed_pc=0x0c0c8428u; return 0; }
r[4]=r[10];
goto P_0c0c842a;
P_0c0c842a: /* original 7f08, guest PC 0x0c0c842a */
if(!s->budget--) { s->failed_pc=0x0c0c842au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c842c;
P_0c0c842c: /* original d017, guest PC 0x0c0c842c */
if(!s->budget--) { s->failed_pc=0x0c0c842cu; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c842e;
P_0c0c842e: /* original 53f1, guest PC 0x0c0c842e */
if(!s->budget--) { s->failed_pc=0x0c0c842eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8430;
P_0c0c8430: /* original 6a93, guest PC 0x0c0c8430 */
if(!s->budget--) { s->failed_pc=0x0c0c8430u; return 0; }
r[10]=r[9];
goto P_0c0c8432;
P_0c0c8432: /* original 003d, guest PC 0x0c0c8432 */
if(!s->budget--) { s->failed_pc=0x0c0c8432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8434;
P_0c0c8434: /* original 88ff, guest PC 0x0c0c8434 */
if(!s->budget--) { s->failed_pc=0x0c0c8434u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c8436;
P_0c0c8436: /* original 8d0f, guest PC 0x0c0c8436 */
if(!s->budget--) { s->failed_pc=0x0c0c8436u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000040u;
if(cond) { goto P_0c0c8458; }
goto P_0c0c843a;
P_0c0c8438: /* original 7a40, guest PC 0x0c0c8438 */
if(!s->budget--) { s->failed_pc=0x0c0c8438u; return 0; }
r[10]+=0x00000040u;
goto P_0c0c843a;
P_0c0c843a: /* original 51f2, guest PC 0x0c0c843a */
if(!s->budget--) { s->failed_pc=0x0c0c843au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0c843c;
P_0c0c843c: /* original 4108, guest PC 0x0c0c843c */
if(!s->budget--) { s->failed_pc=0x0c0c843cu; return 0; }
r[1]<<=2;
goto P_0c0c843e;
P_0c0c843e: /* original 319c, guest PC 0x0c0c843e */
if(!s->budget--) { s->failed_pc=0x0c0c843eu; return 0; }
r[1]+=r[9];
goto P_0c0c8440;
P_0c0c8440: /* original 2f12, guest PC 0x0c0c8440 */
if(!s->budget--) { s->failed_pc=0x0c0c8440u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c8442;
P_0c0c8442: /* original 2a12, guest PC 0x0c0c8442 */
if(!s->budget--) { s->failed_pc=0x0c0c8442u; return 0; }
write(ram,r[10],r[1],4);
goto P_0c0c8444;
P_0c0c8444: /* original 65f2, guest PC 0x0c0c8444 */
if(!s->budget--) { s->failed_pc=0x0c0c8444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c8446;
P_0c0c8446: /* original 53f1, guest PC 0x0c0c8446 */
if(!s->budget--) { s->failed_pc=0x0c0c8446u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c8448;
P_0c0c8448: /* original d010, guest PC 0x0c0c8448 */
if(!s->budget--) { s->failed_pc=0x0c0c8448u; return 0; }
r[0]=read(ram,0x0c0c848cu,4);
goto P_0c0c844a;
P_0c0c844a: /* original d211, guest PC 0x0c0c844a */
if(!s->budget--) { s->failed_pc=0x0c0c844au; return 0; }
r[2]=read(ram,0x0c0c8490u,4);
goto P_0c0c844c;
P_0c0c844c: /* original 420b, guest PC 0x0c0c844c */
if(!s->budget--) { s->failed_pc=0x0c0c844cu; return 0; }
target=r[2];
r[16]=0x0c0c8450u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8450u) { target=s->pc; goto dispatch; }
goto P_0c0c8450;
P_0c0c844e: /* original 043d, guest PC 0x0c0c844e */
if(!s->budget--) { s->failed_pc=0x0c0c844eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c8450;
P_0c0c8450: /* original 63f2, guest PC 0x0c0c8450 */
if(!s->budget--) { s->failed_pc=0x0c0c8450u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8452;
P_0c0c8452: /* original 6232, guest PC 0x0c0c8452 */
if(!s->budget--) { s->failed_pc=0x0c0c8452u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0c8454;
P_0c0c8454: /* original 2228, guest PC 0x0c0c8454 */
if(!s->budget--) { s->failed_pc=0x0c0c8454u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8456;
P_0c0c8456: /* original 891d, guest PC 0x0c0c8456 */
if(!s->budget--) { s->failed_pc=0x0c0c8456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c8458;
P_0c0c8458: /* original 61a2, guest PC 0x0c0c8458 */
if(!s->budget--) { s->failed_pc=0x0c0c8458u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0c845a;
P_0c0c845a: /* original 2118, guest PC 0x0c0c845a */
if(!s->budget--) { s->failed_pc=0x0c0c845au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c845c;
P_0c0c845c: /* original 891a, guest PC 0x0c0c845c */
if(!s->budget--) { s->failed_pc=0x0c0c845cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8494; }
goto P_0c0c845e;
P_0c0c845e: /* original 64a2, guest PC 0x0c0c845e */
if(!s->budget--) { s->failed_pc=0x0c0c845eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8460;
P_0c0c8460: /* original 6342, guest PC 0x0c0c8460 */
if(!s->budget--) { s->failed_pc=0x0c0c8460u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c8462;
P_0c0c8462: /* original 2338, guest PC 0x0c0c8462 */
if(!s->budget--) { s->failed_pc=0x0c0c8462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c8464;
P_0c0c8464: /* original 8901, guest PC 0x0c0c8464 */
if(!s->budget--) { s->failed_pc=0x0c0c8464u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c846a; }
goto P_0c0c8466;
P_0c0c8466: /* original a015, guest PC 0x0c0c8466 */
if(!s->budget--) { s->failed_pc=0x0c0c8466u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c8494;
P_0c0c8468: /* original 2ac2, guest PC 0x0c0c8468 */
if(!s->budget--) { s->failed_pc=0x0c0c8468u; return 0; }
write(ram,r[10],r[12],4);
goto P_0c0c846a;
P_0c0c846a: /* original 9308, guest PC 0x0c0c846a */
if(!s->budget--) { s->failed_pc=0x0c0c846au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c847eu,2);
goto P_0c0c846c;
P_0c0c846c: /* original 6033, guest PC 0x0c0c846c */
if(!s->budget--) { s->failed_pc=0x0c0c846cu; return 0; }
r[0]=r[3];
goto P_0c0c846e;
P_0c0c846e: /* original 70d0, guest PC 0x0c0c846e */
if(!s->budget--) { s->failed_pc=0x0c0c846eu; return 0; }
r[0]+=0xffffffd0u;
goto P_0c0c8470;
P_0c0c8470: /* original a0b7, guest PC 0x0c0c8470 */
if(!s->budget--) { s->failed_pc=0x0c0c8470u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c85e2;
P_0c0c8472: /* original 0e34, guest PC 0x0c0c8472 */
if(!s->budget--) { s->failed_pc=0x0c0c8472u; return 0; }
write(ram,r[14]+r[0],r[3],1);
return vf3_matrix_family(0x0c0c8474u,s,ram);
P_0c0c8494: /* original 905f, guest PC 0x0c0c8494 */
if(!s->budget--) { s->failed_pc=0x0c0c8494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8556u,2);
goto P_0c0c8496;
P_0c0c8496: /* original 01ec, guest PC 0x0c0c8496 */
if(!s->budget--) { s->failed_pc=0x0c0c8496u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8498;
P_0c0c8498: /* original 70f8, guest PC 0x0c0c8498 */
if(!s->budget--) { s->failed_pc=0x0c0c8498u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c849a;
P_0c0c849a: /* original 03ec, guest PC 0x0c0c849a */
if(!s->budget--) { s->failed_pc=0x0c0c849au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c849c;
P_0c0c849c: /* original 3130, guest PC 0x0c0c849c */
if(!s->budget--) { s->failed_pc=0x0c0c849cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0c849e;
P_0c0c849e: /* original 8939, guest PC 0x0c0c849e */
if(!s->budget--) { s->failed_pc=0x0c0c849eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8514; }
goto P_0c0c84a0;
P_0c0c84a0: /* original 905a, guest PC 0x0c0c84a0 */
if(!s->budget--) { s->failed_pc=0x0c0c84a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84a2;
P_0c0c84a2: /* original 00ed, guest PC 0x0c0c84a2 */
if(!s->budget--) { s->failed_pc=0x0c0c84a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84a4;
P_0c0c84a4: /* original 88ff, guest PC 0x0c0c84a4 */
if(!s->budget--) { s->failed_pc=0x0c0c84a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c84a6;
P_0c0c84a6: /* original 8d18, guest PC 0x0c0c84a6 */
if(!s->budget--) { s->failed_pc=0x0c0c84a6u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(cond) { goto P_0c0c84da; }
goto P_0c0c84aa;
P_0c0c84a8: /* original 6a03, guest PC 0x0c0c84a8 */
if(!s->budget--) { s->failed_pc=0x0c0c84a8u; return 0; }
r[10]=r[0];
goto P_0c0c84aa;
P_0c0c84aa: /* original e220, guest PC 0x0c0c84aa */
if(!s->budget--) { s->failed_pc=0x0c0c84aau; return 0; }
r[2]=0x00000020u;
goto P_0c0c84ac;
P_0c0c84ac: /* original 64d3, guest PC 0x0c0c84ac */
if(!s->budget--) { s->failed_pc=0x0c0c84acu; return 0; }
r[4]=r[13];
goto P_0c0c84ae;
P_0c0c84ae: /* original 2f26, guest PC 0x0c0c84ae */
if(!s->budget--) { s->failed_pc=0x0c0c84aeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84b0;
P_0c0c84b0: /* original 6723, guest PC 0x0c0c84b0 */
if(!s->budget--) { s->failed_pc=0x0c0c84b0u; return 0; }
r[7]=r[2];
goto P_0c0c84b2;
P_0c0c84b2: /* original 9552, guest PC 0x0c0c84b2 */
if(!s->budget--) { s->failed_pc=0x0c0c84b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84b4;
P_0c0c84b4: /* original e63e, guest PC 0x0c0c84b4 */
if(!s->budget--) { s->failed_pc=0x0c0c84b4u; return 0; }
r[6]=0x0000003eu;
goto P_0c0c84b6;
P_0c0c84b6: /* original d32a, guest PC 0x0c0c84b6 */
if(!s->budget--) { s->failed_pc=0x0c0c84b6u; return 0; }
r[3]=read(ram,0x0c0c8560u,4);
goto P_0c0c84b8;
P_0c0c84b8: /* original 430b, guest PC 0x0c0c84b8 */
if(!s->budget--) { s->failed_pc=0x0c0c84b8u; return 0; }
target=r[3];
r[16]=0x0c0c84bcu;
r[4]+=0x00000058u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84bcu) { target=s->pc; goto dispatch; }
goto P_0c0c84bc;
P_0c0c84ba: /* original 7458, guest PC 0x0c0c84ba */
if(!s->budget--) { s->failed_pc=0x0c0c84bau; return 0; }
r[4]+=0x00000058u;
goto P_0c0c84bc;
P_0c0c84bc: /* original d229, guest PC 0x0c0c84bc */
if(!s->budget--) { s->failed_pc=0x0c0c84bcu; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84be;
P_0c0c84be: /* original 7f04, guest PC 0x0c0c84be */
if(!s->budget--) { s->failed_pc=0x0c0c84beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84c0;
P_0c0c84c0: /* original 420b, guest PC 0x0c0c84c0 */
if(!s->budget--) { s->failed_pc=0x0c0c84c0u; return 0; }
target=r[2];
r[16]=0x0c0c84c4u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84c4u) { target=s->pc; goto dispatch; }
goto P_0c0c84c4;
P_0c0c84c2: /* original 64a3, guest PC 0x0c0c84c2 */
if(!s->budget--) { s->failed_pc=0x0c0c84c2u; return 0; }
r[4]=r[10];
goto P_0c0c84c4;
P_0c0c84c4: /* original 600d, guest PC 0x0c0c84c4 */
if(!s->budget--) { s->failed_pc=0x0c0c84c4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84c6;
P_0c0c84c6: /* original 2008, guest PC 0x0c0c84c6 */
if(!s->budget--) { s->failed_pc=0x0c0c84c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c84c8;
P_0c0c84c8: /* original 8907, guest PC 0x0c0c84c8 */
if(!s->budget--) { s->failed_pc=0x0c0c84c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c84da; }
goto P_0c0c84ca;
P_0c0c84ca: /* original 66d3, guest PC 0x0c0c84ca */
if(!s->budget--) { s->failed_pc=0x0c0c84cau; return 0; }
r[6]=r[13];
goto P_0c0c84cc;
P_0c0c84cc: /* original 2fc6, guest PC 0x0c0c84cc */
if(!s->budget--) { s->failed_pc=0x0c0c84ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c84ce;
P_0c0c84ce: /* original 9444, guest PC 0x0c0c84ce */
if(!s->budget--) { s->failed_pc=0x0c0c84ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c84d0;
P_0c0c84d0: /* original 7658, guest PC 0x0c0c84d0 */
if(!s->budget--) { s->failed_pc=0x0c0c84d0u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c84d2;
P_0c0c84d2: /* original e700, guest PC 0x0c0c84d2 */
if(!s->budget--) { s->failed_pc=0x0c0c84d2u; return 0; }
r[7]=0x00000000u;
goto P_0c0c84d4;
P_0c0c84d4: /* original 4b0b, guest PC 0x0c0c84d4 */
if(!s->budget--) { s->failed_pc=0x0c0c84d4u; return 0; }
target=r[11];
r[16]=0x0c0c84d8u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84d8u) { target=s->pc; goto dispatch; }
goto P_0c0c84d8;
P_0c0c84d6: /* original 65a3, guest PC 0x0c0c84d6 */
if(!s->budget--) { s->failed_pc=0x0c0c84d6u; return 0; }
r[5]=r[10];
goto P_0c0c84d8;
P_0c0c84d8: /* original 7f04, guest PC 0x0c0c84d8 */
if(!s->budget--) { s->failed_pc=0x0c0c84d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c84da;
P_0c0c84da: /* original d023, guest PC 0x0c0c84da */
if(!s->budget--) { s->failed_pc=0x0c0c84dau; return 0; }
r[0]=read(ram,0x0c0c8568u,4);
goto P_0c0c84dc;
P_0c0c84dc: /* original 65d3, guest PC 0x0c0c84dc */
if(!s->budget--) { s->failed_pc=0x0c0c84dcu; return 0; }
r[5]=r[13];
goto P_0c0c84de;
P_0c0c84de: /* original 52f1, guest PC 0x0c0c84de */
if(!s->budget--) { s->failed_pc=0x0c0c84deu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c84e0;
P_0c0c84e0: /* original 7558, guest PC 0x0c0c84e0 */
if(!s->budget--) { s->failed_pc=0x0c0c84e0u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c84e2;
P_0c0c84e2: /* original 032d, guest PC 0x0c0c84e2 */
if(!s->budget--) { s->failed_pc=0x0c0c84e2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c84e4;
P_0c0c84e4: /* original 9038, guest PC 0x0c0c84e4 */
if(!s->budget--) { s->failed_pc=0x0c0c84e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c84e6;
P_0c0c84e6: /* original 0e35, guest PC 0x0c0c84e6 */
if(!s->budget--) { s->failed_pc=0x0c0c84e6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c84e8;
P_0c0c84e8: /* original e307, guest PC 0x0c0c84e8 */
if(!s->budget--) { s->failed_pc=0x0c0c84e8u; return 0; }
r[3]=0x00000007u;
goto P_0c0c84ea;
P_0c0c84ea: /* original 0aed, guest PC 0x0c0c84ea */
if(!s->budget--) { s->failed_pc=0x0c0c84eau; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c84ec;
P_0c0c84ec: /* original 7002, guest PC 0x0c0c84ec */
if(!s->budget--) { s->failed_pc=0x0c0c84ecu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c84ee;
P_0c0c84ee: /* original 0e34, guest PC 0x0c0c84ee */
if(!s->budget--) { s->failed_pc=0x0c0c84eeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c84f0;
P_0c0c84f0: /* original d31e, guest PC 0x0c0c84f0 */
if(!s->budget--) { s->failed_pc=0x0c0c84f0u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c84f2;
P_0c0c84f2: /* original 430b, guest PC 0x0c0c84f2 */
if(!s->budget--) { s->failed_pc=0x0c0c84f2u; return 0; }
target=r[3];
r[16]=0x0c0c84f6u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84f6u) { target=s->pc; goto dispatch; }
goto P_0c0c84f6;
P_0c0c84f4: /* original 64a3, guest PC 0x0c0c84f4 */
if(!s->budget--) { s->failed_pc=0x0c0c84f4u; return 0; }
r[4]=r[10];
goto P_0c0c84f6;
P_0c0c84f6: /* original d21b, guest PC 0x0c0c84f6 */
if(!s->budget--) { s->failed_pc=0x0c0c84f6u; return 0; }
r[2]=read(ram,0x0c0c8564u,4);
goto P_0c0c84f8;
P_0c0c84f8: /* original 420b, guest PC 0x0c0c84f8 */
if(!s->budget--) { s->failed_pc=0x0c0c84f8u; return 0; }
target=r[2];
r[16]=0x0c0c84fcu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c84fcu) { target=s->pc; goto dispatch; }
goto P_0c0c84fc;
P_0c0c84fa: /* original 64a3, guest PC 0x0c0c84fa */
if(!s->budget--) { s->failed_pc=0x0c0c84fau; return 0; }
r[4]=r[10];
goto P_0c0c84fc;
P_0c0c84fc: /* original 600d, guest PC 0x0c0c84fc */
if(!s->budget--) { s->failed_pc=0x0c0c84fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c84fe;
P_0c0c84fe: /* original 2008, guest PC 0x0c0c84fe */
if(!s->budget--) { s->failed_pc=0x0c0c84feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8500;
P_0c0c8500: /* original 896f, guest PC 0x0c0c8500 */
if(!s->budget--) { s->failed_pc=0x0c0c8500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8502;
P_0c0c8502: /* original 66d3, guest PC 0x0c0c8502 */
if(!s->budget--) { s->failed_pc=0x0c0c8502u; return 0; }
r[6]=r[13];
goto P_0c0c8504;
P_0c0c8504: /* original 2fc6, guest PC 0x0c0c8504 */
if(!s->budget--) { s->failed_pc=0x0c0c8504u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8506;
P_0c0c8506: /* original 9429, guest PC 0x0c0c8506 */
if(!s->budget--) { s->failed_pc=0x0c0c8506u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855cu,2);
goto P_0c0c8508;
P_0c0c8508: /* original 7658, guest PC 0x0c0c8508 */
if(!s->budget--) { s->failed_pc=0x0c0c8508u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c850a;
P_0c0c850a: /* original d719, guest PC 0x0c0c850a */
if(!s->budget--) { s->failed_pc=0x0c0c850au; return 0; }
r[7]=read(ram,0x0c0c8570u,4);
goto P_0c0c850c;
P_0c0c850c: /* original 4b0b, guest PC 0x0c0c850c */
if(!s->budget--) { s->failed_pc=0x0c0c850cu; return 0; }
target=r[11];
r[16]=0x0c0c8510u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8510u) { target=s->pc; goto dispatch; }
goto P_0c0c8510;
P_0c0c850e: /* original 65a3, guest PC 0x0c0c850e */
if(!s->budget--) { s->failed_pc=0x0c0c850eu; return 0; }
r[5]=r[10];
goto P_0c0c8510;
P_0c0c8510: /* original a067, guest PC 0x0c0c8510 */
if(!s->budget--) { s->failed_pc=0x0c0c8510u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8512: /* original 7f04, guest PC 0x0c0c8512 */
if(!s->budget--) { s->failed_pc=0x0c0c8512u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8514;
P_0c0c8514: /* original 9023, guest PC 0x0c0c8514 */
if(!s->budget--) { s->failed_pc=0x0c0c8514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855eu,2);
goto P_0c0c8516;
P_0c0c8516: /* original 04ec, guest PC 0x0c0c8516 */
if(!s->budget--) { s->failed_pc=0x0c0c8516u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c8518;
P_0c0c8518: /* original 4415, guest PC 0x0c0c8518 */
if(!s->budget--) { s->failed_pc=0x0c0c8518u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c851a;
P_0c0c851a: /* original 892b, guest PC 0x0c0c851a */
if(!s->budget--) { s->failed_pc=0x0c0c851au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8574; }
goto P_0c0c851c;
P_0c0c851c: /* original 6a93, guest PC 0x0c0c851c */
if(!s->budget--) { s->failed_pc=0x0c0c851cu; return 0; }
r[10]=r[9];
goto P_0c0c851e;
P_0c0c851e: /* original 7a44, guest PC 0x0c0c851e */
if(!s->budget--) { s->failed_pc=0x0c0c851eu; return 0; }
r[10]+=0x00000044u;
goto P_0c0c8520;
P_0c0c8520: /* original 62a2, guest PC 0x0c0c8520 */
if(!s->budget--) { s->failed_pc=0x0c0c8520u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c8522;
P_0c0c8522: /* original 2228, guest PC 0x0c0c8522 */
if(!s->budget--) { s->failed_pc=0x0c0c8522u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c8524;
P_0c0c8524: /* original 8904, guest PC 0x0c0c8524 */
if(!s->budget--) { s->failed_pc=0x0c0c8524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8530; }
goto P_0c0c8526;
P_0c0c8526: /* original d311, guest PC 0x0c0c8526 */
if(!s->budget--) { s->failed_pc=0x0c0c8526u; return 0; }
r[3]=read(ram,0x0c0c856cu,4);
goto P_0c0c8528;
P_0c0c8528: /* original 65d3, guest PC 0x0c0c8528 */
if(!s->budget--) { s->failed_pc=0x0c0c8528u; return 0; }
r[5]=r[13];
goto P_0c0c852a;
P_0c0c852a: /* original 7558, guest PC 0x0c0c852a */
if(!s->budget--) { s->failed_pc=0x0c0c852au; return 0; }
r[5]+=0x00000058u;
goto P_0c0c852c;
P_0c0c852c: /* original 430b, guest PC 0x0c0c852c */
if(!s->budget--) { s->failed_pc=0x0c0c852cu; return 0; }
target=r[3];
r[16]=0x0c0c8530u;
tmp=read(ram,r[10],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8530u) { target=s->pc; goto dispatch; }
goto P_0c0c8530;
P_0c0c852e: /* original 64a2, guest PC 0x0c0c852e */
if(!s->budget--) { s->failed_pc=0x0c0c852eu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c8530;
P_0c0c8530: /* original 9012, guest PC 0x0c0c8530 */
if(!s->budget--) { s->failed_pc=0x0c0c8530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8532;
P_0c0c8532: /* original 02ed, guest PC 0x0c0c8532 */
if(!s->budget--) { s->failed_pc=0x0c0c8532u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8534;
P_0c0c8534: /* original 2a22, guest PC 0x0c0c8534 */
if(!s->budget--) { s->failed_pc=0x0c0c8534u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c0c8536;
P_0c0c8536: /* original d30b, guest PC 0x0c0c8536 */
if(!s->budget--) { s->failed_pc=0x0c0c8536u; return 0; }
r[3]=read(ram,0x0c0c8564u,4);
goto P_0c0c8538;
P_0c0c8538: /* original 430b, guest PC 0x0c0c8538 */
if(!s->budget--) { s->failed_pc=0x0c0c8538u; return 0; }
target=r[3];
r[16]=0x0c0c853cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c853cu) { target=s->pc; goto dispatch; }
goto P_0c0c853c;
P_0c0c853a: /* original 04ed, guest PC 0x0c0c853a */
if(!s->budget--) { s->failed_pc=0x0c0c853au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c853c;
P_0c0c853c: /* original 600d, guest PC 0x0c0c853c */
if(!s->budget--) { s->failed_pc=0x0c0c853cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c853e;
P_0c0c853e: /* original 2008, guest PC 0x0c0c853e */
if(!s->budget--) { s->failed_pc=0x0c0c853eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8540;
P_0c0c8540: /* original 894f, guest PC 0x0c0c8540 */
if(!s->budget--) { s->failed_pc=0x0c0c8540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c8542;
P_0c0c8542: /* original 66d3, guest PC 0x0c0c8542 */
if(!s->budget--) { s->failed_pc=0x0c0c8542u; return 0; }
r[6]=r[13];
goto P_0c0c8544;
P_0c0c8544: /* original 2fc6, guest PC 0x0c0c8544 */
if(!s->budget--) { s->failed_pc=0x0c0c8544u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8546;
P_0c0c8546: /* original 9007, guest PC 0x0c0c8546 */
if(!s->budget--) { s->failed_pc=0x0c0c8546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8558u,2);
goto P_0c0c8548;
P_0c0c8548: /* original e700, guest PC 0x0c0c8548 */
if(!s->budget--) { s->failed_pc=0x0c0c8548u; return 0; }
r[7]=0x00000000u;
goto P_0c0c854a;
P_0c0c854a: /* original 9406, guest PC 0x0c0c854a */
if(!s->budget--) { s->failed_pc=0x0c0c854au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c855au,2);
goto P_0c0c854c;
P_0c0c854c: /* original 7658, guest PC 0x0c0c854c */
if(!s->budget--) { s->failed_pc=0x0c0c854cu; return 0; }
r[6]+=0x00000058u;
goto P_0c0c854e;
P_0c0c854e: /* original 4b0b, guest PC 0x0c0c854e */
if(!s->budget--) { s->failed_pc=0x0c0c854eu; return 0; }
target=r[11];
r[16]=0x0c0c8552u;
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8552u) { target=s->pc; goto dispatch; }
goto P_0c0c8552;
P_0c0c8550: /* original 05ed, guest PC 0x0c0c8550 */
if(!s->budget--) { s->failed_pc=0x0c0c8550u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8552;
P_0c0c8552: /* original a046, guest PC 0x0c0c8552 */
if(!s->budget--) { s->failed_pc=0x0c0c8552u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c85e2;
P_0c0c8554: /* original 7f04, guest PC 0x0c0c8554 */
if(!s->budget--) { s->failed_pc=0x0c0c8554u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0c8556u,s,ram);
P_0c0c8574: /* original e306, guest PC 0x0c0c8574 */
if(!s->budget--) { s->failed_pc=0x0c0c8574u; return 0; }
r[3]=0x00000006u;
goto P_0c0c8576;
P_0c0c8576: /* original 74ff, guest PC 0x0c0c8576 */
if(!s->budget--) { s->failed_pc=0x0c0c8576u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c8578;
P_0c0c8578: /* original 3348, guest PC 0x0c0c8578 */
if(!s->budget--) { s->failed_pc=0x0c0c8578u; return 0; }
r[3]-=r[4];
goto P_0c0c857a;
P_0c0c857a: /* original 0e44, guest PC 0x0c0c857a */
if(!s->budget--) { s->failed_pc=0x0c0c857au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c857c;
P_0c0c857c: /* original 6433, guest PC 0x0c0c857c */
if(!s->budget--) { s->failed_pc=0x0c0c857cu; return 0; }
r[4]=r[3];
goto P_0c0c857e;
P_0c0c857e: /* original 4408, guest PC 0x0c0c857e */
if(!s->budget--) { s->failed_pc=0x0c0c857eu; return 0; }
r[4]<<=2;
goto P_0c0c8580;
P_0c0c8580: /* original e91b, guest PC 0x0c0c8580 */
if(!s->budget--) { s->failed_pc=0x0c0c8580u; return 0; }
r[9]=0x0000001bu;
goto P_0c0c8582;
P_0c0c8582: /* original 6543, guest PC 0x0c0c8582 */
if(!s->budget--) { s->failed_pc=0x0c0c8582u; return 0; }
r[5]=r[4];
goto P_0c0c8584;
P_0c0c8584: /* original 3948, guest PC 0x0c0c8584 */
if(!s->budget--) { s->failed_pc=0x0c0c8584u; return 0; }
r[9]-=r[4];
goto P_0c0c8586;
P_0c0c8586: /* original d72a, guest PC 0x0c0c8586 */
if(!s->budget--) { s->failed_pc=0x0c0c8586u; return 0; }
r[7]=read(ram,0x0c0c8630u,4);
goto P_0c0c8588;
P_0c0c8588: /* original 7504, guest PC 0x0c0c8588 */
if(!s->budget--) { s->failed_pc=0x0c0c8588u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c858a;
P_0c0c858a: /* original 6693, guest PC 0x0c0c858a */
if(!s->budget--) { s->failed_pc=0x0c0c858au; return 0; }
r[6]=r[9];
goto P_0c0c858c;
P_0c0c858c: /* original 70fe, guest PC 0x0c0c858c */
if(!s->budget--) { s->failed_pc=0x0c0c858cu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0c858e;
P_0c0c858e: /* original 0aed, guest PC 0x0c0c858e */
if(!s->budget--) { s->failed_pc=0x0c0c858eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c8590;
P_0c0c8590: /* original 4518, guest PC 0x0c0c8590 */
if(!s->budget--) { s->failed_pc=0x0c0c8590u; return 0; }
r[5]<<=8;
goto P_0c0c8592;
P_0c0c8592: /* original 4628, guest PC 0x0c0c8592 */
if(!s->budget--) { s->failed_pc=0x0c0c8592u; return 0; }
r[6]<<=16;
goto P_0c0c8594;
P_0c0c8594: /* original 6053, guest PC 0x0c0c8594 */
if(!s->budget--) { s->failed_pc=0x0c0c8594u; return 0; }
r[0]=r[5];
goto P_0c0c8596;
P_0c0c8596: /* original 4618, guest PC 0x0c0c8596 */
if(!s->budget--) { s->failed_pc=0x0c0c8596u; return 0; }
r[6]<<=8;
goto P_0c0c8598;
P_0c0c8598: /* original 206b, guest PC 0x0c0c8598 */
if(!s->budget--) { s->failed_pc=0x0c0c8598u; return 0; }
r[0]|=r[6];
goto P_0c0c859a;
P_0c0c859a: /* original cb18, guest PC 0x0c0c859a */
if(!s->budget--) { s->failed_pc=0x0c0c859au; return 0; }
r[0]|=24u;
goto P_0c0c859c;
P_0c0c859c: /* original 2f02, guest PC 0x0c0c859c */
if(!s->budget--) { s->failed_pc=0x0c0c859cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c859e;
P_0c0c859e: /* original 6053, guest PC 0x0c0c859e */
if(!s->budget--) { s->failed_pc=0x0c0c859eu; return 0; }
r[0]=r[5];
goto P_0c0c85a0;
P_0c0c85a0: /* original 207b, guest PC 0x0c0c85a0 */
if(!s->budget--) { s->failed_pc=0x0c0c85a0u; return 0; }
r[0]|=r[7];
goto P_0c0c85a2;
P_0c0c85a2: /* original cb18, guest PC 0x0c0c85a2 */
if(!s->budget--) { s->failed_pc=0x0c0c85a2u; return 0; }
r[0]|=24u;
goto P_0c0c85a4;
P_0c0c85a4: /* original 1f01, guest PC 0x0c0c85a4 */
if(!s->budget--) { s->failed_pc=0x0c0c85a4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c85a6;
P_0c0c85a6: /* original d323, guest PC 0x0c0c85a6 */
if(!s->budget--) { s->failed_pc=0x0c0c85a6u; return 0; }
r[3]=read(ram,0x0c0c8634u,4);
goto P_0c0c85a8;
P_0c0c85a8: /* original 430b, guest PC 0x0c0c85a8 */
if(!s->budget--) { s->failed_pc=0x0c0c85a8u; return 0; }
target=r[3];
r[16]=0x0c0c85acu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85acu) { target=s->pc; goto dispatch; }
goto P_0c0c85ac;
P_0c0c85aa: /* original 64a3, guest PC 0x0c0c85aa */
if(!s->budget--) { s->failed_pc=0x0c0c85aau; return 0; }
r[4]=r[10];
goto P_0c0c85ac;
P_0c0c85ac: /* original 600d, guest PC 0x0c0c85ac */
if(!s->budget--) { s->failed_pc=0x0c0c85acu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c85ae;
P_0c0c85ae: /* original 2008, guest PC 0x0c0c85ae */
if(!s->budget--) { s->failed_pc=0x0c0c85aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c85b0;
P_0c0c85b0: /* original 8917, guest PC 0x0c0c85b0 */
if(!s->budget--) { s->failed_pc=0x0c0c85b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85e2; }
goto P_0c0c85b2;
P_0c0c85b2: /* original d321, guest PC 0x0c0c85b2 */
if(!s->budget--) { s->failed_pc=0x0c0c85b2u; return 0; }
r[3]=read(ram,0x0c0c8638u,4);
goto P_0c0c85b4;
P_0c0c85b4: /* original 65d3, guest PC 0x0c0c85b4 */
if(!s->budget--) { s->failed_pc=0x0c0c85b4u; return 0; }
r[5]=r[13];
goto P_0c0c85b6;
P_0c0c85b6: /* original 7558, guest PC 0x0c0c85b6 */
if(!s->budget--) { s->failed_pc=0x0c0c85b6u; return 0; }
r[5]+=0x00000058u;
goto P_0c0c85b8;
P_0c0c85b8: /* original 430b, guest PC 0x0c0c85b8 */
if(!s->budget--) { s->failed_pc=0x0c0c85b8u; return 0; }
target=r[3];
r[16]=0x0c0c85bcu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85bcu) { target=s->pc; goto dispatch; }
goto P_0c0c85bc;
P_0c0c85ba: /* original 64a3, guest PC 0x0c0c85ba */
if(!s->budget--) { s->failed_pc=0x0c0c85bau; return 0; }
r[4]=r[10];
goto P_0c0c85bc;
P_0c0c85bc: /* original 9232, guest PC 0x0c0c85bc */
if(!s->budget--) { s->failed_pc=0x0c0c85bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8624u,2);
goto P_0c0c85be;
P_0c0c85be: /* original 4900, guest PC 0x0c0c85be */
if(!s->budget--) { s->failed_pc=0x0c0c85beu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0c85c0;
P_0c0c85c0: /* original 66d3, guest PC 0x0c0c85c0 */
if(!s->budget--) { s->failed_pc=0x0c0c85c0u; return 0; }
r[6]=r[13];
goto P_0c0c85c2;
P_0c0c85c2: /* original 65a3, guest PC 0x0c0c85c2 */
if(!s->budget--) { s->failed_pc=0x0c0c85c2u; return 0; }
r[5]=r[10];
goto P_0c0c85c4;
P_0c0c85c4: /* original 292b, guest PC 0x0c0c85c4 */
if(!s->budget--) { s->failed_pc=0x0c0c85c4u; return 0; }
r[9]|=r[2];
goto P_0c0c85c6;
P_0c0c85c6: /* original 1f92, guest PC 0x0c0c85c6 */
if(!s->budget--) { s->failed_pc=0x0c0c85c6u; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0c85c8;
P_0c0c85c8: /* original 7658, guest PC 0x0c0c85c8 */
if(!s->budget--) { s->failed_pc=0x0c0c85c8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85ca;
P_0c0c85ca: /* original 2fc6, guest PC 0x0c0c85ca */
if(!s->budget--) { s->failed_pc=0x0c0c85cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85cc;
P_0c0c85cc: /* original 57f1, guest PC 0x0c0c85cc */
if(!s->budget--) { s->failed_pc=0x0c0c85ccu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0c85ce;
P_0c0c85ce: /* original 4b0b, guest PC 0x0c0c85ce */
if(!s->budget--) { s->failed_pc=0x0c0c85ceu; return 0; }
target=r[11];
r[16]=0x0c0c85d2u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85d2u) { target=s->pc; goto dispatch; }
goto P_0c0c85d2;
P_0c0c85d0: /* original 54f3, guest PC 0x0c0c85d0 */
if(!s->budget--) { s->failed_pc=0x0c0c85d0u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0c85d2;
P_0c0c85d2: /* original 2fc6, guest PC 0x0c0c85d2 */
if(!s->budget--) { s->failed_pc=0x0c0c85d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85d4;
P_0c0c85d4: /* original 66d3, guest PC 0x0c0c85d4 */
if(!s->budget--) { s->failed_pc=0x0c0c85d4u; return 0; }
r[6]=r[13];
goto P_0c0c85d6;
P_0c0c85d6: /* original 9426, guest PC 0x0c0c85d6 */
if(!s->budget--) { s->failed_pc=0x0c0c85d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8626u,2);
goto P_0c0c85d8;
P_0c0c85d8: /* original 7658, guest PC 0x0c0c85d8 */
if(!s->budget--) { s->failed_pc=0x0c0c85d8u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c85da;
P_0c0c85da: /* original 57f3, guest PC 0x0c0c85da */
if(!s->budget--) { s->failed_pc=0x0c0c85dau; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0c85dc;
P_0c0c85dc: /* original 4b0b, guest PC 0x0c0c85dc */
if(!s->budget--) { s->failed_pc=0x0c0c85dcu; return 0; }
target=r[11];
r[16]=0x0c0c85e0u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c85e0u) { target=s->pc; goto dispatch; }
goto P_0c0c85e0;
P_0c0c85de: /* original 65a3, guest PC 0x0c0c85de */
if(!s->budget--) { s->failed_pc=0x0c0c85deu; return 0; }
r[5]=r[10];
goto P_0c0c85e0;
P_0c0c85e0: /* original 7f08, guest PC 0x0c0c85e0 */
if(!s->budget--) { s->failed_pc=0x0c0c85e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c85e2;
P_0c0c85e2: /* original 9022, guest PC 0x0c0c85e2 */
if(!s->budget--) { s->failed_pc=0x0c0c85e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862au,2);
goto P_0c0c85e4;
P_0c0c85e4: /* original 9420, guest PC 0x0c0c85e4 */
if(!s->budget--) { s->failed_pc=0x0c0c85e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85e6;
P_0c0c85e6: /* original 00ec, guest PC 0x0c0c85e6 */
if(!s->budget--) { s->failed_pc=0x0c0c85e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c85e8;
P_0c0c85e8: /* original 600c, guest PC 0x0c0c85e8 */
if(!s->budget--) { s->failed_pc=0x0c0c85e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c85ea;
P_0c0c85ea: /* original 8801, guest PC 0x0c0c85ea */
if(!s->budget--) { s->failed_pc=0x0c0c85eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c85ec;
P_0c0c85ec: /* original 8903, guest PC 0x0c0c85ec */
if(!s->budget--) { s->failed_pc=0x0c0c85ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c85f6; }
goto P_0c0c85ee;
P_0c0c85ee: /* original 50f4, guest PC 0x0c0c85ee */
if(!s->budget--) { s->failed_pc=0x0c0c85eeu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c85f0;
P_0c0c85f0: /* original 6002, guest PC 0x0c0c85f0 */
if(!s->budget--) { s->failed_pc=0x0c0c85f0u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0c85f2;
P_0c0c85f2: /* original c810, guest PC 0x0c0c85f2 */
if(!s->budget--) { s->failed_pc=0x0c0c85f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c85f4;
P_0c0c85f4: /* original 8b07, guest PC 0x0c0c85f4 */
if(!s->budget--) { s->failed_pc=0x0c0c85f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8606; }
goto P_0c0c85f6;
P_0c0c85f6: /* original 2fc6, guest PC 0x0c0c85f6 */
if(!s->budget--) { s->failed_pc=0x0c0c85f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c85f8;
P_0c0c85f8: /* original e700, guest PC 0x0c0c85f8 */
if(!s->budget--) { s->failed_pc=0x0c0c85f8u; return 0; }
r[7]=0x00000000u;
goto P_0c0c85fa;
P_0c0c85fa: /* original 9517, guest PC 0x0c0c85fa */
if(!s->budget--) { s->failed_pc=0x0c0c85fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c85fc;
P_0c0c85fc: /* original 9414, guest PC 0x0c0c85fc */
if(!s->budget--) { s->failed_pc=0x0c0c85fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8628u,2);
goto P_0c0c85fe;
P_0c0c85fe: /* original 4b0b, guest PC 0x0c0c85fe */
if(!s->budget--) { s->failed_pc=0x0c0c85feu; return 0; }
target=r[11];
r[16]=0x0c0c8602u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8602u) { target=s->pc; goto dispatch; }
goto P_0c0c8602;
P_0c0c8600: /* original 66d3, guest PC 0x0c0c8600 */
if(!s->budget--) { s->failed_pc=0x0c0c8600u; return 0; }
r[6]=r[13];
goto P_0c0c8602;
P_0c0c8602: /* original a005, guest PC 0x0c0c8602 */
if(!s->budget--) { s->failed_pc=0x0c0c8602u; return 0; }
goto P_0c0c8610;
P_0c0c8604: /* original 0009, guest PC 0x0c0c8604 */
if(!s->budget--) { s->failed_pc=0x0c0c8604u; return 0; }
goto P_0c0c8606;
P_0c0c8606: /* original e700, guest PC 0x0c0c8606 */
if(!s->budget--) { s->failed_pc=0x0c0c8606u; return 0; }
r[7]=0x00000000u;
goto P_0c0c8608;
P_0c0c8608: /* original 2fc6, guest PC 0x0c0c8608 */
if(!s->budget--) { s->failed_pc=0x0c0c8608u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c860a;
P_0c0c860a: /* original 950f, guest PC 0x0c0c860a */
if(!s->budget--) { s->failed_pc=0x0c0c860au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c862cu,2);
goto P_0c0c860c;
P_0c0c860c: /* original 480b, guest PC 0x0c0c860c */
if(!s->budget--) { s->failed_pc=0x0c0c860cu; return 0; }
target=r[8];
r[16]=0x0c0c8610u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8610u) { target=s->pc; goto dispatch; }
goto P_0c0c8610;
P_0c0c860e: /* original 66d3, guest PC 0x0c0c860e */
if(!s->budget--) { s->failed_pc=0x0c0c860eu; return 0; }
r[6]=r[13];
goto P_0c0c8610;
P_0c0c8610: /* original 7f1c, guest PC 0x0c0c8610 */
if(!s->budget--) { s->failed_pc=0x0c0c8610u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0c8612;
P_0c0c8612: /* original 4f26, guest PC 0x0c0c8612 */
if(!s->budget--) { s->failed_pc=0x0c0c8612u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8614;
P_0c0c8614: /* original 68f6, guest PC 0x0c0c8614 */
if(!s->budget--) { s->failed_pc=0x0c0c8614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c8616;
P_0c0c8616: /* original 69f6, guest PC 0x0c0c8616 */
if(!s->budget--) { s->failed_pc=0x0c0c8616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c8618;
P_0c0c8618: /* original 6af6, guest PC 0x0c0c8618 */
if(!s->budget--) { s->failed_pc=0x0c0c8618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c861a;
P_0c0c861a: /* original 6bf6, guest PC 0x0c0c861a */
if(!s->budget--) { s->failed_pc=0x0c0c861au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c861c;
P_0c0c861c: /* original 6cf6, guest PC 0x0c0c861c */
if(!s->budget--) { s->failed_pc=0x0c0c861cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c861e;
P_0c0c861e: /* original 6df6, guest PC 0x0c0c861e */
if(!s->budget--) { s->failed_pc=0x0c0c861eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8620;
P_0c0c8620: /* original 000b, guest PC 0x0c0c8620 */
if(!s->budget--) { s->failed_pc=0x0c0c8620u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8622: /* original 6ef6, guest PC 0x0c0c8622 */
if(!s->budget--) { s->failed_pc=0x0c0c8622u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8624u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03b8f4u,0x0c03b8f6u,0x0c03b8f8u,0x0c03b8fau,0x0c03b8fcu,0x0c03b8feu,0x0c03b900u,0x0c03b902u,0x0c03b904u,0x0c03b906u,0x0c03b908u,0x0c03b90au,0x0c03b90cu,0x0c03b90eu,0x0c03b910u,0x0c03b912u,
0x0c03b914u,0x0c03b916u,0x0c03b918u,0x0c03b91au,0x0c03b91cu,0x0c03b91eu,0x0c03b920u,0x0c03b922u,0x0c03b924u,0x0c03b926u,0x0c03b928u,0x0c03b92au,0x0c03b92cu,0x0c03b92eu,0x0c03b930u,0x0c03b932u,
0x0c03b934u,0x0c03b936u,0x0c03b938u,0x0c03b93au,0x0c03b93cu,0x0c03b93eu,0x0c03b940u,0x0c03b942u,0x0c03b944u,0x0c03b946u,0x0c03b948u,0x0c03b94au,0x0c03b94cu,0x0c03b94eu,0x0c03b950u,0x0c03b952u,
0x0c03b954u,0x0c03b956u,0x0c03b958u,0x0c03b95au,0x0c03b95cu,0x0c03b95eu,0x0c03b960u,0x0c03b962u,0x0c03b964u,0x0c03b966u,0x0c03b968u,0x0c03b96au,0x0c03b96cu,0x0c03b96eu,0x0c03b970u,0x0c03b972u,
0x0c03b974u,0x0c03b976u,0x0c03b978u,0x0c03b97au,0x0c03b97cu,0x0c03b97eu,0x0c03b980u,0x0c03b982u,0x0c03b984u,0x0c03b986u,0x0c03b988u,0x0c03b98au,0x0c03b98cu,0x0c03b98eu,0x0c03b990u,0x0c03b992u,
0x0c03b994u,0x0c03b996u,0x0c03b998u,0x0c03b99au,0x0c03b99cu,0x0c03b99eu,0x0c03b9a0u,0x0c03b9a2u,0x0c03b9a4u,0x0c03b9a6u,0x0c03b9a8u,0x0c03b9aau,0x0c03b9acu,0x0c03b9aeu,0x0c03b9b0u,0x0c03b9b2u,
0x0c03b9b4u,0x0c03b9b6u,0x0c03b9b8u,0x0c03b9bau,0x0c03b9bcu,0x0c03b9beu,0x0c03b9c0u,0x0c03b9c2u,0x0c03b9c4u,0x0c03b9c6u,0x0c03b9c8u,0x0c03b9cau,0x0c03b9ccu,0x0c03b9ceu,0x0c03b9d0u,0x0c03b9d2u,
0x0c03b9d4u,0x0c03b9d6u,0x0c03b9d8u,0x0c03b9dau,0x0c03b9dcu,0x0c03b9deu,0x0c03b9e0u,0x0c03b9e2u,0x0c03b9e4u,0x0c03b9e6u,0x0c03b9e8u,0x0c03b9eau,0x0c03b9ecu,0x0c03b9eeu,0x0c03b9f0u,0x0c03b9f2u,
0x0c03b9f4u,0x0c03b9f6u,0x0c03b9f8u,0x0c03b9fau,0x0c03b9fcu,0x0c03b9feu,0x0c03ba00u,0x0c03ba02u,0x0c03ba04u,0x0c03ba06u,0x0c03ba08u,0x0c03ba0au,0x0c03ba0cu,0x0c03ba0eu,0x0c03ba10u,0x0c03ba12u,
0x0c03ba14u,0x0c03ba16u,0x0c03ba18u,0x0c03ba1au,0x0c03ba1cu,0x0c03ba1eu,0x0c03ba20u,0x0c03ba22u,0x0c03ba24u,0x0c03ba26u,0x0c03ba28u,0x0c03ba2au,0x0c03ba2cu,0x0c03ba2eu,0x0c03ba30u,0x0c03ba32u,
0x0c054b84u,0x0c054b86u,0x0c054b88u,0x0c054b8au,0x0c054b8cu,0x0c054b8eu,0x0c054b90u,0x0c054b92u,0x0c054b94u,0x0c054b96u,0x0c054b98u,0x0c054b9au,0x0c054b9cu,0x0c054b9eu,0x0c054ba0u,0x0c054ba2u,
0x0c054ba4u,0x0c054ba6u,0x0c054ba8u,0x0c054baau,0x0c054bacu,0x0c054baeu,0x0c054bb0u,0x0c054bb2u,0x0c054bb4u,0x0c054bb6u,0x0c054bb8u,0x0c054bbau,0x0c054bbcu,0x0c054bbeu,0x0c054bc0u,0x0c054bc2u,
0x0c054bc4u,0x0c054bc6u,0x0c054bc8u,0x0c054bcau,0x0c054bccu,0x0c054bceu,0x0c054bd0u,0x0c054bd2u,0x0c054bd4u,0x0c054bd6u,0x0c054bd8u,0x0c054bdau,0x0c054bdcu,0x0c054bdeu,0x0c054be0u,0x0c054be2u,
0x0c054be4u,0x0c054be6u,0x0c054be8u,0x0c054beau,0x0c054becu,0x0c054beeu,0x0c054bf0u,0x0c054bf2u,0x0c054bf4u,0x0c054bf6u,0x0c06d638u,0x0c06d63au,0x0c06d63cu,0x0c06d63eu,0x0c06d640u,0x0c06d642u,
0x0c06d644u,0x0c06d646u,0x0c06d648u,0x0c06d64au,0x0c06d64cu,0x0c06d64eu,0x0c06d650u,0x0c06d652u,0x0c06d654u,0x0c06d656u,0x0c06d658u,0x0c06d65au,0x0c06d65cu,0x0c06d65eu,0x0c06d660u,0x0c06d662u,
0x0c06d664u,0x0c06d666u,0x0c06d668u,0x0c06d66au,0x0c06d66cu,0x0c06d66eu,0x0c06d670u,0x0c06d672u,0x0c06d674u,0x0c06d676u,0x0c06d678u,0x0c06d67au,0x0c06d67cu,0x0c06d67eu,0x0c06d680u,0x0c06d682u,
0x0c06d684u,0x0c06d686u,0x0c06d688u,0x0c06d68au,0x0c06d68cu,0x0c06d68eu,0x0c06d690u,0x0c06d692u,0x0c06d694u,0x0c06d696u,0x0c06d698u,0x0c06d69au,0x0c06d69cu,0x0c06d69eu,0x0c06d6a0u,0x0c06d6a2u,
0x0c06d6a4u,0x0c06d6a6u,0x0c06d6a8u,0x0c06d6aau,0x0c06d6acu,0x0c06d6aeu,0x0c06d6b0u,0x0c06d6b2u,0x0c06d6b4u,0x0c06d6b6u,0x0c06d6b8u,0x0c06d6bau,0x0c06d6bcu,0x0c06d6beu,0x0c06d6c0u,0x0c06d6c2u,
0x0c06d6c4u,0x0c06d6c6u,0x0c06d6c8u,0x0c06d6cau,0x0c06d6ccu,0x0c06d6ceu,0x0c06d6d0u,0x0c06d6d2u,0x0c06d6d4u,0x0c06d6d6u,0x0c06d6d8u,0x0c06d6dau,0x0c06d6dcu,0x0c06d6deu,0x0c06d6e0u,0x0c06d6e2u,
0x0c06d6e4u,0x0c06d6e6u,0x0c06d6e8u,0x0c06d6eau,0x0c06d6ecu,0x0c06d6eeu,0x0c06d6f0u,0x0c06d6f2u,0x0c06d6f4u,0x0c06d6f6u,0x0c06d6f8u,0x0c06d6fau,0x0c06d6fcu,0x0c06d6feu,0x0c06d700u,0x0c06d702u,
0x0c06d704u,0x0c06d706u,0x0c06d708u,0x0c07e104u,0x0c07e106u,0x0c07e108u,0x0c07e10au,0x0c07e10cu,0x0c07e10eu,0x0c07e110u,0x0c07e112u,0x0c07e114u,0x0c07e116u,0x0c07e118u,0x0c07e11au,0x0c07e11cu,
0x0c07e11eu,0x0c07e120u,0x0c07e122u,0x0c07e124u,0x0c07e126u,0x0c07e128u,0x0c07e12au,0x0c07e12cu,0x0c07e12eu,0x0c07e130u,0x0c07e132u,0x0c07e134u,0x0c07e136u,0x0c07e138u,0x0c07e13au,0x0c07e13cu,
0x0c07e13eu,0x0c07e140u,0x0c07e142u,0x0c07e144u,0x0c07e146u,0x0c07e148u,0x0c07e14au,0x0c07e14cu,0x0c07e14eu,0x0c07e150u,0x0c07e152u,0x0c07e154u,0x0c07e156u,0x0c07e158u,0x0c07e15au,0x0c07e15cu,
0x0c07e15eu,0x0c07e160u,0x0c07e162u,0x0c07e164u,0x0c07e166u,0x0c07e168u,0x0c07e16au,0x0c07e16cu,0x0c07e16eu,0x0c07e170u,0x0c07e172u,0x0c07e174u,0x0c07e176u,0x0c07e178u,0x0c07e17au,0x0c07e17cu,
0x0c07e17eu,0x0c07e180u,0x0c07e182u,0x0c07e184u,0x0c07e186u,0x0c07e188u,0x0c07e18au,0x0c07e18cu,0x0c07e18eu,0x0c07e190u,0x0c07e192u,0x0c07e194u,0x0c0806e4u,0x0c0806e6u,0x0c0806e8u,0x0c0806eau,
0x0c0806ecu,0x0c0806eeu,0x0c0806f0u,0x0c0806f2u,0x0c0806f4u,0x0c0806f6u,0x0c0806f8u,0x0c0806fau,0x0c0806fcu,0x0c0806feu,0x0c080700u,0x0c080702u,0x0c080704u,0x0c080706u,0x0c080708u,0x0c08070au,
0x0c08070cu,0x0c08070eu,0x0c080710u,0x0c080712u,0x0c080714u,0x0c080716u,0x0c080718u,0x0c08071au,0x0c08071cu,0x0c08071eu,0x0c080720u,0x0c080722u,0x0c080724u,0x0c080726u,0x0c080728u,0x0c08072au,
0x0c08072cu,0x0c08072eu,0x0c080730u,0x0c080732u,0x0c080734u,0x0c080736u,0x0c080738u,0x0c08073au,0x0c08073cu,0x0c08073eu,0x0c080740u,0x0c080742u,0x0c080744u,0x0c080746u,0x0c080748u,0x0c08074au,
0x0c08074cu,0x0c08074eu,0x0c080750u,0x0c080752u,0x0c080754u,0x0c080756u,0x0c080758u,0x0c08075au,0x0c08075cu,0x0c08075eu,0x0c080760u,0x0c080762u,0x0c080764u,0x0c080766u,0x0c080768u,0x0c08076au,
0x0c080d2cu,0x0c080d2eu,0x0c080d30u,0x0c080d32u,0x0c080d34u,0x0c080d36u,0x0c080d38u,0x0c080d3au,0x0c080d3cu,0x0c080d3eu,0x0c080d40u,0x0c080d42u,0x0c080d44u,0x0c080d46u,0x0c080d48u,0x0c080d4au,
0x0c080d4cu,0x0c080d4eu,0x0c080d50u,0x0c080d52u,0x0c080d54u,0x0c080d56u,0x0c080d58u,0x0c080d5au,0x0c080d5cu,0x0c080d5eu,0x0c080d60u,0x0c080d62u,0x0c080d64u,0x0c080d66u,0x0c080d68u,0x0c080d6au,
0x0c080d6cu,0x0c080d6eu,0x0c080d70u,0x0c080d72u,0x0c080d74u,0x0c080d76u,0x0c080d78u,0x0c080d7au,0x0c080d7cu,0x0c080d7eu,0x0c080d80u,0x0c080d82u,0x0c080d84u,0x0c080d86u,0x0c080d88u,0x0c080d8au,
0x0c080d8cu,0x0c080d8eu,0x0c080d90u,0x0c080d92u,0x0c080d94u,0x0c080d96u,0x0c080d98u,0x0c080d9au,0x0c080d9cu,0x0c080d9eu,0x0c080da0u,0x0c080da2u,0x0c080da4u,0x0c080da6u,0x0c080da8u,0x0c080daau,
0x0c080dacu,0x0c080daeu,0x0c080db0u,0x0c080db2u,0x0c080db4u,0x0c080db6u,0x0c080db8u,0x0c080dbau,0x0c080dbcu,0x0c080dbeu,0x0c080dc0u,0x0c080dc2u,0x0c080dc4u,0x0c080dc6u,0x0c080dc8u,0x0c080dcau,
0x0c080dccu,0x0c080dceu,0x0c080dd0u,0x0c080dd2u,0x0c080dd4u,0x0c080dd6u,0x0c080dd8u,0x0c080ddau,0x0c080ddcu,0x0c089c9cu,0x0c089c9eu,0x0c089ca0u,0x0c089ca2u,0x0c089ca4u,0x0c089ca6u,0x0c089ca8u,
0x0c089caau,0x0c089cacu,0x0c089caeu,0x0c089cb0u,0x0c089cb2u,0x0c089cb4u,0x0c089cb6u,0x0c089cb8u,0x0c089cbau,0x0c089cbcu,0x0c089cbeu,0x0c089cc0u,0x0c089cc2u,0x0c089cc4u,0x0c089cc6u,0x0c089cc8u,
0x0c089ccau,0x0c089cccu,0x0c089cceu,0x0c089cd0u,0x0c089cd2u,0x0c089cd4u,0x0c089cd6u,0x0c089cd8u,0x0c089cdau,0x0c089cdcu,0x0c089cdeu,0x0c089ce0u,0x0c089ce2u,0x0c089ce4u,0x0c089ce6u,0x0c089ce8u,
0x0c089ceau,0x0c089cecu,0x0c089ceeu,0x0c089cf0u,0x0c089cf2u,0x0c089cf4u,0x0c089cf6u,0x0c089cf8u,0x0c089cfau,0x0c089cfcu,0x0c089cfeu,0x0c089d00u,0x0c089d02u,0x0c089d04u,0x0c089d06u,0x0c089d08u,
0x0c089d0au,0x0c089d0cu,0x0c089d0eu,0x0c089d10u,0x0c089d12u,0x0c089d14u,0x0c089d16u,0x0c089d18u,0x0c089d1au,0x0c089d1cu,0x0c089d1eu,0x0c089d20u,0x0c089d22u,0x0c089d24u,0x0c089d26u,0x0c0aca18u,
0x0c0aca1au,0x0c0aca1cu,0x0c0aca1eu,0x0c0aca20u,0x0c0aca22u,0x0c0aca24u,0x0c0aca26u,0x0c0aca28u,0x0c0aca2au,0x0c0aca2cu,0x0c0aca2eu,0x0c0aca30u,0x0c0aca32u,0x0c0aca34u,0x0c0aca36u,0x0c0aca38u,
0x0c0aca3au,0x0c0aca3cu,0x0c0aca3eu,0x0c0aca40u,0x0c0aca42u,0x0c0aca44u,0x0c0aca46u,0x0c0aca48u,0x0c0aca4au,0x0c0aca4cu,0x0c0aca4eu,0x0c0aca50u,0x0c0aca52u,0x0c0aca54u,0x0c0aca56u,0x0c0aca58u,
0x0c0aca5au,0x0c0aca5cu,0x0c0aca5eu,0x0c0aca60u,0x0c0aca62u,0x0c0aca64u,0x0c0aca66u,0x0c0aca68u,0x0c0aca6au,0x0c0aca6cu,0x0c0acf68u,0x0c0acf6au,0x0c0acf6cu,0x0c0acf6eu,0x0c0acf70u,0x0c0acf72u,
0x0c0acf74u,0x0c0acf76u,0x0c0acf78u,0x0c0acf7au,0x0c0acf7cu,0x0c0acf7eu,0x0c0acf80u,0x0c0acf82u,0x0c0acf84u,0x0c0acf86u,0x0c0acf88u,0x0c0acf8au,0x0c0acf8cu,0x0c0acf8eu,0x0c0acf90u,0x0c0acf92u,
0x0c0acf94u,0x0c0acf96u,0x0c0acf98u,0x0c0acf9au,0x0c0acf9cu,0x0c0acf9eu,0x0c0acfa0u,0x0c0acfa2u,0x0c0acfa4u,0x0c0acfa6u,0x0c0acfa8u,0x0c0acfaau,0x0c0acfacu,0x0c0acfaeu,0x0c0acfb0u,0x0c0acfb2u,
0x0c0acfb4u,0x0c0acfb6u,0x0c0acfb8u,0x0c0acfbau,0x0c0acfbcu,0x0c0acfbeu,0x0c0acfc0u,0x0c0acfc2u,0x0c0acfc4u,0x0c0acfc6u,0x0c0acfc8u,0x0c0acfcau,0x0c0acfccu,0x0c0acfceu,0x0c0acfd0u,0x0c0acfd2u,
0x0c0acfd4u,0x0c0acfd6u,0x0c0acfd8u,0x0c0acfdau,0x0c0acfdcu,0x0c0acfdeu,0x0c0acfe0u,0x0c0acfe2u,0x0c0acfe4u,0x0c0acfe6u,0x0c0acfe8u,0x0c0acfeau,0x0c0acfecu,0x0c0acfeeu,0x0c0acff0u,0x0c0acff2u,
0x0c0acff4u,0x0c0acff6u,0x0c0acff8u,0x0c0c4d2cu,0x0c0c4d2eu,0x0c0c4d30u,0x0c0c4d32u,0x0c0c4d34u,0x0c0c4d36u,0x0c0c4d38u,0x0c0c4d3au,0x0c0c4d3cu,0x0c0c4d3eu,0x0c0c4d40u,0x0c0c4d42u,0x0c0c4d44u,
0x0c0c4d46u,0x0c0c4d48u,0x0c0c4d4au,0x0c0c4d4cu,0x0c0c4d4eu,0x0c0c4d50u,0x0c0c4d52u,0x0c0c4d54u,0x0c0c4d56u,0x0c0c4d58u,0x0c0c4d5au,0x0c0c4d5cu,0x0c0c4d5eu,0x0c0c4d60u,0x0c0c4d62u,0x0c0c4d64u,
0x0c0c4d66u,0x0c0c4d68u,0x0c0c4d6au,0x0c0c4d6cu,0x0c0c4d6eu,0x0c0c4d70u,0x0c0c4d72u,0x0c0c4d74u,0x0c0c4d76u,0x0c0c4d78u,0x0c0c4d7au,0x0c0c4d7cu,0x0c0c4d7eu,0x0c0c4d80u,0x0c0c4d82u,0x0c0c4d84u,
0x0c0c4d86u,0x0c0c4d88u,0x0c0c4d8au,0x0c0c4d8cu,0x0c0c4d8eu,0x0c0c4d90u,0x0c0c4d92u,0x0c0c4d94u,0x0c0c4d96u,0x0c0c4d98u,0x0c0c4d9au,0x0c0c4d9cu,0x0c0c4d9eu,0x0c0c4da0u,0x0c0c4da2u,0x0c0c4da4u,
0x0c0c4da6u,0x0c0c4da8u,0x0c0c4daau,0x0c0c4e4au,0x0c0c4e4cu,0x0c0c4e4eu,0x0c0c4e50u,0x0c0c4e52u,0x0c0c4e54u,0x0c0c4e56u,0x0c0c4e58u,0x0c0c4e5au,0x0c0c4e5cu,0x0c0c4e5eu,0x0c0c4e60u,0x0c0c4e62u,
0x0c0c4e64u,0x0c0c4e66u,0x0c0c4e68u,0x0c0c4e6au,0x0c0c4e6cu,0x0c0c4e6eu,0x0c0c4e70u,0x0c0c4e72u,0x0c0c4e74u,0x0c0c4e76u,0x0c0c4e78u,0x0c0c4e7au,0x0c0c4e7cu,0x0c0c4e7eu,0x0c0c4e80u,0x0c0c4e82u,
0x0c0c4e84u,0x0c0c4e86u,0x0c0c4e88u,0x0c0c4e8au,0x0c0c4e8cu,0x0c0c4e8eu,0x0c0c4e90u,0x0c0c4e92u,0x0c0c4e94u,0x0c0c4e96u,0x0c0c4e98u,0x0c0c4e9au,0x0c0c4e9cu,0x0c0c4e9eu,0x0c0c4ea0u,0x0c0c4ea2u,
0x0c0c4ea4u,0x0c0c4ea6u,0x0c0c4ea8u,0x0c0c4eaau,0x0c0c4eacu,0x0c0c4eaeu,0x0c0c6104u,0x0c0c6106u,0x0c0c6108u,0x0c0c610au,0x0c0c610cu,0x0c0c610eu,0x0c0c6110u,0x0c0c6112u,0x0c0c6114u,0x0c0c6116u,
0x0c0c6118u,0x0c0c611au,0x0c0c611cu,0x0c0c611eu,0x0c0c6120u,0x0c0c6122u,0x0c0c6124u,0x0c0c6126u,0x0c0c6128u,0x0c0c612au,0x0c0c612cu,0x0c0c612eu,0x0c0c6130u,0x0c0c6132u,0x0c0c6134u,0x0c0c6136u,
0x0c0c6138u,0x0c0c613au,0x0c0c613cu,0x0c0c613eu,0x0c0c6140u,0x0c0c6142u,0x0c0c6144u,0x0c0c6146u,0x0c0c6148u,0x0c0c614au,0x0c0c614cu,0x0c0c614eu,0x0c0c6150u,0x0c0c6152u,0x0c0c6154u,0x0c0c6156u,
0x0c0c6158u,0x0c0c615au,0x0c0c615cu,0x0c0c615eu,0x0c0c6160u,0x0c0c6162u,0x0c0c6164u,0x0c0c6166u,0x0c0c6168u,0x0c0c616au,0x0c0c616cu,0x0c0c616eu,0x0c0c6170u,0x0c0c6172u,0x0c0c6174u,0x0c0c6176u,
0x0c0c6178u,0x0c0c8274u,0x0c0c8276u,0x0c0c8278u,0x0c0c827au,0x0c0c827cu,0x0c0c827eu,0x0c0c8280u,0x0c0c8282u,0x0c0c8284u,0x0c0c8286u,0x0c0c8288u,0x0c0c828au,0x0c0c828cu,0x0c0c828eu,0x0c0c8290u,
0x0c0c8292u,0x0c0c8294u,0x0c0c8296u,0x0c0c8298u,0x0c0c829au,0x0c0c829cu,0x0c0c829eu,0x0c0c82a0u,0x0c0c82a2u,0x0c0c82a4u,0x0c0c82a6u,0x0c0c82a8u,0x0c0c82aau,0x0c0c82acu,0x0c0c82aeu,0x0c0c82b0u,
0x0c0c82b2u,0x0c0c82b4u,0x0c0c82b6u,0x0c0c82b8u,0x0c0c82bau,0x0c0c82bcu,0x0c0c82beu,0x0c0c82c0u,0x0c0c82c2u,0x0c0c82c4u,0x0c0c82c6u,0x0c0c82c8u,0x0c0c82cau,0x0c0c82ccu,0x0c0c82ceu,0x0c0c82d0u,
0x0c0c82d2u,0x0c0c82d4u,0x0c0c82d6u,0x0c0c82d8u,0x0c0c82dau,0x0c0c82dcu,0x0c0c82deu,0x0c0c82e0u,0x0c0c82e2u,0x0c0c8324u,0x0c0c8326u,0x0c0c8328u,0x0c0c832au,0x0c0c832cu,0x0c0c832eu,0x0c0c8330u,
0x0c0c8332u,0x0c0c8334u,0x0c0c8336u,0x0c0c8338u,0x0c0c833au,0x0c0c833cu,0x0c0c833eu,0x0c0c8340u,0x0c0c8342u,0x0c0c8344u,0x0c0c8346u,0x0c0c8348u,0x0c0c834au,0x0c0c834cu,0x0c0c834eu,0x0c0c8350u,
0x0c0c8352u,0x0c0c8354u,0x0c0c8356u,0x0c0c8358u,0x0c0c835au,0x0c0c835cu,0x0c0c835eu,0x0c0c8394u,0x0c0c8396u,0x0c0c8398u,0x0c0c839au,0x0c0c839cu,0x0c0c839eu,0x0c0c83a0u,0x0c0c83a2u,0x0c0c83a4u,
0x0c0c83a6u,0x0c0c83a8u,0x0c0c83aau,0x0c0c83acu,0x0c0c83aeu,0x0c0c83b0u,0x0c0c83b2u,0x0c0c83b4u,0x0c0c83b6u,0x0c0c83b8u,0x0c0c83bau,0x0c0c83bcu,0x0c0c83beu,0x0c0c83c0u,0x0c0c83c2u,0x0c0c83c4u,
0x0c0c83c6u,0x0c0c83c8u,0x0c0c83cau,0x0c0c83ccu,0x0c0c83ceu,0x0c0c83d0u,0x0c0c83d2u,0x0c0c83d4u,0x0c0c83d6u,0x0c0c83d8u,0x0c0c83dau,0x0c0c83dcu,0x0c0c83deu,0x0c0c83e0u,0x0c0c83e2u,0x0c0c83e4u,
0x0c0c83e6u,0x0c0c83e8u,0x0c0c83eau,0x0c0c83ecu,0x0c0c83eeu,0x0c0c83f0u,0x0c0c83f2u,0x0c0c83f4u,0x0c0c83f6u,0x0c0c83f8u,0x0c0c83fau,0x0c0c83fcu,0x0c0c83feu,0x0c0c8400u,0x0c0c8402u,0x0c0c8404u,
0x0c0c8406u,0x0c0c8408u,0x0c0c840au,0x0c0c840cu,0x0c0c840eu,0x0c0c8410u,0x0c0c8412u,0x0c0c8414u,0x0c0c8416u,0x0c0c8418u,0x0c0c841au,0x0c0c841cu,0x0c0c841eu,0x0c0c8420u,0x0c0c8422u,0x0c0c8424u,
0x0c0c8426u,0x0c0c8428u,0x0c0c842au,0x0c0c842cu,0x0c0c842eu,0x0c0c8430u,0x0c0c8432u,0x0c0c8434u,0x0c0c8436u,0x0c0c8438u,0x0c0c843au,0x0c0c843cu,0x0c0c843eu,0x0c0c8440u,0x0c0c8442u,0x0c0c8444u,
0x0c0c8446u,0x0c0c8448u,0x0c0c844au,0x0c0c844cu,0x0c0c844eu,0x0c0c8450u,0x0c0c8452u,0x0c0c8454u,0x0c0c8456u,0x0c0c8458u,0x0c0c845au,0x0c0c845cu,0x0c0c845eu,0x0c0c8460u,0x0c0c8462u,0x0c0c8464u,
0x0c0c8466u,0x0c0c8468u,0x0c0c846au,0x0c0c846cu,0x0c0c846eu,0x0c0c8470u,0x0c0c8472u,0x0c0c8494u,0x0c0c8496u,0x0c0c8498u,0x0c0c849au,0x0c0c849cu,0x0c0c849eu,0x0c0c84a0u,0x0c0c84a2u,0x0c0c84a4u,
0x0c0c84a6u,0x0c0c84a8u,0x0c0c84aau,0x0c0c84acu,0x0c0c84aeu,0x0c0c84b0u,0x0c0c84b2u,0x0c0c84b4u,0x0c0c84b6u,0x0c0c84b8u,0x0c0c84bau,0x0c0c84bcu,0x0c0c84beu,0x0c0c84c0u,0x0c0c84c2u,0x0c0c84c4u,
0x0c0c84c6u,0x0c0c84c8u,0x0c0c84cau,0x0c0c84ccu,0x0c0c84ceu,0x0c0c84d0u,0x0c0c84d2u,0x0c0c84d4u,0x0c0c84d6u,0x0c0c84d8u,0x0c0c84dau,0x0c0c84dcu,0x0c0c84deu,0x0c0c84e0u,0x0c0c84e2u,0x0c0c84e4u,
0x0c0c84e6u,0x0c0c84e8u,0x0c0c84eau,0x0c0c84ecu,0x0c0c84eeu,0x0c0c84f0u,0x0c0c84f2u,0x0c0c84f4u,0x0c0c84f6u,0x0c0c84f8u,0x0c0c84fau,0x0c0c84fcu,0x0c0c84feu,0x0c0c8500u,0x0c0c8502u,0x0c0c8504u,
0x0c0c8506u,0x0c0c8508u,0x0c0c850au,0x0c0c850cu,0x0c0c850eu,0x0c0c8510u,0x0c0c8512u,0x0c0c8514u,0x0c0c8516u,0x0c0c8518u,0x0c0c851au,0x0c0c851cu,0x0c0c851eu,0x0c0c8520u,0x0c0c8522u,0x0c0c8524u,
0x0c0c8526u,0x0c0c8528u,0x0c0c852au,0x0c0c852cu,0x0c0c852eu,0x0c0c8530u,0x0c0c8532u,0x0c0c8534u,0x0c0c8536u,0x0c0c8538u,0x0c0c853au,0x0c0c853cu,0x0c0c853eu,0x0c0c8540u,0x0c0c8542u,0x0c0c8544u,
0x0c0c8546u,0x0c0c8548u,0x0c0c854au,0x0c0c854cu,0x0c0c854eu,0x0c0c8550u,0x0c0c8552u,0x0c0c8554u,0x0c0c8574u,0x0c0c8576u,0x0c0c8578u,0x0c0c857au,0x0c0c857cu,0x0c0c857eu,0x0c0c8580u,0x0c0c8582u,
0x0c0c8584u,0x0c0c8586u,0x0c0c8588u,0x0c0c858au,0x0c0c858cu,0x0c0c858eu,0x0c0c8590u,0x0c0c8592u,0x0c0c8594u,0x0c0c8596u,0x0c0c8598u,0x0c0c859au,0x0c0c859cu,0x0c0c859eu,0x0c0c85a0u,0x0c0c85a2u,
0x0c0c85a4u,0x0c0c85a6u,0x0c0c85a8u,0x0c0c85aau,0x0c0c85acu,0x0c0c85aeu,0x0c0c85b0u,0x0c0c85b2u,0x0c0c85b4u,0x0c0c85b6u,0x0c0c85b8u,0x0c0c85bau,0x0c0c85bcu,0x0c0c85beu,0x0c0c85c0u,0x0c0c85c2u,
0x0c0c85c4u,0x0c0c85c6u,0x0c0c85c8u,0x0c0c85cau,0x0c0c85ccu,0x0c0c85ceu,0x0c0c85d0u,0x0c0c85d2u,0x0c0c85d4u,0x0c0c85d6u,0x0c0c85d8u,0x0c0c85dau,0x0c0c85dcu,0x0c0c85deu,0x0c0c85e0u,0x0c0c85e2u,
0x0c0c85e4u,0x0c0c85e6u,0x0c0c85e8u,0x0c0c85eau,0x0c0c85ecu,0x0c0c85eeu,0x0c0c85f0u,0x0c0c85f2u,0x0c0c85f4u,0x0c0c85f6u,0x0c0c85f8u,0x0c0c85fau,0x0c0c85fcu,0x0c0c85feu,0x0c0c8600u,0x0c0c8602u,
0x0c0c8604u,0x0c0c8606u,0x0c0c8608u,0x0c0c860au,0x0c0c860cu,0x0c0c860eu,0x0c0c8610u,0x0c0c8612u,0x0c0c8614u,0x0c0c8616u,0x0c0c8618u,0x0c0c861au,0x0c0c861cu,0x0c0c861eu,0x0c0c8620u,0x0c0c8622u,
};
int vf3_target_closure_step_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
