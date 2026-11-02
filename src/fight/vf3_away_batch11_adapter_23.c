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
int vf3_away_batch11_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c636u: goto P_0c06c636;
case 0x0c06c638u: goto P_0c06c638;
case 0x0c06c63au: goto P_0c06c63a;
case 0x0c06c63cu: goto P_0c06c63c;
case 0x0c06c63eu: goto P_0c06c63e;
case 0x0c06c640u: goto P_0c06c640;
case 0x0c06c642u: goto P_0c06c642;
case 0x0c06c644u: goto P_0c06c644;
case 0x0c06c646u: goto P_0c06c646;
case 0x0c06c648u: goto P_0c06c648;
case 0x0c06c64au: goto P_0c06c64a;
case 0x0c06c64cu: goto P_0c06c64c;
case 0x0c06c64eu: goto P_0c06c64e;
case 0x0c06c650u: goto P_0c06c650;
case 0x0c06c652u: goto P_0c06c652;
case 0x0c06c654u: goto P_0c06c654;
case 0x0c06c656u: goto P_0c06c656;
case 0x0c06c658u: goto P_0c06c658;
case 0x0c06c65au: goto P_0c06c65a;
case 0x0c06c65cu: goto P_0c06c65c;
case 0x0c06c65eu: goto P_0c06c65e;
case 0x0c06c660u: goto P_0c06c660;
case 0x0c06c662u: goto P_0c06c662;
case 0x0c06c664u: goto P_0c06c664;
case 0x0c06c666u: goto P_0c06c666;
case 0x0c06c668u: goto P_0c06c668;
case 0x0c06c66au: goto P_0c06c66a;
case 0x0c06c66cu: goto P_0c06c66c;
case 0x0c06c66eu: goto P_0c06c66e;
case 0x0c06c670u: goto P_0c06c670;
case 0x0c06c672u: goto P_0c06c672;
case 0x0c06c674u: goto P_0c06c674;
case 0x0c06c676u: goto P_0c06c676;
case 0x0c06c678u: goto P_0c06c678;
case 0x0c06c67au: goto P_0c06c67a;
case 0x0c06c67cu: goto P_0c06c67c;
case 0x0c06c67eu: goto P_0c06c67e;
case 0x0c06c680u: goto P_0c06c680;
case 0x0c06c682u: goto P_0c06c682;
case 0x0c06c684u: goto P_0c06c684;
case 0x0c06c686u: goto P_0c06c686;
case 0x0c06c688u: goto P_0c06c688;
case 0x0c06c68au: goto P_0c06c68a;
case 0x0c06c68cu: goto P_0c06c68c;
case 0x0c06c68eu: goto P_0c06c68e;
case 0x0c06c690u: goto P_0c06c690;
case 0x0c06c692u: goto P_0c06c692;
case 0x0c06c694u: goto P_0c06c694;
case 0x0c06c696u: goto P_0c06c696;
case 0x0c06c698u: goto P_0c06c698;
case 0x0c06c69au: goto P_0c06c69a;
case 0x0c06c69cu: goto P_0c06c69c;
case 0x0c06c69eu: goto P_0c06c69e;
case 0x0c06c6a0u: goto P_0c06c6a0;
case 0x0c06c6a2u: goto P_0c06c6a2;
case 0x0c06c6a4u: goto P_0c06c6a4;
case 0x0c06c6a6u: goto P_0c06c6a6;
case 0x0c06c6a8u: goto P_0c06c6a8;
case 0x0c06c6aau: goto P_0c06c6aa;
case 0x0c06c6acu: goto P_0c06c6ac;
case 0x0c06c6aeu: goto P_0c06c6ae;
case 0x0c06c6b0u: goto P_0c06c6b0;
case 0x0c06c6b2u: goto P_0c06c6b2;
case 0x0c06c6b4u: goto P_0c06c6b4;
case 0x0c06c6b6u: goto P_0c06c6b6;
case 0x0c06c6b8u: goto P_0c06c6b8;
case 0x0c06c6bau: goto P_0c06c6ba;
case 0x0c06c6bcu: goto P_0c06c6bc;
case 0x0c06c6beu: goto P_0c06c6be;
case 0x0c06c6c0u: goto P_0c06c6c0;
case 0x0c06c6c2u: goto P_0c06c6c2;
case 0x0c06c6c4u: goto P_0c06c6c4;
case 0x0c06c6c6u: goto P_0c06c6c6;
case 0x0c06c6c8u: goto P_0c06c6c8;
case 0x0c06c6cau: goto P_0c06c6ca;
case 0x0c06c6ccu: goto P_0c06c6cc;
case 0x0c06c6ceu: goto P_0c06c6ce;
case 0x0c06c6d0u: goto P_0c06c6d0;
case 0x0c06c6d2u: goto P_0c06c6d2;
case 0x0c06c6d4u: goto P_0c06c6d4;
case 0x0c06c6d6u: goto P_0c06c6d6;
case 0x0c06c6d8u: goto P_0c06c6d8;
case 0x0c06c6dau: goto P_0c06c6da;
case 0x0c06c6dcu: goto P_0c06c6dc;
case 0x0c06c6deu: goto P_0c06c6de;
case 0x0c06c720u: goto P_0c06c720;
case 0x0c06c722u: goto P_0c06c722;
case 0x0c06c724u: goto P_0c06c724;
case 0x0c06c726u: goto P_0c06c726;
case 0x0c06c728u: goto P_0c06c728;
case 0x0c06c72au: goto P_0c06c72a;
case 0x0c06c72cu: goto P_0c06c72c;
case 0x0c06c72eu: goto P_0c06c72e;
case 0x0c06c730u: goto P_0c06c730;
case 0x0c06c732u: goto P_0c06c732;
case 0x0c06c734u: goto P_0c06c734;
case 0x0c06c736u: goto P_0c06c736;
case 0x0c06c738u: goto P_0c06c738;
case 0x0c06c73au: goto P_0c06c73a;
case 0x0c06c73cu: goto P_0c06c73c;
case 0x0c06c73eu: goto P_0c06c73e;
case 0x0c06c740u: goto P_0c06c740;
case 0x0c06c742u: goto P_0c06c742;
case 0x0c06c744u: goto P_0c06c744;
case 0x0c06c746u: goto P_0c06c746;
case 0x0c06c748u: goto P_0c06c748;
case 0x0c06c74au: goto P_0c06c74a;
case 0x0c06c74cu: goto P_0c06c74c;
case 0x0c06c74eu: goto P_0c06c74e;
case 0x0c06c750u: goto P_0c06c750;
case 0x0c06c752u: goto P_0c06c752;
case 0x0c06c754u: goto P_0c06c754;
case 0x0c06c756u: goto P_0c06c756;
case 0x0c06c758u: goto P_0c06c758;
case 0x0c06c75au: goto P_0c06c75a;
case 0x0c06c75cu: goto P_0c06c75c;
case 0x0c06c75eu: goto P_0c06c75e;
case 0x0c06c760u: goto P_0c06c760;
case 0x0c06c762u: goto P_0c06c762;
case 0x0c06c764u: goto P_0c06c764;
case 0x0c06c766u: goto P_0c06c766;
case 0x0c06c768u: goto P_0c06c768;
case 0x0c06c76au: goto P_0c06c76a;
case 0x0c06c76cu: goto P_0c06c76c;
case 0x0c06c76eu: goto P_0c06c76e;
case 0x0c06c770u: goto P_0c06c770;
case 0x0c06c772u: goto P_0c06c772;
case 0x0c06c774u: goto P_0c06c774;
case 0x0c06c776u: goto P_0c06c776;
case 0x0c06c778u: goto P_0c06c778;
case 0x0c06c77au: goto P_0c06c77a;
case 0x0c06c77cu: goto P_0c06c77c;
case 0x0c06c77eu: goto P_0c06c77e;
case 0x0c06c780u: goto P_0c06c780;
case 0x0c06c782u: goto P_0c06c782;
case 0x0c06c784u: goto P_0c06c784;
case 0x0c06c786u: goto P_0c06c786;
case 0x0c06c788u: goto P_0c06c788;
case 0x0c06c78au: goto P_0c06c78a;
case 0x0c06c78cu: goto P_0c06c78c;
case 0x0c06c78eu: goto P_0c06c78e;
case 0x0c06c790u: goto P_0c06c790;
case 0x0c06c792u: goto P_0c06c792;
case 0x0c06c794u: goto P_0c06c794;
case 0x0c06c796u: goto P_0c06c796;
case 0x0c06c798u: goto P_0c06c798;
case 0x0c06c79au: goto P_0c06c79a;
case 0x0c06c79cu: goto P_0c06c79c;
case 0x0c06c79eu: goto P_0c06c79e;
case 0x0c06c7a0u: goto P_0c06c7a0;
case 0x0c06c7a2u: goto P_0c06c7a2;
case 0x0c06c7a4u: goto P_0c06c7a4;
case 0x0c06c7a6u: goto P_0c06c7a6;
case 0x0c06c7a8u: goto P_0c06c7a8;
case 0x0c06c7aau: goto P_0c06c7aa;
case 0x0c06c7acu: goto P_0c06c7ac;
case 0x0c06c7aeu: goto P_0c06c7ae;
case 0x0c06c7b0u: goto P_0c06c7b0;
case 0x0c06c7b2u: goto P_0c06c7b2;
case 0x0c06c7b4u: goto P_0c06c7b4;
case 0x0c06c7b6u: goto P_0c06c7b6;
case 0x0c06c7b8u: goto P_0c06c7b8;
case 0x0c06c7bau: goto P_0c06c7ba;
case 0x0c06c7bcu: goto P_0c06c7bc;
case 0x0c06c7beu: goto P_0c06c7be;
case 0x0c06c7c0u: goto P_0c06c7c0;
case 0x0c06c7c2u: goto P_0c06c7c2;
case 0x0c06c7c4u: goto P_0c06c7c4;
case 0x0c06c7c6u: goto P_0c06c7c6;
case 0x0c06c7c8u: goto P_0c06c7c8;
case 0x0c06c7cau: goto P_0c06c7ca;
case 0x0c06e8a2u: goto P_0c06e8a2;
case 0x0c06e8a4u: goto P_0c06e8a4;
case 0x0c06e8a6u: goto P_0c06e8a6;
case 0x0c06e8a8u: goto P_0c06e8a8;
case 0x0c06e8aau: goto P_0c06e8aa;
case 0x0c06e8acu: goto P_0c06e8ac;
case 0x0c06e8aeu: goto P_0c06e8ae;
case 0x0c06e8b0u: goto P_0c06e8b0;
case 0x0c06e8b2u: goto P_0c06e8b2;
case 0x0c06e8b4u: goto P_0c06e8b4;
case 0x0c06e8b6u: goto P_0c06e8b6;
case 0x0c06e8b8u: goto P_0c06e8b8;
case 0x0c06e8bau: goto P_0c06e8ba;
case 0x0c06e8bcu: goto P_0c06e8bc;
case 0x0c06e8beu: goto P_0c06e8be;
case 0x0c06e8c0u: goto P_0c06e8c0;
case 0x0c06e8c2u: goto P_0c06e8c2;
case 0x0c06e8c4u: goto P_0c06e8c4;
case 0x0c06e8c6u: goto P_0c06e8c6;
case 0x0c06e8c8u: goto P_0c06e8c8;
case 0x0c06e8cau: goto P_0c06e8ca;
case 0x0c06e8ccu: goto P_0c06e8cc;
case 0x0c06e8ceu: goto P_0c06e8ce;
case 0x0c06e8d0u: goto P_0c06e8d0;
case 0x0c06e8d2u: goto P_0c06e8d2;
case 0x0c06e8d4u: goto P_0c06e8d4;
case 0x0c06e8d6u: goto P_0c06e8d6;
case 0x0c06e8d8u: goto P_0c06e8d8;
case 0x0c06e8dau: goto P_0c06e8da;
case 0x0c06e8dcu: goto P_0c06e8dc;
case 0x0c06e8deu: goto P_0c06e8de;
case 0x0c06e8e0u: goto P_0c06e8e0;
case 0x0c06e8e2u: goto P_0c06e8e2;
case 0x0c06e8e4u: goto P_0c06e8e4;
case 0x0c06e8e6u: goto P_0c06e8e6;
case 0x0c06e8e8u: goto P_0c06e8e8;
case 0x0c06e8eau: goto P_0c06e8ea;
case 0x0c06e8ecu: goto P_0c06e8ec;
case 0x0c06e8eeu: goto P_0c06e8ee;
case 0x0c06e8f0u: goto P_0c06e8f0;
case 0x0c06e8f2u: goto P_0c06e8f2;
case 0x0c06e8f4u: goto P_0c06e8f4;
case 0x0c06e8f6u: goto P_0c06e8f6;
case 0x0c06e8f8u: goto P_0c06e8f8;
case 0x0c06e8fau: goto P_0c06e8fa;
case 0x0c06e8fcu: goto P_0c06e8fc;
case 0x0c06e8feu: goto P_0c06e8fe;
case 0x0c06e900u: goto P_0c06e900;
case 0x0c06e902u: goto P_0c06e902;
case 0x0c06e904u: goto P_0c06e904;
case 0x0c06e906u: goto P_0c06e906;
case 0x0c06e908u: goto P_0c06e908;
case 0x0c06e90au: goto P_0c06e90a;
case 0x0c06e90cu: goto P_0c06e90c;
case 0x0c06e90eu: goto P_0c06e90e;
case 0x0c06e910u: goto P_0c06e910;
case 0x0c06e912u: goto P_0c06e912;
case 0x0c06e914u: goto P_0c06e914;
case 0x0c06e916u: goto P_0c06e916;
case 0x0c06e918u: goto P_0c06e918;
case 0x0c06e91au: goto P_0c06e91a;
case 0x0c06e91cu: goto P_0c06e91c;
case 0x0c06e91eu: goto P_0c06e91e;
case 0x0c06e920u: goto P_0c06e920;
case 0x0c06e922u: goto P_0c06e922;
case 0x0c06e924u: goto P_0c06e924;
case 0x0c06e926u: goto P_0c06e926;
case 0x0c06e928u: goto P_0c06e928;
case 0x0c06e92au: goto P_0c06e92a;
case 0x0c06e92cu: goto P_0c06e92c;
case 0x0c06e92eu: goto P_0c06e92e;
case 0x0c06e930u: goto P_0c06e930;
case 0x0c06e932u: goto P_0c06e932;
case 0x0c06e934u: goto P_0c06e934;
case 0x0c06e936u: goto P_0c06e936;
case 0x0c06e938u: goto P_0c06e938;
case 0x0c06e93au: goto P_0c06e93a;
case 0x0c06e93cu: goto P_0c06e93c;
case 0x0c06e93eu: goto P_0c06e93e;
case 0x0c06e940u: goto P_0c06e940;
case 0x0c06e964u: goto P_0c06e964;
case 0x0c06e966u: goto P_0c06e966;
case 0x0c06e968u: goto P_0c06e968;
case 0x0c06e96au: goto P_0c06e96a;
case 0x0c06e96cu: goto P_0c06e96c;
case 0x0c06e96eu: goto P_0c06e96e;
case 0x0c06e970u: goto P_0c06e970;
case 0x0c06e972u: goto P_0c06e972;
case 0x0c06e974u: goto P_0c06e974;
case 0x0c06e976u: goto P_0c06e976;
case 0x0c06e978u: goto P_0c06e978;
case 0x0c06e97au: goto P_0c06e97a;
case 0x0c06e97cu: goto P_0c06e97c;
case 0x0c06e97eu: goto P_0c06e97e;
case 0x0c06e980u: goto P_0c06e980;
case 0x0c06e982u: goto P_0c06e982;
case 0x0c06e984u: goto P_0c06e984;
case 0x0c06e986u: goto P_0c06e986;
case 0x0c06e988u: goto P_0c06e988;
case 0x0c06e98au: goto P_0c06e98a;
case 0x0c06e98cu: goto P_0c06e98c;
case 0x0c06e98eu: goto P_0c06e98e;
case 0x0c06e990u: goto P_0c06e990;
case 0x0c06e992u: goto P_0c06e992;
case 0x0c06e994u: goto P_0c06e994;
case 0x0c06e996u: goto P_0c06e996;
case 0x0c06e998u: goto P_0c06e998;
case 0x0c06e99au: goto P_0c06e99a;
case 0x0c06e99cu: goto P_0c06e99c;
case 0x0c06e99eu: goto P_0c06e99e;
case 0x0c06e9a0u: goto P_0c06e9a0;
case 0x0c06e9a2u: goto P_0c06e9a2;
case 0x0c06e9a4u: goto P_0c06e9a4;
case 0x0c06e9a6u: goto P_0c06e9a6;
case 0x0c06e9a8u: goto P_0c06e9a8;
case 0x0c06e9aau: goto P_0c06e9aa;
case 0x0c06e9acu: goto P_0c06e9ac;
case 0x0c06e9aeu: goto P_0c06e9ae;
case 0x0c06e9b0u: goto P_0c06e9b0;
case 0x0c06e9b2u: goto P_0c06e9b2;
case 0x0c06e9b4u: goto P_0c06e9b4;
case 0x0c06e9b6u: goto P_0c06e9b6;
case 0x0c06e9b8u: goto P_0c06e9b8;
case 0x0c06e9bau: goto P_0c06e9ba;
case 0x0c06e9bcu: goto P_0c06e9bc;
case 0x0c06e9beu: goto P_0c06e9be;
case 0x0c06e9c0u: goto P_0c06e9c0;
case 0x0c06e9c2u: goto P_0c06e9c2;
case 0x0c06e9c4u: goto P_0c06e9c4;
case 0x0c06e9c6u: goto P_0c06e9c6;
case 0x0c06e9c8u: goto P_0c06e9c8;
case 0x0c06e9cau: goto P_0c06e9ca;
case 0x0c06e9ccu: goto P_0c06e9cc;
case 0x0c06e9ceu: goto P_0c06e9ce;
case 0x0c06e9d0u: goto P_0c06e9d0;
case 0x0c06e9d2u: goto P_0c06e9d2;
case 0x0c06e9d4u: goto P_0c06e9d4;
case 0x0c06e9d6u: goto P_0c06e9d6;
case 0x0c06e9d8u: goto P_0c06e9d8;
case 0x0c06e9dau: goto P_0c06e9da;
case 0x0c06e9dcu: goto P_0c06e9dc;
case 0x0c06e9deu: goto P_0c06e9de;
case 0x0c06e9e0u: goto P_0c06e9e0;
case 0x0c06e9e2u: goto P_0c06e9e2;
case 0x0c06e9e4u: goto P_0c06e9e4;
case 0x0c06e9e6u: goto P_0c06e9e6;
case 0x0c06e9e8u: goto P_0c06e9e8;
case 0x0c06e9eau: goto P_0c06e9ea;
case 0x0c06e9ecu: goto P_0c06e9ec;
case 0x0c06e9eeu: goto P_0c06e9ee;
case 0x0c06e9f0u: goto P_0c06e9f0;
case 0x0c06e9f2u: goto P_0c06e9f2;
case 0x0c06e9f4u: goto P_0c06e9f4;
case 0x0c06e9f6u: goto P_0c06e9f6;
case 0x0c06e9f8u: goto P_0c06e9f8;
case 0x0c06e9fau: goto P_0c06e9fa;
case 0x0c06e9fcu: goto P_0c06e9fc;
case 0x0c06e9feu: goto P_0c06e9fe;
case 0x0c06ea00u: goto P_0c06ea00;
case 0x0c06ea02u: goto P_0c06ea02;
case 0x0c06ea04u: goto P_0c06ea04;
case 0x0c06ea06u: goto P_0c06ea06;
case 0x0c06ea08u: goto P_0c06ea08;
case 0x0c06ea0au: goto P_0c06ea0a;
case 0x0c06ea0cu: goto P_0c06ea0c;
case 0x0c06ea0eu: goto P_0c06ea0e;
case 0x0c06ea10u: goto P_0c06ea10;
case 0x0c06ea12u: goto P_0c06ea12;
case 0x0c06ea14u: goto P_0c06ea14;
case 0x0c06ea16u: goto P_0c06ea16;
case 0x0c06ea18u: goto P_0c06ea18;
case 0x0c06ea1au: goto P_0c06ea1a;
case 0x0c06ea1cu: goto P_0c06ea1c;
case 0x0c06ea1eu: goto P_0c06ea1e;
case 0x0c06ea20u: goto P_0c06ea20;
case 0x0c06ea22u: goto P_0c06ea22;
case 0x0c06ea24u: goto P_0c06ea24;
case 0x0c06ea26u: goto P_0c06ea26;
case 0x0c06ea28u: goto P_0c06ea28;
case 0x0c06ea2au: goto P_0c06ea2a;
case 0x0c06ea2cu: goto P_0c06ea2c;
case 0x0c06ea2eu: goto P_0c06ea2e;
case 0x0c06ea30u: goto P_0c06ea30;
case 0x0c06ea32u: goto P_0c06ea32;
case 0x0c06ea34u: goto P_0c06ea34;
case 0x0c06ea36u: goto P_0c06ea36;
case 0x0c06ea38u: goto P_0c06ea38;
case 0x0c06ea3au: goto P_0c06ea3a;
case 0x0c06ea3cu: goto P_0c06ea3c;
case 0x0c06ea3eu: goto P_0c06ea3e;
case 0x0c06ea40u: goto P_0c06ea40;
case 0x0c06ea42u: goto P_0c06ea42;
case 0x0c06ea44u: goto P_0c06ea44;
case 0x0c06ea46u: goto P_0c06ea46;
case 0x0c06ea48u: goto P_0c06ea48;
case 0x0c06ea4au: goto P_0c06ea4a;
case 0x0c06ea4cu: goto P_0c06ea4c;
case 0x0c06ea4eu: goto P_0c06ea4e;
case 0x0c06ea50u: goto P_0c06ea50;
case 0x0c06ea52u: goto P_0c06ea52;
case 0x0c06ea54u: goto P_0c06ea54;
case 0x0c06ea56u: goto P_0c06ea56;
case 0x0c06ea58u: goto P_0c06ea58;
case 0x0c06ea5au: goto P_0c06ea5a;
case 0x0c06ea5cu: goto P_0c06ea5c;
case 0x0c06ea5eu: goto P_0c06ea5e;
case 0x0c06ea60u: goto P_0c06ea60;
case 0x0c06ea62u: goto P_0c06ea62;
case 0x0c06ea64u: goto P_0c06ea64;
case 0x0c06ea66u: goto P_0c06ea66;
case 0x0c06ea68u: goto P_0c06ea68;
case 0x0c06ea6au: goto P_0c06ea6a;
case 0x0c06ea6cu: goto P_0c06ea6c;
case 0x0c06ea6eu: goto P_0c06ea6e;
case 0x0c06ea70u: goto P_0c06ea70;
case 0x0c06ea72u: goto P_0c06ea72;
case 0x0c06ea74u: goto P_0c06ea74;
case 0x0c06ea76u: goto P_0c06ea76;
case 0x0c06ea78u: goto P_0c06ea78;
case 0x0c06ea7au: goto P_0c06ea7a;
case 0x0c06ea7cu: goto P_0c06ea7c;
case 0x0c06ea7eu: goto P_0c06ea7e;
case 0x0c06ea80u: goto P_0c06ea80;
case 0x0c06ea82u: goto P_0c06ea82;
case 0x0c06ea84u: goto P_0c06ea84;
case 0x0c06ea86u: goto P_0c06ea86;
case 0x0c06ea88u: goto P_0c06ea88;
case 0x0c06ea8au: goto P_0c06ea8a;
case 0x0c06ea8cu: goto P_0c06ea8c;
case 0x0c06ea8eu: goto P_0c06ea8e;
case 0x0c06ea90u: goto P_0c06ea90;
case 0x0c06ea92u: goto P_0c06ea92;
case 0x0c06ea94u: goto P_0c06ea94;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c636: /* original 2fe6, guest PC 0x0c06c636 */
if(!s->budget--) { s->failed_pc=0x0c06c636u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c638;
P_0c06c638: /* original 4400, guest PC 0x0c06c638 */
if(!s->budget--) { s->failed_pc=0x0c06c638u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c63a;
P_0c06c63a: /* original 4f22, guest PC 0x0c06c63a */
if(!s->budget--) { s->failed_pc=0x0c06c63au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c63c;
P_0c06c63c: /* original e101, guest PC 0x0c06c63c */
if(!s->budget--) { s->failed_pc=0x0c06c63cu; return 0; }
r[1]=0x00000001u;
goto P_0c06c63e;
P_0c06c63e: /* original 6e53, guest PC 0x0c06c63e */
if(!s->budget--) { s->failed_pc=0x0c06c63eu; return 0; }
r[14]=r[5];
goto P_0c06c640;
P_0c06c640: /* original 7ff8, guest PC 0x0c06c640 */
if(!s->budget--) { s->failed_pc=0x0c06c640u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c642;
P_0c06c642: /* original 2f62, guest PC 0x0c06c642 */
if(!s->budget--) { s->failed_pc=0x0c06c642u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c644;
P_0c06c644: /* original 6643, guest PC 0x0c06c644 */
if(!s->budget--) { s->failed_pc=0x0c06c644u; return 0; }
r[6]=r[4];
goto P_0c06c646;
P_0c06c646: /* original d326, guest PC 0x0c06c646 */
if(!s->budget--) { s->failed_pc=0x0c06c646u; return 0; }
r[3]=read(ram,0x0c06c6e0u,4);
goto P_0c06c648;
P_0c06c648: /* original 1f31, guest PC 0x0c06c648 */
if(!s->budget--) { s->failed_pc=0x0c06c648u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06c64a;
P_0c06c64a: /* original e307, guest PC 0x0c06c64a */
if(!s->budget--) { s->failed_pc=0x0c06c64au; return 0; }
r[3]=0x00000007u;
goto P_0c06c64c;
P_0c06c64c: /* original d228, guest PC 0x0c06c64c */
if(!s->budget--) { s->failed_pc=0x0c06c64cu; return 0; }
r[2]=read(ram,0x0c06c6f0u,4);
goto P_0c06c64e;
P_0c06c64e: /* original 4e3d, guest PC 0x0c06c64e */
if(!s->budget--) { s->failed_pc=0x0c06c64eu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?r[14]>>((-r[3])&31u):0):r[14]<<(r[3]&31u);
goto P_0c06c650;
P_0c06c650: /* original 6422, guest PC 0x0c06c650 */
if(!s->budget--) { s->failed_pc=0x0c06c650u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c652;
P_0c06c652: /* original 3416, guest PC 0x0c06c652 */
if(!s->budget--) { s->failed_pc=0x0c06c652u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[1])!=0);
goto P_0c06c654;
P_0c06c654: /* original 8d03, guest PC 0x0c06c654 */
if(!s->budget--) { s->failed_pc=0x0c06c654u; return 0; }
cond=r[17]&1u;
r[6]|=r[14];
if(cond) { goto P_0c06c65e; }
goto P_0c06c658;
P_0c06c656: /* original 26eb, guest PC 0x0c06c656 */
if(!s->budget--) { s->failed_pc=0x0c06c656u; return 0; }
r[6]|=r[14];
goto P_0c06c658;
P_0c06c658: /* original d526, guest PC 0x0c06c658 */
if(!s->budget--) { s->failed_pc=0x0c06c658u; return 0; }
r[5]=read(ram,0x0c06c6f4u,4);
goto P_0c06c65a;
P_0c06c65a: /* original a001, guest PC 0x0c06c65a */
if(!s->budget--) { s->failed_pc=0x0c06c65au; return 0; }
goto P_0c06c660;
P_0c06c65c: /* original 0009, guest PC 0x0c06c65c */
if(!s->budget--) { s->failed_pc=0x0c06c65cu; return 0; }
goto P_0c06c65e;
P_0c06c65e: /* original d526, guest PC 0x0c06c65e */
if(!s->budget--) { s->failed_pc=0x0c06c65eu; return 0; }
r[5]=read(ram,0x0c06c6f8u,4);
goto P_0c06c660;
P_0c06c660: /* original b023, guest PC 0x0c06c660 */
if(!s->budget--) { s->failed_pc=0x0c06c660u; return 0; }
target=code_base|0x0c06c6aau; r[16]=code_base|0x0c06c664u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c664u) { target=s->pc; goto dispatch; }
goto P_0c06c664;
P_0c06c662: /* original 0009, guest PC 0x0c06c662 */
if(!s->budget--) { s->failed_pc=0x0c06c662u; return 0; }
goto P_0c06c664;
P_0c06c664: /* original d225, guest PC 0x0c06c664 */
if(!s->budget--) { s->failed_pc=0x0c06c664u; return 0; }
r[2]=read(ram,0x0c06c6fcu,4);
goto P_0c06c666;
P_0c06c666: /* original d326, guest PC 0x0c06c666 */
if(!s->budget--) { s->failed_pc=0x0c06c666u; return 0; }
r[3]=read(ram,0x0c06c700u,4);
goto P_0c06c668;
P_0c06c668: /* original 6422, guest PC 0x0c06c668 */
if(!s->budget--) { s->failed_pc=0x0c06c668u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c66a;
P_0c06c66a: /* original 2438, guest PC 0x0c06c66a */
if(!s->budget--) { s->failed_pc=0x0c06c66au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06c66c;
P_0c06c66c: /* original 8b0e, guest PC 0x0c06c66c */
if(!s->budget--) { s->failed_pc=0x0c06c66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c68c; }
goto P_0c06c66e;
P_0c06c66e: /* original d125, guest PC 0x0c06c66e */
if(!s->budget--) { s->failed_pc=0x0c06c66eu; return 0; }
r[1]=read(ram,0x0c06c704u,4);
goto P_0c06c670;
P_0c06c670: /* original 6010, guest PC 0x0c06c670 */
if(!s->budget--) { s->failed_pc=0x0c06c670u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c06c672;
P_0c06c672: /* original 600c, guest PC 0x0c06c672 */
if(!s->budget--) { s->failed_pc=0x0c06c672u; return 0; }
r[0]=r[0]&255u;
goto P_0c06c674;
P_0c06c674: /* original 8803, guest PC 0x0c06c674 */
if(!s->budget--) { s->failed_pc=0x0c06c674u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c676;
P_0c06c676: /* original 8b14, guest PC 0x0c06c676 */
if(!s->budget--) { s->failed_pc=0x0c06c676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c6a2; }
goto P_0c06c678;
P_0c06c678: /* original 64f2, guest PC 0x0c06c678 */
if(!s->budget--) { s->failed_pc=0x0c06c678u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c67a;
P_0c06c67a: /* original d523, guest PC 0x0c06c67a */
if(!s->budget--) { s->failed_pc=0x0c06c67au; return 0; }
r[5]=read(ram,0x0c06c708u,4);
goto P_0c06c67c;
P_0c06c67c: /* original 7403, guest PC 0x0c06c67c */
if(!s->budget--) { s->failed_pc=0x0c06c67cu; return 0; }
r[4]+=0x00000003u;
goto P_0c06c67e;
P_0c06c67e: /* original d223, guest PC 0x0c06c67e */
if(!s->budget--) { s->failed_pc=0x0c06c67eu; return 0; }
r[2]=read(ram,0x0c06c70cu,4);
goto P_0c06c680;
P_0c06c680: /* original 4400, guest PC 0x0c06c680 */
if(!s->budget--) { s->failed_pc=0x0c06c680u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c682;
P_0c06c682: /* original 24eb, guest PC 0x0c06c682 */
if(!s->budget--) { s->failed_pc=0x0c06c682u; return 0; }
r[4]|=r[14];
goto P_0c06c684;
P_0c06c684: /* original 420b, guest PC 0x0c06c684 */
if(!s->budget--) { s->failed_pc=0x0c06c684u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c688u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c688u) { target=s->pc; goto dispatch; }
goto P_0c06c688;
P_0c06c686: /* original e601, guest PC 0x0c06c686 */
if(!s->budget--) { s->failed_pc=0x0c06c686u; return 0; }
r[6]=0x00000001u;
goto P_0c06c688;
P_0c06c688: /* original a00b, guest PC 0x0c06c688 */
if(!s->budget--) { s->failed_pc=0x0c06c688u; return 0; }
goto P_0c06c6a2;
P_0c06c68a: /* original 0009, guest PC 0x0c06c68a */
if(!s->budget--) { s->failed_pc=0x0c06c68au; return 0; }
goto P_0c06c68c;
P_0c06c68c: /* original 65f2, guest PC 0x0c06c68c */
if(!s->budget--) { s->failed_pc=0x0c06c68cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06c68e;
P_0c06c68e: /* original e120, guest PC 0x0c06c68e */
if(!s->budget--) { s->failed_pc=0x0c06c68eu; return 0; }
r[1]=0x00000020u;
goto P_0c06c690;
P_0c06c690: /* original e615, guest PC 0x0c06c690 */
if(!s->budget--) { s->failed_pc=0x0c06c690u; return 0; }
r[6]=0x00000015u;
goto P_0c06c692;
P_0c06c692: /* original 2f16, guest PC 0x0c06c692 */
if(!s->budget--) { s->failed_pc=0x0c06c692u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c694;
P_0c06c694: /* original d215, guest PC 0x0c06c694 */
if(!s->budget--) { s->failed_pc=0x0c06c694u; return 0; }
r[2]=read(ram,0x0c06c6ecu,4);
goto P_0c06c696;
P_0c06c696: /* original 4500, guest PC 0x0c06c696 */
if(!s->budget--) { s->failed_pc=0x0c06c696u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c698;
P_0c06c698: /* original e701, guest PC 0x0c06c698 */
if(!s->budget--) { s->failed_pc=0x0c06c698u; return 0; }
r[7]=0x00000001u;
goto P_0c06c69a;
P_0c06c69a: /* original 25eb, guest PC 0x0c06c69a */
if(!s->budget--) { s->failed_pc=0x0c06c69au; return 0; }
r[5]|=r[14];
goto P_0c06c69c;
P_0c06c69c: /* original 420b, guest PC 0x0c06c69c */
if(!s->budget--) { s->failed_pc=0x0c06c69cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6a0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6a0u) { target=s->pc; goto dispatch; }
goto P_0c06c6a0;
P_0c06c69e: /* original 54f2, guest PC 0x0c06c69e */
if(!s->budget--) { s->failed_pc=0x0c06c69eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c6a0;
P_0c06c6a0: /* original 7f04, guest PC 0x0c06c6a0 */
if(!s->budget--) { s->failed_pc=0x0c06c6a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c6a2;
P_0c06c6a2: /* original 7f08, guest PC 0x0c06c6a2 */
if(!s->budget--) { s->failed_pc=0x0c06c6a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c6a4;
P_0c06c6a4: /* original 4f26, guest PC 0x0c06c6a4 */
if(!s->budget--) { s->failed_pc=0x0c06c6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6a6;
P_0c06c6a6: /* original 000b, guest PC 0x0c06c6a6 */
if(!s->budget--) { s->failed_pc=0x0c06c6a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c6a8: /* original 6ef6, guest PC 0x0c06c6a8 */
if(!s->budget--) { s->failed_pc=0x0c06c6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c6aa;
P_0c06c6aa: /* original 4f22, guest PC 0x0c06c6aa */
if(!s->budget--) { s->failed_pc=0x0c06c6aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6ac;
P_0c06c6ac: /* original 7ff4, guest PC 0x0c06c6ac */
if(!s->budget--) { s->failed_pc=0x0c06c6acu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06c6ae;
P_0c06c6ae: /* original 1f41, guest PC 0x0c06c6ae */
if(!s->budget--) { s->failed_pc=0x0c06c6aeu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06c6b0;
P_0c06c6b0: /* original 1f52, guest PC 0x0c06c6b0 */
if(!s->budget--) { s->failed_pc=0x0c06c6b0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06c6b2;
P_0c06c6b2: /* original 2f62, guest PC 0x0c06c6b2 */
if(!s->budget--) { s->failed_pc=0x0c06c6b2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c6b4;
P_0c06c6b4: /* original 53f2, guest PC 0x0c06c6b4 */
if(!s->budget--) { s->failed_pc=0x0c06c6b4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06c6b6;
P_0c06c6b6: /* original 2f36, guest PC 0x0c06c6b6 */
if(!s->budget--) { s->failed_pc=0x0c06c6b6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6b8;
P_0c06c6b8: /* original d215, guest PC 0x0c06c6b8 */
if(!s->budget--) { s->failed_pc=0x0c06c6b8u; return 0; }
r[2]=read(ram,0x0c06c710u,4);
goto P_0c06c6ba;
P_0c06c6ba: /* original 2f26, guest PC 0x0c06c6ba */
if(!s->budget--) { s->failed_pc=0x0c06c6bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6bc;
P_0c06c6bc: /* original 53f3, guest PC 0x0c06c6bc */
if(!s->budget--) { s->failed_pc=0x0c06c6bcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06c6be;
P_0c06c6be: /* original 2f36, guest PC 0x0c06c6be */
if(!s->budget--) { s->failed_pc=0x0c06c6beu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c0;
P_0c06c6c0: /* original d114, guest PC 0x0c06c6c0 */
if(!s->budget--) { s->failed_pc=0x0c06c6c0u; return 0; }
r[1]=read(ram,0x0c06c714u,4);
goto P_0c06c6c2;
P_0c06c6c2: /* original 2f16, guest PC 0x0c06c6c2 */
if(!s->budget--) { s->failed_pc=0x0c06c6c2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c4;
P_0c06c6c4: /* original d314, guest PC 0x0c06c6c4 */
if(!s->budget--) { s->failed_pc=0x0c06c6c4u; return 0; }
r[3]=read(ram,0x0c06c718u,4);
goto P_0c06c6c6;
P_0c06c6c6: /* original 2f36, guest PC 0x0c06c6c6 */
if(!s->budget--) { s->failed_pc=0x0c06c6c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c8;
P_0c06c6c8: /* original d214, guest PC 0x0c06c6c8 */
if(!s->budget--) { s->failed_pc=0x0c06c6c8u; return 0; }
r[2]=read(ram,0x0c06c71cu,4);
goto P_0c06c6ca;
P_0c06c6ca: /* original 420b, guest PC 0x0c06c6ca */
if(!s->budget--) { s->failed_pc=0x0c06c6cau; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6ceu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6ceu) { target=s->pc; goto dispatch; }
goto P_0c06c6ce;
P_0c06c6cc: /* original 54f5, guest PC 0x0c06c6cc */
if(!s->budget--) { s->failed_pc=0x0c06c6ccu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c06c6ce;
P_0c06c6ce: /* original 7f20, guest PC 0x0c06c6ce */
if(!s->budget--) { s->failed_pc=0x0c06c6ceu; return 0; }
r[15]+=0x00000020u;
goto P_0c06c6d0;
P_0c06c6d0: /* original 4f26, guest PC 0x0c06c6d0 */
if(!s->budget--) { s->failed_pc=0x0c06c6d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6d2;
P_0c06c6d2: /* original 000b, guest PC 0x0c06c6d2 */
if(!s->budget--) { s->failed_pc=0x0c06c6d2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c6d4: /* original 0009, guest PC 0x0c06c6d4 */
if(!s->budget--) { s->failed_pc=0x0c06c6d4u; return 0; }
goto P_0c06c6d6;
P_0c06c6d6: /* original 4f22, guest PC 0x0c06c6d6 */
if(!s->budget--) { s->failed_pc=0x0c06c6d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6d8;
P_0c06c6d8: /* original bf76, guest PC 0x0c06c6d8 */
if(!s->budget--) { s->failed_pc=0x0c06c6d8u; return 0; }
target=code_base|0x0c06c5c8u; r[16]=code_base|0x0c06c6dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6dcu) { target=s->pc; goto dispatch; }
goto P_0c06c6dc;
P_0c06c6da: /* original 0009, guest PC 0x0c06c6da */
if(!s->budget--) { s->failed_pc=0x0c06c6dau; return 0; }
goto P_0c06c6dc;
P_0c06c6dc: /* original a020, guest PC 0x0c06c6dc */
if(!s->budget--) { s->failed_pc=0x0c06c6dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c720;
P_0c06c6de: /* original 4f26, guest PC 0x0c06c6de */
if(!s->budget--) { s->failed_pc=0x0c06c6deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c06c6e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c6e0u; return 0; } return 1;
P_0c06c720: /* original 2fe6, guest PC 0x0c06c720 */
if(!s->budget--) { s->failed_pc=0x0c06c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c722;
P_0c06c722: /* original 9053, guest PC 0x0c06c722 */
if(!s->budget--) { s->failed_pc=0x0c06c722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ccu,2);
goto P_0c06c724;
P_0c06c724: /* original 7ffc, guest PC 0x0c06c724 */
if(!s->budget--) { s->failed_pc=0x0c06c724u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c726;
P_0c06c726: /* original de2c, guest PC 0x0c06c726 */
if(!s->budget--) { s->failed_pc=0x0c06c726u; return 0; }
r[14]=read(ram,0x0c06c7d8u,4);
goto P_0c06c728;
P_0c06c728: /* original 00ec, guest PC 0x0c06c728 */
if(!s->budget--) { s->failed_pc=0x0c06c728u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c72a;
P_0c06c72a: /* original 8801, guest PC 0x0c06c72a */
if(!s->budget--) { s->failed_pc=0x0c06c72au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c72c;
P_0c06c72c: /* original 8d12, guest PC 0x0c06c72c */
if(!s->budget--) { s->failed_pc=0x0c06c72cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06c754; }
goto P_0c06c730;
P_0c06c72e: /* original 6403, guest PC 0x0c06c72e */
if(!s->budget--) { s->failed_pc=0x0c06c72eu; return 0; }
r[4]=r[0];
goto P_0c06c730;
P_0c06c730: /* original 904d, guest PC 0x0c06c730 */
if(!s->budget--) { s->failed_pc=0x0c06c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ceu,2);
goto P_0c06c732;
P_0c06c732: /* original 04ec, guest PC 0x0c06c732 */
if(!s->budget--) { s->failed_pc=0x0c06c732u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c734;
P_0c06c734: /* original 70ff, guest PC 0x0c06c734 */
if(!s->budget--) { s->failed_pc=0x0c06c734u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c736;
P_0c06c736: /* original 03ec, guest PC 0x0c06c736 */
if(!s->budget--) { s->failed_pc=0x0c06c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c738;
P_0c06c738: /* original 2338, guest PC 0x0c06c738 */
if(!s->budget--) { s->failed_pc=0x0c06c738u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06c73a;
P_0c06c73a: /* original 8f02, guest PC 0x0c06c73a */
if(!s->budget--) { s->failed_pc=0x0c06c73au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06c742; }
goto P_0c06c73e;
P_0c06c73c: /* original 2f32, guest PC 0x0c06c73c */
if(!s->budget--) { s->failed_pc=0x0c06c73cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c73e;
P_0c06c73e: /* original 2448, guest PC 0x0c06c73e */
if(!s->budget--) { s->failed_pc=0x0c06c73eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06c740;
P_0c06c740: /* original 890c, guest PC 0x0c06c740 */
if(!s->budget--) { s->failed_pc=0x0c06c740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c75c; }
goto P_0c06c742;
P_0c06c742: /* original 9045, guest PC 0x0c06c742 */
if(!s->budget--) { s->failed_pc=0x0c06c742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d0u,2);
goto P_0c06c744;
P_0c06c744: /* original 63f2, guest PC 0x0c06c744 */
if(!s->budget--) { s->failed_pc=0x0c06c744u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06c746;
P_0c06c746: /* original 04ec, guest PC 0x0c06c746 */
if(!s->budget--) { s->failed_pc=0x0c06c746u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c748;
P_0c06c748: /* original 3342, guest PC 0x0c06c748 */
if(!s->budget--) { s->failed_pc=0x0c06c748u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c06c74a;
P_0c06c74a: /* original 8903, guest PC 0x0c06c74a */
if(!s->budget--) { s->failed_pc=0x0c06c74au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c754; }
goto P_0c06c74c;
P_0c06c74c: /* original 9041, guest PC 0x0c06c74c */
if(!s->budget--) { s->failed_pc=0x0c06c74cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c74e;
P_0c06c74e: /* original e102, guest PC 0x0c06c74e */
if(!s->budget--) { s->failed_pc=0x0c06c74eu; return 0; }
r[1]=0x00000002u;
goto P_0c06c750;
P_0c06c750: /* original a007, guest PC 0x0c06c750 */
if(!s->budget--) { s->failed_pc=0x0c06c750u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c752: /* original 0e14, guest PC 0x0c06c752 */
if(!s->budget--) { s->failed_pc=0x0c06c752u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c754;
P_0c06c754: /* original 903d, guest PC 0x0c06c754 */
if(!s->budget--) { s->failed_pc=0x0c06c754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c756;
P_0c06c756: /* original e303, guest PC 0x0c06c756 */
if(!s->budget--) { s->failed_pc=0x0c06c756u; return 0; }
r[3]=0x00000003u;
goto P_0c06c758;
P_0c06c758: /* original a003, guest PC 0x0c06c758 */
if(!s->budget--) { s->failed_pc=0x0c06c758u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c762;
P_0c06c75a: /* original 0e34, guest PC 0x0c06c75a */
if(!s->budget--) { s->failed_pc=0x0c06c75au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c75c;
P_0c06c75c: /* original 9039, guest PC 0x0c06c75c */
if(!s->budget--) { s->failed_pc=0x0c06c75cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c75e;
P_0c06c75e: /* original e101, guest PC 0x0c06c75e */
if(!s->budget--) { s->failed_pc=0x0c06c75eu; return 0; }
r[1]=0x00000001u;
goto P_0c06c760;
P_0c06c760: /* original 0e14, guest PC 0x0c06c760 */
if(!s->budget--) { s->failed_pc=0x0c06c760u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c762: /* original 9036, guest PC 0x0c06c762 */
if(!s->budget--) { s->failed_pc=0x0c06c762u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c764;
P_0c06c764: /* original 00ec, guest PC 0x0c06c764 */
if(!s->budget--) { s->failed_pc=0x0c06c764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c766;
P_0c06c766: /* original 8803, guest PC 0x0c06c766 */
if(!s->budget--) { s->failed_pc=0x0c06c766u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c768;
P_0c06c768: /* original 8f03, guest PC 0x0c06c768 */
if(!s->budget--) { s->failed_pc=0x0c06c768u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06c772; }
goto P_0c06c76c;
P_0c06c76a: /* original 6403, guest PC 0x0c06c76a */
if(!s->budget--) { s->failed_pc=0x0c06c76au; return 0; }
r[4]=r[0];
goto P_0c06c76c;
P_0c06c76c: /* original 7f04, guest PC 0x0c06c76c */
if(!s->budget--) { s->failed_pc=0x0c06c76cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c76e;
P_0c06c76e: /* original a018, guest PC 0x0c06c76e */
if(!s->budget--) { s->failed_pc=0x0c06c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c770: /* original 6ef6, guest PC 0x0c06c770 */
if(!s->budget--) { s->failed_pc=0x0c06c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c772;
P_0c06c772: /* original d31a, guest PC 0x0c06c772 */
if(!s->budget--) { s->failed_pc=0x0c06c772u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c774;
P_0c06c774: /* original e23f, guest PC 0x0c06c774 */
if(!s->budget--) { s->failed_pc=0x0c06c774u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c776;
P_0c06c776: /* original 902d, guest PC 0x0c06c776 */
if(!s->budget--) { s->failed_pc=0x0c06c776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c778;
P_0c06c778: /* original 6532, guest PC 0x0c06c778 */
if(!s->budget--) { s->failed_pc=0x0c06c778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c77a;
P_0c06c77a: /* original e303, guest PC 0x0c06c77a */
if(!s->budget--) { s->failed_pc=0x0c06c77au; return 0; }
r[3]=0x00000003u;
goto P_0c06c77c;
P_0c06c77c: /* original 04ec, guest PC 0x0c06c77c */
if(!s->budget--) { s->failed_pc=0x0c06c77cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c77e;
P_0c06c77e: /* original 2529, guest PC 0x0c06c77e */
if(!s->budget--) { s->failed_pc=0x0c06c77eu; return 0; }
r[5]&=r[2];
goto P_0c06c780;
P_0c06c780: /* original 2558, guest PC 0x0c06c780 */
if(!s->budget--) { s->failed_pc=0x0c06c780u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c782;
P_0c06c782: /* original 8f01, guest PC 0x0c06c782 */
if(!s->budget--) { s->failed_pc=0x0c06c782u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c06c788; }
goto P_0c06c786;
P_0c06c784: /* original 2439, guest PC 0x0c06c784 */
if(!s->budget--) { s->failed_pc=0x0c06c784u; return 0; }
r[4]&=r[3];
goto P_0c06c786;
P_0c06c786: /* original 7401, guest PC 0x0c06c786 */
if(!s->budget--) { s->failed_pc=0x0c06c786u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c788;
P_0c06c788: /* original e302, guest PC 0x0c06c788 */
if(!s->budget--) { s->failed_pc=0x0c06c788u; return 0; }
r[3]=0x00000002u;
goto P_0c06c78a;
P_0c06c78a: /* original 3436, guest PC 0x0c06c78a */
if(!s->budget--) { s->failed_pc=0x0c06c78au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c06c78c;
P_0c06c78c: /* original 8b00, guest PC 0x0c06c78c */
if(!s->budget--) { s->failed_pc=0x0c06c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c790; }
goto P_0c06c78e;
P_0c06c78e: /* original e400, guest PC 0x0c06c78e */
if(!s->budget--) { s->failed_pc=0x0c06c78eu; return 0; }
r[4]=0x00000000u;
goto P_0c06c790;
P_0c06c790: /* original 0e44, guest PC 0x0c06c790 */
if(!s->budget--) { s->failed_pc=0x0c06c790u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06c792;
P_0c06c792: /* original 4408, guest PC 0x0c06c792 */
if(!s->budget--) { s->failed_pc=0x0c06c792u; return 0; }
r[4]<<=2;
goto P_0c06c794;
P_0c06c794: /* original d012, guest PC 0x0c06c794 */
if(!s->budget--) { s->failed_pc=0x0c06c794u; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c796;
P_0c06c796: /* original 034e, guest PC 0x0c06c796 */
if(!s->budget--) { s->failed_pc=0x0c06c796u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c798;
P_0c06c798: /* original 2f32, guest PC 0x0c06c798 */
if(!s->budget--) { s->failed_pc=0x0c06c798u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c79a;
P_0c06c79a: /* original 7f04, guest PC 0x0c06c79a */
if(!s->budget--) { s->failed_pc=0x0c06c79au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c79c;
P_0c06c79c: /* original 6233, guest PC 0x0c06c79c */
if(!s->budget--) { s->failed_pc=0x0c06c79cu; return 0; }
r[2]=r[3];
goto P_0c06c79e;
P_0c06c79e: /* original 422b, guest PC 0x0c06c79e */
if(!s->budget--) { s->failed_pc=0x0c06c79eu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06c7a0: /* original 6ef6, guest PC 0x0c06c7a0 */
if(!s->budget--) { s->failed_pc=0x0c06c7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c7a2: /* original d30e, guest PC 0x0c06c7a2 */
if(!s->budget--) { s->failed_pc=0x0c06c7a2u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c7a4;
P_0c06c7a4: /* original e23f, guest PC 0x0c06c7a4 */
if(!s->budget--) { s->failed_pc=0x0c06c7a4u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c7a6;
P_0c06c7a6: /* original 9015, guest PC 0x0c06c7a6 */
if(!s->budget--) { s->failed_pc=0x0c06c7a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c7a8;
P_0c06c7a8: /* original e601, guest PC 0x0c06c7a8 */
if(!s->budget--) { s->failed_pc=0x0c06c7a8u; return 0; }
r[6]=0x00000001u;
goto P_0c06c7aa;
P_0c06c7aa: /* original d70b, guest PC 0x0c06c7aa */
if(!s->budget--) { s->failed_pc=0x0c06c7aau; return 0; }
r[7]=read(ram,0x0c06c7d8u,4);
goto P_0c06c7ac;
P_0c06c7ac: /* original 7ffc, guest PC 0x0c06c7ac */
if(!s->budget--) { s->failed_pc=0x0c06c7acu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c7ae;
P_0c06c7ae: /* original 6532, guest PC 0x0c06c7ae */
if(!s->budget--) { s->failed_pc=0x0c06c7aeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c7b0;
P_0c06c7b0: /* original 047c, guest PC 0x0c06c7b0 */
if(!s->budget--) { s->failed_pc=0x0c06c7b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c7b2;
P_0c06c7b2: /* original 2529, guest PC 0x0c06c7b2 */
if(!s->budget--) { s->failed_pc=0x0c06c7b2u; return 0; }
r[5]&=r[2];
goto P_0c06c7b4;
P_0c06c7b4: /* original 2558, guest PC 0x0c06c7b4 */
if(!s->budget--) { s->failed_pc=0x0c06c7b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c7b6;
P_0c06c7b6: /* original 8f02, guest PC 0x0c06c7b6 */
if(!s->budget--) { s->failed_pc=0x0c06c7b6u; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c06c7be; }
goto P_0c06c7ba;
P_0c06c7b8: /* original 2469, guest PC 0x0c06c7b8 */
if(!s->budget--) { s->failed_pc=0x0c06c7b8u; return 0; }
r[4]&=r[6];
goto P_0c06c7ba;
P_0c06c7ba: /* original 246a, guest PC 0x0c06c7ba */
if(!s->budget--) { s->failed_pc=0x0c06c7bau; return 0; }
r[4]^=r[6];
goto P_0c06c7bc;
P_0c06c7bc: /* original 0744, guest PC 0x0c06c7bc */
if(!s->budget--) { s->failed_pc=0x0c06c7bcu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c06c7be;
P_0c06c7be: /* original d008, guest PC 0x0c06c7be */
if(!s->budget--) { s->failed_pc=0x0c06c7beu; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c7c0;
P_0c06c7c0: /* original 4408, guest PC 0x0c06c7c0 */
if(!s->budget--) { s->failed_pc=0x0c06c7c0u; return 0; }
r[4]<<=2;
goto P_0c06c7c2;
P_0c06c7c2: /* original 034e, guest PC 0x0c06c7c2 */
if(!s->budget--) { s->failed_pc=0x0c06c7c2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c7c4;
P_0c06c7c4: /* original 6233, guest PC 0x0c06c7c4 */
if(!s->budget--) { s->failed_pc=0x0c06c7c4u; return 0; }
r[2]=r[3];
goto P_0c06c7c6;
P_0c06c7c6: /* original 2f32, guest PC 0x0c06c7c6 */
if(!s->budget--) { s->failed_pc=0x0c06c7c6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c7c8;
P_0c06c7c8: /* original 422b, guest PC 0x0c06c7c8 */
if(!s->budget--) { s->failed_pc=0x0c06c7c8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06c7ca: /* original 7f04, guest PC 0x0c06c7ca */
if(!s->budget--) { s->failed_pc=0x0c06c7cau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c06c7ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c7ccu; return 0; } return 1;
P_0c06e8a2: /* original 7ff0, guest PC 0x0c06e8a2 */
if(!s->budget--) { s->failed_pc=0x0c06e8a2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c06e8a4;
P_0c06e8a4: /* original 2f42, guest PC 0x0c06e8a4 */
if(!s->budget--) { s->failed_pc=0x0c06e8a4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06e8a6;
P_0c06e8a6: /* original 1f52, guest PC 0x0c06e8a6 */
if(!s->budget--) { s->failed_pc=0x0c06e8a6u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06e8a8;
P_0c06e8a8: /* original 1f63, guest PC 0x0c06e8a8 */
if(!s->budget--) { s->failed_pc=0x0c06e8a8u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c06e8aa;
P_0c06e8aa: /* original 1f71, guest PC 0x0c06e8aa */
if(!s->budget--) { s->failed_pc=0x0c06e8aau; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c06e8ac;
P_0c06e8ac: /* original 904c, guest PC 0x0c06e8ac */
if(!s->budget--) { s->failed_pc=0x0c06e8acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e948u,2);
goto P_0c06e8ae;
P_0c06e8ae: /* original 63f2, guest PC 0x0c06e8ae */
if(!s->budget--) { s->failed_pc=0x0c06e8aeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06e8b0;
P_0c06e8b0: /* original 57f4, guest PC 0x0c06e8b0 */
if(!s->budget--) { s->failed_pc=0x0c06e8b0u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c06e8b2;
P_0c06e8b2: /* original f536, guest PC 0x0c06e8b2 */
if(!s->budget--) { s->failed_pc=0x0c06e8b2u; return 0; }
vf3_matrix_load(s,ram,5,r[3]+r[0]);
goto P_0c06e8b4;
P_0c06e8b4: /* original 70f8, guest PC 0x0c06e8b4 */
if(!s->budget--) { s->failed_pc=0x0c06e8b4u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c06e8b6;
P_0c06e8b6: /* original f436, guest PC 0x0c06e8b6 */
if(!s->budget--) { s->failed_pc=0x0c06e8b6u; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c06e8b8;
P_0c06e8b8: /* original 56f1, guest PC 0x0c06e8b8 */
if(!s->budget--) { s->failed_pc=0x0c06e8b8u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c06e8ba;
P_0c06e8ba: /* original 54f2, guest PC 0x0c06e8ba */
if(!s->budget--) { s->failed_pc=0x0c06e8bau; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06e8bc;
P_0c06e8bc: /* original 55f3, guest PC 0x0c06e8bc */
if(!s->budget--) { s->failed_pc=0x0c06e8bcu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c06e8be;
P_0c06e8be: /* original f54d, guest PC 0x0c06e8be */
if(!s->budget--) { s->failed_pc=0x0c06e8beu; return 0; }
fr[5]^=0x80000000u;
goto P_0c06e8c0;
P_0c06e8c0: /* original a000, guest PC 0x0c06e8c0 */
if(!s->budget--) { s->failed_pc=0x0c06e8c0u; return 0; }
r[15]+=0x00000010u;
goto P_0c06e8c4;
P_0c06e8c2: /* original 7f10, guest PC 0x0c06e8c2 */
if(!s->budget--) { s->failed_pc=0x0c06e8c2u; return 0; }
r[15]+=0x00000010u;
goto P_0c06e8c4;
P_0c06e8c4: /* original fffb, guest PC 0x0c06e8c4 */
if(!s->budget--) { s->failed_pc=0x0c06e8c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e8c6;
P_0c06e8c6: /* original ffeb, guest PC 0x0c06e8c6 */
if(!s->budget--) { s->failed_pc=0x0c06e8c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e8c8;
P_0c06e8c8: /* original ffdb, guest PC 0x0c06e8c8 */
if(!s->budget--) { s->failed_pc=0x0c06e8c8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e8ca;
P_0c06e8ca: /* original ffcb, guest PC 0x0c06e8ca */
if(!s->budget--) { s->failed_pc=0x0c06e8cau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06e8cc;
P_0c06e8cc: /* original 4f22, guest PC 0x0c06e8cc */
if(!s->budget--) { s->failed_pc=0x0c06e8ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e8ce;
P_0c06e8ce: /* original fe5c, guest PC 0x0c06e8ce */
if(!s->budget--) { s->failed_pc=0x0c06e8ceu; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c06e8d0;
P_0c06e8d0: /* original ff4c, guest PC 0x0c06e8d0 */
if(!s->budget--) { s->failed_pc=0x0c06e8d0u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c06e8d2;
P_0c06e8d2: /* original 7fd0, guest PC 0x0c06e8d2 */
if(!s->budget--) { s->failed_pc=0x0c06e8d2u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c06e8d4;
P_0c06e8d4: /* original 1f44, guest PC 0x0c06e8d4 */
if(!s->budget--) { s->failed_pc=0x0c06e8d4u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c06e8d6;
P_0c06e8d6: /* original e40f, guest PC 0x0c06e8d6 */
if(!s->budget--) { s->failed_pc=0x0c06e8d6u; return 0; }
r[4]=0x0000000fu;
goto P_0c06e8d8;
P_0c06e8d8: /* original 1f57, guest PC 0x0c06e8d8 */
if(!s->budget--) { s->failed_pc=0x0c06e8d8u; return 0; }
write(ram,r[15]+28,r[5],4);
goto P_0c06e8da;
P_0c06e8da: /* original 1f65, guest PC 0x0c06e8da */
if(!s->budget--) { s->failed_pc=0x0c06e8dau; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c06e8dc;
P_0c06e8dc: /* original 1f76, guest PC 0x0c06e8dc */
if(!s->budget--) { s->failed_pc=0x0c06e8dcu; return 0; }
write(ram,r[15]+24,r[7],4);
goto P_0c06e8de;
P_0c06e8de: /* original d21d, guest PC 0x0c06e8de */
if(!s->budget--) { s->failed_pc=0x0c06e8deu; return 0; }
r[2]=read(ram,0x0c06e954u,4);
goto P_0c06e8e0;
P_0c06e8e0: /* original d31b, guest PC 0x0c06e8e0 */
if(!s->budget--) { s->failed_pc=0x0c06e8e0u; return 0; }
r[3]=read(ram,0x0c06e950u,4);
goto P_0c06e8e2;
P_0c06e8e2: /* original 6020, guest PC 0x0c06e8e2 */
if(!s->budget--) { s->failed_pc=0x0c06e8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c06e8e4;
P_0c06e8e4: /* original 600c, guest PC 0x0c06e8e4 */
if(!s->budget--) { s->failed_pc=0x0c06e8e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c06e8e6;
P_0c06e8e6: /* original 2409, guest PC 0x0c06e8e6 */
if(!s->budget--) { s->failed_pc=0x0c06e8e6u; return 0; }
r[4]&=r[0];
goto P_0c06e8e8;
P_0c06e8e8: /* original 6043, guest PC 0x0c06e8e8 */
if(!s->budget--) { s->failed_pc=0x0c06e8e8u; return 0; }
r[0]=r[4];
goto P_0c06e8ea;
P_0c06e8ea: /* original 880f, guest PC 0x0c06e8ea */
if(!s->budget--) { s->failed_pc=0x0c06e8eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c06e8ec;
P_0c06e8ec: /* original 8f15, guest PC 0x0c06e8ec */
if(!s->budget--) { s->failed_pc=0x0c06e8ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!cond) { goto P_0c06e91a; }
goto P_0c06e8f0;
P_0c06e8ee: /* original 6532, guest PC 0x0c06e8ee */
if(!s->budget--) { s->failed_pc=0x0c06e8eeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06e8f0;
P_0c06e8f0: /* original f3fc, guest PC 0x0c06e8f0 */
if(!s->budget--) { s->failed_pc=0x0c06e8f0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06e8f2;
P_0c06e8f2: /* original f3f2, guest PC 0x0c06e8f2 */
if(!s->budget--) { s->failed_pc=0x0c06e8f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06e8f4;
P_0c06e8f4: /* original f0ec, guest PC 0x0c06e8f4 */
if(!s->budget--) { s->failed_pc=0x0c06e8f4u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e8f6;
P_0c06e8f6: /* original c718, guest PC 0x0c06e8f6 */
if(!s->budget--) { s->failed_pc=0x0c06e8f6u; return 0; }
r[0]=code_base|0x0006e958u;
goto P_0c06e8f8;
P_0c06e8f8: /* original f508, guest PC 0x0c06e8f8 */
if(!s->budget--) { s->failed_pc=0x0c06e8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06e8fa;
P_0c06e8fa: /* original c718, guest PC 0x0c06e8fa */
if(!s->budget--) { s->failed_pc=0x0c06e8fau; return 0; }
r[0]=code_base|0x0006e95cu;
goto P_0c06e8fc;
P_0c06e8fc: /* original f208, guest PC 0x0c06e8fc */
if(!s->budget--) { s->failed_pc=0x0c06e8fcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c06e8fe;
P_0c06e8fe: /* original f3ee, guest PC 0x0c06e8fe */
if(!s->budget--) { s->failed_pc=0x0c06e8feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c06e900;
P_0c06e900: /* original f43c, guest PC 0x0c06e900 */
if(!s->budget--) { s->failed_pc=0x0c06e900u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e902;
P_0c06e902: /* original f245, guest PC 0x0c06e902 */
if(!s->budget--) { s->failed_pc=0x0c06e902u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e904;
P_0c06e904: /* original 8f02, guest PC 0x0c06e904 */
if(!s->budget--) { s->failed_pc=0x0c06e904u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c06e90c; }
goto P_0c06e908;
P_0c06e906: /* original fdfc, guest PC 0x0c06e906 */
if(!s->budget--) { s->failed_pc=0x0c06e906u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e908;
P_0c06e908: /* original a001, guest PC 0x0c06e908 */
if(!s->budget--) { s->failed_pc=0x0c06e908u; return 0; }
fr[4]=0;
goto P_0c06e90e;
P_0c06e90a: /* original f48d, guest PC 0x0c06e90a */
if(!s->budget--) { s->failed_pc=0x0c06e90au; return 0; }
fr[4]=0;
goto P_0c06e90c;
P_0c06e90c: /* original f47d, guest PC 0x0c06e90c */
if(!s->budget--) { s->failed_pc=0x0c06e90cu; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06e90e;
P_0c06e90e: /* original fd42, guest PC 0x0c06e90e */
if(!s->budget--) { s->failed_pc=0x0c06e90eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c06e910;
P_0c06e910: /* original fcec, guest PC 0x0c06e910 */
if(!s->budget--) { s->failed_pc=0x0c06e910u; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c06e912;
P_0c06e912: /* original fc42, guest PC 0x0c06e912 */
if(!s->budget--) { s->failed_pc=0x0c06e912u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c06e914;
P_0c06e914: /* original fd52, guest PC 0x0c06e914 */
if(!s->budget--) { s->failed_pc=0x0c06e914u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'*');
goto P_0c06e916;
P_0c06e916: /* original a083, guest PC 0x0c06e916 */
if(!s->budget--) { s->failed_pc=0x0c06e916u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06ea20;
P_0c06e918: /* original fc52, guest PC 0x0c06e918 */
if(!s->budget--) { s->failed_pc=0x0c06e918u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06e91a;
P_0c06e91a: /* original 9016, guest PC 0x0c06e91a */
if(!s->budget--) { s->failed_pc=0x0c06e91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e94au,2);
goto P_0c06e91c;
P_0c06e91c: /* original f39d, guest PC 0x0c06e91c */
if(!s->budget--) { s->failed_pc=0x0c06e91cu; return 0; }
fr[3]=0x3f800000u;
goto P_0c06e91e;
P_0c06e91e: /* original 045e, guest PC 0x0c06e91e */
if(!s->budget--) { s->failed_pc=0x0c06e91eu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c06e920;
P_0c06e920: /* original c70f, guest PC 0x0c06e920 */
if(!s->budget--) { s->failed_pc=0x0c06e920u; return 0; }
r[0]=code_base|0x0006e960u;
goto P_0c06e922;
P_0c06e922: /* original f908, guest PC 0x0c06e922 */
if(!s->budget--) { s->failed_pc=0x0c06e922u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c06e924;
P_0c06e924: /* original e020, guest PC 0x0c06e924 */
if(!s->budget--) { s->failed_pc=0x0c06e924u; return 0; }
r[0]=0x00000020u;
goto P_0c06e926;
P_0c06e926: /* original f48d, guest PC 0x0c06e926 */
if(!s->budget--) { s->failed_pc=0x0c06e926u; return 0; }
fr[4]=0;
goto P_0c06e928;
P_0c06e928: /* original fc4c, guest PC 0x0c06e928 */
if(!s->budget--) { s->failed_pc=0x0c06e928u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c06e92a;
P_0c06e92a: /* original fd4c, guest PC 0x0c06e92a */
if(!s->budget--) { s->failed_pc=0x0c06e92au; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e92c;
P_0c06e92c: /* original ff37, guest PC 0x0c06e92c */
if(!s->budget--) { s->failed_pc=0x0c06e92cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e92e;
P_0c06e92e: /* original e02c, guest PC 0x0c06e92e */
if(!s->budget--) { s->failed_pc=0x0c06e92eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06e930;
P_0c06e930: /* original 6546, guest PC 0x0c06e930 */
if(!s->budget--) { s->failed_pc=0x0c06e930u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c06e932;
P_0c06e932: /* original f649, guest PC 0x0c06e932 */
if(!s->budget--) { s->failed_pc=0x0c06e932u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e934;
P_0c06e934: /* original f549, guest PC 0x0c06e934 */
if(!s->budget--) { s->failed_pc=0x0c06e934u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e936;
P_0c06e936: /* original f349, guest PC 0x0c06e936 */
if(!s->budget--) { s->failed_pc=0x0c06e936u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e938;
P_0c06e938: /* original ff37, guest PC 0x0c06e938 */
if(!s->budget--) { s->failed_pc=0x0c06e938u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e93a;
P_0c06e93a: /* original e028, guest PC 0x0c06e93a */
if(!s->budget--) { s->failed_pc=0x0c06e93au; return 0; }
r[0]=0x00000028u;
goto P_0c06e93c;
P_0c06e93c: /* original f349, guest PC 0x0c06e93c */
if(!s->budget--) { s->failed_pc=0x0c06e93cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e93e;
P_0c06e93e: /* original a06d, guest PC 0x0c06e93e */
if(!s->budget--) { s->failed_pc=0x0c06e93eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea1c;
P_0c06e940: /* original ff37, guest PC 0x0c06e940 */
if(!s->budget--) { s->failed_pc=0x0c06e940u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c06e942u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e942u; return 0; } return 1;
P_0c06e964: /* original e02c, guest PC 0x0c06e964 */
if(!s->budget--) { s->failed_pc=0x0c06e964u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e966;
P_0c06e966: /* original fb6c, guest PC 0x0c06e966 */
if(!s->budget--) { s->failed_pc=0x0c06e966u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c06e968;
P_0c06e968: /* original f6f6, guest PC 0x0c06e968 */
if(!s->budget--) { s->failed_pc=0x0c06e968u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c06e96a;
P_0c06e96a: /* original e028, guest PC 0x0c06e96a */
if(!s->budget--) { s->failed_pc=0x0c06e96au; return 0; }
r[0]=0x00000028u;
goto P_0c06e96c;
P_0c06e96c: /* original f4fc, guest PC 0x0c06e96c */
if(!s->budget--) { s->failed_pc=0x0c06e96cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e96e;
P_0c06e96e: /* original f4b1, guest PC 0x0c06e96e */
if(!s->budget--) { s->failed_pc=0x0c06e96eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'-');
goto P_0c06e970;
P_0c06e970: /* original f86c, guest PC 0x0c06e970 */
if(!s->budget--) { s->failed_pc=0x0c06e970u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06e972;
P_0c06e972: /* original f8b1, guest PC 0x0c06e972 */
if(!s->budget--) { s->failed_pc=0x0c06e972u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'-');
goto P_0c06e974;
P_0c06e974: /* original fa5c, guest PC 0x0c06e974 */
if(!s->budget--) { s->failed_pc=0x0c06e974u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e976;
P_0c06e976: /* original f5f6, guest PC 0x0c06e976 */
if(!s->budget--) { s->failed_pc=0x0c06e976u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06e978;
P_0c06e978: /* original e024, guest PC 0x0c06e978 */
if(!s->budget--) { s->failed_pc=0x0c06e978u; return 0; }
r[0]=0x00000024u;
goto P_0c06e97a;
P_0c06e97a: /* original f3ec, guest PC 0x0c06e97a */
if(!s->budget--) { s->failed_pc=0x0c06e97au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06e97c;
P_0c06e97c: /* original f3a1, guest PC 0x0c06e97c */
if(!s->budget--) { s->failed_pc=0x0c06e97cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c06e97e;
P_0c06e97e: /* original f75c, guest PC 0x0c06e97e */
if(!s->budget--) { s->failed_pc=0x0c06e97eu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c06e980;
P_0c06e980: /* original f7a1, guest PC 0x0c06e980 */
if(!s->budget--) { s->failed_pc=0x0c06e980u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c06e982;
P_0c06e982: /* original ff37, guest PC 0x0c06e982 */
if(!s->budget--) { s->failed_pc=0x0c06e982u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e984;
P_0c06e984: /* original e00c, guest PC 0x0c06e984 */
if(!s->budget--) { s->failed_pc=0x0c06e984u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e986;
P_0c06e986: /* original f24c, guest PC 0x0c06e986 */
if(!s->budget--) { s->failed_pc=0x0c06e986u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06e988;
P_0c06e988: /* original f48c, guest PC 0x0c06e988 */
if(!s->budget--) { s->failed_pc=0x0c06e988u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c06e98a;
P_0c06e98a: /* original f422, guest PC 0x0c06e98a */
if(!s->budget--) { s->failed_pc=0x0c06e98au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c06e98c;
P_0c06e98c: /* original f07c, guest PC 0x0c06e98c */
if(!s->budget--) { s->failed_pc=0x0c06e98cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e98e;
P_0c06e98e: /* original f14c, guest PC 0x0c06e98e */
if(!s->budget--) { s->failed_pc=0x0c06e98eu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c06e990;
P_0c06e990: /* original f13e, guest PC 0x0c06e990 */
if(!s->budget--) { s->failed_pc=0x0c06e990u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c06e992;
P_0c06e992: /* original f38c, guest PC 0x0c06e992 */
if(!s->budget--) { s->failed_pc=0x0c06e992u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c06e994;
P_0c06e994: /* original f382, guest PC 0x0c06e994 */
if(!s->budget--) { s->failed_pc=0x0c06e994u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c06e996;
P_0c06e996: /* original f41c, guest PC 0x0c06e996 */
if(!s->budget--) { s->failed_pc=0x0c06e996u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c06e998;
P_0c06e998: /* original f37e, guest PC 0x0c06e998 */
if(!s->budget--) { s->failed_pc=0x0c06e998u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06e99a;
P_0c06e99a: /* original f433, guest PC 0x0c06e99a */
if(!s->budget--) { s->failed_pc=0x0c06e99au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c06e99c;
P_0c06e99c: /* original ff37, guest PC 0x0c06e99c */
if(!s->budget--) { s->failed_pc=0x0c06e99cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e99e;
P_0c06e99e: /* original f249, guest PC 0x0c06e99e */
if(!s->budget--) { s->failed_pc=0x0c06e99eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a0;
P_0c06e9a0: /* original e02c, guest PC 0x0c06e9a0 */
if(!s->budget--) { s->failed_pc=0x0c06e9a0u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e9a2;
P_0c06e9a2: /* original ff27, guest PC 0x0c06e9a2 */
if(!s->budget--) { s->failed_pc=0x0c06e9a2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9a4;
P_0c06e9a4: /* original f249, guest PC 0x0c06e9a4 */
if(!s->budget--) { s->failed_pc=0x0c06e9a4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a6;
P_0c06e9a6: /* original e028, guest PC 0x0c06e9a6 */
if(!s->budget--) { s->failed_pc=0x0c06e9a6u; return 0; }
r[0]=0x00000028u;
goto P_0c06e9a8;
P_0c06e9a8: /* original ff27, guest PC 0x0c06e9a8 */
if(!s->budget--) { s->failed_pc=0x0c06e9a8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9aa;
P_0c06e9aa: /* original f28d, guest PC 0x0c06e9aa */
if(!s->budget--) { s->failed_pc=0x0c06e9aau; return 0; }
fr[2]=0;
goto P_0c06e9ac;
P_0c06e9ac: /* original f245, guest PC 0x0c06e9ac */
if(!s->budget--) { s->failed_pc=0x0c06e9acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e9ae;
P_0c06e9ae: /* original 891f, guest PC 0x0c06e9ae */
if(!s->budget--) { s->failed_pc=0x0c06e9aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b0;
P_0c06e9b0: /* original e020, guest PC 0x0c06e9b0 */
if(!s->budget--) { s->failed_pc=0x0c06e9b0u; return 0; }
r[0]=0x00000020u;
goto P_0c06e9b2;
P_0c06e9b2: /* original f2f6, guest PC 0x0c06e9b2 */
if(!s->budget--) { s->failed_pc=0x0c06e9b2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e9b4;
P_0c06e9b4: /* original f425, guest PC 0x0c06e9b4 */
if(!s->budget--) { s->failed_pc=0x0c06e9b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c06e9b6;
P_0c06e9b6: /* original 891b, guest PC 0x0c06e9b6 */
if(!s->budget--) { s->failed_pc=0x0c06e9b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b8;
P_0c06e9b8: /* original f742, guest PC 0x0c06e9b8 */
if(!s->budget--) { s->failed_pc=0x0c06e9b8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06e9ba;
P_0c06e9ba: /* original c737, guest PC 0x0c06e9ba */
if(!s->budget--) { s->failed_pc=0x0c06e9bau; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06e9bc;
P_0c06e9bc: /* original f842, guest PC 0x0c06e9bc */
if(!s->budget--) { s->failed_pc=0x0c06e9bcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c06e9be;
P_0c06e9be: /* original f37c, guest PC 0x0c06e9be */
if(!s->budget--) { s->failed_pc=0x0c06e9beu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e9c0;
P_0c06e9c0: /* original f3a0, guest PC 0x0c06e9c0 */
if(!s->budget--) { s->failed_pc=0x0c06e9c0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'+');
goto P_0c06e9c2;
P_0c06e9c2: /* original f8b0, guest PC 0x0c06e9c2 */
if(!s->budget--) { s->failed_pc=0x0c06e9c2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'+');
goto P_0c06e9c4;
P_0c06e9c4: /* original ff3a, guest PC 0x0c06e9c4 */
if(!s->budget--) { s->failed_pc=0x0c06e9c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e9c6;
P_0c06e9c6: /* original f7fc, guest PC 0x0c06e9c6 */
if(!s->budget--) { s->failed_pc=0x0c06e9c6u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9c8;
P_0c06e9c8: /* original f781, guest PC 0x0c06e9c8 */
if(!s->budget--) { s->failed_pc=0x0c06e9c8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c06e9ca;
P_0c06e9ca: /* original f4ec, guest PC 0x0c06e9ca */
if(!s->budget--) { s->failed_pc=0x0c06e9cau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9cc;
P_0c06e9cc: /* original f431, guest PC 0x0c06e9cc */
if(!s->budget--) { s->failed_pc=0x0c06e9ccu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e9ce;
P_0c06e9ce: /* original f308, guest PC 0x0c06e9ce */
if(!s->budget--) { s->failed_pc=0x0c06e9ceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9d0;
P_0c06e9d0: /* original f772, guest PC 0x0c06e9d0 */
if(!s->budget--) { s->failed_pc=0x0c06e9d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06e9d2;
P_0c06e9d2: /* original f442, guest PC 0x0c06e9d2 */
if(!s->budget--) { s->failed_pc=0x0c06e9d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9d4;
P_0c06e9d4: /* original f470, guest PC 0x0c06e9d4 */
if(!s->budget--) { s->failed_pc=0x0c06e9d4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06e9d6;
P_0c06e9d6: /* original f345, guest PC 0x0c06e9d6 */
if(!s->budget--) { s->failed_pc=0x0c06e9d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06e9d8;
P_0c06e9d8: /* original 8b01, guest PC 0x0c06e9d8 */
if(!s->budget--) { s->failed_pc=0x0c06e9d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e9de; }
goto P_0c06e9da;
P_0c06e9da: /* original a002, guest PC 0x0c06e9da */
if(!s->budget--) { s->failed_pc=0x0c06e9dau; return 0; }
fr[7]=0;
goto P_0c06e9e2;
P_0c06e9dc: /* original f78d, guest PC 0x0c06e9dc */
if(!s->budget--) { s->failed_pc=0x0c06e9dcu; return 0; }
fr[7]=0;
goto P_0c06e9de;
P_0c06e9de: /* original f74c, guest PC 0x0c06e9de */
if(!s->budget--) { s->failed_pc=0x0c06e9deu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06e9e0;
P_0c06e9e0: /* original f77d, guest PC 0x0c06e9e0 */
if(!s->budget--) { s->failed_pc=0x0c06e9e0u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06e9e2;
P_0c06e9e2: /* original f472, guest PC 0x0c06e9e2 */
if(!s->budget--) { s->failed_pc=0x0c06e9e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06e9e4;
P_0c06e9e4: /* original f945, guest PC 0x0c06e9e4 */
if(!s->budget--) { s->failed_pc=0x0c06e9e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06e9e6;
P_0c06e9e6: /* original 8b18, guest PC 0x0c06e9e6 */
if(!s->budget--) { s->failed_pc=0x0c06e9e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06e9e8;
P_0c06e9e8: /* original fd8c, guest PC 0x0c06e9e8 */
if(!s->budget--) { s->failed_pc=0x0c06e9e8u; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c06e9ea;
P_0c06e9ea: /* original f94c, guest PC 0x0c06e9ea */
if(!s->budget--) { s->failed_pc=0x0c06e9eau; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06e9ec;
P_0c06e9ec: /* original a015, guest PC 0x0c06e9ec */
if(!s->budget--) { s->failed_pc=0x0c06e9ecu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06ea1a;
P_0c06e9ee: /* original fcf8, guest PC 0x0c06e9ee */
if(!s->budget--) { s->failed_pc=0x0c06e9eeu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06e9f0;
P_0c06e9f0: /* original f4ec, guest PC 0x0c06e9f0 */
if(!s->budget--) { s->failed_pc=0x0c06e9f0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9f2;
P_0c06e9f2: /* original f451, guest PC 0x0c06e9f2 */
if(!s->budget--) { s->failed_pc=0x0c06e9f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06e9f4;
P_0c06e9f4: /* original f7fc, guest PC 0x0c06e9f4 */
if(!s->budget--) { s->failed_pc=0x0c06e9f4u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9f6;
P_0c06e9f6: /* original f761, guest PC 0x0c06e9f6 */
if(!s->budget--) { s->failed_pc=0x0c06e9f6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c06e9f8;
P_0c06e9f8: /* original c727, guest PC 0x0c06e9f8 */
if(!s->budget--) { s->failed_pc=0x0c06e9f8u; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06e9fa;
P_0c06e9fa: /* original f308, guest PC 0x0c06e9fa */
if(!s->budget--) { s->failed_pc=0x0c06e9fau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9fc;
P_0c06e9fc: /* original f442, guest PC 0x0c06e9fc */
if(!s->budget--) { s->failed_pc=0x0c06e9fcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9fe;
P_0c06e9fe: /* original f772, guest PC 0x0c06e9fe */
if(!s->budget--) { s->failed_pc=0x0c06e9feu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06ea00;
P_0c06ea00: /* original f470, guest PC 0x0c06ea00 */
if(!s->budget--) { s->failed_pc=0x0c06ea00u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06ea02;
P_0c06ea02: /* original f345, guest PC 0x0c06ea02 */
if(!s->budget--) { s->failed_pc=0x0c06ea02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea04;
P_0c06ea04: /* original 8b01, guest PC 0x0c06ea04 */
if(!s->budget--) { s->failed_pc=0x0c06ea04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea0a; }
goto P_0c06ea06;
P_0c06ea06: /* original a002, guest PC 0x0c06ea06 */
if(!s->budget--) { s->failed_pc=0x0c06ea06u; return 0; }
fr[7]=0;
goto P_0c06ea0e;
P_0c06ea08: /* original f78d, guest PC 0x0c06ea08 */
if(!s->budget--) { s->failed_pc=0x0c06ea08u; return 0; }
fr[7]=0;
goto P_0c06ea0a;
P_0c06ea0a: /* original f74c, guest PC 0x0c06ea0a */
if(!s->budget--) { s->failed_pc=0x0c06ea0au; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06ea0c;
P_0c06ea0c: /* original f77d, guest PC 0x0c06ea0c */
if(!s->budget--) { s->failed_pc=0x0c06ea0cu; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06ea0e;
P_0c06ea0e: /* original f472, guest PC 0x0c06ea0e */
if(!s->budget--) { s->failed_pc=0x0c06ea0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06ea10;
P_0c06ea10: /* original f945, guest PC 0x0c06ea10 */
if(!s->budget--) { s->failed_pc=0x0c06ea10u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06ea12;
P_0c06ea12: /* original 8b02, guest PC 0x0c06ea12 */
if(!s->budget--) { s->failed_pc=0x0c06ea12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06ea14;
P_0c06ea14: /* original fc5c, guest PC 0x0c06ea14 */
if(!s->budget--) { s->failed_pc=0x0c06ea14u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c06ea16;
P_0c06ea16: /* original fd6c, guest PC 0x0c06ea16 */
if(!s->budget--) { s->failed_pc=0x0c06ea16u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c06ea18;
P_0c06ea18: /* original f94c, guest PC 0x0c06ea18 */
if(!s->budget--) { s->failed_pc=0x0c06ea18u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06ea1a;
P_0c06ea1a: /* original 75ff, guest PC 0x0c06ea1a */
if(!s->budget--) { s->failed_pc=0x0c06ea1au; return 0; }
r[5]+=0xffffffffu;
goto P_0c06ea1c;
P_0c06ea1c: /* original 2558, guest PC 0x0c06ea1c */
if(!s->budget--) { s->failed_pc=0x0c06ea1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06ea1e;
P_0c06ea1e: /* original 8ba1, guest PC 0x0c06ea1e */
if(!s->budget--) { s->failed_pc=0x0c06ea1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e964; }
goto P_0c06ea20;
P_0c06ea20: /* original f3ec, guest PC 0x0c06ea20 */
if(!s->budget--) { s->failed_pc=0x0c06ea20u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06ea22;
P_0c06ea22: /* original f3c1, guest PC 0x0c06ea22 */
if(!s->budget--) { s->failed_pc=0x0c06ea22u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'-');
goto P_0c06ea24;
P_0c06ea24: /* original e008, guest PC 0x0c06ea24 */
if(!s->budget--) { s->failed_pc=0x0c06ea24u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea26;
P_0c06ea26: /* original ff37, guest PC 0x0c06ea26 */
if(!s->budget--) { s->failed_pc=0x0c06ea26u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea28;
P_0c06ea28: /* original e004, guest PC 0x0c06ea28 */
if(!s->budget--) { s->failed_pc=0x0c06ea28u; return 0; }
r[0]=0x00000004u;
goto P_0c06ea2a;
P_0c06ea2a: /* original f2fc, guest PC 0x0c06ea2a */
if(!s->budget--) { s->failed_pc=0x0c06ea2au; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c06ea2c;
P_0c06ea2c: /* original f2d1, guest PC 0x0c06ea2c */
if(!s->budget--) { s->failed_pc=0x0c06ea2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'-');
goto P_0c06ea2e;
P_0c06ea2e: /* original f53c, guest PC 0x0c06ea2e */
if(!s->budget--) { s->failed_pc=0x0c06ea2eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c06ea30;
P_0c06ea30: /* original ff27, guest PC 0x0c06ea30 */
if(!s->budget--) { s->failed_pc=0x0c06ea30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06ea32;
P_0c06ea32: /* original d31a, guest PC 0x0c06ea32 */
if(!s->budget--) { s->failed_pc=0x0c06ea32u; return 0; }
r[3]=read(ram,0x0c06ea9cu,4);
goto P_0c06ea34;
P_0c06ea34: /* original 430b, guest PC 0x0c06ea34 */
if(!s->budget--) { s->failed_pc=0x0c06ea34u; return 0; }
target=r[3];
r[16]=code_base|0x0c06ea38u;
vf3_matrix_move(s,4,2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ea38u) { target=s->pc; goto dispatch; }
goto P_0c06ea38;
P_0c06ea36: /* original f42c, guest PC 0x0c06ea36 */
if(!s->budget--) { s->failed_pc=0x0c06ea36u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea38;
P_0c06ea38: /* original 640f, guest PC 0x0c06ea38 */
if(!s->budget--) { s->failed_pc=0x0c06ea38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06ea3a;
P_0c06ea3a: /* original f4fc, guest PC 0x0c06ea3a */
if(!s->budget--) { s->failed_pc=0x0c06ea3au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06ea3c;
P_0c06ea3c: /* original e004, guest PC 0x0c06ea3c */
if(!s->budget--) { s->failed_pc=0x0c06ea3cu; return 0; }
r[0]=0x00000004u;
goto P_0c06ea3e;
P_0c06ea3e: /* original f3f6, guest PC 0x0c06ea3e */
if(!s->budget--) { s->failed_pc=0x0c06ea3eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06ea40;
P_0c06ea40: /* original e008, guest PC 0x0c06ea40 */
if(!s->budget--) { s->failed_pc=0x0c06ea40u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea42;
P_0c06ea42: /* original f0f6, guest PC 0x0c06ea42 */
if(!s->budget--) { s->failed_pc=0x0c06ea42u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c06ea44;
P_0c06ea44: /* original f432, guest PC 0x0c06ea44 */
if(!s->budget--) { s->failed_pc=0x0c06ea44u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06ea46;
P_0c06ea46: /* original f24c, guest PC 0x0c06ea46 */
if(!s->budget--) { s->failed_pc=0x0c06ea46u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06ea48;
P_0c06ea48: /* original f2ee, guest PC 0x0c06ea48 */
if(!s->budget--) { s->failed_pc=0x0c06ea48u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c06ea4a;
P_0c06ea4a: /* original f42c, guest PC 0x0c06ea4a */
if(!s->budget--) { s->failed_pc=0x0c06ea4au; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea4c;
P_0c06ea4c: /* original f28d, guest PC 0x0c06ea4c */
if(!s->budget--) { s->failed_pc=0x0c06ea4cu; return 0; }
fr[2]=0;
goto P_0c06ea4e;
P_0c06ea4e: /* original f245, guest PC 0x0c06ea4e */
if(!s->budget--) { s->failed_pc=0x0c06ea4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06ea50;
P_0c06ea50: /* original 8d03, guest PC 0x0c06ea50 */
if(!s->budget--) { s->failed_pc=0x0c06ea50u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,13);
if(cond) { goto P_0c06ea5a; }
goto P_0c06ea54;
P_0c06ea52: /* original f5dc, guest PC 0x0c06ea52 */
if(!s->budget--) { s->failed_pc=0x0c06ea52u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c06ea54;
P_0c06ea54: /* original d212, guest PC 0x0c06ea54 */
if(!s->budget--) { s->failed_pc=0x0c06ea54u; return 0; }
r[2]=read(ram,0x0c06eaa0u,4);
goto P_0c06ea56;
P_0c06ea56: /* original 224a, guest PC 0x0c06ea56 */
if(!s->budget--) { s->failed_pc=0x0c06ea56u; return 0; }
r[2]^=r[4];
goto P_0c06ea58;
P_0c06ea58: /* original 642f, guest PC 0x0c06ea58 */
if(!s->budget--) { s->failed_pc=0x0c06ea58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c06ea5a;
P_0c06ea5a: /* original f4cc, guest PC 0x0c06ea5a */
if(!s->budget--) { s->failed_pc=0x0c06ea5au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c06ea5c;
P_0c06ea5c: /* original f4e1, guest PC 0x0c06ea5c */
if(!s->budget--) { s->failed_pc=0x0c06ea5cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c06ea5e;
P_0c06ea5e: /* original f5f1, guest PC 0x0c06ea5e */
if(!s->budget--) { s->failed_pc=0x0c06ea5eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c06ea60;
P_0c06ea60: /* original c70d, guest PC 0x0c06ea60 */
if(!s->budget--) { s->failed_pc=0x0c06ea60u; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06ea62;
P_0c06ea62: /* original f308, guest PC 0x0c06ea62 */
if(!s->budget--) { s->failed_pc=0x0c06ea62u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ea64;
P_0c06ea64: /* original f442, guest PC 0x0c06ea64 */
if(!s->budget--) { s->failed_pc=0x0c06ea64u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06ea66;
P_0c06ea66: /* original f552, guest PC 0x0c06ea66 */
if(!s->budget--) { s->failed_pc=0x0c06ea66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'*');
goto P_0c06ea68;
P_0c06ea68: /* original f450, guest PC 0x0c06ea68 */
if(!s->budget--) { s->failed_pc=0x0c06ea68u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c06ea6a;
P_0c06ea6a: /* original f345, guest PC 0x0c06ea6a */
if(!s->budget--) { s->failed_pc=0x0c06ea6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea6c;
P_0c06ea6c: /* original 8b01, guest PC 0x0c06ea6c */
if(!s->budget--) { s->failed_pc=0x0c06ea6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea72; }
goto P_0c06ea6e;
P_0c06ea6e: /* original a002, guest PC 0x0c06ea6e */
if(!s->budget--) { s->failed_pc=0x0c06ea6eu; return 0; }
fr[5]=0;
goto P_0c06ea76;
P_0c06ea70: /* original f58d, guest PC 0x0c06ea70 */
if(!s->budget--) { s->failed_pc=0x0c06ea70u; return 0; }
fr[5]=0;
goto P_0c06ea72;
P_0c06ea72: /* original f54c, guest PC 0x0c06ea72 */
if(!s->budget--) { s->failed_pc=0x0c06ea72u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06ea74;
P_0c06ea74: /* original f57d, guest PC 0x0c06ea74 */
if(!s->budget--) { s->failed_pc=0x0c06ea74u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c06ea76;
P_0c06ea76: /* original 53f4, guest PC 0x0c06ea76 */
if(!s->budget--) { s->failed_pc=0x0c06ea76u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c06ea78;
P_0c06ea78: /* original f452, guest PC 0x0c06ea78 */
if(!s->budget--) { s->failed_pc=0x0c06ea78u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06ea7a;
P_0c06ea7a: /* original f3da, guest PC 0x0c06ea7a */
if(!s->budget--) { s->failed_pc=0x0c06ea7au; return 0; }
vf3_matrix_store(s,ram,13,r[3]);
goto P_0c06ea7c;
P_0c06ea7c: /* original 53f7, guest PC 0x0c06ea7c */
if(!s->budget--) { s->failed_pc=0x0c06ea7cu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06ea7e;
P_0c06ea7e: /* original f3ca, guest PC 0x0c06ea7e */
if(!s->budget--) { s->failed_pc=0x0c06ea7eu; return 0; }
vf3_matrix_store(s,ram,12,r[3]);
goto P_0c06ea80;
P_0c06ea80: /* original 53f5, guest PC 0x0c06ea80 */
if(!s->budget--) { s->failed_pc=0x0c06ea80u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06ea82;
P_0c06ea82: /* original f34a, guest PC 0x0c06ea82 */
if(!s->budget--) { s->failed_pc=0x0c06ea82u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c06ea84;
P_0c06ea84: /* original 53f6, guest PC 0x0c06ea84 */
if(!s->budget--) { s->failed_pc=0x0c06ea84u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06ea86;
P_0c06ea86: /* original 7f30, guest PC 0x0c06ea86 */
if(!s->budget--) { s->failed_pc=0x0c06ea86u; return 0; }
r[15]+=0x00000030u;
goto P_0c06ea88;
P_0c06ea88: /* original 4f26, guest PC 0x0c06ea88 */
if(!s->budget--) { s->failed_pc=0x0c06ea88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ea8a;
P_0c06ea8a: /* original 2342, guest PC 0x0c06ea8a */
if(!s->budget--) { s->failed_pc=0x0c06ea8au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06ea8c;
P_0c06ea8c: /* original fcf9, guest PC 0x0c06ea8c */
if(!s->budget--) { s->failed_pc=0x0c06ea8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea8e;
P_0c06ea8e: /* original fdf9, guest PC 0x0c06ea8e */
if(!s->budget--) { s->failed_pc=0x0c06ea8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea90;
P_0c06ea90: /* original fef9, guest PC 0x0c06ea90 */
if(!s->budget--) { s->failed_pc=0x0c06ea90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea92;
P_0c06ea92: /* original 000b, guest PC 0x0c06ea92 */
if(!s->budget--) { s->failed_pc=0x0c06ea92u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c06ea94: /* original fff9, guest PC 0x0c06ea94 */
if(!s->budget--) { s->failed_pc=0x0c06ea94u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c06ea96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ea96u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
