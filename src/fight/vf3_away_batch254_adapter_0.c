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
int vf3_away_batch254_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0696b0u: goto P_0c0696b0;
case 0x0c0696b2u: goto P_0c0696b2;
case 0x0c0696b4u: goto P_0c0696b4;
case 0x0c0696b6u: goto P_0c0696b6;
case 0x0c0696b8u: goto P_0c0696b8;
case 0x0c0696bau: goto P_0c0696ba;
case 0x0c0696bcu: goto P_0c0696bc;
case 0x0c0696beu: goto P_0c0696be;
case 0x0c0696c0u: goto P_0c0696c0;
case 0x0c0696c2u: goto P_0c0696c2;
case 0x0c0696c4u: goto P_0c0696c4;
case 0x0c09abc4u: goto P_0c09abc4;
case 0x0c09abc6u: goto P_0c09abc6;
case 0x0c09abc8u: goto P_0c09abc8;
case 0x0c09abcau: goto P_0c09abca;
case 0x0c09abccu: goto P_0c09abcc;
case 0x0c09abceu: goto P_0c09abce;
case 0x0c09abd0u: goto P_0c09abd0;
case 0x0c09abd2u: goto P_0c09abd2;
case 0x0c09abd4u: goto P_0c09abd4;
case 0x0c09abd6u: goto P_0c09abd6;
case 0x0c09abd8u: goto P_0c09abd8;
case 0x0c09abdau: goto P_0c09abda;
case 0x0c09abdcu: goto P_0c09abdc;
case 0x0c09abdeu: goto P_0c09abde;
case 0x0c09abe0u: goto P_0c09abe0;
case 0x0c09abe2u: goto P_0c09abe2;
case 0x0c09abe4u: goto P_0c09abe4;
case 0x0c09abe6u: goto P_0c09abe6;
case 0x0c09abe8u: goto P_0c09abe8;
case 0x0c09abeau: goto P_0c09abea;
case 0x0c09abecu: goto P_0c09abec;
case 0x0c09abeeu: goto P_0c09abee;
case 0x0c09abf0u: goto P_0c09abf0;
case 0x0c09abf2u: goto P_0c09abf2;
case 0x0c09abf4u: goto P_0c09abf4;
case 0x0c09abf6u: goto P_0c09abf6;
case 0x0c09abf8u: goto P_0c09abf8;
case 0x0c09abfau: goto P_0c09abfa;
case 0x0c09abfcu: goto P_0c09abfc;
case 0x0c09abfeu: goto P_0c09abfe;
case 0x0c09ac00u: goto P_0c09ac00;
case 0x0c09ac02u: goto P_0c09ac02;
case 0x0c09ac04u: goto P_0c09ac04;
case 0x0c09fe68u: goto P_0c09fe68;
case 0x0c09fe6au: goto P_0c09fe6a;
case 0x0c09fe6cu: goto P_0c09fe6c;
case 0x0c09fe6eu: goto P_0c09fe6e;
case 0x0c09fe70u: goto P_0c09fe70;
case 0x0c09fe72u: goto P_0c09fe72;
case 0x0c09fe74u: goto P_0c09fe74;
case 0x0c09fe76u: goto P_0c09fe76;
case 0x0c09fe78u: goto P_0c09fe78;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c9910u: goto P_0c0c9910;
case 0x0c0c9912u: goto P_0c0c9912;
case 0x0c0c9914u: goto P_0c0c9914;
case 0x0c0c9916u: goto P_0c0c9916;
case 0x0c0c9918u: goto P_0c0c9918;
case 0x0c0c991au: goto P_0c0c991a;
case 0x0c0c991cu: goto P_0c0c991c;
case 0x0c0c991eu: goto P_0c0c991e;
case 0x0c0c9920u: goto P_0c0c9920;
case 0x0c0c9922u: goto P_0c0c9922;
case 0x0c0c9924u: goto P_0c0c9924;
case 0x0c0c9926u: goto P_0c0c9926;
case 0x0c0c9928u: goto P_0c0c9928;
case 0x0c0c992au: goto P_0c0c992a;
case 0x0c0c992cu: goto P_0c0c992c;
case 0x0c0c992eu: goto P_0c0c992e;
case 0x0c0c9930u: goto P_0c0c9930;
case 0x0c0c9932u: goto P_0c0c9932;
case 0x0c0c9934u: goto P_0c0c9934;
case 0x0c0c9936u: goto P_0c0c9936;
case 0x0c0c9938u: goto P_0c0c9938;
case 0x0c0c993au: goto P_0c0c993a;
case 0x0c0c993cu: goto P_0c0c993c;
case 0x0c0c993eu: goto P_0c0c993e;
case 0x0c0c9940u: goto P_0c0c9940;
case 0x0c0c9942u: goto P_0c0c9942;
case 0x0c0c9944u: goto P_0c0c9944;
case 0x0c0c9946u: goto P_0c0c9946;
case 0x0c0c9948u: goto P_0c0c9948;
case 0x0c0c994au: goto P_0c0c994a;
case 0x0c0c994cu: goto P_0c0c994c;
case 0x0c0c994eu: goto P_0c0c994e;
case 0x0c0c9950u: goto P_0c0c9950;
case 0x0c0c9952u: goto P_0c0c9952;
case 0x0c0c9954u: goto P_0c0c9954;
case 0x0c0c9956u: goto P_0c0c9956;
case 0x0c0c9958u: goto P_0c0c9958;
case 0x0c0c995au: goto P_0c0c995a;
case 0x0c0c995cu: goto P_0c0c995c;
case 0x0c0c995eu: goto P_0c0c995e;
case 0x0c0c9960u: goto P_0c0c9960;
case 0x0c0c9962u: goto P_0c0c9962;
case 0x0c0c9964u: goto P_0c0c9964;
case 0x0c0c9966u: goto P_0c0c9966;
case 0x0c0c9968u: goto P_0c0c9968;
case 0x0c0c996au: goto P_0c0c996a;
case 0x0c0c996cu: goto P_0c0c996c;
case 0x0c0c996eu: goto P_0c0c996e;
case 0x0c0c9970u: goto P_0c0c9970;
case 0x0c0c9972u: goto P_0c0c9972;
case 0x0c0c9974u: goto P_0c0c9974;
case 0x0c0c9976u: goto P_0c0c9976;
case 0x0c0c9978u: goto P_0c0c9978;
case 0x0c0c997au: goto P_0c0c997a;
case 0x0c0c997cu: goto P_0c0c997c;
case 0x0c0c997eu: goto P_0c0c997e;
case 0x0c0c9980u: goto P_0c0c9980;
case 0x0c0c9982u: goto P_0c0c9982;
case 0x0c0c9984u: goto P_0c0c9984;
case 0x0c0c9986u: goto P_0c0c9986;
case 0x0c0c9988u: goto P_0c0c9988;
case 0x0c0c998au: goto P_0c0c998a;
case 0x0c0c998cu: goto P_0c0c998c;
case 0x0c0c99bcu: goto P_0c0c99bc;
case 0x0c0c99beu: goto P_0c0c99be;
case 0x0c0c99c0u: goto P_0c0c99c0;
case 0x0c0c99c2u: goto P_0c0c99c2;
case 0x0c0c99c4u: goto P_0c0c99c4;
case 0x0c0c99c6u: goto P_0c0c99c6;
case 0x0c0c99c8u: goto P_0c0c99c8;
case 0x0c0c99eeu: goto P_0c0c99ee;
case 0x0c0c99f0u: goto P_0c0c99f0;
case 0x0c0c99f2u: goto P_0c0c99f2;
case 0x0c0c99f4u: goto P_0c0c99f4;
case 0x0c0c99f6u: goto P_0c0c99f6;
case 0x0c0c99f8u: goto P_0c0c99f8;
case 0x0c0c99fau: goto P_0c0c99fa;
case 0x0c0c99fcu: goto P_0c0c99fc;
case 0x0c0c99feu: goto P_0c0c99fe;
case 0x0c0c9a00u: goto P_0c0c9a00;
case 0x0c0c9a02u: goto P_0c0c9a02;
case 0x0c0c9a04u: goto P_0c0c9a04;
case 0x0c0c9a06u: goto P_0c0c9a06;
case 0x0c0c9a08u: goto P_0c0c9a08;
case 0x0c0c9a0au: goto P_0c0c9a0a;
case 0x0c0c9a0cu: goto P_0c0c9a0c;
case 0x0c0c9a0eu: goto P_0c0c9a0e;
case 0x0c0c9a10u: goto P_0c0c9a10;
case 0x0c0c9a12u: goto P_0c0c9a12;
case 0x0c0c9a14u: goto P_0c0c9a14;
case 0x0c0c9a16u: goto P_0c0c9a16;
case 0x0c0c9a18u: goto P_0c0c9a18;
case 0x0c0c9a1au: goto P_0c0c9a1a;
case 0x0c0c9a1cu: goto P_0c0c9a1c;
case 0x0c0c9a1eu: goto P_0c0c9a1e;
case 0x0c0c9a20u: goto P_0c0c9a20;
case 0x0c0c9a22u: goto P_0c0c9a22;
case 0x0c0c9a24u: goto P_0c0c9a24;
case 0x0c0c9a26u: goto P_0c0c9a26;
case 0x0c0c9a28u: goto P_0c0c9a28;
case 0x0c0c9a2au: goto P_0c0c9a2a;
case 0x0c0c9a2cu: goto P_0c0c9a2c;
case 0x0c0c9a2eu: goto P_0c0c9a2e;
case 0x0c0c9a30u: goto P_0c0c9a30;
case 0x0c0c9a32u: goto P_0c0c9a32;
case 0x0c0c9a34u: goto P_0c0c9a34;
case 0x0c0c9a36u: goto P_0c0c9a36;
case 0x0c0c9a38u: goto P_0c0c9a38;
case 0x0c0c9a3au: goto P_0c0c9a3a;
case 0x0c0c9a3cu: goto P_0c0c9a3c;
case 0x0c0c9a3eu: goto P_0c0c9a3e;
case 0x0c0c9a40u: goto P_0c0c9a40;
case 0x0c0c9a42u: goto P_0c0c9a42;
case 0x0c0c9a44u: goto P_0c0c9a44;
case 0x0c0c9a46u: goto P_0c0c9a46;
case 0x0c0c9a48u: goto P_0c0c9a48;
case 0x0c0c9a4au: goto P_0c0c9a4a;
case 0x0c0c9a4cu: goto P_0c0c9a4c;
case 0x0c0c9a4eu: goto P_0c0c9a4e;
case 0x0c0c9a50u: goto P_0c0c9a50;
case 0x0c0c9a52u: goto P_0c0c9a52;
case 0x0c0c9a54u: goto P_0c0c9a54;
case 0x0c0c9a56u: goto P_0c0c9a56;
case 0x0c0c9a58u: goto P_0c0c9a58;
case 0x0c0c9a5au: goto P_0c0c9a5a;
case 0x0c0c9a5cu: goto P_0c0c9a5c;
case 0x0c0c9a5eu: goto P_0c0c9a5e;
case 0x0c0c9a60u: goto P_0c0c9a60;
case 0x0c0c9a62u: goto P_0c0c9a62;
case 0x0c0c9a64u: goto P_0c0c9a64;
case 0x0c0c9a66u: goto P_0c0c9a66;
case 0x0c0c9a68u: goto P_0c0c9a68;
case 0x0c0c9a6au: goto P_0c0c9a6a;
case 0x0c0c9a6cu: goto P_0c0c9a6c;
case 0x0c0c9a6eu: goto P_0c0c9a6e;
case 0x0c0c9a70u: goto P_0c0c9a70;
case 0x0c0c9a72u: goto P_0c0c9a72;
case 0x0c0c9a74u: goto P_0c0c9a74;
case 0x0c0c9a76u: goto P_0c0c9a76;
case 0x0c0c9a78u: goto P_0c0c9a78;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0696b0: /* original d642, guest PC 0x0c0696b0 */
if(!s->budget--) { s->failed_pc=0x0c0696b0u; return 0; }
r[6]=read(ram,0x0c0697bcu,4);
goto P_0c0696b2;
P_0c0696b2: /* original 957c, guest PC 0x0c0696b2 */
if(!s->budget--) { s->failed_pc=0x0c0696b2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697aeu,2);
goto P_0c0696b4;
P_0c0696b4: /* original a002, guest PC 0x0c0696b4 */
if(!s->budget--) { s->failed_pc=0x0c0696b4u; return 0; }
r[4]=0x00000000u;
goto P_0c0696bc;
P_0c0696b6: /* original e400, guest PC 0x0c0696b6 */
if(!s->budget--) { s->failed_pc=0x0c0696b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0696b8;
P_0c0696b8: /* original 2642, guest PC 0x0c0696b8 */
if(!s->budget--) { s->failed_pc=0x0c0696b8u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0696ba;
P_0c0696ba: /* original 7604, guest PC 0x0c0696ba */
if(!s->budget--) { s->failed_pc=0x0c0696bau; return 0; }
r[6]+=0x00000004u;
goto P_0c0696bc;
P_0c0696bc: /* original 2558, guest PC 0x0c0696bc */
if(!s->budget--) { s->failed_pc=0x0c0696bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0696be;
P_0c0696be: /* original 8ffb, guest PC 0x0c0696be */
if(!s->budget--) { s->failed_pc=0x0c0696beu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0696b8; }
goto P_0c0696c2;
P_0c0696c0: /* original 75ff, guest PC 0x0c0696c0 */
if(!s->budget--) { s->failed_pc=0x0c0696c0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0696c2;
P_0c0696c2: /* original 000b, guest PC 0x0c0696c2 */
if(!s->budget--) { s->failed_pc=0x0c0696c2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0696c4: /* original 0009, guest PC 0x0c0696c4 */
if(!s->budget--) { s->failed_pc=0x0c0696c4u; return 0; }
if(!vf3_matrix_family(0x0c0696c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0696c6u; return 0; } return 1;
P_0c09abc4: /* original d512, guest PC 0x0c09abc4 */
if(!s->budget--) { s->failed_pc=0x0c09abc4u; return 0; }
r[5]=read(ram,0x0c09ac10u,4);
goto P_0c09abc6;
P_0c09abc6: /* original e620, guest PC 0x0c09abc6 */
if(!s->budget--) { s->failed_pc=0x0c09abc6u; return 0; }
r[6]=0x00000020u;
goto P_0c09abc8;
P_0c09abc8: /* original 845b, guest PC 0x0c09abc8 */
if(!s->budget--) { s->failed_pc=0x0c09abc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c09abca;
P_0c09abca: /* original 640c, guest PC 0x0c09abca */
if(!s->budget--) { s->failed_pc=0x0c09abcau; return 0; }
r[4]=r[0]&255u;
goto P_0c09abcc;
P_0c09abcc: /* original 3463, guest PC 0x0c09abcc */
if(!s->budget--) { s->failed_pc=0x0c09abccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abce;
P_0c09abce: /* original 8b18, guest PC 0x0c09abce */
if(!s->budget--) { s->failed_pc=0x0c09abceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ac02; }
goto P_0c09abd0;
P_0c09abd0: /* original 9019, guest PC 0x0c09abd0 */
if(!s->budget--) { s->failed_pc=0x0c09abd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac06u,2);
goto P_0c09abd2;
P_0c09abd2: /* original 035e, guest PC 0x0c09abd2 */
if(!s->budget--) { s->failed_pc=0x0c09abd2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09abd4;
P_0c09abd4: /* original 2368, guest PC 0x0c09abd4 */
if(!s->budget--) { s->failed_pc=0x0c09abd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09abd6;
P_0c09abd6: /* original 8914, guest PC 0x0c09abd6 */
if(!s->budget--) { s->failed_pc=0x0c09abd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abd8;
P_0c09abd8: /* original 9017, guest PC 0x0c09abd8 */
if(!s->budget--) { s->failed_pc=0x0c09abd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0au,2);
goto P_0c09abda;
P_0c09abda: /* original 9315, guest PC 0x0c09abda */
if(!s->budget--) { s->failed_pc=0x0c09abdau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac08u,2);
goto P_0c09abdc;
P_0c09abdc: /* original 025e, guest PC 0x0c09abdc */
if(!s->budget--) { s->failed_pc=0x0c09abdcu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abde;
P_0c09abde: /* original 2238, guest PC 0x0c09abde */
if(!s->budget--) { s->failed_pc=0x0c09abdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abe0;
P_0c09abe0: /* original 8f05, guest PC 0x0c09abe0 */
if(!s->budget--) { s->failed_pc=0x0c09abe0u; return 0; }
cond=r[17]&1u;
r[7]=0x00000032u;
if(!cond) { goto P_0c09abee; }
goto P_0c09abe4;
P_0c09abe2: /* original e732, guest PC 0x0c09abe2 */
if(!s->budget--) { s->failed_pc=0x0c09abe2u; return 0; }
r[7]=0x00000032u;
goto P_0c09abe4;
P_0c09abe4: /* original 7401, guest PC 0x0c09abe4 */
if(!s->budget--) { s->failed_pc=0x0c09abe4u; return 0; }
r[4]+=0x00000001u;
goto P_0c09abe6;
P_0c09abe6: /* original 3477, guest PC 0x0c09abe6 */
if(!s->budget--) { s->failed_pc=0x0c09abe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c09abe8;
P_0c09abe8: /* original 8b09, guest PC 0x0c09abe8 */
if(!s->budget--) { s->failed_pc=0x0c09abe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09abfe; }
goto P_0c09abea;
P_0c09abea: /* original a008, guest PC 0x0c09abea */
if(!s->budget--) { s->failed_pc=0x0c09abeau; return 0; }
r[4]=r[6];
goto P_0c09abfe;
P_0c09abec: /* original 6463, guest PC 0x0c09abec */
if(!s->budget--) { s->failed_pc=0x0c09abecu; return 0; }
r[4]=r[6];
goto P_0c09abee;
P_0c09abee: /* original 025e, guest PC 0x0c09abee */
if(!s->budget--) { s->failed_pc=0x0c09abeeu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abf0;
P_0c09abf0: /* original 930c, guest PC 0x0c09abf0 */
if(!s->budget--) { s->failed_pc=0x0c09abf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0cu,2);
goto P_0c09abf2;
P_0c09abf2: /* original 2238, guest PC 0x0c09abf2 */
if(!s->budget--) { s->failed_pc=0x0c09abf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abf4;
P_0c09abf4: /* original 8905, guest PC 0x0c09abf4 */
if(!s->budget--) { s->failed_pc=0x0c09abf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abf6;
P_0c09abf6: /* original 74fd, guest PC 0x0c09abf6 */
if(!s->budget--) { s->failed_pc=0x0c09abf6u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c09abf8;
P_0c09abf8: /* original 3463, guest PC 0x0c09abf8 */
if(!s->budget--) { s->failed_pc=0x0c09abf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abfa;
P_0c09abfa: /* original 8900, guest PC 0x0c09abfa */
if(!s->budget--) { s->failed_pc=0x0c09abfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09abfe; }
goto P_0c09abfc;
P_0c09abfc: /* original 6473, guest PC 0x0c09abfc */
if(!s->budget--) { s->failed_pc=0x0c09abfcu; return 0; }
r[4]=r[7];
goto P_0c09abfe;
P_0c09abfe: /* original 6043, guest PC 0x0c09abfe */
if(!s->budget--) { s->failed_pc=0x0c09abfeu; return 0; }
r[0]=r[4];
goto P_0c09ac00;
P_0c09ac00: /* original 805b, guest PC 0x0c09ac00 */
if(!s->budget--) { s->failed_pc=0x0c09ac00u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c09ac02;
P_0c09ac02: /* original 000b, guest PC 0x0c09ac02 */
if(!s->budget--) { s->failed_pc=0x0c09ac02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09ac04: /* original 0009, guest PC 0x0c09ac04 */
if(!s->budget--) { s->failed_pc=0x0c09ac04u; return 0; }
if(!vf3_matrix_family(0x0c09ac06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ac06u; return 0; } return 1;
P_0c09fe68: /* original 2fe6, guest PC 0x0c09fe68 */
if(!s->budget--) { s->failed_pc=0x0c09fe68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6a;
P_0c09fe6a: /* original 2fd6, guest PC 0x0c09fe6a */
if(!s->budget--) { s->failed_pc=0x0c09fe6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6c;
P_0c09fe6c: /* original 2fc6, guest PC 0x0c09fe6c */
if(!s->budget--) { s->failed_pc=0x0c09fe6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6e;
P_0c09fe6e: /* original 2fb6, guest PC 0x0c09fe6e */
if(!s->budget--) { s->failed_pc=0x0c09fe6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe70;
P_0c09fe70: /* original 2fa6, guest PC 0x0c09fe70 */
if(!s->budget--) { s->failed_pc=0x0c09fe70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe72;
P_0c09fe72: /* original 2f96, guest PC 0x0c09fe72 */
if(!s->budget--) { s->failed_pc=0x0c09fe72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe74;
P_0c09fe74: /* original e900, guest PC 0x0c09fe74 */
if(!s->budget--) { s->failed_pc=0x0c09fe74u; return 0; }
r[9]=0x00000000u;
goto P_0c09fe76;
P_0c09fe76: /* original 2f86, guest PC 0x0c09fe76 */
if(!s->budget--) { s->failed_pc=0x0c09fe76u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe78;
P_0c09fe78: /* original e812, guest PC 0x0c09fe78 */
if(!s->budget--) { s->failed_pc=0x0c09fe78u; return 0; }
r[8]=0x00000012u;
goto P_0c09fe7a;
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09fea8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09febau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=code_base|0x0c09feceu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=code_base|0x0c09fedeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fefeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fefeu; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
if(!vf3_matrix_family(0x0c0c66d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d4u; return 0; } return 1;
P_0c0c9910: /* original 2fe6, guest PC 0x0c0c9910 */
if(!s->budget--) { s->failed_pc=0x0c0c9910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9912;
P_0c0c9912: /* original 903f, guest PC 0x0c0c9912 */
if(!s->budget--) { s->failed_pc=0x0c0c9912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9994u,2);
goto P_0c0c9914;
P_0c0c9914: /* original de22, guest PC 0x0c0c9914 */
if(!s->budget--) { s->failed_pc=0x0c0c9914u; return 0; }
r[14]=read(ram,0x0c0c99a0u,4);
goto P_0c0c9916;
P_0c0c9916: /* original d623, guest PC 0x0c0c9916 */
if(!s->budget--) { s->failed_pc=0x0c0c9916u; return 0; }
r[6]=read(ram,0x0c0c99a4u,4);
goto P_0c0c9918;
P_0c0c9918: /* original 05ee, guest PC 0x0c0c9918 */
if(!s->budget--) { s->failed_pc=0x0c0c9918u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c991a;
P_0c0c991a: /* original 903a, guest PC 0x0c0c991a */
if(!s->budget--) { s->failed_pc=0x0c0c991au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9992u,2);
goto P_0c0c991c;
P_0c0c991c: /* original d322, guest PC 0x0c0c991c */
if(!s->budget--) { s->failed_pc=0x0c0c991cu; return 0; }
r[3]=read(ram,0x0c0c99a8u,4);
goto P_0c0c991e;
P_0c0c991e: /* original 4f22, guest PC 0x0c0c991e */
if(!s->budget--) { s->failed_pc=0x0c0c991eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9920;
P_0c0c9920: /* original 046c, guest PC 0x0c0c9920 */
if(!s->budget--) { s->failed_pc=0x0c0c9920u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c9922;
P_0c0c9922: /* original 2358, guest PC 0x0c0c9922 */
if(!s->budget--) { s->failed_pc=0x0c0c9922u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c9924;
P_0c0c9924: /* original 8f0f, guest PC 0x0c0c9924 */
if(!s->budget--) { s->failed_pc=0x0c0c9924u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(!cond) { goto P_0c0c9946; }
goto P_0c0c9928;
P_0c0c9926: /* original e701, guest PC 0x0c0c9926 */
if(!s->budget--) { s->failed_pc=0x0c0c9926u; return 0; }
r[7]=0x00000001u;
goto P_0c0c9928;
P_0c0c9928: /* original d220, guest PC 0x0c0c9928 */
if(!s->budget--) { s->failed_pc=0x0c0c9928u; return 0; }
r[2]=read(ram,0x0c0c99acu,4);
goto P_0c0c992a;
P_0c0c992a: /* original 2258, guest PC 0x0c0c992a */
if(!s->budget--) { s->failed_pc=0x0c0c992au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c992c;
P_0c0c992c: /* original 8b03, guest PC 0x0c0c992c */
if(!s->budget--) { s->failed_pc=0x0c0c992cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9936; }
goto P_0c0c992e;
P_0c0c992e: /* original 9332, guest PC 0x0c0c992e */
if(!s->budget--) { s->failed_pc=0x0c0c992eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9996u,2);
goto P_0c0c9930;
P_0c0c9930: /* original 2538, guest PC 0x0c0c9930 */
if(!s->budget--) { s->failed_pc=0x0c0c9930u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c9932;
P_0c0c9932: /* original 8d46, guest PC 0x0c0c9932 */
if(!s->budget--) { s->failed_pc=0x0c0c9932u; return 0; }
cond=r[17]&1u;
r[7]=0xffffffffu;
if(cond) { goto P_0c0c99c2; }
goto P_0c0c9936;
P_0c0c9934: /* original e7ff, guest PC 0x0c0c9934 */
if(!s->budget--) { s->failed_pc=0x0c0c9934u; return 0; }
r[7]=0xffffffffu;
goto P_0c0c9936;
P_0c0c9936: /* original 902f, guest PC 0x0c0c9936 */
if(!s->budget--) { s->failed_pc=0x0c0c9936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9998u,2);
goto P_0c0c9938;
P_0c0c9938: /* original e303, guest PC 0x0c0c9938 */
if(!s->budget--) { s->failed_pc=0x0c0c9938u; return 0; }
r[3]=0x00000003u;
goto P_0c0c993a;
P_0c0c993a: /* original 0644, guest PC 0x0c0c993a */
if(!s->budget--) { s->failed_pc=0x0c0c993au; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c993c;
P_0c0c993c: /* original 347c, guest PC 0x0c0c993c */
if(!s->budget--) { s->failed_pc=0x0c0c993cu; return 0; }
r[4]+=r[7];
goto P_0c0c993e;
P_0c0c993e: /* original 70ff, guest PC 0x0c0c993e */
if(!s->budget--) { s->failed_pc=0x0c0c993eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9940;
P_0c0c9940: /* original 2439, guest PC 0x0c0c9940 */
if(!s->budget--) { s->failed_pc=0x0c0c9940u; return 0; }
r[4]&=r[3];
goto P_0c0c9942;
P_0c0c9942: /* original a03e, guest PC 0x0c0c9942 */
if(!s->budget--) { s->failed_pc=0x0c0c9942u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c99c2;
P_0c0c9944: /* original 0644, guest PC 0x0c0c9944 */
if(!s->budget--) { s->failed_pc=0x0c0c9944u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c9946;
P_0c0c9946: /* original 3473, guest PC 0x0c0c9946 */
if(!s->budget--) { s->failed_pc=0x0c0c9946u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c0c9948;
P_0c0c9948: /* original 8f0e, guest PC 0x0c0c9948 */
if(!s->budget--) { s->failed_pc=0x0c0c9948u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0c9968; }
goto P_0c0c994c;
P_0c0c994a: /* original e500, guest PC 0x0c0c994a */
if(!s->budget--) { s->failed_pc=0x0c0c994au; return 0; }
r[5]=0x00000000u;
goto P_0c0c994c;
P_0c0c994c: /* original 6043, guest PC 0x0c0c994c */
if(!s->budget--) { s->failed_pc=0x0c0c994cu; return 0; }
r[0]=r[4];
goto P_0c0c994e;
P_0c0c994e: /* original 8801, guest PC 0x0c0c994e */
if(!s->budget--) { s->failed_pc=0x0c0c994eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9950;
P_0c0c9950: /* original 8d0a, guest PC 0x0c0c9950 */
if(!s->budget--) { s->failed_pc=0x0c0c9950u; return 0; }
cond=r[17]&1u;
r[5]=r[7];
if(cond) { goto P_0c0c9968; }
goto P_0c0c9954;
P_0c0c9952: /* original 6573, guest PC 0x0c0c9952 */
if(!s->budget--) { s->failed_pc=0x0c0c9952u; return 0; }
r[5]=r[7];
goto P_0c0c9954;
P_0c0c9954: /* original 6043, guest PC 0x0c0c9954 */
if(!s->budget--) { s->failed_pc=0x0c0c9954u; return 0; }
r[0]=r[4];
goto P_0c0c9956;
P_0c0c9956: /* original 8802, guest PC 0x0c0c9956 */
if(!s->budget--) { s->failed_pc=0x0c0c9956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9958;
P_0c0c9958: /* original 8d06, guest PC 0x0c0c9958 */
if(!s->budget--) { s->failed_pc=0x0c0c9958u; return 0; }
cond=r[17]&1u;
r[5]=0x00000002u;
if(cond) { goto P_0c0c9968; }
goto P_0c0c995c;
P_0c0c995a: /* original e502, guest PC 0x0c0c995a */
if(!s->budget--) { s->failed_pc=0x0c0c995au; return 0; }
r[5]=0x00000002u;
goto P_0c0c995c;
P_0c0c995c: /* original d314, guest PC 0x0c0c995c */
if(!s->budget--) { s->failed_pc=0x0c0c995cu; return 0; }
r[3]=read(ram,0x0c0c99b0u,4);
goto P_0c0c995e;
P_0c0c995e: /* original 430b, guest PC 0x0c0c995e */
if(!s->budget--) { s->failed_pc=0x0c0c995eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9962u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9962u) { target=s->pc; goto dispatch; }
goto P_0c0c9962;
P_0c0c9960: /* original 0009, guest PC 0x0c0c9960 */
if(!s->budget--) { s->failed_pc=0x0c0c9960u; return 0; }
goto P_0c0c9962;
P_0c0c9962: /* original e000, guest PC 0x0c0c9962 */
if(!s->budget--) { s->failed_pc=0x0c0c9962u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9964;
P_0c0c9964: /* original a02d, guest PC 0x0c0c9964 */
if(!s->budget--) { s->failed_pc=0x0c0c9964u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c99c2;
P_0c0c9966: /* original 80eb, guest PC 0x0c0c9966 */
if(!s->budget--) { s->failed_pc=0x0c0c9966u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9968;
P_0c0c9968: /* original 6053, guest PC 0x0c0c9968 */
if(!s->budget--) { s->failed_pc=0x0c0c9968u; return 0; }
r[0]=r[5];
goto P_0c0c996a;
P_0c0c996a: /* original 8800, guest PC 0x0c0c996a */
if(!s->budget--) { s->failed_pc=0x0c0c996au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c996c;
P_0c0c996c: /* original 8905, guest PC 0x0c0c996c */
if(!s->budget--) { s->failed_pc=0x0c0c996cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c997a; }
goto P_0c0c996e;
P_0c0c996e: /* original 8801, guest PC 0x0c0c996e */
if(!s->budget--) { s->failed_pc=0x0c0c996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9970;
P_0c0c9970: /* original 8908, guest PC 0x0c0c9970 */
if(!s->budget--) { s->failed_pc=0x0c0c9970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9984; }
goto P_0c0c9972;
P_0c0c9972: /* original 8802, guest PC 0x0c0c9972 */
if(!s->budget--) { s->failed_pc=0x0c0c9972u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9974;
P_0c0c9974: /* original 8922, guest PC 0x0c0c9974 */
if(!s->budget--) { s->failed_pc=0x0c0c9974u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c99bc; }
goto P_0c0c9976;
P_0c0c9976: /* original a024, guest PC 0x0c0c9976 */
if(!s->budget--) { s->failed_pc=0x0c0c9976u; return 0; }
goto P_0c0c99c2;
P_0c0c9978: /* original 0009, guest PC 0x0c0c9978 */
if(!s->budget--) { s->failed_pc=0x0c0c9978u; return 0; }
goto P_0c0c997a;
P_0c0c997a: /* original d20e, guest PC 0x0c0c997a */
if(!s->budget--) { s->failed_pc=0x0c0c997au; return 0; }
r[2]=read(ram,0x0c0c99b4u,4);
goto P_0c0c997c;
P_0c0c997c: /* original 420b, guest PC 0x0c0c997c */
if(!s->budget--) { s->failed_pc=0x0c0c997cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9980u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9980u) { target=s->pc; goto dispatch; }
goto P_0c0c9980;
P_0c0c997e: /* original 0009, guest PC 0x0c0c997e */
if(!s->budget--) { s->failed_pc=0x0c0c997eu; return 0; }
goto P_0c0c9980;
P_0c0c9980: /* original a01f, guest PC 0x0c0c9980 */
if(!s->budget--) { s->failed_pc=0x0c0c9980u; return 0; }
goto P_0c0c99c2;
P_0c0c9982: /* original 0009, guest PC 0x0c0c9982 */
if(!s->budget--) { s->failed_pc=0x0c0c9982u; return 0; }
goto P_0c0c9984;
P_0c0c9984: /* original d20c, guest PC 0x0c0c9984 */
if(!s->budget--) { s->failed_pc=0x0c0c9984u; return 0; }
r[2]=read(ram,0x0c0c99b8u,4);
goto P_0c0c9986;
P_0c0c9986: /* original 420b, guest PC 0x0c0c9986 */
if(!s->budget--) { s->failed_pc=0x0c0c9986u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c998au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c998au) { target=s->pc; goto dispatch; }
goto P_0c0c998a;
P_0c0c9988: /* original 0009, guest PC 0x0c0c9988 */
if(!s->budget--) { s->failed_pc=0x0c0c9988u; return 0; }
goto P_0c0c998a;
P_0c0c998a: /* original a01a, guest PC 0x0c0c998a */
if(!s->budget--) { s->failed_pc=0x0c0c998au; return 0; }
goto P_0c0c99c2;
P_0c0c998c: /* original 0009, guest PC 0x0c0c998c */
if(!s->budget--) { s->failed_pc=0x0c0c998cu; return 0; }
if(!vf3_matrix_family(0x0c0c998eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c998eu; return 0; } return 1;
P_0c0c99bc: /* original d23a, guest PC 0x0c0c99bc */
if(!s->budget--) { s->failed_pc=0x0c0c99bcu; return 0; }
r[2]=read(ram,0x0c0c9aa8u,4);
goto P_0c0c99be;
P_0c0c99be: /* original 420b, guest PC 0x0c0c99be */
if(!s->budget--) { s->failed_pc=0x0c0c99beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c99c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c99c2u) { target=s->pc; goto dispatch; }
goto P_0c0c99c2;
P_0c0c99c0: /* original 0009, guest PC 0x0c0c99c0 */
if(!s->budget--) { s->failed_pc=0x0c0c99c0u; return 0; }
goto P_0c0c99c2;
P_0c0c99c2: /* original 4f26, guest PC 0x0c0c99c2 */
if(!s->budget--) { s->failed_pc=0x0c0c99c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c99c4;
P_0c0c99c4: /* original d239, guest PC 0x0c0c99c4 */
if(!s->budget--) { s->failed_pc=0x0c0c99c4u; return 0; }
r[2]=read(ram,0x0c0c9aacu,4);
goto P_0c0c99c6;
P_0c0c99c6: /* original 422b, guest PC 0x0c0c99c6 */
if(!s->budget--) { s->failed_pc=0x0c0c99c6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: goto P_0c09abc4;
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
P_0c0c99c8: /* original 6ef6, guest PC 0x0c0c99c8 */
if(!s->budget--) { s->failed_pc=0x0c0c99c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c99cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c99cau; return 0; } return 1;
P_0c0c99ee: /* original 2fe6, guest PC 0x0c0c99ee */
if(!s->budget--) { s->failed_pc=0x0c0c99eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f0;
P_0c0c99f0: /* original 2fd6, guest PC 0x0c0c99f0 */
if(!s->budget--) { s->failed_pc=0x0c0c99f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f2;
P_0c0c99f2: /* original ed00, guest PC 0x0c0c99f2 */
if(!s->budget--) { s->failed_pc=0x0c0c99f2u; return 0; }
r[13]=0x00000000u;
goto P_0c0c99f4;
P_0c0c99f4: /* original 2fc6, guest PC 0x0c0c99f4 */
if(!s->budget--) { s->failed_pc=0x0c0c99f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f6;
P_0c0c99f6: /* original de2f, guest PC 0x0c0c99f6 */
if(!s->budget--) { s->failed_pc=0x0c0c99f6u; return 0; }
r[14]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c99f8;
P_0c0c99f8: /* original 9052, guest PC 0x0c0c99f8 */
if(!s->budget--) { s->failed_pc=0x0c0c99f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c99fa;
P_0c0c99fa: /* original d52d, guest PC 0x0c0c99fa */
if(!s->budget--) { s->failed_pc=0x0c0c99fau; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c99fc;
P_0c0c99fc: /* original 03ec, guest PC 0x0c0c99fc */
if(!s->budget--) { s->failed_pc=0x0c0c99fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c99fe;
P_0c0c99fe: /* original 4f22, guest PC 0x0c0c99fe */
if(!s->budget--) { s->failed_pc=0x0c0c99feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9a00;
P_0c0c9a00: /* original dc2d, guest PC 0x0c0c9a00 */
if(!s->budget--) { s->failed_pc=0x0c0c9a00u; return 0; }
r[12]=read(ram,0x0c0c9ab8u,4);
goto P_0c0c9a02;
P_0c0c9a02: /* original 2338, guest PC 0x0c0c9a02 */
if(!s->budget--) { s->failed_pc=0x0c0c9a02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9a04;
P_0c0c9a04: /* original 7ffc, guest PC 0x0c0c9a04 */
if(!s->budget--) { s->failed_pc=0x0c0c9a04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9a06;
P_0c0c9a06: /* original 2f32, guest PC 0x0c0c9a06 */
if(!s->budget--) { s->failed_pc=0x0c0c9a06u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9a08;
P_0c0c9a08: /* original 904b, guest PC 0x0c0c9a08 */
if(!s->budget--) { s->failed_pc=0x0c0c9a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa2u,2);
goto P_0c0c9a0a;
P_0c0c9a0a: /* original d62c, guest PC 0x0c0c9a0a */
if(!s->budget--) { s->failed_pc=0x0c0c9a0au; return 0; }
r[6]=read(ram,0x0c0c9abcu,4);
goto P_0c0c9a0c;
P_0c0c9a0c: /* original 075e, guest PC 0x0c0c9a0c */
if(!s->budget--) { s->failed_pc=0x0c0c9a0cu; return 0; }
r[7]=read(ram,r[5]+r[0],4);
goto P_0c0c9a0e;
P_0c0c9a0e: /* original 9046, guest PC 0x0c0c9a0e */
if(!s->budget--) { s->failed_pc=0x0c0c9a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9a9eu,2);
goto P_0c0c9a10;
P_0c0c9a10: /* original 04ec, guest PC 0x0c0c9a10 */
if(!s->budget--) { s->failed_pc=0x0c0c9a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a12;
P_0c0c9a12: /* original 8f27, guest PC 0x0c0c9a12 */
if(!s->budget--) { s->failed_pc=0x0c0c9a12u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(!cond) { goto P_0c0c9a64; }
goto P_0c0c9a16;
P_0c0c9a14: /* original 2679, guest PC 0x0c0c9a14 */
if(!s->budget--) { s->failed_pc=0x0c0c9a14u; return 0; }
r[6]&=r[7];
goto P_0c0c9a16;
P_0c0c9a16: /* original 2668, guest PC 0x0c0c9a16 */
if(!s->budget--) { s->failed_pc=0x0c0c9a16u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a18;
P_0c0c9a18: /* original 8b09, guest PC 0x0c0c9a18 */
if(!s->budget--) { s->failed_pc=0x0c0c9a18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a2e; }
goto P_0c0c9a1a;
P_0c0c9a1a: /* original d229, guest PC 0x0c0c9a1a */
if(!s->budget--) { s->failed_pc=0x0c0c9a1au; return 0; }
r[2]=read(ram,0x0c0c9ac0u,4);
goto P_0c0c9a1c;
P_0c0c9a1c: /* original 2728, guest PC 0x0c0c9a1c */
if(!s->budget--) { s->failed_pc=0x0c0c9a1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0c9a1e;
P_0c0c9a1e: /* original 8925, guest PC 0x0c0c9a1e */
if(!s->budget--) { s->failed_pc=0x0c0c9a1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a20;
P_0c0c9a20: /* original 9040, guest PC 0x0c0c9a20 */
if(!s->budget--) { s->failed_pc=0x0c0c9a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa4u,2);
goto P_0c0c9a22;
P_0c0c9a22: /* original e301, guest PC 0x0c0c9a22 */
if(!s->budget--) { s->failed_pc=0x0c0c9a22u; return 0; }
r[3]=0x00000001u;
goto P_0c0c9a24;
P_0c0c9a24: /* original 0e44, guest PC 0x0c0c9a24 */
if(!s->budget--) { s->failed_pc=0x0c0c9a24u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a26;
P_0c0c9a26: /* original 70ff, guest PC 0x0c0c9a26 */
if(!s->budget--) { s->failed_pc=0x0c0c9a26u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9a28;
P_0c0c9a28: /* original 243a, guest PC 0x0c0c9a28 */
if(!s->budget--) { s->failed_pc=0x0c0c9a28u; return 0; }
r[4]^=r[3];
goto P_0c0c9a2a;
P_0c0c9a2a: /* original a01f, guest PC 0x0c0c9a2a */
if(!s->budget--) { s->failed_pc=0x0c0c9a2au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a6c;
P_0c0c9a2c: /* original 0e44, guest PC 0x0c0c9a2c */
if(!s->budget--) { s->failed_pc=0x0c0c9a2cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a2e;
P_0c0c9a2e: /* original 2448, guest PC 0x0c0c9a2e */
if(!s->budget--) { s->failed_pc=0x0c0c9a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9a30;
P_0c0c9a30: /* original 8b1a, guest PC 0x0c0c9a30 */
if(!s->budget--) { s->failed_pc=0x0c0c9a30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a68; }
goto P_0c0c9a32;
P_0c0c9a32: /* original d224, guest PC 0x0c0c9a32 */
if(!s->budget--) { s->failed_pc=0x0c0c9a32u; return 0; }
r[2]=read(ram,0x0c0c9ac4u,4);
goto P_0c0c9a34;
P_0c0c9a34: /* original 420b, guest PC 0x0c0c9a34 */
if(!s->budget--) { s->failed_pc=0x0c0c9a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a38u) { target=s->pc; goto dispatch; }
goto P_0c0c9a38;
P_0c0c9a36: /* original 0009, guest PC 0x0c0c9a36 */
if(!s->budget--) { s->failed_pc=0x0c0c9a36u; return 0; }
goto P_0c0c9a38;
P_0c0c9a38: /* original d323, guest PC 0x0c0c9a38 */
if(!s->budget--) { s->failed_pc=0x0c0c9a38u; return 0; }
r[3]=read(ram,0x0c0c9ac8u,4);
goto P_0c0c9a3a;
P_0c0c9a3a: /* original 430b, guest PC 0x0c0c9a3a */
if(!s->budget--) { s->failed_pc=0x0c0c9a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a3eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a3eu) { target=s->pc; goto dispatch; }
goto P_0c0c9a3e;
P_0c0c9a3c: /* original 0009, guest PC 0x0c0c9a3c */
if(!s->budget--) { s->failed_pc=0x0c0c9a3cu; return 0; }
goto P_0c0c9a3e;
P_0c0c9a3e: /* original 9032, guest PC 0x0c0c9a3e */
if(!s->budget--) { s->failed_pc=0x0c0c9a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa6u,2);
goto P_0c0c9a40;
P_0c0c9a40: /* original 64c3, guest PC 0x0c0c9a40 */
if(!s->budget--) { s->failed_pc=0x0c0c9a40u; return 0; }
r[4]=r[12];
goto P_0c0c9a42;
P_0c0c9a42: /* original e500, guest PC 0x0c0c9a42 */
if(!s->budget--) { s->failed_pc=0x0c0c9a42u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a44;
P_0c0c9a44: /* original 0ed4, guest PC 0x0c0c9a44 */
if(!s->budget--) { s->failed_pc=0x0c0c9a44u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a46;
P_0c0c9a46: /* original 7004, guest PC 0x0c0c9a46 */
if(!s->budget--) { s->failed_pc=0x0c0c9a46u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c9a48;
P_0c0c9a48: /* original 0ed4, guest PC 0x0c0c9a48 */
if(!s->budget--) { s->failed_pc=0x0c0c9a48u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a4a;
P_0c0c9a4a: /* original d320, guest PC 0x0c0c9a4a */
if(!s->budget--) { s->failed_pc=0x0c0c9a4au; return 0; }
r[3]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a4c;
P_0c0c9a4c: /* original 430b, guest PC 0x0c0c9a4c */
if(!s->budget--) { s->failed_pc=0x0c0c9a4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a50u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a50u) { target=s->pc; goto dispatch; }
goto P_0c0c9a50;
P_0c0c9a4e: /* original 7426, guest PC 0x0c0c9a4e */
if(!s->budget--) { s->failed_pc=0x0c0c9a4eu; return 0; }
r[4]+=0x00000026u;
goto P_0c0c9a50;
P_0c0c9a50: /* original d21e, guest PC 0x0c0c9a50 */
if(!s->budget--) { s->failed_pc=0x0c0c9a50u; return 0; }
r[2]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a52;
P_0c0c9a52: /* original 64c3, guest PC 0x0c0c9a52 */
if(!s->budget--) { s->failed_pc=0x0c0c9a52u; return 0; }
r[4]=r[12];
goto P_0c0c9a54;
P_0c0c9a54: /* original e500, guest PC 0x0c0c9a54 */
if(!s->budget--) { s->failed_pc=0x0c0c9a54u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a56;
P_0c0c9a56: /* original 420b, guest PC 0x0c0c9a56 */
if(!s->budget--) { s->failed_pc=0x0c0c9a56u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a5au;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a5au) { target=s->pc; goto dispatch; }
goto P_0c0c9a5a;
P_0c0c9a58: /* original 7429, guest PC 0x0c0c9a58 */
if(!s->budget--) { s->failed_pc=0x0c0c9a58u; return 0; }
r[4]+=0x00000029u;
goto P_0c0c9a5a;
P_0c0c9a5a: /* original 9021, guest PC 0x0c0c9a5a */
if(!s->budget--) { s->failed_pc=0x0c0c9a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c9a5c;
P_0c0c9a5c: /* original 03ec, guest PC 0x0c0c9a5c */
if(!s->budget--) { s->failed_pc=0x0c0c9a5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a5e;
P_0c0c9a5e: /* original 7301, guest PC 0x0c0c9a5e */
if(!s->budget--) { s->failed_pc=0x0c0c9a5eu; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9a60;
P_0c0c9a60: /* original a004, guest PC 0x0c0c9a60 */
if(!s->budget--) { s->failed_pc=0x0c0c9a60u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a6c;
P_0c0c9a62: /* original 0e34, guest PC 0x0c0c9a62 */
if(!s->budget--) { s->failed_pc=0x0c0c9a62u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a64;
P_0c0c9a64: /* original 2668, guest PC 0x0c0c9a64 */
if(!s->budget--) { s->failed_pc=0x0c0c9a64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a66;
P_0c0c9a66: /* original 8901, guest PC 0x0c0c9a66 */
if(!s->budget--) { s->failed_pc=0x0c0c9a66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a68;
P_0c0c9a68: /* original 60d3, guest PC 0x0c0c9a68 */
if(!s->budget--) { s->failed_pc=0x0c0c9a68u; return 0; }
r[0]=r[13];
goto P_0c0c9a6a;
P_0c0c9a6a: /* original 805b, guest PC 0x0c0c9a6a */
if(!s->budget--) { s->failed_pc=0x0c0c9a6au; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9a6c;
P_0c0c9a6c: /* original 7f04, guest PC 0x0c0c9a6c */
if(!s->budget--) { s->failed_pc=0x0c0c9a6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9a6e;
P_0c0c9a6e: /* original d30f, guest PC 0x0c0c9a6e */
if(!s->budget--) { s->failed_pc=0x0c0c9a6eu; return 0; }
r[3]=read(ram,0x0c0c9aacu,4);
goto P_0c0c9a70;
P_0c0c9a70: /* original 4f26, guest PC 0x0c0c9a70 */
if(!s->budget--) { s->failed_pc=0x0c0c9a70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9a72;
P_0c0c9a72: /* original 6cf6, guest PC 0x0c0c9a72 */
if(!s->budget--) { s->failed_pc=0x0c0c9a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9a74;
P_0c0c9a74: /* original 6df6, guest PC 0x0c0c9a74 */
if(!s->budget--) { s->failed_pc=0x0c0c9a74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9a76;
P_0c0c9a76: /* original 432b, guest PC 0x0c0c9a76 */
if(!s->budget--) { s->failed_pc=0x0c0c9a76u; return 0; }
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
P_0c0c9a78: /* original 6ef6, guest PC 0x0c0c9a78 */
if(!s->budget--) { s->failed_pc=0x0c0c9a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9a7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9a7au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
