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
int vf3_away_batch5_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04f2fcu: goto P_0c04f2fc;
case 0x0c04f2feu: goto P_0c04f2fe;
case 0x0c04f300u: goto P_0c04f300;
case 0x0c04f302u: goto P_0c04f302;
case 0x0c04f304u: goto P_0c04f304;
case 0x0c04f306u: goto P_0c04f306;
case 0x0c04f308u: goto P_0c04f308;
case 0x0c04f30au: goto P_0c04f30a;
case 0x0c04f30cu: goto P_0c04f30c;
case 0x0c04f30eu: goto P_0c04f30e;
case 0x0c04f310u: goto P_0c04f310;
case 0x0c04f312u: goto P_0c04f312;
case 0x0c04f314u: goto P_0c04f314;
case 0x0c04f316u: goto P_0c04f316;
case 0x0c04f318u: goto P_0c04f318;
case 0x0c04f31au: goto P_0c04f31a;
case 0x0c04f31cu: goto P_0c04f31c;
case 0x0c04f31eu: goto P_0c04f31e;
case 0x0c04f320u: goto P_0c04f320;
case 0x0c04f322u: goto P_0c04f322;
case 0x0c04f324u: goto P_0c04f324;
case 0x0c04f326u: goto P_0c04f326;
case 0x0c04f328u: goto P_0c04f328;
case 0x0c04f32au: goto P_0c04f32a;
case 0x0c04f32cu: goto P_0c04f32c;
case 0x0c04f32eu: goto P_0c04f32e;
case 0x0c04f330u: goto P_0c04f330;
case 0x0c04f332u: goto P_0c04f332;
case 0x0c04f334u: goto P_0c04f334;
case 0x0c04f336u: goto P_0c04f336;
case 0x0c04f338u: goto P_0c04f338;
case 0x0c04f33au: goto P_0c04f33a;
case 0x0c04f33cu: goto P_0c04f33c;
case 0x0c04f33eu: goto P_0c04f33e;
case 0x0c04f340u: goto P_0c04f340;
case 0x0c04f342u: goto P_0c04f342;
case 0x0c04f344u: goto P_0c04f344;
case 0x0c04f346u: goto P_0c04f346;
case 0x0c04f348u: goto P_0c04f348;
case 0x0c04f34au: goto P_0c04f34a;
case 0x0c04f34cu: goto P_0c04f34c;
case 0x0c04f34eu: goto P_0c04f34e;
case 0x0c04f350u: goto P_0c04f350;
case 0x0c04f352u: goto P_0c04f352;
case 0x0c04f354u: goto P_0c04f354;
case 0x0c04f356u: goto P_0c04f356;
case 0x0c04f358u: goto P_0c04f358;
case 0x0c04f35au: goto P_0c04f35a;
case 0x0c04f370u: goto P_0c04f370;
case 0x0c04f372u: goto P_0c04f372;
case 0x0c04f374u: goto P_0c04f374;
case 0x0c04f376u: goto P_0c04f376;
case 0x0c04f378u: goto P_0c04f378;
case 0x0c04f37au: goto P_0c04f37a;
case 0x0c04f37cu: goto P_0c04f37c;
case 0x0c04f37eu: goto P_0c04f37e;
case 0x0c04f380u: goto P_0c04f380;
case 0x0c04f382u: goto P_0c04f382;
case 0x0c04f384u: goto P_0c04f384;
case 0x0c04f386u: goto P_0c04f386;
case 0x0c04f388u: goto P_0c04f388;
case 0x0c04f38au: goto P_0c04f38a;
case 0x0c04f38cu: goto P_0c04f38c;
case 0x0c04f38eu: goto P_0c04f38e;
case 0x0c04f390u: goto P_0c04f390;
case 0x0c04f392u: goto P_0c04f392;
case 0x0c04f394u: goto P_0c04f394;
case 0x0c04f396u: goto P_0c04f396;
case 0x0c04f398u: goto P_0c04f398;
case 0x0c04f39au: goto P_0c04f39a;
case 0x0c04f39cu: goto P_0c04f39c;
case 0x0c04f39eu: goto P_0c04f39e;
case 0x0c04f3a0u: goto P_0c04f3a0;
case 0x0c04f3a2u: goto P_0c04f3a2;
case 0x0c04f3a4u: goto P_0c04f3a4;
case 0x0c04f3a6u: goto P_0c04f3a6;
case 0x0c04f3a8u: goto P_0c04f3a8;
case 0x0c04f3aau: goto P_0c04f3aa;
case 0x0c04f3acu: goto P_0c04f3ac;
case 0x0c04f3aeu: goto P_0c04f3ae;
case 0x0c04f3b0u: goto P_0c04f3b0;
case 0x0c04f3b2u: goto P_0c04f3b2;
case 0x0c04f3b4u: goto P_0c04f3b4;
case 0x0c04f3b6u: goto P_0c04f3b6;
case 0x0c04f3b8u: goto P_0c04f3b8;
case 0x0c04f3bau: goto P_0c04f3ba;
case 0x0c04f3bcu: goto P_0c04f3bc;
case 0x0c04f3beu: goto P_0c04f3be;
case 0x0c04f3c0u: goto P_0c04f3c0;
case 0x0c04f3c2u: goto P_0c04f3c2;
case 0x0c04f3c4u: goto P_0c04f3c4;
case 0x0c04f3c6u: goto P_0c04f3c6;
case 0x0c04f3c8u: goto P_0c04f3c8;
case 0x0c04f3cau: goto P_0c04f3ca;
case 0x0c04f3ccu: goto P_0c04f3cc;
case 0x0c04f3ceu: goto P_0c04f3ce;
case 0x0c04f3d0u: goto P_0c04f3d0;
case 0x0c04f3d2u: goto P_0c04f3d2;
case 0x0c04f3d4u: goto P_0c04f3d4;
case 0x0c04f3d6u: goto P_0c04f3d6;
case 0x0c04f3d8u: goto P_0c04f3d8;
case 0x0c04f3dau: goto P_0c04f3da;
case 0x0c04f3dcu: goto P_0c04f3dc;
case 0x0c04f3deu: goto P_0c04f3de;
case 0x0c04f3e0u: goto P_0c04f3e0;
case 0x0c04f3e2u: goto P_0c04f3e2;
case 0x0c04f3e4u: goto P_0c04f3e4;
case 0x0c04f3e6u: goto P_0c04f3e6;
case 0x0c04f3e8u: goto P_0c04f3e8;
case 0x0c04f3eau: goto P_0c04f3ea;
case 0x0c04f3ecu: goto P_0c04f3ec;
case 0x0c04f3eeu: goto P_0c04f3ee;
case 0x0c04f3f0u: goto P_0c04f3f0;
case 0x0c04f3f2u: goto P_0c04f3f2;
case 0x0c04f3f4u: goto P_0c04f3f4;
case 0x0c04f3f6u: goto P_0c04f3f6;
case 0x0c04f3f8u: goto P_0c04f3f8;
case 0x0c04f3fau: goto P_0c04f3fa;
case 0x0c04f3fcu: goto P_0c04f3fc;
case 0x0c04f3feu: goto P_0c04f3fe;
case 0x0c04f400u: goto P_0c04f400;
case 0x0c04f402u: goto P_0c04f402;
case 0x0c04f404u: goto P_0c04f404;
case 0x0c04f406u: goto P_0c04f406;
case 0x0c04f408u: goto P_0c04f408;
case 0x0c04f40au: goto P_0c04f40a;
case 0x0c04f40cu: goto P_0c04f40c;
case 0x0c04f40eu: goto P_0c04f40e;
case 0x0c04f410u: goto P_0c04f410;
case 0x0c04f412u: goto P_0c04f412;
case 0x0c04f414u: goto P_0c04f414;
case 0x0c04f416u: goto P_0c04f416;
case 0x0c04f418u: goto P_0c04f418;
case 0x0c04f41au: goto P_0c04f41a;
case 0x0c04f41cu: goto P_0c04f41c;
case 0x0c04f41eu: goto P_0c04f41e;
case 0x0c04f420u: goto P_0c04f420;
case 0x0c04f422u: goto P_0c04f422;
case 0x0c04f424u: goto P_0c04f424;
case 0x0c04f426u: goto P_0c04f426;
case 0x0c04f428u: goto P_0c04f428;
case 0x0c04f42au: goto P_0c04f42a;
case 0x0c04f42cu: goto P_0c04f42c;
case 0x0c04f42eu: goto P_0c04f42e;
case 0x0c04f430u: goto P_0c04f430;
case 0x0c04f432u: goto P_0c04f432;
case 0x0c04f434u: goto P_0c04f434;
case 0x0c04f436u: goto P_0c04f436;
case 0x0c04f438u: goto P_0c04f438;
case 0x0c04f43au: goto P_0c04f43a;
case 0x0c04f43cu: goto P_0c04f43c;
case 0x0c04f43eu: goto P_0c04f43e;
case 0x0c04f440u: goto P_0c04f440;
case 0x0c04f442u: goto P_0c04f442;
case 0x0c04f444u: goto P_0c04f444;
case 0x0c04f446u: goto P_0c04f446;
case 0x0c04f448u: goto P_0c04f448;
case 0x0c04f44au: goto P_0c04f44a;
case 0x0c04f44cu: goto P_0c04f44c;
case 0x0c04f44eu: goto P_0c04f44e;
case 0x0c04f450u: goto P_0c04f450;
case 0x0c04f452u: goto P_0c04f452;
case 0x0c04f480u: goto P_0c04f480;
case 0x0c04f482u: goto P_0c04f482;
case 0x0c04f484u: goto P_0c04f484;
case 0x0c04f486u: goto P_0c04f486;
case 0x0c04f488u: goto P_0c04f488;
case 0x0c04f48au: goto P_0c04f48a;
case 0x0c04f48cu: goto P_0c04f48c;
case 0x0c04f48eu: goto P_0c04f48e;
case 0x0c04f490u: goto P_0c04f490;
case 0x0c04f492u: goto P_0c04f492;
case 0x0c04f494u: goto P_0c04f494;
case 0x0c04f496u: goto P_0c04f496;
case 0x0c04f498u: goto P_0c04f498;
case 0x0c04f49au: goto P_0c04f49a;
case 0x0c04f49cu: goto P_0c04f49c;
case 0x0c04f49eu: goto P_0c04f49e;
case 0x0c04f4a0u: goto P_0c04f4a0;
case 0x0c04f4a2u: goto P_0c04f4a2;
case 0x0c04f4a4u: goto P_0c04f4a4;
case 0x0c04f4a6u: goto P_0c04f4a6;
case 0x0c04f4a8u: goto P_0c04f4a8;
case 0x0c04f4aau: goto P_0c04f4aa;
case 0x0c04f4acu: goto P_0c04f4ac;
case 0x0c04f4aeu: goto P_0c04f4ae;
case 0x0c04f4b0u: goto P_0c04f4b0;
case 0x0c04f4b2u: goto P_0c04f4b2;
case 0x0c04f4b4u: goto P_0c04f4b4;
case 0x0c04f4b6u: goto P_0c04f4b6;
case 0x0c04f4b8u: goto P_0c04f4b8;
case 0x0c04f4bau: goto P_0c04f4ba;
case 0x0c04f4bcu: goto P_0c04f4bc;
case 0x0c04f4beu: goto P_0c04f4be;
case 0x0c04f4c0u: goto P_0c04f4c0;
case 0x0c04f4c2u: goto P_0c04f4c2;
case 0x0c04f4c4u: goto P_0c04f4c4;
case 0x0c04f4c6u: goto P_0c04f4c6;
case 0x0c04f4c8u: goto P_0c04f4c8;
case 0x0c04f4cau: goto P_0c04f4ca;
case 0x0c04f4ccu: goto P_0c04f4cc;
case 0x0c04f4ceu: goto P_0c04f4ce;
case 0x0c04f4d0u: goto P_0c04f4d0;
case 0x0c04f4d2u: goto P_0c04f4d2;
case 0x0c04f4d4u: goto P_0c04f4d4;
case 0x0c04f4d6u: goto P_0c04f4d6;
case 0x0c04f4d8u: goto P_0c04f4d8;
case 0x0c04f4dau: goto P_0c04f4da;
case 0x0c04f4dcu: goto P_0c04f4dc;
case 0x0c04f4deu: goto P_0c04f4de;
case 0x0c04f4e0u: goto P_0c04f4e0;
case 0x0c04f4e2u: goto P_0c04f4e2;
case 0x0c04f4e4u: goto P_0c04f4e4;
case 0x0c04f4e6u: goto P_0c04f4e6;
case 0x0c04f4e8u: goto P_0c04f4e8;
case 0x0c04f4eau: goto P_0c04f4ea;
case 0x0c04f4ecu: goto P_0c04f4ec;
case 0x0c04f4eeu: goto P_0c04f4ee;
case 0x0c04f4f0u: goto P_0c04f4f0;
case 0x0c04f4f2u: goto P_0c04f4f2;
case 0x0c04f4f4u: goto P_0c04f4f4;
case 0x0c04f4f6u: goto P_0c04f4f6;
case 0x0c04f4f8u: goto P_0c04f4f8;
case 0x0c04f4fau: goto P_0c04f4fa;
case 0x0c04f4fcu: goto P_0c04f4fc;
case 0x0c04f4feu: goto P_0c04f4fe;
case 0x0c04f500u: goto P_0c04f500;
case 0x0c04f502u: goto P_0c04f502;
case 0x0c04f504u: goto P_0c04f504;
case 0x0c04f506u: goto P_0c04f506;
case 0x0c04f508u: goto P_0c04f508;
case 0x0c04f50au: goto P_0c04f50a;
case 0x0c04f50cu: goto P_0c04f50c;
case 0x0c04f50eu: goto P_0c04f50e;
case 0x0c04f510u: goto P_0c04f510;
case 0x0c04f512u: goto P_0c04f512;
case 0x0c04f514u: goto P_0c04f514;
case 0x0c04f516u: goto P_0c04f516;
case 0x0c04f518u: goto P_0c04f518;
case 0x0c04f51au: goto P_0c04f51a;
case 0x0c04f51cu: goto P_0c04f51c;
case 0x0c04f51eu: goto P_0c04f51e;
case 0x0c04f520u: goto P_0c04f520;
case 0x0c04f522u: goto P_0c04f522;
case 0x0c04f524u: goto P_0c04f524;
case 0x0c04f526u: goto P_0c04f526;
case 0x0c04f528u: goto P_0c04f528;
case 0x0c04f52au: goto P_0c04f52a;
case 0x0c04f52cu: goto P_0c04f52c;
case 0x0c04f52eu: goto P_0c04f52e;
case 0x0c04f530u: goto P_0c04f530;
case 0x0c04f532u: goto P_0c04f532;
case 0x0c04f534u: goto P_0c04f534;
case 0x0c04f536u: goto P_0c04f536;
case 0x0c04f538u: goto P_0c04f538;
case 0x0c04f53au: goto P_0c04f53a;
case 0x0c04f53cu: goto P_0c04f53c;
case 0x0c04f558u: goto P_0c04f558;
case 0x0c04f55au: goto P_0c04f55a;
case 0x0c04f55cu: goto P_0c04f55c;
case 0x0c04f55eu: goto P_0c04f55e;
case 0x0c04f560u: goto P_0c04f560;
case 0x0c04f562u: goto P_0c04f562;
case 0x0c04f564u: goto P_0c04f564;
case 0x0c04f566u: goto P_0c04f566;
case 0x0c04f568u: goto P_0c04f568;
case 0x0c04f56au: goto P_0c04f56a;
case 0x0c04f56cu: goto P_0c04f56c;
case 0x0c04f56eu: goto P_0c04f56e;
case 0x0c04f570u: goto P_0c04f570;
case 0x0c04f572u: goto P_0c04f572;
case 0x0c04f574u: goto P_0c04f574;
case 0x0c04f576u: goto P_0c04f576;
case 0x0c04f578u: goto P_0c04f578;
case 0x0c04f57au: goto P_0c04f57a;
case 0x0c04f57cu: goto P_0c04f57c;
case 0x0c04f57eu: goto P_0c04f57e;
case 0x0c04f580u: goto P_0c04f580;
case 0x0c04f582u: goto P_0c04f582;
case 0x0c04f584u: goto P_0c04f584;
case 0x0c04f586u: goto P_0c04f586;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04f2fc: /* original 2fe6, guest PC 0x0c04f2fc */
if(!s->budget--) { s->failed_pc=0x0c04f2fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f2fe;
P_0c04f2fe: /* original 2fd6, guest PC 0x0c04f2fe */
if(!s->budget--) { s->failed_pc=0x0c04f2feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f300;
P_0c04f300: /* original 2fc6, guest PC 0x0c04f300 */
if(!s->budget--) { s->failed_pc=0x0c04f300u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f302;
P_0c04f302: /* original 2fb6, guest PC 0x0c04f302 */
if(!s->budget--) { s->failed_pc=0x0c04f302u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f304;
P_0c04f304: /* original 4f22, guest PC 0x0c04f304 */
if(!s->budget--) { s->failed_pc=0x0c04f304u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f306;
P_0c04f306: /* original 4f12, guest PC 0x0c04f306 */
if(!s->budget--) { s->failed_pc=0x0c04f306u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f308;
P_0c04f308: /* original 7ffc, guest PC 0x0c04f308 */
if(!s->budget--) { s->failed_pc=0x0c04f308u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f30a;
P_0c04f30a: /* original 2f52, guest PC 0x0c04f30a */
if(!s->budget--) { s->failed_pc=0x0c04f30au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f30c;
P_0c04f30c: /* original 9c26, guest PC 0x0c04f30c */
if(!s->budget--) { s->failed_pc=0x0c04f30cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f35cu,2);
goto P_0c04f30e;
P_0c04f30e: /* original d314, guest PC 0x0c04f30e */
if(!s->budget--) { s->failed_pc=0x0c04f30eu; return 0; }
r[3]=read(ram,0x0c04f360u,4);
goto P_0c04f310;
P_0c04f310: /* original 24cf, guest PC 0x0c04f310 */
if(!s->budget--) { s->failed_pc=0x0c04f310u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04f312;
P_0c04f312: /* original db14, guest PC 0x0c04f312 */
if(!s->budget--) { s->failed_pc=0x0c04f312u; return 0; }
r[11]=read(ram,0x0c04f364u,4);
goto P_0c04f314;
P_0c04f314: /* original 0c1a, guest PC 0x0c04f314 */
if(!s->budget--) { s->failed_pc=0x0c04f314u; return 0; }
r[12]=r[19];
goto P_0c04f316;
P_0c04f316: /* original 6ccf, guest PC 0x0c04f316 */
if(!s->budget--) { s->failed_pc=0x0c04f316u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04f318;
P_0c04f318: /* original 3c3c, guest PC 0x0c04f318 */
if(!s->budget--) { s->failed_pc=0x0c04f318u; return 0; }
r[12]+=r[3];
goto P_0c04f31a;
P_0c04f31a: /* original 5eca, guest PC 0x0c04f31a */
if(!s->budget--) { s->failed_pc=0x0c04f31au; return 0; }
r[14]=read(ram,r[12]+40,4);
goto P_0c04f31c;
P_0c04f31c: /* original a011, guest PC 0x0c04f31c */
if(!s->budget--) { s->failed_pc=0x0c04f31cu; return 0; }
r[13]=0x00000000u;
goto P_0c04f342;
P_0c04f31e: /* original ed00, guest PC 0x0c04f31e */
if(!s->budget--) { s->failed_pc=0x0c04f31eu; return 0; }
r[13]=0x00000000u;
goto P_0c04f320;
P_0c04f320: /* original 64e0, guest PC 0x0c04f320 */
if(!s->budget--) { s->failed_pc=0x0c04f320u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04f322;
P_0c04f322: /* original 644c, guest PC 0x0c04f322 */
if(!s->budget--) { s->failed_pc=0x0c04f322u; return 0; }
r[4]=r[4]&255u;
goto P_0c04f324;
P_0c04f324: /* original 2448, guest PC 0x0c04f324 */
if(!s->budget--) { s->failed_pc=0x0c04f324u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f326;
P_0c04f326: /* original 890a, guest PC 0x0c04f326 */
if(!s->budget--) { s->failed_pc=0x0c04f326u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f33e; }
goto P_0c04f328;
P_0c04f328: /* original 62b2, guest PC 0x0c04f328 */
if(!s->budget--) { s->failed_pc=0x0c04f328u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c04f32a;
P_0c04f32a: /* original e502, guest PC 0x0c04f32a */
if(!s->budget--) { s->failed_pc=0x0c04f32au; return 0; }
r[5]=0x00000002u;
goto P_0c04f32c;
P_0c04f32c: /* original 5323, guest PC 0x0c04f32c */
if(!s->budget--) { s->failed_pc=0x0c04f32cu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04f32e;
P_0c04f32e: /* original 430b, guest PC 0x0c04f32e */
if(!s->budget--) { s->failed_pc=0x0c04f32eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04f332u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f332u) { target=s->pc; goto dispatch; }
goto P_0c04f332;
P_0c04f330: /* original 64e3, guest PC 0x0c04f330 */
if(!s->budget--) { s->failed_pc=0x0c04f330u; return 0; }
r[4]=r[14];
goto P_0c04f332;
P_0c04f332: /* original 62f2, guest PC 0x0c04f332 */
if(!s->budget--) { s->failed_pc=0x0c04f332u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04f334;
P_0c04f334: /* original 600d, guest PC 0x0c04f334 */
if(!s->budget--) { s->failed_pc=0x0c04f334u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f336;
P_0c04f336: /* original 3020, guest PC 0x0c04f336 */
if(!s->budget--) { s->failed_pc=0x0c04f336u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04f338;
P_0c04f338: /* original 8b01, guest PC 0x0c04f338 */
if(!s->budget--) { s->failed_pc=0x0c04f338u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f33e; }
goto P_0c04f33a;
P_0c04f33a: /* original a007, guest PC 0x0c04f33a */
if(!s->budget--) { s->failed_pc=0x0c04f33au; return 0; }
r[0]=r[14];
goto P_0c04f34c;
P_0c04f33c: /* original 60e3, guest PC 0x0c04f33c */
if(!s->budget--) { s->failed_pc=0x0c04f33cu; return 0; }
r[0]=r[14];
goto P_0c04f33e;
P_0c04f33e: /* original 7e20, guest PC 0x0c04f33e */
if(!s->budget--) { s->failed_pc=0x0c04f33eu; return 0; }
r[14]+=0x00000020u;
goto P_0c04f340;
P_0c04f340: /* original 7d01, guest PC 0x0c04f340 */
if(!s->budget--) { s->failed_pc=0x0c04f340u; return 0; }
r[13]+=0x00000001u;
goto P_0c04f342;
P_0c04f342: /* original 52c7, guest PC 0x0c04f342 */
if(!s->budget--) { s->failed_pc=0x0c04f342u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c04f344;
P_0c04f344: /* original 532c, guest PC 0x0c04f344 */
if(!s->budget--) { s->failed_pc=0x0c04f344u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04f346;
P_0c04f346: /* original 3d33, guest PC 0x0c04f346 */
if(!s->budget--) { s->failed_pc=0x0c04f346u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04f348;
P_0c04f348: /* original 8bea, guest PC 0x0c04f348 */
if(!s->budget--) { s->failed_pc=0x0c04f348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f320; }
goto P_0c04f34a;
P_0c04f34a: /* original e000, guest PC 0x0c04f34a */
if(!s->budget--) { s->failed_pc=0x0c04f34au; return 0; }
r[0]=0x00000000u;
goto P_0c04f34c;
P_0c04f34c: /* original 7f04, guest PC 0x0c04f34c */
if(!s->budget--) { s->failed_pc=0x0c04f34cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04f34e;
P_0c04f34e: /* original 4f16, guest PC 0x0c04f34e */
if(!s->budget--) { s->failed_pc=0x0c04f34eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f350;
P_0c04f350: /* original 4f26, guest PC 0x0c04f350 */
if(!s->budget--) { s->failed_pc=0x0c04f350u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f352;
P_0c04f352: /* original 6bf6, guest PC 0x0c04f352 */
if(!s->budget--) { s->failed_pc=0x0c04f352u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f354;
P_0c04f354: /* original 6cf6, guest PC 0x0c04f354 */
if(!s->budget--) { s->failed_pc=0x0c04f354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f356;
P_0c04f356: /* original 6df6, guest PC 0x0c04f356 */
if(!s->budget--) { s->failed_pc=0x0c04f356u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f358;
P_0c04f358: /* original 000b, guest PC 0x0c04f358 */
if(!s->budget--) { s->failed_pc=0x0c04f358u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f35a: /* original 6ef6, guest PC 0x0c04f35a */
if(!s->budget--) { s->failed_pc=0x0c04f35au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04f35cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f35cu; return 0; } return 1;
P_0c04f370: /* original 2fe6, guest PC 0x0c04f370 */
if(!s->budget--) { s->failed_pc=0x0c04f370u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f372;
P_0c04f372: /* original 2fd6, guest PC 0x0c04f372 */
if(!s->budget--) { s->failed_pc=0x0c04f372u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f374;
P_0c04f374: /* original 2fc6, guest PC 0x0c04f374 */
if(!s->budget--) { s->failed_pc=0x0c04f374u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f376;
P_0c04f376: /* original 6c43, guest PC 0x0c04f376 */
if(!s->budget--) { s->failed_pc=0x0c04f376u; return 0; }
r[12]=r[4];
goto P_0c04f378;
P_0c04f378: /* original 4f22, guest PC 0x0c04f378 */
if(!s->budget--) { s->failed_pc=0x0c04f378u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f37a;
P_0c04f37a: /* original 9d6b, guest PC 0x0c04f37a */
if(!s->budget--) { s->failed_pc=0x0c04f37au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f454u,2);
goto P_0c04f37c;
P_0c04f37c: /* original d336, guest PC 0x0c04f37c */
if(!s->budget--) { s->failed_pc=0x0c04f37cu; return 0; }
r[3]=read(ram,0x0c04f458u,4);
goto P_0c04f37e;
P_0c04f37e: /* original 4f12, guest PC 0x0c04f37e */
if(!s->budget--) { s->failed_pc=0x0c04f37eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f380;
P_0c04f380: /* original 2cdf, guest PC 0x0c04f380 */
if(!s->budget--) { s->failed_pc=0x0c04f380u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[13]);
goto P_0c04f382;
P_0c04f382: /* original 2f46, guest PC 0x0c04f382 */
if(!s->budget--) { s->failed_pc=0x0c04f382u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f384;
P_0c04f384: /* original d235, guest PC 0x0c04f384 */
if(!s->budget--) { s->failed_pc=0x0c04f384u; return 0; }
r[2]=read(ram,0x0c04f45cu,4);
goto P_0c04f386;
P_0c04f386: /* original 0d1a, guest PC 0x0c04f386 */
if(!s->budget--) { s->failed_pc=0x0c04f386u; return 0; }
r[13]=r[19];
goto P_0c04f388;
P_0c04f388: /* original d135, guest PC 0x0c04f388 */
if(!s->budget--) { s->failed_pc=0x0c04f388u; return 0; }
r[1]=read(ram,0x0c04f460u,4);
goto P_0c04f38a;
P_0c04f38a: /* original 6ddf, guest PC 0x0c04f38a */
if(!s->budget--) { s->failed_pc=0x0c04f38au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04f38c;
P_0c04f38c: /* original 3d3c, guest PC 0x0c04f38c */
if(!s->budget--) { s->failed_pc=0x0c04f38cu; return 0; }
r[13]+=r[3];
goto P_0c04f38e;
P_0c04f38e: /* original 410b, guest PC 0x0c04f38e */
if(!s->budget--) { s->failed_pc=0x0c04f38eu; return 0; }
target=r[1];
r[16]=code_base|0x0c04f392u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f392u) { target=s->pc; goto dispatch; }
goto P_0c04f392;
P_0c04f390: /* original 2f26, guest PC 0x0c04f390 */
if(!s->budget--) { s->failed_pc=0x0c04f390u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f392;
P_0c04f392: /* original 7f08, guest PC 0x0c04f392 */
if(!s->budget--) { s->failed_pc=0x0c04f392u; return 0; }
r[15]+=0x00000008u;
goto P_0c04f394;
P_0c04f394: /* original a025, guest PC 0x0c04f394 */
if(!s->budget--) { s->failed_pc=0x0c04f394u; return 0; }
r[14]=0x00000000u;
goto P_0c04f3e2;
P_0c04f396: /* original ee00, guest PC 0x0c04f396 */
if(!s->budget--) { s->failed_pc=0x0c04f396u; return 0; }
r[14]=0x00000000u;
goto P_0c04f398;
P_0c04f398: /* original 65e3, guest PC 0x0c04f398 */
if(!s->budget--) { s->failed_pc=0x0c04f398u; return 0; }
r[5]=r[14];
goto P_0c04f39a;
P_0c04f39a: /* original b580, guest PC 0x0c04f39a */
if(!s->budget--) { s->failed_pc=0x0c04f39au; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f39eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f39eu) { target=s->pc; goto dispatch; }
goto P_0c04f39e;
P_0c04f39c: /* original 64c3, guest PC 0x0c04f39c */
if(!s->budget--) { s->failed_pc=0x0c04f39cu; return 0; }
r[4]=r[12];
goto P_0c04f39e;
P_0c04f39e: /* original d131, guest PC 0x0c04f39e */
if(!s->budget--) { s->failed_pc=0x0c04f39eu; return 0; }
r[1]=read(ram,0x0c04f464u,4);
goto P_0c04f3a0;
P_0c04f3a0: /* original 640d, guest PC 0x0c04f3a0 */
if(!s->budget--) { s->failed_pc=0x0c04f3a0u; return 0; }
r[4]=r[0]&65535u;
goto P_0c04f3a2;
P_0c04f3a2: /* original 6043, guest PC 0x0c04f3a2 */
if(!s->budget--) { s->failed_pc=0x0c04f3a2u; return 0; }
r[0]=r[4];
goto P_0c04f3a4;
P_0c04f3a4: /* original 3010, guest PC 0x0c04f3a4 */
if(!s->budget--) { s->failed_pc=0x0c04f3a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f3a6;
P_0c04f3a6: /* original 891b, guest PC 0x0c04f3a6 */
if(!s->budget--) { s->failed_pc=0x0c04f3a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f3e0; }
goto P_0c04f3a8;
P_0c04f3a8: /* original d12f, guest PC 0x0c04f3a8 */
if(!s->budget--) { s->failed_pc=0x0c04f3a8u; return 0; }
r[1]=read(ram,0x0c04f468u,4);
goto P_0c04f3aa;
P_0c04f3aa: /* original 3010, guest PC 0x0c04f3aa */
if(!s->budget--) { s->failed_pc=0x0c04f3aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f3ac;
P_0c04f3ac: /* original 8918, guest PC 0x0c04f3ac */
if(!s->budget--) { s->failed_pc=0x0c04f3acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f3e0; }
goto P_0c04f3ae;
P_0c04f3ae: /* original d12f, guest PC 0x0c04f3ae */
if(!s->budget--) { s->failed_pc=0x0c04f3aeu; return 0; }
r[1]=read(ram,0x0c04f46cu,4);
goto P_0c04f3b0;
P_0c04f3b0: /* original 3010, guest PC 0x0c04f3b0 */
if(!s->budget--) { s->failed_pc=0x0c04f3b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f3b2;
P_0c04f3b2: /* original 8915, guest PC 0x0c04f3b2 */
if(!s->budget--) { s->failed_pc=0x0c04f3b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f3e0; }
goto P_0c04f3b4;
P_0c04f3b4: /* original 52d7, guest PC 0x0c04f3b4 */
if(!s->budget--) { s->failed_pc=0x0c04f3b4u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04f3b6;
P_0c04f3b6: /* original 532c, guest PC 0x0c04f3b6 */
if(!s->budget--) { s->failed_pc=0x0c04f3b6u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04f3b8;
P_0c04f3b8: /* original 3e33, guest PC 0x0c04f3b8 */
if(!s->budget--) { s->failed_pc=0x0c04f3b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04f3ba;
P_0c04f3ba: /* original 8905, guest PC 0x0c04f3ba */
if(!s->budget--) { s->failed_pc=0x0c04f3bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f3c8; }
goto P_0c04f3bc;
P_0c04f3bc: /* original 51d7, guest PC 0x0c04f3bc */
if(!s->budget--) { s->failed_pc=0x0c04f3bcu; return 0; }
r[1]=read(ram,r[13]+28,4);
goto P_0c04f3be;
P_0c04f3be: /* original 531c, guest PC 0x0c04f3be */
if(!s->budget--) { s->failed_pc=0x0c04f3beu; return 0; }
r[3]=read(ram,r[1]+48,4);
goto P_0c04f3c0;
P_0c04f3c0: /* original 3433, guest PC 0x0c04f3c0 */
if(!s->budget--) { s->failed_pc=0x0c04f3c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c04f3c2;
P_0c04f3c2: /* original 8906, guest PC 0x0c04f3c2 */
if(!s->budget--) { s->failed_pc=0x0c04f3c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f3d2; }
goto P_0c04f3c4;
P_0c04f3c4: /* original a00c, guest PC 0x0c04f3c4 */
if(!s->budget--) { s->failed_pc=0x0c04f3c4u; return 0; }
goto P_0c04f3e0;
P_0c04f3c6: /* original 0009, guest PC 0x0c04f3c6 */
if(!s->budget--) { s->failed_pc=0x0c04f3c6u; return 0; }
goto P_0c04f3c8;
P_0c04f3c8: /* original 52d7, guest PC 0x0c04f3c8 */
if(!s->budget--) { s->failed_pc=0x0c04f3c8u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04f3ca;
P_0c04f3ca: /* original 6322, guest PC 0x0c04f3ca */
if(!s->budget--) { s->failed_pc=0x0c04f3cau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04f3cc;
P_0c04f3cc: /* original 7301, guest PC 0x0c04f3cc */
if(!s->budget--) { s->failed_pc=0x0c04f3ccu; return 0; }
r[3]+=0x00000001u;
goto P_0c04f3ce;
P_0c04f3ce: /* original 3433, guest PC 0x0c04f3ce */
if(!s->budget--) { s->failed_pc=0x0c04f3ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c04f3d0;
P_0c04f3d0: /* original 8b06, guest PC 0x0c04f3d0 */
if(!s->budget--) { s->failed_pc=0x0c04f3d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f3e0; }
goto P_0c04f3d2;
P_0c04f3d2: /* original d323, guest PC 0x0c04f3d2 */
if(!s->budget--) { s->failed_pc=0x0c04f3d2u; return 0; }
r[3]=read(ram,0x0c04f460u,4);
goto P_0c04f3d4;
P_0c04f3d4: /* original de26, guest PC 0x0c04f3d4 */
if(!s->budget--) { s->failed_pc=0x0c04f3d4u; return 0; }
r[14]=read(ram,0x0c04f470u,4);
goto P_0c04f3d6;
P_0c04f3d6: /* original 430b, guest PC 0x0c04f3d6 */
if(!s->budget--) { s->failed_pc=0x0c04f3d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f3dau;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f3dau) { target=s->pc; goto dispatch; }
goto P_0c04f3da;
P_0c04f3d8: /* original 2fe6, guest PC 0x0c04f3d8 */
if(!s->budget--) { s->failed_pc=0x0c04f3d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f3da;
P_0c04f3da: /* original 7f04, guest PC 0x0c04f3da */
if(!s->budget--) { s->failed_pc=0x0c04f3dau; return 0; }
r[15]+=0x00000004u;
goto P_0c04f3dc;
P_0c04f3dc: /* original a007, guest PC 0x0c04f3dc */
if(!s->budget--) { s->failed_pc=0x0c04f3dcu; return 0; }
r[0]=0xffffffffu;
goto P_0c04f3ee;
P_0c04f3de: /* original e0ff, guest PC 0x0c04f3de */
if(!s->budget--) { s->failed_pc=0x0c04f3deu; return 0; }
r[0]=0xffffffffu;
goto P_0c04f3e0;
P_0c04f3e0: /* original 7e01, guest PC 0x0c04f3e0 */
if(!s->budget--) { s->failed_pc=0x0c04f3e0u; return 0; }
r[14]+=0x00000001u;
goto P_0c04f3e2;
P_0c04f3e2: /* original 53d7, guest PC 0x0c04f3e2 */
if(!s->budget--) { s->failed_pc=0x0c04f3e2u; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c04f3e4;
P_0c04f3e4: /* original 6232, guest PC 0x0c04f3e4 */
if(!s->budget--) { s->failed_pc=0x0c04f3e4u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04f3e6;
P_0c04f3e6: /* original 7201, guest PC 0x0c04f3e6 */
if(!s->budget--) { s->failed_pc=0x0c04f3e6u; return 0; }
r[2]+=0x00000001u;
goto P_0c04f3e8;
P_0c04f3e8: /* original 3e23, guest PC 0x0c04f3e8 */
if(!s->budget--) { s->failed_pc=0x0c04f3e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c04f3ea;
P_0c04f3ea: /* original 8bd5, guest PC 0x0c04f3ea */
if(!s->budget--) { s->failed_pc=0x0c04f3eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f398; }
goto P_0c04f3ec;
P_0c04f3ec: /* original e000, guest PC 0x0c04f3ec */
if(!s->budget--) { s->failed_pc=0x0c04f3ecu; return 0; }
r[0]=0x00000000u;
goto P_0c04f3ee;
P_0c04f3ee: /* original 4f16, guest PC 0x0c04f3ee */
if(!s->budget--) { s->failed_pc=0x0c04f3eeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f3f0;
P_0c04f3f0: /* original 4f26, guest PC 0x0c04f3f0 */
if(!s->budget--) { s->failed_pc=0x0c04f3f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f3f2;
P_0c04f3f2: /* original 6cf6, guest PC 0x0c04f3f2 */
if(!s->budget--) { s->failed_pc=0x0c04f3f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f3f4;
P_0c04f3f4: /* original 6df6, guest PC 0x0c04f3f4 */
if(!s->budget--) { s->failed_pc=0x0c04f3f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f3f6;
P_0c04f3f6: /* original 000b, guest PC 0x0c04f3f6 */
if(!s->budget--) { s->failed_pc=0x0c04f3f6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f3f8: /* original 6ef6, guest PC 0x0c04f3f8 */
if(!s->budget--) { s->failed_pc=0x0c04f3f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f3fa;
P_0c04f3fa: /* original 2fe6, guest PC 0x0c04f3fa */
if(!s->budget--) { s->failed_pc=0x0c04f3fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f3fc;
P_0c04f3fc: /* original 6e43, guest PC 0x0c04f3fc */
if(!s->budget--) { s->failed_pc=0x0c04f3fcu; return 0; }
r[14]=r[4];
goto P_0c04f3fe;
P_0c04f3fe: /* original 2fd6, guest PC 0x0c04f3fe */
if(!s->budget--) { s->failed_pc=0x0c04f3feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f400;
P_0c04f400: /* original 2fc6, guest PC 0x0c04f400 */
if(!s->budget--) { s->failed_pc=0x0c04f400u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f402;
P_0c04f402: /* original 2fb6, guest PC 0x0c04f402 */
if(!s->budget--) { s->failed_pc=0x0c04f402u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f404;
P_0c04f404: /* original 2fa6, guest PC 0x0c04f404 */
if(!s->budget--) { s->failed_pc=0x0c04f404u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f406;
P_0c04f406: /* original 2f96, guest PC 0x0c04f406 */
if(!s->budget--) { s->failed_pc=0x0c04f406u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f408;
P_0c04f408: /* original 4f22, guest PC 0x0c04f408 */
if(!s->budget--) { s->failed_pc=0x0c04f408u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f40a;
P_0c04f40a: /* original 9a23, guest PC 0x0c04f40a */
if(!s->budget--) { s->failed_pc=0x0c04f40au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f454u,2);
goto P_0c04f40c;
P_0c04f40c: /* original 4f12, guest PC 0x0c04f40c */
if(!s->budget--) { s->failed_pc=0x0c04f40cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f40e;
P_0c04f40e: /* original 2eaf, guest PC 0x0c04f40e */
if(!s->budget--) { s->failed_pc=0x0c04f40eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[10]);
goto P_0c04f410;
P_0c04f410: /* original 7fec, guest PC 0x0c04f410 */
if(!s->budget--) { s->failed_pc=0x0c04f410u; return 0; }
r[15]+=0xffffffecu;
goto P_0c04f412;
P_0c04f412: /* original 0a1a, guest PC 0x0c04f412 */
if(!s->budget--) { s->failed_pc=0x0c04f412u; return 0; }
r[10]=r[19];
goto P_0c04f414;
P_0c04f414: /* original 6aaf, guest PC 0x0c04f414 */
if(!s->budget--) { s->failed_pc=0x0c04f414u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c04f416;
P_0c04f416: /* original 2fa2, guest PC 0x0c04f416 */
if(!s->budget--) { s->failed_pc=0x0c04f416u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c04f418;
P_0c04f418: /* original d30f, guest PC 0x0c04f418 */
if(!s->budget--) { s->failed_pc=0x0c04f418u; return 0; }
r[3]=read(ram,0x0c04f458u,4);
goto P_0c04f41a;
P_0c04f41a: /* original 3a3c, guest PC 0x0c04f41a */
if(!s->budget--) { s->failed_pc=0x0c04f41au; return 0; }
r[10]+=r[3];
goto P_0c04f41c;
P_0c04f41c: /* original 84a2, guest PC 0x0c04f41c */
if(!s->budget--) { s->failed_pc=0x0c04f41cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+2,1);
goto P_0c04f41e;
P_0c04f41e: /* original 2008, guest PC 0x0c04f41e */
if(!s->budget--) { s->failed_pc=0x0c04f41eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f420;
P_0c04f420: /* original 8d15, guest PC 0x0c04f420 */
if(!s->budget--) { s->failed_pc=0x0c04f420u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c04f44e; }
goto P_0c04f424;
P_0c04f422: /* original 6b53, guest PC 0x0c04f422 */
if(!s->budget--) { s->failed_pc=0x0c04f422u; return 0; }
r[11]=r[5];
goto P_0c04f424;
P_0c04f424: /* original d313, guest PC 0x0c04f424 */
if(!s->budget--) { s->failed_pc=0x0c04f424u; return 0; }
r[3]=read(ram,0x0c04f474u,4);
goto P_0c04f426;
P_0c04f426: /* original 430b, guest PC 0x0c04f426 */
if(!s->budget--) { s->failed_pc=0x0c04f426u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f42au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f42au) { target=s->pc; goto dispatch; }
goto P_0c04f42a;
P_0c04f428: /* original 64e3, guest PC 0x0c04f428 */
if(!s->budget--) { s->failed_pc=0x0c04f428u; return 0; }
r[4]=r[14];
goto P_0c04f42a;
P_0c04f42a: /* original 2008, guest PC 0x0c04f42a */
if(!s->budget--) { s->failed_pc=0x0c04f42au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f42c;
P_0c04f42c: /* original 8b04, guest PC 0x0c04f42c */
if(!s->budget--) { s->failed_pc=0x0c04f42cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f438; }
goto P_0c04f42e;
P_0c04f42e: /* original d312, guest PC 0x0c04f42e */
if(!s->budget--) { s->failed_pc=0x0c04f42eu; return 0; }
r[3]=read(ram,0x0c04f478u,4);
goto P_0c04f430;
P_0c04f430: /* original 430b, guest PC 0x0c04f430 */
if(!s->budget--) { s->failed_pc=0x0c04f430u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f434u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f434u) { target=s->pc; goto dispatch; }
goto P_0c04f434;
P_0c04f432: /* original 64e3, guest PC 0x0c04f432 */
if(!s->budget--) { s->failed_pc=0x0c04f432u; return 0; }
r[4]=r[14];
goto P_0c04f434;
P_0c04f434: /* original a00b, guest PC 0x0c04f434 */
if(!s->budget--) { s->failed_pc=0x0c04f434u; return 0; }
goto P_0c04f44e;
P_0c04f436: /* original 0009, guest PC 0x0c04f436 */
if(!s->budget--) { s->failed_pc=0x0c04f436u; return 0; }
goto P_0c04f438;
P_0c04f438: /* original d210, guest PC 0x0c04f438 */
if(!s->budget--) { s->failed_pc=0x0c04f438u; return 0; }
r[2]=read(ram,0x0c04f47cu,4);
goto P_0c04f43a;
P_0c04f43a: /* original 420b, guest PC 0x0c04f43a */
if(!s->budget--) { s->failed_pc=0x0c04f43au; return 0; }
target=r[2];
r[16]=code_base|0x0c04f43eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f43eu) { target=s->pc; goto dispatch; }
goto P_0c04f43e;
P_0c04f43c: /* original 64e3, guest PC 0x0c04f43c */
if(!s->budget--) { s->failed_pc=0x0c04f43cu; return 0; }
r[4]=r[14];
goto P_0c04f43e;
P_0c04f43e: /* original 2008, guest PC 0x0c04f43e */
if(!s->budget--) { s->failed_pc=0x0c04f43eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f440;
P_0c04f440: /* original 8905, guest PC 0x0c04f440 */
if(!s->budget--) { s->failed_pc=0x0c04f440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f44e; }
goto P_0c04f442;
P_0c04f442: /* original 62f2, guest PC 0x0c04f442 */
if(!s->budget--) { s->failed_pc=0x0c04f442u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04f444;
P_0c04f444: /* original d304, guest PC 0x0c04f444 */
if(!s->budget--) { s->failed_pc=0x0c04f444u; return 0; }
r[3]=read(ram,0x0c04f458u,4);
goto P_0c04f446;
P_0c04f446: /* original 323c, guest PC 0x0c04f446 */
if(!s->budget--) { s->failed_pc=0x0c04f446u; return 0; }
r[2]+=r[3];
goto P_0c04f448;
P_0c04f448: /* original 8428, guest PC 0x0c04f448 */
if(!s->budget--) { s->failed_pc=0x0c04f448u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04f44a;
P_0c04f44a: /* original 2008, guest PC 0x0c04f44a */
if(!s->budget--) { s->failed_pc=0x0c04f44au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f44c;
P_0c04f44c: /* original 8b18, guest PC 0x0c04f44c */
if(!s->budget--) { s->failed_pc=0x0c04f44cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f480; }
goto P_0c04f44e;
P_0c04f44e: /* original 9002, guest PC 0x0c04f44e */
if(!s->budget--) { s->failed_pc=0x0c04f44eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f456u,2);
goto P_0c04f450;
P_0c04f450: /* original a090, guest PC 0x0c04f450 */
if(!s->budget--) { s->failed_pc=0x0c04f450u; return 0; }
goto P_0c04f574;
P_0c04f452: /* original 0009, guest PC 0x0c04f452 */
if(!s->budget--) { s->failed_pc=0x0c04f452u; return 0; }
if(!vf3_matrix_family(0x0c04f454u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f454u; return 0; } return 1;
P_0c04f480: /* original d330, guest PC 0x0c04f480 */
if(!s->budget--) { s->failed_pc=0x0c04f480u; return 0; }
r[3]=read(ram,0x0c04f544u,4);
goto P_0c04f482;
P_0c04f482: /* original 430b, guest PC 0x0c04f482 */
if(!s->budget--) { s->failed_pc=0x0c04f482u; return 0; }
target=r[3];
r[16]=code_base|0x0c04f486u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f486u) { target=s->pc; goto dispatch; }
goto P_0c04f486;
P_0c04f484: /* original 64e3, guest PC 0x0c04f484 */
if(!s->budget--) { s->failed_pc=0x0c04f484u; return 0; }
r[4]=r[14];
goto P_0c04f486;
P_0c04f486: /* original 4011, guest PC 0x0c04f486 */
if(!s->budget--) { s->failed_pc=0x0c04f486u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04f488;
P_0c04f488: /* original 8902, guest PC 0x0c04f488 */
if(!s->budget--) { s->failed_pc=0x0c04f488u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f490; }
goto P_0c04f48a;
P_0c04f48a: /* original 9058, guest PC 0x0c04f48a */
if(!s->budget--) { s->failed_pc=0x0c04f48au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f53eu,2);
goto P_0c04f48c;
P_0c04f48c: /* original a072, guest PC 0x0c04f48c */
if(!s->budget--) { s->failed_pc=0x0c04f48cu; return 0; }
goto P_0c04f574;
P_0c04f48e: /* original 0009, guest PC 0x0c04f48e */
if(!s->budget--) { s->failed_pc=0x0c04f48eu; return 0; }
goto P_0c04f490;
P_0c04f490: /* original 53a7, guest PC 0x0c04f490 */
if(!s->budget--) { s->failed_pc=0x0c04f490u; return 0; }
r[3]=read(ram,r[10]+28,4);
goto P_0c04f492;
P_0c04f492: /* original 523e, guest PC 0x0c04f492 */
if(!s->budget--) { s->failed_pc=0x0c04f492u; return 0; }
r[2]=read(ram,r[3]+56,4);
goto P_0c04f494;
P_0c04f494: /* original 2228, guest PC 0x0c04f494 */
if(!s->budget--) { s->failed_pc=0x0c04f494u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04f496;
P_0c04f496: /* original 890a, guest PC 0x0c04f496 */
if(!s->budget--) { s->failed_pc=0x0c04f496u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f4ae; }
goto P_0c04f498;
P_0c04f498: /* original 65f3, guest PC 0x0c04f498 */
if(!s->budget--) { s->failed_pc=0x0c04f498u; return 0; }
r[5]=r[15];
goto P_0c04f49a;
P_0c04f49a: /* original 7504, guest PC 0x0c04f49a */
if(!s->budget--) { s->failed_pc=0x0c04f49au; return 0; }
r[5]+=0x00000004u;
goto P_0c04f49c;
P_0c04f49c: /* original bd76, guest PC 0x0c04f49c */
if(!s->budget--) { s->failed_pc=0x0c04f49cu; return 0; }
target=code_base|0x0c04ef8cu; r[16]=code_base|0x0c04f4a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4a0u) { target=s->pc; goto dispatch; }
goto P_0c04f4a0;
P_0c04f49e: /* original 64e3, guest PC 0x0c04f49e */
if(!s->budget--) { s->failed_pc=0x0c04f49eu; return 0; }
r[4]=r[14];
goto P_0c04f4a0;
P_0c04f4a0: /* original 6403, guest PC 0x0c04f4a0 */
if(!s->budget--) { s->failed_pc=0x0c04f4a0u; return 0; }
r[4]=r[0];
goto P_0c04f4a2;
P_0c04f4a2: /* original 2448, guest PC 0x0c04f4a2 */
if(!s->budget--) { s->failed_pc=0x0c04f4a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04f4a4;
P_0c04f4a4: /* original 8903, guest PC 0x0c04f4a4 */
if(!s->budget--) { s->failed_pc=0x0c04f4a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f4ae; }
goto P_0c04f4a6;
P_0c04f4a6: /* original bf63, guest PC 0x0c04f4a6 */
if(!s->budget--) { s->failed_pc=0x0c04f4a6u; return 0; }
target=code_base|0x0c04f370u; r[16]=code_base|0x0c04f4aau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4aau) { target=s->pc; goto dispatch; }
goto P_0c04f4aa;
P_0c04f4a8: /* original 64e3, guest PC 0x0c04f4a8 */
if(!s->budget--) { s->failed_pc=0x0c04f4a8u; return 0; }
r[4]=r[14];
goto P_0c04f4aa;
P_0c04f4aa: /* original 4011, guest PC 0x0c04f4aa */
if(!s->budget--) { s->failed_pc=0x0c04f4aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04f4ac;
P_0c04f4ac: /* original 8902, guest PC 0x0c04f4ac */
if(!s->budget--) { s->failed_pc=0x0c04f4acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f4b4; }
goto P_0c04f4ae;
P_0c04f4ae: /* original 9047, guest PC 0x0c04f4ae */
if(!s->budget--) { s->failed_pc=0x0c04f4aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f540u,2);
goto P_0c04f4b0;
P_0c04f4b0: /* original a060, guest PC 0x0c04f4b0 */
if(!s->budget--) { s->failed_pc=0x0c04f4b0u; return 0; }
goto P_0c04f574;
P_0c04f4b2: /* original 0009, guest PC 0x0c04f4b2 */
if(!s->budget--) { s->failed_pc=0x0c04f4b2u; return 0; }
goto P_0c04f4b4;
P_0c04f4b4: /* original becc, guest PC 0x0c04f4b4 */
if(!s->budget--) { s->failed_pc=0x0c04f4b4u; return 0; }
target=code_base|0x0c04f250u; r[16]=code_base|0x0c04f4b8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4b8u) { target=s->pc; goto dispatch; }
goto P_0c04f4b8;
P_0c04f4b6: /* original 64e3, guest PC 0x0c04f4b6 */
if(!s->budget--) { s->failed_pc=0x0c04f4b6u; return 0; }
r[4]=r[14];
goto P_0c04f4b8;
P_0c04f4b8: /* original 6d03, guest PC 0x0c04f4b8 */
if(!s->budget--) { s->failed_pc=0x0c04f4b8u; return 0; }
r[13]=r[0];
goto P_0c04f4ba;
P_0c04f4ba: /* original 4d11, guest PC 0x0c04f4ba */
if(!s->budget--) { s->failed_pc=0x0c04f4bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c04f4bc;
P_0c04f4bc: /* original 8b39, guest PC 0x0c04f4bc */
if(!s->budget--) { s->failed_pc=0x0c04f4bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f532; }
goto P_0c04f4be;
P_0c04f4be: /* original 65d3, guest PC 0x0c04f4be */
if(!s->budget--) { s->failed_pc=0x0c04f4beu; return 0; }
r[5]=r[13];
goto P_0c04f4c0;
P_0c04f4c0: /* original 7501, guest PC 0x0c04f4c0 */
if(!s->budget--) { s->failed_pc=0x0c04f4c0u; return 0; }
r[5]+=0x00000001u;
goto P_0c04f4c2;
P_0c04f4c2: /* original beef, guest PC 0x0c04f4c2 */
if(!s->budget--) { s->failed_pc=0x0c04f4c2u; return 0; }
target=code_base|0x0c04f2a4u; r[16]=code_base|0x0c04f4c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4c6u) { target=s->pc; goto dispatch; }
goto P_0c04f4c6;
P_0c04f4c4: /* original 64e3, guest PC 0x0c04f4c4 */
if(!s->budget--) { s->failed_pc=0x0c04f4c4u; return 0; }
r[4]=r[14];
goto P_0c04f4c6;
P_0c04f4c6: /* original 6c03, guest PC 0x0c04f4c6 */
if(!s->budget--) { s->failed_pc=0x0c04f4c6u; return 0; }
r[12]=r[0];
goto P_0c04f4c8;
P_0c04f4c8: /* original 4c11, guest PC 0x0c04f4c8 */
if(!s->budget--) { s->failed_pc=0x0c04f4c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04f4ca;
P_0c04f4ca: /* original 8b32, guest PC 0x0c04f4ca */
if(!s->budget--) { s->failed_pc=0x0c04f4cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f532; }
goto P_0c04f4cc;
P_0c04f4cc: /* original d91e, guest PC 0x0c04f4cc */
if(!s->budget--) { s->failed_pc=0x0c04f4ccu; return 0; }
r[9]=read(ram,0x0c04f548u,4);
goto P_0c04f4ce;
P_0c04f4ce: /* original 65d3, guest PC 0x0c04f4ce */
if(!s->budget--) { s->failed_pc=0x0c04f4ceu; return 0; }
r[5]=r[13];
goto P_0c04f4d0;
P_0c04f4d0: /* original 66b3, guest PC 0x0c04f4d0 */
if(!s->budget--) { s->failed_pc=0x0c04f4d0u; return 0; }
r[6]=r[11];
goto P_0c04f4d2;
P_0c04f4d2: /* original 490b, guest PC 0x0c04f4d2 */
if(!s->budget--) { s->failed_pc=0x0c04f4d2u; return 0; }
target=r[9];
r[16]=code_base|0x0c04f4d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4d6u) { target=s->pc; goto dispatch; }
goto P_0c04f4d6;
P_0c04f4d4: /* original 64e3, guest PC 0x0c04f4d4 */
if(!s->budget--) { s->failed_pc=0x0c04f4d4u; return 0; }
r[4]=r[14];
goto P_0c04f4d6;
P_0c04f4d6: /* original 6403, guest PC 0x0c04f4d6 */
if(!s->budget--) { s->failed_pc=0x0c04f4d6u; return 0; }
r[4]=r[0];
goto P_0c04f4d8;
P_0c04f4d8: /* original 4411, guest PC 0x0c04f4d8 */
if(!s->budget--) { s->failed_pc=0x0c04f4d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f4da;
P_0c04f4da: /* original 8b4a, guest PC 0x0c04f4da */
if(!s->budget--) { s->failed_pc=0x0c04f4dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f572; }
goto P_0c04f4dc;
P_0c04f4dc: /* original d91b, guest PC 0x0c04f4dc */
if(!s->budget--) { s->failed_pc=0x0c04f4dcu; return 0; }
r[9]=read(ram,0x0c04f54cu,4);
goto P_0c04f4de;
P_0c04f4de: /* original 65c3, guest PC 0x0c04f4de */
if(!s->budget--) { s->failed_pc=0x0c04f4deu; return 0; }
r[5]=r[12];
goto P_0c04f4e0;
P_0c04f4e0: /* original 66b3, guest PC 0x0c04f4e0 */
if(!s->budget--) { s->failed_pc=0x0c04f4e0u; return 0; }
r[6]=r[11];
goto P_0c04f4e2;
P_0c04f4e2: /* original 490b, guest PC 0x0c04f4e2 */
if(!s->budget--) { s->failed_pc=0x0c04f4e2u; return 0; }
target=r[9];
r[16]=code_base|0x0c04f4e6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4e6u) { target=s->pc; goto dispatch; }
goto P_0c04f4e6;
P_0c04f4e4: /* original 64e3, guest PC 0x0c04f4e4 */
if(!s->budget--) { s->failed_pc=0x0c04f4e4u; return 0; }
r[4]=r[14];
goto P_0c04f4e6;
P_0c04f4e6: /* original 6403, guest PC 0x0c04f4e6 */
if(!s->budget--) { s->failed_pc=0x0c04f4e6u; return 0; }
r[4]=r[0];
goto P_0c04f4e8;
P_0c04f4e8: /* original 4411, guest PC 0x0c04f4e8 */
if(!s->budget--) { s->failed_pc=0x0c04f4e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04f4ea;
P_0c04f4ea: /* original 8b42, guest PC 0x0c04f4ea */
if(!s->budget--) { s->failed_pc=0x0c04f4eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f572; }
goto P_0c04f4ec;
P_0c04f4ec: /* original 65d3, guest PC 0x0c04f4ec */
if(!s->budget--) { s->failed_pc=0x0c04f4ecu; return 0; }
r[5]=r[13];
goto P_0c04f4ee;
P_0c04f4ee: /* original b47b, guest PC 0x0c04f4ee */
if(!s->budget--) { s->failed_pc=0x0c04f4eeu; return 0; }
target=code_base|0x0c04fde8u; r[16]=code_base|0x0c04f4f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4f2u) { target=s->pc; goto dispatch; }
goto P_0c04f4f2;
P_0c04f4f0: /* original 64e3, guest PC 0x0c04f4f0 */
if(!s->budget--) { s->failed_pc=0x0c04f4f0u; return 0; }
r[4]=r[14];
goto P_0c04f4f2;
P_0c04f4f2: /* original 6503, guest PC 0x0c04f4f2 */
if(!s->budget--) { s->failed_pc=0x0c04f4f2u; return 0; }
r[5]=r[0];
goto P_0c04f4f4;
P_0c04f4f4: /* original 4515, guest PC 0x0c04f4f4 */
if(!s->budget--) { s->failed_pc=0x0c04f4f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c04f4f6;
P_0c04f4f6: /* original 8b04, guest PC 0x0c04f4f6 */
if(!s->budget--) { s->failed_pc=0x0c04f4f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f502; }
goto P_0c04f4f8;
P_0c04f4f8: /* original 66c3, guest PC 0x0c04f4f8 */
if(!s->budget--) { s->failed_pc=0x0c04f4f8u; return 0; }
r[6]=r[12];
goto P_0c04f4fa;
P_0c04f4fa: /* original b4a1, guest PC 0x0c04f4fa */
if(!s->budget--) { s->failed_pc=0x0c04f4fau; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f4feu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f4feu) { target=s->pc; goto dispatch; }
goto P_0c04f4fe;
P_0c04f4fc: /* original 64e3, guest PC 0x0c04f4fc */
if(!s->budget--) { s->failed_pc=0x0c04f4fcu; return 0; }
r[4]=r[14];
goto P_0c04f4fe;
P_0c04f4fe: /* original a00a, guest PC 0x0c04f4fe */
if(!s->budget--) { s->failed_pc=0x0c04f4feu; return 0; }
goto P_0c04f516;
P_0c04f500: /* original 0009, guest PC 0x0c04f500 */
if(!s->budget--) { s->failed_pc=0x0c04f500u; return 0; }
goto P_0c04f502;
P_0c04f502: /* original 65d3, guest PC 0x0c04f502 */
if(!s->budget--) { s->failed_pc=0x0c04f502u; return 0; }
r[5]=r[13];
goto P_0c04f504;
P_0c04f504: /* original befa, guest PC 0x0c04f504 */
if(!s->budget--) { s->failed_pc=0x0c04f504u; return 0; }
target=code_base|0x0c04f2fcu; r[16]=code_base|0x0c04f508u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f508u) { target=s->pc; goto dispatch; }
goto P_0c04f508;
P_0c04f506: /* original 64e3, guest PC 0x0c04f506 */
if(!s->budget--) { s->failed_pc=0x0c04f506u; return 0; }
r[4]=r[14];
goto P_0c04f508;
P_0c04f508: /* original d911, guest PC 0x0c04f508 */
if(!s->budget--) { s->failed_pc=0x0c04f508u; return 0; }
r[9]=read(ram,0x0c04f550u,4);
goto P_0c04f50a;
P_0c04f50a: /* original 66c3, guest PC 0x0c04f50a */
if(!s->budget--) { s->failed_pc=0x0c04f50au; return 0; }
r[6]=r[12];
goto P_0c04f50c;
P_0c04f50c: /* original 6403, guest PC 0x0c04f50c */
if(!s->budget--) { s->failed_pc=0x0c04f50cu; return 0; }
r[4]=r[0];
goto P_0c04f50e;
P_0c04f50e: /* original 6392, guest PC 0x0c04f50e */
if(!s->budget--) { s->failed_pc=0x0c04f50eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c04f510;
P_0c04f510: /* original 5234, guest PC 0x0c04f510 */
if(!s->budget--) { s->failed_pc=0x0c04f510u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04f512;
P_0c04f512: /* original 420b, guest PC 0x0c04f512 */
if(!s->budget--) { s->failed_pc=0x0c04f512u; return 0; }
target=r[2];
r[16]=code_base|0x0c04f516u;
r[5]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f516u) { target=s->pc; goto dispatch; }
goto P_0c04f516;
P_0c04f514: /* original e502, guest PC 0x0c04f514 */
if(!s->budget--) { s->failed_pc=0x0c04f514u; return 0; }
r[5]=0x00000002u;
goto P_0c04f516;
P_0c04f516: /* original 65d3, guest PC 0x0c04f516 */
if(!s->budget--) { s->failed_pc=0x0c04f516u; return 0; }
r[5]=r[13];
goto P_0c04f518;
P_0c04f518: /* original b4c1, guest PC 0x0c04f518 */
if(!s->budget--) { s->failed_pc=0x0c04f518u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c04f51cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f51cu) { target=s->pc; goto dispatch; }
goto P_0c04f51c;
P_0c04f51a: /* original 64e3, guest PC 0x0c04f51a */
if(!s->budget--) { s->failed_pc=0x0c04f51au; return 0; }
r[4]=r[14];
goto P_0c04f51c;
P_0c04f51c: /* original 65c3, guest PC 0x0c04f51c */
if(!s->budget--) { s->failed_pc=0x0c04f51cu; return 0; }
r[5]=r[12];
goto P_0c04f51e;
P_0c04f51e: /* original 6603, guest PC 0x0c04f51e */
if(!s->budget--) { s->failed_pc=0x0c04f51eu; return 0; }
r[6]=r[0];
goto P_0c04f520;
P_0c04f520: /* original b48e, guest PC 0x0c04f520 */
if(!s->budget--) { s->failed_pc=0x0c04f520u; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f524u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f524u) { target=s->pc; goto dispatch; }
goto P_0c04f524;
P_0c04f522: /* original 64e3, guest PC 0x0c04f522 */
if(!s->budget--) { s->failed_pc=0x0c04f522u; return 0; }
r[4]=r[14];
goto P_0c04f524;
P_0c04f524: /* original dc0b, guest PC 0x0c04f524 */
if(!s->budget--) { s->failed_pc=0x0c04f524u; return 0; }
r[12]=read(ram,0x0c04f554u,4);
goto P_0c04f526;
P_0c04f526: /* original 65d3, guest PC 0x0c04f526 */
if(!s->budget--) { s->failed_pc=0x0c04f526u; return 0; }
r[5]=r[13];
goto P_0c04f528;
P_0c04f528: /* original 66c3, guest PC 0x0c04f528 */
if(!s->budget--) { s->failed_pc=0x0c04f528u; return 0; }
r[6]=r[12];
goto P_0c04f52a;
P_0c04f52a: /* original b489, guest PC 0x0c04f52a */
if(!s->budget--) { s->failed_pc=0x0c04f52au; return 0; }
target=code_base|0x0c04fe40u; r[16]=code_base|0x0c04f52eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f52eu) { target=s->pc; goto dispatch; }
goto P_0c04f52e;
P_0c04f52c: /* original 64e3, guest PC 0x0c04f52c */
if(!s->budget--) { s->failed_pc=0x0c04f52cu; return 0; }
r[4]=r[14];
goto P_0c04f52e;
P_0c04f52e: /* original afc1, guest PC 0x0c04f52e */
if(!s->budget--) { s->failed_pc=0x0c04f52eu; return 0; }
goto P_0c04f4b4;
P_0c04f530: /* original 0009, guest PC 0x0c04f530 */
if(!s->budget--) { s->failed_pc=0x0c04f530u; return 0; }
goto P_0c04f532;
P_0c04f532: /* original 9606, guest PC 0x0c04f532 */
if(!s->budget--) { s->failed_pc=0x0c04f532u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f542u,2);
goto P_0c04f534;
P_0c04f534: /* original 64a3, guest PC 0x0c04f534 */
if(!s->budget--) { s->failed_pc=0x0c04f534u; return 0; }
r[4]=r[10];
goto P_0c04f536;
P_0c04f536: /* original e500, guest PC 0x0c04f536 */
if(!s->budget--) { s->failed_pc=0x0c04f536u; return 0; }
r[5]=0x00000000u;
goto P_0c04f538;
P_0c04f538: /* original 7448, guest PC 0x0c04f538 */
if(!s->budget--) { s->failed_pc=0x0c04f538u; return 0; }
r[4]+=0x00000048u;
goto P_0c04f53a;
P_0c04f53a: /* original a010, guest PC 0x0c04f53a */
if(!s->budget--) { s->failed_pc=0x0c04f53au; return 0; }
r[7]=0x00000001u;
goto P_0c04f55e;
P_0c04f53c: /* original e701, guest PC 0x0c04f53c */
if(!s->budget--) { s->failed_pc=0x0c04f53cu; return 0; }
r[7]=0x00000001u;
if(!vf3_matrix_family(0x0c04f53eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f53eu; return 0; } return 1;
P_0c04f558: /* original 2470, guest PC 0x0c04f558 */
if(!s->budget--) { s->failed_pc=0x0c04f558u; return 0; }
write(ram,r[4],r[7],1);
goto P_0c04f55a;
P_0c04f55a: /* original 7401, guest PC 0x0c04f55a */
if(!s->budget--) { s->failed_pc=0x0c04f55au; return 0; }
r[4]+=0x00000001u;
goto P_0c04f55c;
P_0c04f55c: /* original 7501, guest PC 0x0c04f55c */
if(!s->budget--) { s->failed_pc=0x0c04f55cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04f55e;
P_0c04f55e: /* original 3563, guest PC 0x0c04f55e */
if(!s->budget--) { s->failed_pc=0x0c04f55eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04f560;
P_0c04f560: /* original 8bfa, guest PC 0x0c04f560 */
if(!s->budget--) { s->failed_pc=0x0c04f560u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f558; }
goto P_0c04f562;
P_0c04f562: /* original b0f4, guest PC 0x0c04f562 */
if(!s->budget--) { s->failed_pc=0x0c04f562u; return 0; }
target=code_base|0x0c04f74eu; r[16]=code_base|0x0c04f566u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f566u) { target=s->pc; goto dispatch; }
goto P_0c04f566;
P_0c04f564: /* original 64e3, guest PC 0x0c04f564 */
if(!s->budget--) { s->failed_pc=0x0c04f564u; return 0; }
r[4]=r[14];
goto P_0c04f566;
P_0c04f566: /* original 4011, guest PC 0x0c04f566 */
if(!s->budget--) { s->failed_pc=0x0c04f566u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04f568;
P_0c04f568: /* original 8f03, guest PC 0x0c04f568 */
if(!s->budget--) { s->failed_pc=0x0c04f568u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04f572; }
goto P_0c04f56c;
P_0c04f56a: /* original 6403, guest PC 0x0c04f56a */
if(!s->budget--) { s->failed_pc=0x0c04f56au; return 0; }
r[4]=r[0];
goto P_0c04f56c;
P_0c04f56c: /* original b3e0, guest PC 0x0c04f56c */
if(!s->budget--) { s->failed_pc=0x0c04f56cu; return 0; }
target=code_base|0x0c04fd30u; r[16]=code_base|0x0c04f570u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f570u) { target=s->pc; goto dispatch; }
goto P_0c04f570;
P_0c04f56e: /* original 64e3, guest PC 0x0c04f56e */
if(!s->budget--) { s->failed_pc=0x0c04f56eu; return 0; }
r[4]=r[14];
goto P_0c04f570;
P_0c04f570: /* original 6403, guest PC 0x0c04f570 */
if(!s->budget--) { s->failed_pc=0x0c04f570u; return 0; }
r[4]=r[0];
goto P_0c04f572;
P_0c04f572: /* original 6043, guest PC 0x0c04f572 */
if(!s->budget--) { s->failed_pc=0x0c04f572u; return 0; }
r[0]=r[4];
goto P_0c04f574;
P_0c04f574: /* original 7f14, guest PC 0x0c04f574 */
if(!s->budget--) { s->failed_pc=0x0c04f574u; return 0; }
r[15]+=0x00000014u;
goto P_0c04f576;
P_0c04f576: /* original 4f16, guest PC 0x0c04f576 */
if(!s->budget--) { s->failed_pc=0x0c04f576u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f578;
P_0c04f578: /* original 4f26, guest PC 0x0c04f578 */
if(!s->budget--) { s->failed_pc=0x0c04f578u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f57a;
P_0c04f57a: /* original 69f6, guest PC 0x0c04f57a */
if(!s->budget--) { s->failed_pc=0x0c04f57au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04f57c;
P_0c04f57c: /* original 6af6, guest PC 0x0c04f57c */
if(!s->budget--) { s->failed_pc=0x0c04f57cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04f57e;
P_0c04f57e: /* original 6bf6, guest PC 0x0c04f57e */
if(!s->budget--) { s->failed_pc=0x0c04f57eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04f580;
P_0c04f580: /* original 6cf6, guest PC 0x0c04f580 */
if(!s->budget--) { s->failed_pc=0x0c04f580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f582;
P_0c04f582: /* original 6df6, guest PC 0x0c04f582 */
if(!s->budget--) { s->failed_pc=0x0c04f582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f584;
P_0c04f584: /* original 000b, guest PC 0x0c04f584 */
if(!s->budget--) { s->failed_pc=0x0c04f584u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f586: /* original 6ef6, guest PC 0x0c04f586 */
if(!s->budget--) { s->failed_pc=0x0c04f586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f588u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
