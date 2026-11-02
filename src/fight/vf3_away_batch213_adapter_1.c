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
int vf3_away_batch213_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0ae318u: goto P_0c0ae318;
case 0x0c0ae31au: goto P_0c0ae31a;
case 0x0c0ae31cu: goto P_0c0ae31c;
case 0x0c0ae31eu: goto P_0c0ae31e;
case 0x0c0ae320u: goto P_0c0ae320;
case 0x0c0ae322u: goto P_0c0ae322;
case 0x0c0ae324u: goto P_0c0ae324;
case 0x0c0ae326u: goto P_0c0ae326;
case 0x0c0ae328u: goto P_0c0ae328;
case 0x0c0ae32au: goto P_0c0ae32a;
case 0x0c0ae32cu: goto P_0c0ae32c;
case 0x0c0ae32eu: goto P_0c0ae32e;
case 0x0c0ae330u: goto P_0c0ae330;
case 0x0c0ae332u: goto P_0c0ae332;
case 0x0c0ae334u: goto P_0c0ae334;
case 0x0c0ae336u: goto P_0c0ae336;
case 0x0c0ae338u: goto P_0c0ae338;
case 0x0c0ae33au: goto P_0c0ae33a;
case 0x0c0ae33cu: goto P_0c0ae33c;
case 0x0c0ae33eu: goto P_0c0ae33e;
case 0x0c0ae340u: goto P_0c0ae340;
case 0x0c0ae342u: goto P_0c0ae342;
case 0x0c0ae344u: goto P_0c0ae344;
case 0x0c0ae346u: goto P_0c0ae346;
case 0x0c0ae348u: goto P_0c0ae348;
case 0x0c0ae34au: goto P_0c0ae34a;
case 0x0c0ae34cu: goto P_0c0ae34c;
case 0x0c0ae34eu: goto P_0c0ae34e;
case 0x0c0ae350u: goto P_0c0ae350;
case 0x0c0ae352u: goto P_0c0ae352;
case 0x0c0ae354u: goto P_0c0ae354;
case 0x0c0ae356u: goto P_0c0ae356;
case 0x0c0ae358u: goto P_0c0ae358;
case 0x0c0ae35au: goto P_0c0ae35a;
case 0x0c0ae35cu: goto P_0c0ae35c;
case 0x0c0ae35eu: goto P_0c0ae35e;
case 0x0c0ae360u: goto P_0c0ae360;
case 0x0c0ae362u: goto P_0c0ae362;
case 0x0c0ae364u: goto P_0c0ae364;
case 0x0c0ae366u: goto P_0c0ae366;
case 0x0c0ae368u: goto P_0c0ae368;
case 0x0c0ae36au: goto P_0c0ae36a;
case 0x0c0ae36cu: goto P_0c0ae36c;
case 0x0c0ae36eu: goto P_0c0ae36e;
case 0x0c0ae370u: goto P_0c0ae370;
case 0x0c0ae372u: goto P_0c0ae372;
case 0x0c0ae374u: goto P_0c0ae374;
case 0x0c0ae376u: goto P_0c0ae376;
case 0x0c0ae378u: goto P_0c0ae378;
case 0x0c0ae37au: goto P_0c0ae37a;
case 0x0c0ae37cu: goto P_0c0ae37c;
case 0x0c0ae37eu: goto P_0c0ae37e;
case 0x0c0ae380u: goto P_0c0ae380;
case 0x0c0ae382u: goto P_0c0ae382;
case 0x0c0ae384u: goto P_0c0ae384;
case 0x0c0ae386u: goto P_0c0ae386;
case 0x0c0ae388u: goto P_0c0ae388;
case 0x0c0ae38au: goto P_0c0ae38a;
case 0x0c0ae38cu: goto P_0c0ae38c;
case 0x0c0ae38eu: goto P_0c0ae38e;
case 0x0c0ae390u: goto P_0c0ae390;
case 0x0c0ae392u: goto P_0c0ae392;
case 0x0c0ae394u: goto P_0c0ae394;
case 0x0c0ae396u: goto P_0c0ae396;
case 0x0c0ae398u: goto P_0c0ae398;
case 0x0c0ae39au: goto P_0c0ae39a;
case 0x0c0ae39cu: goto P_0c0ae39c;
case 0x0c0ae39eu: goto P_0c0ae39e;
case 0x0c0ae3a0u: goto P_0c0ae3a0;
case 0x0c0ae3a2u: goto P_0c0ae3a2;
case 0x0c0ae3a4u: goto P_0c0ae3a4;
case 0x0c0ae3a6u: goto P_0c0ae3a6;
case 0x0c0ae3a8u: goto P_0c0ae3a8;
case 0x0c0ae3aau: goto P_0c0ae3aa;
case 0x0c0ae3acu: goto P_0c0ae3ac;
case 0x0c0ae3aeu: goto P_0c0ae3ae;
case 0x0c0ae3b0u: goto P_0c0ae3b0;
case 0x0c0ae3b2u: goto P_0c0ae3b2;
case 0x0c0ae3b4u: goto P_0c0ae3b4;
case 0x0c0ae3b6u: goto P_0c0ae3b6;
case 0x0c0ae3b8u: goto P_0c0ae3b8;
case 0x0c0ae3bau: goto P_0c0ae3ba;
case 0x0c0ae3bcu: goto P_0c0ae3bc;
case 0x0c0ae3beu: goto P_0c0ae3be;
case 0x0c0ae3c0u: goto P_0c0ae3c0;
case 0x0c0ae3c2u: goto P_0c0ae3c2;
case 0x0c0ae3c4u: goto P_0c0ae3c4;
case 0x0c0ae3c6u: goto P_0c0ae3c6;
case 0x0c0ae3c8u: goto P_0c0ae3c8;
case 0x0c0ae3cau: goto P_0c0ae3ca;
case 0x0c0ae3ccu: goto P_0c0ae3cc;
case 0x0c0ae3ceu: goto P_0c0ae3ce;
case 0x0c0ae3d0u: goto P_0c0ae3d0;
case 0x0c0ae3d2u: goto P_0c0ae3d2;
case 0x0c0ae3d4u: goto P_0c0ae3d4;
case 0x0c0ae3d6u: goto P_0c0ae3d6;
case 0x0c0ae3d8u: goto P_0c0ae3d8;
case 0x0c0ae3dau: goto P_0c0ae3da;
case 0x0c0ae3dcu: goto P_0c0ae3dc;
case 0x0c0ae3deu: goto P_0c0ae3de;
case 0x0c0ae3e0u: goto P_0c0ae3e0;
case 0x0c0ae3e2u: goto P_0c0ae3e2;
case 0x0c0ae3e4u: goto P_0c0ae3e4;
case 0x0c0ae3e6u: goto P_0c0ae3e6;
case 0x0c0ae3e8u: goto P_0c0ae3e8;
case 0x0c0ae3eau: goto P_0c0ae3ea;
case 0x0c0ae3ecu: goto P_0c0ae3ec;
case 0x0c0ae3eeu: goto P_0c0ae3ee;
case 0x0c0ae3f0u: goto P_0c0ae3f0;
case 0x0c0ae3f2u: goto P_0c0ae3f2;
case 0x0c0ae3f4u: goto P_0c0ae3f4;
case 0x0c0ae3f6u: goto P_0c0ae3f6;
case 0x0c0ae3f8u: goto P_0c0ae3f8;
case 0x0c0ae3fau: goto P_0c0ae3fa;
case 0x0c0ae3fcu: goto P_0c0ae3fc;
case 0x0c0ae3feu: goto P_0c0ae3fe;
case 0x0c0ae400u: goto P_0c0ae400;
case 0x0c0ae402u: goto P_0c0ae402;
case 0x0c0ae404u: goto P_0c0ae404;
case 0x0c0ae406u: goto P_0c0ae406;
case 0x0c0ae408u: goto P_0c0ae408;
case 0x0c0ae40au: goto P_0c0ae40a;
case 0x0c0ae40cu: goto P_0c0ae40c;
case 0x0c0ae40eu: goto P_0c0ae40e;
case 0x0c0ae410u: goto P_0c0ae410;
case 0x0c0ae412u: goto P_0c0ae412;
case 0x0c0ae414u: goto P_0c0ae414;
case 0x0c0ae416u: goto P_0c0ae416;
case 0x0c0ae418u: goto P_0c0ae418;
case 0x0c0ae41au: goto P_0c0ae41a;
case 0x0c0ae41cu: goto P_0c0ae41c;
case 0x0c0ae41eu: goto P_0c0ae41e;
case 0x0c0ae420u: goto P_0c0ae420;
case 0x0c0ae422u: goto P_0c0ae422;
case 0x0c0ae424u: goto P_0c0ae424;
case 0x0c0af728u: goto P_0c0af728;
case 0x0c0af72au: goto P_0c0af72a;
case 0x0c0af72cu: goto P_0c0af72c;
case 0x0c0af72eu: goto P_0c0af72e;
case 0x0c0af730u: goto P_0c0af730;
case 0x0c0af732u: goto P_0c0af732;
case 0x0c0af734u: goto P_0c0af734;
case 0x0c0af736u: goto P_0c0af736;
case 0x0c0af738u: goto P_0c0af738;
case 0x0c0af73au: goto P_0c0af73a;
case 0x0c0af73cu: goto P_0c0af73c;
case 0x0c0af73eu: goto P_0c0af73e;
case 0x0c0af740u: goto P_0c0af740;
case 0x0c0af742u: goto P_0c0af742;
case 0x0c0af744u: goto P_0c0af744;
case 0x0c0af746u: goto P_0c0af746;
case 0x0c0af748u: goto P_0c0af748;
case 0x0c0af74au: goto P_0c0af74a;
case 0x0c0af74cu: goto P_0c0af74c;
case 0x0c0af74eu: goto P_0c0af74e;
case 0x0c0af750u: goto P_0c0af750;
case 0x0c0af752u: goto P_0c0af752;
case 0x0c0af754u: goto P_0c0af754;
case 0x0c0af756u: goto P_0c0af756;
case 0x0c0af758u: goto P_0c0af758;
case 0x0c0af75au: goto P_0c0af75a;
case 0x0c0af75cu: goto P_0c0af75c;
case 0x0c0af75eu: goto P_0c0af75e;
case 0x0c0af760u: goto P_0c0af760;
case 0x0c0af762u: goto P_0c0af762;
case 0x0c0af764u: goto P_0c0af764;
case 0x0c0af766u: goto P_0c0af766;
case 0x0c0af768u: goto P_0c0af768;
case 0x0c0af76au: goto P_0c0af76a;
case 0x0c0af76cu: goto P_0c0af76c;
case 0x0c0af76eu: goto P_0c0af76e;
case 0x0c0af770u: goto P_0c0af770;
case 0x0c0af772u: goto P_0c0af772;
case 0x0c0af774u: goto P_0c0af774;
case 0x0c0af776u: goto P_0c0af776;
case 0x0c0af778u: goto P_0c0af778;
case 0x0c0af77au: goto P_0c0af77a;
case 0x0c0af77cu: goto P_0c0af77c;
case 0x0c0af77eu: goto P_0c0af77e;
case 0x0c0af780u: goto P_0c0af780;
case 0x0c0af782u: goto P_0c0af782;
case 0x0c0af784u: goto P_0c0af784;
case 0x0c0af786u: goto P_0c0af786;
case 0x0c0af788u: goto P_0c0af788;
case 0x0c0af78au: goto P_0c0af78a;
case 0x0c0af78cu: goto P_0c0af78c;
case 0x0c0af78eu: goto P_0c0af78e;
case 0x0c0af790u: goto P_0c0af790;
case 0x0c0af792u: goto P_0c0af792;
case 0x0c0af794u: goto P_0c0af794;
case 0x0c0af796u: goto P_0c0af796;
case 0x0c0af798u: goto P_0c0af798;
case 0x0c0af79au: goto P_0c0af79a;
case 0x0c0af79cu: goto P_0c0af79c;
case 0x0c0af79eu: goto P_0c0af79e;
case 0x0c0af7a0u: goto P_0c0af7a0;
case 0x0c0af7a2u: goto P_0c0af7a2;
case 0x0c0af7a4u: goto P_0c0af7a4;
case 0x0c0af7a6u: goto P_0c0af7a6;
case 0x0c0af7a8u: goto P_0c0af7a8;
case 0x0c0af7aau: goto P_0c0af7aa;
case 0x0c0af7acu: goto P_0c0af7ac;
case 0x0c0af7aeu: goto P_0c0af7ae;
case 0x0c0af7b0u: goto P_0c0af7b0;
case 0x0c0af7b2u: goto P_0c0af7b2;
case 0x0c0af7b4u: goto P_0c0af7b4;
case 0x0c0af7b6u: goto P_0c0af7b6;
case 0x0c0af7b8u: goto P_0c0af7b8;
case 0x0c0af7bau: goto P_0c0af7ba;
case 0x0c0af7bcu: goto P_0c0af7bc;
case 0x0c0af7beu: goto P_0c0af7be;
case 0x0c0af7c0u: goto P_0c0af7c0;
case 0x0c0af7c2u: goto P_0c0af7c2;
case 0x0c0af7c4u: goto P_0c0af7c4;
case 0x0c0af7c6u: goto P_0c0af7c6;
case 0x0c0af7c8u: goto P_0c0af7c8;
case 0x0c0af7cau: goto P_0c0af7ca;
case 0x0c0af7ccu: goto P_0c0af7cc;
case 0x0c0af7ceu: goto P_0c0af7ce;
case 0x0c0af7d0u: goto P_0c0af7d0;
case 0x0c0af7d2u: goto P_0c0af7d2;
case 0x0c0af7d4u: goto P_0c0af7d4;
case 0x0c0af7d6u: goto P_0c0af7d6;
case 0x0c0af7d8u: goto P_0c0af7d8;
case 0x0c0af7dau: goto P_0c0af7da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: goto P_0c0af728;
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0ae318: /* original 2fe6, guest PC 0x0c0ae318 */
if(!s->budget--) { s->failed_pc=0x0c0ae318u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae31a;
P_0c0ae31a: /* original 6e43, guest PC 0x0c0ae31a */
if(!s->budget--) { s->failed_pc=0x0c0ae31au; return 0; }
r[14]=r[4];
goto P_0c0ae31c;
P_0c0ae31c: /* original 2fd6, guest PC 0x0c0ae31c */
if(!s->budget--) { s->failed_pc=0x0c0ae31cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae31e;
P_0c0ae31e: /* original 6d63, guest PC 0x0c0ae31e */
if(!s->budget--) { s->failed_pc=0x0c0ae31eu; return 0; }
r[13]=r[6];
goto P_0c0ae320;
P_0c0ae320: /* original 2fc6, guest PC 0x0c0ae320 */
if(!s->budget--) { s->failed_pc=0x0c0ae320u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ae322;
P_0c0ae322: /* original fffb, guest PC 0x0c0ae322 */
if(!s->budget--) { s->failed_pc=0x0c0ae322u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ae324;
P_0c0ae324: /* original 4f22, guest PC 0x0c0ae324 */
if(!s->budget--) { s->failed_pc=0x0c0ae324u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae326;
P_0c0ae326: /* original 7fe4, guest PC 0x0c0ae326 */
if(!s->budget--) { s->failed_pc=0x0c0ae326u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0ae328;
P_0c0ae328: /* original 1f51, guest PC 0x0c0ae328 */
if(!s->budget--) { s->failed_pc=0x0c0ae328u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0ae32a;
P_0c0ae32a: /* original d340, guest PC 0x0c0ae32a */
if(!s->budget--) { s->failed_pc=0x0c0ae32au; return 0; }
r[3]=read(ram,0x0c0ae42cu,4);
goto P_0c0ae32c;
P_0c0ae32c: /* original d43e, guest PC 0x0c0ae32c */
if(!s->budget--) { s->failed_pc=0x0c0ae32cu; return 0; }
r[4]=read(ram,0x0c0ae428u,4);
goto P_0c0ae32e;
P_0c0ae32e: /* original 1f32, guest PC 0x0c0ae32e */
if(!s->budget--) { s->failed_pc=0x0c0ae32eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ae330;
P_0c0ae330: /* original 52d1, guest PC 0x0c0ae330 */
if(!s->budget--) { s->failed_pc=0x0c0ae330u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ae332;
P_0c0ae332: /* original 61d2, guest PC 0x0c0ae332 */
if(!s->budget--) { s->failed_pc=0x0c0ae332u; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c0ae334;
P_0c0ae334: /* original 3120, guest PC 0x0c0ae334 */
if(!s->budget--) { s->failed_pc=0x0c0ae334u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0ae336;
P_0c0ae336: /* original 8b68, guest PC 0x0c0ae336 */
if(!s->budget--) { s->failed_pc=0x0c0ae336u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae338;
P_0c0ae338: /* original 5341, guest PC 0x0c0ae338 */
if(!s->budget--) { s->failed_pc=0x0c0ae338u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0ae33a;
P_0c0ae33a: /* original d53d, guest PC 0x0c0ae33a */
if(!s->budget--) { s->failed_pc=0x0c0ae33au; return 0; }
r[5]=read(ram,0x0c0ae430u,4);
goto P_0c0ae33c;
P_0c0ae33c: /* original 2358, guest PC 0x0c0ae33c */
if(!s->budget--) { s->failed_pc=0x0c0ae33cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0ae33e;
P_0c0ae33e: /* original 8b64, guest PC 0x0c0ae33e */
if(!s->budget--) { s->failed_pc=0x0c0ae33eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae340;
P_0c0ae340: /* original 6242, guest PC 0x0c0ae340 */
if(!s->budget--) { s->failed_pc=0x0c0ae340u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ae342;
P_0c0ae342: /* original 2528, guest PC 0x0c0ae342 */
if(!s->budget--) { s->failed_pc=0x0c0ae342u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0ae344;
P_0c0ae344: /* original 8b61, guest PC 0x0c0ae344 */
if(!s->budget--) { s->failed_pc=0x0c0ae344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae40a; }
goto P_0c0ae346;
P_0c0ae346: /* original 54d2, guest PC 0x0c0ae346 */
if(!s->budget--) { s->failed_pc=0x0c0ae346u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0ae348;
P_0c0ae348: /* original 9c6d, guest PC 0x0c0ae348 */
if(!s->budget--) { s->failed_pc=0x0c0ae348u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae426u,2);
goto P_0c0ae34a;
P_0c0ae34a: /* original 8444, guest PC 0x0c0ae34a */
if(!s->budget--) { s->failed_pc=0x0c0ae34au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0ae34c;
P_0c0ae34c: /* original d339, guest PC 0x0c0ae34c */
if(!s->budget--) { s->failed_pc=0x0c0ae34cu; return 0; }
r[3]=read(ram,0x0c0ae434u,4);
goto P_0c0ae34e;
P_0c0ae34e: /* original 600c, guest PC 0x0c0ae34e */
if(!s->budget--) { s->failed_pc=0x0c0ae34eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae350;
P_0c0ae350: /* original 62e2, guest PC 0x0c0ae350 */
if(!s->budget--) { s->failed_pc=0x0c0ae350u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ae352;
P_0c0ae352: /* original 4018, guest PC 0x0c0ae352 */
if(!s->budget--) { s->failed_pc=0x0c0ae352u; return 0; }
r[0]<<=8;
goto P_0c0ae354;
P_0c0ae354: /* original 2c09, guest PC 0x0c0ae354 */
if(!s->budget--) { s->failed_pc=0x0c0ae354u; return 0; }
r[12]&=r[0];
goto P_0c0ae356;
P_0c0ae356: /* original 8443, guest PC 0x0c0ae356 */
if(!s->budget--) { s->failed_pc=0x0c0ae356u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0ae358;
P_0c0ae358: /* original 2238, guest PC 0x0c0ae358 */
if(!s->budget--) { s->failed_pc=0x0c0ae358u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ae35a;
P_0c0ae35a: /* original 600c, guest PC 0x0c0ae35a */
if(!s->budget--) { s->failed_pc=0x0c0ae35au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae35c;
P_0c0ae35c: /* original 8d01, guest PC 0x0c0ae35c */
if(!s->budget--) { s->failed_pc=0x0c0ae35cu; return 0; }
cond=r[17]&1u;
r[12]|=r[0];
if(cond) { goto P_0c0ae362; }
goto P_0c0ae360;
P_0c0ae35e: /* original 2c0b, guest PC 0x0c0ae35e */
if(!s->budget--) { s->failed_pc=0x0c0ae35eu; return 0; }
r[12]|=r[0];
goto P_0c0ae360;
P_0c0ae360: /* original 6ccb, guest PC 0x0c0ae360 */
if(!s->budget--) { s->failed_pc=0x0c0ae360u; return 0; }
r[12]=0u-r[12];
goto P_0c0ae362;
P_0c0ae362: /* original 85ef, guest PC 0x0c0ae362 */
if(!s->budget--) { s->failed_pc=0x0c0ae362u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ae364;
P_0c0ae364: /* original d334, guest PC 0x0c0ae364 */
if(!s->budget--) { s->failed_pc=0x0c0ae364u; return 0; }
r[3]=read(ram,0x0c0ae438u,4);
goto P_0c0ae366;
P_0c0ae366: /* original 3c0c, guest PC 0x0c0ae366 */
if(!s->budget--) { s->failed_pc=0x0c0ae366u; return 0; }
r[12]+=r[0];
goto P_0c0ae368;
P_0c0ae368: /* original 64cb, guest PC 0x0c0ae368 */
if(!s->budget--) { s->failed_pc=0x0c0ae368u; return 0; }
r[4]=0u-r[12];
goto P_0c0ae36a;
P_0c0ae36a: /* original 644f, guest PC 0x0c0ae36a */
if(!s->budget--) { s->failed_pc=0x0c0ae36au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ae36c;
P_0c0ae36c: /* original 430b, guest PC 0x0c0ae36c */
if(!s->budget--) { s->failed_pc=0x0c0ae36cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae370u;
write(ram,r[15],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae370u) { target=s->pc; goto dispatch; }
goto P_0c0ae370;
P_0c0ae36e: /* original 2f42, guest PC 0x0c0ae36e */
if(!s->budget--) { s->failed_pc=0x0c0ae36eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0ae370;
P_0c0ae370: /* original d332, guest PC 0x0c0ae370 */
if(!s->budget--) { s->failed_pc=0x0c0ae370u; return 0; }
r[3]=read(ram,0x0c0ae43cu,4);
goto P_0c0ae372;
P_0c0ae372: /* original ff0c, guest PC 0x0c0ae372 */
if(!s->budget--) { s->failed_pc=0x0c0ae372u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0ae374;
P_0c0ae374: /* original 430b, guest PC 0x0c0ae374 */
if(!s->budget--) { s->failed_pc=0x0c0ae374u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ae378u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae378u) { target=s->pc; goto dispatch; }
goto P_0c0ae378;
P_0c0ae376: /* original 64f2, guest PC 0x0c0ae376 */
if(!s->budget--) { s->failed_pc=0x0c0ae376u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ae378;
P_0c0ae378: /* original 64f3, guest PC 0x0c0ae378 */
if(!s->budget--) { s->failed_pc=0x0c0ae378u; return 0; }
r[4]=r[15];
goto P_0c0ae37a;
P_0c0ae37a: /* original 740c, guest PC 0x0c0ae37a */
if(!s->budget--) { s->failed_pc=0x0c0ae37au; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ae37c;
P_0c0ae37c: /* original 6543, guest PC 0x0c0ae37c */
if(!s->budget--) { s->failed_pc=0x0c0ae37cu; return 0; }
r[5]=r[4];
goto P_0c0ae37e;
P_0c0ae37e: /* original 6643, guest PC 0x0c0ae37e */
if(!s->budget--) { s->failed_pc=0x0c0ae37eu; return 0; }
r[6]=r[4];
goto P_0c0ae380;
P_0c0ae380: /* original 54d2, guest PC 0x0c0ae380 */
if(!s->budget--) { s->failed_pc=0x0c0ae380u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0ae382;
P_0c0ae382: /* original d330, guest PC 0x0c0ae382 */
if(!s->budget--) { s->failed_pc=0x0c0ae382u; return 0; }
r[3]=read(ram,0x0c0ae444u,4);
goto P_0c0ae384;
P_0c0ae384: /* original 8448, guest PC 0x0c0ae384 */
if(!s->budget--) { s->failed_pc=0x0c0ae384u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0ae386;
P_0c0ae386: /* original d230, guest PC 0x0c0ae386 */
if(!s->budget--) { s->failed_pc=0x0c0ae386u; return 0; }
r[2]=read(ram,0x0c0ae448u,4);
goto P_0c0ae388;
P_0c0ae388: /* original 600c, guest PC 0x0c0ae388 */
if(!s->budget--) { s->failed_pc=0x0c0ae388u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae38a;
P_0c0ae38a: /* original d72d, guest PC 0x0c0ae38a */
if(!s->budget--) { s->failed_pc=0x0c0ae38au; return 0; }
r[7]=read(ram,0x0c0ae440u,4);
goto P_0c0ae38c;
P_0c0ae38c: /* original 4028, guest PC 0x0c0ae38c */
if(!s->budget--) { s->failed_pc=0x0c0ae38cu; return 0; }
r[0]<<=16;
goto P_0c0ae38e;
P_0c0ae38e: /* original f50c, guest PC 0x0c0ae38e */
if(!s->budget--) { s->failed_pc=0x0c0ae38eu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0ae390;
P_0c0ae390: /* original 4018, guest PC 0x0c0ae390 */
if(!s->budget--) { s->failed_pc=0x0c0ae390u; return 0; }
r[0]<<=8;
goto P_0c0ae392;
P_0c0ae392: /* original 2039, guest PC 0x0c0ae392 */
if(!s->budget--) { s->failed_pc=0x0c0ae392u; return 0; }
r[0]&=r[3];
goto P_0c0ae394;
P_0c0ae394: /* original 6103, guest PC 0x0c0ae394 */
if(!s->budget--) { s->failed_pc=0x0c0ae394u; return 0; }
r[1]=r[0];
goto P_0c0ae396;
P_0c0ae396: /* original 8447, guest PC 0x0c0ae396 */
if(!s->budget--) { s->failed_pc=0x0c0ae396u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c0ae398;
P_0c0ae398: /* original 600c, guest PC 0x0c0ae398 */
if(!s->budget--) { s->failed_pc=0x0c0ae398u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae39a;
P_0c0ae39a: /* original 4028, guest PC 0x0c0ae39a */
if(!s->budget--) { s->failed_pc=0x0c0ae39au; return 0; }
r[0]<<=16;
goto P_0c0ae39c;
P_0c0ae39c: /* original 2029, guest PC 0x0c0ae39c */
if(!s->budget--) { s->failed_pc=0x0c0ae39cu; return 0; }
r[0]&=r[2];
goto P_0c0ae39e;
P_0c0ae39e: /* original 210b, guest PC 0x0c0ae39e */
if(!s->budget--) { s->failed_pc=0x0c0ae39eu; return 0; }
r[1]|=r[0];
goto P_0c0ae3a0;
P_0c0ae3a0: /* original 8446, guest PC 0x0c0ae3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0ae3a2;
P_0c0ae3a2: /* original 600c, guest PC 0x0c0ae3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3a4;
P_0c0ae3a4: /* original 4018, guest PC 0x0c0ae3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a4u; return 0; }
r[0]<<=8;
goto P_0c0ae3a6;
P_0c0ae3a6: /* original 2079, guest PC 0x0c0ae3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a6u; return 0; }
r[0]&=r[7];
goto P_0c0ae3a8;
P_0c0ae3a8: /* original 210b, guest PC 0x0c0ae3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3a8u; return 0; }
r[1]|=r[0];
goto P_0c0ae3aa;
P_0c0ae3aa: /* original 8445, guest PC 0x0c0ae3aa */
if(!s->budget--) { s->failed_pc=0x0c0ae3aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0ae3ac;
P_0c0ae3ac: /* original 600c, guest PC 0x0c0ae3ac */
if(!s->budget--) { s->failed_pc=0x0c0ae3acu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3ae;
P_0c0ae3ae: /* original 210b, guest PC 0x0c0ae3ae */
if(!s->budget--) { s->failed_pc=0x0c0ae3aeu; return 0; }
r[1]|=r[0];
goto P_0c0ae3b0;
P_0c0ae3b0: /* original 2f12, guest PC 0x0c0ae3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b0u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ae3b2;
P_0c0ae3b2: /* original 844c, guest PC 0x0c0ae3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+12,1);
goto P_0c0ae3b4;
P_0c0ae3b4: /* original 600c, guest PC 0x0c0ae3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3b6;
P_0c0ae3b6: /* original 4028, guest PC 0x0c0ae3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b6u; return 0; }
r[0]<<=16;
goto P_0c0ae3b8;
P_0c0ae3b8: /* original 4018, guest PC 0x0c0ae3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3b8u; return 0; }
r[0]<<=8;
goto P_0c0ae3ba;
P_0c0ae3ba: /* original 2039, guest PC 0x0c0ae3ba */
if(!s->budget--) { s->failed_pc=0x0c0ae3bau; return 0; }
r[0]&=r[3];
goto P_0c0ae3bc;
P_0c0ae3bc: /* original 6103, guest PC 0x0c0ae3bc */
if(!s->budget--) { s->failed_pc=0x0c0ae3bcu; return 0; }
r[1]=r[0];
goto P_0c0ae3be;
P_0c0ae3be: /* original 844b, guest PC 0x0c0ae3be */
if(!s->budget--) { s->failed_pc=0x0c0ae3beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c0ae3c0;
P_0c0ae3c0: /* original 600c, guest PC 0x0c0ae3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3c2;
P_0c0ae3c2: /* original 4028, guest PC 0x0c0ae3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c2u; return 0; }
r[0]<<=16;
goto P_0c0ae3c4;
P_0c0ae3c4: /* original 2029, guest PC 0x0c0ae3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c4u; return 0; }
r[0]&=r[2];
goto P_0c0ae3c6;
P_0c0ae3c6: /* original 210b, guest PC 0x0c0ae3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c6u; return 0; }
r[1]|=r[0];
goto P_0c0ae3c8;
P_0c0ae3c8: /* original 844a, guest PC 0x0c0ae3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0ae3ca;
P_0c0ae3ca: /* original 600c, guest PC 0x0c0ae3ca */
if(!s->budget--) { s->failed_pc=0x0c0ae3cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3cc;
P_0c0ae3cc: /* original 4018, guest PC 0x0c0ae3cc */
if(!s->budget--) { s->failed_pc=0x0c0ae3ccu; return 0; }
r[0]<<=8;
goto P_0c0ae3ce;
P_0c0ae3ce: /* original 2079, guest PC 0x0c0ae3ce */
if(!s->budget--) { s->failed_pc=0x0c0ae3ceu; return 0; }
r[0]&=r[7];
goto P_0c0ae3d0;
P_0c0ae3d0: /* original 210b, guest PC 0x0c0ae3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d0u; return 0; }
r[1]|=r[0];
goto P_0c0ae3d2;
P_0c0ae3d2: /* original 8449, guest PC 0x0c0ae3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c0ae3d4;
P_0c0ae3d4: /* original 6413, guest PC 0x0c0ae3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d4u; return 0; }
r[4]=r[1];
goto P_0c0ae3d6;
P_0c0ae3d6: /* original 61f2, guest PC 0x0c0ae3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d6u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0ae3d8;
P_0c0ae3d8: /* original 600c, guest PC 0x0c0ae3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae3da;
P_0c0ae3da: /* original 2612, guest PC 0x0c0ae3da */
if(!s->budget--) { s->failed_pc=0x0c0ae3dau; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0ae3dc;
P_0c0ae3dc: /* original 240b, guest PC 0x0c0ae3dc */
if(!s->budget--) { s->failed_pc=0x0c0ae3dcu; return 0; }
r[4]|=r[0];
goto P_0c0ae3de;
P_0c0ae3de: /* original e004, guest PC 0x0c0ae3de */
if(!s->budget--) { s->failed_pc=0x0c0ae3deu; return 0; }
r[0]=0x00000004u;
goto P_0c0ae3e0;
P_0c0ae3e0: /* original 1641, guest PC 0x0c0ae3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e0u; return 0; }
write(ram,r[6]+4,r[4],4);
goto P_0c0ae3e2;
P_0c0ae3e2: /* original f658, guest PC 0x0c0ae3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e2u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c0ae3e4;
P_0c0ae3e4: /* original 51f2, guest PC 0x0c0ae3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e4u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0ae3e6;
P_0c0ae3e6: /* original ff62, guest PC 0x0c0ae3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c0ae3e8;
P_0c0ae3e8: /* original f456, guest PC 0x0c0ae3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3e8u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0ae3ea;
P_0c0ae3ea: /* original f562, guest PC 0x0c0ae3ea */
if(!s->budget--) { s->failed_pc=0x0c0ae3eau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ae3ec;
P_0c0ae3ec: /* original f618, guest PC 0x0c0ae3ec */
if(!s->budget--) { s->failed_pc=0x0c0ae3ecu; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c0ae3ee;
P_0c0ae3ee: /* original e024, guest PC 0x0c0ae3ee */
if(!s->budget--) { s->failed_pc=0x0c0ae3eeu; return 0; }
r[0]=0x00000024u;
goto P_0c0ae3f0;
P_0c0ae3f0: /* original f462, guest PC 0x0c0ae3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ae3f2;
P_0c0ae3f2: /* original fef7, guest PC 0x0c0ae3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0ae3f4;
P_0c0ae3f4: /* original e028, guest PC 0x0c0ae3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f4u; return 0; }
r[0]=0x00000028u;
goto P_0c0ae3f6;
P_0c0ae3f6: /* original fe47, guest PC 0x0c0ae3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ae3f8;
P_0c0ae3f8: /* original 66d3, guest PC 0x0c0ae3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae3f8u; return 0; }
r[6]=r[13];
goto P_0c0ae3fa;
P_0c0ae3fa: /* original e02c, guest PC 0x0c0ae3fa */
if(!s->budget--) { s->failed_pc=0x0c0ae3fau; return 0; }
r[0]=0x0000002cu;
goto P_0c0ae3fc;
P_0c0ae3fc: /* original f54d, guest PC 0x0c0ae3fc */
if(!s->budget--) { s->failed_pc=0x0c0ae3fcu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0ae3fe;
P_0c0ae3fe: /* original 65e3, guest PC 0x0c0ae3fe */
if(!s->budget--) { s->failed_pc=0x0c0ae3feu; return 0; }
r[5]=r[14];
goto P_0c0ae400;
P_0c0ae400: /* original fe57, guest PC 0x0c0ae400 */
if(!s->budget--) { s->failed_pc=0x0c0ae400u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ae402;
P_0c0ae402: /* original 760c, guest PC 0x0c0ae402 */
if(!s->budget--) { s->failed_pc=0x0c0ae402u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ae404;
P_0c0ae404: /* original d111, guest PC 0x0c0ae404 */
if(!s->budget--) { s->failed_pc=0x0c0ae404u; return 0; }
r[1]=read(ram,0x0c0ae44cu,4);
goto P_0c0ae406;
P_0c0ae406: /* original 410b, guest PC 0x0c0ae406 */
if(!s->budget--) { s->failed_pc=0x0c0ae406u; return 0; }
target=r[1];
r[16]=code_base|0x0c0ae40au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae40au) { target=s->pc; goto dispatch; }
goto P_0c0ae40a;
P_0c0ae408: /* original 64e3, guest PC 0x0c0ae408 */
if(!s->budget--) { s->failed_pc=0x0c0ae408u; return 0; }
r[4]=r[14];
goto P_0c0ae40a;
P_0c0ae40a: /* original 53d2, guest PC 0x0c0ae40a */
if(!s->budget--) { s->failed_pc=0x0c0ae40au; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0ae40c;
P_0c0ae40c: /* original 66d3, guest PC 0x0c0ae40c */
if(!s->budget--) { s->failed_pc=0x0c0ae40cu; return 0; }
r[6]=r[13];
goto P_0c0ae40e;
P_0c0ae40e: /* original 730d, guest PC 0x0c0ae40e */
if(!s->budget--) { s->failed_pc=0x0c0ae40eu; return 0; }
r[3]+=0x0000000du;
goto P_0c0ae410;
P_0c0ae410: /* original 1d32, guest PC 0x0c0ae410 */
if(!s->budget--) { s->failed_pc=0x0c0ae410u; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0ae412;
P_0c0ae412: /* original 55f1, guest PC 0x0c0ae412 */
if(!s->budget--) { s->failed_pc=0x0c0ae412u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0ae414;
P_0c0ae414: /* original bf42, guest PC 0x0c0ae414 */
if(!s->budget--) { s->failed_pc=0x0c0ae414u; return 0; }
target=code_base|0x0c0ae29cu; r[16]=code_base|0x0c0ae418u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ae418u) { target=s->pc; goto dispatch; }
goto P_0c0ae418;
P_0c0ae416: /* original 64e3, guest PC 0x0c0ae416 */
if(!s->budget--) { s->failed_pc=0x0c0ae416u; return 0; }
r[4]=r[14];
goto P_0c0ae418;
P_0c0ae418: /* original 7f1c, guest PC 0x0c0ae418 */
if(!s->budget--) { s->failed_pc=0x0c0ae418u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ae41a;
P_0c0ae41a: /* original 4f26, guest PC 0x0c0ae41a */
if(!s->budget--) { s->failed_pc=0x0c0ae41au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae41c;
P_0c0ae41c: /* original fff9, guest PC 0x0c0ae41c */
if(!s->budget--) { s->failed_pc=0x0c0ae41cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ae41e;
P_0c0ae41e: /* original 6cf6, guest PC 0x0c0ae41e */
if(!s->budget--) { s->failed_pc=0x0c0ae41eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae420;
P_0c0ae420: /* original 6df6, guest PC 0x0c0ae420 */
if(!s->budget--) { s->failed_pc=0x0c0ae420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae422;
P_0c0ae422: /* original 000b, guest PC 0x0c0ae422 */
if(!s->budget--) { s->failed_pc=0x0c0ae422u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ae424: /* original 6ef6, guest PC 0x0c0ae424 */
if(!s->budget--) { s->failed_pc=0x0c0ae424u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ae426u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae426u; return 0; } return 1;
P_0c0af728: /* original 2fe6, guest PC 0x0c0af728 */
if(!s->budget--) { s->failed_pc=0x0c0af728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72a;
P_0c0af72a: /* original 6e43, guest PC 0x0c0af72a */
if(!s->budget--) { s->failed_pc=0x0c0af72au; return 0; }
r[14]=r[4];
goto P_0c0af72c;
P_0c0af72c: /* original 2fd6, guest PC 0x0c0af72c */
if(!s->budget--) { s->failed_pc=0x0c0af72cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af72e;
P_0c0af72e: /* original 6d63, guest PC 0x0c0af72e */
if(!s->budget--) { s->failed_pc=0x0c0af72eu; return 0; }
r[13]=r[6];
goto P_0c0af730;
P_0c0af730: /* original 53d2, guest PC 0x0c0af730 */
if(!s->budget--) { s->failed_pc=0x0c0af730u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0af732;
P_0c0af732: /* original 907a, guest PC 0x0c0af732 */
if(!s->budget--) { s->failed_pc=0x0c0af732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82au,2);
goto P_0c0af734;
P_0c0af734: /* original 4f22, guest PC 0x0c0af734 */
if(!s->budget--) { s->failed_pc=0x0c0af734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af736;
P_0c0af736: /* original d441, guest PC 0x0c0af736 */
if(!s->budget--) { s->failed_pc=0x0c0af736u; return 0; }
r[4]=read(ram,0x0c0af83cu,4);
goto P_0c0af738;
P_0c0af738: /* original 0e36, guest PC 0x0c0af738 */
if(!s->budget--) { s->failed_pc=0x0c0af738u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0af73a;
P_0c0af73a: /* original 9377, guest PC 0x0c0af73a */
if(!s->budget--) { s->failed_pc=0x0c0af73au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82cu,2);
goto P_0c0af73c;
P_0c0af73c: /* original 7ff8, guest PC 0x0c0af73c */
if(!s->budget--) { s->failed_pc=0x0c0af73cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af73e;
P_0c0af73e: /* original 52d3, guest PC 0x0c0af73e */
if(!s->budget--) { s->failed_pc=0x0c0af73eu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af740;
P_0c0af740: /* original 2238, guest PC 0x0c0af740 */
if(!s->budget--) { s->failed_pc=0x0c0af740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af742;
P_0c0af742: /* original 890e, guest PC 0x0c0af742 */
if(!s->budget--) { s->failed_pc=0x0c0af742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af762; }
goto P_0c0af744;
P_0c0af744: /* original 51d3, guest PC 0x0c0af744 */
if(!s->budget--) { s->failed_pc=0x0c0af744u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af746;
P_0c0af746: /* original 9372, guest PC 0x0c0af746 */
if(!s->budget--) { s->failed_pc=0x0c0af746u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af82eu,2);
goto P_0c0af748;
P_0c0af748: /* original 2139, guest PC 0x0c0af748 */
if(!s->budget--) { s->failed_pc=0x0c0af748u; return 0; }
r[1]&=r[3];
goto P_0c0af74a;
P_0c0af74a: /* original 1d13, guest PC 0x0c0af74a */
if(!s->budget--) { s->failed_pc=0x0c0af74au; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af74c;
P_0c0af74c: /* original d53c, guest PC 0x0c0af74c */
if(!s->budget--) { s->failed_pc=0x0c0af74cu; return 0; }
r[5]=read(ram,0x0c0af840u,4);
goto P_0c0af74e;
P_0c0af74e: /* original 5241, guest PC 0x0c0af74e */
if(!s->budget--) { s->failed_pc=0x0c0af74eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0af750;
P_0c0af750: /* original 2258, guest PC 0x0c0af750 */
if(!s->budget--) { s->failed_pc=0x0c0af750u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0af752;
P_0c0af752: /* original 8b06, guest PC 0x0c0af752 */
if(!s->budget--) { s->failed_pc=0x0c0af752u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af754;
P_0c0af754: /* original 6342, guest PC 0x0c0af754 */
if(!s->budget--) { s->failed_pc=0x0c0af754u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0af756;
P_0c0af756: /* original 2538, guest PC 0x0c0af756 */
if(!s->budget--) { s->failed_pc=0x0c0af756u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0af758;
P_0c0af758: /* original 8b03, guest PC 0x0c0af758 */
if(!s->budget--) { s->failed_pc=0x0c0af758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af762; }
goto P_0c0af75a;
P_0c0af75a: /* original 85ef, guest PC 0x0c0af75a */
if(!s->budget--) { s->failed_pc=0x0c0af75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af75c;
P_0c0af75c: /* original 9368, guest PC 0x0c0af75c */
if(!s->budget--) { s->failed_pc=0x0c0af75cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af830u,2);
goto P_0c0af75e;
P_0c0af75e: /* original 303c, guest PC 0x0c0af75e */
if(!s->budget--) { s->failed_pc=0x0c0af75eu; return 0; }
r[0]+=r[3];
goto P_0c0af760;
P_0c0af760: /* original 81ef, guest PC 0x0c0af760 */
if(!s->budget--) { s->failed_pc=0x0c0af760u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0af762;
P_0c0af762: /* original 53d4, guest PC 0x0c0af762 */
if(!s->budget--) { s->failed_pc=0x0c0af762u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0af764;
P_0c0af764: /* original d437, guest PC 0x0c0af764 */
if(!s->budget--) { s->failed_pc=0x0c0af764u; return 0; }
r[4]=read(ram,0x0c0af844u,4);
goto P_0c0af766;
P_0c0af766: /* original 2348, guest PC 0x0c0af766 */
if(!s->budget--) { s->failed_pc=0x0c0af766u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af768;
P_0c0af768: /* original 8903, guest PC 0x0c0af768 */
if(!s->budget--) { s->failed_pc=0x0c0af768u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af772; }
goto P_0c0af76a;
P_0c0af76a: /* original 52d3, guest PC 0x0c0af76a */
if(!s->budget--) { s->failed_pc=0x0c0af76au; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af76c;
P_0c0af76c: /* original d336, guest PC 0x0c0af76c */
if(!s->budget--) { s->failed_pc=0x0c0af76cu; return 0; }
r[3]=read(ram,0x0c0af848u,4);
goto P_0c0af76e;
P_0c0af76e: /* original 223b, guest PC 0x0c0af76e */
if(!s->budget--) { s->failed_pc=0x0c0af76eu; return 0; }
r[2]|=r[3];
goto P_0c0af770;
P_0c0af770: /* original 1d23, guest PC 0x0c0af770 */
if(!s->budget--) { s->failed_pc=0x0c0af770u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af772;
P_0c0af772: /* original 51d3, guest PC 0x0c0af772 */
if(!s->budget--) { s->failed_pc=0x0c0af772u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af774;
P_0c0af774: /* original 2418, guest PC 0x0c0af774 */
if(!s->budget--) { s->failed_pc=0x0c0af774u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0af776;
P_0c0af776: /* original 891e, guest PC 0x0c0af776 */
if(!s->budget--) { s->failed_pc=0x0c0af776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7b6; }
goto P_0c0af778;
P_0c0af778: /* original d334, guest PC 0x0c0af778 */
if(!s->budget--) { s->failed_pc=0x0c0af778u; return 0; }
r[3]=read(ram,0x0c0af84cu,4);
goto P_0c0af77a;
P_0c0af77a: /* original 65f3, guest PC 0x0c0af77a */
if(!s->budget--) { s->failed_pc=0x0c0af77au; return 0; }
r[5]=r[15];
goto P_0c0af77c;
P_0c0af77c: /* original 52d3, guest PC 0x0c0af77c */
if(!s->budget--) { s->failed_pc=0x0c0af77cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af77e;
P_0c0af77e: /* original 66f3, guest PC 0x0c0af77e */
if(!s->budget--) { s->failed_pc=0x0c0af77eu; return 0; }
r[6]=r[15];
goto P_0c0af780;
P_0c0af780: /* original 2239, guest PC 0x0c0af780 */
if(!s->budget--) { s->failed_pc=0x0c0af780u; return 0; }
r[2]&=r[3];
goto P_0c0af782;
P_0c0af782: /* original 1d23, guest PC 0x0c0af782 */
if(!s->budget--) { s->failed_pc=0x0c0af782u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0af784;
P_0c0af784: /* original 85ef, guest PC 0x0c0af784 */
if(!s->budget--) { s->failed_pc=0x0c0af784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0af786;
P_0c0af786: /* original 640d, guest PC 0x0c0af786 */
if(!s->budget--) { s->failed_pc=0x0c0af786u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0af788;
P_0c0af788: /* original 9053, guest PC 0x0c0af788 */
if(!s->budget--) { s->failed_pc=0x0c0af788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af832u,2);
goto P_0c0af78a;
P_0c0af78a: /* original f3e6, guest PC 0x0c0af78a */
if(!s->budget--) { s->failed_pc=0x0c0af78au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af78c;
P_0c0af78c: /* original e004, guest PC 0x0c0af78c */
if(!s->budget--) { s->failed_pc=0x0c0af78cu; return 0; }
r[0]=0x00000004u;
goto P_0c0af78e;
P_0c0af78e: /* original ff37, guest PC 0x0c0af78e */
if(!s->budget--) { s->failed_pc=0x0c0af78eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0af790;
P_0c0af790: /* original 9050, guest PC 0x0c0af790 */
if(!s->budget--) { s->failed_pc=0x0c0af790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af834u,2);
goto P_0c0af792;
P_0c0af792: /* original f3e6, guest PC 0x0c0af792 */
if(!s->budget--) { s->failed_pc=0x0c0af792u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0af794;
P_0c0af794: /* original ff3a, guest PC 0x0c0af794 */
if(!s->budget--) { s->failed_pc=0x0c0af794u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0af796;
P_0c0af796: /* original d22e, guest PC 0x0c0af796 */
if(!s->budget--) { s->failed_pc=0x0c0af796u; return 0; }
r[2]=read(ram,0x0c0af850u,4);
goto P_0c0af798;
P_0c0af798: /* original 420b, guest PC 0x0c0af798 */
if(!s->budget--) { s->failed_pc=0x0c0af798u; return 0; }
target=r[2];
r[16]=code_base|0x0c0af79cu;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af79cu) { target=s->pc; goto dispatch; }
goto P_0c0af79c;
P_0c0af79a: /* original 7504, guest PC 0x0c0af79a */
if(!s->budget--) { s->failed_pc=0x0c0af79au; return 0; }
r[5]+=0x00000004u;
goto P_0c0af79c;
P_0c0af79c: /* original 904b, guest PC 0x0c0af79c */
if(!s->budget--) { s->failed_pc=0x0c0af79cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af836u,2);
goto P_0c0af79e;
P_0c0af79e: /* original f2f8, guest PC 0x0c0af79e */
if(!s->budget--) { s->failed_pc=0x0c0af79eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0af7a0;
P_0c0af7a0: /* original f5e6, guest PC 0x0c0af7a0 */
if(!s->budget--) { s->failed_pc=0x0c0af7a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0af7a2;
P_0c0af7a2: /* original 7008, guest PC 0x0c0af7a2 */
if(!s->budget--) { s->failed_pc=0x0c0af7a2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0af7a4;
P_0c0af7a4: /* original f4e6, guest PC 0x0c0af7a4 */
if(!s->budget--) { s->failed_pc=0x0c0af7a4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0af7a6;
P_0c0af7a6: /* original e004, guest PC 0x0c0af7a6 */
if(!s->budget--) { s->failed_pc=0x0c0af7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0af7a8;
P_0c0af7a8: /* original f3f6, guest PC 0x0c0af7a8 */
if(!s->budget--) { s->failed_pc=0x0c0af7a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0af7aa;
P_0c0af7aa: /* original e010, guest PC 0x0c0af7aa */
if(!s->budget--) { s->failed_pc=0x0c0af7aau; return 0; }
r[0]=0x00000010u;
goto P_0c0af7ac;
P_0c0af7ac: /* original f421, guest PC 0x0c0af7ac */
if(!s->budget--) { s->failed_pc=0x0c0af7acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0af7ae;
P_0c0af7ae: /* original f531, guest PC 0x0c0af7ae */
if(!s->budget--) { s->failed_pc=0x0c0af7aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0af7b0;
P_0c0af7b0: /* original fe57, guest PC 0x0c0af7b0 */
if(!s->budget--) { s->failed_pc=0x0c0af7b0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0af7b2;
P_0c0af7b2: /* original e018, guest PC 0x0c0af7b2 */
if(!s->budget--) { s->failed_pc=0x0c0af7b2u; return 0; }
r[0]=0x00000018u;
goto P_0c0af7b4;
P_0c0af7b4: /* original fe47, guest PC 0x0c0af7b4 */
if(!s->budget--) { s->failed_pc=0x0c0af7b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0af7b6;
P_0c0af7b6: /* original d327, guest PC 0x0c0af7b6 */
if(!s->budget--) { s->failed_pc=0x0c0af7b6u; return 0; }
r[3]=read(ram,0x0c0af854u,4);
goto P_0c0af7b8;
P_0c0af7b8: /* original 64e2, guest PC 0x0c0af7b8 */
if(!s->budget--) { s->failed_pc=0x0c0af7b8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0af7ba;
P_0c0af7ba: /* original 2348, guest PC 0x0c0af7ba */
if(!s->budget--) { s->failed_pc=0x0c0af7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0af7bc;
P_0c0af7bc: /* original 8906, guest PC 0x0c0af7bc */
if(!s->budget--) { s->failed_pc=0x0c0af7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af7cc; }
goto P_0c0af7be;
P_0c0af7be: /* original d226, guest PC 0x0c0af7be */
if(!s->budget--) { s->failed_pc=0x0c0af7beu; return 0; }
r[2]=read(ram,0x0c0af858u,4);
goto P_0c0af7c0;
P_0c0af7c0: /* original 2429, guest PC 0x0c0af7c0 */
if(!s->budget--) { s->failed_pc=0x0c0af7c0u; return 0; }
r[4]&=r[2];
goto P_0c0af7c2;
P_0c0af7c2: /* original 2e42, guest PC 0x0c0af7c2 */
if(!s->budget--) { s->failed_pc=0x0c0af7c2u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0af7c4;
P_0c0af7c4: /* original d325, guest PC 0x0c0af7c4 */
if(!s->budget--) { s->failed_pc=0x0c0af7c4u; return 0; }
r[3]=read(ram,0x0c0af85cu,4);
goto P_0c0af7c6;
P_0c0af7c6: /* original 51d3, guest PC 0x0c0af7c6 */
if(!s->budget--) { s->failed_pc=0x0c0af7c6u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0af7c8;
P_0c0af7c8: /* original 213b, guest PC 0x0c0af7c8 */
if(!s->budget--) { s->failed_pc=0x0c0af7c8u; return 0; }
r[1]|=r[3];
goto P_0c0af7ca;
P_0c0af7ca: /* original 1d13, guest PC 0x0c0af7ca */
if(!s->budget--) { s->failed_pc=0x0c0af7cau; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c0af7cc;
P_0c0af7cc: /* original 7f08, guest PC 0x0c0af7cc */
if(!s->budget--) { s->failed_pc=0x0c0af7ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0af7ce;
P_0c0af7ce: /* original 52d3, guest PC 0x0c0af7ce */
if(!s->budget--) { s->failed_pc=0x0c0af7ceu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0af7d0;
P_0c0af7d0: /* original 4f26, guest PC 0x0c0af7d0 */
if(!s->budget--) { s->failed_pc=0x0c0af7d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af7d2;
P_0c0af7d2: /* original e048, guest PC 0x0c0af7d2 */
if(!s->budget--) { s->failed_pc=0x0c0af7d2u; return 0; }
r[0]=0x00000048u;
goto P_0c0af7d4;
P_0c0af7d4: /* original 0e26, guest PC 0x0c0af7d4 */
if(!s->budget--) { s->failed_pc=0x0c0af7d4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af7d6;
P_0c0af7d6: /* original 6df6, guest PC 0x0c0af7d6 */
if(!s->budget--) { s->failed_pc=0x0c0af7d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af7d8;
P_0c0af7d8: /* original 000b, guest PC 0x0c0af7d8 */
if(!s->budget--) { s->failed_pc=0x0c0af7d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af7da: /* original 6ef6, guest PC 0x0c0af7da */
if(!s->budget--) { s->failed_pc=0x0c0af7dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af7dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af7dcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
