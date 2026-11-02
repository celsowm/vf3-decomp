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
int vf3_away_batch121_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b0f4u: goto P_0c07b0f4;
case 0x0c07b0f6u: goto P_0c07b0f6;
case 0x0c07b0f8u: goto P_0c07b0f8;
case 0x0c07b0fau: goto P_0c07b0fa;
case 0x0c07b0fcu: goto P_0c07b0fc;
case 0x0c07b0feu: goto P_0c07b0fe;
case 0x0c07b100u: goto P_0c07b100;
case 0x0c07b102u: goto P_0c07b102;
case 0x0c07b104u: goto P_0c07b104;
case 0x0c07b106u: goto P_0c07b106;
case 0x0c07b108u: goto P_0c07b108;
case 0x0c07b10au: goto P_0c07b10a;
case 0x0c07b10cu: goto P_0c07b10c;
case 0x0c07b10eu: goto P_0c07b10e;
case 0x0c07b110u: goto P_0c07b110;
case 0x0c07b112u: goto P_0c07b112;
case 0x0c07b114u: goto P_0c07b114;
case 0x0c07b116u: goto P_0c07b116;
case 0x0c07b118u: goto P_0c07b118;
case 0x0c07b11au: goto P_0c07b11a;
case 0x0c07b11cu: goto P_0c07b11c;
case 0x0c07b11eu: goto P_0c07b11e;
case 0x0c07b120u: goto P_0c07b120;
case 0x0c07b122u: goto P_0c07b122;
case 0x0c07b124u: goto P_0c07b124;
case 0x0c07b126u: goto P_0c07b126;
case 0x0c07b128u: goto P_0c07b128;
case 0x0c07b12au: goto P_0c07b12a;
case 0x0c07b12cu: goto P_0c07b12c;
case 0x0c07b12eu: goto P_0c07b12e;
case 0x0c07b130u: goto P_0c07b130;
case 0x0c07b132u: goto P_0c07b132;
case 0x0c07b134u: goto P_0c07b134;
case 0x0c07b136u: goto P_0c07b136;
case 0x0c07b138u: goto P_0c07b138;
case 0x0c07b13au: goto P_0c07b13a;
case 0x0c07b13cu: goto P_0c07b13c;
case 0x0c07b13eu: goto P_0c07b13e;
case 0x0c07b140u: goto P_0c07b140;
case 0x0c07b142u: goto P_0c07b142;
case 0x0c07b144u: goto P_0c07b144;
case 0x0c07b146u: goto P_0c07b146;
case 0x0c07b148u: goto P_0c07b148;
case 0x0c07b14au: goto P_0c07b14a;
case 0x0c07b14cu: goto P_0c07b14c;
case 0x0c07b14eu: goto P_0c07b14e;
case 0x0c07b150u: goto P_0c07b150;
case 0x0c07b152u: goto P_0c07b152;
case 0x0c07b154u: goto P_0c07b154;
case 0x0c07b156u: goto P_0c07b156;
case 0x0c07b158u: goto P_0c07b158;
case 0x0c07b15au: goto P_0c07b15a;
case 0x0c07b15cu: goto P_0c07b15c;
case 0x0c07b15eu: goto P_0c07b15e;
case 0x0c07b160u: goto P_0c07b160;
case 0x0c07b162u: goto P_0c07b162;
case 0x0c07b164u: goto P_0c07b164;
case 0x0c07b166u: goto P_0c07b166;
case 0x0c07b168u: goto P_0c07b168;
case 0x0c07b16au: goto P_0c07b16a;
case 0x0c07b16cu: goto P_0c07b16c;
case 0x0c07b16eu: goto P_0c07b16e;
case 0x0c07b170u: goto P_0c07b170;
case 0x0c07b172u: goto P_0c07b172;
case 0x0c07b174u: goto P_0c07b174;
case 0x0c07b176u: goto P_0c07b176;
case 0x0c07b178u: goto P_0c07b178;
case 0x0c07b17au: goto P_0c07b17a;
case 0x0c07b17cu: goto P_0c07b17c;
case 0x0c07b17eu: goto P_0c07b17e;
case 0x0c07b180u: goto P_0c07b180;
case 0x0c07b182u: goto P_0c07b182;
case 0x0c07b184u: goto P_0c07b184;
case 0x0c07b186u: goto P_0c07b186;
case 0x0c07b188u: goto P_0c07b188;
case 0x0c07b18au: goto P_0c07b18a;
case 0x0c07b18cu: goto P_0c07b18c;
case 0x0c07b18eu: goto P_0c07b18e;
case 0x0c07b190u: goto P_0c07b190;
case 0x0c07b192u: goto P_0c07b192;
case 0x0c07b194u: goto P_0c07b194;
case 0x0c07b196u: goto P_0c07b196;
case 0x0c07b198u: goto P_0c07b198;
case 0x0c07b19au: goto P_0c07b19a;
case 0x0c07b19cu: goto P_0c07b19c;
case 0x0c07b19eu: goto P_0c07b19e;
case 0x0c07b1a0u: goto P_0c07b1a0;
case 0x0c07b1a2u: goto P_0c07b1a2;
case 0x0c07b1a4u: goto P_0c07b1a4;
case 0x0c07b1a6u: goto P_0c07b1a6;
case 0x0c07b1a8u: goto P_0c07b1a8;
case 0x0c07b1aau: goto P_0c07b1aa;
case 0x0c07b1acu: goto P_0c07b1ac;
case 0x0c07b1aeu: goto P_0c07b1ae;
case 0x0c07b1b0u: goto P_0c07b1b0;
case 0x0c07b1b2u: goto P_0c07b1b2;
case 0x0c07b1b4u: goto P_0c07b1b4;
case 0x0c07b1b6u: goto P_0c07b1b6;
case 0x0c07b1b8u: goto P_0c07b1b8;
case 0x0c07b1bau: goto P_0c07b1ba;
case 0x0c07b1bcu: goto P_0c07b1bc;
case 0x0c07b1beu: goto P_0c07b1be;
case 0x0c07b1c0u: goto P_0c07b1c0;
case 0x0c07b1c2u: goto P_0c07b1c2;
case 0x0c07b1c4u: goto P_0c07b1c4;
case 0x0c07b1c6u: goto P_0c07b1c6;
case 0x0c07b1c8u: goto P_0c07b1c8;
case 0x0c07b1cau: goto P_0c07b1ca;
case 0x0c07b1ccu: goto P_0c07b1cc;
case 0x0c07b1ceu: goto P_0c07b1ce;
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
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0968f8u: goto P_0c0968f8;
case 0x0c0968fau: goto P_0c0968fa;
case 0x0c0968fcu: goto P_0c0968fc;
case 0x0c0968feu: goto P_0c0968fe;
case 0x0c096900u: goto P_0c096900;
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
case 0x0c09ac14u: goto P_0c09ac14;
case 0x0c09ac16u: goto P_0c09ac16;
case 0x0c09ac18u: goto P_0c09ac18;
case 0x0c09ac1au: goto P_0c09ac1a;
case 0x0c09ac1cu: goto P_0c09ac1c;
case 0x0c09ac1eu: goto P_0c09ac1e;
case 0x0c09ac20u: goto P_0c09ac20;
case 0x0c09ac22u: goto P_0c09ac22;
case 0x0c09ac24u: goto P_0c09ac24;
case 0x0c09ac26u: goto P_0c09ac26;
case 0x0c09ac28u: goto P_0c09ac28;
case 0x0c09ac2au: goto P_0c09ac2a;
case 0x0c09ac2cu: goto P_0c09ac2c;
case 0x0c09ac2eu: goto P_0c09ac2e;
case 0x0c09ac30u: goto P_0c09ac30;
case 0x0c09ac32u: goto P_0c09ac32;
case 0x0c09ac34u: goto P_0c09ac34;
case 0x0c09ac36u: goto P_0c09ac36;
case 0x0c09ac38u: goto P_0c09ac38;
case 0x0c09ac3au: goto P_0c09ac3a;
case 0x0c09ac3cu: goto P_0c09ac3c;
case 0x0c09ac3eu: goto P_0c09ac3e;
case 0x0c09ac40u: goto P_0c09ac40;
case 0x0c09ac42u: goto P_0c09ac42;
case 0x0c09ac44u: goto P_0c09ac44;
case 0x0c09ac46u: goto P_0c09ac46;
case 0x0c09ac48u: goto P_0c09ac48;
case 0x0c09ac4au: goto P_0c09ac4a;
case 0x0c09ac4cu: goto P_0c09ac4c;
case 0x0c09ac4eu: goto P_0c09ac4e;
case 0x0c09ac50u: goto P_0c09ac50;
case 0x0c09ac52u: goto P_0c09ac52;
case 0x0c09ac54u: goto P_0c09ac54;
case 0x0c09ac56u: goto P_0c09ac56;
case 0x0c09ac58u: goto P_0c09ac58;
case 0x0c09ac5au: goto P_0c09ac5a;
case 0x0c09ac5cu: goto P_0c09ac5c;
case 0x0c09ac5eu: goto P_0c09ac5e;
case 0x0c09ac60u: goto P_0c09ac60;
case 0x0c09ac62u: goto P_0c09ac62;
case 0x0c09ac64u: goto P_0c09ac64;
case 0x0c09ac66u: goto P_0c09ac66;
case 0x0c09ac68u: goto P_0c09ac68;
case 0x0c09ac6au: goto P_0c09ac6a;
case 0x0c09ac6cu: goto P_0c09ac6c;
case 0x0c09ac6eu: goto P_0c09ac6e;
case 0x0c09ac70u: goto P_0c09ac70;
case 0x0c09ac72u: goto P_0c09ac72;
case 0x0c09ac74u: goto P_0c09ac74;
case 0x0c09ac76u: goto P_0c09ac76;
case 0x0c09ac78u: goto P_0c09ac78;
case 0x0c09ac7au: goto P_0c09ac7a;
case 0x0c09ac7cu: goto P_0c09ac7c;
case 0x0c09ac7eu: goto P_0c09ac7e;
case 0x0c09ac80u: goto P_0c09ac80;
case 0x0c09ac82u: goto P_0c09ac82;
case 0x0c09ac84u: goto P_0c09ac84;
case 0x0c09ac86u: goto P_0c09ac86;
case 0x0c09ac88u: goto P_0c09ac88;
case 0x0c09ac8au: goto P_0c09ac8a;
case 0x0c09ac8cu: goto P_0c09ac8c;
case 0x0c09ac8eu: goto P_0c09ac8e;
case 0x0c09ac90u: goto P_0c09ac90;
case 0x0c09ac92u: goto P_0c09ac92;
case 0x0c09ac94u: goto P_0c09ac94;
case 0x0c09ac96u: goto P_0c09ac96;
case 0x0c09ac98u: goto P_0c09ac98;
case 0x0c09ac9au: goto P_0c09ac9a;
case 0x0c09ac9cu: goto P_0c09ac9c;
case 0x0c09ac9eu: goto P_0c09ac9e;
case 0x0c09aca0u: goto P_0c09aca0;
case 0x0c09aca2u: goto P_0c09aca2;
case 0x0c09aca4u: goto P_0c09aca4;
case 0x0c09aca6u: goto P_0c09aca6;
case 0x0c09aca8u: goto P_0c09aca8;
case 0x0c09acaau: goto P_0c09acaa;
case 0x0c09acacu: goto P_0c09acac;
case 0x0c09acaeu: goto P_0c09acae;
case 0x0c09acb0u: goto P_0c09acb0;
case 0x0c09acb2u: goto P_0c09acb2;
case 0x0c09acb4u: goto P_0c09acb4;
case 0x0c09acb6u: goto P_0c09acb6;
case 0x0c09acb8u: goto P_0c09acb8;
case 0x0c09acbau: goto P_0c09acba;
case 0x0c09acbcu: goto P_0c09acbc;
case 0x0c09acbeu: goto P_0c09acbe;
case 0x0c09acc0u: goto P_0c09acc0;
case 0x0c09acc2u: goto P_0c09acc2;
case 0x0c09acc4u: goto P_0c09acc4;
case 0x0c09acc6u: goto P_0c09acc6;
case 0x0c09acc8u: goto P_0c09acc8;
case 0x0c09accau: goto P_0c09acca;
case 0x0c09acccu: goto P_0c09accc;
case 0x0c09acceu: goto P_0c09acce;
case 0x0c09acd0u: goto P_0c09acd0;
case 0x0c09acd2u: goto P_0c09acd2;
case 0x0c09acd4u: goto P_0c09acd4;
case 0x0c09acd6u: goto P_0c09acd6;
case 0x0c09acd8u: goto P_0c09acd8;
case 0x0c09acdau: goto P_0c09acda;
case 0x0c09acdcu: goto P_0c09acdc;
case 0x0c09acdeu: goto P_0c09acde;
case 0x0c09ace0u: goto P_0c09ace0;
case 0x0c09ace2u: goto P_0c09ace2;
case 0x0c09ace4u: goto P_0c09ace4;
case 0x0c09ace6u: goto P_0c09ace6;
case 0x0c09ace8u: goto P_0c09ace8;
case 0x0c09aceau: goto P_0c09acea;
case 0x0c09acecu: goto P_0c09acec;
case 0x0c09aceeu: goto P_0c09acee;
case 0x0c09acf0u: goto P_0c09acf0;
case 0x0c09acf2u: goto P_0c09acf2;
case 0x0c09acf4u: goto P_0c09acf4;
case 0x0c09acf6u: goto P_0c09acf6;
case 0x0c09acf8u: goto P_0c09acf8;
case 0x0c09acfau: goto P_0c09acfa;
case 0x0c09acfcu: goto P_0c09acfc;
case 0x0c09acfeu: goto P_0c09acfe;
case 0x0c09ad00u: goto P_0c09ad00;
case 0x0c09ad02u: goto P_0c09ad02;
case 0x0c09ad04u: goto P_0c09ad04;
case 0x0c09ad06u: goto P_0c09ad06;
case 0x0c09ad08u: goto P_0c09ad08;
case 0x0c09ad0au: goto P_0c09ad0a;
case 0x0c09ad0cu: goto P_0c09ad0c;
case 0x0c09ad0eu: goto P_0c09ad0e;
case 0x0c09ad10u: goto P_0c09ad10;
case 0x0c09ad12u: goto P_0c09ad12;
case 0x0c09ad14u: goto P_0c09ad14;
case 0x0c09ad16u: goto P_0c09ad16;
case 0x0c09ad18u: goto P_0c09ad18;
case 0x0c09ad1au: goto P_0c09ad1a;
case 0x0c09ad1cu: goto P_0c09ad1c;
case 0x0c09ad1eu: goto P_0c09ad1e;
case 0x0c09ad20u: goto P_0c09ad20;
case 0x0c09ad22u: goto P_0c09ad22;
case 0x0c09ad24u: goto P_0c09ad24;
case 0x0c09ad26u: goto P_0c09ad26;
case 0x0c09ad28u: goto P_0c09ad28;
case 0x0c09ad2au: goto P_0c09ad2a;
case 0x0c09ad2cu: goto P_0c09ad2c;
case 0x0c09ad2eu: goto P_0c09ad2e;
case 0x0c09ad30u: goto P_0c09ad30;
case 0x0c09ad32u: goto P_0c09ad32;
case 0x0c09ad34u: goto P_0c09ad34;
case 0x0c09ad36u: goto P_0c09ad36;
case 0x0c09ad38u: goto P_0c09ad38;
case 0x0c09ad3au: goto P_0c09ad3a;
case 0x0c09ad3cu: goto P_0c09ad3c;
case 0x0c09ad3eu: goto P_0c09ad3e;
case 0x0c09ad40u: goto P_0c09ad40;
case 0x0c09ad42u: goto P_0c09ad42;
case 0x0c09ad44u: goto P_0c09ad44;
case 0x0c09ad46u: goto P_0c09ad46;
case 0x0c09ad48u: goto P_0c09ad48;
case 0x0c09ad4au: goto P_0c09ad4a;
case 0x0c09ad4cu: goto P_0c09ad4c;
case 0x0c09ad4eu: goto P_0c09ad4e;
case 0x0c09ad50u: goto P_0c09ad50;
case 0x0c09ad52u: goto P_0c09ad52;
case 0x0c09ad54u: goto P_0c09ad54;
case 0x0c09ad56u: goto P_0c09ad56;
case 0x0c09ad58u: goto P_0c09ad58;
case 0x0c09ad5au: goto P_0c09ad5a;
case 0x0c09ad5cu: goto P_0c09ad5c;
case 0x0c09ad5eu: goto P_0c09ad5e;
case 0x0c09ad60u: goto P_0c09ad60;
case 0x0c09ad62u: goto P_0c09ad62;
case 0x0c09ad64u: goto P_0c09ad64;
case 0x0c09ad66u: goto P_0c09ad66;
case 0x0c09ad68u: goto P_0c09ad68;
case 0x0c09ad6au: goto P_0c09ad6a;
case 0x0c09ad6cu: goto P_0c09ad6c;
case 0x0c09ad6eu: goto P_0c09ad6e;
case 0x0c09ad70u: goto P_0c09ad70;
case 0x0c09ad72u: goto P_0c09ad72;
case 0x0c09ad74u: goto P_0c09ad74;
case 0x0c09ad76u: goto P_0c09ad76;
case 0x0c09ad78u: goto P_0c09ad78;
case 0x0c09ad7au: goto P_0c09ad7a;
case 0x0c09ade8u: goto P_0c09ade8;
case 0x0c09adeau: goto P_0c09adea;
case 0x0c09adecu: goto P_0c09adec;
case 0x0c09adeeu: goto P_0c09adee;
case 0x0c09adf0u: goto P_0c09adf0;
case 0x0c09adf2u: goto P_0c09adf2;
case 0x0c09adf4u: goto P_0c09adf4;
case 0x0c09adf6u: goto P_0c09adf6;
case 0x0c09adf8u: goto P_0c09adf8;
case 0x0c09adfau: goto P_0c09adfa;
case 0x0c09adfcu: goto P_0c09adfc;
case 0x0c09adfeu: goto P_0c09adfe;
case 0x0c09ae00u: goto P_0c09ae00;
case 0x0c09ae02u: goto P_0c09ae02;
case 0x0c09ae04u: goto P_0c09ae04;
case 0x0c09ae06u: goto P_0c09ae06;
case 0x0c09ae08u: goto P_0c09ae08;
case 0x0c09ae0au: goto P_0c09ae0a;
case 0x0c09ae0cu: goto P_0c09ae0c;
case 0x0c09ae0eu: goto P_0c09ae0e;
case 0x0c09ae10u: goto P_0c09ae10;
case 0x0c09ae12u: goto P_0c09ae12;
case 0x0c09ae14u: goto P_0c09ae14;
case 0x0c09ae16u: goto P_0c09ae16;
case 0x0c09ae18u: goto P_0c09ae18;
case 0x0c09ae1au: goto P_0c09ae1a;
case 0x0c09ae1cu: goto P_0c09ae1c;
case 0x0c09ae1eu: goto P_0c09ae1e;
case 0x0c09ae20u: goto P_0c09ae20;
case 0x0c09ae22u: goto P_0c09ae22;
case 0x0c09ae24u: goto P_0c09ae24;
case 0x0c09ae26u: goto P_0c09ae26;
case 0x0c09ae28u: goto P_0c09ae28;
case 0x0c09ae2au: goto P_0c09ae2a;
case 0x0c09ae2cu: goto P_0c09ae2c;
case 0x0c09ae2eu: goto P_0c09ae2e;
case 0x0c09ae30u: goto P_0c09ae30;
case 0x0c09ae32u: goto P_0c09ae32;
case 0x0c09ae34u: goto P_0c09ae34;
case 0x0c09ae36u: goto P_0c09ae36;
case 0x0c09ae38u: goto P_0c09ae38;
case 0x0c09ae3au: goto P_0c09ae3a;
case 0x0c09ae3cu: goto P_0c09ae3c;
case 0x0c09ae3eu: goto P_0c09ae3e;
case 0x0c09ae40u: goto P_0c09ae40;
case 0x0c09ae42u: goto P_0c09ae42;
case 0x0c09ae44u: goto P_0c09ae44;
case 0x0c09ae46u: goto P_0c09ae46;
case 0x0c09ae48u: goto P_0c09ae48;
case 0x0c09ae4au: goto P_0c09ae4a;
case 0x0c09ae4cu: goto P_0c09ae4c;
case 0x0c09ae4eu: goto P_0c09ae4e;
case 0x0c09ae50u: goto P_0c09ae50;
case 0x0c09ae52u: goto P_0c09ae52;
case 0x0c09ae54u: goto P_0c09ae54;
case 0x0c09ae56u: goto P_0c09ae56;
case 0x0c09ae58u: goto P_0c09ae58;
case 0x0c09ae5au: goto P_0c09ae5a;
case 0x0c09ae5cu: goto P_0c09ae5c;
case 0x0c09ae5eu: goto P_0c09ae5e;
case 0x0c09ae60u: goto P_0c09ae60;
case 0x0c09ae62u: goto P_0c09ae62;
case 0x0c09ae64u: goto P_0c09ae64;
case 0x0c09ae66u: goto P_0c09ae66;
case 0x0c09ae68u: goto P_0c09ae68;
case 0x0c09ae6au: goto P_0c09ae6a;
case 0x0c09ae6cu: goto P_0c09ae6c;
case 0x0c09ae6eu: goto P_0c09ae6e;
case 0x0c09ae70u: goto P_0c09ae70;
case 0x0c09ae72u: goto P_0c09ae72;
case 0x0c09ae74u: goto P_0c09ae74;
case 0x0c09ae76u: goto P_0c09ae76;
case 0x0c09ae78u: goto P_0c09ae78;
case 0x0c09ae7au: goto P_0c09ae7a;
case 0x0c09ae7cu: goto P_0c09ae7c;
case 0x0c09ae7eu: goto P_0c09ae7e;
case 0x0c09ae80u: goto P_0c09ae80;
case 0x0c09ae82u: goto P_0c09ae82;
case 0x0c09ae84u: goto P_0c09ae84;
case 0x0c09ae86u: goto P_0c09ae86;
case 0x0c09ae88u: goto P_0c09ae88;
case 0x0c09ae8au: goto P_0c09ae8a;
case 0x0c09ae8cu: goto P_0c09ae8c;
case 0x0c09ae8eu: goto P_0c09ae8e;
case 0x0c09ae90u: goto P_0c09ae90;
case 0x0c09ae92u: goto P_0c09ae92;
case 0x0c09ae94u: goto P_0c09ae94;
case 0x0c09ae96u: goto P_0c09ae96;
case 0x0c09ae98u: goto P_0c09ae98;
case 0x0c09ae9au: goto P_0c09ae9a;
case 0x0c09ae9cu: goto P_0c09ae9c;
case 0x0c09ae9eu: goto P_0c09ae9e;
case 0x0c09aea0u: goto P_0c09aea0;
case 0x0c09aea2u: goto P_0c09aea2;
case 0x0c09aea4u: goto P_0c09aea4;
case 0x0c09aea6u: goto P_0c09aea6;
case 0x0c09aea8u: goto P_0c09aea8;
case 0x0c09aeaau: goto P_0c09aeaa;
case 0x0c09aeacu: goto P_0c09aeac;
case 0x0c09aeaeu: goto P_0c09aeae;
case 0x0c09aeb0u: goto P_0c09aeb0;
case 0x0c09aeb2u: goto P_0c09aeb2;
case 0x0c09aeb4u: goto P_0c09aeb4;
case 0x0c09aeb6u: goto P_0c09aeb6;
case 0x0c09aeb8u: goto P_0c09aeb8;
case 0x0c09aebau: goto P_0c09aeba;
case 0x0c09aebcu: goto P_0c09aebc;
case 0x0c09aebeu: goto P_0c09aebe;
case 0x0c09aec0u: goto P_0c09aec0;
case 0x0c09aec2u: goto P_0c09aec2;
case 0x0c09aec4u: goto P_0c09aec4;
case 0x0c09aec6u: goto P_0c09aec6;
case 0x0c09aec8u: goto P_0c09aec8;
case 0x0c09aecau: goto P_0c09aeca;
case 0x0c09aeccu: goto P_0c09aecc;
case 0x0c09aeceu: goto P_0c09aece;
case 0x0c09aed0u: goto P_0c09aed0;
case 0x0c09aed2u: goto P_0c09aed2;
case 0x0c09aed4u: goto P_0c09aed4;
case 0x0c09aed6u: goto P_0c09aed6;
case 0x0c09aed8u: goto P_0c09aed8;
case 0x0c09aedau: goto P_0c09aeda;
case 0x0c09aedcu: goto P_0c09aedc;
case 0x0c09aedeu: goto P_0c09aede;
case 0x0c09aee0u: goto P_0c09aee0;
case 0x0c09aee2u: goto P_0c09aee2;
case 0x0c09aee4u: goto P_0c09aee4;
case 0x0c09aee6u: goto P_0c09aee6;
case 0x0c09aee8u: goto P_0c09aee8;
case 0x0c09aeeau: goto P_0c09aeea;
case 0x0c09aeecu: goto P_0c09aeec;
case 0x0c09aeeeu: goto P_0c09aeee;
case 0x0c09aef0u: goto P_0c09aef0;
case 0x0c09aef2u: goto P_0c09aef2;
case 0x0c09aef4u: goto P_0c09aef4;
case 0x0c09aef6u: goto P_0c09aef6;
case 0x0c09aef8u: goto P_0c09aef8;
case 0x0c09aefau: goto P_0c09aefa;
case 0x0c09aefcu: goto P_0c09aefc;
case 0x0c09aefeu: goto P_0c09aefe;
case 0x0c09af00u: goto P_0c09af00;
case 0x0c09af02u: goto P_0c09af02;
case 0x0c09af04u: goto P_0c09af04;
case 0x0c09af06u: goto P_0c09af06;
case 0x0c09af08u: goto P_0c09af08;
case 0x0c09af0au: goto P_0c09af0a;
case 0x0c09af0cu: goto P_0c09af0c;
case 0x0c09af0eu: goto P_0c09af0e;
case 0x0c09af10u: goto P_0c09af10;
case 0x0c09af12u: goto P_0c09af12;
case 0x0c09af14u: goto P_0c09af14;
case 0x0c09af16u: goto P_0c09af16;
case 0x0c09af18u: goto P_0c09af18;
case 0x0c09af1au: goto P_0c09af1a;
case 0x0c09af1cu: goto P_0c09af1c;
case 0x0c09af1eu: goto P_0c09af1e;
case 0x0c09af20u: goto P_0c09af20;
case 0x0c09af22u: goto P_0c09af22;
case 0x0c09af24u: goto P_0c09af24;
case 0x0c09af26u: goto P_0c09af26;
case 0x0c09af6cu: goto P_0c09af6c;
case 0x0c09af6eu: goto P_0c09af6e;
case 0x0c09af70u: goto P_0c09af70;
case 0x0c09af72u: goto P_0c09af72;
case 0x0c09af74u: goto P_0c09af74;
case 0x0c09af76u: goto P_0c09af76;
case 0x0c09af78u: goto P_0c09af78;
case 0x0c09af7au: goto P_0c09af7a;
case 0x0c09af7cu: goto P_0c09af7c;
case 0x0c09af7eu: goto P_0c09af7e;
case 0x0c09af80u: goto P_0c09af80;
case 0x0c09af82u: goto P_0c09af82;
case 0x0c09af84u: goto P_0c09af84;
case 0x0c09af86u: goto P_0c09af86;
case 0x0c09af88u: goto P_0c09af88;
case 0x0c09af8au: goto P_0c09af8a;
case 0x0c09af8cu: goto P_0c09af8c;
case 0x0c09af8eu: goto P_0c09af8e;
case 0x0c09af90u: goto P_0c09af90;
case 0x0c09af92u: goto P_0c09af92;
case 0x0c09af94u: goto P_0c09af94;
case 0x0c09af96u: goto P_0c09af96;
case 0x0c09af98u: goto P_0c09af98;
case 0x0c09af9au: goto P_0c09af9a;
case 0x0c09af9cu: goto P_0c09af9c;
case 0x0c09af9eu: goto P_0c09af9e;
case 0x0c09afa0u: goto P_0c09afa0;
case 0x0c09afa2u: goto P_0c09afa2;
case 0x0c09afa4u: goto P_0c09afa4;
case 0x0c09afa6u: goto P_0c09afa6;
case 0x0c09afa8u: goto P_0c09afa8;
case 0x0c09afaau: goto P_0c09afaa;
case 0x0c09afacu: goto P_0c09afac;
case 0x0c09afaeu: goto P_0c09afae;
case 0x0c09afb0u: goto P_0c09afb0;
case 0x0c09afb2u: goto P_0c09afb2;
case 0x0c09afb4u: goto P_0c09afb4;
case 0x0c09afb6u: goto P_0c09afb6;
case 0x0c09afb8u: goto P_0c09afb8;
case 0x0c09afbau: goto P_0c09afba;
case 0x0c09afbcu: goto P_0c09afbc;
case 0x0c09afbeu: goto P_0c09afbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b0f4: /* original 2fe6, guest PC 0x0c07b0f4 */
if(!s->budget--) { s->failed_pc=0x0c07b0f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f6;
P_0c07b0f6: /* original 2fd6, guest PC 0x0c07b0f6 */
if(!s->budget--) { s->failed_pc=0x0c07b0f6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f8;
P_0c07b0f8: /* original 2fc6, guest PC 0x0c07b0f8 */
if(!s->budget--) { s->failed_pc=0x0c07b0f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fa;
P_0c07b0fa: /* original 2fb6, guest PC 0x0c07b0fa */
if(!s->budget--) { s->failed_pc=0x0c07b0fau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fc;
P_0c07b0fc: /* original 2fa6, guest PC 0x0c07b0fc */
if(!s->budget--) { s->failed_pc=0x0c07b0fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fe;
P_0c07b0fe: /* original 2f96, guest PC 0x0c07b0fe */
if(!s->budget--) { s->failed_pc=0x0c07b0feu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b100;
P_0c07b100: /* original de35, guest PC 0x0c07b100 */
if(!s->budget--) { s->failed_pc=0x0c07b100u; return 0; }
r[14]=read(ram,0x0c07b1d8u,4);
goto P_0c07b102;
P_0c07b102: /* original 4f22, guest PC 0x0c07b102 */
if(!s->budget--) { s->failed_pc=0x0c07b102u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b104;
P_0c07b104: /* original d933, guest PC 0x0c07b104 */
if(!s->budget--) { s->failed_pc=0x0c07b104u; return 0; }
r[9]=read(ram,0x0c07b1d4u,4);
goto P_0c07b106;
P_0c07b106: /* original d335, guest PC 0x0c07b106 */
if(!s->budget--) { s->failed_pc=0x0c07b106u; return 0; }
r[3]=read(ram,0x0c07b1dcu,4);
goto P_0c07b108;
P_0c07b108: /* original 7ffc, guest PC 0x0c07b108 */
if(!s->budget--) { s->failed_pc=0x0c07b108u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b10a;
P_0c07b10a: /* original 6b92, guest PC 0x0c07b10a */
if(!s->budget--) { s->failed_pc=0x0c07b10au; return 0; }
tmp=read(ram,r[9],4);
r[11]=tmp;
goto P_0c07b10c;
P_0c07b10c: /* original 2f32, guest PC 0x0c07b10c */
if(!s->budget--) { s->failed_pc=0x0c07b10cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07b10e;
P_0c07b10e: /* original 905f, guest PC 0x0c07b10e */
if(!s->budget--) { s->failed_pc=0x0c07b10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b110;
P_0c07b110: /* original 02ed, guest PC 0x0c07b110 */
if(!s->budget--) { s->failed_pc=0x0c07b110u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b112;
P_0c07b112: /* original 4211, guest PC 0x0c07b112 */
if(!s->budget--) { s->failed_pc=0x0c07b112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c07b114;
P_0c07b114: /* original 8f0f, guest PC 0x0c07b114 */
if(!s->budget--) { s->failed_pc=0x0c07b114u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c07b136; }
goto P_0c07b118;
P_0c07b116: /* original 6c43, guest PC 0x0c07b116 */
if(!s->budget--) { s->failed_pc=0x0c07b116u; return 0; }
r[12]=r[4];
goto P_0c07b118;
P_0c07b118: /* original b24a, guest PC 0x0c07b118 */
if(!s->budget--) { s->failed_pc=0x0c07b118u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b11cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b11cu) { target=s->pc; goto dispatch; }
goto P_0c07b11c;
P_0c07b11a: /* original 04ed, guest PC 0x0c07b11a */
if(!s->budget--) { s->failed_pc=0x0c07b11au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b11c;
P_0c07b11c: /* original 6d03, guest PC 0x0c07b11c */
if(!s->budget--) { s->failed_pc=0x0c07b11cu; return 0; }
r[13]=r[0];
goto P_0c07b11e;
P_0c07b11e: /* original b267, guest PC 0x0c07b11e */
if(!s->budget--) { s->failed_pc=0x0c07b11eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b122u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b122u) { target=s->pc; goto dispatch; }
goto P_0c07b122;
P_0c07b120: /* original 6403, guest PC 0x0c07b120 */
if(!s->budget--) { s->failed_pc=0x0c07b120u; return 0; }
r[4]=r[0];
goto P_0c07b122;
P_0c07b122: /* original 64dd, guest PC 0x0c07b122 */
if(!s->budget--) { s->failed_pc=0x0c07b122u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b124;
P_0c07b124: /* original 6043, guest PC 0x0c07b124 */
if(!s->budget--) { s->failed_pc=0x0c07b124u; return 0; }
r[0]=r[4];
goto P_0c07b126;
P_0c07b126: /* original 882c, guest PC 0x0c07b126 */
if(!s->budget--) { s->failed_pc=0x0c07b126u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b128;
P_0c07b128: /* original 8902, guest PC 0x0c07b128 */
if(!s->budget--) { s->failed_pc=0x0c07b128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b130; }
goto P_0c07b12a;
P_0c07b12a: /* original 6043, guest PC 0x0c07b12a */
if(!s->budget--) { s->failed_pc=0x0c07b12au; return 0; }
r[0]=r[4];
goto P_0c07b12c;
P_0c07b12c: /* original 8834, guest PC 0x0c07b12c */
if(!s->budget--) { s->failed_pc=0x0c07b12cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b12e;
P_0c07b12e: /* original 8b02, guest PC 0x0c07b12e */
if(!s->budget--) { s->failed_pc=0x0c07b12eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b136; }
goto P_0c07b130;
P_0c07b130: /* original 64d3, guest PC 0x0c07b130 */
if(!s->budget--) { s->failed_pc=0x0c07b130u; return 0; }
r[4]=r[13];
goto P_0c07b132;
P_0c07b132: /* original b25d, guest PC 0x0c07b132 */
if(!s->budget--) { s->failed_pc=0x0c07b132u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b136u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b136u) { target=s->pc; goto dispatch; }
goto P_0c07b136;
P_0c07b134: /* original 7401, guest PC 0x0c07b134 */
if(!s->budget--) { s->failed_pc=0x0c07b134u; return 0; }
r[4]+=0x00000001u;
goto P_0c07b136;
P_0c07b136: /* original 904b, guest PC 0x0c07b136 */
if(!s->budget--) { s->failed_pc=0x0c07b136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b138;
P_0c07b138: /* original e2ff, guest PC 0x0c07b138 */
if(!s->budget--) { s->failed_pc=0x0c07b138u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b13a;
P_0c07b13a: /* original 0e25, guest PC 0x0c07b13a */
if(!s->budget--) { s->failed_pc=0x0c07b13au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b13c;
P_0c07b13c: /* original d227, guest PC 0x0c07b13c */
if(!s->budget--) { s->failed_pc=0x0c07b13cu; return 0; }
r[2]=read(ram,0x0c07b1dcu,4);
goto P_0c07b13e;
P_0c07b13e: /* original d328, guest PC 0x0c07b13e */
if(!s->budget--) { s->failed_pc=0x0c07b13eu; return 0; }
r[3]=read(ram,0x0c07b1e0u,4);
goto P_0c07b140;
P_0c07b140: /* original 6122, guest PC 0x0c07b140 */
if(!s->budget--) { s->failed_pc=0x0c07b140u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07b142;
P_0c07b142: /* original 2138, guest PC 0x0c07b142 */
if(!s->budget--) { s->failed_pc=0x0c07b142u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07b144;
P_0c07b144: /* original 8b37, guest PC 0x0c07b144 */
if(!s->budget--) { s->failed_pc=0x0c07b144u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1b6; }
goto P_0c07b146;
P_0c07b146: /* original d227, guest PC 0x0c07b146 */
if(!s->budget--) { s->failed_pc=0x0c07b146u; return 0; }
r[2]=read(ram,0x0c07b1e4u,4);
goto P_0c07b148;
P_0c07b148: /* original 63cd, guest PC 0x0c07b148 */
if(!s->budget--) { s->failed_pc=0x0c07b148u; return 0; }
r[3]=r[12]&65535u;
goto P_0c07b14a;
P_0c07b14a: /* original 9041, guest PC 0x0c07b14a */
if(!s->budget--) { s->failed_pc=0x0c07b14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b14c;
P_0c07b14c: /* original 3320, guest PC 0x0c07b14c */
if(!s->budget--) { s->failed_pc=0x0c07b14cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b14e;
P_0c07b14e: /* original 8d32, guest PC 0x0c07b14e */
if(!s->budget--) { s->failed_pc=0x0c07b14eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[12],2);
if(cond) { goto P_0c07b1b6; }
goto P_0c07b152;
P_0c07b150: /* original 0ec5, guest PC 0x0c07b150 */
if(!s->budget--) { s->failed_pc=0x0c07b150u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c07b152;
P_0c07b152: /* original b22d, guest PC 0x0c07b152 */
if(!s->budget--) { s->failed_pc=0x0c07b152u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b156u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b156u) { target=s->pc; goto dispatch; }
goto P_0c07b156;
P_0c07b154: /* original 64c3, guest PC 0x0c07b154 */
if(!s->budget--) { s->failed_pc=0x0c07b154u; return 0; }
r[4]=r[12];
goto P_0c07b156;
P_0c07b156: /* original 6d03, guest PC 0x0c07b156 */
if(!s->budget--) { s->failed_pc=0x0c07b156u; return 0; }
r[13]=r[0];
goto P_0c07b158;
P_0c07b158: /* original 6cdd, guest PC 0x0c07b158 */
if(!s->budget--) { s->failed_pc=0x0c07b158u; return 0; }
r[12]=r[13]&65535u;
goto P_0c07b15a;
P_0c07b15a: /* original d023, guest PC 0x0c07b15a */
if(!s->budget--) { s->failed_pc=0x0c07b15au; return 0; }
r[0]=read(ram,0x0c07b1e8u,4);
goto P_0c07b15c;
P_0c07b15c: /* original 62c3, guest PC 0x0c07b15c */
if(!s->budget--) { s->failed_pc=0x0c07b15cu; return 0; }
r[2]=r[12];
goto P_0c07b15e;
P_0c07b15e: /* original 72db, guest PC 0x0c07b15e */
if(!s->budget--) { s->failed_pc=0x0c07b15eu; return 0; }
r[2]+=0xffffffdbu;
goto P_0c07b160;
P_0c07b160: /* original 032c, guest PC 0x0c07b160 */
if(!s->budget--) { s->failed_pc=0x0c07b160u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07b162;
P_0c07b162: /* original 2338, guest PC 0x0c07b162 */
if(!s->budget--) { s->failed_pc=0x0c07b162u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07b164;
P_0c07b164: /* original 892b, guest PC 0x0c07b164 */
if(!s->budget--) { s->failed_pc=0x0c07b164u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b1be; }
goto P_0c07b166;
P_0c07b166: /* original d321, guest PC 0x0c07b166 */
if(!s->budget--) { s->failed_pc=0x0c07b166u; return 0; }
r[3]=read(ram,0x0c07b1ecu,4);
goto P_0c07b168;
P_0c07b168: /* original 64c3, guest PC 0x0c07b168 */
if(!s->budget--) { s->failed_pc=0x0c07b168u; return 0; }
r[4]=r[12];
goto P_0c07b16a;
P_0c07b16a: /* original 65b3, guest PC 0x0c07b16a */
if(!s->budget--) { s->failed_pc=0x0c07b16au; return 0; }
r[5]=r[11];
goto P_0c07b16c;
P_0c07b16c: /* original 74db, guest PC 0x0c07b16c */
if(!s->budget--) { s->failed_pc=0x0c07b16cu; return 0; }
r[4]+=0xffffffdbu;
goto P_0c07b16e;
P_0c07b16e: /* original 430b, guest PC 0x0c07b16e */
if(!s->budget--) { s->failed_pc=0x0c07b16eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b172u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b172u) { target=s->pc; goto dispatch; }
goto P_0c07b172;
P_0c07b170: /* original 044c, guest PC 0x0c07b170 */
if(!s->budget--) { s->failed_pc=0x0c07b170u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07b172;
P_0c07b172: /* original 6edd, guest PC 0x0c07b172 */
if(!s->budget--) { s->failed_pc=0x0c07b172u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b174;
P_0c07b174: /* original da1e, guest PC 0x0c07b174 */
if(!s->budget--) { s->failed_pc=0x0c07b174u; return 0; }
r[10]=read(ram,0x0c07b1f0u,4);
goto P_0c07b176;
P_0c07b176: /* original 60e3, guest PC 0x0c07b176 */
if(!s->budget--) { s->failed_pc=0x0c07b176u; return 0; }
r[0]=r[14];
goto P_0c07b178;
P_0c07b178: /* original 882c, guest PC 0x0c07b178 */
if(!s->budget--) { s->failed_pc=0x0c07b178u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b17a;
P_0c07b17a: /* original 8b04, guest PC 0x0c07b17a */
if(!s->budget--) { s->failed_pc=0x0c07b17au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b186; }
goto P_0c07b17c;
P_0c07b17c: /* original 4a0b, guest PC 0x0c07b17c */
if(!s->budget--) { s->failed_pc=0x0c07b17cu; return 0; }
target=r[10];
r[16]=code_base|0x0c07b180u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b180u) { target=s->pc; goto dispatch; }
goto P_0c07b180;
P_0c07b17e: /* original 64e3, guest PC 0x0c07b17e */
if(!s->budget--) { s->failed_pc=0x0c07b17eu; return 0; }
r[4]=r[14];
goto P_0c07b180;
P_0c07b180: /* original d41c, guest PC 0x0c07b180 */
if(!s->budget--) { s->failed_pc=0x0c07b180u; return 0; }
r[4]=read(ram,0x0c07b1f4u,4);
goto P_0c07b182;
P_0c07b182: /* original a006, guest PC 0x0c07b182 */
if(!s->budget--) { s->failed_pc=0x0c07b182u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b184: /* original 6592, guest PC 0x0c07b184 */
if(!s->budget--) { s->failed_pc=0x0c07b184u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b186;
P_0c07b186: /* original 8834, guest PC 0x0c07b186 */
if(!s->budget--) { s->failed_pc=0x0c07b186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b188;
P_0c07b188: /* original 8b0c, guest PC 0x0c07b188 */
if(!s->budget--) { s->failed_pc=0x0c07b188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1a4; }
goto P_0c07b18a;
P_0c07b18a: /* original 4a0b, guest PC 0x0c07b18a */
if(!s->budget--) { s->failed_pc=0x0c07b18au; return 0; }
target=r[10];
r[16]=code_base|0x0c07b18eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b18eu) { target=s->pc; goto dispatch; }
goto P_0c07b18e;
P_0c07b18c: /* original 64e3, guest PC 0x0c07b18c */
if(!s->budget--) { s->failed_pc=0x0c07b18cu; return 0; }
r[4]=r[14];
goto P_0c07b18e;
P_0c07b18e: /* original d41a, guest PC 0x0c07b18e */
if(!s->budget--) { s->failed_pc=0x0c07b18eu; return 0; }
r[4]=read(ram,0x0c07b1f8u,4);
goto P_0c07b190;
P_0c07b190: /* original 6592, guest PC 0x0c07b190 */
if(!s->budget--) { s->failed_pc=0x0c07b190u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b192: /* original bb38, guest PC 0x0c07b192 */
if(!s->budget--) { s->failed_pc=0x0c07b192u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07b196u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b196u) { target=s->pc; goto dispatch; }
goto P_0c07b196;
P_0c07b194: /* original 0009, guest PC 0x0c07b194 */
if(!s->budget--) { s->failed_pc=0x0c07b194u; return 0; }
goto P_0c07b196;
P_0c07b196: /* original d019, guest PC 0x0c07b196 */
if(!s->budget--) { s->failed_pc=0x0c07b196u; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b198;
P_0c07b198: /* original 62e3, guest PC 0x0c07b198 */
if(!s->budget--) { s->failed_pc=0x0c07b198u; return 0; }
r[2]=r[14];
goto P_0c07b19a;
P_0c07b19a: /* original 7c01, guest PC 0x0c07b19a */
if(!s->budget--) { s->failed_pc=0x0c07b19au; return 0; }
r[12]+=0x00000001u;
goto P_0c07b19c;
P_0c07b19c: /* original 7201, guest PC 0x0c07b19c */
if(!s->budget--) { s->failed_pc=0x0c07b19cu; return 0; }
r[2]+=0x00000001u;
goto P_0c07b19e;
P_0c07b19e: /* original 4c00, guest PC 0x0c07b19e */
if(!s->budget--) { s->failed_pc=0x0c07b19eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c07b1a0;
P_0c07b1a0: /* original a005, guest PC 0x0c07b1a0 */
if(!s->budget--) { s->failed_pc=0x0c07b1a0u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1ae;
P_0c07b1a2: /* original 0c25, guest PC 0x0c07b1a2 */
if(!s->budget--) { s->failed_pc=0x0c07b1a2u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1a4;
P_0c07b1a4: /* original 4a0b, guest PC 0x0c07b1a4 */
if(!s->budget--) { s->failed_pc=0x0c07b1a4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07b1a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1a8u) { target=s->pc; goto dispatch; }
goto P_0c07b1a8;
P_0c07b1a6: /* original 64e3, guest PC 0x0c07b1a6 */
if(!s->budget--) { s->failed_pc=0x0c07b1a6u; return 0; }
r[4]=r[14];
goto P_0c07b1a8;
P_0c07b1a8: /* original d415, guest PC 0x0c07b1a8 */
if(!s->budget--) { s->failed_pc=0x0c07b1a8u; return 0; }
r[4]=read(ram,0x0c07b200u,4);
goto P_0c07b1aa;
P_0c07b1aa: /* original bb1d, guest PC 0x0c07b1aa */
if(!s->budget--) { s->failed_pc=0x0c07b1aau; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b1aeu;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1aeu) { target=s->pc; goto dispatch; }
goto P_0c07b1ae;
P_0c07b1ac: /* original 65b3, guest PC 0x0c07b1ac */
if(!s->budget--) { s->failed_pc=0x0c07b1acu; return 0; }
r[5]=r[11];
goto P_0c07b1ae;
P_0c07b1ae: /* original d013, guest PC 0x0c07b1ae */
if(!s->budget--) { s->failed_pc=0x0c07b1aeu; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b1b0;
P_0c07b1b0: /* original 6ddd, guest PC 0x0c07b1b0 */
if(!s->budget--) { s->failed_pc=0x0c07b1b0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b1b2;
P_0c07b1b2: /* original 4d00, guest PC 0x0c07b1b2 */
if(!s->budget--) { s->failed_pc=0x0c07b1b2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b1b4;
P_0c07b1b4: /* original 0de5, guest PC 0x0c07b1b4 */
if(!s->budget--) { s->failed_pc=0x0c07b1b4u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c07b1b6;
P_0c07b1b6: /* original 900c, guest PC 0x0c07b1b6 */
if(!s->budget--) { s->failed_pc=0x0c07b1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d2u,2);
goto P_0c07b1b8;
P_0c07b1b8: /* original e2ff, guest PC 0x0c07b1b8 */
if(!s->budget--) { s->failed_pc=0x0c07b1b8u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b1ba;
P_0c07b1ba: /* original 63f2, guest PC 0x0c07b1ba */
if(!s->budget--) { s->failed_pc=0x0c07b1bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07b1bc;
P_0c07b1bc: /* original 0326, guest PC 0x0c07b1bc */
if(!s->budget--) { s->failed_pc=0x0c07b1bcu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c07b1be;
P_0c07b1be: /* original 7f04, guest PC 0x0c07b1be */
if(!s->budget--) { s->failed_pc=0x0c07b1beu; return 0; }
r[15]+=0x00000004u;
goto P_0c07b1c0;
P_0c07b1c0: /* original 4f26, guest PC 0x0c07b1c0 */
if(!s->budget--) { s->failed_pc=0x0c07b1c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b1c2;
P_0c07b1c2: /* original 69f6, guest PC 0x0c07b1c2 */
if(!s->budget--) { s->failed_pc=0x0c07b1c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07b1c4;
P_0c07b1c4: /* original 6af6, guest PC 0x0c07b1c4 */
if(!s->budget--) { s->failed_pc=0x0c07b1c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b1c6;
P_0c07b1c6: /* original 6bf6, guest PC 0x0c07b1c6 */
if(!s->budget--) { s->failed_pc=0x0c07b1c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b1c8;
P_0c07b1c8: /* original 6cf6, guest PC 0x0c07b1c8 */
if(!s->budget--) { s->failed_pc=0x0c07b1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b1ca;
P_0c07b1ca: /* original 6df6, guest PC 0x0c07b1ca */
if(!s->budget--) { s->failed_pc=0x0c07b1cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b1cc;
P_0c07b1cc: /* original 000b, guest PC 0x0c07b1cc */
if(!s->budget--) { s->failed_pc=0x0c07b1ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b1ce: /* original 6ef6, guest PC 0x0c07b1ce */
if(!s->budget--) { s->failed_pc=0x0c07b1ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b1d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b1d0u; return 0; } return 1;
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
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
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
P_0c09ac14: /* original 2fe6, guest PC 0x0c09ac14 */
if(!s->budget--) { s->failed_pc=0x0c09ac14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ac16;
P_0c09ac16: /* original e600, guest PC 0x0c09ac16 */
if(!s->budget--) { s->failed_pc=0x0c09ac16u; return 0; }
r[6]=0x00000000u;
goto P_0c09ac18;
P_0c09ac18: /* original 2fd6, guest PC 0x0c09ac18 */
if(!s->budget--) { s->failed_pc=0x0c09ac18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ac1a;
P_0c09ac1a: /* original 6563, guest PC 0x0c09ac1a */
if(!s->budget--) { s->failed_pc=0x0c09ac1au; return 0; }
r[5]=r[6];
goto P_0c09ac1c;
P_0c09ac1c: /* original 2fc6, guest PC 0x0c09ac1c */
if(!s->budget--) { s->failed_pc=0x0c09ac1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ac1e;
P_0c09ac1e: /* original 2fb6, guest PC 0x0c09ac1e */
if(!s->budget--) { s->failed_pc=0x0c09ac1eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ac20;
P_0c09ac20: /* original fffb, guest PC 0x0c09ac20 */
if(!s->budget--) { s->failed_pc=0x0c09ac20u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09ac22;
P_0c09ac22: /* original 4f22, guest PC 0x0c09ac22 */
if(!s->budget--) { s->failed_pc=0x0c09ac22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ac24;
P_0c09ac24: /* original d35c, guest PC 0x0c09ac24 */
if(!s->budget--) { s->failed_pc=0x0c09ac24u; return 0; }
r[3]=read(ram,0x0c09ad98u,4);
goto P_0c09ac26;
P_0c09ac26: /* original dd5a, guest PC 0x0c09ac26 */
if(!s->budget--) { s->failed_pc=0x0c09ac26u; return 0; }
r[13]=read(ram,0x0c09ad90u,4);
goto P_0c09ac28;
P_0c09ac28: /* original de5a, guest PC 0x0c09ac28 */
if(!s->budget--) { s->failed_pc=0x0c09ac28u; return 0; }
r[14]=read(ram,0x0c09ad94u,4);
goto P_0c09ac2a;
P_0c09ac2a: /* original 430b, guest PC 0x0c09ac2a */
if(!s->budget--) { s->failed_pc=0x0c09ac2au; return 0; }
target=r[3];
r[16]=code_base|0x0c09ac2eu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac2eu) { target=s->pc; goto dispatch; }
goto P_0c09ac2e;
P_0c09ac2c: /* original 6463, guest PC 0x0c09ac2c */
if(!s->budget--) { s->failed_pc=0x0c09ac2cu; return 0; }
r[4]=r[6];
goto P_0c09ac2e;
P_0c09ac2e: /* original e600, guest PC 0x0c09ac2e */
if(!s->budget--) { s->failed_pc=0x0c09ac2eu; return 0; }
r[6]=0x00000000u;
goto P_0c09ac30;
P_0c09ac30: /* original ff8d, guest PC 0x0c09ac30 */
if(!s->budget--) { s->failed_pc=0x0c09ac30u; return 0; }
fr[15]=0;
goto P_0c09ac32;
P_0c09ac32: /* original dc5a, guest PC 0x0c09ac32 */
if(!s->budget--) { s->failed_pc=0x0c09ac32u; return 0; }
r[12]=read(ram,0x0c09ad9cu,4);
goto P_0c09ac34;
P_0c09ac34: /* original 6563, guest PC 0x0c09ac34 */
if(!s->budget--) { s->failed_pc=0x0c09ac34u; return 0; }
r[5]=r[6];
goto P_0c09ac36;
P_0c09ac36: /* original f5fc, guest PC 0x0c09ac36 */
if(!s->budget--) { s->failed_pc=0x0c09ac36u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09ac38;
P_0c09ac38: /* original f4fc, guest PC 0x0c09ac38 */
if(!s->budget--) { s->failed_pc=0x0c09ac38u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09ac3a;
P_0c09ac3a: /* original 4c0b, guest PC 0x0c09ac3a */
if(!s->budget--) { s->failed_pc=0x0c09ac3au; return 0; }
target=r[12];
r[16]=code_base|0x0c09ac3eu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac3eu) { target=s->pc; goto dispatch; }
goto P_0c09ac3e;
P_0c09ac3c: /* original 6463, guest PC 0x0c09ac3c */
if(!s->budget--) { s->failed_pc=0x0c09ac3cu; return 0; }
r[4]=r[6];
goto P_0c09ac3e;
P_0c09ac3e: /* original d258, guest PC 0x0c09ac3e */
if(!s->budget--) { s->failed_pc=0x0c09ac3eu; return 0; }
r[2]=read(ram,0x0c09ada0u,4);
goto P_0c09ac40;
P_0c09ac40: /* original 420b, guest PC 0x0c09ac40 */
if(!s->budget--) { s->failed_pc=0x0c09ac40u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ac44u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac44u) { target=s->pc; goto dispatch; }
goto P_0c09ac44;
P_0c09ac42: /* original 0009, guest PC 0x0c09ac42 */
if(!s->budget--) { s->failed_pc=0x0c09ac42u; return 0; }
goto P_0c09ac44;
P_0c09ac44: /* original d357, guest PC 0x0c09ac44 */
if(!s->budget--) { s->failed_pc=0x0c09ac44u; return 0; }
r[3]=read(ram,0x0c09ada4u,4);
goto P_0c09ac46;
P_0c09ac46: /* original 430b, guest PC 0x0c09ac46 */
if(!s->budget--) { s->failed_pc=0x0c09ac46u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ac4au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac4au) { target=s->pc; goto dispatch; }
goto P_0c09ac4a;
P_0c09ac48: /* original 0009, guest PC 0x0c09ac48 */
if(!s->budget--) { s->failed_pc=0x0c09ac48u; return 0; }
goto P_0c09ac4a;
P_0c09ac4a: /* original d257, guest PC 0x0c09ac4a */
if(!s->budget--) { s->failed_pc=0x0c09ac4au; return 0; }
r[2]=read(ram,0x0c09ada8u,4);
goto P_0c09ac4c;
P_0c09ac4c: /* original 420b, guest PC 0x0c09ac4c */
if(!s->budget--) { s->failed_pc=0x0c09ac4cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09ac50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac50u) { target=s->pc; goto dispatch; }
goto P_0c09ac50;
P_0c09ac4e: /* original 0009, guest PC 0x0c09ac4e */
if(!s->budget--) { s->failed_pc=0x0c09ac4eu; return 0; }
goto P_0c09ac50;
P_0c09ac50: /* original d357, guest PC 0x0c09ac50 */
if(!s->budget--) { s->failed_pc=0x0c09ac50u; return 0; }
r[3]=read(ram,0x0c09adb0u,4);
goto P_0c09ac52;
P_0c09ac52: /* original d456, guest PC 0x0c09ac52 */
if(!s->budget--) { s->failed_pc=0x0c09ac52u; return 0; }
r[4]=read(ram,0x0c09adacu,4);
goto P_0c09ac54;
P_0c09ac54: /* original 430b, guest PC 0x0c09ac54 */
if(!s->budget--) { s->failed_pc=0x0c09ac54u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ac58u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac58u) { target=s->pc; goto dispatch; }
goto P_0c09ac58;
P_0c09ac56: /* original 0009, guest PC 0x0c09ac56 */
if(!s->budget--) { s->failed_pc=0x0c09ac56u; return 0; }
goto P_0c09ac58;
P_0c09ac58: /* original d256, guest PC 0x0c09ac58 */
if(!s->budget--) { s->failed_pc=0x0c09ac58u; return 0; }
r[2]=read(ram,0x0c09adb4u,4);
goto P_0c09ac5a;
P_0c09ac5a: /* original 420b, guest PC 0x0c09ac5a */
if(!s->budget--) { s->failed_pc=0x0c09ac5au; return 0; }
target=r[2];
r[16]=code_base|0x0c09ac5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac5eu) { target=s->pc; goto dispatch; }
goto P_0c09ac5e;
P_0c09ac5c: /* original 0009, guest PC 0x0c09ac5c */
if(!s->budget--) { s->failed_pc=0x0c09ac5cu; return 0; }
goto P_0c09ac5e;
P_0c09ac5e: /* original d356, guest PC 0x0c09ac5e */
if(!s->budget--) { s->failed_pc=0x0c09ac5eu; return 0; }
r[3]=read(ram,0x0c09adb8u,4);
goto P_0c09ac60;
P_0c09ac60: /* original 430b, guest PC 0x0c09ac60 */
if(!s->budget--) { s->failed_pc=0x0c09ac60u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ac64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac64u) { target=s->pc; goto dispatch; }
goto P_0c09ac64;
P_0c09ac62: /* original 0009, guest PC 0x0c09ac62 */
if(!s->budget--) { s->failed_pc=0x0c09ac62u; return 0; }
goto P_0c09ac64;
P_0c09ac64: /* original d255, guest PC 0x0c09ac64 */
if(!s->budget--) { s->failed_pc=0x0c09ac64u; return 0; }
r[2]=read(ram,0x0c09adbcu,4);
goto P_0c09ac66;
P_0c09ac66: /* original 420b, guest PC 0x0c09ac66 */
if(!s->budget--) { s->failed_pc=0x0c09ac66u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ac6au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac6au) { target=s->pc; goto dispatch; }
goto P_0c09ac6a;
P_0c09ac68: /* original 0009, guest PC 0x0c09ac68 */
if(!s->budget--) { s->failed_pc=0x0c09ac68u; return 0; }
goto P_0c09ac6a;
P_0c09ac6a: /* original db55, guest PC 0x0c09ac6a */
if(!s->budget--) { s->failed_pc=0x0c09ac6au; return 0; }
r[11]=read(ram,0x0c09adc0u,4);
goto P_0c09ac6c;
P_0c09ac6c: /* original 4b0b, guest PC 0x0c09ac6c */
if(!s->budget--) { s->failed_pc=0x0c09ac6cu; return 0; }
target=r[11];
r[16]=code_base|0x0c09ac70u;
r[4]=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac70u) { target=s->pc; goto dispatch; }
goto P_0c09ac70;
P_0c09ac6e: /* original e414, guest PC 0x0c09ac6e */
if(!s->budget--) { s->failed_pc=0x0c09ac6eu; return 0; }
r[4]=0x00000014u;
goto P_0c09ac70;
P_0c09ac70: /* original 4b0b, guest PC 0x0c09ac70 */
if(!s->budget--) { s->failed_pc=0x0c09ac70u; return 0; }
target=r[11];
r[16]=code_base|0x0c09ac74u;
r[4]=0x00000016u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac74u) { target=s->pc; goto dispatch; }
goto P_0c09ac74;
P_0c09ac72: /* original e416, guest PC 0x0c09ac72 */
if(!s->budget--) { s->failed_pc=0x0c09ac72u; return 0; }
r[4]=0x00000016u;
goto P_0c09ac74;
P_0c09ac74: /* original 4b0b, guest PC 0x0c09ac74 */
if(!s->budget--) { s->failed_pc=0x0c09ac74u; return 0; }
target=r[11];
r[16]=code_base|0x0c09ac78u;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac78u) { target=s->pc; goto dispatch; }
goto P_0c09ac78;
P_0c09ac76: /* original e40f, guest PC 0x0c09ac76 */
if(!s->budget--) { s->failed_pc=0x0c09ac76u; return 0; }
r[4]=0x0000000fu;
goto P_0c09ac78;
P_0c09ac78: /* original c752, guest PC 0x0c09ac78 */
if(!s->budget--) { s->failed_pc=0x0c09ac78u; return 0; }
r[0]=code_base|0x0009adc4u;
goto P_0c09ac7a;
P_0c09ac7a: /* original f5fc, guest PC 0x0c09ac7a */
if(!s->budget--) { s->failed_pc=0x0c09ac7au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09ac7c;
P_0c09ac7c: /* original e600, guest PC 0x0c09ac7c */
if(!s->budget--) { s->failed_pc=0x0c09ac7cu; return 0; }
r[6]=0x00000000u;
goto P_0c09ac7e;
P_0c09ac7e: /* original f408, guest PC 0x0c09ac7e */
if(!s->budget--) { s->failed_pc=0x0c09ac7eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09ac80;
P_0c09ac80: /* original 6563, guest PC 0x0c09ac80 */
if(!s->budget--) { s->failed_pc=0x0c09ac80u; return 0; }
r[5]=r[6];
goto P_0c09ac82;
P_0c09ac82: /* original 4c0b, guest PC 0x0c09ac82 */
if(!s->budget--) { s->failed_pc=0x0c09ac82u; return 0; }
target=r[12];
r[16]=code_base|0x0c09ac86u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac86u) { target=s->pc; goto dispatch; }
goto P_0c09ac86;
P_0c09ac84: /* original 6463, guest PC 0x0c09ac84 */
if(!s->budget--) { s->failed_pc=0x0c09ac84u; return 0; }
r[4]=r[6];
goto P_0c09ac86;
P_0c09ac86: /* original c750, guest PC 0x0c09ac86 */
if(!s->budget--) { s->failed_pc=0x0c09ac86u; return 0; }
r[0]=code_base|0x0009adc8u;
goto P_0c09ac88;
P_0c09ac88: /* original f5fc, guest PC 0x0c09ac88 */
if(!s->budget--) { s->failed_pc=0x0c09ac88u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09ac8a;
P_0c09ac8a: /* original e600, guest PC 0x0c09ac8a */
if(!s->budget--) { s->failed_pc=0x0c09ac8au; return 0; }
r[6]=0x00000000u;
goto P_0c09ac8c;
P_0c09ac8c: /* original f408, guest PC 0x0c09ac8c */
if(!s->budget--) { s->failed_pc=0x0c09ac8cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09ac8e;
P_0c09ac8e: /* original 6563, guest PC 0x0c09ac8e */
if(!s->budget--) { s->failed_pc=0x0c09ac8eu; return 0; }
r[5]=r[6];
goto P_0c09ac90;
P_0c09ac90: /* original 4c0b, guest PC 0x0c09ac90 */
if(!s->budget--) { s->failed_pc=0x0c09ac90u; return 0; }
target=r[12];
r[16]=code_base|0x0c09ac94u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac94u) { target=s->pc; goto dispatch; }
goto P_0c09ac94;
P_0c09ac92: /* original 6463, guest PC 0x0c09ac92 */
if(!s->budget--) { s->failed_pc=0x0c09ac92u; return 0; }
r[4]=r[6];
goto P_0c09ac94;
P_0c09ac94: /* original d34d, guest PC 0x0c09ac94 */
if(!s->budget--) { s->failed_pc=0x0c09ac94u; return 0; }
r[3]=read(ram,0x0c09adccu,4);
goto P_0c09ac96;
P_0c09ac96: /* original 430b, guest PC 0x0c09ac96 */
if(!s->budget--) { s->failed_pc=0x0c09ac96u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ac9au;
r[4]=0xffffffffu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ac9au) { target=s->pc; goto dispatch; }
goto P_0c09ac9a;
P_0c09ac98: /* original e4ff, guest PC 0x0c09ac98 */
if(!s->budget--) { s->failed_pc=0x0c09ac98u; return 0; }
r[4]=0xffffffffu;
goto P_0c09ac9a;
P_0c09ac9a: /* original 906f, guest PC 0x0c09ac9a */
if(!s->budget--) { s->failed_pc=0x0c09ac9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad7cu,2);
goto P_0c09ac9c;
P_0c09ac9c: /* original e2ff, guest PC 0x0c09ac9c */
if(!s->budget--) { s->failed_pc=0x0c09ac9cu; return 0; }
r[2]=0xffffffffu;
goto P_0c09ac9e;
P_0c09ac9e: /* original 6ce3, guest PC 0x0c09ac9e */
if(!s->budget--) { s->failed_pc=0x0c09ac9eu; return 0; }
r[12]=r[14];
goto P_0c09aca0;
P_0c09aca0: /* original e300, guest PC 0x0c09aca0 */
if(!s->budget--) { s->failed_pc=0x0c09aca0u; return 0; }
r[3]=0x00000000u;
goto P_0c09aca2;
P_0c09aca2: /* original 0e26, guest PC 0x0c09aca2 */
if(!s->budget--) { s->failed_pc=0x0c09aca2u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09aca4;
P_0c09aca4: /* original 66c3, guest PC 0x0c09aca4 */
if(!s->budget--) { s->failed_pc=0x0c09aca4u; return 0; }
r[6]=r[12];
goto P_0c09aca6;
P_0c09aca6: /* original 906a, guest PC 0x0c09aca6 */
if(!s->budget--) { s->failed_pc=0x0c09aca6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad7eu,2);
goto P_0c09aca8;
P_0c09aca8: /* original 7658, guest PC 0x0c09aca8 */
if(!s->budget--) { s->failed_pc=0x0c09aca8u; return 0; }
r[6]+=0x00000058u;
goto P_0c09acaa;
P_0c09acaa: /* original 0c36, guest PC 0x0c09acaa */
if(!s->budget--) { s->failed_pc=0x0c09acaau; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c09acac;
P_0c09acac: /* original 9468, guest PC 0x0c09acac */
if(!s->budget--) { s->failed_pc=0x0c09acacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad80u,2);
goto P_0c09acae;
P_0c09acae: /* original d348, guest PC 0x0c09acae */
if(!s->budget--) { s->failed_pc=0x0c09acaeu; return 0; }
r[3]=read(ram,0x0c09add0u,4);
goto P_0c09acb0;
P_0c09acb0: /* original 430b, guest PC 0x0c09acb0 */
if(!s->budget--) { s->failed_pc=0x0c09acb0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09acb4u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acb4u) { target=s->pc; goto dispatch; }
goto P_0c09acb4;
P_0c09acb2: /* original 65c3, guest PC 0x0c09acb2 */
if(!s->budget--) { s->failed_pc=0x0c09acb2u; return 0; }
r[5]=r[12];
goto P_0c09acb4;
P_0c09acb4: /* original e200, guest PC 0x0c09acb4 */
if(!s->budget--) { s->failed_pc=0x0c09acb4u; return 0; }
r[2]=0x00000000u;
goto P_0c09acb6;
P_0c09acb6: /* original 64c3, guest PC 0x0c09acb6 */
if(!s->budget--) { s->failed_pc=0x0c09acb6u; return 0; }
r[4]=r[12];
goto P_0c09acb8;
P_0c09acb8: /* original 6523, guest PC 0x0c09acb8 */
if(!s->budget--) { s->failed_pc=0x0c09acb8u; return 0; }
r[5]=r[2];
goto P_0c09acba;
P_0c09acba: /* original 2f26, guest PC 0x0c09acba */
if(!s->budget--) { s->failed_pc=0x0c09acbau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09acbc;
P_0c09acbc: /* original d345, guest PC 0x0c09acbc */
if(!s->budget--) { s->failed_pc=0x0c09acbcu; return 0; }
r[3]=read(ram,0x0c09add4u,4);
goto P_0c09acbe;
P_0c09acbe: /* original e730, guest PC 0x0c09acbe */
if(!s->budget--) { s->failed_pc=0x0c09acbeu; return 0; }
r[7]=0x00000030u;
goto P_0c09acc0;
P_0c09acc0: /* original e63e, guest PC 0x0c09acc0 */
if(!s->budget--) { s->failed_pc=0x0c09acc0u; return 0; }
r[6]=0x0000003eu;
goto P_0c09acc2;
P_0c09acc2: /* original 430b, guest PC 0x0c09acc2 */
if(!s->budget--) { s->failed_pc=0x0c09acc2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09acc6u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acc6u) { target=s->pc; goto dispatch; }
goto P_0c09acc6;
P_0c09acc4: /* original 742c, guest PC 0x0c09acc4 */
if(!s->budget--) { s->failed_pc=0x0c09acc4u; return 0; }
r[4]+=0x0000002cu;
goto P_0c09acc6;
P_0c09acc6: /* original 945c, guest PC 0x0c09acc6 */
if(!s->budget--) { s->failed_pc=0x0c09acc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad82u,2);
goto P_0c09acc8;
P_0c09acc8: /* original 7f04, guest PC 0x0c09acc8 */
if(!s->budget--) { s->failed_pc=0x0c09acc8u; return 0; }
r[15]+=0x00000004u;
goto P_0c09acca;
P_0c09acca: /* original de43, guest PC 0x0c09acca */
if(!s->budget--) { s->failed_pc=0x0c09accau; return 0; }
r[14]=read(ram,0x0c09add8u,4);
goto P_0c09accc;
P_0c09accc: /* original 4e0b, guest PC 0x0c09accc */
if(!s->budget--) { s->failed_pc=0x0c09acccu; return 0; }
target=r[14];
r[16]=code_base|0x0c09acd0u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acd0u) { target=s->pc; goto dispatch; }
goto P_0c09acd0;
P_0c09acce: /* original 34cc, guest PC 0x0c09acce */
if(!s->budget--) { s->failed_pc=0x0c09acceu; return 0; }
r[4]+=r[12];
goto P_0c09acd0;
P_0c09acd0: /* original 4e0b, guest PC 0x0c09acd0 */
if(!s->budget--) { s->failed_pc=0x0c09acd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c09acd4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acd4u) { target=s->pc; goto dispatch; }
goto P_0c09acd4;
P_0c09acd2: /* original 64c3, guest PC 0x0c09acd2 */
if(!s->budget--) { s->failed_pc=0x0c09acd2u; return 0; }
r[4]=r[12];
goto P_0c09acd4;
P_0c09acd4: /* original 64c3, guest PC 0x0c09acd4 */
if(!s->budget--) { s->failed_pc=0x0c09acd4u; return 0; }
r[4]=r[12];
goto P_0c09acd6;
P_0c09acd6: /* original 4e0b, guest PC 0x0c09acd6 */
if(!s->budget--) { s->failed_pc=0x0c09acd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c09acdau;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acdau) { target=s->pc; goto dispatch; }
goto P_0c09acda;
P_0c09acd8: /* original 7458, guest PC 0x0c09acd8 */
if(!s->budget--) { s->failed_pc=0x0c09acd8u; return 0; }
r[4]+=0x00000058u;
goto P_0c09acda;
P_0c09acda: /* original de40, guest PC 0x0c09acda */
if(!s->budget--) { s->failed_pc=0x0c09acdau; return 0; }
r[14]=read(ram,0x0c09addcu,4);
goto P_0c09acdc;
P_0c09acdc: /* original 9052, guest PC 0x0c09acdc */
if(!s->budget--) { s->failed_pc=0x0c09acdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad84u,2);
goto P_0c09acde;
P_0c09acde: /* original d240, guest PC 0x0c09acde */
if(!s->budget--) { s->failed_pc=0x0c09acdeu; return 0; }
r[2]=read(ram,0x0c09ade0u,4);
goto P_0c09ace0;
P_0c09ace0: /* original 54ec, guest PC 0x0c09ace0 */
if(!s->budget--) { s->failed_pc=0x0c09ace0u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c09ace2;
P_0c09ace2: /* original 0426, guest PC 0x0c09ace2 */
if(!s->budget--) { s->failed_pc=0x0c09ace2u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c09ace4;
P_0c09ace4: /* original d33f, guest PC 0x0c09ace4 */
if(!s->budget--) { s->failed_pc=0x0c09ace4u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ace6;
P_0c09ace6: /* original 430b, guest PC 0x0c09ace6 */
if(!s->budget--) { s->failed_pc=0x0c09ace6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aceau;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aceau) { target=s->pc; goto dispatch; }
goto P_0c09acea;
P_0c09ace8: /* original 54e6, guest PC 0x0c09ace8 */
if(!s->budget--) { s->failed_pc=0x0c09ace8u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09acea;
P_0c09acea: /* original d23e, guest PC 0x0c09acea */
if(!s->budget--) { s->failed_pc=0x0c09aceau; return 0; }
r[2]=read(ram,0x0c09ade4u,4);
goto P_0c09acec;
P_0c09acec: /* original 420b, guest PC 0x0c09acec */
if(!s->budget--) { s->failed_pc=0x0c09acecu; return 0; }
target=r[2];
r[16]=code_base|0x0c09acf0u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acf0u) { target=s->pc; goto dispatch; }
goto P_0c09acf0;
P_0c09acee: /* original 54e7, guest PC 0x0c09acee */
if(!s->budget--) { s->failed_pc=0x0c09aceeu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09acf0;
P_0c09acf0: /* original d33c, guest PC 0x0c09acf0 */
if(!s->budget--) { s->failed_pc=0x0c09acf0u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09acf2;
P_0c09acf2: /* original 430b, guest PC 0x0c09acf2 */
if(!s->budget--) { s->failed_pc=0x0c09acf2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09acf6u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acf6u) { target=s->pc; goto dispatch; }
goto P_0c09acf6;
P_0c09acf4: /* original 54ef, guest PC 0x0c09acf4 */
if(!s->budget--) { s->failed_pc=0x0c09acf4u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09acf6;
P_0c09acf6: /* original d33b, guest PC 0x0c09acf6 */
if(!s->budget--) { s->failed_pc=0x0c09acf6u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09acf8;
P_0c09acf8: /* original e040, guest PC 0x0c09acf8 */
if(!s->budget--) { s->failed_pc=0x0c09acf8u; return 0; }
r[0]=0x00000040u;
goto P_0c09acfa;
P_0c09acfa: /* original 430b, guest PC 0x0c09acfa */
if(!s->budget--) { s->failed_pc=0x0c09acfau; return 0; }
target=r[3];
r[16]=code_base|0x0c09acfeu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09acfeu) { target=s->pc; goto dispatch; }
goto P_0c09acfe;
P_0c09acfc: /* original 04ee, guest PC 0x0c09acfc */
if(!s->budget--) { s->failed_pc=0x0c09acfcu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09acfe;
P_0c09acfe: /* original d239, guest PC 0x0c09acfe */
if(!s->budget--) { s->failed_pc=0x0c09acfeu; return 0; }
r[2]=read(ram,0x0c09ade4u,4);
goto P_0c09ad00;
P_0c09ad00: /* original 420b, guest PC 0x0c09ad00 */
if(!s->budget--) { s->failed_pc=0x0c09ad00u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ad04u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad04u) { target=s->pc; goto dispatch; }
goto P_0c09ad04;
P_0c09ad02: /* original 54e4, guest PC 0x0c09ad02 */
if(!s->budget--) { s->failed_pc=0x0c09ad02u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09ad04;
P_0c09ad04: /* original d337, guest PC 0x0c09ad04 */
if(!s->budget--) { s->failed_pc=0x0c09ad04u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad06;
P_0c09ad06: /* original 430b, guest PC 0x0c09ad06 */
if(!s->budget--) { s->failed_pc=0x0c09ad06u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad0au;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad0au) { target=s->pc; goto dispatch; }
goto P_0c09ad0a;
P_0c09ad08: /* original 54e5, guest PC 0x0c09ad08 */
if(!s->budget--) { s->failed_pc=0x0c09ad08u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09ad0a;
P_0c09ad0a: /* original d336, guest PC 0x0c09ad0a */
if(!s->budget--) { s->failed_pc=0x0c09ad0au; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad0c;
P_0c09ad0c: /* original e048, guest PC 0x0c09ad0c */
if(!s->budget--) { s->failed_pc=0x0c09ad0cu; return 0; }
r[0]=0x00000048u;
goto P_0c09ad0e;
P_0c09ad0e: /* original 430b, guest PC 0x0c09ad0e */
if(!s->budget--) { s->failed_pc=0x0c09ad0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad12u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad12u) { target=s->pc; goto dispatch; }
goto P_0c09ad12;
P_0c09ad10: /* original 04ee, guest PC 0x0c09ad10 */
if(!s->budget--) { s->failed_pc=0x0c09ad10u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad12;
P_0c09ad12: /* original d334, guest PC 0x0c09ad12 */
if(!s->budget--) { s->failed_pc=0x0c09ad12u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad14;
P_0c09ad14: /* original e05c, guest PC 0x0c09ad14 */
if(!s->budget--) { s->failed_pc=0x0c09ad14u; return 0; }
r[0]=0x0000005cu;
goto P_0c09ad16;
P_0c09ad16: /* original 430b, guest PC 0x0c09ad16 */
if(!s->budget--) { s->failed_pc=0x0c09ad16u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad1au;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad1au) { target=s->pc; goto dispatch; }
goto P_0c09ad1a;
P_0c09ad18: /* original 04ee, guest PC 0x0c09ad18 */
if(!s->budget--) { s->failed_pc=0x0c09ad18u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad1a;
P_0c09ad1a: /* original d332, guest PC 0x0c09ad1a */
if(!s->budget--) { s->failed_pc=0x0c09ad1au; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad1c;
P_0c09ad1c: /* original e060, guest PC 0x0c09ad1c */
if(!s->budget--) { s->failed_pc=0x0c09ad1cu; return 0; }
r[0]=0x00000060u;
goto P_0c09ad1e;
P_0c09ad1e: /* original 430b, guest PC 0x0c09ad1e */
if(!s->budget--) { s->failed_pc=0x0c09ad1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad22u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad22u) { target=s->pc; goto dispatch; }
goto P_0c09ad22;
P_0c09ad20: /* original 04ee, guest PC 0x0c09ad20 */
if(!s->budget--) { s->failed_pc=0x0c09ad20u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad22;
P_0c09ad22: /* original d330, guest PC 0x0c09ad22 */
if(!s->budget--) { s->failed_pc=0x0c09ad22u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad24;
P_0c09ad24: /* original e064, guest PC 0x0c09ad24 */
if(!s->budget--) { s->failed_pc=0x0c09ad24u; return 0; }
r[0]=0x00000064u;
goto P_0c09ad26;
P_0c09ad26: /* original 430b, guest PC 0x0c09ad26 */
if(!s->budget--) { s->failed_pc=0x0c09ad26u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad2au;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad2au) { target=s->pc; goto dispatch; }
goto P_0c09ad2a;
P_0c09ad28: /* original 04ee, guest PC 0x0c09ad28 */
if(!s->budget--) { s->failed_pc=0x0c09ad28u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad2a;
P_0c09ad2a: /* original d32e, guest PC 0x0c09ad2a */
if(!s->budget--) { s->failed_pc=0x0c09ad2au; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad2c;
P_0c09ad2c: /* original e060, guest PC 0x0c09ad2c */
if(!s->budget--) { s->failed_pc=0x0c09ad2cu; return 0; }
r[0]=0x00000060u;
goto P_0c09ad2e;
P_0c09ad2e: /* original 430b, guest PC 0x0c09ad2e */
if(!s->budget--) { s->failed_pc=0x0c09ad2eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad32u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad32u) { target=s->pc; goto dispatch; }
goto P_0c09ad32;
P_0c09ad30: /* original 04ee, guest PC 0x0c09ad30 */
if(!s->budget--) { s->failed_pc=0x0c09ad30u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad32;
P_0c09ad32: /* original d32c, guest PC 0x0c09ad32 */
if(!s->budget--) { s->failed_pc=0x0c09ad32u; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad34;
P_0c09ad34: /* original e064, guest PC 0x0c09ad34 */
if(!s->budget--) { s->failed_pc=0x0c09ad34u; return 0; }
r[0]=0x00000064u;
goto P_0c09ad36;
P_0c09ad36: /* original 430b, guest PC 0x0c09ad36 */
if(!s->budget--) { s->failed_pc=0x0c09ad36u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad3au;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad3au) { target=s->pc; goto dispatch; }
goto P_0c09ad3a;
P_0c09ad38: /* original 04ee, guest PC 0x0c09ad38 */
if(!s->budget--) { s->failed_pc=0x0c09ad38u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad3a;
P_0c09ad3a: /* original d32a, guest PC 0x0c09ad3a */
if(!s->budget--) { s->failed_pc=0x0c09ad3au; return 0; }
r[3]=read(ram,0x0c09ade4u,4);
goto P_0c09ad3c;
P_0c09ad3c: /* original e054, guest PC 0x0c09ad3c */
if(!s->budget--) { s->failed_pc=0x0c09ad3cu; return 0; }
r[0]=0x00000054u;
goto P_0c09ad3e;
P_0c09ad3e: /* original 430b, guest PC 0x0c09ad3e */
if(!s->budget--) { s->failed_pc=0x0c09ad3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ad42u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ad42u) { target=s->pc; goto dispatch; }
goto P_0c09ad42;
P_0c09ad40: /* original 04ee, guest PC 0x0c09ad40 */
if(!s->budget--) { s->failed_pc=0x0c09ad40u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09ad42;
P_0c09ad42: /* original 9020, guest PC 0x0c09ad42 */
if(!s->budget--) { s->failed_pc=0x0c09ad42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad86u,2);
goto P_0c09ad44;
P_0c09ad44: /* original ec00, guest PC 0x0c09ad44 */
if(!s->budget--) { s->failed_pc=0x0c09ad44u; return 0; }
r[12]=0x00000000u;
goto P_0c09ad46;
P_0c09ad46: /* original 63c3, guest PC 0x0c09ad46 */
if(!s->budget--) { s->failed_pc=0x0c09ad46u; return 0; }
r[3]=r[12];
goto P_0c09ad48;
P_0c09ad48: /* original e214, guest PC 0x0c09ad48 */
if(!s->budget--) { s->failed_pc=0x0c09ad48u; return 0; }
r[2]=0x00000014u;
goto P_0c09ad4a;
P_0c09ad4a: /* original 0dc4, guest PC 0x0c09ad4a */
if(!s->budget--) { s->failed_pc=0x0c09ad4au; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c09ad4c;
P_0c09ad4c: /* original 70d2, guest PC 0x0c09ad4c */
if(!s->budget--) { s->failed_pc=0x0c09ad4cu; return 0; }
r[0]+=0xffffffd2u;
goto P_0c09ad4e;
P_0c09ad4e: /* original 0dc6, guest PC 0x0c09ad4e */
if(!s->budget--) { s->failed_pc=0x0c09ad4eu; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c09ad50;
P_0c09ad50: /* original 7050, guest PC 0x0c09ad50 */
if(!s->budget--) { s->failed_pc=0x0c09ad50u; return 0; }
r[0]+=0x00000050u;
goto P_0c09ad52;
P_0c09ad52: /* original 0d34, guest PC 0x0c09ad52 */
if(!s->budget--) { s->failed_pc=0x0c09ad52u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09ad54;
P_0c09ad54: /* original e010, guest PC 0x0c09ad54 */
if(!s->budget--) { s->failed_pc=0x0c09ad54u; return 0; }
r[0]=0x00000010u;
goto P_0c09ad56;
P_0c09ad56: /* original e311, guest PC 0x0c09ad56 */
if(!s->budget--) { s->failed_pc=0x0c09ad56u; return 0; }
r[3]=0x00000011u;
goto P_0c09ad58;
P_0c09ad58: /* original 0d34, guest PC 0x0c09ad58 */
if(!s->budget--) { s->failed_pc=0x0c09ad58u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09ad5a;
P_0c09ad5a: /* original e301, guest PC 0x0c09ad5a */
if(!s->budget--) { s->failed_pc=0x0c09ad5au; return 0; }
r[3]=0x00000001u;
goto P_0c09ad5c;
P_0c09ad5c: /* original 9014, guest PC 0x0c09ad5c */
if(!s->budget--) { s->failed_pc=0x0c09ad5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad88u,2);
goto P_0c09ad5e;
P_0c09ad5e: /* original e50f, guest PC 0x0c09ad5e */
if(!s->budget--) { s->failed_pc=0x0c09ad5eu; return 0; }
r[5]=0x0000000fu;
goto P_0c09ad60;
P_0c09ad60: /* original 54e8, guest PC 0x0c09ad60 */
if(!s->budget--) { s->failed_pc=0x0c09ad60u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09ad62;
P_0c09ad62: /* original f4f7, guest PC 0x0c09ad62 */
if(!s->budget--) { s->failed_pc=0x0c09ad62u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09ad64;
P_0c09ad64: /* original 709f, guest PC 0x0c09ad64 */
if(!s->budget--) { s->failed_pc=0x0c09ad64u; return 0; }
r[0]+=0xffffff9fu;
goto P_0c09ad66;
P_0c09ad66: /* original 04c4, guest PC 0x0c09ad66 */
if(!s->budget--) { s->failed_pc=0x0c09ad66u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c09ad68;
P_0c09ad68: /* original 2432, guest PC 0x0c09ad68 */
if(!s->budget--) { s->failed_pc=0x0c09ad68u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c09ad6a;
P_0c09ad6a: /* original 900e, guest PC 0x0c09ad6a */
if(!s->budget--) { s->failed_pc=0x0c09ad6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad8au,2);
goto P_0c09ad6c;
P_0c09ad6c: /* original 0424, guest PC 0x0c09ad6c */
if(!s->budget--) { s->failed_pc=0x0c09ad6cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09ad6e;
P_0c09ad6e: /* original 900d, guest PC 0x0c09ad6e */
if(!s->budget--) { s->failed_pc=0x0c09ad6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ad8cu,2);
goto P_0c09ad70;
P_0c09ad70: /* original 04c4, guest PC 0x0c09ad70 */
if(!s->budget--) { s->failed_pc=0x0c09ad70u; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c09ad72;
P_0c09ad72: /* original e01c, guest PC 0x0c09ad72 */
if(!s->budget--) { s->failed_pc=0x0c09ad72u; return 0; }
r[0]=0x0000001cu;
goto P_0c09ad74;
P_0c09ad74: /* original 00dc, guest PC 0x0c09ad74 */
if(!s->budget--) { s->failed_pc=0x0c09ad74u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09ad76;
P_0c09ad76: /* original 600c, guest PC 0x0c09ad76 */
if(!s->budget--) { s->failed_pc=0x0c09ad76u; return 0; }
r[0]=r[0]&255u;
goto P_0c09ad78;
P_0c09ad78: /* original a036, guest PC 0x0c09ad78 */
if(!s->budget--) { s->failed_pc=0x0c09ad78u; return 0; }
goto P_0c09ade8;
P_0c09ad7a: /* original 0009, guest PC 0x0c09ad7a */
if(!s->budget--) { s->failed_pc=0x0c09ad7au; return 0; }
if(!vf3_matrix_family(0x0c09ad7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ad7cu; return 0; } return 1;
P_0c09ade8: /* original 2509, guest PC 0x0c09ade8 */
if(!s->budget--) { s->failed_pc=0x0c09ade8u; return 0; }
r[5]&=r[0];
goto P_0c09adea;
P_0c09adea: /* original d353, guest PC 0x0c09adea */
if(!s->budget--) { s->failed_pc=0x0c09adeau; return 0; }
r[3]=read(ram,0x0c09af38u,4);
goto P_0c09adec;
P_0c09adec: /* original 4508, guest PC 0x0c09adec */
if(!s->budget--) { s->failed_pc=0x0c09adecu; return 0; }
r[5]<<=2;
goto P_0c09adee;
P_0c09adee: /* original 919b, guest PC 0x0c09adee */
if(!s->budget--) { s->failed_pc=0x0c09adeeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af28u,2);
goto P_0c09adf0;
P_0c09adf0: /* original 4508, guest PC 0x0c09adf0 */
if(!s->budget--) { s->failed_pc=0x0c09adf0u; return 0; }
r[5]<<=2;
goto P_0c09adf2;
P_0c09adf2: /* original 4508, guest PC 0x0c09adf2 */
if(!s->budget--) { s->failed_pc=0x0c09adf2u; return 0; }
r[5]<<=2;
goto P_0c09adf4;
P_0c09adf4: /* original 353c, guest PC 0x0c09adf4 */
if(!s->budget--) { s->failed_pc=0x0c09adf4u; return 0; }
r[5]+=r[3];
goto P_0c09adf6;
P_0c09adf6: /* original 8455, guest PC 0x0c09adf6 */
if(!s->budget--) { s->failed_pc=0x0c09adf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c09adf8;
P_0c09adf8: /* original 314c, guest PC 0x0c09adf8 */
if(!s->budget--) { s->failed_pc=0x0c09adf8u; return 0; }
r[1]+=r[4];
goto P_0c09adfa;
P_0c09adfa: /* original 2100, guest PC 0x0c09adfa */
if(!s->budget--) { s->failed_pc=0x0c09adfau; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09adfc;
P_0c09adfc: /* original 9295, guest PC 0x0c09adfc */
if(!s->budget--) { s->failed_pc=0x0c09adfcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af2au,2);
goto P_0c09adfe;
P_0c09adfe: /* original 8456, guest PC 0x0c09adfe */
if(!s->budget--) { s->failed_pc=0x0c09adfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+6,1);
goto P_0c09ae00;
P_0c09ae00: /* original 324c, guest PC 0x0c09ae00 */
if(!s->budget--) { s->failed_pc=0x0c09ae00u; return 0; }
r[2]+=r[4];
goto P_0c09ae02;
P_0c09ae02: /* original 2200, guest PC 0x0c09ae02 */
if(!s->budget--) { s->failed_pc=0x0c09ae02u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c09ae04;
P_0c09ae04: /* original 9192, guest PC 0x0c09ae04 */
if(!s->budget--) { s->failed_pc=0x0c09ae04u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af2cu,2);
goto P_0c09ae06;
P_0c09ae06: /* original 8457, guest PC 0x0c09ae06 */
if(!s->budget--) { s->failed_pc=0x0c09ae06u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+7,1);
goto P_0c09ae08;
P_0c09ae08: /* original 314c, guest PC 0x0c09ae08 */
if(!s->budget--) { s->failed_pc=0x0c09ae08u; return 0; }
r[1]+=r[4];
goto P_0c09ae0a;
P_0c09ae0a: /* original 2100, guest PC 0x0c09ae0a */
if(!s->budget--) { s->failed_pc=0x0c09ae0au; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09ae0c;
P_0c09ae0c: /* original e01c, guest PC 0x0c09ae0c */
if(!s->budget--) { s->failed_pc=0x0c09ae0cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09ae0e;
P_0c09ae0e: /* original f356, guest PC 0x0c09ae0e */
if(!s->budget--) { s->failed_pc=0x0c09ae0eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09ae10;
P_0c09ae10: /* original 908d, guest PC 0x0c09ae10 */
if(!s->budget--) { s->failed_pc=0x0c09ae10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af2eu,2);
goto P_0c09ae12;
P_0c09ae12: /* original f437, guest PC 0x0c09ae12 */
if(!s->budget--) { s->failed_pc=0x0c09ae12u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09ae14;
P_0c09ae14: /* original e020, guest PC 0x0c09ae14 */
if(!s->budget--) { s->failed_pc=0x0c09ae14u; return 0; }
r[0]=0x00000020u;
goto P_0c09ae16;
P_0c09ae16: /* original f356, guest PC 0x0c09ae16 */
if(!s->budget--) { s->failed_pc=0x0c09ae16u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09ae18;
P_0c09ae18: /* original 908a, guest PC 0x0c09ae18 */
if(!s->budget--) { s->failed_pc=0x0c09ae18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af30u,2);
goto P_0c09ae1a;
P_0c09ae1a: /* original f437, guest PC 0x0c09ae1a */
if(!s->budget--) { s->failed_pc=0x0c09ae1au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09ae1c;
P_0c09ae1c: /* original e024, guest PC 0x0c09ae1c */
if(!s->budget--) { s->failed_pc=0x0c09ae1cu; return 0; }
r[0]=0x00000024u;
goto P_0c09ae1e;
P_0c09ae1e: /* original f356, guest PC 0x0c09ae1e */
if(!s->budget--) { s->failed_pc=0x0c09ae1eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c09ae20;
P_0c09ae20: /* original 9087, guest PC 0x0c09ae20 */
if(!s->budget--) { s->failed_pc=0x0c09ae20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af32u,2);
goto P_0c09ae22;
P_0c09ae22: /* original f437, guest PC 0x0c09ae22 */
if(!s->budget--) { s->failed_pc=0x0c09ae22u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09ae24;
P_0c09ae24: /* original 5be4, guest PC 0x0c09ae24 */
if(!s->budget--) { s->failed_pc=0x0c09ae24u; return 0; }
r[11]=read(ram,r[14]+16,4);
goto P_0c09ae26;
P_0c09ae26: /* original d245, guest PC 0x0c09ae26 */
if(!s->budget--) { s->failed_pc=0x0c09ae26u; return 0; }
r[2]=read(ram,0x0c09af3cu,4);
goto P_0c09ae28;
P_0c09ae28: /* original 420b, guest PC 0x0c09ae28 */
if(!s->budget--) { s->failed_pc=0x0c09ae28u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ae2cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ae2cu) { target=s->pc; goto dispatch; }
goto P_0c09ae2c;
P_0c09ae2a: /* original 64b3, guest PC 0x0c09ae2a */
if(!s->budget--) { s->failed_pc=0x0c09ae2au; return 0; }
r[4]=r[11];
goto P_0c09ae2c;
P_0c09ae2c: /* original 9082, guest PC 0x0c09ae2c */
if(!s->budget--) { s->failed_pc=0x0c09ae2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af34u,2);
goto P_0c09ae2e;
P_0c09ae2e: /* original 63c3, guest PC 0x0c09ae2e */
if(!s->budget--) { s->failed_pc=0x0c09ae2eu; return 0; }
r[3]=r[12];
goto P_0c09ae30;
P_0c09ae30: /* original 0bc6, guest PC 0x0c09ae30 */
if(!s->budget--) { s->failed_pc=0x0c09ae30u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c09ae32;
P_0c09ae32: /* original d343, guest PC 0x0c09ae32 */
if(!s->budget--) { s->failed_pc=0x0c09ae32u; return 0; }
r[3]=read(ram,0x0c09af40u,4);
goto P_0c09ae34;
P_0c09ae34: /* original 62b2, guest PC 0x0c09ae34 */
if(!s->budget--) { s->failed_pc=0x0c09ae34u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c09ae36;
P_0c09ae36: /* original 2239, guest PC 0x0c09ae36 */
if(!s->budget--) { s->failed_pc=0x0c09ae36u; return 0; }
r[2]&=r[3];
goto P_0c09ae38;
P_0c09ae38: /* original 2b22, guest PC 0x0c09ae38 */
if(!s->budget--) { s->failed_pc=0x0c09ae38u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c09ae3a;
P_0c09ae3a: /* original 5ee5, guest PC 0x0c09ae3a */
if(!s->budget--) { s->failed_pc=0x0c09ae3au; return 0; }
r[14]=read(ram,r[14]+20,4);
goto P_0c09ae3c;
P_0c09ae3c: /* original d13f, guest PC 0x0c09ae3c */
if(!s->budget--) { s->failed_pc=0x0c09ae3cu; return 0; }
r[1]=read(ram,0x0c09af3cu,4);
goto P_0c09ae3e;
P_0c09ae3e: /* original 410b, guest PC 0x0c09ae3e */
if(!s->budget--) { s->failed_pc=0x0c09ae3eu; return 0; }
target=r[1];
r[16]=code_base|0x0c09ae42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ae42u) { target=s->pc; goto dispatch; }
goto P_0c09ae42;
P_0c09ae40: /* original 64e3, guest PC 0x0c09ae40 */
if(!s->budget--) { s->failed_pc=0x0c09ae40u; return 0; }
r[4]=r[14];
goto P_0c09ae42;
P_0c09ae42: /* original 9077, guest PC 0x0c09ae42 */
if(!s->budget--) { s->failed_pc=0x0c09ae42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af34u,2);
goto P_0c09ae44;
P_0c09ae44: /* original e140, guest PC 0x0c09ae44 */
if(!s->budget--) { s->failed_pc=0x0c09ae44u; return 0; }
r[1]=0x00000040u;
goto P_0c09ae46;
P_0c09ae46: /* original 66c3, guest PC 0x0c09ae46 */
if(!s->budget--) { s->failed_pc=0x0c09ae46u; return 0; }
r[6]=r[12];
goto P_0c09ae48;
P_0c09ae48: /* original 65c3, guest PC 0x0c09ae48 */
if(!s->budget--) { s->failed_pc=0x0c09ae48u; return 0; }
r[5]=r[12];
goto P_0c09ae4a;
P_0c09ae4a: /* original 0ec6, guest PC 0x0c09ae4a */
if(!s->budget--) { s->failed_pc=0x0c09ae4au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09ae4c;
P_0c09ae4c: /* original 60c3, guest PC 0x0c09ae4c */
if(!s->budget--) { s->failed_pc=0x0c09ae4cu; return 0; }
r[0]=r[12];
goto P_0c09ae4e;
P_0c09ae4e: /* original 62e2, guest PC 0x0c09ae4e */
if(!s->budget--) { s->failed_pc=0x0c09ae4eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09ae50;
P_0c09ae50: /* original 63c3, guest PC 0x0c09ae50 */
if(!s->budget--) { s->failed_pc=0x0c09ae50u; return 0; }
r[3]=r[12];
goto P_0c09ae52;
P_0c09ae52: /* original d33b, guest PC 0x0c09ae52 */
if(!s->budget--) { s->failed_pc=0x0c09ae52u; return 0; }
r[3]=read(ram,0x0c09af40u,4);
goto P_0c09ae54;
P_0c09ae54: /* original 2239, guest PC 0x0c09ae54 */
if(!s->budget--) { s->failed_pc=0x0c09ae54u; return 0; }
r[2]&=r[3];
goto P_0c09ae56;
P_0c09ae56: /* original 2e22, guest PC 0x0c09ae56 */
if(!s->budget--) { s->failed_pc=0x0c09ae56u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c09ae58;
P_0c09ae58: /* original e271, guest PC 0x0c09ae58 */
if(!s->budget--) { s->failed_pc=0x0c09ae58u; return 0; }
r[2]=0x00000071u;
goto P_0c09ae5a;
P_0c09ae5a: /* original 1d13, guest PC 0x0c09ae5a */
if(!s->budget--) { s->failed_pc=0x0c09ae5au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c09ae5c;
P_0c09ae5c: /* original 80db, guest PC 0x0c09ae5c */
if(!s->budget--) { s->failed_pc=0x0c09ae5cu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09ae5e;
P_0c09ae5e: /* original e010, guest PC 0x0c09ae5e */
if(!s->budget--) { s->failed_pc=0x0c09ae5eu; return 0; }
r[0]=0x00000010u;
goto P_0c09ae60;
P_0c09ae60: /* original 0d24, guest PC 0x0c09ae60 */
if(!s->budget--) { s->failed_pc=0x0c09ae60u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c09ae62;
P_0c09ae62: /* original 84da, guest PC 0x0c09ae62 */
if(!s->budget--) { s->failed_pc=0x0c09ae62u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c09ae64;
P_0c09ae64: /* original 7001, guest PC 0x0c09ae64 */
if(!s->budget--) { s->failed_pc=0x0c09ae64u; return 0; }
r[0]+=0x00000001u;
goto P_0c09ae66;
P_0c09ae66: /* original 80da, guest PC 0x0c09ae66 */
if(!s->budget--) { s->failed_pc=0x0c09ae66u; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09ae68;
P_0c09ae68: /* original d236, guest PC 0x0c09ae68 */
if(!s->budget--) { s->failed_pc=0x0c09ae68u; return 0; }
r[2]=read(ram,0x0c09af44u,4);
goto P_0c09ae6a;
P_0c09ae6a: /* original 420b, guest PC 0x0c09ae6a */
if(!s->budget--) { s->failed_pc=0x0c09ae6au; return 0; }
target=r[2];
r[16]=code_base|0x0c09ae6eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ae6eu) { target=s->pc; goto dispatch; }
goto P_0c09ae6e;
P_0c09ae6c: /* original 64c3, guest PC 0x0c09ae6c */
if(!s->budget--) { s->failed_pc=0x0c09ae6cu; return 0; }
r[4]=r[12];
goto P_0c09ae6e;
P_0c09ae6e: /* original d336, guest PC 0x0c09ae6e */
if(!s->budget--) { s->failed_pc=0x0c09ae6eu; return 0; }
r[3]=read(ram,0x0c09af48u,4);
goto P_0c09ae70;
P_0c09ae70: /* original 430b, guest PC 0x0c09ae70 */
if(!s->budget--) { s->failed_pc=0x0c09ae70u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ae74u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ae74u) { target=s->pc; goto dispatch; }
goto P_0c09ae74;
P_0c09ae72: /* original 0009, guest PC 0x0c09ae72 */
if(!s->budget--) { s->failed_pc=0x0c09ae72u; return 0; }
goto P_0c09ae74;
P_0c09ae74: /* original 4f26, guest PC 0x0c09ae74 */
if(!s->budget--) { s->failed_pc=0x0c09ae74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ae76;
P_0c09ae76: /* original fff9, guest PC 0x0c09ae76 */
if(!s->budget--) { s->failed_pc=0x0c09ae76u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09ae78;
P_0c09ae78: /* original 6bf6, guest PC 0x0c09ae78 */
if(!s->budget--) { s->failed_pc=0x0c09ae78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ae7a;
P_0c09ae7a: /* original 6cf6, guest PC 0x0c09ae7a */
if(!s->budget--) { s->failed_pc=0x0c09ae7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ae7c;
P_0c09ae7c: /* original 6df6, guest PC 0x0c09ae7c */
if(!s->budget--) { s->failed_pc=0x0c09ae7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ae7e;
P_0c09ae7e: /* original a000, guest PC 0x0c09ae7e */
if(!s->budget--) { s->failed_pc=0x0c09ae7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ae82;
P_0c09ae80: /* original 6ef6, guest PC 0x0c09ae80 */
if(!s->budget--) { s->failed_pc=0x0c09ae80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ae82;
P_0c09ae82: /* original d432, guest PC 0x0c09ae82 */
if(!s->budget--) { s->failed_pc=0x0c09ae82u; return 0; }
r[4]=read(ram,0x0c09af4cu,4);
goto P_0c09ae84;
P_0c09ae84: /* original 7ffc, guest PC 0x0c09ae84 */
if(!s->budget--) { s->failed_pc=0x0c09ae84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09ae86;
P_0c09ae86: /* original 844b, guest PC 0x0c09ae86 */
if(!s->budget--) { s->failed_pc=0x0c09ae86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c09ae88;
P_0c09ae88: /* original 650c, guest PC 0x0c09ae88 */
if(!s->budget--) { s->failed_pc=0x0c09ae88u; return 0; }
r[5]=r[0]&255u;
goto P_0c09ae8a;
P_0c09ae8a: /* original 6053, guest PC 0x0c09ae8a */
if(!s->budget--) { s->failed_pc=0x0c09ae8au; return 0; }
r[0]=r[5];
goto P_0c09ae8c;
P_0c09ae8c: /* original 8049, guest PC 0x0c09ae8c */
if(!s->budget--) { s->failed_pc=0x0c09ae8cu; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c09ae8e;
P_0c09ae8e: /* original d230, guest PC 0x0c09ae8e */
if(!s->budget--) { s->failed_pc=0x0c09ae8eu; return 0; }
r[2]=read(ram,0x0c09af50u,4);
goto P_0c09ae90;
P_0c09ae90: /* original 635b, guest PC 0x0c09ae90 */
if(!s->budget--) { s->failed_pc=0x0c09ae90u; return 0; }
r[3]=0u-r[5];
goto P_0c09ae92;
P_0c09ae92: /* original 4508, guest PC 0x0c09ae92 */
if(!s->budget--) { s->failed_pc=0x0c09ae92u; return 0; }
r[5]<<=2;
goto P_0c09ae94;
P_0c09ae94: /* original 423d, guest PC 0x0c09ae94 */
if(!s->budget--) { s->failed_pc=0x0c09ae94u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c09ae96;
P_0c09ae96: /* original 1421, guest PC 0x0c09ae96 */
if(!s->budget--) { s->failed_pc=0x0c09ae96u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09ae98;
P_0c09ae98: /* original d02e, guest PC 0x0c09ae98 */
if(!s->budget--) { s->failed_pc=0x0c09ae98u; return 0; }
r[0]=read(ram,0x0c09af54u,4);
goto P_0c09ae9a;
P_0c09ae9a: /* original 035e, guest PC 0x0c09ae9a */
if(!s->budget--) { s->failed_pc=0x0c09ae9au; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09ae9c;
P_0c09ae9c: /* original 6233, guest PC 0x0c09ae9c */
if(!s->budget--) { s->failed_pc=0x0c09ae9cu; return 0; }
r[2]=r[3];
goto P_0c09ae9e;
P_0c09ae9e: /* original 2f32, guest PC 0x0c09ae9e */
if(!s->budget--) { s->failed_pc=0x0c09ae9eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09aea0;
P_0c09aea0: /* original 422b, guest PC 0x0c09aea0 */
if(!s->budget--) { s->failed_pc=0x0c09aea0u; return 0; }
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
P_0c09aea2: /* original 7f04, guest PC 0x0c09aea2 */
if(!s->budget--) { s->failed_pc=0x0c09aea2u; return 0; }
r[15]+=0x00000004u;
goto P_0c09aea4;
P_0c09aea4: /* original 2fe6, guest PC 0x0c09aea4 */
if(!s->budget--) { s->failed_pc=0x0c09aea4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aea6;
P_0c09aea6: /* original 2fd6, guest PC 0x0c09aea6 */
if(!s->budget--) { s->failed_pc=0x0c09aea6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aea8;
P_0c09aea8: /* original de2b, guest PC 0x0c09aea8 */
if(!s->budget--) { s->failed_pc=0x0c09aea8u; return 0; }
r[14]=read(ram,0x0c09af58u,4);
goto P_0c09aeaa;
P_0c09aeaa: /* original d32c, guest PC 0x0c09aeaa */
if(!s->budget--) { s->failed_pc=0x0c09aeaau; return 0; }
r[3]=read(ram,0x0c09af5cu,4);
goto P_0c09aeac;
P_0c09aeac: /* original 54ec, guest PC 0x0c09aeac */
if(!s->budget--) { s->failed_pc=0x0c09aeacu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c09aeae;
P_0c09aeae: /* original 9042, guest PC 0x0c09aeae */
if(!s->budget--) { s->failed_pc=0x0c09aeaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09af36u,2);
goto P_0c09aeb0;
P_0c09aeb0: /* original 4f22, guest PC 0x0c09aeb0 */
if(!s->budget--) { s->failed_pc=0x0c09aeb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09aeb2;
P_0c09aeb2: /* original dd26, guest PC 0x0c09aeb2 */
if(!s->budget--) { s->failed_pc=0x0c09aeb2u; return 0; }
r[13]=read(ram,0x0c09af4cu,4);
goto P_0c09aeb4;
P_0c09aeb4: /* original 0436, guest PC 0x0c09aeb4 */
if(!s->budget--) { s->failed_pc=0x0c09aeb4u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09aeb6;
P_0c09aeb6: /* original d32a, guest PC 0x0c09aeb6 */
if(!s->budget--) { s->failed_pc=0x0c09aeb6u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aeb8;
P_0c09aeb8: /* original 430b, guest PC 0x0c09aeb8 */
if(!s->budget--) { s->failed_pc=0x0c09aeb8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aebcu;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aebcu) { target=s->pc; goto dispatch; }
goto P_0c09aebc;
P_0c09aeba: /* original 54e6, guest PC 0x0c09aeba */
if(!s->budget--) { s->failed_pc=0x0c09aebau; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09aebc;
P_0c09aebc: /* original d228, guest PC 0x0c09aebc */
if(!s->budget--) { s->failed_pc=0x0c09aebcu; return 0; }
r[2]=read(ram,0x0c09af60u,4);
goto P_0c09aebe;
P_0c09aebe: /* original 420b, guest PC 0x0c09aebe */
if(!s->budget--) { s->failed_pc=0x0c09aebeu; return 0; }
target=r[2];
r[16]=code_base|0x0c09aec2u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aec2u) { target=s->pc; goto dispatch; }
goto P_0c09aec2;
P_0c09aec0: /* original 54e7, guest PC 0x0c09aec0 */
if(!s->budget--) { s->failed_pc=0x0c09aec0u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09aec2;
P_0c09aec2: /* original d327, guest PC 0x0c09aec2 */
if(!s->budget--) { s->failed_pc=0x0c09aec2u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aec4;
P_0c09aec4: /* original 430b, guest PC 0x0c09aec4 */
if(!s->budget--) { s->failed_pc=0x0c09aec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aec8u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aec8u) { target=s->pc; goto dispatch; }
goto P_0c09aec8;
P_0c09aec6: /* original 54ef, guest PC 0x0c09aec6 */
if(!s->budget--) { s->failed_pc=0x0c09aec6u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09aec8;
P_0c09aec8: /* original d325, guest PC 0x0c09aec8 */
if(!s->budget--) { s->failed_pc=0x0c09aec8u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aeca;
P_0c09aeca: /* original e040, guest PC 0x0c09aeca */
if(!s->budget--) { s->failed_pc=0x0c09aecau; return 0; }
r[0]=0x00000040u;
goto P_0c09aecc;
P_0c09aecc: /* original 430b, guest PC 0x0c09aecc */
if(!s->budget--) { s->failed_pc=0x0c09aeccu; return 0; }
target=r[3];
r[16]=code_base|0x0c09aed0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aed0u) { target=s->pc; goto dispatch; }
goto P_0c09aed0;
P_0c09aece: /* original 04ee, guest PC 0x0c09aece */
if(!s->budget--) { s->failed_pc=0x0c09aeceu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aed0;
P_0c09aed0: /* original d223, guest PC 0x0c09aed0 */
if(!s->budget--) { s->failed_pc=0x0c09aed0u; return 0; }
r[2]=read(ram,0x0c09af60u,4);
goto P_0c09aed2;
P_0c09aed2: /* original 420b, guest PC 0x0c09aed2 */
if(!s->budget--) { s->failed_pc=0x0c09aed2u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aed6u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aed6u) { target=s->pc; goto dispatch; }
goto P_0c09aed6;
P_0c09aed4: /* original 54e4, guest PC 0x0c09aed4 */
if(!s->budget--) { s->failed_pc=0x0c09aed4u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09aed6;
P_0c09aed6: /* original d322, guest PC 0x0c09aed6 */
if(!s->budget--) { s->failed_pc=0x0c09aed6u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aed8;
P_0c09aed8: /* original 430b, guest PC 0x0c09aed8 */
if(!s->budget--) { s->failed_pc=0x0c09aed8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aedcu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aedcu) { target=s->pc; goto dispatch; }
goto P_0c09aedc;
P_0c09aeda: /* original 54e5, guest PC 0x0c09aeda */
if(!s->budget--) { s->failed_pc=0x0c09aedau; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09aedc;
P_0c09aedc: /* original d320, guest PC 0x0c09aedc */
if(!s->budget--) { s->failed_pc=0x0c09aedcu; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aede;
P_0c09aede: /* original e048, guest PC 0x0c09aede */
if(!s->budget--) { s->failed_pc=0x0c09aedeu; return 0; }
r[0]=0x00000048u;
goto P_0c09aee0;
P_0c09aee0: /* original 430b, guest PC 0x0c09aee0 */
if(!s->budget--) { s->failed_pc=0x0c09aee0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aee4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aee4u) { target=s->pc; goto dispatch; }
goto P_0c09aee4;
P_0c09aee2: /* original 04ee, guest PC 0x0c09aee2 */
if(!s->budget--) { s->failed_pc=0x0c09aee2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aee4;
P_0c09aee4: /* original d31e, guest PC 0x0c09aee4 */
if(!s->budget--) { s->failed_pc=0x0c09aee4u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aee6;
P_0c09aee6: /* original e05c, guest PC 0x0c09aee6 */
if(!s->budget--) { s->failed_pc=0x0c09aee6u; return 0; }
r[0]=0x0000005cu;
goto P_0c09aee8;
P_0c09aee8: /* original 430b, guest PC 0x0c09aee8 */
if(!s->budget--) { s->failed_pc=0x0c09aee8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aeecu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aeecu) { target=s->pc; goto dispatch; }
goto P_0c09aeec;
P_0c09aeea: /* original 04ee, guest PC 0x0c09aeea */
if(!s->budget--) { s->failed_pc=0x0c09aeeau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aeec;
P_0c09aeec: /* original d31c, guest PC 0x0c09aeec */
if(!s->budget--) { s->failed_pc=0x0c09aeecu; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aeee;
P_0c09aeee: /* original e060, guest PC 0x0c09aeee */
if(!s->budget--) { s->failed_pc=0x0c09aeeeu; return 0; }
r[0]=0x00000060u;
goto P_0c09aef0;
P_0c09aef0: /* original 430b, guest PC 0x0c09aef0 */
if(!s->budget--) { s->failed_pc=0x0c09aef0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aef4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aef4u) { target=s->pc; goto dispatch; }
goto P_0c09aef4;
P_0c09aef2: /* original 04ee, guest PC 0x0c09aef2 */
if(!s->budget--) { s->failed_pc=0x0c09aef2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aef4;
P_0c09aef4: /* original d31a, guest PC 0x0c09aef4 */
if(!s->budget--) { s->failed_pc=0x0c09aef4u; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aef6;
P_0c09aef6: /* original e064, guest PC 0x0c09aef6 */
if(!s->budget--) { s->failed_pc=0x0c09aef6u; return 0; }
r[0]=0x00000064u;
goto P_0c09aef8;
P_0c09aef8: /* original 430b, guest PC 0x0c09aef8 */
if(!s->budget--) { s->failed_pc=0x0c09aef8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aefcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aefcu) { target=s->pc; goto dispatch; }
goto P_0c09aefc;
P_0c09aefa: /* original 04ee, guest PC 0x0c09aefa */
if(!s->budget--) { s->failed_pc=0x0c09aefau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aefc;
P_0c09aefc: /* original d318, guest PC 0x0c09aefc */
if(!s->budget--) { s->failed_pc=0x0c09aefcu; return 0; }
r[3]=read(ram,0x0c09af60u,4);
goto P_0c09aefe;
P_0c09aefe: /* original e054, guest PC 0x0c09aefe */
if(!s->budget--) { s->failed_pc=0x0c09aefeu; return 0; }
r[0]=0x00000054u;
goto P_0c09af00;
P_0c09af00: /* original 430b, guest PC 0x0c09af00 */
if(!s->budget--) { s->failed_pc=0x0c09af00u; return 0; }
target=r[3];
r[16]=code_base|0x0c09af04u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af04u) { target=s->pc; goto dispatch; }
goto P_0c09af04;
P_0c09af02: /* original 04ee, guest PC 0x0c09af02 */
if(!s->budget--) { s->failed_pc=0x0c09af02u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09af04;
P_0c09af04: /* original e010, guest PC 0x0c09af04 */
if(!s->budget--) { s->failed_pc=0x0c09af04u; return 0; }
r[0]=0x00000010u;
goto P_0c09af06;
P_0c09af06: /* original e271, guest PC 0x0c09af06 */
if(!s->budget--) { s->failed_pc=0x0c09af06u; return 0; }
r[2]=0x00000071u;
goto P_0c09af08;
P_0c09af08: /* original 0d24, guest PC 0x0c09af08 */
if(!s->budget--) { s->failed_pc=0x0c09af08u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c09af0a;
P_0c09af0a: /* original e07d, guest PC 0x0c09af0a */
if(!s->budget--) { s->failed_pc=0x0c09af0au; return 0; }
r[0]=0x0000007du;
goto P_0c09af0c;
P_0c09af0c: /* original ee00, guest PC 0x0c09af0c */
if(!s->budget--) { s->failed_pc=0x0c09af0cu; return 0; }
r[14]=0x00000000u;
goto P_0c09af0e;
P_0c09af0e: /* original 4f26, guest PC 0x0c09af0e */
if(!s->budget--) { s->failed_pc=0x0c09af0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09af10;
P_0c09af10: /* original 1de6, guest PC 0x0c09af10 */
if(!s->budget--) { s->failed_pc=0x0c09af10u; return 0; }
write(ram,r[13]+24,r[14],4);
goto P_0c09af12;
P_0c09af12: /* original 65e3, guest PC 0x0c09af12 */
if(!s->budget--) { s->failed_pc=0x0c09af12u; return 0; }
r[5]=r[14];
goto P_0c09af14;
P_0c09af14: /* original 0de4, guest PC 0x0c09af14 */
if(!s->budget--) { s->failed_pc=0x0c09af14u; return 0; }
write(ram,r[13]+r[0],r[14],1);
goto P_0c09af16;
P_0c09af16: /* original 1de5, guest PC 0x0c09af16 */
if(!s->budget--) { s->failed_pc=0x0c09af16u; return 0; }
write(ram,r[13]+20,r[14],4);
goto P_0c09af18;
P_0c09af18: /* original 84db, guest PC 0x0c09af18 */
if(!s->budget--) { s->failed_pc=0x0c09af18u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c09af1a;
P_0c09af1a: /* original 7001, guest PC 0x0c09af1a */
if(!s->budget--) { s->failed_pc=0x0c09af1au; return 0; }
r[0]+=0x00000001u;
goto P_0c09af1c;
P_0c09af1c: /* original 80db, guest PC 0x0c09af1c */
if(!s->budget--) { s->failed_pc=0x0c09af1cu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09af1e;
P_0c09af1e: /* original 6df6, guest PC 0x0c09af1e */
if(!s->budget--) { s->failed_pc=0x0c09af1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09af20;
P_0c09af20: /* original d311, guest PC 0x0c09af20 */
if(!s->budget--) { s->failed_pc=0x0c09af20u; return 0; }
r[3]=read(ram,0x0c09af68u,4);
goto P_0c09af22;
P_0c09af22: /* original d410, guest PC 0x0c09af22 */
if(!s->budget--) { s->failed_pc=0x0c09af22u; return 0; }
r[4]=read(ram,0x0c09af64u,4);
goto P_0c09af24;
P_0c09af24: /* original 432b, guest PC 0x0c09af24 */
if(!s->budget--) { s->failed_pc=0x0c09af24u; return 0; }
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
P_0c09af26: /* original 6ef6, guest PC 0x0c09af26 */
if(!s->budget--) { s->failed_pc=0x0c09af26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09af28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09af28u; return 0; } return 1;
P_0c09af6c: /* original 2fe6, guest PC 0x0c09af6c */
if(!s->budget--) { s->failed_pc=0x0c09af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af6e;
P_0c09af6e: /* original 2fd6, guest PC 0x0c09af6e */
if(!s->budget--) { s->failed_pc=0x0c09af6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af70;
P_0c09af70: /* original 2fc6, guest PC 0x0c09af70 */
if(!s->budget--) { s->failed_pc=0x0c09af70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af72;
P_0c09af72: /* original 4f22, guest PC 0x0c09af72 */
if(!s->budget--) { s->failed_pc=0x0c09af72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09af74;
P_0c09af74: /* original d32c, guest PC 0x0c09af74 */
if(!s->budget--) { s->failed_pc=0x0c09af74u; return 0; }
r[3]=read(ram,0x0c09b028u,4);
goto P_0c09af76;
P_0c09af76: /* original 7ffc, guest PC 0x0c09af76 */
if(!s->budget--) { s->failed_pc=0x0c09af76u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09af78;
P_0c09af78: /* original 2f32, guest PC 0x0c09af78 */
if(!s->budget--) { s->failed_pc=0x0c09af78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09af7a;
P_0c09af7a: /* original dc2c, guest PC 0x0c09af7a */
if(!s->budget--) { s->failed_pc=0x0c09af7au; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09af7c;
P_0c09af7c: /* original dd2c, guest PC 0x0c09af7c */
if(!s->budget--) { s->failed_pc=0x0c09af7cu; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09af7e;
P_0c09af7e: /* original 4d0b, guest PC 0x0c09af7e */
if(!s->budget--) { s->failed_pc=0x0c09af7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c09af82u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af82u) { target=s->pc; goto dispatch; }
goto P_0c09af82;
P_0c09af80: /* original e400, guest PC 0x0c09af80 */
if(!s->budget--) { s->failed_pc=0x0c09af80u; return 0; }
r[4]=0x00000000u;
goto P_0c09af82;
P_0c09af82: /* original 6403, guest PC 0x0c09af82 */
if(!s->budget--) { s->failed_pc=0x0c09af82u; return 0; }
r[4]=r[0];
goto P_0c09af84;
P_0c09af84: /* original 5e42, guest PC 0x0c09af84 */
if(!s->budget--) { s->failed_pc=0x0c09af84u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09af86;
P_0c09af86: /* original 53c2, guest PC 0x0c09af86 */
if(!s->budget--) { s->failed_pc=0x0c09af86u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09af88;
P_0c09af88: /* original d42a, guest PC 0x0c09af88 */
if(!s->budget--) { s->failed_pc=0x0c09af88u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09af8a;
P_0c09af8a: /* original 2349, guest PC 0x0c09af8a */
if(!s->budget--) { s->failed_pc=0x0c09af8au; return 0; }
r[3]&=r[4];
goto P_0c09af8c;
P_0c09af8c: /* original 3340, guest PC 0x0c09af8c */
if(!s->budget--) { s->failed_pc=0x0c09af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09af8e;
P_0c09af8e: /* original 8b05, guest PC 0x0c09af8e */
if(!s->budget--) { s->failed_pc=0x0c09af8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09af9c; }
goto P_0c09af90;
P_0c09af90: /* original 4d0b, guest PC 0x0c09af90 */
if(!s->budget--) { s->failed_pc=0x0c09af90u; return 0; }
target=r[13];
r[16]=code_base|0x0c09af94u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af94u) { target=s->pc; goto dispatch; }
goto P_0c09af94;
P_0c09af92: /* original e401, guest PC 0x0c09af92 */
if(!s->budget--) { s->failed_pc=0x0c09af92u; return 0; }
r[4]=0x00000001u;
goto P_0c09af94;
P_0c09af94: /* original 6403, guest PC 0x0c09af94 */
if(!s->budget--) { s->failed_pc=0x0c09af94u; return 0; }
r[4]=r[0];
goto P_0c09af96;
P_0c09af96: /* original 5342, guest PC 0x0c09af96 */
if(!s->budget--) { s->failed_pc=0x0c09af96u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09af98;
P_0c09af98: /* original a008, guest PC 0x0c09af98 */
if(!s->budget--) { s->failed_pc=0x0c09af98u; return 0; }
r[14]|=r[3];
goto P_0c09afac;
P_0c09af9a: /* original 2e3b, guest PC 0x0c09af9a */
if(!s->budget--) { s->failed_pc=0x0c09af9au; return 0; }
r[14]|=r[3];
goto P_0c09af9c;
P_0c09af9c: /* original 52c2, guest PC 0x0c09af9c */
if(!s->budget--) { s->failed_pc=0x0c09af9cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09af9e;
P_0c09af9e: /* original d326, guest PC 0x0c09af9e */
if(!s->budget--) { s->failed_pc=0x0c09af9eu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afa0;
P_0c09afa0: /* original 2238, guest PC 0x0c09afa0 */
if(!s->budget--) { s->failed_pc=0x0c09afa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09afa2;
P_0c09afa2: /* original 8903, guest PC 0x0c09afa2 */
if(!s->budget--) { s->failed_pc=0x0c09afa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09afac; }
goto P_0c09afa4;
P_0c09afa4: /* original 4d0b, guest PC 0x0c09afa4 */
if(!s->budget--) { s->failed_pc=0x0c09afa4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09afa8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afa8u) { target=s->pc; goto dispatch; }
goto P_0c09afa8;
P_0c09afa6: /* original e401, guest PC 0x0c09afa6 */
if(!s->budget--) { s->failed_pc=0x0c09afa6u; return 0; }
r[4]=0x00000001u;
goto P_0c09afa8;
P_0c09afa8: /* original 6403, guest PC 0x0c09afa8 */
if(!s->budget--) { s->failed_pc=0x0c09afa8u; return 0; }
r[4]=r[0];
goto P_0c09afaa;
P_0c09afaa: /* original 5e42, guest PC 0x0c09afaa */
if(!s->budget--) { s->failed_pc=0x0c09afaau; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09afac;
P_0c09afac: /* original 63f2, guest PC 0x0c09afac */
if(!s->budget--) { s->failed_pc=0x0c09afacu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09afae;
P_0c09afae: /* original 7f04, guest PC 0x0c09afae */
if(!s->budget--) { s->failed_pc=0x0c09afaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c09afb0;
P_0c09afb0: /* original 4f26, guest PC 0x0c09afb0 */
if(!s->budget--) { s->failed_pc=0x0c09afb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09afb2;
P_0c09afb2: /* original 9038, guest PC 0x0c09afb2 */
if(!s->budget--) { s->failed_pc=0x0c09afb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b026u,2);
goto P_0c09afb4;
P_0c09afb4: /* original 03e6, guest PC 0x0c09afb4 */
if(!s->budget--) { s->failed_pc=0x0c09afb4u; return 0; }
write(ram,r[3]+r[0],r[14],4);
goto P_0c09afb6;
P_0c09afb6: /* original 60e3, guest PC 0x0c09afb6 */
if(!s->budget--) { s->failed_pc=0x0c09afb6u; return 0; }
r[0]=r[14];
goto P_0c09afb8;
P_0c09afb8: /* original 6cf6, guest PC 0x0c09afb8 */
if(!s->budget--) { s->failed_pc=0x0c09afb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09afba;
P_0c09afba: /* original 6df6, guest PC 0x0c09afba */
if(!s->budget--) { s->failed_pc=0x0c09afbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09afbc;
P_0c09afbc: /* original 000b, guest PC 0x0c09afbc */
if(!s->budget--) { s->failed_pc=0x0c09afbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09afbe: /* original 6ef6, guest PC 0x0c09afbe */
if(!s->budget--) { s->failed_pc=0x0c09afbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09afc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09afc0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
