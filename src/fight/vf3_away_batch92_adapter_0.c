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
int vf3_away_batch92_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0b6742u: goto P_0c0b6742;
case 0x0c0b6744u: goto P_0c0b6744;
case 0x0c0b6746u: goto P_0c0b6746;
case 0x0c0b6748u: goto P_0c0b6748;
case 0x0c0b674au: goto P_0c0b674a;
case 0x0c0b674cu: goto P_0c0b674c;
case 0x0c0b674eu: goto P_0c0b674e;
case 0x0c0b6750u: goto P_0c0b6750;
case 0x0c0b6752u: goto P_0c0b6752;
case 0x0c0b6754u: goto P_0c0b6754;
case 0x0c0b6756u: goto P_0c0b6756;
case 0x0c0b6758u: goto P_0c0b6758;
case 0x0c0b675au: goto P_0c0b675a;
case 0x0c0b675cu: goto P_0c0b675c;
case 0x0c0b675eu: goto P_0c0b675e;
case 0x0c0b6760u: goto P_0c0b6760;
case 0x0c0b6762u: goto P_0c0b6762;
case 0x0c0b6764u: goto P_0c0b6764;
case 0x0c0b6766u: goto P_0c0b6766;
case 0x0c0b6768u: goto P_0c0b6768;
case 0x0c0b676au: goto P_0c0b676a;
case 0x0c0b676cu: goto P_0c0b676c;
case 0x0c0b676eu: goto P_0c0b676e;
case 0x0c0b6770u: goto P_0c0b6770;
case 0x0c0b6772u: goto P_0c0b6772;
case 0x0c0b6774u: goto P_0c0b6774;
case 0x0c0b6776u: goto P_0c0b6776;
case 0x0c0b6778u: goto P_0c0b6778;
case 0x0c0b677au: goto P_0c0b677a;
case 0x0c0b677cu: goto P_0c0b677c;
case 0x0c0b677eu: goto P_0c0b677e;
case 0x0c0b6780u: goto P_0c0b6780;
case 0x0c0b6782u: goto P_0c0b6782;
case 0x0c0b6784u: goto P_0c0b6784;
case 0x0c0b6786u: goto P_0c0b6786;
case 0x0c0b6788u: goto P_0c0b6788;
case 0x0c0b678au: goto P_0c0b678a;
case 0x0c0b678cu: goto P_0c0b678c;
case 0x0c0b678eu: goto P_0c0b678e;
case 0x0c0b6790u: goto P_0c0b6790;
case 0x0c0b6792u: goto P_0c0b6792;
case 0x0c0b6794u: goto P_0c0b6794;
case 0x0c0b6796u: goto P_0c0b6796;
case 0x0c0b6798u: goto P_0c0b6798;
case 0x0c0b679au: goto P_0c0b679a;
case 0x0c0b679cu: goto P_0c0b679c;
case 0x0c0b679eu: goto P_0c0b679e;
case 0x0c0b67a0u: goto P_0c0b67a0;
case 0x0c0b67a2u: goto P_0c0b67a2;
case 0x0c0b67a4u: goto P_0c0b67a4;
case 0x0c0b67a6u: goto P_0c0b67a6;
case 0x0c0b67a8u: goto P_0c0b67a8;
case 0x0c0b67aau: goto P_0c0b67aa;
case 0x0c0b67acu: goto P_0c0b67ac;
case 0x0c0b67aeu: goto P_0c0b67ae;
case 0x0c0b67b0u: goto P_0c0b67b0;
case 0x0c0b67b2u: goto P_0c0b67b2;
case 0x0c0b67b4u: goto P_0c0b67b4;
case 0x0c0b67b6u: goto P_0c0b67b6;
case 0x0c0b67b8u: goto P_0c0b67b8;
case 0x0c0b67bau: goto P_0c0b67ba;
case 0x0c0b67bcu: goto P_0c0b67bc;
case 0x0c0b67beu: goto P_0c0b67be;
case 0x0c0b67c0u: goto P_0c0b67c0;
case 0x0c0b67c2u: goto P_0c0b67c2;
case 0x0c0b67c4u: goto P_0c0b67c4;
case 0x0c0b67c6u: goto P_0c0b67c6;
case 0x0c0b67c8u: goto P_0c0b67c8;
case 0x0c0b67cau: goto P_0c0b67ca;
case 0x0c0b67ccu: goto P_0c0b67cc;
case 0x0c0b67ceu: goto P_0c0b67ce;
case 0x0c0b67d0u: goto P_0c0b67d0;
case 0x0c0b67d2u: goto P_0c0b67d2;
case 0x0c0b67d4u: goto P_0c0b67d4;
case 0x0c0b67d6u: goto P_0c0b67d6;
case 0x0c0b67d8u: goto P_0c0b67d8;
case 0x0c0b67dau: goto P_0c0b67da;
case 0x0c0b67dcu: goto P_0c0b67dc;
case 0x0c0b67deu: goto P_0c0b67de;
case 0x0c0b67e0u: goto P_0c0b67e0;
case 0x0c0b67e2u: goto P_0c0b67e2;
case 0x0c0b67e4u: goto P_0c0b67e4;
case 0x0c0b67e6u: goto P_0c0b67e6;
case 0x0c0b67e8u: goto P_0c0b67e8;
case 0x0c0b67eau: goto P_0c0b67ea;
case 0x0c0b67ecu: goto P_0c0b67ec;
case 0x0c0b67eeu: goto P_0c0b67ee;
case 0x0c0b67f0u: goto P_0c0b67f0;
case 0x0c0b67f2u: goto P_0c0b67f2;
case 0x0c0b67f4u: goto P_0c0b67f4;
case 0x0c0b67f6u: goto P_0c0b67f6;
case 0x0c0b67f8u: goto P_0c0b67f8;
case 0x0c0b67fau: goto P_0c0b67fa;
case 0x0c0b67fcu: goto P_0c0b67fc;
case 0x0c0b67feu: goto P_0c0b67fe;
case 0x0c0b6800u: goto P_0c0b6800;
case 0x0c0b6802u: goto P_0c0b6802;
case 0x0c0b6804u: goto P_0c0b6804;
case 0x0c0b6806u: goto P_0c0b6806;
case 0x0c0b6808u: goto P_0c0b6808;
case 0x0c0b680au: goto P_0c0b680a;
case 0x0c0b680cu: goto P_0c0b680c;
case 0x0c0b680eu: goto P_0c0b680e;
case 0x0c0b6810u: goto P_0c0b6810;
case 0x0c0b6812u: goto P_0c0b6812;
case 0x0c0b6814u: goto P_0c0b6814;
case 0x0c0b6816u: goto P_0c0b6816;
case 0x0c0b6818u: goto P_0c0b6818;
case 0x0c0b681au: goto P_0c0b681a;
case 0x0c0b681cu: goto P_0c0b681c;
case 0x0c0b681eu: goto P_0c0b681e;
case 0x0c0b6820u: goto P_0c0b6820;
case 0x0c0b6822u: goto P_0c0b6822;
case 0x0c0b6824u: goto P_0c0b6824;
case 0x0c0b6826u: goto P_0c0b6826;
case 0x0c0b6828u: goto P_0c0b6828;
case 0x0c0b682au: goto P_0c0b682a;
case 0x0c0b682cu: goto P_0c0b682c;
case 0x0c0b682eu: goto P_0c0b682e;
case 0x0c0b6830u: goto P_0c0b6830;
case 0x0c0b6832u: goto P_0c0b6832;
case 0x0c0b6834u: goto P_0c0b6834;
case 0x0c0b6836u: goto P_0c0b6836;
case 0x0c0b6838u: goto P_0c0b6838;
case 0x0c0b683au: goto P_0c0b683a;
case 0x0c0b683cu: goto P_0c0b683c;
case 0x0c0b683eu: goto P_0c0b683e;
case 0x0c0b6840u: goto P_0c0b6840;
case 0x0c0b6842u: goto P_0c0b6842;
case 0x0c0b6844u: goto P_0c0b6844;
case 0x0c0b6846u: goto P_0c0b6846;
case 0x0c0b6848u: goto P_0c0b6848;
case 0x0c0b684au: goto P_0c0b684a;
case 0x0c0b684cu: goto P_0c0b684c;
case 0x0c0b684eu: goto P_0c0b684e;
case 0x0c0b6850u: goto P_0c0b6850;
case 0x0c0b6852u: goto P_0c0b6852;
case 0x0c0b6854u: goto P_0c0b6854;
case 0x0c0b6856u: goto P_0c0b6856;
case 0x0c0b6858u: goto P_0c0b6858;
case 0x0c0b685au: goto P_0c0b685a;
case 0x0c0b685cu: goto P_0c0b685c;
case 0x0c0b685eu: goto P_0c0b685e;
case 0x0c0b6860u: goto P_0c0b6860;
case 0x0c0b6862u: goto P_0c0b6862;
case 0x0c0b6864u: goto P_0c0b6864;
case 0x0c0b6866u: goto P_0c0b6866;
case 0x0c0b6868u: goto P_0c0b6868;
case 0x0c0b686au: goto P_0c0b686a;
case 0x0c0b686cu: goto P_0c0b686c;
case 0x0c0b686eu: goto P_0c0b686e;
case 0x0c0b6870u: goto P_0c0b6870;
case 0x0c0b6872u: goto P_0c0b6872;
case 0x0c0b6874u: goto P_0c0b6874;
case 0x0c0b6876u: goto P_0c0b6876;
case 0x0c0b6878u: goto P_0c0b6878;
case 0x0c0b687au: goto P_0c0b687a;
case 0x0c0b687cu: goto P_0c0b687c;
case 0x0c0b687eu: goto P_0c0b687e;
case 0x0c0b6880u: goto P_0c0b6880;
case 0x0c0b6882u: goto P_0c0b6882;
case 0x0c0b6884u: goto P_0c0b6884;
case 0x0c0b6886u: goto P_0c0b6886;
case 0x0c0b6888u: goto P_0c0b6888;
case 0x0c0b688au: goto P_0c0b688a;
case 0x0c0b688cu: goto P_0c0b688c;
case 0x0c0b688eu: goto P_0c0b688e;
case 0x0c0b6890u: goto P_0c0b6890;
case 0x0c0b6892u: goto P_0c0b6892;
case 0x0c0b6894u: goto P_0c0b6894;
case 0x0c0b6896u: goto P_0c0b6896;
case 0x0c0b6898u: goto P_0c0b6898;
case 0x0c0b689au: goto P_0c0b689a;
case 0x0c0b689cu: goto P_0c0b689c;
case 0x0c0b689eu: goto P_0c0b689e;
case 0x0c0b68a0u: goto P_0c0b68a0;
case 0x0c0b68a2u: goto P_0c0b68a2;
case 0x0c0b68a4u: goto P_0c0b68a4;
case 0x0c0b6914u: goto P_0c0b6914;
case 0x0c0b6916u: goto P_0c0b6916;
case 0x0c0b6918u: goto P_0c0b6918;
case 0x0c0b691au: goto P_0c0b691a;
case 0x0c0b691cu: goto P_0c0b691c;
case 0x0c0b691eu: goto P_0c0b691e;
case 0x0c0b6920u: goto P_0c0b6920;
case 0x0c0b6922u: goto P_0c0b6922;
case 0x0c0b6924u: goto P_0c0b6924;
case 0x0c0b6926u: goto P_0c0b6926;
case 0x0c0b6928u: goto P_0c0b6928;
case 0x0c0b692au: goto P_0c0b692a;
case 0x0c0b692cu: goto P_0c0b692c;
case 0x0c0b692eu: goto P_0c0b692e;
case 0x0c0b6930u: goto P_0c0b6930;
case 0x0c0b6932u: goto P_0c0b6932;
case 0x0c0b6934u: goto P_0c0b6934;
case 0x0c0b6936u: goto P_0c0b6936;
case 0x0c0b6938u: goto P_0c0b6938;
case 0x0c0b693au: goto P_0c0b693a;
case 0x0c0b693cu: goto P_0c0b693c;
case 0x0c0b693eu: goto P_0c0b693e;
case 0x0c0b6940u: goto P_0c0b6940;
case 0x0c0b6942u: goto P_0c0b6942;
case 0x0c0b6944u: goto P_0c0b6944;
case 0x0c0b6946u: goto P_0c0b6946;
case 0x0c0b6948u: goto P_0c0b6948;
case 0x0c0b694au: goto P_0c0b694a;
case 0x0c0b694cu: goto P_0c0b694c;
case 0x0c0b694eu: goto P_0c0b694e;
case 0x0c0b6950u: goto P_0c0b6950;
case 0x0c0b6952u: goto P_0c0b6952;
case 0x0c0b6954u: goto P_0c0b6954;
case 0x0c0b6956u: goto P_0c0b6956;
case 0x0c0b6958u: goto P_0c0b6958;
case 0x0c0b695au: goto P_0c0b695a;
case 0x0c0b695cu: goto P_0c0b695c;
case 0x0c0b695eu: goto P_0c0b695e;
case 0x0c0b6960u: goto P_0c0b6960;
case 0x0c0b6962u: goto P_0c0b6962;
case 0x0c0b6964u: goto P_0c0b6964;
case 0x0c0b6966u: goto P_0c0b6966;
case 0x0c0b6968u: goto P_0c0b6968;
case 0x0c0b696au: goto P_0c0b696a;
case 0x0c0b696cu: goto P_0c0b696c;
case 0x0c0b696eu: goto P_0c0b696e;
case 0x0c0b6970u: goto P_0c0b6970;
case 0x0c0b6972u: goto P_0c0b6972;
case 0x0c0b6974u: goto P_0c0b6974;
case 0x0c0b6976u: goto P_0c0b6976;
case 0x0c0b6978u: goto P_0c0b6978;
case 0x0c0b697au: goto P_0c0b697a;
case 0x0c0b697cu: goto P_0c0b697c;
case 0x0c0b697eu: goto P_0c0b697e;
case 0x0c0b6980u: goto P_0c0b6980;
case 0x0c0b6982u: goto P_0c0b6982;
case 0x0c0b6984u: goto P_0c0b6984;
case 0x0c0b6986u: goto P_0c0b6986;
case 0x0c0b6988u: goto P_0c0b6988;
case 0x0c0b698au: goto P_0c0b698a;
case 0x0c0b698cu: goto P_0c0b698c;
case 0x0c0b698eu: goto P_0c0b698e;
case 0x0c0b6990u: goto P_0c0b6990;
case 0x0c0b6992u: goto P_0c0b6992;
case 0x0c0b6994u: goto P_0c0b6994;
case 0x0c0b6996u: goto P_0c0b6996;
case 0x0c0b6998u: goto P_0c0b6998;
case 0x0c0b699au: goto P_0c0b699a;
case 0x0c0b699cu: goto P_0c0b699c;
case 0x0c0b699eu: goto P_0c0b699e;
case 0x0c0b69a0u: goto P_0c0b69a0;
case 0x0c0b69a2u: goto P_0c0b69a2;
case 0x0c0b69a4u: goto P_0c0b69a4;
case 0x0c0b69a6u: goto P_0c0b69a6;
case 0x0c0b69a8u: goto P_0c0b69a8;
case 0x0c0b69aau: goto P_0c0b69aa;
case 0x0c0b69acu: goto P_0c0b69ac;
case 0x0c0b69aeu: goto P_0c0b69ae;
case 0x0c0b69b0u: goto P_0c0b69b0;
case 0x0c0b69b2u: goto P_0c0b69b2;
case 0x0c0b69b4u: goto P_0c0b69b4;
case 0x0c0b69b6u: goto P_0c0b69b6;
case 0x0c0b69b8u: goto P_0c0b69b8;
case 0x0c0b69bau: goto P_0c0b69ba;
case 0x0c0b69bcu: goto P_0c0b69bc;
case 0x0c0b69beu: goto P_0c0b69be;
case 0x0c0b69c0u: goto P_0c0b69c0;
case 0x0c0b69c2u: goto P_0c0b69c2;
case 0x0c0b69c4u: goto P_0c0b69c4;
case 0x0c0b69c6u: goto P_0c0b69c6;
case 0x0c0b69c8u: goto P_0c0b69c8;
case 0x0c0b69cau: goto P_0c0b69ca;
case 0x0c0b69ccu: goto P_0c0b69cc;
case 0x0c0b69ceu: goto P_0c0b69ce;
case 0x0c0b69d0u: goto P_0c0b69d0;
case 0x0c0b69d2u: goto P_0c0b69d2;
case 0x0c0b69d4u: goto P_0c0b69d4;
case 0x0c0b69d6u: goto P_0c0b69d6;
case 0x0c0b69d8u: goto P_0c0b69d8;
case 0x0c0b69dau: goto P_0c0b69da;
case 0x0c0b69dcu: goto P_0c0b69dc;
case 0x0c0b69deu: goto P_0c0b69de;
case 0x0c0b69e0u: goto P_0c0b69e0;
case 0x0c0b69e2u: goto P_0c0b69e2;
case 0x0c0b69e4u: goto P_0c0b69e4;
case 0x0c0b69e6u: goto P_0c0b69e6;
case 0x0c0b69e8u: goto P_0c0b69e8;
case 0x0c0b69eau: goto P_0c0b69ea;
case 0x0c0b69ecu: goto P_0c0b69ec;
case 0x0c0b69eeu: goto P_0c0b69ee;
case 0x0c0b69f0u: goto P_0c0b69f0;
case 0x0c0b69f2u: goto P_0c0b69f2;
case 0x0c0b69f4u: goto P_0c0b69f4;
case 0x0c0b69f6u: goto P_0c0b69f6;
case 0x0c0b69f8u: goto P_0c0b69f8;
case 0x0c0b69fau: goto P_0c0b69fa;
case 0x0c0b69fcu: goto P_0c0b69fc;
case 0x0c0b69feu: goto P_0c0b69fe;
case 0x0c0b6a00u: goto P_0c0b6a00;
case 0x0c0b6a02u: goto P_0c0b6a02;
case 0x0c0b6a04u: goto P_0c0b6a04;
case 0x0c0b6a06u: goto P_0c0b6a06;
case 0x0c0b6a08u: goto P_0c0b6a08;
case 0x0c0b6a0au: goto P_0c0b6a0a;
case 0x0c0b6a0cu: goto P_0c0b6a0c;
case 0x0c0b6a0eu: goto P_0c0b6a0e;
case 0x0c0b6a10u: goto P_0c0b6a10;
case 0x0c0b6a12u: goto P_0c0b6a12;
case 0x0c0b6a14u: goto P_0c0b6a14;
case 0x0c0b6a16u: goto P_0c0b6a16;
case 0x0c0b6a18u: goto P_0c0b6a18;
case 0x0c0b6a1au: goto P_0c0b6a1a;
case 0x0c0b6a1cu: goto P_0c0b6a1c;
case 0x0c0b6a1eu: goto P_0c0b6a1e;
case 0x0c0b6a20u: goto P_0c0b6a20;
case 0x0c0b6a22u: goto P_0c0b6a22;
case 0x0c0b6a24u: goto P_0c0b6a24;
case 0x0c0b6a26u: goto P_0c0b6a26;
case 0x0c0b6a28u: goto P_0c0b6a28;
case 0x0c0b6a2au: goto P_0c0b6a2a;
case 0x0c0b6a2cu: goto P_0c0b6a2c;
case 0x0c0b6a2eu: goto P_0c0b6a2e;
case 0x0c0b6a30u: goto P_0c0b6a30;
case 0x0c0b6a32u: goto P_0c0b6a32;
case 0x0c0b6a34u: goto P_0c0b6a34;
case 0x0c0b6a36u: goto P_0c0b6a36;
case 0x0c0b6a38u: goto P_0c0b6a38;
case 0x0c0b6a3au: goto P_0c0b6a3a;
case 0x0c0b6a3cu: goto P_0c0b6a3c;
case 0x0c0b6a3eu: goto P_0c0b6a3e;
case 0x0c0b6a40u: goto P_0c0b6a40;
case 0x0c0b6a42u: goto P_0c0b6a42;
case 0x0c0b6a44u: goto P_0c0b6a44;
case 0x0c0b6a46u: goto P_0c0b6a46;
case 0x0c0b6a48u: goto P_0c0b6a48;
case 0x0c0b6a4au: goto P_0c0b6a4a;
case 0x0c0b6a4cu: goto P_0c0b6a4c;
case 0x0c0b6a4eu: goto P_0c0b6a4e;
case 0x0c0b6a50u: goto P_0c0b6a50;
case 0x0c0b6a52u: goto P_0c0b6a52;
case 0x0c0b6a54u: goto P_0c0b6a54;
case 0x0c0b6a56u: goto P_0c0b6a56;
case 0x0c0b6a58u: goto P_0c0b6a58;
case 0x0c0b6a5au: goto P_0c0b6a5a;
case 0x0c0b6a5cu: goto P_0c0b6a5c;
case 0x0c0b6a5eu: goto P_0c0b6a5e;
case 0x0c0b6a60u: goto P_0c0b6a60;
case 0x0c0b6a62u: goto P_0c0b6a62;
case 0x0c0b6a64u: goto P_0c0b6a64;
case 0x0c0b6a66u: goto P_0c0b6a66;
case 0x0c0b6a68u: goto P_0c0b6a68;
case 0x0c0b6a6au: goto P_0c0b6a6a;
case 0x0c0b6a6cu: goto P_0c0b6a6c;
case 0x0c0b6ae6u: goto P_0c0b6ae6;
case 0x0c0b6ae8u: goto P_0c0b6ae8;
case 0x0c0b6aeau: goto P_0c0b6aea;
case 0x0c0b6aecu: goto P_0c0b6aec;
case 0x0c0b6aeeu: goto P_0c0b6aee;
case 0x0c0b6af0u: goto P_0c0b6af0;
case 0x0c0b6af2u: goto P_0c0b6af2;
case 0x0c0b6af4u: goto P_0c0b6af4;
case 0x0c0b6af6u: goto P_0c0b6af6;
case 0x0c0b6af8u: goto P_0c0b6af8;
case 0x0c0b6afau: goto P_0c0b6afa;
case 0x0c0b6afcu: goto P_0c0b6afc;
case 0x0c0b6afeu: goto P_0c0b6afe;
case 0x0c0b6b00u: goto P_0c0b6b00;
case 0x0c0b6b02u: goto P_0c0b6b02;
case 0x0c0b6b04u: goto P_0c0b6b04;
case 0x0c0b6b06u: goto P_0c0b6b06;
case 0x0c0b6b08u: goto P_0c0b6b08;
case 0x0c0b6b0au: goto P_0c0b6b0a;
case 0x0c0b6b0cu: goto P_0c0b6b0c;
case 0x0c0b6b0eu: goto P_0c0b6b0e;
case 0x0c0b6b10u: goto P_0c0b6b10;
case 0x0c0b6b12u: goto P_0c0b6b12;
case 0x0c0b6b14u: goto P_0c0b6b14;
case 0x0c0b6b16u: goto P_0c0b6b16;
case 0x0c0b6b18u: goto P_0c0b6b18;
case 0x0c0b6b1au: goto P_0c0b6b1a;
case 0x0c0b6b1cu: goto P_0c0b6b1c;
case 0x0c0b6b1eu: goto P_0c0b6b1e;
case 0x0c0b6b20u: goto P_0c0b6b20;
case 0x0c0b6b22u: goto P_0c0b6b22;
case 0x0c0b6b24u: goto P_0c0b6b24;
case 0x0c0b6b26u: goto P_0c0b6b26;
case 0x0c0b6b28u: goto P_0c0b6b28;
case 0x0c0b6b2au: goto P_0c0b6b2a;
case 0x0c0b6b2cu: goto P_0c0b6b2c;
case 0x0c0b6b2eu: goto P_0c0b6b2e;
case 0x0c0b6b30u: goto P_0c0b6b30;
case 0x0c0b6b32u: goto P_0c0b6b32;
case 0x0c0b6b34u: goto P_0c0b6b34;
case 0x0c0b6b36u: goto P_0c0b6b36;
case 0x0c0b6b38u: goto P_0c0b6b38;
case 0x0c0b6b3au: goto P_0c0b6b3a;
case 0x0c0b6b3cu: goto P_0c0b6b3c;
case 0x0c0b6b3eu: goto P_0c0b6b3e;
case 0x0c0b6b40u: goto P_0c0b6b40;
case 0x0c0b6b42u: goto P_0c0b6b42;
case 0x0c0b6b44u: goto P_0c0b6b44;
case 0x0c0b6b46u: goto P_0c0b6b46;
case 0x0c0b6b48u: goto P_0c0b6b48;
case 0x0c0b6b4au: goto P_0c0b6b4a;
case 0x0c0b6b4cu: goto P_0c0b6b4c;
case 0x0c0b6b4eu: goto P_0c0b6b4e;
case 0x0c0b6b50u: goto P_0c0b6b50;
case 0x0c0b6b52u: goto P_0c0b6b52;
case 0x0c0b6b54u: goto P_0c0b6b54;
case 0x0c0b6b56u: goto P_0c0b6b56;
case 0x0c0b6b58u: goto P_0c0b6b58;
case 0x0c0b6b5au: goto P_0c0b6b5a;
case 0x0c0b6b5cu: goto P_0c0b6b5c;
case 0x0c0b6b5eu: goto P_0c0b6b5e;
case 0x0c0b6b60u: goto P_0c0b6b60;
case 0x0c0b6b62u: goto P_0c0b6b62;
case 0x0c0b6b64u: goto P_0c0b6b64;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0b6742: /* original 2fe6, guest PC 0x0c0b6742 */
if(!s->budget--) { s->failed_pc=0x0c0b6742u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6744;
P_0c0b6744: /* original 2fd6, guest PC 0x0c0b6744 */
if(!s->budget--) { s->failed_pc=0x0c0b6744u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6746;
P_0c0b6746: /* original 2fc6, guest PC 0x0c0b6746 */
if(!s->budget--) { s->failed_pc=0x0c0b6746u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b6748;
P_0c0b6748: /* original 2fb6, guest PC 0x0c0b6748 */
if(!s->budget--) { s->failed_pc=0x0c0b6748u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b674a;
P_0c0b674a: /* original 2fa6, guest PC 0x0c0b674a */
if(!s->budget--) { s->failed_pc=0x0c0b674au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b674c;
P_0c0b674c: /* original 2f96, guest PC 0x0c0b674c */
if(!s->budget--) { s->failed_pc=0x0c0b674cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b674e;
P_0c0b674e: /* original 4f22, guest PC 0x0c0b674e */
if(!s->budget--) { s->failed_pc=0x0c0b674eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b6750;
P_0c0b6750: /* original 5d44, guest PC 0x0c0b6750 */
if(!s->budget--) { s->failed_pc=0x0c0b6750u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b6752;
P_0c0b6752: /* original 94a8, guest PC 0x0c0b6752 */
if(!s->budget--) { s->failed_pc=0x0c0b6752u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68a6u,2);
goto P_0c0b6754;
P_0c0b6754: /* original de6e, guest PC 0x0c0b6754 */
if(!s->budget--) { s->failed_pc=0x0c0b6754u; return 0; }
r[14]=read(ram,0x0c0b6910u,4);
goto P_0c0b6756;
P_0c0b6756: /* original 7ff8, guest PC 0x0c0b6756 */
if(!s->budget--) { s->failed_pc=0x0c0b6756u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b6758;
P_0c0b6758: /* original 4e0b, guest PC 0x0c0b6758 */
if(!s->budget--) { s->failed_pc=0x0c0b6758u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b675cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b675cu) { target=s->pc; goto dispatch; }
goto P_0c0b675c;
P_0c0b675a: /* original 65d2, guest PC 0x0c0b675a */
if(!s->budget--) { s->failed_pc=0x0c0b675au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b675c;
P_0c0b675c: /* original 94a4, guest PC 0x0c0b675c */
if(!s->budget--) { s->failed_pc=0x0c0b675cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68a8u,2);
goto P_0c0b675e;
P_0c0b675e: /* original 4e0b, guest PC 0x0c0b675e */
if(!s->budget--) { s->failed_pc=0x0c0b675eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6762u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6762u) { target=s->pc; goto dispatch; }
goto P_0c0b6762;
P_0c0b6760: /* original 55d1, guest PC 0x0c0b6760 */
if(!s->budget--) { s->failed_pc=0x0c0b6760u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b6762;
P_0c0b6762: /* original 94a2, guest PC 0x0c0b6762 */
if(!s->budget--) { s->failed_pc=0x0c0b6762u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68aau,2);
goto P_0c0b6764;
P_0c0b6764: /* original 4e0b, guest PC 0x0c0b6764 */
if(!s->budget--) { s->failed_pc=0x0c0b6764u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6768u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6768u) { target=s->pc; goto dispatch; }
goto P_0c0b6768;
P_0c0b6766: /* original 55d2, guest PC 0x0c0b6766 */
if(!s->budget--) { s->failed_pc=0x0c0b6766u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b6768;
P_0c0b6768: /* original 94a0, guest PC 0x0c0b6768 */
if(!s->budget--) { s->failed_pc=0x0c0b6768u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68acu,2);
goto P_0c0b676a;
P_0c0b676a: /* original 4e0b, guest PC 0x0c0b676a */
if(!s->budget--) { s->failed_pc=0x0c0b676au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b676eu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b676eu) { target=s->pc; goto dispatch; }
goto P_0c0b676e;
P_0c0b676c: /* original 55d3, guest PC 0x0c0b676c */
if(!s->budget--) { s->failed_pc=0x0c0b676cu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b676e;
P_0c0b676e: /* original 949e, guest PC 0x0c0b676e */
if(!s->budget--) { s->failed_pc=0x0c0b676eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68aeu,2);
goto P_0c0b6770;
P_0c0b6770: /* original 4e0b, guest PC 0x0c0b6770 */
if(!s->budget--) { s->failed_pc=0x0c0b6770u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6774u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6774u) { target=s->pc; goto dispatch; }
goto P_0c0b6774;
P_0c0b6772: /* original 55d4, guest PC 0x0c0b6772 */
if(!s->budget--) { s->failed_pc=0x0c0b6772u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b6774;
P_0c0b6774: /* original 949c, guest PC 0x0c0b6774 */
if(!s->budget--) { s->failed_pc=0x0c0b6774u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68b0u,2);
goto P_0c0b6776;
P_0c0b6776: /* original 4e0b, guest PC 0x0c0b6776 */
if(!s->budget--) { s->failed_pc=0x0c0b6776u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b677au;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b677au) { target=s->pc; goto dispatch; }
goto P_0c0b677a;
P_0c0b6778: /* original 55d5, guest PC 0x0c0b6778 */
if(!s->budget--) { s->failed_pc=0x0c0b6778u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b677a;
P_0c0b677a: /* original 949a, guest PC 0x0c0b677a */
if(!s->budget--) { s->failed_pc=0x0c0b677au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68b2u,2);
goto P_0c0b677c;
P_0c0b677c: /* original 4e0b, guest PC 0x0c0b677c */
if(!s->budget--) { s->failed_pc=0x0c0b677cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6780u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6780u) { target=s->pc; goto dispatch; }
goto P_0c0b6780;
P_0c0b677e: /* original 55d6, guest PC 0x0c0b677e */
if(!s->budget--) { s->failed_pc=0x0c0b677eu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b6780;
P_0c0b6780: /* original 9498, guest PC 0x0c0b6780 */
if(!s->budget--) { s->failed_pc=0x0c0b6780u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68b4u,2);
goto P_0c0b6782;
P_0c0b6782: /* original 4e0b, guest PC 0x0c0b6782 */
if(!s->budget--) { s->failed_pc=0x0c0b6782u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6786u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6786u) { target=s->pc; goto dispatch; }
goto P_0c0b6786;
P_0c0b6784: /* original 55d7, guest PC 0x0c0b6784 */
if(!s->budget--) { s->failed_pc=0x0c0b6784u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b6786;
P_0c0b6786: /* original 9496, guest PC 0x0c0b6786 */
if(!s->budget--) { s->failed_pc=0x0c0b6786u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68b6u,2);
goto P_0c0b6788;
P_0c0b6788: /* original 4e0b, guest PC 0x0c0b6788 */
if(!s->budget--) { s->failed_pc=0x0c0b6788u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b678cu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b678cu) { target=s->pc; goto dispatch; }
goto P_0c0b678c;
P_0c0b678a: /* original 55d8, guest PC 0x0c0b678a */
if(!s->budget--) { s->failed_pc=0x0c0b678au; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b678c;
P_0c0b678c: /* original 9494, guest PC 0x0c0b678c */
if(!s->budget--) { s->failed_pc=0x0c0b678cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68b8u,2);
goto P_0c0b678e;
P_0c0b678e: /* original 4e0b, guest PC 0x0c0b678e */
if(!s->budget--) { s->failed_pc=0x0c0b678eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6792u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6792u) { target=s->pc; goto dispatch; }
goto P_0c0b6792;
P_0c0b6790: /* original 55d9, guest PC 0x0c0b6790 */
if(!s->budget--) { s->failed_pc=0x0c0b6790u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b6792;
P_0c0b6792: /* original 9492, guest PC 0x0c0b6792 */
if(!s->budget--) { s->failed_pc=0x0c0b6792u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68bau,2);
goto P_0c0b6794;
P_0c0b6794: /* original 4e0b, guest PC 0x0c0b6794 */
if(!s->budget--) { s->failed_pc=0x0c0b6794u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6798u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6798u) { target=s->pc; goto dispatch; }
goto P_0c0b6798;
P_0c0b6796: /* original 55da, guest PC 0x0c0b6796 */
if(!s->budget--) { s->failed_pc=0x0c0b6796u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b6798;
P_0c0b6798: /* original 9490, guest PC 0x0c0b6798 */
if(!s->budget--) { s->failed_pc=0x0c0b6798u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68bcu,2);
goto P_0c0b679a;
P_0c0b679a: /* original 4e0b, guest PC 0x0c0b679a */
if(!s->budget--) { s->failed_pc=0x0c0b679au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b679eu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b679eu) { target=s->pc; goto dispatch; }
goto P_0c0b679e;
P_0c0b679c: /* original 55db, guest PC 0x0c0b679c */
if(!s->budget--) { s->failed_pc=0x0c0b679cu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b679e;
P_0c0b679e: /* original 948e, guest PC 0x0c0b679e */
if(!s->budget--) { s->failed_pc=0x0c0b679eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68beu,2);
goto P_0c0b67a0;
P_0c0b67a0: /* original 4e0b, guest PC 0x0c0b67a0 */
if(!s->budget--) { s->failed_pc=0x0c0b67a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67a4u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67a4u) { target=s->pc; goto dispatch; }
goto P_0c0b67a4;
P_0c0b67a2: /* original 55dc, guest PC 0x0c0b67a2 */
if(!s->budget--) { s->failed_pc=0x0c0b67a2u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b67a4;
P_0c0b67a4: /* original 948c, guest PC 0x0c0b67a4 */
if(!s->budget--) { s->failed_pc=0x0c0b67a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68c0u,2);
goto P_0c0b67a6;
P_0c0b67a6: /* original 4e0b, guest PC 0x0c0b67a6 */
if(!s->budget--) { s->failed_pc=0x0c0b67a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67aau;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67aau) { target=s->pc; goto dispatch; }
goto P_0c0b67aa;
P_0c0b67a8: /* original 55dd, guest PC 0x0c0b67a8 */
if(!s->budget--) { s->failed_pc=0x0c0b67a8u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b67aa;
P_0c0b67aa: /* original 948a, guest PC 0x0c0b67aa */
if(!s->budget--) { s->failed_pc=0x0c0b67aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68c2u,2);
goto P_0c0b67ac;
P_0c0b67ac: /* original 4e0b, guest PC 0x0c0b67ac */
if(!s->budget--) { s->failed_pc=0x0c0b67acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67b0u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67b0u) { target=s->pc; goto dispatch; }
goto P_0c0b67b0;
P_0c0b67ae: /* original 55de, guest PC 0x0c0b67ae */
if(!s->budget--) { s->failed_pc=0x0c0b67aeu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b67b0;
P_0c0b67b0: /* original 9488, guest PC 0x0c0b67b0 */
if(!s->budget--) { s->failed_pc=0x0c0b67b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68c4u,2);
goto P_0c0b67b2;
P_0c0b67b2: /* original 4e0b, guest PC 0x0c0b67b2 */
if(!s->budget--) { s->failed_pc=0x0c0b67b2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67b6u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67b6u) { target=s->pc; goto dispatch; }
goto P_0c0b67b6;
P_0c0b67b4: /* original 55df, guest PC 0x0c0b67b4 */
if(!s->budget--) { s->failed_pc=0x0c0b67b4u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b67b6;
P_0c0b67b6: /* original 9486, guest PC 0x0c0b67b6 */
if(!s->budget--) { s->failed_pc=0x0c0b67b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68c6u,2);
goto P_0c0b67b8;
P_0c0b67b8: /* original e040, guest PC 0x0c0b67b8 */
if(!s->budget--) { s->failed_pc=0x0c0b67b8u; return 0; }
r[0]=0x00000040u;
goto P_0c0b67ba;
P_0c0b67ba: /* original 4e0b, guest PC 0x0c0b67ba */
if(!s->budget--) { s->failed_pc=0x0c0b67bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67beu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67beu) { target=s->pc; goto dispatch; }
goto P_0c0b67be;
P_0c0b67bc: /* original 05de, guest PC 0x0c0b67bc */
if(!s->budget--) { s->failed_pc=0x0c0b67bcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67be;
P_0c0b67be: /* original 9483, guest PC 0x0c0b67be */
if(!s->budget--) { s->failed_pc=0x0c0b67beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68c8u,2);
goto P_0c0b67c0;
P_0c0b67c0: /* original e044, guest PC 0x0c0b67c0 */
if(!s->budget--) { s->failed_pc=0x0c0b67c0u; return 0; }
r[0]=0x00000044u;
goto P_0c0b67c2;
P_0c0b67c2: /* original 4e0b, guest PC 0x0c0b67c2 */
if(!s->budget--) { s->failed_pc=0x0c0b67c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67c6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67c6u) { target=s->pc; goto dispatch; }
goto P_0c0b67c6;
P_0c0b67c4: /* original 05de, guest PC 0x0c0b67c4 */
if(!s->budget--) { s->failed_pc=0x0c0b67c4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67c6;
P_0c0b67c6: /* original 9480, guest PC 0x0c0b67c6 */
if(!s->budget--) { s->failed_pc=0x0c0b67c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68cau,2);
goto P_0c0b67c8;
P_0c0b67c8: /* original e048, guest PC 0x0c0b67c8 */
if(!s->budget--) { s->failed_pc=0x0c0b67c8u; return 0; }
r[0]=0x00000048u;
goto P_0c0b67ca;
P_0c0b67ca: /* original 4e0b, guest PC 0x0c0b67ca */
if(!s->budget--) { s->failed_pc=0x0c0b67cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67ceu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67ceu) { target=s->pc; goto dispatch; }
goto P_0c0b67ce;
P_0c0b67cc: /* original 05de, guest PC 0x0c0b67cc */
if(!s->budget--) { s->failed_pc=0x0c0b67ccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67ce;
P_0c0b67ce: /* original 947d, guest PC 0x0c0b67ce */
if(!s->budget--) { s->failed_pc=0x0c0b67ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68ccu,2);
goto P_0c0b67d0;
P_0c0b67d0: /* original e04c, guest PC 0x0c0b67d0 */
if(!s->budget--) { s->failed_pc=0x0c0b67d0u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b67d2;
P_0c0b67d2: /* original 4e0b, guest PC 0x0c0b67d2 */
if(!s->budget--) { s->failed_pc=0x0c0b67d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67d6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67d6u) { target=s->pc; goto dispatch; }
goto P_0c0b67d6;
P_0c0b67d4: /* original 05de, guest PC 0x0c0b67d4 */
if(!s->budget--) { s->failed_pc=0x0c0b67d4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67d6;
P_0c0b67d6: /* original 947a, guest PC 0x0c0b67d6 */
if(!s->budget--) { s->failed_pc=0x0c0b67d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68ceu,2);
goto P_0c0b67d8;
P_0c0b67d8: /* original e050, guest PC 0x0c0b67d8 */
if(!s->budget--) { s->failed_pc=0x0c0b67d8u; return 0; }
r[0]=0x00000050u;
goto P_0c0b67da;
P_0c0b67da: /* original 4e0b, guest PC 0x0c0b67da */
if(!s->budget--) { s->failed_pc=0x0c0b67dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67deu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67deu) { target=s->pc; goto dispatch; }
goto P_0c0b67de;
P_0c0b67dc: /* original 05de, guest PC 0x0c0b67dc */
if(!s->budget--) { s->failed_pc=0x0c0b67dcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67de;
P_0c0b67de: /* original 9477, guest PC 0x0c0b67de */
if(!s->budget--) { s->failed_pc=0x0c0b67deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68d0u,2);
goto P_0c0b67e0;
P_0c0b67e0: /* original e054, guest PC 0x0c0b67e0 */
if(!s->budget--) { s->failed_pc=0x0c0b67e0u; return 0; }
r[0]=0x00000054u;
goto P_0c0b67e2;
P_0c0b67e2: /* original 4e0b, guest PC 0x0c0b67e2 */
if(!s->budget--) { s->failed_pc=0x0c0b67e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67e6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67e6u) { target=s->pc; goto dispatch; }
goto P_0c0b67e6;
P_0c0b67e4: /* original 05de, guest PC 0x0c0b67e4 */
if(!s->budget--) { s->failed_pc=0x0c0b67e4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67e6;
P_0c0b67e6: /* original 9474, guest PC 0x0c0b67e6 */
if(!s->budget--) { s->failed_pc=0x0c0b67e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68d2u,2);
goto P_0c0b67e8;
P_0c0b67e8: /* original e058, guest PC 0x0c0b67e8 */
if(!s->budget--) { s->failed_pc=0x0c0b67e8u; return 0; }
r[0]=0x00000058u;
goto P_0c0b67ea;
P_0c0b67ea: /* original 4e0b, guest PC 0x0c0b67ea */
if(!s->budget--) { s->failed_pc=0x0c0b67eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67eeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67eeu) { target=s->pc; goto dispatch; }
goto P_0c0b67ee;
P_0c0b67ec: /* original 05de, guest PC 0x0c0b67ec */
if(!s->budget--) { s->failed_pc=0x0c0b67ecu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67ee;
P_0c0b67ee: /* original 9471, guest PC 0x0c0b67ee */
if(!s->budget--) { s->failed_pc=0x0c0b67eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68d4u,2);
goto P_0c0b67f0;
P_0c0b67f0: /* original e05c, guest PC 0x0c0b67f0 */
if(!s->budget--) { s->failed_pc=0x0c0b67f0u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b67f2;
P_0c0b67f2: /* original 4e0b, guest PC 0x0c0b67f2 */
if(!s->budget--) { s->failed_pc=0x0c0b67f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67f6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67f6u) { target=s->pc; goto dispatch; }
goto P_0c0b67f6;
P_0c0b67f4: /* original 05de, guest PC 0x0c0b67f4 */
if(!s->budget--) { s->failed_pc=0x0c0b67f4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67f6;
P_0c0b67f6: /* original 946e, guest PC 0x0c0b67f6 */
if(!s->budget--) { s->failed_pc=0x0c0b67f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68d6u,2);
goto P_0c0b67f8;
P_0c0b67f8: /* original e060, guest PC 0x0c0b67f8 */
if(!s->budget--) { s->failed_pc=0x0c0b67f8u; return 0; }
r[0]=0x00000060u;
goto P_0c0b67fa;
P_0c0b67fa: /* original 4e0b, guest PC 0x0c0b67fa */
if(!s->budget--) { s->failed_pc=0x0c0b67fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b67feu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b67feu) { target=s->pc; goto dispatch; }
goto P_0c0b67fe;
P_0c0b67fc: /* original 05de, guest PC 0x0c0b67fc */
if(!s->budget--) { s->failed_pc=0x0c0b67fcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b67fe;
P_0c0b67fe: /* original 946b, guest PC 0x0c0b67fe */
if(!s->budget--) { s->failed_pc=0x0c0b67feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68d8u,2);
goto P_0c0b6800;
P_0c0b6800: /* original e064, guest PC 0x0c0b6800 */
if(!s->budget--) { s->failed_pc=0x0c0b6800u; return 0; }
r[0]=0x00000064u;
goto P_0c0b6802;
P_0c0b6802: /* original 4e0b, guest PC 0x0c0b6802 */
if(!s->budget--) { s->failed_pc=0x0c0b6802u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6806u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6806u) { target=s->pc; goto dispatch; }
goto P_0c0b6806;
P_0c0b6804: /* original 05de, guest PC 0x0c0b6804 */
if(!s->budget--) { s->failed_pc=0x0c0b6804u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6806;
P_0c0b6806: /* original 9468, guest PC 0x0c0b6806 */
if(!s->budget--) { s->failed_pc=0x0c0b6806u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68dau,2);
goto P_0c0b6808;
P_0c0b6808: /* original e068, guest PC 0x0c0b6808 */
if(!s->budget--) { s->failed_pc=0x0c0b6808u; return 0; }
r[0]=0x00000068u;
goto P_0c0b680a;
P_0c0b680a: /* original 4e0b, guest PC 0x0c0b680a */
if(!s->budget--) { s->failed_pc=0x0c0b680au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b680eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b680eu) { target=s->pc; goto dispatch; }
goto P_0c0b680e;
P_0c0b680c: /* original 05de, guest PC 0x0c0b680c */
if(!s->budget--) { s->failed_pc=0x0c0b680cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b680e;
P_0c0b680e: /* original 9465, guest PC 0x0c0b680e */
if(!s->budget--) { s->failed_pc=0x0c0b680eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68dcu,2);
goto P_0c0b6810;
P_0c0b6810: /* original e06c, guest PC 0x0c0b6810 */
if(!s->budget--) { s->failed_pc=0x0c0b6810u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b6812;
P_0c0b6812: /* original 4e0b, guest PC 0x0c0b6812 */
if(!s->budget--) { s->failed_pc=0x0c0b6812u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6816u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6816u) { target=s->pc; goto dispatch; }
goto P_0c0b6816;
P_0c0b6814: /* original 05de, guest PC 0x0c0b6814 */
if(!s->budget--) { s->failed_pc=0x0c0b6814u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6816;
P_0c0b6816: /* original 9462, guest PC 0x0c0b6816 */
if(!s->budget--) { s->failed_pc=0x0c0b6816u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68deu,2);
goto P_0c0b6818;
P_0c0b6818: /* original e070, guest PC 0x0c0b6818 */
if(!s->budget--) { s->failed_pc=0x0c0b6818u; return 0; }
r[0]=0x00000070u;
goto P_0c0b681a;
P_0c0b681a: /* original 4e0b, guest PC 0x0c0b681a */
if(!s->budget--) { s->failed_pc=0x0c0b681au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b681eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b681eu) { target=s->pc; goto dispatch; }
goto P_0c0b681e;
P_0c0b681c: /* original 05de, guest PC 0x0c0b681c */
if(!s->budget--) { s->failed_pc=0x0c0b681cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b681e;
P_0c0b681e: /* original 945f, guest PC 0x0c0b681e */
if(!s->budget--) { s->failed_pc=0x0c0b681eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68e0u,2);
goto P_0c0b6820;
P_0c0b6820: /* original e074, guest PC 0x0c0b6820 */
if(!s->budget--) { s->failed_pc=0x0c0b6820u; return 0; }
r[0]=0x00000074u;
goto P_0c0b6822;
P_0c0b6822: /* original 4e0b, guest PC 0x0c0b6822 */
if(!s->budget--) { s->failed_pc=0x0c0b6822u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6826u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6826u) { target=s->pc; goto dispatch; }
goto P_0c0b6826;
P_0c0b6824: /* original 05de, guest PC 0x0c0b6824 */
if(!s->budget--) { s->failed_pc=0x0c0b6824u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6826;
P_0c0b6826: /* original 945c, guest PC 0x0c0b6826 */
if(!s->budget--) { s->failed_pc=0x0c0b6826u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68e2u,2);
goto P_0c0b6828;
P_0c0b6828: /* original e078, guest PC 0x0c0b6828 */
if(!s->budget--) { s->failed_pc=0x0c0b6828u; return 0; }
r[0]=0x00000078u;
goto P_0c0b682a;
P_0c0b682a: /* original 4e0b, guest PC 0x0c0b682a */
if(!s->budget--) { s->failed_pc=0x0c0b682au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b682eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b682eu) { target=s->pc; goto dispatch; }
goto P_0c0b682e;
P_0c0b682c: /* original 05de, guest PC 0x0c0b682c */
if(!s->budget--) { s->failed_pc=0x0c0b682cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b682e;
P_0c0b682e: /* original 9459, guest PC 0x0c0b682e */
if(!s->budget--) { s->failed_pc=0x0c0b682eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68e4u,2);
goto P_0c0b6830;
P_0c0b6830: /* original e07c, guest PC 0x0c0b6830 */
if(!s->budget--) { s->failed_pc=0x0c0b6830u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b6832;
P_0c0b6832: /* original 4e0b, guest PC 0x0c0b6832 */
if(!s->budget--) { s->failed_pc=0x0c0b6832u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6836u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6836u) { target=s->pc; goto dispatch; }
goto P_0c0b6836;
P_0c0b6834: /* original 05de, guest PC 0x0c0b6834 */
if(!s->budget--) { s->failed_pc=0x0c0b6834u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6836;
P_0c0b6836: /* original 9457, guest PC 0x0c0b6836 */
if(!s->budget--) { s->failed_pc=0x0c0b6836u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68e8u,2);
goto P_0c0b6838;
P_0c0b6838: /* original 9055, guest PC 0x0c0b6838 */
if(!s->budget--) { s->failed_pc=0x0c0b6838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68e6u,2);
goto P_0c0b683a;
P_0c0b683a: /* original 4e0b, guest PC 0x0c0b683a */
if(!s->budget--) { s->failed_pc=0x0c0b683au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b683eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b683eu) { target=s->pc; goto dispatch; }
goto P_0c0b683e;
P_0c0b683c: /* original 05de, guest PC 0x0c0b683c */
if(!s->budget--) { s->failed_pc=0x0c0b683cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b683e;
P_0c0b683e: /* original 9554, guest PC 0x0c0b683e */
if(!s->budget--) { s->failed_pc=0x0c0b683eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68eau,2);
goto P_0c0b6840;
P_0c0b6840: /* original 35dc, guest PC 0x0c0b6840 */
if(!s->budget--) { s->failed_pc=0x0c0b6840u; return 0; }
r[5]+=r[13];
goto P_0c0b6842;
P_0c0b6842: /* original 2f52, guest PC 0x0c0b6842 */
if(!s->budget--) { s->failed_pc=0x0c0b6842u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6844;
P_0c0b6844: /* original 9452, guest PC 0x0c0b6844 */
if(!s->budget--) { s->failed_pc=0x0c0b6844u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68ecu,2);
goto P_0c0b6846;
P_0c0b6846: /* original 4e0b, guest PC 0x0c0b6846 */
if(!s->budget--) { s->failed_pc=0x0c0b6846u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b684au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b684au) { target=s->pc; goto dispatch; }
goto P_0c0b684a;
P_0c0b6848: /* original 6552, guest PC 0x0c0b6848 */
if(!s->budget--) { s->failed_pc=0x0c0b6848u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b684a;
P_0c0b684a: /* original 9550, guest PC 0x0c0b684a */
if(!s->budget--) { s->failed_pc=0x0c0b684au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68eeu,2);
goto P_0c0b684c;
P_0c0b684c: /* original 35dc, guest PC 0x0c0b684c */
if(!s->budget--) { s->failed_pc=0x0c0b684cu; return 0; }
r[5]+=r[13];
goto P_0c0b684e;
P_0c0b684e: /* original 1f51, guest PC 0x0c0b684e */
if(!s->budget--) { s->failed_pc=0x0c0b684eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b6850;
P_0c0b6850: /* original 944e, guest PC 0x0c0b6850 */
if(!s->budget--) { s->failed_pc=0x0c0b6850u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68f0u,2);
goto P_0c0b6852;
P_0c0b6852: /* original 4e0b, guest PC 0x0c0b6852 */
if(!s->budget--) { s->failed_pc=0x0c0b6852u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6856u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6856u) { target=s->pc; goto dispatch; }
goto P_0c0b6856;
P_0c0b6854: /* original 6552, guest PC 0x0c0b6854 */
if(!s->budget--) { s->failed_pc=0x0c0b6854u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6856;
P_0c0b6856: /* original 944d, guest PC 0x0c0b6856 */
if(!s->budget--) { s->failed_pc=0x0c0b6856u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68f4u,2);
goto P_0c0b6858;
P_0c0b6858: /* original 904b, guest PC 0x0c0b6858 */
if(!s->budget--) { s->failed_pc=0x0c0b6858u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68f2u,2);
goto P_0c0b685a;
P_0c0b685a: /* original 4e0b, guest PC 0x0c0b685a */
if(!s->budget--) { s->failed_pc=0x0c0b685au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b685eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b685eu) { target=s->pc; goto dispatch; }
goto P_0c0b685e;
P_0c0b685c: /* original 05de, guest PC 0x0c0b685c */
if(!s->budget--) { s->failed_pc=0x0c0b685cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b685e;
P_0c0b685e: /* original 944b, guest PC 0x0c0b685e */
if(!s->budget--) { s->failed_pc=0x0c0b685eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68f8u,2);
goto P_0c0b6860;
P_0c0b6860: /* original 9049, guest PC 0x0c0b6860 */
if(!s->budget--) { s->failed_pc=0x0c0b6860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68f6u,2);
goto P_0c0b6862;
P_0c0b6862: /* original 4e0b, guest PC 0x0c0b6862 */
if(!s->budget--) { s->failed_pc=0x0c0b6862u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6866u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6866u) { target=s->pc; goto dispatch; }
goto P_0c0b6866;
P_0c0b6864: /* original 05de, guest PC 0x0c0b6864 */
if(!s->budget--) { s->failed_pc=0x0c0b6864u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6866;
P_0c0b6866: /* original 9948, guest PC 0x0c0b6866 */
if(!s->budget--) { s->failed_pc=0x0c0b6866u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68fau,2);
goto P_0c0b6868;
P_0c0b6868: /* original 9448, guest PC 0x0c0b6868 */
if(!s->budget--) { s->failed_pc=0x0c0b6868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68fcu,2);
goto P_0c0b686a;
P_0c0b686a: /* original 39dc, guest PC 0x0c0b686a */
if(!s->budget--) { s->failed_pc=0x0c0b686au; return 0; }
r[9]+=r[13];
goto P_0c0b686c;
P_0c0b686c: /* original 4e0b, guest PC 0x0c0b686c */
if(!s->budget--) { s->failed_pc=0x0c0b686cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6870u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6870u) { target=s->pc; goto dispatch; }
goto P_0c0b6870;
P_0c0b686e: /* original 6592, guest PC 0x0c0b686e */
if(!s->budget--) { s->failed_pc=0x0c0b686eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6870;
P_0c0b6870: /* original 9445, guest PC 0x0c0b6870 */
if(!s->budget--) { s->failed_pc=0x0c0b6870u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b68feu,2);
goto P_0c0b6872;
P_0c0b6872: /* original 4e0b, guest PC 0x0c0b6872 */
if(!s->budget--) { s->failed_pc=0x0c0b6872u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6876u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6876u) { target=s->pc; goto dispatch; }
goto P_0c0b6876;
P_0c0b6874: /* original 6592, guest PC 0x0c0b6874 */
if(!s->budget--) { s->failed_pc=0x0c0b6874u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6876;
P_0c0b6876: /* original 9443, guest PC 0x0c0b6876 */
if(!s->budget--) { s->failed_pc=0x0c0b6876u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6900u,2);
goto P_0c0b6878;
P_0c0b6878: /* original 4e0b, guest PC 0x0c0b6878 */
if(!s->budget--) { s->failed_pc=0x0c0b6878u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b687cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b687cu) { target=s->pc; goto dispatch; }
goto P_0c0b687c;
P_0c0b687a: /* original 6592, guest PC 0x0c0b687a */
if(!s->budget--) { s->failed_pc=0x0c0b687au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b687c;
P_0c0b687c: /* original 9441, guest PC 0x0c0b687c */
if(!s->budget--) { s->failed_pc=0x0c0b687cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6902u,2);
goto P_0c0b687e;
P_0c0b687e: /* original 4e0b, guest PC 0x0c0b687e */
if(!s->budget--) { s->failed_pc=0x0c0b687eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6882u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6882u) { target=s->pc; goto dispatch; }
goto P_0c0b6882;
P_0c0b6880: /* original 6592, guest PC 0x0c0b6880 */
if(!s->budget--) { s->failed_pc=0x0c0b6880u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6882;
P_0c0b6882: /* original 9c3f, guest PC 0x0c0b6882 */
if(!s->budget--) { s->failed_pc=0x0c0b6882u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6904u,2);
goto P_0c0b6884;
P_0c0b6884: /* original 943f, guest PC 0x0c0b6884 */
if(!s->budget--) { s->failed_pc=0x0c0b6884u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6906u,2);
goto P_0c0b6886;
P_0c0b6886: /* original 3cdc, guest PC 0x0c0b6886 */
if(!s->budget--) { s->failed_pc=0x0c0b6886u; return 0; }
r[12]+=r[13];
goto P_0c0b6888;
P_0c0b6888: /* original 4e0b, guest PC 0x0c0b6888 */
if(!s->budget--) { s->failed_pc=0x0c0b6888u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b688cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b688cu) { target=s->pc; goto dispatch; }
goto P_0c0b688c;
P_0c0b688a: /* original 65c2, guest PC 0x0c0b688a */
if(!s->budget--) { s->failed_pc=0x0c0b688au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b688c;
P_0c0b688c: /* original 943c, guest PC 0x0c0b688c */
if(!s->budget--) { s->failed_pc=0x0c0b688cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6908u,2);
goto P_0c0b688e;
P_0c0b688e: /* original 4e0b, guest PC 0x0c0b688e */
if(!s->budget--) { s->failed_pc=0x0c0b688eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6892u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6892u) { target=s->pc; goto dispatch; }
goto P_0c0b6892;
P_0c0b6890: /* original 65c2, guest PC 0x0c0b6890 */
if(!s->budget--) { s->failed_pc=0x0c0b6890u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6892;
P_0c0b6892: /* original 943a, guest PC 0x0c0b6892 */
if(!s->budget--) { s->failed_pc=0x0c0b6892u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b690au,2);
goto P_0c0b6894;
P_0c0b6894: /* original 4e0b, guest PC 0x0c0b6894 */
if(!s->budget--) { s->failed_pc=0x0c0b6894u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6898u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6898u) { target=s->pc; goto dispatch; }
goto P_0c0b6898;
P_0c0b6896: /* original 65c2, guest PC 0x0c0b6896 */
if(!s->budget--) { s->failed_pc=0x0c0b6896u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6898;
P_0c0b6898: /* original 9438, guest PC 0x0c0b6898 */
if(!s->budget--) { s->failed_pc=0x0c0b6898u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b690cu,2);
goto P_0c0b689a;
P_0c0b689a: /* original 4e0b, guest PC 0x0c0b689a */
if(!s->budget--) { s->failed_pc=0x0c0b689au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b689eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b689eu) { target=s->pc; goto dispatch; }
goto P_0c0b689e;
P_0c0b689c: /* original 65c2, guest PC 0x0c0b689c */
if(!s->budget--) { s->failed_pc=0x0c0b689cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b689e;
P_0c0b689e: /* original 9b36, guest PC 0x0c0b689e */
if(!s->budget--) { s->failed_pc=0x0c0b689eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b690eu,2);
goto P_0c0b68a0;
P_0c0b68a0: /* original 3bdc, guest PC 0x0c0b68a0 */
if(!s->budget--) { s->failed_pc=0x0c0b68a0u; return 0; }
r[11]+=r[13];
goto P_0c0b68a2;
P_0c0b68a2: /* original a037, guest PC 0x0c0b68a2 */
if(!s->budget--) { s->failed_pc=0x0c0b68a2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6914;
P_0c0b68a4: /* original 65b2, guest PC 0x0c0b68a4 */
if(!s->budget--) { s->failed_pc=0x0c0b68a4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b68a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b68a6u; return 0; } return 1;
P_0c0b6914: /* original 94ab, guest PC 0x0c0b6914 */
if(!s->budget--) { s->failed_pc=0x0c0b6914u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a6eu,2);
goto P_0c0b6916;
P_0c0b6916: /* original 4e0b, guest PC 0x0c0b6916 */
if(!s->budget--) { s->failed_pc=0x0c0b6916u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b691au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b691au) { target=s->pc; goto dispatch; }
goto P_0c0b691a;
P_0c0b6918: /* original 0009, guest PC 0x0c0b6918 */
if(!s->budget--) { s->failed_pc=0x0c0b6918u; return 0; }
goto P_0c0b691a;
P_0c0b691a: /* original 94a9, guest PC 0x0c0b691a */
if(!s->budget--) { s->failed_pc=0x0c0b691au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a70u,2);
goto P_0c0b691c;
P_0c0b691c: /* original 4e0b, guest PC 0x0c0b691c */
if(!s->budget--) { s->failed_pc=0x0c0b691cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6920u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6920u) { target=s->pc; goto dispatch; }
goto P_0c0b6920;
P_0c0b691e: /* original 65b2, guest PC 0x0c0b691e */
if(!s->budget--) { s->failed_pc=0x0c0b691eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6920;
P_0c0b6920: /* original 94a7, guest PC 0x0c0b6920 */
if(!s->budget--) { s->failed_pc=0x0c0b6920u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a72u,2);
goto P_0c0b6922;
P_0c0b6922: /* original 4e0b, guest PC 0x0c0b6922 */
if(!s->budget--) { s->failed_pc=0x0c0b6922u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6926u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6926u) { target=s->pc; goto dispatch; }
goto P_0c0b6926;
P_0c0b6924: /* original 65b2, guest PC 0x0c0b6924 */
if(!s->budget--) { s->failed_pc=0x0c0b6924u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6926;
P_0c0b6926: /* original 94a5, guest PC 0x0c0b6926 */
if(!s->budget--) { s->failed_pc=0x0c0b6926u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a74u,2);
goto P_0c0b6928;
P_0c0b6928: /* original 4e0b, guest PC 0x0c0b6928 */
if(!s->budget--) { s->failed_pc=0x0c0b6928u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b692cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b692cu) { target=s->pc; goto dispatch; }
goto P_0c0b692c;
P_0c0b692a: /* original 65b2, guest PC 0x0c0b692a */
if(!s->budget--) { s->failed_pc=0x0c0b692au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b692c;
P_0c0b692c: /* original 9aa3, guest PC 0x0c0b692c */
if(!s->budget--) { s->failed_pc=0x0c0b692cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a76u,2);
goto P_0c0b692e;
P_0c0b692e: /* original 94a3, guest PC 0x0c0b692e */
if(!s->budget--) { s->failed_pc=0x0c0b692eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a78u,2);
goto P_0c0b6930;
P_0c0b6930: /* original 3adc, guest PC 0x0c0b6930 */
if(!s->budget--) { s->failed_pc=0x0c0b6930u; return 0; }
r[10]+=r[13];
goto P_0c0b6932;
P_0c0b6932: /* original 4e0b, guest PC 0x0c0b6932 */
if(!s->budget--) { s->failed_pc=0x0c0b6932u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6936u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6936u) { target=s->pc; goto dispatch; }
goto P_0c0b6936;
P_0c0b6934: /* original 65a2, guest PC 0x0c0b6934 */
if(!s->budget--) { s->failed_pc=0x0c0b6934u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b6936;
P_0c0b6936: /* original 94a0, guest PC 0x0c0b6936 */
if(!s->budget--) { s->failed_pc=0x0c0b6936u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a7au,2);
goto P_0c0b6938;
P_0c0b6938: /* original 4e0b, guest PC 0x0c0b6938 */
if(!s->budget--) { s->failed_pc=0x0c0b6938u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b693cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b693cu) { target=s->pc; goto dispatch; }
goto P_0c0b693c;
P_0c0b693a: /* original 65a2, guest PC 0x0c0b693a */
if(!s->budget--) { s->failed_pc=0x0c0b693au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b693c;
P_0c0b693c: /* original 949e, guest PC 0x0c0b693c */
if(!s->budget--) { s->failed_pc=0x0c0b693cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a7cu,2);
goto P_0c0b693e;
P_0c0b693e: /* original 4e0b, guest PC 0x0c0b693e */
if(!s->budget--) { s->failed_pc=0x0c0b693eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6942u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6942u) { target=s->pc; goto dispatch; }
goto P_0c0b6942;
P_0c0b6940: /* original 65a2, guest PC 0x0c0b6940 */
if(!s->budget--) { s->failed_pc=0x0c0b6940u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b6942;
P_0c0b6942: /* original 949c, guest PC 0x0c0b6942 */
if(!s->budget--) { s->failed_pc=0x0c0b6942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a7eu,2);
goto P_0c0b6944;
P_0c0b6944: /* original 4e0b, guest PC 0x0c0b6944 */
if(!s->budget--) { s->failed_pc=0x0c0b6944u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6948u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6948u) { target=s->pc; goto dispatch; }
goto P_0c0b6948;
P_0c0b6946: /* original 65a2, guest PC 0x0c0b6946 */
if(!s->budget--) { s->failed_pc=0x0c0b6946u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b6948;
P_0c0b6948: /* original 949a, guest PC 0x0c0b6948 */
if(!s->budget--) { s->failed_pc=0x0c0b6948u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a80u,2);
goto P_0c0b694a;
P_0c0b694a: /* original 65f2, guest PC 0x0c0b694a */
if(!s->budget--) { s->failed_pc=0x0c0b694au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b694c;
P_0c0b694c: /* original 4e0b, guest PC 0x0c0b694c */
if(!s->budget--) { s->failed_pc=0x0c0b694cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6950u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6950u) { target=s->pc; goto dispatch; }
goto P_0c0b6950;
P_0c0b694e: /* original 6552, guest PC 0x0c0b694e */
if(!s->budget--) { s->failed_pc=0x0c0b694eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6950;
P_0c0b6950: /* original 9497, guest PC 0x0c0b6950 */
if(!s->budget--) { s->failed_pc=0x0c0b6950u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a82u,2);
goto P_0c0b6952;
P_0c0b6952: /* original 55f1, guest PC 0x0c0b6952 */
if(!s->budget--) { s->failed_pc=0x0c0b6952u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b6954;
P_0c0b6954: /* original 4e0b, guest PC 0x0c0b6954 */
if(!s->budget--) { s->failed_pc=0x0c0b6954u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6958u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6958u) { target=s->pc; goto dispatch; }
goto P_0c0b6958;
P_0c0b6956: /* original 6552, guest PC 0x0c0b6956 */
if(!s->budget--) { s->failed_pc=0x0c0b6956u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6958;
P_0c0b6958: /* original 9494, guest PC 0x0c0b6958 */
if(!s->budget--) { s->failed_pc=0x0c0b6958u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a84u,2);
goto P_0c0b695a;
P_0c0b695a: /* original 4e0b, guest PC 0x0c0b695a */
if(!s->budget--) { s->failed_pc=0x0c0b695au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b695eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b695eu) { target=s->pc; goto dispatch; }
goto P_0c0b695e;
P_0c0b695c: /* original 6592, guest PC 0x0c0b695c */
if(!s->budget--) { s->failed_pc=0x0c0b695cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b695e;
P_0c0b695e: /* original 9492, guest PC 0x0c0b695e */
if(!s->budget--) { s->failed_pc=0x0c0b695eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a86u,2);
goto P_0c0b6960;
P_0c0b6960: /* original 4e0b, guest PC 0x0c0b6960 */
if(!s->budget--) { s->failed_pc=0x0c0b6960u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6964u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6964u) { target=s->pc; goto dispatch; }
goto P_0c0b6964;
P_0c0b6962: /* original 6592, guest PC 0x0c0b6962 */
if(!s->budget--) { s->failed_pc=0x0c0b6962u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6964;
P_0c0b6964: /* original 9490, guest PC 0x0c0b6964 */
if(!s->budget--) { s->failed_pc=0x0c0b6964u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a88u,2);
goto P_0c0b6966;
P_0c0b6966: /* original 4e0b, guest PC 0x0c0b6966 */
if(!s->budget--) { s->failed_pc=0x0c0b6966u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b696au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b696au) { target=s->pc; goto dispatch; }
goto P_0c0b696a;
P_0c0b6968: /* original 6592, guest PC 0x0c0b6968 */
if(!s->budget--) { s->failed_pc=0x0c0b6968u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b696a;
P_0c0b696a: /* original 948e, guest PC 0x0c0b696a */
if(!s->budget--) { s->failed_pc=0x0c0b696au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a8au,2);
goto P_0c0b696c;
P_0c0b696c: /* original 4e0b, guest PC 0x0c0b696c */
if(!s->budget--) { s->failed_pc=0x0c0b696cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6970u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6970u) { target=s->pc; goto dispatch; }
goto P_0c0b6970;
P_0c0b696e: /* original 6592, guest PC 0x0c0b696e */
if(!s->budget--) { s->failed_pc=0x0c0b696eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b6970;
P_0c0b6970: /* original 948c, guest PC 0x0c0b6970 */
if(!s->budget--) { s->failed_pc=0x0c0b6970u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a8cu,2);
goto P_0c0b6972;
P_0c0b6972: /* original 4e0b, guest PC 0x0c0b6972 */
if(!s->budget--) { s->failed_pc=0x0c0b6972u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6976u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6976u) { target=s->pc; goto dispatch; }
goto P_0c0b6976;
P_0c0b6974: /* original 65c2, guest PC 0x0c0b6974 */
if(!s->budget--) { s->failed_pc=0x0c0b6974u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6976;
P_0c0b6976: /* original 948a, guest PC 0x0c0b6976 */
if(!s->budget--) { s->failed_pc=0x0c0b6976u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a8eu,2);
goto P_0c0b6978;
P_0c0b6978: /* original 4e0b, guest PC 0x0c0b6978 */
if(!s->budget--) { s->failed_pc=0x0c0b6978u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b697cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b697cu) { target=s->pc; goto dispatch; }
goto P_0c0b697c;
P_0c0b697a: /* original 65c2, guest PC 0x0c0b697a */
if(!s->budget--) { s->failed_pc=0x0c0b697au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b697c;
P_0c0b697c: /* original 9488, guest PC 0x0c0b697c */
if(!s->budget--) { s->failed_pc=0x0c0b697cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a90u,2);
goto P_0c0b697e;
P_0c0b697e: /* original 4e0b, guest PC 0x0c0b697e */
if(!s->budget--) { s->failed_pc=0x0c0b697eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6982u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6982u) { target=s->pc; goto dispatch; }
goto P_0c0b6982;
P_0c0b6980: /* original 65c2, guest PC 0x0c0b6980 */
if(!s->budget--) { s->failed_pc=0x0c0b6980u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6982;
P_0c0b6982: /* original 9486, guest PC 0x0c0b6982 */
if(!s->budget--) { s->failed_pc=0x0c0b6982u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a92u,2);
goto P_0c0b6984;
P_0c0b6984: /* original 4e0b, guest PC 0x0c0b6984 */
if(!s->budget--) { s->failed_pc=0x0c0b6984u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6988u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6988u) { target=s->pc; goto dispatch; }
goto P_0c0b6988;
P_0c0b6986: /* original 65c2, guest PC 0x0c0b6986 */
if(!s->budget--) { s->failed_pc=0x0c0b6986u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b6988;
P_0c0b6988: /* original 9484, guest PC 0x0c0b6988 */
if(!s->budget--) { s->failed_pc=0x0c0b6988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a94u,2);
goto P_0c0b698a;
P_0c0b698a: /* original 4e0b, guest PC 0x0c0b698a */
if(!s->budget--) { s->failed_pc=0x0c0b698au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b698eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b698eu) { target=s->pc; goto dispatch; }
goto P_0c0b698e;
P_0c0b698c: /* original 65b2, guest PC 0x0c0b698c */
if(!s->budget--) { s->failed_pc=0x0c0b698cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b698e;
P_0c0b698e: /* original 9482, guest PC 0x0c0b698e */
if(!s->budget--) { s->failed_pc=0x0c0b698eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a96u,2);
goto P_0c0b6990;
P_0c0b6990: /* original 4e0b, guest PC 0x0c0b6990 */
if(!s->budget--) { s->failed_pc=0x0c0b6990u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6994u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6994u) { target=s->pc; goto dispatch; }
goto P_0c0b6994;
P_0c0b6992: /* original 65b2, guest PC 0x0c0b6992 */
if(!s->budget--) { s->failed_pc=0x0c0b6992u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b6994;
P_0c0b6994: /* original 9480, guest PC 0x0c0b6994 */
if(!s->budget--) { s->failed_pc=0x0c0b6994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a98u,2);
goto P_0c0b6996;
P_0c0b6996: /* original 4e0b, guest PC 0x0c0b6996 */
if(!s->budget--) { s->failed_pc=0x0c0b6996u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b699au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b699au) { target=s->pc; goto dispatch; }
goto P_0c0b699a;
P_0c0b6998: /* original 65b2, guest PC 0x0c0b6998 */
if(!s->budget--) { s->failed_pc=0x0c0b6998u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b699a;
P_0c0b699a: /* original 947e, guest PC 0x0c0b699a */
if(!s->budget--) { s->failed_pc=0x0c0b699au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a9au,2);
goto P_0c0b699c;
P_0c0b699c: /* original 4e0b, guest PC 0x0c0b699c */
if(!s->budget--) { s->failed_pc=0x0c0b699cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69a0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69a0u) { target=s->pc; goto dispatch; }
goto P_0c0b69a0;
P_0c0b699e: /* original 65b2, guest PC 0x0c0b699e */
if(!s->budget--) { s->failed_pc=0x0c0b699eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b69a0;
P_0c0b69a0: /* original 947c, guest PC 0x0c0b69a0 */
if(!s->budget--) { s->failed_pc=0x0c0b69a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a9cu,2);
goto P_0c0b69a2;
P_0c0b69a2: /* original 4e0b, guest PC 0x0c0b69a2 */
if(!s->budget--) { s->failed_pc=0x0c0b69a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69a6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69a6u) { target=s->pc; goto dispatch; }
goto P_0c0b69a6;
P_0c0b69a4: /* original 65a2, guest PC 0x0c0b69a4 */
if(!s->budget--) { s->failed_pc=0x0c0b69a4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b69a6;
P_0c0b69a6: /* original 947a, guest PC 0x0c0b69a6 */
if(!s->budget--) { s->failed_pc=0x0c0b69a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6a9eu,2);
goto P_0c0b69a8;
P_0c0b69a8: /* original 4e0b, guest PC 0x0c0b69a8 */
if(!s->budget--) { s->failed_pc=0x0c0b69a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69acu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69acu) { target=s->pc; goto dispatch; }
goto P_0c0b69ac;
P_0c0b69aa: /* original 65a2, guest PC 0x0c0b69aa */
if(!s->budget--) { s->failed_pc=0x0c0b69aau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b69ac;
P_0c0b69ac: /* original 9478, guest PC 0x0c0b69ac */
if(!s->budget--) { s->failed_pc=0x0c0b69acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aa0u,2);
goto P_0c0b69ae;
P_0c0b69ae: /* original 4e0b, guest PC 0x0c0b69ae */
if(!s->budget--) { s->failed_pc=0x0c0b69aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69b2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69b2u) { target=s->pc; goto dispatch; }
goto P_0c0b69b2;
P_0c0b69b0: /* original 65a2, guest PC 0x0c0b69b0 */
if(!s->budget--) { s->failed_pc=0x0c0b69b0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b69b2;
P_0c0b69b2: /* original 9476, guest PC 0x0c0b69b2 */
if(!s->budget--) { s->failed_pc=0x0c0b69b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aa2u,2);
goto P_0c0b69b4;
P_0c0b69b4: /* original 4e0b, guest PC 0x0c0b69b4 */
if(!s->budget--) { s->failed_pc=0x0c0b69b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69b8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69b8u) { target=s->pc; goto dispatch; }
goto P_0c0b69b8;
P_0c0b69b6: /* original 65a2, guest PC 0x0c0b69b6 */
if(!s->budget--) { s->failed_pc=0x0c0b69b6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b69b8;
P_0c0b69b8: /* original 9574, guest PC 0x0c0b69b8 */
if(!s->budget--) { s->failed_pc=0x0c0b69b8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aa4u,2);
goto P_0c0b69ba;
P_0c0b69ba: /* original 35dc, guest PC 0x0c0b69ba */
if(!s->budget--) { s->failed_pc=0x0c0b69bau; return 0; }
r[5]+=r[13];
goto P_0c0b69bc;
P_0c0b69bc: /* original 2f52, guest PC 0x0c0b69bc */
if(!s->budget--) { s->failed_pc=0x0c0b69bcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b69be;
P_0c0b69be: /* original 9472, guest PC 0x0c0b69be */
if(!s->budget--) { s->failed_pc=0x0c0b69beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aa6u,2);
goto P_0c0b69c0;
P_0c0b69c0: /* original 4e0b, guest PC 0x0c0b69c0 */
if(!s->budget--) { s->failed_pc=0x0c0b69c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69c4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69c4u) { target=s->pc; goto dispatch; }
goto P_0c0b69c4;
P_0c0b69c2: /* original 6552, guest PC 0x0c0b69c2 */
if(!s->budget--) { s->failed_pc=0x0c0b69c2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69c4;
P_0c0b69c4: /* original 9470, guest PC 0x0c0b69c4 */
if(!s->budget--) { s->failed_pc=0x0c0b69c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aa8u,2);
goto P_0c0b69c6;
P_0c0b69c6: /* original 65f2, guest PC 0x0c0b69c6 */
if(!s->budget--) { s->failed_pc=0x0c0b69c6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b69c8;
P_0c0b69c8: /* original 4e0b, guest PC 0x0c0b69c8 */
if(!s->budget--) { s->failed_pc=0x0c0b69c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69ccu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69ccu) { target=s->pc; goto dispatch; }
goto P_0c0b69cc;
P_0c0b69ca: /* original 6552, guest PC 0x0c0b69ca */
if(!s->budget--) { s->failed_pc=0x0c0b69cau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69cc;
P_0c0b69cc: /* original 956d, guest PC 0x0c0b69cc */
if(!s->budget--) { s->failed_pc=0x0c0b69ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aaau,2);
goto P_0c0b69ce;
P_0c0b69ce: /* original 35dc, guest PC 0x0c0b69ce */
if(!s->budget--) { s->failed_pc=0x0c0b69ceu; return 0; }
r[5]+=r[13];
goto P_0c0b69d0;
P_0c0b69d0: /* original 2f52, guest PC 0x0c0b69d0 */
if(!s->budget--) { s->failed_pc=0x0c0b69d0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b69d2;
P_0c0b69d2: /* original 946b, guest PC 0x0c0b69d2 */
if(!s->budget--) { s->failed_pc=0x0c0b69d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aacu,2);
goto P_0c0b69d4;
P_0c0b69d4: /* original 4e0b, guest PC 0x0c0b69d4 */
if(!s->budget--) { s->failed_pc=0x0c0b69d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69d8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69d8u) { target=s->pc; goto dispatch; }
goto P_0c0b69d8;
P_0c0b69d6: /* original 6552, guest PC 0x0c0b69d6 */
if(!s->budget--) { s->failed_pc=0x0c0b69d6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69d8;
P_0c0b69d8: /* original 9469, guest PC 0x0c0b69d8 */
if(!s->budget--) { s->failed_pc=0x0c0b69d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aaeu,2);
goto P_0c0b69da;
P_0c0b69da: /* original 65f2, guest PC 0x0c0b69da */
if(!s->budget--) { s->failed_pc=0x0c0b69dau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b69dc;
P_0c0b69dc: /* original 4e0b, guest PC 0x0c0b69dc */
if(!s->budget--) { s->failed_pc=0x0c0b69dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69e0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69e0u) { target=s->pc; goto dispatch; }
goto P_0c0b69e0;
P_0c0b69de: /* original 6552, guest PC 0x0c0b69de */
if(!s->budget--) { s->failed_pc=0x0c0b69deu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69e0;
P_0c0b69e0: /* original 9467, guest PC 0x0c0b69e0 */
if(!s->budget--) { s->failed_pc=0x0c0b69e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ab2u,2);
goto P_0c0b69e2;
P_0c0b69e2: /* original 9065, guest PC 0x0c0b69e2 */
if(!s->budget--) { s->failed_pc=0x0c0b69e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ab0u,2);
goto P_0c0b69e4;
P_0c0b69e4: /* original 4e0b, guest PC 0x0c0b69e4 */
if(!s->budget--) { s->failed_pc=0x0c0b69e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69e8u) { target=s->pc; goto dispatch; }
goto P_0c0b69e8;
P_0c0b69e6: /* original 05de, guest PC 0x0c0b69e6 */
if(!s->budget--) { s->failed_pc=0x0c0b69e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b69e8;
P_0c0b69e8: /* original 9564, guest PC 0x0c0b69e8 */
if(!s->budget--) { s->failed_pc=0x0c0b69e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ab4u,2);
goto P_0c0b69ea;
P_0c0b69ea: /* original 35dc, guest PC 0x0c0b69ea */
if(!s->budget--) { s->failed_pc=0x0c0b69eau; return 0; }
r[5]+=r[13];
goto P_0c0b69ec;
P_0c0b69ec: /* original 2f52, guest PC 0x0c0b69ec */
if(!s->budget--) { s->failed_pc=0x0c0b69ecu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b69ee;
P_0c0b69ee: /* original 9462, guest PC 0x0c0b69ee */
if(!s->budget--) { s->failed_pc=0x0c0b69eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ab6u,2);
goto P_0c0b69f0;
P_0c0b69f0: /* original 4e0b, guest PC 0x0c0b69f0 */
if(!s->budget--) { s->failed_pc=0x0c0b69f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69f4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69f4u) { target=s->pc; goto dispatch; }
goto P_0c0b69f4;
P_0c0b69f2: /* original 6552, guest PC 0x0c0b69f2 */
if(!s->budget--) { s->failed_pc=0x0c0b69f2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69f4;
P_0c0b69f4: /* original 9460, guest PC 0x0c0b69f4 */
if(!s->budget--) { s->failed_pc=0x0c0b69f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ab8u,2);
goto P_0c0b69f6;
P_0c0b69f6: /* original 65f2, guest PC 0x0c0b69f6 */
if(!s->budget--) { s->failed_pc=0x0c0b69f6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b69f8;
P_0c0b69f8: /* original 4e0b, guest PC 0x0c0b69f8 */
if(!s->budget--) { s->failed_pc=0x0c0b69f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b69fcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b69fcu) { target=s->pc; goto dispatch; }
goto P_0c0b69fc;
P_0c0b69fa: /* original 6552, guest PC 0x0c0b69fa */
if(!s->budget--) { s->failed_pc=0x0c0b69fau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b69fc;
P_0c0b69fc: /* original 945e, guest PC 0x0c0b69fc */
if(!s->budget--) { s->failed_pc=0x0c0b69fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6abcu,2);
goto P_0c0b69fe;
P_0c0b69fe: /* original 905c, guest PC 0x0c0b69fe */
if(!s->budget--) { s->failed_pc=0x0c0b69feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6abau,2);
goto P_0c0b6a00;
P_0c0b6a00: /* original 4e0b, guest PC 0x0c0b6a00 */
if(!s->budget--) { s->failed_pc=0x0c0b6a00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a04u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a04u) { target=s->pc; goto dispatch; }
goto P_0c0b6a04;
P_0c0b6a02: /* original 05de, guest PC 0x0c0b6a02 */
if(!s->budget--) { s->failed_pc=0x0c0b6a02u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a04;
P_0c0b6a04: /* original 955b, guest PC 0x0c0b6a04 */
if(!s->budget--) { s->failed_pc=0x0c0b6a04u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6abeu,2);
goto P_0c0b6a06;
P_0c0b6a06: /* original 35dc, guest PC 0x0c0b6a06 */
if(!s->budget--) { s->failed_pc=0x0c0b6a06u; return 0; }
r[5]+=r[13];
goto P_0c0b6a08;
P_0c0b6a08: /* original 2f52, guest PC 0x0c0b6a08 */
if(!s->budget--) { s->failed_pc=0x0c0b6a08u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6a0a;
P_0c0b6a0a: /* original 9459, guest PC 0x0c0b6a0a */
if(!s->budget--) { s->failed_pc=0x0c0b6a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ac0u,2);
goto P_0c0b6a0c;
P_0c0b6a0c: /* original 4e0b, guest PC 0x0c0b6a0c */
if(!s->budget--) { s->failed_pc=0x0c0b6a0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a10u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a10u) { target=s->pc; goto dispatch; }
goto P_0c0b6a10;
P_0c0b6a0e: /* original 6552, guest PC 0x0c0b6a0e */
if(!s->budget--) { s->failed_pc=0x0c0b6a0eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a10;
P_0c0b6a10: /* original 9457, guest PC 0x0c0b6a10 */
if(!s->budget--) { s->failed_pc=0x0c0b6a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ac2u,2);
goto P_0c0b6a12;
P_0c0b6a12: /* original 65f2, guest PC 0x0c0b6a12 */
if(!s->budget--) { s->failed_pc=0x0c0b6a12u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b6a14;
P_0c0b6a14: /* original 4e0b, guest PC 0x0c0b6a14 */
if(!s->budget--) { s->failed_pc=0x0c0b6a14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a18u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a18u) { target=s->pc; goto dispatch; }
goto P_0c0b6a18;
P_0c0b6a16: /* original 6552, guest PC 0x0c0b6a16 */
if(!s->budget--) { s->failed_pc=0x0c0b6a16u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a18;
P_0c0b6a18: /* original 9455, guest PC 0x0c0b6a18 */
if(!s->budget--) { s->failed_pc=0x0c0b6a18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ac6u,2);
goto P_0c0b6a1a;
P_0c0b6a1a: /* original 9053, guest PC 0x0c0b6a1a */
if(!s->budget--) { s->failed_pc=0x0c0b6a1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ac4u,2);
goto P_0c0b6a1c;
P_0c0b6a1c: /* original 4e0b, guest PC 0x0c0b6a1c */
if(!s->budget--) { s->failed_pc=0x0c0b6a1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a20u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a20u) { target=s->pc; goto dispatch; }
goto P_0c0b6a20;
P_0c0b6a1e: /* original 05de, guest PC 0x0c0b6a1e */
if(!s->budget--) { s->failed_pc=0x0c0b6a1eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a20;
P_0c0b6a20: /* original 9552, guest PC 0x0c0b6a20 */
if(!s->budget--) { s->failed_pc=0x0c0b6a20u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ac8u,2);
goto P_0c0b6a22;
P_0c0b6a22: /* original 35dc, guest PC 0x0c0b6a22 */
if(!s->budget--) { s->failed_pc=0x0c0b6a22u; return 0; }
r[5]+=r[13];
goto P_0c0b6a24;
P_0c0b6a24: /* original 2f52, guest PC 0x0c0b6a24 */
if(!s->budget--) { s->failed_pc=0x0c0b6a24u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6a26;
P_0c0b6a26: /* original 9450, guest PC 0x0c0b6a26 */
if(!s->budget--) { s->failed_pc=0x0c0b6a26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6acau,2);
goto P_0c0b6a28;
P_0c0b6a28: /* original 4e0b, guest PC 0x0c0b6a28 */
if(!s->budget--) { s->failed_pc=0x0c0b6a28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a2cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a2cu) { target=s->pc; goto dispatch; }
goto P_0c0b6a2c;
P_0c0b6a2a: /* original 6552, guest PC 0x0c0b6a2a */
if(!s->budget--) { s->failed_pc=0x0c0b6a2au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a2c;
P_0c0b6a2c: /* original 944e, guest PC 0x0c0b6a2c */
if(!s->budget--) { s->failed_pc=0x0c0b6a2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6accu,2);
goto P_0c0b6a2e;
P_0c0b6a2e: /* original 65f2, guest PC 0x0c0b6a2e */
if(!s->budget--) { s->failed_pc=0x0c0b6a2eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b6a30;
P_0c0b6a30: /* original 4e0b, guest PC 0x0c0b6a30 */
if(!s->budget--) { s->failed_pc=0x0c0b6a30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a34u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a34u) { target=s->pc; goto dispatch; }
goto P_0c0b6a34;
P_0c0b6a32: /* original 6552, guest PC 0x0c0b6a32 */
if(!s->budget--) { s->failed_pc=0x0c0b6a32u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a34;
P_0c0b6a34: /* original 954b, guest PC 0x0c0b6a34 */
if(!s->budget--) { s->failed_pc=0x0c0b6a34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6aceu,2);
goto P_0c0b6a36;
P_0c0b6a36: /* original 35dc, guest PC 0x0c0b6a36 */
if(!s->budget--) { s->failed_pc=0x0c0b6a36u; return 0; }
r[5]+=r[13];
goto P_0c0b6a38;
P_0c0b6a38: /* original 2f52, guest PC 0x0c0b6a38 */
if(!s->budget--) { s->failed_pc=0x0c0b6a38u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b6a3a;
P_0c0b6a3a: /* original 9449, guest PC 0x0c0b6a3a */
if(!s->budget--) { s->failed_pc=0x0c0b6a3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ad0u,2);
goto P_0c0b6a3c;
P_0c0b6a3c: /* original 4e0b, guest PC 0x0c0b6a3c */
if(!s->budget--) { s->failed_pc=0x0c0b6a3cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a40u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a40u) { target=s->pc; goto dispatch; }
goto P_0c0b6a40;
P_0c0b6a3e: /* original 6552, guest PC 0x0c0b6a3e */
if(!s->budget--) { s->failed_pc=0x0c0b6a3eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a40;
P_0c0b6a40: /* original 9447, guest PC 0x0c0b6a40 */
if(!s->budget--) { s->failed_pc=0x0c0b6a40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ad2u,2);
goto P_0c0b6a42;
P_0c0b6a42: /* original 65f2, guest PC 0x0c0b6a42 */
if(!s->budget--) { s->failed_pc=0x0c0b6a42u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b6a44;
P_0c0b6a44: /* original 4e0b, guest PC 0x0c0b6a44 */
if(!s->budget--) { s->failed_pc=0x0c0b6a44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a48u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a48u) { target=s->pc; goto dispatch; }
goto P_0c0b6a48;
P_0c0b6a46: /* original 6552, guest PC 0x0c0b6a46 */
if(!s->budget--) { s->failed_pc=0x0c0b6a46u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b6a48;
P_0c0b6a48: /* original 9445, guest PC 0x0c0b6a48 */
if(!s->budget--) { s->failed_pc=0x0c0b6a48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ad6u,2);
goto P_0c0b6a4a;
P_0c0b6a4a: /* original 9043, guest PC 0x0c0b6a4a */
if(!s->budget--) { s->failed_pc=0x0c0b6a4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ad4u,2);
goto P_0c0b6a4c;
P_0c0b6a4c: /* original 4e0b, guest PC 0x0c0b6a4c */
if(!s->budget--) { s->failed_pc=0x0c0b6a4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a50u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a50u) { target=s->pc; goto dispatch; }
goto P_0c0b6a50;
P_0c0b6a4e: /* original 05de, guest PC 0x0c0b6a4e */
if(!s->budget--) { s->failed_pc=0x0c0b6a4eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a50;
P_0c0b6a50: /* original 9443, guest PC 0x0c0b6a50 */
if(!s->budget--) { s->failed_pc=0x0c0b6a50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6adau,2);
goto P_0c0b6a52;
P_0c0b6a52: /* original 9041, guest PC 0x0c0b6a52 */
if(!s->budget--) { s->failed_pc=0x0c0b6a52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ad8u,2);
goto P_0c0b6a54;
P_0c0b6a54: /* original 4e0b, guest PC 0x0c0b6a54 */
if(!s->budget--) { s->failed_pc=0x0c0b6a54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a58u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a58u) { target=s->pc; goto dispatch; }
goto P_0c0b6a58;
P_0c0b6a56: /* original 05de, guest PC 0x0c0b6a56 */
if(!s->budget--) { s->failed_pc=0x0c0b6a56u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a58;
P_0c0b6a58: /* original 9441, guest PC 0x0c0b6a58 */
if(!s->budget--) { s->failed_pc=0x0c0b6a58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6adeu,2);
goto P_0c0b6a5a;
P_0c0b6a5a: /* original 903f, guest PC 0x0c0b6a5a */
if(!s->budget--) { s->failed_pc=0x0c0b6a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6adcu,2);
goto P_0c0b6a5c;
P_0c0b6a5c: /* original 4e0b, guest PC 0x0c0b6a5c */
if(!s->budget--) { s->failed_pc=0x0c0b6a5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a60u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a60u) { target=s->pc; goto dispatch; }
goto P_0c0b6a60;
P_0c0b6a5e: /* original 05de, guest PC 0x0c0b6a5e */
if(!s->budget--) { s->failed_pc=0x0c0b6a5eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a60;
P_0c0b6a60: /* original 943f, guest PC 0x0c0b6a60 */
if(!s->budget--) { s->failed_pc=0x0c0b6a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ae2u,2);
goto P_0c0b6a62;
P_0c0b6a62: /* original 903d, guest PC 0x0c0b6a62 */
if(!s->budget--) { s->failed_pc=0x0c0b6a62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ae0u,2);
goto P_0c0b6a64;
P_0c0b6a64: /* original 4e0b, guest PC 0x0c0b6a64 */
if(!s->budget--) { s->failed_pc=0x0c0b6a64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6a68u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6a68u) { target=s->pc; goto dispatch; }
goto P_0c0b6a68;
P_0c0b6a66: /* original 05de, guest PC 0x0c0b6a66 */
if(!s->budget--) { s->failed_pc=0x0c0b6a66u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6a68;
P_0c0b6a68: /* original 903c, guest PC 0x0c0b6a68 */
if(!s->budget--) { s->failed_pc=0x0c0b6a68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6ae4u,2);
goto P_0c0b6a6a;
P_0c0b6a6a: /* original a03c, guest PC 0x0c0b6a6a */
if(!s->budget--) { s->failed_pc=0x0c0b6a6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6ae6;
P_0c0b6a6c: /* original 05de, guest PC 0x0c0b6a6c */
if(!s->budget--) { s->failed_pc=0x0c0b6a6cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b6a6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b6a6eu; return 0; } return 1;
P_0c0b6ae6: /* original 943e, guest PC 0x0c0b6ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b6ae6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b66u,2);
goto P_0c0b6ae8;
P_0c0b6ae8: /* original 4e0b, guest PC 0x0c0b6ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b6ae8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6aecu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6aecu) { target=s->pc; goto dispatch; }
goto P_0c0b6aec;
P_0c0b6aea: /* original 0009, guest PC 0x0c0b6aea */
if(!s->budget--) { s->failed_pc=0x0c0b6aeau; return 0; }
goto P_0c0b6aec;
P_0c0b6aec: /* original 943d, guest PC 0x0c0b6aec */
if(!s->budget--) { s->failed_pc=0x0c0b6aecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b6au,2);
goto P_0c0b6aee;
P_0c0b6aee: /* original 903b, guest PC 0x0c0b6aee */
if(!s->budget--) { s->failed_pc=0x0c0b6aeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b68u,2);
goto P_0c0b6af0;
P_0c0b6af0: /* original 4e0b, guest PC 0x0c0b6af0 */
if(!s->budget--) { s->failed_pc=0x0c0b6af0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6af4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6af4u) { target=s->pc; goto dispatch; }
goto P_0c0b6af4;
P_0c0b6af2: /* original 05de, guest PC 0x0c0b6af2 */
if(!s->budget--) { s->failed_pc=0x0c0b6af2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6af4;
P_0c0b6af4: /* original 943b, guest PC 0x0c0b6af4 */
if(!s->budget--) { s->failed_pc=0x0c0b6af4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b6eu,2);
goto P_0c0b6af6;
P_0c0b6af6: /* original 9039, guest PC 0x0c0b6af6 */
if(!s->budget--) { s->failed_pc=0x0c0b6af6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b6cu,2);
goto P_0c0b6af8;
P_0c0b6af8: /* original 4e0b, guest PC 0x0c0b6af8 */
if(!s->budget--) { s->failed_pc=0x0c0b6af8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6afcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6afcu) { target=s->pc; goto dispatch; }
goto P_0c0b6afc;
P_0c0b6afa: /* original 05de, guest PC 0x0c0b6afa */
if(!s->budget--) { s->failed_pc=0x0c0b6afau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6afc;
P_0c0b6afc: /* original 9439, guest PC 0x0c0b6afc */
if(!s->budget--) { s->failed_pc=0x0c0b6afcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b72u,2);
goto P_0c0b6afe;
P_0c0b6afe: /* original 9037, guest PC 0x0c0b6afe */
if(!s->budget--) { s->failed_pc=0x0c0b6afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b70u,2);
goto P_0c0b6b00;
P_0c0b6b00: /* original 4e0b, guest PC 0x0c0b6b00 */
if(!s->budget--) { s->failed_pc=0x0c0b6b00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b04u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b04u) { target=s->pc; goto dispatch; }
goto P_0c0b6b04;
P_0c0b6b02: /* original 05de, guest PC 0x0c0b6b02 */
if(!s->budget--) { s->failed_pc=0x0c0b6b02u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b04;
P_0c0b6b04: /* original 9437, guest PC 0x0c0b6b04 */
if(!s->budget--) { s->failed_pc=0x0c0b6b04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b76u,2);
goto P_0c0b6b06;
P_0c0b6b06: /* original 9035, guest PC 0x0c0b6b06 */
if(!s->budget--) { s->failed_pc=0x0c0b6b06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b74u,2);
goto P_0c0b6b08;
P_0c0b6b08: /* original 4e0b, guest PC 0x0c0b6b08 */
if(!s->budget--) { s->failed_pc=0x0c0b6b08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b0cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b0cu) { target=s->pc; goto dispatch; }
goto P_0c0b6b0c;
P_0c0b6b0a: /* original 05de, guest PC 0x0c0b6b0a */
if(!s->budget--) { s->failed_pc=0x0c0b6b0au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b0c;
P_0c0b6b0c: /* original 9435, guest PC 0x0c0b6b0c */
if(!s->budget--) { s->failed_pc=0x0c0b6b0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b7au,2);
goto P_0c0b6b0e;
P_0c0b6b0e: /* original 9033, guest PC 0x0c0b6b0e */
if(!s->budget--) { s->failed_pc=0x0c0b6b0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b78u,2);
goto P_0c0b6b10;
P_0c0b6b10: /* original 4e0b, guest PC 0x0c0b6b10 */
if(!s->budget--) { s->failed_pc=0x0c0b6b10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b14u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b14u) { target=s->pc; goto dispatch; }
goto P_0c0b6b14;
P_0c0b6b12: /* original 05de, guest PC 0x0c0b6b12 */
if(!s->budget--) { s->failed_pc=0x0c0b6b12u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b14;
P_0c0b6b14: /* original 9433, guest PC 0x0c0b6b14 */
if(!s->budget--) { s->failed_pc=0x0c0b6b14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b7eu,2);
goto P_0c0b6b16;
P_0c0b6b16: /* original 9031, guest PC 0x0c0b6b16 */
if(!s->budget--) { s->failed_pc=0x0c0b6b16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b7cu,2);
goto P_0c0b6b18;
P_0c0b6b18: /* original 4e0b, guest PC 0x0c0b6b18 */
if(!s->budget--) { s->failed_pc=0x0c0b6b18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b1cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b1cu) { target=s->pc; goto dispatch; }
goto P_0c0b6b1c;
P_0c0b6b1a: /* original 05de, guest PC 0x0c0b6b1a */
if(!s->budget--) { s->failed_pc=0x0c0b6b1au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b1c;
P_0c0b6b1c: /* original 9431, guest PC 0x0c0b6b1c */
if(!s->budget--) { s->failed_pc=0x0c0b6b1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b82u,2);
goto P_0c0b6b1e;
P_0c0b6b1e: /* original 902f, guest PC 0x0c0b6b1e */
if(!s->budget--) { s->failed_pc=0x0c0b6b1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b80u,2);
goto P_0c0b6b20;
P_0c0b6b20: /* original 4e0b, guest PC 0x0c0b6b20 */
if(!s->budget--) { s->failed_pc=0x0c0b6b20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b24u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b24u) { target=s->pc; goto dispatch; }
goto P_0c0b6b24;
P_0c0b6b22: /* original 05de, guest PC 0x0c0b6b22 */
if(!s->budget--) { s->failed_pc=0x0c0b6b22u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b24;
P_0c0b6b24: /* original 942f, guest PC 0x0c0b6b24 */
if(!s->budget--) { s->failed_pc=0x0c0b6b24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b86u,2);
goto P_0c0b6b26;
P_0c0b6b26: /* original 902d, guest PC 0x0c0b6b26 */
if(!s->budget--) { s->failed_pc=0x0c0b6b26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b84u,2);
goto P_0c0b6b28;
P_0c0b6b28: /* original 4e0b, guest PC 0x0c0b6b28 */
if(!s->budget--) { s->failed_pc=0x0c0b6b28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b2cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b2cu) { target=s->pc; goto dispatch; }
goto P_0c0b6b2c;
P_0c0b6b2a: /* original 05de, guest PC 0x0c0b6b2a */
if(!s->budget--) { s->failed_pc=0x0c0b6b2au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b2c;
P_0c0b6b2c: /* original 942d, guest PC 0x0c0b6b2c */
if(!s->budget--) { s->failed_pc=0x0c0b6b2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b8au,2);
goto P_0c0b6b2e;
P_0c0b6b2e: /* original 902b, guest PC 0x0c0b6b2e */
if(!s->budget--) { s->failed_pc=0x0c0b6b2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b88u,2);
goto P_0c0b6b30;
P_0c0b6b30: /* original 4e0b, guest PC 0x0c0b6b30 */
if(!s->budget--) { s->failed_pc=0x0c0b6b30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b34u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b34u) { target=s->pc; goto dispatch; }
goto P_0c0b6b34;
P_0c0b6b32: /* original 05de, guest PC 0x0c0b6b32 */
if(!s->budget--) { s->failed_pc=0x0c0b6b32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b34;
P_0c0b6b34: /* original 942b, guest PC 0x0c0b6b34 */
if(!s->budget--) { s->failed_pc=0x0c0b6b34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b8eu,2);
goto P_0c0b6b36;
P_0c0b6b36: /* original 9029, guest PC 0x0c0b6b36 */
if(!s->budget--) { s->failed_pc=0x0c0b6b36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b8cu,2);
goto P_0c0b6b38;
P_0c0b6b38: /* original 4e0b, guest PC 0x0c0b6b38 */
if(!s->budget--) { s->failed_pc=0x0c0b6b38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b6b3c;
P_0c0b6b3a: /* original 05de, guest PC 0x0c0b6b3a */
if(!s->budget--) { s->failed_pc=0x0c0b6b3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b3c;
P_0c0b6b3c: /* original 9429, guest PC 0x0c0b6b3c */
if(!s->budget--) { s->failed_pc=0x0c0b6b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b92u,2);
goto P_0c0b6b3e;
P_0c0b6b3e: /* original 9027, guest PC 0x0c0b6b3e */
if(!s->budget--) { s->failed_pc=0x0c0b6b3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b90u,2);
goto P_0c0b6b40;
P_0c0b6b40: /* original 4e0b, guest PC 0x0c0b6b40 */
if(!s->budget--) { s->failed_pc=0x0c0b6b40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b44u) { target=s->pc; goto dispatch; }
goto P_0c0b6b44;
P_0c0b6b42: /* original 05de, guest PC 0x0c0b6b42 */
if(!s->budget--) { s->failed_pc=0x0c0b6b42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b44;
P_0c0b6b44: /* original 9427, guest PC 0x0c0b6b44 */
if(!s->budget--) { s->failed_pc=0x0c0b6b44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b96u,2);
goto P_0c0b6b46;
P_0c0b6b46: /* original 9025, guest PC 0x0c0b6b46 */
if(!s->budget--) { s->failed_pc=0x0c0b6b46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b94u,2);
goto P_0c0b6b48;
P_0c0b6b48: /* original 4e0b, guest PC 0x0c0b6b48 */
if(!s->budget--) { s->failed_pc=0x0c0b6b48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b4cu) { target=s->pc; goto dispatch; }
goto P_0c0b6b4c;
P_0c0b6b4a: /* original 05de, guest PC 0x0c0b6b4a */
if(!s->budget--) { s->failed_pc=0x0c0b6b4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b4c;
P_0c0b6b4c: /* original 9425, guest PC 0x0c0b6b4c */
if(!s->budget--) { s->failed_pc=0x0c0b6b4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b9au,2);
goto P_0c0b6b4e;
P_0c0b6b4e: /* original 9023, guest PC 0x0c0b6b4e */
if(!s->budget--) { s->failed_pc=0x0c0b6b4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b6b98u,2);
goto P_0c0b6b50;
P_0c0b6b50: /* original 4e0b, guest PC 0x0c0b6b50 */
if(!s->budget--) { s->failed_pc=0x0c0b6b50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b6b54u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b6b54u) { target=s->pc; goto dispatch; }
goto P_0c0b6b54;
P_0c0b6b52: /* original 05de, guest PC 0x0c0b6b52 */
if(!s->budget--) { s->failed_pc=0x0c0b6b52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b6b54;
P_0c0b6b54: /* original 7f08, guest PC 0x0c0b6b54 */
if(!s->budget--) { s->failed_pc=0x0c0b6b54u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b6b56;
P_0c0b6b56: /* original 4f26, guest PC 0x0c0b6b56 */
if(!s->budget--) { s->failed_pc=0x0c0b6b56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b6b58;
P_0c0b6b58: /* original 69f6, guest PC 0x0c0b6b58 */
if(!s->budget--) { s->failed_pc=0x0c0b6b58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b6b5a;
P_0c0b6b5a: /* original 6af6, guest PC 0x0c0b6b5a */
if(!s->budget--) { s->failed_pc=0x0c0b6b5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b6b5c;
P_0c0b6b5c: /* original 6bf6, guest PC 0x0c0b6b5c */
if(!s->budget--) { s->failed_pc=0x0c0b6b5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b6b5e;
P_0c0b6b5e: /* original 6cf6, guest PC 0x0c0b6b5e */
if(!s->budget--) { s->failed_pc=0x0c0b6b5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b6b60;
P_0c0b6b60: /* original 6df6, guest PC 0x0c0b6b60 */
if(!s->budget--) { s->failed_pc=0x0c0b6b60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b6b62;
P_0c0b6b62: /* original 000b, guest PC 0x0c0b6b62 */
if(!s->budget--) { s->failed_pc=0x0c0b6b62u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b6b64: /* original 6ef6, guest PC 0x0c0b6b64 */
if(!s->budget--) { s->failed_pc=0x0c0b6b64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b6b66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b6b66u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
