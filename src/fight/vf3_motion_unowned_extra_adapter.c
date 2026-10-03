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
int vf3_motion_unowned_extra_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0352dau: goto P_0c0352da;
case 0x0c0352dcu: goto P_0c0352dc;
case 0x0c0352deu: goto P_0c0352de;
case 0x0c0352e0u: goto P_0c0352e0;
case 0x0c0352e2u: goto P_0c0352e2;
case 0x0c0352e4u: goto P_0c0352e4;
case 0x0c0352e6u: goto P_0c0352e6;
case 0x0c0352e8u: goto P_0c0352e8;
case 0x0c0352eau: goto P_0c0352ea;
case 0x0c0352ecu: goto P_0c0352ec;
case 0x0c0352eeu: goto P_0c0352ee;
case 0x0c0352f0u: goto P_0c0352f0;
case 0x0c0352f2u: goto P_0c0352f2;
case 0x0c0352f4u: goto P_0c0352f4;
case 0x0c0352f6u: goto P_0c0352f6;
case 0x0c0352f8u: goto P_0c0352f8;
case 0x0c0352fau: goto P_0c0352fa;
case 0x0c0352fcu: goto P_0c0352fc;
case 0x0c0352feu: goto P_0c0352fe;
case 0x0c035300u: goto P_0c035300;
case 0x0c0431eau: goto P_0c0431ea;
case 0x0c0431ecu: goto P_0c0431ec;
case 0x0c0431eeu: goto P_0c0431ee;
case 0x0c0431f0u: goto P_0c0431f0;
case 0x0c0431f2u: goto P_0c0431f2;
case 0x0c0431f4u: goto P_0c0431f4;
case 0x0c0431f6u: goto P_0c0431f6;
case 0x0c0431f8u: goto P_0c0431f8;
case 0x0c0431fau: goto P_0c0431fa;
case 0x0c0431fcu: goto P_0c0431fc;
case 0x0c0431feu: goto P_0c0431fe;
case 0x0c043200u: goto P_0c043200;
case 0x0c043202u: goto P_0c043202;
case 0x0c043204u: goto P_0c043204;
case 0x0c043206u: goto P_0c043206;
case 0x0c043208u: goto P_0c043208;
case 0x0c04320au: goto P_0c04320a;
case 0x0c04320cu: goto P_0c04320c;
case 0x0c04320eu: goto P_0c04320e;
case 0x0c043210u: goto P_0c043210;
case 0x0c043212u: goto P_0c043212;
case 0x0c043214u: goto P_0c043214;
case 0x0c043216u: goto P_0c043216;
case 0x0c043218u: goto P_0c043218;
case 0x0c04321au: goto P_0c04321a;
case 0x0c04321cu: goto P_0c04321c;
case 0x0c04321eu: goto P_0c04321e;
case 0x0c043220u: goto P_0c043220;
case 0x0c043222u: goto P_0c043222;
case 0x0c043224u: goto P_0c043224;
case 0x0c043226u: goto P_0c043226;
case 0x0c043228u: goto P_0c043228;
case 0x0c04322au: goto P_0c04322a;
case 0x0c04322cu: goto P_0c04322c;
case 0x0c04322eu: goto P_0c04322e;
case 0x0c043230u: goto P_0c043230;
case 0x0c043232u: goto P_0c043232;
case 0x0c043234u: goto P_0c043234;
case 0x0c043236u: goto P_0c043236;
case 0x0c043238u: goto P_0c043238;
case 0x0c04323au: goto P_0c04323a;
case 0x0c04323cu: goto P_0c04323c;
case 0x0c04323eu: goto P_0c04323e;
case 0x0c043240u: goto P_0c043240;
case 0x0c043242u: goto P_0c043242;
case 0x0c043244u: goto P_0c043244;
case 0x0c043246u: goto P_0c043246;
case 0x0c043248u: goto P_0c043248;
case 0x0c04324au: goto P_0c04324a;
case 0x0c04324cu: goto P_0c04324c;
case 0x0c04324eu: goto P_0c04324e;
case 0x0c043250u: goto P_0c043250;
case 0x0c043252u: goto P_0c043252;
case 0x0c043254u: goto P_0c043254;
case 0x0c043256u: goto P_0c043256;
case 0x0c043258u: goto P_0c043258;
case 0x0c04325au: goto P_0c04325a;
case 0x0c04325cu: goto P_0c04325c;
case 0x0c04325eu: goto P_0c04325e;
case 0x0c043260u: goto P_0c043260;
case 0x0c043262u: goto P_0c043262;
case 0x0c043264u: goto P_0c043264;
case 0x0c043266u: goto P_0c043266;
case 0x0c043268u: goto P_0c043268;
case 0x0c046616u: goto P_0c046616;
case 0x0c046618u: goto P_0c046618;
case 0x0c04661au: goto P_0c04661a;
case 0x0c04e412u: goto P_0c04e412;
case 0x0c04e414u: goto P_0c04e414;
case 0x0c04e416u: goto P_0c04e416;
case 0x0c04e418u: goto P_0c04e418;
case 0x0c04e41au: goto P_0c04e41a;
case 0x0c04e41cu: goto P_0c04e41c;
case 0x0c04e41eu: goto P_0c04e41e;
case 0x0c04e420u: goto P_0c04e420;
case 0x0c04e422u: goto P_0c04e422;
case 0x0c04e424u: goto P_0c04e424;
case 0x0c04e426u: goto P_0c04e426;
case 0x0c04e428u: goto P_0c04e428;
case 0x0c04e42au: goto P_0c04e42a;
case 0x0c04e42cu: goto P_0c04e42c;
case 0x0c04e42eu: goto P_0c04e42e;
case 0x0c04e430u: goto P_0c04e430;
case 0x0c04e432u: goto P_0c04e432;
case 0x0c04e434u: goto P_0c04e434;
case 0x0c04e436u: goto P_0c04e436;
case 0x0c04e438u: goto P_0c04e438;
case 0x0c04e43au: goto P_0c04e43a;
case 0x0c04e43cu: goto P_0c04e43c;
case 0x0c04e43eu: goto P_0c04e43e;
case 0x0c04e440u: goto P_0c04e440;
case 0x0c04e442u: goto P_0c04e442;
case 0x0c04e444u: goto P_0c04e444;
case 0x0c04e446u: goto P_0c04e446;
case 0x0c04e448u: goto P_0c04e448;
case 0x0c04e44au: goto P_0c04e44a;
case 0x0c04e44cu: goto P_0c04e44c;
case 0x0c04e490u: goto P_0c04e490;
case 0x0c04e492u: goto P_0c04e492;
case 0x0c04e494u: goto P_0c04e494;
case 0x0c04e496u: goto P_0c04e496;
case 0x0c04e498u: goto P_0c04e498;
case 0x0c04e49au: goto P_0c04e49a;
case 0x0c04e49cu: goto P_0c04e49c;
case 0x0c04e49eu: goto P_0c04e49e;
case 0x0c04e4a0u: goto P_0c04e4a0;
case 0x0c04e4a2u: goto P_0c04e4a2;
case 0x0c04e4a4u: goto P_0c04e4a4;
case 0x0c04e4a6u: goto P_0c04e4a6;
case 0x0c04e4a8u: goto P_0c04e4a8;
case 0x0c04e4aau: goto P_0c04e4aa;
case 0x0c04e4acu: goto P_0c04e4ac;
case 0x0c04e4aeu: goto P_0c04e4ae;
case 0x0c04e4b0u: goto P_0c04e4b0;
case 0x0c04e4b2u: goto P_0c04e4b2;
case 0x0c04e4b4u: goto P_0c04e4b4;
case 0x0c04e4b6u: goto P_0c04e4b6;
case 0x0c04e4b8u: goto P_0c04e4b8;
case 0x0c04e4bau: goto P_0c04e4ba;
case 0x0c04e4bcu: goto P_0c04e4bc;
case 0x0c04e4beu: goto P_0c04e4be;
case 0x0c04e4c0u: goto P_0c04e4c0;
case 0x0c04e4c2u: goto P_0c04e4c2;
case 0x0c04e4c4u: goto P_0c04e4c4;
case 0x0c04e4c6u: goto P_0c04e4c6;
case 0x0c04e4c8u: goto P_0c04e4c8;
case 0x0c04e4cau: goto P_0c04e4ca;
case 0x0c04e4ccu: goto P_0c04e4cc;
case 0x0c04e4ceu: goto P_0c04e4ce;
case 0x0c04e4d0u: goto P_0c04e4d0;
case 0x0c04e4d2u: goto P_0c04e4d2;
case 0x0c04e4d4u: goto P_0c04e4d4;
case 0x0c04e4d6u: goto P_0c04e4d6;
case 0x0c04e4d8u: goto P_0c04e4d8;
case 0x0c04e4dau: goto P_0c04e4da;
case 0x0c04e4dcu: goto P_0c04e4dc;
case 0x0c04e4deu: goto P_0c04e4de;
case 0x0c04f88cu: goto P_0c04f88c;
case 0x0c04f88eu: goto P_0c04f88e;
case 0x0c04f890u: goto P_0c04f890;
case 0x0c04f892u: goto P_0c04f892;
case 0x0c04f894u: goto P_0c04f894;
case 0x0c04f896u: goto P_0c04f896;
case 0x0c04f898u: goto P_0c04f898;
case 0x0c04f89au: goto P_0c04f89a;
case 0x0c04f89cu: goto P_0c04f89c;
case 0x0c04f89eu: goto P_0c04f89e;
case 0x0c04f8a0u: goto P_0c04f8a0;
case 0x0c04f8a2u: goto P_0c04f8a2;
case 0x0c04f8a4u: goto P_0c04f8a4;
case 0x0c04f8bcu: goto P_0c04f8bc;
case 0x0c04f8beu: goto P_0c04f8be;
case 0x0c04f8c0u: goto P_0c04f8c0;
case 0x0c04f8c2u: goto P_0c04f8c2;
case 0x0c04f8c4u: goto P_0c04f8c4;
case 0x0c04f8c6u: goto P_0c04f8c6;
case 0x0c04f8c8u: goto P_0c04f8c8;
case 0x0c04f8cau: goto P_0c04f8ca;
case 0x0c04f8ccu: goto P_0c04f8cc;
case 0x0c04f8ceu: goto P_0c04f8ce;
case 0x0c04f8d0u: goto P_0c04f8d0;
case 0x0c04f8d2u: goto P_0c04f8d2;
case 0x0c04f8d4u: goto P_0c04f8d4;
case 0x0c04f8d6u: goto P_0c04f8d6;
case 0x0c04f8d8u: goto P_0c04f8d8;
case 0x0c04f8dau: goto P_0c04f8da;
case 0x0c04f8dcu: goto P_0c04f8dc;
case 0x0c04f8deu: goto P_0c04f8de;
case 0x0c04f8e0u: goto P_0c04f8e0;
case 0x0c04f8e2u: goto P_0c04f8e2;
case 0x0c04f8e4u: goto P_0c04f8e4;
case 0x0c04f8e6u: goto P_0c04f8e6;
case 0x0c04f8e8u: goto P_0c04f8e8;
case 0x0c04f8eau: goto P_0c04f8ea;
case 0x0c04f8ecu: goto P_0c04f8ec;
case 0x0c04f8eeu: goto P_0c04f8ee;
case 0x0c04f8f0u: goto P_0c04f8f0;
case 0x0c04f8f2u: goto P_0c04f8f2;
case 0x0c04f8f4u: goto P_0c04f8f4;
case 0x0c04f8f6u: goto P_0c04f8f6;
case 0x0c04f8f8u: goto P_0c04f8f8;
case 0x0c04f8fau: goto P_0c04f8fa;
case 0x0c04f8fcu: goto P_0c04f8fc;
case 0x0c04f8feu: goto P_0c04f8fe;
case 0x0c04f900u: goto P_0c04f900;
case 0x0c04f902u: goto P_0c04f902;
case 0x0c04f904u: goto P_0c04f904;
case 0x0c04f906u: goto P_0c04f906;
case 0x0c04f908u: goto P_0c04f908;
case 0x0c04f90au: goto P_0c04f90a;
case 0x0c04f90cu: goto P_0c04f90c;
case 0x0c04f90eu: goto P_0c04f90e;
case 0x0c04f910u: goto P_0c04f910;
case 0x0c04f912u: goto P_0c04f912;
case 0x0c04f914u: goto P_0c04f914;
case 0x0c04f916u: goto P_0c04f916;
case 0x0c04f918u: goto P_0c04f918;
case 0x0c04f91au: goto P_0c04f91a;
case 0x0c04f91cu: goto P_0c04f91c;
case 0x0c04f91eu: goto P_0c04f91e;
case 0x0c04f920u: goto P_0c04f920;
case 0x0c04f922u: goto P_0c04f922;
case 0x0c04f924u: goto P_0c04f924;
case 0x0c04f926u: goto P_0c04f926;
case 0x0c04f928u: goto P_0c04f928;
case 0x0c04f92au: goto P_0c04f92a;
case 0x0c04f92cu: goto P_0c04f92c;
case 0x0c04f92eu: goto P_0c04f92e;
case 0x0c04f930u: goto P_0c04f930;
case 0x0c04f932u: goto P_0c04f932;
case 0x0c04f934u: goto P_0c04f934;
case 0x0c04f936u: goto P_0c04f936;
case 0x0c04f938u: goto P_0c04f938;
case 0x0c04f93au: goto P_0c04f93a;
case 0x0c04f93cu: goto P_0c04f93c;
case 0x0c04f93eu: goto P_0c04f93e;
case 0x0c04f940u: goto P_0c04f940;
case 0x0c04f942u: goto P_0c04f942;
case 0x0c04f944u: goto P_0c04f944;
case 0x0c04f946u: goto P_0c04f946;
case 0x0c04f948u: goto P_0c04f948;
case 0x0c04f94au: goto P_0c04f94a;
case 0x0c04f94cu: goto P_0c04f94c;
case 0x0c04f94eu: goto P_0c04f94e;
case 0x0c04f950u: goto P_0c04f950;
case 0x0c04f952u: goto P_0c04f952;
case 0x0c04f954u: goto P_0c04f954;
case 0x0c04f956u: goto P_0c04f956;
case 0x0c04f958u: goto P_0c04f958;
case 0x0c04f95au: goto P_0c04f95a;
case 0x0c04f95cu: goto P_0c04f95c;
case 0x0c04f95eu: goto P_0c04f95e;
case 0x0c04f960u: goto P_0c04f960;
case 0x0c04f962u: goto P_0c04f962;
case 0x0c04f964u: goto P_0c04f964;
case 0x0c04f966u: goto P_0c04f966;
case 0x0c04f968u: goto P_0c04f968;
case 0x0c04f96au: goto P_0c04f96a;
case 0x0c04f96cu: goto P_0c04f96c;
case 0x0c04f96eu: goto P_0c04f96e;
case 0x0c04f970u: goto P_0c04f970;
case 0x0c04f972u: goto P_0c04f972;
case 0x0c04f974u: goto P_0c04f974;
case 0x0c04f976u: goto P_0c04f976;
case 0x0c04f978u: goto P_0c04f978;
case 0x0c04f97au: goto P_0c04f97a;
case 0x0c04f97cu: goto P_0c04f97c;
case 0x0c04f97eu: goto P_0c04f97e;
case 0x0c04f980u: goto P_0c04f980;
case 0x0c04f982u: goto P_0c04f982;
case 0x0c04f984u: goto P_0c04f984;
case 0x0c04f986u: goto P_0c04f986;
case 0x0c04f988u: goto P_0c04f988;
case 0x0c04f98au: goto P_0c04f98a;
case 0x0c04f98cu: goto P_0c04f98c;
case 0x0c04f98eu: goto P_0c04f98e;
case 0x0c04f990u: goto P_0c04f990;
case 0x0c04f992u: goto P_0c04f992;
case 0x0c04f994u: goto P_0c04f994;
case 0x0c04f996u: goto P_0c04f996;
case 0x0c04f998u: goto P_0c04f998;
case 0x0c04f99au: goto P_0c04f99a;
case 0x0c04f99cu: goto P_0c04f99c;
case 0x0c04f99eu: goto P_0c04f99e;
case 0x0c04f9a0u: goto P_0c04f9a0;
case 0x0c04f9a2u: goto P_0c04f9a2;
case 0x0c04f9a4u: goto P_0c04f9a4;
case 0x0c04f9a6u: goto P_0c04f9a6;
case 0x0c04f9a8u: goto P_0c04f9a8;
case 0x0c04f9aau: goto P_0c04f9aa;
case 0x0c04f9acu: goto P_0c04f9ac;
case 0x0c04f9aeu: goto P_0c04f9ae;
case 0x0c04f9b0u: goto P_0c04f9b0;
case 0x0c04f9b2u: goto P_0c04f9b2;
case 0x0c04f9b4u: goto P_0c04f9b4;
case 0x0c04f9b6u: goto P_0c04f9b6;
case 0x0c04f9b8u: goto P_0c04f9b8;
case 0x0c04f9bau: goto P_0c04f9ba;
case 0x0c04f9bcu: goto P_0c04f9bc;
case 0x0c04f9beu: goto P_0c04f9be;
case 0x0c04f9c0u: goto P_0c04f9c0;
case 0x0c04f9c2u: goto P_0c04f9c2;
case 0x0c04f9c4u: goto P_0c04f9c4;
case 0x0c04f9c6u: goto P_0c04f9c6;
case 0x0c04f9c8u: goto P_0c04f9c8;
case 0x0c04f9cau: goto P_0c04f9ca;
case 0x0c04f9ccu: goto P_0c04f9cc;
case 0x0c04f9ceu: goto P_0c04f9ce;
case 0x0c04f9d0u: goto P_0c04f9d0;
case 0x0c04f9d2u: goto P_0c04f9d2;
case 0x0c04f9d4u: goto P_0c04f9d4;
case 0x0c04f9d6u: goto P_0c04f9d6;
case 0x0c04f9f0u: goto P_0c04f9f0;
case 0x0c04f9f2u: goto P_0c04f9f2;
case 0x0c04f9f4u: goto P_0c04f9f4;
case 0x0c04f9f6u: goto P_0c04f9f6;
case 0x0c04f9f8u: goto P_0c04f9f8;
case 0x0c04f9fau: goto P_0c04f9fa;
case 0x0c04f9fcu: goto P_0c04f9fc;
case 0x0c04f9feu: goto P_0c04f9fe;
case 0x0c04fa00u: goto P_0c04fa00;
case 0x0c04fa02u: goto P_0c04fa02;
case 0x0c04fa04u: goto P_0c04fa04;
case 0x0c04fa06u: goto P_0c04fa06;
case 0x0c04fa08u: goto P_0c04fa08;
case 0x0c04fa0au: goto P_0c04fa0a;
case 0x0c04fa0cu: goto P_0c04fa0c;
case 0x0c04fa0eu: goto P_0c04fa0e;
case 0x0c04fa10u: goto P_0c04fa10;
case 0x0c04fa12u: goto P_0c04fa12;
case 0x0c04fa14u: goto P_0c04fa14;
case 0x0c04fa16u: goto P_0c04fa16;
case 0x0c04fa18u: goto P_0c04fa18;
case 0x0c04fa1au: goto P_0c04fa1a;
case 0x0c04fa1cu: goto P_0c04fa1c;
case 0x0c04fa1eu: goto P_0c04fa1e;
case 0x0c04fa20u: goto P_0c04fa20;
case 0x0c04fa22u: goto P_0c04fa22;
case 0x0c04fa24u: goto P_0c04fa24;
case 0x0c04fa26u: goto P_0c04fa26;
case 0x0c04fa28u: goto P_0c04fa28;
case 0x0c04fa2au: goto P_0c04fa2a;
case 0x0c04fa2cu: goto P_0c04fa2c;
case 0x0c04fa2eu: goto P_0c04fa2e;
case 0x0c04fa30u: goto P_0c04fa30;
case 0x0c04fa32u: goto P_0c04fa32;
case 0x0c04fa34u: goto P_0c04fa34;
case 0x0c04fa36u: goto P_0c04fa36;
case 0x0c07ba28u: goto P_0c07ba28;
case 0x0c07ba2au: goto P_0c07ba2a;
case 0x0c07ba2cu: goto P_0c07ba2c;
case 0x0c07ba2eu: goto P_0c07ba2e;
case 0x0c07ba30u: goto P_0c07ba30;
case 0x0c07ba32u: goto P_0c07ba32;
case 0x0c07ba34u: goto P_0c07ba34;
case 0x0c07ba36u: goto P_0c07ba36;
case 0x0c07ba38u: goto P_0c07ba38;
case 0x0c07ba3au: goto P_0c07ba3a;
case 0x0c07ba3cu: goto P_0c07ba3c;
case 0x0c07ba3eu: goto P_0c07ba3e;
case 0x0c07ba40u: goto P_0c07ba40;
case 0x0c07ba42u: goto P_0c07ba42;
case 0x0c07ba44u: goto P_0c07ba44;
case 0x0c07ba46u: goto P_0c07ba46;
case 0x0c07ba48u: goto P_0c07ba48;
case 0x0c07ba4au: goto P_0c07ba4a;
case 0x0c07ba4cu: goto P_0c07ba4c;
case 0x0c07ba4eu: goto P_0c07ba4e;
case 0x0c07ba50u: goto P_0c07ba50;
case 0x0c07ba52u: goto P_0c07ba52;
case 0x0c07ba54u: goto P_0c07ba54;
case 0x0c07ba56u: goto P_0c07ba56;
case 0x0c07ba58u: goto P_0c07ba58;
case 0x0c07ba5au: goto P_0c07ba5a;
case 0x0c07ba5cu: goto P_0c07ba5c;
case 0x0c07ba5eu: goto P_0c07ba5e;
case 0x0c07ba60u: goto P_0c07ba60;
case 0x0c07ba62u: goto P_0c07ba62;
case 0x0c07ba64u: goto P_0c07ba64;
case 0x0c07ba66u: goto P_0c07ba66;
case 0x0c07ba68u: goto P_0c07ba68;
case 0x0c07ba6au: goto P_0c07ba6a;
case 0x0c07ba6cu: goto P_0c07ba6c;
case 0x0c07ba6eu: goto P_0c07ba6e;
case 0x0c07ba70u: goto P_0c07ba70;
case 0x0c07ba72u: goto P_0c07ba72;
case 0x0c07ba74u: goto P_0c07ba74;
case 0x0c07ba76u: goto P_0c07ba76;
case 0x0c07ba78u: goto P_0c07ba78;
case 0x0c07ba7au: goto P_0c07ba7a;
case 0x0c07ba7cu: goto P_0c07ba7c;
case 0x0c07ba7eu: goto P_0c07ba7e;
case 0x0c07ba80u: goto P_0c07ba80;
case 0x0c07ba82u: goto P_0c07ba82;
case 0x0c07ba84u: goto P_0c07ba84;
case 0x0c07ba86u: goto P_0c07ba86;
case 0x0c07ba88u: goto P_0c07ba88;
case 0x0c07ba8au: goto P_0c07ba8a;
case 0x0c07ba8cu: goto P_0c07ba8c;
case 0x0c07ba8eu: goto P_0c07ba8e;
case 0x0c07ba90u: goto P_0c07ba90;
case 0x0c07ba92u: goto P_0c07ba92;
case 0x0c07ba94u: goto P_0c07ba94;
case 0x0c07ba96u: goto P_0c07ba96;
case 0x0c07ba98u: goto P_0c07ba98;
case 0x0c07ba9au: goto P_0c07ba9a;
case 0x0c07ba9cu: goto P_0c07ba9c;
case 0x0c07ba9eu: goto P_0c07ba9e;
case 0x0c07baa0u: goto P_0c07baa0;
case 0x0c07baa2u: goto P_0c07baa2;
case 0x0c07baa4u: goto P_0c07baa4;
case 0x0c07baa6u: goto P_0c07baa6;
case 0x0c07baa8u: goto P_0c07baa8;
case 0x0c07baaau: goto P_0c07baaa;
case 0x0c07baacu: goto P_0c07baac;
case 0x0c07baaeu: goto P_0c07baae;
case 0x0c07bab0u: goto P_0c07bab0;
case 0x0c07bab2u: goto P_0c07bab2;
case 0x0c07bab4u: goto P_0c07bab4;
case 0x0c07bab6u: goto P_0c07bab6;
case 0x0c07bab8u: goto P_0c07bab8;
case 0x0c07babau: goto P_0c07baba;
case 0x0c07babcu: goto P_0c07babc;
case 0x0c07babeu: goto P_0c07babe;
case 0x0c07bac0u: goto P_0c07bac0;
case 0x0c07bac2u: goto P_0c07bac2;
case 0x0c07bac4u: goto P_0c07bac4;
case 0x0c07bac6u: goto P_0c07bac6;
case 0x0c07bac8u: goto P_0c07bac8;
case 0x0c07bacau: goto P_0c07baca;
case 0x0c07baccu: goto P_0c07bacc;
case 0x0c07baceu: goto P_0c07bace;
case 0x0c07bad0u: goto P_0c07bad0;
case 0x0c07bad2u: goto P_0c07bad2;
case 0x0c07bad4u: goto P_0c07bad4;
case 0x0c07bad6u: goto P_0c07bad6;
case 0x0c07bad8u: goto P_0c07bad8;
case 0x0c07badau: goto P_0c07bada;
case 0x0c07badcu: goto P_0c07badc;
case 0x0c07badeu: goto P_0c07bade;
case 0x0c07bae0u: goto P_0c07bae0;
case 0x0c07bae2u: goto P_0c07bae2;
case 0x0c07bae4u: goto P_0c07bae4;
case 0x0c07bae6u: goto P_0c07bae6;
case 0x0c07bae8u: goto P_0c07bae8;
case 0x0c07baeau: goto P_0c07baea;
case 0x0c07baecu: goto P_0c07baec;
case 0x0c07baeeu: goto P_0c07baee;
case 0x0c07baf0u: goto P_0c07baf0;
case 0x0c07baf2u: goto P_0c07baf2;
case 0x0c07baf4u: goto P_0c07baf4;
case 0x0c07baf6u: goto P_0c07baf6;
case 0x0c07baf8u: goto P_0c07baf8;
case 0x0c07bafau: goto P_0c07bafa;
case 0x0c07bafcu: goto P_0c07bafc;
case 0x0c07bafeu: goto P_0c07bafe;
case 0x0c07bb00u: goto P_0c07bb00;
case 0x0c07bb02u: goto P_0c07bb02;
case 0x0c07bb04u: goto P_0c07bb04;
case 0x0c07bb06u: goto P_0c07bb06;
case 0x0c07bb08u: goto P_0c07bb08;
case 0x0c07bb0au: goto P_0c07bb0a;
case 0x0c07bb0cu: goto P_0c07bb0c;
case 0x0c07bb0eu: goto P_0c07bb0e;
case 0x0c07bb10u: goto P_0c07bb10;
case 0x0c07bb12u: goto P_0c07bb12;
case 0x0c07bb14u: goto P_0c07bb14;
case 0x0c07bb16u: goto P_0c07bb16;
case 0x0c07bb18u: goto P_0c07bb18;
case 0x0c07bb1au: goto P_0c07bb1a;
case 0x0c07bb1cu: goto P_0c07bb1c;
case 0x0c07bb1eu: goto P_0c07bb1e;
case 0x0c07bb20u: goto P_0c07bb20;
case 0x0c07bb22u: goto P_0c07bb22;
case 0x0c07bb24u: goto P_0c07bb24;
case 0x0c07bb26u: goto P_0c07bb26;
case 0x0c07bb28u: goto P_0c07bb28;
case 0x0c07bb2au: goto P_0c07bb2a;
case 0x0c07bb2cu: goto P_0c07bb2c;
case 0x0c07bb2eu: goto P_0c07bb2e;
case 0x0c07bb30u: goto P_0c07bb30;
case 0x0c07bb32u: goto P_0c07bb32;
case 0x0c07bb34u: goto P_0c07bb34;
case 0x0c07bb36u: goto P_0c07bb36;
case 0x0c07bb38u: goto P_0c07bb38;
case 0x0c07bb3au: goto P_0c07bb3a;
case 0x0c07bb3cu: goto P_0c07bb3c;
case 0x0c07bb3eu: goto P_0c07bb3e;
case 0x0c07bb40u: goto P_0c07bb40;
case 0x0c07bb42u: goto P_0c07bb42;
case 0x0c07bb44u: goto P_0c07bb44;
case 0x0c07bb46u: goto P_0c07bb46;
case 0x0c07bba0u: goto P_0c07bba0;
case 0x0c07bba2u: goto P_0c07bba2;
case 0x0c07bba4u: goto P_0c07bba4;
case 0x0c07bba6u: goto P_0c07bba6;
case 0x0c07bba8u: goto P_0c07bba8;
case 0x0c07bbaau: goto P_0c07bbaa;
case 0x0c07bbacu: goto P_0c07bbac;
case 0x0c07bbaeu: goto P_0c07bbae;
case 0x0c07bbb0u: goto P_0c07bbb0;
case 0x0c07bbb2u: goto P_0c07bbb2;
case 0x0c07bbb4u: goto P_0c07bbb4;
case 0x0c07bbb6u: goto P_0c07bbb6;
case 0x0c07bbb8u: goto P_0c07bbb8;
case 0x0c07bbbau: goto P_0c07bbba;
case 0x0c07bbbcu: goto P_0c07bbbc;
case 0x0c07bbbeu: goto P_0c07bbbe;
case 0x0c07bbc0u: goto P_0c07bbc0;
case 0x0c07bbc2u: goto P_0c07bbc2;
case 0x0c07bbc4u: goto P_0c07bbc4;
case 0x0c07bbc6u: goto P_0c07bbc6;
case 0x0c07bbc8u: goto P_0c07bbc8;
case 0x0c07bbcau: goto P_0c07bbca;
case 0x0c07bbccu: goto P_0c07bbcc;
case 0x0c07bbceu: goto P_0c07bbce;
case 0x0c07bbd0u: goto P_0c07bbd0;
case 0x0c07bbd2u: goto P_0c07bbd2;
case 0x0c07bbd4u: goto P_0c07bbd4;
case 0x0c07bbd6u: goto P_0c07bbd6;
case 0x0c07bbd8u: goto P_0c07bbd8;
case 0x0c07bbdau: goto P_0c07bbda;
case 0x0c07bbdcu: goto P_0c07bbdc;
case 0x0c07bbdeu: goto P_0c07bbde;
case 0x0c07bbe0u: goto P_0c07bbe0;
case 0x0c07bbe2u: goto P_0c07bbe2;
case 0x0c07bbe4u: goto P_0c07bbe4;
case 0x0c07bbe6u: goto P_0c07bbe6;
case 0x0c07bbe8u: goto P_0c07bbe8;
case 0x0c07bbeau: goto P_0c07bbea;
case 0x0c07bbecu: goto P_0c07bbec;
case 0x0c07bbeeu: goto P_0c07bbee;
case 0x0c07bbf0u: goto P_0c07bbf0;
case 0x0c07bbf2u: goto P_0c07bbf2;
case 0x0c07bbf4u: goto P_0c07bbf4;
case 0x0c07bbf6u: goto P_0c07bbf6;
case 0x0c07bbf8u: goto P_0c07bbf8;
case 0x0c07bbfau: goto P_0c07bbfa;
case 0x0c07bbfcu: goto P_0c07bbfc;
case 0x0c07bbfeu: goto P_0c07bbfe;
case 0x0c07bc00u: goto P_0c07bc00;
case 0x0c07bc02u: goto P_0c07bc02;
case 0x0c07bc04u: goto P_0c07bc04;
case 0x0c07bc06u: goto P_0c07bc06;
case 0x0c07bc08u: goto P_0c07bc08;
case 0x0c07bc0au: goto P_0c07bc0a;
case 0x0c07bc0cu: goto P_0c07bc0c;
case 0x0c07bc0eu: goto P_0c07bc0e;
case 0x0c07bc10u: goto P_0c07bc10;
case 0x0c07bc12u: goto P_0c07bc12;
case 0x0c07bc14u: goto P_0c07bc14;
case 0x0c07bc16u: goto P_0c07bc16;
case 0x0c07bc18u: goto P_0c07bc18;
case 0x0c07bc1au: goto P_0c07bc1a;
case 0x0c07bc1cu: goto P_0c07bc1c;
case 0x0c07bc1eu: goto P_0c07bc1e;
case 0x0c07bc20u: goto P_0c07bc20;
case 0x0c07bc22u: goto P_0c07bc22;
case 0x0c07bc24u: goto P_0c07bc24;
case 0x0c07bc26u: goto P_0c07bc26;
case 0x0c07bc28u: goto P_0c07bc28;
case 0x0c07bc2au: goto P_0c07bc2a;
case 0x0c07bc2cu: goto P_0c07bc2c;
case 0x0c07bc2eu: goto P_0c07bc2e;
case 0x0c07bc30u: goto P_0c07bc30;
case 0x0c07bc32u: goto P_0c07bc32;
case 0x0c07bc34u: goto P_0c07bc34;
case 0x0c07bc36u: goto P_0c07bc36;
case 0x0c07bc38u: goto P_0c07bc38;
case 0x0c07bc3au: goto P_0c07bc3a;
case 0x0c07bc3cu: goto P_0c07bc3c;
case 0x0c07bc3eu: goto P_0c07bc3e;
case 0x0c07bc40u: goto P_0c07bc40;
case 0x0c07bc42u: goto P_0c07bc42;
case 0x0c07bc44u: goto P_0c07bc44;
case 0x0c07bc46u: goto P_0c07bc46;
case 0x0c07bc48u: goto P_0c07bc48;
case 0x0c07bc4au: goto P_0c07bc4a;
case 0x0c07bc4cu: goto P_0c07bc4c;
case 0x0c07bc4eu: goto P_0c07bc4e;
case 0x0c07bc50u: goto P_0c07bc50;
case 0x0c07bc52u: goto P_0c07bc52;
case 0x0c07bc54u: goto P_0c07bc54;
case 0x0c07bc56u: goto P_0c07bc56;
case 0x0c07bc58u: goto P_0c07bc58;
case 0x0c07bc5au: goto P_0c07bc5a;
case 0x0c07bc5cu: goto P_0c07bc5c;
case 0x0c07bc5eu: goto P_0c07bc5e;
case 0x0c07bc60u: goto P_0c07bc60;
case 0x0c07bc62u: goto P_0c07bc62;
case 0x0c07bc64u: goto P_0c07bc64;
case 0x0c07bc66u: goto P_0c07bc66;
case 0x0c07bc68u: goto P_0c07bc68;
case 0x0c07bc6au: goto P_0c07bc6a;
case 0x0c07bc6cu: goto P_0c07bc6c;
case 0x0c07bc6eu: goto P_0c07bc6e;
case 0x0c07bc70u: goto P_0c07bc70;
case 0x0c07bc72u: goto P_0c07bc72;
case 0x0c07bc74u: goto P_0c07bc74;
case 0x0c07bc76u: goto P_0c07bc76;
case 0x0c07bc78u: goto P_0c07bc78;
case 0x0c07bc7au: goto P_0c07bc7a;
case 0x0c07bc7cu: goto P_0c07bc7c;
case 0x0c07bc7eu: goto P_0c07bc7e;
case 0x0c07bc80u: goto P_0c07bc80;
case 0x0c07bc82u: goto P_0c07bc82;
case 0x0c07bc84u: goto P_0c07bc84;
case 0x0c07bc86u: goto P_0c07bc86;
case 0x0c07bc88u: goto P_0c07bc88;
case 0x0c07bc8au: goto P_0c07bc8a;
case 0x0c07bc8cu: goto P_0c07bc8c;
case 0x0c07bc8eu: goto P_0c07bc8e;
case 0x0c07bc90u: goto P_0c07bc90;
case 0x0c07bc92u: goto P_0c07bc92;
case 0x0c07bc94u: goto P_0c07bc94;
case 0x0c07bc96u: goto P_0c07bc96;
case 0x0c07bc98u: goto P_0c07bc98;
case 0x0c07bc9au: goto P_0c07bc9a;
case 0x0c07bc9cu: goto P_0c07bc9c;
case 0x0c07bc9eu: goto P_0c07bc9e;
case 0x0c07bca0u: goto P_0c07bca0;
case 0x0c07bca2u: goto P_0c07bca2;
case 0x0c07bca4u: goto P_0c07bca4;
case 0x0c07bca6u: goto P_0c07bca6;
case 0x0c07bca8u: goto P_0c07bca8;
case 0x0c07bcaau: goto P_0c07bcaa;
case 0x0c07bcacu: goto P_0c07bcac;
case 0x0c07bcaeu: goto P_0c07bcae;
case 0x0c07bcb0u: goto P_0c07bcb0;
case 0x0c07bcb2u: goto P_0c07bcb2;
case 0x0c07bcb4u: goto P_0c07bcb4;
case 0x0c07bcb6u: goto P_0c07bcb6;
case 0x0c07bcb8u: goto P_0c07bcb8;
case 0x0c07bcbau: goto P_0c07bcba;
case 0x0c07bcbcu: goto P_0c07bcbc;
case 0x0c07bcbeu: goto P_0c07bcbe;
case 0x0c07bcc0u: goto P_0c07bcc0;
case 0x0c07bcc2u: goto P_0c07bcc2;
case 0x0c07bcc4u: goto P_0c07bcc4;
case 0x0c07bcc6u: goto P_0c07bcc6;
case 0x0c07bcc8u: goto P_0c07bcc8;
case 0x0c07bccau: goto P_0c07bcca;
case 0x0c07bcccu: goto P_0c07bccc;
case 0x0c07bcceu: goto P_0c07bcce;
case 0x0c07bcd0u: goto P_0c07bcd0;
case 0x0c07bcd2u: goto P_0c07bcd2;
case 0x0c07bcd4u: goto P_0c07bcd4;
case 0x0c07bcd6u: goto P_0c07bcd6;
case 0x0c07bcd8u: goto P_0c07bcd8;
case 0x0c07bcdau: goto P_0c07bcda;
case 0x0c07bcdcu: goto P_0c07bcdc;
case 0x0c07bcdeu: goto P_0c07bcde;
case 0x0c07bce0u: goto P_0c07bce0;
case 0x0c07bce2u: goto P_0c07bce2;
case 0x0c07bce4u: goto P_0c07bce4;
case 0x0c07bce6u: goto P_0c07bce6;
case 0x0c07bce8u: goto P_0c07bce8;
case 0x0c07bceau: goto P_0c07bcea;
case 0x0c07bcecu: goto P_0c07bcec;
case 0x0c07bceeu: goto P_0c07bcee;
case 0x0c07bcf0u: goto P_0c07bcf0;
case 0x0c07bcf2u: goto P_0c07bcf2;
case 0x0c07bcf4u: goto P_0c07bcf4;
case 0x0c07bcf6u: goto P_0c07bcf6;
case 0x0c07bcf8u: goto P_0c07bcf8;
case 0x0c07bd14u: goto P_0c07bd14;
case 0x0c07bd16u: goto P_0c07bd16;
case 0x0c07bd18u: goto P_0c07bd18;
case 0x0c07bd1au: goto P_0c07bd1a;
case 0x0c07bd1cu: goto P_0c07bd1c;
case 0x0c07bd1eu: goto P_0c07bd1e;
case 0x0c07bd20u: goto P_0c07bd20;
case 0x0c07bd22u: goto P_0c07bd22;
case 0x0c07bd24u: goto P_0c07bd24;
case 0x0c07bd26u: goto P_0c07bd26;
case 0x0c07bd28u: goto P_0c07bd28;
case 0x0c07bd2au: goto P_0c07bd2a;
case 0x0c07bd2cu: goto P_0c07bd2c;
case 0x0c07bd2eu: goto P_0c07bd2e;
case 0x0c07bd30u: goto P_0c07bd30;
case 0x0c07bd32u: goto P_0c07bd32;
case 0x0c07bd34u: goto P_0c07bd34;
case 0x0c07bd36u: goto P_0c07bd36;
case 0x0c07bd38u: goto P_0c07bd38;
case 0x0c07bd3au: goto P_0c07bd3a;
case 0x0c07bd3cu: goto P_0c07bd3c;
case 0x0c07bd3eu: goto P_0c07bd3e;
case 0x0c07bd40u: goto P_0c07bd40;
case 0x0c07bd42u: goto P_0c07bd42;
case 0x0c07bd44u: goto P_0c07bd44;
case 0x0c07bd46u: goto P_0c07bd46;
case 0x0c07bd48u: goto P_0c07bd48;
case 0x0c07bd4au: goto P_0c07bd4a;
case 0x0c07bd4cu: goto P_0c07bd4c;
case 0x0c07bd4eu: goto P_0c07bd4e;
case 0x0c07bd50u: goto P_0c07bd50;
case 0x0c07bd52u: goto P_0c07bd52;
case 0x0c07bd54u: goto P_0c07bd54;
case 0x0c07bd56u: goto P_0c07bd56;
case 0x0c07bd58u: goto P_0c07bd58;
case 0x0c07bd5au: goto P_0c07bd5a;
case 0x0c07bd5cu: goto P_0c07bd5c;
case 0x0c07bd5eu: goto P_0c07bd5e;
case 0x0c07bd60u: goto P_0c07bd60;
case 0x0c07bd62u: goto P_0c07bd62;
case 0x0c07bd64u: goto P_0c07bd64;
case 0x0c07bd66u: goto P_0c07bd66;
case 0x0c07bd68u: goto P_0c07bd68;
case 0x0c07bd6au: goto P_0c07bd6a;
case 0x0c07bd6cu: goto P_0c07bd6c;
case 0x0c07bd6eu: goto P_0c07bd6e;
case 0x0c07bd70u: goto P_0c07bd70;
case 0x0c07bd72u: goto P_0c07bd72;
case 0x0c07bd74u: goto P_0c07bd74;
case 0x0c07bd76u: goto P_0c07bd76;
case 0x0c07bd78u: goto P_0c07bd78;
case 0x0c07bd7au: goto P_0c07bd7a;
case 0x0c07bd7cu: goto P_0c07bd7c;
case 0x0c07bd7eu: goto P_0c07bd7e;
case 0x0c07bd80u: goto P_0c07bd80;
case 0x0c07bd82u: goto P_0c07bd82;
case 0x0c07bd84u: goto P_0c07bd84;
case 0x0c07bd86u: goto P_0c07bd86;
case 0x0c07bd88u: goto P_0c07bd88;
case 0x0c07bd8au: goto P_0c07bd8a;
case 0x0c07bd8cu: goto P_0c07bd8c;
case 0x0c07bd8eu: goto P_0c07bd8e;
case 0x0c07bd90u: goto P_0c07bd90;
case 0x0c07bd92u: goto P_0c07bd92;
case 0x0c07bd94u: goto P_0c07bd94;
case 0x0c07bd96u: goto P_0c07bd96;
case 0x0c07bd98u: goto P_0c07bd98;
case 0x0c07bd9au: goto P_0c07bd9a;
case 0x0c07bd9cu: goto P_0c07bd9c;
case 0x0c07bd9eu: goto P_0c07bd9e;
case 0x0c07bda0u: goto P_0c07bda0;
case 0x0c07bda2u: goto P_0c07bda2;
case 0x0c07bda4u: goto P_0c07bda4;
case 0x0c07bda6u: goto P_0c07bda6;
case 0x0c07bda8u: goto P_0c07bda8;
case 0x0c07bdaau: goto P_0c07bdaa;
case 0x0c07bdacu: goto P_0c07bdac;
case 0x0c07bdaeu: goto P_0c07bdae;
case 0x0c07bdb0u: goto P_0c07bdb0;
case 0x0c07bdb2u: goto P_0c07bdb2;
case 0x0c07bdb4u: goto P_0c07bdb4;
case 0x0c07bdb6u: goto P_0c07bdb6;
case 0x0c07bdb8u: goto P_0c07bdb8;
case 0x0c07bdbau: goto P_0c07bdba;
case 0x0c07bdbcu: goto P_0c07bdbc;
case 0x0c07bdbeu: goto P_0c07bdbe;
case 0x0c07bdc0u: goto P_0c07bdc0;
case 0x0c07bdc2u: goto P_0c07bdc2;
case 0x0c07bdc4u: goto P_0c07bdc4;
case 0x0c07bdc6u: goto P_0c07bdc6;
case 0x0c07bdc8u: goto P_0c07bdc8;
case 0x0c07bdcau: goto P_0c07bdca;
case 0x0c07bdccu: goto P_0c07bdcc;
case 0x0c07bdceu: goto P_0c07bdce;
case 0x0c07bdd0u: goto P_0c07bdd0;
case 0x0c07bdd2u: goto P_0c07bdd2;
case 0x0c07bdd4u: goto P_0c07bdd4;
case 0x0c07bdd6u: goto P_0c07bdd6;
case 0x0c07bdd8u: goto P_0c07bdd8;
case 0x0c07bddau: goto P_0c07bdda;
case 0x0c07bddcu: goto P_0c07bddc;
case 0x0c07bddeu: goto P_0c07bdde;
case 0x0c07bde0u: goto P_0c07bde0;
case 0x0c07bde2u: goto P_0c07bde2;
case 0x0c07bde4u: goto P_0c07bde4;
case 0x0c07bde6u: goto P_0c07bde6;
case 0x0c07bde8u: goto P_0c07bde8;
case 0x0c07bdeau: goto P_0c07bdea;
case 0x0c07bdecu: goto P_0c07bdec;
case 0x0c07bdeeu: goto P_0c07bdee;
case 0x0c07bdf0u: goto P_0c07bdf0;
case 0x0c07bdf2u: goto P_0c07bdf2;
case 0x0c07bdf4u: goto P_0c07bdf4;
case 0x0c07bdf6u: goto P_0c07bdf6;
case 0x0c07bdf8u: goto P_0c07bdf8;
case 0x0c07bdfau: goto P_0c07bdfa;
case 0x0c07bdfcu: goto P_0c07bdfc;
case 0x0c07bdfeu: goto P_0c07bdfe;
case 0x0c07be00u: goto P_0c07be00;
case 0x0c07be02u: goto P_0c07be02;
case 0x0c07be04u: goto P_0c07be04;
case 0x0c07be06u: goto P_0c07be06;
case 0x0c07be08u: goto P_0c07be08;
case 0x0c07be0au: goto P_0c07be0a;
case 0x0c07be0cu: goto P_0c07be0c;
case 0x0c07be0eu: goto P_0c07be0e;
case 0x0c07be10u: goto P_0c07be10;
case 0x0c07be12u: goto P_0c07be12;
case 0x0c07be14u: goto P_0c07be14;
case 0x0c07be16u: goto P_0c07be16;
case 0x0c07be18u: goto P_0c07be18;
case 0x0c07be1au: goto P_0c07be1a;
case 0x0c07be1cu: goto P_0c07be1c;
case 0x0c07be1eu: goto P_0c07be1e;
case 0x0c07be20u: goto P_0c07be20;
case 0x0c07be22u: goto P_0c07be22;
case 0x0c07be24u: goto P_0c07be24;
case 0x0c07be26u: goto P_0c07be26;
case 0x0c07be28u: goto P_0c07be28;
case 0x0c07be2au: goto P_0c07be2a;
case 0x0c07be2cu: goto P_0c07be2c;
case 0x0c07be2eu: goto P_0c07be2e;
case 0x0c07be30u: goto P_0c07be30;
case 0x0c07be32u: goto P_0c07be32;
case 0x0c07be34u: goto P_0c07be34;
case 0x0c07be36u: goto P_0c07be36;
case 0x0c07be38u: goto P_0c07be38;
case 0x0c07be3au: goto P_0c07be3a;
case 0x0c07be3cu: goto P_0c07be3c;
case 0x0c07be3eu: goto P_0c07be3e;
case 0x0c07be40u: goto P_0c07be40;
case 0x0c07be42u: goto P_0c07be42;
case 0x0c07be44u: goto P_0c07be44;
case 0x0c07be46u: goto P_0c07be46;
case 0x0c07be48u: goto P_0c07be48;
case 0x0c07be4au: goto P_0c07be4a;
case 0x0c07be4cu: goto P_0c07be4c;
case 0x0c07be4eu: goto P_0c07be4e;
case 0x0c07be50u: goto P_0c07be50;
case 0x0c07be52u: goto P_0c07be52;
case 0x0c07be54u: goto P_0c07be54;
case 0x0c07be56u: goto P_0c07be56;
case 0x0c07be58u: goto P_0c07be58;
case 0x0c07be5au: goto P_0c07be5a;
case 0x0c07be5cu: goto P_0c07be5c;
case 0x0c07be5eu: goto P_0c07be5e;
case 0x0c07be60u: goto P_0c07be60;
case 0x0c07be62u: goto P_0c07be62;
case 0x0c07be64u: goto P_0c07be64;
case 0x0c07be66u: goto P_0c07be66;
case 0x0c07be68u: goto P_0c07be68;
case 0x0c07be6au: goto P_0c07be6a;
case 0x0c07be6cu: goto P_0c07be6c;
case 0x0c07be6eu: goto P_0c07be6e;
case 0x0c07be70u: goto P_0c07be70;
case 0x0c07be72u: goto P_0c07be72;
case 0x0c07be74u: goto P_0c07be74;
case 0x0c07be76u: goto P_0c07be76;
case 0x0c07be78u: goto P_0c07be78;
case 0x0c07be7au: goto P_0c07be7a;
case 0x0c07be7cu: goto P_0c07be7c;
case 0x0c07be7eu: goto P_0c07be7e;
case 0x0c07be80u: goto P_0c07be80;
case 0x0c07be82u: goto P_0c07be82;
case 0x0c07be84u: goto P_0c07be84;
case 0x0c07be86u: goto P_0c07be86;
case 0x0c07be88u: goto P_0c07be88;
case 0x0c07be8au: goto P_0c07be8a;
case 0x0c07be8cu: goto P_0c07be8c;
case 0x0c07be8eu: goto P_0c07be8e;
case 0x0c07be90u: goto P_0c07be90;
case 0x0c07be92u: goto P_0c07be92;
case 0x0c07be94u: goto P_0c07be94;
case 0x0c07be96u: goto P_0c07be96;
case 0x0c07be98u: goto P_0c07be98;
case 0x0c07be9au: goto P_0c07be9a;
case 0x0c07beb0u: goto P_0c07beb0;
case 0x0c07beb2u: goto P_0c07beb2;
case 0x0c07beb4u: goto P_0c07beb4;
case 0x0c07beb6u: goto P_0c07beb6;
case 0x0c07beb8u: goto P_0c07beb8;
case 0x0c07bebau: goto P_0c07beba;
case 0x0c07bebcu: goto P_0c07bebc;
case 0x0c07bebeu: goto P_0c07bebe;
case 0x0c07bec0u: goto P_0c07bec0;
case 0x0c07bec2u: goto P_0c07bec2;
case 0x0c07bec4u: goto P_0c07bec4;
case 0x0c07bec6u: goto P_0c07bec6;
case 0x0c07bec8u: goto P_0c07bec8;
case 0x0c07becau: goto P_0c07beca;
case 0x0c07beccu: goto P_0c07becc;
case 0x0c07beceu: goto P_0c07bece;
case 0x0c07bed0u: goto P_0c07bed0;
case 0x0c07bed2u: goto P_0c07bed2;
case 0x0c07bed4u: goto P_0c07bed4;
case 0x0c07bed6u: goto P_0c07bed6;
case 0x0c07bed8u: goto P_0c07bed8;
case 0x0c07bedau: goto P_0c07beda;
case 0x0c07bedcu: goto P_0c07bedc;
case 0x0c07bedeu: goto P_0c07bede;
case 0x0c07bee0u: goto P_0c07bee0;
case 0x0c07bee2u: goto P_0c07bee2;
case 0x0c07bee4u: goto P_0c07bee4;
case 0x0c07bee6u: goto P_0c07bee6;
case 0x0c07bee8u: goto P_0c07bee8;
case 0x0c07beeau: goto P_0c07beea;
case 0x0c07beecu: goto P_0c07beec;
case 0x0c07beeeu: goto P_0c07beee;
case 0x0c07bef0u: goto P_0c07bef0;
case 0x0c07bef2u: goto P_0c07bef2;
case 0x0c07bef4u: goto P_0c07bef4;
case 0x0c07bef6u: goto P_0c07bef6;
case 0x0c07bef8u: goto P_0c07bef8;
case 0x0c07befau: goto P_0c07befa;
case 0x0c07befcu: goto P_0c07befc;
case 0x0c07befeu: goto P_0c07befe;
case 0x0c07bf00u: goto P_0c07bf00;
case 0x0c07bf02u: goto P_0c07bf02;
case 0x0c07bf04u: goto P_0c07bf04;
case 0x0c07bf06u: goto P_0c07bf06;
case 0x0c07bf08u: goto P_0c07bf08;
case 0x0c07bf0au: goto P_0c07bf0a;
case 0x0c07bf0cu: goto P_0c07bf0c;
case 0x0c07bf0eu: goto P_0c07bf0e;
case 0x0c07bf10u: goto P_0c07bf10;
case 0x0c07bf12u: goto P_0c07bf12;
case 0x0c07bf14u: goto P_0c07bf14;
case 0x0c07bf16u: goto P_0c07bf16;
case 0x0c07bf18u: goto P_0c07bf18;
case 0x0c07bf1au: goto P_0c07bf1a;
case 0x0c07bf1cu: goto P_0c07bf1c;
case 0x0c07bf1eu: goto P_0c07bf1e;
case 0x0c07bf20u: goto P_0c07bf20;
case 0x0c07bf22u: goto P_0c07bf22;
case 0x0c07bf24u: goto P_0c07bf24;
case 0x0c07bf26u: goto P_0c07bf26;
case 0x0c07bf28u: goto P_0c07bf28;
case 0x0c07bf2au: goto P_0c07bf2a;
case 0x0c07bf2cu: goto P_0c07bf2c;
case 0x0c07bf2eu: goto P_0c07bf2e;
case 0x0c07bf30u: goto P_0c07bf30;
case 0x0c07bf32u: goto P_0c07bf32;
case 0x0c07bf34u: goto P_0c07bf34;
case 0x0c07bf36u: goto P_0c07bf36;
case 0x0c07bf38u: goto P_0c07bf38;
case 0x0c07bf3au: goto P_0c07bf3a;
case 0x0c07bf3cu: goto P_0c07bf3c;
case 0x0c07bf3eu: goto P_0c07bf3e;
case 0x0c07bf40u: goto P_0c07bf40;
case 0x0c07bf42u: goto P_0c07bf42;
case 0x0c07bf44u: goto P_0c07bf44;
case 0x0c07bf46u: goto P_0c07bf46;
case 0x0c07bf48u: goto P_0c07bf48;
case 0x0c07bf4au: goto P_0c07bf4a;
case 0x0c07bf4cu: goto P_0c07bf4c;
case 0x0c07bf4eu: goto P_0c07bf4e;
case 0x0c07bf50u: goto P_0c07bf50;
case 0x0c07bf52u: goto P_0c07bf52;
case 0x0c07bf54u: goto P_0c07bf54;
case 0x0c07bf56u: goto P_0c07bf56;
case 0x0c07bf58u: goto P_0c07bf58;
case 0x0c07bf5au: goto P_0c07bf5a;
case 0x0c07bf5cu: goto P_0c07bf5c;
case 0x0c07bf5eu: goto P_0c07bf5e;
case 0x0c07bf60u: goto P_0c07bf60;
case 0x0c07bf62u: goto P_0c07bf62;
case 0x0c07bf64u: goto P_0c07bf64;
case 0x0c07bf66u: goto P_0c07bf66;
case 0x0c07bf68u: goto P_0c07bf68;
case 0x0c07bf6au: goto P_0c07bf6a;
case 0x0c07bf6cu: goto P_0c07bf6c;
case 0x0c07bf6eu: goto P_0c07bf6e;
case 0x0c07bf70u: goto P_0c07bf70;
case 0x0c07bf72u: goto P_0c07bf72;
case 0x0c07bf74u: goto P_0c07bf74;
case 0x0c07bf76u: goto P_0c07bf76;
case 0x0c07bf78u: goto P_0c07bf78;
case 0x0c07bf7au: goto P_0c07bf7a;
case 0x0c07bf7cu: goto P_0c07bf7c;
case 0x0c07bf7eu: goto P_0c07bf7e;
case 0x0c07bf80u: goto P_0c07bf80;
case 0x0c07bf82u: goto P_0c07bf82;
case 0x0c07bf84u: goto P_0c07bf84;
case 0x0c07bf86u: goto P_0c07bf86;
case 0x0c07bf88u: goto P_0c07bf88;
case 0x0c07bf8au: goto P_0c07bf8a;
case 0x0c07bf8cu: goto P_0c07bf8c;
case 0x0c07bf8eu: goto P_0c07bf8e;
case 0x0c07bf90u: goto P_0c07bf90;
case 0x0c07bf92u: goto P_0c07bf92;
case 0x0c07bf94u: goto P_0c07bf94;
case 0x0c07bf96u: goto P_0c07bf96;
case 0x0c07bf98u: goto P_0c07bf98;
case 0x0c07bf9au: goto P_0c07bf9a;
case 0x0c07bf9cu: goto P_0c07bf9c;
case 0x0c07bf9eu: goto P_0c07bf9e;
case 0x0c07bfa0u: goto P_0c07bfa0;
case 0x0c07bfa2u: goto P_0c07bfa2;
case 0x0c07bfa4u: goto P_0c07bfa4;
case 0x0c07bfa6u: goto P_0c07bfa6;
case 0x0c07bfa8u: goto P_0c07bfa8;
case 0x0c07bfaau: goto P_0c07bfaa;
case 0x0c07bfacu: goto P_0c07bfac;
case 0x0c07bfaeu: goto P_0c07bfae;
case 0x0c07bfb0u: goto P_0c07bfb0;
case 0x0c07bfb2u: goto P_0c07bfb2;
case 0x0c07bfb4u: goto P_0c07bfb4;
case 0x0c07bfb6u: goto P_0c07bfb6;
case 0x0c07bfb8u: goto P_0c07bfb8;
case 0x0c07bfbau: goto P_0c07bfba;
case 0x0c07bfbcu: goto P_0c07bfbc;
case 0x0c07bfbeu: goto P_0c07bfbe;
case 0x0c07bfc0u: goto P_0c07bfc0;
case 0x0c07bfc2u: goto P_0c07bfc2;
case 0x0c07bfc4u: goto P_0c07bfc4;
case 0x0c07bfc6u: goto P_0c07bfc6;
case 0x0c07bfc8u: goto P_0c07bfc8;
case 0x0c07bfcau: goto P_0c07bfca;
case 0x0c07bfccu: goto P_0c07bfcc;
case 0x0c07bfceu: goto P_0c07bfce;
case 0x0c07bfd0u: goto P_0c07bfd0;
case 0x0c07bfd2u: goto P_0c07bfd2;
case 0x0c07bfd4u: goto P_0c07bfd4;
case 0x0c07bfd6u: goto P_0c07bfd6;
case 0x0c07bfd8u: goto P_0c07bfd8;
case 0x0c07bfdau: goto P_0c07bfda;
case 0x0c07bfdcu: goto P_0c07bfdc;
case 0x0c07bfdeu: goto P_0c07bfde;
case 0x0c07bfe0u: goto P_0c07bfe0;
case 0x0c07bfe2u: goto P_0c07bfe2;
case 0x0c07bfe4u: goto P_0c07bfe4;
case 0x0c07bfe6u: goto P_0c07bfe6;
case 0x0c07bfe8u: goto P_0c07bfe8;
case 0x0c07bfeau: goto P_0c07bfea;
case 0x0c07bfecu: goto P_0c07bfec;
case 0x0c07bfeeu: goto P_0c07bfee;
case 0x0c07bff0u: goto P_0c07bff0;
case 0x0c07bff2u: goto P_0c07bff2;
case 0x0c07bff4u: goto P_0c07bff4;
case 0x0c07bff6u: goto P_0c07bff6;
case 0x0c07bff8u: goto P_0c07bff8;
case 0x0c07bffau: goto P_0c07bffa;
case 0x0c07bffcu: goto P_0c07bffc;
case 0x0c07bffeu: goto P_0c07bffe;
case 0x0c07c000u: goto P_0c07c000;
case 0x0c07c002u: goto P_0c07c002;
case 0x0c07c004u: goto P_0c07c004;
case 0x0c07c006u: goto P_0c07c006;
case 0x0c07c008u: goto P_0c07c008;
case 0x0c07c00au: goto P_0c07c00a;
case 0x0c07c00cu: goto P_0c07c00c;
case 0x0c07c00eu: goto P_0c07c00e;
case 0x0c07c010u: goto P_0c07c010;
case 0x0c07c012u: goto P_0c07c012;
case 0x0c07c014u: goto P_0c07c014;
case 0x0c07c016u: goto P_0c07c016;
case 0x0c07c018u: goto P_0c07c018;
case 0x0c07c01au: goto P_0c07c01a;
case 0x0c07c01cu: goto P_0c07c01c;
case 0x0c07c01eu: goto P_0c07c01e;
case 0x0c07c020u: goto P_0c07c020;
case 0x0c07c022u: goto P_0c07c022;
case 0x0c07c024u: goto P_0c07c024;
case 0x0c07c026u: goto P_0c07c026;
case 0x0c07c028u: goto P_0c07c028;
case 0x0c07c02au: goto P_0c07c02a;
case 0x0c07c02cu: goto P_0c07c02c;
case 0x0c07c02eu: goto P_0c07c02e;
case 0x0c07c030u: goto P_0c07c030;
case 0x0c07c032u: goto P_0c07c032;
case 0x0c07c034u: goto P_0c07c034;
case 0x0c07c036u: goto P_0c07c036;
case 0x0c07c038u: goto P_0c07c038;
case 0x0c07c03au: goto P_0c07c03a;
case 0x0c07c03cu: goto P_0c07c03c;
case 0x0c07c03eu: goto P_0c07c03e;
case 0x0c07c040u: goto P_0c07c040;
case 0x0c07c042u: goto P_0c07c042;
case 0x0c07c05cu: goto P_0c07c05c;
case 0x0c07c05eu: goto P_0c07c05e;
case 0x0c07c060u: goto P_0c07c060;
case 0x0c07c062u: goto P_0c07c062;
case 0x0c07c064u: goto P_0c07c064;
case 0x0c07c066u: goto P_0c07c066;
case 0x0c07c068u: goto P_0c07c068;
case 0x0c07c06au: goto P_0c07c06a;
case 0x0c07c06cu: goto P_0c07c06c;
case 0x0c07c06eu: goto P_0c07c06e;
case 0x0c07c070u: goto P_0c07c070;
case 0x0c07c072u: goto P_0c07c072;
case 0x0c07c074u: goto P_0c07c074;
case 0x0c07c076u: goto P_0c07c076;
case 0x0c07c078u: goto P_0c07c078;
case 0x0c07c07au: goto P_0c07c07a;
case 0x0c07c07cu: goto P_0c07c07c;
case 0x0c07c07eu: goto P_0c07c07e;
case 0x0c07c080u: goto P_0c07c080;
case 0x0c07c082u: goto P_0c07c082;
case 0x0c07c084u: goto P_0c07c084;
case 0x0c07c086u: goto P_0c07c086;
case 0x0c07c088u: goto P_0c07c088;
case 0x0c07c08au: goto P_0c07c08a;
case 0x0c07c08cu: goto P_0c07c08c;
case 0x0c07c08eu: goto P_0c07c08e;
case 0x0c07c090u: goto P_0c07c090;
case 0x0c07c092u: goto P_0c07c092;
case 0x0c07c094u: goto P_0c07c094;
case 0x0c07c096u: goto P_0c07c096;
case 0x0c07c098u: goto P_0c07c098;
case 0x0c07c09au: goto P_0c07c09a;
case 0x0c07c09cu: goto P_0c07c09c;
case 0x0c07c09eu: goto P_0c07c09e;
case 0x0c07c0a0u: goto P_0c07c0a0;
case 0x0c07c0a2u: goto P_0c07c0a2;
case 0x0c07c0a4u: goto P_0c07c0a4;
case 0x0c07c0a6u: goto P_0c07c0a6;
case 0x0c07c0a8u: goto P_0c07c0a8;
case 0x0c07c0aau: goto P_0c07c0aa;
case 0x0c07c0acu: goto P_0c07c0ac;
case 0x0c07c0aeu: goto P_0c07c0ae;
case 0x0c07c0b0u: goto P_0c07c0b0;
case 0x0c07c0b2u: goto P_0c07c0b2;
case 0x0c07c0b4u: goto P_0c07c0b4;
case 0x0c07c0b6u: goto P_0c07c0b6;
case 0x0c07c0b8u: goto P_0c07c0b8;
case 0x0c07c0bau: goto P_0c07c0ba;
case 0x0c07c0bcu: goto P_0c07c0bc;
case 0x0c07c0beu: goto P_0c07c0be;
case 0x0c07c0c0u: goto P_0c07c0c0;
case 0x0c07c0c2u: goto P_0c07c0c2;
case 0x0c07c0c4u: goto P_0c07c0c4;
case 0x0c07c0c6u: goto P_0c07c0c6;
case 0x0c07c0c8u: goto P_0c07c0c8;
case 0x0c07c0cau: goto P_0c07c0ca;
case 0x0c07c0ccu: goto P_0c07c0cc;
case 0x0c07c0ceu: goto P_0c07c0ce;
case 0x0c07c0d0u: goto P_0c07c0d0;
case 0x0c07c0d2u: goto P_0c07c0d2;
case 0x0c07c0d4u: goto P_0c07c0d4;
case 0x0c07c0d6u: goto P_0c07c0d6;
case 0x0c07c0d8u: goto P_0c07c0d8;
case 0x0c07c0dau: goto P_0c07c0da;
case 0x0c07c0dcu: goto P_0c07c0dc;
case 0x0c07c0deu: goto P_0c07c0de;
case 0x0c07c0e0u: goto P_0c07c0e0;
case 0x0c07c0e2u: goto P_0c07c0e2;
case 0x0c07c0e4u: goto P_0c07c0e4;
case 0x0c07c0e6u: goto P_0c07c0e6;
case 0x0c07c0e8u: goto P_0c07c0e8;
case 0x0c07c0eau: goto P_0c07c0ea;
case 0x0c07c0ecu: goto P_0c07c0ec;
case 0x0c07c0eeu: goto P_0c07c0ee;
case 0x0c07c0f0u: goto P_0c07c0f0;
case 0x0c07c0f2u: goto P_0c07c0f2;
case 0x0c07c0f4u: goto P_0c07c0f4;
case 0x0c07c0f6u: goto P_0c07c0f6;
case 0x0c07c0f8u: goto P_0c07c0f8;
case 0x0c07c0fau: goto P_0c07c0fa;
case 0x0c07c0fcu: goto P_0c07c0fc;
case 0x0c07c0feu: goto P_0c07c0fe;
case 0x0c07c100u: goto P_0c07c100;
case 0x0c07c102u: goto P_0c07c102;
case 0x0c07c12cu: goto P_0c07c12c;
case 0x0c07c12eu: goto P_0c07c12e;
case 0x0c07c130u: goto P_0c07c130;
case 0x0c07c132u: goto P_0c07c132;
case 0x0c07c134u: goto P_0c07c134;
case 0x0c07c136u: goto P_0c07c136;
case 0x0c07c138u: goto P_0c07c138;
case 0x0c07c13au: goto P_0c07c13a;
case 0x0c07c13cu: goto P_0c07c13c;
case 0x0c07c13eu: goto P_0c07c13e;
case 0x0c07c140u: goto P_0c07c140;
case 0x0c07c142u: goto P_0c07c142;
case 0x0c07c144u: goto P_0c07c144;
case 0x0c07c146u: goto P_0c07c146;
case 0x0c07c148u: goto P_0c07c148;
case 0x0c07c14au: goto P_0c07c14a;
case 0x0c07c14cu: goto P_0c07c14c;
case 0x0c07c14eu: goto P_0c07c14e;
case 0x0c07c150u: goto P_0c07c150;
case 0x0c07c152u: goto P_0c07c152;
case 0x0c07c154u: goto P_0c07c154;
case 0x0c07c156u: goto P_0c07c156;
case 0x0c07c158u: goto P_0c07c158;
case 0x0c07c15au: goto P_0c07c15a;
case 0x0c07c15cu: goto P_0c07c15c;
case 0x0c07c15eu: goto P_0c07c15e;
case 0x0c07c160u: goto P_0c07c160;
case 0x0c07c162u: goto P_0c07c162;
case 0x0c07c164u: goto P_0c07c164;
case 0x0c07c166u: goto P_0c07c166;
case 0x0c07c168u: goto P_0c07c168;
case 0x0c07c16au: goto P_0c07c16a;
case 0x0c07c16cu: goto P_0c07c16c;
case 0x0c07c16eu: goto P_0c07c16e;
case 0x0c07c170u: goto P_0c07c170;
case 0x0c07c172u: goto P_0c07c172;
case 0x0c07c174u: goto P_0c07c174;
case 0x0c07c176u: goto P_0c07c176;
case 0x0c07c178u: goto P_0c07c178;
case 0x0c07c17au: goto P_0c07c17a;
case 0x0c07c17cu: goto P_0c07c17c;
case 0x0c07c17eu: goto P_0c07c17e;
case 0x0c07c180u: goto P_0c07c180;
case 0x0c07c182u: goto P_0c07c182;
case 0x0c07c184u: goto P_0c07c184;
case 0x0c07c186u: goto P_0c07c186;
case 0x0c07c188u: goto P_0c07c188;
case 0x0c07c18au: goto P_0c07c18a;
case 0x0c07c18cu: goto P_0c07c18c;
case 0x0c07c18eu: goto P_0c07c18e;
case 0x0c07c190u: goto P_0c07c190;
case 0x0c07c192u: goto P_0c07c192;
case 0x0c07c194u: goto P_0c07c194;
case 0x0c07c196u: goto P_0c07c196;
case 0x0c07c198u: goto P_0c07c198;
case 0x0c07c19au: goto P_0c07c19a;
case 0x0c07c19cu: goto P_0c07c19c;
case 0x0c07c19eu: goto P_0c07c19e;
case 0x0c07c1a0u: goto P_0c07c1a0;
case 0x0c07c1a2u: goto P_0c07c1a2;
case 0x0c07c1a4u: goto P_0c07c1a4;
case 0x0c07c1a6u: goto P_0c07c1a6;
case 0x0c07c1a8u: goto P_0c07c1a8;
case 0x0c07c1aau: goto P_0c07c1aa;
case 0x0c07c1acu: goto P_0c07c1ac;
case 0x0c07c1aeu: goto P_0c07c1ae;
case 0x0c07c1b0u: goto P_0c07c1b0;
case 0x0c07c1b2u: goto P_0c07c1b2;
case 0x0c07c1b4u: goto P_0c07c1b4;
case 0x0c07c1b6u: goto P_0c07c1b6;
case 0x0c07c1b8u: goto P_0c07c1b8;
case 0x0c07c1bau: goto P_0c07c1ba;
case 0x0c07c1bcu: goto P_0c07c1bc;
case 0x0c07c1beu: goto P_0c07c1be;
case 0x0c07c1c0u: goto P_0c07c1c0;
case 0x0c07c1c2u: goto P_0c07c1c2;
case 0x0c07c1c4u: goto P_0c07c1c4;
case 0x0c07c1c6u: goto P_0c07c1c6;
case 0x0c07c1c8u: goto P_0c07c1c8;
case 0x0c07c1cau: goto P_0c07c1ca;
case 0x0c07c1ccu: goto P_0c07c1cc;
case 0x0c07c1ceu: goto P_0c07c1ce;
case 0x0c07c1d0u: goto P_0c07c1d0;
case 0x0c07c1d2u: goto P_0c07c1d2;
case 0x0c07c1d4u: goto P_0c07c1d4;
case 0x0c07c1d6u: goto P_0c07c1d6;
case 0x0c07c1d8u: goto P_0c07c1d8;
case 0x0c07c1dau: goto P_0c07c1da;
case 0x0c07c1dcu: goto P_0c07c1dc;
case 0x0c07c1deu: goto P_0c07c1de;
case 0x0c07c1e0u: goto P_0c07c1e0;
case 0x0c07c1e2u: goto P_0c07c1e2;
case 0x0c07c1e4u: goto P_0c07c1e4;
case 0x0c07c1e6u: goto P_0c07c1e6;
case 0x0c07c1e8u: goto P_0c07c1e8;
case 0x0c07c1eau: goto P_0c07c1ea;
case 0x0c07c1ecu: goto P_0c07c1ec;
case 0x0c07c1eeu: goto P_0c07c1ee;
case 0x0c07c1f0u: goto P_0c07c1f0;
case 0x0c07c1f2u: goto P_0c07c1f2;
case 0x0c07c1f4u: goto P_0c07c1f4;
case 0x0c07c1f6u: goto P_0c07c1f6;
case 0x0c07c1f8u: goto P_0c07c1f8;
case 0x0c07c1fau: goto P_0c07c1fa;
case 0x0c07c1fcu: goto P_0c07c1fc;
case 0x0c07c1feu: goto P_0c07c1fe;
case 0x0c07c200u: goto P_0c07c200;
case 0x0c07c202u: goto P_0c07c202;
case 0x0c07c204u: goto P_0c07c204;
case 0x0c07c206u: goto P_0c07c206;
case 0x0c07c208u: goto P_0c07c208;
case 0x0c07c20au: goto P_0c07c20a;
case 0x0c07c20cu: goto P_0c07c20c;
case 0x0c07c20eu: goto P_0c07c20e;
case 0x0c07c210u: goto P_0c07c210;
case 0x0c07c212u: goto P_0c07c212;
case 0x0c07c214u: goto P_0c07c214;
case 0x0c07c216u: goto P_0c07c216;
case 0x0c07c218u: goto P_0c07c218;
case 0x0c07c21au: goto P_0c07c21a;
case 0x0c07c21cu: goto P_0c07c21c;
case 0x0c07c21eu: goto P_0c07c21e;
case 0x0c07c220u: goto P_0c07c220;
case 0x0c07c222u: goto P_0c07c222;
case 0x0c07c224u: goto P_0c07c224;
case 0x0c07c226u: goto P_0c07c226;
case 0x0c07c228u: goto P_0c07c228;
case 0x0c07c22au: goto P_0c07c22a;
case 0x0c07c22cu: goto P_0c07c22c;
case 0x0c07c22eu: goto P_0c07c22e;
case 0x0c07c230u: goto P_0c07c230;
case 0x0c07c232u: goto P_0c07c232;
case 0x0c07c234u: goto P_0c07c234;
case 0x0c07c236u: goto P_0c07c236;
case 0x0c07c238u: goto P_0c07c238;
case 0x0c07c23au: goto P_0c07c23a;
case 0x0c07c23cu: goto P_0c07c23c;
case 0x0c07c23eu: goto P_0c07c23e;
case 0x0c07c240u: goto P_0c07c240;
case 0x0c07c242u: goto P_0c07c242;
case 0x0c07c244u: goto P_0c07c244;
case 0x0c07c246u: goto P_0c07c246;
case 0x0c07c248u: goto P_0c07c248;
case 0x0c07c24au: goto P_0c07c24a;
case 0x0c07c24cu: goto P_0c07c24c;
case 0x0c07c24eu: goto P_0c07c24e;
case 0x0c07c250u: goto P_0c07c250;
case 0x0c07c252u: goto P_0c07c252;
case 0x0c07c254u: goto P_0c07c254;
case 0x0c07c256u: goto P_0c07c256;
case 0x0c07c258u: goto P_0c07c258;
case 0x0c07c25au: goto P_0c07c25a;
case 0x0c07c25cu: goto P_0c07c25c;
case 0x0c07c25eu: goto P_0c07c25e;
case 0x0c07c260u: goto P_0c07c260;
case 0x0c07c262u: goto P_0c07c262;
case 0x0c07c264u: goto P_0c07c264;
case 0x0c07c266u: goto P_0c07c266;
case 0x0c07c268u: goto P_0c07c268;
case 0x0c07c26au: goto P_0c07c26a;
case 0x0c07c26cu: goto P_0c07c26c;
case 0x0c07c26eu: goto P_0c07c26e;
case 0x0c07c270u: goto P_0c07c270;
case 0x0c07c272u: goto P_0c07c272;
case 0x0c07c274u: goto P_0c07c274;
case 0x0c07c276u: goto P_0c07c276;
case 0x0c07c278u: goto P_0c07c278;
case 0x0c07c27au: goto P_0c07c27a;
case 0x0c07c27cu: goto P_0c07c27c;
case 0x0c07c27eu: goto P_0c07c27e;
case 0x0c07c280u: goto P_0c07c280;
case 0x0c07c282u: goto P_0c07c282;
case 0x0c07c284u: goto P_0c07c284;
case 0x0c07c286u: goto P_0c07c286;
case 0x0c07c288u: goto P_0c07c288;
case 0x0c07c28au: goto P_0c07c28a;
case 0x0c07c28cu: goto P_0c07c28c;
case 0x0c07c28eu: goto P_0c07c28e;
case 0x0c07c290u: goto P_0c07c290;
case 0x0c07c292u: goto P_0c07c292;
case 0x0c07c294u: goto P_0c07c294;
case 0x0c07c296u: goto P_0c07c296;
case 0x0c07c298u: goto P_0c07c298;
case 0x0c07c29au: goto P_0c07c29a;
case 0x0c07c29cu: goto P_0c07c29c;
case 0x0c07c29eu: goto P_0c07c29e;
case 0x0c07c2a0u: goto P_0c07c2a0;
case 0x0c07c2a2u: goto P_0c07c2a2;
case 0x0c07c2a4u: goto P_0c07c2a4;
case 0x0c07c2a6u: goto P_0c07c2a6;
case 0x0c07c2a8u: goto P_0c07c2a8;
case 0x0c07c2aau: goto P_0c07c2aa;
case 0x0c07c2acu: goto P_0c07c2ac;
case 0x0c07c2aeu: goto P_0c07c2ae;
case 0x0c07c2b0u: goto P_0c07c2b0;
case 0x0c07c2b2u: goto P_0c07c2b2;
case 0x0c07c2b4u: goto P_0c07c2b4;
case 0x0c07c2d0u: goto P_0c07c2d0;
case 0x0c07c2d2u: goto P_0c07c2d2;
case 0x0c07c2d4u: goto P_0c07c2d4;
case 0x0c07c2d6u: goto P_0c07c2d6;
case 0x0c07c2d8u: goto P_0c07c2d8;
case 0x0c07c2dau: goto P_0c07c2da;
case 0x0c07c2dcu: goto P_0c07c2dc;
case 0x0c07c2deu: goto P_0c07c2de;
case 0x0c07c2e0u: goto P_0c07c2e0;
case 0x0c07c2e2u: goto P_0c07c2e2;
case 0x0c07c2e4u: goto P_0c07c2e4;
case 0x0c07c2e6u: goto P_0c07c2e6;
case 0x0c07c2e8u: goto P_0c07c2e8;
case 0x0c07c2eau: goto P_0c07c2ea;
case 0x0c07c2ecu: goto P_0c07c2ec;
case 0x0c07c2eeu: goto P_0c07c2ee;
case 0x0c07c2f0u: goto P_0c07c2f0;
case 0x0c07c2f2u: goto P_0c07c2f2;
case 0x0c07c2f4u: goto P_0c07c2f4;
case 0x0c07c2f6u: goto P_0c07c2f6;
case 0x0c07c2f8u: goto P_0c07c2f8;
case 0x0c07c2fau: goto P_0c07c2fa;
case 0x0c07c2fcu: goto P_0c07c2fc;
case 0x0c07c2feu: goto P_0c07c2fe;
case 0x0c07c300u: goto P_0c07c300;
case 0x0c07c302u: goto P_0c07c302;
case 0x0c07c304u: goto P_0c07c304;
case 0x0c07c306u: goto P_0c07c306;
case 0x0c07c308u: goto P_0c07c308;
case 0x0c07c30au: goto P_0c07c30a;
case 0x0c07c30cu: goto P_0c07c30c;
case 0x0c07c30eu: goto P_0c07c30e;
case 0x0c07c310u: goto P_0c07c310;
case 0x0c07c312u: goto P_0c07c312;
case 0x0c07c314u: goto P_0c07c314;
case 0x0c07c316u: goto P_0c07c316;
case 0x0c07c318u: goto P_0c07c318;
case 0x0c07c31au: goto P_0c07c31a;
case 0x0c07c31cu: goto P_0c07c31c;
case 0x0c07c31eu: goto P_0c07c31e;
case 0x0c07c320u: goto P_0c07c320;
case 0x0c07c322u: goto P_0c07c322;
case 0x0c07c324u: goto P_0c07c324;
case 0x0c07c326u: goto P_0c07c326;
case 0x0c07c328u: goto P_0c07c328;
case 0x0c07c32au: goto P_0c07c32a;
case 0x0c07c32cu: goto P_0c07c32c;
case 0x0c07c32eu: goto P_0c07c32e;
case 0x0c07c330u: goto P_0c07c330;
case 0x0c07c332u: goto P_0c07c332;
case 0x0c07c540u: goto P_0c07c540;
case 0x0c07c542u: goto P_0c07c542;
case 0x0c07c544u: goto P_0c07c544;
case 0x0c07c546u: goto P_0c07c546;
case 0x0c07c548u: goto P_0c07c548;
case 0x0c07c54au: goto P_0c07c54a;
case 0x0c07c54cu: goto P_0c07c54c;
case 0x0c07c54eu: goto P_0c07c54e;
case 0x0c07c550u: goto P_0c07c550;
case 0x0c07c552u: goto P_0c07c552;
case 0x0c07c554u: goto P_0c07c554;
case 0x0c07c556u: goto P_0c07c556;
case 0x0c07c558u: goto P_0c07c558;
case 0x0c07c55au: goto P_0c07c55a;
case 0x0c07c55cu: goto P_0c07c55c;
case 0x0c07c55eu: goto P_0c07c55e;
case 0x0c07c560u: goto P_0c07c560;
case 0x0c07c562u: goto P_0c07c562;
case 0x0c07c564u: goto P_0c07c564;
case 0x0c07c566u: goto P_0c07c566;
case 0x0c07c568u: goto P_0c07c568;
case 0x0c07c56au: goto P_0c07c56a;
case 0x0c07c56cu: goto P_0c07c56c;
case 0x0c07c56eu: goto P_0c07c56e;
case 0x0c07c570u: goto P_0c07c570;
case 0x0c07c572u: goto P_0c07c572;
case 0x0c07c574u: goto P_0c07c574;
case 0x0c07c576u: goto P_0c07c576;
case 0x0c07c578u: goto P_0c07c578;
case 0x0c07c57au: goto P_0c07c57a;
case 0x0c07c57cu: goto P_0c07c57c;
case 0x0c07c57eu: goto P_0c07c57e;
case 0x0c07c580u: goto P_0c07c580;
case 0x0c07c582u: goto P_0c07c582;
case 0x0c07c584u: goto P_0c07c584;
case 0x0c07c586u: goto P_0c07c586;
case 0x0c07c588u: goto P_0c07c588;
case 0x0c07c58au: goto P_0c07c58a;
case 0x0c07c58cu: goto P_0c07c58c;
case 0x0c07c58eu: goto P_0c07c58e;
case 0x0c07c590u: goto P_0c07c590;
case 0x0c07c592u: goto P_0c07c592;
case 0x0c07c594u: goto P_0c07c594;
case 0x0c07c596u: goto P_0c07c596;
case 0x0c07c598u: goto P_0c07c598;
case 0x0c07c59au: goto P_0c07c59a;
case 0x0c07c59cu: goto P_0c07c59c;
case 0x0c07c59eu: goto P_0c07c59e;
case 0x0c07c5a0u: goto P_0c07c5a0;
case 0x0c07c5a2u: goto P_0c07c5a2;
case 0x0c07c5a4u: goto P_0c07c5a4;
case 0x0c07c5a6u: goto P_0c07c5a6;
case 0x0c07c5a8u: goto P_0c07c5a8;
case 0x0c07c5aau: goto P_0c07c5aa;
case 0x0c07c5acu: goto P_0c07c5ac;
case 0x0c07c5aeu: goto P_0c07c5ae;
case 0x0c07c5b0u: goto P_0c07c5b0;
case 0x0c07c5b2u: goto P_0c07c5b2;
case 0x0c07c5b4u: goto P_0c07c5b4;
case 0x0c07c5b6u: goto P_0c07c5b6;
case 0x0c07c5b8u: goto P_0c07c5b8;
case 0x0c07c5bau: goto P_0c07c5ba;
case 0x0c07c5bcu: goto P_0c07c5bc;
case 0x0c07c5beu: goto P_0c07c5be;
case 0x0c07c5c0u: goto P_0c07c5c0;
case 0x0c07c5c2u: goto P_0c07c5c2;
case 0x0c07c5c4u: goto P_0c07c5c4;
case 0x0c07c5c6u: goto P_0c07c5c6;
case 0x0c07c5c8u: goto P_0c07c5c8;
case 0x0c07c5cau: goto P_0c07c5ca;
case 0x0c07c5ccu: goto P_0c07c5cc;
case 0x0c07c5ceu: goto P_0c07c5ce;
case 0x0c07c5d0u: goto P_0c07c5d0;
case 0x0c07c5d2u: goto P_0c07c5d2;
case 0x0c07c5d4u: goto P_0c07c5d4;
case 0x0c07c5d6u: goto P_0c07c5d6;
case 0x0c07c5d8u: goto P_0c07c5d8;
case 0x0c07c5dau: goto P_0c07c5da;
case 0x0c07c5dcu: goto P_0c07c5dc;
case 0x0c07c5deu: goto P_0c07c5de;
case 0x0c07c5e0u: goto P_0c07c5e0;
case 0x0c07c5e2u: goto P_0c07c5e2;
case 0x0c07c5e4u: goto P_0c07c5e4;
case 0x0c07c5e6u: goto P_0c07c5e6;
case 0x0c08c80eu: goto P_0c08c80e;
case 0x0c08c810u: goto P_0c08c810;
case 0x0c08c812u: goto P_0c08c812;
case 0x0c08c814u: goto P_0c08c814;
case 0x0c08c816u: goto P_0c08c816;
case 0x0c08c818u: goto P_0c08c818;
case 0x0c08c81au: goto P_0c08c81a;
case 0x0c08c81cu: goto P_0c08c81c;
case 0x0c08c81eu: goto P_0c08c81e;
case 0x0c08c820u: goto P_0c08c820;
case 0x0c08c822u: goto P_0c08c822;
case 0x0c08c824u: goto P_0c08c824;
case 0x0c08c826u: goto P_0c08c826;
case 0x0c08c828u: goto P_0c08c828;
case 0x0c08c82eu: goto P_0c08c82e;
case 0x0c08c830u: goto P_0c08c830;
case 0x0c08c832u: goto P_0c08c832;
case 0x0c08c834u: goto P_0c08c834;
case 0x0c08c836u: goto P_0c08c836;
case 0x0c08c838u: goto P_0c08c838;
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
case 0x0c08c990u: goto P_0c08c990;
case 0x0c08c992u: goto P_0c08c992;
case 0x0c08c994u: goto P_0c08c994;
case 0x0c08c996u: goto P_0c08c996;
case 0x0c08c998u: goto P_0c08c998;
case 0x0c08c99au: goto P_0c08c99a;
case 0x0c08c99cu: goto P_0c08c99c;
case 0x0c08c99eu: goto P_0c08c99e;
case 0x0c08c9a0u: goto P_0c08c9a0;
case 0x0c08c9a2u: goto P_0c08c9a2;
case 0x0c08c9a4u: goto P_0c08c9a4;
case 0x0c08c9a6u: goto P_0c08c9a6;
case 0x0c08c9a8u: goto P_0c08c9a8;
case 0x0c08c9aau: goto P_0c08c9aa;
case 0x0c08c9acu: goto P_0c08c9ac;
case 0x0c08c9aeu: goto P_0c08c9ae;
case 0x0c08c9b0u: goto P_0c08c9b0;
case 0x0c08c9b2u: goto P_0c08c9b2;
case 0x0c08c9b4u: goto P_0c08c9b4;
case 0x0c08c9b6u: goto P_0c08c9b6;
case 0x0c08c9b8u: goto P_0c08c9b8;
case 0x0c08c9bau: goto P_0c08c9ba;
case 0x0c08c9bcu: goto P_0c08c9bc;
case 0x0c08c9beu: goto P_0c08c9be;
case 0x0c08c9c0u: goto P_0c08c9c0;
case 0x0c08c9c2u: goto P_0c08c9c2;
case 0x0c08c9c4u: goto P_0c08c9c4;
case 0x0c08c9c6u: goto P_0c08c9c6;
case 0x0c08c9c8u: goto P_0c08c9c8;
case 0x0c08c9cau: goto P_0c08c9ca;
case 0x0c08c9ccu: goto P_0c08c9cc;
case 0x0c08c9ceu: goto P_0c08c9ce;
case 0x0c08c9d0u: goto P_0c08c9d0;
case 0x0c08c9d2u: goto P_0c08c9d2;
case 0x0c08c9d4u: goto P_0c08c9d4;
case 0x0c08c9d6u: goto P_0c08c9d6;
case 0x0c08c9d8u: goto P_0c08c9d8;
case 0x0c08c9dau: goto P_0c08c9da;
case 0x0c08c9dcu: goto P_0c08c9dc;
case 0x0c08c9deu: goto P_0c08c9de;
case 0x0c08c9e0u: goto P_0c08c9e0;
case 0x0c08c9e2u: goto P_0c08c9e2;
case 0x0c08c9e4u: goto P_0c08c9e4;
case 0x0c08c9e6u: goto P_0c08c9e6;
case 0x0c08c9e8u: goto P_0c08c9e8;
case 0x0c08c9eau: goto P_0c08c9ea;
case 0x0c08c9ecu: goto P_0c08c9ec;
case 0x0c08c9eeu: goto P_0c08c9ee;
case 0x0c08c9f0u: goto P_0c08c9f0;
case 0x0c08c9f2u: goto P_0c08c9f2;
case 0x0c08c9f4u: goto P_0c08c9f4;
case 0x0c08c9f6u: goto P_0c08c9f6;
case 0x0c08c9f8u: goto P_0c08c9f8;
case 0x0c08c9fau: goto P_0c08c9fa;
case 0x0c08c9fcu: goto P_0c08c9fc;
case 0x0c08c9feu: goto P_0c08c9fe;
case 0x0c08ca00u: goto P_0c08ca00;
case 0x0c08ca02u: goto P_0c08ca02;
case 0x0c08ca04u: goto P_0c08ca04;
case 0x0c08ca06u: goto P_0c08ca06;
case 0x0c08ca08u: goto P_0c08ca08;
case 0x0c08ca0au: goto P_0c08ca0a;
case 0x0c08ca0cu: goto P_0c08ca0c;
case 0x0c08ca0eu: goto P_0c08ca0e;
case 0x0c08ca10u: goto P_0c08ca10;
case 0x0c08ca12u: goto P_0c08ca12;
case 0x0c08ca14u: goto P_0c08ca14;
case 0x0c08ca16u: goto P_0c08ca16;
case 0x0c08ca18u: goto P_0c08ca18;
case 0x0c08ca1au: goto P_0c08ca1a;
case 0x0c08ca1cu: goto P_0c08ca1c;
case 0x0c08ca1eu: goto P_0c08ca1e;
case 0x0c08ca20u: goto P_0c08ca20;
case 0x0c08ca22u: goto P_0c08ca22;
case 0x0c08ca24u: goto P_0c08ca24;
case 0x0c08ca26u: goto P_0c08ca26;
case 0x0c08ca28u: goto P_0c08ca28;
case 0x0c08ca2au: goto P_0c08ca2a;
case 0x0c08ca2cu: goto P_0c08ca2c;
case 0x0c08ca54u: goto P_0c08ca54;
case 0x0c08ca56u: goto P_0c08ca56;
case 0x0c08ca58u: goto P_0c08ca58;
case 0x0c08ca5au: goto P_0c08ca5a;
case 0x0c08ca5cu: goto P_0c08ca5c;
case 0x0c08ca5eu: goto P_0c08ca5e;
case 0x0c08ca60u: goto P_0c08ca60;
case 0x0c08ca62u: goto P_0c08ca62;
case 0x0c08ca64u: goto P_0c08ca64;
case 0x0c08ca66u: goto P_0c08ca66;
case 0x0c08ca68u: goto P_0c08ca68;
case 0x0c08ca6au: goto P_0c08ca6a;
case 0x0c08ca6cu: goto P_0c08ca6c;
case 0x0c08ca6eu: goto P_0c08ca6e;
case 0x0c08ca70u: goto P_0c08ca70;
case 0x0c08ca72u: goto P_0c08ca72;
case 0x0c08ca74u: goto P_0c08ca74;
case 0x0c08ca76u: goto P_0c08ca76;
case 0x0c08ca78u: goto P_0c08ca78;
case 0x0c08ca7au: goto P_0c08ca7a;
case 0x0c08ca7cu: goto P_0c08ca7c;
case 0x0c08ca7eu: goto P_0c08ca7e;
case 0x0c08ca80u: goto P_0c08ca80;
case 0x0c08ca82u: goto P_0c08ca82;
case 0x0c08ca84u: goto P_0c08ca84;
case 0x0c08ca86u: goto P_0c08ca86;
case 0x0c08ca88u: goto P_0c08ca88;
case 0x0c08ca8au: goto P_0c08ca8a;
case 0x0c08ca8cu: goto P_0c08ca8c;
case 0x0c08ca8eu: goto P_0c08ca8e;
case 0x0c08ca90u: goto P_0c08ca90;
case 0x0c08ca92u: goto P_0c08ca92;
case 0x0c08ca94u: goto P_0c08ca94;
case 0x0c08ca96u: goto P_0c08ca96;
case 0x0c08ca98u: goto P_0c08ca98;
case 0x0c08ca9au: goto P_0c08ca9a;
case 0x0c08ca9cu: goto P_0c08ca9c;
case 0x0c08ca9eu: goto P_0c08ca9e;
case 0x0c08caa0u: goto P_0c08caa0;
case 0x0c08caa2u: goto P_0c08caa2;
case 0x0c08caa4u: goto P_0c08caa4;
case 0x0c08caa6u: goto P_0c08caa6;
case 0x0c08caa8u: goto P_0c08caa8;
case 0x0c08caaau: goto P_0c08caaa;
case 0x0c08caacu: goto P_0c08caac;
case 0x0c08caaeu: goto P_0c08caae;
case 0x0c08cab0u: goto P_0c08cab0;
case 0x0c08cab2u: goto P_0c08cab2;
case 0x0c08cab4u: goto P_0c08cab4;
case 0x0c08cab6u: goto P_0c08cab6;
case 0x0c08cab8u: goto P_0c08cab8;
case 0x0c08cabau: goto P_0c08caba;
case 0x0c08cabcu: goto P_0c08cabc;
case 0x0c08cabeu: goto P_0c08cabe;
case 0x0c08cac0u: goto P_0c08cac0;
case 0x0c08cac2u: goto P_0c08cac2;
case 0x0c08cac4u: goto P_0c08cac4;
case 0x0c08cac6u: goto P_0c08cac6;
case 0x0c08cac8u: goto P_0c08cac8;
case 0x0c08cacau: goto P_0c08caca;
case 0x0c08caccu: goto P_0c08cacc;
case 0x0c08caceu: goto P_0c08cace;
case 0x0c08cad0u: goto P_0c08cad0;
case 0x0c08cad2u: goto P_0c08cad2;
case 0x0c09635au: goto P_0c09635a;
case 0x0c09635cu: goto P_0c09635c;
case 0x0c09635eu: goto P_0c09635e;
case 0x0c096360u: goto P_0c096360;
case 0x0c096362u: goto P_0c096362;
case 0x0c096364u: goto P_0c096364;
case 0x0c096366u: goto P_0c096366;
case 0x0c096368u: goto P_0c096368;
case 0x0c09636au: goto P_0c09636a;
case 0x0c09636cu: goto P_0c09636c;
case 0x0c09636eu: goto P_0c09636e;
case 0x0c096370u: goto P_0c096370;
case 0x0c096372u: goto P_0c096372;
case 0x0c096374u: goto P_0c096374;
case 0x0c096376u: goto P_0c096376;
case 0x0c096378u: goto P_0c096378;
case 0x0c09637au: goto P_0c09637a;
case 0x0c09637cu: goto P_0c09637c;
case 0x0c09637eu: goto P_0c09637e;
case 0x0c096380u: goto P_0c096380;
case 0x0c096382u: goto P_0c096382;
case 0x0c096384u: goto P_0c096384;
case 0x0c096386u: goto P_0c096386;
case 0x0c096388u: goto P_0c096388;
case 0x0c09638au: goto P_0c09638a;
case 0x0c09638cu: goto P_0c09638c;
case 0x0c09638eu: goto P_0c09638e;
case 0x0c096390u: goto P_0c096390;
case 0x0c096392u: goto P_0c096392;
case 0x0c096394u: goto P_0c096394;
case 0x0c096396u: goto P_0c096396;
case 0x0c096398u: goto P_0c096398;
case 0x0c09639au: goto P_0c09639a;
case 0x0c09639cu: goto P_0c09639c;
case 0x0c09639eu: goto P_0c09639e;
case 0x0c0963a0u: goto P_0c0963a0;
case 0x0c0963a2u: goto P_0c0963a2;
case 0x0c0963a4u: goto P_0c0963a4;
case 0x0c0963a6u: goto P_0c0963a6;
case 0x0c0963a8u: goto P_0c0963a8;
case 0x0c0963aau: goto P_0c0963aa;
case 0x0c0963d0u: goto P_0c0963d0;
case 0x0c0963d2u: goto P_0c0963d2;
case 0x0c0963d4u: goto P_0c0963d4;
case 0x0c0963d6u: goto P_0c0963d6;
case 0x0c0963d8u: goto P_0c0963d8;
case 0x0c0963dau: goto P_0c0963da;
case 0x0c0963dcu: goto P_0c0963dc;
case 0x0c0963deu: goto P_0c0963de;
case 0x0c0963e0u: goto P_0c0963e0;
case 0x0c0963e2u: goto P_0c0963e2;
case 0x0c0963e4u: goto P_0c0963e4;
case 0x0c0963e6u: goto P_0c0963e6;
case 0x0c0963e8u: goto P_0c0963e8;
case 0x0c0963eau: goto P_0c0963ea;
case 0x0c0963ecu: goto P_0c0963ec;
case 0x0c0963eeu: goto P_0c0963ee;
case 0x0c0963f0u: goto P_0c0963f0;
case 0x0c0963f2u: goto P_0c0963f2;
case 0x0c0963f4u: goto P_0c0963f4;
case 0x0c0963f6u: goto P_0c0963f6;
case 0x0c0963f8u: goto P_0c0963f8;
case 0x0c0963fau: goto P_0c0963fa;
case 0x0c0963fcu: goto P_0c0963fc;
case 0x0c0963feu: goto P_0c0963fe;
case 0x0c096400u: goto P_0c096400;
case 0x0c096402u: goto P_0c096402;
case 0x0c096404u: goto P_0c096404;
case 0x0c096406u: goto P_0c096406;
case 0x0c096408u: goto P_0c096408;
case 0x0c09640au: goto P_0c09640a;
case 0x0c09640cu: goto P_0c09640c;
case 0x0c09640eu: goto P_0c09640e;
case 0x0c096410u: goto P_0c096410;
case 0x0c096412u: goto P_0c096412;
case 0x0c096414u: goto P_0c096414;
case 0x0c096416u: goto P_0c096416;
case 0x0c096418u: goto P_0c096418;
case 0x0c09641au: goto P_0c09641a;
case 0x0c09641cu: goto P_0c09641c;
case 0x0c09641eu: goto P_0c09641e;
case 0x0c096420u: goto P_0c096420;
case 0x0c096422u: goto P_0c096422;
case 0x0c096424u: goto P_0c096424;
case 0x0c096426u: goto P_0c096426;
case 0x0c096428u: goto P_0c096428;
case 0x0c09642au: goto P_0c09642a;
case 0x0c09642cu: goto P_0c09642c;
case 0x0c09642eu: goto P_0c09642e;
case 0x0c096430u: goto P_0c096430;
case 0x0c096432u: goto P_0c096432;
case 0x0c096434u: goto P_0c096434;
case 0x0c096436u: goto P_0c096436;
case 0x0c096438u: goto P_0c096438;
case 0x0c09643au: goto P_0c09643a;
case 0x0c09643cu: goto P_0c09643c;
case 0x0c09643eu: goto P_0c09643e;
case 0x0c096440u: goto P_0c096440;
case 0x0c096442u: goto P_0c096442;
case 0x0c096444u: goto P_0c096444;
case 0x0c096446u: goto P_0c096446;
case 0x0c096448u: goto P_0c096448;
case 0x0c09644au: goto P_0c09644a;
case 0x0c09644cu: goto P_0c09644c;
case 0x0c09644eu: goto P_0c09644e;
case 0x0c096450u: goto P_0c096450;
case 0x0c096452u: goto P_0c096452;
case 0x0c096454u: goto P_0c096454;
case 0x0c096456u: goto P_0c096456;
case 0x0c096458u: goto P_0c096458;
case 0x0c09645au: goto P_0c09645a;
case 0x0c09645cu: goto P_0c09645c;
case 0x0c09645eu: goto P_0c09645e;
case 0x0c096460u: goto P_0c096460;
case 0x0c096462u: goto P_0c096462;
case 0x0c096464u: goto P_0c096464;
case 0x0c096466u: goto P_0c096466;
case 0x0c096468u: goto P_0c096468;
case 0x0c09646au: goto P_0c09646a;
case 0x0c09646cu: goto P_0c09646c;
case 0x0c09646eu: goto P_0c09646e;
case 0x0c096470u: goto P_0c096470;
case 0x0c096472u: goto P_0c096472;
case 0x0c096474u: goto P_0c096474;
case 0x0c096476u: goto P_0c096476;
case 0x0c096478u: goto P_0c096478;
case 0x0c09647au: goto P_0c09647a;
case 0x0c09647cu: goto P_0c09647c;
case 0x0c09647eu: goto P_0c09647e;
case 0x0c096480u: goto P_0c096480;
case 0x0c096482u: goto P_0c096482;
case 0x0c096484u: goto P_0c096484;
case 0x0c096486u: goto P_0c096486;
case 0x0c096488u: goto P_0c096488;
case 0x0c09648au: goto P_0c09648a;
case 0x0c09648cu: goto P_0c09648c;
case 0x0c09648eu: goto P_0c09648e;
case 0x0c096490u: goto P_0c096490;
case 0x0c096492u: goto P_0c096492;
case 0x0c096494u: goto P_0c096494;
case 0x0c096496u: goto P_0c096496;
case 0x0c096498u: goto P_0c096498;
case 0x0c09649au: goto P_0c09649a;
case 0x0c09649cu: goto P_0c09649c;
case 0x0c09649eu: goto P_0c09649e;
case 0x0c0964a0u: goto P_0c0964a0;
case 0x0c0964a2u: goto P_0c0964a2;
case 0x0c0964a4u: goto P_0c0964a4;
case 0x0c0964a6u: goto P_0c0964a6;
case 0x0c0964a8u: goto P_0c0964a8;
case 0x0c0964aau: goto P_0c0964aa;
case 0x0c0964acu: goto P_0c0964ac;
case 0x0c0964aeu: goto P_0c0964ae;
case 0x0c0964b0u: goto P_0c0964b0;
case 0x0c0964b2u: goto P_0c0964b2;
case 0x0c0964b4u: goto P_0c0964b4;
case 0x0c0964b6u: goto P_0c0964b6;
case 0x0c0964b8u: goto P_0c0964b8;
case 0x0c0964bau: goto P_0c0964ba;
case 0x0c0964bcu: goto P_0c0964bc;
case 0x0c0964beu: goto P_0c0964be;
case 0x0c0964c0u: goto P_0c0964c0;
case 0x0c0964c2u: goto P_0c0964c2;
case 0x0c09650cu: goto P_0c09650c;
case 0x0c09650eu: goto P_0c09650e;
case 0x0c096510u: goto P_0c096510;
case 0x0c096512u: goto P_0c096512;
case 0x0c096514u: goto P_0c096514;
case 0x0c096516u: goto P_0c096516;
case 0x0c096518u: goto P_0c096518;
case 0x0c09651au: goto P_0c09651a;
case 0x0c09651cu: goto P_0c09651c;
case 0x0c09651eu: goto P_0c09651e;
case 0x0c096520u: goto P_0c096520;
case 0x0c096522u: goto P_0c096522;
case 0x0c096524u: goto P_0c096524;
case 0x0c096526u: goto P_0c096526;
case 0x0c096528u: goto P_0c096528;
case 0x0c09652au: goto P_0c09652a;
case 0x0c09652cu: goto P_0c09652c;
case 0x0c09652eu: goto P_0c09652e;
case 0x0c096530u: goto P_0c096530;
case 0x0c096532u: goto P_0c096532;
case 0x0c096534u: goto P_0c096534;
case 0x0c096536u: goto P_0c096536;
case 0x0c096538u: goto P_0c096538;
case 0x0c09653au: goto P_0c09653a;
case 0x0c09653cu: goto P_0c09653c;
case 0x0c09653eu: goto P_0c09653e;
case 0x0c096540u: goto P_0c096540;
case 0x0c096542u: goto P_0c096542;
case 0x0c096544u: goto P_0c096544;
case 0x0c096546u: goto P_0c096546;
case 0x0c096548u: goto P_0c096548;
case 0x0c09654au: goto P_0c09654a;
case 0x0c09654cu: goto P_0c09654c;
case 0x0c09654eu: goto P_0c09654e;
case 0x0c096550u: goto P_0c096550;
case 0x0c096552u: goto P_0c096552;
case 0x0c096554u: goto P_0c096554;
case 0x0c096556u: goto P_0c096556;
case 0x0c096558u: goto P_0c096558;
case 0x0c09655au: goto P_0c09655a;
case 0x0c09655cu: goto P_0c09655c;
case 0x0c09655eu: goto P_0c09655e;
case 0x0c096560u: goto P_0c096560;
case 0x0c096562u: goto P_0c096562;
case 0x0c096564u: goto P_0c096564;
case 0x0c096566u: goto P_0c096566;
case 0x0c096568u: goto P_0c096568;
case 0x0c09656au: goto P_0c09656a;
case 0x0c09656cu: goto P_0c09656c;
case 0x0c09656eu: goto P_0c09656e;
case 0x0c096570u: goto P_0c096570;
case 0x0c096572u: goto P_0c096572;
case 0x0c096574u: goto P_0c096574;
case 0x0c096576u: goto P_0c096576;
case 0x0c096578u: goto P_0c096578;
case 0x0c09657au: goto P_0c09657a;
case 0x0c09657cu: goto P_0c09657c;
case 0x0c09657eu: goto P_0c09657e;
case 0x0c096580u: goto P_0c096580;
case 0x0c096582u: goto P_0c096582;
case 0x0c096584u: goto P_0c096584;
case 0x0c096586u: goto P_0c096586;
case 0x0c096588u: goto P_0c096588;
case 0x0c09658au: goto P_0c09658a;
case 0x0c09658cu: goto P_0c09658c;
case 0x0c09658eu: goto P_0c09658e;
case 0x0c096590u: goto P_0c096590;
case 0x0c096592u: goto P_0c096592;
case 0x0c096594u: goto P_0c096594;
case 0x0c096596u: goto P_0c096596;
case 0x0c096598u: goto P_0c096598;
case 0x0c09659au: goto P_0c09659a;
case 0x0c09659cu: goto P_0c09659c;
case 0x0c09659eu: goto P_0c09659e;
case 0x0c0965a0u: goto P_0c0965a0;
case 0x0c0965a2u: goto P_0c0965a2;
case 0x0c0965a4u: goto P_0c0965a4;
case 0x0c0965a6u: goto P_0c0965a6;
case 0x0c0965a8u: goto P_0c0965a8;
case 0x0c0965aau: goto P_0c0965aa;
case 0x0c0965acu: goto P_0c0965ac;
case 0x0c0965aeu: goto P_0c0965ae;
case 0x0c0965b0u: goto P_0c0965b0;
case 0x0c0965b2u: goto P_0c0965b2;
case 0x0c0965b4u: goto P_0c0965b4;
case 0x0c0965b6u: goto P_0c0965b6;
case 0x0c0965b8u: goto P_0c0965b8;
case 0x0c0965bau: goto P_0c0965ba;
case 0x0c0965bcu: goto P_0c0965bc;
case 0x0c0965beu: goto P_0c0965be;
case 0x0c0965c0u: goto P_0c0965c0;
case 0x0c0965c2u: goto P_0c0965c2;
case 0x0c0965c4u: goto P_0c0965c4;
case 0x0c0965c6u: goto P_0c0965c6;
case 0x0c0965c8u: goto P_0c0965c8;
case 0x0c0965cau: goto P_0c0965ca;
case 0x0c0965ccu: goto P_0c0965cc;
case 0x0c0965ecu: goto P_0c0965ec;
case 0x0c0965eeu: goto P_0c0965ee;
case 0x0c0965f0u: goto P_0c0965f0;
case 0x0c0965f2u: goto P_0c0965f2;
case 0x0c0965f4u: goto P_0c0965f4;
case 0x0c0965f6u: goto P_0c0965f6;
case 0x0c0965f8u: goto P_0c0965f8;
case 0x0c0965fau: goto P_0c0965fa;
case 0x0c0965fcu: goto P_0c0965fc;
case 0x0c0965feu: goto P_0c0965fe;
case 0x0c096600u: goto P_0c096600;
case 0x0c096602u: goto P_0c096602;
case 0x0c096604u: goto P_0c096604;
case 0x0c096606u: goto P_0c096606;
case 0x0c096608u: goto P_0c096608;
case 0x0c09660au: goto P_0c09660a;
case 0x0c09660cu: goto P_0c09660c;
case 0x0c09660eu: goto P_0c09660e;
case 0x0c096610u: goto P_0c096610;
case 0x0c096612u: goto P_0c096612;
case 0x0c096614u: goto P_0c096614;
case 0x0c096616u: goto P_0c096616;
case 0x0c096618u: goto P_0c096618;
case 0x0c09661au: goto P_0c09661a;
case 0x0c09661cu: goto P_0c09661c;
case 0x0c09661eu: goto P_0c09661e;
case 0x0c096620u: goto P_0c096620;
case 0x0c096622u: goto P_0c096622;
case 0x0c096624u: goto P_0c096624;
case 0x0c096626u: goto P_0c096626;
case 0x0c096628u: goto P_0c096628;
case 0x0c09662au: goto P_0c09662a;
case 0x0c09662cu: goto P_0c09662c;
case 0x0c09662eu: goto P_0c09662e;
case 0x0c096630u: goto P_0c096630;
case 0x0c096632u: goto P_0c096632;
case 0x0c096634u: goto P_0c096634;
case 0x0c096636u: goto P_0c096636;
case 0x0c096638u: goto P_0c096638;
case 0x0c09663au: goto P_0c09663a;
case 0x0c09663cu: goto P_0c09663c;
case 0x0c09663eu: goto P_0c09663e;
case 0x0c096640u: goto P_0c096640;
case 0x0c096642u: goto P_0c096642;
case 0x0c096644u: goto P_0c096644;
case 0x0c096646u: goto P_0c096646;
case 0x0c096648u: goto P_0c096648;
case 0x0c09664au: goto P_0c09664a;
case 0x0c0a2e2cu: goto P_0c0a2e2c;
case 0x0c0a2e2eu: goto P_0c0a2e2e;
case 0x0c0a2e30u: goto P_0c0a2e30;
case 0x0c0a2e32u: goto P_0c0a2e32;
case 0x0c0a2e34u: goto P_0c0a2e34;
case 0x0c0a2e36u: goto P_0c0a2e36;
case 0x0c0a2e38u: goto P_0c0a2e38;
case 0x0c0a2e3au: goto P_0c0a2e3a;
case 0x0c0a2e3cu: goto P_0c0a2e3c;
case 0x0c0a2e3eu: goto P_0c0a2e3e;
case 0x0c0a2e40u: goto P_0c0a2e40;
case 0x0c0a2e42u: goto P_0c0a2e42;
case 0x0c0a2e44u: goto P_0c0a2e44;
case 0x0c0a2e46u: goto P_0c0a2e46;
case 0x0c0a30b4u: goto P_0c0a30b4;
case 0x0c0a30b6u: goto P_0c0a30b6;
case 0x0c0a30b8u: goto P_0c0a30b8;
case 0x0c0a30bau: goto P_0c0a30ba;
case 0x0c0a30bcu: goto P_0c0a30bc;
case 0x0c0a30beu: goto P_0c0a30be;
case 0x0c0a30c0u: goto P_0c0a30c0;
case 0x0c0a30c2u: goto P_0c0a30c2;
case 0x0c0a30c4u: goto P_0c0a30c4;
case 0x0c0a30c6u: goto P_0c0a30c6;
case 0x0c0a30c8u: goto P_0c0a30c8;
case 0x0c0a30cau: goto P_0c0a30ca;
case 0x0c0a30ccu: goto P_0c0a30cc;
case 0x0c0a30ceu: goto P_0c0a30ce;
case 0x0c0a30d0u: goto P_0c0a30d0;
case 0x0c0a30d2u: goto P_0c0a30d2;
case 0x0c0a30d4u: goto P_0c0a30d4;
case 0x0c0a30d6u: goto P_0c0a30d6;
case 0x0c0a30d8u: goto P_0c0a30d8;
case 0x0c0a30dau: goto P_0c0a30da;
case 0x0c0a30dcu: goto P_0c0a30dc;
case 0x0c0a30deu: goto P_0c0a30de;
case 0x0c0a30e0u: goto P_0c0a30e0;
case 0x0c0a30e2u: goto P_0c0a30e2;
case 0x0c0a30e4u: goto P_0c0a30e4;
case 0x0c0a30e6u: goto P_0c0a30e6;
case 0x0c0a30e8u: goto P_0c0a30e8;
case 0x0c0a30eau: goto P_0c0a30ea;
case 0x0c0a30ecu: goto P_0c0a30ec;
case 0x0c0a30eeu: goto P_0c0a30ee;
case 0x0c0a30f0u: goto P_0c0a30f0;
case 0x0c0a30f2u: goto P_0c0a30f2;
case 0x0c0a30f4u: goto P_0c0a30f4;
case 0x0c0a30f6u: goto P_0c0a30f6;
case 0x0c0a30f8u: goto P_0c0a30f8;
case 0x0c0a30fau: goto P_0c0a30fa;
case 0x0c0a30fcu: goto P_0c0a30fc;
case 0x0c0a30feu: goto P_0c0a30fe;
case 0x0c0a3100u: goto P_0c0a3100;
case 0x0c0a3102u: goto P_0c0a3102;
case 0x0c0a3104u: goto P_0c0a3104;
case 0x0c0a3106u: goto P_0c0a3106;
case 0x0c0a3108u: goto P_0c0a3108;
case 0x0c0a310au: goto P_0c0a310a;
case 0x0c0a310cu: goto P_0c0a310c;
case 0x0c0a310eu: goto P_0c0a310e;
case 0x0c0a3110u: goto P_0c0a3110;
case 0x0c0a3112u: goto P_0c0a3112;
case 0x0c0a3114u: goto P_0c0a3114;
case 0x0c0a3116u: goto P_0c0a3116;
case 0x0c0a3118u: goto P_0c0a3118;
case 0x0c0a311au: goto P_0c0a311a;
case 0x0c0a311cu: goto P_0c0a311c;
case 0x0c0a311eu: goto P_0c0a311e;
case 0x0c0a3120u: goto P_0c0a3120;
case 0x0c0a3122u: goto P_0c0a3122;
case 0x0c0a3124u: goto P_0c0a3124;
case 0x0c0a3126u: goto P_0c0a3126;
case 0x0c0a3128u: goto P_0c0a3128;
case 0x0c0a312au: goto P_0c0a312a;
case 0x0c0a312cu: goto P_0c0a312c;
case 0x0c0a312eu: goto P_0c0a312e;
case 0x0c0a3130u: goto P_0c0a3130;
case 0x0c0a3132u: goto P_0c0a3132;
case 0x0c0a3134u: goto P_0c0a3134;
case 0x0c0a3136u: goto P_0c0a3136;
case 0x0c0a3138u: goto P_0c0a3138;
case 0x0c0a313au: goto P_0c0a313a;
case 0x0c0a313cu: goto P_0c0a313c;
case 0x0c0a313eu: goto P_0c0a313e;
case 0x0c0a3140u: goto P_0c0a3140;
case 0x0c0a3142u: goto P_0c0a3142;
case 0x0c0a3144u: goto P_0c0a3144;
case 0x0c0a3146u: goto P_0c0a3146;
case 0x0c0a3148u: goto P_0c0a3148;
case 0x0c0a314au: goto P_0c0a314a;
case 0x0c0a314cu: goto P_0c0a314c;
case 0x0c0a314eu: goto P_0c0a314e;
case 0x0c0a3150u: goto P_0c0a3150;
case 0x0c0a3152u: goto P_0c0a3152;
case 0x0c0a3154u: goto P_0c0a3154;
case 0x0c0a3156u: goto P_0c0a3156;
case 0x0c0a3158u: goto P_0c0a3158;
case 0x0c0a315au: goto P_0c0a315a;
case 0x0c0a315cu: goto P_0c0a315c;
case 0x0c0a315eu: goto P_0c0a315e;
case 0x0c0a3160u: goto P_0c0a3160;
case 0x0c0a3162u: goto P_0c0a3162;
case 0x0c0a3164u: goto P_0c0a3164;
case 0x0c0a3166u: goto P_0c0a3166;
case 0x0c0a3168u: goto P_0c0a3168;
case 0x0c0a316au: goto P_0c0a316a;
case 0x0c0a316cu: goto P_0c0a316c;
case 0x0c0a316eu: goto P_0c0a316e;
case 0x0c0a3170u: goto P_0c0a3170;
case 0x0c0a3172u: goto P_0c0a3172;
case 0x0c0a3174u: goto P_0c0a3174;
case 0x0c0a3176u: goto P_0c0a3176;
case 0x0c0a3178u: goto P_0c0a3178;
case 0x0c0a317au: goto P_0c0a317a;
case 0x0c0a317cu: goto P_0c0a317c;
case 0x0c0a317eu: goto P_0c0a317e;
case 0x0c0a3180u: goto P_0c0a3180;
case 0x0c0a3182u: goto P_0c0a3182;
case 0x0c0a3184u: goto P_0c0a3184;
case 0x0c0a3186u: goto P_0c0a3186;
case 0x0c0a3188u: goto P_0c0a3188;
case 0x0c0a318au: goto P_0c0a318a;
case 0x0c0a318cu: goto P_0c0a318c;
case 0x0c0a318eu: goto P_0c0a318e;
case 0x0c0a3190u: goto P_0c0a3190;
case 0x0c0a3192u: goto P_0c0a3192;
case 0x0c0a3194u: goto P_0c0a3194;
case 0x0c0a3196u: goto P_0c0a3196;
case 0x0c0a3198u: goto P_0c0a3198;
case 0x0c0a319au: goto P_0c0a319a;
case 0x0c0a319cu: goto P_0c0a319c;
case 0x0c0a319eu: goto P_0c0a319e;
case 0x0c0a31a0u: goto P_0c0a31a0;
case 0x0c0a31a2u: goto P_0c0a31a2;
case 0x0c0a31a4u: goto P_0c0a31a4;
case 0x0c0a31a6u: goto P_0c0a31a6;
case 0x0c0a31a8u: goto P_0c0a31a8;
case 0x0c0a31aau: goto P_0c0a31aa;
case 0x0c0a31acu: goto P_0c0a31ac;
case 0x0c0a31aeu: goto P_0c0a31ae;
case 0x0c0a31b0u: goto P_0c0a31b0;
case 0x0c0a31b2u: goto P_0c0a31b2;
case 0x0c0a31b4u: goto P_0c0a31b4;
case 0x0c0a31b6u: goto P_0c0a31b6;
case 0x0c0a31b8u: goto P_0c0a31b8;
case 0x0c0a31bau: goto P_0c0a31ba;
case 0x0c0a31bcu: goto P_0c0a31bc;
case 0x0c0a31beu: goto P_0c0a31be;
case 0x0c0a31c0u: goto P_0c0a31c0;
case 0x0c0a31c2u: goto P_0c0a31c2;
case 0x0c0a31c4u: goto P_0c0a31c4;
case 0x0c0a31c6u: goto P_0c0a31c6;
case 0x0c0a31c8u: goto P_0c0a31c8;
case 0x0c0a3226u: goto P_0c0a3226;
case 0x0c0a3228u: goto P_0c0a3228;
case 0x0c0a322au: goto P_0c0a322a;
case 0x0c0a322cu: goto P_0c0a322c;
case 0x0c0a322eu: goto P_0c0a322e;
case 0x0c0a3230u: goto P_0c0a3230;
case 0x0c0a3232u: goto P_0c0a3232;
case 0x0c0a3234u: goto P_0c0a3234;
case 0x0c0a3236u: goto P_0c0a3236;
case 0x0c0a3238u: goto P_0c0a3238;
case 0x0c0a323au: goto P_0c0a323a;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
case 0x0c0cc2d6u: goto P_0c0cc2d6;
case 0x0c0cc2d8u: goto P_0c0cc2d8;
case 0x0c0cc2dau: goto P_0c0cc2da;
case 0x0c0cc2dcu: goto P_0c0cc2dc;
case 0x0c0cc2deu: goto P_0c0cc2de;
case 0x0c0cc2e0u: goto P_0c0cc2e0;
case 0x0c0cc2e2u: goto P_0c0cc2e2;
case 0x0c0cc2e4u: goto P_0c0cc2e4;
case 0x0c0cc2e6u: goto P_0c0cc2e6;
case 0x0c0cc2e8u: goto P_0c0cc2e8;
case 0x0c0cc2eau: goto P_0c0cc2ea;
case 0x0c0cc2ecu: goto P_0c0cc2ec;
case 0x0c0cc2eeu: goto P_0c0cc2ee;
case 0x0c0cc2f0u: goto P_0c0cc2f0;
case 0x0c0cc2f2u: goto P_0c0cc2f2;
case 0x0c0cc2f4u: goto P_0c0cc2f4;
case 0x0c0cc2f6u: goto P_0c0cc2f6;
case 0x0c0cc2f8u: goto P_0c0cc2f8;
case 0x0c0cc2fau: goto P_0c0cc2fa;
case 0x0c0cc2fcu: goto P_0c0cc2fc;
case 0x0c0cc2feu: goto P_0c0cc2fe;
case 0x0c0cc300u: goto P_0c0cc300;
case 0x0c0cc302u: goto P_0c0cc302;
case 0x0c0cc304u: goto P_0c0cc304;
case 0x0c0cc306u: goto P_0c0cc306;
case 0x0c0cc308u: goto P_0c0cc308;
case 0x0c0cc30au: goto P_0c0cc30a;
case 0x0c0cc30cu: goto P_0c0cc30c;
case 0x0c0cc30eu: goto P_0c0cc30e;
case 0x0c0cc310u: goto P_0c0cc310;
case 0x0c0cc312u: goto P_0c0cc312;
case 0x0c0cc314u: goto P_0c0cc314;
case 0x0c0cc316u: goto P_0c0cc316;
case 0x0c0cc318u: goto P_0c0cc318;
case 0x0c0cc31au: goto P_0c0cc31a;
case 0x0c0cc31cu: goto P_0c0cc31c;
case 0x0c0cc31eu: goto P_0c0cc31e;
case 0x0c0cc320u: goto P_0c0cc320;
case 0x0c0cc322u: goto P_0c0cc322;
case 0x0c0cc324u: goto P_0c0cc324;
case 0x0c0cc326u: goto P_0c0cc326;
case 0x0c0cc328u: goto P_0c0cc328;
case 0x0c0cc32au: goto P_0c0cc32a;
case 0x0c0cc32cu: goto P_0c0cc32c;
case 0x0c0cc32eu: goto P_0c0cc32e;
case 0x0c0cc330u: goto P_0c0cc330;
case 0x0c0cc332u: goto P_0c0cc332;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0352da: /* original d26c, guest PC 0x0c0352da */
if(!s->budget--) { s->failed_pc=0x0c0352dau; return 0; }
r[2]=read(ram,0x0c03548cu,4);
goto P_0c0352dc;
P_0c0352dc: /* original 4f22, guest PC 0x0c0352dc */
if(!s->budget--) { s->failed_pc=0x0c0352dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0352de;
P_0c0352de: /* original 6322, guest PC 0x0c0352de */
if(!s->budget--) { s->failed_pc=0x0c0352deu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0352e0;
P_0c0352e0: /* original 5135, guest PC 0x0c0352e0 */
if(!s->budget--) { s->failed_pc=0x0c0352e0u; return 0; }
r[1]=read(ram,r[3]+20,4);
goto P_0c0352e2;
P_0c0352e2: /* original 7ff8, guest PC 0x0c0352e2 */
if(!s->budget--) { s->failed_pc=0x0c0352e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0352e4;
P_0c0352e4: /* original 5018, guest PC 0x0c0352e4 */
if(!s->budget--) { s->failed_pc=0x0c0352e4u; return 0; }
r[0]=read(ram,r[1]+32,4);
goto P_0c0352e6;
P_0c0352e6: /* original 400b, guest PC 0x0c0352e6 */
if(!s->budget--) { s->failed_pc=0x0c0352e6u; return 0; }
target=r[0];
r[16]=0x0c0352eau;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0352eau) { target=s->pc; goto dispatch; }
goto P_0c0352ea;
P_0c0352e8: /* original 64f3, guest PC 0x0c0352e8 */
if(!s->budget--) { s->failed_pc=0x0c0352e8u; return 0; }
r[4]=r[15];
goto P_0c0352ea;
P_0c0352ea: /* original 6403, guest PC 0x0c0352ea */
if(!s->budget--) { s->failed_pc=0x0c0352eau; return 0; }
r[4]=r[0];
goto P_0c0352ec;
P_0c0352ec: /* original 2448, guest PC 0x0c0352ec */
if(!s->budget--) { s->failed_pc=0x0c0352ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0352ee;
P_0c0352ee: /* original 8b03, guest PC 0x0c0352ee */
if(!s->budget--) { s->failed_pc=0x0c0352eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0352f8; }
goto P_0c0352f0;
P_0c0352f0: /* original 7f08, guest PC 0x0c0352f0 */
if(!s->budget--) { s->failed_pc=0x0c0352f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0352f2;
P_0c0352f2: /* original 4f26, guest PC 0x0c0352f2 */
if(!s->budget--) { s->failed_pc=0x0c0352f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352f4;
P_0c0352f4: /* original 000b, guest PC 0x0c0352f4 */
if(!s->budget--) { s->failed_pc=0x0c0352f4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0352f6: /* original e0ff, guest PC 0x0c0352f6 */
if(!s->budget--) { s->failed_pc=0x0c0352f6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0352f8;
P_0c0352f8: /* original 60f2, guest PC 0x0c0352f8 */
if(!s->budget--) { s->failed_pc=0x0c0352f8u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0352fa;
P_0c0352fa: /* original 7f08, guest PC 0x0c0352fa */
if(!s->budget--) { s->failed_pc=0x0c0352fau; return 0; }
r[15]+=0x00000008u;
goto P_0c0352fc;
P_0c0352fc: /* original 4f26, guest PC 0x0c0352fc */
if(!s->budget--) { s->failed_pc=0x0c0352fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352fe;
P_0c0352fe: /* original 000b, guest PC 0x0c0352fe */
if(!s->budget--) { s->failed_pc=0x0c0352feu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035300: /* original 0009, guest PC 0x0c035300 */
if(!s->budget--) { s->failed_pc=0x0c035300u; return 0; }
return vf3_matrix_family(0x0c035302u,s,ram);
P_0c0431ea: /* original 4f22, guest PC 0x0c0431ea */
if(!s->budget--) { s->failed_pc=0x0c0431eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0431ec;
P_0c0431ec: /* original 4c08, guest PC 0x0c0431ec */
if(!s->budget--) { s->failed_pc=0x0c0431ecu; return 0; }
r[12]<<=2;
goto P_0c0431ee;
P_0c0431ee: /* original 6e63, guest PC 0x0c0431ee */
if(!s->budget--) { s->failed_pc=0x0c0431eeu; return 0; }
r[14]=r[6];
goto P_0c0431f0;
P_0c0431f0: /* original 4c00, guest PC 0x0c0431f0 */
if(!s->budget--) { s->failed_pc=0x0c0431f0u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0431f2;
P_0c0431f2: /* original 8801, guest PC 0x0c0431f2 */
if(!s->budget--) { s->failed_pc=0x0c0431f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0431f4;
P_0c0431f4: /* original 7ff0, guest PC 0x0c0431f4 */
if(!s->budget--) { s->failed_pc=0x0c0431f4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0431f6;
P_0c0431f6: /* original 6df3, guest PC 0x0c0431f6 */
if(!s->budget--) { s->failed_pc=0x0c0431f6u; return 0; }
r[13]=r[15];
goto P_0c0431f8;
P_0c0431f8: /* original 2d42, guest PC 0x0c0431f8 */
if(!s->budget--) { s->failed_pc=0x0c0431f8u; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0431fa;
P_0c0431fa: /* original 1d51, guest PC 0x0c0431fa */
if(!s->budget--) { s->failed_pc=0x0c0431fau; return 0; }
write(ram,r[13]+4,r[5],4);
goto P_0c0431fc;
P_0c0431fc: /* original 64d3, guest PC 0x0c0431fc */
if(!s->budget--) { s->failed_pc=0x0c0431fcu; return 0; }
r[4]=r[13];
goto P_0c0431fe;
P_0c0431fe: /* original 1d33, guest PC 0x0c0431fe */
if(!s->budget--) { s->failed_pc=0x0c0431feu; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c043200;
P_0c043200: /* original 8f08, guest PC 0x0c043200 */
if(!s->budget--) { s->failed_pc=0x0c043200u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(!cond) { goto P_0c043214; }
goto P_0c043204;
P_0c043202: /* original 7408, guest PC 0x0c043202 */
if(!s->budget--) { s->failed_pc=0x0c043202u; return 0; }
r[4]+=0x00000008u;
goto P_0c043204;
P_0c043204: /* original 65c3, guest PC 0x0c043204 */
if(!s->budget--) { s->failed_pc=0x0c043204u; return 0; }
r[5]=r[12];
goto P_0c043206;
P_0c043206: /* original eb11, guest PC 0x0c043206 */
if(!s->budget--) { s->failed_pc=0x0c043206u; return 0; }
r[11]=0x00000011u;
goto P_0c043208;
P_0c043208: /* original 24e2, guest PC 0x0c043208 */
if(!s->budget--) { s->failed_pc=0x0c043208u; return 0; }
write(ram,r[4],r[14],4);
goto P_0c04320a;
P_0c04320a: /* original d348, guest PC 0x0c04320a */
if(!s->budget--) { s->failed_pc=0x0c04320au; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c04320c;
P_0c04320c: /* original 430b, guest PC 0x0c04320c */
if(!s->budget--) { s->failed_pc=0x0c04320cu; return 0; }
target=r[3];
r[16]=0x0c043210u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043210u) { target=s->pc; goto dispatch; }
goto P_0c043210;
P_0c04320e: /* original 64e3, guest PC 0x0c04320e */
if(!s->budget--) { s->failed_pc=0x0c04320eu; return 0; }
r[4]=r[14];
goto P_0c043210;
P_0c043210: /* original a009, guest PC 0x0c043210 */
if(!s->budget--) { s->failed_pc=0x0c043210u; return 0; }
goto P_0c043226;
P_0c043212: /* original 0009, guest PC 0x0c043212 */
if(!s->budget--) { s->failed_pc=0x0c043212u; return 0; }
goto P_0c043214;
P_0c043214: /* original 2778, guest PC 0x0c043214 */
if(!s->budget--) { s->failed_pc=0x0c043214u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c043216;
P_0c043216: /* original 8b04, guest PC 0x0c043216 */
if(!s->budget--) { s->failed_pc=0x0c043216u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043222; }
goto P_0c043218;
P_0c043218: /* original d245, guest PC 0x0c043218 */
if(!s->budget--) { s->failed_pc=0x0c043218u; return 0; }
r[2]=read(ram,0x0c043330u,4);
goto P_0c04321a;
P_0c04321a: /* original eb10, guest PC 0x0c04321a */
if(!s->budget--) { s->failed_pc=0x0c04321au; return 0; }
r[11]=0x00000010u;
goto P_0c04321c;
P_0c04321c: /* original 22eb, guest PC 0x0c04321c */
if(!s->budget--) { s->failed_pc=0x0c04321cu; return 0; }
r[2]|=r[14];
goto P_0c04321e;
P_0c04321e: /* original a002, guest PC 0x0c04321e */
if(!s->budget--) { s->failed_pc=0x0c04321eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043226;
P_0c043220: /* original 2422, guest PC 0x0c043220 */
if(!s->budget--) { s->failed_pc=0x0c043220u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c043222;
P_0c043222: /* original a01b, guest PC 0x0c043222 */
if(!s->budget--) { s->failed_pc=0x0c043222u; return 0; }
r[0]=0xffffffeeu;
goto P_0c04325c;
P_0c043224: /* original e0ee, guest PC 0x0c043224 */
if(!s->budget--) { s->failed_pc=0x0c043224u; return 0; }
r[0]=0xffffffeeu;
goto P_0c043226;
P_0c043226: /* original d243, guest PC 0x0c043226 */
if(!s->budget--) { s->failed_pc=0x0c043226u; return 0; }
r[2]=read(ram,0x0c043334u,4);
goto P_0c043228;
P_0c043228: /* original 65d3, guest PC 0x0c043228 */
if(!s->budget--) { s->failed_pc=0x0c043228u; return 0; }
r[5]=r[13];
goto P_0c04322a;
P_0c04322a: /* original 420b, guest PC 0x0c04322a */
if(!s->budget--) { s->failed_pc=0x0c04322au; return 0; }
target=r[2];
r[16]=0x0c04322eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04322eu) { target=s->pc; goto dispatch; }
goto P_0c04322e;
P_0c04322c: /* original 64b3, guest PC 0x0c04322c */
if(!s->budget--) { s->failed_pc=0x0c04322cu; return 0; }
r[4]=r[11];
goto P_0c04322e;
P_0c04322e: /* original 6d03, guest PC 0x0c04322e */
if(!s->budget--) { s->failed_pc=0x0c04322eu; return 0; }
r[13]=r[0];
goto P_0c043230;
P_0c043230: /* original 2dd8, guest PC 0x0c043230 */
if(!s->budget--) { s->failed_pc=0x0c043230u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c043232;
P_0c043232: /* original 8912, guest PC 0x0c043232 */
if(!s->budget--) { s->failed_pc=0x0c043232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043234;
P_0c043234: /* original e3e4, guest PC 0x0c043234 */
if(!s->budget--) { s->failed_pc=0x0c043234u; return 0; }
r[3]=0xffffffe4u;
goto P_0c043236;
P_0c043236: /* original 60e3, guest PC 0x0c043236 */
if(!s->budget--) { s->failed_pc=0x0c043236u; return 0; }
r[0]=r[14];
goto P_0c043238;
P_0c043238: /* original 403c, guest PC 0x0c043238 */
if(!s->budget--) { s->failed_pc=0x0c043238u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c04323a;
P_0c04323a: /* original c90f, guest PC 0x0c04323a */
if(!s->budget--) { s->failed_pc=0x0c04323au; return 0; }
r[0]&=15u;
goto P_0c04323c;
P_0c04323c: /* original 880a, guest PC 0x0c04323c */
if(!s->budget--) { s->failed_pc=0x0c04323cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c04323e;
P_0c04323e: /* original 890c, guest PC 0x0c04323e */
if(!s->budget--) { s->failed_pc=0x0c04323eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04325a; }
goto P_0c043240;
P_0c043240: /* original e31f, guest PC 0x0c043240 */
if(!s->budget--) { s->failed_pc=0x0c043240u; return 0; }
r[3]=0x0000001fu;
goto P_0c043242;
P_0c043242: /* original 23e8, guest PC 0x0c043242 */
if(!s->budget--) { s->failed_pc=0x0c043242u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c043244;
P_0c043244: /* original 8b05, guest PC 0x0c043244 */
if(!s->budget--) { s->failed_pc=0x0c043244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043252; }
goto P_0c043246;
P_0c043246: /* original d33c, guest PC 0x0c043246 */
if(!s->budget--) { s->failed_pc=0x0c043246u; return 0; }
r[3]=read(ram,0x0c043338u,4);
goto P_0c043248;
P_0c043248: /* original 65c3, guest PC 0x0c043248 */
if(!s->budget--) { s->failed_pc=0x0c043248u; return 0; }
r[5]=r[12];
goto P_0c04324a;
P_0c04324a: /* original 430b, guest PC 0x0c04324a */
if(!s->budget--) { s->failed_pc=0x0c04324au; return 0; }
target=r[3];
r[16]=0x0c04324eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04324eu) { target=s->pc; goto dispatch; }
goto P_0c04324e;
P_0c04324c: /* original 64e3, guest PC 0x0c04324c */
if(!s->budget--) { s->failed_pc=0x0c04324cu; return 0; }
r[4]=r[14];
goto P_0c04324e;
P_0c04324e: /* original a004, guest PC 0x0c04324e */
if(!s->budget--) { s->failed_pc=0x0c04324eu; return 0; }
goto P_0c04325a;
P_0c043250: /* original 0009, guest PC 0x0c043250 */
if(!s->budget--) { s->failed_pc=0x0c043250u; return 0; }
goto P_0c043252;
P_0c043252: /* original d336, guest PC 0x0c043252 */
if(!s->budget--) { s->failed_pc=0x0c043252u; return 0; }
r[3]=read(ram,0x0c04332cu,4);
goto P_0c043254;
P_0c043254: /* original 65c3, guest PC 0x0c043254 */
if(!s->budget--) { s->failed_pc=0x0c043254u; return 0; }
r[5]=r[12];
goto P_0c043256;
P_0c043256: /* original 430b, guest PC 0x0c043256 */
if(!s->budget--) { s->failed_pc=0x0c043256u; return 0; }
target=r[3];
r[16]=0x0c04325au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04325au) { target=s->pc; goto dispatch; }
goto P_0c04325a;
P_0c043258: /* original 64e3, guest PC 0x0c043258 */
if(!s->budget--) { s->failed_pc=0x0c043258u; return 0; }
r[4]=r[14];
goto P_0c04325a;
P_0c04325a: /* original 60d3, guest PC 0x0c04325a */
if(!s->budget--) { s->failed_pc=0x0c04325au; return 0; }
r[0]=r[13];
goto P_0c04325c;
P_0c04325c: /* original 7f10, guest PC 0x0c04325c */
if(!s->budget--) { s->failed_pc=0x0c04325cu; return 0; }
r[15]+=0x00000010u;
goto P_0c04325e;
P_0c04325e: /* original 4f26, guest PC 0x0c04325e */
if(!s->budget--) { s->failed_pc=0x0c04325eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043260;
P_0c043260: /* original 6bf6, guest PC 0x0c043260 */
if(!s->budget--) { s->failed_pc=0x0c043260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043262;
P_0c043262: /* original 6cf6, guest PC 0x0c043262 */
if(!s->budget--) { s->failed_pc=0x0c043262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043264;
P_0c043264: /* original 6df6, guest PC 0x0c043264 */
if(!s->budget--) { s->failed_pc=0x0c043264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043266;
P_0c043266: /* original 000b, guest PC 0x0c043266 */
if(!s->budget--) { s->failed_pc=0x0c043266u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043268: /* original 6ef6, guest PC 0x0c043268 */
if(!s->budget--) { s->failed_pc=0x0c043268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04326au,s,ram);
P_0c046616: /* original d341, guest PC 0x0c046616 */
if(!s->budget--) { s->failed_pc=0x0c046616u; return 0; }
r[3]=read(ram,0x0c04671cu,4);
goto P_0c046618;
P_0c046618: /* original 432b, guest PC 0x0c046618 */
if(!s->budget--) { s->failed_pc=0x0c046618u; return 0; }
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
P_0c04661a: /* original 0009, guest PC 0x0c04661a */
if(!s->budget--) { s->failed_pc=0x0c04661au; return 0; }
return vf3_matrix_family(0x0c04661cu,s,ram);
P_0c04e412: /* original 4f22, guest PC 0x0c04e412 */
if(!s->budget--) { s->failed_pc=0x0c04e412u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e414;
P_0c04e414: /* original 6353, guest PC 0x0c04e414 */
if(!s->budget--) { s->failed_pc=0x0c04e414u; return 0; }
r[3]=r[5];
goto P_0c04e416;
P_0c04e416: /* original 4f12, guest PC 0x0c04e416 */
if(!s->budget--) { s->failed_pc=0x0c04e416u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e418;
P_0c04e418: /* original 7fd0, guest PC 0x0c04e418 */
if(!s->budget--) { s->failed_pc=0x0c04e418u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04e41a;
P_0c04e41a: /* original 2f52, guest PC 0x0c04e41a */
if(!s->budget--) { s->failed_pc=0x0c04e41au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04e41c;
P_0c04e41c: /* original 2f56, guest PC 0x0c04e41c */
if(!s->budget--) { s->failed_pc=0x0c04e41cu; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c04e41e;
P_0c04e41e: /* original 2fe6, guest PC 0x0c04e41e */
if(!s->budget--) { s->failed_pc=0x0c04e41eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c04e420;
P_0c04e420: /* original d316, guest PC 0x0c04e420 */
if(!s->budget--) { s->failed_pc=0x0c04e420u; return 0; }
r[3]=read(ram,0x0c04e47cu,4);
goto P_0c04e422;
P_0c04e422: /* original d217, guest PC 0x0c04e422 */
if(!s->budget--) { s->failed_pc=0x0c04e422u; return 0; }
r[2]=read(ram,0x0c04e480u,4);
goto P_0c04e424;
P_0c04e424: /* original 420b, guest PC 0x0c04e424 */
if(!s->budget--) { s->failed_pc=0x0c04e424u; return 0; }
target=r[2];
r[16]=0x0c04e428u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e428u) { target=s->pc; goto dispatch; }
goto P_0c04e428;
P_0c04e426: /* original 2f36, guest PC 0x0c04e426 */
if(!s->budget--) { s->failed_pc=0x0c04e426u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c04e428;
P_0c04e428: /* original 9111, guest PC 0x0c04e428 */
if(!s->budget--) { s->failed_pc=0x0c04e428u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e44eu,2);
goto P_0c04e42a;
P_0c04e42a: /* original d016, guest PC 0x0c04e42a */
if(!s->budget--) { s->failed_pc=0x0c04e42au; return 0; }
r[0]=read(ram,0x0c04e484u,4);
goto P_0c04e42c;
P_0c04e42c: /* original 2e1f, guest PC 0x0c04e42c */
if(!s->budget--) { s->failed_pc=0x0c04e42cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[1]);
goto P_0c04e42e;
P_0c04e42e: /* original 011a, guest PC 0x0c04e42e */
if(!s->budget--) { s->failed_pc=0x0c04e42eu; return 0; }
r[1]=r[19];
goto P_0c04e430;
P_0c04e430: /* original 611f, guest PC 0x0c04e430 */
if(!s->budget--) { s->failed_pc=0x0c04e430u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04e432;
P_0c04e432: /* original 031c, guest PC 0x0c04e432 */
if(!s->budget--) { s->failed_pc=0x0c04e432u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c04e434;
P_0c04e434: /* original 2338, guest PC 0x0c04e434 */
if(!s->budget--) { s->failed_pc=0x0c04e434u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04e436;
P_0c04e436: /* original 8d38, guest PC 0x0c04e436 */
if(!s->budget--) { s->failed_pc=0x0c04e436u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04e4aa; }
goto P_0c04e43a;
P_0c04e438: /* original 7f0c, guest PC 0x0c04e438 */
if(!s->budget--) { s->failed_pc=0x0c04e438u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e43a;
P_0c04e43a: /* original d213, guest PC 0x0c04e43a */
if(!s->budget--) { s->failed_pc=0x0c04e43au; return 0; }
r[2]=read(ram,0x0c04e488u,4);
goto P_0c04e43c;
P_0c04e43c: /* original 420b, guest PC 0x0c04e43c */
if(!s->budget--) { s->failed_pc=0x0c04e43cu; return 0; }
target=r[2];
r[16]=0x0c04e440u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e440u) { target=s->pc; goto dispatch; }
goto P_0c04e440;
P_0c04e43e: /* original 64e3, guest PC 0x0c04e43e */
if(!s->budget--) { s->failed_pc=0x0c04e43eu; return 0; }
r[4]=r[14];
goto P_0c04e440;
P_0c04e440: /* original 2008, guest PC 0x0c04e440 */
if(!s->budget--) { s->failed_pc=0x0c04e440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e442;
P_0c04e442: /* original 8b25, guest PC 0x0c04e442 */
if(!s->budget--) { s->failed_pc=0x0c04e442u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e490; }
goto P_0c04e444;
P_0c04e444: /* original d211, guest PC 0x0c04e444 */
if(!s->budget--) { s->failed_pc=0x0c04e444u; return 0; }
r[2]=read(ram,0x0c04e48cu,4);
goto P_0c04e446;
P_0c04e446: /* original 420b, guest PC 0x0c04e446 */
if(!s->budget--) { s->failed_pc=0x0c04e446u; return 0; }
target=r[2];
r[16]=0x0c04e44au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e44au) { target=s->pc; goto dispatch; }
goto P_0c04e44a;
P_0c04e448: /* original 64e3, guest PC 0x0c04e448 */
if(!s->budget--) { s->failed_pc=0x0c04e448u; return 0; }
r[4]=r[14];
goto P_0c04e44a;
P_0c04e44a: /* original a02e, guest PC 0x0c04e44a */
if(!s->budget--) { s->failed_pc=0x0c04e44au; return 0; }
goto P_0c04e4aa;
P_0c04e44c: /* original 0009, guest PC 0x0c04e44c */
if(!s->budget--) { s->failed_pc=0x0c04e44cu; return 0; }
return vf3_matrix_family(0x0c04e44eu,s,ram);
P_0c04e490: /* original d338, guest PC 0x0c04e490 */
if(!s->budget--) { s->failed_pc=0x0c04e490u; return 0; }
r[3]=read(ram,0x0c04e574u,4);
goto P_0c04e492;
P_0c04e492: /* original 430b, guest PC 0x0c04e492 */
if(!s->budget--) { s->failed_pc=0x0c04e492u; return 0; }
target=r[3];
r[16]=0x0c04e496u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e496u) { target=s->pc; goto dispatch; }
goto P_0c04e496;
P_0c04e494: /* original 64e3, guest PC 0x0c04e494 */
if(!s->budget--) { s->failed_pc=0x0c04e494u; return 0; }
r[4]=r[14];
goto P_0c04e496;
P_0c04e496: /* original 2008, guest PC 0x0c04e496 */
if(!s->budget--) { s->failed_pc=0x0c04e496u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e498;
P_0c04e498: /* original 8907, guest PC 0x0c04e498 */
if(!s->budget--) { s->failed_pc=0x0c04e498u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e4aa; }
goto P_0c04e49a;
P_0c04e49a: /* original 9266, guest PC 0x0c04e49a */
if(!s->budget--) { s->failed_pc=0x0c04e49au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56au,2);
goto P_0c04e49c;
P_0c04e49c: /* original d036, guest PC 0x0c04e49c */
if(!s->budget--) { s->failed_pc=0x0c04e49cu; return 0; }
r[0]=read(ram,0x0c04e578u,4);
goto P_0c04e49e;
P_0c04e49e: /* original 2e2f, guest PC 0x0c04e49e */
if(!s->budget--) { s->failed_pc=0x0c04e49eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[2]);
goto P_0c04e4a0;
P_0c04e4a0: /* original 021a, guest PC 0x0c04e4a0 */
if(!s->budget--) { s->failed_pc=0x0c04e4a0u; return 0; }
r[2]=r[19];
goto P_0c04e4a2;
P_0c04e4a2: /* original 622f, guest PC 0x0c04e4a2 */
if(!s->budget--) { s->failed_pc=0x0c04e4a2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e4a4;
P_0c04e4a4: /* original 032c, guest PC 0x0c04e4a4 */
if(!s->budget--) { s->failed_pc=0x0c04e4a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c04e4a6;
P_0c04e4a6: /* original 2338, guest PC 0x0c04e4a6 */
if(!s->budget--) { s->failed_pc=0x0c04e4a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04e4a8;
P_0c04e4a8: /* original 8b02, guest PC 0x0c04e4a8 */
if(!s->budget--) { s->failed_pc=0x0c04e4a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e4b0; }
goto P_0c04e4aa;
P_0c04e4aa: /* original 905f, guest PC 0x0c04e4aa */
if(!s->budget--) { s->failed_pc=0x0c04e4aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56cu,2);
goto P_0c04e4ac;
P_0c04e4ac: /* original a013, guest PC 0x0c04e4ac */
if(!s->budget--) { s->failed_pc=0x0c04e4acu; return 0; }
goto P_0c04e4d6;
P_0c04e4ae: /* original 0009, guest PC 0x0c04e4ae */
if(!s->budget--) { s->failed_pc=0x0c04e4aeu; return 0; }
goto P_0c04e4b0;
P_0c04e4b0: /* original d332, guest PC 0x0c04e4b0 */
if(!s->budget--) { s->failed_pc=0x0c04e4b0u; return 0; }
r[3]=read(ram,0x0c04e57cu,4);
goto P_0c04e4b2;
P_0c04e4b2: /* original 430b, guest PC 0x0c04e4b2 */
if(!s->budget--) { s->failed_pc=0x0c04e4b2u; return 0; }
target=r[3];
r[16]=0x0c04e4b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e4b6u) { target=s->pc; goto dispatch; }
goto P_0c04e4b6;
P_0c04e4b4: /* original 64e3, guest PC 0x0c04e4b4 */
if(!s->budget--) { s->failed_pc=0x0c04e4b4u; return 0; }
r[4]=r[14];
goto P_0c04e4b6;
P_0c04e4b6: /* original 4011, guest PC 0x0c04e4b6 */
if(!s->budget--) { s->failed_pc=0x0c04e4b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e4b8;
P_0c04e4b8: /* original 8902, guest PC 0x0c04e4b8 */
if(!s->budget--) { s->failed_pc=0x0c04e4b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e4c0; }
goto P_0c04e4ba;
P_0c04e4ba: /* original 9058, guest PC 0x0c04e4ba */
if(!s->budget--) { s->failed_pc=0x0c04e4bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56eu,2);
goto P_0c04e4bc;
P_0c04e4bc: /* original a00b, guest PC 0x0c04e4bc */
if(!s->budget--) { s->failed_pc=0x0c04e4bcu; return 0; }
goto P_0c04e4d6;
P_0c04e4be: /* original 0009, guest PC 0x0c04e4be */
if(!s->budget--) { s->failed_pc=0x0c04e4beu; return 0; }
goto P_0c04e4c0;
P_0c04e4c0: /* original 65f2, guest PC 0x0c04e4c0 */
if(!s->budget--) { s->failed_pc=0x0c04e4c0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04e4c2;
P_0c04e4c2: /* original 66f3, guest PC 0x0c04e4c2 */
if(!s->budget--) { s->failed_pc=0x0c04e4c2u; return 0; }
r[6]=r[15];
goto P_0c04e4c4;
P_0c04e4c4: /* original d32e, guest PC 0x0c04e4c4 */
if(!s->budget--) { s->failed_pc=0x0c04e4c4u; return 0; }
r[3]=read(ram,0x0c04e580u,4);
goto P_0c04e4c6;
P_0c04e4c6: /* original 7604, guest PC 0x0c04e4c6 */
if(!s->budget--) { s->failed_pc=0x0c04e4c6u; return 0; }
r[6]+=0x00000004u;
goto P_0c04e4c8;
P_0c04e4c8: /* original 430b, guest PC 0x0c04e4c8 */
if(!s->budget--) { s->failed_pc=0x0c04e4c8u; return 0; }
target=r[3];
r[16]=0x0c04e4ccu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e4ccu) { target=s->pc; goto dispatch; }
goto P_0c04e4cc;
P_0c04e4ca: /* original 64e3, guest PC 0x0c04e4ca */
if(!s->budget--) { s->failed_pc=0x0c04e4cau; return 0; }
r[4]=r[14];
goto P_0c04e4cc;
P_0c04e4cc: /* original 4011, guest PC 0x0c04e4cc */
if(!s->budget--) { s->failed_pc=0x0c04e4ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e4ce;
P_0c04e4ce: /* original 8b01, guest PC 0x0c04e4ce */
if(!s->budget--) { s->failed_pc=0x0c04e4ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e4d4; }
goto P_0c04e4d0;
P_0c04e4d0: /* original a001, guest PC 0x0c04e4d0 */
if(!s->budget--) { s->failed_pc=0x0c04e4d0u; return 0; }
r[0]=0x00000000u;
goto P_0c04e4d6;
P_0c04e4d2: /* original e000, guest PC 0x0c04e4d2 */
if(!s->budget--) { s->failed_pc=0x0c04e4d2u; return 0; }
r[0]=0x00000000u;
goto P_0c04e4d4;
P_0c04e4d4: /* original 904c, guest PC 0x0c04e4d4 */
if(!s->budget--) { s->failed_pc=0x0c04e4d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e570u,2);
goto P_0c04e4d6;
P_0c04e4d6: /* original 7f30, guest PC 0x0c04e4d6 */
if(!s->budget--) { s->failed_pc=0x0c04e4d6u; return 0; }
r[15]+=0x00000030u;
goto P_0c04e4d8;
P_0c04e4d8: /* original 4f16, guest PC 0x0c04e4d8 */
if(!s->budget--) { s->failed_pc=0x0c04e4d8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e4da;
P_0c04e4da: /* original 4f26, guest PC 0x0c04e4da */
if(!s->budget--) { s->failed_pc=0x0c04e4dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e4dc;
P_0c04e4dc: /* original 000b, guest PC 0x0c04e4dc */
if(!s->budget--) { s->failed_pc=0x0c04e4dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e4de: /* original 6ef6, guest PC 0x0c04e4de */
if(!s->budget--) { s->failed_pc=0x0c04e4deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e4e0u,s,ram);
P_0c04f88c: /* original e600, guest PC 0x0c04f88c */
if(!s->budget--) { s->failed_pc=0x0c04f88cu; return 0; }
r[6]=0x00000000u;
goto P_0c04f88e;
P_0c04f88e: /* original e70c, guest PC 0x0c04f88e */
if(!s->budget--) { s->failed_pc=0x0c04f88eu; return 0; }
r[7]=0x0000000cu;
goto P_0c04f890;
P_0c04f890: /* original 6563, guest PC 0x0c04f890 */
if(!s->budget--) { s->failed_pc=0x0c04f890u; return 0; }
r[5]=r[6];
goto P_0c04f892;
P_0c04f892: /* original 6340, guest PC 0x0c04f892 */
if(!s->budget--) { s->failed_pc=0x0c04f892u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f894;
P_0c04f894: /* original 2338, guest PC 0x0c04f894 */
if(!s->budget--) { s->failed_pc=0x0c04f894u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f896;
P_0c04f896: /* original 8904, guest PC 0x0c04f896 */
if(!s->budget--) { s->failed_pc=0x0c04f896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8a2; }
goto P_0c04f898;
P_0c04f898: /* original 7601, guest PC 0x0c04f898 */
if(!s->budget--) { s->failed_pc=0x0c04f898u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f89a;
P_0c04f89a: /* original 3673, guest PC 0x0c04f89a */
if(!s->budget--) { s->failed_pc=0x0c04f89au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f89c;
P_0c04f89c: /* original 7501, guest PC 0x0c04f89c */
if(!s->budget--) { s->failed_pc=0x0c04f89cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04f89e;
P_0c04f89e: /* original 8ff8, guest PC 0x0c04f89e */
if(!s->budget--) { s->failed_pc=0x0c04f89eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f892; }
goto P_0c04f8a2;
P_0c04f8a0: /* original 7401, guest PC 0x0c04f8a0 */
if(!s->budget--) { s->failed_pc=0x0c04f8a0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8a2;
P_0c04f8a2: /* original 000b, guest PC 0x0c04f8a2 */
if(!s->budget--) { s->failed_pc=0x0c04f8a2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c04f8a4: /* original 6053, guest PC 0x0c04f8a4 */
if(!s->budget--) { s->failed_pc=0x0c04f8a4u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c04f8a6u,s,ram);
P_0c04f8bc: /* original 2fe6, guest PC 0x0c04f8bc */
if(!s->budget--) { s->failed_pc=0x0c04f8bcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c04f8be;
P_0c04f8be: /* original 4f22, guest PC 0x0c04f8be */
if(!s->budget--) { s->failed_pc=0x0c04f8beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f8c0;
P_0c04f8c0: /* original 7ff8, guest PC 0x0c04f8c0 */
if(!s->budget--) { s->failed_pc=0x0c04f8c0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04f8c2;
P_0c04f8c2: /* original 2f42, guest PC 0x0c04f8c2 */
if(!s->budget--) { s->failed_pc=0x0c04f8c2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04f8c4;
P_0c04f8c4: /* original 1f51, guest PC 0x0c04f8c4 */
if(!s->budget--) { s->failed_pc=0x0c04f8c4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04f8c6;
P_0c04f8c6: /* original bfe1, guest PC 0x0c04f8c6 */
if(!s->budget--) { s->failed_pc=0x0c04f8c6u; return 0; }
target=0x0c04f88cu; r[16]=0x0c04f8cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f8cau) { target=s->pc; goto dispatch; }
goto P_0c04f8ca;
P_0c04f8c8: /* original 64f2, guest PC 0x0c04f8c8 */
if(!s->budget--) { s->failed_pc=0x0c04f8c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04f8ca;
P_0c04f8ca: /* original 6e03, guest PC 0x0c04f8ca */
if(!s->budget--) { s->failed_pc=0x0c04f8cau; return 0; }
r[14]=r[0];
goto P_0c04f8cc;
P_0c04f8cc: /* original bfde, guest PC 0x0c04f8cc */
if(!s->budget--) { s->failed_pc=0x0c04f8ccu; return 0; }
target=0x0c04f88cu; r[16]=0x0c04f8d0u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f8d0u) { target=s->pc; goto dispatch; }
goto P_0c04f8d0;
P_0c04f8ce: /* original 54f1, guest PC 0x0c04f8ce */
if(!s->budget--) { s->failed_pc=0x0c04f8ceu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d0;
P_0c04f8d0: /* original 6403, guest PC 0x0c04f8d0 */
if(!s->budget--) { s->failed_pc=0x0c04f8d0u; return 0; }
r[4]=r[0];
goto P_0c04f8d2;
P_0c04f8d2: /* original 3e40, guest PC 0x0c04f8d2 */
if(!s->budget--) { s->failed_pc=0x0c04f8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c04f8d4;
P_0c04f8d4: /* original 8b08, guest PC 0x0c04f8d4 */
if(!s->budget--) { s->failed_pc=0x0c04f8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f8e8; }
goto P_0c04f8d6;
P_0c04f8d6: /* original 54f1, guest PC 0x0c04f8d6 */
if(!s->budget--) { s->failed_pc=0x0c04f8d6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d8;
P_0c04f8d8: /* original 4e15, guest PC 0x0c04f8d8 */
if(!s->budget--) { s->failed_pc=0x0c04f8d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c04f8da;
P_0c04f8da: /* original e600, guest PC 0x0c04f8da */
if(!s->budget--) { s->failed_pc=0x0c04f8dau; return 0; }
r[6]=0x00000000u;
goto P_0c04f8dc;
P_0c04f8dc: /* original 8f0e, guest PC 0x0c04f8dc */
if(!s->budget--) { s->failed_pc=0x0c04f8dcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!cond) { goto P_0c04f8fc; }
goto P_0c04f8e0;
P_0c04f8de: /* original 65f2, guest PC 0x0c04f8de */
if(!s->budget--) { s->failed_pc=0x0c04f8deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f8e0;
P_0c04f8e0: /* original 6340, guest PC 0x0c04f8e0 */
if(!s->budget--) { s->failed_pc=0x0c04f8e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f8e2;
P_0c04f8e2: /* original 6250, guest PC 0x0c04f8e2 */
if(!s->budget--) { s->failed_pc=0x0c04f8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c04f8e4;
P_0c04f8e4: /* original 3230, guest PC 0x0c04f8e4 */
if(!s->budget--) { s->failed_pc=0x0c04f8e4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04f8e6;
P_0c04f8e6: /* original 8904, guest PC 0x0c04f8e6 */
if(!s->budget--) { s->failed_pc=0x0c04f8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8f2; }
goto P_0c04f8e8;
P_0c04f8e8: /* original 7f08, guest PC 0x0c04f8e8 */
if(!s->budget--) { s->failed_pc=0x0c04f8e8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04f8ea;
P_0c04f8ea: /* original 4f26, guest PC 0x0c04f8ea */
if(!s->budget--) { s->failed_pc=0x0c04f8eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f8ec;
P_0c04f8ec: /* original e000, guest PC 0x0c04f8ec */
if(!s->budget--) { s->failed_pc=0x0c04f8ecu; return 0; }
r[0]=0x00000000u;
goto P_0c04f8ee;
P_0c04f8ee: /* original 000b, guest PC 0x0c04f8ee */
if(!s->budget--) { s->failed_pc=0x0c04f8eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f8f0: /* original 6ef6, guest PC 0x0c04f8f0 */
if(!s->budget--) { s->failed_pc=0x0c04f8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f8f2;
P_0c04f8f2: /* original 7601, guest PC 0x0c04f8f2 */
if(!s->budget--) { s->failed_pc=0x0c04f8f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f8f4;
P_0c04f8f4: /* original 36e3, guest PC 0x0c04f8f4 */
if(!s->budget--) { s->failed_pc=0x0c04f8f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[14])!=0);
goto P_0c04f8f6;
P_0c04f8f6: /* original 7401, guest PC 0x0c04f8f6 */
if(!s->budget--) { s->failed_pc=0x0c04f8f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8f8;
P_0c04f8f8: /* original 8ff2, guest PC 0x0c04f8f8 */
if(!s->budget--) { s->failed_pc=0x0c04f8f8u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c04f8e0; }
goto P_0c04f8fc;
P_0c04f8fa: /* original 7501, guest PC 0x0c04f8fa */
if(!s->budget--) { s->failed_pc=0x0c04f8fau; return 0; }
r[5]+=0x00000001u;
goto P_0c04f8fc;
P_0c04f8fc: /* original e001, guest PC 0x0c04f8fc */
if(!s->budget--) { s->failed_pc=0x0c04f8fcu; return 0; }
r[0]=0x00000001u;
goto P_0c04f8fe;
P_0c04f8fe: /* original 7f08, guest PC 0x0c04f8fe */
if(!s->budget--) { s->failed_pc=0x0c04f8feu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f900;
P_0c04f900: /* original 4f26, guest PC 0x0c04f900 */
if(!s->budget--) { s->failed_pc=0x0c04f900u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f902;
P_0c04f902: /* original 000b, guest PC 0x0c04f902 */
if(!s->budget--) { s->failed_pc=0x0c04f902u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f904: /* original 6ef6, guest PC 0x0c04f904 */
if(!s->budget--) { s->failed_pc=0x0c04f904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f906;
P_0c04f906: /* original 2fe6, guest PC 0x0c04f906 */
if(!s->budget--) { s->failed_pc=0x0c04f906u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c04f908;
P_0c04f908: /* original 6e53, guest PC 0x0c04f908 */
if(!s->budget--) { s->failed_pc=0x0c04f908u; return 0; }
r[14]=r[5];
goto P_0c04f90a;
P_0c04f90a: /* original 2fd6, guest PC 0x0c04f90a */
if(!s->budget--) { s->failed_pc=0x0c04f90au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c04f90c;
P_0c04f90c: /* original 6d43, guest PC 0x0c04f90c */
if(!s->budget--) { s->failed_pc=0x0c04f90cu; return 0; }
r[13]=r[4];
goto P_0c04f90e;
P_0c04f90e: /* original 2fc6, guest PC 0x0c04f90e */
if(!s->budget--) { s->failed_pc=0x0c04f90eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c04f910;
P_0c04f910: /* original e500, guest PC 0x0c04f910 */
if(!s->budget--) { s->failed_pc=0x0c04f910u; return 0; }
r[5]=0x00000000u;
goto P_0c04f912;
P_0c04f912: /* original 4f22, guest PC 0x0c04f912 */
if(!s->budget--) { s->failed_pc=0x0c04f912u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f914;
P_0c04f914: /* original 63d0, guest PC 0x0c04f914 */
if(!s->budget--) { s->failed_pc=0x0c04f914u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c04f916;
P_0c04f916: /* original 35dc, guest PC 0x0c04f916 */
if(!s->budget--) { s->failed_pc=0x0c04f916u; return 0; }
r[5]+=r[13];
goto P_0c04f918;
P_0c04f918: /* original 64e3, guest PC 0x0c04f918 */
if(!s->budget--) { s->failed_pc=0x0c04f918u; return 0; }
r[4]=r[14];
goto P_0c04f91a;
P_0c04f91a: /* original ec00, guest PC 0x0c04f91a */
if(!s->budget--) { s->failed_pc=0x0c04f91au; return 0; }
r[12]=0x00000000u;
goto P_0c04f91c;
P_0c04f91c: /* original 7ffc, guest PC 0x0c04f91c */
if(!s->budget--) { s->failed_pc=0x0c04f91cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f91e;
P_0c04f91e: /* original 66c3, guest PC 0x0c04f91e */
if(!s->budget--) { s->failed_pc=0x0c04f91eu; return 0; }
r[6]=r[12];
goto P_0c04f920;
P_0c04f920: /* original 633c, guest PC 0x0c04f920 */
if(!s->budget--) { s->failed_pc=0x0c04f920u; return 0; }
r[3]=r[3]&255u;
goto P_0c04f922;
P_0c04f922: /* original e70c, guest PC 0x0c04f922 */
if(!s->budget--) { s->failed_pc=0x0c04f922u; return 0; }
r[7]=0x0000000cu;
goto P_0c04f924;
P_0c04f924: /* original 1e31, guest PC 0x0c04f924 */
if(!s->budget--) { s->failed_pc=0x0c04f924u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04f926;
P_0c04f926: /* original 2f52, guest PC 0x0c04f926 */
if(!s->budget--) { s->failed_pc=0x0c04f926u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f928;
P_0c04f928: /* original 7410, guest PC 0x0c04f928 */
if(!s->budget--) { s->failed_pc=0x0c04f928u; return 0; }
r[4]+=0x00000010u;
goto P_0c04f92a;
P_0c04f92a: /* original 7504, guest PC 0x0c04f92a */
if(!s->budget--) { s->failed_pc=0x0c04f92au; return 0; }
r[5]+=0x00000004u;
goto P_0c04f92c;
P_0c04f92c: /* original 6354, guest PC 0x0c04f92c */
if(!s->budget--) { s->failed_pc=0x0c04f92cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f92e;
P_0c04f92e: /* original 7601, guest PC 0x0c04f92e */
if(!s->budget--) { s->failed_pc=0x0c04f92eu; return 0; }
r[6]+=0x00000001u;
goto P_0c04f930;
P_0c04f930: /* original 3673, guest PC 0x0c04f930 */
if(!s->budget--) { s->failed_pc=0x0c04f930u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f932;
P_0c04f932: /* original 2430, guest PC 0x0c04f932 */
if(!s->budget--) { s->failed_pc=0x0c04f932u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f934;
P_0c04f934: /* original 8ffa, guest PC 0x0c04f934 */
if(!s->budget--) { s->failed_pc=0x0c04f934u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f92c; }
goto P_0c04f938;
P_0c04f936: /* original 7401, guest PC 0x0c04f936 */
if(!s->budget--) { s->failed_pc=0x0c04f936u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f938;
P_0c04f938: /* original e01c, guest PC 0x0c04f938 */
if(!s->budget--) { s->failed_pc=0x0c04f938u; return 0; }
r[0]=0x0000001cu;
goto P_0c04f93a;
P_0c04f93a: /* original 64e3, guest PC 0x0c04f93a */
if(!s->budget--) { s->failed_pc=0x0c04f93au; return 0; }
r[4]=r[14];
goto P_0c04f93c;
P_0c04f93c: /* original e708, guest PC 0x0c04f93c */
if(!s->budget--) { s->failed_pc=0x0c04f93cu; return 0; }
r[7]=0x00000008u;
goto P_0c04f93e;
P_0c04f93e: /* original 0ec4, guest PC 0x0c04f93e */
if(!s->budget--) { s->failed_pc=0x0c04f93eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c04f940;
P_0c04f940: /* original 65f2, guest PC 0x0c04f940 */
if(!s->budget--) { s->failed_pc=0x0c04f940u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f942;
P_0c04f942: /* original 7420, guest PC 0x0c04f942 */
if(!s->budget--) { s->failed_pc=0x0c04f942u; return 0; }
r[4]+=0x00000020u;
goto P_0c04f944;
P_0c04f944: /* original 66c3, guest PC 0x0c04f944 */
if(!s->budget--) { s->failed_pc=0x0c04f944u; return 0; }
r[6]=r[12];
goto P_0c04f946;
P_0c04f946: /* original 7510, guest PC 0x0c04f946 */
if(!s->budget--) { s->failed_pc=0x0c04f946u; return 0; }
r[5]+=0x00000010u;
goto P_0c04f948;
P_0c04f948: /* original 6354, guest PC 0x0c04f948 */
if(!s->budget--) { s->failed_pc=0x0c04f948u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f94a;
P_0c04f94a: /* original 7601, guest PC 0x0c04f94a */
if(!s->budget--) { s->failed_pc=0x0c04f94au; return 0; }
r[6]+=0x00000001u;
goto P_0c04f94c;
P_0c04f94c: /* original 3673, guest PC 0x0c04f94c */
if(!s->budget--) { s->failed_pc=0x0c04f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f94e;
P_0c04f94e: /* original 2430, guest PC 0x0c04f94e */
if(!s->budget--) { s->failed_pc=0x0c04f94eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f950;
P_0c04f950: /* original 8ffa, guest PC 0x0c04f950 */
if(!s->budget--) { s->failed_pc=0x0c04f950u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f948; }
goto P_0c04f954;
P_0c04f952: /* original 7401, guest PC 0x0c04f952 */
if(!s->budget--) { s->failed_pc=0x0c04f952u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f954;
P_0c04f954: /* original dc21, guest PC 0x0c04f954 */
if(!s->budget--) { s->failed_pc=0x0c04f954u; return 0; }
r[12]=read(ram,0x0c04f9dcu,4);
goto P_0c04f956;
P_0c04f956: /* original e502, guest PC 0x0c04f956 */
if(!s->budget--) { s->failed_pc=0x0c04f956u; return 0; }
r[5]=0x00000002u;
goto P_0c04f958;
P_0c04f958: /* original 63c2, guest PC 0x0c04f958 */
if(!s->budget--) { s->failed_pc=0x0c04f958u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f95a;
P_0c04f95a: /* original 5233, guest PC 0x0c04f95a */
if(!s->budget--) { s->failed_pc=0x0c04f95au; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f95c;
P_0c04f95c: /* original 420b, guest PC 0x0c04f95c */
if(!s->budget--) { s->failed_pc=0x0c04f95cu; return 0; }
target=r[2];
r[16]=0x0c04f960u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f960u) { target=s->pc; goto dispatch; }
goto P_0c04f960;
P_0c04f95e: /* original 64d3, guest PC 0x0c04f95e */
if(!s->budget--) { s->failed_pc=0x0c04f95eu; return 0; }
r[4]=r[13];
goto P_0c04f960;
P_0c04f960: /* original 600d, guest PC 0x0c04f960 */
if(!s->budget--) { s->failed_pc=0x0c04f960u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f962;
P_0c04f962: /* original e518, guest PC 0x0c04f962 */
if(!s->budget--) { s->failed_pc=0x0c04f962u; return 0; }
r[5]=0x00000018u;
goto P_0c04f964;
P_0c04f964: /* original 1e03, guest PC 0x0c04f964 */
if(!s->budget--) { s->failed_pc=0x0c04f964u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c04f966;
P_0c04f966: /* original 63c2, guest PC 0x0c04f966 */
if(!s->budget--) { s->failed_pc=0x0c04f966u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f968;
P_0c04f968: /* original 5233, guest PC 0x0c04f968 */
if(!s->budget--) { s->failed_pc=0x0c04f968u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f96a;
P_0c04f96a: /* original 420b, guest PC 0x0c04f96a */
if(!s->budget--) { s->failed_pc=0x0c04f96au; return 0; }
target=r[2];
r[16]=0x0c04f96eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f96eu) { target=s->pc; goto dispatch; }
goto P_0c04f96e;
P_0c04f96c: /* original 64d3, guest PC 0x0c04f96c */
if(!s->budget--) { s->failed_pc=0x0c04f96cu; return 0; }
r[4]=r[13];
goto P_0c04f96e;
P_0c04f96e: /* original 600d, guest PC 0x0c04f96e */
if(!s->budget--) { s->failed_pc=0x0c04f96eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f970;
P_0c04f970: /* original 1e0a, guest PC 0x0c04f970 */
if(!s->budget--) { s->failed_pc=0x0c04f970u; return 0; }
write(ram,r[14]+40,r[0],4);
goto P_0c04f972;
P_0c04f972: /* original e51a, guest PC 0x0c04f972 */
if(!s->budget--) { s->failed_pc=0x0c04f972u; return 0; }
r[5]=0x0000001au;
goto P_0c04f974;
P_0c04f974: /* original 84d1, guest PC 0x0c04f974 */
if(!s->budget--) { s->failed_pc=0x0c04f974u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c04f976;
P_0c04f976: /* original 80ea, guest PC 0x0c04f976 */
if(!s->budget--) { s->failed_pc=0x0c04f976u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04f978;
P_0c04f978: /* original 60c2, guest PC 0x0c04f978 */
if(!s->budget--) { s->failed_pc=0x0c04f978u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c04f97a;
P_0c04f97a: /* original 5003, guest PC 0x0c04f97a */
if(!s->budget--) { s->failed_pc=0x0c04f97au; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04f97c;
P_0c04f97c: /* original 400b, guest PC 0x0c04f97c */
if(!s->budget--) { s->failed_pc=0x0c04f97cu; return 0; }
target=r[0];
r[16]=0x0c04f980u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f980u) { target=s->pc; goto dispatch; }
goto P_0c04f980;
P_0c04f97e: /* original 64d3, guest PC 0x0c04f97e */
if(!s->budget--) { s->failed_pc=0x0c04f97eu; return 0; }
r[4]=r[13];
goto P_0c04f980;
P_0c04f980: /* original 7f04, guest PC 0x0c04f980 */
if(!s->budget--) { s->failed_pc=0x0c04f980u; return 0; }
r[15]+=0x00000004u;
goto P_0c04f982;
P_0c04f982: /* original 81e4, guest PC 0x0c04f982 */
if(!s->budget--) { s->failed_pc=0x0c04f982u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c04f984;
P_0c04f984: /* original 4f26, guest PC 0x0c04f984 */
if(!s->budget--) { s->failed_pc=0x0c04f984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f986;
P_0c04f986: /* original 6cf6, guest PC 0x0c04f986 */
if(!s->budget--) { s->failed_pc=0x0c04f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f988;
P_0c04f988: /* original 6df6, guest PC 0x0c04f988 */
if(!s->budget--) { s->failed_pc=0x0c04f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f98a;
P_0c04f98a: /* original 000b, guest PC 0x0c04f98a */
if(!s->budget--) { s->failed_pc=0x0c04f98au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f98c: /* original 6ef6, guest PC 0x0c04f98c */
if(!s->budget--) { s->failed_pc=0x0c04f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f98e;
P_0c04f98e: /* original 2fe6, guest PC 0x0c04f98e */
if(!s->budget--) { s->failed_pc=0x0c04f98eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c04f990;
P_0c04f990: /* original 2fd6, guest PC 0x0c04f990 */
if(!s->budget--) { s->failed_pc=0x0c04f990u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c04f992;
P_0c04f992: /* original 2fc6, guest PC 0x0c04f992 */
if(!s->budget--) { s->failed_pc=0x0c04f992u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c04f994;
P_0c04f994: /* original 2fb6, guest PC 0x0c04f994 */
if(!s->budget--) { s->failed_pc=0x0c04f994u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c04f996;
P_0c04f996: /* original 6b53, guest PC 0x0c04f996 */
if(!s->budget--) { s->failed_pc=0x0c04f996u; return 0; }
r[11]=r[5];
goto P_0c04f998;
P_0c04f998: /* original 2fa6, guest PC 0x0c04f998 */
if(!s->budget--) { s->failed_pc=0x0c04f998u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c04f99a;
P_0c04f99a: /* original 4f22, guest PC 0x0c04f99a */
if(!s->budget--) { s->failed_pc=0x0c04f99au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f99c;
P_0c04f99c: /* original 4f12, guest PC 0x0c04f99c */
if(!s->budget--) { s->failed_pc=0x0c04f99cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f99e;
P_0c04f99e: /* original 7ffc, guest PC 0x0c04f99e */
if(!s->budget--) { s->failed_pc=0x0c04f99eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f9a0;
P_0c04f9a0: /* original 2f62, guest PC 0x0c04f9a0 */
if(!s->budget--) { s->failed_pc=0x0c04f9a0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04f9a2;
P_0c04f9a2: /* original 9c19, guest PC 0x0c04f9a2 */
if(!s->budget--) { s->failed_pc=0x0c04f9a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9d8u,2);
goto P_0c04f9a4;
P_0c04f9a4: /* original d30e, guest PC 0x0c04f9a4 */
if(!s->budget--) { s->failed_pc=0x0c04f9a4u; return 0; }
r[3]=read(ram,0x0c04f9e0u,4);
goto P_0c04f9a6;
P_0c04f9a6: /* original 24cf, guest PC 0x0c04f9a6 */
if(!s->budget--) { s->failed_pc=0x0c04f9a6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04f9a8;
P_0c04f9a8: /* original 2fb6, guest PC 0x0c04f9a8 */
if(!s->budget--) { s->failed_pc=0x0c04f9a8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c04f9aa;
P_0c04f9aa: /* original d10f, guest PC 0x0c04f9aa */
if(!s->budget--) { s->failed_pc=0x0c04f9aau; return 0; }
r[1]=read(ram,0x0c04f9e8u,4);
goto P_0c04f9ac;
P_0c04f9ac: /* original d20d, guest PC 0x0c04f9ac */
if(!s->budget--) { s->failed_pc=0x0c04f9acu; return 0; }
r[2]=read(ram,0x0c04f9e4u,4);
goto P_0c04f9ae;
P_0c04f9ae: /* original 0c1a, guest PC 0x0c04f9ae */
if(!s->budget--) { s->failed_pc=0x0c04f9aeu; return 0; }
r[12]=r[19];
goto P_0c04f9b0;
P_0c04f9b0: /* original 6ccf, guest PC 0x0c04f9b0 */
if(!s->budget--) { s->failed_pc=0x0c04f9b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04f9b2;
P_0c04f9b2: /* original 3c3c, guest PC 0x0c04f9b2 */
if(!s->budget--) { s->failed_pc=0x0c04f9b2u; return 0; }
r[12]+=r[3];
goto P_0c04f9b4;
P_0c04f9b4: /* original 410b, guest PC 0x0c04f9b4 */
if(!s->budget--) { s->failed_pc=0x0c04f9b4u; return 0; }
target=r[1];
r[16]=0x0c04f9b8u;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f9b8u) { target=s->pc; goto dispatch; }
goto P_0c04f9b8;
P_0c04f9b6: /* original 2f26, guest PC 0x0c04f9b6 */
if(!s->budget--) { s->failed_pc=0x0c04f9b6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c04f9b8;
P_0c04f9b8: /* original da0c, guest PC 0x0c04f9b8 */
if(!s->budget--) { s->failed_pc=0x0c04f9b8u; return 0; }
r[10]=read(ram,0x0c04f9ecu,4);
goto P_0c04f9ba;
P_0c04f9ba: /* original 7f08, guest PC 0x0c04f9ba */
if(!s->budget--) { s->failed_pc=0x0c04f9bau; return 0; }
r[15]+=0x00000008u;
goto P_0c04f9bc;
P_0c04f9bc: /* original 5eca, guest PC 0x0c04f9bc */
if(!s->budget--) { s->failed_pc=0x0c04f9bcu; return 0; }
r[14]=read(ram,r[12]+40,4);
goto P_0c04f9be;
P_0c04f9be: /* original a028, guest PC 0x0c04f9be */
if(!s->budget--) { s->failed_pc=0x0c04f9beu; return 0; }
r[13]=0x00000000u;
goto P_0c04fa12;
P_0c04f9c0: /* original ed00, guest PC 0x0c04f9c0 */
if(!s->budget--) { s->failed_pc=0x0c04f9c0u; return 0; }
r[13]=0x00000000u;
goto P_0c04f9c2;
P_0c04f9c2: /* original 64e0, guest PC 0x0c04f9c2 */
if(!s->budget--) { s->failed_pc=0x0c04f9c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04f9c4;
P_0c04f9c4: /* original 604c, guest PC 0x0c04f9c4 */
if(!s->budget--) { s->failed_pc=0x0c04f9c4u; return 0; }
r[0]=r[4]&255u;
goto P_0c04f9c6;
P_0c04f9c6: /* original 8800, guest PC 0x0c04f9c6 */
if(!s->budget--) { s->failed_pc=0x0c04f9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04f9c8;
P_0c04f9c8: /* original 8921, guest PC 0x0c04f9c8 */
if(!s->budget--) { s->failed_pc=0x0c04f9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9ca;
P_0c04f9ca: /* original 8833, guest PC 0x0c04f9ca */
if(!s->budget--) { s->failed_pc=0x0c04f9cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04f9cc;
P_0c04f9cc: /* original 8910, guest PC 0x0c04f9cc */
if(!s->budget--) { s->failed_pc=0x0c04f9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9ce;
P_0c04f9ce: /* original 9104, guest PC 0x0c04f9ce */
if(!s->budget--) { s->failed_pc=0x0c04f9ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9dau,2);
goto P_0c04f9d0;
P_0c04f9d0: /* original 3010, guest PC 0x0c04f9d0 */
if(!s->budget--) { s->failed_pc=0x0c04f9d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f9d2;
P_0c04f9d2: /* original 890d, guest PC 0x0c04f9d2 */
if(!s->budget--) { s->failed_pc=0x0c04f9d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9d4;
P_0c04f9d4: /* original a01b, guest PC 0x0c04f9d4 */
if(!s->budget--) { s->failed_pc=0x0c04f9d4u; return 0; }
goto P_0c04fa0e;
P_0c04f9d6: /* original 0009, guest PC 0x0c04f9d6 */
if(!s->budget--) { s->failed_pc=0x0c04f9d6u; return 0; }
return vf3_matrix_family(0x0c04f9d8u,s,ram);
P_0c04f9f0: /* original 65e3, guest PC 0x0c04f9f0 */
if(!s->budget--) { s->failed_pc=0x0c04f9f0u; return 0; }
r[5]=r[14];
goto P_0c04f9f2;
P_0c04f9f2: /* original 7504, guest PC 0x0c04f9f2 */
if(!s->budget--) { s->failed_pc=0x0c04f9f2u; return 0; }
r[5]+=0x00000004u;
goto P_0c04f9f4;
P_0c04f9f4: /* original bf62, guest PC 0x0c04f9f4 */
if(!s->budget--) { s->failed_pc=0x0c04f9f4u; return 0; }
target=0x0c04f8bcu; r[16]=0x0c04f9f8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f9f8u) { target=s->pc; goto dispatch; }
goto P_0c04f9f8;
P_0c04f9f6: /* original 64b3, guest PC 0x0c04f9f6 */
if(!s->budget--) { s->failed_pc=0x0c04f9f6u; return 0; }
r[4]=r[11];
goto P_0c04f9f8;
P_0c04f9f8: /* original 2008, guest PC 0x0c04f9f8 */
if(!s->budget--) { s->failed_pc=0x0c04f9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f9fa;
P_0c04f9fa: /* original 8908, guest PC 0x0c04f9fa */
if(!s->budget--) { s->failed_pc=0x0c04f9fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9fc;
P_0c04f9fc: /* original 65f2, guest PC 0x0c04f9fc */
if(!s->budget--) { s->failed_pc=0x0c04f9fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f9fe;
P_0c04f9fe: /* original bf82, guest PC 0x0c04f9fe */
if(!s->budget--) { s->failed_pc=0x0c04f9feu; return 0; }
target=0x0c04f906u; r[16]=0x0c04fa02u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa02u) { target=s->pc; goto dispatch; }
goto P_0c04fa02;
P_0c04fa00: /* original 64e3, guest PC 0x0c04fa00 */
if(!s->budget--) { s->failed_pc=0x0c04fa00u; return 0; }
r[4]=r[14];
goto P_0c04fa02;
P_0c04fa02: /* original d239, guest PC 0x0c04fa02 */
if(!s->budget--) { s->failed_pc=0x0c04fa02u; return 0; }
r[2]=read(ram,0x0c04fae8u,4);
goto P_0c04fa04;
P_0c04fa04: /* original 420b, guest PC 0x0c04fa04 */
if(!s->budget--) { s->failed_pc=0x0c04fa04u; return 0; }
target=r[2];
r[16]=0x0c04fa08u;
r[15]-=4; write(ram,r[15],r[10],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa08u) { target=s->pc; goto dispatch; }
goto P_0c04fa08;
P_0c04fa06: /* original 2fa6, guest PC 0x0c04fa06 */
if(!s->budget--) { s->failed_pc=0x0c04fa06u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c04fa08;
P_0c04fa08: /* original 7f04, guest PC 0x0c04fa08 */
if(!s->budget--) { s->failed_pc=0x0c04fa08u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa0a;
P_0c04fa0a: /* original a00c, guest PC 0x0c04fa0a */
if(!s->budget--) { s->failed_pc=0x0c04fa0au; return 0; }
r[0]=r[13];
goto P_0c04fa26;
P_0c04fa0c: /* original 60d3, guest PC 0x0c04fa0c */
if(!s->budget--) { s->failed_pc=0x0c04fa0cu; return 0; }
r[0]=r[13];
goto P_0c04fa0e;
P_0c04fa0e: /* original 7e20, guest PC 0x0c04fa0e */
if(!s->budget--) { s->failed_pc=0x0c04fa0eu; return 0; }
r[14]+=0x00000020u;
goto P_0c04fa10;
P_0c04fa10: /* original 7d01, guest PC 0x0c04fa10 */
if(!s->budget--) { s->failed_pc=0x0c04fa10u; return 0; }
r[13]+=0x00000001u;
goto P_0c04fa12;
P_0c04fa12: /* original 52c7, guest PC 0x0c04fa12 */
if(!s->budget--) { s->failed_pc=0x0c04fa12u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c04fa14;
P_0c04fa14: /* original 532c, guest PC 0x0c04fa14 */
if(!s->budget--) { s->failed_pc=0x0c04fa14u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04fa16;
P_0c04fa16: /* original 3d33, guest PC 0x0c04fa16 */
if(!s->budget--) { s->failed_pc=0x0c04fa16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fa18;
P_0c04fa18: /* original 8bd3, guest PC 0x0c04fa18 */
if(!s->budget--) { s->failed_pc=0x0c04fa18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f9c2; }
goto P_0c04fa1a;
P_0c04fa1a: /* original d333, guest PC 0x0c04fa1a */
if(!s->budget--) { s->failed_pc=0x0c04fa1au; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fa1c;
P_0c04fa1c: /* original d133, guest PC 0x0c04fa1c */
if(!s->budget--) { s->failed_pc=0x0c04fa1cu; return 0; }
r[1]=read(ram,0x0c04faecu,4);
goto P_0c04fa1e;
P_0c04fa1e: /* original 430b, guest PC 0x0c04fa1e */
if(!s->budget--) { s->failed_pc=0x0c04fa1eu; return 0; }
target=r[3];
r[16]=0x0c04fa22u;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa22u) { target=s->pc; goto dispatch; }
goto P_0c04fa22;
P_0c04fa20: /* original 2f16, guest PC 0x0c04fa20 */
if(!s->budget--) { s->failed_pc=0x0c04fa20u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c04fa22;
P_0c04fa22: /* original e0ff, guest PC 0x0c04fa22 */
if(!s->budget--) { s->failed_pc=0x0c04fa22u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa24;
P_0c04fa24: /* original 7f04, guest PC 0x0c04fa24 */
if(!s->budget--) { s->failed_pc=0x0c04fa24u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa26;
P_0c04fa26: /* original 7f04, guest PC 0x0c04fa26 */
if(!s->budget--) { s->failed_pc=0x0c04fa26u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa28;
P_0c04fa28: /* original 4f16, guest PC 0x0c04fa28 */
if(!s->budget--) { s->failed_pc=0x0c04fa28u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2a;
P_0c04fa2a: /* original 4f26, guest PC 0x0c04fa2a */
if(!s->budget--) { s->failed_pc=0x0c04fa2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2c;
P_0c04fa2c: /* original 6af6, guest PC 0x0c04fa2c */
if(!s->budget--) { s->failed_pc=0x0c04fa2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fa2e;
P_0c04fa2e: /* original 6bf6, guest PC 0x0c04fa2e */
if(!s->budget--) { s->failed_pc=0x0c04fa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fa30;
P_0c04fa30: /* original 6cf6, guest PC 0x0c04fa30 */
if(!s->budget--) { s->failed_pc=0x0c04fa30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fa32;
P_0c04fa32: /* original 6df6, guest PC 0x0c04fa32 */
if(!s->budget--) { s->failed_pc=0x0c04fa32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa34;
P_0c04fa34: /* original 000b, guest PC 0x0c04fa34 */
if(!s->budget--) { s->failed_pc=0x0c04fa34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa36: /* original 6ef6, guest PC 0x0c04fa36 */
if(!s->budget--) { s->failed_pc=0x0c04fa36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fa38u,s,ram);
P_0c07ba28: /* original 2fe6, guest PC 0x0c07ba28 */
if(!s->budget--) { s->failed_pc=0x0c07ba28u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07ba2a;
P_0c07ba2a: /* original 2fd6, guest PC 0x0c07ba2a */
if(!s->budget--) { s->failed_pc=0x0c07ba2au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07ba2c;
P_0c07ba2c: /* original 2fc6, guest PC 0x0c07ba2c */
if(!s->budget--) { s->failed_pc=0x0c07ba2cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c07ba2e;
P_0c07ba2e: /* original 2fb6, guest PC 0x0c07ba2e */
if(!s->budget--) { s->failed_pc=0x0c07ba2eu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07ba30;
P_0c07ba30: /* original 2fa6, guest PC 0x0c07ba30 */
if(!s->budget--) { s->failed_pc=0x0c07ba30u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c07ba32;
P_0c07ba32: /* original 2f96, guest PC 0x0c07ba32 */
if(!s->budget--) { s->failed_pc=0x0c07ba32u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c07ba34;
P_0c07ba34: /* original 2f86, guest PC 0x0c07ba34 */
if(!s->budget--) { s->failed_pc=0x0c07ba34u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c07ba36;
P_0c07ba36: /* original fffb, guest PC 0x0c07ba36 */
if(!s->budget--) { s->failed_pc=0x0c07ba36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07ba38;
P_0c07ba38: /* original ffeb, guest PC 0x0c07ba38 */
if(!s->budget--) { s->failed_pc=0x0c07ba38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07ba3a;
P_0c07ba3a: /* original 4f22, guest PC 0x0c07ba3a */
if(!s->budget--) { s->failed_pc=0x0c07ba3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ba3c;
P_0c07ba3c: /* original d24b, guest PC 0x0c07ba3c */
if(!s->budget--) { s->failed_pc=0x0c07ba3cu; return 0; }
r[2]=read(ram,0x0c07bb6cu,4);
goto P_0c07ba3e;
P_0c07ba3e: /* original 9083, guest PC 0x0c07ba3e */
if(!s->budget--) { s->failed_pc=0x0c07ba3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb48u,2);
goto P_0c07ba40;
P_0c07ba40: /* original 4f12, guest PC 0x0c07ba40 */
if(!s->budget--) { s->failed_pc=0x0c07ba40u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07ba42;
P_0c07ba42: /* original 6322, guest PC 0x0c07ba42 */
if(!s->budget--) { s->failed_pc=0x0c07ba42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ba44;
P_0c07ba44: /* original dd48, guest PC 0x0c07ba44 */
if(!s->budget--) { s->failed_pc=0x0c07ba44u; return 0; }
r[13]=read(ram,0x0c07bb68u,4);
goto P_0c07ba46;
P_0c07ba46: /* original 3f0c, guest PC 0x0c07ba46 */
if(!s->budget--) { s->failed_pc=0x0c07ba46u; return 0; }
r[15]+=r[0];
goto P_0c07ba48;
P_0c07ba48: /* original 1f3d, guest PC 0x0c07ba48 */
if(!s->budget--) { s->failed_pc=0x0c07ba48u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c07ba4a;
P_0c07ba4a: /* original d349, guest PC 0x0c07ba4a */
if(!s->budget--) { s->failed_pc=0x0c07ba4au; return 0; }
r[3]=read(ram,0x0c07bb70u,4);
goto P_0c07ba4c;
P_0c07ba4c: /* original 6132, guest PC 0x0c07ba4c */
if(!s->budget--) { s->failed_pc=0x0c07ba4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07ba4e;
P_0c07ba4e: /* original 1f1c, guest PC 0x0c07ba4e */
if(!s->budget--) { s->failed_pc=0x0c07ba4eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c07ba50;
P_0c07ba50: /* original 50d2, guest PC 0x0c07ba50 */
if(!s->budget--) { s->failed_pc=0x0c07ba50u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c07ba52;
P_0c07ba52: /* original d148, guest PC 0x0c07ba52 */
if(!s->budget--) { s->failed_pc=0x0c07ba52u; return 0; }
r[1]=read(ram,0x0c07bb74u,4);
goto P_0c07ba54;
P_0c07ba54: /* original 2018, guest PC 0x0c07ba54 */
if(!s->budget--) { s->failed_pc=0x0c07ba54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c07ba56;
P_0c07ba56: /* original 8f1a, guest PC 0x0c07ba56 */
if(!s->budget--) { s->failed_pc=0x0c07ba56u; return 0; }
cond=r[17]&1u;
r[11]=0x00000020u;
if(!cond) { goto P_0c07ba8e; }
goto P_0c07ba5a;
P_0c07ba58: /* original eb20, guest PC 0x0c07ba58 */
if(!s->budget--) { s->failed_pc=0x0c07ba58u; return 0; }
r[11]=0x00000020u;
goto P_0c07ba5a;
P_0c07ba5a: /* original 53fd, guest PC 0x0c07ba5a */
if(!s->budget--) { s->failed_pc=0x0c07ba5au; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07ba5c;
P_0c07ba5c: /* original 23b8, guest PC 0x0c07ba5c */
if(!s->budget--) { s->failed_pc=0x0c07ba5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c07ba5e;
P_0c07ba5e: /* original 8902, guest PC 0x0c07ba5e */
if(!s->budget--) { s->failed_pc=0x0c07ba5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba66; }
goto P_0c07ba60;
P_0c07ba60: /* original d145, guest PC 0x0c07ba60 */
if(!s->budget--) { s->failed_pc=0x0c07ba60u; return 0; }
r[1]=read(ram,0x0c07bb78u,4);
goto P_0c07ba62;
P_0c07ba62: /* original 410b, guest PC 0x0c07ba62 */
if(!s->budget--) { s->failed_pc=0x0c07ba62u; return 0; }
target=r[1];
r[16]=0x0c07ba66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba66u) { target=s->pc; goto dispatch; }
goto P_0c07ba66;
P_0c07ba64: /* original 0009, guest PC 0x0c07ba64 */
if(!s->budget--) { s->failed_pc=0x0c07ba64u; return 0; }
goto P_0c07ba66;
P_0c07ba66: /* original 50fd, guest PC 0x0c07ba66 */
if(!s->budget--) { s->failed_pc=0x0c07ba66u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba68;
P_0c07ba68: /* original c880, guest PC 0x0c07ba68 */
if(!s->budget--) { s->failed_pc=0x0c07ba68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c07ba6a;
P_0c07ba6a: /* original 8902, guest PC 0x0c07ba6a */
if(!s->budget--) { s->failed_pc=0x0c07ba6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba72; }
goto P_0c07ba6c;
P_0c07ba6c: /* original d243, guest PC 0x0c07ba6c */
if(!s->budget--) { s->failed_pc=0x0c07ba6cu; return 0; }
r[2]=read(ram,0x0c07bb7cu,4);
goto P_0c07ba6e;
P_0c07ba6e: /* original 420b, guest PC 0x0c07ba6e */
if(!s->budget--) { s->failed_pc=0x0c07ba6eu; return 0; }
target=r[2];
r[16]=0x0c07ba72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba72u) { target=s->pc; goto dispatch; }
goto P_0c07ba72;
P_0c07ba70: /* original 0009, guest PC 0x0c07ba70 */
if(!s->budget--) { s->failed_pc=0x0c07ba70u; return 0; }
goto P_0c07ba72;
P_0c07ba72: /* original 52fd, guest PC 0x0c07ba72 */
if(!s->budget--) { s->failed_pc=0x0c07ba72u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07ba74;
P_0c07ba74: /* original 9369, guest PC 0x0c07ba74 */
if(!s->budget--) { s->failed_pc=0x0c07ba74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4au,2);
goto P_0c07ba76;
P_0c07ba76: /* original 2238, guest PC 0x0c07ba76 */
if(!s->budget--) { s->failed_pc=0x0c07ba76u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07ba78;
P_0c07ba78: /* original 8902, guest PC 0x0c07ba78 */
if(!s->budget--) { s->failed_pc=0x0c07ba78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba80; }
goto P_0c07ba7a;
P_0c07ba7a: /* original d241, guest PC 0x0c07ba7a */
if(!s->budget--) { s->failed_pc=0x0c07ba7au; return 0; }
r[2]=read(ram,0x0c07bb80u,4);
goto P_0c07ba7c;
P_0c07ba7c: /* original 420b, guest PC 0x0c07ba7c */
if(!s->budget--) { s->failed_pc=0x0c07ba7cu; return 0; }
target=r[2];
r[16]=0x0c07ba80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba80u) { target=s->pc; goto dispatch; }
goto P_0c07ba80;
P_0c07ba7e: /* original 0009, guest PC 0x0c07ba7e */
if(!s->budget--) { s->failed_pc=0x0c07ba7eu; return 0; }
goto P_0c07ba80;
P_0c07ba80: /* original 51fd, guest PC 0x0c07ba80 */
if(!s->budget--) { s->failed_pc=0x0c07ba80u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c07ba82;
P_0c07ba82: /* original 9363, guest PC 0x0c07ba82 */
if(!s->budget--) { s->failed_pc=0x0c07ba82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4cu,2);
goto P_0c07ba84;
P_0c07ba84: /* original 2138, guest PC 0x0c07ba84 */
if(!s->budget--) { s->failed_pc=0x0c07ba84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07ba86;
P_0c07ba86: /* original 8902, guest PC 0x0c07ba86 */
if(!s->budget--) { s->failed_pc=0x0c07ba86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba8e; }
goto P_0c07ba88;
P_0c07ba88: /* original d23e, guest PC 0x0c07ba88 */
if(!s->budget--) { s->failed_pc=0x0c07ba88u; return 0; }
r[2]=read(ram,0x0c07bb84u,4);
goto P_0c07ba8a;
P_0c07ba8a: /* original 420b, guest PC 0x0c07ba8a */
if(!s->budget--) { s->failed_pc=0x0c07ba8au; return 0; }
target=r[2];
r[16]=0x0c07ba8eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba8eu) { target=s->pc; goto dispatch; }
goto P_0c07ba8e;
P_0c07ba8c: /* original 0009, guest PC 0x0c07ba8c */
if(!s->budget--) { s->failed_pc=0x0c07ba8cu; return 0; }
goto P_0c07ba8e;
P_0c07ba8e: /* original 50fd, guest PC 0x0c07ba8e */
if(!s->budget--) { s->failed_pc=0x0c07ba8eu; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba90;
P_0c07ba90: /* original c801, guest PC 0x0c07ba90 */
if(!s->budget--) { s->failed_pc=0x0c07ba90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07ba92;
P_0c07ba92: /* original 8905, guest PC 0x0c07ba92 */
if(!s->budget--) { s->failed_pc=0x0c07ba92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07baa0; }
goto P_0c07ba94;
P_0c07ba94: /* original d13c, guest PC 0x0c07ba94 */
if(!s->budget--) { s->failed_pc=0x0c07ba94u; return 0; }
r[1]=read(ram,0x0c07bb88u,4);
goto P_0c07ba96;
P_0c07ba96: /* original 410b, guest PC 0x0c07ba96 */
if(!s->budget--) { s->failed_pc=0x0c07ba96u; return 0; }
target=r[1];
r[16]=0x0c07ba9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba9au) { target=s->pc; goto dispatch; }
goto P_0c07ba9a;
P_0c07ba98: /* original 0009, guest PC 0x0c07ba98 */
if(!s->budget--) { s->failed_pc=0x0c07ba98u; return 0; }
goto P_0c07ba9a;
P_0c07ba9a: /* original 53fc, guest PC 0x0c07ba9a */
if(!s->budget--) { s->failed_pc=0x0c07ba9au; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07ba9c;
P_0c07ba9c: /* original 230b, guest PC 0x0c07ba9c */
if(!s->budget--) { s->failed_pc=0x0c07ba9cu; return 0; }
r[3]|=r[0];
goto P_0c07ba9e;
P_0c07ba9e: /* original 1f3c, guest PC 0x0c07ba9e */
if(!s->budget--) { s->failed_pc=0x0c07ba9eu; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07baa0;
P_0c07baa0: /* original 53fd, guest PC 0x0c07baa0 */
if(!s->budget--) { s->failed_pc=0x0c07baa0u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07baa2;
P_0c07baa2: /* original ee00, guest PC 0x0c07baa2 */
if(!s->budget--) { s->failed_pc=0x0c07baa2u; return 0; }
r[14]=0x00000000u;
goto P_0c07baa4;
P_0c07baa4: /* original 9453, guest PC 0x0c07baa4 */
if(!s->budget--) { s->failed_pc=0x0c07baa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4eu,2);
goto P_0c07baa6;
P_0c07baa6: /* original 52fc, guest PC 0x0c07baa6 */
if(!s->budget--) { s->failed_pc=0x0c07baa6u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c07baa8;
P_0c07baa8: /* original 2439, guest PC 0x0c07baa8 */
if(!s->budget--) { s->failed_pc=0x0c07baa8u; return 0; }
r[4]&=r[3];
goto P_0c07baaa;
P_0c07baaa: /* original 242b, guest PC 0x0c07baaa */
if(!s->budget--) { s->failed_pc=0x0c07baaau; return 0; }
r[4]|=r[2];
goto P_0c07baac;
P_0c07baac: /* original 6043, guest PC 0x0c07baac */
if(!s->budget--) { s->failed_pc=0x0c07baacu; return 0; }
r[0]=r[4];
goto P_0c07baae;
P_0c07baae: /* original 1f4c, guest PC 0x0c07baae */
if(!s->budget--) { s->failed_pc=0x0c07baaeu; return 0; }
write(ram,r[15]+48,r[4],4);
goto P_0c07bab0;
P_0c07bab0: /* original d330, guest PC 0x0c07bab0 */
if(!s->budget--) { s->failed_pc=0x0c07bab0u; return 0; }
r[3]=read(ram,0x0c07bb74u,4);
goto P_0c07bab2;
P_0c07bab2: /* original c904, guest PC 0x0c07bab2 */
if(!s->budget--) { s->failed_pc=0x0c07bab2u; return 0; }
r[0]&=4u;
goto P_0c07bab4;
P_0c07bab4: /* original 52d2, guest PC 0x0c07bab4 */
if(!s->budget--) { s->failed_pc=0x0c07bab4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c07bab6;
P_0c07bab6: /* original 2238, guest PC 0x0c07bab6 */
if(!s->budget--) { s->failed_pc=0x0c07bab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07bab8;
P_0c07bab8: /* original 8f02, guest PC 0x0c07bab8 */
if(!s->budget--) { s->failed_pc=0x0c07bab8u; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(!cond) { goto P_0c07bac0; }
goto P_0c07babc;
P_0c07baba: /* original 6c03, guest PC 0x0c07baba */
if(!s->budget--) { s->failed_pc=0x0c07babau; return 0; }
r[12]=r[0];
goto P_0c07babc;
P_0c07babc: /* original a408, guest PC 0x0c07babc */
if(!s->budget--) { s->failed_pc=0x0c07babcu; return 0; }
goto P_0c07c2d0;
P_0c07babe: /* original 0009, guest PC 0x0c07babe */
if(!s->budget--) { s->failed_pc=0x0c07babeu; return 0; }
goto P_0c07bac0;
P_0c07bac0: /* original 2cc8, guest PC 0x0c07bac0 */
if(!s->budget--) { s->failed_pc=0x0c07bac0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07bac2;
P_0c07bac2: /* original 8b01, guest PC 0x0c07bac2 */
if(!s->budget--) { s->failed_pc=0x0c07bac2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bac8; }
goto P_0c07bac4;
P_0c07bac4: /* original a415, guest PC 0x0c07bac4 */
if(!s->budget--) { s->failed_pc=0x0c07bac4u; return 0; }
goto P_0c07c2f2;
P_0c07bac6: /* original 0009, guest PC 0x0c07bac6 */
if(!s->budget--) { s->failed_pc=0x0c07bac6u; return 0; }
goto P_0c07bac8;
P_0c07bac8: /* original d231, guest PC 0x0c07bac8 */
if(!s->budget--) { s->failed_pc=0x0c07bac8u; return 0; }
r[2]=read(ram,0x0c07bb90u,4);
goto P_0c07baca;
P_0c07baca: /* original e026, guest PC 0x0c07baca */
if(!s->budget--) { s->failed_pc=0x0c07bacau; return 0; }
r[0]=0x00000026u;
goto P_0c07bacc;
P_0c07bacc: /* original dd2f, guest PC 0x0c07bacc */
if(!s->budget--) { s->failed_pc=0x0c07baccu; return 0; }
r[13]=read(ram,0x0c07bb8cu,4);
goto P_0c07bace;
P_0c07bace: /* original e553, guest PC 0x0c07bace */
if(!s->budget--) { s->failed_pc=0x0c07baceu; return 0; }
r[5]=0x00000053u;
goto P_0c07bad0;
P_0c07bad0: /* original 2f22, guest PC 0x0c07bad0 */
if(!s->budget--) { s->failed_pc=0x0c07bad0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07bad2;
P_0c07bad2: /* original e209, guest PC 0x0c07bad2 */
if(!s->budget--) { s->failed_pc=0x0c07bad2u; return 0; }
r[2]=0x00000009u;
goto P_0c07bad4;
P_0c07bad4: /* original 7d2c, guest PC 0x0c07bad4 */
if(!s->budget--) { s->failed_pc=0x0c07bad4u; return 0; }
r[13]+=0x0000002cu;
goto P_0c07bad6;
P_0c07bad6: /* original 0d25, guest PC 0x0c07bad6 */
if(!s->budget--) { s->failed_pc=0x0c07bad6u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07bad8;
P_0c07bad8: /* original e022, guest PC 0x0c07bad8 */
if(!s->budget--) { s->failed_pc=0x0c07bad8u; return 0; }
r[0]=0x00000022u;
goto P_0c07bada;
P_0c07bada: /* original 01dd, guest PC 0x0c07bada */
if(!s->budget--) { s->failed_pc=0x0c07badau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07badc;
P_0c07badc: /* original e202, guest PC 0x0c07badc */
if(!s->budget--) { s->failed_pc=0x0c07badcu; return 0; }
r[2]=0x00000002u;
goto P_0c07bade;
P_0c07bade: /* original 212b, guest PC 0x0c07bade */
if(!s->budget--) { s->failed_pc=0x0c07badeu; return 0; }
r[1]|=r[2];
goto P_0c07bae0;
P_0c07bae0: /* original 0d15, guest PC 0x0c07bae0 */
if(!s->budget--) { s->failed_pc=0x0c07bae0u; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c07bae2;
P_0c07bae2: /* original d12c, guest PC 0x0c07bae2 */
if(!s->budget--) { s->failed_pc=0x0c07bae2u; return 0; }
r[1]=read(ram,0x0c07bb94u,4);
goto P_0c07bae4;
P_0c07bae4: /* original 410b, guest PC 0x0c07bae4 */
if(!s->budget--) { s->failed_pc=0x0c07bae4u; return 0; }
target=r[1];
r[16]=0x0c07bae8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bae8u) { target=s->pc; goto dispatch; }
goto P_0c07bae8;
P_0c07bae6: /* original 64d3, guest PC 0x0c07bae6 */
if(!s->budget--) { s->failed_pc=0x0c07bae6u; return 0; }
r[4]=r[13];
goto P_0c07bae8;
P_0c07bae8: /* original 9332, guest PC 0x0c07bae8 */
if(!s->budget--) { s->failed_pc=0x0c07bae8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb50u,2);
goto P_0c07baea;
P_0c07baea: /* original 33fc, guest PC 0x0c07baea */
if(!s->budget--) { s->failed_pc=0x0c07baeau; return 0; }
r[3]+=r[15];
goto P_0c07baec;
P_0c07baec: /* original 1f31, guest PC 0x0c07baec */
if(!s->budget--) { s->failed_pc=0x0c07baecu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07baee;
P_0c07baee: /* original 62f2, guest PC 0x0c07baee */
if(!s->budget--) { s->failed_pc=0x0c07baeeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07baf0;
P_0c07baf0: /* original 902f, guest PC 0x0c07baf0 */
if(!s->budget--) { s->failed_pc=0x0c07baf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb52u,2);
goto P_0c07baf2;
P_0c07baf2: /* original 012d, guest PC 0x0c07baf2 */
if(!s->budget--) { s->failed_pc=0x0c07baf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07baf4;
P_0c07baf4: /* original 611d, guest PC 0x0c07baf4 */
if(!s->budget--) { s->failed_pc=0x0c07baf4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07baf6;
P_0c07baf6: /* original 2312, guest PC 0x0c07baf6 */
if(!s->budget--) { s->failed_pc=0x0c07baf6u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07baf8;
P_0c07baf8: /* original 902c, guest PC 0x0c07baf8 */
if(!s->budget--) { s->failed_pc=0x0c07baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb54u,2);
goto P_0c07bafa;
P_0c07bafa: /* original 63f2, guest PC 0x0c07bafa */
if(!s->budget--) { s->failed_pc=0x0c07bafau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bafc;
P_0c07bafc: /* original 54f1, guest PC 0x0c07bafc */
if(!s->budget--) { s->failed_pc=0x0c07bafcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bafe;
P_0c07bafe: /* original 023d, guest PC 0x0c07bafe */
if(!s->budget--) { s->failed_pc=0x0c07bafeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb00;
P_0c07bb00: /* original 7408, guest PC 0x0c07bb00 */
if(!s->budget--) { s->failed_pc=0x0c07bb00u; return 0; }
r[4]+=0x00000008u;
goto P_0c07bb02;
P_0c07bb02: /* original 622d, guest PC 0x0c07bb02 */
if(!s->budget--) { s->failed_pc=0x0c07bb02u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb04;
P_0c07bb04: /* original 2422, guest PC 0x0c07bb04 */
if(!s->budget--) { s->failed_pc=0x0c07bb04u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c07bb06;
P_0c07bb06: /* original 9026, guest PC 0x0c07bb06 */
if(!s->budget--) { s->failed_pc=0x0c07bb06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb56u,2);
goto P_0c07bb08;
P_0c07bb08: /* original 62f2, guest PC 0x0c07bb08 */
if(!s->budget--) { s->failed_pc=0x0c07bb08u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bb0a;
P_0c07bb0a: /* original 53f1, guest PC 0x0c07bb0a */
if(!s->budget--) { s->failed_pc=0x0c07bb0au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bb0c;
P_0c07bb0c: /* original 012d, guest PC 0x0c07bb0c */
if(!s->budget--) { s->failed_pc=0x0c07bb0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07bb0e;
P_0c07bb0e: /* original 611d, guest PC 0x0c07bb0e */
if(!s->budget--) { s->failed_pc=0x0c07bb0eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c07bb10;
P_0c07bb10: /* original 1311, guest PC 0x0c07bb10 */
if(!s->budget--) { s->failed_pc=0x0c07bb10u; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c07bb12;
P_0c07bb12: /* original 9021, guest PC 0x0c07bb12 */
if(!s->budget--) { s->failed_pc=0x0c07bb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb58u,2);
goto P_0c07bb14;
P_0c07bb14: /* original 63f2, guest PC 0x0c07bb14 */
if(!s->budget--) { s->failed_pc=0x0c07bb14u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb16;
P_0c07bb16: /* original 023d, guest PC 0x0c07bb16 */
if(!s->budget--) { s->failed_pc=0x0c07bb16u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb18;
P_0c07bb18: /* original 622d, guest PC 0x0c07bb18 */
if(!s->budget--) { s->failed_pc=0x0c07bb18u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb1a;
P_0c07bb1a: /* original 1421, guest PC 0x0c07bb1a */
if(!s->budget--) { s->failed_pc=0x0c07bb1au; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c07bb1c;
P_0c07bb1c: /* original 63f2, guest PC 0x0c07bb1c */
if(!s->budget--) { s->failed_pc=0x0c07bb1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb1e;
P_0c07bb1e: /* original 901c, guest PC 0x0c07bb1e */
if(!s->budget--) { s->failed_pc=0x0c07bb1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5au,2);
goto P_0c07bb20;
P_0c07bb20: /* original 023d, guest PC 0x0c07bb20 */
if(!s->budget--) { s->failed_pc=0x0c07bb20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb22;
P_0c07bb22: /* original e07c, guest PC 0x0c07bb22 */
if(!s->budget--) { s->failed_pc=0x0c07bb22u; return 0; }
r[0]=0x0000007cu;
goto P_0c07bb24;
P_0c07bb24: /* original 622d, guest PC 0x0c07bb24 */
if(!s->budget--) { s->failed_pc=0x0c07bb24u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb26;
P_0c07bb26: /* original 0f26, guest PC 0x0c07bb26 */
if(!s->budget--) { s->failed_pc=0x0c07bb26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb28;
P_0c07bb28: /* original 9018, guest PC 0x0c07bb28 */
if(!s->budget--) { s->failed_pc=0x0c07bb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5cu,2);
goto P_0c07bb2a;
P_0c07bb2a: /* original 63f2, guest PC 0x0c07bb2a */
if(!s->budget--) { s->failed_pc=0x0c07bb2au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb2c;
P_0c07bb2c: /* original 023d, guest PC 0x0c07bb2c */
if(!s->budget--) { s->failed_pc=0x0c07bb2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb2e;
P_0c07bb2e: /* original 9016, guest PC 0x0c07bb2e */
if(!s->budget--) { s->failed_pc=0x0c07bb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5eu,2);
goto P_0c07bb30;
P_0c07bb30: /* original 622d, guest PC 0x0c07bb30 */
if(!s->budget--) { s->failed_pc=0x0c07bb30u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb32;
P_0c07bb32: /* original 0f26, guest PC 0x0c07bb32 */
if(!s->budget--) { s->failed_pc=0x0c07bb32u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb34;
P_0c07bb34: /* original 9116, guest PC 0x0c07bb34 */
if(!s->budget--) { s->failed_pc=0x0c07bb34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb64u,2);
goto P_0c07bb36;
P_0c07bb36: /* original 60f2, guest PC 0x0c07bb36 */
if(!s->budget--) { s->failed_pc=0x0c07bb36u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07bb38;
P_0c07bb38: /* original d918, guest PC 0x0c07bb38 */
if(!s->budget--) { s->failed_pc=0x0c07bb38u; return 0; }
r[9]=read(ram,0x0c07bb9cu,4);
goto P_0c07bb3a;
P_0c07bb3a: /* original 001c, guest PC 0x0c07bb3a */
if(!s->budget--) { s->failed_pc=0x0c07bb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bb3c;
P_0c07bb3c: /* original 9a10, guest PC 0x0c07bb3c */
if(!s->budget--) { s->failed_pc=0x0c07bb3cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb60u,2);
goto P_0c07bb3e;
P_0c07bb3e: /* original 9c10, guest PC 0x0c07bb3e */
if(!s->budget--) { s->failed_pc=0x0c07bb3eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb62u,2);
goto P_0c07bb40;
P_0c07bb40: /* original 8802, guest PC 0x0c07bb40 */
if(!s->budget--) { s->failed_pc=0x0c07bb40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07bb42;
P_0c07bb42: /* original d815, guest PC 0x0c07bb42 */
if(!s->budget--) { s->failed_pc=0x0c07bb42u; return 0; }
r[8]=read(ram,0x0c07bb98u,4);
goto P_0c07bb44;
P_0c07bb44: /* original a02c, guest PC 0x0c07bb44 */
if(!s->budget--) { s->failed_pc=0x0c07bb44u; return 0; }
goto P_0c07bba0;
P_0c07bb46: /* original 0009, guest PC 0x0c07bb46 */
if(!s->budget--) { s->failed_pc=0x0c07bb46u; return 0; }
return vf3_matrix_family(0x0c07bb48u,s,ram);
P_0c07bba0: /* original 8b3a, guest PC 0x0c07bba0 */
if(!s->budget--) { s->failed_pc=0x0c07bba0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bc18; }
goto P_0c07bba2;
P_0c07bba2: /* original 94aa, guest PC 0x0c07bba2 */
if(!s->budget--) { s->failed_pc=0x0c07bba2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bba4;
P_0c07bba4: /* original 66d3, guest PC 0x0c07bba4 */
if(!s->budget--) { s->failed_pc=0x0c07bba4u; return 0; }
r[6]=r[13];
goto P_0c07bba6;
P_0c07bba6: /* original 2fe6, guest PC 0x0c07bba6 */
if(!s->budget--) { s->failed_pc=0x0c07bba6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bba8;
P_0c07bba8: /* original e700, guest PC 0x0c07bba8 */
if(!s->budget--) { s->failed_pc=0x0c07bba8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbaa;
P_0c07bbaa: /* original d258, guest PC 0x0c07bbaa */
if(!s->budget--) { s->failed_pc=0x0c07bbaau; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbac;
P_0c07bbac: /* original 420b, guest PC 0x0c07bbac */
if(!s->budget--) { s->failed_pc=0x0c07bbacu; return 0; }
target=r[2];
r[16]=0x0c07bbb0u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbb0u) { target=s->pc; goto dispatch; }
goto P_0c07bbb0;
P_0c07bbae: /* original 65c3, guest PC 0x0c07bbae */
if(!s->budget--) { s->failed_pc=0x0c07bbaeu; return 0; }
r[5]=r[12];
goto P_0c07bbb0;
P_0c07bbb0: /* original 7f04, guest PC 0x0c07bbb0 */
if(!s->budget--) { s->failed_pc=0x0c07bbb0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbb2;
P_0c07bbb2: /* original 90a3, guest PC 0x0c07bbb2 */
if(!s->budget--) { s->failed_pc=0x0c07bbb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbb4;
P_0c07bbb4: /* original 63f2, guest PC 0x0c07bbb4 */
if(!s->budget--) { s->failed_pc=0x0c07bbb4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bbb6;
P_0c07bbb6: /* original 023c, guest PC 0x0c07bbb6 */
if(!s->budget--) { s->failed_pc=0x0c07bbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbb8;
P_0c07bbb8: /* original 7001, guest PC 0x0c07bbb8 */
if(!s->budget--) { s->failed_pc=0x0c07bbb8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbba;
P_0c07bbba: /* original 013c, guest PC 0x0c07bbba */
if(!s->budget--) { s->failed_pc=0x0c07bbbau; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbbc;
P_0c07bbbc: /* original 3210, guest PC 0x0c07bbbc */
if(!s->budget--) { s->failed_pc=0x0c07bbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bbbe;
P_0c07bbbe: /* original 8d0f, guest PC 0x0c07bbbe */
if(!s->budget--) { s->failed_pc=0x0c07bbbeu; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bbe0; }
goto P_0c07bbc2;
P_0c07bbc0: /* original 64a3, guest PC 0x0c07bbc0 */
if(!s->budget--) { s->failed_pc=0x0c07bbc0u; return 0; }
r[4]=r[10];
goto P_0c07bbc2;
P_0c07bbc2: /* original 2fe6, guest PC 0x0c07bbc2 */
if(!s->budget--) { s->failed_pc=0x0c07bbc2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bbc4;
P_0c07bbc4: /* original e700, guest PC 0x0c07bbc4 */
if(!s->budget--) { s->failed_pc=0x0c07bbc4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbc6;
P_0c07bbc6: /* original 5af1, guest PC 0x0c07bbc6 */
if(!s->budget--) { s->failed_pc=0x0c07bbc6u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c07bbc8;
P_0c07bbc8: /* original 66d3, guest PC 0x0c07bbc8 */
if(!s->budget--) { s->failed_pc=0x0c07bbc8u; return 0; }
r[6]=r[13];
goto P_0c07bbca;
P_0c07bbca: /* original 9098, guest PC 0x0c07bbca */
if(!s->budget--) { s->failed_pc=0x0c07bbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bbcc;
P_0c07bbcc: /* original d34f, guest PC 0x0c07bbcc */
if(!s->budget--) { s->failed_pc=0x0c07bbccu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbce;
P_0c07bbce: /* original 00ac, guest PC 0x0c07bbce */
if(!s->budget--) { s->failed_pc=0x0c07bbceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbd0;
P_0c07bbd0: /* original 4008, guest PC 0x0c07bbd0 */
if(!s->budget--) { s->failed_pc=0x0c07bbd0u; return 0; }
r[0]<<=2;
goto P_0c07bbd2;
P_0c07bbd2: /* original 430b, guest PC 0x0c07bbd2 */
if(!s->budget--) { s->failed_pc=0x0c07bbd2u; return 0; }
target=r[3];
r[16]=0x0c07bbd6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbd6u) { target=s->pc; goto dispatch; }
goto P_0c07bbd6;
P_0c07bbd4: /* original 059e, guest PC 0x0c07bbd4 */
if(!s->budget--) { s->failed_pc=0x0c07bbd4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bbd6;
P_0c07bbd6: /* original 9091, guest PC 0x0c07bbd6 */
if(!s->budget--) { s->failed_pc=0x0c07bbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbd8;
P_0c07bbd8: /* original 7f04, guest PC 0x0c07bbd8 */
if(!s->budget--) { s->failed_pc=0x0c07bbd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbda;
P_0c07bbda: /* original 02ac, guest PC 0x0c07bbda */
if(!s->budget--) { s->failed_pc=0x0c07bbdau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbdc;
P_0c07bbdc: /* original 7001, guest PC 0x0c07bbdc */
if(!s->budget--) { s->failed_pc=0x0c07bbdcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbde;
P_0c07bbde: /* original 0a24, guest PC 0x0c07bbde */
if(!s->budget--) { s->failed_pc=0x0c07bbdeu; return 0; }
write(ram,r[10]+r[0],r[2],1);
goto P_0c07bbe0;
P_0c07bbe0: /* original 2fb6, guest PC 0x0c07bbe0 */
if(!s->budget--) { s->failed_pc=0x0c07bbe0u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bbe2;
P_0c07bbe2: /* original 66d3, guest PC 0x0c07bbe2 */
if(!s->budget--) { s->failed_pc=0x0c07bbe2u; return 0; }
r[6]=r[13];
goto P_0c07bbe4;
P_0c07bbe4: /* original 2fe6, guest PC 0x0c07bbe4 */
if(!s->budget--) { s->failed_pc=0x0c07bbe4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bbe6;
P_0c07bbe6: /* original e700, guest PC 0x0c07bbe6 */
if(!s->budget--) { s->failed_pc=0x0c07bbe6u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbe8;
P_0c07bbe8: /* original 948a, guest PC 0x0c07bbe8 */
if(!s->budget--) { s->failed_pc=0x0c07bbe8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bbea;
P_0c07bbea: /* original 480b, guest PC 0x0c07bbea */
if(!s->budget--) { s->failed_pc=0x0c07bbeau; return 0; }
target=r[8];
r[16]=0x0c07bbeeu;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbeeu) { target=s->pc; goto dispatch; }
goto P_0c07bbee;
P_0c07bbec: /* original 65c3, guest PC 0x0c07bbec */
if(!s->budget--) { s->failed_pc=0x0c07bbecu; return 0; }
r[5]=r[12];
goto P_0c07bbee;
P_0c07bbee: /* original 2fb6, guest PC 0x0c07bbee */
if(!s->budget--) { s->failed_pc=0x0c07bbeeu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bbf0;
P_0c07bbf0: /* original 66d3, guest PC 0x0c07bbf0 */
if(!s->budget--) { s->failed_pc=0x0c07bbf0u; return 0; }
r[6]=r[13];
goto P_0c07bbf2;
P_0c07bbf2: /* original 2fe6, guest PC 0x0c07bbf2 */
if(!s->budget--) { s->failed_pc=0x0c07bbf2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bbf4;
P_0c07bbf4: /* original e700, guest PC 0x0c07bbf4 */
if(!s->budget--) { s->failed_pc=0x0c07bbf4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbf6;
P_0c07bbf6: /* original 9484, guest PC 0x0c07bbf6 */
if(!s->budget--) { s->failed_pc=0x0c07bbf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bbf8;
P_0c07bbf8: /* original 480b, guest PC 0x0c07bbf8 */
if(!s->budget--) { s->failed_pc=0x0c07bbf8u; return 0; }
target=r[8];
r[16]=0x0c07bbfcu;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbfcu) { target=s->pc; goto dispatch; }
goto P_0c07bbfc;
P_0c07bbfa: /* original 559a, guest PC 0x0c07bbfa */
if(!s->budget--) { s->failed_pc=0x0c07bbfau; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bbfc;
P_0c07bbfc: /* original 2fb6, guest PC 0x0c07bbfc */
if(!s->budget--) { s->failed_pc=0x0c07bbfcu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bbfe;
P_0c07bbfe: /* original e700, guest PC 0x0c07bbfe */
if(!s->budget--) { s->failed_pc=0x0c07bbfeu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc00;
P_0c07bc00: /* original 2fe6, guest PC 0x0c07bc00 */
if(!s->budget--) { s->failed_pc=0x0c07bc00u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc02;
P_0c07bc02: /* original 66d3, guest PC 0x0c07bc02 */
if(!s->budget--) { s->failed_pc=0x0c07bc02u; return 0; }
r[6]=r[13];
goto P_0c07bc04;
P_0c07bc04: /* original 55f6, guest PC 0x0c07bc04 */
if(!s->budget--) { s->failed_pc=0x0c07bc04u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c07bc06;
P_0c07bc06: /* original 907d, guest PC 0x0c07bc06 */
if(!s->budget--) { s->failed_pc=0x0c07bc06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc08;
P_0c07bc08: /* original 947d, guest PC 0x0c07bc08 */
if(!s->budget--) { s->failed_pc=0x0c07bc08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc0a;
P_0c07bc0a: /* original 055c, guest PC 0x0c07bc0a */
if(!s->budget--) { s->failed_pc=0x0c07bc0au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc0c;
P_0c07bc0c: /* original 4508, guest PC 0x0c07bc0c */
if(!s->budget--) { s->failed_pc=0x0c07bc0cu; return 0; }
r[5]<<=2;
goto P_0c07bc0e;
P_0c07bc0e: /* original 359c, guest PC 0x0c07bc0e */
if(!s->budget--) { s->failed_pc=0x0c07bc0eu; return 0; }
r[5]+=r[9];
goto P_0c07bc10;
P_0c07bc10: /* original 480b, guest PC 0x0c07bc10 */
if(!s->budget--) { s->failed_pc=0x0c07bc10u; return 0; }
target=r[8];
r[16]=0x0c07bc14u;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc14u) { target=s->pc; goto dispatch; }
goto P_0c07bc14;
P_0c07bc12: /* original 5551, guest PC 0x0c07bc12 */
if(!s->budget--) { s->failed_pc=0x0c07bc12u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc14;
P_0c07bc14: /* original a045, guest PC 0x0c07bc14 */
if(!s->budget--) { s->failed_pc=0x0c07bc14u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bca2;
P_0c07bc16: /* original 7f18, guest PC 0x0c07bc16 */
if(!s->budget--) { s->failed_pc=0x0c07bc16u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bc18;
P_0c07bc18: /* original 9472, guest PC 0x0c07bc18 */
if(!s->budget--) { s->failed_pc=0x0c07bc18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bc1a;
P_0c07bc1a: /* original 66d3, guest PC 0x0c07bc1a */
if(!s->budget--) { s->failed_pc=0x0c07bc1au; return 0; }
r[6]=r[13];
goto P_0c07bc1c;
P_0c07bc1c: /* original 2fe6, guest PC 0x0c07bc1c */
if(!s->budget--) { s->failed_pc=0x0c07bc1cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc1e;
P_0c07bc1e: /* original e700, guest PC 0x0c07bc1e */
if(!s->budget--) { s->failed_pc=0x0c07bc1eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc20;
P_0c07bc20: /* original d23a, guest PC 0x0c07bc20 */
if(!s->budget--) { s->failed_pc=0x0c07bc20u; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc22;
P_0c07bc22: /* original 420b, guest PC 0x0c07bc22 */
if(!s->budget--) { s->failed_pc=0x0c07bc22u; return 0; }
target=r[2];
r[16]=0x0c07bc26u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc26u) { target=s->pc; goto dispatch; }
goto P_0c07bc26;
P_0c07bc24: /* original 65c3, guest PC 0x0c07bc24 */
if(!s->budget--) { s->failed_pc=0x0c07bc24u; return 0; }
r[5]=r[12];
goto P_0c07bc26;
P_0c07bc26: /* original 946c, guest PC 0x0c07bc26 */
if(!s->budget--) { s->failed_pc=0x0c07bc26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bc28;
P_0c07bc28: /* original 66d3, guest PC 0x0c07bc28 */
if(!s->budget--) { s->failed_pc=0x0c07bc28u; return 0; }
r[6]=r[13];
goto P_0c07bc2a;
P_0c07bc2a: /* original 2fe6, guest PC 0x0c07bc2a */
if(!s->budget--) { s->failed_pc=0x0c07bc2au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc2c;
P_0c07bc2c: /* original e700, guest PC 0x0c07bc2c */
if(!s->budget--) { s->failed_pc=0x0c07bc2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc2e;
P_0c07bc2e: /* original d337, guest PC 0x0c07bc2e */
if(!s->budget--) { s->failed_pc=0x0c07bc2eu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc30;
P_0c07bc30: /* original 430b, guest PC 0x0c07bc30 */
if(!s->budget--) { s->failed_pc=0x0c07bc30u; return 0; }
target=r[3];
r[16]=0x0c07bc34u;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc34u) { target=s->pc; goto dispatch; }
goto P_0c07bc34;
P_0c07bc32: /* original 559a, guest PC 0x0c07bc32 */
if(!s->budget--) { s->failed_pc=0x0c07bc32u; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bc34;
P_0c07bc34: /* original 9467, guest PC 0x0c07bc34 */
if(!s->budget--) { s->failed_pc=0x0c07bc34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc36;
P_0c07bc36: /* original e700, guest PC 0x0c07bc36 */
if(!s->budget--) { s->failed_pc=0x0c07bc36u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc38;
P_0c07bc38: /* original 2fe6, guest PC 0x0c07bc38 */
if(!s->budget--) { s->failed_pc=0x0c07bc38u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc3a;
P_0c07bc3a: /* original 66d3, guest PC 0x0c07bc3a */
if(!s->budget--) { s->failed_pc=0x0c07bc3au; return 0; }
r[6]=r[13];
goto P_0c07bc3c;
P_0c07bc3c: /* original 55f3, guest PC 0x0c07bc3c */
if(!s->budget--) { s->failed_pc=0x0c07bc3cu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07bc3e;
P_0c07bc3e: /* original 9061, guest PC 0x0c07bc3e */
if(!s->budget--) { s->failed_pc=0x0c07bc3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc40;
P_0c07bc40: /* original d332, guest PC 0x0c07bc40 */
if(!s->budget--) { s->failed_pc=0x0c07bc40u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc42;
P_0c07bc42: /* original 055c, guest PC 0x0c07bc42 */
if(!s->budget--) { s->failed_pc=0x0c07bc42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc44;
P_0c07bc44: /* original 4508, guest PC 0x0c07bc44 */
if(!s->budget--) { s->failed_pc=0x0c07bc44u; return 0; }
r[5]<<=2;
goto P_0c07bc46;
P_0c07bc46: /* original 359c, guest PC 0x0c07bc46 */
if(!s->budget--) { s->failed_pc=0x0c07bc46u; return 0; }
r[5]+=r[9];
goto P_0c07bc48;
P_0c07bc48: /* original 430b, guest PC 0x0c07bc48 */
if(!s->budget--) { s->failed_pc=0x0c07bc48u; return 0; }
target=r[3];
r[16]=0x0c07bc4cu;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc4cu) { target=s->pc; goto dispatch; }
goto P_0c07bc4c;
P_0c07bc4a: /* original 5551, guest PC 0x0c07bc4a */
if(!s->budget--) { s->failed_pc=0x0c07bc4au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc4c;
P_0c07bc4c: /* original 2fb6, guest PC 0x0c07bc4c */
if(!s->budget--) { s->failed_pc=0x0c07bc4cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bc4e;
P_0c07bc4e: /* original 66d3, guest PC 0x0c07bc4e */
if(!s->budget--) { s->failed_pc=0x0c07bc4eu; return 0; }
r[6]=r[13];
goto P_0c07bc50;
P_0c07bc50: /* original 2fe6, guest PC 0x0c07bc50 */
if(!s->budget--) { s->failed_pc=0x0c07bc50u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc52;
P_0c07bc52: /* original e700, guest PC 0x0c07bc52 */
if(!s->budget--) { s->failed_pc=0x0c07bc52u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc54;
P_0c07bc54: /* original 9451, guest PC 0x0c07bc54 */
if(!s->budget--) { s->failed_pc=0x0c07bc54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bc56;
P_0c07bc56: /* original 480b, guest PC 0x0c07bc56 */
if(!s->budget--) { s->failed_pc=0x0c07bc56u; return 0; }
target=r[8];
r[16]=0x0c07bc5au;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc5au) { target=s->pc; goto dispatch; }
goto P_0c07bc5a;
P_0c07bc58: /* original 65c3, guest PC 0x0c07bc58 */
if(!s->budget--) { s->failed_pc=0x0c07bc58u; return 0; }
r[5]=r[12];
goto P_0c07bc5a;
P_0c07bc5a: /* original 7f14, guest PC 0x0c07bc5a */
if(!s->budget--) { s->failed_pc=0x0c07bc5au; return 0; }
r[15]+=0x00000014u;
goto P_0c07bc5c;
P_0c07bc5c: /* original 904e, guest PC 0x0c07bc5c */
if(!s->budget--) { s->failed_pc=0x0c07bc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc5e;
P_0c07bc5e: /* original 62f2, guest PC 0x0c07bc5e */
if(!s->budget--) { s->failed_pc=0x0c07bc5eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bc60;
P_0c07bc60: /* original 032c, guest PC 0x0c07bc60 */
if(!s->budget--) { s->failed_pc=0x0c07bc60u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc62;
P_0c07bc62: /* original 7001, guest PC 0x0c07bc62 */
if(!s->budget--) { s->failed_pc=0x0c07bc62u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc64;
P_0c07bc64: /* original 012c, guest PC 0x0c07bc64 */
if(!s->budget--) { s->failed_pc=0x0c07bc64u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc66;
P_0c07bc66: /* original 3310, guest PC 0x0c07bc66 */
if(!s->budget--) { s->failed_pc=0x0c07bc66u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c07bc68;
P_0c07bc68: /* original 8d0f, guest PC 0x0c07bc68 */
if(!s->budget--) { s->failed_pc=0x0c07bc68u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bc8a; }
goto P_0c07bc6c;
P_0c07bc6a: /* original 64a3, guest PC 0x0c07bc6a */
if(!s->budget--) { s->failed_pc=0x0c07bc6au; return 0; }
r[4]=r[10];
goto P_0c07bc6c;
P_0c07bc6c: /* original 2fe6, guest PC 0x0c07bc6c */
if(!s->budget--) { s->failed_pc=0x0c07bc6cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc6e;
P_0c07bc6e: /* original e700, guest PC 0x0c07bc6e */
if(!s->budget--) { s->failed_pc=0x0c07bc6eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc70;
P_0c07bc70: /* original 5cf1, guest PC 0x0c07bc70 */
if(!s->budget--) { s->failed_pc=0x0c07bc70u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07bc72;
P_0c07bc72: /* original 66d3, guest PC 0x0c07bc72 */
if(!s->budget--) { s->failed_pc=0x0c07bc72u; return 0; }
r[6]=r[13];
goto P_0c07bc74;
P_0c07bc74: /* original 9043, guest PC 0x0c07bc74 */
if(!s->budget--) { s->failed_pc=0x0c07bc74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bc76;
P_0c07bc76: /* original d325, guest PC 0x0c07bc76 */
if(!s->budget--) { s->failed_pc=0x0c07bc76u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc78;
P_0c07bc78: /* original 00cc, guest PC 0x0c07bc78 */
if(!s->budget--) { s->failed_pc=0x0c07bc78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc7a;
P_0c07bc7a: /* original 4008, guest PC 0x0c07bc7a */
if(!s->budget--) { s->failed_pc=0x0c07bc7au; return 0; }
r[0]<<=2;
goto P_0c07bc7c;
P_0c07bc7c: /* original 430b, guest PC 0x0c07bc7c */
if(!s->budget--) { s->failed_pc=0x0c07bc7cu; return 0; }
target=r[3];
r[16]=0x0c07bc80u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc80u) { target=s->pc; goto dispatch; }
goto P_0c07bc80;
P_0c07bc7e: /* original 059e, guest PC 0x0c07bc7e */
if(!s->budget--) { s->failed_pc=0x0c07bc7eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc80;
P_0c07bc80: /* original 903c, guest PC 0x0c07bc80 */
if(!s->budget--) { s->failed_pc=0x0c07bc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc82;
P_0c07bc82: /* original 7f04, guest PC 0x0c07bc82 */
if(!s->budget--) { s->failed_pc=0x0c07bc82u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bc84;
P_0c07bc84: /* original 02cc, guest PC 0x0c07bc84 */
if(!s->budget--) { s->failed_pc=0x0c07bc84u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc86;
P_0c07bc86: /* original 7001, guest PC 0x0c07bc86 */
if(!s->budget--) { s->failed_pc=0x0c07bc86u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc88;
P_0c07bc88: /* original 0c24, guest PC 0x0c07bc88 */
if(!s->budget--) { s->failed_pc=0x0c07bc88u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c07bc8a;
P_0c07bc8a: /* original 2fb6, guest PC 0x0c07bc8a */
if(!s->budget--) { s->failed_pc=0x0c07bc8au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bc8c;
P_0c07bc8c: /* original e700, guest PC 0x0c07bc8c */
if(!s->budget--) { s->failed_pc=0x0c07bc8cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc8e;
P_0c07bc8e: /* original 2fe6, guest PC 0x0c07bc8e */
if(!s->budget--) { s->failed_pc=0x0c07bc8eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bc90;
P_0c07bc90: /* original 66d3, guest PC 0x0c07bc90 */
if(!s->budget--) { s->failed_pc=0x0c07bc90u; return 0; }
r[6]=r[13];
goto P_0c07bc92;
P_0c07bc92: /* original 50f2, guest PC 0x0c07bc92 */
if(!s->budget--) { s->failed_pc=0x0c07bc92u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c07bc94;
P_0c07bc94: /* original 9132, guest PC 0x0c07bc94 */
if(!s->budget--) { s->failed_pc=0x0c07bc94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc96;
P_0c07bc96: /* original 001c, guest PC 0x0c07bc96 */
if(!s->budget--) { s->failed_pc=0x0c07bc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bc98;
P_0c07bc98: /* original 4008, guest PC 0x0c07bc98 */
if(!s->budget--) { s->failed_pc=0x0c07bc98u; return 0; }
r[0]<<=2;
goto P_0c07bc9a;
P_0c07bc9a: /* original 059e, guest PC 0x0c07bc9a */
if(!s->budget--) { s->failed_pc=0x0c07bc9au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc9c;
P_0c07bc9c: /* original 480b, guest PC 0x0c07bc9c */
if(!s->budget--) { s->failed_pc=0x0c07bc9cu; return 0; }
target=r[8];
r[16]=0x0c07bca0u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bca0u) { target=s->pc; goto dispatch; }
goto P_0c07bca0;
P_0c07bc9e: /* original 64a3, guest PC 0x0c07bc9e */
if(!s->budget--) { s->failed_pc=0x0c07bc9eu; return 0; }
r[4]=r[10];
goto P_0c07bca0;
P_0c07bca0: /* original 7f08, guest PC 0x0c07bca0 */
if(!s->budget--) { s->failed_pc=0x0c07bca0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bca2;
P_0c07bca2: /* original d31b, guest PC 0x0c07bca2 */
if(!s->budget--) { s->failed_pc=0x0c07bca2u; return 0; }
r[3]=read(ram,0x0c07bd10u,4);
goto P_0c07bca4;
P_0c07bca4: /* original fe8d, guest PC 0x0c07bca4 */
if(!s->budget--) { s->failed_pc=0x0c07bca4u; return 0; }
fr[14]=0;
goto P_0c07bca6;
P_0c07bca6: /* original 6032, guest PC 0x0c07bca6 */
if(!s->budget--) { s->failed_pc=0x0c07bca6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bca8;
P_0c07bca8: /* original c801, guest PC 0x0c07bca8 */
if(!s->budget--) { s->failed_pc=0x0c07bca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07bcaa;
P_0c07bcaa: /* original 8d02, guest PC 0x0c07bcaa */
if(!s->budget--) { s->failed_pc=0x0c07bcaau; return 0; }
cond=r[17]&1u;
r[10]=0x00000064u;
if(cond) { goto P_0c07bcb2; }
goto P_0c07bcae;
P_0c07bcac: /* original ea64, guest PC 0x0c07bcac */
if(!s->budget--) { s->failed_pc=0x0c07bcacu; return 0; }
r[10]=0x00000064u;
goto P_0c07bcae;
P_0c07bcae: /* original a212, guest PC 0x0c07bcae */
if(!s->budget--) { s->failed_pc=0x0c07bcaeu; return 0; }
goto P_0c07c0d6;
P_0c07bcb0: /* original 0009, guest PC 0x0c07bcb0 */
if(!s->budget--) { s->failed_pc=0x0c07bcb0u; return 0; }
goto P_0c07bcb2;
P_0c07bcb2: /* original 6193, guest PC 0x0c07bcb2 */
if(!s->budget--) { s->failed_pc=0x0c07bcb2u; return 0; }
r[1]=r[9];
goto P_0c07bcb4;
P_0c07bcb4: /* original 1fe8, guest PC 0x0c07bcb4 */
if(!s->budget--) { s->failed_pc=0x0c07bcb4u; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c07bcb6;
P_0c07bcb6: /* original 9227, guest PC 0x0c07bcb6 */
if(!s->budget--) { s->failed_pc=0x0c07bcb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcb8;
P_0c07bcb8: /* original 32fc, guest PC 0x0c07bcb8 */
if(!s->budget--) { s->failed_pc=0x0c07bcb8u; return 0; }
r[2]+=r[15];
goto P_0c07bcba;
P_0c07bcba: /* original 1f2f, guest PC 0x0c07bcba */
if(!s->budget--) { s->failed_pc=0x0c07bcbau; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c07bcbc;
P_0c07bcbc: /* original 1f1a, guest PC 0x0c07bcbc */
if(!s->budget--) { s->failed_pc=0x0c07bcbcu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07bcbe;
P_0c07bcbe: /* original a196, guest PC 0x0c07bcbe */
if(!s->budget--) { s->failed_pc=0x0c07bcbeu; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bfee;
P_0c07bcc0: /* original ff9d, guest PC 0x0c07bcc0 */
if(!s->budget--) { s->failed_pc=0x0c07bcc0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bcc2;
P_0c07bcc2: /* original e122, guest PC 0x0c07bcc2 */
if(!s->budget--) { s->failed_pc=0x0c07bcc2u; return 0; }
r[1]=0x00000022u;
goto P_0c07bcc4;
P_0c07bcc4: /* original 53f8, guest PC 0x0c07bcc4 */
if(!s->budget--) { s->failed_pc=0x0c07bcc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07bcc6;
P_0c07bcc6: /* original e007, guest PC 0x0c07bcc6 */
if(!s->budget--) { s->failed_pc=0x0c07bcc6u; return 0; }
r[0]=0x00000007u;
goto P_0c07bcc8;
P_0c07bcc8: /* original 6ce3, guest PC 0x0c07bcc8 */
if(!s->budget--) { s->failed_pc=0x0c07bcc8u; return 0; }
r[12]=r[14];
goto P_0c07bcca;
P_0c07bcca: /* original 4308, guest PC 0x0c07bcca */
if(!s->budget--) { s->failed_pc=0x0c07bccau; return 0; }
r[3]<<=2;
goto P_0c07bccc;
P_0c07bccc: /* original 4300, guest PC 0x0c07bccc */
if(!s->budget--) { s->failed_pc=0x0c07bcccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bcce;
P_0c07bcce: /* original 1f32, guest PC 0x0c07bcce */
if(!s->budget--) { s->failed_pc=0x0c07bcceu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07bcd0;
P_0c07bcd0: /* original 921a, guest PC 0x0c07bcd0 */
if(!s->budget--) { s->failed_pc=0x0c07bcd0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcd2;
P_0c07bcd2: /* original 32fc, guest PC 0x0c07bcd2 */
if(!s->budget--) { s->failed_pc=0x0c07bcd2u; return 0; }
r[2]+=r[15];
goto P_0c07bcd4;
P_0c07bcd4: /* original 332c, guest PC 0x0c07bcd4 */
if(!s->budget--) { s->failed_pc=0x0c07bcd4u; return 0; }
r[3]+=r[2];
goto P_0c07bcd6;
P_0c07bcd6: /* original 1f34, guest PC 0x0c07bcd6 */
if(!s->budget--) { s->failed_pc=0x0c07bcd6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07bcd8;
P_0c07bcd8: /* original 1f39, guest PC 0x0c07bcd8 */
if(!s->budget--) { s->failed_pc=0x0c07bcd8u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bcda;
P_0c07bcda: /* original 1f1b, guest PC 0x0c07bcda */
if(!s->budget--) { s->failed_pc=0x0c07bcdau; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07bcdc;
P_0c07bcdc: /* original e11e, guest PC 0x0c07bcdc */
if(!s->budget--) { s->failed_pc=0x0c07bcdcu; return 0; }
r[1]=0x0000001eu;
goto P_0c07bcde;
P_0c07bcde: /* original 1f17, guest PC 0x0c07bcde */
if(!s->budget--) { s->failed_pc=0x0c07bcdeu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bce0;
P_0c07bce0: /* original 55f4, guest PC 0x0c07bce0 */
if(!s->budget--) { s->failed_pc=0x0c07bce0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07bce2;
P_0c07bce2: /* original 1f54, guest PC 0x0c07bce2 */
if(!s->budget--) { s->failed_pc=0x0c07bce2u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bce4;
P_0c07bce4: /* original 51f8, guest PC 0x0c07bce4 */
if(!s->budget--) { s->failed_pc=0x0c07bce4u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bce6;
P_0c07bce6: /* original 4100, guest PC 0x0c07bce6 */
if(!s->budget--) { s->failed_pc=0x0c07bce6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07bce8;
P_0c07bce8: /* original 7102, guest PC 0x0c07bce8 */
if(!s->budget--) { s->failed_pc=0x0c07bce8u; return 0; }
r[1]+=0x00000002u;
goto P_0c07bcea;
P_0c07bcea: /* original 410c, guest PC 0x0c07bcea */
if(!s->budget--) { s->failed_pc=0x0c07bceau; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07bcec;
P_0c07bcec: /* original 1f11, guest PC 0x0c07bcec */
if(!s->budget--) { s->failed_pc=0x0c07bcecu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07bcee;
P_0c07bcee: /* original 1f54, guest PC 0x0c07bcee */
if(!s->budget--) { s->failed_pc=0x0c07bceeu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf0;
P_0c07bcf0: /* original 54f1, guest PC 0x0c07bcf0 */
if(!s->budget--) { s->failed_pc=0x0c07bcf0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bcf2;
P_0c07bcf2: /* original 1f41, guest PC 0x0c07bcf2 */
if(!s->budget--) { s->failed_pc=0x0c07bcf2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bcf4;
P_0c07bcf4: /* original 1f54, guest PC 0x0c07bcf4 */
if(!s->budget--) { s->failed_pc=0x0c07bcf4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf6;
P_0c07bcf6: /* original a172, guest PC 0x0c07bcf6 */
if(!s->budget--) { s->failed_pc=0x0c07bcf6u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bfde;
P_0c07bcf8: /* original 1f41, guest PC 0x0c07bcf8 */
if(!s->budget--) { s->failed_pc=0x0c07bcf8u; return 0; }
write(ram,r[15]+4,r[4],4);
return vf3_matrix_family(0x0c07bcfau,s,ram);
P_0c07bd14: /* original 63c3, guest PC 0x0c07bd14 */
if(!s->budget--) { s->failed_pc=0x0c07bd14u; return 0; }
r[3]=r[12];
goto P_0c07bd16;
P_0c07bd16: /* original 4308, guest PC 0x0c07bd16 */
if(!s->budget--) { s->failed_pc=0x0c07bd16u; return 0; }
r[3]<<=2;
goto P_0c07bd18;
P_0c07bd18: /* original 62c3, guest PC 0x0c07bd18 */
if(!s->budget--) { s->failed_pc=0x0c07bd18u; return 0; }
r[2]=r[12];
goto P_0c07bd1a;
P_0c07bd1a: /* original 332c, guest PC 0x0c07bd1a */
if(!s->budget--) { s->failed_pc=0x0c07bd1au; return 0; }
r[3]+=r[2];
goto P_0c07bd1c;
P_0c07bd1c: /* original 64c3, guest PC 0x0c07bd1c */
if(!s->budget--) { s->failed_pc=0x0c07bd1cu; return 0; }
r[4]=r[12];
goto P_0c07bd1e;
P_0c07bd1e: /* original 61f3, guest PC 0x0c07bd1e */
if(!s->budget--) { s->failed_pc=0x0c07bd1eu; return 0; }
r[1]=r[15];
goto P_0c07bd20;
P_0c07bd20: /* original 4308, guest PC 0x0c07bd20 */
if(!s->budget--) { s->failed_pc=0x0c07bd20u; return 0; }
r[3]<<=2;
goto P_0c07bd22;
P_0c07bd22: /* original 4408, guest PC 0x0c07bd22 */
if(!s->budget--) { s->failed_pc=0x0c07bd22u; return 0; }
r[4]<<=2;
goto P_0c07bd24;
P_0c07bd24: /* original 717c, guest PC 0x0c07bd24 */
if(!s->budget--) { s->failed_pc=0x0c07bd24u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bd26;
P_0c07bd26: /* original 314c, guest PC 0x0c07bd26 */
if(!s->budget--) { s->failed_pc=0x0c07bd26u; return 0; }
r[1]+=r[4];
goto P_0c07bd28;
P_0c07bd28: /* original 4300, guest PC 0x0c07bd28 */
if(!s->budget--) { s->failed_pc=0x0c07bd28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2a;
P_0c07bd2a: /* original 730f, guest PC 0x0c07bd2a */
if(!s->budget--) { s->failed_pc=0x0c07bd2au; return 0; }
r[3]+=0x0000000fu;
goto P_0c07bd2c;
P_0c07bd2c: /* original 4300, guest PC 0x0c07bd2c */
if(!s->budget--) { s->failed_pc=0x0c07bd2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2e;
P_0c07bd2e: /* original 1f33, guest PC 0x0c07bd2e */
if(!s->budget--) { s->failed_pc=0x0c07bd2eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07bd30;
P_0c07bd30: /* original 52ff, guest PC 0x0c07bd30 */
if(!s->budget--) { s->failed_pc=0x0c07bd30u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c07bd32;
P_0c07bd32: /* original 6112, guest PC 0x0c07bd32 */
if(!s->budget--) { s->failed_pc=0x0c07bd32u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd34;
P_0c07bd34: /* original 324c, guest PC 0x0c07bd34 */
if(!s->budget--) { s->failed_pc=0x0c07bd34u; return 0; }
r[2]+=r[4];
goto P_0c07bd36;
P_0c07bd36: /* original 5222, guest PC 0x0c07bd36 */
if(!s->budget--) { s->failed_pc=0x0c07bd36u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c07bd38;
P_0c07bd38: /* original 3210, guest PC 0x0c07bd38 */
if(!s->budget--) { s->failed_pc=0x0c07bd38u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bd3a;
P_0c07bd3a: /* original 8b01, guest PC 0x0c07bd3a */
if(!s->budget--) { s->failed_pc=0x0c07bd3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bd40; }
goto P_0c07bd3c;
P_0c07bd3c: /* original a0a0, guest PC 0x0c07bd3c */
if(!s->budget--) { s->failed_pc=0x0c07bd3cu; return 0; }
goto P_0c07be80;
P_0c07bd3e: /* original 0009, guest PC 0x0c07bd3e */
if(!s->budget--) { s->failed_pc=0x0c07bd3eu; return 0; }
goto P_0c07bd40;
P_0c07bd40: /* original 50f8, guest PC 0x0c07bd40 */
if(!s->budget--) { s->failed_pc=0x0c07bd40u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c07bd42;
P_0c07bd42: /* original 8801, guest PC 0x0c07bd42 */
if(!s->budget--) { s->failed_pc=0x0c07bd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07bd44;
P_0c07bd44: /* original 8901, guest PC 0x0c07bd44 */
if(!s->budget--) { s->failed_pc=0x0c07bd44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bd4a; }
goto P_0c07bd46;
P_0c07bd46: /* original a09b, guest PC 0x0c07bd46 */
if(!s->budget--) { s->failed_pc=0x0c07bd46u; return 0; }
goto P_0c07be80;
P_0c07bd48: /* original 0009, guest PC 0x0c07bd48 */
if(!s->budget--) { s->failed_pc=0x0c07bd48u; return 0; }
goto P_0c07bd4a;
P_0c07bd4a: /* original 62f3, guest PC 0x0c07bd4a */
if(!s->budget--) { s->failed_pc=0x0c07bd4au; return 0; }
r[2]=r[15];
goto P_0c07bd4c;
P_0c07bd4c: /* original 63c3, guest PC 0x0c07bd4c */
if(!s->budget--) { s->failed_pc=0x0c07bd4cu; return 0; }
r[3]=r[12];
goto P_0c07bd4e;
P_0c07bd4e: /* original 727c, guest PC 0x0c07bd4e */
if(!s->budget--) { s->failed_pc=0x0c07bd4eu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bd50;
P_0c07bd50: /* original 4308, guest PC 0x0c07bd50 */
if(!s->budget--) { s->failed_pc=0x0c07bd50u; return 0; }
r[3]<<=2;
goto P_0c07bd52;
P_0c07bd52: /* original 332c, guest PC 0x0c07bd52 */
if(!s->budget--) { s->failed_pc=0x0c07bd52u; return 0; }
r[3]+=r[2];
goto P_0c07bd54;
P_0c07bd54: /* original 6132, guest PC 0x0c07bd54 */
if(!s->budget--) { s->failed_pc=0x0c07bd54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bd56;
P_0c07bd56: /* original 31a3, guest PC 0x0c07bd56 */
if(!s->budget--) { s->failed_pc=0x0c07bd56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[10])!=0);
goto P_0c07bd58;
P_0c07bd58: /* original 8b3f, guest PC 0x0c07bd58 */
if(!s->budget--) { s->failed_pc=0x0c07bd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bdda; }
goto P_0c07bd5a;
P_0c07bd5a: /* original 60c3, guest PC 0x0c07bd5a */
if(!s->budget--) { s->failed_pc=0x0c07bd5au; return 0; }
r[0]=r[12];
goto P_0c07bd5c;
P_0c07bd5c: /* original 63f3, guest PC 0x0c07bd5c */
if(!s->budget--) { s->failed_pc=0x0c07bd5cu; return 0; }
r[3]=r[15];
goto P_0c07bd5e;
P_0c07bd5e: /* original 4008, guest PC 0x0c07bd5e */
if(!s->budget--) { s->failed_pc=0x0c07bd5eu; return 0; }
r[0]<<=2;
goto P_0c07bd60;
P_0c07bd60: /* original 7374, guest PC 0x0c07bd60 */
if(!s->budget--) { s->failed_pc=0x0c07bd60u; return 0; }
r[3]+=0x00000074u;
goto P_0c07bd62;
P_0c07bd62: /* original 1f06, guest PC 0x0c07bd62 */
if(!s->budget--) { s->failed_pc=0x0c07bd62u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c07bd64;
P_0c07bd64: /* original 303c, guest PC 0x0c07bd64 */
if(!s->budget--) { s->failed_pc=0x0c07bd64u; return 0; }
r[0]+=r[3];
goto P_0c07bd66;
P_0c07bd66: /* original 1f05, guest PC 0x0c07bd66 */
if(!s->budget--) { s->failed_pc=0x0c07bd66u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bd68;
P_0c07bd68: /* original 2f06, guest PC 0x0c07bd68 */
if(!s->budget--) { s->failed_pc=0x0c07bd68u; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c07bd6a;
P_0c07bd6a: /* original 9297, guest PC 0x0c07bd6a */
if(!s->budget--) { s->failed_pc=0x0c07bd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07bd6c;
P_0c07bd6c: /* original 51f7, guest PC 0x0c07bd6c */
if(!s->budget--) { s->failed_pc=0x0c07bd6cu; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bd6e;
P_0c07bd6e: /* original 32fc, guest PC 0x0c07bd6e */
if(!s->budget--) { s->failed_pc=0x0c07bd6eu; return 0; }
r[2]+=r[15];
goto P_0c07bd70;
P_0c07bd70: /* original 312c, guest PC 0x0c07bd70 */
if(!s->budget--) { s->failed_pc=0x0c07bd70u; return 0; }
r[1]+=r[2];
goto P_0c07bd72;
P_0c07bd72: /* original 1f1f, guest PC 0x0c07bd72 */
if(!s->budget--) { s->failed_pc=0x0c07bd72u; return 0; }
write(ram,r[15]+60,r[1],4);
goto P_0c07bd74;
P_0c07bd74: /* original d34c, guest PC 0x0c07bd74 */
if(!s->budget--) { s->failed_pc=0x0c07bd74u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07bd76;
P_0c07bd76: /* original 6112, guest PC 0x0c07bd76 */
if(!s->budget--) { s->failed_pc=0x0c07bd76u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd78;
P_0c07bd78: /* original 430b, guest PC 0x0c07bd78 */
if(!s->budget--) { s->failed_pc=0x0c07bd78u; return 0; }
target=r[3];
r[16]=0x0c07bd7cu;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bd7cu) { target=s->pc; goto dispatch; }
goto P_0c07bd7c;
P_0c07bd7a: /* original 60a3, guest PC 0x0c07bd7a */
if(!s->budget--) { s->failed_pc=0x0c07bd7au; return 0; }
r[0]=r[10];
goto P_0c07bd7c;
P_0c07bd7c: /* original 64c3, guest PC 0x0c07bd7c */
if(!s->budget--) { s->failed_pc=0x0c07bd7cu; return 0; }
r[4]=r[12];
goto P_0c07bd7e;
P_0c07bd7e: /* original 61f6, guest PC 0x0c07bd7e */
if(!s->budget--) { s->failed_pc=0x0c07bd7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c07bd80;
P_0c07bd80: /* original 4408, guest PC 0x0c07bd80 */
if(!s->budget--) { s->failed_pc=0x0c07bd80u; return 0; }
r[4]<<=2;
goto P_0c07bd82;
P_0c07bd82: /* original 63c3, guest PC 0x0c07bd82 */
if(!s->budget--) { s->failed_pc=0x0c07bd82u; return 0; }
r[3]=r[12];
goto P_0c07bd84;
P_0c07bd84: /* original 343c, guest PC 0x0c07bd84 */
if(!s->budget--) { s->failed_pc=0x0c07bd84u; return 0; }
r[4]+=r[3];
goto P_0c07bd86;
P_0c07bd86: /* original 2102, guest PC 0x0c07bd86 */
if(!s->budget--) { s->failed_pc=0x0c07bd86u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07bd88;
P_0c07bd88: /* original 4408, guest PC 0x0c07bd88 */
if(!s->budget--) { s->failed_pc=0x0c07bd88u; return 0; }
r[4]<<=2;
goto P_0c07bd8a;
P_0c07bd8a: /* original 9188, guest PC 0x0c07bd8a */
if(!s->budget--) { s->failed_pc=0x0c07bd8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07bd8c;
P_0c07bd8c: /* original 2fe6, guest PC 0x0c07bd8c */
if(!s->budget--) { s->failed_pc=0x0c07bd8cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bd8e;
P_0c07bd8e: /* original 4400, guest PC 0x0c07bd8e */
if(!s->budget--) { s->failed_pc=0x0c07bd8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd90;
P_0c07bd90: /* original 50f6, guest PC 0x0c07bd90 */
if(!s->budget--) { s->failed_pc=0x0c07bd90u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07bd92;
P_0c07bd92: /* original 740d, guest PC 0x0c07bd92 */
if(!s->budget--) { s->failed_pc=0x0c07bd92u; return 0; }
r[4]+=0x0000000du;
goto P_0c07bd94;
P_0c07bd94: /* original d345, guest PC 0x0c07bd94 */
if(!s->budget--) { s->failed_pc=0x0c07bd94u; return 0; }
r[3]=read(ram,0x0c07beacu,4);
goto P_0c07bd96;
P_0c07bd96: /* original 4400, guest PC 0x0c07bd96 */
if(!s->budget--) { s->failed_pc=0x0c07bd96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd98;
P_0c07bd98: /* original 6002, guest PC 0x0c07bd98 */
if(!s->budget--) { s->failed_pc=0x0c07bd98u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bd9a;
P_0c07bd9a: /* original 241b, guest PC 0x0c07bd9a */
if(!s->budget--) { s->failed_pc=0x0c07bd9au; return 0; }
r[4]|=r[1];
goto P_0c07bd9c;
P_0c07bd9c: /* original 66d3, guest PC 0x0c07bd9c */
if(!s->budget--) { s->failed_pc=0x0c07bd9cu; return 0; }
r[6]=r[13];
goto P_0c07bd9e;
P_0c07bd9e: /* original e700, guest PC 0x0c07bd9e */
if(!s->budget--) { s->failed_pc=0x0c07bd9eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bda0;
P_0c07bda0: /* original 4008, guest PC 0x0c07bda0 */
if(!s->budget--) { s->failed_pc=0x0c07bda0u; return 0; }
r[0]<<=2;
goto P_0c07bda2;
P_0c07bda2: /* original 430b, guest PC 0x0c07bda2 */
if(!s->budget--) { s->failed_pc=0x0c07bda2u; return 0; }
target=r[3];
r[16]=0x0c07bda6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bda6u) { target=s->pc; goto dispatch; }
goto P_0c07bda6;
P_0c07bda4: /* original 059e, guest PC 0x0c07bda4 */
if(!s->budget--) { s->failed_pc=0x0c07bda4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bda6;
P_0c07bda6: /* original 7f04, guest PC 0x0c07bda6 */
if(!s->budget--) { s->failed_pc=0x0c07bda6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bda8;
P_0c07bda8: /* original 53f5, guest PC 0x0c07bda8 */
if(!s->budget--) { s->failed_pc=0x0c07bda8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bdaa;
P_0c07bdaa: /* original 52fe, guest PC 0x0c07bdaa */
if(!s->budget--) { s->failed_pc=0x0c07bdaau; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c07bdac;
P_0c07bdac: /* original 6132, guest PC 0x0c07bdac */
if(!s->budget--) { s->failed_pc=0x0c07bdacu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bdae;
P_0c07bdae: /* original 6322, guest PC 0x0c07bdae */
if(!s->budget--) { s->failed_pc=0x0c07bdaeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07bdb0;
P_0c07bdb0: /* original 01a7, guest PC 0x0c07bdb0 */
if(!s->budget--) { s->failed_pc=0x0c07bdb0u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bdb2;
P_0c07bdb2: /* original 011a, guest PC 0x0c07bdb2 */
if(!s->budget--) { s->failed_pc=0x0c07bdb2u; return 0; }
r[1]=r[19];
goto P_0c07bdb4;
P_0c07bdb4: /* original 3318, guest PC 0x0c07bdb4 */
if(!s->budget--) { s->failed_pc=0x0c07bdb4u; return 0; }
r[3]-=r[1];
goto P_0c07bdb6;
P_0c07bdb6: /* original 2232, guest PC 0x0c07bdb6 */
if(!s->budget--) { s->failed_pc=0x0c07bdb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07bdb8;
P_0c07bdb8: /* original e10a, guest PC 0x0c07bdb8 */
if(!s->budget--) { s->failed_pc=0x0c07bdb8u; return 0; }
r[1]=0x0000000au;
goto P_0c07bdba;
P_0c07bdba: /* original 50f4, guest PC 0x0c07bdba */
if(!s->budget--) { s->failed_pc=0x0c07bdbau; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bdbc;
P_0c07bdbc: /* original 52f6, guest PC 0x0c07bdbc */
if(!s->budget--) { s->failed_pc=0x0c07bdbcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07bdbe;
P_0c07bdbe: /* original 032e, guest PC 0x0c07bdbe */
if(!s->budget--) { s->failed_pc=0x0c07bdbeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c07bdc0;
P_0c07bdc0: /* original 3313, guest PC 0x0c07bdc0 */
if(!s->budget--) { s->failed_pc=0x0c07bdc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c07bdc2;
P_0c07bdc2: /* original 890a, guest PC 0x0c07bdc2 */
if(!s->budget--) { s->failed_pc=0x0c07bdc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bdda; }
goto P_0c07bdc4;
P_0c07bdc4: /* original 54f3, guest PC 0x0c07bdc4 */
if(!s->budget--) { s->failed_pc=0x0c07bdc4u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07bdc6;
P_0c07bdc6: /* original 66d3, guest PC 0x0c07bdc6 */
if(!s->budget--) { s->failed_pc=0x0c07bdc6u; return 0; }
r[6]=r[13];
goto P_0c07bdc8;
P_0c07bdc8: /* original 53f1, guest PC 0x0c07bdc8 */
if(!s->budget--) { s->failed_pc=0x0c07bdc8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bdca;
P_0c07bdca: /* original e700, guest PC 0x0c07bdca */
if(!s->budget--) { s->failed_pc=0x0c07bdcau; return 0; }
r[7]=0x00000000u;
goto P_0c07bdcc;
P_0c07bdcc: /* original 2fe6, guest PC 0x0c07bdcc */
if(!s->budget--) { s->failed_pc=0x0c07bdccu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bdce;
P_0c07bdce: /* original 55fb, guest PC 0x0c07bdce */
if(!s->budget--) { s->failed_pc=0x0c07bdceu; return 0; }
r[5]=read(ram,r[15]+44,4);
goto P_0c07bdd0;
P_0c07bdd0: /* original 243b, guest PC 0x0c07bdd0 */
if(!s->budget--) { s->failed_pc=0x0c07bdd0u; return 0; }
r[4]|=r[3];
goto P_0c07bdd2;
P_0c07bdd2: /* original d236, guest PC 0x0c07bdd2 */
if(!s->budget--) { s->failed_pc=0x0c07bdd2u; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07bdd4;
P_0c07bdd4: /* original 420b, guest PC 0x0c07bdd4 */
if(!s->budget--) { s->failed_pc=0x0c07bdd4u; return 0; }
target=r[2];
r[16]=0x0c07bdd8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bdd8u) { target=s->pc; goto dispatch; }
goto P_0c07bdd8;
P_0c07bdd6: /* original 6552, guest PC 0x0c07bdd6 */
if(!s->budget--) { s->failed_pc=0x0c07bdd6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bdd8;
P_0c07bdd8: /* original 7f04, guest PC 0x0c07bdd8 */
if(!s->budget--) { s->failed_pc=0x0c07bdd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bdda;
P_0c07bdda: /* original 62f3, guest PC 0x0c07bdda */
if(!s->budget--) { s->failed_pc=0x0c07bddau; return 0; }
r[2]=r[15];
goto P_0c07bddc;
P_0c07bddc: /* original 63c3, guest PC 0x0c07bddc */
if(!s->budget--) { s->failed_pc=0x0c07bddcu; return 0; }
r[3]=r[12];
goto P_0c07bdde;
P_0c07bdde: /* original 727c, guest PC 0x0c07bdde */
if(!s->budget--) { s->failed_pc=0x0c07bddeu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bde0;
P_0c07bde0: /* original 4308, guest PC 0x0c07bde0 */
if(!s->budget--) { s->failed_pc=0x0c07bde0u; return 0; }
r[3]<<=2;
goto P_0c07bde2;
P_0c07bde2: /* original 332c, guest PC 0x0c07bde2 */
if(!s->budget--) { s->failed_pc=0x0c07bde2u; return 0; }
r[3]+=r[2];
goto P_0c07bde4;
P_0c07bde4: /* original 6032, guest PC 0x0c07bde4 */
if(!s->budget--) { s->failed_pc=0x0c07bde4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bde6;
P_0c07bde6: /* original e10a, guest PC 0x0c07bde6 */
if(!s->budget--) { s->failed_pc=0x0c07bde6u; return 0; }
r[1]=0x0000000au;
goto P_0c07bde8;
P_0c07bde8: /* original 3013, guest PC 0x0c07bde8 */
if(!s->budget--) { s->failed_pc=0x0c07bde8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c07bdea;
P_0c07bdea: /* original 8b26, guest PC 0x0c07bdea */
if(!s->budget--) { s->failed_pc=0x0c07bdeau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07be3a; }
goto P_0c07bdec;
P_0c07bdec: /* original 61f3, guest PC 0x0c07bdec */
if(!s->budget--) { s->failed_pc=0x0c07bdecu; return 0; }
r[1]=r[15];
goto P_0c07bdee;
P_0c07bdee: /* original 64c3, guest PC 0x0c07bdee */
if(!s->budget--) { s->failed_pc=0x0c07bdeeu; return 0; }
r[4]=r[12];
goto P_0c07bdf0;
P_0c07bdf0: /* original 717c, guest PC 0x0c07bdf0 */
if(!s->budget--) { s->failed_pc=0x0c07bdf0u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bdf2;
P_0c07bdf2: /* original 60f3, guest PC 0x0c07bdf2 */
if(!s->budget--) { s->failed_pc=0x0c07bdf2u; return 0; }
r[0]=r[15];
goto P_0c07bdf4;
P_0c07bdf4: /* original 4408, guest PC 0x0c07bdf4 */
if(!s->budget--) { s->failed_pc=0x0c07bdf4u; return 0; }
r[4]<<=2;
goto P_0c07bdf6;
P_0c07bdf6: /* original 314c, guest PC 0x0c07bdf6 */
if(!s->budget--) { s->failed_pc=0x0c07bdf6u; return 0; }
r[1]+=r[4];
goto P_0c07bdf8;
P_0c07bdf8: /* original 7074, guest PC 0x0c07bdf8 */
if(!s->budget--) { s->failed_pc=0x0c07bdf8u; return 0; }
r[0]+=0x00000074u;
goto P_0c07bdfa;
P_0c07bdfa: /* original 304c, guest PC 0x0c07bdfa */
if(!s->budget--) { s->failed_pc=0x0c07bdfau; return 0; }
r[0]+=r[4];
goto P_0c07bdfc;
P_0c07bdfc: /* original 1f05, guest PC 0x0c07bdfc */
if(!s->budget--) { s->failed_pc=0x0c07bdfcu; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bdfe;
P_0c07bdfe: /* original 6203, guest PC 0x0c07bdfe */
if(!s->budget--) { s->failed_pc=0x0c07bdfeu; return 0; }
r[2]=r[0];
goto P_0c07be00;
P_0c07be00: /* original 1f16, guest PC 0x0c07be00 */
if(!s->budget--) { s->failed_pc=0x0c07be00u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07be02;
P_0c07be02: /* original d329, guest PC 0x0c07be02 */
if(!s->budget--) { s->failed_pc=0x0c07be02u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07be04;
P_0c07be04: /* original 6112, guest PC 0x0c07be04 */
if(!s->budget--) { s->failed_pc=0x0c07be04u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07be06;
P_0c07be06: /* original 430b, guest PC 0x0c07be06 */
if(!s->budget--) { s->failed_pc=0x0c07be06u; return 0; }
target=r[3];
r[16]=0x0c07be0au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be0au) { target=s->pc; goto dispatch; }
goto P_0c07be0a;
P_0c07be08: /* original e00a, guest PC 0x0c07be08 */
if(!s->budget--) { s->failed_pc=0x0c07be08u; return 0; }
r[0]=0x0000000au;
goto P_0c07be0a;
P_0c07be0a: /* original 2202, guest PC 0x0c07be0a */
if(!s->budget--) { s->failed_pc=0x0c07be0au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07be0c;
P_0c07be0c: /* original e700, guest PC 0x0c07be0c */
if(!s->budget--) { s->failed_pc=0x0c07be0cu; return 0; }
r[7]=0x00000000u;
goto P_0c07be0e;
P_0c07be0e: /* original 54f3, guest PC 0x0c07be0e */
if(!s->budget--) { s->failed_pc=0x0c07be0eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07be10;
P_0c07be10: /* original 66d3, guest PC 0x0c07be10 */
if(!s->budget--) { s->failed_pc=0x0c07be10u; return 0; }
r[6]=r[13];
goto P_0c07be12;
P_0c07be12: /* original 9344, guest PC 0x0c07be12 */
if(!s->budget--) { s->failed_pc=0x0c07be12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be14;
P_0c07be14: /* original 2fe6, guest PC 0x0c07be14 */
if(!s->budget--) { s->failed_pc=0x0c07be14u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07be16;
P_0c07be16: /* original 50f6, guest PC 0x0c07be16 */
if(!s->budget--) { s->failed_pc=0x0c07be16u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07be18;
P_0c07be18: /* original 243b, guest PC 0x0c07be18 */
if(!s->budget--) { s->failed_pc=0x0c07be18u; return 0; }
r[4]|=r[3];
goto P_0c07be1a;
P_0c07be1a: /* original d224, guest PC 0x0c07be1a */
if(!s->budget--) { s->failed_pc=0x0c07be1au; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07be1c;
P_0c07be1c: /* original 6002, guest PC 0x0c07be1c */
if(!s->budget--) { s->failed_pc=0x0c07be1cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07be1e;
P_0c07be1e: /* original 4008, guest PC 0x0c07be1e */
if(!s->budget--) { s->failed_pc=0x0c07be1eu; return 0; }
r[0]<<=2;
goto P_0c07be20;
P_0c07be20: /* original 420b, guest PC 0x0c07be20 */
if(!s->budget--) { s->failed_pc=0x0c07be20u; return 0; }
target=r[2];
r[16]=0x0c07be24u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be24u) { target=s->pc; goto dispatch; }
goto P_0c07be24;
P_0c07be22: /* original 059e, guest PC 0x0c07be22 */
if(!s->budget--) { s->failed_pc=0x0c07be22u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be24;
P_0c07be24: /* original 7f04, guest PC 0x0c07be24 */
if(!s->budget--) { s->failed_pc=0x0c07be24u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be26;
P_0c07be26: /* original 52f5, guest PC 0x0c07be26 */
if(!s->budget--) { s->failed_pc=0x0c07be26u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07be28;
P_0c07be28: /* original 53f6, guest PC 0x0c07be28 */
if(!s->budget--) { s->failed_pc=0x0c07be28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07be2a;
P_0c07be2a: /* original 6222, guest PC 0x0c07be2a */
if(!s->budget--) { s->failed_pc=0x0c07be2au; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07be2c;
P_0c07be2c: /* original 6032, guest PC 0x0c07be2c */
if(!s->budget--) { s->failed_pc=0x0c07be2cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07be2e;
P_0c07be2e: /* original 6123, guest PC 0x0c07be2e */
if(!s->budget--) { s->failed_pc=0x0c07be2eu; return 0; }
r[1]=r[2];
goto P_0c07be30;
P_0c07be30: /* original 4208, guest PC 0x0c07be30 */
if(!s->budget--) { s->failed_pc=0x0c07be30u; return 0; }
r[2]<<=2;
goto P_0c07be32;
P_0c07be32: /* original 321c, guest PC 0x0c07be32 */
if(!s->budget--) { s->failed_pc=0x0c07be32u; return 0; }
r[2]+=r[1];
goto P_0c07be34;
P_0c07be34: /* original 4200, guest PC 0x0c07be34 */
if(!s->budget--) { s->failed_pc=0x0c07be34u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07be36;
P_0c07be36: /* original 3028, guest PC 0x0c07be36 */
if(!s->budget--) { s->failed_pc=0x0c07be36u; return 0; }
r[0]-=r[2];
goto P_0c07be38;
P_0c07be38: /* original 2302, guest PC 0x0c07be38 */
if(!s->budget--) { s->failed_pc=0x0c07be38u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07be3a;
P_0c07be3a: /* original 64c3, guest PC 0x0c07be3a */
if(!s->budget--) { s->failed_pc=0x0c07be3au; return 0; }
r[4]=r[12];
goto P_0c07be3c;
P_0c07be3c: /* original 4408, guest PC 0x0c07be3c */
if(!s->budget--) { s->failed_pc=0x0c07be3cu; return 0; }
r[4]<<=2;
goto P_0c07be3e;
P_0c07be3e: /* original 63c3, guest PC 0x0c07be3e */
if(!s->budget--) { s->failed_pc=0x0c07be3eu; return 0; }
r[3]=r[12];
goto P_0c07be40;
P_0c07be40: /* original 343c, guest PC 0x0c07be40 */
if(!s->budget--) { s->failed_pc=0x0c07be40u; return 0; }
r[4]+=r[3];
goto P_0c07be42;
P_0c07be42: /* original 60c3, guest PC 0x0c07be42 */
if(!s->budget--) { s->failed_pc=0x0c07be42u; return 0; }
r[0]=r[12];
goto P_0c07be44;
P_0c07be44: /* original 4408, guest PC 0x0c07be44 */
if(!s->budget--) { s->failed_pc=0x0c07be44u; return 0; }
r[4]<<=2;
goto P_0c07be46;
P_0c07be46: /* original 4008, guest PC 0x0c07be46 */
if(!s->budget--) { s->failed_pc=0x0c07be46u; return 0; }
r[0]<<=2;
goto P_0c07be48;
P_0c07be48: /* original 9229, guest PC 0x0c07be48 */
if(!s->budget--) { s->failed_pc=0x0c07be48u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be4a;
P_0c07be4a: /* original 2fe6, guest PC 0x0c07be4a */
if(!s->budget--) { s->failed_pc=0x0c07be4au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07be4c;
P_0c07be4c: /* original 4400, guest PC 0x0c07be4c */
if(!s->budget--) { s->failed_pc=0x0c07be4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be4e;
P_0c07be4e: /* original 9325, guest PC 0x0c07be4e */
if(!s->budget--) { s->failed_pc=0x0c07be4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07be50;
P_0c07be50: /* original 7411, guest PC 0x0c07be50 */
if(!s->budget--) { s->failed_pc=0x0c07be50u; return 0; }
r[4]+=0x00000011u;
goto P_0c07be52;
P_0c07be52: /* original 4400, guest PC 0x0c07be52 */
if(!s->budget--) { s->failed_pc=0x0c07be52u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be54;
P_0c07be54: /* original d115, guest PC 0x0c07be54 */
if(!s->budget--) { s->failed_pc=0x0c07be54u; return 0; }
r[1]=read(ram,0x0c07beacu,4);
goto P_0c07be56;
P_0c07be56: /* original 33fc, guest PC 0x0c07be56 */
if(!s->budget--) { s->failed_pc=0x0c07be56u; return 0; }
r[3]+=r[15];
goto P_0c07be58;
P_0c07be58: /* original 66d3, guest PC 0x0c07be58 */
if(!s->budget--) { s->failed_pc=0x0c07be58u; return 0; }
r[6]=r[13];
goto P_0c07be5a;
P_0c07be5a: /* original 003e, guest PC 0x0c07be5a */
if(!s->budget--) { s->failed_pc=0x0c07be5au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c07be5c;
P_0c07be5c: /* original 242b, guest PC 0x0c07be5c */
if(!s->budget--) { s->failed_pc=0x0c07be5cu; return 0; }
r[4]|=r[2];
goto P_0c07be5e;
P_0c07be5e: /* original e700, guest PC 0x0c07be5e */
if(!s->budget--) { s->failed_pc=0x0c07be5eu; return 0; }
r[7]=0x00000000u;
goto P_0c07be60;
P_0c07be60: /* original 4008, guest PC 0x0c07be60 */
if(!s->budget--) { s->failed_pc=0x0c07be60u; return 0; }
r[0]<<=2;
goto P_0c07be62;
P_0c07be62: /* original 410b, guest PC 0x0c07be62 */
if(!s->budget--) { s->failed_pc=0x0c07be62u; return 0; }
target=r[1];
r[16]=0x0c07be66u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be66u) { target=s->pc; goto dispatch; }
goto P_0c07be66;
P_0c07be64: /* original 059e, guest PC 0x0c07be64 */
if(!s->budget--) { s->failed_pc=0x0c07be64u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be66;
P_0c07be66: /* original 7f04, guest PC 0x0c07be66 */
if(!s->budget--) { s->failed_pc=0x0c07be66u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be68;
P_0c07be68: /* original 931a, guest PC 0x0c07be68 */
if(!s->budget--) { s->failed_pc=0x0c07be68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea0u,2);
goto P_0c07be6a;
P_0c07be6a: /* original 60f2, guest PC 0x0c07be6a */
if(!s->budget--) { s->failed_pc=0x0c07be6au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be6c;
P_0c07be6c: /* original 64c3, guest PC 0x0c07be6c */
if(!s->budget--) { s->failed_pc=0x0c07be6cu; return 0; }
r[4]=r[12];
goto P_0c07be6e;
P_0c07be6e: /* original 9218, guest PC 0x0c07be6e */
if(!s->budget--) { s->failed_pc=0x0c07be6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea2u,2);
goto P_0c07be70;
P_0c07be70: /* original 4400, guest PC 0x0c07be70 */
if(!s->budget--) { s->failed_pc=0x0c07be70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be72;
P_0c07be72: /* original 330c, guest PC 0x0c07be72 */
if(!s->budget--) { s->failed_pc=0x0c07be72u; return 0; }
r[3]+=r[0];
goto P_0c07be74;
P_0c07be74: /* original 60f2, guest PC 0x0c07be74 */
if(!s->budget--) { s->failed_pc=0x0c07be74u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be76;
P_0c07be76: /* original 334c, guest PC 0x0c07be76 */
if(!s->budget--) { s->failed_pc=0x0c07be76u; return 0; }
r[3]+=r[4];
goto P_0c07be78;
P_0c07be78: /* original 320c, guest PC 0x0c07be78 */
if(!s->budget--) { s->failed_pc=0x0c07be78u; return 0; }
r[2]+=r[0];
goto P_0c07be7a;
P_0c07be7a: /* original 324c, guest PC 0x0c07be7a */
if(!s->budget--) { s->failed_pc=0x0c07be7au; return 0; }
r[2]+=r[4];
goto P_0c07be7c;
P_0c07be7c: /* original 6121, guest PC 0x0c07be7c */
if(!s->budget--) { s->failed_pc=0x0c07be7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c07be7e;
P_0c07be7e: /* original 2311, guest PC 0x0c07be7e */
if(!s->budget--) { s->failed_pc=0x0c07be7eu; return 0; }
write(ram,r[3],r[1],2);
goto P_0c07be80;
P_0c07be80: /* original 50f4, guest PC 0x0c07be80 */
if(!s->budget--) { s->failed_pc=0x0c07be80u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07be82;
P_0c07be82: /* original 63c3, guest PC 0x0c07be82 */
if(!s->budget--) { s->failed_pc=0x0c07be82u; return 0; }
r[3]=r[12];
goto P_0c07be84;
P_0c07be84: /* original 4308, guest PC 0x0c07be84 */
if(!s->budget--) { s->failed_pc=0x0c07be84u; return 0; }
r[3]<<=2;
goto P_0c07be86;
P_0c07be86: /* original 033e, guest PC 0x0c07be86 */
if(!s->budget--) { s->failed_pc=0x0c07be86u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07be88;
P_0c07be88: /* original 33a3, guest PC 0x0c07be88 */
if(!s->budget--) { s->failed_pc=0x0c07be88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07be8a;
P_0c07be8a: /* original 8b54, guest PC 0x0c07be8a */
if(!s->budget--) { s->failed_pc=0x0c07be8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bf36; }
goto P_0c07be8c;
P_0c07be8c: /* original 930a, guest PC 0x0c07be8c */
if(!s->budget--) { s->failed_pc=0x0c07be8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea4u,2);
goto P_0c07be8e;
P_0c07be8e: /* original 64c3, guest PC 0x0c07be8e */
if(!s->budget--) { s->failed_pc=0x0c07be8eu; return 0; }
r[4]=r[12];
goto P_0c07be90;
P_0c07be90: /* original 52f2, guest PC 0x0c07be90 */
if(!s->budget--) { s->failed_pc=0x0c07be90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07be92;
P_0c07be92: /* original 4408, guest PC 0x0c07be92 */
if(!s->budget--) { s->failed_pc=0x0c07be92u; return 0; }
r[4]<<=2;
goto P_0c07be94;
P_0c07be94: /* original 33fc, guest PC 0x0c07be94 */
if(!s->budget--) { s->failed_pc=0x0c07be94u; return 0; }
r[3]+=r[15];
goto P_0c07be96;
P_0c07be96: /* original 323c, guest PC 0x0c07be96 */
if(!s->budget--) { s->failed_pc=0x0c07be96u; return 0; }
r[2]+=r[3];
goto P_0c07be98;
P_0c07be98: /* original a00a, guest PC 0x0c07be98 */
if(!s->budget--) { s->failed_pc=0x0c07be98u; return 0; }
goto P_0c07beb0;
P_0c07be9a: /* original 0009, guest PC 0x0c07be9a */
if(!s->budget--) { s->failed_pc=0x0c07be9au; return 0; }
return vf3_matrix_family(0x0c07be9cu,s,ram);
P_0c07beb0: /* original 324c, guest PC 0x0c07beb0 */
if(!s->budget--) { s->failed_pc=0x0c07beb0u; return 0; }
r[2]+=r[4];
goto P_0c07beb2;
P_0c07beb2: /* original 1f25, guest PC 0x0c07beb2 */
if(!s->budget--) { s->failed_pc=0x0c07beb2u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07beb4;
P_0c07beb4: /* original 90c6, guest PC 0x0c07beb4 */
if(!s->budget--) { s->failed_pc=0x0c07beb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c044u,2);
goto P_0c07beb6;
P_0c07beb6: /* original 51f2, guest PC 0x0c07beb6 */
if(!s->budget--) { s->failed_pc=0x0c07beb6u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07beb8;
P_0c07beb8: /* original 30fc, guest PC 0x0c07beb8 */
if(!s->budget--) { s->failed_pc=0x0c07beb8u; return 0; }
r[0]+=r[15];
goto P_0c07beba;
P_0c07beba: /* original 310c, guest PC 0x0c07beba */
if(!s->budget--) { s->failed_pc=0x0c07bebau; return 0; }
r[1]+=r[0];
goto P_0c07bebc;
P_0c07bebc: /* original 314c, guest PC 0x0c07bebc */
if(!s->budget--) { s->failed_pc=0x0c07bebcu; return 0; }
r[1]+=r[4];
goto P_0c07bebe;
P_0c07bebe: /* original 1f16, guest PC 0x0c07bebe */
if(!s->budget--) { s->failed_pc=0x0c07bebeu; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bec0;
P_0c07bec0: /* original 6112, guest PC 0x0c07bec0 */
if(!s->budget--) { s->failed_pc=0x0c07bec0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bec2;
P_0c07bec2: /* original d365, guest PC 0x0c07bec2 */
if(!s->budget--) { s->failed_pc=0x0c07bec2u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bec4;
P_0c07bec4: /* original 430b, guest PC 0x0c07bec4 */
if(!s->budget--) { s->failed_pc=0x0c07bec4u; return 0; }
target=r[3];
r[16]=0x0c07bec8u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bec8u) { target=s->pc; goto dispatch; }
goto P_0c07bec8;
P_0c07bec6: /* original 60a3, guest PC 0x0c07bec6 */
if(!s->budget--) { s->failed_pc=0x0c07bec6u; return 0; }
r[0]=r[10];
goto P_0c07bec8;
P_0c07bec8: /* original 2202, guest PC 0x0c07bec8 */
if(!s->budget--) { s->failed_pc=0x0c07bec8u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07beca;
P_0c07beca: /* original 62c3, guest PC 0x0c07beca */
if(!s->budget--) { s->failed_pc=0x0c07becau; return 0; }
r[2]=r[12];
goto P_0c07becc;
P_0c07becc: /* original 4208, guest PC 0x0c07becc */
if(!s->budget--) { s->failed_pc=0x0c07beccu; return 0; }
r[2]<<=2;
goto P_0c07bece;
P_0c07bece: /* original 63c3, guest PC 0x0c07bece */
if(!s->budget--) { s->failed_pc=0x0c07beceu; return 0; }
r[3]=r[12];
goto P_0c07bed0;
P_0c07bed0: /* original 323c, guest PC 0x0c07bed0 */
if(!s->budget--) { s->failed_pc=0x0c07bed0u; return 0; }
r[2]+=r[3];
goto P_0c07bed2;
P_0c07bed2: /* original 51f1, guest PC 0x0c07bed2 */
if(!s->budget--) { s->failed_pc=0x0c07bed2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bed4;
P_0c07bed4: /* original 4208, guest PC 0x0c07bed4 */
if(!s->budget--) { s->failed_pc=0x0c07bed4u; return 0; }
r[2]<<=2;
goto P_0c07bed6;
P_0c07bed6: /* original 66d3, guest PC 0x0c07bed6 */
if(!s->budget--) { s->failed_pc=0x0c07bed6u; return 0; }
r[6]=r[13];
goto P_0c07bed8;
P_0c07bed8: /* original 4200, guest PC 0x0c07bed8 */
if(!s->budget--) { s->failed_pc=0x0c07bed8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07beda;
P_0c07beda: /* original 720d, guest PC 0x0c07beda */
if(!s->budget--) { s->failed_pc=0x0c07bedau; return 0; }
r[2]+=0x0000000du;
goto P_0c07bedc;
P_0c07bedc: /* original 4200, guest PC 0x0c07bedc */
if(!s->budget--) { s->failed_pc=0x0c07bedcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bede;
P_0c07bede: /* original 221b, guest PC 0x0c07bede */
if(!s->budget--) { s->failed_pc=0x0c07bedeu; return 0; }
r[2]|=r[1];
goto P_0c07bee0;
P_0c07bee0: /* original 1f2e, guest PC 0x0c07bee0 */
if(!s->budget--) { s->failed_pc=0x0c07bee0u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c07bee2;
P_0c07bee2: /* original e700, guest PC 0x0c07bee2 */
if(!s->budget--) { s->failed_pc=0x0c07bee2u; return 0; }
r[7]=0x00000000u;
goto P_0c07bee4;
P_0c07bee4: /* original 2fb6, guest PC 0x0c07bee4 */
if(!s->budget--) { s->failed_pc=0x0c07bee4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bee6;
P_0c07bee6: /* original 2fe6, guest PC 0x0c07bee6 */
if(!s->budget--) { s->failed_pc=0x0c07bee6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bee8;
P_0c07bee8: /* original 50f7, guest PC 0x0c07bee8 */
if(!s->budget--) { s->failed_pc=0x0c07bee8u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c07beea;
P_0c07beea: /* original 6002, guest PC 0x0c07beea */
if(!s->budget--) { s->failed_pc=0x0c07beeau; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07beec;
P_0c07beec: /* original 4008, guest PC 0x0c07beec */
if(!s->budget--) { s->failed_pc=0x0c07beecu; return 0; }
r[0]<<=2;
goto P_0c07beee;
P_0c07beee: /* original 059e, guest PC 0x0c07beee */
if(!s->budget--) { s->failed_pc=0x0c07beeeu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bef0;
P_0c07bef0: /* original 480b, guest PC 0x0c07bef0 */
if(!s->budget--) { s->failed_pc=0x0c07bef0u; return 0; }
target=r[8];
r[16]=0x0c07bef4u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bef4u) { target=s->pc; goto dispatch; }
goto P_0c07bef4;
P_0c07bef2: /* original 6423, guest PC 0x0c07bef2 */
if(!s->budget--) { s->failed_pc=0x0c07bef2u; return 0; }
r[4]=r[2];
goto P_0c07bef4;
P_0c07bef4: /* original 7f08, guest PC 0x0c07bef4 */
if(!s->budget--) { s->failed_pc=0x0c07bef4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bef6;
P_0c07bef6: /* original 6403, guest PC 0x0c07bef6 */
if(!s->budget--) { s->failed_pc=0x0c07bef6u; return 0; }
r[4]=r[0];
goto P_0c07bef8;
P_0c07bef8: /* original e030, guest PC 0x0c07bef8 */
if(!s->budget--) { s->failed_pc=0x0c07bef8u; return 0; }
r[0]=0x00000030u;
goto P_0c07befa;
P_0c07befa: /* original f4f7, guest PC 0x0c07befa */
if(!s->budget--) { s->failed_pc=0x0c07befau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07befc;
P_0c07befc: /* original 52f5, guest PC 0x0c07befc */
if(!s->budget--) { s->failed_pc=0x0c07befcu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07befe;
P_0c07befe: /* original 53f6, guest PC 0x0c07befe */
if(!s->budget--) { s->failed_pc=0x0c07befeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf00;
P_0c07bf00: /* original 6122, guest PC 0x0c07bf00 */
if(!s->budget--) { s->failed_pc=0x0c07bf00u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07bf02;
P_0c07bf02: /* original 6232, guest PC 0x0c07bf02 */
if(!s->budget--) { s->failed_pc=0x0c07bf02u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07bf04;
P_0c07bf04: /* original 01a7, guest PC 0x0c07bf04 */
if(!s->budget--) { s->failed_pc=0x0c07bf04u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bf06;
P_0c07bf06: /* original 011a, guest PC 0x0c07bf06 */
if(!s->budget--) { s->failed_pc=0x0c07bf06u; return 0; }
r[1]=r[19];
goto P_0c07bf08;
P_0c07bf08: /* original 3218, guest PC 0x0c07bf08 */
if(!s->budget--) { s->failed_pc=0x0c07bf08u; return 0; }
r[2]-=r[1];
goto P_0c07bf0a;
P_0c07bf0a: /* original 2322, guest PC 0x0c07bf0a */
if(!s->budget--) { s->failed_pc=0x0c07bf0au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07bf0c;
P_0c07bf0c: /* original e20a, guest PC 0x0c07bf0c */
if(!s->budget--) { s->failed_pc=0x0c07bf0cu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf0e;
P_0c07bf0e: /* original 53f6, guest PC 0x0c07bf0e */
if(!s->budget--) { s->failed_pc=0x0c07bf0eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf10;
P_0c07bf10: /* original 6132, guest PC 0x0c07bf10 */
if(!s->budget--) { s->failed_pc=0x0c07bf10u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bf12;
P_0c07bf12: /* original 3123, guest PC 0x0c07bf12 */
if(!s->budget--) { s->failed_pc=0x0c07bf12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07bf14;
P_0c07bf14: /* original 890f, guest PC 0x0c07bf14 */
if(!s->budget--) { s->failed_pc=0x0c07bf14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bf36; }
goto P_0c07bf16;
P_0c07bf16: /* original 50f3, guest PC 0x0c07bf16 */
if(!s->budget--) { s->failed_pc=0x0c07bf16u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c07bf18;
P_0c07bf18: /* original e700, guest PC 0x0c07bf18 */
if(!s->budget--) { s->failed_pc=0x0c07bf18u; return 0; }
r[7]=0x00000000u;
goto P_0c07bf1a;
P_0c07bf1a: /* original 53f1, guest PC 0x0c07bf1a */
if(!s->budget--) { s->failed_pc=0x0c07bf1au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bf1c;
P_0c07bf1c: /* original 66d3, guest PC 0x0c07bf1c */
if(!s->budget--) { s->failed_pc=0x0c07bf1cu; return 0; }
r[6]=r[13];
goto P_0c07bf1e;
P_0c07bf1e: /* original 203b, guest PC 0x0c07bf1e */
if(!s->budget--) { s->failed_pc=0x0c07bf1eu; return 0; }
r[0]|=r[3];
goto P_0c07bf20;
P_0c07bf20: /* original 1f03, guest PC 0x0c07bf20 */
if(!s->budget--) { s->failed_pc=0x0c07bf20u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07bf22;
P_0c07bf22: /* original 2fb6, guest PC 0x0c07bf22 */
if(!s->budget--) { s->failed_pc=0x0c07bf22u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bf24;
P_0c07bf24: /* original 2fe6, guest PC 0x0c07bf24 */
if(!s->budget--) { s->failed_pc=0x0c07bf24u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bf26;
P_0c07bf26: /* original 55fc, guest PC 0x0c07bf26 */
if(!s->budget--) { s->failed_pc=0x0c07bf26u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c07bf28;
P_0c07bf28: /* original 6552, guest PC 0x0c07bf28 */
if(!s->budget--) { s->failed_pc=0x0c07bf28u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bf2a;
P_0c07bf2a: /* original 480b, guest PC 0x0c07bf2a */
if(!s->budget--) { s->failed_pc=0x0c07bf2au; return 0; }
target=r[8];
r[16]=0x0c07bf2eu;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf2eu) { target=s->pc; goto dispatch; }
goto P_0c07bf2e;
P_0c07bf2c: /* original 54f5, guest PC 0x0c07bf2c */
if(!s->budget--) { s->failed_pc=0x0c07bf2cu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07bf2e;
P_0c07bf2e: /* original 6403, guest PC 0x0c07bf2e */
if(!s->budget--) { s->failed_pc=0x0c07bf2eu; return 0; }
r[4]=r[0];
goto P_0c07bf30;
P_0c07bf30: /* original e030, guest PC 0x0c07bf30 */
if(!s->budget--) { s->failed_pc=0x0c07bf30u; return 0; }
r[0]=0x00000030u;
goto P_0c07bf32;
P_0c07bf32: /* original f4f7, guest PC 0x0c07bf32 */
if(!s->budget--) { s->failed_pc=0x0c07bf32u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf34;
P_0c07bf34: /* original 7f08, guest PC 0x0c07bf34 */
if(!s->budget--) { s->failed_pc=0x0c07bf34u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf36;
P_0c07bf36: /* original 50f4, guest PC 0x0c07bf36 */
if(!s->budget--) { s->failed_pc=0x0c07bf36u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bf38;
P_0c07bf38: /* original 63c3, guest PC 0x0c07bf38 */
if(!s->budget--) { s->failed_pc=0x0c07bf38u; return 0; }
r[3]=r[12];
goto P_0c07bf3a;
P_0c07bf3a: /* original 4308, guest PC 0x0c07bf3a */
if(!s->budget--) { s->failed_pc=0x0c07bf3au; return 0; }
r[3]<<=2;
goto P_0c07bf3c;
P_0c07bf3c: /* original 033e, guest PC 0x0c07bf3c */
if(!s->budget--) { s->failed_pc=0x0c07bf3cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07bf3e;
P_0c07bf3e: /* original e20a, guest PC 0x0c07bf3e */
if(!s->budget--) { s->failed_pc=0x0c07bf3eu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf40;
P_0c07bf40: /* original 3323, guest PC 0x0c07bf40 */
if(!s->budget--) { s->failed_pc=0x0c07bf40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07bf42;
P_0c07bf42: /* original 8b30, guest PC 0x0c07bf42 */
if(!s->budget--) { s->failed_pc=0x0c07bf42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bfa6; }
goto P_0c07bf44;
P_0c07bf44: /* original 937f, guest PC 0x0c07bf44 */
if(!s->budget--) { s->failed_pc=0x0c07bf44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c046u,2);
goto P_0c07bf46;
P_0c07bf46: /* original 64c3, guest PC 0x0c07bf46 */
if(!s->budget--) { s->failed_pc=0x0c07bf46u; return 0; }
r[4]=r[12];
goto P_0c07bf48;
P_0c07bf48: /* original 51f2, guest PC 0x0c07bf48 */
if(!s->budget--) { s->failed_pc=0x0c07bf48u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07bf4a;
P_0c07bf4a: /* original 4408, guest PC 0x0c07bf4a */
if(!s->budget--) { s->failed_pc=0x0c07bf4au; return 0; }
r[4]<<=2;
goto P_0c07bf4c;
P_0c07bf4c: /* original 33fc, guest PC 0x0c07bf4c */
if(!s->budget--) { s->failed_pc=0x0c07bf4cu; return 0; }
r[3]+=r[15];
goto P_0c07bf4e;
P_0c07bf4e: /* original 313c, guest PC 0x0c07bf4e */
if(!s->budget--) { s->failed_pc=0x0c07bf4eu; return 0; }
r[1]+=r[3];
goto P_0c07bf50;
P_0c07bf50: /* original 314c, guest PC 0x0c07bf50 */
if(!s->budget--) { s->failed_pc=0x0c07bf50u; return 0; }
r[1]+=r[4];
goto P_0c07bf52;
P_0c07bf52: /* original 1f13, guest PC 0x0c07bf52 */
if(!s->budget--) { s->failed_pc=0x0c07bf52u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07bf54;
P_0c07bf54: /* original 2f16, guest PC 0x0c07bf54 */
if(!s->budget--) { s->failed_pc=0x0c07bf54u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07bf56;
P_0c07bf56: /* original 9277, guest PC 0x0c07bf56 */
if(!s->budget--) { s->failed_pc=0x0c07bf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c048u,2);
goto P_0c07bf58;
P_0c07bf58: /* original 51f3, guest PC 0x0c07bf58 */
if(!s->budget--) { s->failed_pc=0x0c07bf58u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07bf5a;
P_0c07bf5a: /* original 32fc, guest PC 0x0c07bf5a */
if(!s->budget--) { s->failed_pc=0x0c07bf5au; return 0; }
r[2]+=r[15];
goto P_0c07bf5c;
P_0c07bf5c: /* original 312c, guest PC 0x0c07bf5c */
if(!s->budget--) { s->failed_pc=0x0c07bf5cu; return 0; }
r[1]+=r[2];
goto P_0c07bf5e;
P_0c07bf5e: /* original 314c, guest PC 0x0c07bf5e */
if(!s->budget--) { s->failed_pc=0x0c07bf5eu; return 0; }
r[1]+=r[4];
goto P_0c07bf60;
P_0c07bf60: /* original 1f16, guest PC 0x0c07bf60 */
if(!s->budget--) { s->failed_pc=0x0c07bf60u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf62;
P_0c07bf62: /* original d33d, guest PC 0x0c07bf62 */
if(!s->budget--) { s->failed_pc=0x0c07bf62u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bf64;
P_0c07bf64: /* original 6112, guest PC 0x0c07bf64 */
if(!s->budget--) { s->failed_pc=0x0c07bf64u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bf66;
P_0c07bf66: /* original 430b, guest PC 0x0c07bf66 */
if(!s->budget--) { s->failed_pc=0x0c07bf66u; return 0; }
target=r[3];
r[16]=0x0c07bf6au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf6au) { target=s->pc; goto dispatch; }
goto P_0c07bf6a;
P_0c07bf68: /* original e00a, guest PC 0x0c07bf68 */
if(!s->budget--) { s->failed_pc=0x0c07bf68u; return 0; }
r[0]=0x0000000au;
goto P_0c07bf6a;
P_0c07bf6a: /* original 63f6, guest PC 0x0c07bf6a */
if(!s->budget--) { s->failed_pc=0x0c07bf6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07bf6c;
P_0c07bf6c: /* original e700, guest PC 0x0c07bf6c */
if(!s->budget--) { s->failed_pc=0x0c07bf6cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bf6e;
P_0c07bf6e: /* original 66d3, guest PC 0x0c07bf6e */
if(!s->budget--) { s->failed_pc=0x0c07bf6eu; return 0; }
r[6]=r[13];
goto P_0c07bf70;
P_0c07bf70: /* original 2302, guest PC 0x0c07bf70 */
if(!s->budget--) { s->failed_pc=0x0c07bf70u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bf72;
P_0c07bf72: /* original 51f1, guest PC 0x0c07bf72 */
if(!s->budget--) { s->failed_pc=0x0c07bf72u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bf74;
P_0c07bf74: /* original 53f7, guest PC 0x0c07bf74 */
if(!s->budget--) { s->failed_pc=0x0c07bf74u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c07bf76;
P_0c07bf76: /* original 213b, guest PC 0x0c07bf76 */
if(!s->budget--) { s->failed_pc=0x0c07bf76u; return 0; }
r[1]|=r[3];
goto P_0c07bf78;
P_0c07bf78: /* original 1f16, guest PC 0x0c07bf78 */
if(!s->budget--) { s->failed_pc=0x0c07bf78u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf7a;
P_0c07bf7a: /* original 2fb6, guest PC 0x0c07bf7a */
if(!s->budget--) { s->failed_pc=0x0c07bf7au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bf7c;
P_0c07bf7c: /* original 2fe6, guest PC 0x0c07bf7c */
if(!s->budget--) { s->failed_pc=0x0c07bf7cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bf7e;
P_0c07bf7e: /* original 50f5, guest PC 0x0c07bf7e */
if(!s->budget--) { s->failed_pc=0x0c07bf7eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c07bf80;
P_0c07bf80: /* original 6002, guest PC 0x0c07bf80 */
if(!s->budget--) { s->failed_pc=0x0c07bf80u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bf82;
P_0c07bf82: /* original 4008, guest PC 0x0c07bf82 */
if(!s->budget--) { s->failed_pc=0x0c07bf82u; return 0; }
r[0]<<=2;
goto P_0c07bf84;
P_0c07bf84: /* original 059e, guest PC 0x0c07bf84 */
if(!s->budget--) { s->failed_pc=0x0c07bf84u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bf86;
P_0c07bf86: /* original 480b, guest PC 0x0c07bf86 */
if(!s->budget--) { s->failed_pc=0x0c07bf86u; return 0; }
target=r[8];
r[16]=0x0c07bf8au;
r[4]=r[1];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf8au) { target=s->pc; goto dispatch; }
goto P_0c07bf8a;
P_0c07bf88: /* original 6413, guest PC 0x0c07bf88 */
if(!s->budget--) { s->failed_pc=0x0c07bf88u; return 0; }
r[4]=r[1];
goto P_0c07bf8a;
P_0c07bf8a: /* original 7f08, guest PC 0x0c07bf8a */
if(!s->budget--) { s->failed_pc=0x0c07bf8au; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf8c;
P_0c07bf8c: /* original 6403, guest PC 0x0c07bf8c */
if(!s->budget--) { s->failed_pc=0x0c07bf8cu; return 0; }
r[4]=r[0];
goto P_0c07bf8e;
P_0c07bf8e: /* original e030, guest PC 0x0c07bf8e */
if(!s->budget--) { s->failed_pc=0x0c07bf8eu; return 0; }
r[0]=0x00000030u;
goto P_0c07bf90;
P_0c07bf90: /* original f4f7, guest PC 0x0c07bf90 */
if(!s->budget--) { s->failed_pc=0x0c07bf90u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf92;
P_0c07bf92: /* original 52f3, guest PC 0x0c07bf92 */
if(!s->budget--) { s->failed_pc=0x0c07bf92u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07bf94;
P_0c07bf94: /* original 53f5, guest PC 0x0c07bf94 */
if(!s->budget--) { s->failed_pc=0x0c07bf94u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bf96;
P_0c07bf96: /* original 6222, guest PC 0x0c07bf96 */
if(!s->budget--) { s->failed_pc=0x0c07bf96u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07bf98;
P_0c07bf98: /* original 6032, guest PC 0x0c07bf98 */
if(!s->budget--) { s->failed_pc=0x0c07bf98u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bf9a;
P_0c07bf9a: /* original 6123, guest PC 0x0c07bf9a */
if(!s->budget--) { s->failed_pc=0x0c07bf9au; return 0; }
r[1]=r[2];
goto P_0c07bf9c;
P_0c07bf9c: /* original 4208, guest PC 0x0c07bf9c */
if(!s->budget--) { s->failed_pc=0x0c07bf9cu; return 0; }
r[2]<<=2;
goto P_0c07bf9e;
P_0c07bf9e: /* original 321c, guest PC 0x0c07bf9e */
if(!s->budget--) { s->failed_pc=0x0c07bf9eu; return 0; }
r[2]+=r[1];
goto P_0c07bfa0;
P_0c07bfa0: /* original 4200, guest PC 0x0c07bfa0 */
if(!s->budget--) { s->failed_pc=0x0c07bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bfa2;
P_0c07bfa2: /* original 3028, guest PC 0x0c07bfa2 */
if(!s->budget--) { s->failed_pc=0x0c07bfa2u; return 0; }
r[0]-=r[2];
goto P_0c07bfa4;
P_0c07bfa4: /* original 2302, guest PC 0x0c07bfa4 */
if(!s->budget--) { s->failed_pc=0x0c07bfa4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bfa6;
P_0c07bfa6: /* original 52f1, guest PC 0x0c07bfa6 */
if(!s->budget--) { s->failed_pc=0x0c07bfa6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07bfa8;
P_0c07bfa8: /* original e700, guest PC 0x0c07bfa8 */
if(!s->budget--) { s->failed_pc=0x0c07bfa8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bfaa;
P_0c07bfaa: /* original 53fb, guest PC 0x0c07bfaa */
if(!s->budget--) { s->failed_pc=0x0c07bfaau; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c07bfac;
P_0c07bfac: /* original 66d3, guest PC 0x0c07bfac */
if(!s->budget--) { s->failed_pc=0x0c07bfacu; return 0; }
r[6]=r[13];
goto P_0c07bfae;
P_0c07bfae: /* original 223b, guest PC 0x0c07bfae */
if(!s->budget--) { s->failed_pc=0x0c07bfaeu; return 0; }
r[2]|=r[3];
goto P_0c07bfb0;
P_0c07bfb0: /* original 1f23, guest PC 0x0c07bfb0 */
if(!s->budget--) { s->failed_pc=0x0c07bfb0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07bfb2;
P_0c07bfb2: /* original 2fb6, guest PC 0x0c07bfb2 */
if(!s->budget--) { s->failed_pc=0x0c07bfb2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bfb4;
P_0c07bfb4: /* original 2fe6, guest PC 0x0c07bfb4 */
if(!s->budget--) { s->failed_pc=0x0c07bfb4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07bfb6;
P_0c07bfb6: /* original 50fb, guest PC 0x0c07bfb6 */
if(!s->budget--) { s->failed_pc=0x0c07bfb6u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c07bfb8;
P_0c07bfb8: /* original 6002, guest PC 0x0c07bfb8 */
if(!s->budget--) { s->failed_pc=0x0c07bfb8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bfba;
P_0c07bfba: /* original 4008, guest PC 0x0c07bfba */
if(!s->budget--) { s->failed_pc=0x0c07bfbau; return 0; }
r[0]<<=2;
goto P_0c07bfbc;
P_0c07bfbc: /* original 059e, guest PC 0x0c07bfbc */
if(!s->budget--) { s->failed_pc=0x0c07bfbcu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bfbe;
P_0c07bfbe: /* original 480b, guest PC 0x0c07bfbe */
if(!s->budget--) { s->failed_pc=0x0c07bfbeu; return 0; }
target=r[8];
r[16]=0x0c07bfc2u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bfc2u) { target=s->pc; goto dispatch; }
goto P_0c07bfc2;
P_0c07bfc0: /* original 6423, guest PC 0x0c07bfc0 */
if(!s->budget--) { s->failed_pc=0x0c07bfc0u; return 0; }
r[4]=r[2];
goto P_0c07bfc2;
P_0c07bfc2: /* original 7f08, guest PC 0x0c07bfc2 */
if(!s->budget--) { s->failed_pc=0x0c07bfc2u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bfc4;
P_0c07bfc4: /* original 6403, guest PC 0x0c07bfc4 */
if(!s->budget--) { s->failed_pc=0x0c07bfc4u; return 0; }
r[4]=r[0];
goto P_0c07bfc6;
P_0c07bfc6: /* original e030, guest PC 0x0c07bfc6 */
if(!s->budget--) { s->failed_pc=0x0c07bfc6u; return 0; }
r[0]=0x00000030u;
goto P_0c07bfc8;
P_0c07bfc8: /* original f4f7, guest PC 0x0c07bfc8 */
if(!s->budget--) { s->failed_pc=0x0c07bfc8u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bfca;
P_0c07bfca: /* original 7c01, guest PC 0x0c07bfca */
if(!s->budget--) { s->failed_pc=0x0c07bfcau; return 0; }
r[12]+=0x00000001u;
goto P_0c07bfcc;
P_0c07bfcc: /* original 53f9, guest PC 0x0c07bfcc */
if(!s->budget--) { s->failed_pc=0x0c07bfccu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07bfce;
P_0c07bfce: /* original 7304, guest PC 0x0c07bfce */
if(!s->budget--) { s->failed_pc=0x0c07bfceu; return 0; }
r[3]+=0x00000004u;
goto P_0c07bfd0;
P_0c07bfd0: /* original 1f39, guest PC 0x0c07bfd0 */
if(!s->budget--) { s->failed_pc=0x0c07bfd0u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bfd2;
P_0c07bfd2: /* original 52fb, guest PC 0x0c07bfd2 */
if(!s->budget--) { s->failed_pc=0x0c07bfd2u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07bfd4;
P_0c07bfd4: /* original 7250, guest PC 0x0c07bfd4 */
if(!s->budget--) { s->failed_pc=0x0c07bfd4u; return 0; }
r[2]+=0x00000050u;
goto P_0c07bfd6;
P_0c07bfd6: /* original 1f2b, guest PC 0x0c07bfd6 */
if(!s->budget--) { s->failed_pc=0x0c07bfd6u; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07bfd8;
P_0c07bfd8: /* original 51f7, guest PC 0x0c07bfd8 */
if(!s->budget--) { s->failed_pc=0x0c07bfd8u; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bfda;
P_0c07bfda: /* original 7150, guest PC 0x0c07bfda */
if(!s->budget--) { s->failed_pc=0x0c07bfdau; return 0; }
r[1]+=0x00000050u;
goto P_0c07bfdc;
P_0c07bfdc: /* original 1f17, guest PC 0x0c07bfdc */
if(!s->budget--) { s->failed_pc=0x0c07bfdcu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bfde;
P_0c07bfde: /* original e302, guest PC 0x0c07bfde */
if(!s->budget--) { s->failed_pc=0x0c07bfdeu; return 0; }
r[3]=0x00000002u;
goto P_0c07bfe0;
P_0c07bfe0: /* original 3c33, guest PC 0x0c07bfe0 */
if(!s->budget--) { s->failed_pc=0x0c07bfe0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c07bfe2;
P_0c07bfe2: /* original 8901, guest PC 0x0c07bfe2 */
if(!s->budget--) { s->failed_pc=0x0c07bfe2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bfe8; }
goto P_0c07bfe4;
P_0c07bfe4: /* original ae96, guest PC 0x0c07bfe4 */
if(!s->budget--) { s->failed_pc=0x0c07bfe4u; return 0; }
goto P_0c07bd14;
P_0c07bfe6: /* original 0009, guest PC 0x0c07bfe6 */
if(!s->budget--) { s->failed_pc=0x0c07bfe6u; return 0; }
goto P_0c07bfe8;
P_0c07bfe8: /* original 51f8, guest PC 0x0c07bfe8 */
if(!s->budget--) { s->failed_pc=0x0c07bfe8u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bfea;
P_0c07bfea: /* original 7101, guest PC 0x0c07bfea */
if(!s->budget--) { s->failed_pc=0x0c07bfeau; return 0; }
r[1]+=0x00000001u;
goto P_0c07bfec;
P_0c07bfec: /* original 1f18, guest PC 0x0c07bfec */
if(!s->budget--) { s->failed_pc=0x0c07bfecu; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07bfee;
P_0c07bfee: /* original 52f8, guest PC 0x0c07bfee */
if(!s->budget--) { s->failed_pc=0x0c07bfeeu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07bff0;
P_0c07bff0: /* original e302, guest PC 0x0c07bff0 */
if(!s->budget--) { s->failed_pc=0x0c07bff0u; return 0; }
r[3]=0x00000002u;
goto P_0c07bff2;
P_0c07bff2: /* original 3233, guest PC 0x0c07bff2 */
if(!s->budget--) { s->failed_pc=0x0c07bff2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c07bff4;
P_0c07bff4: /* original 8901, guest PC 0x0c07bff4 */
if(!s->budget--) { s->failed_pc=0x0c07bff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bffa; }
goto P_0c07bff6;
P_0c07bff6: /* original ae64, guest PC 0x0c07bff6 */
if(!s->budget--) { s->failed_pc=0x0c07bff6u; return 0; }
goto P_0c07bcc2;
P_0c07bff8: /* original 0009, guest PC 0x0c07bff8 */
if(!s->budget--) { s->failed_pc=0x0c07bff8u; return 0; }
goto P_0c07bffa;
P_0c07bffa: /* original 2fb6, guest PC 0x0c07bffa */
if(!s->budget--) { s->failed_pc=0x0c07bffau; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07bffc;
P_0c07bffc: /* original e700, guest PC 0x0c07bffc */
if(!s->budget--) { s->failed_pc=0x0c07bffcu; return 0; }
r[7]=0x00000000u;
goto P_0c07bffe;
P_0c07bffe: /* original 2fe6, guest PC 0x0c07bffe */
if(!s->budget--) { s->failed_pc=0x0c07bffeu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c000;
P_0c07c000: /* original 9523, guest PC 0x0c07c000 */
if(!s->budget--) { s->failed_pc=0x0c07c000u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c002;
P_0c07c002: /* original 9423, guest PC 0x0c07c002 */
if(!s->budget--) { s->failed_pc=0x0c07c002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04cu,2);
goto P_0c07c004;
P_0c07c004: /* original 480b, guest PC 0x0c07c004 */
if(!s->budget--) { s->failed_pc=0x0c07c004u; return 0; }
target=r[8];
r[16]=0x0c07c008u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c008u) { target=s->pc; goto dispatch; }
goto P_0c07c008;
P_0c07c006: /* original 66d3, guest PC 0x0c07c006 */
if(!s->budget--) { s->failed_pc=0x0c07c006u; return 0; }
r[6]=r[13];
goto P_0c07c008;
P_0c07c008: /* original 6403, guest PC 0x0c07c008 */
if(!s->budget--) { s->failed_pc=0x0c07c008u; return 0; }
r[4]=r[0];
goto P_0c07c00a;
P_0c07c00a: /* original e030, guest PC 0x0c07c00a */
if(!s->budget--) { s->failed_pc=0x0c07c00au; return 0; }
r[0]=0x00000030u;
goto P_0c07c00c;
P_0c07c00c: /* original f4f7, guest PC 0x0c07c00c */
if(!s->budget--) { s->failed_pc=0x0c07c00cu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c00e;
P_0c07c00e: /* original e700, guest PC 0x0c07c00e */
if(!s->budget--) { s->failed_pc=0x0c07c00eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c010;
P_0c07c010: /* original 2fb6, guest PC 0x0c07c010 */
if(!s->budget--) { s->failed_pc=0x0c07c010u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c012;
P_0c07c012: /* original 2fe6, guest PC 0x0c07c012 */
if(!s->budget--) { s->failed_pc=0x0c07c012u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c014;
P_0c07c014: /* original 951b, guest PC 0x0c07c014 */
if(!s->budget--) { s->failed_pc=0x0c07c014u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c016;
P_0c07c016: /* original 941b, guest PC 0x0c07c016 */
if(!s->budget--) { s->failed_pc=0x0c07c016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c050u,2);
goto P_0c07c018;
P_0c07c018: /* original 480b, guest PC 0x0c07c018 */
if(!s->budget--) { s->failed_pc=0x0c07c018u; return 0; }
target=r[8];
r[16]=0x0c07c01cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c01cu) { target=s->pc; goto dispatch; }
goto P_0c07c01c;
P_0c07c01a: /* original 66d3, guest PC 0x0c07c01a */
if(!s->budget--) { s->failed_pc=0x0c07c01au; return 0; }
r[6]=r[13];
goto P_0c07c01c;
P_0c07c01c: /* original 6403, guest PC 0x0c07c01c */
if(!s->budget--) { s->failed_pc=0x0c07c01cu; return 0; }
r[4]=r[0];
goto P_0c07c01e;
P_0c07c01e: /* original e030, guest PC 0x0c07c01e */
if(!s->budget--) { s->failed_pc=0x0c07c01eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c020;
P_0c07c020: /* original f4f7, guest PC 0x0c07c020 */
if(!s->budget--) { s->failed_pc=0x0c07c020u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c022;
P_0c07c022: /* original e700, guest PC 0x0c07c022 */
if(!s->budget--) { s->failed_pc=0x0c07c022u; return 0; }
r[7]=0x00000000u;
goto P_0c07c024;
P_0c07c024: /* original 2fb6, guest PC 0x0c07c024 */
if(!s->budget--) { s->failed_pc=0x0c07c024u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c026;
P_0c07c026: /* original 2fe6, guest PC 0x0c07c026 */
if(!s->budget--) { s->failed_pc=0x0c07c026u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c028;
P_0c07c028: /* original 950f, guest PC 0x0c07c028 */
if(!s->budget--) { s->failed_pc=0x0c07c028u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c02a;
P_0c07c02a: /* original 9412, guest PC 0x0c07c02a */
if(!s->budget--) { s->failed_pc=0x0c07c02au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c052u,2);
goto P_0c07c02c;
P_0c07c02c: /* original 480b, guest PC 0x0c07c02c */
if(!s->budget--) { s->failed_pc=0x0c07c02cu; return 0; }
target=r[8];
r[16]=0x0c07c030u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c030u) { target=s->pc; goto dispatch; }
goto P_0c07c030;
P_0c07c02e: /* original 66d3, guest PC 0x0c07c02e */
if(!s->budget--) { s->failed_pc=0x0c07c02eu; return 0; }
r[6]=r[13];
goto P_0c07c030;
P_0c07c030: /* original 6403, guest PC 0x0c07c030 */
if(!s->budget--) { s->failed_pc=0x0c07c030u; return 0; }
r[4]=r[0];
goto P_0c07c032;
P_0c07c032: /* original e030, guest PC 0x0c07c032 */
if(!s->budget--) { s->failed_pc=0x0c07c032u; return 0; }
r[0]=0x00000030u;
goto P_0c07c034;
P_0c07c034: /* original f4f7, guest PC 0x0c07c034 */
if(!s->budget--) { s->failed_pc=0x0c07c034u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c036;
P_0c07c036: /* original e700, guest PC 0x0c07c036 */
if(!s->budget--) { s->failed_pc=0x0c07c036u; return 0; }
r[7]=0x00000000u;
goto P_0c07c038;
P_0c07c038: /* original 2fb6, guest PC 0x0c07c038 */
if(!s->budget--) { s->failed_pc=0x0c07c038u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c03a;
P_0c07c03a: /* original 2fe6, guest PC 0x0c07c03a */
if(!s->budget--) { s->failed_pc=0x0c07c03au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c03c;
P_0c07c03c: /* original 9507, guest PC 0x0c07c03c */
if(!s->budget--) { s->failed_pc=0x0c07c03cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c03e;
P_0c07c03e: /* original 9409, guest PC 0x0c07c03e */
if(!s->budget--) { s->failed_pc=0x0c07c03eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c054u,2);
goto P_0c07c040;
P_0c07c040: /* original a00c, guest PC 0x0c07c040 */
if(!s->budget--) { s->failed_pc=0x0c07c040u; return 0; }
r[6]=r[13];
goto P_0c07c05c;
P_0c07c042: /* original 66d3, guest PC 0x0c07c042 */
if(!s->budget--) { s->failed_pc=0x0c07c042u; return 0; }
r[6]=r[13];
return vf3_matrix_family(0x0c07c044u,s,ram);
P_0c07c05c: /* original 480b, guest PC 0x0c07c05c */
if(!s->budget--) { s->failed_pc=0x0c07c05cu; return 0; }
target=r[8];
r[16]=0x0c07c060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c060u) { target=s->pc; goto dispatch; }
goto P_0c07c060;
P_0c07c05e: /* original 0009, guest PC 0x0c07c05e */
if(!s->budget--) { s->failed_pc=0x0c07c05eu; return 0; }
goto P_0c07c060;
P_0c07c060: /* original 6403, guest PC 0x0c07c060 */
if(!s->budget--) { s->failed_pc=0x0c07c060u; return 0; }
r[4]=r[0];
goto P_0c07c062;
P_0c07c062: /* original e030, guest PC 0x0c07c062 */
if(!s->budget--) { s->failed_pc=0x0c07c062u; return 0; }
r[0]=0x00000030u;
goto P_0c07c064;
P_0c07c064: /* original f4f7, guest PC 0x0c07c064 */
if(!s->budget--) { s->failed_pc=0x0c07c064u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c066;
P_0c07c066: /* original d329, guest PC 0x0c07c066 */
if(!s->budget--) { s->failed_pc=0x0c07c066u; return 0; }
r[3]=read(ram,0x0c07c10cu,4);
goto P_0c07c068;
P_0c07c068: /* original 944c, guest PC 0x0c07c068 */
if(!s->budget--) { s->failed_pc=0x0c07c068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c104u,2);
goto P_0c07c06a;
P_0c07c06a: /* original 430b, guest PC 0x0c07c06a */
if(!s->budget--) { s->failed_pc=0x0c07c06au; return 0; }
target=r[3];
r[16]=0x0c07c06eu;
r[15]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c06eu) { target=s->pc; goto dispatch; }
goto P_0c07c06e;
P_0c07c06c: /* original 7f20, guest PC 0x0c07c06c */
if(!s->budget--) { s->failed_pc=0x0c07c06cu; return 0; }
r[15]+=0x00000020u;
goto P_0c07c06e;
P_0c07c06e: /* original 6d03, guest PC 0x0c07c06e */
if(!s->budget--) { s->failed_pc=0x0c07c06eu; return 0; }
r[13]=r[0];
goto P_0c07c070;
P_0c07c070: /* original 52d8, guest PC 0x0c07c070 */
if(!s->budget--) { s->failed_pc=0x0c07c070u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c07c072;
P_0c07c072: /* original e040, guest PC 0x0c07c072 */
if(!s->budget--) { s->failed_pc=0x0c07c072u; return 0; }
r[0]=0x00000040u;
goto P_0c07c074;
P_0c07c074: /* original 64f3, guest PC 0x0c07c074 */
if(!s->budget--) { s->failed_pc=0x0c07c074u; return 0; }
r[4]=r[15];
goto P_0c07c076;
P_0c07c076: /* original 0f26, guest PC 0x0c07c076 */
if(!s->budget--) { s->failed_pc=0x0c07c076u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07c078;
P_0c07c078: /* original c725, guest PC 0x0c07c078 */
if(!s->budget--) { s->failed_pc=0x0c07c078u; return 0; }
r[0]=0x0c07c110u;
goto P_0c07c07a;
P_0c07c07a: /* original f308, guest PC 0x0c07c07a */
if(!s->budget--) { s->failed_pc=0x0c07c07au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c07c;
P_0c07c07c: /* original e018, guest PC 0x0c07c07c */
if(!s->budget--) { s->failed_pc=0x0c07c07cu; return 0; }
r[0]=0x00000018u;
goto P_0c07c07e;
P_0c07c07e: /* original f6d6, guest PC 0x0c07c07e */
if(!s->budget--) { s->failed_pc=0x0c07c07eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c080;
P_0c07c080: /* original c724, guest PC 0x0c07c080 */
if(!s->budget--) { s->failed_pc=0x0c07c080u; return 0; }
r[0]=0x0c07c114u;
goto P_0c07c082;
P_0c07c082: /* original f208, guest PC 0x0c07c082 */
if(!s->budget--) { s->failed_pc=0x0c07c082u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07c084;
P_0c07c084: /* original e01c, guest PC 0x0c07c084 */
if(!s->budget--) { s->failed_pc=0x0c07c084u; return 0; }
r[0]=0x0000001cu;
goto P_0c07c086;
P_0c07c086: /* original f7d6, guest PC 0x0c07c086 */
if(!s->budget--) { s->failed_pc=0x0c07c086u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c088;
P_0c07c088: /* original f632, guest PC 0x0c07c088 */
if(!s->budget--) { s->failed_pc=0x0c07c088u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c07c08a;
P_0c07c08a: /* original c723, guest PC 0x0c07c08a */
if(!s->budget--) { s->failed_pc=0x0c07c08au; return 0; }
r[0]=0x0c07c118u;
goto P_0c07c08c;
P_0c07c08c: /* original d323, guest PC 0x0c07c08c */
if(!s->budget--) { s->failed_pc=0x0c07c08cu; return 0; }
r[3]=read(ram,0x0c07c11cu,4);
goto P_0c07c08e;
P_0c07c08e: /* original f722, guest PC 0x0c07c08e */
if(!s->budget--) { s->failed_pc=0x0c07c08eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c07c090;
P_0c07c090: /* original f808, guest PC 0x0c07c090 */
if(!s->budget--) { s->failed_pc=0x0c07c090u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c07c092;
P_0c07c092: /* original f5ec, guest PC 0x0c07c092 */
if(!s->budget--) { s->failed_pc=0x0c07c092u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c07c094;
P_0c07c094: /* original f4ec, guest PC 0x0c07c094 */
if(!s->budget--) { s->failed_pc=0x0c07c094u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07c096;
P_0c07c096: /* original 430b, guest PC 0x0c07c096 */
if(!s->budget--) { s->failed_pc=0x0c07c096u; return 0; }
target=r[3];
r[16]=0x0c07c09au;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c09au) { target=s->pc; goto dispatch; }
goto P_0c07c09a;
P_0c07c098: /* original 7440, guest PC 0x0c07c098 */
if(!s->budget--) { s->failed_pc=0x0c07c098u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c09a;
P_0c07c09a: /* original e014, guest PC 0x0c07c09a */
if(!s->budget--) { s->failed_pc=0x0c07c09au; return 0; }
r[0]=0x00000014u;
goto P_0c07c09c;
P_0c07c09c: /* original d320, guest PC 0x0c07c09c */
if(!s->budget--) { s->failed_pc=0x0c07c09cu; return 0; }
r[3]=read(ram,0x0c07c120u,4);
goto P_0c07c09e;
P_0c07c09e: /* original f9d6, guest PC 0x0c07c09e */
if(!s->budget--) { s->failed_pc=0x0c07c09eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c07c0a0;
P_0c07c0a0: /* original e010, guest PC 0x0c07c0a0 */
if(!s->budget--) { s->failed_pc=0x0c07c0a0u; return 0; }
r[0]=0x00000010u;
goto P_0c07c0a2;
P_0c07c0a2: /* original f8d6, guest PC 0x0c07c0a2 */
if(!s->budget--) { s->failed_pc=0x0c07c0a2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c07c0a4;
P_0c07c0a4: /* original e00c, guest PC 0x0c07c0a4 */
if(!s->budget--) { s->failed_pc=0x0c07c0a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c07c0a6;
P_0c07c0a6: /* original f7d6, guest PC 0x0c07c0a6 */
if(!s->budget--) { s->failed_pc=0x0c07c0a6u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c0a8;
P_0c07c0a8: /* original e008, guest PC 0x0c07c0a8 */
if(!s->budget--) { s->failed_pc=0x0c07c0a8u; return 0; }
r[0]=0x00000008u;
goto P_0c07c0aa;
P_0c07c0aa: /* original f6d6, guest PC 0x0c07c0aa */
if(!s->budget--) { s->failed_pc=0x0c07c0aau; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c0ac;
P_0c07c0ac: /* original e004, guest PC 0x0c07c0ac */
if(!s->budget--) { s->failed_pc=0x0c07c0acu; return 0; }
r[0]=0x00000004u;
goto P_0c07c0ae;
P_0c07c0ae: /* original f4d8, guest PC 0x0c07c0ae */
if(!s->budget--) { s->failed_pc=0x0c07c0aeu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c07c0b0;
P_0c07c0b0: /* original 64f3, guest PC 0x0c07c0b0 */
if(!s->budget--) { s->failed_pc=0x0c07c0b0u; return 0; }
r[4]=r[15];
goto P_0c07c0b2;
P_0c07c0b2: /* original f5d6, guest PC 0x0c07c0b2 */
if(!s->budget--) { s->failed_pc=0x0c07c0b2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c07c0b4;
P_0c07c0b4: /* original 430b, guest PC 0x0c07c0b4 */
if(!s->budget--) { s->failed_pc=0x0c07c0b4u; return 0; }
target=r[3];
r[16]=0x0c07c0b8u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0b8u) { target=s->pc; goto dispatch; }
goto P_0c07c0b8;
P_0c07c0b6: /* original 7440, guest PC 0x0c07c0b6 */
if(!s->budget--) { s->failed_pc=0x0c07c0b6u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0b8;
P_0c07c0b8: /* original e068, guest PC 0x0c07c0b8 */
if(!s->budget--) { s->failed_pc=0x0c07c0b8u; return 0; }
r[0]=0x00000068u;
goto P_0c07c0ba;
P_0c07c0ba: /* original 64f3, guest PC 0x0c07c0ba */
if(!s->budget--) { s->failed_pc=0x0c07c0bau; return 0; }
r[4]=r[15];
goto P_0c07c0bc;
P_0c07c0bc: /* original 0fe6, guest PC 0x0c07c0bc */
if(!s->budget--) { s->failed_pc=0x0c07c0bcu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c07c0be;
P_0c07c0be: /* original e06c, guest PC 0x0c07c0be */
if(!s->budget--) { s->failed_pc=0x0c07c0beu; return 0; }
r[0]=0x0000006cu;
goto P_0c07c0c0;
P_0c07c0c0: /* original 9321, guest PC 0x0c07c0c0 */
if(!s->budget--) { s->failed_pc=0x0c07c0c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c106u,2);
goto P_0c07c0c2;
P_0c07c0c2: /* original 0f36, guest PC 0x0c07c0c2 */
if(!s->budget--) { s->failed_pc=0x0c07c0c2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07c0c4;
P_0c07c0c4: /* original c717, guest PC 0x0c07c0c4 */
if(!s->budget--) { s->failed_pc=0x0c07c0c4u; return 0; }
r[0]=0x0c07c124u;
goto P_0c07c0c6;
P_0c07c0c6: /* original f308, guest PC 0x0c07c0c6 */
if(!s->budget--) { s->failed_pc=0x0c07c0c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c0c8;
P_0c07c0c8: /* original e070, guest PC 0x0c07c0c8 */
if(!s->budget--) { s->failed_pc=0x0c07c0c8u; return 0; }
r[0]=0x00000070u;
goto P_0c07c0ca;
P_0c07c0ca: /* original ff37, guest PC 0x0c07c0ca */
if(!s->budget--) { s->failed_pc=0x0c07c0cau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c07c0cc;
P_0c07c0cc: /* original d316, guest PC 0x0c07c0cc */
if(!s->budget--) { s->failed_pc=0x0c07c0ccu; return 0; }
r[3]=read(ram,0x0c07c128u,4);
goto P_0c07c0ce;
P_0c07c0ce: /* original 430b, guest PC 0x0c07c0ce */
if(!s->budget--) { s->failed_pc=0x0c07c0ceu; return 0; }
target=r[3];
r[16]=0x0c07c0d2u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0d2u) { target=s->pc; goto dispatch; }
goto P_0c07c0d2;
P_0c07c0d0: /* original 7440, guest PC 0x0c07c0d0 */
if(!s->budget--) { s->failed_pc=0x0c07c0d0u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0d2;
P_0c07c0d2: /* original a0eb, guest PC 0x0c07c0d2 */
if(!s->budget--) { s->failed_pc=0x0c07c0d2u; return 0; }
goto P_0c07c2ac;
P_0c07c0d4: /* original 0009, guest PC 0x0c07c0d4 */
if(!s->budget--) { s->failed_pc=0x0c07c0d4u; return 0; }
goto P_0c07c0d6;
P_0c07c0d6: /* original a0ba, guest PC 0x0c07c0d6 */
if(!s->budget--) { s->failed_pc=0x0c07c0d6u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c24e;
P_0c07c0d8: /* original 1fe9, guest PC 0x0c07c0d8 */
if(!s->budget--) { s->failed_pc=0x0c07c0d8u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c0da;
P_0c07c0da: /* original e122, guest PC 0x0c07c0da */
if(!s->budget--) { s->failed_pc=0x0c07c0dau; return 0; }
r[1]=0x00000022u;
goto P_0c07c0dc;
P_0c07c0dc: /* original 1fe2, guest PC 0x0c07c0dc */
if(!s->budget--) { s->failed_pc=0x0c07c0dcu; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c07c0de;
P_0c07c0de: /* original 53f9, guest PC 0x0c07c0de */
if(!s->budget--) { s->failed_pc=0x0c07c0deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c0e0;
P_0c07c0e0: /* original e007, guest PC 0x0c07c0e0 */
if(!s->budget--) { s->failed_pc=0x0c07c0e0u; return 0; }
r[0]=0x00000007u;
goto P_0c07c0e2;
P_0c07c0e2: /* original 4308, guest PC 0x0c07c0e2 */
if(!s->budget--) { s->failed_pc=0x0c07c0e2u; return 0; }
r[3]<<=2;
goto P_0c07c0e4;
P_0c07c0e4: /* original 4300, guest PC 0x0c07c0e4 */
if(!s->budget--) { s->failed_pc=0x0c07c0e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07c0e6;
P_0c07c0e6: /* original 2f32, guest PC 0x0c07c0e6 */
if(!s->budget--) { s->failed_pc=0x0c07c0e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07c0e8;
P_0c07c0e8: /* original 920e, guest PC 0x0c07c0e8 */
if(!s->budget--) { s->failed_pc=0x0c07c0e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c108u,2);
goto P_0c07c0ea;
P_0c07c0ea: /* original 32fc, guest PC 0x0c07c0ea */
if(!s->budget--) { s->failed_pc=0x0c07c0eau; return 0; }
r[2]+=r[15];
goto P_0c07c0ec;
P_0c07c0ec: /* original 332c, guest PC 0x0c07c0ec */
if(!s->budget--) { s->failed_pc=0x0c07c0ecu; return 0; }
r[3]+=r[2];
goto P_0c07c0ee;
P_0c07c0ee: /* original 1f34, guest PC 0x0c07c0ee */
if(!s->budget--) { s->failed_pc=0x0c07c0eeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07c0f0;
P_0c07c0f0: /* original 1f3b, guest PC 0x0c07c0f0 */
if(!s->budget--) { s->failed_pc=0x0c07c0f0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c07c0f2;
P_0c07c0f2: /* original 1f13, guest PC 0x0c07c0f2 */
if(!s->budget--) { s->failed_pc=0x0c07c0f2u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c0f4;
P_0c07c0f4: /* original e11e, guest PC 0x0c07c0f4 */
if(!s->budget--) { s->failed_pc=0x0c07c0f4u; return 0; }
r[1]=0x0000001eu;
goto P_0c07c0f6;
P_0c07c0f6: /* original 1f18, guest PC 0x0c07c0f6 */
if(!s->budget--) { s->failed_pc=0x0c07c0f6u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07c0f8;
P_0c07c0f8: /* original 51f9, guest PC 0x0c07c0f8 */
if(!s->budget--) { s->failed_pc=0x0c07c0f8u; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c0fa;
P_0c07c0fa: /* original 4100, guest PC 0x0c07c0fa */
if(!s->budget--) { s->failed_pc=0x0c07c0fau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07c0fc;
P_0c07c0fc: /* original 7102, guest PC 0x0c07c0fc */
if(!s->budget--) { s->failed_pc=0x0c07c0fcu; return 0; }
r[1]+=0x00000002u;
goto P_0c07c0fe;
P_0c07c0fe: /* original 410c, guest PC 0x0c07c0fe */
if(!s->budget--) { s->failed_pc=0x0c07c0feu; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07c100;
P_0c07c100: /* original a09c, guest PC 0x0c07c100 */
if(!s->budget--) { s->failed_pc=0x0c07c100u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07c23c;
P_0c07c102: /* original 1f11, guest PC 0x0c07c102 */
if(!s->budget--) { s->failed_pc=0x0c07c102u; return 0; }
write(ram,r[15]+4,r[1],4);
return vf3_matrix_family(0x0c07c104u,s,ram);
P_0c07c12c: /* original 5cf2, guest PC 0x0c07c12c */
if(!s->budget--) { s->failed_pc=0x0c07c12cu; return 0; }
r[12]=read(ram,r[15]+8,4);
goto P_0c07c12e;
P_0c07c12e: /* original 50f4, guest PC 0x0c07c12e */
if(!s->budget--) { s->failed_pc=0x0c07c12eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c130;
P_0c07c130: /* original 4c08, guest PC 0x0c07c130 */
if(!s->budget--) { s->failed_pc=0x0c07c130u; return 0; }
r[12]<<=2;
goto P_0c07c132;
P_0c07c132: /* original 03ce, guest PC 0x0c07c132 */
if(!s->budget--) { s->failed_pc=0x0c07c132u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c134;
P_0c07c134: /* original 33a3, guest PC 0x0c07c134 */
if(!s->budget--) { s->failed_pc=0x0c07c134u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07c136;
P_0c07c136: /* original 8b31, guest PC 0x0c07c136 */
if(!s->budget--) { s->failed_pc=0x0c07c136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c19c; }
goto P_0c07c138;
P_0c07c138: /* original 93bd, guest PC 0x0c07c138 */
if(!s->budget--) { s->failed_pc=0x0c07c138u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c13a;
P_0c07c13a: /* original 62f2, guest PC 0x0c07c13a */
if(!s->budget--) { s->failed_pc=0x0c07c13au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c13c;
P_0c07c13c: /* original 33fc, guest PC 0x0c07c13c */
if(!s->budget--) { s->failed_pc=0x0c07c13cu; return 0; }
r[3]+=r[15];
goto P_0c07c13e;
P_0c07c13e: /* original 323c, guest PC 0x0c07c13e */
if(!s->budget--) { s->failed_pc=0x0c07c13eu; return 0; }
r[2]+=r[3];
goto P_0c07c140;
P_0c07c140: /* original 32cc, guest PC 0x0c07c140 */
if(!s->budget--) { s->failed_pc=0x0c07c140u; return 0; }
r[2]+=r[12];
goto P_0c07c142;
P_0c07c142: /* original 1f27, guest PC 0x0c07c142 */
if(!s->budget--) { s->failed_pc=0x0c07c142u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07c144;
P_0c07c144: /* original 90b8, guest PC 0x0c07c144 */
if(!s->budget--) { s->failed_pc=0x0c07c144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b8u,2);
goto P_0c07c146;
P_0c07c146: /* original 61f2, guest PC 0x0c07c146 */
if(!s->budget--) { s->failed_pc=0x0c07c146u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c148;
P_0c07c148: /* original 30fc, guest PC 0x0c07c148 */
if(!s->budget--) { s->failed_pc=0x0c07c148u; return 0; }
r[0]+=r[15];
goto P_0c07c14a;
P_0c07c14a: /* original 310c, guest PC 0x0c07c14a */
if(!s->budget--) { s->failed_pc=0x0c07c14au; return 0; }
r[1]+=r[0];
goto P_0c07c14c;
P_0c07c14c: /* original 31cc, guest PC 0x0c07c14c */
if(!s->budget--) { s->failed_pc=0x0c07c14cu; return 0; }
r[1]+=r[12];
goto P_0c07c14e;
P_0c07c14e: /* original 1f1a, guest PC 0x0c07c14e */
if(!s->budget--) { s->failed_pc=0x0c07c14eu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07c150;
P_0c07c150: /* original 6112, guest PC 0x0c07c150 */
if(!s->budget--) { s->failed_pc=0x0c07c150u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c152;
P_0c07c152: /* original d35d, guest PC 0x0c07c152 */
if(!s->budget--) { s->failed_pc=0x0c07c152u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c154;
P_0c07c154: /* original 430b, guest PC 0x0c07c154 */
if(!s->budget--) { s->failed_pc=0x0c07c154u; return 0; }
target=r[3];
r[16]=0x0c07c158u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c158u) { target=s->pc; goto dispatch; }
goto P_0c07c158;
P_0c07c156: /* original 60a3, guest PC 0x0c07c156 */
if(!s->budget--) { s->failed_pc=0x0c07c156u; return 0; }
r[0]=r[10];
goto P_0c07c158;
P_0c07c158: /* original 2202, guest PC 0x0c07c158 */
if(!s->budget--) { s->failed_pc=0x0c07c158u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07c15a;
P_0c07c15a: /* original e700, guest PC 0x0c07c15a */
if(!s->budget--) { s->failed_pc=0x0c07c15au; return 0; }
r[7]=0x00000000u;
goto P_0c07c15c;
P_0c07c15c: /* original 52f2, guest PC 0x0c07c15c */
if(!s->budget--) { s->failed_pc=0x0c07c15cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07c15e;
P_0c07c15e: /* original 66d3, guest PC 0x0c07c15e */
if(!s->budget--) { s->failed_pc=0x0c07c15eu; return 0; }
r[6]=r[13];
goto P_0c07c160;
P_0c07c160: /* original 6323, guest PC 0x0c07c160 */
if(!s->budget--) { s->failed_pc=0x0c07c160u; return 0; }
r[3]=r[2];
goto P_0c07c162;
P_0c07c162: /* original 4208, guest PC 0x0c07c162 */
if(!s->budget--) { s->failed_pc=0x0c07c162u; return 0; }
r[2]<<=2;
goto P_0c07c164;
P_0c07c164: /* original 323c, guest PC 0x0c07c164 */
if(!s->budget--) { s->failed_pc=0x0c07c164u; return 0; }
r[2]+=r[3];
goto P_0c07c166;
P_0c07c166: /* original 53f1, guest PC 0x0c07c166 */
if(!s->budget--) { s->failed_pc=0x0c07c166u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c168;
P_0c07c168: /* original 4208, guest PC 0x0c07c168 */
if(!s->budget--) { s->failed_pc=0x0c07c168u; return 0; }
r[2]<<=2;
goto P_0c07c16a;
P_0c07c16a: /* original 4200, guest PC 0x0c07c16a */
if(!s->budget--) { s->failed_pc=0x0c07c16au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c16c;
P_0c07c16c: /* original 720d, guest PC 0x0c07c16c */
if(!s->budget--) { s->failed_pc=0x0c07c16cu; return 0; }
r[2]+=0x0000000du;
goto P_0c07c16e;
P_0c07c16e: /* original 4200, guest PC 0x0c07c16e */
if(!s->budget--) { s->failed_pc=0x0c07c16eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c170;
P_0c07c170: /* original 223b, guest PC 0x0c07c170 */
if(!s->budget--) { s->failed_pc=0x0c07c170u; return 0; }
r[2]|=r[3];
goto P_0c07c172;
P_0c07c172: /* original 1f25, guest PC 0x0c07c172 */
if(!s->budget--) { s->failed_pc=0x0c07c172u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07c174;
P_0c07c174: /* original 2fb6, guest PC 0x0c07c174 */
if(!s->budget--) { s->failed_pc=0x0c07c174u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c176;
P_0c07c176: /* original 2fe6, guest PC 0x0c07c176 */
if(!s->budget--) { s->failed_pc=0x0c07c176u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c178;
P_0c07c178: /* original 50f9, guest PC 0x0c07c178 */
if(!s->budget--) { s->failed_pc=0x0c07c178u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c17a;
P_0c07c17a: /* original 6002, guest PC 0x0c07c17a */
if(!s->budget--) { s->failed_pc=0x0c07c17au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c17c;
P_0c07c17c: /* original 4008, guest PC 0x0c07c17c */
if(!s->budget--) { s->failed_pc=0x0c07c17cu; return 0; }
r[0]<<=2;
goto P_0c07c17e;
P_0c07c17e: /* original 059e, guest PC 0x0c07c17e */
if(!s->budget--) { s->failed_pc=0x0c07c17eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c180;
P_0c07c180: /* original 480b, guest PC 0x0c07c180 */
if(!s->budget--) { s->failed_pc=0x0c07c180u; return 0; }
target=r[8];
r[16]=0x0c07c184u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c184u) { target=s->pc; goto dispatch; }
goto P_0c07c184;
P_0c07c182: /* original 6423, guest PC 0x0c07c182 */
if(!s->budget--) { s->failed_pc=0x0c07c182u; return 0; }
r[4]=r[2];
goto P_0c07c184;
P_0c07c184: /* original 7f08, guest PC 0x0c07c184 */
if(!s->budget--) { s->failed_pc=0x0c07c184u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c186;
P_0c07c186: /* original 6403, guest PC 0x0c07c186 */
if(!s->budget--) { s->failed_pc=0x0c07c186u; return 0; }
r[4]=r[0];
goto P_0c07c188;
P_0c07c188: /* original e030, guest PC 0x0c07c188 */
if(!s->budget--) { s->failed_pc=0x0c07c188u; return 0; }
r[0]=0x00000030u;
goto P_0c07c18a;
P_0c07c18a: /* original f4e7, guest PC 0x0c07c18a */
if(!s->budget--) { s->failed_pc=0x0c07c18au; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c18c;
P_0c07c18c: /* original 52f7, guest PC 0x0c07c18c */
if(!s->budget--) { s->failed_pc=0x0c07c18cu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c18e;
P_0c07c18e: /* original 53fa, guest PC 0x0c07c18e */
if(!s->budget--) { s->failed_pc=0x0c07c18eu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c190;
P_0c07c190: /* original 6122, guest PC 0x0c07c190 */
if(!s->budget--) { s->failed_pc=0x0c07c190u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07c192;
P_0c07c192: /* original 6232, guest PC 0x0c07c192 */
if(!s->budget--) { s->failed_pc=0x0c07c192u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07c194;
P_0c07c194: /* original 01a7, guest PC 0x0c07c194 */
if(!s->budget--) { s->failed_pc=0x0c07c194u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07c196;
P_0c07c196: /* original 011a, guest PC 0x0c07c196 */
if(!s->budget--) { s->failed_pc=0x0c07c196u; return 0; }
r[1]=r[19];
goto P_0c07c198;
P_0c07c198: /* original 3218, guest PC 0x0c07c198 */
if(!s->budget--) { s->failed_pc=0x0c07c198u; return 0; }
r[2]-=r[1];
goto P_0c07c19a;
P_0c07c19a: /* original 2322, guest PC 0x0c07c19a */
if(!s->budget--) { s->failed_pc=0x0c07c19au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c19c;
P_0c07c19c: /* original 50f4, guest PC 0x0c07c19c */
if(!s->budget--) { s->failed_pc=0x0c07c19cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c19e;
P_0c07c19e: /* original e20a, guest PC 0x0c07c19e */
if(!s->budget--) { s->failed_pc=0x0c07c19eu; return 0; }
r[2]=0x0000000au;
goto P_0c07c1a0;
P_0c07c1a0: /* original 03ce, guest PC 0x0c07c1a0 */
if(!s->budget--) { s->failed_pc=0x0c07c1a0u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c1a2;
P_0c07c1a2: /* original 3323, guest PC 0x0c07c1a2 */
if(!s->budget--) { s->failed_pc=0x0c07c1a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07c1a4;
P_0c07c1a4: /* original 8b2d, guest PC 0x0c07c1a4 */
if(!s->budget--) { s->failed_pc=0x0c07c1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c202; }
goto P_0c07c1a6;
P_0c07c1a6: /* original 9386, guest PC 0x0c07c1a6 */
if(!s->budget--) { s->failed_pc=0x0c07c1a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c1a8;
P_0c07c1a8: /* original 61f2, guest PC 0x0c07c1a8 */
if(!s->budget--) { s->failed_pc=0x0c07c1a8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c1aa;
P_0c07c1aa: /* original 33fc, guest PC 0x0c07c1aa */
if(!s->budget--) { s->failed_pc=0x0c07c1aau; return 0; }
r[3]+=r[15];
goto P_0c07c1ac;
P_0c07c1ac: /* original 313c, guest PC 0x0c07c1ac */
if(!s->budget--) { s->failed_pc=0x0c07c1acu; return 0; }
r[1]+=r[3];
goto P_0c07c1ae;
P_0c07c1ae: /* original 31cc, guest PC 0x0c07c1ae */
if(!s->budget--) { s->failed_pc=0x0c07c1aeu; return 0; }
r[1]+=r[12];
goto P_0c07c1b0;
P_0c07c1b0: /* original 1f17, guest PC 0x0c07c1b0 */
if(!s->budget--) { s->failed_pc=0x0c07c1b0u; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07c1b2;
P_0c07c1b2: /* original 2f16, guest PC 0x0c07c1b2 */
if(!s->budget--) { s->failed_pc=0x0c07c1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07c1b4;
P_0c07c1b4: /* original 9281, guest PC 0x0c07c1b4 */
if(!s->budget--) { s->failed_pc=0x0c07c1b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bau,2);
goto P_0c07c1b6;
P_0c07c1b6: /* original 51f1, guest PC 0x0c07c1b6 */
if(!s->budget--) { s->failed_pc=0x0c07c1b6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07c1b8;
P_0c07c1b8: /* original 32fc, guest PC 0x0c07c1b8 */
if(!s->budget--) { s->failed_pc=0x0c07c1b8u; return 0; }
r[2]+=r[15];
goto P_0c07c1ba;
P_0c07c1ba: /* original 312c, guest PC 0x0c07c1ba */
if(!s->budget--) { s->failed_pc=0x0c07c1bau; return 0; }
r[1]+=r[2];
goto P_0c07c1bc;
P_0c07c1bc: /* original 31cc, guest PC 0x0c07c1bc */
if(!s->budget--) { s->failed_pc=0x0c07c1bcu; return 0; }
r[1]+=r[12];
goto P_0c07c1be;
P_0c07c1be: /* original 1f1b, guest PC 0x0c07c1be */
if(!s->budget--) { s->failed_pc=0x0c07c1beu; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07c1c0;
P_0c07c1c0: /* original d341, guest PC 0x0c07c1c0 */
if(!s->budget--) { s->failed_pc=0x0c07c1c0u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c1c2;
P_0c07c1c2: /* original 6112, guest PC 0x0c07c1c2 */
if(!s->budget--) { s->failed_pc=0x0c07c1c2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c1c4;
P_0c07c1c4: /* original 430b, guest PC 0x0c07c1c4 */
if(!s->budget--) { s->failed_pc=0x0c07c1c4u; return 0; }
target=r[3];
r[16]=0x0c07c1c8u;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1c8u) { target=s->pc; goto dispatch; }
goto P_0c07c1c8;
P_0c07c1c6: /* original e00a, guest PC 0x0c07c1c6 */
if(!s->budget--) { s->failed_pc=0x0c07c1c6u; return 0; }
r[0]=0x0000000au;
goto P_0c07c1c8;
P_0c07c1c8: /* original 63f6, guest PC 0x0c07c1c8 */
if(!s->budget--) { s->failed_pc=0x0c07c1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07c1ca;
P_0c07c1ca: /* original e700, guest PC 0x0c07c1ca */
if(!s->budget--) { s->failed_pc=0x0c07c1cau; return 0; }
r[7]=0x00000000u;
goto P_0c07c1cc;
P_0c07c1cc: /* original 66d3, guest PC 0x0c07c1cc */
if(!s->budget--) { s->failed_pc=0x0c07c1ccu; return 0; }
r[6]=r[13];
goto P_0c07c1ce;
P_0c07c1ce: /* original 2302, guest PC 0x0c07c1ce */
if(!s->budget--) { s->failed_pc=0x0c07c1ceu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c1d0;
P_0c07c1d0: /* original 5cf1, guest PC 0x0c07c1d0 */
if(!s->budget--) { s->failed_pc=0x0c07c1d0u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c1d2;
P_0c07c1d2: /* original 53f8, guest PC 0x0c07c1d2 */
if(!s->budget--) { s->failed_pc=0x0c07c1d2u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c1d4;
P_0c07c1d4: /* original 2fb6, guest PC 0x0c07c1d4 */
if(!s->budget--) { s->failed_pc=0x0c07c1d4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c1d6;
P_0c07c1d6: /* original 2fe6, guest PC 0x0c07c1d6 */
if(!s->budget--) { s->failed_pc=0x0c07c1d6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c1d8;
P_0c07c1d8: /* original 2c3b, guest PC 0x0c07c1d8 */
if(!s->budget--) { s->failed_pc=0x0c07c1d8u; return 0; }
r[12]|=r[3];
goto P_0c07c1da;
P_0c07c1da: /* original 50f9, guest PC 0x0c07c1da */
if(!s->budget--) { s->failed_pc=0x0c07c1dau; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c1dc;
P_0c07c1dc: /* original 6002, guest PC 0x0c07c1dc */
if(!s->budget--) { s->failed_pc=0x0c07c1dcu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c1de;
P_0c07c1de: /* original 4008, guest PC 0x0c07c1de */
if(!s->budget--) { s->failed_pc=0x0c07c1deu; return 0; }
r[0]<<=2;
goto P_0c07c1e0;
P_0c07c1e0: /* original 059e, guest PC 0x0c07c1e0 */
if(!s->budget--) { s->failed_pc=0x0c07c1e0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c1e2;
P_0c07c1e2: /* original 480b, guest PC 0x0c07c1e2 */
if(!s->budget--) { s->failed_pc=0x0c07c1e2u; return 0; }
target=r[8];
r[16]=0x0c07c1e6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1e6u) { target=s->pc; goto dispatch; }
goto P_0c07c1e6;
P_0c07c1e4: /* original 64c3, guest PC 0x0c07c1e4 */
if(!s->budget--) { s->failed_pc=0x0c07c1e4u; return 0; }
r[4]=r[12];
goto P_0c07c1e6;
P_0c07c1e6: /* original 7f08, guest PC 0x0c07c1e6 */
if(!s->budget--) { s->failed_pc=0x0c07c1e6u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c1e8;
P_0c07c1e8: /* original 6403, guest PC 0x0c07c1e8 */
if(!s->budget--) { s->failed_pc=0x0c07c1e8u; return 0; }
r[4]=r[0];
goto P_0c07c1ea;
P_0c07c1ea: /* original e030, guest PC 0x0c07c1ea */
if(!s->budget--) { s->failed_pc=0x0c07c1eau; return 0; }
r[0]=0x00000030u;
goto P_0c07c1ec;
P_0c07c1ec: /* original f4e7, guest PC 0x0c07c1ec */
if(!s->budget--) { s->failed_pc=0x0c07c1ecu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c1ee;
P_0c07c1ee: /* original 52f7, guest PC 0x0c07c1ee */
if(!s->budget--) { s->failed_pc=0x0c07c1eeu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c1f0;
P_0c07c1f0: /* original 53fa, guest PC 0x0c07c1f0 */
if(!s->budget--) { s->failed_pc=0x0c07c1f0u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c1f2;
P_0c07c1f2: /* original 6222, guest PC 0x0c07c1f2 */
if(!s->budget--) { s->failed_pc=0x0c07c1f2u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07c1f4;
P_0c07c1f4: /* original 6032, guest PC 0x0c07c1f4 */
if(!s->budget--) { s->failed_pc=0x0c07c1f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07c1f6;
P_0c07c1f6: /* original 6123, guest PC 0x0c07c1f6 */
if(!s->budget--) { s->failed_pc=0x0c07c1f6u; return 0; }
r[1]=r[2];
goto P_0c07c1f8;
P_0c07c1f8: /* original 4208, guest PC 0x0c07c1f8 */
if(!s->budget--) { s->failed_pc=0x0c07c1f8u; return 0; }
r[2]<<=2;
goto P_0c07c1fa;
P_0c07c1fa: /* original 321c, guest PC 0x0c07c1fa */
if(!s->budget--) { s->failed_pc=0x0c07c1fau; return 0; }
r[2]+=r[1];
goto P_0c07c1fc;
P_0c07c1fc: /* original 4200, guest PC 0x0c07c1fc */
if(!s->budget--) { s->failed_pc=0x0c07c1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c1fe;
P_0c07c1fe: /* original 3028, guest PC 0x0c07c1fe */
if(!s->budget--) { s->failed_pc=0x0c07c1feu; return 0; }
r[0]-=r[2];
goto P_0c07c200;
P_0c07c200: /* original 2302, guest PC 0x0c07c200 */
if(!s->budget--) { s->failed_pc=0x0c07c200u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c202;
P_0c07c202: /* original 5cf1, guest PC 0x0c07c202 */
if(!s->budget--) { s->failed_pc=0x0c07c202u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c204;
P_0c07c204: /* original e700, guest PC 0x0c07c204 */
if(!s->budget--) { s->failed_pc=0x0c07c204u; return 0; }
r[7]=0x00000000u;
goto P_0c07c206;
P_0c07c206: /* original 53f3, guest PC 0x0c07c206 */
if(!s->budget--) { s->failed_pc=0x0c07c206u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07c208;
P_0c07c208: /* original 66d3, guest PC 0x0c07c208 */
if(!s->budget--) { s->failed_pc=0x0c07c208u; return 0; }
r[6]=r[13];
goto P_0c07c20a;
P_0c07c20a: /* original 2fb6, guest PC 0x0c07c20a */
if(!s->budget--) { s->failed_pc=0x0c07c20au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c20c;
P_0c07c20c: /* original 2fe6, guest PC 0x0c07c20c */
if(!s->budget--) { s->failed_pc=0x0c07c20cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c20e;
P_0c07c20e: /* original 2c3b, guest PC 0x0c07c20e */
if(!s->budget--) { s->failed_pc=0x0c07c20eu; return 0; }
r[12]|=r[3];
goto P_0c07c210;
P_0c07c210: /* original 50fd, guest PC 0x0c07c210 */
if(!s->budget--) { s->failed_pc=0x0c07c210u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07c212;
P_0c07c212: /* original 6002, guest PC 0x0c07c212 */
if(!s->budget--) { s->failed_pc=0x0c07c212u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c214;
P_0c07c214: /* original 4008, guest PC 0x0c07c214 */
if(!s->budget--) { s->failed_pc=0x0c07c214u; return 0; }
r[0]<<=2;
goto P_0c07c216;
P_0c07c216: /* original 059e, guest PC 0x0c07c216 */
if(!s->budget--) { s->failed_pc=0x0c07c216u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c218;
P_0c07c218: /* original 480b, guest PC 0x0c07c218 */
if(!s->budget--) { s->failed_pc=0x0c07c218u; return 0; }
target=r[8];
r[16]=0x0c07c21cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c21cu) { target=s->pc; goto dispatch; }
goto P_0c07c21c;
P_0c07c21a: /* original 64c3, guest PC 0x0c07c21a */
if(!s->budget--) { s->failed_pc=0x0c07c21au; return 0; }
r[4]=r[12];
goto P_0c07c21c;
P_0c07c21c: /* original 7f08, guest PC 0x0c07c21c */
if(!s->budget--) { s->failed_pc=0x0c07c21cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07c21e;
P_0c07c21e: /* original 6403, guest PC 0x0c07c21e */
if(!s->budget--) { s->failed_pc=0x0c07c21eu; return 0; }
r[4]=r[0];
goto P_0c07c220;
P_0c07c220: /* original e030, guest PC 0x0c07c220 */
if(!s->budget--) { s->failed_pc=0x0c07c220u; return 0; }
r[0]=0x00000030u;
goto P_0c07c222;
P_0c07c222: /* original f4e7, guest PC 0x0c07c222 */
if(!s->budget--) { s->failed_pc=0x0c07c222u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c224;
P_0c07c224: /* original 53f2, guest PC 0x0c07c224 */
if(!s->budget--) { s->failed_pc=0x0c07c224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07c226;
P_0c07c226: /* original 7301, guest PC 0x0c07c226 */
if(!s->budget--) { s->failed_pc=0x0c07c226u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c228;
P_0c07c228: /* original 1f32, guest PC 0x0c07c228 */
if(!s->budget--) { s->failed_pc=0x0c07c228u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c22a;
P_0c07c22a: /* original 52fb, guest PC 0x0c07c22a */
if(!s->budget--) { s->failed_pc=0x0c07c22au; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07c22c;
P_0c07c22c: /* original 7204, guest PC 0x0c07c22c */
if(!s->budget--) { s->failed_pc=0x0c07c22cu; return 0; }
r[2]+=0x00000004u;
goto P_0c07c22e;
P_0c07c22e: /* original 1f2b, guest PC 0x0c07c22e */
if(!s->budget--) { s->failed_pc=0x0c07c22eu; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07c230;
P_0c07c230: /* original 51f3, guest PC 0x0c07c230 */
if(!s->budget--) { s->failed_pc=0x0c07c230u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07c232;
P_0c07c232: /* original 7150, guest PC 0x0c07c232 */
if(!s->budget--) { s->failed_pc=0x0c07c232u; return 0; }
r[1]+=0x00000050u;
goto P_0c07c234;
P_0c07c234: /* original 1f13, guest PC 0x0c07c234 */
if(!s->budget--) { s->failed_pc=0x0c07c234u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c236;
P_0c07c236: /* original 53f8, guest PC 0x0c07c236 */
if(!s->budget--) { s->failed_pc=0x0c07c236u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c238;
P_0c07c238: /* original 7350, guest PC 0x0c07c238 */
if(!s->budget--) { s->failed_pc=0x0c07c238u; return 0; }
r[3]+=0x00000050u;
goto P_0c07c23a;
P_0c07c23a: /* original 1f38, guest PC 0x0c07c23a */
if(!s->budget--) { s->failed_pc=0x0c07c23au; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07c23c;
P_0c07c23c: /* original 51f2, guest PC 0x0c07c23c */
if(!s->budget--) { s->failed_pc=0x0c07c23cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07c23e;
P_0c07c23e: /* original e202, guest PC 0x0c07c23e */
if(!s->budget--) { s->failed_pc=0x0c07c23eu; return 0; }
r[2]=0x00000002u;
goto P_0c07c240;
P_0c07c240: /* original 3123, guest PC 0x0c07c240 */
if(!s->budget--) { s->failed_pc=0x0c07c240u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c242;
P_0c07c242: /* original 8901, guest PC 0x0c07c242 */
if(!s->budget--) { s->failed_pc=0x0c07c242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c248; }
goto P_0c07c244;
P_0c07c244: /* original af72, guest PC 0x0c07c244 */
if(!s->budget--) { s->failed_pc=0x0c07c244u; return 0; }
goto P_0c07c12c;
P_0c07c246: /* original 0009, guest PC 0x0c07c246 */
if(!s->budget--) { s->failed_pc=0x0c07c246u; return 0; }
goto P_0c07c248;
P_0c07c248: /* original 53f9, guest PC 0x0c07c248 */
if(!s->budget--) { s->failed_pc=0x0c07c248u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c24a;
P_0c07c24a: /* original 7301, guest PC 0x0c07c24a */
if(!s->budget--) { s->failed_pc=0x0c07c24au; return 0; }
r[3]+=0x00000001u;
goto P_0c07c24c;
P_0c07c24c: /* original 1f39, guest PC 0x0c07c24c */
if(!s->budget--) { s->failed_pc=0x0c07c24cu; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07c24e;
P_0c07c24e: /* original 51f9, guest PC 0x0c07c24e */
if(!s->budget--) { s->failed_pc=0x0c07c24eu; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c250;
P_0c07c250: /* original e202, guest PC 0x0c07c250 */
if(!s->budget--) { s->failed_pc=0x0c07c250u; return 0; }
r[2]=0x00000002u;
goto P_0c07c252;
P_0c07c252: /* original 3123, guest PC 0x0c07c252 */
if(!s->budget--) { s->failed_pc=0x0c07c252u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c254;
P_0c07c254: /* original 8901, guest PC 0x0c07c254 */
if(!s->budget--) { s->failed_pc=0x0c07c254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c25a; }
goto P_0c07c256;
P_0c07c256: /* original af40, guest PC 0x0c07c256 */
if(!s->budget--) { s->failed_pc=0x0c07c256u; return 0; }
goto P_0c07c0da;
P_0c07c258: /* original 0009, guest PC 0x0c07c258 */
if(!s->budget--) { s->failed_pc=0x0c07c258u; return 0; }
goto P_0c07c25a;
P_0c07c25a: /* original 2fb6, guest PC 0x0c07c25a */
if(!s->budget--) { s->failed_pc=0x0c07c25au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c25c;
P_0c07c25c: /* original e700, guest PC 0x0c07c25c */
if(!s->budget--) { s->failed_pc=0x0c07c25cu; return 0; }
r[7]=0x00000000u;
goto P_0c07c25e;
P_0c07c25e: /* original 2fe6, guest PC 0x0c07c25e */
if(!s->budget--) { s->failed_pc=0x0c07c25eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c260;
P_0c07c260: /* original 952c, guest PC 0x0c07c260 */
if(!s->budget--) { s->failed_pc=0x0c07c260u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c262;
P_0c07c262: /* original 942c, guest PC 0x0c07c262 */
if(!s->budget--) { s->failed_pc=0x0c07c262u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2beu,2);
goto P_0c07c264;
P_0c07c264: /* original 480b, guest PC 0x0c07c264 */
if(!s->budget--) { s->failed_pc=0x0c07c264u; return 0; }
target=r[8];
r[16]=0x0c07c268u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c268u) { target=s->pc; goto dispatch; }
goto P_0c07c268;
P_0c07c266: /* original 66d3, guest PC 0x0c07c266 */
if(!s->budget--) { s->failed_pc=0x0c07c266u; return 0; }
r[6]=r[13];
goto P_0c07c268;
P_0c07c268: /* original 6403, guest PC 0x0c07c268 */
if(!s->budget--) { s->failed_pc=0x0c07c268u; return 0; }
r[4]=r[0];
goto P_0c07c26a;
P_0c07c26a: /* original e030, guest PC 0x0c07c26a */
if(!s->budget--) { s->failed_pc=0x0c07c26au; return 0; }
r[0]=0x00000030u;
goto P_0c07c26c;
P_0c07c26c: /* original f4e7, guest PC 0x0c07c26c */
if(!s->budget--) { s->failed_pc=0x0c07c26cu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c26e;
P_0c07c26e: /* original e700, guest PC 0x0c07c26e */
if(!s->budget--) { s->failed_pc=0x0c07c26eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c270;
P_0c07c270: /* original 2fb6, guest PC 0x0c07c270 */
if(!s->budget--) { s->failed_pc=0x0c07c270u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c272;
P_0c07c272: /* original 2fe6, guest PC 0x0c07c272 */
if(!s->budget--) { s->failed_pc=0x0c07c272u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c274;
P_0c07c274: /* original 9524, guest PC 0x0c07c274 */
if(!s->budget--) { s->failed_pc=0x0c07c274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c276;
P_0c07c276: /* original 9424, guest PC 0x0c07c276 */
if(!s->budget--) { s->failed_pc=0x0c07c276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c2u,2);
goto P_0c07c278;
P_0c07c278: /* original 480b, guest PC 0x0c07c278 */
if(!s->budget--) { s->failed_pc=0x0c07c278u; return 0; }
target=r[8];
r[16]=0x0c07c27cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c27cu) { target=s->pc; goto dispatch; }
goto P_0c07c27c;
P_0c07c27a: /* original 66d3, guest PC 0x0c07c27a */
if(!s->budget--) { s->failed_pc=0x0c07c27au; return 0; }
r[6]=r[13];
goto P_0c07c27c;
P_0c07c27c: /* original 6403, guest PC 0x0c07c27c */
if(!s->budget--) { s->failed_pc=0x0c07c27cu; return 0; }
r[4]=r[0];
goto P_0c07c27e;
P_0c07c27e: /* original e030, guest PC 0x0c07c27e */
if(!s->budget--) { s->failed_pc=0x0c07c27eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c280;
P_0c07c280: /* original f4e7, guest PC 0x0c07c280 */
if(!s->budget--) { s->failed_pc=0x0c07c280u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c282;
P_0c07c282: /* original e700, guest PC 0x0c07c282 */
if(!s->budget--) { s->failed_pc=0x0c07c282u; return 0; }
r[7]=0x00000000u;
goto P_0c07c284;
P_0c07c284: /* original 2fb6, guest PC 0x0c07c284 */
if(!s->budget--) { s->failed_pc=0x0c07c284u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c286;
P_0c07c286: /* original 2fe6, guest PC 0x0c07c286 */
if(!s->budget--) { s->failed_pc=0x0c07c286u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c288;
P_0c07c288: /* original 9518, guest PC 0x0c07c288 */
if(!s->budget--) { s->failed_pc=0x0c07c288u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c28a;
P_0c07c28a: /* original 941b, guest PC 0x0c07c28a */
if(!s->budget--) { s->failed_pc=0x0c07c28au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c4u,2);
goto P_0c07c28c;
P_0c07c28c: /* original 480b, guest PC 0x0c07c28c */
if(!s->budget--) { s->failed_pc=0x0c07c28cu; return 0; }
target=r[8];
r[16]=0x0c07c290u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c290u) { target=s->pc; goto dispatch; }
goto P_0c07c290;
P_0c07c28e: /* original 66d3, guest PC 0x0c07c28e */
if(!s->budget--) { s->failed_pc=0x0c07c28eu; return 0; }
r[6]=r[13];
goto P_0c07c290;
P_0c07c290: /* original 6403, guest PC 0x0c07c290 */
if(!s->budget--) { s->failed_pc=0x0c07c290u; return 0; }
r[4]=r[0];
goto P_0c07c292;
P_0c07c292: /* original e030, guest PC 0x0c07c292 */
if(!s->budget--) { s->failed_pc=0x0c07c292u; return 0; }
r[0]=0x00000030u;
goto P_0c07c294;
P_0c07c294: /* original f4e7, guest PC 0x0c07c294 */
if(!s->budget--) { s->failed_pc=0x0c07c294u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c296;
P_0c07c296: /* original e700, guest PC 0x0c07c296 */
if(!s->budget--) { s->failed_pc=0x0c07c296u; return 0; }
r[7]=0x00000000u;
goto P_0c07c298;
P_0c07c298: /* original 2fb6, guest PC 0x0c07c298 */
if(!s->budget--) { s->failed_pc=0x0c07c298u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c29a;
P_0c07c29a: /* original 2fe6, guest PC 0x0c07c29a */
if(!s->budget--) { s->failed_pc=0x0c07c29au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c29c;
P_0c07c29c: /* original 9510, guest PC 0x0c07c29c */
if(!s->budget--) { s->failed_pc=0x0c07c29cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c29e;
P_0c07c29e: /* original 9412, guest PC 0x0c07c29e */
if(!s->budget--) { s->failed_pc=0x0c07c29eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c6u,2);
goto P_0c07c2a0;
P_0c07c2a0: /* original 480b, guest PC 0x0c07c2a0 */
if(!s->budget--) { s->failed_pc=0x0c07c2a0u; return 0; }
target=r[8];
r[16]=0x0c07c2a4u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2a4u) { target=s->pc; goto dispatch; }
goto P_0c07c2a4;
P_0c07c2a2: /* original 66d3, guest PC 0x0c07c2a2 */
if(!s->budget--) { s->failed_pc=0x0c07c2a2u; return 0; }
r[6]=r[13];
goto P_0c07c2a4;
P_0c07c2a4: /* original 6403, guest PC 0x0c07c2a4 */
if(!s->budget--) { s->failed_pc=0x0c07c2a4u; return 0; }
r[4]=r[0];
goto P_0c07c2a6;
P_0c07c2a6: /* original e030, guest PC 0x0c07c2a6 */
if(!s->budget--) { s->failed_pc=0x0c07c2a6u; return 0; }
r[0]=0x00000030u;
goto P_0c07c2a8;
P_0c07c2a8: /* original f4e7, guest PC 0x0c07c2a8 */
if(!s->budget--) { s->failed_pc=0x0c07c2a8u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c2aa;
P_0c07c2aa: /* original 7f20, guest PC 0x0c07c2aa */
if(!s->budget--) { s->failed_pc=0x0c07c2aau; return 0; }
r[15]+=0x00000020u;
goto P_0c07c2ac;
P_0c07c2ac: /* original d307, guest PC 0x0c07c2ac */
if(!s->budget--) { s->failed_pc=0x0c07c2acu; return 0; }
r[3]=read(ram,0x0c07c2ccu,4);
goto P_0c07c2ae;
P_0c07c2ae: /* original 430b, guest PC 0x0c07c2ae */
if(!s->budget--) { s->failed_pc=0x0c07c2aeu; return 0; }
target=r[3];
r[16]=0x0c07c2b2u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2b2u) { target=s->pc; goto dispatch; }
goto P_0c07c2b2;
P_0c07c2b0: /* original e400, guest PC 0x0c07c2b0 */
if(!s->budget--) { s->failed_pc=0x0c07c2b0u; return 0; }
r[4]=0x00000000u;
goto P_0c07c2b2;
P_0c07c2b2: /* original a01e, guest PC 0x0c07c2b2 */
if(!s->budget--) { s->failed_pc=0x0c07c2b2u; return 0; }
goto P_0c07c2f2;
P_0c07c2b4: /* original 0009, guest PC 0x0c07c2b4 */
if(!s->budget--) { s->failed_pc=0x0c07c2b4u; return 0; }
return vf3_matrix_family(0x0c07c2b6u,s,ram);
P_0c07c2d0: /* original 50fc, guest PC 0x0c07c2d0 */
if(!s->budget--) { s->failed_pc=0x0c07c2d0u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2d2;
P_0c07c2d2: /* original c802, guest PC 0x0c07c2d2 */
if(!s->budget--) { s->failed_pc=0x0c07c2d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07c2d4;
P_0c07c2d4: /* original 8902, guest PC 0x0c07c2d4 */
if(!s->budget--) { s->failed_pc=0x0c07c2d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2dc; }
goto P_0c07c2d6;
P_0c07c2d6: /* original d243, guest PC 0x0c07c2d6 */
if(!s->budget--) { s->failed_pc=0x0c07c2d6u; return 0; }
r[2]=read(ram,0x0c07c3e4u,4);
goto P_0c07c2d8;
P_0c07c2d8: /* original 420b, guest PC 0x0c07c2d8 */
if(!s->budget--) { s->failed_pc=0x0c07c2d8u; return 0; }
target=r[2];
r[16]=0x0c07c2dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2dcu) { target=s->pc; goto dispatch; }
goto P_0c07c2dc;
P_0c07c2da: /* original 0009, guest PC 0x0c07c2da */
if(!s->budget--) { s->failed_pc=0x0c07c2dau; return 0; }
goto P_0c07c2dc;
P_0c07c2dc: /* original 2cc8, guest PC 0x0c07c2dc */
if(!s->budget--) { s->failed_pc=0x0c07c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07c2de;
P_0c07c2de: /* original 8902, guest PC 0x0c07c2de */
if(!s->budget--) { s->failed_pc=0x0c07c2deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2e6; }
goto P_0c07c2e0;
P_0c07c2e0: /* original d241, guest PC 0x0c07c2e0 */
if(!s->budget--) { s->failed_pc=0x0c07c2e0u; return 0; }
r[2]=read(ram,0x0c07c3e8u,4);
goto P_0c07c2e2;
P_0c07c2e2: /* original 420b, guest PC 0x0c07c2e2 */
if(!s->budget--) { s->failed_pc=0x0c07c2e2u; return 0; }
target=r[2];
r[16]=0x0c07c2e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2e6u) { target=s->pc; goto dispatch; }
goto P_0c07c2e6;
P_0c07c2e4: /* original 0009, guest PC 0x0c07c2e4 */
if(!s->budget--) { s->failed_pc=0x0c07c2e4u; return 0; }
goto P_0c07c2e6;
P_0c07c2e6: /* original 50fc, guest PC 0x0c07c2e6 */
if(!s->budget--) { s->failed_pc=0x0c07c2e6u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2e8;
P_0c07c2e8: /* original c808, guest PC 0x0c07c2e8 */
if(!s->budget--) { s->failed_pc=0x0c07c2e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c07c2ea;
P_0c07c2ea: /* original 8902, guest PC 0x0c07c2ea */
if(!s->budget--) { s->failed_pc=0x0c07c2eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2f2; }
goto P_0c07c2ec;
P_0c07c2ec: /* original d13f, guest PC 0x0c07c2ec */
if(!s->budget--) { s->failed_pc=0x0c07c2ecu; return 0; }
r[1]=read(ram,0x0c07c3ecu,4);
goto P_0c07c2ee;
P_0c07c2ee: /* original 410b, guest PC 0x0c07c2ee */
if(!s->budget--) { s->failed_pc=0x0c07c2eeu; return 0; }
target=r[1];
r[16]=0x0c07c2f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2f2u) { target=s->pc; goto dispatch; }
goto P_0c07c2f2;
P_0c07c2f0: /* original 0009, guest PC 0x0c07c2f0 */
if(!s->budget--) { s->failed_pc=0x0c07c2f0u; return 0; }
goto P_0c07c2f2;
P_0c07c2f2: /* original 51fc, guest PC 0x0c07c2f2 */
if(!s->budget--) { s->failed_pc=0x0c07c2f2u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07c2f4;
P_0c07c2f4: /* original 9370, guest PC 0x0c07c2f4 */
if(!s->budget--) { s->failed_pc=0x0c07c2f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3d8u,2);
goto P_0c07c2f6;
P_0c07c2f6: /* original 2138, guest PC 0x0c07c2f6 */
if(!s->budget--) { s->failed_pc=0x0c07c2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07c2f8;
P_0c07c2f8: /* original 8902, guest PC 0x0c07c2f8 */
if(!s->budget--) { s->failed_pc=0x0c07c2f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c300; }
goto P_0c07c2fa;
P_0c07c2fa: /* original d23d, guest PC 0x0c07c2fa */
if(!s->budget--) { s->failed_pc=0x0c07c2fau; return 0; }
r[2]=read(ram,0x0c07c3f0u,4);
goto P_0c07c2fc;
P_0c07c2fc: /* original 420b, guest PC 0x0c07c2fc */
if(!s->budget--) { s->failed_pc=0x0c07c2fcu; return 0; }
target=r[2];
r[16]=0x0c07c300u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c300u) { target=s->pc; goto dispatch; }
goto P_0c07c300;
P_0c07c2fe: /* original 0009, guest PC 0x0c07c2fe */
if(!s->budget--) { s->failed_pc=0x0c07c2feu; return 0; }
goto P_0c07c300;
P_0c07c300: /* original 52fd, guest PC 0x0c07c300 */
if(!s->budget--) { s->failed_pc=0x0c07c300u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07c302;
P_0c07c302: /* original 64e3, guest PC 0x0c07c302 */
if(!s->budget--) { s->failed_pc=0x0c07c302u; return 0; }
r[4]=r[14];
goto P_0c07c304;
P_0c07c304: /* original 53fc, guest PC 0x0c07c304 */
if(!s->budget--) { s->failed_pc=0x0c07c304u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c306;
P_0c07c306: /* original 223b, guest PC 0x0c07c306 */
if(!s->budget--) { s->failed_pc=0x0c07c306u; return 0; }
r[2]|=r[3];
goto P_0c07c308;
P_0c07c308: /* original 1f2c, guest PC 0x0c07c308 */
if(!s->budget--) { s->failed_pc=0x0c07c308u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c07c30a;
P_0c07c30a: /* original d33a, guest PC 0x0c07c30a */
if(!s->budget--) { s->failed_pc=0x0c07c30au; return 0; }
r[3]=read(ram,0x0c07c3f4u,4);
goto P_0c07c30c;
P_0c07c30c: /* original 2322, guest PC 0x0c07c30c */
if(!s->budget--) { s->failed_pc=0x0c07c30cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c30e;
P_0c07c30e: /* original d23a, guest PC 0x0c07c30e */
if(!s->budget--) { s->failed_pc=0x0c07c30eu; return 0; }
r[2]=read(ram,0x0c07c3f8u,4);
goto P_0c07c310;
P_0c07c310: /* original 22e2, guest PC 0x0c07c310 */
if(!s->budget--) { s->failed_pc=0x0c07c310u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c07c312;
P_0c07c312: /* original d13a, guest PC 0x0c07c312 */
if(!s->budget--) { s->failed_pc=0x0c07c312u; return 0; }
r[1]=read(ram,0x0c07c3fcu,4);
goto P_0c07c314;
P_0c07c314: /* original 53fc, guest PC 0x0c07c314 */
if(!s->budget--) { s->failed_pc=0x0c07c314u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c316;
P_0c07c316: /* original 2132, guest PC 0x0c07c316 */
if(!s->budget--) { s->failed_pc=0x0c07c316u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c07c318;
P_0c07c318: /* original 915f, guest PC 0x0c07c318 */
if(!s->budget--) { s->failed_pc=0x0c07c318u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3dau,2);
goto P_0c07c31a;
P_0c07c31a: /* original 3f1c, guest PC 0x0c07c31a */
if(!s->budget--) { s->failed_pc=0x0c07c31au; return 0; }
r[15]+=r[1];
goto P_0c07c31c;
P_0c07c31c: /* original 4f16, guest PC 0x0c07c31c */
if(!s->budget--) { s->failed_pc=0x0c07c31cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c31e;
P_0c07c31e: /* original 4f26, guest PC 0x0c07c31e */
if(!s->budget--) { s->failed_pc=0x0c07c31eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c320;
P_0c07c320: /* original fef9, guest PC 0x0c07c320 */
if(!s->budget--) { s->failed_pc=0x0c07c320u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c322;
P_0c07c322: /* original fff9, guest PC 0x0c07c322 */
if(!s->budget--) { s->failed_pc=0x0c07c322u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c324;
P_0c07c324: /* original 68f6, guest PC 0x0c07c324 */
if(!s->budget--) { s->failed_pc=0x0c07c324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07c326;
P_0c07c326: /* original 69f6, guest PC 0x0c07c326 */
if(!s->budget--) { s->failed_pc=0x0c07c326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c328;
P_0c07c328: /* original 6af6, guest PC 0x0c07c328 */
if(!s->budget--) { s->failed_pc=0x0c07c328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c32a;
P_0c07c32a: /* original 6bf6, guest PC 0x0c07c32a */
if(!s->budget--) { s->failed_pc=0x0c07c32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c32c;
P_0c07c32c: /* original 6cf6, guest PC 0x0c07c32c */
if(!s->budget--) { s->failed_pc=0x0c07c32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c32e;
P_0c07c32e: /* original 6df6, guest PC 0x0c07c32e */
if(!s->budget--) { s->failed_pc=0x0c07c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c330;
P_0c07c330: /* original 000b, guest PC 0x0c07c330 */
if(!s->budget--) { s->failed_pc=0x0c07c330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07c332: /* original 6ef6, guest PC 0x0c07c332 */
if(!s->budget--) { s->failed_pc=0x0c07c332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c334u,s,ram);
P_0c07c540: /* original 4f22, guest PC 0x0c07c540 */
if(!s->budget--) { s->failed_pc=0x0c07c540u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c542;
P_0c07c542: /* original 7ff0, guest PC 0x0c07c542 */
if(!s->budget--) { s->failed_pc=0x0c07c542u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c07c544;
P_0c07c544: /* original 2f42, guest PC 0x0c07c544 */
if(!s->budget--) { s->failed_pc=0x0c07c544u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c546;
P_0c07c546: /* original 1f53, guest PC 0x0c07c546 */
if(!s->budget--) { s->failed_pc=0x0c07c546u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c07c548;
P_0c07c548: /* original d34a, guest PC 0x0c07c548 */
if(!s->budget--) { s->failed_pc=0x0c07c548u; return 0; }
r[3]=read(ram,0x0c07c674u,4);
goto P_0c07c54a;
P_0c07c54a: /* original 1f32, guest PC 0x0c07c54a */
if(!s->budget--) { s->failed_pc=0x0c07c54au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c54c;
P_0c07c54c: /* original 62f2, guest PC 0x0c07c54c */
if(!s->budget--) { s->failed_pc=0x0c07c54cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c54e;
P_0c07c54e: /* original 1f21, guest PC 0x0c07c54e */
if(!s->budget--) { s->failed_pc=0x0c07c54eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07c550;
P_0c07c550: /* original d349, guest PC 0x0c07c550 */
if(!s->budget--) { s->failed_pc=0x0c07c550u; return 0; }
r[3]=read(ram,0x0c07c678u,4);
goto P_0c07c552;
P_0c07c552: /* original 430b, guest PC 0x0c07c552 */
if(!s->budget--) { s->failed_pc=0x0c07c552u; return 0; }
target=r[3];
r[16]=0x0c07c556u;
r[4]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c556u) { target=s->pc; goto dispatch; }
goto P_0c07c556;
P_0c07c554: /* original e40a, guest PC 0x0c07c554 */
if(!s->budget--) { s->failed_pc=0x0c07c554u; return 0; }
r[4]=0x0000000au;
goto P_0c07c556;
P_0c07c556: /* original d248, guest PC 0x0c07c556 */
if(!s->budget--) { s->failed_pc=0x0c07c556u; return 0; }
r[2]=read(ram,0x0c07c678u,4);
goto P_0c07c558;
P_0c07c558: /* original 420b, guest PC 0x0c07c558 */
if(!s->budget--) { s->failed_pc=0x0c07c558u; return 0; }
target=r[2];
r[16]=0x0c07c55cu;
r[4]=0x0000000bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c55cu) { target=s->pc; goto dispatch; }
goto P_0c07c55c;
P_0c07c55a: /* original e40b, guest PC 0x0c07c55a */
if(!s->budget--) { s->failed_pc=0x0c07c55au; return 0; }
r[4]=0x0000000bu;
goto P_0c07c55c;
P_0c07c55c: /* original de47, guest PC 0x0c07c55c */
if(!s->budget--) { s->failed_pc=0x0c07c55cu; return 0; }
r[14]=read(ram,0x0c07c67cu,4);
goto P_0c07c55e;
P_0c07c55e: /* original 54f2, guest PC 0x0c07c55e */
if(!s->budget--) { s->failed_pc=0x0c07c55eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07c560;
P_0c07c560: /* original d347, guest PC 0x0c07c560 */
if(!s->budget--) { s->failed_pc=0x0c07c560u; return 0; }
r[3]=read(ram,0x0c07c680u,4);
goto P_0c07c562;
P_0c07c562: /* original 6de3, guest PC 0x0c07c562 */
if(!s->budget--) { s->failed_pc=0x0c07c562u; return 0; }
r[13]=r[14];
goto P_0c07c564;
P_0c07c564: /* original 6ae3, guest PC 0x0c07c564 */
if(!s->budget--) { s->failed_pc=0x0c07c564u; return 0; }
r[10]=r[14];
goto P_0c07c566;
P_0c07c566: /* original 7d58, guest PC 0x0c07c566 */
if(!s->budget--) { s->failed_pc=0x0c07c566u; return 0; }
r[13]+=0x00000058u;
goto P_0c07c568;
P_0c07c568: /* original 430b, guest PC 0x0c07c568 */
if(!s->budget--) { s->failed_pc=0x0c07c568u; return 0; }
target=r[3];
r[16]=0x0c07c56cu;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c56cu) { target=s->pc; goto dispatch; }
goto P_0c07c56c;
P_0c07c56a: /* original 7412, guest PC 0x0c07c56a */
if(!s->budget--) { s->failed_pc=0x0c07c56au; return 0; }
r[4]+=0x00000012u;
goto P_0c07c56c;
P_0c07c56c: /* original dc45, guest PC 0x0c07c56c */
if(!s->budget--) { s->failed_pc=0x0c07c56cu; return 0; }
r[12]=read(ram,0x0c07c684u,4);
goto P_0c07c56e;
P_0c07c56e: /* original 84c9, guest PC 0x0c07c56e */
if(!s->budget--) { s->failed_pc=0x0c07c56eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+9,1);
goto P_0c07c570;
P_0c07c570: /* original 600c, guest PC 0x0c07c570 */
if(!s->budget--) { s->failed_pc=0x0c07c570u; return 0; }
r[0]=r[0]&255u;
goto P_0c07c572;
P_0c07c572: /* original 8802, guest PC 0x0c07c572 */
if(!s->budget--) { s->failed_pc=0x0c07c572u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07c574;
P_0c07c574: /* original 8f26, guest PC 0x0c07c574 */
if(!s->budget--) { s->failed_pc=0x0c07c574u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c07c5c4; }
goto P_0c07c578;
P_0c07c576: /* original 6403, guest PC 0x0c07c576 */
if(!s->budget--) { s->failed_pc=0x0c07c576u; return 0; }
r[4]=r[0];
goto P_0c07c578;
P_0c07c578: /* original e900, guest PC 0x0c07c578 */
if(!s->budget--) { s->failed_pc=0x0c07c578u; return 0; }
r[9]=0x00000000u;
goto P_0c07c57a;
P_0c07c57a: /* original 66d3, guest PC 0x0c07c57a */
if(!s->budget--) { s->failed_pc=0x0c07c57au; return 0; }
r[6]=r[13];
goto P_0c07c57c;
P_0c07c57c: /* original e23f, guest PC 0x0c07c57c */
if(!s->budget--) { s->failed_pc=0x0c07c57cu; return 0; }
r[2]=0x0000003fu;
goto P_0c07c57e;
P_0c07c57e: /* original 1c96, guest PC 0x0c07c57e */
if(!s->budget--) { s->failed_pc=0x0c07c57eu; return 0; }
write(ram,r[12]+24,r[9],4);
goto P_0c07c580;
P_0c07c580: /* original 9070, guest PC 0x0c07c580 */
if(!s->budget--) { s->failed_pc=0x0c07c580u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c664u,2);
goto P_0c07c582;
P_0c07c582: /* original 0e26, guest PC 0x0c07c582 */
if(!s->budget--) { s->failed_pc=0x0c07c582u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07c584;
P_0c07c584: /* original 946f, guest PC 0x0c07c584 */
if(!s->budget--) { s->failed_pc=0x0c07c584u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c666u,2);
goto P_0c07c586;
P_0c07c586: /* original d340, guest PC 0x0c07c586 */
if(!s->budget--) { s->failed_pc=0x0c07c586u; return 0; }
r[3]=read(ram,0x0c07c688u,4);
goto P_0c07c588;
P_0c07c588: /* original 430b, guest PC 0x0c07c588 */
if(!s->budget--) { s->failed_pc=0x0c07c588u; return 0; }
target=r[3];
r[16]=0x0c07c58cu;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c58cu) { target=s->pc; goto dispatch; }
goto P_0c07c58c;
P_0c07c58a: /* original 65a3, guest PC 0x0c07c58a */
if(!s->budget--) { s->failed_pc=0x0c07c58au; return 0; }
r[5]=r[10];
goto P_0c07c58c;
P_0c07c58c: /* original db3f, guest PC 0x0c07c58c */
if(!s->budget--) { s->failed_pc=0x0c07c58cu; return 0; }
r[11]=read(ram,0x0c07c68cu,4);
goto P_0c07c58e;
P_0c07c58e: /* original 4b0b, guest PC 0x0c07c58e */
if(!s->budget--) { s->failed_pc=0x0c07c58eu; return 0; }
target=r[11];
r[16]=0x0c07c592u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c592u) { target=s->pc; goto dispatch; }
goto P_0c07c592;
P_0c07c590: /* original 64a3, guest PC 0x0c07c590 */
if(!s->budget--) { s->failed_pc=0x0c07c590u; return 0; }
r[4]=r[10];
goto P_0c07c592;
P_0c07c592: /* original 4b0b, guest PC 0x0c07c592 */
if(!s->budget--) { s->failed_pc=0x0c07c592u; return 0; }
target=r[11];
r[16]=0x0c07c596u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c596u) { target=s->pc; goto dispatch; }
goto P_0c07c596;
P_0c07c594: /* original 64d3, guest PC 0x0c07c594 */
if(!s->budget--) { s->failed_pc=0x0c07c594u; return 0; }
r[4]=r[13];
goto P_0c07c596;
P_0c07c596: /* original 64e3, guest PC 0x0c07c596 */
if(!s->budget--) { s->failed_pc=0x0c07c596u; return 0; }
r[4]=r[14];
goto P_0c07c598;
P_0c07c598: /* original 4b0b, guest PC 0x0c07c598 */
if(!s->budget--) { s->failed_pc=0x0c07c598u; return 0; }
target=r[11];
r[16]=0x0c07c59cu;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c59cu) { target=s->pc; goto dispatch; }
goto P_0c07c59c;
P_0c07c59a: /* original 742c, guest PC 0x0c07c59a */
if(!s->budget--) { s->failed_pc=0x0c07c59au; return 0; }
r[4]+=0x0000002cu;
goto P_0c07c59c;
P_0c07c59c: /* original 9464, guest PC 0x0c07c59c */
if(!s->budget--) { s->failed_pc=0x0c07c59cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c668u,2);
goto P_0c07c59e;
P_0c07c59e: /* original 4b0b, guest PC 0x0c07c59e */
if(!s->budget--) { s->failed_pc=0x0c07c59eu; return 0; }
target=r[11];
r[16]=0x0c07c5a2u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c5a2u) { target=s->pc; goto dispatch; }
goto P_0c07c5a2;
P_0c07c5a0: /* original 34ec, guest PC 0x0c07c5a0 */
if(!s->budget--) { s->failed_pc=0x0c07c5a0u; return 0; }
r[4]+=r[14];
goto P_0c07c5a2;
P_0c07c5a2: /* original de3b, guest PC 0x0c07c5a2 */
if(!s->budget--) { s->failed_pc=0x0c07c5a2u; return 0; }
r[14]=read(ram,0x0c07c690u,4);
goto P_0c07c5a4;
P_0c07c5a4: /* original d23b, guest PC 0x0c07c5a4 */
if(!s->budget--) { s->failed_pc=0x0c07c5a4u; return 0; }
r[2]=read(ram,0x0c07c694u,4);
goto P_0c07c5a6;
P_0c07c5a6: /* original 65e3, guest PC 0x0c07c5a6 */
if(!s->budget--) { s->failed_pc=0x0c07c5a6u; return 0; }
r[5]=r[14];
goto P_0c07c5a8;
P_0c07c5a8: /* original 66e3, guest PC 0x0c07c5a8 */
if(!s->budget--) { s->failed_pc=0x0c07c5a8u; return 0; }
r[6]=r[14];
goto P_0c07c5aa;
P_0c07c5aa: /* original 420b, guest PC 0x0c07c5aa */
if(!s->budget--) { s->failed_pc=0x0c07c5aau; return 0; }
target=r[2];
r[16]=0x0c07c5aeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c5aeu) { target=s->pc; goto dispatch; }
goto P_0c07c5ae;
P_0c07c5ac: /* original 64e3, guest PC 0x0c07c5ac */
if(!s->budget--) { s->failed_pc=0x0c07c5acu; return 0; }
r[4]=r[14];
goto P_0c07c5ae;
P_0c07c5ae: /* original 1f93, guest PC 0x0c07c5ae */
if(!s->budget--) { s->failed_pc=0x0c07c5aeu; return 0; }
write(ram,r[15]+12,r[9],4);
goto P_0c07c5b0;
P_0c07c5b0: /* original e301, guest PC 0x0c07c5b0 */
if(!s->budget--) { s->failed_pc=0x0c07c5b0u; return 0; }
r[3]=0x00000001u;
goto P_0c07c5b2;
P_0c07c5b2: /* original 66d3, guest PC 0x0c07c5b2 */
if(!s->budget--) { s->failed_pc=0x0c07c5b2u; return 0; }
r[6]=r[13];
goto P_0c07c5b4;
P_0c07c5b4: /* original 2f36, guest PC 0x0c07c5b4 */
if(!s->budget--) { s->failed_pc=0x0c07c5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07c5b6;
P_0c07c5b6: /* original d238, guest PC 0x0c07c5b6 */
if(!s->budget--) { s->failed_pc=0x0c07c5b6u; return 0; }
r[2]=read(ram,0x0c07c698u,4);
goto P_0c07c5b8;
P_0c07c5b8: /* original 6793, guest PC 0x0c07c5b8 */
if(!s->budget--) { s->failed_pc=0x0c07c5b8u; return 0; }
r[7]=r[9];
goto P_0c07c5ba;
P_0c07c5ba: /* original 9556, guest PC 0x0c07c5ba */
if(!s->budget--) { s->failed_pc=0x0c07c5bau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c66au,2);
goto P_0c07c5bc;
P_0c07c5bc: /* original 420b, guest PC 0x0c07c5bc */
if(!s->budget--) { s->failed_pc=0x0c07c5bcu; return 0; }
target=r[2];
r[16]=0x0c07c5c0u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c5c0u) { target=s->pc; goto dispatch; }
goto P_0c07c5c0;
P_0c07c5be: /* original 6493, guest PC 0x0c07c5be */
if(!s->budget--) { s->failed_pc=0x0c07c5beu; return 0; }
r[4]=r[9];
goto P_0c07c5c0;
P_0c07c5c0: /* original 1c95, guest PC 0x0c07c5c0 */
if(!s->budget--) { s->failed_pc=0x0c07c5c0u; return 0; }
write(ram,r[12]+20,r[9],4);
goto P_0c07c5c2;
P_0c07c5c2: /* original 7f04, guest PC 0x0c07c5c2 */
if(!s->budget--) { s->failed_pc=0x0c07c5c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c5c4;
P_0c07c5c4: /* original 53f1, guest PC 0x0c07c5c4 */
if(!s->budget--) { s->failed_pc=0x0c07c5c4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c5c6;
P_0c07c5c6: /* original e010, guest PC 0x0c07c5c6 */
if(!s->budget--) { s->failed_pc=0x0c07c5c6u; return 0; }
r[0]=0x00000010u;
goto P_0c07c5c8;
P_0c07c5c8: /* original d234, guest PC 0x0c07c5c8 */
if(!s->budget--) { s->failed_pc=0x0c07c5c8u; return 0; }
r[2]=read(ram,0x0c07c69cu,4);
goto P_0c07c5ca;
P_0c07c5ca: /* original 1324, guest PC 0x0c07c5ca */
if(!s->budget--) { s->failed_pc=0x0c07c5cau; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07c5cc;
P_0c07c5cc: /* original 03cc, guest PC 0x0c07c5cc */
if(!s->budget--) { s->failed_pc=0x0c07c5ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07c5ce;
P_0c07c5ce: /* original 7301, guest PC 0x0c07c5ce */
if(!s->budget--) { s->failed_pc=0x0c07c5ceu; return 0; }
r[3]+=0x00000001u;
goto P_0c07c5d0;
P_0c07c5d0: /* original 0c34, guest PC 0x0c07c5d0 */
if(!s->budget--) { s->failed_pc=0x0c07c5d0u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c07c5d2;
P_0c07c5d2: /* original 55f3, guest PC 0x0c07c5d2 */
if(!s->budget--) { s->failed_pc=0x0c07c5d2u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07c5d4;
P_0c07c5d4: /* original 64f2, guest PC 0x0c07c5d4 */
if(!s->budget--) { s->failed_pc=0x0c07c5d4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c5d6;
P_0c07c5d6: /* original 7f10, guest PC 0x0c07c5d6 */
if(!s->budget--) { s->failed_pc=0x0c07c5d6u; return 0; }
r[15]+=0x00000010u;
goto P_0c07c5d8;
P_0c07c5d8: /* original 4f26, guest PC 0x0c07c5d8 */
if(!s->budget--) { s->failed_pc=0x0c07c5d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c5da;
P_0c07c5da: /* original 69f6, guest PC 0x0c07c5da */
if(!s->budget--) { s->failed_pc=0x0c07c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c5dc;
P_0c07c5dc: /* original 6af6, guest PC 0x0c07c5dc */
if(!s->budget--) { s->failed_pc=0x0c07c5dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c5de;
P_0c07c5de: /* original 6bf6, guest PC 0x0c07c5de */
if(!s->budget--) { s->failed_pc=0x0c07c5deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c5e0;
P_0c07c5e0: /* original 6cf6, guest PC 0x0c07c5e0 */
if(!s->budget--) { s->failed_pc=0x0c07c5e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c5e2;
P_0c07c5e2: /* original 6df6, guest PC 0x0c07c5e2 */
if(!s->budget--) { s->failed_pc=0x0c07c5e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c5e4;
P_0c07c5e4: /* original aa20, guest PC 0x0c07c5e4 */
if(!s->budget--) { s->failed_pc=0x0c07c5e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ba28;
P_0c07c5e6: /* original 6ef6, guest PC 0x0c07c5e6 */
if(!s->budget--) { s->failed_pc=0x0c07c5e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c5e8u,s,ram);
P_0c08c80e: /* original 6152, guest PC 0x0c08c80e */
if(!s->budget--) { s->failed_pc=0x0c08c80eu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c08c810;
P_0c08c810: /* original e3fe, guest PC 0x0c08c810 */
if(!s->budget--) { s->failed_pc=0x0c08c810u; return 0; }
r[3]=0xfffffffeu;
goto P_0c08c812;
P_0c08c812: /* original e028, guest PC 0x0c08c812 */
if(!s->budget--) { s->failed_pc=0x0c08c812u; return 0; }
r[0]=0x00000028u;
goto P_0c08c814;
P_0c08c814: /* original 2139, guest PC 0x0c08c814 */
if(!s->budget--) { s->failed_pc=0x0c08c814u; return 0; }
r[1]&=r[3];
goto P_0c08c816;
P_0c08c816: /* original 2512, guest PC 0x0c08c816 */
if(!s->budget--) { s->failed_pc=0x0c08c816u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c08c818;
P_0c08c818: /* original e500, guest PC 0x0c08c818 */
if(!s->budget--) { s->failed_pc=0x0c08c818u; return 0; }
r[5]=0x00000000u;
goto P_0c08c81a;
P_0c08c81a: /* original 0455, guest PC 0x0c08c81a */
if(!s->budget--) { s->failed_pc=0x0c08c81au; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c08c81c;
P_0c08c81c: /* original e02c, guest PC 0x0c08c81c */
if(!s->budget--) { s->failed_pc=0x0c08c81cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08c81e;
P_0c08c81e: /* original 0454, guest PC 0x0c08c81e */
if(!s->budget--) { s->failed_pc=0x0c08c81eu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08c820;
P_0c08c820: /* original e02d, guest PC 0x0c08c820 */
if(!s->budget--) { s->failed_pc=0x0c08c820u; return 0; }
r[0]=0x0000002du;
goto P_0c08c822;
P_0c08c822: /* original 0454, guest PC 0x0c08c822 */
if(!s->budget--) { s->failed_pc=0x0c08c822u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08c824;
P_0c08c824: /* original 6053, guest PC 0x0c08c824 */
if(!s->budget--) { s->failed_pc=0x0c08c824u; return 0; }
r[0]=r[5];
goto P_0c08c826;
P_0c08c826: /* original 000b, guest PC 0x0c08c826 */
if(!s->budget--) { s->failed_pc=0x0c08c826u; return 0; }
target=r[16];
write(ram,r[4]+20,r[0],2);
s->pc=target; return ram->oob==0;
P_0c08c828: /* original 814a, guest PC 0x0c08c828 */
if(!s->budget--) { s->failed_pc=0x0c08c828u; return 0; }
write(ram,r[4]+20,r[0],2);
return vf3_matrix_family(0x0c08c82au,s,ram);
P_0c08c82e: /* original 2fe6, guest PC 0x0c08c82e */
if(!s->budget--) { s->failed_pc=0x0c08c82eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08c830;
P_0c08c830: /* original e030, guest PC 0x0c08c830 */
if(!s->budget--) { s->failed_pc=0x0c08c830u; return 0; }
r[0]=0x00000030u;
goto P_0c08c832;
P_0c08c832: /* original 2fd6, guest PC 0x0c08c832 */
if(!s->budget--) { s->failed_pc=0x0c08c832u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08c834;
P_0c08c834: /* original 6e43, guest PC 0x0c08c834 */
if(!s->budget--) { s->failed_pc=0x0c08c834u; return 0; }
r[14]=r[4];
goto P_0c08c836;
P_0c08c836: /* original 2fc6, guest PC 0x0c08c836 */
if(!s->budget--) { s->failed_pc=0x0c08c836u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08c838;
P_0c08c838: /* original 6c53, guest PC 0x0c08c838 */
if(!s->budget--) { s->failed_pc=0x0c08c838u; return 0; }
r[12]=r[5];
goto P_0c08c83a;
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
P_0c08c990: /* original 2fe6, guest PC 0x0c08c990 */
if(!s->budget--) { s->failed_pc=0x0c08c990u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08c992;
P_0c08c992: /* original 6e53, guest PC 0x0c08c992 */
if(!s->budget--) { s->failed_pc=0x0c08c992u; return 0; }
r[14]=r[5];
goto P_0c08c994;
P_0c08c994: /* original 2fd6, guest PC 0x0c08c994 */
if(!s->budget--) { s->failed_pc=0x0c08c994u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08c996;
P_0c08c996: /* original e048, guest PC 0x0c08c996 */
if(!s->budget--) { s->failed_pc=0x0c08c996u; return 0; }
r[0]=0x00000048u;
goto P_0c08c998;
P_0c08c998: /* original 6d43, guest PC 0x0c08c998 */
if(!s->budget--) { s->failed_pc=0x0c08c998u; return 0; }
r[13]=r[4];
goto P_0c08c99a;
P_0c08c99a: /* original 2fc6, guest PC 0x0c08c99a */
if(!s->budget--) { s->failed_pc=0x0c08c99au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08c99c;
P_0c08c99c: /* original 04ee, guest PC 0x0c08c99c */
if(!s->budget--) { s->failed_pc=0x0c08c99cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08c99e;
P_0c08c99e: /* original e061, guest PC 0x0c08c99e */
if(!s->budget--) { s->failed_pc=0x0c08c99eu; return 0; }
r[0]=0x00000061u;
goto P_0c08c9a0;
P_0c08c9a0: /* original 4f22, guest PC 0x0c08c9a0 */
if(!s->budget--) { s->failed_pc=0x0c08c9a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c9a2;
P_0c08c9a2: /* original 044c, guest PC 0x0c08c9a2 */
if(!s->budget--) { s->failed_pc=0x0c08c9a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08c9a4;
P_0c08c9a4: /* original 6043, guest PC 0x0c08c9a4 */
if(!s->budget--) { s->failed_pc=0x0c08c9a4u; return 0; }
r[0]=r[4];
goto P_0c08c9a6;
P_0c08c9a6: /* original 80e8, guest PC 0x0c08c9a6 */
if(!s->budget--) { s->failed_pc=0x0c08c9a6u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c08c9a8;
P_0c08c9a8: /* original e048, guest PC 0x0c08c9a8 */
if(!s->budget--) { s->failed_pc=0x0c08c9a8u; return 0; }
r[0]=0x00000048u;
goto P_0c08c9aa;
P_0c08c9aa: /* original 00dc, guest PC 0x0c08c9aa */
if(!s->budget--) { s->failed_pc=0x0c08c9aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08c9ac;
P_0c08c9ac: /* original 8801, guest PC 0x0c08c9ac */
if(!s->budget--) { s->failed_pc=0x0c08c9acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c9ae;
P_0c08c9ae: /* original 8b01, guest PC 0x0c08c9ae */
if(!s->budget--) { s->failed_pc=0x0c08c9aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08c9b4; }
goto P_0c08c9b0;
P_0c08c9b0: /* original a08b, guest PC 0x0c08c9b0 */
if(!s->budget--) { s->failed_pc=0x0c08c9b0u; return 0; }
goto P_0c08caca;
P_0c08c9b2: /* original 0009, guest PC 0x0c08c9b2 */
if(!s->budget--) { s->failed_pc=0x0c08c9b2u; return 0; }
goto P_0c08c9b4;
P_0c08c9b4: /* original 60e2, guest PC 0x0c08c9b4 */
if(!s->budget--) { s->failed_pc=0x0c08c9b4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08c9b6;
P_0c08c9b6: /* original cb01, guest PC 0x0c08c9b6 */
if(!s->budget--) { s->failed_pc=0x0c08c9b6u; return 0; }
r[0]|=1u;
goto P_0c08c9b8;
P_0c08c9b8: /* original 2e02, guest PC 0x0c08c9b8 */
if(!s->budget--) { s->failed_pc=0x0c08c9b8u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08c9ba;
P_0c08c9ba: /* original e04c, guest PC 0x0c08c9ba */
if(!s->budget--) { s->failed_pc=0x0c08c9bau; return 0; }
r[0]=0x0000004cu;
goto P_0c08c9bc;
P_0c08c9bc: /* original 04ee, guest PC 0x0c08c9bc */
if(!s->budget--) { s->failed_pc=0x0c08c9bcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08c9be;
P_0c08c9be: /* original e03c, guest PC 0x0c08c9be */
if(!s->budget--) { s->failed_pc=0x0c08c9beu; return 0; }
r[0]=0x0000003cu;
goto P_0c08c9c0;
P_0c08c9c0: /* original 9335, guest PC 0x0c08c9c0 */
if(!s->budget--) { s->failed_pc=0x0c08c9c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca2eu,2);
goto P_0c08c9c2;
P_0c08c9c2: /* original 044d, guest PC 0x0c08c9c2 */
if(!s->budget--) { s->failed_pc=0x0c08c9c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08c9c4;
P_0c08c9c4: /* original 644d, guest PC 0x0c08c9c4 */
if(!s->budget--) { s->failed_pc=0x0c08c9c4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c9c6;
P_0c08c9c6: /* original 3430, guest PC 0x0c08c9c6 */
if(!s->budget--) { s->failed_pc=0x0c08c9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9c8;
P_0c08c9c8: /* original 891e, guest PC 0x0c08c9c8 */
if(!s->budget--) { s->failed_pc=0x0c08c9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9ca;
P_0c08c9ca: /* original 9231, guest PC 0x0c08c9ca */
if(!s->budget--) { s->failed_pc=0x0c08c9cau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca30u,2);
goto P_0c08c9cc;
P_0c08c9cc: /* original 3420, guest PC 0x0c08c9cc */
if(!s->budget--) { s->failed_pc=0x0c08c9ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9ce;
P_0c08c9ce: /* original 891b, guest PC 0x0c08c9ce */
if(!s->budget--) { s->failed_pc=0x0c08c9ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9d0;
P_0c08c9d0: /* original 932f, guest PC 0x0c08c9d0 */
if(!s->budget--) { s->failed_pc=0x0c08c9d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca32u,2);
goto P_0c08c9d2;
P_0c08c9d2: /* original 3430, guest PC 0x0c08c9d2 */
if(!s->budget--) { s->failed_pc=0x0c08c9d2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9d4;
P_0c08c9d4: /* original 8918, guest PC 0x0c08c9d4 */
if(!s->budget--) { s->failed_pc=0x0c08c9d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9d6;
P_0c08c9d6: /* original 922d, guest PC 0x0c08c9d6 */
if(!s->budget--) { s->failed_pc=0x0c08c9d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca34u,2);
goto P_0c08c9d8;
P_0c08c9d8: /* original 3420, guest PC 0x0c08c9d8 */
if(!s->budget--) { s->failed_pc=0x0c08c9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9da;
P_0c08c9da: /* original 8915, guest PC 0x0c08c9da */
if(!s->budget--) { s->failed_pc=0x0c08c9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9dc;
P_0c08c9dc: /* original 932b, guest PC 0x0c08c9dc */
if(!s->budget--) { s->failed_pc=0x0c08c9dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca36u,2);
goto P_0c08c9de;
P_0c08c9de: /* original 3430, guest PC 0x0c08c9de */
if(!s->budget--) { s->failed_pc=0x0c08c9deu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9e0;
P_0c08c9e0: /* original 8912, guest PC 0x0c08c9e0 */
if(!s->budget--) { s->failed_pc=0x0c08c9e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9e2;
P_0c08c9e2: /* original 9229, guest PC 0x0c08c9e2 */
if(!s->budget--) { s->failed_pc=0x0c08c9e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca38u,2);
goto P_0c08c9e4;
P_0c08c9e4: /* original 3420, guest PC 0x0c08c9e4 */
if(!s->budget--) { s->failed_pc=0x0c08c9e4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9e6;
P_0c08c9e6: /* original 890f, guest PC 0x0c08c9e6 */
if(!s->budget--) { s->failed_pc=0x0c08c9e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9e8;
P_0c08c9e8: /* original 9327, guest PC 0x0c08c9e8 */
if(!s->budget--) { s->failed_pc=0x0c08c9e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3au,2);
goto P_0c08c9ea;
P_0c08c9ea: /* original 3430, guest PC 0x0c08c9ea */
if(!s->budget--) { s->failed_pc=0x0c08c9eau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9ec;
P_0c08c9ec: /* original 890c, guest PC 0x0c08c9ec */
if(!s->budget--) { s->failed_pc=0x0c08c9ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9ee;
P_0c08c9ee: /* original 9225, guest PC 0x0c08c9ee */
if(!s->budget--) { s->failed_pc=0x0c08c9eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3cu,2);
goto P_0c08c9f0;
P_0c08c9f0: /* original 3420, guest PC 0x0c08c9f0 */
if(!s->budget--) { s->failed_pc=0x0c08c9f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9f2;
P_0c08c9f2: /* original 8909, guest PC 0x0c08c9f2 */
if(!s->budget--) { s->failed_pc=0x0c08c9f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9f4;
P_0c08c9f4: /* original 9323, guest PC 0x0c08c9f4 */
if(!s->budget--) { s->failed_pc=0x0c08c9f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca3eu,2);
goto P_0c08c9f6;
P_0c08c9f6: /* original 3430, guest PC 0x0c08c9f6 */
if(!s->budget--) { s->failed_pc=0x0c08c9f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08c9f8;
P_0c08c9f8: /* original 8906, guest PC 0x0c08c9f8 */
if(!s->budget--) { s->failed_pc=0x0c08c9f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08c9fa;
P_0c08c9fa: /* original 9221, guest PC 0x0c08c9fa */
if(!s->budget--) { s->failed_pc=0x0c08c9fau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ca40u,2);
goto P_0c08c9fc;
P_0c08c9fc: /* original 3420, guest PC 0x0c08c9fc */
if(!s->budget--) { s->failed_pc=0x0c08c9fcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08c9fe;
P_0c08c9fe: /* original 8903, guest PC 0x0c08c9fe */
if(!s->budget--) { s->failed_pc=0x0c08c9feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca08; }
goto P_0c08ca00;
P_0c08ca00: /* original 64e2, guest PC 0x0c08ca00 */
if(!s->budget--) { s->failed_pc=0x0c08ca00u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c08ca02;
P_0c08ca02: /* original e320, guest PC 0x0c08ca02 */
if(!s->budget--) { s->failed_pc=0x0c08ca02u; return 0; }
r[3]=0x00000020u;
goto P_0c08ca04;
P_0c08ca04: /* original 2438, guest PC 0x0c08ca04 */
if(!s->budget--) { s->failed_pc=0x0c08ca04u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08ca06;
P_0c08ca06: /* original 8925, guest PC 0x0c08ca06 */
if(!s->budget--) { s->failed_pc=0x0c08ca06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ca54; }
goto P_0c08ca08;
P_0c08ca08: /* original 84e8, guest PC 0x0c08ca08 */
if(!s->budget--) { s->failed_pc=0x0c08ca08u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca0a;
P_0c08ca0a: /* original d10e, guest PC 0x0c08ca0a */
if(!s->budget--) { s->failed_pc=0x0c08ca0au; return 0; }
r[1]=read(ram,0x0c08ca44u,4);
goto P_0c08ca0c;
P_0c08ca0c: /* original 600c, guest PC 0x0c08ca0c */
if(!s->budget--) { s->failed_pc=0x0c08ca0cu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca0e;
P_0c08ca0e: /* original d30e, guest PC 0x0c08ca0e */
if(!s->budget--) { s->failed_pc=0x0c08ca0eu; return 0; }
r[3]=read(ram,0x0c08ca48u,4);
goto P_0c08ca10;
P_0c08ca10: /* original 0c1c, guest PC 0x0c08ca10 */
if(!s->budget--) { s->failed_pc=0x0c08ca10u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08ca12;
P_0c08ca12: /* original 430b, guest PC 0x0c08ca12 */
if(!s->budget--) { s->failed_pc=0x0c08ca12u; return 0; }
target=r[3];
r[16]=0x0c08ca16u;
r[12]=r[12]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ca16u) { target=s->pc; goto dispatch; }
goto P_0c08ca16;
P_0c08ca14: /* original 6ccc, guest PC 0x0c08ca14 */
if(!s->budget--) { s->failed_pc=0x0c08ca14u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca16;
P_0c08ca16: /* original d20d, guest PC 0x0c08ca16 */
if(!s->budget--) { s->failed_pc=0x0c08ca16u; return 0; }
r[2]=read(ram,0x0c08ca4cu,4);
goto P_0c08ca18;
P_0c08ca18: /* original 6103, guest PC 0x0c08ca18 */
if(!s->budget--) { s->failed_pc=0x0c08ca18u; return 0; }
r[1]=r[0];
goto P_0c08ca1a;
P_0c08ca1a: /* original 420b, guest PC 0x0c08ca1a */
if(!s->budget--) { s->failed_pc=0x0c08ca1au; return 0; }
target=r[2];
r[16]=0x0c08ca1eu;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ca1eu) { target=s->pc; goto dispatch; }
goto P_0c08ca1e;
P_0c08ca1c: /* original 60c3, guest PC 0x0c08ca1c */
if(!s->budget--) { s->failed_pc=0x0c08ca1cu; return 0; }
r[0]=r[12];
goto P_0c08ca1e;
P_0c08ca1e: /* original 6c03, guest PC 0x0c08ca1e */
if(!s->budget--) { s->failed_pc=0x0c08ca1eu; return 0; }
r[12]=r[0];
goto P_0c08ca20;
P_0c08ca20: /* original 84e8, guest PC 0x0c08ca20 */
if(!s->budget--) { s->failed_pc=0x0c08ca20u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca22;
P_0c08ca22: /* original d10b, guest PC 0x0c08ca22 */
if(!s->budget--) { s->failed_pc=0x0c08ca22u; return 0; }
r[1]=read(ram,0x0c08ca50u,4);
goto P_0c08ca24;
P_0c08ca24: /* original 64c3, guest PC 0x0c08ca24 */
if(!s->budget--) { s->failed_pc=0x0c08ca24u; return 0; }
r[4]=r[12];
goto P_0c08ca26;
P_0c08ca26: /* original 600c, guest PC 0x0c08ca26 */
if(!s->budget--) { s->failed_pc=0x0c08ca26u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca28;
P_0c08ca28: /* original 4008, guest PC 0x0c08ca28 */
if(!s->budget--) { s->failed_pc=0x0c08ca28u; return 0; }
r[0]<<=2;
goto P_0c08ca2a;
P_0c08ca2a: /* original a036, guest PC 0x0c08ca2a */
if(!s->budget--) { s->failed_pc=0x0c08ca2au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08ca9a;
P_0c08ca2c: /* original 4400, guest PC 0x0c08ca2c */
if(!s->budget--) { s->failed_pc=0x0c08ca2cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
return vf3_matrix_family(0x0c08ca2eu,s,ram);
P_0c08ca54: /* original 84e8, guest PC 0x0c08ca54 */
if(!s->budget--) { s->failed_pc=0x0c08ca54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca56;
P_0c08ca56: /* original e304, guest PC 0x0c08ca56 */
if(!s->budget--) { s->failed_pc=0x0c08ca56u; return 0; }
r[3]=0x00000004u;
goto P_0c08ca58;
P_0c08ca58: /* original d246, guest PC 0x0c08ca58 */
if(!s->budget--) { s->failed_pc=0x0c08ca58u; return 0; }
r[2]=read(ram,0x0c08cb74u,4);
goto P_0c08ca5a;
P_0c08ca5a: /* original d147, guest PC 0x0c08ca5a */
if(!s->budget--) { s->failed_pc=0x0c08ca5au; return 0; }
r[1]=read(ram,0x0c08cb78u,4);
goto P_0c08ca5c;
P_0c08ca5c: /* original 600c, guest PC 0x0c08ca5c */
if(!s->budget--) { s->failed_pc=0x0c08ca5cu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca5e;
P_0c08ca5e: /* original 6420, guest PC 0x0c08ca5e */
if(!s->budget--) { s->failed_pc=0x0c08ca5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[4]=tmp;
goto P_0c08ca60;
P_0c08ca60: /* original 0c1c, guest PC 0x0c08ca60 */
if(!s->budget--) { s->failed_pc=0x0c08ca60u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08ca62;
P_0c08ca62: /* original 3432, guest PC 0x0c08ca62 */
if(!s->budget--) { s->failed_pc=0x0c08ca62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c08ca64;
P_0c08ca64: /* original 8f0b, guest PC 0x0c08ca64 */
if(!s->budget--) { s->failed_pc=0x0c08ca64u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08ca7e; }
goto P_0c08ca68;
P_0c08ca66: /* original 6ccc, guest PC 0x0c08ca66 */
if(!s->budget--) { s->failed_pc=0x0c08ca66u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca68;
P_0c08ca68: /* original 84e8, guest PC 0x0c08ca68 */
if(!s->budget--) { s->failed_pc=0x0c08ca68u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca6a;
P_0c08ca6a: /* original e302, guest PC 0x0c08ca6a */
if(!s->budget--) { s->failed_pc=0x0c08ca6au; return 0; }
r[3]=0x00000002u;
goto P_0c08ca6c;
P_0c08ca6c: /* original d243, guest PC 0x0c08ca6c */
if(!s->budget--) { s->failed_pc=0x0c08ca6cu; return 0; }
r[2]=read(ram,0x0c08cb7cu,4);
goto P_0c08ca6e;
P_0c08ca6e: /* original 600c, guest PC 0x0c08ca6e */
if(!s->budget--) { s->failed_pc=0x0c08ca6eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca70;
P_0c08ca70: /* original 0c2c, guest PC 0x0c08ca70 */
if(!s->budget--) { s->failed_pc=0x0c08ca70u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c08ca72;
P_0c08ca72: /* original e04f, guest PC 0x0c08ca72 */
if(!s->budget--) { s->failed_pc=0x0c08ca72u; return 0; }
r[0]=0x0000004fu;
goto P_0c08ca74;
P_0c08ca74: /* original 01dc, guest PC 0x0c08ca74 */
if(!s->budget--) { s->failed_pc=0x0c08ca74u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08ca76;
P_0c08ca76: /* original 3133, guest PC 0x0c08ca76 */
if(!s->budget--) { s->failed_pc=0x0c08ca76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c08ca78;
P_0c08ca78: /* original 8f01, guest PC 0x0c08ca78 */
if(!s->budget--) { s->failed_pc=0x0c08ca78u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08ca7e; }
goto P_0c08ca7c;
P_0c08ca7a: /* original 6ccc, guest PC 0x0c08ca7a */
if(!s->budget--) { s->failed_pc=0x0c08ca7au; return 0; }
r[12]=r[12]&255u;
goto P_0c08ca7c;
P_0c08ca7c: /* original 3c38, guest PC 0x0c08ca7c */
if(!s->budget--) { s->failed_pc=0x0c08ca7cu; return 0; }
r[12]-=r[3];
goto P_0c08ca7e;
P_0c08ca7e: /* original d340, guest PC 0x0c08ca7e */
if(!s->budget--) { s->failed_pc=0x0c08ca7eu; return 0; }
r[3]=read(ram,0x0c08cb80u,4);
goto P_0c08ca80;
P_0c08ca80: /* original 430b, guest PC 0x0c08ca80 */
if(!s->budget--) { s->failed_pc=0x0c08ca80u; return 0; }
target=r[3];
r[16]=0x0c08ca84u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ca84u) { target=s->pc; goto dispatch; }
goto P_0c08ca84;
P_0c08ca82: /* original 0009, guest PC 0x0c08ca82 */
if(!s->budget--) { s->failed_pc=0x0c08ca82u; return 0; }
goto P_0c08ca84;
P_0c08ca84: /* original d23f, guest PC 0x0c08ca84 */
if(!s->budget--) { s->failed_pc=0x0c08ca84u; return 0; }
r[2]=read(ram,0x0c08cb84u,4);
goto P_0c08ca86;
P_0c08ca86: /* original 6103, guest PC 0x0c08ca86 */
if(!s->budget--) { s->failed_pc=0x0c08ca86u; return 0; }
r[1]=r[0];
goto P_0c08ca88;
P_0c08ca88: /* original 420b, guest PC 0x0c08ca88 */
if(!s->budget--) { s->failed_pc=0x0c08ca88u; return 0; }
target=r[2];
r[16]=0x0c08ca8cu;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ca8cu) { target=s->pc; goto dispatch; }
goto P_0c08ca8c;
P_0c08ca8a: /* original 60c3, guest PC 0x0c08ca8a */
if(!s->budget--) { s->failed_pc=0x0c08ca8au; return 0; }
r[0]=r[12];
goto P_0c08ca8c;
P_0c08ca8c: /* original 6c03, guest PC 0x0c08ca8c */
if(!s->budget--) { s->failed_pc=0x0c08ca8cu; return 0; }
r[12]=r[0];
goto P_0c08ca8e;
P_0c08ca8e: /* original 84e8, guest PC 0x0c08ca8e */
if(!s->budget--) { s->failed_pc=0x0c08ca8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08ca90;
P_0c08ca90: /* original 64c3, guest PC 0x0c08ca90 */
if(!s->budget--) { s->failed_pc=0x0c08ca90u; return 0; }
r[4]=r[12];
goto P_0c08ca92;
P_0c08ca92: /* original d13d, guest PC 0x0c08ca92 */
if(!s->budget--) { s->failed_pc=0x0c08ca92u; return 0; }
r[1]=read(ram,0x0c08cb88u,4);
goto P_0c08ca94;
P_0c08ca94: /* original 600c, guest PC 0x0c08ca94 */
if(!s->budget--) { s->failed_pc=0x0c08ca94u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ca96;
P_0c08ca96: /* original 4400, guest PC 0x0c08ca96 */
if(!s->budget--) { s->failed_pc=0x0c08ca96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08ca98;
P_0c08ca98: /* original 4008, guest PC 0x0c08ca98 */
if(!s->budget--) { s->failed_pc=0x0c08ca98u; return 0; }
r[0]<<=2;
goto P_0c08ca9a;
P_0c08ca9a: /* original 001e, guest PC 0x0c08ca9a */
if(!s->budget--) { s->failed_pc=0x0c08ca9au; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08ca9c;
P_0c08ca9c: /* original e500, guest PC 0x0c08ca9c */
if(!s->budget--) { s->failed_pc=0x0c08ca9cu; return 0; }
r[5]=0x00000000u;
goto P_0c08ca9e;
P_0c08ca9e: /* original 044d, guest PC 0x0c08ca9e */
if(!s->budget--) { s->failed_pc=0x0c08ca9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08caa0;
P_0c08caa0: /* original e028, guest PC 0x0c08caa0 */
if(!s->budget--) { s->failed_pc=0x0c08caa0u; return 0; }
r[0]=0x00000028u;
goto P_0c08caa2;
P_0c08caa2: /* original 644d, guest PC 0x0c08caa2 */
if(!s->budget--) { s->failed_pc=0x0c08caa2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08caa4;
P_0c08caa4: /* original 0d45, guest PC 0x0c08caa4 */
if(!s->budget--) { s->failed_pc=0x0c08caa4u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08caa6;
P_0c08caa6: /* original e040, guest PC 0x0c08caa6 */
if(!s->budget--) { s->failed_pc=0x0c08caa6u; return 0; }
r[0]=0x00000040u;
goto P_0c08caa8;
P_0c08caa8: /* original 1e4d, guest PC 0x0c08caa8 */
if(!s->budget--) { s->failed_pc=0x0c08caa8u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08caaa;
P_0c08caaa: /* original 0e56, guest PC 0x0c08caaa */
if(!s->budget--) { s->failed_pc=0x0c08caaau; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08caac;
P_0c08caac: /* original b354, guest PC 0x0c08caac */
if(!s->budget--) { s->failed_pc=0x0c08caacu; return 0; }
target=0x0c08d158u; r[16]=0x0c08cab0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cab0u) { target=s->pc; goto dispatch; }
goto P_0c08cab0;
P_0c08caae: /* original 64e3, guest PC 0x0c08caae */
if(!s->budget--) { s->failed_pc=0x0c08caaeu; return 0; }
r[4]=r[14];
goto P_0c08cab0;
P_0c08cab0: /* original e200, guest PC 0x0c08cab0 */
if(!s->budget--) { s->failed_pc=0x0c08cab0u; return 0; }
r[2]=0x00000000u;
goto P_0c08cab2;
P_0c08cab2: /* original 55ee, guest PC 0x0c08cab2 */
if(!s->budget--) { s->failed_pc=0x0c08cab2u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cab4;
P_0c08cab4: /* original e02c, guest PC 0x0c08cab4 */
if(!s->budget--) { s->failed_pc=0x0c08cab4u; return 0; }
r[0]=0x0000002cu;
goto P_0c08cab6;
P_0c08cab6: /* original 54ef, guest PC 0x0c08cab6 */
if(!s->budget--) { s->failed_pc=0x0c08cab6u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cab8;
P_0c08cab8: /* original 0d24, guest PC 0x0c08cab8 */
if(!s->budget--) { s->failed_pc=0x0c08cab8u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08caba;
P_0c08caba: /* original e02d, guest PC 0x0c08caba */
if(!s->budget--) { s->failed_pc=0x0c08cabau; return 0; }
r[0]=0x0000002du;
goto P_0c08cabc;
P_0c08cabc: /* original 0d54, guest PC 0x0c08cabc */
if(!s->budget--) { s->failed_pc=0x0c08cabcu; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cabe;
P_0c08cabe: /* original 6043, guest PC 0x0c08cabe */
if(!s->budget--) { s->failed_pc=0x0c08cabeu; return 0; }
r[0]=r[4];
goto P_0c08cac0;
P_0c08cac0: /* original 81da, guest PC 0x0c08cac0 */
if(!s->budget--) { s->failed_pc=0x0c08cac0u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cac2;
P_0c08cac2: /* original e048, guest PC 0x0c08cac2 */
if(!s->budget--) { s->failed_pc=0x0c08cac2u; return 0; }
r[0]=0x00000048u;
goto P_0c08cac4;
P_0c08cac4: /* original 03dc, guest PC 0x0c08cac4 */
if(!s->budget--) { s->failed_pc=0x0c08cac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cac6;
P_0c08cac6: /* original 7301, guest PC 0x0c08cac6 */
if(!s->budget--) { s->failed_pc=0x0c08cac6u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cac8;
P_0c08cac8: /* original 0d34, guest PC 0x0c08cac8 */
if(!s->budget--) { s->failed_pc=0x0c08cac8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08caca;
P_0c08caca: /* original 4f26, guest PC 0x0c08caca */
if(!s->budget--) { s->failed_pc=0x0c08cacau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cacc;
P_0c08cacc: /* original 6cf6, guest PC 0x0c08cacc */
if(!s->budget--) { s->failed_pc=0x0c08caccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cace;
P_0c08cace: /* original 6df6, guest PC 0x0c08cace */
if(!s->budget--) { s->failed_pc=0x0c08caceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cad0;
P_0c08cad0: /* original 000b, guest PC 0x0c08cad0 */
if(!s->budget--) { s->failed_pc=0x0c08cad0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cad2: /* original 6ef6, guest PC 0x0c08cad2 */
if(!s->budget--) { s->failed_pc=0x0c08cad2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08cad4u,s,ram);
P_0c09635a: /* original 4f22, guest PC 0x0c09635a */
if(!s->budget--) { s->failed_pc=0x0c09635au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09635c;
P_0c09635c: /* original dc16, guest PC 0x0c09635c */
if(!s->budget--) { s->failed_pc=0x0c09635cu; return 0; }
r[12]=read(ram,0x0c0963b8u,4);
goto P_0c09635e;
P_0c09635e: /* original de17, guest PC 0x0c09635e */
if(!s->budget--) { s->failed_pc=0x0c09635eu; return 0; }
r[14]=read(ram,0x0c0963bcu,4);
goto P_0c096360;
P_0c096360: /* original 0436, guest PC 0x0c096360 */
if(!s->budget--) { s->failed_pc=0x0c096360u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096362;
P_0c096362: /* original 70fc, guest PC 0x0c096362 */
if(!s->budget--) { s->failed_pc=0x0c096362u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096364;
P_0c096364: /* original 0436, guest PC 0x0c096364 */
if(!s->budget--) { s->failed_pc=0x0c096364u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096366;
P_0c096366: /* original 70fc, guest PC 0x0c096366 */
if(!s->budget--) { s->failed_pc=0x0c096366u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096368;
P_0c096368: /* original 0436, guest PC 0x0c096368 */
if(!s->budget--) { s->failed_pc=0x0c096368u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09636a;
P_0c09636a: /* original 6433, guest PC 0x0c09636a */
if(!s->budget--) { s->failed_pc=0x0c09636au; return 0; }
r[4]=r[3];
goto P_0c09636c;
P_0c09636c: /* original d614, guest PC 0x0c09636c */
if(!s->budget--) { s->failed_pc=0x0c09636cu; return 0; }
r[6]=read(ram,0x0c0963c0u,4);
goto P_0c09636e;
P_0c09636e: /* original 7ffc, guest PC 0x0c09636e */
if(!s->budget--) { s->failed_pc=0x0c09636eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096370;
P_0c096370: /* original bf6a, guest PC 0x0c096370 */
if(!s->budget--) { s->failed_pc=0x0c096370u; return 0; }
target=0x0c096248u; r[16]=0x0c096374u;
r[13]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096374u) { target=s->pc; goto dispatch; }
goto P_0c096374;
P_0c096372: /* original ed01, guest PC 0x0c096372 */
if(!s->budget--) { s->failed_pc=0x0c096372u; return 0; }
r[13]=0x00000001u;
goto P_0c096374;
P_0c096374: /* original d613, guest PC 0x0c096374 */
if(!s->budget--) { s->failed_pc=0x0c096374u; return 0; }
r[6]=read(ram,0x0c0963c4u,4);
goto P_0c096376;
P_0c096376: /* original 65d3, guest PC 0x0c096376 */
if(!s->budget--) { s->failed_pc=0x0c096376u; return 0; }
r[5]=r[13];
goto P_0c096378;
P_0c096378: /* original bf66, guest PC 0x0c096378 */
if(!s->budget--) { s->failed_pc=0x0c096378u; return 0; }
target=0x0c096248u; r[16]=0x0c09637cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09637cu) { target=s->pc; goto dispatch; }
goto P_0c09637c;
P_0c09637a: /* original 64d3, guest PC 0x0c09637a */
if(!s->budget--) { s->failed_pc=0x0c09637au; return 0; }
r[4]=r[13];
goto P_0c09637c;
P_0c09637c: /* original 9b19, guest PC 0x0c09637c */
if(!s->budget--) { s->failed_pc=0x0c09637cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0963b2u,2);
goto P_0c09637e;
P_0c09637e: /* original d912, guest PC 0x0c09637e */
if(!s->budget--) { s->failed_pc=0x0c09637eu; return 0; }
r[9]=read(ram,0x0c0963c8u,4);
goto P_0c096380;
P_0c096380: /* original a059, guest PC 0x0c096380 */
if(!s->budget--) { s->failed_pc=0x0c096380u; return 0; }
r[8]=0x00000000u;
goto P_0c096436;
P_0c096382: /* original e800, guest PC 0x0c096382 */
if(!s->budget--) { s->failed_pc=0x0c096382u; return 0; }
r[8]=0x00000000u;
goto P_0c096384;
P_0c096384: /* original 4c0b, guest PC 0x0c096384 */
if(!s->budget--) { s->failed_pc=0x0c096384u; return 0; }
target=r[12];
r[16]=0x0c096388u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096388u) { target=s->pc; goto dispatch; }
goto P_0c096388;
P_0c096386: /* original 6483, guest PC 0x0c096386 */
if(!s->budget--) { s->failed_pc=0x0c096386u; return 0; }
r[4]=r[8];
goto P_0c096388;
P_0c096388: /* original 6403, guest PC 0x0c096388 */
if(!s->budget--) { s->failed_pc=0x0c096388u; return 0; }
r[4]=r[0];
goto P_0c09638a;
P_0c09638a: /* original 5244, guest PC 0x0c09638a */
if(!s->budget--) { s->failed_pc=0x0c09638au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09638c;
P_0c09638c: /* original 22b9, guest PC 0x0c09638c */
if(!s->budget--) { s->failed_pc=0x0c09638cu; return 0; }
r[2]&=r[11];
goto P_0c09638e;
P_0c09638e: /* original 32b0, guest PC 0x0c09638e */
if(!s->budget--) { s->failed_pc=0x0c09638eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c096390;
P_0c096390: /* original 8b50, guest PC 0x0c096390 */
if(!s->budget--) { s->failed_pc=0x0c096390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c096392;
P_0c096392: /* original 5242, guest PC 0x0c096392 */
if(!s->budget--) { s->failed_pc=0x0c096392u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096394;
P_0c096394: /* original 22a8, guest PC 0x0c096394 */
if(!s->budget--) { s->failed_pc=0x0c096394u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c096396;
P_0c096396: /* original 894d, guest PC 0x0c096396 */
if(!s->budget--) { s->failed_pc=0x0c096396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096434; }
goto P_0c096398;
P_0c096398: /* original d106, guest PC 0x0c096398 */
if(!s->budget--) { s->failed_pc=0x0c096398u; return 0; }
r[1]=read(ram,0x0c0963b4u,4);
goto P_0c09639a;
P_0c09639a: /* original d30c, guest PC 0x0c09639a */
if(!s->budget--) { s->failed_pc=0x0c09639au; return 0; }
r[3]=read(ram,0x0c0963ccu,4);
goto P_0c09639c;
P_0c09639c: /* original 6412, guest PC 0x0c09639c */
if(!s->budget--) { s->failed_pc=0x0c09639cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c09639e;
P_0c09639e: /* original 2348, guest PC 0x0c09639e */
if(!s->budget--) { s->failed_pc=0x0c09639eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0963a0;
P_0c0963a0: /* original 8916, guest PC 0x0c0963a0 */
if(!s->budget--) { s->failed_pc=0x0c0963a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0963d0; }
goto P_0c0963a2;
P_0c0963a2: /* original e500, guest PC 0x0c0963a2 */
if(!s->budget--) { s->failed_pc=0x0c0963a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0963a4;
P_0c0963a4: /* original b25e, guest PC 0x0c0963a4 */
if(!s->budget--) { s->failed_pc=0x0c0963a4u; return 0; }
target=0x0c096864u; r[16]=0x0c0963a8u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963a8u) { target=s->pc; goto dispatch; }
goto P_0c0963a8;
P_0c0963a6: /* original 6453, guest PC 0x0c0963a6 */
if(!s->budget--) { s->failed_pc=0x0c0963a6u; return 0; }
r[4]=r[5];
goto P_0c0963a8;
P_0c0963a8: /* original a044, guest PC 0x0c0963a8 */
if(!s->budget--) { s->failed_pc=0x0c0963a8u; return 0; }
goto P_0c096434;
P_0c0963aa: /* original 0009, guest PC 0x0c0963aa */
if(!s->budget--) { s->failed_pc=0x0c0963aau; return 0; }
return vf3_matrix_family(0x0c0963acu,s,ram);
P_0c0963d0: /* original d33d, guest PC 0x0c0963d0 */
if(!s->budget--) { s->failed_pc=0x0c0963d0u; return 0; }
r[3]=read(ram,0x0c0964c8u,4);
goto P_0c0963d2;
P_0c0963d2: /* original 2438, guest PC 0x0c0963d2 */
if(!s->budget--) { s->failed_pc=0x0c0963d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0963d4;
P_0c0963d4: /* original 8b2e, guest PC 0x0c0963d4 */
if(!s->budget--) { s->failed_pc=0x0c0963d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c0963d6;
P_0c0963d6: /* original d23d, guest PC 0x0c0963d6 */
if(!s->budget--) { s->failed_pc=0x0c0963d6u; return 0; }
r[2]=read(ram,0x0c0964ccu,4);
goto P_0c0963d8;
P_0c0963d8: /* original e600, guest PC 0x0c0963d8 */
if(!s->budget--) { s->failed_pc=0x0c0963d8u; return 0; }
r[6]=0x00000000u;
goto P_0c0963da;
P_0c0963da: /* original 6563, guest PC 0x0c0963da */
if(!s->budget--) { s->failed_pc=0x0c0963dau; return 0; }
r[5]=r[6];
goto P_0c0963dc;
P_0c0963dc: /* original 22d2, guest PC 0x0c0963dc */
if(!s->budget--) { s->failed_pc=0x0c0963dcu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c0963de;
P_0c0963de: /* original d13c, guest PC 0x0c0963de */
if(!s->budget--) { s->failed_pc=0x0c0963deu; return 0; }
r[1]=read(ram,0x0c0964d0u,4);
goto P_0c0963e0;
P_0c0963e0: /* original 410b, guest PC 0x0c0963e0 */
if(!s->budget--) { s->failed_pc=0x0c0963e0u; return 0; }
target=r[1];
r[16]=0x0c0963e4u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963e4u) { target=s->pc; goto dispatch; }
goto P_0c0963e4;
P_0c0963e2: /* original 6463, guest PC 0x0c0963e2 */
if(!s->budget--) { s->failed_pc=0x0c0963e2u; return 0; }
r[4]=r[6];
goto P_0c0963e4;
P_0c0963e4: /* original d33b, guest PC 0x0c0963e4 */
if(!s->budget--) { s->failed_pc=0x0c0963e4u; return 0; }
r[3]=read(ram,0x0c0964d4u,4);
goto P_0c0963e6;
P_0c0963e6: /* original 430b, guest PC 0x0c0963e6 */
if(!s->budget--) { s->failed_pc=0x0c0963e6u; return 0; }
target=r[3];
r[16]=0x0c0963eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963eau) { target=s->pc; goto dispatch; }
goto P_0c0963ea;
P_0c0963e8: /* original 0009, guest PC 0x0c0963e8 */
if(!s->budget--) { s->failed_pc=0x0c0963e8u; return 0; }
goto P_0c0963ea;
P_0c0963ea: /* original 0002, guest PC 0x0c0963ea */
if(!s->budget--) { s->failed_pc=0x0c0963eau; return 0; }
r[0]=r[17];
goto P_0c0963ec;
P_0c0963ec: /* original 926a, guest PC 0x0c0963ec */
if(!s->budget--) { s->failed_pc=0x0c0963ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c0963ee;
P_0c0963ee: /* original 2029, guest PC 0x0c0963ee */
if(!s->budget--) { s->failed_pc=0x0c0963eeu; return 0; }
r[0]&=r[2];
goto P_0c0963f0;
P_0c0963f0: /* original cbe0, guest PC 0x0c0963f0 */
if(!s->budget--) { s->failed_pc=0x0c0963f0u; return 0; }
r[0]|=224u;
goto P_0c0963f2;
P_0c0963f2: /* original 400e, guest PC 0x0c0963f2 */
if(!s->budget--) { s->failed_pc=0x0c0963f2u; return 0; }
r[17]=r[0];
goto P_0c0963f4;
P_0c0963f4: /* original d338, guest PC 0x0c0963f4 */
if(!s->budget--) { s->failed_pc=0x0c0963f4u; return 0; }
r[3]=read(ram,0x0c0964d8u,4);
goto P_0c0963f6;
P_0c0963f6: /* original 430b, guest PC 0x0c0963f6 */
if(!s->budget--) { s->failed_pc=0x0c0963f6u; return 0; }
target=r[3];
r[16]=0x0c0963fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963fau) { target=s->pc; goto dispatch; }
goto P_0c0963fa;
P_0c0963f8: /* original 0009, guest PC 0x0c0963f8 */
if(!s->budget--) { s->failed_pc=0x0c0963f8u; return 0; }
goto P_0c0963fa;
P_0c0963fa: /* original d138, guest PC 0x0c0963fa */
if(!s->budget--) { s->failed_pc=0x0c0963fau; return 0; }
r[1]=read(ram,0x0c0964dcu,4);
goto P_0c0963fc;
P_0c0963fc: /* original 410b, guest PC 0x0c0963fc */
if(!s->budget--) { s->failed_pc=0x0c0963fcu; return 0; }
target=r[1];
r[16]=0x0c096400u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096400u) { target=s->pc; goto dispatch; }
goto P_0c096400;
P_0c0963fe: /* original 0009, guest PC 0x0c0963fe */
if(!s->budget--) { s->failed_pc=0x0c0963feu; return 0; }
goto P_0c096400;
P_0c096400: /* original 0002, guest PC 0x0c096400 */
if(!s->budget--) { s->failed_pc=0x0c096400u; return 0; }
r[0]=r[17];
goto P_0c096402;
P_0c096402: /* original 935f, guest PC 0x0c096402 */
if(!s->budget--) { s->failed_pc=0x0c096402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096404;
P_0c096404: /* original 2039, guest PC 0x0c096404 */
if(!s->budget--) { s->failed_pc=0x0c096404u; return 0; }
r[0]&=r[3];
goto P_0c096406;
P_0c096406: /* original 400e, guest PC 0x0c096406 */
if(!s->budget--) { s->failed_pc=0x0c096406u; return 0; }
r[17]=r[0];
goto P_0c096408;
P_0c096408: /* original d235, guest PC 0x0c096408 */
if(!s->budget--) { s->failed_pc=0x0c096408u; return 0; }
r[2]=read(ram,0x0c0964e0u,4);
goto P_0c09640a;
P_0c09640a: /* original 420b, guest PC 0x0c09640a */
if(!s->budget--) { s->failed_pc=0x0c09640au; return 0; }
target=r[2];
r[16]=0x0c09640eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09640eu) { target=s->pc; goto dispatch; }
goto P_0c09640e;
P_0c09640c: /* original 0009, guest PC 0x0c09640c */
if(!s->budget--) { s->failed_pc=0x0c09640cu; return 0; }
goto P_0c09640e;
P_0c09640e: /* original d134, guest PC 0x0c09640e */
if(!s->budget--) { s->failed_pc=0x0c09640eu; return 0; }
r[1]=read(ram,0x0c0964e0u,4);
goto P_0c096410;
P_0c096410: /* original 410b, guest PC 0x0c096410 */
if(!s->budget--) { s->failed_pc=0x0c096410u; return 0; }
target=r[1];
r[16]=0x0c096414u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096414u) { target=s->pc; goto dispatch; }
goto P_0c096414;
P_0c096412: /* original 0009, guest PC 0x0c096412 */
if(!s->budget--) { s->failed_pc=0x0c096412u; return 0; }
goto P_0c096414;
P_0c096414: /* original d233, guest PC 0x0c096414 */
if(!s->budget--) { s->failed_pc=0x0c096414u; return 0; }
r[2]=read(ram,0x0c0964e4u,4);
goto P_0c096416;
P_0c096416: /* original 229b, guest PC 0x0c096416 */
if(!s->budget--) { s->failed_pc=0x0c096416u; return 0; }
r[2]|=r[9];
goto P_0c096418;
P_0c096418: /* original 420b, guest PC 0x0c096418 */
if(!s->budget--) { s->failed_pc=0x0c096418u; return 0; }
target=r[2];
r[16]=0x0c09641cu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09641cu) { target=s->pc; goto dispatch; }
goto P_0c09641c;
P_0c09641a: /* original e400, guest PC 0x0c09641a */
if(!s->budget--) { s->failed_pc=0x0c09641au; return 0; }
r[4]=0x00000000u;
goto P_0c09641c;
P_0c09641c: /* original d332, guest PC 0x0c09641c */
if(!s->budget--) { s->failed_pc=0x0c09641cu; return 0; }
r[3]=read(ram,0x0c0964e8u,4);
goto P_0c09641e;
P_0c09641e: /* original 239b, guest PC 0x0c09641e */
if(!s->budget--) { s->failed_pc=0x0c09641eu; return 0; }
r[3]|=r[9];
goto P_0c096420;
P_0c096420: /* original 430b, guest PC 0x0c096420 */
if(!s->budget--) { s->failed_pc=0x0c096420u; return 0; }
target=r[3];
r[16]=0x0c096424u;
r[4]=0x0000003fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096424u) { target=s->pc; goto dispatch; }
goto P_0c096424;
P_0c096422: /* original e43f, guest PC 0x0c096422 */
if(!s->budget--) { s->failed_pc=0x0c096422u; return 0; }
r[4]=0x0000003fu;
goto P_0c096424;
P_0c096424: /* original 0002, guest PC 0x0c096424 */
if(!s->budget--) { s->failed_pc=0x0c096424u; return 0; }
r[0]=r[17];
goto P_0c096426;
P_0c096426: /* original 924d, guest PC 0x0c096426 */
if(!s->budget--) { s->failed_pc=0x0c096426u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096428;
P_0c096428: /* original 2029, guest PC 0x0c096428 */
if(!s->budget--) { s->failed_pc=0x0c096428u; return 0; }
r[0]&=r[2];
goto P_0c09642a;
P_0c09642a: /* original cbe0, guest PC 0x0c09642a */
if(!s->budget--) { s->failed_pc=0x0c09642au; return 0; }
r[0]|=224u;
goto P_0c09642c;
P_0c09642c: /* original 400e, guest PC 0x0c09642c */
if(!s->budget--) { s->failed_pc=0x0c09642cu; return 0; }
r[17]=r[0];
goto P_0c09642e;
P_0c09642e: /* original d32f, guest PC 0x0c09642e */
if(!s->budget--) { s->failed_pc=0x0c09642eu; return 0; }
r[3]=read(ram,0x0c0964ecu,4);
goto P_0c096430;
P_0c096430: /* original 430b, guest PC 0x0c096430 */
if(!s->budget--) { s->failed_pc=0x0c096430u; return 0; }
target=r[3];
r[16]=0x0c096434u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096434u) { target=s->pc; goto dispatch; }
goto P_0c096434;
P_0c096432: /* original 0009, guest PC 0x0c096432 */
if(!s->budget--) { s->failed_pc=0x0c096432u; return 0; }
goto P_0c096434;
P_0c096434: /* original 7801, guest PC 0x0c096434 */
if(!s->budget--) { s->failed_pc=0x0c096434u; return 0; }
r[8]+=0x00000001u;
goto P_0c096436;
P_0c096436: /* original e202, guest PC 0x0c096436 */
if(!s->budget--) { s->failed_pc=0x0c096436u; return 0; }
r[2]=0x00000002u;
goto P_0c096438;
P_0c096438: /* original 3823, guest PC 0x0c096438 */
if(!s->budget--) { s->failed_pc=0x0c096438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c09643a;
P_0c09643a: /* original 8ba3, guest PC 0x0c09643a */
if(!s->budget--) { s->failed_pc=0x0c09643au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096384; }
goto P_0c09643c;
P_0c09643c: /* original d12c, guest PC 0x0c09643c */
if(!s->budget--) { s->failed_pc=0x0c09643cu; return 0; }
r[1]=read(ram,0x0c0964f0u,4);
goto P_0c09643e;
P_0c09643e: /* original 410b, guest PC 0x0c09643e */
if(!s->budget--) { s->failed_pc=0x0c09643eu; return 0; }
target=r[1];
r[16]=0x0c096442u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096442u) { target=s->pc; goto dispatch; }
goto P_0c096442;
P_0c096440: /* original 0009, guest PC 0x0c096440 */
if(!s->budget--) { s->failed_pc=0x0c096440u; return 0; }
goto P_0c096442;
P_0c096442: /* original 8806, guest PC 0x0c096442 */
if(!s->budget--) { s->failed_pc=0x0c096442u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c096444;
P_0c096444: /* original 8f03, guest PC 0x0c096444 */
if(!s->budget--) { s->failed_pc=0x0c096444u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c09644e; }
goto P_0c096448;
P_0c096446: /* original 6403, guest PC 0x0c096446 */
if(!s->budget--) { s->failed_pc=0x0c096446u; return 0; }
r[4]=r[0];
goto P_0c096448;
P_0c096448: /* original e500, guest PC 0x0c096448 */
if(!s->budget--) { s->failed_pc=0x0c096448u; return 0; }
r[5]=0x00000000u;
goto P_0c09644a;
P_0c09644a: /* original b20b, guest PC 0x0c09644a */
if(!s->budget--) { s->failed_pc=0x0c09644au; return 0; }
target=0x0c096864u; r[16]=0x0c09644eu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09644eu) { target=s->pc; goto dispatch; }
goto P_0c09644e;
P_0c09644c: /* original 6453, guest PC 0x0c09644c */
if(!s->budget--) { s->failed_pc=0x0c09644cu; return 0; }
r[4]=r[5];
goto P_0c09644e;
P_0c09644e: /* original d429, guest PC 0x0c09644e */
if(!s->budget--) { s->failed_pc=0x0c09644eu; return 0; }
r[4]=read(ram,0x0c0964f4u,4);
goto P_0c096450;
P_0c096450: /* original d32b, guest PC 0x0c096450 */
if(!s->budget--) { s->failed_pc=0x0c096450u; return 0; }
r[3]=read(ram,0x0c096500u,4);
goto P_0c096452;
P_0c096452: /* original 6242, guest PC 0x0c096452 */
if(!s->budget--) { s->failed_pc=0x0c096452u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c096454;
P_0c096454: /* original db28, guest PC 0x0c096454 */
if(!s->budget--) { s->failed_pc=0x0c096454u; return 0; }
r[11]=read(ram,0x0c0964f8u,4);
goto P_0c096456;
P_0c096456: /* original d529, guest PC 0x0c096456 */
if(!s->budget--) { s->failed_pc=0x0c096456u; return 0; }
r[5]=read(ram,0x0c0964fcu,4);
goto P_0c096458;
P_0c096458: /* original 2238, guest PC 0x0c096458 */
if(!s->budget--) { s->failed_pc=0x0c096458u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09645a;
P_0c09645a: /* original 8b01, guest PC 0x0c09645a */
if(!s->budget--) { s->failed_pc=0x0c09645au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096460; }
goto P_0c09645c;
P_0c09645c: /* original a0d4, guest PC 0x0c09645c */
if(!s->budget--) { s->failed_pc=0x0c09645cu; return 0; }
goto P_0c096608;
P_0c09645e: /* original 0009, guest PC 0x0c09645e */
if(!s->budget--) { s->failed_pc=0x0c09645eu; return 0; }
goto P_0c096460;
P_0c096460: /* original 5141, guest PC 0x0c096460 */
if(!s->budget--) { s->failed_pc=0x0c096460u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c096462;
P_0c096462: /* original d228, guest PC 0x0c096462 */
if(!s->budget--) { s->failed_pc=0x0c096462u; return 0; }
r[2]=read(ram,0x0c096504u,4);
goto P_0c096464;
P_0c096464: /* original 2128, guest PC 0x0c096464 */
if(!s->budget--) { s->failed_pc=0x0c096464u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c096466;
P_0c096466: /* original 8b01, guest PC 0x0c096466 */
if(!s->budget--) { s->failed_pc=0x0c096466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09646c; }
goto P_0c096468;
P_0c096468: /* original a0c7, guest PC 0x0c096468 */
if(!s->budget--) { s->failed_pc=0x0c096468u; return 0; }
goto P_0c0965fa;
P_0c09646a: /* original 0009, guest PC 0x0c09646a */
if(!s->budget--) { s->failed_pc=0x0c09646au; return 0; }
goto P_0c09646c;
P_0c09646c: /* original e800, guest PC 0x0c09646c */
if(!s->budget--) { s->failed_pc=0x0c09646cu; return 0; }
r[8]=0x00000000u;
goto P_0c09646e;
P_0c09646e: /* original 6183, guest PC 0x0c09646e */
if(!s->budget--) { s->failed_pc=0x0c09646eu; return 0; }
r[1]=r[8];
goto P_0c096470;
P_0c096470: /* original 6913, guest PC 0x0c096470 */
if(!s->budget--) { s->failed_pc=0x0c096470u; return 0; }
r[9]=r[1];
goto P_0c096472;
P_0c096472: /* original 2f12, guest PC 0x0c096472 */
if(!s->budget--) { s->failed_pc=0x0c096472u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c096474;
P_0c096474: /* original 50b2, guest PC 0x0c096474 */
if(!s->budget--) { s->failed_pc=0x0c096474u; return 0; }
r[0]=read(ram,r[11]+8,4);
goto P_0c096476;
P_0c096476: /* original d124, guest PC 0x0c096476 */
if(!s->budget--) { s->failed_pc=0x0c096476u; return 0; }
r[1]=read(ram,0x0c096508u,4);
goto P_0c096478;
P_0c096478: /* original 2018, guest PC 0x0c096478 */
if(!s->budget--) { s->failed_pc=0x0c096478u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09647a;
P_0c09647a: /* original 8904, guest PC 0x0c09647a */
if(!s->budget--) { s->failed_pc=0x0c09647au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096486; }
goto P_0c09647c;
P_0c09647c: /* original e029, guest PC 0x0c09647c */
if(!s->budget--) { s->failed_pc=0x0c09647cu; return 0; }
r[0]=0x00000029u;
goto P_0c09647e;
P_0c09647e: /* original 00bc, guest PC 0x0c09647e */
if(!s->budget--) { s->failed_pc=0x0c09647eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c096480;
P_0c096480: /* original 600c, guest PC 0x0c096480 */
if(!s->budget--) { s->failed_pc=0x0c096480u; return 0; }
r[0]=r[0]&255u;
goto P_0c096482;
P_0c096482: /* original 8802, guest PC 0x0c096482 */
if(!s->budget--) { s->failed_pc=0x0c096482u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c096484;
P_0c096484: /* original 8903, guest PC 0x0c096484 */
if(!s->budget--) { s->failed_pc=0x0c096484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09648e; }
goto P_0c096486;
P_0c096486: /* original 4c0b, guest PC 0x0c096486 */
if(!s->budget--) { s->failed_pc=0x0c096486u; return 0; }
target=r[12];
r[16]=0x0c09648au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09648au) { target=s->pc; goto dispatch; }
goto P_0c09648a;
P_0c096488: /* original e400, guest PC 0x0c096488 */
if(!s->budget--) { s->failed_pc=0x0c096488u; return 0; }
r[4]=0x00000000u;
goto P_0c09648a;
P_0c09648a: /* original 6403, guest PC 0x0c09648a */
if(!s->budget--) { s->failed_pc=0x0c09648au; return 0; }
r[4]=r[0];
goto P_0c09648c;
P_0c09648c: /* original 5842, guest PC 0x0c09648c */
if(!s->budget--) { s->failed_pc=0x0c09648cu; return 0; }
r[8]=read(ram,r[4]+8,4);
goto P_0c09648e;
P_0c09648e: /* original 52b2, guest PC 0x0c09648e */
if(!s->budget--) { s->failed_pc=0x0c09648eu; return 0; }
r[2]=read(ram,r[11]+8,4);
goto P_0c096490;
P_0c096490: /* original d31d, guest PC 0x0c096490 */
if(!s->budget--) { s->failed_pc=0x0c096490u; return 0; }
r[3]=read(ram,0x0c096508u,4);
goto P_0c096492;
P_0c096492: /* original 2238, guest PC 0x0c096492 */
if(!s->budget--) { s->failed_pc=0x0c096492u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096494;
P_0c096494: /* original 8904, guest PC 0x0c096494 */
if(!s->budget--) { s->failed_pc=0x0c096494u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964a0; }
goto P_0c096496;
P_0c096496: /* original e029, guest PC 0x0c096496 */
if(!s->budget--) { s->failed_pc=0x0c096496u; return 0; }
r[0]=0x00000029u;
goto P_0c096498;
P_0c096498: /* original 00bc, guest PC 0x0c096498 */
if(!s->budget--) { s->failed_pc=0x0c096498u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c09649a;
P_0c09649a: /* original 600c, guest PC 0x0c09649a */
if(!s->budget--) { s->failed_pc=0x0c09649au; return 0; }
r[0]=r[0]&255u;
goto P_0c09649c;
P_0c09649c: /* original 8801, guest PC 0x0c09649c */
if(!s->budget--) { s->failed_pc=0x0c09649cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09649e;
P_0c09649e: /* original 8904, guest PC 0x0c09649e */
if(!s->budget--) { s->failed_pc=0x0c09649eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964aa; }
goto P_0c0964a0;
P_0c0964a0: /* original 4c0b, guest PC 0x0c0964a0 */
if(!s->budget--) { s->failed_pc=0x0c0964a0u; return 0; }
target=r[12];
r[16]=0x0c0964a4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0964a4u) { target=s->pc; goto dispatch; }
goto P_0c0964a4;
P_0c0964a2: /* original e401, guest PC 0x0c0964a2 */
if(!s->budget--) { s->failed_pc=0x0c0964a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0964a4;
P_0c0964a4: /* original 6403, guest PC 0x0c0964a4 */
if(!s->budget--) { s->failed_pc=0x0c0964a4u; return 0; }
r[4]=r[0];
goto P_0c0964a6;
P_0c0964a6: /* original 5342, guest PC 0x0c0964a6 */
if(!s->budget--) { s->failed_pc=0x0c0964a6u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0964a8;
P_0c0964a8: /* original 2f32, guest PC 0x0c0964a8 */
if(!s->budget--) { s->failed_pc=0x0c0964a8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0964aa;
P_0c0964aa: /* original e029, guest PC 0x0c0964aa */
if(!s->budget--) { s->failed_pc=0x0c0964aau; return 0; }
r[0]=0x00000029u;
goto P_0c0964ac;
P_0c0964ac: /* original 00bc, guest PC 0x0c0964ac */
if(!s->budget--) { s->failed_pc=0x0c0964acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0964ae;
P_0c0964ae: /* original 600c, guest PC 0x0c0964ae */
if(!s->budget--) { s->failed_pc=0x0c0964aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0964b0;
P_0c0964b0: /* original 8801, guest PC 0x0c0964b0 */
if(!s->budget--) { s->failed_pc=0x0c0964b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0964b2;
P_0c0964b2: /* original 8b2b, guest PC 0x0c0964b2 */
if(!s->budget--) { s->failed_pc=0x0c0964b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09650c; }
goto P_0c0964b4;
P_0c0964b4: /* original 4c0b, guest PC 0x0c0964b4 */
if(!s->budget--) { s->failed_pc=0x0c0964b4u; return 0; }
target=r[12];
r[16]=0x0c0964b8u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0964b8u) { target=s->pc; goto dispatch; }
goto P_0c0964b8;
P_0c0964b6: /* original e400, guest PC 0x0c0964b6 */
if(!s->budget--) { s->failed_pc=0x0c0964b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0964b8;
P_0c0964b8: /* original 6403, guest PC 0x0c0964b8 */
if(!s->budget--) { s->failed_pc=0x0c0964b8u; return 0; }
r[4]=r[0];
goto P_0c0964ba;
P_0c0964ba: /* original 6042, guest PC 0x0c0964ba */
if(!s->budget--) { s->failed_pc=0x0c0964bau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0964bc;
P_0c0964bc: /* original 88fe, guest PC 0x0c0964bc */
if(!s->budget--) { s->failed_pc=0x0c0964bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c0964be;
P_0c0964be: /* original 892d, guest PC 0x0c0964be */
if(!s->budget--) { s->failed_pc=0x0c0964beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09651c; }
goto P_0c0964c0;
P_0c0964c0: /* original a03d, guest PC 0x0c0964c0 */
if(!s->budget--) { s->failed_pc=0x0c0964c0u; return 0; }
goto P_0c09653e;
P_0c0964c2: /* original 0009, guest PC 0x0c0964c2 */
if(!s->budget--) { s->failed_pc=0x0c0964c2u; return 0; }
return vf3_matrix_family(0x0c0964c4u,s,ram);
P_0c09650c: /* original 8802, guest PC 0x0c09650c */
if(!s->budget--) { s->failed_pc=0x0c09650cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09650e;
P_0c09650e: /* original 8b07, guest PC 0x0c09650e */
if(!s->budget--) { s->failed_pc=0x0c09650eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096520; }
goto P_0c096510;
P_0c096510: /* original 4c0b, guest PC 0x0c096510 */
if(!s->budget--) { s->failed_pc=0x0c096510u; return 0; }
target=r[12];
r[16]=0x0c096514u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096514u) { target=s->pc; goto dispatch; }
goto P_0c096514;
P_0c096512: /* original e401, guest PC 0x0c096512 */
if(!s->budget--) { s->failed_pc=0x0c096512u; return 0; }
r[4]=0x00000001u;
goto P_0c096514;
P_0c096514: /* original 6403, guest PC 0x0c096514 */
if(!s->budget--) { s->failed_pc=0x0c096514u; return 0; }
r[4]=r[0];
goto P_0c096516;
P_0c096516: /* original 6042, guest PC 0x0c096516 */
if(!s->budget--) { s->failed_pc=0x0c096516u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096518;
P_0c096518: /* original 88fe, guest PC 0x0c096518 */
if(!s->budget--) { s->failed_pc=0x0c096518u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09651a;
P_0c09651a: /* original 8b10, guest PC 0x0c09651a */
if(!s->budget--) { s->failed_pc=0x0c09651au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09651c;
P_0c09651c: /* original a00f, guest PC 0x0c09651c */
if(!s->budget--) { s->failed_pc=0x0c09651cu; return 0; }
r[9]=r[13];
goto P_0c09653e;
P_0c09651e: /* original 69d3, guest PC 0x0c09651e */
if(!s->budget--) { s->failed_pc=0x0c09651eu; return 0; }
r[9]=r[13];
goto P_0c096520;
P_0c096520: /* original 4c0b, guest PC 0x0c096520 */
if(!s->budget--) { s->failed_pc=0x0c096520u; return 0; }
target=r[12];
r[16]=0x0c096524u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096524u) { target=s->pc; goto dispatch; }
goto P_0c096524;
P_0c096522: /* original e400, guest PC 0x0c096522 */
if(!s->budget--) { s->failed_pc=0x0c096522u; return 0; }
r[4]=0x00000000u;
goto P_0c096524;
P_0c096524: /* original 6403, guest PC 0x0c096524 */
if(!s->budget--) { s->failed_pc=0x0c096524u; return 0; }
r[4]=r[0];
goto P_0c096526;
P_0c096526: /* original 6042, guest PC 0x0c096526 */
if(!s->budget--) { s->failed_pc=0x0c096526u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096528;
P_0c096528: /* original 88fe, guest PC 0x0c096528 */
if(!s->budget--) { s->failed_pc=0x0c096528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09652a;
P_0c09652a: /* original 8f01, guest PC 0x0c09652a */
if(!s->budget--) { s->failed_pc=0x0c09652au; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(!cond) { goto P_0c096530; }
goto P_0c09652e;
P_0c09652c: /* original e401, guest PC 0x0c09652c */
if(!s->budget--) { s->failed_pc=0x0c09652cu; return 0; }
r[4]=0x00000001u;
goto P_0c09652e;
P_0c09652e: /* original 69d3, guest PC 0x0c09652e */
if(!s->budget--) { s->failed_pc=0x0c09652eu; return 0; }
r[9]=r[13];
goto P_0c096530;
P_0c096530: /* original 4c0b, guest PC 0x0c096530 */
if(!s->budget--) { s->failed_pc=0x0c096530u; return 0; }
target=r[12];
r[16]=0x0c096534u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096534u) { target=s->pc; goto dispatch; }
goto P_0c096534;
P_0c096532: /* original 0009, guest PC 0x0c096532 */
if(!s->budget--) { s->failed_pc=0x0c096532u; return 0; }
goto P_0c096534;
P_0c096534: /* original 6403, guest PC 0x0c096534 */
if(!s->budget--) { s->failed_pc=0x0c096534u; return 0; }
r[4]=r[0];
goto P_0c096536;
P_0c096536: /* original 6042, guest PC 0x0c096536 */
if(!s->budget--) { s->failed_pc=0x0c096536u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096538;
P_0c096538: /* original 88fe, guest PC 0x0c096538 */
if(!s->budget--) { s->failed_pc=0x0c096538u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09653a;
P_0c09653a: /* original 8b00, guest PC 0x0c09653a */
if(!s->budget--) { s->failed_pc=0x0c09653au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09653c;
P_0c09653c: /* original 29db, guest PC 0x0c09653c */
if(!s->budget--) { s->failed_pc=0x0c09653cu; return 0; }
r[9]|=r[13];
goto P_0c09653e;
P_0c09653e: /* original 64e2, guest PC 0x0c09653e */
if(!s->budget--) { s->failed_pc=0x0c09653eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c096540;
P_0c096540: /* original 2998, guest PC 0x0c096540 */
if(!s->budget--) { s->failed_pc=0x0c096540u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c096542;
P_0c096542: /* original d523, guest PC 0x0c096542 */
if(!s->budget--) { s->failed_pc=0x0c096542u; return 0; }
r[5]=read(ram,0x0c0965d0u,4);
goto P_0c096544;
P_0c096544: /* original 8d06, guest PC 0x0c096544 */
if(!s->budget--) { s->failed_pc=0x0c096544u; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(cond) { goto P_0c096554; }
goto P_0c096548;
P_0c096546: /* original 2459, guest PC 0x0c096546 */
if(!s->budget--) { s->failed_pc=0x0c096546u; return 0; }
r[4]&=r[5];
goto P_0c096548;
P_0c096548: /* original 2448, guest PC 0x0c096548 */
if(!s->budget--) { s->failed_pc=0x0c096548u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09654a;
P_0c09654a: /* original 8b6a, guest PC 0x0c09654a */
if(!s->budget--) { s->failed_pc=0x0c09654au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096622; }
goto P_0c09654c;
P_0c09654c: /* original 63e2, guest PC 0x0c09654c */
if(!s->budget--) { s->failed_pc=0x0c09654cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c09654e;
P_0c09654e: /* original 235b, guest PC 0x0c09654e */
if(!s->budget--) { s->failed_pc=0x0c09654eu; return 0; }
r[3]|=r[5];
goto P_0c096550;
P_0c096550: /* original a037, guest PC 0x0c096550 */
if(!s->budget--) { s->failed_pc=0x0c096550u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0965c2;
P_0c096552: /* original 2e32, guest PC 0x0c096552 */
if(!s->budget--) { s->failed_pc=0x0c096552u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c096554;
P_0c096554: /* original 2448, guest PC 0x0c096554 */
if(!s->budget--) { s->failed_pc=0x0c096554u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096556;
P_0c096556: /* original 8904, guest PC 0x0c096556 */
if(!s->budget--) { s->failed_pc=0x0c096556u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096562; }
goto P_0c096558;
P_0c096558: /* original 62e2, guest PC 0x0c096558 */
if(!s->budget--) { s->failed_pc=0x0c096558u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09655a;
P_0c09655a: /* original d31e, guest PC 0x0c09655a */
if(!s->budget--) { s->failed_pc=0x0c09655au; return 0; }
r[3]=read(ram,0x0c0965d4u,4);
goto P_0c09655c;
P_0c09655c: /* original 2239, guest PC 0x0c09655c */
if(!s->budget--) { s->failed_pc=0x0c09655cu; return 0; }
r[2]&=r[3];
goto P_0c09655e;
P_0c09655e: /* original a030, guest PC 0x0c09655e */
if(!s->budget--) { s->failed_pc=0x0c09655eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c096560: /* original 2e22, guest PC 0x0c096560 */
if(!s->budget--) { s->failed_pc=0x0c096560u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096562;
P_0c096562: /* original 60f2, guest PC 0x0c096562 */
if(!s->budget--) { s->failed_pc=0x0c096562u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c096564;
P_0c096564: /* original 208b, guest PC 0x0c096564 */
if(!s->budget--) { s->failed_pc=0x0c096564u; return 0; }
r[0]|=r[8];
goto P_0c096566;
P_0c096566: /* original 20a8, guest PC 0x0c096566 */
if(!s->budget--) { s->failed_pc=0x0c096566u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[10])==0)!=0);
goto P_0c096568;
P_0c096568: /* original 895b, guest PC 0x0c096568 */
if(!s->budget--) { s->failed_pc=0x0c096568u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09656a;
P_0c09656a: /* original 62e2, guest PC 0x0c09656a */
if(!s->budget--) { s->failed_pc=0x0c09656au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09656c;
P_0c09656c: /* original 6483, guest PC 0x0c09656c */
if(!s->budget--) { s->failed_pc=0x0c09656cu; return 0; }
r[4]=r[8];
goto P_0c09656e;
P_0c09656e: /* original 22d8, guest PC 0x0c09656e */
if(!s->budget--) { s->failed_pc=0x0c09656eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c096570;
P_0c096570: /* original 8d19, guest PC 0x0c096570 */
if(!s->budget--) { s->failed_pc=0x0c096570u; return 0; }
cond=r[17]&1u;
r[4]&=r[10];
if(cond) { goto P_0c0965a6; }
goto P_0c096574;
P_0c096572: /* original 24a9, guest PC 0x0c096572 */
if(!s->budget--) { s->failed_pc=0x0c096572u; return 0; }
r[4]&=r[10];
goto P_0c096574;
P_0c096574: /* original 2448, guest PC 0x0c096574 */
if(!s->budget--) { s->failed_pc=0x0c096574u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096576;
P_0c096576: /* original 8909, guest PC 0x0c096576 */
if(!s->budget--) { s->failed_pc=0x0c096576u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096578;
P_0c096578: /* original d018, guest PC 0x0c096578 */
if(!s->budget--) { s->failed_pc=0x0c096578u; return 0; }
r[0]=read(ram,0x0c0965dcu,4);
goto P_0c09657a;
P_0c09657a: /* original d317, guest PC 0x0c09657a */
if(!s->budget--) { s->failed_pc=0x0c09657au; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c09657c;
P_0c09657c: /* original 6102, guest PC 0x0c09657c */
if(!s->budget--) { s->failed_pc=0x0c09657cu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c09657e;
P_0c09657e: /* original 2138, guest PC 0x0c09657e */
if(!s->budget--) { s->failed_pc=0x0c09657eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c096580;
P_0c096580: /* original 8904, guest PC 0x0c096580 */
if(!s->budget--) { s->failed_pc=0x0c096580u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096582;
P_0c096582: /* original 62e2, guest PC 0x0c096582 */
if(!s->budget--) { s->failed_pc=0x0c096582u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c096584;
P_0c096584: /* original d316, guest PC 0x0c096584 */
if(!s->budget--) { s->failed_pc=0x0c096584u; return 0; }
r[3]=read(ram,0x0c0965e0u,4);
goto P_0c096586;
P_0c096586: /* original 223a, guest PC 0x0c096586 */
if(!s->budget--) { s->failed_pc=0x0c096586u; return 0; }
r[2]^=r[3];
goto P_0c096588;
P_0c096588: /* original a01b, guest PC 0x0c096588 */
if(!s->budget--) { s->failed_pc=0x0c096588u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c09658a: /* original 2e22, guest PC 0x0c09658a */
if(!s->budget--) { s->failed_pc=0x0c09658au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c09658c;
P_0c09658c: /* original 61f2, guest PC 0x0c09658c */
if(!s->budget--) { s->failed_pc=0x0c09658cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09658e;
P_0c09658e: /* original 21a8, guest PC 0x0c09658e */
if(!s->budget--) { s->failed_pc=0x0c09658eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c096590;
P_0c096590: /* original 8947, guest PC 0x0c096590 */
if(!s->budget--) { s->failed_pc=0x0c096590u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096592;
P_0c096592: /* original d112, guest PC 0x0c096592 */
if(!s->budget--) { s->failed_pc=0x0c096592u; return 0; }
r[1]=read(ram,0x0c0965dcu,4);
goto P_0c096594;
P_0c096594: /* original d313, guest PC 0x0c096594 */
if(!s->budget--) { s->failed_pc=0x0c096594u; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c096596;
P_0c096596: /* original 6212, guest PC 0x0c096596 */
if(!s->budget--) { s->failed_pc=0x0c096596u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c096598;
P_0c096598: /* original 2238, guest PC 0x0c096598 */
if(!s->budget--) { s->failed_pc=0x0c096598u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09659a;
P_0c09659a: /* original 8942, guest PC 0x0c09659a */
if(!s->budget--) { s->failed_pc=0x0c09659au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09659c;
P_0c09659c: /* original 60e2, guest PC 0x0c09659c */
if(!s->budget--) { s->failed_pc=0x0c09659cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09659e;
P_0c09659e: /* original d312, guest PC 0x0c09659e */
if(!s->budget--) { s->failed_pc=0x0c09659eu; return 0; }
r[3]=read(ram,0x0c0965e8u,4);
goto P_0c0965a0;
P_0c0965a0: /* original 203a, guest PC 0x0c0965a0 */
if(!s->budget--) { s->failed_pc=0x0c0965a0u; return 0; }
r[0]^=r[3];
goto P_0c0965a2;
P_0c0965a2: /* original a00e, guest PC 0x0c0965a2 */
if(!s->budget--) { s->failed_pc=0x0c0965a2u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965c2;
P_0c0965a4: /* original 2e02, guest PC 0x0c0965a4 */
if(!s->budget--) { s->failed_pc=0x0c0965a4u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965a6;
P_0c0965a6: /* original 61e2, guest PC 0x0c0965a6 */
if(!s->budget--) { s->failed_pc=0x0c0965a6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965a8;
P_0c0965a8: /* original 2448, guest PC 0x0c0965a8 */
if(!s->budget--) { s->failed_pc=0x0c0965a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0965aa;
P_0c0965aa: /* original 21da, guest PC 0x0c0965aa */
if(!s->budget--) { s->failed_pc=0x0c0965aau; return 0; }
r[1]^=r[13];
goto P_0c0965ac;
P_0c0965ac: /* original 8d05, guest PC 0x0c0965ac */
if(!s->budget--) { s->failed_pc=0x0c0965acu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[1],4);
if(cond) { goto P_0c0965ba; }
goto P_0c0965b0;
P_0c0965ae: /* original 2e12, guest PC 0x0c0965ae */
if(!s->budget--) { s->failed_pc=0x0c0965aeu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965b0;
P_0c0965b0: /* original 62e2, guest PC 0x0c0965b0 */
if(!s->budget--) { s->failed_pc=0x0c0965b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965b2;
P_0c0965b2: /* original d309, guest PC 0x0c0965b2 */
if(!s->budget--) { s->failed_pc=0x0c0965b2u; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c0965b4;
P_0c0965b4: /* original 223b, guest PC 0x0c0965b4 */
if(!s->budget--) { s->failed_pc=0x0c0965b4u; return 0; }
r[2]|=r[3];
goto P_0c0965b6;
P_0c0965b6: /* original a004, guest PC 0x0c0965b6 */
if(!s->budget--) { s->failed_pc=0x0c0965b6u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c0965b8: /* original 2e22, guest PC 0x0c0965b8 */
if(!s->budget--) { s->failed_pc=0x0c0965b8u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965ba;
P_0c0965ba: /* original 61e2, guest PC 0x0c0965ba */
if(!s->budget--) { s->failed_pc=0x0c0965bau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965bc;
P_0c0965bc: /* original d309, guest PC 0x0c0965bc */
if(!s->budget--) { s->failed_pc=0x0c0965bcu; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c0965be;
P_0c0965be: /* original 213b, guest PC 0x0c0965be */
if(!s->budget--) { s->failed_pc=0x0c0965beu; return 0; }
r[1]|=r[3];
goto P_0c0965c0;
P_0c0965c0: /* original 2e12, guest PC 0x0c0965c0 */
if(!s->budget--) { s->failed_pc=0x0c0965c0u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965c2;
P_0c0965c2: /* original 62e2, guest PC 0x0c0965c2 */
if(!s->budget--) { s->failed_pc=0x0c0965c2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965c4;
P_0c0965c4: /* original 22d8, guest PC 0x0c0965c4 */
if(!s->budget--) { s->failed_pc=0x0c0965c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0965c6;
P_0c0965c6: /* original 8911, guest PC 0x0c0965c6 */
if(!s->budget--) { s->failed_pc=0x0c0965c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0965ec; }
goto P_0c0965c8;
P_0c0965c8: /* original 9401, guest PC 0x0c0965c8 */
if(!s->budget--) { s->failed_pc=0x0c0965c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0965ceu,2);
goto P_0c0965ca;
P_0c0965ca: /* original a011, guest PC 0x0c0965ca */
if(!s->budget--) { s->failed_pc=0x0c0965cau; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965cc: /* original e500, guest PC 0x0c0965cc */
if(!s->budget--) { s->failed_pc=0x0c0965ccu; return 0; }
r[5]=0x00000000u;
return vf3_matrix_family(0x0c0965ceu,s,ram);
P_0c0965ec: /* original 947c, guest PC 0x0c0965ec */
if(!s->budget--) { s->failed_pc=0x0c0965ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966e8u,2);
goto P_0c0965ee;
P_0c0965ee: /* original e500, guest PC 0x0c0965ee */
if(!s->budget--) { s->failed_pc=0x0c0965eeu; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965f0: /* original d23f, guest PC 0x0c0965f0 */
if(!s->budget--) { s->failed_pc=0x0c0965f0u; return 0; }
r[2]=read(ram,0x0c0966f0u,4);
goto P_0c0965f2;
P_0c0965f2: /* original 420b, guest PC 0x0c0965f2 */
if(!s->budget--) { s->failed_pc=0x0c0965f2u; return 0; }
target=r[2];
r[16]=0x0c0965f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0965f6u) { target=s->pc; goto dispatch; }
goto P_0c0965f6;
P_0c0965f4: /* original 0009, guest PC 0x0c0965f4 */
if(!s->budget--) { s->failed_pc=0x0c0965f4u; return 0; }
goto P_0c0965f6;
P_0c0965f6: /* original a014, guest PC 0x0c0965f6 */
if(!s->budget--) { s->failed_pc=0x0c0965f6u; return 0; }
goto P_0c096622;
P_0c0965f8: /* original 0009, guest PC 0x0c0965f8 */
if(!s->budget--) { s->failed_pc=0x0c0965f8u; return 0; }
goto P_0c0965fa;
P_0c0965fa: /* original 2518, guest PC 0x0c0965fa */
if(!s->budget--) { s->failed_pc=0x0c0965fau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0965fc;
P_0c0965fc: /* original 8911, guest PC 0x0c0965fc */
if(!s->budget--) { s->failed_pc=0x0c0965fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c0965fe;
P_0c0965fe: /* original 61e2, guest PC 0x0c0965fe */
if(!s->budget--) { s->failed_pc=0x0c0965feu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c096600;
P_0c096600: /* original 21d8, guest PC 0x0c096600 */
if(!s->budget--) { s->failed_pc=0x0c096600u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c096602;
P_0c096602: /* original 8b06, guest PC 0x0c096602 */
if(!s->budget--) { s->failed_pc=0x0c096602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096612; }
goto P_0c096604;
P_0c096604: /* original a00d, guest PC 0x0c096604 */
if(!s->budget--) { s->failed_pc=0x0c096604u; return 0; }
goto P_0c096622;
P_0c096606: /* original 0009, guest PC 0x0c096606 */
if(!s->budget--) { s->failed_pc=0x0c096606u; return 0; }
goto P_0c096608;
P_0c096608: /* original 2528, guest PC 0x0c096608 */
if(!s->budget--) { s->failed_pc=0x0c096608u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09660a;
P_0c09660a: /* original 890a, guest PC 0x0c09660a */
if(!s->budget--) { s->failed_pc=0x0c09660au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09660c;
P_0c09660c: /* original 60e2, guest PC 0x0c09660c */
if(!s->budget--) { s->failed_pc=0x0c09660cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09660e;
P_0c09660e: /* original 20d8, guest PC 0x0c09660e */
if(!s->budget--) { s->failed_pc=0x0c09660eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c096610;
P_0c096610: /* original 8907, guest PC 0x0c096610 */
if(!s->budget--) { s->failed_pc=0x0c096610u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096612;
P_0c096612: /* original d337, guest PC 0x0c096612 */
if(!s->budget--) { s->failed_pc=0x0c096612u; return 0; }
r[3]=read(ram,0x0c0966f0u,4);
goto P_0c096614;
P_0c096614: /* original 9469, guest PC 0x0c096614 */
if(!s->budget--) { s->failed_pc=0x0c096614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966eau,2);
goto P_0c096616;
P_0c096616: /* original 430b, guest PC 0x0c096616 */
if(!s->budget--) { s->failed_pc=0x0c096616u; return 0; }
target=r[3];
r[16]=0x0c09661au;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09661au) { target=s->pc; goto dispatch; }
goto P_0c09661a;
P_0c096618: /* original e500, guest PC 0x0c096618 */
if(!s->budget--) { s->failed_pc=0x0c096618u; return 0; }
r[5]=0x00000000u;
goto P_0c09661a;
P_0c09661a: /* original 62e2, guest PC 0x0c09661a */
if(!s->budget--) { s->failed_pc=0x0c09661au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09661c;
P_0c09661c: /* original e3fe, guest PC 0x0c09661c */
if(!s->budget--) { s->failed_pc=0x0c09661cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c09661e;
P_0c09661e: /* original 2239, guest PC 0x0c09661e */
if(!s->budget--) { s->failed_pc=0x0c09661eu; return 0; }
r[2]&=r[3];
goto P_0c096620;
P_0c096620: /* original 2e22, guest PC 0x0c096620 */
if(!s->budget--) { s->failed_pc=0x0c096620u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096622;
P_0c096622: /* original 4c0b, guest PC 0x0c096622 */
if(!s->budget--) { s->failed_pc=0x0c096622u; return 0; }
target=r[12];
r[16]=0x0c096626u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096626u) { target=s->pc; goto dispatch; }
goto P_0c096626;
P_0c096624: /* original e401, guest PC 0x0c096624 */
if(!s->budget--) { s->failed_pc=0x0c096624u; return 0; }
r[4]=0x00000001u;
goto P_0c096626;
P_0c096626: /* original 6403, guest PC 0x0c096626 */
if(!s->budget--) { s->failed_pc=0x0c096626u; return 0; }
r[4]=r[0];
goto P_0c096628;
P_0c096628: /* original 5242, guest PC 0x0c096628 */
if(!s->budget--) { s->failed_pc=0x0c096628u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09662a;
P_0c09662a: /* original d332, guest PC 0x0c09662a */
if(!s->budget--) { s->failed_pc=0x0c09662au; return 0; }
r[3]=read(ram,0x0c0966f4u,4);
goto P_0c09662c;
P_0c09662c: /* original 2238, guest PC 0x0c09662c */
if(!s->budget--) { s->failed_pc=0x0c09662cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09662e;
P_0c09662e: /* original 8b03, guest PC 0x0c09662e */
if(!s->budget--) { s->failed_pc=0x0c09662eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096638; }
goto P_0c096630;
P_0c096630: /* original 5242, guest PC 0x0c096630 */
if(!s->budget--) { s->failed_pc=0x0c096630u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096632;
P_0c096632: /* original 955b, guest PC 0x0c096632 */
if(!s->budget--) { s->failed_pc=0x0c096632u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966ecu,2);
goto P_0c096634;
P_0c096634: /* original 2259, guest PC 0x0c096634 */
if(!s->budget--) { s->failed_pc=0x0c096634u; return 0; }
r[2]&=r[5];
goto P_0c096636;
P_0c096636: /* original 3250, guest PC 0x0c096636 */
if(!s->budget--) { s->failed_pc=0x0c096636u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[5])!=0);
goto P_0c096638;
P_0c096638: /* original 7f04, guest PC 0x0c096638 */
if(!s->budget--) { s->failed_pc=0x0c096638u; return 0; }
r[15]+=0x00000004u;
goto P_0c09663a;
P_0c09663a: /* original 4f26, guest PC 0x0c09663a */
if(!s->budget--) { s->failed_pc=0x0c09663au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09663c;
P_0c09663c: /* original 68f6, guest PC 0x0c09663c */
if(!s->budget--) { s->failed_pc=0x0c09663cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09663e;
P_0c09663e: /* original 69f6, guest PC 0x0c09663e */
if(!s->budget--) { s->failed_pc=0x0c09663eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096640;
P_0c096640: /* original 6af6, guest PC 0x0c096640 */
if(!s->budget--) { s->failed_pc=0x0c096640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096642;
P_0c096642: /* original 6bf6, guest PC 0x0c096642 */
if(!s->budget--) { s->failed_pc=0x0c096642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096644;
P_0c096644: /* original 6cf6, guest PC 0x0c096644 */
if(!s->budget--) { s->failed_pc=0x0c096644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096646;
P_0c096646: /* original 6df6, guest PC 0x0c096646 */
if(!s->budget--) { s->failed_pc=0x0c096646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096648;
P_0c096648: /* original 000b, guest PC 0x0c096648 */
if(!s->budget--) { s->failed_pc=0x0c096648u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09664a: /* original 6ef6, guest PC 0x0c09664a */
if(!s->budget--) { s->failed_pc=0x0c09664au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09664cu,s,ram);
P_0c0a2e2c: /* original d34f, guest PC 0x0c0a2e2c */
if(!s->budget--) { s->failed_pc=0x0c0a2e2cu; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e2e;
P_0c0a2e2e: /* original 6543, guest PC 0x0c0a2e2e */
if(!s->budget--) { s->failed_pc=0x0c0a2e2eu; return 0; }
r[5]=r[4];
goto P_0c0a2e30;
P_0c0a2e30: /* original 4508, guest PC 0x0c0a2e30 */
if(!s->budget--) { s->failed_pc=0x0c0a2e30u; return 0; }
r[5]<<=2;
goto P_0c0a2e32;
P_0c0a2e32: /* original 353c, guest PC 0x0c0a2e32 */
if(!s->budget--) { s->failed_pc=0x0c0a2e32u; return 0; }
r[5]+=r[3];
goto P_0c0a2e34;
P_0c0a2e34: /* original 6252, guest PC 0x0c0a2e34 */
if(!s->budget--) { s->failed_pc=0x0c0a2e34u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0a2e36;
P_0c0a2e36: /* original 2228, guest PC 0x0c0a2e36 */
if(!s->budget--) { s->failed_pc=0x0c0a2e36u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e38;
P_0c0a2e38: /* original 8904, guest PC 0x0c0a2e38 */
if(!s->budget--) { s->failed_pc=0x0c0a2e38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e44; }
goto P_0c0a2e3a;
P_0c0a2e3a: /* original 6052, guest PC 0x0c0a2e3a */
if(!s->budget--) { s->failed_pc=0x0c0a2e3au; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c0a2e3c;
P_0c0a2e3c: /* original 88ff, guest PC 0x0c0a2e3c */
if(!s->budget--) { s->failed_pc=0x0c0a2e3cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e3e;
P_0c0a2e3e: /* original 8901, guest PC 0x0c0a2e3e */
if(!s->budget--) { s->failed_pc=0x0c0a2e3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e44; }
goto P_0c0a2e40;
P_0c0a2e40: /* original e100, guest PC 0x0c0a2e40 */
if(!s->budget--) { s->failed_pc=0x0c0a2e40u; return 0; }
r[1]=0x00000000u;
goto P_0c0a2e42;
P_0c0a2e42: /* original 2512, guest PC 0x0c0a2e42 */
if(!s->budget--) { s->failed_pc=0x0c0a2e42u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0a2e44;
P_0c0a2e44: /* original 000b, guest PC 0x0c0a2e44 */
if(!s->budget--) { s->failed_pc=0x0c0a2e44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e46: /* original 0009, guest PC 0x0c0a2e46 */
if(!s->budget--) { s->failed_pc=0x0c0a2e46u; return 0; }
return vf3_matrix_family(0x0c0a2e48u,s,ram);
P_0c0a30b4: /* original 4f22, guest PC 0x0c0a30b4 */
if(!s->budget--) { s->failed_pc=0x0c0a30b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a30b6;
P_0c0a30b6: /* original 9488, guest PC 0x0c0a30b6 */
if(!s->budget--) { s->failed_pc=0x0c0a30b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31cau,2);
goto P_0c0a30b8;
P_0c0a30b8: /* original beb8, guest PC 0x0c0a30b8 */
if(!s->budget--) { s->failed_pc=0x0c0a30b8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30bcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30bcu) { target=s->pc; goto dispatch; }
goto P_0c0a30bc;
P_0c0a30ba: /* original 0009, guest PC 0x0c0a30ba */
if(!s->budget--) { s->failed_pc=0x0c0a30bau; return 0; }
goto P_0c0a30bc;
P_0c0a30bc: /* original 9486, guest PC 0x0c0a30bc */
if(!s->budget--) { s->failed_pc=0x0c0a30bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31ccu,2);
goto P_0c0a30be;
P_0c0a30be: /* original beb5, guest PC 0x0c0a30be */
if(!s->budget--) { s->failed_pc=0x0c0a30beu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30c2u) { target=s->pc; goto dispatch; }
goto P_0c0a30c2;
P_0c0a30c0: /* original 0009, guest PC 0x0c0a30c0 */
if(!s->budget--) { s->failed_pc=0x0c0a30c0u; return 0; }
goto P_0c0a30c2;
P_0c0a30c2: /* original 9484, guest PC 0x0c0a30c2 */
if(!s->budget--) { s->failed_pc=0x0c0a30c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31ceu,2);
goto P_0c0a30c4;
P_0c0a30c4: /* original beb2, guest PC 0x0c0a30c4 */
if(!s->budget--) { s->failed_pc=0x0c0a30c4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30c8u) { target=s->pc; goto dispatch; }
goto P_0c0a30c8;
P_0c0a30c6: /* original 0009, guest PC 0x0c0a30c6 */
if(!s->budget--) { s->failed_pc=0x0c0a30c6u; return 0; }
goto P_0c0a30c8;
P_0c0a30c8: /* original 9482, guest PC 0x0c0a30c8 */
if(!s->budget--) { s->failed_pc=0x0c0a30c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31d0u,2);
goto P_0c0a30ca;
P_0c0a30ca: /* original beaf, guest PC 0x0c0a30ca */
if(!s->budget--) { s->failed_pc=0x0c0a30cau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30ceu) { target=s->pc; goto dispatch; }
goto P_0c0a30ce;
P_0c0a30cc: /* original 0009, guest PC 0x0c0a30cc */
if(!s->budget--) { s->failed_pc=0x0c0a30ccu; return 0; }
goto P_0c0a30ce;
P_0c0a30ce: /* original 9480, guest PC 0x0c0a30ce */
if(!s->budget--) { s->failed_pc=0x0c0a30ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31d2u,2);
goto P_0c0a30d0;
P_0c0a30d0: /* original beac, guest PC 0x0c0a30d0 */
if(!s->budget--) { s->failed_pc=0x0c0a30d0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30d4u) { target=s->pc; goto dispatch; }
goto P_0c0a30d4;
P_0c0a30d2: /* original 0009, guest PC 0x0c0a30d2 */
if(!s->budget--) { s->failed_pc=0x0c0a30d2u; return 0; }
goto P_0c0a30d4;
P_0c0a30d4: /* original 947e, guest PC 0x0c0a30d4 */
if(!s->budget--) { s->failed_pc=0x0c0a30d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31d4u,2);
goto P_0c0a30d6;
P_0c0a30d6: /* original bea9, guest PC 0x0c0a30d6 */
if(!s->budget--) { s->failed_pc=0x0c0a30d6u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30dau) { target=s->pc; goto dispatch; }
goto P_0c0a30da;
P_0c0a30d8: /* original 0009, guest PC 0x0c0a30d8 */
if(!s->budget--) { s->failed_pc=0x0c0a30d8u; return 0; }
goto P_0c0a30da;
P_0c0a30da: /* original 947c, guest PC 0x0c0a30da */
if(!s->budget--) { s->failed_pc=0x0c0a30dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31d6u,2);
goto P_0c0a30dc;
P_0c0a30dc: /* original bea6, guest PC 0x0c0a30dc */
if(!s->budget--) { s->failed_pc=0x0c0a30dcu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30e0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30e0u) { target=s->pc; goto dispatch; }
goto P_0c0a30e0;
P_0c0a30de: /* original 0009, guest PC 0x0c0a30de */
if(!s->budget--) { s->failed_pc=0x0c0a30deu; return 0; }
goto P_0c0a30e0;
P_0c0a30e0: /* original 947a, guest PC 0x0c0a30e0 */
if(!s->budget--) { s->failed_pc=0x0c0a30e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31d8u,2);
goto P_0c0a30e2;
P_0c0a30e2: /* original bea3, guest PC 0x0c0a30e2 */
if(!s->budget--) { s->failed_pc=0x0c0a30e2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30e6u) { target=s->pc; goto dispatch; }
goto P_0c0a30e6;
P_0c0a30e4: /* original 0009, guest PC 0x0c0a30e4 */
if(!s->budget--) { s->failed_pc=0x0c0a30e4u; return 0; }
goto P_0c0a30e6;
P_0c0a30e6: /* original 9478, guest PC 0x0c0a30e6 */
if(!s->budget--) { s->failed_pc=0x0c0a30e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31dau,2);
goto P_0c0a30e8;
P_0c0a30e8: /* original bea0, guest PC 0x0c0a30e8 */
if(!s->budget--) { s->failed_pc=0x0c0a30e8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30ecu) { target=s->pc; goto dispatch; }
goto P_0c0a30ec;
P_0c0a30ea: /* original 0009, guest PC 0x0c0a30ea */
if(!s->budget--) { s->failed_pc=0x0c0a30eau; return 0; }
goto P_0c0a30ec;
P_0c0a30ec: /* original 9476, guest PC 0x0c0a30ec */
if(!s->budget--) { s->failed_pc=0x0c0a30ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31dcu,2);
goto P_0c0a30ee;
P_0c0a30ee: /* original be9d, guest PC 0x0c0a30ee */
if(!s->budget--) { s->failed_pc=0x0c0a30eeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30f2u) { target=s->pc; goto dispatch; }
goto P_0c0a30f2;
P_0c0a30f0: /* original 0009, guest PC 0x0c0a30f0 */
if(!s->budget--) { s->failed_pc=0x0c0a30f0u; return 0; }
goto P_0c0a30f2;
P_0c0a30f2: /* original 9474, guest PC 0x0c0a30f2 */
if(!s->budget--) { s->failed_pc=0x0c0a30f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31deu,2);
goto P_0c0a30f4;
P_0c0a30f4: /* original be9a, guest PC 0x0c0a30f4 */
if(!s->budget--) { s->failed_pc=0x0c0a30f4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30f8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30f8u) { target=s->pc; goto dispatch; }
goto P_0c0a30f8;
P_0c0a30f6: /* original 0009, guest PC 0x0c0a30f6 */
if(!s->budget--) { s->failed_pc=0x0c0a30f6u; return 0; }
goto P_0c0a30f8;
P_0c0a30f8: /* original 9472, guest PC 0x0c0a30f8 */
if(!s->budget--) { s->failed_pc=0x0c0a30f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31e0u,2);
goto P_0c0a30fa;
P_0c0a30fa: /* original be97, guest PC 0x0c0a30fa */
if(!s->budget--) { s->failed_pc=0x0c0a30fau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a30feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a30feu) { target=s->pc; goto dispatch; }
goto P_0c0a30fe;
P_0c0a30fc: /* original 0009, guest PC 0x0c0a30fc */
if(!s->budget--) { s->failed_pc=0x0c0a30fcu; return 0; }
goto P_0c0a30fe;
P_0c0a30fe: /* original 9470, guest PC 0x0c0a30fe */
if(!s->budget--) { s->failed_pc=0x0c0a30feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31e2u,2);
goto P_0c0a3100;
P_0c0a3100: /* original be94, guest PC 0x0c0a3100 */
if(!s->budget--) { s->failed_pc=0x0c0a3100u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3104u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3104u) { target=s->pc; goto dispatch; }
goto P_0c0a3104;
P_0c0a3102: /* original 0009, guest PC 0x0c0a3102 */
if(!s->budget--) { s->failed_pc=0x0c0a3102u; return 0; }
goto P_0c0a3104;
P_0c0a3104: /* original 946e, guest PC 0x0c0a3104 */
if(!s->budget--) { s->failed_pc=0x0c0a3104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31e4u,2);
goto P_0c0a3106;
P_0c0a3106: /* original be91, guest PC 0x0c0a3106 */
if(!s->budget--) { s->failed_pc=0x0c0a3106u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a310au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a310au) { target=s->pc; goto dispatch; }
goto P_0c0a310a;
P_0c0a3108: /* original 0009, guest PC 0x0c0a3108 */
if(!s->budget--) { s->failed_pc=0x0c0a3108u; return 0; }
goto P_0c0a310a;
P_0c0a310a: /* original 946c, guest PC 0x0c0a310a */
if(!s->budget--) { s->failed_pc=0x0c0a310au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31e6u,2);
goto P_0c0a310c;
P_0c0a310c: /* original be8e, guest PC 0x0c0a310c */
if(!s->budget--) { s->failed_pc=0x0c0a310cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3110u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3110u) { target=s->pc; goto dispatch; }
goto P_0c0a3110;
P_0c0a310e: /* original 0009, guest PC 0x0c0a310e */
if(!s->budget--) { s->failed_pc=0x0c0a310eu; return 0; }
goto P_0c0a3110;
P_0c0a3110: /* original 946a, guest PC 0x0c0a3110 */
if(!s->budget--) { s->failed_pc=0x0c0a3110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31e8u,2);
goto P_0c0a3112;
P_0c0a3112: /* original be8b, guest PC 0x0c0a3112 */
if(!s->budget--) { s->failed_pc=0x0c0a3112u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3116u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3116u) { target=s->pc; goto dispatch; }
goto P_0c0a3116;
P_0c0a3114: /* original 0009, guest PC 0x0c0a3114 */
if(!s->budget--) { s->failed_pc=0x0c0a3114u; return 0; }
goto P_0c0a3116;
P_0c0a3116: /* original 9468, guest PC 0x0c0a3116 */
if(!s->budget--) { s->failed_pc=0x0c0a3116u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31eau,2);
goto P_0c0a3118;
P_0c0a3118: /* original be88, guest PC 0x0c0a3118 */
if(!s->budget--) { s->failed_pc=0x0c0a3118u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a311cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a311cu) { target=s->pc; goto dispatch; }
goto P_0c0a311c;
P_0c0a311a: /* original 0009, guest PC 0x0c0a311a */
if(!s->budget--) { s->failed_pc=0x0c0a311au; return 0; }
goto P_0c0a311c;
P_0c0a311c: /* original 9466, guest PC 0x0c0a311c */
if(!s->budget--) { s->failed_pc=0x0c0a311cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31ecu,2);
goto P_0c0a311e;
P_0c0a311e: /* original be85, guest PC 0x0c0a311e */
if(!s->budget--) { s->failed_pc=0x0c0a311eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3122u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3122u) { target=s->pc; goto dispatch; }
goto P_0c0a3122;
P_0c0a3120: /* original 0009, guest PC 0x0c0a3120 */
if(!s->budget--) { s->failed_pc=0x0c0a3120u; return 0; }
goto P_0c0a3122;
P_0c0a3122: /* original 9464, guest PC 0x0c0a3122 */
if(!s->budget--) { s->failed_pc=0x0c0a3122u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31eeu,2);
goto P_0c0a3124;
P_0c0a3124: /* original be82, guest PC 0x0c0a3124 */
if(!s->budget--) { s->failed_pc=0x0c0a3124u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3128u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3128u) { target=s->pc; goto dispatch; }
goto P_0c0a3128;
P_0c0a3126: /* original 0009, guest PC 0x0c0a3126 */
if(!s->budget--) { s->failed_pc=0x0c0a3126u; return 0; }
goto P_0c0a3128;
P_0c0a3128: /* original 9462, guest PC 0x0c0a3128 */
if(!s->budget--) { s->failed_pc=0x0c0a3128u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31f0u,2);
goto P_0c0a312a;
P_0c0a312a: /* original be7f, guest PC 0x0c0a312a */
if(!s->budget--) { s->failed_pc=0x0c0a312au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a312eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a312eu) { target=s->pc; goto dispatch; }
goto P_0c0a312e;
P_0c0a312c: /* original 0009, guest PC 0x0c0a312c */
if(!s->budget--) { s->failed_pc=0x0c0a312cu; return 0; }
goto P_0c0a312e;
P_0c0a312e: /* original 9460, guest PC 0x0c0a312e */
if(!s->budget--) { s->failed_pc=0x0c0a312eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31f2u,2);
goto P_0c0a3130;
P_0c0a3130: /* original be7c, guest PC 0x0c0a3130 */
if(!s->budget--) { s->failed_pc=0x0c0a3130u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3134u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3134u) { target=s->pc; goto dispatch; }
goto P_0c0a3134;
P_0c0a3132: /* original 0009, guest PC 0x0c0a3132 */
if(!s->budget--) { s->failed_pc=0x0c0a3132u; return 0; }
goto P_0c0a3134;
P_0c0a3134: /* original 945e, guest PC 0x0c0a3134 */
if(!s->budget--) { s->failed_pc=0x0c0a3134u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31f4u,2);
goto P_0c0a3136;
P_0c0a3136: /* original be79, guest PC 0x0c0a3136 */
if(!s->budget--) { s->failed_pc=0x0c0a3136u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a313au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a313au) { target=s->pc; goto dispatch; }
goto P_0c0a313a;
P_0c0a3138: /* original 0009, guest PC 0x0c0a3138 */
if(!s->budget--) { s->failed_pc=0x0c0a3138u; return 0; }
goto P_0c0a313a;
P_0c0a313a: /* original 945c, guest PC 0x0c0a313a */
if(!s->budget--) { s->failed_pc=0x0c0a313au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31f6u,2);
goto P_0c0a313c;
P_0c0a313c: /* original be76, guest PC 0x0c0a313c */
if(!s->budget--) { s->failed_pc=0x0c0a313cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3140u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3140u) { target=s->pc; goto dispatch; }
goto P_0c0a3140;
P_0c0a313e: /* original 0009, guest PC 0x0c0a313e */
if(!s->budget--) { s->failed_pc=0x0c0a313eu; return 0; }
goto P_0c0a3140;
P_0c0a3140: /* original 945a, guest PC 0x0c0a3140 */
if(!s->budget--) { s->failed_pc=0x0c0a3140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31f8u,2);
goto P_0c0a3142;
P_0c0a3142: /* original be73, guest PC 0x0c0a3142 */
if(!s->budget--) { s->failed_pc=0x0c0a3142u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3146u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3146u) { target=s->pc; goto dispatch; }
goto P_0c0a3146;
P_0c0a3144: /* original 0009, guest PC 0x0c0a3144 */
if(!s->budget--) { s->failed_pc=0x0c0a3144u; return 0; }
goto P_0c0a3146;
P_0c0a3146: /* original 9458, guest PC 0x0c0a3146 */
if(!s->budget--) { s->failed_pc=0x0c0a3146u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31fau,2);
goto P_0c0a3148;
P_0c0a3148: /* original be70, guest PC 0x0c0a3148 */
if(!s->budget--) { s->failed_pc=0x0c0a3148u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a314cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a314cu) { target=s->pc; goto dispatch; }
goto P_0c0a314c;
P_0c0a314a: /* original 0009, guest PC 0x0c0a314a */
if(!s->budget--) { s->failed_pc=0x0c0a314au; return 0; }
goto P_0c0a314c;
P_0c0a314c: /* original 9456, guest PC 0x0c0a314c */
if(!s->budget--) { s->failed_pc=0x0c0a314cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31fcu,2);
goto P_0c0a314e;
P_0c0a314e: /* original be6d, guest PC 0x0c0a314e */
if(!s->budget--) { s->failed_pc=0x0c0a314eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3152u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3152u) { target=s->pc; goto dispatch; }
goto P_0c0a3152;
P_0c0a3150: /* original 0009, guest PC 0x0c0a3150 */
if(!s->budget--) { s->failed_pc=0x0c0a3150u; return 0; }
goto P_0c0a3152;
P_0c0a3152: /* original 9454, guest PC 0x0c0a3152 */
if(!s->budget--) { s->failed_pc=0x0c0a3152u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a31feu,2);
goto P_0c0a3154;
P_0c0a3154: /* original be6a, guest PC 0x0c0a3154 */
if(!s->budget--) { s->failed_pc=0x0c0a3154u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3158u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3158u) { target=s->pc; goto dispatch; }
goto P_0c0a3158;
P_0c0a3156: /* original 0009, guest PC 0x0c0a3156 */
if(!s->budget--) { s->failed_pc=0x0c0a3156u; return 0; }
goto P_0c0a3158;
P_0c0a3158: /* original 9452, guest PC 0x0c0a3158 */
if(!s->budget--) { s->failed_pc=0x0c0a3158u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3200u,2);
goto P_0c0a315a;
P_0c0a315a: /* original be67, guest PC 0x0c0a315a */
if(!s->budget--) { s->failed_pc=0x0c0a315au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a315eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a315eu) { target=s->pc; goto dispatch; }
goto P_0c0a315e;
P_0c0a315c: /* original 0009, guest PC 0x0c0a315c */
if(!s->budget--) { s->failed_pc=0x0c0a315cu; return 0; }
goto P_0c0a315e;
P_0c0a315e: /* original 9450, guest PC 0x0c0a315e */
if(!s->budget--) { s->failed_pc=0x0c0a315eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3202u,2);
goto P_0c0a3160;
P_0c0a3160: /* original be64, guest PC 0x0c0a3160 */
if(!s->budget--) { s->failed_pc=0x0c0a3160u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3164u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3164u) { target=s->pc; goto dispatch; }
goto P_0c0a3164;
P_0c0a3162: /* original 0009, guest PC 0x0c0a3162 */
if(!s->budget--) { s->failed_pc=0x0c0a3162u; return 0; }
goto P_0c0a3164;
P_0c0a3164: /* original 944e, guest PC 0x0c0a3164 */
if(!s->budget--) { s->failed_pc=0x0c0a3164u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3204u,2);
goto P_0c0a3166;
P_0c0a3166: /* original be61, guest PC 0x0c0a3166 */
if(!s->budget--) { s->failed_pc=0x0c0a3166u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a316au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a316au) { target=s->pc; goto dispatch; }
goto P_0c0a316a;
P_0c0a3168: /* original 0009, guest PC 0x0c0a3168 */
if(!s->budget--) { s->failed_pc=0x0c0a3168u; return 0; }
goto P_0c0a316a;
P_0c0a316a: /* original 944c, guest PC 0x0c0a316a */
if(!s->budget--) { s->failed_pc=0x0c0a316au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3206u,2);
goto P_0c0a316c;
P_0c0a316c: /* original be5e, guest PC 0x0c0a316c */
if(!s->budget--) { s->failed_pc=0x0c0a316cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3170u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3170u) { target=s->pc; goto dispatch; }
goto P_0c0a3170;
P_0c0a316e: /* original 0009, guest PC 0x0c0a316e */
if(!s->budget--) { s->failed_pc=0x0c0a316eu; return 0; }
goto P_0c0a3170;
P_0c0a3170: /* original 944a, guest PC 0x0c0a3170 */
if(!s->budget--) { s->failed_pc=0x0c0a3170u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3208u,2);
goto P_0c0a3172;
P_0c0a3172: /* original be5b, guest PC 0x0c0a3172 */
if(!s->budget--) { s->failed_pc=0x0c0a3172u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3176u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3176u) { target=s->pc; goto dispatch; }
goto P_0c0a3176;
P_0c0a3174: /* original 0009, guest PC 0x0c0a3174 */
if(!s->budget--) { s->failed_pc=0x0c0a3174u; return 0; }
goto P_0c0a3176;
P_0c0a3176: /* original 9448, guest PC 0x0c0a3176 */
if(!s->budget--) { s->failed_pc=0x0c0a3176u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a320au,2);
goto P_0c0a3178;
P_0c0a3178: /* original be58, guest PC 0x0c0a3178 */
if(!s->budget--) { s->failed_pc=0x0c0a3178u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a317cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a317cu) { target=s->pc; goto dispatch; }
goto P_0c0a317c;
P_0c0a317a: /* original 0009, guest PC 0x0c0a317a */
if(!s->budget--) { s->failed_pc=0x0c0a317au; return 0; }
goto P_0c0a317c;
P_0c0a317c: /* original 9446, guest PC 0x0c0a317c */
if(!s->budget--) { s->failed_pc=0x0c0a317cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a320cu,2);
goto P_0c0a317e;
P_0c0a317e: /* original be55, guest PC 0x0c0a317e */
if(!s->budget--) { s->failed_pc=0x0c0a317eu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3182u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3182u) { target=s->pc; goto dispatch; }
goto P_0c0a3182;
P_0c0a3180: /* original 0009, guest PC 0x0c0a3180 */
if(!s->budget--) { s->failed_pc=0x0c0a3180u; return 0; }
goto P_0c0a3182;
P_0c0a3182: /* original 9444, guest PC 0x0c0a3182 */
if(!s->budget--) { s->failed_pc=0x0c0a3182u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a320eu,2);
goto P_0c0a3184;
P_0c0a3184: /* original be52, guest PC 0x0c0a3184 */
if(!s->budget--) { s->failed_pc=0x0c0a3184u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3188u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3188u) { target=s->pc; goto dispatch; }
goto P_0c0a3188;
P_0c0a3186: /* original 0009, guest PC 0x0c0a3186 */
if(!s->budget--) { s->failed_pc=0x0c0a3186u; return 0; }
goto P_0c0a3188;
P_0c0a3188: /* original 9442, guest PC 0x0c0a3188 */
if(!s->budget--) { s->failed_pc=0x0c0a3188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3210u,2);
goto P_0c0a318a;
P_0c0a318a: /* original be4f, guest PC 0x0c0a318a */
if(!s->budget--) { s->failed_pc=0x0c0a318au; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a318eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a318eu) { target=s->pc; goto dispatch; }
goto P_0c0a318e;
P_0c0a318c: /* original 0009, guest PC 0x0c0a318c */
if(!s->budget--) { s->failed_pc=0x0c0a318cu; return 0; }
goto P_0c0a318e;
P_0c0a318e: /* original 9440, guest PC 0x0c0a318e */
if(!s->budget--) { s->failed_pc=0x0c0a318eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3212u,2);
goto P_0c0a3190;
P_0c0a3190: /* original be4c, guest PC 0x0c0a3190 */
if(!s->budget--) { s->failed_pc=0x0c0a3190u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3194u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3194u) { target=s->pc; goto dispatch; }
goto P_0c0a3194;
P_0c0a3192: /* original 0009, guest PC 0x0c0a3192 */
if(!s->budget--) { s->failed_pc=0x0c0a3192u; return 0; }
goto P_0c0a3194;
P_0c0a3194: /* original 943e, guest PC 0x0c0a3194 */
if(!s->budget--) { s->failed_pc=0x0c0a3194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3214u,2);
goto P_0c0a3196;
P_0c0a3196: /* original be49, guest PC 0x0c0a3196 */
if(!s->budget--) { s->failed_pc=0x0c0a3196u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a319au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a319au) { target=s->pc; goto dispatch; }
goto P_0c0a319a;
P_0c0a3198: /* original 0009, guest PC 0x0c0a3198 */
if(!s->budget--) { s->failed_pc=0x0c0a3198u; return 0; }
goto P_0c0a319a;
P_0c0a319a: /* original 943c, guest PC 0x0c0a319a */
if(!s->budget--) { s->failed_pc=0x0c0a319au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3216u,2);
goto P_0c0a319c;
P_0c0a319c: /* original be46, guest PC 0x0c0a319c */
if(!s->budget--) { s->failed_pc=0x0c0a319cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31a0u) { target=s->pc; goto dispatch; }
goto P_0c0a31a0;
P_0c0a319e: /* original 0009, guest PC 0x0c0a319e */
if(!s->budget--) { s->failed_pc=0x0c0a319eu; return 0; }
goto P_0c0a31a0;
P_0c0a31a0: /* original 943a, guest PC 0x0c0a31a0 */
if(!s->budget--) { s->failed_pc=0x0c0a31a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3218u,2);
goto P_0c0a31a2;
P_0c0a31a2: /* original be43, guest PC 0x0c0a31a2 */
if(!s->budget--) { s->failed_pc=0x0c0a31a2u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31a6u) { target=s->pc; goto dispatch; }
goto P_0c0a31a6;
P_0c0a31a4: /* original 0009, guest PC 0x0c0a31a4 */
if(!s->budget--) { s->failed_pc=0x0c0a31a4u; return 0; }
goto P_0c0a31a6;
P_0c0a31a6: /* original 9438, guest PC 0x0c0a31a6 */
if(!s->budget--) { s->failed_pc=0x0c0a31a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a321au,2);
goto P_0c0a31a8;
P_0c0a31a8: /* original be40, guest PC 0x0c0a31a8 */
if(!s->budget--) { s->failed_pc=0x0c0a31a8u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31acu) { target=s->pc; goto dispatch; }
goto P_0c0a31ac;
P_0c0a31aa: /* original 0009, guest PC 0x0c0a31aa */
if(!s->budget--) { s->failed_pc=0x0c0a31aau; return 0; }
goto P_0c0a31ac;
P_0c0a31ac: /* original 9436, guest PC 0x0c0a31ac */
if(!s->budget--) { s->failed_pc=0x0c0a31acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a321cu,2);
goto P_0c0a31ae;
P_0c0a31ae: /* original be3d, guest PC 0x0c0a31ae */
if(!s->budget--) { s->failed_pc=0x0c0a31aeu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31b2u) { target=s->pc; goto dispatch; }
goto P_0c0a31b2;
P_0c0a31b0: /* original 0009, guest PC 0x0c0a31b0 */
if(!s->budget--) { s->failed_pc=0x0c0a31b0u; return 0; }
goto P_0c0a31b2;
P_0c0a31b2: /* original 9434, guest PC 0x0c0a31b2 */
if(!s->budget--) { s->failed_pc=0x0c0a31b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a321eu,2);
goto P_0c0a31b4;
P_0c0a31b4: /* original be3a, guest PC 0x0c0a31b4 */
if(!s->budget--) { s->failed_pc=0x0c0a31b4u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31b8u) { target=s->pc; goto dispatch; }
goto P_0c0a31b8;
P_0c0a31b6: /* original 0009, guest PC 0x0c0a31b6 */
if(!s->budget--) { s->failed_pc=0x0c0a31b6u; return 0; }
goto P_0c0a31b8;
P_0c0a31b8: /* original 9432, guest PC 0x0c0a31b8 */
if(!s->budget--) { s->failed_pc=0x0c0a31b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3220u,2);
goto P_0c0a31ba;
P_0c0a31ba: /* original be37, guest PC 0x0c0a31ba */
if(!s->budget--) { s->failed_pc=0x0c0a31bau; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31beu) { target=s->pc; goto dispatch; }
goto P_0c0a31be;
P_0c0a31bc: /* original 0009, guest PC 0x0c0a31bc */
if(!s->budget--) { s->failed_pc=0x0c0a31bcu; return 0; }
goto P_0c0a31be;
P_0c0a31be: /* original 9430, guest PC 0x0c0a31be */
if(!s->budget--) { s->failed_pc=0x0c0a31beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3222u,2);
goto P_0c0a31c0;
P_0c0a31c0: /* original be34, guest PC 0x0c0a31c0 */
if(!s->budget--) { s->failed_pc=0x0c0a31c0u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a31c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a31c4u) { target=s->pc; goto dispatch; }
goto P_0c0a31c4;
P_0c0a31c2: /* original 0009, guest PC 0x0c0a31c2 */
if(!s->budget--) { s->failed_pc=0x0c0a31c2u; return 0; }
goto P_0c0a31c4;
P_0c0a31c4: /* original 942e, guest PC 0x0c0a31c4 */
if(!s->budget--) { s->failed_pc=0x0c0a31c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3224u,2);
goto P_0c0a31c6;
P_0c0a31c6: /* original a02e, guest PC 0x0c0a31c6 */
if(!s->budget--) { s->failed_pc=0x0c0a31c6u; return 0; }
goto P_0c0a3226;
P_0c0a31c8: /* original 0009, guest PC 0x0c0a31c8 */
if(!s->budget--) { s->failed_pc=0x0c0a31c8u; return 0; }
return vf3_matrix_family(0x0c0a31cau,s,ram);
P_0c0a3226: /* original be01, guest PC 0x0c0a3226 */
if(!s->budget--) { s->failed_pc=0x0c0a3226u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a322au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a322au) { target=s->pc; goto dispatch; }
goto P_0c0a322a;
P_0c0a3228: /* original 0009, guest PC 0x0c0a3228 */
if(!s->budget--) { s->failed_pc=0x0c0a3228u; return 0; }
goto P_0c0a322a;
P_0c0a322a: /* original 9407, guest PC 0x0c0a322a */
if(!s->budget--) { s->failed_pc=0x0c0a322au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a323cu,2);
goto P_0c0a322c;
P_0c0a322c: /* original bdfe, guest PC 0x0c0a322c */
if(!s->budget--) { s->failed_pc=0x0c0a322cu; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3230u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3230u) { target=s->pc; goto dispatch; }
goto P_0c0a3230;
P_0c0a322e: /* original 0009, guest PC 0x0c0a322e */
if(!s->budget--) { s->failed_pc=0x0c0a322eu; return 0; }
goto P_0c0a3230;
P_0c0a3230: /* original 9405, guest PC 0x0c0a3230 */
if(!s->budget--) { s->failed_pc=0x0c0a3230u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a323eu,2);
goto P_0c0a3232;
P_0c0a3232: /* original bdfb, guest PC 0x0c0a3232 */
if(!s->budget--) { s->failed_pc=0x0c0a3232u; return 0; }
target=0x0c0a2e2cu; r[16]=0x0c0a3236u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a3236u) { target=s->pc; goto dispatch; }
goto P_0c0a3236;
P_0c0a3234: /* original 0009, guest PC 0x0c0a3234 */
if(!s->budget--) { s->failed_pc=0x0c0a3234u; return 0; }
goto P_0c0a3236;
P_0c0a3236: /* original 9403, guest PC 0x0c0a3236 */
if(!s->budget--) { s->failed_pc=0x0c0a3236u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a3240u,2);
goto P_0c0a3238;
P_0c0a3238: /* original adf8, guest PC 0x0c0a3238 */
if(!s->budget--) { s->failed_pc=0x0c0a3238u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2e2c;
P_0c0a323a: /* original 4f26, guest PC 0x0c0a323a */
if(!s->budget--) { s->failed_pc=0x0c0a323au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0a323cu,s,ram);
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
return vf3_matrix_family(0x0c0a7fa6u,s,ram);
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=0x0c0a7fc8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=0x0c0a7fd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=0x0c0a7ff6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=0x0c0a8000u;
r[5]=0x00000072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=0x0c0a8006u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=0x0c0a801au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=0x0c0a8024u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=0x0c0a802au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a803cu,s,ram);
P_0c0cc2d6: /* original 66f2, guest PC 0x0c0cc2d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d6u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0cc2d8;
P_0c0cc2d8: /* original c726, guest PC 0x0c0cc2d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d8u; return 0; }
r[0]=0x0c0cc374u;
goto P_0c0cc2da;
P_0c0cc2da: /* original f408, guest PC 0x0c0cc2da */
if(!s->budget--) { s->failed_pc=0x0c0cc2dau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cc2dc;
P_0c0cc2dc: /* original e018, guest PC 0x0c0cc2dc */
if(!s->budget--) { s->failed_pc=0x0c0cc2dcu; return 0; }
r[0]=0x00000018u;
goto P_0c0cc2de;
P_0c0cc2de: /* original 666c, guest PC 0x0c0cc2de */
if(!s->budget--) { s->failed_pc=0x0c0cc2deu; return 0; }
r[6]=r[6]&255u;
goto P_0c0cc2e0;
P_0c0cc2e0: /* original 465a, guest PC 0x0c0cc2e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2e0u; return 0; }
r[53]=r[6];
goto P_0c0cc2e2;
P_0c0cc2e2: /* original f32d, guest PC 0x0c0cc2e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2e2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc2e4;
P_0c0cc2e4: /* original f53c, guest PC 0x0c0cc2e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2e4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc2e6;
P_0c0cc2e6: /* original f34c, guest PC 0x0c0cc2e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2e6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cc2e8;
P_0c0cc2e8: /* original f45c, guest PC 0x0c0cc2e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2e8u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cc2ea;
P_0c0cc2ea: /* original f432, guest PC 0x0c0cc2ea */
if(!s->budget--) { s->failed_pc=0x0c0cc2eau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc2ec;
P_0c0cc2ec: /* original f556, guest PC 0x0c0cc2ec */
if(!s->budget--) { s->failed_pc=0x0c0cc2ecu; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cc2ee;
P_0c0cc2ee: /* original e01c, guest PC 0x0c0cc2ee */
if(!s->budget--) { s->failed_pc=0x0c0cc2eeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc2f0;
P_0c0cc2f0: /* original f656, guest PC 0x0c0cc2f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2f0u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0cc2f2;
P_0c0cc2f2: /* original e020, guest PC 0x0c0cc2f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2f2u; return 0; }
r[0]=0x00000020u;
goto P_0c0cc2f4;
P_0c0cc2f4: /* original f542, guest PC 0x0c0cc2f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2f4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cc2f6;
P_0c0cc2f6: /* original f34c, guest PC 0x0c0cc2f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2f6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cc2f8;
P_0c0cc2f8: /* original f642, guest PC 0x0c0cc2f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2f8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0cc2fa;
P_0c0cc2fa: /* original f456, guest PC 0x0c0cc2fa */
if(!s->budget--) { s->failed_pc=0x0c0cc2fau; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0cc2fc;
P_0c0cc2fc: /* original e00c, guest PC 0x0c0cc2fc */
if(!s->budget--) { s->failed_pc=0x0c0cc2fcu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc2fe;
P_0c0cc2fe: /* original f432, guest PC 0x0c0cc2fe */
if(!s->budget--) { s->failed_pc=0x0c0cc2feu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cc300;
P_0c0cc300: /* original f457, guest PC 0x0c0cc300 */
if(!s->budget--) { s->failed_pc=0x0c0cc300u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cc302;
P_0c0cc302: /* original e010, guest PC 0x0c0cc302 */
if(!s->budget--) { s->failed_pc=0x0c0cc302u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc304;
P_0c0cc304: /* original f467, guest PC 0x0c0cc304 */
if(!s->budget--) { s->failed_pc=0x0c0cc304u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0cc306;
P_0c0cc306: /* original e014, guest PC 0x0c0cc306 */
if(!s->budget--) { s->failed_pc=0x0c0cc306u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc308;
P_0c0cc308: /* original f447, guest PC 0x0c0cc308 */
if(!s->budget--) { s->failed_pc=0x0c0cc308u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0cc30a;
P_0c0cc30a: /* original e004, guest PC 0x0c0cc30a */
if(!s->budget--) { s->failed_pc=0x0c0cc30au; return 0; }
r[0]=0x00000004u;
goto P_0c0cc30c;
P_0c0cc30c: /* original f378, guest PC 0x0c0cc30c */
if(!s->budget--) { s->failed_pc=0x0c0cc30cu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cc30e;
P_0c0cc30e: /* original f350, guest PC 0x0c0cc30e */
if(!s->budget--) { s->failed_pc=0x0c0cc30eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0cc310;
P_0c0cc310: /* original f43a, guest PC 0x0c0cc310 */
if(!s->budget--) { s->failed_pc=0x0c0cc310u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c0cc312;
P_0c0cc312: /* original f276, guest PC 0x0c0cc312 */
if(!s->budget--) { s->failed_pc=0x0c0cc312u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc314;
P_0c0cc314: /* original f260, guest PC 0x0c0cc314 */
if(!s->budget--) { s->failed_pc=0x0c0cc314u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c0cc316;
P_0c0cc316: /* original f427, guest PC 0x0c0cc316 */
if(!s->budget--) { s->failed_pc=0x0c0cc316u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0cc318;
P_0c0cc318: /* original e008, guest PC 0x0c0cc318 */
if(!s->budget--) { s->failed_pc=0x0c0cc318u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc31a;
P_0c0cc31a: /* original f376, guest PC 0x0c0cc31a */
if(!s->budget--) { s->failed_pc=0x0c0cc31au; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc31c;
P_0c0cc31c: /* original e3f8, guest PC 0x0c0cc31c */
if(!s->budget--) { s->failed_pc=0x0c0cc31cu; return 0; }
r[3]=0xfffffff8u;
goto P_0c0cc31e;
P_0c0cc31e: /* original e51f, guest PC 0x0c0cc31e */
if(!s->budget--) { s->failed_pc=0x0c0cc31eu; return 0; }
r[5]=0x0000001fu;
goto P_0c0cc320;
P_0c0cc320: /* original f34d, guest PC 0x0c0cc320 */
if(!s->budget--) { s->failed_pc=0x0c0cc320u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cc322;
P_0c0cc322: /* original f341, guest PC 0x0c0cc322 */
if(!s->budget--) { s->failed_pc=0x0c0cc322u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c0cc324;
P_0c0cc324: /* original f437, guest PC 0x0c0cc324 */
if(!s->budget--) { s->failed_pc=0x0c0cc324u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0cc326;
P_0c0cc326: /* original 60f2, guest PC 0x0c0cc326 */
if(!s->budget--) { s->failed_pc=0x0c0cc326u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cc328;
P_0c0cc328: /* original 403c, guest PC 0x0c0cc328 */
if(!s->budget--) { s->failed_pc=0x0c0cc328u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0cc32a;
P_0c0cc32a: /* original 2509, guest PC 0x0c0cc32a */
if(!s->budget--) { s->failed_pc=0x0c0cc32au; return 0; }
r[5]&=r[0];
goto P_0c0cc32c;
P_0c0cc32c: /* original 7504, guest PC 0x0c0cc32c */
if(!s->budget--) { s->failed_pc=0x0c0cc32cu; return 0; }
r[5]+=0x00000004u;
goto P_0c0cc32e;
P_0c0cc32e: /* original 6053, guest PC 0x0c0cc32e */
if(!s->budget--) { s->failed_pc=0x0c0cc32eu; return 0; }
r[0]=r[5];
goto P_0c0cc330;
P_0c0cc330: /* original 000b, guest PC 0x0c0cc330 */
if(!s->budget--) { s->failed_pc=0x0c0cc330u; return 0; }
target=r[16];
write(ram,r[4]+30,r[0],2);
s->pc=target; return ram->oob==0;
P_0c0cc332: /* original 814f, guest PC 0x0c0cc332 */
if(!s->budget--) { s->failed_pc=0x0c0cc332u; return 0; }
write(ram,r[4]+30,r[0],2);
return vf3_matrix_family(0x0c0cc334u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0352dau,0x0c0352dcu,0x0c0352deu,0x0c0352e0u,0x0c0352e2u,0x0c0352e4u,0x0c0352e6u,0x0c0352e8u,0x0c0352eau,0x0c0352ecu,0x0c0352eeu,0x0c0352f0u,0x0c0352f2u,0x0c0352f4u,0x0c0352f6u,0x0c0352f8u,
0x0c0352fau,0x0c0352fcu,0x0c0352feu,0x0c035300u,0x0c0431eau,0x0c0431ecu,0x0c0431eeu,0x0c0431f0u,0x0c0431f2u,0x0c0431f4u,0x0c0431f6u,0x0c0431f8u,0x0c0431fau,0x0c0431fcu,0x0c0431feu,0x0c043200u,
0x0c043202u,0x0c043204u,0x0c043206u,0x0c043208u,0x0c04320au,0x0c04320cu,0x0c04320eu,0x0c043210u,0x0c043212u,0x0c043214u,0x0c043216u,0x0c043218u,0x0c04321au,0x0c04321cu,0x0c04321eu,0x0c043220u,
0x0c043222u,0x0c043224u,0x0c043226u,0x0c043228u,0x0c04322au,0x0c04322cu,0x0c04322eu,0x0c043230u,0x0c043232u,0x0c043234u,0x0c043236u,0x0c043238u,0x0c04323au,0x0c04323cu,0x0c04323eu,0x0c043240u,
0x0c043242u,0x0c043244u,0x0c043246u,0x0c043248u,0x0c04324au,0x0c04324cu,0x0c04324eu,0x0c043250u,0x0c043252u,0x0c043254u,0x0c043256u,0x0c043258u,0x0c04325au,0x0c04325cu,0x0c04325eu,0x0c043260u,
0x0c043262u,0x0c043264u,0x0c043266u,0x0c043268u,0x0c046616u,0x0c046618u,0x0c04661au,0x0c04e412u,0x0c04e414u,0x0c04e416u,0x0c04e418u,0x0c04e41au,0x0c04e41cu,0x0c04e41eu,0x0c04e420u,0x0c04e422u,
0x0c04e424u,0x0c04e426u,0x0c04e428u,0x0c04e42au,0x0c04e42cu,0x0c04e42eu,0x0c04e430u,0x0c04e432u,0x0c04e434u,0x0c04e436u,0x0c04e438u,0x0c04e43au,0x0c04e43cu,0x0c04e43eu,0x0c04e440u,0x0c04e442u,
0x0c04e444u,0x0c04e446u,0x0c04e448u,0x0c04e44au,0x0c04e44cu,0x0c04e490u,0x0c04e492u,0x0c04e494u,0x0c04e496u,0x0c04e498u,0x0c04e49au,0x0c04e49cu,0x0c04e49eu,0x0c04e4a0u,0x0c04e4a2u,0x0c04e4a4u,
0x0c04e4a6u,0x0c04e4a8u,0x0c04e4aau,0x0c04e4acu,0x0c04e4aeu,0x0c04e4b0u,0x0c04e4b2u,0x0c04e4b4u,0x0c04e4b6u,0x0c04e4b8u,0x0c04e4bau,0x0c04e4bcu,0x0c04e4beu,0x0c04e4c0u,0x0c04e4c2u,0x0c04e4c4u,
0x0c04e4c6u,0x0c04e4c8u,0x0c04e4cau,0x0c04e4ccu,0x0c04e4ceu,0x0c04e4d0u,0x0c04e4d2u,0x0c04e4d4u,0x0c04e4d6u,0x0c04e4d8u,0x0c04e4dau,0x0c04e4dcu,0x0c04e4deu,0x0c04f88cu,0x0c04f88eu,0x0c04f890u,
0x0c04f892u,0x0c04f894u,0x0c04f896u,0x0c04f898u,0x0c04f89au,0x0c04f89cu,0x0c04f89eu,0x0c04f8a0u,0x0c04f8a2u,0x0c04f8a4u,0x0c04f8bcu,0x0c04f8beu,0x0c04f8c0u,0x0c04f8c2u,0x0c04f8c4u,0x0c04f8c6u,
0x0c04f8c8u,0x0c04f8cau,0x0c04f8ccu,0x0c04f8ceu,0x0c04f8d0u,0x0c04f8d2u,0x0c04f8d4u,0x0c04f8d6u,0x0c04f8d8u,0x0c04f8dau,0x0c04f8dcu,0x0c04f8deu,0x0c04f8e0u,0x0c04f8e2u,0x0c04f8e4u,0x0c04f8e6u,
0x0c04f8e8u,0x0c04f8eau,0x0c04f8ecu,0x0c04f8eeu,0x0c04f8f0u,0x0c04f8f2u,0x0c04f8f4u,0x0c04f8f6u,0x0c04f8f8u,0x0c04f8fau,0x0c04f8fcu,0x0c04f8feu,0x0c04f900u,0x0c04f902u,0x0c04f904u,0x0c04f906u,
0x0c04f908u,0x0c04f90au,0x0c04f90cu,0x0c04f90eu,0x0c04f910u,0x0c04f912u,0x0c04f914u,0x0c04f916u,0x0c04f918u,0x0c04f91au,0x0c04f91cu,0x0c04f91eu,0x0c04f920u,0x0c04f922u,0x0c04f924u,0x0c04f926u,
0x0c04f928u,0x0c04f92au,0x0c04f92cu,0x0c04f92eu,0x0c04f930u,0x0c04f932u,0x0c04f934u,0x0c04f936u,0x0c04f938u,0x0c04f93au,0x0c04f93cu,0x0c04f93eu,0x0c04f940u,0x0c04f942u,0x0c04f944u,0x0c04f946u,
0x0c04f948u,0x0c04f94au,0x0c04f94cu,0x0c04f94eu,0x0c04f950u,0x0c04f952u,0x0c04f954u,0x0c04f956u,0x0c04f958u,0x0c04f95au,0x0c04f95cu,0x0c04f95eu,0x0c04f960u,0x0c04f962u,0x0c04f964u,0x0c04f966u,
0x0c04f968u,0x0c04f96au,0x0c04f96cu,0x0c04f96eu,0x0c04f970u,0x0c04f972u,0x0c04f974u,0x0c04f976u,0x0c04f978u,0x0c04f97au,0x0c04f97cu,0x0c04f97eu,0x0c04f980u,0x0c04f982u,0x0c04f984u,0x0c04f986u,
0x0c04f988u,0x0c04f98au,0x0c04f98cu,0x0c04f98eu,0x0c04f990u,0x0c04f992u,0x0c04f994u,0x0c04f996u,0x0c04f998u,0x0c04f99au,0x0c04f99cu,0x0c04f99eu,0x0c04f9a0u,0x0c04f9a2u,0x0c04f9a4u,0x0c04f9a6u,
0x0c04f9a8u,0x0c04f9aau,0x0c04f9acu,0x0c04f9aeu,0x0c04f9b0u,0x0c04f9b2u,0x0c04f9b4u,0x0c04f9b6u,0x0c04f9b8u,0x0c04f9bau,0x0c04f9bcu,0x0c04f9beu,0x0c04f9c0u,0x0c04f9c2u,0x0c04f9c4u,0x0c04f9c6u,
0x0c04f9c8u,0x0c04f9cau,0x0c04f9ccu,0x0c04f9ceu,0x0c04f9d0u,0x0c04f9d2u,0x0c04f9d4u,0x0c04f9d6u,0x0c04f9f0u,0x0c04f9f2u,0x0c04f9f4u,0x0c04f9f6u,0x0c04f9f8u,0x0c04f9fau,0x0c04f9fcu,0x0c04f9feu,
0x0c04fa00u,0x0c04fa02u,0x0c04fa04u,0x0c04fa06u,0x0c04fa08u,0x0c04fa0au,0x0c04fa0cu,0x0c04fa0eu,0x0c04fa10u,0x0c04fa12u,0x0c04fa14u,0x0c04fa16u,0x0c04fa18u,0x0c04fa1au,0x0c04fa1cu,0x0c04fa1eu,
0x0c04fa20u,0x0c04fa22u,0x0c04fa24u,0x0c04fa26u,0x0c04fa28u,0x0c04fa2au,0x0c04fa2cu,0x0c04fa2eu,0x0c04fa30u,0x0c04fa32u,0x0c04fa34u,0x0c04fa36u,0x0c07ba28u,0x0c07ba2au,0x0c07ba2cu,0x0c07ba2eu,
0x0c07ba30u,0x0c07ba32u,0x0c07ba34u,0x0c07ba36u,0x0c07ba38u,0x0c07ba3au,0x0c07ba3cu,0x0c07ba3eu,0x0c07ba40u,0x0c07ba42u,0x0c07ba44u,0x0c07ba46u,0x0c07ba48u,0x0c07ba4au,0x0c07ba4cu,0x0c07ba4eu,
0x0c07ba50u,0x0c07ba52u,0x0c07ba54u,0x0c07ba56u,0x0c07ba58u,0x0c07ba5au,0x0c07ba5cu,0x0c07ba5eu,0x0c07ba60u,0x0c07ba62u,0x0c07ba64u,0x0c07ba66u,0x0c07ba68u,0x0c07ba6au,0x0c07ba6cu,0x0c07ba6eu,
0x0c07ba70u,0x0c07ba72u,0x0c07ba74u,0x0c07ba76u,0x0c07ba78u,0x0c07ba7au,0x0c07ba7cu,0x0c07ba7eu,0x0c07ba80u,0x0c07ba82u,0x0c07ba84u,0x0c07ba86u,0x0c07ba88u,0x0c07ba8au,0x0c07ba8cu,0x0c07ba8eu,
0x0c07ba90u,0x0c07ba92u,0x0c07ba94u,0x0c07ba96u,0x0c07ba98u,0x0c07ba9au,0x0c07ba9cu,0x0c07ba9eu,0x0c07baa0u,0x0c07baa2u,0x0c07baa4u,0x0c07baa6u,0x0c07baa8u,0x0c07baaau,0x0c07baacu,0x0c07baaeu,
0x0c07bab0u,0x0c07bab2u,0x0c07bab4u,0x0c07bab6u,0x0c07bab8u,0x0c07babau,0x0c07babcu,0x0c07babeu,0x0c07bac0u,0x0c07bac2u,0x0c07bac4u,0x0c07bac6u,0x0c07bac8u,0x0c07bacau,0x0c07baccu,0x0c07baceu,
0x0c07bad0u,0x0c07bad2u,0x0c07bad4u,0x0c07bad6u,0x0c07bad8u,0x0c07badau,0x0c07badcu,0x0c07badeu,0x0c07bae0u,0x0c07bae2u,0x0c07bae4u,0x0c07bae6u,0x0c07bae8u,0x0c07baeau,0x0c07baecu,0x0c07baeeu,
0x0c07baf0u,0x0c07baf2u,0x0c07baf4u,0x0c07baf6u,0x0c07baf8u,0x0c07bafau,0x0c07bafcu,0x0c07bafeu,0x0c07bb00u,0x0c07bb02u,0x0c07bb04u,0x0c07bb06u,0x0c07bb08u,0x0c07bb0au,0x0c07bb0cu,0x0c07bb0eu,
0x0c07bb10u,0x0c07bb12u,0x0c07bb14u,0x0c07bb16u,0x0c07bb18u,0x0c07bb1au,0x0c07bb1cu,0x0c07bb1eu,0x0c07bb20u,0x0c07bb22u,0x0c07bb24u,0x0c07bb26u,0x0c07bb28u,0x0c07bb2au,0x0c07bb2cu,0x0c07bb2eu,
0x0c07bb30u,0x0c07bb32u,0x0c07bb34u,0x0c07bb36u,0x0c07bb38u,0x0c07bb3au,0x0c07bb3cu,0x0c07bb3eu,0x0c07bb40u,0x0c07bb42u,0x0c07bb44u,0x0c07bb46u,0x0c07bba0u,0x0c07bba2u,0x0c07bba4u,0x0c07bba6u,
0x0c07bba8u,0x0c07bbaau,0x0c07bbacu,0x0c07bbaeu,0x0c07bbb0u,0x0c07bbb2u,0x0c07bbb4u,0x0c07bbb6u,0x0c07bbb8u,0x0c07bbbau,0x0c07bbbcu,0x0c07bbbeu,0x0c07bbc0u,0x0c07bbc2u,0x0c07bbc4u,0x0c07bbc6u,
0x0c07bbc8u,0x0c07bbcau,0x0c07bbccu,0x0c07bbceu,0x0c07bbd0u,0x0c07bbd2u,0x0c07bbd4u,0x0c07bbd6u,0x0c07bbd8u,0x0c07bbdau,0x0c07bbdcu,0x0c07bbdeu,0x0c07bbe0u,0x0c07bbe2u,0x0c07bbe4u,0x0c07bbe6u,
0x0c07bbe8u,0x0c07bbeau,0x0c07bbecu,0x0c07bbeeu,0x0c07bbf0u,0x0c07bbf2u,0x0c07bbf4u,0x0c07bbf6u,0x0c07bbf8u,0x0c07bbfau,0x0c07bbfcu,0x0c07bbfeu,0x0c07bc00u,0x0c07bc02u,0x0c07bc04u,0x0c07bc06u,
0x0c07bc08u,0x0c07bc0au,0x0c07bc0cu,0x0c07bc0eu,0x0c07bc10u,0x0c07bc12u,0x0c07bc14u,0x0c07bc16u,0x0c07bc18u,0x0c07bc1au,0x0c07bc1cu,0x0c07bc1eu,0x0c07bc20u,0x0c07bc22u,0x0c07bc24u,0x0c07bc26u,
0x0c07bc28u,0x0c07bc2au,0x0c07bc2cu,0x0c07bc2eu,0x0c07bc30u,0x0c07bc32u,0x0c07bc34u,0x0c07bc36u,0x0c07bc38u,0x0c07bc3au,0x0c07bc3cu,0x0c07bc3eu,0x0c07bc40u,0x0c07bc42u,0x0c07bc44u,0x0c07bc46u,
0x0c07bc48u,0x0c07bc4au,0x0c07bc4cu,0x0c07bc4eu,0x0c07bc50u,0x0c07bc52u,0x0c07bc54u,0x0c07bc56u,0x0c07bc58u,0x0c07bc5au,0x0c07bc5cu,0x0c07bc5eu,0x0c07bc60u,0x0c07bc62u,0x0c07bc64u,0x0c07bc66u,
0x0c07bc68u,0x0c07bc6au,0x0c07bc6cu,0x0c07bc6eu,0x0c07bc70u,0x0c07bc72u,0x0c07bc74u,0x0c07bc76u,0x0c07bc78u,0x0c07bc7au,0x0c07bc7cu,0x0c07bc7eu,0x0c07bc80u,0x0c07bc82u,0x0c07bc84u,0x0c07bc86u,
0x0c07bc88u,0x0c07bc8au,0x0c07bc8cu,0x0c07bc8eu,0x0c07bc90u,0x0c07bc92u,0x0c07bc94u,0x0c07bc96u,0x0c07bc98u,0x0c07bc9au,0x0c07bc9cu,0x0c07bc9eu,0x0c07bca0u,0x0c07bca2u,0x0c07bca4u,0x0c07bca6u,
0x0c07bca8u,0x0c07bcaau,0x0c07bcacu,0x0c07bcaeu,0x0c07bcb0u,0x0c07bcb2u,0x0c07bcb4u,0x0c07bcb6u,0x0c07bcb8u,0x0c07bcbau,0x0c07bcbcu,0x0c07bcbeu,0x0c07bcc0u,0x0c07bcc2u,0x0c07bcc4u,0x0c07bcc6u,
0x0c07bcc8u,0x0c07bccau,0x0c07bcccu,0x0c07bcceu,0x0c07bcd0u,0x0c07bcd2u,0x0c07bcd4u,0x0c07bcd6u,0x0c07bcd8u,0x0c07bcdau,0x0c07bcdcu,0x0c07bcdeu,0x0c07bce0u,0x0c07bce2u,0x0c07bce4u,0x0c07bce6u,
0x0c07bce8u,0x0c07bceau,0x0c07bcecu,0x0c07bceeu,0x0c07bcf0u,0x0c07bcf2u,0x0c07bcf4u,0x0c07bcf6u,0x0c07bcf8u,0x0c07bd14u,0x0c07bd16u,0x0c07bd18u,0x0c07bd1au,0x0c07bd1cu,0x0c07bd1eu,0x0c07bd20u,
0x0c07bd22u,0x0c07bd24u,0x0c07bd26u,0x0c07bd28u,0x0c07bd2au,0x0c07bd2cu,0x0c07bd2eu,0x0c07bd30u,0x0c07bd32u,0x0c07bd34u,0x0c07bd36u,0x0c07bd38u,0x0c07bd3au,0x0c07bd3cu,0x0c07bd3eu,0x0c07bd40u,
0x0c07bd42u,0x0c07bd44u,0x0c07bd46u,0x0c07bd48u,0x0c07bd4au,0x0c07bd4cu,0x0c07bd4eu,0x0c07bd50u,0x0c07bd52u,0x0c07bd54u,0x0c07bd56u,0x0c07bd58u,0x0c07bd5au,0x0c07bd5cu,0x0c07bd5eu,0x0c07bd60u,
0x0c07bd62u,0x0c07bd64u,0x0c07bd66u,0x0c07bd68u,0x0c07bd6au,0x0c07bd6cu,0x0c07bd6eu,0x0c07bd70u,0x0c07bd72u,0x0c07bd74u,0x0c07bd76u,0x0c07bd78u,0x0c07bd7au,0x0c07bd7cu,0x0c07bd7eu,0x0c07bd80u,
0x0c07bd82u,0x0c07bd84u,0x0c07bd86u,0x0c07bd88u,0x0c07bd8au,0x0c07bd8cu,0x0c07bd8eu,0x0c07bd90u,0x0c07bd92u,0x0c07bd94u,0x0c07bd96u,0x0c07bd98u,0x0c07bd9au,0x0c07bd9cu,0x0c07bd9eu,0x0c07bda0u,
0x0c07bda2u,0x0c07bda4u,0x0c07bda6u,0x0c07bda8u,0x0c07bdaau,0x0c07bdacu,0x0c07bdaeu,0x0c07bdb0u,0x0c07bdb2u,0x0c07bdb4u,0x0c07bdb6u,0x0c07bdb8u,0x0c07bdbau,0x0c07bdbcu,0x0c07bdbeu,0x0c07bdc0u,
0x0c07bdc2u,0x0c07bdc4u,0x0c07bdc6u,0x0c07bdc8u,0x0c07bdcau,0x0c07bdccu,0x0c07bdceu,0x0c07bdd0u,0x0c07bdd2u,0x0c07bdd4u,0x0c07bdd6u,0x0c07bdd8u,0x0c07bddau,0x0c07bddcu,0x0c07bddeu,0x0c07bde0u,
0x0c07bde2u,0x0c07bde4u,0x0c07bde6u,0x0c07bde8u,0x0c07bdeau,0x0c07bdecu,0x0c07bdeeu,0x0c07bdf0u,0x0c07bdf2u,0x0c07bdf4u,0x0c07bdf6u,0x0c07bdf8u,0x0c07bdfau,0x0c07bdfcu,0x0c07bdfeu,0x0c07be00u,
0x0c07be02u,0x0c07be04u,0x0c07be06u,0x0c07be08u,0x0c07be0au,0x0c07be0cu,0x0c07be0eu,0x0c07be10u,0x0c07be12u,0x0c07be14u,0x0c07be16u,0x0c07be18u,0x0c07be1au,0x0c07be1cu,0x0c07be1eu,0x0c07be20u,
0x0c07be22u,0x0c07be24u,0x0c07be26u,0x0c07be28u,0x0c07be2au,0x0c07be2cu,0x0c07be2eu,0x0c07be30u,0x0c07be32u,0x0c07be34u,0x0c07be36u,0x0c07be38u,0x0c07be3au,0x0c07be3cu,0x0c07be3eu,0x0c07be40u,
0x0c07be42u,0x0c07be44u,0x0c07be46u,0x0c07be48u,0x0c07be4au,0x0c07be4cu,0x0c07be4eu,0x0c07be50u,0x0c07be52u,0x0c07be54u,0x0c07be56u,0x0c07be58u,0x0c07be5au,0x0c07be5cu,0x0c07be5eu,0x0c07be60u,
0x0c07be62u,0x0c07be64u,0x0c07be66u,0x0c07be68u,0x0c07be6au,0x0c07be6cu,0x0c07be6eu,0x0c07be70u,0x0c07be72u,0x0c07be74u,0x0c07be76u,0x0c07be78u,0x0c07be7au,0x0c07be7cu,0x0c07be7eu,0x0c07be80u,
0x0c07be82u,0x0c07be84u,0x0c07be86u,0x0c07be88u,0x0c07be8au,0x0c07be8cu,0x0c07be8eu,0x0c07be90u,0x0c07be92u,0x0c07be94u,0x0c07be96u,0x0c07be98u,0x0c07be9au,0x0c07beb0u,0x0c07beb2u,0x0c07beb4u,
0x0c07beb6u,0x0c07beb8u,0x0c07bebau,0x0c07bebcu,0x0c07bebeu,0x0c07bec0u,0x0c07bec2u,0x0c07bec4u,0x0c07bec6u,0x0c07bec8u,0x0c07becau,0x0c07beccu,0x0c07beceu,0x0c07bed0u,0x0c07bed2u,0x0c07bed4u,
0x0c07bed6u,0x0c07bed8u,0x0c07bedau,0x0c07bedcu,0x0c07bedeu,0x0c07bee0u,0x0c07bee2u,0x0c07bee4u,0x0c07bee6u,0x0c07bee8u,0x0c07beeau,0x0c07beecu,0x0c07beeeu,0x0c07bef0u,0x0c07bef2u,0x0c07bef4u,
0x0c07bef6u,0x0c07bef8u,0x0c07befau,0x0c07befcu,0x0c07befeu,0x0c07bf00u,0x0c07bf02u,0x0c07bf04u,0x0c07bf06u,0x0c07bf08u,0x0c07bf0au,0x0c07bf0cu,0x0c07bf0eu,0x0c07bf10u,0x0c07bf12u,0x0c07bf14u,
0x0c07bf16u,0x0c07bf18u,0x0c07bf1au,0x0c07bf1cu,0x0c07bf1eu,0x0c07bf20u,0x0c07bf22u,0x0c07bf24u,0x0c07bf26u,0x0c07bf28u,0x0c07bf2au,0x0c07bf2cu,0x0c07bf2eu,0x0c07bf30u,0x0c07bf32u,0x0c07bf34u,
0x0c07bf36u,0x0c07bf38u,0x0c07bf3au,0x0c07bf3cu,0x0c07bf3eu,0x0c07bf40u,0x0c07bf42u,0x0c07bf44u,0x0c07bf46u,0x0c07bf48u,0x0c07bf4au,0x0c07bf4cu,0x0c07bf4eu,0x0c07bf50u,0x0c07bf52u,0x0c07bf54u,
0x0c07bf56u,0x0c07bf58u,0x0c07bf5au,0x0c07bf5cu,0x0c07bf5eu,0x0c07bf60u,0x0c07bf62u,0x0c07bf64u,0x0c07bf66u,0x0c07bf68u,0x0c07bf6au,0x0c07bf6cu,0x0c07bf6eu,0x0c07bf70u,0x0c07bf72u,0x0c07bf74u,
0x0c07bf76u,0x0c07bf78u,0x0c07bf7au,0x0c07bf7cu,0x0c07bf7eu,0x0c07bf80u,0x0c07bf82u,0x0c07bf84u,0x0c07bf86u,0x0c07bf88u,0x0c07bf8au,0x0c07bf8cu,0x0c07bf8eu,0x0c07bf90u,0x0c07bf92u,0x0c07bf94u,
0x0c07bf96u,0x0c07bf98u,0x0c07bf9au,0x0c07bf9cu,0x0c07bf9eu,0x0c07bfa0u,0x0c07bfa2u,0x0c07bfa4u,0x0c07bfa6u,0x0c07bfa8u,0x0c07bfaau,0x0c07bfacu,0x0c07bfaeu,0x0c07bfb0u,0x0c07bfb2u,0x0c07bfb4u,
0x0c07bfb6u,0x0c07bfb8u,0x0c07bfbau,0x0c07bfbcu,0x0c07bfbeu,0x0c07bfc0u,0x0c07bfc2u,0x0c07bfc4u,0x0c07bfc6u,0x0c07bfc8u,0x0c07bfcau,0x0c07bfccu,0x0c07bfceu,0x0c07bfd0u,0x0c07bfd2u,0x0c07bfd4u,
0x0c07bfd6u,0x0c07bfd8u,0x0c07bfdau,0x0c07bfdcu,0x0c07bfdeu,0x0c07bfe0u,0x0c07bfe2u,0x0c07bfe4u,0x0c07bfe6u,0x0c07bfe8u,0x0c07bfeau,0x0c07bfecu,0x0c07bfeeu,0x0c07bff0u,0x0c07bff2u,0x0c07bff4u,
0x0c07bff6u,0x0c07bff8u,0x0c07bffau,0x0c07bffcu,0x0c07bffeu,0x0c07c000u,0x0c07c002u,0x0c07c004u,0x0c07c006u,0x0c07c008u,0x0c07c00au,0x0c07c00cu,0x0c07c00eu,0x0c07c010u,0x0c07c012u,0x0c07c014u,
0x0c07c016u,0x0c07c018u,0x0c07c01au,0x0c07c01cu,0x0c07c01eu,0x0c07c020u,0x0c07c022u,0x0c07c024u,0x0c07c026u,0x0c07c028u,0x0c07c02au,0x0c07c02cu,0x0c07c02eu,0x0c07c030u,0x0c07c032u,0x0c07c034u,
0x0c07c036u,0x0c07c038u,0x0c07c03au,0x0c07c03cu,0x0c07c03eu,0x0c07c040u,0x0c07c042u,0x0c07c05cu,0x0c07c05eu,0x0c07c060u,0x0c07c062u,0x0c07c064u,0x0c07c066u,0x0c07c068u,0x0c07c06au,0x0c07c06cu,
0x0c07c06eu,0x0c07c070u,0x0c07c072u,0x0c07c074u,0x0c07c076u,0x0c07c078u,0x0c07c07au,0x0c07c07cu,0x0c07c07eu,0x0c07c080u,0x0c07c082u,0x0c07c084u,0x0c07c086u,0x0c07c088u,0x0c07c08au,0x0c07c08cu,
0x0c07c08eu,0x0c07c090u,0x0c07c092u,0x0c07c094u,0x0c07c096u,0x0c07c098u,0x0c07c09au,0x0c07c09cu,0x0c07c09eu,0x0c07c0a0u,0x0c07c0a2u,0x0c07c0a4u,0x0c07c0a6u,0x0c07c0a8u,0x0c07c0aau,0x0c07c0acu,
0x0c07c0aeu,0x0c07c0b0u,0x0c07c0b2u,0x0c07c0b4u,0x0c07c0b6u,0x0c07c0b8u,0x0c07c0bau,0x0c07c0bcu,0x0c07c0beu,0x0c07c0c0u,0x0c07c0c2u,0x0c07c0c4u,0x0c07c0c6u,0x0c07c0c8u,0x0c07c0cau,0x0c07c0ccu,
0x0c07c0ceu,0x0c07c0d0u,0x0c07c0d2u,0x0c07c0d4u,0x0c07c0d6u,0x0c07c0d8u,0x0c07c0dau,0x0c07c0dcu,0x0c07c0deu,0x0c07c0e0u,0x0c07c0e2u,0x0c07c0e4u,0x0c07c0e6u,0x0c07c0e8u,0x0c07c0eau,0x0c07c0ecu,
0x0c07c0eeu,0x0c07c0f0u,0x0c07c0f2u,0x0c07c0f4u,0x0c07c0f6u,0x0c07c0f8u,0x0c07c0fau,0x0c07c0fcu,0x0c07c0feu,0x0c07c100u,0x0c07c102u,0x0c07c12cu,0x0c07c12eu,0x0c07c130u,0x0c07c132u,0x0c07c134u,
0x0c07c136u,0x0c07c138u,0x0c07c13au,0x0c07c13cu,0x0c07c13eu,0x0c07c140u,0x0c07c142u,0x0c07c144u,0x0c07c146u,0x0c07c148u,0x0c07c14au,0x0c07c14cu,0x0c07c14eu,0x0c07c150u,0x0c07c152u,0x0c07c154u,
0x0c07c156u,0x0c07c158u,0x0c07c15au,0x0c07c15cu,0x0c07c15eu,0x0c07c160u,0x0c07c162u,0x0c07c164u,0x0c07c166u,0x0c07c168u,0x0c07c16au,0x0c07c16cu,0x0c07c16eu,0x0c07c170u,0x0c07c172u,0x0c07c174u,
0x0c07c176u,0x0c07c178u,0x0c07c17au,0x0c07c17cu,0x0c07c17eu,0x0c07c180u,0x0c07c182u,0x0c07c184u,0x0c07c186u,0x0c07c188u,0x0c07c18au,0x0c07c18cu,0x0c07c18eu,0x0c07c190u,0x0c07c192u,0x0c07c194u,
0x0c07c196u,0x0c07c198u,0x0c07c19au,0x0c07c19cu,0x0c07c19eu,0x0c07c1a0u,0x0c07c1a2u,0x0c07c1a4u,0x0c07c1a6u,0x0c07c1a8u,0x0c07c1aau,0x0c07c1acu,0x0c07c1aeu,0x0c07c1b0u,0x0c07c1b2u,0x0c07c1b4u,
0x0c07c1b6u,0x0c07c1b8u,0x0c07c1bau,0x0c07c1bcu,0x0c07c1beu,0x0c07c1c0u,0x0c07c1c2u,0x0c07c1c4u,0x0c07c1c6u,0x0c07c1c8u,0x0c07c1cau,0x0c07c1ccu,0x0c07c1ceu,0x0c07c1d0u,0x0c07c1d2u,0x0c07c1d4u,
0x0c07c1d6u,0x0c07c1d8u,0x0c07c1dau,0x0c07c1dcu,0x0c07c1deu,0x0c07c1e0u,0x0c07c1e2u,0x0c07c1e4u,0x0c07c1e6u,0x0c07c1e8u,0x0c07c1eau,0x0c07c1ecu,0x0c07c1eeu,0x0c07c1f0u,0x0c07c1f2u,0x0c07c1f4u,
0x0c07c1f6u,0x0c07c1f8u,0x0c07c1fau,0x0c07c1fcu,0x0c07c1feu,0x0c07c200u,0x0c07c202u,0x0c07c204u,0x0c07c206u,0x0c07c208u,0x0c07c20au,0x0c07c20cu,0x0c07c20eu,0x0c07c210u,0x0c07c212u,0x0c07c214u,
0x0c07c216u,0x0c07c218u,0x0c07c21au,0x0c07c21cu,0x0c07c21eu,0x0c07c220u,0x0c07c222u,0x0c07c224u,0x0c07c226u,0x0c07c228u,0x0c07c22au,0x0c07c22cu,0x0c07c22eu,0x0c07c230u,0x0c07c232u,0x0c07c234u,
0x0c07c236u,0x0c07c238u,0x0c07c23au,0x0c07c23cu,0x0c07c23eu,0x0c07c240u,0x0c07c242u,0x0c07c244u,0x0c07c246u,0x0c07c248u,0x0c07c24au,0x0c07c24cu,0x0c07c24eu,0x0c07c250u,0x0c07c252u,0x0c07c254u,
0x0c07c256u,0x0c07c258u,0x0c07c25au,0x0c07c25cu,0x0c07c25eu,0x0c07c260u,0x0c07c262u,0x0c07c264u,0x0c07c266u,0x0c07c268u,0x0c07c26au,0x0c07c26cu,0x0c07c26eu,0x0c07c270u,0x0c07c272u,0x0c07c274u,
0x0c07c276u,0x0c07c278u,0x0c07c27au,0x0c07c27cu,0x0c07c27eu,0x0c07c280u,0x0c07c282u,0x0c07c284u,0x0c07c286u,0x0c07c288u,0x0c07c28au,0x0c07c28cu,0x0c07c28eu,0x0c07c290u,0x0c07c292u,0x0c07c294u,
0x0c07c296u,0x0c07c298u,0x0c07c29au,0x0c07c29cu,0x0c07c29eu,0x0c07c2a0u,0x0c07c2a2u,0x0c07c2a4u,0x0c07c2a6u,0x0c07c2a8u,0x0c07c2aau,0x0c07c2acu,0x0c07c2aeu,0x0c07c2b0u,0x0c07c2b2u,0x0c07c2b4u,
0x0c07c2d0u,0x0c07c2d2u,0x0c07c2d4u,0x0c07c2d6u,0x0c07c2d8u,0x0c07c2dau,0x0c07c2dcu,0x0c07c2deu,0x0c07c2e0u,0x0c07c2e2u,0x0c07c2e4u,0x0c07c2e6u,0x0c07c2e8u,0x0c07c2eau,0x0c07c2ecu,0x0c07c2eeu,
0x0c07c2f0u,0x0c07c2f2u,0x0c07c2f4u,0x0c07c2f6u,0x0c07c2f8u,0x0c07c2fau,0x0c07c2fcu,0x0c07c2feu,0x0c07c300u,0x0c07c302u,0x0c07c304u,0x0c07c306u,0x0c07c308u,0x0c07c30au,0x0c07c30cu,0x0c07c30eu,
0x0c07c310u,0x0c07c312u,0x0c07c314u,0x0c07c316u,0x0c07c318u,0x0c07c31au,0x0c07c31cu,0x0c07c31eu,0x0c07c320u,0x0c07c322u,0x0c07c324u,0x0c07c326u,0x0c07c328u,0x0c07c32au,0x0c07c32cu,0x0c07c32eu,
0x0c07c330u,0x0c07c332u,0x0c07c540u,0x0c07c542u,0x0c07c544u,0x0c07c546u,0x0c07c548u,0x0c07c54au,0x0c07c54cu,0x0c07c54eu,0x0c07c550u,0x0c07c552u,0x0c07c554u,0x0c07c556u,0x0c07c558u,0x0c07c55au,
0x0c07c55cu,0x0c07c55eu,0x0c07c560u,0x0c07c562u,0x0c07c564u,0x0c07c566u,0x0c07c568u,0x0c07c56au,0x0c07c56cu,0x0c07c56eu,0x0c07c570u,0x0c07c572u,0x0c07c574u,0x0c07c576u,0x0c07c578u,0x0c07c57au,
0x0c07c57cu,0x0c07c57eu,0x0c07c580u,0x0c07c582u,0x0c07c584u,0x0c07c586u,0x0c07c588u,0x0c07c58au,0x0c07c58cu,0x0c07c58eu,0x0c07c590u,0x0c07c592u,0x0c07c594u,0x0c07c596u,0x0c07c598u,0x0c07c59au,
0x0c07c59cu,0x0c07c59eu,0x0c07c5a0u,0x0c07c5a2u,0x0c07c5a4u,0x0c07c5a6u,0x0c07c5a8u,0x0c07c5aau,0x0c07c5acu,0x0c07c5aeu,0x0c07c5b0u,0x0c07c5b2u,0x0c07c5b4u,0x0c07c5b6u,0x0c07c5b8u,0x0c07c5bau,
0x0c07c5bcu,0x0c07c5beu,0x0c07c5c0u,0x0c07c5c2u,0x0c07c5c4u,0x0c07c5c6u,0x0c07c5c8u,0x0c07c5cau,0x0c07c5ccu,0x0c07c5ceu,0x0c07c5d0u,0x0c07c5d2u,0x0c07c5d4u,0x0c07c5d6u,0x0c07c5d8u,0x0c07c5dau,
0x0c07c5dcu,0x0c07c5deu,0x0c07c5e0u,0x0c07c5e2u,0x0c07c5e4u,0x0c07c5e6u,0x0c08c80eu,0x0c08c810u,0x0c08c812u,0x0c08c814u,0x0c08c816u,0x0c08c818u,0x0c08c81au,0x0c08c81cu,0x0c08c81eu,0x0c08c820u,
0x0c08c822u,0x0c08c824u,0x0c08c826u,0x0c08c828u,0x0c08c82eu,0x0c08c830u,0x0c08c832u,0x0c08c834u,0x0c08c836u,0x0c08c838u,0x0c08c83au,0x0c08c83cu,0x0c08c83eu,0x0c08c840u,0x0c08c842u,0x0c08c844u,
0x0c08c846u,0x0c08c848u,0x0c08c84au,0x0c08c84cu,0x0c08c84eu,0x0c08c850u,0x0c08c852u,0x0c08c854u,0x0c08c856u,0x0c08c858u,0x0c08c85au,0x0c08c85cu,0x0c08c87cu,0x0c08c87eu,0x0c08c880u,0x0c08c882u,
0x0c08c884u,0x0c08c886u,0x0c08c888u,0x0c08c88au,0x0c08c88cu,0x0c08c88eu,0x0c08c890u,0x0c08c892u,0x0c08c894u,0x0c08c896u,0x0c08c898u,0x0c08c89au,0x0c08c89cu,0x0c08c89eu,0x0c08c8a0u,0x0c08c8a2u,
0x0c08c8a4u,0x0c08c8a6u,0x0c08c8a8u,0x0c08c8aau,0x0c08c8acu,0x0c08c8aeu,0x0c08c8b0u,0x0c08c8b2u,0x0c08c8b4u,0x0c08c8b6u,0x0c08c8b8u,0x0c08c8bau,0x0c08c8bcu,0x0c08c8beu,0x0c08c8c0u,0x0c08c8c2u,
0x0c08c8c4u,0x0c08c8c6u,0x0c08c8c8u,0x0c08c8cau,0x0c08c8ccu,0x0c08c8ceu,0x0c08c8d0u,0x0c08c8d2u,0x0c08c8d4u,0x0c08c8d6u,0x0c08c8d8u,0x0c08c8dau,0x0c08c8dcu,0x0c08c8deu,0x0c08c8e0u,0x0c08c8e2u,
0x0c08c8e4u,0x0c08c8e6u,0x0c08c8e8u,0x0c08c8eau,0x0c08c8ecu,0x0c08c8eeu,0x0c08c8f0u,0x0c08c8f2u,0x0c08c8f4u,0x0c08c8f6u,0x0c08c8f8u,0x0c08c8fau,0x0c08c8fcu,0x0c08c8feu,0x0c08c900u,0x0c08c990u,
0x0c08c992u,0x0c08c994u,0x0c08c996u,0x0c08c998u,0x0c08c99au,0x0c08c99cu,0x0c08c99eu,0x0c08c9a0u,0x0c08c9a2u,0x0c08c9a4u,0x0c08c9a6u,0x0c08c9a8u,0x0c08c9aau,0x0c08c9acu,0x0c08c9aeu,0x0c08c9b0u,
0x0c08c9b2u,0x0c08c9b4u,0x0c08c9b6u,0x0c08c9b8u,0x0c08c9bau,0x0c08c9bcu,0x0c08c9beu,0x0c08c9c0u,0x0c08c9c2u,0x0c08c9c4u,0x0c08c9c6u,0x0c08c9c8u,0x0c08c9cau,0x0c08c9ccu,0x0c08c9ceu,0x0c08c9d0u,
0x0c08c9d2u,0x0c08c9d4u,0x0c08c9d6u,0x0c08c9d8u,0x0c08c9dau,0x0c08c9dcu,0x0c08c9deu,0x0c08c9e0u,0x0c08c9e2u,0x0c08c9e4u,0x0c08c9e6u,0x0c08c9e8u,0x0c08c9eau,0x0c08c9ecu,0x0c08c9eeu,0x0c08c9f0u,
0x0c08c9f2u,0x0c08c9f4u,0x0c08c9f6u,0x0c08c9f8u,0x0c08c9fau,0x0c08c9fcu,0x0c08c9feu,0x0c08ca00u,0x0c08ca02u,0x0c08ca04u,0x0c08ca06u,0x0c08ca08u,0x0c08ca0au,0x0c08ca0cu,0x0c08ca0eu,0x0c08ca10u,
0x0c08ca12u,0x0c08ca14u,0x0c08ca16u,0x0c08ca18u,0x0c08ca1au,0x0c08ca1cu,0x0c08ca1eu,0x0c08ca20u,0x0c08ca22u,0x0c08ca24u,0x0c08ca26u,0x0c08ca28u,0x0c08ca2au,0x0c08ca2cu,0x0c08ca54u,0x0c08ca56u,
0x0c08ca58u,0x0c08ca5au,0x0c08ca5cu,0x0c08ca5eu,0x0c08ca60u,0x0c08ca62u,0x0c08ca64u,0x0c08ca66u,0x0c08ca68u,0x0c08ca6au,0x0c08ca6cu,0x0c08ca6eu,0x0c08ca70u,0x0c08ca72u,0x0c08ca74u,0x0c08ca76u,
0x0c08ca78u,0x0c08ca7au,0x0c08ca7cu,0x0c08ca7eu,0x0c08ca80u,0x0c08ca82u,0x0c08ca84u,0x0c08ca86u,0x0c08ca88u,0x0c08ca8au,0x0c08ca8cu,0x0c08ca8eu,0x0c08ca90u,0x0c08ca92u,0x0c08ca94u,0x0c08ca96u,
0x0c08ca98u,0x0c08ca9au,0x0c08ca9cu,0x0c08ca9eu,0x0c08caa0u,0x0c08caa2u,0x0c08caa4u,0x0c08caa6u,0x0c08caa8u,0x0c08caaau,0x0c08caacu,0x0c08caaeu,0x0c08cab0u,0x0c08cab2u,0x0c08cab4u,0x0c08cab6u,
0x0c08cab8u,0x0c08cabau,0x0c08cabcu,0x0c08cabeu,0x0c08cac0u,0x0c08cac2u,0x0c08cac4u,0x0c08cac6u,0x0c08cac8u,0x0c08cacau,0x0c08caccu,0x0c08caceu,0x0c08cad0u,0x0c08cad2u,0x0c09635au,0x0c09635cu,
0x0c09635eu,0x0c096360u,0x0c096362u,0x0c096364u,0x0c096366u,0x0c096368u,0x0c09636au,0x0c09636cu,0x0c09636eu,0x0c096370u,0x0c096372u,0x0c096374u,0x0c096376u,0x0c096378u,0x0c09637au,0x0c09637cu,
0x0c09637eu,0x0c096380u,0x0c096382u,0x0c096384u,0x0c096386u,0x0c096388u,0x0c09638au,0x0c09638cu,0x0c09638eu,0x0c096390u,0x0c096392u,0x0c096394u,0x0c096396u,0x0c096398u,0x0c09639au,0x0c09639cu,
0x0c09639eu,0x0c0963a0u,0x0c0963a2u,0x0c0963a4u,0x0c0963a6u,0x0c0963a8u,0x0c0963aau,0x0c0963d0u,0x0c0963d2u,0x0c0963d4u,0x0c0963d6u,0x0c0963d8u,0x0c0963dau,0x0c0963dcu,0x0c0963deu,0x0c0963e0u,
0x0c0963e2u,0x0c0963e4u,0x0c0963e6u,0x0c0963e8u,0x0c0963eau,0x0c0963ecu,0x0c0963eeu,0x0c0963f0u,0x0c0963f2u,0x0c0963f4u,0x0c0963f6u,0x0c0963f8u,0x0c0963fau,0x0c0963fcu,0x0c0963feu,0x0c096400u,
0x0c096402u,0x0c096404u,0x0c096406u,0x0c096408u,0x0c09640au,0x0c09640cu,0x0c09640eu,0x0c096410u,0x0c096412u,0x0c096414u,0x0c096416u,0x0c096418u,0x0c09641au,0x0c09641cu,0x0c09641eu,0x0c096420u,
0x0c096422u,0x0c096424u,0x0c096426u,0x0c096428u,0x0c09642au,0x0c09642cu,0x0c09642eu,0x0c096430u,0x0c096432u,0x0c096434u,0x0c096436u,0x0c096438u,0x0c09643au,0x0c09643cu,0x0c09643eu,0x0c096440u,
0x0c096442u,0x0c096444u,0x0c096446u,0x0c096448u,0x0c09644au,0x0c09644cu,0x0c09644eu,0x0c096450u,0x0c096452u,0x0c096454u,0x0c096456u,0x0c096458u,0x0c09645au,0x0c09645cu,0x0c09645eu,0x0c096460u,
0x0c096462u,0x0c096464u,0x0c096466u,0x0c096468u,0x0c09646au,0x0c09646cu,0x0c09646eu,0x0c096470u,0x0c096472u,0x0c096474u,0x0c096476u,0x0c096478u,0x0c09647au,0x0c09647cu,0x0c09647eu,0x0c096480u,
0x0c096482u,0x0c096484u,0x0c096486u,0x0c096488u,0x0c09648au,0x0c09648cu,0x0c09648eu,0x0c096490u,0x0c096492u,0x0c096494u,0x0c096496u,0x0c096498u,0x0c09649au,0x0c09649cu,0x0c09649eu,0x0c0964a0u,
0x0c0964a2u,0x0c0964a4u,0x0c0964a6u,0x0c0964a8u,0x0c0964aau,0x0c0964acu,0x0c0964aeu,0x0c0964b0u,0x0c0964b2u,0x0c0964b4u,0x0c0964b6u,0x0c0964b8u,0x0c0964bau,0x0c0964bcu,0x0c0964beu,0x0c0964c0u,
0x0c0964c2u,0x0c09650cu,0x0c09650eu,0x0c096510u,0x0c096512u,0x0c096514u,0x0c096516u,0x0c096518u,0x0c09651au,0x0c09651cu,0x0c09651eu,0x0c096520u,0x0c096522u,0x0c096524u,0x0c096526u,0x0c096528u,
0x0c09652au,0x0c09652cu,0x0c09652eu,0x0c096530u,0x0c096532u,0x0c096534u,0x0c096536u,0x0c096538u,0x0c09653au,0x0c09653cu,0x0c09653eu,0x0c096540u,0x0c096542u,0x0c096544u,0x0c096546u,0x0c096548u,
0x0c09654au,0x0c09654cu,0x0c09654eu,0x0c096550u,0x0c096552u,0x0c096554u,0x0c096556u,0x0c096558u,0x0c09655au,0x0c09655cu,0x0c09655eu,0x0c096560u,0x0c096562u,0x0c096564u,0x0c096566u,0x0c096568u,
0x0c09656au,0x0c09656cu,0x0c09656eu,0x0c096570u,0x0c096572u,0x0c096574u,0x0c096576u,0x0c096578u,0x0c09657au,0x0c09657cu,0x0c09657eu,0x0c096580u,0x0c096582u,0x0c096584u,0x0c096586u,0x0c096588u,
0x0c09658au,0x0c09658cu,0x0c09658eu,0x0c096590u,0x0c096592u,0x0c096594u,0x0c096596u,0x0c096598u,0x0c09659au,0x0c09659cu,0x0c09659eu,0x0c0965a0u,0x0c0965a2u,0x0c0965a4u,0x0c0965a6u,0x0c0965a8u,
0x0c0965aau,0x0c0965acu,0x0c0965aeu,0x0c0965b0u,0x0c0965b2u,0x0c0965b4u,0x0c0965b6u,0x0c0965b8u,0x0c0965bau,0x0c0965bcu,0x0c0965beu,0x0c0965c0u,0x0c0965c2u,0x0c0965c4u,0x0c0965c6u,0x0c0965c8u,
0x0c0965cau,0x0c0965ccu,0x0c0965ecu,0x0c0965eeu,0x0c0965f0u,0x0c0965f2u,0x0c0965f4u,0x0c0965f6u,0x0c0965f8u,0x0c0965fau,0x0c0965fcu,0x0c0965feu,0x0c096600u,0x0c096602u,0x0c096604u,0x0c096606u,
0x0c096608u,0x0c09660au,0x0c09660cu,0x0c09660eu,0x0c096610u,0x0c096612u,0x0c096614u,0x0c096616u,0x0c096618u,0x0c09661au,0x0c09661cu,0x0c09661eu,0x0c096620u,0x0c096622u,0x0c096624u,0x0c096626u,
0x0c096628u,0x0c09662au,0x0c09662cu,0x0c09662eu,0x0c096630u,0x0c096632u,0x0c096634u,0x0c096636u,0x0c096638u,0x0c09663au,0x0c09663cu,0x0c09663eu,0x0c096640u,0x0c096642u,0x0c096644u,0x0c096646u,
0x0c096648u,0x0c09664au,0x0c0a2e2cu,0x0c0a2e2eu,0x0c0a2e30u,0x0c0a2e32u,0x0c0a2e34u,0x0c0a2e36u,0x0c0a2e38u,0x0c0a2e3au,0x0c0a2e3cu,0x0c0a2e3eu,0x0c0a2e40u,0x0c0a2e42u,0x0c0a2e44u,0x0c0a2e46u,
0x0c0a30b4u,0x0c0a30b6u,0x0c0a30b8u,0x0c0a30bau,0x0c0a30bcu,0x0c0a30beu,0x0c0a30c0u,0x0c0a30c2u,0x0c0a30c4u,0x0c0a30c6u,0x0c0a30c8u,0x0c0a30cau,0x0c0a30ccu,0x0c0a30ceu,0x0c0a30d0u,0x0c0a30d2u,
0x0c0a30d4u,0x0c0a30d6u,0x0c0a30d8u,0x0c0a30dau,0x0c0a30dcu,0x0c0a30deu,0x0c0a30e0u,0x0c0a30e2u,0x0c0a30e4u,0x0c0a30e6u,0x0c0a30e8u,0x0c0a30eau,0x0c0a30ecu,0x0c0a30eeu,0x0c0a30f0u,0x0c0a30f2u,
0x0c0a30f4u,0x0c0a30f6u,0x0c0a30f8u,0x0c0a30fau,0x0c0a30fcu,0x0c0a30feu,0x0c0a3100u,0x0c0a3102u,0x0c0a3104u,0x0c0a3106u,0x0c0a3108u,0x0c0a310au,0x0c0a310cu,0x0c0a310eu,0x0c0a3110u,0x0c0a3112u,
0x0c0a3114u,0x0c0a3116u,0x0c0a3118u,0x0c0a311au,0x0c0a311cu,0x0c0a311eu,0x0c0a3120u,0x0c0a3122u,0x0c0a3124u,0x0c0a3126u,0x0c0a3128u,0x0c0a312au,0x0c0a312cu,0x0c0a312eu,0x0c0a3130u,0x0c0a3132u,
0x0c0a3134u,0x0c0a3136u,0x0c0a3138u,0x0c0a313au,0x0c0a313cu,0x0c0a313eu,0x0c0a3140u,0x0c0a3142u,0x0c0a3144u,0x0c0a3146u,0x0c0a3148u,0x0c0a314au,0x0c0a314cu,0x0c0a314eu,0x0c0a3150u,0x0c0a3152u,
0x0c0a3154u,0x0c0a3156u,0x0c0a3158u,0x0c0a315au,0x0c0a315cu,0x0c0a315eu,0x0c0a3160u,0x0c0a3162u,0x0c0a3164u,0x0c0a3166u,0x0c0a3168u,0x0c0a316au,0x0c0a316cu,0x0c0a316eu,0x0c0a3170u,0x0c0a3172u,
0x0c0a3174u,0x0c0a3176u,0x0c0a3178u,0x0c0a317au,0x0c0a317cu,0x0c0a317eu,0x0c0a3180u,0x0c0a3182u,0x0c0a3184u,0x0c0a3186u,0x0c0a3188u,0x0c0a318au,0x0c0a318cu,0x0c0a318eu,0x0c0a3190u,0x0c0a3192u,
0x0c0a3194u,0x0c0a3196u,0x0c0a3198u,0x0c0a319au,0x0c0a319cu,0x0c0a319eu,0x0c0a31a0u,0x0c0a31a2u,0x0c0a31a4u,0x0c0a31a6u,0x0c0a31a8u,0x0c0a31aau,0x0c0a31acu,0x0c0a31aeu,0x0c0a31b0u,0x0c0a31b2u,
0x0c0a31b4u,0x0c0a31b6u,0x0c0a31b8u,0x0c0a31bau,0x0c0a31bcu,0x0c0a31beu,0x0c0a31c0u,0x0c0a31c2u,0x0c0a31c4u,0x0c0a31c6u,0x0c0a31c8u,0x0c0a3226u,0x0c0a3228u,0x0c0a322au,0x0c0a322cu,0x0c0a322eu,
0x0c0a3230u,0x0c0a3232u,0x0c0a3234u,0x0c0a3236u,0x0c0a3238u,0x0c0a323au,0x0c0a7f68u,0x0c0a7f6au,0x0c0a7f6cu,0x0c0a7f6eu,0x0c0a7f70u,0x0c0a7f72u,0x0c0a7f74u,0x0c0a7f76u,0x0c0a7f78u,0x0c0a7f7au,
0x0c0a7f7cu,0x0c0a7f7eu,0x0c0a7f80u,0x0c0a7f82u,0x0c0a7f84u,0x0c0a7f86u,0x0c0a7f88u,0x0c0a7f8au,0x0c0a7f8cu,0x0c0a7f8eu,0x0c0a7f90u,0x0c0a7f92u,0x0c0a7f94u,0x0c0a7f96u,0x0c0a7f98u,0x0c0a7f9au,
0x0c0a7f9cu,0x0c0a7f9eu,0x0c0a7fa0u,0x0c0a7fa2u,0x0c0a7fa4u,0x0c0a7fc0u,0x0c0a7fc2u,0x0c0a7fc4u,0x0c0a7fc6u,0x0c0a7fc8u,0x0c0a7fcau,0x0c0a7fccu,0x0c0a7fceu,0x0c0a7fd0u,0x0c0a7fd2u,0x0c0a7fd4u,
0x0c0a7fd6u,0x0c0a7fd8u,0x0c0a7fdau,0x0c0a7fdcu,0x0c0a7fdeu,0x0c0a7fe0u,0x0c0a7fe2u,0x0c0a7fe4u,0x0c0a7fe6u,0x0c0a7fe8u,0x0c0a7feau,0x0c0a7fecu,0x0c0a7feeu,0x0c0a7ff0u,0x0c0a7ff2u,0x0c0a7ff4u,
0x0c0a7ff6u,0x0c0a7ff8u,0x0c0a7ffau,0x0c0a7ffcu,0x0c0a7ffeu,0x0c0a8000u,0x0c0a8002u,0x0c0a8004u,0x0c0a8006u,0x0c0a8008u,0x0c0a800au,0x0c0a800cu,0x0c0a800eu,0x0c0a8010u,0x0c0a8012u,0x0c0a8014u,
0x0c0a8016u,0x0c0a8018u,0x0c0a801au,0x0c0a801cu,0x0c0a801eu,0x0c0a8020u,0x0c0a8022u,0x0c0a8024u,0x0c0a8026u,0x0c0a8028u,0x0c0a802au,0x0c0a802cu,0x0c0a802eu,0x0c0a8030u,0x0c0a8032u,0x0c0a8034u,
0x0c0a8036u,0x0c0a8038u,0x0c0a803au,0x0c0cc2d6u,0x0c0cc2d8u,0x0c0cc2dau,0x0c0cc2dcu,0x0c0cc2deu,0x0c0cc2e0u,0x0c0cc2e2u,0x0c0cc2e4u,0x0c0cc2e6u,0x0c0cc2e8u,0x0c0cc2eau,0x0c0cc2ecu,0x0c0cc2eeu,
0x0c0cc2f0u,0x0c0cc2f2u,0x0c0cc2f4u,0x0c0cc2f6u,0x0c0cc2f8u,0x0c0cc2fau,0x0c0cc2fcu,0x0c0cc2feu,0x0c0cc300u,0x0c0cc302u,0x0c0cc304u,0x0c0cc306u,0x0c0cc308u,0x0c0cc30au,0x0c0cc30cu,0x0c0cc30eu,
0x0c0cc310u,0x0c0cc312u,0x0c0cc314u,0x0c0cc316u,0x0c0cc318u,0x0c0cc31au,0x0c0cc31cu,0x0c0cc31eu,0x0c0cc320u,0x0c0cc322u,0x0c0cc324u,0x0c0cc326u,0x0c0cc328u,0x0c0cc32au,0x0c0cc32cu,0x0c0cc32eu,
0x0c0cc330u,0x0c0cc332u,
};
int vf3_motion_unowned_extra_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
