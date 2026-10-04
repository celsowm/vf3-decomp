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
int vf3_tenpp_leaf_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b736u: goto P_0c07b736;
case 0x0c07b738u: goto P_0c07b738;
case 0x0c07b73au: goto P_0c07b73a;
case 0x0c07b73cu: goto P_0c07b73c;
case 0x0c07b73eu: goto P_0c07b73e;
case 0x0c07b740u: goto P_0c07b740;
case 0x0c07b742u: goto P_0c07b742;
case 0x0c07b744u: goto P_0c07b744;
case 0x0c07b746u: goto P_0c07b746;
case 0x0c07b748u: goto P_0c07b748;
case 0x0c07b74au: goto P_0c07b74a;
case 0x0c07b74cu: goto P_0c07b74c;
case 0x0c07b74eu: goto P_0c07b74e;
case 0x0c07b750u: goto P_0c07b750;
case 0x0c07b752u: goto P_0c07b752;
case 0x0c07b754u: goto P_0c07b754;
case 0x0c07b756u: goto P_0c07b756;
case 0x0c07b758u: goto P_0c07b758;
case 0x0c07b98au: goto P_0c07b98a;
case 0x0c07b98cu: goto P_0c07b98c;
case 0x0c07b98eu: goto P_0c07b98e;
case 0x0c07b990u: goto P_0c07b990;
case 0x0c07b992u: goto P_0c07b992;
case 0x0c07b994u: goto P_0c07b994;
case 0x0c07b996u: goto P_0c07b996;
case 0x0c07b998u: goto P_0c07b998;
case 0x0c07b99au: goto P_0c07b99a;
case 0x0c07b99cu: goto P_0c07b99c;
case 0x0c07b99eu: goto P_0c07b99e;
case 0x0c0805f8u: goto P_0c0805f8;
case 0x0c0805fau: goto P_0c0805fa;
case 0x0c0805fcu: goto P_0c0805fc;
case 0x0c0805feu: goto P_0c0805fe;
case 0x0c080600u: goto P_0c080600;
case 0x0c080602u: goto P_0c080602;
case 0x0c080604u: goto P_0c080604;
case 0x0c080606u: goto P_0c080606;
case 0x0c080608u: goto P_0c080608;
case 0x0c08060au: goto P_0c08060a;
case 0x0c08060cu: goto P_0c08060c;
case 0x0c08060eu: goto P_0c08060e;
case 0x0c080610u: goto P_0c080610;
case 0x0c0807f0u: goto P_0c0807f0;
case 0x0c0807f2u: goto P_0c0807f2;
case 0x0c0807f4u: goto P_0c0807f4;
case 0x0c0807f6u: goto P_0c0807f6;
case 0x0c0807f8u: goto P_0c0807f8;
case 0x0c0807fau: goto P_0c0807fa;
case 0x0c0807fcu: goto P_0c0807fc;
case 0x0c0807feu: goto P_0c0807fe;
case 0x0c080800u: goto P_0c080800;
case 0x0c080802u: goto P_0c080802;
case 0x0c080804u: goto P_0c080804;
case 0x0c080806u: goto P_0c080806;
case 0x0c080808u: goto P_0c080808;
case 0x0c08080au: goto P_0c08080a;
case 0x0c08080cu: goto P_0c08080c;
case 0x0c08080eu: goto P_0c08080e;
case 0x0c080810u: goto P_0c080810;
case 0x0c080812u: goto P_0c080812;
case 0x0c080814u: goto P_0c080814;
case 0x0c080816u: goto P_0c080816;
case 0x0c080818u: goto P_0c080818;
case 0x0c08081au: goto P_0c08081a;
case 0x0c08081cu: goto P_0c08081c;
case 0x0c08081eu: goto P_0c08081e;
case 0x0c080820u: goto P_0c080820;
case 0x0c080822u: goto P_0c080822;
case 0x0c081098u: goto P_0c081098;
case 0x0c08109au: goto P_0c08109a;
case 0x0c08109cu: goto P_0c08109c;
case 0x0c08109eu: goto P_0c08109e;
case 0x0c0810a0u: goto P_0c0810a0;
case 0x0c0810a2u: goto P_0c0810a2;
case 0x0c0810a4u: goto P_0c0810a4;
case 0x0c0810a6u: goto P_0c0810a6;
case 0x0c0810a8u: goto P_0c0810a8;
case 0x0c0810aau: goto P_0c0810aa;
case 0x0c0810acu: goto P_0c0810ac;
case 0x0c0810aeu: goto P_0c0810ae;
case 0x0c0810b0u: goto P_0c0810b0;
case 0x0c0810b2u: goto P_0c0810b2;
case 0x0c0810b4u: goto P_0c0810b4;
case 0x0c0810b6u: goto P_0c0810b6;
case 0x0c0810b8u: goto P_0c0810b8;
case 0x0c0810bau: goto P_0c0810ba;
case 0x0c081ce8u: goto P_0c081ce8;
case 0x0c081ceau: goto P_0c081cea;
case 0x0c081cecu: goto P_0c081cec;
case 0x0c081ceeu: goto P_0c081cee;
case 0x0c081cf0u: goto P_0c081cf0;
case 0x0c081cf2u: goto P_0c081cf2;
case 0x0c081cf4u: goto P_0c081cf4;
case 0x0c081cf6u: goto P_0c081cf6;
case 0x0c081cf8u: goto P_0c081cf8;
case 0x0c081cfau: goto P_0c081cfa;
case 0x0c081cfcu: goto P_0c081cfc;
case 0x0c081cfeu: goto P_0c081cfe;
case 0x0c081d00u: goto P_0c081d00;
case 0x0c081d02u: goto P_0c081d02;
case 0x0c081d04u: goto P_0c081d04;
case 0x0c081d06u: goto P_0c081d06;
case 0x0c081d08u: goto P_0c081d08;
case 0x0c081d0au: goto P_0c081d0a;
case 0x0c081d0cu: goto P_0c081d0c;
case 0x0c081d0eu: goto P_0c081d0e;
case 0x0c08763cu: goto P_0c08763c;
case 0x0c08763eu: goto P_0c08763e;
case 0x0c087640u: goto P_0c087640;
case 0x0c087642u: goto P_0c087642;
case 0x0c087644u: goto P_0c087644;
case 0x0c087646u: goto P_0c087646;
case 0x0c087648u: goto P_0c087648;
case 0x0c08764au: goto P_0c08764a;
case 0x0c08764cu: goto P_0c08764c;
case 0x0c08764eu: goto P_0c08764e;
case 0x0c087650u: goto P_0c087650;
case 0x0c087652u: goto P_0c087652;
case 0x0c087654u: goto P_0c087654;
case 0x0c087656u: goto P_0c087656;
case 0x0c087658u: goto P_0c087658;
case 0x0c08765au: goto P_0c08765a;
case 0x0c08765cu: goto P_0c08765c;
case 0x0c08765eu: goto P_0c08765e;
case 0x0c087660u: goto P_0c087660;
case 0x0c087662u: goto P_0c087662;
case 0x0c087664u: goto P_0c087664;
case 0x0c087666u: goto P_0c087666;
case 0x0c087668u: goto P_0c087668;
case 0x0c08766au: goto P_0c08766a;
case 0x0c08766cu: goto P_0c08766c;
case 0x0c08766eu: goto P_0c08766e;
case 0x0c087670u: goto P_0c087670;
case 0x0c087672u: goto P_0c087672;
case 0x0c087674u: goto P_0c087674;
case 0x0c087676u: goto P_0c087676;
case 0x0c087678u: goto P_0c087678;
case 0x0c08767au: goto P_0c08767a;
case 0x0c08767cu: goto P_0c08767c;
case 0x0c08767eu: goto P_0c08767e;
case 0x0c087680u: goto P_0c087680;
case 0x0c087682u: goto P_0c087682;
case 0x0c087684u: goto P_0c087684;
case 0x0c087686u: goto P_0c087686;
case 0x0c087688u: goto P_0c087688;
case 0x0c08768au: goto P_0c08768a;
case 0x0c08768cu: goto P_0c08768c;
case 0x0c08768eu: goto P_0c08768e;
case 0x0c087690u: goto P_0c087690;
case 0x0c087692u: goto P_0c087692;
case 0x0c087694u: goto P_0c087694;
case 0x0c087696u: goto P_0c087696;
case 0x0c08769cu: goto P_0c08769c;
case 0x0c08769eu: goto P_0c08769e;
case 0x0c0876a0u: goto P_0c0876a0;
case 0x0c0876a2u: goto P_0c0876a2;
case 0x0c0876a4u: goto P_0c0876a4;
case 0x0c0876a6u: goto P_0c0876a6;
case 0x0c0876a8u: goto P_0c0876a8;
case 0x0c0876aau: goto P_0c0876aa;
case 0x0c0876acu: goto P_0c0876ac;
case 0x0c0876aeu: goto P_0c0876ae;
case 0x0c0876b0u: goto P_0c0876b0;
case 0x0c0876b2u: goto P_0c0876b2;
case 0x0c0876b4u: goto P_0c0876b4;
case 0x0c0876b6u: goto P_0c0876b6;
case 0x0c0876b8u: goto P_0c0876b8;
case 0x0c0876bau: goto P_0c0876ba;
case 0x0c0876bcu: goto P_0c0876bc;
case 0x0c0876beu: goto P_0c0876be;
case 0x0c0876c0u: goto P_0c0876c0;
case 0x0c0876c2u: goto P_0c0876c2;
case 0x0c0876c4u: goto P_0c0876c4;
case 0x0c0876c6u: goto P_0c0876c6;
case 0x0c0876c8u: goto P_0c0876c8;
case 0x0c0876cau: goto P_0c0876ca;
case 0x0c0876ccu: goto P_0c0876cc;
case 0x0c0876ceu: goto P_0c0876ce;
case 0x0c0876d0u: goto P_0c0876d0;
case 0x0c0876d2u: goto P_0c0876d2;
case 0x0c0876d4u: goto P_0c0876d4;
case 0x0c0876d6u: goto P_0c0876d6;
case 0x0c0876d8u: goto P_0c0876d8;
case 0x0c0876dau: goto P_0c0876da;
case 0x0c0876dcu: goto P_0c0876dc;
case 0x0c0876deu: goto P_0c0876de;
case 0x0c0876e0u: goto P_0c0876e0;
case 0x0c0876e2u: goto P_0c0876e2;
case 0x0c0876e4u: goto P_0c0876e4;
case 0x0c0876e6u: goto P_0c0876e6;
case 0x0c0876e8u: goto P_0c0876e8;
case 0x0c0876eau: goto P_0c0876ea;
case 0x0c0876ecu: goto P_0c0876ec;
case 0x0c0876eeu: goto P_0c0876ee;
case 0x0c0876f0u: goto P_0c0876f0;
case 0x0c0879dau: goto P_0c0879da;
case 0x0c0879dcu: goto P_0c0879dc;
case 0x0c0879deu: goto P_0c0879de;
case 0x0c0879e0u: goto P_0c0879e0;
case 0x0c0879e2u: goto P_0c0879e2;
case 0x0c0879e4u: goto P_0c0879e4;
case 0x0c0879e6u: goto P_0c0879e6;
case 0x0c0879e8u: goto P_0c0879e8;
case 0x0c0879eau: goto P_0c0879ea;
case 0x0c0879ecu: goto P_0c0879ec;
case 0x0c0879eeu: goto P_0c0879ee;
case 0x0c0879f0u: goto P_0c0879f0;
case 0x0c0879f2u: goto P_0c0879f2;
case 0x0c0879f4u: goto P_0c0879f4;
case 0x0c0879f6u: goto P_0c0879f6;
case 0x0c0879f8u: goto P_0c0879f8;
case 0x0c0879fau: goto P_0c0879fa;
case 0x0c0879fcu: goto P_0c0879fc;
case 0x0c0879feu: goto P_0c0879fe;
case 0x0c087a00u: goto P_0c087a00;
case 0x0c087a02u: goto P_0c087a02;
case 0x0c087a04u: goto P_0c087a04;
case 0x0c087a06u: goto P_0c087a06;
case 0x0c087a08u: goto P_0c087a08;
case 0x0c087a0au: goto P_0c087a0a;
case 0x0c087a0cu: goto P_0c087a0c;
case 0x0c087a0eu: goto P_0c087a0e;
case 0x0c087a10u: goto P_0c087a10;
case 0x0c087a12u: goto P_0c087a12;
case 0x0c087a14u: goto P_0c087a14;
case 0x0c087a16u: goto P_0c087a16;
case 0x0c087a18u: goto P_0c087a18;
case 0x0c087a1au: goto P_0c087a1a;
case 0x0c087a1cu: goto P_0c087a1c;
case 0x0c087a1eu: goto P_0c087a1e;
case 0x0c087a20u: goto P_0c087a20;
case 0x0c087a22u: goto P_0c087a22;
case 0x0c08b648u: goto P_0c08b648;
case 0x0c08b64au: goto P_0c08b64a;
case 0x0c08b64cu: goto P_0c08b64c;
case 0x0c08b64eu: goto P_0c08b64e;
case 0x0c08b650u: goto P_0c08b650;
case 0x0c08b652u: goto P_0c08b652;
case 0x0c08b654u: goto P_0c08b654;
case 0x0c08b656u: goto P_0c08b656;
case 0x0c08b658u: goto P_0c08b658;
case 0x0c08b65au: goto P_0c08b65a;
case 0x0c08b65cu: goto P_0c08b65c;
case 0x0c08b65eu: goto P_0c08b65e;
case 0x0c08b660u: goto P_0c08b660;
case 0x0c08b662u: goto P_0c08b662;
case 0x0c08b668u: goto P_0c08b668;
case 0x0c08b66au: goto P_0c08b66a;
case 0x0c08b66cu: goto P_0c08b66c;
case 0x0c08b66eu: goto P_0c08b66e;
case 0x0c08b670u: goto P_0c08b670;
case 0x0c08b672u: goto P_0c08b672;
case 0x0c08b674u: goto P_0c08b674;
case 0x0c08b676u: goto P_0c08b676;
case 0x0c08b678u: goto P_0c08b678;
case 0x0c08b67au: goto P_0c08b67a;
case 0x0c08b67cu: goto P_0c08b67c;
case 0x0c08b67eu: goto P_0c08b67e;
case 0x0c08b680u: goto P_0c08b680;
case 0x0c08b682u: goto P_0c08b682;
case 0x0c08b684u: goto P_0c08b684;
case 0x0c08b686u: goto P_0c08b686;
case 0x0c08b688u: goto P_0c08b688;
case 0x0c08b68au: goto P_0c08b68a;
case 0x0c08b68cu: goto P_0c08b68c;
case 0x0c08b68eu: goto P_0c08b68e;
case 0x0c08b690u: goto P_0c08b690;
case 0x0c08b692u: goto P_0c08b692;
case 0x0c08b694u: goto P_0c08b694;
case 0x0c08b696u: goto P_0c08b696;
case 0x0c08b698u: goto P_0c08b698;
case 0x0c08b69au: goto P_0c08b69a;
case 0x0c08b69cu: goto P_0c08b69c;
case 0x0c08b69eu: goto P_0c08b69e;
case 0x0c08b6a0u: goto P_0c08b6a0;
case 0x0c08b6a2u: goto P_0c08b6a2;
case 0x0c08b6a4u: goto P_0c08b6a4;
case 0x0c08b6a6u: goto P_0c08b6a6;
case 0x0c08b6a8u: goto P_0c08b6a8;
case 0x0c08b6aau: goto P_0c08b6aa;
case 0x0c08b6acu: goto P_0c08b6ac;
case 0x0c08b6aeu: goto P_0c08b6ae;
case 0x0c08b6b0u: goto P_0c08b6b0;
case 0x0c08b6b2u: goto P_0c08b6b2;
case 0x0c08b6b4u: goto P_0c08b6b4;
case 0x0c08b6b6u: goto P_0c08b6b6;
case 0x0c08b6b8u: goto P_0c08b6b8;
case 0x0c08b6bau: goto P_0c08b6ba;
case 0x0c08b6bcu: goto P_0c08b6bc;
case 0x0c08b6beu: goto P_0c08b6be;
case 0x0c08b6c0u: goto P_0c08b6c0;
case 0x0c08b6c2u: goto P_0c08b6c2;
case 0x0c08b6c4u: goto P_0c08b6c4;
case 0x0c08b6c6u: goto P_0c08b6c6;
case 0x0c08b6c8u: goto P_0c08b6c8;
case 0x0c08b6cau: goto P_0c08b6ca;
case 0x0c08b6ccu: goto P_0c08b6cc;
case 0x0c08b6ceu: goto P_0c08b6ce;
case 0x0c08b6d0u: goto P_0c08b6d0;
case 0x0c08b6d2u: goto P_0c08b6d2;
case 0x0c08b6d4u: goto P_0c08b6d4;
case 0x0c08b6d6u: goto P_0c08b6d6;
case 0x0c08b6d8u: goto P_0c08b6d8;
case 0x0c08b6dau: goto P_0c08b6da;
case 0x0c08b6dcu: goto P_0c08b6dc;
case 0x0c08b6deu: goto P_0c08b6de;
case 0x0c08b6e0u: goto P_0c08b6e0;
case 0x0c08b6e2u: goto P_0c08b6e2;
case 0x0c08b6e4u: goto P_0c08b6e4;
case 0x0c08b6e6u: goto P_0c08b6e6;
case 0x0c08b6e8u: goto P_0c08b6e8;
case 0x0c08b6eau: goto P_0c08b6ea;
case 0x0c08b6ecu: goto P_0c08b6ec;
case 0x0c08b6eeu: goto P_0c08b6ee;
case 0x0c08b6f0u: goto P_0c08b6f0;
case 0x0c08b6f2u: goto P_0c08b6f2;
case 0x0c08b6f4u: goto P_0c08b6f4;
case 0x0c08b6f6u: goto P_0c08b6f6;
case 0x0c08b6f8u: goto P_0c08b6f8;
case 0x0c08b6fau: goto P_0c08b6fa;
case 0x0c08b6fcu: goto P_0c08b6fc;
case 0x0c08b6feu: goto P_0c08b6fe;
case 0x0c08b700u: goto P_0c08b700;
case 0x0c08b702u: goto P_0c08b702;
case 0x0c08b704u: goto P_0c08b704;
case 0x0c08b706u: goto P_0c08b706;
case 0x0c08b708u: goto P_0c08b708;
case 0x0c08b70au: goto P_0c08b70a;
case 0x0c08b70cu: goto P_0c08b70c;
case 0x0c08b70eu: goto P_0c08b70e;
case 0x0c08b710u: goto P_0c08b710;
case 0x0c08b712u: goto P_0c08b712;
case 0x0c08b714u: goto P_0c08b714;
case 0x0c08b716u: goto P_0c08b716;
case 0x0c08b718u: goto P_0c08b718;
case 0x0c08b71au: goto P_0c08b71a;
case 0x0c08b71cu: goto P_0c08b71c;
case 0x0c08b71eu: goto P_0c08b71e;
case 0x0c08b720u: goto P_0c08b720;
case 0x0c08b722u: goto P_0c08b722;
case 0x0c08b724u: goto P_0c08b724;
case 0x0c08b726u: goto P_0c08b726;
case 0x0c08b728u: goto P_0c08b728;
case 0x0c08b72au: goto P_0c08b72a;
case 0x0c08b72cu: goto P_0c08b72c;
case 0x0c08b72eu: goto P_0c08b72e;
case 0x0c08b730u: goto P_0c08b730;
case 0x0c08b732u: goto P_0c08b732;
case 0x0c08b734u: goto P_0c08b734;
case 0x0c08b736u: goto P_0c08b736;
case 0x0c08b738u: goto P_0c08b738;
case 0x0c08b73au: goto P_0c08b73a;
case 0x0c08b73cu: goto P_0c08b73c;
case 0x0c08b73eu: goto P_0c08b73e;
case 0x0c08b740u: goto P_0c08b740;
case 0x0c08b742u: goto P_0c08b742;
case 0x0c08b744u: goto P_0c08b744;
case 0x0c08b746u: goto P_0c08b746;
case 0x0c08b748u: goto P_0c08b748;
case 0x0c08b74au: goto P_0c08b74a;
case 0x0c08b74cu: goto P_0c08b74c;
case 0x0c08b74eu: goto P_0c08b74e;
case 0x0c08b750u: goto P_0c08b750;
case 0x0c08b752u: goto P_0c08b752;
case 0x0c08b754u: goto P_0c08b754;
case 0x0c08b756u: goto P_0c08b756;
case 0x0c08b758u: goto P_0c08b758;
case 0x0c08b75au: goto P_0c08b75a;
case 0x0c08b75cu: goto P_0c08b75c;
case 0x0c08b75eu: goto P_0c08b75e;
case 0x0c08b760u: goto P_0c08b760;
case 0x0c08b762u: goto P_0c08b762;
case 0x0c08b764u: goto P_0c08b764;
case 0x0c08b766u: goto P_0c08b766;
case 0x0c08b768u: goto P_0c08b768;
case 0x0c08b76au: goto P_0c08b76a;
case 0x0c08b76cu: goto P_0c08b76c;
case 0x0c08b76eu: goto P_0c08b76e;
case 0x0c08b770u: goto P_0c08b770;
case 0x0c08b772u: goto P_0c08b772;
case 0x0c08b774u: goto P_0c08b774;
case 0x0c08b776u: goto P_0c08b776;
case 0x0c08b778u: goto P_0c08b778;
case 0x0c08b77au: goto P_0c08b77a;
case 0x0c08b77cu: goto P_0c08b77c;
case 0x0c08b77eu: goto P_0c08b77e;
case 0x0c08b7acu: goto P_0c08b7ac;
case 0x0c08b7aeu: goto P_0c08b7ae;
case 0x0c08b7b0u: goto P_0c08b7b0;
case 0x0c08b7b2u: goto P_0c08b7b2;
case 0x0c08b7b4u: goto P_0c08b7b4;
case 0x0c08b7b6u: goto P_0c08b7b6;
case 0x0c08b7b8u: goto P_0c08b7b8;
case 0x0c08b7bau: goto P_0c08b7ba;
case 0x0c08b7bcu: goto P_0c08b7bc;
case 0x0c08b7beu: goto P_0c08b7be;
case 0x0c08b7c0u: goto P_0c08b7c0;
case 0x0c08b7c2u: goto P_0c08b7c2;
case 0x0c08b7c4u: goto P_0c08b7c4;
case 0x0c08b7c6u: goto P_0c08b7c6;
case 0x0c08b7c8u: goto P_0c08b7c8;
case 0x0c08b7cau: goto P_0c08b7ca;
case 0x0c08b7ccu: goto P_0c08b7cc;
case 0x0c08b7ceu: goto P_0c08b7ce;
case 0x0c08b7d0u: goto P_0c08b7d0;
case 0x0c08b7d2u: goto P_0c08b7d2;
case 0x0c08b7d4u: goto P_0c08b7d4;
case 0x0c08b7d6u: goto P_0c08b7d6;
case 0x0c08b7d8u: goto P_0c08b7d8;
case 0x0c08b7dau: goto P_0c08b7da;
case 0x0c08b7dcu: goto P_0c08b7dc;
case 0x0c08b7deu: goto P_0c08b7de;
case 0x0c08b7e0u: goto P_0c08b7e0;
case 0x0c08b7e2u: goto P_0c08b7e2;
case 0x0c08b7e4u: goto P_0c08b7e4;
case 0x0c08b7e6u: goto P_0c08b7e6;
case 0x0c08b7e8u: goto P_0c08b7e8;
case 0x0c08d406u: goto P_0c08d406;
case 0x0c08d408u: goto P_0c08d408;
case 0x0c08d40au: goto P_0c08d40a;
case 0x0c08d40cu: goto P_0c08d40c;
case 0x0c08d40eu: goto P_0c08d40e;
case 0x0c08d410u: goto P_0c08d410;
case 0x0c08d412u: goto P_0c08d412;
case 0x0c08d414u: goto P_0c08d414;
case 0x0c08d416u: goto P_0c08d416;
case 0x0c08d418u: goto P_0c08d418;
case 0x0c08d41au: goto P_0c08d41a;
case 0x0c08d41cu: goto P_0c08d41c;
case 0x0c08d41eu: goto P_0c08d41e;
case 0x0c08d420u: goto P_0c08d420;
case 0x0c08d422u: goto P_0c08d422;
case 0x0c08d424u: goto P_0c08d424;
case 0x0c08d426u: goto P_0c08d426;
case 0x0c08d428u: goto P_0c08d428;
case 0x0c08d42au: goto P_0c08d42a;
case 0x0c08d42cu: goto P_0c08d42c;
case 0x0c08d42eu: goto P_0c08d42e;
case 0x0c08d430u: goto P_0c08d430;
case 0x0c08d432u: goto P_0c08d432;
case 0x0c08d434u: goto P_0c08d434;
case 0x0c08d436u: goto P_0c08d436;
case 0x0c08d438u: goto P_0c08d438;
case 0x0c08d43au: goto P_0c08d43a;
case 0x0c08d43cu: goto P_0c08d43c;
case 0x0c08d43eu: goto P_0c08d43e;
case 0x0c08d440u: goto P_0c08d440;
case 0x0c08d442u: goto P_0c08d442;
case 0x0c08d444u: goto P_0c08d444;
case 0x0c08d446u: goto P_0c08d446;
case 0x0c08d448u: goto P_0c08d448;
case 0x0c08d44au: goto P_0c08d44a;
case 0x0c08f344u: goto P_0c08f344;
case 0x0c08f346u: goto P_0c08f346;
case 0x0c08f348u: goto P_0c08f348;
case 0x0c08f34au: goto P_0c08f34a;
case 0x0c08f34cu: goto P_0c08f34c;
case 0x0c08f34eu: goto P_0c08f34e;
case 0x0c08f350u: goto P_0c08f350;
case 0x0c08f352u: goto P_0c08f352;
case 0x0c08f354u: goto P_0c08f354;
case 0x0c08f356u: goto P_0c08f356;
case 0x0c08f358u: goto P_0c08f358;
case 0x0c08f35au: goto P_0c08f35a;
case 0x0c08f35cu: goto P_0c08f35c;
case 0x0c08f35eu: goto P_0c08f35e;
case 0x0c08f360u: goto P_0c08f360;
case 0x0c08f362u: goto P_0c08f362;
case 0x0c08f364u: goto P_0c08f364;
case 0x0c08f366u: goto P_0c08f366;
case 0x0c08f368u: goto P_0c08f368;
case 0x0c08f36au: goto P_0c08f36a;
case 0x0c08f36cu: goto P_0c08f36c;
case 0x0c08f36eu: goto P_0c08f36e;
case 0x0c08f370u: goto P_0c08f370;
case 0x0c08f372u: goto P_0c08f372;
case 0x0c08f374u: goto P_0c08f374;
case 0x0c08f376u: goto P_0c08f376;
case 0x0c08f378u: goto P_0c08f378;
case 0x0c08f37au: goto P_0c08f37a;
case 0x0c08f37cu: goto P_0c08f37c;
case 0x0c08f37eu: goto P_0c08f37e;
case 0x0c08f380u: goto P_0c08f380;
case 0x0c08f382u: goto P_0c08f382;
case 0x0c08f384u: goto P_0c08f384;
case 0x0c08f386u: goto P_0c08f386;
case 0x0c08f388u: goto P_0c08f388;
case 0x0c08f38au: goto P_0c08f38a;
case 0x0c08f38cu: goto P_0c08f38c;
case 0x0c08f38eu: goto P_0c08f38e;
case 0x0c08f390u: goto P_0c08f390;
case 0x0c08f392u: goto P_0c08f392;
case 0x0c08f394u: goto P_0c08f394;
case 0x0c08f396u: goto P_0c08f396;
case 0x0c08f398u: goto P_0c08f398;
case 0x0c08f39au: goto P_0c08f39a;
case 0x0c08f39cu: goto P_0c08f39c;
case 0x0c08f39eu: goto P_0c08f39e;
case 0x0c08f3a0u: goto P_0c08f3a0;
case 0x0c08f3a2u: goto P_0c08f3a2;
case 0x0c08f3a4u: goto P_0c08f3a4;
case 0x0c08f3a6u: goto P_0c08f3a6;
case 0x0c08f3a8u: goto P_0c08f3a8;
case 0x0c08f3aau: goto P_0c08f3aa;
case 0x0c08f3acu: goto P_0c08f3ac;
case 0x0c08f3aeu: goto P_0c08f3ae;
case 0x0c08f3b0u: goto P_0c08f3b0;
case 0x0c08f3b2u: goto P_0c08f3b2;
case 0x0c08f3b4u: goto P_0c08f3b4;
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
case 0x0c08f4aeu: goto P_0c08f4ae;
case 0x0c08f4b0u: goto P_0c08f4b0;
case 0x0c08f4b2u: goto P_0c08f4b2;
case 0x0c08f4b4u: goto P_0c08f4b4;
case 0x0c08f4b6u: goto P_0c08f4b6;
case 0x0c08f4b8u: goto P_0c08f4b8;
case 0x0c08f4bau: goto P_0c08f4ba;
case 0x0c08f4bcu: goto P_0c08f4bc;
case 0x0c08f4beu: goto P_0c08f4be;
case 0x0c08f4c0u: goto P_0c08f4c0;
case 0x0c08f4d6u: goto P_0c08f4d6;
case 0x0c08f4d8u: goto P_0c08f4d8;
case 0x0c08f4dau: goto P_0c08f4da;
case 0x0c08f4dcu: goto P_0c08f4dc;
case 0x0c08f4deu: goto P_0c08f4de;
case 0x0c08f4e0u: goto P_0c08f4e0;
case 0x0c08f4e2u: goto P_0c08f4e2;
case 0x0c08f4e4u: goto P_0c08f4e4;
case 0x0c08f4e6u: goto P_0c08f4e6;
case 0x0c08f4e8u: goto P_0c08f4e8;
case 0x0c08f4eau: goto P_0c08f4ea;
case 0x0c08f4ecu: goto P_0c08f4ec;
case 0x0c08f4eeu: goto P_0c08f4ee;
case 0x0c08f4f0u: goto P_0c08f4f0;
case 0x0c08f4f2u: goto P_0c08f4f2;
case 0x0c08f4f4u: goto P_0c08f4f4;
case 0x0c08f4f6u: goto P_0c08f4f6;
case 0x0c08f4f8u: goto P_0c08f4f8;
case 0x0c08f4fau: goto P_0c08f4fa;
case 0x0c08f4fcu: goto P_0c08f4fc;
case 0x0c08f4feu: goto P_0c08f4fe;
case 0x0c08f500u: goto P_0c08f500;
case 0x0c08f502u: goto P_0c08f502;
case 0x0c08f504u: goto P_0c08f504;
case 0x0c08f506u: goto P_0c08f506;
case 0x0c08f508u: goto P_0c08f508;
case 0x0c08f50au: goto P_0c08f50a;
case 0x0c08f50cu: goto P_0c08f50c;
case 0x0c08f50eu: goto P_0c08f50e;
case 0x0c08f510u: goto P_0c08f510;
case 0x0c08f512u: goto P_0c08f512;
case 0x0c08f514u: goto P_0c08f514;
case 0x0c08f516u: goto P_0c08f516;
case 0x0c08f518u: goto P_0c08f518;
case 0x0c08f51au: goto P_0c08f51a;
case 0x0c08f51cu: goto P_0c08f51c;
case 0x0c08f51eu: goto P_0c08f51e;
case 0x0c08f520u: goto P_0c08f520;
case 0x0c08f522u: goto P_0c08f522;
case 0x0c08f524u: goto P_0c08f524;
case 0x0c08f526u: goto P_0c08f526;
case 0x0c08f528u: goto P_0c08f528;
case 0x0c08f52au: goto P_0c08f52a;
case 0x0c08f52cu: goto P_0c08f52c;
case 0x0c08f52eu: goto P_0c08f52e;
case 0x0c08f530u: goto P_0c08f530;
case 0x0c08f5c2u: goto P_0c08f5c2;
case 0x0c08f5c4u: goto P_0c08f5c4;
case 0x0c08f5c6u: goto P_0c08f5c6;
case 0x0c08f5c8u: goto P_0c08f5c8;
case 0x0c08f5cau: goto P_0c08f5ca;
case 0x0c08f5ccu: goto P_0c08f5cc;
case 0x0c08f5ceu: goto P_0c08f5ce;
case 0x0c08f5d0u: goto P_0c08f5d0;
case 0x0c08f5d2u: goto P_0c08f5d2;
case 0x0c08f5d4u: goto P_0c08f5d4;
case 0x0c08f5d6u: goto P_0c08f5d6;
case 0x0c08f5d8u: goto P_0c08f5d8;
case 0x0c08f5dau: goto P_0c08f5da;
case 0x0c08f5dcu: goto P_0c08f5dc;
case 0x0c08f5deu: goto P_0c08f5de;
case 0x0c08f5e0u: goto P_0c08f5e0;
case 0x0c08f5e2u: goto P_0c08f5e2;
case 0x0c08f5e4u: goto P_0c08f5e4;
case 0x0c08f5e6u: goto P_0c08f5e6;
case 0x0c08f5e8u: goto P_0c08f5e8;
case 0x0c08f5eau: goto P_0c08f5ea;
case 0x0c08f5ecu: goto P_0c08f5ec;
case 0x0c08f5eeu: goto P_0c08f5ee;
case 0x0c08f5f0u: goto P_0c08f5f0;
case 0x0c08f5f2u: goto P_0c08f5f2;
case 0x0c08f5f4u: goto P_0c08f5f4;
case 0x0c08f5f6u: goto P_0c08f5f6;
case 0x0c08f5f8u: goto P_0c08f5f8;
case 0x0c08f5fau: goto P_0c08f5fa;
case 0x0c08f5fcu: goto P_0c08f5fc;
case 0x0c08f5feu: goto P_0c08f5fe;
case 0x0c08f600u: goto P_0c08f600;
case 0x0c08f602u: goto P_0c08f602;
case 0x0c08f604u: goto P_0c08f604;
case 0x0c08f606u: goto P_0c08f606;
case 0x0c08f608u: goto P_0c08f608;
case 0x0c08f60au: goto P_0c08f60a;
case 0x0c08f60cu: goto P_0c08f60c;
case 0x0c08f60eu: goto P_0c08f60e;
case 0x0c08f610u: goto P_0c08f610;
case 0x0c08f612u: goto P_0c08f612;
case 0x0c08f614u: goto P_0c08f614;
case 0x0c08f616u: goto P_0c08f616;
case 0x0c08f618u: goto P_0c08f618;
case 0x0c08f61au: goto P_0c08f61a;
case 0x0c08f61cu: goto P_0c08f61c;
case 0x0c08f61eu: goto P_0c08f61e;
case 0x0c08f620u: goto P_0c08f620;
case 0x0c08f622u: goto P_0c08f622;
case 0x0c08f624u: goto P_0c08f624;
case 0x0c08f626u: goto P_0c08f626;
case 0x0c08f628u: goto P_0c08f628;
case 0x0c08f62au: goto P_0c08f62a;
case 0x0c08f62cu: goto P_0c08f62c;
case 0x0c08f62eu: goto P_0c08f62e;
case 0x0c08f630u: goto P_0c08f630;
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
case 0x0c0944f6u: goto P_0c0944f6;
case 0x0c0944f8u: goto P_0c0944f8;
case 0x0c0944fau: goto P_0c0944fa;
case 0x0c0944fcu: goto P_0c0944fc;
case 0x0c0944feu: goto P_0c0944fe;
case 0x0c094500u: goto P_0c094500;
case 0x0c094502u: goto P_0c094502;
case 0x0c094504u: goto P_0c094504;
case 0x0c094506u: goto P_0c094506;
case 0x0c094508u: goto P_0c094508;
case 0x0c09450au: goto P_0c09450a;
case 0x0c09450cu: goto P_0c09450c;
case 0x0c09450eu: goto P_0c09450e;
case 0x0c094510u: goto P_0c094510;
case 0x0c094512u: goto P_0c094512;
case 0x0c094514u: goto P_0c094514;
case 0x0c094516u: goto P_0c094516;
case 0x0c094518u: goto P_0c094518;
case 0x0c09451au: goto P_0c09451a;
case 0x0c09451cu: goto P_0c09451c;
case 0x0c09451eu: goto P_0c09451e;
case 0x0c094520u: goto P_0c094520;
case 0x0c094522u: goto P_0c094522;
case 0x0c094524u: goto P_0c094524;
case 0x0c094526u: goto P_0c094526;
case 0x0c094528u: goto P_0c094528;
case 0x0c0a7450u: goto P_0c0a7450;
case 0x0c0a7452u: goto P_0c0a7452;
case 0x0c0a7454u: goto P_0c0a7454;
case 0x0c0a7456u: goto P_0c0a7456;
case 0x0c0a7458u: goto P_0c0a7458;
case 0x0c0a745au: goto P_0c0a745a;
case 0x0c0a745cu: goto P_0c0a745c;
case 0x0c0a745eu: goto P_0c0a745e;
case 0x0c0a7460u: goto P_0c0a7460;
case 0x0c0a7462u: goto P_0c0a7462;
case 0x0c0a7464u: goto P_0c0a7464;
case 0x0c0a7466u: goto P_0c0a7466;
case 0x0c0a7468u: goto P_0c0a7468;
case 0x0c0a746au: goto P_0c0a746a;
case 0x0c0a746cu: goto P_0c0a746c;
case 0x0c0a746eu: goto P_0c0a746e;
case 0x0c0abb2au: goto P_0c0abb2a;
case 0x0c0abb2cu: goto P_0c0abb2c;
case 0x0c0abb2eu: goto P_0c0abb2e;
case 0x0c0abb30u: goto P_0c0abb30;
case 0x0c0abb32u: goto P_0c0abb32;
case 0x0c0abb34u: goto P_0c0abb34;
case 0x0c0abb36u: goto P_0c0abb36;
case 0x0c0abb38u: goto P_0c0abb38;
case 0x0c0abb3au: goto P_0c0abb3a;
case 0x0c0abb3cu: goto P_0c0abb3c;
case 0x0c0abb3eu: goto P_0c0abb3e;
case 0x0c0abb40u: goto P_0c0abb40;
case 0x0c0abb42u: goto P_0c0abb42;
case 0x0c0abb44u: goto P_0c0abb44;
case 0x0c0abb46u: goto P_0c0abb46;
case 0x0c0abb48u: goto P_0c0abb48;
case 0x0c0abb4au: goto P_0c0abb4a;
case 0x0c0abb4cu: goto P_0c0abb4c;
case 0x0c0abb4eu: goto P_0c0abb4e;
case 0x0c0abb50u: goto P_0c0abb50;
case 0x0c0abb52u: goto P_0c0abb52;
case 0x0c0abb54u: goto P_0c0abb54;
case 0x0c0abb56u: goto P_0c0abb56;
case 0x0c0abb58u: goto P_0c0abb58;
case 0x0c0abb5au: goto P_0c0abb5a;
case 0x0c0abb5cu: goto P_0c0abb5c;
case 0x0c0abb5eu: goto P_0c0abb5e;
case 0x0c0abb60u: goto P_0c0abb60;
case 0x0c0abb62u: goto P_0c0abb62;
case 0x0c0abb64u: goto P_0c0abb64;
case 0x0c0abb66u: goto P_0c0abb66;
case 0x0c0abb68u: goto P_0c0abb68;
case 0x0c0abb6au: goto P_0c0abb6a;
case 0x0c0abb6cu: goto P_0c0abb6c;
case 0x0c0abb6eu: goto P_0c0abb6e;
case 0x0c0abb70u: goto P_0c0abb70;
case 0x0c0abb72u: goto P_0c0abb72;
case 0x0c0abb74u: goto P_0c0abb74;
case 0x0c0abb76u: goto P_0c0abb76;
case 0x0c0abb78u: goto P_0c0abb78;
case 0x0c0abb7au: goto P_0c0abb7a;
case 0x0c0abb7cu: goto P_0c0abb7c;
case 0x0c0abb7eu: goto P_0c0abb7e;
case 0x0c0abb80u: goto P_0c0abb80;
case 0x0c0abb82u: goto P_0c0abb82;
case 0x0c0abb84u: goto P_0c0abb84;
case 0x0c0abb86u: goto P_0c0abb86;
case 0x0c0abb88u: goto P_0c0abb88;
case 0x0c0abb8au: goto P_0c0abb8a;
case 0x0c0abb8cu: goto P_0c0abb8c;
case 0x0c0abb8eu: goto P_0c0abb8e;
case 0x0c0abb90u: goto P_0c0abb90;
case 0x0c0abb92u: goto P_0c0abb92;
case 0x0c0abb94u: goto P_0c0abb94;
case 0x0c0abb96u: goto P_0c0abb96;
case 0x0c0abb98u: goto P_0c0abb98;
case 0x0c0abb9au: goto P_0c0abb9a;
case 0x0c0abb9cu: goto P_0c0abb9c;
case 0x0c0abb9eu: goto P_0c0abb9e;
case 0x0c0abba0u: goto P_0c0abba0;
case 0x0c0abba2u: goto P_0c0abba2;
case 0x0c0abba4u: goto P_0c0abba4;
case 0x0c0abba6u: goto P_0c0abba6;
case 0x0c0abba8u: goto P_0c0abba8;
case 0x0c0abbaau: goto P_0c0abbaa;
case 0x0c0abbacu: goto P_0c0abbac;
case 0x0c0abbaeu: goto P_0c0abbae;
case 0x0c0abbb0u: goto P_0c0abbb0;
case 0x0c0abbb2u: goto P_0c0abbb2;
case 0x0c0abbb4u: goto P_0c0abbb4;
case 0x0c0abbb6u: goto P_0c0abbb6;
case 0x0c0abbb8u: goto P_0c0abbb8;
case 0x0c0abcecu: goto P_0c0abcec;
case 0x0c0abceeu: goto P_0c0abcee;
case 0x0c0abcf0u: goto P_0c0abcf0;
case 0x0c0abcf2u: goto P_0c0abcf2;
case 0x0c0abcf4u: goto P_0c0abcf4;
case 0x0c0abcf6u: goto P_0c0abcf6;
case 0x0c0abcf8u: goto P_0c0abcf8;
case 0x0c0abcfau: goto P_0c0abcfa;
case 0x0c0abcfcu: goto P_0c0abcfc;
case 0x0c0abcfeu: goto P_0c0abcfe;
case 0x0c0abd00u: goto P_0c0abd00;
case 0x0c0abd02u: goto P_0c0abd02;
case 0x0c0abd04u: goto P_0c0abd04;
case 0x0c0abd06u: goto P_0c0abd06;
case 0x0c0abd08u: goto P_0c0abd08;
case 0x0c0c01b4u: goto P_0c0c01b4;
case 0x0c0c01b6u: goto P_0c0c01b6;
case 0x0c0c01b8u: goto P_0c0c01b8;
case 0x0c0c01bau: goto P_0c0c01ba;
case 0x0c0c01bcu: goto P_0c0c01bc;
case 0x0c0c01beu: goto P_0c0c01be;
case 0x0c0c01c0u: goto P_0c0c01c0;
case 0x0c0c01c2u: goto P_0c0c01c2;
case 0x0c0c01c4u: goto P_0c0c01c4;
case 0x0c0c01c6u: goto P_0c0c01c6;
case 0x0c0c01c8u: goto P_0c0c01c8;
case 0x0c0c01cau: goto P_0c0c01ca;
case 0x0c0c01ccu: goto P_0c0c01cc;
case 0x0c0c01ceu: goto P_0c0c01ce;
case 0x0c0c01d0u: goto P_0c0c01d0;
case 0x0c0c01d2u: goto P_0c0c01d2;
case 0x0c0c01d4u: goto P_0c0c01d4;
case 0x0c0c01d6u: goto P_0c0c01d6;
case 0x0c0c01d8u: goto P_0c0c01d8;
case 0x0c0c01dau: goto P_0c0c01da;
case 0x0c0c01dcu: goto P_0c0c01dc;
case 0x0c0c01deu: goto P_0c0c01de;
case 0x0c0c01e0u: goto P_0c0c01e0;
case 0x0c0c01e2u: goto P_0c0c01e2;
case 0x0c0c01e4u: goto P_0c0c01e4;
case 0x0c0c01e6u: goto P_0c0c01e6;
case 0x0c0c01e8u: goto P_0c0c01e8;
case 0x0c0c01eau: goto P_0c0c01ea;
case 0x0c0c01ecu: goto P_0c0c01ec;
case 0x0c0c01eeu: goto P_0c0c01ee;
case 0x0c0c01f0u: goto P_0c0c01f0;
case 0x0c0c01f2u: goto P_0c0c01f2;
case 0x0c0c01f4u: goto P_0c0c01f4;
case 0x0c0c01f6u: goto P_0c0c01f6;
case 0x0c0c01f8u: goto P_0c0c01f8;
case 0x0c0c01fau: goto P_0c0c01fa;
case 0x0c0c0208u: goto P_0c0c0208;
case 0x0c0c020au: goto P_0c0c020a;
case 0x0c0c020cu: goto P_0c0c020c;
case 0x0c0c020eu: goto P_0c0c020e;
case 0x0c0c0210u: goto P_0c0c0210;
case 0x0c0c0212u: goto P_0c0c0212;
case 0x0c0c0214u: goto P_0c0c0214;
case 0x0c0c0216u: goto P_0c0c0216;
case 0x0c0c0218u: goto P_0c0c0218;
case 0x0c0c021au: goto P_0c0c021a;
case 0x0c0c021cu: goto P_0c0c021c;
case 0x0c0c021eu: goto P_0c0c021e;
case 0x0c0c0220u: goto P_0c0c0220;
case 0x0c0c0222u: goto P_0c0c0222;
case 0x0c0c0224u: goto P_0c0c0224;
case 0x0c0c0226u: goto P_0c0c0226;
case 0x0c0c0228u: goto P_0c0c0228;
case 0x0c0c022au: goto P_0c0c022a;
case 0x0c0c022cu: goto P_0c0c022c;
case 0x0c0c022eu: goto P_0c0c022e;
case 0x0c0c0230u: goto P_0c0c0230;
case 0x0c0c0232u: goto P_0c0c0232;
case 0x0c0c0234u: goto P_0c0c0234;
case 0x0c0c0236u: goto P_0c0c0236;
case 0x0c0c0238u: goto P_0c0c0238;
case 0x0c0c023au: goto P_0c0c023a;
case 0x0c0c023cu: goto P_0c0c023c;
case 0x0c0c023eu: goto P_0c0c023e;
case 0x0c0c0240u: goto P_0c0c0240;
case 0x0c0c0242u: goto P_0c0c0242;
case 0x0c0c0244u: goto P_0c0c0244;
case 0x0c0c0246u: goto P_0c0c0246;
case 0x0c0c0248u: goto P_0c0c0248;
case 0x0c0c024au: goto P_0c0c024a;
case 0x0c0c024cu: goto P_0c0c024c;
case 0x0c0c024eu: goto P_0c0c024e;
case 0x0c0c0250u: goto P_0c0c0250;
case 0x0c0c0252u: goto P_0c0c0252;
case 0x0c0c0254u: goto P_0c0c0254;
case 0x0c0c0256u: goto P_0c0c0256;
case 0x0c0c0258u: goto P_0c0c0258;
case 0x0c0c025au: goto P_0c0c025a;
case 0x0c0c025cu: goto P_0c0c025c;
case 0x0c0c025eu: goto P_0c0c025e;
case 0x0c0c0260u: goto P_0c0c0260;
case 0x0c0c0262u: goto P_0c0c0262;
case 0x0c0c0264u: goto P_0c0c0264;
case 0x0c0c0266u: goto P_0c0c0266;
case 0x0c0c0268u: goto P_0c0c0268;
case 0x0c0c026au: goto P_0c0c026a;
case 0x0c0c026cu: goto P_0c0c026c;
case 0x0c0c026eu: goto P_0c0c026e;
case 0x0c0c0270u: goto P_0c0c0270;
case 0x0c0c0272u: goto P_0c0c0272;
case 0x0c0c0274u: goto P_0c0c0274;
case 0x0c0c0276u: goto P_0c0c0276;
case 0x0c0c0278u: goto P_0c0c0278;
case 0x0c0c027au: goto P_0c0c027a;
case 0x0c0c027cu: goto P_0c0c027c;
case 0x0c0c027eu: goto P_0c0c027e;
case 0x0c0c0280u: goto P_0c0c0280;
case 0x0c0c0282u: goto P_0c0c0282;
case 0x0c0c0284u: goto P_0c0c0284;
case 0x0c0c0286u: goto P_0c0c0286;
case 0x0c0c0288u: goto P_0c0c0288;
case 0x0c0c028au: goto P_0c0c028a;
case 0x0c0c028cu: goto P_0c0c028c;
case 0x0c0c028eu: goto P_0c0c028e;
case 0x0c0c0290u: goto P_0c0c0290;
case 0x0c0c0292u: goto P_0c0c0292;
case 0x0c0c0294u: goto P_0c0c0294;
case 0x0c0c0296u: goto P_0c0c0296;
case 0x0c0c0298u: goto P_0c0c0298;
case 0x0c0c029au: goto P_0c0c029a;
case 0x0c0c029cu: goto P_0c0c029c;
case 0x0c0c029eu: goto P_0c0c029e;
case 0x0c0c02a0u: goto P_0c0c02a0;
case 0x0c0c02a2u: goto P_0c0c02a2;
case 0x0c0c02a4u: goto P_0c0c02a4;
case 0x0c0c02a6u: goto P_0c0c02a6;
case 0x0c0c02a8u: goto P_0c0c02a8;
case 0x0c0c02aau: goto P_0c0c02aa;
case 0x0c0c02acu: goto P_0c0c02ac;
case 0x0c0c02aeu: goto P_0c0c02ae;
case 0x0c0c02b0u: goto P_0c0c02b0;
case 0x0c0c02b2u: goto P_0c0c02b2;
case 0x0c0c02b4u: goto P_0c0c02b4;
case 0x0c0c02b6u: goto P_0c0c02b6;
case 0x0c0c02b8u: goto P_0c0c02b8;
case 0x0c0c02bau: goto P_0c0c02ba;
case 0x0c0c02bcu: goto P_0c0c02bc;
case 0x0c0c02beu: goto P_0c0c02be;
case 0x0c0c02c0u: goto P_0c0c02c0;
case 0x0c0c02c2u: goto P_0c0c02c2;
case 0x0c0c02c4u: goto P_0c0c02c4;
case 0x0c0c02c6u: goto P_0c0c02c6;
case 0x0c0c02c8u: goto P_0c0c02c8;
case 0x0c0c02cau: goto P_0c0c02ca;
case 0x0c0c02ccu: goto P_0c0c02cc;
case 0x0c0c02ceu: goto P_0c0c02ce;
case 0x0c0c02d0u: goto P_0c0c02d0;
case 0x0c0c02d2u: goto P_0c0c02d2;
case 0x0c0c02d4u: goto P_0c0c02d4;
case 0x0c0c02d6u: goto P_0c0c02d6;
case 0x0c0c02d8u: goto P_0c0c02d8;
case 0x0c0c02dau: goto P_0c0c02da;
case 0x0c0c02dcu: goto P_0c0c02dc;
case 0x0c0c02deu: goto P_0c0c02de;
case 0x0c0c02e0u: goto P_0c0c02e0;
case 0x0c0c02e2u: goto P_0c0c02e2;
case 0x0c0c02e4u: goto P_0c0c02e4;
case 0x0c0c02e6u: goto P_0c0c02e6;
case 0x0c0c02e8u: goto P_0c0c02e8;
case 0x0c0c02eau: goto P_0c0c02ea;
case 0x0c0c02ecu: goto P_0c0c02ec;
case 0x0c0c02eeu: goto P_0c0c02ee;
case 0x0c0c02f0u: goto P_0c0c02f0;
case 0x0c0c02f2u: goto P_0c0c02f2;
case 0x0c0c02f4u: goto P_0c0c02f4;
case 0x0c0c02f6u: goto P_0c0c02f6;
case 0x0c0c02f8u: goto P_0c0c02f8;
case 0x0c0c02fau: goto P_0c0c02fa;
case 0x0c0c02fcu: goto P_0c0c02fc;
case 0x0c0c02feu: goto P_0c0c02fe;
case 0x0c0c0300u: goto P_0c0c0300;
case 0x0c0c0302u: goto P_0c0c0302;
case 0x0c0c0304u: goto P_0c0c0304;
case 0x0c0c0306u: goto P_0c0c0306;
case 0x0c0c0308u: goto P_0c0c0308;
case 0x0c0c030au: goto P_0c0c030a;
case 0x0c0c030cu: goto P_0c0c030c;
case 0x0c0c030eu: goto P_0c0c030e;
case 0x0c0c0310u: goto P_0c0c0310;
case 0x0c0c0312u: goto P_0c0c0312;
case 0x0c0c0314u: goto P_0c0c0314;
case 0x0c0c0316u: goto P_0c0c0316;
case 0x0c0c0318u: goto P_0c0c0318;
case 0x0c0c031au: goto P_0c0c031a;
case 0x0c0c031cu: goto P_0c0c031c;
case 0x0c0c031eu: goto P_0c0c031e;
case 0x0c0c0320u: goto P_0c0c0320;
case 0x0c0c0322u: goto P_0c0c0322;
case 0x0c0c0324u: goto P_0c0c0324;
case 0x0c0c0326u: goto P_0c0c0326;
case 0x0c0c0328u: goto P_0c0c0328;
case 0x0c0c032au: goto P_0c0c032a;
case 0x0c0c032cu: goto P_0c0c032c;
case 0x0c0c032eu: goto P_0c0c032e;
case 0x0c0c0330u: goto P_0c0c0330;
case 0x0c0c0332u: goto P_0c0c0332;
case 0x0c0c0334u: goto P_0c0c0334;
case 0x0c0c0336u: goto P_0c0c0336;
case 0x0c0c0338u: goto P_0c0c0338;
case 0x0c0c033au: goto P_0c0c033a;
case 0x0c0c033cu: goto P_0c0c033c;
case 0x0c0c033eu: goto P_0c0c033e;
case 0x0c0c0340u: goto P_0c0c0340;
case 0x0c0c0342u: goto P_0c0c0342;
case 0x0c0c0344u: goto P_0c0c0344;
case 0x0c0c0346u: goto P_0c0c0346;
case 0x0c0c0348u: goto P_0c0c0348;
case 0x0c0c034au: goto P_0c0c034a;
case 0x0c0c034cu: goto P_0c0c034c;
case 0x0c0c034eu: goto P_0c0c034e;
case 0x0c0c0350u: goto P_0c0c0350;
case 0x0c0c0352u: goto P_0c0c0352;
case 0x0c0c0354u: goto P_0c0c0354;
case 0x0c0c0356u: goto P_0c0c0356;
case 0x0c0c0358u: goto P_0c0c0358;
case 0x0c0c035au: goto P_0c0c035a;
case 0x0c0c035cu: goto P_0c0c035c;
case 0x0c0c035eu: goto P_0c0c035e;
case 0x0c0c0360u: goto P_0c0c0360;
case 0x0c0c0362u: goto P_0c0c0362;
case 0x0c0c0364u: goto P_0c0c0364;
case 0x0c0c0366u: goto P_0c0c0366;
case 0x0c0c0368u: goto P_0c0c0368;
case 0x0c0c036au: goto P_0c0c036a;
case 0x0c0c036cu: goto P_0c0c036c;
case 0x0c0c036eu: goto P_0c0c036e;
case 0x0c0c0370u: goto P_0c0c0370;
case 0x0c0c0372u: goto P_0c0c0372;
case 0x0c0c0374u: goto P_0c0c0374;
case 0x0c0c0376u: goto P_0c0c0376;
case 0x0c0c0378u: goto P_0c0c0378;
case 0x0c0c037au: goto P_0c0c037a;
case 0x0c0c037cu: goto P_0c0c037c;
case 0x0c0c037eu: goto P_0c0c037e;
case 0x0c0c0380u: goto P_0c0c0380;
case 0x0c0c0382u: goto P_0c0c0382;
case 0x0c0c0384u: goto P_0c0c0384;
case 0x0c0c0386u: goto P_0c0c0386;
case 0x0c0c0388u: goto P_0c0c0388;
case 0x0c0c038au: goto P_0c0c038a;
case 0x0c0c03c4u: goto P_0c0c03c4;
case 0x0c0c03c6u: goto P_0c0c03c6;
case 0x0c0c03c8u: goto P_0c0c03c8;
case 0x0c0c03cau: goto P_0c0c03ca;
case 0x0c0c03ccu: goto P_0c0c03cc;
case 0x0c0c03ceu: goto P_0c0c03ce;
case 0x0c0c03d0u: goto P_0c0c03d0;
case 0x0c0c03d2u: goto P_0c0c03d2;
case 0x0c0c03d4u: goto P_0c0c03d4;
case 0x0c0c03d6u: goto P_0c0c03d6;
case 0x0c0c03d8u: goto P_0c0c03d8;
case 0x0c0c03dau: goto P_0c0c03da;
case 0x0c0c03dcu: goto P_0c0c03dc;
case 0x0c0c03deu: goto P_0c0c03de;
case 0x0c0c03e0u: goto P_0c0c03e0;
case 0x0c0c03e2u: goto P_0c0c03e2;
case 0x0c0c03e4u: goto P_0c0c03e4;
case 0x0c0c03e6u: goto P_0c0c03e6;
case 0x0c0c03e8u: goto P_0c0c03e8;
case 0x0c0c03eau: goto P_0c0c03ea;
case 0x0c0c03ecu: goto P_0c0c03ec;
case 0x0c0c03eeu: goto P_0c0c03ee;
case 0x0c0c03f0u: goto P_0c0c03f0;
case 0x0c0c03f2u: goto P_0c0c03f2;
case 0x0c0c03f4u: goto P_0c0c03f4;
case 0x0c0c03f6u: goto P_0c0c03f6;
case 0x0c0c03f8u: goto P_0c0c03f8;
case 0x0c0c03fau: goto P_0c0c03fa;
case 0x0c0c03fcu: goto P_0c0c03fc;
case 0x0c0c03feu: goto P_0c0c03fe;
case 0x0c0c0400u: goto P_0c0c0400;
case 0x0c0c0402u: goto P_0c0c0402;
case 0x0c0c0404u: goto P_0c0c0404;
case 0x0c0c0406u: goto P_0c0c0406;
case 0x0c0c0408u: goto P_0c0c0408;
case 0x0c0c040au: goto P_0c0c040a;
case 0x0c0c040cu: goto P_0c0c040c;
case 0x0c0c040eu: goto P_0c0c040e;
case 0x0c0c0410u: goto P_0c0c0410;
case 0x0c0c0412u: goto P_0c0c0412;
case 0x0c0c0414u: goto P_0c0c0414;
case 0x0c0c0416u: goto P_0c0c0416;
case 0x0c0c0418u: goto P_0c0c0418;
case 0x0c0c041au: goto P_0c0c041a;
case 0x0c0c041cu: goto P_0c0c041c;
case 0x0c0c041eu: goto P_0c0c041e;
case 0x0c0c0420u: goto P_0c0c0420;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b736: /* original 4f22, guest PC 0x0c07b736 */
if(!s->budget--) { s->failed_pc=0x0c07b736u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b738;
P_0c07b738: /* original 2642, guest PC 0x0c07b738 */
if(!s->budget--) { s->failed_pc=0x0c07b738u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c07b73a;
P_0c07b73a: /* original d445, guest PC 0x0c07b73a */
if(!s->budget--) { s->failed_pc=0x0c07b73au; return 0; }
r[4]=read(ram,0x0c07b850u,4);
goto P_0c07b73c;
P_0c07b73c: /* original 2452, guest PC 0x0c07b73c */
if(!s->budget--) { s->failed_pc=0x0c07b73cu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c07b73e;
P_0c07b73e: /* original 917f, guest PC 0x0c07b73e */
if(!s->budget--) { s->failed_pc=0x0c07b73eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b840u,2);
goto P_0c07b740;
P_0c07b740: /* original d344, guest PC 0x0c07b740 */
if(!s->budget--) { s->failed_pc=0x0c07b740u; return 0; }
r[3]=read(ram,0x0c07b854u,4);
goto P_0c07b742;
P_0c07b742: /* original 430b, guest PC 0x0c07b742 */
if(!s->budget--) { s->failed_pc=0x0c07b742u; return 0; }
target=r[3];
r[16]=0x0c07b746u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b746u) { target=s->pc; goto dispatch; }
goto P_0c07b746;
P_0c07b744: /* original 6053, guest PC 0x0c07b744 */
if(!s->budget--) { s->failed_pc=0x0c07b744u; return 0; }
r[0]=r[5];
goto P_0c07b746;
P_0c07b746: /* original d244, guest PC 0x0c07b746 */
if(!s->budget--) { s->failed_pc=0x0c07b746u; return 0; }
r[2]=read(ram,0x0c07b858u,4);
goto P_0c07b748;
P_0c07b748: /* original 2202, guest PC 0x0c07b748 */
if(!s->budget--) { s->failed_pc=0x0c07b748u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07b74a;
P_0c07b74a: /* original 917a, guest PC 0x0c07b74a */
if(!s->budget--) { s->failed_pc=0x0c07b74au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b842u,2);
goto P_0c07b74c;
P_0c07b74c: /* original d341, guest PC 0x0c07b74c */
if(!s->budget--) { s->failed_pc=0x0c07b74cu; return 0; }
r[3]=read(ram,0x0c07b854u,4);
goto P_0c07b74e;
P_0c07b74e: /* original 430b, guest PC 0x0c07b74e */
if(!s->budget--) { s->failed_pc=0x0c07b74eu; return 0; }
target=r[3];
r[16]=0x0c07b752u;
tmp=read(ram,r[6],4);
r[0]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b752u) { target=s->pc; goto dispatch; }
goto P_0c07b752;
P_0c07b750: /* original 6062, guest PC 0x0c07b750 */
if(!s->budget--) { s->failed_pc=0x0c07b750u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c07b752;
P_0c07b752: /* original 4f26, guest PC 0x0c07b752 */
if(!s->budget--) { s->failed_pc=0x0c07b752u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b754;
P_0c07b754: /* original d241, guest PC 0x0c07b754 */
if(!s->budget--) { s->failed_pc=0x0c07b754u; return 0; }
r[2]=read(ram,0x0c07b85cu,4);
goto P_0c07b756;
P_0c07b756: /* original 000b, guest PC 0x0c07b756 */
if(!s->budget--) { s->failed_pc=0x0c07b756u; return 0; }
target=r[16];
write(ram,r[2],r[0],4);
s->pc=target; return ram->oob==0;
P_0c07b758: /* original 2202, guest PC 0x0c07b758 */
if(!s->budget--) { s->failed_pc=0x0c07b758u; return 0; }
write(ram,r[2],r[0],4);
return vf3_matrix_family(0x0c07b75au,s,ram);
P_0c07b98a: /* original 4f22, guest PC 0x0c07b98a */
if(!s->budget--) { s->failed_pc=0x0c07b98au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b98c;
P_0c07b98c: /* original d31f, guest PC 0x0c07b98c */
if(!s->budget--) { s->failed_pc=0x0c07b98cu; return 0; }
r[3]=read(ram,0x0c07ba0cu,4);
goto P_0c07b98e;
P_0c07b98e: /* original 430b, guest PC 0x0c07b98e */
if(!s->budget--) { s->failed_pc=0x0c07b98eu; return 0; }
target=r[3];
r[16]=0x0c07b992u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b992u) { target=s->pc; goto dispatch; }
goto P_0c07b992;
P_0c07b990: /* original 6e43, guest PC 0x0c07b990 */
if(!s->budget--) { s->failed_pc=0x0c07b990u; return 0; }
r[14]=r[4];
goto P_0c07b992;
P_0c07b992: /* original 4f26, guest PC 0x0c07b992 */
if(!s->budget--) { s->failed_pc=0x0c07b992u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b994;
P_0c07b994: /* original d21e, guest PC 0x0c07b994 */
if(!s->budget--) { s->failed_pc=0x0c07b994u; return 0; }
r[2]=read(ram,0x0c07ba10u,4);
goto P_0c07b996;
P_0c07b996: /* original 1e23, guest PC 0x0c07b996 */
if(!s->budget--) { s->failed_pc=0x0c07b996u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c07b998;
P_0c07b998: /* original d31e, guest PC 0x0c07b998 */
if(!s->budget--) { s->failed_pc=0x0c07b998u; return 0; }
r[3]=read(ram,0x0c07ba14u,4);
goto P_0c07b99a;
P_0c07b99a: /* original 1e34, guest PC 0x0c07b99a */
if(!s->budget--) { s->failed_pc=0x0c07b99au; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c07b99c;
P_0c07b99c: /* original 000b, guest PC 0x0c07b99c */
if(!s->budget--) { s->failed_pc=0x0c07b99cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b99e: /* original 6ef6, guest PC 0x0c07b99e */
if(!s->budget--) { s->failed_pc=0x0c07b99eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b9a0u,s,ram);
P_0c0805f8: /* original 4f22, guest PC 0x0c0805f8 */
if(!s->budget--) { s->failed_pc=0x0c0805f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0805fa;
P_0c0805fa: /* original 9517, guest PC 0x0c0805fa */
if(!s->budget--) { s->failed_pc=0x0c0805fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08062cu,2);
goto P_0c0805fc;
P_0c0805fc: /* original e320, guest PC 0x0c0805fc */
if(!s->budget--) { s->failed_pc=0x0c0805fcu; return 0; }
r[3]=0x00000020u;
goto P_0c0805fe;
P_0c0805fe: /* original e728, guest PC 0x0c0805fe */
if(!s->budget--) { s->failed_pc=0x0c0805feu; return 0; }
r[7]=0x00000028u;
goto P_0c080600;
P_0c080600: /* original 2f36, guest PC 0x0c080600 */
if(!s->budget--) { s->failed_pc=0x0c080600u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c080602;
P_0c080602: /* original d218, guest PC 0x0c080602 */
if(!s->budget--) { s->failed_pc=0x0c080602u; return 0; }
r[2]=read(ram,0x0c080664u,4);
goto P_0c080604;
P_0c080604: /* original d40a, guest PC 0x0c080604 */
if(!s->budget--) { s->failed_pc=0x0c080604u; return 0; }
r[4]=read(ram,0x0c080630u,4);
goto P_0c080606;
P_0c080606: /* original 420b, guest PC 0x0c080606 */
if(!s->budget--) { s->failed_pc=0x0c080606u; return 0; }
target=r[2];
r[16]=0x0c08060au;
r[6]=0x00000026u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08060au) { target=s->pc; goto dispatch; }
goto P_0c08060a;
P_0c080608: /* original e626, guest PC 0x0c080608 */
if(!s->budget--) { s->failed_pc=0x0c080608u; return 0; }
r[6]=0x00000026u;
goto P_0c08060a;
P_0c08060a: /* original 7f04, guest PC 0x0c08060a */
if(!s->budget--) { s->failed_pc=0x0c08060au; return 0; }
r[15]+=0x00000004u;
goto P_0c08060c;
P_0c08060c: /* original 4f26, guest PC 0x0c08060c */
if(!s->budget--) { s->failed_pc=0x0c08060cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08060e;
P_0c08060e: /* original 000b, guest PC 0x0c08060e */
if(!s->budget--) { s->failed_pc=0x0c08060eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c080610: /* original 0009, guest PC 0x0c080610 */
if(!s->budget--) { s->failed_pc=0x0c080610u; return 0; }
return vf3_matrix_family(0x0c080612u,s,ram);
P_0c0807f0: /* original 4f22, guest PC 0x0c0807f0 */
if(!s->budget--) { s->failed_pc=0x0c0807f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0807f2;
P_0c0807f2: /* original e300, guest PC 0x0c0807f2 */
if(!s->budget--) { s->failed_pc=0x0c0807f2u; return 0; }
r[3]=0x00000000u;
goto P_0c0807f4;
P_0c0807f4: /* original d40d, guest PC 0x0c0807f4 */
if(!s->budget--) { s->failed_pc=0x0c0807f4u; return 0; }
r[4]=read(ram,0x0c08082cu,4);
goto P_0c0807f6;
P_0c0807f6: /* original e63e, guest PC 0x0c0807f6 */
if(!s->budget--) { s->failed_pc=0x0c0807f6u; return 0; }
r[6]=0x0000003eu;
goto P_0c0807f8;
P_0c0807f8: /* original 2f36, guest PC 0x0c0807f8 */
if(!s->budget--) { s->failed_pc=0x0c0807f8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0807fa;
P_0c0807fa: /* original e730, guest PC 0x0c0807fa */
if(!s->budget--) { s->failed_pc=0x0c0807fau; return 0; }
r[7]=0x00000030u;
goto P_0c0807fc;
P_0c0807fc: /* original d20d, guest PC 0x0c0807fc */
if(!s->budget--) { s->failed_pc=0x0c0807fcu; return 0; }
r[2]=read(ram,0x0c080834u,4);
goto P_0c0807fe;
P_0c0807fe: /* original 420b, guest PC 0x0c0807fe */
if(!s->budget--) { s->failed_pc=0x0c0807feu; return 0; }
target=r[2];
r[16]=0x0c080802u;
r[5]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080802u) { target=s->pc; goto dispatch; }
goto P_0c080802;
P_0c080800: /* original 6533, guest PC 0x0c080800 */
if(!s->budget--) { s->failed_pc=0x0c080800u; return 0; }
r[5]=r[3];
goto P_0c080802;
P_0c080802: /* original 7f04, guest PC 0x0c080802 */
if(!s->budget--) { s->failed_pc=0x0c080802u; return 0; }
r[15]+=0x00000004u;
goto P_0c080804;
P_0c080804: /* original 4f26, guest PC 0x0c080804 */
if(!s->budget--) { s->failed_pc=0x0c080804u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080806;
P_0c080806: /* original 000b, guest PC 0x0c080806 */
if(!s->budget--) { s->failed_pc=0x0c080806u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c080808: /* original 0009, guest PC 0x0c080808 */
if(!s->budget--) { s->failed_pc=0x0c080808u; return 0; }
goto P_0c08080a;
P_0c08080a: /* original 4f22, guest PC 0x0c08080a */
if(!s->budget--) { s->failed_pc=0x0c08080au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08080c;
P_0c08080c: /* original d607, guest PC 0x0c08080c */
if(!s->budget--) { s->failed_pc=0x0c08080cu; return 0; }
r[6]=read(ram,0x0c08082cu,4);
goto P_0c08080e;
P_0c08080e: /* original e300, guest PC 0x0c08080e */
if(!s->budget--) { s->failed_pc=0x0c08080eu; return 0; }
r[3]=0x00000000u;
goto P_0c080810;
P_0c080810: /* original 2f36, guest PC 0x0c080810 */
if(!s->budget--) { s->failed_pc=0x0c080810u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c080812;
P_0c080812: /* original 9509, guest PC 0x0c080812 */
if(!s->budget--) { s->failed_pc=0x0c080812u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080828u,2);
goto P_0c080814;
P_0c080814: /* original 9409, guest PC 0x0c080814 */
if(!s->budget--) { s->failed_pc=0x0c080814u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08082au,2);
goto P_0c080816;
P_0c080816: /* original d206, guest PC 0x0c080816 */
if(!s->budget--) { s->failed_pc=0x0c080816u; return 0; }
r[2]=read(ram,0x0c080830u,4);
goto P_0c080818;
P_0c080818: /* original 420b, guest PC 0x0c080818 */
if(!s->budget--) { s->failed_pc=0x0c080818u; return 0; }
target=r[2];
r[16]=0x0c08081cu;
r[7]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08081cu) { target=s->pc; goto dispatch; }
goto P_0c08081c;
P_0c08081a: /* original 6733, guest PC 0x0c08081a */
if(!s->budget--) { s->failed_pc=0x0c08081au; return 0; }
r[7]=r[3];
goto P_0c08081c;
P_0c08081c: /* original 7f04, guest PC 0x0c08081c */
if(!s->budget--) { s->failed_pc=0x0c08081cu; return 0; }
r[15]+=0x00000004u;
goto P_0c08081e;
P_0c08081e: /* original 4f26, guest PC 0x0c08081e */
if(!s->budget--) { s->failed_pc=0x0c08081eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080820;
P_0c080820: /* original 000b, guest PC 0x0c080820 */
if(!s->budget--) { s->failed_pc=0x0c080820u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c080822: /* original 0009, guest PC 0x0c080822 */
if(!s->budget--) { s->failed_pc=0x0c080822u; return 0; }
return vf3_matrix_family(0x0c080824u,s,ram);
P_0c081098: /* original 4f22, guest PC 0x0c081098 */
if(!s->budget--) { s->failed_pc=0x0c081098u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08109a;
P_0c08109a: /* original 6742, guest PC 0x0c08109a */
if(!s->budget--) { s->failed_pc=0x0c08109au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c08109c;
P_0c08109c: /* original d330, guest PC 0x0c08109c */
if(!s->budget--) { s->failed_pc=0x0c08109cu; return 0; }
r[3]=read(ram,0x0c081160u,4);
goto P_0c08109e;
P_0c08109e: /* original 4f12, guest PC 0x0c08109e */
if(!s->budget--) { s->failed_pc=0x0c08109eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0810a0;
P_0c0810a0: /* original 6173, guest PC 0x0c0810a0 */
if(!s->budget--) { s->failed_pc=0x0c0810a0u; return 0; }
r[1]=r[7];
goto P_0c0810a2;
P_0c0810a2: /* original 430b, guest PC 0x0c0810a2 */
if(!s->budget--) { s->failed_pc=0x0c0810a2u; return 0; }
target=r[3];
r[16]=0x0c0810a6u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0810a6u) { target=s->pc; goto dispatch; }
goto P_0c0810a6;
P_0c0810a4: /* original 6053, guest PC 0x0c0810a4 */
if(!s->budget--) { s->failed_pc=0x0c0810a4u; return 0; }
r[0]=r[5];
goto P_0c0810a6;
P_0c0810a6: /* original 6603, guest PC 0x0c0810a6 */
if(!s->budget--) { s->failed_pc=0x0c0810a6u; return 0; }
r[6]=r[0];
goto P_0c0810a8;
P_0c0810a8: /* original 6273, guest PC 0x0c0810a8 */
if(!s->budget--) { s->failed_pc=0x0c0810a8u; return 0; }
r[2]=r[7];
goto P_0c0810aa;
P_0c0810aa: /* original 0567, guest PC 0x0c0810aa */
if(!s->budget--) { s->failed_pc=0x0c0810aau; return 0; }
r[19]=r[5]*r[6];
goto P_0c0810ac;
P_0c0810ac: /* original 2462, guest PC 0x0c0810ac */
if(!s->budget--) { s->failed_pc=0x0c0810acu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0810ae;
P_0c0810ae: /* original 051a, guest PC 0x0c0810ae */
if(!s->budget--) { s->failed_pc=0x0c0810aeu; return 0; }
r[5]=r[19];
goto P_0c0810b0;
P_0c0810b0: /* original 4f16, guest PC 0x0c0810b0 */
if(!s->budget--) { s->failed_pc=0x0c0810b0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b2;
P_0c0810b2: /* original 3258, guest PC 0x0c0810b2 */
if(!s->budget--) { s->failed_pc=0x0c0810b2u; return 0; }
r[2]-=r[5];
goto P_0c0810b4;
P_0c0810b4: /* original 4f26, guest PC 0x0c0810b4 */
if(!s->budget--) { s->failed_pc=0x0c0810b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b6;
P_0c0810b6: /* original 6023, guest PC 0x0c0810b6 */
if(!s->budget--) { s->failed_pc=0x0c0810b6u; return 0; }
r[0]=r[2];
goto P_0c0810b8;
P_0c0810b8: /* original 000b, guest PC 0x0c0810b8 */
if(!s->budget--) { s->failed_pc=0x0c0810b8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0810ba: /* original 0009, guest PC 0x0c0810ba */
if(!s->budget--) { s->failed_pc=0x0c0810bau; return 0; }
return vf3_matrix_family(0x0c0810bcu,s,ram);
P_0c081ce8: /* original 4f22, guest PC 0x0c081ce8 */
if(!s->budget--) { s->failed_pc=0x0c081ce8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081cea;
P_0c081cea: /* original e200, guest PC 0x0c081cea */
if(!s->budget--) { s->failed_pc=0x0c081ceau; return 0; }
r[2]=0x00000000u;
goto P_0c081cec;
P_0c081cec: /* original 4400, guest PC 0x0c081cec */
if(!s->budget--) { s->failed_pc=0x0c081cecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c081cee;
P_0c081cee: /* original 6723, guest PC 0x0c081cee */
if(!s->budget--) { s->failed_pc=0x0c081ceeu; return 0; }
r[7]=r[2];
goto P_0c081cf0;
P_0c081cf0: /* original 7ff8, guest PC 0x0c081cf0 */
if(!s->budget--) { s->failed_pc=0x0c081cf0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c081cf2;
P_0c081cf2: /* original 2f62, guest PC 0x0c081cf2 */
if(!s->budget--) { s->failed_pc=0x0c081cf2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c081cf4;
P_0c081cf4: /* original d309, guest PC 0x0c081cf4 */
if(!s->budget--) { s->failed_pc=0x0c081cf4u; return 0; }
r[3]=read(ram,0x0c081d1cu,4);
goto P_0c081cf6;
P_0c081cf6: /* original 1f31, guest PC 0x0c081cf6 */
if(!s->budget--) { s->failed_pc=0x0c081cf6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c081cf8;
P_0c081cf8: /* original e307, guest PC 0x0c081cf8 */
if(!s->budget--) { s->failed_pc=0x0c081cf8u; return 0; }
r[3]=0x00000007u;
goto P_0c081cfa;
P_0c081cfa: /* original 2f26, guest PC 0x0c081cfa */
if(!s->budget--) { s->failed_pc=0x0c081cfau; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c081cfc;
P_0c081cfc: /* original 453c, guest PC 0x0c081cfc */
if(!s->budget--) { s->failed_pc=0x0c081cfcu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c081cfe;
P_0c081cfe: /* original 56f2, guest PC 0x0c081cfe */
if(!s->budget--) { s->failed_pc=0x0c081cfeu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c081d00;
P_0c081d00: /* original 245b, guest PC 0x0c081d00 */
if(!s->budget--) { s->failed_pc=0x0c081d00u; return 0; }
r[4]|=r[5];
goto P_0c081d02;
P_0c081d02: /* original d107, guest PC 0x0c081d02 */
if(!s->budget--) { s->failed_pc=0x0c081d02u; return 0; }
r[1]=read(ram,0x0c081d20u,4);
goto P_0c081d04;
P_0c081d04: /* original 410b, guest PC 0x0c081d04 */
if(!s->budget--) { s->failed_pc=0x0c081d04u; return 0; }
target=r[1];
r[16]=0x0c081d08u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081d08u) { target=s->pc; goto dispatch; }
goto P_0c081d08;
P_0c081d06: /* original 55f1, guest PC 0x0c081d06 */
if(!s->budget--) { s->failed_pc=0x0c081d06u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c081d08;
P_0c081d08: /* original 7f0c, guest PC 0x0c081d08 */
if(!s->budget--) { s->failed_pc=0x0c081d08u; return 0; }
r[15]+=0x0000000cu;
goto P_0c081d0a;
P_0c081d0a: /* original 4f26, guest PC 0x0c081d0a */
if(!s->budget--) { s->failed_pc=0x0c081d0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081d0c;
P_0c081d0c: /* original 000b, guest PC 0x0c081d0c */
if(!s->budget--) { s->failed_pc=0x0c081d0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c081d0e: /* original 0009, guest PC 0x0c081d0e */
if(!s->budget--) { s->failed_pc=0x0c081d0eu; return 0; }
return vf3_matrix_family(0x0c081d10u,s,ram);
P_0c08763c: /* original 4f22, guest PC 0x0c08763c */
if(!s->budget--) { s->failed_pc=0x0c08763cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08763e;
P_0c08763e: /* original d352, guest PC 0x0c08763e */
if(!s->budget--) { s->failed_pc=0x0c08763eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c087640;
P_0c087640: /* original 7fc0, guest PC 0x0c087640 */
if(!s->budget--) { s->failed_pc=0x0c087640u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c087642;
P_0c087642: /* original 430b, guest PC 0x0c087642 */
if(!s->budget--) { s->failed_pc=0x0c087642u; return 0; }
target=r[3];
r[16]=0x0c087646u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087646u) { target=s->pc; goto dispatch; }
goto P_0c087646;
P_0c087644: /* original 64f3, guest PC 0x0c087644 */
if(!s->budget--) { s->failed_pc=0x0c087644u; return 0; }
r[4]=r[15];
goto P_0c087646;
P_0c087646: /* original f3e8, guest PC 0x0c087646 */
if(!s->budget--) { s->failed_pc=0x0c087646u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c087648;
P_0c087648: /* original e004, guest PC 0x0c087648 */
if(!s->budget--) { s->failed_pc=0x0c087648u; return 0; }
r[0]=0x00000004u;
goto P_0c08764a;
P_0c08764a: /* original ff3a, guest PC 0x0c08764a */
if(!s->budget--) { s->failed_pc=0x0c08764au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08764c;
P_0c08764c: /* original f3e6, guest PC 0x0c08764c */
if(!s->budget--) { s->failed_pc=0x0c08764cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08764e;
P_0c08764e: /* original e004, guest PC 0x0c08764e */
if(!s->budget--) { s->failed_pc=0x0c08764eu; return 0; }
r[0]=0x00000004u;
goto P_0c087650;
P_0c087650: /* original ff37, guest PC 0x0c087650 */
if(!s->budget--) { s->failed_pc=0x0c087650u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087652;
P_0c087652: /* original e008, guest PC 0x0c087652 */
if(!s->budget--) { s->failed_pc=0x0c087652u; return 0; }
r[0]=0x00000008u;
goto P_0c087654;
P_0c087654: /* original f3e6, guest PC 0x0c087654 */
if(!s->budget--) { s->failed_pc=0x0c087654u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087656;
P_0c087656: /* original e008, guest PC 0x0c087656 */
if(!s->budget--) { s->failed_pc=0x0c087656u; return 0; }
r[0]=0x00000008u;
goto P_0c087658;
P_0c087658: /* original ff37, guest PC 0x0c087658 */
if(!s->budget--) { s->failed_pc=0x0c087658u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08765a;
P_0c08765a: /* original e010, guest PC 0x0c08765a */
if(!s->budget--) { s->failed_pc=0x0c08765au; return 0; }
r[0]=0x00000010u;
goto P_0c08765c;
P_0c08765c: /* original f3e6, guest PC 0x0c08765c */
if(!s->budget--) { s->failed_pc=0x0c08765cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08765e;
P_0c08765e: /* original e010, guest PC 0x0c08765e */
if(!s->budget--) { s->failed_pc=0x0c08765eu; return 0; }
r[0]=0x00000010u;
goto P_0c087660;
P_0c087660: /* original ff37, guest PC 0x0c087660 */
if(!s->budget--) { s->failed_pc=0x0c087660u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087662;
P_0c087662: /* original e014, guest PC 0x0c087662 */
if(!s->budget--) { s->failed_pc=0x0c087662u; return 0; }
r[0]=0x00000014u;
goto P_0c087664;
P_0c087664: /* original f3e6, guest PC 0x0c087664 */
if(!s->budget--) { s->failed_pc=0x0c087664u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087666;
P_0c087666: /* original e014, guest PC 0x0c087666 */
if(!s->budget--) { s->failed_pc=0x0c087666u; return 0; }
r[0]=0x00000014u;
goto P_0c087668;
P_0c087668: /* original ff37, guest PC 0x0c087668 */
if(!s->budget--) { s->failed_pc=0x0c087668u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08766a;
P_0c08766a: /* original e018, guest PC 0x0c08766a */
if(!s->budget--) { s->failed_pc=0x0c08766au; return 0; }
r[0]=0x00000018u;
goto P_0c08766c;
P_0c08766c: /* original f3e6, guest PC 0x0c08766c */
if(!s->budget--) { s->failed_pc=0x0c08766cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08766e;
P_0c08766e: /* original e018, guest PC 0x0c08766e */
if(!s->budget--) { s->failed_pc=0x0c08766eu; return 0; }
r[0]=0x00000018u;
goto P_0c087670;
P_0c087670: /* original ff37, guest PC 0x0c087670 */
if(!s->budget--) { s->failed_pc=0x0c087670u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087672;
P_0c087672: /* original e020, guest PC 0x0c087672 */
if(!s->budget--) { s->failed_pc=0x0c087672u; return 0; }
r[0]=0x00000020u;
goto P_0c087674;
P_0c087674: /* original f3e6, guest PC 0x0c087674 */
if(!s->budget--) { s->failed_pc=0x0c087674u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087676;
P_0c087676: /* original e020, guest PC 0x0c087676 */
if(!s->budget--) { s->failed_pc=0x0c087676u; return 0; }
r[0]=0x00000020u;
goto P_0c087678;
P_0c087678: /* original ff37, guest PC 0x0c087678 */
if(!s->budget--) { s->failed_pc=0x0c087678u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08767a;
P_0c08767a: /* original e024, guest PC 0x0c08767a */
if(!s->budget--) { s->failed_pc=0x0c08767au; return 0; }
r[0]=0x00000024u;
goto P_0c08767c;
P_0c08767c: /* original f3e6, guest PC 0x0c08767c */
if(!s->budget--) { s->failed_pc=0x0c08767cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08767e;
P_0c08767e: /* original e024, guest PC 0x0c08767e */
if(!s->budget--) { s->failed_pc=0x0c08767eu; return 0; }
r[0]=0x00000024u;
goto P_0c087680;
P_0c087680: /* original ff37, guest PC 0x0c087680 */
if(!s->budget--) { s->failed_pc=0x0c087680u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087682;
P_0c087682: /* original e028, guest PC 0x0c087682 */
if(!s->budget--) { s->failed_pc=0x0c087682u; return 0; }
r[0]=0x00000028u;
goto P_0c087684;
P_0c087684: /* original f3e6, guest PC 0x0c087684 */
if(!s->budget--) { s->failed_pc=0x0c087684u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087686;
P_0c087686: /* original e028, guest PC 0x0c087686 */
if(!s->budget--) { s->failed_pc=0x0c087686u; return 0; }
r[0]=0x00000028u;
goto P_0c087688;
P_0c087688: /* original ff37, guest PC 0x0c087688 */
if(!s->budget--) { s->failed_pc=0x0c087688u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08768a;
P_0c08768a: /* original d341, guest PC 0x0c08768a */
if(!s->budget--) { s->failed_pc=0x0c08768au; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08768c;
P_0c08768c: /* original 430b, guest PC 0x0c08768c */
if(!s->budget--) { s->failed_pc=0x0c08768cu; return 0; }
target=r[3];
r[16]=0x0c087690u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087690u) { target=s->pc; goto dispatch; }
goto P_0c087690;
P_0c08768e: /* original 64f3, guest PC 0x0c08768e */
if(!s->budget--) { s->failed_pc=0x0c08768eu; return 0; }
r[4]=r[15];
goto P_0c087690;
P_0c087690: /* original 7f40, guest PC 0x0c087690 */
if(!s->budget--) { s->failed_pc=0x0c087690u; return 0; }
r[15]+=0x00000040u;
goto P_0c087692;
P_0c087692: /* original 4f26, guest PC 0x0c087692 */
if(!s->budget--) { s->failed_pc=0x0c087692u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087694;
P_0c087694: /* original 000b, guest PC 0x0c087694 */
if(!s->budget--) { s->failed_pc=0x0c087694u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087696: /* original 6ef6, guest PC 0x0c087696 */
if(!s->budget--) { s->failed_pc=0x0c087696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c087698u,s,ram);
P_0c08769c: /* original 4f22, guest PC 0x0c08769c */
if(!s->budget--) { s->failed_pc=0x0c08769cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08769e;
P_0c08769e: /* original d33a, guest PC 0x0c08769e */
if(!s->budget--) { s->failed_pc=0x0c08769eu; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0876a0;
P_0c0876a0: /* original 7fc0, guest PC 0x0c0876a0 */
if(!s->budget--) { s->failed_pc=0x0c0876a0u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0876a2;
P_0c0876a2: /* original 430b, guest PC 0x0c0876a2 */
if(!s->budget--) { s->failed_pc=0x0c0876a2u; return 0; }
target=r[3];
r[16]=0x0c0876a6u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0876a6u) { target=s->pc; goto dispatch; }
goto P_0c0876a6;
P_0c0876a4: /* original 64f3, guest PC 0x0c0876a4 */
if(!s->budget--) { s->failed_pc=0x0c0876a4u; return 0; }
r[4]=r[15];
goto P_0c0876a6;
P_0c0876a6: /* original f3f8, guest PC 0x0c0876a6 */
if(!s->budget--) { s->failed_pc=0x0c0876a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0876a8;
P_0c0876a8: /* original e004, guest PC 0x0c0876a8 */
if(!s->budget--) { s->failed_pc=0x0c0876a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0876aa;
P_0c0876aa: /* original fe3a, guest PC 0x0c0876aa */
if(!s->budget--) { s->failed_pc=0x0c0876aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0876ac;
P_0c0876ac: /* original f3f6, guest PC 0x0c0876ac */
if(!s->budget--) { s->failed_pc=0x0c0876acu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ae;
P_0c0876ae: /* original e004, guest PC 0x0c0876ae */
if(!s->budget--) { s->failed_pc=0x0c0876aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0876b0;
P_0c0876b0: /* original fe37, guest PC 0x0c0876b0 */
if(!s->budget--) { s->failed_pc=0x0c0876b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876b2;
P_0c0876b2: /* original e008, guest PC 0x0c0876b2 */
if(!s->budget--) { s->failed_pc=0x0c0876b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b4;
P_0c0876b4: /* original f3f6, guest PC 0x0c0876b4 */
if(!s->budget--) { s->failed_pc=0x0c0876b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876b6;
P_0c0876b6: /* original e008, guest PC 0x0c0876b6 */
if(!s->budget--) { s->failed_pc=0x0c0876b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0876b8;
P_0c0876b8: /* original fe37, guest PC 0x0c0876b8 */
if(!s->budget--) { s->failed_pc=0x0c0876b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ba;
P_0c0876ba: /* original e010, guest PC 0x0c0876ba */
if(!s->budget--) { s->failed_pc=0x0c0876bau; return 0; }
r[0]=0x00000010u;
goto P_0c0876bc;
P_0c0876bc: /* original f3f6, guest PC 0x0c0876bc */
if(!s->budget--) { s->failed_pc=0x0c0876bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876be;
P_0c0876be: /* original e010, guest PC 0x0c0876be */
if(!s->budget--) { s->failed_pc=0x0c0876beu; return 0; }
r[0]=0x00000010u;
goto P_0c0876c0;
P_0c0876c0: /* original fe37, guest PC 0x0c0876c0 */
if(!s->budget--) { s->failed_pc=0x0c0876c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876c2;
P_0c0876c2: /* original e014, guest PC 0x0c0876c2 */
if(!s->budget--) { s->failed_pc=0x0c0876c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c4;
P_0c0876c4: /* original f3f6, guest PC 0x0c0876c4 */
if(!s->budget--) { s->failed_pc=0x0c0876c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876c6;
P_0c0876c6: /* original e014, guest PC 0x0c0876c6 */
if(!s->budget--) { s->failed_pc=0x0c0876c6u; return 0; }
r[0]=0x00000014u;
goto P_0c0876c8;
P_0c0876c8: /* original fe37, guest PC 0x0c0876c8 */
if(!s->budget--) { s->failed_pc=0x0c0876c8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ca;
P_0c0876ca: /* original e018, guest PC 0x0c0876ca */
if(!s->budget--) { s->failed_pc=0x0c0876cau; return 0; }
r[0]=0x00000018u;
goto P_0c0876cc;
P_0c0876cc: /* original f3f6, guest PC 0x0c0876cc */
if(!s->budget--) { s->failed_pc=0x0c0876ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876ce;
P_0c0876ce: /* original e018, guest PC 0x0c0876ce */
if(!s->budget--) { s->failed_pc=0x0c0876ceu; return 0; }
r[0]=0x00000018u;
goto P_0c0876d0;
P_0c0876d0: /* original fe37, guest PC 0x0c0876d0 */
if(!s->budget--) { s->failed_pc=0x0c0876d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876d2;
P_0c0876d2: /* original e020, guest PC 0x0c0876d2 */
if(!s->budget--) { s->failed_pc=0x0c0876d2u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d4;
P_0c0876d4: /* original f3f6, guest PC 0x0c0876d4 */
if(!s->budget--) { s->failed_pc=0x0c0876d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876d6;
P_0c0876d6: /* original e020, guest PC 0x0c0876d6 */
if(!s->budget--) { s->failed_pc=0x0c0876d6u; return 0; }
r[0]=0x00000020u;
goto P_0c0876d8;
P_0c0876d8: /* original fe37, guest PC 0x0c0876d8 */
if(!s->budget--) { s->failed_pc=0x0c0876d8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876da;
P_0c0876da: /* original e024, guest PC 0x0c0876da */
if(!s->budget--) { s->failed_pc=0x0c0876dau; return 0; }
r[0]=0x00000024u;
goto P_0c0876dc;
P_0c0876dc: /* original f3f6, guest PC 0x0c0876dc */
if(!s->budget--) { s->failed_pc=0x0c0876dcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876de;
P_0c0876de: /* original e024, guest PC 0x0c0876de */
if(!s->budget--) { s->failed_pc=0x0c0876deu; return 0; }
r[0]=0x00000024u;
goto P_0c0876e0;
P_0c0876e0: /* original fe37, guest PC 0x0c0876e0 */
if(!s->budget--) { s->failed_pc=0x0c0876e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876e2;
P_0c0876e2: /* original e028, guest PC 0x0c0876e2 */
if(!s->budget--) { s->failed_pc=0x0c0876e2u; return 0; }
r[0]=0x00000028u;
goto P_0c0876e4;
P_0c0876e4: /* original f3f6, guest PC 0x0c0876e4 */
if(!s->budget--) { s->failed_pc=0x0c0876e4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0876e6;
P_0c0876e6: /* original 7f40, guest PC 0x0c0876e6 */
if(!s->budget--) { s->failed_pc=0x0c0876e6u; return 0; }
r[15]+=0x00000040u;
goto P_0c0876e8;
P_0c0876e8: /* original 4f26, guest PC 0x0c0876e8 */
if(!s->budget--) { s->failed_pc=0x0c0876e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0876ea;
P_0c0876ea: /* original e028, guest PC 0x0c0876ea */
if(!s->budget--) { s->failed_pc=0x0c0876eau; return 0; }
r[0]=0x00000028u;
goto P_0c0876ec;
P_0c0876ec: /* original fe37, guest PC 0x0c0876ec */
if(!s->budget--) { s->failed_pc=0x0c0876ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0876ee;
P_0c0876ee: /* original 000b, guest PC 0x0c0876ee */
if(!s->budget--) { s->failed_pc=0x0c0876eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0876f0: /* original 6ef6, guest PC 0x0c0876f0 */
if(!s->budget--) { s->failed_pc=0x0c0876f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0876f2u,s,ram);
P_0c0879da: /* original 4f22, guest PC 0x0c0879da */
if(!s->budget--) { s->failed_pc=0x0c0879dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0879dc;
P_0c0879dc: /* original 9024, guest PC 0x0c0879dc */
if(!s->budget--) { s->failed_pc=0x0c0879dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a28u,2);
goto P_0c0879de;
P_0c0879de: /* original 4f12, guest PC 0x0c0879de */
if(!s->budget--) { s->failed_pc=0x0c0879deu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0879e0;
P_0c0879e0: /* original f346, guest PC 0x0c0879e0 */
if(!s->budget--) { s->failed_pc=0x0c0879e0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879e2;
P_0c0879e2: /* original e008, guest PC 0x0c0879e2 */
if(!s->budget--) { s->failed_pc=0x0c0879e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0879e4;
P_0c0879e4: /* original 7ff4, guest PC 0x0c0879e4 */
if(!s->budget--) { s->failed_pc=0x0c0879e4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0879e6;
P_0c0879e6: /* original ff37, guest PC 0x0c0879e6 */
if(!s->budget--) { s->failed_pc=0x0c0879e6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0879e8;
P_0c0879e8: /* original 901f, guest PC 0x0c0879e8 */
if(!s->budget--) { s->failed_pc=0x0c0879e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2au,2);
goto P_0c0879ea;
P_0c0879ea: /* original f346, guest PC 0x0c0879ea */
if(!s->budget--) { s->failed_pc=0x0c0879eau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879ec;
P_0c0879ec: /* original ff3a, guest PC 0x0c0879ec */
if(!s->budget--) { s->failed_pc=0x0c0879ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0879ee;
P_0c0879ee: /* original 901d, guest PC 0x0c0879ee */
if(!s->budget--) { s->failed_pc=0x0c0879eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2cu,2);
goto P_0c0879f0;
P_0c0879f0: /* original 054e, guest PC 0x0c0879f0 */
if(!s->budget--) { s->failed_pc=0x0c0879f0u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0879f2;
P_0c0879f2: /* original 7008, guest PC 0x0c0879f2 */
if(!s->budget--) { s->failed_pc=0x0c0879f2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0879f4;
P_0c0879f4: /* original 044e, guest PC 0x0c0879f4 */
if(!s->budget--) { s->failed_pc=0x0c0879f4u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0879f6;
P_0c0879f6: /* original c710, guest PC 0x0c0879f6 */
if(!s->budget--) { s->failed_pc=0x0c0879f6u; return 0; }
r[0]=0x0c087a38u;
goto P_0c0879f8;
P_0c0879f8: /* original f308, guest PC 0x0c0879f8 */
if(!s->budget--) { s->failed_pc=0x0c0879f8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0879fa;
P_0c0879fa: /* original f432, guest PC 0x0c0879fa */
if(!s->budget--) { s->failed_pc=0x0c0879fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0879fc;
P_0c0879fc: /* original f43d, guest PC 0x0c0879fc */
if(!s->budget--) { s->failed_pc=0x0c0879fcu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0879fe;
P_0c0879fe: /* original 065a, guest PC 0x0c0879fe */
if(!s->budget--) { s->failed_pc=0x0c0879feu; return 0; }
r[6]=r[53];
goto P_0c087a00;
P_0c087a00: /* original 346c, guest PC 0x0c087a00 */
if(!s->budget--) { s->failed_pc=0x0c087a00u; return 0; }
r[4]+=r[6];
goto P_0c087a02;
P_0c087a02: /* original 0547, guest PC 0x0c087a02 */
if(!s->budget--) { s->failed_pc=0x0c087a02u; return 0; }
r[19]=r[5]*r[4];
goto P_0c087a04;
P_0c087a04: /* original 041a, guest PC 0x0c087a04 */
if(!s->budget--) { s->failed_pc=0x0c087a04u; return 0; }
r[4]=r[19];
goto P_0c087a06;
P_0c087a06: /* original 644d, guest PC 0x0c087a06 */
if(!s->budget--) { s->failed_pc=0x0c087a06u; return 0; }
r[4]=r[4]&65535u;
goto P_0c087a08;
P_0c087a08: /* original 1f41, guest PC 0x0c087a08 */
if(!s->budget--) { s->failed_pc=0x0c087a08u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c087a0a;
P_0c087a0a: /* original d30c, guest PC 0x0c087a0a */
if(!s->budget--) { s->failed_pc=0x0c087a0au; return 0; }
r[3]=read(ram,0x0c087a3cu,4);
goto P_0c087a0c;
P_0c087a0c: /* original 430b, guest PC 0x0c087a0c */
if(!s->budget--) { s->failed_pc=0x0c087a0cu; return 0; }
target=r[3];
r[16]=0x0c087a10u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087a10u) { target=s->pc; goto dispatch; }
goto P_0c087a10;
P_0c087a0e: /* original 644f, guest PC 0x0c087a0e */
if(!s->budget--) { s->failed_pc=0x0c087a0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c087a10;
P_0c087a10: /* original e008, guest PC 0x0c087a10 */
if(!s->budget--) { s->failed_pc=0x0c087a10u; return 0; }
r[0]=0x00000008u;
goto P_0c087a12;
P_0c087a12: /* original f2f8, guest PC 0x0c087a12 */
if(!s->budget--) { s->failed_pc=0x0c087a12u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c087a14;
P_0c087a14: /* original f3f6, guest PC 0x0c087a14 */
if(!s->budget--) { s->failed_pc=0x0c087a14u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087a16;
P_0c087a16: /* original 7f0c, guest PC 0x0c087a16 */
if(!s->budget--) { s->failed_pc=0x0c087a16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c087a18;
P_0c087a18: /* original 4f16, guest PC 0x0c087a18 */
if(!s->budget--) { s->failed_pc=0x0c087a18u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1a;
P_0c087a1a: /* original f32e, guest PC 0x0c087a1a */
if(!s->budget--) { s->failed_pc=0x0c087a1au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c087a1c;
P_0c087a1c: /* original 4f26, guest PC 0x0c087a1c */
if(!s->budget--) { s->failed_pc=0x0c087a1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1e;
P_0c087a1e: /* original f03c, guest PC 0x0c087a1e */
if(!s->budget--) { s->failed_pc=0x0c087a1eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c087a20;
P_0c087a20: /* original 000b, guest PC 0x0c087a20 */
if(!s->budget--) { s->failed_pc=0x0c087a20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087a22: /* original 0009, guest PC 0x0c087a22 */
if(!s->budget--) { s->failed_pc=0x0c087a22u; return 0; }
return vf3_matrix_family(0x0c087a24u,s,ram);
P_0c08b648: /* original 4f22, guest PC 0x0c08b648 */
if(!s->budget--) { s->failed_pc=0x0c08b648u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b64a;
P_0c08b64a: /* original 7ffc, guest PC 0x0c08b64a */
if(!s->budget--) { s->failed_pc=0x0c08b64au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b64c;
P_0c08b64c: /* original 2fe2, guest PC 0x0c08b64c */
if(!s->budget--) { s->failed_pc=0x0c08b64cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b64e;
P_0c08b64e: /* original b019, guest PC 0x0c08b64e */
if(!s->budget--) { s->failed_pc=0x0c08b64eu; return 0; }
target=0x0c08b684u; r[16]=0x0c08b652u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b652u) { target=s->pc; goto dispatch; }
goto P_0c08b652;
P_0c08b650: /* original 64e3, guest PC 0x0c08b650 */
if(!s->budget--) { s->failed_pc=0x0c08b650u; return 0; }
r[4]=r[14];
goto P_0c08b652;
P_0c08b652: /* original b06d, guest PC 0x0c08b652 */
if(!s->budget--) { s->failed_pc=0x0c08b652u; return 0; }
target=0x0c08b730u; r[16]=0x0c08b656u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b656u) { target=s->pc; goto dispatch; }
goto P_0c08b656;
P_0c08b654: /* original 64e3, guest PC 0x0c08b654 */
if(!s->budget--) { s->failed_pc=0x0c08b654u; return 0; }
r[4]=r[14];
goto P_0c08b656;
P_0c08b656: /* original 63f2, guest PC 0x0c08b656 */
if(!s->budget--) { s->failed_pc=0x0c08b656u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b658;
P_0c08b658: /* original 7f04, guest PC 0x0c08b658 */
if(!s->budget--) { s->failed_pc=0x0c08b658u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b65a;
P_0c08b65a: /* original 4f26, guest PC 0x0c08b65a */
if(!s->budget--) { s->failed_pc=0x0c08b65au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b65c;
P_0c08b65c: /* original d24b, guest PC 0x0c08b65c */
if(!s->budget--) { s->failed_pc=0x0c08b65cu; return 0; }
r[2]=read(ram,0x0c08b78cu,4);
goto P_0c08b65e;
P_0c08b65e: /* original 1323, guest PC 0x0c08b65e */
if(!s->budget--) { s->failed_pc=0x0c08b65eu; return 0; }
write(ram,r[3]+12,r[2],4);
goto P_0c08b660;
P_0c08b660: /* original 000b, guest PC 0x0c08b660 */
if(!s->budget--) { s->failed_pc=0x0c08b660u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b662: /* original 6ef6, guest PC 0x0c08b662 */
if(!s->budget--) { s->failed_pc=0x0c08b662u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b664u,s,ram);
P_0c08b668: /* original 4f22, guest PC 0x0c08b668 */
if(!s->budget--) { s->failed_pc=0x0c08b668u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b66a;
P_0c08b66a: /* original 7ffc, guest PC 0x0c08b66a */
if(!s->budget--) { s->failed_pc=0x0c08b66au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b66c;
P_0c08b66c: /* original 2fe2, guest PC 0x0c08b66c */
if(!s->budget--) { s->failed_pc=0x0c08b66cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b66e;
P_0c08b66e: /* original b009, guest PC 0x0c08b66e */
if(!s->budget--) { s->failed_pc=0x0c08b66eu; return 0; }
target=0x0c08b684u; r[16]=0x0c08b672u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b672u) { target=s->pc; goto dispatch; }
goto P_0c08b672;
P_0c08b670: /* original 64e3, guest PC 0x0c08b670 */
if(!s->budget--) { s->failed_pc=0x0c08b670u; return 0; }
r[4]=r[14];
goto P_0c08b672;
P_0c08b672: /* original b05d, guest PC 0x0c08b672 */
if(!s->budget--) { s->failed_pc=0x0c08b672u; return 0; }
target=0x0c08b730u; r[16]=0x0c08b676u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b676u) { target=s->pc; goto dispatch; }
goto P_0c08b676;
P_0c08b674: /* original 64e3, guest PC 0x0c08b674 */
if(!s->budget--) { s->failed_pc=0x0c08b674u; return 0; }
r[4]=r[14];
goto P_0c08b676;
P_0c08b676: /* original 63f2, guest PC 0x0c08b676 */
if(!s->budget--) { s->failed_pc=0x0c08b676u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08b678;
P_0c08b678: /* original 7f04, guest PC 0x0c08b678 */
if(!s->budget--) { s->failed_pc=0x0c08b678u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b67a;
P_0c08b67a: /* original 4f26, guest PC 0x0c08b67a */
if(!s->budget--) { s->failed_pc=0x0c08b67au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b67c;
P_0c08b67c: /* original d244, guest PC 0x0c08b67c */
if(!s->budget--) { s->failed_pc=0x0c08b67cu; return 0; }
r[2]=read(ram,0x0c08b790u,4);
goto P_0c08b67e;
P_0c08b67e: /* original 1323, guest PC 0x0c08b67e */
if(!s->budget--) { s->failed_pc=0x0c08b67eu; return 0; }
write(ram,r[3]+12,r[2],4);
goto P_0c08b680;
P_0c08b680: /* original 000b, guest PC 0x0c08b680 */
if(!s->budget--) { s->failed_pc=0x0c08b680u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b682: /* original 6ef6, guest PC 0x0c08b682 */
if(!s->budget--) { s->failed_pc=0x0c08b682u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b684;
P_0c08b684: /* original d344, guest PC 0x0c08b684 */
if(!s->budget--) { s->failed_pc=0x0c08b684u; return 0; }
r[3]=read(ram,0x0c08b798u,4);
goto P_0c08b686;
P_0c08b686: /* original d643, guest PC 0x0c08b686 */
if(!s->budget--) { s->failed_pc=0x0c08b686u; return 0; }
r[6]=read(ram,0x0c08b794u,4);
goto P_0c08b688;
P_0c08b688: /* original 6732, guest PC 0x0c08b688 */
if(!s->budget--) { s->failed_pc=0x0c08b688u; return 0; }
tmp=read(ram,r[3],4);
r[7]=tmp;
goto P_0c08b68a;
P_0c08b68a: /* original 6072, guest PC 0x0c08b68a */
if(!s->budget--) { s->failed_pc=0x0c08b68au; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c08b68c;
P_0c08b68c: /* original c802, guest PC 0x0c08b68c */
if(!s->budget--) { s->failed_pc=0x0c08b68cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c08b68e;
P_0c08b68e: /* original 8d03, guest PC 0x0c08b68e */
if(!s->budget--) { s->failed_pc=0x0c08b68eu; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c08b698; }
goto P_0c08b692;
P_0c08b690: /* original e500, guest PC 0x0c08b690 */
if(!s->budget--) { s->failed_pc=0x0c08b690u; return 0; }
r[5]=0x00000000u;
goto P_0c08b692;
P_0c08b692: /* original 9075, guest PC 0x0c08b692 */
if(!s->budget--) { s->failed_pc=0x0c08b692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b780u,2);
goto P_0c08b694;
P_0c08b694: /* original a003, guest PC 0x0c08b694 */
if(!s->budget--) { s->failed_pc=0x0c08b694u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b69e;
P_0c08b696: /* original 0454, guest PC 0x0c08b696 */
if(!s->budget--) { s->failed_pc=0x0c08b696u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b698;
P_0c08b698: /* original 9072, guest PC 0x0c08b698 */
if(!s->budget--) { s->failed_pc=0x0c08b698u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b780u,2);
goto P_0c08b69a;
P_0c08b69a: /* original e101, guest PC 0x0c08b69a */
if(!s->budget--) { s->failed_pc=0x0c08b69au; return 0; }
r[1]=0x00000001u;
goto P_0c08b69c;
P_0c08b69c: /* original 0414, guest PC 0x0c08b69c */
if(!s->budget--) { s->failed_pc=0x0c08b69cu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c08b69e;
P_0c08b69e: /* original 6053, guest PC 0x0c08b69e */
if(!s->budget--) { s->failed_pc=0x0c08b69eu; return 0; }
r[0]=r[5];
goto P_0c08b6a0;
P_0c08b6a0: /* original 1454, guest PC 0x0c08b6a0 */
if(!s->budget--) { s->failed_pc=0x0c08b6a0u; return 0; }
write(ram,r[4]+16,r[5],4);
goto P_0c08b6a2;
P_0c08b6a2: /* original 814a, guest PC 0x0c08b6a2 */
if(!s->budget--) { s->failed_pc=0x0c08b6a2u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c08b6a4;
P_0c08b6a4: /* original 814b, guest PC 0x0c08b6a4 */
if(!s->budget--) { s->failed_pc=0x0c08b6a4u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c08b6a6;
P_0c08b6a6: /* original 814c, guest PC 0x0c08b6a6 */
if(!s->budget--) { s->failed_pc=0x0c08b6a6u; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c08b6a8;
P_0c08b6a8: /* original 814e, guest PC 0x0c08b6a8 */
if(!s->budget--) { s->failed_pc=0x0c08b6a8u; return 0; }
write(ram,r[4]+28,r[0],2);
goto P_0c08b6aa;
P_0c08b6aa: /* original 814f, guest PC 0x0c08b6aa */
if(!s->budget--) { s->failed_pc=0x0c08b6aau; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c08b6ac;
P_0c08b6ac: /* original e022, guest PC 0x0c08b6ac */
if(!s->budget--) { s->failed_pc=0x0c08b6acu; return 0; }
r[0]=0x00000022u;
goto P_0c08b6ae;
P_0c08b6ae: /* original 0455, guest PC 0x0c08b6ae */
if(!s->budget--) { s->failed_pc=0x0c08b6aeu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08b6b0;
P_0c08b6b0: /* original e024, guest PC 0x0c08b6b0 */
if(!s->budget--) { s->failed_pc=0x0c08b6b0u; return 0; }
r[0]=0x00000024u;
goto P_0c08b6b2;
P_0c08b6b2: /* original 0455, guest PC 0x0c08b6b2 */
if(!s->budget--) { s->failed_pc=0x0c08b6b2u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08b6b4;
P_0c08b6b4: /* original e026, guest PC 0x0c08b6b4 */
if(!s->budget--) { s->failed_pc=0x0c08b6b4u; return 0; }
r[0]=0x00000026u;
goto P_0c08b6b6;
P_0c08b6b6: /* original 0455, guest PC 0x0c08b6b6 */
if(!s->budget--) { s->failed_pc=0x0c08b6b6u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08b6b8;
P_0c08b6b8: /* original e028, guest PC 0x0c08b6b8 */
if(!s->budget--) { s->failed_pc=0x0c08b6b8u; return 0; }
r[0]=0x00000028u;
goto P_0c08b6ba;
P_0c08b6ba: /* original 0455, guest PC 0x0c08b6ba */
if(!s->budget--) { s->failed_pc=0x0c08b6bau; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08b6bc;
P_0c08b6bc: /* original e02c, guest PC 0x0c08b6bc */
if(!s->budget--) { s->failed_pc=0x0c08b6bcu; return 0; }
r[0]=0x0000002cu;
goto P_0c08b6be;
P_0c08b6be: /* original 0454, guest PC 0x0c08b6be */
if(!s->budget--) { s->failed_pc=0x0c08b6beu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6c0;
P_0c08b6c0: /* original e02d, guest PC 0x0c08b6c0 */
if(!s->budget--) { s->failed_pc=0x0c08b6c0u; return 0; }
r[0]=0x0000002du;
goto P_0c08b6c2;
P_0c08b6c2: /* original 0454, guest PC 0x0c08b6c2 */
if(!s->budget--) { s->failed_pc=0x0c08b6c2u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6c4;
P_0c08b6c4: /* original e040, guest PC 0x0c08b6c4 */
if(!s->budget--) { s->failed_pc=0x0c08b6c4u; return 0; }
r[0]=0x00000040u;
goto P_0c08b6c6;
P_0c08b6c6: /* original 0454, guest PC 0x0c08b6c6 */
if(!s->budget--) { s->failed_pc=0x0c08b6c6u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6c8;
P_0c08b6c8: /* original e041, guest PC 0x0c08b6c8 */
if(!s->budget--) { s->failed_pc=0x0c08b6c8u; return 0; }
r[0]=0x00000041u;
goto P_0c08b6ca;
P_0c08b6ca: /* original 0454, guest PC 0x0c08b6ca */
if(!s->budget--) { s->failed_pc=0x0c08b6cau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6cc;
P_0c08b6cc: /* original e044, guest PC 0x0c08b6cc */
if(!s->budget--) { s->failed_pc=0x0c08b6ccu; return 0; }
r[0]=0x00000044u;
goto P_0c08b6ce;
P_0c08b6ce: /* original 0456, guest PC 0x0c08b6ce */
if(!s->budget--) { s->failed_pc=0x0c08b6ceu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b6d0;
P_0c08b6d0: /* original e048, guest PC 0x0c08b6d0 */
if(!s->budget--) { s->failed_pc=0x0c08b6d0u; return 0; }
r[0]=0x00000048u;
goto P_0c08b6d2;
P_0c08b6d2: /* original 0454, guest PC 0x0c08b6d2 */
if(!s->budget--) { s->failed_pc=0x0c08b6d2u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6d4;
P_0c08b6d4: /* original e04a, guest PC 0x0c08b6d4 */
if(!s->budget--) { s->failed_pc=0x0c08b6d4u; return 0; }
r[0]=0x0000004au;
goto P_0c08b6d6;
P_0c08b6d6: /* original 9354, guest PC 0x0c08b6d6 */
if(!s->budget--) { s->failed_pc=0x0c08b6d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b782u,2);
goto P_0c08b6d8;
P_0c08b6d8: /* original 0435, guest PC 0x0c08b6d8 */
if(!s->budget--) { s->failed_pc=0x0c08b6d8u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c08b6da;
P_0c08b6da: /* original e04c, guest PC 0x0c08b6da */
if(!s->budget--) { s->failed_pc=0x0c08b6dau; return 0; }
r[0]=0x0000004cu;
goto P_0c08b6dc;
P_0c08b6dc: /* original 0455, guest PC 0x0c08b6dc */
if(!s->budget--) { s->failed_pc=0x0c08b6dcu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08b6de;
P_0c08b6de: /* original e04f, guest PC 0x0c08b6de */
if(!s->budget--) { s->failed_pc=0x0c08b6deu; return 0; }
r[0]=0x0000004fu;
goto P_0c08b6e0;
P_0c08b6e0: /* original 0454, guest PC 0x0c08b6e0 */
if(!s->budget--) { s->failed_pc=0x0c08b6e0u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6e2;
P_0c08b6e2: /* original 7036, guest PC 0x0c08b6e2 */
if(!s->budget--) { s->failed_pc=0x0c08b6e2u; return 0; }
r[0]+=0x00000036u;
goto P_0c08b6e4;
P_0c08b6e4: /* original 0454, guest PC 0x0c08b6e4 */
if(!s->budget--) { s->failed_pc=0x0c08b6e4u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6e6;
P_0c08b6e6: /* original 7001, guest PC 0x0c08b6e6 */
if(!s->budget--) { s->failed_pc=0x0c08b6e6u; return 0; }
r[0]+=0x00000001u;
goto P_0c08b6e8;
P_0c08b6e8: /* original 0454, guest PC 0x0c08b6e8 */
if(!s->budget--) { s->failed_pc=0x0c08b6e8u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08b6ea;
P_0c08b6ea: /* original 904b, guest PC 0x0c08b6ea */
if(!s->budget--) { s->failed_pc=0x0c08b6eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b784u,2);
goto P_0c08b6ec;
P_0c08b6ec: /* original 006c, guest PC 0x0c08b6ec */
if(!s->budget--) { s->failed_pc=0x0c08b6ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c08b6ee;
P_0c08b6ee: /* original 8801, guest PC 0x0c08b6ee */
if(!s->budget--) { s->failed_pc=0x0c08b6eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08b6f0;
P_0c08b6f0: /* original 8b1c, guest PC 0x0c08b6f0 */
if(!s->budget--) { s->failed_pc=0x0c08b6f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b72c; }
goto P_0c08b6f2;
P_0c08b6f2: /* original 9048, guest PC 0x0c08b6f2 */
if(!s->budget--) { s->failed_pc=0x0c08b6f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b786u,2);
goto P_0c08b6f4;
P_0c08b6f4: /* original 0654, guest PC 0x0c08b6f4 */
if(!s->budget--) { s->failed_pc=0x0c08b6f4u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c08b6f6;
P_0c08b6f6: /* original 70f4, guest PC 0x0c08b6f6 */
if(!s->budget--) { s->failed_pc=0x0c08b6f6u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c08b6f8;
P_0c08b6f8: /* original 0654, guest PC 0x0c08b6f8 */
if(!s->budget--) { s->failed_pc=0x0c08b6f8u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c08b6fa;
P_0c08b6fa: /* original e050, guest PC 0x0c08b6fa */
if(!s->budget--) { s->failed_pc=0x0c08b6fau; return 0; }
r[0]=0x00000050u;
goto P_0c08b6fc;
P_0c08b6fc: /* original f48d, guest PC 0x0c08b6fc */
if(!s->budget--) { s->failed_pc=0x0c08b6fcu; return 0; }
fr[4]=0;
goto P_0c08b6fe;
P_0c08b6fe: /* original f447, guest PC 0x0c08b6fe */
if(!s->budget--) { s->failed_pc=0x0c08b6feu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08b700;
P_0c08b700: /* original 7030, guest PC 0x0c08b700 */
if(!s->budget--) { s->failed_pc=0x0c08b700u; return 0; }
r[0]+=0x00000030u;
goto P_0c08b702;
P_0c08b702: /* original f447, guest PC 0x0c08b702 */
if(!s->budget--) { s->failed_pc=0x0c08b702u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08b704;
P_0c08b704: /* original e058, guest PC 0x0c08b704 */
if(!s->budget--) { s->failed_pc=0x0c08b704u; return 0; }
r[0]=0x00000058u;
goto P_0c08b706;
P_0c08b706: /* original 0456, guest PC 0x0c08b706 */
if(!s->budget--) { s->failed_pc=0x0c08b706u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b708;
P_0c08b708: /* original e05c, guest PC 0x0c08b708 */
if(!s->budget--) { s->failed_pc=0x0c08b708u; return 0; }
r[0]=0x0000005cu;
goto P_0c08b70a;
P_0c08b70a: /* original 0456, guest PC 0x0c08b70a */
if(!s->budget--) { s->failed_pc=0x0c08b70au; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b70c;
P_0c08b70c: /* original e060, guest PC 0x0c08b70c */
if(!s->budget--) { s->failed_pc=0x0c08b70cu; return 0; }
r[0]=0x00000060u;
goto P_0c08b70e;
P_0c08b70e: /* original 0456, guest PC 0x0c08b70e */
if(!s->budget--) { s->failed_pc=0x0c08b70eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b710;
P_0c08b710: /* original e064, guest PC 0x0c08b710 */
if(!s->budget--) { s->failed_pc=0x0c08b710u; return 0; }
r[0]=0x00000064u;
goto P_0c08b712;
P_0c08b712: /* original 0456, guest PC 0x0c08b712 */
if(!s->budget--) { s->failed_pc=0x0c08b712u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b714;
P_0c08b714: /* original e068, guest PC 0x0c08b714 */
if(!s->budget--) { s->failed_pc=0x0c08b714u; return 0; }
r[0]=0x00000068u;
goto P_0c08b716;
P_0c08b716: /* original 0456, guest PC 0x0c08b716 */
if(!s->budget--) { s->failed_pc=0x0c08b716u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b718;
P_0c08b718: /* original e06c, guest PC 0x0c08b718 */
if(!s->budget--) { s->failed_pc=0x0c08b718u; return 0; }
r[0]=0x0000006cu;
goto P_0c08b71a;
P_0c08b71a: /* original 0456, guest PC 0x0c08b71a */
if(!s->budget--) { s->failed_pc=0x0c08b71au; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b71c;
P_0c08b71c: /* original e070, guest PC 0x0c08b71c */
if(!s->budget--) { s->failed_pc=0x0c08b71cu; return 0; }
r[0]=0x00000070u;
goto P_0c08b71e;
P_0c08b71e: /* original 0456, guest PC 0x0c08b71e */
if(!s->budget--) { s->failed_pc=0x0c08b71eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b720;
P_0c08b720: /* original e074, guest PC 0x0c08b720 */
if(!s->budget--) { s->failed_pc=0x0c08b720u; return 0; }
r[0]=0x00000074u;
goto P_0c08b722;
P_0c08b722: /* original 0456, guest PC 0x0c08b722 */
if(!s->budget--) { s->failed_pc=0x0c08b722u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b724;
P_0c08b724: /* original e078, guest PC 0x0c08b724 */
if(!s->budget--) { s->failed_pc=0x0c08b724u; return 0; }
r[0]=0x00000078u;
goto P_0c08b726;
P_0c08b726: /* original 0456, guest PC 0x0c08b726 */
if(!s->budget--) { s->failed_pc=0x0c08b726u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b728;
P_0c08b728: /* original e07c, guest PC 0x0c08b728 */
if(!s->budget--) { s->failed_pc=0x0c08b728u; return 0; }
r[0]=0x0000007cu;
goto P_0c08b72a;
P_0c08b72a: /* original 0456, guest PC 0x0c08b72a */
if(!s->budget--) { s->failed_pc=0x0c08b72au; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08b72c;
P_0c08b72c: /* original 000b, guest PC 0x0c08b72c */
if(!s->budget--) { s->failed_pc=0x0c08b72cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08b72e: /* original 0009, guest PC 0x0c08b72e */
if(!s->budget--) { s->failed_pc=0x0c08b72eu; return 0; }
goto P_0c08b730;
P_0c08b730: /* original 2fe6, guest PC 0x0c08b730 */
if(!s->budget--) { s->failed_pc=0x0c08b730u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08b732;
P_0c08b732: /* original e02b, guest PC 0x0c08b732 */
if(!s->budget--) { s->failed_pc=0x0c08b732u; return 0; }
r[0]=0x0000002bu;
goto P_0c08b734;
P_0c08b734: /* original 2fd6, guest PC 0x0c08b734 */
if(!s->budget--) { s->failed_pc=0x0c08b734u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08b736;
P_0c08b736: /* original 2fc6, guest PC 0x0c08b736 */
if(!s->budget--) { s->failed_pc=0x0c08b736u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08b738;
P_0c08b738: /* original 6c43, guest PC 0x0c08b738 */
if(!s->budget--) { s->failed_pc=0x0c08b738u; return 0; }
r[12]=r[4];
goto P_0c08b73a;
P_0c08b73a: /* original 2fb6, guest PC 0x0c08b73a */
if(!s->budget--) { s->failed_pc=0x0c08b73au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c08b73c;
P_0c08b73c: /* original 4f22, guest PC 0x0c08b73c */
if(!s->budget--) { s->failed_pc=0x0c08b73cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b73e;
P_0c08b73e: /* original d317, guest PC 0x0c08b73e */
if(!s->budget--) { s->failed_pc=0x0c08b73eu; return 0; }
r[3]=read(ram,0x0c08b79cu,4);
goto P_0c08b740;
P_0c08b740: /* original dd14, guest PC 0x0c08b740 */
if(!s->budget--) { s->failed_pc=0x0c08b740u; return 0; }
r[13]=read(ram,0x0c08b794u,4);
goto P_0c08b742;
P_0c08b742: /* original 7ffc, guest PC 0x0c08b742 */
if(!s->budget--) { s->failed_pc=0x0c08b742u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b744;
P_0c08b744: /* original 6433, guest PC 0x0c08b744 */
if(!s->budget--) { s->failed_pc=0x0c08b744u; return 0; }
r[4]=r[3];
goto P_0c08b746;
P_0c08b746: /* original 2f32, guest PC 0x0c08b746 */
if(!s->budget--) { s->failed_pc=0x0c08b746u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08b748;
P_0c08b748: /* original db15, guest PC 0x0c08b748 */
if(!s->budget--) { s->failed_pc=0x0c08b748u; return 0; }
r[11]=read(ram,0x0c08b7a0u,4);
goto P_0c08b74a;
P_0c08b74a: /* original d316, guest PC 0x0c08b74a */
if(!s->budget--) { s->failed_pc=0x0c08b74au; return 0; }
r[3]=read(ram,0x0c08b7a4u,4);
goto P_0c08b74c;
P_0c08b74c: /* original 0ebc, guest PC 0x0c08b74c */
if(!s->budget--) { s->failed_pc=0x0c08b74cu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c08b74e;
P_0c08b74e: /* original 430b, guest PC 0x0c08b74e */
if(!s->budget--) { s->failed_pc=0x0c08b74eu; return 0; }
target=r[3];
r[16]=0x0c08b752u;
r[4]+=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b752u) { target=s->pc; goto dispatch; }
goto P_0c08b752;
P_0c08b750: /* original 7402, guest PC 0x0c08b750 */
if(!s->budget--) { s->failed_pc=0x0c08b750u; return 0; }
r[4]+=0x00000002u;
goto P_0c08b752;
P_0c08b752: /* original 640c, guest PC 0x0c08b752 */
if(!s->budget--) { s->failed_pc=0x0c08b752u; return 0; }
r[4]=r[0]&255u;
goto P_0c08b754;
P_0c08b754: /* original e04f, guest PC 0x0c08b754 */
if(!s->budget--) { s->failed_pc=0x0c08b754u; return 0; }
r[0]=0x0000004fu;
goto P_0c08b756;
P_0c08b756: /* original 0c44, guest PC 0x0c08b756 */
if(!s->budget--) { s->failed_pc=0x0c08b756u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c08b758;
P_0c08b758: /* original 52b2, guest PC 0x0c08b758 */
if(!s->budget--) { s->failed_pc=0x0c08b758u; return 0; }
r[2]=read(ram,r[11]+8,4);
goto P_0c08b75a;
P_0c08b75a: /* original d313, guest PC 0x0c08b75a */
if(!s->budget--) { s->failed_pc=0x0c08b75au; return 0; }
r[3]=read(ram,0x0c08b7a8u,4);
goto P_0c08b75c;
P_0c08b75c: /* original 2238, guest PC 0x0c08b75c */
if(!s->budget--) { s->failed_pc=0x0c08b75cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08b75e;
P_0c08b75e: /* original 892c, guest PC 0x0c08b75e */
if(!s->budget--) { s->failed_pc=0x0c08b75eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b7ba; }
goto P_0c08b760;
P_0c08b760: /* original 9012, guest PC 0x0c08b760 */
if(!s->budget--) { s->failed_pc=0x0c08b760u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b788u,2);
goto P_0c08b762;
P_0c08b762: /* original 0edc, guest PC 0x0c08b762 */
if(!s->budget--) { s->failed_pc=0x0c08b762u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08b764;
P_0c08b764: /* original e02b, guest PC 0x0c08b764 */
if(!s->budget--) { s->failed_pc=0x0c08b764u; return 0; }
r[0]=0x0000002bu;
goto P_0c08b766;
P_0c08b766: /* original 0be4, guest PC 0x0c08b766 */
if(!s->budget--) { s->failed_pc=0x0c08b766u; return 0; }
write(ram,r[11]+r[0],r[14],1);
goto P_0c08b768;
P_0c08b768: /* original 900f, guest PC 0x0c08b768 */
if(!s->budget--) { s->failed_pc=0x0c08b768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b78au,2);
goto P_0c08b76a;
P_0c08b76a: /* original 00dc, guest PC 0x0c08b76a */
if(!s->budget--) { s->failed_pc=0x0c08b76au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08b76c;
P_0c08b76c: /* original 8802, guest PC 0x0c08b76c */
if(!s->budget--) { s->failed_pc=0x0c08b76cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08b76e;
P_0c08b76e: /* original 8b1d, guest PC 0x0c08b76e */
if(!s->budget--) { s->failed_pc=0x0c08b76eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b7ac; }
goto P_0c08b770;
P_0c08b770: /* original 9009, guest PC 0x0c08b770 */
if(!s->budget--) { s->failed_pc=0x0c08b770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b786u,2);
goto P_0c08b772;
P_0c08b772: /* original e504, guest PC 0x0c08b772 */
if(!s->budget--) { s->failed_pc=0x0c08b772u; return 0; }
r[5]=0x00000004u;
goto P_0c08b774;
P_0c08b774: /* original 6453, guest PC 0x0c08b774 */
if(!s->budget--) { s->failed_pc=0x0c08b774u; return 0; }
r[4]=r[5];
goto P_0c08b776;
P_0c08b776: /* original 0edc, guest PC 0x0c08b776 */
if(!s->budget--) { s->failed_pc=0x0c08b776u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08b778;
P_0c08b778: /* original e04f, guest PC 0x0c08b778 */
if(!s->budget--) { s->failed_pc=0x0c08b778u; return 0; }
r[0]=0x0000004fu;
goto P_0c08b77a;
P_0c08b77a: /* original 7e01, guest PC 0x0c08b77a */
if(!s->budget--) { s->failed_pc=0x0c08b77au; return 0; }
r[14]+=0x00000001u;
goto P_0c08b77c;
P_0c08b77c: /* original a01d, guest PC 0x0c08b77c */
if(!s->budget--) { s->failed_pc=0x0c08b77cu; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c08b7ba;
P_0c08b77e: /* original 0c44, guest PC 0x0c08b77e */
if(!s->budget--) { s->failed_pc=0x0c08b77eu; return 0; }
write(ram,r[12]+r[0],r[4],1);
return vf3_matrix_family(0x0c08b780u,s,ram);
P_0c08b7ac: /* original 2ee8, guest PC 0x0c08b7ac */
if(!s->budget--) { s->failed_pc=0x0c08b7acu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08b7ae;
P_0c08b7ae: /* original 8b01, guest PC 0x0c08b7ae */
if(!s->budget--) { s->failed_pc=0x0c08b7aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b7b4; }
goto P_0c08b7b0;
P_0c08b7b0: /* original a001, guest PC 0x0c08b7b0 */
if(!s->budget--) { s->failed_pc=0x0c08b7b0u; return 0; }
r[2]=0x00000001u;
goto P_0c08b7b6;
P_0c08b7b2: /* original e201, guest PC 0x0c08b7b2 */
if(!s->budget--) { s->failed_pc=0x0c08b7b2u; return 0; }
r[2]=0x00000001u;
goto P_0c08b7b4;
P_0c08b7b4: /* original e200, guest PC 0x0c08b7b4 */
if(!s->budget--) { s->failed_pc=0x0c08b7b4u; return 0; }
r[2]=0x00000000u;
goto P_0c08b7b6;
P_0c08b7b6: /* original 9068, guest PC 0x0c08b7b6 */
if(!s->budget--) { s->failed_pc=0x0c08b7b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b88au,2);
goto P_0c08b7b8;
P_0c08b7b8: /* original 0d24, guest PC 0x0c08b7b8 */
if(!s->budget--) { s->failed_pc=0x0c08b7b8u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08b7ba;
P_0c08b7ba: /* original d034, guest PC 0x0c08b7ba */
if(!s->budget--) { s->failed_pc=0x0c08b7bau; return 0; }
r[0]=read(ram,0x0c08b88cu,4);
goto P_0c08b7bc;
P_0c08b7bc: /* original 4408, guest PC 0x0c08b7bc */
if(!s->budget--) { s->failed_pc=0x0c08b7bcu; return 0; }
r[4]<<=2;
goto P_0c08b7be;
P_0c08b7be: /* original 4e08, guest PC 0x0c08b7be */
if(!s->budget--) { s->failed_pc=0x0c08b7beu; return 0; }
r[14]<<=2;
goto P_0c08b7c0;
P_0c08b7c0: /* original 044e, guest PC 0x0c08b7c0 */
if(!s->budget--) { s->failed_pc=0x0c08b7c0u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08b7c2;
P_0c08b7c2: /* original 4e08, guest PC 0x0c08b7c2 */
if(!s->budget--) { s->failed_pc=0x0c08b7c2u; return 0; }
r[14]<<=2;
goto P_0c08b7c4;
P_0c08b7c4: /* original e50f, guest PC 0x0c08b7c4 */
if(!s->budget--) { s->failed_pc=0x0c08b7c4u; return 0; }
r[5]=0x0000000fu;
goto P_0c08b7c6;
P_0c08b7c6: /* original 3e4c, guest PC 0x0c08b7c6 */
if(!s->budget--) { s->failed_pc=0x0c08b7c6u; return 0; }
r[14]+=r[4];
goto P_0c08b7c8;
P_0c08b7c8: /* original 64c3, guest PC 0x0c08b7c8 */
if(!s->budget--) { s->failed_pc=0x0c08b7c8u; return 0; }
r[4]=r[12];
goto P_0c08b7ca;
P_0c08b7ca: /* original 742e, guest PC 0x0c08b7ca */
if(!s->budget--) { s->failed_pc=0x0c08b7cau; return 0; }
r[4]+=0x0000002eu;
goto P_0c08b7cc;
P_0c08b7cc: /* original 61e4, guest PC 0x0c08b7cc */
if(!s->budget--) { s->failed_pc=0x0c08b7ccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]+=1;
r[1]=tmp;
goto P_0c08b7ce;
P_0c08b7ce: /* original 75ff, guest PC 0x0c08b7ce */
if(!s->budget--) { s->failed_pc=0x0c08b7ceu; return 0; }
r[5]+=0xffffffffu;
goto P_0c08b7d0;
P_0c08b7d0: /* original 2558, guest PC 0x0c08b7d0 */
if(!s->budget--) { s->failed_pc=0x0c08b7d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08b7d2;
P_0c08b7d2: /* original 2410, guest PC 0x0c08b7d2 */
if(!s->budget--) { s->failed_pc=0x0c08b7d2u; return 0; }
write(ram,r[4],r[1],1);
goto P_0c08b7d4;
P_0c08b7d4: /* original 8ffa, guest PC 0x0c08b7d4 */
if(!s->budget--) { s->failed_pc=0x0c08b7d4u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c08b7cc; }
goto P_0c08b7d8;
P_0c08b7d6: /* original 7401, guest PC 0x0c08b7d6 */
if(!s->budget--) { s->failed_pc=0x0c08b7d6u; return 0; }
r[4]+=0x00000001u;
goto P_0c08b7d8;
P_0c08b7d8: /* original 7f04, guest PC 0x0c08b7d8 */
if(!s->budget--) { s->failed_pc=0x0c08b7d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c08b7da;
P_0c08b7da: /* original 62e0, guest PC 0x0c08b7da */
if(!s->budget--) { s->failed_pc=0x0c08b7dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c08b7dc;
P_0c08b7dc: /* original 4f26, guest PC 0x0c08b7dc */
if(!s->budget--) { s->failed_pc=0x0c08b7dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b7de;
P_0c08b7de: /* original 2420, guest PC 0x0c08b7de */
if(!s->budget--) { s->failed_pc=0x0c08b7deu; return 0; }
write(ram,r[4],r[2],1);
goto P_0c08b7e0;
P_0c08b7e0: /* original 6bf6, guest PC 0x0c08b7e0 */
if(!s->budget--) { s->failed_pc=0x0c08b7e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b7e2;
P_0c08b7e2: /* original 6cf6, guest PC 0x0c08b7e2 */
if(!s->budget--) { s->failed_pc=0x0c08b7e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b7e4;
P_0c08b7e4: /* original 6df6, guest PC 0x0c08b7e4 */
if(!s->budget--) { s->failed_pc=0x0c08b7e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b7e6;
P_0c08b7e6: /* original 000b, guest PC 0x0c08b7e6 */
if(!s->budget--) { s->failed_pc=0x0c08b7e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b7e8: /* original 6ef6, guest PC 0x0c08b7e8 */
if(!s->budget--) { s->failed_pc=0x0c08b7e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b7eau,s,ram);
P_0c08d406: /* original 4f22, guest PC 0x0c08d406 */
if(!s->budget--) { s->failed_pc=0x0c08d406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d408;
P_0c08d408: /* original 8801, guest PC 0x0c08d408 */
if(!s->budget--) { s->failed_pc=0x0c08d408u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d40a;
P_0c08d40a: /* original 8d1b, guest PC 0x0c08d40a */
if(!s->budget--) { s->failed_pc=0x0c08d40au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08d444; }
goto P_0c08d40e;
P_0c08d40c: /* original 6d53, guest PC 0x0c08d40c */
if(!s->budget--) { s->failed_pc=0x0c08d40cu; return 0; }
r[13]=r[5];
goto P_0c08d40e;
P_0c08d40e: /* original 60d2, guest PC 0x0c08d40e */
if(!s->budget--) { s->failed_pc=0x0c08d40eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08d410;
P_0c08d410: /* original cb01, guest PC 0x0c08d410 */
if(!s->budget--) { s->failed_pc=0x0c08d410u; return 0; }
r[0]|=1u;
goto P_0c08d412;
P_0c08d412: /* original 2d02, guest PC 0x0c08d412 */
if(!s->budget--) { s->failed_pc=0x0c08d412u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08d414;
P_0c08d414: /* original e028, guest PC 0x0c08d414 */
if(!s->budget--) { s->failed_pc=0x0c08d414u; return 0; }
r[0]=0x00000028u;
goto P_0c08d416;
P_0c08d416: /* original 921b, guest PC 0x0c08d416 */
if(!s->budget--) { s->failed_pc=0x0c08d416u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d450u,2);
goto P_0c08d418;
P_0c08d418: /* original 0e25, guest PC 0x0c08d418 */
if(!s->budget--) { s->failed_pc=0x0c08d418u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08d41a;
P_0c08d41a: /* original e200, guest PC 0x0c08d41a */
if(!s->budget--) { s->failed_pc=0x0c08d41au; return 0; }
r[2]=0x00000000u;
goto P_0c08d41c;
P_0c08d41c: /* original 03ed, guest PC 0x0c08d41c */
if(!s->budget--) { s->failed_pc=0x0c08d41cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08d41e;
P_0c08d41e: /* original e040, guest PC 0x0c08d41e */
if(!s->budget--) { s->failed_pc=0x0c08d41eu; return 0; }
r[0]=0x00000040u;
goto P_0c08d420;
P_0c08d420: /* original 633d, guest PC 0x0c08d420 */
if(!s->budget--) { s->failed_pc=0x0c08d420u; return 0; }
r[3]=r[3]&65535u;
goto P_0c08d422;
P_0c08d422: /* original 1d3d, guest PC 0x0c08d422 */
if(!s->budget--) { s->failed_pc=0x0c08d422u; return 0; }
write(ram,r[13]+52,r[3],4);
goto P_0c08d424;
P_0c08d424: /* original 0d26, guest PC 0x0c08d424 */
if(!s->budget--) { s->failed_pc=0x0c08d424u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c08d426;
P_0c08d426: /* original be97, guest PC 0x0c08d426 */
if(!s->budget--) { s->failed_pc=0x0c08d426u; return 0; }
target=0x0c08d158u; r[16]=0x0c08d42au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08d42au) { target=s->pc; goto dispatch; }
goto P_0c08d42a;
P_0c08d428: /* original 64d3, guest PC 0x0c08d428 */
if(!s->budget--) { s->failed_pc=0x0c08d428u; return 0; }
r[4]=r[13];
goto P_0c08d42a;
P_0c08d42a: /* original e200, guest PC 0x0c08d42a */
if(!s->budget--) { s->failed_pc=0x0c08d42au; return 0; }
r[2]=0x00000000u;
goto P_0c08d42c;
P_0c08d42c: /* original 54de, guest PC 0x0c08d42c */
if(!s->budget--) { s->failed_pc=0x0c08d42cu; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08d42e;
P_0c08d42e: /* original e02c, guest PC 0x0c08d42e */
if(!s->budget--) { s->failed_pc=0x0c08d42eu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d430;
P_0c08d430: /* original 55df, guest PC 0x0c08d430 */
if(!s->budget--) { s->failed_pc=0x0c08d430u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08d432;
P_0c08d432: /* original 0e24, guest PC 0x0c08d432 */
if(!s->budget--) { s->failed_pc=0x0c08d432u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08d434;
P_0c08d434: /* original e02d, guest PC 0x0c08d434 */
if(!s->budget--) { s->failed_pc=0x0c08d434u; return 0; }
r[0]=0x0000002du;
goto P_0c08d436;
P_0c08d436: /* original 0e44, guest PC 0x0c08d436 */
if(!s->budget--) { s->failed_pc=0x0c08d436u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08d438;
P_0c08d438: /* original 6053, guest PC 0x0c08d438 */
if(!s->budget--) { s->failed_pc=0x0c08d438u; return 0; }
r[0]=r[5];
goto P_0c08d43a;
P_0c08d43a: /* original 81ea, guest PC 0x0c08d43a */
if(!s->budget--) { s->failed_pc=0x0c08d43au; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08d43c;
P_0c08d43c: /* original e048, guest PC 0x0c08d43c */
if(!s->budget--) { s->failed_pc=0x0c08d43cu; return 0; }
r[0]=0x00000048u;
goto P_0c08d43e;
P_0c08d43e: /* original 03ec, guest PC 0x0c08d43e */
if(!s->budget--) { s->failed_pc=0x0c08d43eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d440;
P_0c08d440: /* original 7301, guest PC 0x0c08d440 */
if(!s->budget--) { s->failed_pc=0x0c08d440u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d442;
P_0c08d442: /* original 0e34, guest PC 0x0c08d442 */
if(!s->budget--) { s->failed_pc=0x0c08d442u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08d444;
P_0c08d444: /* original 4f26, guest PC 0x0c08d444 */
if(!s->budget--) { s->failed_pc=0x0c08d444u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d446;
P_0c08d446: /* original 6df6, guest PC 0x0c08d446 */
if(!s->budget--) { s->failed_pc=0x0c08d446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d448;
P_0c08d448: /* original 000b, guest PC 0x0c08d448 */
if(!s->budget--) { s->failed_pc=0x0c08d448u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d44a: /* original 6ef6, guest PC 0x0c08d44a */
if(!s->budget--) { s->failed_pc=0x0c08d44au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08d44cu,s,ram);
P_0c08f344: /* original 4f22, guest PC 0x0c08f344 */
if(!s->budget--) { s->failed_pc=0x0c08f344u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f346;
P_0c08f346: /* original f549, guest PC 0x0c08f346 */
if(!s->budget--) { s->failed_pc=0x0c08f346u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08f348;
P_0c08f348: /* original fd49, guest PC 0x0c08f348 */
if(!s->budget--) { s->failed_pc=0x0c08f348u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c08f34a;
P_0c08f34a: /* original f562, guest PC 0x0c08f34a */
if(!s->budget--) { s->failed_pc=0x0c08f34au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c08f34c;
P_0c08f34c: /* original 7ff8, guest PC 0x0c08f34c */
if(!s->budget--) { s->failed_pc=0x0c08f34cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08f34e;
P_0c08f34e: /* original f448, guest PC 0x0c08f34e */
if(!s->budget--) { s->failed_pc=0x0c08f34eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c08f350;
P_0c08f350: /* original f462, guest PC 0x0c08f350 */
if(!s->budget--) { s->failed_pc=0x0c08f350u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c08f352;
P_0c08f352: /* original f608, guest PC 0x0c08f352 */
if(!s->budget--) { s->failed_pc=0x0c08f352u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08f354;
P_0c08f354: /* original f562, guest PC 0x0c08f354 */
if(!s->budget--) { s->failed_pc=0x0c08f354u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c08f356;
P_0c08f356: /* original f53d, guest PC 0x0c08f356 */
if(!s->budget--) { s->failed_pc=0x0c08f356u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c08f358;
P_0c08f358: /* original 035a, guest PC 0x0c08f358 */
if(!s->budget--) { s->failed_pc=0x0c08f358u; return 0; }
r[3]=r[53];
goto P_0c08f35a;
P_0c08f35a: /* original 2f31, guest PC 0x0c08f35a */
if(!s->budget--) { s->failed_pc=0x0c08f35au; return 0; }
write(ram,r[15],r[3],2);
goto P_0c08f35c;
P_0c08f35c: /* original f34c, guest PC 0x0c08f35c */
if(!s->budget--) { s->failed_pc=0x0c08f35cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08f35e;
P_0c08f35e: /* original f362, guest PC 0x0c08f35e */
if(!s->budget--) { s->failed_pc=0x0c08f35eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c08f360;
P_0c08f360: /* original f33d, guest PC 0x0c08f360 */
if(!s->budget--) { s->failed_pc=0x0c08f360u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08f362;
P_0c08f362: /* original 005a, guest PC 0x0c08f362 */
if(!s->budget--) { s->failed_pc=0x0c08f362u; return 0; }
r[0]=r[53];
goto P_0c08f364;
P_0c08f364: /* original 81f2, guest PC 0x0c08f364 */
if(!s->budget--) { s->failed_pc=0x0c08f364u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c08f366;
P_0c08f366: /* original d219, guest PC 0x0c08f366 */
if(!s->budget--) { s->failed_pc=0x0c08f366u; return 0; }
r[2]=read(ram,0x0c08f3ccu,4);
goto P_0c08f368;
P_0c08f368: /* original 420b, guest PC 0x0c08f368 */
if(!s->budget--) { s->failed_pc=0x0c08f368u; return 0; }
target=r[2];
r[16]=0x0c08f36cu;
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f36cu) { target=s->pc; goto dispatch; }
goto P_0c08f36c;
P_0c08f36a: /* original 643f, guest PC 0x0c08f36a */
if(!s->budget--) { s->failed_pc=0x0c08f36au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c08f36c;
P_0c08f36c: /* original d317, guest PC 0x0c08f36c */
if(!s->budget--) { s->failed_pc=0x0c08f36cu; return 0; }
r[3]=read(ram,0x0c08f3ccu,4);
goto P_0c08f36e;
P_0c08f36e: /* original 85f2, guest PC 0x0c08f36e */
if(!s->budget--) { s->failed_pc=0x0c08f36eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08f370;
P_0c08f370: /* original ff0c, guest PC 0x0c08f370 */
if(!s->budget--) { s->failed_pc=0x0c08f370u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c08f372;
P_0c08f372: /* original 430b, guest PC 0x0c08f372 */
if(!s->budget--) { s->failed_pc=0x0c08f372u; return 0; }
target=r[3];
r[16]=0x0c08f376u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f376u) { target=s->pc; goto dispatch; }
goto P_0c08f376;
P_0c08f374: /* original 6403, guest PC 0x0c08f374 */
if(!s->budget--) { s->failed_pc=0x0c08f374u; return 0; }
r[4]=r[0];
goto P_0c08f376;
P_0c08f376: /* original f4ec, guest PC 0x0c08f376 */
if(!s->budget--) { s->failed_pc=0x0c08f376u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08f378;
P_0c08f378: /* original f4f2, guest PC 0x0c08f378 */
if(!s->budget--) { s->failed_pc=0x0c08f378u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c08f37a;
P_0c08f37a: /* original f3dc, guest PC 0x0c08f37a */
if(!s->budget--) { s->failed_pc=0x0c08f37au; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c08f37c;
P_0c08f37c: /* original 7f08, guest PC 0x0c08f37c */
if(!s->budget--) { s->failed_pc=0x0c08f37cu; return 0; }
r[15]+=0x00000008u;
goto P_0c08f37e;
P_0c08f37e: /* original f50c, guest PC 0x0c08f37e */
if(!s->budget--) { s->failed_pc=0x0c08f37eu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c08f380;
P_0c08f380: /* original f352, guest PC 0x0c08f380 */
if(!s->budget--) { s->failed_pc=0x0c08f380u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c08f382;
P_0c08f382: /* original f5fc, guest PC 0x0c08f382 */
if(!s->budget--) { s->failed_pc=0x0c08f382u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f384;
P_0c08f384: /* original e05c, guest PC 0x0c08f384 */
if(!s->budget--) { s->failed_pc=0x0c08f384u; return 0; }
r[0]=0x0000005cu;
goto P_0c08f386;
P_0c08f386: /* original f24c, guest PC 0x0c08f386 */
if(!s->budget--) { s->failed_pc=0x0c08f386u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c08f388;
P_0c08f388: /* original 4f26, guest PC 0x0c08f388 */
if(!s->budget--) { s->failed_pc=0x0c08f388u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f38a;
P_0c08f38a: /* original f43c, guest PC 0x0c08f38a */
if(!s->budget--) { s->failed_pc=0x0c08f38au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08f38c;
P_0c08f38c: /* original f421, guest PC 0x0c08f38c */
if(!s->budget--) { s->failed_pc=0x0c08f38cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c08f38e;
P_0c08f38e: /* original f30c, guest PC 0x0c08f38e */
if(!s->budget--) { s->failed_pc=0x0c08f38eu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c08f390;
P_0c08f390: /* original f531, guest PC 0x0c08f390 */
if(!s->budget--) { s->failed_pc=0x0c08f390u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c08f392;
P_0c08f392: /* original f453, guest PC 0x0c08f392 */
if(!s->budget--) { s->failed_pc=0x0c08f392u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c08f394;
P_0c08f394: /* original f5ec, guest PC 0x0c08f394 */
if(!s->budget--) { s->failed_pc=0x0c08f394u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f396;
P_0c08f396: /* original f540, guest PC 0x0c08f396 */
if(!s->budget--) { s->failed_pc=0x0c08f396u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c08f398;
P_0c08f398: /* original f35c, guest PC 0x0c08f398 */
if(!s->budget--) { s->failed_pc=0x0c08f398u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f39a;
P_0c08f39a: /* original f5fc, guest PC 0x0c08f39a */
if(!s->budget--) { s->failed_pc=0x0c08f39au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f39c;
P_0c08f39c: /* original f532, guest PC 0x0c08f39c */
if(!s->budget--) { s->failed_pc=0x0c08f39cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08f39e;
P_0c08f39e: /* original fee7, guest PC 0x0c08f39e */
if(!s->budget--) { s->failed_pc=0x0c08f39eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08f3a0;
P_0c08f3a0: /* original e060, guest PC 0x0c08f3a0 */
if(!s->budget--) { s->failed_pc=0x0c08f3a0u; return 0; }
r[0]=0x00000060u;
goto P_0c08f3a2;
P_0c08f3a2: /* original fed7, guest PC 0x0c08f3a2 */
if(!s->budget--) { s->failed_pc=0x0c08f3a2u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08f3a4;
P_0c08f3a4: /* original e064, guest PC 0x0c08f3a4 */
if(!s->budget--) { s->failed_pc=0x0c08f3a4u; return 0; }
r[0]=0x00000064u;
goto P_0c08f3a6;
P_0c08f3a6: /* original fe47, guest PC 0x0c08f3a6 */
if(!s->budget--) { s->failed_pc=0x0c08f3a6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08f3a8;
P_0c08f3a8: /* original e068, guest PC 0x0c08f3a8 */
if(!s->budget--) { s->failed_pc=0x0c08f3a8u; return 0; }
r[0]=0x00000068u;
goto P_0c08f3aa;
P_0c08f3aa: /* original fe57, guest PC 0x0c08f3aa */
if(!s->budget--) { s->failed_pc=0x0c08f3aau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08f3ac;
P_0c08f3ac: /* original fdf9, guest PC 0x0c08f3ac */
if(!s->budget--) { s->failed_pc=0x0c08f3acu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3ae;
P_0c08f3ae: /* original fef9, guest PC 0x0c08f3ae */
if(!s->budget--) { s->failed_pc=0x0c08f3aeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3b0;
P_0c08f3b0: /* original fff9, guest PC 0x0c08f3b0 */
if(!s->budget--) { s->failed_pc=0x0c08f3b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f3b2;
P_0c08f3b2: /* original 000b, guest PC 0x0c08f3b2 */
if(!s->budget--) { s->failed_pc=0x0c08f3b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f3b4: /* original 6ef6, guest PC 0x0c08f3b4 */
if(!s->budget--) { s->failed_pc=0x0c08f3b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f3b6u,s,ram);
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
goto P_0c08f4ae;
P_0c08f4ae: /* original 5641, guest PC 0x0c08f4ae */
if(!s->budget--) { s->failed_pc=0x0c08f4aeu; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c08f4b0;
P_0c08f4b0: /* original 6752, guest PC 0x0c08f4b0 */
if(!s->budget--) { s->failed_pc=0x0c08f4b0u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c08f4b2;
P_0c08f4b2: /* original 5061, guest PC 0x0c08f4b2 */
if(!s->budget--) { s->failed_pc=0x0c08f4b2u; return 0; }
r[0]=read(ram,r[6]+4,4);
goto P_0c08f4b4;
P_0c08f4b4: /* original 2672, guest PC 0x0c08f4b4 */
if(!s->budget--) { s->failed_pc=0x0c08f4b4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c08f4b6;
P_0c08f4b6: /* original 1651, guest PC 0x0c08f4b6 */
if(!s->budget--) { s->failed_pc=0x0c08f4b6u; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08f4b8;
P_0c08f4b8: /* original 2042, guest PC 0x0c08f4b8 */
if(!s->budget--) { s->failed_pc=0x0c08f4b8u; return 0; }
write(ram,r[0],r[4],4);
goto P_0c08f4ba;
P_0c08f4ba: /* original 1401, guest PC 0x0c08f4ba */
if(!s->budget--) { s->failed_pc=0x0c08f4bau; return 0; }
write(ram,r[4]+4,r[0],4);
goto P_0c08f4bc;
P_0c08f4bc: /* original 2562, guest PC 0x0c08f4bc */
if(!s->budget--) { s->failed_pc=0x0c08f4bcu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c08f4be;
P_0c08f4be: /* original 000b, guest PC 0x0c08f4be */
if(!s->budget--) { s->failed_pc=0x0c08f4beu; return 0; }
target=r[16];
write(ram,r[7]+4,r[6],4);
s->pc=target; return ram->oob==0;
P_0c08f4c0: /* original 1761, guest PC 0x0c08f4c0 */
if(!s->budget--) { s->failed_pc=0x0c08f4c0u; return 0; }
write(ram,r[7]+4,r[6],4);
return vf3_matrix_family(0x0c08f4c2u,s,ram);
P_0c08f4d6: /* original e600, guest PC 0x0c08f4d6 */
if(!s->budget--) { s->failed_pc=0x0c08f4d6u; return 0; }
r[6]=0x00000000u;
goto P_0c08f4d8;
P_0c08f4d8: /* original 2442, guest PC 0x0c08f4d8 */
if(!s->budget--) { s->failed_pc=0x0c08f4d8u; return 0; }
write(ram,r[4],r[4],4);
goto P_0c08f4da;
P_0c08f4da: /* original 3560, guest PC 0x0c08f4da */
if(!s->budget--) { s->failed_pc=0x0c08f4dau; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c08f4dc;
P_0c08f4dc: /* original 1441, guest PC 0x0c08f4dc */
if(!s->budget--) { s->failed_pc=0x0c08f4dcu; return 0; }
write(ram,r[4]+4,r[4],4);
goto P_0c08f4de;
P_0c08f4de: /* original 8d0c, guest PC 0x0c08f4de */
if(!s->budget--) { s->failed_pc=0x0c08f4deu; return 0; }
cond=r[17]&1u;
write(ram,r[4]+8,r[6],4);
if(cond) { goto P_0c08f4fa; }
goto P_0c08f4e2;
P_0c08f4e0: /* original 1462, guest PC 0x0c08f4e0 */
if(!s->budget--) { s->failed_pc=0x0c08f4e0u; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c08f4e2;
P_0c08f4e2: /* original 6643, guest PC 0x0c08f4e2 */
if(!s->budget--) { s->failed_pc=0x0c08f4e2u; return 0; }
r[6]=r[4];
goto P_0c08f4e4;
P_0c08f4e4: /* original 6053, guest PC 0x0c08f4e4 */
if(!s->budget--) { s->failed_pc=0x0c08f4e4u; return 0; }
r[0]=r[5];
goto P_0c08f4e6;
P_0c08f4e6: /* original 760c, guest PC 0x0c08f4e6 */
if(!s->budget--) { s->failed_pc=0x0c08f4e6u; return 0; }
r[6]+=0x0000000cu;
goto P_0c08f4e8;
P_0c08f4e8: /* original 6743, guest PC 0x0c08f4e8 */
if(!s->budget--) { s->failed_pc=0x0c08f4e8u; return 0; }
r[7]=r[4];
goto P_0c08f4ea;
P_0c08f4ea: /* original 1761, guest PC 0x0c08f4ea */
if(!s->budget--) { s->failed_pc=0x0c08f4eau; return 0; }
write(ram,r[7]+4,r[6],4);
goto P_0c08f4ec;
P_0c08f4ec: /* original 4010, guest PC 0x0c08f4ec */
if(!s->budget--) { s->failed_pc=0x0c08f4ecu; return 0; }
--r[0];
r[17]=(r[17]&~1u)|((r[0]==0)!=0);
goto P_0c08f4ee;
P_0c08f4ee: /* original 2462, guest PC 0x0c08f4ee */
if(!s->budget--) { s->failed_pc=0x0c08f4eeu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c08f4f0;
P_0c08f4f0: /* original 1641, guest PC 0x0c08f4f0 */
if(!s->budget--) { s->failed_pc=0x0c08f4f0u; return 0; }
write(ram,r[6]+4,r[4],4);
goto P_0c08f4f2;
P_0c08f4f2: /* original 2672, guest PC 0x0c08f4f2 */
if(!s->budget--) { s->failed_pc=0x0c08f4f2u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c08f4f4;
P_0c08f4f4: /* original 6763, guest PC 0x0c08f4f4 */
if(!s->budget--) { s->failed_pc=0x0c08f4f4u; return 0; }
r[7]=r[6];
goto P_0c08f4f6;
P_0c08f4f6: /* original 8ff8, guest PC 0x0c08f4f6 */
if(!s->budget--) { s->failed_pc=0x0c08f4f6u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000000cu;
if(!cond) { goto P_0c08f4ea; }
goto P_0c08f4fa;
P_0c08f4f8: /* original 760c, guest PC 0x0c08f4f8 */
if(!s->budget--) { s->failed_pc=0x0c08f4f8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c08f4fa;
P_0c08f4fa: /* original 000b, guest PC 0x0c08f4fa */
if(!s->budget--) { s->failed_pc=0x0c08f4fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08f4fc: /* original 0009, guest PC 0x0c08f4fc */
if(!s->budget--) { s->failed_pc=0x0c08f4fcu; return 0; }
goto P_0c08f4fe;
P_0c08f4fe: /* original 931a, guest PC 0x0c08f4fe */
if(!s->budget--) { s->failed_pc=0x0c08f4feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f536u,2);
goto P_0c08f500;
P_0c08f500: /* original 7ff8, guest PC 0x0c08f500 */
if(!s->budget--) { s->failed_pc=0x0c08f500u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08f502;
P_0c08f502: /* original 334c, guest PC 0x0c08f502 */
if(!s->budget--) { s->failed_pc=0x0c08f502u; return 0; }
r[3]+=r[4];
goto P_0c08f504;
P_0c08f504: /* original 2f32, guest PC 0x0c08f504 */
if(!s->budget--) { s->failed_pc=0x0c08f504u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08f506;
P_0c08f506: /* original 9217, guest PC 0x0c08f506 */
if(!s->budget--) { s->failed_pc=0x0c08f506u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f538u,2);
goto P_0c08f508;
P_0c08f508: /* original 324c, guest PC 0x0c08f508 */
if(!s->budget--) { s->failed_pc=0x0c08f508u; return 0; }
r[2]+=r[4];
goto P_0c08f50a;
P_0c08f50a: /* original 1f21, guest PC 0x0c08f50a */
if(!s->budget--) { s->failed_pc=0x0c08f50au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08f50c;
P_0c08f50c: /* original 9017, guest PC 0x0c08f50c */
if(!s->budget--) { s->failed_pc=0x0c08f50cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f53eu,2);
goto P_0c08f50e;
P_0c08f50e: /* original 9715, guest PC 0x0c08f50e */
if(!s->budget--) { s->failed_pc=0x0c08f50eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f53cu,2);
goto P_0c08f510;
P_0c08f510: /* original 064e, guest PC 0x0c08f510 */
if(!s->budget--) { s->failed_pc=0x0c08f510u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c08f512;
P_0c08f512: /* original 9312, guest PC 0x0c08f512 */
if(!s->budget--) { s->failed_pc=0x0c08f512u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f53au,2);
goto P_0c08f514;
P_0c08f514: /* original 374c, guest PC 0x0c08f514 */
if(!s->budget--) { s->failed_pc=0x0c08f514u; return 0; }
r[7]+=r[4];
goto P_0c08f516;
P_0c08f516: /* original 6563, guest PC 0x0c08f516 */
if(!s->budget--) { s->failed_pc=0x0c08f516u; return 0; }
r[5]=r[6];
goto P_0c08f518;
P_0c08f518: /* original 7520, guest PC 0x0c08f518 */
if(!s->budget--) { s->failed_pc=0x0c08f518u; return 0; }
r[5]+=0x00000020u;
goto P_0c08f51a;
P_0c08f51a: /* original 373c, guest PC 0x0c08f51a */
if(!s->budget--) { s->failed_pc=0x0c08f51au; return 0; }
r[7]+=r[3];
goto P_0c08f51c;
P_0c08f51c: /* original 3572, guest PC 0x0c08f51c */
if(!s->budget--) { s->failed_pc=0x0c08f51cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[7])!=0);
goto P_0c08f51e;
P_0c08f51e: /* original 8b00, guest PC 0x0c08f51e */
if(!s->budget--) { s->failed_pc=0x0c08f51eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f522; }
goto P_0c08f520;
P_0c08f520: /* original 7580, guest PC 0x0c08f520 */
if(!s->budget--) { s->failed_pc=0x0c08f520u; return 0; }
r[5]+=0xffffff80u;
goto P_0c08f522;
P_0c08f522: /* original 0456, guest PC 0x0c08f522 */
if(!s->budget--) { s->failed_pc=0x0c08f522u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c08f524;
P_0c08f524: /* original 900c, guest PC 0x0c08f524 */
if(!s->budget--) { s->failed_pc=0x0c08f524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f540u,2);
goto P_0c08f526;
P_0c08f526: /* original 044e, guest PC 0x0c08f526 */
if(!s->budget--) { s->failed_pc=0x0c08f526u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08f528;
P_0c08f528: /* original 1462, guest PC 0x0c08f528 */
if(!s->budget--) { s->failed_pc=0x0c08f528u; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c08f52a;
P_0c08f52a: /* original 64f2, guest PC 0x0c08f52a */
if(!s->budget--) { s->failed_pc=0x0c08f52au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08f52c;
P_0c08f52c: /* original 55f1, guest PC 0x0c08f52c */
if(!s->budget--) { s->failed_pc=0x0c08f52cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c08f52e;
P_0c08f52e: /* original afbe, guest PC 0x0c08f52e */
if(!s->budget--) { s->failed_pc=0x0c08f52eu; return 0; }
r[15]+=0x00000008u;
goto P_0c08f4ae;
P_0c08f530: /* original 7f08, guest PC 0x0c08f530 */
if(!s->budget--) { s->failed_pc=0x0c08f530u; return 0; }
r[15]+=0x00000008u;
return vf3_matrix_family(0x0c08f532u,s,ram);
P_0c08f5c2: /* original 4f22, guest PC 0x0c08f5c2 */
if(!s->budget--) { s->failed_pc=0x0c08f5c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f5c4;
P_0c08f5c4: /* original 9466, guest PC 0x0c08f5c4 */
if(!s->budget--) { s->failed_pc=0x0c08f5c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f694u,2);
goto P_0c08f5c6;
P_0c08f5c6: /* original e508, guest PC 0x0c08f5c6 */
if(!s->budget--) { s->failed_pc=0x0c08f5c6u; return 0; }
r[5]=0x00000008u;
goto P_0c08f5c8;
P_0c08f5c8: /* original bf85, guest PC 0x0c08f5c8 */
if(!s->budget--) { s->failed_pc=0x0c08f5c8u; return 0; }
target=0x0c08f4d6u; r[16]=0x0c08f5ccu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f5ccu) { target=s->pc; goto dispatch; }
goto P_0c08f5cc;
P_0c08f5ca: /* original 34ec, guest PC 0x0c08f5ca */
if(!s->budget--) { s->failed_pc=0x0c08f5cau; return 0; }
r[4]+=r[14];
goto P_0c08f5cc;
P_0c08f5cc: /* original 9463, guest PC 0x0c08f5cc */
if(!s->budget--) { s->failed_pc=0x0c08f5ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f696u,2);
goto P_0c08f5ce;
P_0c08f5ce: /* original e500, guest PC 0x0c08f5ce */
if(!s->budget--) { s->failed_pc=0x0c08f5ceu; return 0; }
r[5]=0x00000000u;
goto P_0c08f5d0;
P_0c08f5d0: /* original bf81, guest PC 0x0c08f5d0 */
if(!s->budget--) { s->failed_pc=0x0c08f5d0u; return 0; }
target=0x0c08f4d6u; r[16]=0x0c08f5d4u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f5d4u) { target=s->pc; goto dispatch; }
goto P_0c08f5d4;
P_0c08f5d2: /* original 34ec, guest PC 0x0c08f5d2 */
if(!s->budget--) { s->failed_pc=0x0c08f5d2u; return 0; }
r[4]+=r[14];
goto P_0c08f5d4;
P_0c08f5d4: /* original 9061, guest PC 0x0c08f5d4 */
if(!s->budget--) { s->failed_pc=0x0c08f5d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f69au,2);
goto P_0c08f5d6;
P_0c08f5d6: /* original f48d, guest PC 0x0c08f5d6 */
if(!s->budget--) { s->failed_pc=0x0c08f5d6u; return 0; }
fr[4]=0;
goto P_0c08f5d8;
P_0c08f5d8: /* original f54c, guest PC 0x0c08f5d8 */
if(!s->budget--) { s->failed_pc=0x0c08f5d8u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c08f5da;
P_0c08f5da: /* original f69d, guest PC 0x0c08f5da */
if(!s->budget--) { s->failed_pc=0x0c08f5dau; return 0; }
fr[6]=0x3f800000u;
goto P_0c08f5dc;
P_0c08f5dc: /* original f76c, guest PC 0x0c08f5dc */
if(!s->budget--) { s->failed_pc=0x0c08f5dcu; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c08f5de;
P_0c08f5de: /* original fe57, guest PC 0x0c08f5de */
if(!s->budget--) { s->failed_pc=0x0c08f5deu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08f5e0;
P_0c08f5e0: /* original 7004, guest PC 0x0c08f5e0 */
if(!s->budget--) { s->failed_pc=0x0c08f5e0u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f5e2;
P_0c08f5e2: /* original fe77, guest PC 0x0c08f5e2 */
if(!s->budget--) { s->failed_pc=0x0c08f5e2u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08f5e4;
P_0c08f5e4: /* original 70f0, guest PC 0x0c08f5e4 */
if(!s->budget--) { s->failed_pc=0x0c08f5e4u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c08f5e6;
P_0c08f5e6: /* original 9459, guest PC 0x0c08f5e6 */
if(!s->budget--) { s->failed_pc=0x0c08f5e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f69cu,2);
goto P_0c08f5e8;
P_0c08f5e8: /* original 34ec, guest PC 0x0c08f5e8 */
if(!s->budget--) { s->failed_pc=0x0c08f5e8u; return 0; }
r[4]+=r[14];
goto P_0c08f5ea;
P_0c08f5ea: /* original 0e46, guest PC 0x0c08f5ea */
if(!s->budget--) { s->failed_pc=0x0c08f5eau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08f5ec;
P_0c08f5ec: /* original e05c, guest PC 0x0c08f5ec */
if(!s->budget--) { s->failed_pc=0x0c08f5ecu; return 0; }
r[0]=0x0000005cu;
goto P_0c08f5ee;
P_0c08f5ee: /* original f7e6, guest PC 0x0c08f5ee */
if(!s->budget--) { s->failed_pc=0x0c08f5eeu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f5f0;
P_0c08f5f0: /* original c72c, guest PC 0x0c08f5f0 */
if(!s->budget--) { s->failed_pc=0x0c08f5f0u; return 0; }
r[0]=0x0c08f6a4u;
goto P_0c08f5f2;
P_0c08f5f2: /* original fa08, guest PC 0x0c08f5f2 */
if(!s->budget--) { s->failed_pc=0x0c08f5f2u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08f5f4;
P_0c08f5f4: /* original 9053, guest PC 0x0c08f5f4 */
if(!s->budget--) { s->failed_pc=0x0c08f5f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f69eu,2);
goto P_0c08f5f6;
P_0c08f5f6: /* original fb5c, guest PC 0x0c08f5f6 */
if(!s->budget--) { s->failed_pc=0x0c08f5f6u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c08f5f8;
P_0c08f5f8: /* original 04ee, guest PC 0x0c08f5f8 */
if(!s->budget--) { s->failed_pc=0x0c08f5f8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08f5fa;
P_0c08f5fa: /* original e004, guest PC 0x0c08f5fa */
if(!s->budget--) { s->failed_pc=0x0c08f5fau; return 0; }
r[0]=0x00000004u;
goto P_0c08f5fc;
P_0c08f5fc: /* original f96c, guest PC 0x0c08f5fc */
if(!s->budget--) { s->failed_pc=0x0c08f5fcu; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c08f5fe;
P_0c08f5fe: /* original f85c, guest PC 0x0c08f5fe */
if(!s->budget--) { s->failed_pc=0x0c08f5feu; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c08f600;
P_0c08f600: /* original f4ba, guest PC 0x0c08f600 */
if(!s->budget--) { s->failed_pc=0x0c08f600u; return 0; }
vf3_matrix_store(s,ram,11,r[4]);
goto P_0c08f602;
P_0c08f602: /* original f477, guest PC 0x0c08f602 */
if(!s->budget--) { s->failed_pc=0x0c08f602u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08f604;
P_0c08f604: /* original e008, guest PC 0x0c08f604 */
if(!s->budget--) { s->failed_pc=0x0c08f604u; return 0; }
r[0]=0x00000008u;
goto P_0c08f606;
P_0c08f606: /* original f4b7, guest PC 0x0c08f606 */
if(!s->budget--) { s->failed_pc=0x0c08f606u; return 0; }
vf3_matrix_store(s,ram,11,r[4]+r[0]);
goto P_0c08f608;
P_0c08f608: /* original e00c, guest PC 0x0c08f608 */
if(!s->budget--) { s->failed_pc=0x0c08f608u; return 0; }
r[0]=0x0000000cu;
goto P_0c08f60a;
P_0c08f60a: /* original f497, guest PC 0x0c08f60a */
if(!s->budget--) { s->failed_pc=0x0c08f60au; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08f60c;
P_0c08f60c: /* original e010, guest PC 0x0c08f60c */
if(!s->budget--) { s->failed_pc=0x0c08f60cu; return 0; }
r[0]=0x00000010u;
goto P_0c08f60e;
P_0c08f60e: /* original f4a7, guest PC 0x0c08f60e */
if(!s->budget--) { s->failed_pc=0x0c08f60eu; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08f610;
P_0c08f610: /* original e014, guest PC 0x0c08f610 */
if(!s->budget--) { s->failed_pc=0x0c08f610u; return 0; }
r[0]=0x00000014u;
goto P_0c08f612;
P_0c08f612: /* original f4b7, guest PC 0x0c08f612 */
if(!s->budget--) { s->failed_pc=0x0c08f612u; return 0; }
vf3_matrix_store(s,ram,11,r[4]+r[0]);
goto P_0c08f614;
P_0c08f614: /* original e018, guest PC 0x0c08f614 */
if(!s->budget--) { s->failed_pc=0x0c08f614u; return 0; }
r[0]=0x00000018u;
goto P_0c08f616;
P_0c08f616: /* original f497, guest PC 0x0c08f616 */
if(!s->budget--) { s->failed_pc=0x0c08f616u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08f618;
P_0c08f618: /* original e01c, guest PC 0x0c08f618 */
if(!s->budget--) { s->failed_pc=0x0c08f618u; return 0; }
r[0]=0x0000001cu;
goto P_0c08f61a;
P_0c08f61a: /* original f4b7, guest PC 0x0c08f61a */
if(!s->budget--) { s->failed_pc=0x0c08f61au; return 0; }
vf3_matrix_store(s,ram,11,r[4]+r[0]);
goto P_0c08f61c;
P_0c08f61c: /* original bf6f, guest PC 0x0c08f61c */
if(!s->budget--) { s->failed_pc=0x0c08f61cu; return 0; }
target=0x0c08f4feu; r[16]=0x0c08f620u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08f620u) { target=s->pc; goto dispatch; }
goto P_0c08f620;
P_0c08f61e: /* original 64e3, guest PC 0x0c08f61e */
if(!s->budget--) { s->failed_pc=0x0c08f61eu; return 0; }
r[4]=r[14];
goto P_0c08f620;
P_0c08f620: /* original 903e, guest PC 0x0c08f620 */
if(!s->budget--) { s->failed_pc=0x0c08f620u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f6a0u,2);
goto P_0c08f622;
P_0c08f622: /* original 4f26, guest PC 0x0c08f622 */
if(!s->budget--) { s->failed_pc=0x0c08f622u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f624;
P_0c08f624: /* original 04ee, guest PC 0x0c08f624 */
if(!s->budget--) { s->failed_pc=0x0c08f624u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08f626;
P_0c08f626: /* original 903c, guest PC 0x0c08f626 */
if(!s->budget--) { s->failed_pc=0x0c08f626u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f6a2u,2);
goto P_0c08f628;
P_0c08f628: /* original 0e46, guest PC 0x0c08f628 */
if(!s->budget--) { s->failed_pc=0x0c08f628u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08f62a;
P_0c08f62a: /* original 7004, guest PC 0x0c08f62a */
if(!s->budget--) { s->failed_pc=0x0c08f62au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f62c;
P_0c08f62c: /* original 0e46, guest PC 0x0c08f62c */
if(!s->budget--) { s->failed_pc=0x0c08f62cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08f62e;
P_0c08f62e: /* original 000b, guest PC 0x0c08f62e */
if(!s->budget--) { s->failed_pc=0x0c08f62eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08f630: /* original 6ef6, guest PC 0x0c08f630 */
if(!s->budget--) { s->failed_pc=0x0c08f630u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08f632u,s,ram);
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
P_0c0944f6: /* original 4f22, guest PC 0x0c0944f6 */
if(!s->budget--) { s->failed_pc=0x0c0944f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0944f8;
P_0c0944f8: /* original 7ffc, guest PC 0x0c0944f8 */
if(!s->budget--) { s->failed_pc=0x0c0944f8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0944fa;
P_0c0944fa: /* original 2f42, guest PC 0x0c0944fa */
if(!s->budget--) { s->failed_pc=0x0c0944fau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0944fc;
P_0c0944fc: /* original d313, guest PC 0x0c0944fc */
if(!s->budget--) { s->failed_pc=0x0c0944fcu; return 0; }
r[3]=read(ram,0x0c09454cu,4);
goto P_0c0944fe;
P_0c0944fe: /* original 6e32, guest PC 0x0c0944fe */
if(!s->budget--) { s->failed_pc=0x0c0944feu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c094500;
P_0c094500: /* original 85e8, guest PC 0x0c094500 */
if(!s->budget--) { s->failed_pc=0x0c094500u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c094502;
P_0c094502: /* original cb01, guest PC 0x0c094502 */
if(!s->budget--) { s->failed_pc=0x0c094502u; return 0; }
r[0]|=1u;
goto P_0c094504;
P_0c094504: /* original 81e8, guest PC 0x0c094504 */
if(!s->budget--) { s->failed_pc=0x0c094504u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c094506;
P_0c094506: /* original 61e2, guest PC 0x0c094506 */
if(!s->budget--) { s->failed_pc=0x0c094506u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c094508;
P_0c094508: /* original 2129, guest PC 0x0c094508 */
if(!s->budget--) { s->failed_pc=0x0c094508u; return 0; }
r[1]&=r[2];
goto P_0c09450a;
P_0c09450a: /* original 2e12, guest PC 0x0c09450a */
if(!s->budget--) { s->failed_pc=0x0c09450au; return 0; }
write(ram,r[14],r[1],4);
goto P_0c09450c;
P_0c09450c: /* original d110, guest PC 0x0c09450c */
if(!s->budget--) { s->failed_pc=0x0c09450cu; return 0; }
r[1]=read(ram,0x0c094550u,4);
goto P_0c09450e;
P_0c09450e: /* original 65f2, guest PC 0x0c09450e */
if(!s->budget--) { s->failed_pc=0x0c09450eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c094510;
P_0c094510: /* original 410b, guest PC 0x0c094510 */
if(!s->budget--) { s->failed_pc=0x0c094510u; return 0; }
target=r[1];
r[16]=0x0c094514u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094514u) { target=s->pc; goto dispatch; }
goto P_0c094514;
P_0c094512: /* original 64e3, guest PC 0x0c094512 */
if(!s->budget--) { s->failed_pc=0x0c094512u; return 0; }
r[4]=r[14];
goto P_0c094514;
P_0c094514: /* original d30f, guest PC 0x0c094514 */
if(!s->budget--) { s->failed_pc=0x0c094514u; return 0; }
r[3]=read(ram,0x0c094554u,4);
goto P_0c094516;
P_0c094516: /* original 65f2, guest PC 0x0c094516 */
if(!s->budget--) { s->failed_pc=0x0c094516u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c094518;
P_0c094518: /* original 430b, guest PC 0x0c094518 */
if(!s->budget--) { s->failed_pc=0x0c094518u; return 0; }
target=r[3];
r[16]=0x0c09451cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09451cu) { target=s->pc; goto dispatch; }
goto P_0c09451c;
P_0c09451a: /* original 64e3, guest PC 0x0c09451a */
if(!s->budget--) { s->failed_pc=0x0c09451au; return 0; }
r[4]=r[14];
goto P_0c09451c;
P_0c09451c: /* original 7f04, guest PC 0x0c09451c */
if(!s->budget--) { s->failed_pc=0x0c09451cu; return 0; }
r[15]+=0x00000004u;
goto P_0c09451e;
P_0c09451e: /* original 60e2, guest PC 0x0c09451e */
if(!s->budget--) { s->failed_pc=0x0c09451eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c094520;
P_0c094520: /* original 4f26, guest PC 0x0c094520 */
if(!s->budget--) { s->failed_pc=0x0c094520u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094522;
P_0c094522: /* original cb01, guest PC 0x0c094522 */
if(!s->budget--) { s->failed_pc=0x0c094522u; return 0; }
r[0]|=1u;
goto P_0c094524;
P_0c094524: /* original 2e02, guest PC 0x0c094524 */
if(!s->budget--) { s->failed_pc=0x0c094524u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c094526;
P_0c094526: /* original 000b, guest PC 0x0c094526 */
if(!s->budget--) { s->failed_pc=0x0c094526u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094528: /* original 6ef6, guest PC 0x0c094528 */
if(!s->budget--) { s->failed_pc=0x0c094528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09452au,s,ram);
P_0c0a7450: /* original 4f22, guest PC 0x0c0a7450 */
if(!s->budget--) { s->failed_pc=0x0c0a7450u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7452;
P_0c0a7452: /* original e635, guest PC 0x0c0a7452 */
if(!s->budget--) { s->failed_pc=0x0c0a7452u; return 0; }
r[6]=0x00000035u;
goto P_0c0a7454;
P_0c0a7454: /* original 7ffc, guest PC 0x0c0a7454 */
if(!s->budget--) { s->failed_pc=0x0c0a7454u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7456;
P_0c0a7456: /* original 2f42, guest PC 0x0c0a7456 */
if(!s->budget--) { s->failed_pc=0x0c0a7456u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a7458;
P_0c0a7458: /* original d41e, guest PC 0x0c0a7458 */
if(!s->budget--) { s->failed_pc=0x0c0a7458u; return 0; }
r[4]=read(ram,0x0c0a74d4u,4);
goto P_0c0a745a;
P_0c0a745a: /* original bef9, guest PC 0x0c0a745a */
if(!s->budget--) { s->failed_pc=0x0c0a745au; return 0; }
target=0x0c0a7250u; r[16]=0x0c0a745eu;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a745eu) { target=s->pc; goto dispatch; }
goto P_0c0a745e;
P_0c0a745c: /* original 65f2, guest PC 0x0c0a745c */
if(!s->budget--) { s->failed_pc=0x0c0a745cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0a745e;
P_0c0a745e: /* original d31d, guest PC 0x0c0a745e */
if(!s->budget--) { s->failed_pc=0x0c0a745eu; return 0; }
r[3]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7460;
P_0c0a7460: /* original 7f04, guest PC 0x0c0a7460 */
if(!s->budget--) { s->failed_pc=0x0c0a7460u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7462;
P_0c0a7462: /* original d21d, guest PC 0x0c0a7462 */
if(!s->budget--) { s->failed_pc=0x0c0a7462u; return 0; }
r[2]=read(ram,0x0c0a74d8u,4);
goto P_0c0a7464;
P_0c0a7464: /* original 6132, guest PC 0x0c0a7464 */
if(!s->budget--) { s->failed_pc=0x0c0a7464u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a7466;
P_0c0a7466: /* original 4f26, guest PC 0x0c0a7466 */
if(!s->budget--) { s->failed_pc=0x0c0a7466u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7468;
P_0c0a7468: /* original 212b, guest PC 0x0c0a7468 */
if(!s->budget--) { s->failed_pc=0x0c0a7468u; return 0; }
r[1]|=r[2];
goto P_0c0a746a;
P_0c0a746a: /* original 2312, guest PC 0x0c0a746a */
if(!s->budget--) { s->failed_pc=0x0c0a746au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a746c;
P_0c0a746c: /* original 000b, guest PC 0x0c0a746c */
if(!s->budget--) { s->failed_pc=0x0c0a746cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a746e: /* original 0009, guest PC 0x0c0a746e */
if(!s->budget--) { s->failed_pc=0x0c0a746eu; return 0; }
return vf3_matrix_family(0x0c0a7470u,s,ram);
P_0c0abb2a: /* original 4f22, guest PC 0x0c0abb2a */
if(!s->budget--) { s->failed_pc=0x0c0abb2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb2c;
P_0c0abb2c: /* original b0de, guest PC 0x0c0abb2c */
if(!s->budget--) { s->failed_pc=0x0c0abb2cu; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abb30u;
r[13]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abb30u) { target=s->pc; goto dispatch; }
goto P_0c0abb30;
P_0c0abb2e: /* original 6d53, guest PC 0x0c0abb2e */
if(!s->budget--) { s->failed_pc=0x0c0abb2eu; return 0; }
r[13]=r[5];
goto P_0c0abb30;
P_0c0abb30: /* original e03e, guest PC 0x0c0abb30 */
if(!s->budget--) { s->failed_pc=0x0c0abb30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb32;
P_0c0abb32: /* original 04ed, guest PC 0x0c0abb32 */
if(!s->budget--) { s->failed_pc=0x0c0abb32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb34;
P_0c0abb34: /* original 9054, guest PC 0x0c0abb34 */
if(!s->budget--) { s->failed_pc=0x0c0abb34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe0u,2);
goto P_0c0abb36;
P_0c0abb36: /* original 644d, guest PC 0x0c0abb36 */
if(!s->budget--) { s->failed_pc=0x0c0abb36u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0abb38;
P_0c0abb38: /* original 05ed, guest PC 0x0c0abb38 */
if(!s->budget--) { s->failed_pc=0x0c0abb38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb3a;
P_0c0abb3a: /* original 9052, guest PC 0x0c0abb3a */
if(!s->budget--) { s->failed_pc=0x0c0abb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abb3c;
P_0c0abb3c: /* original 3450, guest PC 0x0c0abb3c */
if(!s->budget--) { s->failed_pc=0x0c0abb3cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0abb3e;
P_0c0abb3e: /* original 06ed, guest PC 0x0c0abb3e */
if(!s->budget--) { s->failed_pc=0x0c0abb3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb40;
P_0c0abb40: /* original 8f03, guest PC 0x0c0abb40 */
if(!s->budget--) { s->failed_pc=0x0c0abb40u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&65535u;
if(!cond) { goto P_0c0abb4a; }
goto P_0c0abb44;
P_0c0abb42: /* original 666d, guest PC 0x0c0abb42 */
if(!s->budget--) { s->failed_pc=0x0c0abb42u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0abb44;
P_0c0abb44: /* original e03e, guest PC 0x0c0abb44 */
if(!s->budget--) { s->failed_pc=0x0c0abb44u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb46;
P_0c0abb46: /* original 7401, guest PC 0x0c0abb46 */
if(!s->budget--) { s->failed_pc=0x0c0abb46u; return 0; }
r[4]+=0x00000001u;
goto P_0c0abb48;
P_0c0abb48: /* original 0e45, guest PC 0x0c0abb48 */
if(!s->budget--) { s->failed_pc=0x0c0abb48u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abb4a;
P_0c0abb4a: /* original 3462, guest PC 0x0c0abb4a */
if(!s->budget--) { s->failed_pc=0x0c0abb4au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c0abb4c;
P_0c0abb4c: /* original 8b15, guest PC 0x0c0abb4c */
if(!s->budget--) { s->failed_pc=0x0c0abb4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb7a; }
goto P_0c0abb4e;
P_0c0abb4e: /* original e204, guest PC 0x0c0abb4e */
if(!s->budget--) { s->failed_pc=0x0c0abb4eu; return 0; }
r[2]=0x00000004u;
goto P_0c0abb50;
P_0c0abb50: /* original 65d3, guest PC 0x0c0abb50 */
if(!s->budget--) { s->failed_pc=0x0c0abb50u; return 0; }
r[5]=r[13];
goto P_0c0abb52;
P_0c0abb52: /* original 6323, guest PC 0x0c0abb52 */
if(!s->budget--) { s->failed_pc=0x0c0abb52u; return 0; }
r[3]=r[2];
goto P_0c0abb54;
P_0c0abb54: /* original e062, guest PC 0x0c0abb54 */
if(!s->budget--) { s->failed_pc=0x0c0abb54u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb56;
P_0c0abb56: /* original 1d22, guest PC 0x0c0abb56 */
if(!s->budget--) { s->failed_pc=0x0c0abb56u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb58;
P_0c0abb58: /* original 64e3, guest PC 0x0c0abb58 */
if(!s->budget--) { s->failed_pc=0x0c0abb58u; return 0; }
r[4]=r[14];
goto P_0c0abb5a;
P_0c0abb5a: /* original 0e34, guest PC 0x0c0abb5a */
if(!s->budget--) { s->failed_pc=0x0c0abb5au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb5c;
P_0c0abb5c: /* original e048, guest PC 0x0c0abb5c */
if(!s->budget--) { s->failed_pc=0x0c0abb5cu; return 0; }
r[0]=0x00000048u;
goto P_0c0abb5e;
P_0c0abb5e: /* original 62d2, guest PC 0x0c0abb5e */
if(!s->budget--) { s->failed_pc=0x0c0abb5eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abb60;
P_0c0abb60: /* original d323, guest PC 0x0c0abb60 */
if(!s->budget--) { s->failed_pc=0x0c0abb60u; return 0; }
r[3]=read(ram,0x0c0abbf0u,4);
goto P_0c0abb62;
P_0c0abb62: /* original 4f26, guest PC 0x0c0abb62 */
if(!s->budget--) { s->failed_pc=0x0c0abb62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb64;
P_0c0abb64: /* original 223b, guest PC 0x0c0abb64 */
if(!s->budget--) { s->failed_pc=0x0c0abb64u; return 0; }
r[2]|=r[3];
goto P_0c0abb66;
P_0c0abb66: /* original 2d22, guest PC 0x0c0abb66 */
if(!s->budget--) { s->failed_pc=0x0c0abb66u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0abb68;
P_0c0abb68: /* original 01ee, guest PC 0x0c0abb68 */
if(!s->budget--) { s->failed_pc=0x0c0abb68u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0abb6a;
P_0c0abb6a: /* original d222, guest PC 0x0c0abb6a */
if(!s->budget--) { s->failed_pc=0x0c0abb6au; return 0; }
r[2]=read(ram,0x0c0abbf4u,4);
goto P_0c0abb6c;
P_0c0abb6c: /* original 212b, guest PC 0x0c0abb6c */
if(!s->budget--) { s->failed_pc=0x0c0abb6cu; return 0; }
r[1]|=r[2];
goto P_0c0abb6e;
P_0c0abb6e: /* original 0e16, guest PC 0x0c0abb6e */
if(!s->budget--) { s->failed_pc=0x0c0abb6eu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0abb70;
P_0c0abb70: /* original 60d2, guest PC 0x0c0abb70 */
if(!s->budget--) { s->failed_pc=0x0c0abb70u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0abb72;
P_0c0abb72: /* original 2e02, guest PC 0x0c0abb72 */
if(!s->budget--) { s->failed_pc=0x0c0abb72u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0abb74;
P_0c0abb74: /* original 6df6, guest PC 0x0c0abb74 */
if(!s->budget--) { s->failed_pc=0x0c0abb74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb76;
P_0c0abb76: /* original a004, guest PC 0x0c0abb76 */
if(!s->budget--) { s->failed_pc=0x0c0abb76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb78: /* original 6ef6, guest PC 0x0c0abb78 */
if(!s->budget--) { s->failed_pc=0x0c0abb78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb7a;
P_0c0abb7a: /* original 4f26, guest PC 0x0c0abb7a */
if(!s->budget--) { s->failed_pc=0x0c0abb7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb7c;
P_0c0abb7c: /* original 6df6, guest PC 0x0c0abb7c */
if(!s->budget--) { s->failed_pc=0x0c0abb7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb7e;
P_0c0abb7e: /* original 000b, guest PC 0x0c0abb7e */
if(!s->budget--) { s->failed_pc=0x0c0abb7eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb80: /* original 6ef6, guest PC 0x0c0abb80 */
if(!s->budget--) { s->failed_pc=0x0c0abb80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb82: /* original 2fe6, guest PC 0x0c0abb82 */
if(!s->budget--) { s->failed_pc=0x0c0abb82u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0abb84;
P_0c0abb84: /* original e048, guest PC 0x0c0abb84 */
if(!s->budget--) { s->failed_pc=0x0c0abb84u; return 0; }
r[0]=0x00000048u;
goto P_0c0abb86;
P_0c0abb86: /* original 6e43, guest PC 0x0c0abb86 */
if(!s->budget--) { s->failed_pc=0x0c0abb86u; return 0; }
r[14]=r[4];
goto P_0c0abb88;
P_0c0abb88: /* original 02ee, guest PC 0x0c0abb88 */
if(!s->budget--) { s->failed_pc=0x0c0abb88u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0abb8a;
P_0c0abb8a: /* original d31b, guest PC 0x0c0abb8a */
if(!s->budget--) { s->failed_pc=0x0c0abb8au; return 0; }
r[3]=read(ram,0x0c0abbf8u,4);
goto P_0c0abb8c;
P_0c0abb8c: /* original 4f22, guest PC 0x0c0abb8c */
if(!s->budget--) { s->failed_pc=0x0c0abb8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb8e;
P_0c0abb8e: /* original 2239, guest PC 0x0c0abb8e */
if(!s->budget--) { s->failed_pc=0x0c0abb8eu; return 0; }
r[2]&=r[3];
goto P_0c0abb90;
P_0c0abb90: /* original 0e26, guest PC 0x0c0abb90 */
if(!s->budget--) { s->failed_pc=0x0c0abb90u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0abb92;
P_0c0abb92: /* original b0ab, guest PC 0x0c0abb92 */
if(!s->budget--) { s->failed_pc=0x0c0abb92u; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abb96u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abb96u) { target=s->pc; goto dispatch; }
goto P_0c0abb96;
P_0c0abb94: /* original 64e3, guest PC 0x0c0abb94 */
if(!s->budget--) { s->failed_pc=0x0c0abb94u; return 0; }
r[4]=r[14];
goto P_0c0abb96;
P_0c0abb96: /* original e024, guest PC 0x0c0abb96 */
if(!s->budget--) { s->failed_pc=0x0c0abb96u; return 0; }
r[0]=0x00000024u;
goto P_0c0abb98;
P_0c0abb98: /* original f48d, guest PC 0x0c0abb98 */
if(!s->budget--) { s->failed_pc=0x0c0abb98u; return 0; }
fr[4]=0;
goto P_0c0abb9a;
P_0c0abb9a: /* original fe47, guest PC 0x0c0abb9a */
if(!s->budget--) { s->failed_pc=0x0c0abb9au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abb9c;
P_0c0abb9c: /* original e02c, guest PC 0x0c0abb9c */
if(!s->budget--) { s->failed_pc=0x0c0abb9cu; return 0; }
r[0]=0x0000002cu;
goto P_0c0abb9e;
P_0c0abb9e: /* original fe47, guest PC 0x0c0abb9e */
if(!s->budget--) { s->failed_pc=0x0c0abb9eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba0;
P_0c0abba0: /* original 9020, guest PC 0x0c0abba0 */
if(!s->budget--) { s->failed_pc=0x0c0abba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe4u,2);
goto P_0c0abba2;
P_0c0abba2: /* original 4f26, guest PC 0x0c0abba2 */
if(!s->budget--) { s->failed_pc=0x0c0abba2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abba4;
P_0c0abba4: /* original fe47, guest PC 0x0c0abba4 */
if(!s->budget--) { s->failed_pc=0x0c0abba4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba6;
P_0c0abba6: /* original 7004, guest PC 0x0c0abba6 */
if(!s->budget--) { s->failed_pc=0x0c0abba6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0abba8;
P_0c0abba8: /* original fe47, guest PC 0x0c0abba8 */
if(!s->budget--) { s->failed_pc=0x0c0abba8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbaa;
P_0c0abbaa: /* original 7004, guest PC 0x0c0abbaa */
if(!s->budget--) { s->failed_pc=0x0c0abbaau; return 0; }
r[0]+=0x00000004u;
goto P_0c0abbac;
P_0c0abbac: /* original fe47, guest PC 0x0c0abbac */
if(!s->budget--) { s->failed_pc=0x0c0abbacu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbae;
P_0c0abbae: /* original 9018, guest PC 0x0c0abbae */
if(!s->budget--) { s->failed_pc=0x0c0abbaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abbb0;
P_0c0abbb0: /* original 03ed, guest PC 0x0c0abbb0 */
if(!s->budget--) { s->failed_pc=0x0c0abbb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abbb2;
P_0c0abbb2: /* original e03e, guest PC 0x0c0abbb2 */
if(!s->budget--) { s->failed_pc=0x0c0abbb2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abbb4;
P_0c0abbb4: /* original 0e35, guest PC 0x0c0abbb4 */
if(!s->budget--) { s->failed_pc=0x0c0abbb4u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0abbb6;
P_0c0abbb6: /* original 000b, guest PC 0x0c0abbb6 */
if(!s->budget--) { s->failed_pc=0x0c0abbb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abbb8: /* original 6ef6, guest PC 0x0c0abbb8 */
if(!s->budget--) { s->failed_pc=0x0c0abbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abbbau,s,ram);
P_0c0abcec: /* original 9014, guest PC 0x0c0abcec */
if(!s->budget--) { s->failed_pc=0x0c0abcecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd18u,2);
goto P_0c0abcee;
P_0c0abcee: /* original f346, guest PC 0x0c0abcee */
if(!s->budget--) { s->failed_pc=0x0c0abceeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abcf0;
P_0c0abcf0: /* original 9013, guest PC 0x0c0abcf0 */
if(!s->budget--) { s->failed_pc=0x0c0abcf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd1au,2);
goto P_0c0abcf2;
P_0c0abcf2: /* original f446, guest PC 0x0c0abcf2 */
if(!s->budget--) { s->failed_pc=0x0c0abcf2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abcf4;
P_0c0abcf4: /* original e014, guest PC 0x0c0abcf4 */
if(!s->budget--) { s->failed_pc=0x0c0abcf4u; return 0; }
r[0]=0x00000014u;
goto P_0c0abcf6;
P_0c0abcf6: /* original f430, guest PC 0x0c0abcf6 */
if(!s->budget--) { s->failed_pc=0x0c0abcf6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0abcf8;
P_0c0abcf8: /* original f346, guest PC 0x0c0abcf8 */
if(!s->budget--) { s->failed_pc=0x0c0abcf8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abcfa;
P_0c0abcfa: /* original f345, guest PC 0x0c0abcfa */
if(!s->budget--) { s->failed_pc=0x0c0abcfau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abcfc;
P_0c0abcfc: /* original 8903, guest PC 0x0c0abcfc */
if(!s->budget--) { s->failed_pc=0x0c0abcfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abd06; }
goto P_0c0abcfe;
P_0c0abcfe: /* original f447, guest PC 0x0c0abcfe */
if(!s->budget--) { s->failed_pc=0x0c0abcfeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abd00;
P_0c0abd00: /* original e028, guest PC 0x0c0abd00 */
if(!s->budget--) { s->failed_pc=0x0c0abd00u; return 0; }
r[0]=0x00000028u;
goto P_0c0abd02;
P_0c0abd02: /* original f38d, guest PC 0x0c0abd02 */
if(!s->budget--) { s->failed_pc=0x0c0abd02u; return 0; }
fr[3]=0;
goto P_0c0abd04;
P_0c0abd04: /* original f437, guest PC 0x0c0abd04 */
if(!s->budget--) { s->failed_pc=0x0c0abd04u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abd06;
P_0c0abd06: /* original 000b, guest PC 0x0c0abd06 */
if(!s->budget--) { s->failed_pc=0x0c0abd06u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abd08: /* original 0009, guest PC 0x0c0abd08 */
if(!s->budget--) { s->failed_pc=0x0c0abd08u; return 0; }
return vf3_matrix_family(0x0c0abd0au,s,ram);
P_0c0c01b4: /* original 4f22, guest PC 0x0c0c01b4 */
if(!s->budget--) { s->failed_pc=0x0c0c01b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c01b6;
P_0c0c01b6: /* original 7ff4, guest PC 0x0c0c01b6 */
if(!s->budget--) { s->failed_pc=0x0c0c01b6u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c01b8;
P_0c0c01b8: /* original 2f42, guest PC 0x0c0c01b8 */
if(!s->budget--) { s->failed_pc=0x0c0c01b8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c01ba;
P_0c0c01ba: /* original d510, guest PC 0x0c0c01ba */
if(!s->budget--) { s->failed_pc=0x0c0c01bau; return 0; }
r[5]=read(ram,0x0c0c01fcu,4);
goto P_0c0c01bc;
P_0c0c01bc: /* original 5354, guest PC 0x0c0c01bc */
if(!s->budget--) { s->failed_pc=0x0c0c01bcu; return 0; }
r[3]=read(ram,r[5]+16,4);
goto P_0c0c01be;
P_0c0c01be: /* original 1f31, guest PC 0x0c0c01be */
if(!s->budget--) { s->failed_pc=0x0c0c01beu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c01c0;
P_0c0c01c0: /* original 5255, guest PC 0x0c0c01c0 */
if(!s->budget--) { s->failed_pc=0x0c0c01c0u; return 0; }
r[2]=read(ram,r[5]+20,4);
goto P_0c0c01c2;
P_0c0c01c2: /* original 1f22, guest PC 0x0c0c01c2 */
if(!s->budget--) { s->failed_pc=0x0c0c01c2u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0c01c4;
P_0c0c01c4: /* original 6623, guest PC 0x0c0c01c4 */
if(!s->budget--) { s->failed_pc=0x0c0c01c4u; return 0; }
r[6]=r[2];
goto P_0c0c01c6;
P_0c0c01c6: /* original b01f, guest PC 0x0c0c01c6 */
if(!s->budget--) { s->failed_pc=0x0c0c01c6u; return 0; }
target=0x0c0c0208u; r[16]=0x0c0c01cau;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c01cau) { target=s->pc; goto dispatch; }
goto P_0c0c01ca;
P_0c0c01c8: /* original 55f1, guest PC 0x0c0c01c8 */
if(!s->budget--) { s->failed_pc=0x0c0c01c8u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c01ca;
P_0c0c01ca: /* original 62f2, guest PC 0x0c0c01ca */
if(!s->budget--) { s->failed_pc=0x0c0c01cau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c01cc;
P_0c0c01cc: /* original 7f0c, guest PC 0x0c0c01cc */
if(!s->budget--) { s->failed_pc=0x0c0c01ccu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c01ce;
P_0c0c01ce: /* original 4f26, guest PC 0x0c0c01ce */
if(!s->budget--) { s->failed_pc=0x0c0c01ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c01d0;
P_0c0c01d0: /* original d30b, guest PC 0x0c0c01d0 */
if(!s->budget--) { s->failed_pc=0x0c0c01d0u; return 0; }
r[3]=read(ram,0x0c0c0200u,4);
goto P_0c0c01d2;
P_0c0c01d2: /* original 1233, guest PC 0x0c0c01d2 */
if(!s->budget--) { s->failed_pc=0x0c0c01d2u; return 0; }
write(ram,r[2]+12,r[3],4);
goto P_0c0c01d4;
P_0c0c01d4: /* original 000b, guest PC 0x0c0c01d4 */
if(!s->budget--) { s->failed_pc=0x0c0c01d4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c01d6: /* original 0009, guest PC 0x0c0c01d6 */
if(!s->budget--) { s->failed_pc=0x0c0c01d6u; return 0; }
goto P_0c0c01d8;
P_0c0c01d8: /* original 4f22, guest PC 0x0c0c01d8 */
if(!s->budget--) { s->failed_pc=0x0c0c01d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c01da;
P_0c0c01da: /* original 7ff4, guest PC 0x0c0c01da */
if(!s->budget--) { s->failed_pc=0x0c0c01dau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c01dc;
P_0c0c01dc: /* original 2f42, guest PC 0x0c0c01dc */
if(!s->budget--) { s->failed_pc=0x0c0c01dcu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c01de;
P_0c0c01de: /* original d507, guest PC 0x0c0c01de */
if(!s->budget--) { s->failed_pc=0x0c0c01deu; return 0; }
r[5]=read(ram,0x0c0c01fcu,4);
goto P_0c0c01e0;
P_0c0c01e0: /* original 5355, guest PC 0x0c0c01e0 */
if(!s->budget--) { s->failed_pc=0x0c0c01e0u; return 0; }
r[3]=read(ram,r[5]+20,4);
goto P_0c0c01e2;
P_0c0c01e2: /* original 1f31, guest PC 0x0c0c01e2 */
if(!s->budget--) { s->failed_pc=0x0c0c01e2u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c01e4;
P_0c0c01e4: /* original 5254, guest PC 0x0c0c01e4 */
if(!s->budget--) { s->failed_pc=0x0c0c01e4u; return 0; }
r[2]=read(ram,r[5]+16,4);
goto P_0c0c01e6;
P_0c0c01e6: /* original 1f22, guest PC 0x0c0c01e6 */
if(!s->budget--) { s->failed_pc=0x0c0c01e6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0c01e8;
P_0c0c01e8: /* original 6623, guest PC 0x0c0c01e8 */
if(!s->budget--) { s->failed_pc=0x0c0c01e8u; return 0; }
r[6]=r[2];
goto P_0c0c01ea;
P_0c0c01ea: /* original b00d, guest PC 0x0c0c01ea */
if(!s->budget--) { s->failed_pc=0x0c0c01eau; return 0; }
target=0x0c0c0208u; r[16]=0x0c0c01eeu;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c01eeu) { target=s->pc; goto dispatch; }
goto P_0c0c01ee;
P_0c0c01ec: /* original 55f1, guest PC 0x0c0c01ec */
if(!s->budget--) { s->failed_pc=0x0c0c01ecu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c01ee;
P_0c0c01ee: /* original 62f2, guest PC 0x0c0c01ee */
if(!s->budget--) { s->failed_pc=0x0c0c01eeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c01f0;
P_0c0c01f0: /* original 7f0c, guest PC 0x0c0c01f0 */
if(!s->budget--) { s->failed_pc=0x0c0c01f0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c01f2;
P_0c0c01f2: /* original 4f26, guest PC 0x0c0c01f2 */
if(!s->budget--) { s->failed_pc=0x0c0c01f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c01f4;
P_0c0c01f4: /* original d303, guest PC 0x0c0c01f4 */
if(!s->budget--) { s->failed_pc=0x0c0c01f4u; return 0; }
r[3]=read(ram,0x0c0c0204u,4);
goto P_0c0c01f6;
P_0c0c01f6: /* original 1233, guest PC 0x0c0c01f6 */
if(!s->budget--) { s->failed_pc=0x0c0c01f6u; return 0; }
write(ram,r[2]+12,r[3],4);
goto P_0c0c01f8;
P_0c0c01f8: /* original 000b, guest PC 0x0c0c01f8 */
if(!s->budget--) { s->failed_pc=0x0c0c01f8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c01fa: /* original 0009, guest PC 0x0c0c01fa */
if(!s->budget--) { s->failed_pc=0x0c0c01fau; return 0; }
return vf3_matrix_family(0x0c0c01fcu,s,ram);
P_0c0c0208: /* original 2fe6, guest PC 0x0c0c0208 */
if(!s->budget--) { s->failed_pc=0x0c0c0208u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c020a;
P_0c0c020a: /* original 6e43, guest PC 0x0c0c020a */
if(!s->budget--) { s->failed_pc=0x0c0c020au; return 0; }
r[14]=r[4];
goto P_0c0c020c;
P_0c0c020c: /* original 2fd6, guest PC 0x0c0c020c */
if(!s->budget--) { s->failed_pc=0x0c0c020cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c020e;
P_0c0c020e: /* original ed00, guest PC 0x0c0c020e */
if(!s->budget--) { s->failed_pc=0x0c0c020eu; return 0; }
r[13]=0x00000000u;
goto P_0c0c0210;
P_0c0c0210: /* original 2fc6, guest PC 0x0c0c0210 */
if(!s->budget--) { s->failed_pc=0x0c0c0210u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c0212;
P_0c0c0212: /* original 6c53, guest PC 0x0c0c0212 */
if(!s->budget--) { s->failed_pc=0x0c0c0212u; return 0; }
r[12]=r[5];
goto P_0c0c0214;
P_0c0c0214: /* original 2fb6, guest PC 0x0c0c0214 */
if(!s->budget--) { s->failed_pc=0x0c0c0214u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c0216;
P_0c0c0216: /* original fffb, guest PC 0x0c0c0216 */
if(!s->budget--) { s->failed_pc=0x0c0c0216u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c0218;
P_0c0c0218: /* original 4f22, guest PC 0x0c0c0218 */
if(!s->budget--) { s->failed_pc=0x0c0c0218u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c021a;
P_0c0c021a: /* original 7fc8, guest PC 0x0c0c021a */
if(!s->budget--) { s->failed_pc=0x0c0c021au; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0c021c;
P_0c0c021c: /* original 65f3, guest PC 0x0c0c021c */
if(!s->budget--) { s->failed_pc=0x0c0c021cu; return 0; }
r[5]=r[15];
goto P_0c0c021e;
P_0c0c021e: /* original 1f61, guest PC 0x0c0c021e */
if(!s->budget--) { s->failed_pc=0x0c0c021eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0c0220;
P_0c0c0220: /* original db62, guest PC 0x0c0c0220 */
if(!s->budget--) { s->failed_pc=0x0c0c0220u; return 0; }
r[11]=read(ram,0x0c0c03acu,4);
goto P_0c0c0222;
P_0c0c0222: /* original 7508, guest PC 0x0c0c0222 */
if(!s->budget--) { s->failed_pc=0x0c0c0222u; return 0; }
r[5]+=0x00000008u;
goto P_0c0c0224;
P_0c0c0224: /* original 2fd2, guest PC 0x0c0c0224 */
if(!s->budget--) { s->failed_pc=0x0c0c0224u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c0226;
P_0c0c0226: /* original ff8d, guest PC 0x0c0c0226 */
if(!s->budget--) { s->failed_pc=0x0c0c0226u; return 0; }
fr[15]=0;
goto P_0c0c0228;
P_0c0c0228: /* original b708, guest PC 0x0c0c0228 */
if(!s->budget--) { s->failed_pc=0x0c0c0228u; return 0; }
target=0x0c0c103cu; r[16]=0x0c0c022cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c022cu) { target=s->pc; goto dispatch; }
goto P_0c0c022c;
P_0c0c022a: /* original 64e3, guest PC 0x0c0c022a */
if(!s->budget--) { s->failed_pc=0x0c0c022au; return 0; }
r[4]=r[14];
goto P_0c0c022c;
P_0c0c022c: /* original e044, guest PC 0x0c0c022c */
if(!s->budget--) { s->failed_pc=0x0c0c022cu; return 0; }
r[0]=0x00000044u;
goto P_0c0c022e;
P_0c0c022e: /* original 0ed5, guest PC 0x0c0c022e */
if(!s->budget--) { s->failed_pc=0x0c0c022eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0230;
P_0c0c0230: /* original e046, guest PC 0x0c0c0230 */
if(!s->budget--) { s->failed_pc=0x0c0c0230u; return 0; }
r[0]=0x00000046u;
goto P_0c0c0232;
P_0c0c0232: /* original 0ed5, guest PC 0x0c0c0232 */
if(!s->budget--) { s->failed_pc=0x0c0c0232u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0234;
P_0c0c0234: /* original e048, guest PC 0x0c0c0234 */
if(!s->budget--) { s->failed_pc=0x0c0c0234u; return 0; }
r[0]=0x00000048u;
goto P_0c0c0236;
P_0c0c0236: /* original 0ed5, guest PC 0x0c0c0236 */
if(!s->budget--) { s->failed_pc=0x0c0c0236u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0238;
P_0c0c0238: /* original e040, guest PC 0x0c0c0238 */
if(!s->budget--) { s->failed_pc=0x0c0c0238u; return 0; }
r[0]=0x00000040u;
goto P_0c0c023a;
P_0c0c023a: /* original 63f2, guest PC 0x0c0c023a */
if(!s->budget--) { s->failed_pc=0x0c0c023au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c023c;
P_0c0c023c: /* original 0e36, guest PC 0x0c0c023c */
if(!s->budget--) { s->failed_pc=0x0c0c023cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c023e;
P_0c0c023e: /* original 60d3, guest PC 0x0c0c023e */
if(!s->budget--) { s->failed_pc=0x0c0c023eu; return 0; }
r[0]=r[13];
goto P_0c0c0240;
P_0c0c0240: /* original 81e3, guest PC 0x0c0c0240 */
if(!s->budget--) { s->failed_pc=0x0c0c0240u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c0c0242;
P_0c0c0242: /* original e04a, guest PC 0x0c0c0242 */
if(!s->budget--) { s->failed_pc=0x0c0c0242u; return 0; }
r[0]=0x0000004au;
goto P_0c0c0244;
P_0c0c0244: /* original 0ed4, guest PC 0x0c0c0244 */
if(!s->budget--) { s->failed_pc=0x0c0c0244u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c0246;
P_0c0c0246: /* original e04b, guest PC 0x0c0c0246 */
if(!s->budget--) { s->failed_pc=0x0c0c0246u; return 0; }
r[0]=0x0000004bu;
goto P_0c0c0248;
P_0c0c0248: /* original 0ed4, guest PC 0x0c0c0248 */
if(!s->budget--) { s->failed_pc=0x0c0c0248u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c024a;
P_0c0c024a: /* original 63e2, guest PC 0x0c0c024a */
if(!s->budget--) { s->failed_pc=0x0c0c024au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c024c;
P_0c0c024c: /* original 1f35, guest PC 0x0c0c024c */
if(!s->budget--) { s->failed_pc=0x0c0c024cu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0c024e;
P_0c0c024e: /* original d358, guest PC 0x0c0c024e */
if(!s->budget--) { s->failed_pc=0x0c0c024eu; return 0; }
r[3]=read(ram,0x0c0c03b0u,4);
goto P_0c0c0250;
P_0c0c0250: /* original 52f5, guest PC 0x0c0c0250 */
if(!s->budget--) { s->failed_pc=0x0c0c0250u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0c0252;
P_0c0c0252: /* original 2239, guest PC 0x0c0c0252 */
if(!s->budget--) { s->failed_pc=0x0c0c0252u; return 0; }
r[2]&=r[3];
goto P_0c0c0254;
P_0c0c0254: /* original 1f25, guest PC 0x0c0c0254 */
if(!s->budget--) { s->failed_pc=0x0c0c0254u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0c0256;
P_0c0c0256: /* original 6123, guest PC 0x0c0c0256 */
if(!s->budget--) { s->failed_pc=0x0c0c0256u; return 0; }
r[1]=r[2];
goto P_0c0c0258;
P_0c0c0258: /* original 2e22, guest PC 0x0c0c0258 */
if(!s->budget--) { s->failed_pc=0x0c0c0258u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0c025a;
P_0c0c025a: /* original 9097, guest PC 0x0c0c025a */
if(!s->budget--) { s->failed_pc=0x0c0c025au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c038cu,2);
goto P_0c0c025c;
P_0c0c025c: /* original 04bc, guest PC 0x0c0c025c */
if(!s->budget--) { s->failed_pc=0x0c0c025cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c025e;
P_0c0c025e: /* original 9096, guest PC 0x0c0c025e */
if(!s->budget--) { s->failed_pc=0x0c0c025eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c038eu,2);
goto P_0c0c0260;
P_0c0c0260: /* original 05bc, guest PC 0x0c0c0260 */
if(!s->budget--) { s->failed_pc=0x0c0c0260u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c0262;
P_0c0c0262: /* original 3450, guest PC 0x0c0c0262 */
if(!s->budget--) { s->failed_pc=0x0c0c0262u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0c0264;
P_0c0c0264: /* original 8b01, guest PC 0x0c0c0264 */
if(!s->budget--) { s->failed_pc=0x0c0c0264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c026a; }
goto P_0c0c0266;
P_0c0c0266: /* original a0d4, guest PC 0x0c0c0266 */
if(!s->budget--) { s->failed_pc=0x0c0c0266u; return 0; }
goto P_0c0c0412;
P_0c0c0268: /* original 0009, guest PC 0x0c0c0268 */
if(!s->budget--) { s->failed_pc=0x0c0c0268u; return 0; }
goto P_0c0c026a;
P_0c0c026a: /* original e04c, guest PC 0x0c0c026a */
if(!s->budget--) { s->failed_pc=0x0c0c026au; return 0; }
r[0]=0x0000004cu;
goto P_0c0c026c;
P_0c0c026c: /* original 64d3, guest PC 0x0c0c026c */
if(!s->budget--) { s->failed_pc=0x0c0c026cu; return 0; }
r[4]=r[13];
goto P_0c0c026e;
P_0c0c026e: /* original 0ed5, guest PC 0x0c0c026e */
if(!s->budget--) { s->failed_pc=0x0c0c026eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0270;
P_0c0c0270: /* original e04e, guest PC 0x0c0c0270 */
if(!s->budget--) { s->failed_pc=0x0c0c0270u; return 0; }
r[0]=0x0000004eu;
goto P_0c0c0272;
P_0c0c0272: /* original 0ed5, guest PC 0x0c0c0272 */
if(!s->budget--) { s->failed_pc=0x0c0c0272u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0274;
P_0c0c0274: /* original e061, guest PC 0x0c0c0274 */
if(!s->budget--) { s->failed_pc=0x0c0c0274u; return 0; }
r[0]=0x00000061u;
goto P_0c0c0276;
P_0c0c0276: /* original 03cc, guest PC 0x0c0c0276 */
if(!s->budget--) { s->failed_pc=0x0c0c0276u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c0278;
P_0c0c0278: /* original e061, guest PC 0x0c0c0278 */
if(!s->budget--) { s->failed_pc=0x0c0c0278u; return 0; }
r[0]=0x00000061u;
goto P_0c0c027a;
P_0c0c027a: /* original e5ff, guest PC 0x0c0c027a */
if(!s->budget--) { s->failed_pc=0x0c0c027au; return 0; }
r[5]=0xffffffffu;
goto P_0c0c027c;
P_0c0c027c: /* original 633c, guest PC 0x0c0c027c */
if(!s->budget--) { s->failed_pc=0x0c0c027cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c027e;
P_0c0c027e: /* original 1f36, guest PC 0x0c0c027e */
if(!s->budget--) { s->failed_pc=0x0c0c027eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0c0280;
P_0c0c0280: /* original 02cc, guest PC 0x0c0c0280 */
if(!s->budget--) { s->failed_pc=0x0c0c0280u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c0282;
P_0c0c0282: /* original e050, guest PC 0x0c0c0282 */
if(!s->budget--) { s->failed_pc=0x0c0c0282u; return 0; }
r[0]=0x00000050u;
goto P_0c0c0284;
P_0c0c0284: /* original 0e24, guest PC 0x0c0c0284 */
if(!s->budget--) { s->failed_pc=0x0c0c0284u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c0286;
P_0c0c0286: /* original e051, guest PC 0x0c0c0286 */
if(!s->budget--) { s->failed_pc=0x0c0c0286u; return 0; }
r[0]=0x00000051u;
goto P_0c0c0288;
P_0c0c0288: /* original 0ed4, guest PC 0x0c0c0288 */
if(!s->budget--) { s->failed_pc=0x0c0c0288u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c028a;
P_0c0c028a: /* original e052, guest PC 0x0c0c028a */
if(!s->budget--) { s->failed_pc=0x0c0c028au; return 0; }
r[0]=0x00000052u;
goto P_0c0c028c;
P_0c0c028c: /* original 0e54, guest PC 0x0c0c028c */
if(!s->budget--) { s->failed_pc=0x0c0c028cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c028e;
P_0c0c028e: /* original e053, guest PC 0x0c0c028e */
if(!s->budget--) { s->failed_pc=0x0c0c028eu; return 0; }
r[0]=0x00000053u;
goto P_0c0c0290;
P_0c0c0290: /* original 0ed4, guest PC 0x0c0c0290 */
if(!s->budget--) { s->failed_pc=0x0c0c0290u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c0292;
P_0c0c0292: /* original 907d, guest PC 0x0c0c0292 */
if(!s->budget--) { s->failed_pc=0x0c0c0292u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0390u,2);
goto P_0c0c0294;
P_0c0c0294: /* original 0ed4, guest PC 0x0c0c0294 */
if(!s->budget--) { s->failed_pc=0x0c0c0294u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c0296;
P_0c0c0296: /* original 7001, guest PC 0x0c0c0296 */
if(!s->budget--) { s->failed_pc=0x0c0c0296u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c0298;
P_0c0c0298: /* original 0e54, guest PC 0x0c0c0298 */
if(!s->budget--) { s->failed_pc=0x0c0c0298u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c029a;
P_0c0c029a: /* original 7001, guest PC 0x0c0c029a */
if(!s->budget--) { s->failed_pc=0x0c0c029au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c029c;
P_0c0c029c: /* original 0ed4, guest PC 0x0c0c029c */
if(!s->budget--) { s->failed_pc=0x0c0c029cu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c029e;
P_0c0c029e: /* original 7001, guest PC 0x0c0c029e */
if(!s->budget--) { s->failed_pc=0x0c0c029eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c02a0;
P_0c0c02a0: /* original 0ed4, guest PC 0x0c0c02a0 */
if(!s->budget--) { s->failed_pc=0x0c0c02a0u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c02a2;
P_0c0c02a2: /* original 9676, guest PC 0x0c0c02a2 */
if(!s->budget--) { s->failed_pc=0x0c0c02a2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0392u,2);
goto P_0c0c02a4;
P_0c0c02a4: /* original 63e3, guest PC 0x0c0c02a4 */
if(!s->budget--) { s->failed_pc=0x0c0c02a4u; return 0; }
r[3]=r[14];
goto P_0c0c02a6;
P_0c0c02a6: /* original 7354, guest PC 0x0c0c02a6 */
if(!s->budget--) { s->failed_pc=0x0c0c02a6u; return 0; }
r[3]+=0x00000054u;
goto P_0c0c02a8;
P_0c0c02a8: /* original 334c, guest PC 0x0c0c02a8 */
if(!s->budget--) { s->failed_pc=0x0c0c02a8u; return 0; }
r[3]+=r[4];
goto P_0c0c02aa;
P_0c0c02aa: /* original 2350, guest PC 0x0c0c02aa */
if(!s->budget--) { s->failed_pc=0x0c0c02aau; return 0; }
write(ram,r[3],r[5],1);
goto P_0c0c02ac;
P_0c0c02ac: /* original 4610, guest PC 0x0c0c02ac */
if(!s->budget--) { s->failed_pc=0x0c0c02acu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c02ae;
P_0c0c02ae: /* original 9271, guest PC 0x0c0c02ae */
if(!s->budget--) { s->failed_pc=0x0c0c02aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0394u,2);
goto P_0c0c02b0;
P_0c0c02b0: /* original 32ec, guest PC 0x0c0c02b0 */
if(!s->budget--) { s->failed_pc=0x0c0c02b0u; return 0; }
r[2]+=r[14];
goto P_0c0c02b2;
P_0c0c02b2: /* original 324c, guest PC 0x0c0c02b2 */
if(!s->budget--) { s->failed_pc=0x0c0c02b2u; return 0; }
r[2]+=r[4];
goto P_0c0c02b4;
P_0c0c02b4: /* original 22d0, guest PC 0x0c0c02b4 */
if(!s->budget--) { s->failed_pc=0x0c0c02b4u; return 0; }
write(ram,r[2],r[13],1);
goto P_0c0c02b6;
P_0c0c02b6: /* original 936e, guest PC 0x0c0c02b6 */
if(!s->budget--) { s->failed_pc=0x0c0c02b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0396u,2);
goto P_0c0c02b8;
P_0c0c02b8: /* original 33ec, guest PC 0x0c0c02b8 */
if(!s->budget--) { s->failed_pc=0x0c0c02b8u; return 0; }
r[3]+=r[14];
goto P_0c0c02ba;
P_0c0c02ba: /* original 334c, guest PC 0x0c0c02ba */
if(!s->budget--) { s->failed_pc=0x0c0c02bau; return 0; }
r[3]+=r[4];
goto P_0c0c02bc;
P_0c0c02bc: /* original 2350, guest PC 0x0c0c02bc */
if(!s->budget--) { s->failed_pc=0x0c0c02bcu; return 0; }
write(ram,r[3],r[5],1);
goto P_0c0c02be;
P_0c0c02be: /* original 926b, guest PC 0x0c0c02be */
if(!s->budget--) { s->failed_pc=0x0c0c02beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0398u,2);
goto P_0c0c02c0;
P_0c0c02c0: /* original 32ec, guest PC 0x0c0c02c0 */
if(!s->budget--) { s->failed_pc=0x0c0c02c0u; return 0; }
r[2]+=r[14];
goto P_0c0c02c2;
P_0c0c02c2: /* original 324c, guest PC 0x0c0c02c2 */
if(!s->budget--) { s->failed_pc=0x0c0c02c2u; return 0; }
r[2]+=r[4];
goto P_0c0c02c4;
P_0c0c02c4: /* original 22d0, guest PC 0x0c0c02c4 */
if(!s->budget--) { s->failed_pc=0x0c0c02c4u; return 0; }
write(ram,r[2],r[13],1);
goto P_0c0c02c6;
P_0c0c02c6: /* original 8fed, guest PC 0x0c0c02c6 */
if(!s->budget--) { s->failed_pc=0x0c0c02c6u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0c02a4; }
goto P_0c0c02ca;
P_0c0c02c8: /* original 7401, guest PC 0x0c0c02c8 */
if(!s->budget--) { s->failed_pc=0x0c0c02c8u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c02ca;
P_0c0c02ca: /* original 53f6, guest PC 0x0c0c02ca */
if(!s->budget--) { s->failed_pc=0x0c0c02cau; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c02cc;
P_0c0c02cc: /* original d039, guest PC 0x0c0c02cc */
if(!s->budget--) { s->failed_pc=0x0c0c02ccu; return 0; }
r[0]=read(ram,0x0c0c03b4u,4);
goto P_0c0c02ce;
P_0c0c02ce: /* original 4308, guest PC 0x0c0c02ce */
if(!s->budget--) { s->failed_pc=0x0c0c02ceu; return 0; }
r[3]<<=2;
goto P_0c0c02d0;
P_0c0c02d0: /* original f336, guest PC 0x0c0c02d0 */
if(!s->budget--) { s->failed_pc=0x0c0c02d0u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c02d2;
P_0c0c02d2: /* original 9062, guest PC 0x0c0c02d2 */
if(!s->budget--) { s->failed_pc=0x0c0c02d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c039au,2);
goto P_0c0c02d4;
P_0c0c02d4: /* original fe37, guest PC 0x0c0c02d4 */
if(!s->budget--) { s->failed_pc=0x0c0c02d4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c02d6;
P_0c0c02d6: /* original 53f6, guest PC 0x0c0c02d6 */
if(!s->budget--) { s->failed_pc=0x0c0c02d6u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c02d8;
P_0c0c02d8: /* original d037, guest PC 0x0c0c02d8 */
if(!s->budget--) { s->failed_pc=0x0c0c02d8u; return 0; }
r[0]=read(ram,0x0c0c03b8u,4);
goto P_0c0c02da;
P_0c0c02da: /* original 4308, guest PC 0x0c0c02da */
if(!s->budget--) { s->failed_pc=0x0c0c02dau; return 0; }
r[3]<<=2;
goto P_0c0c02dc;
P_0c0c02dc: /* original f336, guest PC 0x0c0c02dc */
if(!s->budget--) { s->failed_pc=0x0c0c02dcu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c02de;
P_0c0c02de: /* original 905d, guest PC 0x0c0c02de */
if(!s->budget--) { s->failed_pc=0x0c0c02deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c039cu,2);
goto P_0c0c02e0;
P_0c0c02e0: /* original fe37, guest PC 0x0c0c02e0 */
if(!s->budget--) { s->failed_pc=0x0c0c02e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c02e2;
P_0c0c02e2: /* original 53f6, guest PC 0x0c0c02e2 */
if(!s->budget--) { s->failed_pc=0x0c0c02e2u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c02e4;
P_0c0c02e4: /* original d035, guest PC 0x0c0c02e4 */
if(!s->budget--) { s->failed_pc=0x0c0c02e4u; return 0; }
r[0]=read(ram,0x0c0c03bcu,4);
goto P_0c0c02e6;
P_0c0c02e6: /* original 4308, guest PC 0x0c0c02e6 */
if(!s->budget--) { s->failed_pc=0x0c0c02e6u; return 0; }
r[3]<<=2;
goto P_0c0c02e8;
P_0c0c02e8: /* original f336, guest PC 0x0c0c02e8 */
if(!s->budget--) { s->failed_pc=0x0c0c02e8u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c02ea;
P_0c0c02ea: /* original 9058, guest PC 0x0c0c02ea */
if(!s->budget--) { s->failed_pc=0x0c0c02eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c039eu,2);
goto P_0c0c02ec;
P_0c0c02ec: /* original fe37, guest PC 0x0c0c02ec */
if(!s->budget--) { s->failed_pc=0x0c0c02ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c02ee;
P_0c0c02ee: /* original 53f6, guest PC 0x0c0c02ee */
if(!s->budget--) { s->failed_pc=0x0c0c02eeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c02f0;
P_0c0c02f0: /* original d033, guest PC 0x0c0c02f0 */
if(!s->budget--) { s->failed_pc=0x0c0c02f0u; return 0; }
r[0]=read(ram,0x0c0c03c0u,4);
goto P_0c0c02f2;
P_0c0c02f2: /* original 4308, guest PC 0x0c0c02f2 */
if(!s->budget--) { s->failed_pc=0x0c0c02f2u; return 0; }
r[3]<<=2;
goto P_0c0c02f4;
P_0c0c02f4: /* original f336, guest PC 0x0c0c02f4 */
if(!s->budget--) { s->failed_pc=0x0c0c02f4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c02f6;
P_0c0c02f6: /* original 9053, guest PC 0x0c0c02f6 */
if(!s->budget--) { s->failed_pc=0x0c0c02f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c03a0u,2);
goto P_0c0c02f8;
P_0c0c02f8: /* original fe37, guest PC 0x0c0c02f8 */
if(!s->budget--) { s->failed_pc=0x0c0c02f8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c02fa;
P_0c0c02fa: /* original 7004, guest PC 0x0c0c02fa */
if(!s->budget--) { s->failed_pc=0x0c0c02fau; return 0; }
r[0]+=0x00000004u;
goto P_0c0c02fc;
P_0c0c02fc: /* original 0ed4, guest PC 0x0c0c02fc */
if(!s->budget--) { s->failed_pc=0x0c0c02fcu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c02fe;
P_0c0c02fe: /* original 7001, guest PC 0x0c0c02fe */
if(!s->budget--) { s->failed_pc=0x0c0c02feu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c0300;
P_0c0c0300: /* original 0ed4, guest PC 0x0c0c0300 */
if(!s->budget--) { s->failed_pc=0x0c0c0300u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c0302;
P_0c0c0302: /* original 7001, guest PC 0x0c0c0302 */
if(!s->budget--) { s->failed_pc=0x0c0c0302u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c0304;
P_0c0c0304: /* original 0ed4, guest PC 0x0c0c0304 */
if(!s->budget--) { s->failed_pc=0x0c0c0304u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c0306;
P_0c0c0306: /* original 7001, guest PC 0x0c0c0306 */
if(!s->budget--) { s->failed_pc=0x0c0c0306u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c0308;
P_0c0c0308: /* original 0ed4, guest PC 0x0c0c0308 */
if(!s->budget--) { s->failed_pc=0x0c0c0308u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c030a;
P_0c0c030a: /* original 7001, guest PC 0x0c0c030a */
if(!s->budget--) { s->failed_pc=0x0c0c030au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c030c;
P_0c0c030c: /* original 0ed5, guest PC 0x0c0c030c */
if(!s->budget--) { s->failed_pc=0x0c0c030cu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c030e;
P_0c0c030e: /* original 7002, guest PC 0x0c0c030e */
if(!s->budget--) { s->failed_pc=0x0c0c030eu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c0310;
P_0c0c0310: /* original 0ed5, guest PC 0x0c0c0310 */
if(!s->budget--) { s->failed_pc=0x0c0c0310u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0312;
P_0c0c0312: /* original 7002, guest PC 0x0c0c0312 */
if(!s->budget--) { s->failed_pc=0x0c0c0312u; return 0; }
r[0]+=0x00000002u;
goto P_0c0c0314;
P_0c0c0314: /* original 0ed5, guest PC 0x0c0c0314 */
if(!s->budget--) { s->failed_pc=0x0c0c0314u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0316;
P_0c0c0316: /* original 7002, guest PC 0x0c0c0316 */
if(!s->budget--) { s->failed_pc=0x0c0c0316u; return 0; }
r[0]+=0x00000002u;
goto P_0c0c0318;
P_0c0c0318: /* original 0ed5, guest PC 0x0c0c0318 */
if(!s->budget--) { s->failed_pc=0x0c0c0318u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c031a;
P_0c0c031a: /* original 7002, guest PC 0x0c0c031a */
if(!s->budget--) { s->failed_pc=0x0c0c031au; return 0; }
r[0]+=0x00000002u;
goto P_0c0c031c;
P_0c0c031c: /* original 0ed5, guest PC 0x0c0c031c */
if(!s->budget--) { s->failed_pc=0x0c0c031cu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c031e;
P_0c0c031e: /* original 7002, guest PC 0x0c0c031e */
if(!s->budget--) { s->failed_pc=0x0c0c031eu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c0320;
P_0c0c0320: /* original 0ed5, guest PC 0x0c0c0320 */
if(!s->budget--) { s->failed_pc=0x0c0c0320u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0c0322;
P_0c0c0322: /* original 7002, guest PC 0x0c0c0322 */
if(!s->budget--) { s->failed_pc=0x0c0c0322u; return 0; }
r[0]+=0x00000002u;
goto P_0c0c0324;
P_0c0c0324: /* original fef7, guest PC 0x0c0c0324 */
if(!s->budget--) { s->failed_pc=0x0c0c0324u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0326;
P_0c0c0326: /* original 7004, guest PC 0x0c0c0326 */
if(!s->budget--) { s->failed_pc=0x0c0c0326u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0328;
P_0c0c0328: /* original fef7, guest PC 0x0c0c0328 */
if(!s->budget--) { s->failed_pc=0x0c0c0328u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c032a;
P_0c0c032a: /* original 7004, guest PC 0x0c0c032a */
if(!s->budget--) { s->failed_pc=0x0c0c032au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c032c;
P_0c0c032c: /* original fef7, guest PC 0x0c0c032c */
if(!s->budget--) { s->failed_pc=0x0c0c032cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c032e;
P_0c0c032e: /* original 7004, guest PC 0x0c0c032e */
if(!s->budget--) { s->failed_pc=0x0c0c032eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0330;
P_0c0c0330: /* original fef7, guest PC 0x0c0c0330 */
if(!s->budget--) { s->failed_pc=0x0c0c0330u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0332;
P_0c0c0332: /* original 7004, guest PC 0x0c0c0332 */
if(!s->budget--) { s->failed_pc=0x0c0c0332u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0334;
P_0c0c0334: /* original fef7, guest PC 0x0c0c0334 */
if(!s->budget--) { s->failed_pc=0x0c0c0334u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0336;
P_0c0c0336: /* original 7004, guest PC 0x0c0c0336 */
if(!s->budget--) { s->failed_pc=0x0c0c0336u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0338;
P_0c0c0338: /* original fef7, guest PC 0x0c0c0338 */
if(!s->budget--) { s->failed_pc=0x0c0c0338u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c033a;
P_0c0c033a: /* original 7004, guest PC 0x0c0c033a */
if(!s->budget--) { s->failed_pc=0x0c0c033au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c033c;
P_0c0c033c: /* original fef7, guest PC 0x0c0c033c */
if(!s->budget--) { s->failed_pc=0x0c0c033cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c033e;
P_0c0c033e: /* original 7004, guest PC 0x0c0c033e */
if(!s->budget--) { s->failed_pc=0x0c0c033eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0340;
P_0c0c0340: /* original fef7, guest PC 0x0c0c0340 */
if(!s->budget--) { s->failed_pc=0x0c0c0340u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0342;
P_0c0c0342: /* original 7004, guest PC 0x0c0c0342 */
if(!s->budget--) { s->failed_pc=0x0c0c0342u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0344;
P_0c0c0344: /* original fef7, guest PC 0x0c0c0344 */
if(!s->budget--) { s->failed_pc=0x0c0c0344u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0346;
P_0c0c0346: /* original 7004, guest PC 0x0c0c0346 */
if(!s->budget--) { s->failed_pc=0x0c0c0346u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0348;
P_0c0c0348: /* original fef7, guest PC 0x0c0c0348 */
if(!s->budget--) { s->failed_pc=0x0c0c0348u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c034a;
P_0c0c034a: /* original 7004, guest PC 0x0c0c034a */
if(!s->budget--) { s->failed_pc=0x0c0c034au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c034c;
P_0c0c034c: /* original 65d3, guest PC 0x0c0c034c */
if(!s->budget--) { s->failed_pc=0x0c0c034cu; return 0; }
r[5]=r[13];
goto P_0c0c034e;
P_0c0c034e: /* original fef7, guest PC 0x0c0c034e */
if(!s->budget--) { s->failed_pc=0x0c0c034eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0350;
P_0c0c0350: /* original 7004, guest PC 0x0c0c0350 */
if(!s->budget--) { s->failed_pc=0x0c0c0350u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0352;
P_0c0c0352: /* original fef7, guest PC 0x0c0c0352 */
if(!s->budget--) { s->failed_pc=0x0c0c0352u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0354;
P_0c0c0354: /* original 7004, guest PC 0x0c0c0354 */
if(!s->budget--) { s->failed_pc=0x0c0c0354u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0356;
P_0c0c0356: /* original fef7, guest PC 0x0c0c0356 */
if(!s->budget--) { s->failed_pc=0x0c0c0356u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0358;
P_0c0c0358: /* original 7004, guest PC 0x0c0c0358 */
if(!s->budget--) { s->failed_pc=0x0c0c0358u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c035a;
P_0c0c035a: /* original fef7, guest PC 0x0c0c035a */
if(!s->budget--) { s->failed_pc=0x0c0c035au; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c035c;
P_0c0c035c: /* original 7004, guest PC 0x0c0c035c */
if(!s->budget--) { s->failed_pc=0x0c0c035cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c035e;
P_0c0c035e: /* original fef7, guest PC 0x0c0c035e */
if(!s->budget--) { s->failed_pc=0x0c0c035eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0360;
P_0c0c0360: /* original 7004, guest PC 0x0c0c0360 */
if(!s->budget--) { s->failed_pc=0x0c0c0360u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0362;
P_0c0c0362: /* original fef7, guest PC 0x0c0c0362 */
if(!s->budget--) { s->failed_pc=0x0c0c0362u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c0364;
P_0c0c0364: /* original 7004, guest PC 0x0c0c0364 */
if(!s->budget--) { s->failed_pc=0x0c0c0364u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c0366;
P_0c0c0366: /* original e607, guest PC 0x0c0c0366 */
if(!s->budget--) { s->failed_pc=0x0c0c0366u; return 0; }
r[6]=0x00000007u;
goto P_0c0c0368;
P_0c0c0368: /* original fef7, guest PC 0x0c0c0368 */
if(!s->budget--) { s->failed_pc=0x0c0c0368u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c036a;
P_0c0c036a: /* original 931a, guest PC 0x0c0c036a */
if(!s->budget--) { s->failed_pc=0x0c0c036au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c03a2u,2);
goto P_0c0c036c;
P_0c0c036c: /* original 6453, guest PC 0x0c0c036c */
if(!s->budget--) { s->failed_pc=0x0c0c036cu; return 0; }
r[4]=r[5];
goto P_0c0c036e;
P_0c0c036e: /* original 4408, guest PC 0x0c0c036e */
if(!s->budget--) { s->failed_pc=0x0c0c036eu; return 0; }
r[4]<<=2;
goto P_0c0c0370;
P_0c0c0370: /* original 33ec, guest PC 0x0c0c0370 */
if(!s->budget--) { s->failed_pc=0x0c0c0370u; return 0; }
r[3]+=r[14];
goto P_0c0c0372;
P_0c0c0372: /* original 334c, guest PC 0x0c0c0372 */
if(!s->budget--) { s->failed_pc=0x0c0c0372u; return 0; }
r[3]+=r[4];
goto P_0c0c0374;
P_0c0c0374: /* original f3fa, guest PC 0x0c0c0374 */
if(!s->budget--) { s->failed_pc=0x0c0c0374u; return 0; }
vf3_matrix_store(s,ram,15,r[3]);
goto P_0c0c0376;
P_0c0c0376: /* original 9215, guest PC 0x0c0c0376 */
if(!s->budget--) { s->failed_pc=0x0c0c0376u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c03a4u,2);
goto P_0c0c0378;
P_0c0c0378: /* original 32ec, guest PC 0x0c0c0378 */
if(!s->budget--) { s->failed_pc=0x0c0c0378u; return 0; }
r[2]+=r[14];
goto P_0c0c037a;
P_0c0c037a: /* original 324c, guest PC 0x0c0c037a */
if(!s->budget--) { s->failed_pc=0x0c0c037au; return 0; }
r[2]+=r[4];
goto P_0c0c037c;
P_0c0c037c: /* original f2fa, guest PC 0x0c0c037c */
if(!s->budget--) { s->failed_pc=0x0c0c037cu; return 0; }
vf3_matrix_store(s,ram,15,r[2]);
goto P_0c0c037e;
P_0c0c037e: /* original 9312, guest PC 0x0c0c037e */
if(!s->budget--) { s->failed_pc=0x0c0c037eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c03a6u,2);
goto P_0c0c0380;
P_0c0c0380: /* original 33ec, guest PC 0x0c0c0380 */
if(!s->budget--) { s->failed_pc=0x0c0c0380u; return 0; }
r[3]+=r[14];
goto P_0c0c0382;
P_0c0c0382: /* original 334c, guest PC 0x0c0c0382 */
if(!s->budget--) { s->failed_pc=0x0c0c0382u; return 0; }
r[3]+=r[4];
goto P_0c0c0384;
P_0c0c0384: /* original f3fa, guest PC 0x0c0c0384 */
if(!s->budget--) { s->failed_pc=0x0c0c0384u; return 0; }
vf3_matrix_store(s,ram,15,r[3]);
goto P_0c0c0386;
P_0c0c0386: /* original 920f, guest PC 0x0c0c0386 */
if(!s->budget--) { s->failed_pc=0x0c0c0386u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c03a8u,2);
goto P_0c0c0388;
P_0c0c0388: /* original a01c, guest PC 0x0c0c0388 */
if(!s->budget--) { s->failed_pc=0x0c0c0388u; return 0; }
goto P_0c0c03c4;
P_0c0c038a: /* original 0009, guest PC 0x0c0c038a */
if(!s->budget--) { s->failed_pc=0x0c0c038au; return 0; }
return vf3_matrix_family(0x0c0c038cu,s,ram);
P_0c0c03c4: /* original 32ec, guest PC 0x0c0c03c4 */
if(!s->budget--) { s->failed_pc=0x0c0c03c4u; return 0; }
r[2]+=r[14];
goto P_0c0c03c6;
P_0c0c03c6: /* original 324c, guest PC 0x0c0c03c6 */
if(!s->budget--) { s->failed_pc=0x0c0c03c6u; return 0; }
r[2]+=r[4];
goto P_0c0c03c8;
P_0c0c03c8: /* original 4610, guest PC 0x0c0c03c8 */
if(!s->budget--) { s->failed_pc=0x0c0c03c8u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c03ca;
P_0c0c03ca: /* original f2fa, guest PC 0x0c0c03ca */
if(!s->budget--) { s->failed_pc=0x0c0c03cau; return 0; }
vf3_matrix_store(s,ram,15,r[2]);
goto P_0c0c03cc;
P_0c0c03cc: /* original 9389, guest PC 0x0c0c03cc */
if(!s->budget--) { s->failed_pc=0x0c0c03ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04e2u,2);
goto P_0c0c03ce;
P_0c0c03ce: /* original 33ec, guest PC 0x0c0c03ce */
if(!s->budget--) { s->failed_pc=0x0c0c03ceu; return 0; }
r[3]+=r[14];
goto P_0c0c03d0;
P_0c0c03d0: /* original 343c, guest PC 0x0c0c03d0 */
if(!s->budget--) { s->failed_pc=0x0c0c03d0u; return 0; }
r[4]+=r[3];
goto P_0c0c03d2;
P_0c0c03d2: /* original f4fa, guest PC 0x0c0c03d2 */
if(!s->budget--) { s->failed_pc=0x0c0c03d2u; return 0; }
vf3_matrix_store(s,ram,15,r[4]);
goto P_0c0c03d4;
P_0c0c03d4: /* original 8fc9, guest PC 0x0c0c03d4 */
if(!s->budget--) { s->failed_pc=0x0c0c03d4u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0c036a; }
goto P_0c0c03d8;
P_0c0c03d6: /* original 7501, guest PC 0x0c0c03d6 */
if(!s->budget--) { s->failed_pc=0x0c0c03d6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c03d8;
P_0c0c03d8: /* original 9084, guest PC 0x0c0c03d8 */
if(!s->budget--) { s->failed_pc=0x0c0c03d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04e4u,2);
goto P_0c0c03da;
P_0c0c03da: /* original 0ed4, guest PC 0x0c0c03da */
if(!s->budget--) { s->failed_pc=0x0c0c03dau; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c03dc;
P_0c0c03dc: /* original 7001, guest PC 0x0c0c03dc */
if(!s->budget--) { s->failed_pc=0x0c0c03dcu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c03de;
P_0c0c03de: /* original 0ed4, guest PC 0x0c0c03de */
if(!s->budget--) { s->failed_pc=0x0c0c03deu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c03e0;
P_0c0c03e0: /* original 7001, guest PC 0x0c0c03e0 */
if(!s->budget--) { s->failed_pc=0x0c0c03e0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c03e2;
P_0c0c03e2: /* original 0ed4, guest PC 0x0c0c03e2 */
if(!s->budget--) { s->failed_pc=0x0c0c03e2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c03e4;
P_0c0c03e4: /* original 7001, guest PC 0x0c0c03e4 */
if(!s->budget--) { s->failed_pc=0x0c0c03e4u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c03e6;
P_0c0c03e6: /* original 0ed4, guest PC 0x0c0c03e6 */
if(!s->budget--) { s->failed_pc=0x0c0c03e6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c03e8;
P_0c0c03e8: /* original 907d, guest PC 0x0c0c03e8 */
if(!s->budget--) { s->failed_pc=0x0c0c03e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04e6u,2);
goto P_0c0c03ea;
P_0c0c03ea: /* original 03ce, guest PC 0x0c0c03ea */
if(!s->budget--) { s->failed_pc=0x0c0c03eau; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c0c03ec;
P_0c0c03ec: /* original 907c, guest PC 0x0c0c03ec */
if(!s->budget--) { s->failed_pc=0x0c0c03ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04e8u,2);
goto P_0c0c03ee;
P_0c0c03ee: /* original 0e36, guest PC 0x0c0c03ee */
if(!s->budget--) { s->failed_pc=0x0c0c03eeu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c03f0;
P_0c0c03f0: /* original 907b, guest PC 0x0c0c03f0 */
if(!s->budget--) { s->failed_pc=0x0c0c03f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04eau,2);
goto P_0c0c03f2;
P_0c0c03f2: /* original 02ce, guest PC 0x0c0c03f2 */
if(!s->budget--) { s->failed_pc=0x0c0c03f2u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c03f4;
P_0c0c03f4: /* original 907a, guest PC 0x0c0c03f4 */
if(!s->budget--) { s->failed_pc=0x0c0c03f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04ecu,2);
goto P_0c0c03f6;
P_0c0c03f6: /* original 0e26, guest PC 0x0c0c03f6 */
if(!s->budget--) { s->failed_pc=0x0c0c03f6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c03f8;
P_0c0c03f8: /* original 9079, guest PC 0x0c0c03f8 */
if(!s->budget--) { s->failed_pc=0x0c0c03f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04eeu,2);
goto P_0c0c03fa;
P_0c0c03fa: /* original 03ce, guest PC 0x0c0c03fa */
if(!s->budget--) { s->failed_pc=0x0c0c03fau; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c0c03fc;
P_0c0c03fc: /* original 9078, guest PC 0x0c0c03fc */
if(!s->budget--) { s->failed_pc=0x0c0c03fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04f0u,2);
goto P_0c0c03fe;
P_0c0c03fe: /* original 0e36, guest PC 0x0c0c03fe */
if(!s->budget--) { s->failed_pc=0x0c0c03feu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c0400;
P_0c0c0400: /* original 9075, guest PC 0x0c0c0400 */
if(!s->budget--) { s->failed_pc=0x0c0c0400u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04eeu,2);
goto P_0c0c0402;
P_0c0c0402: /* original 52f1, guest PC 0x0c0c0402 */
if(!s->budget--) { s->failed_pc=0x0c0c0402u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c0404;
P_0c0c0404: /* original 032e, guest PC 0x0c0c0404 */
if(!s->budget--) { s->failed_pc=0x0c0c0404u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0c0406;
P_0c0c0406: /* original 9074, guest PC 0x0c0c0406 */
if(!s->budget--) { s->failed_pc=0x0c0c0406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04f2u,2);
goto P_0c0c0408;
P_0c0c0408: /* original 0e36, guest PC 0x0c0c0408 */
if(!s->budget--) { s->failed_pc=0x0c0c0408u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c040a;
P_0c0c040a: /* original 9073, guest PC 0x0c0c040a */
if(!s->budget--) { s->failed_pc=0x0c0c040au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04f4u,2);
goto P_0c0c040c;
P_0c0c040c: /* original 02ce, guest PC 0x0c0c040c */
if(!s->budget--) { s->failed_pc=0x0c0c040cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c040e;
P_0c0c040e: /* original 9072, guest PC 0x0c0c040e */
if(!s->budget--) { s->failed_pc=0x0c0c040eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c04f6u,2);
goto P_0c0c0410;
P_0c0c0410: /* original 0e26, guest PC 0x0c0c0410 */
if(!s->budget--) { s->failed_pc=0x0c0c0410u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c0412;
P_0c0c0412: /* original 7f38, guest PC 0x0c0c0412 */
if(!s->budget--) { s->failed_pc=0x0c0c0412u; return 0; }
r[15]+=0x00000038u;
goto P_0c0c0414;
P_0c0c0414: /* original 4f26, guest PC 0x0c0c0414 */
if(!s->budget--) { s->failed_pc=0x0c0c0414u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0416;
P_0c0c0416: /* original fff9, guest PC 0x0c0c0416 */
if(!s->budget--) { s->failed_pc=0x0c0c0416u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c0418;
P_0c0c0418: /* original 6bf6, guest PC 0x0c0c0418 */
if(!s->budget--) { s->failed_pc=0x0c0c0418u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c041a;
P_0c0c041a: /* original 6cf6, guest PC 0x0c0c041a */
if(!s->budget--) { s->failed_pc=0x0c0c041au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c041c;
P_0c0c041c: /* original 6df6, guest PC 0x0c0c041c */
if(!s->budget--) { s->failed_pc=0x0c0c041cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c041e;
P_0c0c041e: /* original 000b, guest PC 0x0c0c041e */
if(!s->budget--) { s->failed_pc=0x0c0c041eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c0420: /* original 6ef6, guest PC 0x0c0c0420 */
if(!s->budget--) { s->failed_pc=0x0c0c0420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c0422u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
