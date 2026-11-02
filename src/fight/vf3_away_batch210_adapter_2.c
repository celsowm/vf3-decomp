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
int vf3_away_batch210_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09efceu: goto P_0c09efce;
case 0x0c09efd0u: goto P_0c09efd0;
case 0x0c09efd2u: goto P_0c09efd2;
case 0x0c09efd4u: goto P_0c09efd4;
case 0x0c09efd6u: goto P_0c09efd6;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
case 0x0c09f1acu: goto P_0c09f1ac;
case 0x0c09f1aeu: goto P_0c09f1ae;
case 0x0c09f1b0u: goto P_0c09f1b0;
case 0x0c09f1b2u: goto P_0c09f1b2;
case 0x0c09f1b4u: goto P_0c09f1b4;
case 0x0c09f1b6u: goto P_0c09f1b6;
case 0x0c09f1b8u: goto P_0c09f1b8;
case 0x0c09f1bau: goto P_0c09f1ba;
case 0x0c09f1bcu: goto P_0c09f1bc;
case 0x0c09f1beu: goto P_0c09f1be;
case 0x0c09f1c0u: goto P_0c09f1c0;
case 0x0c09f1c2u: goto P_0c09f1c2;
case 0x0c09f1c4u: goto P_0c09f1c4;
case 0x0c09f1c6u: goto P_0c09f1c6;
case 0x0c09f1c8u: goto P_0c09f1c8;
case 0x0c09f1cau: goto P_0c09f1ca;
case 0x0c09f1ccu: goto P_0c09f1cc;
case 0x0c09f1ceu: goto P_0c09f1ce;
case 0x0c09f1d0u: goto P_0c09f1d0;
case 0x0c09f1d2u: goto P_0c09f1d2;
case 0x0c09f1d4u: goto P_0c09f1d4;
case 0x0c09f1d6u: goto P_0c09f1d6;
case 0x0c09f1d8u: goto P_0c09f1d8;
case 0x0c09f1dau: goto P_0c09f1da;
case 0x0c09f1dcu: goto P_0c09f1dc;
case 0x0c09f1deu: goto P_0c09f1de;
case 0x0c09f1e0u: goto P_0c09f1e0;
case 0x0c09f1e2u: goto P_0c09f1e2;
case 0x0c09f1e4u: goto P_0c09f1e4;
case 0x0c09f1e6u: goto P_0c09f1e6;
case 0x0c09f1e8u: goto P_0c09f1e8;
case 0x0c09f1eau: goto P_0c09f1ea;
case 0x0c09f1ecu: goto P_0c09f1ec;
case 0x0c09f1eeu: goto P_0c09f1ee;
case 0x0c09f1f0u: goto P_0c09f1f0;
case 0x0c09f1f2u: goto P_0c09f1f2;
case 0x0c09f1f4u: goto P_0c09f1f4;
case 0x0c09f1f6u: goto P_0c09f1f6;
case 0x0c09f1f8u: goto P_0c09f1f8;
case 0x0c09f1fau: goto P_0c09f1fa;
case 0x0c09f1fcu: goto P_0c09f1fc;
case 0x0c09f1feu: goto P_0c09f1fe;
case 0x0c09f200u: goto P_0c09f200;
case 0x0c09f202u: goto P_0c09f202;
case 0x0c09f204u: goto P_0c09f204;
case 0x0c09f206u: goto P_0c09f206;
case 0x0c09f208u: goto P_0c09f208;
case 0x0c09f20au: goto P_0c09f20a;
case 0x0c09f20cu: goto P_0c09f20c;
case 0x0c09f20eu: goto P_0c09f20e;
case 0x0c09f210u: goto P_0c09f210;
case 0x0c09f212u: goto P_0c09f212;
case 0x0c09f214u: goto P_0c09f214;
case 0x0c09f216u: goto P_0c09f216;
case 0x0c09f218u: goto P_0c09f218;
case 0x0c09f21au: goto P_0c09f21a;
case 0x0c09f21cu: goto P_0c09f21c;
case 0x0c09f21eu: goto P_0c09f21e;
case 0x0c09f220u: goto P_0c09f220;
case 0x0c09f222u: goto P_0c09f222;
case 0x0c09f224u: goto P_0c09f224;
case 0x0c09f226u: goto P_0c09f226;
case 0x0c09f228u: goto P_0c09f228;
case 0x0c09f22au: goto P_0c09f22a;
case 0x0c09f22cu: goto P_0c09f22c;
case 0x0c09f22eu: goto P_0c09f22e;
case 0x0c09f230u: goto P_0c09f230;
case 0x0c09f232u: goto P_0c09f232;
case 0x0c09f234u: goto P_0c09f234;
case 0x0c09f236u: goto P_0c09f236;
case 0x0c09f238u: goto P_0c09f238;
case 0x0c09f23au: goto P_0c09f23a;
case 0x0c09f23cu: goto P_0c09f23c;
case 0x0c09f23eu: goto P_0c09f23e;
case 0x0c09f240u: goto P_0c09f240;
case 0x0c09f242u: goto P_0c09f242;
case 0x0c09f244u: goto P_0c09f244;
case 0x0c09f246u: goto P_0c09f246;
case 0x0c09f248u: goto P_0c09f248;
case 0x0c09f24au: goto P_0c09f24a;
case 0x0c09f24cu: goto P_0c09f24c;
case 0x0c09f24eu: goto P_0c09f24e;
case 0x0c09f250u: goto P_0c09f250;
case 0x0c09f268u: goto P_0c09f268;
case 0x0c09f26au: goto P_0c09f26a;
case 0x0c09f26cu: goto P_0c09f26c;
case 0x0c09f26eu: goto P_0c09f26e;
case 0x0c09f270u: goto P_0c09f270;
case 0x0c09f272u: goto P_0c09f272;
case 0x0c09f274u: goto P_0c09f274;
case 0x0c09f276u: goto P_0c09f276;
case 0x0c09f278u: goto P_0c09f278;
case 0x0c09f27au: goto P_0c09f27a;
case 0x0c09f27cu: goto P_0c09f27c;
case 0x0c09f27eu: goto P_0c09f27e;
case 0x0c09f280u: goto P_0c09f280;
case 0x0c09f282u: goto P_0c09f282;
case 0x0c09f284u: goto P_0c09f284;
case 0x0c09f286u: goto P_0c09f286;
case 0x0c09f288u: goto P_0c09f288;
case 0x0c09f28au: goto P_0c09f28a;
case 0x0c09f28cu: goto P_0c09f28c;
case 0x0c09f28eu: goto P_0c09f28e;
case 0x0c09f290u: goto P_0c09f290;
case 0x0c09f292u: goto P_0c09f292;
case 0x0c09f294u: goto P_0c09f294;
case 0x0c09f296u: goto P_0c09f296;
case 0x0c09f298u: goto P_0c09f298;
case 0x0c09f29au: goto P_0c09f29a;
case 0x0c09f29cu: goto P_0c09f29c;
case 0x0c09f29eu: goto P_0c09f29e;
case 0x0c09f2a0u: goto P_0c09f2a0;
case 0x0c09f2a2u: goto P_0c09f2a2;
case 0x0c09f2a4u: goto P_0c09f2a4;
case 0x0c09f2a6u: goto P_0c09f2a6;
case 0x0c09f2a8u: goto P_0c09f2a8;
case 0x0c09f2aau: goto P_0c09f2aa;
case 0x0c09f2acu: goto P_0c09f2ac;
case 0x0c09f2aeu: goto P_0c09f2ae;
case 0x0c09f2b0u: goto P_0c09f2b0;
case 0x0c09f2b2u: goto P_0c09f2b2;
case 0x0c09f2b4u: goto P_0c09f2b4;
case 0x0c09f2b6u: goto P_0c09f2b6;
case 0x0c09f2b8u: goto P_0c09f2b8;
case 0x0c09f2bau: goto P_0c09f2ba;
case 0x0c09f2bcu: goto P_0c09f2bc;
case 0x0c09f2beu: goto P_0c09f2be;
case 0x0c09f2c0u: goto P_0c09f2c0;
case 0x0c09f2c2u: goto P_0c09f2c2;
case 0x0c09f2c4u: goto P_0c09f2c4;
case 0x0c09f2c6u: goto P_0c09f2c6;
case 0x0c09f2c8u: goto P_0c09f2c8;
case 0x0c09f2cau: goto P_0c09f2ca;
case 0x0c09f2ccu: goto P_0c09f2cc;
case 0x0c09f2ceu: goto P_0c09f2ce;
case 0x0c09f2d0u: goto P_0c09f2d0;
case 0x0c09f2d2u: goto P_0c09f2d2;
case 0x0c09f2d4u: goto P_0c09f2d4;
case 0x0c09f2d6u: goto P_0c09f2d6;
case 0x0c09f2d8u: goto P_0c09f2d8;
case 0x0c09f2dau: goto P_0c09f2da;
case 0x0c09f2dcu: goto P_0c09f2dc;
case 0x0c09f2deu: goto P_0c09f2de;
case 0x0c09f2e0u: goto P_0c09f2e0;
case 0x0c09f2e2u: goto P_0c09f2e2;
case 0x0c09f2e4u: goto P_0c09f2e4;
case 0x0c09f2e6u: goto P_0c09f2e6;
case 0x0c09f2e8u: goto P_0c09f2e8;
case 0x0c09f2eau: goto P_0c09f2ea;
case 0x0c09f2ecu: goto P_0c09f2ec;
case 0x0c09f2eeu: goto P_0c09f2ee;
case 0x0c09f2f0u: goto P_0c09f2f0;
case 0x0c09f2f2u: goto P_0c09f2f2;
case 0x0c09f2f4u: goto P_0c09f2f4;
case 0x0c09f2f6u: goto P_0c09f2f6;
case 0x0c09f2f8u: goto P_0c09f2f8;
case 0x0c09f2fau: goto P_0c09f2fa;
case 0x0c09f2fcu: goto P_0c09f2fc;
case 0x0c09f2feu: goto P_0c09f2fe;
case 0x0c09f300u: goto P_0c09f300;
case 0x0c09f302u: goto P_0c09f302;
case 0x0c09f304u: goto P_0c09f304;
case 0x0c09f306u: goto P_0c09f306;
case 0x0c09f308u: goto P_0c09f308;
case 0x0c09f30au: goto P_0c09f30a;
case 0x0c09f30cu: goto P_0c09f30c;
case 0x0c09f30eu: goto P_0c09f30e;
case 0x0c09f310u: goto P_0c09f310;
case 0x0c09f312u: goto P_0c09f312;
case 0x0c09f314u: goto P_0c09f314;
case 0x0c09f316u: goto P_0c09f316;
case 0x0c09f318u: goto P_0c09f318;
case 0x0c09f31au: goto P_0c09f31a;
case 0x0c09f31cu: goto P_0c09f31c;
case 0x0c09f31eu: goto P_0c09f31e;
case 0x0c09f320u: goto P_0c09f320;
case 0x0c09f322u: goto P_0c09f322;
case 0x0c09f324u: goto P_0c09f324;
case 0x0c09f326u: goto P_0c09f326;
case 0x0c09f328u: goto P_0c09f328;
case 0x0c09f32au: goto P_0c09f32a;
case 0x0c09f32cu: goto P_0c09f32c;
case 0x0c09f32eu: goto P_0c09f32e;
case 0x0c09f330u: goto P_0c09f330;
case 0x0c09f332u: goto P_0c09f332;
case 0x0c09f334u: goto P_0c09f334;
case 0x0c0ac900u: goto P_0c0ac900;
case 0x0c0ac902u: goto P_0c0ac902;
case 0x0c0ac904u: goto P_0c0ac904;
case 0x0c0ac906u: goto P_0c0ac906;
case 0x0c0ac908u: goto P_0c0ac908;
case 0x0c0ac90au: goto P_0c0ac90a;
case 0x0c0ac90cu: goto P_0c0ac90c;
case 0x0c0ac90eu: goto P_0c0ac90e;
case 0x0c0ac910u: goto P_0c0ac910;
case 0x0c0ac912u: goto P_0c0ac912;
case 0x0c0ac914u: goto P_0c0ac914;
case 0x0c0ac916u: goto P_0c0ac916;
case 0x0c0ac918u: goto P_0c0ac918;
case 0x0c0ac91au: goto P_0c0ac91a;
case 0x0c0ac91cu: goto P_0c0ac91c;
case 0x0c0ac91eu: goto P_0c0ac91e;
case 0x0c0ac920u: goto P_0c0ac920;
case 0x0c0ac922u: goto P_0c0ac922;
case 0x0c0ac924u: goto P_0c0ac924;
case 0x0c0ac926u: goto P_0c0ac926;
case 0x0c0ac928u: goto P_0c0ac928;
case 0x0c0ac92au: goto P_0c0ac92a;
case 0x0c0ac92cu: goto P_0c0ac92c;
case 0x0c0ac92eu: goto P_0c0ac92e;
case 0x0c0ac930u: goto P_0c0ac930;
case 0x0c0ac932u: goto P_0c0ac932;
case 0x0c0ac934u: goto P_0c0ac934;
case 0x0c0ac936u: goto P_0c0ac936;
case 0x0c0ac938u: goto P_0c0ac938;
case 0x0c0ac93au: goto P_0c0ac93a;
case 0x0c0ac93cu: goto P_0c0ac93c;
case 0x0c0ac93eu: goto P_0c0ac93e;
case 0x0c0ac940u: goto P_0c0ac940;
case 0x0c0ac942u: goto P_0c0ac942;
case 0x0c0ac944u: goto P_0c0ac944;
case 0x0c0ac946u: goto P_0c0ac946;
case 0x0c0ac948u: goto P_0c0ac948;
case 0x0c0ac968u: goto P_0c0ac968;
case 0x0c0ac96au: goto P_0c0ac96a;
case 0x0c0ac96cu: goto P_0c0ac96c;
case 0x0c0ac96eu: goto P_0c0ac96e;
case 0x0c0ac970u: goto P_0c0ac970;
case 0x0c0ac972u: goto P_0c0ac972;
case 0x0c0ac974u: goto P_0c0ac974;
case 0x0c0ac976u: goto P_0c0ac976;
case 0x0c0ac978u: goto P_0c0ac978;
case 0x0c0ac97au: goto P_0c0ac97a;
case 0x0c0ac97cu: goto P_0c0ac97c;
case 0x0c0ac97eu: goto P_0c0ac97e;
case 0x0c0ac980u: goto P_0c0ac980;
case 0x0c0ac982u: goto P_0c0ac982;
case 0x0c0ac984u: goto P_0c0ac984;
case 0x0c0ac986u: goto P_0c0ac986;
case 0x0c0ac988u: goto P_0c0ac988;
case 0x0c0ac98au: goto P_0c0ac98a;
case 0x0c0ac98cu: goto P_0c0ac98c;
case 0x0c0ac98eu: goto P_0c0ac98e;
case 0x0c0ac990u: goto P_0c0ac990;
case 0x0c0ac992u: goto P_0c0ac992;
case 0x0c0ac994u: goto P_0c0ac994;
case 0x0c0ac996u: goto P_0c0ac996;
case 0x0c0ac998u: goto P_0c0ac998;
case 0x0c0ac99au: goto P_0c0ac99a;
case 0x0c0ac99cu: goto P_0c0ac99c;
case 0x0c0ac99eu: goto P_0c0ac99e;
case 0x0c0ac9a0u: goto P_0c0ac9a0;
case 0x0c0ac9a2u: goto P_0c0ac9a2;
case 0x0c0ac9a4u: goto P_0c0ac9a4;
case 0x0c0ac9a6u: goto P_0c0ac9a6;
case 0x0c0ac9a8u: goto P_0c0ac9a8;
case 0x0c0ac9aau: goto P_0c0ac9aa;
case 0x0c0ac9acu: goto P_0c0ac9ac;
case 0x0c0ac9aeu: goto P_0c0ac9ae;
case 0x0c0ac9b0u: goto P_0c0ac9b0;
case 0x0c0ac9b2u: goto P_0c0ac9b2;
case 0x0c0ac9b4u: goto P_0c0ac9b4;
case 0x0c0ac9b6u: goto P_0c0ac9b6;
case 0x0c0ac9b8u: goto P_0c0ac9b8;
case 0x0c0ac9bau: goto P_0c0ac9ba;
case 0x0c0ac9bcu: goto P_0c0ac9bc;
case 0x0c0ac9beu: goto P_0c0ac9be;
case 0x0c0ac9c0u: goto P_0c0ac9c0;
case 0x0c0ac9c2u: goto P_0c0ac9c2;
case 0x0c0ac9c4u: goto P_0c0ac9c4;
case 0x0c0ac9c6u: goto P_0c0ac9c6;
case 0x0c0ac9c8u: goto P_0c0ac9c8;
case 0x0c0ac9cau: goto P_0c0ac9ca;
case 0x0c0ac9ccu: goto P_0c0ac9cc;
case 0x0c0ac9ceu: goto P_0c0ac9ce;
case 0x0c0ac9d0u: goto P_0c0ac9d0;
case 0x0c0ac9d2u: goto P_0c0ac9d2;
case 0x0c0ac9d4u: goto P_0c0ac9d4;
case 0x0c0ac9d6u: goto P_0c0ac9d6;
case 0x0c0ac9d8u: goto P_0c0ac9d8;
case 0x0c0ac9dau: goto P_0c0ac9da;
case 0x0c0ac9dcu: goto P_0c0ac9dc;
case 0x0c0ac9deu: goto P_0c0ac9de;
case 0x0c0ac9e0u: goto P_0c0ac9e0;
case 0x0c0ac9e2u: goto P_0c0ac9e2;
case 0x0c0ac9e4u: goto P_0c0ac9e4;
case 0x0c0ac9e6u: goto P_0c0ac9e6;
case 0x0c0ac9e8u: goto P_0c0ac9e8;
case 0x0c0ac9eau: goto P_0c0ac9ea;
case 0x0c0ac9ecu: goto P_0c0ac9ec;
case 0x0c0ac9eeu: goto P_0c0ac9ee;
case 0x0c0ac9f0u: goto P_0c0ac9f0;
case 0x0c0ac9f2u: goto P_0c0ac9f2;
case 0x0c0ac9f4u: goto P_0c0ac9f4;
case 0x0c0ac9f6u: goto P_0c0ac9f6;
case 0x0c0ac9f8u: goto P_0c0ac9f8;
case 0x0c0ac9fau: goto P_0c0ac9fa;
case 0x0c0ac9fcu: goto P_0c0ac9fc;
case 0x0c0ac9feu: goto P_0c0ac9fe;
case 0x0c0aca00u: goto P_0c0aca00;
case 0x0c0aca02u: goto P_0c0aca02;
case 0x0c0aca04u: goto P_0c0aca04;
case 0x0c0aca06u: goto P_0c0aca06;
case 0x0c0aca08u: goto P_0c0aca08;
case 0x0c0aca0au: goto P_0c0aca0a;
case 0x0c0aca0cu: goto P_0c0aca0c;
case 0x0c0aca0eu: goto P_0c0aca0e;
case 0x0c0aca10u: goto P_0c0aca10;
case 0x0c0aca12u: goto P_0c0aca12;
case 0x0c0aca14u: goto P_0c0aca14;
case 0x0c0aca16u: goto P_0c0aca16;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09efce: /* original 933f, guest PC 0x0c09efce */
if(!s->budget--) { s->failed_pc=0x0c09efceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09efd0;
P_0c09efd0: /* original e042, guest PC 0x0c09efd0 */
if(!s->budget--) { s->failed_pc=0x0c09efd0u; return 0; }
r[0]=0x00000042u;
goto P_0c09efd2;
P_0c09efd2: /* original 0435, guest PC 0x0c09efd2 */
if(!s->budget--) { s->failed_pc=0x0c09efd2u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efd4;
P_0c09efd4: /* original a000, guest PC 0x0c09efd4 */
if(!s->budget--) { s->failed_pc=0x0c09efd4u; return 0; }
goto P_0c09efd8;
P_0c09efd6: /* original 0009, guest PC 0x0c09efd6 */
if(!s->budget--) { s->failed_pc=0x0c09efd6u; return 0; }
goto P_0c09efd8;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c09efe6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09efe6u; return 0; } return 1;
P_0c09f1ac: /* original e048, guest PC 0x0c09f1ac */
if(!s->budget--) { s->failed_pc=0x0c09f1acu; return 0; }
r[0]=0x00000048u;
goto P_0c09f1ae;
P_0c09f1ae: /* original 2fe6, guest PC 0x0c09f1ae */
if(!s->budget--) { s->failed_pc=0x0c09f1aeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b0;
P_0c09f1b0: /* original 2fd6, guest PC 0x0c09f1b0 */
if(!s->budget--) { s->failed_pc=0x0c09f1b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b2;
P_0c09f1b2: /* original e304, guest PC 0x0c09f1b2 */
if(!s->budget--) { s->failed_pc=0x0c09f1b2u; return 0; }
r[3]=0x00000004u;
goto P_0c09f1b4;
P_0c09f1b4: /* original 2fc6, guest PC 0x0c09f1b4 */
if(!s->budget--) { s->failed_pc=0x0c09f1b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1b6;
P_0c09f1b6: /* original e520, guest PC 0x0c09f1b6 */
if(!s->budget--) { s->failed_pc=0x0c09f1b6u; return 0; }
r[5]=0x00000020u;
goto P_0c09f1b8;
P_0c09f1b8: /* original 2fb6, guest PC 0x0c09f1b8 */
if(!s->budget--) { s->failed_pc=0x0c09f1b8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1ba;
P_0c09f1ba: /* original e210, guest PC 0x0c09f1ba */
if(!s->budget--) { s->failed_pc=0x0c09f1bau; return 0; }
r[2]=0x00000010u;
goto P_0c09f1bc;
P_0c09f1bc: /* original 2fa6, guest PC 0x0c09f1bc */
if(!s->budget--) { s->failed_pc=0x0c09f1bcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1be;
P_0c09f1be: /* original e700, guest PC 0x0c09f1be */
if(!s->budget--) { s->failed_pc=0x0c09f1beu; return 0; }
r[7]=0x00000000u;
goto P_0c09f1c0;
P_0c09f1c0: /* original 2f96, guest PC 0x0c09f1c0 */
if(!s->budget--) { s->failed_pc=0x0c09f1c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c2;
P_0c09f1c2: /* original 2f86, guest PC 0x0c09f1c2 */
if(!s->budget--) { s->failed_pc=0x0c09f1c2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f1c4;
P_0c09f1c4: /* original 064e, guest PC 0x0c09f1c4 */
if(!s->budget--) { s->failed_pc=0x0c09f1c4u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f1c6;
P_0c09f1c6: /* original 7fec, guest PC 0x0c09f1c6 */
if(!s->budget--) { s->failed_pc=0x0c09f1c6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09f1c8;
P_0c09f1c8: /* original 2f32, guest PC 0x0c09f1c8 */
if(!s->budget--) { s->failed_pc=0x0c09f1c8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f1ca;
P_0c09f1ca: /* original 9042, guest PC 0x0c09f1ca */
if(!s->budget--) { s->failed_pc=0x0c09f1cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f252u,2);
goto P_0c09f1cc;
P_0c09f1cc: /* original dc23, guest PC 0x0c09f1cc */
if(!s->budget--) { s->failed_pc=0x0c09f1ccu; return 0; }
r[12]=read(ram,0x0c09f25cu,4);
goto P_0c09f1ce;
P_0c09f1ce: /* original 0e4c, guest PC 0x0c09f1ce */
if(!s->budget--) { s->failed_pc=0x0c09f1ceu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1d0;
P_0c09f1d0: /* original db21, guest PC 0x0c09f1d0 */
if(!s->budget--) { s->failed_pc=0x0c09f1d0u; return 0; }
r[11]=read(ram,0x0c09f258u,4);
goto P_0c09f1d2;
P_0c09f1d2: /* original 6eec, guest PC 0x0c09f1d2 */
if(!s->budget--) { s->failed_pc=0x0c09f1d2u; return 0; }
r[14]=r[14]&255u;
goto P_0c09f1d4;
P_0c09f1d4: /* original 60e3, guest PC 0x0c09f1d4 */
if(!s->budget--) { s->failed_pc=0x0c09f1d4u; return 0; }
r[0]=r[14];
goto P_0c09f1d6;
P_0c09f1d6: /* original 4001, guest PC 0x0c09f1d6 */
if(!s->budget--) { s->failed_pc=0x0c09f1d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c09f1d8;
P_0c09f1d8: /* original 6303, guest PC 0x0c09f1d8 */
if(!s->budget--) { s->failed_pc=0x0c09f1d8u; return 0; }
r[3]=r[0];
goto P_0c09f1da;
P_0c09f1da: /* original 60e3, guest PC 0x0c09f1da */
if(!s->budget--) { s->failed_pc=0x0c09f1dau; return 0; }
r[0]=r[14];
goto P_0c09f1dc;
P_0c09f1dc: /* original c901, guest PC 0x0c09f1dc */
if(!s->budget--) { s->failed_pc=0x0c09f1dcu; return 0; }
r[0]&=1u;
goto P_0c09f1de;
P_0c09f1de: /* original 4005, guest PC 0x0c09f1de */
if(!s->budget--) { s->failed_pc=0x0c09f1deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c09f1e0;
P_0c09f1e0: /* original 203b, guest PC 0x0c09f1e0 */
if(!s->budget--) { s->failed_pc=0x0c09f1e0u; return 0; }
r[0]|=r[3];
goto P_0c09f1e2;
P_0c09f1e2: /* original 2509, guest PC 0x0c09f1e2 */
if(!s->budget--) { s->failed_pc=0x0c09f1e2u; return 0; }
r[5]&=r[0];
goto P_0c09f1e4;
P_0c09f1e4: /* original 9036, guest PC 0x0c09f1e4 */
if(!s->budget--) { s->failed_pc=0x0c09f1e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f254u,2);
goto P_0c09f1e6;
P_0c09f1e6: /* original 252b, guest PC 0x0c09f1e6 */
if(!s->budget--) { s->failed_pc=0x0c09f1e6u; return 0; }
r[5]|=r[2];
goto P_0c09f1e8;
P_0c09f1e8: /* original 034c, guest PC 0x0c09f1e8 */
if(!s->budget--) { s->failed_pc=0x0c09f1e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f1ea;
P_0c09f1ea: /* original 633c, guest PC 0x0c09f1ea */
if(!s->budget--) { s->failed_pc=0x0c09f1eau; return 0; }
r[3]=r[3]&255u;
goto P_0c09f1ec;
P_0c09f1ec: /* original 6853, guest PC 0x0c09f1ec */
if(!s->budget--) { s->failed_pc=0x0c09f1ecu; return 0; }
r[8]=r[5];
goto P_0c09f1ee;
P_0c09f1ee: /* original 1f31, guest PC 0x0c09f1ee */
if(!s->budget--) { s->failed_pc=0x0c09f1eeu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f1f0;
P_0c09f1f0: /* original 61f2, guest PC 0x0c09f1f0 */
if(!s->budget--) { s->failed_pc=0x0c09f1f0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09f1f2;
P_0c09f1f2: /* original e902, guest PC 0x0c09f1f2 */
if(!s->budget--) { s->failed_pc=0x0c09f1f2u; return 0; }
r[9]=0x00000002u;
goto P_0c09f1f4;
P_0c09f1f4: /* original 2168, guest PC 0x0c09f1f4 */
if(!s->budget--) { s->failed_pc=0x0c09f1f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c09f1f6;
P_0c09f1f6: /* original 8f2a, guest PC 0x0c09f1f6 */
if(!s->budget--) { s->failed_pc=0x0c09f1f6u; return 0; }
cond=r[17]&1u;
r[8]|=r[9];
if(!cond) { goto P_0c09f24e; }
goto P_0c09f1fa;
P_0c09f1f8: /* original 289b, guest PC 0x0c09f1f8 */
if(!s->budget--) { s->failed_pc=0x0c09f1f8u; return 0; }
r[8]|=r[9];
goto P_0c09f1fa;
P_0c09f1fa: /* original 53f1, guest PC 0x0c09f1fa */
if(!s->budget--) { s->failed_pc=0x0c09f1fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f1fc;
P_0c09f1fc: /* original 2338, guest PC 0x0c09f1fc */
if(!s->budget--) { s->failed_pc=0x0c09f1fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f1fe;
P_0c09f1fe: /* original 8b26, guest PC 0x0c09f1fe */
if(!s->budget--) { s->failed_pc=0x0c09f1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24e; }
goto P_0c09f200;
P_0c09f200: /* original d217, guest PC 0x0c09f200 */
if(!s->budget--) { s->failed_pc=0x0c09f200u; return 0; }
r[2]=read(ram,0x0c09f260u,4);
goto P_0c09f202;
P_0c09f202: /* original 2769, guest PC 0x0c09f202 */
if(!s->budget--) { s->failed_pc=0x0c09f202u; return 0; }
r[7]&=r[6];
goto P_0c09f204;
P_0c09f204: /* original 2b69, guest PC 0x0c09f204 */
if(!s->budget--) { s->failed_pc=0x0c09f204u; return 0; }
r[11]&=r[6];
goto P_0c09f206;
P_0c09f206: /* original 6323, guest PC 0x0c09f206 */
if(!s->budget--) { s->failed_pc=0x0c09f206u; return 0; }
r[3]=r[2];
goto P_0c09f208;
P_0c09f208: /* original 2f22, guest PC 0x0c09f208 */
if(!s->budget--) { s->failed_pc=0x0c09f208u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09f20a;
P_0c09f20a: /* original 9d24, guest PC 0x0c09f20a */
if(!s->budget--) { s->failed_pc=0x0c09f20au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f256u,2);
goto P_0c09f20c;
P_0c09f20c: /* original 2369, guest PC 0x0c09f20c */
if(!s->budget--) { s->failed_pc=0x0c09f20cu; return 0; }
r[3]&=r[6];
goto P_0c09f20e;
P_0c09f20e: /* original da15, guest PC 0x0c09f20e */
if(!s->budget--) { s->failed_pc=0x0c09f20eu; return 0; }
r[10]=read(ram,0x0c09f264u,4);
goto P_0c09f210;
P_0c09f210: /* original 2c69, guest PC 0x0c09f210 */
if(!s->budget--) { s->failed_pc=0x0c09f210u; return 0; }
r[12]&=r[6];
goto P_0c09f212;
P_0c09f212: /* original 2d69, guest PC 0x0c09f212 */
if(!s->budget--) { s->failed_pc=0x0c09f212u; return 0; }
r[13]&=r[6];
goto P_0c09f214;
P_0c09f214: /* original 1f31, guest PC 0x0c09f214 */
if(!s->budget--) { s->failed_pc=0x0c09f214u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f216;
P_0c09f216: /* original 62f2, guest PC 0x0c09f216 */
if(!s->budget--) { s->failed_pc=0x0c09f216u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f218;
P_0c09f218: /* original 26a9, guest PC 0x0c09f218 */
if(!s->budget--) { s->failed_pc=0x0c09f218u; return 0; }
r[6]&=r[10];
goto P_0c09f21a;
P_0c09f21a: /* original 3320, guest PC 0x0c09f21a */
if(!s->budget--) { s->failed_pc=0x0c09f21au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09f21c;
P_0c09f21c: /* original 0029, guest PC 0x0c09f21c */
if(!s->budget--) { s->failed_pc=0x0c09f21cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f21e;
P_0c09f21e: /* original 36a0, guest PC 0x0c09f21e */
if(!s->budget--) { s->failed_pc=0x0c09f21eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[10])!=0);
goto P_0c09f220;
P_0c09f220: /* original ca01, guest PC 0x0c09f220 */
if(!s->budget--) { s->failed_pc=0x0c09f220u; return 0; }
r[0]^=1u;
goto P_0c09f222;
P_0c09f222: /* original 2f02, guest PC 0x0c09f222 */
if(!s->budget--) { s->failed_pc=0x0c09f222u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f224;
P_0c09f224: /* original 0029, guest PC 0x0c09f224 */
if(!s->budget--) { s->failed_pc=0x0c09f224u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f226;
P_0c09f226: /* original ca01, guest PC 0x0c09f226 */
if(!s->budget--) { s->failed_pc=0x0c09f226u; return 0; }
r[0]^=1u;
goto P_0c09f228;
P_0c09f228: /* original 1fb2, guest PC 0x0c09f228 */
if(!s->budget--) { s->failed_pc=0x0c09f228u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c09f22a;
P_0c09f22a: /* original 1fc3, guest PC 0x0c09f22a */
if(!s->budget--) { s->failed_pc=0x0c09f22au; return 0; }
write(ram,r[15]+12,r[12],4);
goto P_0c09f22c;
P_0c09f22c: /* original 1f04, guest PC 0x0c09f22c */
if(!s->budget--) { s->failed_pc=0x0c09f22cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c09f22e;
P_0c09f22e: /* original 1fd1, guest PC 0x0c09f22e */
if(!s->budget--) { s->failed_pc=0x0c09f22eu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c09f230;
P_0c09f230: /* original 62f2, guest PC 0x0c09f230 */
if(!s->budget--) { s->failed_pc=0x0c09f230u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f232;
P_0c09f232: /* original 2228, guest PC 0x0c09f232 */
if(!s->budget--) { s->failed_pc=0x0c09f232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f234;
P_0c09f234: /* original 8d08, guest PC 0x0c09f234 */
if(!s->budget--) { s->failed_pc=0x0c09f234u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c09f248; }
goto P_0c09f238;
P_0c09f236: /* original e601, guest PC 0x0c09f236 */
if(!s->budget--) { s->failed_pc=0x0c09f236u; return 0; }
r[6]=0x00000001u;
goto P_0c09f238;
P_0c09f238: /* original 53f2, guest PC 0x0c09f238 */
if(!s->budget--) { s->failed_pc=0x0c09f238u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f23a;
P_0c09f23a: /* original 2338, guest PC 0x0c09f23a */
if(!s->budget--) { s->failed_pc=0x0c09f23au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f23c;
P_0c09f23c: /* original 8b14, guest PC 0x0c09f23c */
if(!s->budget--) { s->failed_pc=0x0c09f23cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f268; }
goto P_0c09f23e;
P_0c09f23e: /* original 2778, guest PC 0x0c09f23e */
if(!s->budget--) { s->failed_pc=0x0c09f23eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f240;
P_0c09f240: /* original 8b03, guest PC 0x0c09f240 */
if(!s->budget--) { s->failed_pc=0x0c09f240u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f24a; }
goto P_0c09f242;
P_0c09f242: /* original 52f3, guest PC 0x0c09f242 */
if(!s->budget--) { s->failed_pc=0x0c09f242u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f244;
P_0c09f244: /* original 2228, guest PC 0x0c09f244 */
if(!s->budget--) { s->failed_pc=0x0c09f244u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f246;
P_0c09f246: /* original 8b15, guest PC 0x0c09f246 */
if(!s->budget--) { s->failed_pc=0x0c09f246u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f248;
P_0c09f248: /* original 6583, guest PC 0x0c09f248 */
if(!s->budget--) { s->failed_pc=0x0c09f248u; return 0; }
r[5]=r[8];
goto P_0c09f24a;
P_0c09f24a: /* original a014, guest PC 0x0c09f24a */
if(!s->budget--) { s->failed_pc=0x0c09f24au; return 0; }
r[5]|=r[6];
goto P_0c09f276;
P_0c09f24c: /* original 256b, guest PC 0x0c09f24c */
if(!s->budget--) { s->failed_pc=0x0c09f24cu; return 0; }
r[5]|=r[6];
goto P_0c09f24e;
P_0c09f24e: /* original a012, guest PC 0x0c09f24e */
if(!s->budget--) { s->failed_pc=0x0c09f24eu; return 0; }
r[5]=r[8];
goto P_0c09f276;
P_0c09f250: /* original 6583, guest PC 0x0c09f250 */
if(!s->budget--) { s->failed_pc=0x0c09f250u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c09f252u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f252u; return 0; } return 1;
P_0c09f268: /* original e048, guest PC 0x0c09f268 */
if(!s->budget--) { s->failed_pc=0x0c09f268u; return 0; }
r[0]=0x00000048u;
goto P_0c09f26a;
P_0c09f26a: /* original d335, guest PC 0x0c09f26a */
if(!s->budget--) { s->failed_pc=0x0c09f26au; return 0; }
r[3]=read(ram,0x0c09f340u,4);
goto P_0c09f26c;
P_0c09f26c: /* original 024e, guest PC 0x0c09f26c */
if(!s->budget--) { s->failed_pc=0x0c09f26cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c09f26e;
P_0c09f26e: /* original 2238, guest PC 0x0c09f26e */
if(!s->budget--) { s->failed_pc=0x0c09f26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f270;
P_0c09f270: /* original 8b00, guest PC 0x0c09f270 */
if(!s->budget--) { s->failed_pc=0x0c09f270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f274; }
goto P_0c09f272;
P_0c09f272: /* original 256b, guest PC 0x0c09f272 */
if(!s->budget--) { s->failed_pc=0x0c09f272u; return 0; }
r[5]|=r[6];
goto P_0c09f274;
P_0c09f274: /* original 259b, guest PC 0x0c09f274 */
if(!s->budget--) { s->failed_pc=0x0c09f274u; return 0; }
r[5]|=r[9];
goto P_0c09f276;
P_0c09f276: /* original 905e, guest PC 0x0c09f276 */
if(!s->budget--) { s->failed_pc=0x0c09f276u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f336u,2);
goto P_0c09f278;
P_0c09f278: /* original e30f, guest PC 0x0c09f278 */
if(!s->budget--) { s->failed_pc=0x0c09f278u; return 0; }
r[3]=0x0000000fu;
goto P_0c09f27a;
P_0c09f27a: /* original e208, guest PC 0x0c09f27a */
if(!s->budget--) { s->failed_pc=0x0c09f27au; return 0; }
r[2]=0x00000008u;
goto P_0c09f27c;
P_0c09f27c: /* original 0d4d, guest PC 0x0c09f27c */
if(!s->budget--) { s->failed_pc=0x0c09f27cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f27e;
P_0c09f27e: /* original e03e, guest PC 0x0c09f27e */
if(!s->budget--) { s->failed_pc=0x0c09f27eu; return 0; }
r[0]=0x0000003eu;
goto P_0c09f280;
P_0c09f280: /* original 064d, guest PC 0x0c09f280 */
if(!s->budget--) { s->failed_pc=0x0c09f280u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09f282;
P_0c09f282: /* original 6ddd, guest PC 0x0c09f282 */
if(!s->budget--) { s->failed_pc=0x0c09f282u; return 0; }
r[13]=r[13]&65535u;
goto P_0c09f284;
P_0c09f284: /* original 67d3, guest PC 0x0c09f284 */
if(!s->budget--) { s->failed_pc=0x0c09f284u; return 0; }
r[7]=r[13];
goto P_0c09f286;
P_0c09f286: /* original 666d, guest PC 0x0c09f286 */
if(!s->budget--) { s->failed_pc=0x0c09f286u; return 0; }
r[6]=r[6]&65535u;
goto P_0c09f288;
P_0c09f288: /* original 3768, guest PC 0x0c09f288 */
if(!s->budget--) { s->failed_pc=0x0c09f288u; return 0; }
r[7]-=r[6];
goto P_0c09f28a;
P_0c09f28a: /* original 3732, guest PC 0x0c09f28a */
if(!s->budget--) { s->failed_pc=0x0c09f28au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[3])!=0);
goto P_0c09f28c;
P_0c09f28c: /* original 0029, guest PC 0x0c09f28c */
if(!s->budget--) { s->failed_pc=0x0c09f28cu; return 0; }
r[0]=r[17]&1u;
goto P_0c09f28e;
P_0c09f28e: /* original 3726, guest PC 0x0c09f28e */
if(!s->budget--) { s->failed_pc=0x0c09f28eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[2])!=0);
goto P_0c09f290;
P_0c09f290: /* original 1f02, guest PC 0x0c09f290 */
if(!s->budget--) { s->failed_pc=0x0c09f290u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09f292;
P_0c09f292: /* original 0029, guest PC 0x0c09f292 */
if(!s->budget--) { s->failed_pc=0x0c09f292u; return 0; }
r[0]=r[17]&1u;
goto P_0c09f294;
P_0c09f294: /* original 1f03, guest PC 0x0c09f294 */
if(!s->budget--) { s->failed_pc=0x0c09f294u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c09f296;
P_0c09f296: /* original 6763, guest PC 0x0c09f296 */
if(!s->budget--) { s->failed_pc=0x0c09f296u; return 0; }
r[7]=r[6];
goto P_0c09f298;
P_0c09f298: /* original 53f1, guest PC 0x0c09f298 */
if(!s->budget--) { s->failed_pc=0x0c09f298u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f29a;
P_0c09f29a: /* original 2338, guest PC 0x0c09f29a */
if(!s->budget--) { s->failed_pc=0x0c09f29au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f29c;
P_0c09f29c: /* original 8f02, guest PC 0x0c09f29c */
if(!s->budget--) { s->failed_pc=0x0c09f29cu; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000eu;
if(!cond) { goto P_0c09f2a4; }
goto P_0c09f2a0;
P_0c09f29e: /* original 770e, guest PC 0x0c09f29e */
if(!s->budget--) { s->failed_pc=0x0c09f29eu; return 0; }
r[7]+=0x0000000eu;
goto P_0c09f2a0;
P_0c09f2a0: /* original 6763, guest PC 0x0c09f2a0 */
if(!s->budget--) { s->failed_pc=0x0c09f2a0u; return 0; }
r[7]=r[6];
goto P_0c09f2a2;
P_0c09f2a2: /* original 7707, guest PC 0x0c09f2a2 */
if(!s->budget--) { s->failed_pc=0x0c09f2a2u; return 0; }
r[7]+=0x00000007u;
goto P_0c09f2a4;
P_0c09f2a4: /* original 6cd3, guest PC 0x0c09f2a4 */
if(!s->budget--) { s->failed_pc=0x0c09f2a4u; return 0; }
r[12]=r[13];
goto P_0c09f2a6;
P_0c09f2a6: /* original 7cf9, guest PC 0x0c09f2a6 */
if(!s->budget--) { s->failed_pc=0x0c09f2a6u; return 0; }
r[12]+=0xfffffff9u;
goto P_0c09f2a8;
P_0c09f2a8: /* original 2fc2, guest PC 0x0c09f2a8 */
if(!s->budget--) { s->failed_pc=0x0c09f2a8u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c09f2aa;
P_0c09f2aa: /* original 53f4, guest PC 0x0c09f2aa */
if(!s->budget--) { s->failed_pc=0x0c09f2aau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c09f2ac;
P_0c09f2ac: /* original 2338, guest PC 0x0c09f2ac */
if(!s->budget--) { s->failed_pc=0x0c09f2acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ae;
P_0c09f2ae: /* original 8b02, guest PC 0x0c09f2ae */
if(!s->budget--) { s->failed_pc=0x0c09f2aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2b6; }
goto P_0c09f2b0;
P_0c09f2b0: /* original 6cf2, guest PC 0x0c09f2b0 */
if(!s->budget--) { s->failed_pc=0x0c09f2b0u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c09f2b2;
P_0c09f2b2: /* original 6763, guest PC 0x0c09f2b2 */
if(!s->budget--) { s->failed_pc=0x0c09f2b2u; return 0; }
r[7]=r[6];
goto P_0c09f2b4;
P_0c09f2b4: /* original 7701, guest PC 0x0c09f2b4 */
if(!s->budget--) { s->failed_pc=0x0c09f2b4u; return 0; }
r[7]+=0x00000001u;
goto P_0c09f2b6;
P_0c09f2b6: /* original 53f2, guest PC 0x0c09f2b6 */
if(!s->budget--) { s->failed_pc=0x0c09f2b6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c09f2b8;
P_0c09f2b8: /* original 2338, guest PC 0x0c09f2b8 */
if(!s->budget--) { s->failed_pc=0x0c09f2b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f2ba;
P_0c09f2ba: /* original 8b07, guest PC 0x0c09f2ba */
if(!s->budget--) { s->failed_pc=0x0c09f2bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2bc;
P_0c09f2bc: /* original 52f3, guest PC 0x0c09f2bc */
if(!s->budget--) { s->failed_pc=0x0c09f2bcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c09f2be;
P_0c09f2be: /* original 6c73, guest PC 0x0c09f2be */
if(!s->budget--) { s->failed_pc=0x0c09f2beu; return 0; }
r[12]=r[7];
goto P_0c09f2c0;
P_0c09f2c0: /* original 2228, guest PC 0x0c09f2c0 */
if(!s->budget--) { s->failed_pc=0x0c09f2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f2c2;
P_0c09f2c2: /* original 8f03, guest PC 0x0c09f2c2 */
if(!s->budget--) { s->failed_pc=0x0c09f2c2u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c09f2cc; }
goto P_0c09f2c6;
P_0c09f2c4: /* original 7c01, guest PC 0x0c09f2c4 */
if(!s->budget--) { s->failed_pc=0x0c09f2c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2c6;
P_0c09f2c6: /* original 6cd3, guest PC 0x0c09f2c6 */
if(!s->budget--) { s->failed_pc=0x0c09f2c6u; return 0; }
r[12]=r[13];
goto P_0c09f2c8;
P_0c09f2c8: /* original 7c01, guest PC 0x0c09f2c8 */
if(!s->budget--) { s->failed_pc=0x0c09f2c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c09f2ca;
P_0c09f2ca: /* original 67d3, guest PC 0x0c09f2ca */
if(!s->budget--) { s->failed_pc=0x0c09f2cau; return 0; }
r[7]=r[13];
goto P_0c09f2cc;
P_0c09f2cc: /* original 9034, guest PC 0x0c09f2cc */
if(!s->budget--) { s->failed_pc=0x0c09f2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f338u,2);
goto P_0c09f2ce;
P_0c09f2ce: /* original e200, guest PC 0x0c09f2ce */
if(!s->budget--) { s->failed_pc=0x0c09f2ceu; return 0; }
r[2]=0x00000000u;
goto P_0c09f2d0;
P_0c09f2d0: /* original 76ff, guest PC 0x0c09f2d0 */
if(!s->budget--) { s->failed_pc=0x0c09f2d0u; return 0; }
r[6]+=0xffffffffu;
goto P_0c09f2d2;
P_0c09f2d2: /* original 0424, guest PC 0x0c09f2d2 */
if(!s->budget--) { s->failed_pc=0x0c09f2d2u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09f2d4;
P_0c09f2d4: /* original 70f0, guest PC 0x0c09f2d4 */
if(!s->budget--) { s->failed_pc=0x0c09f2d4u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09f2d6;
P_0c09f2d6: /* original 0475, guest PC 0x0c09f2d6 */
if(!s->budget--) { s->failed_pc=0x0c09f2d6u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c09f2d8;
P_0c09f2d8: /* original 7002, guest PC 0x0c09f2d8 */
if(!s->budget--) { s->failed_pc=0x0c09f2d8u; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2da;
P_0c09f2da: /* original 04c5, guest PC 0x0c09f2da */
if(!s->budget--) { s->failed_pc=0x0c09f2dau; return 0; }
write(ram,r[4]+r[0],r[12],2);
goto P_0c09f2dc;
P_0c09f2dc: /* original 7002, guest PC 0x0c09f2dc */
if(!s->budget--) { s->failed_pc=0x0c09f2dcu; return 0; }
r[0]+=0x00000002u;
goto P_0c09f2de;
P_0c09f2de: /* original 0465, guest PC 0x0c09f2de */
if(!s->budget--) { s->failed_pc=0x0c09f2deu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c09f2e0;
P_0c09f2e0: /* original e04c, guest PC 0x0c09f2e0 */
if(!s->budget--) { s->failed_pc=0x0c09f2e0u; return 0; }
r[0]=0x0000004cu;
goto P_0c09f2e2;
P_0c09f2e2: /* original d318, guest PC 0x0c09f2e2 */
if(!s->budget--) { s->failed_pc=0x0c09f2e2u; return 0; }
r[3]=read(ram,0x0c09f344u,4);
goto P_0c09f2e4;
P_0c09f2e4: /* original 29e9, guest PC 0x0c09f2e4 */
if(!s->budget--) { s->failed_pc=0x0c09f2e4u; return 0; }
r[9]&=r[14];
goto P_0c09f2e6;
P_0c09f2e6: /* original 064e, guest PC 0x0c09f2e6 */
if(!s->budget--) { s->failed_pc=0x0c09f2e6u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c09f2e8;
P_0c09f2e8: /* original 2369, guest PC 0x0c09f2e8 */
if(!s->budget--) { s->failed_pc=0x0c09f2e8u; return 0; }
r[3]&=r[6];
goto P_0c09f2ea;
P_0c09f2ea: /* original 1f31, guest PC 0x0c09f2ea */
if(!s->budget--) { s->failed_pc=0x0c09f2eau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2ec;
P_0c09f2ec: /* original d716, guest PC 0x0c09f2ec */
if(!s->budget--) { s->failed_pc=0x0c09f2ecu; return 0; }
r[7]=read(ram,0x0c09f348u,4);
goto P_0c09f2ee;
P_0c09f2ee: /* original 2f92, guest PC 0x0c09f2ee */
if(!s->budget--) { s->failed_pc=0x0c09f2eeu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c09f2f0;
P_0c09f2f0: /* original d216, guest PC 0x0c09f2f0 */
if(!s->budget--) { s->failed_pc=0x0c09f2f0u; return 0; }
r[2]=read(ram,0x0c09f34cu,4);
goto P_0c09f2f2;
P_0c09f2f2: /* original 2769, guest PC 0x0c09f2f2 */
if(!s->budget--) { s->failed_pc=0x0c09f2f2u; return 0; }
r[7]&=r[6];
goto P_0c09f2f4;
P_0c09f2f4: /* original 1f31, guest PC 0x0c09f2f4 */
if(!s->budget--) { s->failed_pc=0x0c09f2f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f2f6;
P_0c09f2f6: /* original 2629, guest PC 0x0c09f2f6 */
if(!s->budget--) { s->failed_pc=0x0c09f2f6u; return 0; }
r[6]&=r[2];
goto P_0c09f2f8;
P_0c09f2f8: /* original 1f64, guest PC 0x0c09f2f8 */
if(!s->budget--) { s->failed_pc=0x0c09f2f8u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c09f2fa;
P_0c09f2fa: /* original 53f1, guest PC 0x0c09f2fa */
if(!s->budget--) { s->failed_pc=0x0c09f2fau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f2fc;
P_0c09f2fc: /* original 961d, guest PC 0x0c09f2fc */
if(!s->budget--) { s->failed_pc=0x0c09f2fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33au,2);
goto P_0c09f2fe;
P_0c09f2fe: /* original 2338, guest PC 0x0c09f2fe */
if(!s->budget--) { s->failed_pc=0x0c09f2feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f300;
P_0c09f300: /* original 8900, guest PC 0x0c09f300 */
if(!s->budget--) { s->failed_pc=0x0c09f300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f304; }
goto P_0c09f302;
P_0c09f302: /* original 2569, guest PC 0x0c09f302 */
if(!s->budget--) { s->failed_pc=0x0c09f302u; return 0; }
r[5]&=r[6];
goto P_0c09f304;
P_0c09f304: /* original 2778, guest PC 0x0c09f304 */
if(!s->budget--) { s->failed_pc=0x0c09f304u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f306;
P_0c09f306: /* original 8901, guest PC 0x0c09f306 */
if(!s->budget--) { s->failed_pc=0x0c09f306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f30c; }
goto P_0c09f308;
P_0c09f308: /* original 9218, guest PC 0x0c09f308 */
if(!s->budget--) { s->failed_pc=0x0c09f308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33cu,2);
goto P_0c09f30a;
P_0c09f30a: /* original 2529, guest PC 0x0c09f30a */
if(!s->budget--) { s->failed_pc=0x0c09f30au; return 0; }
r[5]&=r[2];
goto P_0c09f30c;
P_0c09f30c: /* original 63f2, guest PC 0x0c09f30c */
if(!s->budget--) { s->failed_pc=0x0c09f30cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f30e;
P_0c09f30e: /* original 2338, guest PC 0x0c09f30e */
if(!s->budget--) { s->failed_pc=0x0c09f30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f310;
P_0c09f310: /* original 8b00, guest PC 0x0c09f310 */
if(!s->budget--) { s->failed_pc=0x0c09f310u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f314; }
goto P_0c09f312;
P_0c09f312: /* original 2569, guest PC 0x0c09f312 */
if(!s->budget--) { s->failed_pc=0x0c09f312u; return 0; }
r[5]&=r[6];
goto P_0c09f314;
P_0c09f314: /* original 52f4, guest PC 0x0c09f314 */
if(!s->budget--) { s->failed_pc=0x0c09f314u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c09f316;
P_0c09f316: /* original 2228, guest PC 0x0c09f316 */
if(!s->budget--) { s->failed_pc=0x0c09f316u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f318;
P_0c09f318: /* original 8901, guest PC 0x0c09f318 */
if(!s->budget--) { s->failed_pc=0x0c09f318u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f31e; }
goto P_0c09f31a;
P_0c09f31a: /* original e204, guest PC 0x0c09f31a */
if(!s->budget--) { s->failed_pc=0x0c09f31au; return 0; }
r[2]=0x00000004u;
goto P_0c09f31c;
P_0c09f31c: /* original 252b, guest PC 0x0c09f31c */
if(!s->budget--) { s->failed_pc=0x0c09f31cu; return 0; }
r[5]|=r[2];
goto P_0c09f31e;
P_0c09f31e: /* original 7f14, guest PC 0x0c09f31e */
if(!s->budget--) { s->failed_pc=0x0c09f31eu; return 0; }
r[15]+=0x00000014u;
goto P_0c09f320;
P_0c09f320: /* original 900d, guest PC 0x0c09f320 */
if(!s->budget--) { s->failed_pc=0x0c09f320u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f33eu,2);
goto P_0c09f322;
P_0c09f322: /* original 0454, guest PC 0x0c09f322 */
if(!s->budget--) { s->failed_pc=0x0c09f322u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09f324;
P_0c09f324: /* original 68f6, guest PC 0x0c09f324 */
if(!s->budget--) { s->failed_pc=0x0c09f324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09f326;
P_0c09f326: /* original d30a, guest PC 0x0c09f326 */
if(!s->budget--) { s->failed_pc=0x0c09f326u; return 0; }
r[3]=read(ram,0x0c09f350u,4);
goto P_0c09f328;
P_0c09f328: /* original 69f6, guest PC 0x0c09f328 */
if(!s->budget--) { s->failed_pc=0x0c09f328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09f32a;
P_0c09f32a: /* original 6af6, guest PC 0x0c09f32a */
if(!s->budget--) { s->failed_pc=0x0c09f32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09f32c;
P_0c09f32c: /* original 6bf6, guest PC 0x0c09f32c */
if(!s->budget--) { s->failed_pc=0x0c09f32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09f32e;
P_0c09f32e: /* original 6cf6, guest PC 0x0c09f32e */
if(!s->budget--) { s->failed_pc=0x0c09f32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f330;
P_0c09f330: /* original 6df6, guest PC 0x0c09f330 */
if(!s->budget--) { s->failed_pc=0x0c09f330u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f332;
P_0c09f332: /* original 432b, guest PC 0x0c09f332 */
if(!s->budget--) { s->failed_pc=0x0c09f332u; return 0; }
target=r[3];
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
P_0c09f334: /* original 6ef6, guest PC 0x0c09f334 */
if(!s->budget--) { s->failed_pc=0x0c09f334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f336u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f336u; return 0; } return 1;
P_0c0ac900: /* original 2fe6, guest PC 0x0c0ac900 */
if(!s->budget--) { s->failed_pc=0x0c0ac900u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac902;
P_0c0ac902: /* original 6e43, guest PC 0x0c0ac902 */
if(!s->budget--) { s->failed_pc=0x0c0ac902u; return 0; }
r[14]=r[4];
goto P_0c0ac904;
P_0c0ac904: /* original 2fd6, guest PC 0x0c0ac904 */
if(!s->budget--) { s->failed_pc=0x0c0ac904u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac906;
P_0c0ac906: /* original e401, guest PC 0x0c0ac906 */
if(!s->budget--) { s->failed_pc=0x0c0ac906u; return 0; }
r[4]=0x00000001u;
goto P_0c0ac908;
P_0c0ac908: /* original 2fc6, guest PC 0x0c0ac908 */
if(!s->budget--) { s->failed_pc=0x0c0ac908u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac90a;
P_0c0ac90a: /* original 6c63, guest PC 0x0c0ac90a */
if(!s->budget--) { s->failed_pc=0x0c0ac90au; return 0; }
r[12]=r[6];
goto P_0c0ac90c;
P_0c0ac90c: /* original 4f22, guest PC 0x0c0ac90c */
if(!s->budget--) { s->failed_pc=0x0c0ac90cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac90e;
P_0c0ac90e: /* original 53c1, guest PC 0x0c0ac90e */
if(!s->budget--) { s->failed_pc=0x0c0ac90eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac910;
P_0c0ac910: /* original 3342, guest PC 0x0c0ac910 */
if(!s->budget--) { s->failed_pc=0x0c0ac910u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0ac912;
P_0c0ac912: /* original 7ffc, guest PC 0x0c0ac912 */
if(!s->budget--) { s->failed_pc=0x0c0ac912u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac914;
P_0c0ac914: /* original 8f06, guest PC 0x0c0ac914 */
if(!s->budget--) { s->failed_pc=0x0c0ac914u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0ac924; }
goto P_0c0ac918;
P_0c0ac916: /* original 6d53, guest PC 0x0c0ac916 */
if(!s->budget--) { s->failed_pc=0x0c0ac916u; return 0; }
r[13]=r[5];
goto P_0c0ac918;
P_0c0ac918: /* original 50c1, guest PC 0x0c0ac918 */
if(!s->budget--) { s->failed_pc=0x0c0ac918u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c0ac91a;
P_0c0ac91a: /* original 8801, guest PC 0x0c0ac91a */
if(!s->budget--) { s->failed_pc=0x0c0ac91au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ac91c;
P_0c0ac91c: /* original 8924, guest PC 0x0c0ac91c */
if(!s->budget--) { s->failed_pc=0x0c0ac91cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac968; }
goto P_0c0ac91e;
P_0c0ac91e: /* original 53c1, guest PC 0x0c0ac91e */
if(!s->budget--) { s->failed_pc=0x0c0ac91eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac920;
P_0c0ac920: /* original 3346, guest PC 0x0c0ac920 */
if(!s->budget--) { s->failed_pc=0x0c0ac920u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0ac922;
P_0c0ac922: /* original 895a, guest PC 0x0c0ac922 */
if(!s->budget--) { s->failed_pc=0x0c0ac922u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9da; }
goto P_0c0ac924;
P_0c0ac924: /* original 62e2, guest PC 0x0c0ac924 */
if(!s->budget--) { s->failed_pc=0x0c0ac924u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ac926;
P_0c0ac926: /* original d30f, guest PC 0x0c0ac926 */
if(!s->budget--) { s->failed_pc=0x0c0ac926u; return 0; }
r[3]=read(ram,0x0c0ac964u,4);
goto P_0c0ac928;
P_0c0ac928: /* original 2239, guest PC 0x0c0ac928 */
if(!s->budget--) { s->failed_pc=0x0c0ac928u; return 0; }
r[2]&=r[3];
goto P_0c0ac92a;
P_0c0ac92a: /* original 2e22, guest PC 0x0c0ac92a */
if(!s->budget--) { s->failed_pc=0x0c0ac92au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ac92c;
P_0c0ac92c: /* original 61c2, guest PC 0x0c0ac92c */
if(!s->budget--) { s->failed_pc=0x0c0ac92cu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0ac92e;
P_0c0ac92e: /* original 611d, guest PC 0x0c0ac92e */
if(!s->budget--) { s->failed_pc=0x0c0ac92eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ac930;
P_0c0ac930: /* original 6513, guest PC 0x0c0ac930 */
if(!s->budget--) { s->failed_pc=0x0c0ac930u; return 0; }
r[5]=r[1];
goto P_0c0ac932;
P_0c0ac932: /* original 2f12, guest PC 0x0c0ac932 */
if(!s->budget--) { s->failed_pc=0x0c0ac932u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ac934;
P_0c0ac934: /* original b420, guest PC 0x0c0ac934 */
if(!s->budget--) { s->failed_pc=0x0c0ac934u; return 0; }
target=code_base|0x0c0ad178u; r[16]=code_base|0x0c0ac938u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac938u) { target=s->pc; goto dispatch; }
goto P_0c0ac938;
P_0c0ac936: /* original 64e3, guest PC 0x0c0ac936 */
if(!s->budget--) { s->failed_pc=0x0c0ac936u; return 0; }
r[4]=r[14];
goto P_0c0ac938;
P_0c0ac938: /* original 7f04, guest PC 0x0c0ac938 */
if(!s->budget--) { s->failed_pc=0x0c0ac938u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac93a;
P_0c0ac93a: /* original 66c3, guest PC 0x0c0ac93a */
if(!s->budget--) { s->failed_pc=0x0c0ac93au; return 0; }
r[6]=r[12];
goto P_0c0ac93c;
P_0c0ac93c: /* original 4f26, guest PC 0x0c0ac93c */
if(!s->budget--) { s->failed_pc=0x0c0ac93cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac93e;
P_0c0ac93e: /* original 65d3, guest PC 0x0c0ac93e */
if(!s->budget--) { s->failed_pc=0x0c0ac93eu; return 0; }
r[5]=r[13];
goto P_0c0ac940;
P_0c0ac940: /* original 64e3, guest PC 0x0c0ac940 */
if(!s->budget--) { s->failed_pc=0x0c0ac940u; return 0; }
r[4]=r[14];
goto P_0c0ac942;
P_0c0ac942: /* original 6cf6, guest PC 0x0c0ac942 */
if(!s->budget--) { s->failed_pc=0x0c0ac942u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ac944;
P_0c0ac944: /* original 6df6, guest PC 0x0c0ac944 */
if(!s->budget--) { s->failed_pc=0x0c0ac944u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac946;
P_0c0ac946: /* original a067, guest PC 0x0c0ac946 */
if(!s->budget--) { s->failed_pc=0x0c0ac946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aca18u,s,ram);
P_0c0ac948: /* original 6ef6, guest PC 0x0c0ac948 */
if(!s->budget--) { s->failed_pc=0x0c0ac948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ac94au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac94au; return 0; } return 1;
P_0c0ac968: /* original e048, guest PC 0x0c0ac968 */
if(!s->budget--) { s->failed_pc=0x0c0ac968u; return 0; }
r[0]=0x00000048u;
goto P_0c0ac96a;
P_0c0ac96a: /* original d345, guest PC 0x0c0ac96a */
if(!s->budget--) { s->failed_pc=0x0c0ac96au; return 0; }
r[3]=read(ram,0x0c0aca80u,4);
goto P_0c0ac96c;
P_0c0ac96c: /* original 02ee, guest PC 0x0c0ac96c */
if(!s->budget--) { s->failed_pc=0x0c0ac96cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac96e;
P_0c0ac96e: /* original 2238, guest PC 0x0c0ac96e */
if(!s->budget--) { s->failed_pc=0x0c0ac96eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac970;
P_0c0ac970: /* original 8921, guest PC 0x0c0ac970 */
if(!s->budget--) { s->failed_pc=0x0c0ac970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9b6; }
goto P_0c0ac972;
P_0c0ac972: /* original e010, guest PC 0x0c0ac972 */
if(!s->budget--) { s->failed_pc=0x0c0ac972u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac974;
P_0c0ac974: /* original f5e6, guest PC 0x0c0ac974 */
if(!s->budget--) { s->failed_pc=0x0c0ac974u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ac976;
P_0c0ac976: /* original e014, guest PC 0x0c0ac976 */
if(!s->budget--) { s->failed_pc=0x0c0ac976u; return 0; }
r[0]=0x00000014u;
goto P_0c0ac978;
P_0c0ac978: /* original f6e6, guest PC 0x0c0ac978 */
if(!s->budget--) { s->failed_pc=0x0c0ac978u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ac97a;
P_0c0ac97a: /* original e018, guest PC 0x0c0ac97a */
if(!s->budget--) { s->failed_pc=0x0c0ac97au; return 0; }
r[0]=0x00000018u;
goto P_0c0ac97c;
P_0c0ac97c: /* original f4e6, guest PC 0x0c0ac97c */
if(!s->budget--) { s->failed_pc=0x0c0ac97cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ac97e;
P_0c0ac97e: /* original e010, guest PC 0x0c0ac97e */
if(!s->budget--) { s->failed_pc=0x0c0ac97eu; return 0; }
r[0]=0x00000010u;
goto P_0c0ac980;
P_0c0ac980: /* original f9d6, guest PC 0x0c0ac980 */
if(!s->budget--) { s->failed_pc=0x0c0ac980u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0ac982;
P_0c0ac982: /* original e014, guest PC 0x0c0ac982 */
if(!s->budget--) { s->failed_pc=0x0c0ac982u; return 0; }
r[0]=0x00000014u;
goto P_0c0ac984;
P_0c0ac984: /* original f8d6, guest PC 0x0c0ac984 */
if(!s->budget--) { s->failed_pc=0x0c0ac984u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0ac986;
P_0c0ac986: /* original e018, guest PC 0x0c0ac986 */
if(!s->budget--) { s->failed_pc=0x0c0ac986u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac988;
P_0c0ac988: /* original fad6, guest PC 0x0c0ac988 */
if(!s->budget--) { s->failed_pc=0x0c0ac988u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c0ac98a;
P_0c0ac98a: /* original f951, guest PC 0x0c0ac98a */
if(!s->budget--) { s->failed_pc=0x0c0ac98au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'-');
goto P_0c0ac98c;
P_0c0ac98c: /* original c73d, guest PC 0x0c0ac98c */
if(!s->budget--) { s->failed_pc=0x0c0ac98cu; return 0; }
r[0]=code_base|0x000aca84u;
goto P_0c0ac98e;
P_0c0ac98e: /* original f35c, guest PC 0x0c0ac98e */
if(!s->budget--) { s->failed_pc=0x0c0ac98eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ac990;
P_0c0ac990: /* original f708, guest PC 0x0c0ac990 */
if(!s->budget--) { s->failed_pc=0x0c0ac990u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0ac992;
P_0c0ac992: /* original f861, guest PC 0x0c0ac992 */
if(!s->budget--) { s->failed_pc=0x0c0ac992u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c0ac994;
P_0c0ac994: /* original fa41, guest PC 0x0c0ac994 */
if(!s->budget--) { s->failed_pc=0x0c0ac994u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c0ac996;
P_0c0ac996: /* original f26c, guest PC 0x0c0ac996 */
if(!s->budget--) { s->failed_pc=0x0c0ac996u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ac998;
P_0c0ac998: /* original f07c, guest PC 0x0c0ac998 */
if(!s->budget--) { s->failed_pc=0x0c0ac998u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0ac99a;
P_0c0ac99a: /* original f39e, guest PC 0x0c0ac99a */
if(!s->budget--) { s->failed_pc=0x0c0ac99au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0ac99c;
P_0c0ac99c: /* original e010, guest PC 0x0c0ac99c */
if(!s->budget--) { s->failed_pc=0x0c0ac99cu; return 0; }
r[0]=0x00000010u;
goto P_0c0ac99e;
P_0c0ac99e: /* original f28e, guest PC 0x0c0ac99e */
if(!s->budget--) { s->failed_pc=0x0c0ac99eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0ac9a0;
P_0c0ac9a0: /* original f53c, guest PC 0x0c0ac9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a0u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ac9a2;
P_0c0ac9a2: /* original f34c, guest PC 0x0c0ac9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a2u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac9a4;
P_0c0ac9a4: /* original f3ae, guest PC 0x0c0ac9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c0ac9a6;
P_0c0ac9a6: /* original f62c, guest PC 0x0c0ac9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0ac9a8;
P_0c0ac9a8: /* original f43c, guest PC 0x0c0ac9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ac9aa;
P_0c0ac9aa: /* original fe57, guest PC 0x0c0ac9aa */
if(!s->budget--) { s->failed_pc=0x0c0ac9aau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ac9ac;
P_0c0ac9ac: /* original e014, guest PC 0x0c0ac9ac */
if(!s->budget--) { s->failed_pc=0x0c0ac9acu; return 0; }
r[0]=0x00000014u;
goto P_0c0ac9ae;
P_0c0ac9ae: /* original fe67, guest PC 0x0c0ac9ae */
if(!s->budget--) { s->failed_pc=0x0c0ac9aeu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0ac9b0;
P_0c0ac9b0: /* original e018, guest PC 0x0c0ac9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b0u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac9b2;
P_0c0ac9b2: /* original a02b, guest PC 0x0c0ac9b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aca0c;
P_0c0ac9b4: /* original fe47, guest PC 0x0c0ac9b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ac9b6;
P_0c0ac9b6: /* original e010, guest PC 0x0c0ac9b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac9b8;
P_0c0ac9b8: /* original f3d6, guest PC 0x0c0ac9b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9ba;
P_0c0ac9ba: /* original fe37, guest PC 0x0c0ac9ba */
if(!s->budget--) { s->failed_pc=0x0c0ac9bau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9bc;
P_0c0ac9bc: /* original e014, guest PC 0x0c0ac9bc */
if(!s->budget--) { s->failed_pc=0x0c0ac9bcu; return 0; }
r[0]=0x00000014u;
goto P_0c0ac9be;
P_0c0ac9be: /* original f3d6, guest PC 0x0c0ac9be */
if(!s->budget--) { s->failed_pc=0x0c0ac9beu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9c0;
P_0c0ac9c0: /* original fe37, guest PC 0x0c0ac9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9c2;
P_0c0ac9c2: /* original e018, guest PC 0x0c0ac9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac9c4;
P_0c0ac9c4: /* original f3d6, guest PC 0x0c0ac9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9c6;
P_0c0ac9c6: /* original fe37, guest PC 0x0c0ac9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9c8;
P_0c0ac9c8: /* original 85df, guest PC 0x0c0ac9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+30,2);
goto P_0c0ac9ca;
P_0c0ac9ca: /* original 81ef, guest PC 0x0c0ac9ca */
if(!s->budget--) { s->failed_pc=0x0c0ac9cau; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ac9cc;
P_0c0ac9cc: /* original e062, guest PC 0x0c0ac9cc */
if(!s->budget--) { s->failed_pc=0x0c0ac9ccu; return 0; }
r[0]=0x00000062u;
goto P_0c0ac9ce;
P_0c0ac9ce: /* original 53c1, guest PC 0x0c0ac9ce */
if(!s->budget--) { s->failed_pc=0x0c0ac9ceu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac9d0;
P_0c0ac9d0: /* original 7301, guest PC 0x0c0ac9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d0u; return 0; }
r[3]+=0x00000001u;
goto P_0c0ac9d2;
P_0c0ac9d2: /* original 6233, guest PC 0x0c0ac9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d2u; return 0; }
r[2]=r[3];
goto P_0c0ac9d4;
P_0c0ac9d4: /* original 1c31, guest PC 0x0c0ac9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d4u; return 0; }
write(ram,r[12]+4,r[3],4);
goto P_0c0ac9d6;
P_0c0ac9d6: /* original a019, guest PC 0x0c0ac9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aca0c;
P_0c0ac9d8: /* original 0e24, guest PC 0x0c0ac9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ac9da;
P_0c0ac9da: /* original e03e, guest PC 0x0c0ac9da */
if(!s->budget--) { s->failed_pc=0x0c0ac9dau; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac9dc;
P_0c0ac9dc: /* original 03ed, guest PC 0x0c0ac9dc */
if(!s->budget--) { s->failed_pc=0x0c0ac9dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9de;
P_0c0ac9de: /* original 9046, guest PC 0x0c0ac9de */
if(!s->budget--) { s->failed_pc=0x0c0ac9deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca6eu,2);
goto P_0c0ac9e0;
P_0c0ac9e0: /* original 02ed, guest PC 0x0c0ac9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9e2;
P_0c0ac9e2: /* original 3322, guest PC 0x0c0ac9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac9e4;
P_0c0ac9e4: /* original 8b12, guest PC 0x0c0ac9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aca0c; }
goto P_0c0ac9e6;
P_0c0ac9e6: /* original 9043, guest PC 0x0c0ac9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca70u,2);
goto P_0c0ac9e8;
P_0c0ac9e8: /* original 04ed, guest PC 0x0c0ac9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9ea;
P_0c0ac9ea: /* original 644d, guest PC 0x0c0ac9ea */
if(!s->budget--) { s->failed_pc=0x0c0ac9eau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ac9ec;
P_0c0ac9ec: /* original 644c, guest PC 0x0c0ac9ec */
if(!s->budget--) { s->failed_pc=0x0c0ac9ecu; return 0; }
r[4]=r[4]&255u;
goto P_0c0ac9ee;
P_0c0ac9ee: /* original 6043, guest PC 0x0c0ac9ee */
if(!s->budget--) { s->failed_pc=0x0c0ac9eeu; return 0; }
r[0]=r[4];
goto P_0c0ac9f0;
P_0c0ac9f0: /* original 8804, guest PC 0x0c0ac9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ac9f2;
P_0c0ac9f2: /* original 8902, guest PC 0x0c0ac9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9fa; }
goto P_0c0ac9f4;
P_0c0ac9f4: /* original e300, guest PC 0x0c0ac9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f4u; return 0; }
r[3]=0x00000000u;
goto P_0c0ac9f6;
P_0c0ac9f6: /* original a009, guest PC 0x0c0ac9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f6u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aca0c;
P_0c0ac9f8: /* original 1e3e, guest PC 0x0c0ac9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f8u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ac9fa;
P_0c0ac9fa: /* original e066, guest PC 0x0c0ac9fa */
if(!s->budget--) { s->failed_pc=0x0c0ac9fau; return 0; }
r[0]=0x00000066u;
goto P_0c0ac9fc;
P_0c0ac9fc: /* original e202, guest PC 0x0c0ac9fc */
if(!s->budget--) { s->failed_pc=0x0c0ac9fcu; return 0; }
r[2]=0x00000002u;
goto P_0c0ac9fe;
P_0c0ac9fe: /* original 0e25, guest PC 0x0c0ac9fe */
if(!s->budget--) { s->failed_pc=0x0c0ac9feu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aca00;
P_0c0aca00: /* original d321, guest PC 0x0c0aca00 */
if(!s->budget--) { s->failed_pc=0x0c0aca00u; return 0; }
r[3]=read(ram,0x0c0aca88u,4);
goto P_0c0aca02;
P_0c0aca02: /* original 1e3d, guest PC 0x0c0aca02 */
if(!s->budget--) { s->failed_pc=0x0c0aca02u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0aca04;
P_0c0aca04: /* original 62e2, guest PC 0x0c0aca04 */
if(!s->budget--) { s->failed_pc=0x0c0aca04u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aca06;
P_0c0aca06: /* original d321, guest PC 0x0c0aca06 */
if(!s->budget--) { s->failed_pc=0x0c0aca06u; return 0; }
r[3]=read(ram,0x0c0aca8cu,4);
goto P_0c0aca08;
P_0c0aca08: /* original 223b, guest PC 0x0c0aca08 */
if(!s->budget--) { s->failed_pc=0x0c0aca08u; return 0; }
r[2]|=r[3];
goto P_0c0aca0a;
P_0c0aca0a: /* original 2e22, guest PC 0x0c0aca0a */
if(!s->budget--) { s->failed_pc=0x0c0aca0au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0aca0c;
P_0c0aca0c: /* original 7f04, guest PC 0x0c0aca0c */
if(!s->budget--) { s->failed_pc=0x0c0aca0cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aca0e;
P_0c0aca0e: /* original 4f26, guest PC 0x0c0aca0e */
if(!s->budget--) { s->failed_pc=0x0c0aca0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aca10;
P_0c0aca10: /* original 6cf6, guest PC 0x0c0aca10 */
if(!s->budget--) { s->failed_pc=0x0c0aca10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aca12;
P_0c0aca12: /* original 6df6, guest PC 0x0c0aca12 */
if(!s->budget--) { s->failed_pc=0x0c0aca12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aca14;
P_0c0aca14: /* original 000b, guest PC 0x0c0aca14 */
if(!s->budget--) { s->failed_pc=0x0c0aca14u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aca16: /* original 6ef6, guest PC 0x0c0aca16 */
if(!s->budget--) { s->failed_pc=0x0c0aca16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aca18u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
