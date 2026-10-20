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
int vf3_0a67_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a67ceu: goto P_0c0a67ce;
case 0x0c0a67d0u: goto P_0c0a67d0;
case 0x0c0a67d2u: goto P_0c0a67d2;
case 0x0c0a67d4u: goto P_0c0a67d4;
case 0x0c0a67d6u: goto P_0c0a67d6;
case 0x0c0a67d8u: goto P_0c0a67d8;
case 0x0c0a67dau: goto P_0c0a67da;
case 0x0c0a67dcu: goto P_0c0a67dc;
case 0x0c0a67deu: goto P_0c0a67de;
case 0x0c0a67e0u: goto P_0c0a67e0;
case 0x0c0a67e2u: goto P_0c0a67e2;
case 0x0c0a67e4u: goto P_0c0a67e4;
case 0x0c0a67e6u: goto P_0c0a67e6;
case 0x0c0a67e8u: goto P_0c0a67e8;
case 0x0c0a67eau: goto P_0c0a67ea;
case 0x0c0a67ecu: goto P_0c0a67ec;
case 0x0c0a67eeu: goto P_0c0a67ee;
case 0x0c0a67f0u: goto P_0c0a67f0;
case 0x0c0a67f2u: goto P_0c0a67f2;
case 0x0c0a67f4u: goto P_0c0a67f4;
case 0x0c0a67f6u: goto P_0c0a67f6;
case 0x0c0a67f8u: goto P_0c0a67f8;
case 0x0c0a67fau: goto P_0c0a67fa;
case 0x0c0a67fcu: goto P_0c0a67fc;
case 0x0c0a67feu: goto P_0c0a67fe;
case 0x0c0a6800u: goto P_0c0a6800;
case 0x0c0a6802u: goto P_0c0a6802;
case 0x0c0a6804u: goto P_0c0a6804;
case 0x0c0a6806u: goto P_0c0a6806;
case 0x0c0a6808u: goto P_0c0a6808;
case 0x0c0a680au: goto P_0c0a680a;
case 0x0c0a680cu: goto P_0c0a680c;
case 0x0c0a680eu: goto P_0c0a680e;
case 0x0c0a6810u: goto P_0c0a6810;
case 0x0c0a6812u: goto P_0c0a6812;
case 0x0c0a6814u: goto P_0c0a6814;
case 0x0c0a6816u: goto P_0c0a6816;
case 0x0c0a6818u: goto P_0c0a6818;
case 0x0c0a681au: goto P_0c0a681a;
case 0x0c0a681cu: goto P_0c0a681c;
case 0x0c0a681eu: goto P_0c0a681e;
case 0x0c0a6820u: goto P_0c0a6820;
case 0x0c0a6822u: goto P_0c0a6822;
case 0x0c0a6824u: goto P_0c0a6824;
case 0x0c0a6826u: goto P_0c0a6826;
case 0x0c0a6828u: goto P_0c0a6828;
case 0x0c0a682au: goto P_0c0a682a;
case 0x0c0a682cu: goto P_0c0a682c;
case 0x0c0a682eu: goto P_0c0a682e;
case 0x0c0a6830u: goto P_0c0a6830;
case 0x0c0a6832u: goto P_0c0a6832;
case 0x0c0a6834u: goto P_0c0a6834;
case 0x0c0a6836u: goto P_0c0a6836;
case 0x0c0a6838u: goto P_0c0a6838;
case 0x0c0a683au: goto P_0c0a683a;
case 0x0c0a683cu: goto P_0c0a683c;
case 0x0c0a683eu: goto P_0c0a683e;
case 0x0c0a6840u: goto P_0c0a6840;
case 0x0c0a6842u: goto P_0c0a6842;
case 0x0c0a6844u: goto P_0c0a6844;
case 0x0c0a6846u: goto P_0c0a6846;
case 0x0c0a6848u: goto P_0c0a6848;
case 0x0c0a684au: goto P_0c0a684a;
case 0x0c0a684cu: goto P_0c0a684c;
case 0x0c0a684eu: goto P_0c0a684e;
case 0x0c0a6850u: goto P_0c0a6850;
case 0x0c0a6852u: goto P_0c0a6852;
case 0x0c0a6854u: goto P_0c0a6854;
case 0x0c0a6856u: goto P_0c0a6856;
case 0x0c0a6858u: goto P_0c0a6858;
case 0x0c0a685au: goto P_0c0a685a;
case 0x0c0a685cu: goto P_0c0a685c;
case 0x0c0a685eu: goto P_0c0a685e;
case 0x0c0a6860u: goto P_0c0a6860;
case 0x0c0a6862u: goto P_0c0a6862;
case 0x0c0a6864u: goto P_0c0a6864;
case 0x0c0a6866u: goto P_0c0a6866;
case 0x0c0a6868u: goto P_0c0a6868;
case 0x0c0a686au: goto P_0c0a686a;
case 0x0c0a686cu: goto P_0c0a686c;
case 0x0c0a686eu: goto P_0c0a686e;
case 0x0c0a6870u: goto P_0c0a6870;
case 0x0c0a6872u: goto P_0c0a6872;
case 0x0c0a6874u: goto P_0c0a6874;
case 0x0c0a6876u: goto P_0c0a6876;
case 0x0c0a6878u: goto P_0c0a6878;
case 0x0c0a687au: goto P_0c0a687a;
case 0x0c0a687cu: goto P_0c0a687c;
case 0x0c0a687eu: goto P_0c0a687e;
case 0x0c0a6880u: goto P_0c0a6880;
case 0x0c0a6882u: goto P_0c0a6882;
case 0x0c0a6884u: goto P_0c0a6884;
case 0x0c0a6886u: goto P_0c0a6886;
case 0x0c0a6888u: goto P_0c0a6888;
case 0x0c0a688au: goto P_0c0a688a;
case 0x0c0a688cu: goto P_0c0a688c;
case 0x0c0a688eu: goto P_0c0a688e;
case 0x0c0a6890u: goto P_0c0a6890;
case 0x0c0a6892u: goto P_0c0a6892;
case 0x0c0a6894u: goto P_0c0a6894;
case 0x0c0a6896u: goto P_0c0a6896;
case 0x0c0a6898u: goto P_0c0a6898;
case 0x0c0a689au: goto P_0c0a689a;
case 0x0c0a689cu: goto P_0c0a689c;
case 0x0c0a689eu: goto P_0c0a689e;
case 0x0c0a68a0u: goto P_0c0a68a0;
case 0x0c0a68a2u: goto P_0c0a68a2;
case 0x0c0a68a4u: goto P_0c0a68a4;
case 0x0c0a68a6u: goto P_0c0a68a6;
case 0x0c0a68a8u: goto P_0c0a68a8;
case 0x0c0a68aau: goto P_0c0a68aa;
case 0x0c0a68acu: goto P_0c0a68ac;
case 0x0c0a68aeu: goto P_0c0a68ae;
case 0x0c0a68b0u: goto P_0c0a68b0;
case 0x0c0a68b2u: goto P_0c0a68b2;
case 0x0c0a68b4u: goto P_0c0a68b4;
case 0x0c0a68b6u: goto P_0c0a68b6;
case 0x0c0a68b8u: goto P_0c0a68b8;
case 0x0c0a68bau: goto P_0c0a68ba;
case 0x0c0a68bcu: goto P_0c0a68bc;
case 0x0c0a68beu: goto P_0c0a68be;
case 0x0c0a68c0u: goto P_0c0a68c0;
case 0x0c0a68c2u: goto P_0c0a68c2;
case 0x0c0a68c4u: goto P_0c0a68c4;
case 0x0c0a68c6u: goto P_0c0a68c6;
case 0x0c0a68c8u: goto P_0c0a68c8;
case 0x0c0a68cau: goto P_0c0a68ca;
case 0x0c0a68ccu: goto P_0c0a68cc;
case 0x0c0a68ceu: goto P_0c0a68ce;
case 0x0c0a68d0u: goto P_0c0a68d0;
case 0x0c0a68d2u: goto P_0c0a68d2;
case 0x0c0a68d4u: goto P_0c0a68d4;
case 0x0c0a68d6u: goto P_0c0a68d6;
case 0x0c0a68d8u: goto P_0c0a68d8;
case 0x0c0a68dau: goto P_0c0a68da;
case 0x0c0a68dcu: goto P_0c0a68dc;
case 0x0c0a68deu: goto P_0c0a68de;
case 0x0c0a68e0u: goto P_0c0a68e0;
case 0x0c0a68e2u: goto P_0c0a68e2;
case 0x0c0a68e4u: goto P_0c0a68e4;
case 0x0c0a68e6u: goto P_0c0a68e6;
case 0x0c0a68e8u: goto P_0c0a68e8;
case 0x0c0a68eau: goto P_0c0a68ea;
case 0x0c0a68ecu: goto P_0c0a68ec;
case 0x0c0a68eeu: goto P_0c0a68ee;
case 0x0c0a68f0u: goto P_0c0a68f0;
case 0x0c0a68f2u: goto P_0c0a68f2;
case 0x0c0a68f4u: goto P_0c0a68f4;
case 0x0c0a68f6u: goto P_0c0a68f6;
case 0x0c0a68f8u: goto P_0c0a68f8;
case 0x0c0a68fau: goto P_0c0a68fa;
case 0x0c0a68fcu: goto P_0c0a68fc;
case 0x0c0a68feu: goto P_0c0a68fe;
case 0x0c0a6900u: goto P_0c0a6900;
case 0x0c0a6902u: goto P_0c0a6902;
case 0x0c0a6904u: goto P_0c0a6904;
case 0x0c0a6906u: goto P_0c0a6906;
case 0x0c0a6908u: goto P_0c0a6908;
case 0x0c0a690au: goto P_0c0a690a;
case 0x0c0a690cu: goto P_0c0a690c;
case 0x0c0a690eu: goto P_0c0a690e;
case 0x0c0a6910u: goto P_0c0a6910;
case 0x0c0a6912u: goto P_0c0a6912;
case 0x0c0a6914u: goto P_0c0a6914;
case 0x0c0a6916u: goto P_0c0a6916;
case 0x0c0a6918u: goto P_0c0a6918;
case 0x0c0a691au: goto P_0c0a691a;
case 0x0c0a691cu: goto P_0c0a691c;
case 0x0c0a691eu: goto P_0c0a691e;
case 0x0c0a6920u: goto P_0c0a6920;
case 0x0c0a6922u: goto P_0c0a6922;
case 0x0c0a6924u: goto P_0c0a6924;
case 0x0c0a6926u: goto P_0c0a6926;
case 0x0c0a6928u: goto P_0c0a6928;
case 0x0c0a692au: goto P_0c0a692a;
case 0x0c0a692cu: goto P_0c0a692c;
case 0x0c0a692eu: goto P_0c0a692e;
case 0x0c0a6930u: goto P_0c0a6930;
case 0x0c0a6932u: goto P_0c0a6932;
case 0x0c0a6934u: goto P_0c0a6934;
case 0x0c0a6936u: goto P_0c0a6936;
case 0x0c0a6938u: goto P_0c0a6938;
case 0x0c0a693au: goto P_0c0a693a;
case 0x0c0a693cu: goto P_0c0a693c;
case 0x0c0a693eu: goto P_0c0a693e;
case 0x0c0a6940u: goto P_0c0a6940;
case 0x0c0a6942u: goto P_0c0a6942;
case 0x0c0a6944u: goto P_0c0a6944;
case 0x0c0a6946u: goto P_0c0a6946;
case 0x0c0a6948u: goto P_0c0a6948;
case 0x0c0a694au: goto P_0c0a694a;
case 0x0c0a694cu: goto P_0c0a694c;
case 0x0c0a694eu: goto P_0c0a694e;
case 0x0c0a6950u: goto P_0c0a6950;
case 0x0c0a6952u: goto P_0c0a6952;
case 0x0c0a6954u: goto P_0c0a6954;
case 0x0c0a6956u: goto P_0c0a6956;
case 0x0c0a6958u: goto P_0c0a6958;
case 0x0c0a695au: goto P_0c0a695a;
case 0x0c0a695cu: goto P_0c0a695c;
case 0x0c0a695eu: goto P_0c0a695e;
case 0x0c0a6960u: goto P_0c0a6960;
case 0x0c0a6962u: goto P_0c0a6962;
case 0x0c0a6964u: goto P_0c0a6964;
case 0x0c0a6966u: goto P_0c0a6966;
case 0x0c0a6968u: goto P_0c0a6968;
case 0x0c0a696au: goto P_0c0a696a;
case 0x0c0a696cu: goto P_0c0a696c;
case 0x0c0a696eu: goto P_0c0a696e;
case 0x0c0a6970u: goto P_0c0a6970;
case 0x0c0a6972u: goto P_0c0a6972;
case 0x0c0a6974u: goto P_0c0a6974;
case 0x0c0a6976u: goto P_0c0a6976;
case 0x0c0a6978u: goto P_0c0a6978;
case 0x0c0a697au: goto P_0c0a697a;
case 0x0c0a697cu: goto P_0c0a697c;
case 0x0c0a697eu: goto P_0c0a697e;
case 0x0c0a6980u: goto P_0c0a6980;
case 0x0c0a6982u: goto P_0c0a6982;
case 0x0c0a6984u: goto P_0c0a6984;
case 0x0c0a6986u: goto P_0c0a6986;
case 0x0c0a6988u: goto P_0c0a6988;
case 0x0c0a698au: goto P_0c0a698a;
case 0x0c0a698cu: goto P_0c0a698c;
case 0x0c0a698eu: goto P_0c0a698e;
case 0x0c0a6990u: goto P_0c0a6990;
case 0x0c0a6992u: goto P_0c0a6992;
case 0x0c0a6994u: goto P_0c0a6994;
case 0x0c0a6996u: goto P_0c0a6996;
case 0x0c0a6998u: goto P_0c0a6998;
case 0x0c0a699au: goto P_0c0a699a;
case 0x0c0a699cu: goto P_0c0a699c;
case 0x0c0a699eu: goto P_0c0a699e;
case 0x0c0a69a0u: goto P_0c0a69a0;
case 0x0c0a69a2u: goto P_0c0a69a2;
case 0x0c0a69a4u: goto P_0c0a69a4;
case 0x0c0a69a6u: goto P_0c0a69a6;
case 0x0c0a69a8u: goto P_0c0a69a8;
case 0x0c0a69aau: goto P_0c0a69aa;
case 0x0c0a69acu: goto P_0c0a69ac;
case 0x0c0a69aeu: goto P_0c0a69ae;
case 0x0c0a69b0u: goto P_0c0a69b0;
case 0x0c0a69b2u: goto P_0c0a69b2;
case 0x0c0a69b4u: goto P_0c0a69b4;
case 0x0c0a69b6u: goto P_0c0a69b6;
case 0x0c0a69b8u: goto P_0c0a69b8;
case 0x0c0a69bau: goto P_0c0a69ba;
case 0x0c0a69bcu: goto P_0c0a69bc;
case 0x0c0a69beu: goto P_0c0a69be;
case 0x0c0a69c0u: goto P_0c0a69c0;
case 0x0c0a69c2u: goto P_0c0a69c2;
case 0x0c0a69c4u: goto P_0c0a69c4;
case 0x0c0a69c6u: goto P_0c0a69c6;
case 0x0c0a69c8u: goto P_0c0a69c8;
case 0x0c0a69cau: goto P_0c0a69ca;
case 0x0c0a69ccu: goto P_0c0a69cc;
case 0x0c0a69ceu: goto P_0c0a69ce;
case 0x0c0a69d0u: goto P_0c0a69d0;
case 0x0c0a69d2u: goto P_0c0a69d2;
case 0x0c0a69d4u: goto P_0c0a69d4;
case 0x0c0a69d6u: goto P_0c0a69d6;
case 0x0c0a69d8u: goto P_0c0a69d8;
case 0x0c0a69dau: goto P_0c0a69da;
case 0x0c0a69dcu: goto P_0c0a69dc;
case 0x0c0a69deu: goto P_0c0a69de;
case 0x0c0a69e0u: goto P_0c0a69e0;
case 0x0c0a69e2u: goto P_0c0a69e2;
case 0x0c0a69e4u: goto P_0c0a69e4;
case 0x0c0a69e6u: goto P_0c0a69e6;
case 0x0c0a69e8u: goto P_0c0a69e8;
case 0x0c0a69eau: goto P_0c0a69ea;
case 0x0c0a69ecu: goto P_0c0a69ec;
case 0x0c0a69eeu: goto P_0c0a69ee;
case 0x0c0a69f0u: goto P_0c0a69f0;
case 0x0c0a69f2u: goto P_0c0a69f2;
case 0x0c0a69f4u: goto P_0c0a69f4;
case 0x0c0a69f6u: goto P_0c0a69f6;
case 0x0c0a69f8u: goto P_0c0a69f8;
case 0x0c0a69fau: goto P_0c0a69fa;
case 0x0c0a69fcu: goto P_0c0a69fc;
case 0x0c0a69feu: goto P_0c0a69fe;
case 0x0c0a6a00u: goto P_0c0a6a00;
case 0x0c0a6a02u: goto P_0c0a6a02;
case 0x0c0a6a04u: goto P_0c0a6a04;
case 0x0c0a6a06u: goto P_0c0a6a06;
case 0x0c0a6a08u: goto P_0c0a6a08;
case 0x0c0a6a0au: goto P_0c0a6a0a;
case 0x0c0a6a0cu: goto P_0c0a6a0c;
case 0x0c0a6a0eu: goto P_0c0a6a0e;
case 0x0c0a6a10u: goto P_0c0a6a10;
case 0x0c0a6a12u: goto P_0c0a6a12;
case 0x0c0a6a14u: goto P_0c0a6a14;
case 0x0c0a6a16u: goto P_0c0a6a16;
case 0x0c0a6a18u: goto P_0c0a6a18;
case 0x0c0a6a1au: goto P_0c0a6a1a;
case 0x0c0a6a1cu: goto P_0c0a6a1c;
case 0x0c0a6a1eu: goto P_0c0a6a1e;
case 0x0c0a6a20u: goto P_0c0a6a20;
case 0x0c0a6a22u: goto P_0c0a6a22;
case 0x0c0a6a24u: goto P_0c0a6a24;
case 0x0c0a6a26u: goto P_0c0a6a26;
case 0x0c0a6a28u: goto P_0c0a6a28;
case 0x0c0a6a2au: goto P_0c0a6a2a;
case 0x0c0a6a2cu: goto P_0c0a6a2c;
case 0x0c0a6a2eu: goto P_0c0a6a2e;
case 0x0c0a6a30u: goto P_0c0a6a30;
case 0x0c0a6a32u: goto P_0c0a6a32;
case 0x0c0a6a34u: goto P_0c0a6a34;
case 0x0c0a6a36u: goto P_0c0a6a36;
case 0x0c0a6a38u: goto P_0c0a6a38;
case 0x0c0a6a3au: goto P_0c0a6a3a;
case 0x0c0a6a3cu: goto P_0c0a6a3c;
case 0x0c0a6a3eu: goto P_0c0a6a3e;
case 0x0c0a6a40u: goto P_0c0a6a40;
case 0x0c0a6a42u: goto P_0c0a6a42;
case 0x0c0a6a44u: goto P_0c0a6a44;
case 0x0c0a6a46u: goto P_0c0a6a46;
case 0x0c0a6a48u: goto P_0c0a6a48;
case 0x0c0a6a4au: goto P_0c0a6a4a;
case 0x0c0a6a4cu: goto P_0c0a6a4c;
case 0x0c0a6a4eu: goto P_0c0a6a4e;
case 0x0c0a6a50u: goto P_0c0a6a50;
case 0x0c0a6a52u: goto P_0c0a6a52;
case 0x0c0a6a54u: goto P_0c0a6a54;
case 0x0c0a6a56u: goto P_0c0a6a56;
case 0x0c0a6a58u: goto P_0c0a6a58;
case 0x0c0a6a5au: goto P_0c0a6a5a;
case 0x0c0a6a5cu: goto P_0c0a6a5c;
case 0x0c0a6a5eu: goto P_0c0a6a5e;
case 0x0c0a6a60u: goto P_0c0a6a60;
case 0x0c0a6a62u: goto P_0c0a6a62;
case 0x0c0a6a64u: goto P_0c0a6a64;
case 0x0c0a6a66u: goto P_0c0a6a66;
case 0x0c0a6a68u: goto P_0c0a6a68;
case 0x0c0a6a6au: goto P_0c0a6a6a;
case 0x0c0a6a6cu: goto P_0c0a6a6c;
case 0x0c0a6a6eu: goto P_0c0a6a6e;
case 0x0c0a6a70u: goto P_0c0a6a70;
case 0x0c0a6a72u: goto P_0c0a6a72;
case 0x0c0a6a74u: goto P_0c0a6a74;
case 0x0c0a6a76u: goto P_0c0a6a76;
case 0x0c0a6a78u: goto P_0c0a6a78;
case 0x0c0a6a7au: goto P_0c0a6a7a;
case 0x0c0a6a7cu: goto P_0c0a6a7c;
case 0x0c0a6a7eu: goto P_0c0a6a7e;
case 0x0c0a6a80u: goto P_0c0a6a80;
case 0x0c0a6a82u: goto P_0c0a6a82;
case 0x0c0a6a84u: goto P_0c0a6a84;
case 0x0c0a6a86u: goto P_0c0a6a86;
case 0x0c0a6a88u: goto P_0c0a6a88;
case 0x0c0a6a8au: goto P_0c0a6a8a;
case 0x0c0a6a8cu: goto P_0c0a6a8c;
case 0x0c0a6a8eu: goto P_0c0a6a8e;
case 0x0c0a6a90u: goto P_0c0a6a90;
case 0x0c0a6a92u: goto P_0c0a6a92;
case 0x0c0a6a94u: goto P_0c0a6a94;
case 0x0c0a6a96u: goto P_0c0a6a96;
case 0x0c0a6a98u: goto P_0c0a6a98;
case 0x0c0a6a9au: goto P_0c0a6a9a;
case 0x0c0a6a9cu: goto P_0c0a6a9c;
case 0x0c0a6a9eu: goto P_0c0a6a9e;
case 0x0c0a6aa0u: goto P_0c0a6aa0;
case 0x0c0a6aa2u: goto P_0c0a6aa2;
case 0x0c0a6aa4u: goto P_0c0a6aa4;
case 0x0c0a6aa6u: goto P_0c0a6aa6;
case 0x0c0a6aa8u: goto P_0c0a6aa8;
case 0x0c0a6aaau: goto P_0c0a6aaa;
case 0x0c0a6aacu: goto P_0c0a6aac;
case 0x0c0a6aaeu: goto P_0c0a6aae;
case 0x0c0a6ab0u: goto P_0c0a6ab0;
case 0x0c0a6ab2u: goto P_0c0a6ab2;
case 0x0c0a6ab4u: goto P_0c0a6ab4;
case 0x0c0a6ab6u: goto P_0c0a6ab6;
case 0x0c0a6ab8u: goto P_0c0a6ab8;
case 0x0c0a6abau: goto P_0c0a6aba;
case 0x0c0a6abcu: goto P_0c0a6abc;
case 0x0c0a6abeu: goto P_0c0a6abe;
case 0x0c0a6ac0u: goto P_0c0a6ac0;
case 0x0c0a6ac2u: goto P_0c0a6ac2;
case 0x0c0a6ac4u: goto P_0c0a6ac4;
case 0x0c0a6ac6u: goto P_0c0a6ac6;
case 0x0c0a6ac8u: goto P_0c0a6ac8;
case 0x0c0a6acau: goto P_0c0a6aca;
case 0x0c0a6af4u: goto P_0c0a6af4;
case 0x0c0a6af6u: goto P_0c0a6af6;
case 0x0c0a6af8u: goto P_0c0a6af8;
case 0x0c0a6afau: goto P_0c0a6afa;
case 0x0c0a6afcu: goto P_0c0a6afc;
case 0x0c0a6afeu: goto P_0c0a6afe;
case 0x0c0a6b00u: goto P_0c0a6b00;
case 0x0c0a6b02u: goto P_0c0a6b02;
case 0x0c0a6b04u: goto P_0c0a6b04;
case 0x0c0a6b06u: goto P_0c0a6b06;
case 0x0c0a6b08u: goto P_0c0a6b08;
case 0x0c0a6b0au: goto P_0c0a6b0a;
case 0x0c0a6b0cu: goto P_0c0a6b0c;
case 0x0c0a6b0eu: goto P_0c0a6b0e;
case 0x0c0a6b10u: goto P_0c0a6b10;
case 0x0c0a6b12u: goto P_0c0a6b12;
case 0x0c0a6b14u: goto P_0c0a6b14;
case 0x0c0a6b16u: goto P_0c0a6b16;
case 0x0c0a6b18u: goto P_0c0a6b18;
case 0x0c0a6b1au: goto P_0c0a6b1a;
case 0x0c0a6b1cu: goto P_0c0a6b1c;
case 0x0c0a6b1eu: goto P_0c0a6b1e;
case 0x0c0a6b20u: goto P_0c0a6b20;
case 0x0c0a6b22u: goto P_0c0a6b22;
case 0x0c0a6b24u: goto P_0c0a6b24;
case 0x0c0a6b26u: goto P_0c0a6b26;
case 0x0c0a6b28u: goto P_0c0a6b28;
case 0x0c0a6b2au: goto P_0c0a6b2a;
case 0x0c0a6b2cu: goto P_0c0a6b2c;
case 0x0c0a6b2eu: goto P_0c0a6b2e;
case 0x0c0a6b30u: goto P_0c0a6b30;
case 0x0c0a6b32u: goto P_0c0a6b32;
case 0x0c0a6b34u: goto P_0c0a6b34;
case 0x0c0a6b36u: goto P_0c0a6b36;
case 0x0c0a6b38u: goto P_0c0a6b38;
case 0x0c0a6b3au: goto P_0c0a6b3a;
case 0x0c0a6b3cu: goto P_0c0a6b3c;
case 0x0c0a6b3eu: goto P_0c0a6b3e;
case 0x0c0a6b40u: goto P_0c0a6b40;
case 0x0c0a6b42u: goto P_0c0a6b42;
case 0x0c0a6b44u: goto P_0c0a6b44;
case 0x0c0a6b46u: goto P_0c0a6b46;
case 0x0c0a6b48u: goto P_0c0a6b48;
case 0x0c0a6b4au: goto P_0c0a6b4a;
case 0x0c0a6b4cu: goto P_0c0a6b4c;
case 0x0c0a6b4eu: goto P_0c0a6b4e;
case 0x0c0a6b50u: goto P_0c0a6b50;
case 0x0c0a6b52u: goto P_0c0a6b52;
case 0x0c0a6b54u: goto P_0c0a6b54;
case 0x0c0a6b56u: goto P_0c0a6b56;
case 0x0c0a6b58u: goto P_0c0a6b58;
case 0x0c0a6b5au: goto P_0c0a6b5a;
case 0x0c0a6b5cu: goto P_0c0a6b5c;
case 0x0c0a6b5eu: goto P_0c0a6b5e;
case 0x0c0a6b60u: goto P_0c0a6b60;
case 0x0c0a6b62u: goto P_0c0a6b62;
case 0x0c0a6b64u: goto P_0c0a6b64;
case 0x0c0a6b66u: goto P_0c0a6b66;
case 0x0c0a6b68u: goto P_0c0a6b68;
case 0x0c0a6b6au: goto P_0c0a6b6a;
case 0x0c0a6b6cu: goto P_0c0a6b6c;
case 0x0c0a6b6eu: goto P_0c0a6b6e;
case 0x0c0a6b70u: goto P_0c0a6b70;
case 0x0c0a6b72u: goto P_0c0a6b72;
case 0x0c0a6b74u: goto P_0c0a6b74;
case 0x0c0a6b76u: goto P_0c0a6b76;
case 0x0c0a6b78u: goto P_0c0a6b78;
case 0x0c0a6b7au: goto P_0c0a6b7a;
case 0x0c0a6b7cu: goto P_0c0a6b7c;
case 0x0c0a6b7eu: goto P_0c0a6b7e;
case 0x0c0a6b80u: goto P_0c0a6b80;
case 0x0c0a6b82u: goto P_0c0a6b82;
case 0x0c0a6b84u: goto P_0c0a6b84;
case 0x0c0a6b86u: goto P_0c0a6b86;
case 0x0c0a6b88u: goto P_0c0a6b88;
case 0x0c0a6b8au: goto P_0c0a6b8a;
case 0x0c0a6b8cu: goto P_0c0a6b8c;
case 0x0c0a6b8eu: goto P_0c0a6b8e;
case 0x0c0a6b90u: goto P_0c0a6b90;
case 0x0c0a6b92u: goto P_0c0a6b92;
case 0x0c0a6b94u: goto P_0c0a6b94;
case 0x0c0a6b96u: goto P_0c0a6b96;
case 0x0c0a6b98u: goto P_0c0a6b98;
case 0x0c0a6b9au: goto P_0c0a6b9a;
case 0x0c0a6b9cu: goto P_0c0a6b9c;
case 0x0c0a6b9eu: goto P_0c0a6b9e;
case 0x0c0a6ba0u: goto P_0c0a6ba0;
case 0x0c0a6ba2u: goto P_0c0a6ba2;
case 0x0c0a6ba4u: goto P_0c0a6ba4;
case 0x0c0a6ba6u: goto P_0c0a6ba6;
case 0x0c0a6ba8u: goto P_0c0a6ba8;
case 0x0c0a6baau: goto P_0c0a6baa;
case 0x0c0a6bacu: goto P_0c0a6bac;
case 0x0c0a6baeu: goto P_0c0a6bae;
case 0x0c0a6bb0u: goto P_0c0a6bb0;
case 0x0c0a6bb2u: goto P_0c0a6bb2;
case 0x0c0a6bb4u: goto P_0c0a6bb4;
case 0x0c0a6bb6u: goto P_0c0a6bb6;
case 0x0c0a6bb8u: goto P_0c0a6bb8;
case 0x0c0a6bbau: goto P_0c0a6bba;
case 0x0c0a6bbcu: goto P_0c0a6bbc;
case 0x0c0a6bbeu: goto P_0c0a6bbe;
case 0x0c0a6bc0u: goto P_0c0a6bc0;
case 0x0c0a6bc2u: goto P_0c0a6bc2;
case 0x0c0a6bc4u: goto P_0c0a6bc4;
case 0x0c0a6bc6u: goto P_0c0a6bc6;
case 0x0c0a6bc8u: goto P_0c0a6bc8;
case 0x0c0a6bcau: goto P_0c0a6bca;
case 0x0c0a6bccu: goto P_0c0a6bcc;
case 0x0c0a6bceu: goto P_0c0a6bce;
case 0x0c0a6bd0u: goto P_0c0a6bd0;
case 0x0c0a6bd2u: goto P_0c0a6bd2;
case 0x0c0a6bd4u: goto P_0c0a6bd4;
case 0x0c0a6bd6u: goto P_0c0a6bd6;
case 0x0c0a6bd8u: goto P_0c0a6bd8;
case 0x0c0a6bdau: goto P_0c0a6bda;
case 0x0c0a6bdcu: goto P_0c0a6bdc;
case 0x0c0a6bdeu: goto P_0c0a6bde;
case 0x0c0a6be0u: goto P_0c0a6be0;
case 0x0c0a6be2u: goto P_0c0a6be2;
case 0x0c0a6be4u: goto P_0c0a6be4;
case 0x0c0a6be6u: goto P_0c0a6be6;
case 0x0c0a6be8u: goto P_0c0a6be8;
case 0x0c0a6beau: goto P_0c0a6bea;
case 0x0c0a6becu: goto P_0c0a6bec;
case 0x0c0a6beeu: goto P_0c0a6bee;
case 0x0c0a6bf0u: goto P_0c0a6bf0;
case 0x0c0a6bf2u: goto P_0c0a6bf2;
case 0x0c0a6bf4u: goto P_0c0a6bf4;
case 0x0c0a6bf6u: goto P_0c0a6bf6;
case 0x0c0a6bf8u: goto P_0c0a6bf8;
case 0x0c0a6bfau: goto P_0c0a6bfa;
case 0x0c0a6bfcu: goto P_0c0a6bfc;
case 0x0c0a6bfeu: goto P_0c0a6bfe;
case 0x0c0a6c00u: goto P_0c0a6c00;
case 0x0c0a6c02u: goto P_0c0a6c02;
case 0x0c0a6c04u: goto P_0c0a6c04;
case 0x0c0a6c06u: goto P_0c0a6c06;
case 0x0c0a6c08u: goto P_0c0a6c08;
case 0x0c0a6c0au: goto P_0c0a6c0a;
case 0x0c0a6c0cu: goto P_0c0a6c0c;
case 0x0c0a6c0eu: goto P_0c0a6c0e;
case 0x0c0a6c10u: goto P_0c0a6c10;
case 0x0c0a6c12u: goto P_0c0a6c12;
case 0x0c0a6c14u: goto P_0c0a6c14;
case 0x0c0a6c16u: goto P_0c0a6c16;
case 0x0c0a6c18u: goto P_0c0a6c18;
case 0x0c0a6c1au: goto P_0c0a6c1a;
case 0x0c0a6c1cu: goto P_0c0a6c1c;
case 0x0c0a6c1eu: goto P_0c0a6c1e;
case 0x0c0a6c20u: goto P_0c0a6c20;
case 0x0c0a6c22u: goto P_0c0a6c22;
case 0x0c0a6c24u: goto P_0c0a6c24;
case 0x0c0a6c26u: goto P_0c0a6c26;
case 0x0c0a6c28u: goto P_0c0a6c28;
case 0x0c0a6c2au: goto P_0c0a6c2a;
case 0x0c0a6c2cu: goto P_0c0a6c2c;
case 0x0c0a6c2eu: goto P_0c0a6c2e;
case 0x0c0a6c30u: goto P_0c0a6c30;
case 0x0c0a6c32u: goto P_0c0a6c32;
case 0x0c0a6c34u: goto P_0c0a6c34;
case 0x0c0a6c36u: goto P_0c0a6c36;
case 0x0c0a6c38u: goto P_0c0a6c38;
case 0x0c0a6c3au: goto P_0c0a6c3a;
case 0x0c0a6c3cu: goto P_0c0a6c3c;
case 0x0c0a6c3eu: goto P_0c0a6c3e;
case 0x0c0a6c40u: goto P_0c0a6c40;
case 0x0c0a6c42u: goto P_0c0a6c42;
case 0x0c0a6c44u: goto P_0c0a6c44;
case 0x0c0a6c46u: goto P_0c0a6c46;
case 0x0c0a6c48u: goto P_0c0a6c48;
case 0x0c0a6c4au: goto P_0c0a6c4a;
case 0x0c0a6c4cu: goto P_0c0a6c4c;
case 0x0c0a6c4eu: goto P_0c0a6c4e;
case 0x0c0a6c50u: goto P_0c0a6c50;
case 0x0c0a6c52u: goto P_0c0a6c52;
case 0x0c0a6c54u: goto P_0c0a6c54;
case 0x0c0a6c56u: goto P_0c0a6c56;
case 0x0c0a6c58u: goto P_0c0a6c58;
case 0x0c0a6c5au: goto P_0c0a6c5a;
case 0x0c0a6c5cu: goto P_0c0a6c5c;
case 0x0c0a6c5eu: goto P_0c0a6c5e;
case 0x0c0a6c60u: goto P_0c0a6c60;
case 0x0c0a6c62u: goto P_0c0a6c62;
case 0x0c0a6c64u: goto P_0c0a6c64;
case 0x0c0a6c66u: goto P_0c0a6c66;
case 0x0c0a6c68u: goto P_0c0a6c68;
case 0x0c0a6c6au: goto P_0c0a6c6a;
case 0x0c0a6c6cu: goto P_0c0a6c6c;
case 0x0c0a6c6eu: goto P_0c0a6c6e;
case 0x0c0a6c70u: goto P_0c0a6c70;
case 0x0c0a6c72u: goto P_0c0a6c72;
case 0x0c0a6c74u: goto P_0c0a6c74;
case 0x0c0a6c76u: goto P_0c0a6c76;
case 0x0c0a6c78u: goto P_0c0a6c78;
case 0x0c0a6c7au: goto P_0c0a6c7a;
case 0x0c0a6c7cu: goto P_0c0a6c7c;
case 0x0c0a6c7eu: goto P_0c0a6c7e;
case 0x0c0a6c80u: goto P_0c0a6c80;
case 0x0c0a6c82u: goto P_0c0a6c82;
case 0x0c0a6c84u: goto P_0c0a6c84;
case 0x0c0a6c86u: goto P_0c0a6c86;
case 0x0c0a6c88u: goto P_0c0a6c88;
case 0x0c0a6c8au: goto P_0c0a6c8a;
case 0x0c0a6c8cu: goto P_0c0a6c8c;
case 0x0c0a6c8eu: goto P_0c0a6c8e;
case 0x0c0a6c90u: goto P_0c0a6c90;
case 0x0c0a6c92u: goto P_0c0a6c92;
case 0x0c0a6c94u: goto P_0c0a6c94;
case 0x0c0a6c96u: goto P_0c0a6c96;
case 0x0c0a6c98u: goto P_0c0a6c98;
case 0x0c0a6c9au: goto P_0c0a6c9a;
case 0x0c0a6c9cu: goto P_0c0a6c9c;
case 0x0c0a6c9eu: goto P_0c0a6c9e;
case 0x0c0a6ca0u: goto P_0c0a6ca0;
case 0x0c0a6ca2u: goto P_0c0a6ca2;
case 0x0c0a6ca4u: goto P_0c0a6ca4;
case 0x0c0a6ca6u: goto P_0c0a6ca6;
case 0x0c0a6ca8u: goto P_0c0a6ca8;
case 0x0c0a6caau: goto P_0c0a6caa;
case 0x0c0a6cacu: goto P_0c0a6cac;
case 0x0c0a6caeu: goto P_0c0a6cae;
case 0x0c0a6cb0u: goto P_0c0a6cb0;
case 0x0c0a6cb2u: goto P_0c0a6cb2;
case 0x0c0a6cb4u: goto P_0c0a6cb4;
case 0x0c0a6cb6u: goto P_0c0a6cb6;
case 0x0c0a6cb8u: goto P_0c0a6cb8;
case 0x0c0a6cbau: goto P_0c0a6cba;
case 0x0c0a6cbcu: goto P_0c0a6cbc;
case 0x0c0a6cbeu: goto P_0c0a6cbe;
case 0x0c0a6cc0u: goto P_0c0a6cc0;
case 0x0c0a6cc2u: goto P_0c0a6cc2;
case 0x0c0a6cc4u: goto P_0c0a6cc4;
case 0x0c0a6cc6u: goto P_0c0a6cc6;
case 0x0c0a6cc8u: goto P_0c0a6cc8;
case 0x0c0a6ccau: goto P_0c0a6cca;
case 0x0c0a6cccu: goto P_0c0a6ccc;
case 0x0c0a6cceu: goto P_0c0a6cce;
case 0x0c0a6cd0u: goto P_0c0a6cd0;
case 0x0c0a6cd2u: goto P_0c0a6cd2;
case 0x0c0a6cd4u: goto P_0c0a6cd4;
case 0x0c0a6cd6u: goto P_0c0a6cd6;
case 0x0c0a6cd8u: goto P_0c0a6cd8;
case 0x0c0a6cdau: goto P_0c0a6cda;
case 0x0c0a6cdcu: goto P_0c0a6cdc;
case 0x0c0a6cdeu: goto P_0c0a6cde;
case 0x0c0a6ce0u: goto P_0c0a6ce0;
case 0x0c0a6ce2u: goto P_0c0a6ce2;
case 0x0c0a6ce4u: goto P_0c0a6ce4;
case 0x0c0a6ce6u: goto P_0c0a6ce6;
case 0x0c0a6ce8u: goto P_0c0a6ce8;
case 0x0c0a6ceau: goto P_0c0a6cea;
case 0x0c0a6cecu: goto P_0c0a6cec;
case 0x0c0a6ceeu: goto P_0c0a6cee;
case 0x0c0a6cf0u: goto P_0c0a6cf0;
case 0x0c0a6cf2u: goto P_0c0a6cf2;
case 0x0c0a6cf4u: goto P_0c0a6cf4;
case 0x0c0a6cf6u: goto P_0c0a6cf6;
case 0x0c0a6cf8u: goto P_0c0a6cf8;
case 0x0c0a6cfau: goto P_0c0a6cfa;
case 0x0c0a6cfcu: goto P_0c0a6cfc;
case 0x0c0a6cfeu: goto P_0c0a6cfe;
case 0x0c0a6d00u: goto P_0c0a6d00;
case 0x0c0a6d02u: goto P_0c0a6d02;
case 0x0c0a6d04u: goto P_0c0a6d04;
case 0x0c0a6d06u: goto P_0c0a6d06;
case 0x0c0a6d08u: goto P_0c0a6d08;
case 0x0c0a6d0au: goto P_0c0a6d0a;
case 0x0c0a6d0cu: goto P_0c0a6d0c;
case 0x0c0a6d0eu: goto P_0c0a6d0e;
case 0x0c0a6d10u: goto P_0c0a6d10;
case 0x0c0a6d12u: goto P_0c0a6d12;
case 0x0c0a6d14u: goto P_0c0a6d14;
case 0x0c0a6d16u: goto P_0c0a6d16;
case 0x0c0a6d18u: goto P_0c0a6d18;
case 0x0c0a6d1au: goto P_0c0a6d1a;
case 0x0c0a6d1cu: goto P_0c0a6d1c;
case 0x0c0a6d1eu: goto P_0c0a6d1e;
case 0x0c0a6d20u: goto P_0c0a6d20;
case 0x0c0a6d22u: goto P_0c0a6d22;
case 0x0c0a6d24u: goto P_0c0a6d24;
case 0x0c0a6d26u: goto P_0c0a6d26;
case 0x0c0a6d28u: goto P_0c0a6d28;
case 0x0c0a6d2au: goto P_0c0a6d2a;
case 0x0c0a6d2cu: goto P_0c0a6d2c;
case 0x0c0a6d2eu: goto P_0c0a6d2e;
case 0x0c0a6d30u: goto P_0c0a6d30;
case 0x0c0a6d32u: goto P_0c0a6d32;
case 0x0c0a6d34u: goto P_0c0a6d34;
case 0x0c0a6d36u: goto P_0c0a6d36;
case 0x0c0a6d38u: goto P_0c0a6d38;
case 0x0c0a6d3au: goto P_0c0a6d3a;
case 0x0c0a6d3cu: goto P_0c0a6d3c;
case 0x0c0a6d3eu: goto P_0c0a6d3e;
case 0x0c0a6d40u: goto P_0c0a6d40;
case 0x0c0a6d42u: goto P_0c0a6d42;
case 0x0c0a6d44u: goto P_0c0a6d44;
case 0x0c0a6d46u: goto P_0c0a6d46;
case 0x0c0a6d48u: goto P_0c0a6d48;
case 0x0c0a6d4au: goto P_0c0a6d4a;
case 0x0c0a6d4cu: goto P_0c0a6d4c;
case 0x0c0a6d4eu: goto P_0c0a6d4e;
case 0x0c0a6d50u: goto P_0c0a6d50;
case 0x0c0a6d52u: goto P_0c0a6d52;
case 0x0c0a6d54u: goto P_0c0a6d54;
case 0x0c0a6d56u: goto P_0c0a6d56;
case 0x0c0a6d58u: goto P_0c0a6d58;
case 0x0c0a6d5au: goto P_0c0a6d5a;
case 0x0c0a6d5cu: goto P_0c0a6d5c;
case 0x0c0a6d5eu: goto P_0c0a6d5e;
case 0x0c0a6d60u: goto P_0c0a6d60;
case 0x0c0a6d62u: goto P_0c0a6d62;
case 0x0c0a6d64u: goto P_0c0a6d64;
case 0x0c0a6d66u: goto P_0c0a6d66;
case 0x0c0a6d68u: goto P_0c0a6d68;
case 0x0c0a6d6au: goto P_0c0a6d6a;
case 0x0c0a6d6cu: goto P_0c0a6d6c;
case 0x0c0a6d6eu: goto P_0c0a6d6e;
case 0x0c0a6d70u: goto P_0c0a6d70;
case 0x0c0a6d72u: goto P_0c0a6d72;
case 0x0c0a6d74u: goto P_0c0a6d74;
case 0x0c0a6d76u: goto P_0c0a6d76;
case 0x0c0a6d78u: goto P_0c0a6d78;
case 0x0c0a6d7au: goto P_0c0a6d7a;
case 0x0c0a6d7cu: goto P_0c0a6d7c;
case 0x0c0a6d7eu: goto P_0c0a6d7e;
case 0x0c0a6d80u: goto P_0c0a6d80;
case 0x0c0a6d82u: goto P_0c0a6d82;
case 0x0c0a6d84u: goto P_0c0a6d84;
case 0x0c0a6d86u: goto P_0c0a6d86;
case 0x0c0a6d88u: goto P_0c0a6d88;
case 0x0c0a6d8au: goto P_0c0a6d8a;
case 0x0c0a6d8cu: goto P_0c0a6d8c;
case 0x0c0a6d8eu: goto P_0c0a6d8e;
case 0x0c0a6d90u: goto P_0c0a6d90;
case 0x0c0a6d92u: goto P_0c0a6d92;
case 0x0c0a6d94u: goto P_0c0a6d94;
case 0x0c0a6d96u: goto P_0c0a6d96;
case 0x0c0a6d98u: goto P_0c0a6d98;
case 0x0c0a6d9au: goto P_0c0a6d9a;
case 0x0c0a6d9cu: goto P_0c0a6d9c;
case 0x0c0a6d9eu: goto P_0c0a6d9e;
case 0x0c0a6da0u: goto P_0c0a6da0;
case 0x0c0a6da2u: goto P_0c0a6da2;
case 0x0c0a6da4u: goto P_0c0a6da4;
case 0x0c0a6da6u: goto P_0c0a6da6;
case 0x0c0a6da8u: goto P_0c0a6da8;
case 0x0c0a6daau: goto P_0c0a6daa;
case 0x0c0a6dacu: goto P_0c0a6dac;
case 0x0c0a6daeu: goto P_0c0a6dae;
case 0x0c0a6db0u: goto P_0c0a6db0;
case 0x0c0a6db2u: goto P_0c0a6db2;
case 0x0c0a6db4u: goto P_0c0a6db4;
case 0x0c0a6db6u: goto P_0c0a6db6;
case 0x0c0a6db8u: goto P_0c0a6db8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a67ce: /* original 4f22, guest PC 0x0c0a67ce */
if(!s->budget--) { s->failed_pc=0x0c0a67ceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a67d0;
P_0c0a67d0: /* original 7f98, guest PC 0x0c0a67d0 */
if(!s->budget--) { s->failed_pc=0x0c0a67d0u; return 0; }
r[15]+=0xffffff98u;
goto P_0c0a67d2;
P_0c0a67d2: /* original 1f43, guest PC 0x0c0a67d2 */
if(!s->budget--) { s->failed_pc=0x0c0a67d2u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0a67d4;
P_0c0a67d4: /* original d3bd, guest PC 0x0c0a67d4 */
if(!s->budget--) { s->failed_pc=0x0c0a67d4u; return 0; }
r[3]=read(ram,0x0c0a6accu,4);
goto P_0c0a67d6;
P_0c0a67d6: /* original 430b, guest PC 0x0c0a67d6 */
if(!s->budget--) { s->failed_pc=0x0c0a67d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a67dau;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a67dau) { target=s->pc; goto dispatch; }
goto P_0c0a67da;
P_0c0a67d8: /* original e400, guest PC 0x0c0a67d8 */
if(!s->budget--) { s->failed_pc=0x0c0a67d8u; return 0; }
r[4]=0x00000000u;
goto P_0c0a67da;
P_0c0a67da: /* original be4f, guest PC 0x0c0a67da */
if(!s->budget--) { s->failed_pc=0x0c0a67dau; return 0; }
target=0x0c0a647cu; r[16]=code_base|0x0c0a67deu;
r[4]=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a67deu) { target=s->pc; goto dispatch; }
goto P_0c0a67de;
P_0c0a67dc: /* original e46c, guest PC 0x0c0a67dc */
if(!s->budget--) { s->failed_pc=0x0c0a67dcu; return 0; }
r[4]=0x0000006cu;
goto P_0c0a67de;
P_0c0a67de: /* original 6e03, guest PC 0x0c0a67de */
if(!s->budget--) { s->failed_pc=0x0c0a67deu; return 0; }
r[14]=r[0];
goto P_0c0a67e0;
P_0c0a67e0: /* original e034, guest PC 0x0c0a67e0 */
if(!s->budget--) { s->failed_pc=0x0c0a67e0u; return 0; }
r[0]=0x00000034u;
goto P_0c0a67e2;
P_0c0a67e2: /* original f39d, guest PC 0x0c0a67e2 */
if(!s->budget--) { s->failed_pc=0x0c0a67e2u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0a67e4;
P_0c0a67e4: /* original ff37, guest PC 0x0c0a67e4 */
if(!s->budget--) { s->failed_pc=0x0c0a67e4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a67e6;
P_0c0a67e6: /* original e008, guest PC 0x0c0a67e6 */
if(!s->budget--) { s->failed_pc=0x0c0a67e6u; return 0; }
r[0]=0x00000008u;
goto P_0c0a67e8;
P_0c0a67e8: /* original f38d, guest PC 0x0c0a67e8 */
if(!s->budget--) { s->failed_pc=0x0c0a67e8u; return 0; }
fr[3]=0;
goto P_0c0a67ea;
P_0c0a67ea: /* original 5df3, guest PC 0x0c0a67ea */
if(!s->budget--) { s->failed_pc=0x0c0a67eau; return 0; }
r[13]=read(ram,r[15]+12,4);
goto P_0c0a67ec;
P_0c0a67ec: /* original ff8d, guest PC 0x0c0a67ec */
if(!s->budget--) { s->failed_pc=0x0c0a67ecu; return 0; }
fr[15]=0;
goto P_0c0a67ee;
P_0c0a67ee: /* original fe37, guest PC 0x0c0a67ee */
if(!s->budget--) { s->failed_pc=0x0c0a67eeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a67f0;
P_0c0a67f0: /* original e004, guest PC 0x0c0a67f0 */
if(!s->budget--) { s->failed_pc=0x0c0a67f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0a67f2;
P_0c0a67f2: /* original fe37, guest PC 0x0c0a67f2 */
if(!s->budget--) { s->failed_pc=0x0c0a67f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a67f4;
P_0c0a67f4: /* original e00c, guest PC 0x0c0a67f4 */
if(!s->budget--) { s->failed_pc=0x0c0a67f4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a67f6;
P_0c0a67f6: /* original fe3a, guest PC 0x0c0a67f6 */
if(!s->budget--) { s->failed_pc=0x0c0a67f6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0a67f8;
P_0c0a67f8: /* original f3a8, guest PC 0x0c0a67f8 */
if(!s->budget--) { s->failed_pc=0x0c0a67f8u; return 0; }
vf3_matrix_load(s,ram,3,r[10]);
goto P_0c0a67fa;
P_0c0a67fa: /* original fe37, guest PC 0x0c0a67fa */
if(!s->budget--) { s->failed_pc=0x0c0a67fau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a67fc;
P_0c0a67fc: /* original e004, guest PC 0x0c0a67fc */
if(!s->budget--) { s->failed_pc=0x0c0a67fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a67fe;
P_0c0a67fe: /* original f3a6, guest PC 0x0c0a67fe */
if(!s->budget--) { s->failed_pc=0x0c0a67feu; return 0; }
vf3_matrix_load(s,ram,3,r[10]+r[0]);
goto P_0c0a6800;
P_0c0a6800: /* original e010, guest PC 0x0c0a6800 */
if(!s->budget--) { s->failed_pc=0x0c0a6800u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6802;
P_0c0a6802: /* original fe37, guest PC 0x0c0a6802 */
if(!s->budget--) { s->failed_pc=0x0c0a6802u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a6804;
P_0c0a6804: /* original e008, guest PC 0x0c0a6804 */
if(!s->budget--) { s->failed_pc=0x0c0a6804u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6806;
P_0c0a6806: /* original f3a6, guest PC 0x0c0a6806 */
if(!s->budget--) { s->failed_pc=0x0c0a6806u; return 0; }
vf3_matrix_load(s,ram,3,r[10]+r[0]);
goto P_0c0a6808;
P_0c0a6808: /* original e014, guest PC 0x0c0a6808 */
if(!s->budget--) { s->failed_pc=0x0c0a6808u; return 0; }
r[0]=0x00000014u;
goto P_0c0a680a;
P_0c0a680a: /* original fe37, guest PC 0x0c0a680a */
if(!s->budget--) { s->failed_pc=0x0c0a680au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a680c;
P_0c0a680c: /* original e030, guest PC 0x0c0a680c */
if(!s->budget--) { s->failed_pc=0x0c0a680cu; return 0; }
r[0]=0x00000030u;
goto P_0c0a680e;
P_0c0a680e: /* original f3b8, guest PC 0x0c0a680e */
if(!s->budget--) { s->failed_pc=0x0c0a680eu; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c0a6810;
P_0c0a6810: /* original fe37, guest PC 0x0c0a6810 */
if(!s->budget--) { s->failed_pc=0x0c0a6810u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a6812;
P_0c0a6812: /* original e004, guest PC 0x0c0a6812 */
if(!s->budget--) { s->failed_pc=0x0c0a6812u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6814;
P_0c0a6814: /* original f3b6, guest PC 0x0c0a6814 */
if(!s->budget--) { s->failed_pc=0x0c0a6814u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0a6816;
P_0c0a6816: /* original e034, guest PC 0x0c0a6816 */
if(!s->budget--) { s->failed_pc=0x0c0a6816u; return 0; }
r[0]=0x00000034u;
goto P_0c0a6818;
P_0c0a6818: /* original fe37, guest PC 0x0c0a6818 */
if(!s->budget--) { s->failed_pc=0x0c0a6818u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a681a;
P_0c0a681a: /* original e008, guest PC 0x0c0a681a */
if(!s->budget--) { s->failed_pc=0x0c0a681au; return 0; }
r[0]=0x00000008u;
goto P_0c0a681c;
P_0c0a681c: /* original f3b6, guest PC 0x0c0a681c */
if(!s->budget--) { s->failed_pc=0x0c0a681cu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0a681e;
P_0c0a681e: /* original e038, guest PC 0x0c0a681e */
if(!s->budget--) { s->failed_pc=0x0c0a681eu; return 0; }
r[0]=0x00000038u;
goto P_0c0a6820;
P_0c0a6820: /* original 67f3, guest PC 0x0c0a6820 */
if(!s->budget--) { s->failed_pc=0x0c0a6820u; return 0; }
r[7]=r[15];
goto P_0c0a6822;
P_0c0a6822: /* original fe37, guest PC 0x0c0a6822 */
if(!s->budget--) { s->failed_pc=0x0c0a6822u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a6824;
P_0c0a6824: /* original e00c, guest PC 0x0c0a6824 */
if(!s->budget--) { s->failed_pc=0x0c0a6824u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6826;
P_0c0a6826: /* original f3e6, guest PC 0x0c0a6826 */
if(!s->budget--) { s->failed_pc=0x0c0a6826u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6828;
P_0c0a6828: /* original e010, guest PC 0x0c0a6828 */
if(!s->budget--) { s->failed_pc=0x0c0a6828u; return 0; }
r[0]=0x00000010u;
goto P_0c0a682a;
P_0c0a682a: /* original 66f3, guest PC 0x0c0a682a */
if(!s->budget--) { s->failed_pc=0x0c0a682au; return 0; }
r[6]=r[15];
goto P_0c0a682c;
P_0c0a682c: /* original 7608, guest PC 0x0c0a682c */
if(!s->budget--) { s->failed_pc=0x0c0a682cu; return 0; }
r[6]+=0x00000008u;
goto P_0c0a682e;
P_0c0a682e: /* original ff3a, guest PC 0x0c0a682e */
if(!s->budget--) { s->failed_pc=0x0c0a682eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a6830;
P_0c0a6830: /* original 65f3, guest PC 0x0c0a6830 */
if(!s->budget--) { s->failed_pc=0x0c0a6830u; return 0; }
r[5]=r[15];
goto P_0c0a6832;
P_0c0a6832: /* original f3e6, guest PC 0x0c0a6832 */
if(!s->budget--) { s->failed_pc=0x0c0a6832u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6834;
P_0c0a6834: /* original e008, guest PC 0x0c0a6834 */
if(!s->budget--) { s->failed_pc=0x0c0a6834u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6836;
P_0c0a6836: /* original 7704, guest PC 0x0c0a6836 */
if(!s->budget--) { s->failed_pc=0x0c0a6836u; return 0; }
r[7]+=0x00000004u;
goto P_0c0a6838;
P_0c0a6838: /* original ff37, guest PC 0x0c0a6838 */
if(!s->budget--) { s->failed_pc=0x0c0a6838u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a683a;
P_0c0a683a: /* original e014, guest PC 0x0c0a683a */
if(!s->budget--) { s->failed_pc=0x0c0a683au; return 0; }
r[0]=0x00000014u;
goto P_0c0a683c;
P_0c0a683c: /* original f3e6, guest PC 0x0c0a683c */
if(!s->budget--) { s->failed_pc=0x0c0a683cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a683e;
P_0c0a683e: /* original e004, guest PC 0x0c0a683e */
if(!s->budget--) { s->failed_pc=0x0c0a683eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6840;
P_0c0a6840: /* original ff37, guest PC 0x0c0a6840 */
if(!s->budget--) { s->failed_pc=0x0c0a6840u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6842;
P_0c0a6842: /* original b104, guest PC 0x0c0a6842 */
if(!s->budget--) { s->failed_pc=0x0c0a6842u; return 0; }
target=0x0c0a6a4eu; r[16]=code_base|0x0c0a6846u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6846u) { target=s->pc; goto dispatch; }
goto P_0c0a6846;
P_0c0a6844: /* original 64d3, guest PC 0x0c0a6844 */
if(!s->budget--) { s->failed_pc=0x0c0a6844u; return 0; }
r[4]=r[13];
goto P_0c0a6846;
P_0c0a6846: /* original f3f8, guest PC 0x0c0a6846 */
if(!s->budget--) { s->failed_pc=0x0c0a6846u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0a6848;
P_0c0a6848: /* original e020, guest PC 0x0c0a6848 */
if(!s->budget--) { s->failed_pc=0x0c0a6848u; return 0; }
r[0]=0x00000020u;
goto P_0c0a684a;
P_0c0a684a: /* original 64f3, guest PC 0x0c0a684a */
if(!s->budget--) { s->failed_pc=0x0c0a684au; return 0; }
r[4]=r[15];
goto P_0c0a684c;
P_0c0a684c: /* original ff37, guest PC 0x0c0a684c */
if(!s->budget--) { s->failed_pc=0x0c0a684cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a684e;
P_0c0a684e: /* original e008, guest PC 0x0c0a684e */
if(!s->budget--) { s->failed_pc=0x0c0a684eu; return 0; }
r[0]=0x00000008u;
goto P_0c0a6850;
P_0c0a6850: /* original f3f6, guest PC 0x0c0a6850 */
if(!s->budget--) { s->failed_pc=0x0c0a6850u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6852;
P_0c0a6852: /* original e01c, guest PC 0x0c0a6852 */
if(!s->budget--) { s->failed_pc=0x0c0a6852u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6854;
P_0c0a6854: /* original ff37, guest PC 0x0c0a6854 */
if(!s->budget--) { s->failed_pc=0x0c0a6854u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6856;
P_0c0a6856: /* original e004, guest PC 0x0c0a6856 */
if(!s->budget--) { s->failed_pc=0x0c0a6856u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6858;
P_0c0a6858: /* original f3f6, guest PC 0x0c0a6858 */
if(!s->budget--) { s->failed_pc=0x0c0a6858u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a685a;
P_0c0a685a: /* original e018, guest PC 0x0c0a685a */
if(!s->budget--) { s->failed_pc=0x0c0a685au; return 0; }
r[0]=0x00000018u;
goto P_0c0a685c;
P_0c0a685c: /* original ff37, guest PC 0x0c0a685c */
if(!s->budget--) { s->failed_pc=0x0c0a685cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a685e;
P_0c0a685e: /* original d39c, guest PC 0x0c0a685e */
if(!s->budget--) { s->failed_pc=0x0c0a685eu; return 0; }
r[3]=read(ram,0x0c0a6ad0u,4);
goto P_0c0a6860;
P_0c0a6860: /* original 430b, guest PC 0x0c0a6860 */
if(!s->budget--) { s->failed_pc=0x0c0a6860u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6864u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6864u) { target=s->pc; goto dispatch; }
goto P_0c0a6864;
P_0c0a6862: /* original 7438, guest PC 0x0c0a6862 */
if(!s->budget--) { s->failed_pc=0x0c0a6862u; return 0; }
r[4]+=0x00000038u;
goto P_0c0a6864;
P_0c0a6864: /* original d29b, guest PC 0x0c0a6864 */
if(!s->budget--) { s->failed_pc=0x0c0a6864u; return 0; }
r[2]=read(ram,0x0c0a6ad4u,4);
goto P_0c0a6866;
P_0c0a6866: /* original 64d3, guest PC 0x0c0a6866 */
if(!s->budget--) { s->failed_pc=0x0c0a6866u; return 0; }
r[4]=r[13];
goto P_0c0a6868;
P_0c0a6868: /* original 420b, guest PC 0x0c0a6868 */
if(!s->budget--) { s->failed_pc=0x0c0a6868u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a686cu;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a686cu) { target=s->pc; goto dispatch; }
goto P_0c0a686c;
P_0c0a686a: /* original 7410, guest PC 0x0c0a686a */
if(!s->budget--) { s->failed_pc=0x0c0a686au; return 0; }
r[4]+=0x00000010u;
goto P_0c0a686c;
P_0c0a686c: /* original d39a, guest PC 0x0c0a686c */
if(!s->budget--) { s->failed_pc=0x0c0a686cu; return 0; }
r[3]=read(ram,0x0c0a6ad8u,4);
goto P_0c0a686e;
P_0c0a686e: /* original 64f3, guest PC 0x0c0a686e */
if(!s->budget--) { s->failed_pc=0x0c0a686eu; return 0; }
r[4]=r[15];
goto P_0c0a6870;
P_0c0a6870: /* original 430b, guest PC 0x0c0a6870 */
if(!s->budget--) { s->failed_pc=0x0c0a6870u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6874u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6874u) { target=s->pc; goto dispatch; }
goto P_0c0a6874;
P_0c0a6872: /* original 7438, guest PC 0x0c0a6872 */
if(!s->budget--) { s->failed_pc=0x0c0a6872u; return 0; }
r[4]+=0x00000038u;
goto P_0c0a6874;
P_0c0a6874: /* original e020, guest PC 0x0c0a6874 */
if(!s->budget--) { s->failed_pc=0x0c0a6874u; return 0; }
r[0]=0x00000020u;
goto P_0c0a6876;
P_0c0a6876: /* original f3f6, guest PC 0x0c0a6876 */
if(!s->budget--) { s->failed_pc=0x0c0a6876u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6878;
P_0c0a6878: /* original e044, guest PC 0x0c0a6878 */
if(!s->budget--) { s->failed_pc=0x0c0a6878u; return 0; }
r[0]=0x00000044u;
goto P_0c0a687a;
P_0c0a687a: /* original ff37, guest PC 0x0c0a687a */
if(!s->budget--) { s->failed_pc=0x0c0a687au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a687c;
P_0c0a687c: /* original e01c, guest PC 0x0c0a687c */
if(!s->budget--) { s->failed_pc=0x0c0a687cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0a687e;
P_0c0a687e: /* original f3f6, guest PC 0x0c0a687e */
if(!s->budget--) { s->failed_pc=0x0c0a687eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6880;
P_0c0a6880: /* original e048, guest PC 0x0c0a6880 */
if(!s->budget--) { s->failed_pc=0x0c0a6880u; return 0; }
r[0]=0x00000048u;
goto P_0c0a6882;
P_0c0a6882: /* original ff37, guest PC 0x0c0a6882 */
if(!s->budget--) { s->failed_pc=0x0c0a6882u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6884;
P_0c0a6884: /* original e018, guest PC 0x0c0a6884 */
if(!s->budget--) { s->failed_pc=0x0c0a6884u; return 0; }
r[0]=0x00000018u;
goto P_0c0a6886;
P_0c0a6886: /* original f3f6, guest PC 0x0c0a6886 */
if(!s->budget--) { s->failed_pc=0x0c0a6886u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6888;
P_0c0a6888: /* original e04c, guest PC 0x0c0a6888 */
if(!s->budget--) { s->failed_pc=0x0c0a6888u; return 0; }
r[0]=0x0000004cu;
goto P_0c0a688a;
P_0c0a688a: /* original ff37, guest PC 0x0c0a688a */
if(!s->budget--) { s->failed_pc=0x0c0a688au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a688c;
P_0c0a688c: /* original d38f, guest PC 0x0c0a688c */
if(!s->budget--) { s->failed_pc=0x0c0a688cu; return 0; }
r[3]=read(ram,0x0c0a6accu,4);
goto P_0c0a688e;
P_0c0a688e: /* original 430b, guest PC 0x0c0a688e */
if(!s->budget--) { s->failed_pc=0x0c0a688eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6892u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6892u) { target=s->pc; goto dispatch; }
goto P_0c0a6892;
P_0c0a6890: /* original e400, guest PC 0x0c0a6890 */
if(!s->budget--) { s->failed_pc=0x0c0a6890u; return 0; }
r[4]=0x00000000u;
goto P_0c0a6892;
P_0c0a6892: /* original d292, guest PC 0x0c0a6892 */
if(!s->budget--) { s->failed_pc=0x0c0a6892u; return 0; }
r[2]=read(ram,0x0c0a6adcu,4);
goto P_0c0a6894;
P_0c0a6894: /* original 420b, guest PC 0x0c0a6894 */
if(!s->budget--) { s->failed_pc=0x0c0a6894u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a6898u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6898u) { target=s->pc; goto dispatch; }
goto P_0c0a6898;
P_0c0a6896: /* original 0009, guest PC 0x0c0a6896 */
if(!s->budget--) { s->failed_pc=0x0c0a6896u; return 0; }
goto P_0c0a6898;
P_0c0a6898: /* original d391, guest PC 0x0c0a6898 */
if(!s->budget--) { s->failed_pc=0x0c0a6898u; return 0; }
r[3]=read(ram,0x0c0a6ae0u,4);
goto P_0c0a689a;
P_0c0a689a: /* original 65f3, guest PC 0x0c0a689a */
if(!s->budget--) { s->failed_pc=0x0c0a689au; return 0; }
r[5]=r[15];
goto P_0c0a689c;
P_0c0a689c: /* original 64f3, guest PC 0x0c0a689c */
if(!s->budget--) { s->failed_pc=0x0c0a689cu; return 0; }
r[4]=r[15];
goto P_0c0a689e;
P_0c0a689e: /* original 7544, guest PC 0x0c0a689e */
if(!s->budget--) { s->failed_pc=0x0c0a689eu; return 0; }
r[5]+=0x00000044u;
goto P_0c0a68a0;
P_0c0a68a0: /* original 430b, guest PC 0x0c0a68a0 */
if(!s->budget--) { s->failed_pc=0x0c0a68a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a68a4u;
r[4]+=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a68a4u) { target=s->pc; goto dispatch; }
goto P_0c0a68a4;
P_0c0a68a2: /* original 7444, guest PC 0x0c0a68a2 */
if(!s->budget--) { s->failed_pc=0x0c0a68a2u; return 0; }
r[4]+=0x00000044u;
goto P_0c0a68a4;
P_0c0a68a4: /* original d28f, guest PC 0x0c0a68a4 */
if(!s->budget--) { s->failed_pc=0x0c0a68a4u; return 0; }
r[2]=read(ram,0x0c0a6ae4u,4);
goto P_0c0a68a6;
P_0c0a68a6: /* original 420b, guest PC 0x0c0a68a6 */
if(!s->budget--) { s->failed_pc=0x0c0a68a6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a68aau;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a68aau) { target=s->pc; goto dispatch; }
goto P_0c0a68aa;
P_0c0a68a8: /* original e401, guest PC 0x0c0a68a8 */
if(!s->budget--) { s->failed_pc=0x0c0a68a8u; return 0; }
r[4]=0x00000001u;
goto P_0c0a68aa;
P_0c0a68aa: /* original e044, guest PC 0x0c0a68aa */
if(!s->budget--) { s->failed_pc=0x0c0a68aau; return 0; }
r[0]=0x00000044u;
goto P_0c0a68ac;
P_0c0a68ac: /* original 65e3, guest PC 0x0c0a68ac */
if(!s->budget--) { s->failed_pc=0x0c0a68acu; return 0; }
r[5]=r[14];
goto P_0c0a68ae;
P_0c0a68ae: /* original f3f6, guest PC 0x0c0a68ae */
if(!s->budget--) { s->failed_pc=0x0c0a68aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68b0;
P_0c0a68b0: /* original e014, guest PC 0x0c0a68b0 */
if(!s->budget--) { s->failed_pc=0x0c0a68b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0a68b2;
P_0c0a68b2: /* original ff37, guest PC 0x0c0a68b2 */
if(!s->budget--) { s->failed_pc=0x0c0a68b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68b4;
P_0c0a68b4: /* original e048, guest PC 0x0c0a68b4 */
if(!s->budget--) { s->failed_pc=0x0c0a68b4u; return 0; }
r[0]=0x00000048u;
goto P_0c0a68b6;
P_0c0a68b6: /* original f3f6, guest PC 0x0c0a68b6 */
if(!s->budget--) { s->failed_pc=0x0c0a68b6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68b8;
P_0c0a68b8: /* original e010, guest PC 0x0c0a68b8 */
if(!s->budget--) { s->failed_pc=0x0c0a68b8u; return 0; }
r[0]=0x00000010u;
goto P_0c0a68ba;
P_0c0a68ba: /* original ff37, guest PC 0x0c0a68ba */
if(!s->budget--) { s->failed_pc=0x0c0a68bau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68bc;
P_0c0a68bc: /* original e04c, guest PC 0x0c0a68bc */
if(!s->budget--) { s->failed_pc=0x0c0a68bcu; return 0; }
r[0]=0x0000004cu;
goto P_0c0a68be;
P_0c0a68be: /* original f3f6, guest PC 0x0c0a68be */
if(!s->budget--) { s->failed_pc=0x0c0a68beu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68c0;
P_0c0a68c0: /* original e024, guest PC 0x0c0a68c0 */
if(!s->budget--) { s->failed_pc=0x0c0a68c0u; return 0; }
r[0]=0x00000024u;
goto P_0c0a68c2;
P_0c0a68c2: /* original ff37, guest PC 0x0c0a68c2 */
if(!s->budget--) { s->failed_pc=0x0c0a68c2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68c4;
P_0c0a68c4: /* original b116, guest PC 0x0c0a68c4 */
if(!s->budget--) { s->failed_pc=0x0c0a68c4u; return 0; }
target=0x0c0a6af4u; r[16]=code_base|0x0c0a68c8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a68c8u) { target=s->pc; goto dispatch; }
goto P_0c0a68c8;
P_0c0a68c6: /* original 64d3, guest PC 0x0c0a68c6 */
if(!s->budget--) { s->failed_pc=0x0c0a68c6u; return 0; }
r[4]=r[13];
goto P_0c0a68c8;
P_0c0a68c8: /* original e05c, guest PC 0x0c0a68c8 */
if(!s->budget--) { s->failed_pc=0x0c0a68c8u; return 0; }
r[0]=0x0000005cu;
goto P_0c0a68ca;
P_0c0a68ca: /* original 66f3, guest PC 0x0c0a68ca */
if(!s->budget--) { s->failed_pc=0x0c0a68cau; return 0; }
r[6]=r[15];
goto P_0c0a68cc;
P_0c0a68cc: /* original fff7, guest PC 0x0c0a68cc */
if(!s->budget--) { s->failed_pc=0x0c0a68ccu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0a68ce;
P_0c0a68ce: /* original e060, guest PC 0x0c0a68ce */
if(!s->budget--) { s->failed_pc=0x0c0a68ceu; return 0; }
r[0]=0x00000060u;
goto P_0c0a68d0;
P_0c0a68d0: /* original fff7, guest PC 0x0c0a68d0 */
if(!s->budget--) { s->failed_pc=0x0c0a68d0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0a68d2;
P_0c0a68d2: /* original e064, guest PC 0x0c0a68d2 */
if(!s->budget--) { s->failed_pc=0x0c0a68d2u; return 0; }
r[0]=0x00000064u;
goto P_0c0a68d4;
P_0c0a68d4: /* original fff7, guest PC 0x0c0a68d4 */
if(!s->budget--) { s->failed_pc=0x0c0a68d4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0a68d6;
P_0c0a68d6: /* original e014, guest PC 0x0c0a68d6 */
if(!s->budget--) { s->failed_pc=0x0c0a68d6u; return 0; }
r[0]=0x00000014u;
goto P_0c0a68d8;
P_0c0a68d8: /* original f3f6, guest PC 0x0c0a68d8 */
if(!s->budget--) { s->failed_pc=0x0c0a68d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68da;
P_0c0a68da: /* original e050, guest PC 0x0c0a68da */
if(!s->budget--) { s->failed_pc=0x0c0a68dau; return 0; }
r[0]=0x00000050u;
goto P_0c0a68dc;
P_0c0a68dc: /* original 65f3, guest PC 0x0c0a68dc */
if(!s->budget--) { s->failed_pc=0x0c0a68dcu; return 0; }
r[5]=r[15];
goto P_0c0a68de;
P_0c0a68de: /* original 755c, guest PC 0x0c0a68de */
if(!s->budget--) { s->failed_pc=0x0c0a68deu; return 0; }
r[5]+=0x0000005cu;
goto P_0c0a68e0;
P_0c0a68e0: /* original ff37, guest PC 0x0c0a68e0 */
if(!s->budget--) { s->failed_pc=0x0c0a68e0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68e2;
P_0c0a68e2: /* original e010, guest PC 0x0c0a68e2 */
if(!s->budget--) { s->failed_pc=0x0c0a68e2u; return 0; }
r[0]=0x00000010u;
goto P_0c0a68e4;
P_0c0a68e4: /* original f3f6, guest PC 0x0c0a68e4 */
if(!s->budget--) { s->failed_pc=0x0c0a68e4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68e6;
P_0c0a68e6: /* original e054, guest PC 0x0c0a68e6 */
if(!s->budget--) { s->failed_pc=0x0c0a68e6u; return 0; }
r[0]=0x00000054u;
goto P_0c0a68e8;
P_0c0a68e8: /* original 7650, guest PC 0x0c0a68e8 */
if(!s->budget--) { s->failed_pc=0x0c0a68e8u; return 0; }
r[6]+=0x00000050u;
goto P_0c0a68ea;
P_0c0a68ea: /* original ff37, guest PC 0x0c0a68ea */
if(!s->budget--) { s->failed_pc=0x0c0a68eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68ec;
P_0c0a68ec: /* original e024, guest PC 0x0c0a68ec */
if(!s->budget--) { s->failed_pc=0x0c0a68ecu; return 0; }
r[0]=0x00000024u;
goto P_0c0a68ee;
P_0c0a68ee: /* original f3f6, guest PC 0x0c0a68ee */
if(!s->budget--) { s->failed_pc=0x0c0a68eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a68f0;
P_0c0a68f0: /* original e058, guest PC 0x0c0a68f0 */
if(!s->budget--) { s->failed_pc=0x0c0a68f0u; return 0; }
r[0]=0x00000058u;
goto P_0c0a68f2;
P_0c0a68f2: /* original ff37, guest PC 0x0c0a68f2 */
if(!s->budget--) { s->failed_pc=0x0c0a68f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a68f4;
P_0c0a68f4: /* original b18b, guest PC 0x0c0a68f4 */
if(!s->budget--) { s->failed_pc=0x0c0a68f4u; return 0; }
target=0x0c0a6c0eu; r[16]=code_base|0x0c0a68f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a68f8u) { target=s->pc; goto dispatch; }
goto P_0c0a68f8;
P_0c0a68f6: /* original 64e3, guest PC 0x0c0a68f6 */
if(!s->budget--) { s->failed_pc=0x0c0a68f6u; return 0; }
r[4]=r[14];
goto P_0c0a68f8;
P_0c0a68f8: /* original e05c, guest PC 0x0c0a68f8 */
if(!s->budget--) { s->failed_pc=0x0c0a68f8u; return 0; }
r[0]=0x0000005cu;
goto P_0c0a68fa;
P_0c0a68fa: /* original fdf6, guest PC 0x0c0a68fa */
if(!s->budget--) { s->failed_pc=0x0c0a68fau; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0a68fc;
P_0c0a68fc: /* original e060, guest PC 0x0c0a68fc */
if(!s->budget--) { s->failed_pc=0x0c0a68fcu; return 0; }
r[0]=0x00000060u;
goto P_0c0a68fe;
P_0c0a68fe: /* original f5f6, guest PC 0x0c0a68fe */
if(!s->budget--) { s->failed_pc=0x0c0a68feu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a6900;
P_0c0a6900: /* original e064, guest PC 0x0c0a6900 */
if(!s->budget--) { s->failed_pc=0x0c0a6900u; return 0; }
r[0]=0x00000064u;
goto P_0c0a6902;
P_0c0a6902: /* original fbf6, guest PC 0x0c0a6902 */
if(!s->budget--) { s->failed_pc=0x0c0a6902u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c0a6904;
P_0c0a6904: /* original e030, guest PC 0x0c0a6904 */
if(!s->budget--) { s->failed_pc=0x0c0a6904u; return 0; }
r[0]=0x00000030u;
goto P_0c0a6906;
P_0c0a6906: /* original fee6, guest PC 0x0c0a6906 */
if(!s->budget--) { s->failed_pc=0x0c0a6906u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0a6908;
P_0c0a6908: /* original e034, guest PC 0x0c0a6908 */
if(!s->budget--) { s->failed_pc=0x0c0a6908u; return 0; }
r[0]=0x00000034u;
goto P_0c0a690a;
P_0c0a690a: /* original fae6, guest PC 0x0c0a690a */
if(!s->budget--) { s->failed_pc=0x0c0a690au; return 0; }
vf3_matrix_load(s,ram,10,r[14]+r[0]);
goto P_0c0a690c;
P_0c0a690c: /* original e038, guest PC 0x0c0a690c */
if(!s->budget--) { s->failed_pc=0x0c0a690cu; return 0; }
r[0]=0x00000038u;
goto P_0c0a690e;
P_0c0a690e: /* original f3dc, guest PC 0x0c0a690e */
if(!s->budget--) { s->failed_pc=0x0c0a690eu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0a6910;
P_0c0a6910: /* original f3e2, guest PC 0x0c0a6910 */
if(!s->budget--) { s->failed_pc=0x0c0a6910u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0a6912;
P_0c0a6912: /* original f9e6, guest PC 0x0c0a6912 */
if(!s->budget--) { s->failed_pc=0x0c0a6912u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0a6914;
P_0c0a6914: /* original e030, guest PC 0x0c0a6914 */
if(!s->budget--) { s->failed_pc=0x0c0a6914u; return 0; }
r[0]=0x00000030u;
goto P_0c0a6916;
P_0c0a6916: /* original ff37, guest PC 0x0c0a6916 */
if(!s->budget--) { s->failed_pc=0x0c0a6916u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6918;
P_0c0a6918: /* original e02c, guest PC 0x0c0a6918 */
if(!s->budget--) { s->failed_pc=0x0c0a6918u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a691a;
P_0c0a691a: /* original f25c, guest PC 0x0c0a691a */
if(!s->budget--) { s->failed_pc=0x0c0a691au; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a691c;
P_0c0a691c: /* original f2a2, guest PC 0x0c0a691c */
if(!s->budget--) { s->failed_pc=0x0c0a691cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0a691e;
P_0c0a691e: /* original f13c, guest PC 0x0c0a691e */
if(!s->budget--) { s->failed_pc=0x0c0a691eu; return 0; }
vf3_matrix_move(s,1,3);
goto P_0c0a6920;
P_0c0a6920: /* original ff27, guest PC 0x0c0a6920 */
if(!s->budget--) { s->failed_pc=0x0c0a6920u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6922;
P_0c0a6922: /* original e028, guest PC 0x0c0a6922 */
if(!s->budget--) { s->failed_pc=0x0c0a6922u; return 0; }
r[0]=0x00000028u;
goto P_0c0a6924;
P_0c0a6924: /* original f42c, guest PC 0x0c0a6924 */
if(!s->budget--) { s->failed_pc=0x0c0a6924u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a6926;
P_0c0a6926: /* original f410, guest PC 0x0c0a6926 */
if(!s->budget--) { s->failed_pc=0x0c0a6926u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c0a6928;
P_0c0a6928: /* original f0bc, guest PC 0x0c0a6928 */
if(!s->budget--) { s->failed_pc=0x0c0a6928u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c0a692a;
P_0c0a692a: /* original f092, guest PC 0x0c0a692a */
if(!s->budget--) { s->failed_pc=0x0c0a692au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[9],r[18],'*');
goto P_0c0a692c;
P_0c0a692c: /* original f18d, guest PC 0x0c0a692c */
if(!s->budget--) { s->failed_pc=0x0c0a692cu; return 0; }
fr[1]=0;
goto P_0c0a692e;
P_0c0a692e: /* original f34c, guest PC 0x0c0a692e */
if(!s->budget--) { s->failed_pc=0x0c0a692eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a6930;
P_0c0a6930: /* original f40c, guest PC 0x0c0a6930 */
if(!s->budget--) { s->failed_pc=0x0c0a6930u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a6932;
P_0c0a6932: /* original f430, guest PC 0x0c0a6932 */
if(!s->budget--) { s->failed_pc=0x0c0a6932u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0a6934;
P_0c0a6934: /* original f415, guest PC 0x0c0a6934 */
if(!s->budget--) { s->failed_pc=0x0c0a6934u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[1]))!=0);
goto P_0c0a6936;
P_0c0a6936: /* original 8f6c, guest PC 0x0c0a6936 */
if(!s->budget--) { s->failed_pc=0x0c0a6936u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(!cond) { goto P_0c0a6a12; }
goto P_0c0a693a;
P_0c0a6938: /* original ff07, guest PC 0x0c0a6938 */
if(!s->budget--) { s->failed_pc=0x0c0a6938u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0a693a;
P_0c0a693a: /* original f3dc, guest PC 0x0c0a693a */
if(!s->budget--) { s->failed_pc=0x0c0a693au; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0a693c;
P_0c0a693c: /* original f3d2, guest PC 0x0c0a693c */
if(!s->budget--) { s->failed_pc=0x0c0a693cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c0a693e;
P_0c0a693e: /* original f05c, guest PC 0x0c0a693e */
if(!s->budget--) { s->failed_pc=0x0c0a693eu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0a6940;
P_0c0a6940: /* original f28d, guest PC 0x0c0a6940 */
if(!s->budget--) { s->failed_pc=0x0c0a6940u; return 0; }
fr[2]=0;
goto P_0c0a6942;
P_0c0a6942: /* original f35e, guest PC 0x0c0a6942 */
if(!s->budget--) { s->failed_pc=0x0c0a6942u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0a6944;
P_0c0a6944: /* original f0bc, guest PC 0x0c0a6944 */
if(!s->budget--) { s->failed_pc=0x0c0a6944u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c0a6946;
P_0c0a6946: /* original f3be, guest PC 0x0c0a6946 */
if(!s->budget--) { s->failed_pc=0x0c0a6946u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[11],fr[3],r[18]);
goto P_0c0a6948;
P_0c0a6948: /* original f325, guest PC 0x0c0a6948 */
if(!s->budget--) { s->failed_pc=0x0c0a6948u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0a694a;
P_0c0a694a: /* original 8f62, guest PC 0x0c0a694a */
if(!s->budget--) { s->failed_pc=0x0c0a694au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(!cond) { goto P_0c0a6a12; }
goto P_0c0a694e;
P_0c0a694c: /* original ff3a, guest PC 0x0c0a694c */
if(!s->budget--) { s->failed_pc=0x0c0a694cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a694e;
P_0c0a694e: /* original f7ec, guest PC 0x0c0a694e */
if(!s->budget--) { s->failed_pc=0x0c0a694eu; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c0a6950;
P_0c0a6950: /* original f742, guest PC 0x0c0a6950 */
if(!s->budget--) { s->failed_pc=0x0c0a6950u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a6952;
P_0c0a6952: /* original f8ac, guest PC 0x0c0a6952 */
if(!s->budget--) { s->failed_pc=0x0c0a6952u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c0a6954;
P_0c0a6954: /* original f842, guest PC 0x0c0a6954 */
if(!s->budget--) { s->failed_pc=0x0c0a6954u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0a6956;
P_0c0a6956: /* original f69c, guest PC 0x0c0a6956 */
if(!s->budget--) { s->failed_pc=0x0c0a6956u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c0a6958;
P_0c0a6958: /* original f642, guest PC 0x0c0a6958 */
if(!s->budget--) { s->failed_pc=0x0c0a6958u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a695a;
P_0c0a695a: /* original c763, guest PC 0x0c0a695a */
if(!s->budget--) { s->failed_pc=0x0c0a695au; return 0; }
r[0]=0x0c0a6ae8u;
goto P_0c0a695c;
P_0c0a695c: /* original f37c, guest PC 0x0c0a695c */
if(!s->budget--) { s->failed_pc=0x0c0a695cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0a695e;
P_0c0a695e: /* original f7dc, guest PC 0x0c0a695e */
if(!s->budget--) { s->failed_pc=0x0c0a695eu; return 0; }
vf3_matrix_move(s,7,13);
goto P_0c0a6960;
P_0c0a6960: /* original f731, guest PC 0x0c0a6960 */
if(!s->budget--) { s->failed_pc=0x0c0a6960u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0a6962;
P_0c0a6962: /* original f38c, guest PC 0x0c0a6962 */
if(!s->budget--) { s->failed_pc=0x0c0a6962u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0a6964;
P_0c0a6964: /* original f85c, guest PC 0x0c0a6964 */
if(!s->budget--) { s->failed_pc=0x0c0a6964u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0a6966;
P_0c0a6966: /* original f831, guest PC 0x0c0a6966 */
if(!s->budget--) { s->failed_pc=0x0c0a6966u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a6968;
P_0c0a6968: /* original f36c, guest PC 0x0c0a6968 */
if(!s->budget--) { s->failed_pc=0x0c0a6968u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a696a;
P_0c0a696a: /* original f57c, guest PC 0x0c0a696a */
if(!s->budget--) { s->failed_pc=0x0c0a696au; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0a696c;
P_0c0a696c: /* original f572, guest PC 0x0c0a696c */
if(!s->budget--) { s->failed_pc=0x0c0a696cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0a696e;
P_0c0a696e: /* original f6bc, guest PC 0x0c0a696e */
if(!s->budget--) { s->failed_pc=0x0c0a696eu; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c0a6970;
P_0c0a6970: /* original f631, guest PC 0x0c0a6970 */
if(!s->budget--) { s->failed_pc=0x0c0a6970u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a6972;
P_0c0a6972: /* original f08c, guest PC 0x0c0a6972 */
if(!s->budget--) { s->failed_pc=0x0c0a6972u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c0a6974;
P_0c0a6974: /* original f25c, guest PC 0x0c0a6974 */
if(!s->budget--) { s->failed_pc=0x0c0a6974u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a6976;
P_0c0a6976: /* original f28e, guest PC 0x0c0a6976 */
if(!s->budget--) { s->failed_pc=0x0c0a6976u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0a6978;
P_0c0a6978: /* original f06c, guest PC 0x0c0a6978 */
if(!s->budget--) { s->failed_pc=0x0c0a6978u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0a697a;
P_0c0a697a: /* original f32c, guest PC 0x0c0a697a */
if(!s->budget--) { s->failed_pc=0x0c0a697au; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0a697c;
P_0c0a697c: /* original f36e, guest PC 0x0c0a697c */
if(!s->budget--) { s->failed_pc=0x0c0a697cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0a697e;
P_0c0a697e: /* original f208, guest PC 0x0c0a697e */
if(!s->budget--) { s->failed_pc=0x0c0a697eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0a6980;
P_0c0a6980: /* original f53c, guest PC 0x0c0a6980 */
if(!s->budget--) { s->failed_pc=0x0c0a6980u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0a6982;
P_0c0a6982: /* original f255, guest PC 0x0c0a6982 */
if(!s->budget--) { s->failed_pc=0x0c0a6982u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
goto P_0c0a6984;
P_0c0a6984: /* original 8f02, guest PC 0x0c0a6984 */
if(!s->budget--) { s->failed_pc=0x0c0a6984u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c0a698c; }
goto P_0c0a6988;
P_0c0a6986: /* original f34c, guest PC 0x0c0a6986 */
if(!s->budget--) { s->failed_pc=0x0c0a6986u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a6988;
P_0c0a6988: /* original a002, guest PC 0x0c0a6988 */
if(!s->budget--) { s->failed_pc=0x0c0a6988u; return 0; }
fr[11]=0;
goto P_0c0a6990;
P_0c0a698a: /* original fb8d, guest PC 0x0c0a698a */
if(!s->budget--) { s->failed_pc=0x0c0a698au; return 0; }
fr[11]=0;
goto P_0c0a698c;
P_0c0a698c: /* original fb5c, guest PC 0x0c0a698c */
if(!s->budget--) { s->failed_pc=0x0c0a698cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0a698e;
P_0c0a698e: /* original fb6d, guest PC 0x0c0a698e */
if(!s->budget--) { s->failed_pc=0x0c0a698eu; return 0; }
fr[11]=vf3_fpu_sqrt(fr[11],r[18]);
goto P_0c0a6990;
P_0c0a6990: /* original f4bc, guest PC 0x0c0a6990 */
if(!s->budget--) { s->failed_pc=0x0c0a6990u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c0a6992;
P_0c0a6992: /* original f433, guest PC 0x0c0a6992 */
if(!s->budget--) { s->failed_pc=0x0c0a6992u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0a6994;
P_0c0a6994: /* original e074, guest PC 0x0c0a6994 */
if(!s->budget--) { s->failed_pc=0x0c0a6994u; return 0; }
r[0]=0x00000074u;
goto P_0c0a6996;
P_0c0a6996: /* original f5d6, guest PC 0x0c0a6996 */
if(!s->budget--) { s->failed_pc=0x0c0a6996u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a6998;
P_0c0a6998: /* original e034, guest PC 0x0c0a6998 */
if(!s->budget--) { s->failed_pc=0x0c0a6998u; return 0; }
r[0]=0x00000034u;
goto P_0c0a699a;
P_0c0a699a: /* original f3f6, guest PC 0x0c0a699a */
if(!s->budget--) { s->failed_pc=0x0c0a699au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a699c;
P_0c0a699c: /* original e078, guest PC 0x0c0a699c */
if(!s->budget--) { s->failed_pc=0x0c0a699cu; return 0; }
r[0]=0x00000078u;
goto P_0c0a699e;
P_0c0a699e: /* original f530, guest PC 0x0c0a699e */
if(!s->budget--) { s->failed_pc=0x0c0a699eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a69a0;
P_0c0a69a0: /* original f453, guest PC 0x0c0a69a0 */
if(!s->budget--) { s->failed_pc=0x0c0a69a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0a69a2;
P_0c0a69a2: /* original f5d6, guest PC 0x0c0a69a2 */
if(!s->budget--) { s->failed_pc=0x0c0a69a2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a69a4;
P_0c0a69a4: /* original f455, guest PC 0x0c0a69a4 */
if(!s->budget--) { s->failed_pc=0x0c0a69a4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a69a6;
P_0c0a69a6: /* original 8f01, guest PC 0x0c0a69a6 */
if(!s->budget--) { s->failed_pc=0x0c0a69a6u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c0a69ac; }
goto P_0c0a69aa;
P_0c0a69a8: /* original f38d, guest PC 0x0c0a69a8 */
if(!s->budget--) { s->failed_pc=0x0c0a69a8u; return 0; }
fr[3]=0;
goto P_0c0a69aa;
P_0c0a69aa: /* original f45c, guest PC 0x0c0a69aa */
if(!s->budget--) { s->failed_pc=0x0c0a69aau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a69ac;
P_0c0a69ac: /* original fb35, guest PC 0x0c0a69ac */
if(!s->budget--) { s->failed_pc=0x0c0a69acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c0a69ae;
P_0c0a69ae: /* original 8901, guest PC 0x0c0a69ae */
if(!s->budget--) { s->failed_pc=0x0c0a69aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a69b4; }
goto P_0c0a69b0;
P_0c0a69b0: /* original a001, guest PC 0x0c0a69b0 */
if(!s->budget--) { s->failed_pc=0x0c0a69b0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a69b6;
P_0c0a69b2: /* original f4fc, guest PC 0x0c0a69b2 */
if(!s->budget--) { s->failed_pc=0x0c0a69b2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a69b4;
P_0c0a69b4: /* original f4b3, guest PC 0x0c0a69b4 */
if(!s->budget--) { s->failed_pc=0x0c0a69b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'/');
goto P_0c0a69b6;
P_0c0a69b6: /* original f04c, guest PC 0x0c0a69b6 */
if(!s->budget--) { s->failed_pc=0x0c0a69b6u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0a69b8;
P_0c0a69b8: /* original e030, guest PC 0x0c0a69b8 */
if(!s->budget--) { s->failed_pc=0x0c0a69b8u; return 0; }
r[0]=0x00000030u;
goto P_0c0a69ba;
P_0c0a69ba: /* original fbec, guest PC 0x0c0a69ba */
if(!s->budget--) { s->failed_pc=0x0c0a69bau; return 0; }
vf3_matrix_move(s,11,14);
goto P_0c0a69bc;
P_0c0a69bc: /* original fb7e, guest PC 0x0c0a69bc */
if(!s->budget--) { s->failed_pc=0x0c0a69bcu; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[7],fr[11],r[18]);
goto P_0c0a69be;
P_0c0a69be: /* original f4ec, guest PC 0x0c0a69be */
if(!s->budget--) { s->failed_pc=0x0c0a69beu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a69c0;
P_0c0a69c0: /* original f7ac, guest PC 0x0c0a69c0 */
if(!s->budget--) { s->failed_pc=0x0c0a69c0u; return 0; }
vf3_matrix_move(s,7,10);
goto P_0c0a69c2;
P_0c0a69c2: /* original f78e, guest PC 0x0c0a69c2 */
if(!s->budget--) { s->failed_pc=0x0c0a69c2u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[8],fr[7],r[18]);
goto P_0c0a69c4;
P_0c0a69c4: /* original f39c, guest PC 0x0c0a69c4 */
if(!s->budget--) { s->failed_pc=0x0c0a69c4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0a69c6;
P_0c0a69c6: /* original f36e, guest PC 0x0c0a69c6 */
if(!s->budget--) { s->failed_pc=0x0c0a69c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0a69c8;
P_0c0a69c8: /* original f4b2, guest PC 0x0c0a69c8 */
if(!s->budget--) { s->failed_pc=0x0c0a69c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'*');
goto P_0c0a69ca;
P_0c0a69ca: /* original f5f6, guest PC 0x0c0a69ca */
if(!s->budget--) { s->failed_pc=0x0c0a69cau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a69cc;
P_0c0a69cc: /* original e02c, guest PC 0x0c0a69cc */
if(!s->budget--) { s->failed_pc=0x0c0a69ccu; return 0; }
r[0]=0x0000002cu;
goto P_0c0a69ce;
P_0c0a69ce: /* original f07c, guest PC 0x0c0a69ce */
if(!s->budget--) { s->failed_pc=0x0c0a69ceu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0a69d0;
P_0c0a69d0: /* original f63c, guest PC 0x0c0a69d0 */
if(!s->budget--) { s->failed_pc=0x0c0a69d0u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0a69d2;
P_0c0a69d2: /* original f24c, guest PC 0x0c0a69d2 */
if(!s->budget--) { s->failed_pc=0x0c0a69d2u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0a69d4;
P_0c0a69d4: /* original f2ae, guest PC 0x0c0a69d4 */
if(!s->budget--) { s->failed_pc=0x0c0a69d4u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[10],fr[2],r[18]);
goto P_0c0a69d6;
P_0c0a69d6: /* original f06c, guest PC 0x0c0a69d6 */
if(!s->budget--) { s->failed_pc=0x0c0a69d6u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0a69d8;
P_0c0a69d8: /* original f32c, guest PC 0x0c0a69d8 */
if(!s->budget--) { s->failed_pc=0x0c0a69d8u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0a69da;
P_0c0a69da: /* original f39e, guest PC 0x0c0a69da */
if(!s->budget--) { s->failed_pc=0x0c0a69dau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0a69dc;
P_0c0a69dc: /* original f43c, guest PC 0x0c0a69dc */
if(!s->budget--) { s->failed_pc=0x0c0a69dcu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a69de;
P_0c0a69de: /* original f35c, guest PC 0x0c0a69de */
if(!s->budget--) { s->failed_pc=0x0c0a69deu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0a69e0;
P_0c0a69e0: /* original f5f6, guest PC 0x0c0a69e0 */
if(!s->budget--) { s->failed_pc=0x0c0a69e0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a69e2;
P_0c0a69e2: /* original e028, guest PC 0x0c0a69e2 */
if(!s->budget--) { s->failed_pc=0x0c0a69e2u; return 0; }
r[0]=0x00000028u;
goto P_0c0a69e4;
P_0c0a69e4: /* original f530, guest PC 0x0c0a69e4 */
if(!s->budget--) { s->failed_pc=0x0c0a69e4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a69e6;
P_0c0a69e6: /* original f35c, guest PC 0x0c0a69e6 */
if(!s->budget--) { s->failed_pc=0x0c0a69e6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0a69e8;
P_0c0a69e8: /* original f5f6, guest PC 0x0c0a69e8 */
if(!s->budget--) { s->failed_pc=0x0c0a69e8u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a69ea;
P_0c0a69ea: /* original e074, guest PC 0x0c0a69ea */
if(!s->budget--) { s->failed_pc=0x0c0a69eau; return 0; }
r[0]=0x00000074u;
goto P_0c0a69ec;
P_0c0a69ec: /* original f530, guest PC 0x0c0a69ec */
if(!s->budget--) { s->failed_pc=0x0c0a69ecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0a69ee;
P_0c0a69ee: /* original f34c, guest PC 0x0c0a69ee */
if(!s->budget--) { s->failed_pc=0x0c0a69eeu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a69f0;
P_0c0a69f0: /* original f45c, guest PC 0x0c0a69f0 */
if(!s->budget--) { s->failed_pc=0x0c0a69f0u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a69f2;
P_0c0a69f2: /* original f433, guest PC 0x0c0a69f2 */
if(!s->budget--) { s->failed_pc=0x0c0a69f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0a69f4;
P_0c0a69f4: /* original f45d, guest PC 0x0c0a69f4 */
if(!s->budget--) { s->failed_pc=0x0c0a69f4u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0a69f6;
P_0c0a69f6: /* original f5d6, guest PC 0x0c0a69f6 */
if(!s->budget--) { s->failed_pc=0x0c0a69f6u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a69f8;
P_0c0a69f8: /* original e008, guest PC 0x0c0a69f8 */
if(!s->budget--) { s->failed_pc=0x0c0a69f8u; return 0; }
r[0]=0x00000008u;
goto P_0c0a69fa;
P_0c0a69fa: /* original f34c, guest PC 0x0c0a69fa */
if(!s->budget--) { s->failed_pc=0x0c0a69fau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0a69fc;
P_0c0a69fc: /* original f05c, guest PC 0x0c0a69fc */
if(!s->budget--) { s->failed_pc=0x0c0a69fcu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0a69fe;
P_0c0a69fe: /* original f34e, guest PC 0x0c0a69fe */
if(!s->budget--) { s->failed_pc=0x0c0a69feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0a6a00;
P_0c0a6a00: /* original f43c, guest PC 0x0c0a6a00 */
if(!s->budget--) { s->failed_pc=0x0c0a6a00u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a6a02;
P_0c0a6a02: /* original f742, guest PC 0x0c0a6a02 */
if(!s->budget--) { s->failed_pc=0x0c0a6a02u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a6a04;
P_0c0a6a04: /* original fb42, guest PC 0x0c0a6a04 */
if(!s->budget--) { s->failed_pc=0x0c0a6a04u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'*');
goto P_0c0a6a06;
P_0c0a6a06: /* original f642, guest PC 0x0c0a6a06 */
if(!s->budget--) { s->failed_pc=0x0c0a6a06u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a6a08;
P_0c0a6a08: /* original ffba, guest PC 0x0c0a6a08 */
if(!s->budget--) { s->failed_pc=0x0c0a6a08u; return 0; }
vf3_matrix_store(s,ram,11,r[15]);
goto P_0c0a6a0a;
P_0c0a6a0a: /* original ff77, guest PC 0x0c0a6a0a */
if(!s->budget--) { s->failed_pc=0x0c0a6a0au; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0a6a0c;
P_0c0a6a0c: /* original e004, guest PC 0x0c0a6a0c */
if(!s->budget--) { s->failed_pc=0x0c0a6a0cu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6a0e;
P_0c0a6a0e: /* original a005, guest PC 0x0c0a6a0e */
if(!s->budget--) { s->failed_pc=0x0c0a6a0eu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0a6a1c;
P_0c0a6a10: /* original ff67, guest PC 0x0c0a6a10 */
if(!s->budget--) { s->failed_pc=0x0c0a6a10u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0a6a12;
P_0c0a6a12: /* original e008, guest PC 0x0c0a6a12 */
if(!s->budget--) { s->failed_pc=0x0c0a6a12u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6a14;
P_0c0a6a14: /* original fffa, guest PC 0x0c0a6a14 */
if(!s->budget--) { s->failed_pc=0x0c0a6a14u; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a6a16;
P_0c0a6a16: /* original fff7, guest PC 0x0c0a6a16 */
if(!s->budget--) { s->failed_pc=0x0c0a6a16u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0a6a18;
P_0c0a6a18: /* original e004, guest PC 0x0c0a6a18 */
if(!s->budget--) { s->failed_pc=0x0c0a6a18u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6a1a;
P_0c0a6a1a: /* original fff7, guest PC 0x0c0a6a1a */
if(!s->budget--) { s->failed_pc=0x0c0a6a1au; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0a6a1c;
P_0c0a6a1c: /* original d331, guest PC 0x0c0a6a1c */
if(!s->budget--) { s->failed_pc=0x0c0a6a1cu; return 0; }
r[3]=read(ram,0x0c0a6ae4u,4);
goto P_0c0a6a1e;
P_0c0a6a1e: /* original 430b, guest PC 0x0c0a6a1e */
if(!s->budget--) { s->failed_pc=0x0c0a6a1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6a22u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6a22u) { target=s->pc; goto dispatch; }
goto P_0c0a6a22;
P_0c0a6a20: /* original e401, guest PC 0x0c0a6a20 */
if(!s->budget--) { s->failed_pc=0x0c0a6a20u; return 0; }
r[4]=0x00000001u;
goto P_0c0a6a22;
P_0c0a6a22: /* original e05c, guest PC 0x0c0a6a22 */
if(!s->budget--) { s->failed_pc=0x0c0a6a22u; return 0; }
r[0]=0x0000005cu;
goto P_0c0a6a24;
P_0c0a6a24: /* original f3f6, guest PC 0x0c0a6a24 */
if(!s->budget--) { s->failed_pc=0x0c0a6a24u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6a26;
P_0c0a6a26: /* original e060, guest PC 0x0c0a6a26 */
if(!s->budget--) { s->failed_pc=0x0c0a6a26u; return 0; }
r[0]=0x00000060u;
goto P_0c0a6a28;
P_0c0a6a28: /* original fc3a, guest PC 0x0c0a6a28 */
if(!s->budget--) { s->failed_pc=0x0c0a6a28u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c0a6a2a;
P_0c0a6a2a: /* original f3f6, guest PC 0x0c0a6a2a */
if(!s->budget--) { s->failed_pc=0x0c0a6a2au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6a2c;
P_0c0a6a2c: /* original e004, guest PC 0x0c0a6a2c */
if(!s->budget--) { s->failed_pc=0x0c0a6a2cu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6a2e;
P_0c0a6a2e: /* original fc37, guest PC 0x0c0a6a2e */
if(!s->budget--) { s->failed_pc=0x0c0a6a2eu; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c0a6a30;
P_0c0a6a30: /* original e064, guest PC 0x0c0a6a30 */
if(!s->budget--) { s->failed_pc=0x0c0a6a30u; return 0; }
r[0]=0x00000064u;
goto P_0c0a6a32;
P_0c0a6a32: /* original f3f6, guest PC 0x0c0a6a32 */
if(!s->budget--) { s->failed_pc=0x0c0a6a32u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6a34;
P_0c0a6a34: /* original 7f68, guest PC 0x0c0a6a34 */
if(!s->budget--) { s->failed_pc=0x0c0a6a34u; return 0; }
r[15]+=0x00000068u;
goto P_0c0a6a36;
P_0c0a6a36: /* original 4f26, guest PC 0x0c0a6a36 */
if(!s->budget--) { s->failed_pc=0x0c0a6a36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6a38;
P_0c0a6a38: /* original e008, guest PC 0x0c0a6a38 */
if(!s->budget--) { s->failed_pc=0x0c0a6a38u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6a3a;
P_0c0a6a3a: /* original fc37, guest PC 0x0c0a6a3a */
if(!s->budget--) { s->failed_pc=0x0c0a6a3au; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c0a6a3c;
P_0c0a6a3c: /* original fdf9, guest PC 0x0c0a6a3c */
if(!s->budget--) { s->failed_pc=0x0c0a6a3cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6a3e;
P_0c0a6a3e: /* original fef9, guest PC 0x0c0a6a3e */
if(!s->budget--) { s->failed_pc=0x0c0a6a3eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6a40;
P_0c0a6a40: /* original fff9, guest PC 0x0c0a6a40 */
if(!s->budget--) { s->failed_pc=0x0c0a6a40u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6a42;
P_0c0a6a42: /* original 6af6, guest PC 0x0c0a6a42 */
if(!s->budget--) { s->failed_pc=0x0c0a6a42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a6a44;
P_0c0a6a44: /* original 6bf6, guest PC 0x0c0a6a44 */
if(!s->budget--) { s->failed_pc=0x0c0a6a44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a6a46;
P_0c0a6a46: /* original 6cf6, guest PC 0x0c0a6a46 */
if(!s->budget--) { s->failed_pc=0x0c0a6a46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a6a48;
P_0c0a6a48: /* original 6df6, guest PC 0x0c0a6a48 */
if(!s->budget--) { s->failed_pc=0x0c0a6a48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a6a4a;
P_0c0a6a4a: /* original 000b, guest PC 0x0c0a6a4a */
if(!s->budget--) { s->failed_pc=0x0c0a6a4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a6a4c: /* original 6ef6, guest PC 0x0c0a6a4c */
if(!s->budget--) { s->failed_pc=0x0c0a6a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a6a4e;
P_0c0a6a4e: /* original 2fe6, guest PC 0x0c0a6a4e */
if(!s->budget--) { s->failed_pc=0x0c0a6a4eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a6a50;
P_0c0a6a50: /* original e00c, guest PC 0x0c0a6a50 */
if(!s->budget--) { s->failed_pc=0x0c0a6a50u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6a52;
P_0c0a6a52: /* original 4f22, guest PC 0x0c0a6a52 */
if(!s->budget--) { s->failed_pc=0x0c0a6a52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a6a54;
P_0c0a6a54: /* original 6e43, guest PC 0x0c0a6a54 */
if(!s->budget--) { s->failed_pc=0x0c0a6a54u; return 0; }
r[14]=r[4];
goto P_0c0a6a56;
P_0c0a6a56: /* original 7fe8, guest PC 0x0c0a6a56 */
if(!s->budget--) { s->failed_pc=0x0c0a6a56u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0a6a58;
P_0c0a6a58: /* original 1f52, guest PC 0x0c0a6a58 */
if(!s->budget--) { s->failed_pc=0x0c0a6a58u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a6a5a;
P_0c0a6a5a: /* original 2f62, guest PC 0x0c0a6a5a */
if(!s->budget--) { s->failed_pc=0x0c0a6a5au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a6a5c;
P_0c0a6a5c: /* original 1f71, guest PC 0x0c0a6a5c */
if(!s->budget--) { s->failed_pc=0x0c0a6a5cu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0a6a5e;
P_0c0a6a5e: /* original 53f2, guest PC 0x0c0a6a5e */
if(!s->budget--) { s->failed_pc=0x0c0a6a5eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a6a60;
P_0c0a6a60: /* original f338, guest PC 0x0c0a6a60 */
if(!s->budget--) { s->failed_pc=0x0c0a6a60u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0a6a62;
P_0c0a6a62: /* original ff37, guest PC 0x0c0a6a62 */
if(!s->budget--) { s->failed_pc=0x0c0a6a62u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6a64;
P_0c0a6a64: /* original e010, guest PC 0x0c0a6a64 */
if(!s->budget--) { s->failed_pc=0x0c0a6a64u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6a66;
P_0c0a6a66: /* original 63f2, guest PC 0x0c0a6a66 */
if(!s->budget--) { s->failed_pc=0x0c0a6a66u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a6a68;
P_0c0a6a68: /* original f338, guest PC 0x0c0a6a68 */
if(!s->budget--) { s->failed_pc=0x0c0a6a68u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0a6a6a;
P_0c0a6a6a: /* original ff37, guest PC 0x0c0a6a6a */
if(!s->budget--) { s->failed_pc=0x0c0a6a6au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6a6c;
P_0c0a6a6c: /* original e014, guest PC 0x0c0a6a6c */
if(!s->budget--) { s->failed_pc=0x0c0a6a6cu; return 0; }
r[0]=0x00000014u;
goto P_0c0a6a6e;
P_0c0a6a6e: /* original 53f1, guest PC 0x0c0a6a6e */
if(!s->budget--) { s->failed_pc=0x0c0a6a6eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a6a70;
P_0c0a6a70: /* original f338, guest PC 0x0c0a6a70 */
if(!s->budget--) { s->failed_pc=0x0c0a6a70u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0a6a72;
P_0c0a6a72: /* original ff37, guest PC 0x0c0a6a72 */
if(!s->budget--) { s->failed_pc=0x0c0a6a72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6a74;
P_0c0a6a74: /* original d315, guest PC 0x0c0a6a74 */
if(!s->budget--) { s->failed_pc=0x0c0a6a74u; return 0; }
r[3]=read(ram,0x0c0a6accu,4);
goto P_0c0a6a76;
P_0c0a6a76: /* original 430b, guest PC 0x0c0a6a76 */
if(!s->budget--) { s->failed_pc=0x0c0a6a76u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6a7au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6a7au) { target=s->pc; goto dispatch; }
goto P_0c0a6a7a;
P_0c0a6a78: /* original e400, guest PC 0x0c0a6a78 */
if(!s->budget--) { s->failed_pc=0x0c0a6a78u; return 0; }
r[4]=0x00000000u;
goto P_0c0a6a7a;
P_0c0a6a7a: /* original d216, guest PC 0x0c0a6a7a */
if(!s->budget--) { s->failed_pc=0x0c0a6a7au; return 0; }
r[2]=read(ram,0x0c0a6ad4u,4);
goto P_0c0a6a7c;
P_0c0a6a7c: /* original 64e3, guest PC 0x0c0a6a7c */
if(!s->budget--) { s->failed_pc=0x0c0a6a7cu; return 0; }
r[4]=r[14];
goto P_0c0a6a7e;
P_0c0a6a7e: /* original 420b, guest PC 0x0c0a6a7e */
if(!s->budget--) { s->failed_pc=0x0c0a6a7eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a6a82u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6a82u) { target=s->pc; goto dispatch; }
goto P_0c0a6a82;
P_0c0a6a80: /* original 7410, guest PC 0x0c0a6a80 */
if(!s->budget--) { s->failed_pc=0x0c0a6a80u; return 0; }
r[4]+=0x00000010u;
goto P_0c0a6a82;
P_0c0a6a82: /* original d315, guest PC 0x0c0a6a82 */
if(!s->budget--) { s->failed_pc=0x0c0a6a82u; return 0; }
r[3]=read(ram,0x0c0a6ad8u,4);
goto P_0c0a6a84;
P_0c0a6a84: /* original 64e3, guest PC 0x0c0a6a84 */
if(!s->budget--) { s->failed_pc=0x0c0a6a84u; return 0; }
r[4]=r[14];
goto P_0c0a6a86;
P_0c0a6a86: /* original 430b, guest PC 0x0c0a6a86 */
if(!s->budget--) { s->failed_pc=0x0c0a6a86u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6a8au;
r[4]+=0x0000005cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6a8au) { target=s->pc; goto dispatch; }
goto P_0c0a6a8a;
P_0c0a6a88: /* original 745c, guest PC 0x0c0a6a88 */
if(!s->budget--) { s->failed_pc=0x0c0a6a88u; return 0; }
r[4]+=0x0000005cu;
goto P_0c0a6a8a;
P_0c0a6a8a: /* original 65f3, guest PC 0x0c0a6a8a */
if(!s->budget--) { s->failed_pc=0x0c0a6a8au; return 0; }
r[5]=r[15];
goto P_0c0a6a8c;
P_0c0a6a8c: /* original d217, guest PC 0x0c0a6a8c */
if(!s->budget--) { s->failed_pc=0x0c0a6a8cu; return 0; }
r[2]=read(ram,0x0c0a6aecu,4);
goto P_0c0a6a8e;
P_0c0a6a8e: /* original 66f3, guest PC 0x0c0a6a8e */
if(!s->budget--) { s->failed_pc=0x0c0a6a8eu; return 0; }
r[6]=r[15];
goto P_0c0a6a90;
P_0c0a6a90: /* original 64e3, guest PC 0x0c0a6a90 */
if(!s->budget--) { s->failed_pc=0x0c0a6a90u; return 0; }
r[4]=r[14];
goto P_0c0a6a92;
P_0c0a6a92: /* original 760c, guest PC 0x0c0a6a92 */
if(!s->budget--) { s->failed_pc=0x0c0a6a92u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0a6a94;
P_0c0a6a94: /* original 750c, guest PC 0x0c0a6a94 */
if(!s->budget--) { s->failed_pc=0x0c0a6a94u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0a6a96;
P_0c0a6a96: /* original 420b, guest PC 0x0c0a6a96 */
if(!s->budget--) { s->failed_pc=0x0c0a6a96u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a6a9au;
r[4]+=0x00000050u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6a9au) { target=s->pc; goto dispatch; }
goto P_0c0a6a9a;
P_0c0a6a98: /* original 7450, guest PC 0x0c0a6a98 */
if(!s->budget--) { s->failed_pc=0x0c0a6a98u; return 0; }
r[4]+=0x00000050u;
goto P_0c0a6a9a;
P_0c0a6a9a: /* original d315, guest PC 0x0c0a6a9a */
if(!s->budget--) { s->failed_pc=0x0c0a6a9au; return 0; }
r[3]=read(ram,0x0c0a6af0u,4);
goto P_0c0a6a9c;
P_0c0a6a9c: /* original 65f3, guest PC 0x0c0a6a9c */
if(!s->budget--) { s->failed_pc=0x0c0a6a9cu; return 0; }
r[5]=r[15];
goto P_0c0a6a9e;
P_0c0a6a9e: /* original 64f3, guest PC 0x0c0a6a9e */
if(!s->budget--) { s->failed_pc=0x0c0a6a9eu; return 0; }
r[4]=r[15];
goto P_0c0a6aa0;
P_0c0a6aa0: /* original 750c, guest PC 0x0c0a6aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a6aa0u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0a6aa2;
P_0c0a6aa2: /* original 430b, guest PC 0x0c0a6aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a6aa2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a6aa6u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6aa6u) { target=s->pc; goto dispatch; }
goto P_0c0a6aa6;
P_0c0a6aa4: /* original 740c, guest PC 0x0c0a6aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a6aa4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a6aa6;
P_0c0a6aa6: /* original d20f, guest PC 0x0c0a6aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a6aa6u; return 0; }
r[2]=read(ram,0x0c0a6ae4u,4);
goto P_0c0a6aa8;
P_0c0a6aa8: /* original 420b, guest PC 0x0c0a6aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a6aa8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a6aacu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6aacu) { target=s->pc; goto dispatch; }
goto P_0c0a6aac;
P_0c0a6aaa: /* original e401, guest PC 0x0c0a6aaa */
if(!s->budget--) { s->failed_pc=0x0c0a6aaau; return 0; }
r[4]=0x00000001u;
goto P_0c0a6aac;
P_0c0a6aac: /* original e00c, guest PC 0x0c0a6aac */
if(!s->budget--) { s->failed_pc=0x0c0a6aacu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6aae;
P_0c0a6aae: /* original 53f2, guest PC 0x0c0a6aae */
if(!s->budget--) { s->failed_pc=0x0c0a6aaeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a6ab0;
P_0c0a6ab0: /* original f3f6, guest PC 0x0c0a6ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a6ab0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6ab2;
P_0c0a6ab2: /* original e010, guest PC 0x0c0a6ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a6ab2u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6ab4;
P_0c0a6ab4: /* original f33a, guest PC 0x0c0a6ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a6ab4u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a6ab6;
P_0c0a6ab6: /* original f3f6, guest PC 0x0c0a6ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a6ab6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6ab8;
P_0c0a6ab8: /* original e014, guest PC 0x0c0a6ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a6ab8u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6aba;
P_0c0a6aba: /* original 63f2, guest PC 0x0c0a6aba */
if(!s->budget--) { s->failed_pc=0x0c0a6abau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a6abc;
P_0c0a6abc: /* original f33a, guest PC 0x0c0a6abc */
if(!s->budget--) { s->failed_pc=0x0c0a6abcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a6abe;
P_0c0a6abe: /* original f3f6, guest PC 0x0c0a6abe */
if(!s->budget--) { s->failed_pc=0x0c0a6abeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6ac0;
P_0c0a6ac0: /* original 53f1, guest PC 0x0c0a6ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a6ac0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a6ac2;
P_0c0a6ac2: /* original 7f18, guest PC 0x0c0a6ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a6ac2u; return 0; }
r[15]+=0x00000018u;
goto P_0c0a6ac4;
P_0c0a6ac4: /* original 4f26, guest PC 0x0c0a6ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a6ac4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6ac6;
P_0c0a6ac6: /* original f33a, guest PC 0x0c0a6ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a6ac6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a6ac8;
P_0c0a6ac8: /* original 000b, guest PC 0x0c0a6ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a6ac8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a6aca: /* original 6ef6, guest PC 0x0c0a6aca */
if(!s->budget--) { s->failed_pc=0x0c0a6acau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a6accu,s,ram);
P_0c0a6af4: /* original e004, guest PC 0x0c0a6af4 */
if(!s->budget--) { s->failed_pc=0x0c0a6af4u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6af6;
P_0c0a6af6: /* original fffb, guest PC 0x0c0a6af6 */
if(!s->budget--) { s->failed_pc=0x0c0a6af6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a6af8;
P_0c0a6af8: /* original ffeb, guest PC 0x0c0a6af8 */
if(!s->budget--) { s->failed_pc=0x0c0a6af8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a6afa;
P_0c0a6afa: /* original ffdb, guest PC 0x0c0a6afa */
if(!s->budget--) { s->failed_pc=0x0c0a6afau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a6afc;
P_0c0a6afc: /* original ffcb, guest PC 0x0c0a6afc */
if(!s->budget--) { s->failed_pc=0x0c0a6afcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a6afe;
P_0c0a6afe: /* original ff46, guest PC 0x0c0a6afe */
if(!s->budget--) { s->failed_pc=0x0c0a6afeu; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0a6b00;
P_0c0a6b00: /* original e008, guest PC 0x0c0a6b00 */
if(!s->budget--) { s->failed_pc=0x0c0a6b00u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6b02;
P_0c0a6b02: /* original fb46, guest PC 0x0c0a6b02 */
if(!s->budget--) { s->failed_pc=0x0c0a6b02u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c0a6b04;
P_0c0a6b04: /* original e00c, guest PC 0x0c0a6b04 */
if(!s->budget--) { s->failed_pc=0x0c0a6b04u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6b06;
P_0c0a6b06: /* original f748, guest PC 0x0c0a6b06 */
if(!s->budget--) { s->failed_pc=0x0c0a6b06u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
goto P_0c0a6b08;
P_0c0a6b08: /* original 7fec, guest PC 0x0c0a6b08 */
if(!s->budget--) { s->failed_pc=0x0c0a6b08u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a6b0a;
P_0c0a6b0a: /* original fd46, guest PC 0x0c0a6b0a */
if(!s->budget--) { s->failed_pc=0x0c0a6b0au; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c0a6b0c;
P_0c0a6b0c: /* original f556, guest PC 0x0c0a6b0c */
if(!s->budget--) { s->failed_pc=0x0c0a6b0cu; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0a6b0e;
P_0c0a6b0e: /* original e010, guest PC 0x0c0a6b0e */
if(!s->budget--) { s->failed_pc=0x0c0a6b0eu; return 0; }
r[0]=0x00000010u;
goto P_0c0a6b10;
P_0c0a6b10: /* original fb72, guest PC 0x0c0a6b10 */
if(!s->budget--) { s->failed_pc=0x0c0a6b10u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c0a6b12;
P_0c0a6b12: /* original f656, guest PC 0x0c0a6b12 */
if(!s->budget--) { s->failed_pc=0x0c0a6b12u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0a6b14;
P_0c0a6b14: /* original e014, guest PC 0x0c0a6b14 */
if(!s->budget--) { s->failed_pc=0x0c0a6b14u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6b16;
P_0c0a6b16: /* original fd72, guest PC 0x0c0a6b16 */
if(!s->budget--) { s->failed_pc=0x0c0a6b16u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'*');
goto P_0c0a6b18;
P_0c0a6b18: /* original f456, guest PC 0x0c0a6b18 */
if(!s->budget--) { s->failed_pc=0x0c0a6b18u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0a6b1a;
P_0c0a6b1a: /* original ff72, guest PC 0x0c0a6b1a */
if(!s->budget--) { s->failed_pc=0x0c0a6b1au; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[7],r[18],'*');
goto P_0c0a6b1c;
P_0c0a6b1c: /* original f88d, guest PC 0x0c0a6b1c */
if(!s->budget--) { s->failed_pc=0x0c0a6b1cu; return 0; }
fr[8]=0;
goto P_0c0a6b1e;
P_0c0a6b1e: /* original f3bc, guest PC 0x0c0a6b1e */
if(!s->budget--) { s->failed_pc=0x0c0a6b1eu; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c0a6b20;
P_0c0a6b20: /* original f342, guest PC 0x0c0a6b20 */
if(!s->budget--) { s->failed_pc=0x0c0a6b20u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a6b22;
P_0c0a6b22: /* original f2dc, guest PC 0x0c0a6b22 */
if(!s->budget--) { s->failed_pc=0x0c0a6b22u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c0a6b24;
P_0c0a6b24: /* original f262, guest PC 0x0c0a6b24 */
if(!s->budget--) { s->failed_pc=0x0c0a6b24u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0a6b26;
P_0c0a6b26: /* original fc3c, guest PC 0x0c0a6b26 */
if(!s->budget--) { s->failed_pc=0x0c0a6b26u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c0a6b28;
P_0c0a6b28: /* original fc81, guest PC 0x0c0a6b28 */
if(!s->budget--) { s->failed_pc=0x0c0a6b28u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[8],r[18],'-');
goto P_0c0a6b2a;
P_0c0a6b2a: /* original f24d, guest PC 0x0c0a6b2a */
if(!s->budget--) { s->failed_pc=0x0c0a6b2au; return 0; }
fr[2]^=0x80000000u;
goto P_0c0a6b2c;
P_0c0a6b2c: /* original ff2a, guest PC 0x0c0a6b2c */
if(!s->budget--) { s->failed_pc=0x0c0a6b2cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0a6b2e;
P_0c0a6b2e: /* original f94c, guest PC 0x0c0a6b2e */
if(!s->budget--) { s->failed_pc=0x0c0a6b2eu; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c0a6b30;
P_0c0a6b30: /* original f9c2, guest PC 0x0c0a6b30 */
if(!s->budget--) { s->failed_pc=0x0c0a6b30u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0a6b32;
P_0c0a6b32: /* original fa5c, guest PC 0x0c0a6b32 */
if(!s->budget--) { s->failed_pc=0x0c0a6b32u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c0a6b34;
P_0c0a6b34: /* original fa22, guest PC 0x0c0a6b34 */
if(!s->budget--) { s->failed_pc=0x0c0a6b34u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'*');
goto P_0c0a6b36;
P_0c0a6b36: /* original f36c, guest PC 0x0c0a6b36 */
if(!s->budget--) { s->failed_pc=0x0c0a6b36u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a6b38;
P_0c0a6b38: /* original f382, guest PC 0x0c0a6b38 */
if(!s->budget--) { s->failed_pc=0x0c0a6b38u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0a6b3a;
P_0c0a6b3a: /* original e010, guest PC 0x0c0a6b3a */
if(!s->budget--) { s->failed_pc=0x0c0a6b3au; return 0; }
r[0]=0x00000010u;
goto P_0c0a6b3c;
P_0c0a6b3c: /* original fd52, guest PC 0x0c0a6b3c */
if(!s->budget--) { s->failed_pc=0x0c0a6b3cu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'*');
goto P_0c0a6b3e;
P_0c0a6b3e: /* original ff37, guest PC 0x0c0a6b3e */
if(!s->budget--) { s->failed_pc=0x0c0a6b3eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6b40;
P_0c0a6b40: /* original e00c, guest PC 0x0c0a6b40 */
if(!s->budget--) { s->failed_pc=0x0c0a6b40u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6b42;
P_0c0a6b42: /* original f2f8, guest PC 0x0c0a6b42 */
if(!s->budget--) { s->failed_pc=0x0c0a6b42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a6b44;
P_0c0a6b44: /* original fd81, guest PC 0x0c0a6b44 */
if(!s->budget--) { s->failed_pc=0x0c0a6b44u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[8],r[18],'-');
goto P_0c0a6b46;
P_0c0a6b46: /* original f16c, guest PC 0x0c0a6b46 */
if(!s->budget--) { s->failed_pc=0x0c0a6b46u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0a6b48;
P_0c0a6b48: /* original f122, guest PC 0x0c0a6b48 */
if(!s->budget--) { s->failed_pc=0x0c0a6b48u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0a6b4a;
P_0c0a6b4a: /* original f09c, guest PC 0x0c0a6b4a */
if(!s->budget--) { s->failed_pc=0x0c0a6b4au; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0a6b4c;
P_0c0a6b4c: /* original fe3c, guest PC 0x0c0a6b4c */
if(!s->budget--) { s->failed_pc=0x0c0a6b4cu; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0a6b4e;
P_0c0a6b4e: /* original f91c, guest PC 0x0c0a6b4e */
if(!s->budget--) { s->failed_pc=0x0c0a6b4eu; return 0; }
vf3_matrix_move(s,9,1);
goto P_0c0a6b50;
P_0c0a6b50: /* original f901, guest PC 0x0c0a6b50 */
if(!s->budget--) { s->failed_pc=0x0c0a6b50u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[0],r[18],'-');
goto P_0c0a6b52;
P_0c0a6b52: /* original f14c, guest PC 0x0c0a6b52 */
if(!s->budget--) { s->failed_pc=0x0c0a6b52u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0a6b54;
P_0c0a6b54: /* original f182, guest PC 0x0c0a6b54 */
if(!s->budget--) { s->failed_pc=0x0c0a6b54u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'*');
goto P_0c0a6b56;
P_0c0a6b56: /* original ff17, guest PC 0x0c0a6b56 */
if(!s->budget--) { s->failed_pc=0x0c0a6b56u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a6b58;
P_0c0a6b58: /* original e04c, guest PC 0x0c0a6b58 */
if(!s->budget--) { s->failed_pc=0x0c0a6b58u; return 0; }
r[0]=0x0000004cu;
goto P_0c0a6b5a;
P_0c0a6b5a: /* original f05c, guest PC 0x0c0a6b5a */
if(!s->budget--) { s->failed_pc=0x0c0a6b5au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0a6b5c;
P_0c0a6b5c: /* original f0c2, guest PC 0x0c0a6b5c */
if(!s->budget--) { s->failed_pc=0x0c0a6b5cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[12],r[18],'*');
goto P_0c0a6b5e;
P_0c0a6b5e: /* original f3ac, guest PC 0x0c0a6b5e */
if(!s->budget--) { s->failed_pc=0x0c0a6b5eu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c0a6b60;
P_0c0a6b60: /* original fa1c, guest PC 0x0c0a6b60 */
if(!s->budget--) { s->failed_pc=0x0c0a6b60u; return 0; }
vf3_matrix_move(s,10,1);
goto P_0c0a6b62;
P_0c0a6b62: /* original fa31, guest PC 0x0c0a6b62 */
if(!s->budget--) { s->failed_pc=0x0c0a6b62u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c0a6b64;
P_0c0a6b64: /* original f3ec, guest PC 0x0c0a6b64 */
if(!s->budget--) { s->failed_pc=0x0c0a6b64u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0a6b66;
P_0c0a6b66: /* original fe0c, guest PC 0x0c0a6b66 */
if(!s->budget--) { s->failed_pc=0x0c0a6b66u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0a6b68;
P_0c0a6b68: /* original fe31, guest PC 0x0c0a6b68 */
if(!s->budget--) { s->failed_pc=0x0c0a6b68u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0a6b6a;
P_0c0a6b6a: /* original f5a7, guest PC 0x0c0a6b6a */
if(!s->budget--) { s->failed_pc=0x0c0a6b6au; return 0; }
vf3_matrix_store(s,ram,10,r[5]+r[0]);
goto P_0c0a6b6c;
P_0c0a6b6c: /* original e050, guest PC 0x0c0a6b6c */
if(!s->budget--) { s->failed_pc=0x0c0a6b6cu; return 0; }
r[0]=0x00000050u;
goto P_0c0a6b6e;
P_0c0a6b6e: /* original f5e7, guest PC 0x0c0a6b6e */
if(!s->budget--) { s->failed_pc=0x0c0a6b6eu; return 0; }
vf3_matrix_store(s,ram,14,r[5]+r[0]);
goto P_0c0a6b70;
P_0c0a6b70: /* original fcfc, guest PC 0x0c0a6b70 */
if(!s->budget--) { s->failed_pc=0x0c0a6b70u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0a6b72;
P_0c0a6b72: /* original fc42, guest PC 0x0c0a6b72 */
if(!s->budget--) { s->failed_pc=0x0c0a6b72u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c0a6b74;
P_0c0a6b74: /* original e004, guest PC 0x0c0a6b74 */
if(!s->budget--) { s->failed_pc=0x0c0a6b74u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6b76;
P_0c0a6b76: /* original ff62, guest PC 0x0c0a6b76 */
if(!s->budget--) { s->failed_pc=0x0c0a6b76u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c0a6b78;
P_0c0a6b78: /* original ffd7, guest PC 0x0c0a6b78 */
if(!s->budget--) { s->failed_pc=0x0c0a6b78u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0a6b7a;
P_0c0a6b7a: /* original e00c, guest PC 0x0c0a6b7a */
if(!s->budget--) { s->failed_pc=0x0c0a6b7au; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6b7c;
P_0c0a6b7c: /* original f26c, guest PC 0x0c0a6b7c */
if(!s->budget--) { s->failed_pc=0x0c0a6b7cu; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0a6b7e;
P_0c0a6b7e: /* original f3dc, guest PC 0x0c0a6b7e */
if(!s->budget--) { s->failed_pc=0x0c0a6b7eu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0a6b80;
P_0c0a6b80: /* original f232, guest PC 0x0c0a6b80 */
if(!s->budget--) { s->failed_pc=0x0c0a6b80u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a6b82;
P_0c0a6b82: /* original fef6, guest PC 0x0c0a6b82 */
if(!s->budget--) { s->failed_pc=0x0c0a6b82u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0a6b84;
P_0c0a6b84: /* original e008, guest PC 0x0c0a6b84 */
if(!s->budget--) { s->failed_pc=0x0c0a6b84u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6b86;
P_0c0a6b86: /* original fa5c, guest PC 0x0c0a6b86 */
if(!s->budget--) { s->failed_pc=0x0c0a6b86u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c0a6b88;
P_0c0a6b88: /* original fa32, guest PC 0x0c0a6b88 */
if(!s->budget--) { s->failed_pc=0x0c0a6b88u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'*');
goto P_0c0a6b8a;
P_0c0a6b8a: /* original f3ec, guest PC 0x0c0a6b8a */
if(!s->budget--) { s->failed_pc=0x0c0a6b8au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0a6b8c;
P_0c0a6b8c: /* original fe2c, guest PC 0x0c0a6b8c */
if(!s->budget--) { s->failed_pc=0x0c0a6b8cu; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c0a6b8e;
P_0c0a6b8e: /* original fe31, guest PC 0x0c0a6b8e */
if(!s->budget--) { s->failed_pc=0x0c0a6b8eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0a6b90;
P_0c0a6b90: /* original f24c, guest PC 0x0c0a6b90 */
if(!s->budget--) { s->failed_pc=0x0c0a6b90u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0a6b92;
P_0c0a6b92: /* original f2c2, guest PC 0x0c0a6b92 */
if(!s->budget--) { s->failed_pc=0x0c0a6b92u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'*');
goto P_0c0a6b94;
P_0c0a6b94: /* original f3ac, guest PC 0x0c0a6b94 */
if(!s->budget--) { s->failed_pc=0x0c0a6b94u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c0a6b96;
P_0c0a6b96: /* original fd6c, guest PC 0x0c0a6b96 */
if(!s->budget--) { s->failed_pc=0x0c0a6b96u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c0a6b98;
P_0c0a6b98: /* original fdc2, guest PC 0x0c0a6b98 */
if(!s->budget--) { s->failed_pc=0x0c0a6b98u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[12],r[18],'*');
goto P_0c0a6b9a;
P_0c0a6b9a: /* original fa2c, guest PC 0x0c0a6b9a */
if(!s->budget--) { s->failed_pc=0x0c0a6b9au; return 0; }
vf3_matrix_move(s,10,2);
goto P_0c0a6b9c;
P_0c0a6b9c: /* original fa31, guest PC 0x0c0a6b9c */
if(!s->budget--) { s->failed_pc=0x0c0a6b9cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c0a6b9e;
P_0c0a6b9e: /* original f25c, guest PC 0x0c0a6b9e */
if(!s->budget--) { s->failed_pc=0x0c0a6b9eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a6ba0;
P_0c0a6ba0: /* original f282, guest PC 0x0c0a6ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a6ba0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c0a6ba2;
P_0c0a6ba2: /* original ff27, guest PC 0x0c0a6ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a6ba2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6ba4;
P_0c0a6ba4: /* original e054, guest PC 0x0c0a6ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a6ba4u; return 0; }
r[0]=0x00000054u;
goto P_0c0a6ba6;
P_0c0a6ba6: /* original f3dc, guest PC 0x0c0a6ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a6ba6u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0a6ba8;
P_0c0a6ba8: /* original fd2c, guest PC 0x0c0a6ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a6ba8u; return 0; }
vf3_matrix_move(s,13,2);
goto P_0c0a6baa;
P_0c0a6baa: /* original fd31, guest PC 0x0c0a6baa */
if(!s->budget--) { s->failed_pc=0x0c0a6baau; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'-');
goto P_0c0a6bac;
P_0c0a6bac: /* original f5e7, guest PC 0x0c0a6bac */
if(!s->budget--) { s->failed_pc=0x0c0a6bacu; return 0; }
vf3_matrix_store(s,ram,14,r[5]+r[0]);
goto P_0c0a6bae;
P_0c0a6bae: /* original e05c, guest PC 0x0c0a6bae */
if(!s->budget--) { s->failed_pc=0x0c0a6baeu; return 0; }
r[0]=0x0000005cu;
goto P_0c0a6bb0;
P_0c0a6bb0: /* original f5d7, guest PC 0x0c0a6bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a6bb0u; return 0; }
vf3_matrix_store(s,ram,13,r[5]+r[0]);
goto P_0c0a6bb2;
P_0c0a6bb2: /* original fefc, guest PC 0x0c0a6bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a6bb2u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c0a6bb4;
P_0c0a6bb4: /* original ffbc, guest PC 0x0c0a6bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a6bb4u; return 0; }
vf3_matrix_move(s,15,11);
goto P_0c0a6bb6;
P_0c0a6bb6: /* original ff52, guest PC 0x0c0a6bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a6bb6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c0a6bb8;
P_0c0a6bb8: /* original fe81, guest PC 0x0c0a6bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a6bb8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[8],r[18],'-');
goto P_0c0a6bba;
P_0c0a6bba: /* original f84c, guest PC 0x0c0a6bba */
if(!s->budget--) { s->failed_pc=0x0c0a6bbau; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c0a6bbc;
P_0c0a6bbc: /* original e008, guest PC 0x0c0a6bbc */
if(!s->budget--) { s->failed_pc=0x0c0a6bbcu; return 0; }
r[0]=0x00000008u;
goto P_0c0a6bbe;
P_0c0a6bbe: /* original fbf6, guest PC 0x0c0a6bbe */
if(!s->budget--) { s->failed_pc=0x0c0a6bbeu; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c0a6bc0;
P_0c0a6bc0: /* original e010, guest PC 0x0c0a6bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a6bc0u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6bc2;
P_0c0a6bc2: /* original f8f2, guest PC 0x0c0a6bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a6bc2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c0a6bc4;
P_0c0a6bc4: /* original f4e2, guest PC 0x0c0a6bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a6bc4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'*');
goto P_0c0a6bc6;
P_0c0a6bc6: /* original f6e2, guest PC 0x0c0a6bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a6bc6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'*');
goto P_0c0a6bc8;
P_0c0a6bc8: /* original f5f2, guest PC 0x0c0a6bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a6bc8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c0a6bca;
P_0c0a6bca: /* original f38c, guest PC 0x0c0a6bca */
if(!s->budget--) { s->failed_pc=0x0c0a6bcau; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0a6bcc;
P_0c0a6bcc: /* original f8f6, guest PC 0x0c0a6bcc */
if(!s->budget--) { s->failed_pc=0x0c0a6bccu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0a6bce;
P_0c0a6bce: /* original e060, guest PC 0x0c0a6bce */
if(!s->budget--) { s->failed_pc=0x0c0a6bceu; return 0; }
r[0]=0x00000060u;
goto P_0c0a6bd0;
P_0c0a6bd0: /* original f831, guest PC 0x0c0a6bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a6bd0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a6bd2;
P_0c0a6bd2: /* original f3bc, guest PC 0x0c0a6bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a6bd2u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c0a6bd4;
P_0c0a6bd4: /* original fb4c, guest PC 0x0c0a6bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a6bd4u; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c0a6bd6;
P_0c0a6bd6: /* original fb31, guest PC 0x0c0a6bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a6bd6u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'-');
goto P_0c0a6bd8;
P_0c0a6bd8: /* original f36c, guest PC 0x0c0a6bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a6bd8u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a6bda;
P_0c0a6bda: /* original f65c, guest PC 0x0c0a6bda */
if(!s->budget--) { s->failed_pc=0x0c0a6bdau; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0a6bdc;
P_0c0a6bdc: /* original f631, guest PC 0x0c0a6bdc */
if(!s->budget--) { s->failed_pc=0x0c0a6bdcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a6bde;
P_0c0a6bde: /* original f587, guest PC 0x0c0a6bde */
if(!s->budget--) { s->failed_pc=0x0c0a6bdeu; return 0; }
vf3_matrix_store(s,ram,8,r[5]+r[0]);
goto P_0c0a6be0;
P_0c0a6be0: /* original e064, guest PC 0x0c0a6be0 */
if(!s->budget--) { s->failed_pc=0x0c0a6be0u; return 0; }
r[0]=0x00000064u;
goto P_0c0a6be2;
P_0c0a6be2: /* original f5b7, guest PC 0x0c0a6be2 */
if(!s->budget--) { s->failed_pc=0x0c0a6be2u; return 0; }
vf3_matrix_store(s,ram,11,r[5]+r[0]);
goto P_0c0a6be4;
P_0c0a6be4: /* original f39c, guest PC 0x0c0a6be4 */
if(!s->budget--) { s->failed_pc=0x0c0a6be4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0a6be6;
P_0c0a6be6: /* original f97c, guest PC 0x0c0a6be6 */
if(!s->budget--) { s->failed_pc=0x0c0a6be6u; return 0; }
vf3_matrix_move(s,9,7);
goto P_0c0a6be8;
P_0c0a6be8: /* original f930, guest PC 0x0c0a6be8 */
if(!s->budget--) { s->failed_pc=0x0c0a6be8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'+');
goto P_0c0a6bea;
P_0c0a6bea: /* original f3ac, guest PC 0x0c0a6bea */
if(!s->budget--) { s->failed_pc=0x0c0a6beau; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c0a6bec;
P_0c0a6bec: /* original fa7c, guest PC 0x0c0a6bec */
if(!s->budget--) { s->failed_pc=0x0c0a6becu; return 0; }
vf3_matrix_move(s,10,7);
goto P_0c0a6bee;
P_0c0a6bee: /* original fa30, guest PC 0x0c0a6bee */
if(!s->budget--) { s->failed_pc=0x0c0a6beeu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c0a6bf0;
P_0c0a6bf0: /* original f36c, guest PC 0x0c0a6bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a6bf0u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a6bf2;
P_0c0a6bf2: /* original f67c, guest PC 0x0c0a6bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a6bf2u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0a6bf4;
P_0c0a6bf4: /* original 7f14, guest PC 0x0c0a6bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a6bf4u; return 0; }
r[15]+=0x00000014u;
goto P_0c0a6bf6;
P_0c0a6bf6: /* original f630, guest PC 0x0c0a6bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a6bf6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0a6bf8;
P_0c0a6bf8: /* original e048, guest PC 0x0c0a6bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a6bf8u; return 0; }
r[0]=0x00000048u;
goto P_0c0a6bfa;
P_0c0a6bfa: /* original f597, guest PC 0x0c0a6bfa */
if(!s->budget--) { s->failed_pc=0x0c0a6bfau; return 0; }
vf3_matrix_store(s,ram,9,r[5]+r[0]);
goto P_0c0a6bfc;
P_0c0a6bfc: /* original e058, guest PC 0x0c0a6bfc */
if(!s->budget--) { s->failed_pc=0x0c0a6bfcu; return 0; }
r[0]=0x00000058u;
goto P_0c0a6bfe;
P_0c0a6bfe: /* original f5a7, guest PC 0x0c0a6bfe */
if(!s->budget--) { s->failed_pc=0x0c0a6bfeu; return 0; }
vf3_matrix_store(s,ram,10,r[5]+r[0]);
goto P_0c0a6c00;
P_0c0a6c00: /* original e068, guest PC 0x0c0a6c00 */
if(!s->budget--) { s->failed_pc=0x0c0a6c00u; return 0; }
r[0]=0x00000068u;
goto P_0c0a6c02;
P_0c0a6c02: /* original f567, guest PC 0x0c0a6c02 */
if(!s->budget--) { s->failed_pc=0x0c0a6c02u; return 0; }
vf3_matrix_store(s,ram,6,r[5]+r[0]);
goto P_0c0a6c04;
P_0c0a6c04: /* original fcf9, guest PC 0x0c0a6c04 */
if(!s->budget--) { s->failed_pc=0x0c0a6c04u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6c06;
P_0c0a6c06: /* original fdf9, guest PC 0x0c0a6c06 */
if(!s->budget--) { s->failed_pc=0x0c0a6c06u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6c08;
P_0c0a6c08: /* original fef9, guest PC 0x0c0a6c08 */
if(!s->budget--) { s->failed_pc=0x0c0a6c08u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6c0a;
P_0c0a6c0a: /* original 000b, guest PC 0x0c0a6c0a */
if(!s->budget--) { s->failed_pc=0x0c0a6c0au; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c0a6c0c: /* original fff9, guest PC 0x0c0a6c0c */
if(!s->budget--) { s->failed_pc=0x0c0a6c0cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6c0e;
P_0c0a6c0e: /* original e004, guest PC 0x0c0a6c0e */
if(!s->budget--) { s->failed_pc=0x0c0a6c0eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6c10;
P_0c0a6c10: /* original fffb, guest PC 0x0c0a6c10 */
if(!s->budget--) { s->failed_pc=0x0c0a6c10u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a6c12;
P_0c0a6c12: /* original ffeb, guest PC 0x0c0a6c12 */
if(!s->budget--) { s->failed_pc=0x0c0a6c12u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a6c14;
P_0c0a6c14: /* original ffdb, guest PC 0x0c0a6c14 */
if(!s->budget--) { s->failed_pc=0x0c0a6c14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a6c16;
P_0c0a6c16: /* original ffcb, guest PC 0x0c0a6c16 */
if(!s->budget--) { s->failed_pc=0x0c0a6c16u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a6c18;
P_0c0a6c18: /* original f856, guest PC 0x0c0a6c18 */
if(!s->budget--) { s->failed_pc=0x0c0a6c18u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0a6c1a;
P_0c0a6c1a: /* original e008, guest PC 0x0c0a6c1a */
if(!s->budget--) { s->failed_pc=0x0c0a6c1au; return 0; }
r[0]=0x00000008u;
goto P_0c0a6c1c;
P_0c0a6c1c: /* original f356, guest PC 0x0c0a6c1c */
if(!s->budget--) { s->failed_pc=0x0c0a6c1cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a6c1e;
P_0c0a6c1e: /* original e020, guest PC 0x0c0a6c1e */
if(!s->budget--) { s->failed_pc=0x0c0a6c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a6c20;
P_0c0a6c20: /* original 7fc8, guest PC 0x0c0a6c20 */
if(!s->budget--) { s->failed_pc=0x0c0a6c20u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0a6c22;
P_0c0a6c22: /* original fa58, guest PC 0x0c0a6c22 */
if(!s->budget--) { s->failed_pc=0x0c0a6c22u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0a6c24;
P_0c0a6c24: /* original ff37, guest PC 0x0c0a6c24 */
if(!s->budget--) { s->failed_pc=0x0c0a6c24u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6c26;
P_0c0a6c26: /* original e004, guest PC 0x0c0a6c26 */
if(!s->budget--) { s->failed_pc=0x0c0a6c26u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6c28;
P_0c0a6c28: /* original f466, guest PC 0x0c0a6c28 */
if(!s->budget--) { s->failed_pc=0x0c0a6c28u; return 0; }
vf3_matrix_load(s,ram,4,r[6]+r[0]);
goto P_0c0a6c2a;
P_0c0a6c2a: /* original e008, guest PC 0x0c0a6c2a */
if(!s->budget--) { s->failed_pc=0x0c0a6c2au; return 0; }
r[0]=0x00000008u;
goto P_0c0a6c2c;
P_0c0a6c2c: /* original f966, guest PC 0x0c0a6c2c */
if(!s->budget--) { s->failed_pc=0x0c0a6c2cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c0a6c2e;
P_0c0a6c2e: /* original e048, guest PC 0x0c0a6c2e */
if(!s->budget--) { s->failed_pc=0x0c0a6c2eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a6c30;
P_0c0a6c30: /* original f346, guest PC 0x0c0a6c30 */
if(!s->budget--) { s->failed_pc=0x0c0a6c30u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a6c32;
P_0c0a6c32: /* original e004, guest PC 0x0c0a6c32 */
if(!s->budget--) { s->failed_pc=0x0c0a6c32u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6c34;
P_0c0a6c34: /* original f568, guest PC 0x0c0a6c34 */
if(!s->budget--) { s->failed_pc=0x0c0a6c34u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0a6c36;
P_0c0a6c36: /* original ff37, guest PC 0x0c0a6c36 */
if(!s->budget--) { s->failed_pc=0x0c0a6c36u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6c38;
P_0c0a6c38: /* original e04c, guest PC 0x0c0a6c38 */
if(!s->budget--) { s->failed_pc=0x0c0a6c38u; return 0; }
r[0]=0x0000004cu;
goto P_0c0a6c3a;
P_0c0a6c3a: /* original fb46, guest PC 0x0c0a6c3a */
if(!s->budget--) { s->failed_pc=0x0c0a6c3au; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c0a6c3c;
P_0c0a6c3c: /* original e050, guest PC 0x0c0a6c3c */
if(!s->budget--) { s->failed_pc=0x0c0a6c3cu; return 0; }
r[0]=0x00000050u;
goto P_0c0a6c3e;
P_0c0a6c3e: /* original f346, guest PC 0x0c0a6c3e */
if(!s->budget--) { s->failed_pc=0x0c0a6c3eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a6c40;
P_0c0a6c40: /* original e01c, guest PC 0x0c0a6c40 */
if(!s->budget--) { s->failed_pc=0x0c0a6c40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6c42;
P_0c0a6c42: /* original ff37, guest PC 0x0c0a6c42 */
if(!s->budget--) { s->failed_pc=0x0c0a6c42u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6c44;
P_0c0a6c44: /* original e054, guest PC 0x0c0a6c44 */
if(!s->budget--) { s->failed_pc=0x0c0a6c44u; return 0; }
r[0]=0x00000054u;
goto P_0c0a6c46;
P_0c0a6c46: /* original f346, guest PC 0x0c0a6c46 */
if(!s->budget--) { s->failed_pc=0x0c0a6c46u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a6c48;
P_0c0a6c48: /* original e058, guest PC 0x0c0a6c48 */
if(!s->budget--) { s->failed_pc=0x0c0a6c48u; return 0; }
r[0]=0x00000058u;
goto P_0c0a6c4a;
P_0c0a6c4a: /* original ff3a, guest PC 0x0c0a6c4a */
if(!s->budget--) { s->failed_pc=0x0c0a6c4au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a6c4c;
P_0c0a6c4c: /* original fc46, guest PC 0x0c0a6c4c */
if(!s->budget--) { s->failed_pc=0x0c0a6c4cu; return 0; }
vf3_matrix_load(s,ram,12,r[4]+r[0]);
goto P_0c0a6c4e;
P_0c0a6c4e: /* original e05c, guest PC 0x0c0a6c4e */
if(!s->budget--) { s->failed_pc=0x0c0a6c4eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0a6c50;
P_0c0a6c50: /* original f39c, guest PC 0x0c0a6c50 */
if(!s->budget--) { s->failed_pc=0x0c0a6c50u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0a6c52;
P_0c0a6c52: /* original f746, guest PC 0x0c0a6c52 */
if(!s->budget--) { s->failed_pc=0x0c0a6c52u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0a6c54;
P_0c0a6c54: /* original e060, guest PC 0x0c0a6c54 */
if(!s->budget--) { s->failed_pc=0x0c0a6c54u; return 0; }
r[0]=0x00000060u;
goto P_0c0a6c56;
P_0c0a6c56: /* original fd46, guest PC 0x0c0a6c56 */
if(!s->budget--) { s->failed_pc=0x0c0a6c56u; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c0a6c58;
P_0c0a6c58: /* original e064, guest PC 0x0c0a6c58 */
if(!s->budget--) { s->failed_pc=0x0c0a6c58u; return 0; }
r[0]=0x00000064u;
goto P_0c0a6c5a;
P_0c0a6c5a: /* original ff46, guest PC 0x0c0a6c5a */
if(!s->budget--) { s->failed_pc=0x0c0a6c5au; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0a6c5c;
P_0c0a6c5c: /* original e068, guest PC 0x0c0a6c5c */
if(!s->budget--) { s->failed_pc=0x0c0a6c5cu; return 0; }
r[0]=0x00000068u;
goto P_0c0a6c5e;
P_0c0a6c5e: /* original fe46, guest PC 0x0c0a6c5e */
if(!s->budget--) { s->failed_pc=0x0c0a6c5eu; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0a6c60;
P_0c0a6c60: /* original e020, guest PC 0x0c0a6c60 */
if(!s->budget--) { s->failed_pc=0x0c0a6c60u; return 0; }
r[0]=0x00000020u;
goto P_0c0a6c62;
P_0c0a6c62: /* original f9f6, guest PC 0x0c0a6c62 */
if(!s->budget--) { s->failed_pc=0x0c0a6c62u; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0a6c64;
P_0c0a6c64: /* original f841, guest PC 0x0c0a6c64 */
if(!s->budget--) { s->failed_pc=0x0c0a6c64u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0a6c66;
P_0c0a6c66: /* original e024, guest PC 0x0c0a6c66 */
if(!s->budget--) { s->failed_pc=0x0c0a6c66u; return 0; }
r[0]=0x00000024u;
goto P_0c0a6c68;
P_0c0a6c68: /* original fa51, guest PC 0x0c0a6c68 */
if(!s->budget--) { s->failed_pc=0x0c0a6c68u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'-');
goto P_0c0a6c6a;
P_0c0a6c6a: /* original f931, guest PC 0x0c0a6c6a */
if(!s->budget--) { s->failed_pc=0x0c0a6c6au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0a6c6c;
P_0c0a6c6c: /* original f37c, guest PC 0x0c0a6c6c */
if(!s->budget--) { s->failed_pc=0x0c0a6c6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0a6c6e;
P_0c0a6c6e: /* original f3f2, guest PC 0x0c0a6c6e */
if(!s->budget--) { s->failed_pc=0x0c0a6c6eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0a6c70;
P_0c0a6c70: /* original ff37, guest PC 0x0c0a6c70 */
if(!s->budget--) { s->failed_pc=0x0c0a6c70u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6c72;
P_0c0a6c72: /* original e028, guest PC 0x0c0a6c72 */
if(!s->budget--) { s->failed_pc=0x0c0a6c72u; return 0; }
r[0]=0x00000028u;
goto P_0c0a6c74;
P_0c0a6c74: /* original f2bc, guest PC 0x0c0a6c74 */
if(!s->budget--) { s->failed_pc=0x0c0a6c74u; return 0; }
vf3_matrix_move(s,2,11);
goto P_0c0a6c76;
P_0c0a6c76: /* original f2e2, guest PC 0x0c0a6c76 */
if(!s->budget--) { s->failed_pc=0x0c0a6c76u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0a6c78;
P_0c0a6c78: /* original f43c, guest PC 0x0c0a6c78 */
if(!s->budget--) { s->failed_pc=0x0c0a6c78u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a6c7a;
P_0c0a6c7a: /* original ff27, guest PC 0x0c0a6c7a */
if(!s->budget--) { s->failed_pc=0x0c0a6c7au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6c7c;
P_0c0a6c7c: /* original e00c, guest PC 0x0c0a6c7c */
if(!s->budget--) { s->failed_pc=0x0c0a6c7cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6c7e;
P_0c0a6c7e: /* original f1bc, guest PC 0x0c0a6c7e */
if(!s->budget--) { s->failed_pc=0x0c0a6c7eu; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c0a6c80;
P_0c0a6c80: /* original f1c2, guest PC 0x0c0a6c80 */
if(!s->budget--) { s->failed_pc=0x0c0a6c80u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[12],r[18],'*');
goto P_0c0a6c82;
P_0c0a6c82: /* original f52c, guest PC 0x0c0a6c82 */
if(!s->budget--) { s->failed_pc=0x0c0a6c82u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0a6c84;
P_0c0a6c84: /* original ff17, guest PC 0x0c0a6c84 */
if(!s->budget--) { s->failed_pc=0x0c0a6c84u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a6c86;
P_0c0a6c86: /* original e02c, guest PC 0x0c0a6c86 */
if(!s->budget--) { s->failed_pc=0x0c0a6c86u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a6c88;
P_0c0a6c88: /* original f3cc, guest PC 0x0c0a6c88 */
if(!s->budget--) { s->failed_pc=0x0c0a6c88u; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0a6c8a;
P_0c0a6c8a: /* original f3e2, guest PC 0x0c0a6c8a */
if(!s->budget--) { s->failed_pc=0x0c0a6c8au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0a6c8c;
P_0c0a6c8c: /* original f61c, guest PC 0x0c0a6c8c */
if(!s->budget--) { s->failed_pc=0x0c0a6c8cu; return 0; }
vf3_matrix_move(s,6,1);
goto P_0c0a6c8e;
P_0c0a6c8e: /* original ff37, guest PC 0x0c0a6c8e */
if(!s->budget--) { s->failed_pc=0x0c0a6c8eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6c90;
P_0c0a6c90: /* original e01c, guest PC 0x0c0a6c90 */
if(!s->budget--) { s->failed_pc=0x0c0a6c90u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6c92;
P_0c0a6c92: /* original f0f6, guest PC 0x0c0a6c92 */
if(!s->budget--) { s->failed_pc=0x0c0a6c92u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0a6c94;
P_0c0a6c94: /* original e034, guest PC 0x0c0a6c94 */
if(!s->budget--) { s->failed_pc=0x0c0a6c94u; return 0; }
r[0]=0x00000034u;
goto P_0c0a6c96;
P_0c0a6c96: /* original f24c, guest PC 0x0c0a6c96 */
if(!s->budget--) { s->failed_pc=0x0c0a6c96u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0a6c98;
P_0c0a6c98: /* original f0f2, guest PC 0x0c0a6c98 */
if(!s->budget--) { s->failed_pc=0x0c0a6c98u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c0a6c9a;
P_0c0a6c9a: /* original f43c, guest PC 0x0c0a6c9a */
if(!s->budget--) { s->failed_pc=0x0c0a6c9au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a6c9c;
P_0c0a6c9c: /* original f421, guest PC 0x0c0a6c9c */
if(!s->budget--) { s->failed_pc=0x0c0a6c9cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0a6c9e;
P_0c0a6c9e: /* original ff07, guest PC 0x0c0a6c9e */
if(!s->budget--) { s->failed_pc=0x0c0a6c9eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0a6ca0;
P_0c0a6ca0: /* original e030, guest PC 0x0c0a6ca0 */
if(!s->budget--) { s->failed_pc=0x0c0a6ca0u; return 0; }
r[0]=0x00000030u;
goto P_0c0a6ca2;
P_0c0a6ca2: /* original f1bc, guest PC 0x0c0a6ca2 */
if(!s->budget--) { s->failed_pc=0x0c0a6ca2u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c0a6ca4;
P_0c0a6ca4: /* original f172, guest PC 0x0c0a6ca4 */
if(!s->budget--) { s->failed_pc=0x0c0a6ca4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'*');
goto P_0c0a6ca6;
P_0c0a6ca6: /* original f25c, guest PC 0x0c0a6ca6 */
if(!s->budget--) { s->failed_pc=0x0c0a6ca6u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a6ca8;
P_0c0a6ca8: /* original f50c, guest PC 0x0c0a6ca8 */
if(!s->budget--) { s->failed_pc=0x0c0a6ca8u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0a6caa;
P_0c0a6caa: /* original f521, guest PC 0x0c0a6caa */
if(!s->budget--) { s->failed_pc=0x0c0a6caau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0a6cac;
P_0c0a6cac: /* original ff17, guest PC 0x0c0a6cac */
if(!s->budget--) { s->failed_pc=0x0c0a6cacu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a6cae;
P_0c0a6cae: /* original e004, guest PC 0x0c0a6cae */
if(!s->budget--) { s->failed_pc=0x0c0a6caeu; return 0; }
r[0]=0x00000004u;
goto P_0c0a6cb0;
P_0c0a6cb0: /* original f36c, guest PC 0x0c0a6cb0 */
if(!s->budget--) { s->failed_pc=0x0c0a6cb0u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0a6cb2;
P_0c0a6cb2: /* original f61c, guest PC 0x0c0a6cb2 */
if(!s->budget--) { s->failed_pc=0x0c0a6cb2u; return 0; }
vf3_matrix_move(s,6,1);
goto P_0c0a6cb4;
P_0c0a6cb4: /* original f631, guest PC 0x0c0a6cb4 */
if(!s->budget--) { s->failed_pc=0x0c0a6cb4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a6cb6;
P_0c0a6cb6: /* original f3f6, guest PC 0x0c0a6cb6 */
if(!s->budget--) { s->failed_pc=0x0c0a6cb6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6cb8;
P_0c0a6cb8: /* original e024, guest PC 0x0c0a6cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a6cb8u; return 0; }
r[0]=0x00000024u;
goto P_0c0a6cba;
P_0c0a6cba: /* original f0f8, guest PC 0x0c0a6cba */
if(!s->budget--) { s->failed_pc=0x0c0a6cbau; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0a6cbc;
P_0c0a6cbc: /* original f432, guest PC 0x0c0a6cbc */
if(!s->budget--) { s->failed_pc=0x0c0a6cbcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0a6cbe;
P_0c0a6cbe: /* original f24c, guest PC 0x0c0a6cbe */
if(!s->budget--) { s->failed_pc=0x0c0a6cbeu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0a6cc0;
P_0c0a6cc0: /* original f25e, guest PC 0x0c0a6cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a6cc0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c0a6cc2;
P_0c0a6cc2: /* original f0dc, guest PC 0x0c0a6cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a6cc2u; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0a6cc4;
P_0c0a6cc4: /* original f5f6, guest PC 0x0c0a6cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a6cc4u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a6cc6;
P_0c0a6cc6: /* original f26e, guest PC 0x0c0a6cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a6cc6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0a6cc8;
P_0c0a6cc8: /* original f42c, guest PC 0x0c0a6cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a6cc8u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a6cca;
P_0c0a6cca: /* original f49d, guest PC 0x0c0a6cca */
if(!s->budget--) { s->failed_pc=0x0c0a6ccau; return 0; }
fr[4]=0x3f800000u;
goto P_0c0a6ccc;
P_0c0a6ccc: /* original f423, guest PC 0x0c0a6ccc */
if(!s->budget--) { s->failed_pc=0x0c0a6cccu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a6cce;
P_0c0a6cce: /* original e028, guest PC 0x0c0a6cce */
if(!s->budget--) { s->failed_pc=0x0c0a6cceu; return 0; }
r[0]=0x00000028u;
goto P_0c0a6cd0;
P_0c0a6cd0: /* original f6f6, guest PC 0x0c0a6cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a6cd0u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a6cd2;
P_0c0a6cd2: /* original e00c, guest PC 0x0c0a6cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a6cd2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6cd4;
P_0c0a6cd4: /* original f2f6, guest PC 0x0c0a6cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a6cd4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6cd6;
P_0c0a6cd6: /* original e010, guest PC 0x0c0a6cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a6cd6u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6cd8;
P_0c0a6cd8: /* original ff27, guest PC 0x0c0a6cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a6cd8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6cda;
P_0c0a6cda: /* original e02c, guest PC 0x0c0a6cda */
if(!s->budget--) { s->failed_pc=0x0c0a6cdau; return 0; }
r[0]=0x0000002cu;
goto P_0c0a6cdc;
P_0c0a6cdc: /* original f25c, guest PC 0x0c0a6cdc */
if(!s->budget--) { s->failed_pc=0x0c0a6cdcu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a6cde;
P_0c0a6cde: /* original f5f6, guest PC 0x0c0a6cde */
if(!s->budget--) { s->failed_pc=0x0c0a6cdeu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a6ce0;
P_0c0a6ce0: /* original e034, guest PC 0x0c0a6ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a6ce0u; return 0; }
r[0]=0x00000034u;
goto P_0c0a6ce2;
P_0c0a6ce2: /* original f521, guest PC 0x0c0a6ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a6ce2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0a6ce4;
P_0c0a6ce4: /* original f26c, guest PC 0x0c0a6ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a6ce4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0a6ce6;
P_0c0a6ce6: /* original f6f6, guest PC 0x0c0a6ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a6ce6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a6ce8;
P_0c0a6ce8: /* original e010, guest PC 0x0c0a6ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a6ce8u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6cea;
P_0c0a6cea: /* original f621, guest PC 0x0c0a6cea */
if(!s->budget--) { s->failed_pc=0x0c0a6ceau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c0a6cec;
P_0c0a6cec: /* original f2f6, guest PC 0x0c0a6cec */
if(!s->budget--) { s->failed_pc=0x0c0a6cecu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6cee;
P_0c0a6cee: /* original f5a2, guest PC 0x0c0a6cee */
if(!s->budget--) { s->failed_pc=0x0c0a6ceeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c0a6cf0;
P_0c0a6cf0: /* original e010, guest PC 0x0c0a6cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a6cf0u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6cf2;
P_0c0a6cf2: /* original f121, guest PC 0x0c0a6cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a6cf2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c0a6cf4;
P_0c0a6cf4: /* original ff17, guest PC 0x0c0a6cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a6cf4u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a6cf6;
P_0c0a6cf6: /* original e010, guest PC 0x0c0a6cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a6cf6u; return 0; }
r[0]=0x00000010u;
goto P_0c0a6cf8;
P_0c0a6cf8: /* original f25c, guest PC 0x0c0a6cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a6cf8u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0a6cfa;
P_0c0a6cfa: /* original f08c, guest PC 0x0c0a6cfa */
if(!s->budget--) { s->failed_pc=0x0c0a6cfau; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c0a6cfc;
P_0c0a6cfc: /* original f26e, guest PC 0x0c0a6cfc */
if(!s->budget--) { s->failed_pc=0x0c0a6cfcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0a6cfe;
P_0c0a6cfe: /* original f09c, guest PC 0x0c0a6cfe */
if(!s->budget--) { s->failed_pc=0x0c0a6cfeu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0a6d00;
P_0c0a6d00: /* original f69c, guest PC 0x0c0a6d00 */
if(!s->budget--) { s->failed_pc=0x0c0a6d00u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c0a6d02;
P_0c0a6d02: /* original f672, guest PC 0x0c0a6d02 */
if(!s->budget--) { s->failed_pc=0x0c0a6d02u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0a6d04;
P_0c0a6d04: /* original f12c, guest PC 0x0c0a6d04 */
if(!s->budget--) { s->failed_pc=0x0c0a6d04u; return 0; }
vf3_matrix_move(s,1,2);
goto P_0c0a6d06;
P_0c0a6d06: /* original f2f6, guest PC 0x0c0a6d06 */
if(!s->budget--) { s->failed_pc=0x0c0a6d06u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6d08;
P_0c0a6d08: /* original f12e, guest PC 0x0c0a6d08 */
if(!s->budget--) { s->failed_pc=0x0c0a6d08u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[2],fr[1],r[18]);
goto P_0c0a6d0a;
P_0c0a6d0a: /* original f2ac, guest PC 0x0c0a6d0a */
if(!s->budget--) { s->failed_pc=0x0c0a6d0au; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c0a6d0c;
P_0c0a6d0c: /* original f51c, guest PC 0x0c0a6d0c */
if(!s->budget--) { s->failed_pc=0x0c0a6d0cu; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c0a6d0e;
P_0c0a6d0e: /* original f2e2, guest PC 0x0c0a6d0e */
if(!s->budget--) { s->failed_pc=0x0c0a6d0eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0a6d10;
P_0c0a6d10: /* original e018, guest PC 0x0c0a6d10 */
if(!s->budget--) { s->failed_pc=0x0c0a6d10u; return 0; }
r[0]=0x00000018u;
goto P_0c0a6d12;
P_0c0a6d12: /* original ff27, guest PC 0x0c0a6d12 */
if(!s->budget--) { s->failed_pc=0x0c0a6d12u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6d14;
P_0c0a6d14: /* original e014, guest PC 0x0c0a6d14 */
if(!s->budget--) { s->failed_pc=0x0c0a6d14u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6d16;
P_0c0a6d16: /* original f1ac, guest PC 0x0c0a6d16 */
if(!s->budget--) { s->failed_pc=0x0c0a6d16u; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c0a6d18;
P_0c0a6d18: /* original f182, guest PC 0x0c0a6d18 */
if(!s->budget--) { s->failed_pc=0x0c0a6d18u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'*');
goto P_0c0a6d1a;
P_0c0a6d1a: /* original ff17, guest PC 0x0c0a6d1a */
if(!s->budget--) { s->failed_pc=0x0c0a6d1au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0a6d1c;
P_0c0a6d1c: /* original e01c, guest PC 0x0c0a6d1c */
if(!s->budget--) { s->failed_pc=0x0c0a6d1cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6d1e;
P_0c0a6d1e: /* original f38c, guest PC 0x0c0a6d1e */
if(!s->budget--) { s->failed_pc=0x0c0a6d1eu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0a6d20;
P_0c0a6d20: /* original f3e2, guest PC 0x0c0a6d20 */
if(!s->budget--) { s->failed_pc=0x0c0a6d20u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0a6d22;
P_0c0a6d22: /* original f06c, guest PC 0x0c0a6d22 */
if(!s->budget--) { s->failed_pc=0x0c0a6d22u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0a6d24;
P_0c0a6d24: /* original f63c, guest PC 0x0c0a6d24 */
if(!s->budget--) { s->failed_pc=0x0c0a6d24u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0a6d26;
P_0c0a6d26: /* original f601, guest PC 0x0c0a6d26 */
if(!s->budget--) { s->failed_pc=0x0c0a6d26u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[0],r[18],'-');
goto P_0c0a6d28;
P_0c0a6d28: /* original f3f6, guest PC 0x0c0a6d28 */
if(!s->budget--) { s->failed_pc=0x0c0a6d28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6d2a;
P_0c0a6d2a: /* original e018, guest PC 0x0c0a6d2a */
if(!s->budget--) { s->failed_pc=0x0c0a6d2au; return 0; }
r[0]=0x00000018u;
goto P_0c0a6d2c;
P_0c0a6d2c: /* original f09c, guest PC 0x0c0a6d2c */
if(!s->budget--) { s->failed_pc=0x0c0a6d2cu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c0a6d2e;
P_0c0a6d2e: /* original f032, guest PC 0x0c0a6d2e */
if(!s->budget--) { s->failed_pc=0x0c0a6d2eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0a6d30;
P_0c0a6d30: /* original f2f6, guest PC 0x0c0a6d30 */
if(!s->budget--) { s->failed_pc=0x0c0a6d30u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6d32;
P_0c0a6d32: /* original e018, guest PC 0x0c0a6d32 */
if(!s->budget--) { s->failed_pc=0x0c0a6d32u; return 0; }
r[0]=0x00000018u;
goto P_0c0a6d34;
P_0c0a6d34: /* original f021, guest PC 0x0c0a6d34 */
if(!s->budget--) { s->failed_pc=0x0c0a6d34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'-');
goto P_0c0a6d36;
P_0c0a6d36: /* original ff07, guest PC 0x0c0a6d36 */
if(!s->budget--) { s->failed_pc=0x0c0a6d36u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0a6d38;
P_0c0a6d38: /* original e014, guest PC 0x0c0a6d38 */
if(!s->budget--) { s->failed_pc=0x0c0a6d38u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6d3a;
P_0c0a6d3a: /* original f2ac, guest PC 0x0c0a6d3a */
if(!s->budget--) { s->failed_pc=0x0c0a6d3au; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c0a6d3c;
P_0c0a6d3c: /* original f272, guest PC 0x0c0a6d3c */
if(!s->budget--) { s->failed_pc=0x0c0a6d3cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c0a6d3e;
P_0c0a6d3e: /* original f1f6, guest PC 0x0c0a6d3e */
if(!s->budget--) { s->failed_pc=0x0c0a6d3eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0a6d40;
P_0c0a6d40: /* original e014, guest PC 0x0c0a6d40 */
if(!s->budget--) { s->failed_pc=0x0c0a6d40u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6d42;
P_0c0a6d42: /* original f211, guest PC 0x0c0a6d42 */
if(!s->budget--) { s->failed_pc=0x0c0a6d42u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'-');
goto P_0c0a6d44;
P_0c0a6d44: /* original ff27, guest PC 0x0c0a6d44 */
if(!s->budget--) { s->failed_pc=0x0c0a6d44u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6d46;
P_0c0a6d46: /* original e004, guest PC 0x0c0a6d46 */
if(!s->budget--) { s->failed_pc=0x0c0a6d46u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6d48;
P_0c0a6d48: /* original f3f6, guest PC 0x0c0a6d48 */
if(!s->budget--) { s->failed_pc=0x0c0a6d48u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a6d4a;
P_0c0a6d4a: /* original f632, guest PC 0x0c0a6d4a */
if(!s->budget--) { s->failed_pc=0x0c0a6d4au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0a6d4c;
P_0c0a6d4c: /* original f16c, guest PC 0x0c0a6d4c */
if(!s->budget--) { s->failed_pc=0x0c0a6d4cu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0a6d4e;
P_0c0a6d4e: /* original e018, guest PC 0x0c0a6d4e */
if(!s->budget--) { s->failed_pc=0x0c0a6d4eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a6d50;
P_0c0a6d50: /* original f0f8, guest PC 0x0c0a6d50 */
if(!s->budget--) { s->failed_pc=0x0c0a6d50u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0a6d52;
P_0c0a6d52: /* original f2f6, guest PC 0x0c0a6d52 */
if(!s->budget--) { s->failed_pc=0x0c0a6d52u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6d54;
P_0c0a6d54: /* original e014, guest PC 0x0c0a6d54 */
if(!s->budget--) { s->failed_pc=0x0c0a6d54u; return 0; }
r[0]=0x00000014u;
goto P_0c0a6d56;
P_0c0a6d56: /* original f78c, guest PC 0x0c0a6d56 */
if(!s->budget--) { s->failed_pc=0x0c0a6d56u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c0a6d58;
P_0c0a6d58: /* original f7f2, guest PC 0x0c0a6d58 */
if(!s->budget--) { s->failed_pc=0x0c0a6d58u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c0a6d5a;
P_0c0a6d5a: /* original f12e, guest PC 0x0c0a6d5a */
if(!s->budget--) { s->failed_pc=0x0c0a6d5au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[2],fr[1],r[18]);
goto P_0c0a6d5c;
P_0c0a6d5c: /* original f0dc, guest PC 0x0c0a6d5c */
if(!s->budget--) { s->failed_pc=0x0c0a6d5cu; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0a6d5e;
P_0c0a6d5e: /* original fe9c, guest PC 0x0c0a6d5e */
if(!s->budget--) { s->failed_pc=0x0c0a6d5eu; return 0; }
vf3_matrix_move(s,14,9);
goto P_0c0a6d60;
P_0c0a6d60: /* original f9c2, guest PC 0x0c0a6d60 */
if(!s->budget--) { s->failed_pc=0x0c0a6d60u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0a6d62;
P_0c0a6d62: /* original feb2, guest PC 0x0c0a6d62 */
if(!s->budget--) { s->failed_pc=0x0c0a6d62u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'*');
goto P_0c0a6d64;
P_0c0a6d64: /* original faf2, guest PC 0x0c0a6d64 */
if(!s->budget--) { s->failed_pc=0x0c0a6d64u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c0a6d66;
P_0c0a6d66: /* original f21c, guest PC 0x0c0a6d66 */
if(!s->budget--) { s->failed_pc=0x0c0a6d66u; return 0; }
vf3_matrix_move(s,2,1);
goto P_0c0a6d68;
P_0c0a6d68: /* original f8b2, guest PC 0x0c0a6d68 */
if(!s->budget--) { s->failed_pc=0x0c0a6d68u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'*');
goto P_0c0a6d6a;
P_0c0a6d6a: /* original f1f6, guest PC 0x0c0a6d6a */
if(!s->budget--) { s->failed_pc=0x0c0a6d6au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0a6d6c;
P_0c0a6d6c: /* original e00c, guest PC 0x0c0a6d6c */
if(!s->budget--) { s->failed_pc=0x0c0a6d6cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a6d6e;
P_0c0a6d6e: /* original f21e, guest PC 0x0c0a6d6e */
if(!s->budget--) { s->failed_pc=0x0c0a6d6eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[1],fr[2],r[18]);
goto P_0c0a6d70;
P_0c0a6d70: /* original f62c, guest PC 0x0c0a6d70 */
if(!s->budget--) { s->failed_pc=0x0c0a6d70u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0a6d72;
P_0c0a6d72: /* original f2f6, guest PC 0x0c0a6d72 */
if(!s->budget--) { s->failed_pc=0x0c0a6d72u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6d74;
P_0c0a6d74: /* original e008, guest PC 0x0c0a6d74 */
if(!s->budget--) { s->failed_pc=0x0c0a6d74u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6d76;
P_0c0a6d76: /* original ff27, guest PC 0x0c0a6d76 */
if(!s->budget--) { s->failed_pc=0x0c0a6d76u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0a6d78;
P_0c0a6d78: /* original e008, guest PC 0x0c0a6d78 */
if(!s->budget--) { s->failed_pc=0x0c0a6d78u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6d7a;
P_0c0a6d7a: /* original f27c, guest PC 0x0c0a6d7a */
if(!s->budget--) { s->failed_pc=0x0c0a6d7au; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c0a6d7c;
P_0c0a6d7c: /* original f79c, guest PC 0x0c0a6d7c */
if(!s->budget--) { s->failed_pc=0x0c0a6d7cu; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c0a6d7e;
P_0c0a6d7e: /* original f721, guest PC 0x0c0a6d7e */
if(!s->budget--) { s->failed_pc=0x0c0a6d7eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'-');
goto P_0c0a6d80;
P_0c0a6d80: /* original f2ec, guest PC 0x0c0a6d80 */
if(!s->budget--) { s->failed_pc=0x0c0a6d80u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0a6d82;
P_0c0a6d82: /* original feac, guest PC 0x0c0a6d82 */
if(!s->budget--) { s->failed_pc=0x0c0a6d82u; return 0; }
vf3_matrix_move(s,14,10);
goto P_0c0a6d84;
P_0c0a6d84: /* original fe21, guest PC 0x0c0a6d84 */
if(!s->budget--) { s->failed_pc=0x0c0a6d84u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'-');
goto P_0c0a6d86;
P_0c0a6d86: /* original f2f6, guest PC 0x0c0a6d86 */
if(!s->budget--) { s->failed_pc=0x0c0a6d86u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6d88;
P_0c0a6d88: /* original e008, guest PC 0x0c0a6d88 */
if(!s->budget--) { s->failed_pc=0x0c0a6d88u; return 0; }
r[0]=0x00000008u;
goto P_0c0a6d8a;
P_0c0a6d8a: /* original f821, guest PC 0x0c0a6d8a */
if(!s->budget--) { s->failed_pc=0x0c0a6d8au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c0a6d8c;
P_0c0a6d8c: /* original ff87, guest PC 0x0c0a6d8c */
if(!s->budget--) { s->failed_pc=0x0c0a6d8cu; return 0; }
vf3_matrix_store(s,ram,8,r[15]+r[0]);
goto P_0c0a6d8e;
P_0c0a6d8e: /* original f732, guest PC 0x0c0a6d8e */
if(!s->budget--) { s->failed_pc=0x0c0a6d8eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0a6d90;
P_0c0a6d90: /* original f0f8, guest PC 0x0c0a6d90 */
if(!s->budget--) { s->failed_pc=0x0c0a6d90u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c0a6d92;
P_0c0a6d92: /* original f28c, guest PC 0x0c0a6d92 */
if(!s->budget--) { s->failed_pc=0x0c0a6d92u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c0a6d94;
P_0c0a6d94: /* original 7f38, guest PC 0x0c0a6d94 */
if(!s->budget--) { s->failed_pc=0x0c0a6d94u; return 0; }
r[15]+=0x00000038u;
goto P_0c0a6d96;
P_0c0a6d96: /* original f642, guest PC 0x0c0a6d96 */
if(!s->budget--) { s->failed_pc=0x0c0a6d96u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a6d98;
P_0c0a6d98: /* original e004, guest PC 0x0c0a6d98 */
if(!s->budget--) { s->failed_pc=0x0c0a6d98u; return 0; }
r[0]=0x00000004u;
goto P_0c0a6d9a;
P_0c0a6d9a: /* original f542, guest PC 0x0c0a6d9a */
if(!s->budget--) { s->failed_pc=0x0c0a6d9au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0a6d9c;
P_0c0a6d9c: /* original f37c, guest PC 0x0c0a6d9c */
if(!s->budget--) { s->failed_pc=0x0c0a6d9cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0a6d9e;
P_0c0a6d9e: /* original f3ee, guest PC 0x0c0a6d9e */
if(!s->budget--) { s->failed_pc=0x0c0a6d9eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c0a6da0;
P_0c0a6da0: /* original f0dc, guest PC 0x0c0a6da0 */
if(!s->budget--) { s->failed_pc=0x0c0a6da0u; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0a6da2;
P_0c0a6da2: /* original f32e, guest PC 0x0c0a6da2 */
if(!s->budget--) { s->failed_pc=0x0c0a6da2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0a6da4;
P_0c0a6da4: /* original f73c, guest PC 0x0c0a6da4 */
if(!s->budget--) { s->failed_pc=0x0c0a6da4u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c0a6da6;
P_0c0a6da6: /* original f742, guest PC 0x0c0a6da6 */
if(!s->budget--) { s->failed_pc=0x0c0a6da6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a6da8;
P_0c0a6da8: /* original f55a, guest PC 0x0c0a6da8 */
if(!s->budget--) { s->failed_pc=0x0c0a6da8u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c0a6daa;
P_0c0a6daa: /* original f567, guest PC 0x0c0a6daa */
if(!s->budget--) { s->failed_pc=0x0c0a6daau; return 0; }
vf3_matrix_store(s,ram,6,r[5]+r[0]);
goto P_0c0a6dac;
P_0c0a6dac: /* original e008, guest PC 0x0c0a6dac */
if(!s->budget--) { s->failed_pc=0x0c0a6dacu; return 0; }
r[0]=0x00000008u;
goto P_0c0a6dae;
P_0c0a6dae: /* original f577, guest PC 0x0c0a6dae */
if(!s->budget--) { s->failed_pc=0x0c0a6daeu; return 0; }
vf3_matrix_store(s,ram,7,r[5]+r[0]);
goto P_0c0a6db0;
P_0c0a6db0: /* original fcf9, guest PC 0x0c0a6db0 */
if(!s->budget--) { s->failed_pc=0x0c0a6db0u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6db2;
P_0c0a6db2: /* original fdf9, guest PC 0x0c0a6db2 */
if(!s->budget--) { s->failed_pc=0x0c0a6db2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6db4;
P_0c0a6db4: /* original fef9, guest PC 0x0c0a6db4 */
if(!s->budget--) { s->failed_pc=0x0c0a6db4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a6db6;
P_0c0a6db6: /* original 000b, guest PC 0x0c0a6db6 */
if(!s->budget--) { s->failed_pc=0x0c0a6db6u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c0a6db8: /* original fff9, guest PC 0x0c0a6db8 */
if(!s->budget--) { s->failed_pc=0x0c0a6db8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0a6dbau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0a67ceu,0x0c0a67d0u,0x0c0a67d2u,0x0c0a67d4u,0x0c0a67d6u,0x0c0a67d8u,0x0c0a67dau,0x0c0a67dcu,0x0c0a67deu,0x0c0a67e0u,0x0c0a67e2u,0x0c0a67e4u,0x0c0a67e6u,0x0c0a67e8u,0x0c0a67eau,0x0c0a67ecu,
0x0c0a67eeu,0x0c0a67f0u,0x0c0a67f2u,0x0c0a67f4u,0x0c0a67f6u,0x0c0a67f8u,0x0c0a67fau,0x0c0a67fcu,0x0c0a67feu,0x0c0a6800u,0x0c0a6802u,0x0c0a6804u,0x0c0a6806u,0x0c0a6808u,0x0c0a680au,0x0c0a680cu,
0x0c0a680eu,0x0c0a6810u,0x0c0a6812u,0x0c0a6814u,0x0c0a6816u,0x0c0a6818u,0x0c0a681au,0x0c0a681cu,0x0c0a681eu,0x0c0a6820u,0x0c0a6822u,0x0c0a6824u,0x0c0a6826u,0x0c0a6828u,0x0c0a682au,0x0c0a682cu,
0x0c0a682eu,0x0c0a6830u,0x0c0a6832u,0x0c0a6834u,0x0c0a6836u,0x0c0a6838u,0x0c0a683au,0x0c0a683cu,0x0c0a683eu,0x0c0a6840u,0x0c0a6842u,0x0c0a6844u,0x0c0a6846u,0x0c0a6848u,0x0c0a684au,0x0c0a684cu,
0x0c0a684eu,0x0c0a6850u,0x0c0a6852u,0x0c0a6854u,0x0c0a6856u,0x0c0a6858u,0x0c0a685au,0x0c0a685cu,0x0c0a685eu,0x0c0a6860u,0x0c0a6862u,0x0c0a6864u,0x0c0a6866u,0x0c0a6868u,0x0c0a686au,0x0c0a686cu,
0x0c0a686eu,0x0c0a6870u,0x0c0a6872u,0x0c0a6874u,0x0c0a6876u,0x0c0a6878u,0x0c0a687au,0x0c0a687cu,0x0c0a687eu,0x0c0a6880u,0x0c0a6882u,0x0c0a6884u,0x0c0a6886u,0x0c0a6888u,0x0c0a688au,0x0c0a688cu,
0x0c0a688eu,0x0c0a6890u,0x0c0a6892u,0x0c0a6894u,0x0c0a6896u,0x0c0a6898u,0x0c0a689au,0x0c0a689cu,0x0c0a689eu,0x0c0a68a0u,0x0c0a68a2u,0x0c0a68a4u,0x0c0a68a6u,0x0c0a68a8u,0x0c0a68aau,0x0c0a68acu,
0x0c0a68aeu,0x0c0a68b0u,0x0c0a68b2u,0x0c0a68b4u,0x0c0a68b6u,0x0c0a68b8u,0x0c0a68bau,0x0c0a68bcu,0x0c0a68beu,0x0c0a68c0u,0x0c0a68c2u,0x0c0a68c4u,0x0c0a68c6u,0x0c0a68c8u,0x0c0a68cau,0x0c0a68ccu,
0x0c0a68ceu,0x0c0a68d0u,0x0c0a68d2u,0x0c0a68d4u,0x0c0a68d6u,0x0c0a68d8u,0x0c0a68dau,0x0c0a68dcu,0x0c0a68deu,0x0c0a68e0u,0x0c0a68e2u,0x0c0a68e4u,0x0c0a68e6u,0x0c0a68e8u,0x0c0a68eau,0x0c0a68ecu,
0x0c0a68eeu,0x0c0a68f0u,0x0c0a68f2u,0x0c0a68f4u,0x0c0a68f6u,0x0c0a68f8u,0x0c0a68fau,0x0c0a68fcu,0x0c0a68feu,0x0c0a6900u,0x0c0a6902u,0x0c0a6904u,0x0c0a6906u,0x0c0a6908u,0x0c0a690au,0x0c0a690cu,
0x0c0a690eu,0x0c0a6910u,0x0c0a6912u,0x0c0a6914u,0x0c0a6916u,0x0c0a6918u,0x0c0a691au,0x0c0a691cu,0x0c0a691eu,0x0c0a6920u,0x0c0a6922u,0x0c0a6924u,0x0c0a6926u,0x0c0a6928u,0x0c0a692au,0x0c0a692cu,
0x0c0a692eu,0x0c0a6930u,0x0c0a6932u,0x0c0a6934u,0x0c0a6936u,0x0c0a6938u,0x0c0a693au,0x0c0a693cu,0x0c0a693eu,0x0c0a6940u,0x0c0a6942u,0x0c0a6944u,0x0c0a6946u,0x0c0a6948u,0x0c0a694au,0x0c0a694cu,
0x0c0a694eu,0x0c0a6950u,0x0c0a6952u,0x0c0a6954u,0x0c0a6956u,0x0c0a6958u,0x0c0a695au,0x0c0a695cu,0x0c0a695eu,0x0c0a6960u,0x0c0a6962u,0x0c0a6964u,0x0c0a6966u,0x0c0a6968u,0x0c0a696au,0x0c0a696cu,
0x0c0a696eu,0x0c0a6970u,0x0c0a6972u,0x0c0a6974u,0x0c0a6976u,0x0c0a6978u,0x0c0a697au,0x0c0a697cu,0x0c0a697eu,0x0c0a6980u,0x0c0a6982u,0x0c0a6984u,0x0c0a6986u,0x0c0a6988u,0x0c0a698au,0x0c0a698cu,
0x0c0a698eu,0x0c0a6990u,0x0c0a6992u,0x0c0a6994u,0x0c0a6996u,0x0c0a6998u,0x0c0a699au,0x0c0a699cu,0x0c0a699eu,0x0c0a69a0u,0x0c0a69a2u,0x0c0a69a4u,0x0c0a69a6u,0x0c0a69a8u,0x0c0a69aau,0x0c0a69acu,
0x0c0a69aeu,0x0c0a69b0u,0x0c0a69b2u,0x0c0a69b4u,0x0c0a69b6u,0x0c0a69b8u,0x0c0a69bau,0x0c0a69bcu,0x0c0a69beu,0x0c0a69c0u,0x0c0a69c2u,0x0c0a69c4u,0x0c0a69c6u,0x0c0a69c8u,0x0c0a69cau,0x0c0a69ccu,
0x0c0a69ceu,0x0c0a69d0u,0x0c0a69d2u,0x0c0a69d4u,0x0c0a69d6u,0x0c0a69d8u,0x0c0a69dau,0x0c0a69dcu,0x0c0a69deu,0x0c0a69e0u,0x0c0a69e2u,0x0c0a69e4u,0x0c0a69e6u,0x0c0a69e8u,0x0c0a69eau,0x0c0a69ecu,
0x0c0a69eeu,0x0c0a69f0u,0x0c0a69f2u,0x0c0a69f4u,0x0c0a69f6u,0x0c0a69f8u,0x0c0a69fau,0x0c0a69fcu,0x0c0a69feu,0x0c0a6a00u,0x0c0a6a02u,0x0c0a6a04u,0x0c0a6a06u,0x0c0a6a08u,0x0c0a6a0au,0x0c0a6a0cu,
0x0c0a6a0eu,0x0c0a6a10u,0x0c0a6a12u,0x0c0a6a14u,0x0c0a6a16u,0x0c0a6a18u,0x0c0a6a1au,0x0c0a6a1cu,0x0c0a6a1eu,0x0c0a6a20u,0x0c0a6a22u,0x0c0a6a24u,0x0c0a6a26u,0x0c0a6a28u,0x0c0a6a2au,0x0c0a6a2cu,
0x0c0a6a2eu,0x0c0a6a30u,0x0c0a6a32u,0x0c0a6a34u,0x0c0a6a36u,0x0c0a6a38u,0x0c0a6a3au,0x0c0a6a3cu,0x0c0a6a3eu,0x0c0a6a40u,0x0c0a6a42u,0x0c0a6a44u,0x0c0a6a46u,0x0c0a6a48u,0x0c0a6a4au,0x0c0a6a4cu,
0x0c0a6a4eu,0x0c0a6a50u,0x0c0a6a52u,0x0c0a6a54u,0x0c0a6a56u,0x0c0a6a58u,0x0c0a6a5au,0x0c0a6a5cu,0x0c0a6a5eu,0x0c0a6a60u,0x0c0a6a62u,0x0c0a6a64u,0x0c0a6a66u,0x0c0a6a68u,0x0c0a6a6au,0x0c0a6a6cu,
0x0c0a6a6eu,0x0c0a6a70u,0x0c0a6a72u,0x0c0a6a74u,0x0c0a6a76u,0x0c0a6a78u,0x0c0a6a7au,0x0c0a6a7cu,0x0c0a6a7eu,0x0c0a6a80u,0x0c0a6a82u,0x0c0a6a84u,0x0c0a6a86u,0x0c0a6a88u,0x0c0a6a8au,0x0c0a6a8cu,
0x0c0a6a8eu,0x0c0a6a90u,0x0c0a6a92u,0x0c0a6a94u,0x0c0a6a96u,0x0c0a6a98u,0x0c0a6a9au,0x0c0a6a9cu,0x0c0a6a9eu,0x0c0a6aa0u,0x0c0a6aa2u,0x0c0a6aa4u,0x0c0a6aa6u,0x0c0a6aa8u,0x0c0a6aaau,0x0c0a6aacu,
0x0c0a6aaeu,0x0c0a6ab0u,0x0c0a6ab2u,0x0c0a6ab4u,0x0c0a6ab6u,0x0c0a6ab8u,0x0c0a6abau,0x0c0a6abcu,0x0c0a6abeu,0x0c0a6ac0u,0x0c0a6ac2u,0x0c0a6ac4u,0x0c0a6ac6u,0x0c0a6ac8u,0x0c0a6acau,0x0c0a6af4u,
0x0c0a6af6u,0x0c0a6af8u,0x0c0a6afau,0x0c0a6afcu,0x0c0a6afeu,0x0c0a6b00u,0x0c0a6b02u,0x0c0a6b04u,0x0c0a6b06u,0x0c0a6b08u,0x0c0a6b0au,0x0c0a6b0cu,0x0c0a6b0eu,0x0c0a6b10u,0x0c0a6b12u,0x0c0a6b14u,
0x0c0a6b16u,0x0c0a6b18u,0x0c0a6b1au,0x0c0a6b1cu,0x0c0a6b1eu,0x0c0a6b20u,0x0c0a6b22u,0x0c0a6b24u,0x0c0a6b26u,0x0c0a6b28u,0x0c0a6b2au,0x0c0a6b2cu,0x0c0a6b2eu,0x0c0a6b30u,0x0c0a6b32u,0x0c0a6b34u,
0x0c0a6b36u,0x0c0a6b38u,0x0c0a6b3au,0x0c0a6b3cu,0x0c0a6b3eu,0x0c0a6b40u,0x0c0a6b42u,0x0c0a6b44u,0x0c0a6b46u,0x0c0a6b48u,0x0c0a6b4au,0x0c0a6b4cu,0x0c0a6b4eu,0x0c0a6b50u,0x0c0a6b52u,0x0c0a6b54u,
0x0c0a6b56u,0x0c0a6b58u,0x0c0a6b5au,0x0c0a6b5cu,0x0c0a6b5eu,0x0c0a6b60u,0x0c0a6b62u,0x0c0a6b64u,0x0c0a6b66u,0x0c0a6b68u,0x0c0a6b6au,0x0c0a6b6cu,0x0c0a6b6eu,0x0c0a6b70u,0x0c0a6b72u,0x0c0a6b74u,
0x0c0a6b76u,0x0c0a6b78u,0x0c0a6b7au,0x0c0a6b7cu,0x0c0a6b7eu,0x0c0a6b80u,0x0c0a6b82u,0x0c0a6b84u,0x0c0a6b86u,0x0c0a6b88u,0x0c0a6b8au,0x0c0a6b8cu,0x0c0a6b8eu,0x0c0a6b90u,0x0c0a6b92u,0x0c0a6b94u,
0x0c0a6b96u,0x0c0a6b98u,0x0c0a6b9au,0x0c0a6b9cu,0x0c0a6b9eu,0x0c0a6ba0u,0x0c0a6ba2u,0x0c0a6ba4u,0x0c0a6ba6u,0x0c0a6ba8u,0x0c0a6baau,0x0c0a6bacu,0x0c0a6baeu,0x0c0a6bb0u,0x0c0a6bb2u,0x0c0a6bb4u,
0x0c0a6bb6u,0x0c0a6bb8u,0x0c0a6bbau,0x0c0a6bbcu,0x0c0a6bbeu,0x0c0a6bc0u,0x0c0a6bc2u,0x0c0a6bc4u,0x0c0a6bc6u,0x0c0a6bc8u,0x0c0a6bcau,0x0c0a6bccu,0x0c0a6bceu,0x0c0a6bd0u,0x0c0a6bd2u,0x0c0a6bd4u,
0x0c0a6bd6u,0x0c0a6bd8u,0x0c0a6bdau,0x0c0a6bdcu,0x0c0a6bdeu,0x0c0a6be0u,0x0c0a6be2u,0x0c0a6be4u,0x0c0a6be6u,0x0c0a6be8u,0x0c0a6beau,0x0c0a6becu,0x0c0a6beeu,0x0c0a6bf0u,0x0c0a6bf2u,0x0c0a6bf4u,
0x0c0a6bf6u,0x0c0a6bf8u,0x0c0a6bfau,0x0c0a6bfcu,0x0c0a6bfeu,0x0c0a6c00u,0x0c0a6c02u,0x0c0a6c04u,0x0c0a6c06u,0x0c0a6c08u,0x0c0a6c0au,0x0c0a6c0cu,0x0c0a6c0eu,0x0c0a6c10u,0x0c0a6c12u,0x0c0a6c14u,
0x0c0a6c16u,0x0c0a6c18u,0x0c0a6c1au,0x0c0a6c1cu,0x0c0a6c1eu,0x0c0a6c20u,0x0c0a6c22u,0x0c0a6c24u,0x0c0a6c26u,0x0c0a6c28u,0x0c0a6c2au,0x0c0a6c2cu,0x0c0a6c2eu,0x0c0a6c30u,0x0c0a6c32u,0x0c0a6c34u,
0x0c0a6c36u,0x0c0a6c38u,0x0c0a6c3au,0x0c0a6c3cu,0x0c0a6c3eu,0x0c0a6c40u,0x0c0a6c42u,0x0c0a6c44u,0x0c0a6c46u,0x0c0a6c48u,0x0c0a6c4au,0x0c0a6c4cu,0x0c0a6c4eu,0x0c0a6c50u,0x0c0a6c52u,0x0c0a6c54u,
0x0c0a6c56u,0x0c0a6c58u,0x0c0a6c5au,0x0c0a6c5cu,0x0c0a6c5eu,0x0c0a6c60u,0x0c0a6c62u,0x0c0a6c64u,0x0c0a6c66u,0x0c0a6c68u,0x0c0a6c6au,0x0c0a6c6cu,0x0c0a6c6eu,0x0c0a6c70u,0x0c0a6c72u,0x0c0a6c74u,
0x0c0a6c76u,0x0c0a6c78u,0x0c0a6c7au,0x0c0a6c7cu,0x0c0a6c7eu,0x0c0a6c80u,0x0c0a6c82u,0x0c0a6c84u,0x0c0a6c86u,0x0c0a6c88u,0x0c0a6c8au,0x0c0a6c8cu,0x0c0a6c8eu,0x0c0a6c90u,0x0c0a6c92u,0x0c0a6c94u,
0x0c0a6c96u,0x0c0a6c98u,0x0c0a6c9au,0x0c0a6c9cu,0x0c0a6c9eu,0x0c0a6ca0u,0x0c0a6ca2u,0x0c0a6ca4u,0x0c0a6ca6u,0x0c0a6ca8u,0x0c0a6caau,0x0c0a6cacu,0x0c0a6caeu,0x0c0a6cb0u,0x0c0a6cb2u,0x0c0a6cb4u,
0x0c0a6cb6u,0x0c0a6cb8u,0x0c0a6cbau,0x0c0a6cbcu,0x0c0a6cbeu,0x0c0a6cc0u,0x0c0a6cc2u,0x0c0a6cc4u,0x0c0a6cc6u,0x0c0a6cc8u,0x0c0a6ccau,0x0c0a6cccu,0x0c0a6cceu,0x0c0a6cd0u,0x0c0a6cd2u,0x0c0a6cd4u,
0x0c0a6cd6u,0x0c0a6cd8u,0x0c0a6cdau,0x0c0a6cdcu,0x0c0a6cdeu,0x0c0a6ce0u,0x0c0a6ce2u,0x0c0a6ce4u,0x0c0a6ce6u,0x0c0a6ce8u,0x0c0a6ceau,0x0c0a6cecu,0x0c0a6ceeu,0x0c0a6cf0u,0x0c0a6cf2u,0x0c0a6cf4u,
0x0c0a6cf6u,0x0c0a6cf8u,0x0c0a6cfau,0x0c0a6cfcu,0x0c0a6cfeu,0x0c0a6d00u,0x0c0a6d02u,0x0c0a6d04u,0x0c0a6d06u,0x0c0a6d08u,0x0c0a6d0au,0x0c0a6d0cu,0x0c0a6d0eu,0x0c0a6d10u,0x0c0a6d12u,0x0c0a6d14u,
0x0c0a6d16u,0x0c0a6d18u,0x0c0a6d1au,0x0c0a6d1cu,0x0c0a6d1eu,0x0c0a6d20u,0x0c0a6d22u,0x0c0a6d24u,0x0c0a6d26u,0x0c0a6d28u,0x0c0a6d2au,0x0c0a6d2cu,0x0c0a6d2eu,0x0c0a6d30u,0x0c0a6d32u,0x0c0a6d34u,
0x0c0a6d36u,0x0c0a6d38u,0x0c0a6d3au,0x0c0a6d3cu,0x0c0a6d3eu,0x0c0a6d40u,0x0c0a6d42u,0x0c0a6d44u,0x0c0a6d46u,0x0c0a6d48u,0x0c0a6d4au,0x0c0a6d4cu,0x0c0a6d4eu,0x0c0a6d50u,0x0c0a6d52u,0x0c0a6d54u,
0x0c0a6d56u,0x0c0a6d58u,0x0c0a6d5au,0x0c0a6d5cu,0x0c0a6d5eu,0x0c0a6d60u,0x0c0a6d62u,0x0c0a6d64u,0x0c0a6d66u,0x0c0a6d68u,0x0c0a6d6au,0x0c0a6d6cu,0x0c0a6d6eu,0x0c0a6d70u,0x0c0a6d72u,0x0c0a6d74u,
0x0c0a6d76u,0x0c0a6d78u,0x0c0a6d7au,0x0c0a6d7cu,0x0c0a6d7eu,0x0c0a6d80u,0x0c0a6d82u,0x0c0a6d84u,0x0c0a6d86u,0x0c0a6d88u,0x0c0a6d8au,0x0c0a6d8cu,0x0c0a6d8eu,0x0c0a6d90u,0x0c0a6d92u,0x0c0a6d94u,
0x0c0a6d96u,0x0c0a6d98u,0x0c0a6d9au,0x0c0a6d9cu,0x0c0a6d9eu,0x0c0a6da0u,0x0c0a6da2u,0x0c0a6da4u,0x0c0a6da6u,0x0c0a6da8u,0x0c0a6daau,0x0c0a6dacu,0x0c0a6daeu,0x0c0a6db0u,0x0c0a6db2u,0x0c0a6db4u,
0x0c0a6db6u,0x0c0a6db8u,
};
int vf3_0a67_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
