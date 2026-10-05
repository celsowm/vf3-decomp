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
int vf3_advance_branch_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ab8f0u: goto P_0c0ab8f0;
case 0x0c0ab8f2u: goto P_0c0ab8f2;
case 0x0c0ab8f4u: goto P_0c0ab8f4;
case 0x0c0ab8f6u: goto P_0c0ab8f6;
case 0x0c0ab8f8u: goto P_0c0ab8f8;
case 0x0c0ab8fau: goto P_0c0ab8fa;
case 0x0c0ab8fcu: goto P_0c0ab8fc;
case 0x0c0ab8feu: goto P_0c0ab8fe;
case 0x0c0ab900u: goto P_0c0ab900;
case 0x0c0ab902u: goto P_0c0ab902;
case 0x0c0ab904u: goto P_0c0ab904;
case 0x0c0ab906u: goto P_0c0ab906;
case 0x0c0ab908u: goto P_0c0ab908;
case 0x0c0ab90au: goto P_0c0ab90a;
case 0x0c0ab90cu: goto P_0c0ab90c;
case 0x0c0ab90eu: goto P_0c0ab90e;
case 0x0c0ab910u: goto P_0c0ab910;
case 0x0c0ab912u: goto P_0c0ab912;
case 0x0c0ab914u: goto P_0c0ab914;
case 0x0c0ab916u: goto P_0c0ab916;
case 0x0c0ab918u: goto P_0c0ab918;
case 0x0c0ab91au: goto P_0c0ab91a;
case 0x0c0ab91cu: goto P_0c0ab91c;
case 0x0c0ab91eu: goto P_0c0ab91e;
case 0x0c0ab920u: goto P_0c0ab920;
case 0x0c0ab922u: goto P_0c0ab922;
case 0x0c0ab924u: goto P_0c0ab924;
case 0x0c0ab926u: goto P_0c0ab926;
case 0x0c0ab928u: goto P_0c0ab928;
case 0x0c0ab92au: goto P_0c0ab92a;
case 0x0c0ab92cu: goto P_0c0ab92c;
case 0x0c0ab92eu: goto P_0c0ab92e;
case 0x0c0ab930u: goto P_0c0ab930;
case 0x0c0ab932u: goto P_0c0ab932;
case 0x0c0ab934u: goto P_0c0ab934;
case 0x0c0ab936u: goto P_0c0ab936;
case 0x0c0ab938u: goto P_0c0ab938;
case 0x0c0ab93au: goto P_0c0ab93a;
case 0x0c0ab93cu: goto P_0c0ab93c;
case 0x0c0ab93eu: goto P_0c0ab93e;
case 0x0c0ab940u: goto P_0c0ab940;
case 0x0c0ab942u: goto P_0c0ab942;
case 0x0c0ab944u: goto P_0c0ab944;
case 0x0c0ab946u: goto P_0c0ab946;
case 0x0c0ab948u: goto P_0c0ab948;
case 0x0c0ab94au: goto P_0c0ab94a;
case 0x0c0ab94cu: goto P_0c0ab94c;
case 0x0c0ab94eu: goto P_0c0ab94e;
case 0x0c0ab950u: goto P_0c0ab950;
case 0x0c0ab952u: goto P_0c0ab952;
case 0x0c0ab954u: goto P_0c0ab954;
case 0x0c0ab956u: goto P_0c0ab956;
case 0x0c0ab958u: goto P_0c0ab958;
case 0x0c0ab95au: goto P_0c0ab95a;
case 0x0c0ab95cu: goto P_0c0ab95c;
case 0x0c0ab95eu: goto P_0c0ab95e;
case 0x0c0ab960u: goto P_0c0ab960;
case 0x0c0ab962u: goto P_0c0ab962;
case 0x0c0ab964u: goto P_0c0ab964;
case 0x0c0ab966u: goto P_0c0ab966;
case 0x0c0ab968u: goto P_0c0ab968;
case 0x0c0ab96au: goto P_0c0ab96a;
case 0x0c0ab96cu: goto P_0c0ab96c;
case 0x0c0ab96eu: goto P_0c0ab96e;
case 0x0c0ab970u: goto P_0c0ab970;
case 0x0c0ab972u: goto P_0c0ab972;
case 0x0c0ab974u: goto P_0c0ab974;
case 0x0c0ab976u: goto P_0c0ab976;
case 0x0c0ab978u: goto P_0c0ab978;
case 0x0c0ab97au: goto P_0c0ab97a;
case 0x0c0ab97cu: goto P_0c0ab97c;
case 0x0c0ab97eu: goto P_0c0ab97e;
case 0x0c0ab980u: goto P_0c0ab980;
case 0x0c0ab982u: goto P_0c0ab982;
case 0x0c0ab984u: goto P_0c0ab984;
case 0x0c0ab986u: goto P_0c0ab986;
case 0x0c0ab988u: goto P_0c0ab988;
case 0x0c0ab98au: goto P_0c0ab98a;
case 0x0c0ab98cu: goto P_0c0ab98c;
case 0x0c0ab98eu: goto P_0c0ab98e;
case 0x0c0ab9c0u: goto P_0c0ab9c0;
case 0x0c0ab9c2u: goto P_0c0ab9c2;
case 0x0c0ab9c4u: goto P_0c0ab9c4;
case 0x0c0ab9c6u: goto P_0c0ab9c6;
case 0x0c0ab9c8u: goto P_0c0ab9c8;
case 0x0c0ab9cau: goto P_0c0ab9ca;
case 0x0c0ab9ccu: goto P_0c0ab9cc;
case 0x0c0ab9ceu: goto P_0c0ab9ce;
case 0x0c0ab9d0u: goto P_0c0ab9d0;
case 0x0c0ab9d2u: goto P_0c0ab9d2;
case 0x0c0ab9d4u: goto P_0c0ab9d4;
case 0x0c0ab9d6u: goto P_0c0ab9d6;
case 0x0c0ab9d8u: goto P_0c0ab9d8;
case 0x0c0ab9dau: goto P_0c0ab9da;
case 0x0c0ab9dcu: goto P_0c0ab9dc;
case 0x0c0ab9deu: goto P_0c0ab9de;
case 0x0c0ab9e0u: goto P_0c0ab9e0;
case 0x0c0ab9e2u: goto P_0c0ab9e2;
case 0x0c0ab9e4u: goto P_0c0ab9e4;
case 0x0c0ab9e6u: goto P_0c0ab9e6;
case 0x0c0ab9e8u: goto P_0c0ab9e8;
case 0x0c0ab9eau: goto P_0c0ab9ea;
case 0x0c0ab9ecu: goto P_0c0ab9ec;
case 0x0c0ab9eeu: goto P_0c0ab9ee;
case 0x0c0ab9f0u: goto P_0c0ab9f0;
case 0x0c0ab9f2u: goto P_0c0ab9f2;
case 0x0c0ab9f4u: goto P_0c0ab9f4;
case 0x0c0ab9f6u: goto P_0c0ab9f6;
case 0x0c0ab9f8u: goto P_0c0ab9f8;
case 0x0c0ab9fau: goto P_0c0ab9fa;
case 0x0c0ab9fcu: goto P_0c0ab9fc;
case 0x0c0ab9feu: goto P_0c0ab9fe;
case 0x0c0aba00u: goto P_0c0aba00;
case 0x0c0aba02u: goto P_0c0aba02;
case 0x0c0aba04u: goto P_0c0aba04;
case 0x0c0aba06u: goto P_0c0aba06;
case 0x0c0aba08u: goto P_0c0aba08;
case 0x0c0aba0au: goto P_0c0aba0a;
case 0x0c0aba0cu: goto P_0c0aba0c;
case 0x0c0aba0eu: goto P_0c0aba0e;
case 0x0c0aba10u: goto P_0c0aba10;
case 0x0c0aba12u: goto P_0c0aba12;
case 0x0c0aba14u: goto P_0c0aba14;
case 0x0c0aba16u: goto P_0c0aba16;
case 0x0c0aba18u: goto P_0c0aba18;
case 0x0c0aba1au: goto P_0c0aba1a;
case 0x0c0aba1cu: goto P_0c0aba1c;
case 0x0c0aba1eu: goto P_0c0aba1e;
case 0x0c0aba20u: goto P_0c0aba20;
case 0x0c0aba22u: goto P_0c0aba22;
case 0x0c0aba24u: goto P_0c0aba24;
case 0x0c0aba26u: goto P_0c0aba26;
case 0x0c0aba28u: goto P_0c0aba28;
case 0x0c0aba2au: goto P_0c0aba2a;
case 0x0c0aba2cu: goto P_0c0aba2c;
case 0x0c0aba2eu: goto P_0c0aba2e;
case 0x0c0aba30u: goto P_0c0aba30;
case 0x0c0aba32u: goto P_0c0aba32;
case 0x0c0aba34u: goto P_0c0aba34;
case 0x0c0aba36u: goto P_0c0aba36;
case 0x0c0aba38u: goto P_0c0aba38;
case 0x0c0aba3au: goto P_0c0aba3a;
case 0x0c0aba3cu: goto P_0c0aba3c;
case 0x0c0aba3eu: goto P_0c0aba3e;
case 0x0c0aba40u: goto P_0c0aba40;
case 0x0c0aba42u: goto P_0c0aba42;
case 0x0c0aba44u: goto P_0c0aba44;
case 0x0c0aba46u: goto P_0c0aba46;
case 0x0c0aba48u: goto P_0c0aba48;
case 0x0c0aba4au: goto P_0c0aba4a;
case 0x0c0aba4cu: goto P_0c0aba4c;
case 0x0c0aba4eu: goto P_0c0aba4e;
case 0x0c0aba50u: goto P_0c0aba50;
case 0x0c0aba52u: goto P_0c0aba52;
case 0x0c0aba54u: goto P_0c0aba54;
case 0x0c0aba56u: goto P_0c0aba56;
case 0x0c0aba58u: goto P_0c0aba58;
case 0x0c0aba5au: goto P_0c0aba5a;
case 0x0c0aba5cu: goto P_0c0aba5c;
case 0x0c0aba5eu: goto P_0c0aba5e;
case 0x0c0aba60u: goto P_0c0aba60;
case 0x0c0aba62u: goto P_0c0aba62;
case 0x0c0aba64u: goto P_0c0aba64;
case 0x0c0aba66u: goto P_0c0aba66;
case 0x0c0aba68u: goto P_0c0aba68;
case 0x0c0aba6au: goto P_0c0aba6a;
case 0x0c0aba6cu: goto P_0c0aba6c;
case 0x0c0aba6eu: goto P_0c0aba6e;
case 0x0c0aba70u: goto P_0c0aba70;
case 0x0c0aba72u: goto P_0c0aba72;
case 0x0c0aba74u: goto P_0c0aba74;
case 0x0c0aba76u: goto P_0c0aba76;
case 0x0c0aba78u: goto P_0c0aba78;
case 0x0c0aba7au: goto P_0c0aba7a;
case 0x0c0aba7cu: goto P_0c0aba7c;
case 0x0c0aba7eu: goto P_0c0aba7e;
case 0x0c0aba80u: goto P_0c0aba80;
case 0x0c0aba82u: goto P_0c0aba82;
case 0x0c0aba84u: goto P_0c0aba84;
case 0x0c0aba86u: goto P_0c0aba86;
case 0x0c0aba88u: goto P_0c0aba88;
case 0x0c0aba8au: goto P_0c0aba8a;
case 0x0c0aba8cu: goto P_0c0aba8c;
case 0x0c0aba8eu: goto P_0c0aba8e;
case 0x0c0aba90u: goto P_0c0aba90;
case 0x0c0aba92u: goto P_0c0aba92;
case 0x0c0aba94u: goto P_0c0aba94;
case 0x0c0aba96u: goto P_0c0aba96;
case 0x0c0abad0u: goto P_0c0abad0;
case 0x0c0abad2u: goto P_0c0abad2;
case 0x0c0abad4u: goto P_0c0abad4;
case 0x0c0abad6u: goto P_0c0abad6;
case 0x0c0abad8u: goto P_0c0abad8;
case 0x0c0abadau: goto P_0c0abada;
case 0x0c0abadcu: goto P_0c0abadc;
case 0x0c0abadeu: goto P_0c0abade;
case 0x0c0abae0u: goto P_0c0abae0;
case 0x0c0abae2u: goto P_0c0abae2;
case 0x0c0abae4u: goto P_0c0abae4;
case 0x0c0abae6u: goto P_0c0abae6;
case 0x0c0abae8u: goto P_0c0abae8;
case 0x0c0abaeau: goto P_0c0abaea;
case 0x0c0abaecu: goto P_0c0abaec;
case 0x0c0abaeeu: goto P_0c0abaee;
case 0x0c0abaf0u: goto P_0c0abaf0;
case 0x0c0abaf2u: goto P_0c0abaf2;
case 0x0c0abaf4u: goto P_0c0abaf4;
case 0x0c0abaf6u: goto P_0c0abaf6;
case 0x0c0abaf8u: goto P_0c0abaf8;
case 0x0c0abafau: goto P_0c0abafa;
case 0x0c0abafcu: goto P_0c0abafc;
case 0x0c0abafeu: goto P_0c0abafe;
case 0x0c0abb00u: goto P_0c0abb00;
case 0x0c0abb02u: goto P_0c0abb02;
case 0x0c0abb04u: goto P_0c0abb04;
case 0x0c0abb06u: goto P_0c0abb06;
case 0x0c0abb08u: goto P_0c0abb08;
case 0x0c0abb0au: goto P_0c0abb0a;
case 0x0c0abb0cu: goto P_0c0abb0c;
case 0x0c0abb0eu: goto P_0c0abb0e;
case 0x0c0abb10u: goto P_0c0abb10;
case 0x0c0abb12u: goto P_0c0abb12;
case 0x0c0abb14u: goto P_0c0abb14;
case 0x0c0abb16u: goto P_0c0abb16;
case 0x0c0abb18u: goto P_0c0abb18;
case 0x0c0abb1au: goto P_0c0abb1a;
case 0x0c0abb1cu: goto P_0c0abb1c;
case 0x0c0abb1eu: goto P_0c0abb1e;
case 0x0c0abb20u: goto P_0c0abb20;
case 0x0c0abb22u: goto P_0c0abb22;
case 0x0c0abb24u: goto P_0c0abb24;
case 0x0c0abb26u: goto P_0c0abb26;
case 0x0c0abb28u: goto P_0c0abb28;
case 0x0c0abbbau: goto P_0c0abbba;
case 0x0c0abbbcu: goto P_0c0abbbc;
case 0x0c0abbbeu: goto P_0c0abbbe;
case 0x0c0abbc0u: goto P_0c0abbc0;
case 0x0c0abbc2u: goto P_0c0abbc2;
case 0x0c0abbc4u: goto P_0c0abbc4;
case 0x0c0abbc6u: goto P_0c0abbc6;
case 0x0c0abbc8u: goto P_0c0abbc8;
case 0x0c0abbcau: goto P_0c0abbca;
case 0x0c0abbccu: goto P_0c0abbcc;
case 0x0c0abbceu: goto P_0c0abbce;
case 0x0c0abbd0u: goto P_0c0abbd0;
case 0x0c0abbd2u: goto P_0c0abbd2;
case 0x0c0abbd4u: goto P_0c0abbd4;
case 0x0c0abbd6u: goto P_0c0abbd6;
case 0x0c0abbd8u: goto P_0c0abbd8;
case 0x0c0abbdau: goto P_0c0abbda;
case 0x0c0abbdcu: goto P_0c0abbdc;
case 0x0c0abbdeu: goto P_0c0abbde;
case 0x0c0abdc4u: goto P_0c0abdc4;
case 0x0c0abdc6u: goto P_0c0abdc6;
case 0x0c0abdc8u: goto P_0c0abdc8;
case 0x0c0abdcau: goto P_0c0abdca;
case 0x0c0abdccu: goto P_0c0abdcc;
case 0x0c0abdceu: goto P_0c0abdce;
case 0x0c0abdd0u: goto P_0c0abdd0;
case 0x0c0abdd2u: goto P_0c0abdd2;
case 0x0c0abdd4u: goto P_0c0abdd4;
case 0x0c0abdd6u: goto P_0c0abdd6;
case 0x0c0abdd8u: goto P_0c0abdd8;
case 0x0c0abddau: goto P_0c0abdda;
case 0x0c0abddcu: goto P_0c0abddc;
case 0x0c0abddeu: goto P_0c0abdde;
case 0x0c0abde0u: goto P_0c0abde0;
case 0x0c0abde2u: goto P_0c0abde2;
case 0x0c0abde4u: goto P_0c0abde4;
case 0x0c0abde6u: goto P_0c0abde6;
case 0x0c0abde8u: goto P_0c0abde8;
case 0x0c0abdeau: goto P_0c0abdea;
case 0x0c0abdecu: goto P_0c0abdec;
case 0x0c0abdeeu: goto P_0c0abdee;
case 0x0c0abdf0u: goto P_0c0abdf0;
case 0x0c0abdf2u: goto P_0c0abdf2;
case 0x0c0abdf4u: goto P_0c0abdf4;
case 0x0c0abdf6u: goto P_0c0abdf6;
case 0x0c0abdf8u: goto P_0c0abdf8;
case 0x0c0abdfau: goto P_0c0abdfa;
case 0x0c0abe20u: goto P_0c0abe20;
case 0x0c0abe22u: goto P_0c0abe22;
case 0x0c0abe24u: goto P_0c0abe24;
case 0x0c0abe26u: goto P_0c0abe26;
case 0x0c0abe28u: goto P_0c0abe28;
case 0x0c0abe2au: goto P_0c0abe2a;
case 0x0c0abe2cu: goto P_0c0abe2c;
case 0x0c0abe2eu: goto P_0c0abe2e;
case 0x0c0abe30u: goto P_0c0abe30;
case 0x0c0abe32u: goto P_0c0abe32;
case 0x0c0abe34u: goto P_0c0abe34;
case 0x0c0abe36u: goto P_0c0abe36;
case 0x0c0abe38u: goto P_0c0abe38;
case 0x0c0abe3au: goto P_0c0abe3a;
case 0x0c0abe3cu: goto P_0c0abe3c;
case 0x0c0abe3eu: goto P_0c0abe3e;
case 0x0c0abe40u: goto P_0c0abe40;
case 0x0c0abe42u: goto P_0c0abe42;
case 0x0c0abe44u: goto P_0c0abe44;
case 0x0c0abe46u: goto P_0c0abe46;
case 0x0c0abe48u: goto P_0c0abe48;
case 0x0c0abe4au: goto P_0c0abe4a;
case 0x0c0abe4cu: goto P_0c0abe4c;
case 0x0c0abe4eu: goto P_0c0abe4e;
case 0x0c0abe50u: goto P_0c0abe50;
case 0x0c0abe52u: goto P_0c0abe52;
case 0x0c0abe54u: goto P_0c0abe54;
case 0x0c0abe56u: goto P_0c0abe56;
case 0x0c0abe58u: goto P_0c0abe58;
case 0x0c0abe5au: goto P_0c0abe5a;
case 0x0c0abe5cu: goto P_0c0abe5c;
case 0x0c0abe5eu: goto P_0c0abe5e;
case 0x0c0abe60u: goto P_0c0abe60;
case 0x0c0abe62u: goto P_0c0abe62;
case 0x0c0abe64u: goto P_0c0abe64;
case 0x0c0abe66u: goto P_0c0abe66;
case 0x0c0abe68u: goto P_0c0abe68;
case 0x0c0abe6au: goto P_0c0abe6a;
case 0x0c0abe6cu: goto P_0c0abe6c;
case 0x0c0abe6eu: goto P_0c0abe6e;
case 0x0c0abe70u: goto P_0c0abe70;
case 0x0c0abe72u: goto P_0c0abe72;
case 0x0c0abe74u: goto P_0c0abe74;
case 0x0c0abe76u: goto P_0c0abe76;
case 0x0c0abe78u: goto P_0c0abe78;
case 0x0c0abe7au: goto P_0c0abe7a;
case 0x0c0abe7cu: goto P_0c0abe7c;
case 0x0c0abe7eu: goto P_0c0abe7e;
case 0x0c0abe80u: goto P_0c0abe80;
case 0x0c0abe82u: goto P_0c0abe82;
case 0x0c0c1ac2u: goto P_0c0c1ac2;
case 0x0c0c1ac4u: goto P_0c0c1ac4;
case 0x0c0c1ac6u: goto P_0c0c1ac6;
case 0x0c0c1ac8u: goto P_0c0c1ac8;
case 0x0c0c1acau: goto P_0c0c1aca;
case 0x0c0c1accu: goto P_0c0c1acc;
case 0x0c0c1aceu: goto P_0c0c1ace;
case 0x0c0c1ad0u: goto P_0c0c1ad0;
case 0x0c0c1ad2u: goto P_0c0c1ad2;
case 0x0c0c1ad4u: goto P_0c0c1ad4;
case 0x0c0c1ad6u: goto P_0c0c1ad6;
case 0x0c0c1ad8u: goto P_0c0c1ad8;
case 0x0c0c1adau: goto P_0c0c1ada;
case 0x0c0c1adcu: goto P_0c0c1adc;
case 0x0c0c1adeu: goto P_0c0c1ade;
case 0x0c0c1ae0u: goto P_0c0c1ae0;
case 0x0c0c1ae2u: goto P_0c0c1ae2;
case 0x0c0c1ae4u: goto P_0c0c1ae4;
case 0x0c0c1ae6u: goto P_0c0c1ae6;
case 0x0c0c1ae8u: goto P_0c0c1ae8;
case 0x0c0c1aeau: goto P_0c0c1aea;
case 0x0c0c1aecu: goto P_0c0c1aec;
case 0x0c0c1aeeu: goto P_0c0c1aee;
case 0x0c0c1af0u: goto P_0c0c1af0;
case 0x0c0c1af2u: goto P_0c0c1af2;
case 0x0c0c1af4u: goto P_0c0c1af4;
case 0x0c0c1af6u: goto P_0c0c1af6;
case 0x0c0c1af8u: goto P_0c0c1af8;
case 0x0c0c1afau: goto P_0c0c1afa;
case 0x0c0c1afcu: goto P_0c0c1afc;
case 0x0c0c1afeu: goto P_0c0c1afe;
case 0x0c0c1b00u: goto P_0c0c1b00;
case 0x0c0c1b02u: goto P_0c0c1b02;
case 0x0c0c1b04u: goto P_0c0c1b04;
case 0x0c0c1b06u: goto P_0c0c1b06;
case 0x0c0c1b08u: goto P_0c0c1b08;
case 0x0c0c1b0au: goto P_0c0c1b0a;
case 0x0c0c1b0cu: goto P_0c0c1b0c;
case 0x0c0c1b0eu: goto P_0c0c1b0e;
case 0x0c0c1b10u: goto P_0c0c1b10;
case 0x0c0c1b12u: goto P_0c0c1b12;
case 0x0c0c1b14u: goto P_0c0c1b14;
case 0x0c0c1b16u: goto P_0c0c1b16;
case 0x0c0c1b18u: goto P_0c0c1b18;
case 0x0c0c1b1au: goto P_0c0c1b1a;
case 0x0c0c1b1cu: goto P_0c0c1b1c;
case 0x0c0c1b1eu: goto P_0c0c1b1e;
case 0x0c0c1b20u: goto P_0c0c1b20;
case 0x0c0c1b22u: goto P_0c0c1b22;
case 0x0c0c1b24u: goto P_0c0c1b24;
case 0x0c0c1b26u: goto P_0c0c1b26;
case 0x0c0c1b28u: goto P_0c0c1b28;
case 0x0c0c1b2au: goto P_0c0c1b2a;
case 0x0c0c1b2cu: goto P_0c0c1b2c;
case 0x0c0c1b2eu: goto P_0c0c1b2e;
case 0x0c0c1b30u: goto P_0c0c1b30;
case 0x0c0c1b32u: goto P_0c0c1b32;
case 0x0c0c1b34u: goto P_0c0c1b34;
case 0x0c0c1b36u: goto P_0c0c1b36;
case 0x0c0c1b38u: goto P_0c0c1b38;
case 0x0c0c1b3au: goto P_0c0c1b3a;
case 0x0c0c1b3cu: goto P_0c0c1b3c;
case 0x0c0c1b3eu: goto P_0c0c1b3e;
case 0x0c0c1b40u: goto P_0c0c1b40;
case 0x0c0c1b42u: goto P_0c0c1b42;
case 0x0c0c1b44u: goto P_0c0c1b44;
case 0x0c0c1b46u: goto P_0c0c1b46;
case 0x0c0c1b48u: goto P_0c0c1b48;
case 0x0c0c1b4au: goto P_0c0c1b4a;
case 0x0c0c1b4cu: goto P_0c0c1b4c;
case 0x0c0c1b4eu: goto P_0c0c1b4e;
case 0x0c0c1b50u: goto P_0c0c1b50;
case 0x0c0c1b52u: goto P_0c0c1b52;
case 0x0c0c1b54u: goto P_0c0c1b54;
case 0x0c0c1b56u: goto P_0c0c1b56;
case 0x0c0c1b58u: goto P_0c0c1b58;
case 0x0c0c1b5au: goto P_0c0c1b5a;
case 0x0c0c1b5cu: goto P_0c0c1b5c;
case 0x0c0c1b5eu: goto P_0c0c1b5e;
case 0x0c0c1b60u: goto P_0c0c1b60;
case 0x0c0c1b62u: goto P_0c0c1b62;
case 0x0c0c1b64u: goto P_0c0c1b64;
case 0x0c0c1b66u: goto P_0c0c1b66;
case 0x0c0c1b68u: goto P_0c0c1b68;
case 0x0c0c1b6au: goto P_0c0c1b6a;
case 0x0c0c1b6cu: goto P_0c0c1b6c;
case 0x0c0c1b6eu: goto P_0c0c1b6e;
case 0x0c0c1b70u: goto P_0c0c1b70;
case 0x0c0c1b72u: goto P_0c0c1b72;
case 0x0c0c1b74u: goto P_0c0c1b74;
case 0x0c0c1b76u: goto P_0c0c1b76;
case 0x0c0c1b78u: goto P_0c0c1b78;
case 0x0c0c1b7au: goto P_0c0c1b7a;
case 0x0c0c1b7cu: goto P_0c0c1b7c;
case 0x0c0c1b7eu: goto P_0c0c1b7e;
case 0x0c0c1b80u: goto P_0c0c1b80;
case 0x0c0c1b82u: goto P_0c0c1b82;
case 0x0c0c1b84u: goto P_0c0c1b84;
case 0x0c0c1b86u: goto P_0c0c1b86;
case 0x0c0c1b88u: goto P_0c0c1b88;
case 0x0c0c1b8au: goto P_0c0c1b8a;
case 0x0c0c1b8cu: goto P_0c0c1b8c;
case 0x0c0c1b8eu: goto P_0c0c1b8e;
case 0x0c0c1b90u: goto P_0c0c1b90;
case 0x0c0c1b92u: goto P_0c0c1b92;
case 0x0c0c1b94u: goto P_0c0c1b94;
case 0x0c0c1b96u: goto P_0c0c1b96;
case 0x0c0c1b98u: goto P_0c0c1b98;
case 0x0c0c1b9au: goto P_0c0c1b9a;
case 0x0c0c1b9cu: goto P_0c0c1b9c;
case 0x0c0c1b9eu: goto P_0c0c1b9e;
case 0x0c0c1ba0u: goto P_0c0c1ba0;
case 0x0c0c1ba2u: goto P_0c0c1ba2;
case 0x0c0c1ba4u: goto P_0c0c1ba4;
case 0x0c0c1ba6u: goto P_0c0c1ba6;
case 0x0c0c1ba8u: goto P_0c0c1ba8;
case 0x0c0c1baau: goto P_0c0c1baa;
case 0x0c0c1bacu: goto P_0c0c1bac;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ab8f0: /* original 4f22, guest PC 0x0c0ab8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab8f2;
P_0c0ab8f2: /* original d32f, guest PC 0x0c0ab8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f2u; return 0; }
r[3]=read(ram,0x0c0ab9b0u,4);
goto P_0c0ab8f4;
P_0c0ab8f4: /* original d42d, guest PC 0x0c0ab8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f4u; return 0; }
r[4]=read(ram,0x0c0ab9acu,4);
goto P_0c0ab8f6;
P_0c0ab8f6: /* original 7ff8, guest PC 0x0c0ab8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ab8f8;
P_0c0ab8f8: /* original 1f31, guest PC 0x0c0ab8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ab8fa;
P_0c0ab8fa: /* original 904a, guest PC 0x0c0ab8fa */
if(!s->budget--) { s->failed_pc=0x0c0ab8fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab992u,2);
goto P_0c0ab8fc;
P_0c0ab8fc: /* original f3e6, guest PC 0x0c0ab8fc */
if(!s->budget--) { s->failed_pc=0x0c0ab8fcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab8fe;
P_0c0ab8fe: /* original e024, guest PC 0x0c0ab8fe */
if(!s->budget--) { s->failed_pc=0x0c0ab8feu; return 0; }
r[0]=0x00000024u;
goto P_0c0ab900;
P_0c0ab900: /* original fe37, guest PC 0x0c0ab900 */
if(!s->budget--) { s->failed_pc=0x0c0ab900u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab902;
P_0c0ab902: /* original 9047, guest PC 0x0c0ab902 */
if(!s->budget--) { s->failed_pc=0x0c0ab902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab994u,2);
goto P_0c0ab904;
P_0c0ab904: /* original f3e6, guest PC 0x0c0ab904 */
if(!s->budget--) { s->failed_pc=0x0c0ab904u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab906;
P_0c0ab906: /* original e02c, guest PC 0x0c0ab906 */
if(!s->budget--) { s->failed_pc=0x0c0ab906u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab908;
P_0c0ab908: /* original fe37, guest PC 0x0c0ab908 */
if(!s->budget--) { s->failed_pc=0x0c0ab908u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab90a;
P_0c0ab90a: /* original e03e, guest PC 0x0c0ab90a */
if(!s->budget--) { s->failed_pc=0x0c0ab90au; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab90c;
P_0c0ab90c: /* original 03ed, guest PC 0x0c0ab90c */
if(!s->budget--) { s->failed_pc=0x0c0ab90cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab90e;
P_0c0ab90e: /* original 9042, guest PC 0x0c0ab90e */
if(!s->budget--) { s->failed_pc=0x0c0ab90eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab996u,2);
goto P_0c0ab910;
P_0c0ab910: /* original 02ed, guest PC 0x0c0ab910 */
if(!s->budget--) { s->failed_pc=0x0c0ab910u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab912;
P_0c0ab912: /* original 3322, guest PC 0x0c0ab912 */
if(!s->budget--) { s->failed_pc=0x0c0ab912u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab914;
P_0c0ab914: /* original 8d06, guest PC 0x0c0ab914 */
if(!s->budget--) { s->failed_pc=0x0c0ab914u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0ab924; }
goto P_0c0ab918;
P_0c0ab916: /* original 6d53, guest PC 0x0c0ab916 */
if(!s->budget--) { s->failed_pc=0x0c0ab916u; return 0; }
r[13]=r[5];
goto P_0c0ab918;
P_0c0ab918: /* original e048, guest PC 0x0c0ab918 */
if(!s->budget--) { s->failed_pc=0x0c0ab918u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab91a;
P_0c0ab91a: /* original d326, guest PC 0x0c0ab91a */
if(!s->budget--) { s->failed_pc=0x0c0ab91au; return 0; }
r[3]=read(ram,0x0c0ab9b4u,4);
goto P_0c0ab91c;
P_0c0ab91c: /* original 02ee, guest PC 0x0c0ab91c */
if(!s->budget--) { s->failed_pc=0x0c0ab91cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab91e;
P_0c0ab91e: /* original 2239, guest PC 0x0c0ab91e */
if(!s->budget--) { s->failed_pc=0x0c0ab91eu; return 0; }
r[2]&=r[3];
goto P_0c0ab920;
P_0c0ab920: /* original a0b5, guest PC 0x0c0ab920 */
if(!s->budget--) { s->failed_pc=0x0c0ab920u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0aba8e;
P_0c0ab922: /* original 0e26, guest PC 0x0c0ab922 */
if(!s->budget--) { s->failed_pc=0x0c0ab922u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab924;
P_0c0ab924: /* original e061, guest PC 0x0c0ab924 */
if(!s->budget--) { s->failed_pc=0x0c0ab924u; return 0; }
r[0]=0x00000061u;
goto P_0c0ab926;
P_0c0ab926: /* original 00ec, guest PC 0x0c0ab926 */
if(!s->budget--) { s->failed_pc=0x0c0ab926u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab928;
P_0c0ab928: /* original 600c, guest PC 0x0c0ab928 */
if(!s->budget--) { s->failed_pc=0x0c0ab928u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab92a;
P_0c0ab92a: /* original 8809, guest PC 0x0c0ab92a */
if(!s->budget--) { s->failed_pc=0x0c0ab92au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0ab92c;
P_0c0ab92c: /* original 8909, guest PC 0x0c0ab92c */
if(!s->budget--) { s->failed_pc=0x0c0ab92cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab942; }
goto P_0c0ab92e;
P_0c0ab92e: /* original 9034, guest PC 0x0c0ab92e */
if(!s->budget--) { s->failed_pc=0x0c0ab92eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab99au,2);
goto P_0c0ab930;
P_0c0ab930: /* original 9332, guest PC 0x0c0ab930 */
if(!s->budget--) { s->failed_pc=0x0c0ab930u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab998u,2);
goto P_0c0ab932;
P_0c0ab932: /* original 024e, guest PC 0x0c0ab932 */
if(!s->budget--) { s->failed_pc=0x0c0ab932u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0ab934;
P_0c0ab934: /* original 2238, guest PC 0x0c0ab934 */
if(!s->budget--) { s->failed_pc=0x0c0ab934u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab936;
P_0c0ab936: /* original 8904, guest PC 0x0c0ab936 */
if(!s->budget--) { s->failed_pc=0x0c0ab936u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab942; }
goto P_0c0ab938;
P_0c0ab938: /* original 65d3, guest PC 0x0c0ab938 */
if(!s->budget--) { s->failed_pc=0x0c0ab938u; return 0; }
r[5]=r[13];
goto P_0c0ab93a;
P_0c0ab93a: /* original b13e, guest PC 0x0c0ab93a */
if(!s->budget--) { s->failed_pc=0x0c0ab93au; return 0; }
target=0x0c0abbbau; r[16]=0x0c0ab93eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab93eu) { target=s->pc; goto dispatch; }
goto P_0c0ab93e;
P_0c0ab93c: /* original 64e3, guest PC 0x0c0ab93c */
if(!s->budget--) { s->failed_pc=0x0c0ab93cu; return 0; }
r[4]=r[14];
goto P_0c0ab93e;
P_0c0ab93e: /* original a0a6, guest PC 0x0c0ab93e */
if(!s->budget--) { s->failed_pc=0x0c0ab93eu; return 0; }
goto P_0c0aba8e;
P_0c0ab940: /* original 0009, guest PC 0x0c0ab940 */
if(!s->budget--) { s->failed_pc=0x0c0ab940u; return 0; }
goto P_0c0ab942;
P_0c0ab942: /* original d31d, guest PC 0x0c0ab942 */
if(!s->budget--) { s->failed_pc=0x0c0ab942u; return 0; }
r[3]=read(ram,0x0c0ab9b8u,4);
goto P_0c0ab944;
P_0c0ab944: /* original 66e3, guest PC 0x0c0ab944 */
if(!s->budget--) { s->failed_pc=0x0c0ab944u; return 0; }
r[6]=r[14];
goto P_0c0ab946;
P_0c0ab946: /* original 65d3, guest PC 0x0c0ab946 */
if(!s->budget--) { s->failed_pc=0x0c0ab946u; return 0; }
r[5]=r[13];
goto P_0c0ab948;
P_0c0ab948: /* original 7648, guest PC 0x0c0ab948 */
if(!s->budget--) { s->failed_pc=0x0c0ab948u; return 0; }
r[6]+=0x00000048u;
goto P_0c0ab94a;
P_0c0ab94a: /* original 430b, guest PC 0x0c0ab94a */
if(!s->budget--) { s->failed_pc=0x0c0ab94au; return 0; }
target=r[3];
r[16]=0x0c0ab94eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab94eu) { target=s->pc; goto dispatch; }
goto P_0c0ab94e;
P_0c0ab94c: /* original 64e3, guest PC 0x0c0ab94c */
if(!s->budget--) { s->failed_pc=0x0c0ab94cu; return 0; }
r[4]=r[14];
goto P_0c0ab94e;
P_0c0ab94e: /* original 62d2, guest PC 0x0c0ab94e */
if(!s->budget--) { s->failed_pc=0x0c0ab94eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab950;
P_0c0ab950: /* original 2e22, guest PC 0x0c0ab950 */
if(!s->budget--) { s->failed_pc=0x0c0ab950u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab952;
P_0c0ab952: /* original 901e, guest PC 0x0c0ab952 */
if(!s->budget--) { s->failed_pc=0x0c0ab952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab992u,2);
goto P_0c0ab954;
P_0c0ab954: /* original f3e6, guest PC 0x0c0ab954 */
if(!s->budget--) { s->failed_pc=0x0c0ab954u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab956;
P_0c0ab956: /* original e024, guest PC 0x0c0ab956 */
if(!s->budget--) { s->failed_pc=0x0c0ab956u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab958;
P_0c0ab958: /* original fe37, guest PC 0x0c0ab958 */
if(!s->budget--) { s->failed_pc=0x0c0ab958u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab95a;
P_0c0ab95a: /* original 901b, guest PC 0x0c0ab95a */
if(!s->budget--) { s->failed_pc=0x0c0ab95au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab994u,2);
goto P_0c0ab95c;
P_0c0ab95c: /* original f3e6, guest PC 0x0c0ab95c */
if(!s->budget--) { s->failed_pc=0x0c0ab95cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab95e;
P_0c0ab95e: /* original e02c, guest PC 0x0c0ab95e */
if(!s->budget--) { s->failed_pc=0x0c0ab95eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab960;
P_0c0ab960: /* original fe37, guest PC 0x0c0ab960 */
if(!s->budget--) { s->failed_pc=0x0c0ab960u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab962;
P_0c0ab962: /* original b275, guest PC 0x0c0ab962 */
if(!s->budget--) { s->failed_pc=0x0c0ab962u; return 0; }
target=0x0c0abe50u; r[16]=0x0c0ab966u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab966u) { target=s->pc; goto dispatch; }
goto P_0c0ab966;
P_0c0ab964: /* original 64e3, guest PC 0x0c0ab964 */
if(!s->budget--) { s->failed_pc=0x0c0ab964u; return 0; }
r[4]=r[14];
goto P_0c0ab966;
P_0c0ab966: /* original 62d2, guest PC 0x0c0ab966 */
if(!s->budget--) { s->failed_pc=0x0c0ab966u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab968;
P_0c0ab968: /* original 9318, guest PC 0x0c0ab968 */
if(!s->budget--) { s->failed_pc=0x0c0ab968u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab99cu,2);
goto P_0c0ab96a;
P_0c0ab96a: /* original 2238, guest PC 0x0c0ab96a */
if(!s->budget--) { s->failed_pc=0x0c0ab96au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab96c;
P_0c0ab96c: /* original 8b28, guest PC 0x0c0ab96c */
if(!s->budget--) { s->failed_pc=0x0c0ab96cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab9c0; }
goto P_0c0ab96e;
P_0c0ab96e: /* original 50f1, guest PC 0x0c0ab96e */
if(!s->budget--) { s->failed_pc=0x0c0ab96eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0ab970;
P_0c0ab970: /* original e11c, guest PC 0x0c0ab970 */
if(!s->budget--) { s->failed_pc=0x0c0ab970u; return 0; }
r[1]=0x0000001cu;
goto P_0c0ab972;
P_0c0ab972: /* original d212, guest PC 0x0c0ab972 */
if(!s->budget--) { s->failed_pc=0x0c0ab972u; return 0; }
r[2]=read(ram,0x0c0ab9bcu,4);
goto P_0c0ab974;
P_0c0ab974: /* original 001c, guest PC 0x0c0ab974 */
if(!s->budget--) { s->failed_pc=0x0c0ab974u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0ab976;
P_0c0ab976: /* original 600c, guest PC 0x0c0ab976 */
if(!s->budget--) { s->failed_pc=0x0c0ab976u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab978;
P_0c0ab978: /* original c90f, guest PC 0x0c0ab978 */
if(!s->budget--) { s->failed_pc=0x0c0ab978u; return 0; }
r[0]&=15u;
goto P_0c0ab97a;
P_0c0ab97a: /* original 4008, guest PC 0x0c0ab97a */
if(!s->budget--) { s->failed_pc=0x0c0ab97au; return 0; }
r[0]<<=2;
goto P_0c0ab97c;
P_0c0ab97c: /* original f326, guest PC 0x0c0ab97c */
if(!s->budget--) { s->failed_pc=0x0c0ab97cu; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c0ab97e;
P_0c0ab97e: /* original e00c, guest PC 0x0c0ab97e */
if(!s->budget--) { s->failed_pc=0x0c0ab97eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab980;
P_0c0ab980: /* original ff3a, guest PC 0x0c0ab980 */
if(!s->budget--) { s->failed_pc=0x0c0ab980u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab982;
P_0c0ab982: /* original f2d6, guest PC 0x0c0ab982 */
if(!s->budget--) { s->failed_pc=0x0c0ab982u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c0ab984;
P_0c0ab984: /* original f235, guest PC 0x0c0ab984 */
if(!s->budget--) { s->failed_pc=0x0c0ab984u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab986;
P_0c0ab986: /* original 8b01, guest PC 0x0c0ab986 */
if(!s->budget--) { s->failed_pc=0x0c0ab986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab98c; }
goto P_0c0ab988;
P_0c0ab988: /* original a081, guest PC 0x0c0ab988 */
if(!s->budget--) { s->failed_pc=0x0c0ab988u; return 0; }
goto P_0c0aba8e;
P_0c0ab98a: /* original 0009, guest PC 0x0c0ab98a */
if(!s->budget--) { s->failed_pc=0x0c0ab98au; return 0; }
goto P_0c0ab98c;
P_0c0ab98c: /* original a04e, guest PC 0x0c0ab98c */
if(!s->budget--) { s->failed_pc=0x0c0ab98cu; return 0; }
goto P_0c0aba2c;
P_0c0ab98e: /* original 0009, guest PC 0x0c0ab98e */
if(!s->budget--) { s->failed_pc=0x0c0ab98eu; return 0; }
return vf3_matrix_family(0x0c0ab990u,s,ram);
P_0c0ab9c0: /* original 906a, guest PC 0x0c0ab9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba98u,2);
goto P_0c0ab9c2;
P_0c0ab9c2: /* original 00ec, guest PC 0x0c0ab9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab9c4;
P_0c0ab9c4: /* original 600c, guest PC 0x0c0ab9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab9c6;
P_0c0ab9c6: /* original c804, guest PC 0x0c0ab9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0ab9c8;
P_0c0ab9c8: /* original 8b05, guest PC 0x0c0ab9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab9d6; }
goto P_0c0ab9ca;
P_0c0ab9ca: /* original e03e, guest PC 0x0c0ab9ca */
if(!s->budget--) { s->failed_pc=0x0c0ab9cau; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab9cc;
P_0c0ab9cc: /* original 03ed, guest PC 0x0c0ab9cc */
if(!s->budget--) { s->failed_pc=0x0c0ab9ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab9ce;
P_0c0ab9ce: /* original 9064, guest PC 0x0c0ab9ce */
if(!s->budget--) { s->failed_pc=0x0c0ab9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9au,2);
goto P_0c0ab9d0;
P_0c0ab9d0: /* original 02ed, guest PC 0x0c0ab9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab9d2;
P_0c0ab9d2: /* original 3322, guest PC 0x0c0ab9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab9d4;
P_0c0ab9d4: /* original 8b5b, guest PC 0x0c0ab9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba8e; }
goto P_0c0ab9d6;
P_0c0ab9d6: /* original 9061, guest PC 0x0c0ab9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9cu,2);
goto P_0c0ab9d8;
P_0c0ab9d8: /* original f3e6, guest PC 0x0c0ab9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab9da;
P_0c0ab9da: /* original c735, guest PC 0x0c0ab9da */
if(!s->budget--) { s->failed_pc=0x0c0ab9dau; return 0; }
r[0]=0x0c0abab0u;
goto P_0c0ab9dc;
P_0c0ab9dc: /* original ff3a, guest PC 0x0c0ab9dc */
if(!s->budget--) { s->failed_pc=0x0c0ab9dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab9de;
P_0c0ab9de: /* original f408, guest PC 0x0c0ab9de */
if(!s->budget--) { s->failed_pc=0x0c0ab9deu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ab9e0;
P_0c0ab9e0: /* original c734, guest PC 0x0c0ab9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e0u; return 0; }
r[0]=0x0c0abab4u;
goto P_0c0ab9e2;
P_0c0ab9e2: /* original f508, guest PC 0x0c0ab9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e2u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0ab9e4;
P_0c0ab9e4: /* original e00c, guest PC 0x0c0ab9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab9e6;
P_0c0ab9e6: /* original f350, guest PC 0x0c0ab9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0ab9e8;
P_0c0ab9e8: /* original ff3a, guest PC 0x0c0ab9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab9ea;
P_0c0ab9ea: /* original f2d6, guest PC 0x0c0ab9ea */
if(!s->budget--) { s->failed_pc=0x0c0ab9eau; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c0ab9ec;
P_0c0ab9ec: /* original f235, guest PC 0x0c0ab9ec */
if(!s->budget--) { s->failed_pc=0x0c0ab9ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab9ee;
P_0c0ab9ee: /* original 894e, guest PC 0x0c0ab9ee */
if(!s->budget--) { s->failed_pc=0x0c0ab9eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba8e; }
goto P_0c0ab9f0;
P_0c0ab9f0: /* original 9055, guest PC 0x0c0ab9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9eu,2);
goto P_0c0ab9f2;
P_0c0ab9f2: /* original e51c, guest PC 0x0c0ab9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f2u; return 0; }
r[5]=0x0000001cu;
goto P_0c0ab9f4;
P_0c0ab9f4: /* original 9456, guest PC 0x0c0ab9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa4u,2);
goto P_0c0ab9f6;
P_0c0ab9f6: /* original 07ee, guest PC 0x0c0ab9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f6u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0ab9f8;
P_0c0ab9f8: /* original 9052, guest PC 0x0c0ab9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa0u,2);
goto P_0c0ab9fa;
P_0c0ab9fa: /* original 34ec, guest PC 0x0c0ab9fa */
if(!s->budget--) { s->failed_pc=0x0c0ab9fau; return 0; }
r[4]+=r[14];
goto P_0c0ab9fc;
P_0c0ab9fc: /* original 9651, guest PC 0x0c0ab9fc */
if(!s->budget--) { s->failed_pc=0x0c0ab9fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa2u,2);
goto P_0c0ab9fe;
P_0c0ab9fe: /* original f3e6, guest PC 0x0c0ab9fe */
if(!s->budget--) { s->failed_pc=0x0c0ab9feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0aba00;
P_0c0aba00: /* original c72d, guest PC 0x0c0aba00 */
if(!s->budget--) { s->failed_pc=0x0c0aba00u; return 0; }
r[0]=0x0c0abab8u;
goto P_0c0aba02;
P_0c0aba02: /* original 36ec, guest PC 0x0c0aba02 */
if(!s->budget--) { s->failed_pc=0x0c0aba02u; return 0; }
r[6]+=r[14];
goto P_0c0aba04;
P_0c0aba04: /* original f341, guest PC 0x0c0aba04 */
if(!s->budget--) { s->failed_pc=0x0c0aba04u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c0aba06;
P_0c0aba06: /* original ff3a, guest PC 0x0c0aba06 */
if(!s->budget--) { s->failed_pc=0x0c0aba06u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0aba08;
P_0c0aba08: /* original f608, guest PC 0x0c0aba08 */
if(!s->budget--) { s->failed_pc=0x0c0aba08u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aba0a;
P_0c0aba0a: /* original e004, guest PC 0x0c0aba0a */
if(!s->budget--) { s->failed_pc=0x0c0aba0au; return 0; }
r[0]=0x00000004u;
goto P_0c0aba0c;
P_0c0aba0c: /* original f549, guest PC 0x0c0aba0c */
if(!s->budget--) { s->failed_pc=0x0c0aba0cu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0aba0e;
P_0c0aba0e: /* original f476, guest PC 0x0c0aba0e */
if(!s->budget--) { s->failed_pc=0x0c0aba0eu; return 0; }
vf3_matrix_load(s,ram,4,r[7]+r[0]);
goto P_0c0aba10;
P_0c0aba10: /* original f769, guest PC 0x0c0aba10 */
if(!s->budget--) { s->failed_pc=0x0c0aba10u; return 0; }
vf3_matrix_load(s,ram,7,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0aba12;
P_0c0aba12: /* original f451, guest PC 0x0c0aba12 */
if(!s->budget--) { s->failed_pc=0x0c0aba12u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0aba14;
P_0c0aba14: /* original f54c, guest PC 0x0c0aba14 */
if(!s->budget--) { s->failed_pc=0x0c0aba14u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0aba16;
P_0c0aba16: /* original f561, guest PC 0x0c0aba16 */
if(!s->budget--) { s->failed_pc=0x0c0aba16u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0aba18;
P_0c0aba18: /* original f575, guest PC 0x0c0aba18 */
if(!s->budget--) { s->failed_pc=0x0c0aba18u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[7]))!=0);
goto P_0c0aba1a;
P_0c0aba1a: /* original 8d03, guest PC 0x0c0aba1a */
if(!s->budget--) { s->failed_pc=0x0c0aba1au; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000cu;
if(cond) { goto P_0c0aba24; }
goto P_0c0aba1e;
P_0c0aba1c: /* original 770c, guest PC 0x0c0aba1c */
if(!s->budget--) { s->failed_pc=0x0c0aba1cu; return 0; }
r[7]+=0x0000000cu;
goto P_0c0aba1e;
P_0c0aba1e: /* original f3f8, guest PC 0x0c0aba1e */
if(!s->budget--) { s->failed_pc=0x0c0aba1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0aba20;
P_0c0aba20: /* original f345, guest PC 0x0c0aba20 */
if(!s->budget--) { s->failed_pc=0x0c0aba20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0aba22;
P_0c0aba22: /* original 8903, guest PC 0x0c0aba22 */
if(!s->budget--) { s->failed_pc=0x0c0aba22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba2c; }
goto P_0c0aba24;
P_0c0aba24: /* original 4510, guest PC 0x0c0aba24 */
if(!s->budget--) { s->failed_pc=0x0c0aba24u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c0aba26;
P_0c0aba26: /* original 8bf0, guest PC 0x0c0aba26 */
if(!s->budget--) { s->failed_pc=0x0c0aba26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba0a; }
goto P_0c0aba28;
P_0c0aba28: /* original a031, guest PC 0x0c0aba28 */
if(!s->budget--) { s->failed_pc=0x0c0aba28u; return 0; }
goto P_0c0aba8e;
P_0c0aba2a: /* original 0009, guest PC 0x0c0aba2a */
if(!s->budget--) { s->failed_pc=0x0c0aba2au; return 0; }
goto P_0c0aba2c;
P_0c0aba2c: /* original d323, guest PC 0x0c0aba2c */
if(!s->budget--) { s->failed_pc=0x0c0aba2cu; return 0; }
r[3]=read(ram,0x0c0ababcu,4);
goto P_0c0aba2e;
P_0c0aba2e: /* original 64f3, guest PC 0x0c0aba2e */
if(!s->budget--) { s->failed_pc=0x0c0aba2eu; return 0; }
r[4]=r[15];
goto P_0c0aba30;
P_0c0aba30: /* original 9039, guest PC 0x0c0aba30 */
if(!s->budget--) { s->failed_pc=0x0c0aba30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa6u,2);
goto P_0c0aba32;
P_0c0aba32: /* original 430b, guest PC 0x0c0aba32 */
if(!s->budget--) { s->failed_pc=0x0c0aba32u; return 0; }
target=r[3];
r[16]=0x0c0aba36u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aba36u) { target=s->pc; goto dispatch; }
goto P_0c0aba36;
P_0c0aba34: /* original f4e6, guest PC 0x0c0aba34 */
if(!s->budget--) { s->failed_pc=0x0c0aba34u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aba36;
P_0c0aba36: /* original f38d, guest PC 0x0c0aba36 */
if(!s->budget--) { s->failed_pc=0x0c0aba36u; return 0; }
fr[3]=0;
goto P_0c0aba38;
P_0c0aba38: /* original f305, guest PC 0x0c0aba38 */
if(!s->budget--) { s->failed_pc=0x0c0aba38u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c0aba3a;
P_0c0aba3a: /* original 8903, guest PC 0x0c0aba3a */
if(!s->budget--) { s->failed_pc=0x0c0aba3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba44; }
goto P_0c0aba3c;
P_0c0aba3c: /* original 62d2, guest PC 0x0c0aba3c */
if(!s->budget--) { s->failed_pc=0x0c0aba3cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aba3e;
P_0c0aba3e: /* original d320, guest PC 0x0c0aba3e */
if(!s->budget--) { s->failed_pc=0x0c0aba3eu; return 0; }
r[3]=read(ram,0x0c0abac0u,4);
goto P_0c0aba40;
P_0c0aba40: /* original 2238, guest PC 0x0c0aba40 */
if(!s->budget--) { s->failed_pc=0x0c0aba40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aba42;
P_0c0aba42: /* original 8b07, guest PC 0x0c0aba42 */
if(!s->budget--) { s->failed_pc=0x0c0aba42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba54; }
goto P_0c0aba44;
P_0c0aba44: /* original 9030, guest PC 0x0c0aba44 */
if(!s->budget--) { s->failed_pc=0x0c0aba44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa8u,2);
goto P_0c0aba46;
P_0c0aba46: /* original 01ee, guest PC 0x0c0aba46 */
if(!s->budget--) { s->failed_pc=0x0c0aba46u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aba48;
P_0c0aba48: /* original 2118, guest PC 0x0c0aba48 */
if(!s->budget--) { s->failed_pc=0x0c0aba48u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0aba4a;
P_0c0aba4a: /* original 8b20, guest PC 0x0c0aba4a */
if(!s->budget--) { s->failed_pc=0x0c0aba4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba8e; }
goto P_0c0aba4c;
P_0c0aba4c: /* original 902d, guest PC 0x0c0aba4c */
if(!s->budget--) { s->failed_pc=0x0c0aba4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaaau,2);
goto P_0c0aba4e;
P_0c0aba4e: /* original 01ee, guest PC 0x0c0aba4e */
if(!s->budget--) { s->failed_pc=0x0c0aba4eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aba50;
P_0c0aba50: /* original 2118, guest PC 0x0c0aba50 */
if(!s->budget--) { s->failed_pc=0x0c0aba50u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0aba52;
P_0c0aba52: /* original 891c, guest PC 0x0c0aba52 */
if(!s->budget--) { s->failed_pc=0x0c0aba52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba8e; }
goto P_0c0aba54;
P_0c0aba54: /* original e102, guest PC 0x0c0aba54 */
if(!s->budget--) { s->failed_pc=0x0c0aba54u; return 0; }
r[1]=0x00000002u;
goto P_0c0aba56;
P_0c0aba56: /* original 65e3, guest PC 0x0c0aba56 */
if(!s->budget--) { s->failed_pc=0x0c0aba56u; return 0; }
r[5]=r[14];
goto P_0c0aba58;
P_0c0aba58: /* original 6313, guest PC 0x0c0aba58 */
if(!s->budget--) { s->failed_pc=0x0c0aba58u; return 0; }
r[3]=r[1];
goto P_0c0aba5a;
P_0c0aba5a: /* original e062, guest PC 0x0c0aba5a */
if(!s->budget--) { s->failed_pc=0x0c0aba5au; return 0; }
r[0]=0x00000062u;
goto P_0c0aba5c;
P_0c0aba5c: /* original 1d12, guest PC 0x0c0aba5c */
if(!s->budget--) { s->failed_pc=0x0c0aba5cu; return 0; }
write(ram,r[13]+8,r[1],4);
goto P_0c0aba5e;
P_0c0aba5e: /* original 0e34, guest PC 0x0c0aba5e */
if(!s->budget--) { s->failed_pc=0x0c0aba5eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0aba60;
P_0c0aba60: /* original 9024, guest PC 0x0c0aba60 */
if(!s->budget--) { s->failed_pc=0x0c0aba60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaacu,2);
goto P_0c0aba62;
P_0c0aba62: /* original 02ed, guest PC 0x0c0aba62 */
if(!s->budget--) { s->failed_pc=0x0c0aba62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aba64;
P_0c0aba64: /* original e03e, guest PC 0x0c0aba64 */
if(!s->budget--) { s->failed_pc=0x0c0aba64u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aba66;
P_0c0aba66: /* original 0e25, guest PC 0x0c0aba66 */
if(!s->budget--) { s->failed_pc=0x0c0aba66u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aba68;
P_0c0aba68: /* original e048, guest PC 0x0c0aba68 */
if(!s->budget--) { s->failed_pc=0x0c0aba68u; return 0; }
r[0]=0x00000048u;
goto P_0c0aba6a;
P_0c0aba6a: /* original d316, guest PC 0x0c0aba6a */
if(!s->budget--) { s->failed_pc=0x0c0aba6au; return 0; }
r[3]=read(ram,0x0c0abac4u,4);
goto P_0c0aba6c;
P_0c0aba6c: /* original 62d2, guest PC 0x0c0aba6c */
if(!s->budget--) { s->failed_pc=0x0c0aba6cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aba6e;
P_0c0aba6e: /* original 04ee, guest PC 0x0c0aba6e */
if(!s->budget--) { s->failed_pc=0x0c0aba6eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aba70;
P_0c0aba70: /* original 223b, guest PC 0x0c0aba70 */
if(!s->budget--) { s->failed_pc=0x0c0aba70u; return 0; }
r[2]|=r[3];
goto P_0c0aba72;
P_0c0aba72: /* original 2d22, guest PC 0x0c0aba72 */
if(!s->budget--) { s->failed_pc=0x0c0aba72u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0aba74;
P_0c0aba74: /* original 911b, guest PC 0x0c0aba74 */
if(!s->budget--) { s->failed_pc=0x0c0aba74u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaaeu,2);
goto P_0c0aba76;
P_0c0aba76: /* original 63d2, guest PC 0x0c0aba76 */
if(!s->budget--) { s->failed_pc=0x0c0aba76u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0aba78;
P_0c0aba78: /* original d213, guest PC 0x0c0aba78 */
if(!s->budget--) { s->failed_pc=0x0c0aba78u; return 0; }
r[2]=read(ram,0x0c0abac8u,4);
goto P_0c0aba7a;
P_0c0aba7a: /* original 2419, guest PC 0x0c0aba7a */
if(!s->budget--) { s->failed_pc=0x0c0aba7au; return 0; }
r[4]&=r[1];
goto P_0c0aba7c;
P_0c0aba7c: /* original 2e32, guest PC 0x0c0aba7c */
if(!s->budget--) { s->failed_pc=0x0c0aba7cu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0aba7e;
P_0c0aba7e: /* original 242b, guest PC 0x0c0aba7e */
if(!s->budget--) { s->failed_pc=0x0c0aba7eu; return 0; }
r[4]|=r[2];
goto P_0c0aba80;
P_0c0aba80: /* original 0e46, guest PC 0x0c0aba80 */
if(!s->budget--) { s->failed_pc=0x0c0aba80u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0aba82;
P_0c0aba82: /* original d312, guest PC 0x0c0aba82 */
if(!s->budget--) { s->failed_pc=0x0c0aba82u; return 0; }
r[3]=read(ram,0x0c0abaccu,4);
goto P_0c0aba84;
P_0c0aba84: /* original 430b, guest PC 0x0c0aba84 */
if(!s->budget--) { s->failed_pc=0x0c0aba84u; return 0; }
target=r[3];
r[16]=0x0c0aba88u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aba88u) { target=s->pc; goto dispatch; }
goto P_0c0aba88;
P_0c0aba86: /* original e400, guest PC 0x0c0aba86 */
if(!s->budget--) { s->failed_pc=0x0c0aba86u; return 0; }
r[4]=0x00000000u;
goto P_0c0aba88;
P_0c0aba88: /* original 65d3, guest PC 0x0c0aba88 */
if(!s->budget--) { s->failed_pc=0x0c0aba88u; return 0; }
r[5]=r[13];
goto P_0c0aba8a;
P_0c0aba8a: /* original b021, guest PC 0x0c0aba8a */
if(!s->budget--) { s->failed_pc=0x0c0aba8au; return 0; }
target=0x0c0abad0u; r[16]=0x0c0aba8eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aba8eu) { target=s->pc; goto dispatch; }
goto P_0c0aba8e;
P_0c0aba8c: /* original 64e3, guest PC 0x0c0aba8c */
if(!s->budget--) { s->failed_pc=0x0c0aba8cu; return 0; }
r[4]=r[14];
goto P_0c0aba8e;
P_0c0aba8e: /* original 7f08, guest PC 0x0c0aba8e */
if(!s->budget--) { s->failed_pc=0x0c0aba8eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0aba90;
P_0c0aba90: /* original 4f26, guest PC 0x0c0aba90 */
if(!s->budget--) { s->failed_pc=0x0c0aba90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aba92;
P_0c0aba92: /* original 6df6, guest PC 0x0c0aba92 */
if(!s->budget--) { s->failed_pc=0x0c0aba92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aba94;
P_0c0aba94: /* original 000b, guest PC 0x0c0aba94 */
if(!s->budget--) { s->failed_pc=0x0c0aba94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aba96: /* original 6ef6, guest PC 0x0c0aba96 */
if(!s->budget--) { s->failed_pc=0x0c0aba96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aba98u,s,ram);
P_0c0abad0: /* original 2fe6, guest PC 0x0c0abad0 */
if(!s->budget--) { s->failed_pc=0x0c0abad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abad2;
P_0c0abad2: /* original 6e43, guest PC 0x0c0abad2 */
if(!s->budget--) { s->failed_pc=0x0c0abad2u; return 0; }
r[14]=r[4];
goto P_0c0abad4;
P_0c0abad4: /* original 2fd6, guest PC 0x0c0abad4 */
if(!s->budget--) { s->failed_pc=0x0c0abad4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abad6;
P_0c0abad6: /* original 6d53, guest PC 0x0c0abad6 */
if(!s->budget--) { s->failed_pc=0x0c0abad6u; return 0; }
r[13]=r[5];
goto P_0c0abad8;
P_0c0abad8: /* original 4f22, guest PC 0x0c0abad8 */
if(!s->budget--) { s->failed_pc=0x0c0abad8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abada;
P_0c0abada: /* original d344, guest PC 0x0c0abada */
if(!s->budget--) { s->failed_pc=0x0c0abadau; return 0; }
r[3]=read(ram,0x0c0abbecu,4);
goto P_0c0abadc;
P_0c0abadc: /* original 7ff8, guest PC 0x0c0abadc */
if(!s->budget--) { s->failed_pc=0x0c0abadcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0abade;
P_0c0abade: /* original 2f32, guest PC 0x0c0abade */
if(!s->budget--) { s->failed_pc=0x0c0abadeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0abae0;
P_0c0abae0: /* original b104, guest PC 0x0c0abae0 */
if(!s->budget--) { s->failed_pc=0x0c0abae0u; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abae4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abae4u) { target=s->pc; goto dispatch; }
goto P_0c0abae4;
P_0c0abae2: /* original 64e3, guest PC 0x0c0abae2 */
if(!s->budget--) { s->failed_pc=0x0c0abae2u; return 0; }
r[4]=r[14];
goto P_0c0abae4;
P_0c0abae4: /* original b122, guest PC 0x0c0abae4 */
if(!s->budget--) { s->failed_pc=0x0c0abae4u; return 0; }
target=0x0c0abd2cu; r[16]=0x0c0abae8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abae8u) { target=s->pc; goto dispatch; }
goto P_0c0abae8;
P_0c0abae6: /* original 64e3, guest PC 0x0c0abae6 */
if(!s->budget--) { s->failed_pc=0x0c0abae6u; return 0; }
r[4]=r[14];
goto P_0c0abae8;
P_0c0abae8: /* original 1f01, guest PC 0x0c0abae8 */
if(!s->budget--) { s->failed_pc=0x0c0abae8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0abaea;
P_0c0abaea: /* original b16b, guest PC 0x0c0abaea */
if(!s->budget--) { s->failed_pc=0x0c0abaeau; return 0; }
target=0x0c0abdc4u; r[16]=0x0c0abaeeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abaeeu) { target=s->pc; goto dispatch; }
goto P_0c0abaee;
P_0c0abaec: /* original 64e3, guest PC 0x0c0abaec */
if(!s->budget--) { s->failed_pc=0x0c0abaecu; return 0; }
r[4]=r[14];
goto P_0c0abaee;
P_0c0abaee: /* original 50f1, guest PC 0x0c0abaee */
if(!s->budget--) { s->failed_pc=0x0c0abaeeu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0abaf0;
P_0c0abaf0: /* original 8801, guest PC 0x0c0abaf0 */
if(!s->budget--) { s->failed_pc=0x0c0abaf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abaf2;
P_0c0abaf2: /* original 8b06, guest PC 0x0c0abaf2 */
if(!s->budget--) { s->failed_pc=0x0c0abaf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb02; }
goto P_0c0abaf4;
P_0c0abaf4: /* original 60f2, guest PC 0x0c0abaf4 */
if(!s->budget--) { s->failed_pc=0x0c0abaf4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0abaf6;
P_0c0abaf6: /* original e11c, guest PC 0x0c0abaf6 */
if(!s->budget--) { s->failed_pc=0x0c0abaf6u; return 0; }
r[1]=0x0000001cu;
goto P_0c0abaf8;
P_0c0abaf8: /* original 001c, guest PC 0x0c0abaf8 */
if(!s->budget--) { s->failed_pc=0x0c0abaf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0abafa;
P_0c0abafa: /* original 600c, guest PC 0x0c0abafa */
if(!s->budget--) { s->failed_pc=0x0c0abafau; return 0; }
r[0]=r[0]&255u;
goto P_0c0abafc;
P_0c0abafc: /* original c90f, guest PC 0x0c0abafc */
if(!s->budget--) { s->failed_pc=0x0c0abafcu; return 0; }
r[0]&=15u;
goto P_0c0abafe;
P_0c0abafe: /* original 8806, guest PC 0x0c0abafe */
if(!s->budget--) { s->failed_pc=0x0c0abafeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0abb00;
P_0c0abb00: /* original 8b0b, guest PC 0x0c0abb00 */
if(!s->budget--) { s->failed_pc=0x0c0abb00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb1a; }
goto P_0c0abb02;
P_0c0abb02: /* original 7f08, guest PC 0x0c0abb02 */
if(!s->budget--) { s->failed_pc=0x0c0abb02u; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb04;
P_0c0abb04: /* original 65d3, guest PC 0x0c0abb04 */
if(!s->budget--) { s->failed_pc=0x0c0abb04u; return 0; }
r[5]=r[13];
goto P_0c0abb06;
P_0c0abb06: /* original 4f26, guest PC 0x0c0abb06 */
if(!s->budget--) { s->failed_pc=0x0c0abb06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb08;
P_0c0abb08: /* original e203, guest PC 0x0c0abb08 */
if(!s->budget--) { s->failed_pc=0x0c0abb08u; return 0; }
r[2]=0x00000003u;
goto P_0c0abb0a;
P_0c0abb0a: /* original 64e3, guest PC 0x0c0abb0a */
if(!s->budget--) { s->failed_pc=0x0c0abb0au; return 0; }
r[4]=r[14];
goto P_0c0abb0c;
P_0c0abb0c: /* original 1d22, guest PC 0x0c0abb0c */
if(!s->budget--) { s->failed_pc=0x0c0abb0cu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb0e;
P_0c0abb0e: /* original 6323, guest PC 0x0c0abb0e */
if(!s->budget--) { s->failed_pc=0x0c0abb0eu; return 0; }
r[3]=r[2];
goto P_0c0abb10;
P_0c0abb10: /* original e062, guest PC 0x0c0abb10 */
if(!s->budget--) { s->failed_pc=0x0c0abb10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb12;
P_0c0abb12: /* original 0e34, guest PC 0x0c0abb12 */
if(!s->budget--) { s->failed_pc=0x0c0abb12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb14;
P_0c0abb14: /* original 6df6, guest PC 0x0c0abb14 */
if(!s->budget--) { s->failed_pc=0x0c0abb14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb16;
P_0c0abb16: /* original a005, guest PC 0x0c0abb16 */
if(!s->budget--) { s->failed_pc=0x0c0abb16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb18: /* original 6ef6, guest PC 0x0c0abb18 */
if(!s->budget--) { s->failed_pc=0x0c0abb18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb1a;
P_0c0abb1a: /* original 7f08, guest PC 0x0c0abb1a */
if(!s->budget--) { s->failed_pc=0x0c0abb1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb1c;
P_0c0abb1c: /* original 4f26, guest PC 0x0c0abb1c */
if(!s->budget--) { s->failed_pc=0x0c0abb1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb1e;
P_0c0abb1e: /* original 6df6, guest PC 0x0c0abb1e */
if(!s->budget--) { s->failed_pc=0x0c0abb1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb20;
P_0c0abb20: /* original 000b, guest PC 0x0c0abb20 */
if(!s->budget--) { s->failed_pc=0x0c0abb20u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb22: /* original 6ef6, guest PC 0x0c0abb22 */
if(!s->budget--) { s->failed_pc=0x0c0abb22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb24: /* original 2fe6, guest PC 0x0c0abb24 */
if(!s->budget--) { s->failed_pc=0x0c0abb24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb26;
P_0c0abb26: /* original 6e43, guest PC 0x0c0abb26 */
if(!s->budget--) { s->failed_pc=0x0c0abb26u; return 0; }
r[14]=r[4];
goto P_0c0abb28;
P_0c0abb28: /* original 2fd6, guest PC 0x0c0abb28 */
if(!s->budget--) { s->failed_pc=0x0c0abb28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c0abb2au,s,ram);
P_0c0abbba: /* original e205, guest PC 0x0c0abbba */
if(!s->budget--) { s->failed_pc=0x0c0abbbau; return 0; }
r[2]=0x00000005u;
goto P_0c0abbbc;
P_0c0abbbc: /* original e062, guest PC 0x0c0abbbc */
if(!s->budget--) { s->failed_pc=0x0c0abbbcu; return 0; }
r[0]=0x00000062u;
goto P_0c0abbbe;
P_0c0abbbe: /* original 6323, guest PC 0x0c0abbbe */
if(!s->budget--) { s->failed_pc=0x0c0abbbeu; return 0; }
r[3]=r[2];
goto P_0c0abbc0;
P_0c0abbc0: /* original 1522, guest PC 0x0c0abbc0 */
if(!s->budget--) { s->failed_pc=0x0c0abbc0u; return 0; }
write(ram,r[5]+8,r[2],4);
goto P_0c0abbc2;
P_0c0abbc2: /* original 0434, guest PC 0x0c0abbc2 */
if(!s->budget--) { s->failed_pc=0x0c0abbc2u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0abbc4;
P_0c0abbc4: /* original 900f, guest PC 0x0c0abbc4 */
if(!s->budget--) { s->failed_pc=0x0c0abbc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe6u,2);
goto P_0c0abbc6;
P_0c0abbc6: /* original f346, guest PC 0x0c0abbc6 */
if(!s->budget--) { s->failed_pc=0x0c0abbc6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abbc8;
P_0c0abbc8: /* original e024, guest PC 0x0c0abbc8 */
if(!s->budget--) { s->failed_pc=0x0c0abbc8u; return 0; }
r[0]=0x00000024u;
goto P_0c0abbca;
P_0c0abbca: /* original f437, guest PC 0x0c0abbca */
if(!s->budget--) { s->failed_pc=0x0c0abbcau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abbcc;
P_0c0abbcc: /* original 900c, guest PC 0x0c0abbcc */
if(!s->budget--) { s->failed_pc=0x0c0abbccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe8u,2);
goto P_0c0abbce;
P_0c0abbce: /* original f346, guest PC 0x0c0abbce */
if(!s->budget--) { s->failed_pc=0x0c0abbceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abbd0;
P_0c0abbd0: /* original e02c, guest PC 0x0c0abbd0 */
if(!s->budget--) { s->failed_pc=0x0c0abbd0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abbd2;
P_0c0abbd2: /* original f437, guest PC 0x0c0abbd2 */
if(!s->budget--) { s->failed_pc=0x0c0abbd2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abbd4;
P_0c0abbd4: /* original 9006, guest PC 0x0c0abbd4 */
if(!s->budget--) { s->failed_pc=0x0c0abbd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe4u,2);
goto P_0c0abbd6;
P_0c0abbd6: /* original f48d, guest PC 0x0c0abbd6 */
if(!s->budget--) { s->failed_pc=0x0c0abbd6u; return 0; }
fr[4]=0;
goto P_0c0abbd8;
P_0c0abbd8: /* original f447, guest PC 0x0c0abbd8 */
if(!s->budget--) { s->failed_pc=0x0c0abbd8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abbda;
P_0c0abbda: /* original 7008, guest PC 0x0c0abbda */
if(!s->budget--) { s->failed_pc=0x0c0abbdau; return 0; }
r[0]+=0x00000008u;
goto P_0c0abbdc;
P_0c0abbdc: /* original a00e, guest PC 0x0c0abbdc */
if(!s->budget--) { s->failed_pc=0x0c0abbdcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
return vf3_matrix_family(0x0c0abbfcu,s,ram);
P_0c0abbde: /* original f447, guest PC 0x0c0abbde */
if(!s->budget--) { s->failed_pc=0x0c0abbdeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
return vf3_matrix_family(0x0c0abbe0u,s,ram);
P_0c0abdc4: /* original 901b, guest PC 0x0c0abdc4 */
if(!s->budget--) { s->failed_pc=0x0c0abdc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfeu,2);
goto P_0c0abdc6;
P_0c0abdc6: /* original d510, guest PC 0x0c0abdc6 */
if(!s->budget--) { s->failed_pc=0x0c0abdc6u; return 0; }
r[5]=read(ram,0x0c0abe08u,4);
goto P_0c0abdc8;
P_0c0abdc8: /* original f546, guest PC 0x0c0abdc8 */
if(!s->budget--) { s->failed_pc=0x0c0abdc8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abdca;
P_0c0abdca: /* original 70fc, guest PC 0x0c0abdca */
if(!s->budget--) { s->failed_pc=0x0c0abdcau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0abdcc;
P_0c0abdcc: /* original f446, guest PC 0x0c0abdcc */
if(!s->budget--) { s->failed_pc=0x0c0abdccu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abdce;
P_0c0abdce: /* original e01c, guest PC 0x0c0abdce */
if(!s->budget--) { s->failed_pc=0x0c0abdceu; return 0; }
r[0]=0x0000001cu;
goto P_0c0abdd0;
P_0c0abdd0: /* original 005c, guest PC 0x0c0abdd0 */
if(!s->budget--) { s->failed_pc=0x0c0abdd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0abdd2;
P_0c0abdd2: /* original e50f, guest PC 0x0c0abdd2 */
if(!s->budget--) { s->failed_pc=0x0c0abdd2u; return 0; }
r[5]=0x0000000fu;
goto P_0c0abdd4;
P_0c0abdd4: /* original 600c, guest PC 0x0c0abdd4 */
if(!s->budget--) { s->failed_pc=0x0c0abdd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abdd6;
P_0c0abdd6: /* original 2509, guest PC 0x0c0abdd6 */
if(!s->budget--) { s->failed_pc=0x0c0abdd6u; return 0; }
r[5]&=r[0];
goto P_0c0abdd8;
P_0c0abdd8: /* original c70e, guest PC 0x0c0abdd8 */
if(!s->budget--) { s->failed_pc=0x0c0abdd8u; return 0; }
r[0]=0x0c0abe14u;
goto P_0c0abdda;
P_0c0abdda: /* original f608, guest PC 0x0c0abdda */
if(!s->budget--) { s->failed_pc=0x0c0abddau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0abddc;
P_0c0abddc: /* original 6053, guest PC 0x0c0abddc */
if(!s->budget--) { s->failed_pc=0x0c0abddcu; return 0; }
r[0]=r[5];
goto P_0c0abdde;
P_0c0abdde: /* original 8807, guest PC 0x0c0abdde */
if(!s->budget--) { s->failed_pc=0x0c0abddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0abde0;
P_0c0abde0: /* original 891e, guest PC 0x0c0abde0 */
if(!s->budget--) { s->failed_pc=0x0c0abde0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe20; }
goto P_0c0abde2;
P_0c0abde2: /* original 6053, guest PC 0x0c0abde2 */
if(!s->budget--) { s->failed_pc=0x0c0abde2u; return 0; }
r[0]=r[5];
goto P_0c0abde4;
P_0c0abde4: /* original 8805, guest PC 0x0c0abde4 */
if(!s->budget--) { s->failed_pc=0x0c0abde4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0abde6;
P_0c0abde6: /* original 8b31, guest PC 0x0c0abde6 */
if(!s->budget--) { s->failed_pc=0x0c0abde6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abe4c; }
goto P_0c0abde8;
P_0c0abde8: /* original c70b, guest PC 0x0c0abde8 */
if(!s->budget--) { s->failed_pc=0x0c0abde8u; return 0; }
r[0]=0x0c0abe18u;
goto P_0c0abdea;
P_0c0abdea: /* original f308, guest PC 0x0c0abdea */
if(!s->budget--) { s->failed_pc=0x0c0abdeau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdec;
P_0c0abdec: /* original f435, guest PC 0x0c0abdec */
if(!s->budget--) { s->failed_pc=0x0c0abdecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abdee;
P_0c0abdee: /* original 892d, guest PC 0x0c0abdee */
if(!s->budget--) { s->failed_pc=0x0c0abdeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf0;
P_0c0abdf0: /* original c70a, guest PC 0x0c0abdf0 */
if(!s->budget--) { s->failed_pc=0x0c0abdf0u; return 0; }
r[0]=0x0c0abe1cu;
goto P_0c0abdf2;
P_0c0abdf2: /* original f308, guest PC 0x0c0abdf2 */
if(!s->budget--) { s->failed_pc=0x0c0abdf2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abdf4;
P_0c0abdf4: /* original f345, guest PC 0x0c0abdf4 */
if(!s->budget--) { s->failed_pc=0x0c0abdf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abdf6;
P_0c0abdf6: /* original 8929, guest PC 0x0c0abdf6 */
if(!s->budget--) { s->failed_pc=0x0c0abdf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abdf8;
P_0c0abdf8: /* original a026, guest PC 0x0c0abdf8 */
if(!s->budget--) { s->failed_pc=0x0c0abdf8u; return 0; }
goto P_0c0abe48;
P_0c0abdfa: /* original 0009, guest PC 0x0c0abdfa */
if(!s->budget--) { s->failed_pc=0x0c0abdfau; return 0; }
return vf3_matrix_family(0x0c0abdfcu,s,ram);
P_0c0abe20: /* original c740, guest PC 0x0c0abe20 */
if(!s->budget--) { s->failed_pc=0x0c0abe20u; return 0; }
r[0]=0x0c0abf24u;
goto P_0c0abe22;
P_0c0abe22: /* original f308, guest PC 0x0c0abe22 */
if(!s->budget--) { s->failed_pc=0x0c0abe22u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe24;
P_0c0abe24: /* original f355, guest PC 0x0c0abe24 */
if(!s->budget--) { s->failed_pc=0x0c0abe24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0abe26;
P_0c0abe26: /* original 8911, guest PC 0x0c0abe26 */
if(!s->budget--) { s->failed_pc=0x0c0abe26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe4c; }
goto P_0c0abe28;
P_0c0abe28: /* original c73f, guest PC 0x0c0abe28 */
if(!s->budget--) { s->failed_pc=0x0c0abe28u; return 0; }
r[0]=0x0c0abf28u;
goto P_0c0abe2a;
P_0c0abe2a: /* original f308, guest PC 0x0c0abe2a */
if(!s->budget--) { s->failed_pc=0x0c0abe2au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe2c;
P_0c0abe2c: /* original f435, guest PC 0x0c0abe2c */
if(!s->budget--) { s->failed_pc=0x0c0abe2cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe2e;
P_0c0abe2e: /* original 8906, guest PC 0x0c0abe2e */
if(!s->budget--) { s->failed_pc=0x0c0abe2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe3e; }
goto P_0c0abe30;
P_0c0abe30: /* original c73e, guest PC 0x0c0abe30 */
if(!s->budget--) { s->failed_pc=0x0c0abe30u; return 0; }
r[0]=0x0c0abf2cu;
goto P_0c0abe32;
P_0c0abe32: /* original f308, guest PC 0x0c0abe32 */
if(!s->budget--) { s->failed_pc=0x0c0abe32u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe34;
P_0c0abe34: /* original f345, guest PC 0x0c0abe34 */
if(!s->budget--) { s->failed_pc=0x0c0abe34u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0abe36;
P_0c0abe36: /* original 8907, guest PC 0x0c0abe36 */
if(!s->budget--) { s->failed_pc=0x0c0abe36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe38;
P_0c0abe38: /* original f38d, guest PC 0x0c0abe38 */
if(!s->budget--) { s->failed_pc=0x0c0abe38u; return 0; }
fr[3]=0;
goto P_0c0abe3a;
P_0c0abe3a: /* original f435, guest PC 0x0c0abe3a */
if(!s->budget--) { s->failed_pc=0x0c0abe3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0abe3c;
P_0c0abe3c: /* original 8904, guest PC 0x0c0abe3c */
if(!s->budget--) { s->failed_pc=0x0c0abe3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe48; }
goto P_0c0abe3e;
P_0c0abe3e: /* original c73c, guest PC 0x0c0abe3e */
if(!s->budget--) { s->failed_pc=0x0c0abe3eu; return 0; }
r[0]=0x0c0abf30u;
goto P_0c0abe40;
P_0c0abe40: /* original f308, guest PC 0x0c0abe40 */
if(!s->budget--) { s->failed_pc=0x0c0abe40u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe42;
P_0c0abe42: /* original e024, guest PC 0x0c0abe42 */
if(!s->budget--) { s->failed_pc=0x0c0abe42u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe44;
P_0c0abe44: /* original 000b, guest PC 0x0c0abe44 */
if(!s->budget--) { s->failed_pc=0x0c0abe44u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0abe46: /* original f437, guest PC 0x0c0abe46 */
if(!s->budget--) { s->failed_pc=0x0c0abe46u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abe48;
P_0c0abe48: /* original e024, guest PC 0x0c0abe48 */
if(!s->budget--) { s->failed_pc=0x0c0abe48u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe4a;
P_0c0abe4a: /* original f467, guest PC 0x0c0abe4a */
if(!s->budget--) { s->failed_pc=0x0c0abe4au; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0abe4c;
P_0c0abe4c: /* original 000b, guest PC 0x0c0abe4c */
if(!s->budget--) { s->failed_pc=0x0c0abe4cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abe4e: /* original 0009, guest PC 0x0c0abe4e */
if(!s->budget--) { s->failed_pc=0x0c0abe4eu; return 0; }
goto P_0c0abe50;
P_0c0abe50: /* original d538, guest PC 0x0c0abe50 */
if(!s->budget--) { s->failed_pc=0x0c0abe50u; return 0; }
r[5]=read(ram,0x0c0abf34u,4);
goto P_0c0abe52;
P_0c0abe52: /* original e01c, guest PC 0x0c0abe52 */
if(!s->budget--) { s->failed_pc=0x0c0abe52u; return 0; }
r[0]=0x0000001cu;
goto P_0c0abe54;
P_0c0abe54: /* original 005c, guest PC 0x0c0abe54 */
if(!s->budget--) { s->failed_pc=0x0c0abe54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0abe56;
P_0c0abe56: /* original 600c, guest PC 0x0c0abe56 */
if(!s->budget--) { s->failed_pc=0x0c0abe56u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abe58;
P_0c0abe58: /* original c90f, guest PC 0x0c0abe58 */
if(!s->budget--) { s->failed_pc=0x0c0abe58u; return 0; }
r[0]&=15u;
goto P_0c0abe5a;
P_0c0abe5a: /* original 8807, guest PC 0x0c0abe5a */
if(!s->budget--) { s->failed_pc=0x0c0abe5au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0abe5c;
P_0c0abe5c: /* original 8b10, guest PC 0x0c0abe5c */
if(!s->budget--) { s->failed_pc=0x0c0abe5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abe80; }
goto P_0c0abe5e;
P_0c0abe5e: /* original 905e, guest PC 0x0c0abe5e */
if(!s->budget--) { s->failed_pc=0x0c0abe5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abf1eu,2);
goto P_0c0abe60;
P_0c0abe60: /* original 024e, guest PC 0x0c0abe60 */
if(!s->budget--) { s->failed_pc=0x0c0abe60u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0abe62;
P_0c0abe62: /* original 2228, guest PC 0x0c0abe62 */
if(!s->budget--) { s->failed_pc=0x0c0abe62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0abe64;
P_0c0abe64: /* original 890c, guest PC 0x0c0abe64 */
if(!s->budget--) { s->failed_pc=0x0c0abe64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe80; }
goto P_0c0abe66;
P_0c0abe66: /* original c734, guest PC 0x0c0abe66 */
if(!s->budget--) { s->failed_pc=0x0c0abe66u; return 0; }
r[0]=0x0c0abf38u;
goto P_0c0abe68;
P_0c0abe68: /* original f308, guest PC 0x0c0abe68 */
if(!s->budget--) { s->failed_pc=0x0c0abe68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abe6a;
P_0c0abe6a: /* original 9059, guest PC 0x0c0abe6a */
if(!s->budget--) { s->failed_pc=0x0c0abe6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abf20u,2);
goto P_0c0abe6c;
P_0c0abe6c: /* original f246, guest PC 0x0c0abe6c */
if(!s->budget--) { s->failed_pc=0x0c0abe6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0abe6e;
P_0c0abe6e: /* original f235, guest PC 0x0c0abe6e */
if(!s->budget--) { s->failed_pc=0x0c0abe6eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0abe70;
P_0c0abe70: /* original 8906, guest PC 0x0c0abe70 */
if(!s->budget--) { s->failed_pc=0x0c0abe70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abe80; }
goto P_0c0abe72;
P_0c0abe72: /* original e024, guest PC 0x0c0abe72 */
if(!s->budget--) { s->failed_pc=0x0c0abe72u; return 0; }
r[0]=0x00000024u;
goto P_0c0abe74;
P_0c0abe74: /* original f546, guest PC 0x0c0abe74 */
if(!s->budget--) { s->failed_pc=0x0c0abe74u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abe76;
P_0c0abe76: /* original e02c, guest PC 0x0c0abe76 */
if(!s->budget--) { s->failed_pc=0x0c0abe76u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abe78;
P_0c0abe78: /* original f446, guest PC 0x0c0abe78 */
if(!s->budget--) { s->failed_pc=0x0c0abe78u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abe7a;
P_0c0abe7a: /* original f457, guest PC 0x0c0abe7a */
if(!s->budget--) { s->failed_pc=0x0c0abe7au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0abe7c;
P_0c0abe7c: /* original e024, guest PC 0x0c0abe7c */
if(!s->budget--) { s->failed_pc=0x0c0abe7cu; return 0; }
r[0]=0x00000024u;
goto P_0c0abe7e;
P_0c0abe7e: /* original f447, guest PC 0x0c0abe7e */
if(!s->budget--) { s->failed_pc=0x0c0abe7eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abe80;
P_0c0abe80: /* original 000b, guest PC 0x0c0abe80 */
if(!s->budget--) { s->failed_pc=0x0c0abe80u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abe82: /* original 0009, guest PC 0x0c0abe82 */
if(!s->budget--) { s->failed_pc=0x0c0abe82u; return 0; }
return vf3_matrix_family(0x0c0abe84u,s,ram);
P_0c0c1ac2: /* original 4f22, guest PC 0x0c0c1ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ac2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1ac4;
P_0c0c1ac4: /* original d63b, guest PC 0x0c0c1ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ac4u; return 0; }
r[6]=read(ram,0x0c0c1bb4u,4);
goto P_0c0c1ac6;
P_0c0c1ac6: /* original fc3c, guest PC 0x0c0c1ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ac6u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c0c1ac8;
P_0c0c1ac8: /* original f32d, guest PC 0x0c0c1ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ac8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1aca;
P_0c0c1aca: /* original fc22, guest PC 0x0c0c1aca */
if(!s->budget--) { s->failed_pc=0x0c0c1acau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'*');
goto P_0c0c1acc;
P_0c0c1acc: /* original f218, guest PC 0x0c0c1acc */
if(!s->budget--) { s->failed_pc=0x0c0c1accu; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0c1ace;
P_0c0c1ace: /* original 996e, guest PC 0x0c0c1ace */
if(!s->budget--) { s->failed_pc=0x0c0c1aceu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1baeu,2);
goto P_0c0c1ad0;
P_0c0c1ad0: /* original 7fc8, guest PC 0x0c0c1ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ad0u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0c1ad2;
P_0c0c1ad2: /* original 5543, guest PC 0x0c0c1ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ad2u; return 0; }
r[5]=read(ram,r[4]+12,4);
goto P_0c0c1ad4;
P_0c0c1ad4: /* original 396c, guest PC 0x0c0c1ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ad4u; return 0; }
r[9]+=r[6];
goto P_0c0c1ad6;
P_0c0c1ad6: /* original f322, guest PC 0x0c0c1ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ad6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1ad8;
P_0c0c1ad8: /* original ff3a, guest PC 0x0c0c1ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ad8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1ada;
P_0c0c1ada: /* original eb00, guest PC 0x0c0c1ada */
if(!s->budget--) { s->failed_pc=0x0c0c1adau; return 0; }
r[11]=0x00000000u;
goto P_0c0c1adc;
P_0c0c1adc: /* original 9a68, guest PC 0x0c0c1adc */
if(!s->budget--) { s->failed_pc=0x0c0c1adcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1bb0u,2);
goto P_0c0c1ade;
P_0c0c1ade: /* original e801, guest PC 0x0c0c1ade */
if(!s->budget--) { s->failed_pc=0x0c0c1adeu; return 0; }
r[8]=0x00000001u;
goto P_0c0c1ae0;
P_0c0c1ae0: /* original dc37, guest PC 0x0c0c1ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ae0u; return 0; }
r[12]=read(ram,0x0c0c1bc0u,4);
goto P_0c0c1ae2;
P_0c0c1ae2: /* original 6e53, guest PC 0x0c0c1ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ae2u; return 0; }
r[14]=r[5];
goto P_0c0c1ae4;
P_0c0c1ae4: /* original dd37, guest PC 0x0c0c1ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ae4u; return 0; }
r[13]=read(ram,0x0c0c1bc4u,4);
goto P_0c0c1ae6;
P_0c0c1ae6: /* original 63e1, guest PC 0x0c0c1ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ae6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1ae8;
P_0c0c1ae8: /* original 633d, guest PC 0x0c0c1ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ae8u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1aea;
P_0c0c1aea: /* original 2388, guest PC 0x0c0c1aea */
if(!s->budget--) { s->failed_pc=0x0c0c1aeau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c1aec;
P_0c0c1aec: /* original 894c, guest PC 0x0c0c1aec */
if(!s->budget--) { s->failed_pc=0x0c0c1aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1b88; }
goto P_0c0c1aee;
P_0c0c1aee: /* original 60e1, guest PC 0x0c0c1aee */
if(!s->budget--) { s->failed_pc=0x0c0c1aeeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c1af0;
P_0c0c1af0: /* original 600d, guest PC 0x0c0c1af0 */
if(!s->budget--) { s->failed_pc=0x0c0c1af0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1af2;
P_0c0c1af2: /* original c808, guest PC 0x0c0c1af2 */
if(!s->budget--) { s->failed_pc=0x0c0c1af2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0c1af4;
P_0c0c1af4: /* original 893a, guest PC 0x0c0c1af4 */
if(!s->budget--) { s->failed_pc=0x0c0c1af4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1b6c; }
goto P_0c0c1af6;
P_0c0c1af6: /* original 65e3, guest PC 0x0c0c1af6 */
if(!s->budget--) { s->failed_pc=0x0c0c1af6u; return 0; }
r[5]=r[14];
goto P_0c0c1af8;
P_0c0c1af8: /* original 64f3, guest PC 0x0c0c1af8 */
if(!s->budget--) { s->failed_pc=0x0c0c1af8u; return 0; }
r[4]=r[15];
goto P_0c0c1afa;
P_0c0c1afa: /* original 7510, guest PC 0x0c0c1afa */
if(!s->budget--) { s->failed_pc=0x0c0c1afau; return 0; }
r[5]+=0x00000010u;
goto P_0c0c1afc;
P_0c0c1afc: /* original e634, guest PC 0x0c0c1afc */
if(!s->budget--) { s->failed_pc=0x0c0c1afcu; return 0; }
r[6]=0x00000034u;
goto P_0c0c1afe;
P_0c0c1afe: /* original 4c0b, guest PC 0x0c0c1afe */
if(!s->budget--) { s->failed_pc=0x0c0c1afeu; return 0; }
target=r[12];
r[16]=0x0c0c1b02u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1b02u) { target=s->pc; goto dispatch; }
goto P_0c0c1b02;
P_0c0c1b00: /* original 7404, guest PC 0x0c0c1b00 */
if(!s->budget--) { s->failed_pc=0x0c0c1b00u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1b02;
P_0c0c1b02: /* original d331, guest PC 0x0c0c1b02 */
if(!s->budget--) { s->failed_pc=0x0c0c1b02u; return 0; }
r[3]=read(ram,0x0c0c1bc8u,4);
goto P_0c0c1b04;
P_0c0c1b04: /* original 430b, guest PC 0x0c0c1b04 */
if(!s->budget--) { s->failed_pc=0x0c0c1b04u; return 0; }
target=r[3];
r[16]=0x0c0c1b08u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1b08u) { target=s->pc; goto dispatch; }
goto P_0c0c1b08;
P_0c0c1b06: /* original 54f1, guest PC 0x0c0c1b06 */
if(!s->budget--) { s->failed_pc=0x0c0c1b06u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c1b08;
P_0c0c1b08: /* original 6403, guest PC 0x0c0c1b08 */
if(!s->budget--) { s->failed_pc=0x0c0c1b08u; return 0; }
r[4]=r[0];
goto P_0c0c1b0a;
P_0c0c1b0a: /* original e00c, guest PC 0x0c0c1b0a */
if(!s->budget--) { s->failed_pc=0x0c0c1b0au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1b0c;
P_0c0c1b0c: /* original fd46, guest PC 0x0c0c1b0c */
if(!s->budget--) { s->failed_pc=0x0c0c1b0cu; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c0c1b0e;
P_0c0c1b0e: /* original e01c, guest PC 0x0c0c1b0e */
if(!s->budget--) { s->failed_pc=0x0c0c1b0eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c1b10;
P_0c0c1b10: /* original fe46, guest PC 0x0c0c1b10 */
if(!s->budget--) { s->failed_pc=0x0c0c1b10u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0c1b12;
P_0c0c1b12: /* original f38d, guest PC 0x0c0c1b12 */
if(!s->budget--) { s->failed_pc=0x0c0c1b12u; return 0; }
fr[3]=0;
goto P_0c0c1b14;
P_0c0c1b14: /* original fd35, guest PC 0x0c0c1b14 */
if(!s->budget--) { s->failed_pc=0x0c0c1b14u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c0c1b16;
P_0c0c1b16: /* original fed3, guest PC 0x0c0c1b16 */
if(!s->budget--) { s->failed_pc=0x0c0c1b16u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'/');
goto P_0c0c1b18;
P_0c0c1b18: /* original 8f36, guest PC 0x0c0c1b18 */
if(!s->budget--) { s->failed_pc=0x0c0c1b18u; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0c1b88; }
goto P_0c0c1b1c;
P_0c0c1b1a: /* original ff8d, guest PC 0x0c0c1b1a */
if(!s->budget--) { s->failed_pc=0x0c0c1b1au; return 0; }
fr[15]=0;
goto P_0c0c1b1c;
P_0c0c1b1c: /* original f3fc, guest PC 0x0c0c1b1c */
if(!s->budget--) { s->failed_pc=0x0c0c1b1cu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c1b1e;
P_0c0c1b1e: /* original f3c0, guest PC 0x0c0c1b1e */
if(!s->budget--) { s->failed_pc=0x0c0c1b1eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'+');
goto P_0c0c1b20;
P_0c0c1b20: /* original e00c, guest PC 0x0c0c1b20 */
if(!s->budget--) { s->failed_pc=0x0c0c1b20u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1b22;
P_0c0c1b22: /* original ff37, guest PC 0x0c0c1b22 */
if(!s->budget--) { s->failed_pc=0x0c0c1b22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1b24;
P_0c0c1b24: /* original e020, guest PC 0x0c0c1b24 */
if(!s->budget--) { s->failed_pc=0x0c0c1b24u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1b26;
P_0c0c1b26: /* original f3fc, guest PC 0x0c0c1b26 */
if(!s->budget--) { s->failed_pc=0x0c0c1b26u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c1b28;
P_0c0c1b28: /* original f3e2, guest PC 0x0c0c1b28 */
if(!s->budget--) { s->failed_pc=0x0c0c1b28u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0c1b2a;
P_0c0c1b2a: /* original ff37, guest PC 0x0c0c1b2a */
if(!s->budget--) { s->failed_pc=0x0c0c1b2au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1b2c;
P_0c0c1b2c: /* original f3e0, guest PC 0x0c0c1b2c */
if(!s->budget--) { s->failed_pc=0x0c0c1b2cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c0c1b2e;
P_0c0c1b2e: /* original e028, guest PC 0x0c0c1b2e */
if(!s->budget--) { s->failed_pc=0x0c0c1b2eu; return 0; }
r[0]=0x00000028u;
goto P_0c0c1b30;
P_0c0c1b30: /* original ff37, guest PC 0x0c0c1b30 */
if(!s->budget--) { s->failed_pc=0x0c0c1b30u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1b32;
P_0c0c1b32: /* original c726, guest PC 0x0c0c1b32 */
if(!s->budget--) { s->failed_pc=0x0c0c1b32u; return 0; }
r[0]=0x0c0c1bccu;
goto P_0c0c1b34;
P_0c0c1b34: /* original f308, guest PC 0x0c0c1b34 */
if(!s->budget--) { s->failed_pc=0x0c0c1b34u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1b36;
P_0c0c1b36: /* original f2fc, guest PC 0x0c0c1b36 */
if(!s->budget--) { s->failed_pc=0x0c0c1b36u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0c1b38;
P_0c0c1b38: /* original f232, guest PC 0x0c0c1b38 */
if(!s->budget--) { s->failed_pc=0x0c0c1b38u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c1b3a;
P_0c0c1b3a: /* original f23d, guest PC 0x0c0c1b3a */
if(!s->budget--) { s->failed_pc=0x0c0c1b3au; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c0c1b3c;
P_0c0c1b3c: /* original 045a, guest PC 0x0c0c1b3c */
if(!s->budget--) { s->failed_pc=0x0c0c1b3cu; return 0; }
r[4]=r[53];
goto P_0c0c1b3e;
P_0c0c1b3e: /* original 34a3, guest PC 0x0c0c1b3e */
if(!s->budget--) { s->failed_pc=0x0c0c1b3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[10])!=0);
goto P_0c0c1b40;
P_0c0c1b40: /* original 8922, guest PC 0x0c0c1b40 */
if(!s->budget--) { s->failed_pc=0x0c0c1b40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1b88; }
goto P_0c0c1b42;
P_0c0c1b42: /* original e018, guest PC 0x0c0c1b42 */
if(!s->budget--) { s->failed_pc=0x0c0c1b42u; return 0; }
r[0]=0x00000018u;
goto P_0c0c1b44;
P_0c0c1b44: /* original ffe7, guest PC 0x0c0c1b44 */
if(!s->budget--) { s->failed_pc=0x0c0c1b44u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c1b46;
P_0c0c1b46: /* original 6043, guest PC 0x0c0c1b46 */
if(!s->budget--) { s->failed_pc=0x0c0c1b46u; return 0; }
r[0]=r[4];
goto P_0c0c1b48;
P_0c0c1b48: /* original 039c, guest PC 0x0c0c1b48 */
if(!s->budget--) { s->failed_pc=0x0c0c1b48u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c1b4a;
P_0c0c1b4a: /* original 64f3, guest PC 0x0c0c1b4a */
if(!s->budget--) { s->failed_pc=0x0c0c1b4au; return 0; }
r[4]=r[15];
goto P_0c0c1b4c;
P_0c0c1b4c: /* original f2f8, guest PC 0x0c0c1b4c */
if(!s->budget--) { s->failed_pc=0x0c0c1b4cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0c1b4e;
P_0c0c1b4e: /* original 633c, guest PC 0x0c0c1b4e */
if(!s->budget--) { s->failed_pc=0x0c0c1b4eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c1b50;
P_0c0c1b50: /* original 435a, guest PC 0x0c0c1b50 */
if(!s->budget--) { s->failed_pc=0x0c0c1b50u; return 0; }
r[53]=r[3];
goto P_0c0c1b52;
P_0c0c1b52: /* original 63f3, guest PC 0x0c0c1b52 */
if(!s->budget--) { s->failed_pc=0x0c0c1b52u; return 0; }
r[3]=r[15];
goto P_0c0c1b54;
P_0c0c1b54: /* original 7308, guest PC 0x0c0c1b54 */
if(!s->budget--) { s->failed_pc=0x0c0c1b54u; return 0; }
r[3]+=0x00000008u;
goto P_0c0c1b56;
P_0c0c1b56: /* original f32d, guest PC 0x0c0c1b56 */
if(!s->budget--) { s->failed_pc=0x0c0c1b56u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1b58;
P_0c0c1b58: /* original f231, guest PC 0x0c0c1b58 */
if(!s->budget--) { s->failed_pc=0x0c0c1b58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1b5a;
P_0c0c1b5a: /* original f32a, guest PC 0x0c0c1b5a */
if(!s->budget--) { s->failed_pc=0x0c0c1b5au; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c0c1b5c;
P_0c0c1b5c: /* original 4d0b, guest PC 0x0c0c1b5c */
if(!s->budget--) { s->failed_pc=0x0c0c1b5cu; return 0; }
target=r[13];
r[16]=0x0c0c1b60u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1b60u) { target=s->pc; goto dispatch; }
goto P_0c0c1b60;
P_0c0c1b5e: /* original 7404, guest PC 0x0c0c1b5e */
if(!s->budget--) { s->failed_pc=0x0c0c1b5eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1b60;
P_0c0c1b60: /* original f39d, guest PC 0x0c0c1b60 */
if(!s->budget--) { s->failed_pc=0x0c0c1b60u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1b62;
P_0c0c1b62: /* original ff30, guest PC 0x0c0c1b62 */
if(!s->budget--) { s->failed_pc=0x0c0c1b62u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c1b64;
P_0c0c1b64: /* original fdf5, guest PC 0x0c0c1b64 */
if(!s->budget--) { s->failed_pc=0x0c0c1b64u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[15]))!=0);
goto P_0c0c1b66;
P_0c0c1b66: /* original 89d9, guest PC 0x0c0c1b66 */
if(!s->budget--) { s->failed_pc=0x0c0c1b66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1b1c; }
goto P_0c0c1b68;
P_0c0c1b68: /* original a00e, guest PC 0x0c0c1b68 */
if(!s->budget--) { s->failed_pc=0x0c0c1b68u; return 0; }
goto P_0c0c1b88;
P_0c0c1b6a: /* original 0009, guest PC 0x0c0c1b6a */
if(!s->budget--) { s->failed_pc=0x0c0c1b6au; return 0; }
goto P_0c0c1b6c;
P_0c0c1b6c: /* original 65e3, guest PC 0x0c0c1b6c */
if(!s->budget--) { s->failed_pc=0x0c0c1b6cu; return 0; }
r[5]=r[14];
goto P_0c0c1b6e;
P_0c0c1b6e: /* original 64f3, guest PC 0x0c0c1b6e */
if(!s->budget--) { s->failed_pc=0x0c0c1b6eu; return 0; }
r[4]=r[15];
goto P_0c0c1b70;
P_0c0c1b70: /* original 7510, guest PC 0x0c0c1b70 */
if(!s->budget--) { s->failed_pc=0x0c0c1b70u; return 0; }
r[5]+=0x00000010u;
goto P_0c0c1b72;
P_0c0c1b72: /* original e634, guest PC 0x0c0c1b72 */
if(!s->budget--) { s->failed_pc=0x0c0c1b72u; return 0; }
r[6]=0x00000034u;
goto P_0c0c1b74;
P_0c0c1b74: /* original 4c0b, guest PC 0x0c0c1b74 */
if(!s->budget--) { s->failed_pc=0x0c0c1b74u; return 0; }
target=r[12];
r[16]=0x0c0c1b78u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1b78u) { target=s->pc; goto dispatch; }
goto P_0c0c1b78;
P_0c0c1b76: /* original 7404, guest PC 0x0c0c1b76 */
if(!s->budget--) { s->failed_pc=0x0c0c1b76u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1b78;
P_0c0c1b78: /* original e00c, guest PC 0x0c0c1b78 */
if(!s->budget--) { s->failed_pc=0x0c0c1b78u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1b7a;
P_0c0c1b7a: /* original 64f3, guest PC 0x0c0c1b7a */
if(!s->budget--) { s->failed_pc=0x0c0c1b7au; return 0; }
r[4]=r[15];
goto P_0c0c1b7c;
P_0c0c1b7c: /* original f3f6, guest PC 0x0c0c1b7c */
if(!s->budget--) { s->failed_pc=0x0c0c1b7cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c1b7e;
P_0c0c1b7e: /* original e00c, guest PC 0x0c0c1b7e */
if(!s->budget--) { s->failed_pc=0x0c0c1b7eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1b80;
P_0c0c1b80: /* original f3c0, guest PC 0x0c0c1b80 */
if(!s->budget--) { s->failed_pc=0x0c0c1b80u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'+');
goto P_0c0c1b82;
P_0c0c1b82: /* original ff37, guest PC 0x0c0c1b82 */
if(!s->budget--) { s->failed_pc=0x0c0c1b82u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1b84;
P_0c0c1b84: /* original 4d0b, guest PC 0x0c0c1b84 */
if(!s->budget--) { s->failed_pc=0x0c0c1b84u; return 0; }
target=r[13];
r[16]=0x0c0c1b88u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1b88u) { target=s->pc; goto dispatch; }
goto P_0c0c1b88;
P_0c0c1b86: /* original 7404, guest PC 0x0c0c1b86 */
if(!s->budget--) { s->failed_pc=0x0c0c1b86u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1b88;
P_0c0c1b88: /* original e378, guest PC 0x0c0c1b88 */
if(!s->budget--) { s->failed_pc=0x0c0c1b88u; return 0; }
r[3]=0x00000078u;
goto P_0c0c1b8a;
P_0c0c1b8a: /* original 7b01, guest PC 0x0c0c1b8a */
if(!s->budget--) { s->failed_pc=0x0c0c1b8au; return 0; }
r[11]+=0x00000001u;
goto P_0c0c1b8c;
P_0c0c1b8c: /* original 3b32, guest PC 0x0c0c1b8c */
if(!s->budget--) { s->failed_pc=0x0c0c1b8cu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[3])!=0);
goto P_0c0c1b8e;
P_0c0c1b8e: /* original 8faa, guest PC 0x0c0c1b8e */
if(!s->budget--) { s->failed_pc=0x0c0c1b8eu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c1ae6; }
goto P_0c0c1b92;
P_0c0c1b90: /* original 7e44, guest PC 0x0c0c1b90 */
if(!s->budget--) { s->failed_pc=0x0c0c1b90u; return 0; }
r[14]+=0x00000044u;
goto P_0c0c1b92;
P_0c0c1b92: /* original 7f38, guest PC 0x0c0c1b92 */
if(!s->budget--) { s->failed_pc=0x0c0c1b92u; return 0; }
r[15]+=0x00000038u;
goto P_0c0c1b94;
P_0c0c1b94: /* original 4f26, guest PC 0x0c0c1b94 */
if(!s->budget--) { s->failed_pc=0x0c0c1b94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1b96;
P_0c0c1b96: /* original fcf9, guest PC 0x0c0c1b96 */
if(!s->budget--) { s->failed_pc=0x0c0c1b96u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1b98;
P_0c0c1b98: /* original fdf9, guest PC 0x0c0c1b98 */
if(!s->budget--) { s->failed_pc=0x0c0c1b98u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1b9a;
P_0c0c1b9a: /* original fef9, guest PC 0x0c0c1b9a */
if(!s->budget--) { s->failed_pc=0x0c0c1b9au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1b9c;
P_0c0c1b9c: /* original fff9, guest PC 0x0c0c1b9c */
if(!s->budget--) { s->failed_pc=0x0c0c1b9cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1b9e;
P_0c0c1b9e: /* original 68f6, guest PC 0x0c0c1b9e */
if(!s->budget--) { s->failed_pc=0x0c0c1b9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1ba0;
P_0c0c1ba0: /* original 69f6, guest PC 0x0c0c1ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ba0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1ba2;
P_0c0c1ba2: /* original 6af6, guest PC 0x0c0c1ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ba2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1ba4;
P_0c0c1ba4: /* original 6bf6, guest PC 0x0c0c1ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ba4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1ba6;
P_0c0c1ba6: /* original 6cf6, guest PC 0x0c0c1ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ba6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1ba8;
P_0c0c1ba8: /* original 6df6, guest PC 0x0c0c1ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ba8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1baa;
P_0c0c1baa: /* original 000b, guest PC 0x0c0c1baa */
if(!s->budget--) { s->failed_pc=0x0c0c1baau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1bac: /* original 6ef6, guest PC 0x0c0c1bac */
if(!s->budget--) { s->failed_pc=0x0c0c1bacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1baeu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0ab8f0u,0x0c0ab8f2u,0x0c0ab8f4u,0x0c0ab8f6u,0x0c0ab8f8u,0x0c0ab8fau,0x0c0ab8fcu,0x0c0ab8feu,0x0c0ab900u,0x0c0ab902u,0x0c0ab904u,0x0c0ab906u,0x0c0ab908u,0x0c0ab90au,0x0c0ab90cu,0x0c0ab90eu,
0x0c0ab910u,0x0c0ab912u,0x0c0ab914u,0x0c0ab916u,0x0c0ab918u,0x0c0ab91au,0x0c0ab91cu,0x0c0ab91eu,0x0c0ab920u,0x0c0ab922u,0x0c0ab924u,0x0c0ab926u,0x0c0ab928u,0x0c0ab92au,0x0c0ab92cu,0x0c0ab92eu,
0x0c0ab930u,0x0c0ab932u,0x0c0ab934u,0x0c0ab936u,0x0c0ab938u,0x0c0ab93au,0x0c0ab93cu,0x0c0ab93eu,0x0c0ab940u,0x0c0ab942u,0x0c0ab944u,0x0c0ab946u,0x0c0ab948u,0x0c0ab94au,0x0c0ab94cu,0x0c0ab94eu,
0x0c0ab950u,0x0c0ab952u,0x0c0ab954u,0x0c0ab956u,0x0c0ab958u,0x0c0ab95au,0x0c0ab95cu,0x0c0ab95eu,0x0c0ab960u,0x0c0ab962u,0x0c0ab964u,0x0c0ab966u,0x0c0ab968u,0x0c0ab96au,0x0c0ab96cu,0x0c0ab96eu,
0x0c0ab970u,0x0c0ab972u,0x0c0ab974u,0x0c0ab976u,0x0c0ab978u,0x0c0ab97au,0x0c0ab97cu,0x0c0ab97eu,0x0c0ab980u,0x0c0ab982u,0x0c0ab984u,0x0c0ab986u,0x0c0ab988u,0x0c0ab98au,0x0c0ab98cu,0x0c0ab98eu,
0x0c0ab9c0u,0x0c0ab9c2u,0x0c0ab9c4u,0x0c0ab9c6u,0x0c0ab9c8u,0x0c0ab9cau,0x0c0ab9ccu,0x0c0ab9ceu,0x0c0ab9d0u,0x0c0ab9d2u,0x0c0ab9d4u,0x0c0ab9d6u,0x0c0ab9d8u,0x0c0ab9dau,0x0c0ab9dcu,0x0c0ab9deu,
0x0c0ab9e0u,0x0c0ab9e2u,0x0c0ab9e4u,0x0c0ab9e6u,0x0c0ab9e8u,0x0c0ab9eau,0x0c0ab9ecu,0x0c0ab9eeu,0x0c0ab9f0u,0x0c0ab9f2u,0x0c0ab9f4u,0x0c0ab9f6u,0x0c0ab9f8u,0x0c0ab9fau,0x0c0ab9fcu,0x0c0ab9feu,
0x0c0aba00u,0x0c0aba02u,0x0c0aba04u,0x0c0aba06u,0x0c0aba08u,0x0c0aba0au,0x0c0aba0cu,0x0c0aba0eu,0x0c0aba10u,0x0c0aba12u,0x0c0aba14u,0x0c0aba16u,0x0c0aba18u,0x0c0aba1au,0x0c0aba1cu,0x0c0aba1eu,
0x0c0aba20u,0x0c0aba22u,0x0c0aba24u,0x0c0aba26u,0x0c0aba28u,0x0c0aba2au,0x0c0aba2cu,0x0c0aba2eu,0x0c0aba30u,0x0c0aba32u,0x0c0aba34u,0x0c0aba36u,0x0c0aba38u,0x0c0aba3au,0x0c0aba3cu,0x0c0aba3eu,
0x0c0aba40u,0x0c0aba42u,0x0c0aba44u,0x0c0aba46u,0x0c0aba48u,0x0c0aba4au,0x0c0aba4cu,0x0c0aba4eu,0x0c0aba50u,0x0c0aba52u,0x0c0aba54u,0x0c0aba56u,0x0c0aba58u,0x0c0aba5au,0x0c0aba5cu,0x0c0aba5eu,
0x0c0aba60u,0x0c0aba62u,0x0c0aba64u,0x0c0aba66u,0x0c0aba68u,0x0c0aba6au,0x0c0aba6cu,0x0c0aba6eu,0x0c0aba70u,0x0c0aba72u,0x0c0aba74u,0x0c0aba76u,0x0c0aba78u,0x0c0aba7au,0x0c0aba7cu,0x0c0aba7eu,
0x0c0aba80u,0x0c0aba82u,0x0c0aba84u,0x0c0aba86u,0x0c0aba88u,0x0c0aba8au,0x0c0aba8cu,0x0c0aba8eu,0x0c0aba90u,0x0c0aba92u,0x0c0aba94u,0x0c0aba96u,0x0c0abad0u,0x0c0abad2u,0x0c0abad4u,0x0c0abad6u,
0x0c0abad8u,0x0c0abadau,0x0c0abadcu,0x0c0abadeu,0x0c0abae0u,0x0c0abae2u,0x0c0abae4u,0x0c0abae6u,0x0c0abae8u,0x0c0abaeau,0x0c0abaecu,0x0c0abaeeu,0x0c0abaf0u,0x0c0abaf2u,0x0c0abaf4u,0x0c0abaf6u,
0x0c0abaf8u,0x0c0abafau,0x0c0abafcu,0x0c0abafeu,0x0c0abb00u,0x0c0abb02u,0x0c0abb04u,0x0c0abb06u,0x0c0abb08u,0x0c0abb0au,0x0c0abb0cu,0x0c0abb0eu,0x0c0abb10u,0x0c0abb12u,0x0c0abb14u,0x0c0abb16u,
0x0c0abb18u,0x0c0abb1au,0x0c0abb1cu,0x0c0abb1eu,0x0c0abb20u,0x0c0abb22u,0x0c0abb24u,0x0c0abb26u,0x0c0abb28u,0x0c0abbbau,0x0c0abbbcu,0x0c0abbbeu,0x0c0abbc0u,0x0c0abbc2u,0x0c0abbc4u,0x0c0abbc6u,
0x0c0abbc8u,0x0c0abbcau,0x0c0abbccu,0x0c0abbceu,0x0c0abbd0u,0x0c0abbd2u,0x0c0abbd4u,0x0c0abbd6u,0x0c0abbd8u,0x0c0abbdau,0x0c0abbdcu,0x0c0abbdeu,0x0c0abdc4u,0x0c0abdc6u,0x0c0abdc8u,0x0c0abdcau,
0x0c0abdccu,0x0c0abdceu,0x0c0abdd0u,0x0c0abdd2u,0x0c0abdd4u,0x0c0abdd6u,0x0c0abdd8u,0x0c0abddau,0x0c0abddcu,0x0c0abddeu,0x0c0abde0u,0x0c0abde2u,0x0c0abde4u,0x0c0abde6u,0x0c0abde8u,0x0c0abdeau,
0x0c0abdecu,0x0c0abdeeu,0x0c0abdf0u,0x0c0abdf2u,0x0c0abdf4u,0x0c0abdf6u,0x0c0abdf8u,0x0c0abdfau,0x0c0abe20u,0x0c0abe22u,0x0c0abe24u,0x0c0abe26u,0x0c0abe28u,0x0c0abe2au,0x0c0abe2cu,0x0c0abe2eu,
0x0c0abe30u,0x0c0abe32u,0x0c0abe34u,0x0c0abe36u,0x0c0abe38u,0x0c0abe3au,0x0c0abe3cu,0x0c0abe3eu,0x0c0abe40u,0x0c0abe42u,0x0c0abe44u,0x0c0abe46u,0x0c0abe48u,0x0c0abe4au,0x0c0abe4cu,0x0c0abe4eu,
0x0c0abe50u,0x0c0abe52u,0x0c0abe54u,0x0c0abe56u,0x0c0abe58u,0x0c0abe5au,0x0c0abe5cu,0x0c0abe5eu,0x0c0abe60u,0x0c0abe62u,0x0c0abe64u,0x0c0abe66u,0x0c0abe68u,0x0c0abe6au,0x0c0abe6cu,0x0c0abe6eu,
0x0c0abe70u,0x0c0abe72u,0x0c0abe74u,0x0c0abe76u,0x0c0abe78u,0x0c0abe7au,0x0c0abe7cu,0x0c0abe7eu,0x0c0abe80u,0x0c0abe82u,0x0c0c1ac2u,0x0c0c1ac4u,0x0c0c1ac6u,0x0c0c1ac8u,0x0c0c1acau,0x0c0c1accu,
0x0c0c1aceu,0x0c0c1ad0u,0x0c0c1ad2u,0x0c0c1ad4u,0x0c0c1ad6u,0x0c0c1ad8u,0x0c0c1adau,0x0c0c1adcu,0x0c0c1adeu,0x0c0c1ae0u,0x0c0c1ae2u,0x0c0c1ae4u,0x0c0c1ae6u,0x0c0c1ae8u,0x0c0c1aeau,0x0c0c1aecu,
0x0c0c1aeeu,0x0c0c1af0u,0x0c0c1af2u,0x0c0c1af4u,0x0c0c1af6u,0x0c0c1af8u,0x0c0c1afau,0x0c0c1afcu,0x0c0c1afeu,0x0c0c1b00u,0x0c0c1b02u,0x0c0c1b04u,0x0c0c1b06u,0x0c0c1b08u,0x0c0c1b0au,0x0c0c1b0cu,
0x0c0c1b0eu,0x0c0c1b10u,0x0c0c1b12u,0x0c0c1b14u,0x0c0c1b16u,0x0c0c1b18u,0x0c0c1b1au,0x0c0c1b1cu,0x0c0c1b1eu,0x0c0c1b20u,0x0c0c1b22u,0x0c0c1b24u,0x0c0c1b26u,0x0c0c1b28u,0x0c0c1b2au,0x0c0c1b2cu,
0x0c0c1b2eu,0x0c0c1b30u,0x0c0c1b32u,0x0c0c1b34u,0x0c0c1b36u,0x0c0c1b38u,0x0c0c1b3au,0x0c0c1b3cu,0x0c0c1b3eu,0x0c0c1b40u,0x0c0c1b42u,0x0c0c1b44u,0x0c0c1b46u,0x0c0c1b48u,0x0c0c1b4au,0x0c0c1b4cu,
0x0c0c1b4eu,0x0c0c1b50u,0x0c0c1b52u,0x0c0c1b54u,0x0c0c1b56u,0x0c0c1b58u,0x0c0c1b5au,0x0c0c1b5cu,0x0c0c1b5eu,0x0c0c1b60u,0x0c0c1b62u,0x0c0c1b64u,0x0c0c1b66u,0x0c0c1b68u,0x0c0c1b6au,0x0c0c1b6cu,
0x0c0c1b6eu,0x0c0c1b70u,0x0c0c1b72u,0x0c0c1b74u,0x0c0c1b76u,0x0c0c1b78u,0x0c0c1b7au,0x0c0c1b7cu,0x0c0c1b7eu,0x0c0c1b80u,0x0c0c1b82u,0x0c0c1b84u,0x0c0c1b86u,0x0c0c1b88u,0x0c0c1b8au,0x0c0c1b8cu,
0x0c0c1b8eu,0x0c0c1b90u,0x0c0c1b92u,0x0c0c1b94u,0x0c0c1b96u,0x0c0c1b98u,0x0c0c1b9au,0x0c0c1b9cu,0x0c0c1b9eu,0x0c0c1ba0u,0x0c0c1ba2u,0x0c0c1ba4u,0x0c0c1ba6u,0x0c0c1ba8u,0x0c0c1baau,0x0c0c1bacu,
};
int vf3_advance_branch_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
