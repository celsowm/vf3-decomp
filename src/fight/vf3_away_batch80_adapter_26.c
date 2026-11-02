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
int vf3_away_batch80_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
case 0x0c0c674au: goto P_0c0c674a;
case 0x0c0c674cu: goto P_0c0c674c;
case 0x0c0c674eu: goto P_0c0c674e;
case 0x0c0c6750u: goto P_0c0c6750;
case 0x0c0c6752u: goto P_0c0c6752;
case 0x0c0c6754u: goto P_0c0c6754;
case 0x0c0c6756u: goto P_0c0c6756;
case 0x0c0c6758u: goto P_0c0c6758;
case 0x0c0c675au: goto P_0c0c675a;
case 0x0c0c675cu: goto P_0c0c675c;
case 0x0c0c675eu: goto P_0c0c675e;
case 0x0c0c6760u: goto P_0c0c6760;
case 0x0c0c6762u: goto P_0c0c6762;
case 0x0c0c6764u: goto P_0c0c6764;
case 0x0c0c6766u: goto P_0c0c6766;
case 0x0c0c6768u: goto P_0c0c6768;
case 0x0c0c676au: goto P_0c0c676a;
case 0x0c0c676cu: goto P_0c0c676c;
case 0x0c0c676eu: goto P_0c0c676e;
case 0x0c0c6770u: goto P_0c0c6770;
case 0x0c0c6772u: goto P_0c0c6772;
case 0x0c0c6774u: goto P_0c0c6774;
case 0x0c0c6776u: goto P_0c0c6776;
case 0x0c0c6778u: goto P_0c0c6778;
case 0x0c0c677au: goto P_0c0c677a;
case 0x0c0c677cu: goto P_0c0c677c;
case 0x0c0c677eu: goto P_0c0c677e;
case 0x0c0c6780u: goto P_0c0c6780;
case 0x0c0c6782u: goto P_0c0c6782;
case 0x0c0c6784u: goto P_0c0c6784;
case 0x0c0c6786u: goto P_0c0c6786;
case 0x0c0c6788u: goto P_0c0c6788;
case 0x0c0c678au: goto P_0c0c678a;
case 0x0c0c678cu: goto P_0c0c678c;
case 0x0c0c678eu: goto P_0c0c678e;
case 0x0c0c6790u: goto P_0c0c6790;
case 0x0c0c6792u: goto P_0c0c6792;
case 0x0c0c6794u: goto P_0c0c6794;
case 0x0c0c6796u: goto P_0c0c6796;
case 0x0c0c6798u: goto P_0c0c6798;
case 0x0c0c679au: goto P_0c0c679a;
case 0x0c0c679cu: goto P_0c0c679c;
case 0x0c0c679eu: goto P_0c0c679e;
case 0x0c0c67a0u: goto P_0c0c67a0;
case 0x0c0c67a2u: goto P_0c0c67a2;
case 0x0c0c67a4u: goto P_0c0c67a4;
case 0x0c0c67a6u: goto P_0c0c67a6;
case 0x0c0c67a8u: goto P_0c0c67a8;
case 0x0c0c67aau: goto P_0c0c67aa;
case 0x0c0c67acu: goto P_0c0c67ac;
case 0x0c0c67aeu: goto P_0c0c67ae;
case 0x0c0c67b0u: goto P_0c0c67b0;
case 0x0c0c67b2u: goto P_0c0c67b2;
case 0x0c0c67b4u: goto P_0c0c67b4;
case 0x0c0c67b6u: goto P_0c0c67b6;
case 0x0c0c67b8u: goto P_0c0c67b8;
case 0x0c0c67bau: goto P_0c0c67ba;
case 0x0c0c67bcu: goto P_0c0c67bc;
case 0x0c0c67beu: goto P_0c0c67be;
case 0x0c0c67c0u: goto P_0c0c67c0;
case 0x0c0c67c2u: goto P_0c0c67c2;
case 0x0c0c67c4u: goto P_0c0c67c4;
case 0x0c0c67c6u: goto P_0c0c67c6;
case 0x0c0c67c8u: goto P_0c0c67c8;
case 0x0c0c67cau: goto P_0c0c67ca;
case 0x0c0c67ccu: goto P_0c0c67cc;
case 0x0c0c67ceu: goto P_0c0c67ce;
case 0x0c0c67d0u: goto P_0c0c67d0;
case 0x0c0c67d2u: goto P_0c0c67d2;
case 0x0c0c67d4u: goto P_0c0c67d4;
case 0x0c0c67f8u: goto P_0c0c67f8;
case 0x0c0c67fau: goto P_0c0c67fa;
case 0x0c0c67fcu: goto P_0c0c67fc;
case 0x0c0c67feu: goto P_0c0c67fe;
case 0x0c0c6800u: goto P_0c0c6800;
case 0x0c0c6802u: goto P_0c0c6802;
case 0x0c0c6804u: goto P_0c0c6804;
case 0x0c0c6806u: goto P_0c0c6806;
case 0x0c0c6808u: goto P_0c0c6808;
case 0x0c0c680au: goto P_0c0c680a;
case 0x0c0c680cu: goto P_0c0c680c;
case 0x0c0c680eu: goto P_0c0c680e;
case 0x0c0c6810u: goto P_0c0c6810;
case 0x0c0c6812u: goto P_0c0c6812;
case 0x0c0c6814u: goto P_0c0c6814;
case 0x0c0c6816u: goto P_0c0c6816;
case 0x0c0c6818u: goto P_0c0c6818;
case 0x0c0c681au: goto P_0c0c681a;
case 0x0c0c681cu: goto P_0c0c681c;
case 0x0c0c681eu: goto P_0c0c681e;
case 0x0c0c6820u: goto P_0c0c6820;
case 0x0c0c6822u: goto P_0c0c6822;
case 0x0c0c6824u: goto P_0c0c6824;
case 0x0c0c6826u: goto P_0c0c6826;
case 0x0c0c6828u: goto P_0c0c6828;
case 0x0c0c682au: goto P_0c0c682a;
case 0x0c0c682cu: goto P_0c0c682c;
case 0x0c0c682eu: goto P_0c0c682e;
case 0x0c0c6830u: goto P_0c0c6830;
case 0x0c0c6832u: goto P_0c0c6832;
case 0x0c0c6834u: goto P_0c0c6834;
case 0x0c0c6836u: goto P_0c0c6836;
case 0x0c0c6838u: goto P_0c0c6838;
case 0x0c0c683au: goto P_0c0c683a;
case 0x0c0c683cu: goto P_0c0c683c;
case 0x0c0c683eu: goto P_0c0c683e;
case 0x0c0c6840u: goto P_0c0c6840;
case 0x0c0c6842u: goto P_0c0c6842;
case 0x0c0c6844u: goto P_0c0c6844;
case 0x0c0c6846u: goto P_0c0c6846;
case 0x0c0c6848u: goto P_0c0c6848;
case 0x0c0c684au: goto P_0c0c684a;
case 0x0c0c684cu: goto P_0c0c684c;
case 0x0c0c684eu: goto P_0c0c684e;
case 0x0c0c6850u: goto P_0c0c6850;
case 0x0c0c6852u: goto P_0c0c6852;
case 0x0c0c6854u: goto P_0c0c6854;
case 0x0c0c6856u: goto P_0c0c6856;
case 0x0c0c6858u: goto P_0c0c6858;
case 0x0c0c685au: goto P_0c0c685a;
case 0x0c0c685cu: goto P_0c0c685c;
case 0x0c0c685eu: goto P_0c0c685e;
case 0x0c0c6860u: goto P_0c0c6860;
case 0x0c0c6862u: goto P_0c0c6862;
case 0x0c0c6864u: goto P_0c0c6864;
case 0x0c0c6866u: goto P_0c0c6866;
case 0x0c0c6868u: goto P_0c0c6868;
case 0x0c0c686au: goto P_0c0c686a;
case 0x0c0c686cu: goto P_0c0c686c;
case 0x0c0c686eu: goto P_0c0c686e;
case 0x0c0c6870u: goto P_0c0c6870;
case 0x0c0c6872u: goto P_0c0c6872;
case 0x0c0c6874u: goto P_0c0c6874;
case 0x0c0c6876u: goto P_0c0c6876;
case 0x0c0c6878u: goto P_0c0c6878;
case 0x0c0c687au: goto P_0c0c687a;
case 0x0c0c687cu: goto P_0c0c687c;
case 0x0c0c687eu: goto P_0c0c687e;
case 0x0c0c6880u: goto P_0c0c6880;
case 0x0c0c6882u: goto P_0c0c6882;
case 0x0c0c6884u: goto P_0c0c6884;
case 0x0c0c6886u: goto P_0c0c6886;
case 0x0c0c6888u: goto P_0c0c6888;
case 0x0c0c688au: goto P_0c0c688a;
case 0x0c0c688cu: goto P_0c0c688c;
case 0x0c0c688eu: goto P_0c0c688e;
case 0x0c0c6890u: goto P_0c0c6890;
case 0x0c0c6892u: goto P_0c0c6892;
case 0x0c0c6894u: goto P_0c0c6894;
case 0x0c0c6896u: goto P_0c0c6896;
case 0x0c0c6898u: goto P_0c0c6898;
case 0x0c0c689au: goto P_0c0c689a;
case 0x0c0c689cu: goto P_0c0c689c;
case 0x0c0c689eu: goto P_0c0c689e;
case 0x0c0c68a0u: goto P_0c0c68a0;
case 0x0c0c68a2u: goto P_0c0c68a2;
case 0x0c0c68a4u: goto P_0c0c68a4;
case 0x0c0c68a6u: goto P_0c0c68a6;
case 0x0c0c68a8u: goto P_0c0c68a8;
case 0x0c0c68aau: goto P_0c0c68aa;
case 0x0c0c68acu: goto P_0c0c68ac;
case 0x0c0c68aeu: goto P_0c0c68ae;
case 0x0c0c68b0u: goto P_0c0c68b0;
case 0x0c0c68ccu: goto P_0c0c68cc;
case 0x0c0c68ceu: goto P_0c0c68ce;
case 0x0c0c68d0u: goto P_0c0c68d0;
case 0x0c0c68d2u: goto P_0c0c68d2;
case 0x0c0c68d4u: goto P_0c0c68d4;
case 0x0c0c68d6u: goto P_0c0c68d6;
case 0x0c0c68d8u: goto P_0c0c68d8;
case 0x0c0c68dau: goto P_0c0c68da;
case 0x0c0c68dcu: goto P_0c0c68dc;
case 0x0c0c68deu: goto P_0c0c68de;
case 0x0c0c68e0u: goto P_0c0c68e0;
case 0x0c0c68e2u: goto P_0c0c68e2;
case 0x0c0c68e4u: goto P_0c0c68e4;
case 0x0c0c68e6u: goto P_0c0c68e6;
case 0x0c0c68e8u: goto P_0c0c68e8;
case 0x0c0c68eau: goto P_0c0c68ea;
case 0x0c0c68ecu: goto P_0c0c68ec;
case 0x0c0c68eeu: goto P_0c0c68ee;
case 0x0c0c68f0u: goto P_0c0c68f0;
case 0x0c0c68f2u: goto P_0c0c68f2;
case 0x0c0c68f4u: goto P_0c0c68f4;
case 0x0c0c68f6u: goto P_0c0c68f6;
case 0x0c0c68f8u: goto P_0c0c68f8;
case 0x0c0c68fau: goto P_0c0c68fa;
case 0x0c0c68fcu: goto P_0c0c68fc;
case 0x0c0c68feu: goto P_0c0c68fe;
case 0x0c0c6900u: goto P_0c0c6900;
case 0x0c0c6902u: goto P_0c0c6902;
case 0x0c0c6904u: goto P_0c0c6904;
case 0x0c0c6906u: goto P_0c0c6906;
case 0x0c0c6908u: goto P_0c0c6908;
case 0x0c0c690au: goto P_0c0c690a;
case 0x0c0c690cu: goto P_0c0c690c;
case 0x0c0c690eu: goto P_0c0c690e;
case 0x0c0c6910u: goto P_0c0c6910;
case 0x0c0c6912u: goto P_0c0c6912;
case 0x0c0c6914u: goto P_0c0c6914;
case 0x0c0c6916u: goto P_0c0c6916;
case 0x0c0c6918u: goto P_0c0c6918;
case 0x0c0c691au: goto P_0c0c691a;
case 0x0c0c691cu: goto P_0c0c691c;
case 0x0c0c691eu: goto P_0c0c691e;
case 0x0c0c6920u: goto P_0c0c6920;
case 0x0c0c6922u: goto P_0c0c6922;
case 0x0c0c6924u: goto P_0c0c6924;
case 0x0c0c6926u: goto P_0c0c6926;
case 0x0c0c6928u: goto P_0c0c6928;
case 0x0c0c692au: goto P_0c0c692a;
case 0x0c0c692cu: goto P_0c0c692c;
case 0x0c0c692eu: goto P_0c0c692e;
case 0x0c0c6930u: goto P_0c0c6930;
case 0x0c0c6932u: goto P_0c0c6932;
case 0x0c0c6934u: goto P_0c0c6934;
case 0x0c0c6936u: goto P_0c0c6936;
case 0x0c0c6938u: goto P_0c0c6938;
case 0x0c0c693au: goto P_0c0c693a;
case 0x0c0c693cu: goto P_0c0c693c;
case 0x0c0c693eu: goto P_0c0c693e;
case 0x0c0c6940u: goto P_0c0c6940;
case 0x0c0c6942u: goto P_0c0c6942;
case 0x0c0c6944u: goto P_0c0c6944;
case 0x0c0c6946u: goto P_0c0c6946;
case 0x0c0c6948u: goto P_0c0c6948;
case 0x0c0c694au: goto P_0c0c694a;
case 0x0c0c694cu: goto P_0c0c694c;
case 0x0c0c694eu: goto P_0c0c694e;
case 0x0c0c6950u: goto P_0c0c6950;
case 0x0c0c6952u: goto P_0c0c6952;
case 0x0c0c6954u: goto P_0c0c6954;
case 0x0c0c6956u: goto P_0c0c6956;
case 0x0c0c6958u: goto P_0c0c6958;
case 0x0c0c695au: goto P_0c0c695a;
case 0x0c0c695cu: goto P_0c0c695c;
case 0x0c0c695eu: goto P_0c0c695e;
case 0x0c0c6960u: goto P_0c0c6960;
case 0x0c0c6962u: goto P_0c0c6962;
case 0x0c0c6964u: goto P_0c0c6964;
case 0x0c0c6966u: goto P_0c0c6966;
case 0x0c0c6968u: goto P_0c0c6968;
case 0x0c0c696au: goto P_0c0c696a;
case 0x0c0c696cu: goto P_0c0c696c;
case 0x0c0c696eu: goto P_0c0c696e;
case 0x0c0c6970u: goto P_0c0c6970;
case 0x0c0c6972u: goto P_0c0c6972;
case 0x0c0c6974u: goto P_0c0c6974;
case 0x0c0c6976u: goto P_0c0c6976;
case 0x0c0c6978u: goto P_0c0c6978;
case 0x0c0c697au: goto P_0c0c697a;
case 0x0c0c697cu: goto P_0c0c697c;
case 0x0c0c697eu: goto P_0c0c697e;
case 0x0c0c6980u: goto P_0c0c6980;
case 0x0c0c6982u: goto P_0c0c6982;
case 0x0c0c6984u: goto P_0c0c6984;
case 0x0c0c6986u: goto P_0c0c6986;
case 0x0c0c6988u: goto P_0c0c6988;
case 0x0c0c698au: goto P_0c0c698a;
case 0x0c0c698cu: goto P_0c0c698c;
case 0x0c0c698eu: goto P_0c0c698e;
case 0x0c0c6990u: goto P_0c0c6990;
case 0x0c0c6992u: goto P_0c0c6992;
case 0x0c0c6994u: goto P_0c0c6994;
case 0x0c0c6996u: goto P_0c0c6996;
case 0x0c0c69b8u: goto P_0c0c69b8;
case 0x0c0c69bau: goto P_0c0c69ba;
case 0x0c0c69bcu: goto P_0c0c69bc;
case 0x0c0c69beu: goto P_0c0c69be;
case 0x0c0c69c0u: goto P_0c0c69c0;
case 0x0c0c69c2u: goto P_0c0c69c2;
case 0x0c0c69c4u: goto P_0c0c69c4;
case 0x0c0c69c6u: goto P_0c0c69c6;
case 0x0c0c69c8u: goto P_0c0c69c8;
case 0x0c0c69cau: goto P_0c0c69ca;
case 0x0c0c69ccu: goto P_0c0c69cc;
case 0x0c0c69ceu: goto P_0c0c69ce;
case 0x0c0c69d0u: goto P_0c0c69d0;
case 0x0c0c69d2u: goto P_0c0c69d2;
case 0x0c0c69d4u: goto P_0c0c69d4;
case 0x0c0c69d6u: goto P_0c0c69d6;
case 0x0c0c69d8u: goto P_0c0c69d8;
case 0x0c0c69dau: goto P_0c0c69da;
case 0x0c0c69dcu: goto P_0c0c69dc;
case 0x0c0c69deu: goto P_0c0c69de;
case 0x0c0c69e0u: goto P_0c0c69e0;
case 0x0c0c69e2u: goto P_0c0c69e2;
case 0x0c0c69e4u: goto P_0c0c69e4;
case 0x0c0c69e6u: goto P_0c0c69e6;
case 0x0c0c69e8u: goto P_0c0c69e8;
case 0x0c0c69eau: goto P_0c0c69ea;
case 0x0c0c69ecu: goto P_0c0c69ec;
case 0x0c0c69eeu: goto P_0c0c69ee;
case 0x0c0c69f0u: goto P_0c0c69f0;
case 0x0c0c69f2u: goto P_0c0c69f2;
case 0x0c0c69f4u: goto P_0c0c69f4;
case 0x0c0c69f6u: goto P_0c0c69f6;
case 0x0c0c69f8u: goto P_0c0c69f8;
case 0x0c0c69fau: goto P_0c0c69fa;
case 0x0c0c69fcu: goto P_0c0c69fc;
case 0x0c0c69feu: goto P_0c0c69fe;
case 0x0c0c6a00u: goto P_0c0c6a00;
case 0x0c0c6a02u: goto P_0c0c6a02;
case 0x0c0c6a04u: goto P_0c0c6a04;
case 0x0c0c6a06u: goto P_0c0c6a06;
case 0x0c0c6a08u: goto P_0c0c6a08;
case 0x0c0c6a0au: goto P_0c0c6a0a;
case 0x0c0c6a0cu: goto P_0c0c6a0c;
case 0x0c0c6a0eu: goto P_0c0c6a0e;
case 0x0c0c6a10u: goto P_0c0c6a10;
case 0x0c0c6a12u: goto P_0c0c6a12;
case 0x0c0c6a14u: goto P_0c0c6a14;
case 0x0c0c6a16u: goto P_0c0c6a16;
case 0x0c0c6a18u: goto P_0c0c6a18;
case 0x0c0c6a1au: goto P_0c0c6a1a;
case 0x0c0c6a1cu: goto P_0c0c6a1c;
case 0x0c0c6a1eu: goto P_0c0c6a1e;
case 0x0c0c6a20u: goto P_0c0c6a20;
case 0x0c0c6a22u: goto P_0c0c6a22;
case 0x0c0c6a24u: goto P_0c0c6a24;
case 0x0c0c6a26u: goto P_0c0c6a26;
case 0x0c0c6a28u: goto P_0c0c6a28;
case 0x0c0c6a2au: goto P_0c0c6a2a;
case 0x0c0c6a2cu: goto P_0c0c6a2c;
case 0x0c0c6a2eu: goto P_0c0c6a2e;
case 0x0c0c6a30u: goto P_0c0c6a30;
case 0x0c0c6a32u: goto P_0c0c6a32;
case 0x0c0c6a34u: goto P_0c0c6a34;
case 0x0c0c6a36u: goto P_0c0c6a36;
case 0x0c0c6a38u: goto P_0c0c6a38;
case 0x0c0c6a3au: goto P_0c0c6a3a;
case 0x0c0c6a3cu: goto P_0c0c6a3c;
case 0x0c0c6a3eu: goto P_0c0c6a3e;
case 0x0c0c6a40u: goto P_0c0c6a40;
case 0x0c0c6a42u: goto P_0c0c6a42;
case 0x0c0c6a44u: goto P_0c0c6a44;
case 0x0c0c6a46u: goto P_0c0c6a46;
case 0x0c0c6a48u: goto P_0c0c6a48;
case 0x0c0c6a4au: goto P_0c0c6a4a;
case 0x0c0c6a4cu: goto P_0c0c6a4c;
case 0x0c0c6a4eu: goto P_0c0c6a4e;
case 0x0c0c6a50u: goto P_0c0c6a50;
case 0x0c0c6a52u: goto P_0c0c6a52;
case 0x0c0c6a54u: goto P_0c0c6a54;
case 0x0c0c6a56u: goto P_0c0c6a56;
case 0x0c0c6a58u: goto P_0c0c6a58;
case 0x0c0c6a5au: goto P_0c0c6a5a;
case 0x0c0c6a5cu: goto P_0c0c6a5c;
case 0x0c0c6a5eu: goto P_0c0c6a5e;
case 0x0c0c6a60u: goto P_0c0c6a60;
case 0x0c0c6a62u: goto P_0c0c6a62;
case 0x0c0c6a64u: goto P_0c0c6a64;
case 0x0c0c6a66u: goto P_0c0c6a66;
case 0x0c0c6a68u: goto P_0c0c6a68;
case 0x0c0c6a6au: goto P_0c0c6a6a;
case 0x0c0c6a6cu: goto P_0c0c6a6c;
case 0x0c0c6a6eu: goto P_0c0c6a6e;
case 0x0c0c6a70u: goto P_0c0c6a70;
case 0x0c0c6a72u: goto P_0c0c6a72;
case 0x0c0c6a74u: goto P_0c0c6a74;
case 0x0c0c6a76u: goto P_0c0c6a76;
case 0x0c0c6a78u: goto P_0c0c6a78;
case 0x0c0c6a7au: goto P_0c0c6a7a;
case 0x0c0c6a7cu: goto P_0c0c6a7c;
case 0x0c0c6a7eu: goto P_0c0c6a7e;
case 0x0c0c6a80u: goto P_0c0c6a80;
case 0x0c0c6a82u: goto P_0c0c6a82;
case 0x0c0c6a84u: goto P_0c0c6a84;
case 0x0c0c6a86u: goto P_0c0c6a86;
case 0x0c0c6a88u: goto P_0c0c6a88;
case 0x0c0c6a8au: goto P_0c0c6a8a;
case 0x0c0c6a8cu: goto P_0c0c6a8c;
case 0x0c0c6a8eu: goto P_0c0c6a8e;
case 0x0c0c6a90u: goto P_0c0c6a90;
case 0x0c0c6a92u: goto P_0c0c6a92;
case 0x0c0c6a94u: goto P_0c0c6a94;
case 0x0c0c6a96u: goto P_0c0c6a96;
case 0x0c0c6a98u: goto P_0c0c6a98;
case 0x0c0c6a9au: goto P_0c0c6a9a;
case 0x0c0c6a9cu: goto P_0c0c6a9c;
case 0x0c0c6a9eu: goto P_0c0c6a9e;
case 0x0c0c6aa0u: goto P_0c0c6aa0;
case 0x0c0c6aa2u: goto P_0c0c6aa2;
case 0x0c0c6aa4u: goto P_0c0c6aa4;
case 0x0c0c6aa6u: goto P_0c0c6aa6;
case 0x0c0c6aa8u: goto P_0c0c6aa8;
case 0x0c0c6aaau: goto P_0c0c6aaa;
case 0x0c0c6aacu: goto P_0c0c6aac;
case 0x0c0c6aaeu: goto P_0c0c6aae;
case 0x0c0c6ab0u: goto P_0c0c6ab0;
case 0x0c0c6ab2u: goto P_0c0c6ab2;
case 0x0c0c6ab4u: goto P_0c0c6ab4;
case 0x0c0c6ab6u: goto P_0c0c6ab6;
case 0x0c0c6ab8u: goto P_0c0c6ab8;
case 0x0c0c6aecu: goto P_0c0c6aec;
case 0x0c0c6aeeu: goto P_0c0c6aee;
case 0x0c0c6af0u: goto P_0c0c6af0;
case 0x0c0c6af2u: goto P_0c0c6af2;
case 0x0c0c6af4u: goto P_0c0c6af4;
case 0x0c0c6af6u: goto P_0c0c6af6;
case 0x0c0c6af8u: goto P_0c0c6af8;
case 0x0c0c6afau: goto P_0c0c6afa;
case 0x0c0c6afcu: goto P_0c0c6afc;
case 0x0c0c6afeu: goto P_0c0c6afe;
case 0x0c0c6b00u: goto P_0c0c6b00;
case 0x0c0c6b02u: goto P_0c0c6b02;
case 0x0c0c6b04u: goto P_0c0c6b04;
case 0x0c0c6b06u: goto P_0c0c6b06;
case 0x0c0c6b08u: goto P_0c0c6b08;
case 0x0c0c6b0au: goto P_0c0c6b0a;
case 0x0c0c6b0cu: goto P_0c0c6b0c;
case 0x0c0c6b0eu: goto P_0c0c6b0e;
case 0x0c0c6b10u: goto P_0c0c6b10;
case 0x0c0c6b12u: goto P_0c0c6b12;
case 0x0c0c6b14u: goto P_0c0c6b14;
case 0x0c0c6b16u: goto P_0c0c6b16;
case 0x0c0c6b18u: goto P_0c0c6b18;
case 0x0c0c6b1au: goto P_0c0c6b1a;
case 0x0c0c6b1cu: goto P_0c0c6b1c;
case 0x0c0c6b1eu: goto P_0c0c6b1e;
case 0x0c0c6b20u: goto P_0c0c6b20;
case 0x0c0c6b22u: goto P_0c0c6b22;
case 0x0c0c6b24u: goto P_0c0c6b24;
case 0x0c0c6b26u: goto P_0c0c6b26;
case 0x0c0c6b28u: goto P_0c0c6b28;
case 0x0c0c6b2au: goto P_0c0c6b2a;
case 0x0c0c6b2cu: goto P_0c0c6b2c;
case 0x0c0c6b2eu: goto P_0c0c6b2e;
case 0x0c0c6b30u: goto P_0c0c6b30;
case 0x0c0c6b32u: goto P_0c0c6b32;
case 0x0c0c6b34u: goto P_0c0c6b34;
case 0x0c0c6b36u: goto P_0c0c6b36;
case 0x0c0c6b38u: goto P_0c0c6b38;
case 0x0c0c6b3au: goto P_0c0c6b3a;
case 0x0c0c6b3cu: goto P_0c0c6b3c;
case 0x0c0c6b3eu: goto P_0c0c6b3e;
case 0x0c0c6b40u: goto P_0c0c6b40;
case 0x0c0c6b42u: goto P_0c0c6b42;
case 0x0c0c6b44u: goto P_0c0c6b44;
case 0x0c0c6b46u: goto P_0c0c6b46;
case 0x0c0c6b48u: goto P_0c0c6b48;
case 0x0c0c6b4au: goto P_0c0c6b4a;
case 0x0c0c6b4cu: goto P_0c0c6b4c;
case 0x0c0c6b4eu: goto P_0c0c6b4e;
case 0x0c0c6b50u: goto P_0c0c6b50;
case 0x0c0c6b52u: goto P_0c0c6b52;
case 0x0c0c6b54u: goto P_0c0c6b54;
case 0x0c0c6b56u: goto P_0c0c6b56;
case 0x0c0c6b58u: goto P_0c0c6b58;
case 0x0c0c6b5au: goto P_0c0c6b5a;
case 0x0c0c6b5cu: goto P_0c0c6b5c;
case 0x0c0c6b5eu: goto P_0c0c6b5e;
case 0x0c0c6b60u: goto P_0c0c6b60;
case 0x0c0c6b62u: goto P_0c0c6b62;
case 0x0c0c6b64u: goto P_0c0c6b64;
case 0x0c0c6b66u: goto P_0c0c6b66;
case 0x0c0c6b68u: goto P_0c0c6b68;
case 0x0c0c6b6au: goto P_0c0c6b6a;
case 0x0c0c6b6cu: goto P_0c0c6b6c;
case 0x0c0c6b6eu: goto P_0c0c6b6e;
case 0x0c0c6b70u: goto P_0c0c6b70;
case 0x0c0c6b72u: goto P_0c0c6b72;
case 0x0c0c6b74u: goto P_0c0c6b74;
case 0x0c0c6b76u: goto P_0c0c6b76;
case 0x0c0c6b78u: goto P_0c0c6b78;
case 0x0c0c6b7au: goto P_0c0c6b7a;
case 0x0c0c6b7cu: goto P_0c0c6b7c;
case 0x0c0c6b7eu: goto P_0c0c6b7e;
case 0x0c0c6b80u: goto P_0c0c6b80;
case 0x0c0c6b82u: goto P_0c0c6b82;
case 0x0c0c6b84u: goto P_0c0c6b84;
case 0x0c0c6b86u: goto P_0c0c6b86;
case 0x0c0c6b88u: goto P_0c0c6b88;
case 0x0c0c6b8au: goto P_0c0c6b8a;
case 0x0c0c6b8cu: goto P_0c0c6b8c;
case 0x0c0c6b8eu: goto P_0c0c6b8e;
case 0x0c0c6b90u: goto P_0c0c6b90;
case 0x0c0c6b92u: goto P_0c0c6b92;
case 0x0c0c6b94u: goto P_0c0c6b94;
case 0x0c0c6b96u: goto P_0c0c6b96;
case 0x0c0c6b98u: goto P_0c0c6b98;
case 0x0c0c6b9au: goto P_0c0c6b9a;
case 0x0c0c6b9cu: goto P_0c0c6b9c;
case 0x0c0c6b9eu: goto P_0c0c6b9e;
case 0x0c0c6ba0u: goto P_0c0c6ba0;
case 0x0c0c6ba2u: goto P_0c0c6ba2;
case 0x0c0c6ba4u: goto P_0c0c6ba4;
case 0x0c0c6ba6u: goto P_0c0c6ba6;
case 0x0c0c6ba8u: goto P_0c0c6ba8;
case 0x0c0c6baau: goto P_0c0c6baa;
case 0x0c0c6bacu: goto P_0c0c6bac;
case 0x0c0c6baeu: goto P_0c0c6bae;
case 0x0c0c6bb0u: goto P_0c0c6bb0;
case 0x0c0c6bb2u: goto P_0c0c6bb2;
case 0x0c0c6bb4u: goto P_0c0c6bb4;
case 0x0c0c6bb6u: goto P_0c0c6bb6;
case 0x0c0c6bb8u: goto P_0c0c6bb8;
case 0x0c0c6bbau: goto P_0c0c6bba;
case 0x0c0c6bbcu: goto P_0c0c6bbc;
case 0x0c0c6bbeu: goto P_0c0c6bbe;
case 0x0c0c6bc0u: goto P_0c0c6bc0;
case 0x0c0c6bc2u: goto P_0c0c6bc2;
case 0x0c0c6bc4u: goto P_0c0c6bc4;
case 0x0c0c6bc6u: goto P_0c0c6bc6;
case 0x0c0c6bc8u: goto P_0c0c6bc8;
case 0x0c0c6bcau: goto P_0c0c6bca;
case 0x0c0c6bccu: goto P_0c0c6bcc;
case 0x0c0c6bceu: goto P_0c0c6bce;
case 0x0c0c6bd0u: goto P_0c0c6bd0;
case 0x0c0c6bd2u: goto P_0c0c6bd2;
case 0x0c0c6bd4u: goto P_0c0c6bd4;
case 0x0c0c6bd6u: goto P_0c0c6bd6;
case 0x0c0c6bd8u: goto P_0c0c6bd8;
case 0x0c0c6bdau: goto P_0c0c6bda;
case 0x0c0c6bdcu: goto P_0c0c6bdc;
case 0x0c0c6bdeu: goto P_0c0c6bde;
case 0x0c0c6be0u: goto P_0c0c6be0;
case 0x0c0c6c14u: goto P_0c0c6c14;
case 0x0c0c6c16u: goto P_0c0c6c16;
case 0x0c0c6c18u: goto P_0c0c6c18;
case 0x0c0c6c1au: goto P_0c0c6c1a;
case 0x0c0c6c1cu: goto P_0c0c6c1c;
case 0x0c0c6c1eu: goto P_0c0c6c1e;
case 0x0c0c6c20u: goto P_0c0c6c20;
case 0x0c0c6c22u: goto P_0c0c6c22;
case 0x0c0c6c24u: goto P_0c0c6c24;
case 0x0c0c6c26u: goto P_0c0c6c26;
case 0x0c0c6c28u: goto P_0c0c6c28;
case 0x0c0c6c2au: goto P_0c0c6c2a;
case 0x0c0c6c2cu: goto P_0c0c6c2c;
case 0x0c0c6c2eu: goto P_0c0c6c2e;
case 0x0c0c6c30u: goto P_0c0c6c30;
case 0x0c0c6c32u: goto P_0c0c6c32;
case 0x0c0c6c34u: goto P_0c0c6c34;
case 0x0c0c6c36u: goto P_0c0c6c36;
case 0x0c0c6c38u: goto P_0c0c6c38;
case 0x0c0c6c3au: goto P_0c0c6c3a;
case 0x0c0c6c3cu: goto P_0c0c6c3c;
case 0x0c0c6c3eu: goto P_0c0c6c3e;
case 0x0c0c6c40u: goto P_0c0c6c40;
case 0x0c0c6c42u: goto P_0c0c6c42;
case 0x0c0c6c44u: goto P_0c0c6c44;
case 0x0c0c6c46u: goto P_0c0c6c46;
case 0x0c0c6c48u: goto P_0c0c6c48;
case 0x0c0c6c4au: goto P_0c0c6c4a;
case 0x0c0c6c4cu: goto P_0c0c6c4c;
case 0x0c0c6c4eu: goto P_0c0c6c4e;
case 0x0c0c6c50u: goto P_0c0c6c50;
case 0x0c0c6c52u: goto P_0c0c6c52;
case 0x0c0c6c54u: goto P_0c0c6c54;
case 0x0c0c6c56u: goto P_0c0c6c56;
case 0x0c0c6c58u: goto P_0c0c6c58;
case 0x0c0c6c5au: goto P_0c0c6c5a;
case 0x0c0c6c5cu: goto P_0c0c6c5c;
case 0x0c0c6c5eu: goto P_0c0c6c5e;
case 0x0c0c6c60u: goto P_0c0c6c60;
case 0x0c0c6c62u: goto P_0c0c6c62;
case 0x0c0c6c64u: goto P_0c0c6c64;
case 0x0c0c6c66u: goto P_0c0c6c66;
case 0x0c0c6c68u: goto P_0c0c6c68;
case 0x0c0c6c6au: goto P_0c0c6c6a;
case 0x0c0c6c6cu: goto P_0c0c6c6c;
case 0x0c0c6c6eu: goto P_0c0c6c6e;
case 0x0c0c6c70u: goto P_0c0c6c70;
case 0x0c0c6c72u: goto P_0c0c6c72;
case 0x0c0c6c74u: goto P_0c0c6c74;
case 0x0c0c6c76u: goto P_0c0c6c76;
case 0x0c0c6c78u: goto P_0c0c6c78;
case 0x0c0c6c7au: goto P_0c0c6c7a;
case 0x0c0c6c7cu: goto P_0c0c6c7c;
case 0x0c0c6c7eu: goto P_0c0c6c7e;
case 0x0c0c6c80u: goto P_0c0c6c80;
case 0x0c0c6c82u: goto P_0c0c6c82;
case 0x0c0c6c84u: goto P_0c0c6c84;
case 0x0c0c6c86u: goto P_0c0c6c86;
case 0x0c0c6c88u: goto P_0c0c6c88;
case 0x0c0c6c8au: goto P_0c0c6c8a;
case 0x0c0c6c8cu: goto P_0c0c6c8c;
case 0x0c0c6c8eu: goto P_0c0c6c8e;
case 0x0c0c6c90u: goto P_0c0c6c90;
case 0x0c0c6c92u: goto P_0c0c6c92;
case 0x0c0c6c94u: goto P_0c0c6c94;
case 0x0c0c6c96u: goto P_0c0c6c96;
case 0x0c0c6c98u: goto P_0c0c6c98;
case 0x0c0c6c9au: goto P_0c0c6c9a;
case 0x0c0c6c9cu: goto P_0c0c6c9c;
case 0x0c0c6c9eu: goto P_0c0c6c9e;
case 0x0c0c6ca0u: goto P_0c0c6ca0;
case 0x0c0c6ca2u: goto P_0c0c6ca2;
case 0x0c0c6ca4u: goto P_0c0c6ca4;
case 0x0c0c6ca6u: goto P_0c0c6ca6;
case 0x0c0c6ca8u: goto P_0c0c6ca8;
case 0x0c0c6caau: goto P_0c0c6caa;
case 0x0c0c6cacu: goto P_0c0c6cac;
case 0x0c0c6caeu: goto P_0c0c6cae;
case 0x0c0c6cb0u: goto P_0c0c6cb0;
case 0x0c0c6cb2u: goto P_0c0c6cb2;
case 0x0c0c6cb4u: goto P_0c0c6cb4;
case 0x0c0c6cb6u: goto P_0c0c6cb6;
case 0x0c0c6cb8u: goto P_0c0c6cb8;
case 0x0c0c6cbau: goto P_0c0c6cba;
case 0x0c0c6cbcu: goto P_0c0c6cbc;
case 0x0c0c6cbeu: goto P_0c0c6cbe;
case 0x0c0c6cc0u: goto P_0c0c6cc0;
case 0x0c0c6cc2u: goto P_0c0c6cc2;
case 0x0c0c6cc4u: goto P_0c0c6cc4;
case 0x0c0c6cc6u: goto P_0c0c6cc6;
case 0x0c0c6cc8u: goto P_0c0c6cc8;
case 0x0c0c6ccau: goto P_0c0c6cca;
case 0x0c0c6cccu: goto P_0c0c6ccc;
case 0x0c0c6cf8u: goto P_0c0c6cf8;
case 0x0c0c6cfau: goto P_0c0c6cfa;
case 0x0c0c6cfcu: goto P_0c0c6cfc;
case 0x0c0c6cfeu: goto P_0c0c6cfe;
case 0x0c0c6d00u: goto P_0c0c6d00;
case 0x0c0c6d02u: goto P_0c0c6d02;
case 0x0c0c6d04u: goto P_0c0c6d04;
case 0x0c0c6d06u: goto P_0c0c6d06;
case 0x0c0c6d08u: goto P_0c0c6d08;
case 0x0c0c6d0au: goto P_0c0c6d0a;
case 0x0c0c6d0cu: goto P_0c0c6d0c;
case 0x0c0c6d0eu: goto P_0c0c6d0e;
case 0x0c0c6d10u: goto P_0c0c6d10;
case 0x0c0c6d12u: goto P_0c0c6d12;
case 0x0c0c6d14u: goto P_0c0c6d14;
case 0x0c0c6d16u: goto P_0c0c6d16;
case 0x0c0c6d18u: goto P_0c0c6d18;
case 0x0c0c6d1au: goto P_0c0c6d1a;
case 0x0c0c6d1cu: goto P_0c0c6d1c;
case 0x0c0c6d1eu: goto P_0c0c6d1e;
case 0x0c0c6d20u: goto P_0c0c6d20;
case 0x0c0c6d22u: goto P_0c0c6d22;
case 0x0c0c6d24u: goto P_0c0c6d24;
case 0x0c0c6d26u: goto P_0c0c6d26;
case 0x0c0c6d28u: goto P_0c0c6d28;
case 0x0c0c6d2au: goto P_0c0c6d2a;
case 0x0c0c6d2cu: goto P_0c0c6d2c;
case 0x0c0c6d2eu: goto P_0c0c6d2e;
case 0x0c0c6d30u: goto P_0c0c6d30;
case 0x0c0c6d32u: goto P_0c0c6d32;
case 0x0c0c6d34u: goto P_0c0c6d34;
case 0x0c0c6d36u: goto P_0c0c6d36;
case 0x0c0c6d38u: goto P_0c0c6d38;
case 0x0c0c6d3au: goto P_0c0c6d3a;
case 0x0c0c6d3cu: goto P_0c0c6d3c;
case 0x0c0c6d3eu: goto P_0c0c6d3e;
case 0x0c0c6d40u: goto P_0c0c6d40;
case 0x0c0c6d42u: goto P_0c0c6d42;
case 0x0c0c6d44u: goto P_0c0c6d44;
case 0x0c0c6d46u: goto P_0c0c6d46;
case 0x0c0c6d48u: goto P_0c0c6d48;
case 0x0c0c6d4au: goto P_0c0c6d4a;
case 0x0c0c6d4cu: goto P_0c0c6d4c;
case 0x0c0c6d4eu: goto P_0c0c6d4e;
case 0x0c0c6d50u: goto P_0c0c6d50;
case 0x0c0c6d52u: goto P_0c0c6d52;
case 0x0c0c6d54u: goto P_0c0c6d54;
case 0x0c0c6d56u: goto P_0c0c6d56;
case 0x0c0c6d58u: goto P_0c0c6d58;
case 0x0c0c6d5au: goto P_0c0c6d5a;
case 0x0c0c6d5cu: goto P_0c0c6d5c;
case 0x0c0c6d5eu: goto P_0c0c6d5e;
case 0x0c0c6d60u: goto P_0c0c6d60;
case 0x0c0c6d62u: goto P_0c0c6d62;
case 0x0c0c6d64u: goto P_0c0c6d64;
case 0x0c0c6d66u: goto P_0c0c6d66;
case 0x0c0c6d68u: goto P_0c0c6d68;
case 0x0c0c6d6au: goto P_0c0c6d6a;
case 0x0c0c6d6cu: goto P_0c0c6d6c;
case 0x0c0c6d6eu: goto P_0c0c6d6e;
case 0x0c0c6d70u: goto P_0c0c6d70;
case 0x0c0c6d72u: goto P_0c0c6d72;
case 0x0c0c6d74u: goto P_0c0c6d74;
case 0x0c0c6d76u: goto P_0c0c6d76;
case 0x0c0c6d78u: goto P_0c0c6d78;
case 0x0c0c6d7au: goto P_0c0c6d7a;
case 0x0c0c6d7cu: goto P_0c0c6d7c;
case 0x0c0c6d7eu: goto P_0c0c6d7e;
case 0x0c0c6d80u: goto P_0c0c6d80;
case 0x0c0c6d82u: goto P_0c0c6d82;
case 0x0c0c6d84u: goto P_0c0c6d84;
case 0x0c0c6d86u: goto P_0c0c6d86;
case 0x0c0c6d88u: goto P_0c0c6d88;
case 0x0c0c6d8au: goto P_0c0c6d8a;
case 0x0c0c6d8cu: goto P_0c0c6d8c;
case 0x0c0c6d8eu: goto P_0c0c6d8e;
case 0x0c0c6d90u: goto P_0c0c6d90;
case 0x0c0c6d92u: goto P_0c0c6d92;
case 0x0c0c6d94u: goto P_0c0c6d94;
case 0x0c0c6d96u: goto P_0c0c6d96;
case 0x0c0c6d98u: goto P_0c0c6d98;
case 0x0c0c6d9au: goto P_0c0c6d9a;
case 0x0c0c6d9cu: goto P_0c0c6d9c;
case 0x0c0c6d9eu: goto P_0c0c6d9e;
case 0x0c0c6da0u: goto P_0c0c6da0;
case 0x0c0c6da2u: goto P_0c0c6da2;
case 0x0c0c6da4u: goto P_0c0c6da4;
case 0x0c0c6da6u: goto P_0c0c6da6;
case 0x0c0c6da8u: goto P_0c0c6da8;
case 0x0c0c6daau: goto P_0c0c6daa;
case 0x0c0c6dacu: goto P_0c0c6dac;
case 0x0c0c6daeu: goto P_0c0c6dae;
case 0x0c0c6db0u: goto P_0c0c6db0;
case 0x0c0c6db2u: goto P_0c0c6db2;
case 0x0c0c6db4u: goto P_0c0c6db4;
case 0x0c0c6db6u: goto P_0c0c6db6;
case 0x0c0c6db8u: goto P_0c0c6db8;
case 0x0c0c6dbau: goto P_0c0c6dba;
case 0x0c0c6dbcu: goto P_0c0c6dbc;
case 0x0c0c6dbeu: goto P_0c0c6dbe;
case 0x0c0c6dc0u: goto P_0c0c6dc0;
case 0x0c0c6dc2u: goto P_0c0c6dc2;
case 0x0c0c6dc4u: goto P_0c0c6dc4;
case 0x0c0c6dc6u: goto P_0c0c6dc6;
case 0x0c0c6dc8u: goto P_0c0c6dc8;
case 0x0c0c6dcau: goto P_0c0c6dca;
case 0x0c0c6dccu: goto P_0c0c6dcc;
case 0x0c0c6dfcu: goto P_0c0c6dfc;
case 0x0c0c6dfeu: goto P_0c0c6dfe;
case 0x0c0c6e00u: goto P_0c0c6e00;
case 0x0c0c6e02u: goto P_0c0c6e02;
case 0x0c0c6e04u: goto P_0c0c6e04;
case 0x0c0c6e06u: goto P_0c0c6e06;
case 0x0c0c6e08u: goto P_0c0c6e08;
case 0x0c0c6e0au: goto P_0c0c6e0a;
case 0x0c0c6e0cu: goto P_0c0c6e0c;
case 0x0c0c6e0eu: goto P_0c0c6e0e;
case 0x0c0c6e10u: goto P_0c0c6e10;
case 0x0c0c6e12u: goto P_0c0c6e12;
case 0x0c0c6e14u: goto P_0c0c6e14;
case 0x0c0c6e16u: goto P_0c0c6e16;
case 0x0c0c6e18u: goto P_0c0c6e18;
case 0x0c0c6e1au: goto P_0c0c6e1a;
case 0x0c0c6e1cu: goto P_0c0c6e1c;
case 0x0c0c6e1eu: goto P_0c0c6e1e;
case 0x0c0c6e20u: goto P_0c0c6e20;
case 0x0c0c6e22u: goto P_0c0c6e22;
case 0x0c0c6e24u: goto P_0c0c6e24;
case 0x0c0c6e26u: goto P_0c0c6e26;
case 0x0c0c6e28u: goto P_0c0c6e28;
case 0x0c0c6e2au: goto P_0c0c6e2a;
case 0x0c0c6e2cu: goto P_0c0c6e2c;
case 0x0c0c6e2eu: goto P_0c0c6e2e;
case 0x0c0c6e30u: goto P_0c0c6e30;
case 0x0c0c6e32u: goto P_0c0c6e32;
case 0x0c0c6e34u: goto P_0c0c6e34;
case 0x0c0c6e36u: goto P_0c0c6e36;
case 0x0c0c6e38u: goto P_0c0c6e38;
case 0x0c0c6e3au: goto P_0c0c6e3a;
case 0x0c0c6e3cu: goto P_0c0c6e3c;
case 0x0c0c6e3eu: goto P_0c0c6e3e;
case 0x0c0c6e40u: goto P_0c0c6e40;
case 0x0c0c6e42u: goto P_0c0c6e42;
case 0x0c0c6e44u: goto P_0c0c6e44;
case 0x0c0c6e46u: goto P_0c0c6e46;
case 0x0c0c6e48u: goto P_0c0c6e48;
case 0x0c0c6e4au: goto P_0c0c6e4a;
case 0x0c0c6e4cu: goto P_0c0c6e4c;
case 0x0c0c6e4eu: goto P_0c0c6e4e;
case 0x0c0c6e50u: goto P_0c0c6e50;
case 0x0c0c6e52u: goto P_0c0c6e52;
case 0x0c0c6e54u: goto P_0c0c6e54;
case 0x0c0c6e56u: goto P_0c0c6e56;
case 0x0c0c6e58u: goto P_0c0c6e58;
case 0x0c0c6e5au: goto P_0c0c6e5a;
case 0x0c0c6e5cu: goto P_0c0c6e5c;
case 0x0c0c6e5eu: goto P_0c0c6e5e;
case 0x0c0c6e60u: goto P_0c0c6e60;
case 0x0c0c6e62u: goto P_0c0c6e62;
case 0x0c0c6e64u: goto P_0c0c6e64;
case 0x0c0c6e66u: goto P_0c0c6e66;
case 0x0c0c6e68u: goto P_0c0c6e68;
case 0x0c0c6e6au: goto P_0c0c6e6a;
case 0x0c0c6e6cu: goto P_0c0c6e6c;
case 0x0c0c6e6eu: goto P_0c0c6e6e;
case 0x0c0c6e70u: goto P_0c0c6e70;
case 0x0c0c6e72u: goto P_0c0c6e72;
case 0x0c0c6e74u: goto P_0c0c6e74;
case 0x0c0c6e76u: goto P_0c0c6e76;
case 0x0c0c6e78u: goto P_0c0c6e78;
case 0x0c0c6e7au: goto P_0c0c6e7a;
case 0x0c0c6e7cu: goto P_0c0c6e7c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5dba;
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
goto P_0c0c5dba;
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c674a;
P_0c0c674a: /* original 4f22, guest PC 0x0c0c674a */
if(!s->budget--) { s->failed_pc=0x0c0c674au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c674c;
P_0c0c674c: /* original 7ff8, guest PC 0x0c0c674c */
if(!s->budget--) { s->failed_pc=0x0c0c674cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c674e;
P_0c0c674e: /* original 2f42, guest PC 0x0c0c674e */
if(!s->budget--) { s->failed_pc=0x0c0c674eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c6750;
P_0c0c6750: /* original 1f51, guest PC 0x0c0c6750 */
if(!s->budget--) { s->failed_pc=0x0c0c6750u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0c6752;
P_0c0c6752: /* original d126, guest PC 0x0c0c6752 */
if(!s->budget--) { s->failed_pc=0x0c0c6752u; return 0; }
r[1]=read(ram,0x0c0c67ecu,4);
goto P_0c0c6754;
P_0c0c6754: /* original d324, guest PC 0x0c0c6754 */
if(!s->budget--) { s->failed_pc=0x0c0c6754u; return 0; }
r[3]=read(ram,0x0c0c67e8u,4);
goto P_0c0c6756;
P_0c0c6756: /* original 6212, guest PC 0x0c0c6756 */
if(!s->budget--) { s->failed_pc=0x0c0c6756u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6758;
P_0c0c6758: /* original 2238, guest PC 0x0c0c6758 */
if(!s->budget--) { s->failed_pc=0x0c0c6758u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c675a;
P_0c0c675a: /* original 8b05, guest PC 0x0c0c675a */
if(!s->budget--) { s->failed_pc=0x0c0c675au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6768; }
goto P_0c0c675c;
P_0c0c675c: /* original 55f1, guest PC 0x0c0c675c */
if(!s->budget--) { s->failed_pc=0x0c0c675cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c675e;
P_0c0c675e: /* original b007, guest PC 0x0c0c675e */
if(!s->budget--) { s->failed_pc=0x0c0c675eu; return 0; }
target=code_base|0x0c0c6770u; r[16]=code_base|0x0c0c6762u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6762u) { target=s->pc; goto dispatch; }
goto P_0c0c6762;
P_0c0c6760: /* original 64f2, guest PC 0x0c0c6760 */
if(!s->budget--) { s->failed_pc=0x0c0c6760u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6762;
P_0c0c6762: /* original 65f2, guest PC 0x0c0c6762 */
if(!s->budget--) { s->failed_pc=0x0c0c6762u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c6764;
P_0c0c6764: /* original b004, guest PC 0x0c0c6764 */
if(!s->budget--) { s->failed_pc=0x0c0c6764u; return 0; }
target=code_base|0x0c0c6770u; r[16]=code_base|0x0c0c6768u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6768u) { target=s->pc; goto dispatch; }
goto P_0c0c6768;
P_0c0c6766: /* original 54f1, guest PC 0x0c0c6766 */
if(!s->budget--) { s->failed_pc=0x0c0c6766u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6768;
P_0c0c6768: /* original 7f08, guest PC 0x0c0c6768 */
if(!s->budget--) { s->failed_pc=0x0c0c6768u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c676a;
P_0c0c676a: /* original 4f26, guest PC 0x0c0c676a */
if(!s->budget--) { s->failed_pc=0x0c0c676au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c676c;
P_0c0c676c: /* original 000b, guest PC 0x0c0c676c */
if(!s->budget--) { s->failed_pc=0x0c0c676cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c676e: /* original 0009, guest PC 0x0c0c676e */
if(!s->budget--) { s->failed_pc=0x0c0c676eu; return 0; }
goto P_0c0c6770;
P_0c0c6770: /* original 2fe6, guest PC 0x0c0c6770 */
if(!s->budget--) { s->failed_pc=0x0c0c6770u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6772;
P_0c0c6772: /* original e11c, guest PC 0x0c0c6772 */
if(!s->budget--) { s->failed_pc=0x0c0c6772u; return 0; }
r[1]=0x0000001cu;
goto P_0c0c6774;
P_0c0c6774: /* original 2fd6, guest PC 0x0c0c6774 */
if(!s->budget--) { s->failed_pc=0x0c0c6774u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6776;
P_0c0c6776: /* original 6e43, guest PC 0x0c0c6776 */
if(!s->budget--) { s->failed_pc=0x0c0c6776u; return 0; }
r[14]=r[4];
goto P_0c0c6778;
P_0c0c6778: /* original 2fc6, guest PC 0x0c0c6778 */
if(!s->budget--) { s->failed_pc=0x0c0c6778u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c677a;
P_0c0c677a: /* original e40f, guest PC 0x0c0c677a */
if(!s->budget--) { s->failed_pc=0x0c0c677au; return 0; }
r[4]=0x0000000fu;
goto P_0c0c677c;
P_0c0c677c: /* original 2fb6, guest PC 0x0c0c677c */
if(!s->budget--) { s->failed_pc=0x0c0c677cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c677e;
P_0c0c677e: /* original 2fa6, guest PC 0x0c0c677e */
if(!s->budget--) { s->failed_pc=0x0c0c677eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6780;
P_0c0c6780: /* original ea04, guest PC 0x0c0c6780 */
if(!s->budget--) { s->failed_pc=0x0c0c6780u; return 0; }
r[10]=0x00000004u;
goto P_0c0c6782;
P_0c0c6782: /* original 2f96, guest PC 0x0c0c6782 */
if(!s->budget--) { s->failed_pc=0x0c0c6782u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6784;
P_0c0c6784: /* original 2f86, guest PC 0x0c0c6784 */
if(!s->budget--) { s->failed_pc=0x0c0c6784u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6786;
P_0c0c6786: /* original fffb, guest PC 0x0c0c6786 */
if(!s->budget--) { s->failed_pc=0x0c0c6786u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c6788;
P_0c0c6788: /* original ffeb, guest PC 0x0c0c6788 */
if(!s->budget--) { s->failed_pc=0x0c0c6788u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c678a;
P_0c0c678a: /* original ffdb, guest PC 0x0c0c678a */
if(!s->budget--) { s->failed_pc=0x0c0c678au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c678c;
P_0c0c678c: /* original ffcb, guest PC 0x0c0c678c */
if(!s->budget--) { s->failed_pc=0x0c0c678cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c678e;
P_0c0c678e: /* original 4f22, guest PC 0x0c0c678e */
if(!s->budget--) { s->failed_pc=0x0c0c678eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6790;
P_0c0c6790: /* original d817, guest PC 0x0c0c6790 */
if(!s->budget--) { s->failed_pc=0x0c0c6790u; return 0; }
r[8]=read(ram,0x0c0c67f0u,4);
goto P_0c0c6792;
P_0c0c6792: /* original 7fc0, guest PC 0x0c0c6792 */
if(!s->budget--) { s->failed_pc=0x0c0c6792u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0c6794;
P_0c0c6794: /* original 1f5a, guest PC 0x0c0c6794 */
if(!s->budget--) { s->failed_pc=0x0c0c6794u; return 0; }
write(ram,r[15]+40,r[5],4);
goto P_0c0c6796;
P_0c0c6796: /* original d312, guest PC 0x0c0c6796 */
if(!s->budget--) { s->failed_pc=0x0c0c6796u; return 0; }
r[3]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6798;
P_0c0c6798: /* original 6033, guest PC 0x0c0c6798 */
if(!s->budget--) { s->failed_pc=0x0c0c6798u; return 0; }
r[0]=r[3];
goto P_0c0c679a;
P_0c0c679a: /* original 1f32, guest PC 0x0c0c679a */
if(!s->budget--) { s->failed_pc=0x0c0c679au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c679c;
P_0c0c679c: /* original 001c, guest PC 0x0c0c679c */
if(!s->budget--) { s->failed_pc=0x0c0c679cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c679e;
P_0c0c679e: /* original 931d, guest PC 0x0c0c679e */
if(!s->budget--) { s->failed_pc=0x0c0c679eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67dcu,2);
goto P_0c0c67a0;
P_0c0c67a0: /* original 600c, guest PC 0x0c0c67a0 */
if(!s->budget--) { s->failed_pc=0x0c0c67a0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c67a2;
P_0c0c67a2: /* original 2409, guest PC 0x0c0c67a2 */
if(!s->budget--) { s->failed_pc=0x0c0c67a2u; return 0; }
r[4]&=r[0];
goto P_0c0c67a4;
P_0c0c67a4: /* original 9019, guest PC 0x0c0c67a4 */
if(!s->budget--) { s->failed_pc=0x0c0c67a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67dau,2);
goto P_0c0c67a6;
P_0c0c67a6: /* original 33ec, guest PC 0x0c0c67a6 */
if(!s->budget--) { s->failed_pc=0x0c0c67a6u; return 0; }
r[3]+=r[14];
goto P_0c0c67a8;
P_0c0c67a8: /* original 09ee, guest PC 0x0c0c67a8 */
if(!s->budget--) { s->failed_pc=0x0c0c67a8u; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c0c67aa;
P_0c0c67aa: /* original 6043, guest PC 0x0c0c67aa */
if(!s->budget--) { s->failed_pc=0x0c0c67aau; return 0; }
r[0]=r[4];
goto P_0c0c67ac;
P_0c0c67ac: /* original 1f31, guest PC 0x0c0c67ac */
if(!s->budget--) { s->failed_pc=0x0c0c67acu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c67ae;
P_0c0c67ae: /* original dc11, guest PC 0x0c0c67ae */
if(!s->budget--) { s->failed_pc=0x0c0c67aeu; return 0; }
r[12]=read(ram,0x0c0c67f4u,4);
goto P_0c0c67b0;
P_0c0c67b0: /* original 8802, guest PC 0x0c0c67b0 */
if(!s->budget--) { s->failed_pc=0x0c0c67b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c67b2;
P_0c0c67b2: /* original 8f02, guest PC 0x0c0c67b2 */
if(!s->budget--) { s->failed_pc=0x0c0c67b2u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c0c67ba; }
goto P_0c0c67b6;
P_0c0c67b4: /* original eb00, guest PC 0x0c0c67b4 */
if(!s->budget--) { s->failed_pc=0x0c0c67b4u; return 0; }
r[11]=0x00000000u;
goto P_0c0c67b6;
P_0c0c67b6: /* original a002, guest PC 0x0c0c67b6 */
if(!s->budget--) { s->failed_pc=0x0c0c67b6u; return 0; }
write(ram,r[12],r[11],4);
goto P_0c0c67be;
P_0c0c67b8: /* original 2cb2, guest PC 0x0c0c67b8 */
if(!s->budget--) { s->failed_pc=0x0c0c67b8u; return 0; }
write(ram,r[12],r[11],4);
goto P_0c0c67ba;
P_0c0c67ba: /* original e201, guest PC 0x0c0c67ba */
if(!s->budget--) { s->failed_pc=0x0c0c67bau; return 0; }
r[2]=0x00000001u;
goto P_0c0c67bc;
P_0c0c67bc: /* original 2c22, guest PC 0x0c0c67bc */
if(!s->budget--) { s->failed_pc=0x0c0c67bcu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0c67be;
P_0c0c67be: /* original 6043, guest PC 0x0c0c67be */
if(!s->budget--) { s->failed_pc=0x0c0c67beu; return 0; }
r[0]=r[4];
goto P_0c0c67c0;
P_0c0c67c0: /* original 8807, guest PC 0x0c0c67c0 */
if(!s->budget--) { s->failed_pc=0x0c0c67c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c67c2;
P_0c0c67c2: /* original 8f02, guest PC 0x0c0c67c2 */
if(!s->budget--) { s->failed_pc=0x0c0c67c2u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c0c67ca; }
goto P_0c0c67c6;
P_0c0c67c4: /* original 6043, guest PC 0x0c0c67c4 */
if(!s->budget--) { s->failed_pc=0x0c0c67c4u; return 0; }
r[0]=r[4];
goto P_0c0c67c6;
P_0c0c67c6: /* original a002, guest PC 0x0c0c67c6 */
if(!s->budget--) { s->failed_pc=0x0c0c67c6u; return 0; }
write(ram,r[12]+28,r[11],4);
goto P_0c0c67ce;
P_0c0c67c8: /* original 1cb7, guest PC 0x0c0c67c8 */
if(!s->budget--) { s->failed_pc=0x0c0c67c8u; return 0; }
write(ram,r[12]+28,r[11],4);
goto P_0c0c67ca;
P_0c0c67ca: /* original e301, guest PC 0x0c0c67ca */
if(!s->budget--) { s->failed_pc=0x0c0c67cau; return 0; }
r[3]=0x00000001u;
goto P_0c0c67cc;
P_0c0c67cc: /* original 1c37, guest PC 0x0c0c67cc */
if(!s->budget--) { s->failed_pc=0x0c0c67ccu; return 0; }
write(ram,r[12]+28,r[3],4);
goto P_0c0c67ce;
P_0c0c67ce: /* original 880d, guest PC 0x0c0c67ce */
if(!s->budget--) { s->failed_pc=0x0c0c67ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c67d0;
P_0c0c67d0: /* original 8b12, guest PC 0x0c0c67d0 */
if(!s->budget--) { s->failed_pc=0x0c0c67d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c67f8; }
goto P_0c0c67d2;
P_0c0c67d2: /* original a013, guest PC 0x0c0c67d2 */
if(!s->budget--) { s->failed_pc=0x0c0c67d2u; return 0; }
write(ram,r[12]+24,r[11],4);
goto P_0c0c67fc;
P_0c0c67d4: /* original 1cb6, guest PC 0x0c0c67d4 */
if(!s->budget--) { s->failed_pc=0x0c0c67d4u; return 0; }
write(ram,r[12]+24,r[11],4);
if(!vf3_matrix_family(0x0c0c67d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c67d6u; return 0; } return 1;
P_0c0c67f8: /* original e201, guest PC 0x0c0c67f8 */
if(!s->budget--) { s->failed_pc=0x0c0c67f8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c67fa;
P_0c0c67fa: /* original 1c26, guest PC 0x0c0c67fa */
if(!s->budget--) { s->failed_pc=0x0c0c67fau; return 0; }
write(ram,r[12]+24,r[2],4);
goto P_0c0c67fc;
P_0c0c67fc: /* original 51c7, guest PC 0x0c0c67fc */
if(!s->budget--) { s->failed_pc=0x0c0c67fcu; return 0; }
r[1]=read(ram,r[12]+28,4);
goto P_0c0c67fe;
P_0c0c67fe: /* original ed1c, guest PC 0x0c0c67fe */
if(!s->budget--) { s->failed_pc=0x0c0c67feu; return 0; }
r[13]=0x0000001cu;
goto P_0c0c6800;
P_0c0c6800: /* original 63c2, guest PC 0x0c0c6800 */
if(!s->budget--) { s->failed_pc=0x0c0c6800u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6802;
P_0c0c6802: /* original 213b, guest PC 0x0c0c6802 */
if(!s->budget--) { s->failed_pc=0x0c0c6802u; return 0; }
r[1]|=r[3];
goto P_0c0c6804;
P_0c0c6804: /* original 1c17, guest PC 0x0c0c6804 */
if(!s->budget--) { s->failed_pc=0x0c0c6804u; return 0; }
write(ram,r[12]+28,r[1],4);
goto P_0c0c6806;
P_0c0c6806: /* original 2fd2, guest PC 0x0c0c6806 */
if(!s->budget--) { s->failed_pc=0x0c0c6806u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c6808;
P_0c0c6808: /* original e008, guest PC 0x0c0c6808 */
if(!s->budget--) { s->failed_pc=0x0c0c6808u; return 0; }
r[0]=0x00000008u;
goto P_0c0c680a;
P_0c0c680a: /* original f498, guest PC 0x0c0c680a */
if(!s->budget--) { s->failed_pc=0x0c0c680au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c0c680c;
P_0c0c680c: /* original f396, guest PC 0x0c0c680c */
if(!s->budget--) { s->failed_pc=0x0c0c680cu; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c0c680e;
P_0c0c680e: /* original e02c, guest PC 0x0c0c680e */
if(!s->budget--) { s->failed_pc=0x0c0c680eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c6810;
P_0c0c6810: /* original 790c, guest PC 0x0c0c6810 */
if(!s->budget--) { s->failed_pc=0x0c0c6810u; return 0; }
r[9]+=0x0000000cu;
goto P_0c0c6812;
P_0c0c6812: /* original ff37, guest PC 0x0c0c6812 */
if(!s->budget--) { s->failed_pc=0x0c0c6812u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6814;
P_0c0c6814: /* original d329, guest PC 0x0c0c6814 */
if(!s->budget--) { s->failed_pc=0x0c0c6814u; return 0; }
r[3]=read(ram,0x0c0c68bcu,4);
goto P_0c0c6816;
P_0c0c6816: /* original f53c, guest PC 0x0c0c6816 */
if(!s->budget--) { s->failed_pc=0x0c0c6816u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c6818;
P_0c0c6818: /* original 430b, guest PC 0x0c0c6818 */
if(!s->budget--) { s->failed_pc=0x0c0c6818u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c681cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c681cu) { target=s->pc; goto dispatch; }
goto P_0c0c681c;
P_0c0c681a: /* original f54d, guest PC 0x0c0c681a */
if(!s->budget--) { s->failed_pc=0x0c0c681au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c681c;
P_0c0c681c: /* original 52f1, guest PC 0x0c0c681c */
if(!s->budget--) { s->failed_pc=0x0c0c681cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c681e;
P_0c0c681e: /* original f40c, guest PC 0x0c0c681e */
if(!s->budget--) { s->failed_pc=0x0c0c681eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c6820;
P_0c0c6820: /* original f24a, guest PC 0x0c0c6820 */
if(!s->budget--) { s->failed_pc=0x0c0c6820u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c0c6822;
P_0c0c6822: /* original 53f1, guest PC 0x0c0c6822 */
if(!s->budget--) { s->failed_pc=0x0c0c6822u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c6824;
P_0c0c6824: /* original 7304, guest PC 0x0c0c6824 */
if(!s->budget--) { s->failed_pc=0x0c0c6824u; return 0; }
r[3]+=0x00000004u;
goto P_0c0c6826;
P_0c0c6826: /* original 1f31, guest PC 0x0c0c6826 */
if(!s->budget--) { s->failed_pc=0x0c0c6826u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c6828;
P_0c0c6828: /* original 62f2, guest PC 0x0c0c6828 */
if(!s->budget--) { s->failed_pc=0x0c0c6828u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c682a;
P_0c0c682a: /* original 72ff, guest PC 0x0c0c682a */
if(!s->budget--) { s->failed_pc=0x0c0c682au; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c682c;
P_0c0c682c: /* original 2228, guest PC 0x0c0c682c */
if(!s->budget--) { s->failed_pc=0x0c0c682cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c682e;
P_0c0c682e: /* original 8feb, guest PC 0x0c0c682e */
if(!s->budget--) { s->failed_pc=0x0c0c682eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c0c6808; }
goto P_0c0c6832;
P_0c0c6830: /* original 2f22, guest PC 0x0c0c6830 */
if(!s->budget--) { s->failed_pc=0x0c0c6830u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c6832;
P_0c0c6832: /* original e048, guest PC 0x0c0c6832 */
if(!s->budget--) { s->failed_pc=0x0c0c6832u; return 0; }
r[0]=0x00000048u;
goto P_0c0c6834;
P_0c0c6834: /* original 933d, guest PC 0x0c0c6834 */
if(!s->budget--) { s->failed_pc=0x0c0c6834u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68b2u,2);
goto P_0c0c6836;
P_0c0c6836: /* original 04ee, guest PC 0x0c0c6836 */
if(!s->budget--) { s->failed_pc=0x0c0c6836u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c6838;
P_0c0c6838: /* original 2348, guest PC 0x0c0c6838 */
if(!s->budget--) { s->failed_pc=0x0c0c6838u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c683a;
P_0c0c683a: /* original 891b, guest PC 0x0c0c683a */
if(!s->budget--) { s->failed_pc=0x0c0c683au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6874; }
goto P_0c0c683c;
P_0c0c683c: /* original d220, guest PC 0x0c0c683c */
if(!s->budget--) { s->failed_pc=0x0c0c683cu; return 0; }
r[2]=read(ram,0x0c0c68c0u,4);
goto P_0c0c683e;
P_0c0c683e: /* original 2428, guest PC 0x0c0c683e */
if(!s->budget--) { s->failed_pc=0x0c0c683eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0c6840;
P_0c0c6840: /* original 8b18, guest PC 0x0c0c6840 */
if(!s->budget--) { s->failed_pc=0x0c0c6840u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6874; }
goto P_0c0c6842;
P_0c0c6842: /* original 9037, guest PC 0x0c0c6842 */
if(!s->budget--) { s->failed_pc=0x0c0c6842u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68b4u,2);
goto P_0c0c6844;
P_0c0c6844: /* original 53fa, guest PC 0x0c0c6844 */
if(!s->budget--) { s->failed_pc=0x0c0c6844u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c0c6846;
P_0c0c6846: /* original 9537, guest PC 0x0c0c6846 */
if(!s->budget--) { s->failed_pc=0x0c0c6846u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68b8u,2);
goto P_0c0c6848;
P_0c0c6848: /* original f536, guest PC 0x0c0c6848 */
if(!s->budget--) { s->failed_pc=0x0c0c6848u; return 0; }
vf3_matrix_load(s,ram,5,r[3]+r[0]);
goto P_0c0c684a;
P_0c0c684a: /* original 9034, guest PC 0x0c0c684a */
if(!s->budget--) { s->failed_pc=0x0c0c684au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68b6u,2);
goto P_0c0c684c;
P_0c0c684c: /* original 35ec, guest PC 0x0c0c684c */
if(!s->budget--) { s->failed_pc=0x0c0c684cu; return 0; }
r[5]+=r[14];
goto P_0c0c684e;
P_0c0c684e: /* original 04ec, guest PC 0x0c0c684e */
if(!s->budget--) { s->failed_pc=0x0c0c684eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c6850;
P_0c0c6850: /* original d01c, guest PC 0x0c0c6850 */
if(!s->budget--) { s->failed_pc=0x0c0c6850u; return 0; }
r[0]=read(ram,0x0c0c68c4u,4);
goto P_0c0c6852;
P_0c0c6852: /* original 664c, guest PC 0x0c0c6852 */
if(!s->budget--) { s->failed_pc=0x0c0c6852u; return 0; }
r[6]=r[4]&255u;
goto P_0c0c6854;
P_0c0c6854: /* original 64d3, guest PC 0x0c0c6854 */
if(!s->budget--) { s->failed_pc=0x0c0c6854u; return 0; }
r[4]=r[13];
goto P_0c0c6856;
P_0c0c6856: /* original 4608, guest PC 0x0c0c6856 */
if(!s->budget--) { s->failed_pc=0x0c0c6856u; return 0; }
r[6]<<=2;
goto P_0c0c6858;
P_0c0c6858: /* original 066e, guest PC 0x0c0c6858 */
if(!s->budget--) { s->failed_pc=0x0c0c6858u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c0c685a;
P_0c0c685a: /* original 67d3, guest PC 0x0c0c685a */
if(!s->budget--) { s->failed_pc=0x0c0c685au; return 0; }
r[7]=r[13];
goto P_0c0c685c;
P_0c0c685c: /* original d31a, guest PC 0x0c0c685c */
if(!s->budget--) { s->failed_pc=0x0c0c685cu; return 0; }
r[3]=read(ram,0x0c0c68c8u,4);
goto P_0c0c685e;
P_0c0c685e: /* original 3748, guest PC 0x0c0c685e */
if(!s->budget--) { s->failed_pc=0x0c0c685eu; return 0; }
r[7]-=r[4];
goto P_0c0c6860;
P_0c0c6860: /* original 677b, guest PC 0x0c0c6860 */
if(!s->budget--) { s->failed_pc=0x0c0c6860u; return 0; }
r[7]=0u-r[7];
goto P_0c0c6862;
P_0c0c6862: /* original 437d, guest PC 0x0c0c6862 */
if(!s->budget--) { s->failed_pc=0x0c0c6862u; return 0; }
r[3]=(r[7]&0x80000000u)?((r[7]&31u)?r[3]>>((-r[7])&31u):0):r[3]<<(r[7]&31u);
goto P_0c0c6864;
P_0c0c6864: /* original 2368, guest PC 0x0c0c6864 */
if(!s->budget--) { s->failed_pc=0x0c0c6864u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c6866;
P_0c0c6866: /* original 8902, guest PC 0x0c0c6866 */
if(!s->budget--) { s->failed_pc=0x0c0c6866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c686e; }
goto P_0c0c6868;
P_0c0c6868: /* original f458, guest PC 0x0c0c6868 */
if(!s->budget--) { s->failed_pc=0x0c0c6868u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c0c686a;
P_0c0c686a: /* original f450, guest PC 0x0c0c686a */
if(!s->budget--) { s->failed_pc=0x0c0c686au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c0c686c;
P_0c0c686c: /* original f54a, guest PC 0x0c0c686c */
if(!s->budget--) { s->failed_pc=0x0c0c686cu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c0c686e;
P_0c0c686e: /* original 4410, guest PC 0x0c0c686e */
if(!s->budget--) { s->failed_pc=0x0c0c686eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0c6870;
P_0c0c6870: /* original 8ff3, guest PC 0x0c0c6870 */
if(!s->budget--) { s->failed_pc=0x0c0c6870u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0c685a; }
goto P_0c0c6874;
P_0c0c6872: /* original 7504, guest PC 0x0c0c6872 */
if(!s->budget--) { s->failed_pc=0x0c0c6872u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c6874;
P_0c0c6874: /* original 9420, guest PC 0x0c0c6874 */
if(!s->budget--) { s->failed_pc=0x0c0c6874u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68b8u,2);
goto P_0c0c6876;
P_0c0c6876: /* original e04c, guest PC 0x0c0c6876 */
if(!s->budget--) { s->failed_pc=0x0c0c6876u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c6878;
P_0c0c6878: /* original f38d, guest PC 0x0c0c6878 */
if(!s->budget--) { s->failed_pc=0x0c0c6878u; return 0; }
fr[3]=0;
goto P_0c0c687a;
P_0c0c687a: /* original 34ec, guest PC 0x0c0c687a */
if(!s->budget--) { s->failed_pc=0x0c0c687au; return 0; }
r[4]+=r[14];
goto P_0c0c687c;
P_0c0c687c: /* original ff46, guest PC 0x0c0c687c */
if(!s->budget--) { s->failed_pc=0x0c0c687cu; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0c687e;
P_0c0c687e: /* original 7468, guest PC 0x0c0c687e */
if(!s->budget--) { s->failed_pc=0x0c0c687eu; return 0; }
r[4]+=0x00000068u;
goto P_0c0c6880;
P_0c0c6880: /* original fe48, guest PC 0x0c0c6880 */
if(!s->budget--) { s->failed_pc=0x0c0c6880u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
goto P_0c0c6882;
P_0c0c6882: /* original fcfc, guest PC 0x0c0c6882 */
if(!s->budget--) { s->failed_pc=0x0c0c6882u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0c6884;
P_0c0c6884: /* original fce1, guest PC 0x0c0c6884 */
if(!s->budget--) { s->failed_pc=0x0c0c6884u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'-');
goto P_0c0c6886;
P_0c0c6886: /* original f3c5, guest PC 0x0c0c6886 */
if(!s->budget--) { s->failed_pc=0x0c0c6886u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[12]))!=0);
goto P_0c0c6888;
P_0c0c6888: /* original 8d02, guest PC 0x0c0c6888 */
if(!s->budget--) { s->failed_pc=0x0c0c6888u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(cond) { goto P_0c0c6890; }
goto P_0c0c688c;
P_0c0c688a: /* original f38d, guest PC 0x0c0c688a */
if(!s->budget--) { s->failed_pc=0x0c0c688au; return 0; }
fr[3]=0;
goto P_0c0c688c;
P_0c0c688c: /* original a001, guest PC 0x0c0c688c */
if(!s->budget--) { s->failed_pc=0x0c0c688cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c6892;
P_0c0c688e: /* original f4ec, guest PC 0x0c0c688e */
if(!s->budget--) { s->failed_pc=0x0c0c688eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c6890;
P_0c0c6890: /* original f4fc, guest PC 0x0c0c6890 */
if(!s->budget--) { s->failed_pc=0x0c0c6890u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c6892;
P_0c0c6892: /* original f3c5, guest PC 0x0c0c6892 */
if(!s->budget--) { s->failed_pc=0x0c0c6892u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[12]))!=0);
goto P_0c0c6894;
P_0c0c6894: /* original 8901, guest PC 0x0c0c6894 */
if(!s->budget--) { s->failed_pc=0x0c0c6894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c689a; }
goto P_0c0c6896;
P_0c0c6896: /* original a001, guest PC 0x0c0c6896 */
if(!s->budget--) { s->failed_pc=0x0c0c6896u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c689c;
P_0c0c6898: /* original f5fc, guest PC 0x0c0c6898 */
if(!s->budget--) { s->failed_pc=0x0c0c6898u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c689a;
P_0c0c689a: /* original f5ec, guest PC 0x0c0c689a */
if(!s->budget--) { s->failed_pc=0x0c0c689au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c689c;
P_0c0c689c: /* original 900d, guest PC 0x0c0c689c */
if(!s->budget--) { s->failed_pc=0x0c0c689cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c68bau,2);
goto P_0c0c689e;
P_0c0c689e: /* original fe47, guest PC 0x0c0c689e */
if(!s->budget--) { s->failed_pc=0x0c0c689eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c68a0;
P_0c0c68a0: /* original 7004, guest PC 0x0c0c68a0 */
if(!s->budget--) { s->failed_pc=0x0c0c68a0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c68a2;
P_0c0c68a2: /* original fe57, guest PC 0x0c0c68a2 */
if(!s->budget--) { s->failed_pc=0x0c0c68a2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c68a4;
P_0c0c68a4: /* original 64e2, guest PC 0x0c0c68a4 */
if(!s->budget--) { s->failed_pc=0x0c0c68a4u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c68a6;
P_0c0c68a6: /* original d306, guest PC 0x0c0c68a6 */
if(!s->budget--) { s->failed_pc=0x0c0c68a6u; return 0; }
r[3]=read(ram,0x0c0c68c0u,4);
goto P_0c0c68a8;
P_0c0c68a8: /* original 2438, guest PC 0x0c0c68a8 */
if(!s->budget--) { s->failed_pc=0x0c0c68a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c68aa;
P_0c0c68aa: /* original 8f0f, guest PC 0x0c0c68aa */
if(!s->budget--) { s->failed_pc=0x0c0c68aau; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(!cond) { goto P_0c0c68cc; }
goto P_0c0c68ae;
P_0c0c68ac: /* original 6db3, guest PC 0x0c0c68ac */
if(!s->budget--) { s->failed_pc=0x0c0c68acu; return 0; }
r[13]=r[11];
goto P_0c0c68ae;
P_0c0c68ae: /* original a00f, guest PC 0x0c0c68ae */
if(!s->budget--) { s->failed_pc=0x0c0c68aeu; return 0; }
write(ram,r[12]+16,r[11],4);
goto P_0c0c68d0;
P_0c0c68b0: /* original 1cb4, guest PC 0x0c0c68b0 */
if(!s->budget--) { s->failed_pc=0x0c0c68b0u; return 0; }
write(ram,r[12]+16,r[11],4);
if(!vf3_matrix_family(0x0c0c68b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c68b2u; return 0; } return 1;
P_0c0c68cc: /* original e201, guest PC 0x0c0c68cc */
if(!s->budget--) { s->failed_pc=0x0c0c68ccu; return 0; }
r[2]=0x00000001u;
goto P_0c0c68ce;
P_0c0c68ce: /* original 1c24, guest PC 0x0c0c68ce */
if(!s->budget--) { s->failed_pc=0x0c0c68ceu; return 0; }
write(ram,r[12]+16,r[2],4);
goto P_0c0c68d0;
P_0c0c68d0: /* original e063, guest PC 0x0c0c68d0 */
if(!s->budget--) { s->failed_pc=0x0c0c68d0u; return 0; }
r[0]=0x00000063u;
goto P_0c0c68d2;
P_0c0c68d2: /* original 04ec, guest PC 0x0c0c68d2 */
if(!s->budget--) { s->failed_pc=0x0c0c68d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c68d4;
P_0c0c68d4: /* original 9060, guest PC 0x0c0c68d4 */
if(!s->budget--) { s->failed_pc=0x0c0c68d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6998u,2);
goto P_0c0c68d6;
P_0c0c68d6: /* original 644c, guest PC 0x0c0c68d6 */
if(!s->budget--) { s->failed_pc=0x0c0c68d6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c68d8;
P_0c0c68d8: /* original 0bee, guest PC 0x0c0c68d8 */
if(!s->budget--) { s->failed_pc=0x0c0c68d8u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0c68da;
P_0c0c68da: /* original e048, guest PC 0x0c0c68da */
if(!s->budget--) { s->failed_pc=0x0c0c68dau; return 0; }
r[0]=0x00000048u;
goto P_0c0c68dc;
P_0c0c68dc: /* original 09ee, guest PC 0x0c0c68dc */
if(!s->budget--) { s->failed_pc=0x0c0c68dcu; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c0c68de;
P_0c0c68de: /* original 74ff, guest PC 0x0c0c68de */
if(!s->budget--) { s->failed_pc=0x0c0c68deu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c68e0;
P_0c0c68e0: /* original 905b, guest PC 0x0c0c68e0 */
if(!s->budget--) { s->failed_pc=0x0c0c68e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c699au,2);
goto P_0c0c68e2;
P_0c0c68e2: /* original 03ee, guest PC 0x0c0c68e2 */
if(!s->budget--) { s->failed_pc=0x0c0c68e2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c68e4;
P_0c0c68e4: /* original 1f31, guest PC 0x0c0c68e4 */
if(!s->budget--) { s->failed_pc=0x0c0c68e4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c68e6;
P_0c0c68e6: /* original 9059, guest PC 0x0c0c68e6 */
if(!s->budget--) { s->failed_pc=0x0c0c68e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c699cu,2);
goto P_0c0c68e8;
P_0c0c68e8: /* original 02ec, guest PC 0x0c0c68e8 */
if(!s->budget--) { s->failed_pc=0x0c0c68e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c68ea;
P_0c0c68ea: /* original 622c, guest PC 0x0c0c68ea */
if(!s->budget--) { s->failed_pc=0x0c0c68eau; return 0; }
r[2]=r[2]&255u;
goto P_0c0c68ec;
P_0c0c68ec: /* original 2f22, guest PC 0x0c0c68ec */
if(!s->budget--) { s->failed_pc=0x0c0c68ecu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c68ee;
P_0c0c68ee: /* original 1c43, guest PC 0x0c0c68ee */
if(!s->budget--) { s->failed_pc=0x0c0c68eeu; return 0; }
write(ram,r[12]+12,r[4],4);
goto P_0c0c68f0;
P_0c0c68f0: /* original 53f2, guest PC 0x0c0c68f0 */
if(!s->budget--) { s->failed_pc=0x0c0c68f0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c68f2;
P_0c0c68f2: /* original d22d, guest PC 0x0c0c68f2 */
if(!s->budget--) { s->failed_pc=0x0c0c68f2u; return 0; }
r[2]=read(ram,0x0c0c69a8u,4);
goto P_0c0c68f4;
P_0c0c68f4: /* original 6132, guest PC 0x0c0c68f4 */
if(!s->budget--) { s->failed_pc=0x0c0c68f4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0c68f6;
P_0c0c68f6: /* original 2128, guest PC 0x0c0c68f6 */
if(!s->budget--) { s->failed_pc=0x0c0c68f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0c68f8;
P_0c0c68f8: /* original 8b04, guest PC 0x0c0c68f8 */
if(!s->budget--) { s->failed_pc=0x0c0c68f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6904; }
goto P_0c0c68fa;
P_0c0c68fa: /* original 53f2, guest PC 0x0c0c68fa */
if(!s->budget--) { s->failed_pc=0x0c0c68fau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c68fc;
P_0c0c68fc: /* original d22b, guest PC 0x0c0c68fc */
if(!s->budget--) { s->failed_pc=0x0c0c68fcu; return 0; }
r[2]=read(ram,0x0c0c69acu,4);
goto P_0c0c68fe;
P_0c0c68fe: /* original 5131, guest PC 0x0c0c68fe */
if(!s->budget--) { s->failed_pc=0x0c0c68feu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c0c6900;
P_0c0c6900: /* original 2128, guest PC 0x0c0c6900 */
if(!s->budget--) { s->failed_pc=0x0c0c6900u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0c6902;
P_0c0c6902: /* original 8918, guest PC 0x0c0c6902 */
if(!s->budget--) { s->failed_pc=0x0c0c6902u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6936; }
goto P_0c0c6904;
P_0c0c6904: /* original 904b, guest PC 0x0c0c6904 */
if(!s->budget--) { s->failed_pc=0x0c0c6904u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c699eu,2);
goto P_0c0c6906;
P_0c0c6906: /* original 04ee, guest PC 0x0c0c6906 */
if(!s->budget--) { s->failed_pc=0x0c0c6906u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c6908;
P_0c0c6908: /* original 24a8, guest PC 0x0c0c6908 */
if(!s->budget--) { s->failed_pc=0x0c0c6908u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0c690a;
P_0c0c690a: /* original 8b14, guest PC 0x0c0c690a */
if(!s->budget--) { s->failed_pc=0x0c0c690au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6936; }
goto P_0c0c690c;
P_0c0c690c: /* original 50f2, guest PC 0x0c0c690c */
if(!s->budget--) { s->failed_pc=0x0c0c690cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0c690e;
P_0c0c690e: /* original e11c, guest PC 0x0c0c690e */
if(!s->budget--) { s->failed_pc=0x0c0c690eu; return 0; }
r[1]=0x0000001cu;
goto P_0c0c6910;
P_0c0c6910: /* original e40f, guest PC 0x0c0c6910 */
if(!s->budget--) { s->failed_pc=0x0c0c6910u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c6912;
P_0c0c6912: /* original 001c, guest PC 0x0c0c6912 */
if(!s->budget--) { s->failed_pc=0x0c0c6912u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c6914;
P_0c0c6914: /* original 600c, guest PC 0x0c0c6914 */
if(!s->budget--) { s->failed_pc=0x0c0c6914u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c6916;
P_0c0c6916: /* original 2409, guest PC 0x0c0c6916 */
if(!s->budget--) { s->failed_pc=0x0c0c6916u; return 0; }
r[4]&=r[0];
goto P_0c0c6918;
P_0c0c6918: /* original 6043, guest PC 0x0c0c6918 */
if(!s->budget--) { s->failed_pc=0x0c0c6918u; return 0; }
r[0]=r[4];
goto P_0c0c691a;
P_0c0c691a: /* original 880c, guest PC 0x0c0c691a */
if(!s->budget--) { s->failed_pc=0x0c0c691au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0c691c;
P_0c0c691c: /* original 8901, guest PC 0x0c0c691c */
if(!s->budget--) { s->failed_pc=0x0c0c691cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6922; }
goto P_0c0c691e;
P_0c0c691e: /* original a29e, guest PC 0x0c0c691e */
if(!s->budget--) { s->failed_pc=0x0c0c691eu; return 0; }
goto P_0c0c6e5e;
P_0c0c6920: /* original 0009, guest PC 0x0c0c6920 */
if(!s->budget--) { s->failed_pc=0x0c0c6920u; return 0; }
goto P_0c0c6922;
P_0c0c6922: /* original 6043, guest PC 0x0c0c6922 */
if(!s->budget--) { s->failed_pc=0x0c0c6922u; return 0; }
r[0]=r[4];
goto P_0c0c6924;
P_0c0c6924: /* original 8805, guest PC 0x0c0c6924 */
if(!s->budget--) { s->failed_pc=0x0c0c6924u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c6926;
P_0c0c6926: /* original 8901, guest PC 0x0c0c6926 */
if(!s->budget--) { s->failed_pc=0x0c0c6926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c692c; }
goto P_0c0c6928;
P_0c0c6928: /* original a299, guest PC 0x0c0c6928 */
if(!s->budget--) { s->failed_pc=0x0c0c6928u; return 0; }
goto P_0c0c6e5e;
P_0c0c692a: /* original 0009, guest PC 0x0c0c692a */
if(!s->budget--) { s->failed_pc=0x0c0c692au; return 0; }
goto P_0c0c692c;
P_0c0c692c: /* original 6043, guest PC 0x0c0c692c */
if(!s->budget--) { s->failed_pc=0x0c0c692cu; return 0; }
r[0]=r[4];
goto P_0c0c692e;
P_0c0c692e: /* original 880f, guest PC 0x0c0c692e */
if(!s->budget--) { s->failed_pc=0x0c0c692eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0c6930;
P_0c0c6930: /* original 8901, guest PC 0x0c0c6930 */
if(!s->budget--) { s->failed_pc=0x0c0c6930u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6936; }
goto P_0c0c6932;
P_0c0c6932: /* original a294, guest PC 0x0c0c6932 */
if(!s->budget--) { s->failed_pc=0x0c0c6932u; return 0; }
goto P_0c0c6e5e;
P_0c0c6934: /* original 0009, guest PC 0x0c0c6934 */
if(!s->budget--) { s->failed_pc=0x0c0c6934u; return 0; }
goto P_0c0c6936;
P_0c0c6936: /* original 9333, guest PC 0x0c0c6936 */
if(!s->budget--) { s->failed_pc=0x0c0c6936u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c69a0u,2);
goto P_0c0c6938;
P_0c0c6938: /* original 2398, guest PC 0x0c0c6938 */
if(!s->budget--) { s->failed_pc=0x0c0c6938u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c693a;
P_0c0c693a: /* original 8901, guest PC 0x0c0c693a */
if(!s->budget--) { s->failed_pc=0x0c0c693au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6940; }
goto P_0c0c693c;
P_0c0c693c: /* original a28f, guest PC 0x0c0c693c */
if(!s->budget--) { s->failed_pc=0x0c0c693cu; return 0; }
goto P_0c0c6e5e;
P_0c0c693e: /* original 0009, guest PC 0x0c0c693e */
if(!s->budget--) { s->failed_pc=0x0c0c693eu; return 0; }
goto P_0c0c6940;
P_0c0c6940: /* original e03c, guest PC 0x0c0c6940 */
if(!s->budget--) { s->failed_pc=0x0c0c6940u; return 0; }
r[0]=0x0000003cu;
goto P_0c0c6942;
P_0c0c6942: /* original 932e, guest PC 0x0c0c6942 */
if(!s->budget--) { s->failed_pc=0x0c0c6942u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c69a2u,2);
goto P_0c0c6944;
P_0c0c6944: /* original 02ed, guest PC 0x0c0c6944 */
if(!s->budget--) { s->failed_pc=0x0c0c6944u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c6946;
P_0c0c6946: /* original 622d, guest PC 0x0c0c6946 */
if(!s->budget--) { s->failed_pc=0x0c0c6946u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c6948;
P_0c0c6948: /* original 3230, guest PC 0x0c0c6948 */
if(!s->budget--) { s->failed_pc=0x0c0c6948u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c694a;
P_0c0c694a: /* original 8b01, guest PC 0x0c0c694a */
if(!s->budget--) { s->failed_pc=0x0c0c694au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6950; }
goto P_0c0c694c;
P_0c0c694c: /* original a287, guest PC 0x0c0c694c */
if(!s->budget--) { s->failed_pc=0x0c0c694cu; return 0; }
goto P_0c0c6e5e;
P_0c0c694e: /* original 0009, guest PC 0x0c0c694e */
if(!s->budget--) { s->failed_pc=0x0c0c694eu; return 0; }
goto P_0c0c6950;
P_0c0c6950: /* original e04c, guest PC 0x0c0c6950 */
if(!s->budget--) { s->failed_pc=0x0c0c6950u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c6952;
P_0c0c6952: /* original 9325, guest PC 0x0c0c6952 */
if(!s->budget--) { s->failed_pc=0x0c0c6952u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c69a0u,2);
goto P_0c0c6954;
P_0c0c6954: /* original 02ee, guest PC 0x0c0c6954 */
if(!s->budget--) { s->failed_pc=0x0c0c6954u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c6956;
P_0c0c6956: /* original 2238, guest PC 0x0c0c6956 */
if(!s->budget--) { s->failed_pc=0x0c0c6956u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c6958;
P_0c0c6958: /* original 8f17, guest PC 0x0c0c6958 */
if(!s->budget--) { s->failed_pc=0x0c0c6958u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[12]+16,4);
if(!cond) { goto P_0c0c698a; }
goto P_0c0c695c;
P_0c0c695a: /* original 54c4, guest PC 0x0c0c695a */
if(!s->budget--) { s->failed_pc=0x0c0c695au; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c0c695c;
P_0c0c695c: /* original d514, guest PC 0x0c0c695c */
if(!s->budget--) { s->failed_pc=0x0c0c695cu; return 0; }
r[5]=read(ram,0x0c0c69b0u,4);
goto P_0c0c695e;
P_0c0c695e: /* original 2598, guest PC 0x0c0c695e */
if(!s->budget--) { s->failed_pc=0x0c0c695eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[9])==0)!=0);
goto P_0c0c6960;
P_0c0c6960: /* original 8b01, guest PC 0x0c0c6960 */
if(!s->budget--) { s->failed_pc=0x0c0c6960u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6966; }
goto P_0c0c6962;
P_0c0c6962: /* original a0c3, guest PC 0x0c0c6962 */
if(!s->budget--) { s->failed_pc=0x0c0c6962u; return 0; }
goto P_0c0c6aec;
P_0c0c6964: /* original 0009, guest PC 0x0c0c6964 */
if(!s->budget--) { s->failed_pc=0x0c0c6964u; return 0; }
goto P_0c0c6966;
P_0c0c6966: /* original 951d, guest PC 0x0c0c6966 */
if(!s->budget--) { s->failed_pc=0x0c0c6966u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c69a4u,2);
goto P_0c0c6968;
P_0c0c6968: /* original 2598, guest PC 0x0c0c6968 */
if(!s->budget--) { s->failed_pc=0x0c0c6968u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[9])==0)!=0);
goto P_0c0c696a;
P_0c0c696a: /* original 8906, guest PC 0x0c0c696a */
if(!s->budget--) { s->failed_pc=0x0c0c696au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c697a; }
goto P_0c0c696c;
P_0c0c696c: /* original 931b, guest PC 0x0c0c696c */
if(!s->budget--) { s->failed_pc=0x0c0c696cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c69a6u,2);
goto P_0c0c696e;
P_0c0c696e: /* original 2398, guest PC 0x0c0c696e */
if(!s->budget--) { s->failed_pc=0x0c0c696eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c6970;
P_0c0c6970: /* original 8b02, guest PC 0x0c0c6970 */
if(!s->budget--) { s->failed_pc=0x0c0c6970u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6978; }
goto P_0c0c6972;
P_0c0c6972: /* original d510, guest PC 0x0c0c6972 */
if(!s->budget--) { s->failed_pc=0x0c0c6972u; return 0; }
r[5]=read(ram,0x0c0c69b4u,4);
goto P_0c0c6974;
P_0c0c6974: /* original 2598, guest PC 0x0c0c6974 */
if(!s->budget--) { s->failed_pc=0x0c0c6974u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[9])==0)!=0);
goto P_0c0c6976;
P_0c0c6976: /* original 8b00, guest PC 0x0c0c6976 */
if(!s->budget--) { s->failed_pc=0x0c0c6976u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c697a; }
goto P_0c0c6978;
P_0c0c6978: /* original ed20, guest PC 0x0c0c6978 */
if(!s->budget--) { s->failed_pc=0x0c0c6978u; return 0; }
r[13]=0x00000020u;
goto P_0c0c697a;
P_0c0c697a: /* original 6393, guest PC 0x0c0c697a */
if(!s->budget--) { s->failed_pc=0x0c0c697au; return 0; }
r[3]=r[9];
goto P_0c0c697c;
P_0c0c697c: /* original 2388, guest PC 0x0c0c697c */
if(!s->budget--) { s->failed_pc=0x0c0c697cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c697e;
P_0c0c697e: /* original 8904, guest PC 0x0c0c697e */
if(!s->budget--) { s->failed_pc=0x0c0c697eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c698a; }
goto P_0c0c6980;
P_0c0c6980: /* original 52c3, guest PC 0x0c0c6980 */
if(!s->budget--) { s->failed_pc=0x0c0c6980u; return 0; }
r[2]=read(ram,r[12]+12,4);
goto P_0c0c6982;
P_0c0c6982: /* original 2228, guest PC 0x0c0c6982 */
if(!s->budget--) { s->failed_pc=0x0c0c6982u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c6984;
P_0c0c6984: /* original 8901, guest PC 0x0c0c6984 */
if(!s->budget--) { s->failed_pc=0x0c0c6984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c698a; }
goto P_0c0c6986;
P_0c0c6986: /* original a0b1, guest PC 0x0c0c6986 */
if(!s->budget--) { s->failed_pc=0x0c0c6986u; return 0; }
goto P_0c0c6aec;
P_0c0c6988: /* original 0009, guest PC 0x0c0c6988 */
if(!s->budget--) { s->failed_pc=0x0c0c6988u; return 0; }
goto P_0c0c698a;
P_0c0c698a: /* original 2448, guest PC 0x0c0c698a */
if(!s->budget--) { s->failed_pc=0x0c0c698au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c698c;
P_0c0c698c: /* original e101, guest PC 0x0c0c698c */
if(!s->budget--) { s->failed_pc=0x0c0c698cu; return 0; }
r[1]=0x00000001u;
goto P_0c0c698e;
P_0c0c698e: /* original 8d13, guest PC 0x0c0c698e */
if(!s->budget--) { s->failed_pc=0x0c0c698eu; return 0; }
cond=r[17]&1u;
r[13]|=r[1];
if(cond) { goto P_0c0c69b8; }
goto P_0c0c6992;
P_0c0c6990: /* original 2d1b, guest PC 0x0c0c6990 */
if(!s->budget--) { s->failed_pc=0x0c0c6990u; return 0; }
r[13]|=r[1];
goto P_0c0c6992;
P_0c0c6992: /* original e320, guest PC 0x0c0c6992 */
if(!s->budget--) { s->failed_pc=0x0c0c6992u; return 0; }
r[3]=0x00000020u;
goto P_0c0c6994;
P_0c0c6994: /* original a263, guest PC 0x0c0c6994 */
if(!s->budget--) { s->failed_pc=0x0c0c6994u; return 0; }
r[13]|=r[3];
goto P_0c0c6e5e;
P_0c0c6996: /* original 2d3b, guest PC 0x0c0c6996 */
if(!s->budget--) { s->failed_pc=0x0c0c6996u; return 0; }
r[13]|=r[3];
if(!vf3_matrix_family(0x0c0c6998u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6998u; return 0; } return 1;
P_0c0c69b8: /* original 967f, guest PC 0x0c0c69b8 */
if(!s->budget--) { s->failed_pc=0x0c0c69b8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6abau,2);
goto P_0c0c69ba;
P_0c0c69ba: /* original 36ec, guest PC 0x0c0c69ba */
if(!s->budget--) { s->failed_pc=0x0c0c69bau; return 0; }
r[6]+=r[14];
goto P_0c0c69bc;
P_0c0c69bc: /* original 046e, guest PC 0x0c0c69bc */
if(!s->budget--) { s->failed_pc=0x0c0c69bcu; return 0; }
r[4]=read(ram,r[6]+r[0],4);
goto P_0c0c69be;
P_0c0c69be: /* original e068, guest PC 0x0c0c69be */
if(!s->budget--) { s->failed_pc=0x0c0c69beu; return 0; }
r[0]=0x00000068u;
goto P_0c0c69c0;
P_0c0c69c0: /* original 056e, guest PC 0x0c0c69c0 */
if(!s->budget--) { s->failed_pc=0x0c0c69c0u; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c0c69c2;
P_0c0c69c2: /* original 6743, guest PC 0x0c0c69c2 */
if(!s->budget--) { s->failed_pc=0x0c0c69c2u; return 0; }
r[7]=r[4];
goto P_0c0c69c4;
P_0c0c69c4: /* original 5662, guest PC 0x0c0c69c4 */
if(!s->budget--) { s->failed_pc=0x0c0c69c4u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c0c69c6;
P_0c0c69c6: /* original 275b, guest PC 0x0c0c69c6 */
if(!s->budget--) { s->failed_pc=0x0c0c69c6u; return 0; }
r[7]|=r[5];
goto P_0c0c69c8;
P_0c0c69c8: /* original 276b, guest PC 0x0c0c69c8 */
if(!s->budget--) { s->failed_pc=0x0c0c69c8u; return 0; }
r[7]|=r[6];
goto P_0c0c69ca;
P_0c0c69ca: /* original 27a8, guest PC 0x0c0c69ca */
if(!s->budget--) { s->failed_pc=0x0c0c69cau; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[10])==0)!=0);
goto P_0c0c69cc;
P_0c0c69cc: /* original 8908, guest PC 0x0c0c69cc */
if(!s->budget--) { s->failed_pc=0x0c0c69ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c69e0; }
goto P_0c0c69ce;
P_0c0c69ce: /* original 2459, guest PC 0x0c0c69ce */
if(!s->budget--) { s->failed_pc=0x0c0c69ceu; return 0; }
r[4]&=r[5];
goto P_0c0c69d0;
P_0c0c69d0: /* original 24a8, guest PC 0x0c0c69d0 */
if(!s->budget--) { s->failed_pc=0x0c0c69d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0c69d2;
P_0c0c69d2: /* original 8b01, guest PC 0x0c0c69d2 */
if(!s->budget--) { s->failed_pc=0x0c0c69d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c69d8; }
goto P_0c0c69d4;
P_0c0c69d4: /* original e340, guest PC 0x0c0c69d4 */
if(!s->budget--) { s->failed_pc=0x0c0c69d4u; return 0; }
r[3]=0x00000040u;
goto P_0c0c69d6;
P_0c0c69d6: /* original 2d3b, guest PC 0x0c0c69d6 */
if(!s->budget--) { s->failed_pc=0x0c0c69d6u; return 0; }
r[13]|=r[3];
goto P_0c0c69d8;
P_0c0c69d8: /* original 26a8, guest PC 0x0c0c69d8 */
if(!s->budget--) { s->failed_pc=0x0c0c69d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[10])==0)!=0);
goto P_0c0c69da;
P_0c0c69da: /* original 8b01, guest PC 0x0c0c69da */
if(!s->budget--) { s->failed_pc=0x0c0c69dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c69e0; }
goto P_0c0c69dc;
P_0c0c69dc: /* original 926e, guest PC 0x0c0c69dc */
if(!s->budget--) { s->failed_pc=0x0c0c69dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6abcu,2);
goto P_0c0c69de;
P_0c0c69de: /* original 2d2b, guest PC 0x0c0c69de */
if(!s->budget--) { s->failed_pc=0x0c0c69deu; return 0; }
r[13]|=r[2];
goto P_0c0c69e0;
P_0c0c69e0: /* original 9c6f, guest PC 0x0c0c69e0 */
if(!s->budget--) { s->failed_pc=0x0c0c69e0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ac2u,2);
goto P_0c0c69e2;
P_0c0c69e2: /* original e320, guest PC 0x0c0c69e2 */
if(!s->budget--) { s->failed_pc=0x0c0c69e2u; return 0; }
r[3]=0x00000020u;
goto P_0c0c69e4;
P_0c0c69e4: /* original 906b, guest PC 0x0c0c69e4 */
if(!s->budget--) { s->failed_pc=0x0c0c69e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6abeu,2);
goto P_0c0c69e6;
P_0c0c69e6: /* original 23d8, guest PC 0x0c0c69e6 */
if(!s->budget--) { s->failed_pc=0x0c0c69e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c69e8;
P_0c0c69e8: /* original 9b6a, guest PC 0x0c0c69e8 */
if(!s->budget--) { s->failed_pc=0x0c0c69e8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ac0u,2);
goto P_0c0c69ea;
P_0c0c69ea: /* original 8f46, guest PC 0x0c0c69ea */
if(!s->budget--) { s->failed_pc=0x0c0c69eau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[14]+r[0]);
if(!cond) { goto P_0c0c6a7a; }
goto P_0c0c69ee;
P_0c0c69ec: /* original fde6, guest PC 0x0c0c69ec */
if(!s->budget--) { s->failed_pc=0x0c0c69ecu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0c69ee;
P_0c0c69ee: /* original 9069, guest PC 0x0c0c69ee */
if(!s->budget--) { s->failed_pc=0x0c0c69eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ac4u,2);
goto P_0c0c69f0;
P_0c0c69f0: /* original f4e6, guest PC 0x0c0c69f0 */
if(!s->budget--) { s->failed_pc=0x0c0c69f0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c69f2;
P_0c0c69f2: /* original 7008, guest PC 0x0c0c69f2 */
if(!s->budget--) { s->failed_pc=0x0c0c69f2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c69f4;
P_0c0c69f4: /* original f3e6, guest PC 0x0c0c69f4 */
if(!s->budget--) { s->failed_pc=0x0c0c69f4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c69f6;
P_0c0c69f6: /* original e020, guest PC 0x0c0c69f6 */
if(!s->budget--) { s->failed_pc=0x0c0c69f6u; return 0; }
r[0]=0x00000020u;
goto P_0c0c69f8;
P_0c0c69f8: /* original ff37, guest PC 0x0c0c69f8 */
if(!s->budget--) { s->failed_pc=0x0c0c69f8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c69fa;
P_0c0c69fa: /* original d336, guest PC 0x0c0c69fa */
if(!s->budget--) { s->failed_pc=0x0c0c69fau; return 0; }
r[3]=read(ram,0x0c0c6ad4u,4);
goto P_0c0c69fc;
P_0c0c69fc: /* original f53c, guest PC 0x0c0c69fc */
if(!s->budget--) { s->failed_pc=0x0c0c69fcu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c69fe;
P_0c0c69fe: /* original 430b, guest PC 0x0c0c69fe */
if(!s->budget--) { s->failed_pc=0x0c0c69feu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a02u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a02u) { target=s->pc; goto dispatch; }
goto P_0c0c6a02;
P_0c0c6a00: /* original f54d, guest PC 0x0c0c6a00 */
if(!s->budget--) { s->failed_pc=0x0c0c6a00u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c6a02;
P_0c0c6a02: /* original c735, guest PC 0x0c0c6a02 */
if(!s->budget--) { s->failed_pc=0x0c0c6a02u; return 0; }
r[0]=code_base|0x000c6ad8u;
goto P_0c0c6a04;
P_0c0c6a04: /* original d335, guest PC 0x0c0c6a04 */
if(!s->budget--) { s->failed_pc=0x0c0c6a04u; return 0; }
r[3]=read(ram,0x0c0c6adcu,4);
goto P_0c0c6a06;
P_0c0c6a06: /* original f508, guest PC 0x0c0c6a06 */
if(!s->budget--) { s->failed_pc=0x0c0c6a06u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6a08;
P_0c0c6a08: /* original f30c, guest PC 0x0c0c6a08 */
if(!s->budget--) { s->failed_pc=0x0c0c6a08u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c6a0a;
P_0c0c6a0a: /* original f4dc, guest PC 0x0c0c6a0a */
if(!s->budget--) { s->failed_pc=0x0c0c6a0au; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c6a0c;
P_0c0c6a0c: /* original 430b, guest PC 0x0c0c6a0c */
if(!s->budget--) { s->failed_pc=0x0c0c6a0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a10u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a10u) { target=s->pc; goto dispatch; }
goto P_0c0c6a10;
P_0c0c6a0e: /* original f431, guest PC 0x0c0c6a0e */
if(!s->budget--) { s->failed_pc=0x0c0c6a0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0c6a10;
P_0c0c6a10: /* original d233, guest PC 0x0c0c6a10 */
if(!s->budget--) { s->failed_pc=0x0c0c6a10u; return 0; }
r[2]=read(ram,0x0c0c6ae0u,4);
goto P_0c0c6a12;
P_0c0c6a12: /* original 600f, guest PC 0x0c0c6a12 */
if(!s->budget--) { s->failed_pc=0x0c0c6a12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6a14;
P_0c0c6a14: /* original 2298, guest PC 0x0c0c6a14 */
if(!s->budget--) { s->failed_pc=0x0c0c6a14u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c0c6a16;
P_0c0c6a16: /* original 8d01, guest PC 0x0c0c6a16 */
if(!s->budget--) { s->failed_pc=0x0c0c6a16u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
if(cond) { goto P_0c0c6a1c; }
goto P_0c0c6a1a;
P_0c0c6a18: /* original 640f, guest PC 0x0c0c6a18 */
if(!s->budget--) { s->failed_pc=0x0c0c6a18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6a1a;
P_0c0c6a1a: /* original 644b, guest PC 0x0c0c6a1a */
if(!s->budget--) { s->failed_pc=0x0c0c6a1au; return 0; }
r[4]=0u-r[4];
goto P_0c0c6a1c;
P_0c0c6a1c: /* original 9053, guest PC 0x0c0c6a1c */
if(!s->budget--) { s->failed_pc=0x0c0c6a1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ac6u,2);
goto P_0c0c6a1e;
P_0c0c6a1e: /* original 0e45, guest PC 0x0c0c6a1e */
if(!s->budget--) { s->failed_pc=0x0c0c6a1eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0c6a20;
P_0c0c6a20: /* original 700e, guest PC 0x0c0c6a20 */
if(!s->budget--) { s->failed_pc=0x0c0c6a20u; return 0; }
r[0]+=0x0000000eu;
goto P_0c0c6a22;
P_0c0c6a22: /* original f4e6, guest PC 0x0c0c6a22 */
if(!s->budget--) { s->failed_pc=0x0c0c6a22u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6a24;
P_0c0c6a24: /* original 7008, guest PC 0x0c0c6a24 */
if(!s->budget--) { s->failed_pc=0x0c0c6a24u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c6a26;
P_0c0c6a26: /* original f3e6, guest PC 0x0c0c6a26 */
if(!s->budget--) { s->failed_pc=0x0c0c6a26u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c6a28;
P_0c0c6a28: /* original e018, guest PC 0x0c0c6a28 */
if(!s->budget--) { s->failed_pc=0x0c0c6a28u; return 0; }
r[0]=0x00000018u;
goto P_0c0c6a2a;
P_0c0c6a2a: /* original ff37, guest PC 0x0c0c6a2a */
if(!s->budget--) { s->failed_pc=0x0c0c6a2au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6a2c;
P_0c0c6a2c: /* original d329, guest PC 0x0c0c6a2c */
if(!s->budget--) { s->failed_pc=0x0c0c6a2cu; return 0; }
r[3]=read(ram,0x0c0c6ad4u,4);
goto P_0c0c6a2e;
P_0c0c6a2e: /* original f53c, guest PC 0x0c0c6a2e */
if(!s->budget--) { s->failed_pc=0x0c0c6a2eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c6a30;
P_0c0c6a30: /* original 430b, guest PC 0x0c0c6a30 */
if(!s->budget--) { s->failed_pc=0x0c0c6a30u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a34u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a34u) { target=s->pc; goto dispatch; }
goto P_0c0c6a34;
P_0c0c6a32: /* original f54d, guest PC 0x0c0c6a32 */
if(!s->budget--) { s->failed_pc=0x0c0c6a32u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c6a34;
P_0c0c6a34: /* original e00c, guest PC 0x0c0c6a34 */
if(!s->budget--) { s->failed_pc=0x0c0c6a34u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c6a36;
P_0c0c6a36: /* original ff07, guest PC 0x0c0c6a36 */
if(!s->budget--) { s->failed_pc=0x0c0c6a36u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c6a38;
P_0c0c6a38: /* original 9046, guest PC 0x0c0c6a38 */
if(!s->budget--) { s->failed_pc=0x0c0c6a38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ac8u,2);
goto P_0c0c6a3a;
P_0c0c6a3a: /* original f4e6, guest PC 0x0c0c6a3a */
if(!s->budget--) { s->failed_pc=0x0c0c6a3au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6a3c;
P_0c0c6a3c: /* original 7008, guest PC 0x0c0c6a3c */
if(!s->budget--) { s->failed_pc=0x0c0c6a3cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c6a3e;
P_0c0c6a3e: /* original f3e6, guest PC 0x0c0c6a3e */
if(!s->budget--) { s->failed_pc=0x0c0c6a3eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c6a40;
P_0c0c6a40: /* original e01c, guest PC 0x0c0c6a40 */
if(!s->budget--) { s->failed_pc=0x0c0c6a40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c6a42;
P_0c0c6a42: /* original ff37, guest PC 0x0c0c6a42 */
if(!s->budget--) { s->failed_pc=0x0c0c6a42u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6a44;
P_0c0c6a44: /* original d323, guest PC 0x0c0c6a44 */
if(!s->budget--) { s->failed_pc=0x0c0c6a44u; return 0; }
r[3]=read(ram,0x0c0c6ad4u,4);
goto P_0c0c6a46;
P_0c0c6a46: /* original f53c, guest PC 0x0c0c6a46 */
if(!s->budget--) { s->failed_pc=0x0c0c6a46u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c6a48;
P_0c0c6a48: /* original 430b, guest PC 0x0c0c6a48 */
if(!s->budget--) { s->failed_pc=0x0c0c6a48u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a4cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a4cu) { target=s->pc; goto dispatch; }
goto P_0c0c6a4c;
P_0c0c6a4a: /* original f54d, guest PC 0x0c0c6a4a */
if(!s->budget--) { s->failed_pc=0x0c0c6a4au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c6a4c;
P_0c0c6a4c: /* original c725, guest PC 0x0c0c6a4c */
if(!s->budget--) { s->failed_pc=0x0c0c6a4cu; return 0; }
r[0]=code_base|0x000c6ae4u;
goto P_0c0c6a4e;
P_0c0c6a4e: /* original d323, guest PC 0x0c0c6a4e */
if(!s->budget--) { s->failed_pc=0x0c0c6a4eu; return 0; }
r[3]=read(ram,0x0c0c6adcu,4);
goto P_0c0c6a50;
P_0c0c6a50: /* original f508, guest PC 0x0c0c6a50 */
if(!s->budget--) { s->failed_pc=0x0c0c6a50u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6a52;
P_0c0c6a52: /* original e00c, guest PC 0x0c0c6a52 */
if(!s->budget--) { s->failed_pc=0x0c0c6a52u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c6a54;
P_0c0c6a54: /* original f3f6, guest PC 0x0c0c6a54 */
if(!s->budget--) { s->failed_pc=0x0c0c6a54u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c6a56;
P_0c0c6a56: /* original f40c, guest PC 0x0c0c6a56 */
if(!s->budget--) { s->failed_pc=0x0c0c6a56u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c6a58;
P_0c0c6a58: /* original 430b, guest PC 0x0c0c6a58 */
if(!s->budget--) { s->failed_pc=0x0c0c6a58u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a5cu;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a5cu) { target=s->pc; goto dispatch; }
goto P_0c0c6a5c;
P_0c0c6a5a: /* original f431, guest PC 0x0c0c6a5a */
if(!s->budget--) { s->failed_pc=0x0c0c6a5au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0c6a5c;
P_0c0c6a5c: /* original d220, guest PC 0x0c0c6a5c */
if(!s->budget--) { s->failed_pc=0x0c0c6a5cu; return 0; }
r[2]=read(ram,0x0c0c6ae0u,4);
goto P_0c0c6a5e;
P_0c0c6a5e: /* original 600f, guest PC 0x0c0c6a5e */
if(!s->budget--) { s->failed_pc=0x0c0c6a5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6a60;
P_0c0c6a60: /* original 2298, guest PC 0x0c0c6a60 */
if(!s->budget--) { s->failed_pc=0x0c0c6a60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c0c6a62;
P_0c0c6a62: /* original 8d01, guest PC 0x0c0c6a62 */
if(!s->budget--) { s->failed_pc=0x0c0c6a62u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
if(cond) { goto P_0c0c6a68; }
goto P_0c0c6a66;
P_0c0c6a64: /* original 640f, guest PC 0x0c0c6a64 */
if(!s->budget--) { s->failed_pc=0x0c0c6a64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6a66;
P_0c0c6a66: /* original 644b, guest PC 0x0c0c6a66 */
if(!s->budget--) { s->failed_pc=0x0c0c6a66u; return 0; }
r[4]=0u-r[4];
goto P_0c0c6a68;
P_0c0c6a68: /* original 34b7, guest PC 0x0c0c6a68 */
if(!s->budget--) { s->failed_pc=0x0c0c6a68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[11])!=0);
goto P_0c0c6a6a;
P_0c0c6a6a: /* original 8b01, guest PC 0x0c0c6a6a */
if(!s->budget--) { s->failed_pc=0x0c0c6a6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6a70; }
goto P_0c0c6a6c;
P_0c0c6a6c: /* original a003, guest PC 0x0c0c6a6c */
if(!s->budget--) { s->failed_pc=0x0c0c6a6cu; return 0; }
r[4]=r[11];
goto P_0c0c6a76;
P_0c0c6a6e: /* original 64b3, guest PC 0x0c0c6a6e */
if(!s->budget--) { s->failed_pc=0x0c0c6a6eu; return 0; }
r[4]=r[11];
goto P_0c0c6a70;
P_0c0c6a70: /* original 34c3, guest PC 0x0c0c6a70 */
if(!s->budget--) { s->failed_pc=0x0c0c6a70u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c0c6a72;
P_0c0c6a72: /* original 8900, guest PC 0x0c0c6a72 */
if(!s->budget--) { s->failed_pc=0x0c0c6a72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6a76; }
goto P_0c0c6a74;
P_0c0c6a74: /* original 64c3, guest PC 0x0c0c6a74 */
if(!s->budget--) { s->failed_pc=0x0c0c6a74u; return 0; }
r[4]=r[12];
goto P_0c0c6a76;
P_0c0c6a76: /* original 9028, guest PC 0x0c0c6a76 */
if(!s->budget--) { s->failed_pc=0x0c0c6a76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6acau,2);
goto P_0c0c6a78;
P_0c0c6a78: /* original 0e45, guest PC 0x0c0c6a78 */
if(!s->budget--) { s->failed_pc=0x0c0c6a78u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0c6a7a;
P_0c0c6a7a: /* original 9427, guest PC 0x0c0c6a7a */
if(!s->budget--) { s->failed_pc=0x0c0c6a7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6accu,2);
goto P_0c0c6a7c;
P_0c0c6a7c: /* original 24d8, guest PC 0x0c0c6a7c */
if(!s->budget--) { s->failed_pc=0x0c0c6a7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0c6a7e;
P_0c0c6a7e: /* original 8901, guest PC 0x0c0c6a7e */
if(!s->budget--) { s->failed_pc=0x0c0c6a7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6a84; }
goto P_0c0c6a80;
P_0c0c6a80: /* original a1c1, guest PC 0x0c0c6a80 */
if(!s->budget--) { s->failed_pc=0x0c0c6a80u; return 0; }
goto P_0c0c6e06;
P_0c0c6a82: /* original 0009, guest PC 0x0c0c6a82 */
if(!s->budget--) { s->failed_pc=0x0c0c6a82u; return 0; }
goto P_0c0c6a84;
P_0c0c6a84: /* original 9423, guest PC 0x0c0c6a84 */
if(!s->budget--) { s->failed_pc=0x0c0c6a84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6aceu,2);
goto P_0c0c6a86;
P_0c0c6a86: /* original e00c, guest PC 0x0c0c6a86 */
if(!s->budget--) { s->failed_pc=0x0c0c6a86u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c6a88;
P_0c0c6a88: /* original d314, guest PC 0x0c0c6a88 */
if(!s->budget--) { s->failed_pc=0x0c0c6a88u; return 0; }
r[3]=read(ram,0x0c0c6adcu,4);
goto P_0c0c6a8a;
P_0c0c6a8a: /* original 34ec, guest PC 0x0c0c6a8a */
if(!s->budget--) { s->failed_pc=0x0c0c6a8au; return 0; }
r[4]+=r[14];
goto P_0c0c6a8c;
P_0c0c6a8c: /* original f446, guest PC 0x0c0c6a8c */
if(!s->budget--) { s->failed_pc=0x0c0c6a8cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c6a8e;
P_0c0c6a8e: /* original e020, guest PC 0x0c0c6a8e */
if(!s->budget--) { s->failed_pc=0x0c0c6a8eu; return 0; }
r[0]=0x00000020u;
goto P_0c0c6a90;
P_0c0c6a90: /* original f646, guest PC 0x0c0c6a90 */
if(!s->budget--) { s->failed_pc=0x0c0c6a90u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0c6a92;
P_0c0c6a92: /* original c715, guest PC 0x0c0c6a92 */
if(!s->budget--) { s->failed_pc=0x0c0c6a92u; return 0; }
r[0]=code_base|0x000c6ae8u;
goto P_0c0c6a94;
P_0c0c6a94: /* original f508, guest PC 0x0c0c6a94 */
if(!s->budget--) { s->failed_pc=0x0c0c6a94u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6a96;
P_0c0c6a96: /* original 430b, guest PC 0x0c0c6a96 */
if(!s->budget--) { s->failed_pc=0x0c0c6a96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6a9au;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6a9au) { target=s->pc; goto dispatch; }
goto P_0c0c6a9a;
P_0c0c6a98: /* original f461, guest PC 0x0c0c6a98 */
if(!s->budget--) { s->failed_pc=0x0c0c6a98u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0c6a9a;
P_0c0c6a9a: /* original d211, guest PC 0x0c0c6a9a */
if(!s->budget--) { s->failed_pc=0x0c0c6a9au; return 0; }
r[2]=read(ram,0x0c0c6ae0u,4);
goto P_0c0c6a9c;
P_0c0c6a9c: /* original 600f, guest PC 0x0c0c6a9c */
if(!s->budget--) { s->failed_pc=0x0c0c6a9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6a9e;
P_0c0c6a9e: /* original 2928, guest PC 0x0c0c6a9e */
if(!s->budget--) { s->failed_pc=0x0c0c6a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c0c6aa0;
P_0c0c6aa0: /* original 8d01, guest PC 0x0c0c6aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c6aa0u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
if(cond) { goto P_0c0c6aa6; }
goto P_0c0c6aa4;
P_0c0c6aa2: /* original 640f, guest PC 0x0c0c6aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c6aa2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6aa4;
P_0c0c6aa4: /* original 644b, guest PC 0x0c0c6aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c6aa4u; return 0; }
r[4]=0u-r[4];
goto P_0c0c6aa6;
P_0c0c6aa6: /* original 34b7, guest PC 0x0c0c6aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c6aa6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[11])!=0);
goto P_0c0c6aa8;
P_0c0c6aa8: /* original 8b01, guest PC 0x0c0c6aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c6aa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6aae; }
goto P_0c0c6aaa;
P_0c0c6aaa: /* original a003, guest PC 0x0c0c6aaa */
if(!s->budget--) { s->failed_pc=0x0c0c6aaau; return 0; }
r[4]=r[11];
goto P_0c0c6ab4;
P_0c0c6aac: /* original 64b3, guest PC 0x0c0c6aac */
if(!s->budget--) { s->failed_pc=0x0c0c6aacu; return 0; }
r[4]=r[11];
goto P_0c0c6aae;
P_0c0c6aae: /* original 34c3, guest PC 0x0c0c6aae */
if(!s->budget--) { s->failed_pc=0x0c0c6aaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c0c6ab0;
P_0c0c6ab0: /* original 8900, guest PC 0x0c0c6ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ab0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6ab4; }
goto P_0c0c6ab2;
P_0c0c6ab2: /* original 64c3, guest PC 0x0c0c6ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ab2u; return 0; }
r[4]=r[12];
goto P_0c0c6ab4;
P_0c0c6ab4: /* original 900c, guest PC 0x0c0c6ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ab4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ad0u,2);
goto P_0c0c6ab6;
P_0c0c6ab6: /* original a1a6, guest PC 0x0c0c6ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ab6u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0c6e06;
P_0c0c6ab8: /* original 0e45, guest PC 0x0c0c6ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ab8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c0c6abau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6abau; return 0; } return 1;
P_0c0c6aec: /* original 2448, guest PC 0x0c0c6aec */
if(!s->budget--) { s->failed_pc=0x0c0c6aecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c6aee;
P_0c0c6aee: /* original 8901, guest PC 0x0c0c6aee */
if(!s->budget--) { s->failed_pc=0x0c0c6aeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6af4; }
goto P_0c0c6af0;
P_0c0c6af0: /* original a1b5, guest PC 0x0c0c6af0 */
if(!s->budget--) { s->failed_pc=0x0c0c6af0u; return 0; }
goto P_0c0c6e5e;
P_0c0c6af2: /* original 0009, guest PC 0x0c0c6af2 */
if(!s->budget--) { s->failed_pc=0x0c0c6af2u; return 0; }
goto P_0c0c6af4;
P_0c0c6af4: /* original e220, guest PC 0x0c0c6af4 */
if(!s->budget--) { s->failed_pc=0x0c0c6af4u; return 0; }
r[2]=0x00000020u;
goto P_0c0c6af6;
P_0c0c6af6: /* original 2928, guest PC 0x0c0c6af6 */
if(!s->budget--) { s->failed_pc=0x0c0c6af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c0c6af8;
P_0c0c6af8: /* original 8932, guest PC 0x0c0c6af8 */
if(!s->budget--) { s->failed_pc=0x0c0c6af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6b60; }
goto P_0c0c6afa;
P_0c0c6afa: /* original 9472, guest PC 0x0c0c6afa */
if(!s->budget--) { s->failed_pc=0x0c0c6afau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6be2u,2);
goto P_0c0c6afc;
P_0c0c6afc: /* original e01c, guest PC 0x0c0c6afc */
if(!s->budget--) { s->failed_pc=0x0c0c6afcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c6afe;
P_0c0c6afe: /* original 34ec, guest PC 0x0c0c6afe */
if(!s->budget--) { s->failed_pc=0x0c0c6afeu; return 0; }
r[4]+=r[14];
goto P_0c0c6b00;
P_0c0c6b00: /* original ff46, guest PC 0x0c0c6b00 */
if(!s->budget--) { s->failed_pc=0x0c0c6b00u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0c6b02;
P_0c0c6b02: /* original e030, guest PC 0x0c0c6b02 */
if(!s->budget--) { s->failed_pc=0x0c0c6b02u; return 0; }
r[0]=0x00000030u;
goto P_0c0c6b04;
P_0c0c6b04: /* original fe46, guest PC 0x0c0c6b04 */
if(!s->budget--) { s->failed_pc=0x0c0c6b04u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0c6b06;
P_0c0c6b06: /* original 64b3, guest PC 0x0c0c6b06 */
if(!s->budget--) { s->failed_pc=0x0c0c6b06u; return 0; }
r[4]=r[11];
goto P_0c0c6b08;
P_0c0c6b08: /* original 906c, guest PC 0x0c0c6b08 */
if(!s->budget--) { s->failed_pc=0x0c0c6b08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6be4u,2);
goto P_0c0c6b0a;
P_0c0c6b0a: /* original 7458, guest PC 0x0c0c6b0a */
if(!s->budget--) { s->failed_pc=0x0c0c6b0au; return 0; }
r[4]+=0x00000058u;
goto P_0c0c6b0c;
P_0c0c6b0c: /* original f448, guest PC 0x0c0c6b0c */
if(!s->budget--) { s->failed_pc=0x0c0c6b0cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c6b0e;
P_0c0c6b0e: /* original f5e6, guest PC 0x0c0c6b0e */
if(!s->budget--) { s->failed_pc=0x0c0c6b0eu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c6b10;
P_0c0c6b10: /* original f451, guest PC 0x0c0c6b10 */
if(!s->budget--) { s->failed_pc=0x0c0c6b10u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0c6b12;
P_0c0c6b12: /* original f4f5, guest PC 0x0c0c6b12 */
if(!s->budget--) { s->failed_pc=0x0c0c6b12u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c6b14;
P_0c0c6b14: /* original 8f04, guest PC 0x0c0c6b14 */
if(!s->budget--) { s->failed_pc=0x0c0c6b14u; return 0; }
cond=r[17]&1u;
r[4]=0x00000008u;
if(!cond) { goto P_0c0c6b20; }
goto P_0c0c6b18;
P_0c0c6b16: /* original e408, guest PC 0x0c0c6b16 */
if(!s->budget--) { s->failed_pc=0x0c0c6b16u; return 0; }
r[4]=0x00000008u;
goto P_0c0c6b18;
P_0c0c6b18: /* original 9065, guest PC 0x0c0c6b18 */
if(!s->budget--) { s->failed_pc=0x0c0c6b18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6be6u,2);
goto P_0c0c6b1a;
P_0c0c6b1a: /* original 05ee, guest PC 0x0c0c6b1a */
if(!s->budget--) { s->failed_pc=0x0c0c6b1au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c6b1c;
P_0c0c6b1c: /* original 25a8, guest PC 0x0c0c6b1c */
if(!s->budget--) { s->failed_pc=0x0c0c6b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[10])==0)!=0);
goto P_0c0c6b1e;
P_0c0c6b1e: /* original 8900, guest PC 0x0c0c6b1e */
if(!s->budget--) { s->failed_pc=0x0c0c6b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6b22; }
goto P_0c0c6b20;
P_0c0c6b20: /* original 2d4b, guest PC 0x0c0c6b20 */
if(!s->budget--) { s->failed_pc=0x0c0c6b20u; return 0; }
r[13]|=r[4];
goto P_0c0c6b22;
P_0c0c6b22: /* original 9561, guest PC 0x0c0c6b22 */
if(!s->budget--) { s->failed_pc=0x0c0c6b22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6be8u,2);
goto P_0c0c6b24;
P_0c0c6b24: /* original 9061, guest PC 0x0c0c6b24 */
if(!s->budget--) { s->failed_pc=0x0c0c6b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6beau,2);
goto P_0c0c6b26;
P_0c0c6b26: /* original 35bc, guest PC 0x0c0c6b26 */
if(!s->budget--) { s->failed_pc=0x0c0c6b26u; return 0; }
r[5]+=r[11];
goto P_0c0c6b28;
P_0c0c6b28: /* original f5e6, guest PC 0x0c0c6b28 */
if(!s->budget--) { s->failed_pc=0x0c0c6b28u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c6b2a;
P_0c0c6b2a: /* original f458, guest PC 0x0c0c6b2a */
if(!s->budget--) { s->failed_pc=0x0c0c6b2au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c0c6b2c;
P_0c0c6b2c: /* original f451, guest PC 0x0c0c6b2c */
if(!s->budget--) { s->failed_pc=0x0c0c6b2cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0c6b2e;
P_0c0c6b2e: /* original f4e5, guest PC 0x0c0c6b2e */
if(!s->budget--) { s->failed_pc=0x0c0c6b2eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[14]))!=0);
goto P_0c0c6b30;
P_0c0c6b30: /* original 8b03, guest PC 0x0c0c6b30 */
if(!s->budget--) { s->failed_pc=0x0c0c6b30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6b3a; }
goto P_0c0c6b32;
P_0c0c6b32: /* original 905b, guest PC 0x0c0c6b32 */
if(!s->budget--) { s->failed_pc=0x0c0c6b32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6becu,2);
goto P_0c0c6b34;
P_0c0c6b34: /* original 05ee, guest PC 0x0c0c6b34 */
if(!s->budget--) { s->failed_pc=0x0c0c6b34u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c6b36;
P_0c0c6b36: /* original 25a8, guest PC 0x0c0c6b36 */
if(!s->budget--) { s->failed_pc=0x0c0c6b36u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[10])==0)!=0);
goto P_0c0c6b38;
P_0c0c6b38: /* original 8901, guest PC 0x0c0c6b38 */
if(!s->budget--) { s->failed_pc=0x0c0c6b38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6b3e; }
goto P_0c0c6b3a;
P_0c0c6b3a: /* original e310, guest PC 0x0c0c6b3a */
if(!s->budget--) { s->failed_pc=0x0c0c6b3au; return 0; }
r[3]=0x00000010u;
goto P_0c0c6b3c;
P_0c0c6b3c: /* original 2d3b, guest PC 0x0c0c6b3c */
if(!s->budget--) { s->failed_pc=0x0c0c6b3cu; return 0; }
r[13]|=r[3];
goto P_0c0c6b3e;
P_0c0c6b3e: /* original e518, guest PC 0x0c0c6b3e */
if(!s->budget--) { s->failed_pc=0x0c0c6b3eu; return 0; }
r[5]=0x00000018u;
goto P_0c0c6b40;
P_0c0c6b40: /* original 25d9, guest PC 0x0c0c6b40 */
if(!s->budget--) { s->failed_pc=0x0c0c6b40u; return 0; }
r[5]&=r[13];
goto P_0c0c6b42;
P_0c0c6b42: /* original 6053, guest PC 0x0c0c6b42 */
if(!s->budget--) { s->failed_pc=0x0c0c6b42u; return 0; }
r[0]=r[5];
goto P_0c0c6b44;
P_0c0c6b44: /* original 8818, guest PC 0x0c0c6b44 */
if(!s->budget--) { s->failed_pc=0x0c0c6b44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c0c6b46;
P_0c0c6b46: /* original 8b04, guest PC 0x0c0c6b46 */
if(!s->budget--) { s->failed_pc=0x0c0c6b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6b52; }
goto P_0c0c6b48;
P_0c0c6b48: /* original c72d, guest PC 0x0c0c6b48 */
if(!s->budget--) { s->failed_pc=0x0c0c6b48u; return 0; }
r[0]=code_base|0x000c6c00u;
goto P_0c0c6b4a;
P_0c0c6b4a: /* original f5fc, guest PC 0x0c0c6b4a */
if(!s->budget--) { s->failed_pc=0x0c0c6b4au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6b4c;
P_0c0c6b4c: /* original f408, guest PC 0x0c0c6b4c */
if(!s->budget--) { s->failed_pc=0x0c0c6b4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c6b4e;
P_0c0c6b4e: /* original a12d, guest PC 0x0c0c6b4e */
if(!s->budget--) { s->failed_pc=0x0c0c6b4eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0c6dac;
P_0c0c6b50: /* original f5e1, guest PC 0x0c0c6b50 */
if(!s->budget--) { s->failed_pc=0x0c0c6b50u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0c6b52;
P_0c0c6b52: /* original 24d8, guest PC 0x0c0c6b52 */
if(!s->budget--) { s->failed_pc=0x0c0c6b52u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0c6b54;
P_0c0c6b54: /* original 8d02, guest PC 0x0c0c6b54 */
if(!s->budget--) { s->failed_pc=0x0c0c6b54u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(cond) { goto P_0c0c6b5c; }
goto P_0c0c6b58;
P_0c0c6b56: /* original fdfc, guest PC 0x0c0c6b56 */
if(!s->budget--) { s->failed_pc=0x0c0c6b56u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c0c6b58;
P_0c0c6b58: /* original a155, guest PC 0x0c0c6b58 */
if(!s->budget--) { s->failed_pc=0x0c0c6b58u; return 0; }
goto P_0c0c6e06;
P_0c0c6b5a: /* original 0009, guest PC 0x0c0c6b5a */
if(!s->budget--) { s->failed_pc=0x0c0c6b5au; return 0; }
goto P_0c0c6b5c;
P_0c0c6b5c: /* original a112, guest PC 0x0c0c6b5c */
if(!s->budget--) { s->failed_pc=0x0c0c6b5cu; return 0; }
goto P_0c0c6d84;
P_0c0c6b5e: /* original 0009, guest PC 0x0c0c6b5e */
if(!s->budget--) { s->failed_pc=0x0c0c6b5eu; return 0; }
goto P_0c0c6b60;
P_0c0c6b60: /* original 9445, guest PC 0x0c0c6b60 */
if(!s->budget--) { s->failed_pc=0x0c0c6b60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6beeu,2);
goto P_0c0c6b62;
P_0c0c6b62: /* original c728, guest PC 0x0c0c6b62 */
if(!s->budget--) { s->failed_pc=0x0c0c6b62u; return 0; }
r[0]=code_base|0x000c6c04u;
goto P_0c0c6b64;
P_0c0c6b64: /* original fd08, guest PC 0x0c0c6b64 */
if(!s->budget--) { s->failed_pc=0x0c0c6b64u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0c6b66;
P_0c0c6b66: /* original e014, guest PC 0x0c0c6b66 */
if(!s->budget--) { s->failed_pc=0x0c0c6b66u; return 0; }
r[0]=0x00000014u;
goto P_0c0c6b68;
P_0c0c6b68: /* original 34bc, guest PC 0x0c0c6b68 */
if(!s->budget--) { s->failed_pc=0x0c0c6b68u; return 0; }
r[4]+=r[11];
goto P_0c0c6b6a;
P_0c0c6b6a: /* original f548, guest PC 0x0c0c6b6a */
if(!s->budget--) { s->failed_pc=0x0c0c6b6au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c0c6b6c;
P_0c0c6b6c: /* original 9440, guest PC 0x0c0c6b6c */
if(!s->budget--) { s->failed_pc=0x0c0c6b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bf0u,2);
goto P_0c0c6b6e;
P_0c0c6b6e: /* original 34bc, guest PC 0x0c0c6b6e */
if(!s->budget--) { s->failed_pc=0x0c0c6b6eu; return 0; }
r[4]+=r[11];
goto P_0c0c6b70;
P_0c0c6b70: /* original f348, guest PC 0x0c0c6b70 */
if(!s->budget--) { s->failed_pc=0x0c0c6b70u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0c6b72;
P_0c0c6b72: /* original ff37, guest PC 0x0c0c6b72 */
if(!s->budget--) { s->failed_pc=0x0c0c6b72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6b74;
P_0c0c6b74: /* original c724, guest PC 0x0c0c6b74 */
if(!s->budget--) { s->failed_pc=0x0c0c6b74u; return 0; }
r[0]=code_base|0x000c6c08u;
goto P_0c0c6b76;
P_0c0c6b76: /* original f65c, guest PC 0x0c0c6b76 */
if(!s->budget--) { s->failed_pc=0x0c0c6b76u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0c6b78;
P_0c0c6b78: /* original f631, guest PC 0x0c0c6b78 */
if(!s->budget--) { s->failed_pc=0x0c0c6b78u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0c6b7a;
P_0c0c6b7a: /* original f408, guest PC 0x0c0c6b7a */
if(!s->budget--) { s->failed_pc=0x0c0c6b7au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c6b7c;
P_0c0c6b7c: /* original e010, guest PC 0x0c0c6b7c */
if(!s->budget--) { s->failed_pc=0x0c0c6b7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c6b7e;
P_0c0c6b7e: /* original f65d, guest PC 0x0c0c6b7e */
if(!s->budget--) { s->failed_pc=0x0c0c6b7eu; return 0; }
fr[6]&=0x7fffffffu;
goto P_0c0c6b80;
P_0c0c6b80: /* original f641, guest PC 0x0c0c6b80 */
if(!s->budget--) { s->failed_pc=0x0c0c6b80u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c0c6b82;
P_0c0c6b82: /* original ff67, guest PC 0x0c0c6b82 */
if(!s->budget--) { s->failed_pc=0x0c0c6b82u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c6b84;
P_0c0c6b84: /* original e04c, guest PC 0x0c0c6b84 */
if(!s->budget--) { s->failed_pc=0x0c0c6b84u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c6b86;
P_0c0c6b86: /* original 9534, guest PC 0x0c0c6b86 */
if(!s->budget--) { s->failed_pc=0x0c0c6b86u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bf2u,2);
goto P_0c0c6b88;
P_0c0c6b88: /* original 9434, guest PC 0x0c0c6b88 */
if(!s->budget--) { s->failed_pc=0x0c0c6b88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bf4u,2);
goto P_0c0c6b8a;
P_0c0c6b8a: /* original 35ec, guest PC 0x0c0c6b8a */
if(!s->budget--) { s->failed_pc=0x0c0c6b8au; return 0; }
r[5]+=r[14];
goto P_0c0c6b8c;
P_0c0c6b8c: /* original 9333, guest PC 0x0c0c6b8c */
if(!s->budget--) { s->failed_pc=0x0c0c6b8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bf6u,2);
goto P_0c0c6b8e;
P_0c0c6b8e: /* original f656, guest PC 0x0c0c6b8e */
if(!s->budget--) { s->failed_pc=0x0c0c6b8eu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0c6b90;
P_0c0c6b90: /* original 7550, guest PC 0x0c0c6b90 */
if(!s->budget--) { s->failed_pc=0x0c0c6b90u; return 0; }
r[5]+=0x00000050u;
goto P_0c0c6b92;
P_0c0c6b92: /* original 34bc, guest PC 0x0c0c6b92 */
if(!s->budget--) { s->failed_pc=0x0c0c6b92u; return 0; }
r[4]+=r[11];
goto P_0c0c6b94;
P_0c0c6b94: /* original f758, guest PC 0x0c0c6b94 */
if(!s->budget--) { s->failed_pc=0x0c0c6b94u; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
goto P_0c0c6b96;
P_0c0c6b96: /* original f448, guest PC 0x0c0c6b96 */
if(!s->budget--) { s->failed_pc=0x0c0c6b96u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c6b98;
P_0c0c6b98: /* original f561, guest PC 0x0c0c6b98 */
if(!s->budget--) { s->failed_pc=0x0c0c6b98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0c6b9a;
P_0c0c6b9a: /* original f471, guest PC 0x0c0c6b9a */
if(!s->budget--) { s->failed_pc=0x0c0c6b9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c0c6b9c;
P_0c0c6b9c: /* original f5d1, guest PC 0x0c0c6b9c */
if(!s->budget--) { s->failed_pc=0x0c0c6b9cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'-');
goto P_0c0c6b9e;
P_0c0c6b9e: /* original f4d1, guest PC 0x0c0c6b9e */
if(!s->budget--) { s->failed_pc=0x0c0c6b9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c0c6ba0;
P_0c0c6ba0: /* original f5f5, guest PC 0x0c0c6ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ba0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[15]))!=0);
goto P_0c0c6ba2;
P_0c0c6ba2: /* original 8f04, guest PC 0x0c0c6ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ba2u; return 0; }
cond=r[17]&1u;
r[13]|=r[3];
if(!cond) { goto P_0c0c6bae; }
goto P_0c0c6ba6;
P_0c0c6ba4: /* original 2d3b, guest PC 0x0c0c6ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ba4u; return 0; }
r[13]|=r[3];
goto P_0c0c6ba6;
P_0c0c6ba6: /* original f4f5, guest PC 0x0c0c6ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ba6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c6ba8;
P_0c0c6ba8: /* original 8b01, guest PC 0x0c0c6ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6bae; }
goto P_0c0c6baa;
P_0c0c6baa: /* original 9325, guest PC 0x0c0c6baa */
if(!s->budget--) { s->failed_pc=0x0c0c6baau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bf8u,2);
goto P_0c0c6bac;
P_0c0c6bac: /* original 2d39, guest PC 0x0c0c6bac */
if(!s->budget--) { s->failed_pc=0x0c0c6bacu; return 0; }
r[13]&=r[3];
goto P_0c0c6bae;
P_0c0c6bae: /* original 9424, guest PC 0x0c0c6bae */
if(!s->budget--) { s->failed_pc=0x0c0c6baeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bfau,2);
goto P_0c0c6bb0;
P_0c0c6bb0: /* original d216, guest PC 0x0c0c6bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6bb0u; return 0; }
r[2]=read(ram,0x0c0c6c0cu,4);
goto P_0c0c6bb2;
P_0c0c6bb2: /* original 34bc, guest PC 0x0c0c6bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6bb2u; return 0; }
r[4]+=r[11];
goto P_0c0c6bb4;
P_0c0c6bb4: /* original f448, guest PC 0x0c0c6bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6bb4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c6bb6;
P_0c0c6bb6: /* original 9421, guest PC 0x0c0c6bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bfcu,2);
goto P_0c0c6bb8;
P_0c0c6bb8: /* original 34bc, guest PC 0x0c0c6bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6bb8u; return 0; }
r[4]+=r[11];
goto P_0c0c6bba;
P_0c0c6bba: /* original f548, guest PC 0x0c0c6bba */
if(!s->budget--) { s->failed_pc=0x0c0c6bbau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c0c6bbc;
P_0c0c6bbc: /* original 64f3, guest PC 0x0c0c6bbc */
if(!s->budget--) { s->failed_pc=0x0c0c6bbcu; return 0; }
r[4]=r[15];
goto P_0c0c6bbe;
P_0c0c6bbe: /* original 420b, guest PC 0x0c0c6bbe */
if(!s->budget--) { s->failed_pc=0x0c0c6bbeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6bc2u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6bc2u) { target=s->pc; goto dispatch; }
goto P_0c0c6bc2;
P_0c0c6bc0: /* original 7434, guest PC 0x0c0c6bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c6bc0u; return 0; }
r[4]+=0x00000034u;
goto P_0c0c6bc2;
P_0c0c6bc2: /* original 991c, guest PC 0x0c0c6bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c6bc2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6bfeu,2);
goto P_0c0c6bc4;
P_0c0c6bc4: /* original 6403, guest PC 0x0c0c6bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c6bc4u; return 0; }
r[4]=r[0];
goto P_0c0c6bc6;
P_0c0c6bc6: /* original 24a8, guest PC 0x0c0c6bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c6bc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0c6bc8;
P_0c0c6bc8: /* original 8950, guest PC 0x0c0c6bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c6bc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6c6c; }
goto P_0c0c6bca;
P_0c0c6bca: /* original 53f1, guest PC 0x0c0c6bca */
if(!s->budget--) { s->failed_pc=0x0c0c6bcau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c6bcc;
P_0c0c6bcc: /* original 2388, guest PC 0x0c0c6bcc */
if(!s->budget--) { s->failed_pc=0x0c0c6bccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c6bce;
P_0c0c6bce: /* original 892d, guest PC 0x0c0c6bce */
if(!s->budget--) { s->failed_pc=0x0c0c6bceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6c2c; }
goto P_0c0c6bd0;
P_0c0c6bd0: /* original d50f, guest PC 0x0c0c6bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c6bd0u; return 0; }
r[5]=read(ram,0x0c0c6c10u,4);
goto P_0c0c6bd2;
P_0c0c6bd2: /* original 63f2, guest PC 0x0c0c6bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c6bd2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c6bd4;
P_0c0c6bd4: /* original 6454, guest PC 0x0c0c6bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c6bd4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[4]=tmp;
goto P_0c0c6bd6;
P_0c0c6bd6: /* original 3430, guest PC 0x0c0c6bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c6bd6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c6bd8;
P_0c0c6bd8: /* original 891c, guest PC 0x0c0c6bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c6bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6c14; }
goto P_0c0c6bda;
P_0c0c6bda: /* original 2448, guest PC 0x0c0c6bda */
if(!s->budget--) { s->failed_pc=0x0c0c6bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c6bdc;
P_0c0c6bdc: /* original 8bf9, guest PC 0x0c0c6bdc */
if(!s->budget--) { s->failed_pc=0x0c0c6bdcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6bd2; }
goto P_0c0c6bde;
P_0c0c6bde: /* original a025, guest PC 0x0c0c6bde */
if(!s->budget--) { s->failed_pc=0x0c0c6bdeu; return 0; }
goto P_0c0c6c2c;
P_0c0c6be0: /* original 0009, guest PC 0x0c0c6be0 */
if(!s->budget--) { s->failed_pc=0x0c0c6be0u; return 0; }
if(!vf3_matrix_family(0x0c0c6be2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6be2u; return 0; } return 1;
P_0c0c6c14: /* original 51c3, guest PC 0x0c0c6c14 */
if(!s->budget--) { s->failed_pc=0x0c0c6c14u; return 0; }
r[1]=read(ram,r[12]+12,4);
goto P_0c0c6c16;
P_0c0c6c16: /* original 4111, guest PC 0x0c0c6c16 */
if(!s->budget--) { s->failed_pc=0x0c0c6c16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=0)!=0);
goto P_0c0c6c18;
P_0c0c6c18: /* original 8b08, guest PC 0x0c0c6c18 */
if(!s->budget--) { s->failed_pc=0x0c0c6c18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6c2c; }
goto P_0c0c6c1a;
P_0c0c6c1a: /* original e010, guest PC 0x0c0c6c1a */
if(!s->budget--) { s->failed_pc=0x0c0c6c1au; return 0; }
r[0]=0x00000010u;
goto P_0c0c6c1c;
P_0c0c6c1c: /* original f38d, guest PC 0x0c0c6c1c */
if(!s->budget--) { s->failed_pc=0x0c0c6c1cu; return 0; }
fr[3]=0;
goto P_0c0c6c1e;
P_0c0c6c1e: /* original f2f6, guest PC 0x0c0c6c1e */
if(!s->budget--) { s->failed_pc=0x0c0c6c1eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c6c20;
P_0c0c6c20: /* original 9355, guest PC 0x0c0c6c20 */
if(!s->budget--) { s->failed_pc=0x0c0c6c20u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cceu,2);
goto P_0c0c6c22;
P_0c0c6c22: /* original f235, guest PC 0x0c0c6c22 */
if(!s->budget--) { s->failed_pc=0x0c0c6c22u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0c6c24;
P_0c0c6c24: /* original 8f02, guest PC 0x0c0c6c24 */
if(!s->budget--) { s->failed_pc=0x0c0c6c24u; return 0; }
cond=r[17]&1u;
r[13]|=r[3];
if(!cond) { goto P_0c0c6c2c; }
goto P_0c0c6c28;
P_0c0c6c26: /* original 2d3b, guest PC 0x0c0c6c26 */
if(!s->budget--) { s->failed_pc=0x0c0c6c26u; return 0; }
r[13]|=r[3];
goto P_0c0c6c28;
P_0c0c6c28: /* original e320, guest PC 0x0c0c6c28 */
if(!s->budget--) { s->failed_pc=0x0c0c6c28u; return 0; }
r[3]=0x00000020u;
goto P_0c0c6c2a;
P_0c0c6c2a: /* original 2d3b, guest PC 0x0c0c6c2a */
if(!s->budget--) { s->failed_pc=0x0c0c6c2au; return 0; }
r[13]|=r[3];
goto P_0c0c6c2c;
P_0c0c6c2c: /* original 9050, guest PC 0x0c0c6c2c */
if(!s->budget--) { s->failed_pc=0x0c0c6c2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cd0u,2);
goto P_0c0c6c2e;
P_0c0c6c2e: /* original e202, guest PC 0x0c0c6c2e */
if(!s->budget--) { s->failed_pc=0x0c0c6c2eu; return 0; }
r[2]=0x00000002u;
goto P_0c0c6c30;
P_0c0c6c30: /* original 2d2b, guest PC 0x0c0c6c30 */
if(!s->budget--) { s->failed_pc=0x0c0c6c30u; return 0; }
r[13]|=r[2];
goto P_0c0c6c32;
P_0c0c6c32: /* original f4e6, guest PC 0x0c0c6c32 */
if(!s->budget--) { s->failed_pc=0x0c0c6c32u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6c34;
P_0c0c6c34: /* original 7008, guest PC 0x0c0c6c34 */
if(!s->budget--) { s->failed_pc=0x0c0c6c34u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c6c36;
P_0c0c6c36: /* original f3e6, guest PC 0x0c0c6c36 */
if(!s->budget--) { s->failed_pc=0x0c0c6c36u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c6c38;
P_0c0c6c38: /* original e030, guest PC 0x0c0c6c38 */
if(!s->budget--) { s->failed_pc=0x0c0c6c38u; return 0; }
r[0]=0x00000030u;
goto P_0c0c6c3a;
P_0c0c6c3a: /* original ff37, guest PC 0x0c0c6c3a */
if(!s->budget--) { s->failed_pc=0x0c0c6c3au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6c3c;
P_0c0c6c3c: /* original d329, guest PC 0x0c0c6c3c */
if(!s->budget--) { s->failed_pc=0x0c0c6c3cu; return 0; }
r[3]=read(ram,0x0c0c6ce4u,4);
goto P_0c0c6c3e;
P_0c0c6c3e: /* original f53c, guest PC 0x0c0c6c3e */
if(!s->budget--) { s->failed_pc=0x0c0c6c3eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c6c40;
P_0c0c6c40: /* original 430b, guest PC 0x0c0c6c40 */
if(!s->budget--) { s->failed_pc=0x0c0c6c40u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6c44u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6c44u) { target=s->pc; goto dispatch; }
goto P_0c0c6c44;
P_0c0c6c42: /* original f54d, guest PC 0x0c0c6c42 */
if(!s->budget--) { s->failed_pc=0x0c0c6c42u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c6c44;
P_0c0c6c44: /* original 9045, guest PC 0x0c0c6c44 */
if(!s->budget--) { s->failed_pc=0x0c0c6c44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cd2u,2);
goto P_0c0c6c46;
P_0c0c6c46: /* original d329, guest PC 0x0c0c6c46 */
if(!s->budget--) { s->failed_pc=0x0c0c6c46u; return 0; }
r[3]=read(ram,0x0c0c6cecu,4);
goto P_0c0c6c48;
P_0c0c6c48: /* original f6e6, guest PC 0x0c0c6c48 */
if(!s->budget--) { s->failed_pc=0x0c0c6c48u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c6c4a;
P_0c0c6c4a: /* original c727, guest PC 0x0c0c6c4a */
if(!s->budget--) { s->failed_pc=0x0c0c6c4au; return 0; }
r[0]=code_base|0x000c6ce8u;
goto P_0c0c6c4c;
P_0c0c6c4c: /* original f508, guest PC 0x0c0c6c4c */
if(!s->budget--) { s->failed_pc=0x0c0c6c4cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6c4e;
P_0c0c6c4e: /* original f40c, guest PC 0x0c0c6c4e */
if(!s->budget--) { s->failed_pc=0x0c0c6c4eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c6c50;
P_0c0c6c50: /* original 430b, guest PC 0x0c0c6c50 */
if(!s->budget--) { s->failed_pc=0x0c0c6c50u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6c54u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6c54u) { target=s->pc; goto dispatch; }
goto P_0c0c6c54;
P_0c0c6c52: /* original f461, guest PC 0x0c0c6c52 */
if(!s->budget--) { s->failed_pc=0x0c0c6c52u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0c6c54;
P_0c0c6c54: /* original 923e, guest PC 0x0c0c6c54 */
if(!s->budget--) { s->failed_pc=0x0c0c6c54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cd4u,2);
goto P_0c0c6c56;
P_0c0c6c56: /* original 600f, guest PC 0x0c0c6c56 */
if(!s->budget--) { s->failed_pc=0x0c0c6c56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6c58;
P_0c0c6c58: /* original 640f, guest PC 0x0c0c6c58 */
if(!s->budget--) { s->failed_pc=0x0c0c6c58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6c5a;
P_0c0c6c5a: /* original 3427, guest PC 0x0c0c6c5a */
if(!s->budget--) { s->failed_pc=0x0c0c6c5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0c6c5c;
P_0c0c6c5c: /* original 8b01, guest PC 0x0c0c6c5c */
if(!s->budget--) { s->failed_pc=0x0c0c6c5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6c62; }
goto P_0c0c6c5e;
P_0c0c6c5e: /* original a003, guest PC 0x0c0c6c5e */
if(!s->budget--) { s->failed_pc=0x0c0c6c5eu; return 0; }
r[4]=r[2];
goto P_0c0c6c68;
P_0c0c6c60: /* original 6423, guest PC 0x0c0c6c60 */
if(!s->budget--) { s->failed_pc=0x0c0c6c60u; return 0; }
r[4]=r[2];
goto P_0c0c6c62;
P_0c0c6c62: /* original 3493, guest PC 0x0c0c6c62 */
if(!s->budget--) { s->failed_pc=0x0c0c6c62u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[9])!=0);
goto P_0c0c6c64;
P_0c0c6c64: /* original 8900, guest PC 0x0c0c6c64 */
if(!s->budget--) { s->failed_pc=0x0c0c6c64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6c68; }
goto P_0c0c6c66;
P_0c0c6c66: /* original 6493, guest PC 0x0c0c6c66 */
if(!s->budget--) { s->failed_pc=0x0c0c6c66u; return 0; }
r[4]=r[9];
goto P_0c0c6c68;
P_0c0c6c68: /* original 9035, guest PC 0x0c0c6c68 */
if(!s->budget--) { s->failed_pc=0x0c0c6c68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cd6u,2);
goto P_0c0c6c6a;
P_0c0c6c6a: /* original 0e45, guest PC 0x0c0c6c6a */
if(!s->budget--) { s->failed_pc=0x0c0c6c6au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0c6c6c;
P_0c0c6c6c: /* original 9534, guest PC 0x0c0c6c6c */
if(!s->budget--) { s->failed_pc=0x0c0c6c6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cd8u,2);
goto P_0c0c6c6e;
P_0c0c6c6e: /* original e068, guest PC 0x0c0c6c6e */
if(!s->budget--) { s->failed_pc=0x0c0c6c6eu; return 0; }
r[0]=0x00000068u;
goto P_0c0c6c70;
P_0c0c6c70: /* original 9433, guest PC 0x0c0c6c70 */
if(!s->budget--) { s->failed_pc=0x0c0c6c70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cdau,2);
goto P_0c0c6c72;
P_0c0c6c72: /* original 35ec, guest PC 0x0c0c6c72 */
if(!s->budget--) { s->failed_pc=0x0c0c6c72u; return 0; }
r[5]+=r[14];
goto P_0c0c6c74;
P_0c0c6c74: /* original 9332, guest PC 0x0c0c6c74 */
if(!s->budget--) { s->failed_pc=0x0c0c6c74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cdcu,2);
goto P_0c0c6c76;
P_0c0c6c76: /* original f556, guest PC 0x0c0c6c76 */
if(!s->budget--) { s->failed_pc=0x0c0c6c76u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0c6c78;
P_0c0c6c78: /* original e014, guest PC 0x0c0c6c78 */
if(!s->budget--) { s->failed_pc=0x0c0c6c78u; return 0; }
r[0]=0x00000014u;
goto P_0c0c6c7a;
P_0c0c6c7a: /* original 34bc, guest PC 0x0c0c6c7a */
if(!s->budget--) { s->failed_pc=0x0c0c6c7au; return 0; }
r[4]+=r[11];
goto P_0c0c6c7c;
P_0c0c6c7c: /* original f35c, guest PC 0x0c0c6c7c */
if(!s->budget--) { s->failed_pc=0x0c0c6c7cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0c6c7e;
P_0c0c6c7e: /* original 756c, guest PC 0x0c0c6c7e */
if(!s->budget--) { s->failed_pc=0x0c0c6c7eu; return 0; }
r[5]+=0x0000006cu;
goto P_0c0c6c80;
P_0c0c6c80: /* original f5f6, guest PC 0x0c0c6c80 */
if(!s->budget--) { s->failed_pc=0x0c0c6c80u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c6c82;
P_0c0c6c82: /* original f448, guest PC 0x0c0c6c82 */
if(!s->budget--) { s->failed_pc=0x0c0c6c82u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c6c84;
P_0c0c6c84: /* original f531, guest PC 0x0c0c6c84 */
if(!s->budget--) { s->failed_pc=0x0c0c6c84u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0c6c86;
P_0c0c6c86: /* original f658, guest PC 0x0c0c6c86 */
if(!s->budget--) { s->failed_pc=0x0c0c6c86u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c0c6c88;
P_0c0c6c88: /* original f461, guest PC 0x0c0c6c88 */
if(!s->budget--) { s->failed_pc=0x0c0c6c88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0c6c8a;
P_0c0c6c8a: /* original f5d1, guest PC 0x0c0c6c8a */
if(!s->budget--) { s->failed_pc=0x0c0c6c8au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'-');
goto P_0c0c6c8c;
P_0c0c6c8c: /* original f4d1, guest PC 0x0c0c6c8c */
if(!s->budget--) { s->failed_pc=0x0c0c6c8cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c0c6c8e;
P_0c0c6c8e: /* original f5e5, guest PC 0x0c0c6c8e */
if(!s->budget--) { s->failed_pc=0x0c0c6c8eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[14]))!=0);
goto P_0c0c6c90;
P_0c0c6c90: /* original 8f04, guest PC 0x0c0c6c90 */
if(!s->budget--) { s->failed_pc=0x0c0c6c90u; return 0; }
cond=r[17]&1u;
r[13]|=r[3];
if(!cond) { goto P_0c0c6c9c; }
goto P_0c0c6c94;
P_0c0c6c92: /* original 2d3b, guest PC 0x0c0c6c92 */
if(!s->budget--) { s->failed_pc=0x0c0c6c92u; return 0; }
r[13]|=r[3];
goto P_0c0c6c94;
P_0c0c6c94: /* original f4e5, guest PC 0x0c0c6c94 */
if(!s->budget--) { s->failed_pc=0x0c0c6c94u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[14]))!=0);
goto P_0c0c6c96;
P_0c0c6c96: /* original 8b01, guest PC 0x0c0c6c96 */
if(!s->budget--) { s->failed_pc=0x0c0c6c96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6c9c; }
goto P_0c0c6c98;
P_0c0c6c98: /* original 9321, guest PC 0x0c0c6c98 */
if(!s->budget--) { s->failed_pc=0x0c0c6c98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6cdeu,2);
goto P_0c0c6c9a;
P_0c0c6c9a: /* original 2d39, guest PC 0x0c0c6c9a */
if(!s->budget--) { s->failed_pc=0x0c0c6c9au; return 0; }
r[13]&=r[3];
goto P_0c0c6c9c;
P_0c0c6c9c: /* original 9420, guest PC 0x0c0c6c9c */
if(!s->budget--) { s->failed_pc=0x0c0c6c9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ce0u,2);
goto P_0c0c6c9e;
P_0c0c6c9e: /* original d214, guest PC 0x0c0c6c9e */
if(!s->budget--) { s->failed_pc=0x0c0c6c9eu; return 0; }
r[2]=read(ram,0x0c0c6cf0u,4);
goto P_0c0c6ca0;
P_0c0c6ca0: /* original 34bc, guest PC 0x0c0c6ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ca0u; return 0; }
r[4]+=r[11];
goto P_0c0c6ca2;
P_0c0c6ca2: /* original f448, guest PC 0x0c0c6ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ca2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c6ca4;
P_0c0c6ca4: /* original 941d, guest PC 0x0c0c6ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ca4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ce2u,2);
goto P_0c0c6ca6;
P_0c0c6ca6: /* original 34bc, guest PC 0x0c0c6ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ca6u; return 0; }
r[4]+=r[11];
goto P_0c0c6ca8;
P_0c0c6ca8: /* original f548, guest PC 0x0c0c6ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ca8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c0c6caa;
P_0c0c6caa: /* original 64f3, guest PC 0x0c0c6caa */
if(!s->budget--) { s->failed_pc=0x0c0c6caau; return 0; }
r[4]=r[15];
goto P_0c0c6cac;
P_0c0c6cac: /* original 420b, guest PC 0x0c0c6cac */
if(!s->budget--) { s->failed_pc=0x0c0c6cacu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6cb0u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6cb0u) { target=s->pc; goto dispatch; }
goto P_0c0c6cb0;
P_0c0c6cae: /* original 7434, guest PC 0x0c0c6cae */
if(!s->budget--) { s->failed_pc=0x0c0c6caeu; return 0; }
r[4]+=0x00000034u;
goto P_0c0c6cb0;
P_0c0c6cb0: /* original 6403, guest PC 0x0c0c6cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6cb0u; return 0; }
r[4]=r[0];
goto P_0c0c6cb2;
P_0c0c6cb2: /* original 24a8, guest PC 0x0c0c6cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6cb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0c6cb4;
P_0c0c6cb4: /* original 894b, guest PC 0x0c0c6cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6cb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d4e; }
goto P_0c0c6cb6;
P_0c0c6cb6: /* original 53f1, guest PC 0x0c0c6cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6cb6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c6cb8;
P_0c0c6cb8: /* original 2388, guest PC 0x0c0c6cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6cb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c6cba;
P_0c0c6cba: /* original 8929, guest PC 0x0c0c6cba */
if(!s->budget--) { s->failed_pc=0x0c0c6cbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d10; }
goto P_0c0c6cbc;
P_0c0c6cbc: /* original d50d, guest PC 0x0c0c6cbc */
if(!s->budget--) { s->failed_pc=0x0c0c6cbcu; return 0; }
r[5]=read(ram,0x0c0c6cf4u,4);
goto P_0c0c6cbe;
P_0c0c6cbe: /* original 63f2, guest PC 0x0c0c6cbe */
if(!s->budget--) { s->failed_pc=0x0c0c6cbeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c6cc0;
P_0c0c6cc0: /* original 6454, guest PC 0x0c0c6cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c6cc0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[4]=tmp;
goto P_0c0c6cc2;
P_0c0c6cc2: /* original 3430, guest PC 0x0c0c6cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c6cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0c6cc4;
P_0c0c6cc4: /* original 8918, guest PC 0x0c0c6cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c6cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6cf8; }
goto P_0c0c6cc6;
P_0c0c6cc6: /* original 2448, guest PC 0x0c0c6cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c6cc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c6cc8;
P_0c0c6cc8: /* original 8bf9, guest PC 0x0c0c6cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c6cc8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6cbe; }
goto P_0c0c6cca;
P_0c0c6cca: /* original a021, guest PC 0x0c0c6cca */
if(!s->budget--) { s->failed_pc=0x0c0c6ccau; return 0; }
goto P_0c0c6d10;
P_0c0c6ccc: /* original 0009, guest PC 0x0c0c6ccc */
if(!s->budget--) { s->failed_pc=0x0c0c6cccu; return 0; }
if(!vf3_matrix_family(0x0c0c6cceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6cceu; return 0; } return 1;
P_0c0c6cf8: /* original 51c3, guest PC 0x0c0c6cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c6cf8u; return 0; }
r[1]=read(ram,r[12]+12,4);
goto P_0c0c6cfa;
P_0c0c6cfa: /* original 4111, guest PC 0x0c0c6cfa */
if(!s->budget--) { s->failed_pc=0x0c0c6cfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=0)!=0);
goto P_0c0c6cfc;
P_0c0c6cfc: /* original 8b08, guest PC 0x0c0c6cfc */
if(!s->budget--) { s->failed_pc=0x0c0c6cfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6d10; }
goto P_0c0c6cfe;
P_0c0c6cfe: /* original e010, guest PC 0x0c0c6cfe */
if(!s->budget--) { s->failed_pc=0x0c0c6cfeu; return 0; }
r[0]=0x00000010u;
goto P_0c0c6d00;
P_0c0c6d00: /* original f38d, guest PC 0x0c0c6d00 */
if(!s->budget--) { s->failed_pc=0x0c0c6d00u; return 0; }
fr[3]=0;
goto P_0c0c6d02;
P_0c0c6d02: /* original f2f6, guest PC 0x0c0c6d02 */
if(!s->budget--) { s->failed_pc=0x0c0c6d02u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c6d04;
P_0c0c6d04: /* original 9363, guest PC 0x0c0c6d04 */
if(!s->budget--) { s->failed_pc=0x0c0c6d04u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dceu,2);
goto P_0c0c6d06;
P_0c0c6d06: /* original f235, guest PC 0x0c0c6d06 */
if(!s->budget--) { s->failed_pc=0x0c0c6d06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0c6d08;
P_0c0c6d08: /* original 8f02, guest PC 0x0c0c6d08 */
if(!s->budget--) { s->failed_pc=0x0c0c6d08u; return 0; }
cond=r[17]&1u;
r[13]|=r[3];
if(!cond) { goto P_0c0c6d10; }
goto P_0c0c6d0c;
P_0c0c6d0a: /* original 2d3b, guest PC 0x0c0c6d0a */
if(!s->budget--) { s->failed_pc=0x0c0c6d0au; return 0; }
r[13]|=r[3];
goto P_0c0c6d0c;
P_0c0c6d0c: /* original e320, guest PC 0x0c0c6d0c */
if(!s->budget--) { s->failed_pc=0x0c0c6d0cu; return 0; }
r[3]=0x00000020u;
goto P_0c0c6d0e;
P_0c0c6d0e: /* original 2d3b, guest PC 0x0c0c6d0e */
if(!s->budget--) { s->failed_pc=0x0c0c6d0eu; return 0; }
r[13]|=r[3];
goto P_0c0c6d10;
P_0c0c6d10: /* original 905e, guest PC 0x0c0c6d10 */
if(!s->budget--) { s->failed_pc=0x0c0c6d10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dd0u,2);
goto P_0c0c6d12;
P_0c0c6d12: /* original 2dab, guest PC 0x0c0c6d12 */
if(!s->budget--) { s->failed_pc=0x0c0c6d12u; return 0; }
r[13]|=r[10];
goto P_0c0c6d14;
P_0c0c6d14: /* original f4e6, guest PC 0x0c0c6d14 */
if(!s->budget--) { s->failed_pc=0x0c0c6d14u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6d16;
P_0c0c6d16: /* original 7008, guest PC 0x0c0c6d16 */
if(!s->budget--) { s->failed_pc=0x0c0c6d16u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c6d18;
P_0c0c6d18: /* original f3e6, guest PC 0x0c0c6d18 */
if(!s->budget--) { s->failed_pc=0x0c0c6d18u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c6d1a;
P_0c0c6d1a: /* original e024, guest PC 0x0c0c6d1a */
if(!s->budget--) { s->failed_pc=0x0c0c6d1au; return 0; }
r[0]=0x00000024u;
goto P_0c0c6d1c;
P_0c0c6d1c: /* original ff37, guest PC 0x0c0c6d1c */
if(!s->budget--) { s->failed_pc=0x0c0c6d1cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c6d1e;
P_0c0c6d1e: /* original d331, guest PC 0x0c0c6d1e */
if(!s->budget--) { s->failed_pc=0x0c0c6d1eu; return 0; }
r[3]=read(ram,0x0c0c6de4u,4);
goto P_0c0c6d20;
P_0c0c6d20: /* original f53c, guest PC 0x0c0c6d20 */
if(!s->budget--) { s->failed_pc=0x0c0c6d20u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c6d22;
P_0c0c6d22: /* original 430b, guest PC 0x0c0c6d22 */
if(!s->budget--) { s->failed_pc=0x0c0c6d22u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6d26u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6d26u) { target=s->pc; goto dispatch; }
goto P_0c0c6d26;
P_0c0c6d24: /* original f54d, guest PC 0x0c0c6d24 */
if(!s->budget--) { s->failed_pc=0x0c0c6d24u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c6d26;
P_0c0c6d26: /* original 9054, guest PC 0x0c0c6d26 */
if(!s->budget--) { s->failed_pc=0x0c0c6d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dd2u,2);
goto P_0c0c6d28;
P_0c0c6d28: /* original d330, guest PC 0x0c0c6d28 */
if(!s->budget--) { s->failed_pc=0x0c0c6d28u; return 0; }
r[3]=read(ram,0x0c0c6decu,4);
goto P_0c0c6d2a;
P_0c0c6d2a: /* original f6e6, guest PC 0x0c0c6d2a */
if(!s->budget--) { s->failed_pc=0x0c0c6d2au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c6d2c;
P_0c0c6d2c: /* original c72e, guest PC 0x0c0c6d2c */
if(!s->budget--) { s->failed_pc=0x0c0c6d2cu; return 0; }
r[0]=code_base|0x000c6de8u;
goto P_0c0c6d2e;
P_0c0c6d2e: /* original f508, guest PC 0x0c0c6d2e */
if(!s->budget--) { s->failed_pc=0x0c0c6d2eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6d30;
P_0c0c6d30: /* original f40c, guest PC 0x0c0c6d30 */
if(!s->budget--) { s->failed_pc=0x0c0c6d30u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c6d32;
P_0c0c6d32: /* original 430b, guest PC 0x0c0c6d32 */
if(!s->budget--) { s->failed_pc=0x0c0c6d32u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6d36u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6d36u) { target=s->pc; goto dispatch; }
goto P_0c0c6d36;
P_0c0c6d34: /* original f461, guest PC 0x0c0c6d34 */
if(!s->budget--) { s->failed_pc=0x0c0c6d34u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0c6d36;
P_0c0c6d36: /* original 924d, guest PC 0x0c0c6d36 */
if(!s->budget--) { s->failed_pc=0x0c0c6d36u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dd4u,2);
goto P_0c0c6d38;
P_0c0c6d38: /* original 600f, guest PC 0x0c0c6d38 */
if(!s->budget--) { s->failed_pc=0x0c0c6d38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6d3a;
P_0c0c6d3a: /* original 640f, guest PC 0x0c0c6d3a */
if(!s->budget--) { s->failed_pc=0x0c0c6d3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c6d3c;
P_0c0c6d3c: /* original 3427, guest PC 0x0c0c6d3c */
if(!s->budget--) { s->failed_pc=0x0c0c6d3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c0c6d3e;
P_0c0c6d3e: /* original 8b01, guest PC 0x0c0c6d3e */
if(!s->budget--) { s->failed_pc=0x0c0c6d3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6d44; }
goto P_0c0c6d40;
P_0c0c6d40: /* original a003, guest PC 0x0c0c6d40 */
if(!s->budget--) { s->failed_pc=0x0c0c6d40u; return 0; }
r[4]=r[2];
goto P_0c0c6d4a;
P_0c0c6d42: /* original 6423, guest PC 0x0c0c6d42 */
if(!s->budget--) { s->failed_pc=0x0c0c6d42u; return 0; }
r[4]=r[2];
goto P_0c0c6d44;
P_0c0c6d44: /* original 3493, guest PC 0x0c0c6d44 */
if(!s->budget--) { s->failed_pc=0x0c0c6d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[9])!=0);
goto P_0c0c6d46;
P_0c0c6d46: /* original 8900, guest PC 0x0c0c6d46 */
if(!s->budget--) { s->failed_pc=0x0c0c6d46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d4a; }
goto P_0c0c6d48;
P_0c0c6d48: /* original 6493, guest PC 0x0c0c6d48 */
if(!s->budget--) { s->failed_pc=0x0c0c6d48u; return 0; }
r[4]=r[9];
goto P_0c0c6d4a;
P_0c0c6d4a: /* original 9044, guest PC 0x0c0c6d4a */
if(!s->budget--) { s->failed_pc=0x0c0c6d4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dd6u,2);
goto P_0c0c6d4c;
P_0c0c6d4c: /* original 0e45, guest PC 0x0c0c6d4c */
if(!s->budget--) { s->failed_pc=0x0c0c6d4cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0c6d4e;
P_0c0c6d4e: /* original e406, guest PC 0x0c0c6d4e */
if(!s->budget--) { s->failed_pc=0x0c0c6d4eu; return 0; }
r[4]=0x00000006u;
goto P_0c0c6d50;
P_0c0c6d50: /* original 24d9, guest PC 0x0c0c6d50 */
if(!s->budget--) { s->failed_pc=0x0c0c6d50u; return 0; }
r[4]&=r[13];
goto P_0c0c6d52;
P_0c0c6d52: /* original 6043, guest PC 0x0c0c6d52 */
if(!s->budget--) { s->failed_pc=0x0c0c6d52u; return 0; }
r[0]=r[4];
goto P_0c0c6d54;
P_0c0c6d54: /* original 8806, guest PC 0x0c0c6d54 */
if(!s->budget--) { s->failed_pc=0x0c0c6d54u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c6d56;
P_0c0c6d56: /* original 8b51, guest PC 0x0c0c6d56 */
if(!s->budget--) { s->failed_pc=0x0c0c6d56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6dfc; }
goto P_0c0c6d58;
P_0c0c6d58: /* original 933e, guest PC 0x0c0c6d58 */
if(!s->budget--) { s->failed_pc=0x0c0c6d58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dd8u,2);
goto P_0c0c6d5a;
P_0c0c6d5a: /* original 23d8, guest PC 0x0c0c6d5a */
if(!s->budget--) { s->failed_pc=0x0c0c6d5au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6d5c;
P_0c0c6d5c: /* original 8b12, guest PC 0x0c0c6d5c */
if(!s->budget--) { s->failed_pc=0x0c0c6d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6d84; }
goto P_0c0c6d5e;
P_0c0c6d5e: /* original 9136, guest PC 0x0c0c6d5e */
if(!s->budget--) { s->failed_pc=0x0c0c6d5eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6dceu,2);
goto P_0c0c6d60;
P_0c0c6d60: /* original 21d8, guest PC 0x0c0c6d60 */
if(!s->budget--) { s->failed_pc=0x0c0c6d60u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c0c6d62;
P_0c0c6d62: /* original 8b0a, guest PC 0x0c0c6d62 */
if(!s->budget--) { s->failed_pc=0x0c0c6d62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6d7a; }
goto P_0c0c6d64;
P_0c0c6d64: /* original e320, guest PC 0x0c0c6d64 */
if(!s->budget--) { s->failed_pc=0x0c0c6d64u; return 0; }
r[3]=0x00000020u;
goto P_0c0c6d66;
P_0c0c6d66: /* original 23d8, guest PC 0x0c0c6d66 */
if(!s->budget--) { s->failed_pc=0x0c0c6d66u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6d68;
P_0c0c6d68: /* original 890e, guest PC 0x0c0c6d68 */
if(!s->budget--) { s->failed_pc=0x0c0c6d68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d88; }
goto P_0c0c6d6a;
P_0c0c6d6a: /* original 9436, guest PC 0x0c0c6d6a */
if(!s->budget--) { s->failed_pc=0x0c0c6d6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ddau,2);
goto P_0c0c6d6c;
P_0c0c6d6c: /* original 6543, guest PC 0x0c0c6d6c */
if(!s->budget--) { s->failed_pc=0x0c0c6d6cu; return 0; }
r[5]=r[4];
goto P_0c0c6d6e;
P_0c0c6d6e: /* original 25d9, guest PC 0x0c0c6d6e */
if(!s->budget--) { s->failed_pc=0x0c0c6d6eu; return 0; }
r[5]&=r[13];
goto P_0c0c6d70;
P_0c0c6d70: /* original 3540, guest PC 0x0c0c6d70 */
if(!s->budget--) { s->failed_pc=0x0c0c6d70u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0c6d72;
P_0c0c6d72: /* original 8909, guest PC 0x0c0c6d72 */
if(!s->budget--) { s->failed_pc=0x0c0c6d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d88; }
goto P_0c0c6d74;
P_0c0c6d74: /* original 9332, guest PC 0x0c0c6d74 */
if(!s->budget--) { s->failed_pc=0x0c0c6d74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ddcu,2);
goto P_0c0c6d76;
P_0c0c6d76: /* original 23d8, guest PC 0x0c0c6d76 */
if(!s->budget--) { s->failed_pc=0x0c0c6d76u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6d78;
P_0c0c6d78: /* original 8901, guest PC 0x0c0c6d78 */
if(!s->budget--) { s->failed_pc=0x0c0c6d78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d7e; }
goto P_0c0c6d7a;
P_0c0c6d7a: /* original a044, guest PC 0x0c0c6d7a */
if(!s->budget--) { s->failed_pc=0x0c0c6d7au; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c0c6e06;
P_0c0c6d7c: /* original fdfc, guest PC 0x0c0c6d7c */
if(!s->budget--) { s->failed_pc=0x0c0c6d7cu; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c0c6d7e;
P_0c0c6d7e: /* original 922e, guest PC 0x0c0c6d7e */
if(!s->budget--) { s->failed_pc=0x0c0c6d7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ddeu,2);
goto P_0c0c6d80;
P_0c0c6d80: /* original 22d8, guest PC 0x0c0c6d80 */
if(!s->budget--) { s->failed_pc=0x0c0c6d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6d82;
P_0c0c6d82: /* original 8901, guest PC 0x0c0c6d82 */
if(!s->budget--) { s->failed_pc=0x0c0c6d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6d88; }
goto P_0c0c6d84;
P_0c0c6d84: /* original a03f, guest PC 0x0c0c6d84 */
if(!s->budget--) { s->failed_pc=0x0c0c6d84u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0c6e06;
P_0c0c6d86: /* original fdec, guest PC 0x0c0c6d86 */
if(!s->budget--) { s->failed_pc=0x0c0c6d86u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0c6d88;
P_0c0c6d88: /* original 902a, guest PC 0x0c0c6d88 */
if(!s->budget--) { s->failed_pc=0x0c0c6d88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6de0u,2);
goto P_0c0c6d8a;
P_0c0c6d8a: /* original 65e2, guest PC 0x0c0c6d8a */
if(!s->budget--) { s->failed_pc=0x0c0c6d8au; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0c6d8c;
P_0c0c6d8c: /* original 04ee, guest PC 0x0c0c6d8c */
if(!s->budget--) { s->failed_pc=0x0c0c6d8cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c6d8e;
P_0c0c6d8e: /* original c718, guest PC 0x0c0c6d8e */
if(!s->budget--) { s->failed_pc=0x0c0c6d8eu; return 0; }
r[0]=code_base|0x000c6df0u;
goto P_0c0c6d90;
P_0c0c6d90: /* original 2588, guest PC 0x0c0c6d90 */
if(!s->budget--) { s->failed_pc=0x0c0c6d90u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[8])==0)!=0);
goto P_0c0c6d92;
P_0c0c6d92: /* original 8d06, guest PC 0x0c0c6d92 */
if(!s->budget--) { s->failed_pc=0x0c0c6d92u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0c6da2; }
goto P_0c0c6d96;
P_0c0c6d94: /* original f408, guest PC 0x0c0c6d94 */
if(!s->budget--) { s->failed_pc=0x0c0c6d94u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c6d96;
P_0c0c6d96: /* original 2488, guest PC 0x0c0c6d96 */
if(!s->budget--) { s->failed_pc=0x0c0c6d96u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0c6d98;
P_0c0c6d98: /* original c716, guest PC 0x0c0c6d98 */
if(!s->budget--) { s->failed_pc=0x0c0c6d98u; return 0; }
r[0]=code_base|0x000c6df4u;
goto P_0c0c6d9a;
P_0c0c6d9a: /* original 8f06, guest PC 0x0c0c6d9a */
if(!s->budget--) { s->failed_pc=0x0c0c6d9au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(!cond) { goto P_0c0c6daa; }
goto P_0c0c6d9e;
P_0c0c6d9c: /* original f408, guest PC 0x0c0c6d9c */
if(!s->budget--) { s->failed_pc=0x0c0c6d9cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c6d9e;
P_0c0c6d9e: /* original c716, guest PC 0x0c0c6d9e */
if(!s->budget--) { s->failed_pc=0x0c0c6d9eu; return 0; }
r[0]=code_base|0x000c6df8u;
goto P_0c0c6da0;
P_0c0c6da0: /* original f408, guest PC 0x0c0c6da0 */
if(!s->budget--) { s->failed_pc=0x0c0c6da0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c6da2;
P_0c0c6da2: /* original e061, guest PC 0x0c0c6da2 */
if(!s->budget--) { s->failed_pc=0x0c0c6da2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c6da4;
P_0c0c6da4: /* original 00ec, guest PC 0x0c0c6da4 */
if(!s->budget--) { s->failed_pc=0x0c0c6da4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c6da6;
P_0c0c6da6: /* original 600c, guest PC 0x0c0c6da6 */
if(!s->budget--) { s->failed_pc=0x0c0c6da6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c6da8;
P_0c0c6da8: /* original 8801, guest PC 0x0c0c6da8 */
if(!s->budget--) { s->failed_pc=0x0c0c6da8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c6daa;
P_0c0c6daa: /* original f5cc, guest PC 0x0c0c6daa */
if(!s->budget--) { s->failed_pc=0x0c0c6daau; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0c6dac;
P_0c0c6dac: /* original f38d, guest PC 0x0c0c6dac */
if(!s->budget--) { s->failed_pc=0x0c0c6dacu; return 0; }
fr[3]=0;
goto P_0c0c6dae;
P_0c0c6dae: /* original f355, guest PC 0x0c0c6dae */
if(!s->budget--) { s->failed_pc=0x0c0c6daeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0c6db0;
P_0c0c6db0: /* original 8d02, guest PC 0x0c0c6db0 */
if(!s->budget--) { s->failed_pc=0x0c0c6db0u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(cond) { goto P_0c0c6db8; }
goto P_0c0c6db4;
P_0c0c6db2: /* original f38d, guest PC 0x0c0c6db2 */
if(!s->budget--) { s->failed_pc=0x0c0c6db2u; return 0; }
fr[3]=0;
goto P_0c0c6db4;
P_0c0c6db4: /* original a001, guest PC 0x0c0c6db4 */
if(!s->budget--) { s->failed_pc=0x0c0c6db4u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c6dba;
P_0c0c6db6: /* original f6ec, guest PC 0x0c0c6db6 */
if(!s->budget--) { s->failed_pc=0x0c0c6db6u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c6db8;
P_0c0c6db8: /* original f6fc, guest PC 0x0c0c6db8 */
if(!s->budget--) { s->failed_pc=0x0c0c6db8u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c6dba;
P_0c0c6dba: /* original f355, guest PC 0x0c0c6dba */
if(!s->budget--) { s->failed_pc=0x0c0c6dbau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0c6dbc;
P_0c0c6dbc: /* original 8901, guest PC 0x0c0c6dbc */
if(!s->budget--) { s->failed_pc=0x0c0c6dbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6dc2; }
goto P_0c0c6dbe;
P_0c0c6dbe: /* original a001, guest PC 0x0c0c6dbe */
if(!s->budget--) { s->failed_pc=0x0c0c6dbeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6dc4;
P_0c0c6dc0: /* original f5fc, guest PC 0x0c0c6dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c6dc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6dc2;
P_0c0c6dc2: /* original f5ec, guest PC 0x0c0c6dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c6dc2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c6dc4;
P_0c0c6dc4: /* original f561, guest PC 0x0c0c6dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c6dc4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0c6dc6;
P_0c0c6dc6: /* original f04c, guest PC 0x0c0c6dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c6dc6u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0c6dc8;
P_0c0c6dc8: /* original f65e, guest PC 0x0c0c6dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c6dc8u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[5],fr[6],r[18]);
goto P_0c0c6dca;
P_0c0c6dca: /* original a01c, guest PC 0x0c0c6dca */
if(!s->budget--) { s->failed_pc=0x0c0c6dcau; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c0c6e06;
P_0c0c6dcc: /* original fd6c, guest PC 0x0c0c6dcc */
if(!s->budget--) { s->failed_pc=0x0c0c6dccu; return 0; }
vf3_matrix_move(s,13,6);
if(!vf3_matrix_family(0x0c0c6dceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6dceu; return 0; } return 1;
P_0c0c6dfc: /* original e202, guest PC 0x0c0c6dfc */
if(!s->budget--) { s->failed_pc=0x0c0c6dfcu; return 0; }
r[2]=0x00000002u;
goto P_0c0c6dfe;
P_0c0c6dfe: /* original 22d8, guest PC 0x0c0c6dfe */
if(!s->budget--) { s->failed_pc=0x0c0c6dfeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6e00;
P_0c0c6e00: /* original 8f01, guest PC 0x0c0c6e00 */
if(!s->budget--) { s->failed_pc=0x0c0c6e00u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c0c6e06; }
goto P_0c0c6e04;
P_0c0c6e02: /* original fdfc, guest PC 0x0c0c6e02 */
if(!s->budget--) { s->failed_pc=0x0c0c6e02u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c0c6e04;
P_0c0c6e04: /* original fdec, guest PC 0x0c0c6e04 */
if(!s->budget--) { s->failed_pc=0x0c0c6e04u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0c6e06;
P_0c0c6e06: /* original e014, guest PC 0x0c0c6e06 */
if(!s->budget--) { s->failed_pc=0x0c0c6e06u; return 0; }
r[0]=0x00000014u;
goto P_0c0c6e08;
P_0c0c6e08: /* original f4dc, guest PC 0x0c0c6e08 */
if(!s->budget--) { s->failed_pc=0x0c0c6e08u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c6e0a;
P_0c0c6e0a: /* original f3e6, guest PC 0x0c0c6e0a */
if(!s->budget--) { s->failed_pc=0x0c0c6e0au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c6e0c;
P_0c0c6e0c: /* original e048, guest PC 0x0c0c6e0c */
if(!s->budget--) { s->failed_pc=0x0c0c6e0cu; return 0; }
r[0]=0x00000048u;
goto P_0c0c6e0e;
P_0c0c6e0e: /* original 04ee, guest PC 0x0c0c6e0e */
if(!s->budget--) { s->failed_pc=0x0c0c6e0eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c6e10;
P_0c0c6e10: /* original e04c, guest PC 0x0c0c6e10 */
if(!s->budget--) { s->failed_pc=0x0c0c6e10u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c6e12;
P_0c0c6e12: /* original f431, guest PC 0x0c0c6e12 */
if(!s->budget--) { s->failed_pc=0x0c0c6e12u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0c6e14;
P_0c0c6e14: /* original 05ee, guest PC 0x0c0c6e14 */
if(!s->budget--) { s->failed_pc=0x0c0c6e14u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c6e16;
P_0c0c6e16: /* original 6343, guest PC 0x0c0c6e16 */
if(!s->budget--) { s->failed_pc=0x0c0c6e16u; return 0; }
r[3]=r[4];
goto P_0c0c6e18;
P_0c0c6e18: /* original 23a8, guest PC 0x0c0c6e18 */
if(!s->budget--) { s->failed_pc=0x0c0c6e18u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0c6e1a;
P_0c0c6e1a: /* original c737, guest PC 0x0c0c6e1a */
if(!s->budget--) { s->failed_pc=0x0c0c6e1au; return 0; }
r[0]=code_base|0x000c6ef8u;
goto P_0c0c6e1c;
P_0c0c6e1c: /* original 8f09, guest PC 0x0c0c6e1c */
if(!s->budget--) { s->failed_pc=0x0c0c6e1cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,5,r[0]);
if(!cond) { goto P_0c0c6e32; }
goto P_0c0c6e20;
P_0c0c6e1e: /* original f508, guest PC 0x0c0c6e1e */
if(!s->budget--) { s->failed_pc=0x0c0c6e1eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6e20;
P_0c0c6e20: /* original d236, guest PC 0x0c0c6e20 */
if(!s->budget--) { s->failed_pc=0x0c0c6e20u; return 0; }
r[2]=read(ram,0x0c0c6efcu,4);
goto P_0c0c6e22;
P_0c0c6e22: /* original 2528, guest PC 0x0c0c6e22 */
if(!s->budget--) { s->failed_pc=0x0c0c6e22u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0c6e24;
P_0c0c6e24: /* original 8b05, guest PC 0x0c0c6e24 */
if(!s->budget--) { s->failed_pc=0x0c0c6e24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6e32; }
goto P_0c0c6e26;
P_0c0c6e26: /* original 2488, guest PC 0x0c0c6e26 */
if(!s->budget--) { s->failed_pc=0x0c0c6e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0c6e28;
P_0c0c6e28: /* original c735, guest PC 0x0c0c6e28 */
if(!s->budget--) { s->failed_pc=0x0c0c6e28u; return 0; }
r[0]=code_base|0x000c6f00u;
goto P_0c0c6e2a;
P_0c0c6e2a: /* original 8f02, guest PC 0x0c0c6e2a */
if(!s->budget--) { s->failed_pc=0x0c0c6e2au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,5,r[0]);
if(!cond) { goto P_0c0c6e32; }
goto P_0c0c6e2e;
P_0c0c6e2c: /* original f508, guest PC 0x0c0c6e2c */
if(!s->budget--) { s->failed_pc=0x0c0c6e2cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6e2e;
P_0c0c6e2e: /* original c735, guest PC 0x0c0c6e2e */
if(!s->budget--) { s->failed_pc=0x0c0c6e2eu; return 0; }
r[0]=code_base|0x000c6f04u;
goto P_0c0c6e30;
P_0c0c6e30: /* original f508, guest PC 0x0c0c6e30 */
if(!s->budget--) { s->failed_pc=0x0c0c6e30u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c6e32;
P_0c0c6e32: /* original f455, guest PC 0x0c0c6e32 */
if(!s->budget--) { s->failed_pc=0x0c0c6e32u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c6e34;
P_0c0c6e34: /* original f65c, guest PC 0x0c0c6e34 */
if(!s->budget--) { s->failed_pc=0x0c0c6e34u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0c6e36;
P_0c0c6e36: /* original 8d04, guest PC 0x0c0c6e36 */
if(!s->budget--) { s->failed_pc=0x0c0c6e36u; return 0; }
cond=r[17]&1u;
fr[6]^=0x80000000u;
if(cond) { goto P_0c0c6e42; }
goto P_0c0c6e3a;
P_0c0c6e38: /* original f64d, guest PC 0x0c0c6e38 */
if(!s->budget--) { s->failed_pc=0x0c0c6e38u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0c6e3a;
P_0c0c6e3a: /* original f645, guest PC 0x0c0c6e3a */
if(!s->budget--) { s->failed_pc=0x0c0c6e3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c0c6e3c;
P_0c0c6e3c: /* original 8903, guest PC 0x0c0c6e3c */
if(!s->budget--) { s->failed_pc=0x0c0c6e3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6e46; }
goto P_0c0c6e3e;
P_0c0c6e3e: /* original a003, guest PC 0x0c0c6e3e */
if(!s->budget--) { s->failed_pc=0x0c0c6e3eu; return 0; }
goto P_0c0c6e48;
P_0c0c6e40: /* original 0009, guest PC 0x0c0c6e40 */
if(!s->budget--) { s->failed_pc=0x0c0c6e40u; return 0; }
goto P_0c0c6e42;
P_0c0c6e42: /* original a001, guest PC 0x0c0c6e42 */
if(!s->budget--) { s->failed_pc=0x0c0c6e42u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0c6e48;
P_0c0c6e44: /* original f45c, guest PC 0x0c0c6e44 */
if(!s->budget--) { s->failed_pc=0x0c0c6e44u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0c6e46;
P_0c0c6e46: /* original f46c, guest PC 0x0c0c6e46 */
if(!s->budget--) { s->failed_pc=0x0c0c6e46u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0c6e48;
P_0c0c6e48: /* original 9051, guest PC 0x0c0c6e48 */
if(!s->budget--) { s->failed_pc=0x0c0c6e48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6eeeu,2);
goto P_0c0c6e4a;
P_0c0c6e4a: /* original 2dd8, guest PC 0x0c0c6e4a */
if(!s->budget--) { s->failed_pc=0x0c0c6e4au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c6e4c;
P_0c0c6e4c: /* original f58d, guest PC 0x0c0c6e4c */
if(!s->budget--) { s->failed_pc=0x0c0c6e4cu; return 0; }
fr[5]=0;
goto P_0c0c6e4e;
P_0c0c6e4e: /* original fe57, guest PC 0x0c0c6e4e */
if(!s->budget--) { s->failed_pc=0x0c0c6e4eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c6e50;
P_0c0c6e50: /* original 7004, guest PC 0x0c0c6e50 */
if(!s->budget--) { s->failed_pc=0x0c0c6e50u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c6e52;
P_0c0c6e52: /* original fe47, guest PC 0x0c0c6e52 */
if(!s->budget--) { s->failed_pc=0x0c0c6e52u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c6e54;
P_0c0c6e54: /* original 7004, guest PC 0x0c0c6e54 */
if(!s->budget--) { s->failed_pc=0x0c0c6e54u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c6e56;
P_0c0c6e56: /* original 8f02, guest PC 0x0c0c6e56 */
if(!s->budget--) { s->failed_pc=0x0c0c6e56u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,5,r[14]+r[0]);
if(!cond) { goto P_0c0c6e5e; }
goto P_0c0c6e5a;
P_0c0c6e58: /* original fe57, guest PC 0x0c0c6e58 */
if(!s->budget--) { s->failed_pc=0x0c0c6e58u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c6e5a;
P_0c0c6e5a: /* original 9049, guest PC 0x0c0c6e5a */
if(!s->budget--) { s->failed_pc=0x0c0c6e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef0u,2);
goto P_0c0c6e5c;
P_0c0c6e5c: /* original fe57, guest PC 0x0c0c6e5c */
if(!s->budget--) { s->failed_pc=0x0c0c6e5cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c6e5e;
P_0c0c6e5e: /* original 7f40, guest PC 0x0c0c6e5e */
if(!s->budget--) { s->failed_pc=0x0c0c6e5eu; return 0; }
r[15]+=0x00000040u;
goto P_0c0c6e60;
P_0c0c6e60: /* original 9047, guest PC 0x0c0c6e60 */
if(!s->budget--) { s->failed_pc=0x0c0c6e60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef2u,2);
goto P_0c0c6e62;
P_0c0c6e62: /* original 4f26, guest PC 0x0c0c6e62 */
if(!s->budget--) { s->failed_pc=0x0c0c6e62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6e64;
P_0c0c6e64: /* original 0ed4, guest PC 0x0c0c6e64 */
if(!s->budget--) { s->failed_pc=0x0c0c6e64u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c6e66;
P_0c0c6e66: /* original fcf9, guest PC 0x0c0c6e66 */
if(!s->budget--) { s->failed_pc=0x0c0c6e66u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c6e68;
P_0c0c6e68: /* original fdf9, guest PC 0x0c0c6e68 */
if(!s->budget--) { s->failed_pc=0x0c0c6e68u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c6e6a;
P_0c0c6e6a: /* original fef9, guest PC 0x0c0c6e6a */
if(!s->budget--) { s->failed_pc=0x0c0c6e6au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c6e6c;
P_0c0c6e6c: /* original fff9, guest PC 0x0c0c6e6c */
if(!s->budget--) { s->failed_pc=0x0c0c6e6cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c6e6e;
P_0c0c6e6e: /* original 68f6, guest PC 0x0c0c6e6e */
if(!s->budget--) { s->failed_pc=0x0c0c6e6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6e70;
P_0c0c6e70: /* original 69f6, guest PC 0x0c0c6e70 */
if(!s->budget--) { s->failed_pc=0x0c0c6e70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c6e72;
P_0c0c6e72: /* original 6af6, guest PC 0x0c0c6e72 */
if(!s->budget--) { s->failed_pc=0x0c0c6e72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c6e74;
P_0c0c6e74: /* original 6bf6, guest PC 0x0c0c6e74 */
if(!s->budget--) { s->failed_pc=0x0c0c6e74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c6e76;
P_0c0c6e76: /* original 6cf6, guest PC 0x0c0c6e76 */
if(!s->budget--) { s->failed_pc=0x0c0c6e76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6e78;
P_0c0c6e78: /* original 6df6, guest PC 0x0c0c6e78 */
if(!s->budget--) { s->failed_pc=0x0c0c6e78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6e7a;
P_0c0c6e7a: /* original 000b, guest PC 0x0c0c6e7a */
if(!s->budget--) { s->failed_pc=0x0c0c6e7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6e7c: /* original 6ef6, guest PC 0x0c0c6e7c */
if(!s->budget--) { s->failed_pc=0x0c0c6e7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c6e7eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
