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
int vf3_away_batch21_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0aca94u: goto P_0c0aca94;
case 0x0c0aca96u: goto P_0c0aca96;
case 0x0c0aca98u: goto P_0c0aca98;
case 0x0c0aca9au: goto P_0c0aca9a;
case 0x0c0aca9cu: goto P_0c0aca9c;
case 0x0c0aca9eu: goto P_0c0aca9e;
case 0x0c0acaa0u: goto P_0c0acaa0;
case 0x0c0acaa2u: goto P_0c0acaa2;
case 0x0c0acaa4u: goto P_0c0acaa4;
case 0x0c0acaa6u: goto P_0c0acaa6;
case 0x0c0acaa8u: goto P_0c0acaa8;
case 0x0c0acaaau: goto P_0c0acaaa;
case 0x0c0acaacu: goto P_0c0acaac;
case 0x0c0acaaeu: goto P_0c0acaae;
case 0x0c0acab0u: goto P_0c0acab0;
case 0x0c0acab2u: goto P_0c0acab2;
case 0x0c0acab4u: goto P_0c0acab4;
case 0x0c0acab6u: goto P_0c0acab6;
case 0x0c0acab8u: goto P_0c0acab8;
case 0x0c0acabau: goto P_0c0acaba;
case 0x0c0acabcu: goto P_0c0acabc;
case 0x0c0acabeu: goto P_0c0acabe;
case 0x0c0acac0u: goto P_0c0acac0;
case 0x0c0acac2u: goto P_0c0acac2;
case 0x0c0acac4u: goto P_0c0acac4;
case 0x0c0acac6u: goto P_0c0acac6;
case 0x0c0acac8u: goto P_0c0acac8;
case 0x0c0acacau: goto P_0c0acaca;
case 0x0c0acaccu: goto P_0c0acacc;
case 0x0c0acaceu: goto P_0c0acace;
case 0x0c0acad0u: goto P_0c0acad0;
case 0x0c0acad2u: goto P_0c0acad2;
case 0x0c0acad4u: goto P_0c0acad4;
case 0x0c0acad6u: goto P_0c0acad6;
case 0x0c0acad8u: goto P_0c0acad8;
case 0x0c0acadau: goto P_0c0acada;
case 0x0c0acadcu: goto P_0c0acadc;
case 0x0c0acadeu: goto P_0c0acade;
case 0x0c0acae0u: goto P_0c0acae0;
case 0x0c0acae2u: goto P_0c0acae2;
case 0x0c0acae4u: goto P_0c0acae4;
case 0x0c0acae6u: goto P_0c0acae6;
case 0x0c0acae8u: goto P_0c0acae8;
case 0x0c0acaeau: goto P_0c0acaea;
case 0x0c0acaecu: goto P_0c0acaec;
case 0x0c0acaeeu: goto P_0c0acaee;
case 0x0c0acaf0u: goto P_0c0acaf0;
case 0x0c0acaf2u: goto P_0c0acaf2;
case 0x0c0acaf4u: goto P_0c0acaf4;
case 0x0c0acaf6u: goto P_0c0acaf6;
case 0x0c0acaf8u: goto P_0c0acaf8;
case 0x0c0acafau: goto P_0c0acafa;
case 0x0c0acafcu: goto P_0c0acafc;
case 0x0c0acafeu: goto P_0c0acafe;
case 0x0c0acb00u: goto P_0c0acb00;
case 0x0c0acb02u: goto P_0c0acb02;
case 0x0c0acb04u: goto P_0c0acb04;
case 0x0c0acb06u: goto P_0c0acb06;
case 0x0c0acb08u: goto P_0c0acb08;
case 0x0c0acb0au: goto P_0c0acb0a;
case 0x0c0acb0cu: goto P_0c0acb0c;
case 0x0c0acb0eu: goto P_0c0acb0e;
case 0x0c0acb10u: goto P_0c0acb10;
case 0x0c0acb12u: goto P_0c0acb12;
case 0x0c0acb14u: goto P_0c0acb14;
case 0x0c0acb16u: goto P_0c0acb16;
case 0x0c0acb18u: goto P_0c0acb18;
case 0x0c0acb1au: goto P_0c0acb1a;
case 0x0c0acb1cu: goto P_0c0acb1c;
case 0x0c0acb1eu: goto P_0c0acb1e;
case 0x0c0acb20u: goto P_0c0acb20;
case 0x0c0acb22u: goto P_0c0acb22;
case 0x0c0acb24u: goto P_0c0acb24;
case 0x0c0acb26u: goto P_0c0acb26;
case 0x0c0acb28u: goto P_0c0acb28;
case 0x0c0acb2au: goto P_0c0acb2a;
case 0x0c0acb2cu: goto P_0c0acb2c;
case 0x0c0acb2eu: goto P_0c0acb2e;
case 0x0c0acb30u: goto P_0c0acb30;
case 0x0c0acb32u: goto P_0c0acb32;
case 0x0c0acb34u: goto P_0c0acb34;
case 0x0c0acb36u: goto P_0c0acb36;
case 0x0c0acb38u: goto P_0c0acb38;
case 0x0c0acb3au: goto P_0c0acb3a;
case 0x0c0acb3cu: goto P_0c0acb3c;
case 0x0c0acb3eu: goto P_0c0acb3e;
case 0x0c0acb40u: goto P_0c0acb40;
case 0x0c0acb42u: goto P_0c0acb42;
case 0x0c0acb44u: goto P_0c0acb44;
case 0x0c0acb46u: goto P_0c0acb46;
case 0x0c0acb48u: goto P_0c0acb48;
case 0x0c0acb4au: goto P_0c0acb4a;
case 0x0c0acb4cu: goto P_0c0acb4c;
case 0x0c0acb4eu: goto P_0c0acb4e;
case 0x0c0acb50u: goto P_0c0acb50;
case 0x0c0acb52u: goto P_0c0acb52;
case 0x0c0acb54u: goto P_0c0acb54;
case 0x0c0acb56u: goto P_0c0acb56;
case 0x0c0acb58u: goto P_0c0acb58;
case 0x0c0acb5au: goto P_0c0acb5a;
case 0x0c0acb5cu: goto P_0c0acb5c;
case 0x0c0acb5eu: goto P_0c0acb5e;
case 0x0c0acb60u: goto P_0c0acb60;
case 0x0c0acb62u: goto P_0c0acb62;
case 0x0c0acb64u: goto P_0c0acb64;
case 0x0c0acb66u: goto P_0c0acb66;
case 0x0c0acb68u: goto P_0c0acb68;
case 0x0c0acb6au: goto P_0c0acb6a;
case 0x0c0acb6cu: goto P_0c0acb6c;
case 0x0c0acb6eu: goto P_0c0acb6e;
case 0x0c0acb70u: goto P_0c0acb70;
case 0x0c0acb72u: goto P_0c0acb72;
case 0x0c0acb74u: goto P_0c0acb74;
case 0x0c0acb76u: goto P_0c0acb76;
case 0x0c0acb78u: goto P_0c0acb78;
case 0x0c0acb7au: goto P_0c0acb7a;
case 0x0c0acb7cu: goto P_0c0acb7c;
case 0x0c0acb7eu: goto P_0c0acb7e;
case 0x0c0acb80u: goto P_0c0acb80;
case 0x0c0acbb4u: goto P_0c0acbb4;
case 0x0c0acbb6u: goto P_0c0acbb6;
case 0x0c0acbb8u: goto P_0c0acbb8;
case 0x0c0acbbau: goto P_0c0acbba;
case 0x0c0acbbcu: goto P_0c0acbbc;
case 0x0c0acbbeu: goto P_0c0acbbe;
case 0x0c0acbc0u: goto P_0c0acbc0;
case 0x0c0acbc2u: goto P_0c0acbc2;
case 0x0c0acbc4u: goto P_0c0acbc4;
case 0x0c0acbc6u: goto P_0c0acbc6;
case 0x0c0acbc8u: goto P_0c0acbc8;
case 0x0c0acbcau: goto P_0c0acbca;
case 0x0c0acbccu: goto P_0c0acbcc;
case 0x0c0acbceu: goto P_0c0acbce;
case 0x0c0acbd0u: goto P_0c0acbd0;
case 0x0c0acbd2u: goto P_0c0acbd2;
case 0x0c0acbd4u: goto P_0c0acbd4;
case 0x0c0acbd6u: goto P_0c0acbd6;
case 0x0c0acbd8u: goto P_0c0acbd8;
case 0x0c0acbdau: goto P_0c0acbda;
case 0x0c0acbdcu: goto P_0c0acbdc;
case 0x0c0acbdeu: goto P_0c0acbde;
case 0x0c0acbe0u: goto P_0c0acbe0;
case 0x0c0acbe2u: goto P_0c0acbe2;
case 0x0c0acbe4u: goto P_0c0acbe4;
case 0x0c0acbe6u: goto P_0c0acbe6;
case 0x0c0acbe8u: goto P_0c0acbe8;
case 0x0c0acbeau: goto P_0c0acbea;
case 0x0c0acbecu: goto P_0c0acbec;
case 0x0c0acbeeu: goto P_0c0acbee;
case 0x0c0acbf0u: goto P_0c0acbf0;
case 0x0c0acbf2u: goto P_0c0acbf2;
case 0x0c0acbf4u: goto P_0c0acbf4;
case 0x0c0acbf6u: goto P_0c0acbf6;
case 0x0c0acbf8u: goto P_0c0acbf8;
case 0x0c0acbfau: goto P_0c0acbfa;
case 0x0c0acbfcu: goto P_0c0acbfc;
case 0x0c0acbfeu: goto P_0c0acbfe;
case 0x0c0acc00u: goto P_0c0acc00;
case 0x0c0acc02u: goto P_0c0acc02;
case 0x0c0acc04u: goto P_0c0acc04;
case 0x0c0acc06u: goto P_0c0acc06;
case 0x0c0acc08u: goto P_0c0acc08;
case 0x0c0acc0au: goto P_0c0acc0a;
case 0x0c0acc0cu: goto P_0c0acc0c;
case 0x0c0acc0eu: goto P_0c0acc0e;
case 0x0c0acc10u: goto P_0c0acc10;
case 0x0c0acc12u: goto P_0c0acc12;
case 0x0c0acc14u: goto P_0c0acc14;
case 0x0c0acc16u: goto P_0c0acc16;
case 0x0c0acc18u: goto P_0c0acc18;
case 0x0c0acc1au: goto P_0c0acc1a;
case 0x0c0acc1cu: goto P_0c0acc1c;
case 0x0c0acc1eu: goto P_0c0acc1e;
case 0x0c0acc20u: goto P_0c0acc20;
case 0x0c0acc22u: goto P_0c0acc22;
case 0x0c0acc24u: goto P_0c0acc24;
case 0x0c0acc26u: goto P_0c0acc26;
case 0x0c0acc28u: goto P_0c0acc28;
case 0x0c0acc2au: goto P_0c0acc2a;
case 0x0c0acc2cu: goto P_0c0acc2c;
case 0x0c0acc2eu: goto P_0c0acc2e;
case 0x0c0acc30u: goto P_0c0acc30;
case 0x0c0acc32u: goto P_0c0acc32;
case 0x0c0acc34u: goto P_0c0acc34;
case 0x0c0acc36u: goto P_0c0acc36;
case 0x0c0acc38u: goto P_0c0acc38;
case 0x0c0acc3au: goto P_0c0acc3a;
case 0x0c0acc3cu: goto P_0c0acc3c;
case 0x0c0acc3eu: goto P_0c0acc3e;
case 0x0c0acc40u: goto P_0c0acc40;
case 0x0c0acc42u: goto P_0c0acc42;
case 0x0c0acc44u: goto P_0c0acc44;
case 0x0c0acc46u: goto P_0c0acc46;
case 0x0c0acc48u: goto P_0c0acc48;
case 0x0c0acc4au: goto P_0c0acc4a;
case 0x0c0acc4cu: goto P_0c0acc4c;
case 0x0c0acc4eu: goto P_0c0acc4e;
case 0x0c0acc50u: goto P_0c0acc50;
case 0x0c0acc52u: goto P_0c0acc52;
case 0x0c0acc54u: goto P_0c0acc54;
case 0x0c0acc56u: goto P_0c0acc56;
case 0x0c0acc58u: goto P_0c0acc58;
case 0x0c0acc5au: goto P_0c0acc5a;
case 0x0c0acc5cu: goto P_0c0acc5c;
case 0x0c0acc5eu: goto P_0c0acc5e;
case 0x0c0acc60u: goto P_0c0acc60;
case 0x0c0acc94u: goto P_0c0acc94;
case 0x0c0acc96u: goto P_0c0acc96;
case 0x0c0acc98u: goto P_0c0acc98;
case 0x0c0acc9au: goto P_0c0acc9a;
case 0x0c0acc9cu: goto P_0c0acc9c;
case 0x0c0acc9eu: goto P_0c0acc9e;
case 0x0c0acca0u: goto P_0c0acca0;
case 0x0c0acca2u: goto P_0c0acca2;
case 0x0c0acca4u: goto P_0c0acca4;
case 0x0c0acca6u: goto P_0c0acca6;
case 0x0c0acca8u: goto P_0c0acca8;
case 0x0c0accaau: goto P_0c0accaa;
case 0x0c0accacu: goto P_0c0accac;
case 0x0c0accaeu: goto P_0c0accae;
case 0x0c0accb0u: goto P_0c0accb0;
case 0x0c0accb2u: goto P_0c0accb2;
case 0x0c0accb4u: goto P_0c0accb4;
case 0x0c0accb6u: goto P_0c0accb6;
case 0x0c0accb8u: goto P_0c0accb8;
case 0x0c0accbau: goto P_0c0accba;
case 0x0c0accbcu: goto P_0c0accbc;
case 0x0c0accbeu: goto P_0c0accbe;
case 0x0c0accc0u: goto P_0c0accc0;
case 0x0c0accc2u: goto P_0c0accc2;
case 0x0c0accc4u: goto P_0c0accc4;
case 0x0c0accc6u: goto P_0c0accc6;
case 0x0c0accc8u: goto P_0c0accc8;
case 0x0c0acccau: goto P_0c0accca;
case 0x0c0accccu: goto P_0c0acccc;
case 0x0c0accceu: goto P_0c0accce;
case 0x0c0accd0u: goto P_0c0accd0;
case 0x0c0accd2u: goto P_0c0accd2;
case 0x0c0accd4u: goto P_0c0accd4;
case 0x0c0accd6u: goto P_0c0accd6;
case 0x0c0accd8u: goto P_0c0accd8;
case 0x0c0accdau: goto P_0c0accda;
case 0x0c0accdcu: goto P_0c0accdc;
case 0x0c0accdeu: goto P_0c0accde;
case 0x0c0acce0u: goto P_0c0acce0;
case 0x0c0acce2u: goto P_0c0acce2;
case 0x0c0acce4u: goto P_0c0acce4;
case 0x0c0acce6u: goto P_0c0acce6;
case 0x0c0acce8u: goto P_0c0acce8;
case 0x0c0acceau: goto P_0c0accea;
case 0x0c0accecu: goto P_0c0accec;
case 0x0c0acceeu: goto P_0c0accee;
case 0x0c0accf0u: goto P_0c0accf0;
case 0x0c0accf2u: goto P_0c0accf2;
case 0x0c0accf4u: goto P_0c0accf4;
case 0x0c0accf6u: goto P_0c0accf6;
case 0x0c0accf8u: goto P_0c0accf8;
case 0x0c0accfau: goto P_0c0accfa;
case 0x0c0accfcu: goto P_0c0accfc;
case 0x0c0accfeu: goto P_0c0accfe;
case 0x0c0acd00u: goto P_0c0acd00;
case 0x0c0acd02u: goto P_0c0acd02;
case 0x0c0acd04u: goto P_0c0acd04;
case 0x0c0acd06u: goto P_0c0acd06;
case 0x0c0acd08u: goto P_0c0acd08;
case 0x0c0acd0au: goto P_0c0acd0a;
case 0x0c0acd0cu: goto P_0c0acd0c;
case 0x0c0acd0eu: goto P_0c0acd0e;
case 0x0c0acd10u: goto P_0c0acd10;
case 0x0c0acd12u: goto P_0c0acd12;
case 0x0c0acd14u: goto P_0c0acd14;
case 0x0c0acd16u: goto P_0c0acd16;
case 0x0c0acd18u: goto P_0c0acd18;
case 0x0c0acd1au: goto P_0c0acd1a;
case 0x0c0acd1cu: goto P_0c0acd1c;
case 0x0c0acd1eu: goto P_0c0acd1e;
case 0x0c0acd20u: goto P_0c0acd20;
case 0x0c0acd22u: goto P_0c0acd22;
case 0x0c0acd24u: goto P_0c0acd24;
case 0x0c0acd26u: goto P_0c0acd26;
case 0x0c0acd28u: goto P_0c0acd28;
case 0x0c0acd2au: goto P_0c0acd2a;
case 0x0c0acd2cu: goto P_0c0acd2c;
case 0x0c0acd2eu: goto P_0c0acd2e;
case 0x0c0acd30u: goto P_0c0acd30;
case 0x0c0acd32u: goto P_0c0acd32;
case 0x0c0acd34u: goto P_0c0acd34;
case 0x0c0acd36u: goto P_0c0acd36;
case 0x0c0acd38u: goto P_0c0acd38;
case 0x0c0acd3au: goto P_0c0acd3a;
case 0x0c0acd3cu: goto P_0c0acd3c;
case 0x0c0acd3eu: goto P_0c0acd3e;
case 0x0c0acd40u: goto P_0c0acd40;
case 0x0c0acd42u: goto P_0c0acd42;
case 0x0c0acd44u: goto P_0c0acd44;
case 0x0c0acd46u: goto P_0c0acd46;
case 0x0c0acd48u: goto P_0c0acd48;
case 0x0c0acd4au: goto P_0c0acd4a;
case 0x0c0acd4cu: goto P_0c0acd4c;
case 0x0c0acd4eu: goto P_0c0acd4e;
case 0x0c0acd50u: goto P_0c0acd50;
case 0x0c0acd52u: goto P_0c0acd52;
case 0x0c0acd54u: goto P_0c0acd54;
case 0x0c0acd56u: goto P_0c0acd56;
case 0x0c0acd58u: goto P_0c0acd58;
case 0x0c0acd5au: goto P_0c0acd5a;
case 0x0c0acd5cu: goto P_0c0acd5c;
case 0x0c0acd5eu: goto P_0c0acd5e;
case 0x0c0acd60u: goto P_0c0acd60;
case 0x0c0acd62u: goto P_0c0acd62;
case 0x0c0acd64u: goto P_0c0acd64;
case 0x0c0acd66u: goto P_0c0acd66;
case 0x0c0acd68u: goto P_0c0acd68;
case 0x0c0acd6au: goto P_0c0acd6a;
case 0x0c0acd6cu: goto P_0c0acd6c;
case 0x0c0acd6eu: goto P_0c0acd6e;
case 0x0c0acd70u: goto P_0c0acd70;
case 0x0c0acd72u: goto P_0c0acd72;
case 0x0c0acd74u: goto P_0c0acd74;
case 0x0c0acd76u: goto P_0c0acd76;
case 0x0c0acd78u: goto P_0c0acd78;
case 0x0c0acd7au: goto P_0c0acd7a;
case 0x0c0acd7cu: goto P_0c0acd7c;
case 0x0c0acd7eu: goto P_0c0acd7e;
case 0x0c0acd80u: goto P_0c0acd80;
case 0x0c0acd82u: goto P_0c0acd82;
case 0x0c0acd84u: goto P_0c0acd84;
case 0x0c0acd86u: goto P_0c0acd86;
case 0x0c0acd88u: goto P_0c0acd88;
case 0x0c0acd8au: goto P_0c0acd8a;
case 0x0c0acd8cu: goto P_0c0acd8c;
case 0x0c0acd8eu: goto P_0c0acd8e;
case 0x0c0acd90u: goto P_0c0acd90;
case 0x0c0acd92u: goto P_0c0acd92;
case 0x0c0acd94u: goto P_0c0acd94;
case 0x0c0acd96u: goto P_0c0acd96;
case 0x0c0acd98u: goto P_0c0acd98;
case 0x0c0acd9au: goto P_0c0acd9a;
case 0x0c0acd9cu: goto P_0c0acd9c;
case 0x0c0acdd0u: goto P_0c0acdd0;
case 0x0c0acdd2u: goto P_0c0acdd2;
case 0x0c0acdd4u: goto P_0c0acdd4;
case 0x0c0acdd6u: goto P_0c0acdd6;
case 0x0c0acdd8u: goto P_0c0acdd8;
case 0x0c0acddau: goto P_0c0acdda;
case 0x0c0acddcu: goto P_0c0acddc;
case 0x0c0acddeu: goto P_0c0acdde;
case 0x0c0acde0u: goto P_0c0acde0;
case 0x0c0acde2u: goto P_0c0acde2;
case 0x0c0acde4u: goto P_0c0acde4;
case 0x0c0acde6u: goto P_0c0acde6;
case 0x0c0acde8u: goto P_0c0acde8;
case 0x0c0acdeau: goto P_0c0acdea;
case 0x0c0acdecu: goto P_0c0acdec;
case 0x0c0acdeeu: goto P_0c0acdee;
case 0x0c0acdf0u: goto P_0c0acdf0;
case 0x0c0acdf2u: goto P_0c0acdf2;
case 0x0c0acdf4u: goto P_0c0acdf4;
case 0x0c0acdf6u: goto P_0c0acdf6;
case 0x0c0acdf8u: goto P_0c0acdf8;
case 0x0c0acdfau: goto P_0c0acdfa;
case 0x0c0acdfcu: goto P_0c0acdfc;
case 0x0c0acdfeu: goto P_0c0acdfe;
case 0x0c0ace00u: goto P_0c0ace00;
case 0x0c0ace02u: goto P_0c0ace02;
case 0x0c0ace04u: goto P_0c0ace04;
case 0x0c0ace06u: goto P_0c0ace06;
case 0x0c0ace08u: goto P_0c0ace08;
case 0x0c0ace0au: goto P_0c0ace0a;
case 0x0c0ace0cu: goto P_0c0ace0c;
case 0x0c0ace0eu: goto P_0c0ace0e;
case 0x0c0ace10u: goto P_0c0ace10;
case 0x0c0ace12u: goto P_0c0ace12;
case 0x0c0ace14u: goto P_0c0ace14;
case 0x0c0ace16u: goto P_0c0ace16;
case 0x0c0ace18u: goto P_0c0ace18;
case 0x0c0ace1au: goto P_0c0ace1a;
case 0x0c0ace1cu: goto P_0c0ace1c;
case 0x0c0ace1eu: goto P_0c0ace1e;
case 0x0c0ace20u: goto P_0c0ace20;
case 0x0c0ace22u: goto P_0c0ace22;
case 0x0c0ace24u: goto P_0c0ace24;
case 0x0c0ace26u: goto P_0c0ace26;
case 0x0c0ace28u: goto P_0c0ace28;
case 0x0c0ace2au: goto P_0c0ace2a;
case 0x0c0ace2cu: goto P_0c0ace2c;
case 0x0c0ace2eu: goto P_0c0ace2e;
case 0x0c0ace30u: goto P_0c0ace30;
case 0x0c0ace32u: goto P_0c0ace32;
default: return vf3_matrix_family(target,s,ram);
}
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
goto P_0c0aca18;
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
goto P_0c0aca18;
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
if(!vf3_matrix_family(0x0c0aca6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aca6eu; return 0; } return 1;
P_0c0aca94: /* original 2fe6, guest PC 0x0c0aca94 */
if(!s->budget--) { s->failed_pc=0x0c0aca94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aca96;
P_0c0aca96: /* original 6e43, guest PC 0x0c0aca96 */
if(!s->budget--) { s->failed_pc=0x0c0aca96u; return 0; }
r[14]=r[4];
goto P_0c0aca98;
P_0c0aca98: /* original 2fd6, guest PC 0x0c0aca98 */
if(!s->budget--) { s->failed_pc=0x0c0aca98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aca9a;
P_0c0aca9a: /* original 6d63, guest PC 0x0c0aca9a */
if(!s->budget--) { s->failed_pc=0x0c0aca9au; return 0; }
r[13]=r[6];
goto P_0c0aca9c;
P_0c0aca9c: /* original 2fc6, guest PC 0x0c0aca9c */
if(!s->budget--) { s->failed_pc=0x0c0aca9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aca9e;
P_0c0aca9e: /* original e401, guest PC 0x0c0aca9e */
if(!s->budget--) { s->failed_pc=0x0c0aca9eu; return 0; }
r[4]=0x00000001u;
goto P_0c0acaa0;
P_0c0acaa0: /* original 2fb6, guest PC 0x0c0acaa0 */
if(!s->budget--) { s->failed_pc=0x0c0acaa0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0acaa2;
P_0c0acaa2: /* original 2fa6, guest PC 0x0c0acaa2 */
if(!s->budget--) { s->failed_pc=0x0c0acaa2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0acaa4;
P_0c0acaa4: /* original 2f96, guest PC 0x0c0acaa4 */
if(!s->budget--) { s->failed_pc=0x0c0acaa4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0acaa6;
P_0c0acaa6: /* original 2f86, guest PC 0x0c0acaa6 */
if(!s->budget--) { s->failed_pc=0x0c0acaa6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0acaa8;
P_0c0acaa8: /* original 4f22, guest PC 0x0c0acaa8 */
if(!s->budget--) { s->failed_pc=0x0c0acaa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0acaaa;
P_0c0acaaa: /* original d33a, guest PC 0x0c0acaaa */
if(!s->budget--) { s->failed_pc=0x0c0acaaau; return 0; }
r[3]=read(ram,0x0c0acb94u,4);
goto P_0c0acaac;
P_0c0acaac: /* original 7fe8, guest PC 0x0c0acaac */
if(!s->budget--) { s->failed_pc=0x0c0acaacu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0acaae;
P_0c0acaae: /* original 1f32, guest PC 0x0c0acaae */
if(!s->budget--) { s->failed_pc=0x0c0acaaeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0acab0;
P_0c0acab0: /* original 53d1, guest PC 0x0c0acab0 */
if(!s->budget--) { s->failed_pc=0x0c0acab0u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0acab2;
P_0c0acab2: /* original db3a, guest PC 0x0c0acab2 */
if(!s->budget--) { s->failed_pc=0x0c0acab2u; return 0; }
r[11]=read(ram,0x0c0acb9cu,4);
goto P_0c0acab4;
P_0c0acab4: /* original da38, guest PC 0x0c0acab4 */
if(!s->budget--) { s->failed_pc=0x0c0acab4u; return 0; }
r[10]=read(ram,0x0c0acb98u,4);
goto P_0c0acab6;
P_0c0acab6: /* original 3342, guest PC 0x0c0acab6 */
if(!s->budget--) { s->failed_pc=0x0c0acab6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0acab8;
P_0c0acab8: /* original 9963, guest PC 0x0c0acab8 */
if(!s->budget--) { s->failed_pc=0x0c0acab8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb82u,2);
goto P_0c0acaba;
P_0c0acaba: /* original 8f0e, guest PC 0x0c0acaba */
if(!s->budget--) { s->failed_pc=0x0c0acabau; return 0; }
cond=r[17]&1u;
r[12]=r[5];
if(!cond) { goto P_0c0acada; }
goto P_0c0acabe;
P_0c0acabc: /* original 6c53, guest PC 0x0c0acabc */
if(!s->budget--) { s->failed_pc=0x0c0acabcu; return 0; }
r[12]=r[5];
goto P_0c0acabe;
P_0c0acabe: /* original 50d1, guest PC 0x0c0acabe */
if(!s->budget--) { s->failed_pc=0x0c0acabeu; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0acac0;
P_0c0acac0: /* original 8801, guest PC 0x0c0acac0 */
if(!s->budget--) { s->failed_pc=0x0c0acac0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0acac2;
P_0c0acac2: /* original 8977, guest PC 0x0c0acac2 */
if(!s->budget--) { s->failed_pc=0x0c0acac2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbb4; }
goto P_0c0acac4;
P_0c0acac4: /* original 50d1, guest PC 0x0c0acac4 */
if(!s->budget--) { s->failed_pc=0x0c0acac4u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0acac6;
P_0c0acac6: /* original 8802, guest PC 0x0c0acac6 */
if(!s->budget--) { s->failed_pc=0x0c0acac6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0acac8;
P_0c0acac8: /* original 8b01, guest PC 0x0c0acac8 */
if(!s->budget--) { s->failed_pc=0x0c0acac8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acace; }
goto P_0c0acaca;
P_0c0acaca: /* original a0b9, guest PC 0x0c0acaca */
if(!s->budget--) { s->failed_pc=0x0c0acacau; return 0; }
goto P_0c0acc40;
P_0c0acacc: /* original 0009, guest PC 0x0c0acacc */
if(!s->budget--) { s->failed_pc=0x0c0acaccu; return 0; }
goto P_0c0acace;
P_0c0acace: /* original 52d1, guest PC 0x0c0acace */
if(!s->budget--) { s->failed_pc=0x0c0acaceu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0acad0;
P_0c0acad0: /* original e302, guest PC 0x0c0acad0 */
if(!s->budget--) { s->failed_pc=0x0c0acad0u; return 0; }
r[3]=0x00000002u;
goto P_0c0acad2;
P_0c0acad2: /* original 3236, guest PC 0x0c0acad2 */
if(!s->budget--) { s->failed_pc=0x0c0acad2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0acad4;
P_0c0acad4: /* original 8b01, guest PC 0x0c0acad4 */
if(!s->budget--) { s->failed_pc=0x0c0acad4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acada; }
goto P_0c0acad6;
P_0c0acad6: /* original a18c, guest PC 0x0c0acad6 */
if(!s->budget--) { s->failed_pc=0x0c0acad6u; return 0; }
goto P_0c0acdf2;
P_0c0acad8: /* original 0009, guest PC 0x0c0acad8 */
if(!s->budget--) { s->failed_pc=0x0c0acad8u; return 0; }
goto P_0c0acada;
P_0c0acada: /* original 9053, guest PC 0x0c0acada */
if(!s->budget--) { s->failed_pc=0x0c0acadau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb84u,2);
goto P_0c0acadc;
P_0c0acadc: /* original 0e44, guest PC 0x0c0acadc */
if(!s->budget--) { s->failed_pc=0x0c0acadcu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0acade;
P_0c0acade: /* original e06a, guest PC 0x0c0acade */
if(!s->budget--) { s->failed_pc=0x0c0acadeu; return 0; }
r[0]=0x0000006au;
goto P_0c0acae0;
P_0c0acae0: /* original 04ed, guest PC 0x0c0acae0 */
if(!s->budget--) { s->failed_pc=0x0c0acae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acae2;
P_0c0acae2: /* original 9050, guest PC 0x0c0acae2 */
if(!s->budget--) { s->failed_pc=0x0c0acae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb86u,2);
goto P_0c0acae4;
P_0c0acae4: /* original 03ee, guest PC 0x0c0acae4 */
if(!s->budget--) { s->failed_pc=0x0c0acae4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acae6;
P_0c0acae6: /* original 2398, guest PC 0x0c0acae6 */
if(!s->budget--) { s->failed_pc=0x0c0acae6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0acae8;
P_0c0acae8: /* original 8b18, guest PC 0x0c0acae8 */
if(!s->budget--) { s->failed_pc=0x0c0acae8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acaea;
P_0c0acaea: /* original e048, guest PC 0x0c0acaea */
if(!s->budget--) { s->failed_pc=0x0c0acaeau; return 0; }
r[0]=0x00000048u;
goto P_0c0acaec;
P_0c0acaec: /* original 934c, guest PC 0x0c0acaec */
if(!s->budget--) { s->failed_pc=0x0c0acaecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb88u,2);
goto P_0c0acaee;
P_0c0acaee: /* original 02ee, guest PC 0x0c0acaee */
if(!s->budget--) { s->failed_pc=0x0c0acaeeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acaf0;
P_0c0acaf0: /* original 2238, guest PC 0x0c0acaf0 */
if(!s->budget--) { s->failed_pc=0x0c0acaf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acaf2;
P_0c0acaf2: /* original 8b13, guest PC 0x0c0acaf2 */
if(!s->budget--) { s->failed_pc=0x0c0acaf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acaf4;
P_0c0acaf4: /* original 01ee, guest PC 0x0c0acaf4 */
if(!s->budget--) { s->failed_pc=0x0c0acaf4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0acaf6;
P_0c0acaf6: /* original 2918, guest PC 0x0c0acaf6 */
if(!s->budget--) { s->failed_pc=0x0c0acaf6u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[1])==0)!=0);
goto P_0c0acaf8;
P_0c0acaf8: /* original 8b10, guest PC 0x0c0acaf8 */
if(!s->budget--) { s->failed_pc=0x0c0acaf8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acafa;
P_0c0acafa: /* original e050, guest PC 0x0c0acafa */
if(!s->budget--) { s->failed_pc=0x0c0acafau; return 0; }
r[0]=0x00000050u;
goto P_0c0acafc;
P_0c0acafc: /* original d328, guest PC 0x0c0acafc */
if(!s->budget--) { s->failed_pc=0x0c0acafcu; return 0; }
r[3]=read(ram,0x0c0acba0u,4);
goto P_0c0acafe;
P_0c0acafe: /* original 02ce, guest PC 0x0c0acafe */
if(!s->budget--) { s->failed_pc=0x0c0acafeu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0acb00;
P_0c0acb00: /* original 2238, guest PC 0x0c0acb00 */
if(!s->budget--) { s->failed_pc=0x0c0acb00u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acb02;
P_0c0acb02: /* original 8b03, guest PC 0x0c0acb02 */
if(!s->budget--) { s->failed_pc=0x0c0acb02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb0c; }
goto P_0c0acb04;
P_0c0acb04: /* original 01ce, guest PC 0x0c0acb04 */
if(!s->budget--) { s->failed_pc=0x0c0acb04u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c0acb06;
P_0c0acb06: /* original d327, guest PC 0x0c0acb06 */
if(!s->budget--) { s->failed_pc=0x0c0acb06u; return 0; }
r[3]=read(ram,0x0c0acba4u,4);
goto P_0c0acb08;
P_0c0acb08: /* original 2138, guest PC 0x0c0acb08 */
if(!s->budget--) { s->failed_pc=0x0c0acb08u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0acb0a;
P_0c0acb0a: /* original 8900, guest PC 0x0c0acb0a */
if(!s->budget--) { s->failed_pc=0x0c0acb0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acb0e; }
goto P_0c0acb0c;
P_0c0acb0c: /* original 34ac, guest PC 0x0c0acb0c */
if(!s->budget--) { s->failed_pc=0x0c0acb0cu; return 0; }
r[4]+=r[10];
goto P_0c0acb0e;
P_0c0acb0e: /* original e048, guest PC 0x0c0acb0e */
if(!s->budget--) { s->failed_pc=0x0c0acb0eu; return 0; }
r[0]=0x00000048u;
goto P_0c0acb10;
P_0c0acb10: /* original d325, guest PC 0x0c0acb10 */
if(!s->budget--) { s->failed_pc=0x0c0acb10u; return 0; }
r[3]=read(ram,0x0c0acba8u,4);
goto P_0c0acb12;
P_0c0acb12: /* original 02ee, guest PC 0x0c0acb12 */
if(!s->budget--) { s->failed_pc=0x0c0acb12u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acb14;
P_0c0acb14: /* original 2239, guest PC 0x0c0acb14 */
if(!s->budget--) { s->failed_pc=0x0c0acb14u; return 0; }
r[2]&=r[3];
goto P_0c0acb16;
P_0c0acb16: /* original 0e26, guest PC 0x0c0acb16 */
if(!s->budget--) { s->failed_pc=0x0c0acb16u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0acb18;
P_0c0acb18: /* original 6043, guest PC 0x0c0acb18 */
if(!s->budget--) { s->failed_pc=0x0c0acb18u; return 0; }
r[0]=r[4];
goto P_0c0acb1a;
P_0c0acb1a: /* original 81ef, guest PC 0x0c0acb1a */
if(!s->budget--) { s->failed_pc=0x0c0acb1au; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0acb1c;
P_0c0acb1c: /* original 63d2, guest PC 0x0c0acb1c */
if(!s->budget--) { s->failed_pc=0x0c0acb1cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0acb1e;
P_0c0acb1e: /* original 633d, guest PC 0x0c0acb1e */
if(!s->budget--) { s->failed_pc=0x0c0acb1eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0acb20;
P_0c0acb20: /* original 6533, guest PC 0x0c0acb20 */
if(!s->budget--) { s->failed_pc=0x0c0acb20u; return 0; }
r[5]=r[3];
goto P_0c0acb22;
P_0c0acb22: /* original 1f32, guest PC 0x0c0acb22 */
if(!s->budget--) { s->failed_pc=0x0c0acb22u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0acb24;
P_0c0acb24: /* original b2f5, guest PC 0x0c0acb24 */
if(!s->budget--) { s->failed_pc=0x0c0acb24u; return 0; }
target=code_base|0x0c0ad112u; r[16]=code_base|0x0c0acb28u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acb28u) { target=s->pc; goto dispatch; }
goto P_0c0acb28;
P_0c0acb26: /* original 64e3, guest PC 0x0c0acb26 */
if(!s->budget--) { s->failed_pc=0x0c0acb26u; return 0; }
r[4]=r[14];
goto P_0c0acb28;
P_0c0acb28: /* original e04c, guest PC 0x0c0acb28 */
if(!s->budget--) { s->failed_pc=0x0c0acb28u; return 0; }
r[0]=0x0000004cu;
goto P_0c0acb2a;
P_0c0acb2a: /* original 932e, guest PC 0x0c0acb2a */
if(!s->budget--) { s->failed_pc=0x0c0acb2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8au,2);
goto P_0c0acb2c;
P_0c0acb2c: /* original 02ee, guest PC 0x0c0acb2c */
if(!s->budget--) { s->failed_pc=0x0c0acb2cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acb2e;
P_0c0acb2e: /* original 2238, guest PC 0x0c0acb2e */
if(!s->budget--) { s->failed_pc=0x0c0acb2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acb30;
P_0c0acb30: /* original 890f, guest PC 0x0c0acb30 */
if(!s->budget--) { s->failed_pc=0x0c0acb30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acb52; }
goto P_0c0acb32;
P_0c0acb32: /* original e06a, guest PC 0x0c0acb32 */
if(!s->budget--) { s->failed_pc=0x0c0acb32u; return 0; }
r[0]=0x0000006au;
goto P_0c0acb34;
P_0c0acb34: /* original 952a, guest PC 0x0c0acb34 */
if(!s->budget--) { s->failed_pc=0x0c0acb34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8cu,2);
goto P_0c0acb36;
P_0c0acb36: /* original 04ed, guest PC 0x0c0acb36 */
if(!s->budget--) { s->failed_pc=0x0c0acb36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acb38;
P_0c0acb38: /* original 9029, guest PC 0x0c0acb38 */
if(!s->budget--) { s->failed_pc=0x0c0acb38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8eu,2);
goto P_0c0acb3a;
P_0c0acb3a: /* original 644d, guest PC 0x0c0acb3a */
if(!s->budget--) { s->failed_pc=0x0c0acb3au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0acb3c;
P_0c0acb3c: /* original 06ed, guest PC 0x0c0acb3c */
if(!s->budget--) { s->failed_pc=0x0c0acb3cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acb3e;
P_0c0acb3e: /* original 6343, guest PC 0x0c0acb3e */
if(!s->budget--) { s->failed_pc=0x0c0acb3eu; return 0; }
r[3]=r[4];
goto P_0c0acb40;
P_0c0acb40: /* original 666d, guest PC 0x0c0acb40 */
if(!s->budget--) { s->failed_pc=0x0c0acb40u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0acb42;
P_0c0acb42: /* original 3368, guest PC 0x0c0acb42 */
if(!s->budget--) { s->failed_pc=0x0c0acb42u; return 0; }
r[3]-=r[6];
goto P_0c0acb44;
P_0c0acb44: /* original 6633, guest PC 0x0c0acb44 */
if(!s->budget--) { s->failed_pc=0x0c0acb44u; return 0; }
r[6]=r[3];
goto P_0c0acb46;
P_0c0acb46: /* original 26a8, guest PC 0x0c0acb46 */
if(!s->budget--) { s->failed_pc=0x0c0acb46u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[10])==0)!=0);
goto P_0c0acb48;
P_0c0acb48: /* original 8b00, guest PC 0x0c0acb48 */
if(!s->budget--) { s->failed_pc=0x0c0acb48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb4c; }
goto P_0c0acb4a;
P_0c0acb4a: /* original 9521, guest PC 0x0c0acb4a */
if(!s->budget--) { s->failed_pc=0x0c0acb4au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb90u,2);
goto P_0c0acb4c;
P_0c0acb4c: /* original 345c, guest PC 0x0c0acb4c */
if(!s->budget--) { s->failed_pc=0x0c0acb4cu; return 0; }
r[4]+=r[5];
goto P_0c0acb4e;
P_0c0acb4e: /* original 6043, guest PC 0x0c0acb4e */
if(!s->budget--) { s->failed_pc=0x0c0acb4eu; return 0; }
r[0]=r[4];
goto P_0c0acb50;
P_0c0acb50: /* original 81ef, guest PC 0x0c0acb50 */
if(!s->budget--) { s->failed_pc=0x0c0acb50u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0acb52;
P_0c0acb52: /* original e04c, guest PC 0x0c0acb52 */
if(!s->budget--) { s->failed_pc=0x0c0acb52u; return 0; }
r[0]=0x0000004cu;
goto P_0c0acb54;
P_0c0acb54: /* original d216, guest PC 0x0c0acb54 */
if(!s->budget--) { s->failed_pc=0x0c0acb54u; return 0; }
r[2]=read(ram,0x0c0acbb0u,4);
goto P_0c0acb56;
P_0c0acb56: /* original 05ee, guest PC 0x0c0acb56 */
if(!s->budget--) { s->failed_pc=0x0c0acb56u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0acb58;
P_0c0acb58: /* original 64e2, guest PC 0x0c0acb58 */
if(!s->budget--) { s->failed_pc=0x0c0acb58u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0acb5a;
P_0c0acb5a: /* original d314, guest PC 0x0c0acb5a */
if(!s->budget--) { s->failed_pc=0x0c0acb5au; return 0; }
r[3]=read(ram,0x0c0acbacu,4);
goto P_0c0acb5c;
P_0c0acb5c: /* original 2528, guest PC 0x0c0acb5c */
if(!s->budget--) { s->failed_pc=0x0c0acb5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0acb5e;
P_0c0acb5e: /* original 8d01, guest PC 0x0c0acb5e */
if(!s->budget--) { s->failed_pc=0x0c0acb5eu; return 0; }
cond=r[17]&1u;
r[4]|=r[3];
if(cond) { goto P_0c0acb64; }
goto P_0c0acb62;
P_0c0acb60: /* original 243b, guest PC 0x0c0acb60 */
if(!s->budget--) { s->failed_pc=0x0c0acb60u; return 0; }
r[4]|=r[3];
goto P_0c0acb62;
P_0c0acb62: /* original 24b9, guest PC 0x0c0acb62 */
if(!s->budget--) { s->failed_pc=0x0c0acb62u; return 0; }
r[4]&=r[11];
goto P_0c0acb64;
P_0c0acb64: /* original e024, guest PC 0x0c0acb64 */
if(!s->budget--) { s->failed_pc=0x0c0acb64u; return 0; }
r[0]=0x00000024u;
goto P_0c0acb66;
P_0c0acb66: /* original 2e42, guest PC 0x0c0acb66 */
if(!s->budget--) { s->failed_pc=0x0c0acb66u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0acb68;
P_0c0acb68: /* original f48d, guest PC 0x0c0acb68 */
if(!s->budget--) { s->failed_pc=0x0c0acb68u; return 0; }
fr[4]=0;
goto P_0c0acb6a;
P_0c0acb6a: /* original fe47, guest PC 0x0c0acb6a */
if(!s->budget--) { s->failed_pc=0x0c0acb6au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb6c;
P_0c0acb6c: /* original e028, guest PC 0x0c0acb6c */
if(!s->budget--) { s->failed_pc=0x0c0acb6cu; return 0; }
r[0]=0x00000028u;
goto P_0c0acb6e;
P_0c0acb6e: /* original fe47, guest PC 0x0c0acb6e */
if(!s->budget--) { s->failed_pc=0x0c0acb6eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb70;
P_0c0acb70: /* original e02c, guest PC 0x0c0acb70 */
if(!s->budget--) { s->failed_pc=0x0c0acb70u; return 0; }
r[0]=0x0000002cu;
goto P_0c0acb72;
P_0c0acb72: /* original fe47, guest PC 0x0c0acb72 */
if(!s->budget--) { s->failed_pc=0x0c0acb72u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb74;
P_0c0acb74: /* original 900d, guest PC 0x0c0acb74 */
if(!s->budget--) { s->failed_pc=0x0c0acb74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb92u,2);
goto P_0c0acb76;
P_0c0acb76: /* original fe47, guest PC 0x0c0acb76 */
if(!s->budget--) { s->failed_pc=0x0c0acb76u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb78;
P_0c0acb78: /* original 7004, guest PC 0x0c0acb78 */
if(!s->budget--) { s->failed_pc=0x0c0acb78u; return 0; }
r[0]+=0x00000004u;
goto P_0c0acb7a;
P_0c0acb7a: /* original fe47, guest PC 0x0c0acb7a */
if(!s->budget--) { s->failed_pc=0x0c0acb7au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb7c;
P_0c0acb7c: /* original 7004, guest PC 0x0c0acb7c */
if(!s->budget--) { s->failed_pc=0x0c0acb7cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0acb7e;
P_0c0acb7e: /* original a107, guest PC 0x0c0acb7e */
if(!s->budget--) { s->failed_pc=0x0c0acb7eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acd90;
P_0c0acb80: /* original fe47, guest PC 0x0c0acb80 */
if(!s->budget--) { s->failed_pc=0x0c0acb80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(0x0c0acb82u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0acb82u; return 0; } return 1;
P_0c0acbb4: /* original e03e, guest PC 0x0c0acbb4 */
if(!s->budget--) { s->failed_pc=0x0c0acbb4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acbb6;
P_0c0acbb6: /* original 02ed, guest PC 0x0c0acbb6 */
if(!s->budget--) { s->failed_pc=0x0c0acbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbb8;
P_0c0acbb8: /* original 9053, guest PC 0x0c0acbb8 */
if(!s->budget--) { s->failed_pc=0x0c0acbb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc62u,2);
goto P_0c0acbba;
P_0c0acbba: /* original 03ed, guest PC 0x0c0acbba */
if(!s->budget--) { s->failed_pc=0x0c0acbbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbbc;
P_0c0acbbc: /* original 3232, guest PC 0x0c0acbbc */
if(!s->budget--) { s->failed_pc=0x0c0acbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0acbbe;
P_0c0acbbe: /* original 8935, guest PC 0x0c0acbbe */
if(!s->budget--) { s->failed_pc=0x0c0acbbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc2c; }
goto P_0c0acbc0;
P_0c0acbc0: /* original e048, guest PC 0x0c0acbc0 */
if(!s->budget--) { s->failed_pc=0x0c0acbc0u; return 0; }
r[0]=0x00000048u;
goto P_0c0acbc2;
P_0c0acbc2: /* original d32c, guest PC 0x0c0acbc2 */
if(!s->budget--) { s->failed_pc=0x0c0acbc2u; return 0; }
r[3]=read(ram,0x0c0acc74u,4);
goto P_0c0acbc4;
P_0c0acbc4: /* original 02ee, guest PC 0x0c0acbc4 */
if(!s->budget--) { s->failed_pc=0x0c0acbc4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acbc6;
P_0c0acbc6: /* original 2238, guest PC 0x0c0acbc6 */
if(!s->budget--) { s->failed_pc=0x0c0acbc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acbc8;
P_0c0acbc8: /* original 8902, guest PC 0x0c0acbc8 */
if(!s->budget--) { s->failed_pc=0x0c0acbc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbd0; }
goto P_0c0acbca;
P_0c0acbca: /* original d32b, guest PC 0x0c0acbca */
if(!s->budget--) { s->failed_pc=0x0c0acbcau; return 0; }
r[3]=read(ram,0x0c0acc78u,4);
goto P_0c0acbcc;
P_0c0acbcc: /* original 430b, guest PC 0x0c0acbcc */
if(!s->budget--) { s->failed_pc=0x0c0acbccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0acbd0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acbd0u) { target=s->pc; goto dispatch; }
goto P_0c0acbd0;
P_0c0acbce: /* original 64e3, guest PC 0x0c0acbce */
if(!s->budget--) { s->failed_pc=0x0c0acbceu; return 0; }
r[4]=r[14];
goto P_0c0acbd0;
P_0c0acbd0: /* original e048, guest PC 0x0c0acbd0 */
if(!s->budget--) { s->failed_pc=0x0c0acbd0u; return 0; }
r[0]=0x00000048u;
goto P_0c0acbd2;
P_0c0acbd2: /* original 9347, guest PC 0x0c0acbd2 */
if(!s->budget--) { s->failed_pc=0x0c0acbd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc64u,2);
goto P_0c0acbd4;
P_0c0acbd4: /* original 02ce, guest PC 0x0c0acbd4 */
if(!s->budget--) { s->failed_pc=0x0c0acbd4u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0acbd6;
P_0c0acbd6: /* original 2238, guest PC 0x0c0acbd6 */
if(!s->budget--) { s->failed_pc=0x0c0acbd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acbd8;
P_0c0acbd8: /* original 8901, guest PC 0x0c0acbd8 */
if(!s->budget--) { s->failed_pc=0x0c0acbd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbde; }
goto P_0c0acbda;
P_0c0acbda: /* original a121, guest PC 0x0c0acbda */
if(!s->budget--) { s->failed_pc=0x0c0acbdau; return 0; }
goto P_0c0ace20;
P_0c0acbdc: /* original 0009, guest PC 0x0c0acbdc */
if(!s->budget--) { s->failed_pc=0x0c0acbdcu; return 0; }
goto P_0c0acbde;
P_0c0acbde: /* original 03ee, guest PC 0x0c0acbde */
if(!s->budget--) { s->failed_pc=0x0c0acbdeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acbe0;
P_0c0acbe0: /* original 2938, guest PC 0x0c0acbe0 */
if(!s->budget--) { s->failed_pc=0x0c0acbe0u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[3])==0)!=0);
goto P_0c0acbe2;
P_0c0acbe2: /* original 8b01, guest PC 0x0c0acbe2 */
if(!s->budget--) { s->failed_pc=0x0c0acbe2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acbe8; }
goto P_0c0acbe4;
P_0c0acbe4: /* original a11c, guest PC 0x0c0acbe4 */
if(!s->budget--) { s->failed_pc=0x0c0acbe4u; return 0; }
goto P_0c0ace20;
P_0c0acbe6: /* original 0009, guest PC 0x0c0acbe6 */
if(!s->budget--) { s->failed_pc=0x0c0acbe6u; return 0; }
goto P_0c0acbe8;
P_0c0acbe8: /* original e03e, guest PC 0x0c0acbe8 */
if(!s->budget--) { s->failed_pc=0x0c0acbe8u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acbea;
P_0c0acbea: /* original 01ed, guest PC 0x0c0acbea */
if(!s->budget--) { s->failed_pc=0x0c0acbeau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbec;
P_0c0acbec: /* original 903b, guest PC 0x0c0acbec */
if(!s->budget--) { s->failed_pc=0x0c0acbecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc66u,2);
goto P_0c0acbee;
P_0c0acbee: /* original 611d, guest PC 0x0c0acbee */
if(!s->budget--) { s->failed_pc=0x0c0acbeeu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0acbf0;
P_0c0acbf0: /* original 03ed, guest PC 0x0c0acbf0 */
if(!s->budget--) { s->failed_pc=0x0c0acbf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbf2;
P_0c0acbf2: /* original 3133, guest PC 0x0c0acbf2 */
if(!s->budget--) { s->failed_pc=0x0c0acbf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0acbf4;
P_0c0acbf4: /* original 8b01, guest PC 0x0c0acbf4 */
if(!s->budget--) { s->failed_pc=0x0c0acbf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acbfa; }
goto P_0c0acbf6;
P_0c0acbf6: /* original a113, guest PC 0x0c0acbf6 */
if(!s->budget--) { s->failed_pc=0x0c0acbf6u; return 0; }
goto P_0c0ace20;
P_0c0acbf8: /* original 0009, guest PC 0x0c0acbf8 */
if(!s->budget--) { s->failed_pc=0x0c0acbf8u; return 0; }
goto P_0c0acbfa;
P_0c0acbfa: /* original e048, guest PC 0x0c0acbfa */
if(!s->budget--) { s->failed_pc=0x0c0acbfau; return 0; }
r[0]=0x00000048u;
goto P_0c0acbfc;
P_0c0acbfc: /* original d31f, guest PC 0x0c0acbfc */
if(!s->budget--) { s->failed_pc=0x0c0acbfcu; return 0; }
r[3]=read(ram,0x0c0acc7cu,4);
goto P_0c0acbfe;
P_0c0acbfe: /* original 04ee, guest PC 0x0c0acbfe */
if(!s->budget--) { s->failed_pc=0x0c0acbfeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0acc00;
P_0c0acc00: /* original 9032, guest PC 0x0c0acc00 */
if(!s->budget--) { s->failed_pc=0x0c0acc00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc68u,2);
goto P_0c0acc02;
P_0c0acc02: /* original 65e2, guest PC 0x0c0acc02 */
if(!s->budget--) { s->failed_pc=0x0c0acc02u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0acc04;
P_0c0acc04: /* original 06ee, guest PC 0x0c0acc04 */
if(!s->budget--) { s->failed_pc=0x0c0acc04u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0acc06;
P_0c0acc06: /* original e048, guest PC 0x0c0acc06 */
if(!s->budget--) { s->failed_pc=0x0c0acc06u; return 0; }
r[0]=0x00000048u;
goto P_0c0acc08;
P_0c0acc08: /* original 1e3d, guest PC 0x0c0acc08 */
if(!s->budget--) { s->failed_pc=0x0c0acc08u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0acc0a;
P_0c0acc0a: /* original 25b9, guest PC 0x0c0acc0a */
if(!s->budget--) { s->failed_pc=0x0c0acc0au; return 0; }
r[5]&=r[11];
goto P_0c0acc0c;
P_0c0acc0c: /* original d21c, guest PC 0x0c0acc0c */
if(!s->budget--) { s->failed_pc=0x0c0acc0cu; return 0; }
r[2]=read(ram,0x0c0acc80u,4);
goto P_0c0acc0e;
P_0c0acc0e: /* original 2e52, guest PC 0x0c0acc0e */
if(!s->budget--) { s->failed_pc=0x0c0acc0eu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0acc10;
P_0c0acc10: /* original 932b, guest PC 0x0c0acc10 */
if(!s->budget--) { s->failed_pc=0x0c0acc10u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6au,2);
goto P_0c0acc12;
P_0c0acc12: /* original 2429, guest PC 0x0c0acc12 */
if(!s->budget--) { s->failed_pc=0x0c0acc12u; return 0; }
r[4]&=r[2];
goto P_0c0acc14;
P_0c0acc14: /* original 2638, guest PC 0x0c0acc14 */
if(!s->budget--) { s->failed_pc=0x0c0acc14u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0acc16;
P_0c0acc16: /* original 8f02, guest PC 0x0c0acc16 */
if(!s->budget--) { s->failed_pc=0x0c0acc16u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c0acc1e; }
goto P_0c0acc1a;
P_0c0acc18: /* original 0e46, guest PC 0x0c0acc18 */
if(!s->budget--) { s->failed_pc=0x0c0acc18u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0acc1a;
P_0c0acc1a: /* original a101, guest PC 0x0c0acc1a */
if(!s->budget--) { s->failed_pc=0x0c0acc1au; return 0; }
goto P_0c0ace20;
P_0c0acc1c: /* original 0009, guest PC 0x0c0acc1c */
if(!s->budget--) { s->failed_pc=0x0c0acc1cu; return 0; }
goto P_0c0acc1e;
P_0c0acc1e: /* original d119, guest PC 0x0c0acc1e */
if(!s->budget--) { s->failed_pc=0x0c0acc1eu; return 0; }
r[1]=read(ram,0x0c0acc84u,4);
goto P_0c0acc20;
P_0c0acc20: /* original 241b, guest PC 0x0c0acc20 */
if(!s->budget--) { s->failed_pc=0x0c0acc20u; return 0; }
r[4]|=r[1];
goto P_0c0acc22;
P_0c0acc22: /* original 0e46, guest PC 0x0c0acc22 */
if(!s->budget--) { s->failed_pc=0x0c0acc22u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0acc24;
P_0c0acc24: /* original 9023, guest PC 0x0c0acc24 */
if(!s->budget--) { s->failed_pc=0x0c0acc24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6eu,2);
goto P_0c0acc26;
P_0c0acc26: /* original 9321, guest PC 0x0c0acc26 */
if(!s->budget--) { s->failed_pc=0x0c0acc26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6cu,2);
goto P_0c0acc28;
P_0c0acc28: /* original a0fa, guest PC 0x0c0acc28 */
if(!s->budget--) { s->failed_pc=0x0c0acc28u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ace20;
P_0c0acc2a: /* original 0e35, guest PC 0x0c0acc2a */
if(!s->budget--) { s->failed_pc=0x0c0acc2au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0acc2c;
P_0c0acc2c: /* original 62e2, guest PC 0x0c0acc2c */
if(!s->budget--) { s->failed_pc=0x0c0acc2cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0acc2e;
P_0c0acc2e: /* original e062, guest PC 0x0c0acc2e */
if(!s->budget--) { s->failed_pc=0x0c0acc2eu; return 0; }
r[0]=0x00000062u;
goto P_0c0acc30;
P_0c0acc30: /* original d315, guest PC 0x0c0acc30 */
if(!s->budget--) { s->failed_pc=0x0c0acc30u; return 0; }
r[3]=read(ram,0x0c0acc88u,4);
goto P_0c0acc32;
P_0c0acc32: /* original 2239, guest PC 0x0c0acc32 */
if(!s->budget--) { s->failed_pc=0x0c0acc32u; return 0; }
r[2]&=r[3];
goto P_0c0acc34;
P_0c0acc34: /* original 2e22, guest PC 0x0c0acc34 */
if(!s->budget--) { s->failed_pc=0x0c0acc34u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0acc36;
P_0c0acc36: /* original 51d1, guest PC 0x0c0acc36 */
if(!s->budget--) { s->failed_pc=0x0c0acc36u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0acc38;
P_0c0acc38: /* original 7101, guest PC 0x0c0acc38 */
if(!s->budget--) { s->failed_pc=0x0c0acc38u; return 0; }
r[1]+=0x00000001u;
goto P_0c0acc3a;
P_0c0acc3a: /* original 6213, guest PC 0x0c0acc3a */
if(!s->budget--) { s->failed_pc=0x0c0acc3au; return 0; }
r[2]=r[1];
goto P_0c0acc3c;
P_0c0acc3c: /* original 1d11, guest PC 0x0c0acc3c */
if(!s->budget--) { s->failed_pc=0x0c0acc3cu; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0acc3e;
P_0c0acc3e: /* original 0e24, guest PC 0x0c0acc3e */
if(!s->budget--) { s->failed_pc=0x0c0acc3eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0acc40;
P_0c0acc40: /* original 9016, guest PC 0x0c0acc40 */
if(!s->budget--) { s->failed_pc=0x0c0acc40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc70u,2);
goto P_0c0acc42;
P_0c0acc42: /* original d512, guest PC 0x0c0acc42 */
if(!s->budget--) { s->failed_pc=0x0c0acc42u; return 0; }
r[5]=read(ram,0x0c0acc8cu,4);
goto P_0c0acc44;
P_0c0acc44: /* original 03ee, guest PC 0x0c0acc44 */
if(!s->budget--) { s->failed_pc=0x0c0acc44u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acc46;
P_0c0acc46: /* original 2538, guest PC 0x0c0acc46 */
if(!s->budget--) { s->failed_pc=0x0c0acc46u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0acc48;
P_0c0acc48: /* original 8901, guest PC 0x0c0acc48 */
if(!s->budget--) { s->failed_pc=0x0c0acc48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc4e; }
goto P_0c0acc4a;
P_0c0acc4a: /* original 9012, guest PC 0x0c0acc4a */
if(!s->budget--) { s->failed_pc=0x0c0acc4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc72u,2);
goto P_0c0acc4c;
P_0c0acc4c: /* original 0e44, guest PC 0x0c0acc4c */
if(!s->budget--) { s->failed_pc=0x0c0acc4cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0acc4e;
P_0c0acc4e: /* original 62e2, guest PC 0x0c0acc4e */
if(!s->budget--) { s->failed_pc=0x0c0acc4eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0acc50;
P_0c0acc50: /* original d30f, guest PC 0x0c0acc50 */
if(!s->budget--) { s->failed_pc=0x0c0acc50u; return 0; }
r[3]=read(ram,0x0c0acc90u,4);
goto P_0c0acc52;
P_0c0acc52: /* original 2238, guest PC 0x0c0acc52 */
if(!s->budget--) { s->failed_pc=0x0c0acc52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acc54;
P_0c0acc54: /* original 891e, guest PC 0x0c0acc54 */
if(!s->budget--) { s->failed_pc=0x0c0acc54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc94; }
goto P_0c0acc56;
P_0c0acc56: /* original 9004, guest PC 0x0c0acc56 */
if(!s->budget--) { s->failed_pc=0x0c0acc56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc62u,2);
goto P_0c0acc58;
P_0c0acc58: /* original 01ed, guest PC 0x0c0acc58 */
if(!s->budget--) { s->failed_pc=0x0c0acc58u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acc5a;
P_0c0acc5a: /* original e03e, guest PC 0x0c0acc5a */
if(!s->budget--) { s->failed_pc=0x0c0acc5au; return 0; }
r[0]=0x0000003eu;
goto P_0c0acc5c;
P_0c0acc5c: /* original 0e15, guest PC 0x0c0acc5c */
if(!s->budget--) { s->failed_pc=0x0c0acc5cu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0acc5e;
P_0c0acc5e: /* original a0df, guest PC 0x0c0acc5e */
if(!s->budget--) { s->failed_pc=0x0c0acc5eu; return 0; }
goto P_0c0ace20;
P_0c0acc60: /* original 0009, guest PC 0x0c0acc60 */
if(!s->budget--) { s->failed_pc=0x0c0acc60u; return 0; }
if(!vf3_matrix_family(0x0c0acc62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0acc62u; return 0; } return 1;
P_0c0acc94: /* original e03c, guest PC 0x0c0acc94 */
if(!s->budget--) { s->failed_pc=0x0c0acc94u; return 0; }
r[0]=0x0000003cu;
goto P_0c0acc96;
P_0c0acc96: /* original 9282, guest PC 0x0c0acc96 */
if(!s->budget--) { s->failed_pc=0x0c0acc96u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acd9eu,2);
goto P_0c0acc98;
P_0c0acc98: /* original 03ed, guest PC 0x0c0acc98 */
if(!s->budget--) { s->failed_pc=0x0c0acc98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acc9a;
P_0c0acc9a: /* original 633d, guest PC 0x0c0acc9a */
if(!s->budget--) { s->failed_pc=0x0c0acc9au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0acc9c;
P_0c0acc9c: /* original 3320, guest PC 0x0c0acc9c */
if(!s->budget--) { s->failed_pc=0x0c0acc9cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0acc9e;
P_0c0acc9e: /* original 8b0d, guest PC 0x0c0acc9e */
if(!s->budget--) { s->failed_pc=0x0c0acc9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0accbc; }
goto P_0c0acca0;
P_0c0acca0: /* original 907e, guest PC 0x0c0acca0 */
if(!s->budget--) { s->failed_pc=0x0c0acca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda0u,2);
goto P_0c0acca2;
P_0c0acca2: /* original 64f3, guest PC 0x0c0acca2 */
if(!s->budget--) { s->failed_pc=0x0c0acca2u; return 0; }
r[4]=r[15];
goto P_0c0acca4;
P_0c0acca4: /* original d342, guest PC 0x0c0acca4 */
if(!s->budget--) { s->failed_pc=0x0c0acca4u; return 0; }
r[3]=read(ram,0x0c0acdb0u,4);
goto P_0c0acca6;
P_0c0acca6: /* original 740c, guest PC 0x0c0acca6 */
if(!s->budget--) { s->failed_pc=0x0c0acca6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0acca8;
P_0c0acca8: /* original f5e6, guest PC 0x0c0acca8 */
if(!s->budget--) { s->failed_pc=0x0c0acca8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0accaa;
P_0c0accaa: /* original 70f8, guest PC 0x0c0accaa */
if(!s->budget--) { s->failed_pc=0x0c0accaau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0accac;
P_0c0accac: /* original 430b, guest PC 0x0c0accac */
if(!s->budget--) { s->failed_pc=0x0c0accacu; return 0; }
target=r[3];
r[16]=code_base|0x0c0accb0u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0accb0u) { target=s->pc; goto dispatch; }
goto P_0c0accb0;
P_0c0accae: /* original f4e6, guest PC 0x0c0accae */
if(!s->budget--) { s->failed_pc=0x0c0accaeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0accb0;
P_0c0accb0: /* original e204, guest PC 0x0c0accb0 */
if(!s->budget--) { s->failed_pc=0x0c0accb0u; return 0; }
r[2]=0x00000004u;
goto P_0c0accb2;
P_0c0accb2: /* original 6403, guest PC 0x0c0accb2 */
if(!s->budget--) { s->failed_pc=0x0c0accb2u; return 0; }
r[4]=r[0];
goto P_0c0accb4;
P_0c0accb4: /* original 2428, guest PC 0x0c0accb4 */
if(!s->budget--) { s->failed_pc=0x0c0accb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0accb6;
P_0c0accb6: /* original 8b01, guest PC 0x0c0accb6 */
if(!s->budget--) { s->failed_pc=0x0c0accb6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0accbc; }
goto P_0c0accb8;
P_0c0accb8: /* original a095, guest PC 0x0c0accb8 */
if(!s->budget--) { s->failed_pc=0x0c0accb8u; return 0; }
goto P_0c0acde6;
P_0c0accba: /* original 0009, guest PC 0x0c0accba */
if(!s->budget--) { s->failed_pc=0x0c0accbau; return 0; }
goto P_0c0accbc;
P_0c0accbc: /* original e048, guest PC 0x0c0accbc */
if(!s->budget--) { s->failed_pc=0x0c0accbcu; return 0; }
r[0]=0x00000048u;
goto P_0c0accbe;
P_0c0accbe: /* original d53d, guest PC 0x0c0accbe */
if(!s->budget--) { s->failed_pc=0x0c0accbeu; return 0; }
r[5]=read(ram,0x0c0acdb4u,4);
goto P_0c0accc0;
P_0c0accc0: /* original 04ee, guest PC 0x0c0accc0 */
if(!s->budget--) { s->failed_pc=0x0c0accc0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0accc2;
P_0c0accc2: /* original 906e, guest PC 0x0c0accc2 */
if(!s->budget--) { s->failed_pc=0x0c0accc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda2u,2);
goto P_0c0accc4;
P_0c0accc4: /* original 03ee, guest PC 0x0c0accc4 */
if(!s->budget--) { s->failed_pc=0x0c0accc4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0accc6;
P_0c0accc6: /* original 2358, guest PC 0x0c0accc6 */
if(!s->budget--) { s->failed_pc=0x0c0accc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0accc8;
P_0c0accc8: /* original 8d01, guest PC 0x0c0accc8 */
if(!s->budget--) { s->failed_pc=0x0c0accc8u; return 0; }
cond=r[17]&1u;
r[4]&=r[11];
if(cond) { goto P_0c0accce; }
goto P_0c0acccc;
P_0c0accca: /* original 24b9, guest PC 0x0c0accca */
if(!s->budget--) { s->failed_pc=0x0c0acccau; return 0; }
r[4]&=r[11];
goto P_0c0acccc;
P_0c0acccc: /* original 245b, guest PC 0x0c0acccc */
if(!s->budget--) { s->failed_pc=0x0c0accccu; return 0; }
r[4]|=r[5];
goto P_0c0accce;
P_0c0accce: /* original e048, guest PC 0x0c0accce */
if(!s->budget--) { s->failed_pc=0x0c0accceu; return 0; }
r[0]=0x00000048u;
goto P_0c0accd0;
P_0c0accd0: /* original 0e46, guest PC 0x0c0accd0 */
if(!s->budget--) { s->failed_pc=0x0c0accd0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0accd2;
P_0c0accd2: /* original e04c, guest PC 0x0c0accd2 */
if(!s->budget--) { s->failed_pc=0x0c0accd2u; return 0; }
r[0]=0x0000004cu;
goto P_0c0accd4;
P_0c0accd4: /* original 02ee, guest PC 0x0c0accd4 */
if(!s->budget--) { s->failed_pc=0x0c0accd4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0accd6;
P_0c0accd6: /* original d338, guest PC 0x0c0accd6 */
if(!s->budget--) { s->failed_pc=0x0c0accd6u; return 0; }
r[3]=read(ram,0x0c0acdb8u,4);
goto P_0c0accd8;
P_0c0accd8: /* original 2238, guest PC 0x0c0accd8 */
if(!s->budget--) { s->failed_pc=0x0c0accd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0accda;
P_0c0accda: /* original 8901, guest PC 0x0c0accda */
if(!s->budget--) { s->failed_pc=0x0c0accdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acce0; }
goto P_0c0accdc;
P_0c0accdc: /* original a083, guest PC 0x0c0accdc */
if(!s->budget--) { s->failed_pc=0x0c0accdcu; return 0; }
goto P_0c0acde6;
P_0c0accde: /* original 0009, guest PC 0x0c0accde */
if(!s->budget--) { s->failed_pc=0x0c0accdeu; return 0; }
goto P_0c0acce0;
P_0c0acce0: /* original 9060, guest PC 0x0c0acce0 */
if(!s->budget--) { s->failed_pc=0x0c0acce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda4u,2);
goto P_0c0acce2;
P_0c0acce2: /* original 2459, guest PC 0x0c0acce2 */
if(!s->budget--) { s->failed_pc=0x0c0acce2u; return 0; }
r[4]&=r[5];
goto P_0c0acce4;
P_0c0acce4: /* original 6343, guest PC 0x0c0acce4 */
if(!s->budget--) { s->failed_pc=0x0c0acce4u; return 0; }
r[3]=r[4];
goto P_0c0acce6;
P_0c0acce6: /* original 2338, guest PC 0x0c0acce6 */
if(!s->budget--) { s->failed_pc=0x0c0acce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0acce8;
P_0c0acce8: /* original 09ec, guest PC 0x0c0acce8 */
if(!s->budget--) { s->failed_pc=0x0c0acce8u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0accea;
P_0c0accea: /* original e800, guest PC 0x0c0accea */
if(!s->budget--) { s->failed_pc=0x0c0acceau; return 0; }
r[8]=0x00000000u;
goto P_0c0accec;
P_0c0accec: /* original 699c, guest PC 0x0c0accec */
if(!s->budget--) { s->failed_pc=0x0c0accecu; return 0; }
r[9]=r[9]&255u;
goto P_0c0accee;
P_0c0accee: /* original 8d0a, guest PC 0x0c0accee */
if(!s->budget--) { s->failed_pc=0x0c0acceeu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c0acd06; }
goto P_0c0accf2;
P_0c0accf0: /* original 1f41, guest PC 0x0c0accf0 */
if(!s->budget--) { s->failed_pc=0x0c0accf0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0accf2;
P_0c0accf2: /* original 9058, guest PC 0x0c0accf2 */
if(!s->budget--) { s->failed_pc=0x0c0accf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda6u,2);
goto P_0c0accf4;
P_0c0accf4: /* original 04ed, guest PC 0x0c0accf4 */
if(!s->budget--) { s->failed_pc=0x0c0accf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0accf6;
P_0c0accf6: /* original e066, guest PC 0x0c0accf6 */
if(!s->budget--) { s->failed_pc=0x0c0accf6u; return 0; }
r[0]=0x00000066u;
goto P_0c0accf8;
P_0c0accf8: /* original 349c, guest PC 0x0c0accf8 */
if(!s->budget--) { s->failed_pc=0x0c0accf8u; return 0; }
r[4]+=r[9];
goto P_0c0accfa;
P_0c0accfa: /* original 6543, guest PC 0x0c0accfa */
if(!s->budget--) { s->failed_pc=0x0c0accfau; return 0; }
r[5]=r[4];
goto P_0c0accfc;
P_0c0accfc: /* original 4521, guest PC 0x0c0accfc */
if(!s->budget--) { s->failed_pc=0x0c0accfcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0accfe;
P_0c0accfe: /* original 4521, guest PC 0x0c0accfe */
if(!s->budget--) { s->failed_pc=0x0c0accfeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0acd00;
P_0c0acd00: /* original 3458, guest PC 0x0c0acd00 */
if(!s->budget--) { s->failed_pc=0x0c0acd00u; return 0; }
r[4]-=r[5];
goto P_0c0acd02;
P_0c0acd02: /* original a002, guest PC 0x0c0acd02 */
if(!s->budget--) { s->failed_pc=0x0c0acd02u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0acd0a;
P_0c0acd04: /* original 0e45, guest PC 0x0c0acd04 */
if(!s->budget--) { s->failed_pc=0x0c0acd04u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0acd06;
P_0c0acd06: /* original e066, guest PC 0x0c0acd06 */
if(!s->budget--) { s->failed_pc=0x0c0acd06u; return 0; }
r[0]=0x00000066u;
goto P_0c0acd08;
P_0c0acd08: /* original 0e85, guest PC 0x0c0acd08 */
if(!s->budget--) { s->failed_pc=0x0c0acd08u; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0acd0a;
P_0c0acd0a: /* original 904c, guest PC 0x0c0acd0a */
if(!s->budget--) { s->failed_pc=0x0c0acd0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda6u,2);
goto P_0c0acd0c;
P_0c0acd0c: /* original 2998, guest PC 0x0c0acd0c */
if(!s->budget--) { s->failed_pc=0x0c0acd0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0acd0e;
P_0c0acd0e: /* original 0e85, guest PC 0x0c0acd0e */
if(!s->budget--) { s->failed_pc=0x0c0acd0eu; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0acd10;
P_0c0acd10: /* original 904a, guest PC 0x0c0acd10 */
if(!s->budget--) { s->failed_pc=0x0c0acd10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda8u,2);
goto P_0c0acd12;
P_0c0acd12: /* original 03ec, guest PC 0x0c0acd12 */
if(!s->budget--) { s->failed_pc=0x0c0acd12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0acd14;
P_0c0acd14: /* original 623c, guest PC 0x0c0acd14 */
if(!s->budget--) { s->failed_pc=0x0c0acd14u; return 0; }
r[2]=r[3]&255u;
goto P_0c0acd16;
P_0c0acd16: /* original 7201, guest PC 0x0c0acd16 */
if(!s->budget--) { s->failed_pc=0x0c0acd16u; return 0; }
r[2]+=0x00000001u;
goto P_0c0acd18;
P_0c0acd18: /* original 2f22, guest PC 0x0c0acd18 */
if(!s->budget--) { s->failed_pc=0x0c0acd18u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0acd1a;
P_0c0acd1a: /* original 6323, guest PC 0x0c0acd1a */
if(!s->budget--) { s->failed_pc=0x0c0acd1au; return 0; }
r[3]=r[2];
goto P_0c0acd1c;
P_0c0acd1c: /* original 9044, guest PC 0x0c0acd1c */
if(!s->budget--) { s->failed_pc=0x0c0acd1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda8u,2);
goto P_0c0acd1e;
P_0c0acd1e: /* original 8f0b, guest PC 0x0c0acd1e */
if(!s->budget--) { s->failed_pc=0x0c0acd1eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[3],1);
if(!cond) { goto P_0c0acd38; }
goto P_0c0acd22;
P_0c0acd20: /* original 0e34, guest PC 0x0c0acd20 */
if(!s->budget--) { s->failed_pc=0x0c0acd20u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0acd22;
P_0c0acd22: /* original d326, guest PC 0x0c0acd22 */
if(!s->budget--) { s->failed_pc=0x0c0acd22u; return 0; }
r[3]=read(ram,0x0c0acdbcu,4);
goto P_0c0acd24;
P_0c0acd24: /* original 65c3, guest PC 0x0c0acd24 */
if(!s->budget--) { s->failed_pc=0x0c0acd24u; return 0; }
r[5]=r[12];
goto P_0c0acd26;
P_0c0acd26: /* original 67f2, guest PC 0x0c0acd26 */
if(!s->budget--) { s->failed_pc=0x0c0acd26u; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c0acd28;
P_0c0acd28: /* original 6693, guest PC 0x0c0acd28 */
if(!s->budget--) { s->failed_pc=0x0c0acd28u; return 0; }
r[6]=r[9];
goto P_0c0acd2a;
P_0c0acd2a: /* original 430b, guest PC 0x0c0acd2a */
if(!s->budget--) { s->failed_pc=0x0c0acd2au; return 0; }
target=r[3];
r[16]=code_base|0x0c0acd2eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acd2eu) { target=s->pc; goto dispatch; }
goto P_0c0acd2e;
P_0c0acd2c: /* original 64e3, guest PC 0x0c0acd2c */
if(!s->budget--) { s->failed_pc=0x0c0acd2cu; return 0; }
r[4]=r[14];
goto P_0c0acd2e;
P_0c0acd2e: /* original 52f1, guest PC 0x0c0acd2e */
if(!s->budget--) { s->failed_pc=0x0c0acd2eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0acd30;
P_0c0acd30: /* original 2228, guest PC 0x0c0acd30 */
if(!s->budget--) { s->failed_pc=0x0c0acd30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0acd32;
P_0c0acd32: /* original 8b10, guest PC 0x0c0acd32 */
if(!s->budget--) { s->failed_pc=0x0c0acd32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd56; }
goto P_0c0acd34;
P_0c0acd34: /* original a01d, guest PC 0x0c0acd34 */
if(!s->budget--) { s->failed_pc=0x0c0acd34u; return 0; }
goto P_0c0acd72;
P_0c0acd36: /* original 0009, guest PC 0x0c0acd36 */
if(!s->budget--) { s->failed_pc=0x0c0acd36u; return 0; }
goto P_0c0acd38;
P_0c0acd38: /* original 53f2, guest PC 0x0c0acd38 */
if(!s->budget--) { s->failed_pc=0x0c0acd38u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0acd3a;
P_0c0acd3a: /* original 5235, guest PC 0x0c0acd3a */
if(!s->budget--) { s->failed_pc=0x0c0acd3au; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c0acd3c;
P_0c0acd3c: /* original 4215, guest PC 0x0c0acd3c */
if(!s->budget--) { s->failed_pc=0x0c0acd3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0acd3e;
P_0c0acd3e: /* original 8b0a, guest PC 0x0c0acd3e */
if(!s->budget--) { s->failed_pc=0x0c0acd3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd56; }
goto P_0c0acd40;
P_0c0acd40: /* original d31f, guest PC 0x0c0acd40 */
if(!s->budget--) { s->failed_pc=0x0c0acd40u; return 0; }
r[3]=read(ram,0x0c0acdc0u,4);
goto P_0c0acd42;
P_0c0acd42: /* original 65c3, guest PC 0x0c0acd42 */
if(!s->budget--) { s->failed_pc=0x0c0acd42u; return 0; }
r[5]=r[12];
goto P_0c0acd44;
P_0c0acd44: /* original 6693, guest PC 0x0c0acd44 */
if(!s->budget--) { s->failed_pc=0x0c0acd44u; return 0; }
r[6]=r[9];
goto P_0c0acd46;
P_0c0acd46: /* original 430b, guest PC 0x0c0acd46 */
if(!s->budget--) { s->failed_pc=0x0c0acd46u; return 0; }
target=r[3];
r[16]=code_base|0x0c0acd4au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acd4au) { target=s->pc; goto dispatch; }
goto P_0c0acd4a;
P_0c0acd48: /* original 64e3, guest PC 0x0c0acd48 */
if(!s->budget--) { s->failed_pc=0x0c0acd48u; return 0; }
r[4]=r[14];
goto P_0c0acd4a;
P_0c0acd4a: /* original d31c, guest PC 0x0c0acd4a */
if(!s->budget--) { s->failed_pc=0x0c0acd4au; return 0; }
r[3]=read(ram,0x0c0acdbcu,4);
goto P_0c0acd4c;
P_0c0acd4c: /* original 65c3, guest PC 0x0c0acd4c */
if(!s->budget--) { s->failed_pc=0x0c0acd4cu; return 0; }
r[5]=r[12];
goto P_0c0acd4e;
P_0c0acd4e: /* original 67f2, guest PC 0x0c0acd4e */
if(!s->budget--) { s->failed_pc=0x0c0acd4eu; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c0acd50;
P_0c0acd50: /* original 6693, guest PC 0x0c0acd50 */
if(!s->budget--) { s->failed_pc=0x0c0acd50u; return 0; }
r[6]=r[9];
goto P_0c0acd52;
P_0c0acd52: /* original 430b, guest PC 0x0c0acd52 */
if(!s->budget--) { s->failed_pc=0x0c0acd52u; return 0; }
target=r[3];
r[16]=code_base|0x0c0acd56u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acd56u) { target=s->pc; goto dispatch; }
goto P_0c0acd56;
P_0c0acd54: /* original 64e3, guest PC 0x0c0acd54 */
if(!s->budget--) { s->failed_pc=0x0c0acd54u; return 0; }
r[4]=r[14];
goto P_0c0acd56;
P_0c0acd56: /* original c71c, guest PC 0x0c0acd56 */
if(!s->budget--) { s->failed_pc=0x0c0acd56u; return 0; }
r[0]=code_base|0x000acdc8u;
goto P_0c0acd58;
P_0c0acd58: /* original d21a, guest PC 0x0c0acd58 */
if(!s->budget--) { s->failed_pc=0x0c0acd58u; return 0; }
r[2]=read(ram,0x0c0acdc4u,4);
goto P_0c0acd5a;
P_0c0acd5a: /* original f308, guest PC 0x0c0acd5a */
if(!s->budget--) { s->failed_pc=0x0c0acd5au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0acd5c;
P_0c0acd5c: /* original 9025, guest PC 0x0c0acd5c */
if(!s->budget--) { s->failed_pc=0x0c0acd5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acdaau,2);
goto P_0c0acd5e;
P_0c0acd5e: /* original 6422, guest PC 0x0c0acd5e */
if(!s->budget--) { s->failed_pc=0x0c0acd5eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0acd60;
P_0c0acd60: /* original f437, guest PC 0x0c0acd60 */
if(!s->budget--) { s->failed_pc=0x0c0acd60u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0acd62;
P_0c0acd62: /* original 53f1, guest PC 0x0c0acd62 */
if(!s->budget--) { s->failed_pc=0x0c0acd62u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0acd64;
P_0c0acd64: /* original 2338, guest PC 0x0c0acd64 */
if(!s->budget--) { s->failed_pc=0x0c0acd64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0acd66;
P_0c0acd66: /* original 8b3e, guest PC 0x0c0acd66 */
if(!s->budget--) { s->failed_pc=0x0c0acd66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acde6; }
goto P_0c0acd68;
P_0c0acd68: /* original e046, guest PC 0x0c0acd68 */
if(!s->budget--) { s->failed_pc=0x0c0acd68u; return 0; }
r[0]=0x00000046u;
goto P_0c0acd6a;
P_0c0acd6a: /* original 02ed, guest PC 0x0c0acd6a */
if(!s->budget--) { s->failed_pc=0x0c0acd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acd6c;
P_0c0acd6c: /* original 622d, guest PC 0x0c0acd6c */
if(!s->budget--) { s->failed_pc=0x0c0acd6cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0acd6e;
P_0c0acd6e: /* original 4215, guest PC 0x0c0acd6e */
if(!s->budget--) { s->failed_pc=0x0c0acd6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0acd70;
P_0c0acd70: /* original 8b04, guest PC 0x0c0acd70 */
if(!s->budget--) { s->failed_pc=0x0c0acd70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd7c; }
goto P_0c0acd72;
P_0c0acd72: /* original 63e2, guest PC 0x0c0acd72 */
if(!s->budget--) { s->failed_pc=0x0c0acd72u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0acd74;
P_0c0acd74: /* original 23b9, guest PC 0x0c0acd74 */
if(!s->budget--) { s->failed_pc=0x0c0acd74u; return 0; }
r[3]&=r[11];
goto P_0c0acd76;
P_0c0acd76: /* original 2e32, guest PC 0x0c0acd76 */
if(!s->budget--) { s->failed_pc=0x0c0acd76u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0acd78;
P_0c0acd78: /* original a052, guest PC 0x0c0acd78 */
if(!s->budget--) { s->failed_pc=0x0c0acd78u; return 0; }
write(ram,r[14]+56,r[8],4);
goto P_0c0ace20;
P_0c0acd7a: /* original 1e8e, guest PC 0x0c0acd7a */
if(!s->budget--) { s->failed_pc=0x0c0acd7au; return 0; }
write(ram,r[14]+56,r[8],4);
goto P_0c0acd7c;
P_0c0acd7c: /* original d213, guest PC 0x0c0acd7c */
if(!s->budget--) { s->failed_pc=0x0c0acd7cu; return 0; }
r[2]=read(ram,0x0c0acdccu,4);
goto P_0c0acd7e;
P_0c0acd7e: /* original e503, guest PC 0x0c0acd7e */
if(!s->budget--) { s->failed_pc=0x0c0acd7eu; return 0; }
r[5]=0x00000003u;
goto P_0c0acd80;
P_0c0acd80: /* original 420b, guest PC 0x0c0acd80 */
if(!s->budget--) { s->failed_pc=0x0c0acd80u; return 0; }
target=r[2];
r[16]=code_base|0x0c0acd84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0acd84u) { target=s->pc; goto dispatch; }
goto P_0c0acd84;
P_0c0acd82: /* original 64e3, guest PC 0x0c0acd82 */
if(!s->budget--) { s->failed_pc=0x0c0acd82u; return 0; }
r[4]=r[14];
goto P_0c0acd84;
P_0c0acd84: /* original 6403, guest PC 0x0c0acd84 */
if(!s->budget--) { s->failed_pc=0x0c0acd84u; return 0; }
r[4]=r[0];
goto P_0c0acd86;
P_0c0acd86: /* original 2448, guest PC 0x0c0acd86 */
if(!s->budget--) { s->failed_pc=0x0c0acd86u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0acd88;
P_0c0acd88: /* original 8922, guest PC 0x0c0acd88 */
if(!s->budget--) { s->failed_pc=0x0c0acd88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acdd0; }
goto P_0c0acd8a;
P_0c0acd8a: /* original 900f, guest PC 0x0c0acd8a */
if(!s->budget--) { s->failed_pc=0x0c0acd8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acdacu,2);
goto P_0c0acd8c;
P_0c0acd8c: /* original e303, guest PC 0x0c0acd8c */
if(!s->budget--) { s->failed_pc=0x0c0acd8cu; return 0; }
r[3]=0x00000003u;
goto P_0c0acd8e;
P_0c0acd8e: /* original 0e34, guest PC 0x0c0acd8e */
if(!s->budget--) { s->failed_pc=0x0c0acd8eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0acd90;
P_0c0acd90: /* original 52d1, guest PC 0x0c0acd90 */
if(!s->budget--) { s->failed_pc=0x0c0acd90u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0acd92;
P_0c0acd92: /* original e062, guest PC 0x0c0acd92 */
if(!s->budget--) { s->failed_pc=0x0c0acd92u; return 0; }
r[0]=0x00000062u;
goto P_0c0acd94;
P_0c0acd94: /* original 7201, guest PC 0x0c0acd94 */
if(!s->budget--) { s->failed_pc=0x0c0acd94u; return 0; }
r[2]+=0x00000001u;
goto P_0c0acd96;
P_0c0acd96: /* original 6323, guest PC 0x0c0acd96 */
if(!s->budget--) { s->failed_pc=0x0c0acd96u; return 0; }
r[3]=r[2];
goto P_0c0acd98;
P_0c0acd98: /* original 1d21, guest PC 0x0c0acd98 */
if(!s->budget--) { s->failed_pc=0x0c0acd98u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0acd9a;
P_0c0acd9a: /* original a041, guest PC 0x0c0acd9a */
if(!s->budget--) { s->failed_pc=0x0c0acd9au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ace20;
P_0c0acd9c: /* original 0e34, guest PC 0x0c0acd9c */
if(!s->budget--) { s->failed_pc=0x0c0acd9cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0acd9eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0acd9eu; return 0; } return 1;
P_0c0acdd0: /* original e061, guest PC 0x0c0acdd0 */
if(!s->budget--) { s->failed_pc=0x0c0acdd0u; return 0; }
r[0]=0x00000061u;
goto P_0c0acdd2;
P_0c0acdd2: /* original 00ec, guest PC 0x0c0acdd2 */
if(!s->budget--) { s->failed_pc=0x0c0acdd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0acdd4;
P_0c0acdd4: /* original 600c, guest PC 0x0c0acdd4 */
if(!s->budget--) { s->failed_pc=0x0c0acdd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0acdd6;
P_0c0acdd6: /* original 880c, guest PC 0x0c0acdd6 */
if(!s->budget--) { s->failed_pc=0x0c0acdd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0acdd8;
P_0c0acdd8: /* original 8902, guest PC 0x0c0acdd8 */
if(!s->budget--) { s->failed_pc=0x0c0acdd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acde0; }
goto P_0c0acdda;
P_0c0acdda: /* original d344, guest PC 0x0c0acdda */
if(!s->budget--) { s->failed_pc=0x0c0acddau; return 0; }
r[3]=read(ram,0x0c0aceecu,4);
goto P_0c0acddc;
P_0c0acddc: /* original a020, guest PC 0x0c0acddc */
if(!s->budget--) { s->failed_pc=0x0c0acddcu; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ace20;
P_0c0acdde: /* original 1e3d, guest PC 0x0c0acdde */
if(!s->budget--) { s->failed_pc=0x0c0acddeu; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0acde0;
P_0c0acde0: /* original d243, guest PC 0x0c0acde0 */
if(!s->budget--) { s->failed_pc=0x0c0acde0u; return 0; }
r[2]=read(ram,0x0c0acef0u,4);
goto P_0c0acde2;
P_0c0acde2: /* original a01d, guest PC 0x0c0acde2 */
if(!s->budget--) { s->failed_pc=0x0c0acde2u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0ace20;
P_0c0acde4: /* original 1e2d, guest PC 0x0c0acde4 */
if(!s->budget--) { s->failed_pc=0x0c0acde4u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0acde6;
P_0c0acde6: /* original 53d1, guest PC 0x0c0acde6 */
if(!s->budget--) { s->failed_pc=0x0c0acde6u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0acde8;
P_0c0acde8: /* original e062, guest PC 0x0c0acde8 */
if(!s->budget--) { s->failed_pc=0x0c0acde8u; return 0; }
r[0]=0x00000062u;
goto P_0c0acdea;
P_0c0acdea: /* original 7301, guest PC 0x0c0acdea */
if(!s->budget--) { s->failed_pc=0x0c0acdeau; return 0; }
r[3]+=0x00000001u;
goto P_0c0acdec;
P_0c0acdec: /* original 6233, guest PC 0x0c0acdec */
if(!s->budget--) { s->failed_pc=0x0c0acdecu; return 0; }
r[2]=r[3];
goto P_0c0acdee;
P_0c0acdee: /* original 1d31, guest PC 0x0c0acdee */
if(!s->budget--) { s->failed_pc=0x0c0acdeeu; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0acdf0;
P_0c0acdf0: /* original 0e24, guest PC 0x0c0acdf0 */
if(!s->budget--) { s->failed_pc=0x0c0acdf0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0acdf2;
P_0c0acdf2: /* original e03e, guest PC 0x0c0acdf2 */
if(!s->budget--) { s->failed_pc=0x0c0acdf2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acdf4;
P_0c0acdf4: /* original 03ed, guest PC 0x0c0acdf4 */
if(!s->budget--) { s->failed_pc=0x0c0acdf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acdf6;
P_0c0acdf6: /* original 9070, guest PC 0x0c0acdf6 */
if(!s->budget--) { s->failed_pc=0x0c0acdf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedau,2);
goto P_0c0acdf8;
P_0c0acdf8: /* original 02ed, guest PC 0x0c0acdf8 */
if(!s->budget--) { s->failed_pc=0x0c0acdf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acdfa;
P_0c0acdfa: /* original 3322, guest PC 0x0c0acdfa */
if(!s->budget--) { s->failed_pc=0x0c0acdfau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0acdfc;
P_0c0acdfc: /* original 8b10, guest PC 0x0c0acdfc */
if(!s->budget--) { s->failed_pc=0x0c0acdfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ace20; }
goto P_0c0acdfe;
P_0c0acdfe: /* original 62e2, guest PC 0x0c0acdfe */
if(!s->budget--) { s->failed_pc=0x0c0acdfeu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ace00;
P_0c0ace00: /* original 2a28, guest PC 0x0c0ace00 */
if(!s->budget--) { s->failed_pc=0x0c0ace00u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0ace02;
P_0c0ace02: /* original 8b02, guest PC 0x0c0ace02 */
if(!s->budget--) { s->failed_pc=0x0c0ace02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ace0a; }
goto P_0c0ace04;
P_0c0ace04: /* original d43b, guest PC 0x0c0ace04 */
if(!s->budget--) { s->failed_pc=0x0c0ace04u; return 0; }
r[4]=read(ram,0x0c0acef4u,4);
goto P_0c0ace06;
P_0c0ace06: /* original a00a, guest PC 0x0c0ace06 */
if(!s->budget--) { s->failed_pc=0x0c0ace06u; return 0; }
goto P_0c0ace1e;
P_0c0ace08: /* original 0009, guest PC 0x0c0ace08 */
if(!s->budget--) { s->failed_pc=0x0c0ace08u; return 0; }
goto P_0c0ace0a;
P_0c0ace0a: /* original d23b, guest PC 0x0c0ace0a */
if(!s->budget--) { s->failed_pc=0x0c0ace0au; return 0; }
r[2]=read(ram,0x0c0acef8u,4);
goto P_0c0ace0c;
P_0c0ace0c: /* original 420b, guest PC 0x0c0ace0c */
if(!s->budget--) { s->failed_pc=0x0c0ace0cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ace10u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ace10u) { target=s->pc; goto dispatch; }
goto P_0c0ace10;
P_0c0ace0e: /* original 64e3, guest PC 0x0c0ace0e */
if(!s->budget--) { s->failed_pc=0x0c0ace0eu; return 0; }
r[4]=r[14];
goto P_0c0ace10;
P_0c0ace10: /* original 9064, guest PC 0x0c0ace10 */
if(!s->budget--) { s->failed_pc=0x0c0ace10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedcu,2);
goto P_0c0ace12;
P_0c0ace12: /* original 9364, guest PC 0x0c0ace12 */
if(!s->budget--) { s->failed_pc=0x0c0ace12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedeu,2);
goto P_0c0ace14;
P_0c0ace14: /* original 05ec, guest PC 0x0c0ace14 */
if(!s->budget--) { s->failed_pc=0x0c0ace14u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ace16;
P_0c0ace16: /* original d439, guest PC 0x0c0ace16 */
if(!s->budget--) { s->failed_pc=0x0c0ace16u; return 0; }
r[4]=read(ram,0x0c0acefcu,4);
goto P_0c0ace18;
P_0c0ace18: /* original 655c, guest PC 0x0c0ace18 */
if(!s->budget--) { s->failed_pc=0x0c0ace18u; return 0; }
r[5]=r[5]&255u;
goto P_0c0ace1a;
P_0c0ace1a: /* original 253b, guest PC 0x0c0ace1a */
if(!s->budget--) { s->failed_pc=0x0c0ace1au; return 0; }
r[5]|=r[3];
goto P_0c0ace1c;
P_0c0ace1c: /* original 0e54, guest PC 0x0c0ace1c */
if(!s->budget--) { s->failed_pc=0x0c0ace1cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0ace1e;
P_0c0ace1e: /* original 1e4d, guest PC 0x0c0ace1e */
if(!s->budget--) { s->failed_pc=0x0c0ace1eu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0ace20;
P_0c0ace20: /* original 7f18, guest PC 0x0c0ace20 */
if(!s->budget--) { s->failed_pc=0x0c0ace20u; return 0; }
r[15]+=0x00000018u;
goto P_0c0ace22;
P_0c0ace22: /* original 4f26, guest PC 0x0c0ace22 */
if(!s->budget--) { s->failed_pc=0x0c0ace22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ace24;
P_0c0ace24: /* original 68f6, guest PC 0x0c0ace24 */
if(!s->budget--) { s->failed_pc=0x0c0ace24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0ace26;
P_0c0ace26: /* original 69f6, guest PC 0x0c0ace26 */
if(!s->budget--) { s->failed_pc=0x0c0ace26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ace28;
P_0c0ace28: /* original 6af6, guest PC 0x0c0ace28 */
if(!s->budget--) { s->failed_pc=0x0c0ace28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ace2a;
P_0c0ace2a: /* original 6bf6, guest PC 0x0c0ace2a */
if(!s->budget--) { s->failed_pc=0x0c0ace2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ace2c;
P_0c0ace2c: /* original 6cf6, guest PC 0x0c0ace2c */
if(!s->budget--) { s->failed_pc=0x0c0ace2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ace2e;
P_0c0ace2e: /* original 6df6, guest PC 0x0c0ace2e */
if(!s->budget--) { s->failed_pc=0x0c0ace2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ace30;
P_0c0ace30: /* original 000b, guest PC 0x0c0ace30 */
if(!s->budget--) { s->failed_pc=0x0c0ace30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ace32: /* original 6ef6, guest PC 0x0c0ace32 */
if(!s->budget--) { s->failed_pc=0x0c0ace32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ace34u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ace34u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
