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
int vf3_fifth_leaf_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c074854u: goto P_0c074854;
case 0x0c074856u: goto P_0c074856;
case 0x0c074858u: goto P_0c074858;
case 0x0c07485au: goto P_0c07485a;
case 0x0c07485cu: goto P_0c07485c;
case 0x0c07485eu: goto P_0c07485e;
case 0x0c074860u: goto P_0c074860;
case 0x0c074862u: goto P_0c074862;
case 0x0c074864u: goto P_0c074864;
case 0x0c074866u: goto P_0c074866;
case 0x0c074868u: goto P_0c074868;
case 0x0c07486au: goto P_0c07486a;
case 0x0c07486cu: goto P_0c07486c;
case 0x0c07486eu: goto P_0c07486e;
case 0x0c074870u: goto P_0c074870;
case 0x0c074872u: goto P_0c074872;
case 0x0c074874u: goto P_0c074874;
case 0x0c074876u: goto P_0c074876;
case 0x0c074878u: goto P_0c074878;
case 0x0c07487au: goto P_0c07487a;
case 0x0c07487cu: goto P_0c07487c;
case 0x0c07487eu: goto P_0c07487e;
case 0x0c074880u: goto P_0c074880;
case 0x0c074882u: goto P_0c074882;
case 0x0c074884u: goto P_0c074884;
case 0x0c074886u: goto P_0c074886;
case 0x0c074888u: goto P_0c074888;
case 0x0c07488au: goto P_0c07488a;
case 0x0c07488cu: goto P_0c07488c;
case 0x0c07488eu: goto P_0c07488e;
case 0x0c074890u: goto P_0c074890;
case 0x0c074892u: goto P_0c074892;
case 0x0c074894u: goto P_0c074894;
case 0x0c074896u: goto P_0c074896;
case 0x0c074898u: goto P_0c074898;
case 0x0c07489au: goto P_0c07489a;
case 0x0c07489cu: goto P_0c07489c;
case 0x0c07489eu: goto P_0c07489e;
case 0x0c0748a0u: goto P_0c0748a0;
case 0x0c0748a2u: goto P_0c0748a2;
case 0x0c0748a4u: goto P_0c0748a4;
case 0x0c0748a6u: goto P_0c0748a6;
case 0x0c074e24u: goto P_0c074e24;
case 0x0c074e26u: goto P_0c074e26;
case 0x0c074e28u: goto P_0c074e28;
case 0x0c074e2au: goto P_0c074e2a;
case 0x0c074e2cu: goto P_0c074e2c;
case 0x0c074e2eu: goto P_0c074e2e;
case 0x0c074e30u: goto P_0c074e30;
case 0x0c074e32u: goto P_0c074e32;
case 0x0c074e34u: goto P_0c074e34;
case 0x0c074e36u: goto P_0c074e36;
case 0x0c074e38u: goto P_0c074e38;
case 0x0c074e3au: goto P_0c074e3a;
case 0x0c074e3cu: goto P_0c074e3c;
case 0x0c074e3eu: goto P_0c074e3e;
case 0x0c074e40u: goto P_0c074e40;
case 0x0c074e42u: goto P_0c074e42;
case 0x0c074e44u: goto P_0c074e44;
case 0x0c074e46u: goto P_0c074e46;
case 0x0c074e48u: goto P_0c074e48;
case 0x0c074e4au: goto P_0c074e4a;
case 0x0c074e4cu: goto P_0c074e4c;
case 0x0c074e4eu: goto P_0c074e4e;
case 0x0c074e50u: goto P_0c074e50;
case 0x0c074e52u: goto P_0c074e52;
case 0x0c074e54u: goto P_0c074e54;
case 0x0c074e56u: goto P_0c074e56;
case 0x0c074e58u: goto P_0c074e58;
case 0x0c074e5au: goto P_0c074e5a;
case 0x0c074e5cu: goto P_0c074e5c;
case 0x0c074e5eu: goto P_0c074e5e;
case 0x0c074e60u: goto P_0c074e60;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c07c9ecu: goto P_0c07c9ec;
case 0x0c07c9eeu: goto P_0c07c9ee;
case 0x0c07c9f0u: goto P_0c07c9f0;
case 0x0c07c9f2u: goto P_0c07c9f2;
case 0x0c07c9f4u: goto P_0c07c9f4;
case 0x0c07c9f6u: goto P_0c07c9f6;
case 0x0c07c9f8u: goto P_0c07c9f8;
case 0x0c07c9fau: goto P_0c07c9fa;
case 0x0c07c9fcu: goto P_0c07c9fc;
case 0x0c07c9feu: goto P_0c07c9fe;
case 0x0c07ca00u: goto P_0c07ca00;
case 0x0c07ca02u: goto P_0c07ca02;
case 0x0c07ca04u: goto P_0c07ca04;
case 0x0c07ca06u: goto P_0c07ca06;
case 0x0c07ca08u: goto P_0c07ca08;
case 0x0c07ca0au: goto P_0c07ca0a;
case 0x0c07ca0cu: goto P_0c07ca0c;
case 0x0c07ca0eu: goto P_0c07ca0e;
case 0x0c07ca10u: goto P_0c07ca10;
case 0x0c07ca12u: goto P_0c07ca12;
case 0x0c07ca14u: goto P_0c07ca14;
case 0x0c07ca16u: goto P_0c07ca16;
case 0x0c07ca18u: goto P_0c07ca18;
case 0x0c07ca1au: goto P_0c07ca1a;
case 0x0c07ca1cu: goto P_0c07ca1c;
case 0x0c07ca1eu: goto P_0c07ca1e;
case 0x0c07ca20u: goto P_0c07ca20;
case 0x0c07ca22u: goto P_0c07ca22;
case 0x0c07ca24u: goto P_0c07ca24;
case 0x0c07ca26u: goto P_0c07ca26;
case 0x0c07ca28u: goto P_0c07ca28;
case 0x0c084faau: goto P_0c084faa;
case 0x0c084facu: goto P_0c084fac;
case 0x0c084faeu: goto P_0c084fae;
case 0x0c084fb0u: goto P_0c084fb0;
case 0x0c084fb2u: goto P_0c084fb2;
case 0x0c084fb4u: goto P_0c084fb4;
case 0x0c084fb6u: goto P_0c084fb6;
case 0x0c084fb8u: goto P_0c084fb8;
case 0x0c084fbau: goto P_0c084fba;
case 0x0c084fbcu: goto P_0c084fbc;
case 0x0c084fbeu: goto P_0c084fbe;
case 0x0c084fc0u: goto P_0c084fc0;
case 0x0c084fc2u: goto P_0c084fc2;
case 0x0c084fc4u: goto P_0c084fc4;
case 0x0c084fc6u: goto P_0c084fc6;
case 0x0c084fc8u: goto P_0c084fc8;
case 0x0c084fcau: goto P_0c084fca;
case 0x0c084fccu: goto P_0c084fcc;
case 0x0c084fceu: goto P_0c084fce;
case 0x0c084fd0u: goto P_0c084fd0;
case 0x0c084fd2u: goto P_0c084fd2;
case 0x0c084fd4u: goto P_0c084fd4;
case 0x0c084fd6u: goto P_0c084fd6;
case 0x0c084fd8u: goto P_0c084fd8;
case 0x0c084fdau: goto P_0c084fda;
case 0x0c084fdcu: goto P_0c084fdc;
case 0x0c084fdeu: goto P_0c084fde;
case 0x0c084fe0u: goto P_0c084fe0;
case 0x0c084fe2u: goto P_0c084fe2;
case 0x0c084fe4u: goto P_0c084fe4;
case 0x0c084fe6u: goto P_0c084fe6;
case 0x0c084fe8u: goto P_0c084fe8;
case 0x0c084feau: goto P_0c084fea;
case 0x0c084fecu: goto P_0c084fec;
case 0x0c084feeu: goto P_0c084fee;
case 0x0c084ff0u: goto P_0c084ff0;
case 0x0c08b430u: goto P_0c08b430;
case 0x0c08b432u: goto P_0c08b432;
case 0x0c08b434u: goto P_0c08b434;
case 0x0c08b436u: goto P_0c08b436;
case 0x0c08b438u: goto P_0c08b438;
case 0x0c08b43au: goto P_0c08b43a;
case 0x0c08b43cu: goto P_0c08b43c;
case 0x0c08b43eu: goto P_0c08b43e;
case 0x0c08b440u: goto P_0c08b440;
case 0x0c08b442u: goto P_0c08b442;
case 0x0c08b444u: goto P_0c08b444;
case 0x0c08b446u: goto P_0c08b446;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
case 0x0c08b5aeu: goto P_0c08b5ae;
case 0x0c08b5b0u: goto P_0c08b5b0;
case 0x0c08b5b2u: goto P_0c08b5b2;
case 0x0c08b5b4u: goto P_0c08b5b4;
case 0x0c08b5b6u: goto P_0c08b5b6;
case 0x0c08b5b8u: goto P_0c08b5b8;
case 0x0c08b5bau: goto P_0c08b5ba;
case 0x0c08b5bcu: goto P_0c08b5bc;
case 0x0c08b5beu: goto P_0c08b5be;
case 0x0c08b5c0u: goto P_0c08b5c0;
case 0x0c08b5c2u: goto P_0c08b5c2;
case 0x0c08b5c4u: goto P_0c08b5c4;
case 0x0c08b5c6u: goto P_0c08b5c6;
case 0x0c08b5c8u: goto P_0c08b5c8;
case 0x0c08b5cau: goto P_0c08b5ca;
case 0x0c08b5ccu: goto P_0c08b5cc;
case 0x0c08b5ceu: goto P_0c08b5ce;
case 0x0c08b5d0u: goto P_0c08b5d0;
case 0x0c08b5d2u: goto P_0c08b5d2;
case 0x0c08b5d4u: goto P_0c08b5d4;
case 0x0c08b5d6u: goto P_0c08b5d6;
case 0x0c08b5d8u: goto P_0c08b5d8;
case 0x0c091dbeu: goto P_0c091dbe;
case 0x0c091dc0u: goto P_0c091dc0;
case 0x0c091dc2u: goto P_0c091dc2;
case 0x0c091dc4u: goto P_0c091dc4;
case 0x0c091dc6u: goto P_0c091dc6;
case 0x0c091dc8u: goto P_0c091dc8;
case 0x0c091dcau: goto P_0c091dca;
case 0x0c091dccu: goto P_0c091dcc;
case 0x0c091dceu: goto P_0c091dce;
case 0x0c091dd0u: goto P_0c091dd0;
case 0x0c091dd2u: goto P_0c091dd2;
case 0x0c091dd4u: goto P_0c091dd4;
case 0x0c091dd6u: goto P_0c091dd6;
case 0x0c091dd8u: goto P_0c091dd8;
case 0x0c091ddau: goto P_0c091dda;
case 0x0c091ddcu: goto P_0c091ddc;
case 0x0c091ddeu: goto P_0c091dde;
case 0x0c091de0u: goto P_0c091de0;
case 0x0c091de2u: goto P_0c091de2;
case 0x0c091de4u: goto P_0c091de4;
case 0x0c092270u: goto P_0c092270;
case 0x0c092272u: goto P_0c092272;
case 0x0c092274u: goto P_0c092274;
case 0x0c092276u: goto P_0c092276;
case 0x0c092278u: goto P_0c092278;
case 0x0c09227au: goto P_0c09227a;
case 0x0c09227cu: goto P_0c09227c;
case 0x0c09227eu: goto P_0c09227e;
case 0x0c092280u: goto P_0c092280;
case 0x0c092282u: goto P_0c092282;
case 0x0c092284u: goto P_0c092284;
case 0x0c092286u: goto P_0c092286;
case 0x0c092288u: goto P_0c092288;
case 0x0c09228au: goto P_0c09228a;
case 0x0c09228cu: goto P_0c09228c;
case 0x0c09228eu: goto P_0c09228e;
case 0x0c092290u: goto P_0c092290;
case 0x0c092292u: goto P_0c092292;
case 0x0c092294u: goto P_0c092294;
case 0x0c092296u: goto P_0c092296;
case 0x0c092298u: goto P_0c092298;
case 0x0c09229au: goto P_0c09229a;
case 0x0c09229cu: goto P_0c09229c;
case 0x0c09229eu: goto P_0c09229e;
case 0x0c0922a0u: goto P_0c0922a0;
case 0x0c0922a2u: goto P_0c0922a2;
case 0x0c0922a4u: goto P_0c0922a4;
case 0x0c0922a6u: goto P_0c0922a6;
case 0x0c0924bcu: goto P_0c0924bc;
case 0x0c0924beu: goto P_0c0924be;
case 0x0c0924c0u: goto P_0c0924c0;
case 0x0c0924c2u: goto P_0c0924c2;
case 0x0c0924c4u: goto P_0c0924c4;
case 0x0c0924c6u: goto P_0c0924c6;
case 0x0c0924c8u: goto P_0c0924c8;
case 0x0c0924cau: goto P_0c0924ca;
case 0x0c0924ccu: goto P_0c0924cc;
case 0x0c0924ceu: goto P_0c0924ce;
case 0x0c092550u: goto P_0c092550;
case 0x0c092552u: goto P_0c092552;
case 0x0c092554u: goto P_0c092554;
case 0x0c092556u: goto P_0c092556;
case 0x0c092558u: goto P_0c092558;
case 0x0c09255au: goto P_0c09255a;
case 0x0c09255cu: goto P_0c09255c;
case 0x0c09255eu: goto P_0c09255e;
case 0x0c092560u: goto P_0c092560;
case 0x0c092562u: goto P_0c092562;
case 0x0c092564u: goto P_0c092564;
case 0x0c092566u: goto P_0c092566;
case 0x0c092568u: goto P_0c092568;
case 0x0c0926bau: goto P_0c0926ba;
case 0x0c0926bcu: goto P_0c0926bc;
case 0x0c0926beu: goto P_0c0926be;
case 0x0c0926c0u: goto P_0c0926c0;
case 0x0c0926c2u: goto P_0c0926c2;
case 0x0c0926c4u: goto P_0c0926c4;
case 0x0c0926c6u: goto P_0c0926c6;
case 0x0c0926c8u: goto P_0c0926c8;
case 0x0c0926cau: goto P_0c0926ca;
case 0x0c092b8cu: goto P_0c092b8c;
case 0x0c092b8eu: goto P_0c092b8e;
case 0x0c092b90u: goto P_0c092b90;
case 0x0c092b92u: goto P_0c092b92;
case 0x0c092b94u: goto P_0c092b94;
case 0x0c092b96u: goto P_0c092b96;
case 0x0c092b98u: goto P_0c092b98;
case 0x0c092b9au: goto P_0c092b9a;
case 0x0c092b9cu: goto P_0c092b9c;
case 0x0c092b9eu: goto P_0c092b9e;
case 0x0c092ba0u: goto P_0c092ba0;
case 0x0c092ba2u: goto P_0c092ba2;
case 0x0c092ba4u: goto P_0c092ba4;
case 0x0c092ba6u: goto P_0c092ba6;
case 0x0c092ba8u: goto P_0c092ba8;
case 0x0c092baau: goto P_0c092baa;
case 0x0c092bacu: goto P_0c092bac;
case 0x0c092bb4u: goto P_0c092bb4;
case 0x0c092bb6u: goto P_0c092bb6;
case 0x0c092bb8u: goto P_0c092bb8;
case 0x0c092bbau: goto P_0c092bba;
case 0x0c092bbcu: goto P_0c092bbc;
case 0x0c092bbeu: goto P_0c092bbe;
case 0x0c092bc0u: goto P_0c092bc0;
case 0x0c092bc2u: goto P_0c092bc2;
case 0x0c092bc4u: goto P_0c092bc4;
case 0x0c092bc6u: goto P_0c092bc6;
case 0x0c092bc8u: goto P_0c092bc8;
case 0x0c092bcau: goto P_0c092bca;
case 0x0c092bccu: goto P_0c092bcc;
case 0x0c092bceu: goto P_0c092bce;
case 0x0c092bd0u: goto P_0c092bd0;
case 0x0c092bd2u: goto P_0c092bd2;
case 0x0c092bd4u: goto P_0c092bd4;
case 0x0c092bd6u: goto P_0c092bd6;
case 0x0c092bd8u: goto P_0c092bd8;
case 0x0c092bdau: goto P_0c092bda;
case 0x0c092bdcu: goto P_0c092bdc;
case 0x0c092bdeu: goto P_0c092bde;
case 0x0c092be0u: goto P_0c092be0;
case 0x0c092be2u: goto P_0c092be2;
case 0x0c092be4u: goto P_0c092be4;
case 0x0c092be6u: goto P_0c092be6;
case 0x0c092be8u: goto P_0c092be8;
case 0x0c092beau: goto P_0c092bea;
case 0x0c092becu: goto P_0c092bec;
case 0x0c092beeu: goto P_0c092bee;
case 0x0c092bf0u: goto P_0c092bf0;
case 0x0c092bf2u: goto P_0c092bf2;
case 0x0c092bf4u: goto P_0c092bf4;
case 0x0c092bf6u: goto P_0c092bf6;
case 0x0c092bf8u: goto P_0c092bf8;
case 0x0c092bfau: goto P_0c092bfa;
case 0x0c092bfcu: goto P_0c092bfc;
case 0x0c092bfeu: goto P_0c092bfe;
case 0x0c092c04u: goto P_0c092c04;
case 0x0c092c06u: goto P_0c092c06;
case 0x0c092c08u: goto P_0c092c08;
case 0x0c092c0au: goto P_0c092c0a;
case 0x0c092c0cu: goto P_0c092c0c;
case 0x0c092c0eu: goto P_0c092c0e;
case 0x0c092c10u: goto P_0c092c10;
case 0x0c092c12u: goto P_0c092c12;
case 0x0c092c14u: goto P_0c092c14;
case 0x0c092c16u: goto P_0c092c16;
case 0x0c092c18u: goto P_0c092c18;
case 0x0c092c1au: goto P_0c092c1a;
case 0x0c092c1cu: goto P_0c092c1c;
case 0x0c092c1eu: goto P_0c092c1e;
case 0x0c092c20u: goto P_0c092c20;
case 0x0c092c22u: goto P_0c092c22;
case 0x0c092c24u: goto P_0c092c24;
case 0x0c092c26u: goto P_0c092c26;
case 0x0c092c28u: goto P_0c092c28;
case 0x0c092c2au: goto P_0c092c2a;
case 0x0c092c2cu: goto P_0c092c2c;
case 0x0c092c2eu: goto P_0c092c2e;
case 0x0c092c30u: goto P_0c092c30;
case 0x0c092c32u: goto P_0c092c32;
case 0x0c092c34u: goto P_0c092c34;
case 0x0c092c36u: goto P_0c092c36;
case 0x0c092c38u: goto P_0c092c38;
case 0x0c092c3au: goto P_0c092c3a;
case 0x0c092c3cu: goto P_0c092c3c;
case 0x0c092ebcu: goto P_0c092ebc;
case 0x0c092ebeu: goto P_0c092ebe;
case 0x0c092ec0u: goto P_0c092ec0;
case 0x0c092ec2u: goto P_0c092ec2;
case 0x0c092ec4u: goto P_0c092ec4;
case 0x0c092ec6u: goto P_0c092ec6;
case 0x0c092ec8u: goto P_0c092ec8;
case 0x0c092ecau: goto P_0c092eca;
case 0x0c092eccu: goto P_0c092ecc;
case 0x0c092eceu: goto P_0c092ece;
case 0x0c092ed0u: goto P_0c092ed0;
case 0x0c092ed2u: goto P_0c092ed2;
case 0x0c092ed4u: goto P_0c092ed4;
case 0x0c092ed6u: goto P_0c092ed6;
case 0x0c092ed8u: goto P_0c092ed8;
case 0x0c092edau: goto P_0c092eda;
case 0x0c092edcu: goto P_0c092edc;
case 0x0c092edeu: goto P_0c092ede;
case 0x0c092ee0u: goto P_0c092ee0;
case 0x0c092ee2u: goto P_0c092ee2;
case 0x0c092ee4u: goto P_0c092ee4;
case 0x0c092ee6u: goto P_0c092ee6;
case 0x0c092ee8u: goto P_0c092ee8;
case 0x0c092eeau: goto P_0c092eea;
case 0x0c092eecu: goto P_0c092eec;
case 0x0c092eeeu: goto P_0c092eee;
case 0x0c092ef0u: goto P_0c092ef0;
case 0x0c092ef2u: goto P_0c092ef2;
case 0x0c092ef4u: goto P_0c092ef4;
case 0x0c092f00u: goto P_0c092f00;
case 0x0c092f02u: goto P_0c092f02;
case 0x0c092f04u: goto P_0c092f04;
case 0x0c092f06u: goto P_0c092f06;
case 0x0c092f08u: goto P_0c092f08;
case 0x0c092f0au: goto P_0c092f0a;
case 0x0c092f0cu: goto P_0c092f0c;
case 0x0c092f0eu: goto P_0c092f0e;
case 0x0c092f10u: goto P_0c092f10;
case 0x0c092f12u: goto P_0c092f12;
case 0x0c092f14u: goto P_0c092f14;
case 0x0c092f16u: goto P_0c092f16;
case 0x0c092f18u: goto P_0c092f18;
case 0x0c092f1au: goto P_0c092f1a;
case 0x0c09318eu: goto P_0c09318e;
case 0x0c093190u: goto P_0c093190;
case 0x0c093192u: goto P_0c093192;
case 0x0c093194u: goto P_0c093194;
case 0x0c093196u: goto P_0c093196;
case 0x0c093198u: goto P_0c093198;
case 0x0c09319au: goto P_0c09319a;
case 0x0c09319cu: goto P_0c09319c;
case 0x0c09319eu: goto P_0c09319e;
case 0x0c0931a0u: goto P_0c0931a0;
case 0x0c0931a2u: goto P_0c0931a2;
case 0x0c0931a4u: goto P_0c0931a4;
case 0x0c0931a6u: goto P_0c0931a6;
case 0x0c0931a8u: goto P_0c0931a8;
case 0x0c0931aau: goto P_0c0931aa;
case 0x0c0931acu: goto P_0c0931ac;
case 0x0c0931aeu: goto P_0c0931ae;
case 0x0c0931b0u: goto P_0c0931b0;
case 0x0c0931b2u: goto P_0c0931b2;
case 0x0c0931b4u: goto P_0c0931b4;
case 0x0c0931b6u: goto P_0c0931b6;
case 0x0c0931b8u: goto P_0c0931b8;
case 0x0c0931bau: goto P_0c0931ba;
case 0x0c0931bcu: goto P_0c0931bc;
case 0x0c0931beu: goto P_0c0931be;
case 0x0c0931c0u: goto P_0c0931c0;
case 0x0c0931c2u: goto P_0c0931c2;
case 0x0c0931c4u: goto P_0c0931c4;
case 0x0c0931c6u: goto P_0c0931c6;
case 0x0c093794u: goto P_0c093794;
case 0x0c093796u: goto P_0c093796;
case 0x0c093798u: goto P_0c093798;
case 0x0c09379au: goto P_0c09379a;
case 0x0c09379cu: goto P_0c09379c;
case 0x0c09379eu: goto P_0c09379e;
case 0x0c0937a0u: goto P_0c0937a0;
case 0x0c0937a2u: goto P_0c0937a2;
case 0x0c0937a4u: goto P_0c0937a4;
case 0x0c0937a6u: goto P_0c0937a6;
case 0x0c0937a8u: goto P_0c0937a8;
case 0x0c0937aau: goto P_0c0937aa;
case 0x0c0937acu: goto P_0c0937ac;
case 0x0c0937aeu: goto P_0c0937ae;
case 0x0c0937b0u: goto P_0c0937b0;
case 0x0c0937b2u: goto P_0c0937b2;
case 0x0c0937b4u: goto P_0c0937b4;
case 0x0c0937b6u: goto P_0c0937b6;
case 0x0c0937b8u: goto P_0c0937b8;
case 0x0c0937bau: goto P_0c0937ba;
case 0x0c0937bcu: goto P_0c0937bc;
case 0x0c0937beu: goto P_0c0937be;
case 0x0c0937c0u: goto P_0c0937c0;
case 0x0c0937c2u: goto P_0c0937c2;
case 0x0c0937c4u: goto P_0c0937c4;
case 0x0c0937c6u: goto P_0c0937c6;
case 0x0c0937c8u: goto P_0c0937c8;
case 0x0c0937cau: goto P_0c0937ca;
case 0x0c0937ccu: goto P_0c0937cc;
case 0x0c0937ceu: goto P_0c0937ce;
case 0x0c0937d4u: goto P_0c0937d4;
case 0x0c0937d6u: goto P_0c0937d6;
case 0x0c0937d8u: goto P_0c0937d8;
case 0x0c0937dau: goto P_0c0937da;
case 0x0c0937dcu: goto P_0c0937dc;
case 0x0c0937deu: goto P_0c0937de;
case 0x0c0937e0u: goto P_0c0937e0;
case 0x0c0937e2u: goto P_0c0937e2;
case 0x0c0937e4u: goto P_0c0937e4;
case 0x0c0937e6u: goto P_0c0937e6;
case 0x0c0937e8u: goto P_0c0937e8;
case 0x0c0937eau: goto P_0c0937ea;
case 0x0c0937ecu: goto P_0c0937ec;
case 0x0c0937eeu: goto P_0c0937ee;
case 0x0c0937f0u: goto P_0c0937f0;
case 0x0c0937f2u: goto P_0c0937f2;
case 0x0c0937f4u: goto P_0c0937f4;
case 0x0c0937f6u: goto P_0c0937f6;
case 0x0c0937f8u: goto P_0c0937f8;
case 0x0c0937fau: goto P_0c0937fa;
case 0x0c0937fcu: goto P_0c0937fc;
case 0x0c0937feu: goto P_0c0937fe;
case 0x0c093800u: goto P_0c093800;
case 0x0c093802u: goto P_0c093802;
case 0x0c093804u: goto P_0c093804;
case 0x0c093806u: goto P_0c093806;
case 0x0c093808u: goto P_0c093808;
case 0x0c09380au: goto P_0c09380a;
case 0x0c09380cu: goto P_0c09380c;
case 0x0c09380eu: goto P_0c09380e;
case 0x0c093810u: goto P_0c093810;
case 0x0c093812u: goto P_0c093812;
case 0x0c093814u: goto P_0c093814;
case 0x0c093816u: goto P_0c093816;
case 0x0c093818u: goto P_0c093818;
case 0x0c09381au: goto P_0c09381a;
case 0x0c09381cu: goto P_0c09381c;
case 0x0c09381eu: goto P_0c09381e;
case 0x0c093820u: goto P_0c093820;
case 0x0c093822u: goto P_0c093822;
case 0x0c093824u: goto P_0c093824;
case 0x0c093826u: goto P_0c093826;
case 0x0c093828u: goto P_0c093828;
case 0x0c0938acu: goto P_0c0938ac;
case 0x0c0938aeu: goto P_0c0938ae;
case 0x0c0938b0u: goto P_0c0938b0;
case 0x0c0938b2u: goto P_0c0938b2;
case 0x0c0938b4u: goto P_0c0938b4;
case 0x0c0938b6u: goto P_0c0938b6;
case 0x0c0938b8u: goto P_0c0938b8;
case 0x0c0938bau: goto P_0c0938ba;
case 0x0c0938bcu: goto P_0c0938bc;
case 0x0c0938beu: goto P_0c0938be;
case 0x0c0938c0u: goto P_0c0938c0;
case 0x0c0938c2u: goto P_0c0938c2;
case 0x0c0938c4u: goto P_0c0938c4;
case 0x0c0938c6u: goto P_0c0938c6;
case 0x0c0938c8u: goto P_0c0938c8;
case 0x0c0938cau: goto P_0c0938ca;
case 0x0c0938ccu: goto P_0c0938cc;
case 0x0c0938ceu: goto P_0c0938ce;
case 0x0c0938d0u: goto P_0c0938d0;
case 0x0c0938d2u: goto P_0c0938d2;
case 0x0c0938d4u: goto P_0c0938d4;
case 0x0c0938d6u: goto P_0c0938d6;
case 0x0c0938d8u: goto P_0c0938d8;
case 0x0c0938dau: goto P_0c0938da;
case 0x0c0938dcu: goto P_0c0938dc;
case 0x0c0938deu: goto P_0c0938de;
case 0x0c0938e0u: goto P_0c0938e0;
case 0x0c0938e2u: goto P_0c0938e2;
case 0x0c0938e4u: goto P_0c0938e4;
case 0x0c0938e6u: goto P_0c0938e6;
case 0x0c0938e8u: goto P_0c0938e8;
case 0x0c0938eau: goto P_0c0938ea;
case 0x0c0938ecu: goto P_0c0938ec;
case 0x0c0938eeu: goto P_0c0938ee;
case 0x0c0938f0u: goto P_0c0938f0;
case 0x0c0938f2u: goto P_0c0938f2;
case 0x0c0938f4u: goto P_0c0938f4;
case 0x0c0938f6u: goto P_0c0938f6;
case 0x0c0938f8u: goto P_0c0938f8;
case 0x0c0938fau: goto P_0c0938fa;
case 0x0c0938fcu: goto P_0c0938fc;
case 0x0c0938feu: goto P_0c0938fe;
case 0x0c093900u: goto P_0c093900;
case 0x0c093902u: goto P_0c093902;
case 0x0c093904u: goto P_0c093904;
case 0x0c093906u: goto P_0c093906;
case 0x0c093908u: goto P_0c093908;
case 0x0c09390au: goto P_0c09390a;
case 0x0c09390cu: goto P_0c09390c;
case 0x0c09390eu: goto P_0c09390e;
case 0x0c093910u: goto P_0c093910;
case 0x0c093912u: goto P_0c093912;
case 0x0c093914u: goto P_0c093914;
case 0x0c093916u: goto P_0c093916;
case 0x0c093918u: goto P_0c093918;
case 0x0c09391au: goto P_0c09391a;
case 0x0c09391cu: goto P_0c09391c;
case 0x0c09391eu: goto P_0c09391e;
case 0x0c093920u: goto P_0c093920;
case 0x0c093922u: goto P_0c093922;
case 0x0c093924u: goto P_0c093924;
case 0x0c093926u: goto P_0c093926;
case 0x0c093928u: goto P_0c093928;
case 0x0c09392au: goto P_0c09392a;
case 0x0c09392cu: goto P_0c09392c;
case 0x0c09392eu: goto P_0c09392e;
case 0x0c093930u: goto P_0c093930;
case 0x0c093932u: goto P_0c093932;
case 0x0c093934u: goto P_0c093934;
case 0x0c093936u: goto P_0c093936;
case 0x0c093938u: goto P_0c093938;
case 0x0c09393au: goto P_0c09393a;
case 0x0c09393cu: goto P_0c09393c;
case 0x0c09393eu: goto P_0c09393e;
case 0x0c093940u: goto P_0c093940;
case 0x0c093942u: goto P_0c093942;
case 0x0c093944u: goto P_0c093944;
case 0x0c093946u: goto P_0c093946;
case 0x0c093948u: goto P_0c093948;
case 0x0c09394au: goto P_0c09394a;
case 0x0c09394cu: goto P_0c09394c;
case 0x0c09394eu: goto P_0c09394e;
case 0x0c093950u: goto P_0c093950;
case 0x0c093952u: goto P_0c093952;
case 0x0c093954u: goto P_0c093954;
case 0x0c093956u: goto P_0c093956;
case 0x0c093958u: goto P_0c093958;
case 0x0c09395au: goto P_0c09395a;
case 0x0c09395cu: goto P_0c09395c;
case 0x0c093964u: goto P_0c093964;
case 0x0c093966u: goto P_0c093966;
case 0x0c093968u: goto P_0c093968;
case 0x0c09396au: goto P_0c09396a;
case 0x0c09396cu: goto P_0c09396c;
case 0x0c09396eu: goto P_0c09396e;
case 0x0c093970u: goto P_0c093970;
case 0x0c093972u: goto P_0c093972;
case 0x0c093974u: goto P_0c093974;
case 0x0c093976u: goto P_0c093976;
case 0x0c093978u: goto P_0c093978;
case 0x0c09397au: goto P_0c09397a;
case 0x0c09397cu: goto P_0c09397c;
case 0x0c09397eu: goto P_0c09397e;
case 0x0c093980u: goto P_0c093980;
case 0x0c093982u: goto P_0c093982;
case 0x0c093984u: goto P_0c093984;
case 0x0c093986u: goto P_0c093986;
case 0x0c093988u: goto P_0c093988;
case 0x0c09398au: goto P_0c09398a;
case 0x0c09398cu: goto P_0c09398c;
case 0x0c09398eu: goto P_0c09398e;
case 0x0c093990u: goto P_0c093990;
case 0x0c093992u: goto P_0c093992;
case 0x0c093994u: goto P_0c093994;
case 0x0c093996u: goto P_0c093996;
case 0x0c093998u: goto P_0c093998;
case 0x0c09399au: goto P_0c09399a;
case 0x0c09399cu: goto P_0c09399c;
case 0x0c09399eu: goto P_0c09399e;
case 0x0c0939a0u: goto P_0c0939a0;
case 0x0c0939a2u: goto P_0c0939a2;
case 0x0c0939a4u: goto P_0c0939a4;
case 0x0c0939a6u: goto P_0c0939a6;
case 0x0c0939a8u: goto P_0c0939a8;
case 0x0c0939aau: goto P_0c0939aa;
case 0x0c0939acu: goto P_0c0939ac;
case 0x0c0939aeu: goto P_0c0939ae;
case 0x0c0939b0u: goto P_0c0939b0;
case 0x0c0939b2u: goto P_0c0939b2;
case 0x0c0939b4u: goto P_0c0939b4;
case 0x0c0939b6u: goto P_0c0939b6;
case 0x0c0939b8u: goto P_0c0939b8;
case 0x0c0939bau: goto P_0c0939ba;
case 0x0c0939bcu: goto P_0c0939bc;
case 0x0c0939beu: goto P_0c0939be;
case 0x0c0939c0u: goto P_0c0939c0;
case 0x0c0939c2u: goto P_0c0939c2;
case 0x0c0939c4u: goto P_0c0939c4;
case 0x0c0939c6u: goto P_0c0939c6;
case 0x0c0939c8u: goto P_0c0939c8;
case 0x0c0939cau: goto P_0c0939ca;
case 0x0c0939ccu: goto P_0c0939cc;
case 0x0c0939ceu: goto P_0c0939ce;
case 0x0c0939d0u: goto P_0c0939d0;
case 0x0c0939d2u: goto P_0c0939d2;
case 0x0c0939d4u: goto P_0c0939d4;
case 0x0c0939d6u: goto P_0c0939d6;
case 0x0c0939d8u: goto P_0c0939d8;
case 0x0c0939dau: goto P_0c0939da;
case 0x0c0939dcu: goto P_0c0939dc;
case 0x0c0939deu: goto P_0c0939de;
case 0x0c0939e0u: goto P_0c0939e0;
case 0x0c0939e2u: goto P_0c0939e2;
case 0x0c0939e4u: goto P_0c0939e4;
case 0x0c0939e6u: goto P_0c0939e6;
case 0x0c0939e8u: goto P_0c0939e8;
case 0x0c0939eau: goto P_0c0939ea;
case 0x0c0939ecu: goto P_0c0939ec;
case 0x0c0939eeu: goto P_0c0939ee;
case 0x0c0939f0u: goto P_0c0939f0;
case 0x0c093a04u: goto P_0c093a04;
case 0x0c093a06u: goto P_0c093a06;
case 0x0c093a08u: goto P_0c093a08;
case 0x0c093a0au: goto P_0c093a0a;
case 0x0c093a0cu: goto P_0c093a0c;
case 0x0c093a0eu: goto P_0c093a0e;
case 0x0c093a10u: goto P_0c093a10;
case 0x0c093a12u: goto P_0c093a12;
case 0x0c093a14u: goto P_0c093a14;
case 0x0c093a16u: goto P_0c093a16;
case 0x0c093a18u: goto P_0c093a18;
case 0x0c093a1au: goto P_0c093a1a;
case 0x0c093a1cu: goto P_0c093a1c;
case 0x0c093a1eu: goto P_0c093a1e;
case 0x0c093a20u: goto P_0c093a20;
case 0x0c093a22u: goto P_0c093a22;
case 0x0c093a24u: goto P_0c093a24;
case 0x0c093a26u: goto P_0c093a26;
case 0x0c093a28u: goto P_0c093a28;
case 0x0c093a2au: goto P_0c093a2a;
case 0x0c093a2cu: goto P_0c093a2c;
case 0x0c093a2eu: goto P_0c093a2e;
case 0x0c093a30u: goto P_0c093a30;
case 0x0c093a32u: goto P_0c093a32;
case 0x0c093a34u: goto P_0c093a34;
case 0x0c093a36u: goto P_0c093a36;
case 0x0c093a38u: goto P_0c093a38;
case 0x0c093a3au: goto P_0c093a3a;
case 0x0c093a3cu: goto P_0c093a3c;
case 0x0c093a3eu: goto P_0c093a3e;
case 0x0c093a40u: goto P_0c093a40;
case 0x0c093a70u: goto P_0c093a70;
case 0x0c093a72u: goto P_0c093a72;
case 0x0c093a74u: goto P_0c093a74;
case 0x0c093a76u: goto P_0c093a76;
case 0x0c093a78u: goto P_0c093a78;
case 0x0c093a7au: goto P_0c093a7a;
case 0x0c093a7cu: goto P_0c093a7c;
case 0x0c093a7eu: goto P_0c093a7e;
case 0x0c093a80u: goto P_0c093a80;
case 0x0c093a82u: goto P_0c093a82;
case 0x0c093a84u: goto P_0c093a84;
case 0x0c093a86u: goto P_0c093a86;
case 0x0c093a88u: goto P_0c093a88;
case 0x0c093a8au: goto P_0c093a8a;
case 0x0c093a8cu: goto P_0c093a8c;
case 0x0c093a8eu: goto P_0c093a8e;
case 0x0c093a90u: goto P_0c093a90;
case 0x0c093a92u: goto P_0c093a92;
case 0x0c093a94u: goto P_0c093a94;
case 0x0c093a96u: goto P_0c093a96;
case 0x0c093a98u: goto P_0c093a98;
case 0x0c093a9au: goto P_0c093a9a;
case 0x0c093ad0u: goto P_0c093ad0;
case 0x0c093ad2u: goto P_0c093ad2;
case 0x0c093ad4u: goto P_0c093ad4;
case 0x0c093ad6u: goto P_0c093ad6;
case 0x0c093ad8u: goto P_0c093ad8;
case 0x0c093adau: goto P_0c093ada;
case 0x0c093adcu: goto P_0c093adc;
case 0x0c093adeu: goto P_0c093ade;
case 0x0c093ae0u: goto P_0c093ae0;
case 0x0c093ae2u: goto P_0c093ae2;
case 0x0c093ae4u: goto P_0c093ae4;
case 0x0c093ae6u: goto P_0c093ae6;
case 0x0c093ae8u: goto P_0c093ae8;
case 0x0c093aeau: goto P_0c093aea;
case 0x0c093aecu: goto P_0c093aec;
case 0x0c093aeeu: goto P_0c093aee;
case 0x0c093af0u: goto P_0c093af0;
case 0x0c093af2u: goto P_0c093af2;
case 0x0c093af4u: goto P_0c093af4;
case 0x0c093af6u: goto P_0c093af6;
case 0x0c093af8u: goto P_0c093af8;
case 0x0c093afau: goto P_0c093afa;
case 0x0c093afcu: goto P_0c093afc;
case 0x0c093afeu: goto P_0c093afe;
case 0x0c093b00u: goto P_0c093b00;
case 0x0c093b02u: goto P_0c093b02;
case 0x0c093b04u: goto P_0c093b04;
case 0x0c093b06u: goto P_0c093b06;
case 0x0c093b08u: goto P_0c093b08;
case 0x0c093b10u: goto P_0c093b10;
case 0x0c093b12u: goto P_0c093b12;
case 0x0c093b14u: goto P_0c093b14;
case 0x0c093b16u: goto P_0c093b16;
case 0x0c093b18u: goto P_0c093b18;
case 0x0c093b1au: goto P_0c093b1a;
case 0x0c093b1cu: goto P_0c093b1c;
case 0x0c093b1eu: goto P_0c093b1e;
case 0x0c093b20u: goto P_0c093b20;
case 0x0c093b22u: goto P_0c093b22;
case 0x0c093b24u: goto P_0c093b24;
case 0x0c093b26u: goto P_0c093b26;
case 0x0c093b28u: goto P_0c093b28;
case 0x0c093b2au: goto P_0c093b2a;
case 0x0c093b2cu: goto P_0c093b2c;
case 0x0c093b2eu: goto P_0c093b2e;
case 0x0c093b30u: goto P_0c093b30;
case 0x0c093b32u: goto P_0c093b32;
case 0x0c093b34u: goto P_0c093b34;
case 0x0c093b36u: goto P_0c093b36;
case 0x0c093b38u: goto P_0c093b38;
case 0x0c093b3au: goto P_0c093b3a;
case 0x0c093b3cu: goto P_0c093b3c;
case 0x0c093b3eu: goto P_0c093b3e;
case 0x0c093b40u: goto P_0c093b40;
case 0x0c093b42u: goto P_0c093b42;
case 0x0c093b44u: goto P_0c093b44;
case 0x0c093b46u: goto P_0c093b46;
case 0x0c093b48u: goto P_0c093b48;
case 0x0c093b4au: goto P_0c093b4a;
case 0x0c093b4cu: goto P_0c093b4c;
case 0x0c093b4eu: goto P_0c093b4e;
case 0x0c093b50u: goto P_0c093b50;
case 0x0c093b52u: goto P_0c093b52;
case 0x0c094242u: goto P_0c094242;
case 0x0c094244u: goto P_0c094244;
case 0x0c094246u: goto P_0c094246;
case 0x0c094248u: goto P_0c094248;
case 0x0c09424au: goto P_0c09424a;
case 0x0c09424cu: goto P_0c09424c;
case 0x0c09424eu: goto P_0c09424e;
case 0x0c094250u: goto P_0c094250;
case 0x0c094252u: goto P_0c094252;
case 0x0c094254u: goto P_0c094254;
case 0x0c094256u: goto P_0c094256;
case 0x0c094258u: goto P_0c094258;
case 0x0c09425au: goto P_0c09425a;
case 0x0c09425cu: goto P_0c09425c;
case 0x0c09425eu: goto P_0c09425e;
case 0x0c094260u: goto P_0c094260;
case 0x0c094262u: goto P_0c094262;
case 0x0c094264u: goto P_0c094264;
case 0x0c094266u: goto P_0c094266;
case 0x0c094268u: goto P_0c094268;
case 0x0c09426au: goto P_0c09426a;
case 0x0c09426cu: goto P_0c09426c;
case 0x0c09426eu: goto P_0c09426e;
case 0x0c094270u: goto P_0c094270;
case 0x0c094272u: goto P_0c094272;
case 0x0c094274u: goto P_0c094274;
case 0x0c094276u: goto P_0c094276;
case 0x0c094278u: goto P_0c094278;
case 0x0c09427au: goto P_0c09427a;
case 0x0c09427cu: goto P_0c09427c;
case 0x0c09427eu: goto P_0c09427e;
case 0x0c094280u: goto P_0c094280;
case 0x0c094282u: goto P_0c094282;
case 0x0c094284u: goto P_0c094284;
case 0x0c094286u: goto P_0c094286;
case 0x0c094288u: goto P_0c094288;
case 0x0c09428au: goto P_0c09428a;
case 0x0c09428cu: goto P_0c09428c;
case 0x0c09428eu: goto P_0c09428e;
case 0x0c094290u: goto P_0c094290;
case 0x0c094292u: goto P_0c094292;
case 0x0c094294u: goto P_0c094294;
case 0x0c094296u: goto P_0c094296;
case 0x0c094298u: goto P_0c094298;
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
case 0x0c095608u: goto P_0c095608;
case 0x0c09560au: goto P_0c09560a;
case 0x0c09560cu: goto P_0c09560c;
case 0x0c09560eu: goto P_0c09560e;
case 0x0c095610u: goto P_0c095610;
case 0x0c095612u: goto P_0c095612;
case 0x0c095614u: goto P_0c095614;
case 0x0c095616u: goto P_0c095616;
case 0x0c095618u: goto P_0c095618;
case 0x0c09561au: goto P_0c09561a;
case 0x0c09561cu: goto P_0c09561c;
case 0x0c09561eu: goto P_0c09561e;
case 0x0c095620u: goto P_0c095620;
case 0x0c095622u: goto P_0c095622;
case 0x0c095624u: goto P_0c095624;
case 0x0c095626u: goto P_0c095626;
case 0x0c095628u: goto P_0c095628;
case 0x0c09562au: goto P_0c09562a;
case 0x0c09562cu: goto P_0c09562c;
case 0x0c09562eu: goto P_0c09562e;
case 0x0c095630u: goto P_0c095630;
case 0x0c095632u: goto P_0c095632;
case 0x0c095634u: goto P_0c095634;
case 0x0c095636u: goto P_0c095636;
case 0x0c095638u: goto P_0c095638;
case 0x0c09563au: goto P_0c09563a;
case 0x0c09563cu: goto P_0c09563c;
case 0x0c09563eu: goto P_0c09563e;
case 0x0c095640u: goto P_0c095640;
case 0x0c095642u: goto P_0c095642;
case 0x0c095644u: goto P_0c095644;
case 0x0c095646u: goto P_0c095646;
case 0x0c095648u: goto P_0c095648;
case 0x0c09564au: goto P_0c09564a;
case 0x0c09564cu: goto P_0c09564c;
case 0x0c095652u: goto P_0c095652;
case 0x0c095654u: goto P_0c095654;
case 0x0c095656u: goto P_0c095656;
case 0x0c095658u: goto P_0c095658;
case 0x0c09565au: goto P_0c09565a;
case 0x0c09565cu: goto P_0c09565c;
case 0x0c09565eu: goto P_0c09565e;
case 0x0c095660u: goto P_0c095660;
case 0x0c095662u: goto P_0c095662;
case 0x0c095664u: goto P_0c095664;
case 0x0c095666u: goto P_0c095666;
case 0x0c095668u: goto P_0c095668;
case 0x0c09566au: goto P_0c09566a;
case 0x0c09566cu: goto P_0c09566c;
case 0x0c09566eu: goto P_0c09566e;
case 0x0c095670u: goto P_0c095670;
case 0x0c095672u: goto P_0c095672;
case 0x0c095674u: goto P_0c095674;
case 0x0c095676u: goto P_0c095676;
case 0x0c095678u: goto P_0c095678;
case 0x0c09567au: goto P_0c09567a;
case 0x0c09567cu: goto P_0c09567c;
case 0x0c09567eu: goto P_0c09567e;
case 0x0c095680u: goto P_0c095680;
case 0x0c095682u: goto P_0c095682;
case 0x0c095684u: goto P_0c095684;
case 0x0c095686u: goto P_0c095686;
case 0x0c095688u: goto P_0c095688;
case 0x0c09568au: goto P_0c09568a;
case 0x0c09568cu: goto P_0c09568c;
case 0x0c09568eu: goto P_0c09568e;
case 0x0c095690u: goto P_0c095690;
case 0x0c095692u: goto P_0c095692;
case 0x0c095694u: goto P_0c095694;
case 0x0c095696u: goto P_0c095696;
case 0x0c095698u: goto P_0c095698;
case 0x0c09569au: goto P_0c09569a;
case 0x0c09569cu: goto P_0c09569c;
case 0x0c096650u: goto P_0c096650;
case 0x0c096652u: goto P_0c096652;
case 0x0c096654u: goto P_0c096654;
case 0x0c096656u: goto P_0c096656;
case 0x0c096658u: goto P_0c096658;
case 0x0c09665au: goto P_0c09665a;
case 0x0c09665cu: goto P_0c09665c;
case 0x0c09665eu: goto P_0c09665e;
case 0x0c096660u: goto P_0c096660;
case 0x0c096662u: goto P_0c096662;
case 0x0c096664u: goto P_0c096664;
case 0x0c096666u: goto P_0c096666;
case 0x0c096668u: goto P_0c096668;
case 0x0c09666au: goto P_0c09666a;
case 0x0c09666cu: goto P_0c09666c;
case 0x0c09666eu: goto P_0c09666e;
case 0x0c096670u: goto P_0c096670;
case 0x0c096672u: goto P_0c096672;
case 0x0c096674u: goto P_0c096674;
case 0x0c096676u: goto P_0c096676;
case 0x0c096678u: goto P_0c096678;
case 0x0c09667au: goto P_0c09667a;
case 0x0c09667cu: goto P_0c09667c;
case 0x0c09667eu: goto P_0c09667e;
case 0x0c096680u: goto P_0c096680;
case 0x0c096682u: goto P_0c096682;
case 0x0c096684u: goto P_0c096684;
case 0x0c096686u: goto P_0c096686;
case 0x0c096688u: goto P_0c096688;
case 0x0c09668au: goto P_0c09668a;
case 0x0c09668cu: goto P_0c09668c;
case 0x0c09668eu: goto P_0c09668e;
case 0x0c096690u: goto P_0c096690;
case 0x0c096692u: goto P_0c096692;
case 0x0c096694u: goto P_0c096694;
case 0x0c096696u: goto P_0c096696;
case 0x0c09d42cu: goto P_0c09d42c;
case 0x0c09d42eu: goto P_0c09d42e;
case 0x0c09d430u: goto P_0c09d430;
case 0x0c09d432u: goto P_0c09d432;
case 0x0c09d434u: goto P_0c09d434;
case 0x0c09d436u: goto P_0c09d436;
case 0x0c09d438u: goto P_0c09d438;
case 0x0c09d43au: goto P_0c09d43a;
case 0x0c09d43cu: goto P_0c09d43c;
case 0x0c09d43eu: goto P_0c09d43e;
case 0x0c09d440u: goto P_0c09d440;
case 0x0c09d442u: goto P_0c09d442;
case 0x0c09d444u: goto P_0c09d444;
case 0x0c09d446u: goto P_0c09d446;
case 0x0c09d448u: goto P_0c09d448;
case 0x0c09d44au: goto P_0c09d44a;
case 0x0c09d44cu: goto P_0c09d44c;
case 0x0c09d44eu: goto P_0c09d44e;
case 0x0c09d450u: goto P_0c09d450;
case 0x0c09d4b0u: goto P_0c09d4b0;
case 0x0c09d4b2u: goto P_0c09d4b2;
case 0x0c09d4b4u: goto P_0c09d4b4;
case 0x0c09d4b6u: goto P_0c09d4b6;
case 0x0c09d4b8u: goto P_0c09d4b8;
case 0x0c09d4bau: goto P_0c09d4ba;
case 0x0c09d4bcu: goto P_0c09d4bc;
case 0x0c09d4beu: goto P_0c09d4be;
case 0x0c09d4c0u: goto P_0c09d4c0;
case 0x0c09d4c2u: goto P_0c09d4c2;
case 0x0c09d4c4u: goto P_0c09d4c4;
case 0x0c09d4c6u: goto P_0c09d4c6;
case 0x0c09d4c8u: goto P_0c09d4c8;
case 0x0c09d4cau: goto P_0c09d4ca;
case 0x0c09d4ccu: goto P_0c09d4cc;
case 0x0c09d4ceu: goto P_0c09d4ce;
case 0x0c09d4d0u: goto P_0c09d4d0;
case 0x0c09d4d2u: goto P_0c09d4d2;
case 0x0c09d4d4u: goto P_0c09d4d4;
case 0x0c09d4d6u: goto P_0c09d4d6;
case 0x0c09d4d8u: goto P_0c09d4d8;
case 0x0c09d4dau: goto P_0c09d4da;
case 0x0c09d4dcu: goto P_0c09d4dc;
case 0x0c09d4deu: goto P_0c09d4de;
case 0x0c09d4e0u: goto P_0c09d4e0;
case 0x0c09d4e2u: goto P_0c09d4e2;
case 0x0c09d4e4u: goto P_0c09d4e4;
case 0x0c09d4eeu: goto P_0c09d4ee;
case 0x0c09d4f0u: goto P_0c09d4f0;
case 0x0c09d4f2u: goto P_0c09d4f2;
case 0x0c09d4f4u: goto P_0c09d4f4;
case 0x0c09d4f6u: goto P_0c09d4f6;
case 0x0c09d4f8u: goto P_0c09d4f8;
case 0x0c09d4fau: goto P_0c09d4fa;
case 0x0c09d4fcu: goto P_0c09d4fc;
case 0x0c09d4feu: goto P_0c09d4fe;
case 0x0c09d500u: goto P_0c09d500;
case 0x0c09d502u: goto P_0c09d502;
case 0x0c09d504u: goto P_0c09d504;
case 0x0c09d506u: goto P_0c09d506;
case 0x0c09d508u: goto P_0c09d508;
case 0x0c09d50au: goto P_0c09d50a;
case 0x0c09d50cu: goto P_0c09d50c;
case 0x0c09d50eu: goto P_0c09d50e;
case 0x0c09d510u: goto P_0c09d510;
case 0x0c09d512u: goto P_0c09d512;
case 0x0c09d514u: goto P_0c09d514;
case 0x0c09d516u: goto P_0c09d516;
case 0x0c09d518u: goto P_0c09d518;
case 0x0c09d51au: goto P_0c09d51a;
case 0x0c09d51cu: goto P_0c09d51c;
case 0x0c09d51eu: goto P_0c09d51e;
case 0x0c09d520u: goto P_0c09d520;
case 0x0c09d522u: goto P_0c09d522;
case 0x0c09d524u: goto P_0c09d524;
case 0x0c09d526u: goto P_0c09d526;
case 0x0c09d528u: goto P_0c09d528;
case 0x0c09d52au: goto P_0c09d52a;
case 0x0c09d52cu: goto P_0c09d52c;
case 0x0c09d52eu: goto P_0c09d52e;
case 0x0c09d530u: goto P_0c09d530;
case 0x0c09d532u: goto P_0c09d532;
case 0x0c09d534u: goto P_0c09d534;
case 0x0c09d536u: goto P_0c09d536;
case 0x0c09d538u: goto P_0c09d538;
case 0x0c09d53au: goto P_0c09d53a;
case 0x0c09d53cu: goto P_0c09d53c;
case 0x0c09d53eu: goto P_0c09d53e;
case 0x0c09d540u: goto P_0c09d540;
case 0x0c09d542u: goto P_0c09d542;
case 0x0c09d544u: goto P_0c09d544;
case 0x0c09d546u: goto P_0c09d546;
case 0x0c09d548u: goto P_0c09d548;
case 0x0c09d54au: goto P_0c09d54a;
case 0x0c09d54cu: goto P_0c09d54c;
case 0x0c09d54eu: goto P_0c09d54e;
case 0x0c09d550u: goto P_0c09d550;
case 0x0c09d552u: goto P_0c09d552;
case 0x0c09d554u: goto P_0c09d554;
case 0x0c09d556u: goto P_0c09d556;
case 0x0c09d558u: goto P_0c09d558;
case 0x0c09d55au: goto P_0c09d55a;
case 0x0c09d55cu: goto P_0c09d55c;
case 0x0c09d55eu: goto P_0c09d55e;
case 0x0c09d560u: goto P_0c09d560;
case 0x0c09d562u: goto P_0c09d562;
case 0x0c09d564u: goto P_0c09d564;
case 0x0c09d566u: goto P_0c09d566;
case 0x0c09d568u: goto P_0c09d568;
case 0x0c09d56au: goto P_0c09d56a;
case 0x0c09d56cu: goto P_0c09d56c;
case 0x0c09d56eu: goto P_0c09d56e;
case 0x0c09d570u: goto P_0c09d570;
case 0x0c09d572u: goto P_0c09d572;
case 0x0c09d574u: goto P_0c09d574;
case 0x0c09d576u: goto P_0c09d576;
case 0x0c09d578u: goto P_0c09d578;
case 0x0c09da22u: goto P_0c09da22;
case 0x0c09da24u: goto P_0c09da24;
case 0x0c09da26u: goto P_0c09da26;
case 0x0c09da28u: goto P_0c09da28;
case 0x0c09da2au: goto P_0c09da2a;
case 0x0c09da2cu: goto P_0c09da2c;
case 0x0c09da2eu: goto P_0c09da2e;
case 0x0c09da30u: goto P_0c09da30;
case 0x0c09da32u: goto P_0c09da32;
case 0x0c09da34u: goto P_0c09da34;
case 0x0c09da36u: goto P_0c09da36;
case 0x0c09da38u: goto P_0c09da38;
case 0x0c09da3au: goto P_0c09da3a;
case 0x0c09da3cu: goto P_0c09da3c;
case 0x0c09da3eu: goto P_0c09da3e;
case 0x0c09da40u: goto P_0c09da40;
case 0x0c09da42u: goto P_0c09da42;
case 0x0c09da44u: goto P_0c09da44;
case 0x0c09da46u: goto P_0c09da46;
case 0x0c09da48u: goto P_0c09da48;
case 0x0c09da4au: goto P_0c09da4a;
case 0x0c09da4cu: goto P_0c09da4c;
case 0x0c09da4eu: goto P_0c09da4e;
case 0x0c09da50u: goto P_0c09da50;
case 0x0c09da52u: goto P_0c09da52;
case 0x0c09da54u: goto P_0c09da54;
case 0x0c09da56u: goto P_0c09da56;
case 0x0c09da58u: goto P_0c09da58;
case 0x0c09da5au: goto P_0c09da5a;
case 0x0c09da5cu: goto P_0c09da5c;
case 0x0c09da5eu: goto P_0c09da5e;
case 0x0c09da60u: goto P_0c09da60;
case 0x0c09da62u: goto P_0c09da62;
case 0x0c09da64u: goto P_0c09da64;
case 0x0c09da66u: goto P_0c09da66;
case 0x0c09da68u: goto P_0c09da68;
case 0x0c09da6au: goto P_0c09da6a;
case 0x0c09da6cu: goto P_0c09da6c;
case 0x0c09da6eu: goto P_0c09da6e;
case 0x0c09da70u: goto P_0c09da70;
case 0x0c09dbc0u: goto P_0c09dbc0;
case 0x0c09dbc2u: goto P_0c09dbc2;
case 0x0c09dbc4u: goto P_0c09dbc4;
case 0x0c09dbc6u: goto P_0c09dbc6;
case 0x0c09dbc8u: goto P_0c09dbc8;
case 0x0c09dbcau: goto P_0c09dbca;
case 0x0c09dbccu: goto P_0c09dbcc;
case 0x0c09dbceu: goto P_0c09dbce;
case 0x0c09dbd0u: goto P_0c09dbd0;
case 0x0c09dbd2u: goto P_0c09dbd2;
case 0x0c09dbd4u: goto P_0c09dbd4;
case 0x0c09dbd6u: goto P_0c09dbd6;
case 0x0c09dbd8u: goto P_0c09dbd8;
case 0x0c09dbdau: goto P_0c09dbda;
case 0x0c09dbdcu: goto P_0c09dbdc;
case 0x0c09dbdeu: goto P_0c09dbde;
case 0x0c09dbe0u: goto P_0c09dbe0;
case 0x0c09dbe2u: goto P_0c09dbe2;
case 0x0c09dbe4u: goto P_0c09dbe4;
case 0x0c09ee18u: goto P_0c09ee18;
case 0x0c09ee1au: goto P_0c09ee1a;
case 0x0c09ee1cu: goto P_0c09ee1c;
case 0x0c09ee1eu: goto P_0c09ee1e;
case 0x0c09ee20u: goto P_0c09ee20;
case 0x0c09ee22u: goto P_0c09ee22;
case 0x0c09ee24u: goto P_0c09ee24;
case 0x0c09ee26u: goto P_0c09ee26;
case 0x0c09ee28u: goto P_0c09ee28;
case 0x0c09ee2au: goto P_0c09ee2a;
case 0x0c09ee2cu: goto P_0c09ee2c;
case 0x0c09ee2eu: goto P_0c09ee2e;
case 0x0c09ee30u: goto P_0c09ee30;
case 0x0c09ee32u: goto P_0c09ee32;
case 0x0c09ee34u: goto P_0c09ee34;
case 0x0c09ee36u: goto P_0c09ee36;
case 0x0c09ee38u: goto P_0c09ee38;
case 0x0c09ee3au: goto P_0c09ee3a;
case 0x0c09ee3cu: goto P_0c09ee3c;
case 0x0c09ee3eu: goto P_0c09ee3e;
case 0x0c09ee40u: goto P_0c09ee40;
case 0x0c09ee42u: goto P_0c09ee42;
case 0x0c09ee44u: goto P_0c09ee44;
case 0x0c09ee46u: goto P_0c09ee46;
case 0x0c09ee48u: goto P_0c09ee48;
case 0x0c09ee4au: goto P_0c09ee4a;
case 0x0c09ee4cu: goto P_0c09ee4c;
case 0x0c09ee4eu: goto P_0c09ee4e;
case 0x0c09ee50u: goto P_0c09ee50;
case 0x0c09ee52u: goto P_0c09ee52;
case 0x0c09ee54u: goto P_0c09ee54;
case 0x0c09ee56u: goto P_0c09ee56;
case 0x0c09ee58u: goto P_0c09ee58;
case 0x0c09ee5au: goto P_0c09ee5a;
case 0x0c09ee5cu: goto P_0c09ee5c;
case 0x0c09ee5eu: goto P_0c09ee5e;
case 0x0c09ee60u: goto P_0c09ee60;
case 0x0c09ee62u: goto P_0c09ee62;
case 0x0c09ee64u: goto P_0c09ee64;
case 0x0c09ee66u: goto P_0c09ee66;
case 0x0c09ee68u: goto P_0c09ee68;
case 0x0c09ee6au: goto P_0c09ee6a;
case 0x0c09ee6cu: goto P_0c09ee6c;
case 0x0c09ee6eu: goto P_0c09ee6e;
case 0x0c09ee70u: goto P_0c09ee70;
case 0x0c09ee72u: goto P_0c09ee72;
case 0x0c09ee74u: goto P_0c09ee74;
case 0x0c09ee76u: goto P_0c09ee76;
case 0x0c09ee78u: goto P_0c09ee78;
case 0x0c09ee7au: goto P_0c09ee7a;
case 0x0c09ee7cu: goto P_0c09ee7c;
case 0x0c09ee7eu: goto P_0c09ee7e;
case 0x0c09ee80u: goto P_0c09ee80;
case 0x0c09ee82u: goto P_0c09ee82;
case 0x0c09ee84u: goto P_0c09ee84;
case 0x0c09ee86u: goto P_0c09ee86;
case 0x0c09ee88u: goto P_0c09ee88;
case 0x0c09ee8au: goto P_0c09ee8a;
case 0x0c09ee8cu: goto P_0c09ee8c;
case 0x0c09ee8eu: goto P_0c09ee8e;
case 0x0c09ee90u: goto P_0c09ee90;
case 0x0c09ee92u: goto P_0c09ee92;
case 0x0c09ee94u: goto P_0c09ee94;
case 0x0c09ee96u: goto P_0c09ee96;
case 0x0c09ee98u: goto P_0c09ee98;
case 0x0c09ee9au: goto P_0c09ee9a;
case 0x0c09ee9cu: goto P_0c09ee9c;
case 0x0c09ee9eu: goto P_0c09ee9e;
case 0x0c09eea0u: goto P_0c09eea0;
case 0x0c09eea2u: goto P_0c09eea2;
case 0x0c09eea4u: goto P_0c09eea4;
case 0x0c09eea6u: goto P_0c09eea6;
case 0x0c09eea8u: goto P_0c09eea8;
case 0x0c09eeaau: goto P_0c09eeaa;
case 0x0c09eeacu: goto P_0c09eeac;
case 0x0c09eeaeu: goto P_0c09eeae;
case 0x0c09eeb0u: goto P_0c09eeb0;
case 0x0c09eeb2u: goto P_0c09eeb2;
case 0x0c09eeb4u: goto P_0c09eeb4;
case 0x0c09eeb6u: goto P_0c09eeb6;
case 0x0c09eeb8u: goto P_0c09eeb8;
case 0x0c09eebau: goto P_0c09eeba;
case 0x0c09eebcu: goto P_0c09eebc;
case 0x0c09eebeu: goto P_0c09eebe;
case 0x0c09eec0u: goto P_0c09eec0;
case 0x0c09eec2u: goto P_0c09eec2;
case 0x0c09eec4u: goto P_0c09eec4;
case 0x0c09eec6u: goto P_0c09eec6;
case 0x0c09eec8u: goto P_0c09eec8;
case 0x0c09eecau: goto P_0c09eeca;
case 0x0c09eeccu: goto P_0c09eecc;
case 0x0c09eeceu: goto P_0c09eece;
case 0x0c09eed0u: goto P_0c09eed0;
case 0x0c09eed2u: goto P_0c09eed2;
case 0x0c09eed4u: goto P_0c09eed4;
case 0x0c09eed6u: goto P_0c09eed6;
case 0x0c09eed8u: goto P_0c09eed8;
case 0x0c09eedau: goto P_0c09eeda;
case 0x0c09eedcu: goto P_0c09eedc;
case 0x0c09eedeu: goto P_0c09eede;
case 0x0c09eee0u: goto P_0c09eee0;
case 0x0c09eee2u: goto P_0c09eee2;
case 0x0c09eee4u: goto P_0c09eee4;
case 0x0c09eee6u: goto P_0c09eee6;
case 0x0c09eee8u: goto P_0c09eee8;
case 0x0c09eeeau: goto P_0c09eeea;
case 0x0c09eeecu: goto P_0c09eeec;
case 0x0c09eeeeu: goto P_0c09eeee;
case 0x0c09eef0u: goto P_0c09eef0;
case 0x0c09eef2u: goto P_0c09eef2;
case 0x0c09eef4u: goto P_0c09eef4;
case 0x0c09eef6u: goto P_0c09eef6;
case 0x0c09eef8u: goto P_0c09eef8;
case 0x0c09eefau: goto P_0c09eefa;
case 0x0c09eefcu: goto P_0c09eefc;
case 0x0c09eefeu: goto P_0c09eefe;
case 0x0c09ef00u: goto P_0c09ef00;
case 0x0c09ef02u: goto P_0c09ef02;
case 0x0c09ef04u: goto P_0c09ef04;
case 0x0c09ef06u: goto P_0c09ef06;
case 0x0c09ef08u: goto P_0c09ef08;
case 0x0c09ef0au: goto P_0c09ef0a;
case 0x0c09ef0cu: goto P_0c09ef0c;
case 0x0c09ef0eu: goto P_0c09ef0e;
case 0x0c09ef10u: goto P_0c09ef10;
case 0x0c09ef12u: goto P_0c09ef12;
case 0x0c09ef14u: goto P_0c09ef14;
case 0x0c09ef16u: goto P_0c09ef16;
case 0x0c09ef18u: goto P_0c09ef18;
case 0x0c09ef1au: goto P_0c09ef1a;
case 0x0c09ef1cu: goto P_0c09ef1c;
case 0x0c09ef1eu: goto P_0c09ef1e;
case 0x0c09ef20u: goto P_0c09ef20;
case 0x0c09ef22u: goto P_0c09ef22;
case 0x0c09ef24u: goto P_0c09ef24;
case 0x0c09ef26u: goto P_0c09ef26;
case 0x0c09ef28u: goto P_0c09ef28;
case 0x0c09ef78u: goto P_0c09ef78;
case 0x0c09ef7au: goto P_0c09ef7a;
case 0x0c09ef7cu: goto P_0c09ef7c;
case 0x0c09ef7eu: goto P_0c09ef7e;
case 0x0c09ef80u: goto P_0c09ef80;
case 0x0c09ef82u: goto P_0c09ef82;
case 0x0c09ef84u: goto P_0c09ef84;
case 0x0c09ef86u: goto P_0c09ef86;
case 0x0c09ef88u: goto P_0c09ef88;
case 0x0c09ef8au: goto P_0c09ef8a;
case 0x0c09ef8cu: goto P_0c09ef8c;
case 0x0c09ef8eu: goto P_0c09ef8e;
case 0x0c09ef90u: goto P_0c09ef90;
case 0x0c09ef92u: goto P_0c09ef92;
case 0x0c09ef94u: goto P_0c09ef94;
case 0x0c09ef96u: goto P_0c09ef96;
case 0x0c09ef98u: goto P_0c09ef98;
case 0x0c09ef9au: goto P_0c09ef9a;
case 0x0c09ef9cu: goto P_0c09ef9c;
case 0x0c09ef9eu: goto P_0c09ef9e;
case 0x0c09efa0u: goto P_0c09efa0;
case 0x0c09efa2u: goto P_0c09efa2;
case 0x0c09efa4u: goto P_0c09efa4;
case 0x0c09efa6u: goto P_0c09efa6;
case 0x0c09efa8u: goto P_0c09efa8;
case 0x0c09efaau: goto P_0c09efaa;
case 0x0c09efacu: goto P_0c09efac;
case 0x0c09efaeu: goto P_0c09efae;
case 0x0c09efb0u: goto P_0c09efb0;
case 0x0c09efb2u: goto P_0c09efb2;
case 0x0c09efb4u: goto P_0c09efb4;
case 0x0c09efb6u: goto P_0c09efb6;
case 0x0c09efb8u: goto P_0c09efb8;
case 0x0c09efbau: goto P_0c09efba;
case 0x0c09efbcu: goto P_0c09efbc;
case 0x0c09efbeu: goto P_0c09efbe;
case 0x0c09efc0u: goto P_0c09efc0;
case 0x0c09efc2u: goto P_0c09efc2;
case 0x0c09efc4u: goto P_0c09efc4;
case 0x0c09efc6u: goto P_0c09efc6;
case 0x0c09efc8u: goto P_0c09efc8;
case 0x0c09efcau: goto P_0c09efca;
case 0x0c09efccu: goto P_0c09efcc;
case 0x0c09f036u: goto P_0c09f036;
case 0x0c09f038u: goto P_0c09f038;
case 0x0c09f03au: goto P_0c09f03a;
case 0x0c09f03cu: goto P_0c09f03c;
case 0x0c09f03eu: goto P_0c09f03e;
case 0x0c09f040u: goto P_0c09f040;
case 0x0c09f042u: goto P_0c09f042;
case 0x0c09f044u: goto P_0c09f044;
case 0x0c09f046u: goto P_0c09f046;
case 0x0c0a7390u: goto P_0c0a7390;
case 0x0c0a7392u: goto P_0c0a7392;
case 0x0c0a7394u: goto P_0c0a7394;
case 0x0c0a7396u: goto P_0c0a7396;
case 0x0c0a7398u: goto P_0c0a7398;
case 0x0c0a739au: goto P_0c0a739a;
case 0x0c0a739cu: goto P_0c0a739c;
case 0x0c0a739eu: goto P_0c0a739e;
case 0x0c0a73a0u: goto P_0c0a73a0;
case 0x0c0a73a2u: goto P_0c0a73a2;
case 0x0c0a73a4u: goto P_0c0a73a4;
case 0x0c0a73a6u: goto P_0c0a73a6;
case 0x0c0a73a8u: goto P_0c0a73a8;
case 0x0c0a73aau: goto P_0c0a73aa;
case 0x0c0a73acu: goto P_0c0a73ac;
case 0x0c0a73aeu: goto P_0c0a73ae;
case 0x0c0a73b0u: goto P_0c0a73b0;
case 0x0c0a73b2u: goto P_0c0a73b2;
case 0x0c0a73b4u: goto P_0c0a73b4;
case 0x0c0a73b6u: goto P_0c0a73b6;
case 0x0c0a73b8u: goto P_0c0a73b8;
case 0x0c0a73bau: goto P_0c0a73ba;
case 0x0c0a73bcu: goto P_0c0a73bc;
case 0x0c0a73beu: goto P_0c0a73be;
case 0x0c0a73c0u: goto P_0c0a73c0;
case 0x0c0a740eu: goto P_0c0a740e;
case 0x0c0a7410u: goto P_0c0a7410;
case 0x0c0a7412u: goto P_0c0a7412;
case 0x0c0a7414u: goto P_0c0a7414;
case 0x0c0a7416u: goto P_0c0a7416;
case 0x0c0a7418u: goto P_0c0a7418;
case 0x0c0a741au: goto P_0c0a741a;
case 0x0c0a741cu: goto P_0c0a741c;
case 0x0c0a741eu: goto P_0c0a741e;
case 0x0c0a7420u: goto P_0c0a7420;
case 0x0c0a7422u: goto P_0c0a7422;
case 0x0c0a7424u: goto P_0c0a7424;
case 0x0c0a7426u: goto P_0c0a7426;
case 0x0c0a7428u: goto P_0c0a7428;
case 0x0c0a742au: goto P_0c0a742a;
case 0x0c0a742cu: goto P_0c0a742c;
case 0x0c0a742eu: goto P_0c0a742e;
case 0x0c0a7430u: goto P_0c0a7430;
case 0x0c0a7432u: goto P_0c0a7432;
case 0x0c0a7434u: goto P_0c0a7434;
case 0x0c0a7436u: goto P_0c0a7436;
case 0x0c0a7438u: goto P_0c0a7438;
case 0x0c0a7478u: goto P_0c0a7478;
case 0x0c0a747au: goto P_0c0a747a;
case 0x0c0a747cu: goto P_0c0a747c;
case 0x0c0a747eu: goto P_0c0a747e;
case 0x0c0a7480u: goto P_0c0a7480;
case 0x0c0a7482u: goto P_0c0a7482;
case 0x0c0a7484u: goto P_0c0a7484;
case 0x0c0a7486u: goto P_0c0a7486;
case 0x0c0a7488u: goto P_0c0a7488;
case 0x0c0a748au: goto P_0c0a748a;
case 0x0c0a748cu: goto P_0c0a748c;
case 0x0c0a748eu: goto P_0c0a748e;
case 0x0c0a7490u: goto P_0c0a7490;
case 0x0c0a7492u: goto P_0c0a7492;
case 0x0c0a7494u: goto P_0c0a7494;
case 0x0c0a7496u: goto P_0c0a7496;
case 0x0c0a7498u: goto P_0c0a7498;
case 0x0c0a749au: goto P_0c0a749a;
case 0x0c0a749cu: goto P_0c0a749c;
case 0x0c0a749eu: goto P_0c0a749e;
case 0x0c0a74a0u: goto P_0c0a74a0;
case 0x0c0a74a2u: goto P_0c0a74a2;
case 0x0c0a74a4u: goto P_0c0a74a4;
case 0x0c0a74a6u: goto P_0c0a74a6;
case 0x0c0a74a8u: goto P_0c0a74a8;
case 0x0c0a74aau: goto P_0c0a74aa;
case 0x0c0a74acu: goto P_0c0a74ac;
case 0x0c0a74aeu: goto P_0c0a74ae;
case 0x0c0a74b0u: goto P_0c0a74b0;
case 0x0c0a74b2u: goto P_0c0a74b2;
case 0x0c0a74b4u: goto P_0c0a74b4;
case 0x0c0a74b6u: goto P_0c0a74b6;
case 0x0c0a74b8u: goto P_0c0a74b8;
case 0x0c0a74bau: goto P_0c0a74ba;
case 0x0c0a74f4u: goto P_0c0a74f4;
case 0x0c0a74f6u: goto P_0c0a74f6;
case 0x0c0a74f8u: goto P_0c0a74f8;
case 0x0c0a7568u: goto P_0c0a7568;
case 0x0c0a756au: goto P_0c0a756a;
case 0x0c0a7570u: goto P_0c0a7570;
case 0x0c0a7572u: goto P_0c0a7572;
case 0x0c0a7574u: goto P_0c0a7574;
case 0x0c0a7576u: goto P_0c0a7576;
case 0x0c0a7578u: goto P_0c0a7578;
case 0x0c0a757au: goto P_0c0a757a;
case 0x0c0a757cu: goto P_0c0a757c;
case 0x0c0a757eu: goto P_0c0a757e;
case 0x0c0a7580u: goto P_0c0a7580;
case 0x0c0a7582u: goto P_0c0a7582;
case 0x0c0a7584u: goto P_0c0a7584;
case 0x0c0a7586u: goto P_0c0a7586;
case 0x0c0a7588u: goto P_0c0a7588;
case 0x0c0a758au: goto P_0c0a758a;
case 0x0c0a758cu: goto P_0c0a758c;
case 0x0c0a758eu: goto P_0c0a758e;
case 0x0c0a7590u: goto P_0c0a7590;
case 0x0c0a7592u: goto P_0c0a7592;
case 0x0c0a7594u: goto P_0c0a7594;
case 0x0c0a7596u: goto P_0c0a7596;
case 0x0c0a7598u: goto P_0c0a7598;
case 0x0c0a759au: goto P_0c0a759a;
case 0x0c0a759cu: goto P_0c0a759c;
case 0x0c0a759eu: goto P_0c0a759e;
case 0x0c0a75a0u: goto P_0c0a75a0;
case 0x0c0a75a2u: goto P_0c0a75a2;
case 0x0c0a75a4u: goto P_0c0a75a4;
case 0x0c0a75a6u: goto P_0c0a75a6;
case 0x0c0a75a8u: goto P_0c0a75a8;
case 0x0c0a75aau: goto P_0c0a75aa;
case 0x0c0a75acu: goto P_0c0a75ac;
case 0x0c0a75aeu: goto P_0c0a75ae;
case 0x0c0a75b0u: goto P_0c0a75b0;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
case 0x0c0a76eeu: goto P_0c0a76ee;
case 0x0c0a76f0u: goto P_0c0a76f0;
case 0x0c0a76f2u: goto P_0c0a76f2;
case 0x0c0a76f4u: goto P_0c0a76f4;
case 0x0c0a76f6u: goto P_0c0a76f6;
case 0x0c0a76f8u: goto P_0c0a76f8;
case 0x0c0a76fau: goto P_0c0a76fa;
case 0x0c0a76fcu: goto P_0c0a76fc;
case 0x0c0a76feu: goto P_0c0a76fe;
case 0x0c0a7700u: goto P_0c0a7700;
case 0x0c0a7702u: goto P_0c0a7702;
case 0x0c0a7704u: goto P_0c0a7704;
case 0x0c0a7706u: goto P_0c0a7706;
case 0x0c0a7708u: goto P_0c0a7708;
case 0x0c0a770au: goto P_0c0a770a;
case 0x0c0a770cu: goto P_0c0a770c;
case 0x0c0a770eu: goto P_0c0a770e;
case 0x0c0a7710u: goto P_0c0a7710;
case 0x0c0a7712u: goto P_0c0a7712;
case 0x0c0a7714u: goto P_0c0a7714;
case 0x0c0a7716u: goto P_0c0a7716;
case 0x0c0a7718u: goto P_0c0a7718;
case 0x0c0a771au: goto P_0c0a771a;
case 0x0c0a771cu: goto P_0c0a771c;
case 0x0c0a771eu: goto P_0c0a771e;
case 0x0c0a7720u: goto P_0c0a7720;
case 0x0c0a7722u: goto P_0c0a7722;
case 0x0c0a7724u: goto P_0c0a7724;
case 0x0c0a7726u: goto P_0c0a7726;
case 0x0c0a7728u: goto P_0c0a7728;
case 0x0c0a772au: goto P_0c0a772a;
case 0x0c0a772cu: goto P_0c0a772c;
case 0x0c0a772eu: goto P_0c0a772e;
case 0x0c0a7730u: goto P_0c0a7730;
case 0x0c0a7732u: goto P_0c0a7732;
case 0x0c0a7734u: goto P_0c0a7734;
case 0x0c0a7736u: goto P_0c0a7736;
case 0x0c0a7738u: goto P_0c0a7738;
case 0x0c0a773au: goto P_0c0a773a;
case 0x0c0a773cu: goto P_0c0a773c;
case 0x0c0a773eu: goto P_0c0a773e;
case 0x0c0a7740u: goto P_0c0a7740;
case 0x0c0a7742u: goto P_0c0a7742;
case 0x0c0a7744u: goto P_0c0a7744;
case 0x0c0a7746u: goto P_0c0a7746;
case 0x0c0a7748u: goto P_0c0a7748;
case 0x0c0a774au: goto P_0c0a774a;
case 0x0c0a7b5au: goto P_0c0a7b5a;
case 0x0c0a7b5cu: goto P_0c0a7b5c;
case 0x0c0a7b5eu: goto P_0c0a7b5e;
case 0x0c0a7b60u: goto P_0c0a7b60;
case 0x0c0a7b62u: goto P_0c0a7b62;
case 0x0c0a7b64u: goto P_0c0a7b64;
case 0x0c0a7b66u: goto P_0c0a7b66;
case 0x0c0a7b68u: goto P_0c0a7b68;
case 0x0c0a7b6au: goto P_0c0a7b6a;
case 0x0c0a7b6cu: goto P_0c0a7b6c;
case 0x0c0a7b6eu: goto P_0c0a7b6e;
case 0x0c0a7b70u: goto P_0c0a7b70;
case 0x0c0a7b72u: goto P_0c0a7b72;
case 0x0c0a7b74u: goto P_0c0a7b74;
case 0x0c0a7b76u: goto P_0c0a7b76;
case 0x0c0a7b78u: goto P_0c0a7b78;
case 0x0c0a7b7au: goto P_0c0a7b7a;
case 0x0c0a7b7cu: goto P_0c0a7b7c;
case 0x0c0a7b7eu: goto P_0c0a7b7e;
case 0x0c0a7b80u: goto P_0c0a7b80;
case 0x0c0a7b82u: goto P_0c0a7b82;
case 0x0c0a7b84u: goto P_0c0a7b84;
case 0x0c0a9f62u: goto P_0c0a9f62;
case 0x0c0a9f64u: goto P_0c0a9f64;
case 0x0c0a9f66u: goto P_0c0a9f66;
case 0x0c0a9f68u: goto P_0c0a9f68;
case 0x0c0a9f6au: goto P_0c0a9f6a;
case 0x0c0a9f6cu: goto P_0c0a9f6c;
case 0x0c0a9f6eu: goto P_0c0a9f6e;
case 0x0c0a9f70u: goto P_0c0a9f70;
case 0x0c0a9f72u: goto P_0c0a9f72;
case 0x0c0a9f74u: goto P_0c0a9f74;
case 0x0c0a9f76u: goto P_0c0a9f76;
case 0x0c0a9f78u: goto P_0c0a9f78;
case 0x0c0a9f7au: goto P_0c0a9f7a;
case 0x0c0a9f7cu: goto P_0c0a9f7c;
case 0x0c0a9f7eu: goto P_0c0a9f7e;
case 0x0c0a9f80u: goto P_0c0a9f80;
case 0x0c0a9f82u: goto P_0c0a9f82;
case 0x0c0a9f84u: goto P_0c0a9f84;
case 0x0c0a9f86u: goto P_0c0a9f86;
case 0x0c0a9f88u: goto P_0c0a9f88;
case 0x0c0a9f8au: goto P_0c0a9f8a;
case 0x0c0a9f8cu: goto P_0c0a9f8c;
case 0x0c0a9f8eu: goto P_0c0a9f8e;
case 0x0c0a9f90u: goto P_0c0a9f90;
case 0x0c0a9f92u: goto P_0c0a9f92;
case 0x0c0a9f94u: goto P_0c0a9f94;
case 0x0c0a9f96u: goto P_0c0a9f96;
case 0x0c0a9f98u: goto P_0c0a9f98;
case 0x0c0a9f9au: goto P_0c0a9f9a;
case 0x0c0a9f9cu: goto P_0c0a9f9c;
case 0x0c0a9f9eu: goto P_0c0a9f9e;
case 0x0c0a9fa0u: goto P_0c0a9fa0;
case 0x0c0a9fa2u: goto P_0c0a9fa2;
case 0x0c0a9fa4u: goto P_0c0a9fa4;
case 0x0c0a9fa6u: goto P_0c0a9fa6;
case 0x0c0a9fa8u: goto P_0c0a9fa8;
case 0x0c0aa446u: goto P_0c0aa446;
case 0x0c0aa448u: goto P_0c0aa448;
case 0x0c0aa44au: goto P_0c0aa44a;
case 0x0c0aa44cu: goto P_0c0aa44c;
case 0x0c0aa44eu: goto P_0c0aa44e;
case 0x0c0aa450u: goto P_0c0aa450;
case 0x0c0aa452u: goto P_0c0aa452;
case 0x0c0aa454u: goto P_0c0aa454;
case 0x0c0aa456u: goto P_0c0aa456;
case 0x0c0aa458u: goto P_0c0aa458;
case 0x0c0aa45au: goto P_0c0aa45a;
case 0x0c0aa45cu: goto P_0c0aa45c;
case 0x0c0aa45eu: goto P_0c0aa45e;
case 0x0c0aa460u: goto P_0c0aa460;
case 0x0c0aa462u: goto P_0c0aa462;
case 0x0c0aa464u: goto P_0c0aa464;
case 0x0c0aa466u: goto P_0c0aa466;
case 0x0c0aa468u: goto P_0c0aa468;
case 0x0c0aa46au: goto P_0c0aa46a;
case 0x0c0aa46cu: goto P_0c0aa46c;
case 0x0c0aa46eu: goto P_0c0aa46e;
case 0x0c0aa470u: goto P_0c0aa470;
case 0x0c0aa472u: goto P_0c0aa472;
case 0x0c0aa474u: goto P_0c0aa474;
case 0x0c0aa4b8u: goto P_0c0aa4b8;
case 0x0c0aa4bau: goto P_0c0aa4ba;
case 0x0c0aa4bcu: goto P_0c0aa4bc;
case 0x0c0aa4beu: goto P_0c0aa4be;
case 0x0c0aa4c0u: goto P_0c0aa4c0;
case 0x0c0aa4c2u: goto P_0c0aa4c2;
case 0x0c0aa4c4u: goto P_0c0aa4c4;
case 0x0c0aa4c6u: goto P_0c0aa4c6;
case 0x0c0aa4c8u: goto P_0c0aa4c8;
case 0x0c0aa4cau: goto P_0c0aa4ca;
case 0x0c0aa4ccu: goto P_0c0aa4cc;
case 0x0c0aa4ceu: goto P_0c0aa4ce;
case 0x0c0aa4d0u: goto P_0c0aa4d0;
case 0x0c0aa4d2u: goto P_0c0aa4d2;
case 0x0c0aa4d4u: goto P_0c0aa4d4;
case 0x0c0aa4d6u: goto P_0c0aa4d6;
case 0x0c0aa4d8u: goto P_0c0aa4d8;
case 0x0c0aa4dau: goto P_0c0aa4da;
case 0x0c0aa4dcu: goto P_0c0aa4dc;
case 0x0c0aa4deu: goto P_0c0aa4de;
case 0x0c0aa4e0u: goto P_0c0aa4e0;
case 0x0c0aa4e2u: goto P_0c0aa4e2;
case 0x0c0aa4e4u: goto P_0c0aa4e4;
case 0x0c0aa4e6u: goto P_0c0aa4e6;
case 0x0c0aa4e8u: goto P_0c0aa4e8;
case 0x0c0abe84u: goto P_0c0abe84;
case 0x0c0abe86u: goto P_0c0abe86;
case 0x0c0abe88u: goto P_0c0abe88;
case 0x0c0abe8au: goto P_0c0abe8a;
case 0x0c0abe8cu: goto P_0c0abe8c;
case 0x0c0abe8eu: goto P_0c0abe8e;
case 0x0c0abe90u: goto P_0c0abe90;
case 0x0c0abe92u: goto P_0c0abe92;
case 0x0c0abe94u: goto P_0c0abe94;
case 0x0c0abe96u: goto P_0c0abe96;
case 0x0c0abe98u: goto P_0c0abe98;
case 0x0c0abe9au: goto P_0c0abe9a;
case 0x0c0abe9cu: goto P_0c0abe9c;
case 0x0c0abe9eu: goto P_0c0abe9e;
case 0x0c0abea0u: goto P_0c0abea0;
case 0x0c0abea2u: goto P_0c0abea2;
case 0x0c0abea4u: goto P_0c0abea4;
case 0x0c0abea6u: goto P_0c0abea6;
case 0x0c0ac1e4u: goto P_0c0ac1e4;
case 0x0c0ac1e6u: goto P_0c0ac1e6;
case 0x0c0ac1e8u: goto P_0c0ac1e8;
case 0x0c0ac1eau: goto P_0c0ac1ea;
case 0x0c0ac1ecu: goto P_0c0ac1ec;
case 0x0c0ac1eeu: goto P_0c0ac1ee;
case 0x0c0ac1f0u: goto P_0c0ac1f0;
case 0x0c0ac1f2u: goto P_0c0ac1f2;
case 0x0c0ac1f4u: goto P_0c0ac1f4;
case 0x0c0ac1f6u: goto P_0c0ac1f6;
case 0x0c0ac1f8u: goto P_0c0ac1f8;
case 0x0c0ac1fau: goto P_0c0ac1fa;
case 0x0c0ac1fcu: goto P_0c0ac1fc;
case 0x0c0ac1feu: goto P_0c0ac1fe;
case 0x0c0ac200u: goto P_0c0ac200;
case 0x0c0ac202u: goto P_0c0ac202;
case 0x0c0ac204u: goto P_0c0ac204;
case 0x0c0ac206u: goto P_0c0ac206;
case 0x0c0ac208u: goto P_0c0ac208;
case 0x0c0ac20au: goto P_0c0ac20a;
case 0x0c0ac20cu: goto P_0c0ac20c;
case 0x0c0ac20eu: goto P_0c0ac20e;
case 0x0c0ac210u: goto P_0c0ac210;
case 0x0c0ac212u: goto P_0c0ac212;
case 0x0c0ac214u: goto P_0c0ac214;
case 0x0c0ac216u: goto P_0c0ac216;
case 0x0c0ac218u: goto P_0c0ac218;
case 0x0c0ac21au: goto P_0c0ac21a;
case 0x0c0ac21cu: goto P_0c0ac21c;
case 0x0c0ac21eu: goto P_0c0ac21e;
case 0x0c0ac220u: goto P_0c0ac220;
case 0x0c0ac222u: goto P_0c0ac222;
case 0x0c0ac224u: goto P_0c0ac224;
case 0x0c0ac226u: goto P_0c0ac226;
case 0x0c0ac228u: goto P_0c0ac228;
case 0x0c0b1b34u: goto P_0c0b1b34;
case 0x0c0b1b36u: goto P_0c0b1b36;
case 0x0c0b1b38u: goto P_0c0b1b38;
case 0x0c0b1b3au: goto P_0c0b1b3a;
case 0x0c0b1b3cu: goto P_0c0b1b3c;
case 0x0c0b1b3eu: goto P_0c0b1b3e;
case 0x0c0b1b40u: goto P_0c0b1b40;
case 0x0c0b1b42u: goto P_0c0b1b42;
case 0x0c0b1b44u: goto P_0c0b1b44;
case 0x0c0b1b46u: goto P_0c0b1b46;
case 0x0c0b1b48u: goto P_0c0b1b48;
case 0x0c0b1b4au: goto P_0c0b1b4a;
case 0x0c0b1b4cu: goto P_0c0b1b4c;
case 0x0c0b1b4eu: goto P_0c0b1b4e;
case 0x0c0b1b50u: goto P_0c0b1b50;
case 0x0c0b1b52u: goto P_0c0b1b52;
case 0x0c0b1b54u: goto P_0c0b1b54;
case 0x0c0b1b56u: goto P_0c0b1b56;
case 0x0c0b1b58u: goto P_0c0b1b58;
case 0x0c0b1b5au: goto P_0c0b1b5a;
case 0x0c0b1b5cu: goto P_0c0b1b5c;
case 0x0c0b1b5eu: goto P_0c0b1b5e;
case 0x0c0b1b60u: goto P_0c0b1b60;
case 0x0c0b1b62u: goto P_0c0b1b62;
case 0x0c0b1b64u: goto P_0c0b1b64;
case 0x0c0b1b66u: goto P_0c0b1b66;
case 0x0c0b1b68u: goto P_0c0b1b68;
case 0x0c0b1b6au: goto P_0c0b1b6a;
case 0x0c0b1c94u: goto P_0c0b1c94;
case 0x0c0b1c96u: goto P_0c0b1c96;
case 0x0c0b1c98u: goto P_0c0b1c98;
case 0x0c0b1c9au: goto P_0c0b1c9a;
case 0x0c0b1c9cu: goto P_0c0b1c9c;
case 0x0c0b1c9eu: goto P_0c0b1c9e;
case 0x0c0b1ca0u: goto P_0c0b1ca0;
case 0x0c0b1ca2u: goto P_0c0b1ca2;
case 0x0c0b1ca4u: goto P_0c0b1ca4;
case 0x0c0b1ca6u: goto P_0c0b1ca6;
case 0x0c0b1ca8u: goto P_0c0b1ca8;
case 0x0c0b1caau: goto P_0c0b1caa;
case 0x0c0b1cacu: goto P_0c0b1cac;
case 0x0c0b1caeu: goto P_0c0b1cae;
case 0x0c0b1cb0u: goto P_0c0b1cb0;
case 0x0c0b1cb2u: goto P_0c0b1cb2;
case 0x0c0b1cb4u: goto P_0c0b1cb4;
case 0x0c0b1cb6u: goto P_0c0b1cb6;
case 0x0c0b1cb8u: goto P_0c0b1cb8;
case 0x0c0b1cbau: goto P_0c0b1cba;
case 0x0c0b1cbcu: goto P_0c0b1cbc;
case 0x0c0b1cbeu: goto P_0c0b1cbe;
case 0x0c0b1cc0u: goto P_0c0b1cc0;
case 0x0c0b1cc2u: goto P_0c0b1cc2;
case 0x0c0c12a4u: goto P_0c0c12a4;
case 0x0c0c12a6u: goto P_0c0c12a6;
case 0x0c0c12a8u: goto P_0c0c12a8;
case 0x0c0c12aau: goto P_0c0c12aa;
case 0x0c0c12acu: goto P_0c0c12ac;
case 0x0c0c12aeu: goto P_0c0c12ae;
case 0x0c0c12b0u: goto P_0c0c12b0;
case 0x0c0c12b2u: goto P_0c0c12b2;
case 0x0c0c12b4u: goto P_0c0c12b4;
case 0x0c0c12b6u: goto P_0c0c12b6;
case 0x0c0c12b8u: goto P_0c0c12b8;
case 0x0c0c12bau: goto P_0c0c12ba;
case 0x0c0c12bcu: goto P_0c0c12bc;
case 0x0c0c12beu: goto P_0c0c12be;
case 0x0c0c12c0u: goto P_0c0c12c0;
case 0x0c0c12c2u: goto P_0c0c12c2;
case 0x0c0c12c4u: goto P_0c0c12c4;
case 0x0c0c12c6u: goto P_0c0c12c6;
case 0x0c0c12c8u: goto P_0c0c12c8;
case 0x0c0c12cau: goto P_0c0c12ca;
case 0x0c0c12ccu: goto P_0c0c12cc;
case 0x0c0c12ceu: goto P_0c0c12ce;
case 0x0c0c12d0u: goto P_0c0c12d0;
case 0x0c0c12d2u: goto P_0c0c12d2;
case 0x0c0c12d4u: goto P_0c0c12d4;
case 0x0c0c12d6u: goto P_0c0c12d6;
case 0x0c0c1d86u: goto P_0c0c1d86;
case 0x0c0c1d88u: goto P_0c0c1d88;
case 0x0c0c1d8au: goto P_0c0c1d8a;
case 0x0c0c1d8cu: goto P_0c0c1d8c;
case 0x0c0c1d8eu: goto P_0c0c1d8e;
case 0x0c0c1d90u: goto P_0c0c1d90;
case 0x0c0c1d92u: goto P_0c0c1d92;
case 0x0c0c1d94u: goto P_0c0c1d94;
case 0x0c0c1d96u: goto P_0c0c1d96;
case 0x0c0c1d98u: goto P_0c0c1d98;
case 0x0c0c1d9au: goto P_0c0c1d9a;
case 0x0c0c1d9cu: goto P_0c0c1d9c;
case 0x0c0c1d9eu: goto P_0c0c1d9e;
case 0x0c0c1da0u: goto P_0c0c1da0;
case 0x0c0c1da2u: goto P_0c0c1da2;
case 0x0c0c1da4u: goto P_0c0c1da4;
case 0x0c0c1da6u: goto P_0c0c1da6;
case 0x0c0c1da8u: goto P_0c0c1da8;
case 0x0c0c1daau: goto P_0c0c1daa;
case 0x0c0c1dacu: goto P_0c0c1dac;
case 0x0c0c1daeu: goto P_0c0c1dae;
case 0x0c0c1db0u: goto P_0c0c1db0;
case 0x0c0c1db2u: goto P_0c0c1db2;
case 0x0c0c1db4u: goto P_0c0c1db4;
case 0x0c0c1db6u: goto P_0c0c1db6;
case 0x0c0c1db8u: goto P_0c0c1db8;
case 0x0c0c1dbau: goto P_0c0c1dba;
case 0x0c0c1dbcu: goto P_0c0c1dbc;
case 0x0c0c1dbeu: goto P_0c0c1dbe;
case 0x0c0c1dc0u: goto P_0c0c1dc0;
case 0x0c0c1dc2u: goto P_0c0c1dc2;
case 0x0c0c1dc4u: goto P_0c0c1dc4;
case 0x0c0c1dc6u: goto P_0c0c1dc6;
case 0x0c0c1dc8u: goto P_0c0c1dc8;
case 0x0c0c1dcau: goto P_0c0c1dca;
case 0x0c0c1dccu: goto P_0c0c1dcc;
case 0x0c0c1dceu: goto P_0c0c1dce;
case 0x0c0c1dd0u: goto P_0c0c1dd0;
case 0x0c0c1dd2u: goto P_0c0c1dd2;
case 0x0c0c1dd4u: goto P_0c0c1dd4;
case 0x0c0c1dd6u: goto P_0c0c1dd6;
case 0x0c0c1dd8u: goto P_0c0c1dd8;
case 0x0c0c1ddau: goto P_0c0c1dda;
case 0x0c0c1ddcu: goto P_0c0c1ddc;
case 0x0c0c1ddeu: goto P_0c0c1dde;
case 0x0c0c1de0u: goto P_0c0c1de0;
case 0x0c0c1de2u: goto P_0c0c1de2;
case 0x0c0c1de4u: goto P_0c0c1de4;
case 0x0c0c1de6u: goto P_0c0c1de6;
case 0x0c0c1de8u: goto P_0c0c1de8;
case 0x0c0c1deau: goto P_0c0c1dea;
case 0x0c0c1decu: goto P_0c0c1dec;
case 0x0c0c1deeu: goto P_0c0c1dee;
case 0x0c0c1df0u: goto P_0c0c1df0;
case 0x0c0c1df2u: goto P_0c0c1df2;
case 0x0c0c1e24u: goto P_0c0c1e24;
case 0x0c0c1e26u: goto P_0c0c1e26;
case 0x0c0c1e28u: goto P_0c0c1e28;
case 0x0c0c1e2au: goto P_0c0c1e2a;
case 0x0c0c1e2cu: goto P_0c0c1e2c;
case 0x0c0c1e2eu: goto P_0c0c1e2e;
case 0x0c0c1e30u: goto P_0c0c1e30;
case 0x0c0c1e32u: goto P_0c0c1e32;
case 0x0c0c1e34u: goto P_0c0c1e34;
case 0x0c0c1e36u: goto P_0c0c1e36;
case 0x0c0c1e38u: goto P_0c0c1e38;
case 0x0c0c1e3au: goto P_0c0c1e3a;
case 0x0c0c1e3cu: goto P_0c0c1e3c;
case 0x0c0c1e3eu: goto P_0c0c1e3e;
case 0x0c0c1e40u: goto P_0c0c1e40;
case 0x0c0c1e42u: goto P_0c0c1e42;
case 0x0c0c1e44u: goto P_0c0c1e44;
case 0x0c0c1e46u: goto P_0c0c1e46;
case 0x0c0c1e48u: goto P_0c0c1e48;
case 0x0c0c1e4au: goto P_0c0c1e4a;
case 0x0c0c1e4cu: goto P_0c0c1e4c;
case 0x0c0c1e4eu: goto P_0c0c1e4e;
case 0x0c0c1e50u: goto P_0c0c1e50;
case 0x0c0c1e52u: goto P_0c0c1e52;
case 0x0c0c1e54u: goto P_0c0c1e54;
case 0x0c0c1e56u: goto P_0c0c1e56;
case 0x0c0c1e58u: goto P_0c0c1e58;
case 0x0c0c1e5au: goto P_0c0c1e5a;
case 0x0c0c1e5cu: goto P_0c0c1e5c;
case 0x0c0c1e5eu: goto P_0c0c1e5e;
case 0x0c0c1e60u: goto P_0c0c1e60;
case 0x0c0c1e62u: goto P_0c0c1e62;
case 0x0c0c1e64u: goto P_0c0c1e64;
case 0x0c0c1e66u: goto P_0c0c1e66;
case 0x0c0c1e68u: goto P_0c0c1e68;
case 0x0c0c1e6au: goto P_0c0c1e6a;
case 0x0c0c1e6cu: goto P_0c0c1e6c;
case 0x0c0c1e6eu: goto P_0c0c1e6e;
case 0x0c0c1e70u: goto P_0c0c1e70;
case 0x0c0c1e72u: goto P_0c0c1e72;
case 0x0c0c1e74u: goto P_0c0c1e74;
case 0x0c0c1e76u: goto P_0c0c1e76;
case 0x0c0c1e78u: goto P_0c0c1e78;
case 0x0c0c1e7au: goto P_0c0c1e7a;
case 0x0c0c1e7cu: goto P_0c0c1e7c;
case 0x0c0c1e7eu: goto P_0c0c1e7e;
case 0x0c0c1e80u: goto P_0c0c1e80;
case 0x0c0c1e82u: goto P_0c0c1e82;
case 0x0c0c1e84u: goto P_0c0c1e84;
case 0x0c0c1e86u: goto P_0c0c1e86;
case 0x0c0c1e88u: goto P_0c0c1e88;
case 0x0c0c1e8au: goto P_0c0c1e8a;
case 0x0c0c1e8cu: goto P_0c0c1e8c;
case 0x0c0c1e8eu: goto P_0c0c1e8e;
case 0x0c0c1e90u: goto P_0c0c1e90;
case 0x0c0c1e92u: goto P_0c0c1e92;
case 0x0c0c1e94u: goto P_0c0c1e94;
case 0x0c0c1e96u: goto P_0c0c1e96;
case 0x0c0c1e98u: goto P_0c0c1e98;
case 0x0c0c1e9au: goto P_0c0c1e9a;
case 0x0c0c1e9cu: goto P_0c0c1e9c;
case 0x0c0c1e9eu: goto P_0c0c1e9e;
case 0x0c0c1ea0u: goto P_0c0c1ea0;
case 0x0c0c1ea2u: goto P_0c0c1ea2;
case 0x0c0c1ea4u: goto P_0c0c1ea4;
case 0x0c0c1ea6u: goto P_0c0c1ea6;
case 0x0c0c1ea8u: goto P_0c0c1ea8;
case 0x0c0c1eaau: goto P_0c0c1eaa;
case 0x0c0c1eacu: goto P_0c0c1eac;
case 0x0c0c1eaeu: goto P_0c0c1eae;
case 0x0c0c1eb0u: goto P_0c0c1eb0;
case 0x0c0c1eb2u: goto P_0c0c1eb2;
case 0x0c0c1eb4u: goto P_0c0c1eb4;
case 0x0c0c1eb6u: goto P_0c0c1eb6;
case 0x0c0c1eb8u: goto P_0c0c1eb8;
case 0x0c0c1ebau: goto P_0c0c1eba;
case 0x0c0c1ebcu: goto P_0c0c1ebc;
case 0x0c0c1ebeu: goto P_0c0c1ebe;
case 0x0c0c1ec0u: goto P_0c0c1ec0;
case 0x0c0c1ec2u: goto P_0c0c1ec2;
case 0x0c0c1ec4u: goto P_0c0c1ec4;
case 0x0c0c1ec6u: goto P_0c0c1ec6;
case 0x0c0c1ec8u: goto P_0c0c1ec8;
case 0x0c0c1ecau: goto P_0c0c1eca;
case 0x0c0c1eccu: goto P_0c0c1ecc;
case 0x0c0c1eceu: goto P_0c0c1ece;
case 0x0c0c1ed0u: goto P_0c0c1ed0;
case 0x0c0c1ed2u: goto P_0c0c1ed2;
case 0x0c0c1ed4u: goto P_0c0c1ed4;
case 0x0c0c1ed6u: goto P_0c0c1ed6;
case 0x0c0c1ed8u: goto P_0c0c1ed8;
case 0x0c0c1edau: goto P_0c0c1eda;
case 0x0c0c1edcu: goto P_0c0c1edc;
case 0x0c0c1edeu: goto P_0c0c1ede;
case 0x0c0c1ee0u: goto P_0c0c1ee0;
case 0x0c0c1ee2u: goto P_0c0c1ee2;
case 0x0c0c1ee4u: goto P_0c0c1ee4;
case 0x0c0c1ee6u: goto P_0c0c1ee6;
case 0x0c0c1ee8u: goto P_0c0c1ee8;
case 0x0c0c1eeau: goto P_0c0c1eea;
case 0x0c0c1eecu: goto P_0c0c1eec;
case 0x0c0c1eeeu: goto P_0c0c1eee;
case 0x0c0c1ef0u: goto P_0c0c1ef0;
case 0x0c0c1ef2u: goto P_0c0c1ef2;
case 0x0c0c1ef4u: goto P_0c0c1ef4;
case 0x0c0c1ef6u: goto P_0c0c1ef6;
case 0x0c0c1ef8u: goto P_0c0c1ef8;
case 0x0c0c1efau: goto P_0c0c1efa;
case 0x0c0c1efcu: goto P_0c0c1efc;
case 0x0c0c1efeu: goto P_0c0c1efe;
case 0x0c0c1f00u: goto P_0c0c1f00;
case 0x0c0c1f02u: goto P_0c0c1f02;
case 0x0c0c1f04u: goto P_0c0c1f04;
case 0x0c0c1f06u: goto P_0c0c1f06;
case 0x0c0c1f08u: goto P_0c0c1f08;
case 0x0c0c1f0au: goto P_0c0c1f0a;
case 0x0c0c1f0cu: goto P_0c0c1f0c;
case 0x0c0c1f0eu: goto P_0c0c1f0e;
case 0x0c0c1f10u: goto P_0c0c1f10;
case 0x0c0c1f12u: goto P_0c0c1f12;
case 0x0c0c1f14u: goto P_0c0c1f14;
case 0x0c0c1f16u: goto P_0c0c1f16;
case 0x0c0c1f18u: goto P_0c0c1f18;
case 0x0c0c1f1au: goto P_0c0c1f1a;
case 0x0c0c1f1cu: goto P_0c0c1f1c;
case 0x0c0c1f1eu: goto P_0c0c1f1e;
case 0x0c0c1f20u: goto P_0c0c1f20;
case 0x0c0c1f22u: goto P_0c0c1f22;
case 0x0c0c1f24u: goto P_0c0c1f24;
case 0x0c0c1f26u: goto P_0c0c1f26;
case 0x0c0c1f28u: goto P_0c0c1f28;
case 0x0c0c1f2au: goto P_0c0c1f2a;
case 0x0c0c1f2cu: goto P_0c0c1f2c;
case 0x0c0c1f2eu: goto P_0c0c1f2e;
case 0x0c0c1f30u: goto P_0c0c1f30;
case 0x0c0c2b66u: goto P_0c0c2b66;
case 0x0c0c2b68u: goto P_0c0c2b68;
case 0x0c0c2b6au: goto P_0c0c2b6a;
case 0x0c0c2b6cu: goto P_0c0c2b6c;
case 0x0c0c2b6eu: goto P_0c0c2b6e;
case 0x0c0c2b70u: goto P_0c0c2b70;
case 0x0c0c2b72u: goto P_0c0c2b72;
case 0x0c0c2b74u: goto P_0c0c2b74;
case 0x0c0c2b76u: goto P_0c0c2b76;
case 0x0c0c2b78u: goto P_0c0c2b78;
case 0x0c0c2b7au: goto P_0c0c2b7a;
case 0x0c0c2b7cu: goto P_0c0c2b7c;
case 0x0c0c2b7eu: goto P_0c0c2b7e;
case 0x0c0c4eb0u: goto P_0c0c4eb0;
case 0x0c0c4eb2u: goto P_0c0c4eb2;
case 0x0c0c4eb4u: goto P_0c0c4eb4;
case 0x0c0c4eb6u: goto P_0c0c4eb6;
case 0x0c0c4eb8u: goto P_0c0c4eb8;
case 0x0c0c6e7eu: goto P_0c0c6e7e;
case 0x0c0c6e80u: goto P_0c0c6e80;
case 0x0c0c6e82u: goto P_0c0c6e82;
case 0x0c0c6e84u: goto P_0c0c6e84;
case 0x0c0c6e86u: goto P_0c0c6e86;
case 0x0c0c6e88u: goto P_0c0c6e88;
case 0x0c0c6e8au: goto P_0c0c6e8a;
case 0x0c0c6e8cu: goto P_0c0c6e8c;
case 0x0c0c6e8eu: goto P_0c0c6e8e;
case 0x0c0c6e90u: goto P_0c0c6e90;
case 0x0c0c6e92u: goto P_0c0c6e92;
case 0x0c0c6e94u: goto P_0c0c6e94;
case 0x0c0c6e96u: goto P_0c0c6e96;
case 0x0c0c6e98u: goto P_0c0c6e98;
case 0x0c0c6e9au: goto P_0c0c6e9a;
case 0x0c0c6e9cu: goto P_0c0c6e9c;
case 0x0c0c6e9eu: goto P_0c0c6e9e;
case 0x0c0c6ea0u: goto P_0c0c6ea0;
case 0x0c0c6ea2u: goto P_0c0c6ea2;
case 0x0c0c6ea4u: goto P_0c0c6ea4;
case 0x0c0c6ea6u: goto P_0c0c6ea6;
case 0x0c0c6ea8u: goto P_0c0c6ea8;
case 0x0c0c6eaau: goto P_0c0c6eaa;
case 0x0c0c6eacu: goto P_0c0c6eac;
case 0x0c0c6eaeu: goto P_0c0c6eae;
case 0x0c0c6eb0u: goto P_0c0c6eb0;
case 0x0c0c6eb2u: goto P_0c0c6eb2;
case 0x0c0c6eb4u: goto P_0c0c6eb4;
case 0x0c0c6eb6u: goto P_0c0c6eb6;
case 0x0c0c6eb8u: goto P_0c0c6eb8;
case 0x0c0c6ebau: goto P_0c0c6eba;
case 0x0c0c6ebcu: goto P_0c0c6ebc;
case 0x0c0c6ebeu: goto P_0c0c6ebe;
case 0x0c0c6ec0u: goto P_0c0c6ec0;
case 0x0c0c6ec2u: goto P_0c0c6ec2;
case 0x0c0c6ec4u: goto P_0c0c6ec4;
case 0x0c0c6ec6u: goto P_0c0c6ec6;
case 0x0c0c6ec8u: goto P_0c0c6ec8;
case 0x0c0c6ecau: goto P_0c0c6eca;
case 0x0c0c6eccu: goto P_0c0c6ecc;
case 0x0c0c6eceu: goto P_0c0c6ece;
case 0x0c0c6ed0u: goto P_0c0c6ed0;
case 0x0c0c6ed2u: goto P_0c0c6ed2;
case 0x0c0c6ed4u: goto P_0c0c6ed4;
case 0x0c0c6ed6u: goto P_0c0c6ed6;
case 0x0c0c6ed8u: goto P_0c0c6ed8;
case 0x0c0c6edau: goto P_0c0c6eda;
case 0x0c0c6edcu: goto P_0c0c6edc;
case 0x0c0c6edeu: goto P_0c0c6ede;
case 0x0c0c6ee0u: goto P_0c0c6ee0;
case 0x0c0c6ee2u: goto P_0c0c6ee2;
case 0x0c0c6ee4u: goto P_0c0c6ee4;
case 0x0c0c6ee6u: goto P_0c0c6ee6;
case 0x0c0c6ee8u: goto P_0c0c6ee8;
case 0x0c0c6eeau: goto P_0c0c6eea;
case 0x0c0c6eecu: goto P_0c0c6eec;
case 0x0c0c6f1cu: goto P_0c0c6f1c;
case 0x0c0c6f1eu: goto P_0c0c6f1e;
case 0x0c0c6f20u: goto P_0c0c6f20;
case 0x0c0c6f22u: goto P_0c0c6f22;
case 0x0c0c6f24u: goto P_0c0c6f24;
case 0x0c0c6f26u: goto P_0c0c6f26;
case 0x0c0c6f28u: goto P_0c0c6f28;
case 0x0c0c6f2au: goto P_0c0c6f2a;
case 0x0c0c6f2cu: goto P_0c0c6f2c;
case 0x0c0c6f2eu: goto P_0c0c6f2e;
case 0x0c0c6f30u: goto P_0c0c6f30;
case 0x0c0c6f32u: goto P_0c0c6f32;
case 0x0c0c6f34u: goto P_0c0c6f34;
case 0x0c0c6f36u: goto P_0c0c6f36;
case 0x0c0c6f38u: goto P_0c0c6f38;
case 0x0c0c6f3au: goto P_0c0c6f3a;
case 0x0c0c6f3cu: goto P_0c0c6f3c;
case 0x0c0c6f3eu: goto P_0c0c6f3e;
case 0x0c0c6f40u: goto P_0c0c6f40;
case 0x0c0c6f42u: goto P_0c0c6f42;
case 0x0c0c6f44u: goto P_0c0c6f44;
case 0x0c0c6f46u: goto P_0c0c6f46;
case 0x0c0c6f48u: goto P_0c0c6f48;
case 0x0c0c6f4au: goto P_0c0c6f4a;
case 0x0c0c6f4cu: goto P_0c0c6f4c;
case 0x0c0c6f4eu: goto P_0c0c6f4e;
case 0x0c0c6f50u: goto P_0c0c6f50;
case 0x0c0c6f52u: goto P_0c0c6f52;
case 0x0c0c6f54u: goto P_0c0c6f54;
case 0x0c0c6f56u: goto P_0c0c6f56;
case 0x0c0c6f58u: goto P_0c0c6f58;
case 0x0c0c6f5au: goto P_0c0c6f5a;
case 0x0c0c6f5cu: goto P_0c0c6f5c;
case 0x0c0c6f5eu: goto P_0c0c6f5e;
case 0x0c0c6f60u: goto P_0c0c6f60;
case 0x0c0c6f62u: goto P_0c0c6f62;
case 0x0c0c6f64u: goto P_0c0c6f64;
case 0x0c0c6f66u: goto P_0c0c6f66;
case 0x0c0c6f68u: goto P_0c0c6f68;
case 0x0c0c6f6au: goto P_0c0c6f6a;
case 0x0c0c6f6cu: goto P_0c0c6f6c;
case 0x0c0c6f6eu: goto P_0c0c6f6e;
case 0x0c0c6f70u: goto P_0c0c6f70;
case 0x0c0c6f72u: goto P_0c0c6f72;
case 0x0c0c6f74u: goto P_0c0c6f74;
case 0x0c0c6f76u: goto P_0c0c6f76;
case 0x0c0c6f78u: goto P_0c0c6f78;
case 0x0c0c6f7au: goto P_0c0c6f7a;
case 0x0c0c6f7cu: goto P_0c0c6f7c;
case 0x0c0c6f7eu: goto P_0c0c6f7e;
case 0x0c0c6f80u: goto P_0c0c6f80;
case 0x0c0c6f82u: goto P_0c0c6f82;
case 0x0c0c6f84u: goto P_0c0c6f84;
case 0x0c0c6f86u: goto P_0c0c6f86;
case 0x0c0c6f88u: goto P_0c0c6f88;
case 0x0c0c6f8au: goto P_0c0c6f8a;
case 0x0c0c6f8cu: goto P_0c0c6f8c;
case 0x0c0c6f8eu: goto P_0c0c6f8e;
case 0x0c0c6f90u: goto P_0c0c6f90;
case 0x0c0c6f92u: goto P_0c0c6f92;
case 0x0c0c6f94u: goto P_0c0c6f94;
case 0x0c0c6f96u: goto P_0c0c6f96;
case 0x0c0c6f98u: goto P_0c0c6f98;
case 0x0c0c6f9au: goto P_0c0c6f9a;
case 0x0c0c6f9cu: goto P_0c0c6f9c;
case 0x0c0c6f9eu: goto P_0c0c6f9e;
case 0x0c0c6fa0u: goto P_0c0c6fa0;
case 0x0c0c6fa2u: goto P_0c0c6fa2;
case 0x0c0c6fa4u: goto P_0c0c6fa4;
case 0x0c0c6fa6u: goto P_0c0c6fa6;
case 0x0c0c6fa8u: goto P_0c0c6fa8;
case 0x0c0c6faau: goto P_0c0c6faa;
case 0x0c0c6facu: goto P_0c0c6fac;
case 0x0c0c6faeu: goto P_0c0c6fae;
case 0x0c0c6fb0u: goto P_0c0c6fb0;
case 0x0c0c6fb2u: goto P_0c0c6fb2;
case 0x0c0c6fb4u: goto P_0c0c6fb4;
case 0x0c0c6fb6u: goto P_0c0c6fb6;
case 0x0c0c6fb8u: goto P_0c0c6fb8;
case 0x0c0c6fbau: goto P_0c0c6fba;
case 0x0c0c6fbcu: goto P_0c0c6fbc;
case 0x0c0c6fbeu: goto P_0c0c6fbe;
case 0x0c0c6fc0u: goto P_0c0c6fc0;
case 0x0c0c6fc2u: goto P_0c0c6fc2;
case 0x0c0c6fc4u: goto P_0c0c6fc4;
case 0x0c0c6fc6u: goto P_0c0c6fc6;
case 0x0c0c6fc8u: goto P_0c0c6fc8;
case 0x0c0c6fcau: goto P_0c0c6fca;
case 0x0c0c6fccu: goto P_0c0c6fcc;
case 0x0c0c6fceu: goto P_0c0c6fce;
case 0x0c0c6fd0u: goto P_0c0c6fd0;
case 0x0c0c6fd2u: goto P_0c0c6fd2;
case 0x0c0c6fd4u: goto P_0c0c6fd4;
case 0x0c0c6fd6u: goto P_0c0c6fd6;
case 0x0c0c6fd8u: goto P_0c0c6fd8;
case 0x0c0c6fdau: goto P_0c0c6fda;
case 0x0c0c6fdcu: goto P_0c0c6fdc;
case 0x0c0c6fdeu: goto P_0c0c6fde;
case 0x0c0c6fe0u: goto P_0c0c6fe0;
case 0x0c0c6fe2u: goto P_0c0c6fe2;
case 0x0c0c6fe4u: goto P_0c0c6fe4;
case 0x0c0c6fe6u: goto P_0c0c6fe6;
case 0x0c0c6fe8u: goto P_0c0c6fe8;
case 0x0c0c6feau: goto P_0c0c6fea;
case 0x0c0c6fecu: goto P_0c0c6fec;
case 0x0c0c6feeu: goto P_0c0c6fee;
case 0x0c0c6ff0u: goto P_0c0c6ff0;
case 0x0c0c6ff2u: goto P_0c0c6ff2;
case 0x0c0c6ff4u: goto P_0c0c6ff4;
case 0x0c0c6ff6u: goto P_0c0c6ff6;
case 0x0c0c6ff8u: goto P_0c0c6ff8;
case 0x0c0c6ffau: goto P_0c0c6ffa;
case 0x0c0c6ffcu: goto P_0c0c6ffc;
case 0x0c0c6ffeu: goto P_0c0c6ffe;
case 0x0c0c7000u: goto P_0c0c7000;
case 0x0c0c7002u: goto P_0c0c7002;
case 0x0c0c7004u: goto P_0c0c7004;
case 0x0c0c7006u: goto P_0c0c7006;
case 0x0c0c7008u: goto P_0c0c7008;
case 0x0c0c700au: goto P_0c0c700a;
case 0x0c0c700cu: goto P_0c0c700c;
case 0x0c0c700eu: goto P_0c0c700e;
case 0x0c0c7010u: goto P_0c0c7010;
case 0x0c0c7012u: goto P_0c0c7012;
case 0x0c0c7014u: goto P_0c0c7014;
case 0x0c0c7016u: goto P_0c0c7016;
case 0x0c0c7018u: goto P_0c0c7018;
case 0x0c0c701au: goto P_0c0c701a;
case 0x0c0c701cu: goto P_0c0c701c;
case 0x0c0c701eu: goto P_0c0c701e;
case 0x0c0c7020u: goto P_0c0c7020;
case 0x0c0c7022u: goto P_0c0c7022;
case 0x0c0caaf2u: goto P_0c0caaf2;
case 0x0c0caaf4u: goto P_0c0caaf4;
case 0x0c0caaf6u: goto P_0c0caaf6;
case 0x0c0caaf8u: goto P_0c0caaf8;
case 0x0c0caafau: goto P_0c0caafa;
case 0x0c0caafcu: goto P_0c0caafc;
case 0x0c0caafeu: goto P_0c0caafe;
case 0x0c0cab00u: goto P_0c0cab00;
case 0x0c0cab02u: goto P_0c0cab02;
case 0x0c0cab04u: goto P_0c0cab04;
case 0x0c0cab06u: goto P_0c0cab06;
case 0x0c0cab08u: goto P_0c0cab08;
case 0x0c0cab0au: goto P_0c0cab0a;
case 0x0c0cab0cu: goto P_0c0cab0c;
case 0x0c0cab0eu: goto P_0c0cab0e;
case 0x0c0cab10u: goto P_0c0cab10;
case 0x0c0cab30u: goto P_0c0cab30;
case 0x0c0cab32u: goto P_0c0cab32;
case 0x0c0cab34u: goto P_0c0cab34;
case 0x0c0cab36u: goto P_0c0cab36;
case 0x0c0cab38u: goto P_0c0cab38;
case 0x0c0cab3au: goto P_0c0cab3a;
case 0x0c0cab3cu: goto P_0c0cab3c;
case 0x0c0cab3eu: goto P_0c0cab3e;
case 0x0c0cab40u: goto P_0c0cab40;
case 0x0c0cab42u: goto P_0c0cab42;
case 0x0c0cab44u: goto P_0c0cab44;
case 0x0c0cab46u: goto P_0c0cab46;
case 0x0c0cab48u: goto P_0c0cab48;
case 0x0c0cab4au: goto P_0c0cab4a;
case 0x0c0cab4cu: goto P_0c0cab4c;
case 0x0c0cab4eu: goto P_0c0cab4e;
case 0x0c0cab50u: goto P_0c0cab50;
case 0x0c0cab52u: goto P_0c0cab52;
case 0x0c0cab54u: goto P_0c0cab54;
case 0x0c0cab56u: goto P_0c0cab56;
case 0x0c0cab58u: goto P_0c0cab58;
case 0x0c0cab5au: goto P_0c0cab5a;
case 0x0c0cab5cu: goto P_0c0cab5c;
case 0x0c0cab5eu: goto P_0c0cab5e;
case 0x0c0cab60u: goto P_0c0cab60;
case 0x0c0cab62u: goto P_0c0cab62;
case 0x0c0cab64u: goto P_0c0cab64;
case 0x0c0cab66u: goto P_0c0cab66;
case 0x0c0cab68u: goto P_0c0cab68;
case 0x0c0cab6au: goto P_0c0cab6a;
case 0x0c0cab6cu: goto P_0c0cab6c;
case 0x0c0cab6eu: goto P_0c0cab6e;
case 0x0c0cab70u: goto P_0c0cab70;
case 0x0c0cab72u: goto P_0c0cab72;
case 0x0c0cab74u: goto P_0c0cab74;
case 0x0c0cab76u: goto P_0c0cab76;
case 0x0c0cab78u: goto P_0c0cab78;
case 0x0c0cab7au: goto P_0c0cab7a;
case 0x0c0cab7cu: goto P_0c0cab7c;
case 0x0c0cab7eu: goto P_0c0cab7e;
case 0x0c0cab80u: goto P_0c0cab80;
case 0x0c0cab82u: goto P_0c0cab82;
case 0x0c0cab84u: goto P_0c0cab84;
case 0x0c0cab86u: goto P_0c0cab86;
case 0x0c0cab88u: goto P_0c0cab88;
case 0x0c0cab8au: goto P_0c0cab8a;
case 0x0c0cab8cu: goto P_0c0cab8c;
case 0x0c0cab8eu: goto P_0c0cab8e;
case 0x0c0cab90u: goto P_0c0cab90;
case 0x0c0cab92u: goto P_0c0cab92;
case 0x0c0cab94u: goto P_0c0cab94;
case 0x0c0cab96u: goto P_0c0cab96;
case 0x0c0cab98u: goto P_0c0cab98;
case 0x0c0cab9au: goto P_0c0cab9a;
case 0x0c0cab9cu: goto P_0c0cab9c;
case 0x0c0cab9eu: goto P_0c0cab9e;
case 0x0c0caba0u: goto P_0c0caba0;
case 0x0c0caba2u: goto P_0c0caba2;
case 0x0c0caba4u: goto P_0c0caba4;
case 0x0c0caba6u: goto P_0c0caba6;
case 0x0c0caba8u: goto P_0c0caba8;
case 0x0c0cabaau: goto P_0c0cabaa;
case 0x0c0cabacu: goto P_0c0cabac;
case 0x0c0cabaeu: goto P_0c0cabae;
case 0x0c0cabb0u: goto P_0c0cabb0;
case 0x0c0cabb2u: goto P_0c0cabb2;
case 0x0c0cabb4u: goto P_0c0cabb4;
case 0x0c0cabb6u: goto P_0c0cabb6;
case 0x0c0cabb8u: goto P_0c0cabb8;
case 0x0c0cabbau: goto P_0c0cabba;
case 0x0c0cabbcu: goto P_0c0cabbc;
case 0x0c0cabbeu: goto P_0c0cabbe;
case 0x0c0cabc0u: goto P_0c0cabc0;
case 0x0c0cabc2u: goto P_0c0cabc2;
case 0x0c0cabc4u: goto P_0c0cabc4;
case 0x0c0cabc6u: goto P_0c0cabc6;
case 0x0c0cabc8u: goto P_0c0cabc8;
case 0x0c0cabcau: goto P_0c0cabca;
case 0x0c0cabccu: goto P_0c0cabcc;
case 0x0c0cabceu: goto P_0c0cabce;
case 0x0c0cabd0u: goto P_0c0cabd0;
case 0x0c0cabd2u: goto P_0c0cabd2;
case 0x0c0cabd4u: goto P_0c0cabd4;
case 0x0c0cabd6u: goto P_0c0cabd6;
case 0x0c0cabd8u: goto P_0c0cabd8;
case 0x0c0cabdau: goto P_0c0cabda;
case 0x0c0cabdcu: goto P_0c0cabdc;
case 0x0c0cabdeu: goto P_0c0cabde;
case 0x0c0cabe0u: goto P_0c0cabe0;
case 0x0c0cabe2u: goto P_0c0cabe2;
case 0x0c0cabe4u: goto P_0c0cabe4;
case 0x0c0cabe6u: goto P_0c0cabe6;
case 0x0c0cabe8u: goto P_0c0cabe8;
case 0x0c0cabeau: goto P_0c0cabea;
case 0x0c0cabecu: goto P_0c0cabec;
case 0x0c0cabeeu: goto P_0c0cabee;
case 0x0c0cabf0u: goto P_0c0cabf0;
case 0x0c0cabf2u: goto P_0c0cabf2;
case 0x0c0cabf4u: goto P_0c0cabf4;
case 0x0c0cabf6u: goto P_0c0cabf6;
case 0x0c0cabf8u: goto P_0c0cabf8;
case 0x0c0cabfau: goto P_0c0cabfa;
case 0x0c0cabfcu: goto P_0c0cabfc;
case 0x0c0cabfeu: goto P_0c0cabfe;
case 0x0c0cac00u: goto P_0c0cac00;
case 0x0c0cac02u: goto P_0c0cac02;
case 0x0c0cac04u: goto P_0c0cac04;
case 0x0c0cac06u: goto P_0c0cac06;
case 0x0c0cac08u: goto P_0c0cac08;
case 0x0c0cac0au: goto P_0c0cac0a;
case 0x0c0cac0cu: goto P_0c0cac0c;
case 0x0c0cac0eu: goto P_0c0cac0e;
case 0x0c0cac10u: goto P_0c0cac10;
case 0x0c0cac12u: goto P_0c0cac12;
case 0x0c0cac14u: goto P_0c0cac14;
case 0x0c0cac16u: goto P_0c0cac16;
case 0x0c0cac18u: goto P_0c0cac18;
case 0x0c0cac1au: goto P_0c0cac1a;
case 0x0c0cac1cu: goto P_0c0cac1c;
case 0x0c0cac1eu: goto P_0c0cac1e;
case 0x0c0cac20u: goto P_0c0cac20;
case 0x0c0cac22u: goto P_0c0cac22;
case 0x0c0cac24u: goto P_0c0cac24;
case 0x0c0cac26u: goto P_0c0cac26;
case 0x0c0cac28u: goto P_0c0cac28;
case 0x0c0cac2au: goto P_0c0cac2a;
case 0x0c0cac2cu: goto P_0c0cac2c;
case 0x0c0cac2eu: goto P_0c0cac2e;
case 0x0c0cac5cu: goto P_0c0cac5c;
case 0x0c0cac5eu: goto P_0c0cac5e;
case 0x0c0cac60u: goto P_0c0cac60;
case 0x0c0cac62u: goto P_0c0cac62;
case 0x0c0cac64u: goto P_0c0cac64;
case 0x0c0cac66u: goto P_0c0cac66;
case 0x0c0cac68u: goto P_0c0cac68;
case 0x0c0cac6au: goto P_0c0cac6a;
case 0x0c0cac6cu: goto P_0c0cac6c;
case 0x0c0cac6eu: goto P_0c0cac6e;
case 0x0c0cac70u: goto P_0c0cac70;
case 0x0c0cac72u: goto P_0c0cac72;
case 0x0c0cac74u: goto P_0c0cac74;
case 0x0c0cac76u: goto P_0c0cac76;
case 0x0c0cac78u: goto P_0c0cac78;
case 0x0c0cac7au: goto P_0c0cac7a;
case 0x0c0cac7cu: goto P_0c0cac7c;
case 0x0c0cac7eu: goto P_0c0cac7e;
case 0x0c0cac80u: goto P_0c0cac80;
case 0x0c0cac82u: goto P_0c0cac82;
case 0x0c0cac84u: goto P_0c0cac84;
case 0x0c0cac86u: goto P_0c0cac86;
case 0x0c0cac88u: goto P_0c0cac88;
case 0x0c0cac8au: goto P_0c0cac8a;
case 0x0c0cac8cu: goto P_0c0cac8c;
case 0x0c0cac8eu: goto P_0c0cac8e;
case 0x0c0cac90u: goto P_0c0cac90;
case 0x0c0cac92u: goto P_0c0cac92;
case 0x0c0cac94u: goto P_0c0cac94;
case 0x0c0cac96u: goto P_0c0cac96;
case 0x0c0cac98u: goto P_0c0cac98;
case 0x0c0cac9au: goto P_0c0cac9a;
case 0x0c0cac9cu: goto P_0c0cac9c;
case 0x0c0cac9eu: goto P_0c0cac9e;
case 0x0c0caca0u: goto P_0c0caca0;
case 0x0c0caca2u: goto P_0c0caca2;
case 0x0c0caca4u: goto P_0c0caca4;
case 0x0c0caca6u: goto P_0c0caca6;
case 0x0c0caca8u: goto P_0c0caca8;
case 0x0c0cacaau: goto P_0c0cacaa;
case 0x0c0cacacu: goto P_0c0cacac;
case 0x0c0cacaeu: goto P_0c0cacae;
case 0x0c0cacb0u: goto P_0c0cacb0;
case 0x0c0cacb2u: goto P_0c0cacb2;
case 0x0c0cacb4u: goto P_0c0cacb4;
case 0x0c0cacb6u: goto P_0c0cacb6;
case 0x0c0cacb8u: goto P_0c0cacb8;
case 0x0c0cacbau: goto P_0c0cacba;
case 0x0c0cacbcu: goto P_0c0cacbc;
case 0x0c0cacbeu: goto P_0c0cacbe;
case 0x0c0cacc0u: goto P_0c0cacc0;
case 0x0c0cacc2u: goto P_0c0cacc2;
case 0x0c0cacc4u: goto P_0c0cacc4;
case 0x0c0cacc6u: goto P_0c0cacc6;
case 0x0c0cacc8u: goto P_0c0cacc8;
case 0x0c0caccau: goto P_0c0cacca;
case 0x0c0cacccu: goto P_0c0caccc;
case 0x0c0cacceu: goto P_0c0cacce;
case 0x0c0cacd0u: goto P_0c0cacd0;
case 0x0c0cacd2u: goto P_0c0cacd2;
case 0x0c0cacd4u: goto P_0c0cacd4;
case 0x0c0cacd6u: goto P_0c0cacd6;
case 0x0c0cacd8u: goto P_0c0cacd8;
case 0x0c0cacdau: goto P_0c0cacda;
case 0x0c0cacdcu: goto P_0c0cacdc;
case 0x0c0cacdeu: goto P_0c0cacde;
case 0x0c0cace0u: goto P_0c0cace0;
case 0x0c0cace2u: goto P_0c0cace2;
case 0x0c0cace4u: goto P_0c0cace4;
case 0x0c0cace6u: goto P_0c0cace6;
case 0x0c0cace8u: goto P_0c0cace8;
case 0x0c0caceau: goto P_0c0cacea;
case 0x0c0cacecu: goto P_0c0cacec;
case 0x0c0caceeu: goto P_0c0cacee;
case 0x0c0cad04u: goto P_0c0cad04;
case 0x0c0cad06u: goto P_0c0cad06;
case 0x0c0cad08u: goto P_0c0cad08;
case 0x0c0cad0au: goto P_0c0cad0a;
case 0x0c0cad0cu: goto P_0c0cad0c;
case 0x0c0cad0eu: goto P_0c0cad0e;
case 0x0c0cad10u: goto P_0c0cad10;
case 0x0c0cad12u: goto P_0c0cad12;
case 0x0c0cad14u: goto P_0c0cad14;
case 0x0c0cad16u: goto P_0c0cad16;
case 0x0c0cad18u: goto P_0c0cad18;
case 0x0c0cad1au: goto P_0c0cad1a;
case 0x0c0cad1cu: goto P_0c0cad1c;
case 0x0c0cad1eu: goto P_0c0cad1e;
case 0x0c0cad20u: goto P_0c0cad20;
case 0x0c0cad22u: goto P_0c0cad22;
case 0x0c0cad24u: goto P_0c0cad24;
case 0x0c0cad26u: goto P_0c0cad26;
case 0x0c0cad28u: goto P_0c0cad28;
case 0x0c0cad2au: goto P_0c0cad2a;
case 0x0c0cad2cu: goto P_0c0cad2c;
case 0x0c0cad2eu: goto P_0c0cad2e;
case 0x0c0cad30u: goto P_0c0cad30;
case 0x0c0cad32u: goto P_0c0cad32;
case 0x0c0cad34u: goto P_0c0cad34;
case 0x0c0cad36u: goto P_0c0cad36;
case 0x0c0cad38u: goto P_0c0cad38;
case 0x0c0cad3au: goto P_0c0cad3a;
case 0x0c0cad3cu: goto P_0c0cad3c;
case 0x0c0cad3eu: goto P_0c0cad3e;
case 0x0c0cad40u: goto P_0c0cad40;
case 0x0c0cad42u: goto P_0c0cad42;
case 0x0c0cad44u: goto P_0c0cad44;
case 0x0c0cad46u: goto P_0c0cad46;
case 0x0c0cad48u: goto P_0c0cad48;
case 0x0c0cad4au: goto P_0c0cad4a;
case 0x0c0cad4cu: goto P_0c0cad4c;
case 0x0c0cad4eu: goto P_0c0cad4e;
case 0x0c0cad50u: goto P_0c0cad50;
case 0x0c0cad52u: goto P_0c0cad52;
case 0x0c0cad54u: goto P_0c0cad54;
case 0x0c0cad56u: goto P_0c0cad56;
case 0x0c0cad58u: goto P_0c0cad58;
case 0x0c0cad5au: goto P_0c0cad5a;
case 0x0c0cad5cu: goto P_0c0cad5c;
case 0x0c0cad5eu: goto P_0c0cad5e;
case 0x0c0cad60u: goto P_0c0cad60;
case 0x0c0cad62u: goto P_0c0cad62;
case 0x0c0cad64u: goto P_0c0cad64;
case 0x0c0cad66u: goto P_0c0cad66;
case 0x0c0cad68u: goto P_0c0cad68;
case 0x0c0cad6au: goto P_0c0cad6a;
case 0x0c0cad6cu: goto P_0c0cad6c;
case 0x0c0cad6eu: goto P_0c0cad6e;
case 0x0c0cad70u: goto P_0c0cad70;
case 0x0c0cad72u: goto P_0c0cad72;
case 0x0c0cad74u: goto P_0c0cad74;
case 0x0c0cad76u: goto P_0c0cad76;
case 0x0c0cad78u: goto P_0c0cad78;
case 0x0c0cad7au: goto P_0c0cad7a;
case 0x0c0cad7cu: goto P_0c0cad7c;
case 0x0c0cad7eu: goto P_0c0cad7e;
case 0x0c0cad80u: goto P_0c0cad80;
case 0x0c0cad82u: goto P_0c0cad82;
case 0x0c0cad84u: goto P_0c0cad84;
case 0x0c0cad86u: goto P_0c0cad86;
case 0x0c0cad88u: goto P_0c0cad88;
case 0x0c0cad8au: goto P_0c0cad8a;
case 0x0c0cad8cu: goto P_0c0cad8c;
case 0x0c0cad8eu: goto P_0c0cad8e;
case 0x0c0cad90u: goto P_0c0cad90;
case 0x0c0cad92u: goto P_0c0cad92;
case 0x0c0cad94u: goto P_0c0cad94;
case 0x0c0cad96u: goto P_0c0cad96;
case 0x0c0cad98u: goto P_0c0cad98;
case 0x0c0cad9au: goto P_0c0cad9a;
case 0x0c0cad9cu: goto P_0c0cad9c;
case 0x0c0cad9eu: goto P_0c0cad9e;
case 0x0c0cada0u: goto P_0c0cada0;
case 0x0c0cada2u: goto P_0c0cada2;
case 0x0c0cada4u: goto P_0c0cada4;
case 0x0c0cada6u: goto P_0c0cada6;
case 0x0c0cada8u: goto P_0c0cada8;
case 0x0c0cadaau: goto P_0c0cadaa;
case 0x0c0cadacu: goto P_0c0cadac;
case 0x0c0cadaeu: goto P_0c0cadae;
case 0x0c0cadb0u: goto P_0c0cadb0;
case 0x0c0cadb2u: goto P_0c0cadb2;
case 0x0c0cadb4u: goto P_0c0cadb4;
case 0x0c0cadb6u: goto P_0c0cadb6;
case 0x0c0cadb8u: goto P_0c0cadb8;
case 0x0c0cadbau: goto P_0c0cadba;
case 0x0c0cadbcu: goto P_0c0cadbc;
case 0x0c0cadbeu: goto P_0c0cadbe;
case 0x0c0cadc0u: goto P_0c0cadc0;
case 0x0c0cadc2u: goto P_0c0cadc2;
case 0x0c0cade0u: goto P_0c0cade0;
case 0x0c0cade2u: goto P_0c0cade2;
case 0x0c0cade4u: goto P_0c0cade4;
case 0x0c0cade6u: goto P_0c0cade6;
case 0x0c0cade8u: goto P_0c0cade8;
case 0x0c0cadeau: goto P_0c0cadea;
case 0x0c0cadecu: goto P_0c0cadec;
case 0x0c0cadeeu: goto P_0c0cadee;
case 0x0c0cadf0u: goto P_0c0cadf0;
case 0x0c0cadf2u: goto P_0c0cadf2;
case 0x0c0cadf4u: goto P_0c0cadf4;
case 0x0c0cadf6u: goto P_0c0cadf6;
case 0x0c0cadf8u: goto P_0c0cadf8;
case 0x0c0cadfau: goto P_0c0cadfa;
case 0x0c0cadfcu: goto P_0c0cadfc;
case 0x0c0cadfeu: goto P_0c0cadfe;
case 0x0c0cae00u: goto P_0c0cae00;
case 0x0c0cae02u: goto P_0c0cae02;
case 0x0c0cae04u: goto P_0c0cae04;
case 0x0c0cae06u: goto P_0c0cae06;
case 0x0c0cae08u: goto P_0c0cae08;
case 0x0c0cae0au: goto P_0c0cae0a;
case 0x0c0cae0cu: goto P_0c0cae0c;
case 0x0c0cae0eu: goto P_0c0cae0e;
case 0x0c0cae10u: goto P_0c0cae10;
case 0x0c0cae12u: goto P_0c0cae12;
case 0x0c0cae14u: goto P_0c0cae14;
case 0x0c0cae16u: goto P_0c0cae16;
case 0x0c0cae18u: goto P_0c0cae18;
case 0x0c0cae1au: goto P_0c0cae1a;
case 0x0c0cae1cu: goto P_0c0cae1c;
case 0x0c0cae1eu: goto P_0c0cae1e;
case 0x0c0cae20u: goto P_0c0cae20;
case 0x0c0cae22u: goto P_0c0cae22;
case 0x0c0cae24u: goto P_0c0cae24;
case 0x0c0cae26u: goto P_0c0cae26;
case 0x0c0cae28u: goto P_0c0cae28;
case 0x0c0cae2au: goto P_0c0cae2a;
case 0x0c0cae2cu: goto P_0c0cae2c;
case 0x0c0cae2eu: goto P_0c0cae2e;
case 0x0c0cae30u: goto P_0c0cae30;
case 0x0c0cae32u: goto P_0c0cae32;
case 0x0c0cae34u: goto P_0c0cae34;
case 0x0c0cae36u: goto P_0c0cae36;
case 0x0c0cae38u: goto P_0c0cae38;
case 0x0c0cae3au: goto P_0c0cae3a;
case 0x0c0cae3cu: goto P_0c0cae3c;
case 0x0c0cae3eu: goto P_0c0cae3e;
case 0x0c0cae40u: goto P_0c0cae40;
case 0x0c0cae42u: goto P_0c0cae42;
case 0x0c0cae44u: goto P_0c0cae44;
case 0x0c0cae46u: goto P_0c0cae46;
case 0x0c0cae48u: goto P_0c0cae48;
case 0x0c0cae4au: goto P_0c0cae4a;
case 0x0c0cae4cu: goto P_0c0cae4c;
case 0x0c0cae4eu: goto P_0c0cae4e;
case 0x0c0cae50u: goto P_0c0cae50;
case 0x0c0cae52u: goto P_0c0cae52;
case 0x0c0cae54u: goto P_0c0cae54;
case 0x0c0cae56u: goto P_0c0cae56;
case 0x0c0cae58u: goto P_0c0cae58;
case 0x0c0cae5au: goto P_0c0cae5a;
case 0x0c0cae5cu: goto P_0c0cae5c;
case 0x0c0cae5eu: goto P_0c0cae5e;
case 0x0c0cae60u: goto P_0c0cae60;
case 0x0c0cae62u: goto P_0c0cae62;
case 0x0c0cae64u: goto P_0c0cae64;
case 0x0c0cae66u: goto P_0c0cae66;
case 0x0c0cae68u: goto P_0c0cae68;
case 0x0c0cae6au: goto P_0c0cae6a;
case 0x0c0cae6cu: goto P_0c0cae6c;
case 0x0c0cae6eu: goto P_0c0cae6e;
case 0x0c0cae70u: goto P_0c0cae70;
case 0x0c0cae72u: goto P_0c0cae72;
case 0x0c0cae74u: goto P_0c0cae74;
case 0x0c0cae76u: goto P_0c0cae76;
case 0x0c0cae78u: goto P_0c0cae78;
case 0x0c0cae7au: goto P_0c0cae7a;
case 0x0c0cae7cu: goto P_0c0cae7c;
case 0x0c0cae7eu: goto P_0c0cae7e;
case 0x0c0cae80u: goto P_0c0cae80;
case 0x0c0cae82u: goto P_0c0cae82;
case 0x0c0cae84u: goto P_0c0cae84;
case 0x0c0cae86u: goto P_0c0cae86;
case 0x0c0cae88u: goto P_0c0cae88;
case 0x0c0cae8au: goto P_0c0cae8a;
case 0x0c0cae8cu: goto P_0c0cae8c;
case 0x0c0cae8eu: goto P_0c0cae8e;
case 0x0c0cae90u: goto P_0c0cae90;
case 0x0c0cae92u: goto P_0c0cae92;
case 0x0c0cae94u: goto P_0c0cae94;
case 0x0c0cae96u: goto P_0c0cae96;
case 0x0c0cae98u: goto P_0c0cae98;
case 0x0c0cae9au: goto P_0c0cae9a;
case 0x0c0cae9cu: goto P_0c0cae9c;
case 0x0c0cae9eu: goto P_0c0cae9e;
case 0x0c0caea0u: goto P_0c0caea0;
case 0x0c0caea2u: goto P_0c0caea2;
case 0x0c0caea4u: goto P_0c0caea4;
case 0x0c0caea6u: goto P_0c0caea6;
case 0x0c0caea8u: goto P_0c0caea8;
case 0x0c0caeaau: goto P_0c0caeaa;
case 0x0c0caeacu: goto P_0c0caeac;
case 0x0c0caeaeu: goto P_0c0caeae;
case 0x0c0caeb0u: goto P_0c0caeb0;
case 0x0c0caeb2u: goto P_0c0caeb2;
case 0x0c0caeb4u: goto P_0c0caeb4;
case 0x0c0caeb6u: goto P_0c0caeb6;
case 0x0c0caeb8u: goto P_0c0caeb8;
case 0x0c0caebau: goto P_0c0caeba;
case 0x0c0caebcu: goto P_0c0caebc;
case 0x0c0caebeu: goto P_0c0caebe;
case 0x0c0caec0u: goto P_0c0caec0;
case 0x0c0caec2u: goto P_0c0caec2;
case 0x0c0caec4u: goto P_0c0caec4;
case 0x0c0caec6u: goto P_0c0caec6;
case 0x0c0caec8u: goto P_0c0caec8;
case 0x0c0caecau: goto P_0c0caeca;
case 0x0c0caeccu: goto P_0c0caecc;
case 0x0c0caeceu: goto P_0c0caece;
case 0x0c0caed0u: goto P_0c0caed0;
case 0x0c0caed2u: goto P_0c0caed2;
case 0x0c0caed4u: goto P_0c0caed4;
case 0x0c0caed6u: goto P_0c0caed6;
case 0x0c0caed8u: goto P_0c0caed8;
case 0x0c0caedau: goto P_0c0caeda;
case 0x0c0caedcu: goto P_0c0caedc;
case 0x0c0caedeu: goto P_0c0caede;
case 0x0c0caee0u: goto P_0c0caee0;
case 0x0c0caee2u: goto P_0c0caee2;
case 0x0c0caee4u: goto P_0c0caee4;
case 0x0c0caee6u: goto P_0c0caee6;
case 0x0c0caee8u: goto P_0c0caee8;
case 0x0c0caeeau: goto P_0c0caeea;
case 0x0c0caeecu: goto P_0c0caeec;
case 0x0c0caeeeu: goto P_0c0caeee;
case 0x0c0caef0u: goto P_0c0caef0;
case 0x0c0caef2u: goto P_0c0caef2;
case 0x0c0caf18u: goto P_0c0caf18;
case 0x0c0caf1au: goto P_0c0caf1a;
case 0x0c0caf1cu: goto P_0c0caf1c;
case 0x0c0caf1eu: goto P_0c0caf1e;
case 0x0c0caf20u: goto P_0c0caf20;
case 0x0c0caf22u: goto P_0c0caf22;
case 0x0c0caf24u: goto P_0c0caf24;
case 0x0c0caf26u: goto P_0c0caf26;
case 0x0c0caf28u: goto P_0c0caf28;
case 0x0c0caf2au: goto P_0c0caf2a;
case 0x0c0caf2cu: goto P_0c0caf2c;
case 0x0c0caf2eu: goto P_0c0caf2e;
case 0x0c0caf30u: goto P_0c0caf30;
case 0x0c0caf32u: goto P_0c0caf32;
case 0x0c0caf34u: goto P_0c0caf34;
case 0x0c0caf36u: goto P_0c0caf36;
case 0x0c0caf38u: goto P_0c0caf38;
case 0x0c0caf3au: goto P_0c0caf3a;
case 0x0c0caf3cu: goto P_0c0caf3c;
case 0x0c0caf3eu: goto P_0c0caf3e;
case 0x0c0caf40u: goto P_0c0caf40;
case 0x0c0caf42u: goto P_0c0caf42;
case 0x0c0caf44u: goto P_0c0caf44;
case 0x0c0caf46u: goto P_0c0caf46;
case 0x0c0caf48u: goto P_0c0caf48;
case 0x0c0caf4au: goto P_0c0caf4a;
case 0x0c0caf4cu: goto P_0c0caf4c;
case 0x0c0caf4eu: goto P_0c0caf4e;
case 0x0c0caf50u: goto P_0c0caf50;
case 0x0c0caf52u: goto P_0c0caf52;
case 0x0c0caf54u: goto P_0c0caf54;
case 0x0c0caf56u: goto P_0c0caf56;
case 0x0c0caf58u: goto P_0c0caf58;
case 0x0c0caf5au: goto P_0c0caf5a;
case 0x0c0caf5cu: goto P_0c0caf5c;
case 0x0c0cc5f4u: goto P_0c0cc5f4;
case 0x0c0cc5f6u: goto P_0c0cc5f6;
case 0x0c0cc5f8u: goto P_0c0cc5f8;
case 0x0c0cc5fau: goto P_0c0cc5fa;
case 0x0c0cc5fcu: goto P_0c0cc5fc;
case 0x0c0cc5feu: goto P_0c0cc5fe;
case 0x0c0cc600u: goto P_0c0cc600;
case 0x0c0cc602u: goto P_0c0cc602;
case 0x0c0cc604u: goto P_0c0cc604;
case 0x0c0cc606u: goto P_0c0cc606;
case 0x0c0cc608u: goto P_0c0cc608;
case 0x0c0cc60au: goto P_0c0cc60a;
case 0x0c0cc60cu: goto P_0c0cc60c;
case 0x0c0cc60eu: goto P_0c0cc60e;
case 0x0c0cc610u: goto P_0c0cc610;
case 0x0c0cc612u: goto P_0c0cc612;
case 0x0c0cc614u: goto P_0c0cc614;
case 0x0c0cc616u: goto P_0c0cc616;
case 0x0c0cc618u: goto P_0c0cc618;
case 0x0c0cc61au: goto P_0c0cc61a;
case 0x0c0cc61cu: goto P_0c0cc61c;
case 0x0c0cc61eu: goto P_0c0cc61e;
case 0x0c0cc620u: goto P_0c0cc620;
case 0x0c0cc622u: goto P_0c0cc622;
case 0x0c0cc624u: goto P_0c0cc624;
case 0x0c0cc626u: goto P_0c0cc626;
case 0x0c0cc628u: goto P_0c0cc628;
case 0x0c0cc62au: goto P_0c0cc62a;
case 0x0c0cc62cu: goto P_0c0cc62c;
case 0x0c0cc62eu: goto P_0c0cc62e;
case 0x0c0cc630u: goto P_0c0cc630;
case 0x0c0cc632u: goto P_0c0cc632;
case 0x0c0cc634u: goto P_0c0cc634;
case 0x0c0cc636u: goto P_0c0cc636;
case 0x0c0cc638u: goto P_0c0cc638;
case 0x0c0cc63au: goto P_0c0cc63a;
case 0x0c0cc63cu: goto P_0c0cc63c;
case 0x0c0cc63eu: goto P_0c0cc63e;
case 0x0c0cc640u: goto P_0c0cc640;
case 0x0c0cc642u: goto P_0c0cc642;
case 0x0c0cc644u: goto P_0c0cc644;
case 0x0c0cc646u: goto P_0c0cc646;
case 0x0c0cc648u: goto P_0c0cc648;
case 0x0c0cc64au: goto P_0c0cc64a;
case 0x0c0cc64cu: goto P_0c0cc64c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c074854: /* original 902d, guest PC 0x0c074854 */
if(!s->budget--) { s->failed_pc=0x0c074854u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b2u,2);
goto P_0c074856;
P_0c074856: /* original 7ff4, guest PC 0x0c074856 */
if(!s->budget--) { s->failed_pc=0x0c074856u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c074858;
P_0c074858: /* original 952c, guest PC 0x0c074858 */
if(!s->budget--) { s->failed_pc=0x0c074858u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b4u,2);
goto P_0c07485a;
P_0c07485a: /* original f446, guest PC 0x0c07485a */
if(!s->budget--) { s->failed_pc=0x0c07485au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c07485c;
P_0c07485c: /* original 7004, guest PC 0x0c07485c */
if(!s->budget--) { s->failed_pc=0x0c07485cu; return 0; }
r[0]+=0x00000004u;
goto P_0c07485e;
P_0c07485e: /* original f546, guest PC 0x0c07485e */
if(!s->budget--) { s->failed_pc=0x0c07485eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c074860;
P_0c074860: /* original 7004, guest PC 0x0c074860 */
if(!s->budget--) { s->failed_pc=0x0c074860u; return 0; }
r[0]+=0x00000004u;
goto P_0c074862;
P_0c074862: /* original f646, guest PC 0x0c074862 */
if(!s->budget--) { s->failed_pc=0x0c074862u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c074864;
P_0c074864: /* original e010, guest PC 0x0c074864 */
if(!s->budget--) { s->failed_pc=0x0c074864u; return 0; }
r[0]=0x00000010u;
goto P_0c074866;
P_0c074866: /* original f346, guest PC 0x0c074866 */
if(!s->budget--) { s->failed_pc=0x0c074866u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074868;
P_0c074868: /* original 354c, guest PC 0x0c074868 */
if(!s->budget--) { s->failed_pc=0x0c074868u; return 0; }
r[5]+=r[4];
goto P_0c07486a;
P_0c07486a: /* original 9624, guest PC 0x0c07486a */
if(!s->budget--) { s->failed_pc=0x0c07486au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b6u,2);
goto P_0c07486c;
P_0c07486c: /* original f340, guest PC 0x0c07486c */
if(!s->budget--) { s->failed_pc=0x0c07486cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07486e;
P_0c07486e: /* original 365c, guest PC 0x0c07486e */
if(!s->budget--) { s->failed_pc=0x0c07486eu; return 0; }
r[6]+=r[5];
goto P_0c074870;
P_0c074870: /* original 3560, guest PC 0x0c074870 */
if(!s->budget--) { s->failed_pc=0x0c074870u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074872;
P_0c074872: /* original f437, guest PC 0x0c074872 */
if(!s->budget--) { s->failed_pc=0x0c074872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074874;
P_0c074874: /* original e014, guest PC 0x0c074874 */
if(!s->budget--) { s->failed_pc=0x0c074874u; return 0; }
r[0]=0x00000014u;
goto P_0c074876;
P_0c074876: /* original f246, guest PC 0x0c074876 */
if(!s->budget--) { s->failed_pc=0x0c074876u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074878;
P_0c074878: /* original f250, guest PC 0x0c074878 */
if(!s->budget--) { s->failed_pc=0x0c074878u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07487a;
P_0c07487a: /* original f427, guest PC 0x0c07487a */
if(!s->budget--) { s->failed_pc=0x0c07487au; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07487c;
P_0c07487c: /* original e018, guest PC 0x0c07487c */
if(!s->budget--) { s->failed_pc=0x0c07487cu; return 0; }
r[0]=0x00000018u;
goto P_0c07487e;
P_0c07487e: /* original f346, guest PC 0x0c07487e */
if(!s->budget--) { s->failed_pc=0x0c07487eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074880;
P_0c074880: /* original f360, guest PC 0x0c074880 */
if(!s->budget--) { s->failed_pc=0x0c074880u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c074882;
P_0c074882: /* original 8d0f, guest PC 0x0c074882 */
if(!s->budget--) { s->failed_pc=0x0c074882u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c0748a4; }
goto P_0c074886;
P_0c074884: /* original f437, guest PC 0x0c074884 */
if(!s->budget--) { s->failed_pc=0x0c074884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074886;
P_0c074886: /* original e030, guest PC 0x0c074886 */
if(!s->budget--) { s->failed_pc=0x0c074886u; return 0; }
r[0]=0x00000030u;
goto P_0c074888;
P_0c074888: /* original f356, guest PC 0x0c074888 */
if(!s->budget--) { s->failed_pc=0x0c074888u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07488a;
P_0c07488a: /* original f340, guest PC 0x0c07488a */
if(!s->budget--) { s->failed_pc=0x0c07488au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07488c;
P_0c07488c: /* original f537, guest PC 0x0c07488c */
if(!s->budget--) { s->failed_pc=0x0c07488cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07488e;
P_0c07488e: /* original e034, guest PC 0x0c07488e */
if(!s->budget--) { s->failed_pc=0x0c07488eu; return 0; }
r[0]=0x00000034u;
goto P_0c074890;
P_0c074890: /* original f256, guest PC 0x0c074890 */
if(!s->budget--) { s->failed_pc=0x0c074890u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c074892;
P_0c074892: /* original f250, guest PC 0x0c074892 */
if(!s->budget--) { s->failed_pc=0x0c074892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074894;
P_0c074894: /* original f527, guest PC 0x0c074894 */
if(!s->budget--) { s->failed_pc=0x0c074894u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074896;
P_0c074896: /* original e038, guest PC 0x0c074896 */
if(!s->budget--) { s->failed_pc=0x0c074896u; return 0; }
r[0]=0x00000038u;
goto P_0c074898;
P_0c074898: /* original f356, guest PC 0x0c074898 */
if(!s->budget--) { s->failed_pc=0x0c074898u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07489a;
P_0c07489a: /* original f360, guest PC 0x0c07489a */
if(!s->budget--) { s->failed_pc=0x0c07489au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c07489c;
P_0c07489c: /* original f537, guest PC 0x0c07489c */
if(!s->budget--) { s->failed_pc=0x0c07489cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07489e;
P_0c07489e: /* original 7540, guest PC 0x0c07489e */
if(!s->budget--) { s->failed_pc=0x0c07489eu; return 0; }
r[5]+=0x00000040u;
goto P_0c0748a0;
P_0c0748a0: /* original 3560, guest PC 0x0c0748a0 */
if(!s->budget--) { s->failed_pc=0x0c0748a0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0748a2;
P_0c0748a2: /* original 8bf0, guest PC 0x0c0748a2 */
if(!s->budget--) { s->failed_pc=0x0c0748a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074886; }
goto P_0c0748a4;
P_0c0748a4: /* original 000b, guest PC 0x0c0748a4 */
if(!s->budget--) { s->failed_pc=0x0c0748a4u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c0748a6: /* original 7f0c, guest PC 0x0c0748a6 */
if(!s->budget--) { s->failed_pc=0x0c0748a6u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0748a8u,s,ram);
P_0c074e24: /* original 4f22, guest PC 0x0c074e24 */
if(!s->budget--) { s->failed_pc=0x0c074e24u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074e26;
P_0c074e26: /* original 6212, guest PC 0x0c074e26 */
if(!s->budget--) { s->failed_pc=0x0c074e26u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c074e28;
P_0c074e28: /* original d312, guest PC 0x0c074e28 */
if(!s->budget--) { s->failed_pc=0x0c074e28u; return 0; }
r[3]=read(ram,0x0c074e74u,4);
goto P_0c074e2a;
P_0c074e2a: /* original 5d44, guest PC 0x0c074e2a */
if(!s->budget--) { s->failed_pc=0x0c074e2au; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c074e2c;
P_0c074e2c: /* original 7ffc, guest PC 0x0c074e2c */
if(!s->budget--) { s->failed_pc=0x0c074e2cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c074e2e;
P_0c074e2e: /* original 2238, guest PC 0x0c074e2e */
if(!s->budget--) { s->failed_pc=0x0c074e2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074e30;
P_0c074e30: /* original 8f12, guest PC 0x0c074e30 */
if(!s->budget--) { s->failed_pc=0x0c074e30u; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[4]+20,4);
if(!cond) { goto P_0c074e58; }
goto P_0c074e34;
P_0c074e32: /* original 5e45, guest PC 0x0c074e32 */
if(!s->budget--) { s->failed_pc=0x0c074e32u; return 0; }
r[14]=read(ram,r[4]+20,4);
goto P_0c074e34;
P_0c074e34: /* original 65e3, guest PC 0x0c074e34 */
if(!s->budget--) { s->failed_pc=0x0c074e34u; return 0; }
r[5]=r[14];
goto P_0c074e36;
P_0c074e36: /* original b021, guest PC 0x0c074e36 */
if(!s->budget--) { s->failed_pc=0x0c074e36u; return 0; }
target=0x0c074e7cu; r[16]=0x0c074e3au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074e3au) { target=s->pc; goto dispatch; }
goto P_0c074e3a;
P_0c074e38: /* original 64d3, guest PC 0x0c074e38 */
if(!s->budget--) { s->failed_pc=0x0c074e38u; return 0; }
r[4]=r[13];
goto P_0c074e3a;
P_0c074e3a: /* original 65d3, guest PC 0x0c074e3a */
if(!s->budget--) { s->failed_pc=0x0c074e3au; return 0; }
r[5]=r[13];
goto P_0c074e3c;
P_0c074e3c: /* original b01e, guest PC 0x0c074e3c */
if(!s->budget--) { s->failed_pc=0x0c074e3cu; return 0; }
target=0x0c074e7cu; r[16]=0x0c074e40u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074e40u) { target=s->pc; goto dispatch; }
goto P_0c074e40;
P_0c074e3e: /* original 64e3, guest PC 0x0c074e3e */
if(!s->budget--) { s->failed_pc=0x0c074e3eu; return 0; }
r[4]=r[14];
goto P_0c074e40;
P_0c074e40: /* original 65e3, guest PC 0x0c074e40 */
if(!s->budget--) { s->failed_pc=0x0c074e40u; return 0; }
r[5]=r[14];
goto P_0c074e42;
P_0c074e42: /* original b04d, guest PC 0x0c074e42 */
if(!s->budget--) { s->failed_pc=0x0c074e42u; return 0; }
target=0x0c074ee0u; r[16]=0x0c074e46u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074e46u) { target=s->pc; goto dispatch; }
goto P_0c074e46;
P_0c074e44: /* original 64d3, guest PC 0x0c074e44 */
if(!s->budget--) { s->failed_pc=0x0c074e44u; return 0; }
r[4]=r[13];
goto P_0c074e46;
P_0c074e46: /* original 65d3, guest PC 0x0c074e46 */
if(!s->budget--) { s->failed_pc=0x0c074e46u; return 0; }
r[5]=r[13];
goto P_0c074e48;
P_0c074e48: /* original 2f02, guest PC 0x0c074e48 */
if(!s->budget--) { s->failed_pc=0x0c074e48u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c074e4a;
P_0c074e4a: /* original b049, guest PC 0x0c074e4a */
if(!s->budget--) { s->failed_pc=0x0c074e4au; return 0; }
target=0x0c074ee0u; r[16]=0x0c074e4eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074e4eu) { target=s->pc; goto dispatch; }
goto P_0c074e4e;
P_0c074e4c: /* original 64e3, guest PC 0x0c074e4c */
if(!s->budget--) { s->failed_pc=0x0c074e4cu; return 0; }
r[4]=r[14];
goto P_0c074e4e;
P_0c074e4e: /* original 66f2, guest PC 0x0c074e4e */
if(!s->budget--) { s->failed_pc=0x0c074e4eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c074e50;
P_0c074e50: /* original 65e3, guest PC 0x0c074e50 */
if(!s->budget--) { s->failed_pc=0x0c074e50u; return 0; }
r[5]=r[14];
goto P_0c074e52;
P_0c074e52: /* original 6703, guest PC 0x0c074e52 */
if(!s->budget--) { s->failed_pc=0x0c074e52u; return 0; }
r[7]=r[0];
goto P_0c074e54;
P_0c074e54: /* original b0cb, guest PC 0x0c074e54 */
if(!s->budget--) { s->failed_pc=0x0c074e54u; return 0; }
target=0x0c074feeu; r[16]=0x0c074e58u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074e58u) { target=s->pc; goto dispatch; }
goto P_0c074e58;
P_0c074e56: /* original 64d3, guest PC 0x0c074e56 */
if(!s->budget--) { s->failed_pc=0x0c074e56u; return 0; }
r[4]=r[13];
goto P_0c074e58;
P_0c074e58: /* original 7f04, guest PC 0x0c074e58 */
if(!s->budget--) { s->failed_pc=0x0c074e58u; return 0; }
r[15]+=0x00000004u;
goto P_0c074e5a;
P_0c074e5a: /* original 4f26, guest PC 0x0c074e5a */
if(!s->budget--) { s->failed_pc=0x0c074e5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074e5c;
P_0c074e5c: /* original 6df6, guest PC 0x0c074e5c */
if(!s->budget--) { s->failed_pc=0x0c074e5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c074e5e;
P_0c074e5e: /* original 000b, guest PC 0x0c074e5e */
if(!s->budget--) { s->failed_pc=0x0c074e5eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074e60: /* original 6ef6, guest PC 0x0c074e60 */
if(!s->budget--) { s->failed_pc=0x0c074e60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c074e62u,s,ram);
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=0x0c07b6deu; r[16]=0x0c07b6d6u;
r[7]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=0x0c07b6ecu;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
return vf3_matrix_family(0x0c07b6f4u,s,ram);
P_0c07c9ec: /* original 4f22, guest PC 0x0c07c9ec */
if(!s->budget--) { s->failed_pc=0x0c07c9ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c9ee;
P_0c07c9ee: /* original 6030, guest PC 0x0c07c9ee */
if(!s->budget--) { s->failed_pc=0x0c07c9eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c07c9f0;
P_0c07c9f0: /* original 8801, guest PC 0x0c07c9f0 */
if(!s->budget--) { s->failed_pc=0x0c07c9f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07c9f2;
P_0c07c9f2: /* original 8902, guest PC 0x0c07c9f2 */
if(!s->budget--) { s->failed_pc=0x0c07c9f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c9fa; }
goto P_0c07c9f4;
P_0c07c9f4: /* original 9d38, guest PC 0x0c07c9f4 */
if(!s->budget--) { s->failed_pc=0x0c07c9f4u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca68u,2);
goto P_0c07c9f6;
P_0c07c9f6: /* original a001, guest PC 0x0c07c9f6 */
if(!s->budget--) { s->failed_pc=0x0c07c9f6u; return 0; }
goto P_0c07c9fc;
P_0c07c9f8: /* original 0009, guest PC 0x0c07c9f8 */
if(!s->budget--) { s->failed_pc=0x0c07c9f8u; return 0; }
goto P_0c07c9fa;
P_0c07c9fa: /* original 9d36, guest PC 0x0c07c9fa */
if(!s->budget--) { s->failed_pc=0x0c07c9fau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca6au,2);
goto P_0c07c9fc;
P_0c07c9fc: /* original de1e, guest PC 0x0c07c9fc */
if(!s->budget--) { s->failed_pc=0x0c07c9fcu; return 0; }
r[14]=read(ram,0x0c07ca78u,4);
goto P_0c07c9fe;
P_0c07c9fe: /* original e301, guest PC 0x0c07c9fe */
if(!s->budget--) { s->failed_pc=0x0c07c9feu; return 0; }
r[3]=0x00000001u;
goto P_0c07ca00;
P_0c07ca00: /* original 2f36, guest PC 0x0c07ca00 */
if(!s->budget--) { s->failed_pc=0x0c07ca00u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07ca02;
P_0c07ca02: /* original e700, guest PC 0x0c07ca02 */
if(!s->budget--) { s->failed_pc=0x0c07ca02u; return 0; }
r[7]=0x00000000u;
goto P_0c07ca04;
P_0c07ca04: /* original 9532, guest PC 0x0c07ca04 */
if(!s->budget--) { s->failed_pc=0x0c07ca04u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca6cu,2);
goto P_0c07ca06;
P_0c07ca06: /* original 66e3, guest PC 0x0c07ca06 */
if(!s->budget--) { s->failed_pc=0x0c07ca06u; return 0; }
r[6]=r[14];
goto P_0c07ca08;
P_0c07ca08: /* original d21f, guest PC 0x0c07ca08 */
if(!s->budget--) { s->failed_pc=0x0c07ca08u; return 0; }
r[2]=read(ram,0x0c07ca88u,4);
goto P_0c07ca0a;
P_0c07ca0a: /* original 420b, guest PC 0x0c07ca0a */
if(!s->budget--) { s->failed_pc=0x0c07ca0au; return 0; }
target=r[2];
r[16]=0x0c07ca0eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ca0eu) { target=s->pc; goto dispatch; }
goto P_0c07ca0e;
P_0c07ca0c: /* original 64d3, guest PC 0x0c07ca0c */
if(!s->budget--) { s->failed_pc=0x0c07ca0cu; return 0; }
r[4]=r[13];
goto P_0c07ca0e;
P_0c07ca0e: /* original e301, guest PC 0x0c07ca0e */
if(!s->budget--) { s->failed_pc=0x0c07ca0eu; return 0; }
r[3]=0x00000001u;
goto P_0c07ca10;
P_0c07ca10: /* original 2f36, guest PC 0x0c07ca10 */
if(!s->budget--) { s->failed_pc=0x0c07ca10u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07ca12;
P_0c07ca12: /* original e700, guest PC 0x0c07ca12 */
if(!s->budget--) { s->failed_pc=0x0c07ca12u; return 0; }
r[7]=0x00000000u;
goto P_0c07ca14;
P_0c07ca14: /* original 942c, guest PC 0x0c07ca14 */
if(!s->budget--) { s->failed_pc=0x0c07ca14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca70u,2);
goto P_0c07ca16;
P_0c07ca16: /* original 952a, guest PC 0x0c07ca16 */
if(!s->budget--) { s->failed_pc=0x0c07ca16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca6eu,2);
goto P_0c07ca18;
P_0c07ca18: /* original d21b, guest PC 0x0c07ca18 */
if(!s->budget--) { s->failed_pc=0x0c07ca18u; return 0; }
r[2]=read(ram,0x0c07ca88u,4);
goto P_0c07ca1a;
P_0c07ca1a: /* original 420b, guest PC 0x0c07ca1a */
if(!s->budget--) { s->failed_pc=0x0c07ca1au; return 0; }
target=r[2];
r[16]=0x0c07ca1eu;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ca1eu) { target=s->pc; goto dispatch; }
goto P_0c07ca1e;
P_0c07ca1c: /* original 66e3, guest PC 0x0c07ca1c */
if(!s->budget--) { s->failed_pc=0x0c07ca1cu; return 0; }
r[6]=r[14];
goto P_0c07ca1e;
P_0c07ca1e: /* original 7f08, guest PC 0x0c07ca1e */
if(!s->budget--) { s->failed_pc=0x0c07ca1eu; return 0; }
r[15]+=0x00000008u;
goto P_0c07ca20;
P_0c07ca20: /* original 9026, guest PC 0x0c07ca20 */
if(!s->budget--) { s->failed_pc=0x0c07ca20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca70u,2);
goto P_0c07ca22;
P_0c07ca22: /* original 4f26, guest PC 0x0c07ca22 */
if(!s->budget--) { s->failed_pc=0x0c07ca22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ca24;
P_0c07ca24: /* original 6df6, guest PC 0x0c07ca24 */
if(!s->budget--) { s->failed_pc=0x0c07ca24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ca26;
P_0c07ca26: /* original 000b, guest PC 0x0c07ca26 */
if(!s->budget--) { s->failed_pc=0x0c07ca26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ca28: /* original 6ef6, guest PC 0x0c07ca28 */
if(!s->budget--) { s->failed_pc=0x0c07ca28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ca2au,s,ram);
P_0c084faa: /* original 4f22, guest PC 0x0c084faa */
if(!s->budget--) { s->failed_pc=0x0c084faau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084fac;
P_0c084fac: /* original 8441, guest PC 0x0c084fac */
if(!s->budget--) { s->failed_pc=0x0c084facu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c084fae;
P_0c084fae: /* original 6540, guest PC 0x0c084fae */
if(!s->budget--) { s->failed_pc=0x0c084faeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c084fb0;
P_0c084fb0: /* original 7ff8, guest PC 0x0c084fb0 */
if(!s->budget--) { s->failed_pc=0x0c084fb0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c084fb2;
P_0c084fb2: /* original 1f01, guest PC 0x0c084fb2 */
if(!s->budget--) { s->failed_pc=0x0c084fb2u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c084fb4;
P_0c084fb4: /* original e061, guest PC 0x0c084fb4 */
if(!s->budget--) { s->failed_pc=0x0c084fb4u; return 0; }
r[0]=0x00000061u;
goto P_0c084fb6;
P_0c084fb6: /* original d313, guest PC 0x0c084fb6 */
if(!s->budget--) { s->failed_pc=0x0c084fb6u; return 0; }
r[3]=read(ram,0x0c085004u,4);
goto P_0c084fb8;
P_0c084fb8: /* original 6432, guest PC 0x0c084fb8 */
if(!s->budget--) { s->failed_pc=0x0c084fb8u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c084fba;
P_0c084fba: /* original 004c, guest PC 0x0c084fba */
if(!s->budget--) { s->failed_pc=0x0c084fbau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c084fbc;
P_0c084fbc: /* original 600c, guest PC 0x0c084fbc */
if(!s->budget--) { s->failed_pc=0x0c084fbcu; return 0; }
r[0]=r[0]&255u;
goto P_0c084fbe;
P_0c084fbe: /* original 8809, guest PC 0x0c084fbe */
if(!s->budget--) { s->failed_pc=0x0c084fbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c084fc0;
P_0c084fc0: /* original 8b04, guest PC 0x0c084fc0 */
if(!s->budget--) { s->failed_pc=0x0c084fc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084fcc; }
goto P_0c084fc2;
P_0c084fc2: /* original d011, guest PC 0x0c084fc2 */
if(!s->budget--) { s->failed_pc=0x0c084fc2u; return 0; }
r[0]=read(ram,0x0c085008u,4);
goto P_0c084fc4;
P_0c084fc4: /* original 4508, guest PC 0x0c084fc4 */
if(!s->budget--) { s->failed_pc=0x0c084fc4u; return 0; }
r[5]<<=2;
goto P_0c084fc6;
P_0c084fc6: /* original 015e, guest PC 0x0c084fc6 */
if(!s->budget--) { s->failed_pc=0x0c084fc6u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c084fc8;
P_0c084fc8: /* original 410b, guest PC 0x0c084fc8 */
if(!s->budget--) { s->failed_pc=0x0c084fc8u; return 0; }
target=r[1];
r[16]=0x0c084fccu;
write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c084fccu) { target=s->pc; goto dispatch; }
goto P_0c084fcc;
P_0c084fca: /* original 2f12, guest PC 0x0c084fca */
if(!s->budget--) { s->failed_pc=0x0c084fcau; return 0; }
write(ram,r[15],r[1],4);
goto P_0c084fcc;
P_0c084fcc: /* original d30f, guest PC 0x0c084fcc */
if(!s->budget--) { s->failed_pc=0x0c084fccu; return 0; }
r[3]=read(ram,0x0c08500cu,4);
goto P_0c084fce;
P_0c084fce: /* original e061, guest PC 0x0c084fce */
if(!s->budget--) { s->failed_pc=0x0c084fceu; return 0; }
r[0]=0x00000061u;
goto P_0c084fd0;
P_0c084fd0: /* original 6432, guest PC 0x0c084fd0 */
if(!s->budget--) { s->failed_pc=0x0c084fd0u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c084fd2;
P_0c084fd2: /* original 004c, guest PC 0x0c084fd2 */
if(!s->budget--) { s->failed_pc=0x0c084fd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c084fd4;
P_0c084fd4: /* original 600c, guest PC 0x0c084fd4 */
if(!s->budget--) { s->failed_pc=0x0c084fd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c084fd6;
P_0c084fd6: /* original 8809, guest PC 0x0c084fd6 */
if(!s->budget--) { s->failed_pc=0x0c084fd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c084fd8;
P_0c084fd8: /* original 8b07, guest PC 0x0c084fd8 */
if(!s->budget--) { s->failed_pc=0x0c084fd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c084fea; }
goto P_0c084fda;
P_0c084fda: /* original 51f1, guest PC 0x0c084fda */
if(!s->budget--) { s->failed_pc=0x0c084fdau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c084fdc;
P_0c084fdc: /* original d00a, guest PC 0x0c084fdc */
if(!s->budget--) { s->failed_pc=0x0c084fdcu; return 0; }
r[0]=read(ram,0x0c085008u,4);
goto P_0c084fde;
P_0c084fde: /* original 4108, guest PC 0x0c084fde */
if(!s->budget--) { s->failed_pc=0x0c084fdeu; return 0; }
r[1]<<=2;
goto P_0c084fe0;
P_0c084fe0: /* original 021e, guest PC 0x0c084fe0 */
if(!s->budget--) { s->failed_pc=0x0c084fe0u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c084fe2;
P_0c084fe2: /* original 2f22, guest PC 0x0c084fe2 */
if(!s->budget--) { s->failed_pc=0x0c084fe2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c084fe4;
P_0c084fe4: /* original 7f08, guest PC 0x0c084fe4 */
if(!s->budget--) { s->failed_pc=0x0c084fe4u; return 0; }
r[15]+=0x00000008u;
goto P_0c084fe6;
P_0c084fe6: /* original 422b, guest PC 0x0c084fe6 */
if(!s->budget--) { s->failed_pc=0x0c084fe6u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c084fe8: /* original 4f26, guest PC 0x0c084fe8 */
if(!s->budget--) { s->failed_pc=0x0c084fe8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084fea;
P_0c084fea: /* original 7f08, guest PC 0x0c084fea */
if(!s->budget--) { s->failed_pc=0x0c084feau; return 0; }
r[15]+=0x00000008u;
goto P_0c084fec;
P_0c084fec: /* original 4f26, guest PC 0x0c084fec */
if(!s->budget--) { s->failed_pc=0x0c084fecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084fee;
P_0c084fee: /* original 000b, guest PC 0x0c084fee */
if(!s->budget--) { s->failed_pc=0x0c084feeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c084ff0: /* original 0009, guest PC 0x0c084ff0 */
if(!s->budget--) { s->failed_pc=0x0c084ff0u; return 0; }
return vf3_matrix_family(0x0c084ff2u,s,ram);
P_0c08b430: /* original 2fe6, guest PC 0x0c08b430 */
if(!s->budget--) { s->failed_pc=0x0c08b430u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08b432;
P_0c08b432: /* original 6e73, guest PC 0x0c08b432 */
if(!s->budget--) { s->failed_pc=0x0c08b432u; return 0; }
r[14]=r[7];
goto P_0c08b434;
P_0c08b434: /* original 2fd6, guest PC 0x0c08b434 */
if(!s->budget--) { s->failed_pc=0x0c08b434u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08b436;
P_0c08b436: /* original 2fc6, guest PC 0x0c08b436 */
if(!s->budget--) { s->failed_pc=0x0c08b436u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08b438;
P_0c08b438: /* original 6c53, guest PC 0x0c08b438 */
if(!s->budget--) { s->failed_pc=0x0c08b438u; return 0; }
r[12]=r[5];
goto P_0c08b43a;
P_0c08b43a: /* original 2fb6, guest PC 0x0c08b43a */
if(!s->budget--) { s->failed_pc=0x0c08b43au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c08b43c;
P_0c08b43c: /* original 2fa6, guest PC 0x0c08b43c */
if(!s->budget--) { s->failed_pc=0x0c08b43cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c08b43e;
P_0c08b43e: /* original 2f96, guest PC 0x0c08b43e */
if(!s->budget--) { s->failed_pc=0x0c08b43eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c08b440;
P_0c08b440: /* original 6943, guest PC 0x0c08b440 */
if(!s->budget--) { s->failed_pc=0x0c08b440u; return 0; }
r[9]=r[4];
goto P_0c08b442;
P_0c08b442: /* original 2f86, guest PC 0x0c08b442 */
if(!s->budget--) { s->failed_pc=0x0c08b442u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c08b444;
P_0c08b444: /* original 7964, guest PC 0x0c08b444 */
if(!s->budget--) { s->failed_pc=0x0c08b444u; return 0; }
r[9]+=0x00000064u;
goto P_0c08b446;
P_0c08b446: /* original fffb, guest PC 0x0c08b446 */
if(!s->budget--) { s->failed_pc=0x0c08b446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b448;
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=0x0c08b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=0x0c08b480u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=0x0c08b4b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b4deu,s,ram);
P_0c08b5ae: /* original 4f22, guest PC 0x0c08b5ae */
if(!s->budget--) { s->failed_pc=0x0c08b5aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b5b0;
P_0c08b5b0: /* original bf2c, guest PC 0x0c08b5b0 */
if(!s->budget--) { s->failed_pc=0x0c08b5b0u; return 0; }
target=0x0c08b40cu; r[16]=0x0c08b5b4u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b5b4u) { target=s->pc; goto dispatch; }
goto P_0c08b5b4;
P_0c08b5b2: /* original 6e43, guest PC 0x0c08b5b2 */
if(!s->budget--) { s->failed_pc=0x0c08b5b2u; return 0; }
r[14]=r[4];
goto P_0c08b5b4;
P_0c08b5b4: /* original 2008, guest PC 0x0c08b5b4 */
if(!s->budget--) { s->failed_pc=0x0c08b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c08b5b6;
P_0c08b5b6: /* original 8b0d, guest PC 0x0c08b5b6 */
if(!s->budget--) { s->failed_pc=0x0c08b5b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b5d4; }
goto P_0c08b5b8;
P_0c08b5b8: /* original e010, guest PC 0x0c08b5b8 */
if(!s->budget--) { s->failed_pc=0x0c08b5b8u; return 0; }
r[0]=0x00000010u;
goto P_0c08b5ba;
P_0c08b5ba: /* original 9336, guest PC 0x0c08b5ba */
if(!s->budget--) { s->failed_pc=0x0c08b5bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b62au,2);
goto P_0c08b5bc;
P_0c08b5bc: /* original 04ec, guest PC 0x0c08b5bc */
if(!s->budget--) { s->failed_pc=0x0c08b5bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b5be;
P_0c08b5be: /* original 3430, guest PC 0x0c08b5be */
if(!s->budget--) { s->failed_pc=0x0c08b5beu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08b5c0;
P_0c08b5c0: /* original 8908, guest PC 0x0c08b5c0 */
if(!s->budget--) { s->failed_pc=0x0c08b5c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b5d4; }
goto P_0c08b5c2;
P_0c08b5c2: /* original bf8c, guest PC 0x0c08b5c2 */
if(!s->budget--) { s->failed_pc=0x0c08b5c2u; return 0; }
target=0x0c08b4deu; r[16]=0x0c08b5c6u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b5c6u) { target=s->pc; goto dispatch; }
goto P_0c08b5c6;
P_0c08b5c4: /* original 04ec, guest PC 0x0c08b5c4 */
if(!s->budget--) { s->failed_pc=0x0c08b5c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b5c6;
P_0c08b5c6: /* original 4f26, guest PC 0x0c08b5c6 */
if(!s->budget--) { s->failed_pc=0x0c08b5c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b5c8;
P_0c08b5c8: /* original 64e3, guest PC 0x0c08b5c8 */
if(!s->budget--) { s->failed_pc=0x0c08b5c8u; return 0; }
r[4]=r[14];
goto P_0c08b5ca;
P_0c08b5ca: /* original e50c, guest PC 0x0c08b5ca */
if(!s->budget--) { s->failed_pc=0x0c08b5cau; return 0; }
r[5]=0x0000000cu;
goto P_0c08b5cc;
P_0c08b5cc: /* original 6703, guest PC 0x0c08b5cc */
if(!s->budget--) { s->failed_pc=0x0c08b5ccu; return 0; }
r[7]=r[0];
goto P_0c08b5ce;
P_0c08b5ce: /* original e600, guest PC 0x0c08b5ce */
if(!s->budget--) { s->failed_pc=0x0c08b5ceu; return 0; }
r[6]=0x00000000u;
goto P_0c08b5d0;
P_0c08b5d0: /* original af2e, guest PC 0x0c08b5d0 */
if(!s->budget--) { s->failed_pc=0x0c08b5d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b430;
P_0c08b5d2: /* original 6ef6, guest PC 0x0c08b5d2 */
if(!s->budget--) { s->failed_pc=0x0c08b5d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b5d4;
P_0c08b5d4: /* original 4f26, guest PC 0x0c08b5d4 */
if(!s->budget--) { s->failed_pc=0x0c08b5d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b5d6;
P_0c08b5d6: /* original 000b, guest PC 0x0c08b5d6 */
if(!s->budget--) { s->failed_pc=0x0c08b5d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b5d8: /* original 6ef6, guest PC 0x0c08b5d8 */
if(!s->budget--) { s->failed_pc=0x0c08b5d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b5dau,s,ram);
P_0c091dbe: /* original 4f22, guest PC 0x0c091dbe */
if(!s->budget--) { s->failed_pc=0x0c091dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091dc0;
P_0c091dc0: /* original 7ffc, guest PC 0x0c091dc0 */
if(!s->budget--) { s->failed_pc=0x0c091dc0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c091dc2;
P_0c091dc2: /* original 2f42, guest PC 0x0c091dc2 */
if(!s->budget--) { s->failed_pc=0x0c091dc2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c091dc4;
P_0c091dc4: /* original d12b, guest PC 0x0c091dc4 */
if(!s->budget--) { s->failed_pc=0x0c091dc4u; return 0; }
r[1]=read(ram,0x0c091e74u,4);
goto P_0c091dc6;
P_0c091dc6: /* original d32a, guest PC 0x0c091dc6 */
if(!s->budget--) { s->failed_pc=0x0c091dc6u; return 0; }
r[3]=read(ram,0x0c091e70u,4);
goto P_0c091dc8;
P_0c091dc8: /* original 6212, guest PC 0x0c091dc8 */
if(!s->budget--) { s->failed_pc=0x0c091dc8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c091dca;
P_0c091dca: /* original 2238, guest PC 0x0c091dca */
if(!s->budget--) { s->failed_pc=0x0c091dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091dcc;
P_0c091dcc: /* original 8b07, guest PC 0x0c091dcc */
if(!s->budget--) { s->failed_pc=0x0c091dccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091dde; }
goto P_0c091dce;
P_0c091dce: /* original 9348, guest PC 0x0c091dce */
if(!s->budget--) { s->failed_pc=0x0c091dceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e62u,2);
goto P_0c091dd0;
P_0c091dd0: /* original 64f2, guest PC 0x0c091dd0 */
if(!s->budget--) { s->failed_pc=0x0c091dd0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dd2;
P_0c091dd2: /* original b008, guest PC 0x0c091dd2 */
if(!s->budget--) { s->failed_pc=0x0c091dd2u; return 0; }
target=0x0c091de6u; r[16]=0x0c091dd6u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091dd6u) { target=s->pc; goto dispatch; }
goto P_0c091dd6;
P_0c091dd4: /* original 343c, guest PC 0x0c091dd4 */
if(!s->budget--) { s->failed_pc=0x0c091dd4u; return 0; }
r[4]+=r[3];
goto P_0c091dd6;
P_0c091dd6: /* original 9345, guest PC 0x0c091dd6 */
if(!s->budget--) { s->failed_pc=0x0c091dd6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091e64u,2);
goto P_0c091dd8;
P_0c091dd8: /* original 64f2, guest PC 0x0c091dd8 */
if(!s->budget--) { s->failed_pc=0x0c091dd8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c091dda;
P_0c091dda: /* original b004, guest PC 0x0c091dda */
if(!s->budget--) { s->failed_pc=0x0c091ddau; return 0; }
target=0x0c091de6u; r[16]=0x0c091ddeu;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ddeu) { target=s->pc; goto dispatch; }
goto P_0c091dde;
P_0c091ddc: /* original 343c, guest PC 0x0c091ddc */
if(!s->budget--) { s->failed_pc=0x0c091ddcu; return 0; }
r[4]+=r[3];
goto P_0c091dde;
P_0c091dde: /* original 7f04, guest PC 0x0c091dde */
if(!s->budget--) { s->failed_pc=0x0c091ddeu; return 0; }
r[15]+=0x00000004u;
goto P_0c091de0;
P_0c091de0: /* original 4f26, guest PC 0x0c091de0 */
if(!s->budget--) { s->failed_pc=0x0c091de0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091de2;
P_0c091de2: /* original 000b, guest PC 0x0c091de2 */
if(!s->budget--) { s->failed_pc=0x0c091de2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c091de4: /* original 0009, guest PC 0x0c091de4 */
if(!s->budget--) { s->failed_pc=0x0c091de4u; return 0; }
return vf3_matrix_family(0x0c091de6u,s,ram);
P_0c092270: /* original 4f22, guest PC 0x0c092270 */
if(!s->budget--) { s->failed_pc=0x0c092270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c092272;
P_0c092272: /* original 7301, guest PC 0x0c092272 */
if(!s->budget--) { s->failed_pc=0x0c092272u; return 0; }
r[3]+=0x00000001u;
goto P_0c092274;
P_0c092274: /* original 0e35, guest PC 0x0c092274 */
if(!s->budget--) { s->failed_pc=0x0c092274u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c092276;
P_0c092276: /* original d121, guest PC 0x0c092276 */
if(!s->budget--) { s->failed_pc=0x0c092276u; return 0; }
r[1]=read(ram,0x0c0922fcu,4);
goto P_0c092278;
P_0c092278: /* original d31f, guest PC 0x0c092278 */
if(!s->budget--) { s->failed_pc=0x0c092278u; return 0; }
r[3]=read(ram,0x0c0922f8u,4);
goto P_0c09227a;
P_0c09227a: /* original 6212, guest PC 0x0c09227a */
if(!s->budget--) { s->failed_pc=0x0c09227au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09227c;
P_0c09227c: /* original 2238, guest PC 0x0c09227c */
if(!s->budget--) { s->failed_pc=0x0c09227cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09227e;
P_0c09227e: /* original 8b06, guest PC 0x0c09227e */
if(!s->budget--) { s->failed_pc=0x0c09227eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09228e; }
goto P_0c092280;
P_0c092280: /* original b008, guest PC 0x0c092280 */
if(!s->budget--) { s->failed_pc=0x0c092280u; return 0; }
target=0x0c092294u; r[16]=0x0c092284u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092284u) { target=s->pc; goto dispatch; }
goto P_0c092284;
P_0c092282: /* original 64e3, guest PC 0x0c092282 */
if(!s->budget--) { s->failed_pc=0x0c092282u; return 0; }
r[4]=r[14];
goto P_0c092284;
P_0c092284: /* original b11a, guest PC 0x0c092284 */
if(!s->budget--) { s->failed_pc=0x0c092284u; return 0; }
target=0x0c0924bcu; r[16]=0x0c092288u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092288u) { target=s->pc; goto dispatch; }
goto P_0c092288;
P_0c092286: /* original 64e3, guest PC 0x0c092286 */
if(!s->budget--) { s->failed_pc=0x0c092286u; return 0; }
r[4]=r[14];
goto P_0c092288;
P_0c092288: /* original d31d, guest PC 0x0c092288 */
if(!s->budget--) { s->failed_pc=0x0c092288u; return 0; }
r[3]=read(ram,0x0c092300u,4);
goto P_0c09228a;
P_0c09228a: /* original 430b, guest PC 0x0c09228a */
if(!s->budget--) { s->failed_pc=0x0c09228au; return 0; }
target=r[3];
r[16]=0x0c09228eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09228eu) { target=s->pc; goto dispatch; }
goto P_0c09228e;
P_0c09228c: /* original 64e3, guest PC 0x0c09228c */
if(!s->budget--) { s->failed_pc=0x0c09228cu; return 0; }
r[4]=r[14];
goto P_0c09228e;
P_0c09228e: /* original 4f26, guest PC 0x0c09228e */
if(!s->budget--) { s->failed_pc=0x0c09228eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c092290;
P_0c092290: /* original 000b, guest PC 0x0c092290 */
if(!s->budget--) { s->failed_pc=0x0c092290u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092292: /* original 6ef6, guest PC 0x0c092292 */
if(!s->budget--) { s->failed_pc=0x0c092292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c092294;
P_0c092294: /* original 2fe6, guest PC 0x0c092294 */
if(!s->budget--) { s->failed_pc=0x0c092294u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c092296;
P_0c092296: /* original 6e43, guest PC 0x0c092296 */
if(!s->budget--) { s->failed_pc=0x0c092296u; return 0; }
r[14]=r[4];
goto P_0c092298;
P_0c092298: /* original 2fd6, guest PC 0x0c092298 */
if(!s->budget--) { s->failed_pc=0x0c092298u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c09229a;
P_0c09229a: /* original 2fc6, guest PC 0x0c09229a */
if(!s->budget--) { s->failed_pc=0x0c09229au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c09229c;
P_0c09229c: /* original 2fb6, guest PC 0x0c09229c */
if(!s->budget--) { s->failed_pc=0x0c09229cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c09229e;
P_0c09229e: /* original 2fa6, guest PC 0x0c09229e */
if(!s->budget--) { s->failed_pc=0x0c09229eu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0922a0;
P_0c0922a0: /* original 2f96, guest PC 0x0c0922a0 */
if(!s->budget--) { s->failed_pc=0x0c0922a0u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0922a2;
P_0c0922a2: /* original fffb, guest PC 0x0c0922a2 */
if(!s->budget--) { s->failed_pc=0x0c0922a2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0922a4;
P_0c0922a4: /* original ffeb, guest PC 0x0c0922a4 */
if(!s->budget--) { s->failed_pc=0x0c0922a4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0922a6;
P_0c0922a6: /* original 85e8, guest PC 0x0c0922a6 */
if(!s->budget--) { s->failed_pc=0x0c0922a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
return vf3_matrix_family(0x0c0922a8u,s,ram);
P_0c0924bc: /* original 2fe6, guest PC 0x0c0924bc */
if(!s->budget--) { s->failed_pc=0x0c0924bcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0924be;
P_0c0924be: /* original 2fd6, guest PC 0x0c0924be */
if(!s->budget--) { s->failed_pc=0x0c0924beu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0924c0;
P_0c0924c0: /* original 6d43, guest PC 0x0c0924c0 */
if(!s->budget--) { s->failed_pc=0x0c0924c0u; return 0; }
r[13]=r[4];
goto P_0c0924c2;
P_0c0924c2: /* original 2fc6, guest PC 0x0c0924c2 */
if(!s->budget--) { s->failed_pc=0x0c0924c2u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0924c4;
P_0c0924c4: /* original 2fb6, guest PC 0x0c0924c4 */
if(!s->budget--) { s->failed_pc=0x0c0924c4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0924c6;
P_0c0924c6: /* original 2fa6, guest PC 0x0c0924c6 */
if(!s->budget--) { s->failed_pc=0x0c0924c6u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0924c8;
P_0c0924c8: /* original 2f96, guest PC 0x0c0924c8 */
if(!s->budget--) { s->failed_pc=0x0c0924c8u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0924ca;
P_0c0924ca: /* original d42c, guest PC 0x0c0924ca */
if(!s->budget--) { s->failed_pc=0x0c0924cau; return 0; }
r[4]=read(ram,0x0c09257cu,4);
goto P_0c0924cc;
P_0c0924cc: /* original d32c, guest PC 0x0c0924cc */
if(!s->budget--) { s->failed_pc=0x0c0924ccu; return 0; }
r[3]=read(ram,0x0c092580u,4);
goto P_0c0924ce;
P_0c0924ce: /* original 6242, guest PC 0x0c0924ce */
if(!s->budget--) { s->failed_pc=0x0c0924ceu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
return vf3_matrix_family(0x0c0924d0u,s,ram);
P_0c092550: /* original 4f22, guest PC 0x0c092550 */
if(!s->budget--) { s->failed_pc=0x0c092550u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c092552;
P_0c092552: /* original 6ddc, guest PC 0x0c092552 */
if(!s->budget--) { s->failed_pc=0x0c092552u; return 0; }
r[13]=r[13]&255u;
goto P_0c092554;
P_0c092554: /* original d010, guest PC 0x0c092554 */
if(!s->budget--) { s->failed_pc=0x0c092554u; return 0; }
r[0]=read(ram,0x0c092598u,4);
goto P_0c092556;
P_0c092556: /* original 4d08, guest PC 0x0c092556 */
if(!s->budget--) { s->failed_pc=0x0c092556u; return 0; }
r[13]<<=2;
goto P_0c092558;
P_0c092558: /* original d310, guest PC 0x0c092558 */
if(!s->budget--) { s->failed_pc=0x0c092558u; return 0; }
r[3]=read(ram,0x0c09259cu,4);
goto P_0c09255a;
P_0c09255a: /* original 0dde, guest PC 0x0c09255a */
if(!s->budget--) { s->failed_pc=0x0c09255au; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c09255c;
P_0c09255c: /* original 7ff4, guest PC 0x0c09255c */
if(!s->budget--) { s->failed_pc=0x0c09255cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09255e;
P_0c09255e: /* original 430b, guest PC 0x0c09255e */
if(!s->budget--) { s->failed_pc=0x0c09255eu; return 0; }
target=r[3];
r[16]=0x0c092562u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c092562u) { target=s->pc; goto dispatch; }
goto P_0c092562;
P_0c092560: /* original e400, guest PC 0x0c092560 */
if(!s->budget--) { s->failed_pc=0x0c092560u; return 0; }
r[4]=0x00000000u;
goto P_0c092562;
P_0c092562: /* original d210, guest PC 0x0c092562 */
if(!s->budget--) { s->failed_pc=0x0c092562u; return 0; }
r[2]=read(ram,0x0c0925a4u,4);
goto P_0c092564;
P_0c092564: /* original db0e, guest PC 0x0c092564 */
if(!s->budget--) { s->failed_pc=0x0c092564u; return 0; }
r[11]=read(ram,0x0c0925a0u,4);
goto P_0c092566;
P_0c092566: /* original 422b, guest PC 0x0c092566 */
if(!s->budget--) { s->failed_pc=0x0c092566u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c092568: /* original 0009, guest PC 0x0c092568 */
if(!s->budget--) { s->failed_pc=0x0c092568u; return 0; }
return vf3_matrix_family(0x0c09256au,s,ram);
P_0c0926ba: /* original 2fe6, guest PC 0x0c0926ba */
if(!s->budget--) { s->failed_pc=0x0c0926bau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0926bc;
P_0c0926bc: /* original 6e43, guest PC 0x0c0926bc */
if(!s->budget--) { s->failed_pc=0x0c0926bcu; return 0; }
r[14]=r[4];
goto P_0c0926be;
P_0c0926be: /* original 2fd6, guest PC 0x0c0926be */
if(!s->budget--) { s->failed_pc=0x0c0926beu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0926c0;
P_0c0926c0: /* original 2fc6, guest PC 0x0c0926c0 */
if(!s->budget--) { s->failed_pc=0x0c0926c0u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0926c2;
P_0c0926c2: /* original 2fb6, guest PC 0x0c0926c2 */
if(!s->budget--) { s->failed_pc=0x0c0926c2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0926c4;
P_0c0926c4: /* original 2fa6, guest PC 0x0c0926c4 */
if(!s->budget--) { s->failed_pc=0x0c0926c4u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0926c6;
P_0c0926c6: /* original 2f96, guest PC 0x0c0926c6 */
if(!s->budget--) { s->failed_pc=0x0c0926c6u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0926c8;
P_0c0926c8: /* original 2f86, guest PC 0x0c0926c8 */
if(!s->budget--) { s->failed_pc=0x0c0926c8u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0926ca;
P_0c0926ca: /* original d40f, guest PC 0x0c0926ca */
if(!s->budget--) { s->failed_pc=0x0c0926cau; return 0; }
r[4]=read(ram,0x0c092708u,4);
return vf3_matrix_family(0x0c0926ccu,s,ram);
P_0c092b8c: /* original f40b, guest PC 0x0c092b8c */
if(!s->budget--) { s->failed_pc=0x0c092b8cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092b8e;
P_0c092b8e: /* original 0009, guest PC 0x0c092b8e */
if(!s->budget--) { s->failed_pc=0x0c092b8eu; return 0; }
goto P_0c092b90;
P_0c092b90: /* original 52f2, guest PC 0x0c092b90 */
if(!s->budget--) { s->failed_pc=0x0c092b90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c092b92;
P_0c092b92: /* original 51fa, guest PC 0x0c092b92 */
if(!s->budget--) { s->failed_pc=0x0c092b92u; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c092b94;
P_0c092b94: /* original 930b, guest PC 0x0c092b94 */
if(!s->budget--) { s->failed_pc=0x0c092b94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092baeu,2);
goto P_0c092b96;
P_0c092b96: /* original f428, guest PC 0x0c092b96 */
if(!s->budget--) { s->failed_pc=0x0c092b96u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
goto P_0c092b98;
P_0c092b98: /* original 2138, guest PC 0x0c092b98 */
if(!s->budget--) { s->failed_pc=0x0c092b98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c092b9a;
P_0c092b9a: /* original 8d03, guest PC 0x0c092b9a */
if(!s->budget--) { s->failed_pc=0x0c092b9au; return 0; }
cond=r[17]&1u;
r[5]=r[14];
if(cond) { goto P_0c092ba4; }
goto P_0c092b9e;
P_0c092b9c: /* original 65e3, guest PC 0x0c092b9c */
if(!s->budget--) { s->failed_pc=0x0c092b9cu; return 0; }
r[5]=r[14];
goto P_0c092b9e;
P_0c092b9e: /* original c704, guest PC 0x0c092b9e */
if(!s->budget--) { s->failed_pc=0x0c092b9eu; return 0; }
r[0]=0x0c092bb0u;
goto P_0c092ba0;
P_0c092ba0: /* original f308, guest PC 0x0c092ba0 */
if(!s->budget--) { s->failed_pc=0x0c092ba0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c092ba2;
P_0c092ba2: /* original f432, guest PC 0x0c092ba2 */
if(!s->budget--) { s->failed_pc=0x0c092ba2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c092ba4;
P_0c092ba4: /* original 64e3, guest PC 0x0c092ba4 */
if(!s->budget--) { s->failed_pc=0x0c092ba4u; return 0; }
r[4]=r[14];
goto P_0c092ba6;
P_0c092ba6: /* original 7418, guest PC 0x0c092ba6 */
if(!s->budget--) { s->failed_pc=0x0c092ba6u; return 0; }
r[4]+=0x00000018u;
goto P_0c092ba8;
P_0c092ba8: /* original 7518, guest PC 0x0c092ba8 */
if(!s->budget--) { s->failed_pc=0x0c092ba8u; return 0; }
r[5]+=0x00000018u;
goto P_0c092baa;
P_0c092baa: /* original a003, guest PC 0x0c092baa */
if(!s->budget--) { s->failed_pc=0x0c092baau; return 0; }
goto P_0c092bb4;
P_0c092bac: /* original 0009, guest PC 0x0c092bac */
if(!s->budget--) { s->failed_pc=0x0c092bacu; return 0; }
return vf3_matrix_family(0x0c092baeu,s,ram);
P_0c092bb4: /* original f059, guest PC 0x0c092bb4 */
if(!s->budget--) { s->failed_pc=0x0c092bb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bb6;
P_0c092bb6: /* original f159, guest PC 0x0c092bb6 */
if(!s->budget--) { s->failed_pc=0x0c092bb6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bb8;
P_0c092bb8: /* original f259, guest PC 0x0c092bb8 */
if(!s->budget--) { s->failed_pc=0x0c092bb8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bba;
P_0c092bba: /* original 740c, guest PC 0x0c092bba */
if(!s->budget--) { s->failed_pc=0x0c092bbau; return 0; }
r[4]+=0x0000000cu;
goto P_0c092bbc;
P_0c092bbc: /* original f242, guest PC 0x0c092bbc */
if(!s->budget--) { s->failed_pc=0x0c092bbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092bbe;
P_0c092bbe: /* original f142, guest PC 0x0c092bbe */
if(!s->budget--) { s->failed_pc=0x0c092bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092bc0;
P_0c092bc0: /* original f042, guest PC 0x0c092bc0 */
if(!s->budget--) { s->failed_pc=0x0c092bc0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092bc2;
P_0c092bc2: /* original f42b, guest PC 0x0c092bc2 */
if(!s->budget--) { s->failed_pc=0x0c092bc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092bc4;
P_0c092bc4: /* original f41b, guest PC 0x0c092bc4 */
if(!s->budget--) { s->failed_pc=0x0c092bc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092bc6;
P_0c092bc6: /* original f40b, guest PC 0x0c092bc6 */
if(!s->budget--) { s->failed_pc=0x0c092bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092bc8;
P_0c092bc8: /* original 50fa, guest PC 0x0c092bc8 */
if(!s->budget--) { s->failed_pc=0x0c092bc8u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c092bca;
P_0c092bca: /* original c802, guest PC 0x0c092bca */
if(!s->budget--) { s->failed_pc=0x0c092bcau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c092bcc;
P_0c092bcc: /* original 8902, guest PC 0x0c092bcc */
if(!s->budget--) { s->failed_pc=0x0c092bccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092bd4; }
goto P_0c092bce;
P_0c092bce: /* original d30c, guest PC 0x0c092bce */
if(!s->budget--) { s->failed_pc=0x0c092bceu; return 0; }
r[3]=read(ram,0x0c092c00u,4);
goto P_0c092bd0;
P_0c092bd0: /* original 432b, guest PC 0x0c092bd0 */
if(!s->budget--) { s->failed_pc=0x0c092bd0u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c092bd2: /* original 0009, guest PC 0x0c092bd2 */
if(!s->budget--) { s->failed_pc=0x0c092bd2u; return 0; }
goto P_0c092bd4;
P_0c092bd4: /* original 52f1, guest PC 0x0c092bd4 */
if(!s->budget--) { s->failed_pc=0x0c092bd4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c092bd6;
P_0c092bd6: /* original e014, guest PC 0x0c092bd6 */
if(!s->budget--) { s->failed_pc=0x0c092bd6u; return 0; }
r[0]=0x00000014u;
goto P_0c092bd8;
P_0c092bd8: /* original f28d, guest PC 0x0c092bd8 */
if(!s->budget--) { s->failed_pc=0x0c092bd8u; return 0; }
fr[2]=0;
goto P_0c092bda;
P_0c092bda: /* original f426, guest PC 0x0c092bda */
if(!s->budget--) { s->failed_pc=0x0c092bdau; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c092bdc;
P_0c092bdc: /* original f34c, guest PC 0x0c092bdc */
if(!s->budget--) { s->failed_pc=0x0c092bdcu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092bde;
P_0c092bde: /* original f430, guest PC 0x0c092bde */
if(!s->budget--) { s->failed_pc=0x0c092bdeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c092be0;
P_0c092be0: /* original f424, guest PC 0x0c092be0 */
if(!s->budget--) { s->failed_pc=0x0c092be0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[2]))!=0);
goto P_0c092be2;
P_0c092be2: /* original 8b02, guest PC 0x0c092be2 */
if(!s->budget--) { s->failed_pc=0x0c092be2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092bea; }
goto P_0c092be4;
P_0c092be4: /* original d306, guest PC 0x0c092be4 */
if(!s->budget--) { s->failed_pc=0x0c092be4u; return 0; }
r[3]=read(ram,0x0c092c00u,4);
goto P_0c092be6;
P_0c092be6: /* original 432b, guest PC 0x0c092be6 */
if(!s->budget--) { s->failed_pc=0x0c092be6u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c092be8: /* original 0009, guest PC 0x0c092be8 */
if(!s->budget--) { s->failed_pc=0x0c092be8u; return 0; }
goto P_0c092bea;
P_0c092bea: /* original 61f2, guest PC 0x0c092bea */
if(!s->budget--) { s->failed_pc=0x0c092beau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c092bec;
P_0c092bec: /* original 2118, guest PC 0x0c092bec */
if(!s->budget--) { s->failed_pc=0x0c092becu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c092bee;
P_0c092bee: /* original 8b02, guest PC 0x0c092bee */
if(!s->budget--) { s->failed_pc=0x0c092beeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092bf6; }
goto P_0c092bf0;
P_0c092bf0: /* original d103, guest PC 0x0c092bf0 */
if(!s->budget--) { s->failed_pc=0x0c092bf0u; return 0; }
r[1]=read(ram,0x0c092c00u,4);
goto P_0c092bf2;
P_0c092bf2: /* original 412b, guest PC 0x0c092bf2 */
if(!s->budget--) { s->failed_pc=0x0c092bf2u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c092bf4: /* original 0009, guest PC 0x0c092bf4 */
if(!s->budget--) { s->failed_pc=0x0c092bf4u; return 0; }
goto P_0c092bf6;
P_0c092bf6: /* original 64f3, guest PC 0x0c092bf6 */
if(!s->budget--) { s->failed_pc=0x0c092bf6u; return 0; }
r[4]=r[15];
goto P_0c092bf8;
P_0c092bf8: /* original 55f9, guest PC 0x0c092bf8 */
if(!s->budget--) { s->failed_pc=0x0c092bf8u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c092bfa;
P_0c092bfa: /* original 740c, guest PC 0x0c092bfa */
if(!s->budget--) { s->failed_pc=0x0c092bfau; return 0; }
r[4]+=0x0000000cu;
goto P_0c092bfc;
P_0c092bfc: /* original a002, guest PC 0x0c092bfc */
if(!s->budget--) { s->failed_pc=0x0c092bfcu; return 0; }
goto P_0c092c04;
P_0c092bfe: /* original 0009, guest PC 0x0c092bfe */
if(!s->budget--) { s->failed_pc=0x0c092bfeu; return 0; }
return vf3_matrix_family(0x0c092c00u,s,ram);
P_0c092c04: /* original f059, guest PC 0x0c092c04 */
if(!s->budget--) { s->failed_pc=0x0c092c04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c06;
P_0c092c06: /* original f159, guest PC 0x0c092c06 */
if(!s->budget--) { s->failed_pc=0x0c092c06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c08;
P_0c092c08: /* original f259, guest PC 0x0c092c08 */
if(!s->budget--) { s->failed_pc=0x0c092c08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c0a;
P_0c092c0a: /* original 740c, guest PC 0x0c092c0a */
if(!s->budget--) { s->failed_pc=0x0c092c0au; return 0; }
r[4]+=0x0000000cu;
goto P_0c092c0c;
P_0c092c0c: /* original f242, guest PC 0x0c092c0c */
if(!s->budget--) { s->failed_pc=0x0c092c0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092c0e;
P_0c092c0e: /* original f142, guest PC 0x0c092c0e */
if(!s->budget--) { s->failed_pc=0x0c092c0eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092c10;
P_0c092c10: /* original f042, guest PC 0x0c092c10 */
if(!s->budget--) { s->failed_pc=0x0c092c10u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092c12;
P_0c092c12: /* original f42b, guest PC 0x0c092c12 */
if(!s->budget--) { s->failed_pc=0x0c092c12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092c14;
P_0c092c14: /* original f41b, guest PC 0x0c092c14 */
if(!s->budget--) { s->failed_pc=0x0c092c14u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092c16;
P_0c092c16: /* original f40b, guest PC 0x0c092c16 */
if(!s->budget--) { s->failed_pc=0x0c092c16u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092c18;
P_0c092c18: /* original 64f2, guest PC 0x0c092c18 */
if(!s->budget--) { s->failed_pc=0x0c092c18u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c092c1a;
P_0c092c1a: /* original 65f3, guest PC 0x0c092c1a */
if(!s->budget--) { s->failed_pc=0x0c092c1au; return 0; }
r[5]=r[15];
goto P_0c092c1c;
P_0c092c1c: /* original 750c, guest PC 0x0c092c1c */
if(!s->budget--) { s->failed_pc=0x0c092c1cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c092c1e;
P_0c092c1e: /* original 7418, guest PC 0x0c092c1e */
if(!s->budget--) { s->failed_pc=0x0c092c1eu; return 0; }
r[4]+=0x00000018u;
goto P_0c092c20;
P_0c092c20: /* original f049, guest PC 0x0c092c20 */
if(!s->budget--) { s->failed_pc=0x0c092c20u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c22;
P_0c092c22: /* original f359, guest PC 0x0c092c22 */
if(!s->budget--) { s->failed_pc=0x0c092c22u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c24;
P_0c092c24: /* original f149, guest PC 0x0c092c24 */
if(!s->budget--) { s->failed_pc=0x0c092c24u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c26;
P_0c092c26: /* original f459, guest PC 0x0c092c26 */
if(!s->budget--) { s->failed_pc=0x0c092c26u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c28;
P_0c092c28: /* original f249, guest PC 0x0c092c28 */
if(!s->budget--) { s->failed_pc=0x0c092c28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c2a;
P_0c092c2a: /* original f559, guest PC 0x0c092c2a */
if(!s->budget--) { s->failed_pc=0x0c092c2au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c2c;
P_0c092c2c: /* original f030, guest PC 0x0c092c2c */
if(!s->budget--) { s->failed_pc=0x0c092c2cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c092c2e;
P_0c092c2e: /* original f250, guest PC 0x0c092c2e */
if(!s->budget--) { s->failed_pc=0x0c092c2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c092c30;
P_0c092c30: /* original f140, guest PC 0x0c092c30 */
if(!s->budget--) { s->failed_pc=0x0c092c30u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c092c32;
P_0c092c32: /* original f42b, guest PC 0x0c092c32 */
if(!s->budget--) { s->failed_pc=0x0c092c32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092c34;
P_0c092c34: /* original f41b, guest PC 0x0c092c34 */
if(!s->budget--) { s->failed_pc=0x0c092c34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092c36;
P_0c092c36: /* original f40b, guest PC 0x0c092c36 */
if(!s->budget--) { s->failed_pc=0x0c092c36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092c38;
P_0c092c38: /* original 7f18, guest PC 0x0c092c38 */
if(!s->budget--) { s->failed_pc=0x0c092c38u; return 0; }
r[15]+=0x00000018u;
goto P_0c092c3a;
P_0c092c3a: /* original 000b, guest PC 0x0c092c3a */
if(!s->budget--) { s->failed_pc=0x0c092c3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092c3c: /* original 6ef6, guest PC 0x0c092c3c */
if(!s->budget--) { s->failed_pc=0x0c092c3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092c3eu,s,ram);
P_0c092ebc: /* original f40b, guest PC 0x0c092ebc */
if(!s->budget--) { s->failed_pc=0x0c092ebcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092ebe;
P_0c092ebe: /* original 0009, guest PC 0x0c092ebe */
if(!s->budget--) { s->failed_pc=0x0c092ebeu; return 0; }
goto P_0c092ec0;
P_0c092ec0: /* original 64f3, guest PC 0x0c092ec0 */
if(!s->budget--) { s->failed_pc=0x0c092ec0u; return 0; }
r[4]=r[15];
goto P_0c092ec2;
P_0c092ec2: /* original f049, guest PC 0x0c092ec2 */
if(!s->budget--) { s->failed_pc=0x0c092ec2u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092ec4;
P_0c092ec4: /* original f149, guest PC 0x0c092ec4 */
if(!s->budget--) { s->failed_pc=0x0c092ec4u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092ec6;
P_0c092ec6: /* original f248, guest PC 0x0c092ec6 */
if(!s->budget--) { s->failed_pc=0x0c092ec6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c092ec8;
P_0c092ec8: /* original f38d, guest PC 0x0c092ec8 */
if(!s->budget--) { s->failed_pc=0x0c092ec8u; return 0; }
fr[3]=0;
goto P_0c092eca;
P_0c092eca: /* original f0ed, guest PC 0x0c092eca */
if(!s->budget--) { s->failed_pc=0x0c092ecau; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c092ecc;
P_0c092ecc: /* original f03c, guest PC 0x0c092ecc */
if(!s->budget--) { s->failed_pc=0x0c092eccu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c092ece;
P_0c092ece: /* original 0009, guest PC 0x0c092ece */
if(!s->budget--) { s->failed_pc=0x0c092eceu; return 0; }
goto P_0c092ed0;
P_0c092ed0: /* original f38d, guest PC 0x0c092ed0 */
if(!s->budget--) { s->failed_pc=0x0c092ed0u; return 0; }
fr[3]=0;
goto P_0c092ed2;
P_0c092ed2: /* original f40c, guest PC 0x0c092ed2 */
if(!s->budget--) { s->failed_pc=0x0c092ed2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c092ed4;
P_0c092ed4: /* original f434, guest PC 0x0c092ed4 */
if(!s->budget--) { s->failed_pc=0x0c092ed4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c092ed6;
P_0c092ed6: /* original 8b02, guest PC 0x0c092ed6 */
if(!s->budget--) { s->failed_pc=0x0c092ed6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092ede; }
goto P_0c092ed8;
P_0c092ed8: /* original d307, guest PC 0x0c092ed8 */
if(!s->budget--) { s->failed_pc=0x0c092ed8u; return 0; }
r[3]=read(ram,0x0c092ef8u,4);
goto P_0c092eda;
P_0c092eda: /* original 432b, guest PC 0x0c092eda */
if(!s->budget--) { s->failed_pc=0x0c092edau; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c092edc: /* original 0009, guest PC 0x0c092edc */
if(!s->budget--) { s->failed_pc=0x0c092edcu; return 0; }
goto P_0c092ede;
P_0c092ede: /* original c707, guest PC 0x0c092ede */
if(!s->budget--) { s->failed_pc=0x0c092edeu; return 0; }
r[0]=0x0c092efcu;
goto P_0c092ee0;
P_0c092ee0: /* original f308, guest PC 0x0c092ee0 */
if(!s->budget--) { s->failed_pc=0x0c092ee0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c092ee2;
P_0c092ee2: /* original f345, guest PC 0x0c092ee2 */
if(!s->budget--) { s->failed_pc=0x0c092ee2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c092ee4;
P_0c092ee4: /* original 8b01, guest PC 0x0c092ee4 */
if(!s->budget--) { s->failed_pc=0x0c092ee4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092eea; }
goto P_0c092ee6;
P_0c092ee6: /* original a001, guest PC 0x0c092ee6 */
if(!s->budget--) { s->failed_pc=0x0c092ee6u; return 0; }
fr[4]=0;
goto P_0c092eec;
P_0c092ee8: /* original f48d, guest PC 0x0c092ee8 */
if(!s->budget--) { s->failed_pc=0x0c092ee8u; return 0; }
fr[4]=0;
goto P_0c092eea;
P_0c092eea: /* original f47d, guest PC 0x0c092eea */
if(!s->budget--) { s->failed_pc=0x0c092eeau; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c092eec;
P_0c092eec: /* original 64e3, guest PC 0x0c092eec */
if(!s->budget--) { s->failed_pc=0x0c092eecu; return 0; }
r[4]=r[14];
goto P_0c092eee;
P_0c092eee: /* original 745c, guest PC 0x0c092eee */
if(!s->budget--) { s->failed_pc=0x0c092eeeu; return 0; }
r[4]+=0x0000005cu;
goto P_0c092ef0;
P_0c092ef0: /* original 65f3, guest PC 0x0c092ef0 */
if(!s->budget--) { s->failed_pc=0x0c092ef0u; return 0; }
r[5]=r[15];
goto P_0c092ef2;
P_0c092ef2: /* original a005, guest PC 0x0c092ef2 */
if(!s->budget--) { s->failed_pc=0x0c092ef2u; return 0; }
goto P_0c092f00;
P_0c092ef4: /* original 0009, guest PC 0x0c092ef4 */
if(!s->budget--) { s->failed_pc=0x0c092ef4u; return 0; }
return vf3_matrix_family(0x0c092ef6u,s,ram);
P_0c092f00: /* original f059, guest PC 0x0c092f00 */
if(!s->budget--) { s->failed_pc=0x0c092f00u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f02;
P_0c092f02: /* original f159, guest PC 0x0c092f02 */
if(!s->budget--) { s->failed_pc=0x0c092f02u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f04;
P_0c092f04: /* original f259, guest PC 0x0c092f04 */
if(!s->budget--) { s->failed_pc=0x0c092f04u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092f06;
P_0c092f06: /* original 740c, guest PC 0x0c092f06 */
if(!s->budget--) { s->failed_pc=0x0c092f06u; return 0; }
r[4]+=0x0000000cu;
goto P_0c092f08;
P_0c092f08: /* original f242, guest PC 0x0c092f08 */
if(!s->budget--) { s->failed_pc=0x0c092f08u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092f0a;
P_0c092f0a: /* original f142, guest PC 0x0c092f0a */
if(!s->budget--) { s->failed_pc=0x0c092f0au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092f0c;
P_0c092f0c: /* original f042, guest PC 0x0c092f0c */
if(!s->budget--) { s->failed_pc=0x0c092f0cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092f0e;
P_0c092f0e: /* original f42b, guest PC 0x0c092f0e */
if(!s->budget--) { s->failed_pc=0x0c092f0eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092f10;
P_0c092f10: /* original f41b, guest PC 0x0c092f10 */
if(!s->budget--) { s->failed_pc=0x0c092f10u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092f12;
P_0c092f12: /* original f40b, guest PC 0x0c092f12 */
if(!s->budget--) { s->failed_pc=0x0c092f12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092f14;
P_0c092f14: /* original 7f0c, guest PC 0x0c092f14 */
if(!s->budget--) { s->failed_pc=0x0c092f14u; return 0; }
r[15]+=0x0000000cu;
goto P_0c092f16;
P_0c092f16: /* original 6df6, guest PC 0x0c092f16 */
if(!s->budget--) { s->failed_pc=0x0c092f16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c092f18;
P_0c092f18: /* original 000b, guest PC 0x0c092f18 */
if(!s->budget--) { s->failed_pc=0x0c092f18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092f1a: /* original 6ef6, guest PC 0x0c092f1a */
if(!s->budget--) { s->failed_pc=0x0c092f1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092f1cu,s,ram);
P_0c09318e: /* original 4f22, guest PC 0x0c09318e */
if(!s->budget--) { s->failed_pc=0x0c09318eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093190;
P_0c093190: /* original 7ffc, guest PC 0x0c093190 */
if(!s->budget--) { s->failed_pc=0x0c093190u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c093192;
P_0c093192: /* original 2f42, guest PC 0x0c093192 */
if(!s->budget--) { s->failed_pc=0x0c093192u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c093194;
P_0c093194: /* original 9889, guest PC 0x0c093194 */
if(!s->budget--) { s->failed_pc=0x0c093194u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0932aau,2);
goto P_0c093196;
P_0c093196: /* original 9089, guest PC 0x0c093196 */
if(!s->budget--) { s->failed_pc=0x0c093196u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0932acu,2);
goto P_0c093198;
P_0c093198: /* original 383c, guest PC 0x0c093198 */
if(!s->budget--) { s->failed_pc=0x0c093198u; return 0; }
r[8]+=r[3];
goto P_0c09319a;
P_0c09319a: /* original d346, guest PC 0x0c09319a */
if(!s->budget--) { s->failed_pc=0x0c09319au; return 0; }
r[3]=read(ram,0x0c0932b4u,4);
goto P_0c09319c;
P_0c09319c: /* original f5e6, guest PC 0x0c09319c */
if(!s->budget--) { s->failed_pc=0x0c09319cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09319e;
P_0c09319e: /* original 70f8, guest PC 0x0c09319e */
if(!s->budget--) { s->failed_pc=0x0c09319eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0931a0;
P_0c0931a0: /* original f54d, guest PC 0x0c0931a0 */
if(!s->budget--) { s->failed_pc=0x0c0931a0u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0931a2;
P_0c0931a2: /* original 430b, guest PC 0x0c0931a2 */
if(!s->budget--) { s->failed_pc=0x0c0931a2u; return 0; }
target=r[3];
r[16]=0x0c0931a6u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0931a6u) { target=s->pc; goto dispatch; }
goto P_0c0931a6;
P_0c0931a4: /* original f4e6, guest PC 0x0c0931a4 */
if(!s->budget--) { s->failed_pc=0x0c0931a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0931a6;
P_0c0931a6: /* original f80a, guest PC 0x0c0931a6 */
if(!s->budget--) { s->failed_pc=0x0c0931a6u; return 0; }
vf3_matrix_store(s,ram,0,r[8]);
goto P_0c0931a8;
P_0c0931a8: /* original 9082, guest PC 0x0c0931a8 */
if(!s->budget--) { s->failed_pc=0x0c0931a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0932b0u,2);
goto P_0c0931aa;
P_0c0931aa: /* original 9880, guest PC 0x0c0931aa */
if(!s->budget--) { s->failed_pc=0x0c0931aau; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0932aeu,2);
goto P_0c0931ac;
P_0c0931ac: /* original 63f2, guest PC 0x0c0931ac */
if(!s->budget--) { s->failed_pc=0x0c0931acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0931ae;
P_0c0931ae: /* original f5e6, guest PC 0x0c0931ae */
if(!s->budget--) { s->failed_pc=0x0c0931aeu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0931b0;
P_0c0931b0: /* original 70f8, guest PC 0x0c0931b0 */
if(!s->budget--) { s->failed_pc=0x0c0931b0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0931b2;
P_0c0931b2: /* original 383c, guest PC 0x0c0931b2 */
if(!s->budget--) { s->failed_pc=0x0c0931b2u; return 0; }
r[8]+=r[3];
goto P_0c0931b4;
P_0c0931b4: /* original d33f, guest PC 0x0c0931b4 */
if(!s->budget--) { s->failed_pc=0x0c0931b4u; return 0; }
r[3]=read(ram,0x0c0932b4u,4);
goto P_0c0931b6;
P_0c0931b6: /* original f54d, guest PC 0x0c0931b6 */
if(!s->budget--) { s->failed_pc=0x0c0931b6u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0931b8;
P_0c0931b8: /* original 430b, guest PC 0x0c0931b8 */
if(!s->budget--) { s->failed_pc=0x0c0931b8u; return 0; }
target=r[3];
r[16]=0x0c0931bcu;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0931bcu) { target=s->pc; goto dispatch; }
goto P_0c0931bc;
P_0c0931ba: /* original f4e6, guest PC 0x0c0931ba */
if(!s->budget--) { s->failed_pc=0x0c0931bau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0931bc;
P_0c0931bc: /* original 7f04, guest PC 0x0c0931bc */
if(!s->budget--) { s->failed_pc=0x0c0931bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0931be;
P_0c0931be: /* original f80a, guest PC 0x0c0931be */
if(!s->budget--) { s->failed_pc=0x0c0931beu; return 0; }
vf3_matrix_store(s,ram,0,r[8]);
goto P_0c0931c0;
P_0c0931c0: /* original 4f26, guest PC 0x0c0931c0 */
if(!s->budget--) { s->failed_pc=0x0c0931c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0931c2;
P_0c0931c2: /* original 68f6, guest PC 0x0c0931c2 */
if(!s->budget--) { s->failed_pc=0x0c0931c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0931c4;
P_0c0931c4: /* original 000b, guest PC 0x0c0931c4 */
if(!s->budget--) { s->failed_pc=0x0c0931c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0931c6: /* original 6ef6, guest PC 0x0c0931c6 */
if(!s->budget--) { s->failed_pc=0x0c0931c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0931c8u,s,ram);
P_0c093794: /* original f40b, guest PC 0x0c093794 */
if(!s->budget--) { s->failed_pc=0x0c093794u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093796;
P_0c093796: /* original 0009, guest PC 0x0c093796 */
if(!s->budget--) { s->failed_pc=0x0c093796u; return 0; }
goto P_0c093798;
P_0c093798: /* original 64e3, guest PC 0x0c093798 */
if(!s->budget--) { s->failed_pc=0x0c093798u; return 0; }
r[4]=r[14];
goto P_0c09379a;
P_0c09379a: /* original f049, guest PC 0x0c09379a */
if(!s->budget--) { s->failed_pc=0x0c09379au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09379c;
P_0c09379c: /* original f149, guest PC 0x0c09379c */
if(!s->budget--) { s->failed_pc=0x0c09379cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09379e;
P_0c09379e: /* original f248, guest PC 0x0c09379e */
if(!s->budget--) { s->failed_pc=0x0c09379eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c0937a0;
P_0c0937a0: /* original f38d, guest PC 0x0c0937a0 */
if(!s->budget--) { s->failed_pc=0x0c0937a0u; return 0; }
fr[3]=0;
goto P_0c0937a2;
P_0c0937a2: /* original f0ed, guest PC 0x0c0937a2 */
if(!s->budget--) { s->failed_pc=0x0c0937a2u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0937a4;
P_0c0937a4: /* original f03c, guest PC 0x0c0937a4 */
if(!s->budget--) { s->failed_pc=0x0c0937a4u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0937a6;
P_0c0937a6: /* original 0009, guest PC 0x0c0937a6 */
if(!s->budget--) { s->failed_pc=0x0c0937a6u; return 0; }
goto P_0c0937a8;
P_0c0937a8: /* original f38d, guest PC 0x0c0937a8 */
if(!s->budget--) { s->failed_pc=0x0c0937a8u; return 0; }
fr[3]=0;
goto P_0c0937aa;
P_0c0937aa: /* original ff0c, guest PC 0x0c0937aa */
if(!s->budget--) { s->failed_pc=0x0c0937aau; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0937ac;
P_0c0937ac: /* original ff34, guest PC 0x0c0937ac */
if(!s->budget--) { s->failed_pc=0x0c0937acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c0937ae;
P_0c0937ae: /* original 8906, guest PC 0x0c0937ae */
if(!s->budget--) { s->failed_pc=0x0c0937aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0937be; }
goto P_0c0937b0;
P_0c0937b0: /* original c707, guest PC 0x0c0937b0 */
if(!s->budget--) { s->failed_pc=0x0c0937b0u; return 0; }
r[0]=0x0c0937d0u;
goto P_0c0937b2;
P_0c0937b2: /* original f208, guest PC 0x0c0937b2 */
if(!s->budget--) { s->failed_pc=0x0c0937b2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0937b4;
P_0c0937b4: /* original f2f5, guest PC 0x0c0937b4 */
if(!s->budget--) { s->failed_pc=0x0c0937b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0937b6;
P_0c0937b6: /* original 8b01, guest PC 0x0c0937b6 */
if(!s->budget--) { s->failed_pc=0x0c0937b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0937bc; }
goto P_0c0937b8;
P_0c0937b8: /* original a001, guest PC 0x0c0937b8 */
if(!s->budget--) { s->failed_pc=0x0c0937b8u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0937be;
P_0c0937ba: /* original ff3c, guest PC 0x0c0937ba */
if(!s->budget--) { s->failed_pc=0x0c0937bau; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0937bc;
P_0c0937bc: /* original ff7d, guest PC 0x0c0937bc */
if(!s->budget--) { s->failed_pc=0x0c0937bcu; return 0; }
if(!vf3_fpu_fsrra(fr[15],r[18],&fr[15])) goto unsupported;
goto P_0c0937be;
P_0c0937be: /* original 53f1, guest PC 0x0c0937be */
if(!s->budget--) { s->failed_pc=0x0c0937beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0937c0;
P_0c0937c0: /* original e024, guest PC 0x0c0937c0 */
if(!s->budget--) { s->failed_pc=0x0c0937c0u; return 0; }
r[0]=0x00000024u;
goto P_0c0937c2;
P_0c0937c2: /* original f4fc, guest PC 0x0c0937c2 */
if(!s->budget--) { s->failed_pc=0x0c0937c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0937c4;
P_0c0937c4: /* original 64d3, guest PC 0x0c0937c4 */
if(!s->budget--) { s->failed_pc=0x0c0937c4u; return 0; }
r[4]=r[13];
goto P_0c0937c6;
P_0c0937c6: /* original f336, guest PC 0x0c0937c6 */
if(!s->budget--) { s->failed_pc=0x0c0937c6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0937c8;
P_0c0937c8: /* original 65e3, guest PC 0x0c0937c8 */
if(!s->budget--) { s->failed_pc=0x0c0937c8u; return 0; }
r[5]=r[14];
goto P_0c0937ca;
P_0c0937ca: /* original f432, guest PC 0x0c0937ca */
if(!s->budget--) { s->failed_pc=0x0c0937cau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0937cc;
P_0c0937cc: /* original a002, guest PC 0x0c0937cc */
if(!s->budget--) { s->failed_pc=0x0c0937ccu; return 0; }
goto P_0c0937d4;
P_0c0937ce: /* original 0009, guest PC 0x0c0937ce */
if(!s->budget--) { s->failed_pc=0x0c0937ceu; return 0; }
return vf3_matrix_family(0x0c0937d0u,s,ram);
P_0c0937d4: /* original f059, guest PC 0x0c0937d4 */
if(!s->budget--) { s->failed_pc=0x0c0937d4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937d6;
P_0c0937d6: /* original f159, guest PC 0x0c0937d6 */
if(!s->budget--) { s->failed_pc=0x0c0937d6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937d8;
P_0c0937d8: /* original f259, guest PC 0x0c0937d8 */
if(!s->budget--) { s->failed_pc=0x0c0937d8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937da;
P_0c0937da: /* original 740c, guest PC 0x0c0937da */
if(!s->budget--) { s->failed_pc=0x0c0937dau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0937dc;
P_0c0937dc: /* original f242, guest PC 0x0c0937dc */
if(!s->budget--) { s->failed_pc=0x0c0937dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0937de;
P_0c0937de: /* original f142, guest PC 0x0c0937de */
if(!s->budget--) { s->failed_pc=0x0c0937deu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0937e0;
P_0c0937e0: /* original f042, guest PC 0x0c0937e0 */
if(!s->budget--) { s->failed_pc=0x0c0937e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0937e2;
P_0c0937e2: /* original f42b, guest PC 0x0c0937e2 */
if(!s->budget--) { s->failed_pc=0x0c0937e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0937e4;
P_0c0937e4: /* original f41b, guest PC 0x0c0937e4 */
if(!s->budget--) { s->failed_pc=0x0c0937e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0937e6;
P_0c0937e6: /* original f40b, guest PC 0x0c0937e6 */
if(!s->budget--) { s->failed_pc=0x0c0937e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0937e8;
P_0c0937e8: /* original 64e3, guest PC 0x0c0937e8 */
if(!s->budget--) { s->failed_pc=0x0c0937e8u; return 0; }
r[4]=r[14];
goto P_0c0937ea;
P_0c0937ea: /* original 65e3, guest PC 0x0c0937ea */
if(!s->budget--) { s->failed_pc=0x0c0937eau; return 0; }
r[5]=r[14];
goto P_0c0937ec;
P_0c0937ec: /* original f4fc, guest PC 0x0c0937ec */
if(!s->budget--) { s->failed_pc=0x0c0937ecu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0937ee;
P_0c0937ee: /* original f059, guest PC 0x0c0937ee */
if(!s->budget--) { s->failed_pc=0x0c0937eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f0;
P_0c0937f0: /* original f159, guest PC 0x0c0937f0 */
if(!s->budget--) { s->failed_pc=0x0c0937f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f2;
P_0c0937f2: /* original f259, guest PC 0x0c0937f2 */
if(!s->budget--) { s->failed_pc=0x0c0937f2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f4;
P_0c0937f4: /* original 740c, guest PC 0x0c0937f4 */
if(!s->budget--) { s->failed_pc=0x0c0937f4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0937f6;
P_0c0937f6: /* original f242, guest PC 0x0c0937f6 */
if(!s->budget--) { s->failed_pc=0x0c0937f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0937f8;
P_0c0937f8: /* original f142, guest PC 0x0c0937f8 */
if(!s->budget--) { s->failed_pc=0x0c0937f8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0937fa;
P_0c0937fa: /* original f042, guest PC 0x0c0937fa */
if(!s->budget--) { s->failed_pc=0x0c0937fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0937fc;
P_0c0937fc: /* original f42b, guest PC 0x0c0937fc */
if(!s->budget--) { s->failed_pc=0x0c0937fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0937fe;
P_0c0937fe: /* original f41b, guest PC 0x0c0937fe */
if(!s->budget--) { s->failed_pc=0x0c0937feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093800;
P_0c093800: /* original f40b, guest PC 0x0c093800 */
if(!s->budget--) { s->failed_pc=0x0c093800u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093802;
P_0c093802: /* original 0009, guest PC 0x0c093802 */
if(!s->budget--) { s->failed_pc=0x0c093802u; return 0; }
goto P_0c093804;
P_0c093804: /* original 65f2, guest PC 0x0c093804 */
if(!s->budget--) { s->failed_pc=0x0c093804u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c093806;
P_0c093806: /* original 64d3, guest PC 0x0c093806 */
if(!s->budget--) { s->failed_pc=0x0c093806u; return 0; }
r[4]=r[13];
goto P_0c093808;
P_0c093808: /* original f049, guest PC 0x0c093808 */
if(!s->budget--) { s->failed_pc=0x0c093808u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09380a;
P_0c09380a: /* original f359, guest PC 0x0c09380a */
if(!s->budget--) { s->failed_pc=0x0c09380au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09380c;
P_0c09380c: /* original f149, guest PC 0x0c09380c */
if(!s->budget--) { s->failed_pc=0x0c09380cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09380e;
P_0c09380e: /* original f459, guest PC 0x0c09380e */
if(!s->budget--) { s->failed_pc=0x0c09380eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093810;
P_0c093810: /* original f249, guest PC 0x0c093810 */
if(!s->budget--) { s->failed_pc=0x0c093810u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093812;
P_0c093812: /* original f559, guest PC 0x0c093812 */
if(!s->budget--) { s->failed_pc=0x0c093812u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093814;
P_0c093814: /* original f030, guest PC 0x0c093814 */
if(!s->budget--) { s->failed_pc=0x0c093814u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093816;
P_0c093816: /* original f250, guest PC 0x0c093816 */
if(!s->budget--) { s->failed_pc=0x0c093816u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093818;
P_0c093818: /* original f140, guest PC 0x0c093818 */
if(!s->budget--) { s->failed_pc=0x0c093818u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c09381a;
P_0c09381a: /* original f42b, guest PC 0x0c09381a */
if(!s->budget--) { s->failed_pc=0x0c09381au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09381c;
P_0c09381c: /* original f41b, guest PC 0x0c09381c */
if(!s->budget--) { s->failed_pc=0x0c09381cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09381e;
P_0c09381e: /* original f40b, guest PC 0x0c09381e */
if(!s->budget--) { s->failed_pc=0x0c09381eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093820;
P_0c093820: /* original 7f08, guest PC 0x0c093820 */
if(!s->budget--) { s->failed_pc=0x0c093820u; return 0; }
r[15]+=0x00000008u;
goto P_0c093822;
P_0c093822: /* original fff9, guest PC 0x0c093822 */
if(!s->budget--) { s->failed_pc=0x0c093822u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093824;
P_0c093824: /* original 6df6, guest PC 0x0c093824 */
if(!s->budget--) { s->failed_pc=0x0c093824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093826;
P_0c093826: /* original 000b, guest PC 0x0c093826 */
if(!s->budget--) { s->failed_pc=0x0c093826u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093828: /* original 6ef6, guest PC 0x0c093828 */
if(!s->budget--) { s->failed_pc=0x0c093828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09382au,s,ram);
P_0c0938ac: /* original f40b, guest PC 0x0c0938ac */
if(!s->budget--) { s->failed_pc=0x0c0938acu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0938ae;
P_0c0938ae: /* original 0009, guest PC 0x0c0938ae */
if(!s->budget--) { s->failed_pc=0x0c0938aeu; return 0; }
goto P_0c0938b0;
P_0c0938b0: /* original 64f3, guest PC 0x0c0938b0 */
if(!s->budget--) { s->failed_pc=0x0c0938b0u; return 0; }
r[4]=r[15];
goto P_0c0938b2;
P_0c0938b2: /* original 740c, guest PC 0x0c0938b2 */
if(!s->budget--) { s->failed_pc=0x0c0938b2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0938b4;
P_0c0938b4: /* original 65f3, guest PC 0x0c0938b4 */
if(!s->budget--) { s->failed_pc=0x0c0938b4u; return 0; }
r[5]=r[15];
goto P_0c0938b6;
P_0c0938b6: /* original f049, guest PC 0x0c0938b6 */
if(!s->budget--) { s->failed_pc=0x0c0938b6u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938b8;
P_0c0938b8: /* original f149, guest PC 0x0c0938b8 */
if(!s->budget--) { s->failed_pc=0x0c0938b8u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938ba;
P_0c0938ba: /* original f249, guest PC 0x0c0938ba */
if(!s->budget--) { s->failed_pc=0x0c0938bau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938bc;
P_0c0938bc: /* original f38d, guest PC 0x0c0938bc */
if(!s->budget--) { s->failed_pc=0x0c0938bcu; return 0; }
fr[3]=0;
goto P_0c0938be;
P_0c0938be: /* original f459, guest PC 0x0c0938be */
if(!s->budget--) { s->failed_pc=0x0c0938beu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c0;
P_0c0938c0: /* original f559, guest PC 0x0c0938c0 */
if(!s->budget--) { s->failed_pc=0x0c0938c0u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c2;
P_0c0938c2: /* original f659, guest PC 0x0c0938c2 */
if(!s->budget--) { s->failed_pc=0x0c0938c2u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938c4;
P_0c0938c4: /* original f78d, guest PC 0x0c0938c4 */
if(!s->budget--) { s->failed_pc=0x0c0938c4u; return 0; }
fr[7]=0;
goto P_0c0938c6;
P_0c0938c6: /* original f4ed, guest PC 0x0c0938c6 */
if(!s->budget--) { s->failed_pc=0x0c0938c6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0938c8;
P_0c0938c8: /* original f07c, guest PC 0x0c0938c8 */
if(!s->budget--) { s->failed_pc=0x0c0938c8u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0938ca;
P_0c0938ca: /* original 0009, guest PC 0x0c0938ca */
if(!s->budget--) { s->failed_pc=0x0c0938cau; return 0; }
goto P_0c0938cc;
P_0c0938cc: /* original 65f3, guest PC 0x0c0938cc */
if(!s->budget--) { s->failed_pc=0x0c0938ccu; return 0; }
r[5]=r[15];
goto P_0c0938ce;
P_0c0938ce: /* original 64f3, guest PC 0x0c0938ce */
if(!s->budget--) { s->failed_pc=0x0c0938ceu; return 0; }
r[4]=r[15];
goto P_0c0938d0;
P_0c0938d0: /* original ff0c, guest PC 0x0c0938d0 */
if(!s->budget--) { s->failed_pc=0x0c0938d0u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0938d2;
P_0c0938d2: /* original 7424, guest PC 0x0c0938d2 */
if(!s->budget--) { s->failed_pc=0x0c0938d2u; return 0; }
r[4]+=0x00000024u;
goto P_0c0938d4;
P_0c0938d4: /* original f40c, guest PC 0x0c0938d4 */
if(!s->budget--) { s->failed_pc=0x0c0938d4u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0938d6;
P_0c0938d6: /* original 750c, guest PC 0x0c0938d6 */
if(!s->budget--) { s->failed_pc=0x0c0938d6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0938d8;
P_0c0938d8: /* original f059, guest PC 0x0c0938d8 */
if(!s->budget--) { s->failed_pc=0x0c0938d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938da;
P_0c0938da: /* original f159, guest PC 0x0c0938da */
if(!s->budget--) { s->failed_pc=0x0c0938dau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938dc;
P_0c0938dc: /* original f259, guest PC 0x0c0938dc */
if(!s->budget--) { s->failed_pc=0x0c0938dcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938de;
P_0c0938de: /* original 740c, guest PC 0x0c0938de */
if(!s->budget--) { s->failed_pc=0x0c0938deu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0938e0;
P_0c0938e0: /* original f242, guest PC 0x0c0938e0 */
if(!s->budget--) { s->failed_pc=0x0c0938e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0938e2;
P_0c0938e2: /* original f142, guest PC 0x0c0938e2 */
if(!s->budget--) { s->failed_pc=0x0c0938e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0938e4;
P_0c0938e4: /* original f042, guest PC 0x0c0938e4 */
if(!s->budget--) { s->failed_pc=0x0c0938e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0938e6;
P_0c0938e6: /* original f42b, guest PC 0x0c0938e6 */
if(!s->budget--) { s->failed_pc=0x0c0938e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0938e8;
P_0c0938e8: /* original f41b, guest PC 0x0c0938e8 */
if(!s->budget--) { s->failed_pc=0x0c0938e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0938ea;
P_0c0938ea: /* original f40b, guest PC 0x0c0938ea */
if(!s->budget--) { s->failed_pc=0x0c0938eau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0938ec;
P_0c0938ec: /* original 64f3, guest PC 0x0c0938ec */
if(!s->budget--) { s->failed_pc=0x0c0938ecu; return 0; }
r[4]=r[15];
goto P_0c0938ee;
P_0c0938ee: /* original 7424, guest PC 0x0c0938ee */
if(!s->budget--) { s->failed_pc=0x0c0938eeu; return 0; }
r[4]+=0x00000024u;
goto P_0c0938f0;
P_0c0938f0: /* original 65e3, guest PC 0x0c0938f0 */
if(!s->budget--) { s->failed_pc=0x0c0938f0u; return 0; }
r[5]=r[14];
goto P_0c0938f2;
P_0c0938f2: /* original f049, guest PC 0x0c0938f2 */
if(!s->budget--) { s->failed_pc=0x0c0938f2u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f4;
P_0c0938f4: /* original f359, guest PC 0x0c0938f4 */
if(!s->budget--) { s->failed_pc=0x0c0938f4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f6;
P_0c0938f6: /* original f149, guest PC 0x0c0938f6 */
if(!s->budget--) { s->failed_pc=0x0c0938f6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938f8;
P_0c0938f8: /* original f459, guest PC 0x0c0938f8 */
if(!s->budget--) { s->failed_pc=0x0c0938f8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fa;
P_0c0938fa: /* original f249, guest PC 0x0c0938fa */
if(!s->budget--) { s->failed_pc=0x0c0938fau; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fc;
P_0c0938fc: /* original f559, guest PC 0x0c0938fc */
if(!s->budget--) { s->failed_pc=0x0c0938fcu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0938fe;
P_0c0938fe: /* original f030, guest PC 0x0c0938fe */
if(!s->budget--) { s->failed_pc=0x0c0938feu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093900;
P_0c093900: /* original f250, guest PC 0x0c093900 */
if(!s->budget--) { s->failed_pc=0x0c093900u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093902;
P_0c093902: /* original f140, guest PC 0x0c093902 */
if(!s->budget--) { s->failed_pc=0x0c093902u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093904;
P_0c093904: /* original f42b, guest PC 0x0c093904 */
if(!s->budget--) { s->failed_pc=0x0c093904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093906;
P_0c093906: /* original f41b, guest PC 0x0c093906 */
if(!s->budget--) { s->failed_pc=0x0c093906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093908;
P_0c093908: /* original f40b, guest PC 0x0c093908 */
if(!s->budget--) { s->failed_pc=0x0c093908u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c09390a;
P_0c09390a: /* original 0009, guest PC 0x0c09390a */
if(!s->budget--) { s->failed_pc=0x0c09390au; return 0; }
goto P_0c09390c;
P_0c09390c: /* original 64f3, guest PC 0x0c09390c */
if(!s->budget--) { s->failed_pc=0x0c09390cu; return 0; }
r[4]=r[15];
goto P_0c09390e;
P_0c09390e: /* original 66f3, guest PC 0x0c09390e */
if(!s->budget--) { s->failed_pc=0x0c09390eu; return 0; }
r[6]=r[15];
goto P_0c093910;
P_0c093910: /* original 7418, guest PC 0x0c093910 */
if(!s->budget--) { s->failed_pc=0x0c093910u; return 0; }
r[4]+=0x00000018u;
goto P_0c093912;
P_0c093912: /* original 65d3, guest PC 0x0c093912 */
if(!s->budget--) { s->failed_pc=0x0c093912u; return 0; }
r[5]=r[13];
goto P_0c093914;
P_0c093914: /* original 7624, guest PC 0x0c093914 */
if(!s->budget--) { s->failed_pc=0x0c093914u; return 0; }
r[6]+=0x00000024u;
goto P_0c093916;
P_0c093916: /* original f059, guest PC 0x0c093916 */
if(!s->budget--) { s->failed_pc=0x0c093916u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093918;
P_0c093918: /* original f369, guest PC 0x0c093918 */
if(!s->budget--) { s->failed_pc=0x0c093918u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09391a;
P_0c09391a: /* original f159, guest PC 0x0c09391a */
if(!s->budget--) { s->failed_pc=0x0c09391au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09391c;
P_0c09391c: /* original f469, guest PC 0x0c09391c */
if(!s->budget--) { s->failed_pc=0x0c09391cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09391e;
P_0c09391e: /* original f031, guest PC 0x0c09391e */
if(!s->budget--) { s->failed_pc=0x0c09391eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c093920;
P_0c093920: /* original f258, guest PC 0x0c093920 */
if(!s->budget--) { s->failed_pc=0x0c093920u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093922;
P_0c093922: /* original f568, guest PC 0x0c093922 */
if(!s->budget--) { s->failed_pc=0x0c093922u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093924;
P_0c093924: /* original f141, guest PC 0x0c093924 */
if(!s->budget--) { s->failed_pc=0x0c093924u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093926;
P_0c093926: /* original f251, guest PC 0x0c093926 */
if(!s->budget--) { s->failed_pc=0x0c093926u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093928;
P_0c093928: /* original 7408, guest PC 0x0c093928 */
if(!s->budget--) { s->failed_pc=0x0c093928u; return 0; }
r[4]+=0x00000008u;
goto P_0c09392a;
P_0c09392a: /* original f42a, guest PC 0x0c09392a */
if(!s->budget--) { s->failed_pc=0x0c09392au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09392c;
P_0c09392c: /* original f41b, guest PC 0x0c09392c */
if(!s->budget--) { s->failed_pc=0x0c09392cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09392e;
P_0c09392e: /* original f40b, guest PC 0x0c09392e */
if(!s->budget--) { s->failed_pc=0x0c09392eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093930;
P_0c093930: /* original 64f3, guest PC 0x0c093930 */
if(!s->budget--) { s->failed_pc=0x0c093930u; return 0; }
r[4]=r[15];
goto P_0c093932;
P_0c093932: /* original 7418, guest PC 0x0c093932 */
if(!s->budget--) { s->failed_pc=0x0c093932u; return 0; }
r[4]+=0x00000018u;
goto P_0c093934;
P_0c093934: /* original f049, guest PC 0x0c093934 */
if(!s->budget--) { s->failed_pc=0x0c093934u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093936;
P_0c093936: /* original f149, guest PC 0x0c093936 */
if(!s->budget--) { s->failed_pc=0x0c093936u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093938;
P_0c093938: /* original f248, guest PC 0x0c093938 */
if(!s->budget--) { s->failed_pc=0x0c093938u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c09393a;
P_0c09393a: /* original f38d, guest PC 0x0c09393a */
if(!s->budget--) { s->failed_pc=0x0c09393au; return 0; }
fr[3]=0;
goto P_0c09393c;
P_0c09393c: /* original f0ed, guest PC 0x0c09393c */
if(!s->budget--) { s->failed_pc=0x0c09393cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c09393e;
P_0c09393e: /* original f03c, guest PC 0x0c09393e */
if(!s->budget--) { s->failed_pc=0x0c09393eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093940;
P_0c093940: /* original f3c8, guest PC 0x0c093940 */
if(!s->budget--) { s->failed_pc=0x0c093940u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c093942;
P_0c093942: /* original fe0c, guest PC 0x0c093942 */
if(!s->budget--) { s->failed_pc=0x0c093942u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c093944;
P_0c093944: /* original f3e5, guest PC 0x0c093944 */
if(!s->budget--) { s->failed_pc=0x0c093944u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c093946;
P_0c093946: /* original 8902, guest PC 0x0c093946 */
if(!s->budget--) { s->failed_pc=0x0c093946u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09394e; }
goto P_0c093948;
P_0c093948: /* original d305, guest PC 0x0c093948 */
if(!s->budget--) { s->failed_pc=0x0c093948u; return 0; }
r[3]=read(ram,0x0c093960u,4);
goto P_0c09394a;
P_0c09394a: /* original 432b, guest PC 0x0c09394a */
if(!s->budget--) { s->failed_pc=0x0c09394au; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09394c: /* original 0009, guest PC 0x0c09394c */
if(!s->budget--) { s->failed_pc=0x0c09394cu; return 0; }
goto P_0c09394e;
P_0c09394e: /* original f3fc, guest PC 0x0c09394e */
if(!s->budget--) { s->failed_pc=0x0c09394eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c093950;
P_0c093950: /* original ff32, guest PC 0x0c093950 */
if(!s->budget--) { s->failed_pc=0x0c093950u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c093952;
P_0c093952: /* original 65f3, guest PC 0x0c093952 */
if(!s->budget--) { s->failed_pc=0x0c093952u; return 0; }
r[5]=r[15];
goto P_0c093954;
P_0c093954: /* original 64f3, guest PC 0x0c093954 */
if(!s->budget--) { s->failed_pc=0x0c093954u; return 0; }
r[4]=r[15];
goto P_0c093956;
P_0c093956: /* original 7524, guest PC 0x0c093956 */
if(!s->budget--) { s->failed_pc=0x0c093956u; return 0; }
r[5]+=0x00000024u;
goto P_0c093958;
P_0c093958: /* original 66e3, guest PC 0x0c093958 */
if(!s->budget--) { s->failed_pc=0x0c093958u; return 0; }
r[6]=r[14];
goto P_0c09395a;
P_0c09395a: /* original a003, guest PC 0x0c09395a */
if(!s->budget--) { s->failed_pc=0x0c09395au; return 0; }
goto P_0c093964;
P_0c09395c: /* original 0009, guest PC 0x0c09395c */
if(!s->budget--) { s->failed_pc=0x0c09395cu; return 0; }
return vf3_matrix_family(0x0c09395eu,s,ram);
P_0c093964: /* original f059, guest PC 0x0c093964 */
if(!s->budget--) { s->failed_pc=0x0c093964u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093966;
P_0c093966: /* original f369, guest PC 0x0c093966 */
if(!s->budget--) { s->failed_pc=0x0c093966u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093968;
P_0c093968: /* original f159, guest PC 0x0c093968 */
if(!s->budget--) { s->failed_pc=0x0c093968u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09396a;
P_0c09396a: /* original f469, guest PC 0x0c09396a */
if(!s->budget--) { s->failed_pc=0x0c09396au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09396c;
P_0c09396c: /* original f031, guest PC 0x0c09396c */
if(!s->budget--) { s->failed_pc=0x0c09396cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c09396e;
P_0c09396e: /* original f258, guest PC 0x0c09396e */
if(!s->budget--) { s->failed_pc=0x0c09396eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093970;
P_0c093970: /* original f568, guest PC 0x0c093970 */
if(!s->budget--) { s->failed_pc=0x0c093970u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093972;
P_0c093972: /* original f141, guest PC 0x0c093972 */
if(!s->budget--) { s->failed_pc=0x0c093972u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093974;
P_0c093974: /* original f251, guest PC 0x0c093974 */
if(!s->budget--) { s->failed_pc=0x0c093974u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093976;
P_0c093976: /* original 7408, guest PC 0x0c093976 */
if(!s->budget--) { s->failed_pc=0x0c093976u; return 0; }
r[4]+=0x00000008u;
goto P_0c093978;
P_0c093978: /* original f42a, guest PC 0x0c093978 */
if(!s->budget--) { s->failed_pc=0x0c093978u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09397a;
P_0c09397a: /* original f41b, guest PC 0x0c09397a */
if(!s->budget--) { s->failed_pc=0x0c09397au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09397c;
P_0c09397c: /* original f40b, guest PC 0x0c09397c */
if(!s->budget--) { s->failed_pc=0x0c09397cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c09397e;
P_0c09397e: /* original 0009, guest PC 0x0c09397e */
if(!s->budget--) { s->failed_pc=0x0c09397eu; return 0; }
goto P_0c093980;
P_0c093980: /* original 64f3, guest PC 0x0c093980 */
if(!s->budget--) { s->failed_pc=0x0c093980u; return 0; }
r[4]=r[15];
goto P_0c093982;
P_0c093982: /* original 740c, guest PC 0x0c093982 */
if(!s->budget--) { s->failed_pc=0x0c093982u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093984;
P_0c093984: /* original 65f3, guest PC 0x0c093984 */
if(!s->budget--) { s->failed_pc=0x0c093984u; return 0; }
r[5]=r[15];
goto P_0c093986;
P_0c093986: /* original f049, guest PC 0x0c093986 */
if(!s->budget--) { s->failed_pc=0x0c093986u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093988;
P_0c093988: /* original f149, guest PC 0x0c093988 */
if(!s->budget--) { s->failed_pc=0x0c093988u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09398a;
P_0c09398a: /* original f249, guest PC 0x0c09398a */
if(!s->budget--) { s->failed_pc=0x0c09398au; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09398c;
P_0c09398c: /* original f38d, guest PC 0x0c09398c */
if(!s->budget--) { s->failed_pc=0x0c09398cu; return 0; }
fr[3]=0;
goto P_0c09398e;
P_0c09398e: /* original f459, guest PC 0x0c09398e */
if(!s->budget--) { s->failed_pc=0x0c09398eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093990;
P_0c093990: /* original f559, guest PC 0x0c093990 */
if(!s->budget--) { s->failed_pc=0x0c093990u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093992;
P_0c093992: /* original f659, guest PC 0x0c093992 */
if(!s->budget--) { s->failed_pc=0x0c093992u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093994;
P_0c093994: /* original f78d, guest PC 0x0c093994 */
if(!s->budget--) { s->failed_pc=0x0c093994u; return 0; }
fr[7]=0;
goto P_0c093996;
P_0c093996: /* original f4ed, guest PC 0x0c093996 */
if(!s->budget--) { s->failed_pc=0x0c093996u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c093998;
P_0c093998: /* original f07c, guest PC 0x0c093998 */
if(!s->budget--) { s->failed_pc=0x0c093998u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c09399a;
P_0c09399a: /* original 0009, guest PC 0x0c09399a */
if(!s->budget--) { s->failed_pc=0x0c09399au; return 0; }
goto P_0c09399c;
P_0c09399c: /* original f38d, guest PC 0x0c09399c */
if(!s->budget--) { s->failed_pc=0x0c09399cu; return 0; }
fr[3]=0;
goto P_0c09399e;
P_0c09399e: /* original f40c, guest PC 0x0c09399e */
if(!s->budget--) { s->failed_pc=0x0c09399eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0939a0;
P_0c0939a0: /* original f345, guest PC 0x0c0939a0 */
if(!s->budget--) { s->failed_pc=0x0c0939a0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0939a2;
P_0c0939a2: /* original 8b10, guest PC 0x0c0939a2 */
if(!s->budget--) { s->failed_pc=0x0c0939a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0939c6; }
goto P_0c0939a4;
P_0c0939a4: /* original f3c8, guest PC 0x0c0939a4 */
if(!s->budget--) { s->failed_pc=0x0c0939a4u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0939a6;
P_0c0939a6: /* original ff35, guest PC 0x0c0939a6 */
if(!s->budget--) { s->failed_pc=0x0c0939a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0939a8;
P_0c0939a8: /* original 8b02, guest PC 0x0c0939a8 */
if(!s->budget--) { s->failed_pc=0x0c0939a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0939b0; }
goto P_0c0939aa;
P_0c0939aa: /* original d312, guest PC 0x0c0939aa */
if(!s->budget--) { s->failed_pc=0x0c0939aau; return 0; }
r[3]=read(ram,0x0c0939f4u,4);
goto P_0c0939ac;
P_0c0939ac: /* original 432b, guest PC 0x0c0939ac */
if(!s->budget--) { s->failed_pc=0x0c0939acu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0939ae: /* original 0009, guest PC 0x0c0939ae */
if(!s->budget--) { s->failed_pc=0x0c0939aeu; return 0; }
goto P_0c0939b0;
P_0c0939b0: /* original 65f3, guest PC 0x0c0939b0 */
if(!s->budget--) { s->failed_pc=0x0c0939b0u; return 0; }
r[5]=r[15];
goto P_0c0939b2;
P_0c0939b2: /* original d311, guest PC 0x0c0939b2 */
if(!s->budget--) { s->failed_pc=0x0c0939b2u; return 0; }
r[3]=read(ram,0x0c0939f8u,4);
goto P_0c0939b4;
P_0c0939b4: /* original f4b8, guest PC 0x0c0939b4 */
if(!s->budget--) { s->failed_pc=0x0c0939b4u; return 0; }
vf3_matrix_load(s,ram,4,r[11]);
goto P_0c0939b6;
P_0c0939b6: /* original 6693, guest PC 0x0c0939b6 */
if(!s->budget--) { s->failed_pc=0x0c0939b6u; return 0; }
r[6]=r[9];
goto P_0c0939b8;
P_0c0939b8: /* original f5c8, guest PC 0x0c0939b8 */
if(!s->budget--) { s->failed_pc=0x0c0939b8u; return 0; }
vf3_matrix_load(s,ram,5,r[12]);
goto P_0c0939ba;
P_0c0939ba: /* original 7530, guest PC 0x0c0939ba */
if(!s->budget--) { s->failed_pc=0x0c0939bau; return 0; }
r[5]+=0x00000030u;
goto P_0c0939bc;
P_0c0939bc: /* original 430b, guest PC 0x0c0939bc */
if(!s->budget--) { s->failed_pc=0x0c0939bcu; return 0; }
target=r[3];
r[16]=0x0c0939c0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0939c0u) { target=s->pc; goto dispatch; }
goto P_0c0939c0;
P_0c0939be: /* original 64d3, guest PC 0x0c0939be */
if(!s->budget--) { s->failed_pc=0x0c0939beu; return 0; }
r[4]=r[13];
goto P_0c0939c0;
P_0c0939c0: /* original d20c, guest PC 0x0c0939c0 */
if(!s->budget--) { s->failed_pc=0x0c0939c0u; return 0; }
r[2]=read(ram,0x0c0939f4u,4);
goto P_0c0939c2;
P_0c0939c2: /* original 422b, guest PC 0x0c0939c2 */
if(!s->budget--) { s->failed_pc=0x0c0939c2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0939c4: /* original 0009, guest PC 0x0c0939c4 */
if(!s->budget--) { s->failed_pc=0x0c0939c4u; return 0; }
goto P_0c0939c6;
P_0c0939c6: /* original e02c, guest PC 0x0c0939c6 */
if(!s->budget--) { s->failed_pc=0x0c0939c6u; return 0; }
r[0]=0x0000002cu;
goto P_0c0939c8;
P_0c0939c8: /* original f3e6, guest PC 0x0c0939c8 */
if(!s->budget--) { s->failed_pc=0x0c0939c8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0939ca;
P_0c0939ca: /* original f3f5, guest PC 0x0c0939ca */
if(!s->budget--) { s->failed_pc=0x0c0939cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0939cc;
P_0c0939cc: /* original 8902, guest PC 0x0c0939cc */
if(!s->budget--) { s->failed_pc=0x0c0939ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0939d4; }
goto P_0c0939ce;
P_0c0939ce: /* original d30b, guest PC 0x0c0939ce */
if(!s->budget--) { s->failed_pc=0x0c0939ceu; return 0; }
r[3]=read(ram,0x0c0939fcu,4);
goto P_0c0939d0;
P_0c0939d0: /* original 432b, guest PC 0x0c0939d0 */
if(!s->budget--) { s->failed_pc=0x0c0939d0u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0939d2: /* original 0009, guest PC 0x0c0939d2 */
if(!s->budget--) { s->failed_pc=0x0c0939d2u; return 0; }
goto P_0c0939d4;
P_0c0939d4: /* original c70a, guest PC 0x0c0939d4 */
if(!s->budget--) { s->failed_pc=0x0c0939d4u; return 0; }
r[0]=0x0c093a00u;
goto P_0c0939d6;
P_0c0939d6: /* original f208, guest PC 0x0c0939d6 */
if(!s->budget--) { s->failed_pc=0x0c0939d6u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0939d8;
P_0c0939d8: /* original f2e5, guest PC 0x0c0939d8 */
if(!s->budget--) { s->failed_pc=0x0c0939d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c0939da;
P_0c0939da: /* original 8f02, guest PC 0x0c0939da */
if(!s->budget--) { s->failed_pc=0x0c0939dau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[11]);
if(!cond) { goto P_0c0939e2; }
goto P_0c0939de;
P_0c0939dc: /* original f4b8, guest PC 0x0c0939dc */
if(!s->budget--) { s->failed_pc=0x0c0939dcu; return 0; }
vf3_matrix_load(s,ram,4,r[11]);
goto P_0c0939de;
P_0c0939de: /* original a002, guest PC 0x0c0939de */
if(!s->budget--) { s->failed_pc=0x0c0939deu; return 0; }
fr[3]=0;
goto P_0c0939e6;
P_0c0939e0: /* original f38d, guest PC 0x0c0939e0 */
if(!s->budget--) { s->failed_pc=0x0c0939e0u; return 0; }
fr[3]=0;
goto P_0c0939e2;
P_0c0939e2: /* original f3ec, guest PC 0x0c0939e2 */
if(!s->budget--) { s->failed_pc=0x0c0939e2u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0939e4;
P_0c0939e4: /* original f37d, guest PC 0x0c0939e4 */
if(!s->budget--) { s->failed_pc=0x0c0939e4u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0939e6;
P_0c0939e6: /* original f432, guest PC 0x0c0939e6 */
if(!s->budget--) { s->failed_pc=0x0c0939e6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0939e8;
P_0c0939e8: /* original 65f3, guest PC 0x0c0939e8 */
if(!s->budget--) { s->failed_pc=0x0c0939e8u; return 0; }
r[5]=r[15];
goto P_0c0939ea;
P_0c0939ea: /* original 64d3, guest PC 0x0c0939ea */
if(!s->budget--) { s->failed_pc=0x0c0939eau; return 0; }
r[4]=r[13];
goto P_0c0939ec;
P_0c0939ec: /* original 7518, guest PC 0x0c0939ec */
if(!s->budget--) { s->failed_pc=0x0c0939ecu; return 0; }
r[5]+=0x00000018u;
goto P_0c0939ee;
P_0c0939ee: /* original a009, guest PC 0x0c0939ee */
if(!s->budget--) { s->failed_pc=0x0c0939eeu; return 0; }
goto P_0c093a04;
P_0c0939f0: /* original 0009, guest PC 0x0c0939f0 */
if(!s->budget--) { s->failed_pc=0x0c0939f0u; return 0; }
return vf3_matrix_family(0x0c0939f2u,s,ram);
P_0c093a04: /* original f059, guest PC 0x0c093a04 */
if(!s->budget--) { s->failed_pc=0x0c093a04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a06;
P_0c093a06: /* original f159, guest PC 0x0c093a06 */
if(!s->budget--) { s->failed_pc=0x0c093a06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a08;
P_0c093a08: /* original f259, guest PC 0x0c093a08 */
if(!s->budget--) { s->failed_pc=0x0c093a08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a0a;
P_0c093a0a: /* original 740c, guest PC 0x0c093a0a */
if(!s->budget--) { s->failed_pc=0x0c093a0au; return 0; }
r[4]+=0x0000000cu;
goto P_0c093a0c;
P_0c093a0c: /* original f242, guest PC 0x0c093a0c */
if(!s->budget--) { s->failed_pc=0x0c093a0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c093a0e;
P_0c093a0e: /* original f142, guest PC 0x0c093a0e */
if(!s->budget--) { s->failed_pc=0x0c093a0eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c093a10;
P_0c093a10: /* original f042, guest PC 0x0c093a10 */
if(!s->budget--) { s->failed_pc=0x0c093a10u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c093a12;
P_0c093a12: /* original f42b, guest PC 0x0c093a12 */
if(!s->budget--) { s->failed_pc=0x0c093a12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093a14;
P_0c093a14: /* original f41b, guest PC 0x0c093a14 */
if(!s->budget--) { s->failed_pc=0x0c093a14u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093a16;
P_0c093a16: /* original f40b, guest PC 0x0c093a16 */
if(!s->budget--) { s->failed_pc=0x0c093a16u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093a18;
P_0c093a18: /* original 65f3, guest PC 0x0c093a18 */
if(!s->budget--) { s->failed_pc=0x0c093a18u; return 0; }
r[5]=r[15];
goto P_0c093a1a;
P_0c093a1a: /* original 64d3, guest PC 0x0c093a1a */
if(!s->budget--) { s->failed_pc=0x0c093a1au; return 0; }
r[4]=r[13];
goto P_0c093a1c;
P_0c093a1c: /* original 7524, guest PC 0x0c093a1c */
if(!s->budget--) { s->failed_pc=0x0c093a1cu; return 0; }
r[5]+=0x00000024u;
goto P_0c093a1e;
P_0c093a1e: /* original f049, guest PC 0x0c093a1e */
if(!s->budget--) { s->failed_pc=0x0c093a1eu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a20;
P_0c093a20: /* original f359, guest PC 0x0c093a20 */
if(!s->budget--) { s->failed_pc=0x0c093a20u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a22;
P_0c093a22: /* original f149, guest PC 0x0c093a22 */
if(!s->budget--) { s->failed_pc=0x0c093a22u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a24;
P_0c093a24: /* original f459, guest PC 0x0c093a24 */
if(!s->budget--) { s->failed_pc=0x0c093a24u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a26;
P_0c093a26: /* original f249, guest PC 0x0c093a26 */
if(!s->budget--) { s->failed_pc=0x0c093a26u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093a28;
P_0c093a28: /* original f559, guest PC 0x0c093a28 */
if(!s->budget--) { s->failed_pc=0x0c093a28u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093a2a;
P_0c093a2a: /* original f030, guest PC 0x0c093a2a */
if(!s->budget--) { s->failed_pc=0x0c093a2au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093a2c;
P_0c093a2c: /* original f250, guest PC 0x0c093a2c */
if(!s->budget--) { s->failed_pc=0x0c093a2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093a2e;
P_0c093a2e: /* original f140, guest PC 0x0c093a2e */
if(!s->budget--) { s->failed_pc=0x0c093a2eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093a30;
P_0c093a30: /* original f42b, guest PC 0x0c093a30 */
if(!s->budget--) { s->failed_pc=0x0c093a30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093a32;
P_0c093a32: /* original f41b, guest PC 0x0c093a32 */
if(!s->budget--) { s->failed_pc=0x0c093a32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093a34;
P_0c093a34: /* original f40b, guest PC 0x0c093a34 */
if(!s->budget--) { s->failed_pc=0x0c093a34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093a36;
P_0c093a36: /* original 0009, guest PC 0x0c093a36 */
if(!s->budget--) { s->failed_pc=0x0c093a36u; return 0; }
goto P_0c093a38;
P_0c093a38: /* original 6292, guest PC 0x0c093a38 */
if(!s->budget--) { s->failed_pc=0x0c093a38u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c093a3a;
P_0c093a3a: /* original 933c, guest PC 0x0c093a3a */
if(!s->budget--) { s->failed_pc=0x0c093a3au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093ab6u,2);
goto P_0c093a3c;
P_0c093a3c: /* original 223b, guest PC 0x0c093a3c */
if(!s->budget--) { s->failed_pc=0x0c093a3cu; return 0; }
r[2]|=r[3];
goto P_0c093a3e;
P_0c093a3e: /* original a017, guest PC 0x0c093a3e */
if(!s->budget--) { s->failed_pc=0x0c093a3eu; return 0; }
write(ram,r[9],r[2],4);
goto P_0c093a70;
P_0c093a40: /* original 2922, guest PC 0x0c093a40 */
if(!s->budget--) { s->failed_pc=0x0c093a40u; return 0; }
write(ram,r[9],r[2],4);
return vf3_matrix_family(0x0c093a42u,s,ram);
P_0c093a70: /* original e030, guest PC 0x0c093a70 */
if(!s->budget--) { s->failed_pc=0x0c093a70u; return 0; }
r[0]=0x00000030u;
goto P_0c093a72;
P_0c093a72: /* original f3f6, guest PC 0x0c093a72 */
if(!s->budget--) { s->failed_pc=0x0c093a72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a74;
P_0c093a74: /* original e034, guest PC 0x0c093a74 */
if(!s->budget--) { s->failed_pc=0x0c093a74u; return 0; }
r[0]=0x00000034u;
goto P_0c093a76;
P_0c093a76: /* original fa3a, guest PC 0x0c093a76 */
if(!s->budget--) { s->failed_pc=0x0c093a76u; return 0; }
vf3_matrix_store(s,ram,3,r[10]);
goto P_0c093a78;
P_0c093a78: /* original f3f6, guest PC 0x0c093a78 */
if(!s->budget--) { s->failed_pc=0x0c093a78u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a7a;
P_0c093a7a: /* original e004, guest PC 0x0c093a7a */
if(!s->budget--) { s->failed_pc=0x0c093a7au; return 0; }
r[0]=0x00000004u;
goto P_0c093a7c;
P_0c093a7c: /* original fa37, guest PC 0x0c093a7c */
if(!s->budget--) { s->failed_pc=0x0c093a7cu; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c093a7e;
P_0c093a7e: /* original e038, guest PC 0x0c093a7e */
if(!s->budget--) { s->failed_pc=0x0c093a7eu; return 0; }
r[0]=0x00000038u;
goto P_0c093a80;
P_0c093a80: /* original f3f6, guest PC 0x0c093a80 */
if(!s->budget--) { s->failed_pc=0x0c093a80u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093a82;
P_0c093a82: /* original 7f3c, guest PC 0x0c093a82 */
if(!s->budget--) { s->failed_pc=0x0c093a82u; return 0; }
r[15]+=0x0000003cu;
goto P_0c093a84;
P_0c093a84: /* original 4f26, guest PC 0x0c093a84 */
if(!s->budget--) { s->failed_pc=0x0c093a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093a86;
P_0c093a86: /* original e008, guest PC 0x0c093a86 */
if(!s->budget--) { s->failed_pc=0x0c093a86u; return 0; }
r[0]=0x00000008u;
goto P_0c093a88;
P_0c093a88: /* original fa37, guest PC 0x0c093a88 */
if(!s->budget--) { s->failed_pc=0x0c093a88u; return 0; }
vf3_matrix_store(s,ram,3,r[10]+r[0]);
goto P_0c093a8a;
P_0c093a8a: /* original fef9, guest PC 0x0c093a8a */
if(!s->budget--) { s->failed_pc=0x0c093a8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093a8c;
P_0c093a8c: /* original fff9, guest PC 0x0c093a8c */
if(!s->budget--) { s->failed_pc=0x0c093a8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093a8e;
P_0c093a8e: /* original 69f6, guest PC 0x0c093a8e */
if(!s->budget--) { s->failed_pc=0x0c093a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c093a90;
P_0c093a90: /* original 6af6, guest PC 0x0c093a90 */
if(!s->budget--) { s->failed_pc=0x0c093a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093a92;
P_0c093a92: /* original 6bf6, guest PC 0x0c093a92 */
if(!s->budget--) { s->failed_pc=0x0c093a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093a94;
P_0c093a94: /* original 6cf6, guest PC 0x0c093a94 */
if(!s->budget--) { s->failed_pc=0x0c093a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093a96;
P_0c093a96: /* original 6df6, guest PC 0x0c093a96 */
if(!s->budget--) { s->failed_pc=0x0c093a96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093a98;
P_0c093a98: /* original 000b, guest PC 0x0c093a98 */
if(!s->budget--) { s->failed_pc=0x0c093a98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093a9a: /* original 6ef6, guest PC 0x0c093a9a */
if(!s->budget--) { s->failed_pc=0x0c093a9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c093a9cu,s,ram);
P_0c093ad0: /* original f40b, guest PC 0x0c093ad0 */
if(!s->budget--) { s->failed_pc=0x0c093ad0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093ad2;
P_0c093ad2: /* original 0009, guest PC 0x0c093ad2 */
if(!s->budget--) { s->failed_pc=0x0c093ad2u; return 0; }
goto P_0c093ad4;
P_0c093ad4: /* original 64f3, guest PC 0x0c093ad4 */
if(!s->budget--) { s->failed_pc=0x0c093ad4u; return 0; }
r[4]=r[15];
goto P_0c093ad6;
P_0c093ad6: /* original 740c, guest PC 0x0c093ad6 */
if(!s->budget--) { s->failed_pc=0x0c093ad6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093ad8;
P_0c093ad8: /* original f049, guest PC 0x0c093ad8 */
if(!s->budget--) { s->failed_pc=0x0c093ad8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ada;
P_0c093ada: /* original f149, guest PC 0x0c093ada */
if(!s->budget--) { s->failed_pc=0x0c093adau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093adc;
P_0c093adc: /* original f249, guest PC 0x0c093adc */
if(!s->budget--) { s->failed_pc=0x0c093adcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ade;
P_0c093ade: /* original f38d, guest PC 0x0c093ade */
if(!s->budget--) { s->failed_pc=0x0c093adeu; return 0; }
fr[3]=0;
goto P_0c093ae0;
P_0c093ae0: /* original f0ed, guest PC 0x0c093ae0 */
if(!s->budget--) { s->failed_pc=0x0c093ae0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093ae2;
P_0c093ae2: /* original f03c, guest PC 0x0c093ae2 */
if(!s->budget--) { s->failed_pc=0x0c093ae2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093ae4;
P_0c093ae4: /* original f06d, guest PC 0x0c093ae4 */
if(!s->budget--) { s->failed_pc=0x0c093ae4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c093ae6;
P_0c093ae6: /* original 0009, guest PC 0x0c093ae6 */
if(!s->budget--) { s->failed_pc=0x0c093ae6u; return 0; }
goto P_0c093ae8;
P_0c093ae8: /* original e004, guest PC 0x0c093ae8 */
if(!s->budget--) { s->failed_pc=0x0c093ae8u; return 0; }
r[0]=0x00000004u;
goto P_0c093aea;
P_0c093aea: /* original f40c, guest PC 0x0c093aea */
if(!s->budget--) { s->failed_pc=0x0c093aeau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c093aec;
P_0c093aec: /* original f3f6, guest PC 0x0c093aec */
if(!s->budget--) { s->failed_pc=0x0c093aecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093aee;
P_0c093aee: /* original f345, guest PC 0x0c093aee */
if(!s->budget--) { s->failed_pc=0x0c093aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c093af0;
P_0c093af0: /* original 8902, guest PC 0x0c093af0 */
if(!s->budget--) { s->failed_pc=0x0c093af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093af8; }
goto P_0c093af2;
P_0c093af2: /* original d306, guest PC 0x0c093af2 */
if(!s->budget--) { s->failed_pc=0x0c093af2u; return 0; }
r[3]=read(ram,0x0c093b0cu,4);
goto P_0c093af4;
P_0c093af4: /* original 432b, guest PC 0x0c093af4 */
if(!s->budget--) { s->failed_pc=0x0c093af4u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c093af6: /* original 0009, guest PC 0x0c093af6 */
if(!s->budget--) { s->failed_pc=0x0c093af6u; return 0; }
goto P_0c093af8;
P_0c093af8: /* original e004, guest PC 0x0c093af8 */
if(!s->budget--) { s->failed_pc=0x0c093af8u; return 0; }
r[0]=0x00000004u;
goto P_0c093afa;
P_0c093afa: /* original f34c, guest PC 0x0c093afa */
if(!s->budget--) { s->failed_pc=0x0c093afau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c093afc;
P_0c093afc: /* original f4f6, guest PC 0x0c093afc */
if(!s->budget--) { s->failed_pc=0x0c093afcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c093afe;
P_0c093afe: /* original 65f3, guest PC 0x0c093afe */
if(!s->budget--) { s->failed_pc=0x0c093afeu; return 0; }
r[5]=r[15];
goto P_0c093b00;
P_0c093b00: /* original 64e3, guest PC 0x0c093b00 */
if(!s->budget--) { s->failed_pc=0x0c093b00u; return 0; }
r[4]=r[14];
goto P_0c093b02;
P_0c093b02: /* original 750c, guest PC 0x0c093b02 */
if(!s->budget--) { s->failed_pc=0x0c093b02u; return 0; }
r[5]+=0x0000000cu;
goto P_0c093b04;
P_0c093b04: /* original f433, guest PC 0x0c093b04 */
if(!s->budget--) { s->failed_pc=0x0c093b04u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c093b06;
P_0c093b06: /* original a003, guest PC 0x0c093b06 */
if(!s->budget--) { s->failed_pc=0x0c093b06u; return 0; }
goto P_0c093b10;
P_0c093b08: /* original 0009, guest PC 0x0c093b08 */
if(!s->budget--) { s->failed_pc=0x0c093b08u; return 0; }
return vf3_matrix_family(0x0c093b0au,s,ram);
P_0c093b10: /* original f059, guest PC 0x0c093b10 */
if(!s->budget--) { s->failed_pc=0x0c093b10u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b12;
P_0c093b12: /* original f159, guest PC 0x0c093b12 */
if(!s->budget--) { s->failed_pc=0x0c093b12u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b14;
P_0c093b14: /* original f259, guest PC 0x0c093b14 */
if(!s->budget--) { s->failed_pc=0x0c093b14u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b16;
P_0c093b16: /* original 740c, guest PC 0x0c093b16 */
if(!s->budget--) { s->failed_pc=0x0c093b16u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093b18;
P_0c093b18: /* original f242, guest PC 0x0c093b18 */
if(!s->budget--) { s->failed_pc=0x0c093b18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c093b1a;
P_0c093b1a: /* original f142, guest PC 0x0c093b1a */
if(!s->budget--) { s->failed_pc=0x0c093b1au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c093b1c;
P_0c093b1c: /* original f042, guest PC 0x0c093b1c */
if(!s->budget--) { s->failed_pc=0x0c093b1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c093b1e;
P_0c093b1e: /* original f42b, guest PC 0x0c093b1e */
if(!s->budget--) { s->failed_pc=0x0c093b1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b20;
P_0c093b20: /* original f41b, guest PC 0x0c093b20 */
if(!s->budget--) { s->failed_pc=0x0c093b20u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b22;
P_0c093b22: /* original f40b, guest PC 0x0c093b22 */
if(!s->budget--) { s->failed_pc=0x0c093b22u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b24;
P_0c093b24: /* original 55f2, guest PC 0x0c093b24 */
if(!s->budget--) { s->failed_pc=0x0c093b24u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c093b26;
P_0c093b26: /* original 64e3, guest PC 0x0c093b26 */
if(!s->budget--) { s->failed_pc=0x0c093b26u; return 0; }
r[4]=r[14];
goto P_0c093b28;
P_0c093b28: /* original f049, guest PC 0x0c093b28 */
if(!s->budget--) { s->failed_pc=0x0c093b28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2a;
P_0c093b2a: /* original f359, guest PC 0x0c093b2a */
if(!s->budget--) { s->failed_pc=0x0c093b2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2c;
P_0c093b2c: /* original f149, guest PC 0x0c093b2c */
if(!s->budget--) { s->failed_pc=0x0c093b2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2e;
P_0c093b2e: /* original f459, guest PC 0x0c093b2e */
if(!s->budget--) { s->failed_pc=0x0c093b2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b30;
P_0c093b30: /* original f249, guest PC 0x0c093b30 */
if(!s->budget--) { s->failed_pc=0x0c093b30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b32;
P_0c093b32: /* original f559, guest PC 0x0c093b32 */
if(!s->budget--) { s->failed_pc=0x0c093b32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b34;
P_0c093b34: /* original f030, guest PC 0x0c093b34 */
if(!s->budget--) { s->failed_pc=0x0c093b34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093b36;
P_0c093b36: /* original f250, guest PC 0x0c093b36 */
if(!s->budget--) { s->failed_pc=0x0c093b36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093b38;
P_0c093b38: /* original f140, guest PC 0x0c093b38 */
if(!s->budget--) { s->failed_pc=0x0c093b38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093b3a;
P_0c093b3a: /* original f42b, guest PC 0x0c093b3a */
if(!s->budget--) { s->failed_pc=0x0c093b3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b3c;
P_0c093b3c: /* original f41b, guest PC 0x0c093b3c */
if(!s->budget--) { s->failed_pc=0x0c093b3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b3e;
P_0c093b3e: /* original f40b, guest PC 0x0c093b3e */
if(!s->budget--) { s->failed_pc=0x0c093b3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b40;
P_0c093b40: /* original 63f2, guest PC 0x0c093b40 */
if(!s->budget--) { s->failed_pc=0x0c093b40u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c093b42;
P_0c093b42: /* original 9276, guest PC 0x0c093b42 */
if(!s->budget--) { s->failed_pc=0x0c093b42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c32u,2);
goto P_0c093b44;
P_0c093b44: /* original 6132, guest PC 0x0c093b44 */
if(!s->budget--) { s->failed_pc=0x0c093b44u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c093b46;
P_0c093b46: /* original 212b, guest PC 0x0c093b46 */
if(!s->budget--) { s->failed_pc=0x0c093b46u; return 0; }
r[1]|=r[2];
goto P_0c093b48;
P_0c093b48: /* original 2312, guest PC 0x0c093b48 */
if(!s->budget--) { s->failed_pc=0x0c093b48u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c093b4a;
P_0c093b4a: /* original 60f2, guest PC 0x0c093b4a */
if(!s->budget--) { s->failed_pc=0x0c093b4au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093b4c;
P_0c093b4c: /* original 7f18, guest PC 0x0c093b4c */
if(!s->budget--) { s->failed_pc=0x0c093b4cu; return 0; }
r[15]+=0x00000018u;
goto P_0c093b4e;
P_0c093b4e: /* original 6002, guest PC 0x0c093b4e */
if(!s->budget--) { s->failed_pc=0x0c093b4eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c093b50;
P_0c093b50: /* original 000b, guest PC 0x0c093b50 */
if(!s->budget--) { s->failed_pc=0x0c093b50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093b52: /* original 6ef6, guest PC 0x0c093b52 */
if(!s->budget--) { s->failed_pc=0x0c093b52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c093b54u,s,ram);
P_0c094242: /* original f40b, guest PC 0x0c094242 */
if(!s->budget--) { s->failed_pc=0x0c094242u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094244;
P_0c094244: /* original 64f3, guest PC 0x0c094244 */
if(!s->budget--) { s->failed_pc=0x0c094244u; return 0; }
r[4]=r[15];
goto P_0c094246;
P_0c094246: /* original 7404, guest PC 0x0c094246 */
if(!s->budget--) { s->failed_pc=0x0c094246u; return 0; }
r[4]+=0x00000004u;
goto P_0c094248;
P_0c094248: /* original f049, guest PC 0x0c094248 */
if(!s->budget--) { s->failed_pc=0x0c094248u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424a;
P_0c09424a: /* original f149, guest PC 0x0c09424a */
if(!s->budget--) { s->failed_pc=0x0c09424au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424c;
P_0c09424c: /* original f249, guest PC 0x0c09424c */
if(!s->budget--) { s->failed_pc=0x0c09424cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424e;
P_0c09424e: /* original f38d, guest PC 0x0c09424e */
if(!s->budget--) { s->failed_pc=0x0c09424eu; return 0; }
fr[3]=0;
goto P_0c094250;
P_0c094250: /* original f0ed, guest PC 0x0c094250 */
if(!s->budget--) { s->failed_pc=0x0c094250u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c094252;
P_0c094252: /* original f37d, guest PC 0x0c094252 */
if(!s->budget--) { s->failed_pc=0x0c094252u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c094254;
P_0c094254: /* original f232, guest PC 0x0c094254 */
if(!s->budget--) { s->failed_pc=0x0c094254u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c094256;
P_0c094256: /* original f132, guest PC 0x0c094256 */
if(!s->budget--) { s->failed_pc=0x0c094256u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c094258;
P_0c094258: /* original f032, guest PC 0x0c094258 */
if(!s->budget--) { s->failed_pc=0x0c094258u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c09425a;
P_0c09425a: /* original f42b, guest PC 0x0c09425a */
if(!s->budget--) { s->failed_pc=0x0c09425au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09425c;
P_0c09425c: /* original f41b, guest PC 0x0c09425c */
if(!s->budget--) { s->failed_pc=0x0c09425cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09425e;
P_0c09425e: /* original f40b, guest PC 0x0c09425e */
if(!s->budget--) { s->failed_pc=0x0c09425eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094260;
P_0c094260: /* original d31f, guest PC 0x0c094260 */
if(!s->budget--) { s->failed_pc=0x0c094260u; return 0; }
r[3]=read(ram,0x0c0942e0u,4);
goto P_0c094262;
P_0c094262: /* original 65f3, guest PC 0x0c094262 */
if(!s->budget--) { s->failed_pc=0x0c094262u; return 0; }
r[5]=r[15];
goto P_0c094264;
P_0c094264: /* original d41d, guest PC 0x0c094264 */
if(!s->budget--) { s->failed_pc=0x0c094264u; return 0; }
r[4]=read(ram,0x0c0942dcu,4);
goto P_0c094266;
P_0c094266: /* original 430b, guest PC 0x0c094266 */
if(!s->budget--) { s->failed_pc=0x0c094266u; return 0; }
target=r[3];
r[16]=0x0c09426au;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09426au) { target=s->pc; goto dispatch; }
goto P_0c09426a;
P_0c094268: /* original 7504, guest PC 0x0c094268 */
if(!s->budget--) { s->failed_pc=0x0c094268u; return 0; }
r[5]+=0x00000004u;
goto P_0c09426a;
P_0c09426a: /* original d21e, guest PC 0x0c09426a */
if(!s->budget--) { s->failed_pc=0x0c09426au; return 0; }
r[2]=read(ram,0x0c0942e4u,4);
goto P_0c09426c;
P_0c09426c: /* original 22d8, guest PC 0x0c09426c */
if(!s->budget--) { s->failed_pc=0x0c09426cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09426e;
P_0c09426e: /* original 8906, guest PC 0x0c09426e */
if(!s->budget--) { s->failed_pc=0x0c09426eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09427e; }
goto P_0c094270;
P_0c094270: /* original d21e, guest PC 0x0c094270 */
if(!s->budget--) { s->failed_pc=0x0c094270u; return 0; }
r[2]=read(ram,0x0c0942ecu,4);
goto P_0c094272;
P_0c094272: /* original d41d, guest PC 0x0c094272 */
if(!s->budget--) { s->failed_pc=0x0c094272u; return 0; }
r[4]=read(ram,0x0c0942e8u,4);
goto P_0c094274;
P_0c094274: /* original 420b, guest PC 0x0c094274 */
if(!s->budget--) { s->failed_pc=0x0c094274u; return 0; }
target=r[2];
r[16]=0x0c094278u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094278u) { target=s->pc; goto dispatch; }
goto P_0c094278;
P_0c094276: /* original 0009, guest PC 0x0c094276 */
if(!s->budget--) { s->failed_pc=0x0c094276u; return 0; }
goto P_0c094278;
P_0c094278: /* original d31d, guest PC 0x0c094278 */
if(!s->budget--) { s->failed_pc=0x0c094278u; return 0; }
r[3]=read(ram,0x0c0942f0u,4);
goto P_0c09427a;
P_0c09427a: /* original 432b, guest PC 0x0c09427a */
if(!s->budget--) { s->failed_pc=0x0c09427au; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09427c: /* original 0009, guest PC 0x0c09427c */
if(!s->budget--) { s->failed_pc=0x0c09427cu; return 0; }
goto P_0c09427e;
P_0c09427e: /* original 9328, guest PC 0x0c09427e */
if(!s->budget--) { s->failed_pc=0x0c09427eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d2u,2);
goto P_0c094280;
P_0c094280: /* original 2d38, guest PC 0x0c094280 */
if(!s->budget--) { s->failed_pc=0x0c094280u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c094282;
P_0c094282: /* original 8b02, guest PC 0x0c094282 */
if(!s->budget--) { s->failed_pc=0x0c094282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09428a; }
goto P_0c094284;
P_0c094284: /* original d21a, guest PC 0x0c094284 */
if(!s->budget--) { s->failed_pc=0x0c094284u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094286;
P_0c094286: /* original 422b, guest PC 0x0c094286 */
if(!s->budget--) { s->failed_pc=0x0c094286u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c094288: /* original 0009, guest PC 0x0c094288 */
if(!s->budget--) { s->failed_pc=0x0c094288u; return 0; }
goto P_0c09428a;
P_0c09428a: /* original d31a, guest PC 0x0c09428a */
if(!s->budget--) { s->failed_pc=0x0c09428au; return 0; }
r[3]=read(ram,0x0c0942f4u,4);
goto P_0c09428c;
P_0c09428c: /* original 430b, guest PC 0x0c09428c */
if(!s->budget--) { s->failed_pc=0x0c09428cu; return 0; }
target=r[3];
r[16]=0x0c094290u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094290u) { target=s->pc; goto dispatch; }
goto P_0c094290;
P_0c09428e: /* original 64a3, guest PC 0x0c09428e */
if(!s->budget--) { s->failed_pc=0x0c09428eu; return 0; }
r[4]=r[10];
goto P_0c094290;
P_0c094290: /* original 7a24, guest PC 0x0c094290 */
if(!s->budget--) { s->failed_pc=0x0c094290u; return 0; }
r[10]+=0x00000024u;
goto P_0c094292;
P_0c094292: /* original 0a83, guest PC 0x0c094292 */
if(!s->budget--) { s->failed_pc=0x0c094292u; return 0; }
goto P_0c094294;
P_0c094294: /* original d216, guest PC 0x0c094294 */
if(!s->budget--) { s->failed_pc=0x0c094294u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094296;
P_0c094296: /* original 422b, guest PC 0x0c094296 */
if(!s->budget--) { s->failed_pc=0x0c094296u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c094298: /* original 0009, guest PC 0x0c094298 */
if(!s->budget--) { s->failed_pc=0x0c094298u; return 0; }
return vf3_matrix_family(0x0c09429au,s,ram);
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
r[16]=0x0c095552u;
write(ram,r[15]+12,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095552u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c09555au;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09555au) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c095584u,s,ram);
P_0c095608: /* original 4f22, guest PC 0x0c095608 */
if(!s->budget--) { s->failed_pc=0x0c095608u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09560a;
P_0c09560a: /* original d342, guest PC 0x0c09560a */
if(!s->budget--) { s->failed_pc=0x0c09560au; return 0; }
r[3]=read(ram,0x0c095714u,4);
goto P_0c09560c;
P_0c09560c: /* original 430b, guest PC 0x0c09560c */
if(!s->budget--) { s->failed_pc=0x0c09560cu; return 0; }
target=r[3];
r[16]=0x0c095610u;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095610u) { target=s->pc; goto dispatch; }
goto P_0c095610;
P_0c09560e: /* original e004, guest PC 0x0c09560e */
if(!s->budget--) { s->failed_pc=0x0c09560eu; return 0; }
r[0]=0x00000004u;
goto P_0c095610;
P_0c095610: /* original 6e03, guest PC 0x0c095610 */
if(!s->budget--) { s->failed_pc=0x0c095610u; return 0; }
r[14]=r[0];
goto P_0c095612;
P_0c095612: /* original 4e15, guest PC 0x0c095612 */
if(!s->budget--) { s->failed_pc=0x0c095612u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c095614;
P_0c095614: /* original 6743, guest PC 0x0c095614 */
if(!s->budget--) { s->failed_pc=0x0c095614u; return 0; }
r[7]=r[4];
goto P_0c095616;
P_0c095616: /* original 8f05, guest PC 0x0c095616 */
if(!s->budget--) { s->failed_pc=0x0c095616u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c095624; }
goto P_0c09561a;
P_0c095618: /* original e400, guest PC 0x0c095618 */
if(!s->budget--) { s->failed_pc=0x0c095618u; return 0; }
r[4]=0x00000000u;
goto P_0c09561a;
P_0c09561a: /* original 7401, guest PC 0x0c09561a */
if(!s->budget--) { s->failed_pc=0x0c09561au; return 0; }
r[4]+=0x00000001u;
goto P_0c09561c;
P_0c09561c: /* original 2752, guest PC 0x0c09561c */
if(!s->budget--) { s->failed_pc=0x0c09561cu; return 0; }
write(ram,r[7],r[5],4);
goto P_0c09561e;
P_0c09561e: /* original 34e3, guest PC 0x0c09561e */
if(!s->budget--) { s->failed_pc=0x0c09561eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c095620;
P_0c095620: /* original 8ffb, guest PC 0x0c095620 */
if(!s->budget--) { s->failed_pc=0x0c095620u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c09561a; }
goto P_0c095624;
P_0c095622: /* original 7704, guest PC 0x0c095622 */
if(!s->budget--) { s->failed_pc=0x0c095622u; return 0; }
r[7]+=0x00000004u;
goto P_0c095624;
P_0c095624: /* original ee03, guest PC 0x0c095624 */
if(!s->budget--) { s->failed_pc=0x0c095624u; return 0; }
r[14]=0x00000003u;
goto P_0c095626;
P_0c095626: /* original 2e69, guest PC 0x0c095626 */
if(!s->budget--) { s->failed_pc=0x0c095626u; return 0; }
r[14]&=r[6];
goto P_0c095628;
P_0c095628: /* original 2ee8, guest PC 0x0c095628 */
if(!s->budget--) { s->failed_pc=0x0c095628u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c09562a;
P_0c09562a: /* original 890c, guest PC 0x0c09562a */
if(!s->budget--) { s->failed_pc=0x0c09562au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095646; }
goto P_0c09562c;
P_0c09562c: /* original 4e15, guest PC 0x0c09562c */
if(!s->budget--) { s->failed_pc=0x0c09562cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c09562e;
P_0c09562e: /* original 6673, guest PC 0x0c09562e */
if(!s->budget--) { s->failed_pc=0x0c09562eu; return 0; }
r[6]=r[7];
goto P_0c095630;
P_0c095630: /* original 8f05, guest PC 0x0c095630 */
if(!s->budget--) { s->failed_pc=0x0c095630u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c09563e; }
goto P_0c095634;
P_0c095632: /* original e400, guest PC 0x0c095632 */
if(!s->budget--) { s->failed_pc=0x0c095632u; return 0; }
r[4]=0x00000000u;
goto P_0c095634;
P_0c095634: /* original 7401, guest PC 0x0c095634 */
if(!s->budget--) { s->failed_pc=0x0c095634u; return 0; }
r[4]+=0x00000001u;
goto P_0c095636;
P_0c095636: /* original 2650, guest PC 0x0c095636 */
if(!s->budget--) { s->failed_pc=0x0c095636u; return 0; }
write(ram,r[6],r[5],1);
goto P_0c095638;
P_0c095638: /* original 34e3, guest PC 0x0c095638 */
if(!s->budget--) { s->failed_pc=0x0c095638u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c09563a;
P_0c09563a: /* original 8ffb, guest PC 0x0c09563a */
if(!s->budget--) { s->failed_pc=0x0c09563au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c095634; }
goto P_0c09563e;
P_0c09563c: /* original 7601, guest PC 0x0c09563c */
if(!s->budget--) { s->failed_pc=0x0c09563cu; return 0; }
r[6]+=0x00000001u;
goto P_0c09563e;
P_0c09563e: /* original 4f26, guest PC 0x0c09563e */
if(!s->budget--) { s->failed_pc=0x0c09563eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095640;
P_0c095640: /* original 6063, guest PC 0x0c095640 */
if(!s->budget--) { s->failed_pc=0x0c095640u; return 0; }
r[0]=r[6];
goto P_0c095642;
P_0c095642: /* original 000b, guest PC 0x0c095642 */
if(!s->budget--) { s->failed_pc=0x0c095642u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095644: /* original 6ef6, guest PC 0x0c095644 */
if(!s->budget--) { s->failed_pc=0x0c095644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c095646;
P_0c095646: /* original 6073, guest PC 0x0c095646 */
if(!s->budget--) { s->failed_pc=0x0c095646u; return 0; }
r[0]=r[7];
goto P_0c095648;
P_0c095648: /* original 4f26, guest PC 0x0c095648 */
if(!s->budget--) { s->failed_pc=0x0c095648u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09564a;
P_0c09564a: /* original 000b, guest PC 0x0c09564a */
if(!s->budget--) { s->failed_pc=0x0c09564au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09564c: /* original 6ef6, guest PC 0x0c09564c */
if(!s->budget--) { s->failed_pc=0x0c09564cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09564eu,s,ram);
P_0c095652: /* original 4f22, guest PC 0x0c095652 */
if(!s->budget--) { s->failed_pc=0x0c095652u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095654;
P_0c095654: /* original d32f, guest PC 0x0c095654 */
if(!s->budget--) { s->failed_pc=0x0c095654u; return 0; }
r[3]=read(ram,0x0c095714u,4);
goto P_0c095656;
P_0c095656: /* original 430b, guest PC 0x0c095656 */
if(!s->budget--) { s->failed_pc=0x0c095656u; return 0; }
target=r[3];
r[16]=0x0c09565au;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09565au) { target=s->pc; goto dispatch; }
goto P_0c09565a;
P_0c095658: /* original e004, guest PC 0x0c095658 */
if(!s->budget--) { s->failed_pc=0x0c095658u; return 0; }
r[0]=0x00000004u;
goto P_0c09565a;
P_0c09565a: /* original 6743, guest PC 0x0c09565a */
if(!s->budget--) { s->failed_pc=0x0c09565au; return 0; }
r[7]=r[4];
goto P_0c09565c;
P_0c09565c: /* original 6e03, guest PC 0x0c09565c */
if(!s->budget--) { s->failed_pc=0x0c09565cu; return 0; }
r[14]=r[0];
goto P_0c09565e;
P_0c09565e: /* original 4e15, guest PC 0x0c09565e */
if(!s->budget--) { s->failed_pc=0x0c09565eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c095660;
P_0c095660: /* original 6453, guest PC 0x0c095660 */
if(!s->budget--) { s->failed_pc=0x0c095660u; return 0; }
r[4]=r[5];
goto P_0c095662;
P_0c095662: /* original 8f06, guest PC 0x0c095662 */
if(!s->budget--) { s->failed_pc=0x0c095662u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c095672; }
goto P_0c095666;
P_0c095664: /* original e500, guest PC 0x0c095664 */
if(!s->budget--) { s->failed_pc=0x0c095664u; return 0; }
r[5]=0x00000000u;
goto P_0c095666;
P_0c095666: /* original 6246, guest PC 0x0c095666 */
if(!s->budget--) { s->failed_pc=0x0c095666u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[2]=tmp;
goto P_0c095668;
P_0c095668: /* original 7501, guest PC 0x0c095668 */
if(!s->budget--) { s->failed_pc=0x0c095668u; return 0; }
r[5]+=0x00000001u;
goto P_0c09566a;
P_0c09566a: /* original 35e3, guest PC 0x0c09566a */
if(!s->budget--) { s->failed_pc=0x0c09566au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c09566c;
P_0c09566c: /* original 2722, guest PC 0x0c09566c */
if(!s->budget--) { s->failed_pc=0x0c09566cu; return 0; }
write(ram,r[7],r[2],4);
goto P_0c09566e;
P_0c09566e: /* original 8ffa, guest PC 0x0c09566e */
if(!s->budget--) { s->failed_pc=0x0c09566eu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c095666; }
goto P_0c095672;
P_0c095670: /* original 7704, guest PC 0x0c095670 */
if(!s->budget--) { s->failed_pc=0x0c095670u; return 0; }
r[7]+=0x00000004u;
goto P_0c095672;
P_0c095672: /* original ee03, guest PC 0x0c095672 */
if(!s->budget--) { s->failed_pc=0x0c095672u; return 0; }
r[14]=0x00000003u;
goto P_0c095674;
P_0c095674: /* original 2e69, guest PC 0x0c095674 */
if(!s->budget--) { s->failed_pc=0x0c095674u; return 0; }
r[14]&=r[6];
goto P_0c095676;
P_0c095676: /* original 2ee8, guest PC 0x0c095676 */
if(!s->budget--) { s->failed_pc=0x0c095676u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c095678;
P_0c095678: /* original 890d, guest PC 0x0c095678 */
if(!s->budget--) { s->failed_pc=0x0c095678u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095696; }
goto P_0c09567a;
P_0c09567a: /* original 4e15, guest PC 0x0c09567a */
if(!s->budget--) { s->failed_pc=0x0c09567au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c09567c;
P_0c09567c: /* original 6673, guest PC 0x0c09567c */
if(!s->budget--) { s->failed_pc=0x0c09567cu; return 0; }
r[6]=r[7];
goto P_0c09567e;
P_0c09567e: /* original 8f06, guest PC 0x0c09567e */
if(!s->budget--) { s->failed_pc=0x0c09567eu; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c09568e; }
goto P_0c095682;
P_0c095680: /* original e500, guest PC 0x0c095680 */
if(!s->budget--) { s->failed_pc=0x0c095680u; return 0; }
r[5]=0x00000000u;
goto P_0c095682;
P_0c095682: /* original 6346, guest PC 0x0c095682 */
if(!s->budget--) { s->failed_pc=0x0c095682u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c095684;
P_0c095684: /* original 7501, guest PC 0x0c095684 */
if(!s->budget--) { s->failed_pc=0x0c095684u; return 0; }
r[5]+=0x00000001u;
goto P_0c095686;
P_0c095686: /* original 35e3, guest PC 0x0c095686 */
if(!s->budget--) { s->failed_pc=0x0c095686u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c095688;
P_0c095688: /* original 2630, guest PC 0x0c095688 */
if(!s->budget--) { s->failed_pc=0x0c095688u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c09568a;
P_0c09568a: /* original 8ffa, guest PC 0x0c09568a */
if(!s->budget--) { s->failed_pc=0x0c09568au; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c095682; }
goto P_0c09568e;
P_0c09568c: /* original 7601, guest PC 0x0c09568c */
if(!s->budget--) { s->failed_pc=0x0c09568cu; return 0; }
r[6]+=0x00000001u;
goto P_0c09568e;
P_0c09568e: /* original 4f26, guest PC 0x0c09568e */
if(!s->budget--) { s->failed_pc=0x0c09568eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095690;
P_0c095690: /* original 6063, guest PC 0x0c095690 */
if(!s->budget--) { s->failed_pc=0x0c095690u; return 0; }
r[0]=r[6];
goto P_0c095692;
P_0c095692: /* original 000b, guest PC 0x0c095692 */
if(!s->budget--) { s->failed_pc=0x0c095692u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095694: /* original 6ef6, guest PC 0x0c095694 */
if(!s->budget--) { s->failed_pc=0x0c095694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c095696;
P_0c095696: /* original 6073, guest PC 0x0c095696 */
if(!s->budget--) { s->failed_pc=0x0c095696u; return 0; }
r[0]=r[7];
goto P_0c095698;
P_0c095698: /* original 4f26, guest PC 0x0c095698 */
if(!s->budget--) { s->failed_pc=0x0c095698u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09569a;
P_0c09569a: /* original 000b, guest PC 0x0c09569a */
if(!s->budget--) { s->failed_pc=0x0c09569au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09569c: /* original 6ef6, guest PC 0x0c09569c */
if(!s->budget--) { s->failed_pc=0x0c09569cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09569eu,s,ram);
P_0c096650: /* original 4f22, guest PC 0x0c096650 */
if(!s->budget--) { s->failed_pc=0x0c096650u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096652;
P_0c096652: /* original dd2a, guest PC 0x0c096652 */
if(!s->budget--) { s->failed_pc=0x0c096652u; return 0; }
r[13]=read(ram,0x0c0966fcu,4);
goto P_0c096654;
P_0c096654: /* original de28, guest PC 0x0c096654 */
if(!s->budget--) { s->failed_pc=0x0c096654u; return 0; }
r[14]=read(ram,0x0c0966f8u,4);
goto P_0c096656;
P_0c096656: /* original be74, guest PC 0x0c096656 */
if(!s->budget--) { s->failed_pc=0x0c096656u; return 0; }
target=0x0c096342u; r[16]=0x0c09665au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09665au) { target=s->pc; goto dispatch; }
goto P_0c09665a;
P_0c096658: /* original 0009, guest PC 0x0c096658 */
if(!s->budget--) { s->failed_pc=0x0c096658u; return 0; }
goto P_0c09665a;
P_0c09665a: /* original d229, guest PC 0x0c09665a */
if(!s->budget--) { s->failed_pc=0x0c09665au; return 0; }
r[2]=read(ram,0x0c096700u,4);
goto P_0c09665c;
P_0c09665c: /* original be5e, guest PC 0x0c09665c */
if(!s->budget--) { s->failed_pc=0x0c09665cu; return 0; }
target=0x0c09631cu; r[16]=0x0c096660u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096660u) { target=s->pc; goto dispatch; }
goto P_0c096660;
P_0c09665e: /* original 6422, guest PC 0x0c09665e */
if(!s->budget--) { s->failed_pc=0x0c09665eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c096660;
P_0c096660: /* original d228, guest PC 0x0c096660 */
if(!s->budget--) { s->failed_pc=0x0c096660u; return 0; }
r[2]=read(ram,0x0c096704u,4);
goto P_0c096662;
P_0c096662: /* original be5b, guest PC 0x0c096662 */
if(!s->budget--) { s->failed_pc=0x0c096662u; return 0; }
target=0x0c09631cu; r[16]=0x0c096666u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096666u) { target=s->pc; goto dispatch; }
goto P_0c096666;
P_0c096664: /* original 6422, guest PC 0x0c096664 */
if(!s->budget--) { s->failed_pc=0x0c096664u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c096666;
P_0c096666: /* original 54d2, guest PC 0x0c096666 */
if(!s->budget--) { s->failed_pc=0x0c096666u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c096668;
P_0c096668: /* original e502, guest PC 0x0c096668 */
if(!s->budget--) { s->failed_pc=0x0c096668u; return 0; }
r[5]=0x00000002u;
goto P_0c09666a;
P_0c09666a: /* original 6243, guest PC 0x0c09666a */
if(!s->budget--) { s->failed_pc=0x0c09666au; return 0; }
r[2]=r[4];
goto P_0c09666c;
P_0c09666c: /* original 2258, guest PC 0x0c09666c */
if(!s->budget--) { s->failed_pc=0x0c09666cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09666e;
P_0c09666e: /* original 890f, guest PC 0x0c09666e */
if(!s->budget--) { s->failed_pc=0x0c09666eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096690; }
goto P_0c096670;
P_0c096670: /* original 61e2, guest PC 0x0c096670 */
if(!s->budget--) { s->failed_pc=0x0c096670u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c096672;
P_0c096672: /* original 933c, guest PC 0x0c096672 */
if(!s->budget--) { s->failed_pc=0x0c096672u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966eeu,2);
goto P_0c096674;
P_0c096674: /* original 2138, guest PC 0x0c096674 */
if(!s->budget--) { s->failed_pc=0x0c096674u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c096676;
P_0c096676: /* original 8b01, guest PC 0x0c096676 */
if(!s->budget--) { s->failed_pc=0x0c096676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09667c; }
goto P_0c096678;
P_0c096678: /* original a006, guest PC 0x0c096678 */
if(!s->budget--) { s->failed_pc=0x0c096678u; return 0; }
r[0]=0x00000014u;
goto P_0c096688;
P_0c09667a: /* original e014, guest PC 0x0c09667a */
if(!s->budget--) { s->failed_pc=0x0c09667au; return 0; }
r[0]=0x00000014u;
goto P_0c09667c;
P_0c09667c: /* original 84eb, guest PC 0x0c09667c */
if(!s->budget--) { s->failed_pc=0x0c09667cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09667e;
P_0c09667e: /* original e320, guest PC 0x0c09667e */
if(!s->budget--) { s->failed_pc=0x0c09667eu; return 0; }
r[3]=0x00000020u;
goto P_0c096680;
P_0c096680: /* original 600c, guest PC 0x0c096680 */
if(!s->budget--) { s->failed_pc=0x0c096680u; return 0; }
r[0]=r[0]&255u;
goto P_0c096682;
P_0c096682: /* original 3033, guest PC 0x0c096682 */
if(!s->budget--) { s->failed_pc=0x0c096682u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[3])!=0);
goto P_0c096684;
P_0c096684: /* original 8b01, guest PC 0x0c096684 */
if(!s->budget--) { s->failed_pc=0x0c096684u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09668a; }
goto P_0c096686;
P_0c096686: /* original 6053, guest PC 0x0c096686 */
if(!s->budget--) { s->failed_pc=0x0c096686u; return 0; }
r[0]=r[5];
goto P_0c096688;
P_0c096688: /* original 80ea, guest PC 0x0c096688 */
if(!s->budget--) { s->failed_pc=0x0c096688u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09668a;
P_0c09668a: /* original e3fd, guest PC 0x0c09668a */
if(!s->budget--) { s->failed_pc=0x0c09668au; return 0; }
r[3]=0xfffffffdu;
goto P_0c09668c;
P_0c09668c: /* original 2439, guest PC 0x0c09668c */
if(!s->budget--) { s->failed_pc=0x0c09668cu; return 0; }
r[4]&=r[3];
goto P_0c09668e;
P_0c09668e: /* original 1d42, guest PC 0x0c09668e */
if(!s->budget--) { s->failed_pc=0x0c09668eu; return 0; }
write(ram,r[13]+8,r[4],4);
goto P_0c096690;
P_0c096690: /* original 4f26, guest PC 0x0c096690 */
if(!s->budget--) { s->failed_pc=0x0c096690u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096692;
P_0c096692: /* original 6df6, guest PC 0x0c096692 */
if(!s->budget--) { s->failed_pc=0x0c096692u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096694;
P_0c096694: /* original 000b, guest PC 0x0c096694 */
if(!s->budget--) { s->failed_pc=0x0c096694u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096696: /* original 6ef6, guest PC 0x0c096696 */
if(!s->budget--) { s->failed_pc=0x0c096696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096698u,s,ram);
P_0c09d42c: /* original 4f22, guest PC 0x0c09d42c */
if(!s->budget--) { s->failed_pc=0x0c09d42cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d42e;
P_0c09d42e: /* original e004, guest PC 0x0c09d42e */
if(!s->budget--) { s->failed_pc=0x0c09d42eu; return 0; }
r[0]=0x00000004u;
goto P_0c09d430;
P_0c09d430: /* original 7ff0, guest PC 0x0c09d430 */
if(!s->budget--) { s->failed_pc=0x0c09d430u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d432;
P_0c09d432: /* original 2f42, guest PC 0x0c09d432 */
if(!s->budget--) { s->failed_pc=0x0c09d432u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d434;
P_0c09d434: /* original 64f3, guest PC 0x0c09d434 */
if(!s->budget--) { s->failed_pc=0x0c09d434u; return 0; }
r[4]=r[15];
goto P_0c09d436;
P_0c09d436: /* original ff47, guest PC 0x0c09d436 */
if(!s->budget--) { s->failed_pc=0x0c09d436u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d438;
P_0c09d438: /* original e008, guest PC 0x0c09d438 */
if(!s->budget--) { s->failed_pc=0x0c09d438u; return 0; }
r[0]=0x00000008u;
goto P_0c09d43a;
P_0c09d43a: /* original f38d, guest PC 0x0c09d43a */
if(!s->budget--) { s->failed_pc=0x0c09d43au; return 0; }
fr[3]=0;
goto P_0c09d43c;
P_0c09d43c: /* original ff37, guest PC 0x0c09d43c */
if(!s->budget--) { s->failed_pc=0x0c09d43cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09d43e;
P_0c09d43e: /* original e00c, guest PC 0x0c09d43e */
if(!s->budget--) { s->failed_pc=0x0c09d43eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09d440;
P_0c09d440: /* original ff57, guest PC 0x0c09d440 */
if(!s->budget--) { s->failed_pc=0x0c09d440u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d442;
P_0c09d442: /* original d34e, guest PC 0x0c09d442 */
if(!s->budget--) { s->failed_pc=0x0c09d442u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d444;
P_0c09d444: /* original 65f2, guest PC 0x0c09d444 */
if(!s->budget--) { s->failed_pc=0x0c09d444u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d446;
P_0c09d446: /* original 430b, guest PC 0x0c09d446 */
if(!s->budget--) { s->failed_pc=0x0c09d446u; return 0; }
target=r[3];
r[16]=0x0c09d44au;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d44au) { target=s->pc; goto dispatch; }
goto P_0c09d44a;
P_0c09d448: /* original 7404, guest PC 0x0c09d448 */
if(!s->budget--) { s->failed_pc=0x0c09d448u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d44a;
P_0c09d44a: /* original 7f10, guest PC 0x0c09d44a */
if(!s->budget--) { s->failed_pc=0x0c09d44au; return 0; }
r[15]+=0x00000010u;
goto P_0c09d44c;
P_0c09d44c: /* original 4f26, guest PC 0x0c09d44c */
if(!s->budget--) { s->failed_pc=0x0c09d44cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d44e;
P_0c09d44e: /* original 000b, guest PC 0x0c09d44e */
if(!s->budget--) { s->failed_pc=0x0c09d44eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d450: /* original 0009, guest PC 0x0c09d450 */
if(!s->budget--) { s->failed_pc=0x0c09d450u; return 0; }
return vf3_matrix_family(0x0c09d452u,s,ram);
P_0c09d4b0: /* original 4f22, guest PC 0x0c09d4b0 */
if(!s->budget--) { s->failed_pc=0x0c09d4b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4b2;
P_0c09d4b2: /* original 7ff0, guest PC 0x0c09d4b2 */
if(!s->budget--) { s->failed_pc=0x0c09d4b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d4b4;
P_0c09d4b4: /* original 2f51, guest PC 0x0c09d4b4 */
if(!s->budget--) { s->failed_pc=0x0c09d4b4u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c09d4b6;
P_0c09d4b6: /* original 6041, guest PC 0x0c09d4b6 */
if(!s->budget--) { s->failed_pc=0x0c09d4b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[0]=tmp;
goto P_0c09d4b8;
P_0c09d4b8: /* original 81f4, guest PC 0x0c09d4b8 */
if(!s->budget--) { s->failed_pc=0x0c09d4b8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c09d4ba;
P_0c09d4ba: /* original 8541, guest PC 0x0c09d4ba */
if(!s->budget--) { s->failed_pc=0x0c09d4bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09d4bc;
P_0c09d4bc: /* original 81f2, guest PC 0x0c09d4bc */
if(!s->budget--) { s->failed_pc=0x0c09d4bcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c09d4be;
P_0c09d4be: /* original 8542, guest PC 0x0c09d4be */
if(!s->budget--) { s->failed_pc=0x0c09d4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c09d4c0;
P_0c09d4c0: /* original 81f6, guest PC 0x0c09d4c0 */
if(!s->budget--) { s->failed_pc=0x0c09d4c0u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c09d4c2;
P_0c09d4c2: /* original 85f4, guest PC 0x0c09d4c2 */
if(!s->budget--) { s->failed_pc=0x0c09d4c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c09d4c4;
P_0c09d4c4: /* original d32e, guest PC 0x0c09d4c4 */
if(!s->budget--) { s->failed_pc=0x0c09d4c4u; return 0; }
r[3]=read(ram,0x0c09d580u,4);
goto P_0c09d4c6;
P_0c09d4c6: /* original 6403, guest PC 0x0c09d4c6 */
if(!s->budget--) { s->failed_pc=0x0c09d4c6u; return 0; }
r[4]=r[0];
goto P_0c09d4c8;
P_0c09d4c8: /* original 430b, guest PC 0x0c09d4c8 */
if(!s->budget--) { s->failed_pc=0x0c09d4c8u; return 0; }
target=r[3];
r[16]=0x0c09d4ccu;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d4ccu) { target=s->pc; goto dispatch; }
goto P_0c09d4cc;
P_0c09d4ca: /* original 644d, guest PC 0x0c09d4ca */
if(!s->budget--) { s->failed_pc=0x0c09d4cau; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4cc;
P_0c09d4cc: /* original 85f2, guest PC 0x0c09d4cc */
if(!s->budget--) { s->failed_pc=0x0c09d4ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c09d4ce;
P_0c09d4ce: /* original 64f1, guest PC 0x0c09d4ce */
if(!s->budget--) { s->failed_pc=0x0c09d4ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c09d4d0;
P_0c09d4d0: /* original d32c, guest PC 0x0c09d4d0 */
if(!s->budget--) { s->failed_pc=0x0c09d4d0u; return 0; }
r[3]=read(ram,0x0c09d584u,4);
goto P_0c09d4d2;
P_0c09d4d2: /* original 600d, guest PC 0x0c09d4d2 */
if(!s->budget--) { s->failed_pc=0x0c09d4d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09d4d4;
P_0c09d4d4: /* original 430b, guest PC 0x0c09d4d4 */
if(!s->budget--) { s->failed_pc=0x0c09d4d4u; return 0; }
target=r[3];
r[16]=0x0c09d4d8u;
r[4]+=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d4d8u) { target=s->pc; goto dispatch; }
goto P_0c09d4d8;
P_0c09d4d6: /* original 340c, guest PC 0x0c09d4d6 */
if(!s->budget--) { s->failed_pc=0x0c09d4d6u; return 0; }
r[4]+=r[0];
goto P_0c09d4d8;
P_0c09d4d8: /* original 85f6, guest PC 0x0c09d4d8 */
if(!s->budget--) { s->failed_pc=0x0c09d4d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c09d4da;
P_0c09d4da: /* original 7f10, guest PC 0x0c09d4da */
if(!s->budget--) { s->failed_pc=0x0c09d4dau; return 0; }
r[15]+=0x00000010u;
goto P_0c09d4dc;
P_0c09d4dc: /* original d32a, guest PC 0x0c09d4dc */
if(!s->budget--) { s->failed_pc=0x0c09d4dcu; return 0; }
r[3]=read(ram,0x0c09d588u,4);
goto P_0c09d4de;
P_0c09d4de: /* original 6403, guest PC 0x0c09d4de */
if(!s->budget--) { s->failed_pc=0x0c09d4deu; return 0; }
r[4]=r[0];
goto P_0c09d4e0;
P_0c09d4e0: /* original 644d, guest PC 0x0c09d4e0 */
if(!s->budget--) { s->failed_pc=0x0c09d4e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09d4e2;
P_0c09d4e2: /* original 432b, guest PC 0x0c09d4e2 */
if(!s->budget--) { s->failed_pc=0x0c09d4e2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09d4e4: /* original 4f26, guest PC 0x0c09d4e4 */
if(!s->budget--) { s->failed_pc=0x0c09d4e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c09d4e6u,s,ram);
P_0c09d4ee: /* original 4f22, guest PC 0x0c09d4ee */
if(!s->budget--) { s->failed_pc=0x0c09d4eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d4f0;
P_0c09d4f0: /* original f3e6, guest PC 0x0c09d4f0 */
if(!s->budget--) { s->failed_pc=0x0c09d4f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4f2;
P_0c09d4f2: /* original e034, guest PC 0x0c09d4f2 */
if(!s->budget--) { s->failed_pc=0x0c09d4f2u; return 0; }
r[0]=0x00000034u;
goto P_0c09d4f4;
P_0c09d4f4: /* original 7ff4, guest PC 0x0c09d4f4 */
if(!s->budget--) { s->failed_pc=0x0c09d4f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09d4f6;
P_0c09d4f6: /* original 6df3, guest PC 0x0c09d4f6 */
if(!s->budget--) { s->failed_pc=0x0c09d4f6u; return 0; }
r[13]=r[15];
goto P_0c09d4f8;
P_0c09d4f8: /* original fd3a, guest PC 0x0c09d4f8 */
if(!s->budget--) { s->failed_pc=0x0c09d4f8u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c09d4fa;
P_0c09d4fa: /* original f3e6, guest PC 0x0c09d4fa */
if(!s->budget--) { s->failed_pc=0x0c09d4fau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d4fc;
P_0c09d4fc: /* original e004, guest PC 0x0c09d4fc */
if(!s->budget--) { s->failed_pc=0x0c09d4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c09d4fe;
P_0c09d4fe: /* original fd37, guest PC 0x0c09d4fe */
if(!s->budget--) { s->failed_pc=0x0c09d4feu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d500;
P_0c09d500: /* original e038, guest PC 0x0c09d500 */
if(!s->budget--) { s->failed_pc=0x0c09d500u; return 0; }
r[0]=0x00000038u;
goto P_0c09d502;
P_0c09d502: /* original f3e6, guest PC 0x0c09d502 */
if(!s->budget--) { s->failed_pc=0x0c09d502u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09d504;
P_0c09d504: /* original e008, guest PC 0x0c09d504 */
if(!s->budget--) { s->failed_pc=0x0c09d504u; return 0; }
r[0]=0x00000008u;
goto P_0c09d506;
P_0c09d506: /* original fd37, guest PC 0x0c09d506 */
if(!s->budget--) { s->failed_pc=0x0c09d506u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09d508;
P_0c09d508: /* original d320, guest PC 0x0c09d508 */
if(!s->budget--) { s->failed_pc=0x0c09d508u; return 0; }
r[3]=read(ram,0x0c09d58cu,4);
goto P_0c09d50a;
P_0c09d50a: /* original 430b, guest PC 0x0c09d50a */
if(!s->budget--) { s->failed_pc=0x0c09d50au; return 0; }
target=r[3];
r[16]=0x0c09d50eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d50eu) { target=s->pc; goto dispatch; }
goto P_0c09d50e;
P_0c09d50c: /* original 64e3, guest PC 0x0c09d50c */
if(!s->budget--) { s->failed_pc=0x0c09d50cu; return 0; }
r[4]=r[14];
goto P_0c09d50e;
P_0c09d50e: /* original f3d8, guest PC 0x0c09d50e */
if(!s->budget--) { s->failed_pc=0x0c09d50eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c09d510;
P_0c09d510: /* original e030, guest PC 0x0c09d510 */
if(!s->budget--) { s->failed_pc=0x0c09d510u; return 0; }
r[0]=0x00000030u;
goto P_0c09d512;
P_0c09d512: /* original 7f0c, guest PC 0x0c09d512 */
if(!s->budget--) { s->failed_pc=0x0c09d512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09d514;
P_0c09d514: /* original fe37, guest PC 0x0c09d514 */
if(!s->budget--) { s->failed_pc=0x0c09d514u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d516;
P_0c09d516: /* original e004, guest PC 0x0c09d516 */
if(!s->budget--) { s->failed_pc=0x0c09d516u; return 0; }
r[0]=0x00000004u;
goto P_0c09d518;
P_0c09d518: /* original f3d6, guest PC 0x0c09d518 */
if(!s->budget--) { s->failed_pc=0x0c09d518u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d51a;
P_0c09d51a: /* original e034, guest PC 0x0c09d51a */
if(!s->budget--) { s->failed_pc=0x0c09d51au; return 0; }
r[0]=0x00000034u;
goto P_0c09d51c;
P_0c09d51c: /* original 4f26, guest PC 0x0c09d51c */
if(!s->budget--) { s->failed_pc=0x0c09d51cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d51e;
P_0c09d51e: /* original fe37, guest PC 0x0c09d51e */
if(!s->budget--) { s->failed_pc=0x0c09d51eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d520;
P_0c09d520: /* original e008, guest PC 0x0c09d520 */
if(!s->budget--) { s->failed_pc=0x0c09d520u; return 0; }
r[0]=0x00000008u;
goto P_0c09d522;
P_0c09d522: /* original f3d6, guest PC 0x0c09d522 */
if(!s->budget--) { s->failed_pc=0x0c09d522u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09d524;
P_0c09d524: /* original e038, guest PC 0x0c09d524 */
if(!s->budget--) { s->failed_pc=0x0c09d524u; return 0; }
r[0]=0x00000038u;
goto P_0c09d526;
P_0c09d526: /* original fe37, guest PC 0x0c09d526 */
if(!s->budget--) { s->failed_pc=0x0c09d526u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09d528;
P_0c09d528: /* original 6df6, guest PC 0x0c09d528 */
if(!s->budget--) { s->failed_pc=0x0c09d528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d52a;
P_0c09d52a: /* original 000b, guest PC 0x0c09d52a */
if(!s->budget--) { s->failed_pc=0x0c09d52au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d52c: /* original 6ef6, guest PC 0x0c09d52c */
if(!s->budget--) { s->failed_pc=0x0c09d52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09d52e;
P_0c09d52e: /* original 4f22, guest PC 0x0c09d52e */
if(!s->budget--) { s->failed_pc=0x0c09d52eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d530;
P_0c09d530: /* original e004, guest PC 0x0c09d530 */
if(!s->budget--) { s->failed_pc=0x0c09d530u; return 0; }
r[0]=0x00000004u;
goto P_0c09d532;
P_0c09d532: /* original 7ff0, guest PC 0x0c09d532 */
if(!s->budget--) { s->failed_pc=0x0c09d532u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d534;
P_0c09d534: /* original 2f42, guest PC 0x0c09d534 */
if(!s->budget--) { s->failed_pc=0x0c09d534u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d536;
P_0c09d536: /* original 64f3, guest PC 0x0c09d536 */
if(!s->budget--) { s->failed_pc=0x0c09d536u; return 0; }
r[4]=r[15];
goto P_0c09d538;
P_0c09d538: /* original ff47, guest PC 0x0c09d538 */
if(!s->budget--) { s->failed_pc=0x0c09d538u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d53a;
P_0c09d53a: /* original e008, guest PC 0x0c09d53a */
if(!s->budget--) { s->failed_pc=0x0c09d53au; return 0; }
r[0]=0x00000008u;
goto P_0c09d53c;
P_0c09d53c: /* original f48d, guest PC 0x0c09d53c */
if(!s->budget--) { s->failed_pc=0x0c09d53cu; return 0; }
fr[4]=0;
goto P_0c09d53e;
P_0c09d53e: /* original ff47, guest PC 0x0c09d53e */
if(!s->budget--) { s->failed_pc=0x0c09d53eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d540;
P_0c09d540: /* original e00c, guest PC 0x0c09d540 */
if(!s->budget--) { s->failed_pc=0x0c09d540u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d542;
P_0c09d542: /* original ff47, guest PC 0x0c09d542 */
if(!s->budget--) { s->failed_pc=0x0c09d542u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d544;
P_0c09d544: /* original d30d, guest PC 0x0c09d544 */
if(!s->budget--) { s->failed_pc=0x0c09d544u; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d546;
P_0c09d546: /* original 65f2, guest PC 0x0c09d546 */
if(!s->budget--) { s->failed_pc=0x0c09d546u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d548;
P_0c09d548: /* original 430b, guest PC 0x0c09d548 */
if(!s->budget--) { s->failed_pc=0x0c09d548u; return 0; }
target=r[3];
r[16]=0x0c09d54cu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d54cu) { target=s->pc; goto dispatch; }
goto P_0c09d54c;
P_0c09d54a: /* original 7404, guest PC 0x0c09d54a */
if(!s->budget--) { s->failed_pc=0x0c09d54au; return 0; }
r[4]+=0x00000004u;
goto P_0c09d54c;
P_0c09d54c: /* original 7f10, guest PC 0x0c09d54c */
if(!s->budget--) { s->failed_pc=0x0c09d54cu; return 0; }
r[15]+=0x00000010u;
goto P_0c09d54e;
P_0c09d54e: /* original 4f26, guest PC 0x0c09d54e */
if(!s->budget--) { s->failed_pc=0x0c09d54eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d550;
P_0c09d550: /* original 000b, guest PC 0x0c09d550 */
if(!s->budget--) { s->failed_pc=0x0c09d550u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d552: /* original 0009, guest PC 0x0c09d552 */
if(!s->budget--) { s->failed_pc=0x0c09d552u; return 0; }
goto P_0c09d554;
P_0c09d554: /* original 4f22, guest PC 0x0c09d554 */
if(!s->budget--) { s->failed_pc=0x0c09d554u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d556;
P_0c09d556: /* original e004, guest PC 0x0c09d556 */
if(!s->budget--) { s->failed_pc=0x0c09d556u; return 0; }
r[0]=0x00000004u;
goto P_0c09d558;
P_0c09d558: /* original 7ff0, guest PC 0x0c09d558 */
if(!s->budget--) { s->failed_pc=0x0c09d558u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09d55a;
P_0c09d55a: /* original 2f42, guest PC 0x0c09d55a */
if(!s->budget--) { s->failed_pc=0x0c09d55au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d55c;
P_0c09d55c: /* original 64f3, guest PC 0x0c09d55c */
if(!s->budget--) { s->failed_pc=0x0c09d55cu; return 0; }
r[4]=r[15];
goto P_0c09d55e;
P_0c09d55e: /* original f58d, guest PC 0x0c09d55e */
if(!s->budget--) { s->failed_pc=0x0c09d55eu; return 0; }
fr[5]=0;
goto P_0c09d560;
P_0c09d560: /* original ff57, guest PC 0x0c09d560 */
if(!s->budget--) { s->failed_pc=0x0c09d560u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d562;
P_0c09d562: /* original e008, guest PC 0x0c09d562 */
if(!s->budget--) { s->failed_pc=0x0c09d562u; return 0; }
r[0]=0x00000008u;
goto P_0c09d564;
P_0c09d564: /* original ff47, guest PC 0x0c09d564 */
if(!s->budget--) { s->failed_pc=0x0c09d564u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c09d566;
P_0c09d566: /* original e00c, guest PC 0x0c09d566 */
if(!s->budget--) { s->failed_pc=0x0c09d566u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d568;
P_0c09d568: /* original ff57, guest PC 0x0c09d568 */
if(!s->budget--) { s->failed_pc=0x0c09d568u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c09d56a;
P_0c09d56a: /* original d304, guest PC 0x0c09d56a */
if(!s->budget--) { s->failed_pc=0x0c09d56au; return 0; }
r[3]=read(ram,0x0c09d57cu,4);
goto P_0c09d56c;
P_0c09d56c: /* original 65f2, guest PC 0x0c09d56c */
if(!s->budget--) { s->failed_pc=0x0c09d56cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09d56e;
P_0c09d56e: /* original 430b, guest PC 0x0c09d56e */
if(!s->budget--) { s->failed_pc=0x0c09d56eu; return 0; }
target=r[3];
r[16]=0x0c09d572u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09d572u) { target=s->pc; goto dispatch; }
goto P_0c09d572;
P_0c09d570: /* original 7404, guest PC 0x0c09d570 */
if(!s->budget--) { s->failed_pc=0x0c09d570u; return 0; }
r[4]+=0x00000004u;
goto P_0c09d572;
P_0c09d572: /* original 7f10, guest PC 0x0c09d572 */
if(!s->budget--) { s->failed_pc=0x0c09d572u; return 0; }
r[15]+=0x00000010u;
goto P_0c09d574;
P_0c09d574: /* original 4f26, guest PC 0x0c09d574 */
if(!s->budget--) { s->failed_pc=0x0c09d574u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d576;
P_0c09d576: /* original 000b, guest PC 0x0c09d576 */
if(!s->budget--) { s->failed_pc=0x0c09d576u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d578: /* original 0009, guest PC 0x0c09d578 */
if(!s->budget--) { s->failed_pc=0x0c09d578u; return 0; }
return vf3_matrix_family(0x0c09d57au,s,ram);
P_0c09da22: /* original 4f22, guest PC 0x0c09da22 */
if(!s->budget--) { s->failed_pc=0x0c09da22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09da24;
P_0c09da24: /* original 7ff0, guest PC 0x0c09da24 */
if(!s->budget--) { s->failed_pc=0x0c09da24u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09da26;
P_0c09da26: /* original 64f3, guest PC 0x0c09da26 */
if(!s->budget--) { s->failed_pc=0x0c09da26u; return 0; }
r[4]=r[15];
goto P_0c09da28;
P_0c09da28: /* original 2f52, guest PC 0x0c09da28 */
if(!s->budget--) { s->failed_pc=0x0c09da28u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09da2a;
P_0c09da2a: /* original d32f, guest PC 0x0c09da2a */
if(!s->budget--) { s->failed_pc=0x0c09da2au; return 0; }
r[3]=read(ram,0x0c09dae8u,4);
goto P_0c09da2c;
P_0c09da2c: /* original 430b, guest PC 0x0c09da2c */
if(!s->budget--) { s->failed_pc=0x0c09da2cu; return 0; }
target=r[3];
r[16]=0x0c09da30u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da30u) { target=s->pc; goto dispatch; }
goto P_0c09da30;
P_0c09da2e: /* original 7404, guest PC 0x0c09da2e */
if(!s->budget--) { s->failed_pc=0x0c09da2eu; return 0; }
r[4]+=0x00000004u;
goto P_0c09da30;
P_0c09da30: /* original d229, guest PC 0x0c09da30 */
if(!s->budget--) { s->failed_pc=0x0c09da30u; return 0; }
r[2]=read(ram,0x0c09dad8u,4);
goto P_0c09da32;
P_0c09da32: /* original 420b, guest PC 0x0c09da32 */
if(!s->budget--) { s->failed_pc=0x0c09da32u; return 0; }
target=r[2];
r[16]=0x0c09da36u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da36u) { target=s->pc; goto dispatch; }
goto P_0c09da36;
P_0c09da34: /* original 0009, guest PC 0x0c09da34 */
if(!s->budget--) { s->failed_pc=0x0c09da34u; return 0; }
goto P_0c09da36;
P_0c09da36: /* original 64f2, guest PC 0x0c09da36 */
if(!s->budget--) { s->failed_pc=0x0c09da36u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da38;
P_0c09da38: /* original d328, guest PC 0x0c09da38 */
if(!s->budget--) { s->failed_pc=0x0c09da38u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da3a;
P_0c09da3a: /* original 854f, guest PC 0x0c09da3a */
if(!s->budget--) { s->failed_pc=0x0c09da3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c09da3c;
P_0c09da3c: /* original 430b, guest PC 0x0c09da3c */
if(!s->budget--) { s->failed_pc=0x0c09da3cu; return 0; }
target=r[3];
r[16]=0x0c09da40u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da40u) { target=s->pc; goto dispatch; }
goto P_0c09da40;
P_0c09da3e: /* original 6403, guest PC 0x0c09da3e */
if(!s->budget--) { s->failed_pc=0x0c09da3eu; return 0; }
r[4]=r[0];
goto P_0c09da40;
P_0c09da40: /* original d227, guest PC 0x0c09da40 */
if(!s->budget--) { s->failed_pc=0x0c09da40u; return 0; }
r[2]=read(ram,0x0c09dae0u,4);
goto P_0c09da42;
P_0c09da42: /* original 64e1, guest PC 0x0c09da42 */
if(!s->budget--) { s->failed_pc=0x0c09da42u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c09da44;
P_0c09da44: /* original 420b, guest PC 0x0c09da44 */
if(!s->budget--) { s->failed_pc=0x0c09da44u; return 0; }
target=r[2];
r[16]=0x0c09da48u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da48u) { target=s->pc; goto dispatch; }
goto P_0c09da48;
P_0c09da46: /* original 644d, guest PC 0x0c09da46 */
if(!s->budget--) { s->failed_pc=0x0c09da46u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09da48;
P_0c09da48: /* original d324, guest PC 0x0c09da48 */
if(!s->budget--) { s->failed_pc=0x0c09da48u; return 0; }
r[3]=read(ram,0x0c09dadcu,4);
goto P_0c09da4a;
P_0c09da4a: /* original 85e1, guest PC 0x0c09da4a */
if(!s->budget--) { s->failed_pc=0x0c09da4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c09da4c;
P_0c09da4c: /* original 430b, guest PC 0x0c09da4c */
if(!s->budget--) { s->failed_pc=0x0c09da4cu; return 0; }
target=r[3];
r[16]=0x0c09da50u;
r[4]=r[0]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da50u) { target=s->pc; goto dispatch; }
goto P_0c09da50;
P_0c09da4e: /* original 640d, guest PC 0x0c09da4e */
if(!s->budget--) { s->failed_pc=0x0c09da4eu; return 0; }
r[4]=r[0]&65535u;
goto P_0c09da50;
P_0c09da50: /* original 64f2, guest PC 0x0c09da50 */
if(!s->budget--) { s->failed_pc=0x0c09da50u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09da52;
P_0c09da52: /* original 923e, guest PC 0x0c09da52 */
if(!s->budget--) { s->failed_pc=0x0c09da52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dad2u,2);
goto P_0c09da54;
P_0c09da54: /* original 85e2, guest PC 0x0c09da54 */
if(!s->budget--) { s->failed_pc=0x0c09da54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c09da56;
P_0c09da56: /* original 324c, guest PC 0x0c09da56 */
if(!s->budget--) { s->failed_pc=0x0c09da56u; return 0; }
r[2]+=r[4];
goto P_0c09da58;
P_0c09da58: /* original d322, guest PC 0x0c09da58 */
if(!s->budget--) { s->failed_pc=0x0c09da58u; return 0; }
r[3]=read(ram,0x0c09dae4u,4);
goto P_0c09da5a;
P_0c09da5a: /* original 6421, guest PC 0x0c09da5a */
if(!s->budget--) { s->failed_pc=0x0c09da5au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[4]=tmp;
goto P_0c09da5c;
P_0c09da5c: /* original 600d, guest PC 0x0c09da5c */
if(!s->budget--) { s->failed_pc=0x0c09da5cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c09da5e;
P_0c09da5e: /* original 430b, guest PC 0x0c09da5e */
if(!s->budget--) { s->failed_pc=0x0c09da5eu; return 0; }
target=r[3];
r[16]=0x0c09da62u;
r[4]+=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da62u) { target=s->pc; goto dispatch; }
goto P_0c09da62;
P_0c09da60: /* original 340c, guest PC 0x0c09da60 */
if(!s->budget--) { s->failed_pc=0x0c09da60u; return 0; }
r[4]+=r[0];
goto P_0c09da62;
P_0c09da62: /* original d222, guest PC 0x0c09da62 */
if(!s->budget--) { s->failed_pc=0x0c09da62u; return 0; }
r[2]=read(ram,0x0c09daecu,4);
goto P_0c09da64;
P_0c09da64: /* original 64f3, guest PC 0x0c09da64 */
if(!s->budget--) { s->failed_pc=0x0c09da64u; return 0; }
r[4]=r[15];
goto P_0c09da66;
P_0c09da66: /* original 420b, guest PC 0x0c09da66 */
if(!s->budget--) { s->failed_pc=0x0c09da66u; return 0; }
target=r[2];
r[16]=0x0c09da6au;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09da6au) { target=s->pc; goto dispatch; }
goto P_0c09da6a;
P_0c09da68: /* original 7404, guest PC 0x0c09da68 */
if(!s->budget--) { s->failed_pc=0x0c09da68u; return 0; }
r[4]+=0x00000004u;
goto P_0c09da6a;
P_0c09da6a: /* original 7f10, guest PC 0x0c09da6a */
if(!s->budget--) { s->failed_pc=0x0c09da6au; return 0; }
r[15]+=0x00000010u;
goto P_0c09da6c;
P_0c09da6c: /* original 4f26, guest PC 0x0c09da6c */
if(!s->budget--) { s->failed_pc=0x0c09da6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09da6e;
P_0c09da6e: /* original 000b, guest PC 0x0c09da6e */
if(!s->budget--) { s->failed_pc=0x0c09da6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09da70: /* original 6ef6, guest PC 0x0c09da70 */
if(!s->budget--) { s->failed_pc=0x0c09da70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09da72u,s,ram);
P_0c09dbc0: /* original 4f22, guest PC 0x0c09dbc0 */
if(!s->budget--) { s->failed_pc=0x0c09dbc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09dbc2;
P_0c09dbc2: /* original 7fb8, guest PC 0x0c09dbc2 */
if(!s->budget--) { s->failed_pc=0x0c09dbc2u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c09dbc4;
P_0c09dbc4: /* original 2f42, guest PC 0x0c09dbc4 */
if(!s->budget--) { s->failed_pc=0x0c09dbc4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09dbc6;
P_0c09dbc6: /* original 1f51, guest PC 0x0c09dbc6 */
if(!s->budget--) { s->failed_pc=0x0c09dbc6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09dbc8;
P_0c09dbc8: /* original d30e, guest PC 0x0c09dbc8 */
if(!s->budget--) { s->failed_pc=0x0c09dbc8u; return 0; }
r[3]=read(ram,0x0c09dc04u,4);
goto P_0c09dbca;
P_0c09dbca: /* original 430b, guest PC 0x0c09dbca */
if(!s->budget--) { s->failed_pc=0x0c09dbcau; return 0; }
target=r[3];
r[16]=0x0c09dbceu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09dbceu) { target=s->pc; goto dispatch; }
goto P_0c09dbce;
P_0c09dbcc: /* original e400, guest PC 0x0c09dbcc */
if(!s->budget--) { s->failed_pc=0x0c09dbccu; return 0; }
r[4]=0x00000000u;
goto P_0c09dbce;
P_0c09dbce: /* original d218, guest PC 0x0c09dbce */
if(!s->budget--) { s->failed_pc=0x0c09dbceu; return 0; }
r[2]=read(ram,0x0c09dc30u,4);
goto P_0c09dbd0;
P_0c09dbd0: /* original 420b, guest PC 0x0c09dbd0 */
if(!s->budget--) { s->failed_pc=0x0c09dbd0u; return 0; }
target=r[2];
r[16]=0x0c09dbd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09dbd4u) { target=s->pc; goto dispatch; }
goto P_0c09dbd4;
P_0c09dbd2: /* original 0009, guest PC 0x0c09dbd2 */
if(!s->budget--) { s->failed_pc=0x0c09dbd2u; return 0; }
goto P_0c09dbd4;
P_0c09dbd4: /* original d314, guest PC 0x0c09dbd4 */
if(!s->budget--) { s->failed_pc=0x0c09dbd4u; return 0; }
r[3]=read(ram,0x0c09dc28u,4);
goto P_0c09dbd6;
P_0c09dbd6: /* original 55f1, guest PC 0x0c09dbd6 */
if(!s->budget--) { s->failed_pc=0x0c09dbd6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09dbd8;
P_0c09dbd8: /* original 430b, guest PC 0x0c09dbd8 */
if(!s->budget--) { s->failed_pc=0x0c09dbd8u; return 0; }
target=r[3];
r[16]=0x0c09dbdcu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09dbdcu) { target=s->pc; goto dispatch; }
goto P_0c09dbdc;
P_0c09dbda: /* original 64f2, guest PC 0x0c09dbda */
if(!s->budget--) { s->failed_pc=0x0c09dbdau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09dbdc;
P_0c09dbdc: /* original d213, guest PC 0x0c09dbdc */
if(!s->budget--) { s->failed_pc=0x0c09dbdcu; return 0; }
r[2]=read(ram,0x0c09dc2cu,4);
goto P_0c09dbde;
P_0c09dbde: /* original 7f48, guest PC 0x0c09dbde */
if(!s->budget--) { s->failed_pc=0x0c09dbdeu; return 0; }
r[15]+=0x00000048u;
goto P_0c09dbe0;
P_0c09dbe0: /* original e401, guest PC 0x0c09dbe0 */
if(!s->budget--) { s->failed_pc=0x0c09dbe0u; return 0; }
r[4]=0x00000001u;
goto P_0c09dbe2;
P_0c09dbe2: /* original 422b, guest PC 0x0c09dbe2 */
if(!s->budget--) { s->failed_pc=0x0c09dbe2u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09dbe4: /* original 4f26, guest PC 0x0c09dbe4 */
if(!s->budget--) { s->failed_pc=0x0c09dbe4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c09dbe6u,s,ram);
P_0c09ee18: /* original 2fe6, guest PC 0x0c09ee18 */
if(!s->budget--) { s->failed_pc=0x0c09ee18u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c09ee1a;
P_0c09ee1a: /* original 6e43, guest PC 0x0c09ee1a */
if(!s->budget--) { s->failed_pc=0x0c09ee1au; return 0; }
r[14]=r[4];
goto P_0c09ee1c;
P_0c09ee1c: /* original 2fd6, guest PC 0x0c09ee1c */
if(!s->budget--) { s->failed_pc=0x0c09ee1cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c09ee1e;
P_0c09ee1e: /* original e210, guest PC 0x0c09ee1e */
if(!s->budget--) { s->failed_pc=0x0c09ee1eu; return 0; }
r[2]=0x00000010u;
goto P_0c09ee20;
P_0c09ee20: /* original 2fc6, guest PC 0x0c09ee20 */
if(!s->budget--) { s->failed_pc=0x0c09ee20u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c09ee22;
P_0c09ee22: /* original 6c53, guest PC 0x0c09ee22 */
if(!s->budget--) { s->failed_pc=0x0c09ee22u; return 0; }
r[12]=r[5];
goto P_0c09ee24;
P_0c09ee24: /* original 2fb6, guest PC 0x0c09ee24 */
if(!s->budget--) { s->failed_pc=0x0c09ee24u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c09ee26;
P_0c09ee26: /* original 4f22, guest PC 0x0c09ee26 */
if(!s->budget--) { s->failed_pc=0x0c09ee26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ee28;
P_0c09ee28: /* original 9380, guest PC 0x0c09ee28 */
if(!s->budget--) { s->failed_pc=0x0c09ee28u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee2a;
P_0c09ee2a: /* original 33ec, guest PC 0x0c09ee2a */
if(!s->budget--) { s->failed_pc=0x0c09ee2au; return 0; }
r[3]+=r[14];
goto P_0c09ee2c;
P_0c09ee2c: /* original 7ff0, guest PC 0x0c09ee2c */
if(!s->budget--) { s->failed_pc=0x0c09ee2cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09ee2e;
P_0c09ee2e: /* original 2f32, guest PC 0x0c09ee2e */
if(!s->budget--) { s->failed_pc=0x0c09ee2eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee30;
P_0c09ee30: /* original 907d, guest PC 0x0c09ee30 */
if(!s->budget--) { s->failed_pc=0x0c09ee30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee32;
P_0c09ee32: /* original 937b, guest PC 0x0c09ee32 */
if(!s->budget--) { s->failed_pc=0x0c09ee32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee34;
P_0c09ee34: /* original 0bec, guest PC 0x0c09ee34 */
if(!s->budget--) { s->failed_pc=0x0c09ee34u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee36;
P_0c09ee36: /* original 33ec, guest PC 0x0c09ee36 */
if(!s->budget--) { s->failed_pc=0x0c09ee36u; return 0; }
r[3]+=r[14];
goto P_0c09ee38;
P_0c09ee38: /* original 6bbc, guest PC 0x0c09ee38 */
if(!s->budget--) { s->failed_pc=0x0c09ee38u; return 0; }
r[11]=r[11]&255u;
goto P_0c09ee3a;
P_0c09ee3a: /* original 6db3, guest PC 0x0c09ee3a */
if(!s->budget--) { s->failed_pc=0x0c09ee3au; return 0; }
r[13]=r[11];
goto P_0c09ee3c;
P_0c09ee3c: /* original 22d8, guest PC 0x0c09ee3c */
if(!s->budget--) { s->failed_pc=0x0c09ee3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09ee3e;
P_0c09ee3e: /* original 8f02, guest PC 0x0c09ee3e */
if(!s->budget--) { s->failed_pc=0x0c09ee3eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c09ee46; }
goto P_0c09ee42;
P_0c09ee40: /* original 2f32, guest PC 0x0c09ee40 */
if(!s->budget--) { s->failed_pc=0x0c09ee40u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee42;
P_0c09ee42: /* original a099, guest PC 0x0c09ee42 */
if(!s->budget--) { s->failed_pc=0x0c09ee42u; return 0; }
goto P_0c09ef78;
P_0c09ee44: /* original 0009, guest PC 0x0c09ee44 */
if(!s->budget--) { s->failed_pc=0x0c09ee44u; return 0; }
goto P_0c09ee46;
P_0c09ee46: /* original 9373, guest PC 0x0c09ee46 */
if(!s->budget--) { s->failed_pc=0x0c09ee46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef30u,2);
goto P_0c09ee48;
P_0c09ee48: /* original 9071, guest PC 0x0c09ee48 */
if(!s->budget--) { s->failed_pc=0x0c09ee48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee4a;
P_0c09ee4a: /* original 2b39, guest PC 0x0c09ee4a */
if(!s->budget--) { s->failed_pc=0x0c09ee4au; return 0; }
r[11]&=r[3];
goto P_0c09ee4c;
P_0c09ee4c: /* original 0eb4, guest PC 0x0c09ee4c */
if(!s->budget--) { s->failed_pc=0x0c09ee4cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09ee4e;
P_0c09ee4e: /* original 956d, guest PC 0x0c09ee4e */
if(!s->budget--) { s->failed_pc=0x0c09ee4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee50;
P_0c09ee50: /* original d23b, guest PC 0x0c09ee50 */
if(!s->budget--) { s->failed_pc=0x0c09ee50u; return 0; }
r[2]=read(ram,0x0c09ef40u,4);
goto P_0c09ee52;
P_0c09ee52: /* original 35ec, guest PC 0x0c09ee52 */
if(!s->budget--) { s->failed_pc=0x0c09ee52u; return 0; }
r[5]+=r[14];
goto P_0c09ee54;
P_0c09ee54: /* original 420b, guest PC 0x0c09ee54 */
if(!s->budget--) { s->failed_pc=0x0c09ee54u; return 0; }
target=r[2];
r[16]=0x0c09ee58u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ee58u) { target=s->pc; goto dispatch; }
goto P_0c09ee58;
P_0c09ee56: /* original 64e3, guest PC 0x0c09ee56 */
if(!s->budget--) { s->failed_pc=0x0c09ee56u; return 0; }
r[4]=r[14];
goto P_0c09ee58;
P_0c09ee58: /* original d33a, guest PC 0x0c09ee58 */
if(!s->budget--) { s->failed_pc=0x0c09ee58u; return 0; }
r[3]=read(ram,0x0c09ef44u,4);
goto P_0c09ee5a;
P_0c09ee5a: /* original 65f3, guest PC 0x0c09ee5a */
if(!s->budget--) { s->failed_pc=0x0c09ee5au; return 0; }
r[5]=r[15];
goto P_0c09ee5c;
P_0c09ee5c: /* original 66c3, guest PC 0x0c09ee5c */
if(!s->budget--) { s->failed_pc=0x0c09ee5cu; return 0; }
r[6]=r[12];
goto P_0c09ee5e;
P_0c09ee5e: /* original 430b, guest PC 0x0c09ee5e */
if(!s->budget--) { s->failed_pc=0x0c09ee5eu; return 0; }
target=r[3];
r[16]=0x0c09ee62u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ee62u) { target=s->pc; goto dispatch; }
goto P_0c09ee62;
P_0c09ee60: /* original 64e3, guest PC 0x0c09ee60 */
if(!s->budget--) { s->failed_pc=0x0c09ee60u; return 0; }
r[4]=r[14];
goto P_0c09ee62;
P_0c09ee62: /* original d239, guest PC 0x0c09ee62 */
if(!s->budget--) { s->failed_pc=0x0c09ee62u; return 0; }
r[2]=read(ram,0x0c09ef48u,4);
goto P_0c09ee64;
P_0c09ee64: /* original 420b, guest PC 0x0c09ee64 */
if(!s->budget--) { s->failed_pc=0x0c09ee64u; return 0; }
target=r[2];
r[16]=0x0c09ee68u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ee68u) { target=s->pc; goto dispatch; }
goto P_0c09ee68;
P_0c09ee66: /* original 64e3, guest PC 0x0c09ee66 */
if(!s->budget--) { s->failed_pc=0x0c09ee66u; return 0; }
r[4]=r[14];
goto P_0c09ee68;
P_0c09ee68: /* original 62e2, guest PC 0x0c09ee68 */
if(!s->budget--) { s->failed_pc=0x0c09ee68u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09ee6a;
P_0c09ee6a: /* original d338, guest PC 0x0c09ee6a */
if(!s->budget--) { s->failed_pc=0x0c09ee6au; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09ee6c;
P_0c09ee6c: /* original 2238, guest PC 0x0c09ee6c */
if(!s->budget--) { s->failed_pc=0x0c09ee6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09ee6e;
P_0c09ee6e: /* original 8909, guest PC 0x0c09ee6e */
if(!s->budget--) { s->failed_pc=0x0c09ee6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ee84; }
goto P_0c09ee70;
P_0c09ee70: /* original 905d, guest PC 0x0c09ee70 */
if(!s->budget--) { s->failed_pc=0x0c09ee70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee72;
P_0c09ee72: /* original 6db3, guest PC 0x0c09ee72 */
if(!s->budget--) { s->failed_pc=0x0c09ee72u; return 0; }
r[13]=r[11];
goto P_0c09ee74;
P_0c09ee74: /* original 935d, guest PC 0x0c09ee74 */
if(!s->budget--) { s->failed_pc=0x0c09ee74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef32u,2);
goto P_0c09ee76;
P_0c09ee76: /* original 02ec, guest PC 0x0c09ee76 */
if(!s->budget--) { s->failed_pc=0x0c09ee76u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee78;
P_0c09ee78: /* original 223b, guest PC 0x0c09ee78 */
if(!s->budget--) { s->failed_pc=0x0c09ee78u; return 0; }
r[2]|=r[3];
goto P_0c09ee7a;
P_0c09ee7a: /* original 0e24, guest PC 0x0c09ee7a */
if(!s->budget--) { s->failed_pc=0x0c09ee7au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ee7c;
P_0c09ee7c: /* original 9456, guest PC 0x0c09ee7c */
if(!s->budget--) { s->failed_pc=0x0c09ee7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee7e;
P_0c09ee7e: /* original d134, guest PC 0x0c09ee7e */
if(!s->budget--) { s->failed_pc=0x0c09ee7eu; return 0; }
r[1]=read(ram,0x0c09ef50u,4);
goto P_0c09ee80;
P_0c09ee80: /* original 410b, guest PC 0x0c09ee80 */
if(!s->budget--) { s->failed_pc=0x0c09ee80u; return 0; }
target=r[1];
r[16]=0x0c09ee84u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ee84u) { target=s->pc; goto dispatch; }
goto P_0c09ee84;
P_0c09ee82: /* original 34ec, guest PC 0x0c09ee82 */
if(!s->budget--) { s->failed_pc=0x0c09ee82u; return 0; }
r[4]+=r[14];
goto P_0c09ee84;
P_0c09ee84: /* original 9053, guest PC 0x0c09ee84 */
if(!s->budget--) { s->failed_pc=0x0c09ee84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee86;
P_0c09ee86: /* original 00ec, guest PC 0x0c09ee86 */
if(!s->budget--) { s->failed_pc=0x0c09ee86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee88;
P_0c09ee88: /* original 600c, guest PC 0x0c09ee88 */
if(!s->budget--) { s->failed_pc=0x0c09ee88u; return 0; }
r[0]=r[0]&255u;
goto P_0c09ee8a;
P_0c09ee8a: /* original c820, guest PC 0x0c09ee8a */
if(!s->budget--) { s->failed_pc=0x0c09ee8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09ee8c;
P_0c09ee8c: /* original 891f, guest PC 0x0c09ee8c */
if(!s->budget--) { s->failed_pc=0x0c09ee8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eece; }
goto P_0c09ee8e;
P_0c09ee8e: /* original 9051, guest PC 0x0c09ee8e */
if(!s->budget--) { s->failed_pc=0x0c09ee8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09ee90;
P_0c09ee90: /* original 04ed, guest PC 0x0c09ee90 */
if(!s->budget--) { s->failed_pc=0x0c09ee90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ee92;
P_0c09ee92: /* original e008, guest PC 0x0c09ee92 */
if(!s->budget--) { s->failed_pc=0x0c09ee92u; return 0; }
r[0]=0x00000008u;
goto P_0c09ee94;
P_0c09ee94: /* original 6b4b, guest PC 0x0c09ee94 */
if(!s->budget--) { s->failed_pc=0x0c09ee94u; return 0; }
r[11]=0u-r[4];
goto P_0c09ee96;
P_0c09ee96: /* original 4b5a, guest PC 0x0c09ee96 */
if(!s->budget--) { s->failed_pc=0x0c09ee96u; return 0; }
r[53]=r[11];
goto P_0c09ee98;
P_0c09ee98: /* original 64bf, guest PC 0x0c09ee98 */
if(!s->budget--) { s->failed_pc=0x0c09ee98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09ee9a;
P_0c09ee9a: /* original f32d, guest PC 0x0c09ee9a */
if(!s->budget--) { s->failed_pc=0x0c09ee9au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09ee9c;
P_0c09ee9c: /* original ff37, guest PC 0x0c09ee9c */
if(!s->budget--) { s->failed_pc=0x0c09ee9cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ee9e;
P_0c09ee9e: /* original d32d, guest PC 0x0c09ee9e */
if(!s->budget--) { s->failed_pc=0x0c09ee9eu; return 0; }
r[3]=read(ram,0x0c09ef54u,4);
goto P_0c09eea0;
P_0c09eea0: /* original 430b, guest PC 0x0c09eea0 */
if(!s->budget--) { s->failed_pc=0x0c09eea0u; return 0; }
target=r[3];
r[16]=0x0c09eea4u;
write(ram,r[15]+4,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09eea4u) { target=s->pc; goto dispatch; }
goto P_0c09eea4;
P_0c09eea2: /* original 1f41, guest PC 0x0c09eea2 */
if(!s->budget--) { s->failed_pc=0x0c09eea2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c09eea4;
P_0c09eea4: /* original e00c, guest PC 0x0c09eea4 */
if(!s->budget--) { s->failed_pc=0x0c09eea4u; return 0; }
r[0]=0x0000000cu;
goto P_0c09eea6;
P_0c09eea6: /* original ff07, guest PC 0x0c09eea6 */
if(!s->budget--) { s->failed_pc=0x0c09eea6u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c09eea8;
P_0c09eea8: /* original d32b, guest PC 0x0c09eea8 */
if(!s->budget--) { s->failed_pc=0x0c09eea8u; return 0; }
r[3]=read(ram,0x0c09ef58u,4);
goto P_0c09eeaa;
P_0c09eeaa: /* original 430b, guest PC 0x0c09eeaa */
if(!s->budget--) { s->failed_pc=0x0c09eeaau; return 0; }
target=r[3];
r[16]=0x0c09eeaeu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09eeaeu) { target=s->pc; goto dispatch; }
goto P_0c09eeae;
P_0c09eeac: /* original 54f1, guest PC 0x0c09eeac */
if(!s->budget--) { s->failed_pc=0x0c09eeacu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09eeae;
P_0c09eeae: /* original e00c, guest PC 0x0c09eeae */
if(!s->budget--) { s->failed_pc=0x0c09eeaeu; return 0; }
r[0]=0x0000000cu;
goto P_0c09eeb0;
P_0c09eeb0: /* original f39d, guest PC 0x0c09eeb0 */
if(!s->budget--) { s->failed_pc=0x0c09eeb0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c09eeb2;
P_0c09eeb2: /* original f2f6, guest PC 0x0c09eeb2 */
if(!s->budget--) { s->failed_pc=0x0c09eeb2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09eeb4;
P_0c09eeb4: /* original e008, guest PC 0x0c09eeb4 */
if(!s->budget--) { s->failed_pc=0x0c09eeb4u; return 0; }
r[0]=0x00000008u;
goto P_0c09eeb6;
P_0c09eeb6: /* original f6f6, guest PC 0x0c09eeb6 */
if(!s->budget--) { s->failed_pc=0x0c09eeb6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09eeb8;
P_0c09eeb8: /* original f232, guest PC 0x0c09eeb8 */
if(!s->budget--) { s->failed_pc=0x0c09eeb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09eeba;
P_0c09eeba: /* original d328, guest PC 0x0c09eeba */
if(!s->budget--) { s->failed_pc=0x0c09eebau; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eebc;
P_0c09eebc: /* original 943b, guest PC 0x0c09eebc */
if(!s->budget--) { s->failed_pc=0x0c09eebcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eebe;
P_0c09eebe: /* original f50c, guest PC 0x0c09eebe */
if(!s->budget--) { s->failed_pc=0x0c09eebeu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c09eec0;
P_0c09eec0: /* original f42c, guest PC 0x0c09eec0 */
if(!s->budget--) { s->failed_pc=0x0c09eec0u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c09eec2;
P_0c09eec2: /* original f44d, guest PC 0x0c09eec2 */
if(!s->budget--) { s->failed_pc=0x0c09eec2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09eec4;
P_0c09eec4: /* original 430b, guest PC 0x0c09eec4 */
if(!s->budget--) { s->failed_pc=0x0c09eec4u; return 0; }
target=r[3];
r[16]=0x0c09eec8u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09eec8u) { target=s->pc; goto dispatch; }
goto P_0c09eec8;
P_0c09eec6: /* original 34ec, guest PC 0x0c09eec6 */
if(!s->budget--) { s->failed_pc=0x0c09eec6u; return 0; }
r[4]+=r[14];
goto P_0c09eec8;
P_0c09eec8: /* original d225, guest PC 0x0c09eec8 */
if(!s->budget--) { s->failed_pc=0x0c09eec8u; return 0; }
r[2]=read(ram,0x0c09ef60u,4);
goto P_0c09eeca;
P_0c09eeca: /* original 420b, guest PC 0x0c09eeca */
if(!s->budget--) { s->failed_pc=0x0c09eecau; return 0; }
target=r[2];
r[16]=0x0c09eeceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09eeceu) { target=s->pc; goto dispatch; }
goto P_0c09eece;
P_0c09eecc: /* original 64e3, guest PC 0x0c09eecc */
if(!s->budget--) { s->failed_pc=0x0c09eeccu; return 0; }
r[4]=r[14];
goto P_0c09eece;
P_0c09eece: /* original e048, guest PC 0x0c09eece */
if(!s->budget--) { s->failed_pc=0x0c09eeceu; return 0; }
r[0]=0x00000048u;
goto P_0c09eed0;
P_0c09eed0: /* original 9332, guest PC 0x0c09eed0 */
if(!s->budget--) { s->failed_pc=0x0c09eed0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef38u,2);
goto P_0c09eed2;
P_0c09eed2: /* original 02ee, guest PC 0x0c09eed2 */
if(!s->budget--) { s->failed_pc=0x0c09eed2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eed4;
P_0c09eed4: /* original 2238, guest PC 0x0c09eed4 */
if(!s->budget--) { s->failed_pc=0x0c09eed4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eed6;
P_0c09eed6: /* original 8908, guest PC 0x0c09eed6 */
if(!s->budget--) { s->failed_pc=0x0c09eed6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eeea; }
goto P_0c09eed8;
P_0c09eed8: /* original c722, guest PC 0x0c09eed8 */
if(!s->budget--) { s->failed_pc=0x0c09eed8u; return 0; }
r[0]=0x0c09ef64u;
goto P_0c09eeda;
P_0c09eeda: /* original 942c, guest PC 0x0c09eeda */
if(!s->budget--) { s->failed_pc=0x0c09eedau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eedc;
P_0c09eedc: /* original f508, guest PC 0x0c09eedc */
if(!s->budget--) { s->failed_pc=0x0c09eedcu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09eede;
P_0c09eede: /* original c722, guest PC 0x0c09eede */
if(!s->budget--) { s->failed_pc=0x0c09eedeu; return 0; }
r[0]=0x0c09ef68u;
goto P_0c09eee0;
P_0c09eee0: /* original d31e, guest PC 0x0c09eee0 */
if(!s->budget--) { s->failed_pc=0x0c09eee0u; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eee2;
P_0c09eee2: /* original f608, guest PC 0x0c09eee2 */
if(!s->budget--) { s->failed_pc=0x0c09eee2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c09eee4;
P_0c09eee4: /* original f48d, guest PC 0x0c09eee4 */
if(!s->budget--) { s->failed_pc=0x0c09eee4u; return 0; }
fr[4]=0;
goto P_0c09eee6;
P_0c09eee6: /* original 430b, guest PC 0x0c09eee6 */
if(!s->budget--) { s->failed_pc=0x0c09eee6u; return 0; }
target=r[3];
r[16]=0x0c09eeeau;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09eeeau) { target=s->pc; goto dispatch; }
goto P_0c09eeea;
P_0c09eee8: /* original 34ec, guest PC 0x0c09eee8 */
if(!s->budget--) { s->failed_pc=0x0c09eee8u; return 0; }
r[4]+=r[14];
goto P_0c09eeea;
P_0c09eeea: /* original 9026, guest PC 0x0c09eeea */
if(!s->budget--) { s->failed_pc=0x0c09eeeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3au,2);
goto P_0c09eeec;
P_0c09eeec: /* original d317, guest PC 0x0c09eeec */
if(!s->budget--) { s->failed_pc=0x0c09eeecu; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09eeee;
P_0c09eeee: /* original 02ee, guest PC 0x0c09eeee */
if(!s->budget--) { s->failed_pc=0x0c09eeeeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eef0;
P_0c09eef0: /* original 2238, guest PC 0x0c09eef0 */
if(!s->budget--) { s->failed_pc=0x0c09eef0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eef2;
P_0c09eef2: /* original 8908, guest PC 0x0c09eef2 */
if(!s->budget--) { s->failed_pc=0x0c09eef2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef06; }
goto P_0c09eef4;
P_0c09eef4: /* original 9022, guest PC 0x0c09eef4 */
if(!s->budget--) { s->failed_pc=0x0c09eef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3cu,2);
goto P_0c09eef6;
P_0c09eef6: /* original e340, guest PC 0x0c09eef6 */
if(!s->budget--) { s->failed_pc=0x0c09eef6u; return 0; }
r[3]=0x00000040u;
goto P_0c09eef8;
P_0c09eef8: /* original 01ed, guest PC 0x0c09eef8 */
if(!s->budget--) { s->failed_pc=0x0c09eef8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09eefa;
P_0c09eefa: /* original 901b, guest PC 0x0c09eefa */
if(!s->budget--) { s->failed_pc=0x0c09eefau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09eefc;
P_0c09eefc: /* original 0e15, guest PC 0x0c09eefc */
if(!s->budget--) { s->failed_pc=0x0c09eefcu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c09eefe;
P_0c09eefe: /* original 70df, guest PC 0x0c09eefe */
if(!s->budget--) { s->failed_pc=0x0c09eefeu; return 0; }
r[0]+=0xffffffdfu;
goto P_0c09ef00;
P_0c09ef00: /* original 02ec, guest PC 0x0c09ef00 */
if(!s->budget--) { s->failed_pc=0x0c09ef00u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ef02;
P_0c09ef02: /* original 223b, guest PC 0x0c09ef02 */
if(!s->budget--) { s->failed_pc=0x0c09ef02u; return 0; }
r[2]|=r[3];
goto P_0c09ef04;
P_0c09ef04: /* original 0e24, guest PC 0x0c09ef04 */
if(!s->budget--) { s->failed_pc=0x0c09ef04u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ef06;
P_0c09ef06: /* original 9516, guest PC 0x0c09ef06 */
if(!s->budget--) { s->failed_pc=0x0c09ef06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef08;
P_0c09ef08: /* original 9410, guest PC 0x0c09ef08 */
if(!s->budget--) { s->failed_pc=0x0c09ef08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef0a;
P_0c09ef0a: /* original d318, guest PC 0x0c09ef0a */
if(!s->budget--) { s->failed_pc=0x0c09ef0au; return 0; }
r[3]=read(ram,0x0c09ef6cu,4);
goto P_0c09ef0c;
P_0c09ef0c: /* original 35ec, guest PC 0x0c09ef0c */
if(!s->budget--) { s->failed_pc=0x0c09ef0cu; return 0; }
r[5]+=r[14];
goto P_0c09ef0e;
P_0c09ef0e: /* original 430b, guest PC 0x0c09ef0e */
if(!s->budget--) { s->failed_pc=0x0c09ef0eu; return 0; }
target=r[3];
r[16]=0x0c09ef12u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef12u) { target=s->pc; goto dispatch; }
goto P_0c09ef12;
P_0c09ef10: /* original 34ec, guest PC 0x0c09ef10 */
if(!s->budget--) { s->failed_pc=0x0c09ef10u; return 0; }
r[4]+=r[14];
goto P_0c09ef12;
P_0c09ef12: /* original 950b, guest PC 0x0c09ef12 */
if(!s->budget--) { s->failed_pc=0x0c09ef12u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef14;
P_0c09ef14: /* original 960f, guest PC 0x0c09ef14 */
if(!s->budget--) { s->failed_pc=0x0c09ef14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef16;
P_0c09ef16: /* original d216, guest PC 0x0c09ef16 */
if(!s->budget--) { s->failed_pc=0x0c09ef16u; return 0; }
r[2]=read(ram,0x0c09ef70u,4);
goto P_0c09ef18;
P_0c09ef18: /* original 35ec, guest PC 0x0c09ef18 */
if(!s->budget--) { s->failed_pc=0x0c09ef18u; return 0; }
r[5]+=r[14];
goto P_0c09ef1a;
P_0c09ef1a: /* original 36ec, guest PC 0x0c09ef1a */
if(!s->budget--) { s->failed_pc=0x0c09ef1au; return 0; }
r[6]+=r[14];
goto P_0c09ef1c;
P_0c09ef1c: /* original 420b, guest PC 0x0c09ef1c */
if(!s->budget--) { s->failed_pc=0x0c09ef1cu; return 0; }
target=r[2];
r[16]=0x0c09ef20u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef20u) { target=s->pc; goto dispatch; }
goto P_0c09ef20;
P_0c09ef1e: /* original 64e3, guest PC 0x0c09ef1e */
if(!s->budget--) { s->failed_pc=0x0c09ef1eu; return 0; }
r[4]=r[14];
goto P_0c09ef20;
P_0c09ef20: /* original d314, guest PC 0x0c09ef20 */
if(!s->budget--) { s->failed_pc=0x0c09ef20u; return 0; }
r[3]=read(ram,0x0c09ef74u,4);
goto P_0c09ef22;
P_0c09ef22: /* original 430b, guest PC 0x0c09ef22 */
if(!s->budget--) { s->failed_pc=0x0c09ef22u; return 0; }
target=r[3];
r[16]=0x0c09ef26u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef26u) { target=s->pc; goto dispatch; }
goto P_0c09ef26;
P_0c09ef24: /* original 64e3, guest PC 0x0c09ef24 */
if(!s->budget--) { s->failed_pc=0x0c09ef24u; return 0; }
r[4]=r[14];
goto P_0c09ef26;
P_0c09ef26: /* original a03a, guest PC 0x0c09ef26 */
if(!s->budget--) { s->failed_pc=0x0c09ef26u; return 0; }
goto P_0c09ef9e;
P_0c09ef28: /* original 0009, guest PC 0x0c09ef28 */
if(!s->budget--) { s->failed_pc=0x0c09ef28u; return 0; }
return vf3_matrix_family(0x0c09ef2au,s,ram);
P_0c09ef78: /* original 9066, guest PC 0x0c09ef78 */
if(!s->budget--) { s->failed_pc=0x0c09ef78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f048u,2);
goto P_0c09ef7a;
P_0c09ef7a: /* original 65f3, guest PC 0x0c09ef7a */
if(!s->budget--) { s->failed_pc=0x0c09ef7au; return 0; }
r[5]=r[15];
goto P_0c09ef7c;
P_0c09ef7c: /* original 66c3, guest PC 0x0c09ef7c */
if(!s->budget--) { s->failed_pc=0x0c09ef7cu; return 0; }
r[6]=r[12];
goto P_0c09ef7e;
P_0c09ef7e: /* original 03ed, guest PC 0x0c09ef7e */
if(!s->budget--) { s->failed_pc=0x0c09ef7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ef80;
P_0c09ef80: /* original 9063, guest PC 0x0c09ef80 */
if(!s->budget--) { s->failed_pc=0x0c09ef80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04au,2);
goto P_0c09ef82;
P_0c09ef82: /* original 0e35, guest PC 0x0c09ef82 */
if(!s->budget--) { s->failed_pc=0x0c09ef82u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09ef84;
P_0c09ef84: /* original d334, guest PC 0x0c09ef84 */
if(!s->budget--) { s->failed_pc=0x0c09ef84u; return 0; }
r[3]=read(ram,0x0c09f058u,4);
goto P_0c09ef86;
P_0c09ef86: /* original 430b, guest PC 0x0c09ef86 */
if(!s->budget--) { s->failed_pc=0x0c09ef86u; return 0; }
target=r[3];
r[16]=0x0c09ef8au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef8au) { target=s->pc; goto dispatch; }
goto P_0c09ef8a;
P_0c09ef88: /* original 64e3, guest PC 0x0c09ef88 */
if(!s->budget--) { s->failed_pc=0x0c09ef88u; return 0; }
r[4]=r[14];
goto P_0c09ef8a;
P_0c09ef8a: /* original d234, guest PC 0x0c09ef8a */
if(!s->budget--) { s->failed_pc=0x0c09ef8au; return 0; }
r[2]=read(ram,0x0c09f05cu,4);
goto P_0c09ef8c;
P_0c09ef8c: /* original 420b, guest PC 0x0c09ef8c */
if(!s->budget--) { s->failed_pc=0x0c09ef8cu; return 0; }
target=r[2];
r[16]=0x0c09ef90u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef90u) { target=s->pc; goto dispatch; }
goto P_0c09ef90;
P_0c09ef8e: /* original 64e3, guest PC 0x0c09ef8e */
if(!s->budget--) { s->failed_pc=0x0c09ef8eu; return 0; }
r[4]=r[14];
goto P_0c09ef90;
P_0c09ef90: /* original 935c, guest PC 0x0c09ef90 */
if(!s->budget--) { s->failed_pc=0x0c09ef90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04cu,2);
goto P_0c09ef92;
P_0c09ef92: /* original 23d8, guest PC 0x0c09ef92 */
if(!s->budget--) { s->failed_pc=0x0c09ef92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ef94;
P_0c09ef94: /* original 8903, guest PC 0x0c09ef94 */
if(!s->budget--) { s->failed_pc=0x0c09ef94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef9e; }
goto P_0c09ef96;
P_0c09ef96: /* original d332, guest PC 0x0c09ef96 */
if(!s->budget--) { s->failed_pc=0x0c09ef96u; return 0; }
r[3]=read(ram,0x0c09f060u,4);
goto P_0c09ef98;
P_0c09ef98: /* original 9459, guest PC 0x0c09ef98 */
if(!s->budget--) { s->failed_pc=0x0c09ef98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04eu,2);
goto P_0c09ef9a;
P_0c09ef9a: /* original 430b, guest PC 0x0c09ef9a */
if(!s->budget--) { s->failed_pc=0x0c09ef9au; return 0; }
target=r[3];
r[16]=0x0c09ef9eu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ef9eu) { target=s->pc; goto dispatch; }
goto P_0c09ef9e;
P_0c09ef9c: /* original 34ec, guest PC 0x0c09ef9c */
if(!s->budget--) { s->failed_pc=0x0c09ef9cu; return 0; }
r[4]+=r[14];
goto P_0c09ef9e;
P_0c09ef9e: /* original e201, guest PC 0x0c09ef9e */
if(!s->budget--) { s->failed_pc=0x0c09ef9eu; return 0; }
r[2]=0x00000001u;
goto P_0c09efa0;
P_0c09efa0: /* original 22d8, guest PC 0x0c09efa0 */
if(!s->budget--) { s->failed_pc=0x0c09efa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09efa2;
P_0c09efa2: /* original 8902, guest PC 0x0c09efa2 */
if(!s->budget--) { s->failed_pc=0x0c09efa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efaa; }
goto P_0c09efa4;
P_0c09efa4: /* original d22f, guest PC 0x0c09efa4 */
if(!s->budget--) { s->failed_pc=0x0c09efa4u; return 0; }
r[2]=read(ram,0x0c09f064u,4);
goto P_0c09efa6;
P_0c09efa6: /* original 420b, guest PC 0x0c09efa6 */
if(!s->budget--) { s->failed_pc=0x0c09efa6u; return 0; }
target=r[2];
r[16]=0x0c09efaau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09efaau) { target=s->pc; goto dispatch; }
goto P_0c09efaa;
P_0c09efa8: /* original 64e3, guest PC 0x0c09efa8 */
if(!s->budget--) { s->failed_pc=0x0c09efa8u; return 0; }
r[4]=r[14];
goto P_0c09efaa;
P_0c09efaa: /* original e302, guest PC 0x0c09efaa */
if(!s->budget--) { s->failed_pc=0x0c09efaau; return 0; }
r[3]=0x00000002u;
goto P_0c09efac;
P_0c09efac: /* original 23d8, guest PC 0x0c09efac */
if(!s->budget--) { s->failed_pc=0x0c09efacu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09efae;
P_0c09efae: /* original 8904, guest PC 0x0c09efae */
if(!s->budget--) { s->failed_pc=0x0c09efaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efba; }
goto P_0c09efb0;
P_0c09efb0: /* original d32d, guest PC 0x0c09efb0 */
if(!s->budget--) { s->failed_pc=0x0c09efb0u; return 0; }
r[3]=read(ram,0x0c09f068u,4);
goto P_0c09efb2;
P_0c09efb2: /* original 65c3, guest PC 0x0c09efb2 */
if(!s->budget--) { s->failed_pc=0x0c09efb2u; return 0; }
r[5]=r[12];
goto P_0c09efb4;
P_0c09efb4: /* original 66d3, guest PC 0x0c09efb4 */
if(!s->budget--) { s->failed_pc=0x0c09efb4u; return 0; }
r[6]=r[13];
goto P_0c09efb6;
P_0c09efb6: /* original 430b, guest PC 0x0c09efb6 */
if(!s->budget--) { s->failed_pc=0x0c09efb6u; return 0; }
target=r[3];
r[16]=0x0c09efbau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09efbau) { target=s->pc; goto dispatch; }
goto P_0c09efba;
P_0c09efb8: /* original 64e3, guest PC 0x0c09efb8 */
if(!s->budget--) { s->failed_pc=0x0c09efb8u; return 0; }
r[4]=r[14];
goto P_0c09efba;
P_0c09efba: /* original d22c, guest PC 0x0c09efba */
if(!s->budget--) { s->failed_pc=0x0c09efbau; return 0; }
r[2]=read(ram,0x0c09f06cu,4);
goto P_0c09efbc;
P_0c09efbc: /* original 420b, guest PC 0x0c09efbc */
if(!s->budget--) { s->failed_pc=0x0c09efbcu; return 0; }
target=r[2];
r[16]=0x0c09efc0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09efc0u) { target=s->pc; goto dispatch; }
goto P_0c09efc0;
P_0c09efbe: /* original 64e3, guest PC 0x0c09efbe */
if(!s->budget--) { s->failed_pc=0x0c09efbeu; return 0; }
r[4]=r[14];
goto P_0c09efc0;
P_0c09efc0: /* original 7f10, guest PC 0x0c09efc0 */
if(!s->budget--) { s->failed_pc=0x0c09efc0u; return 0; }
r[15]+=0x00000010u;
goto P_0c09efc2;
P_0c09efc2: /* original 4f26, guest PC 0x0c09efc2 */
if(!s->budget--) { s->failed_pc=0x0c09efc2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09efc4;
P_0c09efc4: /* original 6bf6, guest PC 0x0c09efc4 */
if(!s->budget--) { s->failed_pc=0x0c09efc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09efc6;
P_0c09efc6: /* original 6cf6, guest PC 0x0c09efc6 */
if(!s->budget--) { s->failed_pc=0x0c09efc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09efc8;
P_0c09efc8: /* original 6df6, guest PC 0x0c09efc8 */
if(!s->budget--) { s->failed_pc=0x0c09efc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09efca;
P_0c09efca: /* original 000b, guest PC 0x0c09efca */
if(!s->budget--) { s->failed_pc=0x0c09efcau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09efcc: /* original 6ef6, guest PC 0x0c09efcc */
if(!s->budget--) { s->failed_pc=0x0c09efccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09efceu,s,ram);
P_0c09f036: /* original 4f22, guest PC 0x0c09f036 */
if(!s->budget--) { s->failed_pc=0x0c09f036u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f038;
P_0c09f038: /* original 7ffc, guest PC 0x0c09f038 */
if(!s->budget--) { s->failed_pc=0x0c09f038u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09f03a;
P_0c09f03a: /* original bfd4, guest PC 0x0c09f03a */
if(!s->budget--) { s->failed_pc=0x0c09f03au; return 0; }
target=0x0c09efe6u; r[16]=0x0c09f03eu;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09f03eu) { target=s->pc; goto dispatch; }
goto P_0c09f03e;
P_0c09f03c: /* original 2f42, guest PC 0x0c09f03c */
if(!s->budget--) { s->failed_pc=0x0c09f03cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09f03e;
P_0c09f03e: /* original 64f2, guest PC 0x0c09f03e */
if(!s->budget--) { s->failed_pc=0x0c09f03eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09f040;
P_0c09f040: /* original 7f04, guest PC 0x0c09f040 */
if(!s->budget--) { s->failed_pc=0x0c09f040u; return 0; }
r[15]+=0x00000004u;
goto P_0c09f042;
P_0c09f042: /* original 6503, guest PC 0x0c09f042 */
if(!s->budget--) { s->failed_pc=0x0c09f042u; return 0; }
r[5]=r[0];
goto P_0c09f044;
P_0c09f044: /* original aee8, guest PC 0x0c09f044 */
if(!s->budget--) { s->failed_pc=0x0c09f044u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ee18;
P_0c09f046: /* original 4f26, guest PC 0x0c09f046 */
if(!s->budget--) { s->failed_pc=0x0c09f046u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c09f048u,s,ram);
P_0c0a7390: /* original 4f22, guest PC 0x0c0a7390 */
if(!s->budget--) { s->failed_pc=0x0c0a7390u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7392;
P_0c0a7392: /* original 6652, guest PC 0x0c0a7392 */
if(!s->budget--) { s->failed_pc=0x0c0a7392u; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c0a7394;
P_0c0a7394: /* original 9419, guest PC 0x0c0a7394 */
if(!s->budget--) { s->failed_pc=0x0c0a7394u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73cau,2);
goto P_0c0a7396;
P_0c0a7396: /* original 2468, guest PC 0x0c0a7396 */
if(!s->budget--) { s->failed_pc=0x0c0a7396u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[6])==0)!=0);
goto P_0c0a7398;
P_0c0a7398: /* original 8904, guest PC 0x0c0a7398 */
if(!s->budget--) { s->failed_pc=0x0c0a7398u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a73a4; }
goto P_0c0a739a;
P_0c0a739a: /* original 8459, guest PC 0x0c0a739a */
if(!s->budget--) { s->failed_pc=0x0c0a739au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+9,1);
goto P_0c0a739c;
P_0c0a739c: /* original e520, guest PC 0x0c0a739c */
if(!s->budget--) { s->failed_pc=0x0c0a739cu; return 0; }
r[5]=0x00000020u;
goto P_0c0a739e;
P_0c0a739e: /* original 640c, guest PC 0x0c0a739e */
if(!s->budget--) { s->failed_pc=0x0c0a739eu; return 0; }
r[4]=r[0]&255u;
goto P_0c0a73a0;
P_0c0a73a0: /* original 3452, guest PC 0x0c0a73a0 */
if(!s->budget--) { s->failed_pc=0x0c0a73a0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c0a73a2;
P_0c0a73a2: /* original 8b0b, guest PC 0x0c0a73a2 */
if(!s->budget--) { s->failed_pc=0x0c0a73a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a73bc; }
goto P_0c0a73a4;
P_0c0a73a4: /* original d309, guest PC 0x0c0a73a4 */
if(!s->budget--) { s->failed_pc=0x0c0a73a4u; return 0; }
r[3]=read(ram,0x0c0a73ccu,4);
goto P_0c0a73a6;
P_0c0a73a6: /* original d20a, guest PC 0x0c0a73a6 */
if(!s->budget--) { s->failed_pc=0x0c0a73a6u; return 0; }
r[2]=read(ram,0x0c0a73d0u,4);
goto P_0c0a73a8;
P_0c0a73a8: /* original 6132, guest PC 0x0c0a73a8 */
if(!s->budget--) { s->failed_pc=0x0c0a73a8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a73aa;
P_0c0a73aa: /* original 212b, guest PC 0x0c0a73aa */
if(!s->budget--) { s->failed_pc=0x0c0a73aau; return 0; }
r[1]|=r[2];
goto P_0c0a73ac;
P_0c0a73ac: /* original 2312, guest PC 0x0c0a73ac */
if(!s->budget--) { s->failed_pc=0x0c0a73acu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a73ae;
P_0c0a73ae: /* original bf77, guest PC 0x0c0a73ae */
if(!s->budget--) { s->failed_pc=0x0c0a73aeu; return 0; }
target=0x0c0a72a0u; r[16]=0x0c0a73b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a73b2u) { target=s->pc; goto dispatch; }
goto P_0c0a73b2;
P_0c0a73b0: /* original 0009, guest PC 0x0c0a73b0 */
if(!s->budget--) { s->failed_pc=0x0c0a73b0u; return 0; }
goto P_0c0a73b2;
P_0c0a73b2: /* original d306, guest PC 0x0c0a73b2 */
if(!s->budget--) { s->failed_pc=0x0c0a73b2u; return 0; }
r[3]=read(ram,0x0c0a73ccu,4);
goto P_0c0a73b4;
P_0c0a73b4: /* original d214, guest PC 0x0c0a73b4 */
if(!s->budget--) { s->failed_pc=0x0c0a73b4u; return 0; }
r[2]=read(ram,0x0c0a7408u,4);
goto P_0c0a73b6;
P_0c0a73b6: /* original 6032, guest PC 0x0c0a73b6 */
if(!s->budget--) { s->failed_pc=0x0c0a73b6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0a73b8;
P_0c0a73b8: /* original 2029, guest PC 0x0c0a73b8 */
if(!s->budget--) { s->failed_pc=0x0c0a73b8u; return 0; }
r[0]&=r[2];
goto P_0c0a73ba;
P_0c0a73ba: /* original 2302, guest PC 0x0c0a73ba */
if(!s->budget--) { s->failed_pc=0x0c0a73bau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0a73bc;
P_0c0a73bc: /* original 4f26, guest PC 0x0c0a73bc */
if(!s->budget--) { s->failed_pc=0x0c0a73bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a73be;
P_0c0a73be: /* original 000b, guest PC 0x0c0a73be */
if(!s->budget--) { s->failed_pc=0x0c0a73beu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a73c0: /* original 0009, guest PC 0x0c0a73c0 */
if(!s->budget--) { s->failed_pc=0x0c0a73c0u; return 0; }
return vf3_matrix_family(0x0c0a73c2u,s,ram);
P_0c0a740e: /* original 4f22, guest PC 0x0c0a740e */
if(!s->budget--) { s->failed_pc=0x0c0a740eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7410;
P_0c0a7410: /* original 6562, guest PC 0x0c0a7410 */
if(!s->budget--) { s->failed_pc=0x0c0a7410u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c0a7412;
P_0c0a7412: /* original 9455, guest PC 0x0c0a7412 */
if(!s->budget--) { s->failed_pc=0x0c0a7412u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a74c0u,2);
goto P_0c0a7414;
P_0c0a7414: /* original 2458, guest PC 0x0c0a7414 */
if(!s->budget--) { s->failed_pc=0x0c0a7414u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0a7416;
P_0c0a7416: /* original 8904, guest PC 0x0c0a7416 */
if(!s->budget--) { s->failed_pc=0x0c0a7416u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7422; }
goto P_0c0a7418;
P_0c0a7418: /* original 8469, guest PC 0x0c0a7418 */
if(!s->budget--) { s->failed_pc=0x0c0a7418u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0a741a;
P_0c0a741a: /* original e520, guest PC 0x0c0a741a */
if(!s->budget--) { s->failed_pc=0x0c0a741au; return 0; }
r[5]=0x00000020u;
goto P_0c0a741c;
P_0c0a741c: /* original 640c, guest PC 0x0c0a741c */
if(!s->budget--) { s->failed_pc=0x0c0a741cu; return 0; }
r[4]=r[0]&255u;
goto P_0c0a741e;
P_0c0a741e: /* original 3452, guest PC 0x0c0a741e */
if(!s->budget--) { s->failed_pc=0x0c0a741eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c0a7420;
P_0c0a7420: /* original 8b08, guest PC 0x0c0a7420 */
if(!s->budget--) { s->failed_pc=0x0c0a7420u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7434; }
goto P_0c0a7422;
P_0c0a7422: /* original d12c, guest PC 0x0c0a7422 */
if(!s->budget--) { s->failed_pc=0x0c0a7422u; return 0; }
r[1]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7424;
P_0c0a7424: /* original d32a, guest PC 0x0c0a7424 */
if(!s->budget--) { s->failed_pc=0x0c0a7424u; return 0; }
r[3]=read(ram,0x0c0a74d0u,4);
goto P_0c0a7426;
P_0c0a7426: /* original 6212, guest PC 0x0c0a7426 */
if(!s->budget--) { s->failed_pc=0x0c0a7426u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0a7428;
P_0c0a7428: /* original 2238, guest PC 0x0c0a7428 */
if(!s->budget--) { s->failed_pc=0x0c0a7428u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a742a;
P_0c0a742a: /* original 8b01, guest PC 0x0c0a742a */
if(!s->budget--) { s->failed_pc=0x0c0a742au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7430; }
goto P_0c0a742c;
P_0c0a742c: /* original b062, guest PC 0x0c0a742c */
if(!s->budget--) { s->failed_pc=0x0c0a742cu; return 0; }
target=0x0c0a74f4u; r[16]=0x0c0a7430u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7430u) { target=s->pc; goto dispatch; }
goto P_0c0a7430;
P_0c0a742e: /* original 0009, guest PC 0x0c0a742e */
if(!s->budget--) { s->failed_pc=0x0c0a742eu; return 0; }
goto P_0c0a7430;
P_0c0a7430: /* original a09a, guest PC 0x0c0a7430 */
if(!s->budget--) { s->failed_pc=0x0c0a7430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7568;
P_0c0a7432: /* original 4f26, guest PC 0x0c0a7432 */
if(!s->budget--) { s->failed_pc=0x0c0a7432u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7434;
P_0c0a7434: /* original 4f26, guest PC 0x0c0a7434 */
if(!s->budget--) { s->failed_pc=0x0c0a7434u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7436;
P_0c0a7436: /* original 000b, guest PC 0x0c0a7436 */
if(!s->budget--) { s->failed_pc=0x0c0a7436u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a7438: /* original 0009, guest PC 0x0c0a7438 */
if(!s->budget--) { s->failed_pc=0x0c0a7438u; return 0; }
return vf3_matrix_family(0x0c0a743au,s,ram);
P_0c0a7478: /* original 4f22, guest PC 0x0c0a7478 */
if(!s->budget--) { s->failed_pc=0x0c0a7478u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a747a;
P_0c0a747a: /* original d318, guest PC 0x0c0a747a */
if(!s->budget--) { s->failed_pc=0x0c0a747au; return 0; }
r[3]=read(ram,0x0c0a74dcu,4);
goto P_0c0a747c;
P_0c0a747c: /* original de15, guest PC 0x0c0a747c */
if(!s->budget--) { s->failed_pc=0x0c0a747cu; return 0; }
r[14]=read(ram,0x0c0a74d4u,4);
goto P_0c0a747e;
P_0c0a747e: /* original 430b, guest PC 0x0c0a747e */
if(!s->budget--) { s->failed_pc=0x0c0a747eu; return 0; }
target=r[3];
r[16]=0x0c0a7482u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7482u) { target=s->pc; goto dispatch; }
goto P_0c0a7482;
P_0c0a7480: /* original e400, guest PC 0x0c0a7480 */
if(!s->budget--) { s->failed_pc=0x0c0a7480u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7482;
P_0c0a7482: /* original d217, guest PC 0x0c0a7482 */
if(!s->budget--) { s->failed_pc=0x0c0a7482u; return 0; }
r[2]=read(ram,0x0c0a74e0u,4);
goto P_0c0a7484;
P_0c0a7484: /* original 420b, guest PC 0x0c0a7484 */
if(!s->budget--) { s->failed_pc=0x0c0a7484u; return 0; }
target=r[2];
r[16]=0x0c0a7488u;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7488u) { target=s->pc; goto dispatch; }
goto P_0c0a7488;
P_0c0a7486: /* original e403, guest PC 0x0c0a7486 */
if(!s->budget--) { s->failed_pc=0x0c0a7486u; return 0; }
r[4]=0x00000003u;
goto P_0c0a7488;
P_0c0a7488: /* original d316, guest PC 0x0c0a7488 */
if(!s->budget--) { s->failed_pc=0x0c0a7488u; return 0; }
r[3]=read(ram,0x0c0a74e4u,4);
goto P_0c0a748a;
P_0c0a748a: /* original 430b, guest PC 0x0c0a748a */
if(!s->budget--) { s->failed_pc=0x0c0a748au; return 0; }
target=r[3];
r[16]=0x0c0a748eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a748eu) { target=s->pc; goto dispatch; }
goto P_0c0a748e;
P_0c0a748c: /* original 0009, guest PC 0x0c0a748c */
if(!s->budget--) { s->failed_pc=0x0c0a748cu; return 0; }
goto P_0c0a748e;
P_0c0a748e: /* original 9018, guest PC 0x0c0a748e */
if(!s->budget--) { s->failed_pc=0x0c0a748eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a74c2u,2);
goto P_0c0a7490;
P_0c0a7490: /* original 6de3, guest PC 0x0c0a7490 */
if(!s->budget--) { s->failed_pc=0x0c0a7490u; return 0; }
r[13]=r[14];
goto P_0c0a7492;
P_0c0a7492: /* original d315, guest PC 0x0c0a7492 */
if(!s->budget--) { s->failed_pc=0x0c0a7492u; return 0; }
r[3]=read(ram,0x0c0a74e8u,4);
goto P_0c0a7494;
P_0c0a7494: /* original f6d6, guest PC 0x0c0a7494 */
if(!s->budget--) { s->failed_pc=0x0c0a7494u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a7496;
P_0c0a7496: /* original 9015, guest PC 0x0c0a7496 */
if(!s->budget--) { s->failed_pc=0x0c0a7496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a74c4u,2);
goto P_0c0a7498;
P_0c0a7498: /* original f5d6, guest PC 0x0c0a7498 */
if(!s->budget--) { s->failed_pc=0x0c0a7498u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a749a;
P_0c0a749a: /* original 9014, guest PC 0x0c0a749a */
if(!s->budget--) { s->failed_pc=0x0c0a749au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a74c6u,2);
goto P_0c0a749c;
P_0c0a749c: /* original f4d6, guest PC 0x0c0a749c */
if(!s->budget--) { s->failed_pc=0x0c0a749cu; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c0a749e;
P_0c0a749e: /* original 430b, guest PC 0x0c0a749e */
if(!s->budget--) { s->failed_pc=0x0c0a749eu; return 0; }
target=r[3];
r[16]=0x0c0a74a2u;
r[4]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a74a2u) { target=s->pc; goto dispatch; }
goto P_0c0a74a2;
P_0c0a74a0: /* original 54e6, guest PC 0x0c0a74a0 */
if(!s->budget--) { s->failed_pc=0x0c0a74a0u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0a74a2;
P_0c0a74a2: /* original d212, guest PC 0x0c0a74a2 */
if(!s->budget--) { s->failed_pc=0x0c0a74a2u; return 0; }
r[2]=read(ram,0x0c0a74ecu,4);
goto P_0c0a74a4;
P_0c0a74a4: /* original 9410, guest PC 0x0c0a74a4 */
if(!s->budget--) { s->failed_pc=0x0c0a74a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a74c8u,2);
goto P_0c0a74a6;
P_0c0a74a6: /* original 420b, guest PC 0x0c0a74a6 */
if(!s->budget--) { s->failed_pc=0x0c0a74a6u; return 0; }
target=r[2];
r[16]=0x0c0a74aau;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a74aau) { target=s->pc; goto dispatch; }
goto P_0c0a74aa;
P_0c0a74a8: /* original 34ec, guest PC 0x0c0a74a8 */
if(!s->budget--) { s->failed_pc=0x0c0a74a8u; return 0; }
r[4]+=r[14];
goto P_0c0a74aa;
P_0c0a74aa: /* original d30d, guest PC 0x0c0a74aa */
if(!s->budget--) { s->failed_pc=0x0c0a74aau; return 0; }
r[3]=read(ram,0x0c0a74e0u,4);
goto P_0c0a74ac;
P_0c0a74ac: /* original 430b, guest PC 0x0c0a74ac */
if(!s->budget--) { s->failed_pc=0x0c0a74acu; return 0; }
target=r[3];
r[16]=0x0c0a74b0u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a74b0u) { target=s->pc; goto dispatch; }
goto P_0c0a74b0;
P_0c0a74ae: /* original e401, guest PC 0x0c0a74ae */
if(!s->budget--) { s->failed_pc=0x0c0a74aeu; return 0; }
r[4]=0x00000001u;
goto P_0c0a74b0;
P_0c0a74b0: /* original 4f26, guest PC 0x0c0a74b0 */
if(!s->budget--) { s->failed_pc=0x0c0a74b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a74b2;
P_0c0a74b2: /* original d20f, guest PC 0x0c0a74b2 */
if(!s->budget--) { s->failed_pc=0x0c0a74b2u; return 0; }
r[2]=read(ram,0x0c0a74f0u,4);
goto P_0c0a74b4;
P_0c0a74b4: /* original e401, guest PC 0x0c0a74b4 */
if(!s->budget--) { s->failed_pc=0x0c0a74b4u; return 0; }
r[4]=0x00000001u;
goto P_0c0a74b6;
P_0c0a74b6: /* original 6df6, guest PC 0x0c0a74b6 */
if(!s->budget--) { s->failed_pc=0x0c0a74b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a74b8;
P_0c0a74b8: /* original 422b, guest PC 0x0c0a74b8 */
if(!s->budget--) { s->failed_pc=0x0c0a74b8u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0a74ba: /* original 6ef6, guest PC 0x0c0a74ba */
if(!s->budget--) { s->failed_pc=0x0c0a74bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a74bcu,s,ram);
P_0c0a74f4: /* original 2fe6, guest PC 0x0c0a74f4 */
if(!s->budget--) { s->failed_pc=0x0c0a74f4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a74f6;
P_0c0a74f6: /* original 2fd6, guest PC 0x0c0a74f6 */
if(!s->budget--) { s->failed_pc=0x0c0a74f6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0a74f8;
P_0c0a74f8: /* original d32e, guest PC 0x0c0a74f8 */
if(!s->budget--) { s->failed_pc=0x0c0a74f8u; return 0; }
r[3]=read(ram,0x0c0a75b4u,4);
return vf3_matrix_family(0x0c0a74fau,s,ram);
P_0c0a7568: /* original 000b, guest PC 0x0c0a7568 */
if(!s->budget--) { s->failed_pc=0x0c0a7568u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a756a: /* original 0009, guest PC 0x0c0a756a */
if(!s->budget--) { s->failed_pc=0x0c0a756au; return 0; }
return vf3_matrix_family(0x0c0a756cu,s,ram);
P_0c0a7570: /* original 4f22, guest PC 0x0c0a7570 */
if(!s->budget--) { s->failed_pc=0x0c0a7570u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7572;
P_0c0a7572: /* original 3433, guest PC 0x0c0a7572 */
if(!s->budget--) { s->failed_pc=0x0c0a7572u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a7574;
P_0c0a7574: /* original 891a, guest PC 0x0c0a7574 */
if(!s->budget--) { s->failed_pc=0x0c0a7574u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a75ac; }
goto P_0c0a7576;
P_0c0a7576: /* original d01c, guest PC 0x0c0a7576 */
if(!s->budget--) { s->failed_pc=0x0c0a7576u; return 0; }
r[0]=read(ram,0x0c0a75e8u,4);
goto P_0c0a7578;
P_0c0a7578: /* original 6e43, guest PC 0x0c0a7578 */
if(!s->budget--) { s->failed_pc=0x0c0a7578u; return 0; }
r[14]=r[4];
goto P_0c0a757a;
P_0c0a757a: /* original 4e08, guest PC 0x0c0a757a */
if(!s->budget--) { s->failed_pc=0x0c0a757au; return 0; }
r[14]<<=2;
goto P_0c0a757c;
P_0c0a757c: /* original 0eee, guest PC 0x0c0a757c */
if(!s->budget--) { s->failed_pc=0x0c0a757cu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a757e;
P_0c0a757e: /* original 2ee8, guest PC 0x0c0a757e */
if(!s->budget--) { s->failed_pc=0x0c0a757eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7580;
P_0c0a7580: /* original 8914, guest PC 0x0c0a7580 */
if(!s->budget--) { s->failed_pc=0x0c0a7580u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a75ac; }
goto P_0c0a7582;
P_0c0a7582: /* original 60e3, guest PC 0x0c0a7582 */
if(!s->budget--) { s->failed_pc=0x0c0a7582u; return 0; }
r[0]=r[14];
goto P_0c0a7584;
P_0c0a7584: /* original 88ff, guest PC 0x0c0a7584 */
if(!s->budget--) { s->failed_pc=0x0c0a7584u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a7586;
P_0c0a7586: /* original 8911, guest PC 0x0c0a7586 */
if(!s->budget--) { s->failed_pc=0x0c0a7586u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a75ac; }
goto P_0c0a7588;
P_0c0a7588: /* original d318, guest PC 0x0c0a7588 */
if(!s->budget--) { s->failed_pc=0x0c0a7588u; return 0; }
r[3]=read(ram,0x0c0a75ecu,4);
goto P_0c0a758a;
P_0c0a758a: /* original 430b, guest PC 0x0c0a758a */
if(!s->budget--) { s->failed_pc=0x0c0a758au; return 0; }
target=r[3];
r[16]=0x0c0a758eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a758eu) { target=s->pc; goto dispatch; }
goto P_0c0a758e;
P_0c0a758c: /* original e400, guest PC 0x0c0a758c */
if(!s->budget--) { s->failed_pc=0x0c0a758cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a758e;
P_0c0a758e: /* original d219, guest PC 0x0c0a758e */
if(!s->budget--) { s->failed_pc=0x0c0a758eu; return 0; }
r[2]=read(ram,0x0c0a75f4u,4);
goto P_0c0a7590;
P_0c0a7590: /* original d417, guest PC 0x0c0a7590 */
if(!s->budget--) { s->failed_pc=0x0c0a7590u; return 0; }
r[4]=read(ram,0x0c0a75f0u,4);
goto P_0c0a7592;
P_0c0a7592: /* original 420b, guest PC 0x0c0a7592 */
if(!s->budget--) { s->failed_pc=0x0c0a7592u; return 0; }
target=r[2];
r[16]=0x0c0a7596u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7596u) { target=s->pc; goto dispatch; }
goto P_0c0a7596;
P_0c0a7594: /* original 0009, guest PC 0x0c0a7594 */
if(!s->budget--) { s->failed_pc=0x0c0a7594u; return 0; }
goto P_0c0a7596;
P_0c0a7596: /* original 50e1, guest PC 0x0c0a7596 */
if(!s->budget--) { s->failed_pc=0x0c0a7596u; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a7598;
P_0c0a7598: /* original c801, guest PC 0x0c0a7598 */
if(!s->budget--) { s->failed_pc=0x0c0a7598u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a759a;
P_0c0a759a: /* original 8902, guest PC 0x0c0a759a */
if(!s->budget--) { s->failed_pc=0x0c0a759au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a75a2; }
goto P_0c0a759c;
P_0c0a759c: /* original d216, guest PC 0x0c0a759c */
if(!s->budget--) { s->failed_pc=0x0c0a759cu; return 0; }
r[2]=read(ram,0x0c0a75f8u,4);
goto P_0c0a759e;
P_0c0a759e: /* original 420b, guest PC 0x0c0a759e */
if(!s->budget--) { s->failed_pc=0x0c0a759eu; return 0; }
target=r[2];
r[16]=0x0c0a75a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a75a2u) { target=s->pc; goto dispatch; }
goto P_0c0a75a2;
P_0c0a75a0: /* original 64e3, guest PC 0x0c0a75a0 */
if(!s->budget--) { s->failed_pc=0x0c0a75a0u; return 0; }
r[4]=r[14];
goto P_0c0a75a2;
P_0c0a75a2: /* original 4f26, guest PC 0x0c0a75a2 */
if(!s->budget--) { s->failed_pc=0x0c0a75a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a75a4;
P_0c0a75a4: /* original d215, guest PC 0x0c0a75a4 */
if(!s->budget--) { s->failed_pc=0x0c0a75a4u; return 0; }
r[2]=read(ram,0x0c0a75fcu,4);
goto P_0c0a75a6;
P_0c0a75a6: /* original e401, guest PC 0x0c0a75a6 */
if(!s->budget--) { s->failed_pc=0x0c0a75a6u; return 0; }
r[4]=0x00000001u;
goto P_0c0a75a8;
P_0c0a75a8: /* original 422b, guest PC 0x0c0a75a8 */
if(!s->budget--) { s->failed_pc=0x0c0a75a8u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0a75aa: /* original 6ef6, guest PC 0x0c0a75aa */
if(!s->budget--) { s->failed_pc=0x0c0a75aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a75ac;
P_0c0a75ac: /* original 4f26, guest PC 0x0c0a75ac */
if(!s->budget--) { s->failed_pc=0x0c0a75acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a75ae;
P_0c0a75ae: /* original 000b, guest PC 0x0c0a75ae */
if(!s->budget--) { s->failed_pc=0x0c0a75aeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a75b0: /* original 6ef6, guest PC 0x0c0a75b0 */
if(!s->budget--) { s->failed_pc=0x0c0a75b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a75b2u,s,ram);
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=0x0c0a7684u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=0x0c0a768cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=0x0c0a7698u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=0x0c0a76a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=0x0c0a76aeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a76beu,s,ram);
P_0c0a76ee: /* original 4f22, guest PC 0x0c0a76ee */
if(!s->budget--) { s->failed_pc=0x0c0a76eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a76f0;
P_0c0a76f0: /* original 7ff8, guest PC 0x0c0a76f0 */
if(!s->budget--) { s->failed_pc=0x0c0a76f0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a76f2;
P_0c0a76f2: /* original 1f41, guest PC 0x0c0a76f2 */
if(!s->budget--) { s->failed_pc=0x0c0a76f2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a76f4;
P_0c0a76f4: /* original ff4a, guest PC 0x0c0a76f4 */
if(!s->budget--) { s->failed_pc=0x0c0a76f4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a76f6;
P_0c0a76f6: /* original d34b, guest PC 0x0c0a76f6 */
if(!s->budget--) { s->failed_pc=0x0c0a76f6u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a76f8;
P_0c0a76f8: /* original 430b, guest PC 0x0c0a76f8 */
if(!s->budget--) { s->failed_pc=0x0c0a76f8u; return 0; }
target=r[3];
r[16]=0x0c0a76fcu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a76fcu) { target=s->pc; goto dispatch; }
goto P_0c0a76fc;
P_0c0a76fa: /* original e400, guest PC 0x0c0a76fa */
if(!s->budget--) { s->failed_pc=0x0c0a76fau; return 0; }
r[4]=0x00000000u;
goto P_0c0a76fc;
P_0c0a76fc: /* original 5ef1, guest PC 0x0c0a76fc */
if(!s->budget--) { s->failed_pc=0x0c0a76fcu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0a76fe;
P_0c0a76fe: /* original e301, guest PC 0x0c0a76fe */
if(!s->budget--) { s->failed_pc=0x0c0a76feu; return 0; }
r[3]=0x00000001u;
goto P_0c0a7700;
P_0c0a7700: /* original 5ee1, guest PC 0x0c0a7700 */
if(!s->budget--) { s->failed_pc=0x0c0a7700u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c0a7702;
P_0c0a7702: /* original 23e8, guest PC 0x0c0a7702 */
if(!s->budget--) { s->failed_pc=0x0c0a7702u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a7704;
P_0c0a7704: /* original 8b1e, guest PC 0x0c0a7704 */
if(!s->budget--) { s->failed_pc=0x0c0a7704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7744; }
goto P_0c0a7706;
P_0c0a7706: /* original 2ee8, guest PC 0x0c0a7706 */
if(!s->budget--) { s->failed_pc=0x0c0a7706u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7708;
P_0c0a7708: /* original 8916, guest PC 0x0c0a7708 */
if(!s->budget--) { s->failed_pc=0x0c0a7708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a770a;
P_0c0a770a: /* original d348, guest PC 0x0c0a770a */
if(!s->budget--) { s->failed_pc=0x0c0a770au; return 0; }
r[3]=read(ram,0x0c0a782cu,4);
goto P_0c0a770c;
P_0c0a770c: /* original d446, guest PC 0x0c0a770c */
if(!s->budget--) { s->failed_pc=0x0c0a770cu; return 0; }
r[4]=read(ram,0x0c0a7828u,4);
goto P_0c0a770e;
P_0c0a770e: /* original 430b, guest PC 0x0c0a770e */
if(!s->budget--) { s->failed_pc=0x0c0a770eu; return 0; }
target=r[3];
r[16]=0x0c0a7712u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7712u) { target=s->pc; goto dispatch; }
goto P_0c0a7712;
P_0c0a7710: /* original 0009, guest PC 0x0c0a7710 */
if(!s->budget--) { s->failed_pc=0x0c0a7710u; return 0; }
goto P_0c0a7712;
P_0c0a7712: /* original d247, guest PC 0x0c0a7712 */
if(!s->budget--) { s->failed_pc=0x0c0a7712u; return 0; }
r[2]=read(ram,0x0c0a7830u,4);
goto P_0c0a7714;
P_0c0a7714: /* original 420b, guest PC 0x0c0a7714 */
if(!s->budget--) { s->failed_pc=0x0c0a7714u; return 0; }
target=r[2];
r[16]=0x0c0a7718u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7718u) { target=s->pc; goto dispatch; }
goto P_0c0a7718;
P_0c0a7716: /* original 0009, guest PC 0x0c0a7716 */
if(!s->budget--) { s->failed_pc=0x0c0a7716u; return 0; }
goto P_0c0a7718;
P_0c0a7718: /* original f2f8, guest PC 0x0c0a7718 */
if(!s->budget--) { s->failed_pc=0x0c0a7718u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a771a;
P_0c0a771a: /* original f39d, guest PC 0x0c0a771a */
if(!s->budget--) { s->failed_pc=0x0c0a771au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0a771c;
P_0c0a771c: /* original f325, guest PC 0x0c0a771c */
if(!s->budget--) { s->failed_pc=0x0c0a771cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0a771e;
P_0c0a771e: /* original 8907, guest PC 0x0c0a771e */
if(!s->budget--) { s->failed_pc=0x0c0a771eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7730; }
goto P_0c0a7720;
P_0c0a7720: /* original d244, guest PC 0x0c0a7720 */
if(!s->budget--) { s->failed_pc=0x0c0a7720u; return 0; }
r[2]=read(ram,0x0c0a7834u,4);
goto P_0c0a7722;
P_0c0a7722: /* original 22e8, guest PC 0x0c0a7722 */
if(!s->budget--) { s->failed_pc=0x0c0a7722u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0a7724;
P_0c0a7724: /* original 8908, guest PC 0x0c0a7724 */
if(!s->budget--) { s->failed_pc=0x0c0a7724u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a7726;
P_0c0a7726: /* original d244, guest PC 0x0c0a7726 */
if(!s->budget--) { s->failed_pc=0x0c0a7726u; return 0; }
r[2]=read(ram,0x0c0a7838u,4);
goto P_0c0a7728;
P_0c0a7728: /* original 420b, guest PC 0x0c0a7728 */
if(!s->budget--) { s->failed_pc=0x0c0a7728u; return 0; }
target=r[2];
r[16]=0x0c0a772cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a772cu) { target=s->pc; goto dispatch; }
goto P_0c0a772c;
P_0c0a772a: /* original 64e3, guest PC 0x0c0a772a */
if(!s->budget--) { s->failed_pc=0x0c0a772au; return 0; }
r[4]=r[14];
goto P_0c0a772c;
P_0c0a772c: /* original a004, guest PC 0x0c0a772c */
if(!s->budget--) { s->failed_pc=0x0c0a772cu; return 0; }
goto P_0c0a7738;
P_0c0a772e: /* original 0009, guest PC 0x0c0a772e */
if(!s->budget--) { s->failed_pc=0x0c0a772eu; return 0; }
goto P_0c0a7730;
P_0c0a7730: /* original d342, guest PC 0x0c0a7730 */
if(!s->budget--) { s->failed_pc=0x0c0a7730u; return 0; }
r[3]=read(ram,0x0c0a783cu,4);
goto P_0c0a7732;
P_0c0a7732: /* original f42c, guest PC 0x0c0a7732 */
if(!s->budget--) { s->failed_pc=0x0c0a7732u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a7734;
P_0c0a7734: /* original 430b, guest PC 0x0c0a7734 */
if(!s->budget--) { s->failed_pc=0x0c0a7734u; return 0; }
target=r[3];
r[16]=0x0c0a7738u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7738u) { target=s->pc; goto dispatch; }
goto P_0c0a7738;
P_0c0a7736: /* original 64e3, guest PC 0x0c0a7736 */
if(!s->budget--) { s->failed_pc=0x0c0a7736u; return 0; }
r[4]=r[14];
goto P_0c0a7738;
P_0c0a7738: /* original 7f08, guest PC 0x0c0a7738 */
if(!s->budget--) { s->failed_pc=0x0c0a7738u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a773a;
P_0c0a773a: /* original d241, guest PC 0x0c0a773a */
if(!s->budget--) { s->failed_pc=0x0c0a773au; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a773c;
P_0c0a773c: /* original 4f26, guest PC 0x0c0a773c */
if(!s->budget--) { s->failed_pc=0x0c0a773cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a773e;
P_0c0a773e: /* original e401, guest PC 0x0c0a773e */
if(!s->budget--) { s->failed_pc=0x0c0a773eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a7740;
P_0c0a7740: /* original 422b, guest PC 0x0c0a7740 */
if(!s->budget--) { s->failed_pc=0x0c0a7740u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0a7742: /* original 6ef6, guest PC 0x0c0a7742 */
if(!s->budget--) { s->failed_pc=0x0c0a7742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7744;
P_0c0a7744: /* original 7f08, guest PC 0x0c0a7744 */
if(!s->budget--) { s->failed_pc=0x0c0a7744u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a7746;
P_0c0a7746: /* original 4f26, guest PC 0x0c0a7746 */
if(!s->budget--) { s->failed_pc=0x0c0a7746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7748;
P_0c0a7748: /* original 000b, guest PC 0x0c0a7748 */
if(!s->budget--) { s->failed_pc=0x0c0a7748u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a774a: /* original 6ef6, guest PC 0x0c0a774a */
if(!s->budget--) { s->failed_pc=0x0c0a774au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a774cu,s,ram);
P_0c0a7b5a: /* original 4f22, guest PC 0x0c0a7b5a */
if(!s->budget--) { s->failed_pc=0x0c0a7b5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7b5c;
P_0c0a7b5c: /* original 60e2, guest PC 0x0c0a7b5c */
if(!s->budget--) { s->failed_pc=0x0c0a7b5cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a7b5e;
P_0c0a7b5e: /* original c801, guest PC 0x0c0a7b5e */
if(!s->budget--) { s->failed_pc=0x0c0a7b5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7b60;
P_0c0a7b60: /* original 890e, guest PC 0x0c0a7b60 */
if(!s->budget--) { s->failed_pc=0x0c0a7b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7b80; }
goto P_0c0a7b62;
P_0c0a7b62: /* original d30e, guest PC 0x0c0a7b62 */
if(!s->budget--) { s->failed_pc=0x0c0a7b62u; return 0; }
r[3]=read(ram,0x0c0a7b9cu,4);
goto P_0c0a7b64;
P_0c0a7b64: /* original 9012, guest PC 0x0c0a7b64 */
if(!s->budget--) { s->failed_pc=0x0c0a7b64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b8cu,2);
goto P_0c0a7b66;
P_0c0a7b66: /* original 430b, guest PC 0x0c0a7b66 */
if(!s->budget--) { s->failed_pc=0x0c0a7b66u; return 0; }
target=r[3];
r[16]=0x0c0a7b6au;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b6au) { target=s->pc; goto dispatch; }
goto P_0c0a7b6a;
P_0c0a7b68: /* original f4e6, guest PC 0x0c0a7b68 */
if(!s->budget--) { s->failed_pc=0x0c0a7b68u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a7b6a;
P_0c0a7b6a: /* original d20d, guest PC 0x0c0a7b6a */
if(!s->budget--) { s->failed_pc=0x0c0a7b6au; return 0; }
r[2]=read(ram,0x0c0a7ba0u,4);
goto P_0c0a7b6c;
P_0c0a7b6c: /* original 420b, guest PC 0x0c0a7b6c */
if(!s->budget--) { s->failed_pc=0x0c0a7b6cu; return 0; }
target=r[2];
r[16]=0x0c0a7b70u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b70u) { target=s->pc; goto dispatch; }
goto P_0c0a7b70;
P_0c0a7b6e: /* original 6403, guest PC 0x0c0a7b6e */
if(!s->budget--) { s->failed_pc=0x0c0a7b6eu; return 0; }
r[4]=r[0];
goto P_0c0a7b70;
P_0c0a7b70: /* original d30c, guest PC 0x0c0a7b70 */
if(!s->budget--) { s->failed_pc=0x0c0a7b70u; return 0; }
r[3]=read(ram,0x0c0a7ba4u,4);
goto P_0c0a7b72;
P_0c0a7b72: /* original 940c, guest PC 0x0c0a7b72 */
if(!s->budget--) { s->failed_pc=0x0c0a7b72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b8eu,2);
goto P_0c0a7b74;
P_0c0a7b74: /* original 430b, guest PC 0x0c0a7b74 */
if(!s->budget--) { s->failed_pc=0x0c0a7b74u; return 0; }
target=r[3];
r[16]=0x0c0a7b78u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b78u) { target=s->pc; goto dispatch; }
goto P_0c0a7b78;
P_0c0a7b76: /* original 34ec, guest PC 0x0c0a7b76 */
if(!s->budget--) { s->failed_pc=0x0c0a7b76u; return 0; }
r[4]+=r[14];
goto P_0c0a7b78;
P_0c0a7b78: /* original 62e2, guest PC 0x0c0a7b78 */
if(!s->budget--) { s->failed_pc=0x0c0a7b78u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a7b7a;
P_0c0a7b7a: /* original e3fe, guest PC 0x0c0a7b7a */
if(!s->budget--) { s->failed_pc=0x0c0a7b7au; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a7b7c;
P_0c0a7b7c: /* original 2239, guest PC 0x0c0a7b7c */
if(!s->budget--) { s->failed_pc=0x0c0a7b7cu; return 0; }
r[2]&=r[3];
goto P_0c0a7b7e;
P_0c0a7b7e: /* original 2e22, guest PC 0x0c0a7b7e */
if(!s->budget--) { s->failed_pc=0x0c0a7b7eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a7b80;
P_0c0a7b80: /* original 4f26, guest PC 0x0c0a7b80 */
if(!s->budget--) { s->failed_pc=0x0c0a7b80u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b82;
P_0c0a7b82: /* original 000b, guest PC 0x0c0a7b82 */
if(!s->budget--) { s->failed_pc=0x0c0a7b82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7b84: /* original 6ef6, guest PC 0x0c0a7b84 */
if(!s->budget--) { s->failed_pc=0x0c0a7b84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7b86u,s,ram);
P_0c0a9f62: /* original 4f22, guest PC 0x0c0a9f62 */
if(!s->budget--) { s->failed_pc=0x0c0a9f62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9f64;
P_0c0a9f64: /* original 6233, guest PC 0x0c0a9f64 */
if(!s->budget--) { s->failed_pc=0x0c0a9f64u; return 0; }
r[2]=r[3];
goto P_0c0a9f66;
P_0c0a9f66: /* original 2228, guest PC 0x0c0a9f66 */
if(!s->budget--) { s->failed_pc=0x0c0a9f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a9f68;
P_0c0a9f68: /* original 7ff0, guest PC 0x0c0a9f68 */
if(!s->budget--) { s->failed_pc=0x0c0a9f68u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a9f6a;
P_0c0a9f6a: /* original 8f06, guest PC 0x0c0a9f6a */
if(!s->budget--) { s->failed_pc=0x0c0a9f6au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[3],4);
if(!cond) { goto P_0c0a9f7a; }
goto P_0c0a9f6e;
P_0c0a9f6c: /* original 1f33, guest PC 0x0c0a9f6c */
if(!s->budget--) { s->failed_pc=0x0c0a9f6cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a9f6e;
P_0c0a9f6e: /* original b01c, guest PC 0x0c0a9f6e */
if(!s->budget--) { s->failed_pc=0x0c0a9f6eu; return 0; }
target=0x0c0a9faau; r[16]=0x0c0a9f72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9f72u) { target=s->pc; goto dispatch; }
goto P_0c0a9f72;
P_0c0a9f70: /* original 0009, guest PC 0x0c0a9f70 */
if(!s->budget--) { s->failed_pc=0x0c0a9f70u; return 0; }
goto P_0c0a9f72;
P_0c0a9f72: /* original 7f10, guest PC 0x0c0a9f72 */
if(!s->budget--) { s->failed_pc=0x0c0a9f72u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9f74;
P_0c0a9f74: /* original 4f26, guest PC 0x0c0a9f74 */
if(!s->budget--) { s->failed_pc=0x0c0a9f74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9f76;
P_0c0a9f76: /* original 000b, guest PC 0x0c0a9f76 */
if(!s->budget--) { s->failed_pc=0x0c0a9f76u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9f78: /* original 0009, guest PC 0x0c0a9f78 */
if(!s->budget--) { s->failed_pc=0x0c0a9f78u; return 0; }
goto P_0c0a9f7a;
P_0c0a9f7a: /* original 6243, guest PC 0x0c0a9f7a */
if(!s->budget--) { s->failed_pc=0x0c0a9f7au; return 0; }
r[2]=r[4];
goto P_0c0a9f7c;
P_0c0a9f7c: /* original 7238, guest PC 0x0c0a9f7c */
if(!s->budget--) { s->failed_pc=0x0c0a9f7cu; return 0; }
r[2]+=0x00000038u;
goto P_0c0a9f7e;
P_0c0a9f7e: /* original 8423, guest PC 0x0c0a9f7e */
if(!s->budget--) { s->failed_pc=0x0c0a9f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0a9f80;
P_0c0a9f80: /* original 66f3, guest PC 0x0c0a9f80 */
if(!s->budget--) { s->failed_pc=0x0c0a9f80u; return 0; }
r[6]=r[15];
goto P_0c0a9f82;
P_0c0a9f82: /* original 600c, guest PC 0x0c0a9f82 */
if(!s->budget--) { s->failed_pc=0x0c0a9f82u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9f84;
P_0c0a9f84: /* original 1f02, guest PC 0x0c0a9f84 */
if(!s->budget--) { s->failed_pc=0x0c0a9f84u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0a9f86;
P_0c0a9f86: /* original 53f3, guest PC 0x0c0a9f86 */
if(!s->budget--) { s->failed_pc=0x0c0a9f86u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a9f88;
P_0c0a9f88: /* original 4329, guest PC 0x0c0a9f88 */
if(!s->budget--) { s->failed_pc=0x0c0a9f88u; return 0; }
r[3]>>=16;
goto P_0c0a9f8a;
P_0c0a9f8a: /* original 4319, guest PC 0x0c0a9f8a */
if(!s->budget--) { s->failed_pc=0x0c0a9f8au; return 0; }
r[3]>>=8;
goto P_0c0a9f8c;
P_0c0a9f8c: /* original 6033, guest PC 0x0c0a9f8c */
if(!s->budget--) { s->failed_pc=0x0c0a9f8cu; return 0; }
r[0]=r[3];
goto P_0c0a9f8e;
P_0c0a9f8e: /* original c9ff, guest PC 0x0c0a9f8e */
if(!s->budget--) { s->failed_pc=0x0c0a9f8eu; return 0; }
r[0]&=255u;
goto P_0c0a9f90;
P_0c0a9f90: /* original 6303, guest PC 0x0c0a9f90 */
if(!s->budget--) { s->failed_pc=0x0c0a9f90u; return 0; }
r[3]=r[0];
goto P_0c0a9f92;
P_0c0a9f92: /* original 1f01, guest PC 0x0c0a9f92 */
if(!s->budget--) { s->failed_pc=0x0c0a9f92u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0a9f94;
P_0c0a9f94: /* original d00b, guest PC 0x0c0a9f94 */
if(!s->budget--) { s->failed_pc=0x0c0a9f94u; return 0; }
r[0]=read(ram,0x0c0a9fc4u,4);
goto P_0c0a9f96;
P_0c0a9f96: /* original 4308, guest PC 0x0c0a9f96 */
if(!s->budget--) { s->failed_pc=0x0c0a9f96u; return 0; }
r[3]<<=2;
goto P_0c0a9f98;
P_0c0a9f98: /* original 023e, guest PC 0x0c0a9f98 */
if(!s->budget--) { s->failed_pc=0x0c0a9f98u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a9f9a;
P_0c0a9f9a: /* original 6323, guest PC 0x0c0a9f9a */
if(!s->budget--) { s->failed_pc=0x0c0a9f9au; return 0; }
r[3]=r[2];
goto P_0c0a9f9c;
P_0c0a9f9c: /* original 2f22, guest PC 0x0c0a9f9c */
if(!s->budget--) { s->failed_pc=0x0c0a9f9cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a9f9e;
P_0c0a9f9e: /* original 430b, guest PC 0x0c0a9f9e */
if(!s->budget--) { s->failed_pc=0x0c0a9f9eu; return 0; }
target=r[3];
r[16]=0x0c0a9fa2u;
r[6]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a9fa2u) { target=s->pc; goto dispatch; }
goto P_0c0a9fa2;
P_0c0a9fa0: /* original 7604, guest PC 0x0c0a9fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a9fa2;
P_0c0a9fa2: /* original 7f10, guest PC 0x0c0a9fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9fa4;
P_0c0a9fa4: /* original 4f26, guest PC 0x0c0a9fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9fa6;
P_0c0a9fa6: /* original 000b, guest PC 0x0c0a9fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9fa8: /* original 0009, guest PC 0x0c0a9fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa8u; return 0; }
return vf3_matrix_family(0x0c0a9faau,s,ram);
P_0c0aa446: /* original 4f22, guest PC 0x0c0aa446 */
if(!s->budget--) { s->failed_pc=0x0c0aa446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa448;
P_0c0aa448: /* original 6233, guest PC 0x0c0aa448 */
if(!s->budget--) { s->failed_pc=0x0c0aa448u; return 0; }
r[2]=r[3];
goto P_0c0aa44a;
P_0c0aa44a: /* original 2228, guest PC 0x0c0aa44a */
if(!s->budget--) { s->failed_pc=0x0c0aa44au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aa44c;
P_0c0aa44c: /* original 7ff4, guest PC 0x0c0aa44c */
if(!s->budget--) { s->failed_pc=0x0c0aa44cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0aa44e;
P_0c0aa44e: /* original 8d0e, guest PC 0x0c0aa44e */
if(!s->budget--) { s->failed_pc=0x0c0aa44eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c0aa46e; }
goto P_0c0aa452;
P_0c0aa450: /* original 1f31, guest PC 0x0c0aa450 */
if(!s->budget--) { s->failed_pc=0x0c0aa450u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aa452;
P_0c0aa452: /* original e062, guest PC 0x0c0aa452 */
if(!s->budget--) { s->failed_pc=0x0c0aa452u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa454;
P_0c0aa454: /* original 024c, guest PC 0x0c0aa454 */
if(!s->budget--) { s->failed_pc=0x0c0aa454u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0aa456;
P_0c0aa456: /* original 622c, guest PC 0x0c0aa456 */
if(!s->budget--) { s->failed_pc=0x0c0aa456u; return 0; }
r[2]=r[2]&255u;
goto P_0c0aa458;
P_0c0aa458: /* original 1f22, guest PC 0x0c0aa458 */
if(!s->budget--) { s->failed_pc=0x0c0aa458u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0aa45a;
P_0c0aa45a: /* original 56f1, guest PC 0x0c0aa45a */
if(!s->budget--) { s->failed_pc=0x0c0aa45au; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0aa45c;
P_0c0aa45c: /* original d013, guest PC 0x0c0aa45c */
if(!s->budget--) { s->failed_pc=0x0c0aa45cu; return 0; }
r[0]=read(ram,0x0c0aa4acu,4);
goto P_0c0aa45e;
P_0c0aa45e: /* original 4629, guest PC 0x0c0aa45e */
if(!s->budget--) { s->failed_pc=0x0c0aa45eu; return 0; }
r[6]>>=16;
goto P_0c0aa460;
P_0c0aa460: /* original 4619, guest PC 0x0c0aa460 */
if(!s->budget--) { s->failed_pc=0x0c0aa460u; return 0; }
r[6]>>=8;
goto P_0c0aa462;
P_0c0aa462: /* original 4608, guest PC 0x0c0aa462 */
if(!s->budget--) { s->failed_pc=0x0c0aa462u; return 0; }
r[6]<<=2;
goto P_0c0aa464;
P_0c0aa464: /* original 036e, guest PC 0x0c0aa464 */
if(!s->budget--) { s->failed_pc=0x0c0aa464u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0aa466;
P_0c0aa466: /* original 66f3, guest PC 0x0c0aa466 */
if(!s->budget--) { s->failed_pc=0x0c0aa466u; return 0; }
r[6]=r[15];
goto P_0c0aa468;
P_0c0aa468: /* original 2f32, guest PC 0x0c0aa468 */
if(!s->budget--) { s->failed_pc=0x0c0aa468u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aa46a;
P_0c0aa46a: /* original 430b, guest PC 0x0c0aa46a */
if(!s->budget--) { s->failed_pc=0x0c0aa46au; return 0; }
target=r[3];
r[16]=0x0c0aa46eu;
r[6]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa46eu) { target=s->pc; goto dispatch; }
goto P_0c0aa46e;
P_0c0aa46c: /* original 7604, guest PC 0x0c0aa46c */
if(!s->budget--) { s->failed_pc=0x0c0aa46cu; return 0; }
r[6]+=0x00000004u;
goto P_0c0aa46e;
P_0c0aa46e: /* original 7f0c, guest PC 0x0c0aa46e */
if(!s->budget--) { s->failed_pc=0x0c0aa46eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0aa470;
P_0c0aa470: /* original 4f26, guest PC 0x0c0aa470 */
if(!s->budget--) { s->failed_pc=0x0c0aa470u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa472;
P_0c0aa472: /* original 000b, guest PC 0x0c0aa472 */
if(!s->budget--) { s->failed_pc=0x0c0aa472u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa474: /* original 0009, guest PC 0x0c0aa474 */
if(!s->budget--) { s->failed_pc=0x0c0aa474u; return 0; }
return vf3_matrix_family(0x0c0aa476u,s,ram);
P_0c0aa4b8: /* original 4f22, guest PC 0x0c0aa4b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa4b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa4ba;
P_0c0aa4ba: /* original 2338, guest PC 0x0c0aa4ba */
if(!s->budget--) { s->failed_pc=0x0c0aa4bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0aa4bc;
P_0c0aa4bc: /* original 8f0b, guest PC 0x0c0aa4bc */
if(!s->budget--) { s->failed_pc=0x0c0aa4bcu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0aa4d6; }
goto P_0c0aa4c0;
P_0c0aa4be: /* original 6e43, guest PC 0x0c0aa4be */
if(!s->budget--) { s->failed_pc=0x0c0aa4beu; return 0; }
r[14]=r[4];
goto P_0c0aa4c0;
P_0c0aa4c0: /* original 65d2, guest PC 0x0c0aa4c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa4c0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0aa4c2;
P_0c0aa4c2: /* original d33d, guest PC 0x0c0aa4c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa4c2u; return 0; }
r[3]=read(ram,0x0c0aa5b8u,4);
goto P_0c0aa4c4;
P_0c0aa4c4: /* original 655d, guest PC 0x0c0aa4c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa4c4u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa4c6;
P_0c0aa4c6: /* original 430b, guest PC 0x0c0aa4c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa4c6u; return 0; }
target=r[3];
r[16]=0x0c0aa4cau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa4cau) { target=s->pc; goto dispatch; }
goto P_0c0aa4ca;
P_0c0aa4c8: /* original 64e3, guest PC 0x0c0aa4c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa4c8u; return 0; }
r[4]=r[14];
goto P_0c0aa4ca;
P_0c0aa4ca: /* original 52d1, guest PC 0x0c0aa4ca */
if(!s->budget--) { s->failed_pc=0x0c0aa4cau; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0aa4cc;
P_0c0aa4cc: /* original e062, guest PC 0x0c0aa4cc */
if(!s->budget--) { s->failed_pc=0x0c0aa4ccu; return 0; }
r[0]=0x00000062u;
goto P_0c0aa4ce;
P_0c0aa4ce: /* original 7201, guest PC 0x0c0aa4ce */
if(!s->budget--) { s->failed_pc=0x0c0aa4ceu; return 0; }
r[2]+=0x00000001u;
goto P_0c0aa4d0;
P_0c0aa4d0: /* original 6323, guest PC 0x0c0aa4d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa4d0u; return 0; }
r[3]=r[2];
goto P_0c0aa4d2;
P_0c0aa4d2: /* original 1d21, guest PC 0x0c0aa4d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa4d2u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0aa4d4;
P_0c0aa4d4: /* original 0e34, guest PC 0x0c0aa4d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa4d4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0aa4d6;
P_0c0aa4d6: /* original e03c, guest PC 0x0c0aa4d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa4d6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa4d8;
P_0c0aa4d8: /* original 04ed, guest PC 0x0c0aa4d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa4d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa4da;
P_0c0aa4da: /* original 644d, guest PC 0x0c0aa4da */
if(!s->budget--) { s->failed_pc=0x0c0aa4dau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa4dc;
P_0c0aa4dc: /* original 2448, guest PC 0x0c0aa4dc */
if(!s->budget--) { s->failed_pc=0x0c0aa4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0aa4de;
P_0c0aa4de: /* original 8b00, guest PC 0x0c0aa4de */
if(!s->budget--) { s->failed_pc=0x0c0aa4deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa4e2; }
goto P_0c0aa4e0;
P_0c0aa4e0: /* original 1e4e, guest PC 0x0c0aa4e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa4e0u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c0aa4e2;
P_0c0aa4e2: /* original 4f26, guest PC 0x0c0aa4e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa4e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa4e4;
P_0c0aa4e4: /* original 6df6, guest PC 0x0c0aa4e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa4e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aa4e6;
P_0c0aa4e6: /* original 000b, guest PC 0x0c0aa4e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa4e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aa4e8: /* original 6ef6, guest PC 0x0c0aa4e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa4e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aa4eau,s,ram);
P_0c0abe84: /* original 4f22, guest PC 0x0c0abe84 */
if(!s->budget--) { s->failed_pc=0x0c0abe84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abe86;
P_0c0abe86: /* original 6362, guest PC 0x0c0abe86 */
if(!s->budget--) { s->failed_pc=0x0c0abe86u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c0abe88;
P_0c0abe88: /* original 7ff4, guest PC 0x0c0abe88 */
if(!s->budget--) { s->failed_pc=0x0c0abe88u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0abe8a;
P_0c0abe8a: /* original 1f31, guest PC 0x0c0abe8a */
if(!s->budget--) { s->failed_pc=0x0c0abe8au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0abe8c;
P_0c0abe8c: /* original 65f3, guest PC 0x0c0abe8c */
if(!s->budget--) { s->failed_pc=0x0c0abe8cu; return 0; }
r[5]=r[15];
goto P_0c0abe8e;
P_0c0abe8e: /* original 5261, guest PC 0x0c0abe8e */
if(!s->budget--) { s->failed_pc=0x0c0abe8eu; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c0abe90;
P_0c0abe90: /* original 1f22, guest PC 0x0c0abe90 */
if(!s->budget--) { s->failed_pc=0x0c0abe90u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0abe92;
P_0c0abe92: /* original 5361, guest PC 0x0c0abe92 */
if(!s->budget--) { s->failed_pc=0x0c0abe92u; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c0abe94;
P_0c0abe94: /* original d029, guest PC 0x0c0abe94 */
if(!s->budget--) { s->failed_pc=0x0c0abe94u; return 0; }
r[0]=read(ram,0x0c0abf3cu,4);
goto P_0c0abe96;
P_0c0abe96: /* original 4308, guest PC 0x0c0abe96 */
if(!s->budget--) { s->failed_pc=0x0c0abe96u; return 0; }
r[3]<<=2;
goto P_0c0abe98;
P_0c0abe98: /* original 023e, guest PC 0x0c0abe98 */
if(!s->budget--) { s->failed_pc=0x0c0abe98u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0abe9a;
P_0c0abe9a: /* original 2f22, guest PC 0x0c0abe9a */
if(!s->budget--) { s->failed_pc=0x0c0abe9au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0abe9c;
P_0c0abe9c: /* original 420b, guest PC 0x0c0abe9c */
if(!s->budget--) { s->failed_pc=0x0c0abe9cu; return 0; }
target=r[2];
r[16]=0x0c0abea0u;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abea0u) { target=s->pc; goto dispatch; }
goto P_0c0abea0;
P_0c0abe9e: /* original 7504, guest PC 0x0c0abe9e */
if(!s->budget--) { s->failed_pc=0x0c0abe9eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0abea0;
P_0c0abea0: /* original 7f0c, guest PC 0x0c0abea0 */
if(!s->budget--) { s->failed_pc=0x0c0abea0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0abea2;
P_0c0abea2: /* original 4f26, guest PC 0x0c0abea2 */
if(!s->budget--) { s->failed_pc=0x0c0abea2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abea4;
P_0c0abea4: /* original 000b, guest PC 0x0c0abea4 */
if(!s->budget--) { s->failed_pc=0x0c0abea4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0abea6: /* original 0009, guest PC 0x0c0abea6 */
if(!s->budget--) { s->failed_pc=0x0c0abea6u; return 0; }
return vf3_matrix_family(0x0c0abea8u,s,ram);
P_0c0ac1e4: /* original 4f22, guest PC 0x0c0ac1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac1e6;
P_0c0ac1e6: /* original 02ed, guest PC 0x0c0ac1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e8;
P_0c0ac1e8: /* original 3322, guest PC 0x0c0ac1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac1ea;
P_0c0ac1ea: /* original 8b1b, guest PC 0x0c0ac1ea */
if(!s->budget--) { s->failed_pc=0x0c0ac1eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac224; }
goto P_0c0ac1ec;
P_0c0ac1ec: /* original e048, guest PC 0x0c0ac1ec */
if(!s->budget--) { s->failed_pc=0x0c0ac1ecu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1ee;
P_0c0ac1ee: /* original d32c, guest PC 0x0c0ac1ee */
if(!s->budget--) { s->failed_pc=0x0c0ac1eeu; return 0; }
r[3]=read(ram,0x0c0ac2a0u,4);
goto P_0c0ac1f0;
P_0c0ac1f0: /* original 02ee, guest PC 0x0c0ac1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac1f2;
P_0c0ac1f2: /* original 2238, guest PC 0x0c0ac1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac1f4;
P_0c0ac1f4: /* original 8908, guest PC 0x0c0ac1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac208; }
goto P_0c0ac1f6;
P_0c0ac1f6: /* original 61e2, guest PC 0x0c0ac1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac1f8;
P_0c0ac1f8: /* original e000, guest PC 0x0c0ac1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f8u; return 0; }
r[0]=0x00000000u;
goto P_0c0ac1fa;
P_0c0ac1fa: /* original d22a, guest PC 0x0c0ac1fa */
if(!s->budget--) { s->failed_pc=0x0c0ac1fau; return 0; }
r[2]=read(ram,0x0c0ac2a4u,4);
goto P_0c0ac1fc;
P_0c0ac1fc: /* original 4f26, guest PC 0x0c0ac1fc */
if(!s->budget--) { s->failed_pc=0x0c0ac1fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1fe;
P_0c0ac1fe: /* original 2129, guest PC 0x0c0ac1fe */
if(!s->budget--) { s->failed_pc=0x0c0ac1feu; return 0; }
r[1]&=r[2];
goto P_0c0ac200;
P_0c0ac200: /* original 2e12, guest PC 0x0c0ac200 */
if(!s->budget--) { s->failed_pc=0x0c0ac200u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ac202;
P_0c0ac202: /* original 1e0e, guest PC 0x0c0ac202 */
if(!s->budget--) { s->failed_pc=0x0c0ac202u; return 0; }
write(ram,r[14]+56,r[0],4);
goto P_0c0ac204;
P_0c0ac204: /* original 000b, guest PC 0x0c0ac204 */
if(!s->budget--) { s->failed_pc=0x0c0ac204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac206: /* original 6ef6, guest PC 0x0c0ac206 */
if(!s->budget--) { s->failed_pc=0x0c0ac206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac208;
P_0c0ac208: /* original 61e2, guest PC 0x0c0ac208 */
if(!s->budget--) { s->failed_pc=0x0c0ac208u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac20a;
P_0c0ac20a: /* original d224, guest PC 0x0c0ac20a */
if(!s->budget--) { s->failed_pc=0x0c0ac20au; return 0; }
r[2]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac20c;
P_0c0ac20c: /* original 2128, guest PC 0x0c0ac20c */
if(!s->budget--) { s->failed_pc=0x0c0ac20cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac20e;
P_0c0ac20e: /* original 8907, guest PC 0x0c0ac20e */
if(!s->budget--) { s->failed_pc=0x0c0ac20eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac220; }
goto P_0c0ac210;
P_0c0ac210: /* original d125, guest PC 0x0c0ac210 */
if(!s->budget--) { s->failed_pc=0x0c0ac210u; return 0; }
r[1]=read(ram,0x0c0ac2a8u,4);
goto P_0c0ac212;
P_0c0ac212: /* original 410b, guest PC 0x0c0ac212 */
if(!s->budget--) { s->failed_pc=0x0c0ac212u; return 0; }
target=r[1];
r[16]=0x0c0ac216u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac216u) { target=s->pc; goto dispatch; }
goto P_0c0ac216;
P_0c0ac214: /* original 64e3, guest PC 0x0c0ac214 */
if(!s->budget--) { s->failed_pc=0x0c0ac214u; return 0; }
r[4]=r[14];
goto P_0c0ac216;
P_0c0ac216: /* original 4f26, guest PC 0x0c0ac216 */
if(!s->budget--) { s->failed_pc=0x0c0ac216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac218;
P_0c0ac218: /* original d324, guest PC 0x0c0ac218 */
if(!s->budget--) { s->failed_pc=0x0c0ac218u; return 0; }
r[3]=read(ram,0x0c0ac2acu,4);
goto P_0c0ac21a;
P_0c0ac21a: /* original 1e3d, guest PC 0x0c0ac21a */
if(!s->budget--) { s->failed_pc=0x0c0ac21au; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ac21c;
P_0c0ac21c: /* original 000b, guest PC 0x0c0ac21c */
if(!s->budget--) { s->failed_pc=0x0c0ac21cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac21e: /* original 6ef6, guest PC 0x0c0ac21e */
if(!s->budget--) { s->failed_pc=0x0c0ac21eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac220;
P_0c0ac220: /* original d123, guest PC 0x0c0ac220 */
if(!s->budget--) { s->failed_pc=0x0c0ac220u; return 0; }
r[1]=read(ram,0x0c0ac2b0u,4);
goto P_0c0ac222;
P_0c0ac222: /* original 1e1d, guest PC 0x0c0ac222 */
if(!s->budget--) { s->failed_pc=0x0c0ac222u; return 0; }
write(ram,r[14]+52,r[1],4);
goto P_0c0ac224;
P_0c0ac224: /* original 4f26, guest PC 0x0c0ac224 */
if(!s->budget--) { s->failed_pc=0x0c0ac224u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac226;
P_0c0ac226: /* original 000b, guest PC 0x0c0ac226 */
if(!s->budget--) { s->failed_pc=0x0c0ac226u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac228: /* original 6ef6, guest PC 0x0c0ac228 */
if(!s->budget--) { s->failed_pc=0x0c0ac228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac22au,s,ram);
P_0c0b1b34: /* original 4f22, guest PC 0x0c0b1b34 */
if(!s->budget--) { s->failed_pc=0x0c0b1b34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1b36;
P_0c0b1b36: /* original 7ffc, guest PC 0x0c0b1b36 */
if(!s->budget--) { s->failed_pc=0x0c0b1b36u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b1b38;
P_0c0b1b38: /* original 2f42, guest PC 0x0c0b1b38 */
if(!s->budget--) { s->failed_pc=0x0c0b1b38u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0b1b3a;
P_0c0b1b3a: /* original e411, guest PC 0x0c0b1b3a */
if(!s->budget--) { s->failed_pc=0x0c0b1b3au; return 0; }
r[4]=0x00000011u;
goto P_0c0b1b3c;
P_0c0b1b3c: /* original 3546, guest PC 0x0c0b1b3c */
if(!s->budget--) { s->failed_pc=0x0c0b1b3cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c0b1b3e;
P_0c0b1b3e: /* original 8f01, guest PC 0x0c0b1b3e */
if(!s->budget--) { s->failed_pc=0x0c0b1b3eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c0b1b44; }
goto P_0c0b1b42;
P_0c0b1b40: /* original e600, guest PC 0x0c0b1b40 */
if(!s->budget--) { s->failed_pc=0x0c0b1b40u; return 0; }
r[6]=0x00000000u;
goto P_0c0b1b42;
P_0c0b1b42: /* original 6543, guest PC 0x0c0b1b42 */
if(!s->budget--) { s->failed_pc=0x0c0b1b42u; return 0; }
r[5]=r[4];
goto P_0c0b1b44;
P_0c0b1b44: /* original d00c, guest PC 0x0c0b1b44 */
if(!s->budget--) { s->failed_pc=0x0c0b1b44u; return 0; }
r[0]=read(ram,0x0c0b1b78u,4);
goto P_0c0b1b46;
P_0c0b1b46: /* original 6c53, guest PC 0x0c0b1b46 */
if(!s->budget--) { s->failed_pc=0x0c0b1b46u; return 0; }
r[12]=r[5];
goto P_0c0b1b48;
P_0c0b1b48: /* original 4c08, guest PC 0x0c0b1b48 */
if(!s->budget--) { s->failed_pc=0x0c0b1b48u; return 0; }
r[12]<<=2;
goto P_0c0b1b4a;
P_0c0b1b4a: /* original 6d63, guest PC 0x0c0b1b4a */
if(!s->budget--) { s->failed_pc=0x0c0b1b4au; return 0; }
r[13]=r[6];
goto P_0c0b1b4c;
P_0c0b1b4c: /* original 0cce, guest PC 0x0c0b1b4c */
if(!s->budget--) { s->failed_pc=0x0c0b1b4cu; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c0b1b4e;
P_0c0b1b4e: /* original 60d3, guest PC 0x0c0b1b4e */
if(!s->budget--) { s->failed_pc=0x0c0b1b4eu; return 0; }
r[0]=r[13];
goto P_0c0b1b50;
P_0c0b1b50: /* original 4008, guest PC 0x0c0b1b50 */
if(!s->budget--) { s->failed_pc=0x0c0b1b50u; return 0; }
r[0]<<=2;
goto P_0c0b1b52;
P_0c0b1b52: /* original 0ece, guest PC 0x0c0b1b52 */
if(!s->budget--) { s->failed_pc=0x0c0b1b52u; return 0; }
r[14]=read(ram,r[12]+r[0],4);
goto P_0c0b1b54;
P_0c0b1b54: /* original 2ee8, guest PC 0x0c0b1b54 */
if(!s->budget--) { s->failed_pc=0x0c0b1b54u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0b1b56;
P_0c0b1b56: /* original 8903, guest PC 0x0c0b1b56 */
if(!s->budget--) { s->failed_pc=0x0c0b1b56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b60; }
goto P_0c0b1b58;
P_0c0b1b58: /* original 4e0b, guest PC 0x0c0b1b58 */
if(!s->budget--) { s->failed_pc=0x0c0b1b58u; return 0; }
target=r[14];
r[16]=0x0c0b1b5cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b1b5cu) { target=s->pc; goto dispatch; }
goto P_0c0b1b5c;
P_0c0b1b5a: /* original 64f2, guest PC 0x0c0b1b5a */
if(!s->budget--) { s->failed_pc=0x0c0b1b5au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1b5c;
P_0c0b1b5c: /* original aff7, guest PC 0x0c0b1b5c */
if(!s->budget--) { s->failed_pc=0x0c0b1b5cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1b4e;
P_0c0b1b5e: /* original 7d01, guest PC 0x0c0b1b5e */
if(!s->budget--) { s->failed_pc=0x0c0b1b5eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1b60;
P_0c0b1b60: /* original 7f04, guest PC 0x0c0b1b60 */
if(!s->budget--) { s->failed_pc=0x0c0b1b60u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b1b62;
P_0c0b1b62: /* original 4f26, guest PC 0x0c0b1b62 */
if(!s->budget--) { s->failed_pc=0x0c0b1b62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1b64;
P_0c0b1b64: /* original 6cf6, guest PC 0x0c0b1b64 */
if(!s->budget--) { s->failed_pc=0x0c0b1b64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1b66;
P_0c0b1b66: /* original 6df6, guest PC 0x0c0b1b66 */
if(!s->budget--) { s->failed_pc=0x0c0b1b66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1b68;
P_0c0b1b68: /* original 000b, guest PC 0x0c0b1b68 */
if(!s->budget--) { s->failed_pc=0x0c0b1b68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1b6a: /* original 6ef6, guest PC 0x0c0b1b6a */
if(!s->budget--) { s->failed_pc=0x0c0b1b6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b1b6cu,s,ram);
P_0c0b1c94: /* original 4f22, guest PC 0x0c0b1c94 */
if(!s->budget--) { s->failed_pc=0x0c0b1c94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1c96;
P_0c0b1c96: /* original 7fbc, guest PC 0x0c0b1c96 */
if(!s->budget--) { s->failed_pc=0x0c0b1c96u; return 0; }
r[15]+=0xffffffbcu;
goto P_0c0b1c98;
P_0c0b1c98: /* original 2f42, guest PC 0x0c0b1c98 */
if(!s->budget--) { s->failed_pc=0x0c0b1c98u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0b1c9a;
P_0c0b1c9a: /* original 9029, guest PC 0x0c0b1c9a */
if(!s->budget--) { s->failed_pc=0x0c0b1c9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf0u,2);
goto P_0c0b1c9c;
P_0c0b1c9c: /* original d31d, guest PC 0x0c0b1c9c */
if(!s->budget--) { s->failed_pc=0x0c0b1c9cu; return 0; }
r[3]=read(ram,0x0c0b1d14u,4);
goto P_0c0b1c9e;
P_0c0b1c9e: /* original 044d, guest PC 0x0c0b1c9e */
if(!s->budget--) { s->failed_pc=0x0c0b1c9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b1ca0;
P_0c0b1ca0: /* original 6e4d, guest PC 0x0c0b1ca0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca0u; return 0; }
r[14]=r[4]&65535u;
goto P_0c0b1ca2;
P_0c0b1ca2: /* original 3e30, guest PC 0x0c0b1ca2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c0b1ca4;
P_0c0b1ca4: /* original 890a, guest PC 0x0c0b1ca4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1cbc; }
goto P_0c0b1ca6;
P_0c0b1ca6: /* original d214, guest PC 0x0c0b1ca6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca6u; return 0; }
r[2]=read(ram,0x0c0b1cf8u,4);
goto P_0c0b1ca8;
P_0c0b1ca8: /* original 9323, guest PC 0x0c0b1ca8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf2u,2);
goto P_0c0b1caa;
P_0c0b1caa: /* original 64f2, guest PC 0x0c0b1caa */
if(!s->budget--) { s->failed_pc=0x0c0b1caau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1cac;
P_0c0b1cac: /* original 420b, guest PC 0x0c0b1cac */
if(!s->budget--) { s->failed_pc=0x0c0b1cacu; return 0; }
target=r[2];
r[16]=0x0c0b1cb0u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b1cb0u) { target=s->pc; goto dispatch; }
goto P_0c0b1cb0;
P_0c0b1cae: /* original 343c, guest PC 0x0c0b1cae */
if(!s->budget--) { s->failed_pc=0x0c0b1caeu; return 0; }
r[4]+=r[3];
goto P_0c0b1cb0;
P_0c0b1cb0: /* original 7f44, guest PC 0x0c0b1cb0 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb0u; return 0; }
r[15]+=0x00000044u;
goto P_0c0b1cb2;
P_0c0b1cb2: /* original d317, guest PC 0x0c0b1cb2 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb2u; return 0; }
r[3]=read(ram,0x0c0b1d10u,4);
goto P_0c0b1cb4;
P_0c0b1cb4: /* original 4f26, guest PC 0x0c0b1cb4 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1cb6;
P_0c0b1cb6: /* original 64e3, guest PC 0x0c0b1cb6 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb6u; return 0; }
r[4]=r[14];
goto P_0c0b1cb8;
P_0c0b1cb8: /* original 432b, guest PC 0x0c0b1cb8 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb8u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0b1cba: /* original 6ef6, guest PC 0x0c0b1cba */
if(!s->budget--) { s->failed_pc=0x0c0b1cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0b1cbc;
P_0c0b1cbc: /* original 7f44, guest PC 0x0c0b1cbc */
if(!s->budget--) { s->failed_pc=0x0c0b1cbcu; return 0; }
r[15]+=0x00000044u;
goto P_0c0b1cbe;
P_0c0b1cbe: /* original 4f26, guest PC 0x0c0b1cbe */
if(!s->budget--) { s->failed_pc=0x0c0b1cbeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1cc0;
P_0c0b1cc0: /* original 000b, guest PC 0x0c0b1cc0 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1cc2: /* original 6ef6, guest PC 0x0c0b1cc2 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b1cc4u,s,ram);
P_0c0c12a4: /* original 4f22, guest PC 0x0c0c12a4 */
if(!s->budget--) { s->failed_pc=0x0c0c12a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c12a6;
P_0c0c12a6: /* original 7ffc, guest PC 0x0c0c12a6 */
if(!s->budget--) { s->failed_pc=0x0c0c12a6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c12a8;
P_0c0c12a8: /* original 2f42, guest PC 0x0c0c12a8 */
if(!s->budget--) { s->failed_pc=0x0c0c12a8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c12aa;
P_0c0c12aa: /* original 5ee3, guest PC 0x0c0c12aa */
if(!s->budget--) { s->failed_pc=0x0c0c12aau; return 0; }
r[14]=read(ram,r[14]+12,4);
goto P_0c0c12ac;
P_0c0c12ac: /* original db0f, guest PC 0x0c0c12ac */
if(!s->budget--) { s->failed_pc=0x0c0c12acu; return 0; }
r[11]=read(ram,0x0c0c12ecu,4);
goto P_0c0c12ae;
P_0c0c12ae: /* original e500, guest PC 0x0c0c12ae */
if(!s->budget--) { s->failed_pc=0x0c0c12aeu; return 0; }
r[5]=0x00000000u;
goto P_0c0c12b0;
P_0c0c12b0: /* original e644, guest PC 0x0c0c12b0 */
if(!s->budget--) { s->failed_pc=0x0c0c12b0u; return 0; }
r[6]=0x00000044u;
goto P_0c0c12b2;
P_0c0c12b2: /* original 4b0b, guest PC 0x0c0c12b2 */
if(!s->budget--) { s->failed_pc=0x0c0c12b2u; return 0; }
target=r[11];
r[16]=0x0c0c12b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c12b6u) { target=s->pc; goto dispatch; }
goto P_0c0c12b6;
P_0c0c12b4: /* original 64e3, guest PC 0x0c0c12b4 */
if(!s->budget--) { s->failed_pc=0x0c0c12b4u; return 0; }
r[4]=r[14];
goto P_0c0c12b6;
P_0c0c12b6: /* original 7d01, guest PC 0x0c0c12b6 */
if(!s->budget--) { s->failed_pc=0x0c0c12b6u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c12b8;
P_0c0c12b8: /* original 3dc2, guest PC 0x0c0c12b8 */
if(!s->budget--) { s->failed_pc=0x0c0c12b8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[12])!=0);
goto P_0c0c12ba;
P_0c0c12ba: /* original 8ff8, guest PC 0x0c0c12ba */
if(!s->budget--) { s->failed_pc=0x0c0c12bau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(!cond) { goto P_0c0c12ae; }
goto P_0c0c12be;
P_0c0c12bc: /* original 7e44, guest PC 0x0c0c12bc */
if(!s->budget--) { s->failed_pc=0x0c0c12bcu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c12be;
P_0c0c12be: /* original 63f2, guest PC 0x0c0c12be */
if(!s->budget--) { s->failed_pc=0x0c0c12beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c12c0;
P_0c0c12c0: /* original 7f04, guest PC 0x0c0c12c0 */
if(!s->budget--) { s->failed_pc=0x0c0c12c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c12c2;
P_0c0c12c2: /* original 4f26, guest PC 0x0c0c12c2 */
if(!s->budget--) { s->failed_pc=0x0c0c12c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c12c4;
P_0c0c12c4: /* original e022, guest PC 0x0c0c12c4 */
if(!s->budget--) { s->failed_pc=0x0c0c12c4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c12c6;
P_0c0c12c6: /* original 013d, guest PC 0x0c0c12c6 */
if(!s->budget--) { s->failed_pc=0x0c0c12c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c12c8;
P_0c0c12c8: /* original e201, guest PC 0x0c0c12c8 */
if(!s->budget--) { s->failed_pc=0x0c0c12c8u; return 0; }
r[2]=0x00000001u;
goto P_0c0c12ca;
P_0c0c12ca: /* original 212b, guest PC 0x0c0c12ca */
if(!s->budget--) { s->failed_pc=0x0c0c12cau; return 0; }
r[1]|=r[2];
goto P_0c0c12cc;
P_0c0c12cc: /* original 0315, guest PC 0x0c0c12cc */
if(!s->budget--) { s->failed_pc=0x0c0c12ccu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c12ce;
P_0c0c12ce: /* original 6bf6, guest PC 0x0c0c12ce */
if(!s->budget--) { s->failed_pc=0x0c0c12ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c12d0;
P_0c0c12d0: /* original 6cf6, guest PC 0x0c0c12d0 */
if(!s->budget--) { s->failed_pc=0x0c0c12d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c12d2;
P_0c0c12d2: /* original 6df6, guest PC 0x0c0c12d2 */
if(!s->budget--) { s->failed_pc=0x0c0c12d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c12d4;
P_0c0c12d4: /* original 000b, guest PC 0x0c0c12d4 */
if(!s->budget--) { s->failed_pc=0x0c0c12d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c12d6: /* original 6ef6, guest PC 0x0c0c12d6 */
if(!s->budget--) { s->failed_pc=0x0c0c12d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c12d8u,s,ram);
P_0c0c1d86: /* original 2fe6, guest PC 0x0c0c1d86 */
if(!s->budget--) { s->failed_pc=0x0c0c1d86u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1d88;
P_0c0c1d88: /* original 6e43, guest PC 0x0c0c1d88 */
if(!s->budget--) { s->failed_pc=0x0c0c1d88u; return 0; }
r[14]=r[4];
goto P_0c0c1d8a;
P_0c0c1d8a: /* original 2fd6, guest PC 0x0c0c1d8a */
if(!s->budget--) { s->failed_pc=0x0c0c1d8au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c1d8c;
P_0c0c1d8c: /* original e026, guest PC 0x0c0c1d8c */
if(!s->budget--) { s->failed_pc=0x0c0c1d8cu; return 0; }
r[0]=0x00000026u;
goto P_0c0c1d8e;
P_0c0c1d8e: /* original 2fc6, guest PC 0x0c0c1d8e */
if(!s->budget--) { s->failed_pc=0x0c0c1d8eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c1d90;
P_0c0c1d90: /* original e67f, guest PC 0x0c0c1d90 */
if(!s->budget--) { s->failed_pc=0x0c0c1d90u; return 0; }
r[6]=0x0000007fu;
goto P_0c0c1d92;
P_0c0c1d92: /* original 2fb6, guest PC 0x0c0c1d92 */
if(!s->budget--) { s->failed_pc=0x0c0c1d92u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c1d94;
P_0c0c1d94: /* original 2fa6, guest PC 0x0c0c1d94 */
if(!s->budget--) { s->failed_pc=0x0c0c1d94u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c1d96;
P_0c0c1d96: /* original 2f96, guest PC 0x0c0c1d96 */
if(!s->budget--) { s->failed_pc=0x0c0c1d96u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c1d98;
P_0c0c1d98: /* original 2f86, guest PC 0x0c0c1d98 */
if(!s->budget--) { s->failed_pc=0x0c0c1d98u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c1d9a;
P_0c0c1d9a: /* original fffb, guest PC 0x0c0c1d9a */
if(!s->budget--) { s->failed_pc=0x0c0c1d9au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1d9c;
P_0c0c1d9c: /* original ffeb, guest PC 0x0c0c1d9c */
if(!s->budget--) { s->failed_pc=0x0c0c1d9cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1d9e;
P_0c0c1d9e: /* original ffdb, guest PC 0x0c0c1d9e */
if(!s->budget--) { s->failed_pc=0x0c0c1d9eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1da0;
P_0c0c1da0: /* original ffcb, guest PC 0x0c0c1da0 */
if(!s->budget--) { s->failed_pc=0x0c0c1da0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1da2;
P_0c0c1da2: /* original 03ed, guest PC 0x0c0c1da2 */
if(!s->budget--) { s->failed_pc=0x0c0c1da2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1da4;
P_0c0c1da4: /* original d01c, guest PC 0x0c0c1da4 */
if(!s->budget--) { s->failed_pc=0x0c0c1da4u; return 0; }
r[0]=read(ram,0x0c0c1e18u,4);
goto P_0c0c1da6;
P_0c0c1da6: /* original 4f22, guest PC 0x0c0c1da6 */
if(!s->budget--) { s->failed_pc=0x0c0c1da6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1da8;
P_0c0c1da8: /* original dc1a, guest PC 0x0c0c1da8 */
if(!s->budget--) { s->failed_pc=0x0c0c1da8u; return 0; }
r[12]=read(ram,0x0c0c1e14u,4);
goto P_0c0c1daa;
P_0c0c1daa: /* original 633d, guest PC 0x0c0c1daa */
if(!s->budget--) { s->failed_pc=0x0c0c1daau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1dac;
P_0c0c1dac: /* original 4308, guest PC 0x0c0c1dac */
if(!s->budget--) { s->failed_pc=0x0c0c1dacu; return 0; }
r[3]<<=2;
goto P_0c0c1dae;
P_0c0c1dae: /* original 64c3, guest PC 0x0c0c1dae */
if(!s->budget--) { s->failed_pc=0x0c0c1daeu; return 0; }
r[4]=r[12];
goto P_0c0c1db0;
P_0c0c1db0: /* original fe36, guest PC 0x0c0c1db0 */
if(!s->budget--) { s->failed_pc=0x0c0c1db0u; return 0; }
vf3_matrix_load(s,ram,14,r[3]+r[0]);
goto P_0c0c1db2;
P_0c0c1db2: /* original 67c3, guest PC 0x0c0c1db2 */
if(!s->budget--) { s->failed_pc=0x0c0c1db2u; return 0; }
r[7]=r[12];
goto P_0c0c1db4;
P_0c0c1db4: /* original 65c3, guest PC 0x0c0c1db4 */
if(!s->budget--) { s->failed_pc=0x0c0c1db4u; return 0; }
r[5]=r[12];
goto P_0c0c1db6;
P_0c0c1db6: /* original 3e40, guest PC 0x0c0c1db6 */
if(!s->budget--) { s->failed_pc=0x0c0c1db6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c0c1db8;
P_0c0c1db8: /* original c718, guest PC 0x0c0c1db8 */
if(!s->budget--) { s->failed_pc=0x0c0c1db8u; return 0; }
r[0]=0x0c0c1e1cu;
goto P_0c0c1dba;
P_0c0c1dba: /* original 7fc8, guest PC 0x0c0c1dba */
if(!s->budget--) { s->failed_pc=0x0c0c1dbau; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0c1dbc;
P_0c0c1dbc: /* original 752c, guest PC 0x0c0c1dbc */
if(!s->budget--) { s->failed_pc=0x0c0c1dbcu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0c1dbe;
P_0c0c1dbe: /* original 7758, guest PC 0x0c0c1dbe */
if(!s->budget--) { s->failed_pc=0x0c0c1dbeu; return 0; }
r[7]+=0x00000058u;
goto P_0c0c1dc0;
P_0c0c1dc0: /* original 8d02, guest PC 0x0c0c1dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0c1dc8; }
goto P_0c0c1dc4;
P_0c0c1dc2: /* original f408, guest PC 0x0c0c1dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c1dc4;
P_0c0c1dc4: /* original 3e50, guest PC 0x0c0c1dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[5])!=0);
goto P_0c0c1dc6;
P_0c0c1dc6: /* original 8b0f, guest PC 0x0c0c1dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1de8; }
goto P_0c0c1dc8;
P_0c0c1dc8: /* original 9014, guest PC 0x0c0c1dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1df4u,2);
goto P_0c0c1dca;
P_0c0c1dca: /* original 04ce, guest PC 0x0c0c1dca */
if(!s->budget--) { s->failed_pc=0x0c0c1dcau; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c1dcc;
P_0c0c1dcc: /* original 2448, guest PC 0x0c0c1dcc */
if(!s->budget--) { s->failed_pc=0x0c0c1dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1dce;
P_0c0c1dce: /* original 890f, guest PC 0x0c0c1dce */
if(!s->budget--) { s->failed_pc=0x0c0c1dceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1df0; }
goto P_0c0c1dd0;
P_0c0c1dd0: /* original 2469, guest PC 0x0c0c1dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd0u; return 0; }
r[4]&=r[6];
goto P_0c0c1dd2;
P_0c0c1dd2: /* original 644b, guest PC 0x0c0c1dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd2u; return 0; }
r[4]=0u-r[4];
goto P_0c0c1dd4;
P_0c0c1dd4: /* original 747f, guest PC 0x0c0c1dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd4u; return 0; }
r[4]+=0x0000007fu;
goto P_0c0c1dd6;
P_0c0c1dd6: /* original 445a, guest PC 0x0c0c1dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd6u; return 0; }
r[53]=r[4];
goto P_0c0c1dd8;
P_0c0c1dd8: /* original 4411, guest PC 0x0c0c1dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c1dda;
P_0c0c1dda: /* original 8d2e, guest PC 0x0c0c1dda */
if(!s->budget--) { s->failed_pc=0x0c0c1ddau; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1e3a; }
goto P_0c0c1dde;
P_0c0c1ddc: /* original f32d, guest PC 0x0c0c1ddc */
if(!s->budget--) { s->failed_pc=0x0c0c1ddcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1dde;
P_0c0c1dde: /* original d210, guest PC 0x0c0c1dde */
if(!s->budget--) { s->failed_pc=0x0c0c1ddeu; return 0; }
r[2]=read(ram,0x0c0c1e20u,4);
goto P_0c0c1de0;
P_0c0c1de0: /* original 425a, guest PC 0x0c0c1de0 */
if(!s->budget--) { s->failed_pc=0x0c0c1de0u; return 0; }
r[53]=r[2];
goto P_0c0c1de2;
P_0c0c1de2: /* original f20d, guest PC 0x0c0c1de2 */
if(!s->budget--) { s->failed_pc=0x0c0c1de2u; return 0; }
fr[2]=r[53];
goto P_0c0c1de4;
P_0c0c1de4: /* original a029, guest PC 0x0c0c1de4 */
if(!s->budget--) { s->failed_pc=0x0c0c1de4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1e3a;
P_0c0c1de6: /* original f320, guest PC 0x0c0c1de6 */
if(!s->budget--) { s->failed_pc=0x0c0c1de6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1de8;
P_0c0c1de8: /* original 9005, guest PC 0x0c0c1de8 */
if(!s->budget--) { s->failed_pc=0x0c0c1de8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1df6u,2);
goto P_0c0c1dea;
P_0c0c1dea: /* original 04ce, guest PC 0x0c0c1dea */
if(!s->budget--) { s->failed_pc=0x0c0c1deau; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c1dec;
P_0c0c1dec: /* original 2448, guest PC 0x0c0c1dec */
if(!s->budget--) { s->failed_pc=0x0c0c1decu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1dee;
P_0c0c1dee: /* original 8b19, guest PC 0x0c0c1dee */
if(!s->budget--) { s->failed_pc=0x0c0c1deeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e24; }
goto P_0c0c1df0;
P_0c0c1df0: /* original a025, guest PC 0x0c0c1df0 */
if(!s->budget--) { s->failed_pc=0x0c0c1df0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c0c1e3e;
P_0c0c1df2: /* original ff9d, guest PC 0x0c0c1df2 */
if(!s->budget--) { s->failed_pc=0x0c0c1df2u; return 0; }
fr[15]=0x3f800000u;
return vf3_matrix_family(0x0c0c1df4u,s,ram);
P_0c0c1e24: /* original 2469, guest PC 0x0c0c1e24 */
if(!s->budget--) { s->failed_pc=0x0c0c1e24u; return 0; }
r[4]&=r[6];
goto P_0c0c1e26;
P_0c0c1e26: /* original 644b, guest PC 0x0c0c1e26 */
if(!s->budget--) { s->failed_pc=0x0c0c1e26u; return 0; }
r[4]=0u-r[4];
goto P_0c0c1e28;
P_0c0c1e28: /* original 747f, guest PC 0x0c0c1e28 */
if(!s->budget--) { s->failed_pc=0x0c0c1e28u; return 0; }
r[4]+=0x0000007fu;
goto P_0c0c1e2a;
P_0c0c1e2a: /* original 445a, guest PC 0x0c0c1e2a */
if(!s->budget--) { s->failed_pc=0x0c0c1e2au; return 0; }
r[53]=r[4];
goto P_0c0c1e2c;
P_0c0c1e2c: /* original 4411, guest PC 0x0c0c1e2c */
if(!s->budget--) { s->failed_pc=0x0c0c1e2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c1e2e;
P_0c0c1e2e: /* original 8d04, guest PC 0x0c0c1e2e */
if(!s->budget--) { s->failed_pc=0x0c0c1e2eu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1e3a; }
goto P_0c0c1e32;
P_0c0c1e30: /* original f32d, guest PC 0x0c0c1e30 */
if(!s->budget--) { s->failed_pc=0x0c0c1e30u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1e32;
P_0c0c1e32: /* original d346, guest PC 0x0c0c1e32 */
if(!s->budget--) { s->failed_pc=0x0c0c1e32u; return 0; }
r[3]=read(ram,0x0c0c1f4cu,4);
goto P_0c0c1e34;
P_0c0c1e34: /* original 435a, guest PC 0x0c0c1e34 */
if(!s->budget--) { s->failed_pc=0x0c0c1e34u; return 0; }
r[53]=r[3];
goto P_0c0c1e36;
P_0c0c1e36: /* original f20d, guest PC 0x0c0c1e36 */
if(!s->budget--) { s->failed_pc=0x0c0c1e36u; return 0; }
fr[2]=r[53];
goto P_0c0c1e38;
P_0c0c1e38: /* original f320, guest PC 0x0c0c1e38 */
if(!s->budget--) { s->failed_pc=0x0c0c1e38u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1e3a;
P_0c0c1e3a: /* original ff3c, guest PC 0x0c0c1e3a */
if(!s->budget--) { s->failed_pc=0x0c0c1e3au; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0c1e3c;
P_0c0c1e3c: /* original ff43, guest PC 0x0c0c1e3c */
if(!s->budget--) { s->failed_pc=0x0c0c1e3cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'/');
goto P_0c0c1e3e;
P_0c0c1e3e: /* original 3e70, guest PC 0x0c0c1e3e */
if(!s->budget--) { s->failed_pc=0x0c0c1e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[7])!=0);
goto P_0c0c1e40;
P_0c0c1e40: /* original 8f14, guest PC 0x0c0c1e40 */
if(!s->budget--) { s->failed_pc=0x0c0c1e40u; return 0; }
cond=r[17]&1u;
r[4]=0x00000002u;
if(!cond) { goto P_0c0c1e6c; }
goto P_0c0c1e44;
P_0c0c1e42: /* original e402, guest PC 0x0c0c1e42 */
if(!s->budget--) { s->failed_pc=0x0c0c1e42u; return 0; }
r[4]=0x00000002u;
goto P_0c0c1e44;
P_0c0c1e44: /* original 907f, guest PC 0x0c0c1e44 */
if(!s->budget--) { s->failed_pc=0x0c0c1e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f46u,2);
goto P_0c0c1e46;
P_0c0c1e46: /* original 05ce, guest PC 0x0c0c1e46 */
if(!s->budget--) { s->failed_pc=0x0c0c1e46u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0c1e48;
P_0c0c1e48: /* original 4511, guest PC 0x0c0c1e48 */
if(!s->budget--) { s->failed_pc=0x0c0c1e48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c1e4a;
P_0c0c1e4a: /* original 8b06, guest PC 0x0c0c1e4a */
if(!s->budget--) { s->failed_pc=0x0c0c1e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e5a; }
goto P_0c0c1e4c;
P_0c0c1e4c: /* original e210, guest PC 0x0c0c1e4c */
if(!s->budget--) { s->failed_pc=0x0c0c1e4cu; return 0; }
r[2]=0x00000010u;
goto P_0c0c1e4e;
P_0c0c1e4e: /* original 3527, guest PC 0x0c0c1e4e */
if(!s->budget--) { s->failed_pc=0x0c0c1e4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0c1e50;
P_0c0c1e50: /* original 8903, guest PC 0x0c0c1e50 */
if(!s->budget--) { s->failed_pc=0x0c0c1e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1e5a; }
goto P_0c0c1e52;
P_0c0c1e52: /* original bebd, guest PC 0x0c0c1e52 */
if(!s->budget--) { s->failed_pc=0x0c0c1e52u; return 0; }
target=0x0c0c1bd0u; r[16]=0x0c0c1e56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1e56u) { target=s->pc; goto dispatch; }
goto P_0c0c1e56;
P_0c0c1e54: /* original 64e3, guest PC 0x0c0c1e54 */
if(!s->budget--) { s->failed_pc=0x0c0c1e54u; return 0; }
r[4]=r[14];
goto P_0c0c1e56;
P_0c0c1e56: /* original a05e, guest PC 0x0c0c1e56 */
if(!s->budget--) { s->failed_pc=0x0c0c1e56u; return 0; }
goto P_0c0c1f16;
P_0c0c1e58: /* original 0009, guest PC 0x0c0c1e58 */
if(!s->budget--) { s->failed_pc=0x0c0c1e58u; return 0; }
goto P_0c0c1e5a;
P_0c0c1e5a: /* original 9075, guest PC 0x0c0c1e5a */
if(!s->budget--) { s->failed_pc=0x0c0c1e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f48u,2);
goto P_0c0c1e5c;
P_0c0c1e5c: /* original 02ce, guest PC 0x0c0c1e5c */
if(!s->budget--) { s->failed_pc=0x0c0c1e5cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c1e5e;
P_0c0c1e5e: /* original 2228, guest PC 0x0c0c1e5e */
if(!s->budget--) { s->failed_pc=0x0c0c1e5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c1e60;
P_0c0c1e60: /* original 8b09, guest PC 0x0c0c1e60 */
if(!s->budget--) { s->failed_pc=0x0c0c1e60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e76; }
goto P_0c0c1e62;
P_0c0c1e62: /* original e022, guest PC 0x0c0c1e62 */
if(!s->budget--) { s->failed_pc=0x0c0c1e62u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e64;
P_0c0c1e64: /* original 02ed, guest PC 0x0c0c1e64 */
if(!s->budget--) { s->failed_pc=0x0c0c1e64u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e66;
P_0c0c1e66: /* original 622d, guest PC 0x0c0c1e66 */
if(!s->budget--) { s->failed_pc=0x0c0c1e66u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1e68;
P_0c0c1e68: /* original 2248, guest PC 0x0c0c1e68 */
if(!s->budget--) { s->failed_pc=0x0c0c1e68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c1e6a;
P_0c0c1e6a: /* original 8954, guest PC 0x0c0c1e6a */
if(!s->budget--) { s->failed_pc=0x0c0c1e6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e6c;
P_0c0c1e6c: /* original e022, guest PC 0x0c0c1e6c */
if(!s->budget--) { s->failed_pc=0x0c0c1e6cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e6e;
P_0c0c1e6e: /* original 01ed, guest PC 0x0c0c1e6e */
if(!s->budget--) { s->failed_pc=0x0c0c1e6eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e70;
P_0c0c1e70: /* original 611d, guest PC 0x0c0c1e70 */
if(!s->budget--) { s->failed_pc=0x0c0c1e70u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1e72;
P_0c0c1e72: /* original 2148, guest PC 0x0c0c1e72 */
if(!s->budget--) { s->failed_pc=0x0c0c1e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0c1e74;
P_0c0c1e74: /* original 894f, guest PC 0x0c0c1e74 */
if(!s->budget--) { s->failed_pc=0x0c0c1e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e76;
P_0c0c1e76: /* original 85ea, guest PC 0x0c0c1e76 */
if(!s->budget--) { s->failed_pc=0x0c0c1e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0c1e78;
P_0c0c1e78: /* original e800, guest PC 0x0c0c1e78 */
if(!s->budget--) { s->failed_pc=0x0c0c1e78u; return 0; }
r[8]=0x00000000u;
goto P_0c0c1e7a;
P_0c0c1e7a: /* original d235, guest PC 0x0c0c1e7a */
if(!s->budget--) { s->failed_pc=0x0c0c1e7au; return 0; }
r[2]=read(ram,0x0c0c1f50u,4);
goto P_0c0c1e7c;
P_0c0c1e7c: /* original ea78, guest PC 0x0c0c1e7c */
if(!s->budget--) { s->failed_pc=0x0c0c1e7cu; return 0; }
r[10]=0x00000078u;
goto P_0c0c1e7e;
P_0c0c1e7e: /* original 6303, guest PC 0x0c0c1e7e */
if(!s->budget--) { s->failed_pc=0x0c0c1e7eu; return 0; }
r[3]=r[0];
goto P_0c0c1e80;
P_0c0c1e80: /* original 435a, guest PC 0x0c0c1e80 */
if(!s->budget--) { s->failed_pc=0x0c0c1e80u; return 0; }
r[53]=r[3];
goto P_0c0c1e82;
P_0c0c1e82: /* original f228, guest PC 0x0c0c1e82 */
if(!s->budget--) { s->failed_pc=0x0c0c1e82u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1e84;
P_0c0c1e84: /* original 6b83, guest PC 0x0c0c1e84 */
if(!s->budget--) { s->failed_pc=0x0c0c1e84u; return 0; }
r[11]=r[8];
goto P_0c0c1e86;
P_0c0c1e86: /* original 54e3, guest PC 0x0c0c1e86 */
if(!s->budget--) { s->failed_pc=0x0c0c1e86u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0c1e88;
P_0c0c1e88: /* original 3ba2, guest PC 0x0c0c1e88 */
if(!s->budget--) { s->failed_pc=0x0c0c1e88u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1e8a;
P_0c0c1e8a: /* original f32d, guest PC 0x0c0c1e8a */
if(!s->budget--) { s->failed_pc=0x0c0c1e8au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1e8c;
P_0c0c1e8c: /* original 6d43, guest PC 0x0c0c1e8c */
if(!s->budget--) { s->failed_pc=0x0c0c1e8cu; return 0; }
r[13]=r[4];
goto P_0c0c1e8e;
P_0c0c1e8e: /* original f322, guest PC 0x0c0c1e8e */
if(!s->budget--) { s->failed_pc=0x0c0c1e8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1e90;
P_0c0c1e90: /* original ff3a, guest PC 0x0c0c1e90 */
if(!s->budget--) { s->failed_pc=0x0c0c1e90u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1e92;
P_0c0c1e92: /* original 85eb, guest PC 0x0c0c1e92 */
if(!s->budget--) { s->failed_pc=0x0c0c1e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0c1e94;
P_0c0c1e94: /* original d12f, guest PC 0x0c0c1e94 */
if(!s->budget--) { s->failed_pc=0x0c0c1e94u; return 0; }
r[1]=read(ram,0x0c0c1f54u,4);
goto P_0c0c1e96;
P_0c0c1e96: /* original 6303, guest PC 0x0c0c1e96 */
if(!s->budget--) { s->failed_pc=0x0c0c1e96u; return 0; }
r[3]=r[0];
goto P_0c0c1e98;
P_0c0c1e98: /* original 435a, guest PC 0x0c0c1e98 */
if(!s->budget--) { s->failed_pc=0x0c0c1e98u; return 0; }
r[53]=r[3];
goto P_0c0c1e9a;
P_0c0c1e9a: /* original f218, guest PC 0x0c0c1e9a */
if(!s->budget--) { s->failed_pc=0x0c0c1e9au; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0c1e9c;
P_0c0c1e9c: /* original c72e, guest PC 0x0c0c1e9c */
if(!s->budget--) { s->failed_pc=0x0c0c1e9cu; return 0; }
r[0]=0x0c0c1f58u;
goto P_0c0c1e9e;
P_0c0c1e9e: /* original fcec, guest PC 0x0c0c1e9e */
if(!s->budget--) { s->failed_pc=0x0c0c1e9eu; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c0c1ea0;
P_0c0c1ea0: /* original f32d, guest PC 0x0c0c1ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1ea2;
P_0c0c1ea2: /* original fd3c, guest PC 0x0c0c1ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea2u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c1ea4;
P_0c0c1ea4: /* original fd22, guest PC 0x0c0c1ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'*');
goto P_0c0c1ea6;
P_0c0c1ea6: /* original f308, guest PC 0x0c0c1ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1ea8;
P_0c0c1ea8: /* original 8d2e, guest PC 0x0c0c1ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea8u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
if(cond) { goto P_0c0c1f08; }
goto P_0c0c1eac;
P_0c0c1eaa: /* original fc30, guest PC 0x0c0c1eaa */
if(!s->budget--) { s->failed_pc=0x0c0c1eaau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c1eac;
P_0c0c1eac: /* original e910, guest PC 0x0c0c1eac */
if(!s->budget--) { s->failed_pc=0x0c0c1eacu; return 0; }
r[9]=0x00000010u;
goto P_0c0c1eae;
P_0c0c1eae: /* original 60d1, guest PC 0x0c0c1eae */
if(!s->budget--) { s->failed_pc=0x0c0c1eaeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eb0;
P_0c0c1eb0: /* original 600d, guest PC 0x0c0c1eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eb2;
P_0c0c1eb2: /* original c801, guest PC 0x0c0c1eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0c1eb4;
P_0c0c1eb4: /* original 8924, guest PC 0x0c0c1eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f00; }
goto P_0c0c1eb6;
P_0c0c1eb6: /* original 65d3, guest PC 0x0c0c1eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb6u; return 0; }
r[5]=r[13];
goto P_0c0c1eb8;
P_0c0c1eb8: /* original d228, guest PC 0x0c0c1eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb8u; return 0; }
r[2]=read(ram,0x0c0c1f5cu,4);
goto P_0c0c1eba;
P_0c0c1eba: /* original 64f3, guest PC 0x0c0c1eba */
if(!s->budget--) { s->failed_pc=0x0c0c1ebau; return 0; }
r[4]=r[15];
goto P_0c0c1ebc;
P_0c0c1ebc: /* original e634, guest PC 0x0c0c1ebc */
if(!s->budget--) { s->failed_pc=0x0c0c1ebcu; return 0; }
r[6]=0x00000034u;
goto P_0c0c1ebe;
P_0c0c1ebe: /* original 7510, guest PC 0x0c0c1ebe */
if(!s->budget--) { s->failed_pc=0x0c0c1ebeu; return 0; }
r[5]+=0x00000010u;
goto P_0c0c1ec0;
P_0c0c1ec0: /* original 420b, guest PC 0x0c0c1ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec0u; return 0; }
target=r[2];
r[16]=0x0c0c1ec4u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1ec4u) { target=s->pc; goto dispatch; }
goto P_0c0c1ec4;
P_0c0c1ec2: /* original 7404, guest PC 0x0c0c1ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec2u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1ec4;
P_0c0c1ec4: /* original e008, guest PC 0x0c0c1ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ec6;
P_0c0c1ec6: /* original f3f8, guest PC 0x0c0c1ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1ec8;
P_0c0c1ec8: /* original f2f6, guest PC 0x0c0c1ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1eca;
P_0c0c1eca: /* original e008, guest PC 0x0c0c1eca */
if(!s->budget--) { s->failed_pc=0x0c0c1ecau; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ecc;
P_0c0c1ecc: /* original f231, guest PC 0x0c0c1ecc */
if(!s->budget--) { s->failed_pc=0x0c0c1eccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1ece;
P_0c0c1ece: /* original ff27, guest PC 0x0c0c1ece */
if(!s->budget--) { s->failed_pc=0x0c0c1eceu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed0;
P_0c0c1ed0: /* original e00c, guest PC 0x0c0c1ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed2;
P_0c0c1ed2: /* original f2f6, guest PC 0x0c0c1ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed4;
P_0c0c1ed4: /* original e00c, guest PC 0x0c0c1ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed6;
P_0c0c1ed6: /* original f2d0, guest PC 0x0c0c1ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c0c1ed8;
P_0c0c1ed8: /* original ff27, guest PC 0x0c0c1ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1eda;
P_0c0c1eda: /* original e010, guest PC 0x0c0c1eda */
if(!s->budget--) { s->failed_pc=0x0c0c1edau; return 0; }
r[0]=0x00000010u;
goto P_0c0c1edc;
P_0c0c1edc: /* original ffe7, guest PC 0x0c0c1edc */
if(!s->budget--) { s->failed_pc=0x0c0c1edcu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c1ede;
P_0c0c1ede: /* original 63d1, guest PC 0x0c0c1ede */
if(!s->budget--) { s->failed_pc=0x0c0c1edeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0c1ee0;
P_0c0c1ee0: /* original 633d, guest PC 0x0c0c1ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1ee2;
P_0c0c1ee2: /* original 2398, guest PC 0x0c0c1ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c1ee4;
P_0c0c1ee4: /* original 8901, guest PC 0x0c0c1ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1eea; }
goto P_0c0c1ee6;
P_0c0c1ee6: /* original e010, guest PC 0x0c0c1ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1ee8;
P_0c0c1ee8: /* original ffc7, guest PC 0x0c0c1ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee8u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0c1eea;
P_0c0c1eea: /* original 60d1, guest PC 0x0c0c1eea */
if(!s->budget--) { s->failed_pc=0x0c0c1eeau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eec;
P_0c0c1eec: /* original 600d, guest PC 0x0c0c1eec */
if(!s->budget--) { s->failed_pc=0x0c0c1eecu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eee;
P_0c0c1eee: /* original c820, guest PC 0x0c0c1eee */
if(!s->budget--) { s->failed_pc=0x0c0c1eeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0c1ef0;
P_0c0c1ef0: /* original 8b01, guest PC 0x0c0c1ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1ef6; }
goto P_0c0c1ef2;
P_0c0c1ef2: /* original e034, guest PC 0x0c0c1ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c1ef4;
P_0c0c1ef4: /* original fff7, guest PC 0x0c0c1ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c1ef6;
P_0c0c1ef6: /* original d31a, guest PC 0x0c0c1ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef6u; return 0; }
r[3]=read(ram,0x0c0c1f60u,4);
goto P_0c0c1ef8;
P_0c0c1ef8: /* original 64f3, guest PC 0x0c0c1ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef8u; return 0; }
r[4]=r[15];
goto P_0c0c1efa;
P_0c0c1efa: /* original 430b, guest PC 0x0c0c1efa */
if(!s->budget--) { s->failed_pc=0x0c0c1efau; return 0; }
target=r[3];
r[16]=0x0c0c1efeu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1efeu) { target=s->pc; goto dispatch; }
goto P_0c0c1efe;
P_0c0c1efc: /* original 7404, guest PC 0x0c0c1efc */
if(!s->budget--) { s->failed_pc=0x0c0c1efcu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1efe;
P_0c0c1efe: /* original 7801, guest PC 0x0c0c1efe */
if(!s->budget--) { s->failed_pc=0x0c0c1efeu; return 0; }
r[8]+=0x00000001u;
goto P_0c0c1f00;
P_0c0c1f00: /* original 7b01, guest PC 0x0c0c1f00 */
if(!s->budget--) { s->failed_pc=0x0c0c1f00u; return 0; }
r[11]+=0x00000001u;
goto P_0c0c1f02;
P_0c0c1f02: /* original 3ba2, guest PC 0x0c0c1f02 */
if(!s->budget--) { s->failed_pc=0x0c0c1f02u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1f04;
P_0c0c1f04: /* original 8fd3, guest PC 0x0c0c1f04 */
if(!s->budget--) { s->failed_pc=0x0c0c1f04u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000044u;
if(!cond) { goto P_0c0c1eae; }
goto P_0c0c1f08;
P_0c0c1f06: /* original 7d44, guest PC 0x0c0c1f06 */
if(!s->budget--) { s->failed_pc=0x0c0c1f06u; return 0; }
r[13]+=0x00000044u;
goto P_0c0c1f08;
P_0c0c1f08: /* original e028, guest PC 0x0c0c1f08 */
if(!s->budget--) { s->failed_pc=0x0c0c1f08u; return 0; }
r[0]=0x00000028u;
goto P_0c0c1f0a;
P_0c0c1f0a: /* original 0e85, guest PC 0x0c0c1f0a */
if(!s->budget--) { s->failed_pc=0x0c0c1f0au; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c1f0c;
P_0c0c1f0c: /* original e022, guest PC 0x0c0c1f0c */
if(!s->budget--) { s->failed_pc=0x0c0c1f0cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1f0e;
P_0c0c1f0e: /* original 02ed, guest PC 0x0c0c1f0e */
if(!s->budget--) { s->failed_pc=0x0c0c1f0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1f10;
P_0c0c1f10: /* original d314, guest PC 0x0c0c1f10 */
if(!s->budget--) { s->failed_pc=0x0c0c1f10u; return 0; }
r[3]=read(ram,0x0c0c1f64u,4);
goto P_0c0c1f12;
P_0c0c1f12: /* original 2239, guest PC 0x0c0c1f12 */
if(!s->budget--) { s->failed_pc=0x0c0c1f12u; return 0; }
r[2]&=r[3];
goto P_0c0c1f14;
P_0c0c1f14: /* original 0e25, guest PC 0x0c0c1f14 */
if(!s->budget--) { s->failed_pc=0x0c0c1f14u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c1f16;
P_0c0c1f16: /* original 7f38, guest PC 0x0c0c1f16 */
if(!s->budget--) { s->failed_pc=0x0c0c1f16u; return 0; }
r[15]+=0x00000038u;
goto P_0c0c1f18;
P_0c0c1f18: /* original 4f26, guest PC 0x0c0c1f18 */
if(!s->budget--) { s->failed_pc=0x0c0c1f18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1f1a;
P_0c0c1f1a: /* original fcf9, guest PC 0x0c0c1f1a */
if(!s->budget--) { s->failed_pc=0x0c0c1f1au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1c;
P_0c0c1f1c: /* original fdf9, guest PC 0x0c0c1f1c */
if(!s->budget--) { s->failed_pc=0x0c0c1f1cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1e;
P_0c0c1f1e: /* original fef9, guest PC 0x0c0c1f1e */
if(!s->budget--) { s->failed_pc=0x0c0c1f1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f20;
P_0c0c1f20: /* original fff9, guest PC 0x0c0c1f20 */
if(!s->budget--) { s->failed_pc=0x0c0c1f20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f22;
P_0c0c1f22: /* original 68f6, guest PC 0x0c0c1f22 */
if(!s->budget--) { s->failed_pc=0x0c0c1f22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1f24;
P_0c0c1f24: /* original 69f6, guest PC 0x0c0c1f24 */
if(!s->budget--) { s->failed_pc=0x0c0c1f24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1f26;
P_0c0c1f26: /* original 6af6, guest PC 0x0c0c1f26 */
if(!s->budget--) { s->failed_pc=0x0c0c1f26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1f28;
P_0c0c1f28: /* original 6bf6, guest PC 0x0c0c1f28 */
if(!s->budget--) { s->failed_pc=0x0c0c1f28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1f2a;
P_0c0c1f2a: /* original 6cf6, guest PC 0x0c0c1f2a */
if(!s->budget--) { s->failed_pc=0x0c0c1f2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1f2c;
P_0c0c1f2c: /* original 6df6, guest PC 0x0c0c1f2c */
if(!s->budget--) { s->failed_pc=0x0c0c1f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1f2e;
P_0c0c1f2e: /* original 000b, guest PC 0x0c0c1f2e */
if(!s->budget--) { s->failed_pc=0x0c0c1f2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1f30: /* original 6ef6, guest PC 0x0c0c1f30 */
if(!s->budget--) { s->failed_pc=0x0c0c1f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1f32u,s,ram);
P_0c0c2b66: /* original 4f22, guest PC 0x0c0c2b66 */
if(!s->budget--) { s->failed_pc=0x0c0c2b66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2b68;
P_0c0c2b68: /* original 2348, guest PC 0x0c0c2b68 */
if(!s->budget--) { s->failed_pc=0x0c0c2b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c2b6a;
P_0c0c2b6a: /* original 8902, guest PC 0x0c0c2b6a */
if(!s->budget--) { s->failed_pc=0x0c0c2b6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2b72; }
goto P_0c0c2b6c;
P_0c0c2b6c: /* original 5151, guest PC 0x0c0c2b6c */
if(!s->budget--) { s->failed_pc=0x0c0c2b6cu; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c0c2b6e;
P_0c0c2b6e: /* original 2418, guest PC 0x0c0c2b6e */
if(!s->budget--) { s->failed_pc=0x0c0c2b6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0c2b70;
P_0c0c2b70: /* original 8b03, guest PC 0x0c0c2b70 */
if(!s->budget--) { s->failed_pc=0x0c0c2b70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c2b7a; }
goto P_0c0c2b72;
P_0c0c2b72: /* original d334, guest PC 0x0c0c2b72 */
if(!s->budget--) { s->failed_pc=0x0c0c2b72u; return 0; }
r[3]=read(ram,0x0c0c2c44u,4);
goto P_0c0c2b74;
P_0c0c2b74: /* original d432, guest PC 0x0c0c2b74 */
if(!s->budget--) { s->failed_pc=0x0c0c2b74u; return 0; }
r[4]=read(ram,0x0c0c2c40u,4);
goto P_0c0c2b76;
P_0c0c2b76: /* original 430b, guest PC 0x0c0c2b76 */
if(!s->budget--) { s->failed_pc=0x0c0c2b76u; return 0; }
target=r[3];
r[16]=0x0c0c2b7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2b7au) { target=s->pc; goto dispatch; }
goto P_0c0c2b7a;
P_0c0c2b78: /* original 0009, guest PC 0x0c0c2b78 */
if(!s->budget--) { s->failed_pc=0x0c0c2b78u; return 0; }
goto P_0c0c2b7a;
P_0c0c2b7a: /* original 4f26, guest PC 0x0c0c2b7a */
if(!s->budget--) { s->failed_pc=0x0c0c2b7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2b7c;
P_0c0c2b7c: /* original 000b, guest PC 0x0c0c2b7c */
if(!s->budget--) { s->failed_pc=0x0c0c2b7cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c2b7e: /* original 0009, guest PC 0x0c0c2b7e */
if(!s->budget--) { s->failed_pc=0x0c0c2b7eu; return 0; }
return vf3_matrix_family(0x0c0c2b80u,s,ram);
P_0c0c4eb0: /* original 2fe6, guest PC 0x0c0c4eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c4eb2;
P_0c0c4eb2: /* original 2fd6, guest PC 0x0c0c4eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c4eb4;
P_0c0c4eb4: /* original 2fc6, guest PC 0x0c0c4eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c4eb6;
P_0c0c4eb6: /* original 2fb6, guest PC 0x0c0c4eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c4eb8;
P_0c0c4eb8: /* original 2fa6, guest PC 0x0c0c4eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
return vf3_matrix_family(0x0c0c4ebau,s,ram);
P_0c0c6e7e: /* original 4f22, guest PC 0x0c0c6e7e */
if(!s->budget--) { s->failed_pc=0x0c0c6e7eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6e80;
P_0c0c6e80: /* original 7ff8, guest PC 0x0c0c6e80 */
if(!s->budget--) { s->failed_pc=0x0c0c6e80u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c6e82;
P_0c0c6e82: /* original 1f41, guest PC 0x0c0c6e82 */
if(!s->budget--) { s->failed_pc=0x0c0c6e82u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c6e84;
P_0c0c6e84: /* original 2f52, guest PC 0x0c0c6e84 */
if(!s->budget--) { s->failed_pc=0x0c0c6e84u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c6e86;
P_0c0c6e86: /* original d121, guest PC 0x0c0c6e86 */
if(!s->budget--) { s->failed_pc=0x0c0c6e86u; return 0; }
r[1]=read(ram,0x0c0c6f0cu,4);
goto P_0c0c6e88;
P_0c0c6e88: /* original d31f, guest PC 0x0c0c6e88 */
if(!s->budget--) { s->failed_pc=0x0c0c6e88u; return 0; }
r[3]=read(ram,0x0c0c6f08u,4);
goto P_0c0c6e8a;
P_0c0c6e8a: /* original 6212, guest PC 0x0c0c6e8a */
if(!s->budget--) { s->failed_pc=0x0c0c6e8au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c6e8c;
P_0c0c6e8c: /* original 2238, guest PC 0x0c0c6e8c */
if(!s->budget--) { s->failed_pc=0x0c0c6e8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c6e8e;
P_0c0c6e8e: /* original 8b09, guest PC 0x0c0c6e8e */
if(!s->budget--) { s->failed_pc=0x0c0c6e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6ea4; }
goto P_0c0c6e90;
P_0c0c6e90: /* original b00c, guest PC 0x0c0c6e90 */
if(!s->budget--) { s->failed_pc=0x0c0c6e90u; return 0; }
target=0x0c0c6eacu; r[16]=0x0c0c6e94u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6e94u) { target=s->pc; goto dispatch; }
goto P_0c0c6e94;
P_0c0c6e92: /* original 54f1, guest PC 0x0c0c6e92 */
if(!s->budget--) { s->failed_pc=0x0c0c6e92u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6e94;
P_0c0c6e94: /* original d31e, guest PC 0x0c0c6e94 */
if(!s->budget--) { s->failed_pc=0x0c0c6e94u; return 0; }
r[3]=read(ram,0x0c0c6f10u,4);
goto P_0c0c6e96;
P_0c0c6e96: /* original 430b, guest PC 0x0c0c6e96 */
if(!s->budget--) { s->failed_pc=0x0c0c6e96u; return 0; }
target=r[3];
r[16]=0x0c0c6e9au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6e9au) { target=s->pc; goto dispatch; }
goto P_0c0c6e9a;
P_0c0c6e98: /* original 54f1, guest PC 0x0c0c6e98 */
if(!s->budget--) { s->failed_pc=0x0c0c6e98u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c6e9a;
P_0c0c6e9a: /* original b007, guest PC 0x0c0c6e9a */
if(!s->budget--) { s->failed_pc=0x0c0c6e9au; return 0; }
target=0x0c0c6eacu; r[16]=0x0c0c6e9eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6e9eu) { target=s->pc; goto dispatch; }
goto P_0c0c6e9e;
P_0c0c6e9c: /* original 64f2, guest PC 0x0c0c6e9c */
if(!s->budget--) { s->failed_pc=0x0c0c6e9cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6e9e;
P_0c0c6e9e: /* original d31c, guest PC 0x0c0c6e9e */
if(!s->budget--) { s->failed_pc=0x0c0c6e9eu; return 0; }
r[3]=read(ram,0x0c0c6f10u,4);
goto P_0c0c6ea0;
P_0c0c6ea0: /* original 430b, guest PC 0x0c0c6ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea0u; return 0; }
target=r[3];
r[16]=0x0c0c6ea4u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6ea4u) { target=s->pc; goto dispatch; }
goto P_0c0c6ea4;
P_0c0c6ea2: /* original 64f2, guest PC 0x0c0c6ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6ea4;
P_0c0c6ea4: /* original 7f08, guest PC 0x0c0c6ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c6ea6;
P_0c0c6ea6: /* original 4f26, guest PC 0x0c0c6ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6ea8;
P_0c0c6ea8: /* original 000b, guest PC 0x0c0c6ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ea8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c6eaa: /* original 0009, guest PC 0x0c0c6eaa */
if(!s->budget--) { s->failed_pc=0x0c0c6eaau; return 0; }
goto P_0c0c6eac;
P_0c0c6eac: /* original 2fe6, guest PC 0x0c0c6eac */
if(!s->budget--) { s->failed_pc=0x0c0c6eacu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c6eae;
P_0c0c6eae: /* original 6e43, guest PC 0x0c0c6eae */
if(!s->budget--) { s->failed_pc=0x0c0c6eaeu; return 0; }
r[14]=r[4];
goto P_0c0c6eb0;
P_0c0c6eb0: /* original 2fd6, guest PC 0x0c0c6eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c6eb2;
P_0c0c6eb2: /* original e320, guest PC 0x0c0c6eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb2u; return 0; }
r[3]=0x00000020u;
goto P_0c0c6eb4;
P_0c0c6eb4: /* original 2fc6, guest PC 0x0c0c6eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c6eb6;
P_0c0c6eb6: /* original e700, guest PC 0x0c0c6eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb6u; return 0; }
r[7]=0x00000000u;
goto P_0c0c6eb8;
P_0c0c6eb8: /* original 2fb6, guest PC 0x0c0c6eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6eb8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c6eba;
P_0c0c6eba: /* original 2fa6, guest PC 0x0c0c6eba */
if(!s->budget--) { s->failed_pc=0x0c0c6ebau; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c6ebc;
P_0c0c6ebc: /* original 2f96, guest PC 0x0c0c6ebc */
if(!s->budget--) { s->failed_pc=0x0c0c6ebcu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c6ebe;
P_0c0c6ebe: /* original 2f86, guest PC 0x0c0c6ebe */
if(!s->budget--) { s->failed_pc=0x0c0c6ebeu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c6ec0;
P_0c0c6ec0: /* original fffb, guest PC 0x0c0c6ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c6ec2;
P_0c0c6ec2: /* original 9016, guest PC 0x0c0c6ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef2u,2);
goto P_0c0c6ec4;
P_0c0c6ec4: /* original 4f22, guest PC 0x0c0c6ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c6ec6;
P_0c0c6ec6: /* original 0dec, guest PC 0x0c0c6ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec6u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c6ec8;
P_0c0c6ec8: /* original e014, guest PC 0x0c0c6ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ec8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c6eca;
P_0c0c6eca: /* original ffe6, guest PC 0x0c0c6eca */
if(!s->budget--) { s->failed_pc=0x0c0c6ecau; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0c6ecc;
P_0c0c6ecc: /* original 9012, guest PC 0x0c0c6ecc */
if(!s->budget--) { s->failed_pc=0x0c0c6eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6ef4u,2);
goto P_0c0c6ece;
P_0c0c6ece: /* original 6ddc, guest PC 0x0c0c6ece */
if(!s->budget--) { s->failed_pc=0x0c0c6eceu; return 0; }
r[13]=r[13]&255u;
goto P_0c0c6ed0;
P_0c0c6ed0: /* original d510, guest PC 0x0c0c6ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed0u; return 0; }
r[5]=read(ram,0x0c0c6f14u,4);
goto P_0c0c6ed2;
P_0c0c6ed2: /* original 23d8, guest PC 0x0c0c6ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6ed4;
P_0c0c6ed4: /* original 66e2, guest PC 0x0c0c6ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0c6ed6;
P_0c0c6ed6: /* original 0cee, guest PC 0x0c0c6ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed6u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0c6ed8;
P_0c0c6ed8: /* original 8d02, guest PC 0x0c0c6ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ed8u; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(cond) { goto P_0c0c6ee0; }
goto P_0c0c6edc;
P_0c0c6eda: /* original e401, guest PC 0x0c0c6eda */
if(!s->budget--) { s->failed_pc=0x0c0c6edau; return 0; }
r[4]=0x00000001u;
goto P_0c0c6edc;
P_0c0c6edc: /* original a001, guest PC 0x0c0c6edc */
if(!s->budget--) { s->failed_pc=0x0c0c6edcu; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0c6ee2;
P_0c0c6ede: /* original 1547, guest PC 0x0c0c6ede */
if(!s->budget--) { s->failed_pc=0x0c0c6edeu; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c0c6ee0;
P_0c0c6ee0: /* original 1577, guest PC 0x0c0c6ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee0u; return 0; }
write(ram,r[5]+28,r[7],4);
goto P_0c0c6ee2;
P_0c0c6ee2: /* original d20d, guest PC 0x0c0c6ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee2u; return 0; }
r[2]=read(ram,0x0c0c6f18u,4);
goto P_0c0c6ee4;
P_0c0c6ee4: /* original 2628, guest PC 0x0c0c6ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c6ee6;
P_0c0c6ee6: /* original 8d19, guest PC 0x0c0c6ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee6u; return 0; }
cond=r[17]&1u;
r[9]=r[12];
if(cond) { goto P_0c0c6f1c; }
goto P_0c0c6eea;
P_0c0c6ee8: /* original 69c3, guest PC 0x0c0c6ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ee8u; return 0; }
r[9]=r[12];
goto P_0c0c6eea;
P_0c0c6eea: /* original a018, guest PC 0x0c0c6eea */
if(!s->budget--) { s->failed_pc=0x0c0c6eeau; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c0c6f1e;
P_0c0c6eec: /* original 1546, guest PC 0x0c0c6eec */
if(!s->budget--) { s->failed_pc=0x0c0c6eecu; return 0; }
write(ram,r[5]+24,r[4],4);
return vf3_matrix_family(0x0c0c6eeeu,s,ram);
P_0c0c6f1c: /* original 1576, guest PC 0x0c0c6f1c */
if(!s->budget--) { s->failed_pc=0x0c0c6f1cu; return 0; }
write(ram,r[5]+24,r[7],4);
goto P_0c0c6f1e;
P_0c0c6f1e: /* original 9b82, guest PC 0x0c0c6f1e */
if(!s->budget--) { s->failed_pc=0x0c0c6f1eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7026u,2);
goto P_0c0c6f20;
P_0c0c6f20: /* original 24d8, guest PC 0x0c0c6f20 */
if(!s->budget--) { s->failed_pc=0x0c0c6f20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0c6f22;
P_0c0c6f22: /* original 987f, guest PC 0x0c0c6f22 */
if(!s->budget--) { s->failed_pc=0x0c0c6f22u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7024u,2);
goto P_0c0c6f24;
P_0c0c6f24: /* original 7958, guest PC 0x0c0c6f24 */
if(!s->budget--) { s->failed_pc=0x0c0c6f24u; return 0; }
r[9]+=0x00000058u;
goto P_0c0c6f26;
P_0c0c6f26: /* original 9a7f, guest PC 0x0c0c6f26 */
if(!s->budget--) { s->failed_pc=0x0c0c6f26u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7028u,2);
goto P_0c0c6f28;
P_0c0c6f28: /* original 3bcc, guest PC 0x0c0c6f28 */
if(!s->budget--) { s->failed_pc=0x0c0c6f28u; return 0; }
r[11]+=r[12];
goto P_0c0c6f2a;
P_0c0c6f2a: /* original 38cc, guest PC 0x0c0c6f2a */
if(!s->budget--) { s->failed_pc=0x0c0c6f2au; return 0; }
r[8]+=r[12];
goto P_0c0c6f2c;
P_0c0c6f2c: /* original 8f32, guest PC 0x0c0c6f2c */
if(!s->budget--) { s->failed_pc=0x0c0c6f2cu; return 0; }
cond=r[17]&1u;
r[10]+=r[12];
if(!cond) { goto P_0c0c6f94; }
goto P_0c0c6f30;
P_0c0c6f2e: /* original 3acc, guest PC 0x0c0c6f2e */
if(!s->budget--) { s->failed_pc=0x0c0c6f2eu; return 0; }
r[10]+=r[12];
goto P_0c0c6f30;
P_0c0c6f30: /* original e308, guest PC 0x0c0c6f30 */
if(!s->budget--) { s->failed_pc=0x0c0c6f30u; return 0; }
r[3]=0x00000008u;
goto P_0c0c6f32;
P_0c0c6f32: /* original 23d8, guest PC 0x0c0c6f32 */
if(!s->budget--) { s->failed_pc=0x0c0c6f32u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6f34;
P_0c0c6f34: /* original 8908, guest PC 0x0c0c6f34 */
if(!s->budget--) { s->failed_pc=0x0c0c6f34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f48; }
goto P_0c0c6f36;
P_0c0c6f36: /* original 9078, guest PC 0x0c0c6f36 */
if(!s->budget--) { s->failed_pc=0x0c0c6f36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702au,2);
goto P_0c0c6f38;
P_0c0c6f38: /* original 6593, guest PC 0x0c0c6f38 */
if(!s->budget--) { s->failed_pc=0x0c0c6f38u; return 0; }
r[5]=r[9];
goto P_0c0c6f3a;
P_0c0c6f3a: /* original 9478, guest PC 0x0c0c6f3a */
if(!s->budget--) { s->failed_pc=0x0c0c6f3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702eu,2);
goto P_0c0c6f3c;
P_0c0c6f3c: /* original 9676, guest PC 0x0c0c6f3c */
if(!s->budget--) { s->failed_pc=0x0c0c6f3cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702cu,2);
goto P_0c0c6f3e;
P_0c0c6f3e: /* original f4e6, guest PC 0x0c0c6f3e */
if(!s->budget--) { s->failed_pc=0x0c0c6f3eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f40;
P_0c0c6f40: /* original 34ec, guest PC 0x0c0c6f40 */
if(!s->budget--) { s->failed_pc=0x0c0c6f40u; return 0; }
r[4]+=r[14];
goto P_0c0c6f42;
P_0c0c6f42: /* original 36ec, guest PC 0x0c0c6f42 */
if(!s->budget--) { s->failed_pc=0x0c0c6f42u; return 0; }
r[6]+=r[14];
goto P_0c0c6f44;
P_0c0c6f44: /* original b084, guest PC 0x0c0c6f44 */
if(!s->budget--) { s->failed_pc=0x0c0c6f44u; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6f48u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6f48u) { target=s->pc; goto dispatch; }
goto P_0c0c6f48;
P_0c0c6f46: /* original f5fc, guest PC 0x0c0c6f46 */
if(!s->budget--) { s->failed_pc=0x0c0c6f46u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f48;
P_0c0c6f48: /* original e210, guest PC 0x0c0c6f48 */
if(!s->budget--) { s->failed_pc=0x0c0c6f48u; return 0; }
r[2]=0x00000010u;
goto P_0c0c6f4a;
P_0c0c6f4a: /* original 22d8, guest PC 0x0c0c6f4a */
if(!s->budget--) { s->failed_pc=0x0c0c6f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6f4c;
P_0c0c6f4c: /* original 8908, guest PC 0x0c0c6f4c */
if(!s->budget--) { s->failed_pc=0x0c0c6f4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f60; }
goto P_0c0c6f4e;
P_0c0c6f4e: /* original 906f, guest PC 0x0c0c6f4e */
if(!s->budget--) { s->failed_pc=0x0c0c6f4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7030u,2);
goto P_0c0c6f50;
P_0c0c6f50: /* original 6583, guest PC 0x0c0c6f50 */
if(!s->budget--) { s->failed_pc=0x0c0c6f50u; return 0; }
r[5]=r[8];
goto P_0c0c6f52;
P_0c0c6f52: /* original 946f, guest PC 0x0c0c6f52 */
if(!s->budget--) { s->failed_pc=0x0c0c6f52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7034u,2);
goto P_0c0c6f54;
P_0c0c6f54: /* original 966d, guest PC 0x0c0c6f54 */
if(!s->budget--) { s->failed_pc=0x0c0c6f54u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7032u,2);
goto P_0c0c6f56;
P_0c0c6f56: /* original f4e6, guest PC 0x0c0c6f56 */
if(!s->budget--) { s->failed_pc=0x0c0c6f56u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f58;
P_0c0c6f58: /* original 34ec, guest PC 0x0c0c6f58 */
if(!s->budget--) { s->failed_pc=0x0c0c6f58u; return 0; }
r[4]+=r[14];
goto P_0c0c6f5a;
P_0c0c6f5a: /* original 36ec, guest PC 0x0c0c6f5a */
if(!s->budget--) { s->failed_pc=0x0c0c6f5au; return 0; }
r[6]+=r[14];
goto P_0c0c6f5c;
P_0c0c6f5c: /* original b078, guest PC 0x0c0c6f5c */
if(!s->budget--) { s->failed_pc=0x0c0c6f5cu; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6f60u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6f60u) { target=s->pc; goto dispatch; }
goto P_0c0c6f60;
P_0c0c6f5e: /* original f5fc, guest PC 0x0c0c6f5e */
if(!s->budget--) { s->failed_pc=0x0c0c6f5eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f60;
P_0c0c6f60: /* original e202, guest PC 0x0c0c6f60 */
if(!s->budget--) { s->failed_pc=0x0c0c6f60u; return 0; }
r[2]=0x00000002u;
goto P_0c0c6f62;
P_0c0c6f62: /* original 22d8, guest PC 0x0c0c6f62 */
if(!s->budget--) { s->failed_pc=0x0c0c6f62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c6f64;
P_0c0c6f64: /* original 8908, guest PC 0x0c0c6f64 */
if(!s->budget--) { s->failed_pc=0x0c0c6f64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6f78; }
goto P_0c0c6f66;
P_0c0c6f66: /* original 9066, guest PC 0x0c0c6f66 */
if(!s->budget--) { s->failed_pc=0x0c0c6f66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7036u,2);
goto P_0c0c6f68;
P_0c0c6f68: /* original 65b3, guest PC 0x0c0c6f68 */
if(!s->budget--) { s->failed_pc=0x0c0c6f68u; return 0; }
r[5]=r[11];
goto P_0c0c6f6a;
P_0c0c6f6a: /* original 9466, guest PC 0x0c0c6f6a */
if(!s->budget--) { s->failed_pc=0x0c0c6f6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703au,2);
goto P_0c0c6f6c;
P_0c0c6f6c: /* original 9664, guest PC 0x0c0c6f6c */
if(!s->budget--) { s->failed_pc=0x0c0c6f6cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7038u,2);
goto P_0c0c6f6e;
P_0c0c6f6e: /* original f4e6, guest PC 0x0c0c6f6e */
if(!s->budget--) { s->failed_pc=0x0c0c6f6eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f70;
P_0c0c6f70: /* original 34ec, guest PC 0x0c0c6f70 */
if(!s->budget--) { s->failed_pc=0x0c0c6f70u; return 0; }
r[4]+=r[14];
goto P_0c0c6f72;
P_0c0c6f72: /* original 36ec, guest PC 0x0c0c6f72 */
if(!s->budget--) { s->failed_pc=0x0c0c6f72u; return 0; }
r[6]+=r[14];
goto P_0c0c6f74;
P_0c0c6f74: /* original b06c, guest PC 0x0c0c6f74 */
if(!s->budget--) { s->failed_pc=0x0c0c6f74u; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6f78u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6f78u) { target=s->pc; goto dispatch; }
goto P_0c0c6f78;
P_0c0c6f76: /* original f5fc, guest PC 0x0c0c6f76 */
if(!s->budget--) { s->failed_pc=0x0c0c6f76u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f78;
P_0c0c6f78: /* original e204, guest PC 0x0c0c6f78 */
if(!s->budget--) { s->failed_pc=0x0c0c6f78u; return 0; }
r[2]=0x00000004u;
goto P_0c0c6f7a;
P_0c0c6f7a: /* original 2d28, guest PC 0x0c0c6f7a */
if(!s->budget--) { s->failed_pc=0x0c0c6f7au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c0c6f7c;
P_0c0c6f7c: /* original 8948, guest PC 0x0c0c6f7c */
if(!s->budget--) { s->failed_pc=0x0c0c6f7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7010; }
goto P_0c0c6f7e;
P_0c0c6f7e: /* original 905d, guest PC 0x0c0c6f7e */
if(!s->budget--) { s->failed_pc=0x0c0c6f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703cu,2);
goto P_0c0c6f80;
P_0c0c6f80: /* original 65a3, guest PC 0x0c0c6f80 */
if(!s->budget--) { s->failed_pc=0x0c0c6f80u; return 0; }
r[5]=r[10];
goto P_0c0c6f82;
P_0c0c6f82: /* original 945d, guest PC 0x0c0c6f82 */
if(!s->budget--) { s->failed_pc=0x0c0c6f82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7040u,2);
goto P_0c0c6f84;
P_0c0c6f84: /* original 965b, guest PC 0x0c0c6f84 */
if(!s->budget--) { s->failed_pc=0x0c0c6f84u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703eu,2);
goto P_0c0c6f86;
P_0c0c6f86: /* original f4e6, guest PC 0x0c0c6f86 */
if(!s->budget--) { s->failed_pc=0x0c0c6f86u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6f88;
P_0c0c6f88: /* original 34ec, guest PC 0x0c0c6f88 */
if(!s->budget--) { s->failed_pc=0x0c0c6f88u; return 0; }
r[4]+=r[14];
goto P_0c0c6f8a;
P_0c0c6f8a: /* original 36ec, guest PC 0x0c0c6f8a */
if(!s->budget--) { s->failed_pc=0x0c0c6f8au; return 0; }
r[6]+=r[14];
goto P_0c0c6f8c;
P_0c0c6f8c: /* original b060, guest PC 0x0c0c6f8c */
if(!s->budget--) { s->failed_pc=0x0c0c6f8cu; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6f90u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6f90u) { target=s->pc; goto dispatch; }
goto P_0c0c6f90;
P_0c0c6f8e: /* original f5fc, guest PC 0x0c0c6f8e */
if(!s->budget--) { s->failed_pc=0x0c0c6f8eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6f90;
P_0c0c6f90: /* original a03e, guest PC 0x0c0c6f90 */
if(!s->budget--) { s->failed_pc=0x0c0c6f90u; return 0; }
goto P_0c0c7010;
P_0c0c6f92: /* original 0009, guest PC 0x0c0c6f92 */
if(!s->budget--) { s->failed_pc=0x0c0c6f92u; return 0; }
goto P_0c0c6f94;
P_0c0c6f94: /* original 9355, guest PC 0x0c0c6f94 */
if(!s->budget--) { s->failed_pc=0x0c0c6f94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7042u,2);
goto P_0c0c6f96;
P_0c0c6f96: /* original 23d8, guest PC 0x0c0c6f96 */
if(!s->budget--) { s->failed_pc=0x0c0c6f96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c6f98;
P_0c0c6f98: /* original 8b13, guest PC 0x0c0c6f98 */
if(!s->budget--) { s->failed_pc=0x0c0c6f98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6fc2; }
goto P_0c0c6f9a;
P_0c0c6f9a: /* original 9053, guest PC 0x0c0c6f9a */
if(!s->budget--) { s->failed_pc=0x0c0c6f9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7044u,2);
goto P_0c0c6f9c;
P_0c0c6f9c: /* original 65c3, guest PC 0x0c0c6f9c */
if(!s->budget--) { s->failed_pc=0x0c0c6f9cu; return 0; }
r[5]=r[12];
goto P_0c0c6f9e;
P_0c0c6f9e: /* original 9453, guest PC 0x0c0c6f9e */
if(!s->budget--) { s->failed_pc=0x0c0c6f9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7048u,2);
goto P_0c0c6fa0;
P_0c0c6fa0: /* original 751c, guest PC 0x0c0c6fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa0u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0c6fa2;
P_0c0c6fa2: /* original 9650, guest PC 0x0c0c6fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7046u,2);
goto P_0c0c6fa4;
P_0c0c6fa4: /* original f4e6, guest PC 0x0c0c6fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fa6;
P_0c0c6fa6: /* original 34ec, guest PC 0x0c0c6fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa6u; return 0; }
r[4]+=r[14];
goto P_0c0c6fa8;
P_0c0c6fa8: /* original 36ec, guest PC 0x0c0c6fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fa8u; return 0; }
r[6]+=r[14];
goto P_0c0c6faa;
P_0c0c6faa: /* original b051, guest PC 0x0c0c6faa */
if(!s->budget--) { s->failed_pc=0x0c0c6faau; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6faeu;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6faeu) { target=s->pc; goto dispatch; }
goto P_0c0c6fae;
P_0c0c6fac: /* original f5fc, guest PC 0x0c0c6fac */
if(!s->budget--) { s->failed_pc=0x0c0c6facu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fae;
P_0c0c6fae: /* original 904c, guest PC 0x0c0c6fae */
if(!s->budget--) { s->failed_pc=0x0c0c6faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704au,2);
goto P_0c0c6fb0;
P_0c0c6fb0: /* original 65c3, guest PC 0x0c0c6fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb0u; return 0; }
r[5]=r[12];
goto P_0c0c6fb2;
P_0c0c6fb2: /* original 944c, guest PC 0x0c0c6fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704eu,2);
goto P_0c0c6fb4;
P_0c0c6fb4: /* original 7504, guest PC 0x0c0c6fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0c6fb6;
P_0c0c6fb6: /* original 9649, guest PC 0x0c0c6fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c704cu,2);
goto P_0c0c6fb8;
P_0c0c6fb8: /* original f4e6, guest PC 0x0c0c6fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fb8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fba;
P_0c0c6fba: /* original 34ec, guest PC 0x0c0c6fba */
if(!s->budget--) { s->failed_pc=0x0c0c6fbau; return 0; }
r[4]+=r[14];
goto P_0c0c6fbc;
P_0c0c6fbc: /* original 36ec, guest PC 0x0c0c6fbc */
if(!s->budget--) { s->failed_pc=0x0c0c6fbcu; return 0; }
r[6]+=r[14];
goto P_0c0c6fbe;
P_0c0c6fbe: /* original b047, guest PC 0x0c0c6fbe */
if(!s->budget--) { s->failed_pc=0x0c0c6fbeu; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6fc2u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6fc2u) { target=s->pc; goto dispatch; }
goto P_0c0c6fc2;
P_0c0c6fc0: /* original f5fc, guest PC 0x0c0c6fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fc2;
P_0c0c6fc2: /* original 9032, guest PC 0x0c0c6fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702au,2);
goto P_0c0c6fc4;
P_0c0c6fc4: /* original 6593, guest PC 0x0c0c6fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc4u; return 0; }
r[5]=r[9];
goto P_0c0c6fc6;
P_0c0c6fc6: /* original 9432, guest PC 0x0c0c6fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702eu,2);
goto P_0c0c6fc8;
P_0c0c6fc8: /* original 9630, guest PC 0x0c0c6fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fc8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c702cu,2);
goto P_0c0c6fca;
P_0c0c6fca: /* original f4e6, guest PC 0x0c0c6fca */
if(!s->budget--) { s->failed_pc=0x0c0c6fcau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fcc;
P_0c0c6fcc: /* original 34ec, guest PC 0x0c0c6fcc */
if(!s->budget--) { s->failed_pc=0x0c0c6fccu; return 0; }
r[4]+=r[14];
goto P_0c0c6fce;
P_0c0c6fce: /* original 36ec, guest PC 0x0c0c6fce */
if(!s->budget--) { s->failed_pc=0x0c0c6fceu; return 0; }
r[6]+=r[14];
goto P_0c0c6fd0;
P_0c0c6fd0: /* original b03e, guest PC 0x0c0c6fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd0u; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6fd4u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6fd4u) { target=s->pc; goto dispatch; }
goto P_0c0c6fd4;
P_0c0c6fd2: /* original f5fc, guest PC 0x0c0c6fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fd4;
P_0c0c6fd4: /* original 902c, guest PC 0x0c0c6fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7030u,2);
goto P_0c0c6fd6;
P_0c0c6fd6: /* original 6583, guest PC 0x0c0c6fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd6u; return 0; }
r[5]=r[8];
goto P_0c0c6fd8;
P_0c0c6fd8: /* original 942c, guest PC 0x0c0c6fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7034u,2);
goto P_0c0c6fda;
P_0c0c6fda: /* original 962a, guest PC 0x0c0c6fda */
if(!s->budget--) { s->failed_pc=0x0c0c6fdau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7032u,2);
goto P_0c0c6fdc;
P_0c0c6fdc: /* original f4e6, guest PC 0x0c0c6fdc */
if(!s->budget--) { s->failed_pc=0x0c0c6fdcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6fde;
P_0c0c6fde: /* original 34ec, guest PC 0x0c0c6fde */
if(!s->budget--) { s->failed_pc=0x0c0c6fdeu; return 0; }
r[4]+=r[14];
goto P_0c0c6fe0;
P_0c0c6fe0: /* original 36ec, guest PC 0x0c0c6fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe0u; return 0; }
r[6]+=r[14];
goto P_0c0c6fe2;
P_0c0c6fe2: /* original b035, guest PC 0x0c0c6fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe2u; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6fe6u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6fe6u) { target=s->pc; goto dispatch; }
goto P_0c0c6fe6;
P_0c0c6fe4: /* original f5fc, guest PC 0x0c0c6fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe4u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6fe6;
P_0c0c6fe6: /* original e240, guest PC 0x0c0c6fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe6u; return 0; }
r[2]=0x00000040u;
goto P_0c0c6fe8;
P_0c0c6fe8: /* original 2d28, guest PC 0x0c0c6fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c6fe8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c0c6fea;
P_0c0c6fea: /* original 8b11, guest PC 0x0c0c6fea */
if(!s->budget--) { s->failed_pc=0x0c0c6feau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7010; }
goto P_0c0c6fec;
P_0c0c6fec: /* original 9023, guest PC 0x0c0c6fec */
if(!s->budget--) { s->failed_pc=0x0c0c6fecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7036u,2);
goto P_0c0c6fee;
P_0c0c6fee: /* original 65b3, guest PC 0x0c0c6fee */
if(!s->budget--) { s->failed_pc=0x0c0c6feeu; return 0; }
r[5]=r[11];
goto P_0c0c6ff0;
P_0c0c6ff0: /* original 9423, guest PC 0x0c0c6ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703au,2);
goto P_0c0c6ff2;
P_0c0c6ff2: /* original 9621, guest PC 0x0c0c6ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7038u,2);
goto P_0c0c6ff4;
P_0c0c6ff4: /* original f4e6, guest PC 0x0c0c6ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c6ff6;
P_0c0c6ff6: /* original 34ec, guest PC 0x0c0c6ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff6u; return 0; }
r[4]+=r[14];
goto P_0c0c6ff8;
P_0c0c6ff8: /* original 36ec, guest PC 0x0c0c6ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c6ff8u; return 0; }
r[6]+=r[14];
goto P_0c0c6ffa;
P_0c0c6ffa: /* original b029, guest PC 0x0c0c6ffa */
if(!s->budget--) { s->failed_pc=0x0c0c6ffau; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c6ffeu;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c6ffeu) { target=s->pc; goto dispatch; }
goto P_0c0c6ffe;
P_0c0c6ffc: /* original f5fc, guest PC 0x0c0c6ffc */
if(!s->budget--) { s->failed_pc=0x0c0c6ffcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c6ffe;
P_0c0c6ffe: /* original 901d, guest PC 0x0c0c6ffe */
if(!s->budget--) { s->failed_pc=0x0c0c6ffeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703cu,2);
goto P_0c0c7000;
P_0c0c7000: /* original 65a3, guest PC 0x0c0c7000 */
if(!s->budget--) { s->failed_pc=0x0c0c7000u; return 0; }
r[5]=r[10];
goto P_0c0c7002;
P_0c0c7002: /* original 941d, guest PC 0x0c0c7002 */
if(!s->budget--) { s->failed_pc=0x0c0c7002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7040u,2);
goto P_0c0c7004;
P_0c0c7004: /* original 961b, guest PC 0x0c0c7004 */
if(!s->budget--) { s->failed_pc=0x0c0c7004u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c703eu,2);
goto P_0c0c7006;
P_0c0c7006: /* original f4e6, guest PC 0x0c0c7006 */
if(!s->budget--) { s->failed_pc=0x0c0c7006u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c7008;
P_0c0c7008: /* original 34ec, guest PC 0x0c0c7008 */
if(!s->budget--) { s->failed_pc=0x0c0c7008u; return 0; }
r[4]+=r[14];
goto P_0c0c700a;
P_0c0c700a: /* original 36ec, guest PC 0x0c0c700a */
if(!s->budget--) { s->failed_pc=0x0c0c700au; return 0; }
r[6]+=r[14];
goto P_0c0c700c;
P_0c0c700c: /* original b020, guest PC 0x0c0c700c */
if(!s->budget--) { s->failed_pc=0x0c0c700cu; return 0; }
target=0x0c0c7050u; r[16]=0x0c0c7010u;
vf3_matrix_move(s,5,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7010u) { target=s->pc; goto dispatch; }
goto P_0c0c7010;
P_0c0c700e: /* original f5fc, guest PC 0x0c0c700e */
if(!s->budget--) { s->failed_pc=0x0c0c700eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7010;
P_0c0c7010: /* original 4f26, guest PC 0x0c0c7010 */
if(!s->budget--) { s->failed_pc=0x0c0c7010u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7012;
P_0c0c7012: /* original fff9, guest PC 0x0c0c7012 */
if(!s->budget--) { s->failed_pc=0x0c0c7012u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7014;
P_0c0c7014: /* original 68f6, guest PC 0x0c0c7014 */
if(!s->budget--) { s->failed_pc=0x0c0c7014u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c7016;
P_0c0c7016: /* original 69f6, guest PC 0x0c0c7016 */
if(!s->budget--) { s->failed_pc=0x0c0c7016u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7018;
P_0c0c7018: /* original 6af6, guest PC 0x0c0c7018 */
if(!s->budget--) { s->failed_pc=0x0c0c7018u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c701a;
P_0c0c701a: /* original 6bf6, guest PC 0x0c0c701a */
if(!s->budget--) { s->failed_pc=0x0c0c701au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c701c;
P_0c0c701c: /* original 6cf6, guest PC 0x0c0c701c */
if(!s->budget--) { s->failed_pc=0x0c0c701cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c701e;
P_0c0c701e: /* original 6df6, guest PC 0x0c0c701e */
if(!s->budget--) { s->failed_pc=0x0c0c701eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7020;
P_0c0c7020: /* original 000b, guest PC 0x0c0c7020 */
if(!s->budget--) { s->failed_pc=0x0c0c7020u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7022: /* original 6ef6, guest PC 0x0c0c7022 */
if(!s->budget--) { s->failed_pc=0x0c0c7022u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c7024u,s,ram);
P_0c0caaf2: /* original 4f22, guest PC 0x0c0caaf2 */
if(!s->budget--) { s->failed_pc=0x0c0caaf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0caaf4;
P_0c0caaf4: /* original 7ffc, guest PC 0x0c0caaf4 */
if(!s->budget--) { s->failed_pc=0x0c0caaf4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0caaf6;
P_0c0caaf6: /* original 2f52, guest PC 0x0c0caaf6 */
if(!s->budget--) { s->failed_pc=0x0c0caaf6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0caaf8;
P_0c0caaf8: /* original d10c, guest PC 0x0c0caaf8 */
if(!s->budget--) { s->failed_pc=0x0c0caaf8u; return 0; }
r[1]=read(ram,0x0c0cab2cu,4);
goto P_0c0caafa;
P_0c0caafa: /* original d30b, guest PC 0x0c0caafa */
if(!s->budget--) { s->failed_pc=0x0c0caafau; return 0; }
r[3]=read(ram,0x0c0cab28u,4);
goto P_0c0caafc;
P_0c0caafc: /* original 6212, guest PC 0x0c0caafc */
if(!s->budget--) { s->failed_pc=0x0c0caafcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0caafe;
P_0c0caafe: /* original 2238, guest PC 0x0c0caafe */
if(!s->budget--) { s->failed_pc=0x0c0caafeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab00;
P_0c0cab00: /* original 8b03, guest PC 0x0c0cab00 */
if(!s->budget--) { s->failed_pc=0x0c0cab00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cab0a; }
goto P_0c0cab02;
P_0c0cab02: /* original b015, guest PC 0x0c0cab02 */
if(!s->budget--) { s->failed_pc=0x0c0cab02u; return 0; }
target=0x0c0cab30u; r[16]=0x0c0cab06u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab06u) { target=s->pc; goto dispatch; }
goto P_0c0cab06;
P_0c0cab04: /* original 0009, guest PC 0x0c0cab04 */
if(!s->budget--) { s->failed_pc=0x0c0cab04u; return 0; }
goto P_0c0cab06;
P_0c0cab06: /* original b013, guest PC 0x0c0cab06 */
if(!s->budget--) { s->failed_pc=0x0c0cab06u; return 0; }
target=0x0c0cab30u; r[16]=0x0c0cab0au;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab0au) { target=s->pc; goto dispatch; }
goto P_0c0cab0a;
P_0c0cab08: /* original 64f2, guest PC 0x0c0cab08 */
if(!s->budget--) { s->failed_pc=0x0c0cab08u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cab0a;
P_0c0cab0a: /* original 7f04, guest PC 0x0c0cab0a */
if(!s->budget--) { s->failed_pc=0x0c0cab0au; return 0; }
r[15]+=0x00000004u;
goto P_0c0cab0c;
P_0c0cab0c: /* original 4f26, guest PC 0x0c0cab0c */
if(!s->budget--) { s->failed_pc=0x0c0cab0cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cab0e;
P_0c0cab0e: /* original 000b, guest PC 0x0c0cab0e */
if(!s->budget--) { s->failed_pc=0x0c0cab0eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0cab10: /* original 0009, guest PC 0x0c0cab10 */
if(!s->budget--) { s->failed_pc=0x0c0cab10u; return 0; }
return vf3_matrix_family(0x0c0cab12u,s,ram);
P_0c0cab30: /* original 2fe6, guest PC 0x0c0cab30 */
if(!s->budget--) { s->failed_pc=0x0c0cab30u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cab32;
P_0c0cab32: /* original 6e43, guest PC 0x0c0cab32 */
if(!s->budget--) { s->failed_pc=0x0c0cab32u; return 0; }
r[14]=r[4];
goto P_0c0cab34;
P_0c0cab34: /* original 2fd6, guest PC 0x0c0cab34 */
if(!s->budget--) { s->failed_pc=0x0c0cab34u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cab36;
P_0c0cab36: /* original 2fc6, guest PC 0x0c0cab36 */
if(!s->budget--) { s->failed_pc=0x0c0cab36u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cab38;
P_0c0cab38: /* original 2fb6, guest PC 0x0c0cab38 */
if(!s->budget--) { s->failed_pc=0x0c0cab38u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cab3a;
P_0c0cab3a: /* original 2fa6, guest PC 0x0c0cab3a */
if(!s->budget--) { s->failed_pc=0x0c0cab3au; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cab3c;
P_0c0cab3c: /* original 2f96, guest PC 0x0c0cab3c */
if(!s->budget--) { s->failed_pc=0x0c0cab3cu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0cab3e;
P_0c0cab3e: /* original 2f86, guest PC 0x0c0cab3e */
if(!s->budget--) { s->failed_pc=0x0c0cab3eu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0cab40;
P_0c0cab40: /* original fffb, guest PC 0x0c0cab40 */
if(!s->budget--) { s->failed_pc=0x0c0cab40u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cab42;
P_0c0cab42: /* original ffeb, guest PC 0x0c0cab42 */
if(!s->budget--) { s->failed_pc=0x0c0cab42u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cab44;
P_0c0cab44: /* original ffdb, guest PC 0x0c0cab44 */
if(!s->budget--) { s->failed_pc=0x0c0cab44u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cab46;
P_0c0cab46: /* original 4f22, guest PC 0x0c0cab46 */
if(!s->budget--) { s->failed_pc=0x0c0cab46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cab48;
P_0c0cab48: /* original d33c, guest PC 0x0c0cab48 */
if(!s->budget--) { s->failed_pc=0x0c0cab48u; return 0; }
r[3]=read(ram,0x0c0cac3cu,4);
goto P_0c0cab4a;
P_0c0cab4a: /* original 7fc4, guest PC 0x0c0cab4a */
if(!s->budget--) { s->failed_pc=0x0c0cab4au; return 0; }
r[15]+=0xffffffc4u;
goto P_0c0cab4c;
P_0c0cab4c: /* original 1f37, guest PC 0x0c0cab4c */
if(!s->budget--) { s->failed_pc=0x0c0cab4cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0cab4e;
P_0c0cab4e: /* original d23c, guest PC 0x0c0cab4e */
if(!s->budget--) { s->failed_pc=0x0c0cab4eu; return 0; }
r[2]=read(ram,0x0c0cac40u,4);
goto P_0c0cab50;
P_0c0cab50: /* original 1f28, guest PC 0x0c0cab50 */
if(!s->budget--) { s->failed_pc=0x0c0cab50u; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c0cab52;
P_0c0cab52: /* original bdb8, guest PC 0x0c0cab52 */
if(!s->budget--) { s->failed_pc=0x0c0cab52u; return 0; }
target=0x0c0ca6c6u; r[16]=0x0c0cab56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab56u) { target=s->pc; goto dispatch; }
goto P_0c0cab56;
P_0c0cab54: /* original 64e3, guest PC 0x0c0cab54 */
if(!s->budget--) { s->failed_pc=0x0c0cab54u; return 0; }
r[4]=r[14];
goto P_0c0cab56;
P_0c0cab56: /* original bfa1, guest PC 0x0c0cab56 */
if(!s->budget--) { s->failed_pc=0x0c0cab56u; return 0; }
target=0x0c0caa9cu; r[16]=0x0c0cab5au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cab5au) { target=s->pc; goto dispatch; }
goto P_0c0cab5a;
P_0c0cab58: /* original 64e3, guest PC 0x0c0cab58 */
if(!s->budget--) { s->failed_pc=0x0c0cab58u; return 0; }
r[4]=r[14];
goto P_0c0cab5a;
P_0c0cab5a: /* original e048, guest PC 0x0c0cab5a */
if(!s->budget--) { s->failed_pc=0x0c0cab5au; return 0; }
r[0]=0x00000048u;
goto P_0c0cab5c;
P_0c0cab5c: /* original 65e2, guest PC 0x0c0cab5c */
if(!s->budget--) { s->failed_pc=0x0c0cab5cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0cab5e;
P_0c0cab5e: /* original 03ee, guest PC 0x0c0cab5e */
if(!s->budget--) { s->failed_pc=0x0c0cab5eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0cab60;
P_0c0cab60: /* original 1f34, guest PC 0x0c0cab60 */
if(!s->budget--) { s->failed_pc=0x0c0cab60u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cab62;
P_0c0cab62: /* original d338, guest PC 0x0c0cab62 */
if(!s->budget--) { s->failed_pc=0x0c0cab62u; return 0; }
r[3]=read(ram,0x0c0cac44u,4);
goto P_0c0cab64;
P_0c0cab64: /* original 2358, guest PC 0x0c0cab64 */
if(!s->budget--) { s->failed_pc=0x0c0cab64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cab66;
P_0c0cab66: /* original 8f04, guest PC 0x0c0cab66 */
if(!s->budget--) { s->failed_pc=0x0c0cab66u; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(!cond) { goto P_0c0cab72; }
goto P_0c0cab6a;
P_0c0cab68: /* original ea00, guest PC 0x0c0cab68 */
if(!s->budget--) { s->failed_pc=0x0c0cab68u; return 0; }
r[10]=0x00000000u;
goto P_0c0cab6a;
P_0c0cab6a: /* original 52f4, guest PC 0x0c0cab6a */
if(!s->budget--) { s->failed_pc=0x0c0cab6au; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cab6c;
P_0c0cab6c: /* original 9360, guest PC 0x0c0cab6c */
if(!s->budget--) { s->failed_pc=0x0c0cab6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac30u,2);
goto P_0c0cab6e;
P_0c0cab6e: /* original 2238, guest PC 0x0c0cab6e */
if(!s->budget--) { s->failed_pc=0x0c0cab6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cab70;
P_0c0cab70: /* original 8901, guest PC 0x0c0cab70 */
if(!s->budget--) { s->failed_pc=0x0c0cab70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cab76; }
goto P_0c0cab72;
P_0c0cab72: /* original a001, guest PC 0x0c0cab72 */
if(!s->budget--) { s->failed_pc=0x0c0cab72u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab78;
P_0c0cab74: /* original e801, guest PC 0x0c0cab74 */
if(!s->budget--) { s->failed_pc=0x0c0cab74u; return 0; }
r[8]=0x00000001u;
goto P_0c0cab76;
P_0c0cab76: /* original 68a3, guest PC 0x0c0cab76 */
if(!s->budget--) { s->failed_pc=0x0c0cab76u; return 0; }
r[8]=r[10];
goto P_0c0cab78;
P_0c0cab78: /* original c733, guest PC 0x0c0cab78 */
if(!s->budget--) { s->failed_pc=0x0c0cab78u; return 0; }
r[0]=0x0c0cac48u;
goto P_0c0cab7a;
P_0c0cab7a: /* original 6ba3, guest PC 0x0c0cab7a */
if(!s->budget--) { s->failed_pc=0x0c0cab7au; return 0; }
r[11]=r[10];
goto P_0c0cab7c;
P_0c0cab7c: /* original f308, guest PC 0x0c0cab7c */
if(!s->budget--) { s->failed_pc=0x0c0cab7cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cab7e;
P_0c0cab7e: /* original e004, guest PC 0x0c0cab7e */
if(!s->budget--) { s->failed_pc=0x0c0cab7eu; return 0; }
r[0]=0x00000004u;
goto P_0c0cab80;
P_0c0cab80: /* original 6cb3, guest PC 0x0c0cab80 */
if(!s->budget--) { s->failed_pc=0x0c0cab80u; return 0; }
r[12]=r[11];
goto P_0c0cab82;
P_0c0cab82: /* original 69b3, guest PC 0x0c0cab82 */
if(!s->budget--) { s->failed_pc=0x0c0cab82u; return 0; }
r[9]=r[11];
goto P_0c0cab84;
P_0c0cab84: /* original ff37, guest PC 0x0c0cab84 */
if(!s->budget--) { s->failed_pc=0x0c0cab84u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cab86;
P_0c0cab86: /* original e014, guest PC 0x0c0cab86 */
if(!s->budget--) { s->failed_pc=0x0c0cab86u; return 0; }
r[0]=0x00000014u;
goto P_0c0cab88;
P_0c0cab88: /* original f4e6, guest PC 0x0c0cab88 */
if(!s->budget--) { s->failed_pc=0x0c0cab88u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cab8a;
P_0c0cab8a: /* original c730, guest PC 0x0c0cab8a */
if(!s->budget--) { s->failed_pc=0x0c0cab8au; return 0; }
r[0]=0x0c0cac4cu;
goto P_0c0cab8c;
P_0c0cab8c: /* original 9352, guest PC 0x0c0cab8c */
if(!s->budget--) { s->failed_pc=0x0c0cab8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cab8e;
P_0c0cab8e: /* original f708, guest PC 0x0c0cab8e */
if(!s->budget--) { s->failed_pc=0x0c0cab8eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cab90;
P_0c0cab90: /* original e004, guest PC 0x0c0cab90 */
if(!s->budget--) { s->failed_pc=0x0c0cab90u; return 0; }
r[0]=0x00000004u;
goto P_0c0cab92;
P_0c0cab92: /* original 33ec, guest PC 0x0c0cab92 */
if(!s->budget--) { s->failed_pc=0x0c0cab92u; return 0; }
r[3]+=r[14];
goto P_0c0cab94;
P_0c0cab94: /* original f34c, guest PC 0x0c0cab94 */
if(!s->budget--) { s->failed_pc=0x0c0cab94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cab96;
P_0c0cab96: /* original f4f6, guest PC 0x0c0cab96 */
if(!s->budget--) { s->failed_pc=0x0c0cab96u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0cab98;
P_0c0cab98: /* original 904b, guest PC 0x0c0cab98 */
if(!s->budget--) { s->failed_pc=0x0c0cab98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac32u,2);
goto P_0c0cab9a;
P_0c0cab9a: /* original f430, guest PC 0x0c0cab9a */
if(!s->budget--) { s->failed_pc=0x0c0cab9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0cab9c;
P_0c0cab9c: /* original dd2c, guest PC 0x0c0cab9c */
if(!s->budget--) { s->failed_pc=0x0c0cab9cu; return 0; }
r[13]=read(ram,0x0c0cac50u,4);
goto P_0c0cab9e;
P_0c0cab9e: /* original 07ee, guest PC 0x0c0cab9e */
if(!s->budget--) { s->failed_pc=0x0c0cab9eu; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0caba0;
P_0c0caba0: /* original 1f3c, guest PC 0x0c0caba0 */
if(!s->budget--) { s->failed_pc=0x0c0caba0u; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c0caba2;
P_0c0caba2: /* original 64d3, guest PC 0x0c0caba2 */
if(!s->budget--) { s->failed_pc=0x0c0caba2u; return 0; }
r[4]=r[13];
goto P_0c0caba4;
P_0c0caba4: /* original 9247, guest PC 0x0c0caba4 */
if(!s->budget--) { s->failed_pc=0x0c0caba4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac36u,2);
goto P_0c0caba6;
P_0c0caba6: /* original 32ec, guest PC 0x0c0caba6 */
if(!s->budget--) { s->failed_pc=0x0c0caba6u; return 0; }
r[2]+=r[14];
goto P_0c0caba8;
P_0c0caba8: /* original 1f2d, guest PC 0x0c0caba8 */
if(!s->budget--) { s->failed_pc=0x0c0caba8u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0cabaa;
P_0c0cabaa: /* original 9345, guest PC 0x0c0cabaa */
if(!s->budget--) { s->failed_pc=0x0c0cabaau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac38u,2);
goto P_0c0cabac;
P_0c0cabac: /* original 33ec, guest PC 0x0c0cabac */
if(!s->budget--) { s->failed_pc=0x0c0cabacu; return 0; }
r[3]+=r[14];
goto P_0c0cabae;
P_0c0cabae: /* original 1f3e, guest PC 0x0c0cabae */
if(!s->budget--) { s->failed_pc=0x0c0cabaeu; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabb0;
P_0c0cabb0: /* original e32c, guest PC 0x0c0cabb0 */
if(!s->budget--) { s->failed_pc=0x0c0cabb0u; return 0; }
r[3]=0x0000002cu;
goto P_0c0cabb2;
P_0c0cabb2: /* original 923f, guest PC 0x0c0cabb2 */
if(!s->budget--) { s->failed_pc=0x0c0cabb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cac34u,2);
goto P_0c0cabb4;
P_0c0cabb4: /* original 32ec, guest PC 0x0c0cabb4 */
if(!s->budget--) { s->failed_pc=0x0c0cabb4u; return 0; }
r[2]+=r[14];
goto P_0c0cabb6;
P_0c0cabb6: /* original 1f2a, guest PC 0x0c0cabb6 */
if(!s->budget--) { s->failed_pc=0x0c0cabb6u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0cabb8;
P_0c0cabb8: /* original e11c, guest PC 0x0c0cabb8 */
if(!s->budget--) { s->failed_pc=0x0c0cabb8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cabba;
P_0c0cabba: /* original 1f3b, guest PC 0x0c0cabba */
if(!s->budget--) { s->failed_pc=0x0c0cabbau; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0cabbc;
P_0c0cabbc: /* original 50f7, guest PC 0x0c0cabbc */
if(!s->budget--) { s->failed_pc=0x0c0cabbcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cabbe;
P_0c0cabbe: /* original 001c, guest PC 0x0c0cabbe */
if(!s->budget--) { s->failed_pc=0x0c0cabbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cabc0;
P_0c0cabc0: /* original 600c, guest PC 0x0c0cabc0 */
if(!s->budget--) { s->failed_pc=0x0c0cabc0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cabc2;
P_0c0cabc2: /* original c90f, guest PC 0x0c0cabc2 */
if(!s->budget--) { s->failed_pc=0x0c0cabc2u; return 0; }
r[0]&=15u;
goto P_0c0cabc4;
P_0c0cabc4: /* original 8804, guest PC 0x0c0cabc4 */
if(!s->budget--) { s->failed_pc=0x0c0cabc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0cabc6;
P_0c0cabc6: /* original 8d02, guest PC 0x0c0cabc6 */
if(!s->budget--) { s->failed_pc=0x0c0cabc6u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0cabce; }
goto P_0c0cabca;
P_0c0cabc8: /* original 2f02, guest PC 0x0c0cabc8 */
if(!s->budget--) { s->failed_pc=0x0c0cabc8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0cabca;
P_0c0cabca: /* original 8801, guest PC 0x0c0cabca */
if(!s->budget--) { s->failed_pc=0x0c0cabcau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cabcc;
P_0c0cabcc: /* original 8b02, guest PC 0x0c0cabcc */
if(!s->budget--) { s->failed_pc=0x0c0cabccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cabd4; }
goto P_0c0cabce;
P_0c0cabce: /* original d621, guest PC 0x0c0cabce */
if(!s->budget--) { s->failed_pc=0x0c0cabceu; return 0; }
r[6]=read(ram,0x0c0cac54u,4);
goto P_0c0cabd0;
P_0c0cabd0: /* original a001, guest PC 0x0c0cabd0 */
if(!s->budget--) { s->failed_pc=0x0c0cabd0u; return 0; }
goto P_0c0cabd6;
P_0c0cabd2: /* original 0009, guest PC 0x0c0cabd2 */
if(!s->budget--) { s->failed_pc=0x0c0cabd2u; return 0; }
goto P_0c0cabd4;
P_0c0cabd4: /* original d620, guest PC 0x0c0cabd4 */
if(!s->budget--) { s->failed_pc=0x0c0cabd4u; return 0; }
r[6]=read(ram,0x0c0cac58u,4);
goto P_0c0cabd6;
P_0c0cabd6: /* original e21c, guest PC 0x0c0cabd6 */
if(!s->budget--) { s->failed_pc=0x0c0cabd6u; return 0; }
r[2]=0x0000001cu;
goto P_0c0cabd8;
P_0c0cabd8: /* original 1f22, guest PC 0x0c0cabd8 */
if(!s->budget--) { s->failed_pc=0x0c0cabd8u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cabda;
P_0c0cabda: /* original 53fe, guest PC 0x0c0cabda */
if(!s->budget--) { s->failed_pc=0x0c0cabdau; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0cabdc;
P_0c0cabdc: /* original e004, guest PC 0x0c0cabdc */
if(!s->budget--) { s->failed_pc=0x0c0cabdcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cabde;
P_0c0cabde: /* original 7304, guest PC 0x0c0cabde */
if(!s->budget--) { s->failed_pc=0x0c0cabdeu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabe0;
P_0c0cabe0: /* original 1f3e, guest PC 0x0c0cabe0 */
if(!s->budget--) { s->failed_pc=0x0c0cabe0u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cabe2;
P_0c0cabe2: /* original 73fc, guest PC 0x0c0cabe2 */
if(!s->budget--) { s->failed_pc=0x0c0cabe2u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabe4;
P_0c0cabe4: /* original f338, guest PC 0x0c0cabe4 */
if(!s->budget--) { s->failed_pc=0x0c0cabe4u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0cabe6;
P_0c0cabe6: /* original 53fd, guest PC 0x0c0cabe6 */
if(!s->budget--) { s->failed_pc=0x0c0cabe6u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0cabe8;
P_0c0cabe8: /* original f576, guest PC 0x0c0cabe8 */
if(!s->budget--) { s->failed_pc=0x0c0cabe8u; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c0cabea;
P_0c0cabea: /* original 770c, guest PC 0x0c0cabea */
if(!s->budget--) { s->failed_pc=0x0c0cabeau; return 0; }
r[7]+=0x0000000cu;
goto P_0c0cabec;
P_0c0cabec: /* original 7304, guest PC 0x0c0cabec */
if(!s->budget--) { s->failed_pc=0x0c0cabecu; return 0; }
r[3]+=0x00000004u;
goto P_0c0cabee;
P_0c0cabee: /* original 1f3d, guest PC 0x0c0cabee */
if(!s->budget--) { s->failed_pc=0x0c0cabeeu; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c0cabf0;
P_0c0cabf0: /* original 73fc, guest PC 0x0c0cabf0 */
if(!s->budget--) { s->failed_pc=0x0c0cabf0u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0cabf2;
P_0c0cabf2: /* original 6260, guest PC 0x0c0cabf2 */
if(!s->budget--) { s->failed_pc=0x0c0cabf2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[2]=tmp;
goto P_0c0cabf4;
P_0c0cabf4: /* original f838, guest PC 0x0c0cabf4 */
if(!s->budget--) { s->failed_pc=0x0c0cabf4u; return 0; }
vf3_matrix_load(s,ram,8,r[3]);
goto P_0c0cabf6;
P_0c0cabf6: /* original 1f26, guest PC 0x0c0cabf6 */
if(!s->budget--) { s->failed_pc=0x0c0cabf6u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cabf8;
P_0c0cabf8: /* original 4208, guest PC 0x0c0cabf8 */
if(!s->budget--) { s->failed_pc=0x0c0cabf8u; return 0; }
r[2]<<=2;
goto P_0c0cabfa;
P_0c0cabfa: /* original 50fc, guest PC 0x0c0cabfa */
if(!s->budget--) { s->failed_pc=0x0c0cabfau; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c0cabfc;
P_0c0cabfc: /* original f581, guest PC 0x0c0cabfc */
if(!s->budget--) { s->failed_pc=0x0c0cabfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0cabfe;
P_0c0cabfe: /* original 032e, guest PC 0x0c0cabfe */
if(!s->budget--) { s->failed_pc=0x0c0cabfeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0cac00;
P_0c0cac00: /* original 2f32, guest PC 0x0c0cac00 */
if(!s->budget--) { s->failed_pc=0x0c0cac00u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cac02;
P_0c0cac02: /* original 52fb, guest PC 0x0c0cac02 */
if(!s->budget--) { s->failed_pc=0x0c0cac02u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c0cac04;
P_0c0cac04: /* original 2239, guest PC 0x0c0cac04 */
if(!s->budget--) { s->failed_pc=0x0c0cac04u; return 0; }
r[2]&=r[3];
goto P_0c0cac06;
P_0c0cac06: /* original 1f26, guest PC 0x0c0cac06 */
if(!s->budget--) { s->failed_pc=0x0c0cac06u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0cac08;
P_0c0cac08: /* original 51fa, guest PC 0x0c0cac08 */
if(!s->budget--) { s->failed_pc=0x0c0cac08u; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0cac0a;
P_0c0cac0a: /* original 7104, guest PC 0x0c0cac0a */
if(!s->budget--) { s->failed_pc=0x0c0cac0au; return 0; }
r[1]+=0x00000004u;
goto P_0c0cac0c;
P_0c0cac0c: /* original 1f1a, guest PC 0x0c0cac0c */
if(!s->budget--) { s->failed_pc=0x0c0cac0cu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c0cac0e;
P_0c0cac0e: /* original 2136, guest PC 0x0c0cac0e */
if(!s->budget--) { s->failed_pc=0x0c0cac0eu; return 0; }
r[1]-=4; write(ram,r[1],r[3],4);
goto P_0c0cac10;
P_0c0cac10: /* original 53f6, guest PC 0x0c0cac10 */
if(!s->budget--) { s->failed_pc=0x0c0cac10u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac12;
P_0c0cac12: /* original f67c, guest PC 0x0c0cac12 */
if(!s->budget--) { s->failed_pc=0x0c0cac12u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0cac14;
P_0c0cac14: /* original 2338, guest PC 0x0c0cac14 */
if(!s->budget--) { s->failed_pc=0x0c0cac14u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac16;
P_0c0cac16: /* original 8d03, guest PC 0x0c0cac16 */
if(!s->budget--) { s->failed_pc=0x0c0cac16u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
if(cond) { goto P_0c0cac20; }
goto P_0c0cac1a;
P_0c0cac18: /* original f630, guest PC 0x0c0cac18 */
if(!s->budget--) { s->failed_pc=0x0c0cac18u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0cac1a;
P_0c0cac1a: /* original e301, guest PC 0x0c0cac1a */
if(!s->budget--) { s->failed_pc=0x0c0cac1au; return 0; }
r[3]=0x00000001u;
goto P_0c0cac1c;
P_0c0cac1c: /* original a001, guest PC 0x0c0cac1c */
if(!s->budget--) { s->failed_pc=0x0c0cac1cu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac22;
P_0c0cac1e: /* original 1f36, guest PC 0x0c0cac1e */
if(!s->budget--) { s->failed_pc=0x0c0cac1eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cac20;
P_0c0cac20: /* original 1fa6, guest PC 0x0c0cac20 */
if(!s->budget--) { s->failed_pc=0x0c0cac20u; return 0; }
write(ram,r[15]+24,r[10],4);
goto P_0c0cac22;
P_0c0cac22: /* original 60f2, guest PC 0x0c0cac22 */
if(!s->budget--) { s->failed_pc=0x0c0cac22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac24;
P_0c0cac24: /* original c820, guest PC 0x0c0cac24 */
if(!s->budget--) { s->failed_pc=0x0c0cac24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0cac26;
P_0c0cac26: /* original 8d19, guest PC 0x0c0cac26 */
if(!s->budget--) { s->failed_pc=0x0c0cac26u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,5);
if(cond) { goto P_0c0cac5c; }
goto P_0c0cac2a;
P_0c0cac28: /* original f85c, guest PC 0x0c0cac28 */
if(!s->budget--) { s->failed_pc=0x0c0cac28u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cac2a;
P_0c0cac2a: /* original e201, guest PC 0x0c0cac2a */
if(!s->budget--) { s->failed_pc=0x0c0cac2au; return 0; }
r[2]=0x00000001u;
goto P_0c0cac2c;
P_0c0cac2c: /* original a017, guest PC 0x0c0cac2c */
if(!s->budget--) { s->failed_pc=0x0c0cac2cu; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c0cac5e;
P_0c0cac2e: /* original 1f29, guest PC 0x0c0cac2e */
if(!s->budget--) { s->failed_pc=0x0c0cac2eu; return 0; }
write(ram,r[15]+36,r[2],4);
return vf3_matrix_family(0x0c0cac30u,s,ram);
P_0c0cac5c: /* original 1fa9, guest PC 0x0c0cac5c */
if(!s->budget--) { s->failed_pc=0x0c0cac5cu; return 0; }
write(ram,r[15]+36,r[10],4);
goto P_0c0cac5e;
P_0c0cac5e: /* original f841, guest PC 0x0c0cac5e */
if(!s->budget--) { s->failed_pc=0x0c0cac5eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'-');
goto P_0c0cac60;
P_0c0cac60: /* original 60f2, guest PC 0x0c0cac60 */
if(!s->budget--) { s->failed_pc=0x0c0cac60u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cac62;
P_0c0cac62: /* original c802, guest PC 0x0c0cac62 */
if(!s->budget--) { s->failed_pc=0x0c0cac62u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cac64;
P_0c0cac64: /* original 8f1c, guest PC 0x0c0cac64 */
if(!s->budget--) { s->failed_pc=0x0c0cac64u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
if(!cond) { goto P_0c0caca0; }
goto P_0c0cac68;
P_0c0cac66: /* original f561, guest PC 0x0c0cac66 */
if(!s->budget--) { s->failed_pc=0x0c0cac66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0cac68;
P_0c0cac68: /* original 53f6, guest PC 0x0c0cac68 */
if(!s->budget--) { s->failed_pc=0x0c0cac68u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0cac6a;
P_0c0cac6a: /* original 2338, guest PC 0x0c0cac6a */
if(!s->budget--) { s->failed_pc=0x0c0cac6au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac6c;
P_0c0cac6c: /* original 8902, guest PC 0x0c0cac6c */
if(!s->budget--) { s->failed_pc=0x0c0cac6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac74; }
goto P_0c0cac6e;
P_0c0cac6e: /* original 933f, guest PC 0x0c0cac6e */
if(!s->budget--) { s->failed_pc=0x0c0cac6eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac70;
P_0c0cac70: /* original 2358, guest PC 0x0c0cac70 */
if(!s->budget--) { s->failed_pc=0x0c0cac70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0cac72;
P_0c0cac72: /* original 8910, guest PC 0x0c0cac72 */
if(!s->budget--) { s->failed_pc=0x0c0cac72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac96; }
goto P_0c0cac74;
P_0c0cac74: /* original f38d, guest PC 0x0c0cac74 */
if(!s->budget--) { s->failed_pc=0x0c0cac74u; return 0; }
fr[3]=0;
goto P_0c0cac76;
P_0c0cac76: /* original f835, guest PC 0x0c0cac76 */
if(!s->budget--) { s->failed_pc=0x0c0cac76u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[3]))!=0);
goto P_0c0cac78;
P_0c0cac78: /* original 8908, guest PC 0x0c0cac78 */
if(!s->budget--) { s->failed_pc=0x0c0cac78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac7a;
P_0c0cac7a: /* original 2888, guest PC 0x0c0cac7a */
if(!s->budget--) { s->failed_pc=0x0c0cac7au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0cac7c;
P_0c0cac7c: /* original 8b06, guest PC 0x0c0cac7c */
if(!s->budget--) { s->failed_pc=0x0c0cac7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cac8c; }
goto P_0c0cac7e;
P_0c0cac7e: /* original 53f9, guest PC 0x0c0cac7e */
if(!s->budget--) { s->failed_pc=0x0c0cac7eu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0cac80;
P_0c0cac80: /* original 2338, guest PC 0x0c0cac80 */
if(!s->budget--) { s->failed_pc=0x0c0cac80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cac82;
P_0c0cac82: /* original 8902, guest PC 0x0c0cac82 */
if(!s->budget--) { s->failed_pc=0x0c0cac82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8a; }
goto P_0c0cac84;
P_0c0cac84: /* original 9234, guest PC 0x0c0cac84 */
if(!s->budget--) { s->failed_pc=0x0c0cac84u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf0u,2);
goto P_0c0cac86;
P_0c0cac86: /* original 2258, guest PC 0x0c0cac86 */
if(!s->budget--) { s->failed_pc=0x0c0cac86u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0cac88;
P_0c0cac88: /* original 8900, guest PC 0x0c0cac88 */
if(!s->budget--) { s->failed_pc=0x0c0cac88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cac8c; }
goto P_0c0cac8a;
P_0c0cac8a: /* original 2c4b, guest PC 0x0c0cac8a */
if(!s->budget--) { s->failed_pc=0x0c0cac8au; return 0; }
r[12]|=r[4];
goto P_0c0cac8c;
P_0c0cac8c: /* original f38d, guest PC 0x0c0cac8c */
if(!s->budget--) { s->failed_pc=0x0c0cac8cu; return 0; }
fr[3]=0;
goto P_0c0cac8e;
P_0c0cac8e: /* original f535, guest PC 0x0c0cac8e */
if(!s->budget--) { s->failed_pc=0x0c0cac8eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac90;
P_0c0cac90: /* original 890b, guest PC 0x0c0cac90 */
if(!s->budget--) { s->failed_pc=0x0c0cac90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac92;
P_0c0cac92: /* original a00a, guest PC 0x0c0cac92 */
if(!s->budget--) { s->failed_pc=0x0c0cac92u; return 0; }
r[9]|=r[4];
goto P_0c0cacaa;
P_0c0cac94: /* original 294b, guest PC 0x0c0cac94 */
if(!s->budget--) { s->failed_pc=0x0c0cac94u; return 0; }
r[9]|=r[4];
goto P_0c0cac96;
P_0c0cac96: /* original f38d, guest PC 0x0c0cac96 */
if(!s->budget--) { s->failed_pc=0x0c0cac96u; return 0; }
fr[3]=0;
goto P_0c0cac98;
P_0c0cac98: /* original f535, guest PC 0x0c0cac98 */
if(!s->budget--) { s->failed_pc=0x0c0cac98u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cac9a;
P_0c0cac9a: /* original 8906, guest PC 0x0c0cac9a */
if(!s->budget--) { s->failed_pc=0x0c0cac9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacaa; }
goto P_0c0cac9c;
P_0c0cac9c: /* original a005, guest PC 0x0c0cac9c */
if(!s->budget--) { s->failed_pc=0x0c0cac9cu; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cac9e: /* original 2b4b, guest PC 0x0c0cac9e */
if(!s->budget--) { s->failed_pc=0x0c0cac9eu; return 0; }
r[11]|=r[4];
goto P_0c0caca0;
P_0c0caca0: /* original 52f4, guest PC 0x0c0caca0 */
if(!s->budget--) { s->failed_pc=0x0c0caca0u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caca2;
P_0c0caca2: /* original d316, guest PC 0x0c0caca2 */
if(!s->budget--) { s->failed_pc=0x0c0caca2u; return 0; }
r[3]=read(ram,0x0c0cacfcu,4);
goto P_0c0caca4;
P_0c0caca4: /* original 2238, guest PC 0x0c0caca4 */
if(!s->budget--) { s->failed_pc=0x0c0caca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caca6;
P_0c0caca6: /* original 8b00, guest PC 0x0c0caca6 */
if(!s->budget--) { s->failed_pc=0x0c0caca6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacaa; }
goto P_0c0caca8;
P_0c0caca8: /* original 2b4b, guest PC 0x0c0caca8 */
if(!s->budget--) { s->failed_pc=0x0c0caca8u; return 0; }
r[11]|=r[4];
goto P_0c0cacaa;
P_0c0cacaa: /* original 53f2, guest PC 0x0c0cacaa */
if(!s->budget--) { s->failed_pc=0x0c0cacaau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cacac;
P_0c0cacac: /* original 4401, guest PC 0x0c0cacac */
if(!s->budget--) { s->failed_pc=0x0c0cacacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0cacae;
P_0c0cacae: /* original 7601, guest PC 0x0c0cacae */
if(!s->budget--) { s->failed_pc=0x0c0cacaeu; return 0; }
r[6]+=0x00000001u;
goto P_0c0cacb0;
P_0c0cacb0: /* original 73ff, guest PC 0x0c0cacb0 */
if(!s->budget--) { s->failed_pc=0x0c0cacb0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cacb2;
P_0c0cacb2: /* original 2338, guest PC 0x0c0cacb2 */
if(!s->budget--) { s->failed_pc=0x0c0cacb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0cacb4;
P_0c0cacb4: /* original 8f91, guest PC 0x0c0cacb4 */
if(!s->budget--) { s->failed_pc=0x0c0cacb4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c0cabda; }
goto P_0c0cacb8;
P_0c0cacb6: /* original 1f32, guest PC 0x0c0cacb6 */
if(!s->budget--) { s->failed_pc=0x0c0cacb6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cacb8;
P_0c0cacb8: /* original e061, guest PC 0x0c0cacb8 */
if(!s->budget--) { s->failed_pc=0x0c0cacb8u; return 0; }
r[0]=0x00000061u;
goto P_0c0cacba;
P_0c0cacba: /* original 00ec, guest PC 0x0c0cacba */
if(!s->budget--) { s->failed_pc=0x0c0cacbau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cacbc;
P_0c0cacbc: /* original 600c, guest PC 0x0c0cacbc */
if(!s->budget--) { s->failed_pc=0x0c0cacbcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cacbe;
P_0c0cacbe: /* original 8809, guest PC 0x0c0cacbe */
if(!s->budget--) { s->failed_pc=0x0c0cacbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cacc0;
P_0c0cacc0: /* original 8905, guest PC 0x0c0cacc0 */
if(!s->budget--) { s->failed_pc=0x0c0cacc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cacce; }
goto P_0c0cacc2;
P_0c0cacc2: /* original 9017, guest PC 0x0c0cacc2 */
if(!s->budget--) { s->failed_pc=0x0c0cacc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf4u,2);
goto P_0c0cacc4;
P_0c0cacc4: /* original 53f8, guest PC 0x0c0cacc4 */
if(!s->budget--) { s->failed_pc=0x0c0cacc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0cacc6;
P_0c0cacc6: /* original 9214, guest PC 0x0c0cacc6 */
if(!s->budget--) { s->failed_pc=0x0c0cacc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf2u,2);
goto P_0c0cacc8;
P_0c0cacc8: /* original 013e, guest PC 0x0c0cacc8 */
if(!s->budget--) { s->failed_pc=0x0c0cacc8u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c0cacca;
P_0c0cacca: /* original 2128, guest PC 0x0c0cacca */
if(!s->budget--) { s->failed_pc=0x0c0caccau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0caccc;
P_0c0caccc: /* original 8b08, guest PC 0x0c0caccc */
if(!s->budget--) { s->failed_pc=0x0c0cacccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cace0; }
goto P_0c0cacce;
P_0c0cacce: /* original 9012, guest PC 0x0c0cacce */
if(!s->budget--) { s->failed_pc=0x0c0cacceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf6u,2);
goto P_0c0cacd0;
P_0c0cacd0: /* original 64f3, guest PC 0x0c0cacd0 */
if(!s->budget--) { s->failed_pc=0x0c0cacd0u; return 0; }
r[4]=r[15];
goto P_0c0cacd2;
P_0c0cacd2: /* original d30b, guest PC 0x0c0cacd2 */
if(!s->budget--) { s->failed_pc=0x0c0cacd2u; return 0; }
r[3]=read(ram,0x0c0cad00u,4);
goto P_0c0cacd4;
P_0c0cacd4: /* original 7404, guest PC 0x0c0cacd4 */
if(!s->budget--) { s->failed_pc=0x0c0cacd4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0cacd6;
P_0c0cacd6: /* original 430b, guest PC 0x0c0cacd6 */
if(!s->budget--) { s->failed_pc=0x0c0cacd6u; return 0; }
target=r[3];
r[16]=0x0c0cacdau;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cacdau) { target=s->pc; goto dispatch; }
goto P_0c0cacda;
P_0c0cacd8: /* original f4e6, guest PC 0x0c0cacd8 */
if(!s->budget--) { s->failed_pc=0x0c0cacd8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cacda;
P_0c0cacda: /* original f38d, guest PC 0x0c0cacda */
if(!s->budget--) { s->failed_pc=0x0c0cacdau; return 0; }
fr[3]=0;
goto P_0c0cacdc;
P_0c0cacdc: /* original f035, guest PC 0x0c0cacdc */
if(!s->budget--) { s->failed_pc=0x0c0cacdcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0cacde;
P_0c0cacde: /* original 8b05, guest PC 0x0c0cacde */
if(!s->budget--) { s->failed_pc=0x0c0cacdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cacec; }
goto P_0c0cace0;
P_0c0cace0: /* original 2bb8, guest PC 0x0c0cace0 */
if(!s->budget--) { s->failed_pc=0x0c0cace0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0cace2;
P_0c0cace2: /* original 8b0f, guest PC 0x0c0cace2 */
if(!s->budget--) { s->failed_pc=0x0c0cace2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cace4;
P_0c0cace4: /* original 9008, guest PC 0x0c0cace4 */
if(!s->budget--) { s->failed_pc=0x0c0cace4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cacf8u,2);
goto P_0c0cace6;
P_0c0cace6: /* original 00ee, guest PC 0x0c0cace6 */
if(!s->budget--) { s->failed_pc=0x0c0cace6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0cace8;
P_0c0cace8: /* original c804, guest PC 0x0c0cace8 */
if(!s->budget--) { s->failed_pc=0x0c0cace8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0cacea;
P_0c0cacea: /* original 8b0b, guest PC 0x0c0cacea */
if(!s->budget--) { s->failed_pc=0x0c0caceau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cad04; }
goto P_0c0cacec;
P_0c0cacec: /* original a01c, guest PC 0x0c0cacec */
if(!s->budget--) { s->failed_pc=0x0c0cacecu; return 0; }
r[12]=r[10];
goto P_0c0cad28;
P_0c0cacee: /* original 6ca3, guest PC 0x0c0cacee */
if(!s->budget--) { s->failed_pc=0x0c0caceeu; return 0; }
r[12]=r[10];
return vf3_matrix_family(0x0c0cacf0u,s,ram);
P_0c0cad04: /* original 905e, guest PC 0x0c0cad04 */
if(!s->budget--) { s->failed_pc=0x0c0cad04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc4u,2);
goto P_0c0cad06;
P_0c0cad06: /* original d332, guest PC 0x0c0cad06 */
if(!s->budget--) { s->failed_pc=0x0c0cad06u; return 0; }
r[3]=read(ram,0x0c0cadd0u,4);
goto P_0c0cad08;
P_0c0cad08: /* original 02ee, guest PC 0x0c0cad08 */
if(!s->budget--) { s->failed_pc=0x0c0cad08u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cad0a;
P_0c0cad0a: /* original 2238, guest PC 0x0c0cad0a */
if(!s->budget--) { s->failed_pc=0x0c0cad0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cad0c;
P_0c0cad0c: /* original 8908, guest PC 0x0c0cad0c */
if(!s->budget--) { s->failed_pc=0x0c0cad0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cad20; }
goto P_0c0cad0e;
P_0c0cad0e: /* original 905a, guest PC 0x0c0cad0e */
if(!s->budget--) { s->failed_pc=0x0c0cad0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc6u,2);
goto P_0c0cad10;
P_0c0cad10: /* original 01ec, guest PC 0x0c0cad10 */
if(!s->budget--) { s->failed_pc=0x0c0cad10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cad12;
P_0c0cad12: /* original d030, guest PC 0x0c0cad12 */
if(!s->budget--) { s->failed_pc=0x0c0cad12u; return 0; }
r[0]=read(ram,0x0c0cadd4u,4);
goto P_0c0cad14;
P_0c0cad14: /* original 611c, guest PC 0x0c0cad14 */
if(!s->budget--) { s->failed_pc=0x0c0cad14u; return 0; }
r[1]=r[1]&255u;
goto P_0c0cad16;
P_0c0cad16: /* original 4108, guest PC 0x0c0cad16 */
if(!s->budget--) { s->failed_pc=0x0c0cad16u; return 0; }
r[1]<<=2;
goto P_0c0cad18;
P_0c0cad18: /* original 031e, guest PC 0x0c0cad18 */
if(!s->budget--) { s->failed_pc=0x0c0cad18u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c0cad1a;
P_0c0cad1a: /* original 6237, guest PC 0x0c0cad1a */
if(!s->budget--) { s->failed_pc=0x0c0cad1au; return 0; }
r[2]=~r[3];
goto P_0c0cad1c;
P_0c0cad1c: /* original 2f32, guest PC 0x0c0cad1c */
if(!s->budget--) { s->failed_pc=0x0c0cad1cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cad1e;
P_0c0cad1e: /* original 2c29, guest PC 0x0c0cad1e */
if(!s->budget--) { s->failed_pc=0x0c0cad1eu; return 0; }
r[12]&=r[2];
goto P_0c0cad20;
P_0c0cad20: /* original 6397, guest PC 0x0c0cad20 */
if(!s->budget--) { s->failed_pc=0x0c0cad20u; return 0; }
r[3]=~r[9];
goto P_0c0cad22;
P_0c0cad22: /* original 62b7, guest PC 0x0c0cad22 */
if(!s->budget--) { s->failed_pc=0x0c0cad22u; return 0; }
r[2]=~r[11];
goto P_0c0cad24;
P_0c0cad24: /* original 2c39, guest PC 0x0c0cad24 */
if(!s->budget--) { s->failed_pc=0x0c0cad24u; return 0; }
r[12]&=r[3];
goto P_0c0cad26;
P_0c0cad26: /* original 2c29, guest PC 0x0c0cad26 */
if(!s->budget--) { s->failed_pc=0x0c0cad26u; return 0; }
r[12]&=r[2];
goto P_0c0cad28;
P_0c0cad28: /* original 904e, guest PC 0x0c0cad28 */
if(!s->budget--) { s->failed_pc=0x0c0cad28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadc8u,2);
goto P_0c0cad2a;
P_0c0cad2a: /* original d82b, guest PC 0x0c0cad2a */
if(!s->budget--) { s->failed_pc=0x0c0cad2au; return 0; }
r[8]=read(ram,0x0c0cadd8u,4);
goto P_0c0cad2c;
P_0c0cad2c: /* original 0ec6, guest PC 0x0c0cad2c */
if(!s->budget--) { s->failed_pc=0x0c0cad2cu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0cad2e;
P_0c0cad2e: /* original 904c, guest PC 0x0c0cad2e */
if(!s->budget--) { s->failed_pc=0x0c0cad2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadcau,2);
goto P_0c0cad30;
P_0c0cad30: /* original 0e96, guest PC 0x0c0cad30 */
if(!s->budget--) { s->failed_pc=0x0c0cad30u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad32;
P_0c0cad32: /* original 70f8, guest PC 0x0c0cad32 */
if(!s->budget--) { s->failed_pc=0x0c0cad32u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cad34;
P_0c0cad34: /* original 0eb6, guest PC 0x0c0cad34 */
if(!s->budget--) { s->failed_pc=0x0c0cad34u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cad36;
P_0c0cad36: /* original 2fc2, guest PC 0x0c0cad36 */
if(!s->budget--) { s->failed_pc=0x0c0cad36u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0cad38;
P_0c0cad38: /* original 1fa2, guest PC 0x0c0cad38 */
if(!s->budget--) { s->failed_pc=0x0c0cad38u; return 0; }
write(ram,r[15]+8,r[10],4);
goto P_0c0cad3a;
P_0c0cad3a: /* original dc28, guest PC 0x0c0cad3a */
if(!s->budget--) { s->failed_pc=0x0c0cad3au; return 0; }
r[12]=read(ram,0x0c0caddcu,4);
goto P_0c0cad3c;
P_0c0cad3c: /* original 4c0b, guest PC 0x0c0cad3c */
if(!s->budget--) { s->failed_pc=0x0c0cad3cu; return 0; }
target=r[12];
r[16]=0x0c0cad40u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cad40u) { target=s->pc; goto dispatch; }
goto P_0c0cad40;
P_0c0cad3e: /* original 64f2, guest PC 0x0c0cad3e */
if(!s->budget--) { s->failed_pc=0x0c0cad3eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad40;
P_0c0cad40: /* original 8820, guest PC 0x0c0cad40 */
if(!s->budget--) { s->failed_pc=0x0c0cad40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad42;
P_0c0cad42: /* original 8d10, guest PC 0x0c0cad42 */
if(!s->budget--) { s->failed_pc=0x0c0cad42u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad66; }
goto P_0c0cad46;
P_0c0cad44: /* original 6403, guest PC 0x0c0cad44 */
if(!s->budget--) { s->failed_pc=0x0c0cad44u; return 0; }
r[4]=r[0];
goto P_0c0cad46;
P_0c0cad46: /* original 6043, guest PC 0x0c0cad46 */
if(!s->budget--) { s->failed_pc=0x0c0cad46u; return 0; }
r[0]=r[4];
goto P_0c0cad48;
P_0c0cad48: /* original 058c, guest PC 0x0c0cad48 */
if(!s->budget--) { s->failed_pc=0x0c0cad48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad4a;
P_0c0cad4a: /* original 52f2, guest PC 0x0c0cad4a */
if(!s->budget--) { s->failed_pc=0x0c0cad4au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0cad4c;
P_0c0cad4c: /* original 635b, guest PC 0x0c0cad4c */
if(!s->budget--) { s->failed_pc=0x0c0cad4cu; return 0; }
r[3]=0u-r[5];
goto P_0c0cad4e;
P_0c0cad4e: /* original 65d3, guest PC 0x0c0cad4e */
if(!s->budget--) { s->failed_pc=0x0c0cad4eu; return 0; }
r[5]=r[13];
goto P_0c0cad50;
P_0c0cad50: /* original 453d, guest PC 0x0c0cad50 */
if(!s->budget--) { s->failed_pc=0x0c0cad50u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad52;
P_0c0cad52: /* original 634b, guest PC 0x0c0cad52 */
if(!s->budget--) { s->failed_pc=0x0c0cad52u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad54;
P_0c0cad54: /* original 64d3, guest PC 0x0c0cad54 */
if(!s->budget--) { s->failed_pc=0x0c0cad54u; return 0; }
r[4]=r[13];
goto P_0c0cad56;
P_0c0cad56: /* original 443d, guest PC 0x0c0cad56 */
if(!s->budget--) { s->failed_pc=0x0c0cad56u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad58;
P_0c0cad58: /* original 6447, guest PC 0x0c0cad58 */
if(!s->budget--) { s->failed_pc=0x0c0cad58u; return 0; }
r[4]=~r[4];
goto P_0c0cad5a;
P_0c0cad5a: /* original 252b, guest PC 0x0c0cad5a */
if(!s->budget--) { s->failed_pc=0x0c0cad5au; return 0; }
r[5]|=r[2];
goto P_0c0cad5c;
P_0c0cad5c: /* original 1f52, guest PC 0x0c0cad5c */
if(!s->budget--) { s->failed_pc=0x0c0cad5cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0cad5e;
P_0c0cad5e: /* original 63f2, guest PC 0x0c0cad5e */
if(!s->budget--) { s->failed_pc=0x0c0cad5eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cad60;
P_0c0cad60: /* original 2439, guest PC 0x0c0cad60 */
if(!s->budget--) { s->failed_pc=0x0c0cad60u; return 0; }
r[4]&=r[3];
goto P_0c0cad62;
P_0c0cad62: /* original afeb, guest PC 0x0c0cad62 */
if(!s->budget--) { s->failed_pc=0x0c0cad62u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad3c;
P_0c0cad64: /* original 2f42, guest PC 0x0c0cad64 */
if(!s->budget--) { s->failed_pc=0x0c0cad64u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad66;
P_0c0cad66: /* original 9031, guest PC 0x0c0cad66 */
if(!s->budget--) { s->failed_pc=0x0c0cad66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadccu,2);
goto P_0c0cad68;
P_0c0cad68: /* original 53f2, guest PC 0x0c0cad68 */
if(!s->budget--) { s->failed_pc=0x0c0cad68u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0cad6a;
P_0c0cad6a: /* original 0e36, guest PC 0x0c0cad6a */
if(!s->budget--) { s->failed_pc=0x0c0cad6au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0cad6c;
P_0c0cad6c: /* original 2f92, guest PC 0x0c0cad6c */
if(!s->budget--) { s->failed_pc=0x0c0cad6cu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c0cad6e;
P_0c0cad6e: /* original 69a3, guest PC 0x0c0cad6e */
if(!s->budget--) { s->failed_pc=0x0c0cad6eu; return 0; }
r[9]=r[10];
goto P_0c0cad70;
P_0c0cad70: /* original 4c0b, guest PC 0x0c0cad70 */
if(!s->budget--) { s->failed_pc=0x0c0cad70u; return 0; }
target=r[12];
r[16]=0x0c0cad74u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cad74u) { target=s->pc; goto dispatch; }
goto P_0c0cad74;
P_0c0cad72: /* original 64f2, guest PC 0x0c0cad72 */
if(!s->budget--) { s->failed_pc=0x0c0cad72u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cad74;
P_0c0cad74: /* original 8820, guest PC 0x0c0cad74 */
if(!s->budget--) { s->failed_pc=0x0c0cad74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cad76;
P_0c0cad76: /* original 8d0e, guest PC 0x0c0cad76 */
if(!s->budget--) { s->failed_pc=0x0c0cad76u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cad96; }
goto P_0c0cad7a;
P_0c0cad78: /* original 6403, guest PC 0x0c0cad78 */
if(!s->budget--) { s->failed_pc=0x0c0cad78u; return 0; }
r[4]=r[0];
goto P_0c0cad7a;
P_0c0cad7a: /* original 6043, guest PC 0x0c0cad7a */
if(!s->budget--) { s->failed_pc=0x0c0cad7au; return 0; }
r[0]=r[4];
goto P_0c0cad7c;
P_0c0cad7c: /* original 058c, guest PC 0x0c0cad7c */
if(!s->budget--) { s->failed_pc=0x0c0cad7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cad7e;
P_0c0cad7e: /* original 62f2, guest PC 0x0c0cad7e */
if(!s->budget--) { s->failed_pc=0x0c0cad7eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cad80;
P_0c0cad80: /* original 635b, guest PC 0x0c0cad80 */
if(!s->budget--) { s->failed_pc=0x0c0cad80u; return 0; }
r[3]=0u-r[5];
goto P_0c0cad82;
P_0c0cad82: /* original 65d3, guest PC 0x0c0cad82 */
if(!s->budget--) { s->failed_pc=0x0c0cad82u; return 0; }
r[5]=r[13];
goto P_0c0cad84;
P_0c0cad84: /* original 453d, guest PC 0x0c0cad84 */
if(!s->budget--) { s->failed_pc=0x0c0cad84u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cad86;
P_0c0cad86: /* original 634b, guest PC 0x0c0cad86 */
if(!s->budget--) { s->failed_pc=0x0c0cad86u; return 0; }
r[3]=0u-r[4];
goto P_0c0cad88;
P_0c0cad88: /* original 64d3, guest PC 0x0c0cad88 */
if(!s->budget--) { s->failed_pc=0x0c0cad88u; return 0; }
r[4]=r[13];
goto P_0c0cad8a;
P_0c0cad8a: /* original 443d, guest PC 0x0c0cad8a */
if(!s->budget--) { s->failed_pc=0x0c0cad8au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cad8c;
P_0c0cad8c: /* original 6447, guest PC 0x0c0cad8c */
if(!s->budget--) { s->failed_pc=0x0c0cad8cu; return 0; }
r[4]=~r[4];
goto P_0c0cad8e;
P_0c0cad8e: /* original 2429, guest PC 0x0c0cad8e */
if(!s->budget--) { s->failed_pc=0x0c0cad8eu; return 0; }
r[4]&=r[2];
goto P_0c0cad90;
P_0c0cad90: /* original 295b, guest PC 0x0c0cad90 */
if(!s->budget--) { s->failed_pc=0x0c0cad90u; return 0; }
r[9]|=r[5];
goto P_0c0cad92;
P_0c0cad92: /* original afed, guest PC 0x0c0cad92 */
if(!s->budget--) { s->failed_pc=0x0c0cad92u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad70;
P_0c0cad94: /* original 2f42, guest PC 0x0c0cad94 */
if(!s->budget--) { s->failed_pc=0x0c0cad94u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad96;
P_0c0cad96: /* original 901a, guest PC 0x0c0cad96 */
if(!s->budget--) { s->failed_pc=0x0c0cad96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cadceu,2);
goto P_0c0cad98;
P_0c0cad98: /* original 0e96, guest PC 0x0c0cad98 */
if(!s->budget--) { s->failed_pc=0x0c0cad98u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c0cad9a;
P_0c0cad9a: /* original 2fb2, guest PC 0x0c0cad9a */
if(!s->budget--) { s->failed_pc=0x0c0cad9au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c0cad9c;
P_0c0cad9c: /* original 6ba3, guest PC 0x0c0cad9c */
if(!s->budget--) { s->failed_pc=0x0c0cad9cu; return 0; }
r[11]=r[10];
goto P_0c0cad9e;
P_0c0cad9e: /* original 4c0b, guest PC 0x0c0cad9e */
if(!s->budget--) { s->failed_pc=0x0c0cad9eu; return 0; }
target=r[12];
r[16]=0x0c0cada2u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cada2u) { target=s->pc; goto dispatch; }
goto P_0c0cada2;
P_0c0cada0: /* original 64f2, guest PC 0x0c0cada0 */
if(!s->budget--) { s->failed_pc=0x0c0cada0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0cada2;
P_0c0cada2: /* original 8820, guest PC 0x0c0cada2 */
if(!s->budget--) { s->failed_pc=0x0c0cada2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0cada4;
P_0c0cada4: /* original 8d1c, guest PC 0x0c0cada4 */
if(!s->budget--) { s->failed_pc=0x0c0cada4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0cade0; }
goto P_0c0cada8;
P_0c0cada6: /* original 6403, guest PC 0x0c0cada6 */
if(!s->budget--) { s->failed_pc=0x0c0cada6u; return 0; }
r[4]=r[0];
goto P_0c0cada8;
P_0c0cada8: /* original 6043, guest PC 0x0c0cada8 */
if(!s->budget--) { s->failed_pc=0x0c0cada8u; return 0; }
r[0]=r[4];
goto P_0c0cadaa;
P_0c0cadaa: /* original 058c, guest PC 0x0c0cadaa */
if(!s->budget--) { s->failed_pc=0x0c0cadaau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0cadac;
P_0c0cadac: /* original 62f2, guest PC 0x0c0cadac */
if(!s->budget--) { s->failed_pc=0x0c0cadacu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0cadae;
P_0c0cadae: /* original 635b, guest PC 0x0c0cadae */
if(!s->budget--) { s->failed_pc=0x0c0cadaeu; return 0; }
r[3]=0u-r[5];
goto P_0c0cadb0;
P_0c0cadb0: /* original 65d3, guest PC 0x0c0cadb0 */
if(!s->budget--) { s->failed_pc=0x0c0cadb0u; return 0; }
r[5]=r[13];
goto P_0c0cadb2;
P_0c0cadb2: /* original 453d, guest PC 0x0c0cadb2 */
if(!s->budget--) { s->failed_pc=0x0c0cadb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0cadb4;
P_0c0cadb4: /* original 634b, guest PC 0x0c0cadb4 */
if(!s->budget--) { s->failed_pc=0x0c0cadb4u; return 0; }
r[3]=0u-r[4];
goto P_0c0cadb6;
P_0c0cadb6: /* original 64d3, guest PC 0x0c0cadb6 */
if(!s->budget--) { s->failed_pc=0x0c0cadb6u; return 0; }
r[4]=r[13];
goto P_0c0cadb8;
P_0c0cadb8: /* original 443d, guest PC 0x0c0cadb8 */
if(!s->budget--) { s->failed_pc=0x0c0cadb8u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0cadba;
P_0c0cadba: /* original 6447, guest PC 0x0c0cadba */
if(!s->budget--) { s->failed_pc=0x0c0cadbau; return 0; }
r[4]=~r[4];
goto P_0c0cadbc;
P_0c0cadbc: /* original 2429, guest PC 0x0c0cadbc */
if(!s->budget--) { s->failed_pc=0x0c0cadbcu; return 0; }
r[4]&=r[2];
goto P_0c0cadbe;
P_0c0cadbe: /* original 2b5b, guest PC 0x0c0cadbe */
if(!s->budget--) { s->failed_pc=0x0c0cadbeu; return 0; }
r[11]|=r[5];
goto P_0c0cadc0;
P_0c0cadc0: /* original afed, guest PC 0x0c0cadc0 */
if(!s->budget--) { s->failed_pc=0x0c0cadc0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0cad9e;
P_0c0cadc2: /* original 2f42, guest PC 0x0c0cadc2 */
if(!s->budget--) { s->failed_pc=0x0c0cadc2u; return 0; }
write(ram,r[15],r[4],4);
return vf3_matrix_family(0x0c0cadc4u,s,ram);
P_0c0cade0: /* original 9088, guest PC 0x0c0cade0 */
if(!s->budget--) { s->failed_pc=0x0c0cade0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef4u,2);
goto P_0c0cade2;
P_0c0cade2: /* original 0eb6, guest PC 0x0c0cade2 */
if(!s->budget--) { s->failed_pc=0x0c0cade2u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c0cade4;
P_0c0cade4: /* original 52f4, guest PC 0x0c0cade4 */
if(!s->budget--) { s->failed_pc=0x0c0cade4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0cade6;
P_0c0cade6: /* original 9386, guest PC 0x0c0cade6 */
if(!s->budget--) { s->failed_pc=0x0c0cade6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef6u,2);
goto P_0c0cade8;
P_0c0cade8: /* original fe8d, guest PC 0x0c0cade8 */
if(!s->budget--) { s->failed_pc=0x0c0cade8u; return 0; }
fr[14]=0;
goto P_0c0cadea;
P_0c0cadea: /* original 2238, guest PC 0x0c0cadea */
if(!s->budget--) { s->failed_pc=0x0c0cadeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cadec;
P_0c0cadec: /* original ffec, guest PC 0x0c0cadec */
if(!s->budget--) { s->failed_pc=0x0c0cadecu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0cadee;
P_0c0cadee: /* original 8f02, guest PC 0x0c0cadee */
if(!s->budget--) { s->failed_pc=0x0c0cadeeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,14);
if(!cond) { goto P_0c0cadf6; }
goto P_0c0cadf2;
P_0c0cadf0: /* original fdec, guest PC 0x0c0cadf0 */
if(!s->budget--) { s->failed_pc=0x0c0cadf0u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0cadf2;
P_0c0cadf2: /* original a0a1, guest PC 0x0c0cadf2 */
if(!s->budget--) { s->failed_pc=0x0c0cadf2u; return 0; }
goto P_0c0caf38;
P_0c0cadf4: /* original 0009, guest PC 0x0c0cadf4 */
if(!s->budget--) { s->failed_pc=0x0c0cadf4u; return 0; }
goto P_0c0cadf6;
P_0c0cadf6: /* original 50f7, guest PC 0x0c0cadf6 */
if(!s->budget--) { s->failed_pc=0x0c0cadf6u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0cadf8;
P_0c0cadf8: /* original e11c, guest PC 0x0c0cadf8 */
if(!s->budget--) { s->failed_pc=0x0c0cadf8u; return 0; }
r[1]=0x0000001cu;
goto P_0c0cadfa;
P_0c0cadfa: /* original 001c, guest PC 0x0c0cadfa */
if(!s->budget--) { s->failed_pc=0x0c0cadfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0cadfc;
P_0c0cadfc: /* original 600c, guest PC 0x0c0cadfc */
if(!s->budget--) { s->failed_pc=0x0c0cadfcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cadfe;
P_0c0cadfe: /* original c90f, guest PC 0x0c0cadfe */
if(!s->budget--) { s->failed_pc=0x0c0cadfeu; return 0; }
r[0]&=15u;
goto P_0c0cae00;
P_0c0cae00: /* original 8801, guest PC 0x0c0cae00 */
if(!s->budget--) { s->failed_pc=0x0c0cae00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cae02;
P_0c0cae02: /* original 8b26, guest PC 0x0c0cae02 */
if(!s->budget--) { s->failed_pc=0x0c0cae02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae52; }
goto P_0c0cae04;
P_0c0cae04: /* original 63f3, guest PC 0x0c0cae04 */
if(!s->budget--) { s->failed_pc=0x0c0cae04u; return 0; }
r[3]=r[15];
goto P_0c0cae06;
P_0c0cae06: /* original 2f36, guest PC 0x0c0cae06 */
if(!s->budget--) { s->failed_pc=0x0c0cae06u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0cae08;
P_0c0cae08: /* original 65f3, guest PC 0x0c0cae08 */
if(!s->budget--) { s->failed_pc=0x0c0cae08u; return 0; }
r[5]=r[15];
goto P_0c0cae0a;
P_0c0cae0a: /* original d23f, guest PC 0x0c0cae0a */
if(!s->budget--) { s->failed_pc=0x0c0cae0au; return 0; }
r[2]=read(ram,0x0c0caf08u,4);
goto P_0c0cae0c;
P_0c0cae0c: /* original 66f3, guest PC 0x0c0cae0c */
if(!s->budget--) { s->failed_pc=0x0c0cae0cu; return 0; }
r[6]=r[15];
goto P_0c0cae0e;
P_0c0cae0e: /* original 67f3, guest PC 0x0c0cae0e */
if(!s->budget--) { s->failed_pc=0x0c0cae0eu; return 0; }
r[7]=r[15];
goto P_0c0cae10;
P_0c0cae10: /* original 7508, guest PC 0x0c0cae10 */
if(!s->budget--) { s->failed_pc=0x0c0cae10u; return 0; }
r[5]+=0x00000008u;
goto P_0c0cae12;
P_0c0cae12: /* original 7610, guest PC 0x0c0cae12 */
if(!s->budget--) { s->failed_pc=0x0c0cae12u; return 0; }
r[6]+=0x00000010u;
goto P_0c0cae14;
P_0c0cae14: /* original 7718, guest PC 0x0c0cae14 */
if(!s->budget--) { s->failed_pc=0x0c0cae14u; return 0; }
r[7]+=0x00000018u;
goto P_0c0cae16;
P_0c0cae16: /* original 420b, guest PC 0x0c0cae16 */
if(!s->budget--) { s->failed_pc=0x0c0cae16u; return 0; }
target=r[2];
r[16]=0x0c0cae1au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cae1au) { target=s->pc; goto dispatch; }
goto P_0c0cae1a;
P_0c0cae18: /* original 64e3, guest PC 0x0c0cae18 */
if(!s->budget--) { s->failed_pc=0x0c0cae18u; return 0; }
r[4]=r[14];
goto P_0c0cae1a;
P_0c0cae1a: /* original 906d, guest PC 0x0c0cae1a */
if(!s->budget--) { s->failed_pc=0x0c0cae1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caef8u,2);
goto P_0c0cae1c;
P_0c0cae1c: /* original 7f04, guest PC 0x0c0cae1c */
if(!s->budget--) { s->failed_pc=0x0c0cae1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cae1e;
P_0c0cae1e: /* original f3e6, guest PC 0x0c0cae1e */
if(!s->budget--) { s->failed_pc=0x0c0cae1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cae20;
P_0c0cae20: /* original e014, guest PC 0x0c0cae20 */
if(!s->budget--) { s->failed_pc=0x0c0cae20u; return 0; }
r[0]=0x00000014u;
goto P_0c0cae22;
P_0c0cae22: /* original ff37, guest PC 0x0c0cae22 */
if(!s->budget--) { s->failed_pc=0x0c0cae22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae24;
P_0c0cae24: /* original 9069, guest PC 0x0c0cae24 */
if(!s->budget--) { s->failed_pc=0x0c0cae24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefau,2);
goto P_0c0cae26;
P_0c0cae26: /* original f4e6, guest PC 0x0c0cae26 */
if(!s->budget--) { s->failed_pc=0x0c0cae26u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cae28;
P_0c0cae28: /* original e004, guest PC 0x0c0cae28 */
if(!s->budget--) { s->failed_pc=0x0c0cae28u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2a;
P_0c0cae2a: /* original f2f6, guest PC 0x0c0cae2a */
if(!s->budget--) { s->failed_pc=0x0c0cae2au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cae2c;
P_0c0cae2c: /* original e004, guest PC 0x0c0cae2c */
if(!s->budget--) { s->failed_pc=0x0c0cae2cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cae2e;
P_0c0cae2e: /* original f44d, guest PC 0x0c0cae2e */
if(!s->budget--) { s->failed_pc=0x0c0cae2eu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cae30;
P_0c0cae30: /* original f231, guest PC 0x0c0cae30 */
if(!s->budget--) { s->failed_pc=0x0c0cae30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cae32;
P_0c0cae32: /* original ff27, guest PC 0x0c0cae32 */
if(!s->budget--) { s->failed_pc=0x0c0cae32u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cae34;
P_0c0cae34: /* original e00c, guest PC 0x0c0cae34 */
if(!s->budget--) { s->failed_pc=0x0c0cae34u; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae36;
P_0c0cae36: /* original f1f6, guest PC 0x0c0cae36 */
if(!s->budget--) { s->failed_pc=0x0c0cae36u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cae38;
P_0c0cae38: /* original f222, guest PC 0x0c0cae38 */
if(!s->budget--) { s->failed_pc=0x0c0cae38u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[2],r[18],'*');
goto P_0c0cae3a;
P_0c0cae3a: /* original e00c, guest PC 0x0c0cae3a */
if(!s->budget--) { s->failed_pc=0x0c0cae3au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cae3c;
P_0c0cae3c: /* original f141, guest PC 0x0c0cae3c */
if(!s->budget--) { s->failed_pc=0x0c0cae3cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0cae3e;
P_0c0cae3e: /* original ff17, guest PC 0x0c0cae3e */
if(!s->budget--) { s->failed_pc=0x0c0cae3eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0cae40;
P_0c0cae40: /* original e004, guest PC 0x0c0cae40 */
if(!s->budget--) { s->failed_pc=0x0c0cae40u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae42;
P_0c0cae42: /* original f32c, guest PC 0x0c0cae42 */
if(!s->budget--) { s->failed_pc=0x0c0cae42u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0cae44;
P_0c0cae44: /* original f01c, guest PC 0x0c0cae44 */
if(!s->budget--) { s->failed_pc=0x0c0cae44u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c0cae46;
P_0c0cae46: /* original f31e, guest PC 0x0c0cae46 */
if(!s->budget--) { s->failed_pc=0x0c0cae46u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0cae48;
P_0c0cae48: /* original ff37, guest PC 0x0c0cae48 */
if(!s->budget--) { s->failed_pc=0x0c0cae48u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cae4a;
P_0c0cae4a: /* original c730, guest PC 0x0c0cae4a */
if(!s->budget--) { s->failed_pc=0x0c0cae4au; return 0; }
r[0]=0x0c0caf0cu;
goto P_0c0cae4c;
P_0c0cae4c: /* original f408, guest PC 0x0c0cae4c */
if(!s->budget--) { s->failed_pc=0x0c0cae4cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0cae4e;
P_0c0cae4e: /* original f345, guest PC 0x0c0cae4e */
if(!s->budget--) { s->failed_pc=0x0c0cae4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0cae50;
P_0c0cae50: /* original 8972, guest PC 0x0c0cae50 */
if(!s->budget--) { s->failed_pc=0x0c0cae50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf38; }
goto P_0c0cae52;
P_0c0cae52: /* original 9053, guest PC 0x0c0cae52 */
if(!s->budget--) { s->failed_pc=0x0c0cae52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefcu,2);
goto P_0c0cae54;
P_0c0cae54: /* original e506, guest PC 0x0c0cae54 */
if(!s->budget--) { s->failed_pc=0x0c0cae54u; return 0; }
r[5]=0x00000006u;
goto P_0c0cae56;
P_0c0cae56: /* original d32e, guest PC 0x0c0cae56 */
if(!s->budget--) { s->failed_pc=0x0c0cae56u; return 0; }
r[3]=read(ram,0x0c0caf10u,4);
goto P_0c0cae58;
P_0c0cae58: /* original 6453, guest PC 0x0c0cae58 */
if(!s->budget--) { s->failed_pc=0x0c0cae58u; return 0; }
r[4]=r[5];
goto P_0c0cae5a;
P_0c0cae5a: /* original f8e6, guest PC 0x0c0cae5a */
if(!s->budget--) { s->failed_pc=0x0c0cae5au; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0cae5c;
P_0c0cae5c: /* original 7004, guest PC 0x0c0cae5c */
if(!s->budget--) { s->failed_pc=0x0c0cae5cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0cae5e;
P_0c0cae5e: /* original f7e6, guest PC 0x0c0cae5e */
if(!s->budget--) { s->failed_pc=0x0c0cae5eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0cae60;
P_0c0cae60: /* original 701b, guest PC 0x0c0cae60 */
if(!s->budget--) { s->failed_pc=0x0c0cae60u; return 0; }
r[0]+=0x0000001bu;
goto P_0c0cae62;
P_0c0cae62: /* original 07ec, guest PC 0x0c0cae62 */
if(!s->budget--) { s->failed_pc=0x0c0cae62u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cae64;
P_0c0cae64: /* original 1f34, guest PC 0x0c0cae64 */
if(!s->budget--) { s->failed_pc=0x0c0cae64u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0cae66;
P_0c0cae66: /* original 677c, guest PC 0x0c0cae66 */
if(!s->budget--) { s->failed_pc=0x0c0cae66u; return 0; }
r[7]=r[7]&255u;
goto P_0c0cae68;
P_0c0cae68: /* original 6353, guest PC 0x0c0cae68 */
if(!s->budget--) { s->failed_pc=0x0c0cae68u; return 0; }
r[3]=r[5];
goto P_0c0cae6a;
P_0c0cae6a: /* original 3348, guest PC 0x0c0cae6a */
if(!s->budget--) { s->failed_pc=0x0c0cae6au; return 0; }
r[3]-=r[4];
goto P_0c0cae6c;
P_0c0cae6c: /* original 2f32, guest PC 0x0c0cae6c */
if(!s->budget--) { s->failed_pc=0x0c0cae6cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cae6e;
P_0c0cae6e: /* original 56f4, guest PC 0x0c0cae6e */
if(!s->budget--) { s->failed_pc=0x0c0cae6eu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0cae70;
P_0c0cae70: /* original d228, guest PC 0x0c0cae70 */
if(!s->budget--) { s->failed_pc=0x0c0cae70u; return 0; }
r[2]=read(ram,0x0c0caf14u,4);
goto P_0c0cae72;
P_0c0cae72: /* original 363c, guest PC 0x0c0cae72 */
if(!s->budget--) { s->failed_pc=0x0c0cae72u; return 0; }
r[6]+=r[3];
goto P_0c0cae74;
P_0c0cae74: /* original 6160, guest PC 0x0c0cae74 */
if(!s->budget--) { s->failed_pc=0x0c0cae74u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[1]=tmp;
goto P_0c0cae76;
P_0c0cae76: /* original 420b, guest PC 0x0c0cae76 */
if(!s->budget--) { s->failed_pc=0x0c0cae76u; return 0; }
target=r[2];
r[16]=0x0c0cae7au;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cae7au) { target=s->pc; goto dispatch; }
goto P_0c0cae7a;
P_0c0cae78: /* original e004, guest PC 0x0c0cae78 */
if(!s->budget--) { s->failed_pc=0x0c0cae78u; return 0; }
r[0]=0x00000004u;
goto P_0c0cae7a;
P_0c0cae7a: /* original 9340, guest PC 0x0c0cae7a */
if(!s->budget--) { s->failed_pc=0x0c0cae7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caefeu,2);
goto P_0c0cae7c;
P_0c0cae7c: /* original 660e, guest PC 0x0c0cae7c */
if(!s->budget--) { s->failed_pc=0x0c0cae7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0cae7e;
P_0c0cae7e: /* original 4608, guest PC 0x0c0cae7e */
if(!s->budget--) { s->failed_pc=0x0c0cae7eu; return 0; }
r[6]<<=2;
goto P_0c0cae80;
P_0c0cae80: /* original 33ec, guest PC 0x0c0cae80 */
if(!s->budget--) { s->failed_pc=0x0c0cae80u; return 0; }
r[3]+=r[14];
goto P_0c0cae82;
P_0c0cae82: /* original 363c, guest PC 0x0c0cae82 */
if(!s->budget--) { s->failed_pc=0x0c0cae82u; return 0; }
r[6]+=r[3];
goto P_0c0cae84;
P_0c0cae84: /* original 6662, guest PC 0x0c0cae84 */
if(!s->budget--) { s->failed_pc=0x0c0cae84u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0cae86;
P_0c0cae86: /* original e204, guest PC 0x0c0cae86 */
if(!s->budget--) { s->failed_pc=0x0c0cae86u; return 0; }
r[2]=0x00000004u;
goto P_0c0cae88;
P_0c0cae88: /* original 2628, guest PC 0x0c0cae88 */
if(!s->budget--) { s->failed_pc=0x0c0cae88u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0cae8a;
P_0c0cae8a: /* original 8902, guest PC 0x0c0cae8a */
if(!s->budget--) { s->failed_pc=0x0c0cae8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cae92; }
goto P_0c0cae8c;
P_0c0cae8c: /* original f58c, guest PC 0x0c0cae8c */
if(!s->budget--) { s->failed_pc=0x0c0cae8cu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0cae8e;
P_0c0cae8e: /* original a002, guest PC 0x0c0cae8e */
if(!s->budget--) { s->failed_pc=0x0c0cae8eu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae96;
P_0c0cae90: /* original f47c, guest PC 0x0c0cae90 */
if(!s->budget--) { s->failed_pc=0x0c0cae90u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cae92;
P_0c0cae92: /* original f48d, guest PC 0x0c0cae92 */
if(!s->budget--) { s->failed_pc=0x0c0cae92u; return 0; }
fr[4]=0;
goto P_0c0cae94;
P_0c0cae94: /* original f54c, guest PC 0x0c0cae94 */
if(!s->budget--) { s->failed_pc=0x0c0cae94u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cae96;
P_0c0cae96: /* original 4410, guest PC 0x0c0cae96 */
if(!s->budget--) { s->failed_pc=0x0c0cae96u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0cae98;
P_0c0cae98: /* original 8be6, guest PC 0x0c0cae98 */
if(!s->budget--) { s->failed_pc=0x0c0cae98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cae68; }
goto P_0c0cae9a;
P_0c0cae9a: /* original 9332, guest PC 0x0c0cae9a */
if(!s->budget--) { s->failed_pc=0x0c0cae9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf02u,2);
goto P_0c0cae9c;
P_0c0cae9c: /* original e41c, guest PC 0x0c0cae9c */
if(!s->budget--) { s->failed_pc=0x0c0cae9cu; return 0; }
r[4]=0x0000001cu;
goto P_0c0cae9e;
P_0c0cae9e: /* original 902f, guest PC 0x0c0cae9e */
if(!s->budget--) { s->failed_pc=0x0c0cae9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf00u,2);
goto P_0c0caea0;
P_0c0caea0: /* original 33ec, guest PC 0x0c0caea0 */
if(!s->budget--) { s->failed_pc=0x0c0caea0u; return 0; }
r[3]+=r[14];
goto P_0c0caea2;
P_0c0caea2: /* original 05ee, guest PC 0x0c0caea2 */
if(!s->budget--) { s->failed_pc=0x0c0caea2u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0caea4;
P_0c0caea4: /* original 1f32, guest PC 0x0c0caea4 */
if(!s->budget--) { s->failed_pc=0x0c0caea4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caea6;
P_0c0caea6: /* original 922d, guest PC 0x0c0caea6 */
if(!s->budget--) { s->failed_pc=0x0c0caea6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caf04u,2);
goto P_0c0caea8;
P_0c0caea8: /* original 32ec, guest PC 0x0c0caea8 */
if(!s->budget--) { s->failed_pc=0x0c0caea8u; return 0; }
r[2]+=r[14];
goto P_0c0caeaa;
P_0c0caeaa: /* original 1f24, guest PC 0x0c0caeaa */
if(!s->budget--) { s->failed_pc=0x0c0caeaau; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caeac;
P_0c0caeac: /* original 53f2, guest PC 0x0c0caeac */
if(!s->budget--) { s->failed_pc=0x0c0caeacu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0caeae;
P_0c0caeae: /* original e004, guest PC 0x0c0caeae */
if(!s->budget--) { s->failed_pc=0x0c0caeaeu; return 0; }
r[0]=0x00000004u;
goto P_0c0caeb0;
P_0c0caeb0: /* original f656, guest PC 0x0c0caeb0 */
if(!s->budget--) { s->failed_pc=0x0c0caeb0u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0caeb2;
P_0c0caeb2: /* original 7304, guest PC 0x0c0caeb2 */
if(!s->budget--) { s->failed_pc=0x0c0caeb2u; return 0; }
r[3]+=0x00000004u;
goto P_0c0caeb4;
P_0c0caeb4: /* original 1f32, guest PC 0x0c0caeb4 */
if(!s->budget--) { s->failed_pc=0x0c0caeb4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0caeb6;
P_0c0caeb6: /* original 73fc, guest PC 0x0c0caeb6 */
if(!s->budget--) { s->failed_pc=0x0c0caeb6u; return 0; }
r[3]+=0xfffffffcu;
goto P_0c0caeb8;
P_0c0caeb8: /* original 52f4, guest PC 0x0c0caeb8 */
if(!s->budget--) { s->failed_pc=0x0c0caeb8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0caeba;
P_0c0caeba: /* original fa38, guest PC 0x0c0caeba */
if(!s->budget--) { s->failed_pc=0x0c0caebau; return 0; }
vf3_matrix_load(s,ram,10,r[3]);
goto P_0c0caebc;
P_0c0caebc: /* original 7204, guest PC 0x0c0caebc */
if(!s->budget--) { s->failed_pc=0x0c0caebcu; return 0; }
r[2]+=0x00000004u;
goto P_0c0caebe;
P_0c0caebe: /* original f6a1, guest PC 0x0c0caebe */
if(!s->budget--) { s->failed_pc=0x0c0caebeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c0caec0;
P_0c0caec0: /* original 1f24, guest PC 0x0c0caec0 */
if(!s->budget--) { s->failed_pc=0x0c0caec0u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0caec2;
P_0c0caec2: /* original 72fc, guest PC 0x0c0caec2 */
if(!s->budget--) { s->failed_pc=0x0c0caec2u; return 0; }
r[2]+=0xfffffffcu;
goto P_0c0caec4;
P_0c0caec4: /* original f928, guest PC 0x0c0caec4 */
if(!s->budget--) { s->failed_pc=0x0c0caec4u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
goto P_0c0caec6;
P_0c0caec6: /* original f965, guest PC 0x0c0caec6 */
if(!s->budget--) { s->failed_pc=0x0c0caec6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[6]))!=0);
goto P_0c0caec8;
P_0c0caec8: /* original 8f2a, guest PC 0x0c0caec8 */
if(!s->budget--) { s->failed_pc=0x0c0caec8u; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000cu;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caecc;
P_0c0caeca: /* original 750c, guest PC 0x0c0caeca */
if(!s->budget--) { s->failed_pc=0x0c0caecau; return 0; }
r[5]+=0x0000000cu;
goto P_0c0caecc;
P_0c0caecc: /* original f961, guest PC 0x0c0caecc */
if(!s->budget--) { s->failed_pc=0x0c0caeccu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'-');
goto P_0c0caece;
P_0c0caece: /* original e004, guest PC 0x0c0caece */
if(!s->budget--) { s->failed_pc=0x0c0caeceu; return 0; }
r[0]=0x00000004u;
goto P_0c0caed0;
P_0c0caed0: /* original f39c, guest PC 0x0c0caed0 */
if(!s->budget--) { s->failed_pc=0x0c0caed0u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c0caed2;
P_0c0caed2: /* original f3f5, guest PC 0x0c0caed2 */
if(!s->budget--) { s->failed_pc=0x0c0caed2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0caed4;
P_0c0caed4: /* original 8f24, guest PC 0x0c0caed4 */
if(!s->budget--) { s->failed_pc=0x0c0caed4u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,9,r[15]+r[0]);
if(!cond) { goto P_0c0caf20; }
goto P_0c0caed8;
P_0c0caed6: /* original ff97, guest PC 0x0c0caed6 */
if(!s->budget--) { s->failed_pc=0x0c0caed6u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0caed8;
P_0c0caed8: /* original 6043, guest PC 0x0c0caed8 */
if(!s->budget--) { s->failed_pc=0x0c0caed8u; return 0; }
r[0]=r[4];
goto P_0c0caeda;
P_0c0caeda: /* original 880d, guest PC 0x0c0caeda */
if(!s->budget--) { s->failed_pc=0x0c0caedau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0caedc;
P_0c0caedc: /* original f58c, guest PC 0x0c0caedc */
if(!s->budget--) { s->failed_pc=0x0c0caedcu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0caede;
P_0c0caede: /* original 8d1d, guest PC 0x0c0caede */
if(!s->budget--) { s->failed_pc=0x0c0caedeu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,7);
if(cond) { goto P_0c0caf1c; }
goto P_0c0caee2;
P_0c0caee0: /* original f47c, guest PC 0x0c0caee0 */
if(!s->budget--) { s->failed_pc=0x0c0caee0u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0caee2;
P_0c0caee2: /* original e30d, guest PC 0x0c0caee2 */
if(!s->budget--) { s->failed_pc=0x0c0caee2u; return 0; }
r[3]=0x0000000du;
goto P_0c0caee4;
P_0c0caee4: /* original 3437, guest PC 0x0c0caee4 */
if(!s->budget--) { s->failed_pc=0x0c0caee4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0caee6;
P_0c0caee6: /* original e602, guest PC 0x0c0caee6 */
if(!s->budget--) { s->failed_pc=0x0c0caee6u; return 0; }
r[6]=0x00000002u;
goto P_0c0caee8;
P_0c0caee8: /* original 8d16, guest PC 0x0c0caee8 */
if(!s->budget--) { s->failed_pc=0x0c0caee8u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(cond) { goto P_0c0caf18; }
goto P_0c0caeec;
P_0c0caeea: /* original 2679, guest PC 0x0c0caeea */
if(!s->budget--) { s->failed_pc=0x0c0caeeau; return 0; }
r[6]&=r[7];
goto P_0c0caeec;
P_0c0caeec: /* original 2668, guest PC 0x0c0caeec */
if(!s->budget--) { s->failed_pc=0x0c0caeecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caeee;
P_0c0caeee: /* original 8b17, guest PC 0x0c0caeee */
if(!s->budget--) { s->failed_pc=0x0c0caeeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caf20; }
goto P_0c0caef0;
P_0c0caef0: /* original a014, guest PC 0x0c0caef0 */
if(!s->budget--) { s->failed_pc=0x0c0caef0u; return 0; }
goto P_0c0caf1c;
P_0c0caef2: /* original 0009, guest PC 0x0c0caef2 */
if(!s->budget--) { s->failed_pc=0x0c0caef2u; return 0; }
return vf3_matrix_family(0x0c0caef4u,s,ram);
P_0c0caf18: /* original 2668, guest PC 0x0c0caf18 */
if(!s->budget--) { s->failed_pc=0x0c0caf18u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0caf1a;
P_0c0caf1a: /* original 8901, guest PC 0x0c0caf1a */
if(!s->budget--) { s->failed_pc=0x0c0caf1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf20; }
goto P_0c0caf1c;
P_0c0caf1c: /* original e004, guest PC 0x0c0caf1c */
if(!s->budget--) { s->failed_pc=0x0c0caf1cu; return 0; }
r[0]=0x00000004u;
goto P_0c0caf1e;
P_0c0caf1e: /* original fff6, guest PC 0x0c0caf1e */
if(!s->budget--) { s->failed_pc=0x0c0caf1eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0caf20;
P_0c0caf20: /* original 4410, guest PC 0x0c0caf20 */
if(!s->budget--) { s->failed_pc=0x0c0caf20u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0caf22;
P_0c0caf22: /* original 8bc3, guest PC 0x0c0caf22 */
if(!s->budget--) { s->failed_pc=0x0c0caf22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caeac; }
goto P_0c0caf24;
P_0c0caf24: /* original 62e2, guest PC 0x0c0caf24 */
if(!s->budget--) { s->failed_pc=0x0c0caf24u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0caf26;
P_0c0caf26: /* original 9383, guest PC 0x0c0caf26 */
if(!s->budget--) { s->failed_pc=0x0c0caf26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb030u,2);
goto P_0c0caf28;
P_0c0caf28: /* original 2238, guest PC 0x0c0caf28 */
if(!s->budget--) { s->failed_pc=0x0c0caf28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caf2a;
P_0c0caf2a: /* original 8903, guest PC 0x0c0caf2a */
if(!s->budget--) { s->failed_pc=0x0c0caf2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0caf34; }
goto P_0c0caf2c;
P_0c0caf2c: /* original c742, guest PC 0x0c0caf2c */
if(!s->budget--) { s->failed_pc=0x0c0caf2cu; return 0; }
r[0]=0x0c0cb038u;
goto P_0c0caf2e;
P_0c0caf2e: /* original f608, guest PC 0x0c0caf2e */
if(!s->budget--) { s->failed_pc=0x0c0caf2eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0caf30;
P_0c0caf30: /* original f462, guest PC 0x0c0caf30 */
if(!s->budget--) { s->failed_pc=0x0c0caf30u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0caf32;
P_0c0caf32: /* original f562, guest PC 0x0c0caf32 */
if(!s->budget--) { s->failed_pc=0x0c0caf32u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0caf34;
P_0c0caf34: /* original fe4c, guest PC 0x0c0caf34 */
if(!s->budget--) { s->failed_pc=0x0c0caf34u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0caf36;
P_0c0caf36: /* original fd5c, guest PC 0x0c0caf36 */
if(!s->budget--) { s->failed_pc=0x0c0caf36u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0caf38;
P_0c0caf38: /* original 907b, guest PC 0x0c0caf38 */
if(!s->budget--) { s->failed_pc=0x0c0caf38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0caf3a;
P_0c0caf3a: /* original 7f3c, guest PC 0x0c0caf3a */
if(!s->budget--) { s->failed_pc=0x0c0caf3au; return 0; }
r[15]+=0x0000003cu;
goto P_0c0caf3c;
P_0c0caf3c: /* original 4f26, guest PC 0x0c0caf3c */
if(!s->budget--) { s->failed_pc=0x0c0caf3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0caf3e;
P_0c0caf3e: /* original fed7, guest PC 0x0c0caf3e */
if(!s->budget--) { s->failed_pc=0x0c0caf3eu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0caf40;
P_0c0caf40: /* original 7004, guest PC 0x0c0caf40 */
if(!s->budget--) { s->failed_pc=0x0c0caf40u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf42;
P_0c0caf42: /* original fef7, guest PC 0x0c0caf42 */
if(!s->budget--) { s->failed_pc=0x0c0caf42u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0caf44;
P_0c0caf44: /* original 7004, guest PC 0x0c0caf44 */
if(!s->budget--) { s->failed_pc=0x0c0caf44u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caf46;
P_0c0caf46: /* original fee7, guest PC 0x0c0caf46 */
if(!s->budget--) { s->failed_pc=0x0c0caf46u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0caf48;
P_0c0caf48: /* original fdf9, guest PC 0x0c0caf48 */
if(!s->budget--) { s->failed_pc=0x0c0caf48u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4a;
P_0c0caf4a: /* original fef9, guest PC 0x0c0caf4a */
if(!s->budget--) { s->failed_pc=0x0c0caf4au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4c;
P_0c0caf4c: /* original fff9, guest PC 0x0c0caf4c */
if(!s->budget--) { s->failed_pc=0x0c0caf4cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caf4e;
P_0c0caf4e: /* original 68f6, guest PC 0x0c0caf4e */
if(!s->budget--) { s->failed_pc=0x0c0caf4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0caf50;
P_0c0caf50: /* original 69f6, guest PC 0x0c0caf50 */
if(!s->budget--) { s->failed_pc=0x0c0caf50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0caf52;
P_0c0caf52: /* original 6af6, guest PC 0x0c0caf52 */
if(!s->budget--) { s->failed_pc=0x0c0caf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0caf54;
P_0c0caf54: /* original 6bf6, guest PC 0x0c0caf54 */
if(!s->budget--) { s->failed_pc=0x0c0caf54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0caf56;
P_0c0caf56: /* original 6cf6, guest PC 0x0c0caf56 */
if(!s->budget--) { s->failed_pc=0x0c0caf56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0caf58;
P_0c0caf58: /* original 6df6, guest PC 0x0c0caf58 */
if(!s->budget--) { s->failed_pc=0x0c0caf58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0caf5a;
P_0c0caf5a: /* original 000b, guest PC 0x0c0caf5a */
if(!s->budget--) { s->failed_pc=0x0c0caf5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0caf5c: /* original 6ef6, guest PC 0x0c0caf5c */
if(!s->budget--) { s->failed_pc=0x0c0caf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0caf5eu,s,ram);
P_0c0cc5f4: /* original 4f22, guest PC 0x0c0cc5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc5f6;
P_0c0cc5f6: /* original 6212, guest PC 0x0c0cc5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cc5f8;
P_0c0cc5f8: /* original d31c, guest PC 0x0c0cc5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f8u; return 0; }
r[3]=read(ram,0x0c0cc66cu,4);
goto P_0c0cc5fa;
P_0c0cc5fa: /* original 2238, guest PC 0x0c0cc5fa */
if(!s->budget--) { s->failed_pc=0x0c0cc5fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc5fc;
P_0c0cc5fc: /* original 8f1f, guest PC 0x0c0cc5fc */
if(!s->budget--) { s->failed_pc=0x0c0cc5fcu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0cc63e; }
goto P_0c0cc600;
P_0c0cc5fe: /* original 6e43, guest PC 0x0c0cc5fe */
if(!s->budget--) { s->failed_pc=0x0c0cc5feu; return 0; }
r[14]=r[4];
goto P_0c0cc600;
P_0c0cc600: /* original 902b, guest PC 0x0c0cc600 */
if(!s->budget--) { s->failed_pc=0x0c0cc600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc65au,2);
goto P_0c0cc602;
P_0c0cc602: /* original ec00, guest PC 0x0c0cc602 */
if(!s->budget--) { s->failed_pc=0x0c0cc602u; return 0; }
r[12]=0x00000000u;
goto P_0c0cc604;
P_0c0cc604: /* original d91b, guest PC 0x0c0cc604 */
if(!s->budget--) { s->failed_pc=0x0c0cc604u; return 0; }
r[9]=read(ram,0x0c0cc674u,4);
goto P_0c0cc606;
P_0c0cc606: /* original dd1c, guest PC 0x0c0cc606 */
if(!s->budget--) { s->failed_pc=0x0c0cc606u; return 0; }
r[13]=read(ram,0x0c0cc678u,4);
goto P_0c0cc608;
P_0c0cc608: /* original 0bee, guest PC 0x0c0cc608 */
if(!s->budget--) { s->failed_pc=0x0c0cc608u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0cc60a;
P_0c0cc60a: /* original a006, guest PC 0x0c0cc60a */
if(!s->budget--) { s->failed_pc=0x0c0cc60au; return 0; }
r[10]=0x00000008u;
goto P_0c0cc61a;
P_0c0cc60c: /* original ea08, guest PC 0x0c0cc60c */
if(!s->budget--) { s->failed_pc=0x0c0cc60cu; return 0; }
r[10]=0x00000008u;
goto P_0c0cc60e;
P_0c0cc60e: /* original 65d5, guest PC 0x0c0cc60e */
if(!s->budget--) { s->failed_pc=0x0c0cc60eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c0cc610;
P_0c0cc610: /* original 35ec, guest PC 0x0c0cc610 */
if(!s->budget--) { s->failed_pc=0x0c0cc610u; return 0; }
r[5]+=r[14];
goto P_0c0cc612;
P_0c0cc612: /* original 490b, guest PC 0x0c0cc612 */
if(!s->budget--) { s->failed_pc=0x0c0cc612u; return 0; }
target=r[9];
r[16]=0x0c0cc616u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc616u) { target=s->pc; goto dispatch; }
goto P_0c0cc616;
P_0c0cc614: /* original 64b3, guest PC 0x0c0cc614 */
if(!s->budget--) { s->failed_pc=0x0c0cc614u; return 0; }
r[4]=r[11];
goto P_0c0cc616;
P_0c0cc616: /* original 7c01, guest PC 0x0c0cc616 */
if(!s->budget--) { s->failed_pc=0x0c0cc616u; return 0; }
r[12]+=0x00000001u;
goto P_0c0cc618;
P_0c0cc618: /* original 7b40, guest PC 0x0c0cc618 */
if(!s->budget--) { s->failed_pc=0x0c0cc618u; return 0; }
r[11]+=0x00000040u;
goto P_0c0cc61a;
P_0c0cc61a: /* original 3ca3, guest PC 0x0c0cc61a */
if(!s->budget--) { s->failed_pc=0x0c0cc61au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[10])!=0);
goto P_0c0cc61c;
P_0c0cc61c: /* original 8bf7, guest PC 0x0c0cc61c */
if(!s->budget--) { s->failed_pc=0x0c0cc61cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc60e; }
goto P_0c0cc61e;
P_0c0cc61e: /* original 9016, guest PC 0x0c0cc61e */
if(!s->budget--) { s->failed_pc=0x0c0cc61eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc64eu,2);
goto P_0c0cc620;
P_0c0cc620: /* original 04ee, guest PC 0x0c0cc620 */
if(!s->budget--) { s->failed_pc=0x0c0cc620u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0cc622;
P_0c0cc622: /* original 7004, guest PC 0x0c0cc622 */
if(!s->budget--) { s->failed_pc=0x0c0cc622u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc624;
P_0c0cc624: /* original 07ee, guest PC 0x0c0cc624 */
if(!s->budget--) { s->failed_pc=0x0c0cc624u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0cc626;
P_0c0cc626: /* original 7004, guest PC 0x0c0cc626 */
if(!s->budget--) { s->failed_pc=0x0c0cc626u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc628;
P_0c0cc628: /* original 05ee, guest PC 0x0c0cc628 */
if(!s->budget--) { s->failed_pc=0x0c0cc628u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cc62a;
P_0c0cc62a: /* original 7004, guest PC 0x0c0cc62a */
if(!s->budget--) { s->failed_pc=0x0c0cc62au; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc62c;
P_0c0cc62c: /* original 06ee, guest PC 0x0c0cc62c */
if(!s->budget--) { s->failed_pc=0x0c0cc62cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0cc62e;
P_0c0cc62e: /* original 70f8, guest PC 0x0c0cc62e */
if(!s->budget--) { s->failed_pc=0x0c0cc62eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cc630;
P_0c0cc630: /* original 0e46, guest PC 0x0c0cc630 */
if(!s->budget--) { s->failed_pc=0x0c0cc630u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0cc632;
P_0c0cc632: /* original 7004, guest PC 0x0c0cc632 */
if(!s->budget--) { s->failed_pc=0x0c0cc632u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc634;
P_0c0cc634: /* original 0e76, guest PC 0x0c0cc634 */
if(!s->budget--) { s->failed_pc=0x0c0cc634u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0cc636;
P_0c0cc636: /* original 7004, guest PC 0x0c0cc636 */
if(!s->budget--) { s->failed_pc=0x0c0cc636u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc638;
P_0c0cc638: /* original 0e56, guest PC 0x0c0cc638 */
if(!s->budget--) { s->failed_pc=0x0c0cc638u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0cc63a;
P_0c0cc63a: /* original 70f4, guest PC 0x0c0cc63a */
if(!s->budget--) { s->failed_pc=0x0c0cc63au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0cc63c;
P_0c0cc63c: /* original 0e66, guest PC 0x0c0cc63c */
if(!s->budget--) { s->failed_pc=0x0c0cc63cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0cc63e;
P_0c0cc63e: /* original 4f26, guest PC 0x0c0cc63e */
if(!s->budget--) { s->failed_pc=0x0c0cc63eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc640;
P_0c0cc640: /* original 69f6, guest PC 0x0c0cc640 */
if(!s->budget--) { s->failed_pc=0x0c0cc640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc642;
P_0c0cc642: /* original 6af6, guest PC 0x0c0cc642 */
if(!s->budget--) { s->failed_pc=0x0c0cc642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc644;
P_0c0cc644: /* original 6bf6, guest PC 0x0c0cc644 */
if(!s->budget--) { s->failed_pc=0x0c0cc644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc646;
P_0c0cc646: /* original 6cf6, guest PC 0x0c0cc646 */
if(!s->budget--) { s->failed_pc=0x0c0cc646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc648;
P_0c0cc648: /* original 6df6, guest PC 0x0c0cc648 */
if(!s->budget--) { s->failed_pc=0x0c0cc648u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc64a;
P_0c0cc64a: /* original 000b, guest PC 0x0c0cc64a */
if(!s->budget--) { s->failed_pc=0x0c0cc64au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc64c: /* original 6ef6, guest PC 0x0c0cc64c */
if(!s->budget--) { s->failed_pc=0x0c0cc64cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc64eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
