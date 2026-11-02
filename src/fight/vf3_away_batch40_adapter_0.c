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
int vf3_away_batch40_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
case 0x0c042d7cu: goto P_0c042d7c;
case 0x0c042d7eu: goto P_0c042d7e;
case 0x0c042d80u: goto P_0c042d80;
case 0x0c042d82u: goto P_0c042d82;
case 0x0c042d84u: goto P_0c042d84;
case 0x0c042d86u: goto P_0c042d86;
case 0x0c042d88u: goto P_0c042d88;
case 0x0c042d8au: goto P_0c042d8a;
case 0x0c042d8cu: goto P_0c042d8c;
case 0x0c042d8eu: goto P_0c042d8e;
case 0x0c042d90u: goto P_0c042d90;
case 0x0c042d92u: goto P_0c042d92;
case 0x0c042d94u: goto P_0c042d94;
case 0x0c042d96u: goto P_0c042d96;
case 0x0c042d98u: goto P_0c042d98;
case 0x0c042d9au: goto P_0c042d9a;
case 0x0c042d9cu: goto P_0c042d9c;
case 0x0c042d9eu: goto P_0c042d9e;
case 0x0c042da0u: goto P_0c042da0;
case 0x0c042da2u: goto P_0c042da2;
case 0x0c042da4u: goto P_0c042da4;
case 0x0c042da6u: goto P_0c042da6;
case 0x0c042da8u: goto P_0c042da8;
case 0x0c042daau: goto P_0c042daa;
case 0x0c042dacu: goto P_0c042dac;
case 0x0c042daeu: goto P_0c042dae;
case 0x0c042db0u: goto P_0c042db0;
case 0x0c042db2u: goto P_0c042db2;
case 0x0c042db4u: goto P_0c042db4;
case 0x0c042db6u: goto P_0c042db6;
case 0x0c042db8u: goto P_0c042db8;
case 0x0c042dbau: goto P_0c042dba;
case 0x0c042dbcu: goto P_0c042dbc;
case 0x0c042dbeu: goto P_0c042dbe;
case 0x0c042dc0u: goto P_0c042dc0;
case 0x0c042dc2u: goto P_0c042dc2;
case 0x0c042dc4u: goto P_0c042dc4;
case 0x0c042dc6u: goto P_0c042dc6;
case 0x0c042dc8u: goto P_0c042dc8;
case 0x0c042dcau: goto P_0c042dca;
case 0x0c042dccu: goto P_0c042dcc;
case 0x0c042dceu: goto P_0c042dce;
case 0x0c042dd0u: goto P_0c042dd0;
case 0x0c042dd2u: goto P_0c042dd2;
case 0x0c042dd4u: goto P_0c042dd4;
case 0x0c042dd6u: goto P_0c042dd6;
case 0x0c042dd8u: goto P_0c042dd8;
case 0x0c042ddau: goto P_0c042dda;
case 0x0c042ddcu: goto P_0c042ddc;
case 0x0c042ddeu: goto P_0c042dde;
case 0x0c042de0u: goto P_0c042de0;
case 0x0c042de2u: goto P_0c042de2;
case 0x0c042de4u: goto P_0c042de4;
case 0x0c042de6u: goto P_0c042de6;
case 0x0c042de8u: goto P_0c042de8;
case 0x0c042deau: goto P_0c042dea;
case 0x0c042decu: goto P_0c042dec;
case 0x0c042deeu: goto P_0c042dee;
case 0x0c042df0u: goto P_0c042df0;
case 0x0c042df2u: goto P_0c042df2;
case 0x0c042df4u: goto P_0c042df4;
case 0x0c042df6u: goto P_0c042df6;
case 0x0c042df8u: goto P_0c042df8;
case 0x0c042dfau: goto P_0c042dfa;
case 0x0c042dfcu: goto P_0c042dfc;
case 0x0c042dfeu: goto P_0c042dfe;
case 0x0c042e00u: goto P_0c042e00;
case 0x0c042e02u: goto P_0c042e02;
case 0x0c042e04u: goto P_0c042e04;
case 0x0c042e06u: goto P_0c042e06;
case 0x0c042e08u: goto P_0c042e08;
case 0x0c042e0au: goto P_0c042e0a;
case 0x0c042e0cu: goto P_0c042e0c;
case 0x0c042e0eu: goto P_0c042e0e;
case 0x0c042e10u: goto P_0c042e10;
case 0x0c042e12u: goto P_0c042e12;
case 0x0c042e14u: goto P_0c042e14;
case 0x0c042e16u: goto P_0c042e16;
case 0x0c042e18u: goto P_0c042e18;
case 0x0c042e1au: goto P_0c042e1a;
case 0x0c042e1cu: goto P_0c042e1c;
case 0x0c042e1eu: goto P_0c042e1e;
case 0x0c042e20u: goto P_0c042e20;
case 0x0c042e22u: goto P_0c042e22;
case 0x0c042e24u: goto P_0c042e24;
case 0x0c042e26u: goto P_0c042e26;
case 0x0c042e28u: goto P_0c042e28;
case 0x0c042e2au: goto P_0c042e2a;
case 0x0c042e2cu: goto P_0c042e2c;
case 0x0c042e2eu: goto P_0c042e2e;
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c042f08u: goto P_0c042f08;
case 0x0c042f0au: goto P_0c042f0a;
case 0x0c042f0cu: goto P_0c042f0c;
case 0x0c042f0eu: goto P_0c042f0e;
case 0x0c042f10u: goto P_0c042f10;
case 0x0c042f12u: goto P_0c042f12;
case 0x0c06f450u: goto P_0c06f450;
case 0x0c06f452u: goto P_0c06f452;
case 0x0c06f454u: goto P_0c06f454;
case 0x0c06f456u: goto P_0c06f456;
case 0x0c06f458u: goto P_0c06f458;
case 0x0c06f45au: goto P_0c06f45a;
case 0x0c06f45cu: goto P_0c06f45c;
case 0x0c06f45eu: goto P_0c06f45e;
case 0x0c06f460u: goto P_0c06f460;
case 0x0c06f462u: goto P_0c06f462;
case 0x0c06f464u: goto P_0c06f464;
case 0x0c06f466u: goto P_0c06f466;
case 0x0c06f468u: goto P_0c06f468;
case 0x0c06f46au: goto P_0c06f46a;
case 0x0c06f46cu: goto P_0c06f46c;
case 0x0c06f46eu: goto P_0c06f46e;
case 0x0c06f470u: goto P_0c06f470;
case 0x0c06f472u: goto P_0c06f472;
case 0x0c06f474u: goto P_0c06f474;
case 0x0c06f476u: goto P_0c06f476;
case 0x0c06f478u: goto P_0c06f478;
case 0x0c06f47au: goto P_0c06f47a;
case 0x0c06f47cu: goto P_0c06f47c;
case 0x0c06f47eu: goto P_0c06f47e;
case 0x0c06f480u: goto P_0c06f480;
case 0x0c06f482u: goto P_0c06f482;
case 0x0c06f484u: goto P_0c06f484;
case 0x0c06f486u: goto P_0c06f486;
case 0x0c06f488u: goto P_0c06f488;
case 0x0c06f48au: goto P_0c06f48a;
case 0x0c06f48cu: goto P_0c06f48c;
case 0x0c06f48eu: goto P_0c06f48e;
case 0x0c06f490u: goto P_0c06f490;
case 0x0c06f492u: goto P_0c06f492;
case 0x0c06f494u: goto P_0c06f494;
case 0x0c06f496u: goto P_0c06f496;
case 0x0c06f498u: goto P_0c06f498;
case 0x0c06f49au: goto P_0c06f49a;
case 0x0c06f49cu: goto P_0c06f49c;
case 0x0c06f49eu: goto P_0c06f49e;
case 0x0c06f4a0u: goto P_0c06f4a0;
case 0x0c06f4a2u: goto P_0c06f4a2;
case 0x0c06f4a4u: goto P_0c06f4a4;
case 0x0c06f4a6u: goto P_0c06f4a6;
case 0x0c06f4a8u: goto P_0c06f4a8;
case 0x0c06f4aau: goto P_0c06f4aa;
case 0x0c06f4acu: goto P_0c06f4ac;
case 0x0c06f4aeu: goto P_0c06f4ae;
case 0x0c06f4b0u: goto P_0c06f4b0;
case 0x0c06f4b2u: goto P_0c06f4b2;
case 0x0c06f4b4u: goto P_0c06f4b4;
case 0x0c06f4b6u: goto P_0c06f4b6;
case 0x0c06f4f4u: goto P_0c06f4f4;
case 0x0c06f4f6u: goto P_0c06f4f6;
case 0x0c06f4f8u: goto P_0c06f4f8;
case 0x0c06f4fau: goto P_0c06f4fa;
case 0x0c06f4fcu: goto P_0c06f4fc;
case 0x0c06f4feu: goto P_0c06f4fe;
case 0x0c06f500u: goto P_0c06f500;
case 0x0c06f502u: goto P_0c06f502;
case 0x0c06f504u: goto P_0c06f504;
case 0x0c06f506u: goto P_0c06f506;
case 0x0c06f508u: goto P_0c06f508;
case 0x0c06f50au: goto P_0c06f50a;
case 0x0c06f50cu: goto P_0c06f50c;
case 0x0c06f50eu: goto P_0c06f50e;
case 0x0c06f510u: goto P_0c06f510;
case 0x0c06f512u: goto P_0c06f512;
case 0x0c06f514u: goto P_0c06f514;
case 0x0c06f516u: goto P_0c06f516;
case 0x0c06f518u: goto P_0c06f518;
case 0x0c06f51au: goto P_0c06f51a;
case 0x0c06f51cu: goto P_0c06f51c;
case 0x0c06f51eu: goto P_0c06f51e;
case 0x0c06f520u: goto P_0c06f520;
case 0x0c06f522u: goto P_0c06f522;
case 0x0c06f524u: goto P_0c06f524;
case 0x0c06f526u: goto P_0c06f526;
case 0x0c06f528u: goto P_0c06f528;
case 0x0c06f52au: goto P_0c06f52a;
case 0x0c06f52cu: goto P_0c06f52c;
case 0x0c06f52eu: goto P_0c06f52e;
case 0x0c06f530u: goto P_0c06f530;
case 0x0c06f532u: goto P_0c06f532;
case 0x0c06f534u: goto P_0c06f534;
case 0x0c06f536u: goto P_0c06f536;
case 0x0c06f538u: goto P_0c06f538;
case 0x0c06f53au: goto P_0c06f53a;
case 0x0c06f544u: goto P_0c06f544;
case 0x0c06f546u: goto P_0c06f546;
case 0x0c06f548u: goto P_0c06f548;
case 0x0c06f54au: goto P_0c06f54a;
case 0x0c06f54cu: goto P_0c06f54c;
case 0x0c06f54eu: goto P_0c06f54e;
case 0x0c06f550u: goto P_0c06f550;
case 0x0c06f552u: goto P_0c06f552;
case 0x0c06f554u: goto P_0c06f554;
case 0x0c06f556u: goto P_0c06f556;
case 0x0c06f558u: goto P_0c06f558;
case 0x0c06f55au: goto P_0c06f55a;
case 0x0c06f55cu: goto P_0c06f55c;
case 0x0c06f55eu: goto P_0c06f55e;
case 0x0c06f560u: goto P_0c06f560;
case 0x0c06f562u: goto P_0c06f562;
case 0x0c06f566u: goto P_0c06f566;
case 0x0c06f568u: goto P_0c06f568;
case 0x0c06f56au: goto P_0c06f56a;
case 0x0c06f56cu: goto P_0c06f56c;
case 0x0c06f56eu: goto P_0c06f56e;
case 0x0c06f570u: goto P_0c06f570;
case 0x0c06f572u: goto P_0c06f572;
case 0x0c06f574u: goto P_0c06f574;
case 0x0c06f576u: goto P_0c06f576;
case 0x0c06f578u: goto P_0c06f578;
case 0x0c06f57au: goto P_0c06f57a;
case 0x0c06f57cu: goto P_0c06f57c;
case 0x0c06f57eu: goto P_0c06f57e;
case 0x0c06f580u: goto P_0c06f580;
case 0x0c06f582u: goto P_0c06f582;
case 0x0c06f584u: goto P_0c06f584;
case 0x0c06f586u: goto P_0c06f586;
case 0x0c06f588u: goto P_0c06f588;
case 0x0c06f58au: goto P_0c06f58a;
case 0x0c06f58cu: goto P_0c06f58c;
case 0x0c06f58eu: goto P_0c06f58e;
case 0x0c06f590u: goto P_0c06f590;
case 0x0c06f592u: goto P_0c06f592;
case 0x0c06f594u: goto P_0c06f594;
case 0x0c06f596u: goto P_0c06f596;
case 0x0c06f598u: goto P_0c06f598;
case 0x0c06f59au: goto P_0c06f59a;
case 0x0c06f59cu: goto P_0c06f59c;
case 0x0c06f59eu: goto P_0c06f59e;
case 0x0c06f5a0u: goto P_0c06f5a0;
case 0x0c06f5a2u: goto P_0c06f5a2;
case 0x0c06f5a4u: goto P_0c06f5a4;
case 0x0c06f5a6u: goto P_0c06f5a6;
case 0x0c06f5a8u: goto P_0c06f5a8;
case 0x0c06f5aau: goto P_0c06f5aa;
case 0x0c06f5acu: goto P_0c06f5ac;
case 0x0c06f5aeu: goto P_0c06f5ae;
case 0x0c06f5b0u: goto P_0c06f5b0;
case 0x0c06f5b2u: goto P_0c06f5b2;
case 0x0c06f5b4u: goto P_0c06f5b4;
case 0x0c06f5b6u: goto P_0c06f5b6;
case 0x0c06f5b8u: goto P_0c06f5b8;
case 0x0c06f5bau: goto P_0c06f5ba;
case 0x0c06f5bcu: goto P_0c06f5bc;
case 0x0c06f5beu: goto P_0c06f5be;
case 0x0c06f5c0u: goto P_0c06f5c0;
case 0x0c06f5c2u: goto P_0c06f5c2;
case 0x0c06f5c4u: goto P_0c06f5c4;
case 0x0c06f5c6u: goto P_0c06f5c6;
case 0x0c06f5c8u: goto P_0c06f5c8;
case 0x0c06f5cau: goto P_0c06f5ca;
case 0x0c06f5ccu: goto P_0c06f5cc;
case 0x0c06f5ceu: goto P_0c06f5ce;
case 0x0c06f5d0u: goto P_0c06f5d0;
case 0x0c06f5d2u: goto P_0c06f5d2;
case 0x0c06f5d4u: goto P_0c06f5d4;
case 0x0c06f5d6u: goto P_0c06f5d6;
case 0x0c06f5d8u: goto P_0c06f5d8;
case 0x0c06f5dau: goto P_0c06f5da;
case 0x0c06f5dcu: goto P_0c06f5dc;
case 0x0c06f5deu: goto P_0c06f5de;
case 0x0c06f5e0u: goto P_0c06f5e0;
case 0x0c06f5e2u: goto P_0c06f5e2;
case 0x0c06f5e4u: goto P_0c06f5e4;
case 0x0c06f5e6u: goto P_0c06f5e6;
case 0x0c06f5e8u: goto P_0c06f5e8;
case 0x0c06f5eau: goto P_0c06f5ea;
case 0x0c06f5ecu: goto P_0c06f5ec;
case 0x0c06f5eeu: goto P_0c06f5ee;
case 0x0c06f5f0u: goto P_0c06f5f0;
case 0x0c06f5f2u: goto P_0c06f5f2;
case 0x0c06f5f4u: goto P_0c06f5f4;
case 0x0c06f5f6u: goto P_0c06f5f6;
case 0x0c06f5f8u: goto P_0c06f5f8;
case 0x0c06f5fau: goto P_0c06f5fa;
case 0x0c06f5fcu: goto P_0c06f5fc;
case 0x0c06f5feu: goto P_0c06f5fe;
case 0x0c06f600u: goto P_0c06f600;
case 0x0c06f602u: goto P_0c06f602;
case 0x0c06f604u: goto P_0c06f604;
case 0x0c06f606u: goto P_0c06f606;
case 0x0c06f608u: goto P_0c06f608;
case 0x0c06f60au: goto P_0c06f60a;
case 0x0c06f60cu: goto P_0c06f60c;
case 0x0c06f60eu: goto P_0c06f60e;
case 0x0c06f610u: goto P_0c06f610;
case 0x0c06f612u: goto P_0c06f612;
case 0x0c06f614u: goto P_0c06f614;
case 0x0c06f616u: goto P_0c06f616;
case 0x0c06f618u: goto P_0c06f618;
case 0x0c06f61au: goto P_0c06f61a;
case 0x0c06f61cu: goto P_0c06f61c;
case 0x0c06f61eu: goto P_0c06f61e;
case 0x0c06f620u: goto P_0c06f620;
case 0x0c06f622u: goto P_0c06f622;
case 0x0c06f624u: goto P_0c06f624;
case 0x0c06f626u: goto P_0c06f626;
case 0x0c06f628u: goto P_0c06f628;
case 0x0c06f62au: goto P_0c06f62a;
case 0x0c06f62cu: goto P_0c06f62c;
case 0x0c06f62eu: goto P_0c06f62e;
case 0x0c06f630u: goto P_0c06f630;
case 0x0c06f632u: goto P_0c06f632;
case 0x0c06f634u: goto P_0c06f634;
case 0x0c06f636u: goto P_0c06f636;
case 0x0c06f638u: goto P_0c06f638;
case 0x0c06f63au: goto P_0c06f63a;
case 0x0c06f63cu: goto P_0c06f63c;
case 0x0c06f63eu: goto P_0c06f63e;
case 0x0c06f640u: goto P_0c06f640;
case 0x0c06f642u: goto P_0c06f642;
case 0x0c06f644u: goto P_0c06f644;
case 0x0c06f646u: goto P_0c06f646;
case 0x0c06f648u: goto P_0c06f648;
case 0x0c06f64au: goto P_0c06f64a;
case 0x0c06f64cu: goto P_0c06f64c;
case 0x0c06f64eu: goto P_0c06f64e;
case 0x0c06f650u: goto P_0c06f650;
case 0x0c06f652u: goto P_0c06f652;
case 0x0c06f654u: goto P_0c06f654;
case 0x0c06f656u: goto P_0c06f656;
case 0x0c06f658u: goto P_0c06f658;
case 0x0c06f65au: goto P_0c06f65a;
case 0x0c06f65cu: goto P_0c06f65c;
case 0x0c06f65eu: goto P_0c06f65e;
case 0x0c06f68cu: goto P_0c06f68c;
case 0x0c06f68eu: goto P_0c06f68e;
case 0x0c06f690u: goto P_0c06f690;
case 0x0c06f692u: goto P_0c06f692;
case 0x0c06f694u: goto P_0c06f694;
case 0x0c06f696u: goto P_0c06f696;
case 0x0c06f698u: goto P_0c06f698;
case 0x0c06f69au: goto P_0c06f69a;
case 0x0c06f69cu: goto P_0c06f69c;
case 0x0c06f69eu: goto P_0c06f69e;
case 0x0c06f6a0u: goto P_0c06f6a0;
case 0x0c06f6a2u: goto P_0c06f6a2;
case 0x0c06f6a4u: goto P_0c06f6a4;
case 0x0c06f6a6u: goto P_0c06f6a6;
case 0x0c06f6a8u: goto P_0c06f6a8;
case 0x0c06f6aau: goto P_0c06f6aa;
case 0x0c06f6acu: goto P_0c06f6ac;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
P_0c042d7c: /* original 2008, guest PC 0x0c042d7c */
if(!s->budget--) { s->failed_pc=0x0c042d7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042d7e;
P_0c042d7e: /* original 2f26, guest PC 0x0c042d7e */
if(!s->budget--) { s->failed_pc=0x0c042d7eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d80;
P_0c042d80: /* original 8d56, guest PC 0x0c042d80 */
if(!s->budget--) { s->failed_pc=0x0c042d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042e30; }
goto P_0c042d84;
P_0c042d82: /* original 0009, guest PC 0x0c042d82 */
if(!s->budget--) { s->failed_pc=0x0c042d82u; return 0; }
goto P_0c042d84;
P_0c042d84: /* original 2f36, guest PC 0x0c042d84 */
if(!s->budget--) { s->failed_pc=0x0c042d84u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d86;
P_0c042d86: /* original e200, guest PC 0x0c042d86 */
if(!s->budget--) { s->failed_pc=0x0c042d86u; return 0; }
r[2]=0x00000000u;
goto P_0c042d88;
P_0c042d88: /* original 2f46, guest PC 0x0c042d88 */
if(!s->budget--) { s->failed_pc=0x0c042d88u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042d8a;
P_0c042d8a: /* original 2127, guest PC 0x0c042d8a */
if(!s->budget--) { s->failed_pc=0x0c042d8au; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042d8c;
P_0c042d8c: /* original 0429, guest PC 0x0c042d8c */
if(!s->budget--) { s->failed_pc=0x0c042d8cu; return 0; }
r[4]=r[17]&1u;
goto P_0c042d8e;
P_0c042d8e: /* original 333a, guest PC 0x0c042d8e */
if(!s->budget--) { s->failed_pc=0x0c042d8eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d90;
P_0c042d90: /* original 312a, guest PC 0x0c042d90 */
if(!s->budget--) { s->failed_pc=0x0c042d90u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042d92;
P_0c042d92: /* original 2307, guest PC 0x0c042d92 */
if(!s->budget--) { s->failed_pc=0x0c042d92u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042d94;
P_0c042d94: /* original 4124, guest PC 0x0c042d94 */
if(!s->budget--) { s->failed_pc=0x0c042d94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d96;
P_0c042d96: /* original 3304, guest PC 0x0c042d96 */
if(!s->budget--) { s->failed_pc=0x0c042d96u; return 0; }
divide_step(s,3,0);
goto P_0c042d98;
P_0c042d98: /* original 4124, guest PC 0x0c042d98 */
if(!s->budget--) { s->failed_pc=0x0c042d98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9a;
P_0c042d9a: /* original 3304, guest PC 0x0c042d9a */
if(!s->budget--) { s->failed_pc=0x0c042d9au; return 0; }
divide_step(s,3,0);
goto P_0c042d9c;
P_0c042d9c: /* original 4124, guest PC 0x0c042d9c */
if(!s->budget--) { s->failed_pc=0x0c042d9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d9e;
P_0c042d9e: /* original 3304, guest PC 0x0c042d9e */
if(!s->budget--) { s->failed_pc=0x0c042d9eu; return 0; }
divide_step(s,3,0);
goto P_0c042da0;
P_0c042da0: /* original 4124, guest PC 0x0c042da0 */
if(!s->budget--) { s->failed_pc=0x0c042da0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da2;
P_0c042da2: /* original 3304, guest PC 0x0c042da2 */
if(!s->budget--) { s->failed_pc=0x0c042da2u; return 0; }
divide_step(s,3,0);
goto P_0c042da4;
P_0c042da4: /* original 4124, guest PC 0x0c042da4 */
if(!s->budget--) { s->failed_pc=0x0c042da4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042da6;
P_0c042da6: /* original 3304, guest PC 0x0c042da6 */
if(!s->budget--) { s->failed_pc=0x0c042da6u; return 0; }
divide_step(s,3,0);
goto P_0c042da8;
P_0c042da8: /* original 4124, guest PC 0x0c042da8 */
if(!s->budget--) { s->failed_pc=0x0c042da8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042daa;
P_0c042daa: /* original 3304, guest PC 0x0c042daa */
if(!s->budget--) { s->failed_pc=0x0c042daau; return 0; }
divide_step(s,3,0);
goto P_0c042dac;
P_0c042dac: /* original 4124, guest PC 0x0c042dac */
if(!s->budget--) { s->failed_pc=0x0c042dacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dae;
P_0c042dae: /* original 3304, guest PC 0x0c042dae */
if(!s->budget--) { s->failed_pc=0x0c042daeu; return 0; }
divide_step(s,3,0);
goto P_0c042db0;
P_0c042db0: /* original 4124, guest PC 0x0c042db0 */
if(!s->budget--) { s->failed_pc=0x0c042db0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db2;
P_0c042db2: /* original 3304, guest PC 0x0c042db2 */
if(!s->budget--) { s->failed_pc=0x0c042db2u; return 0; }
divide_step(s,3,0);
goto P_0c042db4;
P_0c042db4: /* original 4124, guest PC 0x0c042db4 */
if(!s->budget--) { s->failed_pc=0x0c042db4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042db6;
P_0c042db6: /* original 3304, guest PC 0x0c042db6 */
if(!s->budget--) { s->failed_pc=0x0c042db6u; return 0; }
divide_step(s,3,0);
goto P_0c042db8;
P_0c042db8: /* original 4124, guest PC 0x0c042db8 */
if(!s->budget--) { s->failed_pc=0x0c042db8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dba;
P_0c042dba: /* original 3304, guest PC 0x0c042dba */
if(!s->budget--) { s->failed_pc=0x0c042dbau; return 0; }
divide_step(s,3,0);
goto P_0c042dbc;
P_0c042dbc: /* original 4124, guest PC 0x0c042dbc */
if(!s->budget--) { s->failed_pc=0x0c042dbcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dbe;
P_0c042dbe: /* original 3304, guest PC 0x0c042dbe */
if(!s->budget--) { s->failed_pc=0x0c042dbeu; return 0; }
divide_step(s,3,0);
goto P_0c042dc0;
P_0c042dc0: /* original 4124, guest PC 0x0c042dc0 */
if(!s->budget--) { s->failed_pc=0x0c042dc0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc2;
P_0c042dc2: /* original 3304, guest PC 0x0c042dc2 */
if(!s->budget--) { s->failed_pc=0x0c042dc2u; return 0; }
divide_step(s,3,0);
goto P_0c042dc4;
P_0c042dc4: /* original 4124, guest PC 0x0c042dc4 */
if(!s->budget--) { s->failed_pc=0x0c042dc4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dc6;
P_0c042dc6: /* original 3304, guest PC 0x0c042dc6 */
if(!s->budget--) { s->failed_pc=0x0c042dc6u; return 0; }
divide_step(s,3,0);
goto P_0c042dc8;
P_0c042dc8: /* original 4124, guest PC 0x0c042dc8 */
if(!s->budget--) { s->failed_pc=0x0c042dc8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dca;
P_0c042dca: /* original 3304, guest PC 0x0c042dca */
if(!s->budget--) { s->failed_pc=0x0c042dcau; return 0; }
divide_step(s,3,0);
goto P_0c042dcc;
P_0c042dcc: /* original 4124, guest PC 0x0c042dcc */
if(!s->budget--) { s->failed_pc=0x0c042dccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dce;
P_0c042dce: /* original 3304, guest PC 0x0c042dce */
if(!s->budget--) { s->failed_pc=0x0c042dceu; return 0; }
divide_step(s,3,0);
goto P_0c042dd0;
P_0c042dd0: /* original 4124, guest PC 0x0c042dd0 */
if(!s->budget--) { s->failed_pc=0x0c042dd0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd2;
P_0c042dd2: /* original 3304, guest PC 0x0c042dd2 */
if(!s->budget--) { s->failed_pc=0x0c042dd2u; return 0; }
divide_step(s,3,0);
goto P_0c042dd4;
P_0c042dd4: /* original 4124, guest PC 0x0c042dd4 */
if(!s->budget--) { s->failed_pc=0x0c042dd4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dd6;
P_0c042dd6: /* original 3304, guest PC 0x0c042dd6 */
if(!s->budget--) { s->failed_pc=0x0c042dd6u; return 0; }
divide_step(s,3,0);
goto P_0c042dd8;
P_0c042dd8: /* original 4124, guest PC 0x0c042dd8 */
if(!s->budget--) { s->failed_pc=0x0c042dd8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dda;
P_0c042dda: /* original 3304, guest PC 0x0c042dda */
if(!s->budget--) { s->failed_pc=0x0c042ddau; return 0; }
divide_step(s,3,0);
goto P_0c042ddc;
P_0c042ddc: /* original 4124, guest PC 0x0c042ddc */
if(!s->budget--) { s->failed_pc=0x0c042ddcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dde;
P_0c042dde: /* original 3304, guest PC 0x0c042dde */
if(!s->budget--) { s->failed_pc=0x0c042ddeu; return 0; }
divide_step(s,3,0);
goto P_0c042de0;
P_0c042de0: /* original 4124, guest PC 0x0c042de0 */
if(!s->budget--) { s->failed_pc=0x0c042de0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de2;
P_0c042de2: /* original 3304, guest PC 0x0c042de2 */
if(!s->budget--) { s->failed_pc=0x0c042de2u; return 0; }
divide_step(s,3,0);
goto P_0c042de4;
P_0c042de4: /* original 4124, guest PC 0x0c042de4 */
if(!s->budget--) { s->failed_pc=0x0c042de4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042de6;
P_0c042de6: /* original 3304, guest PC 0x0c042de6 */
if(!s->budget--) { s->failed_pc=0x0c042de6u; return 0; }
divide_step(s,3,0);
goto P_0c042de8;
P_0c042de8: /* original 4124, guest PC 0x0c042de8 */
if(!s->budget--) { s->failed_pc=0x0c042de8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dea;
P_0c042dea: /* original 3304, guest PC 0x0c042dea */
if(!s->budget--) { s->failed_pc=0x0c042deau; return 0; }
divide_step(s,3,0);
goto P_0c042dec;
P_0c042dec: /* original 4124, guest PC 0x0c042dec */
if(!s->budget--) { s->failed_pc=0x0c042decu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dee;
P_0c042dee: /* original 3304, guest PC 0x0c042dee */
if(!s->budget--) { s->failed_pc=0x0c042deeu; return 0; }
divide_step(s,3,0);
goto P_0c042df0;
P_0c042df0: /* original 4124, guest PC 0x0c042df0 */
if(!s->budget--) { s->failed_pc=0x0c042df0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df2;
P_0c042df2: /* original 3304, guest PC 0x0c042df2 */
if(!s->budget--) { s->failed_pc=0x0c042df2u; return 0; }
divide_step(s,3,0);
goto P_0c042df4;
P_0c042df4: /* original 4124, guest PC 0x0c042df4 */
if(!s->budget--) { s->failed_pc=0x0c042df4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042df6;
P_0c042df6: /* original 3304, guest PC 0x0c042df6 */
if(!s->budget--) { s->failed_pc=0x0c042df6u; return 0; }
divide_step(s,3,0);
goto P_0c042df8;
P_0c042df8: /* original 4124, guest PC 0x0c042df8 */
if(!s->budget--) { s->failed_pc=0x0c042df8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfa;
P_0c042dfa: /* original 3304, guest PC 0x0c042dfa */
if(!s->budget--) { s->failed_pc=0x0c042dfau; return 0; }
divide_step(s,3,0);
goto P_0c042dfc;
P_0c042dfc: /* original 4124, guest PC 0x0c042dfc */
if(!s->budget--) { s->failed_pc=0x0c042dfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042dfe;
P_0c042dfe: /* original 3304, guest PC 0x0c042dfe */
if(!s->budget--) { s->failed_pc=0x0c042dfeu; return 0; }
divide_step(s,3,0);
goto P_0c042e00;
P_0c042e00: /* original 4124, guest PC 0x0c042e00 */
if(!s->budget--) { s->failed_pc=0x0c042e00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e02;
P_0c042e02: /* original 3304, guest PC 0x0c042e02 */
if(!s->budget--) { s->failed_pc=0x0c042e02u; return 0; }
divide_step(s,3,0);
goto P_0c042e04;
P_0c042e04: /* original 4124, guest PC 0x0c042e04 */
if(!s->budget--) { s->failed_pc=0x0c042e04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e06;
P_0c042e06: /* original 3304, guest PC 0x0c042e06 */
if(!s->budget--) { s->failed_pc=0x0c042e06u; return 0; }
divide_step(s,3,0);
goto P_0c042e08;
P_0c042e08: /* original 4124, guest PC 0x0c042e08 */
if(!s->budget--) { s->failed_pc=0x0c042e08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0a;
P_0c042e0a: /* original 3304, guest PC 0x0c042e0a */
if(!s->budget--) { s->failed_pc=0x0c042e0au; return 0; }
divide_step(s,3,0);
goto P_0c042e0c;
P_0c042e0c: /* original 4124, guest PC 0x0c042e0c */
if(!s->budget--) { s->failed_pc=0x0c042e0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e0e;
P_0c042e0e: /* original 3304, guest PC 0x0c042e0e */
if(!s->budget--) { s->failed_pc=0x0c042e0eu; return 0; }
divide_step(s,3,0);
goto P_0c042e10;
P_0c042e10: /* original 4124, guest PC 0x0c042e10 */
if(!s->budget--) { s->failed_pc=0x0c042e10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e12;
P_0c042e12: /* original 3304, guest PC 0x0c042e12 */
if(!s->budget--) { s->failed_pc=0x0c042e12u; return 0; }
divide_step(s,3,0);
goto P_0c042e14;
P_0c042e14: /* original 2327, guest PC 0x0c042e14 */
if(!s->budget--) { s->failed_pc=0x0c042e14u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[2]>>31)<<9)|(((r[3]^r[2])>>31)&1u);
goto P_0c042e16;
P_0c042e16: /* original 0229, guest PC 0x0c042e16 */
if(!s->budget--) { s->failed_pc=0x0c042e16u; return 0; }
r[2]=r[17]&1u;
goto P_0c042e18;
P_0c042e18: /* original 224a, guest PC 0x0c042e18 */
if(!s->budget--) { s->failed_pc=0x0c042e18u; return 0; }
r[2]^=r[4];
goto P_0c042e1a;
P_0c042e1a: /* original 4225, guest PC 0x0c042e1a */
if(!s->budget--) { s->failed_pc=0x0c042e1au; return 0; }
tmp=r[2]&1u; r[2]=(r[2]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e1c;
P_0c042e1c: /* original 8b02, guest PC 0x0c042e1c */
if(!s->budget--) { s->failed_pc=0x0c042e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042e24; }
goto P_0c042e1e;
P_0c042e1e: /* original 2307, guest PC 0x0c042e1e */
if(!s->budget--) { s->failed_pc=0x0c042e1eu; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042e20;
P_0c042e20: /* original 4321, guest PC 0x0c042e20 */
if(!s->budget--) { s->failed_pc=0x0c042e20u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c042e22;
P_0c042e22: /* original 3304, guest PC 0x0c042e22 */
if(!s->budget--) { s->failed_pc=0x0c042e22u; return 0; }
divide_step(s,3,0);
goto P_0c042e24;
P_0c042e24: /* original 334c, guest PC 0x0c042e24 */
if(!s->budget--) { s->failed_pc=0x0c042e24u; return 0; }
r[3]+=r[4];
goto P_0c042e26;
P_0c042e26: /* original 6033, guest PC 0x0c042e26 */
if(!s->budget--) { s->failed_pc=0x0c042e26u; return 0; }
r[0]=r[3];
goto P_0c042e28;
P_0c042e28: /* original 64f6, guest PC 0x0c042e28 */
if(!s->budget--) { s->failed_pc=0x0c042e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042e2a;
P_0c042e2a: /* original 63f6, guest PC 0x0c042e2a */
if(!s->budget--) { s->failed_pc=0x0c042e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042e2c;
P_0c042e2c: /* original 000b, guest PC 0x0c042e2c */
if(!s->budget--) { s->failed_pc=0x0c042e2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e2e: /* original 62f6, guest PC 0x0c042e2e */
if(!s->budget--) { s->failed_pc=0x0c042e2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042e30;
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
P_0c042f08: /* original 2f36, guest PC 0x0c042f08 */
if(!s->budget--) { s->failed_pc=0x0c042f08u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042f0a;
P_0c042f0a: /* original d302, guest PC 0x0c042f0a */
if(!s->budget--) { s->failed_pc=0x0c042f0au; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f0c;
P_0c042f0c: /* original 033e, guest PC 0x0c042f0c */
if(!s->budget--) { s->failed_pc=0x0c042f0cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f0e;
P_0c042f0e: /* original 70fc, guest PC 0x0c042f0e */
if(!s->budget--) { s->failed_pc=0x0c042f0eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f10;
P_0c042f10: /* original 432b, guest PC 0x0c042f10 */
if(!s->budget--) { s->failed_pc=0x0c042f10u; return 0; }
target=r[3];
r[3]=read(ram,r[2]+r[0],4);
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
P_0c042f12: /* original 032e, guest PC 0x0c042f12 */
if(!s->budget--) { s->failed_pc=0x0c042f12u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f14u; return 0; } return 1;
P_0c06f450: /* original 2fe6, guest PC 0x0c06f450 */
if(!s->budget--) { s->failed_pc=0x0c06f450u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f452;
P_0c06f452: /* original 6e53, guest PC 0x0c06f452 */
if(!s->budget--) { s->failed_pc=0x0c06f452u; return 0; }
r[14]=r[5];
goto P_0c06f454;
P_0c06f454: /* original 2fd6, guest PC 0x0c06f454 */
if(!s->budget--) { s->failed_pc=0x0c06f454u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f456;
P_0c06f456: /* original 2fc6, guest PC 0x0c06f456 */
if(!s->budget--) { s->failed_pc=0x0c06f456u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f458;
P_0c06f458: /* original 2fb6, guest PC 0x0c06f458 */
if(!s->budget--) { s->failed_pc=0x0c06f458u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f45a;
P_0c06f45a: /* original 6b43, guest PC 0x0c06f45a */
if(!s->budget--) { s->failed_pc=0x0c06f45au; return 0; }
r[11]=r[4];
goto P_0c06f45c;
P_0c06f45c: /* original 2fa6, guest PC 0x0c06f45c */
if(!s->budget--) { s->failed_pc=0x0c06f45cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f45e;
P_0c06f45e: /* original 2f96, guest PC 0x0c06f45e */
if(!s->budget--) { s->failed_pc=0x0c06f45eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f460;
P_0c06f460: /* original 2f86, guest PC 0x0c06f460 */
if(!s->budget--) { s->failed_pc=0x0c06f460u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06f462;
P_0c06f462: /* original fffb, guest PC 0x0c06f462 */
if(!s->budget--) { s->failed_pc=0x0c06f462u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06f464;
P_0c06f464: /* original ffeb, guest PC 0x0c06f464 */
if(!s->budget--) { s->failed_pc=0x0c06f464u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06f466;
P_0c06f466: /* original ffdb, guest PC 0x0c06f466 */
if(!s->budget--) { s->failed_pc=0x0c06f466u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06f468;
P_0c06f468: /* original ffcb, guest PC 0x0c06f468 */
if(!s->budget--) { s->failed_pc=0x0c06f468u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06f46a;
P_0c06f46a: /* original 4f22, guest PC 0x0c06f46a */
if(!s->budget--) { s->failed_pc=0x0c06f46au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06f46c;
P_0c06f46c: /* original dd1a, guest PC 0x0c06f46c */
if(!s->budget--) { s->failed_pc=0x0c06f46cu; return 0; }
r[13]=read(ram,0x0c06f4d8u,4);
goto P_0c06f46e;
P_0c06f46e: /* original d31c, guest PC 0x0c06f46e */
if(!s->budget--) { s->failed_pc=0x0c06f46eu; return 0; }
r[3]=read(ram,0x0c06f4e0u,4);
goto P_0c06f470;
P_0c06f470: /* original 4f12, guest PC 0x0c06f470 */
if(!s->budget--) { s->failed_pc=0x0c06f470u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06f472;
P_0c06f472: /* original d21a, guest PC 0x0c06f472 */
if(!s->budget--) { s->failed_pc=0x0c06f472u; return 0; }
r[2]=read(ram,0x0c06f4dcu,4);
goto P_0c06f474;
P_0c06f474: /* original 7f8c, guest PC 0x0c06f474 */
if(!s->budget--) { s->failed_pc=0x0c06f474u; return 0; }
r[15]+=0xffffff8cu;
goto P_0c06f476;
P_0c06f476: /* original 61f3, guest PC 0x0c06f476 */
if(!s->budget--) { s->failed_pc=0x0c06f476u; return 0; }
r[1]=r[15];
goto P_0c06f478;
P_0c06f478: /* original 7114, guest PC 0x0c06f478 */
if(!s->budget--) { s->failed_pc=0x0c06f478u; return 0; }
r[1]+=0x00000014u;
goto P_0c06f47a;
P_0c06f47a: /* original 430b, guest PC 0x0c06f47a */
if(!s->budget--) { s->failed_pc=0x0c06f47au; return 0; }
target=r[3];
r[16]=code_base|0x0c06f47eu;
r[0]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f47eu) { target=s->pc; goto dispatch; }
goto P_0c06f47e;
P_0c06f47c: /* original e00c, guest PC 0x0c06f47c */
if(!s->budget--) { s->failed_pc=0x0c06f47cu; return 0; }
r[0]=0x0000000cu;
goto P_0c06f47e;
P_0c06f47e: /* original d119, guest PC 0x0c06f47e */
if(!s->budget--) { s->failed_pc=0x0c06f47eu; return 0; }
r[1]=read(ram,0x0c06f4e4u,4);
goto P_0c06f480;
P_0c06f480: /* original e902, guest PC 0x0c06f480 */
if(!s->budget--) { s->failed_pc=0x0c06f480u; return 0; }
r[9]=0x00000002u;
goto P_0c06f482;
P_0c06f482: /* original 410b, guest PC 0x0c06f482 */
if(!s->budget--) { s->failed_pc=0x0c06f482u; return 0; }
target=r[1];
r[16]=code_base|0x0c06f486u;
r[4]=read(ram,r[14]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f486u) { target=s->pc; goto dispatch; }
goto P_0c06f486;
P_0c06f484: /* original 54e3, guest PC 0x0c06f484 */
if(!s->budget--) { s->failed_pc=0x0c06f484u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c06f486;
P_0c06f486: /* original d318, guest PC 0x0c06f486 */
if(!s->budget--) { s->failed_pc=0x0c06f486u; return 0; }
r[3]=read(ram,0x0c06f4e8u,4);
goto P_0c06f488;
P_0c06f488: /* original 430b, guest PC 0x0c06f488 */
if(!s->budget--) { s->failed_pc=0x0c06f488u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f48cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f48cu) { target=s->pc; goto dispatch; }
goto P_0c06f48c;
P_0c06f48a: /* original 0009, guest PC 0x0c06f48a */
if(!s->budget--) { s->failed_pc=0x0c06f48au; return 0; }
goto P_0c06f48c;
P_0c06f48c: /* original d217, guest PC 0x0c06f48c */
if(!s->budget--) { s->failed_pc=0x0c06f48cu; return 0; }
r[2]=read(ram,0x0c06f4ecu,4);
goto P_0c06f48e;
P_0c06f48e: /* original 420b, guest PC 0x0c06f48e */
if(!s->budget--) { s->failed_pc=0x0c06f48eu; return 0; }
target=r[2];
r[16]=code_base|0x0c06f492u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f492u) { target=s->pc; goto dispatch; }
goto P_0c06f492;
P_0c06f490: /* original e400, guest PC 0x0c06f490 */
if(!s->budget--) { s->failed_pc=0x0c06f490u; return 0; }
r[4]=0x00000000u;
goto P_0c06f492;
P_0c06f492: /* original d817, guest PC 0x0c06f492 */
if(!s->budget--) { s->failed_pc=0x0c06f492u; return 0; }
r[8]=read(ram,0x0c06f4f0u,4);
goto P_0c06f494;
P_0c06f494: /* original e06c, guest PC 0x0c06f494 */
if(!s->budget--) { s->failed_pc=0x0c06f494u; return 0; }
r[0]=0x0000006cu;
goto P_0c06f496;
P_0c06f496: /* original 480b, guest PC 0x0c06f496 */
if(!s->budget--) { s->failed_pc=0x0c06f496u; return 0; }
target=r[8];
r[16]=code_base|0x0c06f49au;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f49au) { target=s->pc; goto dispatch; }
goto P_0c06f49a;
P_0c06f498: /* original 04ee, guest PC 0x0c06f498 */
if(!s->budget--) { s->failed_pc=0x0c06f498u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06f49a;
P_0c06f49a: /* original 9010, guest PC 0x0c06f49a */
if(!s->budget--) { s->failed_pc=0x0c06f49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4beu,2);
goto P_0c06f49c;
P_0c06f49c: /* original 64f3, guest PC 0x0c06f49c */
if(!s->budget--) { s->failed_pc=0x0c06f49cu; return 0; }
r[4]=r[15];
goto P_0c06f49e;
P_0c06f49e: /* original 7408, guest PC 0x0c06f49e */
if(!s->budget--) { s->failed_pc=0x0c06f49eu; return 0; }
r[4]+=0x00000008u;
goto P_0c06f4a0;
P_0c06f4a0: /* original f3e6, guest PC 0x0c06f4a0 */
if(!s->budget--) { s->failed_pc=0x0c06f4a0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c06f4a2;
P_0c06f4a2: /* original e008, guest PC 0x0c06f4a2 */
if(!s->budget--) { s->failed_pc=0x0c06f4a2u; return 0; }
r[0]=0x00000008u;
goto P_0c06f4a4;
P_0c06f4a4: /* original ff37, guest PC 0x0c06f4a4 */
if(!s->budget--) { s->failed_pc=0x0c06f4a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f4a6;
P_0c06f4a6: /* original e00c, guest PC 0x0c06f4a6 */
if(!s->budget--) { s->failed_pc=0x0c06f4a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c06f4a8;
P_0c06f4a8: /* original ff8d, guest PC 0x0c06f4a8 */
if(!s->budget--) { s->failed_pc=0x0c06f4a8u; return 0; }
fr[15]=0;
goto P_0c06f4aa;
P_0c06f4aa: /* original fff7, guest PC 0x0c06f4aa */
if(!s->budget--) { s->failed_pc=0x0c06f4aau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f4ac;
P_0c06f4ac: /* original e010, guest PC 0x0c06f4ac */
if(!s->budget--) { s->failed_pc=0x0c06f4acu; return 0; }
r[0]=0x00000010u;
goto P_0c06f4ae;
P_0c06f4ae: /* original fff7, guest PC 0x0c06f4ae */
if(!s->budget--) { s->failed_pc=0x0c06f4aeu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f4b0;
P_0c06f4b0: /* original 9506, guest PC 0x0c06f4b0 */
if(!s->budget--) { s->failed_pc=0x0c06f4b0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f4c0u,2);
goto P_0c06f4b2;
P_0c06f4b2: /* original 35ec, guest PC 0x0c06f4b2 */
if(!s->budget--) { s->failed_pc=0x0c06f4b2u; return 0; }
r[5]+=r[14];
goto P_0c06f4b4;
P_0c06f4b4: /* original a01e, guest PC 0x0c06f4b4 */
if(!s->budget--) { s->failed_pc=0x0c06f4b4u; return 0; }
goto P_0c06f4f4;
P_0c06f4b6: /* original 0009, guest PC 0x0c06f4b6 */
if(!s->budget--) { s->failed_pc=0x0c06f4b6u; return 0; }
if(!vf3_matrix_family(0x0c06f4b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f4b8u; return 0; } return 1;
P_0c06f4f4: /* original f449, guest PC 0x0c06f4f4 */
if(!s->budget--) { s->failed_pc=0x0c06f4f4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f4f6;
P_0c06f4f6: /* original f549, guest PC 0x0c06f4f6 */
if(!s->budget--) { s->failed_pc=0x0c06f4f6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f4f8;
P_0c06f4f8: /* original f648, guest PC 0x0c06f4f8 */
if(!s->budget--) { s->failed_pc=0x0c06f4f8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06f4fa;
P_0c06f4fa: /* original f79d, guest PC 0x0c06f4fa */
if(!s->budget--) { s->failed_pc=0x0c06f4fau; return 0; }
fr[7]=0x3f800000u;
goto P_0c06f4fc;
P_0c06f4fc: /* original f5fd, guest PC 0x0c06f4fc */
if(!s->budget--) { s->failed_pc=0x0c06f4fcu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f4fe;
P_0c06f4fe: /* original 750c, guest PC 0x0c06f4fe */
if(!s->budget--) { s->failed_pc=0x0c06f4feu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f500;
P_0c06f500: /* original f56b, guest PC 0x0c06f500 */
if(!s->budget--) { s->failed_pc=0x0c06f500u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f502;
P_0c06f502: /* original f55b, guest PC 0x0c06f502 */
if(!s->budget--) { s->failed_pc=0x0c06f502u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f504;
P_0c06f504: /* original f54b, guest PC 0x0c06f504 */
if(!s->budget--) { s->failed_pc=0x0c06f504u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f506;
P_0c06f506: /* original 0009, guest PC 0x0c06f506 */
if(!s->budget--) { s->failed_pc=0x0c06f506u; return 0; }
goto P_0c06f508;
P_0c06f508: /* original 64f3, guest PC 0x0c06f508 */
if(!s->budget--) { s->failed_pc=0x0c06f508u; return 0; }
r[4]=r[15];
goto P_0c06f50a;
P_0c06f50a: /* original 65e3, guest PC 0x0c06f50a */
if(!s->budget--) { s->failed_pc=0x0c06f50au; return 0; }
r[5]=r[14];
goto P_0c06f50c;
P_0c06f50c: /* original 7414, guest PC 0x0c06f50c */
if(!s->budget--) { s->failed_pc=0x0c06f50cu; return 0; }
r[4]+=0x00000014u;
goto P_0c06f50e;
P_0c06f50e: /* original 7574, guest PC 0x0c06f50e */
if(!s->budget--) { s->failed_pc=0x0c06f50eu; return 0; }
r[5]+=0x00000074u;
goto P_0c06f510;
P_0c06f510: /* original f449, guest PC 0x0c06f510 */
if(!s->budget--) { s->failed_pc=0x0c06f510u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f512;
P_0c06f512: /* original f549, guest PC 0x0c06f512 */
if(!s->budget--) { s->failed_pc=0x0c06f512u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f514;
P_0c06f514: /* original f649, guest PC 0x0c06f514 */
if(!s->budget--) { s->failed_pc=0x0c06f514u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f516;
P_0c06f516: /* original f78d, guest PC 0x0c06f516 */
if(!s->budget--) { s->failed_pc=0x0c06f516u; return 0; }
fr[7]=0;
goto P_0c06f518;
P_0c06f518: /* original f5fd, guest PC 0x0c06f518 */
if(!s->budget--) { s->failed_pc=0x0c06f518u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f51a;
P_0c06f51a: /* original 750c, guest PC 0x0c06f51a */
if(!s->budget--) { s->failed_pc=0x0c06f51au; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f51c;
P_0c06f51c: /* original f56b, guest PC 0x0c06f51c */
if(!s->budget--) { s->failed_pc=0x0c06f51cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f51e;
P_0c06f51e: /* original f55b, guest PC 0x0c06f51e */
if(!s->budget--) { s->failed_pc=0x0c06f51eu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f520;
P_0c06f520: /* original f54b, guest PC 0x0c06f520 */
if(!s->budget--) { s->failed_pc=0x0c06f520u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f522;
P_0c06f522: /* original 0009, guest PC 0x0c06f522 */
if(!s->budget--) { s->failed_pc=0x0c06f522u; return 0; }
goto P_0c06f524;
P_0c06f524: /* original d306, guest PC 0x0c06f524 */
if(!s->budget--) { s->failed_pc=0x0c06f524u; return 0; }
r[3]=read(ram,0x0c06f540u,4);
goto P_0c06f526;
P_0c06f526: /* original 430b, guest PC 0x0c06f526 */
if(!s->budget--) { s->failed_pc=0x0c06f526u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f52au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f52au) { target=s->pc; goto dispatch; }
goto P_0c06f52a;
P_0c06f528: /* original e401, guest PC 0x0c06f528 */
if(!s->budget--) { s->failed_pc=0x0c06f528u; return 0; }
r[4]=0x00000001u;
goto P_0c06f52a;
P_0c06f52a: /* original e070, guest PC 0x0c06f52a */
if(!s->budget--) { s->failed_pc=0x0c06f52au; return 0; }
r[0]=0x00000070u;
goto P_0c06f52c;
P_0c06f52c: /* original 480b, guest PC 0x0c06f52c */
if(!s->budget--) { s->failed_pc=0x0c06f52cu; return 0; }
target=r[8];
r[16]=code_base|0x0c06f530u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f530u) { target=s->pc; goto dispatch; }
goto P_0c06f530;
P_0c06f52e: /* original 04ee, guest PC 0x0c06f52e */
if(!s->budget--) { s->failed_pc=0x0c06f52eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06f530;
P_0c06f530: /* original 9504, guest PC 0x0c06f530 */
if(!s->budget--) { s->failed_pc=0x0c06f530u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f53cu,2);
goto P_0c06f532;
P_0c06f532: /* original 64f3, guest PC 0x0c06f532 */
if(!s->budget--) { s->failed_pc=0x0c06f532u; return 0; }
r[4]=r[15];
goto P_0c06f534;
P_0c06f534: /* original 7408, guest PC 0x0c06f534 */
if(!s->budget--) { s->failed_pc=0x0c06f534u; return 0; }
r[4]+=0x00000008u;
goto P_0c06f536;
P_0c06f536: /* original 35ec, guest PC 0x0c06f536 */
if(!s->budget--) { s->failed_pc=0x0c06f536u; return 0; }
r[5]+=r[14];
goto P_0c06f538;
P_0c06f538: /* original a004, guest PC 0x0c06f538 */
if(!s->budget--) { s->failed_pc=0x0c06f538u; return 0; }
goto P_0c06f544;
P_0c06f53a: /* original 0009, guest PC 0x0c06f53a */
if(!s->budget--) { s->failed_pc=0x0c06f53au; return 0; }
if(!vf3_matrix_family(0x0c06f53cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f53cu; return 0; } return 1;
P_0c06f544: /* original f449, guest PC 0x0c06f544 */
if(!s->budget--) { s->failed_pc=0x0c06f544u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f546;
P_0c06f546: /* original f549, guest PC 0x0c06f546 */
if(!s->budget--) { s->failed_pc=0x0c06f546u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f548;
P_0c06f548: /* original f648, guest PC 0x0c06f548 */
if(!s->budget--) { s->failed_pc=0x0c06f548u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c06f54a;
P_0c06f54a: /* original f79d, guest PC 0x0c06f54a */
if(!s->budget--) { s->failed_pc=0x0c06f54au; return 0; }
fr[7]=0x3f800000u;
goto P_0c06f54c;
P_0c06f54c: /* original f5fd, guest PC 0x0c06f54c */
if(!s->budget--) { s->failed_pc=0x0c06f54cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f54e;
P_0c06f54e: /* original 750c, guest PC 0x0c06f54e */
if(!s->budget--) { s->failed_pc=0x0c06f54eu; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f550;
P_0c06f550: /* original f56b, guest PC 0x0c06f550 */
if(!s->budget--) { s->failed_pc=0x0c06f550u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f552;
P_0c06f552: /* original f55b, guest PC 0x0c06f552 */
if(!s->budget--) { s->failed_pc=0x0c06f552u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f554;
P_0c06f554: /* original f54b, guest PC 0x0c06f554 */
if(!s->budget--) { s->failed_pc=0x0c06f554u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f556;
P_0c06f556: /* original 0009, guest PC 0x0c06f556 */
if(!s->budget--) { s->failed_pc=0x0c06f556u; return 0; }
goto P_0c06f558;
P_0c06f558: /* original 9504, guest PC 0x0c06f558 */
if(!s->budget--) { s->failed_pc=0x0c06f558u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f564u,2);
goto P_0c06f55a;
P_0c06f55a: /* original 64f3, guest PC 0x0c06f55a */
if(!s->budget--) { s->failed_pc=0x0c06f55au; return 0; }
r[4]=r[15];
goto P_0c06f55c;
P_0c06f55c: /* original 7414, guest PC 0x0c06f55c */
if(!s->budget--) { s->failed_pc=0x0c06f55cu; return 0; }
r[4]+=0x00000014u;
goto P_0c06f55e;
P_0c06f55e: /* original 35ec, guest PC 0x0c06f55e */
if(!s->budget--) { s->failed_pc=0x0c06f55eu; return 0; }
r[5]+=r[14];
goto P_0c06f560;
P_0c06f560: /* original a001, guest PC 0x0c06f560 */
if(!s->budget--) { s->failed_pc=0x0c06f560u; return 0; }
goto P_0c06f566;
P_0c06f562: /* original 0009, guest PC 0x0c06f562 */
if(!s->budget--) { s->failed_pc=0x0c06f562u; return 0; }
if(!vf3_matrix_family(0x0c06f564u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f564u; return 0; } return 1;
P_0c06f566: /* original f449, guest PC 0x0c06f566 */
if(!s->budget--) { s->failed_pc=0x0c06f566u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f568;
P_0c06f568: /* original f549, guest PC 0x0c06f568 */
if(!s->budget--) { s->failed_pc=0x0c06f568u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f56a;
P_0c06f56a: /* original f649, guest PC 0x0c06f56a */
if(!s->budget--) { s->failed_pc=0x0c06f56au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f56c;
P_0c06f56c: /* original f78d, guest PC 0x0c06f56c */
if(!s->budget--) { s->failed_pc=0x0c06f56cu; return 0; }
fr[7]=0;
goto P_0c06f56e;
P_0c06f56e: /* original f5fd, guest PC 0x0c06f56e */
if(!s->budget--) { s->failed_pc=0x0c06f56eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f570;
P_0c06f570: /* original 750c, guest PC 0x0c06f570 */
if(!s->budget--) { s->failed_pc=0x0c06f570u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f572;
P_0c06f572: /* original f56b, guest PC 0x0c06f572 */
if(!s->budget--) { s->failed_pc=0x0c06f572u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f574;
P_0c06f574: /* original f55b, guest PC 0x0c06f574 */
if(!s->budget--) { s->failed_pc=0x0c06f574u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f576;
P_0c06f576: /* original f54b, guest PC 0x0c06f576 */
if(!s->budget--) { s->failed_pc=0x0c06f576u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f578;
P_0c06f578: /* original e058, guest PC 0x0c06f578 */
if(!s->budget--) { s->failed_pc=0x0c06f578u; return 0; }
r[0]=0x00000058u;
goto P_0c06f57a;
P_0c06f57a: /* original 0aee, guest PC 0x0c06f57a */
if(!s->budget--) { s->failed_pc=0x0c06f57au; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c06f57c;
P_0c06f57c: /* original e05c, guest PC 0x0c06f57c */
if(!s->budget--) { s->failed_pc=0x0c06f57cu; return 0; }
r[0]=0x0000005cu;
goto P_0c06f57e;
P_0c06f57e: /* original 03ee, guest PC 0x0c06f57e */
if(!s->budget--) { s->failed_pc=0x0c06f57eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c06f580;
P_0c06f580: /* original e064, guest PC 0x0c06f580 */
if(!s->budget--) { s->failed_pc=0x0c06f580u; return 0; }
r[0]=0x00000064u;
goto P_0c06f582;
P_0c06f582: /* original 1f31, guest PC 0x0c06f582 */
if(!s->budget--) { s->failed_pc=0x0c06f582u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06f584;
P_0c06f584: /* original fee6, guest PC 0x0c06f584 */
if(!s->budget--) { s->failed_pc=0x0c06f584u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c06f586;
P_0c06f586: /* original c737, guest PC 0x0c06f586 */
if(!s->budget--) { s->failed_pc=0x0c06f586u; return 0; }
r[0]=code_base|0x0006f664u;
goto P_0c06f588;
P_0c06f588: /* original f308, guest PC 0x0c06f588 */
if(!s->budget--) { s->failed_pc=0x0c06f588u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06f58a;
P_0c06f58a: /* original e054, guest PC 0x0c06f58a */
if(!s->budget--) { s->failed_pc=0x0c06f58au; return 0; }
r[0]=0x00000054u;
goto P_0c06f58c;
P_0c06f58c: /* original fde6, guest PC 0x0c06f58c */
if(!s->budget--) { s->failed_pc=0x0c06f58cu; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c06f58e;
P_0c06f58e: /* original e048, guest PC 0x0c06f58e */
if(!s->budget--) { s->failed_pc=0x0c06f58eu; return 0; }
r[0]=0x00000048u;
goto P_0c06f590;
P_0c06f590: /* original d335, guest PC 0x0c06f590 */
if(!s->budget--) { s->failed_pc=0x0c06f590u; return 0; }
r[3]=read(ram,0x0c06f668u,4);
goto P_0c06f592;
P_0c06f592: /* original 04be, guest PC 0x0c06f592 */
if(!s->budget--) { s->failed_pc=0x0c06f592u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c06f594;
P_0c06f594: /* original 2348, guest PC 0x0c06f594 */
if(!s->budget--) { s->failed_pc=0x0c06f594u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06f596;
P_0c06f596: /* original 8f03, guest PC 0x0c06f596 */
if(!s->budget--) { s->failed_pc=0x0c06f596u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
if(!cond) { goto P_0c06f5a0; }
goto P_0c06f59a;
P_0c06f598: /* original fd32, guest PC 0x0c06f598 */
if(!s->budget--) { s->failed_pc=0x0c06f598u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c06f59a;
P_0c06f59a: /* original 9161, guest PC 0x0c06f59a */
if(!s->budget--) { s->failed_pc=0x0c06f59au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f660u,2);
goto P_0c06f59c;
P_0c06f59c: /* original 2148, guest PC 0x0c06f59c */
if(!s->budget--) { s->failed_pc=0x0c06f59cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c06f59e;
P_0c06f59e: /* original 8915, guest PC 0x0c06f59e */
if(!s->budget--) { s->failed_pc=0x0c06f59eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f5cc; }
goto P_0c06f5a0;
P_0c06f5a0: /* original f3d8, guest PC 0x0c06f5a0 */
if(!s->budget--) { s->failed_pc=0x0c06f5a0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c06f5a2;
P_0c06f5a2: /* original e06c, guest PC 0x0c06f5a2 */
if(!s->budget--) { s->failed_pc=0x0c06f5a2u; return 0; }
r[0]=0x0000006cu;
goto P_0c06f5a4;
P_0c06f5a4: /* original f34d, guest PC 0x0c06f5a4 */
if(!s->budget--) { s->failed_pc=0x0c06f5a4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c06f5a6;
P_0c06f5a6: /* original ff37, guest PC 0x0c06f5a6 */
if(!s->budget--) { s->failed_pc=0x0c06f5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f5a8;
P_0c06f5a8: /* original e070, guest PC 0x0c06f5a8 */
if(!s->budget--) { s->failed_pc=0x0c06f5a8u; return 0; }
r[0]=0x00000070u;
goto P_0c06f5aa;
P_0c06f5aa: /* original fff7, guest PC 0x0c06f5aa */
if(!s->budget--) { s->failed_pc=0x0c06f5aau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f5ac;
P_0c06f5ac: /* original c72f, guest PC 0x0c06f5ac */
if(!s->budget--) { s->failed_pc=0x0c06f5acu; return 0; }
r[0]=code_base|0x0006f66cu;
goto P_0c06f5ae;
P_0c06f5ae: /* original f408, guest PC 0x0c06f5ae */
if(!s->budget--) { s->failed_pc=0x0c06f5aeu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06f5b0;
P_0c06f5b0: /* original e060, guest PC 0x0c06f5b0 */
if(!s->budget--) { s->failed_pc=0x0c06f5b0u; return 0; }
r[0]=0x00000060u;
goto P_0c06f5b2;
P_0c06f5b2: /* original 00bc, guest PC 0x0c06f5b2 */
if(!s->budget--) { s->failed_pc=0x0c06f5b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06f5b4;
P_0c06f5b4: /* original 600c, guest PC 0x0c06f5b4 */
if(!s->budget--) { s->failed_pc=0x0c06f5b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c06f5b6;
P_0c06f5b6: /* original 8815, guest PC 0x0c06f5b6 */
if(!s->budget--) { s->failed_pc=0x0c06f5b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000015u)!=0);
goto P_0c06f5b8;
P_0c06f5b8: /* original 8b03, guest PC 0x0c06f5b8 */
if(!s->budget--) { s->failed_pc=0x0c06f5b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f5c2; }
goto P_0c06f5ba;
P_0c06f5ba: /* original f3d8, guest PC 0x0c06f5ba */
if(!s->budget--) { s->failed_pc=0x0c06f5bau; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c06f5bc;
P_0c06f5bc: /* original f342, guest PC 0x0c06f5bc */
if(!s->budget--) { s->failed_pc=0x0c06f5bcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f5be;
P_0c06f5be: /* original a002, guest PC 0x0c06f5be */
if(!s->budget--) { s->failed_pc=0x0c06f5beu; return 0; }
fr[3]^=0x80000000u;
goto P_0c06f5c6;
P_0c06f5c0: /* original f34d, guest PC 0x0c06f5c0 */
if(!s->budget--) { s->failed_pc=0x0c06f5c0u; return 0; }
fr[3]^=0x80000000u;
goto P_0c06f5c2;
P_0c06f5c2: /* original f3d8, guest PC 0x0c06f5c2 */
if(!s->budget--) { s->failed_pc=0x0c06f5c2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c06f5c4;
P_0c06f5c4: /* original f342, guest PC 0x0c06f5c4 */
if(!s->budget--) { s->failed_pc=0x0c06f5c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f5c6;
P_0c06f5c6: /* original e068, guest PC 0x0c06f5c6 */
if(!s->budget--) { s->failed_pc=0x0c06f5c6u; return 0; }
r[0]=0x00000068u;
goto P_0c06f5c8;
P_0c06f5c8: /* original a00b, guest PC 0x0c06f5c8 */
if(!s->budget--) { s->failed_pc=0x0c06f5c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f5e2;
P_0c06f5ca: /* original ff37, guest PC 0x0c06f5ca */
if(!s->budget--) { s->failed_pc=0x0c06f5cau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f5cc;
P_0c06f5cc: /* original e070, guest PC 0x0c06f5cc */
if(!s->budget--) { s->failed_pc=0x0c06f5ccu; return 0; }
r[0]=0x00000070u;
goto P_0c06f5ce;
P_0c06f5ce: /* original fff7, guest PC 0x0c06f5ce */
if(!s->budget--) { s->failed_pc=0x0c06f5ceu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f5d0;
P_0c06f5d0: /* original e068, guest PC 0x0c06f5d0 */
if(!s->budget--) { s->failed_pc=0x0c06f5d0u; return 0; }
r[0]=0x00000068u;
goto P_0c06f5d2;
P_0c06f5d2: /* original fff7, guest PC 0x0c06f5d2 */
if(!s->budget--) { s->failed_pc=0x0c06f5d2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c06f5d4;
P_0c06f5d4: /* original c726, guest PC 0x0c06f5d4 */
if(!s->budget--) { s->failed_pc=0x0c06f5d4u; return 0; }
r[0]=code_base|0x0006f670u;
goto P_0c06f5d6;
P_0c06f5d6: /* original f2d8, guest PC 0x0c06f5d6 */
if(!s->budget--) { s->failed_pc=0x0c06f5d6u; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c06f5d8;
P_0c06f5d8: /* original f308, guest PC 0x0c06f5d8 */
if(!s->budget--) { s->failed_pc=0x0c06f5d8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06f5da;
P_0c06f5da: /* original e06c, guest PC 0x0c06f5da */
if(!s->budget--) { s->failed_pc=0x0c06f5dau; return 0; }
r[0]=0x0000006cu;
goto P_0c06f5dc;
P_0c06f5dc: /* original f232, guest PC 0x0c06f5dc */
if(!s->budget--) { s->failed_pc=0x0c06f5dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f5de;
P_0c06f5de: /* original f24d, guest PC 0x0c06f5de */
if(!s->budget--) { s->failed_pc=0x0c06f5deu; return 0; }
fr[2]^=0x80000000u;
goto P_0c06f5e0;
P_0c06f5e0: /* original ff27, guest PC 0x0c06f5e0 */
if(!s->budget--) { s->failed_pc=0x0c06f5e0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06f5e2;
P_0c06f5e2: /* original e061, guest PC 0x0c06f5e2 */
if(!s->budget--) { s->failed_pc=0x0c06f5e2u; return 0; }
r[0]=0x00000061u;
goto P_0c06f5e4;
P_0c06f5e4: /* original 04bc, guest PC 0x0c06f5e4 */
if(!s->budget--) { s->failed_pc=0x0c06f5e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06f5e6;
P_0c06f5e6: /* original 604c, guest PC 0x0c06f5e6 */
if(!s->budget--) { s->failed_pc=0x0c06f5e6u; return 0; }
r[0]=r[4]&255u;
goto P_0c06f5e8;
P_0c06f5e8: /* original 8808, guest PC 0x0c06f5e8 */
if(!s->budget--) { s->failed_pc=0x0c06f5e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c06f5ea;
P_0c06f5ea: /* original 8d03, guest PC 0x0c06f5ea */
if(!s->budget--) { s->failed_pc=0x0c06f5eau; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06f5f4; }
goto P_0c06f5ee;
P_0c06f5ec: /* original 6403, guest PC 0x0c06f5ec */
if(!s->budget--) { s->failed_pc=0x0c06f5ecu; return 0; }
r[4]=r[0];
goto P_0c06f5ee;
P_0c06f5ee: /* original 6043, guest PC 0x0c06f5ee */
if(!s->budget--) { s->failed_pc=0x0c06f5eeu; return 0; }
r[0]=r[4];
goto P_0c06f5f0;
P_0c06f5f0: /* original 880c, guest PC 0x0c06f5f0 */
if(!s->budget--) { s->failed_pc=0x0c06f5f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c06f5f2;
P_0c06f5f2: /* original 8b00, guest PC 0x0c06f5f2 */
if(!s->budget--) { s->failed_pc=0x0c06f5f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06f5f6; }
goto P_0c06f5f4;
P_0c06f5f4: /* original e901, guest PC 0x0c06f5f4 */
if(!s->budget--) { s->failed_pc=0x0c06f5f4u; return 0; }
r[9]=0x00000001u;
goto P_0c06f5f6;
P_0c06f5f6: /* original 6493, guest PC 0x0c06f5f6 */
if(!s->budget--) { s->failed_pc=0x0c06f5f6u; return 0; }
r[4]=r[9];
goto P_0c06f5f8;
P_0c06f5f8: /* original 74ff, guest PC 0x0c06f5f8 */
if(!s->budget--) { s->failed_pc=0x0c06f5f8u; return 0; }
r[4]+=0xffffffffu;
goto P_0c06f5fa;
P_0c06f5fa: /* original 04a7, guest PC 0x0c06f5fa */
if(!s->budget--) { s->failed_pc=0x0c06f5fau; return 0; }
r[19]=r[4]*r[10];
goto P_0c06f5fc;
P_0c06f5fc: /* original 52e1, guest PC 0x0c06f5fc */
if(!s->budget--) { s->failed_pc=0x0c06f5fcu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c06f5fe;
P_0c06f5fe: /* original 6da3, guest PC 0x0c06f5fe */
if(!s->budget--) { s->failed_pc=0x0c06f5feu; return 0; }
r[13]=r[10];
goto P_0c06f600;
P_0c06f600: /* original e03e, guest PC 0x0c06f600 */
if(!s->budget--) { s->failed_pc=0x0c06f600u; return 0; }
r[0]=0x0000003eu;
goto P_0c06f602;
P_0c06f602: /* original 041a, guest PC 0x0c06f602 */
if(!s->budget--) { s->failed_pc=0x0c06f602u; return 0; }
r[4]=r[19];
goto P_0c06f604;
P_0c06f604: /* original 6c43, guest PC 0x0c06f604 */
if(!s->budget--) { s->failed_pc=0x0c06f604u; return 0; }
r[12]=r[4];
goto P_0c06f606;
P_0c06f606: /* original 4c00, guest PC 0x0c06f606 */
if(!s->budget--) { s->failed_pc=0x0c06f606u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c06f608;
P_0c06f608: /* original 6343, guest PC 0x0c06f608 */
if(!s->budget--) { s->failed_pc=0x0c06f608u; return 0; }
r[3]=r[4];
goto P_0c06f60a;
P_0c06f60a: /* original 3c3c, guest PC 0x0c06f60a */
if(!s->budget--) { s->failed_pc=0x0c06f60au; return 0; }
r[12]+=r[3];
goto P_0c06f60c;
P_0c06f60c: /* original 4c08, guest PC 0x0c06f60c */
if(!s->budget--) { s->failed_pc=0x0c06f60cu; return 0; }
r[12]<<=2;
goto P_0c06f60e;
P_0c06f60e: /* original 63a3, guest PC 0x0c06f60e */
if(!s->budget--) { s->failed_pc=0x0c06f60eu; return 0; }
r[3]=r[10];
goto P_0c06f610;
P_0c06f610: /* original 4c00, guest PC 0x0c06f610 */
if(!s->budget--) { s->failed_pc=0x0c06f610u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c06f612;
P_0c06f612: /* original 4d00, guest PC 0x0c06f612 */
if(!s->budget--) { s->failed_pc=0x0c06f612u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c06f614;
P_0c06f614: /* original 3c2c, guest PC 0x0c06f614 */
if(!s->budget--) { s->failed_pc=0x0c06f614u; return 0; }
r[12]+=r[2];
goto P_0c06f616;
P_0c06f616: /* original 52e3, guest PC 0x0c06f616 */
if(!s->budget--) { s->failed_pc=0x0c06f616u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06f618;
P_0c06f618: /* original 3d3c, guest PC 0x0c06f618 */
if(!s->budget--) { s->failed_pc=0x0c06f618u; return 0; }
r[13]+=r[3];
goto P_0c06f61a;
P_0c06f61a: /* original 2f22, guest PC 0x0c06f61a */
if(!s->budget--) { s->failed_pc=0x0c06f61au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06f61c;
P_0c06f61c: /* original 4d08, guest PC 0x0c06f61c */
if(!s->budget--) { s->failed_pc=0x0c06f61cu; return 0; }
r[13]<<=2;
goto P_0c06f61e;
P_0c06f61e: /* original 03bd, guest PC 0x0c06f61e */
if(!s->budget--) { s->failed_pc=0x0c06f61eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c06f620;
P_0c06f620: /* original e202, guest PC 0x0c06f620 */
if(!s->budget--) { s->failed_pc=0x0c06f620u; return 0; }
r[2]=0x00000002u;
goto P_0c06f622;
P_0c06f622: /* original 4d00, guest PC 0x0c06f622 */
if(!s->budget--) { s->failed_pc=0x0c06f622u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c06f624;
P_0c06f624: /* original 633d, guest PC 0x0c06f624 */
if(!s->budget--) { s->failed_pc=0x0c06f624u; return 0; }
r[3]=r[3]&65535u;
goto P_0c06f626;
P_0c06f626: /* original 3323, guest PC 0x0c06f626 */
if(!s->budget--) { s->failed_pc=0x0c06f626u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c06f628;
P_0c06f628: /* original 8d03, guest PC 0x0c06f628 */
if(!s->budget--) { s->failed_pc=0x0c06f628u; return 0; }
cond=r[17]&1u;
r[13]+=r[12];
if(cond) { goto P_0c06f632; }
goto P_0c06f62c;
P_0c06f62a: /* original 3dcc, guest PC 0x0c06f62a */
if(!s->budget--) { s->failed_pc=0x0c06f62au; return 0; }
r[13]+=r[12];
goto P_0c06f62c;
P_0c06f62c: /* original d311, guest PC 0x0c06f62c */
if(!s->budget--) { s->failed_pc=0x0c06f62cu; return 0; }
r[3]=read(ram,0x0c06f674u,4);
goto P_0c06f62e;
P_0c06f62e: /* original 432b, guest PC 0x0c06f62e */
if(!s->budget--) { s->failed_pc=0x0c06f62eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c06f96au: goto P_0c06f96a;
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
P_0c06f630: /* original 0009, guest PC 0x0c06f630 */
if(!s->budget--) { s->failed_pc=0x0c06f630u; return 0; }
goto P_0c06f632;
P_0c06f632: /* original d311, guest PC 0x0c06f632 */
if(!s->budget--) { s->failed_pc=0x0c06f632u; return 0; }
r[3]=read(ram,0x0c06f678u,4);
goto P_0c06f634;
P_0c06f634: /* original 430b, guest PC 0x0c06f634 */
if(!s->budget--) { s->failed_pc=0x0c06f634u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f638u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f638u) { target=s->pc; goto dispatch; }
goto P_0c06f638;
P_0c06f636: /* original e400, guest PC 0x0c06f636 */
if(!s->budget--) { s->failed_pc=0x0c06f636u; return 0; }
r[4]=0x00000000u;
goto P_0c06f638;
P_0c06f638: /* original d310, guest PC 0x0c06f638 */
if(!s->budget--) { s->failed_pc=0x0c06f638u; return 0; }
r[3]=read(ram,0x0c06f67cu,4);
goto P_0c06f63a;
P_0c06f63a: /* original 430b, guest PC 0x0c06f63a */
if(!s->budget--) { s->failed_pc=0x0c06f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c06f63eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f63eu) { target=s->pc; goto dispatch; }
goto P_0c06f63e;
P_0c06f63c: /* original 64f2, guest PC 0x0c06f63c */
if(!s->budget--) { s->failed_pc=0x0c06f63cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06f63e;
P_0c06f63e: /* original d210, guest PC 0x0c06f63e */
if(!s->budget--) { s->failed_pc=0x0c06f63eu; return 0; }
r[2]=read(ram,0x0c06f680u,4);
goto P_0c06f640;
P_0c06f640: /* original 420b, guest PC 0x0c06f640 */
if(!s->budget--) { s->failed_pc=0x0c06f640u; return 0; }
target=r[2];
r[16]=code_base|0x0c06f644u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f644u) { target=s->pc; goto dispatch; }
goto P_0c06f644;
P_0c06f642: /* original 0009, guest PC 0x0c06f642 */
if(!s->budget--) { s->failed_pc=0x0c06f642u; return 0; }
goto P_0c06f644;
P_0c06f644: /* original e048, guest PC 0x0c06f644 */
if(!s->budget--) { s->failed_pc=0x0c06f644u; return 0; }
r[0]=0x00000048u;
goto P_0c06f646;
P_0c06f646: /* original d30f, guest PC 0x0c06f646 */
if(!s->budget--) { s->failed_pc=0x0c06f646u; return 0; }
r[3]=read(ram,0x0c06f684u,4);
goto P_0c06f648;
P_0c06f648: /* original 02be, guest PC 0x0c06f648 */
if(!s->budget--) { s->failed_pc=0x0c06f648u; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c06f64a;
P_0c06f64a: /* original 2238, guest PC 0x0c06f64a */
if(!s->budget--) { s->failed_pc=0x0c06f64au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06f64c;
P_0c06f64c: /* original 8902, guest PC 0x0c06f64c */
if(!s->budget--) { s->failed_pc=0x0c06f64cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f654; }
goto P_0c06f64e;
P_0c06f64e: /* original d10e, guest PC 0x0c06f64e */
if(!s->budget--) { s->failed_pc=0x0c06f64eu; return 0; }
r[1]=read(ram,0x0c06f688u,4);
goto P_0c06f650;
P_0c06f650: /* original 412b, guest PC 0x0c06f650 */
if(!s->budget--) { s->failed_pc=0x0c06f650u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c06f6a0u: goto P_0c06f6a0;
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
P_0c06f652: /* original 0009, guest PC 0x0c06f652 */
if(!s->budget--) { s->failed_pc=0x0c06f652u; return 0; }
goto P_0c06f654;
P_0c06f654: /* original 64f3, guest PC 0x0c06f654 */
if(!s->budget--) { s->failed_pc=0x0c06f654u; return 0; }
r[4]=r[15];
goto P_0c06f656;
P_0c06f656: /* original 65f3, guest PC 0x0c06f656 */
if(!s->budget--) { s->failed_pc=0x0c06f656u; return 0; }
r[5]=r[15];
goto P_0c06f658;
P_0c06f658: /* original 7468, guest PC 0x0c06f658 */
if(!s->budget--) { s->failed_pc=0x0c06f658u; return 0; }
r[4]+=0x00000068u;
goto P_0c06f65a;
P_0c06f65a: /* original 7568, guest PC 0x0c06f65a */
if(!s->budget--) { s->failed_pc=0x0c06f65au; return 0; }
r[5]+=0x00000068u;
goto P_0c06f65c;
P_0c06f65c: /* original a016, guest PC 0x0c06f65c */
if(!s->budget--) { s->failed_pc=0x0c06f65cu; return 0; }
goto P_0c06f68c;
P_0c06f65e: /* original 0009, guest PC 0x0c06f65e */
if(!s->budget--) { s->failed_pc=0x0c06f65eu; return 0; }
if(!vf3_matrix_family(0x0c06f660u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f660u; return 0; } return 1;
P_0c06f68c: /* original f449, guest PC 0x0c06f68c */
if(!s->budget--) { s->failed_pc=0x0c06f68cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f68e;
P_0c06f68e: /* original f549, guest PC 0x0c06f68e */
if(!s->budget--) { s->failed_pc=0x0c06f68eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f690;
P_0c06f690: /* original f649, guest PC 0x0c06f690 */
if(!s->budget--) { s->failed_pc=0x0c06f690u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f692;
P_0c06f692: /* original f78d, guest PC 0x0c06f692 */
if(!s->budget--) { s->failed_pc=0x0c06f692u; return 0; }
fr[7]=0;
goto P_0c06f694;
P_0c06f694: /* original f5fd, guest PC 0x0c06f694 */
if(!s->budget--) { s->failed_pc=0x0c06f694u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c06f696;
P_0c06f696: /* original 750c, guest PC 0x0c06f696 */
if(!s->budget--) { s->failed_pc=0x0c06f696u; return 0; }
r[5]+=0x0000000cu;
goto P_0c06f698;
P_0c06f698: /* original f56b, guest PC 0x0c06f698 */
if(!s->budget--) { s->failed_pc=0x0c06f698u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c06f69a;
P_0c06f69a: /* original f55b, guest PC 0x0c06f69a */
if(!s->budget--) { s->failed_pc=0x0c06f69au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c06f69c;
P_0c06f69c: /* original f54b, guest PC 0x0c06f69c */
if(!s->budget--) { s->failed_pc=0x0c06f69cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06f69e;
P_0c06f69e: /* original 0009, guest PC 0x0c06f69e */
if(!s->budget--) { s->failed_pc=0x0c06f69eu; return 0; }
goto P_0c06f6a0;
P_0c06f6a0: /* original 64e3, guest PC 0x0c06f6a0 */
if(!s->budget--) { s->failed_pc=0x0c06f6a0u; return 0; }
r[4]=r[14];
goto P_0c06f6a2;
P_0c06f6a2: /* original 480b, guest PC 0x0c06f6a2 */
if(!s->budget--) { s->failed_pc=0x0c06f6a2u; return 0; }
target=r[8];
r[16]=code_base|0x0c06f6a6u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f6a6u) { target=s->pc; goto dispatch; }
goto P_0c06f6a6;
P_0c06f6a4: /* original 7410, guest PC 0x0c06f6a4 */
if(!s->budget--) { s->failed_pc=0x0c06f6a4u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f6a6;
P_0c06f6a6: /* original d30b, guest PC 0x0c06f6a6 */
if(!s->budget--) { s->failed_pc=0x0c06f6a6u; return 0; }
r[3]=read(ram,0x0c06f6d4u,4);
goto P_0c06f6a8;
P_0c06f6a8: /* original 6893, guest PC 0x0c06f6a8 */
if(!s->budget--) { s->failed_pc=0x0c06f6a8u; return 0; }
r[8]=r[9];
goto P_0c06f6aa;
P_0c06f6aa: /* original 432b, guest PC 0x0c06f6aa */
if(!s->budget--) { s->failed_pc=0x0c06f6aau; return 0; }
target=r[3];
fr[12]=0x3f800000u;
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
P_0c06f6ac: /* original fc9d, guest PC 0x0c06f6ac */
if(!s->budget--) { s->failed_pc=0x0c06f6acu; return 0; }
fr[12]=0x3f800000u;
if(!vf3_matrix_family(0x0c06f6aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f6aeu; return 0; } return 1;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=code_base|0x0c06f974u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
