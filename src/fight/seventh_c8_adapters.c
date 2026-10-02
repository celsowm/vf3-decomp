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
int vf3_seventh_c8_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c045ba8u: goto P_0c045ba8;
case 0x0c045baau: goto P_0c045baa;
case 0x0c045bacu: goto P_0c045bac;
case 0x0c045baeu: goto P_0c045bae;
case 0x0c045bb0u: goto P_0c045bb0;
case 0x0c045bb2u: goto P_0c045bb2;
case 0x0c045bb4u: goto P_0c045bb4;
case 0x0c045bb6u: goto P_0c045bb6;
case 0x0c045bb8u: goto P_0c045bb8;
case 0x0c045bbau: goto P_0c045bba;
case 0x0c045bbcu: goto P_0c045bbc;
case 0x0c045bbeu: goto P_0c045bbe;
case 0x0c045bc0u: goto P_0c045bc0;
case 0x0c045bc2u: goto P_0c045bc2;
case 0x0c045bc4u: goto P_0c045bc4;
case 0x0c045bc6u: goto P_0c045bc6;
case 0x0c045bc8u: goto P_0c045bc8;
case 0x0c06f75au: goto P_0c06f75a;
case 0x0c06f75cu: goto P_0c06f75c;
case 0x0c06f75eu: goto P_0c06f75e;
case 0x0c06f760u: goto P_0c06f760;
case 0x0c06f762u: goto P_0c06f762;
case 0x0c06f764u: goto P_0c06f764;
case 0x0c06f766u: goto P_0c06f766;
case 0x0c06f768u: goto P_0c06f768;
case 0x0c06f76au: goto P_0c06f76a;
case 0x0c06f76cu: goto P_0c06f76c;
case 0x0c06f76eu: goto P_0c06f76e;
case 0x0c06f770u: goto P_0c06f770;
case 0x0c06f772u: goto P_0c06f772;
case 0x0c06f774u: goto P_0c06f774;
case 0x0c06f776u: goto P_0c06f776;
case 0x0c06f778u: goto P_0c06f778;
case 0x0c06f77au: goto P_0c06f77a;
case 0x0c06f77cu: goto P_0c06f77c;
case 0x0c06f77eu: goto P_0c06f77e;
case 0x0c06f780u: goto P_0c06f780;
case 0x0c06f782u: goto P_0c06f782;
case 0x0c06f784u: goto P_0c06f784;
case 0x0c06f786u: goto P_0c06f786;
case 0x0c06f788u: goto P_0c06f788;
case 0x0c06f78au: goto P_0c06f78a;
case 0x0c06f78cu: goto P_0c06f78c;
case 0x0c06f78eu: goto P_0c06f78e;
case 0x0c06f790u: goto P_0c06f790;
case 0x0c06f792u: goto P_0c06f792;
case 0x0c06f794u: goto P_0c06f794;
case 0x0c06f796u: goto P_0c06f796;
case 0x0c06f798u: goto P_0c06f798;
case 0x0c06f79au: goto P_0c06f79a;
case 0x0c06f79cu: goto P_0c06f79c;
case 0x0c06f79eu: goto P_0c06f79e;
case 0x0c06f7a0u: goto P_0c06f7a0;
case 0x0c06f7a2u: goto P_0c06f7a2;
case 0x0c06f7a4u: goto P_0c06f7a4;
case 0x0c06f7a6u: goto P_0c06f7a6;
case 0x0c06f7a8u: goto P_0c06f7a8;
case 0x0c06f7aau: goto P_0c06f7aa;
case 0x0c06f7acu: goto P_0c06f7ac;
case 0x0c06f7aeu: goto P_0c06f7ae;
case 0x0c06f7b0u: goto P_0c06f7b0;
case 0x0c06f7b2u: goto P_0c06f7b2;
case 0x0c06f7b4u: goto P_0c06f7b4;
case 0x0c06f7b6u: goto P_0c06f7b6;
case 0x0c06f7b8u: goto P_0c06f7b8;
case 0x0c06f7bau: goto P_0c06f7ba;
case 0x0c06f7bcu: goto P_0c06f7bc;
case 0x0c06f7beu: goto P_0c06f7be;
case 0x0c06f7c0u: goto P_0c06f7c0;
case 0x0c06f7c2u: goto P_0c06f7c2;
case 0x0c06f7c4u: goto P_0c06f7c4;
case 0x0c06f7c6u: goto P_0c06f7c6;
case 0x0c06f7c8u: goto P_0c06f7c8;
case 0x0c06f7cau: goto P_0c06f7ca;
case 0x0c06f7ccu: goto P_0c06f7cc;
case 0x0c06f7ceu: goto P_0c06f7ce;
case 0x0c06f7d0u: goto P_0c06f7d0;
case 0x0c06f7d2u: goto P_0c06f7d2;
case 0x0c06f7d4u: goto P_0c06f7d4;
case 0x0c06f7d6u: goto P_0c06f7d6;
case 0x0c06f7d8u: goto P_0c06f7d8;
case 0x0c06f7dau: goto P_0c06f7da;
case 0x0c06f7dcu: goto P_0c06f7dc;
case 0x0c06f7deu: goto P_0c06f7de;
case 0x0c06f7e0u: goto P_0c06f7e0;
case 0x0c06f7e2u: goto P_0c06f7e2;
case 0x0c06f7e4u: goto P_0c06f7e4;
case 0x0c06f7e6u: goto P_0c06f7e6;
case 0x0c06f7e8u: goto P_0c06f7e8;
case 0x0c06f7eau: goto P_0c06f7ea;
case 0x0c06f7ecu: goto P_0c06f7ec;
case 0x0c06f7eeu: goto P_0c06f7ee;
case 0x0c06f7f0u: goto P_0c06f7f0;
case 0x0c06f7f2u: goto P_0c06f7f2;
case 0x0c06f7f4u: goto P_0c06f7f4;
case 0x0c06f7f6u: goto P_0c06f7f6;
case 0x0c06f7f8u: goto P_0c06f7f8;
case 0x0c06f7fau: goto P_0c06f7fa;
case 0x0c06f7fcu: goto P_0c06f7fc;
case 0x0c06f7feu: goto P_0c06f7fe;
case 0x0c06f800u: goto P_0c06f800;
case 0x0c06f802u: goto P_0c06f802;
case 0x0c06f804u: goto P_0c06f804;
case 0x0c06f806u: goto P_0c06f806;
case 0x0c06f808u: goto P_0c06f808;
case 0x0c06f80au: goto P_0c06f80a;
case 0x0c06f80cu: goto P_0c06f80c;
case 0x0c06f80eu: goto P_0c06f80e;
case 0x0c06f810u: goto P_0c06f810;
case 0x0c06f812u: goto P_0c06f812;
case 0x0c06f814u: goto P_0c06f814;
case 0x0c06f816u: goto P_0c06f816;
case 0x0c06f818u: goto P_0c06f818;
case 0x0c06f81au: goto P_0c06f81a;
case 0x0c06f81cu: goto P_0c06f81c;
case 0x0c06f81eu: goto P_0c06f81e;
case 0x0c06f820u: goto P_0c06f820;
case 0x0c06f822u: goto P_0c06f822;
case 0x0c06f824u: goto P_0c06f824;
case 0x0c06f826u: goto P_0c06f826;
case 0x0c06f828u: goto P_0c06f828;
case 0x0c06f82au: goto P_0c06f82a;
case 0x0c06f82cu: goto P_0c06f82c;
case 0x0c06f82eu: goto P_0c06f82e;
case 0x0c06f830u: goto P_0c06f830;
case 0x0c06f832u: goto P_0c06f832;
case 0x0c06f834u: goto P_0c06f834;
case 0x0c06f836u: goto P_0c06f836;
case 0x0c06f838u: goto P_0c06f838;
case 0x0c06f83au: goto P_0c06f83a;
case 0x0c06f83cu: goto P_0c06f83c;
case 0x0c06f83eu: goto P_0c06f83e;
case 0x0c06f840u: goto P_0c06f840;
case 0x0c06f842u: goto P_0c06f842;
case 0x0c06f844u: goto P_0c06f844;
case 0x0c06f846u: goto P_0c06f846;
case 0x0c06f848u: goto P_0c06f848;
case 0x0c06f84au: goto P_0c06f84a;
case 0x0c06f84cu: goto P_0c06f84c;
case 0x0c06f84eu: goto P_0c06f84e;
case 0x0c06f850u: goto P_0c06f850;
case 0x0c06f852u: goto P_0c06f852;
case 0x0c06f854u: goto P_0c06f854;
case 0x0c06f856u: goto P_0c06f856;
case 0x0c06f858u: goto P_0c06f858;
case 0x0c06f85au: goto P_0c06f85a;
case 0x0c06f85cu: goto P_0c06f85c;
case 0x0c06f85eu: goto P_0c06f85e;
case 0x0c06f860u: goto P_0c06f860;
case 0x0c06f862u: goto P_0c06f862;
case 0x0c06f864u: goto P_0c06f864;
case 0x0c06f866u: goto P_0c06f866;
case 0x0c06f868u: goto P_0c06f868;
case 0x0c06f86au: goto P_0c06f86a;
case 0x0c06f86cu: goto P_0c06f86c;
case 0x0c06f86eu: goto P_0c06f86e;
case 0x0c06f870u: goto P_0c06f870;
case 0x0c06f872u: goto P_0c06f872;
case 0x0c06f874u: goto P_0c06f874;
case 0x0c06f876u: goto P_0c06f876;
case 0x0c06f878u: goto P_0c06f878;
case 0x0c06f87au: goto P_0c06f87a;
case 0x0c06f87cu: goto P_0c06f87c;
case 0x0c06f87eu: goto P_0c06f87e;
case 0x0c06f880u: goto P_0c06f880;
case 0x0c06f882u: goto P_0c06f882;
case 0x0c06f884u: goto P_0c06f884;
case 0x0c06f886u: goto P_0c06f886;
case 0x0c06f888u: goto P_0c06f888;
case 0x0c06f88au: goto P_0c06f88a;
case 0x0c06f88cu: goto P_0c06f88c;
case 0x0c06f88eu: goto P_0c06f88e;
case 0x0c06f890u: goto P_0c06f890;
case 0x0c06f892u: goto P_0c06f892;
case 0x0c06f894u: goto P_0c06f894;
case 0x0c06f896u: goto P_0c06f896;
case 0x0c06f898u: goto P_0c06f898;
case 0x0c06f89au: goto P_0c06f89a;
case 0x0c06f89cu: goto P_0c06f89c;
case 0x0c06f89eu: goto P_0c06f89e;
case 0x0c06f8a0u: goto P_0c06f8a0;
case 0x0c06f8a2u: goto P_0c06f8a2;
case 0x0c06f8a4u: goto P_0c06f8a4;
case 0x0c06f8a6u: goto P_0c06f8a6;
case 0x0c06f8a8u: goto P_0c06f8a8;
case 0x0c06f8aau: goto P_0c06f8aa;
case 0x0c06f8acu: goto P_0c06f8ac;
case 0x0c06f8aeu: goto P_0c06f8ae;
case 0x0c06f8b0u: goto P_0c06f8b0;
case 0x0c06f8b2u: goto P_0c06f8b2;
case 0x0c06f8b4u: goto P_0c06f8b4;
case 0x0c06f8b6u: goto P_0c06f8b6;
case 0x0c06f8b8u: goto P_0c06f8b8;
case 0x0c06f8bau: goto P_0c06f8ba;
case 0x0c06f8bcu: goto P_0c06f8bc;
case 0x0c06f8beu: goto P_0c06f8be;
case 0x0c06f8c0u: goto P_0c06f8c0;
case 0x0c06f8c2u: goto P_0c06f8c2;
case 0x0c06f8c4u: goto P_0c06f8c4;
case 0x0c06f8c6u: goto P_0c06f8c6;
case 0x0c06f8c8u: goto P_0c06f8c8;
case 0x0c06f8cau: goto P_0c06f8ca;
case 0x0c06f8ccu: goto P_0c06f8cc;
case 0x0c06f8ceu: goto P_0c06f8ce;
case 0x0c06f8d0u: goto P_0c06f8d0;
case 0x0c06f8d2u: goto P_0c06f8d2;
case 0x0c06f8d4u: goto P_0c06f8d4;
case 0x0c06f8d6u: goto P_0c06f8d6;
case 0x0c06f8d8u: goto P_0c06f8d8;
case 0x0c06f8dau: goto P_0c06f8da;
case 0x0c06f8dcu: goto P_0c06f8dc;
case 0x0c06f8deu: goto P_0c06f8de;
case 0x0c06f8e0u: goto P_0c06f8e0;
case 0x0c06f8e2u: goto P_0c06f8e2;
case 0x0c06f8e4u: goto P_0c06f8e4;
case 0x0c06f8e6u: goto P_0c06f8e6;
case 0x0c06f8e8u: goto P_0c06f8e8;
case 0x0c06f8eau: goto P_0c06f8ea;
case 0x0c06f8ecu: goto P_0c06f8ec;
case 0x0c06f8eeu: goto P_0c06f8ee;
case 0x0c06f8f0u: goto P_0c06f8f0;
case 0x0c06f8f2u: goto P_0c06f8f2;
case 0x0c06f8f4u: goto P_0c06f8f4;
case 0x0c06f8f6u: goto P_0c06f8f6;
case 0x0c06f8f8u: goto P_0c06f8f8;
case 0x0c06f8fau: goto P_0c06f8fa;
case 0x0c06f8fcu: goto P_0c06f8fc;
case 0x0c06f8feu: goto P_0c06f8fe;
case 0x0c06f900u: goto P_0c06f900;
case 0x0c06f902u: goto P_0c06f902;
case 0x0c06f904u: goto P_0c06f904;
case 0x0c06f906u: goto P_0c06f906;
case 0x0c06f908u: goto P_0c06f908;
case 0x0c06f90au: goto P_0c06f90a;
case 0x0c06f90cu: goto P_0c06f90c;
case 0x0c06f90eu: goto P_0c06f90e;
case 0x0c06f910u: goto P_0c06f910;
case 0x0c06f912u: goto P_0c06f912;
case 0x0c06f914u: goto P_0c06f914;
case 0x0c06f916u: goto P_0c06f916;
case 0x0c06f918u: goto P_0c06f918;
case 0x0c06f91au: goto P_0c06f91a;
case 0x0c06f91cu: goto P_0c06f91c;
case 0x0c06f91eu: goto P_0c06f91e;
case 0x0c06f920u: goto P_0c06f920;
case 0x0c06f922u: goto P_0c06f922;
case 0x0c06f924u: goto P_0c06f924;
case 0x0c06f926u: goto P_0c06f926;
case 0x0c06f928u: goto P_0c06f928;
case 0x0c06f92au: goto P_0c06f92a;
case 0x0c06f92cu: goto P_0c06f92c;
case 0x0c06f92eu: goto P_0c06f92e;
case 0x0c06f930u: goto P_0c06f930;
case 0x0c06f932u: goto P_0c06f932;
case 0x0c06f934u: goto P_0c06f934;
case 0x0c06f936u: goto P_0c06f936;
case 0x0c06f938u: goto P_0c06f938;
case 0x0c06f93au: goto P_0c06f93a;
case 0x0c06f93cu: goto P_0c06f93c;
case 0x0c06f93eu: goto P_0c06f93e;
case 0x0c06f940u: goto P_0c06f940;
case 0x0c06f942u: goto P_0c06f942;
case 0x0c06f944u: goto P_0c06f944;
case 0x0c06f946u: goto P_0c06f946;
case 0x0c06f948u: goto P_0c06f948;
case 0x0c06f94au: goto P_0c06f94a;
case 0x0c06f94cu: goto P_0c06f94c;
case 0x0c06f94eu: goto P_0c06f94e;
case 0x0c06f950u: goto P_0c06f950;
case 0x0c06f952u: goto P_0c06f952;
case 0x0c06f954u: goto P_0c06f954;
case 0x0c06f956u: goto P_0c06f956;
case 0x0c06f958u: goto P_0c06f958;
case 0x0c06f95au: goto P_0c06f95a;
case 0x0c06f95cu: goto P_0c06f95c;
case 0x0c06f95eu: goto P_0c06f95e;
case 0x0c06f960u: goto P_0c06f960;
case 0x0c06f962u: goto P_0c06f962;
case 0x0c06f964u: goto P_0c06f964;
case 0x0c06f966u: goto P_0c06f966;
case 0x0c06f968u: goto P_0c06f968;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
case 0x0c070caau: goto P_0c070caa;
case 0x0c070cacu: goto P_0c070cac;
case 0x0c070caeu: goto P_0c070cae;
case 0x0c070cb0u: goto P_0c070cb0;
case 0x0c070cb2u: goto P_0c070cb2;
case 0x0c070cb4u: goto P_0c070cb4;
case 0x0c070cb6u: goto P_0c070cb6;
case 0x0c070cb8u: goto P_0c070cb8;
case 0x0c070cbau: goto P_0c070cba;
case 0x0c070cbcu: goto P_0c070cbc;
case 0x0c070cbeu: goto P_0c070cbe;
case 0x0c070cc0u: goto P_0c070cc0;
case 0x0c070cc2u: goto P_0c070cc2;
case 0x0c070cc4u: goto P_0c070cc4;
case 0x0c070cc6u: goto P_0c070cc6;
case 0x0c070cc8u: goto P_0c070cc8;
case 0x0c070ccau: goto P_0c070cca;
case 0x0c070cccu: goto P_0c070ccc;
case 0x0c070cceu: goto P_0c070cce;
case 0x0c070cd0u: goto P_0c070cd0;
case 0x0c070cd2u: goto P_0c070cd2;
case 0x0c070cd4u: goto P_0c070cd4;
case 0x0c070cd6u: goto P_0c070cd6;
case 0x0c070cd8u: goto P_0c070cd8;
case 0x0c070cdau: goto P_0c070cda;
case 0x0c070cdcu: goto P_0c070cdc;
case 0x0c070cdeu: goto P_0c070cde;
case 0x0c070ce0u: goto P_0c070ce0;
case 0x0c070ce2u: goto P_0c070ce2;
case 0x0c070ce4u: goto P_0c070ce4;
case 0x0c070ce6u: goto P_0c070ce6;
case 0x0c070ce8u: goto P_0c070ce8;
case 0x0c070ceau: goto P_0c070cea;
case 0x0c070cecu: goto P_0c070cec;
case 0x0c070ceeu: goto P_0c070cee;
case 0x0c070cf0u: goto P_0c070cf0;
case 0x0c070cf2u: goto P_0c070cf2;
case 0x0c070cf4u: goto P_0c070cf4;
case 0x0c070cf6u: goto P_0c070cf6;
case 0x0c070cf8u: goto P_0c070cf8;
case 0x0c070cfau: goto P_0c070cfa;
case 0x0c070cfcu: goto P_0c070cfc;
case 0x0c070cfeu: goto P_0c070cfe;
case 0x0c070d00u: goto P_0c070d00;
case 0x0c070d02u: goto P_0c070d02;
case 0x0c070d04u: goto P_0c070d04;
case 0x0c070d06u: goto P_0c070d06;
case 0x0c070d08u: goto P_0c070d08;
case 0x0c070d0au: goto P_0c070d0a;
case 0x0c070d0cu: goto P_0c070d0c;
case 0x0c070d0eu: goto P_0c070d0e;
case 0x0c070d10u: goto P_0c070d10;
case 0x0c070d12u: goto P_0c070d12;
case 0x0c070d14u: goto P_0c070d14;
case 0x0c070d16u: goto P_0c070d16;
case 0x0c070d18u: goto P_0c070d18;
case 0x0c070d1au: goto P_0c070d1a;
case 0x0c070d1cu: goto P_0c070d1c;
case 0x0c070d1eu: goto P_0c070d1e;
case 0x0c070d24u: goto P_0c070d24;
case 0x0c070d26u: goto P_0c070d26;
case 0x0c070d28u: goto P_0c070d28;
case 0x0c070d2au: goto P_0c070d2a;
case 0x0c070d2cu: goto P_0c070d2c;
case 0x0c070d2eu: goto P_0c070d2e;
case 0x0c070d30u: goto P_0c070d30;
case 0x0c070d32u: goto P_0c070d32;
case 0x0c070d34u: goto P_0c070d34;
case 0x0c070d36u: goto P_0c070d36;
case 0x0c070d38u: goto P_0c070d38;
case 0x0c070d3au: goto P_0c070d3a;
case 0x0c070d3cu: goto P_0c070d3c;
case 0x0c070d3eu: goto P_0c070d3e;
case 0x0c070d40u: goto P_0c070d40;
case 0x0c070d42u: goto P_0c070d42;
case 0x0c070d44u: goto P_0c070d44;
case 0x0c070d46u: goto P_0c070d46;
case 0x0c070d48u: goto P_0c070d48;
case 0x0c070d4au: goto P_0c070d4a;
case 0x0c070d4cu: goto P_0c070d4c;
case 0x0c070d4eu: goto P_0c070d4e;
case 0x0c070d50u: goto P_0c070d50;
case 0x0c070d52u: goto P_0c070d52;
case 0x0c070d54u: goto P_0c070d54;
case 0x0c070d56u: goto P_0c070d56;
case 0x0c070d58u: goto P_0c070d58;
case 0x0c070d5au: goto P_0c070d5a;
case 0x0c070d5cu: goto P_0c070d5c;
case 0x0c070d5eu: goto P_0c070d5e;
case 0x0c070d60u: goto P_0c070d60;
case 0x0c070d62u: goto P_0c070d62;
case 0x0c070d64u: goto P_0c070d64;
case 0x0c070d66u: goto P_0c070d66;
case 0x0c070d68u: goto P_0c070d68;
case 0x0c070d6au: goto P_0c070d6a;
case 0x0c070d70u: goto P_0c070d70;
case 0x0c070d72u: goto P_0c070d72;
case 0x0c070d74u: goto P_0c070d74;
case 0x0c070d76u: goto P_0c070d76;
case 0x0c070d78u: goto P_0c070d78;
case 0x0c070d7au: goto P_0c070d7a;
case 0x0c070d7cu: goto P_0c070d7c;
case 0x0c070d7eu: goto P_0c070d7e;
case 0x0c070d80u: goto P_0c070d80;
case 0x0c070d82u: goto P_0c070d82;
case 0x0c070d84u: goto P_0c070d84;
case 0x0c070d86u: goto P_0c070d86;
case 0x0c070d88u: goto P_0c070d88;
case 0x0c070d8au: goto P_0c070d8a;
case 0x0c070d8cu: goto P_0c070d8c;
case 0x0c070d8eu: goto P_0c070d8e;
case 0x0c070d90u: goto P_0c070d90;
case 0x0c070d92u: goto P_0c070d92;
case 0x0c070d94u: goto P_0c070d94;
case 0x0c070d96u: goto P_0c070d96;
case 0x0c070d98u: goto P_0c070d98;
case 0x0c070d9au: goto P_0c070d9a;
case 0x0c070d9cu: goto P_0c070d9c;
case 0x0c070d9eu: goto P_0c070d9e;
case 0x0c070da0u: goto P_0c070da0;
case 0x0c070da2u: goto P_0c070da2;
case 0x0c070da4u: goto P_0c070da4;
case 0x0c070da6u: goto P_0c070da6;
case 0x0c070da8u: goto P_0c070da8;
case 0x0c070db4u: goto P_0c070db4;
case 0x0c070db6u: goto P_0c070db6;
case 0x0c070db8u: goto P_0c070db8;
case 0x0c070dbau: goto P_0c070dba;
case 0x0c070dbcu: goto P_0c070dbc;
case 0x0c070dbeu: goto P_0c070dbe;
case 0x0c070dc0u: goto P_0c070dc0;
case 0x0c070dc2u: goto P_0c070dc2;
case 0x0c070dc4u: goto P_0c070dc4;
case 0x0c070dc6u: goto P_0c070dc6;
case 0x0c070dc8u: goto P_0c070dc8;
case 0x0c070dcau: goto P_0c070dca;
case 0x0c070dccu: goto P_0c070dcc;
case 0x0c070dceu: goto P_0c070dce;
case 0x0c070dd0u: goto P_0c070dd0;
case 0x0c070dd2u: goto P_0c070dd2;
case 0x0c070dd4u: goto P_0c070dd4;
case 0x0c0710e2u: goto P_0c0710e2;
case 0x0c0710e4u: goto P_0c0710e4;
case 0x0c0710e6u: goto P_0c0710e6;
case 0x0c0710e8u: goto P_0c0710e8;
case 0x0c0710eau: goto P_0c0710ea;
case 0x0c0710ecu: goto P_0c0710ec;
case 0x0c0710eeu: goto P_0c0710ee;
case 0x0c0710f0u: goto P_0c0710f0;
case 0x0c0710f2u: goto P_0c0710f2;
case 0x0c0710f4u: goto P_0c0710f4;
case 0x0c0710f6u: goto P_0c0710f6;
case 0x0c0710f8u: goto P_0c0710f8;
case 0x0c0710fau: goto P_0c0710fa;
case 0x0c0710fcu: goto P_0c0710fc;
case 0x0c0710feu: goto P_0c0710fe;
case 0x0c071100u: goto P_0c071100;
case 0x0c071102u: goto P_0c071102;
case 0x0c071104u: goto P_0c071104;
case 0x0c071106u: goto P_0c071106;
case 0x0c071108u: goto P_0c071108;
case 0x0c07110au: goto P_0c07110a;
case 0x0c07110cu: goto P_0c07110c;
case 0x0c07110eu: goto P_0c07110e;
case 0x0c071110u: goto P_0c071110;
case 0x0c071112u: goto P_0c071112;
case 0x0c071114u: goto P_0c071114;
case 0x0c071116u: goto P_0c071116;
case 0x0c071118u: goto P_0c071118;
case 0x0c07111au: goto P_0c07111a;
case 0x0c07111cu: goto P_0c07111c;
case 0x0c07111eu: goto P_0c07111e;
case 0x0c071120u: goto P_0c071120;
case 0x0c071122u: goto P_0c071122;
case 0x0c071124u: goto P_0c071124;
case 0x0c071126u: goto P_0c071126;
case 0x0c071128u: goto P_0c071128;
case 0x0c07112au: goto P_0c07112a;
case 0x0c07112cu: goto P_0c07112c;
case 0x0c07112eu: goto P_0c07112e;
case 0x0c071130u: goto P_0c071130;
case 0x0c071132u: goto P_0c071132;
case 0x0c071134u: goto P_0c071134;
case 0x0c071136u: goto P_0c071136;
case 0x0c071138u: goto P_0c071138;
case 0x0c07113au: goto P_0c07113a;
case 0x0c07113cu: goto P_0c07113c;
case 0x0c07113eu: goto P_0c07113e;
case 0x0c08b430u: goto P_0c08b430;
case 0x0c08b432u: goto P_0c08b432;
case 0x0c08b434u: goto P_0c08b434;
case 0x0c08b436u: goto P_0c08b436;
case 0x0c08b438u: goto P_0c08b438;
case 0x0c08b43au: goto P_0c08b43a;
case 0x0c08b43cu: goto P_0c08b43c;
case 0x0c08b43eu: goto P_0c08b43e;
case 0x0c08b440u: goto P_0c08b440;
case 0x0c08b442u: goto P_0c08b442;
case 0x0c08b444u: goto P_0c08b444;
case 0x0c08b446u: goto P_0c08b446;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
case 0x0c08b4deu: goto P_0c08b4de;
case 0x0c08b4e0u: goto P_0c08b4e0;
case 0x0c08b4e2u: goto P_0c08b4e2;
case 0x0c08b4e4u: goto P_0c08b4e4;
case 0x0c08b4e6u: goto P_0c08b4e6;
case 0x0c08b4e8u: goto P_0c08b4e8;
case 0x0c08b4eau: goto P_0c08b4ea;
case 0x0c08b4ecu: goto P_0c08b4ec;
case 0x0c08b4eeu: goto P_0c08b4ee;
case 0x0c08b4f0u: goto P_0c08b4f0;
case 0x0c08b4f2u: goto P_0c08b4f2;
case 0x0c08b4f4u: goto P_0c08b4f4;
case 0x0c08b4f6u: goto P_0c08b4f6;
case 0x0c08b4f8u: goto P_0c08b4f8;
case 0x0c08b57eu: goto P_0c08b57e;
case 0x0c08b580u: goto P_0c08b580;
case 0x0c08b582u: goto P_0c08b582;
case 0x0c08b584u: goto P_0c08b584;
case 0x0c08b586u: goto P_0c08b586;
case 0x0c08b588u: goto P_0c08b588;
case 0x0c08b58au: goto P_0c08b58a;
case 0x0c08b58cu: goto P_0c08b58c;
case 0x0c08b58eu: goto P_0c08b58e;
case 0x0c08b590u: goto P_0c08b590;
case 0x0c08b592u: goto P_0c08b592;
case 0x0c08b594u: goto P_0c08b594;
case 0x0c08b596u: goto P_0c08b596;
case 0x0c08b598u: goto P_0c08b598;
case 0x0c08b59au: goto P_0c08b59a;
case 0x0c08b59cu: goto P_0c08b59c;
case 0x0c08b59eu: goto P_0c08b59e;
case 0x0c08b5a0u: goto P_0c08b5a0;
case 0x0c08b5a2u: goto P_0c08b5a2;
case 0x0c08b5a4u: goto P_0c08b5a4;
case 0x0c08b5a6u: goto P_0c08b5a6;
case 0x0c08b5a8u: goto P_0c08b5a8;
case 0x0c08b5aau: goto P_0c08b5aa;
case 0x0c0968d0u: goto P_0c0968d0;
case 0x0c0968d2u: goto P_0c0968d2;
case 0x0c0968d4u: goto P_0c0968d4;
case 0x0c0968d6u: goto P_0c0968d6;
case 0x0c0968d8u: goto P_0c0968d8;
case 0x0c0968dau: goto P_0c0968da;
case 0x0c0968dcu: goto P_0c0968dc;
case 0x0c0968deu: goto P_0c0968de;
case 0x0c0968e0u: goto P_0c0968e0;
case 0x0c0968e2u: goto P_0c0968e2;
case 0x0c0968e4u: goto P_0c0968e4;
case 0x0c0968e6u: goto P_0c0968e6;
case 0x0c0968e8u: goto P_0c0968e8;
case 0x0c0968eau: goto P_0c0968ea;
case 0x0c0968ecu: goto P_0c0968ec;
case 0x0c0968eeu: goto P_0c0968ee;
case 0x0c0968f0u: goto P_0c0968f0;
case 0x0c0968f2u: goto P_0c0968f2;
case 0x0c0968f4u: goto P_0c0968f4;
case 0x0c0968f6u: goto P_0c0968f6;
case 0x0c096902u: goto P_0c096902;
case 0x0c096904u: goto P_0c096904;
case 0x0c096906u: goto P_0c096906;
case 0x0c096908u: goto P_0c096908;
case 0x0c096d5eu: goto P_0c096d5e;
case 0x0c096d60u: goto P_0c096d60;
case 0x0c096d62u: goto P_0c096d62;
case 0x0c096d64u: goto P_0c096d64;
case 0x0c096d66u: goto P_0c096d66;
case 0x0c096d68u: goto P_0c096d68;
case 0x0c096d6au: goto P_0c096d6a;
case 0x0c096d6cu: goto P_0c096d6c;
case 0x0c096d6eu: goto P_0c096d6e;
case 0x0c096d70u: goto P_0c096d70;
case 0x0c096d72u: goto P_0c096d72;
case 0x0c096d74u: goto P_0c096d74;
case 0x0c096d76u: goto P_0c096d76;
case 0x0c096d78u: goto P_0c096d78;
case 0x0c096d7au: goto P_0c096d7a;
case 0x0c096d7cu: goto P_0c096d7c;
case 0x0c096d7eu: goto P_0c096d7e;
case 0x0c096d80u: goto P_0c096d80;
case 0x0c096d82u: goto P_0c096d82;
case 0x0c096d84u: goto P_0c096d84;
case 0x0c096d86u: goto P_0c096d86;
case 0x0c096d88u: goto P_0c096d88;
case 0x0c096d8au: goto P_0c096d8a;
case 0x0c096d8cu: goto P_0c096d8c;
case 0x0c096d8eu: goto P_0c096d8e;
case 0x0c096d90u: goto P_0c096d90;
case 0x0c096d92u: goto P_0c096d92;
case 0x0c096d94u: goto P_0c096d94;
case 0x0c096d96u: goto P_0c096d96;
case 0x0c096d98u: goto P_0c096d98;
case 0x0c096d9au: goto P_0c096d9a;
case 0x0c096d9cu: goto P_0c096d9c;
case 0x0c096d9eu: goto P_0c096d9e;
case 0x0c096da0u: goto P_0c096da0;
case 0x0c096da2u: goto P_0c096da2;
case 0x0c096da4u: goto P_0c096da4;
case 0x0c096da6u: goto P_0c096da6;
case 0x0c096da8u: goto P_0c096da8;
case 0x0c096daau: goto P_0c096daa;
case 0x0c096dacu: goto P_0c096dac;
case 0x0c096daeu: goto P_0c096dae;
case 0x0c096db0u: goto P_0c096db0;
case 0x0c096db2u: goto P_0c096db2;
case 0x0c096db4u: goto P_0c096db4;
case 0x0c096db6u: goto P_0c096db6;
case 0x0c096db8u: goto P_0c096db8;
case 0x0c096dbau: goto P_0c096dba;
case 0x0c096dbcu: goto P_0c096dbc;
case 0x0c096dbeu: goto P_0c096dbe;
case 0x0c096f74u: goto P_0c096f74;
case 0x0c096f76u: goto P_0c096f76;
case 0x0c096f78u: goto P_0c096f78;
case 0x0c096f7au: goto P_0c096f7a;
case 0x0c096f7cu: goto P_0c096f7c;
case 0x0c096f7eu: goto P_0c096f7e;
case 0x0c096f80u: goto P_0c096f80;
case 0x0c096f82u: goto P_0c096f82;
case 0x0c096f84u: goto P_0c096f84;
case 0x0c096f86u: goto P_0c096f86;
case 0x0c096f88u: goto P_0c096f88;
case 0x0c096f8au: goto P_0c096f8a;
case 0x0c096f8cu: goto P_0c096f8c;
case 0x0c096f8eu: goto P_0c096f8e;
case 0x0c096f90u: goto P_0c096f90;
case 0x0c096f92u: goto P_0c096f92;
case 0x0c096f94u: goto P_0c096f94;
case 0x0c096f96u: goto P_0c096f96;
case 0x0c0a13a4u: goto P_0c0a13a4;
case 0x0c0a13a6u: goto P_0c0a13a6;
case 0x0c0a13a8u: goto P_0c0a13a8;
case 0x0c0a13aau: goto P_0c0a13aa;
case 0x0c0a13acu: goto P_0c0a13ac;
case 0x0c0a13aeu: goto P_0c0a13ae;
case 0x0c0a13b0u: goto P_0c0a13b0;
case 0x0c0a13b2u: goto P_0c0a13b2;
case 0x0c0a13b4u: goto P_0c0a13b4;
case 0x0c0a13b6u: goto P_0c0a13b6;
case 0x0c0a13b8u: goto P_0c0a13b8;
case 0x0c0a13bau: goto P_0c0a13ba;
case 0x0c0a13bcu: goto P_0c0a13bc;
case 0x0c0a13beu: goto P_0c0a13be;
case 0x0c0a13c0u: goto P_0c0a13c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c045ba8: /* original 4f22, guest PC 0x0c045ba8 */
if(!s->budget--) { s->failed_pc=0x0c045ba8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045baa;
P_0c045baa: /* original 4618, guest PC 0x0c045baa */
if(!s->budget--) { s->failed_pc=0x0c045baau; return 0; }
r[6]<<=8;
goto P_0c045bac;
P_0c045bac: /* original e300, guest PC 0x0c045bac */
if(!s->budget--) { s->failed_pc=0x0c045bacu; return 0; }
r[3]=0x00000000u;
goto P_0c045bae;
P_0c045bae: /* original 7ff8, guest PC 0x0c045bae */
if(!s->budget--) { s->failed_pc=0x0c045baeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c045bb0;
P_0c045bb0: /* original 6ef3, guest PC 0x0c045bb0 */
if(!s->budget--) { s->failed_pc=0x0c045bb0u; return 0; }
r[14]=r[15];
goto P_0c045bb2;
P_0c045bb2: /* original e702, guest PC 0x0c045bb2 */
if(!s->budget--) { s->failed_pc=0x0c045bb2u; return 0; }
r[7]=0x00000002u;
goto P_0c045bb4;
P_0c045bb4: /* original 2e52, guest PC 0x0c045bb4 */
if(!s->budget--) { s->failed_pc=0x0c045bb4u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045bb6;
P_0c045bb6: /* original 1e61, guest PC 0x0c045bb6 */
if(!s->budget--) { s->failed_pc=0x0c045bb6u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c045bb8;
P_0c045bb8: /* original 66e3, guest PC 0x0c045bb8 */
if(!s->budget--) { s->failed_pc=0x0c045bb8u; return 0; }
r[6]=r[14];
goto P_0c045bba;
P_0c045bba: /* original 2f36, guest PC 0x0c045bba */
if(!s->budget--) { s->failed_pc=0x0c045bbau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c045bbc;
P_0c045bbc: /* original 2f36, guest PC 0x0c045bbc */
if(!s->budget--) { s->failed_pc=0x0c045bbcu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c045bbe;
P_0c045bbe: /* original b87f, guest PC 0x0c045bbe */
if(!s->budget--) { s->failed_pc=0x0c045bbeu; return 0; }
target=0x0c044cc0u; r[16]=0x0c045bc2u;
r[5]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045bc2u) { target=s->pc; goto dispatch; }
goto P_0c045bc2;
P_0c045bc0: /* original e50a, guest PC 0x0c045bc0 */
if(!s->budget--) { s->failed_pc=0x0c045bc0u; return 0; }
r[5]=0x0000000au;
goto P_0c045bc2;
P_0c045bc2: /* original 7f10, guest PC 0x0c045bc2 */
if(!s->budget--) { s->failed_pc=0x0c045bc2u; return 0; }
r[15]+=0x00000010u;
goto P_0c045bc4;
P_0c045bc4: /* original 4f26, guest PC 0x0c045bc4 */
if(!s->budget--) { s->failed_pc=0x0c045bc4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045bc6;
P_0c045bc6: /* original 000b, guest PC 0x0c045bc6 */
if(!s->budget--) { s->failed_pc=0x0c045bc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045bc8: /* original 6ef6, guest PC 0x0c045bc8 */
if(!s->budget--) { s->failed_pc=0x0c045bc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c045bcau,s,ram);
P_0c06f75a: /* original f40b, guest PC 0x0c06f75a */
if(!s->budget--) { s->failed_pc=0x0c06f75au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f75c;
P_0c06f75c: /* original 65f3, guest PC 0x0c06f75c */
if(!s->budget--) { s->failed_pc=0x0c06f75cu; return 0; }
r[5]=r[15];
goto P_0c06f75e;
P_0c06f75e: /* original 64d3, guest PC 0x0c06f75e */
if(!s->budget--) { s->failed_pc=0x0c06f75eu; return 0; }
r[4]=r[13];
goto P_0c06f760;
P_0c06f760: /* original 7538, guest PC 0x0c06f760 */
if(!s->budget--) { s->failed_pc=0x0c06f760u; return 0; }
r[5]+=0x00000038u;
goto P_0c06f762;
P_0c06f762: /* original 66c3, guest PC 0x0c06f762 */
if(!s->budget--) { s->failed_pc=0x0c06f762u; return 0; }
r[6]=r[12];
goto P_0c06f764;
P_0c06f764: /* original f059, guest PC 0x0c06f764 */
if(!s->budget--) { s->failed_pc=0x0c06f764u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f766;
P_0c06f766: /* original f369, guest PC 0x0c06f766 */
if(!s->budget--) { s->failed_pc=0x0c06f766u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f768;
P_0c06f768: /* original f159, guest PC 0x0c06f768 */
if(!s->budget--) { s->failed_pc=0x0c06f768u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76a;
P_0c06f76a: /* original f469, guest PC 0x0c06f76a */
if(!s->budget--) { s->failed_pc=0x0c06f76au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76c;
P_0c06f76c: /* original f259, guest PC 0x0c06f76c */
if(!s->budget--) { s->failed_pc=0x0c06f76cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f76e;
P_0c06f76e: /* original f569, guest PC 0x0c06f76e */
if(!s->budget--) { s->failed_pc=0x0c06f76eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f770;
P_0c06f770: /* original 740c, guest PC 0x0c06f770 */
if(!s->budget--) { s->failed_pc=0x0c06f770u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f772;
P_0c06f772: /* original f030, guest PC 0x0c06f772 */
if(!s->budget--) { s->failed_pc=0x0c06f772u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f774;
P_0c06f774: /* original f250, guest PC 0x0c06f774 */
if(!s->budget--) { s->failed_pc=0x0c06f774u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f776;
P_0c06f776: /* original f140, guest PC 0x0c06f776 */
if(!s->budget--) { s->failed_pc=0x0c06f776u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f778;
P_0c06f778: /* original f42b, guest PC 0x0c06f778 */
if(!s->budget--) { s->failed_pc=0x0c06f778u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f77a;
P_0c06f77a: /* original f41b, guest PC 0x0c06f77a */
if(!s->budget--) { s->failed_pc=0x0c06f77au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f77c;
P_0c06f77c: /* original f40b, guest PC 0x0c06f77c */
if(!s->budget--) { s->failed_pc=0x0c06f77cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f77e;
P_0c06f77e: /* original 0009, guest PC 0x0c06f77e */
if(!s->budget--) { s->failed_pc=0x0c06f77eu; return 0; }
goto P_0c06f780;
P_0c06f780: /* original 65f3, guest PC 0x0c06f780 */
if(!s->budget--) { s->failed_pc=0x0c06f780u; return 0; }
r[5]=r[15];
goto P_0c06f782;
P_0c06f782: /* original 64d3, guest PC 0x0c06f782 */
if(!s->budget--) { s->failed_pc=0x0c06f782u; return 0; }
r[4]=r[13];
goto P_0c06f784;
P_0c06f784: /* original 7550, guest PC 0x0c06f784 */
if(!s->budget--) { s->failed_pc=0x0c06f784u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f786;
P_0c06f786: /* original f449, guest PC 0x0c06f786 */
if(!s->budget--) { s->failed_pc=0x0c06f786u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f788;
P_0c06f788: /* original f549, guest PC 0x0c06f788 */
if(!s->budget--) { s->failed_pc=0x0c06f788u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f78a;
P_0c06f78a: /* original f648, guest PC 0x0c06f78a */
if(!s->budget--) { s->failed_pc=0x0c06f78au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06f78c;
P_0c06f78c: /* original f79d, guest PC 0x0c06f78c */
if(!s->budget--) { s->failed_pc=0x0c06f78cu; return 0; }
fr[7]=0x3f800000u;
goto P_0c06f78e;
P_0c06f78e: /* original f5fd, guest PC 0x0c06f78e */
if(!s->budget--) { s->failed_pc=0x0c06f78eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f790;
P_0c06f790: /* original 750c, guest PC 0x0c06f790 */
if(!s->budget--) { s->failed_pc=0x0c06f790u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f792;
P_0c06f792: /* original f56b, guest PC 0x0c06f792 */
if(!s->budget--) { s->failed_pc=0x0c06f792u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f794;
P_0c06f794: /* original f55b, guest PC 0x0c06f794 */
if(!s->budget--) { s->failed_pc=0x0c06f794u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f796;
P_0c06f796: /* original f54b, guest PC 0x0c06f796 */
if(!s->budget--) { s->failed_pc=0x0c06f796u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f798;
P_0c06f798: /* original 64f3, guest PC 0x0c06f798 */
if(!s->budget--) { s->failed_pc=0x0c06f798u; return 0; }
r[4]=r[15];
goto P_0c06f79a;
P_0c06f79a: /* original 65f3, guest PC 0x0c06f79a */
if(!s->budget--) { s->failed_pc=0x0c06f79au; return 0; }
r[5]=r[15];
goto P_0c06f79c;
P_0c06f79c: /* original 745c, guest PC 0x0c06f79c */
if(!s->budget--) { s->failed_pc=0x0c06f79cu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f79e;
P_0c06f79e: /* original 66d3, guest PC 0x0c06f79e */
if(!s->budget--) { s->failed_pc=0x0c06f79eu; return 0; }
r[6]=r[13];
goto P_0c06f7a0;
P_0c06f7a0: /* original 7550, guest PC 0x0c06f7a0 */
if(!s->budget--) { s->failed_pc=0x0c06f7a0u; return 0; }
r[5]+=0x00000050u;
goto P_0c06f7a2;
P_0c06f7a2: /* original f059, guest PC 0x0c06f7a2 */
if(!s->budget--) { s->failed_pc=0x0c06f7a2u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a4;
P_0c06f7a4: /* original f369, guest PC 0x0c06f7a4 */
if(!s->budget--) { s->failed_pc=0x0c06f7a4u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a6;
P_0c06f7a6: /* original f159, guest PC 0x0c06f7a6 */
if(!s->budget--) { s->failed_pc=0x0c06f7a6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7a8;
P_0c06f7a8: /* original f469, guest PC 0x0c06f7a8 */
if(!s->budget--) { s->failed_pc=0x0c06f7a8u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7aa;
P_0c06f7aa: /* original f031, guest PC 0x0c06f7aa */
if(!s->budget--) { s->failed_pc=0x0c06f7aau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f7ac;
P_0c06f7ac: /* original f258, guest PC 0x0c06f7ac */
if(!s->budget--) { s->failed_pc=0x0c06f7acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c06f7ae;
P_0c06f7ae: /* original f568, guest PC 0x0c06f7ae */
if(!s->budget--) { s->failed_pc=0x0c06f7aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c06f7b0;
P_0c06f7b0: /* original f141, guest PC 0x0c06f7b0 */
if(!s->budget--) { s->failed_pc=0x0c06f7b0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f7b2;
P_0c06f7b2: /* original f251, guest PC 0x0c06f7b2 */
if(!s->budget--) { s->failed_pc=0x0c06f7b2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f7b4;
P_0c06f7b4: /* original 7408, guest PC 0x0c06f7b4 */
if(!s->budget--) { s->failed_pc=0x0c06f7b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c06f7b6;
P_0c06f7b6: /* original f42a, guest PC 0x0c06f7b6 */
if(!s->budget--) { s->failed_pc=0x0c06f7b6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7b8;
P_0c06f7b8: /* original f41b, guest PC 0x0c06f7b8 */
if(!s->budget--) { s->failed_pc=0x0c06f7b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7ba;
P_0c06f7ba: /* original f40b, guest PC 0x0c06f7ba */
if(!s->budget--) { s->failed_pc=0x0c06f7bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7bc;
P_0c06f7bc: /* original 64f3, guest PC 0x0c06f7bc */
if(!s->budget--) { s->failed_pc=0x0c06f7bcu; return 0; }
r[4]=r[15];
goto P_0c06f7be;
P_0c06f7be: /* original 65f3, guest PC 0x0c06f7be */
if(!s->budget--) { s->failed_pc=0x0c06f7beu; return 0; }
r[5]=r[15];
goto P_0c06f7c0;
P_0c06f7c0: /* original 745c, guest PC 0x0c06f7c0 */
if(!s->budget--) { s->failed_pc=0x0c06f7c0u; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7c2;
P_0c06f7c2: /* original f4dc, guest PC 0x0c06f7c2 */
if(!s->budget--) { s->failed_pc=0x0c06f7c2u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06f7c4;
P_0c06f7c4: /* original 755c, guest PC 0x0c06f7c4 */
if(!s->budget--) { s->failed_pc=0x0c06f7c4u; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7c6;
P_0c06f7c6: /* original f059, guest PC 0x0c06f7c6 */
if(!s->budget--) { s->failed_pc=0x0c06f7c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7c8;
P_0c06f7c8: /* original f159, guest PC 0x0c06f7c8 */
if(!s->budget--) { s->failed_pc=0x0c06f7c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7ca;
P_0c06f7ca: /* original f259, guest PC 0x0c06f7ca */
if(!s->budget--) { s->failed_pc=0x0c06f7cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7cc;
P_0c06f7cc: /* original 740c, guest PC 0x0c06f7cc */
if(!s->budget--) { s->failed_pc=0x0c06f7ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f7ce;
P_0c06f7ce: /* original f242, guest PC 0x0c06f7ce */
if(!s->budget--) { s->failed_pc=0x0c06f7ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c06f7d0;
P_0c06f7d0: /* original f142, guest PC 0x0c06f7d0 */
if(!s->budget--) { s->failed_pc=0x0c06f7d0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c06f7d2;
P_0c06f7d2: /* original f042, guest PC 0x0c06f7d2 */
if(!s->budget--) { s->failed_pc=0x0c06f7d2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c06f7d4;
P_0c06f7d4: /* original f42b, guest PC 0x0c06f7d4 */
if(!s->budget--) { s->failed_pc=0x0c06f7d4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f7d6;
P_0c06f7d6: /* original f41b, guest PC 0x0c06f7d6 */
if(!s->budget--) { s->failed_pc=0x0c06f7d6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f7d8;
P_0c06f7d8: /* original f40b, guest PC 0x0c06f7d8 */
if(!s->budget--) { s->failed_pc=0x0c06f7d8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f7da;
P_0c06f7da: /* original 0009, guest PC 0x0c06f7da */
if(!s->budget--) { s->failed_pc=0x0c06f7dau; return 0; }
goto P_0c06f7dc;
P_0c06f7dc: /* original 64f3, guest PC 0x0c06f7dc */
if(!s->budget--) { s->failed_pc=0x0c06f7dcu; return 0; }
r[4]=r[15];
goto P_0c06f7de;
P_0c06f7de: /* original 745c, guest PC 0x0c06f7de */
if(!s->budget--) { s->failed_pc=0x0c06f7deu; return 0; }
r[4]+=0x0000005cu;
goto P_0c06f7e0;
P_0c06f7e0: /* original f049, guest PC 0x0c06f7e0 */
if(!s->budget--) { s->failed_pc=0x0c06f7e0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e2;
P_0c06f7e2: /* original f149, guest PC 0x0c06f7e2 */
if(!s->budget--) { s->failed_pc=0x0c06f7e2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e4;
P_0c06f7e4: /* original f249, guest PC 0x0c06f7e4 */
if(!s->budget--) { s->failed_pc=0x0c06f7e4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7e6;
P_0c06f7e6: /* original f38d, guest PC 0x0c06f7e6 */
if(!s->budget--) { s->failed_pc=0x0c06f7e6u; return 0; }
fr[3]=0;
goto P_0c06f7e8;
P_0c06f7e8: /* original f0ed, guest PC 0x0c06f7e8 */
if(!s->budget--) { s->failed_pc=0x0c06f7e8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f7ea;
P_0c06f7ea: /* original f03c, guest PC 0x0c06f7ea */
if(!s->budget--) { s->failed_pc=0x0c06f7eau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c06f7ec;
P_0c06f7ec: /* original f06d, guest PC 0x0c06f7ec */
if(!s->budget--) { s->failed_pc=0x0c06f7ecu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c06f7ee;
P_0c06f7ee: /* original 0009, guest PC 0x0c06f7ee */
if(!s->budget--) { s->failed_pc=0x0c06f7eeu; return 0; }
goto P_0c06f7f0;
P_0c06f7f0: /* original 65f3, guest PC 0x0c06f7f0 */
if(!s->budget--) { s->failed_pc=0x0c06f7f0u; return 0; }
r[5]=r[15];
goto P_0c06f7f2;
P_0c06f7f2: /* original 64f3, guest PC 0x0c06f7f2 */
if(!s->budget--) { s->failed_pc=0x0c06f7f2u; return 0; }
r[4]=r[15];
goto P_0c06f7f4;
P_0c06f7f4: /* original 66f3, guest PC 0x0c06f7f4 */
if(!s->budget--) { s->failed_pc=0x0c06f7f4u; return 0; }
r[6]=r[15];
goto P_0c06f7f6;
P_0c06f7f6: /* original 7444, guest PC 0x0c06f7f6 */
if(!s->budget--) { s->failed_pc=0x0c06f7f6u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f7f8;
P_0c06f7f8: /* original 7668, guest PC 0x0c06f7f8 */
if(!s->budget--) { s->failed_pc=0x0c06f7f8u; return 0; }
r[6]+=0x00000068u;
goto P_0c06f7fa;
P_0c06f7fa: /* original 755c, guest PC 0x0c06f7fa */
if(!s->budget--) { s->failed_pc=0x0c06f7fau; return 0; }
r[5]+=0x0000005cu;
goto P_0c06f7fc;
P_0c06f7fc: /* original f059, guest PC 0x0c06f7fc */
if(!s->budget--) { s->failed_pc=0x0c06f7fcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f7fe;
P_0c06f7fe: /* original f369, guest PC 0x0c06f7fe */
if(!s->budget--) { s->failed_pc=0x0c06f7feu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f800;
P_0c06f800: /* original f159, guest PC 0x0c06f800 */
if(!s->budget--) { s->failed_pc=0x0c06f800u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f802;
P_0c06f802: /* original f469, guest PC 0x0c06f802 */
if(!s->budget--) { s->failed_pc=0x0c06f802u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f804;
P_0c06f804: /* original f259, guest PC 0x0c06f804 */
if(!s->budget--) { s->failed_pc=0x0c06f804u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f806;
P_0c06f806: /* original f569, guest PC 0x0c06f806 */
if(!s->budget--) { s->failed_pc=0x0c06f806u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f808;
P_0c06f808: /* original 740c, guest PC 0x0c06f808 */
if(!s->budget--) { s->failed_pc=0x0c06f808u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f80a;
P_0c06f80a: /* original f030, guest PC 0x0c06f80a */
if(!s->budget--) { s->failed_pc=0x0c06f80au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f80c;
P_0c06f80c: /* original f250, guest PC 0x0c06f80c */
if(!s->budget--) { s->failed_pc=0x0c06f80cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f80e;
P_0c06f80e: /* original f140, guest PC 0x0c06f80e */
if(!s->budget--) { s->failed_pc=0x0c06f80eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f810;
P_0c06f810: /* original f42b, guest PC 0x0c06f810 */
if(!s->budget--) { s->failed_pc=0x0c06f810u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f812;
P_0c06f812: /* original f41b, guest PC 0x0c06f812 */
if(!s->budget--) { s->failed_pc=0x0c06f812u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f814;
P_0c06f814: /* original f40b, guest PC 0x0c06f814 */
if(!s->budget--) { s->failed_pc=0x0c06f814u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f816;
P_0c06f816: /* original 0009, guest PC 0x0c06f816 */
if(!s->budget--) { s->failed_pc=0x0c06f816u; return 0; }
goto P_0c06f818;
P_0c06f818: /* original e038, guest PC 0x0c06f818 */
if(!s->budget--) { s->failed_pc=0x0c06f818u; return 0; }
r[0]=0x00000038u;
goto P_0c06f81a;
P_0c06f81a: /* original 65f3, guest PC 0x0c06f81a */
if(!s->budget--) { s->failed_pc=0x0c06f81au; return 0; }
r[5]=r[15];
goto P_0c06f81c;
P_0c06f81c: /* original f3f6, guest PC 0x0c06f81c */
if(!s->budget--) { s->failed_pc=0x0c06f81cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f81e;
P_0c06f81e: /* original e02c, guest PC 0x0c06f81e */
if(!s->budget--) { s->failed_pc=0x0c06f81eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06f820;
P_0c06f820: /* original 64f3, guest PC 0x0c06f820 */
if(!s->budget--) { s->failed_pc=0x0c06f820u; return 0; }
r[4]=r[15];
goto P_0c06f822;
P_0c06f822: /* original 742c, guest PC 0x0c06f822 */
if(!s->budget--) { s->failed_pc=0x0c06f822u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f824;
P_0c06f824: /* original ff37, guest PC 0x0c06f824 */
if(!s->budget--) { s->failed_pc=0x0c06f824u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f826;
P_0c06f826: /* original e03c, guest PC 0x0c06f826 */
if(!s->budget--) { s->failed_pc=0x0c06f826u; return 0; }
r[0]=0x0000003cu;
goto P_0c06f828;
P_0c06f828: /* original f3f6, guest PC 0x0c06f828 */
if(!s->budget--) { s->failed_pc=0x0c06f828u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f82a;
P_0c06f82a: /* original e030, guest PC 0x0c06f82a */
if(!s->budget--) { s->failed_pc=0x0c06f82au; return 0; }
r[0]=0x00000030u;
goto P_0c06f82c;
P_0c06f82c: /* original 7544, guest PC 0x0c06f82c */
if(!s->budget--) { s->failed_pc=0x0c06f82cu; return 0; }
r[5]+=0x00000044u;
goto P_0c06f82e;
P_0c06f82e: /* original ff37, guest PC 0x0c06f82e */
if(!s->budget--) { s->failed_pc=0x0c06f82eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f830;
P_0c06f830: /* original e040, guest PC 0x0c06f830 */
if(!s->budget--) { s->failed_pc=0x0c06f830u; return 0; }
r[0]=0x00000040u;
goto P_0c06f832;
P_0c06f832: /* original f3f6, guest PC 0x0c06f832 */
if(!s->budget--) { s->failed_pc=0x0c06f832u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f834;
P_0c06f834: /* original e034, guest PC 0x0c06f834 */
if(!s->budget--) { s->failed_pc=0x0c06f834u; return 0; }
r[0]=0x00000034u;
goto P_0c06f836;
P_0c06f836: /* original ff37, guest PC 0x0c06f836 */
if(!s->budget--) { s->failed_pc=0x0c06f836u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f838;
P_0c06f838: /* original f049, guest PC 0x0c06f838 */
if(!s->budget--) { s->failed_pc=0x0c06f838u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83a;
P_0c06f83a: /* original f149, guest PC 0x0c06f83a */
if(!s->budget--) { s->failed_pc=0x0c06f83au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83c;
P_0c06f83c: /* original f249, guest PC 0x0c06f83c */
if(!s->budget--) { s->failed_pc=0x0c06f83cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83e;
P_0c06f83e: /* original f38d, guest PC 0x0c06f83e */
if(!s->budget--) { s->failed_pc=0x0c06f83eu; return 0; }
fr[3]=0;
goto P_0c06f840;
P_0c06f840: /* original f459, guest PC 0x0c06f840 */
if(!s->budget--) { s->failed_pc=0x0c06f840u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f842;
P_0c06f842: /* original f559, guest PC 0x0c06f842 */
if(!s->budget--) { s->failed_pc=0x0c06f842u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f844;
P_0c06f844: /* original f659, guest PC 0x0c06f844 */
if(!s->budget--) { s->failed_pc=0x0c06f844u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f846;
P_0c06f846: /* original f78d, guest PC 0x0c06f846 */
if(!s->budget--) { s->failed_pc=0x0c06f846u; return 0; }
fr[7]=0;
goto P_0c06f848;
P_0c06f848: /* original f4ed, guest PC 0x0c06f848 */
if(!s->budget--) { s->failed_pc=0x0c06f848u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c06f84a;
P_0c06f84a: /* original f07c, guest PC 0x0c06f84a */
if(!s->budget--) { s->failed_pc=0x0c06f84au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06f84c;
P_0c06f84c: /* original 64f3, guest PC 0x0c06f84c */
if(!s->budget--) { s->failed_pc=0x0c06f84cu; return 0; }
r[4]=r[15];
goto P_0c06f84e;
P_0c06f84e: /* original 65f3, guest PC 0x0c06f84e */
if(!s->budget--) { s->failed_pc=0x0c06f84eu; return 0; }
r[5]=r[15];
goto P_0c06f850;
P_0c06f850: /* original 7420, guest PC 0x0c06f850 */
if(!s->budget--) { s->failed_pc=0x0c06f850u; return 0; }
r[4]+=0x00000020u;
goto P_0c06f852;
P_0c06f852: /* original f40c, guest PC 0x0c06f852 */
if(!s->budget--) { s->failed_pc=0x0c06f852u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06f854;
P_0c06f854: /* original 752c, guest PC 0x0c06f854 */
if(!s->budget--) { s->failed_pc=0x0c06f854u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f856;
P_0c06f856: /* original f059, guest PC 0x0c06f856 */
if(!s->budget--) { s->failed_pc=0x0c06f856u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f858;
P_0c06f858: /* original f159, guest PC 0x0c06f858 */
if(!s->budget--) { s->failed_pc=0x0c06f858u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85a;
P_0c06f85a: /* original f259, guest PC 0x0c06f85a */
if(!s->budget--) { s->failed_pc=0x0c06f85au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85c;
P_0c06f85c: /* original f38d, guest PC 0x0c06f85c */
if(!s->budget--) { s->failed_pc=0x0c06f85cu; return 0; }
fr[3]=0;
goto P_0c06f85e;
P_0c06f85e: /* original f0ed, guest PC 0x0c06f85e */
if(!s->budget--) { s->failed_pc=0x0c06f85eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f860;
P_0c06f860: /* original f37d, guest PC 0x0c06f860 */
if(!s->budget--) { s->failed_pc=0x0c06f860u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f862;
P_0c06f862: /* original f342, guest PC 0x0c06f862 */
if(!s->budget--) { s->failed_pc=0x0c06f862u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f864;
P_0c06f864: /* original 740c, guest PC 0x0c06f864 */
if(!s->budget--) { s->failed_pc=0x0c06f864u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f866;
P_0c06f866: /* original f232, guest PC 0x0c06f866 */
if(!s->budget--) { s->failed_pc=0x0c06f866u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f868;
P_0c06f868: /* original f132, guest PC 0x0c06f868 */
if(!s->budget--) { s->failed_pc=0x0c06f868u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f86a;
P_0c06f86a: /* original f032, guest PC 0x0c06f86a */
if(!s->budget--) { s->failed_pc=0x0c06f86au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f86c;
P_0c06f86c: /* original f42b, guest PC 0x0c06f86c */
if(!s->budget--) { s->failed_pc=0x0c06f86cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f86e;
P_0c06f86e: /* original f41b, guest PC 0x0c06f86e */
if(!s->budget--) { s->failed_pc=0x0c06f86eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f870;
P_0c06f870: /* original f40b, guest PC 0x0c06f870 */
if(!s->budget--) { s->failed_pc=0x0c06f870u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f872;
P_0c06f872: /* original 0009, guest PC 0x0c06f872 */
if(!s->budget--) { s->failed_pc=0x0c06f872u; return 0; }
goto P_0c06f874;
P_0c06f874: /* original 64f3, guest PC 0x0c06f874 */
if(!s->budget--) { s->failed_pc=0x0c06f874u; return 0; }
r[4]=r[15];
goto P_0c06f876;
P_0c06f876: /* original 65f3, guest PC 0x0c06f876 */
if(!s->budget--) { s->failed_pc=0x0c06f876u; return 0; }
r[5]=r[15];
goto P_0c06f878;
P_0c06f878: /* original 7444, guest PC 0x0c06f878 */
if(!s->budget--) { s->failed_pc=0x0c06f878u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f87a;
P_0c06f87a: /* original 7520, guest PC 0x0c06f87a */
if(!s->budget--) { s->failed_pc=0x0c06f87au; return 0; }
r[5]+=0x00000020u;
goto P_0c06f87c;
P_0c06f87c: /* original f049, guest PC 0x0c06f87c */
if(!s->budget--) { s->failed_pc=0x0c06f87cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f87e;
P_0c06f87e: /* original f359, guest PC 0x0c06f87e */
if(!s->budget--) { s->failed_pc=0x0c06f87eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f880;
P_0c06f880: /* original f149, guest PC 0x0c06f880 */
if(!s->budget--) { s->failed_pc=0x0c06f880u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f882;
P_0c06f882: /* original f459, guest PC 0x0c06f882 */
if(!s->budget--) { s->failed_pc=0x0c06f882u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f884;
P_0c06f884: /* original f249, guest PC 0x0c06f884 */
if(!s->budget--) { s->failed_pc=0x0c06f884u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f886;
P_0c06f886: /* original f559, guest PC 0x0c06f886 */
if(!s->budget--) { s->failed_pc=0x0c06f886u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f888;
P_0c06f888: /* original f031, guest PC 0x0c06f888 */
if(!s->budget--) { s->failed_pc=0x0c06f888u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f88a;
P_0c06f88a: /* original f251, guest PC 0x0c06f88a */
if(!s->budget--) { s->failed_pc=0x0c06f88au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f88c;
P_0c06f88c: /* original f141, guest PC 0x0c06f88c */
if(!s->budget--) { s->failed_pc=0x0c06f88cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f88e;
P_0c06f88e: /* original f42b, guest PC 0x0c06f88e */
if(!s->budget--) { s->failed_pc=0x0c06f88eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f890;
P_0c06f890: /* original f41b, guest PC 0x0c06f890 */
if(!s->budget--) { s->failed_pc=0x0c06f890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f892;
P_0c06f892: /* original f40b, guest PC 0x0c06f892 */
if(!s->budget--) { s->failed_pc=0x0c06f892u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f894;
P_0c06f894: /* original 65f3, guest PC 0x0c06f894 */
if(!s->budget--) { s->failed_pc=0x0c06f894u; return 0; }
r[5]=r[15];
goto P_0c06f896;
P_0c06f896: /* original 64f3, guest PC 0x0c06f896 */
if(!s->budget--) { s->failed_pc=0x0c06f896u; return 0; }
r[4]=r[15];
goto P_0c06f898;
P_0c06f898: /* original 66f3, guest PC 0x0c06f898 */
if(!s->budget--) { s->failed_pc=0x0c06f898u; return 0; }
r[6]=r[15];
goto P_0c06f89a;
P_0c06f89a: /* original 742c, guest PC 0x0c06f89a */
if(!s->budget--) { s->failed_pc=0x0c06f89au; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f89c;
P_0c06f89c: /* original 7644, guest PC 0x0c06f89c */
if(!s->budget--) { s->failed_pc=0x0c06f89cu; return 0; }
r[6]+=0x00000044u;
goto P_0c06f89e;
P_0c06f89e: /* original 7538, guest PC 0x0c06f89e */
if(!s->budget--) { s->failed_pc=0x0c06f89eu; return 0; }
r[5]+=0x00000038u;
goto P_0c06f8a0;
P_0c06f8a0: /* original f059, guest PC 0x0c06f8a0 */
if(!s->budget--) { s->failed_pc=0x0c06f8a0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a2;
P_0c06f8a2: /* original f369, guest PC 0x0c06f8a2 */
if(!s->budget--) { s->failed_pc=0x0c06f8a2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a4;
P_0c06f8a4: /* original f159, guest PC 0x0c06f8a4 */
if(!s->budget--) { s->failed_pc=0x0c06f8a4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a6;
P_0c06f8a6: /* original f469, guest PC 0x0c06f8a6 */
if(!s->budget--) { s->failed_pc=0x0c06f8a6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a8;
P_0c06f8a8: /* original f259, guest PC 0x0c06f8a8 */
if(!s->budget--) { s->failed_pc=0x0c06f8a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8aa;
P_0c06f8aa: /* original f569, guest PC 0x0c06f8aa */
if(!s->budget--) { s->failed_pc=0x0c06f8aau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ac;
P_0c06f8ac: /* original 740c, guest PC 0x0c06f8ac */
if(!s->budget--) { s->failed_pc=0x0c06f8acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8ae;
P_0c06f8ae: /* original f030, guest PC 0x0c06f8ae */
if(!s->budget--) { s->failed_pc=0x0c06f8aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8b0;
P_0c06f8b0: /* original f250, guest PC 0x0c06f8b0 */
if(!s->budget--) { s->failed_pc=0x0c06f8b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f8b2;
P_0c06f8b2: /* original f140, guest PC 0x0c06f8b2 */
if(!s->budget--) { s->failed_pc=0x0c06f8b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f8b4;
P_0c06f8b4: /* original f42b, guest PC 0x0c06f8b4 */
if(!s->budget--) { s->failed_pc=0x0c06f8b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8b6;
P_0c06f8b6: /* original f41b, guest PC 0x0c06f8b6 */
if(!s->budget--) { s->failed_pc=0x0c06f8b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8b8;
P_0c06f8b8: /* original f40b, guest PC 0x0c06f8b8 */
if(!s->budget--) { s->failed_pc=0x0c06f8b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8ba;
P_0c06f8ba: /* original 0009, guest PC 0x0c06f8ba */
if(!s->budget--) { s->failed_pc=0x0c06f8bau; return 0; }
goto P_0c06f8bc;
P_0c06f8bc: /* original 64f3, guest PC 0x0c06f8bc */
if(!s->budget--) { s->failed_pc=0x0c06f8bcu; return 0; }
r[4]=r[15];
goto P_0c06f8be;
P_0c06f8be: /* original 65f3, guest PC 0x0c06f8be */
if(!s->budget--) { s->failed_pc=0x0c06f8beu; return 0; }
r[5]=r[15];
goto P_0c06f8c0;
P_0c06f8c0: /* original 742c, guest PC 0x0c06f8c0 */
if(!s->budget--) { s->failed_pc=0x0c06f8c0u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f8c2;
P_0c06f8c2: /* original f4ec, guest PC 0x0c06f8c2 */
if(!s->budget--) { s->failed_pc=0x0c06f8c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f8c4;
P_0c06f8c4: /* original 752c, guest PC 0x0c06f8c4 */
if(!s->budget--) { s->failed_pc=0x0c06f8c4u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f8c6;
P_0c06f8c6: /* original f059, guest PC 0x0c06f8c6 */
if(!s->budget--) { s->failed_pc=0x0c06f8c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8c8;
P_0c06f8c8: /* original f159, guest PC 0x0c06f8c8 */
if(!s->budget--) { s->failed_pc=0x0c06f8c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ca;
P_0c06f8ca: /* original f259, guest PC 0x0c06f8ca */
if(!s->budget--) { s->failed_pc=0x0c06f8cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8cc;
P_0c06f8cc: /* original f38d, guest PC 0x0c06f8cc */
if(!s->budget--) { s->failed_pc=0x0c06f8ccu; return 0; }
fr[3]=0;
goto P_0c06f8ce;
P_0c06f8ce: /* original f0ed, guest PC 0x0c06f8ce */
if(!s->budget--) { s->failed_pc=0x0c06f8ceu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f8d0;
P_0c06f8d0: /* original f37d, guest PC 0x0c06f8d0 */
if(!s->budget--) { s->failed_pc=0x0c06f8d0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f8d2;
P_0c06f8d2: /* original f342, guest PC 0x0c06f8d2 */
if(!s->budget--) { s->failed_pc=0x0c06f8d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f8d4;
P_0c06f8d4: /* original 740c, guest PC 0x0c06f8d4 */
if(!s->budget--) { s->failed_pc=0x0c06f8d4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8d6;
P_0c06f8d6: /* original f232, guest PC 0x0c06f8d6 */
if(!s->budget--) { s->failed_pc=0x0c06f8d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f8d8;
P_0c06f8d8: /* original f132, guest PC 0x0c06f8d8 */
if(!s->budget--) { s->failed_pc=0x0c06f8d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f8da;
P_0c06f8da: /* original f032, guest PC 0x0c06f8da */
if(!s->budget--) { s->failed_pc=0x0c06f8dau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f8dc;
P_0c06f8dc: /* original f42b, guest PC 0x0c06f8dc */
if(!s->budget--) { s->failed_pc=0x0c06f8dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8de;
P_0c06f8de: /* original f41b, guest PC 0x0c06f8de */
if(!s->budget--) { s->failed_pc=0x0c06f8deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8e0;
P_0c06f8e0: /* original f40b, guest PC 0x0c06f8e0 */
if(!s->budget--) { s->failed_pc=0x0c06f8e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8e2;
P_0c06f8e2: /* original 0009, guest PC 0x0c06f8e2 */
if(!s->budget--) { s->failed_pc=0x0c06f8e2u; return 0; }
goto P_0c06f8e4;
P_0c06f8e4: /* original 64f3, guest PC 0x0c06f8e4 */
if(!s->budget--) { s->failed_pc=0x0c06f8e4u; return 0; }
r[4]=r[15];
goto P_0c06f8e6;
P_0c06f8e6: /* original 66f3, guest PC 0x0c06f8e6 */
if(!s->budget--) { s->failed_pc=0x0c06f8e6u; return 0; }
r[6]=r[15];
goto P_0c06f8e8;
P_0c06f8e8: /* original 7450, guest PC 0x0c06f8e8 */
if(!s->budget--) { s->failed_pc=0x0c06f8e8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06f8ea;
P_0c06f8ea: /* original 65c3, guest PC 0x0c06f8ea */
if(!s->budget--) { s->failed_pc=0x0c06f8eau; return 0; }
r[5]=r[12];
goto P_0c06f8ec;
P_0c06f8ec: /* original 762c, guest PC 0x0c06f8ec */
if(!s->budget--) { s->failed_pc=0x0c06f8ecu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f8ee;
P_0c06f8ee: /* original f059, guest PC 0x0c06f8ee */
if(!s->budget--) { s->failed_pc=0x0c06f8eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f0;
P_0c06f8f0: /* original f369, guest PC 0x0c06f8f0 */
if(!s->budget--) { s->failed_pc=0x0c06f8f0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f2;
P_0c06f8f2: /* original f159, guest PC 0x0c06f8f2 */
if(!s->budget--) { s->failed_pc=0x0c06f8f2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f4;
P_0c06f8f4: /* original f469, guest PC 0x0c06f8f4 */
if(!s->budget--) { s->failed_pc=0x0c06f8f4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f6;
P_0c06f8f6: /* original f259, guest PC 0x0c06f8f6 */
if(!s->budget--) { s->failed_pc=0x0c06f8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f8;
P_0c06f8f8: /* original f569, guest PC 0x0c06f8f8 */
if(!s->budget--) { s->failed_pc=0x0c06f8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8fa;
P_0c06f8fa: /* original 740c, guest PC 0x0c06f8fa */
if(!s->budget--) { s->failed_pc=0x0c06f8fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8fc;
P_0c06f8fc: /* original f030, guest PC 0x0c06f8fc */
if(!s->budget--) { s->failed_pc=0x0c06f8fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8fe;
P_0c06f8fe: /* original f250, guest PC 0x0c06f8fe */
if(!s->budget--) { s->failed_pc=0x0c06f8feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f900;
P_0c06f900: /* original f140, guest PC 0x0c06f900 */
if(!s->budget--) { s->failed_pc=0x0c06f900u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f902;
P_0c06f902: /* original f42b, guest PC 0x0c06f902 */
if(!s->budget--) { s->failed_pc=0x0c06f902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f904;
P_0c06f904: /* original f41b, guest PC 0x0c06f904 */
if(!s->budget--) { s->failed_pc=0x0c06f904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f906;
P_0c06f906: /* original f40b, guest PC 0x0c06f906 */
if(!s->budget--) { s->failed_pc=0x0c06f906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f908;
P_0c06f908: /* original 66f3, guest PC 0x0c06f908 */
if(!s->budget--) { s->failed_pc=0x0c06f908u; return 0; }
r[6]=r[15];
goto P_0c06f90a;
P_0c06f90a: /* original 64d3, guest PC 0x0c06f90a */
if(!s->budget--) { s->failed_pc=0x0c06f90au; return 0; }
r[4]=r[13];
goto P_0c06f90c;
P_0c06f90c: /* original 65c3, guest PC 0x0c06f90c */
if(!s->budget--) { s->failed_pc=0x0c06f90cu; return 0; }
r[5]=r[12];
goto P_0c06f90e;
P_0c06f90e: /* original 762c, guest PC 0x0c06f90e */
if(!s->budget--) { s->failed_pc=0x0c06f90eu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f910;
P_0c06f910: /* original f059, guest PC 0x0c06f910 */
if(!s->budget--) { s->failed_pc=0x0c06f910u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f912;
P_0c06f912: /* original f369, guest PC 0x0c06f912 */
if(!s->budget--) { s->failed_pc=0x0c06f912u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f914;
P_0c06f914: /* original f159, guest PC 0x0c06f914 */
if(!s->budget--) { s->failed_pc=0x0c06f914u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f916;
P_0c06f916: /* original f469, guest PC 0x0c06f916 */
if(!s->budget--) { s->failed_pc=0x0c06f916u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f918;
P_0c06f918: /* original f259, guest PC 0x0c06f918 */
if(!s->budget--) { s->failed_pc=0x0c06f918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91a;
P_0c06f91a: /* original f569, guest PC 0x0c06f91a */
if(!s->budget--) { s->failed_pc=0x0c06f91au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91c;
P_0c06f91c: /* original 740c, guest PC 0x0c06f91c */
if(!s->budget--) { s->failed_pc=0x0c06f91cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f91e;
P_0c06f91e: /* original f030, guest PC 0x0c06f91e */
if(!s->budget--) { s->failed_pc=0x0c06f91eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f920;
P_0c06f920: /* original f250, guest PC 0x0c06f920 */
if(!s->budget--) { s->failed_pc=0x0c06f920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f922;
P_0c06f922: /* original f140, guest PC 0x0c06f922 */
if(!s->budget--) { s->failed_pc=0x0c06f922u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f924;
P_0c06f924: /* original f42b, guest PC 0x0c06f924 */
if(!s->budget--) { s->failed_pc=0x0c06f924u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f926;
P_0c06f926: /* original f41b, guest PC 0x0c06f926 */
if(!s->budget--) { s->failed_pc=0x0c06f926u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f928;
P_0c06f928: /* original f40b, guest PC 0x0c06f928 */
if(!s->budget--) { s->failed_pc=0x0c06f928u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f92a;
P_0c06f92a: /* original 0009, guest PC 0x0c06f92a */
if(!s->budget--) { s->failed_pc=0x0c06f92au; return 0; }
goto P_0c06f92c;
P_0c06f92c: /* original 7901, guest PC 0x0c06f92c */
if(!s->budget--) { s->failed_pc=0x0c06f92cu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f92e;
P_0c06f92e: /* original 39a3, guest PC 0x0c06f92e */
if(!s->budget--) { s->failed_pc=0x0c06f92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c06f930;
P_0c06f930: /* original 7d18, guest PC 0x0c06f930 */
if(!s->budget--) { s->failed_pc=0x0c06f930u; return 0; }
r[13]+=0x00000018u;
goto P_0c06f932;
P_0c06f932: /* original 8d03, guest PC 0x0c06f932 */
if(!s->budget--) { s->failed_pc=0x0c06f932u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000018u;
if(cond) { goto P_0c06f93c; }
goto P_0c06f936;
P_0c06f934: /* original 7c18, guest PC 0x0c06f934 */
if(!s->budget--) { s->failed_pc=0x0c06f934u; return 0; }
r[12]+=0x00000018u;
goto P_0c06f936;
P_0c06f936: /* original d234, guest PC 0x0c06f936 */
if(!s->budget--) { s->failed_pc=0x0c06f936u; return 0; }
r[2]=read(ram,0x0c06fa08u,4);
goto P_0c06f938;
P_0c06f938: /* original 422b, guest PC 0x0c06f938 */
if(!s->budget--) { s->failed_pc=0x0c06f938u; return 0; }
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
P_0c06f93a: /* original 0009, guest PC 0x0c06f93a */
if(!s->budget--) { s->failed_pc=0x0c06f93au; return 0; }
goto P_0c06f93c;
P_0c06f93c: /* original d333, guest PC 0x0c06f93c */
if(!s->budget--) { s->failed_pc=0x0c06f93cu; return 0; }
r[3]=read(ram,0x0c06fa0cu,4);
goto P_0c06f93e;
P_0c06f93e: /* original 65e3, guest PC 0x0c06f93e */
if(!s->budget--) { s->failed_pc=0x0c06f93eu; return 0; }
r[5]=r[14];
goto P_0c06f940;
P_0c06f940: /* original 6783, guest PC 0x0c06f940 */
if(!s->budget--) { s->failed_pc=0x0c06f940u; return 0; }
r[7]=r[8];
goto P_0c06f942;
P_0c06f942: /* original 66d3, guest PC 0x0c06f942 */
if(!s->budget--) { s->failed_pc=0x0c06f942u; return 0; }
r[6]=r[13];
goto P_0c06f944;
P_0c06f944: /* original 430b, guest PC 0x0c06f944 */
if(!s->budget--) { s->failed_pc=0x0c06f944u; return 0; }
target=r[3];
r[16]=0x0c06f948u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f948u) { target=s->pc; goto dispatch; }
goto P_0c06f948;
P_0c06f946: /* original 64b3, guest PC 0x0c06f946 */
if(!s->budget--) { s->failed_pc=0x0c06f946u; return 0; }
r[4]=r[11];
goto P_0c06f948;
P_0c06f948: /* original 7801, guest PC 0x0c06f948 */
if(!s->budget--) { s->failed_pc=0x0c06f948u; return 0; }
r[8]+=0x00000001u;
goto P_0c06f94a;
P_0c06f94a: /* original 52f1, guest PC 0x0c06f94a */
if(!s->budget--) { s->failed_pc=0x0c06f94au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06f94c;
P_0c06f94c: /* original 3823, guest PC 0x0c06f94c */
if(!s->budget--) { s->failed_pc=0x0c06f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c06f94e;
P_0c06f94e: /* original 8902, guest PC 0x0c06f94e */
if(!s->budget--) { s->failed_pc=0x0c06f94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f956; }
goto P_0c06f950;
P_0c06f950: /* original d32f, guest PC 0x0c06f950 */
if(!s->budget--) { s->failed_pc=0x0c06f950u; return 0; }
r[3]=read(ram,0x0c06fa10u,4);
goto P_0c06f952;
P_0c06f952: /* original 432b, guest PC 0x0c06f952 */
if(!s->budget--) { s->failed_pc=0x0c06f952u; return 0; }
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
P_0c06f954: /* original 0009, guest PC 0x0c06f954 */
if(!s->budget--) { s->failed_pc=0x0c06f954u; return 0; }
goto P_0c06f956;
P_0c06f956: /* original d22f, guest PC 0x0c06f956 */
if(!s->budget--) { s->failed_pc=0x0c06f956u; return 0; }
r[2]=read(ram,0x0c06fa14u,4);
goto P_0c06f958;
P_0c06f958: /* original 420b, guest PC 0x0c06f958 */
if(!s->budget--) { s->failed_pc=0x0c06f958u; return 0; }
target=r[2];
r[16]=0x0c06f95cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f95cu) { target=s->pc; goto dispatch; }
goto P_0c06f95c;
P_0c06f95a: /* original e401, guest PC 0x0c06f95a */
if(!s->budget--) { s->failed_pc=0x0c06f95au; return 0; }
r[4]=0x00000001u;
goto P_0c06f95c;
P_0c06f95c: /* original d32e, guest PC 0x0c06f95c */
if(!s->budget--) { s->failed_pc=0x0c06f95cu; return 0; }
r[3]=read(ram,0x0c06fa18u,4);
goto P_0c06f95e;
P_0c06f95e: /* original 430b, guest PC 0x0c06f95e */
if(!s->budget--) { s->failed_pc=0x0c06f95eu; return 0; }
target=r[3];
r[16]=0x0c06f962u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f962u) { target=s->pc; goto dispatch; }
goto P_0c06f962;
P_0c06f960: /* original 64e3, guest PC 0x0c06f960 */
if(!s->budget--) { s->failed_pc=0x0c06f960u; return 0; }
r[4]=r[14];
goto P_0c06f962;
P_0c06f962: /* original d22e, guest PC 0x0c06f962 */
if(!s->budget--) { s->failed_pc=0x0c06f962u; return 0; }
r[2]=read(ram,0x0c06fa1cu,4);
goto P_0c06f964;
P_0c06f964: /* original 65e3, guest PC 0x0c06f964 */
if(!s->budget--) { s->failed_pc=0x0c06f964u; return 0; }
r[5]=r[14];
goto P_0c06f966;
P_0c06f966: /* original 420b, guest PC 0x0c06f966 */
if(!s->budget--) { s->failed_pc=0x0c06f966u; return 0; }
target=r[2];
r[16]=0x0c06f96au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f96au) { target=s->pc; goto dispatch; }
goto P_0c06f96a;
P_0c06f968: /* original 64b3, guest PC 0x0c06f968 */
if(!s->budget--) { s->failed_pc=0x0c06f968u; return 0; }
r[4]=r[11];
goto P_0c06f96a;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=0x0c06f974u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
P_0c070caa: /* original f40b, guest PC 0x0c070caa */
if(!s->budget--) { s->failed_pc=0x0c070caau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cac;
P_0c070cac: /* original 66f3, guest PC 0x0c070cac */
if(!s->budget--) { s->failed_pc=0x0c070cacu; return 0; }
r[6]=r[15];
goto P_0c070cae;
P_0c070cae: /* original 64e3, guest PC 0x0c070cae */
if(!s->budget--) { s->failed_pc=0x0c070caeu; return 0; }
r[4]=r[14];
goto P_0c070cb0;
P_0c070cb0: /* original 6583, guest PC 0x0c070cb0 */
if(!s->budget--) { s->failed_pc=0x0c070cb0u; return 0; }
r[5]=r[8];
goto P_0c070cb2;
P_0c070cb2: /* original 762c, guest PC 0x0c070cb2 */
if(!s->budget--) { s->failed_pc=0x0c070cb2u; return 0; }
r[6]+=0x0000002cu;
goto P_0c070cb4;
P_0c070cb4: /* original f059, guest PC 0x0c070cb4 */
if(!s->budget--) { s->failed_pc=0x0c070cb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb6;
P_0c070cb6: /* original f369, guest PC 0x0c070cb6 */
if(!s->budget--) { s->failed_pc=0x0c070cb6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb8;
P_0c070cb8: /* original f159, guest PC 0x0c070cb8 */
if(!s->budget--) { s->failed_pc=0x0c070cb8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cba;
P_0c070cba: /* original f469, guest PC 0x0c070cba */
if(!s->budget--) { s->failed_pc=0x0c070cbau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbc;
P_0c070cbc: /* original f259, guest PC 0x0c070cbc */
if(!s->budget--) { s->failed_pc=0x0c070cbcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbe;
P_0c070cbe: /* original f569, guest PC 0x0c070cbe */
if(!s->budget--) { s->failed_pc=0x0c070cbeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cc0;
P_0c070cc0: /* original 740c, guest PC 0x0c070cc0 */
if(!s->budget--) { s->failed_pc=0x0c070cc0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070cc2;
P_0c070cc2: /* original f030, guest PC 0x0c070cc2 */
if(!s->budget--) { s->failed_pc=0x0c070cc2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070cc4;
P_0c070cc4: /* original f250, guest PC 0x0c070cc4 */
if(!s->budget--) { s->failed_pc=0x0c070cc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070cc6;
P_0c070cc6: /* original f140, guest PC 0x0c070cc6 */
if(!s->budget--) { s->failed_pc=0x0c070cc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070cc8;
P_0c070cc8: /* original f42b, guest PC 0x0c070cc8 */
if(!s->budget--) { s->failed_pc=0x0c070cc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cca;
P_0c070cca: /* original f41b, guest PC 0x0c070cca */
if(!s->budget--) { s->failed_pc=0x0c070ccau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ccc;
P_0c070ccc: /* original f40b, guest PC 0x0c070ccc */
if(!s->budget--) { s->failed_pc=0x0c070cccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cce;
P_0c070cce: /* original 0009, guest PC 0x0c070cce */
if(!s->budget--) { s->failed_pc=0x0c070cceu; return 0; }
goto P_0c070cd0;
P_0c070cd0: /* original 64f3, guest PC 0x0c070cd0 */
if(!s->budget--) { s->failed_pc=0x0c070cd0u; return 0; }
r[4]=r[15];
goto P_0c070cd2;
P_0c070cd2: /* original 7444, guest PC 0x0c070cd2 */
if(!s->budget--) { s->failed_pc=0x0c070cd2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cd4;
P_0c070cd4: /* original 66a3, guest PC 0x0c070cd4 */
if(!s->budget--) { s->failed_pc=0x0c070cd4u; return 0; }
r[6]=r[10];
goto P_0c070cd6;
P_0c070cd6: /* original 65d3, guest PC 0x0c070cd6 */
if(!s->budget--) { s->failed_pc=0x0c070cd6u; return 0; }
r[5]=r[13];
goto P_0c070cd8;
P_0c070cd8: /* original f059, guest PC 0x0c070cd8 */
if(!s->budget--) { s->failed_pc=0x0c070cd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cda;
P_0c070cda: /* original f369, guest PC 0x0c070cda */
if(!s->budget--) { s->failed_pc=0x0c070cdau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cdc;
P_0c070cdc: /* original f159, guest PC 0x0c070cdc */
if(!s->budget--) { s->failed_pc=0x0c070cdcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cde;
P_0c070cde: /* original f469, guest PC 0x0c070cde */
if(!s->budget--) { s->failed_pc=0x0c070cdeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070ce0;
P_0c070ce0: /* original f031, guest PC 0x0c070ce0 */
if(!s->budget--) { s->failed_pc=0x0c070ce0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070ce2;
P_0c070ce2: /* original f258, guest PC 0x0c070ce2 */
if(!s->budget--) { s->failed_pc=0x0c070ce2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ce4;
P_0c070ce4: /* original f568, guest PC 0x0c070ce4 */
if(!s->budget--) { s->failed_pc=0x0c070ce4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ce6;
P_0c070ce6: /* original f141, guest PC 0x0c070ce6 */
if(!s->budget--) { s->failed_pc=0x0c070ce6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ce8;
P_0c070ce8: /* original f251, guest PC 0x0c070ce8 */
if(!s->budget--) { s->failed_pc=0x0c070ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070cea;
P_0c070cea: /* original 7408, guest PC 0x0c070cea */
if(!s->budget--) { s->failed_pc=0x0c070ceau; return 0; }
r[4]+=0x00000008u;
goto P_0c070cec;
P_0c070cec: /* original f42a, guest PC 0x0c070cec */
if(!s->budget--) { s->failed_pc=0x0c070cecu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cee;
P_0c070cee: /* original f41b, guest PC 0x0c070cee */
if(!s->budget--) { s->failed_pc=0x0c070ceeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070cf0;
P_0c070cf0: /* original f40b, guest PC 0x0c070cf0 */
if(!s->budget--) { s->failed_pc=0x0c070cf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cf2;
P_0c070cf2: /* original 0009, guest PC 0x0c070cf2 */
if(!s->budget--) { s->failed_pc=0x0c070cf2u; return 0; }
goto P_0c070cf4;
P_0c070cf4: /* original 64f3, guest PC 0x0c070cf4 */
if(!s->budget--) { s->failed_pc=0x0c070cf4u; return 0; }
r[4]=r[15];
goto P_0c070cf6;
P_0c070cf6: /* original 7444, guest PC 0x0c070cf6 */
if(!s->budget--) { s->failed_pc=0x0c070cf6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cf8;
P_0c070cf8: /* original f049, guest PC 0x0c070cf8 */
if(!s->budget--) { s->failed_pc=0x0c070cf8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfa;
P_0c070cfa: /* original f149, guest PC 0x0c070cfa */
if(!s->budget--) { s->failed_pc=0x0c070cfau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfc;
P_0c070cfc: /* original f249, guest PC 0x0c070cfc */
if(!s->budget--) { s->failed_pc=0x0c070cfcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfe;
P_0c070cfe: /* original f38d, guest PC 0x0c070cfe */
if(!s->budget--) { s->failed_pc=0x0c070cfeu; return 0; }
fr[3]=0;
goto P_0c070d00;
P_0c070d00: /* original f0ed, guest PC 0x0c070d00 */
if(!s->budget--) { s->failed_pc=0x0c070d00u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d02;
P_0c070d02: /* original f03c, guest PC 0x0c070d02 */
if(!s->budget--) { s->failed_pc=0x0c070d02u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d04;
P_0c070d04: /* original f06d, guest PC 0x0c070d04 */
if(!s->budget--) { s->failed_pc=0x0c070d04u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d06;
P_0c070d06: /* original 0009, guest PC 0x0c070d06 */
if(!s->budget--) { s->failed_pc=0x0c070d06u; return 0; }
goto P_0c070d08;
P_0c070d08: /* original f38d, guest PC 0x0c070d08 */
if(!s->budget--) { s->failed_pc=0x0c070d08u; return 0; }
fr[3]=0;
goto P_0c070d0a;
P_0c070d0a: /* original fc0c, guest PC 0x0c070d0a */
if(!s->budget--) { s->failed_pc=0x0c070d0au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070d0c;
P_0c070d0c: /* original fc35, guest PC 0x0c070d0c */
if(!s->budget--) { s->failed_pc=0x0c070d0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070d0e;
P_0c070d0e: /* original 8902, guest PC 0x0c070d0e */
if(!s->budget--) { s->failed_pc=0x0c070d0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d16; }
goto P_0c070d10;
P_0c070d10: /* original d303, guest PC 0x0c070d10 */
if(!s->budget--) { s->failed_pc=0x0c070d10u; return 0; }
r[3]=read(ram,0x0c070d20u,4);
goto P_0c070d12;
P_0c070d12: /* original 432b, guest PC 0x0c070d12 */
if(!s->budget--) { s->failed_pc=0x0c070d12u; return 0; }
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
P_0c070d14: /* original 0009, guest PC 0x0c070d14 */
if(!s->budget--) { s->failed_pc=0x0c070d14u; return 0; }
goto P_0c070d16;
P_0c070d16: /* original 64f3, guest PC 0x0c070d16 */
if(!s->budget--) { s->failed_pc=0x0c070d16u; return 0; }
r[4]=r[15];
goto P_0c070d18;
P_0c070d18: /* original 7444, guest PC 0x0c070d18 */
if(!s->budget--) { s->failed_pc=0x0c070d18u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d1a;
P_0c070d1a: /* original 65b3, guest PC 0x0c070d1a */
if(!s->budget--) { s->failed_pc=0x0c070d1au; return 0; }
r[5]=r[11];
goto P_0c070d1c;
P_0c070d1c: /* original a002, guest PC 0x0c070d1c */
if(!s->budget--) { s->failed_pc=0x0c070d1cu; return 0; }
goto P_0c070d24;
P_0c070d1e: /* original 0009, guest PC 0x0c070d1e */
if(!s->budget--) { s->failed_pc=0x0c070d1eu; return 0; }
return vf3_matrix_family(0x0c070d20u,s,ram);
P_0c070d24: /* original f049, guest PC 0x0c070d24 */
if(!s->budget--) { s->failed_pc=0x0c070d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d26;
P_0c070d26: /* original f549, guest PC 0x0c070d26 */
if(!s->budget--) { s->failed_pc=0x0c070d26u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d28;
P_0c070d28: /* original f648, guest PC 0x0c070d28 */
if(!s->budget--) { s->failed_pc=0x0c070d28u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070d2a;
P_0c070d2a: /* original f859, guest PC 0x0c070d2a */
if(!s->budget--) { s->failed_pc=0x0c070d2au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2c;
P_0c070d2c: /* original f959, guest PC 0x0c070d2c */
if(!s->budget--) { s->failed_pc=0x0c070d2cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2e;
P_0c070d2e: /* original fa58, guest PC 0x0c070d2e */
if(!s->budget--) { s->failed_pc=0x0c070d2eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070d30;
P_0c070d30: /* original f35c, guest PC 0x0c070d30 */
if(!s->budget--) { s->failed_pc=0x0c070d30u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070d32;
P_0c070d32: /* original f382, guest PC 0x0c070d32 */
if(!s->budget--) { s->failed_pc=0x0c070d32u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070d34;
P_0c070d34: /* original f20c, guest PC 0x0c070d34 */
if(!s->budget--) { s->failed_pc=0x0c070d34u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070d36;
P_0c070d36: /* original f2a2, guest PC 0x0c070d36 */
if(!s->budget--) { s->failed_pc=0x0c070d36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070d38;
P_0c070d38: /* original f16c, guest PC 0x0c070d38 */
if(!s->budget--) { s->failed_pc=0x0c070d38u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070d3a;
P_0c070d3a: /* original f192, guest PC 0x0c070d3a */
if(!s->budget--) { s->failed_pc=0x0c070d3au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070d3c;
P_0c070d3c: /* original f34d, guest PC 0x0c070d3c */
if(!s->budget--) { s->failed_pc=0x0c070d3cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070d3e;
P_0c070d3e: /* original f39e, guest PC 0x0c070d3e */
if(!s->budget--) { s->failed_pc=0x0c070d3eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070d40;
P_0c070d40: /* original f24d, guest PC 0x0c070d40 */
if(!s->budget--) { s->failed_pc=0x0c070d40u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070d42;
P_0c070d42: /* original f06c, guest PC 0x0c070d42 */
if(!s->budget--) { s->failed_pc=0x0c070d42u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070d44;
P_0c070d44: /* original f28e, guest PC 0x0c070d44 */
if(!s->budget--) { s->failed_pc=0x0c070d44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070d46;
P_0c070d46: /* original f14d, guest PC 0x0c070d46 */
if(!s->budget--) { s->failed_pc=0x0c070d46u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070d48;
P_0c070d48: /* original f05c, guest PC 0x0c070d48 */
if(!s->budget--) { s->failed_pc=0x0c070d48u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070d4a;
P_0c070d4a: /* original f1ae, guest PC 0x0c070d4a */
if(!s->budget--) { s->failed_pc=0x0c070d4au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070d4c;
P_0c070d4c: /* original f08d, guest PC 0x0c070d4c */
if(!s->budget--) { s->failed_pc=0x0c070d4cu; return 0; }
fr[0]=0;
goto P_0c070d4e;
P_0c070d4e: /* original f0ed, guest PC 0x0c070d4e */
if(!s->budget--) { s->failed_pc=0x0c070d4eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d50;
P_0c070d50: /* original f03c, guest PC 0x0c070d50 */
if(!s->budget--) { s->failed_pc=0x0c070d50u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d52;
P_0c070d52: /* original f06d, guest PC 0x0c070d52 */
if(!s->budget--) { s->failed_pc=0x0c070d52u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d54;
P_0c070d54: /* original ff05, guest PC 0x0c070d54 */
if(!s->budget--) { s->failed_pc=0x0c070d54u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070d56;
P_0c070d56: /* original e01c, guest PC 0x0c070d56 */
if(!s->budget--) { s->failed_pc=0x0c070d56u; return 0; }
r[0]=0x0000001cu;
goto P_0c070d58;
P_0c070d58: /* original 8d03, guest PC 0x0c070d58 */
if(!s->budget--) { s->failed_pc=0x0c070d58u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070d62; }
goto P_0c070d5c;
P_0c070d5a: /* original ff07, guest PC 0x0c070d5a */
if(!s->budget--) { s->failed_pc=0x0c070d5au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070d5c;
P_0c070d5c: /* original d303, guest PC 0x0c070d5c */
if(!s->budget--) { s->failed_pc=0x0c070d5cu; return 0; }
r[3]=read(ram,0x0c070d6cu,4);
goto P_0c070d5e;
P_0c070d5e: /* original 432b, guest PC 0x0c070d5e */
if(!s->budget--) { s->failed_pc=0x0c070d5eu; return 0; }
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
P_0c070d60: /* original 0009, guest PC 0x0c070d60 */
if(!s->budget--) { s->failed_pc=0x0c070d60u; return 0; }
goto P_0c070d62;
P_0c070d62: /* original 64f3, guest PC 0x0c070d62 */
if(!s->budget--) { s->failed_pc=0x0c070d62u; return 0; }
r[4]=r[15];
goto P_0c070d64;
P_0c070d64: /* original 7444, guest PC 0x0c070d64 */
if(!s->budget--) { s->failed_pc=0x0c070d64u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d66;
P_0c070d66: /* original 65b3, guest PC 0x0c070d66 */
if(!s->budget--) { s->failed_pc=0x0c070d66u; return 0; }
r[5]=r[11];
goto P_0c070d68;
P_0c070d68: /* original a002, guest PC 0x0c070d68 */
if(!s->budget--) { s->failed_pc=0x0c070d68u; return 0; }
goto P_0c070d70;
P_0c070d6a: /* original 0009, guest PC 0x0c070d6a */
if(!s->budget--) { s->failed_pc=0x0c070d6au; return 0; }
return vf3_matrix_family(0x0c070d6cu,s,ram);
P_0c070d70: /* original f049, guest PC 0x0c070d70 */
if(!s->budget--) { s->failed_pc=0x0c070d70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d72;
P_0c070d72: /* original f149, guest PC 0x0c070d72 */
if(!s->budget--) { s->failed_pc=0x0c070d72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d74;
P_0c070d74: /* original f249, guest PC 0x0c070d74 */
if(!s->budget--) { s->failed_pc=0x0c070d74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d76;
P_0c070d76: /* original f38d, guest PC 0x0c070d76 */
if(!s->budget--) { s->failed_pc=0x0c070d76u; return 0; }
fr[3]=0;
goto P_0c070d78;
P_0c070d78: /* original f459, guest PC 0x0c070d78 */
if(!s->budget--) { s->failed_pc=0x0c070d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7a;
P_0c070d7a: /* original f559, guest PC 0x0c070d7a */
if(!s->budget--) { s->failed_pc=0x0c070d7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7c;
P_0c070d7c: /* original f659, guest PC 0x0c070d7c */
if(!s->budget--) { s->failed_pc=0x0c070d7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7e;
P_0c070d7e: /* original f78d, guest PC 0x0c070d7e */
if(!s->budget--) { s->failed_pc=0x0c070d7eu; return 0; }
fr[7]=0;
goto P_0c070d80;
P_0c070d80: /* original f4ed, guest PC 0x0c070d80 */
if(!s->budget--) { s->failed_pc=0x0c070d80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070d82;
P_0c070d82: /* original f07c, guest PC 0x0c070d82 */
if(!s->budget--) { s->failed_pc=0x0c070d82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070d84;
P_0c070d84: /* original f38d, guest PC 0x0c070d84 */
if(!s->budget--) { s->failed_pc=0x0c070d84u; return 0; }
fr[3]=0;
goto P_0c070d86;
P_0c070d86: /* original f40c, guest PC 0x0c070d86 */
if(!s->budget--) { s->failed_pc=0x0c070d86u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070d88;
P_0c070d88: /* original f345, guest PC 0x0c070d88 */
if(!s->budget--) { s->failed_pc=0x0c070d88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070d8a;
P_0c070d8a: /* original 8902, guest PC 0x0c070d8a */
if(!s->budget--) { s->failed_pc=0x0c070d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d92; }
goto P_0c070d8c;
P_0c070d8c: /* original d307, guest PC 0x0c070d8c */
if(!s->budget--) { s->failed_pc=0x0c070d8cu; return 0; }
r[3]=read(ram,0x0c070dacu,4);
goto P_0c070d8e;
P_0c070d8e: /* original 432b, guest PC 0x0c070d8e */
if(!s->budget--) { s->failed_pc=0x0c070d8eu; return 0; }
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
P_0c070d90: /* original 0009, guest PC 0x0c070d90 */
if(!s->budget--) { s->failed_pc=0x0c070d90u; return 0; }
goto P_0c070d92;
P_0c070d92: /* original ffc5, guest PC 0x0c070d92 */
if(!s->budget--) { s->failed_pc=0x0c070d92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070d94;
P_0c070d94: /* original 8902, guest PC 0x0c070d94 */
if(!s->budget--) { s->failed_pc=0x0c070d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d9c; }
goto P_0c070d96;
P_0c070d96: /* original d206, guest PC 0x0c070d96 */
if(!s->budget--) { s->failed_pc=0x0c070d96u; return 0; }
r[2]=read(ram,0x0c070db0u,4);
goto P_0c070d98;
P_0c070d98: /* original 422b, guest PC 0x0c070d98 */
if(!s->budget--) { s->failed_pc=0x0c070d98u; return 0; }
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
P_0c070d9a: /* original 0009, guest PC 0x0c070d9a */
if(!s->budget--) { s->failed_pc=0x0c070d9au; return 0; }
goto P_0c070d9c;
P_0c070d9c: /* original 64f3, guest PC 0x0c070d9c */
if(!s->budget--) { s->failed_pc=0x0c070d9cu; return 0; }
r[4]=r[15];
goto P_0c070d9e;
P_0c070d9e: /* original 65f3, guest PC 0x0c070d9e */
if(!s->budget--) { s->failed_pc=0x0c070d9eu; return 0; }
r[5]=r[15];
goto P_0c070da0;
P_0c070da0: /* original 7444, guest PC 0x0c070da0 */
if(!s->budget--) { s->failed_pc=0x0c070da0u; return 0; }
r[4]+=0x00000044u;
goto P_0c070da2;
P_0c070da2: /* original f4fc, guest PC 0x0c070da2 */
if(!s->budget--) { s->failed_pc=0x0c070da2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070da4;
P_0c070da4: /* original 7544, guest PC 0x0c070da4 */
if(!s->budget--) { s->failed_pc=0x0c070da4u; return 0; }
r[5]+=0x00000044u;
goto P_0c070da6;
P_0c070da6: /* original a005, guest PC 0x0c070da6 */
if(!s->budget--) { s->failed_pc=0x0c070da6u; return 0; }
goto P_0c070db4;
P_0c070da8: /* original 0009, guest PC 0x0c070da8 */
if(!s->budget--) { s->failed_pc=0x0c070da8u; return 0; }
return vf3_matrix_family(0x0c070daau,s,ram);
P_0c070db4: /* original f059, guest PC 0x0c070db4 */
if(!s->budget--) { s->failed_pc=0x0c070db4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db6;
P_0c070db6: /* original f159, guest PC 0x0c070db6 */
if(!s->budget--) { s->failed_pc=0x0c070db6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db8;
P_0c070db8: /* original f259, guest PC 0x0c070db8 */
if(!s->budget--) { s->failed_pc=0x0c070db8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dba;
P_0c070dba: /* original f38d, guest PC 0x0c070dba */
if(!s->budget--) { s->failed_pc=0x0c070dbau; return 0; }
fr[3]=0;
goto P_0c070dbc;
P_0c070dbc: /* original f0ed, guest PC 0x0c070dbc */
if(!s->budget--) { s->failed_pc=0x0c070dbcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070dbe;
P_0c070dbe: /* original f37d, guest PC 0x0c070dbe */
if(!s->budget--) { s->failed_pc=0x0c070dbeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070dc0;
P_0c070dc0: /* original f342, guest PC 0x0c070dc0 */
if(!s->budget--) { s->failed_pc=0x0c070dc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070dc2;
P_0c070dc2: /* original 740c, guest PC 0x0c070dc2 */
if(!s->budget--) { s->failed_pc=0x0c070dc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dc4;
P_0c070dc4: /* original f232, guest PC 0x0c070dc4 */
if(!s->budget--) { s->failed_pc=0x0c070dc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070dc6;
P_0c070dc6: /* original f132, guest PC 0x0c070dc6 */
if(!s->budget--) { s->failed_pc=0x0c070dc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070dc8;
P_0c070dc8: /* original f032, guest PC 0x0c070dc8 */
if(!s->budget--) { s->failed_pc=0x0c070dc8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070dca;
P_0c070dca: /* original f42b, guest PC 0x0c070dca */
if(!s->budget--) { s->failed_pc=0x0c070dcau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070dcc;
P_0c070dcc: /* original f41b, guest PC 0x0c070dcc */
if(!s->budget--) { s->failed_pc=0x0c070dccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070dce;
P_0c070dce: /* original f40b, guest PC 0x0c070dce */
if(!s->budget--) { s->failed_pc=0x0c070dceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070dd0;
P_0c070dd0: /* original d206, guest PC 0x0c070dd0 */
if(!s->budget--) { s->failed_pc=0x0c070dd0u; return 0; }
r[2]=read(ram,0x0c070decu,4);
goto P_0c070dd2;
P_0c070dd2: /* original 422b, guest PC 0x0c070dd2 */
if(!s->budget--) { s->failed_pc=0x0c070dd2u; return 0; }
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
P_0c070dd4: /* original 0009, guest PC 0x0c070dd4 */
if(!s->budget--) { s->failed_pc=0x0c070dd4u; return 0; }
return vf3_matrix_family(0x0c070dd6u,s,ram);
P_0c0710e2: /* original f40b, guest PC 0x0c0710e2 */
if(!s->budget--) { s->failed_pc=0x0c0710e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0710e4;
P_0c0710e4: /* original 55f1, guest PC 0x0c0710e4 */
if(!s->budget--) { s->failed_pc=0x0c0710e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0710e6;
P_0c0710e6: /* original 66f3, guest PC 0x0c0710e6 */
if(!s->budget--) { s->failed_pc=0x0c0710e6u; return 0; }
r[6]=r[15];
goto P_0c0710e8;
P_0c0710e8: /* original 64d3, guest PC 0x0c0710e8 */
if(!s->budget--) { s->failed_pc=0x0c0710e8u; return 0; }
r[4]=r[13];
goto P_0c0710ea;
P_0c0710ea: /* original 762c, guest PC 0x0c0710ea */
if(!s->budget--) { s->failed_pc=0x0c0710eau; return 0; }
r[6]+=0x0000002cu;
goto P_0c0710ec;
P_0c0710ec: /* original f059, guest PC 0x0c0710ec */
if(!s->budget--) { s->failed_pc=0x0c0710ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ee;
P_0c0710ee: /* original f369, guest PC 0x0c0710ee */
if(!s->budget--) { s->failed_pc=0x0c0710eeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f0;
P_0c0710f0: /* original f159, guest PC 0x0c0710f0 */
if(!s->budget--) { s->failed_pc=0x0c0710f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f2;
P_0c0710f2: /* original f469, guest PC 0x0c0710f2 */
if(!s->budget--) { s->failed_pc=0x0c0710f2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f4;
P_0c0710f4: /* original f259, guest PC 0x0c0710f4 */
if(!s->budget--) { s->failed_pc=0x0c0710f4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f6;
P_0c0710f6: /* original f569, guest PC 0x0c0710f6 */
if(!s->budget--) { s->failed_pc=0x0c0710f6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f8;
P_0c0710f8: /* original 740c, guest PC 0x0c0710f8 */
if(!s->budget--) { s->failed_pc=0x0c0710f8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710fa;
P_0c0710fa: /* original f030, guest PC 0x0c0710fa */
if(!s->budget--) { s->failed_pc=0x0c0710fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0710fc;
P_0c0710fc: /* original f250, guest PC 0x0c0710fc */
if(!s->budget--) { s->failed_pc=0x0c0710fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0710fe;
P_0c0710fe: /* original f140, guest PC 0x0c0710fe */
if(!s->budget--) { s->failed_pc=0x0c0710feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071100;
P_0c071100: /* original f42b, guest PC 0x0c071100 */
if(!s->budget--) { s->failed_pc=0x0c071100u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071102;
P_0c071102: /* original f41b, guest PC 0x0c071102 */
if(!s->budget--) { s->failed_pc=0x0c071102u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071104;
P_0c071104: /* original f40b, guest PC 0x0c071104 */
if(!s->budget--) { s->failed_pc=0x0c071104u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071106;
P_0c071106: /* original 0009, guest PC 0x0c071106 */
if(!s->budget--) { s->failed_pc=0x0c071106u; return 0; }
goto P_0c071108;
P_0c071108: /* original 52f1, guest PC 0x0c071108 */
if(!s->budget--) { s->failed_pc=0x0c071108u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07110a;
P_0c07110a: /* original 7d18, guest PC 0x0c07110a */
if(!s->budget--) { s->failed_pc=0x0c07110au; return 0; }
r[13]+=0x00000018u;
goto P_0c07110c;
P_0c07110c: /* original 78e8, guest PC 0x0c07110c */
if(!s->budget--) { s->failed_pc=0x0c07110cu; return 0; }
r[8]+=0xffffffe8u;
goto P_0c07110e;
P_0c07110e: /* original 7218, guest PC 0x0c07110e */
if(!s->budget--) { s->failed_pc=0x0c07110eu; return 0; }
r[2]+=0x00000018u;
goto P_0c071110;
P_0c071110: /* original 1f21, guest PC 0x0c071110 */
if(!s->budget--) { s->failed_pc=0x0c071110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c071112;
P_0c071112: /* original 7ee8, guest PC 0x0c071112 */
if(!s->budget--) { s->failed_pc=0x0c071112u; return 0; }
r[14]+=0xffffffe8u;
goto P_0c071114;
P_0c071114: /* original 63f2, guest PC 0x0c071114 */
if(!s->budget--) { s->failed_pc=0x0c071114u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071116;
P_0c071116: /* original 73ff, guest PC 0x0c071116 */
if(!s->budget--) { s->failed_pc=0x0c071116u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071118;
P_0c071118: /* original 4315, guest PC 0x0c071118 */
if(!s->budget--) { s->failed_pc=0x0c071118u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07111a;
P_0c07111a: /* original 8f03, guest PC 0x0c07111a */
if(!s->budget--) { s->failed_pc=0x0c07111au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c071124; }
goto P_0c07111e;
P_0c07111c: /* original 2f32, guest PC 0x0c07111c */
if(!s->budget--) { s->failed_pc=0x0c07111cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07111e;
P_0c07111e: /* original d11d, guest PC 0x0c07111e */
if(!s->budget--) { s->failed_pc=0x0c07111eu; return 0; }
r[1]=read(ram,0x0c071194u,4);
goto P_0c071120;
P_0c071120: /* original 412b, guest PC 0x0c071120 */
if(!s->budget--) { s->failed_pc=0x0c071120u; return 0; }
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
P_0c071122: /* original 0009, guest PC 0x0c071122 */
if(!s->budget--) { s->failed_pc=0x0c071122u; return 0; }
goto P_0c071124;
P_0c071124: /* original 7f5c, guest PC 0x0c071124 */
if(!s->budget--) { s->failed_pc=0x0c071124u; return 0; }
r[15]+=0x0000005cu;
goto P_0c071126;
P_0c071126: /* original 4f26, guest PC 0x0c071126 */
if(!s->budget--) { s->failed_pc=0x0c071126u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c071128;
P_0c071128: /* original fcf9, guest PC 0x0c071128 */
if(!s->budget--) { s->failed_pc=0x0c071128u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112a;
P_0c07112a: /* original fdf9, guest PC 0x0c07112a */
if(!s->budget--) { s->failed_pc=0x0c07112au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112c;
P_0c07112c: /* original fef9, guest PC 0x0c07112c */
if(!s->budget--) { s->failed_pc=0x0c07112cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112e;
P_0c07112e: /* original fff9, guest PC 0x0c07112e */
if(!s->budget--) { s->failed_pc=0x0c07112eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071130;
P_0c071130: /* original 68f6, guest PC 0x0c071130 */
if(!s->budget--) { s->failed_pc=0x0c071130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c071132;
P_0c071132: /* original 69f6, guest PC 0x0c071132 */
if(!s->budget--) { s->failed_pc=0x0c071132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071134;
P_0c071134: /* original 6af6, guest PC 0x0c071134 */
if(!s->budget--) { s->failed_pc=0x0c071134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c071136;
P_0c071136: /* original 6bf6, guest PC 0x0c071136 */
if(!s->budget--) { s->failed_pc=0x0c071136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c071138;
P_0c071138: /* original 6cf6, guest PC 0x0c071138 */
if(!s->budget--) { s->failed_pc=0x0c071138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07113a;
P_0c07113a: /* original 6df6, guest PC 0x0c07113a */
if(!s->budget--) { s->failed_pc=0x0c07113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07113c;
P_0c07113c: /* original 000b, guest PC 0x0c07113c */
if(!s->budget--) { s->failed_pc=0x0c07113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07113e: /* original 6ef6, guest PC 0x0c07113e */
if(!s->budget--) { s->failed_pc=0x0c07113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071140u,s,ram);
P_0c08b430: /* original 2fe6, guest PC 0x0c08b430 */
if(!s->budget--) { s->failed_pc=0x0c08b430u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08b432;
P_0c08b432: /* original 6e73, guest PC 0x0c08b432 */
if(!s->budget--) { s->failed_pc=0x0c08b432u; return 0; }
r[14]=r[7];
goto P_0c08b434;
P_0c08b434: /* original 2fd6, guest PC 0x0c08b434 */
if(!s->budget--) { s->failed_pc=0x0c08b434u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08b436;
P_0c08b436: /* original 2fc6, guest PC 0x0c08b436 */
if(!s->budget--) { s->failed_pc=0x0c08b436u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08b438;
P_0c08b438: /* original 6c53, guest PC 0x0c08b438 */
if(!s->budget--) { s->failed_pc=0x0c08b438u; return 0; }
r[12]=r[5];
goto P_0c08b43a;
P_0c08b43a: /* original 2fb6, guest PC 0x0c08b43a */
if(!s->budget--) { s->failed_pc=0x0c08b43au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c08b43c;
P_0c08b43c: /* original 2fa6, guest PC 0x0c08b43c */
if(!s->budget--) { s->failed_pc=0x0c08b43cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c08b43e;
P_0c08b43e: /* original 2f96, guest PC 0x0c08b43e */
if(!s->budget--) { s->failed_pc=0x0c08b43eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c08b440;
P_0c08b440: /* original 6943, guest PC 0x0c08b440 */
if(!s->budget--) { s->failed_pc=0x0c08b440u; return 0; }
r[9]=r[4];
goto P_0c08b442;
P_0c08b442: /* original 2f86, guest PC 0x0c08b442 */
if(!s->budget--) { s->failed_pc=0x0c08b442u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c08b444;
P_0c08b444: /* original 7964, guest PC 0x0c08b444 */
if(!s->budget--) { s->failed_pc=0x0c08b444u; return 0; }
r[9]+=0x00000064u;
goto P_0c08b446;
P_0c08b446: /* original fffb, guest PC 0x0c08b446 */
if(!s->budget--) { s->failed_pc=0x0c08b446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b448;
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=0x0c08b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=0x0c08b480u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=0x0c08b4b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b4de;
P_0c08b4de: /* original d50e, guest PC 0x0c08b4de */
if(!s->budget--) { s->failed_pc=0x0c08b4deu; return 0; }
r[5]=read(ram,0x0c08b518u,4);
goto P_0c08b4e0;
P_0c08b4e0: /* original a007, guest PC 0x0c08b4e0 */
if(!s->budget--) { s->failed_pc=0x0c08b4e0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4f2;
P_0c08b4e2: /* original 664e, guest PC 0x0c08b4e2 */
if(!s->budget--) { s->failed_pc=0x0c08b4e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4e4;
P_0c08b4e4: /* original 7501, guest PC 0x0c08b4e4 */
if(!s->budget--) { s->failed_pc=0x0c08b4e4u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4e6;
P_0c08b4e6: /* original 6450, guest PC 0x0c08b4e6 */
if(!s->budget--) { s->failed_pc=0x0c08b4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[4]=tmp;
goto P_0c08b4e8;
P_0c08b4e8: /* original 644e, guest PC 0x0c08b4e8 */
if(!s->budget--) { s->failed_pc=0x0c08b4e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4ea;
P_0c08b4ea: /* original 2448, guest PC 0x0c08b4ea */
if(!s->budget--) { s->failed_pc=0x0c08b4eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08b4ec;
P_0c08b4ec: /* original 8bfa, guest PC 0x0c08b4ec */
if(!s->budget--) { s->failed_pc=0x0c08b4ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4e4; }
goto P_0c08b4ee;
P_0c08b4ee: /* original 76ff, guest PC 0x0c08b4ee */
if(!s->budget--) { s->failed_pc=0x0c08b4eeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08b4f0;
P_0c08b4f0: /* original 7501, guest PC 0x0c08b4f0 */
if(!s->budget--) { s->failed_pc=0x0c08b4f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4f2;
P_0c08b4f2: /* original 4615, guest PC 0x0c08b4f2 */
if(!s->budget--) { s->failed_pc=0x0c08b4f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c08b4f4;
P_0c08b4f4: /* original 89f7, guest PC 0x0c08b4f4 */
if(!s->budget--) { s->failed_pc=0x0c08b4f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4e6; }
goto P_0c08b4f6;
P_0c08b4f6: /* original 000b, guest PC 0x0c08b4f6 */
if(!s->budget--) { s->failed_pc=0x0c08b4f6u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c08b4f8: /* original 6053, guest PC 0x0c08b4f8 */
if(!s->budget--) { s->failed_pc=0x0c08b4f8u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c08b4fau,s,ram);
P_0c08b57e: /* original 2fe6, guest PC 0x0c08b57e */
if(!s->budget--) { s->failed_pc=0x0c08b57eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08b580;
P_0c08b580: /* original e200, guest PC 0x0c08b580 */
if(!s->budget--) { s->failed_pc=0x0c08b580u; return 0; }
r[2]=0x00000000u;
goto P_0c08b582;
P_0c08b582: /* original d32d, guest PC 0x0c08b582 */
if(!s->budget--) { s->failed_pc=0x0c08b582u; return 0; }
r[3]=read(ram,0x0c08b638u,4);
goto P_0c08b584;
P_0c08b584: /* original e010, guest PC 0x0c08b584 */
if(!s->budget--) { s->failed_pc=0x0c08b584u; return 0; }
r[0]=0x00000010u;
goto P_0c08b586;
P_0c08b586: /* original 4f22, guest PC 0x0c08b586 */
if(!s->budget--) { s->failed_pc=0x0c08b586u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b588;
P_0c08b588: /* original 6e32, guest PC 0x0c08b588 */
if(!s->budget--) { s->failed_pc=0x0c08b588u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c08b58a;
P_0c08b58a: /* original 1e25, guest PC 0x0c08b58a */
if(!s->budget--) { s->failed_pc=0x0c08b58au; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c08b58c;
P_0c08b58c: /* original 924d, guest PC 0x0c08b58c */
if(!s->budget--) { s->failed_pc=0x0c08b58cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b62au,2);
goto P_0c08b58e;
P_0c08b58e: /* original 04ec, guest PC 0x0c08b58e */
if(!s->budget--) { s->failed_pc=0x0c08b58eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b590;
P_0c08b590: /* original 3420, guest PC 0x0c08b590 */
if(!s->budget--) { s->failed_pc=0x0c08b590u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08b592;
P_0c08b592: /* original 8908, guest PC 0x0c08b592 */
if(!s->budget--) { s->failed_pc=0x0c08b592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b5a6; }
goto P_0c08b594;
P_0c08b594: /* original bfa3, guest PC 0x0c08b594 */
if(!s->budget--) { s->failed_pc=0x0c08b594u; return 0; }
target=0x0c08b4deu; r[16]=0x0c08b598u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b598u) { target=s->pc; goto dispatch; }
goto P_0c08b598;
P_0c08b596: /* original 04ec, guest PC 0x0c08b596 */
if(!s->budget--) { s->failed_pc=0x0c08b596u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b598;
P_0c08b598: /* original 4f26, guest PC 0x0c08b598 */
if(!s->budget--) { s->failed_pc=0x0c08b598u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b59a;
P_0c08b59a: /* original 64e3, guest PC 0x0c08b59a */
if(!s->budget--) { s->failed_pc=0x0c08b59au; return 0; }
r[4]=r[14];
goto P_0c08b59c;
P_0c08b59c: /* original e508, guest PC 0x0c08b59c */
if(!s->budget--) { s->failed_pc=0x0c08b59cu; return 0; }
r[5]=0x00000008u;
goto P_0c08b59e;
P_0c08b59e: /* original 6703, guest PC 0x0c08b59e */
if(!s->budget--) { s->failed_pc=0x0c08b59eu; return 0; }
r[7]=r[0];
goto P_0c08b5a0;
P_0c08b5a0: /* original e600, guest PC 0x0c08b5a0 */
if(!s->budget--) { s->failed_pc=0x0c08b5a0u; return 0; }
r[6]=0x00000000u;
goto P_0c08b5a2;
P_0c08b5a2: /* original af45, guest PC 0x0c08b5a2 */
if(!s->budget--) { s->failed_pc=0x0c08b5a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b430;
P_0c08b5a4: /* original 6ef6, guest PC 0x0c08b5a4 */
if(!s->budget--) { s->failed_pc=0x0c08b5a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b5a6;
P_0c08b5a6: /* original 4f26, guest PC 0x0c08b5a6 */
if(!s->budget--) { s->failed_pc=0x0c08b5a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b5a8;
P_0c08b5a8: /* original 000b, guest PC 0x0c08b5a8 */
if(!s->budget--) { s->failed_pc=0x0c08b5a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b5aa: /* original 6ef6, guest PC 0x0c08b5aa */
if(!s->budget--) { s->failed_pc=0x0c08b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b5acu,s,ram);
P_0c0968d0: /* original d418, guest PC 0x0c0968d0 */
if(!s->budget--) { s->failed_pc=0x0c0968d0u; return 0; }
r[4]=read(ram,0x0c096934u,4);
goto P_0c0968d2;
P_0c0968d2: /* original 7ffc, guest PC 0x0c0968d2 */
if(!s->budget--) { s->failed_pc=0x0c0968d2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0968d4;
P_0c0968d4: /* original 5343, guest PC 0x0c0968d4 */
if(!s->budget--) { s->failed_pc=0x0c0968d4u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0968d6;
P_0c0968d6: /* original 73ff, guest PC 0x0c0968d6 */
if(!s->budget--) { s->failed_pc=0x0c0968d6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0968d8;
P_0c0968d8: /* original 1433, guest PC 0x0c0968d8 */
if(!s->budget--) { s->failed_pc=0x0c0968d8u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0968da;
P_0c0968da: /* original 844a, guest PC 0x0c0968da */
if(!s->budget--) { s->failed_pc=0x0c0968dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0968dc;
P_0c0968dc: /* original 650c, guest PC 0x0c0968dc */
if(!s->budget--) { s->failed_pc=0x0c0968dcu; return 0; }
r[5]=r[0]&255u;
goto P_0c0968de;
P_0c0968de: /* original 6053, guest PC 0x0c0968de */
if(!s->budget--) { s->failed_pc=0x0c0968deu; return 0; }
r[0]=r[5];
goto P_0c0968e0;
P_0c0968e0: /* original 8048, guest PC 0x0c0968e0 */
if(!s->budget--) { s->failed_pc=0x0c0968e0u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0968e2;
P_0c0968e2: /* original d215, guest PC 0x0c0968e2 */
if(!s->budget--) { s->failed_pc=0x0c0968e2u; return 0; }
r[2]=read(ram,0x0c096938u,4);
goto P_0c0968e4;
P_0c0968e4: /* original 635b, guest PC 0x0c0968e4 */
if(!s->budget--) { s->failed_pc=0x0c0968e4u; return 0; }
r[3]=0u-r[5];
goto P_0c0968e6;
P_0c0968e6: /* original 4508, guest PC 0x0c0968e6 */
if(!s->budget--) { s->failed_pc=0x0c0968e6u; return 0; }
r[5]<<=2;
goto P_0c0968e8;
P_0c0968e8: /* original 423d, guest PC 0x0c0968e8 */
if(!s->budget--) { s->failed_pc=0x0c0968e8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0968ea;
P_0c0968ea: /* original 2422, guest PC 0x0c0968ea */
if(!s->budget--) { s->failed_pc=0x0c0968eau; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0968ec;
P_0c0968ec: /* original d013, guest PC 0x0c0968ec */
if(!s->budget--) { s->failed_pc=0x0c0968ecu; return 0; }
r[0]=read(ram,0x0c09693cu,4);
goto P_0c0968ee;
P_0c0968ee: /* original 035e, guest PC 0x0c0968ee */
if(!s->budget--) { s->failed_pc=0x0c0968eeu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0968f0;
P_0c0968f0: /* original 6233, guest PC 0x0c0968f0 */
if(!s->budget--) { s->failed_pc=0x0c0968f0u; return 0; }
r[2]=r[3];
goto P_0c0968f2;
P_0c0968f2: /* original 2f32, guest PC 0x0c0968f2 */
if(!s->budget--) { s->failed_pc=0x0c0968f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0968f4;
P_0c0968f4: /* original 422b, guest PC 0x0c0968f4 */
if(!s->budget--) { s->failed_pc=0x0c0968f4u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0968f6: /* original 7f04, guest PC 0x0c0968f6 */
if(!s->budget--) { s->failed_pc=0x0c0968f6u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0968f8u,s,ram);
P_0c096902: /* original 6042, guest PC 0x0c096902 */
if(!s->budget--) { s->failed_pc=0x0c096902u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096904;
P_0c096904: /* original cb01, guest PC 0x0c096904 */
if(!s->budget--) { s->failed_pc=0x0c096904u; return 0; }
r[0]|=1u;
goto P_0c096906;
P_0c096906: /* original 000b, guest PC 0x0c096906 */
if(!s->budget--) { s->failed_pc=0x0c096906u; return 0; }
target=r[16];
write(ram,r[4],r[0],4);
s->pc=target; return ram->oob==0;
P_0c096908: /* original 2402, guest PC 0x0c096908 */
if(!s->budget--) { s->failed_pc=0x0c096908u; return 0; }
write(ram,r[4],r[0],4);
return vf3_matrix_family(0x0c09690au,s,ram);
P_0c096d5e: /* original 2fe6, guest PC 0x0c096d5e */
if(!s->budget--) { s->failed_pc=0x0c096d5eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c096d60;
P_0c096d60: /* original 2fd6, guest PC 0x0c096d60 */
if(!s->budget--) { s->failed_pc=0x0c096d60u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c096d62;
P_0c096d62: /* original 4f22, guest PC 0x0c096d62 */
if(!s->budget--) { s->failed_pc=0x0c096d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096d64;
P_0c096d64: /* original d327, guest PC 0x0c096d64 */
if(!s->budget--) { s->failed_pc=0x0c096d64u; return 0; }
r[3]=read(ram,0x0c096e04u,4);
goto P_0c096d66;
P_0c096d66: /* original dd2a, guest PC 0x0c096d66 */
if(!s->budget--) { s->failed_pc=0x0c096d66u; return 0; }
r[13]=read(ram,0x0c096e10u,4);
goto P_0c096d68;
P_0c096d68: /* original 7ffc, guest PC 0x0c096d68 */
if(!s->budget--) { s->failed_pc=0x0c096d68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d6a;
P_0c096d6a: /* original 2f32, guest PC 0x0c096d6a */
if(!s->budget--) { s->failed_pc=0x0c096d6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d6c;
P_0c096d6c: /* original 52d2, guest PC 0x0c096d6c */
if(!s->budget--) { s->failed_pc=0x0c096d6cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d6e;
P_0c096d6e: /* original d329, guest PC 0x0c096d6e */
if(!s->budget--) { s->failed_pc=0x0c096d6eu; return 0; }
r[3]=read(ram,0x0c096e14u,4);
goto P_0c096d70;
P_0c096d70: /* original 2238, guest PC 0x0c096d70 */
if(!s->budget--) { s->failed_pc=0x0c096d70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096d72;
P_0c096d72: /* original 8920, guest PC 0x0c096d72 */
if(!s->budget--) { s->failed_pc=0x0c096d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096db6; }
goto P_0c096d74;
P_0c096d74: /* original de28, guest PC 0x0c096d74 */
if(!s->budget--) { s->failed_pc=0x0c096d74u; return 0; }
r[14]=read(ram,0x0c096e18u,4);
goto P_0c096d76;
P_0c096d76: /* original bdc4, guest PC 0x0c096d76 */
if(!s->budget--) { s->failed_pc=0x0c096d76u; return 0; }
target=0x0c096902u; r[16]=0x0c096d7au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d7au) { target=s->pc; goto dispatch; }
goto P_0c096d7a;
P_0c096d78: /* original 54e8, guest PC 0x0c096d78 */
if(!s->budget--) { s->failed_pc=0x0c096d78u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c096d7a;
P_0c096d7a: /* original e044, guest PC 0x0c096d7a */
if(!s->budget--) { s->failed_pc=0x0c096d7au; return 0; }
r[0]=0x00000044u;
goto P_0c096d7c;
P_0c096d7c: /* original bdc1, guest PC 0x0c096d7c */
if(!s->budget--) { s->failed_pc=0x0c096d7cu; return 0; }
target=0x0c096902u; r[16]=0x0c096d80u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d80u) { target=s->pc; goto dispatch; }
goto P_0c096d80;
P_0c096d7e: /* original 04ee, guest PC 0x0c096d7e */
if(!s->budget--) { s->failed_pc=0x0c096d7eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d80;
P_0c096d80: /* original 52d2, guest PC 0x0c096d80 */
if(!s->budget--) { s->failed_pc=0x0c096d80u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d82;
P_0c096d82: /* original e044, guest PC 0x0c096d82 */
if(!s->budget--) { s->failed_pc=0x0c096d82u; return 0; }
r[0]=0x00000044u;
goto P_0c096d84;
P_0c096d84: /* original d325, guest PC 0x0c096d84 */
if(!s->budget--) { s->failed_pc=0x0c096d84u; return 0; }
r[3]=read(ram,0x0c096e1cu,4);
goto P_0c096d86;
P_0c096d86: /* original 223b, guest PC 0x0c096d86 */
if(!s->budget--) { s->failed_pc=0x0c096d86u; return 0; }
r[2]|=r[3];
goto P_0c096d88;
P_0c096d88: /* original 1d22, guest PC 0x0c096d88 */
if(!s->budget--) { s->failed_pc=0x0c096d88u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c096d8a;
P_0c096d8a: /* original e201, guest PC 0x0c096d8a */
if(!s->budget--) { s->failed_pc=0x0c096d8au; return 0; }
r[2]=0x00000001u;
goto P_0c096d8c;
P_0c096d8c: /* original d124, guest PC 0x0c096d8c */
if(!s->budget--) { s->failed_pc=0x0c096d8cu; return 0; }
r[1]=read(ram,0x0c096e20u,4);
goto P_0c096d8e;
P_0c096d8e: /* original 04ee, guest PC 0x0c096d8e */
if(!s->budget--) { s->failed_pc=0x0c096d8eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d90;
P_0c096d90: /* original 410b, guest PC 0x0c096d90 */
if(!s->budget--) { s->failed_pc=0x0c096d90u; return 0; }
target=r[1];
r[16]=0x0c096d94u;
write(ram,r[4],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d94u) { target=s->pc; goto dispatch; }
goto P_0c096d94;
P_0c096d92: /* original 2422, guest PC 0x0c096d92 */
if(!s->budget--) { s->failed_pc=0x0c096d92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c096d94;
P_0c096d94: /* original 55e5, guest PC 0x0c096d94 */
if(!s->budget--) { s->failed_pc=0x0c096d94u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c096d96;
P_0c096d96: /* original e400, guest PC 0x0c096d96 */
if(!s->budget--) { s->failed_pc=0x0c096d96u; return 0; }
r[4]=0x00000000u;
goto P_0c096d98;
P_0c096d98: /* original 56e4, guest PC 0x0c096d98 */
if(!s->budget--) { s->failed_pc=0x0c096d98u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c096d9a;
P_0c096d9a: /* original e061, guest PC 0x0c096d9a */
if(!s->budget--) { s->failed_pc=0x0c096d9au; return 0; }
r[0]=0x00000061u;
goto P_0c096d9c;
P_0c096d9c: /* original 0644, guest PC 0x0c096d9c */
if(!s->budget--) { s->failed_pc=0x0c096d9cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096d9e;
P_0c096d9e: /* original 0544, guest PC 0x0c096d9e */
if(!s->budget--) { s->failed_pc=0x0c096d9eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da0;
P_0c096da0: /* original e060, guest PC 0x0c096da0 */
if(!s->budget--) { s->failed_pc=0x0c096da0u; return 0; }
r[0]=0x00000060u;
goto P_0c096da2;
P_0c096da2: /* original 0644, guest PC 0x0c096da2 */
if(!s->budget--) { s->failed_pc=0x0c096da2u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096da4;
P_0c096da4: /* original 0544, guest PC 0x0c096da4 */
if(!s->budget--) { s->failed_pc=0x0c096da4u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da6;
P_0c096da6: /* original e016, guest PC 0x0c096da6 */
if(!s->budget--) { s->failed_pc=0x0c096da6u; return 0; }
r[0]=0x00000016u;
goto P_0c096da8;
P_0c096da8: /* original 63f2, guest PC 0x0c096da8 */
if(!s->budget--) { s->failed_pc=0x0c096da8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096daa;
P_0c096daa: /* original 7f04, guest PC 0x0c096daa */
if(!s->budget--) { s->failed_pc=0x0c096daau; return 0; }
r[15]+=0x00000004u;
goto P_0c096dac;
P_0c096dac: /* original 4f26, guest PC 0x0c096dac */
if(!s->budget--) { s->failed_pc=0x0c096dacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dae;
P_0c096dae: /* original 803a, guest PC 0x0c096dae */
if(!s->budget--) { s->failed_pc=0x0c096daeu; return 0; }
write(ram,r[3]+10,r[0],1);
goto P_0c096db0;
P_0c096db0: /* original 6df6, guest PC 0x0c096db0 */
if(!s->budget--) { s->failed_pc=0x0c096db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096db2;
P_0c096db2: /* original ad8d, guest PC 0x0c096db2 */
if(!s->budget--) { s->failed_pc=0x0c096db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0968d0;
P_0c096db4: /* original 6ef6, guest PC 0x0c096db4 */
if(!s->budget--) { s->failed_pc=0x0c096db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096db6;
P_0c096db6: /* original 7f04, guest PC 0x0c096db6 */
if(!s->budget--) { s->failed_pc=0x0c096db6u; return 0; }
r[15]+=0x00000004u;
goto P_0c096db8;
P_0c096db8: /* original 4f26, guest PC 0x0c096db8 */
if(!s->budget--) { s->failed_pc=0x0c096db8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dba;
P_0c096dba: /* original 6df6, guest PC 0x0c096dba */
if(!s->budget--) { s->failed_pc=0x0c096dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096dbc;
P_0c096dbc: /* original 000b, guest PC 0x0c096dbc */
if(!s->budget--) { s->failed_pc=0x0c096dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096dbe: /* original 6ef6, guest PC 0x0c096dbe */
if(!s->budget--) { s->failed_pc=0x0c096dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096dc0u,s,ram);
P_0c096f74: /* original 4f22, guest PC 0x0c096f74 */
if(!s->budget--) { s->failed_pc=0x0c096f74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096f76;
P_0c096f76: /* original 53e3, guest PC 0x0c096f76 */
if(!s->budget--) { s->failed_pc=0x0c096f76u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c096f78;
P_0c096f78: /* original 2338, guest PC 0x0c096f78 */
if(!s->budget--) { s->failed_pc=0x0c096f78u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c096f7a;
P_0c096f7a: /* original 8b0a, guest PC 0x0c096f7a */
if(!s->budget--) { s->failed_pc=0x0c096f7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096f92; }
goto P_0c096f7c;
P_0c096f7c: /* original d329, guest PC 0x0c096f7c */
if(!s->budget--) { s->failed_pc=0x0c096f7cu; return 0; }
r[3]=read(ram,0x0c097024u,4);
goto P_0c096f7e;
P_0c096f7e: /* original 430b, guest PC 0x0c096f7e */
if(!s->budget--) { s->failed_pc=0x0c096f7eu; return 0; }
target=r[3];
r[16]=0x0c096f82u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096f82u) { target=s->pc; goto dispatch; }
goto P_0c096f82;
P_0c096f80: /* original 0009, guest PC 0x0c096f80 */
if(!s->budget--) { s->failed_pc=0x0c096f80u; return 0; }
goto P_0c096f82;
P_0c096f82: /* original 2008, guest PC 0x0c096f82 */
if(!s->budget--) { s->failed_pc=0x0c096f82u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c096f84;
P_0c096f84: /* original 8b02, guest PC 0x0c096f84 */
if(!s->budget--) { s->failed_pc=0x0c096f84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096f8c; }
goto P_0c096f86;
P_0c096f86: /* original e301, guest PC 0x0c096f86 */
if(!s->budget--) { s->failed_pc=0x0c096f86u; return 0; }
r[3]=0x00000001u;
goto P_0c096f88;
P_0c096f88: /* original a003, guest PC 0x0c096f88 */
if(!s->budget--) { s->failed_pc=0x0c096f88u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c096f92;
P_0c096f8a: /* original 1e33, guest PC 0x0c096f8a */
if(!s->budget--) { s->failed_pc=0x0c096f8au; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c096f8c;
P_0c096f8c: /* original 84eb, guest PC 0x0c096f8c */
if(!s->budget--) { s->failed_pc=0x0c096f8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c096f8e;
P_0c096f8e: /* original 7001, guest PC 0x0c096f8e */
if(!s->budget--) { s->failed_pc=0x0c096f8eu; return 0; }
r[0]+=0x00000001u;
goto P_0c096f90;
P_0c096f90: /* original 80eb, guest PC 0x0c096f90 */
if(!s->budget--) { s->failed_pc=0x0c096f90u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c096f92;
P_0c096f92: /* original 4f26, guest PC 0x0c096f92 */
if(!s->budget--) { s->failed_pc=0x0c096f92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096f94;
P_0c096f94: /* original aee3, guest PC 0x0c096f94 */
if(!s->budget--) { s->failed_pc=0x0c096f94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d5e;
P_0c096f96: /* original 6ef6, guest PC 0x0c096f96 */
if(!s->budget--) { s->failed_pc=0x0c096f96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096f98u,s,ram);
P_0c0a13a4: /* original d224, guest PC 0x0c0a13a4 */
if(!s->budget--) { s->failed_pc=0x0c0a13a4u; return 0; }
r[2]=read(ram,0x0c0a1438u,4);
goto P_0c0a13a6;
P_0c0a13a6: /* original 6322, guest PC 0x0c0a13a6 */
if(!s->budget--) { s->failed_pc=0x0c0a13a6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a13a8;
P_0c0a13a8: /* original 435a, guest PC 0x0c0a13a8 */
if(!s->budget--) { s->failed_pc=0x0c0a13a8u; return 0; }
r[53]=r[3];
goto P_0c0a13aa;
P_0c0a13aa: /* original 4311, guest PC 0x0c0a13aa */
if(!s->budget--) { s->failed_pc=0x0c0a13aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0a13ac;
P_0c0a13ac: /* original 8d04, guest PC 0x0c0a13ac */
if(!s->budget--) { s->failed_pc=0x0c0a13acu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0a13b8; }
goto P_0c0a13b0;
P_0c0a13ae: /* original f32d, guest PC 0x0c0a13ae */
if(!s->budget--) { s->failed_pc=0x0c0a13aeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a13b0;
P_0c0a13b0: /* original d222, guest PC 0x0c0a13b0 */
if(!s->budget--) { s->failed_pc=0x0c0a13b0u; return 0; }
r[2]=read(ram,0x0c0a143cu,4);
goto P_0c0a13b2;
P_0c0a13b2: /* original 425a, guest PC 0x0c0a13b2 */
if(!s->budget--) { s->failed_pc=0x0c0a13b2u; return 0; }
r[53]=r[2];
goto P_0c0a13b4;
P_0c0a13b4: /* original f20d, guest PC 0x0c0a13b4 */
if(!s->budget--) { s->failed_pc=0x0c0a13b4u; return 0; }
fr[2]=r[53];
goto P_0c0a13b6;
P_0c0a13b6: /* original f320, guest PC 0x0c0a13b6 */
if(!s->budget--) { s->failed_pc=0x0c0a13b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0a13b8;
P_0c0a13b8: /* original c721, guest PC 0x0c0a13b8 */
if(!s->budget--) { s->failed_pc=0x0c0a13b8u; return 0; }
r[0]=0x0c0a1440u;
goto P_0c0a13ba;
P_0c0a13ba: /* original f03c, guest PC 0x0c0a13ba */
if(!s->budget--) { s->failed_pc=0x0c0a13bau; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0a13bc;
P_0c0a13bc: /* original f208, guest PC 0x0c0a13bc */
if(!s->budget--) { s->failed_pc=0x0c0a13bcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0a13be;
P_0c0a13be: /* original 000b, guest PC 0x0c0a13be */
if(!s->budget--) { s->failed_pc=0x0c0a13beu; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c0a13c0: /* original f023, guest PC 0x0c0a13c0 */
if(!s->budget--) { s->failed_pc=0x0c0a13c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'/');
return vf3_matrix_family(0x0c0a13c2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c045ba8u,0x0c045baau,0x0c045bacu,0x0c045baeu,0x0c045bb0u,0x0c045bb2u,0x0c045bb4u,0x0c045bb6u,0x0c045bb8u,0x0c045bbau,0x0c045bbcu,0x0c045bbeu,0x0c045bc0u,0x0c045bc2u,0x0c045bc4u,0x0c045bc6u,
0x0c045bc8u,0x0c06f75au,0x0c06f75cu,0x0c06f75eu,0x0c06f760u,0x0c06f762u,0x0c06f764u,0x0c06f766u,0x0c06f768u,0x0c06f76au,0x0c06f76cu,0x0c06f76eu,0x0c06f770u,0x0c06f772u,0x0c06f774u,0x0c06f776u,
0x0c06f778u,0x0c06f77au,0x0c06f77cu,0x0c06f77eu,0x0c06f780u,0x0c06f782u,0x0c06f784u,0x0c06f786u,0x0c06f788u,0x0c06f78au,0x0c06f78cu,0x0c06f78eu,0x0c06f790u,0x0c06f792u,0x0c06f794u,0x0c06f796u,
0x0c06f798u,0x0c06f79au,0x0c06f79cu,0x0c06f79eu,0x0c06f7a0u,0x0c06f7a2u,0x0c06f7a4u,0x0c06f7a6u,0x0c06f7a8u,0x0c06f7aau,0x0c06f7acu,0x0c06f7aeu,0x0c06f7b0u,0x0c06f7b2u,0x0c06f7b4u,0x0c06f7b6u,
0x0c06f7b8u,0x0c06f7bau,0x0c06f7bcu,0x0c06f7beu,0x0c06f7c0u,0x0c06f7c2u,0x0c06f7c4u,0x0c06f7c6u,0x0c06f7c8u,0x0c06f7cau,0x0c06f7ccu,0x0c06f7ceu,0x0c06f7d0u,0x0c06f7d2u,0x0c06f7d4u,0x0c06f7d6u,
0x0c06f7d8u,0x0c06f7dau,0x0c06f7dcu,0x0c06f7deu,0x0c06f7e0u,0x0c06f7e2u,0x0c06f7e4u,0x0c06f7e6u,0x0c06f7e8u,0x0c06f7eau,0x0c06f7ecu,0x0c06f7eeu,0x0c06f7f0u,0x0c06f7f2u,0x0c06f7f4u,0x0c06f7f6u,
0x0c06f7f8u,0x0c06f7fau,0x0c06f7fcu,0x0c06f7feu,0x0c06f800u,0x0c06f802u,0x0c06f804u,0x0c06f806u,0x0c06f808u,0x0c06f80au,0x0c06f80cu,0x0c06f80eu,0x0c06f810u,0x0c06f812u,0x0c06f814u,0x0c06f816u,
0x0c06f818u,0x0c06f81au,0x0c06f81cu,0x0c06f81eu,0x0c06f820u,0x0c06f822u,0x0c06f824u,0x0c06f826u,0x0c06f828u,0x0c06f82au,0x0c06f82cu,0x0c06f82eu,0x0c06f830u,0x0c06f832u,0x0c06f834u,0x0c06f836u,
0x0c06f838u,0x0c06f83au,0x0c06f83cu,0x0c06f83eu,0x0c06f840u,0x0c06f842u,0x0c06f844u,0x0c06f846u,0x0c06f848u,0x0c06f84au,0x0c06f84cu,0x0c06f84eu,0x0c06f850u,0x0c06f852u,0x0c06f854u,0x0c06f856u,
0x0c06f858u,0x0c06f85au,0x0c06f85cu,0x0c06f85eu,0x0c06f860u,0x0c06f862u,0x0c06f864u,0x0c06f866u,0x0c06f868u,0x0c06f86au,0x0c06f86cu,0x0c06f86eu,0x0c06f870u,0x0c06f872u,0x0c06f874u,0x0c06f876u,
0x0c06f878u,0x0c06f87au,0x0c06f87cu,0x0c06f87eu,0x0c06f880u,0x0c06f882u,0x0c06f884u,0x0c06f886u,0x0c06f888u,0x0c06f88au,0x0c06f88cu,0x0c06f88eu,0x0c06f890u,0x0c06f892u,0x0c06f894u,0x0c06f896u,
0x0c06f898u,0x0c06f89au,0x0c06f89cu,0x0c06f89eu,0x0c06f8a0u,0x0c06f8a2u,0x0c06f8a4u,0x0c06f8a6u,0x0c06f8a8u,0x0c06f8aau,0x0c06f8acu,0x0c06f8aeu,0x0c06f8b0u,0x0c06f8b2u,0x0c06f8b4u,0x0c06f8b6u,
0x0c06f8b8u,0x0c06f8bau,0x0c06f8bcu,0x0c06f8beu,0x0c06f8c0u,0x0c06f8c2u,0x0c06f8c4u,0x0c06f8c6u,0x0c06f8c8u,0x0c06f8cau,0x0c06f8ccu,0x0c06f8ceu,0x0c06f8d0u,0x0c06f8d2u,0x0c06f8d4u,0x0c06f8d6u,
0x0c06f8d8u,0x0c06f8dau,0x0c06f8dcu,0x0c06f8deu,0x0c06f8e0u,0x0c06f8e2u,0x0c06f8e4u,0x0c06f8e6u,0x0c06f8e8u,0x0c06f8eau,0x0c06f8ecu,0x0c06f8eeu,0x0c06f8f0u,0x0c06f8f2u,0x0c06f8f4u,0x0c06f8f6u,
0x0c06f8f8u,0x0c06f8fau,0x0c06f8fcu,0x0c06f8feu,0x0c06f900u,0x0c06f902u,0x0c06f904u,0x0c06f906u,0x0c06f908u,0x0c06f90au,0x0c06f90cu,0x0c06f90eu,0x0c06f910u,0x0c06f912u,0x0c06f914u,0x0c06f916u,
0x0c06f918u,0x0c06f91au,0x0c06f91cu,0x0c06f91eu,0x0c06f920u,0x0c06f922u,0x0c06f924u,0x0c06f926u,0x0c06f928u,0x0c06f92au,0x0c06f92cu,0x0c06f92eu,0x0c06f930u,0x0c06f932u,0x0c06f934u,0x0c06f936u,
0x0c06f938u,0x0c06f93au,0x0c06f93cu,0x0c06f93eu,0x0c06f940u,0x0c06f942u,0x0c06f944u,0x0c06f946u,0x0c06f948u,0x0c06f94au,0x0c06f94cu,0x0c06f94eu,0x0c06f950u,0x0c06f952u,0x0c06f954u,0x0c06f956u,
0x0c06f958u,0x0c06f95au,0x0c06f95cu,0x0c06f95eu,0x0c06f960u,0x0c06f962u,0x0c06f964u,0x0c06f966u,0x0c06f968u,0x0c06f96au,0x0c06f96cu,0x0c06f96eu,0x0c06f970u,0x0c06f972u,0x0c06f974u,0x0c06f976u,
0x0c06f978u,0x0c06f97au,0x0c06f97cu,0x0c06f97eu,0x0c06f980u,0x0c06f982u,0x0c06f984u,0x0c06f986u,0x0c06f988u,0x0c06f98au,0x0c06f98cu,0x0c06f98eu,0x0c06f990u,0x0c070caau,0x0c070cacu,0x0c070caeu,
0x0c070cb0u,0x0c070cb2u,0x0c070cb4u,0x0c070cb6u,0x0c070cb8u,0x0c070cbau,0x0c070cbcu,0x0c070cbeu,0x0c070cc0u,0x0c070cc2u,0x0c070cc4u,0x0c070cc6u,0x0c070cc8u,0x0c070ccau,0x0c070cccu,0x0c070cceu,
0x0c070cd0u,0x0c070cd2u,0x0c070cd4u,0x0c070cd6u,0x0c070cd8u,0x0c070cdau,0x0c070cdcu,0x0c070cdeu,0x0c070ce0u,0x0c070ce2u,0x0c070ce4u,0x0c070ce6u,0x0c070ce8u,0x0c070ceau,0x0c070cecu,0x0c070ceeu,
0x0c070cf0u,0x0c070cf2u,0x0c070cf4u,0x0c070cf6u,0x0c070cf8u,0x0c070cfau,0x0c070cfcu,0x0c070cfeu,0x0c070d00u,0x0c070d02u,0x0c070d04u,0x0c070d06u,0x0c070d08u,0x0c070d0au,0x0c070d0cu,0x0c070d0eu,
0x0c070d10u,0x0c070d12u,0x0c070d14u,0x0c070d16u,0x0c070d18u,0x0c070d1au,0x0c070d1cu,0x0c070d1eu,0x0c070d24u,0x0c070d26u,0x0c070d28u,0x0c070d2au,0x0c070d2cu,0x0c070d2eu,0x0c070d30u,0x0c070d32u,
0x0c070d34u,0x0c070d36u,0x0c070d38u,0x0c070d3au,0x0c070d3cu,0x0c070d3eu,0x0c070d40u,0x0c070d42u,0x0c070d44u,0x0c070d46u,0x0c070d48u,0x0c070d4au,0x0c070d4cu,0x0c070d4eu,0x0c070d50u,0x0c070d52u,
0x0c070d54u,0x0c070d56u,0x0c070d58u,0x0c070d5au,0x0c070d5cu,0x0c070d5eu,0x0c070d60u,0x0c070d62u,0x0c070d64u,0x0c070d66u,0x0c070d68u,0x0c070d6au,0x0c070d70u,0x0c070d72u,0x0c070d74u,0x0c070d76u,
0x0c070d78u,0x0c070d7au,0x0c070d7cu,0x0c070d7eu,0x0c070d80u,0x0c070d82u,0x0c070d84u,0x0c070d86u,0x0c070d88u,0x0c070d8au,0x0c070d8cu,0x0c070d8eu,0x0c070d90u,0x0c070d92u,0x0c070d94u,0x0c070d96u,
0x0c070d98u,0x0c070d9au,0x0c070d9cu,0x0c070d9eu,0x0c070da0u,0x0c070da2u,0x0c070da4u,0x0c070da6u,0x0c070da8u,0x0c070db4u,0x0c070db6u,0x0c070db8u,0x0c070dbau,0x0c070dbcu,0x0c070dbeu,0x0c070dc0u,
0x0c070dc2u,0x0c070dc4u,0x0c070dc6u,0x0c070dc8u,0x0c070dcau,0x0c070dccu,0x0c070dceu,0x0c070dd0u,0x0c070dd2u,0x0c070dd4u,0x0c0710e2u,0x0c0710e4u,0x0c0710e6u,0x0c0710e8u,0x0c0710eau,0x0c0710ecu,
0x0c0710eeu,0x0c0710f0u,0x0c0710f2u,0x0c0710f4u,0x0c0710f6u,0x0c0710f8u,0x0c0710fau,0x0c0710fcu,0x0c0710feu,0x0c071100u,0x0c071102u,0x0c071104u,0x0c071106u,0x0c071108u,0x0c07110au,0x0c07110cu,
0x0c07110eu,0x0c071110u,0x0c071112u,0x0c071114u,0x0c071116u,0x0c071118u,0x0c07111au,0x0c07111cu,0x0c07111eu,0x0c071120u,0x0c071122u,0x0c071124u,0x0c071126u,0x0c071128u,0x0c07112au,0x0c07112cu,
0x0c07112eu,0x0c071130u,0x0c071132u,0x0c071134u,0x0c071136u,0x0c071138u,0x0c07113au,0x0c07113cu,0x0c07113eu,0x0c08b430u,0x0c08b432u,0x0c08b434u,0x0c08b436u,0x0c08b438u,0x0c08b43au,0x0c08b43cu,
0x0c08b43eu,0x0c08b440u,0x0c08b442u,0x0c08b444u,0x0c08b446u,0x0c08b448u,0x0c08b44au,0x0c08b44cu,0x0c08b44eu,0x0c08b450u,0x0c08b452u,0x0c08b454u,0x0c08b456u,0x0c08b458u,0x0c08b45au,0x0c08b45cu,
0x0c08b45eu,0x0c08b460u,0x0c08b462u,0x0c08b464u,0x0c08b466u,0x0c08b468u,0x0c08b46au,0x0c08b46cu,0x0c08b46eu,0x0c08b470u,0x0c08b472u,0x0c08b474u,0x0c08b476u,0x0c08b478u,0x0c08b47au,0x0c08b47cu,
0x0c08b47eu,0x0c08b480u,0x0c08b482u,0x0c08b484u,0x0c08b486u,0x0c08b488u,0x0c08b48au,0x0c08b48cu,0x0c08b48eu,0x0c08b490u,0x0c08b492u,0x0c08b494u,0x0c08b496u,0x0c08b498u,0x0c08b49au,0x0c08b49cu,
0x0c08b49eu,0x0c08b4a0u,0x0c08b4a2u,0x0c08b4a4u,0x0c08b4a6u,0x0c08b4a8u,0x0c08b4aau,0x0c08b4acu,0x0c08b4aeu,0x0c08b4b0u,0x0c08b4b2u,0x0c08b4b4u,0x0c08b4b6u,0x0c08b4b8u,0x0c08b4bau,0x0c08b4bcu,
0x0c08b4beu,0x0c08b4c0u,0x0c08b4c2u,0x0c08b4c4u,0x0c08b4c6u,0x0c08b4c8u,0x0c08b4cau,0x0c08b4ccu,0x0c08b4ceu,0x0c08b4d0u,0x0c08b4d2u,0x0c08b4d4u,0x0c08b4d6u,0x0c08b4d8u,0x0c08b4dau,0x0c08b4dcu,
0x0c08b4deu,0x0c08b4e0u,0x0c08b4e2u,0x0c08b4e4u,0x0c08b4e6u,0x0c08b4e8u,0x0c08b4eau,0x0c08b4ecu,0x0c08b4eeu,0x0c08b4f0u,0x0c08b4f2u,0x0c08b4f4u,0x0c08b4f6u,0x0c08b4f8u,0x0c08b57eu,0x0c08b580u,
0x0c08b582u,0x0c08b584u,0x0c08b586u,0x0c08b588u,0x0c08b58au,0x0c08b58cu,0x0c08b58eu,0x0c08b590u,0x0c08b592u,0x0c08b594u,0x0c08b596u,0x0c08b598u,0x0c08b59au,0x0c08b59cu,0x0c08b59eu,0x0c08b5a0u,
0x0c08b5a2u,0x0c08b5a4u,0x0c08b5a6u,0x0c08b5a8u,0x0c08b5aau,0x0c0968d0u,0x0c0968d2u,0x0c0968d4u,0x0c0968d6u,0x0c0968d8u,0x0c0968dau,0x0c0968dcu,0x0c0968deu,0x0c0968e0u,0x0c0968e2u,0x0c0968e4u,
0x0c0968e6u,0x0c0968e8u,0x0c0968eau,0x0c0968ecu,0x0c0968eeu,0x0c0968f0u,0x0c0968f2u,0x0c0968f4u,0x0c0968f6u,0x0c096902u,0x0c096904u,0x0c096906u,0x0c096908u,0x0c096d5eu,0x0c096d60u,0x0c096d62u,
0x0c096d64u,0x0c096d66u,0x0c096d68u,0x0c096d6au,0x0c096d6cu,0x0c096d6eu,0x0c096d70u,0x0c096d72u,0x0c096d74u,0x0c096d76u,0x0c096d78u,0x0c096d7au,0x0c096d7cu,0x0c096d7eu,0x0c096d80u,0x0c096d82u,
0x0c096d84u,0x0c096d86u,0x0c096d88u,0x0c096d8au,0x0c096d8cu,0x0c096d8eu,0x0c096d90u,0x0c096d92u,0x0c096d94u,0x0c096d96u,0x0c096d98u,0x0c096d9au,0x0c096d9cu,0x0c096d9eu,0x0c096da0u,0x0c096da2u,
0x0c096da4u,0x0c096da6u,0x0c096da8u,0x0c096daau,0x0c096dacu,0x0c096daeu,0x0c096db0u,0x0c096db2u,0x0c096db4u,0x0c096db6u,0x0c096db8u,0x0c096dbau,0x0c096dbcu,0x0c096dbeu,0x0c096f74u,0x0c096f76u,
0x0c096f78u,0x0c096f7au,0x0c096f7cu,0x0c096f7eu,0x0c096f80u,0x0c096f82u,0x0c096f84u,0x0c096f86u,0x0c096f88u,0x0c096f8au,0x0c096f8cu,0x0c096f8eu,0x0c096f90u,0x0c096f92u,0x0c096f94u,0x0c096f96u,
0x0c0a13a4u,0x0c0a13a6u,0x0c0a13a8u,0x0c0a13aau,0x0c0a13acu,0x0c0a13aeu,0x0c0a13b0u,0x0c0a13b2u,0x0c0a13b4u,0x0c0a13b6u,0x0c0a13b8u,0x0c0a13bau,0x0c0a13bcu,0x0c0a13beu,0x0c0a13c0u,
};
int vf3_seventh_c8_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
