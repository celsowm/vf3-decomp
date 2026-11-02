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
int vf3_away_batch199_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f83cu: goto P_0c09f83c;
case 0x0c09f83eu: goto P_0c09f83e;
case 0x0c09f840u: goto P_0c09f840;
case 0x0c09f842u: goto P_0c09f842;
case 0x0c09f844u: goto P_0c09f844;
case 0x0c09f846u: goto P_0c09f846;
case 0x0c09f848u: goto P_0c09f848;
case 0x0c09f84au: goto P_0c09f84a;
case 0x0c09f84cu: goto P_0c09f84c;
case 0x0c09f84eu: goto P_0c09f84e;
case 0x0c09f850u: goto P_0c09f850;
case 0x0c09f852u: goto P_0c09f852;
case 0x0c09f854u: goto P_0c09f854;
case 0x0c09f856u: goto P_0c09f856;
case 0x0c09f858u: goto P_0c09f858;
case 0x0c09f85au: goto P_0c09f85a;
case 0x0c09f85cu: goto P_0c09f85c;
case 0x0c09f85eu: goto P_0c09f85e;
case 0x0c09f860u: goto P_0c09f860;
case 0x0c09f862u: goto P_0c09f862;
case 0x0c09f864u: goto P_0c09f864;
case 0x0c09f866u: goto P_0c09f866;
case 0x0c09f868u: goto P_0c09f868;
case 0x0c09f86au: goto P_0c09f86a;
case 0x0c09f86cu: goto P_0c09f86c;
case 0x0c09f86eu: goto P_0c09f86e;
case 0x0c09f870u: goto P_0c09f870;
case 0x0c09f872u: goto P_0c09f872;
case 0x0c09f874u: goto P_0c09f874;
case 0x0c09f876u: goto P_0c09f876;
case 0x0c09f878u: goto P_0c09f878;
case 0x0c09f87au: goto P_0c09f87a;
case 0x0c09f87cu: goto P_0c09f87c;
case 0x0c09f87eu: goto P_0c09f87e;
case 0x0c09f880u: goto P_0c09f880;
case 0x0c09f882u: goto P_0c09f882;
case 0x0c09f884u: goto P_0c09f884;
case 0x0c09f886u: goto P_0c09f886;
case 0x0c09f888u: goto P_0c09f888;
case 0x0c09f88au: goto P_0c09f88a;
case 0x0c09f88cu: goto P_0c09f88c;
case 0x0c09f88eu: goto P_0c09f88e;
case 0x0c09f8d8u: goto P_0c09f8d8;
case 0x0c09f8dau: goto P_0c09f8da;
case 0x0c09f8dcu: goto P_0c09f8dc;
case 0x0c09f8deu: goto P_0c09f8de;
case 0x0c09f8e0u: goto P_0c09f8e0;
case 0x0c09f8e2u: goto P_0c09f8e2;
case 0x0c09f8e4u: goto P_0c09f8e4;
case 0x0c09f8e6u: goto P_0c09f8e6;
case 0x0c09f8e8u: goto P_0c09f8e8;
case 0x0c09f8eau: goto P_0c09f8ea;
case 0x0c09f8ecu: goto P_0c09f8ec;
case 0x0c09f8eeu: goto P_0c09f8ee;
case 0x0c09f8f0u: goto P_0c09f8f0;
case 0x0c09f8f2u: goto P_0c09f8f2;
case 0x0c09f8f4u: goto P_0c09f8f4;
case 0x0c09f8f6u: goto P_0c09f8f6;
case 0x0c09f8f8u: goto P_0c09f8f8;
case 0x0c09f8fau: goto P_0c09f8fa;
case 0x0c09f8fcu: goto P_0c09f8fc;
case 0x0c09f8feu: goto P_0c09f8fe;
case 0x0c09f900u: goto P_0c09f900;
case 0x0c09f902u: goto P_0c09f902;
case 0x0c09f904u: goto P_0c09f904;
case 0x0c09f906u: goto P_0c09f906;
case 0x0c09f908u: goto P_0c09f908;
case 0x0c09f90au: goto P_0c09f90a;
case 0x0c09f90cu: goto P_0c09f90c;
case 0x0c09f90eu: goto P_0c09f90e;
case 0x0c09f910u: goto P_0c09f910;
case 0x0c09f912u: goto P_0c09f912;
case 0x0c09f914u: goto P_0c09f914;
case 0x0c09f916u: goto P_0c09f916;
case 0x0c09f918u: goto P_0c09f918;
case 0x0c09f91au: goto P_0c09f91a;
case 0x0c09f91cu: goto P_0c09f91c;
case 0x0c09f91eu: goto P_0c09f91e;
case 0x0c09f920u: goto P_0c09f920;
case 0x0c09f922u: goto P_0c09f922;
case 0x0c09f924u: goto P_0c09f924;
case 0x0c09f926u: goto P_0c09f926;
case 0x0c09f928u: goto P_0c09f928;
case 0x0c09f92au: goto P_0c09f92a;
case 0x0c09f92cu: goto P_0c09f92c;
case 0x0c09f92eu: goto P_0c09f92e;
case 0x0c09f930u: goto P_0c09f930;
case 0x0c09f932u: goto P_0c09f932;
case 0x0c09f934u: goto P_0c09f934;
case 0x0c09f936u: goto P_0c09f936;
case 0x0c09f938u: goto P_0c09f938;
case 0x0c09f93au: goto P_0c09f93a;
case 0x0c09f93cu: goto P_0c09f93c;
case 0x0c09f93eu: goto P_0c09f93e;
case 0x0c09f940u: goto P_0c09f940;
case 0x0c09f942u: goto P_0c09f942;
case 0x0c09f944u: goto P_0c09f944;
case 0x0c09f946u: goto P_0c09f946;
case 0x0c09f948u: goto P_0c09f948;
case 0x0c09f94au: goto P_0c09f94a;
case 0x0c09f94cu: goto P_0c09f94c;
case 0x0c09f94eu: goto P_0c09f94e;
case 0x0c09f950u: goto P_0c09f950;
case 0x0c09f952u: goto P_0c09f952;
case 0x0c09f954u: goto P_0c09f954;
case 0x0c09f956u: goto P_0c09f956;
case 0x0c09f958u: goto P_0c09f958;
case 0x0c09f95au: goto P_0c09f95a;
case 0x0c09f95cu: goto P_0c09f95c;
case 0x0c09f95eu: goto P_0c09f95e;
case 0x0c09f960u: goto P_0c09f960;
case 0x0c09f962u: goto P_0c09f962;
case 0x0c09f964u: goto P_0c09f964;
case 0x0c09f966u: goto P_0c09f966;
case 0x0c09f968u: goto P_0c09f968;
case 0x0c09f96au: goto P_0c09f96a;
case 0x0c09f96cu: goto P_0c09f96c;
case 0x0c09f96eu: goto P_0c09f96e;
case 0x0c09f970u: goto P_0c09f970;
case 0x0c09f972u: goto P_0c09f972;
case 0x0c09f974u: goto P_0c09f974;
case 0x0c09f976u: goto P_0c09f976;
case 0x0c09f978u: goto P_0c09f978;
case 0x0c09f97au: goto P_0c09f97a;
case 0x0c09f97cu: goto P_0c09f97c;
case 0x0c09f97eu: goto P_0c09f97e;
case 0x0c09f980u: goto P_0c09f980;
case 0x0c09f982u: goto P_0c09f982;
case 0x0c09fc8eu: goto P_0c09fc8e;
case 0x0c09fc90u: goto P_0c09fc90;
case 0x0c09fc92u: goto P_0c09fc92;
case 0x0c09fc94u: goto P_0c09fc94;
case 0x0c09fc96u: goto P_0c09fc96;
case 0x0c09fc98u: goto P_0c09fc98;
case 0x0c09fc9au: goto P_0c09fc9a;
case 0x0c09fc9cu: goto P_0c09fc9c;
case 0x0c09fc9eu: goto P_0c09fc9e;
case 0x0c09fca0u: goto P_0c09fca0;
case 0x0c09fca2u: goto P_0c09fca2;
case 0x0c09fca4u: goto P_0c09fca4;
case 0x0c09fca6u: goto P_0c09fca6;
case 0x0c09fca8u: goto P_0c09fca8;
case 0x0c09fcaau: goto P_0c09fcaa;
case 0x0c09fcacu: goto P_0c09fcac;
case 0x0c09fcaeu: goto P_0c09fcae;
case 0x0c09fcb0u: goto P_0c09fcb0;
case 0x0c09fcb2u: goto P_0c09fcb2;
case 0x0c09fcb4u: goto P_0c09fcb4;
case 0x0c09fcb6u: goto P_0c09fcb6;
case 0x0c09fcb8u: goto P_0c09fcb8;
case 0x0c09fcbau: goto P_0c09fcba;
case 0x0c09fcbcu: goto P_0c09fcbc;
case 0x0c09fcbeu: goto P_0c09fcbe;
case 0x0c09fcc0u: goto P_0c09fcc0;
case 0x0c09fcc2u: goto P_0c09fcc2;
case 0x0c09fcc4u: goto P_0c09fcc4;
case 0x0c09fcc6u: goto P_0c09fcc6;
case 0x0c09fcc8u: goto P_0c09fcc8;
case 0x0c09fccau: goto P_0c09fcca;
case 0x0c09fcccu: goto P_0c09fccc;
case 0x0c09fcceu: goto P_0c09fcce;
case 0x0c09fcd0u: goto P_0c09fcd0;
case 0x0c09fcf4u: goto P_0c09fcf4;
case 0x0c09fcf6u: goto P_0c09fcf6;
case 0x0c09fcf8u: goto P_0c09fcf8;
case 0x0c09fcfau: goto P_0c09fcfa;
case 0x0c09fcfcu: goto P_0c09fcfc;
case 0x0c09fcfeu: goto P_0c09fcfe;
case 0x0c09fd00u: goto P_0c09fd00;
case 0x0c09fd02u: goto P_0c09fd02;
case 0x0c09fd04u: goto P_0c09fd04;
case 0x0c09fd06u: goto P_0c09fd06;
case 0x0c09fd08u: goto P_0c09fd08;
case 0x0c09fd0au: goto P_0c09fd0a;
case 0x0c09fd0cu: goto P_0c09fd0c;
case 0x0c09fd0eu: goto P_0c09fd0e;
case 0x0c09fd10u: goto P_0c09fd10;
case 0x0c09fd12u: goto P_0c09fd12;
case 0x0c09fd14u: goto P_0c09fd14;
case 0x0c09fd16u: goto P_0c09fd16;
case 0x0c09fd18u: goto P_0c09fd18;
case 0x0c09fd1au: goto P_0c09fd1a;
case 0x0c09fd1cu: goto P_0c09fd1c;
case 0x0c09fd1eu: goto P_0c09fd1e;
case 0x0c09fd20u: goto P_0c09fd20;
case 0x0c09fd22u: goto P_0c09fd22;
case 0x0c09fd24u: goto P_0c09fd24;
case 0x0c09fd26u: goto P_0c09fd26;
case 0x0c09fd28u: goto P_0c09fd28;
case 0x0c09fd2au: goto P_0c09fd2a;
case 0x0c09fd2cu: goto P_0c09fd2c;
case 0x0c09fd2eu: goto P_0c09fd2e;
case 0x0c09fd30u: goto P_0c09fd30;
case 0x0c09fd32u: goto P_0c09fd32;
case 0x0c09fd34u: goto P_0c09fd34;
case 0x0c09fd36u: goto P_0c09fd36;
case 0x0c09fd38u: goto P_0c09fd38;
case 0x0c09fd3au: goto P_0c09fd3a;
case 0x0c09fd3cu: goto P_0c09fd3c;
case 0x0c09fd3eu: goto P_0c09fd3e;
case 0x0c09fd40u: goto P_0c09fd40;
case 0x0c09fd42u: goto P_0c09fd42;
case 0x0c09fd44u: goto P_0c09fd44;
case 0x0c09fd46u: goto P_0c09fd46;
case 0x0c09fd48u: goto P_0c09fd48;
case 0x0c09fd4au: goto P_0c09fd4a;
case 0x0c09fd4cu: goto P_0c09fd4c;
case 0x0c09fd4eu: goto P_0c09fd4e;
case 0x0c09fd50u: goto P_0c09fd50;
case 0x0c09fd52u: goto P_0c09fd52;
case 0x0c09fd54u: goto P_0c09fd54;
case 0x0c09fd56u: goto P_0c09fd56;
case 0x0c09fd58u: goto P_0c09fd58;
case 0x0c09fd5au: goto P_0c09fd5a;
case 0x0c09fd5cu: goto P_0c09fd5c;
case 0x0c09fd5eu: goto P_0c09fd5e;
case 0x0c09fd60u: goto P_0c09fd60;
case 0x0c09fd62u: goto P_0c09fd62;
case 0x0c09fd64u: goto P_0c09fd64;
case 0x0c09fd66u: goto P_0c09fd66;
case 0x0c09fd68u: goto P_0c09fd68;
case 0x0c09fd6au: goto P_0c09fd6a;
case 0x0c09fd6cu: goto P_0c09fd6c;
case 0x0c09fd6eu: goto P_0c09fd6e;
case 0x0c09fd70u: goto P_0c09fd70;
case 0x0c09fd72u: goto P_0c09fd72;
case 0x0c09fd74u: goto P_0c09fd74;
case 0x0c09fd76u: goto P_0c09fd76;
case 0x0c09fd78u: goto P_0c09fd78;
case 0x0c09fd7au: goto P_0c09fd7a;
case 0x0c09fd7cu: goto P_0c09fd7c;
case 0x0c09fd7eu: goto P_0c09fd7e;
case 0x0c09fd80u: goto P_0c09fd80;
case 0x0c09fd82u: goto P_0c09fd82;
case 0x0c09fd84u: goto P_0c09fd84;
case 0x0c09fd86u: goto P_0c09fd86;
case 0x0c09fd88u: goto P_0c09fd88;
case 0x0c09fd8au: goto P_0c09fd8a;
case 0x0c09fd8cu: goto P_0c09fd8c;
case 0x0c09fd8eu: goto P_0c09fd8e;
case 0x0c09fd90u: goto P_0c09fd90;
case 0x0c09fd92u: goto P_0c09fd92;
case 0x0c09fd94u: goto P_0c09fd94;
case 0x0c09fd96u: goto P_0c09fd96;
case 0x0c09fd98u: goto P_0c09fd98;
case 0x0c09fd9au: goto P_0c09fd9a;
case 0x0c09fd9cu: goto P_0c09fd9c;
case 0x0c09fd9eu: goto P_0c09fd9e;
case 0x0c09fda0u: goto P_0c09fda0;
case 0x0c09fda2u: goto P_0c09fda2;
case 0x0c09fda4u: goto P_0c09fda4;
case 0x0c09fda6u: goto P_0c09fda6;
case 0x0c09fda8u: goto P_0c09fda8;
case 0x0c09fdaau: goto P_0c09fdaa;
case 0x0c09fdacu: goto P_0c09fdac;
case 0x0c09fdaeu: goto P_0c09fdae;
case 0x0c09fdb0u: goto P_0c09fdb0;
case 0x0c09fdb2u: goto P_0c09fdb2;
case 0x0c09fdb4u: goto P_0c09fdb4;
case 0x0c09fdb6u: goto P_0c09fdb6;
case 0x0c09fdb8u: goto P_0c09fdb8;
case 0x0c09fdbau: goto P_0c09fdba;
case 0x0c09fdbcu: goto P_0c09fdbc;
case 0x0c09fdbeu: goto P_0c09fdbe;
case 0x0c09fdc0u: goto P_0c09fdc0;
case 0x0c09fdc2u: goto P_0c09fdc2;
case 0x0c09fdc4u: goto P_0c09fdc4;
case 0x0c09fdc6u: goto P_0c09fdc6;
case 0x0c09fdc8u: goto P_0c09fdc8;
case 0x0c09fdcau: goto P_0c09fdca;
case 0x0c09fdccu: goto P_0c09fdcc;
case 0x0c09fdceu: goto P_0c09fdce;
case 0x0c09fdd0u: goto P_0c09fdd0;
case 0x0c09fdd2u: goto P_0c09fdd2;
case 0x0c09fdd4u: goto P_0c09fdd4;
case 0x0c09fdd6u: goto P_0c09fdd6;
case 0x0c09fdd8u: goto P_0c09fdd8;
case 0x0c09fddau: goto P_0c09fdda;
case 0x0c09fddcu: goto P_0c09fddc;
case 0x0c09fddeu: goto P_0c09fdde;
case 0x0c09fde0u: goto P_0c09fde0;
case 0x0c09fde2u: goto P_0c09fde2;
case 0x0c09fde4u: goto P_0c09fde4;
case 0x0c09fde6u: goto P_0c09fde6;
case 0x0c09fde8u: goto P_0c09fde8;
case 0x0c09fdeau: goto P_0c09fdea;
case 0x0c09fdecu: goto P_0c09fdec;
case 0x0c09fdeeu: goto P_0c09fdee;
case 0x0c09fdf0u: goto P_0c09fdf0;
case 0x0c09fdf2u: goto P_0c09fdf2;
case 0x0c09fdf4u: goto P_0c09fdf4;
case 0x0c09fdf6u: goto P_0c09fdf6;
case 0x0c09fdf8u: goto P_0c09fdf8;
case 0x0c09fdfau: goto P_0c09fdfa;
case 0x0c09fdfcu: goto P_0c09fdfc;
case 0x0c09fdfeu: goto P_0c09fdfe;
case 0x0c09fe00u: goto P_0c09fe00;
case 0x0c09fe02u: goto P_0c09fe02;
case 0x0c09fe04u: goto P_0c09fe04;
case 0x0c09fe06u: goto P_0c09fe06;
case 0x0c09fe08u: goto P_0c09fe08;
case 0x0c09fe0au: goto P_0c09fe0a;
case 0x0c09fe0cu: goto P_0c09fe0c;
case 0x0c09fe0eu: goto P_0c09fe0e;
case 0x0c09fe10u: goto P_0c09fe10;
case 0x0c09fe12u: goto P_0c09fe12;
case 0x0c09fe14u: goto P_0c09fe14;
case 0x0c09fe16u: goto P_0c09fe16;
case 0x0c09fe18u: goto P_0c09fe18;
case 0x0c09fe1au: goto P_0c09fe1a;
case 0x0c09fe1cu: goto P_0c09fe1c;
case 0x0c09fe1eu: goto P_0c09fe1e;
case 0x0c09fe20u: goto P_0c09fe20;
case 0x0c09fe22u: goto P_0c09fe22;
case 0x0c09fe24u: goto P_0c09fe24;
case 0x0c09fe26u: goto P_0c09fe26;
case 0x0c0a8574u: goto P_0c0a8574;
case 0x0c0a8576u: goto P_0c0a8576;
case 0x0c0a8578u: goto P_0c0a8578;
case 0x0c0a857au: goto P_0c0a857a;
case 0x0c0a857cu: goto P_0c0a857c;
case 0x0c0a857eu: goto P_0c0a857e;
case 0x0c0a8580u: goto P_0c0a8580;
case 0x0c0a8582u: goto P_0c0a8582;
case 0x0c0a8584u: goto P_0c0a8584;
case 0x0c0a8586u: goto P_0c0a8586;
case 0x0c0a8588u: goto P_0c0a8588;
case 0x0c0a858au: goto P_0c0a858a;
case 0x0c0a858cu: goto P_0c0a858c;
case 0x0c0a858eu: goto P_0c0a858e;
case 0x0c0a8590u: goto P_0c0a8590;
case 0x0c0a8592u: goto P_0c0a8592;
case 0x0c0a8594u: goto P_0c0a8594;
case 0x0c0a8596u: goto P_0c0a8596;
case 0x0c0a8598u: goto P_0c0a8598;
case 0x0c0a859au: goto P_0c0a859a;
case 0x0c0a859cu: goto P_0c0a859c;
case 0x0c0a859eu: goto P_0c0a859e;
case 0x0c0a85a0u: goto P_0c0a85a0;
case 0x0c0a85a2u: goto P_0c0a85a2;
case 0x0c0a85a4u: goto P_0c0a85a4;
case 0x0c0a85a6u: goto P_0c0a85a6;
case 0x0c0a85a8u: goto P_0c0a85a8;
case 0x0c0a85aau: goto P_0c0a85aa;
case 0x0c0a85acu: goto P_0c0a85ac;
case 0x0c0a85aeu: goto P_0c0a85ae;
case 0x0c0a85b0u: goto P_0c0a85b0;
case 0x0c0a85b2u: goto P_0c0a85b2;
case 0x0c0a85b4u: goto P_0c0a85b4;
case 0x0c0a85b6u: goto P_0c0a85b6;
case 0x0c0a85b8u: goto P_0c0a85b8;
case 0x0c0a85bau: goto P_0c0a85ba;
case 0x0c0a85bcu: goto P_0c0a85bc;
case 0x0c0a85beu: goto P_0c0a85be;
case 0x0c0a85c0u: goto P_0c0a85c0;
case 0x0c0a85c2u: goto P_0c0a85c2;
case 0x0c0a85c4u: goto P_0c0a85c4;
case 0x0c0a85c6u: goto P_0c0a85c6;
case 0x0c0a85c8u: goto P_0c0a85c8;
case 0x0c0a85cau: goto P_0c0a85ca;
case 0x0c0a85ccu: goto P_0c0a85cc;
case 0x0c0a85ceu: goto P_0c0a85ce;
case 0x0c0a85d0u: goto P_0c0a85d0;
case 0x0c0a85d2u: goto P_0c0a85d2;
case 0x0c0a85d4u: goto P_0c0a85d4;
case 0x0c0a85d6u: goto P_0c0a85d6;
case 0x0c0a85d8u: goto P_0c0a85d8;
case 0x0c0a85dau: goto P_0c0a85da;
case 0x0c0a85dcu: goto P_0c0a85dc;
case 0x0c0a85deu: goto P_0c0a85de;
case 0x0c0a85e0u: goto P_0c0a85e0;
case 0x0c0a85e2u: goto P_0c0a85e2;
case 0x0c0a85e4u: goto P_0c0a85e4;
case 0x0c0a85e6u: goto P_0c0a85e6;
case 0x0c0a85e8u: goto P_0c0a85e8;
case 0x0c0a85eau: goto P_0c0a85ea;
case 0x0c0a85ecu: goto P_0c0a85ec;
case 0x0c0a85eeu: goto P_0c0a85ee;
case 0x0c0a85f0u: goto P_0c0a85f0;
case 0x0c0a85f2u: goto P_0c0a85f2;
case 0x0c0a85f4u: goto P_0c0a85f4;
case 0x0c0a85f6u: goto P_0c0a85f6;
case 0x0c0a85f8u: goto P_0c0a85f8;
case 0x0c0a85fau: goto P_0c0a85fa;
case 0x0c0a85fcu: goto P_0c0a85fc;
case 0x0c0a85feu: goto P_0c0a85fe;
case 0x0c0a8600u: goto P_0c0a8600;
case 0x0c0a8602u: goto P_0c0a8602;
case 0x0c0a8604u: goto P_0c0a8604;
case 0x0c0a8606u: goto P_0c0a8606;
case 0x0c0a8608u: goto P_0c0a8608;
case 0x0c0a860au: goto P_0c0a860a;
case 0x0c0a860cu: goto P_0c0a860c;
case 0x0c0a860eu: goto P_0c0a860e;
case 0x0c0a8610u: goto P_0c0a8610;
case 0x0c0a8612u: goto P_0c0a8612;
case 0x0c0a8614u: goto P_0c0a8614;
case 0x0c0a8616u: goto P_0c0a8616;
case 0x0c0a8618u: goto P_0c0a8618;
case 0x0c0a861au: goto P_0c0a861a;
case 0x0c0a861cu: goto P_0c0a861c;
case 0x0c0a861eu: goto P_0c0a861e;
case 0x0c0a8620u: goto P_0c0a8620;
case 0x0c0a8622u: goto P_0c0a8622;
case 0x0c0a8624u: goto P_0c0a8624;
case 0x0c0a8626u: goto P_0c0a8626;
case 0x0c0a8628u: goto P_0c0a8628;
case 0x0c0a862au: goto P_0c0a862a;
case 0x0c0a862cu: goto P_0c0a862c;
case 0x0c0a862eu: goto P_0c0a862e;
case 0x0c0a8630u: goto P_0c0a8630;
case 0x0c0a8632u: goto P_0c0a8632;
case 0x0c0a8634u: goto P_0c0a8634;
case 0x0c0a8636u: goto P_0c0a8636;
case 0x0c0a8638u: goto P_0c0a8638;
case 0x0c0a863au: goto P_0c0a863a;
case 0x0c0a863cu: goto P_0c0a863c;
case 0x0c0a863eu: goto P_0c0a863e;
case 0x0c0a8640u: goto P_0c0a8640;
case 0x0c0a8642u: goto P_0c0a8642;
case 0x0c0a8644u: goto P_0c0a8644;
case 0x0c0a8646u: goto P_0c0a8646;
case 0x0c0a8648u: goto P_0c0a8648;
case 0x0c0a864au: goto P_0c0a864a;
case 0x0c0a864cu: goto P_0c0a864c;
case 0x0c0a864eu: goto P_0c0a864e;
case 0x0c0a8650u: goto P_0c0a8650;
case 0x0c0a8652u: goto P_0c0a8652;
case 0x0c0a8654u: goto P_0c0a8654;
case 0x0c0a8656u: goto P_0c0a8656;
case 0x0c0a8658u: goto P_0c0a8658;
case 0x0c0a865au: goto P_0c0a865a;
case 0x0c0a865cu: goto P_0c0a865c;
case 0x0c0a865eu: goto P_0c0a865e;
case 0x0c0a8660u: goto P_0c0a8660;
case 0x0c0a8662u: goto P_0c0a8662;
case 0x0c0a8664u: goto P_0c0a8664;
case 0x0c0a8666u: goto P_0c0a8666;
case 0x0c0a8668u: goto P_0c0a8668;
case 0x0c0a866au: goto P_0c0a866a;
case 0x0c0a866cu: goto P_0c0a866c;
case 0x0c0a866eu: goto P_0c0a866e;
case 0x0c0a8670u: goto P_0c0a8670;
case 0x0c0a8672u: goto P_0c0a8672;
case 0x0c0a8674u: goto P_0c0a8674;
case 0x0c0a8676u: goto P_0c0a8676;
case 0x0c0a8678u: goto P_0c0a8678;
case 0x0c0a867au: goto P_0c0a867a;
case 0x0c0a867cu: goto P_0c0a867c;
case 0x0c0a867eu: goto P_0c0a867e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f83c: /* original e607, guest PC 0x0c09f83c */
if(!s->budget--) { s->failed_pc=0x0c09f83cu; return 0; }
r[6]=0x00000007u;
goto P_0c09f83e;
P_0c09f83e: /* original 6543, guest PC 0x0c09f83e */
if(!s->budget--) { s->failed_pc=0x0c09f83eu; return 0; }
r[5]=r[4];
goto P_0c09f840;
P_0c09f840: /* original 6753, guest PC 0x0c09f840 */
if(!s->budget--) { s->failed_pc=0x0c09f840u; return 0; }
r[7]=r[5];
goto P_0c09f842;
P_0c09f842: /* original 7708, guest PC 0x0c09f842 */
if(!s->budget--) { s->failed_pc=0x0c09f842u; return 0; }
r[7]+=0x00000008u;
goto P_0c09f844;
P_0c09f844: /* original f878, guest PC 0x0c09f844 */
if(!s->budget--) { s->failed_pc=0x0c09f844u; return 0; }
vf3_matrix_load(s,ram,8,r[7]);
goto P_0c09f846;
P_0c09f846: /* original 4610, guest PC 0x0c09f846 */
if(!s->budget--) { s->failed_pc=0x0c09f846u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c09f848;
P_0c09f848: /* original f74c, guest PC 0x0c09f848 */
if(!s->budget--) { s->failed_pc=0x0c09f848u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09f84a;
P_0c09f84a: /* original f958, guest PC 0x0c09f84a */
if(!s->budget--) { s->failed_pc=0x0c09f84au; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
goto P_0c09f84c;
P_0c09f84c: /* original f782, guest PC 0x0c09f84c */
if(!s->budget--) { s->failed_pc=0x0c09f84cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c09f84e;
P_0c09f84e: /* original f25c, guest PC 0x0c09f84e */
if(!s->budget--) { s->failed_pc=0x0c09f84eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09f850;
P_0c09f850: /* original f38c, guest PC 0x0c09f850 */
if(!s->budget--) { s->failed_pc=0x0c09f850u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c09f852;
P_0c09f852: /* original f292, guest PC 0x0c09f852 */
if(!s->budget--) { s->failed_pc=0x0c09f852u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c09f854;
P_0c09f854: /* original f85c, guest PC 0x0c09f854 */
if(!s->budget--) { s->failed_pc=0x0c09f854u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c09f856;
P_0c09f856: /* original f832, guest PC 0x0c09f856 */
if(!s->budget--) { s->failed_pc=0x0c09f856u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'*');
goto P_0c09f858;
P_0c09f858: /* original f37c, guest PC 0x0c09f858 */
if(!s->budget--) { s->failed_pc=0x0c09f858u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c09f85a;
P_0c09f85a: /* original f09c, guest PC 0x0c09f85a */
if(!s->budget--) { s->failed_pc=0x0c09f85au; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c09f85c;
P_0c09f85c: /* original f72c, guest PC 0x0c09f85c */
if(!s->budget--) { s->failed_pc=0x0c09f85cu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c09f85e;
P_0c09f85e: /* original f731, guest PC 0x0c09f85e */
if(!s->budget--) { s->failed_pc=0x0c09f85eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c09f860;
P_0c09f860: /* original f28c, guest PC 0x0c09f860 */
if(!s->budget--) { s->failed_pc=0x0c09f860u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c09f862;
P_0c09f862: /* original f24e, guest PC 0x0c09f862 */
if(!s->budget--) { s->failed_pc=0x0c09f862u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c09f864;
P_0c09f864: /* original f82c, guest PC 0x0c09f864 */
if(!s->budget--) { s->failed_pc=0x0c09f864u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c09f866;
P_0c09f866: /* original f57a, guest PC 0x0c09f866 */
if(!s->budget--) { s->failed_pc=0x0c09f866u; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09f868;
P_0c09f868: /* original f78a, guest PC 0x0c09f868 */
if(!s->budget--) { s->failed_pc=0x0c09f868u; return 0; }
vf3_matrix_store(s,ram,8,r[7]);
goto P_0c09f86a;
P_0c09f86a: /* original 8fe9, guest PC 0x0c09f86a */
if(!s->budget--) { s->failed_pc=0x0c09f86au; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000cu;
if(!cond) { goto P_0c09f840; }
goto P_0c09f86e;
P_0c09f86c: /* original 750c, guest PC 0x0c09f86c */
if(!s->budget--) { s->failed_pc=0x0c09f86cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f86e;
P_0c09f86e: /* original e058, guest PC 0x0c09f86e */
if(!s->budget--) { s->failed_pc=0x0c09f86eu; return 0; }
r[0]=0x00000058u;
goto P_0c09f870;
P_0c09f870: /* original f76c, guest PC 0x0c09f870 */
if(!s->budget--) { s->failed_pc=0x0c09f870u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c09f872;
P_0c09f872: /* original f446, guest PC 0x0c09f872 */
if(!s->budget--) { s->failed_pc=0x0c09f872u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c09f874;
P_0c09f874: /* original 902c, guest PC 0x0c09f874 */
if(!s->budget--) { s->failed_pc=0x0c09f874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f8d0u,2);
goto P_0c09f876;
P_0c09f876: /* original f460, guest PC 0x0c09f876 */
if(!s->budget--) { s->failed_pc=0x0c09f876u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c09f878;
P_0c09f878: /* original f546, guest PC 0x0c09f878 */
if(!s->budget--) { s->failed_pc=0x0c09f878u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c09f87a;
P_0c09f87a: /* original 70e8, guest PC 0x0c09f87a */
if(!s->budget--) { s->failed_pc=0x0c09f87au; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09f87c;
P_0c09f87c: /* original f346, guest PC 0x0c09f87c */
if(!s->budget--) { s->failed_pc=0x0c09f87cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f87e;
P_0c09f87e: /* original e058, guest PC 0x0c09f87e */
if(!s->budget--) { s->failed_pc=0x0c09f87eu; return 0; }
r[0]=0x00000058u;
goto P_0c09f880;
P_0c09f880: /* original f560, guest PC 0x0c09f880 */
if(!s->budget--) { s->failed_pc=0x0c09f880u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c09f882;
P_0c09f882: /* original f447, guest PC 0x0c09f882 */
if(!s->budget--) { s->failed_pc=0x0c09f882u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09f884;
P_0c09f884: /* original f730, guest PC 0x0c09f884 */
if(!s->budget--) { s->failed_pc=0x0c09f884u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c09f886;
P_0c09f886: /* original 9023, guest PC 0x0c09f886 */
if(!s->budget--) { s->failed_pc=0x0c09f886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f8d0u,2);
goto P_0c09f888;
P_0c09f888: /* original f457, guest PC 0x0c09f888 */
if(!s->budget--) { s->failed_pc=0x0c09f888u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c09f88a;
P_0c09f88a: /* original 70e8, guest PC 0x0c09f88a */
if(!s->budget--) { s->failed_pc=0x0c09f88au; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09f88c;
P_0c09f88c: /* original 000b, guest PC 0x0c09f88c */
if(!s->budget--) { s->failed_pc=0x0c09f88cu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,7,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c09f88e: /* original f477, guest PC 0x0c09f88e */
if(!s->budget--) { s->failed_pc=0x0c09f88eu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
if(!vf3_matrix_family(0x0c09f890u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f890u; return 0; } return 1;
P_0c09f8d8: /* original 907d, guest PC 0x0c09f8d8 */
if(!s->budget--) { s->failed_pc=0x0c09f8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9d6u,2);
goto P_0c09f8da;
P_0c09f8da: /* original 7ff0, guest PC 0x0c09f8da */
if(!s->budget--) { s->failed_pc=0x0c09f8dau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09f8dc;
P_0c09f8dc: /* original 034e, guest PC 0x0c09f8dc */
if(!s->budget--) { s->failed_pc=0x0c09f8dcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c09f8de;
P_0c09f8de: /* original 1f31, guest PC 0x0c09f8de */
if(!s->budget--) { s->failed_pc=0x0c09f8deu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f8e0;
P_0c09f8e0: /* original 907a, guest PC 0x0c09f8e0 */
if(!s->budget--) { s->failed_pc=0x0c09f8e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9d8u,2);
goto P_0c09f8e2;
P_0c09f8e2: /* original 074e, guest PC 0x0c09f8e2 */
if(!s->budget--) { s->failed_pc=0x0c09f8e2u; return 0; }
r[7]=read(ram,r[4]+r[0],4);
goto P_0c09f8e4;
P_0c09f8e4: /* original 70f9, guest PC 0x0c09f8e4 */
if(!s->budget--) { s->failed_pc=0x0c09f8e4u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c09f8e6;
P_0c09f8e6: /* original 034c, guest PC 0x0c09f8e6 */
if(!s->budget--) { s->failed_pc=0x0c09f8e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f8e8;
P_0c09f8e8: /* original 633c, guest PC 0x0c09f8e8 */
if(!s->budget--) { s->failed_pc=0x0c09f8e8u; return 0; }
r[3]=r[3]&255u;
goto P_0c09f8ea;
P_0c09f8ea: /* original 2f32, guest PC 0x0c09f8ea */
if(!s->budget--) { s->failed_pc=0x0c09f8eau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f8ec;
P_0c09f8ec: /* original d23c, guest PC 0x0c09f8ec */
if(!s->budget--) { s->failed_pc=0x0c09f8ecu; return 0; }
r[2]=read(ram,0x0c09f9e0u,4);
goto P_0c09f8ee;
P_0c09f8ee: /* original 51f1, guest PC 0x0c09f8ee */
if(!s->budget--) { s->failed_pc=0x0c09f8eeu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c09f8f0;
P_0c09f8f0: /* original 2129, guest PC 0x0c09f8f0 */
if(!s->budget--) { s->failed_pc=0x0c09f8f0u; return 0; }
r[1]&=r[2];
goto P_0c09f8f2;
P_0c09f8f2: /* original 1f11, guest PC 0x0c09f8f2 */
if(!s->budget--) { s->failed_pc=0x0c09f8f2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c09f8f4;
P_0c09f8f4: /* original 2279, guest PC 0x0c09f8f4 */
if(!s->budget--) { s->failed_pc=0x0c09f8f4u; return 0; }
r[2]&=r[7];
goto P_0c09f8f6;
P_0c09f8f6: /* original 1f22, guest PC 0x0c09f8f6 */
if(!s->budget--) { s->failed_pc=0x0c09f8f6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f8f8;
P_0c09f8f8: /* original 60f2, guest PC 0x0c09f8f8 */
if(!s->budget--) { s->failed_pc=0x0c09f8f8u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09f8fa;
P_0c09f8fa: /* original c980, guest PC 0x0c09f8fa */
if(!s->budget--) { s->failed_pc=0x0c09f8fau; return 0; }
r[0]&=128u;
goto P_0c09f8fc;
P_0c09f8fc: /* original 2f02, guest PC 0x0c09f8fc */
if(!s->budget--) { s->failed_pc=0x0c09f8fcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f8fe;
P_0c09f8fe: /* original d339, guest PC 0x0c09f8fe */
if(!s->budget--) { s->failed_pc=0x0c09f8feu; return 0; }
r[3]=read(ram,0x0c09f9e4u,4);
goto P_0c09f900;
P_0c09f900: /* original 2379, guest PC 0x0c09f900 */
if(!s->budget--) { s->failed_pc=0x0c09f900u; return 0; }
r[3]&=r[7];
goto P_0c09f902;
P_0c09f902: /* original 1f33, guest PC 0x0c09f902 */
if(!s->budget--) { s->failed_pc=0x0c09f902u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c09f904;
P_0c09f904: /* original 51f2, guest PC 0x0c09f904 */
if(!s->budget--) { s->failed_pc=0x0c09f904u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c09f906;
P_0c09f906: /* original d238, guest PC 0x0c09f906 */
if(!s->budget--) { s->failed_pc=0x0c09f906u; return 0; }
r[2]=read(ram,0x0c09f9e8u,4);
goto P_0c09f908;
P_0c09f908: /* original 2118, guest PC 0x0c09f908 */
if(!s->budget--) { s->failed_pc=0x0c09f908u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09f90a;
P_0c09f90a: /* original 8d39, guest PC 0x0c09f90a */
if(!s->budget--) { s->failed_pc=0x0c09f90au; return 0; }
cond=r[17]&1u;
r[7]&=r[2];
if(cond) { goto P_0c09f980; }
goto P_0c09f90e;
P_0c09f90c: /* original 2729, guest PC 0x0c09f90c */
if(!s->budget--) { s->failed_pc=0x0c09f90cu; return 0; }
r[7]&=r[2];
goto P_0c09f90e;
P_0c09f90e: /* original 53f1, guest PC 0x0c09f90e */
if(!s->budget--) { s->failed_pc=0x0c09f90eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f910;
P_0c09f910: /* original 2338, guest PC 0x0c09f910 */
if(!s->budget--) { s->failed_pc=0x0c09f910u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f912;
P_0c09f912: /* original 8b35, guest PC 0x0c09f912 */
if(!s->budget--) { s->failed_pc=0x0c09f912u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f980; }
goto P_0c09f914;
P_0c09f914: /* original e061, guest PC 0x0c09f914 */
if(!s->budget--) { s->failed_pc=0x0c09f914u; return 0; }
r[0]=0x00000061u;
goto P_0c09f916;
P_0c09f916: /* original 53f3, guest PC 0x0c09f916 */
if(!s->budget--) { s->failed_pc=0x0c09f916u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c09f918;
P_0c09f918: /* original 044c, guest PC 0x0c09f918 */
if(!s->budget--) { s->failed_pc=0x0c09f918u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f91a;
P_0c09f91a: /* original 2338, guest PC 0x0c09f91a */
if(!s->budget--) { s->failed_pc=0x0c09f91au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f91c;
P_0c09f91c: /* original 644c, guest PC 0x0c09f91c */
if(!s->budget--) { s->failed_pc=0x0c09f91cu; return 0; }
r[4]=r[4]&255u;
goto P_0c09f91e;
P_0c09f91e: /* original 8d01, guest PC 0x0c09f91e */
if(!s->budget--) { s->failed_pc=0x0c09f91eu; return 0; }
cond=r[17]&1u;
r[4]<<=2;
if(cond) { goto P_0c09f924; }
goto P_0c09f922;
P_0c09f920: /* original 4408, guest PC 0x0c09f920 */
if(!s->budget--) { s->failed_pc=0x0c09f920u; return 0; }
r[4]<<=2;
goto P_0c09f922;
P_0c09f922: /* original 7402, guest PC 0x0c09f922 */
if(!s->budget--) { s->failed_pc=0x0c09f922u; return 0; }
r[4]+=0x00000002u;
goto P_0c09f924;
P_0c09f924: /* original 2778, guest PC 0x0c09f924 */
if(!s->budget--) { s->failed_pc=0x0c09f924u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f926;
P_0c09f926: /* original 8900, guest PC 0x0c09f926 */
if(!s->budget--) { s->failed_pc=0x0c09f926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f92a; }
goto P_0c09f928;
P_0c09f928: /* original 7401, guest PC 0x0c09f928 */
if(!s->budget--) { s->failed_pc=0x0c09f928u; return 0; }
r[4]+=0x00000001u;
goto P_0c09f92a;
P_0c09f92a: /* original d030, guest PC 0x0c09f92a */
if(!s->budget--) { s->failed_pc=0x0c09f92au; return 0; }
r[0]=read(ram,0x0c09f9ecu,4);
goto P_0c09f92c;
P_0c09f92c: /* original 62f2, guest PC 0x0c09f92c */
if(!s->budget--) { s->failed_pc=0x0c09f92cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f92e;
P_0c09f92e: /* original 034c, guest PC 0x0c09f92e */
if(!s->budget--) { s->failed_pc=0x0c09f92eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f930;
P_0c09f930: /* original 2228, guest PC 0x0c09f930 */
if(!s->budget--) { s->failed_pc=0x0c09f930u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f932;
P_0c09f932: /* original 633c, guest PC 0x0c09f932 */
if(!s->budget--) { s->failed_pc=0x0c09f932u; return 0; }
r[3]=r[3]&255u;
goto P_0c09f934;
P_0c09f934: /* original 8d02, guest PC 0x0c09f934 */
if(!s->budget--) { s->failed_pc=0x0c09f934u; return 0; }
cond=r[17]&1u;
r[4]=r[3];
if(cond) { goto P_0c09f93c; }
goto P_0c09f938;
P_0c09f936: /* original 6433, guest PC 0x0c09f936 */
if(!s->budget--) { s->failed_pc=0x0c09f936u; return 0; }
r[4]=r[3];
goto P_0c09f938;
P_0c09f938: /* original e101, guest PC 0x0c09f938 */
if(!s->budget--) { s->failed_pc=0x0c09f938u; return 0; }
r[1]=0x00000001u;
goto P_0c09f93a;
P_0c09f93a: /* original 241a, guest PC 0x0c09f93a */
if(!s->budget--) { s->failed_pc=0x0c09f93au; return 0; }
r[4]^=r[1];
goto P_0c09f93c;
P_0c09f93c: /* original 2448, guest PC 0x0c09f93c */
if(!s->budget--) { s->failed_pc=0x0c09f93cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09f93e;
P_0c09f93e: /* original 8b07, guest PC 0x0c09f93e */
if(!s->budget--) { s->failed_pc=0x0c09f93eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f950; }
goto P_0c09f940;
P_0c09f940: /* original e03c, guest PC 0x0c09f940 */
if(!s->budget--) { s->failed_pc=0x0c09f940u; return 0; }
r[0]=0x0000003cu;
goto P_0c09f942;
P_0c09f942: /* original f656, guest PC 0x0c09f942 */
if(!s->budget--) { s->failed_pc=0x0c09f942u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c09f944;
P_0c09f944: /* original e044, guest PC 0x0c09f944 */
if(!s->budget--) { s->failed_pc=0x0c09f944u; return 0; }
r[0]=0x00000044u;
goto P_0c09f946;
P_0c09f946: /* original f456, guest PC 0x0c09f946 */
if(!s->budget--) { s->failed_pc=0x0c09f946u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c09f948;
P_0c09f948: /* original e03c, guest PC 0x0c09f948 */
if(!s->budget--) { s->failed_pc=0x0c09f948u; return 0; }
r[0]=0x0000003cu;
goto P_0c09f94a;
P_0c09f94a: /* original f766, guest PC 0x0c09f94a */
if(!s->budget--) { s->failed_pc=0x0c09f94au; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c09f94c;
P_0c09f94c: /* original a007, guest PC 0x0c09f94c */
if(!s->budget--) { s->failed_pc=0x0c09f94cu; return 0; }
r[0]=0x00000044u;
goto P_0c09f95e;
P_0c09f94e: /* original e044, guest PC 0x0c09f94e */
if(!s->budget--) { s->failed_pc=0x0c09f94eu; return 0; }
r[0]=0x00000044u;
goto P_0c09f950;
P_0c09f950: /* original e048, guest PC 0x0c09f950 */
if(!s->budget--) { s->failed_pc=0x0c09f950u; return 0; }
r[0]=0x00000048u;
goto P_0c09f952;
P_0c09f952: /* original f656, guest PC 0x0c09f952 */
if(!s->budget--) { s->failed_pc=0x0c09f952u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c09f954;
P_0c09f954: /* original e050, guest PC 0x0c09f954 */
if(!s->budget--) { s->failed_pc=0x0c09f954u; return 0; }
r[0]=0x00000050u;
goto P_0c09f956;
P_0c09f956: /* original f456, guest PC 0x0c09f956 */
if(!s->budget--) { s->failed_pc=0x0c09f956u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c09f958;
P_0c09f958: /* original e048, guest PC 0x0c09f958 */
if(!s->budget--) { s->failed_pc=0x0c09f958u; return 0; }
r[0]=0x00000048u;
goto P_0c09f95a;
P_0c09f95a: /* original f766, guest PC 0x0c09f95a */
if(!s->budget--) { s->failed_pc=0x0c09f95au; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c09f95c;
P_0c09f95c: /* original e050, guest PC 0x0c09f95c */
if(!s->budget--) { s->failed_pc=0x0c09f95cu; return 0; }
r[0]=0x00000050u;
goto P_0c09f95e;
P_0c09f95e: /* original f671, guest PC 0x0c09f95e */
if(!s->budget--) { s->failed_pc=0x0c09f95eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c09f960;
P_0c09f960: /* original f566, guest PC 0x0c09f960 */
if(!s->budget--) { s->failed_pc=0x0c09f960u; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c09f962;
P_0c09f962: /* original f74c, guest PC 0x0c09f962 */
if(!s->budget--) { s->failed_pc=0x0c09f962u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09f964;
P_0c09f964: /* original 6463, guest PC 0x0c09f964 */
if(!s->budget--) { s->failed_pc=0x0c09f964u; return 0; }
r[4]=r[6];
goto P_0c09f966;
P_0c09f966: /* original f751, guest PC 0x0c09f966 */
if(!s->budget--) { s->failed_pc=0x0c09f966u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c09f968;
P_0c09f968: /* original e507, guest PC 0x0c09f968 */
if(!s->budget--) { s->failed_pc=0x0c09f968u; return 0; }
r[5]=0x00000007u;
goto P_0c09f96a;
P_0c09f96a: /* original 6643, guest PC 0x0c09f96a */
if(!s->budget--) { s->failed_pc=0x0c09f96au; return 0; }
r[6]=r[4];
goto P_0c09f96c;
P_0c09f96c: /* original 7608, guest PC 0x0c09f96c */
if(!s->budget--) { s->failed_pc=0x0c09f96cu; return 0; }
r[6]+=0x00000008u;
goto P_0c09f96e;
P_0c09f96e: /* original f468, guest PC 0x0c09f96e */
if(!s->budget--) { s->failed_pc=0x0c09f96eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
goto P_0c09f970;
P_0c09f970: /* original 4510, guest PC 0x0c09f970 */
if(!s->budget--) { s->failed_pc=0x0c09f970u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09f972;
P_0c09f972: /* original f548, guest PC 0x0c09f972 */
if(!s->budget--) { s->failed_pc=0x0c09f972u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c09f974;
P_0c09f974: /* original f470, guest PC 0x0c09f974 */
if(!s->budget--) { s->failed_pc=0x0c09f974u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c09f976;
P_0c09f976: /* original f560, guest PC 0x0c09f976 */
if(!s->budget--) { s->failed_pc=0x0c09f976u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c09f978;
P_0c09f978: /* original f45a, guest PC 0x0c09f978 */
if(!s->budget--) { s->failed_pc=0x0c09f978u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c09f97a;
P_0c09f97a: /* original f64a, guest PC 0x0c09f97a */
if(!s->budget--) { s->failed_pc=0x0c09f97au; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c09f97c;
P_0c09f97c: /* original 8ff5, guest PC 0x0c09f97c */
if(!s->budget--) { s->failed_pc=0x0c09f97cu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09f96a; }
goto P_0c09f980;
P_0c09f97e: /* original 740c, guest PC 0x0c09f97e */
if(!s->budget--) { s->failed_pc=0x0c09f97eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f980;
P_0c09f980: /* original 000b, guest PC 0x0c09f980 */
if(!s->budget--) { s->failed_pc=0x0c09f980u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c09f982: /* original 7f10, guest PC 0x0c09f982 */
if(!s->budget--) { s->failed_pc=0x0c09f982u; return 0; }
r[15]+=0x00000010u;
if(!vf3_matrix_family(0x0c09f984u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f984u; return 0; } return 1;
P_0c09fc8e: /* original 9024, guest PC 0x0c09fc8e */
if(!s->budget--) { s->failed_pc=0x0c09fc8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdau,2);
goto P_0c09fc90;
P_0c09fc90: /* original 9224, guest PC 0x0c09fc90 */
if(!s->budget--) { s->failed_pc=0x0c09fc90u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdcu,2);
goto P_0c09fc92;
P_0c09fc92: /* original 034d, guest PC 0x0c09fc92 */
if(!s->budget--) { s->failed_pc=0x0c09fc92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09fc94;
P_0c09fc94: /* original 633d, guest PC 0x0c09fc94 */
if(!s->budget--) { s->failed_pc=0x0c09fc94u; return 0; }
r[3]=r[3]&65535u;
goto P_0c09fc96;
P_0c09fc96: /* original 3320, guest PC 0x0c09fc96 */
if(!s->budget--) { s->failed_pc=0x0c09fc96u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09fc98;
P_0c09fc98: /* original 8b05, guest PC 0x0c09fc98 */
if(!s->budget--) { s->failed_pc=0x0c09fc98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09fca6; }
goto P_0c09fc9a;
P_0c09fc9a: /* original 9120, guest PC 0x0c09fc9a */
if(!s->budget--) { s->failed_pc=0x0c09fc9au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdeu,2);
goto P_0c09fc9c;
P_0c09fc9c: /* original e008, guest PC 0x0c09fc9c */
if(!s->budget--) { s->failed_pc=0x0c09fc9cu; return 0; }
r[0]=0x00000008u;
goto P_0c09fc9e;
P_0c09fc9e: /* original f48d, guest PC 0x0c09fc9e */
if(!s->budget--) { s->failed_pc=0x0c09fc9eu; return 0; }
fr[4]=0;
goto P_0c09fca0;
P_0c09fca0: /* original 341c, guest PC 0x0c09fca0 */
if(!s->budget--) { s->failed_pc=0x0c09fca0u; return 0; }
r[4]+=r[1];
goto P_0c09fca2;
P_0c09fca2: /* original f44a, guest PC 0x0c09fca2 */
if(!s->budget--) { s->failed_pc=0x0c09fca2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fca4;
P_0c09fca4: /* original f447, guest PC 0x0c09fca4 */
if(!s->budget--) { s->failed_pc=0x0c09fca4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09fca6;
P_0c09fca6: /* original 000b, guest PC 0x0c09fca6 */
if(!s->budget--) { s->failed_pc=0x0c09fca6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09fca8: /* original 0009, guest PC 0x0c09fca8 */
if(!s->budget--) { s->failed_pc=0x0c09fca8u; return 0; }
goto P_0c09fcaa;
P_0c09fcaa: /* original c711, guest PC 0x0c09fcaa */
if(!s->budget--) { s->failed_pc=0x0c09fcaau; return 0; }
r[0]=code_base|0x0009fcf0u;
goto P_0c09fcac;
P_0c09fcac: /* original f448, guest PC 0x0c09fcac */
if(!s->budget--) { s->failed_pc=0x0c09fcacu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcae;
P_0c09fcae: /* original f508, guest PC 0x0c09fcae */
if(!s->budget--) { s->failed_pc=0x0c09fcaeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09fcb0;
P_0c09fcb0: /* original f451, guest PC 0x0c09fcb0 */
if(!s->budget--) { s->failed_pc=0x0c09fcb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c09fcb2;
P_0c09fcb2: /* original f44d, guest PC 0x0c09fcb2 */
if(!s->budget--) { s->failed_pc=0x0c09fcb2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcb4;
P_0c09fcb4: /* original f450, guest PC 0x0c09fcb4 */
if(!s->budget--) { s->failed_pc=0x0c09fcb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c09fcb6;
P_0c09fcb6: /* original 000b, guest PC 0x0c09fcb6 */
if(!s->budget--) { s->failed_pc=0x0c09fcb6u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcb8: /* original f44a, guest PC 0x0c09fcb8 */
if(!s->budget--) { s->failed_pc=0x0c09fcb8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fcba;
P_0c09fcba: /* original f358, guest PC 0x0c09fcba */
if(!s->budget--) { s->failed_pc=0x0c09fcbau; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c09fcbc;
P_0c09fcbc: /* original f448, guest PC 0x0c09fcbc */
if(!s->budget--) { s->failed_pc=0x0c09fcbcu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcbe;
P_0c09fcbe: /* original f43a, guest PC 0x0c09fcbe */
if(!s->budget--) { s->failed_pc=0x0c09fcbeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09fcc0;
P_0c09fcc0: /* original 000b, guest PC 0x0c09fcc0 */
if(!s->budget--) { s->failed_pc=0x0c09fcc0u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[5]);
s->pc=target; return ram->oob==0;
P_0c09fcc2: /* original f54a, guest PC 0x0c09fcc2 */
if(!s->budget--) { s->failed_pc=0x0c09fcc2u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcc4;
P_0c09fcc4: /* original f448, guest PC 0x0c09fcc4 */
if(!s->budget--) { s->failed_pc=0x0c09fcc4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcc6;
P_0c09fcc6: /* original f558, guest PC 0x0c09fcc6 */
if(!s->budget--) { s->failed_pc=0x0c09fcc6u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09fcc8;
P_0c09fcc8: /* original f44d, guest PC 0x0c09fcc8 */
if(!s->budget--) { s->failed_pc=0x0c09fcc8u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcca;
P_0c09fcca: /* original f54d, guest PC 0x0c09fcca */
if(!s->budget--) { s->failed_pc=0x0c09fccau; return 0; }
fr[5]^=0x80000000u;
goto P_0c09fccc;
P_0c09fccc: /* original f54a, guest PC 0x0c09fccc */
if(!s->budget--) { s->failed_pc=0x0c09fcccu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcce;
P_0c09fcce: /* original 000b, guest PC 0x0c09fcce */
if(!s->budget--) { s->failed_pc=0x0c09fcceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcd0: /* original f45a, guest PC 0x0c09fcd0 */
if(!s->budget--) { s->failed_pc=0x0c09fcd0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
if(!vf3_matrix_family(0x0c09fcd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fcd2u; return 0; } return 1;
P_0c09fcf4: /* original 2fe6, guest PC 0x0c09fcf4 */
if(!s->budget--) { s->failed_pc=0x0c09fcf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fcf6;
P_0c09fcf6: /* original e00c, guest PC 0x0c09fcf6 */
if(!s->budget--) { s->failed_pc=0x0c09fcf6u; return 0; }
r[0]=0x0000000cu;
goto P_0c09fcf8;
P_0c09fcf8: /* original 6e43, guest PC 0x0c09fcf8 */
if(!s->budget--) { s->failed_pc=0x0c09fcf8u; return 0; }
r[14]=r[4];
goto P_0c09fcfa;
P_0c09fcfa: /* original f3e8, guest PC 0x0c09fcfa */
if(!s->budget--) { s->failed_pc=0x0c09fcfau; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c09fcfc;
P_0c09fcfc: /* original 4f22, guest PC 0x0c09fcfc */
if(!s->budget--) { s->failed_pc=0x0c09fcfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fcfe;
P_0c09fcfe: /* original f34d, guest PC 0x0c09fcfe */
if(!s->budget--) { s->failed_pc=0x0c09fcfeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd00;
P_0c09fd00: /* original 65e3, guest PC 0x0c09fd00 */
if(!s->budget--) { s->failed_pc=0x0c09fd00u; return 0; }
r[5]=r[14];
goto P_0c09fd02;
P_0c09fd02: /* original fe3a, guest PC 0x0c09fd02 */
if(!s->budget--) { s->failed_pc=0x0c09fd02u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09fd04;
P_0c09fd04: /* original 64e3, guest PC 0x0c09fd04 */
if(!s->budget--) { s->failed_pc=0x0c09fd04u; return 0; }
r[4]=r[14];
goto P_0c09fd06;
P_0c09fd06: /* original f2e6, guest PC 0x0c09fd06 */
if(!s->budget--) { s->failed_pc=0x0c09fd06u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09fd08;
P_0c09fd08: /* original 7524, guest PC 0x0c09fd08 */
if(!s->budget--) { s->failed_pc=0x0c09fd08u; return 0; }
r[5]+=0x00000024u;
goto P_0c09fd0a;
P_0c09fd0a: /* original f24d, guest PC 0x0c09fd0a */
if(!s->budget--) { s->failed_pc=0x0c09fd0au; return 0; }
fr[2]^=0x80000000u;
goto P_0c09fd0c;
P_0c09fd0c: /* original fe27, guest PC 0x0c09fd0c */
if(!s->budget--) { s->failed_pc=0x0c09fd0cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c09fd0e;
P_0c09fd0e: /* original e018, guest PC 0x0c09fd0e */
if(!s->budget--) { s->failed_pc=0x0c09fd0eu; return 0; }
r[0]=0x00000018u;
goto P_0c09fd10;
P_0c09fd10: /* original f3e6, guest PC 0x0c09fd10 */
if(!s->budget--) { s->failed_pc=0x0c09fd10u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd12;
P_0c09fd12: /* original f34d, guest PC 0x0c09fd12 */
if(!s->budget--) { s->failed_pc=0x0c09fd12u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd14;
P_0c09fd14: /* original fe37, guest PC 0x0c09fd14 */
if(!s->budget--) { s->failed_pc=0x0c09fd14u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd16;
P_0c09fd16: /* original bfd5, guest PC 0x0c09fd16 */
if(!s->budget--) { s->failed_pc=0x0c09fd16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd1au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd1au) { target=s->pc; goto dispatch; }
goto P_0c09fd1a;
P_0c09fd18: /* original 7430, guest PC 0x0c09fd18 */
if(!s->budget--) { s->failed_pc=0x0c09fd18u; return 0; }
r[4]+=0x00000030u;
goto P_0c09fd1a;
P_0c09fd1a: /* original 65e3, guest PC 0x0c09fd1a */
if(!s->budget--) { s->failed_pc=0x0c09fd1au; return 0; }
r[5]=r[14];
goto P_0c09fd1c;
P_0c09fd1c: /* original 64e3, guest PC 0x0c09fd1c */
if(!s->budget--) { s->failed_pc=0x0c09fd1cu; return 0; }
r[4]=r[14];
goto P_0c09fd1e;
P_0c09fd1e: /* original 7528, guest PC 0x0c09fd1e */
if(!s->budget--) { s->failed_pc=0x0c09fd1eu; return 0; }
r[5]+=0x00000028u;
goto P_0c09fd20;
P_0c09fd20: /* original bfcb, guest PC 0x0c09fd20 */
if(!s->budget--) { s->failed_pc=0x0c09fd20u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd24u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd24u) { target=s->pc; goto dispatch; }
goto P_0c09fd24;
P_0c09fd22: /* original 7434, guest PC 0x0c09fd22 */
if(!s->budget--) { s->failed_pc=0x0c09fd22u; return 0; }
r[4]+=0x00000034u;
goto P_0c09fd24;
P_0c09fd24: /* original 65e3, guest PC 0x0c09fd24 */
if(!s->budget--) { s->failed_pc=0x0c09fd24u; return 0; }
r[5]=r[14];
goto P_0c09fd26;
P_0c09fd26: /* original 64e3, guest PC 0x0c09fd26 */
if(!s->budget--) { s->failed_pc=0x0c09fd26u; return 0; }
r[4]=r[14];
goto P_0c09fd28;
P_0c09fd28: /* original 752c, guest PC 0x0c09fd28 */
if(!s->budget--) { s->failed_pc=0x0c09fd28u; return 0; }
r[5]+=0x0000002cu;
goto P_0c09fd2a;
P_0c09fd2a: /* original bfc6, guest PC 0x0c09fd2a */
if(!s->budget--) { s->failed_pc=0x0c09fd2au; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd2eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd2eu) { target=s->pc; goto dispatch; }
goto P_0c09fd2e;
P_0c09fd2c: /* original 7438, guest PC 0x0c09fd2c */
if(!s->budget--) { s->failed_pc=0x0c09fd2cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09fd2e;
P_0c09fd2e: /* original 65e3, guest PC 0x0c09fd2e */
if(!s->budget--) { s->failed_pc=0x0c09fd2eu; return 0; }
r[5]=r[14];
goto P_0c09fd30;
P_0c09fd30: /* original 64e3, guest PC 0x0c09fd30 */
if(!s->budget--) { s->failed_pc=0x0c09fd30u; return 0; }
r[4]=r[14];
goto P_0c09fd32;
P_0c09fd32: /* original 753c, guest PC 0x0c09fd32 */
if(!s->budget--) { s->failed_pc=0x0c09fd32u; return 0; }
r[5]+=0x0000003cu;
goto P_0c09fd34;
P_0c09fd34: /* original bfc6, guest PC 0x0c09fd34 */
if(!s->budget--) { s->failed_pc=0x0c09fd34u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd38u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd38u) { target=s->pc; goto dispatch; }
goto P_0c09fd38;
P_0c09fd36: /* original 7448, guest PC 0x0c09fd36 */
if(!s->budget--) { s->failed_pc=0x0c09fd36u; return 0; }
r[4]+=0x00000048u;
goto P_0c09fd38;
P_0c09fd38: /* original 65e3, guest PC 0x0c09fd38 */
if(!s->budget--) { s->failed_pc=0x0c09fd38u; return 0; }
r[5]=r[14];
goto P_0c09fd3a;
P_0c09fd3a: /* original 64e3, guest PC 0x0c09fd3a */
if(!s->budget--) { s->failed_pc=0x0c09fd3au; return 0; }
r[4]=r[14];
goto P_0c09fd3c;
P_0c09fd3c: /* original 7540, guest PC 0x0c09fd3c */
if(!s->budget--) { s->failed_pc=0x0c09fd3cu; return 0; }
r[5]+=0x00000040u;
goto P_0c09fd3e;
P_0c09fd3e: /* original bfbc, guest PC 0x0c09fd3e */
if(!s->budget--) { s->failed_pc=0x0c09fd3eu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd42u;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd42u) { target=s->pc; goto dispatch; }
goto P_0c09fd42;
P_0c09fd40: /* original 744c, guest PC 0x0c09fd40 */
if(!s->budget--) { s->failed_pc=0x0c09fd40u; return 0; }
r[4]+=0x0000004cu;
goto P_0c09fd42;
P_0c09fd42: /* original 65e3, guest PC 0x0c09fd42 */
if(!s->budget--) { s->failed_pc=0x0c09fd42u; return 0; }
r[5]=r[14];
goto P_0c09fd44;
P_0c09fd44: /* original 64e3, guest PC 0x0c09fd44 */
if(!s->budget--) { s->failed_pc=0x0c09fd44u; return 0; }
r[4]=r[14];
goto P_0c09fd46;
P_0c09fd46: /* original 7544, guest PC 0x0c09fd46 */
if(!s->budget--) { s->failed_pc=0x0c09fd46u; return 0; }
r[5]+=0x00000044u;
goto P_0c09fd48;
P_0c09fd48: /* original bfb7, guest PC 0x0c09fd48 */
if(!s->budget--) { s->failed_pc=0x0c09fd48u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd4cu;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd4cu) { target=s->pc; goto dispatch; }
goto P_0c09fd4c;
P_0c09fd4a: /* original 7450, guest PC 0x0c09fd4a */
if(!s->budget--) { s->failed_pc=0x0c09fd4au; return 0; }
r[4]+=0x00000050u;
goto P_0c09fd4c;
P_0c09fd4c: /* original e054, guest PC 0x0c09fd4c */
if(!s->budget--) { s->failed_pc=0x0c09fd4cu; return 0; }
r[0]=0x00000054u;
goto P_0c09fd4e;
P_0c09fd4e: /* original 64e3, guest PC 0x0c09fd4e */
if(!s->budget--) { s->failed_pc=0x0c09fd4eu; return 0; }
r[4]=r[14];
goto P_0c09fd50;
P_0c09fd50: /* original f3e6, guest PC 0x0c09fd50 */
if(!s->budget--) { s->failed_pc=0x0c09fd50u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd52;
P_0c09fd52: /* original f34d, guest PC 0x0c09fd52 */
if(!s->budget--) { s->failed_pc=0x0c09fd52u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd54;
P_0c09fd54: /* original fe37, guest PC 0x0c09fd54 */
if(!s->budget--) { s->failed_pc=0x0c09fd54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd56;
P_0c09fd56: /* original e058, guest PC 0x0c09fd56 */
if(!s->budget--) { s->failed_pc=0x0c09fd56u; return 0; }
r[0]=0x00000058u;
goto P_0c09fd58;
P_0c09fd58: /* original f3e6, guest PC 0x0c09fd58 */
if(!s->budget--) { s->failed_pc=0x0c09fd58u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd5a;
P_0c09fd5a: /* original f34d, guest PC 0x0c09fd5a */
if(!s->budget--) { s->failed_pc=0x0c09fd5au; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd5c;
P_0c09fd5c: /* original fe37, guest PC 0x0c09fd5c */
if(!s->budget--) { s->failed_pc=0x0c09fd5cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd5e;
P_0c09fd5e: /* original e060, guest PC 0x0c09fd5e */
if(!s->budget--) { s->failed_pc=0x0c09fd5eu; return 0; }
r[0]=0x00000060u;
goto P_0c09fd60;
P_0c09fd60: /* original f3e6, guest PC 0x0c09fd60 */
if(!s->budget--) { s->failed_pc=0x0c09fd60u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd62;
P_0c09fd62: /* original f34d, guest PC 0x0c09fd62 */
if(!s->budget--) { s->failed_pc=0x0c09fd62u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd64;
P_0c09fd64: /* original fe37, guest PC 0x0c09fd64 */
if(!s->budget--) { s->failed_pc=0x0c09fd64u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd66;
P_0c09fd66: /* original bfa0, guest PC 0x0c09fd66 */
if(!s->budget--) { s->failed_pc=0x0c09fd66u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd6au;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd6au) { target=s->pc; goto dispatch; }
goto P_0c09fd6a;
P_0c09fd68: /* original 7464, guest PC 0x0c09fd68 */
if(!s->budget--) { s->failed_pc=0x0c09fd68u; return 0; }
r[4]+=0x00000064u;
goto P_0c09fd6a;
P_0c09fd6a: /* original e068, guest PC 0x0c09fd6a */
if(!s->budget--) { s->failed_pc=0x0c09fd6au; return 0; }
r[0]=0x00000068u;
goto P_0c09fd6c;
P_0c09fd6c: /* original 64e3, guest PC 0x0c09fd6c */
if(!s->budget--) { s->failed_pc=0x0c09fd6cu; return 0; }
r[4]=r[14];
goto P_0c09fd6e;
P_0c09fd6e: /* original f3e6, guest PC 0x0c09fd6e */
if(!s->budget--) { s->failed_pc=0x0c09fd6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd70;
P_0c09fd70: /* original f34d, guest PC 0x0c09fd70 */
if(!s->budget--) { s->failed_pc=0x0c09fd70u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd72;
P_0c09fd72: /* original fe37, guest PC 0x0c09fd72 */
if(!s->budget--) { s->failed_pc=0x0c09fd72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd74;
P_0c09fd74: /* original bf99, guest PC 0x0c09fd74 */
if(!s->budget--) { s->failed_pc=0x0c09fd74u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd78u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd78u) { target=s->pc; goto dispatch; }
goto P_0c09fd78;
P_0c09fd76: /* original 7470, guest PC 0x0c09fd76 */
if(!s->budget--) { s->failed_pc=0x0c09fd76u; return 0; }
r[4]+=0x00000070u;
goto P_0c09fd78;
P_0c09fd78: /* original 9556, guest PC 0x0c09fd78 */
if(!s->budget--) { s->failed_pc=0x0c09fd78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe28u,2);
goto P_0c09fd7a;
P_0c09fd7a: /* original 9456, guest PC 0x0c09fd7a */
if(!s->budget--) { s->failed_pc=0x0c09fd7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2au,2);
goto P_0c09fd7c;
P_0c09fd7c: /* original 35ec, guest PC 0x0c09fd7c */
if(!s->budget--) { s->failed_pc=0x0c09fd7cu; return 0; }
r[5]+=r[14];
goto P_0c09fd7e;
P_0c09fd7e: /* original bfa1, guest PC 0x0c09fd7e */
if(!s->budget--) { s->failed_pc=0x0c09fd7eu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd82u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd82u) { target=s->pc; goto dispatch; }
goto P_0c09fd82;
P_0c09fd80: /* original 34ec, guest PC 0x0c09fd80 */
if(!s->budget--) { s->failed_pc=0x0c09fd80u; return 0; }
r[4]+=r[14];
goto P_0c09fd82;
P_0c09fd82: /* original 9453, guest PC 0x0c09fd82 */
if(!s->budget--) { s->failed_pc=0x0c09fd82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2cu,2);
goto P_0c09fd84;
P_0c09fd84: /* original 65e3, guest PC 0x0c09fd84 */
if(!s->budget--) { s->failed_pc=0x0c09fd84u; return 0; }
r[5]=r[14];
goto P_0c09fd86;
P_0c09fd86: /* original 757c, guest PC 0x0c09fd86 */
if(!s->budget--) { s->failed_pc=0x0c09fd86u; return 0; }
r[5]+=0x0000007cu;
goto P_0c09fd88;
P_0c09fd88: /* original bf9c, guest PC 0x0c09fd88 */
if(!s->budget--) { s->failed_pc=0x0c09fd88u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd8cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd8cu) { target=s->pc; goto dispatch; }
goto P_0c09fd8c;
P_0c09fd8a: /* original 34ec, guest PC 0x0c09fd8a */
if(!s->budget--) { s->failed_pc=0x0c09fd8au; return 0; }
r[4]+=r[14];
goto P_0c09fd8c;
P_0c09fd8c: /* original 944f, guest PC 0x0c09fd8c */
if(!s->budget--) { s->failed_pc=0x0c09fd8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2eu,2);
goto P_0c09fd8e;
P_0c09fd8e: /* original 65e3, guest PC 0x0c09fd8e */
if(!s->budget--) { s->failed_pc=0x0c09fd8eu; return 0; }
r[5]=r[14];
goto P_0c09fd90;
P_0c09fd90: /* original 7578, guest PC 0x0c09fd90 */
if(!s->budget--) { s->failed_pc=0x0c09fd90u; return 0; }
r[5]+=0x00000078u;
goto P_0c09fd92;
P_0c09fd92: /* original bf92, guest PC 0x0c09fd92 */
if(!s->budget--) { s->failed_pc=0x0c09fd92u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd96u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd96u) { target=s->pc; goto dispatch; }
goto P_0c09fd96;
P_0c09fd94: /* original 34ec, guest PC 0x0c09fd94 */
if(!s->budget--) { s->failed_pc=0x0c09fd94u; return 0; }
r[4]+=r[14];
goto P_0c09fd96;
P_0c09fd96: /* original 954b, guest PC 0x0c09fd96 */
if(!s->budget--) { s->failed_pc=0x0c09fd96u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe30u,2);
goto P_0c09fd98;
P_0c09fd98: /* original 944b, guest PC 0x0c09fd98 */
if(!s->budget--) { s->failed_pc=0x0c09fd98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe32u,2);
goto P_0c09fd9a;
P_0c09fd9a: /* original 35ec, guest PC 0x0c09fd9a */
if(!s->budget--) { s->failed_pc=0x0c09fd9au; return 0; }
r[5]+=r[14];
goto P_0c09fd9c;
P_0c09fd9c: /* original bf92, guest PC 0x0c09fd9c */
if(!s->budget--) { s->failed_pc=0x0c09fd9cu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fda0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fda0u) { target=s->pc; goto dispatch; }
goto P_0c09fda0;
P_0c09fd9e: /* original 34ec, guest PC 0x0c09fd9e */
if(!s->budget--) { s->failed_pc=0x0c09fd9eu; return 0; }
r[4]+=r[14];
goto P_0c09fda0;
P_0c09fda0: /* original 9548, guest PC 0x0c09fda0 */
if(!s->budget--) { s->failed_pc=0x0c09fda0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe34u,2);
goto P_0c09fda2;
P_0c09fda2: /* original 9448, guest PC 0x0c09fda2 */
if(!s->budget--) { s->failed_pc=0x0c09fda2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe36u,2);
goto P_0c09fda4;
P_0c09fda4: /* original 35ec, guest PC 0x0c09fda4 */
if(!s->budget--) { s->failed_pc=0x0c09fda4u; return 0; }
r[5]+=r[14];
goto P_0c09fda6;
P_0c09fda6: /* original bf8d, guest PC 0x0c09fda6 */
if(!s->budget--) { s->failed_pc=0x0c09fda6u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdaau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdaau) { target=s->pc; goto dispatch; }
goto P_0c09fdaa;
P_0c09fda8: /* original 34ec, guest PC 0x0c09fda8 */
if(!s->budget--) { s->failed_pc=0x0c09fda8u; return 0; }
r[4]+=r[14];
goto P_0c09fdaa;
P_0c09fdaa: /* original 9545, guest PC 0x0c09fdaa */
if(!s->budget--) { s->failed_pc=0x0c09fdaau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe38u,2);
goto P_0c09fdac;
P_0c09fdac: /* original 9445, guest PC 0x0c09fdac */
if(!s->budget--) { s->failed_pc=0x0c09fdacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3au,2);
goto P_0c09fdae;
P_0c09fdae: /* original 35ec, guest PC 0x0c09fdae */
if(!s->budget--) { s->failed_pc=0x0c09fdaeu; return 0; }
r[5]+=r[14];
goto P_0c09fdb0;
P_0c09fdb0: /* original bf83, guest PC 0x0c09fdb0 */
if(!s->budget--) { s->failed_pc=0x0c09fdb0u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdb4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdb4u) { target=s->pc; goto dispatch; }
goto P_0c09fdb4;
P_0c09fdb2: /* original 34ec, guest PC 0x0c09fdb2 */
if(!s->budget--) { s->failed_pc=0x0c09fdb2u; return 0; }
r[4]+=r[14];
goto P_0c09fdb4;
P_0c09fdb4: /* original 9542, guest PC 0x0c09fdb4 */
if(!s->budget--) { s->failed_pc=0x0c09fdb4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3cu,2);
goto P_0c09fdb6;
P_0c09fdb6: /* original 9442, guest PC 0x0c09fdb6 */
if(!s->budget--) { s->failed_pc=0x0c09fdb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3eu,2);
goto P_0c09fdb8;
P_0c09fdb8: /* original 35ec, guest PC 0x0c09fdb8 */
if(!s->budget--) { s->failed_pc=0x0c09fdb8u; return 0; }
r[5]+=r[14];
goto P_0c09fdba;
P_0c09fdba: /* original bf83, guest PC 0x0c09fdba */
if(!s->budget--) { s->failed_pc=0x0c09fdbau; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdbeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdbeu) { target=s->pc; goto dispatch; }
goto P_0c09fdbe;
P_0c09fdbc: /* original 34ec, guest PC 0x0c09fdbc */
if(!s->budget--) { s->failed_pc=0x0c09fdbcu; return 0; }
r[4]+=r[14];
goto P_0c09fdbe;
P_0c09fdbe: /* original 953f, guest PC 0x0c09fdbe */
if(!s->budget--) { s->failed_pc=0x0c09fdbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe40u,2);
goto P_0c09fdc0;
P_0c09fdc0: /* original 943f, guest PC 0x0c09fdc0 */
if(!s->budget--) { s->failed_pc=0x0c09fdc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe42u,2);
goto P_0c09fdc2;
P_0c09fdc2: /* original 35ec, guest PC 0x0c09fdc2 */
if(!s->budget--) { s->failed_pc=0x0c09fdc2u; return 0; }
r[5]+=r[14];
goto P_0c09fdc4;
P_0c09fdc4: /* original bf7e, guest PC 0x0c09fdc4 */
if(!s->budget--) { s->failed_pc=0x0c09fdc4u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdc8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdc8u) { target=s->pc; goto dispatch; }
goto P_0c09fdc8;
P_0c09fdc6: /* original 34ec, guest PC 0x0c09fdc6 */
if(!s->budget--) { s->failed_pc=0x0c09fdc6u; return 0; }
r[4]+=r[14];
goto P_0c09fdc8;
P_0c09fdc8: /* original 953c, guest PC 0x0c09fdc8 */
if(!s->budget--) { s->failed_pc=0x0c09fdc8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe44u,2);
goto P_0c09fdca;
P_0c09fdca: /* original 943c, guest PC 0x0c09fdca */
if(!s->budget--) { s->failed_pc=0x0c09fdcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe46u,2);
goto P_0c09fdcc;
P_0c09fdcc: /* original 35ec, guest PC 0x0c09fdcc */
if(!s->budget--) { s->failed_pc=0x0c09fdccu; return 0; }
r[5]+=r[14];
goto P_0c09fdce;
P_0c09fdce: /* original bf74, guest PC 0x0c09fdce */
if(!s->budget--) { s->failed_pc=0x0c09fdceu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdd2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdd2u) { target=s->pc; goto dispatch; }
goto P_0c09fdd2;
P_0c09fdd0: /* original 34ec, guest PC 0x0c09fdd0 */
if(!s->budget--) { s->failed_pc=0x0c09fdd0u; return 0; }
r[4]+=r[14];
goto P_0c09fdd2;
P_0c09fdd2: /* original 9039, guest PC 0x0c09fdd2 */
if(!s->budget--) { s->failed_pc=0x0c09fdd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe48u,2);
goto P_0c09fdd4;
P_0c09fdd4: /* original f3e6, guest PC 0x0c09fdd4 */
if(!s->budget--) { s->failed_pc=0x0c09fdd4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fdd6;
P_0c09fdd6: /* original f34d, guest PC 0x0c09fdd6 */
if(!s->budget--) { s->failed_pc=0x0c09fdd6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fdd8;
P_0c09fdd8: /* original fe37, guest PC 0x0c09fdd8 */
if(!s->budget--) { s->failed_pc=0x0c09fdd8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fdda;
P_0c09fdda: /* original 9436, guest PC 0x0c09fdda */
if(!s->budget--) { s->failed_pc=0x0c09fddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4au,2);
goto P_0c09fddc;
P_0c09fddc: /* original bf65, guest PC 0x0c09fddc */
if(!s->budget--) { s->failed_pc=0x0c09fddcu; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fde0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fde0u) { target=s->pc; goto dispatch; }
goto P_0c09fde0;
P_0c09fdde: /* original 34ec, guest PC 0x0c09fdde */
if(!s->budget--) { s->failed_pc=0x0c09fddeu; return 0; }
r[4]+=r[14];
goto P_0c09fde0;
P_0c09fde0: /* original 9034, guest PC 0x0c09fde0 */
if(!s->budget--) { s->failed_pc=0x0c09fde0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4cu,2);
goto P_0c09fde2;
P_0c09fde2: /* original f3e6, guest PC 0x0c09fde2 */
if(!s->budget--) { s->failed_pc=0x0c09fde2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fde4;
P_0c09fde4: /* original f34d, guest PC 0x0c09fde4 */
if(!s->budget--) { s->failed_pc=0x0c09fde4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fde6;
P_0c09fde6: /* original fe37, guest PC 0x0c09fde6 */
if(!s->budget--) { s->failed_pc=0x0c09fde6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fde8;
P_0c09fde8: /* original 9531, guest PC 0x0c09fde8 */
if(!s->budget--) { s->failed_pc=0x0c09fde8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4eu,2);
goto P_0c09fdea;
P_0c09fdea: /* original 9431, guest PC 0x0c09fdea */
if(!s->budget--) { s->failed_pc=0x0c09fdeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe50u,2);
goto P_0c09fdec;
P_0c09fdec: /* original 35ec, guest PC 0x0c09fdec */
if(!s->budget--) { s->failed_pc=0x0c09fdecu; return 0; }
r[5]+=r[14];
goto P_0c09fdee;
P_0c09fdee: /* original bf69, guest PC 0x0c09fdee */
if(!s->budget--) { s->failed_pc=0x0c09fdeeu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdf2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdf2u) { target=s->pc; goto dispatch; }
goto P_0c09fdf2;
P_0c09fdf0: /* original 34ec, guest PC 0x0c09fdf0 */
if(!s->budget--) { s->failed_pc=0x0c09fdf0u; return 0; }
r[4]+=r[14];
goto P_0c09fdf2;
P_0c09fdf2: /* original 952e, guest PC 0x0c09fdf2 */
if(!s->budget--) { s->failed_pc=0x0c09fdf2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe52u,2);
goto P_0c09fdf4;
P_0c09fdf4: /* original 942e, guest PC 0x0c09fdf4 */
if(!s->budget--) { s->failed_pc=0x0c09fdf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe54u,2);
goto P_0c09fdf6;
P_0c09fdf6: /* original 35ec, guest PC 0x0c09fdf6 */
if(!s->budget--) { s->failed_pc=0x0c09fdf6u; return 0; }
r[5]+=r[14];
goto P_0c09fdf8;
P_0c09fdf8: /* original bf64, guest PC 0x0c09fdf8 */
if(!s->budget--) { s->failed_pc=0x0c09fdf8u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdfcu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdfcu) { target=s->pc; goto dispatch; }
goto P_0c09fdfc;
P_0c09fdfa: /* original 34ec, guest PC 0x0c09fdfa */
if(!s->budget--) { s->failed_pc=0x0c09fdfau; return 0; }
r[4]+=r[14];
goto P_0c09fdfc;
P_0c09fdfc: /* original 952b, guest PC 0x0c09fdfc */
if(!s->budget--) { s->failed_pc=0x0c09fdfcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe56u,2);
goto P_0c09fdfe;
P_0c09fdfe: /* original 942b, guest PC 0x0c09fdfe */
if(!s->budget--) { s->failed_pc=0x0c09fdfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe58u,2);
goto P_0c09fe00;
P_0c09fe00: /* original 35ec, guest PC 0x0c09fe00 */
if(!s->budget--) { s->failed_pc=0x0c09fe00u; return 0; }
r[5]+=r[14];
goto P_0c09fe02;
P_0c09fe02: /* original bf5a, guest PC 0x0c09fe02 */
if(!s->budget--) { s->failed_pc=0x0c09fe02u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe06u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe06u) { target=s->pc; goto dispatch; }
goto P_0c09fe06;
P_0c09fe04: /* original 34ec, guest PC 0x0c09fe04 */
if(!s->budget--) { s->failed_pc=0x0c09fe04u; return 0; }
r[4]+=r[14];
goto P_0c09fe06;
P_0c09fe06: /* original 9528, guest PC 0x0c09fe06 */
if(!s->budget--) { s->failed_pc=0x0c09fe06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5au,2);
goto P_0c09fe08;
P_0c09fe08: /* original 9428, guest PC 0x0c09fe08 */
if(!s->budget--) { s->failed_pc=0x0c09fe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5cu,2);
goto P_0c09fe0a;
P_0c09fe0a: /* original 35ec, guest PC 0x0c09fe0a */
if(!s->budget--) { s->failed_pc=0x0c09fe0au; return 0; }
r[5]+=r[14];
goto P_0c09fe0c;
P_0c09fe0c: /* original bf55, guest PC 0x0c09fe0c */
if(!s->budget--) { s->failed_pc=0x0c09fe0cu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe10u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe10u) { target=s->pc; goto dispatch; }
goto P_0c09fe10;
P_0c09fe0e: /* original 34ec, guest PC 0x0c09fe0e */
if(!s->budget--) { s->failed_pc=0x0c09fe0eu; return 0; }
r[4]+=r[14];
goto P_0c09fe10;
P_0c09fe10: /* original 9525, guest PC 0x0c09fe10 */
if(!s->budget--) { s->failed_pc=0x0c09fe10u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5eu,2);
goto P_0c09fe12;
P_0c09fe12: /* original 9425, guest PC 0x0c09fe12 */
if(!s->budget--) { s->failed_pc=0x0c09fe12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe60u,2);
goto P_0c09fe14;
P_0c09fe14: /* original 35ec, guest PC 0x0c09fe14 */
if(!s->budget--) { s->failed_pc=0x0c09fe14u; return 0; }
r[5]+=r[14];
goto P_0c09fe16;
P_0c09fe16: /* original bf55, guest PC 0x0c09fe16 */
if(!s->budget--) { s->failed_pc=0x0c09fe16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fe1au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe1au) { target=s->pc; goto dispatch; }
goto P_0c09fe1a;
P_0c09fe18: /* original 34ec, guest PC 0x0c09fe18 */
if(!s->budget--) { s->failed_pc=0x0c09fe18u; return 0; }
r[4]+=r[14];
goto P_0c09fe1a;
P_0c09fe1a: /* original 9423, guest PC 0x0c09fe1a */
if(!s->budget--) { s->failed_pc=0x0c09fe1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe64u,2);
goto P_0c09fe1c;
P_0c09fe1c: /* original 4f26, guest PC 0x0c09fe1c */
if(!s->budget--) { s->failed_pc=0x0c09fe1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09fe1e;
P_0c09fe1e: /* original 9520, guest PC 0x0c09fe1e */
if(!s->budget--) { s->failed_pc=0x0c09fe1eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe62u,2);
goto P_0c09fe20;
P_0c09fe20: /* original 34ec, guest PC 0x0c09fe20 */
if(!s->budget--) { s->failed_pc=0x0c09fe20u; return 0; }
r[4]+=r[14];
goto P_0c09fe22;
P_0c09fe22: /* original 35ec, guest PC 0x0c09fe22 */
if(!s->budget--) { s->failed_pc=0x0c09fe22u; return 0; }
r[5]+=r[14];
goto P_0c09fe24;
P_0c09fe24: /* original af4e, guest PC 0x0c09fe24 */
if(!s->budget--) { s->failed_pc=0x0c09fe24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09fcc4;
P_0c09fe26: /* original 6ef6, guest PC 0x0c09fe26 */
if(!s->budget--) { s->failed_pc=0x0c09fe26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fe28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fe28u; return 0; } return 1;
P_0c0a8574: /* original 2fe6, guest PC 0x0c0a8574 */
if(!s->budget--) { s->failed_pc=0x0c0a8574u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8576;
P_0c0a8576: /* original 2fd6, guest PC 0x0c0a8576 */
if(!s->budget--) { s->failed_pc=0x0c0a8576u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8578;
P_0c0a8578: /* original 2fc6, guest PC 0x0c0a8578 */
if(!s->budget--) { s->failed_pc=0x0c0a8578u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857a;
P_0c0a857a: /* original 2fb6, guest PC 0x0c0a857a */
if(!s->budget--) { s->failed_pc=0x0c0a857au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857c;
P_0c0a857c: /* original 2fa6, guest PC 0x0c0a857c */
if(!s->budget--) { s->failed_pc=0x0c0a857cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857e;
P_0c0a857e: /* original 2f96, guest PC 0x0c0a857e */
if(!s->budget--) { s->failed_pc=0x0c0a857eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8580;
P_0c0a8580: /* original 2f86, guest PC 0x0c0a8580 */
if(!s->budget--) { s->failed_pc=0x0c0a8580u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8582;
P_0c0a8582: /* original 4f22, guest PC 0x0c0a8582 */
if(!s->budget--) { s->failed_pc=0x0c0a8582u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8584;
P_0c0a8584: /* original 7ff4, guest PC 0x0c0a8584 */
if(!s->budget--) { s->failed_pc=0x0c0a8584u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a8586;
P_0c0a8586: /* original 2f42, guest PC 0x0c0a8586 */
if(!s->budget--) { s->failed_pc=0x0c0a8586u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a8588;
P_0c0a8588: /* original d340, guest PC 0x0c0a8588 */
if(!s->budget--) { s->failed_pc=0x0c0a8588u; return 0; }
r[3]=read(ram,0x0c0a868cu,4);
goto P_0c0a858a;
P_0c0a858a: /* original d241, guest PC 0x0c0a858a */
if(!s->budget--) { s->failed_pc=0x0c0a858au; return 0; }
r[2]=read(ram,0x0c0a8690u,4);
goto P_0c0a858c;
P_0c0a858c: /* original 420b, guest PC 0x0c0a858c */
if(!s->budget--) { s->failed_pc=0x0c0a858cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8590u;
write(ram,r[15]+8,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8590u) { target=s->pc; goto dispatch; }
goto P_0c0a8590;
P_0c0a858e: /* original 1f32, guest PC 0x0c0a858e */
if(!s->budget--) { s->failed_pc=0x0c0a858eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a8590;
P_0c0a8590: /* original 2008, guest PC 0x0c0a8590 */
if(!s->budget--) { s->failed_pc=0x0c0a8590u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8592;
P_0c0a8592: /* original 896b, guest PC 0x0c0a8592 */
if(!s->budget--) { s->failed_pc=0x0c0a8592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a8594;
P_0c0a8594: /* original dc3f, guest PC 0x0c0a8594 */
if(!s->budget--) { s->failed_pc=0x0c0a8594u; return 0; }
r[12]=read(ram,0x0c0a8694u,4);
goto P_0c0a8596;
P_0c0a8596: /* original eb01, guest PC 0x0c0a8596 */
if(!s->budget--) { s->failed_pc=0x0c0a8596u; return 0; }
r[11]=0x00000001u;
goto P_0c0a8598;
P_0c0a8598: /* original 9072, guest PC 0x0c0a8598 */
if(!s->budget--) { s->failed_pc=0x0c0a8598u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8680u,2);
goto P_0c0a859a;
P_0c0a859a: /* original 6df2, guest PC 0x0c0a859a */
if(!s->budget--) { s->failed_pc=0x0c0a859au; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0a859c;
P_0c0a859c: /* original 0cb4, guest PC 0x0c0a859c */
if(!s->budget--) { s->failed_pc=0x0c0a859cu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c0a859e;
P_0c0a859e: /* original e029, guest PC 0x0c0a859e */
if(!s->budget--) { s->failed_pc=0x0c0a859eu; return 0; }
r[0]=0x00000029u;
goto P_0c0a85a0;
P_0c0a85a0: /* original 00cc, guest PC 0x0c0a85a0 */
if(!s->budget--) { s->failed_pc=0x0c0a85a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85a2;
P_0c0a85a2: /* original 80f4, guest PC 0x0c0a85a2 */
if(!s->budget--) { s->failed_pc=0x0c0a85a2u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0a85a4;
P_0c0a85a4: /* original 53c2, guest PC 0x0c0a85a4 */
if(!s->budget--) { s->failed_pc=0x0c0a85a4u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0a85a6;
P_0c0a85a6: /* original 2f32, guest PC 0x0c0a85a6 */
if(!s->budget--) { s->failed_pc=0x0c0a85a6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a85a8;
P_0c0a85a8: /* original 54f2, guest PC 0x0c0a85a8 */
if(!s->budget--) { s->failed_pc=0x0c0a85a8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a85aa;
P_0c0a85aa: /* original d33b, guest PC 0x0c0a85aa */
if(!s->budget--) { s->failed_pc=0x0c0a85aau; return 0; }
r[3]=read(ram,0x0c0a8698u,4);
goto P_0c0a85ac;
P_0c0a85ac: /* original 430b, guest PC 0x0c0a85ac */
if(!s->budget--) { s->failed_pc=0x0c0a85acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a85b0u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a85b0u) { target=s->pc; goto dispatch; }
goto P_0c0a85b0;
P_0c0a85ae: /* original 7413, guest PC 0x0c0a85ae */
if(!s->budget--) { s->failed_pc=0x0c0a85aeu; return 0; }
r[4]+=0x00000013u;
goto P_0c0a85b0;
P_0c0a85b0: /* original 6e0c, guest PC 0x0c0a85b0 */
if(!s->budget--) { s->failed_pc=0x0c0a85b0u; return 0; }
r[14]=r[0]&255u;
goto P_0c0a85b2;
P_0c0a85b2: /* original 84f4, guest PC 0x0c0a85b2 */
if(!s->budget--) { s->failed_pc=0x0c0a85b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0a85b4;
P_0c0a85b4: /* original 8803, guest PC 0x0c0a85b4 */
if(!s->budget--) { s->failed_pc=0x0c0a85b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a85b6;
P_0c0a85b6: /* original 8b09, guest PC 0x0c0a85b6 */
if(!s->budget--) { s->failed_pc=0x0c0a85b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85b8;
P_0c0a85b8: /* original 2ee8, guest PC 0x0c0a85b8 */
if(!s->budget--) { s->failed_pc=0x0c0a85b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a85ba;
P_0c0a85ba: /* original 8907, guest PC 0x0c0a85ba */
if(!s->budget--) { s->failed_pc=0x0c0a85bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85cc; }
goto P_0c0a85bc;
P_0c0a85bc: /* original 64f2, guest PC 0x0c0a85bc */
if(!s->budget--) { s->failed_pc=0x0c0a85bcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a85be;
P_0c0a85be: /* original 644c, guest PC 0x0c0a85be */
if(!s->budget--) { s->failed_pc=0x0c0a85beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0a85c0;
P_0c0a85c0: /* original 6043, guest PC 0x0c0a85c0 */
if(!s->budget--) { s->failed_pc=0x0c0a85c0u; return 0; }
r[0]=r[4];
goto P_0c0a85c2;
P_0c0a85c2: /* original 8801, guest PC 0x0c0a85c2 */
if(!s->budget--) { s->failed_pc=0x0c0a85c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a85c4;
P_0c0a85c4: /* original 8b02, guest PC 0x0c0a85c4 */
if(!s->budget--) { s->failed_pc=0x0c0a85c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85c6;
P_0c0a85c6: /* original 6043, guest PC 0x0c0a85c6 */
if(!s->budget--) { s->failed_pc=0x0c0a85c6u; return 0; }
r[0]=r[4];
goto P_0c0a85c8;
P_0c0a85c8: /* original 881d, guest PC 0x0c0a85c8 */
if(!s->budget--) { s->failed_pc=0x0c0a85c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0a85ca;
P_0c0a85ca: /* original 8904, guest PC 0x0c0a85ca */
if(!s->budget--) { s->failed_pc=0x0c0a85cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85d6; }
goto P_0c0a85cc;
P_0c0a85cc: /* original e019, guest PC 0x0c0a85cc */
if(!s->budget--) { s->failed_pc=0x0c0a85ccu; return 0; }
r[0]=0x00000019u;
goto P_0c0a85ce;
P_0c0a85ce: /* original 04cc, guest PC 0x0c0a85ce */
if(!s->budget--) { s->failed_pc=0x0c0a85ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85d0;
P_0c0a85d0: /* original 604e, guest PC 0x0c0a85d0 */
if(!s->budget--) { s->failed_pc=0x0c0a85d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a85d2;
P_0c0a85d2: /* original 8802, guest PC 0x0c0a85d2 */
if(!s->budget--) { s->failed_pc=0x0c0a85d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a85d4;
P_0c0a85d4: /* original 894a, guest PC 0x0c0a85d4 */
if(!s->budget--) { s->failed_pc=0x0c0a85d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a85d6;
P_0c0a85d6: /* original d231, guest PC 0x0c0a85d6 */
if(!s->budget--) { s->failed_pc=0x0c0a85d6u; return 0; }
r[2]=read(ram,0x0c0a869cu,4);
goto P_0c0a85d8;
P_0c0a85d8: /* original 420b, guest PC 0x0c0a85d8 */
if(!s->budget--) { s->failed_pc=0x0c0a85d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a85dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a85dcu) { target=s->pc; goto dispatch; }
goto P_0c0a85dc;
P_0c0a85da: /* original 0009, guest PC 0x0c0a85da */
if(!s->budget--) { s->failed_pc=0x0c0a85dau; return 0; }
goto P_0c0a85dc;
P_0c0a85dc: /* original d430, guest PC 0x0c0a85dc */
if(!s->budget--) { s->failed_pc=0x0c0a85dcu; return 0; }
r[4]=read(ram,0x0c0a86a0u,4);
goto P_0c0a85de;
P_0c0a85de: /* original 9050, guest PC 0x0c0a85de */
if(!s->budget--) { s->failed_pc=0x0c0a85deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8682u,2);
goto P_0c0a85e0;
P_0c0a85e0: /* original 5a45, guest PC 0x0c0a85e0 */
if(!s->budget--) { s->failed_pc=0x0c0a85e0u; return 0; }
r[10]=read(ram,r[4]+20,4);
goto P_0c0a85e2;
P_0c0a85e2: /* original 5944, guest PC 0x0c0a85e2 */
if(!s->budget--) { s->failed_pc=0x0c0a85e2u; return 0; }
r[9]=read(ram,r[4]+16,4);
goto P_0c0a85e4;
P_0c0a85e4: /* original 09b4, guest PC 0x0c0a85e4 */
if(!s->budget--) { s->failed_pc=0x0c0a85e4u; return 0; }
write(ram,r[9]+r[0],r[11],1);
goto P_0c0a85e6;
P_0c0a85e6: /* original 0ae4, guest PC 0x0c0a85e6 */
if(!s->budget--) { s->failed_pc=0x0c0a85e6u; return 0; }
write(ram,r[10]+r[0],r[14],1);
goto P_0c0a85e8;
P_0c0a85e8: /* original e050, guest PC 0x0c0a85e8 */
if(!s->budget--) { s->failed_pc=0x0c0a85e8u; return 0; }
r[0]=0x00000050u;
goto P_0c0a85ea;
P_0c0a85ea: /* original 054e, guest PC 0x0c0a85ea */
if(!s->budget--) { s->failed_pc=0x0c0a85eau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0a85ec;
P_0c0a85ec: /* original 5e54, guest PC 0x0c0a85ec */
if(!s->budget--) { s->failed_pc=0x0c0a85ecu; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c0a85ee;
P_0c0a85ee: /* original 1de4, guest PC 0x0c0a85ee */
if(!s->budget--) { s->failed_pc=0x0c0a85eeu; return 0; }
write(ram,r[13]+16,r[14],4);
goto P_0c0a85f0;
P_0c0a85f0: /* original 7eff, guest PC 0x0c0a85f0 */
if(!s->budget--) { s->failed_pc=0x0c0a85f0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a85f2;
P_0c0a85f2: /* original 9847, guest PC 0x0c0a85f2 */
if(!s->budget--) { s->failed_pc=0x0c0a85f2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8684u,2);
goto P_0c0a85f4;
P_0c0a85f4: /* original 4e11, guest PC 0x0c0a85f4 */
if(!s->budget--) { s->failed_pc=0x0c0a85f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a85f6;
P_0c0a85f6: /* original 8900, guest PC 0x0c0a85f6 */
if(!s->budget--) { s->failed_pc=0x0c0a85f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85fa; }
goto P_0c0a85f8;
P_0c0a85f8: /* original 6e83, guest PC 0x0c0a85f8 */
if(!s->budget--) { s->failed_pc=0x0c0a85f8u; return 0; }
r[14]=r[8];
goto P_0c0a85fa;
P_0c0a85fa: /* original 1de5, guest PC 0x0c0a85fa */
if(!s->budget--) { s->failed_pc=0x0c0a85fau; return 0; }
write(ram,r[13]+20,r[14],4);
goto P_0c0a85fc;
P_0c0a85fc: /* original 9043, guest PC 0x0c0a85fc */
if(!s->budget--) { s->failed_pc=0x0c0a85fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8686u,2);
goto P_0c0a85fe;
P_0c0a85fe: /* original 5444, guest PC 0x0c0a85fe */
if(!s->budget--) { s->failed_pc=0x0c0a85feu; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0a8600;
P_0c0a8600: /* original 05ce, guest PC 0x0c0a8600 */
if(!s->budget--) { s->failed_pc=0x0c0a8600u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0a8602;
P_0c0a8602: /* original ec00, guest PC 0x0c0a8602 */
if(!s->budget--) { s->failed_pc=0x0c0a8602u; return 0; }
r[12]=0x00000000u;
goto P_0c0a8604;
P_0c0a8604: /* original 3540, guest PC 0x0c0a8604 */
if(!s->budget--) { s->failed_pc=0x0c0a8604u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8606;
P_0c0a8606: /* original 8d01, guest PC 0x0c0a8606 */
if(!s->budget--) { s->failed_pc=0x0c0a8606u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(cond) { goto P_0c0a860c; }
goto P_0c0a860a;
P_0c0a8608: /* original 66c3, guest PC 0x0c0a8608 */
if(!s->budget--) { s->failed_pc=0x0c0a8608u; return 0; }
r[6]=r[12];
goto P_0c0a860a;
P_0c0a860a: /* original 66b3, guest PC 0x0c0a860a */
if(!s->budget--) { s->failed_pc=0x0c0a860au; return 0; }
r[6]=r[11];
goto P_0c0a860c;
P_0c0a860c: /* original e700, guest PC 0x0c0a860c */
if(!s->budget--) { s->failed_pc=0x0c0a860cu; return 0; }
r[7]=0x00000000u;
goto P_0c0a860e;
P_0c0a860e: /* original 65e3, guest PC 0x0c0a860e */
if(!s->budget--) { s->failed_pc=0x0c0a860eu; return 0; }
r[5]=r[14];
goto P_0c0a8610;
P_0c0a8610: /* original b04c, guest PC 0x0c0a8610 */
if(!s->budget--) { s->failed_pc=0x0c0a8610u; return 0; }
target=code_base|0x0c0a86acu; r[16]=code_base|0x0c0a8614u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8614u) { target=s->pc; goto dispatch; }
goto P_0c0a8614;
P_0c0a8612: /* original 6473, guest PC 0x0c0a8612 */
if(!s->budget--) { s->failed_pc=0x0c0a8612u; return 0; }
r[4]=r[7];
goto P_0c0a8614;
P_0c0a8614: /* original 6403, guest PC 0x0c0a8614 */
if(!s->budget--) { s->failed_pc=0x0c0a8614u; return 0; }
r[4]=r[0];
goto P_0c0a8616;
P_0c0a8616: /* original 7eff, guest PC 0x0c0a8616 */
if(!s->budget--) { s->failed_pc=0x0c0a8616u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8618;
P_0c0a8618: /* original 4e11, guest PC 0x0c0a8618 */
if(!s->budget--) { s->failed_pc=0x0c0a8618u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a861a;
P_0c0a861a: /* original 8900, guest PC 0x0c0a861a */
if(!s->budget--) { s->failed_pc=0x0c0a861au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a861e; }
goto P_0c0a861c;
P_0c0a861c: /* original 6e83, guest PC 0x0c0a861c */
if(!s->budget--) { s->failed_pc=0x0c0a861cu; return 0; }
r[14]=r[8];
goto P_0c0a861e;
P_0c0a861e: /* original 4410, guest PC 0x0c0a861e */
if(!s->budget--) { s->failed_pc=0x0c0a861eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0a8620;
P_0c0a8620: /* original 8bf9, guest PC 0x0c0a8620 */
if(!s->budget--) { s->failed_pc=0x0c0a8620u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8616; }
goto P_0c0a8622;
P_0c0a8622: /* original 64e3, guest PC 0x0c0a8622 */
if(!s->budget--) { s->failed_pc=0x0c0a8622u; return 0; }
r[4]=r[14];
goto P_0c0a8624;
P_0c0a8624: /* original 7401, guest PC 0x0c0a8624 */
if(!s->budget--) { s->failed_pc=0x0c0a8624u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8626;
P_0c0a8626: /* original 3486, guest PC 0x0c0a8626 */
if(!s->budget--) { s->failed_pc=0x0c0a8626u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[8])!=0);
goto P_0c0a8628;
P_0c0a8628: /* original 8f01, guest PC 0x0c0a8628 */
if(!s->budget--) { s->failed_pc=0x0c0a8628u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+24,r[14],4);
if(!cond) { goto P_0c0a862e; }
goto P_0c0a862c;
P_0c0a862a: /* original 1de6, guest PC 0x0c0a862a */
if(!s->budget--) { s->failed_pc=0x0c0a862au; return 0; }
write(ram,r[13]+24,r[14],4);
goto P_0c0a862c;
P_0c0a862c: /* original 64c3, guest PC 0x0c0a862c */
if(!s->budget--) { s->failed_pc=0x0c0a862cu; return 0; }
r[4]=r[12];
goto P_0c0a862e;
P_0c0a862e: /* original 6543, guest PC 0x0c0a862e */
if(!s->budget--) { s->failed_pc=0x0c0a862eu; return 0; }
r[5]=r[4];
goto P_0c0a8630;
P_0c0a8630: /* original 7501, guest PC 0x0c0a8630 */
if(!s->budget--) { s->failed_pc=0x0c0a8630u; return 0; }
r[5]+=0x00000001u;
goto P_0c0a8632;
P_0c0a8632: /* original 3586, guest PC 0x0c0a8632 */
if(!s->budget--) { s->failed_pc=0x0c0a8632u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[8])!=0);
goto P_0c0a8634;
P_0c0a8634: /* original 8b00, guest PC 0x0c0a8634 */
if(!s->budget--) { s->failed_pc=0x0c0a8634u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8638; }
goto P_0c0a8636;
P_0c0a8636: /* original 65c3, guest PC 0x0c0a8636 */
if(!s->budget--) { s->failed_pc=0x0c0a8636u; return 0; }
r[5]=r[12];
goto P_0c0a8638;
P_0c0a8638: /* original 4408, guest PC 0x0c0a8638 */
if(!s->budget--) { s->failed_pc=0x0c0a8638u; return 0; }
r[4]<<=2;
goto P_0c0a863a;
P_0c0a863a: /* original 1d54, guest PC 0x0c0a863a */
if(!s->budget--) { s->failed_pc=0x0c0a863au; return 0; }
write(ram,r[13]+16,r[5],4);
goto P_0c0a863c;
P_0c0a863c: /* original 4408, guest PC 0x0c0a863c */
if(!s->budget--) { s->failed_pc=0x0c0a863cu; return 0; }
r[4]<<=2;
goto P_0c0a863e;
P_0c0a863e: /* original de19, guest PC 0x0c0a863e */
if(!s->budget--) { s->failed_pc=0x0c0a863eu; return 0; }
r[14]=read(ram,0x0c0a86a4u,4);
goto P_0c0a8640;
P_0c0a8640: /* original 4408, guest PC 0x0c0a8640 */
if(!s->budget--) { s->failed_pc=0x0c0a8640u; return 0; }
r[4]<<=2;
goto P_0c0a8642;
P_0c0a8642: /* original 9221, guest PC 0x0c0a8642 */
if(!s->budget--) { s->failed_pc=0x0c0a8642u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a8644;
P_0c0a8644: /* original 4400, guest PC 0x0c0a8644 */
if(!s->budget--) { s->failed_pc=0x0c0a8644u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a8646;
P_0c0a8646: /* original 6593, guest PC 0x0c0a8646 */
if(!s->budget--) { s->failed_pc=0x0c0a8646u; return 0; }
r[5]=r[9];
goto P_0c0a8648;
P_0c0a8648: /* original 3e4c, guest PC 0x0c0a8648 */
if(!s->budget--) { s->failed_pc=0x0c0a8648u; return 0; }
r[14]+=r[4];
goto P_0c0a864a;
P_0c0a864a: /* original 66a3, guest PC 0x0c0a864a */
if(!s->budget--) { s->failed_pc=0x0c0a864au; return 0; }
r[6]=r[10];
goto P_0c0a864c;
P_0c0a864c: /* original 64e2, guest PC 0x0c0a864c */
if(!s->budget--) { s->failed_pc=0x0c0a864cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a864e;
P_0c0a864e: /* original 242b, guest PC 0x0c0a864e */
if(!s->budget--) { s->failed_pc=0x0c0a864eu; return 0; }
r[4]|=r[2];
goto P_0c0a8650;
P_0c0a8650: /* original 2e42, guest PC 0x0c0a8650 */
if(!s->budget--) { s->failed_pc=0x0c0a8650u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a8652;
P_0c0a8652: /* original b4f0, guest PC 0x0c0a8652 */
if(!s->budget--) { s->failed_pc=0x0c0a8652u; return 0; }
target=code_base|0x0c0a9036u; r[16]=code_base|0x0c0a8656u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8656u) { target=s->pc; goto dispatch; }
goto P_0c0a8656;
P_0c0a8654: /* original 64e3, guest PC 0x0c0a8654 */
if(!s->budget--) { s->failed_pc=0x0c0a8654u; return 0; }
r[4]=r[14];
goto P_0c0a8656;
P_0c0a8656: /* original 7e40, guest PC 0x0c0a8656 */
if(!s->budget--) { s->failed_pc=0x0c0a8656u; return 0; }
r[14]+=0x00000040u;
goto P_0c0a8658;
P_0c0a8658: /* original 9316, guest PC 0x0c0a8658 */
if(!s->budget--) { s->failed_pc=0x0c0a8658u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a865a;
P_0c0a865a: /* original 62e2, guest PC 0x0c0a865a */
if(!s->budget--) { s->failed_pc=0x0c0a865au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a865c;
P_0c0a865c: /* original 65a3, guest PC 0x0c0a865c */
if(!s->budget--) { s->failed_pc=0x0c0a865cu; return 0; }
r[5]=r[10];
goto P_0c0a865e;
P_0c0a865e: /* original 6693, guest PC 0x0c0a865e */
if(!s->budget--) { s->failed_pc=0x0c0a865eu; return 0; }
r[6]=r[9];
goto P_0c0a8660;
P_0c0a8660: /* original 223b, guest PC 0x0c0a8660 */
if(!s->budget--) { s->failed_pc=0x0c0a8660u; return 0; }
r[2]|=r[3];
goto P_0c0a8662;
P_0c0a8662: /* original 2e22, guest PC 0x0c0a8662 */
if(!s->budget--) { s->failed_pc=0x0c0a8662u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8664;
P_0c0a8664: /* original b4e7, guest PC 0x0c0a8664 */
if(!s->budget--) { s->failed_pc=0x0c0a8664u; return 0; }
target=code_base|0x0c0a9036u; r[16]=code_base|0x0c0a8668u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8668u) { target=s->pc; goto dispatch; }
goto P_0c0a8668;
P_0c0a8666: /* original 64e3, guest PC 0x0c0a8666 */
if(!s->budget--) { s->failed_pc=0x0c0a8666u; return 0; }
r[4]=r[14];
goto P_0c0a8668;
P_0c0a8668: /* original d30f, guest PC 0x0c0a8668 */
if(!s->budget--) { s->failed_pc=0x0c0a8668u; return 0; }
r[3]=read(ram,0x0c0a86a8u,4);
goto P_0c0a866a;
P_0c0a866a: /* original 1d33, guest PC 0x0c0a866a */
if(!s->budget--) { s->failed_pc=0x0c0a866au; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c0a866c;
P_0c0a866c: /* original 7f0c, guest PC 0x0c0a866c */
if(!s->budget--) { s->failed_pc=0x0c0a866cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a866e;
P_0c0a866e: /* original 4f26, guest PC 0x0c0a866e */
if(!s->budget--) { s->failed_pc=0x0c0a866eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8670;
P_0c0a8670: /* original 68f6, guest PC 0x0c0a8670 */
if(!s->budget--) { s->failed_pc=0x0c0a8670u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a8672;
P_0c0a8672: /* original 69f6, guest PC 0x0c0a8672 */
if(!s->budget--) { s->failed_pc=0x0c0a8672u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a8674;
P_0c0a8674: /* original 6af6, guest PC 0x0c0a8674 */
if(!s->budget--) { s->failed_pc=0x0c0a8674u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8676;
P_0c0a8676: /* original 6bf6, guest PC 0x0c0a8676 */
if(!s->budget--) { s->failed_pc=0x0c0a8676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8678;
P_0c0a8678: /* original 6cf6, guest PC 0x0c0a8678 */
if(!s->budget--) { s->failed_pc=0x0c0a8678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a867a;
P_0c0a867a: /* original 6df6, guest PC 0x0c0a867a */
if(!s->budget--) { s->failed_pc=0x0c0a867au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a867c;
P_0c0a867c: /* original 000b, guest PC 0x0c0a867c */
if(!s->budget--) { s->failed_pc=0x0c0a867cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a867e: /* original 6ef6, guest PC 0x0c0a867e */
if(!s->budget--) { s->failed_pc=0x0c0a867eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8680u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8680u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
