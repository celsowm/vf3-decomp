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
int vf3_away_batch22_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ade24u: goto P_0c0ade24;
case 0x0c0ade26u: goto P_0c0ade26;
case 0x0c0ade28u: goto P_0c0ade28;
case 0x0c0ade2au: goto P_0c0ade2a;
case 0x0c0ade2cu: goto P_0c0ade2c;
case 0x0c0ade2eu: goto P_0c0ade2e;
case 0x0c0ade30u: goto P_0c0ade30;
case 0x0c0ade32u: goto P_0c0ade32;
case 0x0c0ade34u: goto P_0c0ade34;
case 0x0c0ade36u: goto P_0c0ade36;
case 0x0c0ade38u: goto P_0c0ade38;
case 0x0c0ade3au: goto P_0c0ade3a;
case 0x0c0ade3cu: goto P_0c0ade3c;
case 0x0c0ade3eu: goto P_0c0ade3e;
case 0x0c0ade40u: goto P_0c0ade40;
case 0x0c0ade42u: goto P_0c0ade42;
case 0x0c0ade44u: goto P_0c0ade44;
case 0x0c0ade46u: goto P_0c0ade46;
case 0x0c0ade48u: goto P_0c0ade48;
case 0x0c0ade4au: goto P_0c0ade4a;
case 0x0c0ade4cu: goto P_0c0ade4c;
case 0x0c0ade4eu: goto P_0c0ade4e;
case 0x0c0ade50u: goto P_0c0ade50;
case 0x0c0ade52u: goto P_0c0ade52;
case 0x0c0ade54u: goto P_0c0ade54;
case 0x0c0ade56u: goto P_0c0ade56;
case 0x0c0ade58u: goto P_0c0ade58;
case 0x0c0ade5au: goto P_0c0ade5a;
case 0x0c0ade5cu: goto P_0c0ade5c;
case 0x0c0ade5eu: goto P_0c0ade5e;
case 0x0c0ade60u: goto P_0c0ade60;
case 0x0c0ade62u: goto P_0c0ade62;
case 0x0c0ade64u: goto P_0c0ade64;
case 0x0c0ade66u: goto P_0c0ade66;
case 0x0c0ade68u: goto P_0c0ade68;
case 0x0c0ade6au: goto P_0c0ade6a;
case 0x0c0ade6cu: goto P_0c0ade6c;
case 0x0c0ade6eu: goto P_0c0ade6e;
case 0x0c0ade70u: goto P_0c0ade70;
case 0x0c0ade72u: goto P_0c0ade72;
case 0x0c0ade74u: goto P_0c0ade74;
case 0x0c0ade76u: goto P_0c0ade76;
case 0x0c0ade78u: goto P_0c0ade78;
case 0x0c0ade7au: goto P_0c0ade7a;
case 0x0c0ade7cu: goto P_0c0ade7c;
case 0x0c0ade7eu: goto P_0c0ade7e;
case 0x0c0ade80u: goto P_0c0ade80;
case 0x0c0ade82u: goto P_0c0ade82;
case 0x0c0ade84u: goto P_0c0ade84;
case 0x0c0ade86u: goto P_0c0ade86;
case 0x0c0ade88u: goto P_0c0ade88;
case 0x0c0ade8au: goto P_0c0ade8a;
case 0x0c0ade8cu: goto P_0c0ade8c;
case 0x0c0ade8eu: goto P_0c0ade8e;
case 0x0c0ade90u: goto P_0c0ade90;
case 0x0c0ade92u: goto P_0c0ade92;
case 0x0c0ade94u: goto P_0c0ade94;
case 0x0c0ade96u: goto P_0c0ade96;
case 0x0c0ade98u: goto P_0c0ade98;
case 0x0c0ade9au: goto P_0c0ade9a;
case 0x0c0ade9cu: goto P_0c0ade9c;
case 0x0c0ade9eu: goto P_0c0ade9e;
case 0x0c0adea0u: goto P_0c0adea0;
case 0x0c0adea2u: goto P_0c0adea2;
case 0x0c0adea4u: goto P_0c0adea4;
case 0x0c0adea6u: goto P_0c0adea6;
case 0x0c0adea8u: goto P_0c0adea8;
case 0x0c0adeaau: goto P_0c0adeaa;
case 0x0c0adeacu: goto P_0c0adeac;
case 0x0c0adeaeu: goto P_0c0adeae;
case 0x0c0adeb0u: goto P_0c0adeb0;
case 0x0c0adeb2u: goto P_0c0adeb2;
case 0x0c0adeb4u: goto P_0c0adeb4;
case 0x0c0adeb6u: goto P_0c0adeb6;
case 0x0c0adeb8u: goto P_0c0adeb8;
case 0x0c0adebau: goto P_0c0adeba;
case 0x0c0adebcu: goto P_0c0adebc;
case 0x0c0adebeu: goto P_0c0adebe;
case 0x0c0adec0u: goto P_0c0adec0;
case 0x0c0adec2u: goto P_0c0adec2;
case 0x0c0adec4u: goto P_0c0adec4;
case 0x0c0adec6u: goto P_0c0adec6;
case 0x0c0adec8u: goto P_0c0adec8;
case 0x0c0adecau: goto P_0c0adeca;
case 0x0c0adeccu: goto P_0c0adecc;
case 0x0c0adeceu: goto P_0c0adece;
case 0x0c0aded0u: goto P_0c0aded0;
case 0x0c0aded2u: goto P_0c0aded2;
case 0x0c0aded4u: goto P_0c0aded4;
case 0x0c0aded6u: goto P_0c0aded6;
case 0x0c0aded8u: goto P_0c0aded8;
case 0x0c0adedau: goto P_0c0adeda;
case 0x0c0adedcu: goto P_0c0adedc;
case 0x0c0adedeu: goto P_0c0adede;
case 0x0c0adee0u: goto P_0c0adee0;
case 0x0c0adee2u: goto P_0c0adee2;
case 0x0c0adee4u: goto P_0c0adee4;
case 0x0c0adee6u: goto P_0c0adee6;
case 0x0c0adee8u: goto P_0c0adee8;
case 0x0c0adeeau: goto P_0c0adeea;
case 0x0c0adeecu: goto P_0c0adeec;
case 0x0c0adeeeu: goto P_0c0adeee;
case 0x0c0adef0u: goto P_0c0adef0;
case 0x0c0adef2u: goto P_0c0adef2;
case 0x0c0adef4u: goto P_0c0adef4;
case 0x0c0adef6u: goto P_0c0adef6;
case 0x0c0adef8u: goto P_0c0adef8;
case 0x0c0adefau: goto P_0c0adefa;
case 0x0c0adefcu: goto P_0c0adefc;
case 0x0c0adefeu: goto P_0c0adefe;
case 0x0c0adf00u: goto P_0c0adf00;
case 0x0c0adf02u: goto P_0c0adf02;
case 0x0c0adf04u: goto P_0c0adf04;
case 0x0c0adf06u: goto P_0c0adf06;
case 0x0c0adf08u: goto P_0c0adf08;
case 0x0c0adf0au: goto P_0c0adf0a;
case 0x0c0adf0cu: goto P_0c0adf0c;
case 0x0c0adf0eu: goto P_0c0adf0e;
case 0x0c0adf10u: goto P_0c0adf10;
case 0x0c0adf12u: goto P_0c0adf12;
case 0x0c0adf14u: goto P_0c0adf14;
case 0x0c0adf16u: goto P_0c0adf16;
case 0x0c0adf18u: goto P_0c0adf18;
case 0x0c0adf1au: goto P_0c0adf1a;
case 0x0c0adf1cu: goto P_0c0adf1c;
case 0x0c0adf38u: goto P_0c0adf38;
case 0x0c0adf3au: goto P_0c0adf3a;
case 0x0c0adf3cu: goto P_0c0adf3c;
case 0x0c0adf3eu: goto P_0c0adf3e;
case 0x0c0adf40u: goto P_0c0adf40;
case 0x0c0adf42u: goto P_0c0adf42;
case 0x0c0adf44u: goto P_0c0adf44;
case 0x0c0adf46u: goto P_0c0adf46;
case 0x0c0adf48u: goto P_0c0adf48;
case 0x0c0adf4au: goto P_0c0adf4a;
case 0x0c0adf4cu: goto P_0c0adf4c;
case 0x0c0adf4eu: goto P_0c0adf4e;
case 0x0c0adf50u: goto P_0c0adf50;
case 0x0c0adf52u: goto P_0c0adf52;
case 0x0c0adf54u: goto P_0c0adf54;
case 0x0c0adf56u: goto P_0c0adf56;
case 0x0c0adf58u: goto P_0c0adf58;
case 0x0c0adf5au: goto P_0c0adf5a;
case 0x0c0adf5cu: goto P_0c0adf5c;
case 0x0c0adf5eu: goto P_0c0adf5e;
case 0x0c0adf60u: goto P_0c0adf60;
case 0x0c0adf62u: goto P_0c0adf62;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ade24: /* original 2fe6, guest PC 0x0c0ade24 */
if(!s->budget--) { s->failed_pc=0x0c0ade24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ade26;
P_0c0ade26: /* original 2fd6, guest PC 0x0c0ade26 */
if(!s->budget--) { s->failed_pc=0x0c0ade26u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ade28;
P_0c0ade28: /* original 8464, guest PC 0x0c0ade28 */
if(!s->budget--) { s->failed_pc=0x0c0ade28u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0ade2a;
P_0c0ade2a: /* original d141, guest PC 0x0c0ade2a */
if(!s->budget--) { s->failed_pc=0x0c0ade2au; return 0; }
r[1]=read(ram,0x0c0adf30u,4);
goto P_0c0ade2c;
P_0c0ade2c: /* original 600c, guest PC 0x0c0ade2c */
if(!s->budget--) { s->failed_pc=0x0c0ade2cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade2e;
P_0c0ade2e: /* original d23f, guest PC 0x0c0ade2e */
if(!s->budget--) { s->failed_pc=0x0c0ade2eu; return 0; }
r[2]=read(ram,0x0c0adf2cu,4);
goto P_0c0ade30;
P_0c0ade30: /* original 4028, guest PC 0x0c0ade30 */
if(!s->budget--) { s->failed_pc=0x0c0ade30u; return 0; }
r[0]<<=16;
goto P_0c0ade32;
P_0c0ade32: /* original dd40, guest PC 0x0c0ade32 */
if(!s->budget--) { s->failed_pc=0x0c0ade32u; return 0; }
r[13]=read(ram,0x0c0adf34u,4);
goto P_0c0ade34;
P_0c0ade34: /* original 4018, guest PC 0x0c0ade34 */
if(!s->budget--) { s->failed_pc=0x0c0ade34u; return 0; }
r[0]<<=8;
goto P_0c0ade36;
P_0c0ade36: /* original 2019, guest PC 0x0c0ade36 */
if(!s->budget--) { s->failed_pc=0x0c0ade36u; return 0; }
r[0]&=r[1];
goto P_0c0ade38;
P_0c0ade38: /* original 6303, guest PC 0x0c0ade38 */
if(!s->budget--) { s->failed_pc=0x0c0ade38u; return 0; }
r[3]=r[0];
goto P_0c0ade3a;
P_0c0ade3a: /* original 8463, guest PC 0x0c0ade3a */
if(!s->budget--) { s->failed_pc=0x0c0ade3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0ade3c;
P_0c0ade3c: /* original 4f22, guest PC 0x0c0ade3c */
if(!s->budget--) { s->failed_pc=0x0c0ade3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ade3e;
P_0c0ade3e: /* original 600c, guest PC 0x0c0ade3e */
if(!s->budget--) { s->failed_pc=0x0c0ade3eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade40;
P_0c0ade40: /* original 4028, guest PC 0x0c0ade40 */
if(!s->budget--) { s->failed_pc=0x0c0ade40u; return 0; }
r[0]<<=16;
goto P_0c0ade42;
P_0c0ade42: /* original 2029, guest PC 0x0c0ade42 */
if(!s->budget--) { s->failed_pc=0x0c0ade42u; return 0; }
r[0]&=r[2];
goto P_0c0ade44;
P_0c0ade44: /* original 230b, guest PC 0x0c0ade44 */
if(!s->budget--) { s->failed_pc=0x0c0ade44u; return 0; }
r[3]|=r[0];
goto P_0c0ade46;
P_0c0ade46: /* original 8462, guest PC 0x0c0ade46 */
if(!s->budget--) { s->failed_pc=0x0c0ade46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0ade48;
P_0c0ade48: /* original 7ff0, guest PC 0x0c0ade48 */
if(!s->budget--) { s->failed_pc=0x0c0ade48u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ade4a;
P_0c0ade4a: /* original 600c, guest PC 0x0c0ade4a */
if(!s->budget--) { s->failed_pc=0x0c0ade4au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade4c;
P_0c0ade4c: /* original 67f3, guest PC 0x0c0ade4c */
if(!s->budget--) { s->failed_pc=0x0c0ade4cu; return 0; }
r[7]=r[15];
goto P_0c0ade4e;
P_0c0ade4e: /* original 4018, guest PC 0x0c0ade4e */
if(!s->budget--) { s->failed_pc=0x0c0ade4eu; return 0; }
r[0]<<=8;
goto P_0c0ade50;
P_0c0ade50: /* original 6ef3, guest PC 0x0c0ade50 */
if(!s->budget--) { s->failed_pc=0x0c0ade50u; return 0; }
r[14]=r[15];
goto P_0c0ade52;
P_0c0ade52: /* original 20d9, guest PC 0x0c0ade52 */
if(!s->budget--) { s->failed_pc=0x0c0ade52u; return 0; }
r[0]&=r[13];
goto P_0c0ade54;
P_0c0ade54: /* original 230b, guest PC 0x0c0ade54 */
if(!s->budget--) { s->failed_pc=0x0c0ade54u; return 0; }
r[3]|=r[0];
goto P_0c0ade56;
P_0c0ade56: /* original 8461, guest PC 0x0c0ade56 */
if(!s->budget--) { s->failed_pc=0x0c0ade56u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0ade58;
P_0c0ade58: /* original 7704, guest PC 0x0c0ade58 */
if(!s->budget--) { s->failed_pc=0x0c0ade58u; return 0; }
r[7]+=0x00000004u;
goto P_0c0ade5a;
P_0c0ade5a: /* original 600c, guest PC 0x0c0ade5a */
if(!s->budget--) { s->failed_pc=0x0c0ade5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade5c;
P_0c0ade5c: /* original 230b, guest PC 0x0c0ade5c */
if(!s->budget--) { s->failed_pc=0x0c0ade5cu; return 0; }
r[3]|=r[0];
goto P_0c0ade5e;
P_0c0ade5e: /* original 2732, guest PC 0x0c0ade5e */
if(!s->budget--) { s->failed_pc=0x0c0ade5eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0ade60;
P_0c0ade60: /* original 7e04, guest PC 0x0c0ade60 */
if(!s->budget--) { s->failed_pc=0x0c0ade60u; return 0; }
r[14]+=0x00000004u;
goto P_0c0ade62;
P_0c0ade62: /* original 8469, guest PC 0x0c0ade62 */
if(!s->budget--) { s->failed_pc=0x0c0ade62u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0ade64;
P_0c0ade64: /* original 600c, guest PC 0x0c0ade64 */
if(!s->budget--) { s->failed_pc=0x0c0ade64u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade66;
P_0c0ade66: /* original 4028, guest PC 0x0c0ade66 */
if(!s->budget--) { s->failed_pc=0x0c0ade66u; return 0; }
r[0]<<=16;
goto P_0c0ade68;
P_0c0ade68: /* original 4018, guest PC 0x0c0ade68 */
if(!s->budget--) { s->failed_pc=0x0c0ade68u; return 0; }
r[0]<<=8;
goto P_0c0ade6a;
P_0c0ade6a: /* original 2019, guest PC 0x0c0ade6a */
if(!s->budget--) { s->failed_pc=0x0c0ade6au; return 0; }
r[0]&=r[1];
goto P_0c0ade6c;
P_0c0ade6c: /* original 6303, guest PC 0x0c0ade6c */
if(!s->budget--) { s->failed_pc=0x0c0ade6cu; return 0; }
r[3]=r[0];
goto P_0c0ade6e;
P_0c0ade6e: /* original 8468, guest PC 0x0c0ade6e */
if(!s->budget--) { s->failed_pc=0x0c0ade6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0ade70;
P_0c0ade70: /* original 600c, guest PC 0x0c0ade70 */
if(!s->budget--) { s->failed_pc=0x0c0ade70u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade72;
P_0c0ade72: /* original 4028, guest PC 0x0c0ade72 */
if(!s->budget--) { s->failed_pc=0x0c0ade72u; return 0; }
r[0]<<=16;
goto P_0c0ade74;
P_0c0ade74: /* original 2029, guest PC 0x0c0ade74 */
if(!s->budget--) { s->failed_pc=0x0c0ade74u; return 0; }
r[0]&=r[2];
goto P_0c0ade76;
P_0c0ade76: /* original 230b, guest PC 0x0c0ade76 */
if(!s->budget--) { s->failed_pc=0x0c0ade76u; return 0; }
r[3]|=r[0];
goto P_0c0ade78;
P_0c0ade78: /* original 8467, guest PC 0x0c0ade78 */
if(!s->budget--) { s->failed_pc=0x0c0ade78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0ade7a;
P_0c0ade7a: /* original 600c, guest PC 0x0c0ade7a */
if(!s->budget--) { s->failed_pc=0x0c0ade7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade7c;
P_0c0ade7c: /* original 4018, guest PC 0x0c0ade7c */
if(!s->budget--) { s->failed_pc=0x0c0ade7cu; return 0; }
r[0]<<=8;
goto P_0c0ade7e;
P_0c0ade7e: /* original 20d9, guest PC 0x0c0ade7e */
if(!s->budget--) { s->failed_pc=0x0c0ade7eu; return 0; }
r[0]&=r[13];
goto P_0c0ade80;
P_0c0ade80: /* original 230b, guest PC 0x0c0ade80 */
if(!s->budget--) { s->failed_pc=0x0c0ade80u; return 0; }
r[3]|=r[0];
goto P_0c0ade82;
P_0c0ade82: /* original 8466, guest PC 0x0c0ade82 */
if(!s->budget--) { s->failed_pc=0x0c0ade82u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0ade84;
P_0c0ade84: /* original 600c, guest PC 0x0c0ade84 */
if(!s->budget--) { s->failed_pc=0x0c0ade84u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade86;
P_0c0ade86: /* original 230b, guest PC 0x0c0ade86 */
if(!s->budget--) { s->failed_pc=0x0c0ade86u; return 0; }
r[3]|=r[0];
goto P_0c0ade88;
P_0c0ade88: /* original 1731, guest PC 0x0c0ade88 */
if(!s->budget--) { s->failed_pc=0x0c0ade88u; return 0; }
write(ram,r[7]+4,r[3],4);
goto P_0c0ade8a;
P_0c0ade8a: /* original 846e, guest PC 0x0c0ade8a */
if(!s->budget--) { s->failed_pc=0x0c0ade8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0ade8c;
P_0c0ade8c: /* original 600c, guest PC 0x0c0ade8c */
if(!s->budget--) { s->failed_pc=0x0c0ade8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade8e;
P_0c0ade8e: /* original 4028, guest PC 0x0c0ade8e */
if(!s->budget--) { s->failed_pc=0x0c0ade8eu; return 0; }
r[0]<<=16;
goto P_0c0ade90;
P_0c0ade90: /* original 4018, guest PC 0x0c0ade90 */
if(!s->budget--) { s->failed_pc=0x0c0ade90u; return 0; }
r[0]<<=8;
goto P_0c0ade92;
P_0c0ade92: /* original 2019, guest PC 0x0c0ade92 */
if(!s->budget--) { s->failed_pc=0x0c0ade92u; return 0; }
r[0]&=r[1];
goto P_0c0ade94;
P_0c0ade94: /* original 6303, guest PC 0x0c0ade94 */
if(!s->budget--) { s->failed_pc=0x0c0ade94u; return 0; }
r[3]=r[0];
goto P_0c0ade96;
P_0c0ade96: /* original 846d, guest PC 0x0c0ade96 */
if(!s->budget--) { s->failed_pc=0x0c0ade96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0ade98;
P_0c0ade98: /* original 600c, guest PC 0x0c0ade98 */
if(!s->budget--) { s->failed_pc=0x0c0ade98u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade9a;
P_0c0ade9a: /* original 4028, guest PC 0x0c0ade9a */
if(!s->budget--) { s->failed_pc=0x0c0ade9au; return 0; }
r[0]<<=16;
goto P_0c0ade9c;
P_0c0ade9c: /* original 2029, guest PC 0x0c0ade9c */
if(!s->budget--) { s->failed_pc=0x0c0ade9cu; return 0; }
r[0]&=r[2];
goto P_0c0ade9e;
P_0c0ade9e: /* original 230b, guest PC 0x0c0ade9e */
if(!s->budget--) { s->failed_pc=0x0c0ade9eu; return 0; }
r[3]|=r[0];
goto P_0c0adea0;
P_0c0adea0: /* original 846c, guest PC 0x0c0adea0 */
if(!s->budget--) { s->failed_pc=0x0c0adea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0adea2;
P_0c0adea2: /* original 600c, guest PC 0x0c0adea2 */
if(!s->budget--) { s->failed_pc=0x0c0adea2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adea4;
P_0c0adea4: /* original 4018, guest PC 0x0c0adea4 */
if(!s->budget--) { s->failed_pc=0x0c0adea4u; return 0; }
r[0]<<=8;
goto P_0c0adea6;
P_0c0adea6: /* original 20d9, guest PC 0x0c0adea6 */
if(!s->budget--) { s->failed_pc=0x0c0adea6u; return 0; }
r[0]&=r[13];
goto P_0c0adea8;
P_0c0adea8: /* original 230b, guest PC 0x0c0adea8 */
if(!s->budget--) { s->failed_pc=0x0c0adea8u; return 0; }
r[3]|=r[0];
goto P_0c0adeaa;
P_0c0adeaa: /* original 846b, guest PC 0x0c0adeaa */
if(!s->budget--) { s->failed_pc=0x0c0adeaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0adeac;
P_0c0adeac: /* original 600c, guest PC 0x0c0adeac */
if(!s->budget--) { s->failed_pc=0x0c0adeacu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adeae;
P_0c0adeae: /* original 230b, guest PC 0x0c0adeae */
if(!s->budget--) { s->failed_pc=0x0c0adeaeu; return 0; }
r[3]|=r[0];
goto P_0c0adeb0;
P_0c0adeb0: /* original e004, guest PC 0x0c0adeb0 */
if(!s->budget--) { s->failed_pc=0x0c0adeb0u; return 0; }
r[0]=0x00000004u;
goto P_0c0adeb2;
P_0c0adeb2: /* original 1732, guest PC 0x0c0adeb2 */
if(!s->budget--) { s->failed_pc=0x0c0adeb2u; return 0; }
write(ram,r[7]+8,r[3],4);
goto P_0c0adeb4;
P_0c0adeb4: /* original f6e6, guest PC 0x0c0adeb4 */
if(!s->budget--) { s->failed_pc=0x0c0adeb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0adeb6;
P_0c0adeb6: /* original e008, guest PC 0x0c0adeb6 */
if(!s->budget--) { s->failed_pc=0x0c0adeb6u; return 0; }
r[0]=0x00000008u;
goto P_0c0adeb8;
P_0c0adeb8: /* original f8e6, guest PC 0x0c0adeb8 */
if(!s->budget--) { s->failed_pc=0x0c0adeb8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0adeba;
P_0c0adeba: /* original 8465, guest PC 0x0c0adeba */
if(!s->budget--) { s->failed_pc=0x0c0adebau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adebc;
P_0c0adebc: /* original f7e8, guest PC 0x0c0adebc */
if(!s->budget--) { s->failed_pc=0x0c0adebcu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c0adebe;
P_0c0adebe: /* original 600c, guest PC 0x0c0adebe */
if(!s->budget--) { s->failed_pc=0x0c0adebeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adec0;
P_0c0adec0: /* original f675, guest PC 0x0c0adec0 */
if(!s->budget--) { s->failed_pc=0x0c0adec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c0adec2;
P_0c0adec2: /* original 2f02, guest PC 0x0c0adec2 */
if(!s->budget--) { s->failed_pc=0x0c0adec2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0adec4;
P_0c0adec4: /* original 846a, guest PC 0x0c0adec4 */
if(!s->budget--) { s->failed_pc=0x0c0adec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0adec6;
P_0c0adec6: /* original 6d0c, guest PC 0x0c0adec6 */
if(!s->budget--) { s->failed_pc=0x0c0adec6u; return 0; }
r[13]=r[0]&255u;
goto P_0c0adec8;
P_0c0adec8: /* original 8d01, guest PC 0x0c0adec8 */
if(!s->budget--) { s->failed_pc=0x0c0adec8u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0adece; }
goto P_0c0adecc;
P_0c0adeca: /* original e701, guest PC 0x0c0adeca */
if(!s->budget--) { s->failed_pc=0x0c0adecau; return 0; }
r[7]=0x00000001u;
goto P_0c0adecc;
P_0c0adecc: /* original e702, guest PC 0x0c0adecc */
if(!s->budget--) { s->failed_pc=0x0c0adeccu; return 0; }
r[7]=0x00000002u;
goto P_0c0adece;
P_0c0adece: /* original 902b, guest PC 0x0c0adece */
if(!s->budget--) { s->failed_pc=0x0c0adeceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf28u,2);
goto P_0c0aded0;
P_0c0aded0: /* original 2dd8, guest PC 0x0c0aded0 */
if(!s->budget--) { s->failed_pc=0x0c0aded0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0aded2;
P_0c0aded2: /* original 0474, guest PC 0x0c0aded2 */
if(!s->budget--) { s->failed_pc=0x0c0aded2u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0aded4;
P_0c0aded4: /* original e05c, guest PC 0x0c0aded4 */
if(!s->budget--) { s->failed_pc=0x0c0aded4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0aded6;
P_0c0aded6: /* original f946, guest PC 0x0c0aded6 */
if(!s->budget--) { s->failed_pc=0x0c0aded6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0aded8;
P_0c0aded8: /* original f57c, guest PC 0x0c0aded8 */
if(!s->budget--) { s->failed_pc=0x0c0aded8u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adeda;
P_0c0adeda: /* original f561, guest PC 0x0c0adeda */
if(!s->budget--) { s->failed_pc=0x0c0adedau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adedc;
P_0c0adedc: /* original f49c, guest PC 0x0c0adedc */
if(!s->budget--) { s->failed_pc=0x0c0adedcu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adede;
P_0c0adede: /* original f461, guest PC 0x0c0adede */
if(!s->budget--) { s->failed_pc=0x0c0adedeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0adee0;
P_0c0adee0: /* original 9023, guest PC 0x0c0adee0 */
if(!s->budget--) { s->failed_pc=0x0c0adee0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf2au,2);
goto P_0c0adee2;
P_0c0adee2: /* original 6ef2, guest PC 0x0c0adee2 */
if(!s->budget--) { s->failed_pc=0x0c0adee2u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c0adee4;
P_0c0adee4: /* original 074c, guest PC 0x0c0adee4 */
if(!s->budget--) { s->failed_pc=0x0c0adee4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0adee6;
P_0c0adee6: /* original 8d0b, guest PC 0x0c0adee6 */
if(!s->budget--) { s->failed_pc=0x0c0adee6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c0adf00; }
goto P_0c0adeea;
P_0c0adee8: /* original 677c, guest PC 0x0c0adee8 */
if(!s->budget--) { s->failed_pc=0x0c0adee8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0adeea;
P_0c0adeea: /* original f58c, guest PC 0x0c0adeea */
if(!s->budget--) { s->failed_pc=0x0c0adeeau; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0adeec;
P_0c0adeec: /* original f561, guest PC 0x0c0adeec */
if(!s->budget--) { s->failed_pc=0x0c0adeecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adeee;
P_0c0adeee: /* original f455, guest PC 0x0c0adeee */
if(!s->budget--) { s->failed_pc=0x0c0adeeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adef0;
P_0c0adef0: /* original 8905, guest PC 0x0c0adef0 */
if(!s->budget--) { s->failed_pc=0x0c0adef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adefe; }
goto P_0c0adef2;
P_0c0adef2: /* original f57c, guest PC 0x0c0adef2 */
if(!s->budget--) { s->failed_pc=0x0c0adef2u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adef4;
P_0c0adef4: /* original f581, guest PC 0x0c0adef4 */
if(!s->budget--) { s->failed_pc=0x0c0adef4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0adef6;
P_0c0adef6: /* original f49c, guest PC 0x0c0adef6 */
if(!s->budget--) { s->failed_pc=0x0c0adef6u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adef8;
P_0c0adef8: /* original 6ed3, guest PC 0x0c0adef8 */
if(!s->budget--) { s->failed_pc=0x0c0adef8u; return 0; }
r[14]=r[13];
goto P_0c0adefa;
P_0c0adefa: /* original a001, guest PC 0x0c0adefa */
if(!s->budget--) { s->failed_pc=0x0c0adefau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adf00;
P_0c0adefc: /* original f481, guest PC 0x0c0adefc */
if(!s->budget--) { s->failed_pc=0x0c0adefcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adefe;
P_0c0adefe: /* original 67d3, guest PC 0x0c0adefe */
if(!s->budget--) { s->failed_pc=0x0c0adefeu; return 0; }
r[7]=r[13];
goto P_0c0adf00;
P_0c0adf00: /* original f38d, guest PC 0x0c0adf00 */
if(!s->budget--) { s->failed_pc=0x0c0adf00u; return 0; }
fr[3]=0;
goto P_0c0adf02;
P_0c0adf02: /* original f355, guest PC 0x0c0adf02 */
if(!s->budget--) { s->failed_pc=0x0c0adf02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0adf04;
P_0c0adf04: /* original 8d07, guest PC 0x0c0adf04 */
if(!s->budget--) { s->failed_pc=0x0c0adf04u; return 0; }
cond=r[17]&1u;
fr[6]=0;
if(cond) { goto P_0c0adf16; }
goto P_0c0adf08;
P_0c0adf06: /* original f68d, guest PC 0x0c0adf06 */
if(!s->budget--) { s->failed_pc=0x0c0adf06u; return 0; }
fr[6]=0;
goto P_0c0adf08;
P_0c0adf08: /* original f38d, guest PC 0x0c0adf08 */
if(!s->budget--) { s->failed_pc=0x0c0adf08u; return 0; }
fr[3]=0;
goto P_0c0adf0a;
P_0c0adf0a: /* original f345, guest PC 0x0c0adf0a */
if(!s->budget--) { s->failed_pc=0x0c0adf0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf0c;
P_0c0adf0c: /* original 8917, guest PC 0x0c0adf0c */
if(!s->budget--) { s->failed_pc=0x0c0adf0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf3e; }
goto P_0c0adf0e;
P_0c0adf0e: /* original f455, guest PC 0x0c0adf0e */
if(!s->budget--) { s->failed_pc=0x0c0adf0eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf10;
P_0c0adf10: /* original 8b16, guest PC 0x0c0adf10 */
if(!s->budget--) { s->failed_pc=0x0c0adf10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0adf40; }
goto P_0c0adf12;
P_0c0adf12: /* original a002, guest PC 0x0c0adf12 */
if(!s->budget--) { s->failed_pc=0x0c0adf12u; return 0; }
goto P_0c0adf1a;
P_0c0adf14: /* original 0009, guest PC 0x0c0adf14 */
if(!s->budget--) { s->failed_pc=0x0c0adf14u; return 0; }
goto P_0c0adf16;
P_0c0adf16: /* original f455, guest PC 0x0c0adf16 */
if(!s->budget--) { s->failed_pc=0x0c0adf16u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf18;
P_0c0adf18: /* original 890e, guest PC 0x0c0adf18 */
if(!s->budget--) { s->failed_pc=0x0c0adf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf38; }
goto P_0c0adf1a;
P_0c0adf1a: /* original a011, guest PC 0x0c0adf1a */
if(!s->budget--) { s->failed_pc=0x0c0adf1au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0adf40;
P_0c0adf1c: /* original f45c, guest PC 0x0c0adf1c */
if(!s->budget--) { s->failed_pc=0x0c0adf1cu; return 0; }
vf3_matrix_move(s,4,5);
if(!vf3_matrix_family(0x0c0adf1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0adf1eu; return 0; } return 1;
P_0c0adf38: /* original f38d, guest PC 0x0c0adf38 */
if(!s->budget--) { s->failed_pc=0x0c0adf38u; return 0; }
fr[3]=0;
goto P_0c0adf3a;
P_0c0adf3a: /* original f345, guest PC 0x0c0adf3a */
if(!s->budget--) { s->failed_pc=0x0c0adf3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf3c;
P_0c0adf3c: /* original 8900, guest PC 0x0c0adf3c */
if(!s->budget--) { s->failed_pc=0x0c0adf3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf40; }
goto P_0c0adf3e;
P_0c0adf3e: /* original f46c, guest PC 0x0c0adf3e */
if(!s->budget--) { s->failed_pc=0x0c0adf3eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0adf40;
P_0c0adf40: /* original f453, guest PC 0x0c0adf40 */
if(!s->budget--) { s->failed_pc=0x0c0adf40u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0adf42;
P_0c0adf42: /* original 37e8, guest PC 0x0c0adf42 */
if(!s->budget--) { s->failed_pc=0x0c0adf42u; return 0; }
r[7]-=r[14];
goto P_0c0adf44;
P_0c0adf44: /* original 475a, guest PC 0x0c0adf44 */
if(!s->budget--) { s->failed_pc=0x0c0adf44u; return 0; }
r[53]=r[7];
goto P_0c0adf46;
P_0c0adf46: /* original 9093, guest PC 0x0c0adf46 */
if(!s->budget--) { s->failed_pc=0x0c0adf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae070u,2);
goto P_0c0adf48;
P_0c0adf48: /* original f32d, guest PC 0x0c0adf48 */
if(!s->budget--) { s->failed_pc=0x0c0adf48u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0adf4a;
P_0c0adf4a: /* original f63c, guest PC 0x0c0adf4a */
if(!s->budget--) { s->failed_pc=0x0c0adf4au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0adf4c;
P_0c0adf4c: /* original f462, guest PC 0x0c0adf4c */
if(!s->budget--) { s->failed_pc=0x0c0adf4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0adf4e;
P_0c0adf4e: /* original f43d, guest PC 0x0c0adf4e */
if(!s->budget--) { s->failed_pc=0x0c0adf4eu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0adf50;
P_0c0adf50: /* original 075a, guest PC 0x0c0adf50 */
if(!s->budget--) { s->failed_pc=0x0c0adf50u; return 0; }
r[7]=r[53];
goto P_0c0adf52;
P_0c0adf52: /* original 3e7c, guest PC 0x0c0adf52 */
if(!s->budget--) { s->failed_pc=0x0c0adf52u; return 0; }
r[14]+=r[7];
goto P_0c0adf54;
P_0c0adf54: /* original 04e4, guest PC 0x0c0adf54 */
if(!s->budget--) { s->failed_pc=0x0c0adf54u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0adf56;
P_0c0adf56: /* original bb0f, guest PC 0x0c0adf56 */
if(!s->budget--) { s->failed_pc=0x0c0adf56u; return 0; }
target=code_base|0x0c0ad578u; r[16]=code_base|0x0c0adf5au;
r[6]+=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0adf5au) { target=s->pc; goto dispatch; }
goto P_0c0adf5a;
P_0c0adf58: /* original 760f, guest PC 0x0c0adf58 */
if(!s->budget--) { s->failed_pc=0x0c0adf58u; return 0; }
r[6]+=0x0000000fu;
goto P_0c0adf5a;
P_0c0adf5a: /* original 7f10, guest PC 0x0c0adf5a */
if(!s->budget--) { s->failed_pc=0x0c0adf5au; return 0; }
r[15]+=0x00000010u;
goto P_0c0adf5c;
P_0c0adf5c: /* original 4f26, guest PC 0x0c0adf5c */
if(!s->budget--) { s->failed_pc=0x0c0adf5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adf5e;
P_0c0adf5e: /* original 6df6, guest PC 0x0c0adf5e */
if(!s->budget--) { s->failed_pc=0x0c0adf5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0adf60;
P_0c0adf60: /* original 000b, guest PC 0x0c0adf60 */
if(!s->budget--) { s->failed_pc=0x0c0adf60u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0adf62: /* original 6ef6, guest PC 0x0c0adf62 */
if(!s->budget--) { s->failed_pc=0x0c0adf62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0adf64u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0adf64u; return 0; } return 1;
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
case 0x0c0af728u: return vf3_matrix_family(0x0c0af728u,s,ram);
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
unsupported: s->failed_pc=target; return 0;
}
