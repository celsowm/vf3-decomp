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
int vf3_advance_05b20e_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05b20eu: goto P_0c05b20e;
case 0x0c05b210u: goto P_0c05b210;
case 0x0c05b212u: goto P_0c05b212;
case 0x0c05b214u: goto P_0c05b214;
case 0x0c05b216u: goto P_0c05b216;
case 0x0c05b218u: goto P_0c05b218;
case 0x0c05b21au: goto P_0c05b21a;
case 0x0c05b21cu: goto P_0c05b21c;
case 0x0c05b21eu: goto P_0c05b21e;
case 0x0c05b220u: goto P_0c05b220;
case 0x0c05b222u: goto P_0c05b222;
case 0x0c05b224u: goto P_0c05b224;
case 0x0c05b226u: goto P_0c05b226;
case 0x0c05b228u: goto P_0c05b228;
case 0x0c05b22au: goto P_0c05b22a;
case 0x0c05b22cu: goto P_0c05b22c;
case 0x0c05b22eu: goto P_0c05b22e;
case 0x0c05b230u: goto P_0c05b230;
case 0x0c05b232u: goto P_0c05b232;
case 0x0c05b234u: goto P_0c05b234;
case 0x0c05b236u: goto P_0c05b236;
case 0x0c05b238u: goto P_0c05b238;
case 0x0c05b23au: goto P_0c05b23a;
case 0x0c05b23cu: goto P_0c05b23c;
case 0x0c05b23eu: goto P_0c05b23e;
case 0x0c05b240u: goto P_0c05b240;
case 0x0c05b242u: goto P_0c05b242;
case 0x0c05b244u: goto P_0c05b244;
case 0x0c05b246u: goto P_0c05b246;
case 0x0c05b248u: goto P_0c05b248;
case 0x0c05b24au: goto P_0c05b24a;
case 0x0c05b24cu: goto P_0c05b24c;
case 0x0c05b24eu: goto P_0c05b24e;
case 0x0c05b250u: goto P_0c05b250;
case 0x0c05b252u: goto P_0c05b252;
case 0x0c05b254u: goto P_0c05b254;
case 0x0c05b256u: goto P_0c05b256;
case 0x0c05b258u: goto P_0c05b258;
case 0x0c05b25au: goto P_0c05b25a;
case 0x0c05b25cu: goto P_0c05b25c;
case 0x0c05b25eu: goto P_0c05b25e;
case 0x0c05b260u: goto P_0c05b260;
case 0x0c05b262u: goto P_0c05b262;
case 0x0c05b264u: goto P_0c05b264;
case 0x0c05b266u: goto P_0c05b266;
case 0x0c05b268u: goto P_0c05b268;
case 0x0c05b26au: goto P_0c05b26a;
case 0x0c05b26cu: goto P_0c05b26c;
case 0x0c05b26eu: goto P_0c05b26e;
case 0x0c05b270u: goto P_0c05b270;
case 0x0c05b272u: goto P_0c05b272;
case 0x0c05b274u: goto P_0c05b274;
case 0x0c05b276u: goto P_0c05b276;
case 0x0c05b278u: goto P_0c05b278;
case 0x0c05b27au: goto P_0c05b27a;
case 0x0c05b27cu: goto P_0c05b27c;
case 0x0c05b27eu: goto P_0c05b27e;
case 0x0c05b280u: goto P_0c05b280;
case 0x0c05b282u: goto P_0c05b282;
case 0x0c05b284u: goto P_0c05b284;
case 0x0c05b286u: goto P_0c05b286;
case 0x0c05b288u: goto P_0c05b288;
case 0x0c05b28au: goto P_0c05b28a;
case 0x0c05b28cu: goto P_0c05b28c;
case 0x0c05b28eu: goto P_0c05b28e;
case 0x0c05b290u: goto P_0c05b290;
case 0x0c05b292u: goto P_0c05b292;
case 0x0c05b294u: goto P_0c05b294;
case 0x0c05b296u: goto P_0c05b296;
case 0x0c05b298u: goto P_0c05b298;
case 0x0c05b29au: goto P_0c05b29a;
case 0x0c05b29cu: goto P_0c05b29c;
case 0x0c05b29eu: goto P_0c05b29e;
case 0x0c05b2a0u: goto P_0c05b2a0;
case 0x0c05b2a2u: goto P_0c05b2a2;
case 0x0c05b2a4u: goto P_0c05b2a4;
case 0x0c05b2a6u: goto P_0c05b2a6;
case 0x0c05b2a8u: goto P_0c05b2a8;
case 0x0c05b2aau: goto P_0c05b2aa;
case 0x0c05b2acu: goto P_0c05b2ac;
case 0x0c05b2aeu: goto P_0c05b2ae;
case 0x0c05b2b0u: goto P_0c05b2b0;
case 0x0c05b2b2u: goto P_0c05b2b2;
case 0x0c05b2b4u: goto P_0c05b2b4;
case 0x0c05b2b6u: goto P_0c05b2b6;
case 0x0c05b2b8u: goto P_0c05b2b8;
case 0x0c05b2bau: goto P_0c05b2ba;
case 0x0c05b2bcu: goto P_0c05b2bc;
case 0x0c05b2beu: goto P_0c05b2be;
case 0x0c05b2c0u: goto P_0c05b2c0;
case 0x0c05b2c2u: goto P_0c05b2c2;
case 0x0c05b2c4u: goto P_0c05b2c4;
case 0x0c05b2c6u: goto P_0c05b2c6;
case 0x0c05b2c8u: goto P_0c05b2c8;
case 0x0c05b2cau: goto P_0c05b2ca;
case 0x0c05b2ccu: goto P_0c05b2cc;
case 0x0c05b2ceu: goto P_0c05b2ce;
case 0x0c05b2d0u: goto P_0c05b2d0;
case 0x0c05b2d2u: goto P_0c05b2d2;
case 0x0c05b2d4u: goto P_0c05b2d4;
case 0x0c05b2d6u: goto P_0c05b2d6;
case 0x0c05b2d8u: goto P_0c05b2d8;
case 0x0c05b2dau: goto P_0c05b2da;
case 0x0c05b2dcu: goto P_0c05b2dc;
case 0x0c05b2deu: goto P_0c05b2de;
case 0x0c05b2e0u: goto P_0c05b2e0;
case 0x0c05b2e2u: goto P_0c05b2e2;
case 0x0c05b2e4u: goto P_0c05b2e4;
case 0x0c05b2e6u: goto P_0c05b2e6;
case 0x0c05b320u: goto P_0c05b320;
case 0x0c05b322u: goto P_0c05b322;
case 0x0c05b324u: goto P_0c05b324;
case 0x0c05b326u: goto P_0c05b326;
case 0x0c05b328u: goto P_0c05b328;
case 0x0c05b32au: goto P_0c05b32a;
case 0x0c05b32cu: goto P_0c05b32c;
case 0x0c05b32eu: goto P_0c05b32e;
case 0x0c05b330u: goto P_0c05b330;
case 0x0c05b332u: goto P_0c05b332;
case 0x0c05b334u: goto P_0c05b334;
case 0x0c05b336u: goto P_0c05b336;
case 0x0c05b338u: goto P_0c05b338;
case 0x0c05b33au: goto P_0c05b33a;
case 0x0c05b33cu: goto P_0c05b33c;
case 0x0c05b33eu: goto P_0c05b33e;
case 0x0c05b340u: goto P_0c05b340;
case 0x0c05b342u: goto P_0c05b342;
case 0x0c05b344u: goto P_0c05b344;
case 0x0c05b346u: goto P_0c05b346;
case 0x0c05b348u: goto P_0c05b348;
case 0x0c05b34au: goto P_0c05b34a;
case 0x0c05b34cu: goto P_0c05b34c;
case 0x0c05b34eu: goto P_0c05b34e;
case 0x0c05b350u: goto P_0c05b350;
case 0x0c05b352u: goto P_0c05b352;
case 0x0c05b354u: goto P_0c05b354;
case 0x0c05b356u: goto P_0c05b356;
case 0x0c05b358u: goto P_0c05b358;
case 0x0c05b35au: goto P_0c05b35a;
case 0x0c05b35cu: goto P_0c05b35c;
case 0x0c05b35eu: goto P_0c05b35e;
case 0x0c05b360u: goto P_0c05b360;
case 0x0c05b362u: goto P_0c05b362;
case 0x0c05b364u: goto P_0c05b364;
case 0x0c05b366u: goto P_0c05b366;
case 0x0c05b368u: goto P_0c05b368;
case 0x0c05b36au: goto P_0c05b36a;
case 0x0c05b36cu: goto P_0c05b36c;
case 0x0c05b36eu: goto P_0c05b36e;
case 0x0c05b370u: goto P_0c05b370;
case 0x0c05b372u: goto P_0c05b372;
case 0x0c05b374u: goto P_0c05b374;
case 0x0c05b376u: goto P_0c05b376;
case 0x0c05b378u: goto P_0c05b378;
case 0x0c05b37au: goto P_0c05b37a;
case 0x0c05b37cu: goto P_0c05b37c;
case 0x0c05b37eu: goto P_0c05b37e;
case 0x0c05b380u: goto P_0c05b380;
case 0x0c05b382u: goto P_0c05b382;
case 0x0c05b384u: goto P_0c05b384;
case 0x0c05b386u: goto P_0c05b386;
case 0x0c05b388u: goto P_0c05b388;
case 0x0c05b38au: goto P_0c05b38a;
case 0x0c05b38cu: goto P_0c05b38c;
case 0x0c05b38eu: goto P_0c05b38e;
case 0x0c05b390u: goto P_0c05b390;
case 0x0c05b392u: goto P_0c05b392;
case 0x0c05b394u: goto P_0c05b394;
case 0x0c05b396u: goto P_0c05b396;
case 0x0c05b398u: goto P_0c05b398;
case 0x0c05b39au: goto P_0c05b39a;
case 0x0c05b39cu: goto P_0c05b39c;
case 0x0c05b39eu: goto P_0c05b39e;
case 0x0c05b3a0u: goto P_0c05b3a0;
case 0x0c05b3d0u: goto P_0c05b3d0;
case 0x0c05b3d2u: goto P_0c05b3d2;
case 0x0c05b3d4u: goto P_0c05b3d4;
case 0x0c05b3d6u: goto P_0c05b3d6;
case 0x0c05b3d8u: goto P_0c05b3d8;
case 0x0c05b3dau: goto P_0c05b3da;
case 0x0c05b3dcu: goto P_0c05b3dc;
case 0x0c05b3deu: goto P_0c05b3de;
case 0x0c05b3e0u: goto P_0c05b3e0;
case 0x0c05b3e2u: goto P_0c05b3e2;
case 0x0c05b3e4u: goto P_0c05b3e4;
case 0x0c05b3e6u: goto P_0c05b3e6;
case 0x0c05b3e8u: goto P_0c05b3e8;
case 0x0c05b3eau: goto P_0c05b3ea;
case 0x0c05b3ecu: goto P_0c05b3ec;
case 0x0c05b3eeu: goto P_0c05b3ee;
case 0x0c05b3f0u: goto P_0c05b3f0;
case 0x0c05b3f2u: goto P_0c05b3f2;
case 0x0c05b3f4u: goto P_0c05b3f4;
case 0x0c05b3f6u: goto P_0c05b3f6;
case 0x0c05b3f8u: goto P_0c05b3f8;
case 0x0c05b3fau: goto P_0c05b3fa;
case 0x0c05b3fcu: goto P_0c05b3fc;
case 0x0c05b3feu: goto P_0c05b3fe;
case 0x0c05b400u: goto P_0c05b400;
case 0x0c05b402u: goto P_0c05b402;
case 0x0c05b404u: goto P_0c05b404;
case 0x0c05b406u: goto P_0c05b406;
case 0x0c05b408u: goto P_0c05b408;
case 0x0c05b40au: goto P_0c05b40a;
case 0x0c05b40cu: goto P_0c05b40c;
case 0x0c05b40eu: goto P_0c05b40e;
case 0x0c05b410u: goto P_0c05b410;
case 0x0c05b412u: goto P_0c05b412;
case 0x0c05b414u: goto P_0c05b414;
case 0x0c05b416u: goto P_0c05b416;
case 0x0c05b418u: goto P_0c05b418;
case 0x0c05b41au: goto P_0c05b41a;
case 0x0c05b41cu: goto P_0c05b41c;
case 0x0c05b41eu: goto P_0c05b41e;
case 0x0c05b420u: goto P_0c05b420;
case 0x0c05b422u: goto P_0c05b422;
case 0x0c05b424u: goto P_0c05b424;
case 0x0c05b426u: goto P_0c05b426;
case 0x0c05b428u: goto P_0c05b428;
case 0x0c05b42au: goto P_0c05b42a;
case 0x0c05b42cu: goto P_0c05b42c;
case 0x0c05b42eu: goto P_0c05b42e;
case 0x0c05b430u: goto P_0c05b430;
case 0x0c05b432u: goto P_0c05b432;
case 0x0c05b434u: goto P_0c05b434;
case 0x0c05b436u: goto P_0c05b436;
case 0x0c05b438u: goto P_0c05b438;
case 0x0c05b43au: goto P_0c05b43a;
case 0x0c05b43cu: goto P_0c05b43c;
case 0x0c05b43eu: goto P_0c05b43e;
case 0x0c05b440u: goto P_0c05b440;
case 0x0c05b442u: goto P_0c05b442;
case 0x0c05b444u: goto P_0c05b444;
case 0x0c05b446u: goto P_0c05b446;
case 0x0c05b448u: goto P_0c05b448;
case 0x0c05b44au: goto P_0c05b44a;
case 0x0c05b44cu: goto P_0c05b44c;
case 0x0c05b44eu: goto P_0c05b44e;
case 0x0c05b450u: goto P_0c05b450;
case 0x0c05b452u: goto P_0c05b452;
case 0x0c05b454u: goto P_0c05b454;
case 0x0c05b456u: goto P_0c05b456;
case 0x0c05b458u: goto P_0c05b458;
case 0x0c05b45au: goto P_0c05b45a;
case 0x0c05b45cu: goto P_0c05b45c;
case 0x0c05b45eu: goto P_0c05b45e;
case 0x0c05b460u: goto P_0c05b460;
case 0x0c05b462u: goto P_0c05b462;
case 0x0c05b464u: goto P_0c05b464;
case 0x0c05b466u: goto P_0c05b466;
case 0x0c05b468u: goto P_0c05b468;
case 0x0c05b46au: goto P_0c05b46a;
case 0x0c05b46cu: goto P_0c05b46c;
case 0x0c05b46eu: goto P_0c05b46e;
case 0x0c05b49cu: goto P_0c05b49c;
case 0x0c05b49eu: goto P_0c05b49e;
case 0x0c05b4a0u: goto P_0c05b4a0;
case 0x0c05b4a2u: goto P_0c05b4a2;
case 0x0c05b4a4u: goto P_0c05b4a4;
case 0x0c05b4a6u: goto P_0c05b4a6;
case 0x0c05b4a8u: goto P_0c05b4a8;
case 0x0c05b4aau: goto P_0c05b4aa;
case 0x0c05b4acu: goto P_0c05b4ac;
case 0x0c05b4aeu: goto P_0c05b4ae;
case 0x0c05b4b0u: goto P_0c05b4b0;
case 0x0c05b4b2u: goto P_0c05b4b2;
case 0x0c05b4b4u: goto P_0c05b4b4;
case 0x0c05b4b6u: goto P_0c05b4b6;
case 0x0c05b4b8u: goto P_0c05b4b8;
case 0x0c05b4bau: goto P_0c05b4ba;
case 0x0c05b4bcu: goto P_0c05b4bc;
case 0x0c05b4beu: goto P_0c05b4be;
case 0x0c05b4c0u: goto P_0c05b4c0;
case 0x0c05b4c2u: goto P_0c05b4c2;
case 0x0c05b4c4u: goto P_0c05b4c4;
case 0x0c05b4c6u: goto P_0c05b4c6;
case 0x0c05b4c8u: goto P_0c05b4c8;
case 0x0c05b4cau: goto P_0c05b4ca;
case 0x0c05b4ccu: goto P_0c05b4cc;
case 0x0c05b4ceu: goto P_0c05b4ce;
case 0x0c05b4d0u: goto P_0c05b4d0;
case 0x0c05b4d2u: goto P_0c05b4d2;
case 0x0c05b4d4u: goto P_0c05b4d4;
case 0x0c05b4d6u: goto P_0c05b4d6;
case 0x0c05b4d8u: goto P_0c05b4d8;
case 0x0c05b4dau: goto P_0c05b4da;
case 0x0c05b4dcu: goto P_0c05b4dc;
case 0x0c05b4deu: goto P_0c05b4de;
case 0x0c05b4e0u: goto P_0c05b4e0;
case 0x0c05b4e2u: goto P_0c05b4e2;
case 0x0c05b4e4u: goto P_0c05b4e4;
case 0x0c05b4e6u: goto P_0c05b4e6;
case 0x0c05b4e8u: goto P_0c05b4e8;
case 0x0c05b4eau: goto P_0c05b4ea;
case 0x0c05b4ecu: goto P_0c05b4ec;
case 0x0c05b4eeu: goto P_0c05b4ee;
case 0x0c05b4f0u: goto P_0c05b4f0;
case 0x0c05b4f2u: goto P_0c05b4f2;
case 0x0c05b4f4u: goto P_0c05b4f4;
case 0x0c05b4f6u: goto P_0c05b4f6;
case 0x0c05b4f8u: goto P_0c05b4f8;
case 0x0c05b4fau: goto P_0c05b4fa;
case 0x0c05b4fcu: goto P_0c05b4fc;
case 0x0c05b4feu: goto P_0c05b4fe;
case 0x0c05b500u: goto P_0c05b500;
case 0x0c05b502u: goto P_0c05b502;
case 0x0c05b504u: goto P_0c05b504;
case 0x0c05b506u: goto P_0c05b506;
case 0x0c05b508u: goto P_0c05b508;
case 0x0c05b50au: goto P_0c05b50a;
case 0x0c05b50cu: goto P_0c05b50c;
case 0x0c05b50eu: goto P_0c05b50e;
case 0x0c05b510u: goto P_0c05b510;
case 0x0c05b512u: goto P_0c05b512;
case 0x0c05b514u: goto P_0c05b514;
case 0x0c05b516u: goto P_0c05b516;
case 0x0c05b518u: goto P_0c05b518;
case 0x0c05b51au: goto P_0c05b51a;
case 0x0c05b51cu: goto P_0c05b51c;
case 0x0c05b51eu: goto P_0c05b51e;
case 0x0c05b520u: goto P_0c05b520;
case 0x0c05b522u: goto P_0c05b522;
case 0x0c05b524u: goto P_0c05b524;
case 0x0c05b526u: goto P_0c05b526;
case 0x0c05b528u: goto P_0c05b528;
case 0x0c05b52au: goto P_0c05b52a;
case 0x0c05b52cu: goto P_0c05b52c;
case 0x0c05b52eu: goto P_0c05b52e;
case 0x0c05b530u: goto P_0c05b530;
case 0x0c05b532u: goto P_0c05b532;
case 0x0c05b534u: goto P_0c05b534;
case 0x0c05b536u: goto P_0c05b536;
case 0x0c05b538u: goto P_0c05b538;
case 0x0c05b53au: goto P_0c05b53a;
case 0x0c05b53cu: goto P_0c05b53c;
case 0x0c05b53eu: goto P_0c05b53e;
case 0x0c05b540u: goto P_0c05b540;
case 0x0c05b542u: goto P_0c05b542;
case 0x0c05b544u: goto P_0c05b544;
case 0x0c05b546u: goto P_0c05b546;
case 0x0c05b548u: goto P_0c05b548;
case 0x0c05b54au: goto P_0c05b54a;
case 0x0c05b54cu: goto P_0c05b54c;
case 0x0c05b54eu: goto P_0c05b54e;
case 0x0c05b550u: goto P_0c05b550;
case 0x0c05b552u: goto P_0c05b552;
case 0x0c05b554u: goto P_0c05b554;
case 0x0c05b556u: goto P_0c05b556;
case 0x0c05b558u: goto P_0c05b558;
case 0x0c05b55au: goto P_0c05b55a;
case 0x0c05b55cu: goto P_0c05b55c;
case 0x0c05b55eu: goto P_0c05b55e;
case 0x0c05b560u: goto P_0c05b560;
case 0x0c05b562u: goto P_0c05b562;
case 0x0c05b564u: goto P_0c05b564;
case 0x0c05b566u: goto P_0c05b566;
case 0x0c05b568u: goto P_0c05b568;
case 0x0c05b56au: goto P_0c05b56a;
case 0x0c05b56cu: goto P_0c05b56c;
case 0x0c05b56eu: goto P_0c05b56e;
case 0x0c05b5b0u: goto P_0c05b5b0;
case 0x0c05b5b2u: goto P_0c05b5b2;
case 0x0c05b5b4u: goto P_0c05b5b4;
case 0x0c05b5b6u: goto P_0c05b5b6;
case 0x0c05b5b8u: goto P_0c05b5b8;
case 0x0c05b5bau: goto P_0c05b5ba;
case 0x0c05b5bcu: goto P_0c05b5bc;
case 0x0c05b5beu: goto P_0c05b5be;
case 0x0c05b5c0u: goto P_0c05b5c0;
case 0x0c05b5c2u: goto P_0c05b5c2;
case 0x0c05b5c4u: goto P_0c05b5c4;
case 0x0c05b5c6u: goto P_0c05b5c6;
case 0x0c05b5c8u: goto P_0c05b5c8;
case 0x0c05b5cau: goto P_0c05b5ca;
case 0x0c05b5ccu: goto P_0c05b5cc;
case 0x0c05b5ceu: goto P_0c05b5ce;
case 0x0c05b5d0u: goto P_0c05b5d0;
case 0x0c05b5d2u: goto P_0c05b5d2;
case 0x0c05b5d4u: goto P_0c05b5d4;
case 0x0c05b5d6u: goto P_0c05b5d6;
case 0x0c05b5d8u: goto P_0c05b5d8;
case 0x0c05b5dau: goto P_0c05b5da;
case 0x0c05b5dcu: goto P_0c05b5dc;
case 0x0c05b5deu: goto P_0c05b5de;
case 0x0c05b5e0u: goto P_0c05b5e0;
case 0x0c05b5e2u: goto P_0c05b5e2;
case 0x0c05b5e4u: goto P_0c05b5e4;
case 0x0c05b5e6u: goto P_0c05b5e6;
case 0x0c05b5e8u: goto P_0c05b5e8;
case 0x0c05b5eau: goto P_0c05b5ea;
case 0x0c05b5ecu: goto P_0c05b5ec;
case 0x0c05b5eeu: goto P_0c05b5ee;
case 0x0c05b5f0u: goto P_0c05b5f0;
case 0x0c05b5f2u: goto P_0c05b5f2;
case 0x0c05b5f4u: goto P_0c05b5f4;
case 0x0c05b5f6u: goto P_0c05b5f6;
case 0x0c05b5f8u: goto P_0c05b5f8;
case 0x0c05b5fau: goto P_0c05b5fa;
case 0x0c05b5fcu: goto P_0c05b5fc;
case 0x0c05b5feu: goto P_0c05b5fe;
case 0x0c05b600u: goto P_0c05b600;
case 0x0c05b602u: goto P_0c05b602;
case 0x0c05b604u: goto P_0c05b604;
case 0x0c05b606u: goto P_0c05b606;
case 0x0c05b608u: goto P_0c05b608;
case 0x0c05b60au: goto P_0c05b60a;
case 0x0c05b60cu: goto P_0c05b60c;
case 0x0c05b60eu: goto P_0c05b60e;
case 0x0c05b610u: goto P_0c05b610;
case 0x0c05b612u: goto P_0c05b612;
case 0x0c05b614u: goto P_0c05b614;
case 0x0c05b616u: goto P_0c05b616;
case 0x0c05b618u: goto P_0c05b618;
case 0x0c05b61au: goto P_0c05b61a;
case 0x0c05b61cu: goto P_0c05b61c;
case 0x0c05b61eu: goto P_0c05b61e;
case 0x0c05b620u: goto P_0c05b620;
case 0x0c05b622u: goto P_0c05b622;
case 0x0c05b624u: goto P_0c05b624;
case 0x0c05b626u: goto P_0c05b626;
case 0x0c05b628u: goto P_0c05b628;
case 0x0c05b62au: goto P_0c05b62a;
case 0x0c05b62cu: goto P_0c05b62c;
case 0x0c05b62eu: goto P_0c05b62e;
case 0x0c05b630u: goto P_0c05b630;
case 0x0c05b632u: goto P_0c05b632;
case 0x0c05b634u: goto P_0c05b634;
case 0x0c05b636u: goto P_0c05b636;
case 0x0c05b638u: goto P_0c05b638;
case 0x0c05b63au: goto P_0c05b63a;
case 0x0c05b63cu: goto P_0c05b63c;
case 0x0c05b63eu: goto P_0c05b63e;
case 0x0c05b640u: goto P_0c05b640;
case 0x0c05b642u: goto P_0c05b642;
case 0x0c05b644u: goto P_0c05b644;
case 0x0c05b646u: goto P_0c05b646;
case 0x0c05b648u: goto P_0c05b648;
case 0x0c05b64au: goto P_0c05b64a;
case 0x0c05b64cu: goto P_0c05b64c;
case 0x0c05b64eu: goto P_0c05b64e;
case 0x0c05b650u: goto P_0c05b650;
case 0x0c05b652u: goto P_0c05b652;
case 0x0c05b654u: goto P_0c05b654;
case 0x0c05b656u: goto P_0c05b656;
case 0x0c05b658u: goto P_0c05b658;
case 0x0c05b65au: goto P_0c05b65a;
case 0x0c05b65cu: goto P_0c05b65c;
case 0x0c05b65eu: goto P_0c05b65e;
case 0x0c05b660u: goto P_0c05b660;
case 0x0c05b662u: goto P_0c05b662;
case 0x0c05b664u: goto P_0c05b664;
case 0x0c05b666u: goto P_0c05b666;
case 0x0c05b668u: goto P_0c05b668;
case 0x0c05b66au: goto P_0c05b66a;
case 0x0c05b66cu: goto P_0c05b66c;
case 0x0c05b66eu: goto P_0c05b66e;
case 0x0c05b670u: goto P_0c05b670;
case 0x0c05b672u: goto P_0c05b672;
case 0x0c05b674u: goto P_0c05b674;
case 0x0c05b676u: goto P_0c05b676;
case 0x0c05b678u: goto P_0c05b678;
case 0x0c05b67au: goto P_0c05b67a;
case 0x0c05b67cu: goto P_0c05b67c;
case 0x0c05b67eu: goto P_0c05b67e;
case 0x0c05b680u: goto P_0c05b680;
case 0x0c05b682u: goto P_0c05b682;
case 0x0c05b684u: goto P_0c05b684;
case 0x0c05b686u: goto P_0c05b686;
case 0x0c05b688u: goto P_0c05b688;
case 0x0c05b68au: goto P_0c05b68a;
case 0x0c05b68cu: goto P_0c05b68c;
case 0x0c05b6b8u: goto P_0c05b6b8;
case 0x0c05b6bau: goto P_0c05b6ba;
case 0x0c05b6bcu: goto P_0c05b6bc;
case 0x0c05b6beu: goto P_0c05b6be;
case 0x0c05b6c0u: goto P_0c05b6c0;
case 0x0c05b6c2u: goto P_0c05b6c2;
case 0x0c05b6c4u: goto P_0c05b6c4;
case 0x0c05b6c6u: goto P_0c05b6c6;
case 0x0c05b6c8u: goto P_0c05b6c8;
case 0x0c05b6cau: goto P_0c05b6ca;
case 0x0c05b6ccu: goto P_0c05b6cc;
case 0x0c05b6ceu: goto P_0c05b6ce;
case 0x0c05b6d0u: goto P_0c05b6d0;
case 0x0c05b6d2u: goto P_0c05b6d2;
case 0x0c05b6d4u: goto P_0c05b6d4;
case 0x0c05b6d6u: goto P_0c05b6d6;
case 0x0c05b6d8u: goto P_0c05b6d8;
case 0x0c05b6dau: goto P_0c05b6da;
case 0x0c05b6dcu: goto P_0c05b6dc;
case 0x0c05b6deu: goto P_0c05b6de;
case 0x0c05b6e0u: goto P_0c05b6e0;
case 0x0c05b6e2u: goto P_0c05b6e2;
case 0x0c05b6e4u: goto P_0c05b6e4;
case 0x0c05b6e6u: goto P_0c05b6e6;
case 0x0c05b6e8u: goto P_0c05b6e8;
case 0x0c05b6eau: goto P_0c05b6ea;
case 0x0c05b6ecu: goto P_0c05b6ec;
case 0x0c05b6eeu: goto P_0c05b6ee;
case 0x0c05b6f0u: goto P_0c05b6f0;
case 0x0c05b6f2u: goto P_0c05b6f2;
case 0x0c05b6f4u: goto P_0c05b6f4;
case 0x0c05b6f6u: goto P_0c05b6f6;
case 0x0c05b6f8u: goto P_0c05b6f8;
case 0x0c05b6fau: goto P_0c05b6fa;
case 0x0c05b6fcu: goto P_0c05b6fc;
case 0x0c05b6feu: goto P_0c05b6fe;
case 0x0c05b700u: goto P_0c05b700;
case 0x0c05b702u: goto P_0c05b702;
case 0x0c05b704u: goto P_0c05b704;
case 0x0c05b706u: goto P_0c05b706;
case 0x0c05b708u: goto P_0c05b708;
case 0x0c05b70au: goto P_0c05b70a;
case 0x0c05b70cu: goto P_0c05b70c;
case 0x0c05b70eu: goto P_0c05b70e;
case 0x0c05b710u: goto P_0c05b710;
case 0x0c05b712u: goto P_0c05b712;
case 0x0c05b714u: goto P_0c05b714;
case 0x0c05b716u: goto P_0c05b716;
case 0x0c05b718u: goto P_0c05b718;
case 0x0c05b71au: goto P_0c05b71a;
case 0x0c05b71cu: goto P_0c05b71c;
case 0x0c05b71eu: goto P_0c05b71e;
case 0x0c05b720u: goto P_0c05b720;
case 0x0c05b722u: goto P_0c05b722;
case 0x0c05b724u: goto P_0c05b724;
case 0x0c05b726u: goto P_0c05b726;
case 0x0c05b728u: goto P_0c05b728;
case 0x0c05b72au: goto P_0c05b72a;
case 0x0c05b72cu: goto P_0c05b72c;
case 0x0c05b72eu: goto P_0c05b72e;
case 0x0c05b730u: goto P_0c05b730;
case 0x0c05b732u: goto P_0c05b732;
case 0x0c05b734u: goto P_0c05b734;
case 0x0c05b736u: goto P_0c05b736;
case 0x0c05b738u: goto P_0c05b738;
case 0x0c05b73au: goto P_0c05b73a;
case 0x0c05b73cu: goto P_0c05b73c;
case 0x0c05b73eu: goto P_0c05b73e;
case 0x0c05b740u: goto P_0c05b740;
case 0x0c05b742u: goto P_0c05b742;
case 0x0c05b744u: goto P_0c05b744;
case 0x0c05b746u: goto P_0c05b746;
case 0x0c05b748u: goto P_0c05b748;
case 0x0c05b74au: goto P_0c05b74a;
case 0x0c05b74cu: goto P_0c05b74c;
case 0x0c05b74eu: goto P_0c05b74e;
case 0x0c05b750u: goto P_0c05b750;
case 0x0c05b752u: goto P_0c05b752;
case 0x0c05b754u: goto P_0c05b754;
case 0x0c05b756u: goto P_0c05b756;
case 0x0c05b758u: goto P_0c05b758;
case 0x0c05b75au: goto P_0c05b75a;
case 0x0c05b75cu: goto P_0c05b75c;
case 0x0c05b75eu: goto P_0c05b75e;
case 0x0c05b760u: goto P_0c05b760;
case 0x0c05b762u: goto P_0c05b762;
case 0x0c05b764u: goto P_0c05b764;
case 0x0c05b766u: goto P_0c05b766;
case 0x0c05b768u: goto P_0c05b768;
case 0x0c05b76au: goto P_0c05b76a;
case 0x0c05b76cu: goto P_0c05b76c;
case 0x0c05b76eu: goto P_0c05b76e;
case 0x0c05b770u: goto P_0c05b770;
case 0x0c05b772u: goto P_0c05b772;
case 0x0c05b774u: goto P_0c05b774;
case 0x0c05b776u: goto P_0c05b776;
case 0x0c05b778u: goto P_0c05b778;
case 0x0c05b77au: goto P_0c05b77a;
case 0x0c05b77cu: goto P_0c05b77c;
case 0x0c05b7c4u: goto P_0c05b7c4;
case 0x0c05b7c6u: goto P_0c05b7c6;
case 0x0c05b7c8u: goto P_0c05b7c8;
case 0x0c05b7cau: goto P_0c05b7ca;
case 0x0c05b7ccu: goto P_0c05b7cc;
case 0x0c05b7ceu: goto P_0c05b7ce;
case 0x0c05b7d0u: goto P_0c05b7d0;
case 0x0c05b7d2u: goto P_0c05b7d2;
case 0x0c05b7d4u: goto P_0c05b7d4;
case 0x0c05b7d6u: goto P_0c05b7d6;
case 0x0c05b7d8u: goto P_0c05b7d8;
case 0x0c05b7dau: goto P_0c05b7da;
case 0x0c05b7dcu: goto P_0c05b7dc;
case 0x0c05b7deu: goto P_0c05b7de;
case 0x0c05b7e0u: goto P_0c05b7e0;
case 0x0c05b7e2u: goto P_0c05b7e2;
case 0x0c05b7e4u: goto P_0c05b7e4;
case 0x0c05b7e6u: goto P_0c05b7e6;
case 0x0c05b7e8u: goto P_0c05b7e8;
case 0x0c05b7eau: goto P_0c05b7ea;
case 0x0c05b7ecu: goto P_0c05b7ec;
case 0x0c05b7eeu: goto P_0c05b7ee;
case 0x0c05b7f0u: goto P_0c05b7f0;
case 0x0c05b7f2u: goto P_0c05b7f2;
case 0x0c05b7f4u: goto P_0c05b7f4;
case 0x0c05b7f6u: goto P_0c05b7f6;
case 0x0c05b7f8u: goto P_0c05b7f8;
case 0x0c05b7fau: goto P_0c05b7fa;
case 0x0c05b7fcu: goto P_0c05b7fc;
case 0x0c05b7feu: goto P_0c05b7fe;
case 0x0c05b800u: goto P_0c05b800;
case 0x0c05b802u: goto P_0c05b802;
case 0x0c05b804u: goto P_0c05b804;
case 0x0c05b806u: goto P_0c05b806;
case 0x0c05b808u: goto P_0c05b808;
case 0x0c05b80au: goto P_0c05b80a;
case 0x0c05b80cu: goto P_0c05b80c;
case 0x0c05b80eu: goto P_0c05b80e;
case 0x0c05b810u: goto P_0c05b810;
case 0x0c05b812u: goto P_0c05b812;
case 0x0c05b814u: goto P_0c05b814;
case 0x0c05b816u: goto P_0c05b816;
case 0x0c05b818u: goto P_0c05b818;
case 0x0c05b81au: goto P_0c05b81a;
case 0x0c05b81cu: goto P_0c05b81c;
case 0x0c05b81eu: goto P_0c05b81e;
case 0x0c05b820u: goto P_0c05b820;
case 0x0c05b822u: goto P_0c05b822;
case 0x0c05b824u: goto P_0c05b824;
case 0x0c05b826u: goto P_0c05b826;
case 0x0c05b828u: goto P_0c05b828;
case 0x0c05b82au: goto P_0c05b82a;
case 0x0c05b82cu: goto P_0c05b82c;
case 0x0c05b82eu: goto P_0c05b82e;
case 0x0c05b830u: goto P_0c05b830;
case 0x0c05b832u: goto P_0c05b832;
case 0x0c05b834u: goto P_0c05b834;
case 0x0c05b836u: goto P_0c05b836;
case 0x0c05b838u: goto P_0c05b838;
case 0x0c05b83au: goto P_0c05b83a;
case 0x0c05b83cu: goto P_0c05b83c;
case 0x0c05b83eu: goto P_0c05b83e;
case 0x0c05b840u: goto P_0c05b840;
case 0x0c05b842u: goto P_0c05b842;
case 0x0c05b844u: goto P_0c05b844;
case 0x0c05b846u: goto P_0c05b846;
case 0x0c05b848u: goto P_0c05b848;
case 0x0c05b84au: goto P_0c05b84a;
case 0x0c05b84cu: goto P_0c05b84c;
case 0x0c05b84eu: goto P_0c05b84e;
case 0x0c05b850u: goto P_0c05b850;
case 0x0c05b852u: goto P_0c05b852;
case 0x0c05b854u: goto P_0c05b854;
case 0x0c05b856u: goto P_0c05b856;
case 0x0c05b858u: goto P_0c05b858;
case 0x0c05b85au: goto P_0c05b85a;
case 0x0c05b85cu: goto P_0c05b85c;
case 0x0c05b85eu: goto P_0c05b85e;
case 0x0c05b860u: goto P_0c05b860;
case 0x0c05b862u: goto P_0c05b862;
case 0x0c05b864u: goto P_0c05b864;
case 0x0c05b866u: goto P_0c05b866;
case 0x0c05b868u: goto P_0c05b868;
case 0x0c05b86au: goto P_0c05b86a;
case 0x0c05b86cu: goto P_0c05b86c;
case 0x0c05b86eu: goto P_0c05b86e;
case 0x0c05b870u: goto P_0c05b870;
case 0x0c05b872u: goto P_0c05b872;
case 0x0c05b874u: goto P_0c05b874;
case 0x0c05b876u: goto P_0c05b876;
case 0x0c05b878u: goto P_0c05b878;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05b20e: /* original 4f22, guest PC 0x0c05b20e */
if(!s->budget--) { s->failed_pc=0x0c05b20eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05b210;
P_0c05b210: /* original d237, guest PC 0x0c05b210 */
if(!s->budget--) { s->failed_pc=0x0c05b210u; return 0; }
r[2]=read(ram,0x0c05b2f0u,4);
goto P_0c05b212;
P_0c05b212: /* original 7fe0, guest PC 0x0c05b212 */
if(!s->budget--) { s->failed_pc=0x0c05b212u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c05b214;
P_0c05b214: /* original 0bde, guest PC 0x0c05b214 */
if(!s->budget--) { s->failed_pc=0x0c05b214u; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c05b216;
P_0c05b216: /* original 61f3, guest PC 0x0c05b216 */
if(!s->budget--) { s->failed_pc=0x0c05b216u; return 0; }
r[1]=r[15];
goto P_0c05b218;
P_0c05b218: /* original 7004, guest PC 0x0c05b218 */
if(!s->budget--) { s->failed_pc=0x0c05b218u; return 0; }
r[0]+=0x00000004u;
goto P_0c05b21a;
P_0c05b21a: /* original 7110, guest PC 0x0c05b21a */
if(!s->budget--) { s->failed_pc=0x0c05b21au; return 0; }
r[1]+=0x00000010u;
goto P_0c05b21c;
P_0c05b21c: /* original 0ede, guest PC 0x0c05b21c */
if(!s->budget--) { s->failed_pc=0x0c05b21cu; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c05b21e;
P_0c05b21e: /* original 7004, guest PC 0x0c05b21e */
if(!s->budget--) { s->failed_pc=0x0c05b21eu; return 0; }
r[0]+=0x00000004u;
goto P_0c05b220;
P_0c05b220: /* original 03de, guest PC 0x0c05b220 */
if(!s->budget--) { s->failed_pc=0x0c05b220u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05b222;
P_0c05b222: /* original 2f32, guest PC 0x0c05b222 */
if(!s->budget--) { s->failed_pc=0x0c05b222u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05b224;
P_0c05b224: /* original 9061, guest PC 0x0c05b224 */
if(!s->budget--) { s->failed_pc=0x0c05b224u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b2eau,2);
goto P_0c05b226;
P_0c05b226: /* original 0ade, guest PC 0x0c05b226 */
if(!s->budget--) { s->failed_pc=0x0c05b226u; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c05b228;
P_0c05b228: /* original d332, guest PC 0x0c05b228 */
if(!s->budget--) { s->failed_pc=0x0c05b228u; return 0; }
r[3]=read(ram,0x0c05b2f4u,4);
goto P_0c05b22a;
P_0c05b22a: /* original 430b, guest PC 0x0c05b22a */
if(!s->budget--) { s->failed_pc=0x0c05b22au; return 0; }
target=r[3];
r[16]=0x0c05b22eu;
r[0]=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05b22eu) { target=s->pc; goto dispatch; }
goto P_0c05b22e;
P_0c05b22c: /* original e010, guest PC 0x0c05b22c */
if(!s->budget--) { s->failed_pc=0x0c05b22cu; return 0; }
r[0]=0x00000010u;
goto P_0c05b22e;
P_0c05b22e: /* original e101, guest PC 0x0c05b22e */
if(!s->budget--) { s->failed_pc=0x0c05b22eu; return 0; }
r[1]=0x00000001u;
goto P_0c05b230;
P_0c05b230: /* original 6cd2, guest PC 0x0c05b230 */
if(!s->budget--) { s->failed_pc=0x0c05b230u; return 0; }
tmp=read(ram,r[13],4);
r[12]=tmp;
goto P_0c05b232;
P_0c05b232: /* original d931, guest PC 0x0c05b232 */
if(!s->budget--) { s->failed_pc=0x0c05b232u; return 0; }
r[9]=read(ram,0x0c05b2f8u,4);
goto P_0c05b234;
P_0c05b234: /* original 21c8, guest PC 0x0c05b234 */
if(!s->budget--) { s->failed_pc=0x0c05b234u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c05b236;
P_0c05b236: /* original 8907, guest PC 0x0c05b236 */
if(!s->budget--) { s->failed_pc=0x0c05b236u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b248; }
goto P_0c05b238;
P_0c05b238: /* original 60b3, guest PC 0x0c05b238 */
if(!s->budget--) { s->failed_pc=0x0c05b238u; return 0; }
r[0]=r[11];
goto P_0c05b23a;
P_0c05b23a: /* original 0009, guest PC 0x0c05b23a */
if(!s->budget--) { s->failed_pc=0x0c05b23au; return 0; }
goto P_0c05b23c;
P_0c05b23c: /* original 51d5, guest PC 0x0c05b23c */
if(!s->budget--) { s->failed_pc=0x0c05b23cu; return 0; }
r[1]=read(ram,r[13]+20,4);
goto P_0c05b23e;
P_0c05b23e: /* original 2099, guest PC 0x0c05b23e */
if(!s->budget--) { s->failed_pc=0x0c05b23eu; return 0; }
r[0]&=r[9];
goto P_0c05b240;
P_0c05b240: /* original e31d, guest PC 0x0c05b240 */
if(!s->budget--) { s->failed_pc=0x0c05b240u; return 0; }
r[3]=0x0000001du;
goto P_0c05b242;
P_0c05b242: /* original 413d, guest PC 0x0c05b242 */
if(!s->budget--) { s->failed_pc=0x0c05b242u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?r[1]>>((-r[3])&31u):0):r[1]<<(r[3]&31u);
goto P_0c05b244;
P_0c05b244: /* original 6b03, guest PC 0x0c05b244 */
if(!s->budget--) { s->failed_pc=0x0c05b244u; return 0; }
r[11]=r[0];
goto P_0c05b246;
P_0c05b246: /* original 2b1b, guest PC 0x0c05b246 */
if(!s->budget--) { s->failed_pc=0x0c05b246u; return 0; }
r[11]|=r[1];
goto P_0c05b248;
P_0c05b248: /* original e302, guest PC 0x0c05b248 */
if(!s->budget--) { s->failed_pc=0x0c05b248u; return 0; }
r[3]=0x00000002u;
goto P_0c05b24a;
P_0c05b24a: /* original 23c8, guest PC 0x0c05b24a */
if(!s->budget--) { s->failed_pc=0x0c05b24au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b24c;
P_0c05b24c: /* original 8906, guest PC 0x0c05b24c */
if(!s->budget--) { s->failed_pc=0x0c05b24cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b25c; }
goto P_0c05b24e;
P_0c05b24e: /* original e31b, guest PC 0x0c05b24e */
if(!s->budget--) { s->failed_pc=0x0c05b24eu; return 0; }
r[3]=0x0000001bu;
goto P_0c05b250;
P_0c05b250: /* original 52d6, guest PC 0x0c05b250 */
if(!s->budget--) { s->failed_pc=0x0c05b250u; return 0; }
r[2]=read(ram,r[13]+24,4);
goto P_0c05b252;
P_0c05b252: /* original d12a, guest PC 0x0c05b252 */
if(!s->budget--) { s->failed_pc=0x0c05b252u; return 0; }
r[1]=read(ram,0x0c05b2fcu,4);
goto P_0c05b254;
P_0c05b254: /* original 21b9, guest PC 0x0c05b254 */
if(!s->budget--) { s->failed_pc=0x0c05b254u; return 0; }
r[1]&=r[11];
goto P_0c05b256;
P_0c05b256: /* original 423d, guest PC 0x0c05b256 */
if(!s->budget--) { s->failed_pc=0x0c05b256u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05b258;
P_0c05b258: /* original 6b13, guest PC 0x0c05b258 */
if(!s->budget--) { s->failed_pc=0x0c05b258u; return 0; }
r[11]=r[1];
goto P_0c05b25a;
P_0c05b25a: /* original 2b2b, guest PC 0x0c05b25a */
if(!s->budget--) { s->failed_pc=0x0c05b25au; return 0; }
r[11]|=r[2];
goto P_0c05b25c;
P_0c05b25c: /* original d728, guest PC 0x0c05b25c */
if(!s->budget--) { s->failed_pc=0x0c05b25cu; return 0; }
r[7]=read(ram,0x0c05b300u,4);
goto P_0c05b25e;
P_0c05b25e: /* original e320, guest PC 0x0c05b25e */
if(!s->budget--) { s->failed_pc=0x0c05b25eu; return 0; }
r[3]=0x00000020u;
goto P_0c05b260;
P_0c05b260: /* original 23c8, guest PC 0x0c05b260 */
if(!s->budget--) { s->failed_pc=0x0c05b260u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b262;
P_0c05b262: /* original 8906, guest PC 0x0c05b262 */
if(!s->budget--) { s->failed_pc=0x0c05b262u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b272; }
goto P_0c05b264;
P_0c05b264: /* original 51da, guest PC 0x0c05b264 */
if(!s->budget--) { s->failed_pc=0x0c05b264u; return 0; }
r[1]=read(ram,r[13]+40,4);
goto P_0c05b266;
P_0c05b266: /* original 2118, guest PC 0x0c05b266 */
if(!s->budget--) { s->failed_pc=0x0c05b266u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b268;
P_0c05b268: /* original 8901, guest PC 0x0c05b268 */
if(!s->budget--) { s->failed_pc=0x0c05b268u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b26e; }
goto P_0c05b26a;
P_0c05b26a: /* original a002, guest PC 0x0c05b26a */
if(!s->budget--) { s->failed_pc=0x0c05b26au; return 0; }
r[11]|=r[7];
goto P_0c05b272;
P_0c05b26c: /* original 2b7b, guest PC 0x0c05b26c */
if(!s->budget--) { s->failed_pc=0x0c05b26cu; return 0; }
r[11]|=r[7];
goto P_0c05b26e;
P_0c05b26e: /* original d225, guest PC 0x0c05b26e */
if(!s->budget--) { s->failed_pc=0x0c05b26eu; return 0; }
r[2]=read(ram,0x0c05b304u,4);
goto P_0c05b270;
P_0c05b270: /* original 2b29, guest PC 0x0c05b270 */
if(!s->budget--) { s->failed_pc=0x0c05b270u; return 0; }
r[11]&=r[2];
goto P_0c05b272;
P_0c05b272: /* original e808, guest PC 0x0c05b272 */
if(!s->budget--) { s->failed_pc=0x0c05b272u; return 0; }
r[8]=0x00000008u;
goto P_0c05b274;
P_0c05b274: /* original 28c9, guest PC 0x0c05b274 */
if(!s->budget--) { s->failed_pc=0x0c05b274u; return 0; }
r[8]&=r[12];
goto P_0c05b276;
P_0c05b276: /* original 2888, guest PC 0x0c05b276 */
if(!s->budget--) { s->failed_pc=0x0c05b276u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c05b278;
P_0c05b278: /* original 8908, guest PC 0x0c05b278 */
if(!s->budget--) { s->failed_pc=0x0c05b278u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b28c; }
goto P_0c05b27a;
P_0c05b27a: /* original d223, guest PC 0x0c05b27a */
if(!s->budget--) { s->failed_pc=0x0c05b27au; return 0; }
r[2]=read(ram,0x0c05b308u,4);
goto P_0c05b27c;
P_0c05b27c: /* original 53d8, guest PC 0x0c05b27c */
if(!s->budget--) { s->failed_pc=0x0c05b27cu; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c05b27e;
P_0c05b27e: /* original 22b9, guest PC 0x0c05b27e */
if(!s->budget--) { s->failed_pc=0x0c05b27eu; return 0; }
r[2]&=r[11];
goto P_0c05b280;
P_0c05b280: /* original 4301, guest PC 0x0c05b280 */
if(!s->budget--) { s->failed_pc=0x0c05b280u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c05b282;
P_0c05b282: /* original 4328, guest PC 0x0c05b282 */
if(!s->budget--) { s->failed_pc=0x0c05b282u; return 0; }
r[3]<<=16;
goto P_0c05b284;
P_0c05b284: /* original 4318, guest PC 0x0c05b284 */
if(!s->budget--) { s->failed_pc=0x0c05b284u; return 0; }
r[3]<<=8;
goto P_0c05b286;
P_0c05b286: /* original 4300, guest PC 0x0c05b286 */
if(!s->budget--) { s->failed_pc=0x0c05b286u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05b288;
P_0c05b288: /* original 6b23, guest PC 0x0c05b288 */
if(!s->budget--) { s->failed_pc=0x0c05b288u; return 0; }
r[11]=r[2];
goto P_0c05b28a;
P_0c05b28a: /* original 2b3b, guest PC 0x0c05b28a */
if(!s->budget--) { s->failed_pc=0x0c05b28au; return 0; }
r[11]|=r[3];
goto P_0c05b28c;
P_0c05b28c: /* original d61f, guest PC 0x0c05b28c */
if(!s->budget--) { s->failed_pc=0x0c05b28cu; return 0; }
r[6]=read(ram,0x0c05b30cu,4);
goto P_0c05b28e;
P_0c05b28e: /* original 922d, guest PC 0x0c05b28e */
if(!s->budget--) { s->failed_pc=0x0c05b28eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b2ecu,2);
goto P_0c05b290;
P_0c05b290: /* original 22c9, guest PC 0x0c05b290 */
if(!s->budget--) { s->failed_pc=0x0c05b290u; return 0; }
r[2]&=r[12];
goto P_0c05b292;
P_0c05b292: /* original 2228, guest PC 0x0c05b292 */
if(!s->budget--) { s->failed_pc=0x0c05b292u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b294;
P_0c05b294: /* original 8d08, guest PC 0x0c05b294 */
if(!s->budget--) { s->failed_pc=0x0c05b294u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[2],4);
if(cond) { goto P_0c05b2a8; }
goto P_0c05b298;
P_0c05b296: /* original 1f23, guest PC 0x0c05b296 */
if(!s->budget--) { s->failed_pc=0x0c05b296u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c05b298;
P_0c05b298: /* original 61b3, guest PC 0x0c05b298 */
if(!s->budget--) { s->failed_pc=0x0c05b298u; return 0; }
r[1]=r[11];
goto P_0c05b29a;
P_0c05b29a: /* original 2169, guest PC 0x0c05b29a */
if(!s->budget--) { s->failed_pc=0x0c05b29au; return 0; }
r[1]&=r[6];
goto P_0c05b29c;
P_0c05b29c: /* original e040, guest PC 0x0c05b29c */
if(!s->budget--) { s->failed_pc=0x0c05b29cu; return 0; }
r[0]=0x00000040u;
goto P_0c05b29e;
P_0c05b29e: /* original 6b13, guest PC 0x0c05b29e */
if(!s->budget--) { s->failed_pc=0x0c05b29eu; return 0; }
r[11]=r[1];
goto P_0c05b2a0;
P_0c05b2a0: /* original 03de, guest PC 0x0c05b2a0 */
if(!s->budget--) { s->failed_pc=0x0c05b2a0u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05b2a2;
P_0c05b2a2: /* original 4328, guest PC 0x0c05b2a2 */
if(!s->budget--) { s->failed_pc=0x0c05b2a2u; return 0; }
r[3]<<=16;
goto P_0c05b2a4;
P_0c05b2a4: /* original 4318, guest PC 0x0c05b2a4 */
if(!s->budget--) { s->failed_pc=0x0c05b2a4u; return 0; }
r[3]<<=8;
goto P_0c05b2a6;
P_0c05b2a6: /* original 2b3b, guest PC 0x0c05b2a6 */
if(!s->budget--) { s->failed_pc=0x0c05b2a6u; return 0; }
r[11]|=r[3];
goto P_0c05b2a8;
P_0c05b2a8: /* original 2888, guest PC 0x0c05b2a8 */
if(!s->budget--) { s->failed_pc=0x0c05b2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c05b2aa;
P_0c05b2aa: /* original 8907, guest PC 0x0c05b2aa */
if(!s->budget--) { s->failed_pc=0x0c05b2aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b2bc; }
goto P_0c05b2ac;
P_0c05b2ac: /* original d218, guest PC 0x0c05b2ac */
if(!s->budget--) { s->failed_pc=0x0c05b2acu; return 0; }
r[2]=read(ram,0x0c05b310u,4);
goto P_0c05b2ae;
P_0c05b2ae: /* original e317, guest PC 0x0c05b2ae */
if(!s->budget--) { s->failed_pc=0x0c05b2aeu; return 0; }
r[3]=0x00000017u;
goto P_0c05b2b0;
P_0c05b2b0: /* original 50d8, guest PC 0x0c05b2b0 */
if(!s->budget--) { s->failed_pc=0x0c05b2b0u; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c05b2b2;
P_0c05b2b2: /* original 22b9, guest PC 0x0c05b2b2 */
if(!s->budget--) { s->failed_pc=0x0c05b2b2u; return 0; }
r[2]&=r[11];
goto P_0c05b2b4;
P_0c05b2b4: /* original c901, guest PC 0x0c05b2b4 */
if(!s->budget--) { s->failed_pc=0x0c05b2b4u; return 0; }
r[0]&=1u;
goto P_0c05b2b6;
P_0c05b2b6: /* original 403d, guest PC 0x0c05b2b6 */
if(!s->budget--) { s->failed_pc=0x0c05b2b6u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c05b2b8;
P_0c05b2b8: /* original 6b23, guest PC 0x0c05b2b8 */
if(!s->budget--) { s->failed_pc=0x0c05b2b8u; return 0; }
r[11]=r[2];
goto P_0c05b2ba;
P_0c05b2ba: /* original 2b0b, guest PC 0x0c05b2ba */
if(!s->budget--) { s->failed_pc=0x0c05b2bau; return 0; }
r[11]|=r[0];
goto P_0c05b2bc;
P_0c05b2bc: /* original d215, guest PC 0x0c05b2bc */
if(!s->budget--) { s->failed_pc=0x0c05b2bcu; return 0; }
r[2]=read(ram,0x0c05b314u,4);
goto P_0c05b2be;
P_0c05b2be: /* original 22c9, guest PC 0x0c05b2be */
if(!s->budget--) { s->failed_pc=0x0c05b2beu; return 0; }
r[2]&=r[12];
goto P_0c05b2c0;
P_0c05b2c0: /* original 2228, guest PC 0x0c05b2c0 */
if(!s->budget--) { s->failed_pc=0x0c05b2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b2c2;
P_0c05b2c2: /* original 8d07, guest PC 0x0c05b2c2 */
if(!s->budget--) { s->failed_pc=0x0c05b2c2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c05b2d4; }
goto P_0c05b2c6;
P_0c05b2c4: /* original 1f22, guest PC 0x0c05b2c4 */
if(!s->budget--) { s->failed_pc=0x0c05b2c4u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c05b2c6;
P_0c05b2c6: /* original e316, guest PC 0x0c05b2c6 */
if(!s->budget--) { s->failed_pc=0x0c05b2c6u; return 0; }
r[3]=0x00000016u;
goto P_0c05b2c8;
P_0c05b2c8: /* original 52d4, guest PC 0x0c05b2c8 */
if(!s->budget--) { s->failed_pc=0x0c05b2c8u; return 0; }
r[2]=read(ram,r[13]+16,4);
goto P_0c05b2ca;
P_0c05b2ca: /* original d113, guest PC 0x0c05b2ca */
if(!s->budget--) { s->failed_pc=0x0c05b2cau; return 0; }
r[1]=read(ram,0x0c05b318u,4);
goto P_0c05b2cc;
P_0c05b2cc: /* original 21b9, guest PC 0x0c05b2cc */
if(!s->budget--) { s->failed_pc=0x0c05b2ccu; return 0; }
r[1]&=r[11];
goto P_0c05b2ce;
P_0c05b2ce: /* original 423d, guest PC 0x0c05b2ce */
if(!s->budget--) { s->failed_pc=0x0c05b2ceu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05b2d0;
P_0c05b2d0: /* original 6b13, guest PC 0x0c05b2d0 */
if(!s->budget--) { s->failed_pc=0x0c05b2d0u; return 0; }
r[11]=r[1];
goto P_0c05b2d2;
P_0c05b2d2: /* original 2b2b, guest PC 0x0c05b2d2 */
if(!s->budget--) { s->failed_pc=0x0c05b2d2u; return 0; }
r[11]|=r[2];
goto P_0c05b2d4;
P_0c05b2d4: /* original 63c3, guest PC 0x0c05b2d4 */
if(!s->budget--) { s->failed_pc=0x0c05b2d4u; return 0; }
r[3]=r[12];
goto P_0c05b2d6;
P_0c05b2d6: /* original 2378, guest PC 0x0c05b2d6 */
if(!s->budget--) { s->failed_pc=0x0c05b2d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c05b2d8;
P_0c05b2d8: /* original 8924, guest PC 0x0c05b2d8 */
if(!s->budget--) { s->failed_pc=0x0c05b2d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b324; }
goto P_0c05b2da;
P_0c05b2da: /* original 9008, guest PC 0x0c05b2da */
if(!s->budget--) { s->failed_pc=0x0c05b2dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b2eeu,2);
goto P_0c05b2dc;
P_0c05b2dc: /* original 01de, guest PC 0x0c05b2dc */
if(!s->budget--) { s->failed_pc=0x0c05b2dcu; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05b2de;
P_0c05b2de: /* original 2118, guest PC 0x0c05b2de */
if(!s->budget--) { s->failed_pc=0x0c05b2deu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b2e0;
P_0c05b2e0: /* original 891e, guest PC 0x0c05b2e0 */
if(!s->budget--) { s->failed_pc=0x0c05b2e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b320; }
goto P_0c05b2e2;
P_0c05b2e2: /* original d20e, guest PC 0x0c05b2e2 */
if(!s->budget--) { s->failed_pc=0x0c05b2e2u; return 0; }
r[2]=read(ram,0x0c05b31cu,4);
goto P_0c05b2e4;
P_0c05b2e4: /* original a01e, guest PC 0x0c05b2e4 */
if(!s->budget--) { s->failed_pc=0x0c05b2e4u; return 0; }
r[11]|=r[2];
goto P_0c05b324;
P_0c05b2e6: /* original 2b2b, guest PC 0x0c05b2e6 */
if(!s->budget--) { s->failed_pc=0x0c05b2e6u; return 0; }
r[11]|=r[2];
return vf3_matrix_family(0x0c05b2e8u,s,ram);
P_0c05b320: /* original d120, guest PC 0x0c05b320 */
if(!s->budget--) { s->failed_pc=0x0c05b320u; return 0; }
r[1]=read(ram,0x0c05b3a4u,4);
goto P_0c05b322;
P_0c05b322: /* original 2b19, guest PC 0x0c05b322 */
if(!s->budget--) { s->failed_pc=0x0c05b322u; return 0; }
r[11]&=r[1];
goto P_0c05b324;
P_0c05b324: /* original d520, guest PC 0x0c05b324 */
if(!s->budget--) { s->failed_pc=0x0c05b324u; return 0; }
r[5]=read(ram,0x0c05b3a8u,4);
goto P_0c05b326;
P_0c05b326: /* original 64e3, guest PC 0x0c05b326 */
if(!s->budget--) { s->failed_pc=0x0c05b326u; return 0; }
r[4]=r[14];
goto P_0c05b328;
P_0c05b328: /* original e340, guest PC 0x0c05b328 */
if(!s->budget--) { s->failed_pc=0x0c05b328u; return 0; }
r[3]=0x00000040u;
goto P_0c05b32a;
P_0c05b32a: /* original 23c8, guest PC 0x0c05b32a */
if(!s->budget--) { s->failed_pc=0x0c05b32au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b32c;
P_0c05b32c: /* original 8d51, guest PC 0x0c05b32c */
if(!s->budget--) { s->failed_pc=0x0c05b32cu; return 0; }
cond=r[17]&1u;
r[4]&=r[9];
if(cond) { goto P_0c05b3d2; }
goto P_0c05b330;
P_0c05b32e: /* original 2499, guest PC 0x0c05b32e */
if(!s->budget--) { s->failed_pc=0x0c05b32eu; return 0; }
r[4]&=r[9];
goto P_0c05b330;
P_0c05b330: /* original 50db, guest PC 0x0c05b330 */
if(!s->budget--) { s->failed_pc=0x0c05b330u; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c05b332;
P_0c05b332: /* original 8800, guest PC 0x0c05b332 */
if(!s->budget--) { s->failed_pc=0x0c05b332u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05b334;
P_0c05b334: /* original 8913, guest PC 0x0c05b334 */
if(!s->budget--) { s->failed_pc=0x0c05b334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b35e; }
goto P_0c05b336;
P_0c05b336: /* original 8801, guest PC 0x0c05b336 */
if(!s->budget--) { s->failed_pc=0x0c05b336u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b338;
P_0c05b338: /* original 8917, guest PC 0x0c05b338 */
if(!s->budget--) { s->failed_pc=0x0c05b338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b36a; }
goto P_0c05b33a;
P_0c05b33a: /* original 8802, guest PC 0x0c05b33a */
if(!s->budget--) { s->failed_pc=0x0c05b33au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05b33c;
P_0c05b33c: /* original 891c, guest PC 0x0c05b33c */
if(!s->budget--) { s->failed_pc=0x0c05b33cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b378; }
goto P_0c05b33e;
P_0c05b33e: /* original 8803, guest PC 0x0c05b33e */
if(!s->budget--) { s->failed_pc=0x0c05b33eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05b340;
P_0c05b340: /* original 891d, guest PC 0x0c05b340 */
if(!s->budget--) { s->failed_pc=0x0c05b340u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b37e; }
goto P_0c05b342;
P_0c05b342: /* original 8804, guest PC 0x0c05b342 */
if(!s->budget--) { s->failed_pc=0x0c05b342u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05b344;
P_0c05b344: /* original 891e, guest PC 0x0c05b344 */
if(!s->budget--) { s->failed_pc=0x0c05b344u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b384; }
goto P_0c05b346;
P_0c05b346: /* original 8805, guest PC 0x0c05b346 */
if(!s->budget--) { s->failed_pc=0x0c05b346u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c05b348;
P_0c05b348: /* original 891f, guest PC 0x0c05b348 */
if(!s->budget--) { s->failed_pc=0x0c05b348u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b38a; }
goto P_0c05b34a;
P_0c05b34a: /* original 8806, guest PC 0x0c05b34a */
if(!s->budget--) { s->failed_pc=0x0c05b34au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c05b34c;
P_0c05b34c: /* original 8920, guest PC 0x0c05b34c */
if(!s->budget--) { s->failed_pc=0x0c05b34cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b390; }
goto P_0c05b34e;
P_0c05b34e: /* original 8808, guest PC 0x0c05b34e */
if(!s->budget--) { s->failed_pc=0x0c05b34eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05b350;
P_0c05b350: /* original 8921, guest PC 0x0c05b350 */
if(!s->budget--) { s->failed_pc=0x0c05b350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b396; }
goto P_0c05b352;
P_0c05b352: /* original 880a, guest PC 0x0c05b352 */
if(!s->budget--) { s->failed_pc=0x0c05b352u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c05b354;
P_0c05b354: /* original 8922, guest PC 0x0c05b354 */
if(!s->budget--) { s->failed_pc=0x0c05b354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b39c; }
goto P_0c05b356;
P_0c05b356: /* original 880b, guest PC 0x0c05b356 */
if(!s->budget--) { s->failed_pc=0x0c05b356u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c05b358;
P_0c05b358: /* original 893a, guest PC 0x0c05b358 */
if(!s->budget--) { s->failed_pc=0x0c05b358u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b3d0; }
goto P_0c05b35a;
P_0c05b35a: /* original a03a, guest PC 0x0c05b35a */
if(!s->budget--) { s->failed_pc=0x0c05b35au; return 0; }
goto P_0c05b3d2;
P_0c05b35c: /* original 0009, guest PC 0x0c05b35c */
if(!s->budget--) { s->failed_pc=0x0c05b35cu; return 0; }
goto P_0c05b35e;
P_0c05b35e: /* original d313, guest PC 0x0c05b35e */
if(!s->budget--) { s->failed_pc=0x0c05b35eu; return 0; }
r[3]=read(ram,0x0c05b3acu,4);
goto P_0c05b360;
P_0c05b360: /* original d213, guest PC 0x0c05b360 */
if(!s->budget--) { s->failed_pc=0x0c05b360u; return 0; }
r[2]=read(ram,0x0c05b3b0u,4);
goto P_0c05b362;
P_0c05b362: /* original 243b, guest PC 0x0c05b362 */
if(!s->budget--) { s->failed_pc=0x0c05b362u; return 0; }
r[4]|=r[3];
goto P_0c05b364;
P_0c05b364: /* original 6e43, guest PC 0x0c05b364 */
if(!s->budget--) { s->failed_pc=0x0c05b364u; return 0; }
r[14]=r[4];
goto P_0c05b366;
P_0c05b366: /* original a005, guest PC 0x0c05b366 */
if(!s->budget--) { s->failed_pc=0x0c05b366u; return 0; }
r[14]&=r[5];
goto P_0c05b374;
P_0c05b368: /* original 2e59, guest PC 0x0c05b368 */
if(!s->budget--) { s->failed_pc=0x0c05b368u; return 0; }
r[14]&=r[5];
goto P_0c05b36a;
P_0c05b36a: /* original d312, guest PC 0x0c05b36a */
if(!s->budget--) { s->failed_pc=0x0c05b36au; return 0; }
r[3]=read(ram,0x0c05b3b4u,4);
goto P_0c05b36c;
P_0c05b36c: /* original d212, guest PC 0x0c05b36c */
if(!s->budget--) { s->failed_pc=0x0c05b36cu; return 0; }
r[2]=read(ram,0x0c05b3b8u,4);
goto P_0c05b36e;
P_0c05b36e: /* original 243b, guest PC 0x0c05b36e */
if(!s->budget--) { s->failed_pc=0x0c05b36eu; return 0; }
r[4]|=r[3];
goto P_0c05b370;
P_0c05b370: /* original 6e43, guest PC 0x0c05b370 */
if(!s->budget--) { s->failed_pc=0x0c05b370u; return 0; }
r[14]=r[4];
goto P_0c05b372;
P_0c05b372: /* original 2e59, guest PC 0x0c05b372 */
if(!s->budget--) { s->failed_pc=0x0c05b372u; return 0; }
r[14]&=r[5];
goto P_0c05b374;
P_0c05b374: /* original a02d, guest PC 0x0c05b374 */
if(!s->budget--) { s->failed_pc=0x0c05b374u; return 0; }
r[14]|=r[2];
goto P_0c05b3d2;
P_0c05b376: /* original 2e2b, guest PC 0x0c05b376 */
if(!s->budget--) { s->failed_pc=0x0c05b376u; return 0; }
r[14]|=r[2];
goto P_0c05b378;
P_0c05b378: /* original de10, guest PC 0x0c05b378 */
if(!s->budget--) { s->failed_pc=0x0c05b378u; return 0; }
r[14]=read(ram,0x0c05b3bcu,4);
goto P_0c05b37a;
P_0c05b37a: /* original a010, guest PC 0x0c05b37a */
if(!s->budget--) { s->failed_pc=0x0c05b37au; return 0; }
goto P_0c05b39e;
P_0c05b37c: /* original 0009, guest PC 0x0c05b37c */
if(!s->budget--) { s->failed_pc=0x0c05b37cu; return 0; }
goto P_0c05b37e;
P_0c05b37e: /* original de10, guest PC 0x0c05b37e */
if(!s->budget--) { s->failed_pc=0x0c05b37eu; return 0; }
r[14]=read(ram,0x0c05b3c0u,4);
goto P_0c05b380;
P_0c05b380: /* original a00d, guest PC 0x0c05b380 */
if(!s->budget--) { s->failed_pc=0x0c05b380u; return 0; }
goto P_0c05b39e;
P_0c05b382: /* original 0009, guest PC 0x0c05b382 */
if(!s->budget--) { s->failed_pc=0x0c05b382u; return 0; }
goto P_0c05b384;
P_0c05b384: /* original de0f, guest PC 0x0c05b384 */
if(!s->budget--) { s->failed_pc=0x0c05b384u; return 0; }
r[14]=read(ram,0x0c05b3c4u,4);
goto P_0c05b386;
P_0c05b386: /* original a00a, guest PC 0x0c05b386 */
if(!s->budget--) { s->failed_pc=0x0c05b386u; return 0; }
goto P_0c05b39e;
P_0c05b388: /* original 0009, guest PC 0x0c05b388 */
if(!s->budget--) { s->failed_pc=0x0c05b388u; return 0; }
goto P_0c05b38a;
P_0c05b38a: /* original de0f, guest PC 0x0c05b38a */
if(!s->budget--) { s->failed_pc=0x0c05b38au; return 0; }
r[14]=read(ram,0x0c05b3c8u,4);
goto P_0c05b38c;
P_0c05b38c: /* original a007, guest PC 0x0c05b38c */
if(!s->budget--) { s->failed_pc=0x0c05b38cu; return 0; }
goto P_0c05b39e;
P_0c05b38e: /* original 0009, guest PC 0x0c05b38e */
if(!s->budget--) { s->failed_pc=0x0c05b38eu; return 0; }
goto P_0c05b390;
P_0c05b390: /* original de06, guest PC 0x0c05b390 */
if(!s->budget--) { s->failed_pc=0x0c05b390u; return 0; }
r[14]=read(ram,0x0c05b3acu,4);
goto P_0c05b392;
P_0c05b392: /* original a004, guest PC 0x0c05b392 */
if(!s->budget--) { s->failed_pc=0x0c05b392u; return 0; }
goto P_0c05b39e;
P_0c05b394: /* original 0009, guest PC 0x0c05b394 */
if(!s->budget--) { s->failed_pc=0x0c05b394u; return 0; }
goto P_0c05b396;
P_0c05b396: /* original de07, guest PC 0x0c05b396 */
if(!s->budget--) { s->failed_pc=0x0c05b396u; return 0; }
r[14]=read(ram,0x0c05b3b4u,4);
goto P_0c05b398;
P_0c05b398: /* original a001, guest PC 0x0c05b398 */
if(!s->budget--) { s->failed_pc=0x0c05b398u; return 0; }
goto P_0c05b39e;
P_0c05b39a: /* original 0009, guest PC 0x0c05b39a */
if(!s->budget--) { s->failed_pc=0x0c05b39au; return 0; }
goto P_0c05b39c;
P_0c05b39c: /* original de0b, guest PC 0x0c05b39c */
if(!s->budget--) { s->failed_pc=0x0c05b39cu; return 0; }
r[14]=read(ram,0x0c05b3ccu,4);
goto P_0c05b39e;
P_0c05b39e: /* original a018, guest PC 0x0c05b39e */
if(!s->budget--) { s->failed_pc=0x0c05b39eu; return 0; }
r[14]|=r[4];
goto P_0c05b3d2;
P_0c05b3a0: /* original 2e4b, guest PC 0x0c05b3a0 */
if(!s->budget--) { s->failed_pc=0x0c05b3a0u; return 0; }
r[14]|=r[4];
return vf3_matrix_family(0x0c05b3a2u,s,ram);
P_0c05b3d0: /* original 6e43, guest PC 0x0c05b3d0 */
if(!s->budget--) { s->failed_pc=0x0c05b3d0u; return 0; }
r[14]=r[4];
goto P_0c05b3d2;
P_0c05b3d2: /* original 934d, guest PC 0x0c05b3d2 */
if(!s->budget--) { s->failed_pc=0x0c05b3d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b470u,2);
goto P_0c05b3d4;
P_0c05b3d4: /* original 23c8, guest PC 0x0c05b3d4 */
if(!s->budget--) { s->failed_pc=0x0c05b3d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b3d6;
P_0c05b3d6: /* original 8941, guest PC 0x0c05b3d6 */
if(!s->budget--) { s->failed_pc=0x0c05b3d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b45c; }
goto P_0c05b3d8;
P_0c05b3d8: /* original 60e3, guest PC 0x0c05b3d8 */
if(!s->budget--) { s->failed_pc=0x0c05b3d8u; return 0; }
r[0]=r[14];
goto P_0c05b3da;
P_0c05b3da: /* original 0009, guest PC 0x0c05b3da */
if(!s->budget--) { s->failed_pc=0x0c05b3dau; return 0; }
goto P_0c05b3dc;
P_0c05b3dc: /* original 2099, guest PC 0x0c05b3dc */
if(!s->budget--) { s->failed_pc=0x0c05b3dcu; return 0; }
r[0]&=r[9];
goto P_0c05b3de;
P_0c05b3de: /* original 64e3, guest PC 0x0c05b3de */
if(!s->budget--) { s->failed_pc=0x0c05b3deu; return 0; }
r[4]=r[14];
goto P_0c05b3e0;
P_0c05b3e0: /* original 1f01, guest PC 0x0c05b3e0 */
if(!s->budget--) { s->failed_pc=0x0c05b3e0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c05b3e2;
P_0c05b3e2: /* original 50dc, guest PC 0x0c05b3e2 */
if(!s->budget--) { s->failed_pc=0x0c05b3e2u; return 0; }
r[0]=read(ram,r[13]+48,4);
goto P_0c05b3e4;
P_0c05b3e4: /* original 8800, guest PC 0x0c05b3e4 */
if(!s->budget--) { s->failed_pc=0x0c05b3e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05b3e6;
P_0c05b3e6: /* original 8d14, guest PC 0x0c05b3e6 */
if(!s->budget--) { s->failed_pc=0x0c05b3e6u; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(cond) { goto P_0c05b412; }
goto P_0c05b3ea;
P_0c05b3e8: /* original 2459, guest PC 0x0c05b3e8 */
if(!s->budget--) { s->failed_pc=0x0c05b3e8u; return 0; }
r[4]&=r[5];
goto P_0c05b3ea;
P_0c05b3ea: /* original 8801, guest PC 0x0c05b3ea */
if(!s->budget--) { s->failed_pc=0x0c05b3eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b3ec;
P_0c05b3ec: /* original 8918, guest PC 0x0c05b3ec */
if(!s->budget--) { s->failed_pc=0x0c05b3ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b420; }
goto P_0c05b3ee;
P_0c05b3ee: /* original 8802, guest PC 0x0c05b3ee */
if(!s->budget--) { s->failed_pc=0x0c05b3eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05b3f0;
P_0c05b3f0: /* original 891e, guest PC 0x0c05b3f0 */
if(!s->budget--) { s->failed_pc=0x0c05b3f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b430; }
goto P_0c05b3f2;
P_0c05b3f2: /* original 8804, guest PC 0x0c05b3f2 */
if(!s->budget--) { s->failed_pc=0x0c05b3f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05b3f4;
P_0c05b3f4: /* original 891f, guest PC 0x0c05b3f4 */
if(!s->budget--) { s->failed_pc=0x0c05b3f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b436; }
goto P_0c05b3f6;
P_0c05b3f6: /* original 8806, guest PC 0x0c05b3f6 */
if(!s->budget--) { s->failed_pc=0x0c05b3f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c05b3f8;
P_0c05b3f8: /* original 8920, guest PC 0x0c05b3f8 */
if(!s->budget--) { s->failed_pc=0x0c05b3f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b43c; }
goto P_0c05b3fa;
P_0c05b3fa: /* original 8807, guest PC 0x0c05b3fa */
if(!s->budget--) { s->failed_pc=0x0c05b3fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c05b3fc;
P_0c05b3fc: /* original 8921, guest PC 0x0c05b3fc */
if(!s->budget--) { s->failed_pc=0x0c05b3fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b442; }
goto P_0c05b3fe;
P_0c05b3fe: /* original 8808, guest PC 0x0c05b3fe */
if(!s->budget--) { s->failed_pc=0x0c05b3feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05b400;
P_0c05b400: /* original 8922, guest PC 0x0c05b400 */
if(!s->budget--) { s->failed_pc=0x0c05b400u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b448; }
goto P_0c05b402;
P_0c05b402: /* original 8809, guest PC 0x0c05b402 */
if(!s->budget--) { s->failed_pc=0x0c05b402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c05b404;
P_0c05b404: /* original 8923, guest PC 0x0c05b404 */
if(!s->budget--) { s->failed_pc=0x0c05b404u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b44e; }
goto P_0c05b406;
P_0c05b406: /* original 880a, guest PC 0x0c05b406 */
if(!s->budget--) { s->failed_pc=0x0c05b406u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c05b408;
P_0c05b408: /* original 8924, guest PC 0x0c05b408 */
if(!s->budget--) { s->failed_pc=0x0c05b408u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b454; }
goto P_0c05b40a;
P_0c05b40a: /* original 880b, guest PC 0x0c05b40a */
if(!s->budget--) { s->failed_pc=0x0c05b40au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c05b40c;
P_0c05b40c: /* original 8925, guest PC 0x0c05b40c */
if(!s->budget--) { s->failed_pc=0x0c05b40cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b45a; }
goto P_0c05b40e;
P_0c05b40e: /* original a025, guest PC 0x0c05b40e */
if(!s->budget--) { s->failed_pc=0x0c05b40eu; return 0; }
goto P_0c05b45c;
P_0c05b410: /* original 0009, guest PC 0x0c05b410 */
if(!s->budget--) { s->failed_pc=0x0c05b410u; return 0; }
goto P_0c05b412;
P_0c05b412: /* original d318, guest PC 0x0c05b412 */
if(!s->budget--) { s->failed_pc=0x0c05b412u; return 0; }
r[3]=read(ram,0x0c05b474u,4);
goto P_0c05b414;
P_0c05b414: /* original 54f1, guest PC 0x0c05b414 */
if(!s->budget--) { s->failed_pc=0x0c05b414u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05b416;
P_0c05b416: /* original 243b, guest PC 0x0c05b416 */
if(!s->budget--) { s->failed_pc=0x0c05b416u; return 0; }
r[4]|=r[3];
goto P_0c05b418;
P_0c05b418: /* original d217, guest PC 0x0c05b418 */
if(!s->budget--) { s->failed_pc=0x0c05b418u; return 0; }
r[2]=read(ram,0x0c05b478u,4);
goto P_0c05b41a;
P_0c05b41a: /* original 6e43, guest PC 0x0c05b41a */
if(!s->budget--) { s->failed_pc=0x0c05b41au; return 0; }
r[14]=r[4];
goto P_0c05b41c;
P_0c05b41c: /* original a006, guest PC 0x0c05b41c */
if(!s->budget--) { s->failed_pc=0x0c05b41cu; return 0; }
r[14]&=r[5];
goto P_0c05b42c;
P_0c05b41e: /* original 2e59, guest PC 0x0c05b41e */
if(!s->budget--) { s->failed_pc=0x0c05b41eu; return 0; }
r[14]&=r[5];
goto P_0c05b420;
P_0c05b420: /* original d316, guest PC 0x0c05b420 */
if(!s->budget--) { s->failed_pc=0x0c05b420u; return 0; }
r[3]=read(ram,0x0c05b47cu,4);
goto P_0c05b422;
P_0c05b422: /* original 54f1, guest PC 0x0c05b422 */
if(!s->budget--) { s->failed_pc=0x0c05b422u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05b424;
P_0c05b424: /* original d216, guest PC 0x0c05b424 */
if(!s->budget--) { s->failed_pc=0x0c05b424u; return 0; }
r[2]=read(ram,0x0c05b480u,4);
goto P_0c05b426;
P_0c05b426: /* original 243b, guest PC 0x0c05b426 */
if(!s->budget--) { s->failed_pc=0x0c05b426u; return 0; }
r[4]|=r[3];
goto P_0c05b428;
P_0c05b428: /* original 6e43, guest PC 0x0c05b428 */
if(!s->budget--) { s->failed_pc=0x0c05b428u; return 0; }
r[14]=r[4];
goto P_0c05b42a;
P_0c05b42a: /* original 2e59, guest PC 0x0c05b42a */
if(!s->budget--) { s->failed_pc=0x0c05b42au; return 0; }
r[14]&=r[5];
goto P_0c05b42c;
P_0c05b42c: /* original a016, guest PC 0x0c05b42c */
if(!s->budget--) { s->failed_pc=0x0c05b42cu; return 0; }
r[14]|=r[2];
goto P_0c05b45c;
P_0c05b42e: /* original 2e2b, guest PC 0x0c05b42e */
if(!s->budget--) { s->failed_pc=0x0c05b42eu; return 0; }
r[14]|=r[2];
goto P_0c05b430;
P_0c05b430: /* original de14, guest PC 0x0c05b430 */
if(!s->budget--) { s->failed_pc=0x0c05b430u; return 0; }
r[14]=read(ram,0x0c05b484u,4);
goto P_0c05b432;
P_0c05b432: /* original a00d, guest PC 0x0c05b432 */
if(!s->budget--) { s->failed_pc=0x0c05b432u; return 0; }
goto P_0c05b450;
P_0c05b434: /* original 0009, guest PC 0x0c05b434 */
if(!s->budget--) { s->failed_pc=0x0c05b434u; return 0; }
goto P_0c05b436;
P_0c05b436: /* original de14, guest PC 0x0c05b436 */
if(!s->budget--) { s->failed_pc=0x0c05b436u; return 0; }
r[14]=read(ram,0x0c05b488u,4);
goto P_0c05b438;
P_0c05b438: /* original a00a, guest PC 0x0c05b438 */
if(!s->budget--) { s->failed_pc=0x0c05b438u; return 0; }
goto P_0c05b450;
P_0c05b43a: /* original 0009, guest PC 0x0c05b43a */
if(!s->budget--) { s->failed_pc=0x0c05b43au; return 0; }
goto P_0c05b43c;
P_0c05b43c: /* original de10, guest PC 0x0c05b43c */
if(!s->budget--) { s->failed_pc=0x0c05b43cu; return 0; }
r[14]=read(ram,0x0c05b480u,4);
goto P_0c05b43e;
P_0c05b43e: /* original a007, guest PC 0x0c05b43e */
if(!s->budget--) { s->failed_pc=0x0c05b43eu; return 0; }
goto P_0c05b450;
P_0c05b440: /* original 0009, guest PC 0x0c05b440 */
if(!s->budget--) { s->failed_pc=0x0c05b440u; return 0; }
goto P_0c05b442;
P_0c05b442: /* original de12, guest PC 0x0c05b442 */
if(!s->budget--) { s->failed_pc=0x0c05b442u; return 0; }
r[14]=read(ram,0x0c05b48cu,4);
goto P_0c05b444;
P_0c05b444: /* original a004, guest PC 0x0c05b444 */
if(!s->budget--) { s->failed_pc=0x0c05b444u; return 0; }
goto P_0c05b450;
P_0c05b446: /* original 0009, guest PC 0x0c05b446 */
if(!s->budget--) { s->failed_pc=0x0c05b446u; return 0; }
goto P_0c05b448;
P_0c05b448: /* original de0b, guest PC 0x0c05b448 */
if(!s->budget--) { s->failed_pc=0x0c05b448u; return 0; }
r[14]=read(ram,0x0c05b478u,4);
goto P_0c05b44a;
P_0c05b44a: /* original a001, guest PC 0x0c05b44a */
if(!s->budget--) { s->failed_pc=0x0c05b44au; return 0; }
goto P_0c05b450;
P_0c05b44c: /* original 0009, guest PC 0x0c05b44c */
if(!s->budget--) { s->failed_pc=0x0c05b44cu; return 0; }
goto P_0c05b44e;
P_0c05b44e: /* original de10, guest PC 0x0c05b44e */
if(!s->budget--) { s->failed_pc=0x0c05b44eu; return 0; }
r[14]=read(ram,0x0c05b490u,4);
goto P_0c05b450;
P_0c05b450: /* original a004, guest PC 0x0c05b450 */
if(!s->budget--) { s->failed_pc=0x0c05b450u; return 0; }
r[14]|=r[4];
goto P_0c05b45c;
P_0c05b452: /* original 2e4b, guest PC 0x0c05b452 */
if(!s->budget--) { s->failed_pc=0x0c05b452u; return 0; }
r[14]|=r[4];
goto P_0c05b454;
P_0c05b454: /* original 6e43, guest PC 0x0c05b454 */
if(!s->budget--) { s->failed_pc=0x0c05b454u; return 0; }
r[14]=r[4];
goto P_0c05b456;
P_0c05b456: /* original a001, guest PC 0x0c05b456 */
if(!s->budget--) { s->failed_pc=0x0c05b456u; return 0; }
r[14]|=r[7];
goto P_0c05b45c;
P_0c05b458: /* original 2e7b, guest PC 0x0c05b458 */
if(!s->budget--) { s->failed_pc=0x0c05b458u; return 0; }
r[14]|=r[7];
goto P_0c05b45a;
P_0c05b45a: /* original 6e43, guest PC 0x0c05b45a */
if(!s->budget--) { s->failed_pc=0x0c05b45au; return 0; }
r[14]=r[4];
goto P_0c05b45c;
P_0c05b45c: /* original d50d, guest PC 0x0c05b45c */
if(!s->budget--) { s->failed_pc=0x0c05b45cu; return 0; }
r[5]=read(ram,0x0c05b494u,4);
goto P_0c05b45e;
P_0c05b45e: /* original 63c3, guest PC 0x0c05b45e */
if(!s->budget--) { s->failed_pc=0x0c05b45eu; return 0; }
r[3]=r[12];
goto P_0c05b460;
P_0c05b460: /* original d40d, guest PC 0x0c05b460 */
if(!s->budget--) { s->failed_pc=0x0c05b460u; return 0; }
r[4]=read(ram,0x0c05b498u,4);
goto P_0c05b462;
P_0c05b462: /* original 2348, guest PC 0x0c05b462 */
if(!s->budget--) { s->failed_pc=0x0c05b462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c05b464;
P_0c05b464: /* original 891c, guest PC 0x0c05b464 */
if(!s->budget--) { s->failed_pc=0x0c05b464u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4a0; }
goto P_0c05b466;
P_0c05b466: /* original 51dd, guest PC 0x0c05b466 */
if(!s->budget--) { s->failed_pc=0x0c05b466u; return 0; }
r[1]=read(ram,r[13]+52,4);
goto P_0c05b468;
P_0c05b468: /* original 2118, guest PC 0x0c05b468 */
if(!s->budget--) { s->failed_pc=0x0c05b468u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b46a;
P_0c05b46a: /* original 8917, guest PC 0x0c05b46a */
if(!s->budget--) { s->failed_pc=0x0c05b46au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b49c; }
goto P_0c05b46c;
P_0c05b46c: /* original a018, guest PC 0x0c05b46c */
if(!s->budget--) { s->failed_pc=0x0c05b46cu; return 0; }
r[14]|=r[5];
goto P_0c05b4a0;
P_0c05b46e: /* original 2e5b, guest PC 0x0c05b46e */
if(!s->budget--) { s->failed_pc=0x0c05b46eu; return 0; }
r[14]|=r[5];
return vf3_matrix_family(0x0c05b470u,s,ram);
P_0c05b49c: /* original d238, guest PC 0x0c05b49c */
if(!s->budget--) { s->failed_pc=0x0c05b49cu; return 0; }
r[2]=read(ram,0x0c05b580u,4);
goto P_0c05b49e;
P_0c05b49e: /* original 2e29, guest PC 0x0c05b49e */
if(!s->budget--) { s->failed_pc=0x0c05b49eu; return 0; }
r[14]&=r[2];
goto P_0c05b4a0;
P_0c05b4a0: /* original 25c8, guest PC 0x0c05b4a0 */
if(!s->budget--) { s->failed_pc=0x0c05b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c05b4a2;
P_0c05b4a2: /* original 8905, guest PC 0x0c05b4a2 */
if(!s->budget--) { s->failed_pc=0x0c05b4a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4b0; }
goto P_0c05b4a4;
P_0c05b4a4: /* original 52de, guest PC 0x0c05b4a4 */
if(!s->budget--) { s->failed_pc=0x0c05b4a4u; return 0; }
r[2]=read(ram,r[13]+56,4);
goto P_0c05b4a6;
P_0c05b4a6: /* original 2228, guest PC 0x0c05b4a6 */
if(!s->budget--) { s->failed_pc=0x0c05b4a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b4a8;
P_0c05b4a8: /* original 8901, guest PC 0x0c05b4a8 */
if(!s->budget--) { s->failed_pc=0x0c05b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4ae; }
goto P_0c05b4aa;
P_0c05b4aa: /* original a001, guest PC 0x0c05b4aa */
if(!s->budget--) { s->failed_pc=0x0c05b4aau; return 0; }
r[14]|=r[4];
goto P_0c05b4b0;
P_0c05b4ac: /* original 2e4b, guest PC 0x0c05b4ac */
if(!s->budget--) { s->failed_pc=0x0c05b4acu; return 0; }
r[14]|=r[4];
goto P_0c05b4ae;
P_0c05b4ae: /* original 2e69, guest PC 0x0c05b4ae */
if(!s->budget--) { s->failed_pc=0x0c05b4aeu; return 0; }
r[14]&=r[6];
goto P_0c05b4b0;
P_0c05b4b0: /* original 925e, guest PC 0x0c05b4b0 */
if(!s->budget--) { s->failed_pc=0x0c05b4b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b570u,2);
goto P_0c05b4b2;
P_0c05b4b2: /* original 22c8, guest PC 0x0c05b4b2 */
if(!s->budget--) { s->failed_pc=0x0c05b4b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c05b4b4;
P_0c05b4b4: /* original 8d08, guest PC 0x0c05b4b4 */
if(!s->budget--) { s->failed_pc=0x0c05b4b4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000003u;
if(cond) { goto P_0c05b4c8; }
goto P_0c05b4b8;
P_0c05b4b6: /* original e503, guest PC 0x0c05b4b6 */
if(!s->budget--) { s->failed_pc=0x0c05b4b6u; return 0; }
r[5]=0x00000003u;
goto P_0c05b4b8;
P_0c05b4b8: /* original 54df, guest PC 0x0c05b4b8 */
if(!s->budget--) { s->failed_pc=0x0c05b4b8u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c05b4ba;
P_0c05b4ba: /* original e316, guest PC 0x0c05b4ba */
if(!s->budget--) { s->failed_pc=0x0c05b4bau; return 0; }
r[3]=0x00000016u;
goto P_0c05b4bc;
P_0c05b4bc: /* original d231, guest PC 0x0c05b4bc */
if(!s->budget--) { s->failed_pc=0x0c05b4bcu; return 0; }
r[2]=read(ram,0x0c05b584u,4);
goto P_0c05b4be;
P_0c05b4be: /* original 2459, guest PC 0x0c05b4be */
if(!s->budget--) { s->failed_pc=0x0c05b4beu; return 0; }
r[4]&=r[5];
goto P_0c05b4c0;
P_0c05b4c0: /* original 22e9, guest PC 0x0c05b4c0 */
if(!s->budget--) { s->failed_pc=0x0c05b4c0u; return 0; }
r[2]&=r[14];
goto P_0c05b4c2;
P_0c05b4c2: /* original 443d, guest PC 0x0c05b4c2 */
if(!s->budget--) { s->failed_pc=0x0c05b4c2u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05b4c4;
P_0c05b4c4: /* original 6e23, guest PC 0x0c05b4c4 */
if(!s->budget--) { s->failed_pc=0x0c05b4c4u; return 0; }
r[14]=r[2];
goto P_0c05b4c6;
P_0c05b4c6: /* original 2e4b, guest PC 0x0c05b4c6 */
if(!s->budget--) { s->failed_pc=0x0c05b4c6u; return 0; }
r[14]|=r[4];
goto P_0c05b4c8;
P_0c05b4c8: /* original d22f, guest PC 0x0c05b4c8 */
if(!s->budget--) { s->failed_pc=0x0c05b4c8u; return 0; }
r[2]=read(ram,0x0c05b588u,4);
goto P_0c05b4ca;
P_0c05b4ca: /* original 22c8, guest PC 0x0c05b4ca */
if(!s->budget--) { s->failed_pc=0x0c05b4cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c05b4cc;
P_0c05b4cc: /* original 8908, guest PC 0x0c05b4cc */
if(!s->budget--) { s->failed_pc=0x0c05b4ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4e0; }
goto P_0c05b4ce;
P_0c05b4ce: /* original e064, guest PC 0x0c05b4ce */
if(!s->budget--) { s->failed_pc=0x0c05b4ceu; return 0; }
r[0]=0x00000064u;
goto P_0c05b4d0;
P_0c05b4d0: /* original 01de, guest PC 0x0c05b4d0 */
if(!s->budget--) { s->failed_pc=0x0c05b4d0u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05b4d2;
P_0c05b4d2: /* original 2118, guest PC 0x0c05b4d2 */
if(!s->budget--) { s->failed_pc=0x0c05b4d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b4d4;
P_0c05b4d4: /* original 8902, guest PC 0x0c05b4d4 */
if(!s->budget--) { s->failed_pc=0x0c05b4d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4dc; }
goto P_0c05b4d6;
P_0c05b4d6: /* original d32d, guest PC 0x0c05b4d6 */
if(!s->budget--) { s->failed_pc=0x0c05b4d6u; return 0; }
r[3]=read(ram,0x0c05b58cu,4);
goto P_0c05b4d8;
P_0c05b4d8: /* original a002, guest PC 0x0c05b4d8 */
if(!s->budget--) { s->failed_pc=0x0c05b4d8u; return 0; }
r[14]|=r[3];
goto P_0c05b4e0;
P_0c05b4da: /* original 2e3b, guest PC 0x0c05b4da */
if(!s->budget--) { s->failed_pc=0x0c05b4dau; return 0; }
r[14]|=r[3];
goto P_0c05b4dc;
P_0c05b4dc: /* original d12c, guest PC 0x0c05b4dc */
if(!s->budget--) { s->failed_pc=0x0c05b4dcu; return 0; }
r[1]=read(ram,0x0c05b590u,4);
goto P_0c05b4de;
P_0c05b4de: /* original 2e19, guest PC 0x0c05b4de */
if(!s->budget--) { s->failed_pc=0x0c05b4deu; return 0; }
r[14]&=r[1];
goto P_0c05b4e0;
P_0c05b4e0: /* original 9347, guest PC 0x0c05b4e0 */
if(!s->budget--) { s->failed_pc=0x0c05b4e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b572u,2);
goto P_0c05b4e2;
P_0c05b4e2: /* original 23c8, guest PC 0x0c05b4e2 */
if(!s->budget--) { s->failed_pc=0x0c05b4e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b4e4;
P_0c05b4e4: /* original 8908, guest PC 0x0c05b4e4 */
if(!s->budget--) { s->failed_pc=0x0c05b4e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4f8; }
goto P_0c05b4e6;
P_0c05b4e6: /* original e044, guest PC 0x0c05b4e6 */
if(!s->budget--) { s->failed_pc=0x0c05b4e6u; return 0; }
r[0]=0x00000044u;
goto P_0c05b4e8;
P_0c05b4e8: /* original 01de, guest PC 0x0c05b4e8 */
if(!s->budget--) { s->failed_pc=0x0c05b4e8u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05b4ea;
P_0c05b4ea: /* original 2118, guest PC 0x0c05b4ea */
if(!s->budget--) { s->failed_pc=0x0c05b4eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b4ec;
P_0c05b4ec: /* original 8902, guest PC 0x0c05b4ec */
if(!s->budget--) { s->failed_pc=0x0c05b4ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b4f4; }
goto P_0c05b4ee;
P_0c05b4ee: /* original d229, guest PC 0x0c05b4ee */
if(!s->budget--) { s->failed_pc=0x0c05b4eeu; return 0; }
r[2]=read(ram,0x0c05b594u,4);
goto P_0c05b4f0;
P_0c05b4f0: /* original a002, guest PC 0x0c05b4f0 */
if(!s->budget--) { s->failed_pc=0x0c05b4f0u; return 0; }
r[14]|=r[2];
goto P_0c05b4f8;
P_0c05b4f2: /* original 2e2b, guest PC 0x0c05b4f2 */
if(!s->budget--) { s->failed_pc=0x0c05b4f2u; return 0; }
r[14]|=r[2];
goto P_0c05b4f4;
P_0c05b4f4: /* original d128, guest PC 0x0c05b4f4 */
if(!s->budget--) { s->failed_pc=0x0c05b4f4u; return 0; }
r[1]=read(ram,0x0c05b598u,4);
goto P_0c05b4f6;
P_0c05b4f6: /* original 2e19, guest PC 0x0c05b4f6 */
if(!s->budget--) { s->failed_pc=0x0c05b4f6u; return 0; }
r[14]&=r[1];
goto P_0c05b4f8;
P_0c05b4f8: /* original 933c, guest PC 0x0c05b4f8 */
if(!s->budget--) { s->failed_pc=0x0c05b4f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b574u,2);
goto P_0c05b4fa;
P_0c05b4fa: /* original 23c8, guest PC 0x0c05b4fa */
if(!s->budget--) { s->failed_pc=0x0c05b4fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b4fc;
P_0c05b4fc: /* original 8908, guest PC 0x0c05b4fc */
if(!s->budget--) { s->failed_pc=0x0c05b4fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b510; }
goto P_0c05b4fe;
P_0c05b4fe: /* original e048, guest PC 0x0c05b4fe */
if(!s->budget--) { s->failed_pc=0x0c05b4feu; return 0; }
r[0]=0x00000048u;
goto P_0c05b500;
P_0c05b500: /* original 01de, guest PC 0x0c05b500 */
if(!s->budget--) { s->failed_pc=0x0c05b500u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05b502;
P_0c05b502: /* original 2118, guest PC 0x0c05b502 */
if(!s->budget--) { s->failed_pc=0x0c05b502u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b504;
P_0c05b504: /* original 8902, guest PC 0x0c05b504 */
if(!s->budget--) { s->failed_pc=0x0c05b504u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b50c; }
goto P_0c05b506;
P_0c05b506: /* original d225, guest PC 0x0c05b506 */
if(!s->budget--) { s->failed_pc=0x0c05b506u; return 0; }
r[2]=read(ram,0x0c05b59cu,4);
goto P_0c05b508;
P_0c05b508: /* original a002, guest PC 0x0c05b508 */
if(!s->budget--) { s->failed_pc=0x0c05b508u; return 0; }
r[14]|=r[2];
goto P_0c05b510;
P_0c05b50a: /* original 2e2b, guest PC 0x0c05b50a */
if(!s->budget--) { s->failed_pc=0x0c05b50au; return 0; }
r[14]|=r[2];
goto P_0c05b50c;
P_0c05b50c: /* original d124, guest PC 0x0c05b50c */
if(!s->budget--) { s->failed_pc=0x0c05b50cu; return 0; }
r[1]=read(ram,0x0c05b5a0u,4);
goto P_0c05b50e;
P_0c05b50e: /* original 2e19, guest PC 0x0c05b50e */
if(!s->budget--) { s->failed_pc=0x0c05b50eu; return 0; }
r[14]&=r[1];
goto P_0c05b510;
P_0c05b510: /* original 9631, guest PC 0x0c05b510 */
if(!s->budget--) { s->failed_pc=0x0c05b510u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b576u,2);
goto P_0c05b512;
P_0c05b512: /* original 63c3, guest PC 0x0c05b512 */
if(!s->budget--) { s->failed_pc=0x0c05b512u; return 0; }
r[3]=r[12];
goto P_0c05b514;
P_0c05b514: /* original 2368, guest PC 0x0c05b514 */
if(!s->budget--) { s->failed_pc=0x0c05b514u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c05b516;
P_0c05b516: /* original 8907, guest PC 0x0c05b516 */
if(!s->budget--) { s->failed_pc=0x0c05b516u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b528; }
goto P_0c05b518;
P_0c05b518: /* original d122, guest PC 0x0c05b518 */
if(!s->budget--) { s->failed_pc=0x0c05b518u; return 0; }
r[1]=read(ram,0x0c05b5a4u,4);
goto P_0c05b51a;
P_0c05b51a: /* original e30f, guest PC 0x0c05b51a */
if(!s->budget--) { s->failed_pc=0x0c05b51au; return 0; }
r[3]=0x0000000fu;
goto P_0c05b51c;
P_0c05b51c: /* original 21e9, guest PC 0x0c05b51c */
if(!s->budget--) { s->failed_pc=0x0c05b51cu; return 0; }
r[1]&=r[14];
goto P_0c05b51e;
P_0c05b51e: /* original e04c, guest PC 0x0c05b51e */
if(!s->budget--) { s->failed_pc=0x0c05b51eu; return 0; }
r[0]=0x0000004cu;
goto P_0c05b520;
P_0c05b520: /* original 02de, guest PC 0x0c05b520 */
if(!s->budget--) { s->failed_pc=0x0c05b520u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b522;
P_0c05b522: /* original 6e13, guest PC 0x0c05b522 */
if(!s->budget--) { s->failed_pc=0x0c05b522u; return 0; }
r[14]=r[1];
goto P_0c05b524;
P_0c05b524: /* original 423d, guest PC 0x0c05b524 */
if(!s->budget--) { s->failed_pc=0x0c05b524u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05b526;
P_0c05b526: /* original 2e2b, guest PC 0x0c05b526 */
if(!s->budget--) { s->failed_pc=0x0c05b526u; return 0; }
r[14]|=r[2];
goto P_0c05b528;
P_0c05b528: /* original 9326, guest PC 0x0c05b528 */
if(!s->budget--) { s->failed_pc=0x0c05b528u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b578u,2);
goto P_0c05b52a;
P_0c05b52a: /* original 23c8, guest PC 0x0c05b52a */
if(!s->budget--) { s->failed_pc=0x0c05b52au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b52c;
P_0c05b52c: /* original 8907, guest PC 0x0c05b52c */
if(!s->budget--) { s->failed_pc=0x0c05b52cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b53e; }
goto P_0c05b52e;
P_0c05b52e: /* original e050, guest PC 0x0c05b52e */
if(!s->budget--) { s->failed_pc=0x0c05b52eu; return 0; }
r[0]=0x00000050u;
goto P_0c05b530;
P_0c05b530: /* original d11d, guest PC 0x0c05b530 */
if(!s->budget--) { s->failed_pc=0x0c05b530u; return 0; }
r[1]=read(ram,0x0c05b5a8u,4);
goto P_0c05b532;
P_0c05b532: /* original 21e9, guest PC 0x0c05b532 */
if(!s->budget--) { s->failed_pc=0x0c05b532u; return 0; }
r[1]&=r[14];
goto P_0c05b534;
P_0c05b534: /* original 03de, guest PC 0x0c05b534 */
if(!s->budget--) { s->failed_pc=0x0c05b534u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05b536;
P_0c05b536: /* original 6e13, guest PC 0x0c05b536 */
if(!s->budget--) { s->failed_pc=0x0c05b536u; return 0; }
r[14]=r[1];
goto P_0c05b538;
P_0c05b538: /* original 4328, guest PC 0x0c05b538 */
if(!s->budget--) { s->failed_pc=0x0c05b538u; return 0; }
r[3]<<=16;
goto P_0c05b53a;
P_0c05b53a: /* original 4300, guest PC 0x0c05b53a */
if(!s->budget--) { s->failed_pc=0x0c05b53au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05b53c;
P_0c05b53c: /* original 2e3b, guest PC 0x0c05b53c */
if(!s->budget--) { s->failed_pc=0x0c05b53cu; return 0; }
r[14]|=r[3];
goto P_0c05b53e;
P_0c05b53e: /* original 931c, guest PC 0x0c05b53e */
if(!s->budget--) { s->failed_pc=0x0c05b53eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b57au,2);
goto P_0c05b540;
P_0c05b540: /* original 23c8, guest PC 0x0c05b540 */
if(!s->budget--) { s->failed_pc=0x0c05b540u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b542;
P_0c05b542: /* original 890c, guest PC 0x0c05b542 */
if(!s->budget--) { s->failed_pc=0x0c05b542u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b55e; }
goto P_0c05b544;
P_0c05b544: /* original 921a, guest PC 0x0c05b544 */
if(!s->budget--) { s->failed_pc=0x0c05b544u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b57cu,2);
goto P_0c05b546;
P_0c05b546: /* original e10d, guest PC 0x0c05b546 */
if(!s->budget--) { s->failed_pc=0x0c05b546u; return 0; }
r[1]=0x0000000du;
goto P_0c05b548;
P_0c05b548: /* original e054, guest PC 0x0c05b548 */
if(!s->budget--) { s->failed_pc=0x0c05b548u; return 0; }
r[0]=0x00000054u;
goto P_0c05b54a;
P_0c05b54a: /* original 63f3, guest PC 0x0c05b54a */
if(!s->budget--) { s->failed_pc=0x0c05b54au; return 0; }
r[3]=r[15];
goto P_0c05b54c;
P_0c05b54c: /* original 04de, guest PC 0x0c05b54c */
if(!s->budget--) { s->failed_pc=0x0c05b54cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b54e;
P_0c05b54e: /* original 22e9, guest PC 0x0c05b54e */
if(!s->budget--) { s->failed_pc=0x0c05b54eu; return 0; }
r[2]&=r[14];
goto P_0c05b550;
P_0c05b550: /* original 4408, guest PC 0x0c05b550 */
if(!s->budget--) { s->failed_pc=0x0c05b550u; return 0; }
r[4]<<=2;
goto P_0c05b552;
P_0c05b552: /* original 7310, guest PC 0x0c05b552 */
if(!s->budget--) { s->failed_pc=0x0c05b552u; return 0; }
r[3]+=0x00000010u;
goto P_0c05b554;
P_0c05b554: /* original 343c, guest PC 0x0c05b554 */
if(!s->budget--) { s->failed_pc=0x0c05b554u; return 0; }
r[4]+=r[3];
goto P_0c05b556;
P_0c05b556: /* original 6e23, guest PC 0x0c05b556 */
if(!s->budget--) { s->failed_pc=0x0c05b556u; return 0; }
r[14]=r[2];
goto P_0c05b558;
P_0c05b558: /* original 6442, guest PC 0x0c05b558 */
if(!s->budget--) { s->failed_pc=0x0c05b558u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05b55a;
P_0c05b55a: /* original 441d, guest PC 0x0c05b55a */
if(!s->budget--) { s->failed_pc=0x0c05b55au; return 0; }
r[4]=(r[1]&0x80000000u)?((r[1]&31u)?r[4]>>((-r[1])&31u):0):r[4]<<(r[1]&31u);
goto P_0c05b55c;
P_0c05b55c: /* original 2e4b, guest PC 0x0c05b55c */
if(!s->budget--) { s->failed_pc=0x0c05b55cu; return 0; }
r[14]|=r[4];
goto P_0c05b55e;
P_0c05b55e: /* original d313, guest PC 0x0c05b55e */
if(!s->budget--) { s->failed_pc=0x0c05b55eu; return 0; }
r[3]=read(ram,0x0c05b5acu,4);
goto P_0c05b560;
P_0c05b560: /* original 23c8, guest PC 0x0c05b560 */
if(!s->budget--) { s->failed_pc=0x0c05b560u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b562;
P_0c05b562: /* original 8927, guest PC 0x0c05b562 */
if(!s->budget--) { s->failed_pc=0x0c05b562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b5b4; }
goto P_0c05b564;
P_0c05b564: /* original e058, guest PC 0x0c05b564 */
if(!s->budget--) { s->failed_pc=0x0c05b564u; return 0; }
r[0]=0x00000058u;
goto P_0c05b566;
P_0c05b566: /* original 01de, guest PC 0x0c05b566 */
if(!s->budget--) { s->failed_pc=0x0c05b566u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c05b568;
P_0c05b568: /* original 2118, guest PC 0x0c05b568 */
if(!s->budget--) { s->failed_pc=0x0c05b568u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05b56a;
P_0c05b56a: /* original 8921, guest PC 0x0c05b56a */
if(!s->budget--) { s->failed_pc=0x0c05b56au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b5b0; }
goto P_0c05b56c;
P_0c05b56c: /* original a022, guest PC 0x0c05b56c */
if(!s->budget--) { s->failed_pc=0x0c05b56cu; return 0; }
r[14]|=r[6];
goto P_0c05b5b4;
P_0c05b56e: /* original 2e6b, guest PC 0x0c05b56e */
if(!s->budget--) { s->failed_pc=0x0c05b56eu; return 0; }
r[14]|=r[6];
return vf3_matrix_family(0x0c05b570u,s,ram);
P_0c05b5b0: /* original 926d, guest PC 0x0c05b5b0 */
if(!s->budget--) { s->failed_pc=0x0c05b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b68eu,2);
goto P_0c05b5b2;
P_0c05b5b2: /* original 2e29, guest PC 0x0c05b5b2 */
if(!s->budget--) { s->failed_pc=0x0c05b5b2u; return 0; }
r[14]&=r[2];
goto P_0c05b5b4;
P_0c05b5b4: /* original d337, guest PC 0x0c05b5b4 */
if(!s->budget--) { s->failed_pc=0x0c05b5b4u; return 0; }
r[3]=read(ram,0x0c05b694u,4);
goto P_0c05b5b6;
P_0c05b5b6: /* original 23c8, guest PC 0x0c05b5b6 */
if(!s->budget--) { s->failed_pc=0x0c05b5b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b5b8;
P_0c05b5b8: /* original 890b, guest PC 0x0c05b5b8 */
if(!s->budget--) { s->failed_pc=0x0c05b5b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b5d2; }
goto P_0c05b5ba;
P_0c05b5ba: /* original e05c, guest PC 0x0c05b5ba */
if(!s->budget--) { s->failed_pc=0x0c05b5bau; return 0; }
r[0]=0x0000005cu;
goto P_0c05b5bc;
P_0c05b5bc: /* original 00de, guest PC 0x0c05b5bc */
if(!s->budget--) { s->failed_pc=0x0c05b5bcu; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c05b5be;
P_0c05b5be: /* original c90f, guest PC 0x0c05b5be */
if(!s->budget--) { s->failed_pc=0x0c05b5beu; return 0; }
r[0]&=15u;
goto P_0c05b5c0;
P_0c05b5c0: /* original 6403, guest PC 0x0c05b5c0 */
if(!s->budget--) { s->failed_pc=0x0c05b5c0u; return 0; }
r[4]=r[0];
goto P_0c05b5c2;
P_0c05b5c2: /* original 2448, guest PC 0x0c05b5c2 */
if(!s->budget--) { s->failed_pc=0x0c05b5c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05b5c4;
P_0c05b5c4: /* original 8b00, guest PC 0x0c05b5c4 */
if(!s->budget--) { s->failed_pc=0x0c05b5c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b5c8; }
goto P_0c05b5c6;
P_0c05b5c6: /* original e404, guest PC 0x0c05b5c6 */
if(!s->budget--) { s->failed_pc=0x0c05b5c6u; return 0; }
r[4]=0x00000004u;
goto P_0c05b5c8;
P_0c05b5c8: /* original 9262, guest PC 0x0c05b5c8 */
if(!s->budget--) { s->failed_pc=0x0c05b5c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b690u,2);
goto P_0c05b5ca;
P_0c05b5ca: /* original 4418, guest PC 0x0c05b5ca */
if(!s->budget--) { s->failed_pc=0x0c05b5cau; return 0; }
r[4]<<=8;
goto P_0c05b5cc;
P_0c05b5cc: /* original 22e9, guest PC 0x0c05b5cc */
if(!s->budget--) { s->failed_pc=0x0c05b5ccu; return 0; }
r[2]&=r[14];
goto P_0c05b5ce;
P_0c05b5ce: /* original 6e23, guest PC 0x0c05b5ce */
if(!s->budget--) { s->failed_pc=0x0c05b5ceu; return 0; }
r[14]=r[2];
goto P_0c05b5d0;
P_0c05b5d0: /* original 2e4b, guest PC 0x0c05b5d0 */
if(!s->budget--) { s->failed_pc=0x0c05b5d0u; return 0; }
r[14]|=r[4];
goto P_0c05b5d2;
P_0c05b5d2: /* original d331, guest PC 0x0c05b5d2 */
if(!s->budget--) { s->failed_pc=0x0c05b5d2u; return 0; }
r[3]=read(ram,0x0c05b698u,4);
goto P_0c05b5d4;
P_0c05b5d4: /* original 23c8, guest PC 0x0c05b5d4 */
if(!s->budget--) { s->failed_pc=0x0c05b5d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b5d6;
P_0c05b5d6: /* original 8909, guest PC 0x0c05b5d6 */
if(!s->budget--) { s->failed_pc=0x0c05b5d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b5ec; }
goto P_0c05b5d8;
P_0c05b5d8: /* original 935b, guest PC 0x0c05b5d8 */
if(!s->budget--) { s->failed_pc=0x0c05b5d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b692u,2);
goto P_0c05b5da;
P_0c05b5da: /* original e060, guest PC 0x0c05b5da */
if(!s->budget--) { s->failed_pc=0x0c05b5dau; return 0; }
r[0]=0x00000060u;
goto P_0c05b5dc;
P_0c05b5dc: /* original 04de, guest PC 0x0c05b5dc */
if(!s->budget--) { s->failed_pc=0x0c05b5dcu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b5de;
P_0c05b5de: /* original 23e9, guest PC 0x0c05b5de */
if(!s->budget--) { s->failed_pc=0x0c05b5deu; return 0; }
r[3]&=r[14];
goto P_0c05b5e0;
P_0c05b5e0: /* original 2459, guest PC 0x0c05b5e0 */
if(!s->budget--) { s->failed_pc=0x0c05b5e0u; return 0; }
r[4]&=r[5];
goto P_0c05b5e2;
P_0c05b5e2: /* original 4408, guest PC 0x0c05b5e2 */
if(!s->budget--) { s->failed_pc=0x0c05b5e2u; return 0; }
r[4]<<=2;
goto P_0c05b5e4;
P_0c05b5e4: /* original 4408, guest PC 0x0c05b5e4 */
if(!s->budget--) { s->failed_pc=0x0c05b5e4u; return 0; }
r[4]<<=2;
goto P_0c05b5e6;
P_0c05b5e6: /* original 4408, guest PC 0x0c05b5e6 */
if(!s->budget--) { s->failed_pc=0x0c05b5e6u; return 0; }
r[4]<<=2;
goto P_0c05b5e8;
P_0c05b5e8: /* original 6e33, guest PC 0x0c05b5e8 */
if(!s->budget--) { s->failed_pc=0x0c05b5e8u; return 0; }
r[14]=r[3];
goto P_0c05b5ea;
P_0c05b5ea: /* original 2e4b, guest PC 0x0c05b5ea */
if(!s->budget--) { s->failed_pc=0x0c05b5eau; return 0; }
r[14]|=r[4];
goto P_0c05b5ec;
P_0c05b5ec: /* original 50d8, guest PC 0x0c05b5ec */
if(!s->budget--) { s->failed_pc=0x0c05b5ecu; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c05b5ee;
P_0c05b5ee: /* original 4021, guest PC 0x0c05b5ee */
if(!s->budget--) { s->failed_pc=0x0c05b5eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c05b5f0;
P_0c05b5f0: /* original 8801, guest PC 0x0c05b5f0 */
if(!s->budget--) { s->failed_pc=0x0c05b5f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b5f2;
P_0c05b5f2: /* original 8b13, guest PC 0x0c05b5f2 */
if(!s->budget--) { s->failed_pc=0x0c05b5f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b61c; }
goto P_0c05b5f4;
P_0c05b5f4: /* original e06c, guest PC 0x0c05b5f4 */
if(!s->budget--) { s->failed_pc=0x0c05b5f4u; return 0; }
r[0]=0x0000006cu;
goto P_0c05b5f6;
P_0c05b5f6: /* original 02de, guest PC 0x0c05b5f6 */
if(!s->budget--) { s->failed_pc=0x0c05b5f6u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b5f8;
P_0c05b5f8: /* original 2228, guest PC 0x0c05b5f8 */
if(!s->budget--) { s->failed_pc=0x0c05b5f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b5fa;
P_0c05b5fa: /* original 890f, guest PC 0x0c05b5fa */
if(!s->budget--) { s->failed_pc=0x0c05b5fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b61c; }
goto P_0c05b5fc;
P_0c05b5fc: /* original 04de, guest PC 0x0c05b5fc */
if(!s->budget--) { s->failed_pc=0x0c05b5fcu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b5fe;
P_0c05b5fe: /* original e3c7, guest PC 0x0c05b5fe */
if(!s->budget--) { s->failed_pc=0x0c05b5feu; return 0; }
r[3]=0xffffffc7u;
goto P_0c05b600;
P_0c05b600: /* original 2e39, guest PC 0x0c05b600 */
if(!s->budget--) { s->failed_pc=0x0c05b600u; return 0; }
r[14]&=r[3];
goto P_0c05b602;
P_0c05b602: /* original bcab, guest PC 0x0c05b602 */
if(!s->budget--) { s->failed_pc=0x0c05b602u; return 0; }
target=0x0c05af5cu; r[16]=0x0c05b606u;
r[4]=read(ram,r[4]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05b606u) { target=s->pc; goto dispatch; }
goto P_0c05b606;
P_0c05b604: /* original 5443, guest PC 0x0c05b604 */
if(!s->budget--) { s->failed_pc=0x0c05b604u; return 0; }
r[4]=read(ram,r[4]+12,4);
goto P_0c05b606;
P_0c05b606: /* original 4008, guest PC 0x0c05b606 */
if(!s->budget--) { s->failed_pc=0x0c05b606u; return 0; }
r[0]<<=2;
goto P_0c05b608;
P_0c05b608: /* original 4000, guest PC 0x0c05b608 */
if(!s->budget--) { s->failed_pc=0x0c05b608u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05b60a;
P_0c05b60a: /* original 2e0b, guest PC 0x0c05b60a */
if(!s->budget--) { s->failed_pc=0x0c05b60au; return 0; }
r[14]|=r[0];
goto P_0c05b60c;
P_0c05b60c: /* original 1fe1, guest PC 0x0c05b60c */
if(!s->budget--) { s->failed_pc=0x0c05b60cu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c05b60e;
P_0c05b60e: /* original e3f8, guest PC 0x0c05b60e */
if(!s->budget--) { s->failed_pc=0x0c05b60eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c05b610;
P_0c05b610: /* original 2e39, guest PC 0x0c05b610 */
if(!s->budget--) { s->failed_pc=0x0c05b610u; return 0; }
r[14]&=r[3];
goto P_0c05b612;
P_0c05b612: /* original e06c, guest PC 0x0c05b612 */
if(!s->budget--) { s->failed_pc=0x0c05b612u; return 0; }
r[0]=0x0000006cu;
goto P_0c05b614;
P_0c05b614: /* original 04de, guest PC 0x0c05b614 */
if(!s->budget--) { s->failed_pc=0x0c05b614u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b616;
P_0c05b616: /* original bca1, guest PC 0x0c05b616 */
if(!s->budget--) { s->failed_pc=0x0c05b616u; return 0; }
target=0x0c05af5cu; r[16]=0x0c05b61au;
r[4]=read(ram,r[4]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05b61au) { target=s->pc; goto dispatch; }
goto P_0c05b61a;
P_0c05b618: /* original 5444, guest PC 0x0c05b618 */
if(!s->budget--) { s->failed_pc=0x0c05b618u; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c05b61a;
P_0c05b61a: /* original 2e0b, guest PC 0x0c05b61a */
if(!s->budget--) { s->failed_pc=0x0c05b61au; return 0; }
r[14]|=r[0];
goto P_0c05b61c;
P_0c05b61c: /* original 50d8, guest PC 0x0c05b61c */
if(!s->budget--) { s->failed_pc=0x0c05b61cu; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c05b61e;
P_0c05b61e: /* original e610, guest PC 0x0c05b61e */
if(!s->budget--) { s->failed_pc=0x0c05b61eu; return 0; }
r[6]=0x00000010u;
goto P_0c05b620;
P_0c05b620: /* original 4021, guest PC 0x0c05b620 */
if(!s->budget--) { s->failed_pc=0x0c05b620u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c05b622;
P_0c05b622: /* original 8801, guest PC 0x0c05b622 */
if(!s->budget--) { s->failed_pc=0x0c05b622u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b624;
P_0c05b624: /* original 8f64, guest PC 0x0c05b624 */
if(!s->budget--) { s->failed_pc=0x0c05b624u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(!cond) { goto P_0c05b6f0; }
goto P_0c05b628;
P_0c05b626: /* original e504, guest PC 0x0c05b626 */
if(!s->budget--) { s->failed_pc=0x0c05b626u; return 0; }
r[5]=0x00000004u;
goto P_0c05b628;
P_0c05b628: /* original e06c, guest PC 0x0c05b628 */
if(!s->budget--) { s->failed_pc=0x0c05b628u; return 0; }
r[0]=0x0000006cu;
goto P_0c05b62a;
P_0c05b62a: /* original 02de, guest PC 0x0c05b62a */
if(!s->budget--) { s->failed_pc=0x0c05b62au; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b62c;
P_0c05b62c: /* original 2228, guest PC 0x0c05b62c */
if(!s->budget--) { s->failed_pc=0x0c05b62cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b62e;
P_0c05b62e: /* original 895f, guest PC 0x0c05b62e */
if(!s->budget--) { s->failed_pc=0x0c05b62eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b6f0; }
goto P_0c05b630;
P_0c05b630: /* original d31a, guest PC 0x0c05b630 */
if(!s->budget--) { s->failed_pc=0x0c05b630u; return 0; }
r[3]=read(ram,0x0c05b69cu,4);
goto P_0c05b632;
P_0c05b632: /* original e06c, guest PC 0x0c05b632 */
if(!s->budget--) { s->failed_pc=0x0c05b632u; return 0; }
r[0]=0x0000006cu;
goto P_0c05b634;
P_0c05b634: /* original 62f2, guest PC 0x0c05b634 */
if(!s->budget--) { s->failed_pc=0x0c05b634u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05b636;
P_0c05b636: /* original e108, guest PC 0x0c05b636 */
if(!s->budget--) { s->failed_pc=0x0c05b636u; return 0; }
r[1]=0x00000008u;
goto P_0c05b638;
P_0c05b638: /* original 04de, guest PC 0x0c05b638 */
if(!s->budget--) { s->failed_pc=0x0c05b638u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b63a;
P_0c05b63a: /* original 2239, guest PC 0x0c05b63a */
if(!s->budget--) { s->failed_pc=0x0c05b63au; return 0; }
r[2]&=r[3];
goto P_0c05b63c;
P_0c05b63c: /* original 5746, guest PC 0x0c05b63c */
if(!s->budget--) { s->failed_pc=0x0c05b63cu; return 0; }
r[7]=read(ram,r[4]+24,4);
goto P_0c05b63e;
P_0c05b63e: /* original e001, guest PC 0x0c05b63e */
if(!s->budget--) { s->failed_pc=0x0c05b63eu; return 0; }
r[0]=0x00000001u;
goto P_0c05b640;
P_0c05b640: /* original 2079, guest PC 0x0c05b640 */
if(!s->budget--) { s->failed_pc=0x0c05b640u; return 0; }
r[0]&=r[7];
goto P_0c05b642;
P_0c05b642: /* original c901, guest PC 0x0c05b642 */
if(!s->budget--) { s->failed_pc=0x0c05b642u; return 0; }
r[0]&=1u;
goto P_0c05b644;
P_0c05b644: /* original 4005, guest PC 0x0c05b644 */
if(!s->budget--) { s->failed_pc=0x0c05b644u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c05b646;
P_0c05b646: /* original 220b, guest PC 0x0c05b646 */
if(!s->budget--) { s->failed_pc=0x0c05b646u; return 0; }
r[2]|=r[0];
goto P_0c05b648;
P_0c05b648: /* original 2f22, guest PC 0x0c05b648 */
if(!s->budget--) { s->failed_pc=0x0c05b648u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c05b64a;
P_0c05b64a: /* original 2719, guest PC 0x0c05b64a */
if(!s->budget--) { s->failed_pc=0x0c05b64au; return 0; }
r[7]&=r[1];
goto P_0c05b64c;
P_0c05b64c: /* original d214, guest PC 0x0c05b64c */
if(!s->budget--) { s->failed_pc=0x0c05b64cu; return 0; }
r[2]=read(ram,0x0c05b6a0u,4);
goto P_0c05b64e;
P_0c05b64e: /* original e31b, guest PC 0x0c05b64e */
if(!s->budget--) { s->failed_pc=0x0c05b64eu; return 0; }
r[3]=0x0000001bu;
goto P_0c05b650;
P_0c05b650: /* original 60f2, guest PC 0x0c05b650 */
if(!s->budget--) { s->failed_pc=0x0c05b650u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05b652;
P_0c05b652: /* original 473d, guest PC 0x0c05b652 */
if(!s->budget--) { s->failed_pc=0x0c05b652u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c05b654;
P_0c05b654: /* original d314, guest PC 0x0c05b654 */
if(!s->budget--) { s->failed_pc=0x0c05b654u; return 0; }
r[3]=read(ram,0x0c05b6a8u,4);
goto P_0c05b656;
P_0c05b656: /* original 2029, guest PC 0x0c05b656 */
if(!s->budget--) { s->failed_pc=0x0c05b656u; return 0; }
r[0]&=r[2];
goto P_0c05b658;
P_0c05b658: /* original 270b, guest PC 0x0c05b658 */
if(!s->budget--) { s->failed_pc=0x0c05b658u; return 0; }
r[7]|=r[0];
goto P_0c05b65a;
P_0c05b65a: /* original 2f72, guest PC 0x0c05b65a */
if(!s->budget--) { s->failed_pc=0x0c05b65au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05b65c;
P_0c05b65c: /* original d711, guest PC 0x0c05b65c */
if(!s->budget--) { s->failed_pc=0x0c05b65cu; return 0; }
r[7]=read(ram,0x0c05b6a4u,4);
goto P_0c05b65e;
P_0c05b65e: /* original 60f2, guest PC 0x0c05b65e */
if(!s->budget--) { s->failed_pc=0x0c05b65eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05b660;
P_0c05b660: /* original 5242, guest PC 0x0c05b660 */
if(!s->budget--) { s->failed_pc=0x0c05b660u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c05b662;
P_0c05b662: /* original 2039, guest PC 0x0c05b662 */
if(!s->budget--) { s->failed_pc=0x0c05b662u; return 0; }
r[0]&=r[3];
goto P_0c05b664;
P_0c05b664: /* original 2279, guest PC 0x0c05b664 */
if(!s->budget--) { s->failed_pc=0x0c05b664u; return 0; }
r[2]&=r[7];
goto P_0c05b666;
P_0c05b666: /* original 6403, guest PC 0x0c05b666 */
if(!s->budget--) { s->failed_pc=0x0c05b666u; return 0; }
r[4]=r[0];
goto P_0c05b668;
P_0c05b668: /* original 242b, guest PC 0x0c05b668 */
if(!s->budget--) { s->failed_pc=0x0c05b668u; return 0; }
r[4]|=r[2];
goto P_0c05b66a;
P_0c05b66a: /* original 2749, guest PC 0x0c05b66a */
if(!s->budget--) { s->failed_pc=0x0c05b66au; return 0; }
r[7]&=r[4];
goto P_0c05b66c;
P_0c05b66c: /* original d20f, guest PC 0x0c05b66c */
if(!s->budget--) { s->failed_pc=0x0c05b66cu; return 0; }
r[2]=read(ram,0x0c05b6acu,4);
goto P_0c05b66e;
P_0c05b66e: /* original 3720, guest PC 0x0c05b66e */
if(!s->budget--) { s->failed_pc=0x0c05b66eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c05b670;
P_0c05b670: /* original 8d04, guest PC 0x0c05b670 */
if(!s->budget--) { s->failed_pc=0x0c05b670u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[7],4);
if(cond) { goto P_0c05b67c; }
goto P_0c05b674;
P_0c05b672: /* original 2f72, guest PC 0x0c05b672 */
if(!s->budget--) { s->failed_pc=0x0c05b672u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05b674;
P_0c05b674: /* original d00e, guest PC 0x0c05b674 */
if(!s->budget--) { s->failed_pc=0x0c05b674u; return 0; }
r[0]=read(ram,0x0c05b6b0u,4);
goto P_0c05b676;
P_0c05b676: /* original 61f2, guest PC 0x0c05b676 */
if(!s->budget--) { s->failed_pc=0x0c05b676u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05b678;
P_0c05b678: /* original 3100, guest PC 0x0c05b678 */
if(!s->budget--) { s->failed_pc=0x0c05b678u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c05b67a;
P_0c05b67a: /* original 8b1d, guest PC 0x0c05b67a */
if(!s->budget--) { s->failed_pc=0x0c05b67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b6b8; }
goto P_0c05b67c;
P_0c05b67c: /* original d70d, guest PC 0x0c05b67c */
if(!s->budget--) { s->failed_pc=0x0c05b67cu; return 0; }
r[7]=read(ram,0x0c05b6b4u,4);
goto P_0c05b67e;
P_0c05b67e: /* original e068, guest PC 0x0c05b67e */
if(!s->budget--) { s->failed_pc=0x0c05b67eu; return 0; }
r[0]=0x00000068u;
goto P_0c05b680;
P_0c05b680: /* original 00de, guest PC 0x0c05b680 */
if(!s->budget--) { s->failed_pc=0x0c05b680u; return 0; }
r[0]=read(ram,r[13]+r[0],4);
goto P_0c05b682;
P_0c05b682: /* original e315, guest PC 0x0c05b682 */
if(!s->budget--) { s->failed_pc=0x0c05b682u; return 0; }
r[3]=0x00000015u;
goto P_0c05b684;
P_0c05b684: /* original 2749, guest PC 0x0c05b684 */
if(!s->budget--) { s->failed_pc=0x0c05b684u; return 0; }
r[7]&=r[4];
goto P_0c05b686;
P_0c05b686: /* original c93f, guest PC 0x0c05b686 */
if(!s->budget--) { s->failed_pc=0x0c05b686u; return 0; }
r[0]&=63u;
goto P_0c05b688;
P_0c05b688: /* original 403d, guest PC 0x0c05b688 */
if(!s->budget--) { s->failed_pc=0x0c05b688u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c05b68a;
P_0c05b68a: /* original a028, guest PC 0x0c05b68a */
if(!s->budget--) { s->failed_pc=0x0c05b68au; return 0; }
r[7]|=r[0];
goto P_0c05b6de;
P_0c05b68c: /* original 270b, guest PC 0x0c05b68c */
if(!s->budget--) { s->failed_pc=0x0c05b68cu; return 0; }
r[7]|=r[0];
return vf3_matrix_family(0x0c05b68eu,s,ram);
P_0c05b6b8: /* original d333, guest PC 0x0c05b6b8 */
if(!s->budget--) { s->failed_pc=0x0c05b6b8u; return 0; }
r[3]=read(ram,0x0c05b788u,4);
goto P_0c05b6ba;
P_0c05b6ba: /* original e06c, guest PC 0x0c05b6ba */
if(!s->budget--) { s->failed_pc=0x0c05b6bau; return 0; }
r[0]=0x0000006cu;
goto P_0c05b6bc;
P_0c05b6bc: /* original 02de, guest PC 0x0c05b6bc */
if(!s->budget--) { s->failed_pc=0x0c05b6bcu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b6be;
P_0c05b6be: /* original 2439, guest PC 0x0c05b6be */
if(!s->budget--) { s->failed_pc=0x0c05b6beu; return 0; }
r[4]&=r[3];
goto P_0c05b6c0;
P_0c05b6c0: /* original 5126, guest PC 0x0c05b6c0 */
if(!s->budget--) { s->failed_pc=0x0c05b6c0u; return 0; }
r[1]=read(ram,r[2]+24,4);
goto P_0c05b6c2;
P_0c05b6c2: /* original e215, guest PC 0x0c05b6c2 */
if(!s->budget--) { s->failed_pc=0x0c05b6c2u; return 0; }
r[2]=0x00000015u;
goto P_0c05b6c4;
P_0c05b6c4: /* original 2f12, guest PC 0x0c05b6c4 */
if(!s->budget--) { s->failed_pc=0x0c05b6c4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c05b6c6;
P_0c05b6c6: /* original 2159, guest PC 0x0c05b6c6 */
if(!s->budget--) { s->failed_pc=0x0c05b6c6u; return 0; }
r[1]&=r[5];
goto P_0c05b6c8;
P_0c05b6c8: /* original 67f2, guest PC 0x0c05b6c8 */
if(!s->budget--) { s->failed_pc=0x0c05b6c8u; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c05b6ca;
P_0c05b6ca: /* original 6117, guest PC 0x0c05b6ca */
if(!s->budget--) { s->failed_pc=0x0c05b6cau; return 0; }
r[1]=~r[1];
goto P_0c05b6cc;
P_0c05b6cc: /* original 2159, guest PC 0x0c05b6cc */
if(!s->budget--) { s->failed_pc=0x0c05b6ccu; return 0; }
r[1]&=r[5];
goto P_0c05b6ce;
P_0c05b6ce: /* original 4128, guest PC 0x0c05b6ce */
if(!s->budget--) { s->failed_pc=0x0c05b6ceu; return 0; }
r[1]<<=16;
goto P_0c05b6d0;
P_0c05b6d0: /* original 4118, guest PC 0x0c05b6d0 */
if(!s->budget--) { s->failed_pc=0x0c05b6d0u; return 0; }
r[1]<<=8;
goto P_0c05b6d2;
P_0c05b6d2: /* original 241b, guest PC 0x0c05b6d2 */
if(!s->budget--) { s->failed_pc=0x0c05b6d2u; return 0; }
r[4]|=r[1];
goto P_0c05b6d4;
P_0c05b6d4: /* original d12d, guest PC 0x0c05b6d4 */
if(!s->budget--) { s->failed_pc=0x0c05b6d4u; return 0; }
r[1]=read(ram,0x0c05b78cu,4);
goto P_0c05b6d6;
P_0c05b6d6: /* original 2769, guest PC 0x0c05b6d6 */
if(!s->budget--) { s->failed_pc=0x0c05b6d6u; return 0; }
r[7]&=r[6];
goto P_0c05b6d8;
P_0c05b6d8: /* original 472d, guest PC 0x0c05b6d8 */
if(!s->budget--) { s->failed_pc=0x0c05b6d8u; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?r[7]>>((-r[2])&31u):0):r[7]<<(r[2]&31u);
goto P_0c05b6da;
P_0c05b6da: /* original 2419, guest PC 0x0c05b6da */
if(!s->budget--) { s->failed_pc=0x0c05b6dau; return 0; }
r[4]&=r[1];
goto P_0c05b6dc;
P_0c05b6dc: /* original 274b, guest PC 0x0c05b6dc */
if(!s->budget--) { s->failed_pc=0x0c05b6dcu; return 0; }
r[7]|=r[4];
goto P_0c05b6de;
P_0c05b6de: /* original e06c, guest PC 0x0c05b6de */
if(!s->budget--) { s->failed_pc=0x0c05b6deu; return 0; }
r[0]=0x0000006cu;
goto P_0c05b6e0;
P_0c05b6e0: /* original d32b, guest PC 0x0c05b6e0 */
if(!s->budget--) { s->failed_pc=0x0c05b6e0u; return 0; }
r[3]=read(ram,0x0c05b790u,4);
goto P_0c05b6e2;
P_0c05b6e2: /* original 2739, guest PC 0x0c05b6e2 */
if(!s->budget--) { s->failed_pc=0x0c05b6e2u; return 0; }
r[7]&=r[3];
goto P_0c05b6e4;
P_0c05b6e4: /* original 02de, guest PC 0x0c05b6e4 */
if(!s->budget--) { s->failed_pc=0x0c05b6e4u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b6e6;
P_0c05b6e6: /* original 5127, guest PC 0x0c05b6e6 */
if(!s->budget--) { s->failed_pc=0x0c05b6e6u; return 0; }
r[1]=read(ram,r[2]+28,4);
goto P_0c05b6e8;
P_0c05b6e8: /* original 4109, guest PC 0x0c05b6e8 */
if(!s->budget--) { s->failed_pc=0x0c05b6e8u; return 0; }
r[1]>>=2;
goto P_0c05b6ea;
P_0c05b6ea: /* original 4101, guest PC 0x0c05b6ea */
if(!s->budget--) { s->failed_pc=0x0c05b6eau; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05b6ec;
P_0c05b6ec: /* original 271b, guest PC 0x0c05b6ec */
if(!s->budget--) { s->failed_pc=0x0c05b6ecu; return 0; }
r[7]|=r[1];
goto P_0c05b6ee;
P_0c05b6ee: /* original 2f72, guest PC 0x0c05b6ee */
if(!s->budget--) { s->failed_pc=0x0c05b6eeu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c05b6f0;
P_0c05b6f0: /* original d328, guest PC 0x0c05b6f0 */
if(!s->budget--) { s->failed_pc=0x0c05b6f0u; return 0; }
r[3]=read(ram,0x0c05b794u,4);
goto P_0c05b6f2;
P_0c05b6f2: /* original 23c8, guest PC 0x0c05b6f2 */
if(!s->budget--) { s->failed_pc=0x0c05b6f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b6f4;
P_0c05b6f4: /* original 8913, guest PC 0x0c05b6f4 */
if(!s->budget--) { s->failed_pc=0x0c05b6f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b71e; }
goto P_0c05b6f6;
P_0c05b6f6: /* original 54d1, guest PC 0x0c05b6f6 */
if(!s->budget--) { s->failed_pc=0x0c05b6f6u; return 0; }
r[4]=read(ram,r[13]+4,4);
goto P_0c05b6f8;
P_0c05b6f8: /* original 2448, guest PC 0x0c05b6f8 */
if(!s->budget--) { s->failed_pc=0x0c05b6f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05b6fa;
P_0c05b6fa: /* original 8f04, guest PC 0x0c05b6fa */
if(!s->budget--) { s->failed_pc=0x0c05b6fau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c05b706; }
goto P_0c05b6fe;
P_0c05b6fc: /* original 6043, guest PC 0x0c05b6fc */
if(!s->budget--) { s->failed_pc=0x0c05b6fcu; return 0; }
r[0]=r[4];
goto P_0c05b6fe;
P_0c05b6fe: /* original 62a3, guest PC 0x0c05b6fe */
if(!s->budget--) { s->failed_pc=0x0c05b6feu; return 0; }
r[2]=r[10];
goto P_0c05b700;
P_0c05b700: /* original da25, guest PC 0x0c05b700 */
if(!s->budget--) { s->failed_pc=0x0c05b700u; return 0; }
r[10]=read(ram,0x0c05b798u,4);
goto P_0c05b702;
P_0c05b702: /* original 2299, guest PC 0x0c05b702 */
if(!s->budget--) { s->failed_pc=0x0c05b702u; return 0; }
r[2]&=r[9];
goto P_0c05b704;
P_0c05b704: /* original 2a2b, guest PC 0x0c05b704 */
if(!s->budget--) { s->failed_pc=0x0c05b704u; return 0; }
r[10]|=r[2];
goto P_0c05b706;
P_0c05b706: /* original 8801, guest PC 0x0c05b706 */
if(!s->budget--) { s->failed_pc=0x0c05b706u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b708;
P_0c05b708: /* original 8f04, guest PC 0x0c05b708 */
if(!s->budget--) { s->failed_pc=0x0c05b708u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c05b714; }
goto P_0c05b70c;
P_0c05b70a: /* original 6043, guest PC 0x0c05b70a */
if(!s->budget--) { s->failed_pc=0x0c05b70au; return 0; }
r[0]=r[4];
goto P_0c05b70c;
P_0c05b70c: /* original 62a3, guest PC 0x0c05b70c */
if(!s->budget--) { s->failed_pc=0x0c05b70cu; return 0; }
r[2]=r[10];
goto P_0c05b70e;
P_0c05b70e: /* original 2299, guest PC 0x0c05b70e */
if(!s->budget--) { s->failed_pc=0x0c05b70eu; return 0; }
r[2]&=r[9];
goto P_0c05b710;
P_0c05b710: /* original da21, guest PC 0x0c05b710 */
if(!s->budget--) { s->failed_pc=0x0c05b710u; return 0; }
r[10]=read(ram,0x0c05b798u,4);
goto P_0c05b712;
P_0c05b712: /* original 2a2b, guest PC 0x0c05b712 */
if(!s->budget--) { s->failed_pc=0x0c05b712u; return 0; }
r[10]|=r[2];
goto P_0c05b714;
P_0c05b714: /* original 8802, guest PC 0x0c05b714 */
if(!s->budget--) { s->failed_pc=0x0c05b714u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05b716;
P_0c05b716: /* original 8b02, guest PC 0x0c05b716 */
if(!s->budget--) { s->failed_pc=0x0c05b716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b71e; }
goto P_0c05b718;
P_0c05b718: /* original 29a9, guest PC 0x0c05b718 */
if(!s->budget--) { s->failed_pc=0x0c05b718u; return 0; }
r[9]&=r[10];
goto P_0c05b71a;
P_0c05b71a: /* original da20, guest PC 0x0c05b71a */
if(!s->budget--) { s->failed_pc=0x0c05b71au; return 0; }
r[10]=read(ram,0x0c05b79cu,4);
goto P_0c05b71c;
P_0c05b71c: /* original 2a9b, guest PC 0x0c05b71c */
if(!s->budget--) { s->failed_pc=0x0c05b71cu; return 0; }
r[10]|=r[9];
goto P_0c05b71e;
P_0c05b71e: /* original d220, guest PC 0x0c05b71e */
if(!s->budget--) { s->failed_pc=0x0c05b71eu; return 0; }
r[2]=read(ram,0x0c05b7a0u,4);
goto P_0c05b720;
P_0c05b720: /* original 22c8, guest PC 0x0c05b720 */
if(!s->budget--) { s->failed_pc=0x0c05b720u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c05b722;
P_0c05b722: /* original 8906, guest PC 0x0c05b722 */
if(!s->budget--) { s->failed_pc=0x0c05b722u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b732; }
goto P_0c05b724;
P_0c05b724: /* original d11f, guest PC 0x0c05b724 */
if(!s->budget--) { s->failed_pc=0x0c05b724u; return 0; }
r[1]=read(ram,0x0c05b7a4u,4);
goto P_0c05b726;
P_0c05b726: /* original 21a9, guest PC 0x0c05b726 */
if(!s->budget--) { s->failed_pc=0x0c05b726u; return 0; }
r[1]&=r[10];
goto P_0c05b728;
P_0c05b728: /* original 53d2, guest PC 0x0c05b728 */
if(!s->budget--) { s->failed_pc=0x0c05b728u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c05b72a;
P_0c05b72a: /* original 6a13, guest PC 0x0c05b72a */
if(!s->budget--) { s->failed_pc=0x0c05b72au; return 0; }
r[10]=r[1];
goto P_0c05b72c;
P_0c05b72c: /* original 4328, guest PC 0x0c05b72c */
if(!s->budget--) { s->failed_pc=0x0c05b72cu; return 0; }
r[3]<<=16;
goto P_0c05b72e;
P_0c05b72e: /* original 4318, guest PC 0x0c05b72e */
if(!s->budget--) { s->failed_pc=0x0c05b72eu; return 0; }
r[3]<<=8;
goto P_0c05b730;
P_0c05b730: /* original 2a3b, guest PC 0x0c05b730 */
if(!s->budget--) { s->failed_pc=0x0c05b730u; return 0; }
r[10]|=r[3];
goto P_0c05b732;
P_0c05b732: /* original d21d, guest PC 0x0c05b732 */
if(!s->budget--) { s->failed_pc=0x0c05b732u; return 0; }
r[2]=read(ram,0x0c05b7a8u,4);
goto P_0c05b734;
P_0c05b734: /* original d71d, guest PC 0x0c05b734 */
if(!s->budget--) { s->failed_pc=0x0c05b734u; return 0; }
r[7]=read(ram,0x0c05b7acu,4);
goto P_0c05b736;
P_0c05b736: /* original 2a2b, guest PC 0x0c05b736 */
if(!s->budget--) { s->failed_pc=0x0c05b736u; return 0; }
r[10]|=r[2];
goto P_0c05b738;
P_0c05b738: /* original d31d, guest PC 0x0c05b738 */
if(!s->budget--) { s->failed_pc=0x0c05b738u; return 0; }
r[3]=read(ram,0x0c05b7b0u,4);
goto P_0c05b73a;
P_0c05b73a: /* original 23c8, guest PC 0x0c05b73a */
if(!s->budget--) { s->failed_pc=0x0c05b73au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c05b73c;
P_0c05b73c: /* original 8d03, guest PC 0x0c05b73c */
if(!s->budget--) { s->failed_pc=0x0c05b73cu; return 0; }
cond=r[17]&1u;
r[7]&=r[10];
if(cond) { goto P_0c05b746; }
goto P_0c05b740;
P_0c05b73e: /* original 27a9, guest PC 0x0c05b73e */
if(!s->budget--) { s->failed_pc=0x0c05b73eu; return 0; }
r[7]&=r[10];
goto P_0c05b740;
P_0c05b740: /* original 901d, guest PC 0x0c05b740 */
if(!s->budget--) { s->failed_pc=0x0c05b740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b77eu,2);
goto P_0c05b742;
P_0c05b742: /* original a002, guest PC 0x0c05b742 */
if(!s->budget--) { s->failed_pc=0x0c05b742u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b74a;
P_0c05b744: /* original 04de, guest PC 0x0c05b744 */
if(!s->budget--) { s->failed_pc=0x0c05b744u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c05b746;
P_0c05b746: /* original d31b, guest PC 0x0c05b746 */
if(!s->budget--) { s->failed_pc=0x0c05b746u; return 0; }
r[3]=read(ram,0x0c05b7b4u,4);
goto P_0c05b748;
P_0c05b748: /* original 6432, guest PC 0x0c05b748 */
if(!s->budget--) { s->failed_pc=0x0c05b748u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05b74a;
P_0c05b74a: /* original 4428, guest PC 0x0c05b74a */
if(!s->budget--) { s->failed_pc=0x0c05b74au; return 0; }
r[4]<<=16;
goto P_0c05b74c;
P_0c05b74c: /* original d21a, guest PC 0x0c05b74c */
if(!s->budget--) { s->failed_pc=0x0c05b74cu; return 0; }
r[2]=read(ram,0x0c05b7b8u,4);
goto P_0c05b74e;
P_0c05b74e: /* original 4408, guest PC 0x0c05b74e */
if(!s->budget--) { s->failed_pc=0x0c05b74eu; return 0; }
r[4]<<=2;
goto P_0c05b750;
P_0c05b750: /* original 22c8, guest PC 0x0c05b750 */
if(!s->budget--) { s->failed_pc=0x0c05b750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c05b752;
P_0c05b752: /* original 8d07, guest PC 0x0c05b752 */
if(!s->budget--) { s->failed_pc=0x0c05b752u; return 0; }
cond=r[17]&1u;
r[4]|=r[7];
if(cond) { goto P_0c05b764; }
goto P_0c05b756;
P_0c05b754: /* original 247b, guest PC 0x0c05b754 */
if(!s->budget--) { s->failed_pc=0x0c05b754u; return 0; }
r[4]|=r[7];
goto P_0c05b756;
P_0c05b756: /* original d119, guest PC 0x0c05b756 */
if(!s->budget--) { s->failed_pc=0x0c05b756u; return 0; }
r[1]=read(ram,0x0c05b7bcu,4);
goto P_0c05b758;
P_0c05b758: /* original 9012, guest PC 0x0c05b758 */
if(!s->budget--) { s->failed_pc=0x0c05b758u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b780u,2);
goto P_0c05b75a;
P_0c05b75a: /* original 2149, guest PC 0x0c05b75a */
if(!s->budget--) { s->failed_pc=0x0c05b75au; return 0; }
r[1]&=r[4];
goto P_0c05b75c;
P_0c05b75c: /* original 03de, guest PC 0x0c05b75c */
if(!s->budget--) { s->failed_pc=0x0c05b75cu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05b75e;
P_0c05b75e: /* original 6413, guest PC 0x0c05b75e */
if(!s->budget--) { s->failed_pc=0x0c05b75eu; return 0; }
r[4]=r[1];
goto P_0c05b760;
P_0c05b760: /* original 4328, guest PC 0x0c05b760 */
if(!s->budget--) { s->failed_pc=0x0c05b760u; return 0; }
r[3]<<=16;
goto P_0c05b762;
P_0c05b762: /* original 243b, guest PC 0x0c05b762 */
if(!s->budget--) { s->failed_pc=0x0c05b762u; return 0; }
r[4]|=r[3];
goto P_0c05b764;
P_0c05b764: /* original 970d, guest PC 0x0c05b764 */
if(!s->budget--) { s->failed_pc=0x0c05b764u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b782u,2);
goto P_0c05b766;
P_0c05b766: /* original d316, guest PC 0x0c05b766 */
if(!s->budget--) { s->failed_pc=0x0c05b766u; return 0; }
r[3]=read(ram,0x0c05b7c0u,4);
goto P_0c05b768;
P_0c05b768: /* original 900c, guest PC 0x0c05b768 */
if(!s->budget--) { s->failed_pc=0x0c05b768u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b784u,2);
goto P_0c05b76a;
P_0c05b76a: /* original 02de, guest PC 0x0c05b76a */
if(!s->budget--) { s->failed_pc=0x0c05b76au; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c05b76c;
P_0c05b76c: /* original 2238, guest PC 0x0c05b76c */
if(!s->budget--) { s->failed_pc=0x0c05b76cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c05b76e;
P_0c05b76e: /* original 8d29, guest PC 0x0c05b76e */
if(!s->budget--) { s->failed_pc=0x0c05b76eu; return 0; }
cond=r[17]&1u;
r[7]&=r[4];
if(cond) { goto P_0c05b7c4; }
goto P_0c05b772;
P_0c05b770: /* original 2749, guest PC 0x0c05b770 */
if(!s->budget--) { s->failed_pc=0x0c05b770u; return 0; }
r[7]&=r[4];
goto P_0c05b772;
P_0c05b772: /* original 50d2, guest PC 0x0c05b772 */
if(!s->budget--) { s->failed_pc=0x0c05b772u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c05b774;
P_0c05b774: /* original c801, guest PC 0x0c05b774 */
if(!s->budget--) { s->failed_pc=0x0c05b774u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05b776;
P_0c05b776: /* original 8925, guest PC 0x0c05b776 */
if(!s->budget--) { s->failed_pc=0x0c05b776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b7c4; }
goto P_0c05b778;
P_0c05b778: /* original e440, guest PC 0x0c05b778 */
if(!s->budget--) { s->failed_pc=0x0c05b778u; return 0; }
r[4]=0x00000040u;
goto P_0c05b77a;
P_0c05b77a: /* original a024, guest PC 0x0c05b77a */
if(!s->budget--) { s->failed_pc=0x0c05b77au; return 0; }
r[4]|=r[7];
goto P_0c05b7c6;
P_0c05b77c: /* original 247b, guest PC 0x0c05b77c */
if(!s->budget--) { s->failed_pc=0x0c05b77cu; return 0; }
r[4]|=r[7];
return vf3_matrix_family(0x0c05b77eu,s,ram);
P_0c05b7c4: /* original 6473, guest PC 0x0c05b7c4 */
if(!s->budget--) { s->failed_pc=0x0c05b7c4u; return 0; }
r[4]=r[7];
goto P_0c05b7c6;
P_0c05b7c6: /* original 26c8, guest PC 0x0c05b7c6 */
if(!s->budget--) { s->failed_pc=0x0c05b7c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[12])==0)!=0);
goto P_0c05b7c8;
P_0c05b7c8: /* original 8910, guest PC 0x0c05b7c8 */
if(!s->budget--) { s->failed_pc=0x0c05b7c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b7ec; }
goto P_0c05b7ca;
P_0c05b7ca: /* original 50d9, guest PC 0x0c05b7ca */
if(!s->budget--) { s->failed_pc=0x0c05b7cau; return 0; }
r[0]=read(ram,r[13]+36,4);
goto P_0c05b7cc;
P_0c05b7cc: /* original c801, guest PC 0x0c05b7cc */
if(!s->budget--) { s->failed_pc=0x0c05b7ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05b7ce;
P_0c05b7ce: /* original 890d, guest PC 0x0c05b7ce */
if(!s->budget--) { s->failed_pc=0x0c05b7ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b7ec; }
goto P_0c05b7d0;
P_0c05b7d0: /* original 9653, guest PC 0x0c05b7d0 */
if(!s->budget--) { s->failed_pc=0x0c05b7d0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b87au,2);
goto P_0c05b7d2;
P_0c05b7d2: /* original e307, guest PC 0x0c05b7d2 */
if(!s->budget--) { s->failed_pc=0x0c05b7d2u; return 0; }
r[3]=0x00000007u;
goto P_0c05b7d4;
P_0c05b7d4: /* original 52d9, guest PC 0x0c05b7d4 */
if(!s->budget--) { s->failed_pc=0x0c05b7d4u; return 0; }
r[2]=read(ram,r[13]+36,4);
goto P_0c05b7d6;
P_0c05b7d6: /* original 2649, guest PC 0x0c05b7d6 */
if(!s->budget--) { s->failed_pc=0x0c05b7d6u; return 0; }
r[6]&=r[4];
goto P_0c05b7d8;
P_0c05b7d8: /* original d129, guest PC 0x0c05b7d8 */
if(!s->budget--) { s->failed_pc=0x0c05b7d8u; return 0; }
r[1]=read(ram,0x0c05b880u,4);
goto P_0c05b7da;
P_0c05b7da: /* original 423d, guest PC 0x0c05b7da */
if(!s->budget--) { s->failed_pc=0x0c05b7dau; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05b7dc;
P_0c05b7dc: /* original 262b, guest PC 0x0c05b7dc */
if(!s->budget--) { s->failed_pc=0x0c05b7dcu; return 0; }
r[6]|=r[2];
goto P_0c05b7de;
P_0c05b7de: /* original e4bf, guest PC 0x0c05b7de */
if(!s->budget--) { s->failed_pc=0x0c05b7deu; return 0; }
r[4]=0xffffffbfu;
goto P_0c05b7e0;
P_0c05b7e0: /* original 6212, guest PC 0x0c05b7e0 */
if(!s->budget--) { s->failed_pc=0x0c05b7e0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05b7e2;
P_0c05b7e2: /* original 2469, guest PC 0x0c05b7e2 */
if(!s->budget--) { s->failed_pc=0x0c05b7e2u; return 0; }
r[4]&=r[6];
goto P_0c05b7e4;
P_0c05b7e4: /* original 4208, guest PC 0x0c05b7e4 */
if(!s->budget--) { s->failed_pc=0x0c05b7e4u; return 0; }
r[2]<<=2;
goto P_0c05b7e6;
P_0c05b7e6: /* original 4208, guest PC 0x0c05b7e6 */
if(!s->budget--) { s->failed_pc=0x0c05b7e6u; return 0; }
r[2]<<=2;
goto P_0c05b7e8;
P_0c05b7e8: /* original 4208, guest PC 0x0c05b7e8 */
if(!s->budget--) { s->failed_pc=0x0c05b7e8u; return 0; }
r[2]<<=2;
goto P_0c05b7ea;
P_0c05b7ea: /* original 242b, guest PC 0x0c05b7ea */
if(!s->budget--) { s->failed_pc=0x0c05b7eau; return 0; }
r[4]|=r[2];
goto P_0c05b7ec;
P_0c05b7ec: /* original d325, guest PC 0x0c05b7ec */
if(!s->budget--) { s->failed_pc=0x0c05b7ecu; return 0; }
r[3]=read(ram,0x0c05b884u,4);
goto P_0c05b7ee;
P_0c05b7ee: /* original 2c38, guest PC 0x0c05b7ee */
if(!s->budget--) { s->failed_pc=0x0c05b7eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c05b7f0;
P_0c05b7f0: /* original 8906, guest PC 0x0c05b7f0 */
if(!s->budget--) { s->failed_pc=0x0c05b7f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b800; }
goto P_0c05b7f2;
P_0c05b7f2: /* original e1cf, guest PC 0x0c05b7f2 */
if(!s->budget--) { s->failed_pc=0x0c05b7f2u; return 0; }
r[1]=0xffffffcfu;
goto P_0c05b7f4;
P_0c05b7f4: /* original 52d3, guest PC 0x0c05b7f4 */
if(!s->budget--) { s->failed_pc=0x0c05b7f4u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c05b7f6;
P_0c05b7f6: /* original 2149, guest PC 0x0c05b7f6 */
if(!s->budget--) { s->failed_pc=0x0c05b7f6u; return 0; }
r[1]&=r[4];
goto P_0c05b7f8;
P_0c05b7f8: /* original 4208, guest PC 0x0c05b7f8 */
if(!s->budget--) { s->failed_pc=0x0c05b7f8u; return 0; }
r[2]<<=2;
goto P_0c05b7fa;
P_0c05b7fa: /* original 4208, guest PC 0x0c05b7fa */
if(!s->budget--) { s->failed_pc=0x0c05b7fau; return 0; }
r[2]<<=2;
goto P_0c05b7fc;
P_0c05b7fc: /* original 6413, guest PC 0x0c05b7fc */
if(!s->budget--) { s->failed_pc=0x0c05b7fcu; return 0; }
r[4]=r[1];
goto P_0c05b7fe;
P_0c05b7fe: /* original 242b, guest PC 0x0c05b7fe */
if(!s->budget--) { s->failed_pc=0x0c05b7feu; return 0; }
r[4]|=r[2];
goto P_0c05b800;
P_0c05b800: /* original 2888, guest PC 0x0c05b800 */
if(!s->budget--) { s->failed_pc=0x0c05b800u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c05b802;
P_0c05b802: /* original 8910, guest PC 0x0c05b802 */
if(!s->budget--) { s->failed_pc=0x0c05b802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b826; }
goto P_0c05b804;
P_0c05b804: /* original 53d8, guest PC 0x0c05b804 */
if(!s->budget--) { s->failed_pc=0x0c05b804u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c05b806;
P_0c05b806: /* original e2f7, guest PC 0x0c05b806 */
if(!s->budget--) { s->failed_pc=0x0c05b806u; return 0; }
r[2]=0xfffffff7u;
goto P_0c05b808;
P_0c05b808: /* original 2249, guest PC 0x0c05b808 */
if(!s->budget--) { s->failed_pc=0x0c05b808u; return 0; }
r[2]&=r[4];
goto P_0c05b80a;
P_0c05b80a: /* original 4301, guest PC 0x0c05b80a */
if(!s->budget--) { s->failed_pc=0x0c05b80au; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c05b80c;
P_0c05b80c: /* original 4308, guest PC 0x0c05b80c */
if(!s->budget--) { s->failed_pc=0x0c05b80cu; return 0; }
r[3]<<=2;
goto P_0c05b80e;
P_0c05b80e: /* original 4300, guest PC 0x0c05b80e */
if(!s->budget--) { s->failed_pc=0x0c05b80eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05b810;
P_0c05b810: /* original 6423, guest PC 0x0c05b810 */
if(!s->budget--) { s->failed_pc=0x0c05b810u; return 0; }
r[4]=r[2];
goto P_0c05b812;
P_0c05b812: /* original 243b, guest PC 0x0c05b812 */
if(!s->budget--) { s->failed_pc=0x0c05b812u; return 0; }
r[4]|=r[3];
goto P_0c05b814;
P_0c05b814: /* original 2888, guest PC 0x0c05b814 */
if(!s->budget--) { s->failed_pc=0x0c05b814u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c05b816;
P_0c05b816: /* original 8906, guest PC 0x0c05b816 */
if(!s->budget--) { s->failed_pc=0x0c05b816u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b826; }
goto P_0c05b818;
P_0c05b818: /* original 50d8, guest PC 0x0c05b818 */
if(!s->budget--) { s->failed_pc=0x0c05b818u; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c05b81a;
P_0c05b81a: /* original e3fd, guest PC 0x0c05b81a */
if(!s->budget--) { s->failed_pc=0x0c05b81au; return 0; }
r[3]=0xfffffffdu;
goto P_0c05b81c;
P_0c05b81c: /* original 2349, guest PC 0x0c05b81c */
if(!s->budget--) { s->failed_pc=0x0c05b81cu; return 0; }
r[3]&=r[4];
goto P_0c05b81e;
P_0c05b81e: /* original c901, guest PC 0x0c05b81e */
if(!s->budget--) { s->failed_pc=0x0c05b81eu; return 0; }
r[0]&=1u;
goto P_0c05b820;
P_0c05b820: /* original 4000, guest PC 0x0c05b820 */
if(!s->budget--) { s->failed_pc=0x0c05b820u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05b822;
P_0c05b822: /* original 6433, guest PC 0x0c05b822 */
if(!s->budget--) { s->failed_pc=0x0c05b822u; return 0; }
r[4]=r[3];
goto P_0c05b824;
P_0c05b824: /* original 240b, guest PC 0x0c05b824 */
if(!s->budget--) { s->failed_pc=0x0c05b824u; return 0; }
r[4]|=r[0];
goto P_0c05b826;
P_0c05b826: /* original 52f3, guest PC 0x0c05b826 */
if(!s->budget--) { s->failed_pc=0x0c05b826u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c05b828;
P_0c05b828: /* original 2228, guest PC 0x0c05b828 */
if(!s->budget--) { s->failed_pc=0x0c05b828u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05b82a;
P_0c05b82a: /* original 8907, guest PC 0x0c05b82a */
if(!s->budget--) { s->failed_pc=0x0c05b82au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b83c; }
goto P_0c05b82c;
P_0c05b82c: /* original e040, guest PC 0x0c05b82c */
if(!s->budget--) { s->failed_pc=0x0c05b82cu; return 0; }
r[0]=0x00000040u;
goto P_0c05b82e;
P_0c05b82e: /* original 03de, guest PC 0x0c05b82e */
if(!s->budget--) { s->failed_pc=0x0c05b82eu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c05b830;
P_0c05b830: /* original 2338, guest PC 0x0c05b830 */
if(!s->budget--) { s->failed_pc=0x0c05b830u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05b832;
P_0c05b832: /* original 8901, guest PC 0x0c05b832 */
if(!s->budget--) { s->failed_pc=0x0c05b832u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b838; }
goto P_0c05b834;
P_0c05b834: /* original a002, guest PC 0x0c05b834 */
if(!s->budget--) { s->failed_pc=0x0c05b834u; return 0; }
r[4]|=r[5];
goto P_0c05b83c;
P_0c05b836: /* original 245b, guest PC 0x0c05b836 */
if(!s->budget--) { s->failed_pc=0x0c05b836u; return 0; }
r[4]|=r[5];
goto P_0c05b838;
P_0c05b838: /* original e2fb, guest PC 0x0c05b838 */
if(!s->budget--) { s->failed_pc=0x0c05b838u; return 0; }
r[2]=0xfffffffbu;
goto P_0c05b83a;
P_0c05b83a: /* original 2429, guest PC 0x0c05b83a */
if(!s->budget--) { s->failed_pc=0x0c05b83au; return 0; }
r[4]&=r[2];
goto P_0c05b83c;
P_0c05b83c: /* original 53f2, guest PC 0x0c05b83c */
if(!s->budget--) { s->failed_pc=0x0c05b83cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05b83e;
P_0c05b83e: /* original 2338, guest PC 0x0c05b83e */
if(!s->budget--) { s->failed_pc=0x0c05b83eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05b840;
P_0c05b840: /* original 8903, guest PC 0x0c05b840 */
if(!s->budget--) { s->failed_pc=0x0c05b840u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b84a; }
goto P_0c05b842;
P_0c05b842: /* original e3fe, guest PC 0x0c05b842 */
if(!s->budget--) { s->failed_pc=0x0c05b842u; return 0; }
r[3]=0xfffffffeu;
goto P_0c05b844;
P_0c05b844: /* original 2349, guest PC 0x0c05b844 */
if(!s->budget--) { s->failed_pc=0x0c05b844u; return 0; }
r[3]&=r[4];
goto P_0c05b846;
P_0c05b846: /* original 54d4, guest PC 0x0c05b846 */
if(!s->budget--) { s->failed_pc=0x0c05b846u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c05b848;
P_0c05b848: /* original 243b, guest PC 0x0c05b848 */
if(!s->budget--) { s->failed_pc=0x0c05b848u; return 0; }
r[4]|=r[3];
goto P_0c05b84a;
P_0c05b84a: /* original d20f, guest PC 0x0c05b84a */
if(!s->budget--) { s->failed_pc=0x0c05b84au; return 0; }
r[2]=read(ram,0x0c05b888u,4);
goto P_0c05b84c;
P_0c05b84c: /* original d30f, guest PC 0x0c05b84c */
if(!s->budget--) { s->failed_pc=0x0c05b84cu; return 0; }
r[3]=read(ram,0x0c05b88cu,4);
goto P_0c05b84e;
P_0c05b84e: /* original 2429, guest PC 0x0c05b84e */
if(!s->budget--) { s->failed_pc=0x0c05b84eu; return 0; }
r[4]&=r[2];
goto P_0c05b850;
P_0c05b850: /* original 9014, guest PC 0x0c05b850 */
if(!s->budget--) { s->failed_pc=0x0c05b850u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b87cu,2);
goto P_0c05b852;
P_0c05b852: /* original 2b39, guest PC 0x0c05b852 */
if(!s->budget--) { s->failed_pc=0x0c05b852u; return 0; }
r[11]&=r[3];
goto P_0c05b854;
P_0c05b854: /* original 0db6, guest PC 0x0c05b854 */
if(!s->budget--) { s->failed_pc=0x0c05b854u; return 0; }
write(ram,r[13]+r[0],r[11],4);
goto P_0c05b856;
P_0c05b856: /* original 7004, guest PC 0x0c05b856 */
if(!s->budget--) { s->failed_pc=0x0c05b856u; return 0; }
r[0]+=0x00000004u;
goto P_0c05b858;
P_0c05b858: /* original 0de6, guest PC 0x0c05b858 */
if(!s->budget--) { s->failed_pc=0x0c05b858u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c05b85a;
P_0c05b85a: /* original 62f2, guest PC 0x0c05b85a */
if(!s->budget--) { s->failed_pc=0x0c05b85au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05b85c;
P_0c05b85c: /* original 900f, guest PC 0x0c05b85c */
if(!s->budget--) { s->failed_pc=0x0c05b85cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b87eu,2);
goto P_0c05b85e;
P_0c05b85e: /* original 0d26, guest PC 0x0c05b85e */
if(!s->budget--) { s->failed_pc=0x0c05b85eu; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c05b860;
P_0c05b860: /* original 70f4, guest PC 0x0c05b860 */
if(!s->budget--) { s->failed_pc=0x0c05b860u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c05b862;
P_0c05b862: /* original 0d46, guest PC 0x0c05b862 */
if(!s->budget--) { s->failed_pc=0x0c05b862u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c05b864;
P_0c05b864: /* original e000, guest PC 0x0c05b864 */
if(!s->budget--) { s->failed_pc=0x0c05b864u; return 0; }
r[0]=0x00000000u;
goto P_0c05b866;
P_0c05b866: /* original 7f20, guest PC 0x0c05b866 */
if(!s->budget--) { s->failed_pc=0x0c05b866u; return 0; }
r[15]+=0x00000020u;
goto P_0c05b868;
P_0c05b868: /* original 4f26, guest PC 0x0c05b868 */
if(!s->budget--) { s->failed_pc=0x0c05b868u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05b86a;
P_0c05b86a: /* original 68f6, guest PC 0x0c05b86a */
if(!s->budget--) { s->failed_pc=0x0c05b86au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05b86c;
P_0c05b86c: /* original 69f6, guest PC 0x0c05b86c */
if(!s->budget--) { s->failed_pc=0x0c05b86cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05b86e;
P_0c05b86e: /* original 6af6, guest PC 0x0c05b86e */
if(!s->budget--) { s->failed_pc=0x0c05b86eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05b870;
P_0c05b870: /* original 6bf6, guest PC 0x0c05b870 */
if(!s->budget--) { s->failed_pc=0x0c05b870u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05b872;
P_0c05b872: /* original 6cf6, guest PC 0x0c05b872 */
if(!s->budget--) { s->failed_pc=0x0c05b872u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05b874;
P_0c05b874: /* original 6df6, guest PC 0x0c05b874 */
if(!s->budget--) { s->failed_pc=0x0c05b874u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05b876;
P_0c05b876: /* original 000b, guest PC 0x0c05b876 */
if(!s->budget--) { s->failed_pc=0x0c05b876u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05b878: /* original 6ef6, guest PC 0x0c05b878 */
if(!s->budget--) { s->failed_pc=0x0c05b878u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05b87au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c05b20eu,0x0c05b210u,0x0c05b212u,0x0c05b214u,0x0c05b216u,0x0c05b218u,0x0c05b21au,0x0c05b21cu,0x0c05b21eu,0x0c05b220u,0x0c05b222u,0x0c05b224u,0x0c05b226u,0x0c05b228u,0x0c05b22au,0x0c05b22cu,
0x0c05b22eu,0x0c05b230u,0x0c05b232u,0x0c05b234u,0x0c05b236u,0x0c05b238u,0x0c05b23au,0x0c05b23cu,0x0c05b23eu,0x0c05b240u,0x0c05b242u,0x0c05b244u,0x0c05b246u,0x0c05b248u,0x0c05b24au,0x0c05b24cu,
0x0c05b24eu,0x0c05b250u,0x0c05b252u,0x0c05b254u,0x0c05b256u,0x0c05b258u,0x0c05b25au,0x0c05b25cu,0x0c05b25eu,0x0c05b260u,0x0c05b262u,0x0c05b264u,0x0c05b266u,0x0c05b268u,0x0c05b26au,0x0c05b26cu,
0x0c05b26eu,0x0c05b270u,0x0c05b272u,0x0c05b274u,0x0c05b276u,0x0c05b278u,0x0c05b27au,0x0c05b27cu,0x0c05b27eu,0x0c05b280u,0x0c05b282u,0x0c05b284u,0x0c05b286u,0x0c05b288u,0x0c05b28au,0x0c05b28cu,
0x0c05b28eu,0x0c05b290u,0x0c05b292u,0x0c05b294u,0x0c05b296u,0x0c05b298u,0x0c05b29au,0x0c05b29cu,0x0c05b29eu,0x0c05b2a0u,0x0c05b2a2u,0x0c05b2a4u,0x0c05b2a6u,0x0c05b2a8u,0x0c05b2aau,0x0c05b2acu,
0x0c05b2aeu,0x0c05b2b0u,0x0c05b2b2u,0x0c05b2b4u,0x0c05b2b6u,0x0c05b2b8u,0x0c05b2bau,0x0c05b2bcu,0x0c05b2beu,0x0c05b2c0u,0x0c05b2c2u,0x0c05b2c4u,0x0c05b2c6u,0x0c05b2c8u,0x0c05b2cau,0x0c05b2ccu,
0x0c05b2ceu,0x0c05b2d0u,0x0c05b2d2u,0x0c05b2d4u,0x0c05b2d6u,0x0c05b2d8u,0x0c05b2dau,0x0c05b2dcu,0x0c05b2deu,0x0c05b2e0u,0x0c05b2e2u,0x0c05b2e4u,0x0c05b2e6u,0x0c05b320u,0x0c05b322u,0x0c05b324u,
0x0c05b326u,0x0c05b328u,0x0c05b32au,0x0c05b32cu,0x0c05b32eu,0x0c05b330u,0x0c05b332u,0x0c05b334u,0x0c05b336u,0x0c05b338u,0x0c05b33au,0x0c05b33cu,0x0c05b33eu,0x0c05b340u,0x0c05b342u,0x0c05b344u,
0x0c05b346u,0x0c05b348u,0x0c05b34au,0x0c05b34cu,0x0c05b34eu,0x0c05b350u,0x0c05b352u,0x0c05b354u,0x0c05b356u,0x0c05b358u,0x0c05b35au,0x0c05b35cu,0x0c05b35eu,0x0c05b360u,0x0c05b362u,0x0c05b364u,
0x0c05b366u,0x0c05b368u,0x0c05b36au,0x0c05b36cu,0x0c05b36eu,0x0c05b370u,0x0c05b372u,0x0c05b374u,0x0c05b376u,0x0c05b378u,0x0c05b37au,0x0c05b37cu,0x0c05b37eu,0x0c05b380u,0x0c05b382u,0x0c05b384u,
0x0c05b386u,0x0c05b388u,0x0c05b38au,0x0c05b38cu,0x0c05b38eu,0x0c05b390u,0x0c05b392u,0x0c05b394u,0x0c05b396u,0x0c05b398u,0x0c05b39au,0x0c05b39cu,0x0c05b39eu,0x0c05b3a0u,0x0c05b3d0u,0x0c05b3d2u,
0x0c05b3d4u,0x0c05b3d6u,0x0c05b3d8u,0x0c05b3dau,0x0c05b3dcu,0x0c05b3deu,0x0c05b3e0u,0x0c05b3e2u,0x0c05b3e4u,0x0c05b3e6u,0x0c05b3e8u,0x0c05b3eau,0x0c05b3ecu,0x0c05b3eeu,0x0c05b3f0u,0x0c05b3f2u,
0x0c05b3f4u,0x0c05b3f6u,0x0c05b3f8u,0x0c05b3fau,0x0c05b3fcu,0x0c05b3feu,0x0c05b400u,0x0c05b402u,0x0c05b404u,0x0c05b406u,0x0c05b408u,0x0c05b40au,0x0c05b40cu,0x0c05b40eu,0x0c05b410u,0x0c05b412u,
0x0c05b414u,0x0c05b416u,0x0c05b418u,0x0c05b41au,0x0c05b41cu,0x0c05b41eu,0x0c05b420u,0x0c05b422u,0x0c05b424u,0x0c05b426u,0x0c05b428u,0x0c05b42au,0x0c05b42cu,0x0c05b42eu,0x0c05b430u,0x0c05b432u,
0x0c05b434u,0x0c05b436u,0x0c05b438u,0x0c05b43au,0x0c05b43cu,0x0c05b43eu,0x0c05b440u,0x0c05b442u,0x0c05b444u,0x0c05b446u,0x0c05b448u,0x0c05b44au,0x0c05b44cu,0x0c05b44eu,0x0c05b450u,0x0c05b452u,
0x0c05b454u,0x0c05b456u,0x0c05b458u,0x0c05b45au,0x0c05b45cu,0x0c05b45eu,0x0c05b460u,0x0c05b462u,0x0c05b464u,0x0c05b466u,0x0c05b468u,0x0c05b46au,0x0c05b46cu,0x0c05b46eu,0x0c05b49cu,0x0c05b49eu,
0x0c05b4a0u,0x0c05b4a2u,0x0c05b4a4u,0x0c05b4a6u,0x0c05b4a8u,0x0c05b4aau,0x0c05b4acu,0x0c05b4aeu,0x0c05b4b0u,0x0c05b4b2u,0x0c05b4b4u,0x0c05b4b6u,0x0c05b4b8u,0x0c05b4bau,0x0c05b4bcu,0x0c05b4beu,
0x0c05b4c0u,0x0c05b4c2u,0x0c05b4c4u,0x0c05b4c6u,0x0c05b4c8u,0x0c05b4cau,0x0c05b4ccu,0x0c05b4ceu,0x0c05b4d0u,0x0c05b4d2u,0x0c05b4d4u,0x0c05b4d6u,0x0c05b4d8u,0x0c05b4dau,0x0c05b4dcu,0x0c05b4deu,
0x0c05b4e0u,0x0c05b4e2u,0x0c05b4e4u,0x0c05b4e6u,0x0c05b4e8u,0x0c05b4eau,0x0c05b4ecu,0x0c05b4eeu,0x0c05b4f0u,0x0c05b4f2u,0x0c05b4f4u,0x0c05b4f6u,0x0c05b4f8u,0x0c05b4fau,0x0c05b4fcu,0x0c05b4feu,
0x0c05b500u,0x0c05b502u,0x0c05b504u,0x0c05b506u,0x0c05b508u,0x0c05b50au,0x0c05b50cu,0x0c05b50eu,0x0c05b510u,0x0c05b512u,0x0c05b514u,0x0c05b516u,0x0c05b518u,0x0c05b51au,0x0c05b51cu,0x0c05b51eu,
0x0c05b520u,0x0c05b522u,0x0c05b524u,0x0c05b526u,0x0c05b528u,0x0c05b52au,0x0c05b52cu,0x0c05b52eu,0x0c05b530u,0x0c05b532u,0x0c05b534u,0x0c05b536u,0x0c05b538u,0x0c05b53au,0x0c05b53cu,0x0c05b53eu,
0x0c05b540u,0x0c05b542u,0x0c05b544u,0x0c05b546u,0x0c05b548u,0x0c05b54au,0x0c05b54cu,0x0c05b54eu,0x0c05b550u,0x0c05b552u,0x0c05b554u,0x0c05b556u,0x0c05b558u,0x0c05b55au,0x0c05b55cu,0x0c05b55eu,
0x0c05b560u,0x0c05b562u,0x0c05b564u,0x0c05b566u,0x0c05b568u,0x0c05b56au,0x0c05b56cu,0x0c05b56eu,0x0c05b5b0u,0x0c05b5b2u,0x0c05b5b4u,0x0c05b5b6u,0x0c05b5b8u,0x0c05b5bau,0x0c05b5bcu,0x0c05b5beu,
0x0c05b5c0u,0x0c05b5c2u,0x0c05b5c4u,0x0c05b5c6u,0x0c05b5c8u,0x0c05b5cau,0x0c05b5ccu,0x0c05b5ceu,0x0c05b5d0u,0x0c05b5d2u,0x0c05b5d4u,0x0c05b5d6u,0x0c05b5d8u,0x0c05b5dau,0x0c05b5dcu,0x0c05b5deu,
0x0c05b5e0u,0x0c05b5e2u,0x0c05b5e4u,0x0c05b5e6u,0x0c05b5e8u,0x0c05b5eau,0x0c05b5ecu,0x0c05b5eeu,0x0c05b5f0u,0x0c05b5f2u,0x0c05b5f4u,0x0c05b5f6u,0x0c05b5f8u,0x0c05b5fau,0x0c05b5fcu,0x0c05b5feu,
0x0c05b600u,0x0c05b602u,0x0c05b604u,0x0c05b606u,0x0c05b608u,0x0c05b60au,0x0c05b60cu,0x0c05b60eu,0x0c05b610u,0x0c05b612u,0x0c05b614u,0x0c05b616u,0x0c05b618u,0x0c05b61au,0x0c05b61cu,0x0c05b61eu,
0x0c05b620u,0x0c05b622u,0x0c05b624u,0x0c05b626u,0x0c05b628u,0x0c05b62au,0x0c05b62cu,0x0c05b62eu,0x0c05b630u,0x0c05b632u,0x0c05b634u,0x0c05b636u,0x0c05b638u,0x0c05b63au,0x0c05b63cu,0x0c05b63eu,
0x0c05b640u,0x0c05b642u,0x0c05b644u,0x0c05b646u,0x0c05b648u,0x0c05b64au,0x0c05b64cu,0x0c05b64eu,0x0c05b650u,0x0c05b652u,0x0c05b654u,0x0c05b656u,0x0c05b658u,0x0c05b65au,0x0c05b65cu,0x0c05b65eu,
0x0c05b660u,0x0c05b662u,0x0c05b664u,0x0c05b666u,0x0c05b668u,0x0c05b66au,0x0c05b66cu,0x0c05b66eu,0x0c05b670u,0x0c05b672u,0x0c05b674u,0x0c05b676u,0x0c05b678u,0x0c05b67au,0x0c05b67cu,0x0c05b67eu,
0x0c05b680u,0x0c05b682u,0x0c05b684u,0x0c05b686u,0x0c05b688u,0x0c05b68au,0x0c05b68cu,0x0c05b6b8u,0x0c05b6bau,0x0c05b6bcu,0x0c05b6beu,0x0c05b6c0u,0x0c05b6c2u,0x0c05b6c4u,0x0c05b6c6u,0x0c05b6c8u,
0x0c05b6cau,0x0c05b6ccu,0x0c05b6ceu,0x0c05b6d0u,0x0c05b6d2u,0x0c05b6d4u,0x0c05b6d6u,0x0c05b6d8u,0x0c05b6dau,0x0c05b6dcu,0x0c05b6deu,0x0c05b6e0u,0x0c05b6e2u,0x0c05b6e4u,0x0c05b6e6u,0x0c05b6e8u,
0x0c05b6eau,0x0c05b6ecu,0x0c05b6eeu,0x0c05b6f0u,0x0c05b6f2u,0x0c05b6f4u,0x0c05b6f6u,0x0c05b6f8u,0x0c05b6fau,0x0c05b6fcu,0x0c05b6feu,0x0c05b700u,0x0c05b702u,0x0c05b704u,0x0c05b706u,0x0c05b708u,
0x0c05b70au,0x0c05b70cu,0x0c05b70eu,0x0c05b710u,0x0c05b712u,0x0c05b714u,0x0c05b716u,0x0c05b718u,0x0c05b71au,0x0c05b71cu,0x0c05b71eu,0x0c05b720u,0x0c05b722u,0x0c05b724u,0x0c05b726u,0x0c05b728u,
0x0c05b72au,0x0c05b72cu,0x0c05b72eu,0x0c05b730u,0x0c05b732u,0x0c05b734u,0x0c05b736u,0x0c05b738u,0x0c05b73au,0x0c05b73cu,0x0c05b73eu,0x0c05b740u,0x0c05b742u,0x0c05b744u,0x0c05b746u,0x0c05b748u,
0x0c05b74au,0x0c05b74cu,0x0c05b74eu,0x0c05b750u,0x0c05b752u,0x0c05b754u,0x0c05b756u,0x0c05b758u,0x0c05b75au,0x0c05b75cu,0x0c05b75eu,0x0c05b760u,0x0c05b762u,0x0c05b764u,0x0c05b766u,0x0c05b768u,
0x0c05b76au,0x0c05b76cu,0x0c05b76eu,0x0c05b770u,0x0c05b772u,0x0c05b774u,0x0c05b776u,0x0c05b778u,0x0c05b77au,0x0c05b77cu,0x0c05b7c4u,0x0c05b7c6u,0x0c05b7c8u,0x0c05b7cau,0x0c05b7ccu,0x0c05b7ceu,
0x0c05b7d0u,0x0c05b7d2u,0x0c05b7d4u,0x0c05b7d6u,0x0c05b7d8u,0x0c05b7dau,0x0c05b7dcu,0x0c05b7deu,0x0c05b7e0u,0x0c05b7e2u,0x0c05b7e4u,0x0c05b7e6u,0x0c05b7e8u,0x0c05b7eau,0x0c05b7ecu,0x0c05b7eeu,
0x0c05b7f0u,0x0c05b7f2u,0x0c05b7f4u,0x0c05b7f6u,0x0c05b7f8u,0x0c05b7fau,0x0c05b7fcu,0x0c05b7feu,0x0c05b800u,0x0c05b802u,0x0c05b804u,0x0c05b806u,0x0c05b808u,0x0c05b80au,0x0c05b80cu,0x0c05b80eu,
0x0c05b810u,0x0c05b812u,0x0c05b814u,0x0c05b816u,0x0c05b818u,0x0c05b81au,0x0c05b81cu,0x0c05b81eu,0x0c05b820u,0x0c05b822u,0x0c05b824u,0x0c05b826u,0x0c05b828u,0x0c05b82au,0x0c05b82cu,0x0c05b82eu,
0x0c05b830u,0x0c05b832u,0x0c05b834u,0x0c05b836u,0x0c05b838u,0x0c05b83au,0x0c05b83cu,0x0c05b83eu,0x0c05b840u,0x0c05b842u,0x0c05b844u,0x0c05b846u,0x0c05b848u,0x0c05b84au,0x0c05b84cu,0x0c05b84eu,
0x0c05b850u,0x0c05b852u,0x0c05b854u,0x0c05b856u,0x0c05b858u,0x0c05b85au,0x0c05b85cu,0x0c05b85eu,0x0c05b860u,0x0c05b862u,0x0c05b864u,0x0c05b866u,0x0c05b868u,0x0c05b86au,0x0c05b86cu,0x0c05b86eu,
0x0c05b870u,0x0c05b872u,0x0c05b874u,0x0c05b876u,0x0c05b878u,
};
int vf3_advance_05b20e_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
