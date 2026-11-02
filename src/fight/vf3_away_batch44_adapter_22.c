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
int vf3_away_batch44_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07e0f0u: goto P_0c07e0f0;
case 0x0c07e0f2u: goto P_0c07e0f2;
case 0x0c07e0f4u: goto P_0c07e0f4;
case 0x0c07e0f6u: goto P_0c07e0f6;
case 0x0c07e0f8u: goto P_0c07e0f8;
case 0x0c07e0fau: goto P_0c07e0fa;
case 0x0c07e0fcu: goto P_0c07e0fc;
case 0x0c07e0feu: goto P_0c07e0fe;
case 0x0c07e100u: goto P_0c07e100;
case 0x0c07e102u: goto P_0c07e102;
case 0x0c07e104u: goto P_0c07e104;
case 0x0c07e106u: goto P_0c07e106;
case 0x0c07e108u: goto P_0c07e108;
case 0x0c07e10au: goto P_0c07e10a;
case 0x0c07e10cu: goto P_0c07e10c;
case 0x0c07e10eu: goto P_0c07e10e;
case 0x0c07e110u: goto P_0c07e110;
case 0x0c07e112u: goto P_0c07e112;
case 0x0c07e114u: goto P_0c07e114;
case 0x0c07e116u: goto P_0c07e116;
case 0x0c07e118u: goto P_0c07e118;
case 0x0c07e11au: goto P_0c07e11a;
case 0x0c07e11cu: goto P_0c07e11c;
case 0x0c07e11eu: goto P_0c07e11e;
case 0x0c07e120u: goto P_0c07e120;
case 0x0c07e122u: goto P_0c07e122;
case 0x0c07e124u: goto P_0c07e124;
case 0x0c07e126u: goto P_0c07e126;
case 0x0c07e128u: goto P_0c07e128;
case 0x0c07e12au: goto P_0c07e12a;
case 0x0c07e12cu: goto P_0c07e12c;
case 0x0c07e12eu: goto P_0c07e12e;
case 0x0c07e130u: goto P_0c07e130;
case 0x0c07e132u: goto P_0c07e132;
case 0x0c07e134u: goto P_0c07e134;
case 0x0c07e136u: goto P_0c07e136;
case 0x0c07e138u: goto P_0c07e138;
case 0x0c07e13au: goto P_0c07e13a;
case 0x0c07e13cu: goto P_0c07e13c;
case 0x0c07e13eu: goto P_0c07e13e;
case 0x0c07e140u: goto P_0c07e140;
case 0x0c07e142u: goto P_0c07e142;
case 0x0c07e144u: goto P_0c07e144;
case 0x0c07e146u: goto P_0c07e146;
case 0x0c07e148u: goto P_0c07e148;
case 0x0c07e14au: goto P_0c07e14a;
case 0x0c07e14cu: goto P_0c07e14c;
case 0x0c07e14eu: goto P_0c07e14e;
case 0x0c07e150u: goto P_0c07e150;
case 0x0c07e152u: goto P_0c07e152;
case 0x0c07e154u: goto P_0c07e154;
case 0x0c07e156u: goto P_0c07e156;
case 0x0c07e158u: goto P_0c07e158;
case 0x0c07e15au: goto P_0c07e15a;
case 0x0c07e15cu: goto P_0c07e15c;
case 0x0c07e15eu: goto P_0c07e15e;
case 0x0c07e160u: goto P_0c07e160;
case 0x0c07e162u: goto P_0c07e162;
case 0x0c07e164u: goto P_0c07e164;
case 0x0c07e166u: goto P_0c07e166;
case 0x0c07e168u: goto P_0c07e168;
case 0x0c07e16au: goto P_0c07e16a;
case 0x0c07e16cu: goto P_0c07e16c;
case 0x0c07e16eu: goto P_0c07e16e;
case 0x0c07e170u: goto P_0c07e170;
case 0x0c07e172u: goto P_0c07e172;
case 0x0c07e174u: goto P_0c07e174;
case 0x0c07e176u: goto P_0c07e176;
case 0x0c07e178u: goto P_0c07e178;
case 0x0c07e17au: goto P_0c07e17a;
case 0x0c07e17cu: goto P_0c07e17c;
case 0x0c07e17eu: goto P_0c07e17e;
case 0x0c07e180u: goto P_0c07e180;
case 0x0c07e182u: goto P_0c07e182;
case 0x0c07e184u: goto P_0c07e184;
case 0x0c07e186u: goto P_0c07e186;
case 0x0c07e188u: goto P_0c07e188;
case 0x0c07e18au: goto P_0c07e18a;
case 0x0c07e18cu: goto P_0c07e18c;
case 0x0c07e18eu: goto P_0c07e18e;
case 0x0c07e190u: goto P_0c07e190;
case 0x0c07e192u: goto P_0c07e192;
case 0x0c07e194u: goto P_0c07e194;
case 0x0c07e284u: goto P_0c07e284;
case 0x0c07e286u: goto P_0c07e286;
case 0x0c07e288u: goto P_0c07e288;
case 0x0c07e28au: goto P_0c07e28a;
case 0x0c07e28cu: goto P_0c07e28c;
case 0x0c07e28eu: goto P_0c07e28e;
case 0x0c07e290u: goto P_0c07e290;
case 0x0c07e292u: goto P_0c07e292;
case 0x0c07e294u: goto P_0c07e294;
case 0x0c07e296u: goto P_0c07e296;
case 0x0c07e298u: goto P_0c07e298;
case 0x0c07e29au: goto P_0c07e29a;
case 0x0c07e29cu: goto P_0c07e29c;
case 0x0c07e29eu: goto P_0c07e29e;
case 0x0c07e2a0u: goto P_0c07e2a0;
case 0x0c07e2a2u: goto P_0c07e2a2;
case 0x0c07e2a4u: goto P_0c07e2a4;
case 0x0c07e2a6u: goto P_0c07e2a6;
case 0x0c07e2a8u: goto P_0c07e2a8;
case 0x0c07e2aau: goto P_0c07e2aa;
case 0x0c07e2acu: goto P_0c07e2ac;
case 0x0c07e2aeu: goto P_0c07e2ae;
case 0x0c07e2b0u: goto P_0c07e2b0;
case 0x0c07e2b2u: goto P_0c07e2b2;
case 0x0c07e2b4u: goto P_0c07e2b4;
case 0x0c07e2b6u: goto P_0c07e2b6;
case 0x0c07e2b8u: goto P_0c07e2b8;
case 0x0c07e2bau: goto P_0c07e2ba;
case 0x0c07e2bcu: goto P_0c07e2bc;
case 0x0c07e2beu: goto P_0c07e2be;
case 0x0c07e2c0u: goto P_0c07e2c0;
case 0x0c07e2c2u: goto P_0c07e2c2;
case 0x0c07e2c4u: goto P_0c07e2c4;
case 0x0c07e2c6u: goto P_0c07e2c6;
case 0x0c07e2c8u: goto P_0c07e2c8;
case 0x0c07e2cau: goto P_0c07e2ca;
case 0x0c07e2ccu: goto P_0c07e2cc;
case 0x0c07e2ceu: goto P_0c07e2ce;
case 0x0c07e2d0u: goto P_0c07e2d0;
case 0x0c07e2d2u: goto P_0c07e2d2;
case 0x0c07e2d4u: goto P_0c07e2d4;
case 0x0c07e2d6u: goto P_0c07e2d6;
case 0x0c07e2d8u: goto P_0c07e2d8;
case 0x0c07e2dau: goto P_0c07e2da;
case 0x0c07e2dcu: goto P_0c07e2dc;
case 0x0c07e2deu: goto P_0c07e2de;
case 0x0c07e2e0u: goto P_0c07e2e0;
case 0x0c07e2e2u: goto P_0c07e2e2;
case 0x0c07e2e4u: goto P_0c07e2e4;
case 0x0c07e2e6u: goto P_0c07e2e6;
case 0x0c07e2e8u: goto P_0c07e2e8;
case 0x0c07e2eau: goto P_0c07e2ea;
case 0x0c07e2ecu: goto P_0c07e2ec;
case 0x0c07e2eeu: goto P_0c07e2ee;
case 0x0c07e2f0u: goto P_0c07e2f0;
case 0x0c07e2f2u: goto P_0c07e2f2;
case 0x0c07e2f4u: goto P_0c07e2f4;
case 0x0c07e2f6u: goto P_0c07e2f6;
case 0x0c07e2f8u: goto P_0c07e2f8;
case 0x0c07e2fau: goto P_0c07e2fa;
case 0x0c07e2fcu: goto P_0c07e2fc;
case 0x0c07e2feu: goto P_0c07e2fe;
case 0x0c07e300u: goto P_0c07e300;
case 0x0c07e302u: goto P_0c07e302;
case 0x0c07e304u: goto P_0c07e304;
case 0x0c07e306u: goto P_0c07e306;
case 0x0c07e308u: goto P_0c07e308;
case 0x0c07e30au: goto P_0c07e30a;
case 0x0c07e30cu: goto P_0c07e30c;
case 0x0c07e30eu: goto P_0c07e30e;
case 0x0c07e310u: goto P_0c07e310;
case 0x0c07e312u: goto P_0c07e312;
case 0x0c07e314u: goto P_0c07e314;
case 0x0c07e316u: goto P_0c07e316;
case 0x0c07e318u: goto P_0c07e318;
case 0x0c07e31au: goto P_0c07e31a;
case 0x0c07e31cu: goto P_0c07e31c;
case 0x0c07e31eu: goto P_0c07e31e;
case 0x0c07e320u: goto P_0c07e320;
case 0x0c07e322u: goto P_0c07e322;
case 0x0c07e324u: goto P_0c07e324;
case 0x0c07e326u: goto P_0c07e326;
case 0x0c07e328u: goto P_0c07e328;
case 0x0c07e32au: goto P_0c07e32a;
case 0x0c07e32cu: goto P_0c07e32c;
case 0x0c07e32eu: goto P_0c07e32e;
case 0x0c07e330u: goto P_0c07e330;
case 0x0c07e332u: goto P_0c07e332;
case 0x0c07e334u: goto P_0c07e334;
case 0x0c07e336u: goto P_0c07e336;
case 0x0c07e338u: goto P_0c07e338;
case 0x0c07e33au: goto P_0c07e33a;
case 0x0c07e33cu: goto P_0c07e33c;
case 0x0c07e33eu: goto P_0c07e33e;
case 0x0c07e340u: goto P_0c07e340;
case 0x0c07e342u: goto P_0c07e342;
case 0x0c07e344u: goto P_0c07e344;
case 0x0c07e346u: goto P_0c07e346;
case 0x0c07e348u: goto P_0c07e348;
case 0x0c07e34au: goto P_0c07e34a;
case 0x0c07e34cu: goto P_0c07e34c;
case 0x0c07e34eu: goto P_0c07e34e;
case 0x0c07e350u: goto P_0c07e350;
case 0x0c07e352u: goto P_0c07e352;
case 0x0c07e354u: goto P_0c07e354;
case 0x0c07e356u: goto P_0c07e356;
case 0x0c07e358u: goto P_0c07e358;
case 0x0c07e35au: goto P_0c07e35a;
case 0x0c07e35cu: goto P_0c07e35c;
case 0x0c07e35eu: goto P_0c07e35e;
case 0x0c07e360u: goto P_0c07e360;
case 0x0c07e362u: goto P_0c07e362;
case 0x0c07e364u: goto P_0c07e364;
case 0x0c07e366u: goto P_0c07e366;
case 0x0c07e368u: goto P_0c07e368;
case 0x0c07e36au: goto P_0c07e36a;
case 0x0c07e36cu: goto P_0c07e36c;
case 0x0c07e36eu: goto P_0c07e36e;
case 0x0c07e370u: goto P_0c07e370;
case 0x0c07e372u: goto P_0c07e372;
case 0x0c07e374u: goto P_0c07e374;
case 0x0c07e376u: goto P_0c07e376;
case 0x0c07e378u: goto P_0c07e378;
case 0x0c07e37au: goto P_0c07e37a;
case 0x0c07e37cu: goto P_0c07e37c;
case 0x0c07e37eu: goto P_0c07e37e;
case 0x0c07e380u: goto P_0c07e380;
case 0x0c07e382u: goto P_0c07e382;
case 0x0c07e384u: goto P_0c07e384;
case 0x0c07e386u: goto P_0c07e386;
case 0x0c07e388u: goto P_0c07e388;
case 0x0c07e38au: goto P_0c07e38a;
case 0x0c07e38cu: goto P_0c07e38c;
case 0x0c07e38eu: goto P_0c07e38e;
case 0x0c07e390u: goto P_0c07e390;
case 0x0c07e392u: goto P_0c07e392;
case 0x0c07e394u: goto P_0c07e394;
case 0x0c07e396u: goto P_0c07e396;
case 0x0c07e398u: goto P_0c07e398;
case 0x0c07e39au: goto P_0c07e39a;
case 0x0c07e39cu: goto P_0c07e39c;
case 0x0c07e39eu: goto P_0c07e39e;
case 0x0c07e3a0u: goto P_0c07e3a0;
case 0x0c07e3a2u: goto P_0c07e3a2;
case 0x0c07e3a4u: goto P_0c07e3a4;
case 0x0c07e3a6u: goto P_0c07e3a6;
case 0x0c07e3a8u: goto P_0c07e3a8;
case 0x0c07e3aau: goto P_0c07e3aa;
case 0x0c07e3acu: goto P_0c07e3ac;
case 0x0c07e3aeu: goto P_0c07e3ae;
case 0x0c07e3b0u: goto P_0c07e3b0;
case 0x0c07e3b2u: goto P_0c07e3b2;
case 0x0c07e3b4u: goto P_0c07e3b4;
case 0x0c07e3b6u: goto P_0c07e3b6;
case 0x0c07e3b8u: goto P_0c07e3b8;
case 0x0c07e3bau: goto P_0c07e3ba;
case 0x0c07e3bcu: goto P_0c07e3bc;
case 0x0c07e3beu: goto P_0c07e3be;
case 0x0c07e3c0u: goto P_0c07e3c0;
case 0x0c07e3c2u: goto P_0c07e3c2;
case 0x0c07e3c4u: goto P_0c07e3c4;
case 0x0c07e3c6u: goto P_0c07e3c6;
case 0x0c07e3c8u: goto P_0c07e3c8;
case 0x0c07e3cau: goto P_0c07e3ca;
case 0x0c07e3ccu: goto P_0c07e3cc;
case 0x0c07e3ceu: goto P_0c07e3ce;
case 0x0c07e3d0u: goto P_0c07e3d0;
case 0x0c07e3d2u: goto P_0c07e3d2;
case 0x0c07e428u: goto P_0c07e428;
case 0x0c07e42au: goto P_0c07e42a;
case 0x0c07e42cu: goto P_0c07e42c;
case 0x0c07e42eu: goto P_0c07e42e;
case 0x0c07e430u: goto P_0c07e430;
case 0x0c07e432u: goto P_0c07e432;
case 0x0c07e434u: goto P_0c07e434;
case 0x0c07e436u: goto P_0c07e436;
case 0x0c07e438u: goto P_0c07e438;
case 0x0c07e43au: goto P_0c07e43a;
case 0x0c07e43cu: goto P_0c07e43c;
case 0x0c07e43eu: goto P_0c07e43e;
case 0x0c07e440u: goto P_0c07e440;
case 0x0c07e442u: goto P_0c07e442;
case 0x0c07e444u: goto P_0c07e444;
case 0x0c07e446u: goto P_0c07e446;
case 0x0c07e448u: goto P_0c07e448;
case 0x0c07e44au: goto P_0c07e44a;
case 0x0c07e44cu: goto P_0c07e44c;
case 0x0c07e44eu: goto P_0c07e44e;
case 0x0c07e450u: goto P_0c07e450;
case 0x0c07e452u: goto P_0c07e452;
case 0x0c07e454u: goto P_0c07e454;
case 0x0c07e456u: goto P_0c07e456;
case 0x0c07e458u: goto P_0c07e458;
case 0x0c07e45au: goto P_0c07e45a;
case 0x0c07e45cu: goto P_0c07e45c;
case 0x0c07e45eu: goto P_0c07e45e;
case 0x0c07e460u: goto P_0c07e460;
case 0x0c07e462u: goto P_0c07e462;
case 0x0c07e464u: goto P_0c07e464;
case 0x0c07e466u: goto P_0c07e466;
case 0x0c07e468u: goto P_0c07e468;
case 0x0c07e46au: goto P_0c07e46a;
case 0x0c07e46cu: goto P_0c07e46c;
case 0x0c07e46eu: goto P_0c07e46e;
case 0x0c07e470u: goto P_0c07e470;
case 0x0c07e472u: goto P_0c07e472;
case 0x0c07e474u: goto P_0c07e474;
case 0x0c07e476u: goto P_0c07e476;
case 0x0c07e478u: goto P_0c07e478;
case 0x0c07e47au: goto P_0c07e47a;
case 0x0c07e47cu: goto P_0c07e47c;
case 0x0c07e47eu: goto P_0c07e47e;
case 0x0c07e480u: goto P_0c07e480;
case 0x0c07e482u: goto P_0c07e482;
case 0x0c07e484u: goto P_0c07e484;
case 0x0c07e486u: goto P_0c07e486;
case 0x0c07e488u: goto P_0c07e488;
case 0x0c07e48au: goto P_0c07e48a;
case 0x0c07e48cu: goto P_0c07e48c;
case 0x0c07e48eu: goto P_0c07e48e;
case 0x0c07e490u: goto P_0c07e490;
case 0x0c07e492u: goto P_0c07e492;
case 0x0c07e494u: goto P_0c07e494;
case 0x0c07e496u: goto P_0c07e496;
case 0x0c07e498u: goto P_0c07e498;
case 0x0c07e49au: goto P_0c07e49a;
case 0x0c07e49cu: goto P_0c07e49c;
case 0x0c07e49eu: goto P_0c07e49e;
case 0x0c07e4a0u: goto P_0c07e4a0;
case 0x0c07e4a2u: goto P_0c07e4a2;
case 0x0c07e4a4u: goto P_0c07e4a4;
case 0x0c07e4a6u: goto P_0c07e4a6;
case 0x0c07e4a8u: goto P_0c07e4a8;
case 0x0c07e4aau: goto P_0c07e4aa;
case 0x0c07e4acu: goto P_0c07e4ac;
case 0x0c07e4aeu: goto P_0c07e4ae;
case 0x0c07e4b0u: goto P_0c07e4b0;
case 0x0c07e4b2u: goto P_0c07e4b2;
case 0x0c07e4b4u: goto P_0c07e4b4;
case 0x0c07e4b6u: goto P_0c07e4b6;
case 0x0c07e4b8u: goto P_0c07e4b8;
case 0x0c07e4bau: goto P_0c07e4ba;
case 0x0c07e4bcu: goto P_0c07e4bc;
case 0x0c07e4ceu: goto P_0c07e4ce;
case 0x0c07e4d0u: goto P_0c07e4d0;
case 0x0c07e4d2u: goto P_0c07e4d2;
case 0x0c07e4d4u: goto P_0c07e4d4;
case 0x0c07e4d6u: goto P_0c07e4d6;
case 0x0c07e4d8u: goto P_0c07e4d8;
case 0x0c07e4dau: goto P_0c07e4da;
case 0x0c07e4dcu: goto P_0c07e4dc;
case 0x0c07e4deu: goto P_0c07e4de;
case 0x0c07e4e0u: goto P_0c07e4e0;
case 0x0c07e4e2u: goto P_0c07e4e2;
case 0x0c07e4e4u: goto P_0c07e4e4;
case 0x0c07e4e6u: goto P_0c07e4e6;
case 0x0c07e4e8u: goto P_0c07e4e8;
case 0x0c07e4eau: goto P_0c07e4ea;
case 0x0c07e4ecu: goto P_0c07e4ec;
case 0x0c07e4eeu: goto P_0c07e4ee;
case 0x0c07e4f0u: goto P_0c07e4f0;
case 0x0c07e4f2u: goto P_0c07e4f2;
case 0x0c07e4f4u: goto P_0c07e4f4;
case 0x0c07e4f6u: goto P_0c07e4f6;
case 0x0c07e4f8u: goto P_0c07e4f8;
case 0x0c07e4fau: goto P_0c07e4fa;
case 0x0c07e4fcu: goto P_0c07e4fc;
case 0x0c07e4feu: goto P_0c07e4fe;
case 0x0c07e500u: goto P_0c07e500;
case 0x0c07e502u: goto P_0c07e502;
case 0x0c07e504u: goto P_0c07e504;
case 0x0c07e506u: goto P_0c07e506;
case 0x0c07e508u: goto P_0c07e508;
case 0x0c07e50au: goto P_0c07e50a;
case 0x0c07e50cu: goto P_0c07e50c;
case 0x0c07e50eu: goto P_0c07e50e;
case 0x0c07e510u: goto P_0c07e510;
case 0x0c07e512u: goto P_0c07e512;
case 0x0c07e514u: goto P_0c07e514;
case 0x0c07e516u: goto P_0c07e516;
case 0x0c07e518u: goto P_0c07e518;
case 0x0c07e51au: goto P_0c07e51a;
case 0x0c07e51cu: goto P_0c07e51c;
case 0x0c07e51eu: goto P_0c07e51e;
case 0x0c07e520u: goto P_0c07e520;
case 0x0c07e522u: goto P_0c07e522;
case 0x0c07e524u: goto P_0c07e524;
case 0x0c07e526u: goto P_0c07e526;
case 0x0c07e528u: goto P_0c07e528;
case 0x0c07e52au: goto P_0c07e52a;
case 0x0c07e52cu: goto P_0c07e52c;
case 0x0c07e52eu: goto P_0c07e52e;
case 0x0c07e530u: goto P_0c07e530;
case 0x0c07e532u: goto P_0c07e532;
case 0x0c07e534u: goto P_0c07e534;
case 0x0c07e536u: goto P_0c07e536;
case 0x0c07e538u: goto P_0c07e538;
case 0x0c07e53au: goto P_0c07e53a;
case 0x0c07e53cu: goto P_0c07e53c;
case 0x0c07e53eu: goto P_0c07e53e;
case 0x0c07e540u: goto P_0c07e540;
case 0x0c07e542u: goto P_0c07e542;
case 0x0c07e544u: goto P_0c07e544;
case 0x0c07e546u: goto P_0c07e546;
case 0x0c07e548u: goto P_0c07e548;
case 0x0c07e54au: goto P_0c07e54a;
case 0x0c07e54cu: goto P_0c07e54c;
case 0x0c07e54eu: goto P_0c07e54e;
case 0x0c07e550u: goto P_0c07e550;
case 0x0c07e552u: goto P_0c07e552;
case 0x0c07e554u: goto P_0c07e554;
case 0x0c07e556u: goto P_0c07e556;
case 0x0c07e558u: goto P_0c07e558;
case 0x0c07e55au: goto P_0c07e55a;
case 0x0c07e55cu: goto P_0c07e55c;
case 0x0c07e55eu: goto P_0c07e55e;
case 0x0c07e560u: goto P_0c07e560;
case 0x0c07e562u: goto P_0c07e562;
case 0x0c07e564u: goto P_0c07e564;
case 0x0c07e566u: goto P_0c07e566;
case 0x0c07e568u: goto P_0c07e568;
case 0x0c07e56au: goto P_0c07e56a;
case 0x0c07e56cu: goto P_0c07e56c;
case 0x0c07e56eu: goto P_0c07e56e;
case 0x0c07e570u: goto P_0c07e570;
case 0x0c07e572u: goto P_0c07e572;
case 0x0c07e574u: goto P_0c07e574;
case 0x0c07e576u: goto P_0c07e576;
case 0x0c07e578u: goto P_0c07e578;
case 0x0c07e57au: goto P_0c07e57a;
case 0x0c07e57cu: goto P_0c07e57c;
case 0x0c07e57eu: goto P_0c07e57e;
case 0x0c07e580u: goto P_0c07e580;
case 0x0c07e582u: goto P_0c07e582;
case 0x0c07e584u: goto P_0c07e584;
case 0x0c07e586u: goto P_0c07e586;
case 0x0c07e588u: goto P_0c07e588;
case 0x0c07e58au: goto P_0c07e58a;
case 0x0c07e58cu: goto P_0c07e58c;
case 0x0c07e58eu: goto P_0c07e58e;
case 0x0c07e590u: goto P_0c07e590;
case 0x0c07e592u: goto P_0c07e592;
case 0x0c07e594u: goto P_0c07e594;
case 0x0c07e596u: goto P_0c07e596;
case 0x0c07e598u: goto P_0c07e598;
case 0x0c07e59au: goto P_0c07e59a;
case 0x0c07e59cu: goto P_0c07e59c;
case 0x0c07e59eu: goto P_0c07e59e;
case 0x0c07e5a0u: goto P_0c07e5a0;
case 0x0c07e5a2u: goto P_0c07e5a2;
case 0x0c07e5a4u: goto P_0c07e5a4;
case 0x0c07e5a6u: goto P_0c07e5a6;
case 0x0c07e5a8u: goto P_0c07e5a8;
case 0x0c07e5aau: goto P_0c07e5aa;
case 0x0c07e5acu: goto P_0c07e5ac;
case 0x0c07e5aeu: goto P_0c07e5ae;
case 0x0c07e5b0u: goto P_0c07e5b0;
case 0x0c07e5b2u: goto P_0c07e5b2;
case 0x0c07e5b4u: goto P_0c07e5b4;
case 0x0c07e5b6u: goto P_0c07e5b6;
case 0x0c07e5b8u: goto P_0c07e5b8;
case 0x0c07e5bau: goto P_0c07e5ba;
case 0x0c07e5bcu: goto P_0c07e5bc;
case 0x0c07e5beu: goto P_0c07e5be;
case 0x0c07e5c0u: goto P_0c07e5c0;
case 0x0c07e5c2u: goto P_0c07e5c2;
case 0x0c07e5c4u: goto P_0c07e5c4;
case 0x0c07e5c6u: goto P_0c07e5c6;
case 0x0c07e5c8u: goto P_0c07e5c8;
case 0x0c07e5cau: goto P_0c07e5ca;
case 0x0c07e5ccu: goto P_0c07e5cc;
case 0x0c07e5ceu: goto P_0c07e5ce;
case 0x0c07e5d0u: goto P_0c07e5d0;
case 0x0c07e5d2u: goto P_0c07e5d2;
case 0x0c07e5d4u: goto P_0c07e5d4;
case 0x0c07e5d6u: goto P_0c07e5d6;
case 0x0c07e5d8u: goto P_0c07e5d8;
case 0x0c07e5dau: goto P_0c07e5da;
case 0x0c07e5dcu: goto P_0c07e5dc;
case 0x0c07e5deu: goto P_0c07e5de;
case 0x0c07e5e0u: goto P_0c07e5e0;
case 0x0c07e5e2u: goto P_0c07e5e2;
case 0x0c07e5e4u: goto P_0c07e5e4;
case 0x0c07e608u: goto P_0c07e608;
case 0x0c07e60au: goto P_0c07e60a;
case 0x0c07e60cu: goto P_0c07e60c;
case 0x0c07e60eu: goto P_0c07e60e;
case 0x0c07e610u: goto P_0c07e610;
case 0x0c07e612u: goto P_0c07e612;
case 0x0c07e614u: goto P_0c07e614;
case 0x0c07e616u: goto P_0c07e616;
case 0x0c07e618u: goto P_0c07e618;
case 0x0c07e61au: goto P_0c07e61a;
case 0x0c07e61cu: goto P_0c07e61c;
case 0x0c07e61eu: goto P_0c07e61e;
case 0x0c07e620u: goto P_0c07e620;
case 0x0c07e622u: goto P_0c07e622;
case 0x0c07e624u: goto P_0c07e624;
case 0x0c07e626u: goto P_0c07e626;
case 0x0c07e628u: goto P_0c07e628;
case 0x0c07e62au: goto P_0c07e62a;
case 0x0c07e62cu: goto P_0c07e62c;
case 0x0c07e62eu: goto P_0c07e62e;
case 0x0c07e630u: goto P_0c07e630;
case 0x0c07e632u: goto P_0c07e632;
case 0x0c07e634u: goto P_0c07e634;
case 0x0c07e636u: goto P_0c07e636;
case 0x0c07e638u: goto P_0c07e638;
case 0x0c07e63au: goto P_0c07e63a;
case 0x0c07e63cu: goto P_0c07e63c;
case 0x0c07e63eu: goto P_0c07e63e;
case 0x0c07e640u: goto P_0c07e640;
case 0x0c07e642u: goto P_0c07e642;
case 0x0c07e644u: goto P_0c07e644;
case 0x0c07e646u: goto P_0c07e646;
case 0x0c07e648u: goto P_0c07e648;
case 0x0c07e64au: goto P_0c07e64a;
case 0x0c07e64cu: goto P_0c07e64c;
case 0x0c07e64eu: goto P_0c07e64e;
case 0x0c07e650u: goto P_0c07e650;
case 0x0c07e652u: goto P_0c07e652;
case 0x0c07e654u: goto P_0c07e654;
case 0x0c07e656u: goto P_0c07e656;
case 0x0c07e658u: goto P_0c07e658;
case 0x0c07e65au: goto P_0c07e65a;
case 0x0c07e65cu: goto P_0c07e65c;
case 0x0c07e65eu: goto P_0c07e65e;
case 0x0c07e660u: goto P_0c07e660;
case 0x0c07e662u: goto P_0c07e662;
case 0x0c07e664u: goto P_0c07e664;
case 0x0c07e666u: goto P_0c07e666;
case 0x0c07e668u: goto P_0c07e668;
case 0x0c07e66au: goto P_0c07e66a;
case 0x0c07e66cu: goto P_0c07e66c;
case 0x0c07e66eu: goto P_0c07e66e;
case 0x0c07e670u: goto P_0c07e670;
case 0x0c07e672u: goto P_0c07e672;
case 0x0c07e674u: goto P_0c07e674;
case 0x0c07e676u: goto P_0c07e676;
case 0x0c07e678u: goto P_0c07e678;
case 0x0c07e67au: goto P_0c07e67a;
case 0x0c07e67cu: goto P_0c07e67c;
case 0x0c07e67eu: goto P_0c07e67e;
case 0x0c07e680u: goto P_0c07e680;
case 0x0c07e682u: goto P_0c07e682;
case 0x0c07e684u: goto P_0c07e684;
case 0x0c07e686u: goto P_0c07e686;
case 0x0c07e688u: goto P_0c07e688;
case 0x0c07e68au: goto P_0c07e68a;
case 0x0c07e68cu: goto P_0c07e68c;
case 0x0c07e68eu: goto P_0c07e68e;
case 0x0c07e690u: goto P_0c07e690;
case 0x0c07e692u: goto P_0c07e692;
case 0x0c07e694u: goto P_0c07e694;
case 0x0c07e696u: goto P_0c07e696;
case 0x0c07e698u: goto P_0c07e698;
case 0x0c07e69au: goto P_0c07e69a;
case 0x0c07e69cu: goto P_0c07e69c;
case 0x0c07e69eu: goto P_0c07e69e;
case 0x0c07e6a0u: goto P_0c07e6a0;
case 0x0c07e6a2u: goto P_0c07e6a2;
case 0x0c07e6a4u: goto P_0c07e6a4;
case 0x0c07e6a6u: goto P_0c07e6a6;
case 0x0c07e6a8u: goto P_0c07e6a8;
case 0x0c07e6aau: goto P_0c07e6aa;
case 0x0c07e6acu: goto P_0c07e6ac;
case 0x0c07e6aeu: goto P_0c07e6ae;
case 0x0c07e6b0u: goto P_0c07e6b0;
case 0x0c07e6b2u: goto P_0c07e6b2;
case 0x0c07e6b4u: goto P_0c07e6b4;
case 0x0c07e6b6u: goto P_0c07e6b6;
case 0x0c07e6b8u: goto P_0c07e6b8;
case 0x0c07e6bau: goto P_0c07e6ba;
case 0x0c07e6bcu: goto P_0c07e6bc;
case 0x0c07e6beu: goto P_0c07e6be;
case 0x0c07e6c0u: goto P_0c07e6c0;
case 0x0c07e6c2u: goto P_0c07e6c2;
case 0x0c07e6c4u: goto P_0c07e6c4;
case 0x0c07e6c6u: goto P_0c07e6c6;
case 0x0c07e6c8u: goto P_0c07e6c8;
case 0x0c07e6cau: goto P_0c07e6ca;
case 0x0c07e6ccu: goto P_0c07e6cc;
case 0x0c07e6ceu: goto P_0c07e6ce;
case 0x0c07e6d0u: goto P_0c07e6d0;
case 0x0c07e6d2u: goto P_0c07e6d2;
case 0x0c07e6d4u: goto P_0c07e6d4;
case 0x0c07e6d6u: goto P_0c07e6d6;
case 0x0c07e6d8u: goto P_0c07e6d8;
case 0x0c07e6dau: goto P_0c07e6da;
case 0x0c07e6dcu: goto P_0c07e6dc;
case 0x0c07e6deu: goto P_0c07e6de;
case 0x0c07e6e0u: goto P_0c07e6e0;
case 0x0c07e6e2u: goto P_0c07e6e2;
case 0x0c07e6e4u: goto P_0c07e6e4;
case 0x0c07e6e6u: goto P_0c07e6e6;
case 0x0c07e6e8u: goto P_0c07e6e8;
case 0x0c07e6eau: goto P_0c07e6ea;
case 0x0c07e6ecu: goto P_0c07e6ec;
case 0x0c07e6eeu: goto P_0c07e6ee;
case 0x0c07e6f0u: goto P_0c07e6f0;
case 0x0c07e6f2u: goto P_0c07e6f2;
case 0x0c07e6f4u: goto P_0c07e6f4;
case 0x0c07e6f6u: goto P_0c07e6f6;
case 0x0c07e6f8u: goto P_0c07e6f8;
case 0x0c07e6fau: goto P_0c07e6fa;
case 0x0c07e6fcu: goto P_0c07e6fc;
case 0x0c07e6feu: goto P_0c07e6fe;
case 0x0c07e700u: goto P_0c07e700;
case 0x0c07e720u: goto P_0c07e720;
case 0x0c07e722u: goto P_0c07e722;
case 0x0c07e724u: goto P_0c07e724;
case 0x0c07e726u: goto P_0c07e726;
case 0x0c07e728u: goto P_0c07e728;
case 0x0c07e72au: goto P_0c07e72a;
case 0x0c07e72cu: goto P_0c07e72c;
case 0x0c07e72eu: goto P_0c07e72e;
case 0x0c07e730u: goto P_0c07e730;
case 0x0c07e732u: goto P_0c07e732;
case 0x0c07e734u: goto P_0c07e734;
case 0x0c07e736u: goto P_0c07e736;
case 0x0c07e738u: goto P_0c07e738;
case 0x0c07e73au: goto P_0c07e73a;
case 0x0c07e73cu: goto P_0c07e73c;
case 0x0c07e73eu: goto P_0c07e73e;
case 0x0c07e740u: goto P_0c07e740;
case 0x0c07e742u: goto P_0c07e742;
case 0x0c07e744u: goto P_0c07e744;
case 0x0c07e746u: goto P_0c07e746;
case 0x0c07e748u: goto P_0c07e748;
case 0x0c07e74au: goto P_0c07e74a;
case 0x0c07e74cu: goto P_0c07e74c;
case 0x0c07e74eu: goto P_0c07e74e;
case 0x0c07e750u: goto P_0c07e750;
case 0x0c07e752u: goto P_0c07e752;
case 0x0c07e754u: goto P_0c07e754;
case 0x0c07e756u: goto P_0c07e756;
case 0x0c07e758u: goto P_0c07e758;
case 0x0c07e75au: goto P_0c07e75a;
case 0x0c07e75cu: goto P_0c07e75c;
case 0x0c07e75eu: goto P_0c07e75e;
case 0x0c07e760u: goto P_0c07e760;
case 0x0c07e762u: goto P_0c07e762;
case 0x0c07e764u: goto P_0c07e764;
case 0x0c07e766u: goto P_0c07e766;
case 0x0c07e768u: goto P_0c07e768;
case 0x0c07e76au: goto P_0c07e76a;
case 0x0c07e76cu: goto P_0c07e76c;
case 0x0c07e76eu: goto P_0c07e76e;
case 0x0c07e770u: goto P_0c07e770;
case 0x0c07e772u: goto P_0c07e772;
case 0x0c07e774u: goto P_0c07e774;
case 0x0c07e776u: goto P_0c07e776;
case 0x0c07e778u: goto P_0c07e778;
case 0x0c07e77au: goto P_0c07e77a;
case 0x0c07e77cu: goto P_0c07e77c;
case 0x0c07e77eu: goto P_0c07e77e;
case 0x0c07e780u: goto P_0c07e780;
case 0x0c07e782u: goto P_0c07e782;
case 0x0c07e784u: goto P_0c07e784;
case 0x0c07e786u: goto P_0c07e786;
case 0x0c07e788u: goto P_0c07e788;
case 0x0c07e78au: goto P_0c07e78a;
case 0x0c07e78cu: goto P_0c07e78c;
case 0x0c07e78eu: goto P_0c07e78e;
case 0x0c07e790u: goto P_0c07e790;
case 0x0c07e792u: goto P_0c07e792;
case 0x0c07e794u: goto P_0c07e794;
case 0x0c07e796u: goto P_0c07e796;
case 0x0c07e798u: goto P_0c07e798;
case 0x0c07e79au: goto P_0c07e79a;
case 0x0c07e79cu: goto P_0c07e79c;
case 0x0c07e79eu: goto P_0c07e79e;
case 0x0c07e7a0u: goto P_0c07e7a0;
case 0x0c07e7a2u: goto P_0c07e7a2;
case 0x0c07e7a4u: goto P_0c07e7a4;
case 0x0c07e7a6u: goto P_0c07e7a6;
case 0x0c07e7a8u: goto P_0c07e7a8;
case 0x0c07e7aau: goto P_0c07e7aa;
case 0x0c07e7acu: goto P_0c07e7ac;
case 0x0c07e7aeu: goto P_0c07e7ae;
case 0x0c07e7b0u: goto P_0c07e7b0;
case 0x0c07e7b2u: goto P_0c07e7b2;
case 0x0c07e7b4u: goto P_0c07e7b4;
case 0x0c07e7b6u: goto P_0c07e7b6;
case 0x0c07e7b8u: goto P_0c07e7b8;
case 0x0c07e7bau: goto P_0c07e7ba;
case 0x0c07e7bcu: goto P_0c07e7bc;
case 0x0c07e7beu: goto P_0c07e7be;
case 0x0c07e7c0u: goto P_0c07e7c0;
case 0x0c07e7c2u: goto P_0c07e7c2;
case 0x0c07e7c4u: goto P_0c07e7c4;
case 0x0c07e7c6u: goto P_0c07e7c6;
case 0x0c07e7c8u: goto P_0c07e7c8;
case 0x0c07e7cau: goto P_0c07e7ca;
case 0x0c07e7ccu: goto P_0c07e7cc;
case 0x0c07e7ceu: goto P_0c07e7ce;
case 0x0c07e7d0u: goto P_0c07e7d0;
case 0x0c07e7d2u: goto P_0c07e7d2;
case 0x0c07e7d4u: goto P_0c07e7d4;
case 0x0c07e7d6u: goto P_0c07e7d6;
case 0x0c07e7d8u: goto P_0c07e7d8;
case 0x0c07e7dau: goto P_0c07e7da;
case 0x0c07e7dcu: goto P_0c07e7dc;
case 0x0c07e7deu: goto P_0c07e7de;
case 0x0c07e7e0u: goto P_0c07e7e0;
case 0x0c07e7e2u: goto P_0c07e7e2;
case 0x0c07e7e4u: goto P_0c07e7e4;
case 0x0c07e7e6u: goto P_0c07e7e6;
case 0x0c07e7e8u: goto P_0c07e7e8;
case 0x0c07e7eau: goto P_0c07e7ea;
case 0x0c07e7ecu: goto P_0c07e7ec;
case 0x0c07e7eeu: goto P_0c07e7ee;
case 0x0c07e7f0u: goto P_0c07e7f0;
case 0x0c07e7f2u: goto P_0c07e7f2;
case 0x0c07e7f4u: goto P_0c07e7f4;
case 0x0c07e7f6u: goto P_0c07e7f6;
case 0x0c07e7f8u: goto P_0c07e7f8;
case 0x0c07e7fau: goto P_0c07e7fa;
case 0x0c07e7fcu: goto P_0c07e7fc;
case 0x0c07e7feu: goto P_0c07e7fe;
case 0x0c07e800u: goto P_0c07e800;
case 0x0c07e802u: goto P_0c07e802;
case 0x0c07e804u: goto P_0c07e804;
case 0x0c07e806u: goto P_0c07e806;
case 0x0c07e808u: goto P_0c07e808;
case 0x0c07e80au: goto P_0c07e80a;
case 0x0c07e80cu: goto P_0c07e80c;
case 0x0c07e80eu: goto P_0c07e80e;
case 0x0c07e810u: goto P_0c07e810;
case 0x0c07e812u: goto P_0c07e812;
case 0x0c07e814u: goto P_0c07e814;
case 0x0c07e816u: goto P_0c07e816;
case 0x0c07e818u: goto P_0c07e818;
case 0x0c07e81au: goto P_0c07e81a;
case 0x0c07e81cu: goto P_0c07e81c;
case 0x0c07e81eu: goto P_0c07e81e;
case 0x0c080920u: goto P_0c080920;
case 0x0c080922u: goto P_0c080922;
case 0x0c080924u: goto P_0c080924;
case 0x0c080926u: goto P_0c080926;
case 0x0c080928u: goto P_0c080928;
case 0x0c08092au: goto P_0c08092a;
case 0x0c08092cu: goto P_0c08092c;
case 0x0c08092eu: goto P_0c08092e;
case 0x0c080930u: goto P_0c080930;
case 0x0c080932u: goto P_0c080932;
case 0x0c080934u: goto P_0c080934;
case 0x0c080936u: goto P_0c080936;
case 0x0c080938u: goto P_0c080938;
case 0x0c08093au: goto P_0c08093a;
case 0x0c08093cu: goto P_0c08093c;
case 0x0c08093eu: goto P_0c08093e;
case 0x0c080940u: goto P_0c080940;
case 0x0c080942u: goto P_0c080942;
case 0x0c080944u: goto P_0c080944;
case 0x0c080946u: goto P_0c080946;
case 0x0c080948u: goto P_0c080948;
case 0x0c08094au: goto P_0c08094a;
case 0x0c08094cu: goto P_0c08094c;
case 0x0c08094eu: goto P_0c08094e;
case 0x0c080950u: goto P_0c080950;
case 0x0c080952u: goto P_0c080952;
case 0x0c080954u: goto P_0c080954;
case 0x0c080956u: goto P_0c080956;
case 0x0c080958u: goto P_0c080958;
case 0x0c08095au: goto P_0c08095a;
case 0x0c08095cu: goto P_0c08095c;
case 0x0c08095eu: goto P_0c08095e;
case 0x0c080960u: goto P_0c080960;
case 0x0c080962u: goto P_0c080962;
case 0x0c080964u: goto P_0c080964;
case 0x0c080966u: goto P_0c080966;
case 0x0c080968u: goto P_0c080968;
case 0x0c08096au: goto P_0c08096a;
case 0x0c08096cu: goto P_0c08096c;
case 0x0c08096eu: goto P_0c08096e;
case 0x0c080970u: goto P_0c080970;
case 0x0c080972u: goto P_0c080972;
case 0x0c080974u: goto P_0c080974;
case 0x0c080976u: goto P_0c080976;
case 0x0c080978u: goto P_0c080978;
case 0x0c08097au: goto P_0c08097a;
case 0x0c08097cu: goto P_0c08097c;
case 0x0c08097eu: goto P_0c08097e;
case 0x0c080980u: goto P_0c080980;
case 0x0c080982u: goto P_0c080982;
case 0x0c080984u: goto P_0c080984;
case 0x0c080986u: goto P_0c080986;
case 0x0c080988u: goto P_0c080988;
case 0x0c08098au: goto P_0c08098a;
case 0x0c08098cu: goto P_0c08098c;
case 0x0c08098eu: goto P_0c08098e;
case 0x0c080990u: goto P_0c080990;
case 0x0c080992u: goto P_0c080992;
case 0x0c080994u: goto P_0c080994;
case 0x0c080996u: goto P_0c080996;
case 0x0c080998u: goto P_0c080998;
case 0x0c08099au: goto P_0c08099a;
case 0x0c08099cu: goto P_0c08099c;
case 0x0c08099eu: goto P_0c08099e;
case 0x0c0809a0u: goto P_0c0809a0;
case 0x0c0809a2u: goto P_0c0809a2;
case 0x0c0809a4u: goto P_0c0809a4;
case 0x0c0809a6u: goto P_0c0809a6;
case 0x0c0809a8u: goto P_0c0809a8;
case 0x0c0809aau: goto P_0c0809aa;
case 0x0c0809acu: goto P_0c0809ac;
case 0x0c0809aeu: goto P_0c0809ae;
case 0x0c0809b0u: goto P_0c0809b0;
case 0x0c0809b2u: goto P_0c0809b2;
case 0x0c0809b4u: goto P_0c0809b4;
case 0x0c0809b6u: goto P_0c0809b6;
case 0x0c0809b8u: goto P_0c0809b8;
case 0x0c0809bau: goto P_0c0809ba;
case 0x0c0809bcu: goto P_0c0809bc;
case 0x0c0809beu: goto P_0c0809be;
case 0x0c0809c0u: goto P_0c0809c0;
case 0x0c0809c2u: goto P_0c0809c2;
case 0x0c0809c4u: goto P_0c0809c4;
case 0x0c0809c6u: goto P_0c0809c6;
case 0x0c0809c8u: goto P_0c0809c8;
case 0x0c0809cau: goto P_0c0809ca;
case 0x0c0809ccu: goto P_0c0809cc;
case 0x0c0809ceu: goto P_0c0809ce;
case 0x0c0809d0u: goto P_0c0809d0;
case 0x0c0809d2u: goto P_0c0809d2;
case 0x0c0809d4u: goto P_0c0809d4;
case 0x0c0809d6u: goto P_0c0809d6;
case 0x0c0809d8u: goto P_0c0809d8;
case 0x0c0809dau: goto P_0c0809da;
case 0x0c0809dcu: goto P_0c0809dc;
case 0x0c0809deu: goto P_0c0809de;
case 0x0c0809e0u: goto P_0c0809e0;
case 0x0c0809e2u: goto P_0c0809e2;
case 0x0c0809e4u: goto P_0c0809e4;
case 0x0c0809e6u: goto P_0c0809e6;
case 0x0c0809e8u: goto P_0c0809e8;
case 0x0c0809eau: goto P_0c0809ea;
case 0x0c0809ecu: goto P_0c0809ec;
case 0x0c0809eeu: goto P_0c0809ee;
case 0x0c0809f0u: goto P_0c0809f0;
case 0x0c0809f2u: goto P_0c0809f2;
case 0x0c0809f4u: goto P_0c0809f4;
case 0x0c0809f6u: goto P_0c0809f6;
case 0x0c0809f8u: goto P_0c0809f8;
case 0x0c0809fau: goto P_0c0809fa;
case 0x0c0809fcu: goto P_0c0809fc;
case 0x0c0809feu: goto P_0c0809fe;
case 0x0c080a00u: goto P_0c080a00;
case 0x0c080a02u: goto P_0c080a02;
case 0x0c080a04u: goto P_0c080a04;
case 0x0c080a06u: goto P_0c080a06;
case 0x0c080a08u: goto P_0c080a08;
case 0x0c080a0au: goto P_0c080a0a;
case 0x0c080a0cu: goto P_0c080a0c;
case 0x0c080a0eu: goto P_0c080a0e;
case 0x0c080a10u: goto P_0c080a10;
case 0x0c080a12u: goto P_0c080a12;
case 0x0c080a14u: goto P_0c080a14;
case 0x0c080a16u: goto P_0c080a16;
case 0x0c080a18u: goto P_0c080a18;
case 0x0c080a1au: goto P_0c080a1a;
case 0x0c080a1cu: goto P_0c080a1c;
case 0x0c080a1eu: goto P_0c080a1e;
case 0x0c080a20u: goto P_0c080a20;
case 0x0c080a22u: goto P_0c080a22;
case 0x0c080a24u: goto P_0c080a24;
case 0x0c080a26u: goto P_0c080a26;
case 0x0c080a28u: goto P_0c080a28;
case 0x0c080a2au: goto P_0c080a2a;
case 0x0c080a2cu: goto P_0c080a2c;
case 0x0c080a2eu: goto P_0c080a2e;
case 0x0c080a30u: goto P_0c080a30;
case 0x0c080a32u: goto P_0c080a32;
case 0x0c080a34u: goto P_0c080a34;
case 0x0c080a36u: goto P_0c080a36;
case 0x0c080a38u: goto P_0c080a38;
case 0x0c080a3au: goto P_0c080a3a;
case 0x0c080a3cu: goto P_0c080a3c;
case 0x0c080a3eu: goto P_0c080a3e;
case 0x0c080a40u: goto P_0c080a40;
case 0x0c080a42u: goto P_0c080a42;
case 0x0c080a44u: goto P_0c080a44;
case 0x0c080a46u: goto P_0c080a46;
case 0x0c080a48u: goto P_0c080a48;
case 0x0c080a4au: goto P_0c080a4a;
case 0x0c080a4cu: goto P_0c080a4c;
case 0x0c080a4eu: goto P_0c080a4e;
case 0x0c080a50u: goto P_0c080a50;
case 0x0c080a52u: goto P_0c080a52;
case 0x0c080a54u: goto P_0c080a54;
case 0x0c080a74u: goto P_0c080a74;
case 0x0c080a76u: goto P_0c080a76;
case 0x0c080a78u: goto P_0c080a78;
case 0x0c080a7au: goto P_0c080a7a;
case 0x0c080a7cu: goto P_0c080a7c;
case 0x0c080a7eu: goto P_0c080a7e;
case 0x0c080a80u: goto P_0c080a80;
case 0x0c080a82u: goto P_0c080a82;
case 0x0c080a84u: goto P_0c080a84;
case 0x0c080a86u: goto P_0c080a86;
case 0x0c080a88u: goto P_0c080a88;
case 0x0c080a8au: goto P_0c080a8a;
case 0x0c080a8cu: goto P_0c080a8c;
case 0x0c080a8eu: goto P_0c080a8e;
case 0x0c080a90u: goto P_0c080a90;
case 0x0c080a92u: goto P_0c080a92;
case 0x0c080a94u: goto P_0c080a94;
case 0x0c080a96u: goto P_0c080a96;
case 0x0c080a98u: goto P_0c080a98;
case 0x0c080a9au: goto P_0c080a9a;
case 0x0c080a9cu: goto P_0c080a9c;
case 0x0c080a9eu: goto P_0c080a9e;
case 0x0c080aa0u: goto P_0c080aa0;
case 0x0c080aa2u: goto P_0c080aa2;
case 0x0c080aa4u: goto P_0c080aa4;
case 0x0c080aa6u: goto P_0c080aa6;
case 0x0c080aa8u: goto P_0c080aa8;
case 0x0c080aaau: goto P_0c080aaa;
case 0x0c080aacu: goto P_0c080aac;
case 0x0c080aaeu: goto P_0c080aae;
case 0x0c080ab0u: goto P_0c080ab0;
case 0x0c080ab2u: goto P_0c080ab2;
case 0x0c080ab4u: goto P_0c080ab4;
case 0x0c080ab6u: goto P_0c080ab6;
case 0x0c080ab8u: goto P_0c080ab8;
case 0x0c080abau: goto P_0c080aba;
case 0x0c080abcu: goto P_0c080abc;
case 0x0c080abeu: goto P_0c080abe;
case 0x0c080ac0u: goto P_0c080ac0;
case 0x0c080ac2u: goto P_0c080ac2;
case 0x0c080ac4u: goto P_0c080ac4;
case 0x0c080ac6u: goto P_0c080ac6;
case 0x0c080ac8u: goto P_0c080ac8;
case 0x0c080acau: goto P_0c080aca;
case 0x0c080accu: goto P_0c080acc;
case 0x0c080aceu: goto P_0c080ace;
case 0x0c080ad0u: goto P_0c080ad0;
case 0x0c080ad2u: goto P_0c080ad2;
case 0x0c080ad4u: goto P_0c080ad4;
case 0x0c080ad6u: goto P_0c080ad6;
case 0x0c080ad8u: goto P_0c080ad8;
case 0x0c080adau: goto P_0c080ada;
case 0x0c080adcu: goto P_0c080adc;
case 0x0c080adeu: goto P_0c080ade;
case 0x0c080ae0u: goto P_0c080ae0;
case 0x0c080ae2u: goto P_0c080ae2;
case 0x0c080ae4u: goto P_0c080ae4;
case 0x0c080ae6u: goto P_0c080ae6;
case 0x0c080ae8u: goto P_0c080ae8;
case 0x0c080aeau: goto P_0c080aea;
case 0x0c080aecu: goto P_0c080aec;
case 0x0c080aeeu: goto P_0c080aee;
case 0x0c080af0u: goto P_0c080af0;
case 0x0c080af2u: goto P_0c080af2;
case 0x0c080af4u: goto P_0c080af4;
case 0x0c080af6u: goto P_0c080af6;
case 0x0c080af8u: goto P_0c080af8;
case 0x0c080afau: goto P_0c080afa;
case 0x0c080afcu: goto P_0c080afc;
case 0x0c080afeu: goto P_0c080afe;
case 0x0c080b00u: goto P_0c080b00;
case 0x0c080b02u: goto P_0c080b02;
case 0x0c080b04u: goto P_0c080b04;
case 0x0c080b06u: goto P_0c080b06;
case 0x0c080b08u: goto P_0c080b08;
case 0x0c080b0au: goto P_0c080b0a;
case 0x0c080b0cu: goto P_0c080b0c;
case 0x0c080b0eu: goto P_0c080b0e;
case 0x0c080b10u: goto P_0c080b10;
case 0x0c080b12u: goto P_0c080b12;
case 0x0c080b14u: goto P_0c080b14;
case 0x0c080b16u: goto P_0c080b16;
case 0x0c080b18u: goto P_0c080b18;
case 0x0c080b1au: goto P_0c080b1a;
case 0x0c080b1cu: goto P_0c080b1c;
case 0x0c080b1eu: goto P_0c080b1e;
case 0x0c080b20u: goto P_0c080b20;
case 0x0c080b22u: goto P_0c080b22;
case 0x0c080b24u: goto P_0c080b24;
case 0x0c080b26u: goto P_0c080b26;
case 0x0c080b28u: goto P_0c080b28;
case 0x0c080b2au: goto P_0c080b2a;
case 0x0c080b2cu: goto P_0c080b2c;
case 0x0c080b2eu: goto P_0c080b2e;
case 0x0c080b30u: goto P_0c080b30;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07e0f0: /* original 2fe6, guest PC 0x0c07e0f0 */
if(!s->budget--) { s->failed_pc=0x0c07e0f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e0f2;
P_0c07e0f2: /* original 6343, guest PC 0x0c07e0f2 */
if(!s->budget--) { s->failed_pc=0x0c07e0f2u; return 0; }
r[3]=r[4];
goto P_0c07e0f4;
P_0c07e0f4: /* original 2fd6, guest PC 0x0c07e0f4 */
if(!s->budget--) { s->failed_pc=0x0c07e0f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e0f6;
P_0c07e0f6: /* original 7328, guest PC 0x0c07e0f6 */
if(!s->budget--) { s->failed_pc=0x0c07e0f6u; return 0; }
r[3]+=0x00000028u;
goto P_0c07e0f8;
P_0c07e0f8: /* original 2fc6, guest PC 0x0c07e0f8 */
if(!s->budget--) { s->failed_pc=0x0c07e0f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e0fa;
P_0c07e0fa: /* original 6e43, guest PC 0x0c07e0fa */
if(!s->budget--) { s->failed_pc=0x0c07e0fau; return 0; }
r[14]=r[4];
goto P_0c07e0fc;
P_0c07e0fc: /* original 2fb6, guest PC 0x0c07e0fc */
if(!s->budget--) { s->failed_pc=0x0c07e0fcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e0fe;
P_0c07e0fe: /* original 2fa6, guest PC 0x0c07e0fe */
if(!s->budget--) { s->failed_pc=0x0c07e0feu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e100;
P_0c07e100: /* original 2f96, guest PC 0x0c07e100 */
if(!s->budget--) { s->failed_pc=0x0c07e100u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e102;
P_0c07e102: /* original 2f86, guest PC 0x0c07e102 */
if(!s->budget--) { s->failed_pc=0x0c07e102u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e104;
P_0c07e104: /* original 4f22, guest PC 0x0c07e104 */
if(!s->budget--) { s->failed_pc=0x0c07e104u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e106;
P_0c07e106: /* original 7ff8, guest PC 0x0c07e106 */
if(!s->budget--) { s->failed_pc=0x0c07e106u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e108;
P_0c07e108: /* original 2f52, guest PC 0x0c07e108 */
if(!s->budget--) { s->failed_pc=0x0c07e108u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c07e10a;
P_0c07e10a: /* original 6231, guest PC 0x0c07e10a */
if(!s->budget--) { s->failed_pc=0x0c07e10au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c07e10c;
P_0c07e10c: /* original d929, guest PC 0x0c07e10c */
if(!s->budget--) { s->failed_pc=0x0c07e10cu; return 0; }
r[9]=read(ram,0x0c07e1b4u,4);
goto P_0c07e10e;
P_0c07e10e: /* original 622d, guest PC 0x0c07e10e */
if(!s->budget--) { s->failed_pc=0x0c07e10eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c07e110;
P_0c07e110: /* original 1f21, guest PC 0x0c07e110 */
if(!s->budget--) { s->failed_pc=0x0c07e110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07e112;
P_0c07e112: /* original d329, guest PC 0x0c07e112 */
if(!s->budget--) { s->failed_pc=0x0c07e112u; return 0; }
r[3]=read(ram,0x0c07e1b8u,4);
goto P_0c07e114;
P_0c07e114: /* original 430b, guest PC 0x0c07e114 */
if(!s->budget--) { s->failed_pc=0x0c07e114u; return 0; }
target=r[3];
r[16]=code_base|0x0c07e118u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e118u) { target=s->pc; goto dispatch; }
goto P_0c07e118;
P_0c07e116: /* original 6493, guest PC 0x0c07e116 */
if(!s->budget--) { s->failed_pc=0x0c07e116u; return 0; }
r[4]=r[9];
goto P_0c07e118;
P_0c07e118: /* original dc28, guest PC 0x0c07e118 */
if(!s->budget--) { s->failed_pc=0x0c07e118u; return 0; }
r[12]=read(ram,0x0c07e1bcu,4);
goto P_0c07e11a;
P_0c07e11a: /* original e804, guest PC 0x0c07e11a */
if(!s->budget--) { s->failed_pc=0x0c07e11au; return 0; }
r[8]=0x00000004u;
goto P_0c07e11c;
P_0c07e11c: /* original 7e44, guest PC 0x0c07e11c */
if(!s->budget--) { s->failed_pc=0x0c07e11cu; return 0; }
r[14]+=0x00000044u;
goto P_0c07e11e;
P_0c07e11e: /* original eb00, guest PC 0x0c07e11e */
if(!s->budget--) { s->failed_pc=0x0c07e11eu; return 0; }
r[11]=0x00000000u;
goto P_0c07e120;
P_0c07e120: /* original ea04, guest PC 0x0c07e120 */
if(!s->budget--) { s->failed_pc=0x0c07e120u; return 0; }
r[10]=0x00000004u;
goto P_0c07e122;
P_0c07e122: /* original ed00, guest PC 0x0c07e122 */
if(!s->budget--) { s->failed_pc=0x0c07e122u; return 0; }
r[13]=0x00000000u;
goto P_0c07e124;
P_0c07e124: /* original e004, guest PC 0x0c07e124 */
if(!s->budget--) { s->failed_pc=0x0c07e124u; return 0; }
r[0]=0x00000004u;
goto P_0c07e126;
P_0c07e126: /* original f5e8, guest PC 0x0c07e126 */
if(!s->budget--) { s->failed_pc=0x0c07e126u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c07e128;
P_0c07e128: /* original f4e6, guest PC 0x0c07e128 */
if(!s->budget--) { s->failed_pc=0x0c07e128u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c07e12a;
P_0c07e12a: /* original e008, guest PC 0x0c07e12a */
if(!s->budget--) { s->failed_pc=0x0c07e12au; return 0; }
r[0]=0x00000008u;
goto P_0c07e12c;
P_0c07e12c: /* original f6e6, guest PC 0x0c07e12c */
if(!s->budget--) { s->failed_pc=0x0c07e12cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c07e12e;
P_0c07e12e: /* original e00c, guest PC 0x0c07e12e */
if(!s->budget--) { s->failed_pc=0x0c07e12eu; return 0; }
r[0]=0x0000000cu;
goto P_0c07e130;
P_0c07e130: /* original f7e6, guest PC 0x0c07e130 */
if(!s->budget--) { s->failed_pc=0x0c07e130u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c07e132;
P_0c07e132: /* original e004, guest PC 0x0c07e132 */
if(!s->budget--) { s->failed_pc=0x0c07e132u; return 0; }
r[0]=0x00000004u;
goto P_0c07e134;
P_0c07e134: /* original f560, guest PC 0x0c07e134 */
if(!s->budget--) { s->failed_pc=0x0c07e134u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c07e136;
P_0c07e136: /* original f470, guest PC 0x0c07e136 */
if(!s->budget--) { s->failed_pc=0x0c07e136u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c07e138;
P_0c07e138: /* original f53d, guest PC 0x0c07e138 */
if(!s->budget--) { s->failed_pc=0x0c07e138u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c07e13a;
P_0c07e13a: /* original fe5a, guest PC 0x0c07e13a */
if(!s->budget--) { s->failed_pc=0x0c07e13au; return 0; }
vf3_matrix_store(s,ram,5,r[14]);
goto P_0c07e13c;
P_0c07e13c: /* original fe47, guest PC 0x0c07e13c */
if(!s->budget--) { s->failed_pc=0x0c07e13cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07e13e;
P_0c07e13e: /* original 60d3, guest PC 0x0c07e13e */
if(!s->budget--) { s->failed_pc=0x0c07e13eu; return 0; }
r[0]=r[13];
goto P_0c07e140;
P_0c07e140: /* original 8830, guest PC 0x0c07e140 */
if(!s->budget--) { s->failed_pc=0x0c07e140u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000030u)!=0);
goto P_0c07e142;
P_0c07e142: /* original 075a, guest PC 0x0c07e142 */
if(!s->budget--) { s->failed_pc=0x0c07e142u; return 0; }
r[7]=r[53];
goto P_0c07e144;
P_0c07e144: /* original f43d, guest PC 0x0c07e144 */
if(!s->budget--) { s->failed_pc=0x0c07e144u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c07e146;
P_0c07e146: /* original 27c9, guest PC 0x0c07e146 */
if(!s->budget--) { s->failed_pc=0x0c07e146u; return 0; }
r[7]&=r[12];
goto P_0c07e148;
P_0c07e148: /* original 045a, guest PC 0x0c07e148 */
if(!s->budget--) { s->failed_pc=0x0c07e148u; return 0; }
r[4]=r[53];
goto P_0c07e14a;
P_0c07e14a: /* original 24c9, guest PC 0x0c07e14a */
if(!s->budget--) { s->failed_pc=0x0c07e14au; return 0; }
r[4]&=r[12];
goto P_0c07e14c;
P_0c07e14c: /* original 4428, guest PC 0x0c07e14c */
if(!s->budget--) { s->failed_pc=0x0c07e14cu; return 0; }
r[4]<<=16;
goto P_0c07e14e;
P_0c07e14e: /* original 274b, guest PC 0x0c07e14e */
if(!s->budget--) { s->failed_pc=0x0c07e14eu; return 0; }
r[7]|=r[4];
goto P_0c07e150;
P_0c07e150: /* original 9421, guest PC 0x0c07e150 */
if(!s->budget--) { s->failed_pc=0x0c07e150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e196u,2);
goto P_0c07e152;
P_0c07e152: /* original 8f01, guest PC 0x0c07e152 */
if(!s->budget--) { s->failed_pc=0x0c07e152u; return 0; }
cond=r[17]&1u;
r[2]=r[13];
if(!cond) { goto P_0c07e158; }
goto P_0c07e156;
P_0c07e154: /* original 62d3, guest PC 0x0c07e154 */
if(!s->budget--) { s->failed_pc=0x0c07e154u; return 0; }
r[2]=r[13];
goto P_0c07e156;
P_0c07e156: /* original 941f, guest PC 0x0c07e156 */
if(!s->budget--) { s->failed_pc=0x0c07e156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e198u,2);
goto P_0c07e158;
P_0c07e158: /* original 4228, guest PC 0x0c07e158 */
if(!s->budget--) { s->failed_pc=0x0c07e158u; return 0; }
r[2]<<=16;
goto P_0c07e15a;
P_0c07e15a: /* original 6693, guest PC 0x0c07e15a */
if(!s->budget--) { s->failed_pc=0x0c07e15au; return 0; }
r[6]=r[9];
goto P_0c07e15c;
P_0c07e15c: /* original 4218, guest PC 0x0c07e15c */
if(!s->budget--) { s->failed_pc=0x0c07e15cu; return 0; }
r[2]<<=8;
goto P_0c07e15e;
P_0c07e15e: /* original e341, guest PC 0x0c07e15e */
if(!s->budget--) { s->failed_pc=0x0c07e15eu; return 0; }
r[3]=0x00000041u;
goto P_0c07e160;
P_0c07e160: /* original 22bb, guest PC 0x0c07e160 */
if(!s->budget--) { s->failed_pc=0x0c07e160u; return 0; }
r[2]|=r[11];
goto P_0c07e162;
P_0c07e162: /* original 2f36, guest PC 0x0c07e162 */
if(!s->budget--) { s->failed_pc=0x0c07e162u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e164;
P_0c07e164: /* original 242b, guest PC 0x0c07e164 */
if(!s->budget--) { s->failed_pc=0x0c07e164u; return 0; }
r[4]|=r[2];
goto P_0c07e166;
P_0c07e166: /* original 2f46, guest PC 0x0c07e166 */
if(!s->budget--) { s->failed_pc=0x0c07e166u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e168;
P_0c07e168: /* original d215, guest PC 0x0c07e168 */
if(!s->budget--) { s->failed_pc=0x0c07e168u; return 0; }
r[2]=read(ram,0x0c07e1c0u,4);
goto P_0c07e16a;
P_0c07e16a: /* original 55f3, guest PC 0x0c07e16a */
if(!s->budget--) { s->failed_pc=0x0c07e16au; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07e16c;
P_0c07e16c: /* original 420b, guest PC 0x0c07e16c */
if(!s->budget--) { s->failed_pc=0x0c07e16cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07e170u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e170u) { target=s->pc; goto dispatch; }
goto P_0c07e170;
P_0c07e16e: /* original 54f2, guest PC 0x0c07e16e */
if(!s->budget--) { s->failed_pc=0x0c07e16eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07e170;
P_0c07e170: /* original 4a10, guest PC 0x0c07e170 */
if(!s->budget--) { s->failed_pc=0x0c07e170u; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c07e172;
P_0c07e172: /* original 7e10, guest PC 0x0c07e172 */
if(!s->budget--) { s->failed_pc=0x0c07e172u; return 0; }
r[14]+=0x00000010u;
goto P_0c07e174;
P_0c07e174: /* original 7f08, guest PC 0x0c07e174 */
if(!s->budget--) { s->failed_pc=0x0c07e174u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e176;
P_0c07e176: /* original 8fd5, guest PC 0x0c07e176 */
if(!s->budget--) { s->failed_pc=0x0c07e176u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000010u;
if(!cond) { goto P_0c07e124; }
goto P_0c07e17a;
P_0c07e178: /* original 7d10, guest PC 0x0c07e178 */
if(!s->budget--) { s->failed_pc=0x0c07e178u; return 0; }
r[13]+=0x00000010u;
goto P_0c07e17a;
P_0c07e17a: /* original d212, guest PC 0x0c07e17a */
if(!s->budget--) { s->failed_pc=0x0c07e17au; return 0; }
r[2]=read(ram,0x0c07e1c4u,4);
goto P_0c07e17c;
P_0c07e17c: /* original 4810, guest PC 0x0c07e17c */
if(!s->budget--) { s->failed_pc=0x0c07e17cu; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c07e17e;
P_0c07e17e: /* original 8fcf, guest PC 0x0c07e17e */
if(!s->budget--) { s->failed_pc=0x0c07e17eu; return 0; }
cond=r[17]&1u;
r[11]+=r[2];
if(!cond) { goto P_0c07e120; }
goto P_0c07e182;
P_0c07e180: /* original 3b2c, guest PC 0x0c07e180 */
if(!s->budget--) { s->failed_pc=0x0c07e180u; return 0; }
r[11]+=r[2];
goto P_0c07e182;
P_0c07e182: /* original 7f08, guest PC 0x0c07e182 */
if(!s->budget--) { s->failed_pc=0x0c07e182u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e184;
P_0c07e184: /* original 4f26, guest PC 0x0c07e184 */
if(!s->budget--) { s->failed_pc=0x0c07e184u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e186;
P_0c07e186: /* original 68f6, guest PC 0x0c07e186 */
if(!s->budget--) { s->failed_pc=0x0c07e186u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07e188;
P_0c07e188: /* original 69f6, guest PC 0x0c07e188 */
if(!s->budget--) { s->failed_pc=0x0c07e188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07e18a;
P_0c07e18a: /* original 6af6, guest PC 0x0c07e18a */
if(!s->budget--) { s->failed_pc=0x0c07e18au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07e18c;
P_0c07e18c: /* original 6bf6, guest PC 0x0c07e18c */
if(!s->budget--) { s->failed_pc=0x0c07e18cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07e18e;
P_0c07e18e: /* original 6cf6, guest PC 0x0c07e18e */
if(!s->budget--) { s->failed_pc=0x0c07e18eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07e190;
P_0c07e190: /* original 6df6, guest PC 0x0c07e190 */
if(!s->budget--) { s->failed_pc=0x0c07e190u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07e192;
P_0c07e192: /* original 000b, guest PC 0x0c07e192 */
if(!s->budget--) { s->failed_pc=0x0c07e192u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07e194: /* original 6ef6, guest PC 0x0c07e194 */
if(!s->budget--) { s->failed_pc=0x0c07e194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07e196u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e196u; return 0; } return 1;
P_0c07e284: /* original 2fe6, guest PC 0x0c07e284 */
if(!s->budget--) { s->failed_pc=0x0c07e284u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e286;
P_0c07e286: /* original 2fd6, guest PC 0x0c07e286 */
if(!s->budget--) { s->failed_pc=0x0c07e286u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e288;
P_0c07e288: /* original 2fc6, guest PC 0x0c07e288 */
if(!s->budget--) { s->failed_pc=0x0c07e288u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e28a;
P_0c07e28a: /* original 2fb6, guest PC 0x0c07e28a */
if(!s->budget--) { s->failed_pc=0x0c07e28au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e28c;
P_0c07e28c: /* original 2fa6, guest PC 0x0c07e28c */
if(!s->budget--) { s->failed_pc=0x0c07e28cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e28e;
P_0c07e28e: /* original 2f96, guest PC 0x0c07e28e */
if(!s->budget--) { s->failed_pc=0x0c07e28eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e290;
P_0c07e290: /* original 2f86, guest PC 0x0c07e290 */
if(!s->budget--) { s->failed_pc=0x0c07e290u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e292;
P_0c07e292: /* original fffb, guest PC 0x0c07e292 */
if(!s->budget--) { s->failed_pc=0x0c07e292u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07e294;
P_0c07e294: /* original 4f22, guest PC 0x0c07e294 */
if(!s->budget--) { s->failed_pc=0x0c07e294u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e296;
P_0c07e296: /* original 7ff8, guest PC 0x0c07e296 */
if(!s->budget--) { s->failed_pc=0x0c07e296u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e298;
P_0c07e298: /* original 2f42, guest PC 0x0c07e298 */
if(!s->budget--) { s->failed_pc=0x0c07e298u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07e29a;
P_0c07e29a: /* original 1f51, guest PC 0x0c07e29a */
if(!s->budget--) { s->failed_pc=0x0c07e29au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07e29c;
P_0c07e29c: /* original d35e, guest PC 0x0c07e29c */
if(!s->budget--) { s->failed_pc=0x0c07e29cu; return 0; }
r[3]=read(ram,0x0c07e418u,4);
goto P_0c07e29e;
P_0c07e29e: /* original d45a, guest PC 0x0c07e29e */
if(!s->budget--) { s->failed_pc=0x0c07e29eu; return 0; }
r[4]=read(ram,0x0c07e408u,4);
goto P_0c07e2a0;
P_0c07e2a0: /* original 6032, guest PC 0x0c07e2a0 */
if(!s->budget--) { s->failed_pc=0x0c07e2a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07e2a2;
P_0c07e2a2: /* original 5142, guest PC 0x0c07e2a2 */
if(!s->budget--) { s->failed_pc=0x0c07e2a2u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c07e2a4;
P_0c07e2a4: /* original d25d, guest PC 0x0c07e2a4 */
if(!s->budget--) { s->failed_pc=0x0c07e2a4u; return 0; }
r[2]=read(ram,0x0c07e41cu,4);
goto P_0c07e2a6;
P_0c07e2a6: /* original c901, guest PC 0x0c07e2a6 */
if(!s->budget--) { s->failed_pc=0x0c07e2a6u; return 0; }
r[0]&=1u;
goto P_0c07e2a8;
P_0c07e2a8: /* original de58, guest PC 0x0c07e2a8 */
if(!s->budget--) { s->failed_pc=0x0c07e2a8u; return 0; }
r[14]=read(ram,0x0c07e40cu,4);
goto P_0c07e2aa;
P_0c07e2aa: /* original 6603, guest PC 0x0c07e2aa */
if(!s->budget--) { s->failed_pc=0x0c07e2aau; return 0; }
r[6]=r[0];
goto P_0c07e2ac;
P_0c07e2ac: /* original d559, guest PC 0x0c07e2ac */
if(!s->budget--) { s->failed_pc=0x0c07e2acu; return 0; }
r[5]=read(ram,0x0c07e414u,4);
goto P_0c07e2ae;
P_0c07e2ae: /* original 2128, guest PC 0x0c07e2ae */
if(!s->budget--) { s->failed_pc=0x0c07e2aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c07e2b0;
P_0c07e2b0: /* original db57, guest PC 0x0c07e2b0 */
if(!s->budget--) { s->failed_pc=0x0c07e2b0u; return 0; }
r[11]=read(ram,0x0c07e410u,4);
goto P_0c07e2b2;
P_0c07e2b2: /* original 8b01, guest PC 0x0c07e2b2 */
if(!s->budget--) { s->failed_pc=0x0c07e2b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07e2b8; }
goto P_0c07e2b4;
P_0c07e2b4: /* original a26b, guest PC 0x0c07e2b4 */
if(!s->budget--) { s->failed_pc=0x0c07e2b4u; return 0; }
goto P_0c07e78e;
P_0c07e2b6: /* original 0009, guest PC 0x0c07e2b6 */
if(!s->budget--) { s->failed_pc=0x0c07e2b6u; return 0; }
goto P_0c07e2b8;
P_0c07e2b8: /* original 2668, guest PC 0x0c07e2b8 */
if(!s->budget--) { s->failed_pc=0x0c07e2b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c07e2ba;
P_0c07e2ba: /* original 8f02, guest PC 0x0c07e2ba */
if(!s->budget--) { s->failed_pc=0x0c07e2bau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c07e2c2; }
goto P_0c07e2be;
P_0c07e2bc: /* original ec00, guest PC 0x0c07e2bc */
if(!s->budget--) { s->failed_pc=0x0c07e2bcu; return 0; }
r[12]=0x00000000u;
goto P_0c07e2be;
P_0c07e2be: /* original a25c, guest PC 0x0c07e2be */
if(!s->budget--) { s->failed_pc=0x0c07e2beu; return 0; }
goto P_0c07e77a;
P_0c07e2c0: /* original 0009, guest PC 0x0c07e2c0 */
if(!s->budget--) { s->failed_pc=0x0c07e2c0u; return 0; }
goto P_0c07e2c2;
P_0c07e2c2: /* original 6d53, guest PC 0x0c07e2c2 */
if(!s->budget--) { s->failed_pc=0x0c07e2c2u; return 0; }
r[13]=r[5];
goto P_0c07e2c4;
P_0c07e2c4: /* original e126, guest PC 0x0c07e2c4 */
if(!s->budget--) { s->failed_pc=0x0c07e2c4u; return 0; }
r[1]=0x00000026u;
goto P_0c07e2c6;
P_0c07e2c6: /* original 7d2c, guest PC 0x0c07e2c6 */
if(!s->budget--) { s->failed_pc=0x0c07e2c6u; return 0; }
r[13]+=0x0000002cu;
goto P_0c07e2c8;
P_0c07e2c8: /* original 31dc, guest PC 0x0c07e2c8 */
if(!s->budget--) { s->failed_pc=0x0c07e2c8u; return 0; }
r[1]+=r[13];
goto P_0c07e2ca;
P_0c07e2ca: /* original e009, guest PC 0x0c07e2ca */
if(!s->budget--) { s->failed_pc=0x0c07e2cau; return 0; }
r[0]=0x00000009u;
goto P_0c07e2cc;
P_0c07e2cc: /* original 2101, guest PC 0x0c07e2cc */
if(!s->budget--) { s->failed_pc=0x0c07e2ccu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c07e2ce;
P_0c07e2ce: /* original e022, guest PC 0x0c07e2ce */
if(!s->budget--) { s->failed_pc=0x0c07e2ceu; return 0; }
r[0]=0x00000022u;
goto P_0c07e2d0;
P_0c07e2d0: /* original 03dd, guest PC 0x0c07e2d0 */
if(!s->budget--) { s->failed_pc=0x0c07e2d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07e2d2;
P_0c07e2d2: /* original e102, guest PC 0x0c07e2d2 */
if(!s->budget--) { s->failed_pc=0x0c07e2d2u; return 0; }
r[1]=0x00000002u;
goto P_0c07e2d4;
P_0c07e2d4: /* original e553, guest PC 0x0c07e2d4 */
if(!s->budget--) { s->failed_pc=0x0c07e2d4u; return 0; }
r[5]=0x00000053u;
goto P_0c07e2d6;
P_0c07e2d6: /* original 231b, guest PC 0x0c07e2d6 */
if(!s->budget--) { s->failed_pc=0x0c07e2d6u; return 0; }
r[3]|=r[1];
goto P_0c07e2d8;
P_0c07e2d8: /* original 0d35, guest PC 0x0c07e2d8 */
if(!s->budget--) { s->failed_pc=0x0c07e2d8u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07e2da;
P_0c07e2da: /* original 4b0b, guest PC 0x0c07e2da */
if(!s->budget--) { s->failed_pc=0x0c07e2dau; return 0; }
target=r[11];
r[16]=code_base|0x0c07e2deu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e2deu) { target=s->pc; goto dispatch; }
goto P_0c07e2de;
P_0c07e2dc: /* original 64d3, guest PC 0x0c07e2dc */
if(!s->budget--) { s->failed_pc=0x0c07e2dcu; return 0; }
r[4]=r[13];
goto P_0c07e2de;
P_0c07e2de: /* original ea20, guest PC 0x0c07e2de */
if(!s->budget--) { s->failed_pc=0x0c07e2deu; return 0; }
r[10]=0x00000020u;
goto P_0c07e2e0;
P_0c07e2e0: /* original db4f, guest PC 0x0c07e2e0 */
if(!s->budget--) { s->failed_pc=0x0c07e2e0u; return 0; }
r[11]=read(ram,0x0c07e420u,4);
goto P_0c07e2e2;
P_0c07e2e2: /* original 2fa6, guest PC 0x0c07e2e2 */
if(!s->budget--) { s->failed_pc=0x0c07e2e2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e2e4;
P_0c07e2e4: /* original e700, guest PC 0x0c07e2e4 */
if(!s->budget--) { s->failed_pc=0x0c07e2e4u; return 0; }
r[7]=0x00000000u;
goto P_0c07e2e6;
P_0c07e2e6: /* original 2fc6, guest PC 0x0c07e2e6 */
if(!s->budget--) { s->failed_pc=0x0c07e2e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e2e8;
P_0c07e2e8: /* original 9475, guest PC 0x0c07e2e8 */
if(!s->budget--) { s->failed_pc=0x0c07e2e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3d6u,2);
goto P_0c07e2ea;
P_0c07e2ea: /* original 9573, guest PC 0x0c07e2ea */
if(!s->budget--) { s->failed_pc=0x0c07e2eau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3d4u,2);
goto P_0c07e2ec;
P_0c07e2ec: /* original 4b0b, guest PC 0x0c07e2ec */
if(!s->budget--) { s->failed_pc=0x0c07e2ecu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e2f0u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e2f0u) { target=s->pc; goto dispatch; }
goto P_0c07e2f0;
P_0c07e2ee: /* original 66d3, guest PC 0x0c07e2ee */
if(!s->budget--) { s->failed_pc=0x0c07e2eeu; return 0; }
r[6]=r[13];
goto P_0c07e2f0;
P_0c07e2f0: /* original 2fa6, guest PC 0x0c07e2f0 */
if(!s->budget--) { s->failed_pc=0x0c07e2f0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e2f2;
P_0c07e2f2: /* original e700, guest PC 0x0c07e2f2 */
if(!s->budget--) { s->failed_pc=0x0c07e2f2u; return 0; }
r[7]=0x00000000u;
goto P_0c07e2f4;
P_0c07e2f4: /* original 2fc6, guest PC 0x0c07e2f4 */
if(!s->budget--) { s->failed_pc=0x0c07e2f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e2f6;
P_0c07e2f6: /* original 956f, guest PC 0x0c07e2f6 */
if(!s->budget--) { s->failed_pc=0x0c07e2f6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3d8u,2);
goto P_0c07e2f8;
P_0c07e2f8: /* original 946f, guest PC 0x0c07e2f8 */
if(!s->budget--) { s->failed_pc=0x0c07e2f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3dau,2);
goto P_0c07e2fa;
P_0c07e2fa: /* original 4b0b, guest PC 0x0c07e2fa */
if(!s->budget--) { s->failed_pc=0x0c07e2fau; return 0; }
target=r[11];
r[16]=code_base|0x0c07e2feu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e2feu) { target=s->pc; goto dispatch; }
goto P_0c07e2fe;
P_0c07e2fc: /* original 66d3, guest PC 0x0c07e2fc */
if(!s->budget--) { s->failed_pc=0x0c07e2fcu; return 0; }
r[6]=r[13];
goto P_0c07e2fe;
P_0c07e2fe: /* original 2fa6, guest PC 0x0c07e2fe */
if(!s->budget--) { s->failed_pc=0x0c07e2feu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e300;
P_0c07e300: /* original e700, guest PC 0x0c07e300 */
if(!s->budget--) { s->failed_pc=0x0c07e300u; return 0; }
r[7]=0x00000000u;
goto P_0c07e302;
P_0c07e302: /* original 2fc6, guest PC 0x0c07e302 */
if(!s->budget--) { s->failed_pc=0x0c07e302u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e304;
P_0c07e304: /* original 956a, guest PC 0x0c07e304 */
if(!s->budget--) { s->failed_pc=0x0c07e304u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3dcu,2);
goto P_0c07e306;
P_0c07e306: /* original 946a, guest PC 0x0c07e306 */
if(!s->budget--) { s->failed_pc=0x0c07e306u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3deu,2);
goto P_0c07e308;
P_0c07e308: /* original 4b0b, guest PC 0x0c07e308 */
if(!s->budget--) { s->failed_pc=0x0c07e308u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e30cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e30cu) { target=s->pc; goto dispatch; }
goto P_0c07e30c;
P_0c07e30a: /* original 66d3, guest PC 0x0c07e30a */
if(!s->budget--) { s->failed_pc=0x0c07e30au; return 0; }
r[6]=r[13];
goto P_0c07e30c;
P_0c07e30c: /* original 2fa6, guest PC 0x0c07e30c */
if(!s->budget--) { s->failed_pc=0x0c07e30cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e30e;
P_0c07e30e: /* original e700, guest PC 0x0c07e30e */
if(!s->budget--) { s->failed_pc=0x0c07e30eu; return 0; }
r[7]=0x00000000u;
goto P_0c07e310;
P_0c07e310: /* original 2fc6, guest PC 0x0c07e310 */
if(!s->budget--) { s->failed_pc=0x0c07e310u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e312;
P_0c07e312: /* original 9565, guest PC 0x0c07e312 */
if(!s->budget--) { s->failed_pc=0x0c07e312u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e0u,2);
goto P_0c07e314;
P_0c07e314: /* original 9465, guest PC 0x0c07e314 */
if(!s->budget--) { s->failed_pc=0x0c07e314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e2u,2);
goto P_0c07e316;
P_0c07e316: /* original 4b0b, guest PC 0x0c07e316 */
if(!s->budget--) { s->failed_pc=0x0c07e316u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e31au;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e31au) { target=s->pc; goto dispatch; }
goto P_0c07e31a;
P_0c07e318: /* original 66d3, guest PC 0x0c07e318 */
if(!s->budget--) { s->failed_pc=0x0c07e318u; return 0; }
r[6]=r[13];
goto P_0c07e31a;
P_0c07e31a: /* original 2fa6, guest PC 0x0c07e31a */
if(!s->budget--) { s->failed_pc=0x0c07e31au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e31c;
P_0c07e31c: /* original e700, guest PC 0x0c07e31c */
if(!s->budget--) { s->failed_pc=0x0c07e31cu; return 0; }
r[7]=0x00000000u;
goto P_0c07e31e;
P_0c07e31e: /* original 2fc6, guest PC 0x0c07e31e */
if(!s->budget--) { s->failed_pc=0x0c07e31eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e320;
P_0c07e320: /* original 9560, guest PC 0x0c07e320 */
if(!s->budget--) { s->failed_pc=0x0c07e320u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e4u,2);
goto P_0c07e322;
P_0c07e322: /* original 9460, guest PC 0x0c07e322 */
if(!s->budget--) { s->failed_pc=0x0c07e322u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e6u,2);
goto P_0c07e324;
P_0c07e324: /* original 4b0b, guest PC 0x0c07e324 */
if(!s->budget--) { s->failed_pc=0x0c07e324u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e328u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e328u) { target=s->pc; goto dispatch; }
goto P_0c07e328;
P_0c07e326: /* original 66d3, guest PC 0x0c07e326 */
if(!s->budget--) { s->failed_pc=0x0c07e326u; return 0; }
r[6]=r[13];
goto P_0c07e328;
P_0c07e328: /* original 2fa6, guest PC 0x0c07e328 */
if(!s->budget--) { s->failed_pc=0x0c07e328u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e32a;
P_0c07e32a: /* original e700, guest PC 0x0c07e32a */
if(!s->budget--) { s->failed_pc=0x0c07e32au; return 0; }
r[7]=0x00000000u;
goto P_0c07e32c;
P_0c07e32c: /* original 2fc6, guest PC 0x0c07e32c */
if(!s->budget--) { s->failed_pc=0x0c07e32cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e32e;
P_0c07e32e: /* original 955b, guest PC 0x0c07e32e */
if(!s->budget--) { s->failed_pc=0x0c07e32eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e8u,2);
goto P_0c07e330;
P_0c07e330: /* original 945b, guest PC 0x0c07e330 */
if(!s->budget--) { s->failed_pc=0x0c07e330u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3eau,2);
goto P_0c07e332;
P_0c07e332: /* original 4b0b, guest PC 0x0c07e332 */
if(!s->budget--) { s->failed_pc=0x0c07e332u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e336u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e336u) { target=s->pc; goto dispatch; }
goto P_0c07e336;
P_0c07e334: /* original 66d3, guest PC 0x0c07e334 */
if(!s->budget--) { s->failed_pc=0x0c07e334u; return 0; }
r[6]=r[13];
goto P_0c07e336;
P_0c07e336: /* original 2fa6, guest PC 0x0c07e336 */
if(!s->budget--) { s->failed_pc=0x0c07e336u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e338;
P_0c07e338: /* original e700, guest PC 0x0c07e338 */
if(!s->budget--) { s->failed_pc=0x0c07e338u; return 0; }
r[7]=0x00000000u;
goto P_0c07e33a;
P_0c07e33a: /* original 2fc6, guest PC 0x0c07e33a */
if(!s->budget--) { s->failed_pc=0x0c07e33au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e33c;
P_0c07e33c: /* original 9556, guest PC 0x0c07e33c */
if(!s->budget--) { s->failed_pc=0x0c07e33cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3ecu,2);
goto P_0c07e33e;
P_0c07e33e: /* original 9456, guest PC 0x0c07e33e */
if(!s->budget--) { s->failed_pc=0x0c07e33eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3eeu,2);
goto P_0c07e340;
P_0c07e340: /* original 4b0b, guest PC 0x0c07e340 */
if(!s->budget--) { s->failed_pc=0x0c07e340u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e344u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e344u) { target=s->pc; goto dispatch; }
goto P_0c07e344;
P_0c07e342: /* original 66d3, guest PC 0x0c07e342 */
if(!s->budget--) { s->failed_pc=0x0c07e342u; return 0; }
r[6]=r[13];
goto P_0c07e344;
P_0c07e344: /* original 2fa6, guest PC 0x0c07e344 */
if(!s->budget--) { s->failed_pc=0x0c07e344u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e346;
P_0c07e346: /* original e700, guest PC 0x0c07e346 */
if(!s->budget--) { s->failed_pc=0x0c07e346u; return 0; }
r[7]=0x00000000u;
goto P_0c07e348;
P_0c07e348: /* original 2fc6, guest PC 0x0c07e348 */
if(!s->budget--) { s->failed_pc=0x0c07e348u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e34a;
P_0c07e34a: /* original 9545, guest PC 0x0c07e34a */
if(!s->budget--) { s->failed_pc=0x0c07e34au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3d8u,2);
goto P_0c07e34c;
P_0c07e34c: /* original 9450, guest PC 0x0c07e34c */
if(!s->budget--) { s->failed_pc=0x0c07e34cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3f0u,2);
goto P_0c07e34e;
P_0c07e34e: /* original 4b0b, guest PC 0x0c07e34e */
if(!s->budget--) { s->failed_pc=0x0c07e34eu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e352u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e352u) { target=s->pc; goto dispatch; }
goto P_0c07e352;
P_0c07e350: /* original 66d3, guest PC 0x0c07e350 */
if(!s->budget--) { s->failed_pc=0x0c07e350u; return 0; }
r[6]=r[13];
goto P_0c07e352;
P_0c07e352: /* original 2fa6, guest PC 0x0c07e352 */
if(!s->budget--) { s->failed_pc=0x0c07e352u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e354;
P_0c07e354: /* original e700, guest PC 0x0c07e354 */
if(!s->budget--) { s->failed_pc=0x0c07e354u; return 0; }
r[7]=0x00000000u;
goto P_0c07e356;
P_0c07e356: /* original 2fc6, guest PC 0x0c07e356 */
if(!s->budget--) { s->failed_pc=0x0c07e356u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e358;
P_0c07e358: /* original 954b, guest PC 0x0c07e358 */
if(!s->budget--) { s->failed_pc=0x0c07e358u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3f2u,2);
goto P_0c07e35a;
P_0c07e35a: /* original 944b, guest PC 0x0c07e35a */
if(!s->budget--) { s->failed_pc=0x0c07e35au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3f4u,2);
goto P_0c07e35c;
P_0c07e35c: /* original 4b0b, guest PC 0x0c07e35c */
if(!s->budget--) { s->failed_pc=0x0c07e35cu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e360u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e360u) { target=s->pc; goto dispatch; }
goto P_0c07e360;
P_0c07e35e: /* original 66d3, guest PC 0x0c07e35e */
if(!s->budget--) { s->failed_pc=0x0c07e35eu; return 0; }
r[6]=r[13];
goto P_0c07e360;
P_0c07e360: /* original 2fa6, guest PC 0x0c07e360 */
if(!s->budget--) { s->failed_pc=0x0c07e360u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e362;
P_0c07e362: /* original e700, guest PC 0x0c07e362 */
if(!s->budget--) { s->failed_pc=0x0c07e362u; return 0; }
r[7]=0x00000000u;
goto P_0c07e364;
P_0c07e364: /* original 2fc6, guest PC 0x0c07e364 */
if(!s->budget--) { s->failed_pc=0x0c07e364u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e366;
P_0c07e366: /* original 953b, guest PC 0x0c07e366 */
if(!s->budget--) { s->failed_pc=0x0c07e366u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3e0u,2);
goto P_0c07e368;
P_0c07e368: /* original 9445, guest PC 0x0c07e368 */
if(!s->budget--) { s->failed_pc=0x0c07e368u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3f6u,2);
goto P_0c07e36a;
P_0c07e36a: /* original 4b0b, guest PC 0x0c07e36a */
if(!s->budget--) { s->failed_pc=0x0c07e36au; return 0; }
target=r[11];
r[16]=code_base|0x0c07e36eu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e36eu) { target=s->pc; goto dispatch; }
goto P_0c07e36e;
P_0c07e36c: /* original 66d3, guest PC 0x0c07e36c */
if(!s->budget--) { s->failed_pc=0x0c07e36cu; return 0; }
r[6]=r[13];
goto P_0c07e36e;
P_0c07e36e: /* original 2fa6, guest PC 0x0c07e36e */
if(!s->budget--) { s->failed_pc=0x0c07e36eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e370;
P_0c07e370: /* original e700, guest PC 0x0c07e370 */
if(!s->budget--) { s->failed_pc=0x0c07e370u; return 0; }
r[7]=0x00000000u;
goto P_0c07e372;
P_0c07e372: /* original 2fc6, guest PC 0x0c07e372 */
if(!s->budget--) { s->failed_pc=0x0c07e372u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e374;
P_0c07e374: /* original 9540, guest PC 0x0c07e374 */
if(!s->budget--) { s->failed_pc=0x0c07e374u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3f8u,2);
goto P_0c07e376;
P_0c07e376: /* original 9440, guest PC 0x0c07e376 */
if(!s->budget--) { s->failed_pc=0x0c07e376u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3fau,2);
goto P_0c07e378;
P_0c07e378: /* original 4b0b, guest PC 0x0c07e378 */
if(!s->budget--) { s->failed_pc=0x0c07e378u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e37cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e37cu) { target=s->pc; goto dispatch; }
goto P_0c07e37c;
P_0c07e37a: /* original 66d3, guest PC 0x0c07e37a */
if(!s->budget--) { s->failed_pc=0x0c07e37au; return 0; }
r[6]=r[13];
goto P_0c07e37c;
P_0c07e37c: /* original 6403, guest PC 0x0c07e37c */
if(!s->budget--) { s->failed_pc=0x0c07e37cu; return 0; }
r[4]=r[0];
goto P_0c07e37e;
P_0c07e37e: /* original 903d, guest PC 0x0c07e37e */
if(!s->budget--) { s->failed_pc=0x0c07e37eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3fcu,2);
goto P_0c07e380;
P_0c07e380: /* original d928, guest PC 0x0c07e380 */
if(!s->budget--) { s->failed_pc=0x0c07e380u; return 0; }
r[9]=read(ram,0x0c07e424u,4);
goto P_0c07e382;
P_0c07e382: /* original e700, guest PC 0x0c07e382 */
if(!s->budget--) { s->failed_pc=0x0c07e382u; return 0; }
r[7]=0x00000000u;
goto P_0c07e384;
P_0c07e384: /* original 02ec, guest PC 0x0c07e384 */
if(!s->budget--) { s->failed_pc=0x0c07e384u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e386;
P_0c07e386: /* original e030, guest PC 0x0c07e386 */
if(!s->budget--) { s->failed_pc=0x0c07e386u; return 0; }
r[0]=0x00000030u;
goto P_0c07e388;
P_0c07e388: /* original 4208, guest PC 0x0c07e388 */
if(!s->budget--) { s->failed_pc=0x0c07e388u; return 0; }
r[2]<<=2;
goto P_0c07e38a;
P_0c07e38a: /* original 4208, guest PC 0x0c07e38a */
if(!s->budget--) { s->failed_pc=0x0c07e38au; return 0; }
r[2]<<=2;
goto P_0c07e38c;
P_0c07e38c: /* original 329c, guest PC 0x0c07e38c */
if(!s->budget--) { s->failed_pc=0x0c07e38cu; return 0; }
r[2]+=r[9];
goto P_0c07e38e;
P_0c07e38e: /* original f328, guest PC 0x0c07e38e */
if(!s->budget--) { s->failed_pc=0x0c07e38eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07e390;
P_0c07e390: /* original f437, guest PC 0x0c07e390 */
if(!s->budget--) { s->failed_pc=0x0c07e390u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e392;
P_0c07e392: /* original 2fa6, guest PC 0x0c07e392 */
if(!s->budget--) { s->failed_pc=0x0c07e392u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e394;
P_0c07e394: /* original 2fc6, guest PC 0x0c07e394 */
if(!s->budget--) { s->failed_pc=0x0c07e394u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e396;
P_0c07e396: /* original 9532, guest PC 0x0c07e396 */
if(!s->budget--) { s->failed_pc=0x0c07e396u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3feu,2);
goto P_0c07e398;
P_0c07e398: /* original 9432, guest PC 0x0c07e398 */
if(!s->budget--) { s->failed_pc=0x0c07e398u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e400u,2);
goto P_0c07e39a;
P_0c07e39a: /* original 4b0b, guest PC 0x0c07e39a */
if(!s->budget--) { s->failed_pc=0x0c07e39au; return 0; }
target=r[11];
r[16]=code_base|0x0c07e39eu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e39eu) { target=s->pc; goto dispatch; }
goto P_0c07e39e;
P_0c07e39c: /* original 66d3, guest PC 0x0c07e39c */
if(!s->budget--) { s->failed_pc=0x0c07e39cu; return 0; }
r[6]=r[13];
goto P_0c07e39e;
P_0c07e39e: /* original 6403, guest PC 0x0c07e39e */
if(!s->budget--) { s->failed_pc=0x0c07e39eu; return 0; }
r[4]=r[0];
goto P_0c07e3a0;
P_0c07e3a0: /* original 902c, guest PC 0x0c07e3a0 */
if(!s->budget--) { s->failed_pc=0x0c07e3a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e3fcu,2);
goto P_0c07e3a2;
P_0c07e3a2: /* original e700, guest PC 0x0c07e3a2 */
if(!s->budget--) { s->failed_pc=0x0c07e3a2u; return 0; }
r[7]=0x00000000u;
goto P_0c07e3a4;
P_0c07e3a4: /* original 03ec, guest PC 0x0c07e3a4 */
if(!s->budget--) { s->failed_pc=0x0c07e3a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e3a6;
P_0c07e3a6: /* original e004, guest PC 0x0c07e3a6 */
if(!s->budget--) { s->failed_pc=0x0c07e3a6u; return 0; }
r[0]=0x00000004u;
goto P_0c07e3a8;
P_0c07e3a8: /* original 4308, guest PC 0x0c07e3a8 */
if(!s->budget--) { s->failed_pc=0x0c07e3a8u; return 0; }
r[3]<<=2;
goto P_0c07e3aa;
P_0c07e3aa: /* original 4308, guest PC 0x0c07e3aa */
if(!s->budget--) { s->failed_pc=0x0c07e3aau; return 0; }
r[3]<<=2;
goto P_0c07e3ac;
P_0c07e3ac: /* original 339c, guest PC 0x0c07e3ac */
if(!s->budget--) { s->failed_pc=0x0c07e3acu; return 0; }
r[3]+=r[9];
goto P_0c07e3ae;
P_0c07e3ae: /* original f336, guest PC 0x0c07e3ae */
if(!s->budget--) { s->failed_pc=0x0c07e3aeu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c07e3b0;
P_0c07e3b0: /* original e030, guest PC 0x0c07e3b0 */
if(!s->budget--) { s->failed_pc=0x0c07e3b0u; return 0; }
r[0]=0x00000030u;
goto P_0c07e3b2;
P_0c07e3b2: /* original f437, guest PC 0x0c07e3b2 */
if(!s->budget--) { s->failed_pc=0x0c07e3b2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e3b4;
P_0c07e3b4: /* original 2fa6, guest PC 0x0c07e3b4 */
if(!s->budget--) { s->failed_pc=0x0c07e3b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e3b6;
P_0c07e3b6: /* original 2fc6, guest PC 0x0c07e3b6 */
if(!s->budget--) { s->failed_pc=0x0c07e3b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e3b8;
P_0c07e3b8: /* original 9523, guest PC 0x0c07e3b8 */
if(!s->budget--) { s->failed_pc=0x0c07e3b8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e402u,2);
goto P_0c07e3ba;
P_0c07e3ba: /* original 9423, guest PC 0x0c07e3ba */
if(!s->budget--) { s->failed_pc=0x0c07e3bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e404u,2);
goto P_0c07e3bc;
P_0c07e3bc: /* original 4b0b, guest PC 0x0c07e3bc */
if(!s->budget--) { s->failed_pc=0x0c07e3bcu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e3c0u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e3c0u) { target=s->pc; goto dispatch; }
goto P_0c07e3c0;
P_0c07e3be: /* original 66d3, guest PC 0x0c07e3be */
if(!s->budget--) { s->failed_pc=0x0c07e3beu; return 0; }
r[6]=r[13];
goto P_0c07e3c0;
P_0c07e3c0: /* original 6403, guest PC 0x0c07e3c0 */
if(!s->budget--) { s->failed_pc=0x0c07e3c0u; return 0; }
r[4]=r[0];
goto P_0c07e3c2;
P_0c07e3c2: /* original 9020, guest PC 0x0c07e3c2 */
if(!s->budget--) { s->failed_pc=0x0c07e3c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e406u,2);
goto P_0c07e3c4;
P_0c07e3c4: /* original 7f68, guest PC 0x0c07e3c4 */
if(!s->budget--) { s->failed_pc=0x0c07e3c4u; return 0; }
r[15]+=0x00000068u;
goto P_0c07e3c6;
P_0c07e3c6: /* original 03ec, guest PC 0x0c07e3c6 */
if(!s->budget--) { s->failed_pc=0x0c07e3c6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e3c8;
P_0c07e3c8: /* original 2338, guest PC 0x0c07e3c8 */
if(!s->budget--) { s->failed_pc=0x0c07e3c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e3ca;
P_0c07e3ca: /* original 8d2d, guest PC 0x0c07e3ca */
if(!s->budget--) { s->failed_pc=0x0c07e3cau; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(cond) { goto P_0c07e428; }
goto P_0c07e3ce;
P_0c07e3cc: /* original ff8d, guest PC 0x0c07e3cc */
if(!s->budget--) { s->failed_pc=0x0c07e3ccu; return 0; }
fr[15]=0;
goto P_0c07e3ce;
P_0c07e3ce: /* original e030, guest PC 0x0c07e3ce */
if(!s->budget--) { s->failed_pc=0x0c07e3ceu; return 0; }
r[0]=0x00000030u;
goto P_0c07e3d0;
P_0c07e3d0: /* original a033, guest PC 0x0c07e3d0 */
if(!s->budget--) { s->failed_pc=0x0c07e3d0u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e43a;
P_0c07e3d2: /* original f4f7, guest PC 0x0c07e3d2 */
if(!s->budget--) { s->failed_pc=0x0c07e3d2u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07e3d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e3d4u; return 0; } return 1;
P_0c07e428: /* original 9049, guest PC 0x0c07e428 */
if(!s->budget--) { s->failed_pc=0x0c07e428u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4beu,2);
goto P_0c07e42a;
P_0c07e42a: /* original 02ec, guest PC 0x0c07e42a */
if(!s->budget--) { s->failed_pc=0x0c07e42au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e42c;
P_0c07e42c: /* original e008, guest PC 0x0c07e42c */
if(!s->budget--) { s->failed_pc=0x0c07e42cu; return 0; }
r[0]=0x00000008u;
goto P_0c07e42e;
P_0c07e42e: /* original 4208, guest PC 0x0c07e42e */
if(!s->budget--) { s->failed_pc=0x0c07e42eu; return 0; }
r[2]<<=2;
goto P_0c07e430;
P_0c07e430: /* original 4208, guest PC 0x0c07e430 */
if(!s->budget--) { s->failed_pc=0x0c07e430u; return 0; }
r[2]<<=2;
goto P_0c07e432;
P_0c07e432: /* original 329c, guest PC 0x0c07e432 */
if(!s->budget--) { s->failed_pc=0x0c07e432u; return 0; }
r[2]+=r[9];
goto P_0c07e434;
P_0c07e434: /* original f326, guest PC 0x0c07e434 */
if(!s->budget--) { s->failed_pc=0x0c07e434u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e436;
P_0c07e436: /* original e030, guest PC 0x0c07e436 */
if(!s->budget--) { s->failed_pc=0x0c07e436u; return 0; }
r[0]=0x00000030u;
goto P_0c07e438;
P_0c07e438: /* original f437, guest PC 0x0c07e438 */
if(!s->budget--) { s->failed_pc=0x0c07e438u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e43a;
P_0c07e43a: /* original 2fa6, guest PC 0x0c07e43a */
if(!s->budget--) { s->failed_pc=0x0c07e43au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e43c;
P_0c07e43c: /* original e700, guest PC 0x0c07e43c */
if(!s->budget--) { s->failed_pc=0x0c07e43cu; return 0; }
r[7]=0x00000000u;
goto P_0c07e43e;
P_0c07e43e: /* original 2fc6, guest PC 0x0c07e43e */
if(!s->budget--) { s->failed_pc=0x0c07e43eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e440;
P_0c07e440: /* original 953e, guest PC 0x0c07e440 */
if(!s->budget--) { s->failed_pc=0x0c07e440u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c0u,2);
goto P_0c07e442;
P_0c07e442: /* original 943e, guest PC 0x0c07e442 */
if(!s->budget--) { s->failed_pc=0x0c07e442u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c2u,2);
goto P_0c07e444;
P_0c07e444: /* original 4b0b, guest PC 0x0c07e444 */
if(!s->budget--) { s->failed_pc=0x0c07e444u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e448u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e448u) { target=s->pc; goto dispatch; }
goto P_0c07e448;
P_0c07e446: /* original 66d3, guest PC 0x0c07e446 */
if(!s->budget--) { s->failed_pc=0x0c07e446u; return 0; }
r[6]=r[13];
goto P_0c07e448;
P_0c07e448: /* original 6403, guest PC 0x0c07e448 */
if(!s->budget--) { s->failed_pc=0x0c07e448u; return 0; }
r[4]=r[0];
goto P_0c07e44a;
P_0c07e44a: /* original 903b, guest PC 0x0c07e44a */
if(!s->budget--) { s->failed_pc=0x0c07e44au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c4u,2);
goto P_0c07e44c;
P_0c07e44c: /* original 03ec, guest PC 0x0c07e44c */
if(!s->budget--) { s->failed_pc=0x0c07e44cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e44e;
P_0c07e44e: /* original 2338, guest PC 0x0c07e44e */
if(!s->budget--) { s->failed_pc=0x0c07e44eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e450;
P_0c07e450: /* original 8d03, guest PC 0x0c07e450 */
if(!s->budget--) { s->failed_pc=0x0c07e450u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e45a; }
goto P_0c07e454;
P_0c07e452: /* original 7f08, guest PC 0x0c07e452 */
if(!s->budget--) { s->failed_pc=0x0c07e452u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e454;
P_0c07e454: /* original e030, guest PC 0x0c07e454 */
if(!s->budget--) { s->failed_pc=0x0c07e454u; return 0; }
r[0]=0x00000030u;
goto P_0c07e456;
P_0c07e456: /* original a009, guest PC 0x0c07e456 */
if(!s->budget--) { s->failed_pc=0x0c07e456u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e46c;
P_0c07e458: /* original f4f7, guest PC 0x0c07e458 */
if(!s->budget--) { s->failed_pc=0x0c07e458u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e45a;
P_0c07e45a: /* original 9030, guest PC 0x0c07e45a */
if(!s->budget--) { s->failed_pc=0x0c07e45au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4beu,2);
goto P_0c07e45c;
P_0c07e45c: /* original 02ec, guest PC 0x0c07e45c */
if(!s->budget--) { s->failed_pc=0x0c07e45cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e45e;
P_0c07e45e: /* original e008, guest PC 0x0c07e45e */
if(!s->budget--) { s->failed_pc=0x0c07e45eu; return 0; }
r[0]=0x00000008u;
goto P_0c07e460;
P_0c07e460: /* original 4208, guest PC 0x0c07e460 */
if(!s->budget--) { s->failed_pc=0x0c07e460u; return 0; }
r[2]<<=2;
goto P_0c07e462;
P_0c07e462: /* original 4208, guest PC 0x0c07e462 */
if(!s->budget--) { s->failed_pc=0x0c07e462u; return 0; }
r[2]<<=2;
goto P_0c07e464;
P_0c07e464: /* original 329c, guest PC 0x0c07e464 */
if(!s->budget--) { s->failed_pc=0x0c07e464u; return 0; }
r[2]+=r[9];
goto P_0c07e466;
P_0c07e466: /* original f326, guest PC 0x0c07e466 */
if(!s->budget--) { s->failed_pc=0x0c07e466u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e468;
P_0c07e468: /* original e030, guest PC 0x0c07e468 */
if(!s->budget--) { s->failed_pc=0x0c07e468u; return 0; }
r[0]=0x00000030u;
goto P_0c07e46a;
P_0c07e46a: /* original f437, guest PC 0x0c07e46a */
if(!s->budget--) { s->failed_pc=0x0c07e46au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e46c;
P_0c07e46c: /* original 2fa6, guest PC 0x0c07e46c */
if(!s->budget--) { s->failed_pc=0x0c07e46cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e46e;
P_0c07e46e: /* original e700, guest PC 0x0c07e46e */
if(!s->budget--) { s->failed_pc=0x0c07e46eu; return 0; }
r[7]=0x00000000u;
goto P_0c07e470;
P_0c07e470: /* original 2fc6, guest PC 0x0c07e470 */
if(!s->budget--) { s->failed_pc=0x0c07e470u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e472;
P_0c07e472: /* original 9528, guest PC 0x0c07e472 */
if(!s->budget--) { s->failed_pc=0x0c07e472u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c6u,2);
goto P_0c07e474;
P_0c07e474: /* original 9428, guest PC 0x0c07e474 */
if(!s->budget--) { s->failed_pc=0x0c07e474u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c8u,2);
goto P_0c07e476;
P_0c07e476: /* original 4b0b, guest PC 0x0c07e476 */
if(!s->budget--) { s->failed_pc=0x0c07e476u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e47au;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e47au) { target=s->pc; goto dispatch; }
goto P_0c07e47a;
P_0c07e478: /* original 66d3, guest PC 0x0c07e478 */
if(!s->budget--) { s->failed_pc=0x0c07e478u; return 0; }
r[6]=r[13];
goto P_0c07e47a;
P_0c07e47a: /* original 6403, guest PC 0x0c07e47a */
if(!s->budget--) { s->failed_pc=0x0c07e47au; return 0; }
r[4]=r[0];
goto P_0c07e47c;
P_0c07e47c: /* original 9022, guest PC 0x0c07e47c */
if(!s->budget--) { s->failed_pc=0x0c07e47cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c4u,2);
goto P_0c07e47e;
P_0c07e47e: /* original 03ec, guest PC 0x0c07e47e */
if(!s->budget--) { s->failed_pc=0x0c07e47eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e480;
P_0c07e480: /* original 2338, guest PC 0x0c07e480 */
if(!s->budget--) { s->failed_pc=0x0c07e480u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e482;
P_0c07e482: /* original 8d03, guest PC 0x0c07e482 */
if(!s->budget--) { s->failed_pc=0x0c07e482u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e48c; }
goto P_0c07e486;
P_0c07e484: /* original 7f08, guest PC 0x0c07e484 */
if(!s->budget--) { s->failed_pc=0x0c07e484u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e486;
P_0c07e486: /* original e030, guest PC 0x0c07e486 */
if(!s->budget--) { s->failed_pc=0x0c07e486u; return 0; }
r[0]=0x00000030u;
goto P_0c07e488;
P_0c07e488: /* original a009, guest PC 0x0c07e488 */
if(!s->budget--) { s->failed_pc=0x0c07e488u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e49e;
P_0c07e48a: /* original f4f7, guest PC 0x0c07e48a */
if(!s->budget--) { s->failed_pc=0x0c07e48au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e48c;
P_0c07e48c: /* original 9017, guest PC 0x0c07e48c */
if(!s->budget--) { s->failed_pc=0x0c07e48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4beu,2);
goto P_0c07e48e;
P_0c07e48e: /* original 02ec, guest PC 0x0c07e48e */
if(!s->budget--) { s->failed_pc=0x0c07e48eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e490;
P_0c07e490: /* original e00c, guest PC 0x0c07e490 */
if(!s->budget--) { s->failed_pc=0x0c07e490u; return 0; }
r[0]=0x0000000cu;
goto P_0c07e492;
P_0c07e492: /* original 4208, guest PC 0x0c07e492 */
if(!s->budget--) { s->failed_pc=0x0c07e492u; return 0; }
r[2]<<=2;
goto P_0c07e494;
P_0c07e494: /* original 4208, guest PC 0x0c07e494 */
if(!s->budget--) { s->failed_pc=0x0c07e494u; return 0; }
r[2]<<=2;
goto P_0c07e496;
P_0c07e496: /* original 329c, guest PC 0x0c07e496 */
if(!s->budget--) { s->failed_pc=0x0c07e496u; return 0; }
r[2]+=r[9];
goto P_0c07e498;
P_0c07e498: /* original f326, guest PC 0x0c07e498 */
if(!s->budget--) { s->failed_pc=0x0c07e498u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e49a;
P_0c07e49a: /* original e030, guest PC 0x0c07e49a */
if(!s->budget--) { s->failed_pc=0x0c07e49au; return 0; }
r[0]=0x00000030u;
goto P_0c07e49c;
P_0c07e49c: /* original f437, guest PC 0x0c07e49c */
if(!s->budget--) { s->failed_pc=0x0c07e49cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e49e;
P_0c07e49e: /* original 2fa6, guest PC 0x0c07e49e */
if(!s->budget--) { s->failed_pc=0x0c07e49eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e4a0;
P_0c07e4a0: /* original e700, guest PC 0x0c07e4a0 */
if(!s->budget--) { s->failed_pc=0x0c07e4a0u; return 0; }
r[7]=0x00000000u;
goto P_0c07e4a2;
P_0c07e4a2: /* original 2fc6, guest PC 0x0c07e4a2 */
if(!s->budget--) { s->failed_pc=0x0c07e4a2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e4a4;
P_0c07e4a4: /* original 9511, guest PC 0x0c07e4a4 */
if(!s->budget--) { s->failed_pc=0x0c07e4a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4cau,2);
goto P_0c07e4a6;
P_0c07e4a6: /* original 9411, guest PC 0x0c07e4a6 */
if(!s->budget--) { s->failed_pc=0x0c07e4a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4ccu,2);
goto P_0c07e4a8;
P_0c07e4a8: /* original 4b0b, guest PC 0x0c07e4a8 */
if(!s->budget--) { s->failed_pc=0x0c07e4a8u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e4acu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e4acu) { target=s->pc; goto dispatch; }
goto P_0c07e4ac;
P_0c07e4aa: /* original 66d3, guest PC 0x0c07e4aa */
if(!s->budget--) { s->failed_pc=0x0c07e4aau; return 0; }
r[6]=r[13];
goto P_0c07e4ac;
P_0c07e4ac: /* original 6403, guest PC 0x0c07e4ac */
if(!s->budget--) { s->failed_pc=0x0c07e4acu; return 0; }
r[4]=r[0];
goto P_0c07e4ae;
P_0c07e4ae: /* original 9009, guest PC 0x0c07e4ae */
if(!s->budget--) { s->failed_pc=0x0c07e4aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e4c4u,2);
goto P_0c07e4b0;
P_0c07e4b0: /* original 03ec, guest PC 0x0c07e4b0 */
if(!s->budget--) { s->failed_pc=0x0c07e4b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e4b2;
P_0c07e4b2: /* original 2338, guest PC 0x0c07e4b2 */
if(!s->budget--) { s->failed_pc=0x0c07e4b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e4b4;
P_0c07e4b4: /* original 8d0b, guest PC 0x0c07e4b4 */
if(!s->budget--) { s->failed_pc=0x0c07e4b4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e4ce; }
goto P_0c07e4b8;
P_0c07e4b6: /* original 7f08, guest PC 0x0c07e4b6 */
if(!s->budget--) { s->failed_pc=0x0c07e4b6u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e4b8;
P_0c07e4b8: /* original e030, guest PC 0x0c07e4b8 */
if(!s->budget--) { s->failed_pc=0x0c07e4b8u; return 0; }
r[0]=0x00000030u;
goto P_0c07e4ba;
P_0c07e4ba: /* original a011, guest PC 0x0c07e4ba */
if(!s->budget--) { s->failed_pc=0x0c07e4bau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e4e0;
P_0c07e4bc: /* original f4f7, guest PC 0x0c07e4bc */
if(!s->budget--) { s->failed_pc=0x0c07e4bcu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07e4beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e4beu; return 0; } return 1;
P_0c07e4ce: /* original 908a, guest PC 0x0c07e4ce */
if(!s->budget--) { s->failed_pc=0x0c07e4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e6u,2);
goto P_0c07e4d0;
P_0c07e4d0: /* original 02ec, guest PC 0x0c07e4d0 */
if(!s->budget--) { s->failed_pc=0x0c07e4d0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e4d2;
P_0c07e4d2: /* original e00c, guest PC 0x0c07e4d2 */
if(!s->budget--) { s->failed_pc=0x0c07e4d2u; return 0; }
r[0]=0x0000000cu;
goto P_0c07e4d4;
P_0c07e4d4: /* original 4208, guest PC 0x0c07e4d4 */
if(!s->budget--) { s->failed_pc=0x0c07e4d4u; return 0; }
r[2]<<=2;
goto P_0c07e4d6;
P_0c07e4d6: /* original 4208, guest PC 0x0c07e4d6 */
if(!s->budget--) { s->failed_pc=0x0c07e4d6u; return 0; }
r[2]<<=2;
goto P_0c07e4d8;
P_0c07e4d8: /* original 329c, guest PC 0x0c07e4d8 */
if(!s->budget--) { s->failed_pc=0x0c07e4d8u; return 0; }
r[2]+=r[9];
goto P_0c07e4da;
P_0c07e4da: /* original f326, guest PC 0x0c07e4da */
if(!s->budget--) { s->failed_pc=0x0c07e4dau; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e4dc;
P_0c07e4dc: /* original e030, guest PC 0x0c07e4dc */
if(!s->budget--) { s->failed_pc=0x0c07e4dcu; return 0; }
r[0]=0x00000030u;
goto P_0c07e4de;
P_0c07e4de: /* original f437, guest PC 0x0c07e4de */
if(!s->budget--) { s->failed_pc=0x0c07e4deu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e4e0;
P_0c07e4e0: /* original 2fa6, guest PC 0x0c07e4e0 */
if(!s->budget--) { s->failed_pc=0x0c07e4e0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e4e2;
P_0c07e4e2: /* original e700, guest PC 0x0c07e4e2 */
if(!s->budget--) { s->failed_pc=0x0c07e4e2u; return 0; }
r[7]=0x00000000u;
goto P_0c07e4e4;
P_0c07e4e4: /* original 2fc6, guest PC 0x0c07e4e4 */
if(!s->budget--) { s->failed_pc=0x0c07e4e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e4e6;
P_0c07e4e6: /* original 957f, guest PC 0x0c07e4e6 */
if(!s->budget--) { s->failed_pc=0x0c07e4e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e8u,2);
goto P_0c07e4e8;
P_0c07e4e8: /* original 947f, guest PC 0x0c07e4e8 */
if(!s->budget--) { s->failed_pc=0x0c07e4e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5eau,2);
goto P_0c07e4ea;
P_0c07e4ea: /* original 4b0b, guest PC 0x0c07e4ea */
if(!s->budget--) { s->failed_pc=0x0c07e4eau; return 0; }
target=r[11];
r[16]=code_base|0x0c07e4eeu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e4eeu) { target=s->pc; goto dispatch; }
goto P_0c07e4ee;
P_0c07e4ec: /* original 66d3, guest PC 0x0c07e4ec */
if(!s->budget--) { s->failed_pc=0x0c07e4ecu; return 0; }
r[6]=r[13];
goto P_0c07e4ee;
P_0c07e4ee: /* original 6403, guest PC 0x0c07e4ee */
if(!s->budget--) { s->failed_pc=0x0c07e4eeu; return 0; }
r[4]=r[0];
goto P_0c07e4f0;
P_0c07e4f0: /* original 9079, guest PC 0x0c07e4f0 */
if(!s->budget--) { s->failed_pc=0x0c07e4f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e6u,2);
goto P_0c07e4f2;
P_0c07e4f2: /* original 03ec, guest PC 0x0c07e4f2 */
if(!s->budget--) { s->failed_pc=0x0c07e4f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e4f4;
P_0c07e4f4: /* original e030, guest PC 0x0c07e4f4 */
if(!s->budget--) { s->failed_pc=0x0c07e4f4u; return 0; }
r[0]=0x00000030u;
goto P_0c07e4f6;
P_0c07e4f6: /* original 4308, guest PC 0x0c07e4f6 */
if(!s->budget--) { s->failed_pc=0x0c07e4f6u; return 0; }
r[3]<<=2;
goto P_0c07e4f8;
P_0c07e4f8: /* original 4308, guest PC 0x0c07e4f8 */
if(!s->budget--) { s->failed_pc=0x0c07e4f8u; return 0; }
r[3]<<=2;
goto P_0c07e4fa;
P_0c07e4fa: /* original 339c, guest PC 0x0c07e4fa */
if(!s->budget--) { s->failed_pc=0x0c07e4fau; return 0; }
r[3]+=r[9];
goto P_0c07e4fc;
P_0c07e4fc: /* original f338, guest PC 0x0c07e4fc */
if(!s->budget--) { s->failed_pc=0x0c07e4fcu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c07e4fe;
P_0c07e4fe: /* original f437, guest PC 0x0c07e4fe */
if(!s->budget--) { s->failed_pc=0x0c07e4feu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e500;
P_0c07e500: /* original 9075, guest PC 0x0c07e500 */
if(!s->budget--) { s->failed_pc=0x0c07e500u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5eeu,2);
goto P_0c07e502;
P_0c07e502: /* original 9473, guest PC 0x0c07e502 */
if(!s->budget--) { s->failed_pc=0x0c07e502u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5ecu,2);
goto P_0c07e504;
P_0c07e504: /* original 03ec, guest PC 0x0c07e504 */
if(!s->budget--) { s->failed_pc=0x0c07e504u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e506;
P_0c07e506: /* original 7001, guest PC 0x0c07e506 */
if(!s->budget--) { s->failed_pc=0x0c07e506u; return 0; }
r[0]+=0x00000001u;
goto P_0c07e508;
P_0c07e508: /* original 02ec, guest PC 0x0c07e508 */
if(!s->budget--) { s->failed_pc=0x0c07e508u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e50a;
P_0c07e50a: /* original d83c, guest PC 0x0c07e50a */
if(!s->budget--) { s->failed_pc=0x0c07e50au; return 0; }
r[8]=read(ram,0x0c07e5fcu,4);
goto P_0c07e50c;
P_0c07e50c: /* original 3320, guest PC 0x0c07e50c */
if(!s->budget--) { s->failed_pc=0x0c07e50cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07e50e;
P_0c07e50e: /* original 8d0e, guest PC 0x0c07e50e */
if(!s->budget--) { s->failed_pc=0x0c07e50eu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e52e; }
goto P_0c07e512;
P_0c07e510: /* original 7f08, guest PC 0x0c07e510 */
if(!s->budget--) { s->failed_pc=0x0c07e510u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e512;
P_0c07e512: /* original e700, guest PC 0x0c07e512 */
if(!s->budget--) { s->failed_pc=0x0c07e512u; return 0; }
r[7]=0x00000000u;
goto P_0c07e514;
P_0c07e514: /* original 66d3, guest PC 0x0c07e514 */
if(!s->budget--) { s->failed_pc=0x0c07e514u; return 0; }
r[6]=r[13];
goto P_0c07e516;
P_0c07e516: /* original 2fc6, guest PC 0x0c07e516 */
if(!s->budget--) { s->failed_pc=0x0c07e516u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e518;
P_0c07e518: /* original 906a, guest PC 0x0c07e518 */
if(!s->budget--) { s->failed_pc=0x0c07e518u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f0u,2);
goto P_0c07e51a;
P_0c07e51a: /* original 05ec, guest PC 0x0c07e51a */
if(!s->budget--) { s->failed_pc=0x0c07e51au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e51c;
P_0c07e51c: /* original d038, guest PC 0x0c07e51c */
if(!s->budget--) { s->failed_pc=0x0c07e51cu; return 0; }
r[0]=read(ram,0x0c07e600u,4);
goto P_0c07e51e;
P_0c07e51e: /* original 4508, guest PC 0x0c07e51e */
if(!s->budget--) { s->failed_pc=0x0c07e51eu; return 0; }
r[5]<<=2;
goto P_0c07e520;
P_0c07e520: /* original 480b, guest PC 0x0c07e520 */
if(!s->budget--) { s->failed_pc=0x0c07e520u; return 0; }
target=r[8];
r[16]=code_base|0x0c07e524u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e524u) { target=s->pc; goto dispatch; }
goto P_0c07e524;
P_0c07e522: /* original 055e, guest PC 0x0c07e522 */
if(!s->budget--) { s->failed_pc=0x0c07e522u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e524;
P_0c07e524: /* original 9063, guest PC 0x0c07e524 */
if(!s->budget--) { s->failed_pc=0x0c07e524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5eeu,2);
goto P_0c07e526;
P_0c07e526: /* original 7f04, guest PC 0x0c07e526 */
if(!s->budget--) { s->failed_pc=0x0c07e526u; return 0; }
r[15]+=0x00000004u;
goto P_0c07e528;
P_0c07e528: /* original 03ec, guest PC 0x0c07e528 */
if(!s->budget--) { s->failed_pc=0x0c07e528u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e52a;
P_0c07e52a: /* original 7001, guest PC 0x0c07e52a */
if(!s->budget--) { s->failed_pc=0x0c07e52au; return 0; }
r[0]+=0x00000001u;
goto P_0c07e52c;
P_0c07e52c: /* original 0e34, guest PC 0x0c07e52c */
if(!s->budget--) { s->failed_pc=0x0c07e52cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07e52e;
P_0c07e52e: /* original 2fa6, guest PC 0x0c07e52e */
if(!s->budget--) { s->failed_pc=0x0c07e52eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e530;
P_0c07e530: /* original e700, guest PC 0x0c07e530 */
if(!s->budget--) { s->failed_pc=0x0c07e530u; return 0; }
r[7]=0x00000000u;
goto P_0c07e532;
P_0c07e532: /* original 2fc6, guest PC 0x0c07e532 */
if(!s->budget--) { s->failed_pc=0x0c07e532u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e534;
P_0c07e534: /* original 66d3, guest PC 0x0c07e534 */
if(!s->budget--) { s->failed_pc=0x0c07e534u; return 0; }
r[6]=r[13];
goto P_0c07e536;
P_0c07e536: /* original 905a, guest PC 0x0c07e536 */
if(!s->budget--) { s->failed_pc=0x0c07e536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5eeu,2);
goto P_0c07e538;
P_0c07e538: /* original 9458, guest PC 0x0c07e538 */
if(!s->budget--) { s->failed_pc=0x0c07e538u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5ecu,2);
goto P_0c07e53a;
P_0c07e53a: /* original 05ec, guest PC 0x0c07e53a */
if(!s->budget--) { s->failed_pc=0x0c07e53au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e53c;
P_0c07e53c: /* original d030, guest PC 0x0c07e53c */
if(!s->budget--) { s->failed_pc=0x0c07e53cu; return 0; }
r[0]=read(ram,0x0c07e600u,4);
goto P_0c07e53e;
P_0c07e53e: /* original 4508, guest PC 0x0c07e53e */
if(!s->budget--) { s->failed_pc=0x0c07e53eu; return 0; }
r[5]<<=2;
goto P_0c07e540;
P_0c07e540: /* original 4b0b, guest PC 0x0c07e540 */
if(!s->budget--) { s->failed_pc=0x0c07e540u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e544u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e544u) { target=s->pc; goto dispatch; }
goto P_0c07e544;
P_0c07e542: /* original 055e, guest PC 0x0c07e542 */
if(!s->budget--) { s->failed_pc=0x0c07e542u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e544;
P_0c07e544: /* original 6403, guest PC 0x0c07e544 */
if(!s->budget--) { s->failed_pc=0x0c07e544u; return 0; }
r[4]=r[0];
goto P_0c07e546;
P_0c07e546: /* original 904e, guest PC 0x0c07e546 */
if(!s->budget--) { s->failed_pc=0x0c07e546u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e6u,2);
goto P_0c07e548;
P_0c07e548: /* original e700, guest PC 0x0c07e548 */
if(!s->budget--) { s->failed_pc=0x0c07e548u; return 0; }
r[7]=0x00000000u;
goto P_0c07e54a;
P_0c07e54a: /* original 03ec, guest PC 0x0c07e54a */
if(!s->budget--) { s->failed_pc=0x0c07e54au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e54c;
P_0c07e54c: /* original e030, guest PC 0x0c07e54c */
if(!s->budget--) { s->failed_pc=0x0c07e54cu; return 0; }
r[0]=0x00000030u;
goto P_0c07e54e;
P_0c07e54e: /* original 4308, guest PC 0x0c07e54e */
if(!s->budget--) { s->failed_pc=0x0c07e54eu; return 0; }
r[3]<<=2;
goto P_0c07e550;
P_0c07e550: /* original 4308, guest PC 0x0c07e550 */
if(!s->budget--) { s->failed_pc=0x0c07e550u; return 0; }
r[3]<<=2;
goto P_0c07e552;
P_0c07e552: /* original 339c, guest PC 0x0c07e552 */
if(!s->budget--) { s->failed_pc=0x0c07e552u; return 0; }
r[3]+=r[9];
goto P_0c07e554;
P_0c07e554: /* original f338, guest PC 0x0c07e554 */
if(!s->budget--) { s->failed_pc=0x0c07e554u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c07e556;
P_0c07e556: /* original f437, guest PC 0x0c07e556 */
if(!s->budget--) { s->failed_pc=0x0c07e556u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e558;
P_0c07e558: /* original 2fa6, guest PC 0x0c07e558 */
if(!s->budget--) { s->failed_pc=0x0c07e558u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e55a;
P_0c07e55a: /* original 2fc6, guest PC 0x0c07e55a */
if(!s->budget--) { s->failed_pc=0x0c07e55au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e55c;
P_0c07e55c: /* original 9544, guest PC 0x0c07e55c */
if(!s->budget--) { s->failed_pc=0x0c07e55cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e8u,2);
goto P_0c07e55e;
P_0c07e55e: /* original 9448, guest PC 0x0c07e55e */
if(!s->budget--) { s->failed_pc=0x0c07e55eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f2u,2);
goto P_0c07e560;
P_0c07e560: /* original 4b0b, guest PC 0x0c07e560 */
if(!s->budget--) { s->failed_pc=0x0c07e560u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e564u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e564u) { target=s->pc; goto dispatch; }
goto P_0c07e564;
P_0c07e562: /* original 66d3, guest PC 0x0c07e562 */
if(!s->budget--) { s->failed_pc=0x0c07e562u; return 0; }
r[6]=r[13];
goto P_0c07e564;
P_0c07e564: /* original 6403, guest PC 0x0c07e564 */
if(!s->budget--) { s->failed_pc=0x0c07e564u; return 0; }
r[4]=r[0];
goto P_0c07e566;
P_0c07e566: /* original 903e, guest PC 0x0c07e566 */
if(!s->budget--) { s->failed_pc=0x0c07e566u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e6u,2);
goto P_0c07e568;
P_0c07e568: /* original 03ec, guest PC 0x0c07e568 */
if(!s->budget--) { s->failed_pc=0x0c07e568u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e56a;
P_0c07e56a: /* original e004, guest PC 0x0c07e56a */
if(!s->budget--) { s->failed_pc=0x0c07e56au; return 0; }
r[0]=0x00000004u;
goto P_0c07e56c;
P_0c07e56c: /* original 4308, guest PC 0x0c07e56c */
if(!s->budget--) { s->failed_pc=0x0c07e56cu; return 0; }
r[3]<<=2;
goto P_0c07e56e;
P_0c07e56e: /* original 4308, guest PC 0x0c07e56e */
if(!s->budget--) { s->failed_pc=0x0c07e56eu; return 0; }
r[3]<<=2;
goto P_0c07e570;
P_0c07e570: /* original 339c, guest PC 0x0c07e570 */
if(!s->budget--) { s->failed_pc=0x0c07e570u; return 0; }
r[3]+=r[9];
goto P_0c07e572;
P_0c07e572: /* original f336, guest PC 0x0c07e572 */
if(!s->budget--) { s->failed_pc=0x0c07e572u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c07e574;
P_0c07e574: /* original e030, guest PC 0x0c07e574 */
if(!s->budget--) { s->failed_pc=0x0c07e574u; return 0; }
r[0]=0x00000030u;
goto P_0c07e576;
P_0c07e576: /* original f437, guest PC 0x0c07e576 */
if(!s->budget--) { s->failed_pc=0x0c07e576u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e578;
P_0c07e578: /* original 903d, guest PC 0x0c07e578 */
if(!s->budget--) { s->failed_pc=0x0c07e578u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f6u,2);
goto P_0c07e57a;
P_0c07e57a: /* original 943b, guest PC 0x0c07e57a */
if(!s->budget--) { s->failed_pc=0x0c07e57au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f4u,2);
goto P_0c07e57c;
P_0c07e57c: /* original 03ec, guest PC 0x0c07e57c */
if(!s->budget--) { s->failed_pc=0x0c07e57cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e57e;
P_0c07e57e: /* original 7001, guest PC 0x0c07e57e */
if(!s->budget--) { s->failed_pc=0x0c07e57eu; return 0; }
r[0]+=0x00000001u;
goto P_0c07e580;
P_0c07e580: /* original 02ec, guest PC 0x0c07e580 */
if(!s->budget--) { s->failed_pc=0x0c07e580u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e582;
P_0c07e582: /* original 3320, guest PC 0x0c07e582 */
if(!s->budget--) { s->failed_pc=0x0c07e582u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07e584;
P_0c07e584: /* original 8d0a, guest PC 0x0c07e584 */
if(!s->budget--) { s->failed_pc=0x0c07e584u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(cond) { goto P_0c07e59c; }
goto P_0c07e588;
P_0c07e586: /* original 7f10, guest PC 0x0c07e586 */
if(!s->budget--) { s->failed_pc=0x0c07e586u; return 0; }
r[15]+=0x00000010u;
goto P_0c07e588;
P_0c07e588: /* original e700, guest PC 0x0c07e588 */
if(!s->budget--) { s->failed_pc=0x0c07e588u; return 0; }
r[7]=0x00000000u;
goto P_0c07e58a;
P_0c07e58a: /* original 66d3, guest PC 0x0c07e58a */
if(!s->budget--) { s->failed_pc=0x0c07e58au; return 0; }
r[6]=r[13];
goto P_0c07e58c;
P_0c07e58c: /* original 2fc6, guest PC 0x0c07e58c */
if(!s->budget--) { s->failed_pc=0x0c07e58cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e58e;
P_0c07e58e: /* original 9033, guest PC 0x0c07e58e */
if(!s->budget--) { s->failed_pc=0x0c07e58eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f8u,2);
goto P_0c07e590;
P_0c07e590: /* original 05ec, guest PC 0x0c07e590 */
if(!s->budget--) { s->failed_pc=0x0c07e590u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e592;
P_0c07e592: /* original d01c, guest PC 0x0c07e592 */
if(!s->budget--) { s->failed_pc=0x0c07e592u; return 0; }
r[0]=read(ram,0x0c07e604u,4);
goto P_0c07e594;
P_0c07e594: /* original 4508, guest PC 0x0c07e594 */
if(!s->budget--) { s->failed_pc=0x0c07e594u; return 0; }
r[5]<<=2;
goto P_0c07e596;
P_0c07e596: /* original 480b, guest PC 0x0c07e596 */
if(!s->budget--) { s->failed_pc=0x0c07e596u; return 0; }
target=r[8];
r[16]=code_base|0x0c07e59au;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e59au) { target=s->pc; goto dispatch; }
goto P_0c07e59a;
P_0c07e598: /* original 055e, guest PC 0x0c07e598 */
if(!s->budget--) { s->failed_pc=0x0c07e598u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e59a;
P_0c07e59a: /* original 7f04, guest PC 0x0c07e59a */
if(!s->budget--) { s->failed_pc=0x0c07e59au; return 0; }
r[15]+=0x00000004u;
goto P_0c07e59c;
P_0c07e59c: /* original 2fa6, guest PC 0x0c07e59c */
if(!s->budget--) { s->failed_pc=0x0c07e59cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e59e;
P_0c07e59e: /* original e700, guest PC 0x0c07e59e */
if(!s->budget--) { s->failed_pc=0x0c07e59eu; return 0; }
r[7]=0x00000000u;
goto P_0c07e5a0;
P_0c07e5a0: /* original 2fc6, guest PC 0x0c07e5a0 */
if(!s->budget--) { s->failed_pc=0x0c07e5a0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e5a2;
P_0c07e5a2: /* original 66d3, guest PC 0x0c07e5a2 */
if(!s->budget--) { s->failed_pc=0x0c07e5a2u; return 0; }
r[6]=r[13];
goto P_0c07e5a4;
P_0c07e5a4: /* original 9027, guest PC 0x0c07e5a4 */
if(!s->budget--) { s->failed_pc=0x0c07e5a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f6u,2);
goto P_0c07e5a6;
P_0c07e5a6: /* original 9425, guest PC 0x0c07e5a6 */
if(!s->budget--) { s->failed_pc=0x0c07e5a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f4u,2);
goto P_0c07e5a8;
P_0c07e5a8: /* original 05ec, guest PC 0x0c07e5a8 */
if(!s->budget--) { s->failed_pc=0x0c07e5a8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e5aa;
P_0c07e5aa: /* original d016, guest PC 0x0c07e5aa */
if(!s->budget--) { s->failed_pc=0x0c07e5aau; return 0; }
r[0]=read(ram,0x0c07e604u,4);
goto P_0c07e5ac;
P_0c07e5ac: /* original 4508, guest PC 0x0c07e5ac */
if(!s->budget--) { s->failed_pc=0x0c07e5acu; return 0; }
r[5]<<=2;
goto P_0c07e5ae;
P_0c07e5ae: /* original 4b0b, guest PC 0x0c07e5ae */
if(!s->budget--) { s->failed_pc=0x0c07e5aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e5b2u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e5b2u) { target=s->pc; goto dispatch; }
goto P_0c07e5b2;
P_0c07e5b0: /* original 055e, guest PC 0x0c07e5b0 */
if(!s->budget--) { s->failed_pc=0x0c07e5b0u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e5b2;
P_0c07e5b2: /* original 6403, guest PC 0x0c07e5b2 */
if(!s->budget--) { s->failed_pc=0x0c07e5b2u; return 0; }
r[4]=r[0];
goto P_0c07e5b4;
P_0c07e5b4: /* original 9017, guest PC 0x0c07e5b4 */
if(!s->budget--) { s->failed_pc=0x0c07e5b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e6u,2);
goto P_0c07e5b6;
P_0c07e5b6: /* original e700, guest PC 0x0c07e5b6 */
if(!s->budget--) { s->failed_pc=0x0c07e5b6u; return 0; }
r[7]=0x00000000u;
goto P_0c07e5b8;
P_0c07e5b8: /* original 03ec, guest PC 0x0c07e5b8 */
if(!s->budget--) { s->failed_pc=0x0c07e5b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e5ba;
P_0c07e5ba: /* original e004, guest PC 0x0c07e5ba */
if(!s->budget--) { s->failed_pc=0x0c07e5bau; return 0; }
r[0]=0x00000004u;
goto P_0c07e5bc;
P_0c07e5bc: /* original 4308, guest PC 0x0c07e5bc */
if(!s->budget--) { s->failed_pc=0x0c07e5bcu; return 0; }
r[3]<<=2;
goto P_0c07e5be;
P_0c07e5be: /* original 4308, guest PC 0x0c07e5be */
if(!s->budget--) { s->failed_pc=0x0c07e5beu; return 0; }
r[3]<<=2;
goto P_0c07e5c0;
P_0c07e5c0: /* original 339c, guest PC 0x0c07e5c0 */
if(!s->budget--) { s->failed_pc=0x0c07e5c0u; return 0; }
r[3]+=r[9];
goto P_0c07e5c2;
P_0c07e5c2: /* original f336, guest PC 0x0c07e5c2 */
if(!s->budget--) { s->failed_pc=0x0c07e5c2u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c07e5c4;
P_0c07e5c4: /* original e030, guest PC 0x0c07e5c4 */
if(!s->budget--) { s->failed_pc=0x0c07e5c4u; return 0; }
r[0]=0x00000030u;
goto P_0c07e5c6;
P_0c07e5c6: /* original f437, guest PC 0x0c07e5c6 */
if(!s->budget--) { s->failed_pc=0x0c07e5c6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e5c8;
P_0c07e5c8: /* original 2fa6, guest PC 0x0c07e5c8 */
if(!s->budget--) { s->failed_pc=0x0c07e5c8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e5ca;
P_0c07e5ca: /* original 2fc6, guest PC 0x0c07e5ca */
if(!s->budget--) { s->failed_pc=0x0c07e5cau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e5cc;
P_0c07e5cc: /* original 950c, guest PC 0x0c07e5cc */
if(!s->budget--) { s->failed_pc=0x0c07e5ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5e8u,2);
goto P_0c07e5ce;
P_0c07e5ce: /* original 9414, guest PC 0x0c07e5ce */
if(!s->budget--) { s->failed_pc=0x0c07e5ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5fau,2);
goto P_0c07e5d0;
P_0c07e5d0: /* original 4b0b, guest PC 0x0c07e5d0 */
if(!s->budget--) { s->failed_pc=0x0c07e5d0u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e5d4u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e5d4u) { target=s->pc; goto dispatch; }
goto P_0c07e5d4;
P_0c07e5d2: /* original 66d3, guest PC 0x0c07e5d2 */
if(!s->budget--) { s->failed_pc=0x0c07e5d2u; return 0; }
r[6]=r[13];
goto P_0c07e5d4;
P_0c07e5d4: /* original 6403, guest PC 0x0c07e5d4 */
if(!s->budget--) { s->failed_pc=0x0c07e5d4u; return 0; }
r[4]=r[0];
goto P_0c07e5d6;
P_0c07e5d6: /* original 900e, guest PC 0x0c07e5d6 */
if(!s->budget--) { s->failed_pc=0x0c07e5d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e5f6u,2);
goto P_0c07e5d8;
P_0c07e5d8: /* original 03ec, guest PC 0x0c07e5d8 */
if(!s->budget--) { s->failed_pc=0x0c07e5d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e5da;
P_0c07e5da: /* original 2338, guest PC 0x0c07e5da */
if(!s->budget--) { s->failed_pc=0x0c07e5dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e5dc;
P_0c07e5dc: /* original 8d14, guest PC 0x0c07e5dc */
if(!s->budget--) { s->failed_pc=0x0c07e5dcu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(cond) { goto P_0c07e608; }
goto P_0c07e5e0;
P_0c07e5de: /* original 7f10, guest PC 0x0c07e5de */
if(!s->budget--) { s->failed_pc=0x0c07e5deu; return 0; }
r[15]+=0x00000010u;
goto P_0c07e5e0;
P_0c07e5e0: /* original e030, guest PC 0x0c07e5e0 */
if(!s->budget--) { s->failed_pc=0x0c07e5e0u; return 0; }
r[0]=0x00000030u;
goto P_0c07e5e2;
P_0c07e5e2: /* original a01a, guest PC 0x0c07e5e2 */
if(!s->budget--) { s->failed_pc=0x0c07e5e2u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e61a;
P_0c07e5e4: /* original f4f7, guest PC 0x0c07e5e4 */
if(!s->budget--) { s->failed_pc=0x0c07e5e4u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07e5e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e5e6u; return 0; } return 1;
P_0c07e608: /* original 907b, guest PC 0x0c07e608 */
if(!s->budget--) { s->failed_pc=0x0c07e608u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e702u,2);
goto P_0c07e60a;
P_0c07e60a: /* original 02ec, guest PC 0x0c07e60a */
if(!s->budget--) { s->failed_pc=0x0c07e60au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e60c;
P_0c07e60c: /* original e008, guest PC 0x0c07e60c */
if(!s->budget--) { s->failed_pc=0x0c07e60cu; return 0; }
r[0]=0x00000008u;
goto P_0c07e60e;
P_0c07e60e: /* original 4208, guest PC 0x0c07e60e */
if(!s->budget--) { s->failed_pc=0x0c07e60eu; return 0; }
r[2]<<=2;
goto P_0c07e610;
P_0c07e610: /* original 4208, guest PC 0x0c07e610 */
if(!s->budget--) { s->failed_pc=0x0c07e610u; return 0; }
r[2]<<=2;
goto P_0c07e612;
P_0c07e612: /* original 329c, guest PC 0x0c07e612 */
if(!s->budget--) { s->failed_pc=0x0c07e612u; return 0; }
r[2]+=r[9];
goto P_0c07e614;
P_0c07e614: /* original f326, guest PC 0x0c07e614 */
if(!s->budget--) { s->failed_pc=0x0c07e614u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e616;
P_0c07e616: /* original e030, guest PC 0x0c07e616 */
if(!s->budget--) { s->failed_pc=0x0c07e616u; return 0; }
r[0]=0x00000030u;
goto P_0c07e618;
P_0c07e618: /* original f437, guest PC 0x0c07e618 */
if(!s->budget--) { s->failed_pc=0x0c07e618u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e61a;
P_0c07e61a: /* original 9074, guest PC 0x0c07e61a */
if(!s->budget--) { s->failed_pc=0x0c07e61au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e706u,2);
goto P_0c07e61c;
P_0c07e61c: /* original 9472, guest PC 0x0c07e61c */
if(!s->budget--) { s->failed_pc=0x0c07e61cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e704u,2);
goto P_0c07e61e;
P_0c07e61e: /* original 03ec, guest PC 0x0c07e61e */
if(!s->budget--) { s->failed_pc=0x0c07e61eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e620;
P_0c07e620: /* original 7001, guest PC 0x0c07e620 */
if(!s->budget--) { s->failed_pc=0x0c07e620u; return 0; }
r[0]+=0x00000001u;
goto P_0c07e622;
P_0c07e622: /* original 02ec, guest PC 0x0c07e622 */
if(!s->budget--) { s->failed_pc=0x0c07e622u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e624;
P_0c07e624: /* original 3320, guest PC 0x0c07e624 */
if(!s->budget--) { s->failed_pc=0x0c07e624u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07e626;
P_0c07e626: /* original 890d, guest PC 0x0c07e626 */
if(!s->budget--) { s->failed_pc=0x0c07e626u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e644; }
goto P_0c07e628;
P_0c07e628: /* original e700, guest PC 0x0c07e628 */
if(!s->budget--) { s->failed_pc=0x0c07e628u; return 0; }
r[7]=0x00000000u;
goto P_0c07e62a;
P_0c07e62a: /* original 66d3, guest PC 0x0c07e62a */
if(!s->budget--) { s->failed_pc=0x0c07e62au; return 0; }
r[6]=r[13];
goto P_0c07e62c;
P_0c07e62c: /* original 2fc6, guest PC 0x0c07e62c */
if(!s->budget--) { s->failed_pc=0x0c07e62cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e62e;
P_0c07e62e: /* original 906b, guest PC 0x0c07e62e */
if(!s->budget--) { s->failed_pc=0x0c07e62eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e708u,2);
goto P_0c07e630;
P_0c07e630: /* original 05ec, guest PC 0x0c07e630 */
if(!s->budget--) { s->failed_pc=0x0c07e630u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e632;
P_0c07e632: /* original d039, guest PC 0x0c07e632 */
if(!s->budget--) { s->failed_pc=0x0c07e632u; return 0; }
r[0]=read(ram,0x0c07e718u,4);
goto P_0c07e634;
P_0c07e634: /* original 4508, guest PC 0x0c07e634 */
if(!s->budget--) { s->failed_pc=0x0c07e634u; return 0; }
r[5]<<=2;
goto P_0c07e636;
P_0c07e636: /* original 480b, guest PC 0x0c07e636 */
if(!s->budget--) { s->failed_pc=0x0c07e636u; return 0; }
target=r[8];
r[16]=code_base|0x0c07e63au;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e63au) { target=s->pc; goto dispatch; }
goto P_0c07e63a;
P_0c07e638: /* original 055e, guest PC 0x0c07e638 */
if(!s->budget--) { s->failed_pc=0x0c07e638u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e63a;
P_0c07e63a: /* original 9064, guest PC 0x0c07e63a */
if(!s->budget--) { s->failed_pc=0x0c07e63au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e706u,2);
goto P_0c07e63c;
P_0c07e63c: /* original 7f04, guest PC 0x0c07e63c */
if(!s->budget--) { s->failed_pc=0x0c07e63cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07e63e;
P_0c07e63e: /* original 03ec, guest PC 0x0c07e63e */
if(!s->budget--) { s->failed_pc=0x0c07e63eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e640;
P_0c07e640: /* original 7001, guest PC 0x0c07e640 */
if(!s->budget--) { s->failed_pc=0x0c07e640u; return 0; }
r[0]+=0x00000001u;
goto P_0c07e642;
P_0c07e642: /* original 0e34, guest PC 0x0c07e642 */
if(!s->budget--) { s->failed_pc=0x0c07e642u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07e644;
P_0c07e644: /* original 2fa6, guest PC 0x0c07e644 */
if(!s->budget--) { s->failed_pc=0x0c07e644u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e646;
P_0c07e646: /* original e700, guest PC 0x0c07e646 */
if(!s->budget--) { s->failed_pc=0x0c07e646u; return 0; }
r[7]=0x00000000u;
goto P_0c07e648;
P_0c07e648: /* original 2fc6, guest PC 0x0c07e648 */
if(!s->budget--) { s->failed_pc=0x0c07e648u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e64a;
P_0c07e64a: /* original 66d3, guest PC 0x0c07e64a */
if(!s->budget--) { s->failed_pc=0x0c07e64au; return 0; }
r[6]=r[13];
goto P_0c07e64c;
P_0c07e64c: /* original 905b, guest PC 0x0c07e64c */
if(!s->budget--) { s->failed_pc=0x0c07e64cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e706u,2);
goto P_0c07e64e;
P_0c07e64e: /* original 9459, guest PC 0x0c07e64e */
if(!s->budget--) { s->failed_pc=0x0c07e64eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e704u,2);
goto P_0c07e650;
P_0c07e650: /* original 05ec, guest PC 0x0c07e650 */
if(!s->budget--) { s->failed_pc=0x0c07e650u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e652;
P_0c07e652: /* original d031, guest PC 0x0c07e652 */
if(!s->budget--) { s->failed_pc=0x0c07e652u; return 0; }
r[0]=read(ram,0x0c07e718u,4);
goto P_0c07e654;
P_0c07e654: /* original 4508, guest PC 0x0c07e654 */
if(!s->budget--) { s->failed_pc=0x0c07e654u; return 0; }
r[5]<<=2;
goto P_0c07e656;
P_0c07e656: /* original 4b0b, guest PC 0x0c07e656 */
if(!s->budget--) { s->failed_pc=0x0c07e656u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e65au;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e65au) { target=s->pc; goto dispatch; }
goto P_0c07e65a;
P_0c07e658: /* original 055e, guest PC 0x0c07e658 */
if(!s->budget--) { s->failed_pc=0x0c07e658u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e65a;
P_0c07e65a: /* original 6403, guest PC 0x0c07e65a */
if(!s->budget--) { s->failed_pc=0x0c07e65au; return 0; }
r[4]=r[0];
goto P_0c07e65c;
P_0c07e65c: /* original 9055, guest PC 0x0c07e65c */
if(!s->budget--) { s->failed_pc=0x0c07e65cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e70au,2);
goto P_0c07e65e;
P_0c07e65e: /* original 03ec, guest PC 0x0c07e65e */
if(!s->budget--) { s->failed_pc=0x0c07e65eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e660;
P_0c07e660: /* original 2338, guest PC 0x0c07e660 */
if(!s->budget--) { s->failed_pc=0x0c07e660u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e662;
P_0c07e662: /* original 8d03, guest PC 0x0c07e662 */
if(!s->budget--) { s->failed_pc=0x0c07e662u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e66c; }
goto P_0c07e666;
P_0c07e664: /* original 7f08, guest PC 0x0c07e664 */
if(!s->budget--) { s->failed_pc=0x0c07e664u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e666;
P_0c07e666: /* original e030, guest PC 0x0c07e666 */
if(!s->budget--) { s->failed_pc=0x0c07e666u; return 0; }
r[0]=0x00000030u;
goto P_0c07e668;
P_0c07e668: /* original a009, guest PC 0x0c07e668 */
if(!s->budget--) { s->failed_pc=0x0c07e668u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e67e;
P_0c07e66a: /* original f4f7, guest PC 0x0c07e66a */
if(!s->budget--) { s->failed_pc=0x0c07e66au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e66c;
P_0c07e66c: /* original 9049, guest PC 0x0c07e66c */
if(!s->budget--) { s->failed_pc=0x0c07e66cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e702u,2);
goto P_0c07e66e;
P_0c07e66e: /* original 02ec, guest PC 0x0c07e66e */
if(!s->budget--) { s->failed_pc=0x0c07e66eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e670;
P_0c07e670: /* original e008, guest PC 0x0c07e670 */
if(!s->budget--) { s->failed_pc=0x0c07e670u; return 0; }
r[0]=0x00000008u;
goto P_0c07e672;
P_0c07e672: /* original 4208, guest PC 0x0c07e672 */
if(!s->budget--) { s->failed_pc=0x0c07e672u; return 0; }
r[2]<<=2;
goto P_0c07e674;
P_0c07e674: /* original 4208, guest PC 0x0c07e674 */
if(!s->budget--) { s->failed_pc=0x0c07e674u; return 0; }
r[2]<<=2;
goto P_0c07e676;
P_0c07e676: /* original 329c, guest PC 0x0c07e676 */
if(!s->budget--) { s->failed_pc=0x0c07e676u; return 0; }
r[2]+=r[9];
goto P_0c07e678;
P_0c07e678: /* original f326, guest PC 0x0c07e678 */
if(!s->budget--) { s->failed_pc=0x0c07e678u; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e67a;
P_0c07e67a: /* original e030, guest PC 0x0c07e67a */
if(!s->budget--) { s->failed_pc=0x0c07e67au; return 0; }
r[0]=0x00000030u;
goto P_0c07e67c;
P_0c07e67c: /* original f437, guest PC 0x0c07e67c */
if(!s->budget--) { s->failed_pc=0x0c07e67cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e67e;
P_0c07e67e: /* original 2fa6, guest PC 0x0c07e67e */
if(!s->budget--) { s->failed_pc=0x0c07e67eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e680;
P_0c07e680: /* original e700, guest PC 0x0c07e680 */
if(!s->budget--) { s->failed_pc=0x0c07e680u; return 0; }
r[7]=0x00000000u;
goto P_0c07e682;
P_0c07e682: /* original 2fc6, guest PC 0x0c07e682 */
if(!s->budget--) { s->failed_pc=0x0c07e682u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e684;
P_0c07e684: /* original 9542, guest PC 0x0c07e684 */
if(!s->budget--) { s->failed_pc=0x0c07e684u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e70cu,2);
goto P_0c07e686;
P_0c07e686: /* original 9442, guest PC 0x0c07e686 */
if(!s->budget--) { s->failed_pc=0x0c07e686u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e70eu,2);
goto P_0c07e688;
P_0c07e688: /* original 4b0b, guest PC 0x0c07e688 */
if(!s->budget--) { s->failed_pc=0x0c07e688u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e68cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e68cu) { target=s->pc; goto dispatch; }
goto P_0c07e68c;
P_0c07e68a: /* original 66d3, guest PC 0x0c07e68a */
if(!s->budget--) { s->failed_pc=0x0c07e68au; return 0; }
r[6]=r[13];
goto P_0c07e68c;
P_0c07e68c: /* original 6403, guest PC 0x0c07e68c */
if(!s->budget--) { s->failed_pc=0x0c07e68cu; return 0; }
r[4]=r[0];
goto P_0c07e68e;
P_0c07e68e: /* original 903c, guest PC 0x0c07e68e */
if(!s->budget--) { s->failed_pc=0x0c07e68eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e70au,2);
goto P_0c07e690;
P_0c07e690: /* original 03ec, guest PC 0x0c07e690 */
if(!s->budget--) { s->failed_pc=0x0c07e690u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e692;
P_0c07e692: /* original 2338, guest PC 0x0c07e692 */
if(!s->budget--) { s->failed_pc=0x0c07e692u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e694;
P_0c07e694: /* original 8d03, guest PC 0x0c07e694 */
if(!s->budget--) { s->failed_pc=0x0c07e694u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e69e; }
goto P_0c07e698;
P_0c07e696: /* original 7f08, guest PC 0x0c07e696 */
if(!s->budget--) { s->failed_pc=0x0c07e696u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e698;
P_0c07e698: /* original e030, guest PC 0x0c07e698 */
if(!s->budget--) { s->failed_pc=0x0c07e698u; return 0; }
r[0]=0x00000030u;
goto P_0c07e69a;
P_0c07e69a: /* original a009, guest PC 0x0c07e69a */
if(!s->budget--) { s->failed_pc=0x0c07e69au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e6b0;
P_0c07e69c: /* original f4f7, guest PC 0x0c07e69c */
if(!s->budget--) { s->failed_pc=0x0c07e69cu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e69e;
P_0c07e69e: /* original 9030, guest PC 0x0c07e69e */
if(!s->budget--) { s->failed_pc=0x0c07e69eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e702u,2);
goto P_0c07e6a0;
P_0c07e6a0: /* original 02ec, guest PC 0x0c07e6a0 */
if(!s->budget--) { s->failed_pc=0x0c07e6a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6a2;
P_0c07e6a2: /* original e00c, guest PC 0x0c07e6a2 */
if(!s->budget--) { s->failed_pc=0x0c07e6a2u; return 0; }
r[0]=0x0000000cu;
goto P_0c07e6a4;
P_0c07e6a4: /* original 4208, guest PC 0x0c07e6a4 */
if(!s->budget--) { s->failed_pc=0x0c07e6a4u; return 0; }
r[2]<<=2;
goto P_0c07e6a6;
P_0c07e6a6: /* original 4208, guest PC 0x0c07e6a6 */
if(!s->budget--) { s->failed_pc=0x0c07e6a6u; return 0; }
r[2]<<=2;
goto P_0c07e6a8;
P_0c07e6a8: /* original 329c, guest PC 0x0c07e6a8 */
if(!s->budget--) { s->failed_pc=0x0c07e6a8u; return 0; }
r[2]+=r[9];
goto P_0c07e6aa;
P_0c07e6aa: /* original f326, guest PC 0x0c07e6aa */
if(!s->budget--) { s->failed_pc=0x0c07e6aau; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c07e6ac;
P_0c07e6ac: /* original e030, guest PC 0x0c07e6ac */
if(!s->budget--) { s->failed_pc=0x0c07e6acu; return 0; }
r[0]=0x00000030u;
goto P_0c07e6ae;
P_0c07e6ae: /* original f437, guest PC 0x0c07e6ae */
if(!s->budget--) { s->failed_pc=0x0c07e6aeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e6b0;
P_0c07e6b0: /* original 902f, guest PC 0x0c07e6b0 */
if(!s->budget--) { s->failed_pc=0x0c07e6b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e712u,2);
goto P_0c07e6b2;
P_0c07e6b2: /* original 942d, guest PC 0x0c07e6b2 */
if(!s->budget--) { s->failed_pc=0x0c07e6b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e710u,2);
goto P_0c07e6b4;
P_0c07e6b4: /* original 03ec, guest PC 0x0c07e6b4 */
if(!s->budget--) { s->failed_pc=0x0c07e6b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6b6;
P_0c07e6b6: /* original 7001, guest PC 0x0c07e6b6 */
if(!s->budget--) { s->failed_pc=0x0c07e6b6u; return 0; }
r[0]+=0x00000001u;
goto P_0c07e6b8;
P_0c07e6b8: /* original 02ec, guest PC 0x0c07e6b8 */
if(!s->budget--) { s->failed_pc=0x0c07e6b8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6ba;
P_0c07e6ba: /* original 3320, guest PC 0x0c07e6ba */
if(!s->budget--) { s->failed_pc=0x0c07e6bau; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07e6bc;
P_0c07e6bc: /* original 890d, guest PC 0x0c07e6bc */
if(!s->budget--) { s->failed_pc=0x0c07e6bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e6da; }
goto P_0c07e6be;
P_0c07e6be: /* original e700, guest PC 0x0c07e6be */
if(!s->budget--) { s->failed_pc=0x0c07e6beu; return 0; }
r[7]=0x00000000u;
goto P_0c07e6c0;
P_0c07e6c0: /* original 66d3, guest PC 0x0c07e6c0 */
if(!s->budget--) { s->failed_pc=0x0c07e6c0u; return 0; }
r[6]=r[13];
goto P_0c07e6c2;
P_0c07e6c2: /* original 2fc6, guest PC 0x0c07e6c2 */
if(!s->budget--) { s->failed_pc=0x0c07e6c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e6c4;
P_0c07e6c4: /* original 9026, guest PC 0x0c07e6c4 */
if(!s->budget--) { s->failed_pc=0x0c07e6c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e714u,2);
goto P_0c07e6c6;
P_0c07e6c6: /* original 05ec, guest PC 0x0c07e6c6 */
if(!s->budget--) { s->failed_pc=0x0c07e6c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6c8;
P_0c07e6c8: /* original d014, guest PC 0x0c07e6c8 */
if(!s->budget--) { s->failed_pc=0x0c07e6c8u; return 0; }
r[0]=read(ram,0x0c07e71cu,4);
goto P_0c07e6ca;
P_0c07e6ca: /* original 4508, guest PC 0x0c07e6ca */
if(!s->budget--) { s->failed_pc=0x0c07e6cau; return 0; }
r[5]<<=2;
goto P_0c07e6cc;
P_0c07e6cc: /* original 480b, guest PC 0x0c07e6cc */
if(!s->budget--) { s->failed_pc=0x0c07e6ccu; return 0; }
target=r[8];
r[16]=code_base|0x0c07e6d0u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e6d0u) { target=s->pc; goto dispatch; }
goto P_0c07e6d0;
P_0c07e6ce: /* original 055e, guest PC 0x0c07e6ce */
if(!s->budget--) { s->failed_pc=0x0c07e6ceu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e6d0;
P_0c07e6d0: /* original 901f, guest PC 0x0c07e6d0 */
if(!s->budget--) { s->failed_pc=0x0c07e6d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e712u,2);
goto P_0c07e6d2;
P_0c07e6d2: /* original 7f04, guest PC 0x0c07e6d2 */
if(!s->budget--) { s->failed_pc=0x0c07e6d2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07e6d4;
P_0c07e6d4: /* original 03ec, guest PC 0x0c07e6d4 */
if(!s->budget--) { s->failed_pc=0x0c07e6d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6d6;
P_0c07e6d6: /* original 7001, guest PC 0x0c07e6d6 */
if(!s->budget--) { s->failed_pc=0x0c07e6d6u; return 0; }
r[0]+=0x00000001u;
goto P_0c07e6d8;
P_0c07e6d8: /* original 0e34, guest PC 0x0c07e6d8 */
if(!s->budget--) { s->failed_pc=0x0c07e6d8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07e6da;
P_0c07e6da: /* original 2fa6, guest PC 0x0c07e6da */
if(!s->budget--) { s->failed_pc=0x0c07e6dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e6dc;
P_0c07e6dc: /* original e700, guest PC 0x0c07e6dc */
if(!s->budget--) { s->failed_pc=0x0c07e6dcu; return 0; }
r[7]=0x00000000u;
goto P_0c07e6de;
P_0c07e6de: /* original 2fc6, guest PC 0x0c07e6de */
if(!s->budget--) { s->failed_pc=0x0c07e6deu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e6e0;
P_0c07e6e0: /* original 66d3, guest PC 0x0c07e6e0 */
if(!s->budget--) { s->failed_pc=0x0c07e6e0u; return 0; }
r[6]=r[13];
goto P_0c07e6e2;
P_0c07e6e2: /* original 9016, guest PC 0x0c07e6e2 */
if(!s->budget--) { s->failed_pc=0x0c07e6e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e712u,2);
goto P_0c07e6e4;
P_0c07e6e4: /* original 9414, guest PC 0x0c07e6e4 */
if(!s->budget--) { s->failed_pc=0x0c07e6e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e710u,2);
goto P_0c07e6e6;
P_0c07e6e6: /* original 05ec, guest PC 0x0c07e6e6 */
if(!s->budget--) { s->failed_pc=0x0c07e6e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6e8;
P_0c07e6e8: /* original d00c, guest PC 0x0c07e6e8 */
if(!s->budget--) { s->failed_pc=0x0c07e6e8u; return 0; }
r[0]=read(ram,0x0c07e71cu,4);
goto P_0c07e6ea;
P_0c07e6ea: /* original 4508, guest PC 0x0c07e6ea */
if(!s->budget--) { s->failed_pc=0x0c07e6eau; return 0; }
r[5]<<=2;
goto P_0c07e6ec;
P_0c07e6ec: /* original 4b0b, guest PC 0x0c07e6ec */
if(!s->budget--) { s->failed_pc=0x0c07e6ecu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e6f0u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e6f0u) { target=s->pc; goto dispatch; }
goto P_0c07e6f0;
P_0c07e6ee: /* original 055e, guest PC 0x0c07e6ee */
if(!s->budget--) { s->failed_pc=0x0c07e6eeu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c07e6f0;
P_0c07e6f0: /* original 6403, guest PC 0x0c07e6f0 */
if(!s->budget--) { s->failed_pc=0x0c07e6f0u; return 0; }
r[4]=r[0];
goto P_0c07e6f2;
P_0c07e6f2: /* original 900a, guest PC 0x0c07e6f2 */
if(!s->budget--) { s->failed_pc=0x0c07e6f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e70au,2);
goto P_0c07e6f4;
P_0c07e6f4: /* original 03ec, guest PC 0x0c07e6f4 */
if(!s->budget--) { s->failed_pc=0x0c07e6f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e6f6;
P_0c07e6f6: /* original 2338, guest PC 0x0c07e6f6 */
if(!s->budget--) { s->failed_pc=0x0c07e6f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07e6f8;
P_0c07e6f8: /* original 8d12, guest PC 0x0c07e6f8 */
if(!s->budget--) { s->failed_pc=0x0c07e6f8u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(cond) { goto P_0c07e720; }
goto P_0c07e6fc;
P_0c07e6fa: /* original 7f08, guest PC 0x0c07e6fa */
if(!s->budget--) { s->failed_pc=0x0c07e6fau; return 0; }
r[15]+=0x00000008u;
goto P_0c07e6fc;
P_0c07e6fc: /* original e030, guest PC 0x0c07e6fc */
if(!s->budget--) { s->failed_pc=0x0c07e6fcu; return 0; }
r[0]=0x00000030u;
goto P_0c07e6fe;
P_0c07e6fe: /* original a018, guest PC 0x0c07e6fe */
if(!s->budget--) { s->failed_pc=0x0c07e6feu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e732;
P_0c07e700: /* original f4f7, guest PC 0x0c07e700 */
if(!s->budget--) { s->failed_pc=0x0c07e700u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07e702u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e702u; return 0; } return 1;
P_0c07e720: /* original 907e, guest PC 0x0c07e720 */
if(!s->budget--) { s->failed_pc=0x0c07e720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e820u,2);
goto P_0c07e722;
P_0c07e722: /* original 02ec, guest PC 0x0c07e722 */
if(!s->budget--) { s->failed_pc=0x0c07e722u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e724;
P_0c07e724: /* original e00c, guest PC 0x0c07e724 */
if(!s->budget--) { s->failed_pc=0x0c07e724u; return 0; }
r[0]=0x0000000cu;
goto P_0c07e726;
P_0c07e726: /* original 4208, guest PC 0x0c07e726 */
if(!s->budget--) { s->failed_pc=0x0c07e726u; return 0; }
r[2]<<=2;
goto P_0c07e728;
P_0c07e728: /* original 4208, guest PC 0x0c07e728 */
if(!s->budget--) { s->failed_pc=0x0c07e728u; return 0; }
r[2]<<=2;
goto P_0c07e72a;
P_0c07e72a: /* original 392c, guest PC 0x0c07e72a */
if(!s->budget--) { s->failed_pc=0x0c07e72au; return 0; }
r[9]+=r[2];
goto P_0c07e72c;
P_0c07e72c: /* original f396, guest PC 0x0c07e72c */
if(!s->budget--) { s->failed_pc=0x0c07e72cu; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c07e72e;
P_0c07e72e: /* original e030, guest PC 0x0c07e72e */
if(!s->budget--) { s->failed_pc=0x0c07e72eu; return 0; }
r[0]=0x00000030u;
goto P_0c07e730;
P_0c07e730: /* original f437, guest PC 0x0c07e730 */
if(!s->budget--) { s->failed_pc=0x0c07e730u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07e732;
P_0c07e732: /* original 51e3, guest PC 0x0c07e732 */
if(!s->budget--) { s->failed_pc=0x0c07e732u; return 0; }
r[1]=read(ram,r[14]+12,4);
goto P_0c07e734;
P_0c07e734: /* original d33f, guest PC 0x0c07e734 */
if(!s->budget--) { s->failed_pc=0x0c07e734u; return 0; }
r[3]=read(ram,0x0c07e834u,4);
goto P_0c07e736;
P_0c07e736: /* original 611b, guest PC 0x0c07e736 */
if(!s->budget--) { s->failed_pc=0x0c07e736u; return 0; }
r[1]=0u-r[1];
goto P_0c07e738;
P_0c07e738: /* original 430b, guest PC 0x0c07e738 */
if(!s->budget--) { s->failed_pc=0x0c07e738u; return 0; }
target=r[3];
r[16]=code_base|0x0c07e73cu;
r[0]=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e73cu) { target=s->pc; goto dispatch; }
goto P_0c07e73c;
P_0c07e73a: /* original e064, guest PC 0x0c07e73a */
if(!s->budget--) { s->failed_pc=0x0c07e73au; return 0; }
r[0]=0x00000064u;
goto P_0c07e73c;
P_0c07e73c: /* original 405a, guest PC 0x0c07e73c */
if(!s->budget--) { s->failed_pc=0x0c07e73cu; return 0; }
r[53]=r[0];
goto P_0c07e73e;
P_0c07e73e: /* original c73e, guest PC 0x0c07e73e */
if(!s->budget--) { s->failed_pc=0x0c07e73eu; return 0; }
r[0]=code_base|0x0007e838u;
goto P_0c07e740;
P_0c07e740: /* original f208, guest PC 0x0c07e740 */
if(!s->budget--) { s->failed_pc=0x0c07e740u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07e742;
P_0c07e742: /* original f49d, guest PC 0x0c07e742 */
if(!s->budget--) { s->failed_pc=0x0c07e742u; return 0; }
fr[4]=0x3f800000u;
goto P_0c07e744;
P_0c07e744: /* original f32d, guest PC 0x0c07e744 */
if(!s->budget--) { s->failed_pc=0x0c07e744u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07e746;
P_0c07e746: /* original ff3c, guest PC 0x0c07e746 */
if(!s->budget--) { s->failed_pc=0x0c07e746u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c07e748;
P_0c07e748: /* original ff22, guest PC 0x0c07e748 */
if(!s->budget--) { s->failed_pc=0x0c07e748u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'*');
goto P_0c07e74a;
P_0c07e74a: /* original f4f5, guest PC 0x0c07e74a */
if(!s->budget--) { s->failed_pc=0x0c07e74au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c07e74c;
P_0c07e74c: /* original 8903, guest PC 0x0c07e74c */
if(!s->budget--) { s->failed_pc=0x0c07e74cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e756; }
goto P_0c07e74e;
P_0c07e74e: /* original c73b, guest PC 0x0c07e74e */
if(!s->budget--) { s->failed_pc=0x0c07e74eu; return 0; }
r[0]=code_base|0x0007e83cu;
goto P_0c07e750;
P_0c07e750: /* original f3fc, guest PC 0x0c07e750 */
if(!s->budget--) { s->failed_pc=0x0c07e750u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c07e752;
P_0c07e752: /* original ff08, guest PC 0x0c07e752 */
if(!s->budget--) { s->failed_pc=0x0c07e752u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c07e754;
P_0c07e754: /* original ff31, guest PC 0x0c07e754 */
if(!s->budget--) { s->failed_pc=0x0c07e754u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c07e756;
P_0c07e756: /* original c73a, guest PC 0x0c07e756 */
if(!s->budget--) { s->failed_pc=0x0c07e756u; return 0; }
r[0]=code_base|0x0007e840u;
goto P_0c07e758;
P_0c07e758: /* original f308, guest PC 0x0c07e758 */
if(!s->budget--) { s->failed_pc=0x0c07e758u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07e75a;
P_0c07e75a: /* original ff30, guest PC 0x0c07e75a */
if(!s->budget--) { s->failed_pc=0x0c07e75au; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c07e75c;
P_0c07e75c: /* original ff45, guest PC 0x0c07e75c */
if(!s->budget--) { s->failed_pc=0x0c07e75cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c07e75e;
P_0c07e75e: /* original 8f01, guest PC 0x0c07e75e */
if(!s->budget--) { s->failed_pc=0x0c07e75eu; return 0; }
cond=r[17]&1u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c07e764; }
goto P_0c07e762;
P_0c07e760: /* original 2fa6, guest PC 0x0c07e760 */
if(!s->budget--) { s->failed_pc=0x0c07e760u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e762;
P_0c07e762: /* original ff4c, guest PC 0x0c07e762 */
if(!s->budget--) { s->failed_pc=0x0c07e762u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c07e764;
P_0c07e764: /* original 2fc6, guest PC 0x0c07e764 */
if(!s->budget--) { s->failed_pc=0x0c07e764u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e766;
P_0c07e766: /* original e700, guest PC 0x0c07e766 */
if(!s->budget--) { s->failed_pc=0x0c07e766u; return 0; }
r[7]=0x00000000u;
goto P_0c07e768;
P_0c07e768: /* original 955b, guest PC 0x0c07e768 */
if(!s->budget--) { s->failed_pc=0x0c07e768u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e822u,2);
goto P_0c07e76a;
P_0c07e76a: /* original 945b, guest PC 0x0c07e76a */
if(!s->budget--) { s->failed_pc=0x0c07e76au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e824u,2);
goto P_0c07e76c;
P_0c07e76c: /* original 4b0b, guest PC 0x0c07e76c */
if(!s->budget--) { s->failed_pc=0x0c07e76cu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e770u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e770u) { target=s->pc; goto dispatch; }
goto P_0c07e770;
P_0c07e76e: /* original 66d3, guest PC 0x0c07e76e */
if(!s->budget--) { s->failed_pc=0x0c07e76eu; return 0; }
r[6]=r[13];
goto P_0c07e770;
P_0c07e770: /* original 6403, guest PC 0x0c07e770 */
if(!s->budget--) { s->failed_pc=0x0c07e770u; return 0; }
r[4]=r[0];
goto P_0c07e772;
P_0c07e772: /* original e030, guest PC 0x0c07e772 */
if(!s->budget--) { s->failed_pc=0x0c07e772u; return 0; }
r[0]=0x00000030u;
goto P_0c07e774;
P_0c07e774: /* original 7f08, guest PC 0x0c07e774 */
if(!s->budget--) { s->failed_pc=0x0c07e774u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e776;
P_0c07e776: /* original a026, guest PC 0x0c07e776 */
if(!s->budget--) { s->failed_pc=0x0c07e776u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e7c6;
P_0c07e778: /* original f4f7, guest PC 0x0c07e778 */
if(!s->budget--) { s->failed_pc=0x0c07e778u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07e77a;
P_0c07e77a: /* original 6453, guest PC 0x0c07e77a */
if(!s->budget--) { s->failed_pc=0x0c07e77au; return 0; }
r[4]=r[5];
goto P_0c07e77c;
P_0c07e77c: /* original e63e, guest PC 0x0c07e77c */
if(!s->budget--) { s->failed_pc=0x0c07e77cu; return 0; }
r[6]=0x0000003eu;
goto P_0c07e77e;
P_0c07e77e: /* original e730, guest PC 0x0c07e77e */
if(!s->budget--) { s->failed_pc=0x0c07e77eu; return 0; }
r[7]=0x00000030u;
goto P_0c07e780;
P_0c07e780: /* original 2fc6, guest PC 0x0c07e780 */
if(!s->budget--) { s->failed_pc=0x0c07e780u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e782;
P_0c07e782: /* original d130, guest PC 0x0c07e782 */
if(!s->budget--) { s->failed_pc=0x0c07e782u; return 0; }
r[1]=read(ram,0x0c07e844u,4);
goto P_0c07e784;
P_0c07e784: /* original 742c, guest PC 0x0c07e784 */
if(!s->budget--) { s->failed_pc=0x0c07e784u; return 0; }
r[4]+=0x0000002cu;
goto P_0c07e786;
P_0c07e786: /* original 410b, guest PC 0x0c07e786 */
if(!s->budget--) { s->failed_pc=0x0c07e786u; return 0; }
target=r[1];
r[16]=code_base|0x0c07e78au;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e78au) { target=s->pc; goto dispatch; }
goto P_0c07e78a;
P_0c07e788: /* original e500, guest PC 0x0c07e788 */
if(!s->budget--) { s->failed_pc=0x0c07e788u; return 0; }
r[5]=0x00000000u;
goto P_0c07e78a;
P_0c07e78a: /* original a01c, guest PC 0x0c07e78a */
if(!s->budget--) { s->failed_pc=0x0c07e78au; return 0; }
r[15]+=0x00000004u;
goto P_0c07e7c6;
P_0c07e78c: /* original 7f04, guest PC 0x0c07e78c */
if(!s->budget--) { s->failed_pc=0x0c07e78cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07e78e;
P_0c07e78e: /* original 2668, guest PC 0x0c07e78e */
if(!s->budget--) { s->failed_pc=0x0c07e78eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c07e790;
P_0c07e790: /* original 8914, guest PC 0x0c07e790 */
if(!s->budget--) { s->failed_pc=0x0c07e790u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e7bc; }
goto P_0c07e792;
P_0c07e792: /* original 9048, guest PC 0x0c07e792 */
if(!s->budget--) { s->failed_pc=0x0c07e792u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e826u,2);
goto P_0c07e794;
P_0c07e794: /* original 00ec, guest PC 0x0c07e794 */
if(!s->budget--) { s->failed_pc=0x0c07e794u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e796;
P_0c07e796: /* original 2008, guest PC 0x0c07e796 */
if(!s->budget--) { s->failed_pc=0x0c07e796u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07e798;
P_0c07e798: /* original 8910, guest PC 0x0c07e798 */
if(!s->budget--) { s->failed_pc=0x0c07e798u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e7bc; }
goto P_0c07e79a;
P_0c07e79a: /* original 6e53, guest PC 0x0c07e79a */
if(!s->budget--) { s->failed_pc=0x0c07e79au; return 0; }
r[14]=r[5];
goto P_0c07e79c;
P_0c07e79c: /* original e553, guest PC 0x0c07e79c */
if(!s->budget--) { s->failed_pc=0x0c07e79cu; return 0; }
r[5]=0x00000053u;
goto P_0c07e79e;
P_0c07e79e: /* original 4b0b, guest PC 0x0c07e79e */
if(!s->budget--) { s->failed_pc=0x0c07e79eu; return 0; }
target=r[11];
r[16]=code_base|0x0c07e7a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e7a2u) { target=s->pc; goto dispatch; }
goto P_0c07e7a2;
P_0c07e7a0: /* original 64e3, guest PC 0x0c07e7a0 */
if(!s->budget--) { s->failed_pc=0x0c07e7a0u; return 0; }
r[4]=r[14];
goto P_0c07e7a2;
P_0c07e7a2: /* original d32a, guest PC 0x0c07e7a2 */
if(!s->budget--) { s->failed_pc=0x0c07e7a2u; return 0; }
r[3]=read(ram,0x0c07e84cu,4);
goto P_0c07e7a4;
P_0c07e7a4: /* original 9440, guest PC 0x0c07e7a4 */
if(!s->budget--) { s->failed_pc=0x0c07e7a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e828u,2);
goto P_0c07e7a6;
P_0c07e7a6: /* original d528, guest PC 0x0c07e7a6 */
if(!s->budget--) { s->failed_pc=0x0c07e7a6u; return 0; }
r[5]=read(ram,0x0c07e848u,4);
goto P_0c07e7a8;
P_0c07e7a8: /* original 430b, guest PC 0x0c07e7a8 */
if(!s->budget--) { s->failed_pc=0x0c07e7a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07e7acu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e7acu) { target=s->pc; goto dispatch; }
goto P_0c07e7ac;
P_0c07e7aa: /* original e601, guest PC 0x0c07e7aa */
if(!s->budget--) { s->failed_pc=0x0c07e7aau; return 0; }
r[6]=0x00000001u;
goto P_0c07e7ac;
P_0c07e7ac: /* original d227, guest PC 0x0c07e7ac */
if(!s->budget--) { s->failed_pc=0x0c07e7acu; return 0; }
r[2]=read(ram,0x0c07e84cu,4);
goto P_0c07e7ae;
P_0c07e7ae: /* original 943c, guest PC 0x0c07e7ae */
if(!s->budget--) { s->failed_pc=0x0c07e7aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e82au,2);
goto P_0c07e7b0;
P_0c07e7b0: /* original d527, guest PC 0x0c07e7b0 */
if(!s->budget--) { s->failed_pc=0x0c07e7b0u; return 0; }
r[5]=read(ram,0x0c07e850u,4);
goto P_0c07e7b2;
P_0c07e7b2: /* original 420b, guest PC 0x0c07e7b2 */
if(!s->budget--) { s->failed_pc=0x0c07e7b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c07e7b6u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e7b6u) { target=s->pc; goto dispatch; }
goto P_0c07e7b6;
P_0c07e7b4: /* original e601, guest PC 0x0c07e7b4 */
if(!s->budget--) { s->failed_pc=0x0c07e7b4u; return 0; }
r[6]=0x00000001u;
goto P_0c07e7b6;
P_0c07e7b6: /* original 9539, guest PC 0x0c07e7b6 */
if(!s->budget--) { s->failed_pc=0x0c07e7b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e82cu,2);
goto P_0c07e7b8;
P_0c07e7b8: /* original 4b0b, guest PC 0x0c07e7b8 */
if(!s->budget--) { s->failed_pc=0x0c07e7b8u; return 0; }
target=r[11];
r[16]=code_base|0x0c07e7bcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e7bcu) { target=s->pc; goto dispatch; }
goto P_0c07e7bc;
P_0c07e7ba: /* original 64e3, guest PC 0x0c07e7ba */
if(!s->budget--) { s->failed_pc=0x0c07e7bau; return 0; }
r[4]=r[14];
goto P_0c07e7bc;
P_0c07e7bc: /* original d325, guest PC 0x0c07e7bc */
if(!s->budget--) { s->failed_pc=0x0c07e7bcu; return 0; }
r[3]=read(ram,0x0c07e854u,4);
goto P_0c07e7be;
P_0c07e7be: /* original 9236, guest PC 0x0c07e7be */
if(!s->budget--) { s->failed_pc=0x0c07e7beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e82eu,2);
goto P_0c07e7c0;
P_0c07e7c0: /* original 6132, guest PC 0x0c07e7c0 */
if(!s->budget--) { s->failed_pc=0x0c07e7c0u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07e7c2;
P_0c07e7c2: /* original 212b, guest PC 0x0c07e7c2 */
if(!s->budget--) { s->failed_pc=0x0c07e7c2u; return 0; }
r[1]|=r[2];
goto P_0c07e7c4;
P_0c07e7c4: /* original 2312, guest PC 0x0c07e7c4 */
if(!s->budget--) { s->failed_pc=0x0c07e7c4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07e7c6;
P_0c07e7c6: /* original d424, guest PC 0x0c07e7c6 */
if(!s->budget--) { s->failed_pc=0x0c07e7c6u; return 0; }
r[4]=read(ram,0x0c07e858u,4);
goto P_0c07e7c8;
P_0c07e7c8: /* original e029, guest PC 0x0c07e7c8 */
if(!s->budget--) { s->failed_pc=0x0c07e7c8u; return 0; }
r[0]=0x00000029u;
goto P_0c07e7ca;
P_0c07e7ca: /* original dd24, guest PC 0x0c07e7ca */
if(!s->budget--) { s->failed_pc=0x0c07e7cau; return 0; }
r[13]=read(ram,0x0c07e85cu,4);
goto P_0c07e7cc;
P_0c07e7cc: /* original 054c, guest PC 0x0c07e7cc */
if(!s->budget--) { s->failed_pc=0x0c07e7ccu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07e7ce;
P_0c07e7ce: /* original 7069, guest PC 0x0c07e7ce */
if(!s->budget--) { s->failed_pc=0x0c07e7ceu; return 0; }
r[0]+=0x00000069u;
goto P_0c07e7d0;
P_0c07e7d0: /* original 064c, guest PC 0x0c07e7d0 */
if(!s->budget--) { s->failed_pc=0x0c07e7d0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07e7d2;
P_0c07e7d2: /* original 605e, guest PC 0x0c07e7d2 */
if(!s->budget--) { s->failed_pc=0x0c07e7d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07e7d4;
P_0c07e7d4: /* original 8803, guest PC 0x0c07e7d4 */
if(!s->budget--) { s->failed_pc=0x0c07e7d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07e7d6;
P_0c07e7d6: /* original 8d0c, guest PC 0x0c07e7d6 */
if(!s->budget--) { s->failed_pc=0x0c07e7d6u; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[4]+8,4);
if(cond) { goto P_0c07e7f2; }
goto P_0c07e7da;
P_0c07e7d8: /* original 5e42, guest PC 0x0c07e7d8 */
if(!s->budget--) { s->failed_pc=0x0c07e7d8u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c07e7da;
P_0c07e7da: /* original 646e, guest PC 0x0c07e7da */
if(!s->budget--) { s->failed_pc=0x0c07e7dau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c07e7dc;
P_0c07e7dc: /* original 9526, guest PC 0x0c07e7dc */
if(!s->budget--) { s->failed_pc=0x0c07e7dcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e82cu,2);
goto P_0c07e7de;
P_0c07e7de: /* original 6043, guest PC 0x0c07e7de */
if(!s->budget--) { s->failed_pc=0x0c07e7deu; return 0; }
r[0]=r[4];
goto P_0c07e7e0;
P_0c07e7e0: /* original 8801, guest PC 0x0c07e7e0 */
if(!s->budget--) { s->failed_pc=0x0c07e7e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07e7e2;
P_0c07e7e2: /* original 8900, guest PC 0x0c07e7e2 */
if(!s->budget--) { s->failed_pc=0x0c07e7e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e7e6; }
goto P_0c07e7e4;
P_0c07e7e4: /* original 9524, guest PC 0x0c07e7e4 */
if(!s->budget--) { s->failed_pc=0x0c07e7e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e830u,2);
goto P_0c07e7e6;
P_0c07e7e6: /* original 25e8, guest PC 0x0c07e7e6 */
if(!s->budget--) { s->failed_pc=0x0c07e7e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[14])==0)!=0);
goto P_0c07e7e8;
P_0c07e7e8: /* original 890c, guest PC 0x0c07e7e8 */
if(!s->budget--) { s->failed_pc=0x0c07e7e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07e804; }
goto P_0c07e7ea;
P_0c07e7ea: /* original 4d0b, guest PC 0x0c07e7ea */
if(!s->budget--) { s->failed_pc=0x0c07e7eau; return 0; }
target=r[13];
r[16]=code_base|0x0c07e7eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e7eeu) { target=s->pc; goto dispatch; }
goto P_0c07e7ee;
P_0c07e7ec: /* original 0009, guest PC 0x0c07e7ec */
if(!s->budget--) { s->failed_pc=0x0c07e7ecu; return 0; }
goto P_0c07e7ee;
P_0c07e7ee: /* original a009, guest PC 0x0c07e7ee */
if(!s->budget--) { s->failed_pc=0x0c07e7eeu; return 0; }
goto P_0c07e804;
P_0c07e7f0: /* original 0009, guest PC 0x0c07e7f0 */
if(!s->budget--) { s->failed_pc=0x0c07e7f0u; return 0; }
goto P_0c07e7f2;
P_0c07e7f2: /* original 951e, guest PC 0x0c07e7f2 */
if(!s->budget--) { s->failed_pc=0x0c07e7f2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e832u,2);
goto P_0c07e7f4;
P_0c07e7f4: /* original 64e3, guest PC 0x0c07e7f4 */
if(!s->budget--) { s->failed_pc=0x0c07e7f4u; return 0; }
r[4]=r[14];
goto P_0c07e7f6;
P_0c07e7f6: /* original 2459, guest PC 0x0c07e7f6 */
if(!s->budget--) { s->failed_pc=0x0c07e7f6u; return 0; }
r[4]&=r[5];
goto P_0c07e7f8;
P_0c07e7f8: /* original 3540, guest PC 0x0c07e7f8 */
if(!s->budget--) { s->failed_pc=0x0c07e7f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c07e7fa;
P_0c07e7fa: /* original 8b03, guest PC 0x0c07e7fa */
if(!s->budget--) { s->failed_pc=0x0c07e7fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07e804; }
goto P_0c07e7fc;
P_0c07e7fc: /* original 4d0b, guest PC 0x0c07e7fc */
if(!s->budget--) { s->failed_pc=0x0c07e7fcu; return 0; }
target=r[13];
r[16]=code_base|0x0c07e800u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e800u) { target=s->pc; goto dispatch; }
goto P_0c07e800;
P_0c07e7fe: /* original e401, guest PC 0x0c07e7fe */
if(!s->budget--) { s->failed_pc=0x0c07e7feu; return 0; }
r[4]=0x00000001u;
goto P_0c07e800;
P_0c07e800: /* original 4d0b, guest PC 0x0c07e800 */
if(!s->budget--) { s->failed_pc=0x0c07e800u; return 0; }
target=r[13];
r[16]=code_base|0x0c07e804u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07e804u) { target=s->pc; goto dispatch; }
goto P_0c07e804;
P_0c07e802: /* original e402, guest PC 0x0c07e802 */
if(!s->budget--) { s->failed_pc=0x0c07e802u; return 0; }
r[4]=0x00000002u;
goto P_0c07e804;
P_0c07e804: /* original 64f2, guest PC 0x0c07e804 */
if(!s->budget--) { s->failed_pc=0x0c07e804u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07e806;
P_0c07e806: /* original 55f1, guest PC 0x0c07e806 */
if(!s->budget--) { s->failed_pc=0x0c07e806u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07e808;
P_0c07e808: /* original 7f08, guest PC 0x0c07e808 */
if(!s->budget--) { s->failed_pc=0x0c07e808u; return 0; }
r[15]+=0x00000008u;
goto P_0c07e80a;
P_0c07e80a: /* original 4f26, guest PC 0x0c07e80a */
if(!s->budget--) { s->failed_pc=0x0c07e80au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e80c;
P_0c07e80c: /* original d314, guest PC 0x0c07e80c */
if(!s->budget--) { s->failed_pc=0x0c07e80cu; return 0; }
r[3]=read(ram,0x0c07e860u,4);
goto P_0c07e80e;
P_0c07e80e: /* original fff9, guest PC 0x0c07e80e */
if(!s->budget--) { s->failed_pc=0x0c07e80eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07e810;
P_0c07e810: /* original 68f6, guest PC 0x0c07e810 */
if(!s->budget--) { s->failed_pc=0x0c07e810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07e812;
P_0c07e812: /* original 69f6, guest PC 0x0c07e812 */
if(!s->budget--) { s->failed_pc=0x0c07e812u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07e814;
P_0c07e814: /* original 6af6, guest PC 0x0c07e814 */
if(!s->budget--) { s->failed_pc=0x0c07e814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07e816;
P_0c07e816: /* original 6bf6, guest PC 0x0c07e816 */
if(!s->budget--) { s->failed_pc=0x0c07e816u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07e818;
P_0c07e818: /* original 6cf6, guest PC 0x0c07e818 */
if(!s->budget--) { s->failed_pc=0x0c07e818u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07e81a;
P_0c07e81a: /* original 6df6, guest PC 0x0c07e81a */
if(!s->budget--) { s->failed_pc=0x0c07e81au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07e81c;
P_0c07e81c: /* original 432b, guest PC 0x0c07e81c */
if(!s->budget--) { s->failed_pc=0x0c07e81cu; return 0; }
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
P_0c07e81e: /* original 6ef6, guest PC 0x0c07e81e */
if(!s->budget--) { s->failed_pc=0x0c07e81eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07e820u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e820u; return 0; } return 1;
P_0c080920: /* original 2fe6, guest PC 0x0c080920 */
if(!s->budget--) { s->failed_pc=0x0c080920u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080922;
P_0c080922: /* original 2fd6, guest PC 0x0c080922 */
if(!s->budget--) { s->failed_pc=0x0c080922u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080924;
P_0c080924: /* original 2fc6, guest PC 0x0c080924 */
if(!s->budget--) { s->failed_pc=0x0c080924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080926;
P_0c080926: /* original 2fb6, guest PC 0x0c080926 */
if(!s->budget--) { s->failed_pc=0x0c080926u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080928;
P_0c080928: /* original 2fa6, guest PC 0x0c080928 */
if(!s->budget--) { s->failed_pc=0x0c080928u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092a;
P_0c08092a: /* original 2f96, guest PC 0x0c08092a */
if(!s->budget--) { s->failed_pc=0x0c08092au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092c;
P_0c08092c: /* original 2f86, guest PC 0x0c08092c */
if(!s->budget--) { s->failed_pc=0x0c08092cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08092e;
P_0c08092e: /* original d44d, guest PC 0x0c08092e */
if(!s->budget--) { s->failed_pc=0x0c08092eu; return 0; }
r[4]=read(ram,0x0c080a64u,4);
goto P_0c080930;
P_0c080930: /* original 4f22, guest PC 0x0c080930 */
if(!s->budget--) { s->failed_pc=0x0c080930u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080932;
P_0c080932: /* original d54a, guest PC 0x0c080932 */
if(!s->budget--) { s->failed_pc=0x0c080932u; return 0; }
r[5]=read(ram,0x0c080a5cu,4);
goto P_0c080934;
P_0c080934: /* original 5344, guest PC 0x0c080934 */
if(!s->budget--) { s->failed_pc=0x0c080934u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c080936;
P_0c080936: /* original 6d53, guest PC 0x0c080936 */
if(!s->budget--) { s->failed_pc=0x0c080936u; return 0; }
r[13]=r[5];
goto P_0c080938;
P_0c080938: /* original 7fe0, guest PC 0x0c080938 */
if(!s->budget--) { s->failed_pc=0x0c080938u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08093a;
P_0c08093a: /* original dc49, guest PC 0x0c08093a */
if(!s->budget--) { s->failed_pc=0x0c08093au; return 0; }
r[12]=read(ram,0x0c080a60u,4);
goto P_0c08093c;
P_0c08093c: /* original 1f37, guest PC 0x0c08093c */
if(!s->budget--) { s->failed_pc=0x0c08093cu; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c08093e;
P_0c08093e: /* original e304, guest PC 0x0c08093e */
if(!s->budget--) { s->failed_pc=0x0c08093eu; return 0; }
r[3]=0x00000004u;
goto P_0c080940;
P_0c080940: /* original 5245, guest PC 0x0c080940 */
if(!s->budget--) { s->failed_pc=0x0c080940u; return 0; }
r[2]=read(ram,r[4]+20,4);
goto P_0c080942;
P_0c080942: /* original 1f26, guest PC 0x0c080942 */
if(!s->budget--) { s->failed_pc=0x0c080942u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c080944;
P_0c080944: /* original 54d2, guest PC 0x0c080944 */
if(!s->budget--) { s->failed_pc=0x0c080944u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c080946;
P_0c080946: /* original da49, guest PC 0x0c080946 */
if(!s->budget--) { s->failed_pc=0x0c080946u; return 0; }
r[10]=read(ram,0x0c080a6cu,4);
goto P_0c080948;
P_0c080948: /* original db49, guest PC 0x0c080948 */
if(!s->budget--) { s->failed_pc=0x0c080948u; return 0; }
r[11]=read(ram,0x0c080a70u,4);
goto P_0c08094a;
P_0c08094a: /* original 2438, guest PC 0x0c08094a */
if(!s->budget--) { s->failed_pc=0x0c08094au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08094c;
P_0c08094c: /* original d946, guest PC 0x0c08094c */
if(!s->budget--) { s->failed_pc=0x0c08094cu; return 0; }
r[9]=read(ram,0x0c080a68u,4);
goto P_0c08094e;
P_0c08094e: /* original 8f02, guest PC 0x0c08094e */
if(!s->budget--) { s->failed_pc=0x0c08094eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c080956; }
goto P_0c080952;
P_0c080950: /* original ee00, guest PC 0x0c080950 */
if(!s->budget--) { s->failed_pc=0x0c080950u; return 0; }
r[14]=0x00000000u;
goto P_0c080952;
P_0c080952: /* original a08f, guest PC 0x0c080952 */
if(!s->budget--) { s->failed_pc=0x0c080952u; return 0; }
goto P_0c080a74;
P_0c080954: /* original 0009, guest PC 0x0c080954 */
if(!s->budget--) { s->failed_pc=0x0c080954u; return 0; }
goto P_0c080956;
P_0c080956: /* original 907e, guest PC 0x0c080956 */
if(!s->budget--) { s->failed_pc=0x0c080956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c080958;
P_0c080958: /* original 68e3, guest PC 0x0c080958 */
if(!s->budget--) { s->failed_pc=0x0c080958u; return 0; }
r[8]=r[14];
goto P_0c08095a;
P_0c08095a: /* original 04dc, guest PC 0x0c08095a */
if(!s->budget--) { s->failed_pc=0x0c08095au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08095c;
P_0c08095c: /* original e01b, guest PC 0x0c08095c */
if(!s->budget--) { s->failed_pc=0x0c08095cu; return 0; }
r[0]=0x0000001bu;
goto P_0c08095e;
P_0c08095e: /* original 02dc, guest PC 0x0c08095e */
if(!s->budget--) { s->failed_pc=0x0c08095eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c080960;
P_0c080960: /* original e014, guest PC 0x0c080960 */
if(!s->budget--) { s->failed_pc=0x0c080960u; return 0; }
r[0]=0x00000014u;
goto P_0c080962;
P_0c080962: /* original 0f24, guest PC 0x0c080962 */
if(!s->budget--) { s->failed_pc=0x0c080962u; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c080964;
P_0c080964: /* original 6243, guest PC 0x0c080964 */
if(!s->budget--) { s->failed_pc=0x0c080964u; return 0; }
r[2]=r[4];
goto P_0c080966;
P_0c080966: /* original 61b2, guest PC 0x0c080966 */
if(!s->budget--) { s->failed_pc=0x0c080966u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c080968;
P_0c080968: /* original 4215, guest PC 0x0c080968 */
if(!s->budget--) { s->failed_pc=0x0c080968u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c08096a;
P_0c08096a: /* original 7106, guest PC 0x0c08096a */
if(!s->budget--) { s->failed_pc=0x0c08096au; return 0; }
r[1]+=0x00000006u;
goto P_0c08096c;
P_0c08096c: /* original 2f10, guest PC 0x0c08096c */
if(!s->budget--) { s->failed_pc=0x0c08096cu; return 0; }
write(ram,r[15],r[1],1);
goto P_0c08096e;
P_0c08096e: /* original 8f2f, guest PC 0x0c08096e */
if(!s->budget--) { s->failed_pc=0x0c08096eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(!cond) { goto P_0c0809d0; }
goto P_0c080972;
P_0c080970: /* original 1f41, guest PC 0x0c080970 */
if(!s->budget--) { s->failed_pc=0x0c080970u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c080972;
P_0c080972: /* original 9371, guest PC 0x0c080972 */
if(!s->budget--) { s->failed_pc=0x0c080972u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a58u,2);
goto P_0c080974;
P_0c080974: /* original 648e, guest PC 0x0c080974 */
if(!s->budget--) { s->failed_pc=0x0c080974u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080976;
P_0c080976: /* original 33dc, guest PC 0x0c080976 */
if(!s->budget--) { s->failed_pc=0x0c080976u; return 0; }
r[3]+=r[13];
goto P_0c080978;
P_0c080978: /* original 343c, guest PC 0x0c080978 */
if(!s->budget--) { s->failed_pc=0x0c080978u; return 0; }
r[4]+=r[3];
goto P_0c08097a;
P_0c08097a: /* original 6440, guest PC 0x0c08097a */
if(!s->budget--) { s->failed_pc=0x0c08097au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c08097c;
P_0c08097c: /* original e30d, guest PC 0x0c08097c */
if(!s->budget--) { s->failed_pc=0x0c08097cu; return 0; }
r[3]=0x0000000du;
goto P_0c08097e;
P_0c08097e: /* original 3433, guest PC 0x0c08097e */
if(!s->budget--) { s->failed_pc=0x0c08097eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c080980;
P_0c080980: /* original 8b00, guest PC 0x0c080980 */
if(!s->budget--) { s->failed_pc=0x0c080980u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080984; }
goto P_0c080982;
P_0c080982: /* original 3438, guest PC 0x0c080982 */
if(!s->budget--) { s->failed_pc=0x0c080982u; return 0; }
r[4]-=r[3];
goto P_0c080984;
P_0c080984: /* original 604e, guest PC 0x0c080984 */
if(!s->budget--) { s->failed_pc=0x0c080984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080986;
P_0c080986: /* original 4000, guest PC 0x0c080986 */
if(!s->budget--) { s->failed_pc=0x0c080986u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080988;
P_0c080988: /* original 00ad, guest PC 0x0c080988 */
if(!s->budget--) { s->failed_pc=0x0c080988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c08098a;
P_0c08098a: /* original e307, guest PC 0x0c08098a */
if(!s->budget--) { s->failed_pc=0x0c08098au; return 0; }
r[3]=0x00000007u;
goto P_0c08098c;
P_0c08098c: /* original 628e, guest PC 0x0c08098c */
if(!s->budget--) { s->failed_pc=0x0c08098cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c08098e;
P_0c08098e: /* original 81f6, guest PC 0x0c08098e */
if(!s->budget--) { s->failed_pc=0x0c08098eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c080990;
P_0c080990: /* original 60f0, guest PC 0x0c080990 */
if(!s->budget--) { s->failed_pc=0x0c080990u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c080992;
P_0c080992: /* original 403c, guest PC 0x0c080992 */
if(!s->budget--) { s->failed_pc=0x0c080992u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080994;
P_0c080994: /* original cb04, guest PC 0x0c080994 */
if(!s->budget--) { s->failed_pc=0x0c080994u; return 0; }
r[0]|=4u;
goto P_0c080996;
P_0c080996: /* original 1f04, guest PC 0x0c080996 */
if(!s->budget--) { s->failed_pc=0x0c080996u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080998;
P_0c080998: /* original 60e3, guest PC 0x0c080998 */
if(!s->budget--) { s->failed_pc=0x0c080998u; return 0; }
r[0]=r[14];
goto P_0c08099a;
P_0c08099a: /* original 80f8, guest PC 0x0c08099a */
if(!s->budget--) { s->failed_pc=0x0c08099au; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c08099c;
P_0c08099c: /* original e014, guest PC 0x0c08099c */
if(!s->budget--) { s->failed_pc=0x0c08099cu; return 0; }
r[0]=0x00000014u;
goto P_0c08099e;
P_0c08099e: /* original 01fc, guest PC 0x0c08099e */
if(!s->budget--) { s->failed_pc=0x0c08099eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0809a0;
P_0c0809a0: /* original 3213, guest PC 0x0c0809a0 */
if(!s->budget--) { s->failed_pc=0x0c0809a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809a2;
P_0c0809a2: /* original 8901, guest PC 0x0c0809a2 */
if(!s->budget--) { s->failed_pc=0x0c0809a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0809a8; }
goto P_0c0809a4;
P_0c0809a4: /* original e001, guest PC 0x0c0809a4 */
if(!s->budget--) { s->failed_pc=0x0c0809a4u; return 0; }
r[0]=0x00000001u;
goto P_0c0809a6;
P_0c0809a6: /* original 80f8, guest PC 0x0c0809a6 */
if(!s->budget--) { s->failed_pc=0x0c0809a6u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c0809a8;
P_0c0809a8: /* original 2fe6, guest PC 0x0c0809a8 */
if(!s->budget--) { s->failed_pc=0x0c0809a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0809aa;
P_0c0809aa: /* original 66c3, guest PC 0x0c0809aa */
if(!s->budget--) { s->failed_pc=0x0c0809aau; return 0; }
r[6]=r[12];
goto P_0c0809ac;
P_0c0809ac: /* original 85f8, guest PC 0x0c0809ac */
if(!s->budget--) { s->failed_pc=0x0c0809acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0809ae;
P_0c0809ae: /* original e700, guest PC 0x0c0809ae */
if(!s->budget--) { s->failed_pc=0x0c0809aeu; return 0; }
r[7]=0x00000000u;
goto P_0c0809b0;
P_0c0809b0: /* original 6303, guest PC 0x0c0809b0 */
if(!s->budget--) { s->failed_pc=0x0c0809b0u; return 0; }
r[3]=r[0];
goto P_0c0809b2;
P_0c0809b2: /* original 84fc, guest PC 0x0c0809b2 */
if(!s->budget--) { s->failed_pc=0x0c0809b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c0809b4;
P_0c0809b4: /* original 3308, guest PC 0x0c0809b4 */
if(!s->budget--) { s->failed_pc=0x0c0809b4u; return 0; }
r[3]-=r[0];
goto P_0c0809b6;
P_0c0809b6: /* original 6533, guest PC 0x0c0809b6 */
if(!s->budget--) { s->failed_pc=0x0c0809b6u; return 0; }
r[5]=r[3];
goto P_0c0809b8;
P_0c0809b8: /* original 7502, guest PC 0x0c0809b8 */
if(!s->budget--) { s->failed_pc=0x0c0809b8u; return 0; }
r[5]+=0x00000002u;
goto P_0c0809ba;
P_0c0809ba: /* original 490b, guest PC 0x0c0809ba */
if(!s->budget--) { s->failed_pc=0x0c0809bau; return 0; }
target=r[9];
r[16]=code_base|0x0c0809beu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0809beu) { target=s->pc; goto dispatch; }
goto P_0c0809be;
P_0c0809bc: /* original 54f5, guest PC 0x0c0809bc */
if(!s->budget--) { s->failed_pc=0x0c0809bcu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0809be;
P_0c0809be: /* original 7f04, guest PC 0x0c0809be */
if(!s->budget--) { s->failed_pc=0x0c0809beu; return 0; }
r[15]+=0x00000004u;
goto P_0c0809c0;
P_0c0809c0: /* original 63f0, guest PC 0x0c0809c0 */
if(!s->budget--) { s->failed_pc=0x0c0809c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c0809c2;
P_0c0809c2: /* original 7801, guest PC 0x0c0809c2 */
if(!s->budget--) { s->failed_pc=0x0c0809c2u; return 0; }
r[8]+=0x00000001u;
goto P_0c0809c4;
P_0c0809c4: /* original 628e, guest PC 0x0c0809c4 */
if(!s->budget--) { s->failed_pc=0x0c0809c4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c0809c6;
P_0c0809c6: /* original 7302, guest PC 0x0c0809c6 */
if(!s->budget--) { s->failed_pc=0x0c0809c6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0809c8;
P_0c0809c8: /* original 2f30, guest PC 0x0c0809c8 */
if(!s->budget--) { s->failed_pc=0x0c0809c8u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809ca;
P_0c0809ca: /* original 51f1, guest PC 0x0c0809ca */
if(!s->budget--) { s->failed_pc=0x0c0809cau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0809cc;
P_0c0809cc: /* original 3213, guest PC 0x0c0809cc */
if(!s->budget--) { s->failed_pc=0x0c0809ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0809ce;
P_0c0809ce: /* original 8bd0, guest PC 0x0c0809ce */
if(!s->budget--) { s->failed_pc=0x0c0809ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080972; }
goto P_0c0809d0;
P_0c0809d0: /* original 9041, guest PC 0x0c0809d0 */
if(!s->budget--) { s->failed_pc=0x0c0809d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a56u,2);
goto P_0c0809d2;
P_0c0809d2: /* original 04dc, guest PC 0x0c0809d2 */
if(!s->budget--) { s->failed_pc=0x0c0809d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d4;
P_0c0809d4: /* original e01a, guest PC 0x0c0809d4 */
if(!s->budget--) { s->failed_pc=0x0c0809d4u; return 0; }
r[0]=0x0000001au;
goto P_0c0809d6;
P_0c0809d6: /* original 00dc, guest PC 0x0c0809d6 */
if(!s->budget--) { s->failed_pc=0x0c0809d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0809d8;
P_0c0809d8: /* original 6243, guest PC 0x0c0809d8 */
if(!s->budget--) { s->failed_pc=0x0c0809d8u; return 0; }
r[2]=r[4];
goto P_0c0809da;
P_0c0809da: /* original 4215, guest PC 0x0c0809da */
if(!s->budget--) { s->failed_pc=0x0c0809dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0809dc;
P_0c0809dc: /* original 80fc, guest PC 0x0c0809dc */
if(!s->budget--) { s->failed_pc=0x0c0809dcu; return 0; }
write(ram,r[15]+12,r[0],1);
goto P_0c0809de;
P_0c0809de: /* original 63b2, guest PC 0x0c0809de */
if(!s->budget--) { s->failed_pc=0x0c0809deu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0809e0;
P_0c0809e0: /* original 6be3, guest PC 0x0c0809e0 */
if(!s->budget--) { s->failed_pc=0x0c0809e0u; return 0; }
r[11]=r[14];
goto P_0c0809e2;
P_0c0809e2: /* original 7306, guest PC 0x0c0809e2 */
if(!s->budget--) { s->failed_pc=0x0c0809e2u; return 0; }
r[3]+=0x00000006u;
goto P_0c0809e4;
P_0c0809e4: /* original 2f30, guest PC 0x0c0809e4 */
if(!s->budget--) { s->failed_pc=0x0c0809e4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0809e6;
P_0c0809e6: /* original 8d02, guest PC 0x0c0809e6 */
if(!s->budget--) { s->failed_pc=0x0c0809e6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c0809ee; }
goto P_0c0809ea;
P_0c0809e8: /* original 1f41, guest PC 0x0c0809e8 */
if(!s->budget--) { s->failed_pc=0x0c0809e8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0809ea;
P_0c0809ea: /* original a097, guest PC 0x0c0809ea */
if(!s->budget--) { s->failed_pc=0x0c0809eau; return 0; }
goto P_0c080b1c;
P_0c0809ec: /* original 0009, guest PC 0x0c0809ec */
if(!s->budget--) { s->failed_pc=0x0c0809ecu; return 0; }
goto P_0c0809ee;
P_0c0809ee: /* original 9334, guest PC 0x0c0809ee */
if(!s->budget--) { s->failed_pc=0x0c0809eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080a5au,2);
goto P_0c0809f0;
P_0c0809f0: /* original 64be, guest PC 0x0c0809f0 */
if(!s->budget--) { s->failed_pc=0x0c0809f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c0809f2;
P_0c0809f2: /* original 33dc, guest PC 0x0c0809f2 */
if(!s->budget--) { s->failed_pc=0x0c0809f2u; return 0; }
r[3]+=r[13];
goto P_0c0809f4;
P_0c0809f4: /* original 343c, guest PC 0x0c0809f4 */
if(!s->budget--) { s->failed_pc=0x0c0809f4u; return 0; }
r[4]+=r[3];
goto P_0c0809f6;
P_0c0809f6: /* original 6440, guest PC 0x0c0809f6 */
if(!s->budget--) { s->failed_pc=0x0c0809f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0809f8;
P_0c0809f8: /* original e30d, guest PC 0x0c0809f8 */
if(!s->budget--) { s->failed_pc=0x0c0809f8u; return 0; }
r[3]=0x0000000du;
goto P_0c0809fa;
P_0c0809fa: /* original 3433, guest PC 0x0c0809fa */
if(!s->budget--) { s->failed_pc=0x0c0809fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0809fc;
P_0c0809fc: /* original 8f01, guest PC 0x0c0809fc */
if(!s->budget--) { s->failed_pc=0x0c0809fcu; return 0; }
cond=r[17]&1u;
r[5]=0x00000036u;
if(!cond) { goto P_0c080a02; }
goto P_0c080a00;
P_0c0809fe: /* original e536, guest PC 0x0c0809fe */
if(!s->budget--) { s->failed_pc=0x0c0809feu; return 0; }
r[5]=0x00000036u;
goto P_0c080a00;
P_0c080a00: /* original 3438, guest PC 0x0c080a00 */
if(!s->budget--) { s->failed_pc=0x0c080a00u; return 0; }
r[4]-=r[3];
goto P_0c080a02;
P_0c080a02: /* original 604e, guest PC 0x0c080a02 */
if(!s->budget--) { s->failed_pc=0x0c080a02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a04;
P_0c080a04: /* original 880c, guest PC 0x0c080a04 */
if(!s->budget--) { s->failed_pc=0x0c080a04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080a06;
P_0c080a06: /* original 8f01, guest PC 0x0c080a06 */
if(!s->budget--) { s->failed_pc=0x0c080a06u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
if(!cond) { goto P_0c080a0c; }
goto P_0c080a0a;
P_0c080a08: /* original 604e, guest PC 0x0c080a08 */
if(!s->budget--) { s->failed_pc=0x0c080a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080a0a;
P_0c080a0a: /* original e535, guest PC 0x0c080a0a */
if(!s->budget--) { s->failed_pc=0x0c080a0au; return 0; }
r[5]=0x00000035u;
goto P_0c080a0c;
P_0c080a0c: /* original 4000, guest PC 0x0c080a0c */
if(!s->budget--) { s->failed_pc=0x0c080a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080a0e;
P_0c080a0e: /* original 00ad, guest PC 0x0c080a0e */
if(!s->budget--) { s->failed_pc=0x0c080a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080a10;
P_0c080a10: /* original e207, guest PC 0x0c080a10 */
if(!s->budget--) { s->failed_pc=0x0c080a10u; return 0; }
r[2]=0x00000007u;
goto P_0c080a12;
P_0c080a12: /* original 655e, guest PC 0x0c080a12 */
if(!s->budget--) { s->failed_pc=0x0c080a12u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c080a14;
P_0c080a14: /* original 81f4, guest PC 0x0c080a14 */
if(!s->budget--) { s->failed_pc=0x0c080a14u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080a16;
P_0c080a16: /* original 4500, guest PC 0x0c080a16 */
if(!s->budget--) { s->failed_pc=0x0c080a16u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c080a18;
P_0c080a18: /* original 63f0, guest PC 0x0c080a18 */
if(!s->budget--) { s->failed_pc=0x0c080a18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a1a;
P_0c080a1a: /* original 432c, guest PC 0x0c080a1a */
if(!s->budget--) { s->failed_pc=0x0c080a1au; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c080a1c;
P_0c080a1c: /* original 253b, guest PC 0x0c080a1c */
if(!s->budget--) { s->failed_pc=0x0c080a1cu; return 0; }
r[5]|=r[3];
goto P_0c080a1e;
P_0c080a1e: /* original 63be, guest PC 0x0c080a1e */
if(!s->budget--) { s->failed_pc=0x0c080a1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a20;
P_0c080a20: /* original 1f54, guest PC 0x0c080a20 */
if(!s->budget--) { s->failed_pc=0x0c080a20u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c080a22;
P_0c080a22: /* original 84fc, guest PC 0x0c080a22 */
if(!s->budget--) { s->failed_pc=0x0c080a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c080a24;
P_0c080a24: /* original 3303, guest PC 0x0c080a24 */
if(!s->budget--) { s->failed_pc=0x0c080a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[0])!=0);
goto P_0c080a26;
P_0c080a26: /* original 8d01, guest PC 0x0c080a26 */
if(!s->budget--) { s->failed_pc=0x0c080a26u; return 0; }
cond=r[17]&1u;
r[8]=r[14];
if(cond) { goto P_0c080a2c; }
goto P_0c080a2a;
P_0c080a28: /* original 68e3, guest PC 0x0c080a28 */
if(!s->budget--) { s->failed_pc=0x0c080a28u; return 0; }
r[8]=r[14];
goto P_0c080a2a;
P_0c080a2a: /* original e801, guest PC 0x0c080a2a */
if(!s->budget--) { s->failed_pc=0x0c080a2au; return 0; }
r[8]=0x00000001u;
goto P_0c080a2c;
P_0c080a2c: /* original 2fe6, guest PC 0x0c080a2c */
if(!s->budget--) { s->failed_pc=0x0c080a2cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a2e;
P_0c080a2e: /* original 688e, guest PC 0x0c080a2e */
if(!s->budget--) { s->failed_pc=0x0c080a2eu; return 0; }
r[8]=(uint32_t)(int32_t)(int8_t)r[8];
goto P_0c080a30;
P_0c080a30: /* original 85f6, guest PC 0x0c080a30 */
if(!s->budget--) { s->failed_pc=0x0c080a30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080a32;
P_0c080a32: /* original 66c3, guest PC 0x0c080a32 */
if(!s->budget--) { s->failed_pc=0x0c080a32u; return 0; }
r[6]=r[12];
goto P_0c080a34;
P_0c080a34: /* original e700, guest PC 0x0c080a34 */
if(!s->budget--) { s->failed_pc=0x0c080a34u; return 0; }
r[7]=0x00000000u;
goto P_0c080a36;
P_0c080a36: /* original 3088, guest PC 0x0c080a36 */
if(!s->budget--) { s->failed_pc=0x0c080a36u; return 0; }
r[0]-=r[8];
goto P_0c080a38;
P_0c080a38: /* original 6503, guest PC 0x0c080a38 */
if(!s->budget--) { s->failed_pc=0x0c080a38u; return 0; }
r[5]=r[0];
goto P_0c080a3a;
P_0c080a3a: /* original 7502, guest PC 0x0c080a3a */
if(!s->budget--) { s->failed_pc=0x0c080a3au; return 0; }
r[5]+=0x00000002u;
goto P_0c080a3c;
P_0c080a3c: /* original 490b, guest PC 0x0c080a3c */
if(!s->budget--) { s->failed_pc=0x0c080a3cu; return 0; }
target=r[9];
r[16]=code_base|0x0c080a40u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a40u) { target=s->pc; goto dispatch; }
goto P_0c080a40;
P_0c080a3e: /* original 54f5, guest PC 0x0c080a3e */
if(!s->budget--) { s->failed_pc=0x0c080a3eu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080a40;
P_0c080a40: /* original 7f04, guest PC 0x0c080a40 */
if(!s->budget--) { s->failed_pc=0x0c080a40u; return 0; }
r[15]+=0x00000004u;
goto P_0c080a42;
P_0c080a42: /* original 63f0, guest PC 0x0c080a42 */
if(!s->budget--) { s->failed_pc=0x0c080a42u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c080a44;
P_0c080a44: /* original 7b01, guest PC 0x0c080a44 */
if(!s->budget--) { s->failed_pc=0x0c080a44u; return 0; }
r[11]+=0x00000001u;
goto P_0c080a46;
P_0c080a46: /* original 62be, guest PC 0x0c080a46 */
if(!s->budget--) { s->failed_pc=0x0c080a46u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c080a48;
P_0c080a48: /* original 7302, guest PC 0x0c080a48 */
if(!s->budget--) { s->failed_pc=0x0c080a48u; return 0; }
r[3]+=0x00000002u;
goto P_0c080a4a;
P_0c080a4a: /* original 2f30, guest PC 0x0c080a4a */
if(!s->budget--) { s->failed_pc=0x0c080a4au; return 0; }
write(ram,r[15],r[3],1);
goto P_0c080a4c;
P_0c080a4c: /* original 51f1, guest PC 0x0c080a4c */
if(!s->budget--) { s->failed_pc=0x0c080a4cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c080a4e;
P_0c080a4e: /* original 3213, guest PC 0x0c080a4e */
if(!s->budget--) { s->failed_pc=0x0c080a4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c080a50;
P_0c080a50: /* original 8bcd, guest PC 0x0c080a50 */
if(!s->budget--) { s->failed_pc=0x0c080a50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0809ee; }
goto P_0c080a52;
P_0c080a52: /* original a063, guest PC 0x0c080a52 */
if(!s->budget--) { s->failed_pc=0x0c080a52u; return 0; }
goto P_0c080b1c;
P_0c080a54: /* original 0009, guest PC 0x0c080a54 */
if(!s->budget--) { s->failed_pc=0x0c080a54u; return 0; }
if(!vf3_matrix_family(0x0c080a56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080a56u; return 0; } return 1;
P_0c080a74: /* original 5152, guest PC 0x0c080a74 */
if(!s->budget--) { s->failed_pc=0x0c080a74u; return 0; }
r[1]=read(ram,r[5]+8,4);
goto P_0c080a76;
P_0c080a76: /* original d22f, guest PC 0x0c080a76 */
if(!s->budget--) { s->failed_pc=0x0c080a76u; return 0; }
r[2]=read(ram,0x0c080b34u,4);
goto P_0c080a78;
P_0c080a78: /* original 2128, guest PC 0x0c080a78 */
if(!s->budget--) { s->failed_pc=0x0c080a78u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c080a7a;
P_0c080a7a: /* original 8b4f, guest PC 0x0c080a7a */
if(!s->budget--) { s->failed_pc=0x0c080a7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b1c; }
goto P_0c080a7c;
P_0c080a7c: /* original 60b2, guest PC 0x0c080a7c */
if(!s->budget--) { s->failed_pc=0x0c080a7cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a7e;
P_0c080a7e: /* original e307, guest PC 0x0c080a7e */
if(!s->budget--) { s->failed_pc=0x0c080a7eu; return 0; }
r[3]=0x00000007u;
goto P_0c080a80;
P_0c080a80: /* original e220, guest PC 0x0c080a80 */
if(!s->budget--) { s->failed_pc=0x0c080a80u; return 0; }
r[2]=0x00000020u;
goto P_0c080a82;
P_0c080a82: /* original 7006, guest PC 0x0c080a82 */
if(!s->budget--) { s->failed_pc=0x0c080a82u; return 0; }
r[0]+=0x00000006u;
goto P_0c080a84;
P_0c080a84: /* original 403c, guest PC 0x0c080a84 */
if(!s->budget--) { s->failed_pc=0x0c080a84u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080a86;
P_0c080a86: /* original cb04, guest PC 0x0c080a86 */
if(!s->budget--) { s->failed_pc=0x0c080a86u; return 0; }
r[0]|=4u;
goto P_0c080a88;
P_0c080a88: /* original 2f02, guest PC 0x0c080a88 */
if(!s->budget--) { s->failed_pc=0x0c080a88u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c080a8a;
P_0c080a8a: /* original 6503, guest PC 0x0c080a8a */
if(!s->budget--) { s->failed_pc=0x0c080a8au; return 0; }
r[5]=r[0];
goto P_0c080a8c;
P_0c080a8c: /* original e615, guest PC 0x0c080a8c */
if(!s->budget--) { s->failed_pc=0x0c080a8cu; return 0; }
r[6]=0x00000015u;
goto P_0c080a8e;
P_0c080a8e: /* original 2f26, guest PC 0x0c080a8e */
if(!s->budget--) { s->failed_pc=0x0c080a8eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080a90;
P_0c080a90: /* original d329, guest PC 0x0c080a90 */
if(!s->budget--) { s->failed_pc=0x0c080a90u; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080a92;
P_0c080a92: /* original e701, guest PC 0x0c080a92 */
if(!s->budget--) { s->failed_pc=0x0c080a92u; return 0; }
r[7]=0x00000001u;
goto P_0c080a94;
P_0c080a94: /* original 430b, guest PC 0x0c080a94 */
if(!s->budget--) { s->failed_pc=0x0c080a94u; return 0; }
target=r[3];
r[16]=code_base|0x0c080a98u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080a98u) { target=s->pc; goto dispatch; }
goto P_0c080a98;
P_0c080a96: /* original 64c3, guest PC 0x0c080a96 */
if(!s->budget--) { s->failed_pc=0x0c080a96u; return 0; }
r[4]=r[12];
goto P_0c080a98;
P_0c080a98: /* original 60b2, guest PC 0x0c080a98 */
if(!s->budget--) { s->failed_pc=0x0c080a98u; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080a9a;
P_0c080a9a: /* original e307, guest PC 0x0c080a9a */
if(!s->budget--) { s->failed_pc=0x0c080a9au; return 0; }
r[3]=0x00000007u;
goto P_0c080a9c;
P_0c080a9c: /* original e220, guest PC 0x0c080a9c */
if(!s->budget--) { s->failed_pc=0x0c080a9cu; return 0; }
r[2]=0x00000020u;
goto P_0c080a9e;
P_0c080a9e: /* original 7006, guest PC 0x0c080a9e */
if(!s->budget--) { s->failed_pc=0x0c080a9eu; return 0; }
r[0]+=0x00000006u;
goto P_0c080aa0;
P_0c080aa0: /* original 403c, guest PC 0x0c080aa0 */
if(!s->budget--) { s->failed_pc=0x0c080aa0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080aa2;
P_0c080aa2: /* original cb5c, guest PC 0x0c080aa2 */
if(!s->budget--) { s->failed_pc=0x0c080aa2u; return 0; }
r[0]|=92u;
goto P_0c080aa4;
P_0c080aa4: /* original 1f01, guest PC 0x0c080aa4 */
if(!s->budget--) { s->failed_pc=0x0c080aa4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c080aa6;
P_0c080aa6: /* original 6503, guest PC 0x0c080aa6 */
if(!s->budget--) { s->failed_pc=0x0c080aa6u; return 0; }
r[5]=r[0];
goto P_0c080aa8;
P_0c080aa8: /* original e615, guest PC 0x0c080aa8 */
if(!s->budget--) { s->failed_pc=0x0c080aa8u; return 0; }
r[6]=0x00000015u;
goto P_0c080aaa;
P_0c080aaa: /* original 2f26, guest PC 0x0c080aaa */
if(!s->budget--) { s->failed_pc=0x0c080aaau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080aac;
P_0c080aac: /* original d322, guest PC 0x0c080aac */
if(!s->budget--) { s->failed_pc=0x0c080aacu; return 0; }
r[3]=read(ram,0x0c080b38u,4);
goto P_0c080aae;
P_0c080aae: /* original e701, guest PC 0x0c080aae */
if(!s->budget--) { s->failed_pc=0x0c080aaeu; return 0; }
r[7]=0x00000001u;
goto P_0c080ab0;
P_0c080ab0: /* original 430b, guest PC 0x0c080ab0 */
if(!s->budget--) { s->failed_pc=0x0c080ab0u; return 0; }
target=r[3];
r[16]=code_base|0x0c080ab4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ab4u) { target=s->pc; goto dispatch; }
goto P_0c080ab4;
P_0c080ab2: /* original 64c3, guest PC 0x0c080ab2 */
if(!s->budget--) { s->failed_pc=0x0c080ab2u; return 0; }
r[4]=r[12];
goto P_0c080ab4;
P_0c080ab4: /* original 54f9, guest PC 0x0c080ab4 */
if(!s->budget--) { s->failed_pc=0x0c080ab4u; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c080ab6;
P_0c080ab6: /* original e061, guest PC 0x0c080ab6 */
if(!s->budget--) { s->failed_pc=0x0c080ab6u; return 0; }
r[0]=0x00000061u;
goto P_0c080ab8;
P_0c080ab8: /* original e207, guest PC 0x0c080ab8 */
if(!s->budget--) { s->failed_pc=0x0c080ab8u; return 0; }
r[2]=0x00000007u;
goto P_0c080aba;
P_0c080aba: /* original 66c3, guest PC 0x0c080aba */
if(!s->budget--) { s->failed_pc=0x0c080abau; return 0; }
r[6]=r[12];
goto P_0c080abc;
P_0c080abc: /* original 044c, guest PC 0x0c080abc */
if(!s->budget--) { s->failed_pc=0x0c080abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080abe;
P_0c080abe: /* original e700, guest PC 0x0c080abe */
if(!s->budget--) { s->failed_pc=0x0c080abeu; return 0; }
r[7]=0x00000000u;
goto P_0c080ac0;
P_0c080ac0: /* original 604e, guest PC 0x0c080ac0 */
if(!s->budget--) { s->failed_pc=0x0c080ac0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080ac2;
P_0c080ac2: /* original 4000, guest PC 0x0c080ac2 */
if(!s->budget--) { s->failed_pc=0x0c080ac2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080ac4;
P_0c080ac4: /* original 03ad, guest PC 0x0c080ac4 */
if(!s->budget--) { s->failed_pc=0x0c080ac4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080ac6;
P_0c080ac6: /* original 6033, guest PC 0x0c080ac6 */
if(!s->budget--) { s->failed_pc=0x0c080ac6u; return 0; }
r[0]=r[3];
goto P_0c080ac8;
P_0c080ac8: /* original 81f4, guest PC 0x0c080ac8 */
if(!s->budget--) { s->failed_pc=0x0c080ac8u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c080aca;
P_0c080aca: /* original 60b2, guest PC 0x0c080aca */
if(!s->budget--) { s->failed_pc=0x0c080acau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080acc;
P_0c080acc: /* original 7006, guest PC 0x0c080acc */
if(!s->budget--) { s->failed_pc=0x0c080accu; return 0; }
r[0]+=0x00000006u;
goto P_0c080ace;
P_0c080ace: /* original 402c, guest PC 0x0c080ace */
if(!s->budget--) { s->failed_pc=0x0c080aceu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c080ad0;
P_0c080ad0: /* original cb04, guest PC 0x0c080ad0 */
if(!s->budget--) { s->failed_pc=0x0c080ad0u; return 0; }
r[0]|=4u;
goto P_0c080ad2;
P_0c080ad2: /* original 1f04, guest PC 0x0c080ad2 */
if(!s->budget--) { s->failed_pc=0x0c080ad2u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c080ad4;
P_0c080ad4: /* original 2fe6, guest PC 0x0c080ad4 */
if(!s->budget--) { s->failed_pc=0x0c080ad4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080ad6;
P_0c080ad6: /* original 85f6, guest PC 0x0c080ad6 */
if(!s->budget--) { s->failed_pc=0x0c080ad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c080ad8;
P_0c080ad8: /* original 6503, guest PC 0x0c080ad8 */
if(!s->budget--) { s->failed_pc=0x0c080ad8u; return 0; }
r[5]=r[0];
goto P_0c080ada;
P_0c080ada: /* original 7502, guest PC 0x0c080ada */
if(!s->budget--) { s->failed_pc=0x0c080adau; return 0; }
r[5]+=0x00000002u;
goto P_0c080adc;
P_0c080adc: /* original 490b, guest PC 0x0c080adc */
if(!s->budget--) { s->failed_pc=0x0c080adcu; return 0; }
target=r[9];
r[16]=code_base|0x0c080ae0u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ae0u) { target=s->pc; goto dispatch; }
goto P_0c080ae0;
P_0c080ade: /* original 54f5, guest PC 0x0c080ade */
if(!s->budget--) { s->failed_pc=0x0c080adeu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c080ae0;
P_0c080ae0: /* original 7f0c, guest PC 0x0c080ae0 */
if(!s->budget--) { s->failed_pc=0x0c080ae0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c080ae2;
P_0c080ae2: /* original 54f6, guest PC 0x0c080ae2 */
if(!s->budget--) { s->failed_pc=0x0c080ae2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c080ae4;
P_0c080ae4: /* original e061, guest PC 0x0c080ae4 */
if(!s->budget--) { s->failed_pc=0x0c080ae4u; return 0; }
r[0]=0x00000061u;
goto P_0c080ae6;
P_0c080ae6: /* original e307, guest PC 0x0c080ae6 */
if(!s->budget--) { s->failed_pc=0x0c080ae6u; return 0; }
r[3]=0x00000007u;
goto P_0c080ae8;
P_0c080ae8: /* original 044c, guest PC 0x0c080ae8 */
if(!s->budget--) { s->failed_pc=0x0c080ae8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080aea;
P_0c080aea: /* original ed6c, guest PC 0x0c080aea */
if(!s->budget--) { s->failed_pc=0x0c080aeau; return 0; }
r[13]=0x0000006cu;
goto P_0c080aec;
P_0c080aec: /* original 60b2, guest PC 0x0c080aec */
if(!s->budget--) { s->failed_pc=0x0c080aecu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080aee;
P_0c080aee: /* original 7006, guest PC 0x0c080aee */
if(!s->budget--) { s->failed_pc=0x0c080aeeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080af0;
P_0c080af0: /* original 403c, guest PC 0x0c080af0 */
if(!s->budget--) { s->failed_pc=0x0c080af0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080af2;
P_0c080af2: /* original 2d0b, guest PC 0x0c080af2 */
if(!s->budget--) { s->failed_pc=0x0c080af2u; return 0; }
r[13]|=r[0];
goto P_0c080af4;
P_0c080af4: /* original 604e, guest PC 0x0c080af4 */
if(!s->budget--) { s->failed_pc=0x0c080af4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080af6;
P_0c080af6: /* original 880c, guest PC 0x0c080af6 */
if(!s->budget--) { s->failed_pc=0x0c080af6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c080af8;
P_0c080af8: /* original 8b04, guest PC 0x0c080af8 */
if(!s->budget--) { s->failed_pc=0x0c080af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080b04; }
goto P_0c080afa;
P_0c080afa: /* original 60b2, guest PC 0x0c080afa */
if(!s->budget--) { s->failed_pc=0x0c080afau; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c080afc;
P_0c080afc: /* original ed64, guest PC 0x0c080afc */
if(!s->budget--) { s->failed_pc=0x0c080afcu; return 0; }
r[13]=0x00000064u;
goto P_0c080afe;
P_0c080afe: /* original 7006, guest PC 0x0c080afe */
if(!s->budget--) { s->failed_pc=0x0c080afeu; return 0; }
r[0]+=0x00000006u;
goto P_0c080b00;
P_0c080b00: /* original 403c, guest PC 0x0c080b00 */
if(!s->budget--) { s->failed_pc=0x0c080b00u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c080b02;
P_0c080b02: /* original 2d0b, guest PC 0x0c080b02 */
if(!s->budget--) { s->failed_pc=0x0c080b02u; return 0; }
r[13]|=r[0];
goto P_0c080b04;
P_0c080b04: /* original 604e, guest PC 0x0c080b04 */
if(!s->budget--) { s->failed_pc=0x0c080b04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c080b06;
P_0c080b06: /* original 66c3, guest PC 0x0c080b06 */
if(!s->budget--) { s->failed_pc=0x0c080b06u; return 0; }
r[6]=r[12];
goto P_0c080b08;
P_0c080b08: /* original 4000, guest PC 0x0c080b08 */
if(!s->budget--) { s->failed_pc=0x0c080b08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c080b0a;
P_0c080b0a: /* original 03ad, guest PC 0x0c080b0a */
if(!s->budget--) { s->failed_pc=0x0c080b0au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c080b0c;
P_0c080b0c: /* original e700, guest PC 0x0c080b0c */
if(!s->budget--) { s->failed_pc=0x0c080b0cu; return 0; }
r[7]=0x00000000u;
goto P_0c080b0e;
P_0c080b0e: /* original 653f, guest PC 0x0c080b0e */
if(!s->budget--) { s->failed_pc=0x0c080b0eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c080b10;
P_0c080b10: /* original 2f31, guest PC 0x0c080b10 */
if(!s->budget--) { s->failed_pc=0x0c080b10u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c080b12;
P_0c080b12: /* original 7502, guest PC 0x0c080b12 */
if(!s->budget--) { s->failed_pc=0x0c080b12u; return 0; }
r[5]+=0x00000002u;
goto P_0c080b14;
P_0c080b14: /* original 2fe6, guest PC 0x0c080b14 */
if(!s->budget--) { s->failed_pc=0x0c080b14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b16;
P_0c080b16: /* original 490b, guest PC 0x0c080b16 */
if(!s->budget--) { s->failed_pc=0x0c080b16u; return 0; }
target=r[9];
r[16]=code_base|0x0c080b1au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080b1au) { target=s->pc; goto dispatch; }
goto P_0c080b1a;
P_0c080b18: /* original 64d3, guest PC 0x0c080b18 */
if(!s->budget--) { s->failed_pc=0x0c080b18u; return 0; }
r[4]=r[13];
goto P_0c080b1a;
P_0c080b1a: /* original 7f04, guest PC 0x0c080b1a */
if(!s->budget--) { s->failed_pc=0x0c080b1au; return 0; }
r[15]+=0x00000004u;
goto P_0c080b1c;
P_0c080b1c: /* original 7f20, guest PC 0x0c080b1c */
if(!s->budget--) { s->failed_pc=0x0c080b1cu; return 0; }
r[15]+=0x00000020u;
goto P_0c080b1e;
P_0c080b1e: /* original 4f26, guest PC 0x0c080b1e */
if(!s->budget--) { s->failed_pc=0x0c080b1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080b20;
P_0c080b20: /* original e000, guest PC 0x0c080b20 */
if(!s->budget--) { s->failed_pc=0x0c080b20u; return 0; }
r[0]=0x00000000u;
goto P_0c080b22;
P_0c080b22: /* original 68f6, guest PC 0x0c080b22 */
if(!s->budget--) { s->failed_pc=0x0c080b22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c080b24;
P_0c080b24: /* original 69f6, guest PC 0x0c080b24 */
if(!s->budget--) { s->failed_pc=0x0c080b24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080b26;
P_0c080b26: /* original 6af6, guest PC 0x0c080b26 */
if(!s->budget--) { s->failed_pc=0x0c080b26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080b28;
P_0c080b28: /* original 6bf6, guest PC 0x0c080b28 */
if(!s->budget--) { s->failed_pc=0x0c080b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080b2a;
P_0c080b2a: /* original 6cf6, guest PC 0x0c080b2a */
if(!s->budget--) { s->failed_pc=0x0c080b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080b2c;
P_0c080b2c: /* original 6df6, guest PC 0x0c080b2c */
if(!s->budget--) { s->failed_pc=0x0c080b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080b2e;
P_0c080b2e: /* original 000b, guest PC 0x0c080b2e */
if(!s->budget--) { s->failed_pc=0x0c080b2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080b30: /* original 6ef6, guest PC 0x0c080b30 */
if(!s->budget--) { s->failed_pc=0x0c080b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080b32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080b32u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
