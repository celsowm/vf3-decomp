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
int vf3_away_batch117_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08b4deu: goto P_0c08b4de;
case 0x0c08b4e0u: goto P_0c08b4e0;
case 0x0c08b4e2u: goto P_0c08b4e2;
case 0x0c08b4e4u: goto P_0c08b4e4;
case 0x0c08b4e6u: goto P_0c08b4e6;
case 0x0c08b4e8u: goto P_0c08b4e8;
case 0x0c08b4eau: goto P_0c08b4ea;
case 0x0c08b4ecu: goto P_0c08b4ec;
case 0x0c08b4eeu: goto P_0c08b4ee;
case 0x0c08b4f0u: goto P_0c08b4f0;
case 0x0c08b4f2u: goto P_0c08b4f2;
case 0x0c08b4f4u: goto P_0c08b4f4;
case 0x0c08b4f6u: goto P_0c08b4f6;
case 0x0c08b4f8u: goto P_0c08b4f8;
case 0x0c08b544u: goto P_0c08b544;
case 0x0c08b546u: goto P_0c08b546;
case 0x0c08b548u: goto P_0c08b548;
case 0x0c08b54au: goto P_0c08b54a;
case 0x0c08b54cu: goto P_0c08b54c;
case 0x0c08b54eu: goto P_0c08b54e;
case 0x0c08b550u: goto P_0c08b550;
case 0x0c08b552u: goto P_0c08b552;
case 0x0c08b554u: goto P_0c08b554;
case 0x0c08b556u: goto P_0c08b556;
case 0x0c08b558u: goto P_0c08b558;
case 0x0c08b55au: goto P_0c08b55a;
case 0x0c08b55cu: goto P_0c08b55c;
case 0x0c08b55eu: goto P_0c08b55e;
case 0x0c08b560u: goto P_0c08b560;
case 0x0c08b562u: goto P_0c08b562;
case 0x0c08b564u: goto P_0c08b564;
case 0x0c08b566u: goto P_0c08b566;
case 0x0c08b568u: goto P_0c08b568;
case 0x0c08b56au: goto P_0c08b56a;
case 0x0c08b56cu: goto P_0c08b56c;
case 0x0c08b56eu: goto P_0c08b56e;
case 0x0c08b570u: goto P_0c08b570;
case 0x0c08b572u: goto P_0c08b572;
case 0x0c08b574u: goto P_0c08b574;
case 0x0c08b576u: goto P_0c08b576;
case 0x0c08b578u: goto P_0c08b578;
case 0x0c08b57au: goto P_0c08b57a;
case 0x0c08b57cu: goto P_0c08b57c;
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
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
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
case 0x0c096902u: goto P_0c096902;
case 0x0c096904u: goto P_0c096904;
case 0x0c096906u: goto P_0c096906;
case 0x0c096908u: goto P_0c096908;
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
P_0c08b4de: /* original d50e, guest PC 0x0c08b4de */
if(!s->budget--) { s->failed_pc=0x0c08b4deu; return 0; }
r[5]=read(ram,0x0c08b518u,4);
goto P_0c08b4e0;
P_0c08b4e0: /* original a007, guest PC 0x0c08b4e0 */
if(!s->budget--) { s->failed_pc=0x0c08b4e0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4f2;
P_0c08b4e2: /* original 664e, guest PC 0x0c08b4e2 */
if(!s->budget--) { s->failed_pc=0x0c08b4e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4e4;
P_0c08b4e4: /* original 7501, guest PC 0x0c08b4e4 */
if(!s->budget--) { s->failed_pc=0x0c08b4e4u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4e6;
P_0c08b4e6: /* original 6450, guest PC 0x0c08b4e6 */
if(!s->budget--) { s->failed_pc=0x0c08b4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[4]=tmp;
goto P_0c08b4e8;
P_0c08b4e8: /* original 644e, guest PC 0x0c08b4e8 */
if(!s->budget--) { s->failed_pc=0x0c08b4e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4ea;
P_0c08b4ea: /* original 2448, guest PC 0x0c08b4ea */
if(!s->budget--) { s->failed_pc=0x0c08b4eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08b4ec;
P_0c08b4ec: /* original 8bfa, guest PC 0x0c08b4ec */
if(!s->budget--) { s->failed_pc=0x0c08b4ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4e4; }
goto P_0c08b4ee;
P_0c08b4ee: /* original 76ff, guest PC 0x0c08b4ee */
if(!s->budget--) { s->failed_pc=0x0c08b4eeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08b4f0;
P_0c08b4f0: /* original 7501, guest PC 0x0c08b4f0 */
if(!s->budget--) { s->failed_pc=0x0c08b4f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4f2;
P_0c08b4f2: /* original 4615, guest PC 0x0c08b4f2 */
if(!s->budget--) { s->failed_pc=0x0c08b4f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c08b4f4;
P_0c08b4f4: /* original 89f7, guest PC 0x0c08b4f4 */
if(!s->budget--) { s->failed_pc=0x0c08b4f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4e6; }
goto P_0c08b4f6;
P_0c08b4f6: /* original 000b, guest PC 0x0c08b4f6 */
if(!s->budget--) { s->failed_pc=0x0c08b4f6u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c08b4f8: /* original 6053, guest PC 0x0c08b4f8 */
if(!s->budget--) { s->failed_pc=0x0c08b4f8u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c08b4fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b4fau; return 0; } return 1;
P_0c08b544: /* original 2fe6, guest PC 0x0c08b544 */
if(!s->budget--) { s->failed_pc=0x0c08b544u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b546;
P_0c08b546: /* original e41e, guest PC 0x0c08b546 */
if(!s->budget--) { s->failed_pc=0x0c08b546u; return 0; }
r[4]=0x0000001eu;
goto P_0c08b548;
P_0c08b548: /* original d33b, guest PC 0x0c08b548 */
if(!s->budget--) { s->failed_pc=0x0c08b548u; return 0; }
r[3]=read(ram,0x0c08b638u,4);
goto P_0c08b54a;
P_0c08b54a: /* original e500, guest PC 0x0c08b54a */
if(!s->budget--) { s->failed_pc=0x0c08b54au; return 0; }
r[5]=0x00000000u;
goto P_0c08b54c;
P_0c08b54c: /* original 4f22, guest PC 0x0c08b54c */
if(!s->budget--) { s->failed_pc=0x0c08b54cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b54e;
P_0c08b54e: /* original 6e32, guest PC 0x0c08b54e */
if(!s->budget--) { s->failed_pc=0x0c08b54eu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c08b550;
P_0c08b550: /* original 66e3, guest PC 0x0c08b550 */
if(!s->budget--) { s->failed_pc=0x0c08b550u; return 0; }
r[6]=r[14];
goto P_0c08b552;
P_0c08b552: /* original 7664, guest PC 0x0c08b552 */
if(!s->budget--) { s->failed_pc=0x0c08b552u; return 0; }
r[6]+=0x00000064u;
goto P_0c08b554;
P_0c08b554: /* original 4410, guest PC 0x0c08b554 */
if(!s->budget--) { s->failed_pc=0x0c08b554u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08b556;
P_0c08b556: /* original 2652, guest PC 0x0c08b556 */
if(!s->budget--) { s->failed_pc=0x0c08b556u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c08b558;
P_0c08b558: /* original 8ffc, guest PC 0x0c08b558 */
if(!s->budget--) { s->failed_pc=0x0c08b558u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c08b554; }
goto P_0c08b55c;
P_0c08b55a: /* original 7604, guest PC 0x0c08b55a */
if(!s->budget--) { s->failed_pc=0x0c08b55au; return 0; }
r[6]+=0x00000004u;
goto P_0c08b55c;
P_0c08b55c: /* original d337, guest PC 0x0c08b55c */
if(!s->budget--) { s->failed_pc=0x0c08b55cu; return 0; }
r[3]=read(ram,0x0c08b63cu,4);
goto P_0c08b55e;
P_0c08b55e: /* original e010, guest PC 0x0c08b55e */
if(!s->budget--) { s->failed_pc=0x0c08b55eu; return 0; }
r[0]=0x00000010u;
goto P_0c08b560;
P_0c08b560: /* original 6230, guest PC 0x0c08b560 */
if(!s->budget--) { s->failed_pc=0x0c08b560u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08b562;
P_0c08b562: /* original 0e24, guest PC 0x0c08b562 */
if(!s->budget--) { s->failed_pc=0x0c08b562u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08b564;
P_0c08b564: /* original bfbb, guest PC 0x0c08b564 */
if(!s->budget--) { s->failed_pc=0x0c08b564u; return 0; }
target=code_base|0x0c08b4deu; r[16]=code_base|0x0c08b568u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b568u) { target=s->pc; goto dispatch; }
goto P_0c08b568;
P_0c08b566: /* original 04ec, guest PC 0x0c08b566 */
if(!s->budget--) { s->failed_pc=0x0c08b566u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b568;
P_0c08b568: /* original e504, guest PC 0x0c08b568 */
if(!s->budget--) { s->failed_pc=0x0c08b568u; return 0; }
r[5]=0x00000004u;
goto P_0c08b56a;
P_0c08b56a: /* original 6703, guest PC 0x0c08b56a */
if(!s->budget--) { s->failed_pc=0x0c08b56au; return 0; }
r[7]=r[0];
goto P_0c08b56c;
P_0c08b56c: /* original e600, guest PC 0x0c08b56c */
if(!s->budget--) { s->failed_pc=0x0c08b56cu; return 0; }
r[6]=0x00000000u;
goto P_0c08b56e;
P_0c08b56e: /* original bf5f, guest PC 0x0c08b56e */
if(!s->budget--) { s->failed_pc=0x0c08b56eu; return 0; }
target=code_base|0x0c08b430u; r[16]=code_base|0x0c08b572u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b572u) { target=s->pc; goto dispatch; }
goto P_0c08b572;
P_0c08b570: /* original 64e3, guest PC 0x0c08b570 */
if(!s->budget--) { s->failed_pc=0x0c08b570u; return 0; }
r[4]=r[14];
goto P_0c08b572;
P_0c08b572: /* original 6403, guest PC 0x0c08b572 */
if(!s->budget--) { s->failed_pc=0x0c08b572u; return 0; }
r[4]=r[0];
goto P_0c08b574;
P_0c08b574: /* original 9058, guest PC 0x0c08b574 */
if(!s->budget--) { s->failed_pc=0x0c08b574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b628u,2);
goto P_0c08b576;
P_0c08b576: /* original 4f26, guest PC 0x0c08b576 */
if(!s->budget--) { s->failed_pc=0x0c08b576u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b578;
P_0c08b578: /* original 0e46, guest PC 0x0c08b578 */
if(!s->budget--) { s->failed_pc=0x0c08b578u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08b57a;
P_0c08b57a: /* original 000b, guest PC 0x0c08b57a */
if(!s->budget--) { s->failed_pc=0x0c08b57au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b57c: /* original 6ef6, guest PC 0x0c08b57c */
if(!s->budget--) { s->failed_pc=0x0c08b57cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08b57eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b57eu; return 0; } return 1;
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
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
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
goto P_0c096902;
P_0c096902: /* original 6042, guest PC 0x0c096902 */
if(!s->budget--) { s->failed_pc=0x0c096902u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096904;
P_0c096904: /* original cb01, guest PC 0x0c096904 */
if(!s->budget--) { s->failed_pc=0x0c096904u; return 0; }
r[0]|=1u;
goto P_0c096906;
P_0c096906: /* original 000b, guest PC 0x0c096906 */
if(!s->budget--) { s->failed_pc=0x0c096906u; return 0; }
target=r[16];
write(ram,r[4],r[0],4);
s->pc=target; return ram->oob==0;
P_0c096908: /* original 2402, guest PC 0x0c096908 */
if(!s->budget--) { s->failed_pc=0x0c096908u; return 0; }
write(ram,r[4],r[0],4);
if(!vf3_matrix_family(0x0c09690au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09690au; return 0; } return 1;
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
return vf3_matrix_family(0x0c098040u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
