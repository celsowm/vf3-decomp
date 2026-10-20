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
int vf3_c90b_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c072d0cu: goto P_0c072d0c;
case 0x0c072d0eu: goto P_0c072d0e;
case 0x0c072d10u: goto P_0c072d10;
case 0x0c072d12u: goto P_0c072d12;
case 0x0c072d14u: goto P_0c072d14;
case 0x0c072d16u: goto P_0c072d16;
case 0x0c072d18u: goto P_0c072d18;
case 0x0c072d1au: goto P_0c072d1a;
case 0x0c072d1cu: goto P_0c072d1c;
case 0x0c0733d0u: goto P_0c0733d0;
case 0x0c0733d2u: goto P_0c0733d2;
case 0x0c0733d4u: goto P_0c0733d4;
case 0x0c0733d6u: goto P_0c0733d6;
case 0x0c0733d8u: goto P_0c0733d8;
case 0x0c0733dau: goto P_0c0733da;
case 0x0c0733dcu: goto P_0c0733dc;
case 0x0c0733deu: goto P_0c0733de;
case 0x0c0733e0u: goto P_0c0733e0;
case 0x0c0733e2u: goto P_0c0733e2;
case 0x0c0733e4u: goto P_0c0733e4;
case 0x0c0733e6u: goto P_0c0733e6;
case 0x0c0733e8u: goto P_0c0733e8;
case 0x0c0733eau: goto P_0c0733ea;
case 0x0c0733ecu: goto P_0c0733ec;
case 0x0c0733eeu: goto P_0c0733ee;
case 0x0c0733f0u: goto P_0c0733f0;
case 0x0c0733f2u: goto P_0c0733f2;
case 0x0c0733f4u: goto P_0c0733f4;
case 0x0c0733f6u: goto P_0c0733f6;
case 0x0c0733f8u: goto P_0c0733f8;
case 0x0c0733fau: goto P_0c0733fa;
case 0x0c0733fcu: goto P_0c0733fc;
case 0x0c0733feu: goto P_0c0733fe;
case 0x0c073400u: goto P_0c073400;
case 0x0c073402u: goto P_0c073402;
case 0x0c073404u: goto P_0c073404;
case 0x0c073406u: goto P_0c073406;
case 0x0c073408u: goto P_0c073408;
case 0x0c07340au: goto P_0c07340a;
case 0x0c07340cu: goto P_0c07340c;
case 0x0c07340eu: goto P_0c07340e;
case 0x0c073410u: goto P_0c073410;
case 0x0c073412u: goto P_0c073412;
case 0x0c073414u: goto P_0c073414;
case 0x0c073416u: goto P_0c073416;
case 0x0c073418u: goto P_0c073418;
case 0x0c07341au: goto P_0c07341a;
case 0x0c07341cu: goto P_0c07341c;
case 0x0c07341eu: goto P_0c07341e;
case 0x0c073420u: goto P_0c073420;
case 0x0c073422u: goto P_0c073422;
case 0x0c073424u: goto P_0c073424;
case 0x0c073426u: goto P_0c073426;
case 0x0c073428u: goto P_0c073428;
case 0x0c07342au: goto P_0c07342a;
case 0x0c07342cu: goto P_0c07342c;
case 0x0c07342eu: goto P_0c07342e;
case 0x0c073430u: goto P_0c073430;
case 0x0c073432u: goto P_0c073432;
case 0x0c073434u: goto P_0c073434;
case 0x0c073436u: goto P_0c073436;
case 0x0c073438u: goto P_0c073438;
case 0x0c07343au: goto P_0c07343a;
case 0x0c07343cu: goto P_0c07343c;
case 0x0c07343eu: goto P_0c07343e;
case 0x0c073440u: goto P_0c073440;
case 0x0c073442u: goto P_0c073442;
case 0x0c073444u: goto P_0c073444;
case 0x0c073446u: goto P_0c073446;
case 0x0c073448u: goto P_0c073448;
case 0x0c07344au: goto P_0c07344a;
case 0x0c07344cu: goto P_0c07344c;
case 0x0c07344eu: goto P_0c07344e;
case 0x0c073450u: goto P_0c073450;
case 0x0c073452u: goto P_0c073452;
case 0x0c073454u: goto P_0c073454;
case 0x0c073456u: goto P_0c073456;
case 0x0c073458u: goto P_0c073458;
case 0x0c07345au: goto P_0c07345a;
case 0x0c07345cu: goto P_0c07345c;
case 0x0c07345eu: goto P_0c07345e;
case 0x0c073460u: goto P_0c073460;
case 0x0c073462u: goto P_0c073462;
case 0x0c073464u: goto P_0c073464;
case 0x0c073466u: goto P_0c073466;
case 0x0c073468u: goto P_0c073468;
case 0x0c07346au: goto P_0c07346a;
case 0x0c07346cu: goto P_0c07346c;
case 0x0c07346eu: goto P_0c07346e;
case 0x0c073470u: goto P_0c073470;
case 0x0c073472u: goto P_0c073472;
case 0x0c073474u: goto P_0c073474;
case 0x0c073476u: goto P_0c073476;
case 0x0c073478u: goto P_0c073478;
case 0x0c07347au: goto P_0c07347a;
case 0x0c07347cu: goto P_0c07347c;
case 0x0c07347eu: goto P_0c07347e;
case 0x0c073480u: goto P_0c073480;
case 0x0c073482u: goto P_0c073482;
case 0x0c073484u: goto P_0c073484;
case 0x0c073486u: goto P_0c073486;
case 0x0c073488u: goto P_0c073488;
case 0x0c07348au: goto P_0c07348a;
case 0x0c07348cu: goto P_0c07348c;
case 0x0c07348eu: goto P_0c07348e;
case 0x0c073490u: goto P_0c073490;
case 0x0c073492u: goto P_0c073492;
case 0x0c073494u: goto P_0c073494;
case 0x0c073496u: goto P_0c073496;
case 0x0c073498u: goto P_0c073498;
case 0x0c07349au: goto P_0c07349a;
case 0x0c07349cu: goto P_0c07349c;
case 0x0c07349eu: goto P_0c07349e;
case 0x0c0734a0u: goto P_0c0734a0;
case 0x0c0734a2u: goto P_0c0734a2;
case 0x0c0734a4u: goto P_0c0734a4;
case 0x0c0734a6u: goto P_0c0734a6;
case 0x0c0734a8u: goto P_0c0734a8;
case 0x0c0734aau: goto P_0c0734aa;
case 0x0c0734acu: goto P_0c0734ac;
case 0x0c0734aeu: goto P_0c0734ae;
case 0x0c0734b0u: goto P_0c0734b0;
case 0x0c0734b2u: goto P_0c0734b2;
case 0x0c0734b4u: goto P_0c0734b4;
case 0x0c0734b6u: goto P_0c0734b6;
case 0x0c0734b8u: goto P_0c0734b8;
case 0x0c0734bau: goto P_0c0734ba;
case 0x0c0734bcu: goto P_0c0734bc;
case 0x0c0734beu: goto P_0c0734be;
case 0x0c0734c0u: goto P_0c0734c0;
case 0x0c0734c2u: goto P_0c0734c2;
case 0x0c0734c4u: goto P_0c0734c4;
case 0x0c0734c6u: goto P_0c0734c6;
case 0x0c0734c8u: goto P_0c0734c8;
case 0x0c0734cau: goto P_0c0734ca;
case 0x0c0734ccu: goto P_0c0734cc;
case 0x0c0734ceu: goto P_0c0734ce;
case 0x0c0734d0u: goto P_0c0734d0;
case 0x0c0734d2u: goto P_0c0734d2;
case 0x0c0734d4u: goto P_0c0734d4;
case 0x0c0734d6u: goto P_0c0734d6;
case 0x0c0734d8u: goto P_0c0734d8;
case 0x0c0734dau: goto P_0c0734da;
case 0x0c0734dcu: goto P_0c0734dc;
case 0x0c0734deu: goto P_0c0734de;
case 0x0c0734e0u: goto P_0c0734e0;
case 0x0c0734e2u: goto P_0c0734e2;
case 0x0c0734e4u: goto P_0c0734e4;
case 0x0c0734e6u: goto P_0c0734e6;
case 0x0c0734e8u: goto P_0c0734e8;
case 0x0c0734eau: goto P_0c0734ea;
case 0x0c0734ecu: goto P_0c0734ec;
case 0x0c0734eeu: goto P_0c0734ee;
case 0x0c0734f0u: goto P_0c0734f0;
case 0x0c0734f2u: goto P_0c0734f2;
case 0x0c0734f4u: goto P_0c0734f4;
case 0x0c07f436u: goto P_0c07f436;
case 0x0c07f438u: goto P_0c07f438;
case 0x0c07f43au: goto P_0c07f43a;
case 0x0c07f43cu: goto P_0c07f43c;
case 0x0c07f43eu: goto P_0c07f43e;
case 0x0c07f440u: goto P_0c07f440;
case 0x0c07f442u: goto P_0c07f442;
case 0x0c07f444u: goto P_0c07f444;
case 0x0c07f446u: goto P_0c07f446;
case 0x0c07f448u: goto P_0c07f448;
case 0x0c07f44au: goto P_0c07f44a;
case 0x0c07f44cu: goto P_0c07f44c;
case 0x0c07f44eu: goto P_0c07f44e;
case 0x0c07f450u: goto P_0c07f450;
case 0x0c07f452u: goto P_0c07f452;
case 0x0c07f454u: goto P_0c07f454;
case 0x0c07f456u: goto P_0c07f456;
case 0x0c07f458u: goto P_0c07f458;
case 0x0c07f45au: goto P_0c07f45a;
case 0x0c07f45cu: goto P_0c07f45c;
case 0x0c07f45eu: goto P_0c07f45e;
case 0x0c07f460u: goto P_0c07f460;
case 0x0c07f462u: goto P_0c07f462;
case 0x0c07f464u: goto P_0c07f464;
case 0x0c07f466u: goto P_0c07f466;
case 0x0c07f468u: goto P_0c07f468;
case 0x0c07f46au: goto P_0c07f46a;
case 0x0c07f46cu: goto P_0c07f46c;
case 0x0c07f46eu: goto P_0c07f46e;
case 0x0c07f470u: goto P_0c07f470;
case 0x0c07f472u: goto P_0c07f472;
case 0x0c07f474u: goto P_0c07f474;
case 0x0c07f476u: goto P_0c07f476;
case 0x0c07f478u: goto P_0c07f478;
case 0x0c07f47au: goto P_0c07f47a;
case 0x0c07f47cu: goto P_0c07f47c;
case 0x0c07f47eu: goto P_0c07f47e;
case 0x0c07f480u: goto P_0c07f480;
case 0x0c07f482u: goto P_0c07f482;
case 0x0c07f484u: goto P_0c07f484;
case 0x0c07f486u: goto P_0c07f486;
case 0x0c07f488u: goto P_0c07f488;
case 0x0c07f48au: goto P_0c07f48a;
case 0x0c07f48cu: goto P_0c07f48c;
case 0x0c07f48eu: goto P_0c07f48e;
case 0x0c07f490u: goto P_0c07f490;
case 0x0c07f492u: goto P_0c07f492;
case 0x0c07f494u: goto P_0c07f494;
case 0x0c07f496u: goto P_0c07f496;
case 0x0c07f498u: goto P_0c07f498;
case 0x0c07f49au: goto P_0c07f49a;
case 0x0c07f49cu: goto P_0c07f49c;
case 0x0c07f49eu: goto P_0c07f49e;
case 0x0c07f4a0u: goto P_0c07f4a0;
case 0x0c07f4a2u: goto P_0c07f4a2;
case 0x0c07f4a4u: goto P_0c07f4a4;
case 0x0c07f4a6u: goto P_0c07f4a6;
case 0x0c07f4a8u: goto P_0c07f4a8;
case 0x0c07f4aau: goto P_0c07f4aa;
case 0x0c07f4acu: goto P_0c07f4ac;
case 0x0c07f4aeu: goto P_0c07f4ae;
case 0x0c07f4b0u: goto P_0c07f4b0;
case 0x0c07f4b2u: goto P_0c07f4b2;
case 0x0c07f4b4u: goto P_0c07f4b4;
case 0x0c07f4b6u: goto P_0c07f4b6;
case 0x0c07f4b8u: goto P_0c07f4b8;
case 0x0c07f4bau: goto P_0c07f4ba;
case 0x0c07f4bcu: goto P_0c07f4bc;
case 0x0c07f4beu: goto P_0c07f4be;
case 0x0c07f4c0u: goto P_0c07f4c0;
case 0x0c07f4c2u: goto P_0c07f4c2;
case 0x0c07f4c4u: goto P_0c07f4c4;
case 0x0c07f4c6u: goto P_0c07f4c6;
case 0x0c07f4c8u: goto P_0c07f4c8;
case 0x0c07f4cau: goto P_0c07f4ca;
case 0x0c07f4ccu: goto P_0c07f4cc;
case 0x0c07f4ceu: goto P_0c07f4ce;
case 0x0c07f4d0u: goto P_0c07f4d0;
case 0x0c07f4d2u: goto P_0c07f4d2;
case 0x0c07f4d4u: goto P_0c07f4d4;
case 0x0c07f4d6u: goto P_0c07f4d6;
case 0x0c07f4d8u: goto P_0c07f4d8;
case 0x0c07f4dau: goto P_0c07f4da;
case 0x0c07f4dcu: goto P_0c07f4dc;
case 0x0c07f4deu: goto P_0c07f4de;
case 0x0c07f4e0u: goto P_0c07f4e0;
case 0x0c07f4e2u: goto P_0c07f4e2;
case 0x0c07f4e4u: goto P_0c07f4e4;
case 0x0c07f4e6u: goto P_0c07f4e6;
case 0x0c07f4e8u: goto P_0c07f4e8;
case 0x0c07f4eau: goto P_0c07f4ea;
case 0x0c07f4ecu: goto P_0c07f4ec;
case 0x0c07f4eeu: goto P_0c07f4ee;
case 0x0c07f4f0u: goto P_0c07f4f0;
case 0x0c07f4f2u: goto P_0c07f4f2;
case 0x0c07f4f4u: goto P_0c07f4f4;
case 0x0c07f4f6u: goto P_0c07f4f6;
case 0x0c07f4f8u: goto P_0c07f4f8;
case 0x0c07f4fau: goto P_0c07f4fa;
case 0x0c07f4fcu: goto P_0c07f4fc;
case 0x0c07f4feu: goto P_0c07f4fe;
case 0x0c07f500u: goto P_0c07f500;
case 0x0c07f502u: goto P_0c07f502;
case 0x0c07f504u: goto P_0c07f504;
case 0x0c07f506u: goto P_0c07f506;
case 0x0c07f508u: goto P_0c07f508;
case 0x0c07f50au: goto P_0c07f50a;
case 0x0c07f50cu: goto P_0c07f50c;
case 0x0c07f50eu: goto P_0c07f50e;
case 0x0c07f510u: goto P_0c07f510;
case 0x0c07f512u: goto P_0c07f512;
case 0x0c07f514u: goto P_0c07f514;
case 0x0c07f516u: goto P_0c07f516;
case 0x0c07f518u: goto P_0c07f518;
case 0x0c07f51au: goto P_0c07f51a;
case 0x0c07f51cu: goto P_0c07f51c;
case 0x0c07f51eu: goto P_0c07f51e;
case 0x0c07f520u: goto P_0c07f520;
case 0x0c07f522u: goto P_0c07f522;
case 0x0c07f524u: goto P_0c07f524;
case 0x0c07f526u: goto P_0c07f526;
case 0x0c07f528u: goto P_0c07f528;
case 0x0c07f52au: goto P_0c07f52a;
case 0x0c07f52cu: goto P_0c07f52c;
case 0x0c07f52eu: goto P_0c07f52e;
case 0x0c07f530u: goto P_0c07f530;
case 0x0c07f532u: goto P_0c07f532;
case 0x0c07f534u: goto P_0c07f534;
case 0x0c07f536u: goto P_0c07f536;
case 0x0c07f538u: goto P_0c07f538;
case 0x0c07f53au: goto P_0c07f53a;
case 0x0c07f53cu: goto P_0c07f53c;
case 0x0c07f53eu: goto P_0c07f53e;
case 0x0c07f540u: goto P_0c07f540;
case 0x0c07f580u: goto P_0c07f580;
case 0x0c07f582u: goto P_0c07f582;
case 0x0c07f584u: goto P_0c07f584;
case 0x0c07f586u: goto P_0c07f586;
case 0x0c07f588u: goto P_0c07f588;
case 0x0c07f58au: goto P_0c07f58a;
case 0x0c07f58cu: goto P_0c07f58c;
case 0x0c07f58eu: goto P_0c07f58e;
case 0x0c07f590u: goto P_0c07f590;
case 0x0c07f592u: goto P_0c07f592;
case 0x0c07f594u: goto P_0c07f594;
case 0x0c07f596u: goto P_0c07f596;
case 0x0c07f598u: goto P_0c07f598;
case 0x0c07f59au: goto P_0c07f59a;
case 0x0c07f59cu: goto P_0c07f59c;
case 0x0c07f59eu: goto P_0c07f59e;
case 0x0c07f5a0u: goto P_0c07f5a0;
case 0x0c07f5a2u: goto P_0c07f5a2;
case 0x0c07f5a4u: goto P_0c07f5a4;
case 0x0c07f5a6u: goto P_0c07f5a6;
case 0x0c07f5a8u: goto P_0c07f5a8;
case 0x0c07f5aau: goto P_0c07f5aa;
case 0x0c07f5acu: goto P_0c07f5ac;
case 0x0c07f5aeu: goto P_0c07f5ae;
case 0x0c07f5b0u: goto P_0c07f5b0;
case 0x0c07f5b2u: goto P_0c07f5b2;
case 0x0c07f5b4u: goto P_0c07f5b4;
case 0x0c07f5b6u: goto P_0c07f5b6;
case 0x0c07f5b8u: goto P_0c07f5b8;
case 0x0c07f5bau: goto P_0c07f5ba;
case 0x0c07f5bcu: goto P_0c07f5bc;
case 0x0c07f5beu: goto P_0c07f5be;
case 0x0c07f5c0u: goto P_0c07f5c0;
case 0x0c07f5c2u: goto P_0c07f5c2;
case 0x0c07f5c4u: goto P_0c07f5c4;
case 0x0c07f5c6u: goto P_0c07f5c6;
case 0x0c07f5c8u: goto P_0c07f5c8;
case 0x0c07f5cau: goto P_0c07f5ca;
case 0x0c07f5ccu: goto P_0c07f5cc;
case 0x0c07f5ceu: goto P_0c07f5ce;
case 0x0c07f5d0u: goto P_0c07f5d0;
case 0x0c07f5d2u: goto P_0c07f5d2;
case 0x0c07f5d4u: goto P_0c07f5d4;
case 0x0c07f5d6u: goto P_0c07f5d6;
case 0x0c07f5d8u: goto P_0c07f5d8;
case 0x0c07f5dau: goto P_0c07f5da;
case 0x0c07f5dcu: goto P_0c07f5dc;
case 0x0c07f5deu: goto P_0c07f5de;
case 0x0c07f5e0u: goto P_0c07f5e0;
case 0x0c07f5e2u: goto P_0c07f5e2;
case 0x0c07f5e4u: goto P_0c07f5e4;
case 0x0c07f5e6u: goto P_0c07f5e6;
case 0x0c07f5f8u: goto P_0c07f5f8;
case 0x0c07f5fau: goto P_0c07f5fa;
case 0x0c07f5fcu: goto P_0c07f5fc;
case 0x0c07f5feu: goto P_0c07f5fe;
case 0x0c07f600u: goto P_0c07f600;
case 0x0c07f602u: goto P_0c07f602;
case 0x0c07f604u: goto P_0c07f604;
case 0x0c07f606u: goto P_0c07f606;
case 0x0c07f608u: goto P_0c07f608;
case 0x0c07f60au: goto P_0c07f60a;
case 0x0c07f60cu: goto P_0c07f60c;
case 0x0c07f60eu: goto P_0c07f60e;
case 0x0c07f610u: goto P_0c07f610;
case 0x0c07f612u: goto P_0c07f612;
case 0x0c07f614u: goto P_0c07f614;
case 0x0c07f616u: goto P_0c07f616;
case 0x0c07f618u: goto P_0c07f618;
case 0x0c07f61au: goto P_0c07f61a;
case 0x0c07f61cu: goto P_0c07f61c;
case 0x0c07f61eu: goto P_0c07f61e;
case 0x0c07f620u: goto P_0c07f620;
case 0x0c07f622u: goto P_0c07f622;
case 0x0c07f624u: goto P_0c07f624;
case 0x0c07f626u: goto P_0c07f626;
case 0x0c07f628u: goto P_0c07f628;
case 0x0c07f62au: goto P_0c07f62a;
case 0x0c07f62cu: goto P_0c07f62c;
case 0x0c07f62eu: goto P_0c07f62e;
case 0x0c07f630u: goto P_0c07f630;
case 0x0c07f632u: goto P_0c07f632;
case 0x0c07f634u: goto P_0c07f634;
case 0x0c07f636u: goto P_0c07f636;
case 0x0c07f638u: goto P_0c07f638;
case 0x0c07f63au: goto P_0c07f63a;
case 0x0c07f63cu: goto P_0c07f63c;
case 0x0c07f63eu: goto P_0c07f63e;
case 0x0c07f640u: goto P_0c07f640;
case 0x0c07f642u: goto P_0c07f642;
case 0x0c07f644u: goto P_0c07f644;
case 0x0c07f646u: goto P_0c07f646;
case 0x0c07f648u: goto P_0c07f648;
case 0x0c07f64au: goto P_0c07f64a;
case 0x0c07f64cu: goto P_0c07f64c;
case 0x0c07f64eu: goto P_0c07f64e;
case 0x0c07f650u: goto P_0c07f650;
case 0x0c07f652u: goto P_0c07f652;
case 0x0c07f654u: goto P_0c07f654;
case 0x0c07f656u: goto P_0c07f656;
case 0x0c07f658u: goto P_0c07f658;
case 0x0c07f65au: goto P_0c07f65a;
case 0x0c07f65cu: goto P_0c07f65c;
case 0x0c07f65eu: goto P_0c07f65e;
case 0x0c07f660u: goto P_0c07f660;
case 0x0c07f662u: goto P_0c07f662;
case 0x0c07f664u: goto P_0c07f664;
case 0x0c07f666u: goto P_0c07f666;
case 0x0c07f668u: goto P_0c07f668;
case 0x0c07f66au: goto P_0c07f66a;
case 0x0c07f66cu: goto P_0c07f66c;
case 0x0c07f66eu: goto P_0c07f66e;
case 0x0c07f670u: goto P_0c07f670;
case 0x0c07f672u: goto P_0c07f672;
case 0x0c07f674u: goto P_0c07f674;
case 0x0c07f676u: goto P_0c07f676;
case 0x0c07f678u: goto P_0c07f678;
case 0x0c07f67au: goto P_0c07f67a;
case 0x0c07f67cu: goto P_0c07f67c;
case 0x0c07f67eu: goto P_0c07f67e;
case 0x0c07f680u: goto P_0c07f680;
case 0x0c07f682u: goto P_0c07f682;
case 0x0c07f684u: goto P_0c07f684;
case 0x0c07f686u: goto P_0c07f686;
case 0x0c07f688u: goto P_0c07f688;
case 0x0c07f68au: goto P_0c07f68a;
case 0x0c07f68cu: goto P_0c07f68c;
case 0x0c07f68eu: goto P_0c07f68e;
case 0x0c07f690u: goto P_0c07f690;
case 0x0c07f692u: goto P_0c07f692;
case 0x0c07f694u: goto P_0c07f694;
case 0x0c07f696u: goto P_0c07f696;
case 0x0c07f698u: goto P_0c07f698;
case 0x0c07f69au: goto P_0c07f69a;
case 0x0c07f69cu: goto P_0c07f69c;
case 0x0c07f69eu: goto P_0c07f69e;
case 0x0c07f6a0u: goto P_0c07f6a0;
case 0x0c07f6a2u: goto P_0c07f6a2;
case 0x0c07f6a4u: goto P_0c07f6a4;
case 0x0c07f6a6u: goto P_0c07f6a6;
case 0x0c07f6a8u: goto P_0c07f6a8;
case 0x0c07f6aau: goto P_0c07f6aa;
case 0x0c07f6acu: goto P_0c07f6ac;
case 0x0c07f6aeu: goto P_0c07f6ae;
case 0x0c07f6b0u: goto P_0c07f6b0;
case 0x0c07f6b2u: goto P_0c07f6b2;
case 0x0c07f6b4u: goto P_0c07f6b4;
case 0x0c07f6b6u: goto P_0c07f6b6;
case 0x0c07f6b8u: goto P_0c07f6b8;
case 0x0c07f6bau: goto P_0c07f6ba;
case 0x0c07f6bcu: goto P_0c07f6bc;
case 0x0c07f6beu: goto P_0c07f6be;
case 0x0c07f6c0u: goto P_0c07f6c0;
case 0x0c07f6c2u: goto P_0c07f6c2;
case 0x0c07f6c4u: goto P_0c07f6c4;
case 0x0c07f6c6u: goto P_0c07f6c6;
case 0x0c07f6c8u: goto P_0c07f6c8;
case 0x0c07f6cau: goto P_0c07f6ca;
case 0x0c07f6ccu: goto P_0c07f6cc;
case 0x0c07f6ceu: goto P_0c07f6ce;
case 0x0c07f6d0u: goto P_0c07f6d0;
case 0x0c07f6d2u: goto P_0c07f6d2;
case 0x0c07f6d4u: goto P_0c07f6d4;
case 0x0c07f6d6u: goto P_0c07f6d6;
case 0x0c07f6d8u: goto P_0c07f6d8;
case 0x0c07f6dau: goto P_0c07f6da;
case 0x0c07f6dcu: goto P_0c07f6dc;
case 0x0c07f6deu: goto P_0c07f6de;
case 0x0c07f6e0u: goto P_0c07f6e0;
case 0x0c07f6e2u: goto P_0c07f6e2;
case 0x0c07f6e4u: goto P_0c07f6e4;
case 0x0c07f6e6u: goto P_0c07f6e6;
case 0x0c07f6e8u: goto P_0c07f6e8;
case 0x0c07f6eau: goto P_0c07f6ea;
case 0x0c07f6ecu: goto P_0c07f6ec;
case 0x0c07f6eeu: goto P_0c07f6ee;
case 0x0c07f6f0u: goto P_0c07f6f0;
case 0x0c07f6f2u: goto P_0c07f6f2;
case 0x0c07f6f4u: goto P_0c07f6f4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c072d0c: /* original 2fe6, guest PC 0x0c072d0c */
if(!s->budget--) { s->failed_pc=0x0c072d0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d0e;
P_0c072d0e: /* original 2fd6, guest PC 0x0c072d0e */
if(!s->budget--) { s->failed_pc=0x0c072d0eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d10;
P_0c072d10: /* original 2fc6, guest PC 0x0c072d10 */
if(!s->budget--) { s->failed_pc=0x0c072d10u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d12;
P_0c072d12: /* original 2fb6, guest PC 0x0c072d12 */
if(!s->budget--) { s->failed_pc=0x0c072d12u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d14;
P_0c072d14: /* original 6b63, guest PC 0x0c072d14 */
if(!s->budget--) { s->failed_pc=0x0c072d14u; return 0; }
r[11]=r[6];
goto P_0c072d16;
P_0c072d16: /* original 2fa6, guest PC 0x0c072d16 */
if(!s->budget--) { s->failed_pc=0x0c072d16u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d18;
P_0c072d18: /* original 6a43, guest PC 0x0c072d18 */
if(!s->budget--) { s->failed_pc=0x0c072d18u; return 0; }
r[10]=r[4];
goto P_0c072d1a;
P_0c072d1a: /* original 2f96, guest PC 0x0c072d1a */
if(!s->budget--) { s->failed_pc=0x0c072d1au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c072d1c;
P_0c072d1c: /* original 2f86, guest PC 0x0c072d1c */
if(!s->budget--) { s->failed_pc=0x0c072d1cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c072d1eu,s,ram);
P_0c0733d0: /* original 4f22, guest PC 0x0c0733d0 */
if(!s->budget--) { s->failed_pc=0x0c0733d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0733d2;
P_0c0733d2: /* original 7ff4, guest PC 0x0c0733d2 */
if(!s->budget--) { s->failed_pc=0x0c0733d2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0733d4;
P_0c0733d4: /* original bc9a, guest PC 0x0c0733d4 */
if(!s->budget--) { s->failed_pc=0x0c0733d4u; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c0733d8u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0733d8u) { target=s->pc; goto dispatch; }
goto P_0c0733d8;
P_0c0733d6: /* original e400, guest PC 0x0c0733d6 */
if(!s->budget--) { s->failed_pc=0x0c0733d6u; return 0; }
r[4]=0x00000000u;
goto P_0c0733d8;
P_0c0733d8: /* original 65e3, guest PC 0x0c0733d8 */
if(!s->budget--) { s->failed_pc=0x0c0733d8u; return 0; }
r[5]=r[14];
goto P_0c0733da;
P_0c0733da: /* original 7518, guest PC 0x0c0733da */
if(!s->budget--) { s->failed_pc=0x0c0733dau; return 0; }
r[5]+=0x00000018u;
goto P_0c0733dc;
P_0c0733dc: /* original e708, guest PC 0x0c0733dc */
if(!s->budget--) { s->failed_pc=0x0c0733dcu; return 0; }
r[7]=0x00000008u;
goto P_0c0733de;
P_0c0733de: /* original e625, guest PC 0x0c0733de */
if(!s->budget--) { s->failed_pc=0x0c0733deu; return 0; }
r[6]=0x00000025u;
goto P_0c0733e0;
P_0c0733e0: /* original bc94, guest PC 0x0c0733e0 */
if(!s->budget--) { s->failed_pc=0x0c0733e0u; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c0733e4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0733e4u) { target=s->pc; goto dispatch; }
goto P_0c0733e4;
P_0c0733e2: /* original e401, guest PC 0x0c0733e2 */
if(!s->budget--) { s->failed_pc=0x0c0733e2u; return 0; }
r[4]=0x00000001u;
goto P_0c0733e4;
P_0c0733e4: /* original 65e3, guest PC 0x0c0733e4 */
if(!s->budget--) { s->failed_pc=0x0c0733e4u; return 0; }
r[5]=r[14];
goto P_0c0733e6;
P_0c0733e6: /* original 751a, guest PC 0x0c0733e6 */
if(!s->budget--) { s->failed_pc=0x0c0733e6u; return 0; }
r[5]+=0x0000001au;
goto P_0c0733e8;
P_0c0733e8: /* original e709, guest PC 0x0c0733e8 */
if(!s->budget--) { s->failed_pc=0x0c0733e8u; return 0; }
r[7]=0x00000009u;
goto P_0c0733ea;
P_0c0733ea: /* original e625, guest PC 0x0c0733ea */
if(!s->budget--) { s->failed_pc=0x0c0733eau; return 0; }
r[6]=0x00000025u;
goto P_0c0733ec;
P_0c0733ec: /* original bc8e, guest PC 0x0c0733ec */
if(!s->budget--) { s->failed_pc=0x0c0733ecu; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c0733f0u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0733f0u) { target=s->pc; goto dispatch; }
goto P_0c0733f0;
P_0c0733ee: /* original e401, guest PC 0x0c0733ee */
if(!s->budget--) { s->failed_pc=0x0c0733eeu; return 0; }
r[4]=0x00000001u;
goto P_0c0733f0;
P_0c0733f0: /* original 65e3, guest PC 0x0c0733f0 */
if(!s->budget--) { s->failed_pc=0x0c0733f0u; return 0; }
r[5]=r[14];
goto P_0c0733f2;
P_0c0733f2: /* original 7519, guest PC 0x0c0733f2 */
if(!s->budget--) { s->failed_pc=0x0c0733f2u; return 0; }
r[5]+=0x00000019u;
goto P_0c0733f4;
P_0c0733f4: /* original e70a, guest PC 0x0c0733f4 */
if(!s->budget--) { s->failed_pc=0x0c0733f4u; return 0; }
r[7]=0x0000000au;
goto P_0c0733f6;
P_0c0733f6: /* original e625, guest PC 0x0c0733f6 */
if(!s->budget--) { s->failed_pc=0x0c0733f6u; return 0; }
r[6]=0x00000025u;
goto P_0c0733f8;
P_0c0733f8: /* original bc88, guest PC 0x0c0733f8 */
if(!s->budget--) { s->failed_pc=0x0c0733f8u; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c0733fcu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0733fcu) { target=s->pc; goto dispatch; }
goto P_0c0733fc;
P_0c0733fa: /* original e401, guest PC 0x0c0733fa */
if(!s->budget--) { s->failed_pc=0x0c0733fau; return 0; }
r[4]=0x00000001u;
goto P_0c0733fc;
P_0c0733fc: /* original 65e3, guest PC 0x0c0733fc */
if(!s->budget--) { s->failed_pc=0x0c0733fcu; return 0; }
r[5]=r[14];
goto P_0c0733fe;
P_0c0733fe: /* original 751b, guest PC 0x0c0733fe */
if(!s->budget--) { s->failed_pc=0x0c0733feu; return 0; }
r[5]+=0x0000001bu;
goto P_0c073400;
P_0c073400: /* original e70b, guest PC 0x0c073400 */
if(!s->budget--) { s->failed_pc=0x0c073400u; return 0; }
r[7]=0x0000000bu;
goto P_0c073402;
P_0c073402: /* original e625, guest PC 0x0c073402 */
if(!s->budget--) { s->failed_pc=0x0c073402u; return 0; }
r[6]=0x00000025u;
goto P_0c073404;
P_0c073404: /* original bc82, guest PC 0x0c073404 */
if(!s->budget--) { s->failed_pc=0x0c073404u; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c073408u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073408u) { target=s->pc; goto dispatch; }
goto P_0c073408;
P_0c073406: /* original e401, guest PC 0x0c073406 */
if(!s->budget--) { s->failed_pc=0x0c073406u; return 0; }
r[4]=0x00000001u;
goto P_0c073408;
P_0c073408: /* original 65e3, guest PC 0x0c073408 */
if(!s->budget--) { s->failed_pc=0x0c073408u; return 0; }
r[5]=r[14];
goto P_0c07340a;
P_0c07340a: /* original 751b, guest PC 0x0c07340a */
if(!s->budget--) { s->failed_pc=0x0c07340au; return 0; }
r[5]+=0x0000001bu;
goto P_0c07340c;
P_0c07340c: /* original e70b, guest PC 0x0c07340c */
if(!s->budget--) { s->failed_pc=0x0c07340cu; return 0; }
r[7]=0x0000000bu;
goto P_0c07340e;
P_0c07340e: /* original e625, guest PC 0x0c07340e */
if(!s->budget--) { s->failed_pc=0x0c07340eu; return 0; }
r[6]=0x00000025u;
goto P_0c073410;
P_0c073410: /* original bc7c, guest PC 0x0c073410 */
if(!s->budget--) { s->failed_pc=0x0c073410u; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c073414u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073414u) { target=s->pc; goto dispatch; }
goto P_0c073414;
P_0c073412: /* original e401, guest PC 0x0c073412 */
if(!s->budget--) { s->failed_pc=0x0c073412u; return 0; }
r[4]=0x00000001u;
goto P_0c073414;
P_0c073414: /* original d33a, guest PC 0x0c073414 */
if(!s->budget--) { s->failed_pc=0x0c073414u; return 0; }
r[3]=read(ram,0x0c073500u,4);
goto P_0c073416;
P_0c073416: /* original 64e3, guest PC 0x0c073416 */
if(!s->budget--) { s->failed_pc=0x0c073416u; return 0; }
r[4]=r[14];
goto P_0c073418;
P_0c073418: /* original 430b, guest PC 0x0c073418 */
if(!s->budget--) { s->failed_pc=0x0c073418u; return 0; }
target=r[3];
r[16]=code_base|0x0c07341cu;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07341cu) { target=s->pc; goto dispatch; }
goto P_0c07341c;
P_0c07341a: /* original 741c, guest PC 0x0c07341a */
if(!s->budget--) { s->failed_pc=0x0c07341au; return 0; }
r[4]+=0x0000001cu;
goto P_0c07341c;
P_0c07341c: /* original 640c, guest PC 0x0c07341c */
if(!s->budget--) { s->failed_pc=0x0c07341cu; return 0; }
r[4]=r[0]&255u;
goto P_0c07341e;
P_0c07341e: /* original dd39, guest PC 0x0c07341e */
if(!s->budget--) { s->failed_pc=0x0c07341eu; return 0; }
r[13]=read(ram,0x0c073504u,4);
goto P_0c073420;
P_0c073420: /* original 6043, guest PC 0x0c073420 */
if(!s->budget--) { s->failed_pc=0x0c073420u; return 0; }
r[0]=r[4];
goto P_0c073422;
P_0c073422: /* original 8801, guest PC 0x0c073422 */
if(!s->budget--) { s->failed_pc=0x0c073422u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c073424;
P_0c073424: /* original 894b, guest PC 0x0c073424 */
if(!s->budget--) { s->failed_pc=0x0c073424u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0734be; }
goto P_0c073426;
P_0c073426: /* original 65e3, guest PC 0x0c073426 */
if(!s->budget--) { s->failed_pc=0x0c073426u; return 0; }
r[5]=r[14];
goto P_0c073428;
P_0c073428: /* original 751d, guest PC 0x0c073428 */
if(!s->budget--) { s->failed_pc=0x0c073428u; return 0; }
r[5]+=0x0000001du;
goto P_0c07342a;
P_0c07342a: /* original e70d, guest PC 0x0c07342a */
if(!s->budget--) { s->failed_pc=0x0c07342au; return 0; }
r[7]=0x0000000du;
goto P_0c07342c;
P_0c07342c: /* original e623, guest PC 0x0c07342c */
if(!s->budget--) { s->failed_pc=0x0c07342cu; return 0; }
r[6]=0x00000023u;
goto P_0c07342e;
P_0c07342e: /* original bc6d, guest PC 0x0c07342e */
if(!s->budget--) { s->failed_pc=0x0c07342eu; return 0; }
target=0x0c072d0cu; r[16]=code_base|0x0c073432u;
r[4]=0x00000005u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073432u) { target=s->pc; goto dispatch; }
goto P_0c073432;
P_0c073430: /* original e405, guest PC 0x0c073430 */
if(!s->budget--) { s->failed_pc=0x0c073430u; return 0; }
r[4]=0x00000005u;
goto P_0c073432;
P_0c073432: /* original d333, guest PC 0x0c073432 */
if(!s->budget--) { s->failed_pc=0x0c073432u; return 0; }
r[3]=read(ram,0x0c073500u,4);
goto P_0c073434;
P_0c073434: /* original 64e3, guest PC 0x0c073434 */
if(!s->budget--) { s->failed_pc=0x0c073434u; return 0; }
r[4]=r[14];
goto P_0c073436;
P_0c073436: /* original 430b, guest PC 0x0c073436 */
if(!s->budget--) { s->failed_pc=0x0c073436u; return 0; }
target=r[3];
r[16]=code_base|0x0c07343au;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07343au) { target=s->pc; goto dispatch; }
goto P_0c07343a;
P_0c073438: /* original 741d, guest PC 0x0c073438 */
if(!s->budget--) { s->failed_pc=0x0c073438u; return 0; }
r[4]+=0x0000001du;
goto P_0c07343a;
P_0c07343a: /* original 640c, guest PC 0x0c07343a */
if(!s->budget--) { s->failed_pc=0x0c07343au; return 0; }
r[4]=r[0]&255u;
goto P_0c07343c;
P_0c07343c: /* original d832, guest PC 0x0c07343c */
if(!s->budget--) { s->failed_pc=0x0c07343cu; return 0; }
r[8]=read(ram,0x0c073508u,4);
goto P_0c07343e;
P_0c07343e: /* original 74ff, guest PC 0x0c07343e */
if(!s->budget--) { s->failed_pc=0x0c07343eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c073440;
P_0c073440: /* original 6343, guest PC 0x0c073440 */
if(!s->budget--) { s->failed_pc=0x0c073440u; return 0; }
r[3]=r[4];
goto P_0c073442;
P_0c073442: /* original 4408, guest PC 0x0c073442 */
if(!s->budget--) { s->failed_pc=0x0c073442u; return 0; }
r[4]<<=2;
goto P_0c073444;
P_0c073444: /* original 343c, guest PC 0x0c073444 */
if(!s->budget--) { s->failed_pc=0x0c073444u; return 0; }
r[4]+=r[3];
goto P_0c073446;
P_0c073446: /* original eb46, guest PC 0x0c073446 */
if(!s->budget--) { s->failed_pc=0x0c073446u; return 0; }
r[11]=0x00000046u;
goto P_0c073448;
P_0c073448: /* original e210, guest PC 0x0c073448 */
if(!s->budget--) { s->failed_pc=0x0c073448u; return 0; }
r[2]=0x00000010u;
goto P_0c07344a;
P_0c07344a: /* original 6cb3, guest PC 0x0c07344a */
if(!s->budget--) { s->failed_pc=0x0c07344au; return 0; }
r[12]=r[11];
goto P_0c07344c;
P_0c07344c: /* original 4400, guest PC 0x0c07344c */
if(!s->budget--) { s->failed_pc=0x0c07344cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07344e;
P_0c07344e: /* original 2f22, guest PC 0x0c07344e */
if(!s->budget--) { s->failed_pc=0x0c07344eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c073450;
P_0c073450: /* original d92e, guest PC 0x0c073450 */
if(!s->budget--) { s->failed_pc=0x0c073450u; return 0; }
r[9]=read(ram,0x0c07350cu,4);
goto P_0c073452;
P_0c073452: /* original 384c, guest PC 0x0c073452 */
if(!s->budget--) { s->failed_pc=0x0c073452u; return 0; }
r[8]+=r[4];
goto P_0c073454;
P_0c073454: /* original 9a4f, guest PC 0x0c073454 */
if(!s->budget--) { s->failed_pc=0x0c073454u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0734f6u,2);
goto P_0c073456;
P_0c073456: /* original a010, guest PC 0x0c073456 */
if(!s->budget--) { s->failed_pc=0x0c073456u; return 0; }
r[12]+=0x0000003au;
goto P_0c07347a;
P_0c073458: /* original 7c3a, guest PC 0x0c073458 */
if(!s->budget--) { s->failed_pc=0x0c073458u; return 0; }
r[12]+=0x0000003au;
goto P_0c07345a;
P_0c07345a: /* original 6384, guest PC 0x0c07345a */
if(!s->budget--) { s->failed_pc=0x0c07345au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[8],1);
r[8]+=1;
r[3]=tmp;
goto P_0c07345c;
P_0c07345c: /* original 62a3, guest PC 0x0c07345c */
if(!s->budget--) { s->failed_pc=0x0c07345cu; return 0; }
r[2]=r[10];
goto P_0c07345e;
P_0c07345e: /* original 22bb, guest PC 0x0c07345e */
if(!s->budget--) { s->failed_pc=0x0c07345eu; return 0; }
r[2]|=r[11];
goto P_0c073460;
P_0c073460: /* original 633c, guest PC 0x0c073460 */
if(!s->budget--) { s->failed_pc=0x0c073460u; return 0; }
r[3]=r[3]&255u;
goto P_0c073462;
P_0c073462: /* original 6033, guest PC 0x0c073462 */
if(!s->budget--) { s->failed_pc=0x0c073462u; return 0; }
r[0]=r[3];
goto P_0c073464;
P_0c073464: /* original 4008, guest PC 0x0c073464 */
if(!s->budget--) { s->failed_pc=0x0c073464u; return 0; }
r[0]<<=2;
goto P_0c073466;
P_0c073466: /* original 1f32, guest PC 0x0c073466 */
if(!s->budget--) { s->failed_pc=0x0c073466u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c073468;
P_0c073468: /* original e601, guest PC 0x0c073468 */
if(!s->budget--) { s->failed_pc=0x0c073468u; return 0; }
r[6]=0x00000001u;
goto P_0c07346a;
P_0c07346a: /* original 1f21, guest PC 0x0c07346a */
if(!s->budget--) { s->failed_pc=0x0c07346au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07346c;
P_0c07346c: /* original 059e, guest PC 0x0c07346c */
if(!s->budget--) { s->failed_pc=0x0c07346cu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07346e;
P_0c07346e: /* original 4d0b, guest PC 0x0c07346e */
if(!s->budget--) { s->failed_pc=0x0c07346eu; return 0; }
target=r[13];
r[16]=code_base|0x0c073472u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073472u) { target=s->pc; goto dispatch; }
goto P_0c073472;
P_0c073470: /* original 6423, guest PC 0x0c073470 */
if(!s->budget--) { s->failed_pc=0x0c073470u; return 0; }
r[4]=r[2];
goto P_0c073472;
P_0c073472: /* original 63f2, guest PC 0x0c073472 */
if(!s->budget--) { s->failed_pc=0x0c073472u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c073474;
P_0c073474: /* original 3acc, guest PC 0x0c073474 */
if(!s->budget--) { s->failed_pc=0x0c073474u; return 0; }
r[10]+=r[12];
goto P_0c073476;
P_0c073476: /* original 7301, guest PC 0x0c073476 */
if(!s->budget--) { s->failed_pc=0x0c073476u; return 0; }
r[3]+=0x00000001u;
goto P_0c073478;
P_0c073478: /* original 2f32, guest PC 0x0c073478 */
if(!s->budget--) { s->failed_pc=0x0c073478u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07347a;
P_0c07347a: /* original 62f2, guest PC 0x0c07347a */
if(!s->budget--) { s->failed_pc=0x0c07347au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07347c;
P_0c07347c: /* original e315, guest PC 0x0c07347c */
if(!s->budget--) { s->failed_pc=0x0c07347cu; return 0; }
r[3]=0x00000015u;
goto P_0c07347e;
P_0c07347e: /* original 3233, guest PC 0x0c07347e */
if(!s->budget--) { s->failed_pc=0x0c07347eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c073480;
P_0c073480: /* original 8beb, guest PC 0x0c073480 */
if(!s->budget--) { s->failed_pc=0x0c073480u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07345a; }
goto P_0c073482;
P_0c073482: /* original d31f, guest PC 0x0c073482 */
if(!s->budget--) { s->failed_pc=0x0c073482u; return 0; }
r[3]=read(ram,0x0c073500u,4);
goto P_0c073484;
P_0c073484: /* original 64e3, guest PC 0x0c073484 */
if(!s->budget--) { s->failed_pc=0x0c073484u; return 0; }
r[4]=r[14];
goto P_0c073486;
P_0c073486: /* original 430b, guest PC 0x0c073486 */
if(!s->budget--) { s->failed_pc=0x0c073486u; return 0; }
target=r[3];
r[16]=code_base|0x0c07348au;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07348au) { target=s->pc; goto dispatch; }
goto P_0c07348a;
P_0c073488: /* original 7417, guest PC 0x0c073488 */
if(!s->budget--) { s->failed_pc=0x0c073488u; return 0; }
r[4]+=0x00000017u;
goto P_0c07348a;
P_0c07348a: /* original 640c, guest PC 0x0c07348a */
if(!s->budget--) { s->failed_pc=0x0c07348au; return 0; }
r[4]=r[0]&255u;
goto P_0c07348c;
P_0c07348c: /* original 6043, guest PC 0x0c07348c */
if(!s->budget--) { s->failed_pc=0x0c07348cu; return 0; }
r[0]=r[4];
goto P_0c07348e;
P_0c07348e: /* original 8801, guest PC 0x0c07348e */
if(!s->budget--) { s->failed_pc=0x0c07348eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c073490;
P_0c073490: /* original 8927, guest PC 0x0c073490 */
if(!s->budget--) { s->failed_pc=0x0c073490u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0734e2; }
goto P_0c073492;
P_0c073492: /* original 9e31, guest PC 0x0c073492 */
if(!s->budget--) { s->failed_pc=0x0c073492u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0734f8u,2);
goto P_0c073494;
P_0c073494: /* original a00e, guest PC 0x0c073494 */
if(!s->budget--) { s->failed_pc=0x0c073494u; return 0; }
r[10]=0x00000016u;
goto P_0c0734b4;
P_0c073496: /* original ea16, guest PC 0x0c073496 */
if(!s->budget--) { s->failed_pc=0x0c073496u; return 0; }
r[10]=0x00000016u;
goto P_0c073498;
P_0c073498: /* original 6384, guest PC 0x0c073498 */
if(!s->budget--) { s->failed_pc=0x0c073498u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[8],1);
r[8]+=1;
r[3]=tmp;
goto P_0c07349a;
P_0c07349a: /* original 62e3, guest PC 0x0c07349a */
if(!s->budget--) { s->failed_pc=0x0c07349au; return 0; }
r[2]=r[14];
goto P_0c07349c;
P_0c07349c: /* original 22bb, guest PC 0x0c07349c */
if(!s->budget--) { s->failed_pc=0x0c07349cu; return 0; }
r[2]|=r[11];
goto P_0c07349e;
P_0c07349e: /* original 633c, guest PC 0x0c07349e */
if(!s->budget--) { s->failed_pc=0x0c07349eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0734a0;
P_0c0734a0: /* original 6033, guest PC 0x0c0734a0 */
if(!s->budget--) { s->failed_pc=0x0c0734a0u; return 0; }
r[0]=r[3];
goto P_0c0734a2;
P_0c0734a2: /* original 4008, guest PC 0x0c0734a2 */
if(!s->budget--) { s->failed_pc=0x0c0734a2u; return 0; }
r[0]<<=2;
goto P_0c0734a4;
P_0c0734a4: /* original 1f31, guest PC 0x0c0734a4 */
if(!s->budget--) { s->failed_pc=0x0c0734a4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0734a6;
P_0c0734a6: /* original e601, guest PC 0x0c0734a6 */
if(!s->budget--) { s->failed_pc=0x0c0734a6u; return 0; }
r[6]=0x00000001u;
goto P_0c0734a8;
P_0c0734a8: /* original 2f22, guest PC 0x0c0734a8 */
if(!s->budget--) { s->failed_pc=0x0c0734a8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0734aa;
P_0c0734aa: /* original 059e, guest PC 0x0c0734aa */
if(!s->budget--) { s->failed_pc=0x0c0734aau; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0734ac;
P_0c0734ac: /* original 4d0b, guest PC 0x0c0734ac */
if(!s->budget--) { s->failed_pc=0x0c0734acu; return 0; }
target=r[13];
r[16]=code_base|0x0c0734b0u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0734b0u) { target=s->pc; goto dispatch; }
goto P_0c0734b0;
P_0c0734ae: /* original 6423, guest PC 0x0c0734ae */
if(!s->budget--) { s->failed_pc=0x0c0734aeu; return 0; }
r[4]=r[2];
goto P_0c0734b0;
P_0c0734b0: /* original 3ecc, guest PC 0x0c0734b0 */
if(!s->budget--) { s->failed_pc=0x0c0734b0u; return 0; }
r[14]+=r[12];
goto P_0c0734b2;
P_0c0734b2: /* original 7a01, guest PC 0x0c0734b2 */
if(!s->budget--) { s->failed_pc=0x0c0734b2u; return 0; }
r[10]+=0x00000001u;
goto P_0c0734b4;
P_0c0734b4: /* original e31b, guest PC 0x0c0734b4 */
if(!s->budget--) { s->failed_pc=0x0c0734b4u; return 0; }
r[3]=0x0000001bu;
goto P_0c0734b6;
P_0c0734b6: /* original 3a33, guest PC 0x0c0734b6 */
if(!s->budget--) { s->failed_pc=0x0c0734b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0734b8;
P_0c0734b8: /* original 8bee, guest PC 0x0c0734b8 */
if(!s->budget--) { s->failed_pc=0x0c0734b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073498; }
goto P_0c0734ba;
P_0c0734ba: /* original a012, guest PC 0x0c0734ba */
if(!s->budget--) { s->failed_pc=0x0c0734bau; return 0; }
goto P_0c0734e2;
P_0c0734bc: /* original 0009, guest PC 0x0c0734bc */
if(!s->budget--) { s->failed_pc=0x0c0734bcu; return 0; }
goto P_0c0734be;
P_0c0734be: /* original 941c, guest PC 0x0c0734be */
if(!s->budget--) { s->failed_pc=0x0c0734beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0734fau,2);
goto P_0c0734c0;
P_0c0734c0: /* original e601, guest PC 0x0c0734c0 */
if(!s->budget--) { s->failed_pc=0x0c0734c0u; return 0; }
r[6]=0x00000001u;
goto P_0c0734c2;
P_0c0734c2: /* original d313, guest PC 0x0c0734c2 */
if(!s->budget--) { s->failed_pc=0x0c0734c2u; return 0; }
r[3]=read(ram,0x0c073510u,4);
goto P_0c0734c4;
P_0c0734c4: /* original 4d0b, guest PC 0x0c0734c4 */
if(!s->budget--) { s->failed_pc=0x0c0734c4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0734c8u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0734c8u) { target=s->pc; goto dispatch; }
goto P_0c0734c8;
P_0c0734c6: /* original 6532, guest PC 0x0c0734c6 */
if(!s->budget--) { s->failed_pc=0x0c0734c6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0734c8;
P_0c0734c8: /* original d20d, guest PC 0x0c0734c8 */
if(!s->budget--) { s->failed_pc=0x0c0734c8u; return 0; }
r[2]=read(ram,0x0c073500u,4);
goto P_0c0734ca;
P_0c0734ca: /* original 64e3, guest PC 0x0c0734ca */
if(!s->budget--) { s->failed_pc=0x0c0734cau; return 0; }
r[4]=r[14];
goto P_0c0734cc;
P_0c0734cc: /* original 420b, guest PC 0x0c0734cc */
if(!s->budget--) { s->failed_pc=0x0c0734ccu; return 0; }
target=r[2];
r[16]=code_base|0x0c0734d0u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0734d0u) { target=s->pc; goto dispatch; }
goto P_0c0734d0;
P_0c0734ce: /* original 7417, guest PC 0x0c0734ce */
if(!s->budget--) { s->failed_pc=0x0c0734ceu; return 0; }
r[4]+=0x00000017u;
goto P_0c0734d0;
P_0c0734d0: /* original 640c, guest PC 0x0c0734d0 */
if(!s->budget--) { s->failed_pc=0x0c0734d0u; return 0; }
r[4]=r[0]&255u;
goto P_0c0734d2;
P_0c0734d2: /* original 6043, guest PC 0x0c0734d2 */
if(!s->budget--) { s->failed_pc=0x0c0734d2u; return 0; }
r[0]=r[4];
goto P_0c0734d4;
P_0c0734d4: /* original 8801, guest PC 0x0c0734d4 */
if(!s->budget--) { s->failed_pc=0x0c0734d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0734d6;
P_0c0734d6: /* original 8904, guest PC 0x0c0734d6 */
if(!s->budget--) { s->failed_pc=0x0c0734d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0734e2; }
goto P_0c0734d8;
P_0c0734d8: /* original 9410, guest PC 0x0c0734d8 */
if(!s->budget--) { s->failed_pc=0x0c0734d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0734fcu,2);
goto P_0c0734da;
P_0c0734da: /* original e601, guest PC 0x0c0734da */
if(!s->budget--) { s->failed_pc=0x0c0734dau; return 0; }
r[6]=0x00000001u;
goto P_0c0734dc;
P_0c0734dc: /* original d20c, guest PC 0x0c0734dc */
if(!s->budget--) { s->failed_pc=0x0c0734dcu; return 0; }
r[2]=read(ram,0x0c073510u,4);
goto P_0c0734de;
P_0c0734de: /* original 4d0b, guest PC 0x0c0734de */
if(!s->budget--) { s->failed_pc=0x0c0734deu; return 0; }
target=r[13];
r[16]=code_base|0x0c0734e2u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0734e2u) { target=s->pc; goto dispatch; }
goto P_0c0734e2;
P_0c0734e0: /* original 6522, guest PC 0x0c0734e0 */
if(!s->budget--) { s->failed_pc=0x0c0734e0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0734e2;
P_0c0734e2: /* original 7f0c, guest PC 0x0c0734e2 */
if(!s->budget--) { s->failed_pc=0x0c0734e2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0734e4;
P_0c0734e4: /* original 4f26, guest PC 0x0c0734e4 */
if(!s->budget--) { s->failed_pc=0x0c0734e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0734e6;
P_0c0734e6: /* original 68f6, guest PC 0x0c0734e6 */
if(!s->budget--) { s->failed_pc=0x0c0734e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0734e8;
P_0c0734e8: /* original 69f6, guest PC 0x0c0734e8 */
if(!s->budget--) { s->failed_pc=0x0c0734e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0734ea;
P_0c0734ea: /* original 6af6, guest PC 0x0c0734ea */
if(!s->budget--) { s->failed_pc=0x0c0734eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0734ec;
P_0c0734ec: /* original 6bf6, guest PC 0x0c0734ec */
if(!s->budget--) { s->failed_pc=0x0c0734ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0734ee;
P_0c0734ee: /* original 6cf6, guest PC 0x0c0734ee */
if(!s->budget--) { s->failed_pc=0x0c0734eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0734f0;
P_0c0734f0: /* original 6df6, guest PC 0x0c0734f0 */
if(!s->budget--) { s->failed_pc=0x0c0734f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0734f2;
P_0c0734f2: /* original 000b, guest PC 0x0c0734f2 */
if(!s->budget--) { s->failed_pc=0x0c0734f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0734f4: /* original 6ef6, guest PC 0x0c0734f4 */
if(!s->budget--) { s->failed_pc=0x0c0734f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0734f6u,s,ram);
P_0c07f436: /* original 4f22, guest PC 0x0c07f436 */
if(!s->budget--) { s->failed_pc=0x0c07f436u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f438;
P_0c07f438: /* original 7fdc, guest PC 0x0c07f438 */
if(!s->budget--) { s->failed_pc=0x0c07f438u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c07f43a;
P_0c07f43a: /* original 1f46, guest PC 0x0c07f43a */
if(!s->budget--) { s->failed_pc=0x0c07f43au; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c07f43c;
P_0c07f43c: /* original d347, guest PC 0x0c07f43c */
if(!s->budget--) { s->failed_pc=0x0c07f43cu; return 0; }
r[3]=read(ram,0x0c07f55cu,4);
goto P_0c07f43e;
P_0c07f43e: /* original 1f38, guest PC 0x0c07f43e */
if(!s->budget--) { s->failed_pc=0x0c07f43eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07f440;
P_0c07f440: /* original 52f6, guest PC 0x0c07f440 */
if(!s->budget--) { s->failed_pc=0x0c07f440u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07f442;
P_0c07f442: /* original 1f27, guest PC 0x0c07f442 */
if(!s->budget--) { s->failed_pc=0x0c07f442u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07f444;
P_0c07f444: /* original d446, guest PC 0x0c07f444 */
if(!s->budget--) { s->failed_pc=0x0c07f444u; return 0; }
r[4]=read(ram,0x0c07f560u,4);
goto P_0c07f446;
P_0c07f446: /* original 6343, guest PC 0x0c07f446 */
if(!s->budget--) { s->failed_pc=0x0c07f446u; return 0; }
r[3]=r[4];
goto P_0c07f448;
P_0c07f448: /* original 7358, guest PC 0x0c07f448 */
if(!s->budget--) { s->failed_pc=0x0c07f448u; return 0; }
r[3]+=0x00000058u;
goto P_0c07f44a;
P_0c07f44a: /* original 1f33, guest PC 0x0c07f44a */
if(!s->budget--) { s->failed_pc=0x0c07f44au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07f44c;
P_0c07f44c: /* original 6c43, guest PC 0x0c07f44c */
if(!s->budget--) { s->failed_pc=0x0c07f44cu; return 0; }
r[12]=r[4];
goto P_0c07f44e;
P_0c07f44e: /* original 81ca, guest PC 0x0c07f44e */
if(!s->budget--) { s->failed_pc=0x0c07f44eu; return 0; }
write(ram,r[12]+20,r[0],2);
goto P_0c07f450;
P_0c07f450: /* original 81cb, guest PC 0x0c07f450 */
if(!s->budget--) { s->failed_pc=0x0c07f450u; return 0; }
write(ram,r[12]+22,r[0],2);
goto P_0c07f452;
P_0c07f452: /* original d344, guest PC 0x0c07f452 */
if(!s->budget--) { s->failed_pc=0x0c07f452u; return 0; }
r[3]=read(ram,0x0c07f564u,4);
goto P_0c07f454;
P_0c07f454: /* original 2302, guest PC 0x0c07f454 */
if(!s->budget--) { s->failed_pc=0x0c07f454u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07f456;
P_0c07f456: /* original 56f3, guest PC 0x0c07f456 */
if(!s->budget--) { s->failed_pc=0x0c07f456u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c07f458;
P_0c07f458: /* original d243, guest PC 0x0c07f458 */
if(!s->budget--) { s->failed_pc=0x0c07f458u; return 0; }
r[2]=read(ram,0x0c07f568u,4);
goto P_0c07f45a;
P_0c07f45a: /* original 9472, guest PC 0x0c07f45a */
if(!s->budget--) { s->failed_pc=0x0c07f45au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f542u,2);
goto P_0c07f45c;
P_0c07f45c: /* original 420b, guest PC 0x0c07f45c */
if(!s->budget--) { s->failed_pc=0x0c07f45cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07f460u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f460u) { target=s->pc; goto dispatch; }
goto P_0c07f460;
P_0c07f45e: /* original 65c3, guest PC 0x0c07f45e */
if(!s->budget--) { s->failed_pc=0x0c07f45eu; return 0; }
r[5]=r[12];
goto P_0c07f460;
P_0c07f460: /* original 9070, guest PC 0x0c07f460 */
if(!s->budget--) { s->failed_pc=0x0c07f460u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f544u,2);
goto P_0c07f462;
P_0c07f462: /* original 66c3, guest PC 0x0c07f462 */
if(!s->budget--) { s->failed_pc=0x0c07f462u; return 0; }
r[6]=r[12];
goto P_0c07f464;
P_0c07f464: /* original db41, guest PC 0x0c07f464 */
if(!s->budget--) { s->failed_pc=0x0c07f464u; return 0; }
r[11]=read(ram,0x0c07f56cu,4);
goto P_0c07f466;
P_0c07f466: /* original 67e3, guest PC 0x0c07f466 */
if(!s->budget--) { s->failed_pc=0x0c07f466u; return 0; }
r[7]=r[14];
goto P_0c07f468;
P_0c07f468: /* original d441, guest PC 0x0c07f468 */
if(!s->budget--) { s->failed_pc=0x0c07f468u; return 0; }
r[4]=read(ram,0x0c07f570u,4);
goto P_0c07f46a;
P_0c07f46a: /* original 05bc, guest PC 0x0c07f46a */
if(!s->budget--) { s->failed_pc=0x0c07f46au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07f46c;
P_0c07f46c: /* original 4500, guest PC 0x0c07f46c */
if(!s->budget--) { s->failed_pc=0x0c07f46cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07f46e;
P_0c07f46e: /* original 6053, guest PC 0x0c07f46e */
if(!s->budget--) { s->failed_pc=0x0c07f46eu; return 0; }
r[0]=r[5];
goto P_0c07f470;
P_0c07f470: /* original 4000, guest PC 0x0c07f470 */
if(!s->budget--) { s->failed_pc=0x0c07f470u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f472;
P_0c07f472: /* original 034d, guest PC 0x0c07f472 */
if(!s->budget--) { s->failed_pc=0x0c07f472u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07f474;
P_0c07f474: /* original 6053, guest PC 0x0c07f474 */
if(!s->budget--) { s->failed_pc=0x0c07f474u; return 0; }
r[0]=r[5];
goto P_0c07f476;
P_0c07f476: /* original 7001, guest PC 0x0c07f476 */
if(!s->budget--) { s->failed_pc=0x0c07f476u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f478;
P_0c07f478: /* original 4000, guest PC 0x0c07f478 */
if(!s->budget--) { s->failed_pc=0x0c07f478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f47a;
P_0c07f47a: /* original 2f31, guest PC 0x0c07f47a */
if(!s->budget--) { s->failed_pc=0x0c07f47au; return 0; }
write(ram,r[15],r[3],2);
goto P_0c07f47c;
P_0c07f47c: /* original 004d, guest PC 0x0c07f47c */
if(!s->budget--) { s->failed_pc=0x0c07f47cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07f47e;
P_0c07f47e: /* original 653f, guest PC 0x0c07f47e */
if(!s->budget--) { s->failed_pc=0x0c07f47eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c07f480;
P_0c07f480: /* original 81f2, guest PC 0x0c07f480 */
if(!s->budget--) { s->failed_pc=0x0c07f480u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c07f482;
P_0c07f482: /* original 9260, guest PC 0x0c07f482 */
if(!s->budget--) { s->failed_pc=0x0c07f482u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f546u,2);
goto P_0c07f484;
P_0c07f484: /* original 1f22, guest PC 0x0c07f484 */
if(!s->budget--) { s->failed_pc=0x0c07f484u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f486;
P_0c07f486: /* original dd3b, guest PC 0x0c07f486 */
if(!s->budget--) { s->failed_pc=0x0c07f486u; return 0; }
r[13]=read(ram,0x0c07f574u,4);
goto P_0c07f488;
P_0c07f488: /* original 2fe6, guest PC 0x0c07f488 */
if(!s->budget--) { s->failed_pc=0x0c07f488u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f48a;
P_0c07f48a: /* original 4d0b, guest PC 0x0c07f48a */
if(!s->budget--) { s->failed_pc=0x0c07f48au; return 0; }
target=r[13];
r[16]=code_base|0x0c07f48eu;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f48eu) { target=s->pc; goto dispatch; }
goto P_0c07f48e;
P_0c07f48c: /* original 54f3, guest PC 0x0c07f48c */
if(!s->budget--) { s->failed_pc=0x0c07f48cu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07f48e;
P_0c07f48e: /* original 935b, guest PC 0x0c07f48e */
if(!s->budget--) { s->failed_pc=0x0c07f48eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f548u,2);
goto P_0c07f490;
P_0c07f490: /* original 67e3, guest PC 0x0c07f490 */
if(!s->budget--) { s->failed_pc=0x0c07f490u; return 0; }
r[7]=r[14];
goto P_0c07f492;
P_0c07f492: /* original 66c3, guest PC 0x0c07f492 */
if(!s->budget--) { s->failed_pc=0x0c07f492u; return 0; }
r[6]=r[12];
goto P_0c07f494;
P_0c07f494: /* original 1f31, guest PC 0x0c07f494 */
if(!s->budget--) { s->failed_pc=0x0c07f494u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f496;
P_0c07f496: /* original 2fe6, guest PC 0x0c07f496 */
if(!s->budget--) { s->failed_pc=0x0c07f496u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f498;
P_0c07f498: /* original 85f6, guest PC 0x0c07f498 */
if(!s->budget--) { s->failed_pc=0x0c07f498u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c07f49a;
P_0c07f49a: /* original 6503, guest PC 0x0c07f49a */
if(!s->budget--) { s->failed_pc=0x0c07f49au; return 0; }
r[5]=r[0];
goto P_0c07f49c;
P_0c07f49c: /* original 4d0b, guest PC 0x0c07f49c */
if(!s->budget--) { s->failed_pc=0x0c07f49cu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4a0u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f4a0u) { target=s->pc; goto dispatch; }
goto P_0c07f4a0;
P_0c07f49e: /* original 54f2, guest PC 0x0c07f49e */
if(!s->budget--) { s->failed_pc=0x0c07f49eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f4a0;
P_0c07f4a0: /* original 9053, guest PC 0x0c07f4a0 */
if(!s->budget--) { s->failed_pc=0x0c07f4a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54au,2);
goto P_0c07f4a2;
P_0c07f4a2: /* original d335, guest PC 0x0c07f4a2 */
if(!s->budget--) { s->failed_pc=0x0c07f4a2u; return 0; }
r[3]=read(ram,0x0c07f578u,4);
goto P_0c07f4a4;
P_0c07f4a4: /* original 0abc, guest PC 0x0c07f4a4 */
if(!s->budget--) { s->failed_pc=0x0c07f4a4u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c07f4a6;
P_0c07f4a6: /* original 9752, guest PC 0x0c07f4a6 */
if(!s->budget--) { s->failed_pc=0x0c07f4a6u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54eu,2);
goto P_0c07f4a8;
P_0c07f4a8: /* original 9550, guest PC 0x0c07f4a8 */
if(!s->budget--) { s->failed_pc=0x0c07f4a8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f54cu,2);
goto P_0c07f4aa;
P_0c07f4aa: /* original 66a3, guest PC 0x0c07f4aa */
if(!s->budget--) { s->failed_pc=0x0c07f4aau; return 0; }
r[6]=r[10];
goto P_0c07f4ac;
P_0c07f4ac: /* original 430b, guest PC 0x0c07f4ac */
if(!s->budget--) { s->failed_pc=0x0c07f4acu; return 0; }
target=r[3];
r[16]=code_base|0x0c07f4b0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f4b0u) { target=s->pc; goto dispatch; }
goto P_0c07f4b0;
P_0c07f4ae: /* original 64c3, guest PC 0x0c07f4ae */
if(!s->budget--) { s->failed_pc=0x0c07f4aeu; return 0; }
r[4]=r[12];
goto P_0c07f4b0;
P_0c07f4b0: /* original 60a3, guest PC 0x0c07f4b0 */
if(!s->budget--) { s->failed_pc=0x0c07f4b0u; return 0; }
r[0]=r[10];
goto P_0c07f4b2;
P_0c07f4b2: /* original e40c, guest PC 0x0c07f4b2 */
if(!s->budget--) { s->failed_pc=0x0c07f4b2u; return 0; }
r[4]=0x0000000cu;
goto P_0c07f4b4;
P_0c07f4b4: /* original 4021, guest PC 0x0c07f4b4 */
if(!s->budget--) { s->failed_pc=0x0c07f4b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c07f4b6;
P_0c07f4b6: /* original d131, guest PC 0x0c07f4b6 */
if(!s->budget--) { s->failed_pc=0x0c07f4b6u; return 0; }
r[1]=read(ram,0x0c07f57cu,4);
goto P_0c07f4b8;
P_0c07f4b8: /* original 2409, guest PC 0x0c07f4b8 */
if(!s->budget--) { s->failed_pc=0x0c07f4b8u; return 0; }
r[4]&=r[0];
goto P_0c07f4ba;
P_0c07f4ba: /* original 67e3, guest PC 0x0c07f4ba */
if(!s->budget--) { s->failed_pc=0x0c07f4bau; return 0; }
r[7]=r[14];
goto P_0c07f4bc;
P_0c07f4bc: /* original 4401, guest PC 0x0c07f4bc */
if(!s->budget--) { s->failed_pc=0x0c07f4bcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c07f4be;
P_0c07f4be: /* original 66c3, guest PC 0x0c07f4be */
if(!s->budget--) { s->failed_pc=0x0c07f4beu; return 0; }
r[6]=r[12];
goto P_0c07f4c0;
P_0c07f4c0: /* original 6043, guest PC 0x0c07f4c0 */
if(!s->budget--) { s->failed_pc=0x0c07f4c0u; return 0; }
r[0]=r[4];
goto P_0c07f4c2;
P_0c07f4c2: /* original 4000, guest PC 0x0c07f4c2 */
if(!s->budget--) { s->failed_pc=0x0c07f4c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07f4c4;
P_0c07f4c4: /* original 001d, guest PC 0x0c07f4c4 */
if(!s->budget--) { s->failed_pc=0x0c07f4c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c07f4c6;
P_0c07f4c6: /* original 81f6, guest PC 0x0c07f4c6 */
if(!s->budget--) { s->failed_pc=0x0c07f4c6u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c07f4c8;
P_0c07f4c8: /* original 9342, guest PC 0x0c07f4c8 */
if(!s->budget--) { s->failed_pc=0x0c07f4c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f550u,2);
goto P_0c07f4ca;
P_0c07f4ca: /* original 1f34, guest PC 0x0c07f4ca */
if(!s->budget--) { s->failed_pc=0x0c07f4cau; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07f4cc;
P_0c07f4cc: /* original 2fe6, guest PC 0x0c07f4cc */
if(!s->budget--) { s->failed_pc=0x0c07f4ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f4ce;
P_0c07f4ce: /* original 85f8, guest PC 0x0c07f4ce */
if(!s->budget--) { s->failed_pc=0x0c07f4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c07f4d0;
P_0c07f4d0: /* original 1f03, guest PC 0x0c07f4d0 */
if(!s->budget--) { s->failed_pc=0x0c07f4d0u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07f4d2;
P_0c07f4d2: /* original 6503, guest PC 0x0c07f4d2 */
if(!s->budget--) { s->failed_pc=0x0c07f4d2u; return 0; }
r[5]=r[0];
goto P_0c07f4d4;
P_0c07f4d4: /* original 4d0b, guest PC 0x0c07f4d4 */
if(!s->budget--) { s->failed_pc=0x0c07f4d4u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4d8u;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f4d8u) { target=s->pc; goto dispatch; }
goto P_0c07f4d8;
P_0c07f4d6: /* original 54f5, guest PC 0x0c07f4d6 */
if(!s->budget--) { s->failed_pc=0x0c07f4d6u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07f4d8;
P_0c07f4d8: /* original 933b, guest PC 0x0c07f4d8 */
if(!s->budget--) { s->failed_pc=0x0c07f4d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f552u,2);
goto P_0c07f4da;
P_0c07f4da: /* original 66c3, guest PC 0x0c07f4da */
if(!s->budget--) { s->failed_pc=0x0c07f4dau; return 0; }
r[6]=r[12];
goto P_0c07f4dc;
P_0c07f4dc: /* original 67e3, guest PC 0x0c07f4dc */
if(!s->budget--) { s->failed_pc=0x0c07f4dcu; return 0; }
r[7]=r[14];
goto P_0c07f4de;
P_0c07f4de: /* original 1f34, guest PC 0x0c07f4de */
if(!s->budget--) { s->failed_pc=0x0c07f4deu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07f4e0;
P_0c07f4e0: /* original 2fe6, guest PC 0x0c07f4e0 */
if(!s->budget--) { s->failed_pc=0x0c07f4e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f4e2;
P_0c07f4e2: /* original 55f4, guest PC 0x0c07f4e2 */
if(!s->budget--) { s->failed_pc=0x0c07f4e2u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07f4e4;
P_0c07f4e4: /* original 4d0b, guest PC 0x0c07f4e4 */
if(!s->budget--) { s->failed_pc=0x0c07f4e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f4e8u;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f4e8u) { target=s->pc; goto dispatch; }
goto P_0c07f4e8;
P_0c07f4e6: /* original 54f5, guest PC 0x0c07f4e6 */
if(!s->budget--) { s->failed_pc=0x0c07f4e6u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07f4e8;
P_0c07f4e8: /* original 9834, guest PC 0x0c07f4e8 */
if(!s->budget--) { s->failed_pc=0x0c07f4e8u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f554u,2);
goto P_0c07f4ea;
P_0c07f4ea: /* original e302, guest PC 0x0c07f4ea */
if(!s->budget--) { s->failed_pc=0x0c07f4eau; return 0; }
r[3]=0x00000002u;
goto P_0c07f4ec;
P_0c07f4ec: /* original 7f10, guest PC 0x0c07f4ec */
if(!s->budget--) { s->failed_pc=0x0c07f4ecu; return 0; }
r[15]+=0x00000010u;
goto P_0c07f4ee;
P_0c07f4ee: /* original 1f32, guest PC 0x0c07f4ee */
if(!s->budget--) { s->failed_pc=0x0c07f4eeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f4f0;
P_0c07f4f0: /* original e901, guest PC 0x0c07f4f0 */
if(!s->budget--) { s->failed_pc=0x0c07f4f0u; return 0; }
r[9]=0x00000001u;
goto P_0c07f4f2;
P_0c07f4f2: /* original e206, guest PC 0x0c07f4f2 */
if(!s->budget--) { s->failed_pc=0x0c07f4f2u; return 0; }
r[2]=0x00000006u;
goto P_0c07f4f4;
P_0c07f4f4: /* original 2f22, guest PC 0x0c07f4f4 */
if(!s->budget--) { s->failed_pc=0x0c07f4f4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07f4f6;
P_0c07f4f6: /* original 6393, guest PC 0x0c07f4f6 */
if(!s->budget--) { s->failed_pc=0x0c07f4f6u; return 0; }
r[3]=r[9];
goto P_0c07f4f8;
P_0c07f4f8: /* original 4300, guest PC 0x0c07f4f8 */
if(!s->budget--) { s->failed_pc=0x0c07f4f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07f4fa;
P_0c07f4fa: /* original 238b, guest PC 0x0c07f4fa */
if(!s->budget--) { s->failed_pc=0x0c07f4fau; return 0; }
r[3]|=r[8];
goto P_0c07f4fc;
P_0c07f4fc: /* original 66c3, guest PC 0x0c07f4fc */
if(!s->budget--) { s->failed_pc=0x0c07f4fcu; return 0; }
r[6]=r[12];
goto P_0c07f4fe;
P_0c07f4fe: /* original 1f31, guest PC 0x0c07f4fe */
if(!s->budget--) { s->failed_pc=0x0c07f4feu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f500;
P_0c07f500: /* original e700, guest PC 0x0c07f500 */
if(!s->budget--) { s->failed_pc=0x0c07f500u; return 0; }
r[7]=0x00000000u;
goto P_0c07f502;
P_0c07f502: /* original 2fe6, guest PC 0x0c07f502 */
if(!s->budget--) { s->failed_pc=0x0c07f502u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f504;
P_0c07f504: /* original 9527, guest PC 0x0c07f504 */
if(!s->budget--) { s->failed_pc=0x0c07f504u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f556u,2);
goto P_0c07f506;
P_0c07f506: /* original 4d0b, guest PC 0x0c07f506 */
if(!s->budget--) { s->failed_pc=0x0c07f506u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f50au;
r[4]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f50au) { target=s->pc; goto dispatch; }
goto P_0c07f50a;
P_0c07f508: /* original 6433, guest PC 0x0c07f508 */
if(!s->budget--) { s->failed_pc=0x0c07f508u; return 0; }
r[4]=r[3];
goto P_0c07f50a;
P_0c07f50a: /* original 7f04, guest PC 0x0c07f50a */
if(!s->budget--) { s->failed_pc=0x0c07f50au; return 0; }
r[15]+=0x00000004u;
goto P_0c07f50c;
P_0c07f50c: /* original 62f2, guest PC 0x0c07f50c */
if(!s->budget--) { s->failed_pc=0x0c07f50cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07f50e;
P_0c07f50e: /* original 72ff, guest PC 0x0c07f50e */
if(!s->budget--) { s->failed_pc=0x0c07f50eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f510;
P_0c07f510: /* original 4215, guest PC 0x0c07f510 */
if(!s->budget--) { s->failed_pc=0x0c07f510u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c07f512;
P_0c07f512: /* original 2f22, guest PC 0x0c07f512 */
if(!s->budget--) { s->failed_pc=0x0c07f512u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07f514;
P_0c07f514: /* original 8def, guest PC 0x0c07f514 */
if(!s->budget--) { s->failed_pc=0x0c07f514u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000004u;
if(cond) { goto P_0c07f4f6; }
goto P_0c07f518;
P_0c07f516: /* original 7904, guest PC 0x0c07f516 */
if(!s->budget--) { s->failed_pc=0x0c07f516u; return 0; }
r[9]+=0x00000004u;
goto P_0c07f518;
P_0c07f518: /* original 52f2, guest PC 0x0c07f518 */
if(!s->budget--) { s->failed_pc=0x0c07f518u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07f51a;
P_0c07f51a: /* original e925, guest PC 0x0c07f51a */
if(!s->budget--) { s->failed_pc=0x0c07f51au; return 0; }
r[9]=0x00000025u;
goto P_0c07f51c;
P_0c07f51c: /* original 72ff, guest PC 0x0c07f51c */
if(!s->budget--) { s->failed_pc=0x0c07f51cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f51e;
P_0c07f51e: /* original 2228, guest PC 0x0c07f51e */
if(!s->budget--) { s->failed_pc=0x0c07f51eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07f520;
P_0c07f520: /* original 8fe7, guest PC 0x0c07f520 */
if(!s->budget--) { s->failed_pc=0x0c07f520u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c07f4f2; }
goto P_0c07f524;
P_0c07f522: /* original 1f22, guest PC 0x0c07f522 */
if(!s->budget--) { s->failed_pc=0x0c07f522u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f524;
P_0c07f524: /* original 9018, guest PC 0x0c07f524 */
if(!s->budget--) { s->failed_pc=0x0c07f524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f558u,2);
goto P_0c07f526;
P_0c07f526: /* original 2aa8, guest PC 0x0c07f526 */
if(!s->budget--) { s->failed_pc=0x0c07f526u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c07f528;
P_0c07f528: /* original 00bd, guest PC 0x0c07f528 */
if(!s->budget--) { s->failed_pc=0x0c07f528u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f52a;
P_0c07f52a: /* original 81f8, guest PC 0x0c07f52a */
if(!s->budget--) { s->failed_pc=0x0c07f52au; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c07f52c;
P_0c07f52c: /* original 8d50, guest PC 0x0c07f52c */
if(!s->budget--) { s->failed_pc=0x0c07f52cu; return 0; }
cond=r[17]&1u;
r[5]=r[10];
if(cond) { goto P_0c07f5d0; }
goto P_0c07f530;
P_0c07f52e: /* original 65a3, guest PC 0x0c07f52e */
if(!s->budget--) { s->failed_pc=0x0c07f52eu; return 0; }
r[5]=r[10];
goto P_0c07f530;
P_0c07f530: /* original e405, guest PC 0x0c07f530 */
if(!s->budget--) { s->failed_pc=0x0c07f530u; return 0; }
r[4]=0x00000005u;
goto P_0c07f532;
P_0c07f532: /* original 3a47, guest PC 0x0c07f532 */
if(!s->budget--) { s->failed_pc=0x0c07f532u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[4])!=0);
goto P_0c07f534;
P_0c07f534: /* original 8b00, guest PC 0x0c07f534 */
if(!s->budget--) { s->failed_pc=0x0c07f534u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f538; }
goto P_0c07f536;
P_0c07f536: /* original 6543, guest PC 0x0c07f536 */
if(!s->budget--) { s->failed_pc=0x0c07f536u; return 0; }
r[5]=r[4];
goto P_0c07f538;
P_0c07f538: /* original e31f, guest PC 0x0c07f538 */
if(!s->budget--) { s->failed_pc=0x0c07f538u; return 0; }
r[3]=0x0000001fu;
goto P_0c07f53a;
P_0c07f53a: /* original 1f41, guest PC 0x0c07f53a */
if(!s->budget--) { s->failed_pc=0x0c07f53au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07f53c;
P_0c07f53c: /* original 1f32, guest PC 0x0c07f53c */
if(!s->budget--) { s->failed_pc=0x0c07f53cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07f53e;
P_0c07f53e: /* original a045, guest PC 0x0c07f53e */
if(!s->budget--) { s->failed_pc=0x0c07f53eu; return 0; }
r[9]=r[5];
goto P_0c07f5cc;
P_0c07f540: /* original 6953, guest PC 0x0c07f540 */
if(!s->budget--) { s->failed_pc=0x0c07f540u; return 0; }
r[9]=r[5];
return vf3_matrix_family(0x0c07f542u,s,ram);
P_0c07f580: /* original 4915, guest PC 0x0c07f580 */
if(!s->budget--) { s->failed_pc=0x0c07f580u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c07f582;
P_0c07f582: /* original 8f20, guest PC 0x0c07f582 */
if(!s->budget--) { s->failed_pc=0x0c07f582u; return 0; }
cond=r[17]&1u;
r[10]+=0xfffffffbu;
if(!cond) { goto P_0c07f5c6; }
goto P_0c07f586;
P_0c07f584: /* original 7afb, guest PC 0x0c07f584 */
if(!s->budget--) { s->failed_pc=0x0c07f584u; return 0; }
r[10]+=0xfffffffbu;
goto P_0c07f586;
P_0c07f586: /* original 932f, guest PC 0x0c07f586 */
if(!s->budget--) { s->failed_pc=0x0c07f586u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5e8u,2);
goto P_0c07f588;
P_0c07f588: /* original 2f32, guest PC 0x0c07f588 */
if(!s->budget--) { s->failed_pc=0x0c07f588u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07f58a;
P_0c07f58a: /* original 53f2, guest PC 0x0c07f58a */
if(!s->budget--) { s->failed_pc=0x0c07f58au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07f58c;
P_0c07f58c: /* original d218, guest PC 0x0c07f58c */
if(!s->budget--) { s->failed_pc=0x0c07f58cu; return 0; }
r[2]=read(ram,0x0c07f5f0u,4);
goto P_0c07f58e;
P_0c07f58e: /* original 85f8, guest PC 0x0c07f58e */
if(!s->budget--) { s->failed_pc=0x0c07f58eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c07f590;
P_0c07f590: /* original 633b, guest PC 0x0c07f590 */
if(!s->budget--) { s->failed_pc=0x0c07f590u; return 0; }
r[3]=0u-r[3];
goto P_0c07f592;
P_0c07f592: /* original 423d, guest PC 0x0c07f592 */
if(!s->budget--) { s->failed_pc=0x0c07f592u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c07f594;
P_0c07f594: /* original 2208, guest PC 0x0c07f594 */
if(!s->budget--) { s->failed_pc=0x0c07f594u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[0])==0)!=0);
goto P_0c07f596;
P_0c07f596: /* original 8901, guest PC 0x0c07f596 */
if(!s->budget--) { s->failed_pc=0x0c07f596u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f59c; }
goto P_0c07f598;
P_0c07f598: /* original 9127, guest PC 0x0c07f598 */
if(!s->budget--) { s->failed_pc=0x0c07f598u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5eau,2);
goto P_0c07f59a;
P_0c07f59a: /* original 2f12, guest PC 0x0c07f59a */
if(!s->budget--) { s->failed_pc=0x0c07f59au; return 0; }
write(ram,r[15],r[1],4);
goto P_0c07f59c;
P_0c07f59c: /* original 53f1, guest PC 0x0c07f59c */
if(!s->budget--) { s->failed_pc=0x0c07f59cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07f59e;
P_0c07f59e: /* original e201, guest PC 0x0c07f59e */
if(!s->budget--) { s->failed_pc=0x0c07f59eu; return 0; }
r[2]=0x00000001u;
goto P_0c07f5a0;
P_0c07f5a0: /* original 66c3, guest PC 0x0c07f5a0 */
if(!s->budget--) { s->failed_pc=0x0c07f5a0u; return 0; }
r[6]=r[12];
goto P_0c07f5a2;
P_0c07f5a2: /* original e700, guest PC 0x0c07f5a2 */
if(!s->budget--) { s->failed_pc=0x0c07f5a2u; return 0; }
r[7]=0x00000000u;
goto P_0c07f5a4;
P_0c07f5a4: /* original 4300, guest PC 0x0c07f5a4 */
if(!s->budget--) { s->failed_pc=0x0c07f5a4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07f5a6;
P_0c07f5a6: /* original 238b, guest PC 0x0c07f5a6 */
if(!s->budget--) { s->failed_pc=0x0c07f5a6u; return 0; }
r[3]|=r[8];
goto P_0c07f5a8;
P_0c07f5a8: /* original 1f35, guest PC 0x0c07f5a8 */
if(!s->budget--) { s->failed_pc=0x0c07f5a8u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c07f5aa;
P_0c07f5aa: /* original 2f26, guest PC 0x0c07f5aa */
if(!s->budget--) { s->failed_pc=0x0c07f5aau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5ac;
P_0c07f5ac: /* original 55f1, guest PC 0x0c07f5ac */
if(!s->budget--) { s->failed_pc=0x0c07f5acu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07f5ae;
P_0c07f5ae: /* original 4d0b, guest PC 0x0c07f5ae */
if(!s->budget--) { s->failed_pc=0x0c07f5aeu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f5b2u;
r[4]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f5b2u) { target=s->pc; goto dispatch; }
goto P_0c07f5b2;
P_0c07f5b0: /* original 6433, guest PC 0x0c07f5b0 */
if(!s->budget--) { s->failed_pc=0x0c07f5b0u; return 0; }
r[4]=r[3];
goto P_0c07f5b2;
P_0c07f5b2: /* original 7f04, guest PC 0x0c07f5b2 */
if(!s->budget--) { s->failed_pc=0x0c07f5b2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07f5b4;
P_0c07f5b4: /* original 53f1, guest PC 0x0c07f5b4 */
if(!s->budget--) { s->failed_pc=0x0c07f5b4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07f5b6;
P_0c07f5b6: /* original 79ff, guest PC 0x0c07f5b6 */
if(!s->budget--) { s->failed_pc=0x0c07f5b6u; return 0; }
r[9]+=0xffffffffu;
goto P_0c07f5b8;
P_0c07f5b8: /* original 4915, guest PC 0x0c07f5b8 */
if(!s->budget--) { s->failed_pc=0x0c07f5b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c07f5ba;
P_0c07f5ba: /* original 7304, guest PC 0x0c07f5ba */
if(!s->budget--) { s->failed_pc=0x0c07f5bau; return 0; }
r[3]+=0x00000004u;
goto P_0c07f5bc;
P_0c07f5bc: /* original 1f31, guest PC 0x0c07f5bc */
if(!s->budget--) { s->failed_pc=0x0c07f5bcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f5be;
P_0c07f5be: /* original 52f2, guest PC 0x0c07f5be */
if(!s->budget--) { s->failed_pc=0x0c07f5beu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07f5c0;
P_0c07f5c0: /* original 72ff, guest PC 0x0c07f5c0 */
if(!s->budget--) { s->failed_pc=0x0c07f5c0u; return 0; }
r[2]+=0xffffffffu;
goto P_0c07f5c2;
P_0c07f5c2: /* original 8de0, guest PC 0x0c07f5c2 */
if(!s->budget--) { s->failed_pc=0x0c07f5c2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c07f586; }
goto P_0c07f5c6;
P_0c07f5c4: /* original 1f22, guest PC 0x0c07f5c4 */
if(!s->budget--) { s->failed_pc=0x0c07f5c4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07f5c6;
P_0c07f5c6: /* original e325, guest PC 0x0c07f5c6 */
if(!s->budget--) { s->failed_pc=0x0c07f5c6u; return 0; }
r[3]=0x00000025u;
goto P_0c07f5c8;
P_0c07f5c8: /* original 69a3, guest PC 0x0c07f5c8 */
if(!s->budget--) { s->failed_pc=0x0c07f5c8u; return 0; }
r[9]=r[10];
goto P_0c07f5ca;
P_0c07f5ca: /* original 1f31, guest PC 0x0c07f5ca */
if(!s->budget--) { s->failed_pc=0x0c07f5cau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07f5cc;
P_0c07f5cc: /* original 4a15, guest PC 0x0c07f5cc */
if(!s->budget--) { s->failed_pc=0x0c07f5ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c07f5ce;
P_0c07f5ce: /* original 89d7, guest PC 0x0c07f5ce */
if(!s->budget--) { s->failed_pc=0x0c07f5ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f580; }
goto P_0c07f5d0;
P_0c07f5d0: /* original d308, guest PC 0x0c07f5d0 */
if(!s->budget--) { s->failed_pc=0x0c07f5d0u; return 0; }
r[3]=read(ram,0x0c07f5f4u,4);
goto P_0c07f5d2;
P_0c07f5d2: /* original 54f8, guest PC 0x0c07f5d2 */
if(!s->budget--) { s->failed_pc=0x0c07f5d2u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c07f5d4;
P_0c07f5d4: /* original 430b, guest PC 0x0c07f5d4 */
if(!s->budget--) { s->failed_pc=0x0c07f5d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f5d8u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f5d8u) { target=s->pc; goto dispatch; }
goto P_0c07f5d8;
P_0c07f5d6: /* original 7412, guest PC 0x0c07f5d6 */
if(!s->budget--) { s->failed_pc=0x0c07f5d6u; return 0; }
r[4]+=0x00000012u;
goto P_0c07f5d8;
P_0c07f5d8: /* original 640c, guest PC 0x0c07f5d8 */
if(!s->budget--) { s->failed_pc=0x0c07f5d8u; return 0; }
r[4]=r[0]&255u;
goto P_0c07f5da;
P_0c07f5da: /* original 2448, guest PC 0x0c07f5da */
if(!s->budget--) { s->failed_pc=0x0c07f5dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07f5dc;
P_0c07f5dc: /* original 890c, guest PC 0x0c07f5dc */
if(!s->budget--) { s->failed_pc=0x0c07f5dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07f5f8; }
goto P_0c07f5de;
P_0c07f5de: /* original e700, guest PC 0x0c07f5de */
if(!s->budget--) { s->failed_pc=0x0c07f5deu; return 0; }
r[7]=0x00000000u;
goto P_0c07f5e0;
P_0c07f5e0: /* original 2fe6, guest PC 0x0c07f5e0 */
if(!s->budget--) { s->failed_pc=0x0c07f5e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5e2;
P_0c07f5e2: /* original 9503, guest PC 0x0c07f5e2 */
if(!s->budget--) { s->failed_pc=0x0c07f5e2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f5ecu,2);
goto P_0c07f5e4;
P_0c07f5e4: /* original a00c, guest PC 0x0c07f5e4 */
if(!s->budget--) { s->failed_pc=0x0c07f5e4u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c07f600;
P_0c07f5e6: /* original 56f4, guest PC 0x0c07f5e6 */
if(!s->budget--) { s->failed_pc=0x0c07f5e6u; return 0; }
r[6]=read(ram,r[15]+16,4);
return vf3_matrix_family(0x0c07f5e8u,s,ram);
P_0c07f5f8: /* original 2fe6, guest PC 0x0c07f5f8 */
if(!s->budget--) { s->failed_pc=0x0c07f5f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f5fa;
P_0c07f5fa: /* original e700, guest PC 0x0c07f5fa */
if(!s->budget--) { s->failed_pc=0x0c07f5fau; return 0; }
r[7]=0x00000000u;
goto P_0c07f5fc;
P_0c07f5fc: /* original 56f4, guest PC 0x0c07f5fc */
if(!s->budget--) { s->failed_pc=0x0c07f5fcu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c07f5fe;
P_0c07f5fe: /* original 957a, guest PC 0x0c07f5fe */
if(!s->budget--) { s->failed_pc=0x0c07f5feu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6f6u,2);
goto P_0c07f600;
P_0c07f600: /* original 4d0b, guest PC 0x0c07f600 */
if(!s->budget--) { s->failed_pc=0x0c07f600u; return 0; }
target=r[13];
r[16]=code_base|0x0c07f604u;
r[4]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f604u) { target=s->pc; goto dispatch; }
goto P_0c07f604;
P_0c07f602: /* original 6473, guest PC 0x0c07f602 */
if(!s->budget--) { s->failed_pc=0x0c07f602u; return 0; }
r[4]=r[7];
goto P_0c07f604;
P_0c07f604: /* original 9a78, guest PC 0x0c07f604 */
if(!s->budget--) { s->failed_pc=0x0c07f604u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6f8u,2);
goto P_0c07f606;
P_0c07f606: /* original e700, guest PC 0x0c07f606 */
if(!s->budget--) { s->failed_pc=0x0c07f606u; return 0; }
r[7]=0x00000000u;
goto P_0c07f608;
P_0c07f608: /* original 2fe6, guest PC 0x0c07f608 */
if(!s->budget--) { s->failed_pc=0x0c07f608u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f60a;
P_0c07f60a: /* original 56f5, guest PC 0x0c07f60a */
if(!s->budget--) { s->failed_pc=0x0c07f60au; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c07f60c;
P_0c07f60c: /* original 9575, guest PC 0x0c07f60c */
if(!s->budget--) { s->failed_pc=0x0c07f60cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6fau,2);
goto P_0c07f60e;
P_0c07f60e: /* original 4d0b, guest PC 0x0c07f60e */
if(!s->budget--) { s->failed_pc=0x0c07f60eu; return 0; }
target=r[13];
r[16]=code_base|0x0c07f612u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f612u) { target=s->pc; goto dispatch; }
goto P_0c07f612;
P_0c07f610: /* original 64a3, guest PC 0x0c07f610 */
if(!s->budget--) { s->failed_pc=0x0c07f610u; return 0; }
r[4]=r[10];
goto P_0c07f612;
P_0c07f612: /* original 9073, guest PC 0x0c07f612 */
if(!s->budget--) { s->failed_pc=0x0c07f612u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6fcu,2);
goto P_0c07f614;
P_0c07f614: /* original 7f08, guest PC 0x0c07f614 */
if(!s->budget--) { s->failed_pc=0x0c07f614u; return 0; }
r[15]+=0x00000008u;
goto P_0c07f616;
P_0c07f616: /* original d33b, guest PC 0x0c07f616 */
if(!s->budget--) { s->failed_pc=0x0c07f616u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f618;
P_0c07f618: /* original e70a, guest PC 0x0c07f618 */
if(!s->budget--) { s->failed_pc=0x0c07f618u; return 0; }
r[7]=0x0000000au;
goto P_0c07f61a;
P_0c07f61a: /* original 05bd, guest PC 0x0c07f61a */
if(!s->budget--) { s->failed_pc=0x0c07f61au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f61c;
P_0c07f61c: /* original 7012, guest PC 0x0c07f61c */
if(!s->budget--) { s->failed_pc=0x0c07f61cu; return 0; }
r[0]+=0x00000012u;
goto P_0c07f61e;
P_0c07f61e: /* original 0cbd, guest PC 0x0c07f61e */
if(!s->budget--) { s->failed_pc=0x0c07f61eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07f620;
P_0c07f620: /* original 615f, guest PC 0x0c07f620 */
if(!s->budget--) { s->failed_pc=0x0c07f620u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f622;
P_0c07f622: /* original 430b, guest PC 0x0c07f622 */
if(!s->budget--) { s->failed_pc=0x0c07f622u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f626u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f626u) { target=s->pc; goto dispatch; }
goto P_0c07f626;
P_0c07f624: /* original 6073, guest PC 0x0c07f624 */
if(!s->budget--) { s->failed_pc=0x0c07f624u; return 0; }
r[0]=r[7];
goto P_0c07f626;
P_0c07f626: /* original 6603, guest PC 0x0c07f626 */
if(!s->budget--) { s->failed_pc=0x0c07f626u; return 0; }
r[6]=r[0];
goto P_0c07f628;
P_0c07f628: /* original 4608, guest PC 0x0c07f628 */
if(!s->budget--) { s->failed_pc=0x0c07f628u; return 0; }
r[6]<<=2;
goto P_0c07f62a;
P_0c07f62a: /* original 6303, guest PC 0x0c07f62a */
if(!s->budget--) { s->failed_pc=0x0c07f62au; return 0; }
r[3]=r[0];
goto P_0c07f62c;
P_0c07f62c: /* original 363c, guest PC 0x0c07f62c */
if(!s->budget--) { s->failed_pc=0x0c07f62cu; return 0; }
r[6]+=r[3];
goto P_0c07f62e;
P_0c07f62e: /* original 6d53, guest PC 0x0c07f62e */
if(!s->budget--) { s->failed_pc=0x0c07f62eu; return 0; }
r[13]=r[5];
goto P_0c07f630;
P_0c07f630: /* original d334, guest PC 0x0c07f630 */
if(!s->budget--) { s->failed_pc=0x0c07f630u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f632;
P_0c07f632: /* original 6403, guest PC 0x0c07f632 */
if(!s->budget--) { s->failed_pc=0x0c07f632u; return 0; }
r[4]=r[0];
goto P_0c07f634;
P_0c07f634: /* original 4600, guest PC 0x0c07f634 */
if(!s->budget--) { s->failed_pc=0x0c07f634u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07f636;
P_0c07f636: /* original 614f, guest PC 0x0c07f636 */
if(!s->budget--) { s->failed_pc=0x0c07f636u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c07f638;
P_0c07f638: /* original 3d68, guest PC 0x0c07f638 */
if(!s->budget--) { s->failed_pc=0x0c07f638u; return 0; }
r[13]-=r[6];
goto P_0c07f63a;
P_0c07f63a: /* original 430b, guest PC 0x0c07f63a */
if(!s->budget--) { s->failed_pc=0x0c07f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c07f63eu;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f63eu) { target=s->pc; goto dispatch; }
goto P_0c07f63e;
P_0c07f63c: /* original 6073, guest PC 0x0c07f63c */
if(!s->budget--) { s->failed_pc=0x0c07f63cu; return 0; }
r[0]=r[7];
goto P_0c07f63e;
P_0c07f63e: /* original 6603, guest PC 0x0c07f63e */
if(!s->budget--) { s->failed_pc=0x0c07f63eu; return 0; }
r[6]=r[0];
goto P_0c07f640;
P_0c07f640: /* original 4608, guest PC 0x0c07f640 */
if(!s->budget--) { s->failed_pc=0x0c07f640u; return 0; }
r[6]<<=2;
goto P_0c07f642;
P_0c07f642: /* original 6303, guest PC 0x0c07f642 */
if(!s->budget--) { s->failed_pc=0x0c07f642u; return 0; }
r[3]=r[0];
goto P_0c07f644;
P_0c07f644: /* original 363c, guest PC 0x0c07f644 */
if(!s->budget--) { s->failed_pc=0x0c07f644u; return 0; }
r[6]+=r[3];
goto P_0c07f646;
P_0c07f646: /* original d32f, guest PC 0x0c07f646 */
if(!s->budget--) { s->failed_pc=0x0c07f646u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f648;
P_0c07f648: /* original 4600, guest PC 0x0c07f648 */
if(!s->budget--) { s->failed_pc=0x0c07f648u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07f64a;
P_0c07f64a: /* original 6503, guest PC 0x0c07f64a */
if(!s->budget--) { s->failed_pc=0x0c07f64au; return 0; }
r[5]=r[0];
goto P_0c07f64c;
P_0c07f64c: /* original 615f, guest PC 0x0c07f64c */
if(!s->budget--) { s->failed_pc=0x0c07f64cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f64e;
P_0c07f64e: /* original 3468, guest PC 0x0c07f64e */
if(!s->budget--) { s->failed_pc=0x0c07f64eu; return 0; }
r[4]-=r[6];
goto P_0c07f650;
P_0c07f650: /* original 430b, guest PC 0x0c07f650 */
if(!s->budget--) { s->failed_pc=0x0c07f650u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f654u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f654u) { target=s->pc; goto dispatch; }
goto P_0c07f654;
P_0c07f652: /* original 6073, guest PC 0x0c07f652 */
if(!s->budget--) { s->failed_pc=0x0c07f652u; return 0; }
r[0]=r[7];
goto P_0c07f654;
P_0c07f654: /* original 6203, guest PC 0x0c07f654 */
if(!s->budget--) { s->failed_pc=0x0c07f654u; return 0; }
r[2]=r[0];
goto P_0c07f656;
P_0c07f656: /* original 4208, guest PC 0x0c07f656 */
if(!s->budget--) { s->failed_pc=0x0c07f656u; return 0; }
r[2]<<=2;
goto P_0c07f658;
P_0c07f658: /* original 6303, guest PC 0x0c07f658 */
if(!s->budget--) { s->failed_pc=0x0c07f658u; return 0; }
r[3]=r[0];
goto P_0c07f65a;
P_0c07f65a: /* original 323c, guest PC 0x0c07f65a */
if(!s->budget--) { s->failed_pc=0x0c07f65au; return 0; }
r[2]+=r[3];
goto P_0c07f65c;
P_0c07f65c: /* original 4200, guest PC 0x0c07f65c */
if(!s->budget--) { s->failed_pc=0x0c07f65cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07f65e;
P_0c07f65e: /* original 6603, guest PC 0x0c07f65e */
if(!s->budget--) { s->failed_pc=0x0c07f65eu; return 0; }
r[6]=r[0];
goto P_0c07f660;
P_0c07f660: /* original 61cf, guest PC 0x0c07f660 */
if(!s->budget--) { s->failed_pc=0x0c07f660u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c07f662;
P_0c07f662: /* original 2f21, guest PC 0x0c07f662 */
if(!s->budget--) { s->failed_pc=0x0c07f662u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c07f664;
P_0c07f664: /* original d327, guest PC 0x0c07f664 */
if(!s->budget--) { s->failed_pc=0x0c07f664u; return 0; }
r[3]=read(ram,0x0c07f704u,4);
goto P_0c07f666;
P_0c07f666: /* original 3528, guest PC 0x0c07f666 */
if(!s->budget--) { s->failed_pc=0x0c07f666u; return 0; }
r[5]-=r[2];
goto P_0c07f668;
P_0c07f668: /* original 430b, guest PC 0x0c07f668 */
if(!s->budget--) { s->failed_pc=0x0c07f668u; return 0; }
target=r[3];
r[16]=code_base|0x0c07f66cu;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f66cu) { target=s->pc; goto dispatch; }
goto P_0c07f66c;
P_0c07f66a: /* original 6073, guest PC 0x0c07f66a */
if(!s->budget--) { s->failed_pc=0x0c07f66au; return 0; }
r[0]=r[7];
goto P_0c07f66c;
P_0c07f66c: /* original 6103, guest PC 0x0c07f66c */
if(!s->budget--) { s->failed_pc=0x0c07f66cu; return 0; }
r[1]=r[0];
goto P_0c07f66e;
P_0c07f66e: /* original 4108, guest PC 0x0c07f66e */
if(!s->budget--) { s->failed_pc=0x0c07f66eu; return 0; }
r[1]<<=2;
goto P_0c07f670;
P_0c07f670: /* original 6303, guest PC 0x0c07f670 */
if(!s->budget--) { s->failed_pc=0x0c07f670u; return 0; }
r[3]=r[0];
goto P_0c07f672;
P_0c07f672: /* original 313c, guest PC 0x0c07f672 */
if(!s->budget--) { s->failed_pc=0x0c07f672u; return 0; }
r[1]+=r[3];
goto P_0c07f674;
P_0c07f674: /* original 4100, guest PC 0x0c07f674 */
if(!s->budget--) { s->failed_pc=0x0c07f674u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07f676;
P_0c07f676: /* original 6703, guest PC 0x0c07f676 */
if(!s->budget--) { s->failed_pc=0x0c07f676u; return 0; }
r[7]=r[0];
goto P_0c07f678;
P_0c07f678: /* original 636f, guest PC 0x0c07f678 */
if(!s->budget--) { s->failed_pc=0x0c07f678u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07f67a;
P_0c07f67a: /* original 3c18, guest PC 0x0c07f67a */
if(!s->budget--) { s->failed_pc=0x0c07f67au; return 0; }
r[12]-=r[1];
goto P_0c07f67c;
P_0c07f67c: /* original 2338, guest PC 0x0c07f67c */
if(!s->budget--) { s->failed_pc=0x0c07f67cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f67e;
P_0c07f67e: /* original 2fc1, guest PC 0x0c07f67e */
if(!s->budget--) { s->failed_pc=0x0c07f67eu; return 0; }
write(ram,r[15],r[12],2);
goto P_0c07f680;
P_0c07f680: /* original 8b11, guest PC 0x0c07f680 */
if(!s->budget--) { s->failed_pc=0x0c07f680u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f682;
P_0c07f682: /* original 635f, guest PC 0x0c07f682 */
if(!s->budget--) { s->failed_pc=0x0c07f682u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07f684;
P_0c07f684: /* original 9c3b, guest PC 0x0c07f684 */
if(!s->budget--) { s->failed_pc=0x0c07f684u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f6feu,2);
goto P_0c07f686;
P_0c07f686: /* original 2338, guest PC 0x0c07f686 */
if(!s->budget--) { s->failed_pc=0x0c07f686u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f688;
P_0c07f688: /* original 8f0d, guest PC 0x0c07f688 */
if(!s->budget--) { s->failed_pc=0x0c07f688u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f68c;
P_0c07f68a: /* original 66c3, guest PC 0x0c07f68a */
if(!s->budget--) { s->failed_pc=0x0c07f68au; return 0; }
r[6]=r[12];
goto P_0c07f68c;
P_0c07f68c: /* original 634f, guest PC 0x0c07f68c */
if(!s->budget--) { s->failed_pc=0x0c07f68cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c07f68e;
P_0c07f68e: /* original 2338, guest PC 0x0c07f68e */
if(!s->budget--) { s->failed_pc=0x0c07f68eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f690;
P_0c07f690: /* original 8f09, guest PC 0x0c07f690 */
if(!s->budget--) { s->failed_pc=0x0c07f690u; return 0; }
cond=r[17]&1u;
r[5]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f694;
P_0c07f692: /* original 65c3, guest PC 0x0c07f692 */
if(!s->budget--) { s->failed_pc=0x0c07f692u; return 0; }
r[5]=r[12];
goto P_0c07f694;
P_0c07f694: /* original 63df, guest PC 0x0c07f694 */
if(!s->budget--) { s->failed_pc=0x0c07f694u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c07f696;
P_0c07f696: /* original 2338, guest PC 0x0c07f696 */
if(!s->budget--) { s->failed_pc=0x0c07f696u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f698;
P_0c07f698: /* original 8f05, guest PC 0x0c07f698 */
if(!s->budget--) { s->failed_pc=0x0c07f698u; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f69c;
P_0c07f69a: /* original 64c3, guest PC 0x0c07f69a */
if(!s->budget--) { s->failed_pc=0x0c07f69au; return 0; }
r[4]=r[12];
goto P_0c07f69c;
P_0c07f69c: /* original 637f, guest PC 0x0c07f69c */
if(!s->budget--) { s->failed_pc=0x0c07f69cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c07f69e;
P_0c07f69e: /* original 2338, guest PC 0x0c07f69e */
if(!s->budget--) { s->failed_pc=0x0c07f69eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07f6a0;
P_0c07f6a0: /* original 8f01, guest PC 0x0c07f6a0 */
if(!s->budget--) { s->failed_pc=0x0c07f6a0u; return 0; }
cond=r[17]&1u;
r[13]=r[12];
if(!cond) { goto P_0c07f6a6; }
goto P_0c07f6a4;
P_0c07f6a2: /* original 6dc3, guest PC 0x0c07f6a2 */
if(!s->budget--) { s->failed_pc=0x0c07f6a2u; return 0; }
r[13]=r[12];
goto P_0c07f6a4;
P_0c07f6a4: /* original 67c3, guest PC 0x0c07f6a4 */
if(!s->budget--) { s->failed_pc=0x0c07f6a4u; return 0; }
r[7]=r[12];
goto P_0c07f6a6;
P_0c07f6a6: /* original 902b, guest PC 0x0c07f6a6 */
if(!s->budget--) { s->failed_pc=0x0c07f6a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f700u,2);
goto P_0c07f6a8;
P_0c07f6a8: /* original 63f0, guest PC 0x0c07f6a8 */
if(!s->budget--) { s->failed_pc=0x0c07f6a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c07f6aa;
P_0c07f6aa: /* original 0b34, guest PC 0x0c07f6aa */
if(!s->budget--) { s->failed_pc=0x0c07f6aau; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c07f6ac;
P_0c07f6ac: /* original 7001, guest PC 0x0c07f6ac */
if(!s->budget--) { s->failed_pc=0x0c07f6acu; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6ae;
P_0c07f6ae: /* original 0b74, guest PC 0x0c07f6ae */
if(!s->budget--) { s->failed_pc=0x0c07f6aeu; return 0; }
write(ram,r[11]+r[0],r[7],1);
goto P_0c07f6b0;
P_0c07f6b0: /* original 7001, guest PC 0x0c07f6b0 */
if(!s->budget--) { s->failed_pc=0x0c07f6b0u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6b2;
P_0c07f6b2: /* original 0bd4, guest PC 0x0c07f6b2 */
if(!s->budget--) { s->failed_pc=0x0c07f6b2u; return 0; }
write(ram,r[11]+r[0],r[13],1);
goto P_0c07f6b4;
P_0c07f6b4: /* original 7001, guest PC 0x0c07f6b4 */
if(!s->budget--) { s->failed_pc=0x0c07f6b4u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6b6;
P_0c07f6b6: /* original 0b44, guest PC 0x0c07f6b6 */
if(!s->budget--) { s->failed_pc=0x0c07f6b6u; return 0; }
write(ram,r[11]+r[0],r[4],1);
goto P_0c07f6b8;
P_0c07f6b8: /* original 7001, guest PC 0x0c07f6b8 */
if(!s->budget--) { s->failed_pc=0x0c07f6b8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6ba;
P_0c07f6ba: /* original 0b54, guest PC 0x0c07f6ba */
if(!s->budget--) { s->failed_pc=0x0c07f6bau; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c07f6bc;
P_0c07f6bc: /* original 7001, guest PC 0x0c07f6bc */
if(!s->budget--) { s->failed_pc=0x0c07f6bcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6be;
P_0c07f6be: /* original 0b64, guest PC 0x0c07f6be */
if(!s->budget--) { s->failed_pc=0x0c07f6beu; return 0; }
write(ram,r[11]+r[0],r[6],1);
goto P_0c07f6c0;
P_0c07f6c0: /* original 70f9, guest PC 0x0c07f6c0 */
if(!s->budget--) { s->failed_pc=0x0c07f6c0u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c07f6c2;
P_0c07f6c2: /* original 0be4, guest PC 0x0c07f6c2 */
if(!s->budget--) { s->failed_pc=0x0c07f6c2u; return 0; }
write(ram,r[11]+r[0],r[14],1);
goto P_0c07f6c4;
P_0c07f6c4: /* original 7001, guest PC 0x0c07f6c4 */
if(!s->budget--) { s->failed_pc=0x0c07f6c4u; return 0; }
r[0]+=0x00000001u;
goto P_0c07f6c6;
P_0c07f6c6: /* original 0be4, guest PC 0x0c07f6c6 */
if(!s->budget--) { s->failed_pc=0x0c07f6c6u; return 0; }
write(ram,r[11]+r[0],r[14],1);
goto P_0c07f6c8;
P_0c07f6c8: /* original 7008, guest PC 0x0c07f6c8 */
if(!s->budget--) { s->failed_pc=0x0c07f6c8u; return 0; }
r[0]+=0x00000008u;
goto P_0c07f6ca;
P_0c07f6ca: /* original e301, guest PC 0x0c07f6ca */
if(!s->budget--) { s->failed_pc=0x0c07f6cau; return 0; }
r[3]=0x00000001u;
goto P_0c07f6cc;
P_0c07f6cc: /* original 65a3, guest PC 0x0c07f6cc */
if(!s->budget--) { s->failed_pc=0x0c07f6ccu; return 0; }
r[5]=r[10];
goto P_0c07f6ce;
P_0c07f6ce: /* original 0b34, guest PC 0x0c07f6ce */
if(!s->budget--) { s->failed_pc=0x0c07f6ceu; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c07f6d0;
P_0c07f6d0: /* original d30d, guest PC 0x0c07f6d0 */
if(!s->budget--) { s->failed_pc=0x0c07f6d0u; return 0; }
r[3]=read(ram,0x0c07f708u,4);
goto P_0c07f6d2;
P_0c07f6d2: /* original 52f7, guest PC 0x0c07f6d2 */
if(!s->budget--) { s->failed_pc=0x0c07f6d2u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07f6d4;
P_0c07f6d4: /* original 1234, guest PC 0x0c07f6d4 */
if(!s->budget--) { s->failed_pc=0x0c07f6d4u; return 0; }
write(ram,r[2]+16,r[3],4);
goto P_0c07f6d6;
P_0c07f6d6: /* original d20d, guest PC 0x0c07f6d6 */
if(!s->budget--) { s->failed_pc=0x0c07f6d6u; return 0; }
r[2]=read(ram,0x0c07f70cu,4);
goto P_0c07f6d8;
P_0c07f6d8: /* original 6120, guest PC 0x0c07f6d8 */
if(!s->budget--) { s->failed_pc=0x0c07f6d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c07f6da;
P_0c07f6da: /* original 7101, guest PC 0x0c07f6da */
if(!s->budget--) { s->failed_pc=0x0c07f6dau; return 0; }
r[1]+=0x00000001u;
goto P_0c07f6dc;
P_0c07f6dc: /* original 2210, guest PC 0x0c07f6dc */
if(!s->budget--) { s->failed_pc=0x0c07f6dcu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c07f6de;
P_0c07f6de: /* original 54f6, guest PC 0x0c07f6de */
if(!s->budget--) { s->failed_pc=0x0c07f6deu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07f6e0;
P_0c07f6e0: /* original 7f24, guest PC 0x0c07f6e0 */
if(!s->budget--) { s->failed_pc=0x0c07f6e0u; return 0; }
r[15]+=0x00000024u;
goto P_0c07f6e2;
P_0c07f6e2: /* original 4f26, guest PC 0x0c07f6e2 */
if(!s->budget--) { s->failed_pc=0x0c07f6e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f6e4;
P_0c07f6e4: /* original 68f6, guest PC 0x0c07f6e4 */
if(!s->budget--) { s->failed_pc=0x0c07f6e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07f6e6;
P_0c07f6e6: /* original 69f6, guest PC 0x0c07f6e6 */
if(!s->budget--) { s->failed_pc=0x0c07f6e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07f6e8;
P_0c07f6e8: /* original d309, guest PC 0x0c07f6e8 */
if(!s->budget--) { s->failed_pc=0x0c07f6e8u; return 0; }
r[3]=read(ram,0x0c07f710u,4);
goto P_0c07f6ea;
P_0c07f6ea: /* original 6af6, guest PC 0x0c07f6ea */
if(!s->budget--) { s->failed_pc=0x0c07f6eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07f6ec;
P_0c07f6ec: /* original 6bf6, guest PC 0x0c07f6ec */
if(!s->budget--) { s->failed_pc=0x0c07f6ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07f6ee;
P_0c07f6ee: /* original 6cf6, guest PC 0x0c07f6ee */
if(!s->budget--) { s->failed_pc=0x0c07f6eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f6f0;
P_0c07f6f0: /* original 6df6, guest PC 0x0c07f6f0 */
if(!s->budget--) { s->failed_pc=0x0c07f6f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f6f2;
P_0c07f6f2: /* original 432b, guest PC 0x0c07f6f2 */
if(!s->budget--) { s->failed_pc=0x0c07f6f2u; return 0; }
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
P_0c07f6f4: /* original 6ef6, guest PC 0x0c07f6f4 */
if(!s->budget--) { s->failed_pc=0x0c07f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07f6f6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c072d0cu,0x0c072d0eu,0x0c072d10u,0x0c072d12u,0x0c072d14u,0x0c072d16u,0x0c072d18u,0x0c072d1au,0x0c072d1cu,0x0c0733d0u,0x0c0733d2u,0x0c0733d4u,0x0c0733d6u,0x0c0733d8u,0x0c0733dau,0x0c0733dcu,
0x0c0733deu,0x0c0733e0u,0x0c0733e2u,0x0c0733e4u,0x0c0733e6u,0x0c0733e8u,0x0c0733eau,0x0c0733ecu,0x0c0733eeu,0x0c0733f0u,0x0c0733f2u,0x0c0733f4u,0x0c0733f6u,0x0c0733f8u,0x0c0733fau,0x0c0733fcu,
0x0c0733feu,0x0c073400u,0x0c073402u,0x0c073404u,0x0c073406u,0x0c073408u,0x0c07340au,0x0c07340cu,0x0c07340eu,0x0c073410u,0x0c073412u,0x0c073414u,0x0c073416u,0x0c073418u,0x0c07341au,0x0c07341cu,
0x0c07341eu,0x0c073420u,0x0c073422u,0x0c073424u,0x0c073426u,0x0c073428u,0x0c07342au,0x0c07342cu,0x0c07342eu,0x0c073430u,0x0c073432u,0x0c073434u,0x0c073436u,0x0c073438u,0x0c07343au,0x0c07343cu,
0x0c07343eu,0x0c073440u,0x0c073442u,0x0c073444u,0x0c073446u,0x0c073448u,0x0c07344au,0x0c07344cu,0x0c07344eu,0x0c073450u,0x0c073452u,0x0c073454u,0x0c073456u,0x0c073458u,0x0c07345au,0x0c07345cu,
0x0c07345eu,0x0c073460u,0x0c073462u,0x0c073464u,0x0c073466u,0x0c073468u,0x0c07346au,0x0c07346cu,0x0c07346eu,0x0c073470u,0x0c073472u,0x0c073474u,0x0c073476u,0x0c073478u,0x0c07347au,0x0c07347cu,
0x0c07347eu,0x0c073480u,0x0c073482u,0x0c073484u,0x0c073486u,0x0c073488u,0x0c07348au,0x0c07348cu,0x0c07348eu,0x0c073490u,0x0c073492u,0x0c073494u,0x0c073496u,0x0c073498u,0x0c07349au,0x0c07349cu,
0x0c07349eu,0x0c0734a0u,0x0c0734a2u,0x0c0734a4u,0x0c0734a6u,0x0c0734a8u,0x0c0734aau,0x0c0734acu,0x0c0734aeu,0x0c0734b0u,0x0c0734b2u,0x0c0734b4u,0x0c0734b6u,0x0c0734b8u,0x0c0734bau,0x0c0734bcu,
0x0c0734beu,0x0c0734c0u,0x0c0734c2u,0x0c0734c4u,0x0c0734c6u,0x0c0734c8u,0x0c0734cau,0x0c0734ccu,0x0c0734ceu,0x0c0734d0u,0x0c0734d2u,0x0c0734d4u,0x0c0734d6u,0x0c0734d8u,0x0c0734dau,0x0c0734dcu,
0x0c0734deu,0x0c0734e0u,0x0c0734e2u,0x0c0734e4u,0x0c0734e6u,0x0c0734e8u,0x0c0734eau,0x0c0734ecu,0x0c0734eeu,0x0c0734f0u,0x0c0734f2u,0x0c0734f4u,0x0c07f436u,0x0c07f438u,0x0c07f43au,0x0c07f43cu,
0x0c07f43eu,0x0c07f440u,0x0c07f442u,0x0c07f444u,0x0c07f446u,0x0c07f448u,0x0c07f44au,0x0c07f44cu,0x0c07f44eu,0x0c07f450u,0x0c07f452u,0x0c07f454u,0x0c07f456u,0x0c07f458u,0x0c07f45au,0x0c07f45cu,
0x0c07f45eu,0x0c07f460u,0x0c07f462u,0x0c07f464u,0x0c07f466u,0x0c07f468u,0x0c07f46au,0x0c07f46cu,0x0c07f46eu,0x0c07f470u,0x0c07f472u,0x0c07f474u,0x0c07f476u,0x0c07f478u,0x0c07f47au,0x0c07f47cu,
0x0c07f47eu,0x0c07f480u,0x0c07f482u,0x0c07f484u,0x0c07f486u,0x0c07f488u,0x0c07f48au,0x0c07f48cu,0x0c07f48eu,0x0c07f490u,0x0c07f492u,0x0c07f494u,0x0c07f496u,0x0c07f498u,0x0c07f49au,0x0c07f49cu,
0x0c07f49eu,0x0c07f4a0u,0x0c07f4a2u,0x0c07f4a4u,0x0c07f4a6u,0x0c07f4a8u,0x0c07f4aau,0x0c07f4acu,0x0c07f4aeu,0x0c07f4b0u,0x0c07f4b2u,0x0c07f4b4u,0x0c07f4b6u,0x0c07f4b8u,0x0c07f4bau,0x0c07f4bcu,
0x0c07f4beu,0x0c07f4c0u,0x0c07f4c2u,0x0c07f4c4u,0x0c07f4c6u,0x0c07f4c8u,0x0c07f4cau,0x0c07f4ccu,0x0c07f4ceu,0x0c07f4d0u,0x0c07f4d2u,0x0c07f4d4u,0x0c07f4d6u,0x0c07f4d8u,0x0c07f4dau,0x0c07f4dcu,
0x0c07f4deu,0x0c07f4e0u,0x0c07f4e2u,0x0c07f4e4u,0x0c07f4e6u,0x0c07f4e8u,0x0c07f4eau,0x0c07f4ecu,0x0c07f4eeu,0x0c07f4f0u,0x0c07f4f2u,0x0c07f4f4u,0x0c07f4f6u,0x0c07f4f8u,0x0c07f4fau,0x0c07f4fcu,
0x0c07f4feu,0x0c07f500u,0x0c07f502u,0x0c07f504u,0x0c07f506u,0x0c07f508u,0x0c07f50au,0x0c07f50cu,0x0c07f50eu,0x0c07f510u,0x0c07f512u,0x0c07f514u,0x0c07f516u,0x0c07f518u,0x0c07f51au,0x0c07f51cu,
0x0c07f51eu,0x0c07f520u,0x0c07f522u,0x0c07f524u,0x0c07f526u,0x0c07f528u,0x0c07f52au,0x0c07f52cu,0x0c07f52eu,0x0c07f530u,0x0c07f532u,0x0c07f534u,0x0c07f536u,0x0c07f538u,0x0c07f53au,0x0c07f53cu,
0x0c07f53eu,0x0c07f540u,0x0c07f580u,0x0c07f582u,0x0c07f584u,0x0c07f586u,0x0c07f588u,0x0c07f58au,0x0c07f58cu,0x0c07f58eu,0x0c07f590u,0x0c07f592u,0x0c07f594u,0x0c07f596u,0x0c07f598u,0x0c07f59au,
0x0c07f59cu,0x0c07f59eu,0x0c07f5a0u,0x0c07f5a2u,0x0c07f5a4u,0x0c07f5a6u,0x0c07f5a8u,0x0c07f5aau,0x0c07f5acu,0x0c07f5aeu,0x0c07f5b0u,0x0c07f5b2u,0x0c07f5b4u,0x0c07f5b6u,0x0c07f5b8u,0x0c07f5bau,
0x0c07f5bcu,0x0c07f5beu,0x0c07f5c0u,0x0c07f5c2u,0x0c07f5c4u,0x0c07f5c6u,0x0c07f5c8u,0x0c07f5cau,0x0c07f5ccu,0x0c07f5ceu,0x0c07f5d0u,0x0c07f5d2u,0x0c07f5d4u,0x0c07f5d6u,0x0c07f5d8u,0x0c07f5dau,
0x0c07f5dcu,0x0c07f5deu,0x0c07f5e0u,0x0c07f5e2u,0x0c07f5e4u,0x0c07f5e6u,0x0c07f5f8u,0x0c07f5fau,0x0c07f5fcu,0x0c07f5feu,0x0c07f600u,0x0c07f602u,0x0c07f604u,0x0c07f606u,0x0c07f608u,0x0c07f60au,
0x0c07f60cu,0x0c07f60eu,0x0c07f610u,0x0c07f612u,0x0c07f614u,0x0c07f616u,0x0c07f618u,0x0c07f61au,0x0c07f61cu,0x0c07f61eu,0x0c07f620u,0x0c07f622u,0x0c07f624u,0x0c07f626u,0x0c07f628u,0x0c07f62au,
0x0c07f62cu,0x0c07f62eu,0x0c07f630u,0x0c07f632u,0x0c07f634u,0x0c07f636u,0x0c07f638u,0x0c07f63au,0x0c07f63cu,0x0c07f63eu,0x0c07f640u,0x0c07f642u,0x0c07f644u,0x0c07f646u,0x0c07f648u,0x0c07f64au,
0x0c07f64cu,0x0c07f64eu,0x0c07f650u,0x0c07f652u,0x0c07f654u,0x0c07f656u,0x0c07f658u,0x0c07f65au,0x0c07f65cu,0x0c07f65eu,0x0c07f660u,0x0c07f662u,0x0c07f664u,0x0c07f666u,0x0c07f668u,0x0c07f66au,
0x0c07f66cu,0x0c07f66eu,0x0c07f670u,0x0c07f672u,0x0c07f674u,0x0c07f676u,0x0c07f678u,0x0c07f67au,0x0c07f67cu,0x0c07f67eu,0x0c07f680u,0x0c07f682u,0x0c07f684u,0x0c07f686u,0x0c07f688u,0x0c07f68au,
0x0c07f68cu,0x0c07f68eu,0x0c07f690u,0x0c07f692u,0x0c07f694u,0x0c07f696u,0x0c07f698u,0x0c07f69au,0x0c07f69cu,0x0c07f69eu,0x0c07f6a0u,0x0c07f6a2u,0x0c07f6a4u,0x0c07f6a6u,0x0c07f6a8u,0x0c07f6aau,
0x0c07f6acu,0x0c07f6aeu,0x0c07f6b0u,0x0c07f6b2u,0x0c07f6b4u,0x0c07f6b6u,0x0c07f6b8u,0x0c07f6bau,0x0c07f6bcu,0x0c07f6beu,0x0c07f6c0u,0x0c07f6c2u,0x0c07f6c4u,0x0c07f6c6u,0x0c07f6c8u,0x0c07f6cau,
0x0c07f6ccu,0x0c07f6ceu,0x0c07f6d0u,0x0c07f6d2u,0x0c07f6d4u,0x0c07f6d6u,0x0c07f6d8u,0x0c07f6dau,0x0c07f6dcu,0x0c07f6deu,0x0c07f6e0u,0x0c07f6e2u,0x0c07f6e4u,0x0c07f6e6u,0x0c07f6e8u,0x0c07f6eau,
0x0c07f6ecu,0x0c07f6eeu,0x0c07f6f0u,0x0c07f6f2u,0x0c07f6f4u,
};
int vf3_c90b_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
