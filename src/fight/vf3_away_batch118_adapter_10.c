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
int vf3_away_batch118_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07a806u: goto P_0c07a806;
case 0x0c07a808u: goto P_0c07a808;
case 0x0c07a80au: goto P_0c07a80a;
case 0x0c07a80cu: goto P_0c07a80c;
case 0x0c07a80eu: goto P_0c07a80e;
case 0x0c07a810u: goto P_0c07a810;
case 0x0c07a812u: goto P_0c07a812;
case 0x0c07a814u: goto P_0c07a814;
case 0x0c07a816u: goto P_0c07a816;
case 0x0c07a818u: goto P_0c07a818;
case 0x0c07a81au: goto P_0c07a81a;
case 0x0c07a81cu: goto P_0c07a81c;
case 0x0c07a81eu: goto P_0c07a81e;
case 0x0c07a820u: goto P_0c07a820;
case 0x0c07a822u: goto P_0c07a822;
case 0x0c07a824u: goto P_0c07a824;
case 0x0c07a826u: goto P_0c07a826;
case 0x0c07a828u: goto P_0c07a828;
case 0x0c07a82au: goto P_0c07a82a;
case 0x0c07a82cu: goto P_0c07a82c;
case 0x0c07a82eu: goto P_0c07a82e;
case 0x0c07a830u: goto P_0c07a830;
case 0x0c07a832u: goto P_0c07a832;
case 0x0c07a834u: goto P_0c07a834;
case 0x0c07a836u: goto P_0c07a836;
case 0x0c07a838u: goto P_0c07a838;
case 0x0c07a83au: goto P_0c07a83a;
case 0x0c07a83cu: goto P_0c07a83c;
case 0x0c07a83eu: goto P_0c07a83e;
case 0x0c07a840u: goto P_0c07a840;
case 0x0c07a842u: goto P_0c07a842;
case 0x0c07ac28u: goto P_0c07ac28;
case 0x0c07ac2au: goto P_0c07ac2a;
case 0x0c07ac2cu: goto P_0c07ac2c;
case 0x0c07ac2eu: goto P_0c07ac2e;
case 0x0c07ac30u: goto P_0c07ac30;
case 0x0c07ac32u: goto P_0c07ac32;
case 0x0c07ac34u: goto P_0c07ac34;
case 0x0c07ac36u: goto P_0c07ac36;
case 0x0c07ac38u: goto P_0c07ac38;
case 0x0c07ac3au: goto P_0c07ac3a;
case 0x0c07ac3cu: goto P_0c07ac3c;
case 0x0c07ac3eu: goto P_0c07ac3e;
case 0x0c07ac40u: goto P_0c07ac40;
case 0x0c07ac42u: goto P_0c07ac42;
case 0x0c07ac44u: goto P_0c07ac44;
case 0x0c07ac46u: goto P_0c07ac46;
case 0x0c07ac48u: goto P_0c07ac48;
case 0x0c07ac4au: goto P_0c07ac4a;
case 0x0c07ac4cu: goto P_0c07ac4c;
case 0x0c07ac4eu: goto P_0c07ac4e;
case 0x0c07ac50u: goto P_0c07ac50;
case 0x0c07ac52u: goto P_0c07ac52;
case 0x0c07ac54u: goto P_0c07ac54;
case 0x0c07ac56u: goto P_0c07ac56;
case 0x0c07ac58u: goto P_0c07ac58;
case 0x0c07ac5au: goto P_0c07ac5a;
case 0x0c07ac5cu: goto P_0c07ac5c;
case 0x0c07ac5eu: goto P_0c07ac5e;
case 0x0c07ac60u: goto P_0c07ac60;
case 0x0c07ac62u: goto P_0c07ac62;
case 0x0c07ac64u: goto P_0c07ac64;
case 0x0c07ac66u: goto P_0c07ac66;
case 0x0c07ac68u: goto P_0c07ac68;
case 0x0c07ad12u: goto P_0c07ad12;
case 0x0c07ad14u: goto P_0c07ad14;
case 0x0c07ad16u: goto P_0c07ad16;
case 0x0c07ad18u: goto P_0c07ad18;
case 0x0c07ad1au: goto P_0c07ad1a;
case 0x0c07ad1cu: goto P_0c07ad1c;
case 0x0c07ad1eu: goto P_0c07ad1e;
case 0x0c07ad20u: goto P_0c07ad20;
case 0x0c07ad22u: goto P_0c07ad22;
case 0x0c07ad24u: goto P_0c07ad24;
case 0x0c07ad26u: goto P_0c07ad26;
case 0x0c07ad28u: goto P_0c07ad28;
case 0x0c07ad2au: goto P_0c07ad2a;
case 0x0c07ad2cu: goto P_0c07ad2c;
case 0x0c07ad2eu: goto P_0c07ad2e;
case 0x0c07ad30u: goto P_0c07ad30;
case 0x0c07ad32u: goto P_0c07ad32;
case 0x0c07ad34u: goto P_0c07ad34;
case 0x0c07ad36u: goto P_0c07ad36;
case 0x0c07ad38u: goto P_0c07ad38;
case 0x0c07ad3au: goto P_0c07ad3a;
case 0x0c07ad3cu: goto P_0c07ad3c;
case 0x0c07ad3eu: goto P_0c07ad3e;
case 0x0c07ad40u: goto P_0c07ad40;
case 0x0c07ad42u: goto P_0c07ad42;
case 0x0c07ad44u: goto P_0c07ad44;
case 0x0c07ad46u: goto P_0c07ad46;
case 0x0c07ad48u: goto P_0c07ad48;
case 0x0c07ad4au: goto P_0c07ad4a;
case 0x0c07ad4cu: goto P_0c07ad4c;
case 0x0c07ad4eu: goto P_0c07ad4e;
case 0x0c07ad50u: goto P_0c07ad50;
case 0x0c07ad52u: goto P_0c07ad52;
case 0x0c07ad54u: goto P_0c07ad54;
case 0x0c07ad56u: goto P_0c07ad56;
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c09553cu: goto P_0c09553c;
case 0x0c09553eu: goto P_0c09553e;
case 0x0c095540u: goto P_0c095540;
case 0x0c095542u: goto P_0c095542;
case 0x0c095544u: goto P_0c095544;
case 0x0c095546u: goto P_0c095546;
case 0x0c095548u: goto P_0c095548;
case 0x0c09554au: goto P_0c09554a;
case 0x0c09554cu: goto P_0c09554c;
case 0x0c09554eu: goto P_0c09554e;
case 0x0c095550u: goto P_0c095550;
case 0x0c095552u: goto P_0c095552;
case 0x0c095554u: goto P_0c095554;
case 0x0c095556u: goto P_0c095556;
case 0x0c095558u: goto P_0c095558;
case 0x0c09555au: goto P_0c09555a;
case 0x0c09555cu: goto P_0c09555c;
case 0x0c09555eu: goto P_0c09555e;
case 0x0c095560u: goto P_0c095560;
case 0x0c095562u: goto P_0c095562;
case 0x0c095564u: goto P_0c095564;
case 0x0c095566u: goto P_0c095566;
case 0x0c095568u: goto P_0c095568;
case 0x0c09556au: goto P_0c09556a;
case 0x0c09556cu: goto P_0c09556c;
case 0x0c09556eu: goto P_0c09556e;
case 0x0c095570u: goto P_0c095570;
case 0x0c095572u: goto P_0c095572;
case 0x0c095574u: goto P_0c095574;
case 0x0c095576u: goto P_0c095576;
case 0x0c095578u: goto P_0c095578;
case 0x0c09557au: goto P_0c09557a;
case 0x0c09557cu: goto P_0c09557c;
case 0x0c09557eu: goto P_0c09557e;
case 0x0c095580u: goto P_0c095580;
case 0x0c095582u: goto P_0c095582;
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
case 0x0c0968f8u: goto P_0c0968f8;
case 0x0c0968fau: goto P_0c0968fa;
case 0x0c0968fcu: goto P_0c0968fc;
case 0x0c0968feu: goto P_0c0968fe;
case 0x0c096900u: goto P_0c096900;
case 0x0c09690au: goto P_0c09690a;
case 0x0c09690cu: goto P_0c09690c;
case 0x0c09690eu: goto P_0c09690e;
case 0x0c096910u: goto P_0c096910;
case 0x0c096912u: goto P_0c096912;
case 0x0c096944u: goto P_0c096944;
case 0x0c096946u: goto P_0c096946;
case 0x0c096948u: goto P_0c096948;
case 0x0c09694au: goto P_0c09694a;
case 0x0c09694cu: goto P_0c09694c;
case 0x0c09694eu: goto P_0c09694e;
case 0x0c096950u: goto P_0c096950;
case 0x0c096952u: goto P_0c096952;
case 0x0c096954u: goto P_0c096954;
case 0x0c096956u: goto P_0c096956;
case 0x0c096958u: goto P_0c096958;
case 0x0c09695au: goto P_0c09695a;
case 0x0c09695cu: goto P_0c09695c;
case 0x0c09695eu: goto P_0c09695e;
case 0x0c096960u: goto P_0c096960;
case 0x0c096962u: goto P_0c096962;
case 0x0c096964u: goto P_0c096964;
case 0x0c096966u: goto P_0c096966;
case 0x0c096968u: goto P_0c096968;
case 0x0c09696au: goto P_0c09696a;
case 0x0c09696cu: goto P_0c09696c;
case 0x0c09696eu: goto P_0c09696e;
case 0x0c096970u: goto P_0c096970;
case 0x0c096972u: goto P_0c096972;
case 0x0c096974u: goto P_0c096974;
case 0x0c096976u: goto P_0c096976;
case 0x0c096978u: goto P_0c096978;
case 0x0c09697au: goto P_0c09697a;
case 0x0c09697cu: goto P_0c09697c;
case 0x0c09697eu: goto P_0c09697e;
case 0x0c096980u: goto P_0c096980;
case 0x0c096982u: goto P_0c096982;
case 0x0c096984u: goto P_0c096984;
case 0x0c096986u: goto P_0c096986;
case 0x0c096988u: goto P_0c096988;
case 0x0c09698au: goto P_0c09698a;
case 0x0c09698cu: goto P_0c09698c;
case 0x0c09698eu: goto P_0c09698e;
case 0x0c096990u: goto P_0c096990;
case 0x0c096992u: goto P_0c096992;
case 0x0c096994u: goto P_0c096994;
case 0x0c096996u: goto P_0c096996;
case 0x0c096998u: goto P_0c096998;
case 0x0c09699au: goto P_0c09699a;
case 0x0c09699cu: goto P_0c09699c;
case 0x0c09699eu: goto P_0c09699e;
case 0x0c0969a0u: goto P_0c0969a0;
case 0x0c0969a2u: goto P_0c0969a2;
case 0x0c0969a4u: goto P_0c0969a4;
case 0x0c0969a6u: goto P_0c0969a6;
case 0x0c0969a8u: goto P_0c0969a8;
case 0x0c0969aau: goto P_0c0969aa;
case 0x0c0969acu: goto P_0c0969ac;
case 0x0c0969aeu: goto P_0c0969ae;
case 0x0c0969b0u: goto P_0c0969b0;
case 0x0c0969b2u: goto P_0c0969b2;
case 0x0c0969b4u: goto P_0c0969b4;
case 0x0c0969b6u: goto P_0c0969b6;
case 0x0c0969b8u: goto P_0c0969b8;
case 0x0c0969bau: goto P_0c0969ba;
case 0x0c0969bcu: goto P_0c0969bc;
case 0x0c0969beu: goto P_0c0969be;
case 0x0c0969c0u: goto P_0c0969c0;
case 0x0c0969c2u: goto P_0c0969c2;
case 0x0c0969c4u: goto P_0c0969c4;
case 0x0c0969c6u: goto P_0c0969c6;
case 0x0c0969c8u: goto P_0c0969c8;
case 0x0c0969cau: goto P_0c0969ca;
case 0x0c0969ccu: goto P_0c0969cc;
case 0x0c0969ceu: goto P_0c0969ce;
case 0x0c0969d0u: goto P_0c0969d0;
case 0x0c0969d2u: goto P_0c0969d2;
case 0x0c0969d4u: goto P_0c0969d4;
case 0x0c0969d6u: goto P_0c0969d6;
case 0x0c0969d8u: goto P_0c0969d8;
case 0x0c0969dau: goto P_0c0969da;
case 0x0c0969dcu: goto P_0c0969dc;
case 0x0c0969deu: goto P_0c0969de;
case 0x0c0969e0u: goto P_0c0969e0;
case 0x0c0969e2u: goto P_0c0969e2;
case 0x0c0969e4u: goto P_0c0969e4;
case 0x0c0969e6u: goto P_0c0969e6;
case 0x0c0969e8u: goto P_0c0969e8;
case 0x0c0969eau: goto P_0c0969ea;
case 0x0c0969ecu: goto P_0c0969ec;
case 0x0c0969eeu: goto P_0c0969ee;
case 0x0c0969f0u: goto P_0c0969f0;
case 0x0c0969f2u: goto P_0c0969f2;
case 0x0c0969f4u: goto P_0c0969f4;
case 0x0c0969f6u: goto P_0c0969f6;
case 0x0c0969f8u: goto P_0c0969f8;
case 0x0c0969fau: goto P_0c0969fa;
case 0x0c0969fcu: goto P_0c0969fc;
case 0x0c0969feu: goto P_0c0969fe;
case 0x0c096a00u: goto P_0c096a00;
case 0x0c096a02u: goto P_0c096a02;
case 0x0c096a04u: goto P_0c096a04;
case 0x0c096a06u: goto P_0c096a06;
case 0x0c096a08u: goto P_0c096a08;
case 0x0c096a0au: goto P_0c096a0a;
case 0x0c096a0cu: goto P_0c096a0c;
case 0x0c096a0eu: goto P_0c096a0e;
case 0x0c096a10u: goto P_0c096a10;
case 0x0c096a12u: goto P_0c096a12;
case 0x0c096a14u: goto P_0c096a14;
case 0x0c096a16u: goto P_0c096a16;
case 0x0c096a18u: goto P_0c096a18;
case 0x0c096a1au: goto P_0c096a1a;
case 0x0c096a1cu: goto P_0c096a1c;
case 0x0c096a1eu: goto P_0c096a1e;
case 0x0c096a20u: goto P_0c096a20;
case 0x0c096a22u: goto P_0c096a22;
case 0x0c097ff4u: goto P_0c097ff4;
case 0x0c097ff6u: goto P_0c097ff6;
case 0x0c097ff8u: goto P_0c097ff8;
case 0x0c097ffau: goto P_0c097ffa;
case 0x0c097ffcu: goto P_0c097ffc;
case 0x0c097ffeu: goto P_0c097ffe;
case 0x0c098000u: goto P_0c098000;
case 0x0c098002u: goto P_0c098002;
case 0x0c098004u: goto P_0c098004;
case 0x0c098006u: goto P_0c098006;
case 0x0c098008u: goto P_0c098008;
case 0x0c09800au: goto P_0c09800a;
case 0x0c09800cu: goto P_0c09800c;
case 0x0c09800eu: goto P_0c09800e;
case 0x0c098010u: goto P_0c098010;
case 0x0c098012u: goto P_0c098012;
case 0x0c098014u: goto P_0c098014;
case 0x0c098016u: goto P_0c098016;
case 0x0c098018u: goto P_0c098018;
case 0x0c09801au: goto P_0c09801a;
case 0x0c09801cu: goto P_0c09801c;
case 0x0c09801eu: goto P_0c09801e;
case 0x0c098020u: goto P_0c098020;
case 0x0c098022u: goto P_0c098022;
case 0x0c098024u: goto P_0c098024;
case 0x0c098026u: goto P_0c098026;
case 0x0c098028u: goto P_0c098028;
case 0x0c09802au: goto P_0c09802a;
case 0x0c09802cu: goto P_0c09802c;
case 0x0c09802eu: goto P_0c09802e;
case 0x0c098030u: goto P_0c098030;
case 0x0c098032u: goto P_0c098032;
case 0x0c098034u: goto P_0c098034;
case 0x0c098036u: goto P_0c098036;
case 0x0c098038u: goto P_0c098038;
case 0x0c09803au: goto P_0c09803a;
case 0x0c09803cu: goto P_0c09803c;
case 0x0c09803eu: goto P_0c09803e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07a806: /* original 2fe6, guest PC 0x0c07a806 */
if(!s->budget--) { s->failed_pc=0x0c07a806u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a808;
P_0c07a808: /* original 6e53, guest PC 0x0c07a808 */
if(!s->budget--) { s->failed_pc=0x0c07a808u; return 0; }
r[14]=r[5];
goto P_0c07a80a;
P_0c07a80a: /* original 2fd6, guest PC 0x0c07a80a */
if(!s->budget--) { s->failed_pc=0x0c07a80au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a80c;
P_0c07a80c: /* original 6d43, guest PC 0x0c07a80c */
if(!s->budget--) { s->failed_pc=0x0c07a80cu; return 0; }
r[13]=r[4];
goto P_0c07a80e;
P_0c07a80e: /* original 4f22, guest PC 0x0c07a80e */
if(!s->budget--) { s->failed_pc=0x0c07a80eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a810;
P_0c07a810: /* original 5041, guest PC 0x0c07a810 */
if(!s->budget--) { s->failed_pc=0x0c07a810u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a812;
P_0c07a812: /* original 88ff, guest PC 0x0c07a812 */
if(!s->budget--) { s->failed_pc=0x0c07a812u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a814;
P_0c07a814: /* original 8904, guest PC 0x0c07a814 */
if(!s->budget--) { s->failed_pc=0x0c07a814u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a820; }
goto P_0c07a816;
P_0c07a816: /* original 5242, guest PC 0x0c07a816 */
if(!s->budget--) { s->failed_pc=0x0c07a816u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a818;
P_0c07a818: /* original 32ec, guest PC 0x0c07a818 */
if(!s->budget--) { s->failed_pc=0x0c07a818u; return 0; }
r[2]+=r[14];
goto P_0c07a81a;
P_0c07a81a: /* original 1422, guest PC 0x0c07a81a */
if(!s->budget--) { s->failed_pc=0x0c07a81au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c07a81c;
P_0c07a81c: /* original aff8, guest PC 0x0c07a81c */
if(!s->budget--) { s->failed_pc=0x0c07a81cu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a810;
P_0c07a81e: /* original 7410, guest PC 0x0c07a81e */
if(!s->budget--) { s->failed_pc=0x0c07a81eu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a820;
P_0c07a820: /* original d369, guest PC 0x0c07a820 */
if(!s->budget--) { s->failed_pc=0x0c07a820u; return 0; }
r[3]=read(ram,0x0c07a9c8u,4);
goto P_0c07a822;
P_0c07a822: /* original 430b, guest PC 0x0c07a822 */
if(!s->budget--) { s->failed_pc=0x0c07a822u; return 0; }
target=r[3];
r[16]=code_base|0x0c07a826u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a826u) { target=s->pc; goto dispatch; }
goto P_0c07a826;
P_0c07a824: /* original 64d3, guest PC 0x0c07a824 */
if(!s->budget--) { s->failed_pc=0x0c07a824u; return 0; }
r[4]=r[13];
goto P_0c07a826;
P_0c07a826: /* original 64d3, guest PC 0x0c07a826 */
if(!s->budget--) { s->failed_pc=0x0c07a826u; return 0; }
r[4]=r[13];
goto P_0c07a828;
P_0c07a828: /* original 6503, guest PC 0x0c07a828 */
if(!s->budget--) { s->failed_pc=0x0c07a828u; return 0; }
r[5]=r[0];
goto P_0c07a82a;
P_0c07a82a: /* original 5041, guest PC 0x0c07a82a */
if(!s->budget--) { s->failed_pc=0x0c07a82au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a82c;
P_0c07a82c: /* original 88ff, guest PC 0x0c07a82c */
if(!s->budget--) { s->failed_pc=0x0c07a82cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a82e;
P_0c07a82e: /* original 8904, guest PC 0x0c07a82e */
if(!s->budget--) { s->failed_pc=0x0c07a82eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a83a; }
goto P_0c07a830;
P_0c07a830: /* original 5342, guest PC 0x0c07a830 */
if(!s->budget--) { s->failed_pc=0x0c07a830u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c07a832;
P_0c07a832: /* original 33e8, guest PC 0x0c07a832 */
if(!s->budget--) { s->failed_pc=0x0c07a832u; return 0; }
r[3]-=r[14];
goto P_0c07a834;
P_0c07a834: /* original 1432, guest PC 0x0c07a834 */
if(!s->budget--) { s->failed_pc=0x0c07a834u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c07a836;
P_0c07a836: /* original aff8, guest PC 0x0c07a836 */
if(!s->budget--) { s->failed_pc=0x0c07a836u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a82a;
P_0c07a838: /* original 7410, guest PC 0x0c07a838 */
if(!s->budget--) { s->failed_pc=0x0c07a838u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a83a;
P_0c07a83a: /* original 4f26, guest PC 0x0c07a83a */
if(!s->budget--) { s->failed_pc=0x0c07a83au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a83c;
P_0c07a83c: /* original 6053, guest PC 0x0c07a83c */
if(!s->budget--) { s->failed_pc=0x0c07a83cu; return 0; }
r[0]=r[5];
goto P_0c07a83e;
P_0c07a83e: /* original 6df6, guest PC 0x0c07a83e */
if(!s->budget--) { s->failed_pc=0x0c07a83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a840;
P_0c07a840: /* original 000b, guest PC 0x0c07a840 */
if(!s->budget--) { s->failed_pc=0x0c07a840u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a842: /* original 6ef6, guest PC 0x0c07a842 */
if(!s->budget--) { s->failed_pc=0x0c07a842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07a844u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a844u; return 0; } return 1;
P_0c07ac28: /* original 2fe6, guest PC 0x0c07ac28 */
if(!s->budget--) { s->failed_pc=0x0c07ac28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2a;
P_0c07ac2a: /* original 2fd6, guest PC 0x0c07ac2a */
if(!s->budget--) { s->failed_pc=0x0c07ac2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2c;
P_0c07ac2c: /* original 6d53, guest PC 0x0c07ac2c */
if(!s->budget--) { s->failed_pc=0x0c07ac2cu; return 0; }
r[13]=r[5];
goto P_0c07ac2e;
P_0c07ac2e: /* original 4f22, guest PC 0x0c07ac2e */
if(!s->budget--) { s->failed_pc=0x0c07ac2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ac30;
P_0c07ac30: /* original 7ffc, guest PC 0x0c07ac30 */
if(!s->budget--) { s->failed_pc=0x0c07ac30u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ac32;
P_0c07ac32: /* original 2f41, guest PC 0x0c07ac32 */
if(!s->budget--) { s->failed_pc=0x0c07ac32u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c07ac34;
P_0c07ac34: /* original 6ef1, guest PC 0x0c07ac34 */
if(!s->budget--) { s->failed_pc=0x0c07ac34u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[14]=tmp;
goto P_0c07ac36;
P_0c07ac36: /* original d32e, guest PC 0x0c07ac36 */
if(!s->budget--) { s->failed_pc=0x0c07ac36u; return 0; }
r[3]=read(ram,0x0c07acf0u,4);
goto P_0c07ac38;
P_0c07ac38: /* original 6eed, guest PC 0x0c07ac38 */
if(!s->budget--) { s->failed_pc=0x0c07ac38u; return 0; }
r[14]=r[14]&65535u;
goto P_0c07ac3a;
P_0c07ac3a: /* original 430b, guest PC 0x0c07ac3a */
if(!s->budget--) { s->failed_pc=0x0c07ac3au; return 0; }
target=r[3];
r[16]=code_base|0x0c07ac3eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ac3eu) { target=s->pc; goto dispatch; }
goto P_0c07ac3e;
P_0c07ac3c: /* original 64e3, guest PC 0x0c07ac3c */
if(!s->budget--) { s->failed_pc=0x0c07ac3cu; return 0; }
r[4]=r[14];
goto P_0c07ac3e;
P_0c07ac3e: /* original 60e3, guest PC 0x0c07ac3e */
if(!s->budget--) { s->failed_pc=0x0c07ac3eu; return 0; }
r[0]=r[14];
goto P_0c07ac40;
P_0c07ac40: /* original 8838, guest PC 0x0c07ac40 */
if(!s->budget--) { s->failed_pc=0x0c07ac40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000038u)!=0);
goto P_0c07ac42;
P_0c07ac42: /* original 8b02, guest PC 0x0c07ac42 */
if(!s->budget--) { s->failed_pc=0x0c07ac42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ac4a; }
goto P_0c07ac44;
P_0c07ac44: /* original d42b, guest PC 0x0c07ac44 */
if(!s->budget--) { s->failed_pc=0x0c07ac44u; return 0; }
r[4]=read(ram,0x0c07acf4u,4);
goto P_0c07ac46;
P_0c07ac46: /* original a002, guest PC 0x0c07ac46 */
if(!s->budget--) { s->failed_pc=0x0c07ac46u; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac48: /* original 65d3, guest PC 0x0c07ac48 */
if(!s->budget--) { s->failed_pc=0x0c07ac48u; return 0; }
r[5]=r[13];
goto P_0c07ac4a;
P_0c07ac4a: /* original d42b, guest PC 0x0c07ac4a */
if(!s->budget--) { s->failed_pc=0x0c07ac4au; return 0; }
r[4]=read(ram,0x0c07acf8u,4);
goto P_0c07ac4c;
P_0c07ac4c: /* original 65d3, guest PC 0x0c07ac4c */
if(!s->budget--) { s->failed_pc=0x0c07ac4cu; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac4e: /* original bdda, guest PC 0x0c07ac4e */
if(!s->budget--) { s->failed_pc=0x0c07ac4eu; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07ac52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ac52u) { target=s->pc; goto dispatch; }
goto P_0c07ac52;
P_0c07ac50: /* original 0009, guest PC 0x0c07ac50 */
if(!s->budget--) { s->failed_pc=0x0c07ac50u; return 0; }
goto P_0c07ac52;
P_0c07ac52: /* original 60f1, guest PC 0x0c07ac52 */
if(!s->budget--) { s->failed_pc=0x0c07ac52u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c07ac54;
P_0c07ac54: /* original 7f04, guest PC 0x0c07ac54 */
if(!s->budget--) { s->failed_pc=0x0c07ac54u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ac56;
P_0c07ac56: /* original 4f26, guest PC 0x0c07ac56 */
if(!s->budget--) { s->failed_pc=0x0c07ac56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac58;
P_0c07ac58: /* original d423, guest PC 0x0c07ac58 */
if(!s->budget--) { s->failed_pc=0x0c07ac58u; return 0; }
r[4]=read(ram,0x0c07ace8u,4);
goto P_0c07ac5a;
P_0c07ac5a: /* original 600d, guest PC 0x0c07ac5a */
if(!s->budget--) { s->failed_pc=0x0c07ac5au; return 0; }
r[0]=r[0]&65535u;
goto P_0c07ac5c;
P_0c07ac5c: /* original 4000, guest PC 0x0c07ac5c */
if(!s->budget--) { s->failed_pc=0x0c07ac5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07ac5e;
P_0c07ac5e: /* original 04e5, guest PC 0x0c07ac5e */
if(!s->budget--) { s->failed_pc=0x0c07ac5eu; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c07ac60;
P_0c07ac60: /* original 60e3, guest PC 0x0c07ac60 */
if(!s->budget--) { s->failed_pc=0x0c07ac60u; return 0; }
r[0]=r[14];
goto P_0c07ac62;
P_0c07ac62: /* original 8147, guest PC 0x0c07ac62 */
if(!s->budget--) { s->failed_pc=0x0c07ac62u; return 0; }
write(ram,r[4]+14,r[0],2);
goto P_0c07ac64;
P_0c07ac64: /* original 6df6, guest PC 0x0c07ac64 */
if(!s->budget--) { s->failed_pc=0x0c07ac64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ac66;
P_0c07ac66: /* original 000b, guest PC 0x0c07ac66 */
if(!s->budget--) { s->failed_pc=0x0c07ac66u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac68: /* original 6ef6, guest PC 0x0c07ac68 */
if(!s->budget--) { s->failed_pc=0x0c07ac68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ac6au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ac6au; return 0; } return 1;
P_0c07ad12: /* original 4f22, guest PC 0x0c07ad12 */
if(!s->budget--) { s->failed_pc=0x0c07ad12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ad14;
P_0c07ad14: /* original 7ff8, guest PC 0x0c07ad14 */
if(!s->budget--) { s->failed_pc=0x0c07ad14u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07ad16;
P_0c07ad16: /* original 2f51, guest PC 0x0c07ad16 */
if(!s->budget--) { s->failed_pc=0x0c07ad16u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c07ad18;
P_0c07ad18: /* original d23d, guest PC 0x0c07ad18 */
if(!s->budget--) { s->failed_pc=0x0c07ad18u; return 0; }
r[2]=read(ram,0x0c07ae10u,4);
goto P_0c07ad1a;
P_0c07ad1a: /* original 6322, guest PC 0x0c07ad1a */
if(!s->budget--) { s->failed_pc=0x0c07ad1au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ad1c;
P_0c07ad1c: /* original 1f31, guest PC 0x0c07ad1c */
if(!s->budget--) { s->failed_pc=0x0c07ad1cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07ad1e;
P_0c07ad1e: /* original b447, guest PC 0x0c07ad1e */
if(!s->budget--) { s->failed_pc=0x0c07ad1eu; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07ad22u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad22u) { target=s->pc; goto dispatch; }
goto P_0c07ad22;
P_0c07ad20: /* original 64f1, guest PC 0x0c07ad20 */
if(!s->budget--) { s->failed_pc=0x0c07ad20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c07ad22;
P_0c07ad22: /* original 6e03, guest PC 0x0c07ad22 */
if(!s->budget--) { s->failed_pc=0x0c07ad22u; return 0; }
r[14]=r[0];
goto P_0c07ad24;
P_0c07ad24: /* original d03b, guest PC 0x0c07ad24 */
if(!s->budget--) { s->failed_pc=0x0c07ad24u; return 0; }
r[0]=read(ram,0x0c07ae14u,4);
goto P_0c07ad26;
P_0c07ad26: /* original 62ed, guest PC 0x0c07ad26 */
if(!s->budget--) { s->failed_pc=0x0c07ad26u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07ad28;
P_0c07ad28: /* original 4200, guest PC 0x0c07ad28 */
if(!s->budget--) { s->failed_pc=0x0c07ad28u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07ad2a;
P_0c07ad2a: /* original 032d, guest PC 0x0c07ad2a */
if(!s->budget--) { s->failed_pc=0x0c07ad2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07ad2c;
P_0c07ad2c: /* original 633d, guest PC 0x0c07ad2c */
if(!s->budget--) { s->failed_pc=0x0c07ad2cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ad2e;
P_0c07ad2e: /* original 2338, guest PC 0x0c07ad2e */
if(!s->budget--) { s->failed_pc=0x0c07ad2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07ad30;
P_0c07ad30: /* original 8b0e, guest PC 0x0c07ad30 */
if(!s->budget--) { s->failed_pc=0x0c07ad30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad50; }
goto P_0c07ad32;
P_0c07ad32: /* original d137, guest PC 0x0c07ad32 */
if(!s->budget--) { s->failed_pc=0x0c07ad32u; return 0; }
r[1]=read(ram,0x0c07ae10u,4);
goto P_0c07ad34;
P_0c07ad34: /* original 64ed, guest PC 0x0c07ad34 */
if(!s->budget--) { s->failed_pc=0x0c07ad34u; return 0; }
r[4]=r[14]&65535u;
goto P_0c07ad36;
P_0c07ad36: /* original d038, guest PC 0x0c07ad36 */
if(!s->budget--) { s->failed_pc=0x0c07ad36u; return 0; }
r[0]=read(ram,0x0c07ae18u,4);
goto P_0c07ad38;
P_0c07ad38: /* original 74c8, guest PC 0x0c07ad38 */
if(!s->budget--) { s->failed_pc=0x0c07ad38u; return 0; }
r[4]+=0xffffffc8u;
goto P_0c07ad3a;
P_0c07ad3a: /* original d338, guest PC 0x0c07ad3a */
if(!s->budget--) { s->failed_pc=0x0c07ad3au; return 0; }
r[3]=read(ram,0x0c07ae1cu,4);
goto P_0c07ad3c;
P_0c07ad3c: /* original 4408, guest PC 0x0c07ad3c */
if(!s->budget--) { s->failed_pc=0x0c07ad3cu; return 0; }
r[4]<<=2;
goto P_0c07ad3e;
P_0c07ad3e: /* original 6512, guest PC 0x0c07ad3e */
if(!s->budget--) { s->failed_pc=0x0c07ad3eu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c07ad40;
P_0c07ad40: /* original 430b, guest PC 0x0c07ad40 */
if(!s->budget--) { s->failed_pc=0x0c07ad40u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ad44u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad44u) { target=s->pc; goto dispatch; }
goto P_0c07ad44;
P_0c07ad42: /* original 044e, guest PC 0x0c07ad42 */
if(!s->budget--) { s->failed_pc=0x0c07ad42u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07ad44;
P_0c07ad44: /* original 55f1, guest PC 0x0c07ad44 */
if(!s->budget--) { s->failed_pc=0x0c07ad44u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ad46;
P_0c07ad46: /* original 7f08, guest PC 0x0c07ad46 */
if(!s->budget--) { s->failed_pc=0x0c07ad46u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad48;
P_0c07ad48: /* original 4f26, guest PC 0x0c07ad48 */
if(!s->budget--) { s->failed_pc=0x0c07ad48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad4a;
P_0c07ad4a: /* original 64e3, guest PC 0x0c07ad4a */
if(!s->budget--) { s->failed_pc=0x0c07ad4au; return 0; }
r[4]=r[14];
goto P_0c07ad4c;
P_0c07ad4c: /* original af6c, guest PC 0x0c07ad4c */
if(!s->budget--) { s->failed_pc=0x0c07ad4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ac28;
P_0c07ad4e: /* original 6ef6, guest PC 0x0c07ad4e */
if(!s->budget--) { s->failed_pc=0x0c07ad4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ad50;
P_0c07ad50: /* original 7f08, guest PC 0x0c07ad50 */
if(!s->budget--) { s->failed_pc=0x0c07ad50u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad52;
P_0c07ad52: /* original 4f26, guest PC 0x0c07ad52 */
if(!s->budget--) { s->failed_pc=0x0c07ad52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad54;
P_0c07ad54: /* original 000b, guest PC 0x0c07ad54 */
if(!s->budget--) { s->failed_pc=0x0c07ad54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ad56: /* original 6ef6, guest PC 0x0c07ad56 */
if(!s->budget--) { s->failed_pc=0x0c07ad56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ad58u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ad58u; return 0; } return 1;
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c09553c: /* original fffb, guest PC 0x0c09553c */
if(!s->budget--) { s->failed_pc=0x0c09553cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09553e;
P_0c09553e: /* original 4f22, guest PC 0x0c09553e */
if(!s->budget--) { s->failed_pc=0x0c09553eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095540;
P_0c095540: /* original 7ff0, guest PC 0x0c095540 */
if(!s->budget--) { s->failed_pc=0x0c095540u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c095542;
P_0c095542: /* original 1f42, guest PC 0x0c095542 */
if(!s->budget--) { s->failed_pc=0x0c095542u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c095544;
P_0c095544: /* original 2f52, guest PC 0x0c095544 */
if(!s->budget--) { s->failed_pc=0x0c095544u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c095546;
P_0c095546: /* original 1f61, guest PC 0x0c095546 */
if(!s->budget--) { s->failed_pc=0x0c095546u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c095548;
P_0c095548: /* original 54f2, guest PC 0x0c095548 */
if(!s->budget--) { s->failed_pc=0x0c095548u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c09554a;
P_0c09554a: /* original d369, guest PC 0x0c09554a */
if(!s->budget--) { s->failed_pc=0x0c09554au; return 0; }
r[3]=read(ram,0x0c0956f0u,4);
goto P_0c09554c;
P_0c09554c: /* original 644f, guest PC 0x0c09554c */
if(!s->budget--) { s->failed_pc=0x0c09554cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09554e;
P_0c09554e: /* original 430b, guest PC 0x0c09554e */
if(!s->budget--) { s->failed_pc=0x0c09554eu; return 0; }
target=r[3];
r[16]=code_base|0x0c095552u;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c095552u) { target=s->pc; goto dispatch; }
goto P_0c095552;
P_0c095550: /* original 1f43, guest PC 0x0c095550 */
if(!s->budget--) { s->failed_pc=0x0c095550u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c095552;
P_0c095552: /* original d368, guest PC 0x0c095552 */
if(!s->budget--) { s->failed_pc=0x0c095552u; return 0; }
r[3]=read(ram,0x0c0956f4u,4);
goto P_0c095554;
P_0c095554: /* original ff0c, guest PC 0x0c095554 */
if(!s->budget--) { s->failed_pc=0x0c095554u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c095556;
P_0c095556: /* original 430b, guest PC 0x0c095556 */
if(!s->budget--) { s->failed_pc=0x0c095556u; return 0; }
target=r[3];
r[16]=code_base|0x0c09555au;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09555au) { target=s->pc; goto dispatch; }
goto P_0c09555a;
P_0c095558: /* original 54f3, guest PC 0x0c095558 */
if(!s->budget--) { s->failed_pc=0x0c095558u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c09555a;
P_0c09555a: /* original 62f2, guest PC 0x0c09555a */
if(!s->budget--) { s->failed_pc=0x0c09555au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09555c;
P_0c09555c: /* original f70c, guest PC 0x0c09555c */
if(!s->budget--) { s->failed_pc=0x0c09555cu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c09555e;
P_0c09555e: /* original f628, guest PC 0x0c09555e */
if(!s->budget--) { s->failed_pc=0x0c09555eu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c095560;
P_0c095560: /* original 53f1, guest PC 0x0c095560 */
if(!s->budget--) { s->failed_pc=0x0c095560u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c095562;
P_0c095562: /* original f762, guest PC 0x0c095562 */
if(!s->budget--) { s->failed_pc=0x0c095562u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c095564;
P_0c095564: /* original f40c, guest PC 0x0c095564 */
if(!s->budget--) { s->failed_pc=0x0c095564u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c095566;
P_0c095566: /* original f538, guest PC 0x0c095566 */
if(!s->budget--) { s->failed_pc=0x0c095566u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c095568;
P_0c095568: /* original 6323, guest PC 0x0c095568 */
if(!s->budget--) { s->failed_pc=0x0c095568u; return 0; }
r[3]=r[2];
goto P_0c09556a;
P_0c09556a: /* original f05c, guest PC 0x0c09556a */
if(!s->budget--) { s->failed_pc=0x0c09556au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09556c;
P_0c09556c: /* original f452, guest PC 0x0c09556c */
if(!s->budget--) { s->failed_pc=0x0c09556cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09556e;
P_0c09556e: /* original f7fe, guest PC 0x0c09556e */
if(!s->budget--) { s->failed_pc=0x0c09556eu; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[15],fr[7],r[18]);
goto P_0c095570;
P_0c095570: /* original ff62, guest PC 0x0c095570 */
if(!s->budget--) { s->failed_pc=0x0c095570u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c095572;
P_0c095572: /* original f57c, guest PC 0x0c095572 */
if(!s->budget--) { s->failed_pc=0x0c095572u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c095574;
P_0c095574: /* original f35a, guest PC 0x0c095574 */
if(!s->budget--) { s->failed_pc=0x0c095574u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c095576;
P_0c095576: /* original f4f1, guest PC 0x0c095576 */
if(!s->budget--) { s->failed_pc=0x0c095576u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c095578;
P_0c095578: /* original 53f1, guest PC 0x0c095578 */
if(!s->budget--) { s->failed_pc=0x0c095578u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09557a;
P_0c09557a: /* original 7f10, guest PC 0x0c09557a */
if(!s->budget--) { s->failed_pc=0x0c09557au; return 0; }
r[15]+=0x00000010u;
goto P_0c09557c;
P_0c09557c: /* original 4f26, guest PC 0x0c09557c */
if(!s->budget--) { s->failed_pc=0x0c09557cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09557e;
P_0c09557e: /* original f34a, guest PC 0x0c09557e */
if(!s->budget--) { s->failed_pc=0x0c09557eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c095580;
P_0c095580: /* original 000b, guest PC 0x0c095580 */
if(!s->budget--) { s->failed_pc=0x0c095580u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c095582: /* original fff9, guest PC 0x0c095582 */
if(!s->budget--) { s->failed_pc=0x0c095582u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c095584u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095584u; return 0; } return 1;
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
P_0c0968f6: /* original 7f04, guest PC 0x0c0968f6 */
if(!s->budget--) { s->failed_pc=0x0c0968f6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0968f8;
P_0c0968f8: /* original 6142, guest PC 0x0c0968f8 */
if(!s->budget--) { s->failed_pc=0x0c0968f8u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c0968fa;
P_0c0968fa: /* original e3fe, guest PC 0x0c0968fa */
if(!s->budget--) { s->failed_pc=0x0c0968fau; return 0; }
r[3]=0xfffffffeu;
goto P_0c0968fc;
P_0c0968fc: /* original 2139, guest PC 0x0c0968fc */
if(!s->budget--) { s->failed_pc=0x0c0968fcu; return 0; }
r[1]&=r[3];
goto P_0c0968fe;
P_0c0968fe: /* original 000b, guest PC 0x0c0968fe */
if(!s->budget--) { s->failed_pc=0x0c0968feu; return 0; }
target=r[16];
write(ram,r[4],r[1],4);
s->pc=target; return ram->oob==0;
P_0c096900: /* original 2412, guest PC 0x0c096900 */
if(!s->budget--) { s->failed_pc=0x0c096900u; return 0; }
write(ram,r[4],r[1],4);
if(!vf3_matrix_family(0x0c096902u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096902u; return 0; } return 1;
P_0c09690a: /* original 6042, guest PC 0x0c09690a */
if(!s->budget--) { s->failed_pc=0x0c09690au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09690c;
P_0c09690c: /* original cb01, guest PC 0x0c09690c */
if(!s->budget--) { s->failed_pc=0x0c09690cu; return 0; }
r[0]|=1u;
goto P_0c09690e;
P_0c09690e: /* original 2402, guest PC 0x0c09690e */
if(!s->budget--) { s->failed_pc=0x0c09690eu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c096910;
P_0c096910: /* original 000b, guest PC 0x0c096910 */
if(!s->budget--) { s->failed_pc=0x0c096910u; return 0; }
target=r[16];
write(ram,r[4]+12,r[5],4);
s->pc=target; return ram->oob==0;
P_0c096912: /* original 1453, guest PC 0x0c096912 */
if(!s->budget--) { s->failed_pc=0x0c096912u; return 0; }
write(ram,r[4]+12,r[5],4);
if(!vf3_matrix_family(0x0c096914u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096914u; return 0; } return 1;
P_0c096944: /* original 2fe6, guest PC 0x0c096944 */
if(!s->budget--) { s->failed_pc=0x0c096944u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096946;
P_0c096946: /* original e600, guest PC 0x0c096946 */
if(!s->budget--) { s->failed_pc=0x0c096946u; return 0; }
r[6]=0x00000000u;
goto P_0c096948;
P_0c096948: /* original 2fd6, guest PC 0x0c096948 */
if(!s->budget--) { s->failed_pc=0x0c096948u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694a;
P_0c09694a: /* original 6563, guest PC 0x0c09694a */
if(!s->budget--) { s->failed_pc=0x0c09694au; return 0; }
r[5]=r[6];
goto P_0c09694c;
P_0c09694c: /* original 2fc6, guest PC 0x0c09694c */
if(!s->budget--) { s->failed_pc=0x0c09694cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694e;
P_0c09694e: /* original 2fb6, guest PC 0x0c09694e */
if(!s->budget--) { s->failed_pc=0x0c09694eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096950;
P_0c096950: /* original 2fa6, guest PC 0x0c096950 */
if(!s->budget--) { s->failed_pc=0x0c096950u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096952;
P_0c096952: /* original 2f96, guest PC 0x0c096952 */
if(!s->budget--) { s->failed_pc=0x0c096952u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096954;
P_0c096954: /* original 2f86, guest PC 0x0c096954 */
if(!s->budget--) { s->failed_pc=0x0c096954u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096956;
P_0c096956: /* original fffb, guest PC 0x0c096956 */
if(!s->budget--) { s->failed_pc=0x0c096956u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c096958;
P_0c096958: /* original 4f22, guest PC 0x0c096958 */
if(!s->budget--) { s->failed_pc=0x0c096958u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09695a;
P_0c09695a: /* original d336, guest PC 0x0c09695a */
if(!s->budget--) { s->failed_pc=0x0c09695au; return 0; }
r[3]=read(ram,0x0c096a34u,4);
goto P_0c09695c;
P_0c09695c: /* original de34, guest PC 0x0c09695c */
if(!s->budget--) { s->failed_pc=0x0c09695cu; return 0; }
r[14]=read(ram,0x0c096a30u,4);
goto P_0c09695e;
P_0c09695e: /* original 430b, guest PC 0x0c09695e */
if(!s->budget--) { s->failed_pc=0x0c09695eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096962u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096962u) { target=s->pc; goto dispatch; }
goto P_0c096962;
P_0c096960: /* original 6463, guest PC 0x0c096960 */
if(!s->budget--) { s->failed_pc=0x0c096960u; return 0; }
r[4]=r[6];
goto P_0c096962;
P_0c096962: /* original e600, guest PC 0x0c096962 */
if(!s->budget--) { s->failed_pc=0x0c096962u; return 0; }
r[6]=0x00000000u;
goto P_0c096964;
P_0c096964: /* original d234, guest PC 0x0c096964 */
if(!s->budget--) { s->failed_pc=0x0c096964u; return 0; }
r[2]=read(ram,0x0c096a38u,4);
goto P_0c096966;
P_0c096966: /* original ff8d, guest PC 0x0c096966 */
if(!s->budget--) { s->failed_pc=0x0c096966u; return 0; }
fr[15]=0;
goto P_0c096968;
P_0c096968: /* original 6563, guest PC 0x0c096968 */
if(!s->budget--) { s->failed_pc=0x0c096968u; return 0; }
r[5]=r[6];
goto P_0c09696a;
P_0c09696a: /* original f5fc, guest PC 0x0c09696a */
if(!s->budget--) { s->failed_pc=0x0c09696au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09696c;
P_0c09696c: /* original f4fc, guest PC 0x0c09696c */
if(!s->budget--) { s->failed_pc=0x0c09696cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09696e;
P_0c09696e: /* original 420b, guest PC 0x0c09696e */
if(!s->budget--) { s->failed_pc=0x0c09696eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096972u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096972u) { target=s->pc; goto dispatch; }
goto P_0c096972;
P_0c096970: /* original 6463, guest PC 0x0c096970 */
if(!s->budget--) { s->failed_pc=0x0c096970u; return 0; }
r[4]=r[6];
goto P_0c096972;
P_0c096972: /* original d332, guest PC 0x0c096972 */
if(!s->budget--) { s->failed_pc=0x0c096972u; return 0; }
r[3]=read(ram,0x0c096a3cu,4);
goto P_0c096974;
P_0c096974: /* original 430b, guest PC 0x0c096974 */
if(!s->budget--) { s->failed_pc=0x0c096974u; return 0; }
target=r[3];
r[16]=code_base|0x0c096978u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096978u) { target=s->pc; goto dispatch; }
goto P_0c096978;
P_0c096976: /* original 0009, guest PC 0x0c096976 */
if(!s->budget--) { s->failed_pc=0x0c096976u; return 0; }
goto P_0c096978;
P_0c096978: /* original d22e, guest PC 0x0c096978 */
if(!s->budget--) { s->failed_pc=0x0c096978u; return 0; }
r[2]=read(ram,0x0c096a34u,4);
goto P_0c09697a;
P_0c09697a: /* original e600, guest PC 0x0c09697a */
if(!s->budget--) { s->failed_pc=0x0c09697au; return 0; }
r[6]=0x00000000u;
goto P_0c09697c;
P_0c09697c: /* original 6563, guest PC 0x0c09697c */
if(!s->budget--) { s->failed_pc=0x0c09697cu; return 0; }
r[5]=r[6];
goto P_0c09697e;
P_0c09697e: /* original 420b, guest PC 0x0c09697e */
if(!s->budget--) { s->failed_pc=0x0c09697eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096982u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096982u) { target=s->pc; goto dispatch; }
goto P_0c096982;
P_0c096980: /* original 6463, guest PC 0x0c096980 */
if(!s->budget--) { s->failed_pc=0x0c096980u; return 0; }
r[4]=r[6];
goto P_0c096982;
P_0c096982: /* original e600, guest PC 0x0c096982 */
if(!s->budget--) { s->failed_pc=0x0c096982u; return 0; }
r[6]=0x00000000u;
goto P_0c096984;
P_0c096984: /* original d32c, guest PC 0x0c096984 */
if(!s->budget--) { s->failed_pc=0x0c096984u; return 0; }
r[3]=read(ram,0x0c096a38u,4);
goto P_0c096986;
P_0c096986: /* original f5fc, guest PC 0x0c096986 */
if(!s->budget--) { s->failed_pc=0x0c096986u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c096988;
P_0c096988: /* original 6563, guest PC 0x0c096988 */
if(!s->budget--) { s->failed_pc=0x0c096988u; return 0; }
r[5]=r[6];
goto P_0c09698a;
P_0c09698a: /* original f4fc, guest PC 0x0c09698a */
if(!s->budget--) { s->failed_pc=0x0c09698au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09698c;
P_0c09698c: /* original 430b, guest PC 0x0c09698c */
if(!s->budget--) { s->failed_pc=0x0c09698cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096990u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096990u) { target=s->pc; goto dispatch; }
goto P_0c096990;
P_0c09698e: /* original 6463, guest PC 0x0c09698e */
if(!s->budget--) { s->failed_pc=0x0c09698eu; return 0; }
r[4]=r[6];
goto P_0c096990;
P_0c096990: /* original d22a, guest PC 0x0c096990 */
if(!s->budget--) { s->failed_pc=0x0c096990u; return 0; }
r[2]=read(ram,0x0c096a3cu,4);
goto P_0c096992;
P_0c096992: /* original 420b, guest PC 0x0c096992 */
if(!s->budget--) { s->failed_pc=0x0c096992u; return 0; }
target=r[2];
r[16]=code_base|0x0c096996u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096996u) { target=s->pc; goto dispatch; }
goto P_0c096996;
P_0c096994: /* original 0009, guest PC 0x0c096994 */
if(!s->budget--) { s->failed_pc=0x0c096994u; return 0; }
goto P_0c096996;
P_0c096996: /* original d32a, guest PC 0x0c096996 */
if(!s->budget--) { s->failed_pc=0x0c096996u; return 0; }
r[3]=read(ram,0x0c096a40u,4);
goto P_0c096998;
P_0c096998: /* original 430b, guest PC 0x0c096998 */
if(!s->budget--) { s->failed_pc=0x0c096998u; return 0; }
target=r[3];
r[16]=code_base|0x0c09699cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09699cu) { target=s->pc; goto dispatch; }
goto P_0c09699c;
P_0c09699a: /* original 0009, guest PC 0x0c09699a */
if(!s->budget--) { s->failed_pc=0x0c09699au; return 0; }
goto P_0c09699c;
P_0c09699c: /* original 9442, guest PC 0x0c09699c */
if(!s->budget--) { s->failed_pc=0x0c09699cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a24u,2);
goto P_0c09699e;
P_0c09699e: /* original e802, guest PC 0x0c09699e */
if(!s->budget--) { s->failed_pc=0x0c09699eu; return 0; }
r[8]=0x00000002u;
goto P_0c0969a0;
P_0c0969a0: /* original 9a41, guest PC 0x0c0969a0 */
if(!s->budget--) { s->failed_pc=0x0c0969a0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969a2;
P_0c0969a2: /* original ec00, guest PC 0x0c0969a2 */
if(!s->budget--) { s->failed_pc=0x0c0969a2u; return 0; }
r[12]=0x00000000u;
goto P_0c0969a4;
P_0c0969a4: /* original dd27, guest PC 0x0c0969a4 */
if(!s->budget--) { s->failed_pc=0x0c0969a4u; return 0; }
r[13]=read(ram,0x0c096a44u,4);
goto P_0c0969a6;
P_0c0969a6: /* original 34ec, guest PC 0x0c0969a6 */
if(!s->budget--) { s->failed_pc=0x0c0969a6u; return 0; }
r[4]+=r[14];
goto P_0c0969a8;
P_0c0969a8: /* original 3aec, guest PC 0x0c0969a8 */
if(!s->budget--) { s->failed_pc=0x0c0969a8u; return 0; }
r[10]+=r[14];
goto P_0c0969aa;
P_0c0969aa: /* original 6b43, guest PC 0x0c0969aa */
if(!s->budget--) { s->failed_pc=0x0c0969aau; return 0; }
r[11]=r[4];
goto P_0c0969ac;
P_0c0969ac: /* original 6943, guest PC 0x0c0969ac */
if(!s->budget--) { s->failed_pc=0x0c0969acu; return 0; }
r[9]=r[4];
goto P_0c0969ae;
P_0c0969ae: /* original 933a, guest PC 0x0c0969ae */
if(!s->budget--) { s->failed_pc=0x0c0969aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969b0;
P_0c0969b0: /* original 62c3, guest PC 0x0c0969b0 */
if(!s->budget--) { s->failed_pc=0x0c0969b0u; return 0; }
r[2]=r[12];
goto P_0c0969b2;
P_0c0969b2: /* original 4208, guest PC 0x0c0969b2 */
if(!s->budget--) { s->failed_pc=0x0c0969b2u; return 0; }
r[2]<<=2;
goto P_0c0969b4;
P_0c0969b4: /* original 33ec, guest PC 0x0c0969b4 */
if(!s->budget--) { s->failed_pc=0x0c0969b4u; return 0; }
r[3]+=r[14];
goto P_0c0969b6;
P_0c0969b6: /* original 323c, guest PC 0x0c0969b6 */
if(!s->budget--) { s->failed_pc=0x0c0969b6u; return 0; }
r[2]+=r[3];
goto P_0c0969b8;
P_0c0969b8: /* original 6122, guest PC 0x0c0969b8 */
if(!s->budget--) { s->failed_pc=0x0c0969b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0969ba;
P_0c0969ba: /* original 2118, guest PC 0x0c0969ba */
if(!s->budget--) { s->failed_pc=0x0c0969bau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0969bc;
P_0c0969bc: /* original 8901, guest PC 0x0c0969bc */
if(!s->budget--) { s->failed_pc=0x0c0969bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969c2; }
goto P_0c0969be;
P_0c0969be: /* original 4d0b, guest PC 0x0c0969be */
if(!s->budget--) { s->failed_pc=0x0c0969beu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969c2u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969c2u) { target=s->pc; goto dispatch; }
goto P_0c0969c2;
P_0c0969c0: /* original 64a2, guest PC 0x0c0969c0 */
if(!s->budget--) { s->failed_pc=0x0c0969c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0969c2;
P_0c0969c2: /* original 6392, guest PC 0x0c0969c2 */
if(!s->budget--) { s->failed_pc=0x0c0969c2u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0969c4;
P_0c0969c4: /* original 2338, guest PC 0x0c0969c4 */
if(!s->budget--) { s->failed_pc=0x0c0969c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969c6;
P_0c0969c6: /* original 8901, guest PC 0x0c0969c6 */
if(!s->budget--) { s->failed_pc=0x0c0969c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969cc; }
goto P_0c0969c8;
P_0c0969c8: /* original 4d0b, guest PC 0x0c0969c8 */
if(!s->budget--) { s->failed_pc=0x0c0969c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969ccu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969ccu) { target=s->pc; goto dispatch; }
goto P_0c0969cc;
P_0c0969ca: /* original 64b2, guest PC 0x0c0969ca */
if(!s->budget--) { s->failed_pc=0x0c0969cau; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0969cc;
P_0c0969cc: /* original 7c01, guest PC 0x0c0969cc */
if(!s->budget--) { s->failed_pc=0x0c0969ccu; return 0; }
r[12]+=0x00000001u;
goto P_0c0969ce;
P_0c0969ce: /* original 3c83, guest PC 0x0c0969ce */
if(!s->budget--) { s->failed_pc=0x0c0969ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[8])!=0);
goto P_0c0969d0;
P_0c0969d0: /* original 7904, guest PC 0x0c0969d0 */
if(!s->budget--) { s->failed_pc=0x0c0969d0u; return 0; }
r[9]+=0x00000004u;
goto P_0c0969d2;
P_0c0969d2: /* original 7b04, guest PC 0x0c0969d2 */
if(!s->budget--) { s->failed_pc=0x0c0969d2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0969d4;
P_0c0969d4: /* original 8feb, guest PC 0x0c0969d4 */
if(!s->budget--) { s->failed_pc=0x0c0969d4u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(!cond) { goto P_0c0969ae; }
goto P_0c0969d8;
P_0c0969d6: /* original 7a04, guest PC 0x0c0969d6 */
if(!s->budget--) { s->failed_pc=0x0c0969d6u; return 0; }
r[10]+=0x00000004u;
goto P_0c0969d8;
P_0c0969d8: /* original 9026, guest PC 0x0c0969d8 */
if(!s->budget--) { s->failed_pc=0x0c0969d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a28u,2);
goto P_0c0969da;
P_0c0969da: /* original 02ee, guest PC 0x0c0969da */
if(!s->budget--) { s->failed_pc=0x0c0969dau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0969dc;
P_0c0969dc: /* original 2228, guest PC 0x0c0969dc */
if(!s->budget--) { s->failed_pc=0x0c0969dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0969de;
P_0c0969de: /* original 8901, guest PC 0x0c0969de */
if(!s->budget--) { s->failed_pc=0x0c0969deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969e4; }
goto P_0c0969e0;
P_0c0969e0: /* original 4d0b, guest PC 0x0c0969e0 */
if(!s->budget--) { s->failed_pc=0x0c0969e0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969e4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969e4u) { target=s->pc; goto dispatch; }
goto P_0c0969e4;
P_0c0969e2: /* original 04ee, guest PC 0x0c0969e2 */
if(!s->budget--) { s->failed_pc=0x0c0969e2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969e4;
P_0c0969e4: /* original 9021, guest PC 0x0c0969e4 */
if(!s->budget--) { s->failed_pc=0x0c0969e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2au,2);
goto P_0c0969e6;
P_0c0969e6: /* original 03ee, guest PC 0x0c0969e6 */
if(!s->budget--) { s->failed_pc=0x0c0969e6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969e8;
P_0c0969e8: /* original 2338, guest PC 0x0c0969e8 */
if(!s->budget--) { s->failed_pc=0x0c0969e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969ea;
P_0c0969ea: /* original 8901, guest PC 0x0c0969ea */
if(!s->budget--) { s->failed_pc=0x0c0969eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969f0; }
goto P_0c0969ec;
P_0c0969ec: /* original 4d0b, guest PC 0x0c0969ec */
if(!s->budget--) { s->failed_pc=0x0c0969ecu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969f0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969f0u) { target=s->pc; goto dispatch; }
goto P_0c0969f0;
P_0c0969ee: /* original 04ee, guest PC 0x0c0969ee */
if(!s->budget--) { s->failed_pc=0x0c0969eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969f0;
P_0c0969f0: /* original 901c, guest PC 0x0c0969f0 */
if(!s->budget--) { s->failed_pc=0x0c0969f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2cu,2);
goto P_0c0969f2;
P_0c0969f2: /* original 03ee, guest PC 0x0c0969f2 */
if(!s->budget--) { s->failed_pc=0x0c0969f2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969f4;
P_0c0969f4: /* original 2338, guest PC 0x0c0969f4 */
if(!s->budget--) { s->failed_pc=0x0c0969f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969f6;
P_0c0969f6: /* original 8901, guest PC 0x0c0969f6 */
if(!s->budget--) { s->failed_pc=0x0c0969f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969fc; }
goto P_0c0969f8;
P_0c0969f8: /* original 4d0b, guest PC 0x0c0969f8 */
if(!s->budget--) { s->failed_pc=0x0c0969f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969fcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969fcu) { target=s->pc; goto dispatch; }
goto P_0c0969fc;
P_0c0969fa: /* original 04ee, guest PC 0x0c0969fa */
if(!s->budget--) { s->failed_pc=0x0c0969fau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969fc;
P_0c0969fc: /* original 9017, guest PC 0x0c0969fc */
if(!s->budget--) { s->failed_pc=0x0c0969fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2eu,2);
goto P_0c0969fe;
P_0c0969fe: /* original 03ee, guest PC 0x0c0969fe */
if(!s->budget--) { s->failed_pc=0x0c0969feu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c096a00;
P_0c096a00: /* original 2338, guest PC 0x0c096a00 */
if(!s->budget--) { s->failed_pc=0x0c096a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c096a02;
P_0c096a02: /* original 8901, guest PC 0x0c096a02 */
if(!s->budget--) { s->failed_pc=0x0c096a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096a08; }
goto P_0c096a04;
P_0c096a04: /* original 4d0b, guest PC 0x0c096a04 */
if(!s->budget--) { s->failed_pc=0x0c096a04u; return 0; }
target=r[13];
r[16]=code_base|0x0c096a08u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a08u) { target=s->pc; goto dispatch; }
goto P_0c096a08;
P_0c096a06: /* original 04ee, guest PC 0x0c096a06 */
if(!s->budget--) { s->failed_pc=0x0c096a06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096a08;
P_0c096a08: /* original d30f, guest PC 0x0c096a08 */
if(!s->budget--) { s->failed_pc=0x0c096a08u; return 0; }
r[3]=read(ram,0x0c096a48u,4);
goto P_0c096a0a;
P_0c096a0a: /* original 430b, guest PC 0x0c096a0a */
if(!s->budget--) { s->failed_pc=0x0c096a0au; return 0; }
target=r[3];
r[16]=code_base|0x0c096a0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a0eu) { target=s->pc; goto dispatch; }
goto P_0c096a0e;
P_0c096a0c: /* original 0009, guest PC 0x0c096a0c */
if(!s->budget--) { s->failed_pc=0x0c096a0cu; return 0; }
goto P_0c096a0e;
P_0c096a0e: /* original 4f26, guest PC 0x0c096a0e */
if(!s->budget--) { s->failed_pc=0x0c096a0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096a10;
P_0c096a10: /* original d20e, guest PC 0x0c096a10 */
if(!s->budget--) { s->failed_pc=0x0c096a10u; return 0; }
r[2]=read(ram,0x0c096a4cu,4);
goto P_0c096a12;
P_0c096a12: /* original fff9, guest PC 0x0c096a12 */
if(!s->budget--) { s->failed_pc=0x0c096a12u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c096a14;
P_0c096a14: /* original 68f6, guest PC 0x0c096a14 */
if(!s->budget--) { s->failed_pc=0x0c096a14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c096a16;
P_0c096a16: /* original 69f6, guest PC 0x0c096a16 */
if(!s->budget--) { s->failed_pc=0x0c096a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096a18;
P_0c096a18: /* original 6af6, guest PC 0x0c096a18 */
if(!s->budget--) { s->failed_pc=0x0c096a18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096a1a;
P_0c096a1a: /* original 6bf6, guest PC 0x0c096a1a */
if(!s->budget--) { s->failed_pc=0x0c096a1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096a1c;
P_0c096a1c: /* original 6cf6, guest PC 0x0c096a1c */
if(!s->budget--) { s->failed_pc=0x0c096a1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096a1e;
P_0c096a1e: /* original 6df6, guest PC 0x0c096a1e */
if(!s->budget--) { s->failed_pc=0x0c096a1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096a20;
P_0c096a20: /* original 422b, guest PC 0x0c096a20 */
if(!s->budget--) { s->failed_pc=0x0c096a20u; return 0; }
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
P_0c096a22: /* original 6ef6, guest PC 0x0c096a22 */
if(!s->budget--) { s->failed_pc=0x0c096a22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096a24u; return 0; } return 1;
P_0c097ff4: /* original d427, guest PC 0x0c097ff4 */
if(!s->budget--) { s->failed_pc=0x0c097ff4u; return 0; }
r[4]=read(ram,0x0c098094u,4);
goto P_0c097ff6;
P_0c097ff6: /* original d329, guest PC 0x0c097ff6 */
if(!s->budget--) { s->failed_pc=0x0c097ff6u; return 0; }
r[3]=read(ram,0x0c09809cu,4);
goto P_0c097ff8;
P_0c097ff8: /* original 5242, guest PC 0x0c097ff8 */
if(!s->budget--) { s->failed_pc=0x0c097ff8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097ffa;
P_0c097ffa: /* original d627, guest PC 0x0c097ffa */
if(!s->budget--) { s->failed_pc=0x0c097ffau; return 0; }
r[6]=read(ram,0x0c098098u,4);
goto P_0c097ffc;
P_0c097ffc: /* original 2238, guest PC 0x0c097ffc */
if(!s->budget--) { s->failed_pc=0x0c097ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097ffe;
P_0c097ffe: /* original 8b1d, guest PC 0x0c097ffe */
if(!s->budget--) { s->failed_pc=0x0c097ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09803c; }
goto P_0c098000;
P_0c098000: /* original 5142, guest PC 0x0c098000 */
if(!s->budget--) { s->failed_pc=0x0c098000u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c098002;
P_0c098002: /* original d327, guest PC 0x0c098002 */
if(!s->budget--) { s->failed_pc=0x0c098002u; return 0; }
r[3]=read(ram,0x0c0980a0u,4);
goto P_0c098004;
P_0c098004: /* original 2138, guest PC 0x0c098004 */
if(!s->budget--) { s->failed_pc=0x0c098004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098006;
P_0c098006: /* original 8919, guest PC 0x0c098006 */
if(!s->budget--) { s->failed_pc=0x0c098006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09803c; }
goto P_0c098008;
P_0c098008: /* original 5242, guest PC 0x0c098008 */
if(!s->budget--) { s->failed_pc=0x0c098008u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09800a;
P_0c09800a: /* original d326, guest PC 0x0c09800a */
if(!s->budget--) { s->failed_pc=0x0c09800au; return 0; }
r[3]=read(ram,0x0c0980a4u,4);
goto P_0c09800c;
P_0c09800c: /* original 2238, guest PC 0x0c09800c */
if(!s->budget--) { s->failed_pc=0x0c09800cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09800e;
P_0c09800e: /* original 8d0f, guest PC 0x0c09800e */
if(!s->budget--) { s->failed_pc=0x0c09800eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c098030; }
goto P_0c098012;
P_0c098010: /* original e700, guest PC 0x0c098010 */
if(!s->budget--) { s->failed_pc=0x0c098010u; return 0; }
r[7]=0x00000000u;
goto P_0c098012;
P_0c098012: /* original e029, guest PC 0x0c098012 */
if(!s->budget--) { s->failed_pc=0x0c098012u; return 0; }
r[0]=0x00000029u;
goto P_0c098014;
P_0c098014: /* original 004c, guest PC 0x0c098014 */
if(!s->budget--) { s->failed_pc=0x0c098014u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098016;
P_0c098016: /* original 600c, guest PC 0x0c098016 */
if(!s->budget--) { s->failed_pc=0x0c098016u; return 0; }
r[0]=r[0]&255u;
goto P_0c098018;
P_0c098018: /* original 8803, guest PC 0x0c098018 */
if(!s->budget--) { s->failed_pc=0x0c098018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09801a;
P_0c09801a: /* original 8909, guest PC 0x0c09801a */
if(!s->budget--) { s->failed_pc=0x0c09801au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098030; }
goto P_0c09801c;
P_0c09801c: /* original e02b, guest PC 0x0c09801c */
if(!s->budget--) { s->failed_pc=0x0c09801cu; return 0; }
r[0]=0x0000002bu;
goto P_0c09801e;
P_0c09801e: /* original 034c, guest PC 0x0c09801e */
if(!s->budget--) { s->failed_pc=0x0c09801eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098020;
P_0c098020: /* original 7301, guest PC 0x0c098020 */
if(!s->budget--) { s->failed_pc=0x0c098020u; return 0; }
r[3]+=0x00000001u;
goto P_0c098022;
P_0c098022: /* original 0434, guest PC 0x0c098022 */
if(!s->budget--) { s->failed_pc=0x0c098022u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098024;
P_0c098024: /* original 554d, guest PC 0x0c098024 */
if(!s->budget--) { s->failed_pc=0x0c098024u; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c098026;
P_0c098026: /* original 534e, guest PC 0x0c098026 */
if(!s->budget--) { s->failed_pc=0x0c098026u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c098028;
P_0c098028: /* original 353c, guest PC 0x0c098028 */
if(!s->budget--) { s->failed_pc=0x0c098028u; return 0; }
r[5]+=r[3];
goto P_0c09802a;
P_0c09802a: /* original 145c, guest PC 0x0c09802a */
if(!s->budget--) { s->failed_pc=0x0c09802au; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c09802c;
P_0c09802c: /* original 145d, guest PC 0x0c09802c */
if(!s->budget--) { s->failed_pc=0x0c09802cu; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c09802e;
P_0c09802e: /* original 147e, guest PC 0x0c09802e */
if(!s->budget--) { s->failed_pc=0x0c09802eu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c098030;
P_0c098030: /* original e010, guest PC 0x0c098030 */
if(!s->budget--) { s->failed_pc=0x0c098030u; return 0; }
r[0]=0x00000010u;
goto P_0c098032;
P_0c098032: /* original 0674, guest PC 0x0c098032 */
if(!s->budget--) { s->failed_pc=0x0c098032u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c098034;
P_0c098034: /* original e00a, guest PC 0x0c098034 */
if(!s->budget--) { s->failed_pc=0x0c098034u; return 0; }
r[0]=0x0000000au;
goto P_0c098036;
P_0c098036: /* original d31c, guest PC 0x0c098036 */
if(!s->budget--) { s->failed_pc=0x0c098036u; return 0; }
r[3]=read(ram,0x0c0980a8u,4);
goto P_0c098038;
P_0c098038: /* original 432b, guest PC 0x0c098038 */
if(!s->budget--) { s->failed_pc=0x0c098038u; return 0; }
target=r[3];
write(ram,r[6]+10,r[0],1);
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0968d0u: goto P_0c0968d0;
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
P_0c09803a: /* original 806a, guest PC 0x0c09803a */
if(!s->budget--) { s->failed_pc=0x0c09803au; return 0; }
write(ram,r[6]+10,r[0],1);
goto P_0c09803c;
P_0c09803c: /* original 000b, guest PC 0x0c09803c */
if(!s->budget--) { s->failed_pc=0x0c09803cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09803e: /* original 0009, guest PC 0x0c09803e */
if(!s->budget--) { s->failed_pc=0x0c09803eu; return 0; }
if(!vf3_matrix_family(0x0c098040u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098040u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
