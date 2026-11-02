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
int vf3_away_batch63_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08f8beu: goto P_0c08f8be;
case 0x0c08f8c0u: goto P_0c08f8c0;
case 0x0c08f8c2u: goto P_0c08f8c2;
case 0x0c08f8c4u: goto P_0c08f8c4;
case 0x0c08f8c6u: goto P_0c08f8c6;
case 0x0c08f8c8u: goto P_0c08f8c8;
case 0x0c08f8cau: goto P_0c08f8ca;
case 0x0c08f8ccu: goto P_0c08f8cc;
case 0x0c08f8ceu: goto P_0c08f8ce;
case 0x0c08f8d0u: goto P_0c08f8d0;
case 0x0c08f8d2u: goto P_0c08f8d2;
case 0x0c08f8d4u: goto P_0c08f8d4;
case 0x0c08f8d6u: goto P_0c08f8d6;
case 0x0c08f8d8u: goto P_0c08f8d8;
case 0x0c08f8dau: goto P_0c08f8da;
case 0x0c08f8dcu: goto P_0c08f8dc;
case 0x0c08f8deu: goto P_0c08f8de;
case 0x0c08f8e0u: goto P_0c08f8e0;
case 0x0c08f8e2u: goto P_0c08f8e2;
case 0x0c08f8e4u: goto P_0c08f8e4;
case 0x0c08f8e6u: goto P_0c08f8e6;
case 0x0c08f8e8u: goto P_0c08f8e8;
case 0x0c08f8eau: goto P_0c08f8ea;
case 0x0c08f8ecu: goto P_0c08f8ec;
case 0x0c08f8eeu: goto P_0c08f8ee;
case 0x0c08f8f0u: goto P_0c08f8f0;
case 0x0c08f8f2u: goto P_0c08f8f2;
case 0x0c08f8f4u: goto P_0c08f8f4;
case 0x0c08f8f6u: goto P_0c08f8f6;
case 0x0c08f8f8u: goto P_0c08f8f8;
case 0x0c08f8fau: goto P_0c08f8fa;
case 0x0c08f8fcu: goto P_0c08f8fc;
case 0x0c08f8feu: goto P_0c08f8fe;
case 0x0c08f900u: goto P_0c08f900;
case 0x0c08f902u: goto P_0c08f902;
case 0x0c08f904u: goto P_0c08f904;
case 0x0c08f906u: goto P_0c08f906;
case 0x0c08f908u: goto P_0c08f908;
case 0x0c08f90au: goto P_0c08f90a;
case 0x0c08f90cu: goto P_0c08f90c;
case 0x0c08f90eu: goto P_0c08f90e;
case 0x0c08f910u: goto P_0c08f910;
case 0x0c08f912u: goto P_0c08f912;
case 0x0c08f914u: goto P_0c08f914;
case 0x0c08f916u: goto P_0c08f916;
case 0x0c08f918u: goto P_0c08f918;
case 0x0c08f91au: goto P_0c08f91a;
case 0x0c08f91cu: goto P_0c08f91c;
case 0x0c08f91eu: goto P_0c08f91e;
case 0x0c08f920u: goto P_0c08f920;
case 0x0c08f922u: goto P_0c08f922;
case 0x0c08f924u: goto P_0c08f924;
case 0x0c08f926u: goto P_0c08f926;
case 0x0c08f928u: goto P_0c08f928;
case 0x0c08f92au: goto P_0c08f92a;
case 0x0c08f92cu: goto P_0c08f92c;
case 0x0c08f92eu: goto P_0c08f92e;
case 0x0c08f930u: goto P_0c08f930;
case 0x0c08f932u: goto P_0c08f932;
case 0x0c08f934u: goto P_0c08f934;
case 0x0c08f936u: goto P_0c08f936;
case 0x0c08f938u: goto P_0c08f938;
case 0x0c08f93au: goto P_0c08f93a;
case 0x0c08f93cu: goto P_0c08f93c;
case 0x0c08f93eu: goto P_0c08f93e;
case 0x0c08f940u: goto P_0c08f940;
case 0x0c08f942u: goto P_0c08f942;
case 0x0c08f944u: goto P_0c08f944;
case 0x0c08f946u: goto P_0c08f946;
case 0x0c08f948u: goto P_0c08f948;
case 0x0c08f94au: goto P_0c08f94a;
case 0x0c08f94cu: goto P_0c08f94c;
case 0x0c08f94eu: goto P_0c08f94e;
case 0x0c08f950u: goto P_0c08f950;
case 0x0c08f952u: goto P_0c08f952;
case 0x0c08f954u: goto P_0c08f954;
case 0x0c08f956u: goto P_0c08f956;
case 0x0c08f958u: goto P_0c08f958;
case 0x0c08f95au: goto P_0c08f95a;
case 0x0c08f95cu: goto P_0c08f95c;
case 0x0c08f95eu: goto P_0c08f95e;
case 0x0c08f960u: goto P_0c08f960;
case 0x0c08f962u: goto P_0c08f962;
case 0x0c08f964u: goto P_0c08f964;
case 0x0c08f966u: goto P_0c08f966;
case 0x0c08f968u: goto P_0c08f968;
case 0x0c08f96au: goto P_0c08f96a;
case 0x0c08f96cu: goto P_0c08f96c;
case 0x0c08f96eu: goto P_0c08f96e;
case 0x0c08f970u: goto P_0c08f970;
case 0x0c08f972u: goto P_0c08f972;
case 0x0c08f974u: goto P_0c08f974;
case 0x0c08f976u: goto P_0c08f976;
case 0x0c08f978u: goto P_0c08f978;
case 0x0c08f97au: goto P_0c08f97a;
case 0x0c08f97cu: goto P_0c08f97c;
case 0x0c08f97eu: goto P_0c08f97e;
case 0x0c08f9acu: goto P_0c08f9ac;
case 0x0c08f9aeu: goto P_0c08f9ae;
case 0x0c08f9b0u: goto P_0c08f9b0;
case 0x0c08f9b2u: goto P_0c08f9b2;
case 0x0c08f9b4u: goto P_0c08f9b4;
case 0x0c08f9b6u: goto P_0c08f9b6;
case 0x0c08f9b8u: goto P_0c08f9b8;
case 0x0c08f9bau: goto P_0c08f9ba;
case 0x0c08f9bcu: goto P_0c08f9bc;
case 0x0c08f9beu: goto P_0c08f9be;
case 0x0c08f9c0u: goto P_0c08f9c0;
case 0x0c08f9c2u: goto P_0c08f9c2;
case 0x0c08f9c4u: goto P_0c08f9c4;
case 0x0c08f9c6u: goto P_0c08f9c6;
case 0x0c08f9c8u: goto P_0c08f9c8;
case 0x0c08f9cau: goto P_0c08f9ca;
case 0x0c08f9ccu: goto P_0c08f9cc;
case 0x0c08f9ceu: goto P_0c08f9ce;
case 0x0c08f9d0u: goto P_0c08f9d0;
case 0x0c08f9d2u: goto P_0c08f9d2;
case 0x0c08f9d4u: goto P_0c08f9d4;
case 0x0c08f9d6u: goto P_0c08f9d6;
case 0x0c08f9d8u: goto P_0c08f9d8;
case 0x0c08f9dau: goto P_0c08f9da;
case 0x0c08f9dcu: goto P_0c08f9dc;
case 0x0c08f9deu: goto P_0c08f9de;
case 0x0c08f9e0u: goto P_0c08f9e0;
case 0x0c08f9e2u: goto P_0c08f9e2;
case 0x0c08f9e4u: goto P_0c08f9e4;
case 0x0c08f9e6u: goto P_0c08f9e6;
case 0x0c08f9e8u: goto P_0c08f9e8;
case 0x0c08f9eau: goto P_0c08f9ea;
case 0x0c08f9ecu: goto P_0c08f9ec;
case 0x0c08f9eeu: goto P_0c08f9ee;
case 0x0c08f9f0u: goto P_0c08f9f0;
case 0x0c08f9f2u: goto P_0c08f9f2;
case 0x0c08f9f4u: goto P_0c08f9f4;
case 0x0c08f9f6u: goto P_0c08f9f6;
case 0x0c08f9f8u: goto P_0c08f9f8;
case 0x0c08f9fau: goto P_0c08f9fa;
case 0x0c08f9fcu: goto P_0c08f9fc;
case 0x0c08f9feu: goto P_0c08f9fe;
case 0x0c08fa00u: goto P_0c08fa00;
case 0x0c08fa02u: goto P_0c08fa02;
case 0x0c08fa04u: goto P_0c08fa04;
case 0x0c08fa06u: goto P_0c08fa06;
case 0x0c08fa08u: goto P_0c08fa08;
case 0x0c08fa0au: goto P_0c08fa0a;
case 0x0c08fa0cu: goto P_0c08fa0c;
case 0x0c08fa0eu: goto P_0c08fa0e;
case 0x0c08fa10u: goto P_0c08fa10;
case 0x0c08fa12u: goto P_0c08fa12;
case 0x0c08fa14u: goto P_0c08fa14;
case 0x0c08fa16u: goto P_0c08fa16;
case 0x0c08fa18u: goto P_0c08fa18;
case 0x0c08fa1au: goto P_0c08fa1a;
case 0x0c08fa1cu: goto P_0c08fa1c;
case 0x0c08fa1eu: goto P_0c08fa1e;
case 0x0c08fa20u: goto P_0c08fa20;
case 0x0c08fa22u: goto P_0c08fa22;
case 0x0c08fa24u: goto P_0c08fa24;
case 0x0c08fa26u: goto P_0c08fa26;
case 0x0c08fa28u: goto P_0c08fa28;
case 0x0c08fa2au: goto P_0c08fa2a;
case 0x0c08fa2cu: goto P_0c08fa2c;
case 0x0c08fa2eu: goto P_0c08fa2e;
case 0x0c08fa30u: goto P_0c08fa30;
case 0x0c08fa32u: goto P_0c08fa32;
case 0x0c08fa34u: goto P_0c08fa34;
case 0x0c08fa36u: goto P_0c08fa36;
case 0x0c08fa38u: goto P_0c08fa38;
case 0x0c08fa3au: goto P_0c08fa3a;
case 0x0c08fa3cu: goto P_0c08fa3c;
case 0x0c08fa3eu: goto P_0c08fa3e;
case 0x0c08fa40u: goto P_0c08fa40;
case 0x0c08fa42u: goto P_0c08fa42;
case 0x0c08fa44u: goto P_0c08fa44;
case 0x0c08fa46u: goto P_0c08fa46;
case 0x0c08fa48u: goto P_0c08fa48;
case 0x0c08fa4au: goto P_0c08fa4a;
case 0x0c08fa4cu: goto P_0c08fa4c;
case 0x0c08fa4eu: goto P_0c08fa4e;
case 0x0c08fa50u: goto P_0c08fa50;
case 0x0c08fa52u: goto P_0c08fa52;
case 0x0c08fa54u: goto P_0c08fa54;
case 0x0c08fa56u: goto P_0c08fa56;
case 0x0c08fa58u: goto P_0c08fa58;
case 0x0c08fa5au: goto P_0c08fa5a;
case 0x0c08fa5cu: goto P_0c08fa5c;
case 0x0c08fa5eu: goto P_0c08fa5e;
case 0x0c08fa60u: goto P_0c08fa60;
case 0x0c08fa62u: goto P_0c08fa62;
case 0x0c08fa64u: goto P_0c08fa64;
case 0x0c08fa66u: goto P_0c08fa66;
case 0x0c08fa68u: goto P_0c08fa68;
case 0x0c08fa6au: goto P_0c08fa6a;
case 0x0c08fa6cu: goto P_0c08fa6c;
case 0x0c08fa6eu: goto P_0c08fa6e;
case 0x0c08fa70u: goto P_0c08fa70;
case 0x0c08fa72u: goto P_0c08fa72;
case 0x0c08fa74u: goto P_0c08fa74;
case 0x0c08fa76u: goto P_0c08fa76;
case 0x0c08fa78u: goto P_0c08fa78;
case 0x0c08fa7au: goto P_0c08fa7a;
case 0x0c08fa7cu: goto P_0c08fa7c;
case 0x0c08fa7eu: goto P_0c08fa7e;
case 0x0c08fa80u: goto P_0c08fa80;
case 0x0c08fa82u: goto P_0c08fa82;
case 0x0c08fa84u: goto P_0c08fa84;
case 0x0c08fa86u: goto P_0c08fa86;
case 0x0c08fa88u: goto P_0c08fa88;
case 0x0c08fa8au: goto P_0c08fa8a;
case 0x0c08fa8cu: goto P_0c08fa8c;
case 0x0c08fa8eu: goto P_0c08fa8e;
case 0x0c08fa90u: goto P_0c08fa90;
case 0x0c08fa92u: goto P_0c08fa92;
case 0x0c08fa94u: goto P_0c08fa94;
case 0x0c08fa96u: goto P_0c08fa96;
case 0x0c08fa98u: goto P_0c08fa98;
case 0x0c08fa9au: goto P_0c08fa9a;
case 0x0c08fa9cu: goto P_0c08fa9c;
case 0x0c08fa9eu: goto P_0c08fa9e;
case 0x0c08faa0u: goto P_0c08faa0;
case 0x0c08faa2u: goto P_0c08faa2;
case 0x0c08faa4u: goto P_0c08faa4;
case 0x0c08faa6u: goto P_0c08faa6;
case 0x0c08faa8u: goto P_0c08faa8;
case 0x0c08faaau: goto P_0c08faaa;
case 0x0c08faacu: goto P_0c08faac;
case 0x0c08faaeu: goto P_0c08faae;
case 0x0c08fab0u: goto P_0c08fab0;
case 0x0c08fab2u: goto P_0c08fab2;
case 0x0c08fab4u: goto P_0c08fab4;
case 0x0c08fab6u: goto P_0c08fab6;
case 0x0c08fab8u: goto P_0c08fab8;
case 0x0c08fabau: goto P_0c08faba;
case 0x0c08fabcu: goto P_0c08fabc;
case 0x0c08fabeu: goto P_0c08fabe;
case 0x0c08fac0u: goto P_0c08fac0;
case 0x0c08fac2u: goto P_0c08fac2;
case 0x0c08fac4u: goto P_0c08fac4;
case 0x0c08fac6u: goto P_0c08fac6;
case 0x0c08fac8u: goto P_0c08fac8;
case 0x0c08facau: goto P_0c08faca;
case 0x0c08faccu: goto P_0c08facc;
case 0x0c08faceu: goto P_0c08face;
case 0x0c08fad0u: goto P_0c08fad0;
case 0x0c08fad2u: goto P_0c08fad2;
case 0x0c08fad4u: goto P_0c08fad4;
case 0x0c08fad6u: goto P_0c08fad6;
case 0x0c08fad8u: goto P_0c08fad8;
case 0x0c08fb00u: goto P_0c08fb00;
case 0x0c08fb02u: goto P_0c08fb02;
case 0x0c08fb04u: goto P_0c08fb04;
case 0x0c08fb06u: goto P_0c08fb06;
case 0x0c08fb08u: goto P_0c08fb08;
case 0x0c08fb0au: goto P_0c08fb0a;
case 0x0c08fb0cu: goto P_0c08fb0c;
case 0x0c08fb0eu: goto P_0c08fb0e;
case 0x0c08fb10u: goto P_0c08fb10;
case 0x0c08fb12u: goto P_0c08fb12;
case 0x0c08fb14u: goto P_0c08fb14;
case 0x0c08fb16u: goto P_0c08fb16;
case 0x0c08fb18u: goto P_0c08fb18;
case 0x0c08fb1au: goto P_0c08fb1a;
case 0x0c08fb1cu: goto P_0c08fb1c;
case 0x0c08fb1eu: goto P_0c08fb1e;
case 0x0c08fb20u: goto P_0c08fb20;
case 0x0c08fb22u: goto P_0c08fb22;
case 0x0c08fb24u: goto P_0c08fb24;
case 0x0c08fb26u: goto P_0c08fb26;
case 0x0c08fb28u: goto P_0c08fb28;
case 0x0c08fb2au: goto P_0c08fb2a;
case 0x0c08fb2cu: goto P_0c08fb2c;
case 0x0c08fb2eu: goto P_0c08fb2e;
case 0x0c08fb30u: goto P_0c08fb30;
case 0x0c08fb32u: goto P_0c08fb32;
case 0x0c08fb34u: goto P_0c08fb34;
case 0x0c08fb36u: goto P_0c08fb36;
case 0x0c08fb38u: goto P_0c08fb38;
case 0x0c08fb3au: goto P_0c08fb3a;
case 0x0c08fb3cu: goto P_0c08fb3c;
case 0x0c08fb3eu: goto P_0c08fb3e;
case 0x0c08fb40u: goto P_0c08fb40;
case 0x0c08fb42u: goto P_0c08fb42;
case 0x0c08fb44u: goto P_0c08fb44;
case 0x0c08fb46u: goto P_0c08fb46;
case 0x0c08fb48u: goto P_0c08fb48;
case 0x0c08fb4au: goto P_0c08fb4a;
case 0x0c08fb4cu: goto P_0c08fb4c;
case 0x0c08fb4eu: goto P_0c08fb4e;
case 0x0c08fb50u: goto P_0c08fb50;
case 0x0c08fb52u: goto P_0c08fb52;
case 0x0c08fb54u: goto P_0c08fb54;
case 0x0c08fb56u: goto P_0c08fb56;
case 0x0c08fb58u: goto P_0c08fb58;
case 0x0c08fb5au: goto P_0c08fb5a;
case 0x0c08fb5cu: goto P_0c08fb5c;
case 0x0c08fb5eu: goto P_0c08fb5e;
case 0x0c08fb60u: goto P_0c08fb60;
case 0x0c08fb62u: goto P_0c08fb62;
case 0x0c08fb64u: goto P_0c08fb64;
case 0x0c08fb66u: goto P_0c08fb66;
case 0x0c08fb68u: goto P_0c08fb68;
case 0x0c08fb6au: goto P_0c08fb6a;
case 0x0c08fb6cu: goto P_0c08fb6c;
case 0x0c08fb6eu: goto P_0c08fb6e;
case 0x0c08fb70u: goto P_0c08fb70;
case 0x0c08fb72u: goto P_0c08fb72;
case 0x0c08fb74u: goto P_0c08fb74;
case 0x0c08fb76u: goto P_0c08fb76;
case 0x0c08fb78u: goto P_0c08fb78;
case 0x0c08fb7au: goto P_0c08fb7a;
case 0x0c08fb7cu: goto P_0c08fb7c;
case 0x0c08fb7eu: goto P_0c08fb7e;
case 0x0c08fb80u: goto P_0c08fb80;
case 0x0c08fb82u: goto P_0c08fb82;
case 0x0c08fb84u: goto P_0c08fb84;
case 0x0c08fb86u: goto P_0c08fb86;
case 0x0c08fb88u: goto P_0c08fb88;
case 0x0c08fb8au: goto P_0c08fb8a;
case 0x0c08fb8cu: goto P_0c08fb8c;
case 0x0c08fb8eu: goto P_0c08fb8e;
case 0x0c08fb90u: goto P_0c08fb90;
case 0x0c08fb92u: goto P_0c08fb92;
case 0x0c08fb94u: goto P_0c08fb94;
case 0x0c08fb96u: goto P_0c08fb96;
case 0x0c08fb98u: goto P_0c08fb98;
case 0x0c08fb9au: goto P_0c08fb9a;
case 0x0c08fb9cu: goto P_0c08fb9c;
case 0x0c08fb9eu: goto P_0c08fb9e;
case 0x0c08fba0u: goto P_0c08fba0;
case 0x0c08fba2u: goto P_0c08fba2;
case 0x0c08fba4u: goto P_0c08fba4;
case 0x0c08fba6u: goto P_0c08fba6;
case 0x0c08fba8u: goto P_0c08fba8;
case 0x0c08fbaau: goto P_0c08fbaa;
case 0x0c08fbacu: goto P_0c08fbac;
case 0x0c08fbaeu: goto P_0c08fbae;
case 0x0c08fbb0u: goto P_0c08fbb0;
case 0x0c08fbb2u: goto P_0c08fbb2;
case 0x0c08fbb4u: goto P_0c08fbb4;
case 0x0c08fbb6u: goto P_0c08fbb6;
case 0x0c08fbb8u: goto P_0c08fbb8;
case 0x0c08fbbau: goto P_0c08fbba;
case 0x0c08fbbcu: goto P_0c08fbbc;
case 0x0c08fbbeu: goto P_0c08fbbe;
case 0x0c08fbc0u: goto P_0c08fbc0;
case 0x0c08fbc2u: goto P_0c08fbc2;
case 0x0c08fbc4u: goto P_0c08fbc4;
case 0x0c08fbc6u: goto P_0c08fbc6;
case 0x0c08fbc8u: goto P_0c08fbc8;
case 0x0c08fbe4u: goto P_0c08fbe4;
case 0x0c08fbe6u: goto P_0c08fbe6;
case 0x0c08fbe8u: goto P_0c08fbe8;
case 0x0c08fbeau: goto P_0c08fbea;
case 0x0c08fbecu: goto P_0c08fbec;
case 0x0c08fbeeu: goto P_0c08fbee;
case 0x0c08fbf0u: goto P_0c08fbf0;
case 0x0c08fbf2u: goto P_0c08fbf2;
case 0x0c08fbf4u: goto P_0c08fbf4;
case 0x0c08fbf6u: goto P_0c08fbf6;
case 0x0c08fbf8u: goto P_0c08fbf8;
case 0x0c08fbfau: goto P_0c08fbfa;
case 0x0c08fbfcu: goto P_0c08fbfc;
case 0x0c08fbfeu: goto P_0c08fbfe;
case 0x0c08fc00u: goto P_0c08fc00;
case 0x0c08fc02u: goto P_0c08fc02;
case 0x0c08fc04u: goto P_0c08fc04;
case 0x0c08fc06u: goto P_0c08fc06;
case 0x0c08fc08u: goto P_0c08fc08;
case 0x0c08fc0au: goto P_0c08fc0a;
case 0x0c08fc0cu: goto P_0c08fc0c;
case 0x0c08fc0eu: goto P_0c08fc0e;
case 0x0c08fc10u: goto P_0c08fc10;
case 0x0c08fc12u: goto P_0c08fc12;
case 0x0c08fc14u: goto P_0c08fc14;
case 0x0c08fc16u: goto P_0c08fc16;
case 0x0c08fc18u: goto P_0c08fc18;
case 0x0c08fc1au: goto P_0c08fc1a;
case 0x0c08fc1cu: goto P_0c08fc1c;
case 0x0c08fc1eu: goto P_0c08fc1e;
case 0x0c08fc20u: goto P_0c08fc20;
case 0x0c08fc22u: goto P_0c08fc22;
case 0x0c08fc24u: goto P_0c08fc24;
case 0x0c08fc26u: goto P_0c08fc26;
case 0x0c08fc28u: goto P_0c08fc28;
case 0x0c08fc2au: goto P_0c08fc2a;
case 0x0c08fc2cu: goto P_0c08fc2c;
case 0x0c08fc2eu: goto P_0c08fc2e;
case 0x0c08fc30u: goto P_0c08fc30;
case 0x0c08fc32u: goto P_0c08fc32;
case 0x0c08fc34u: goto P_0c08fc34;
case 0x0c08fc36u: goto P_0c08fc36;
case 0x0c08fc38u: goto P_0c08fc38;
case 0x0c08fc3au: goto P_0c08fc3a;
case 0x0c08fc3cu: goto P_0c08fc3c;
case 0x0c08fc3eu: goto P_0c08fc3e;
case 0x0c08fc40u: goto P_0c08fc40;
case 0x0c08fc42u: goto P_0c08fc42;
case 0x0c08fc44u: goto P_0c08fc44;
case 0x0c08fc46u: goto P_0c08fc46;
case 0x0c08fc48u: goto P_0c08fc48;
case 0x0c08fc4au: goto P_0c08fc4a;
case 0x0c08fc4cu: goto P_0c08fc4c;
case 0x0c08fc4eu: goto P_0c08fc4e;
case 0x0c08fc50u: goto P_0c08fc50;
case 0x0c08fc52u: goto P_0c08fc52;
case 0x0c08fc54u: goto P_0c08fc54;
case 0x0c08fc56u: goto P_0c08fc56;
case 0x0c08fc58u: goto P_0c08fc58;
case 0x0c08fc5au: goto P_0c08fc5a;
case 0x0c08fc5cu: goto P_0c08fc5c;
case 0x0c08fc5eu: goto P_0c08fc5e;
case 0x0c08fc60u: goto P_0c08fc60;
case 0x0c08fc62u: goto P_0c08fc62;
case 0x0c08fc64u: goto P_0c08fc64;
case 0x0c08fc66u: goto P_0c08fc66;
case 0x0c08fc68u: goto P_0c08fc68;
case 0x0c08fc6au: goto P_0c08fc6a;
case 0x0c08fc6cu: goto P_0c08fc6c;
case 0x0c08fc6eu: goto P_0c08fc6e;
case 0x0c08fc70u: goto P_0c08fc70;
case 0x0c08fc72u: goto P_0c08fc72;
case 0x0c08fc74u: goto P_0c08fc74;
case 0x0c08fc76u: goto P_0c08fc76;
case 0x0c08fc78u: goto P_0c08fc78;
case 0x0c08fc7au: goto P_0c08fc7a;
case 0x0c08fc7cu: goto P_0c08fc7c;
case 0x0c08fc7eu: goto P_0c08fc7e;
case 0x0c08fc80u: goto P_0c08fc80;
case 0x0c08fc82u: goto P_0c08fc82;
case 0x0c08fc84u: goto P_0c08fc84;
case 0x0c08fc86u: goto P_0c08fc86;
case 0x0c08fc88u: goto P_0c08fc88;
case 0x0c08fc8au: goto P_0c08fc8a;
case 0x0c08fc8cu: goto P_0c08fc8c;
case 0x0c08fc8eu: goto P_0c08fc8e;
case 0x0c08fc90u: goto P_0c08fc90;
case 0x0c08fc92u: goto P_0c08fc92;
case 0x0c08fc94u: goto P_0c08fc94;
case 0x0c08fc96u: goto P_0c08fc96;
case 0x0c08fc98u: goto P_0c08fc98;
case 0x0c08fc9au: goto P_0c08fc9a;
case 0x0c08fc9cu: goto P_0c08fc9c;
case 0x0c08fc9eu: goto P_0c08fc9e;
case 0x0c08fca0u: goto P_0c08fca0;
case 0x0c08fca2u: goto P_0c08fca2;
case 0x0c08fca4u: goto P_0c08fca4;
case 0x0c08fca6u: goto P_0c08fca6;
case 0x0c08fca8u: goto P_0c08fca8;
case 0x0c08fcaau: goto P_0c08fcaa;
case 0x0c08fcacu: goto P_0c08fcac;
case 0x0c08fcaeu: goto P_0c08fcae;
case 0x0c08fcb0u: goto P_0c08fcb0;
case 0x0c08fcb2u: goto P_0c08fcb2;
case 0x0c08fcb4u: goto P_0c08fcb4;
case 0x0c08fcb6u: goto P_0c08fcb6;
case 0x0c08fcb8u: goto P_0c08fcb8;
case 0x0c08fcbau: goto P_0c08fcba;
case 0x0c08fcbcu: goto P_0c08fcbc;
case 0x0c08fcbeu: goto P_0c08fcbe;
case 0x0c08fcc0u: goto P_0c08fcc0;
case 0x0c08fcc2u: goto P_0c08fcc2;
case 0x0c08fcc4u: goto P_0c08fcc4;
case 0x0c08fcc6u: goto P_0c08fcc6;
case 0x0c08fcc8u: goto P_0c08fcc8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08f8be: /* original 2fe6, guest PC 0x0c08f8be */
if(!s->budget--) { s->failed_pc=0x0c08f8beu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8c0;
P_0c08f8c0: /* original 6e43, guest PC 0x0c08f8c0 */
if(!s->budget--) { s->failed_pc=0x0c08f8c0u; return 0; }
r[14]=r[4];
goto P_0c08f8c2;
P_0c08f8c2: /* original 2fd6, guest PC 0x0c08f8c2 */
if(!s->budget--) { s->failed_pc=0x0c08f8c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8c4;
P_0c08f8c4: /* original e044, guest PC 0x0c08f8c4 */
if(!s->budget--) { s->failed_pc=0x0c08f8c4u; return 0; }
r[0]=0x00000044u;
goto P_0c08f8c6;
P_0c08f8c6: /* original 2fc6, guest PC 0x0c08f8c6 */
if(!s->budget--) { s->failed_pc=0x0c08f8c6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8c8;
P_0c08f8c8: /* original 2fb6, guest PC 0x0c08f8c8 */
if(!s->budget--) { s->failed_pc=0x0c08f8c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8ca;
P_0c08f8ca: /* original 2fa6, guest PC 0x0c08f8ca */
if(!s->budget--) { s->failed_pc=0x0c08f8cau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8cc;
P_0c08f8cc: /* original 2f96, guest PC 0x0c08f8cc */
if(!s->budget--) { s->failed_pc=0x0c08f8ccu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8ce;
P_0c08f8ce: /* original e904, guest PC 0x0c08f8ce */
if(!s->budget--) { s->failed_pc=0x0c08f8ceu; return 0; }
r[9]=0x00000004u;
goto P_0c08f8d0;
P_0c08f8d0: /* original 2f86, guest PC 0x0c08f8d0 */
if(!s->budget--) { s->failed_pc=0x0c08f8d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f8d2;
P_0c08f8d2: /* original fffb, guest PC 0x0c08f8d2 */
if(!s->budget--) { s->failed_pc=0x0c08f8d2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08f8d4;
P_0c08f8d4: /* original ffeb, guest PC 0x0c08f8d4 */
if(!s->budget--) { s->failed_pc=0x0c08f8d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08f8d6;
P_0c08f8d6: /* original ffdb, guest PC 0x0c08f8d6 */
if(!s->budget--) { s->failed_pc=0x0c08f8d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08f8d8;
P_0c08f8d8: /* original ffcb, guest PC 0x0c08f8d8 */
if(!s->budget--) { s->failed_pc=0x0c08f8d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08f8da;
P_0c08f8da: /* original 05ee, guest PC 0x0c08f8da */
if(!s->budget--) { s->failed_pc=0x0c08f8dau; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c08f8dc;
P_0c08f8dc: /* original e050, guest PC 0x0c08f8dc */
if(!s->budget--) { s->failed_pc=0x0c08f8dcu; return 0; }
r[0]=0x00000050u;
goto P_0c08f8de;
P_0c08f8de: /* original 4f22, guest PC 0x0c08f8de */
if(!s->budget--) { s->failed_pc=0x0c08f8deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f8e0;
P_0c08f8e0: /* original 5ced, guest PC 0x0c08f8e0 */
if(!s->budget--) { s->failed_pc=0x0c08f8e0u; return 0; }
r[12]=read(ram,r[14]+52,4);
goto P_0c08f8e2;
P_0c08f8e2: /* original 06ee, guest PC 0x0c08f8e2 */
if(!s->budget--) { s->failed_pc=0x0c08f8e2u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c08f8e4;
P_0c08f8e4: /* original e050, guest PC 0x0c08f8e4 */
if(!s->budget--) { s->failed_pc=0x0c08f8e4u; return 0; }
r[0]=0x00000050u;
goto P_0c08f8e6;
P_0c08f8e6: /* original 5aee, guest PC 0x0c08f8e6 */
if(!s->budget--) { s->failed_pc=0x0c08f8e6u; return 0; }
r[10]=read(ram,r[14]+56,4);
goto P_0c08f8e8;
P_0c08f8e8: /* original 64c3, guest PC 0x0c08f8e8 */
if(!s->budget--) { s->failed_pc=0x0c08f8e8u; return 0; }
r[4]=r[12];
goto P_0c08f8ea;
P_0c08f8ea: /* original 256b, guest PC 0x0c08f8ea */
if(!s->budget--) { s->failed_pc=0x0c08f8eau; return 0; }
r[5]|=r[6];
goto P_0c08f8ec;
P_0c08f8ec: /* original 7fac, guest PC 0x0c08f8ec */
if(!s->budget--) { s->failed_pc=0x0c08f8ecu; return 0; }
r[15]+=0xffffffacu;
goto P_0c08f8ee;
P_0c08f8ee: /* original 24aa, guest PC 0x0c08f8ee */
if(!s->budget--) { s->failed_pc=0x0c08f8eeu; return 0; }
r[4]^=r[10];
goto P_0c08f8f0;
P_0c08f8f0: /* original 0f56, guest PC 0x0c08f8f0 */
if(!s->budget--) { s->failed_pc=0x0c08f8f0u; return 0; }
write(ram,r[15]+r[0],r[5],4);
goto P_0c08f8f2;
P_0c08f8f2: /* original 2498, guest PC 0x0c08f8f2 */
if(!s->budget--) { s->failed_pc=0x0c08f8f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c08f8f4;
P_0c08f8f4: /* original 8d2a, guest PC 0x0c08f8f4 */
if(!s->budget--) { s->failed_pc=0x0c08f8f4u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(cond) { goto P_0c08f94c; }
goto P_0c08f8f8;
P_0c08f8f6: /* original eb00, guest PC 0x0c08f8f6 */
if(!s->budget--) { s->failed_pc=0x0c08f8f6u; return 0; }
r[11]=0x00000000u;
goto P_0c08f8f8;
P_0c08f8f8: /* original e070, guest PC 0x0c08f8f8 */
if(!s->budget--) { s->failed_pc=0x0c08f8f8u; return 0; }
r[0]=0x00000070u;
goto P_0c08f8fa;
P_0c08f8fa: /* original 63f3, guest PC 0x0c08f8fa */
if(!s->budget--) { s->failed_pc=0x0c08f8fau; return 0; }
r[3]=r[15];
goto P_0c08f8fc;
P_0c08f8fc: /* original f3e6, guest PC 0x0c08f8fc */
if(!s->budget--) { s->failed_pc=0x0c08f8fcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f8fe;
P_0c08f8fe: /* original e00c, guest PC 0x0c08f8fe */
if(!s->budget--) { s->failed_pc=0x0c08f8feu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f900;
P_0c08f900: /* original 7308, guest PC 0x0c08f900 */
if(!s->budget--) { s->failed_pc=0x0c08f900u; return 0; }
r[3]+=0x00000008u;
goto P_0c08f902;
P_0c08f902: /* original ff37, guest PC 0x0c08f902 */
if(!s->budget--) { s->failed_pc=0x0c08f902u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f904;
P_0c08f904: /* original e078, guest PC 0x0c08f904 */
if(!s->budget--) { s->failed_pc=0x0c08f904u; return 0; }
r[0]=0x00000078u;
goto P_0c08f906;
P_0c08f906: /* original f3e6, guest PC 0x0c08f906 */
if(!s->budget--) { s->failed_pc=0x0c08f906u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f908;
P_0c08f908: /* original e010, guest PC 0x0c08f908 */
if(!s->budget--) { s->failed_pc=0x0c08f908u; return 0; }
r[0]=0x00000010u;
goto P_0c08f90a;
P_0c08f90a: /* original ff37, guest PC 0x0c08f90a */
if(!s->budget--) { s->failed_pc=0x0c08f90au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f90c;
P_0c08f90c: /* original 9044, guest PC 0x0c08f90c */
if(!s->budget--) { s->failed_pc=0x0c08f90cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f998u,2);
goto P_0c08f90e;
P_0c08f90e: /* original f3e6, guest PC 0x0c08f90e */
if(!s->budget--) { s->failed_pc=0x0c08f90eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f910;
P_0c08f910: /* original e014, guest PC 0x0c08f910 */
if(!s->budget--) { s->failed_pc=0x0c08f910u; return 0; }
r[0]=0x00000014u;
goto P_0c08f912;
P_0c08f912: /* original ff37, guest PC 0x0c08f912 */
if(!s->budget--) { s->failed_pc=0x0c08f912u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f914;
P_0c08f914: /* original 9041, guest PC 0x0c08f914 */
if(!s->budget--) { s->failed_pc=0x0c08f914u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f99au,2);
goto P_0c08f916;
P_0c08f916: /* original f3e6, guest PC 0x0c08f916 */
if(!s->budget--) { s->failed_pc=0x0c08f916u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f918;
P_0c08f918: /* original e018, guest PC 0x0c08f918 */
if(!s->budget--) { s->failed_pc=0x0c08f918u; return 0; }
r[0]=0x00000018u;
goto P_0c08f91a;
P_0c08f91a: /* original ff37, guest PC 0x0c08f91a */
if(!s->budget--) { s->failed_pc=0x0c08f91au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f91c;
P_0c08f91c: /* original e01c, guest PC 0x0c08f91c */
if(!s->budget--) { s->failed_pc=0x0c08f91cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08f91e;
P_0c08f91e: /* original 2f36, guest PC 0x0c08f91e */
if(!s->budget--) { s->failed_pc=0x0c08f91eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f920;
P_0c08f920: /* original f7f6, guest PC 0x0c08f920 */
if(!s->budget--) { s->failed_pc=0x0c08f920u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c08f922;
P_0c08f922: /* original e018, guest PC 0x0c08f922 */
if(!s->budget--) { s->failed_pc=0x0c08f922u; return 0; }
r[0]=0x00000018u;
goto P_0c08f924;
P_0c08f924: /* original f6f6, guest PC 0x0c08f924 */
if(!s->budget--) { s->failed_pc=0x0c08f924u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08f926;
P_0c08f926: /* original e014, guest PC 0x0c08f926 */
if(!s->budget--) { s->failed_pc=0x0c08f926u; return 0; }
r[0]=0x00000014u;
goto P_0c08f928;
P_0c08f928: /* original f5f6, guest PC 0x0c08f928 */
if(!s->budget--) { s->failed_pc=0x0c08f928u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08f92a;
P_0c08f92a: /* original e010, guest PC 0x0c08f92a */
if(!s->budget--) { s->failed_pc=0x0c08f92au; return 0; }
r[0]=0x00000010u;
goto P_0c08f92c;
P_0c08f92c: /* original 66f3, guest PC 0x0c08f92c */
if(!s->budget--) { s->failed_pc=0x0c08f92cu; return 0; }
r[6]=r[15];
goto P_0c08f92e;
P_0c08f92e: /* original 67f3, guest PC 0x0c08f92e */
if(!s->budget--) { s->failed_pc=0x0c08f92eu; return 0; }
r[7]=r[15];
goto P_0c08f930;
P_0c08f930: /* original f4f6, guest PC 0x0c08f930 */
if(!s->budget--) { s->failed_pc=0x0c08f930u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08f932;
P_0c08f932: /* original 65f3, guest PC 0x0c08f932 */
if(!s->budget--) { s->failed_pc=0x0c08f932u; return 0; }
r[5]=r[15];
goto P_0c08f934;
P_0c08f934: /* original 762c, guest PC 0x0c08f934 */
if(!s->budget--) { s->failed_pc=0x0c08f934u; return 0; }
r[6]+=0x0000002cu;
goto P_0c08f936;
P_0c08f936: /* original 7708, guest PC 0x0c08f936 */
if(!s->budget--) { s->failed_pc=0x0c08f936u; return 0; }
r[7]+=0x00000008u;
goto P_0c08f938;
P_0c08f938: /* original d31b, guest PC 0x0c08f938 */
if(!s->budget--) { s->failed_pc=0x0c08f938u; return 0; }
r[3]=read(ram,0x0c08f9a8u,4);
goto P_0c08f93a;
P_0c08f93a: /* original 64f3, guest PC 0x0c08f93a */
if(!s->budget--) { s->failed_pc=0x0c08f93au; return 0; }
r[4]=r[15];
goto P_0c08f93c;
P_0c08f93c: /* original 7528, guest PC 0x0c08f93c */
if(!s->budget--) { s->failed_pc=0x0c08f93cu; return 0; }
r[5]+=0x00000028u;
goto P_0c08f93e;
P_0c08f93e: /* original 430b, guest PC 0x0c08f93e */
if(!s->budget--) { s->failed_pc=0x0c08f93eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08f942u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f942u) { target=s->pc; goto dispatch; }
goto P_0c08f942;
P_0c08f940: /* original 7404, guest PC 0x0c08f940 */
if(!s->budget--) { s->failed_pc=0x0c08f940u; return 0; }
r[4]+=0x00000004u;
goto P_0c08f942;
P_0c08f942: /* original 7f04, guest PC 0x0c08f942 */
if(!s->budget--) { s->failed_pc=0x0c08f942u; return 0; }
r[15]+=0x00000004u;
goto P_0c08f944;
P_0c08f944: /* original 932a, guest PC 0x0c08f944 */
if(!s->budget--) { s->failed_pc=0x0c08f944u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f99cu,2);
goto P_0c08f946;
P_0c08f946: /* original 5df2, guest PC 0x0c08f946 */
if(!s->budget--) { s->failed_pc=0x0c08f946u; return 0; }
r[13]=read(ram,r[15]+8,4);
goto P_0c08f948;
P_0c08f948: /* original 5bf1, guest PC 0x0c08f948 */
if(!s->budget--) { s->failed_pc=0x0c08f948u; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c08f94a;
P_0c08f94a: /* original 2d3a, guest PC 0x0c08f94a */
if(!s->budget--) { s->failed_pc=0x0c08f94au; return 0; }
r[13]^=r[3];
goto P_0c08f94c;
P_0c08f94c: /* original e07c, guest PC 0x0c08f94c */
if(!s->budget--) { s->failed_pc=0x0c08f94cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08f94e;
P_0c08f94e: /* original fce6, guest PC 0x0c08f94e */
if(!s->budget--) { s->failed_pc=0x0c08f94eu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08f950;
P_0c08f950: /* original 7008, guest PC 0x0c08f950 */
if(!s->budget--) { s->failed_pc=0x0c08f950u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f952;
P_0c08f952: /* original f4e6, guest PC 0x0c08f952 */
if(!s->budget--) { s->failed_pc=0x0c08f952u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f954;
P_0c08f954: /* original 7040, guest PC 0x0c08f954 */
if(!s->budget--) { s->failed_pc=0x0c08f954u; return 0; }
r[0]+=0x00000040u;
goto P_0c08f956;
P_0c08f956: /* original f3e6, guest PC 0x0c08f956 */
if(!s->budget--) { s->failed_pc=0x0c08f956u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f958;
P_0c08f958: /* original e020, guest PC 0x0c08f958 */
if(!s->budget--) { s->failed_pc=0x0c08f958u; return 0; }
r[0]=0x00000020u;
goto P_0c08f95a;
P_0c08f95a: /* original ff37, guest PC 0x0c08f95a */
if(!s->budget--) { s->failed_pc=0x0c08f95au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f95c;
P_0c08f95c: /* original 901f, guest PC 0x0c08f95c */
if(!s->budget--) { s->failed_pc=0x0c08f95cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f99eu,2);
goto P_0c08f95e;
P_0c08f95e: /* original f5e6, guest PC 0x0c08f95e */
if(!s->budget--) { s->failed_pc=0x0c08f95eu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f960;
P_0c08f960: /* original 901e, guest PC 0x0c08f960 */
if(!s->budget--) { s->failed_pc=0x0c08f960u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f9a0u,2);
goto P_0c08f962;
P_0c08f962: /* original 03ec, guest PC 0x0c08f962 */
if(!s->budget--) { s->failed_pc=0x0c08f962u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08f964;
P_0c08f964: /* original 4315, guest PC 0x0c08f964 */
if(!s->budget--) { s->failed_pc=0x0c08f964u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c08f966;
P_0c08f966: /* original 8d21, guest PC 0x0c08f966 */
if(!s->budget--) { s->failed_pc=0x0c08f966u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c08f9ac; }
goto P_0c08f96a;
P_0c08f968: /* original 1f31, guest PC 0x0c08f968 */
if(!s->budget--) { s->failed_pc=0x0c08f968u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c08f96a;
P_0c08f96a: /* original 901a, guest PC 0x0c08f96a */
if(!s->budget--) { s->failed_pc=0x0c08f96au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f9a2u,2);
goto P_0c08f96c;
P_0c08f96c: /* original f3e6, guest PC 0x0c08f96c */
if(!s->budget--) { s->failed_pc=0x0c08f96cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f96e;
P_0c08f96e: /* original e048, guest PC 0x0c08f96e */
if(!s->budget--) { s->failed_pc=0x0c08f96eu; return 0; }
r[0]=0x00000048u;
goto P_0c08f970;
P_0c08f970: /* original ff37, guest PC 0x0c08f970 */
if(!s->budget--) { s->failed_pc=0x0c08f970u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f972;
P_0c08f972: /* original 9017, guest PC 0x0c08f972 */
if(!s->budget--) { s->failed_pc=0x0c08f972u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f9a4u,2);
goto P_0c08f974;
P_0c08f974: /* original f3e6, guest PC 0x0c08f974 */
if(!s->budget--) { s->failed_pc=0x0c08f974u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f976;
P_0c08f976: /* original e040, guest PC 0x0c08f976 */
if(!s->budget--) { s->failed_pc=0x0c08f976u; return 0; }
r[0]=0x00000040u;
goto P_0c08f978;
P_0c08f978: /* original ff37, guest PC 0x0c08f978 */
if(!s->budget--) { s->failed_pc=0x0c08f978u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f97a;
P_0c08f97a: /* original 9014, guest PC 0x0c08f97a */
if(!s->budget--) { s->failed_pc=0x0c08f97au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f9a6u,2);
goto P_0c08f97c;
P_0c08f97c: /* original a01f, guest PC 0x0c08f97c */
if(!s->budget--) { s->failed_pc=0x0c08f97cu; return 0; }
goto P_0c08f9be;
P_0c08f97e: /* original 0009, guest PC 0x0c08f97e */
if(!s->budget--) { s->failed_pc=0x0c08f97eu; return 0; }
if(!vf3_matrix_family(0x0c08f980u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f980u; return 0; } return 1;
P_0c08f9ac: /* original 9095, guest PC 0x0c08f9ac */
if(!s->budget--) { s->failed_pc=0x0c08f9acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fadau,2);
goto P_0c08f9ae;
P_0c08f9ae: /* original f3e6, guest PC 0x0c08f9ae */
if(!s->budget--) { s->failed_pc=0x0c08f9aeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f9b0;
P_0c08f9b0: /* original e048, guest PC 0x0c08f9b0 */
if(!s->budget--) { s->failed_pc=0x0c08f9b0u; return 0; }
r[0]=0x00000048u;
goto P_0c08f9b2;
P_0c08f9b2: /* original ff37, guest PC 0x0c08f9b2 */
if(!s->budget--) { s->failed_pc=0x0c08f9b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f9b4;
P_0c08f9b4: /* original 9092, guest PC 0x0c08f9b4 */
if(!s->budget--) { s->failed_pc=0x0c08f9b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fadcu,2);
goto P_0c08f9b6;
P_0c08f9b6: /* original f3e6, guest PC 0x0c08f9b6 */
if(!s->budget--) { s->failed_pc=0x0c08f9b6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f9b8;
P_0c08f9b8: /* original e040, guest PC 0x0c08f9b8 */
if(!s->budget--) { s->failed_pc=0x0c08f9b8u; return 0; }
r[0]=0x00000040u;
goto P_0c08f9ba;
P_0c08f9ba: /* original ff37, guest PC 0x0c08f9ba */
if(!s->budget--) { s->failed_pc=0x0c08f9bau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f9bc;
P_0c08f9bc: /* original 908f, guest PC 0x0c08f9bc */
if(!s->budget--) { s->failed_pc=0x0c08f9bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fadeu,2);
goto P_0c08f9be;
P_0c08f9be: /* original fde6, guest PC 0x0c08f9be */
if(!s->budget--) { s->failed_pc=0x0c08f9beu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c08f9c0;
P_0c08f9c0: /* original 7008, guest PC 0x0c08f9c0 */
if(!s->budget--) { s->failed_pc=0x0c08f9c0u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f9c2;
P_0c08f9c2: /* original fee6, guest PC 0x0c08f9c2 */
if(!s->budget--) { s->failed_pc=0x0c08f9c2u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c08f9c4;
P_0c08f9c4: /* original 60b3, guest PC 0x0c08f9c4 */
if(!s->budget--) { s->failed_pc=0x0c08f9c4u; return 0; }
r[0]=r[11];
goto P_0c08f9c6;
P_0c08f9c6: /* original 8801, guest PC 0x0c08f9c6 */
if(!s->budget--) { s->failed_pc=0x0c08f9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08f9c8;
P_0c08f9c8: /* original ff5c, guest PC 0x0c08f9c8 */
if(!s->budget--) { s->failed_pc=0x0c08f9c8u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c08f9ca;
P_0c08f9ca: /* original 8d08, guest PC 0x0c08f9ca */
if(!s->budget--) { s->failed_pc=0x0c08f9cau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
if(cond) { goto P_0c08f9de; }
goto P_0c08f9ce;
P_0c08f9cc: /* original ff41, guest PC 0x0c08f9cc */
if(!s->budget--) { s->failed_pc=0x0c08f9ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c08f9ce;
P_0c08f9ce: /* original e020, guest PC 0x0c08f9ce */
if(!s->budget--) { s->failed_pc=0x0c08f9ceu; return 0; }
r[0]=0x00000020u;
goto P_0c08f9d0;
P_0c08f9d0: /* original d346, guest PC 0x0c08f9d0 */
if(!s->budget--) { s->failed_pc=0x0c08f9d0u; return 0; }
r[3]=read(ram,0x0c08faecu,4);
goto P_0c08f9d2;
P_0c08f9d2: /* original f3f6, guest PC 0x0c08f9d2 */
if(!s->budget--) { s->failed_pc=0x0c08f9d2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f9d4;
P_0c08f9d4: /* original f5fc, guest PC 0x0c08f9d4 */
if(!s->budget--) { s->failed_pc=0x0c08f9d4u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f9d6;
P_0c08f9d6: /* original f4cc, guest PC 0x0c08f9d6 */
if(!s->budget--) { s->failed_pc=0x0c08f9d6u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c08f9d8;
P_0c08f9d8: /* original 430b, guest PC 0x0c08f9d8 */
if(!s->budget--) { s->failed_pc=0x0c08f9d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c08f9dcu;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f9dcu) { target=s->pc; goto dispatch; }
goto P_0c08f9dc;
P_0c08f9da: /* original f431, guest PC 0x0c08f9da */
if(!s->budget--) { s->failed_pc=0x0c08f9dau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08f9dc;
P_0c08f9dc: /* original 6d0f, guest PC 0x0c08f9dc */
if(!s->budget--) { s->failed_pc=0x0c08f9dcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08f9de;
P_0c08f9de: /* original e040, guest PC 0x0c08f9de */
if(!s->budget--) { s->failed_pc=0x0c08f9deu; return 0; }
r[0]=0x00000040u;
goto P_0c08f9e0;
P_0c08f9e0: /* original f5ec, guest PC 0x0c08f9e0 */
if(!s->budget--) { s->failed_pc=0x0c08f9e0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08f9e2;
P_0c08f9e2: /* original f3f6, guest PC 0x0c08f9e2 */
if(!s->budget--) { s->failed_pc=0x0c08f9e2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f9e4;
P_0c08f9e4: /* original e048, guest PC 0x0c08f9e4 */
if(!s->budget--) { s->failed_pc=0x0c08f9e4u; return 0; }
r[0]=0x00000048u;
goto P_0c08f9e6;
P_0c08f9e6: /* original 927b, guest PC 0x0c08f9e6 */
if(!s->budget--) { s->failed_pc=0x0c08f9e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae0u,2);
goto P_0c08f9e8;
P_0c08f9e8: /* original f531, guest PC 0x0c08f9e8 */
if(!s->budget--) { s->failed_pc=0x0c08f9e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c08f9ea;
P_0c08f9ea: /* original d340, guest PC 0x0c08f9ea */
if(!s->budget--) { s->failed_pc=0x0c08f9eau; return 0; }
r[3]=read(ram,0x0c08faecu,4);
goto P_0c08f9ec;
P_0c08f9ec: /* original f4f6, guest PC 0x0c08f9ec */
if(!s->budget--) { s->failed_pc=0x0c08f9ecu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08f9ee;
P_0c08f9ee: /* original 3d2c, guest PC 0x0c08f9ee */
if(!s->budget--) { s->failed_pc=0x0c08f9eeu; return 0; }
r[13]+=r[2];
goto P_0c08f9f0;
P_0c08f9f0: /* original 430b, guest PC 0x0c08f9f0 */
if(!s->budget--) { s->failed_pc=0x0c08f9f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c08f9f4u;
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f9f4u) { target=s->pc; goto dispatch; }
goto P_0c08f9f4;
P_0c08f9f2: /* original f4d1, guest PC 0x0c08f9f2 */
if(!s->budget--) { s->failed_pc=0x0c08f9f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c08f9f4;
P_0c08f9f4: /* original 54ec, guest PC 0x0c08f9f4 */
if(!s->budget--) { s->failed_pc=0x0c08f9f4u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c08f9f6;
P_0c08f9f6: /* original e301, guest PC 0x0c08f9f6 */
if(!s->budget--) { s->failed_pc=0x0c08f9f6u; return 0; }
r[3]=0x00000001u;
goto P_0c08f9f8;
P_0c08f9f8: /* original 650f, guest PC 0x0c08f9f8 */
if(!s->budget--) { s->failed_pc=0x0c08f9f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08f9fa;
P_0c08f9fa: /* original 2348, guest PC 0x0c08f9fa */
if(!s->budget--) { s->failed_pc=0x0c08f9fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c08f9fc;
P_0c08f9fc: /* original c73c, guest PC 0x0c08f9fc */
if(!s->budget--) { s->failed_pc=0x0c08f9fcu; return 0; }
r[0]=code_base|0x0008faf0u;
goto P_0c08f9fe;
P_0c08f9fe: /* original 8d0a, guest PC 0x0c08f9fe */
if(!s->budget--) { s->failed_pc=0x0c08f9feu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[0]);
if(cond) { goto P_0c08fa16; }
goto P_0c08fa02;
P_0c08fa00: /* original f908, guest PC 0x0c08fa00 */
if(!s->budget--) { s->failed_pc=0x0c08fa00u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08fa02;
P_0c08fa02: /* original e310, guest PC 0x0c08fa02 */
if(!s->budget--) { s->failed_pc=0x0c08fa02u; return 0; }
r[3]=0x00000010u;
goto P_0c08fa04;
P_0c08fa04: /* original 2348, guest PC 0x0c08fa04 */
if(!s->budget--) { s->failed_pc=0x0c08fa04u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c08fa06;
P_0c08fa06: /* original 8d06, guest PC 0x0c08fa06 */
if(!s->budget--) { s->failed_pc=0x0c08fa06u; return 0; }
cond=r[17]&1u;
r[5]=r[13];
if(cond) { goto P_0c08fa16; }
goto P_0c08fa0a;
P_0c08fa08: /* original 65d3, guest PC 0x0c08fa08 */
if(!s->budget--) { s->failed_pc=0x0c08fa08u; return 0; }
r[5]=r[13];
goto P_0c08fa0a;
P_0c08fa0a: /* original 906a, guest PC 0x0c08fa0a */
if(!s->budget--) { s->failed_pc=0x0c08fa0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae2u,2);
goto P_0c08fa0c;
P_0c08fa0c: /* original f4e6, guest PC 0x0c08fa0c */
if(!s->budget--) { s->failed_pc=0x0c08fa0cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08fa0e;
P_0c08fa0e: /* original f34c, guest PC 0x0c08fa0e */
if(!s->budget--) { s->failed_pc=0x0c08fa0eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fa10;
P_0c08fa10: /* original f392, guest PC 0x0c08fa10 */
if(!s->budget--) { s->failed_pc=0x0c08fa10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'*');
goto P_0c08fa12;
P_0c08fa12: /* original f33d, guest PC 0x0c08fa12 */
if(!s->budget--) { s->failed_pc=0x0c08fa12u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08fa14;
P_0c08fa14: /* original 055a, guest PC 0x0c08fa14 */
if(!s->budget--) { s->failed_pc=0x0c08fa14u; return 0; }
r[5]=r[53];
goto P_0c08fa16;
P_0c08fa16: /* original 60b3, guest PC 0x0c08fa16 */
if(!s->budget--) { s->failed_pc=0x0c08fa16u; return 0; }
r[0]=r[11];
goto P_0c08fa18;
P_0c08fa18: /* original 8801, guest PC 0x0c08fa18 */
if(!s->budget--) { s->failed_pc=0x0c08fa18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08fa1a;
P_0c08fa1a: /* original 890e, guest PC 0x0c08fa1a */
if(!s->budget--) { s->failed_pc=0x0c08fa1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fa3a; }
goto P_0c08fa1c;
P_0c08fa1c: /* original 66d3, guest PC 0x0c08fa1c */
if(!s->budget--) { s->failed_pc=0x0c08fa1cu; return 0; }
r[6]=r[13];
goto P_0c08fa1e;
P_0c08fa1e: /* original 925f, guest PC 0x0c08fa1e */
if(!s->budget--) { s->failed_pc=0x0c08fa1eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae0u,2);
goto P_0c08fa20;
P_0c08fa20: /* original 3658, guest PC 0x0c08fa20 */
if(!s->budget--) { s->failed_pc=0x0c08fa20u; return 0; }
r[6]-=r[5];
goto P_0c08fa22;
P_0c08fa22: /* original d134, guest PC 0x0c08fa22 */
if(!s->budget--) { s->failed_pc=0x0c08fa22u; return 0; }
r[1]=read(ram,0x0c08faf4u,4);
goto P_0c08fa24;
P_0c08fa24: /* original 362c, guest PC 0x0c08fa24 */
if(!s->budget--) { s->failed_pc=0x0c08fa24u; return 0; }
r[6]+=r[2];
goto P_0c08fa26;
P_0c08fa26: /* original 6743, guest PC 0x0c08fa26 */
if(!s->budget--) { s->failed_pc=0x0c08fa26u; return 0; }
r[7]=r[4];
goto P_0c08fa28;
P_0c08fa28: /* original 666f, guest PC 0x0c08fa28 */
if(!s->budget--) { s->failed_pc=0x0c08fa28u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08fa2a;
P_0c08fa2a: /* original e3f7, guest PC 0x0c08fa2a */
if(!s->budget--) { s->failed_pc=0x0c08fa2au; return 0; }
r[3]=0xfffffff7u;
goto P_0c08fa2c;
P_0c08fa2c: /* original 2618, guest PC 0x0c08fa2c */
if(!s->budget--) { s->failed_pc=0x0c08fa2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c08fa2e;
P_0c08fa2e: /* original 2439, guest PC 0x0c08fa2e */
if(!s->budget--) { s->failed_pc=0x0c08fa2eu; return 0; }
r[4]&=r[3];
goto P_0c08fa30;
P_0c08fa30: /* original 8903, guest PC 0x0c08fa30 */
if(!s->budget--) { s->failed_pc=0x0c08fa30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fa3a; }
goto P_0c08fa32;
P_0c08fa32: /* original 9357, guest PC 0x0c08fa32 */
if(!s->budget--) { s->failed_pc=0x0c08fa32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae4u,2);
goto P_0c08fa34;
P_0c08fa34: /* original e208, guest PC 0x0c08fa34 */
if(!s->budget--) { s->failed_pc=0x0c08fa34u; return 0; }
r[2]=0x00000008u;
goto P_0c08fa36;
P_0c08fa36: /* original 242b, guest PC 0x0c08fa36 */
if(!s->budget--) { s->failed_pc=0x0c08fa36u; return 0; }
r[4]|=r[2];
goto P_0c08fa38;
P_0c08fa38: /* original 2d3a, guest PC 0x0c08fa38 */
if(!s->budget--) { s->failed_pc=0x0c08fa38u; return 0; }
r[13]^=r[3];
goto P_0c08fa3a;
P_0c08fa3a: /* original 9052, guest PC 0x0c08fa3a */
if(!s->budget--) { s->failed_pc=0x0c08fa3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae2u,2);
goto P_0c08fa3c;
P_0c08fa3c: /* original 6853, guest PC 0x0c08fa3c */
if(!s->budget--) { s->failed_pc=0x0c08fa3cu; return 0; }
r[8]=r[5];
goto P_0c08fa3e;
P_0c08fa3e: /* original e610, guest PC 0x0c08fa3e */
if(!s->budget--) { s->failed_pc=0x0c08fa3eu; return 0; }
r[6]=0x00000010u;
goto P_0c08fa40;
P_0c08fa40: /* original f3e6, guest PC 0x0c08fa40 */
if(!s->budget--) { s->failed_pc=0x0c08fa40u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08fa42;
P_0c08fa42: /* original 7004, guest PC 0x0c08fa42 */
if(!s->budget--) { s->failed_pc=0x0c08fa42u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fa44;
P_0c08fa44: /* original f4e6, guest PC 0x0c08fa44 */
if(!s->budget--) { s->failed_pc=0x0c08fa44u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08fa46;
P_0c08fa46: /* original 60b3, guest PC 0x0c08fa46 */
if(!s->budget--) { s->failed_pc=0x0c08fa46u; return 0; }
r[0]=r[11];
goto P_0c08fa48;
P_0c08fa48: /* original f392, guest PC 0x0c08fa48 */
if(!s->budget--) { s->failed_pc=0x0c08fa48u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'*');
goto P_0c08fa4a;
P_0c08fa4a: /* original 8801, guest PC 0x0c08fa4a */
if(!s->budget--) { s->failed_pc=0x0c08fa4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08fa4c;
P_0c08fa4c: /* original f33d, guest PC 0x0c08fa4c */
if(!s->budget--) { s->failed_pc=0x0c08fa4cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08fa4e;
P_0c08fa4e: /* original 055a, guest PC 0x0c08fa4e */
if(!s->budget--) { s->failed_pc=0x0c08fa4eu; return 0; }
r[5]=r[53];
goto P_0c08fa50;
P_0c08fa50: /* original 8d0b, guest PC 0x0c08fa50 */
if(!s->budget--) { s->failed_pc=0x0c08fa50u; return 0; }
cond=r[17]&1u;
r[6]&=r[4];
if(cond) { goto P_0c08fa6a; }
goto P_0c08fa54;
P_0c08fa52: /* original 2649, guest PC 0x0c08fa52 */
if(!s->budget--) { s->failed_pc=0x0c08fa52u; return 0; }
r[6]&=r[4];
goto P_0c08fa54;
P_0c08fa54: /* original 2668, guest PC 0x0c08fa54 */
if(!s->budget--) { s->failed_pc=0x0c08fa54u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c08fa56;
P_0c08fa56: /* original 8b08, guest PC 0x0c08fa56 */
if(!s->budget--) { s->failed_pc=0x0c08fa56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fa6a; }
goto P_0c08fa58;
P_0c08fa58: /* original e308, guest PC 0x0c08fa58 */
if(!s->budget--) { s->failed_pc=0x0c08fa58u; return 0; }
r[3]=0x00000008u;
goto P_0c08fa5a;
P_0c08fa5a: /* original 274a, guest PC 0x0c08fa5a */
if(!s->budget--) { s->failed_pc=0x0c08fa5au; return 0; }
r[7]^=r[4];
goto P_0c08fa5c;
P_0c08fa5c: /* original 2738, guest PC 0x0c08fa5c */
if(!s->budget--) { s->failed_pc=0x0c08fa5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c08fa5e;
P_0c08fa5e: /* original 8904, guest PC 0x0c08fa5e */
if(!s->budget--) { s->failed_pc=0x0c08fa5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fa6a; }
goto P_0c08fa60;
P_0c08fa60: /* original 6383, guest PC 0x0c08fa60 */
if(!s->budget--) { s->failed_pc=0x0c08fa60u; return 0; }
r[3]=r[8];
goto P_0c08fa62;
P_0c08fa62: /* original 3588, guest PC 0x0c08fa62 */
if(!s->budget--) { s->failed_pc=0x0c08fa62u; return 0; }
r[5]-=r[8];
goto P_0c08fa64;
P_0c08fa64: /* original 3358, guest PC 0x0c08fa64 */
if(!s->budget--) { s->failed_pc=0x0c08fa64u; return 0; }
r[3]-=r[5];
goto P_0c08fa66;
P_0c08fa66: /* original f44d, guest PC 0x0c08fa66 */
if(!s->budget--) { s->failed_pc=0x0c08fa66u; return 0; }
fr[4]^=0x80000000u;
goto P_0c08fa68;
P_0c08fa68: /* original 6533, guest PC 0x0c08fa68 */
if(!s->budget--) { s->failed_pc=0x0c08fa68u; return 0; }
r[5]=r[3];
goto P_0c08fa6a;
P_0c08fa6a: /* original 903c, guest PC 0x0c08fa6a */
if(!s->budget--) { s->failed_pc=0x0c08fa6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae6u,2);
goto P_0c08fa6c;
P_0c08fa6c: /* original 67d3, guest PC 0x0c08fa6c */
if(!s->budget--) { s->failed_pc=0x0c08fa6cu; return 0; }
r[7]=r[13];
goto P_0c08fa6e;
P_0c08fa6e: /* original 3758, guest PC 0x0c08fa6e */
if(!s->budget--) { s->failed_pc=0x0c08fa6eu; return 0; }
r[7]-=r[5];
goto P_0c08fa70;
P_0c08fa70: /* original f6e6, guest PC 0x0c08fa70 */
if(!s->budget--) { s->failed_pc=0x0c08fa70u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08fa72;
P_0c08fa72: /* original 7004, guest PC 0x0c08fa72 */
if(!s->budget--) { s->failed_pc=0x0c08fa72u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fa74;
P_0c08fa74: /* original f3e6, guest PC 0x0c08fa74 */
if(!s->budget--) { s->failed_pc=0x0c08fa74u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08fa76;
P_0c08fa76: /* original e04c, guest PC 0x0c08fa76 */
if(!s->budget--) { s->failed_pc=0x0c08fa76u; return 0; }
r[0]=0x0000004cu;
goto P_0c08fa78;
P_0c08fa78: /* original 677f, guest PC 0x0c08fa78 */
if(!s->budget--) { s->failed_pc=0x0c08fa78u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c08fa7a;
P_0c08fa7a: /* original ff37, guest PC 0x0c08fa7a */
if(!s->budget--) { s->failed_pc=0x0c08fa7au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fa7c;
P_0c08fa7c: /* original 9034, guest PC 0x0c08fa7c */
if(!s->budget--) { s->failed_pc=0x0c08fa7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fae8u,2);
goto P_0c08fa7e;
P_0c08fa7e: /* original fde6, guest PC 0x0c08fa7e */
if(!s->budget--) { s->failed_pc=0x0c08fa7eu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c08fa80;
P_0c08fa80: /* original 7004, guest PC 0x0c08fa80 */
if(!s->budget--) { s->failed_pc=0x0c08fa80u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fa82;
P_0c08fa82: /* original f8e6, guest PC 0x0c08fa82 */
if(!s->budget--) { s->failed_pc=0x0c08fa82u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c08fa84;
P_0c08fa84: /* original 7004, guest PC 0x0c08fa84 */
if(!s->budget--) { s->failed_pc=0x0c08fa84u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fa86;
P_0c08fa86: /* original f3e6, guest PC 0x0c08fa86 */
if(!s->budget--) { s->failed_pc=0x0c08fa86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08fa88;
P_0c08fa88: /* original e03c, guest PC 0x0c08fa88 */
if(!s->budget--) { s->failed_pc=0x0c08fa88u; return 0; }
r[0]=0x0000003cu;
goto P_0c08fa8a;
P_0c08fa8a: /* original ff37, guest PC 0x0c08fa8a */
if(!s->budget--) { s->failed_pc=0x0c08fa8au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fa8c;
P_0c08fa8c: /* original 902d, guest PC 0x0c08fa8c */
if(!s->budget--) { s->failed_pc=0x0c08fa8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08faeau,2);
goto P_0c08fa8e;
P_0c08fa8e: /* original f3e6, guest PC 0x0c08fa8e */
if(!s->budget--) { s->failed_pc=0x0c08fa8eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08fa90;
P_0c08fa90: /* original e044, guest PC 0x0c08fa90 */
if(!s->budget--) { s->failed_pc=0x0c08fa90u; return 0; }
r[0]=0x00000044u;
goto P_0c08fa92;
P_0c08fa92: /* original ff37, guest PC 0x0c08fa92 */
if(!s->budget--) { s->failed_pc=0x0c08fa92u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fa94;
P_0c08fa94: /* original c718, guest PC 0x0c08fa94 */
if(!s->budget--) { s->failed_pc=0x0c08fa94u; return 0; }
r[0]=code_base|0x0008faf8u;
goto P_0c08fa96;
P_0c08fa96: /* original 475a, guest PC 0x0c08fa96 */
if(!s->budget--) { s->failed_pc=0x0c08fa96u; return 0; }
r[53]=r[7];
goto P_0c08fa98;
P_0c08fa98: /* original fa08, guest PC 0x0c08fa98 */
if(!s->budget--) { s->failed_pc=0x0c08fa98u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08fa9a;
P_0c08fa9a: /* original fb8d, guest PC 0x0c08fa9a */
if(!s->budget--) { s->failed_pc=0x0c08fa9au; return 0; }
fr[11]=0;
goto P_0c08fa9c;
P_0c08fa9c: /* original f32d, guest PC 0x0c08fa9c */
if(!s->budget--) { s->failed_pc=0x0c08fa9cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08fa9e;
P_0c08fa9e: /* original fe3c, guest PC 0x0c08fa9e */
if(!s->budget--) { s->failed_pc=0x0c08fa9eu; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c08faa0;
P_0c08faa0: /* original fea2, guest PC 0x0c08faa0 */
if(!s->budget--) { s->failed_pc=0x0c08faa0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[10],r[18],'*');
goto P_0c08faa2;
P_0c08faa2: /* original f5ec, guest PC 0x0c08faa2 */
if(!s->budget--) { s->failed_pc=0x0c08faa2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08faa4;
P_0c08faa4: /* original f55d, guest PC 0x0c08faa4 */
if(!s->budget--) { s->failed_pc=0x0c08faa4u; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c08faa6;
P_0c08faa6: /* original f75c, guest PC 0x0c08faa6 */
if(!s->budget--) { s->failed_pc=0x0c08faa6u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c08faa8;
P_0c08faa8: /* original f761, guest PC 0x0c08faa8 */
if(!s->budget--) { s->failed_pc=0x0c08faa8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c08faaa;
P_0c08faaa: /* original f27c, guest PC 0x0c08faaa */
if(!s->budget--) { s->failed_pc=0x0c08faaau; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c08faac;
P_0c08faac: /* original e01c, guest PC 0x0c08faac */
if(!s->budget--) { s->failed_pc=0x0c08faacu; return 0; }
r[0]=0x0000001cu;
goto P_0c08faae;
P_0c08faae: /* original f3bc, guest PC 0x0c08faae */
if(!s->budget--) { s->failed_pc=0x0c08faaeu; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c08fab0;
P_0c08fab0: /* original f231, guest PC 0x0c08fab0 */
if(!s->budget--) { s->failed_pc=0x0c08fab0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c08fab2;
P_0c08fab2: /* original f18d, guest PC 0x0c08fab2 */
if(!s->budget--) { s->failed_pc=0x0c08fab2u; return 0; }
fr[1]=0;
goto P_0c08fab4;
P_0c08fab4: /* original f125, guest PC 0x0c08fab4 */
if(!s->budget--) { s->failed_pc=0x0c08fab4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c08fab6;
P_0c08fab6: /* original 8d01, guest PC 0x0c08fab6 */
if(!s->budget--) { s->failed_pc=0x0c08fab6u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,11,r[15]+r[0]);
if(cond) { goto P_0c08fabc; }
goto P_0c08faba;
P_0c08fab8: /* original ffb7, guest PC 0x0c08fab8 */
if(!s->budget--) { s->failed_pc=0x0c08fab8u; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c08faba;
P_0c08faba: /* original f37c, guest PC 0x0c08faba */
if(!s->budget--) { s->failed_pc=0x0c08fabau; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08fabc;
P_0c08fabc: /* original e038, guest PC 0x0c08fabc */
if(!s->budget--) { s->failed_pc=0x0c08fabcu; return 0; }
r[0]=0x00000038u;
goto P_0c08fabe;
P_0c08fabe: /* original ff37, guest PC 0x0c08fabe */
if(!s->budget--) { s->failed_pc=0x0c08fabeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fac0;
P_0c08fac0: /* original e020, guest PC 0x0c08fac0 */
if(!s->budget--) { s->failed_pc=0x0c08fac0u; return 0; }
r[0]=0x00000020u;
goto P_0c08fac2;
P_0c08fac2: /* original f7f6, guest PC 0x0c08fac2 */
if(!s->budget--) { s->failed_pc=0x0c08fac2u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c08fac4;
P_0c08fac4: /* original c70d, guest PC 0x0c08fac4 */
if(!s->budget--) { s->failed_pc=0x0c08fac4u; return 0; }
r[0]=code_base|0x0008fafcu;
goto P_0c08fac6;
P_0c08fac6: /* original f0fc, guest PC 0x0c08fac6 */
if(!s->budget--) { s->failed_pc=0x0c08fac6u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c08fac8;
P_0c08fac8: /* original f7c1, guest PC 0x0c08fac8 */
if(!s->budget--) { s->failed_pc=0x0c08fac8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'-');
goto P_0c08faca;
P_0c08faca: /* original f37c, guest PC 0x0c08faca */
if(!s->budget--) { s->failed_pc=0x0c08facau; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08facc;
P_0c08facc: /* original f732, guest PC 0x0c08facc */
if(!s->budget--) { s->failed_pc=0x0c08faccu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08face;
P_0c08face: /* original f308, guest PC 0x0c08face */
if(!s->budget--) { s->failed_pc=0x0c08faceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08fad0;
P_0c08fad0: /* original f7fe, guest PC 0x0c08fad0 */
if(!s->budget--) { s->failed_pc=0x0c08fad0u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c08fad2;
P_0c08fad2: /* original f375, guest PC 0x0c08fad2 */
if(!s->budget--) { s->failed_pc=0x0c08fad2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c08fad4;
P_0c08fad4: /* original 8b14, guest PC 0x0c08fad4 */
if(!s->budget--) { s->failed_pc=0x0c08fad4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fb00; }
goto P_0c08fad6;
P_0c08fad6: /* original a015, guest PC 0x0c08fad6 */
if(!s->budget--) { s->failed_pc=0x0c08fad6u; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c08fb04;
P_0c08fad8: /* original f2bc, guest PC 0x0c08fad8 */
if(!s->budget--) { s->failed_pc=0x0c08fad8u; return 0; }
vf3_matrix_move(s,2,11);
if(!vf3_matrix_family(0x0c08fadau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08fadau; return 0; } return 1;
P_0c08fb00: /* original f27c, guest PC 0x0c08fb00 */
if(!s->budget--) { s->failed_pc=0x0c08fb00u; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c08fb02;
P_0c08fb02: /* original f27d, guest PC 0x0c08fb02 */
if(!s->budget--) { s->failed_pc=0x0c08fb02u; return 0; }
if(!vf3_fpu_fsrra(fr[2],r[18],&fr[2])) goto unsupported;
goto P_0c08fb04;
P_0c08fb04: /* original f722, guest PC 0x0c08fb04 */
if(!s->budget--) { s->failed_pc=0x0c08fb04u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c08fb06;
P_0c08fb06: /* original c732, guest PC 0x0c08fb06 */
if(!s->budget--) { s->failed_pc=0x0c08fb06u; return 0; }
r[0]=code_base|0x0008fbd0u;
goto P_0c08fb08;
P_0c08fb08: /* original ff08, guest PC 0x0c08fb08 */
if(!s->budget--) { s->failed_pc=0x0c08fb08u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08fb0a;
P_0c08fb0a: /* original f7f5, guest PC 0x0c08fb0a */
if(!s->budget--) { s->failed_pc=0x0c08fb0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[15]))!=0);
goto P_0c08fb0c;
P_0c08fb0c: /* original 8b2c, guest PC 0x0c08fb0c */
if(!s->budget--) { s->failed_pc=0x0c08fb0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fb68; }
goto P_0c08fb0e;
P_0c08fb0e: /* original 67c3, guest PC 0x0c08fb0e */
if(!s->budget--) { s->failed_pc=0x0c08fb0eu; return 0; }
r[7]=r[12];
goto P_0c08fb10;
P_0c08fb10: /* original 27a9, guest PC 0x0c08fb10 */
if(!s->budget--) { s->failed_pc=0x0c08fb10u; return 0; }
r[7]&=r[10];
goto P_0c08fb12;
P_0c08fb12: /* original 2798, guest PC 0x0c08fb12 */
if(!s->budget--) { s->failed_pc=0x0c08fb12u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[9])==0)!=0);
goto P_0c08fb14;
P_0c08fb14: /* original 8928, guest PC 0x0c08fb14 */
if(!s->budget--) { s->failed_pc=0x0c08fb14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fb68; }
goto P_0c08fb16;
P_0c08fb16: /* original 2668, guest PC 0x0c08fb16 */
if(!s->budget--) { s->failed_pc=0x0c08fb16u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c08fb18;
P_0c08fb18: /* original 8b26, guest PC 0x0c08fb18 */
if(!s->budget--) { s->failed_pc=0x0c08fb18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fb68; }
goto P_0c08fb1a;
P_0c08fb1a: /* original 9056, guest PC 0x0c08fb1a */
if(!s->budget--) { s->failed_pc=0x0c08fb1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fbcau,2);
goto P_0c08fb1c;
P_0c08fb1c: /* original d32d, guest PC 0x0c08fb1c */
if(!s->budget--) { s->failed_pc=0x0c08fb1cu; return 0; }
r[3]=read(ram,0x0c08fbd4u,4);
goto P_0c08fb1e;
P_0c08fb1e: /* original 06ee, guest PC 0x0c08fb1e */
if(!s->budget--) { s->failed_pc=0x0c08fb1eu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c08fb20;
P_0c08fb20: /* original e050, guest PC 0x0c08fb20 */
if(!s->budget--) { s->failed_pc=0x0c08fb20u; return 0; }
r[0]=0x00000050u;
goto P_0c08fb22;
P_0c08fb22: /* original 02fe, guest PC 0x0c08fb22 */
if(!s->budget--) { s->failed_pc=0x0c08fb22u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c08fb24;
P_0c08fb24: /* original 2238, guest PC 0x0c08fb24 */
if(!s->budget--) { s->failed_pc=0x0c08fb24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08fb26;
P_0c08fb26: /* original 8f02, guest PC 0x0c08fb26 */
if(!s->budget--) { s->failed_pc=0x0c08fb26u; return 0; }
cond=r[17]&1u;
r[7]=(uint32_t)(int32_t)(int16_t)r[6];
if(!cond) { goto P_0c08fb2e; }
goto P_0c08fb2a;
P_0c08fb28: /* original 676f, guest PC 0x0c08fb28 */
if(!s->budget--) { s->failed_pc=0x0c08fb28u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08fb2a;
P_0c08fb2a: /* original a013, guest PC 0x0c08fb2a */
if(!s->budget--) { s->failed_pc=0x0c08fb2au; return 0; }
r[6]=0x00000000u;
goto P_0c08fb54;
P_0c08fb2c: /* original e600, guest PC 0x0c08fb2c */
if(!s->budget--) { s->failed_pc=0x0c08fb2cu; return 0; }
r[6]=0x00000000u;
goto P_0c08fb2e;
P_0c08fb2e: /* original 2778, guest PC 0x0c08fb2e */
if(!s->budget--) { s->failed_pc=0x0c08fb2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c08fb30;
P_0c08fb30: /* original 8b01, guest PC 0x0c08fb30 */
if(!s->budget--) { s->failed_pc=0x0c08fb30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fb36; }
goto P_0c08fb32;
P_0c08fb32: /* original a00f, guest PC 0x0c08fb32 */
if(!s->budget--) { s->failed_pc=0x0c08fb32u; return 0; }
r[6]=0x00000048u;
goto P_0c08fb54;
P_0c08fb34: /* original e648, guest PC 0x0c08fb34 */
if(!s->budget--) { s->failed_pc=0x0c08fb34u; return 0; }
r[6]=0x00000048u;
goto P_0c08fb36;
P_0c08fb36: /* original 6073, guest PC 0x0c08fb36 */
if(!s->budget--) { s->failed_pc=0x0c08fb36u; return 0; }
r[0]=r[7];
goto P_0c08fb38;
P_0c08fb38: /* original 8801, guest PC 0x0c08fb38 */
if(!s->budget--) { s->failed_pc=0x0c08fb38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08fb3a;
P_0c08fb3a: /* original 890b, guest PC 0x0c08fb3a */
if(!s->budget--) { s->failed_pc=0x0c08fb3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fb54; }
goto P_0c08fb3c;
P_0c08fb3c: /* original 76ff, guest PC 0x0c08fb3c */
if(!s->budget--) { s->failed_pc=0x0c08fb3cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08fb3e;
P_0c08fb3e: /* original 606f, guest PC 0x0c08fb3e */
if(!s->budget--) { s->failed_pc=0x0c08fb3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08fb40;
P_0c08fb40: /* original 8801, guest PC 0x0c08fb40 */
if(!s->budget--) { s->failed_pc=0x0c08fb40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08fb42;
P_0c08fb42: /* original 8b07, guest PC 0x0c08fb42 */
if(!s->budget--) { s->failed_pc=0x0c08fb42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fb54; }
goto P_0c08fb44;
P_0c08fb44: /* original 9042, guest PC 0x0c08fb44 */
if(!s->budget--) { s->failed_pc=0x0c08fb44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fbccu,2);
goto P_0c08fb46;
P_0c08fb46: /* original f3e6, guest PC 0x0c08fb46 */
if(!s->budget--) { s->failed_pc=0x0c08fb46u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08fb48;
P_0c08fb48: /* original e034, guest PC 0x0c08fb48 */
if(!s->budget--) { s->failed_pc=0x0c08fb48u; return 0; }
r[0]=0x00000034u;
goto P_0c08fb4a;
P_0c08fb4a: /* original f535, guest PC 0x0c08fb4a */
if(!s->budget--) { s->failed_pc=0x0c08fb4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c08fb4c;
P_0c08fb4c: /* original 8f02, guest PC 0x0c08fb4c */
if(!s->budget--) { s->failed_pc=0x0c08fb4cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c08fb54; }
goto P_0c08fb50;
P_0c08fb4e: /* original ff37, guest PC 0x0c08fb4e */
if(!s->budget--) { s->failed_pc=0x0c08fb4eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fb50;
P_0c08fb50: /* original e302, guest PC 0x0c08fb50 */
if(!s->budget--) { s->failed_pc=0x0c08fb50u; return 0; }
r[3]=0x00000002u;
goto P_0c08fb52;
P_0c08fb52: /* original 243b, guest PC 0x0c08fb52 */
if(!s->budget--) { s->failed_pc=0x0c08fb52u; return 0; }
r[4]|=r[3];
goto P_0c08fb54;
P_0c08fb54: /* original e302, guest PC 0x0c08fb54 */
if(!s->budget--) { s->failed_pc=0x0c08fb54u; return 0; }
r[3]=0x00000002u;
goto P_0c08fb56;
P_0c08fb56: /* original 9038, guest PC 0x0c08fb56 */
if(!s->budget--) { s->failed_pc=0x0c08fb56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fbcau,2);
goto P_0c08fb58;
P_0c08fb58: /* original 2348, guest PC 0x0c08fb58 */
if(!s->budget--) { s->failed_pc=0x0c08fb58u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c08fb5a;
P_0c08fb5a: /* original 666f, guest PC 0x0c08fb5a */
if(!s->budget--) { s->failed_pc=0x0c08fb5au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08fb5c;
P_0c08fb5c: /* original 8d04, guest PC 0x0c08fb5c */
if(!s->budget--) { s->failed_pc=0x0c08fb5cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[6],4);
if(cond) { goto P_0c08fb68; }
goto P_0c08fb60;
P_0c08fb5e: /* original 0e66, guest PC 0x0c08fb5e */
if(!s->budget--) { s->failed_pc=0x0c08fb5eu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c08fb60;
P_0c08fb60: /* original e038, guest PC 0x0c08fb60 */
if(!s->budget--) { s->failed_pc=0x0c08fb60u; return 0; }
r[0]=0x00000038u;
goto P_0c08fb62;
P_0c08fb62: /* original f5bc, guest PC 0x0c08fb62 */
if(!s->budget--) { s->failed_pc=0x0c08fb62u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c08fb64;
P_0c08fb64: /* original ff57, guest PC 0x0c08fb64 */
if(!s->budget--) { s->failed_pc=0x0c08fb64u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08fb66;
P_0c08fb66: /* original 65d3, guest PC 0x0c08fb66 */
if(!s->budget--) { s->failed_pc=0x0c08fb66u; return 0; }
r[5]=r[13];
goto P_0c08fb68;
P_0c08fb68: /* original e038, guest PC 0x0c08fb68 */
if(!s->budget--) { s->failed_pc=0x0c08fb68u; return 0; }
r[0]=0x00000038u;
goto P_0c08fb6a;
P_0c08fb6a: /* original f7f5, guest PC 0x0c08fb6a */
if(!s->budget--) { s->failed_pc=0x0c08fb6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[15]))!=0);
goto P_0c08fb6c;
P_0c08fb6c: /* original 1e4c, guest PC 0x0c08fb6c */
if(!s->budget--) { s->failed_pc=0x0c08fb6cu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c08fb6e;
P_0c08fb6e: /* original f3f6, guest PC 0x0c08fb6e */
if(!s->budget--) { s->failed_pc=0x0c08fb6eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08fb70;
P_0c08fb70: /* original 902d, guest PC 0x0c08fb70 */
if(!s->budget--) { s->failed_pc=0x0c08fb70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fbceu,2);
goto P_0c08fb72;
P_0c08fb72: /* original 8f65, guest PC 0x0c08fb72 */
if(!s->budget--) { s->failed_pc=0x0c08fb72u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!cond) { goto P_0c08fc40; }
goto P_0c08fb76;
P_0c08fb74: /* original fe37, guest PC 0x0c08fb74 */
if(!s->budget--) { s->failed_pc=0x0c08fb74u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08fb76;
P_0c08fb76: /* original 64c3, guest PC 0x0c08fb76 */
if(!s->budget--) { s->failed_pc=0x0c08fb76u; return 0; }
r[4]=r[12];
goto P_0c08fb78;
P_0c08fb78: /* original 24ab, guest PC 0x0c08fb78 */
if(!s->budget--) { s->failed_pc=0x0c08fb78u; return 0; }
r[4]|=r[10];
goto P_0c08fb7a;
P_0c08fb7a: /* original 2498, guest PC 0x0c08fb7a */
if(!s->budget--) { s->failed_pc=0x0c08fb7au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c08fb7c;
P_0c08fb7c: /* original 8960, guest PC 0x0c08fb7c */
if(!s->budget--) { s->failed_pc=0x0c08fb7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fc40; }
goto P_0c08fb7e;
P_0c08fb7e: /* original f565, guest PC 0x0c08fb7e */
if(!s->budget--) { s->failed_pc=0x0c08fb7eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c08fb80;
P_0c08fb80: /* original 8b5e, guest PC 0x0c08fb80 */
if(!s->budget--) { s->failed_pc=0x0c08fb80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fc40; }
goto P_0c08fb82;
P_0c08fb82: /* original f36c, guest PC 0x0c08fb82 */
if(!s->budget--) { s->failed_pc=0x0c08fb82u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08fb84;
P_0c08fb84: /* original f65c, guest PC 0x0c08fb84 */
if(!s->budget--) { s->failed_pc=0x0c08fb84u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c08fb86;
P_0c08fb86: /* original f631, guest PC 0x0c08fb86 */
if(!s->budget--) { s->failed_pc=0x0c08fb86u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c08fb88;
P_0c08fb88: /* original f28d, guest PC 0x0c08fb88 */
if(!s->budget--) { s->failed_pc=0x0c08fb88u; return 0; }
fr[2]=0;
goto P_0c08fb8a;
P_0c08fb8a: /* original f2e5, guest PC 0x0c08fb8a */
if(!s->budget--) { s->failed_pc=0x0c08fb8au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c08fb8c;
P_0c08fb8c: /* original f76c, guest PC 0x0c08fb8c */
if(!s->budget--) { s->failed_pc=0x0c08fb8cu; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c08fb8e;
P_0c08fb8e: /* original 8f01, guest PC 0x0c08fb8e */
if(!s->budget--) { s->failed_pc=0x0c08fb8eu; return 0; }
cond=r[17]&1u;
fr[7]^=0x80000000u;
if(!cond) { goto P_0c08fb94; }
goto P_0c08fb92;
P_0c08fb90: /* original f74d, guest PC 0x0c08fb90 */
if(!s->budget--) { s->failed_pc=0x0c08fb90u; return 0; }
fr[7]^=0x80000000u;
goto P_0c08fb92;
P_0c08fb92: /* original f67c, guest PC 0x0c08fb92 */
if(!s->budget--) { s->failed_pc=0x0c08fb92u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08fb94;
P_0c08fb94: /* original f641, guest PC 0x0c08fb94 */
if(!s->budget--) { s->failed_pc=0x0c08fb94u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c08fb96;
P_0c08fb96: /* original f74c, guest PC 0x0c08fb96 */
if(!s->budget--) { s->failed_pc=0x0c08fb96u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c08fb98;
P_0c08fb98: /* original f38d, guest PC 0x0c08fb98 */
if(!s->budget--) { s->failed_pc=0x0c08fb98u; return 0; }
fr[3]=0;
goto P_0c08fb9a;
P_0c08fb9a: /* original f762, guest PC 0x0c08fb9a */
if(!s->budget--) { s->failed_pc=0x0c08fb9au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c08fb9c;
P_0c08fb9c: /* original f375, guest PC 0x0c08fb9c */
if(!s->budget--) { s->failed_pc=0x0c08fb9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c08fb9e;
P_0c08fb9e: /* original 8902, guest PC 0x0c08fb9e */
if(!s->budget--) { s->failed_pc=0x0c08fb9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fba6; }
goto P_0c08fba0;
P_0c08fba0: /* original e03c, guest PC 0x0c08fba0 */
if(!s->budget--) { s->failed_pc=0x0c08fba0u; return 0; }
r[0]=0x0000003cu;
goto P_0c08fba2;
P_0c08fba2: /* original a002, guest PC 0x0c08fba2 */
if(!s->budget--) { s->failed_pc=0x0c08fba2u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c08fbaa;
P_0c08fba4: /* original fbf6, guest PC 0x0c08fba4 */
if(!s->budget--) { s->failed_pc=0x0c08fba4u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c08fba6;
P_0c08fba6: /* original e044, guest PC 0x0c08fba6 */
if(!s->budget--) { s->failed_pc=0x0c08fba6u; return 0; }
r[0]=0x00000044u;
goto P_0c08fba8;
P_0c08fba8: /* original fbf6, guest PC 0x0c08fba8 */
if(!s->budget--) { s->failed_pc=0x0c08fba8u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c08fbaa;
P_0c08fbaa: /* original c70b, guest PC 0x0c08fbaa */
if(!s->budget--) { s->failed_pc=0x0c08fbaau; return 0; }
r[0]=code_base|0x0008fbd8u;
goto P_0c08fbac;
P_0c08fbac: /* original f708, guest PC 0x0c08fbac */
if(!s->budget--) { s->failed_pc=0x0c08fbacu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08fbae;
P_0c08fbae: /* original c70b, guest PC 0x0c08fbae */
if(!s->budget--) { s->failed_pc=0x0c08fbaeu; return 0; }
r[0]=code_base|0x0008fbdcu;
goto P_0c08fbb0;
P_0c08fbb0: /* original f308, guest PC 0x0c08fbb0 */
if(!s->budget--) { s->failed_pc=0x0c08fbb0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08fbb2;
P_0c08fbb2: /* original e030, guest PC 0x0c08fbb2 */
if(!s->budget--) { s->failed_pc=0x0c08fbb2u; return 0; }
r[0]=0x00000030u;
goto P_0c08fbb4;
P_0c08fbb4: /* original f672, guest PC 0x0c08fbb4 */
if(!s->budget--) { s->failed_pc=0x0c08fbb4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c08fbb6;
P_0c08fbb6: /* original ff37, guest PC 0x0c08fbb6 */
if(!s->budget--) { s->failed_pc=0x0c08fbb6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fbb8;
P_0c08fbb8: /* original c709, guest PC 0x0c08fbb8 */
if(!s->budget--) { s->failed_pc=0x0c08fbb8u; return 0; }
r[0]=code_base|0x0008fbe0u;
goto P_0c08fbba;
P_0c08fbba: /* original f208, guest PC 0x0c08fbba */
if(!s->budget--) { s->failed_pc=0x0c08fbbau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08fbbc;
P_0c08fbbc: /* original f76c, guest PC 0x0c08fbbc */
if(!s->budget--) { s->failed_pc=0x0c08fbbcu; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c08fbbe;
P_0c08fbbe: /* original f75d, guest PC 0x0c08fbbe */
if(!s->budget--) { s->failed_pc=0x0c08fbbeu; return 0; }
fr[7]&=0x7fffffffu;
goto P_0c08fbc0;
P_0c08fbc0: /* original f275, guest PC 0x0c08fbc0 */
if(!s->budget--) { s->failed_pc=0x0c08fbc0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[7]))!=0);
goto P_0c08fbc2;
P_0c08fbc2: /* original 8f0f, guest PC 0x0c08fbc2 */
if(!s->budget--) { s->failed_pc=0x0c08fbc2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,2,7);
if(!cond) { goto P_0c08fbe4; }
goto P_0c08fbc6;
P_0c08fbc4: /* original f27c, guest PC 0x0c08fbc4 */
if(!s->budget--) { s->failed_pc=0x0c08fbc4u; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c08fbc6;
P_0c08fbc6: /* original a00f, guest PC 0x0c08fbc6 */
if(!s->budget--) { s->failed_pc=0x0c08fbc6u; return 0; }
fr[3]=0;
goto P_0c08fbe8;
P_0c08fbc8: /* original f38d, guest PC 0x0c08fbc8 */
if(!s->budget--) { s->failed_pc=0x0c08fbc8u; return 0; }
fr[3]=0;
if(!vf3_matrix_family(0x0c08fbcau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08fbcau; return 0; } return 1;
P_0c08fbe4: /* original f37c, guest PC 0x0c08fbe4 */
if(!s->budget--) { s->failed_pc=0x0c08fbe4u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08fbe6;
P_0c08fbe6: /* original f37d, guest PC 0x0c08fbe6 */
if(!s->budget--) { s->failed_pc=0x0c08fbe6u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08fbe8;
P_0c08fbe8: /* original f232, guest PC 0x0c08fbe8 */
if(!s->budget--) { s->failed_pc=0x0c08fbe8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08fbea;
P_0c08fbea: /* original f3bc, guest PC 0x0c08fbea */
if(!s->budget--) { s->failed_pc=0x0c08fbeau; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c08fbec;
P_0c08fbec: /* original f17c, guest PC 0x0c08fbec */
if(!s->budget--) { s->failed_pc=0x0c08fbecu; return 0; }
vf3_matrix_move(s,1,7);
goto P_0c08fbee;
P_0c08fbee: /* original e02c, guest PC 0x0c08fbee */
if(!s->budget--) { s->failed_pc=0x0c08fbeeu; return 0; }
r[0]=0x0000002cu;
goto P_0c08fbf0;
P_0c08fbf0: /* original fb2c, guest PC 0x0c08fbf0 */
if(!s->budget--) { s->failed_pc=0x0c08fbf0u; return 0; }
vf3_matrix_move(s,11,2);
goto P_0c08fbf2;
P_0c08fbf2: /* original fb32, guest PC 0x0c08fbf2 */
if(!s->budget--) { s->failed_pc=0x0c08fbf2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'*');
goto P_0c08fbf4;
P_0c08fbf4: /* original f38d, guest PC 0x0c08fbf4 */
if(!s->budget--) { s->failed_pc=0x0c08fbf4u; return 0; }
fr[3]=0;
goto P_0c08fbf6;
P_0c08fbf6: /* original f1b1, guest PC 0x0c08fbf6 */
if(!s->budget--) { s->failed_pc=0x0c08fbf6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'-');
goto P_0c08fbf8;
P_0c08fbf8: /* original f315, guest PC 0x0c08fbf8 */
if(!s->budget--) { s->failed_pc=0x0c08fbf8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c08fbfa;
P_0c08fbfa: /* original 8d01, guest PC 0x0c08fbfa */
if(!s->budget--) { s->failed_pc=0x0c08fbfau; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[15]+r[0]);
if(cond) { goto P_0c08fc00; }
goto P_0c08fbfe;
P_0c08fbfc: /* original ff27, guest PC 0x0c08fbfc */
if(!s->budget--) { s->failed_pc=0x0c08fbfcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08fbfe;
P_0c08fbfe: /* original f7bc, guest PC 0x0c08fbfe */
if(!s->budget--) { s->failed_pc=0x0c08fbfeu; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c08fc00;
P_0c08fc00: /* original f38d, guest PC 0x0c08fc00 */
if(!s->budget--) { s->failed_pc=0x0c08fc00u; return 0; }
fr[3]=0;
goto P_0c08fc02;
P_0c08fc02: /* original f365, guest PC 0x0c08fc02 */
if(!s->budget--) { s->failed_pc=0x0c08fc02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c08fc04;
P_0c08fc04: /* original fb7c, guest PC 0x0c08fc04 */
if(!s->budget--) { s->failed_pc=0x0c08fc04u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c08fc06;
P_0c08fc06: /* original 8d02, guest PC 0x0c08fc06 */
if(!s->budget--) { s->failed_pc=0x0c08fc06u; return 0; }
cond=r[17]&1u;
fr[11]^=0x80000000u;
if(cond) { goto P_0c08fc0e; }
goto P_0c08fc0a;
P_0c08fc08: /* original fb4d, guest PC 0x0c08fc08 */
if(!s->budget--) { s->failed_pc=0x0c08fc08u; return 0; }
fr[11]^=0x80000000u;
goto P_0c08fc0a;
P_0c08fc0a: /* original a001, guest PC 0x0c08fc0a */
if(!s->budget--) { s->failed_pc=0x0c08fc0au; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08fc10;
P_0c08fc0c: /* original f67c, guest PC 0x0c08fc0c */
if(!s->budget--) { s->failed_pc=0x0c08fc0cu; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08fc0e;
P_0c08fc0e: /* original f6bc, guest PC 0x0c08fc0e */
if(!s->budget--) { s->failed_pc=0x0c08fc0eu; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c08fc10;
P_0c08fc10: /* original e030, guest PC 0x0c08fc10 */
if(!s->budget--) { s->failed_pc=0x0c08fc10u; return 0; }
r[0]=0x00000030u;
goto P_0c08fc12;
P_0c08fc12: /* original f28c, guest PC 0x0c08fc12 */
if(!s->budget--) { s->failed_pc=0x0c08fc12u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c08fc14;
P_0c08fc14: /* original f3f6, guest PC 0x0c08fc14 */
if(!s->budget--) { s->failed_pc=0x0c08fc14u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08fc16;
P_0c08fc16: /* original f85c, guest PC 0x0c08fc16 */
if(!s->budget--) { s->failed_pc=0x0c08fc16u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c08fc18;
P_0c08fc18: /* original f822, guest PC 0x0c08fc18 */
if(!s->budget--) { s->failed_pc=0x0c08fc18u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'*');
goto P_0c08fc1a;
P_0c08fc1a: /* original f632, guest PC 0x0c08fc1a */
if(!s->budget--) { s->failed_pc=0x0c08fc1au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c08fc1c;
P_0c08fc1c: /* original f28d, guest PC 0x0c08fc1c */
if(!s->budget--) { s->failed_pc=0x0c08fc1cu; return 0; }
fr[2]=0;
goto P_0c08fc1e;
P_0c08fc1e: /* original f460, guest PC 0x0c08fc1e */
if(!s->budget--) { s->failed_pc=0x0c08fc1eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c08fc20;
P_0c08fc20: /* original f54c, guest PC 0x0c08fc20 */
if(!s->budget--) { s->failed_pc=0x0c08fc20u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c08fc22;
P_0c08fc22: /* original f55d, guest PC 0x0c08fc22 */
if(!s->budget--) { s->failed_pc=0x0c08fc22u; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c08fc24;
P_0c08fc24: /* original f15c, guest PC 0x0c08fc24 */
if(!s->budget--) { s->failed_pc=0x0c08fc24u; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c08fc26;
P_0c08fc26: /* original f181, guest PC 0x0c08fc26 */
if(!s->budget--) { s->failed_pc=0x0c08fc26u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'-');
goto P_0c08fc28;
P_0c08fc28: /* original f215, guest PC 0x0c08fc28 */
if(!s->budget--) { s->failed_pc=0x0c08fc28u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c08fc2a;
P_0c08fc2a: /* original 8900, guest PC 0x0c08fc2a */
if(!s->budget--) { s->failed_pc=0x0c08fc2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fc2e; }
goto P_0c08fc2c;
P_0c08fc2c: /* original f58c, guest PC 0x0c08fc2c */
if(!s->budget--) { s->failed_pc=0x0c08fc2cu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c08fc2e;
P_0c08fc2e: /* original f38d, guest PC 0x0c08fc2e */
if(!s->budget--) { s->failed_pc=0x0c08fc2eu; return 0; }
fr[3]=0;
goto P_0c08fc30;
P_0c08fc30: /* original f345, guest PC 0x0c08fc30 */
if(!s->budget--) { s->failed_pc=0x0c08fc30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c08fc32;
P_0c08fc32: /* original f65c, guest PC 0x0c08fc32 */
if(!s->budget--) { s->failed_pc=0x0c08fc32u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c08fc34;
P_0c08fc34: /* original 8d02, guest PC 0x0c08fc34 */
if(!s->budget--) { s->failed_pc=0x0c08fc34u; return 0; }
cond=r[17]&1u;
fr[6]^=0x80000000u;
if(cond) { goto P_0c08fc3c; }
goto P_0c08fc38;
P_0c08fc36: /* original f64d, guest PC 0x0c08fc36 */
if(!s->budget--) { s->failed_pc=0x0c08fc36u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08fc38;
P_0c08fc38: /* original a009, guest PC 0x0c08fc38 */
if(!s->budget--) { s->failed_pc=0x0c08fc38u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08fc4e;
P_0c08fc3a: /* original f45c, guest PC 0x0c08fc3a */
if(!s->budget--) { s->failed_pc=0x0c08fc3au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08fc3c;
P_0c08fc3c: /* original a007, guest PC 0x0c08fc3c */
if(!s->budget--) { s->failed_pc=0x0c08fc3cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c08fc4e;
P_0c08fc3e: /* original f46c, guest PC 0x0c08fc3e */
if(!s->budget--) { s->failed_pc=0x0c08fc3eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c08fc40;
P_0c08fc40: /* original e04c, guest PC 0x0c08fc40 */
if(!s->budget--) { s->failed_pc=0x0c08fc40u; return 0; }
r[0]=0x0000004cu;
goto P_0c08fc42;
P_0c08fc42: /* original f3f6, guest PC 0x0c08fc42 */
if(!s->budget--) { s->failed_pc=0x0c08fc42u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08fc44;
P_0c08fc44: /* original f632, guest PC 0x0c08fc44 */
if(!s->budget--) { s->failed_pc=0x0c08fc44u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c08fc46;
P_0c08fc46: /* original f565, guest PC 0x0c08fc46 */
if(!s->budget--) { s->failed_pc=0x0c08fc46u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c08fc48;
P_0c08fc48: /* original 8900, guest PC 0x0c08fc48 */
if(!s->budget--) { s->failed_pc=0x0c08fc48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08fc4c; }
goto P_0c08fc4a;
P_0c08fc4a: /* original fdbc, guest PC 0x0c08fc4a */
if(!s->budget--) { s->failed_pc=0x0c08fc4au; return 0; }
vf3_matrix_move(s,13,11);
goto P_0c08fc4c;
P_0c08fc4c: /* original f4d2, guest PC 0x0c08fc4c */
if(!s->budget--) { s->failed_pc=0x0c08fc4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'*');
goto P_0c08fc4e;
P_0c08fc4e: /* original 906a, guest PC 0x0c08fc4e */
if(!s->budget--) { s->failed_pc=0x0c08fc4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fd26u,2);
goto P_0c08fc50;
P_0c08fc50: /* original f28d, guest PC 0x0c08fc50 */
if(!s->budget--) { s->failed_pc=0x0c08fc50u; return 0; }
fr[2]=0;
goto P_0c08fc52;
P_0c08fc52: /* original f5e6, guest PC 0x0c08fc52 */
if(!s->budget--) { s->failed_pc=0x0c08fc52u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08fc54;
P_0c08fc54: /* original f35c, guest PC 0x0c08fc54 */
if(!s->budget--) { s->failed_pc=0x0c08fc54u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08fc56;
P_0c08fc56: /* original f35d, guest PC 0x0c08fc56 */
if(!s->budget--) { s->failed_pc=0x0c08fc56u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c08fc58;
P_0c08fc58: /* original f63c, guest PC 0x0c08fc58 */
if(!s->budget--) { s->failed_pc=0x0c08fc58u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08fc5a;
P_0c08fc5a: /* original f64d, guest PC 0x0c08fc5a */
if(!s->budget--) { s->failed_pc=0x0c08fc5au; return 0; }
fr[6]^=0x80000000u;
goto P_0c08fc5c;
P_0c08fc5c: /* original f265, guest PC 0x0c08fc5c */
if(!s->budget--) { s->failed_pc=0x0c08fc5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[6]))!=0);
goto P_0c08fc5e;
P_0c08fc5e: /* original 8b00, guest PC 0x0c08fc5e */
if(!s->budget--) { s->failed_pc=0x0c08fc5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fc62; }
goto P_0c08fc60;
P_0c08fc60: /* original f45c, guest PC 0x0c08fc60 */
if(!s->budget--) { s->failed_pc=0x0c08fc60u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08fc62;
P_0c08fc62: /* original f34c, guest PC 0x0c08fc62 */
if(!s->budget--) { s->failed_pc=0x0c08fc62u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fc64;
P_0c08fc64: /* original f392, guest PC 0x0c08fc64 */
if(!s->budget--) { s->failed_pc=0x0c08fc64u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'*');
goto P_0c08fc66;
P_0c08fc66: /* original 6ddf, guest PC 0x0c08fc66 */
if(!s->budget--) { s->failed_pc=0x0c08fc66u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08fc68;
P_0c08fc68: /* original 905e, guest PC 0x0c08fc68 */
if(!s->budget--) { s->failed_pc=0x0c08fc68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fd28u,2);
goto P_0c08fc6a;
P_0c08fc6a: /* original f33d, guest PC 0x0c08fc6a */
if(!s->budget--) { s->failed_pc=0x0c08fc6au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08fc6c;
P_0c08fc6c: /* original 045a, guest PC 0x0c08fc6c */
if(!s->budget--) { s->failed_pc=0x0c08fc6cu; return 0; }
r[4]=r[53];
goto P_0c08fc6e;
P_0c08fc6e: /* original 4d5a, guest PC 0x0c08fc6e */
if(!s->budget--) { s->failed_pc=0x0c08fc6eu; return 0; }
r[53]=r[13];
goto P_0c08fc70;
P_0c08fc70: /* original 354c, guest PC 0x0c08fc70 */
if(!s->budget--) { s->failed_pc=0x0c08fc70u; return 0; }
r[5]+=r[4];
goto P_0c08fc72;
P_0c08fc72: /* original f22d, guest PC 0x0c08fc72 */
if(!s->budget--) { s->failed_pc=0x0c08fc72u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c08fc74;
P_0c08fc74: /* original 655f, guest PC 0x0c08fc74 */
if(!s->budget--) { s->failed_pc=0x0c08fc74u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c08fc76;
P_0c08fc76: /* original f52c, guest PC 0x0c08fc76 */
if(!s->budget--) { s->failed_pc=0x0c08fc76u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c08fc78;
P_0c08fc78: /* original f5a2, guest PC 0x0c08fc78 */
if(!s->budget--) { s->failed_pc=0x0c08fc78u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c08fc7a;
P_0c08fc7a: /* original fe57, guest PC 0x0c08fc7a */
if(!s->budget--) { s->failed_pc=0x0c08fc7au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08fc7c;
P_0c08fc7c: /* original 7004, guest PC 0x0c08fc7c */
if(!s->budget--) { s->failed_pc=0x0c08fc7cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08fc7e;
P_0c08fc7e: /* original 455a, guest PC 0x0c08fc7e */
if(!s->budget--) { s->failed_pc=0x0c08fc7eu; return 0; }
r[53]=r[5];
goto P_0c08fc80;
P_0c08fc80: /* original f32d, guest PC 0x0c08fc80 */
if(!s->budget--) { s->failed_pc=0x0c08fc80u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08fc82;
P_0c08fc82: /* original f53c, guest PC 0x0c08fc82 */
if(!s->budget--) { s->failed_pc=0x0c08fc82u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08fc84;
P_0c08fc84: /* original f5a2, guest PC 0x0c08fc84 */
if(!s->budget--) { s->failed_pc=0x0c08fc84u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c08fc86;
P_0c08fc86: /* original fe57, guest PC 0x0c08fc86 */
if(!s->budget--) { s->failed_pc=0x0c08fc86u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08fc88;
P_0c08fc88: /* original c728, guest PC 0x0c08fc88 */
if(!s->budget--) { s->failed_pc=0x0c08fc88u; return 0; }
r[0]=code_base|0x0008fd2cu;
goto P_0c08fc8a;
P_0c08fc8a: /* original f39c, guest PC 0x0c08fc8a */
if(!s->budget--) { s->failed_pc=0x0c08fc8au; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c08fc8c;
P_0c08fc8c: /* original f342, guest PC 0x0c08fc8c */
if(!s->budget--) { s->failed_pc=0x0c08fc8cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08fc8e;
P_0c08fc8e: /* original f33d, guest PC 0x0c08fc8e */
if(!s->budget--) { s->failed_pc=0x0c08fc8eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c08fc90;
P_0c08fc90: /* original ff3a, guest PC 0x0c08fc90 */
if(!s->budget--) { s->failed_pc=0x0c08fc90u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08fc92;
P_0c08fc92: /* original 035a, guest PC 0x0c08fc92 */
if(!s->budget--) { s->failed_pc=0x0c08fc92u; return 0; }
r[3]=r[53];
goto P_0c08fc94;
P_0c08fc94: /* original 633f, guest PC 0x0c08fc94 */
if(!s->budget--) { s->failed_pc=0x0c08fc94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c08fc96;
P_0c08fc96: /* original 6233, guest PC 0x0c08fc96 */
if(!s->budget--) { s->failed_pc=0x0c08fc96u; return 0; }
r[2]=r[3];
goto P_0c08fc98;
P_0c08fc98: /* original 1f31, guest PC 0x0c08fc98 */
if(!s->budget--) { s->failed_pc=0x0c08fc98u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c08fc9a;
P_0c08fc9a: /* original 425a, guest PC 0x0c08fc9a */
if(!s->budget--) { s->failed_pc=0x0c08fc9au; return 0; }
r[53]=r[2];
goto P_0c08fc9c;
P_0c08fc9c: /* original f32d, guest PC 0x0c08fc9c */
if(!s->budget--) { s->failed_pc=0x0c08fc9cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08fc9e;
P_0c08fc9e: /* original f43c, guest PC 0x0c08fc9e */
if(!s->budget--) { s->failed_pc=0x0c08fc9eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08fca0;
P_0c08fca0: /* original f308, guest PC 0x0c08fca0 */
if(!s->budget--) { s->failed_pc=0x0c08fca0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08fca2;
P_0c08fca2: /* original ff3a, guest PC 0x0c08fca2 */
if(!s->budget--) { s->failed_pc=0x0c08fca2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08fca4;
P_0c08fca4: /* original f34c, guest PC 0x0c08fca4 */
if(!s->budget--) { s->failed_pc=0x0c08fca4u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fca6;
P_0c08fca6: /* original f4f8, guest PC 0x0c08fca6 */
if(!s->budget--) { s->failed_pc=0x0c08fca6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c08fca8;
P_0c08fca8: /* original 7f54, guest PC 0x0c08fca8 */
if(!s->budget--) { s->failed_pc=0x0c08fca8u; return 0; }
r[15]+=0x00000054u;
goto P_0c08fcaa;
P_0c08fcaa: /* original 4f26, guest PC 0x0c08fcaa */
if(!s->budget--) { s->failed_pc=0x0c08fcaau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08fcac;
P_0c08fcac: /* original f432, guest PC 0x0c08fcac */
if(!s->budget--) { s->failed_pc=0x0c08fcacu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c08fcae;
P_0c08fcae: /* original 903c, guest PC 0x0c08fcae */
if(!s->budget--) { s->failed_pc=0x0c08fcaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fd2au,2);
goto P_0c08fcb0;
P_0c08fcb0: /* original fe47, guest PC 0x0c08fcb0 */
if(!s->budget--) { s->failed_pc=0x0c08fcb0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08fcb2;
P_0c08fcb2: /* original fcf9, guest PC 0x0c08fcb2 */
if(!s->budget--) { s->failed_pc=0x0c08fcb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fcb4;
P_0c08fcb4: /* original fdf9, guest PC 0x0c08fcb4 */
if(!s->budget--) { s->failed_pc=0x0c08fcb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fcb6;
P_0c08fcb6: /* original fef9, guest PC 0x0c08fcb6 */
if(!s->budget--) { s->failed_pc=0x0c08fcb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fcb8;
P_0c08fcb8: /* original fff9, guest PC 0x0c08fcb8 */
if(!s->budget--) { s->failed_pc=0x0c08fcb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fcba;
P_0c08fcba: /* original 68f6, guest PC 0x0c08fcba */
if(!s->budget--) { s->failed_pc=0x0c08fcbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08fcbc;
P_0c08fcbc: /* original 69f6, guest PC 0x0c08fcbc */
if(!s->budget--) { s->failed_pc=0x0c08fcbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08fcbe;
P_0c08fcbe: /* original 6af6, guest PC 0x0c08fcbe */
if(!s->budget--) { s->failed_pc=0x0c08fcbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08fcc0;
P_0c08fcc0: /* original 6bf6, guest PC 0x0c08fcc0 */
if(!s->budget--) { s->failed_pc=0x0c08fcc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08fcc2;
P_0c08fcc2: /* original 6cf6, guest PC 0x0c08fcc2 */
if(!s->budget--) { s->failed_pc=0x0c08fcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08fcc4;
P_0c08fcc4: /* original 6df6, guest PC 0x0c08fcc4 */
if(!s->budget--) { s->failed_pc=0x0c08fcc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08fcc6;
P_0c08fcc6: /* original 000b, guest PC 0x0c08fcc6 */
if(!s->budget--) { s->failed_pc=0x0c08fcc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08fcc8: /* original 6ef6, guest PC 0x0c08fcc8 */
if(!s->budget--) { s->failed_pc=0x0c08fcc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08fccau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
