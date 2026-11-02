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
int vf3_away_batch9_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06b2ccu: goto P_0c06b2cc;
case 0x0c06b2ceu: goto P_0c06b2ce;
case 0x0c06b2d0u: goto P_0c06b2d0;
case 0x0c06b2d2u: goto P_0c06b2d2;
case 0x0c06b2d4u: goto P_0c06b2d4;
case 0x0c06b2d6u: goto P_0c06b2d6;
case 0x0c06b2d8u: goto P_0c06b2d8;
case 0x0c06b2dau: goto P_0c06b2da;
case 0x0c06b2dcu: goto P_0c06b2dc;
case 0x0c06b2deu: goto P_0c06b2de;
case 0x0c06b2e0u: goto P_0c06b2e0;
case 0x0c06b2e2u: goto P_0c06b2e2;
case 0x0c06b2e4u: goto P_0c06b2e4;
case 0x0c06b2e6u: goto P_0c06b2e6;
case 0x0c06b2e8u: goto P_0c06b2e8;
case 0x0c06b2eau: goto P_0c06b2ea;
case 0x0c06b2ecu: goto P_0c06b2ec;
case 0x0c06b2eeu: goto P_0c06b2ee;
case 0x0c06b2f0u: goto P_0c06b2f0;
case 0x0c06b2f2u: goto P_0c06b2f2;
case 0x0c06b2f4u: goto P_0c06b2f4;
case 0x0c06b2f6u: goto P_0c06b2f6;
case 0x0c06b2f8u: goto P_0c06b2f8;
case 0x0c06b2fau: goto P_0c06b2fa;
case 0x0c06b2fcu: goto P_0c06b2fc;
case 0x0c06b2feu: goto P_0c06b2fe;
case 0x0c06b300u: goto P_0c06b300;
case 0x0c06b302u: goto P_0c06b302;
case 0x0c06b304u: goto P_0c06b304;
case 0x0c06b306u: goto P_0c06b306;
case 0x0c06b308u: goto P_0c06b308;
case 0x0c06b30au: goto P_0c06b30a;
case 0x0c06b30cu: goto P_0c06b30c;
case 0x0c06b30eu: goto P_0c06b30e;
case 0x0c06b310u: goto P_0c06b310;
case 0x0c06b312u: goto P_0c06b312;
case 0x0c06b314u: goto P_0c06b314;
case 0x0c06b316u: goto P_0c06b316;
case 0x0c06b318u: goto P_0c06b318;
case 0x0c06b31au: goto P_0c06b31a;
case 0x0c06b31cu: goto P_0c06b31c;
case 0x0c06b31eu: goto P_0c06b31e;
case 0x0c06b320u: goto P_0c06b320;
case 0x0c06b322u: goto P_0c06b322;
case 0x0c06b324u: goto P_0c06b324;
case 0x0c06b326u: goto P_0c06b326;
case 0x0c06b328u: goto P_0c06b328;
case 0x0c06b32au: goto P_0c06b32a;
case 0x0c06b32cu: goto P_0c06b32c;
case 0x0c06b32eu: goto P_0c06b32e;
case 0x0c06b330u: goto P_0c06b330;
case 0x0c06b332u: goto P_0c06b332;
case 0x0c06b334u: goto P_0c06b334;
case 0x0c06b336u: goto P_0c06b336;
case 0x0c06b338u: goto P_0c06b338;
case 0x0c06b33au: goto P_0c06b33a;
case 0x0c06b33cu: goto P_0c06b33c;
case 0x0c06b33eu: goto P_0c06b33e;
case 0x0c06b340u: goto P_0c06b340;
case 0x0c06b342u: goto P_0c06b342;
case 0x0c06b344u: goto P_0c06b344;
case 0x0c06b346u: goto P_0c06b346;
case 0x0c06b348u: goto P_0c06b348;
case 0x0c06b34au: goto P_0c06b34a;
case 0x0c06b34cu: goto P_0c06b34c;
case 0x0c06b34eu: goto P_0c06b34e;
case 0x0c06b350u: goto P_0c06b350;
case 0x0c06b352u: goto P_0c06b352;
case 0x0c06b354u: goto P_0c06b354;
case 0x0c06b356u: goto P_0c06b356;
case 0x0c06b358u: goto P_0c06b358;
case 0x0c06b35au: goto P_0c06b35a;
case 0x0c06b35cu: goto P_0c06b35c;
case 0x0c06b35eu: goto P_0c06b35e;
case 0x0c06b360u: goto P_0c06b360;
case 0x0c06b362u: goto P_0c06b362;
case 0x0c06b364u: goto P_0c06b364;
case 0x0c06b366u: goto P_0c06b366;
case 0x0c06b368u: goto P_0c06b368;
case 0x0c06b36au: goto P_0c06b36a;
case 0x0c06b36cu: goto P_0c06b36c;
case 0x0c06b36eu: goto P_0c06b36e;
case 0x0c06b370u: goto P_0c06b370;
case 0x0c06b372u: goto P_0c06b372;
case 0x0c06b374u: goto P_0c06b374;
case 0x0c06b376u: goto P_0c06b376;
case 0x0c06b378u: goto P_0c06b378;
case 0x0c06b37au: goto P_0c06b37a;
case 0x0c06b37cu: goto P_0c06b37c;
case 0x0c06b37eu: goto P_0c06b37e;
case 0x0c06b380u: goto P_0c06b380;
case 0x0c06b382u: goto P_0c06b382;
case 0x0c06b384u: goto P_0c06b384;
case 0x0c06b386u: goto P_0c06b386;
case 0x0c06b388u: goto P_0c06b388;
case 0x0c06b38au: goto P_0c06b38a;
case 0x0c06b38cu: goto P_0c06b38c;
case 0x0c06b38eu: goto P_0c06b38e;
case 0x0c06b390u: goto P_0c06b390;
case 0x0c06b392u: goto P_0c06b392;
case 0x0c06b394u: goto P_0c06b394;
case 0x0c06b396u: goto P_0c06b396;
case 0x0c06b398u: goto P_0c06b398;
case 0x0c06b39au: goto P_0c06b39a;
case 0x0c06b39cu: goto P_0c06b39c;
case 0x0c06b39eu: goto P_0c06b39e;
case 0x0c06b3a0u: goto P_0c06b3a0;
case 0x0c06b3a2u: goto P_0c06b3a2;
case 0x0c06b3a4u: goto P_0c06b3a4;
case 0x0c06b3a6u: goto P_0c06b3a6;
case 0x0c06b3a8u: goto P_0c06b3a8;
case 0x0c06b3aau: goto P_0c06b3aa;
case 0x0c06b3acu: goto P_0c06b3ac;
case 0x0c06b3aeu: goto P_0c06b3ae;
case 0x0c06b3b0u: goto P_0c06b3b0;
case 0x0c06b3b2u: goto P_0c06b3b2;
case 0x0c06b3b4u: goto P_0c06b3b4;
case 0x0c06b3b6u: goto P_0c06b3b6;
case 0x0c06b3b8u: goto P_0c06b3b8;
case 0x0c06b3bau: goto P_0c06b3ba;
case 0x0c06b3bcu: goto P_0c06b3bc;
case 0x0c06b3beu: goto P_0c06b3be;
case 0x0c06b3c0u: goto P_0c06b3c0;
case 0x0c06b3c2u: goto P_0c06b3c2;
case 0x0c06b3c4u: goto P_0c06b3c4;
case 0x0c06b3c6u: goto P_0c06b3c6;
case 0x0c06b3c8u: goto P_0c06b3c8;
case 0x0c06b3cau: goto P_0c06b3ca;
case 0x0c06b3ccu: goto P_0c06b3cc;
case 0x0c06b3ceu: goto P_0c06b3ce;
case 0x0c06b3d0u: goto P_0c06b3d0;
case 0x0c06b3d2u: goto P_0c06b3d2;
case 0x0c06b3d4u: goto P_0c06b3d4;
case 0x0c06b3d6u: goto P_0c06b3d6;
case 0x0c06b3d8u: goto P_0c06b3d8;
case 0x0c06b3dau: goto P_0c06b3da;
case 0x0c06b3dcu: goto P_0c06b3dc;
case 0x0c06b3deu: goto P_0c06b3de;
case 0x0c06b3e0u: goto P_0c06b3e0;
case 0x0c06b3e2u: goto P_0c06b3e2;
case 0x0c06b3e4u: goto P_0c06b3e4;
case 0x0c06b3e6u: goto P_0c06b3e6;
case 0x0c06b3e8u: goto P_0c06b3e8;
case 0x0c06b3eau: goto P_0c06b3ea;
case 0x0c06b3ecu: goto P_0c06b3ec;
case 0x0c06b3eeu: goto P_0c06b3ee;
case 0x0c06b3f0u: goto P_0c06b3f0;
case 0x0c06b3f2u: goto P_0c06b3f2;
case 0x0c06b3f4u: goto P_0c06b3f4;
case 0x0c06b3f6u: goto P_0c06b3f6;
case 0x0c06b3f8u: goto P_0c06b3f8;
case 0x0c06b3fau: goto P_0c06b3fa;
case 0x0c06b3fcu: goto P_0c06b3fc;
case 0x0c06b3feu: goto P_0c06b3fe;
case 0x0c06b400u: goto P_0c06b400;
case 0x0c06b402u: goto P_0c06b402;
case 0x0c06b404u: goto P_0c06b404;
case 0x0c06b406u: goto P_0c06b406;
case 0x0c06b408u: goto P_0c06b408;
case 0x0c06b40au: goto P_0c06b40a;
case 0x0c06b45cu: goto P_0c06b45c;
case 0x0c06b45eu: goto P_0c06b45e;
case 0x0c06b460u: goto P_0c06b460;
case 0x0c06b462u: goto P_0c06b462;
case 0x0c06b464u: goto P_0c06b464;
case 0x0c06b466u: goto P_0c06b466;
case 0x0c06b468u: goto P_0c06b468;
case 0x0c06b46au: goto P_0c06b46a;
case 0x0c06b46cu: goto P_0c06b46c;
case 0x0c06b46eu: goto P_0c06b46e;
case 0x0c06b470u: goto P_0c06b470;
case 0x0c06b472u: goto P_0c06b472;
case 0x0c06b474u: goto P_0c06b474;
case 0x0c06b476u: goto P_0c06b476;
case 0x0c06b478u: goto P_0c06b478;
case 0x0c06b47au: goto P_0c06b47a;
case 0x0c06b47cu: goto P_0c06b47c;
case 0x0c06b47eu: goto P_0c06b47e;
case 0x0c06b480u: goto P_0c06b480;
case 0x0c06b482u: goto P_0c06b482;
case 0x0c06b484u: goto P_0c06b484;
case 0x0c06b486u: goto P_0c06b486;
case 0x0c06b488u: goto P_0c06b488;
case 0x0c06b48au: goto P_0c06b48a;
case 0x0c06b48cu: goto P_0c06b48c;
case 0x0c06b48eu: goto P_0c06b48e;
case 0x0c06b490u: goto P_0c06b490;
case 0x0c06b492u: goto P_0c06b492;
case 0x0c06b494u: goto P_0c06b494;
case 0x0c06b496u: goto P_0c06b496;
case 0x0c06b498u: goto P_0c06b498;
case 0x0c06b49au: goto P_0c06b49a;
case 0x0c06b49cu: goto P_0c06b49c;
case 0x0c06b49eu: goto P_0c06b49e;
case 0x0c06b4a0u: goto P_0c06b4a0;
case 0x0c06b4a2u: goto P_0c06b4a2;
case 0x0c06b4a4u: goto P_0c06b4a4;
case 0x0c06b4a6u: goto P_0c06b4a6;
case 0x0c06b4a8u: goto P_0c06b4a8;
case 0x0c06b4aau: goto P_0c06b4aa;
case 0x0c06b4acu: goto P_0c06b4ac;
case 0x0c06b4aeu: goto P_0c06b4ae;
case 0x0c06b4b0u: goto P_0c06b4b0;
case 0x0c06b4b2u: goto P_0c06b4b2;
case 0x0c06b4b4u: goto P_0c06b4b4;
case 0x0c06b4b6u: goto P_0c06b4b6;
case 0x0c06b4b8u: goto P_0c06b4b8;
case 0x0c06b4bau: goto P_0c06b4ba;
case 0x0c06b4bcu: goto P_0c06b4bc;
case 0x0c06b4beu: goto P_0c06b4be;
case 0x0c06b4c0u: goto P_0c06b4c0;
case 0x0c06b4c2u: goto P_0c06b4c2;
case 0x0c06b4c4u: goto P_0c06b4c4;
case 0x0c06b4c6u: goto P_0c06b4c6;
case 0x0c06b4c8u: goto P_0c06b4c8;
case 0x0c06b4cau: goto P_0c06b4ca;
case 0x0c06b4ccu: goto P_0c06b4cc;
case 0x0c06b4ceu: goto P_0c06b4ce;
case 0x0c06b4d0u: goto P_0c06b4d0;
case 0x0c06b4d2u: goto P_0c06b4d2;
case 0x0c06b4d4u: goto P_0c06b4d4;
case 0x0c06b4d6u: goto P_0c06b4d6;
case 0x0c06b4d8u: goto P_0c06b4d8;
case 0x0c06b4dau: goto P_0c06b4da;
case 0x0c06b4dcu: goto P_0c06b4dc;
case 0x0c06b4deu: goto P_0c06b4de;
case 0x0c06b4e0u: goto P_0c06b4e0;
case 0x0c06b4e2u: goto P_0c06b4e2;
case 0x0c06b4e4u: goto P_0c06b4e4;
case 0x0c06b4e6u: goto P_0c06b4e6;
case 0x0c06b4e8u: goto P_0c06b4e8;
case 0x0c06b4eau: goto P_0c06b4ea;
case 0x0c06b4ecu: goto P_0c06b4ec;
case 0x0c06b4eeu: goto P_0c06b4ee;
case 0x0c06b4f0u: goto P_0c06b4f0;
case 0x0c06b4f2u: goto P_0c06b4f2;
case 0x0c06b4f4u: goto P_0c06b4f4;
case 0x0c06b4f6u: goto P_0c06b4f6;
case 0x0c06b4f8u: goto P_0c06b4f8;
case 0x0c06b4fau: goto P_0c06b4fa;
case 0x0c06b4fcu: goto P_0c06b4fc;
case 0x0c06b4feu: goto P_0c06b4fe;
case 0x0c06b500u: goto P_0c06b500;
case 0x0c06b502u: goto P_0c06b502;
case 0x0c06b504u: goto P_0c06b504;
case 0x0c06b506u: goto P_0c06b506;
case 0x0c06b508u: goto P_0c06b508;
case 0x0c06b50au: goto P_0c06b50a;
case 0x0c06b50cu: goto P_0c06b50c;
case 0x0c06b50eu: goto P_0c06b50e;
case 0x0c06b510u: goto P_0c06b510;
case 0x0c06b512u: goto P_0c06b512;
case 0x0c06b514u: goto P_0c06b514;
case 0x0c06b516u: goto P_0c06b516;
case 0x0c06b518u: goto P_0c06b518;
case 0x0c06b51au: goto P_0c06b51a;
case 0x0c06b51cu: goto P_0c06b51c;
case 0x0c06b51eu: goto P_0c06b51e;
case 0x0c06b520u: goto P_0c06b520;
case 0x0c06b522u: goto P_0c06b522;
case 0x0c06b524u: goto P_0c06b524;
case 0x0c06b526u: goto P_0c06b526;
case 0x0c06b528u: goto P_0c06b528;
case 0x0c06b52au: goto P_0c06b52a;
case 0x0c06b52cu: goto P_0c06b52c;
case 0x0c06b52eu: goto P_0c06b52e;
case 0x0c06b530u: goto P_0c06b530;
case 0x0c06b532u: goto P_0c06b532;
case 0x0c06b534u: goto P_0c06b534;
case 0x0c06b536u: goto P_0c06b536;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06b2cc: /* original 2fe6, guest PC 0x0c06b2cc */
if(!s->budget--) { s->failed_pc=0x0c06b2ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2ce;
P_0c06b2ce: /* original 2fd6, guest PC 0x0c06b2ce */
if(!s->budget--) { s->failed_pc=0x0c06b2ceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2d0;
P_0c06b2d0: /* original 2fc6, guest PC 0x0c06b2d0 */
if(!s->budget--) { s->failed_pc=0x0c06b2d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2d2;
P_0c06b2d2: /* original 2fb6, guest PC 0x0c06b2d2 */
if(!s->budget--) { s->failed_pc=0x0c06b2d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2d4;
P_0c06b2d4: /* original 2fa6, guest PC 0x0c06b2d4 */
if(!s->budget--) { s->failed_pc=0x0c06b2d4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2d6;
P_0c06b2d6: /* original 2f96, guest PC 0x0c06b2d6 */
if(!s->budget--) { s->failed_pc=0x0c06b2d6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2d8;
P_0c06b2d8: /* original 2f86, guest PC 0x0c06b2d8 */
if(!s->budget--) { s->failed_pc=0x0c06b2d8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2da;
P_0c06b2da: /* original fffb, guest PC 0x0c06b2da */
if(!s->budget--) { s->failed_pc=0x0c06b2dau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b2dc;
P_0c06b2dc: /* original ffeb, guest PC 0x0c06b2dc */
if(!s->budget--) { s->failed_pc=0x0c06b2dcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b2de;
P_0c06b2de: /* original ffdb, guest PC 0x0c06b2de */
if(!s->budget--) { s->failed_pc=0x0c06b2deu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06b2e0;
P_0c06b2e0: /* original ffcb, guest PC 0x0c06b2e0 */
if(!s->budget--) { s->failed_pc=0x0c06b2e0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06b2e2;
P_0c06b2e2: /* original 4f22, guest PC 0x0c06b2e2 */
if(!s->budget--) { s->failed_pc=0x0c06b2e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b2e4;
P_0c06b2e4: /* original d34f, guest PC 0x0c06b2e4 */
if(!s->budget--) { s->failed_pc=0x0c06b2e4u; return 0; }
r[3]=read(ram,0x0c06b424u,4);
goto P_0c06b2e6;
P_0c06b2e6: /* original 9891, guest PC 0x0c06b2e6 */
if(!s->budget--) { s->failed_pc=0x0c06b2e6u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b40cu,2);
goto P_0c06b2e8;
P_0c06b2e8: /* original 6d30, guest PC 0x0c06b2e8 */
if(!s->budget--) { s->failed_pc=0x0c06b2e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[13]=tmp;
goto P_0c06b2ea;
P_0c06b2ea: /* original 4f12, guest PC 0x0c06b2ea */
if(!s->budget--) { s->failed_pc=0x0c06b2eau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06b2ec;
P_0c06b2ec: /* original d44c, guest PC 0x0c06b2ec */
if(!s->budget--) { s->failed_pc=0x0c06b2ecu; return 0; }
r[4]=read(ram,0x0c06b420u,4);
goto P_0c06b2ee;
P_0c06b2ee: /* original 62d3, guest PC 0x0c06b2ee */
if(!s->budget--) { s->failed_pc=0x0c06b2eeu; return 0; }
r[2]=r[13];
goto P_0c06b2f0;
P_0c06b2f0: /* original 7201, guest PC 0x0c06b2f0 */
if(!s->budget--) { s->failed_pc=0x0c06b2f0u; return 0; }
r[2]+=0x00000001u;
goto P_0c06b2f2;
P_0c06b2f2: /* original de4d, guest PC 0x0c06b2f2 */
if(!s->budget--) { s->failed_pc=0x0c06b2f2u; return 0; }
r[14]=read(ram,0x0c06b428u,4);
goto P_0c06b2f4;
P_0c06b2f4: /* original 384c, guest PC 0x0c06b2f4 */
if(!s->budget--) { s->failed_pc=0x0c06b2f4u; return 0; }
r[8]+=r[4];
goto P_0c06b2f6;
P_0c06b2f6: /* original 7ff0, guest PC 0x0c06b2f6 */
if(!s->budget--) { s->failed_pc=0x0c06b2f6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c06b2f8;
P_0c06b2f8: /* original 2f26, guest PC 0x0c06b2f8 */
if(!s->budget--) { s->failed_pc=0x0c06b2f8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b2fa;
P_0c06b2fa: /* original d14c, guest PC 0x0c06b2fa */
if(!s->budget--) { s->failed_pc=0x0c06b2fau; return 0; }
r[1]=read(ram,0x0c06b42cu,4);
goto P_0c06b2fc;
P_0c06b2fc: /* original 9487, guest PC 0x0c06b2fc */
if(!s->budget--) { s->failed_pc=0x0c06b2fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b40eu,2);
goto P_0c06b2fe;
P_0c06b2fe: /* original 4e0b, guest PC 0x0c06b2fe */
if(!s->budget--) { s->failed_pc=0x0c06b2feu; return 0; }
target=r[14];
r[16]=code_base|0x0c06b302u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b302u) { target=s->pc; goto dispatch; }
goto P_0c06b302;
P_0c06b300: /* original 2f16, guest PC 0x0c06b300 */
if(!s->budget--) { s->failed_pc=0x0c06b300u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b302;
P_0c06b302: /* original 9485, guest PC 0x0c06b302 */
if(!s->budget--) { s->failed_pc=0x0c06b302u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b410u,2);
goto P_0c06b304;
P_0c06b304: /* original d54b, guest PC 0x0c06b304 */
if(!s->budget--) { s->failed_pc=0x0c06b304u; return 0; }
r[5]=read(ram,0x0c06b434u,4);
goto P_0c06b306;
P_0c06b306: /* original dc4a, guest PC 0x0c06b306 */
if(!s->budget--) { s->failed_pc=0x0c06b306u; return 0; }
r[12]=read(ram,0x0c06b430u,4);
goto P_0c06b308;
P_0c06b308: /* original 4c0b, guest PC 0x0c06b308 */
if(!s->budget--) { s->failed_pc=0x0c06b308u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b30cu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b30cu) { target=s->pc; goto dispatch; }
goto P_0c06b30c;
P_0c06b30a: /* original e601, guest PC 0x0c06b30a */
if(!s->budget--) { s->failed_pc=0x0c06b30au; return 0; }
r[6]=0x00000001u;
goto P_0c06b30c;
P_0c06b30c: /* original 9481, guest PC 0x0c06b30c */
if(!s->budget--) { s->failed_pc=0x0c06b30cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b412u,2);
goto P_0c06b30e;
P_0c06b30e: /* original d54a, guest PC 0x0c06b30e */
if(!s->budget--) { s->failed_pc=0x0c06b30eu; return 0; }
r[5]=read(ram,0x0c06b438u,4);
goto P_0c06b310;
P_0c06b310: /* original 4c0b, guest PC 0x0c06b310 */
if(!s->budget--) { s->failed_pc=0x0c06b310u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b314u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b314u) { target=s->pc; goto dispatch; }
goto P_0c06b314;
P_0c06b312: /* original e601, guest PC 0x0c06b312 */
if(!s->budget--) { s->failed_pc=0x0c06b312u; return 0; }
r[6]=0x00000001u;
goto P_0c06b314;
P_0c06b314: /* original 65d3, guest PC 0x0c06b314 */
if(!s->budget--) { s->failed_pc=0x0c06b314u; return 0; }
r[5]=r[13];
goto P_0c06b316;
P_0c06b316: /* original 4508, guest PC 0x0c06b316 */
if(!s->budget--) { s->failed_pc=0x0c06b316u; return 0; }
r[5]<<=2;
goto P_0c06b318;
P_0c06b318: /* original e601, guest PC 0x0c06b318 */
if(!s->budget--) { s->failed_pc=0x0c06b318u; return 0; }
r[6]=0x00000001u;
goto P_0c06b31a;
P_0c06b31a: /* original 1f52, guest PC 0x0c06b31a */
if(!s->budget--) { s->failed_pc=0x0c06b31au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06b31c;
P_0c06b31c: /* original d047, guest PC 0x0c06b31c */
if(!s->budget--) { s->failed_pc=0x0c06b31cu; return 0; }
r[0]=read(ram,0x0c06b43cu,4);
goto P_0c06b31e;
P_0c06b31e: /* original 9479, guest PC 0x0c06b31e */
if(!s->budget--) { s->failed_pc=0x0c06b31eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b414u,2);
goto P_0c06b320;
P_0c06b320: /* original 4c0b, guest PC 0x0c06b320 */
if(!s->budget--) { s->failed_pc=0x0c06b320u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b324u;
r[5]=read(ram,r[5]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b324u) { target=s->pc; goto dispatch; }
goto P_0c06b324;
P_0c06b322: /* original 055e, guest PC 0x0c06b322 */
if(!s->budget--) { s->failed_pc=0x0c06b322u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c06b324;
P_0c06b324: /* original 9477, guest PC 0x0c06b324 */
if(!s->budget--) { s->failed_pc=0x0c06b324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b416u,2);
goto P_0c06b326;
P_0c06b326: /* original d246, guest PC 0x0c06b326 */
if(!s->budget--) { s->failed_pc=0x0c06b326u; return 0; }
r[2]=read(ram,0x0c06b440u,4);
goto P_0c06b328;
P_0c06b328: /* original 53f2, guest PC 0x0c06b328 */
if(!s->budget--) { s->failed_pc=0x0c06b328u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b32a;
P_0c06b32a: /* original 348c, guest PC 0x0c06b32a */
if(!s->budget--) { s->failed_pc=0x0c06b32au; return 0; }
r[4]+=r[8];
goto P_0c06b32c;
P_0c06b32c: /* original 420b, guest PC 0x0c06b32c */
if(!s->budget--) { s->failed_pc=0x0c06b32cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06b330u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b330u) { target=s->pc; goto dispatch; }
goto P_0c06b330;
P_0c06b32e: /* original 343c, guest PC 0x0c06b32e */
if(!s->budget--) { s->failed_pc=0x0c06b32eu; return 0; }
r[4]+=r[3];
goto P_0c06b330;
P_0c06b330: /* original 6503, guest PC 0x0c06b330 */
if(!s->budget--) { s->failed_pc=0x0c06b330u; return 0; }
r[5]=r[0];
goto P_0c06b332;
P_0c06b332: /* original 2f06, guest PC 0x0c06b332 */
if(!s->budget--) { s->failed_pc=0x0c06b332u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b334;
P_0c06b334: /* original d343, guest PC 0x0c06b334 */
if(!s->budget--) { s->failed_pc=0x0c06b334u; return 0; }
r[3]=read(ram,0x0c06b444u,4);
goto P_0c06b336;
P_0c06b336: /* original 946f, guest PC 0x0c06b336 */
if(!s->budget--) { s->failed_pc=0x0c06b336u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b418u,2);
goto P_0c06b338;
P_0c06b338: /* original 4e0b, guest PC 0x0c06b338 */
if(!s->budget--) { s->failed_pc=0x0c06b338u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b33cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b33cu) { target=s->pc; goto dispatch; }
goto P_0c06b33c;
P_0c06b33a: /* original 2f36, guest PC 0x0c06b33a */
if(!s->budget--) { s->failed_pc=0x0c06b33au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b33c;
P_0c06b33c: /* original 946d, guest PC 0x0c06b33c */
if(!s->budget--) { s->failed_pc=0x0c06b33cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b41au,2);
goto P_0c06b33e;
P_0c06b33e: /* original 7f10, guest PC 0x0c06b33e */
if(!s->budget--) { s->failed_pc=0x0c06b33eu; return 0; }
r[15]+=0x00000010u;
goto P_0c06b340;
P_0c06b340: /* original d541, guest PC 0x0c06b340 */
if(!s->budget--) { s->failed_pc=0x0c06b340u; return 0; }
r[5]=read(ram,0x0c06b448u,4);
goto P_0c06b342;
P_0c06b342: /* original 4c0b, guest PC 0x0c06b342 */
if(!s->budget--) { s->failed_pc=0x0c06b342u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b346u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b346u) { target=s->pc; goto dispatch; }
goto P_0c06b346;
P_0c06b344: /* original e601, guest PC 0x0c06b344 */
if(!s->budget--) { s->failed_pc=0x0c06b344u; return 0; }
r[6]=0x00000001u;
goto P_0c06b346;
P_0c06b346: /* original e20d, guest PC 0x0c06b346 */
if(!s->budget--) { s->failed_pc=0x0c06b346u; return 0; }
r[2]=0x0000000du;
goto P_0c06b348;
P_0c06b348: /* original 0d27, guest PC 0x0c06b348 */
if(!s->budget--) { s->failed_pc=0x0c06b348u; return 0; }
r[19]=r[13]*r[2];
goto P_0c06b34a;
P_0c06b34a: /* original c740, guest PC 0x0c06b34a */
if(!s->budget--) { s->failed_pc=0x0c06b34au; return 0; }
r[0]=code_base|0x0006b44cu;
goto P_0c06b34c;
P_0c06b34c: /* original e400, guest PC 0x0c06b34c */
if(!s->budget--) { s->failed_pc=0x0c06b34cu; return 0; }
r[4]=0x00000000u;
goto P_0c06b34e;
P_0c06b34e: /* original ea81, guest PC 0x0c06b34e */
if(!s->budget--) { s->failed_pc=0x0c06b34eu; return 0; }
r[10]=0xffffff81u;
goto P_0c06b350;
P_0c06b350: /* original 1f42, guest PC 0x0c06b350 */
if(!s->budget--) { s->failed_pc=0x0c06b350u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c06b352;
P_0c06b352: /* original 0d1a, guest PC 0x0c06b352 */
if(!s->budget--) { s->failed_pc=0x0c06b352u; return 0; }
r[13]=r[19];
goto P_0c06b354;
P_0c06b354: /* original fc08, guest PC 0x0c06b354 */
if(!s->budget--) { s->failed_pc=0x0c06b354u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c06b356;
P_0c06b356: /* original 6943, guest PC 0x0c06b356 */
if(!s->budget--) { s->failed_pc=0x0c06b356u; return 0; }
r[9]=r[4];
goto P_0c06b358;
P_0c06b358: /* original db38, guest PC 0x0c06b358 */
if(!s->budget--) { s->failed_pc=0x0c06b358u; return 0; }
r[11]=read(ram,0x0c06b43cu,4);
goto P_0c06b35a;
P_0c06b35a: /* original 2fd2, guest PC 0x0c06b35a */
if(!s->budget--) { s->failed_pc=0x0c06b35au; return 0; }
write(ram,r[15],r[13],4);
goto P_0c06b35c;
P_0c06b35c: /* original 6493, guest PC 0x0c06b35c */
if(!s->budget--) { s->failed_pc=0x0c06b35cu; return 0; }
r[4]=r[9];
goto P_0c06b35e;
P_0c06b35e: /* original 740f, guest PC 0x0c06b35e */
if(!s->budget--) { s->failed_pc=0x0c06b35eu; return 0; }
r[4]+=0x0000000fu;
goto P_0c06b360;
P_0c06b360: /* original 6d43, guest PC 0x0c06b360 */
if(!s->budget--) { s->failed_pc=0x0c06b360u; return 0; }
r[13]=r[4];
goto P_0c06b362;
P_0c06b362: /* original e207, guest PC 0x0c06b362 */
if(!s->budget--) { s->failed_pc=0x0c06b362u; return 0; }
r[2]=0x00000007u;
goto P_0c06b364;
P_0c06b364: /* original 4d2c, guest PC 0x0c06b364 */
if(!s->budget--) { s->failed_pc=0x0c06b364u; return 0; }
r[13]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[13]>>((-r[2])&31u)):((int32_t)r[13]<0?0xffffffffu:0)):r[13]<<(r[2]&31u);
goto P_0c06b366;
P_0c06b366: /* original 63f2, guest PC 0x0c06b366 */
if(!s->budget--) { s->failed_pc=0x0c06b366u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06b368;
P_0c06b368: /* original 60d3, guest PC 0x0c06b368 */
if(!s->budget--) { s->failed_pc=0x0c06b368u; return 0; }
r[0]=r[13];
goto P_0c06b36a;
P_0c06b36a: /* original 20a9, guest PC 0x0c06b36a */
if(!s->budget--) { s->failed_pc=0x0c06b36au; return 0; }
r[0]&=r[10];
goto P_0c06b36c;
P_0c06b36c: /* original cb0e, guest PC 0x0c06b36c */
if(!s->budget--) { s->failed_pc=0x0c06b36cu; return 0; }
r[0]|=14u;
goto P_0c06b36e;
P_0c06b36e: /* original 4309, guest PC 0x0c06b36e */
if(!s->budget--) { s->failed_pc=0x0c06b36eu; return 0; }
r[3]>>=2;
goto P_0c06b370;
P_0c06b370: /* original e601, guest PC 0x0c06b370 */
if(!s->budget--) { s->failed_pc=0x0c06b370u; return 0; }
r[6]=0x00000001u;
goto P_0c06b372;
P_0c06b372: /* original 1f33, guest PC 0x0c06b372 */
if(!s->budget--) { s->failed_pc=0x0c06b372u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c06b374;
P_0c06b374: /* original 1f01, guest PC 0x0c06b374 */
if(!s->budget--) { s->failed_pc=0x0c06b374u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06b376;
P_0c06b376: /* original 65b2, guest PC 0x0c06b376 */
if(!s->budget--) { s->failed_pc=0x0c06b376u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c06b378;
P_0c06b378: /* original 4c0b, guest PC 0x0c06b378 */
if(!s->budget--) { s->failed_pc=0x0c06b378u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b37cu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b37cu) { target=s->pc; goto dispatch; }
goto P_0c06b37c;
P_0c06b37a: /* original 6403, guest PC 0x0c06b37a */
if(!s->budget--) { s->failed_pc=0x0c06b37au; return 0; }
r[4]=r[0];
goto P_0c06b37c;
P_0c06b37c: /* original 54f3, guest PC 0x0c06b37c */
if(!s->budget--) { s->failed_pc=0x0c06b37cu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c06b37e;
P_0c06b37e: /* original 4408, guest PC 0x0c06b37e */
if(!s->budget--) { s->failed_pc=0x0c06b37eu; return 0; }
r[4]<<=2;
goto P_0c06b380;
P_0c06b380: /* original 1f41, guest PC 0x0c06b380 */
if(!s->budget--) { s->failed_pc=0x0c06b380u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06b382;
P_0c06b382: /* original 934b, guest PC 0x0c06b382 */
if(!s->budget--) { s->failed_pc=0x0c06b382u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b41cu,2);
goto P_0c06b384;
P_0c06b384: /* original d232, guest PC 0x0c06b384 */
if(!s->budget--) { s->failed_pc=0x0c06b384u; return 0; }
r[2]=read(ram,0x0c06b450u,4);
goto P_0c06b386;
P_0c06b386: /* original 338c, guest PC 0x0c06b386 */
if(!s->budget--) { s->failed_pc=0x0c06b386u; return 0; }
r[3]+=r[8];
goto P_0c06b388;
P_0c06b388: /* original 420b, guest PC 0x0c06b388 */
if(!s->budget--) { s->failed_pc=0x0c06b388u; return 0; }
target=r[2];
r[16]=code_base|0x0c06b38cu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b38cu) { target=s->pc; goto dispatch; }
goto P_0c06b38c;
P_0c06b38a: /* original 343c, guest PC 0x0c06b38a */
if(!s->budget--) { s->failed_pc=0x0c06b38au; return 0; }
r[4]+=r[3];
goto P_0c06b38c;
P_0c06b38c: /* original 9447, guest PC 0x0c06b38c */
if(!s->budget--) { s->failed_pc=0x0c06b38cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b41eu,2);
goto P_0c06b38e;
P_0c06b38e: /* original 53f1, guest PC 0x0c06b38e */
if(!s->budget--) { s->failed_pc=0x0c06b38eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06b390;
P_0c06b390: /* original 348c, guest PC 0x0c06b390 */
if(!s->budget--) { s->failed_pc=0x0c06b390u; return 0; }
r[4]+=r[8];
goto P_0c06b392;
P_0c06b392: /* original 343c, guest PC 0x0c06b392 */
if(!s->budget--) { s->failed_pc=0x0c06b392u; return 0; }
r[4]+=r[3];
goto P_0c06b394;
P_0c06b394: /* original d32e, guest PC 0x0c06b394 */
if(!s->budget--) { s->failed_pc=0x0c06b394u; return 0; }
r[3]=read(ram,0x0c06b450u,4);
goto P_0c06b396;
P_0c06b396: /* original 430b, guest PC 0x0c06b396 */
if(!s->budget--) { s->failed_pc=0x0c06b396u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b39au;
vf3_matrix_move(s,15,0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b39au) { target=s->pc; goto dispatch; }
goto P_0c06b39a;
P_0c06b398: /* original ff0c, guest PC 0x0c06b398 */
if(!s->budget--) { s->failed_pc=0x0c06b398u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c06b39a;
P_0c06b39a: /* original f38d, guest PC 0x0c06b39a */
if(!s->budget--) { s->failed_pc=0x0c06b39au; return 0; }
fr[3]=0;
goto P_0c06b39c;
P_0c06b39c: /* original f3f4, guest PC 0x0c06b39c */
if(!s->budget--) { s->failed_pc=0x0c06b39cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c06b39e;
P_0c06b39e: /* original fdfc, guest PC 0x0c06b39e */
if(!s->budget--) { s->failed_pc=0x0c06b39eu; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06b3a0;
P_0c06b3a0: /* original 60d3, guest PC 0x0c06b3a0 */
if(!s->budget--) { s->failed_pc=0x0c06b3a0u; return 0; }
r[0]=r[13];
goto P_0c06b3a2;
P_0c06b3a2: /* original fe0c, guest PC 0x0c06b3a2 */
if(!s->budget--) { s->failed_pc=0x0c06b3a2u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06b3a4;
P_0c06b3a4: /* original fde1, guest PC 0x0c06b3a4 */
if(!s->budget--) { s->failed_pc=0x0c06b3a4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c06b3a6;
P_0c06b3a6: /* original 20a9, guest PC 0x0c06b3a6 */
if(!s->budget--) { s->failed_pc=0x0c06b3a6u; return 0; }
r[0]&=r[10];
goto P_0c06b3a8;
P_0c06b3a8: /* original ed1e, guest PC 0x0c06b3a8 */
if(!s->budget--) { s->failed_pc=0x0c06b3a8u; return 0; }
r[13]=0x0000001eu;
goto P_0c06b3aa;
P_0c06b3aa: /* original 8f09, guest PC 0x0c06b3aa */
if(!s->budget--) { s->failed_pc=0x0c06b3aau; return 0; }
cond=r[17]&1u;
r[13]|=r[0];
if(!cond) { goto P_0c06b3c0; }
goto P_0c06b3ae;
P_0c06b3ac: /* original 2d0b, guest PC 0x0c06b3ac */
if(!s->budget--) { s->failed_pc=0x0c06b3acu; return 0; }
r[13]|=r[0];
goto P_0c06b3ae;
P_0c06b3ae: /* original ffdb, guest PC 0x0c06b3ae */
if(!s->budget--) { s->failed_pc=0x0c06b3aeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06b3b0;
P_0c06b3b0: /* original ffeb, guest PC 0x0c06b3b0 */
if(!s->budget--) { s->failed_pc=0x0c06b3b0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b3b2;
P_0c06b3b2: /* original fffb, guest PC 0x0c06b3b2 */
if(!s->budget--) { s->failed_pc=0x0c06b3b2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b3b4;
P_0c06b3b4: /* original d227, guest PC 0x0c06b3b4 */
if(!s->budget--) { s->failed_pc=0x0c06b3b4u; return 0; }
r[2]=read(ram,0x0c06b454u,4);
goto P_0c06b3b6;
P_0c06b3b6: /* original 2f26, guest PC 0x0c06b3b6 */
if(!s->budget--) { s->failed_pc=0x0c06b3b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b3b8;
P_0c06b3b8: /* original 4e0b, guest PC 0x0c06b3b8 */
if(!s->budget--) { s->failed_pc=0x0c06b3b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b3bcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b3bcu) { target=s->pc; goto dispatch; }
goto P_0c06b3bc;
P_0c06b3ba: /* original 64d3, guest PC 0x0c06b3ba */
if(!s->budget--) { s->failed_pc=0x0c06b3bau; return 0; }
r[4]=r[13];
goto P_0c06b3bc;
P_0c06b3bc: /* original a00c, guest PC 0x0c06b3bc */
if(!s->budget--) { s->failed_pc=0x0c06b3bcu; return 0; }
r[15]+=0x00000010u;
goto P_0c06b3d8;
P_0c06b3be: /* original 7f10, guest PC 0x0c06b3be */
if(!s->budget--) { s->failed_pc=0x0c06b3beu; return 0; }
r[15]+=0x00000010u;
goto P_0c06b3c0;
P_0c06b3c0: /* original f4ec, guest PC 0x0c06b3c0 */
if(!s->budget--) { s->failed_pc=0x0c06b3c0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06b3c2;
P_0c06b3c2: /* original f4f3, guest PC 0x0c06b3c2 */
if(!s->budget--) { s->failed_pc=0x0c06b3c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'/');
goto P_0c06b3c4;
P_0c06b3c4: /* original ffdb, guest PC 0x0c06b3c4 */
if(!s->budget--) { s->failed_pc=0x0c06b3c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06b3c6;
P_0c06b3c6: /* original ffeb, guest PC 0x0c06b3c6 */
if(!s->budget--) { s->failed_pc=0x0c06b3c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b3c8;
P_0c06b3c8: /* original fffb, guest PC 0x0c06b3c8 */
if(!s->budget--) { s->failed_pc=0x0c06b3c8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b3ca;
P_0c06b3ca: /* original f4c2, guest PC 0x0c06b3ca */
if(!s->budget--) { s->failed_pc=0x0c06b3cau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'*');
goto P_0c06b3cc;
P_0c06b3cc: /* original ff4b, guest PC 0x0c06b3cc */
if(!s->budget--) { s->failed_pc=0x0c06b3ccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c06b3ce;
P_0c06b3ce: /* original d222, guest PC 0x0c06b3ce */
if(!s->budget--) { s->failed_pc=0x0c06b3ceu; return 0; }
r[2]=read(ram,0x0c06b458u,4);
goto P_0c06b3d0;
P_0c06b3d0: /* original 2f26, guest PC 0x0c06b3d0 */
if(!s->budget--) { s->failed_pc=0x0c06b3d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b3d2;
P_0c06b3d2: /* original 4e0b, guest PC 0x0c06b3d2 */
if(!s->budget--) { s->failed_pc=0x0c06b3d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c06b3d6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b3d6u) { target=s->pc; goto dispatch; }
goto P_0c06b3d6;
P_0c06b3d4: /* original 64d3, guest PC 0x0c06b3d4 */
if(!s->budget--) { s->failed_pc=0x0c06b3d4u; return 0; }
r[4]=r[13];
goto P_0c06b3d6;
P_0c06b3d6: /* original 7f14, guest PC 0x0c06b3d6 */
if(!s->budget--) { s->failed_pc=0x0c06b3d6u; return 0; }
r[15]+=0x00000014u;
goto P_0c06b3d8;
P_0c06b3d8: /* original 53f2, guest PC 0x0c06b3d8 */
if(!s->budget--) { s->failed_pc=0x0c06b3d8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06b3da;
P_0c06b3da: /* original e10d, guest PC 0x0c06b3da */
if(!s->budget--) { s->failed_pc=0x0c06b3dau; return 0; }
r[1]=0x0000000du;
goto P_0c06b3dc;
P_0c06b3dc: /* original 7b04, guest PC 0x0c06b3dc */
if(!s->budget--) { s->failed_pc=0x0c06b3dcu; return 0; }
r[11]+=0x00000004u;
goto P_0c06b3de;
P_0c06b3de: /* original 7301, guest PC 0x0c06b3de */
if(!s->budget--) { s->failed_pc=0x0c06b3deu; return 0; }
r[3]+=0x00000001u;
goto P_0c06b3e0;
P_0c06b3e0: /* original 1f32, guest PC 0x0c06b3e0 */
if(!s->budget--) { s->failed_pc=0x0c06b3e0u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c06b3e2;
P_0c06b3e2: /* original 3313, guest PC 0x0c06b3e2 */
if(!s->budget--) { s->failed_pc=0x0c06b3e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c06b3e4;
P_0c06b3e4: /* original 62f2, guest PC 0x0c06b3e4 */
if(!s->budget--) { s->failed_pc=0x0c06b3e4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06b3e6;
P_0c06b3e6: /* original 7201, guest PC 0x0c06b3e6 */
if(!s->budget--) { s->failed_pc=0x0c06b3e6u; return 0; }
r[2]+=0x00000001u;
goto P_0c06b3e8;
P_0c06b3e8: /* original 2f22, guest PC 0x0c06b3e8 */
if(!s->budget--) { s->failed_pc=0x0c06b3e8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06b3ea;
P_0c06b3ea: /* original 8fb7, guest PC 0x0c06b3ea */
if(!s->budget--) { s->failed_pc=0x0c06b3eau; return 0; }
cond=r[17]&1u;
r[9]+=0x00000002u;
if(!cond) { goto P_0c06b35c; }
goto P_0c06b3ee;
P_0c06b3ec: /* original 7902, guest PC 0x0c06b3ec */
if(!s->budget--) { s->failed_pc=0x0c06b3ecu; return 0; }
r[9]+=0x00000002u;
goto P_0c06b3ee;
P_0c06b3ee: /* original 7f10, guest PC 0x0c06b3ee */
if(!s->budget--) { s->failed_pc=0x0c06b3eeu; return 0; }
r[15]+=0x00000010u;
goto P_0c06b3f0;
P_0c06b3f0: /* original 4f16, guest PC 0x0c06b3f0 */
if(!s->budget--) { s->failed_pc=0x0c06b3f0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b3f2;
P_0c06b3f2: /* original 4f26, guest PC 0x0c06b3f2 */
if(!s->budget--) { s->failed_pc=0x0c06b3f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b3f4;
P_0c06b3f4: /* original fcf9, guest PC 0x0c06b3f4 */
if(!s->budget--) { s->failed_pc=0x0c06b3f4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b3f6;
P_0c06b3f6: /* original fdf9, guest PC 0x0c06b3f6 */
if(!s->budget--) { s->failed_pc=0x0c06b3f6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b3f8;
P_0c06b3f8: /* original fef9, guest PC 0x0c06b3f8 */
if(!s->budget--) { s->failed_pc=0x0c06b3f8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b3fa;
P_0c06b3fa: /* original fff9, guest PC 0x0c06b3fa */
if(!s->budget--) { s->failed_pc=0x0c06b3fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b3fc;
P_0c06b3fc: /* original 68f6, guest PC 0x0c06b3fc */
if(!s->budget--) { s->failed_pc=0x0c06b3fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06b3fe;
P_0c06b3fe: /* original 69f6, guest PC 0x0c06b3fe */
if(!s->budget--) { s->failed_pc=0x0c06b3feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06b400;
P_0c06b400: /* original 6af6, guest PC 0x0c06b400 */
if(!s->budget--) { s->failed_pc=0x0c06b400u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b402;
P_0c06b402: /* original 6bf6, guest PC 0x0c06b402 */
if(!s->budget--) { s->failed_pc=0x0c06b402u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b404;
P_0c06b404: /* original 6cf6, guest PC 0x0c06b404 */
if(!s->budget--) { s->failed_pc=0x0c06b404u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b406;
P_0c06b406: /* original 6df6, guest PC 0x0c06b406 */
if(!s->budget--) { s->failed_pc=0x0c06b406u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b408;
P_0c06b408: /* original 000b, guest PC 0x0c06b408 */
if(!s->budget--) { s->failed_pc=0x0c06b408u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b40a: /* original 6ef6, guest PC 0x0c06b40a */
if(!s->budget--) { s->failed_pc=0x0c06b40au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b40cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b40cu; return 0; } return 1;
P_0c06b45c: /* original 2fe6, guest PC 0x0c06b45c */
if(!s->budget--) { s->failed_pc=0x0c06b45cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b45e;
P_0c06b45e: /* original 2fd6, guest PC 0x0c06b45e */
if(!s->budget--) { s->failed_pc=0x0c06b45eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b460;
P_0c06b460: /* original 2fc6, guest PC 0x0c06b460 */
if(!s->budget--) { s->failed_pc=0x0c06b460u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b462;
P_0c06b462: /* original 2fb6, guest PC 0x0c06b462 */
if(!s->budget--) { s->failed_pc=0x0c06b462u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b464;
P_0c06b464: /* original 2fa6, guest PC 0x0c06b464 */
if(!s->budget--) { s->failed_pc=0x0c06b464u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b466;
P_0c06b466: /* original 2f96, guest PC 0x0c06b466 */
if(!s->budget--) { s->failed_pc=0x0c06b466u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b468;
P_0c06b468: /* original 2f86, guest PC 0x0c06b468 */
if(!s->budget--) { s->failed_pc=0x0c06b468u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b46a;
P_0c06b46a: /* original fffb, guest PC 0x0c06b46a */
if(!s->budget--) { s->failed_pc=0x0c06b46au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b46c;
P_0c06b46c: /* original ffeb, guest PC 0x0c06b46c */
if(!s->budget--) { s->failed_pc=0x0c06b46cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b46e;
P_0c06b46e: /* original d436, guest PC 0x0c06b46e */
if(!s->budget--) { s->failed_pc=0x0c06b46eu; return 0; }
r[4]=read(ram,0x0c06b548u,4);
goto P_0c06b470;
P_0c06b470: /* original 9e62, guest PC 0x0c06b470 */
if(!s->budget--) { s->failed_pc=0x0c06b470u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b538u,2);
goto P_0c06b472;
P_0c06b472: /* original 4f22, guest PC 0x0c06b472 */
if(!s->budget--) { s->failed_pc=0x0c06b472u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b474;
P_0c06b474: /* original 3e4c, guest PC 0x0c06b474 */
if(!s->budget--) { s->failed_pc=0x0c06b474u; return 0; }
r[14]+=r[4];
goto P_0c06b476;
P_0c06b476: /* original d536, guest PC 0x0c06b476 */
if(!s->budget--) { s->failed_pc=0x0c06b476u; return 0; }
r[5]=read(ram,0x0c06b550u,4);
goto P_0c06b478;
P_0c06b478: /* original 945f, guest PC 0x0c06b478 */
if(!s->budget--) { s->failed_pc=0x0c06b478u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b53au,2);
goto P_0c06b47a;
P_0c06b47a: /* original db34, guest PC 0x0c06b47a */
if(!s->budget--) { s->failed_pc=0x0c06b47au; return 0; }
r[11]=read(ram,0x0c06b54cu,4);
goto P_0c06b47c;
P_0c06b47c: /* original 7ff4, guest PC 0x0c06b47c */
if(!s->budget--) { s->failed_pc=0x0c06b47cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06b47e;
P_0c06b47e: /* original 4b0b, guest PC 0x0c06b47e */
if(!s->budget--) { s->failed_pc=0x0c06b47eu; return 0; }
target=r[11];
r[16]=code_base|0x0c06b482u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b482u) { target=s->pc; goto dispatch; }
goto P_0c06b482;
P_0c06b480: /* original e601, guest PC 0x0c06b480 */
if(!s->budget--) { s->failed_pc=0x0c06b480u; return 0; }
r[6]=0x00000001u;
goto P_0c06b482;
P_0c06b482: /* original e30f, guest PC 0x0c06b482 */
if(!s->budget--) { s->failed_pc=0x0c06b482u; return 0; }
r[3]=0x0000000fu;
goto P_0c06b484;
P_0c06b484: /* original d833, guest PC 0x0c06b484 */
if(!s->budget--) { s->failed_pc=0x0c06b484u; return 0; }
r[8]=read(ram,0x0c06b554u,4);
goto P_0c06b486;
P_0c06b486: /* original e400, guest PC 0x0c06b486 */
if(!s->budget--) { s->failed_pc=0x0c06b486u; return 0; }
r[4]=0x00000000u;
goto P_0c06b488;
P_0c06b488: /* original 2f42, guest PC 0x0c06b488 */
if(!s->budget--) { s->failed_pc=0x0c06b488u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06b48a;
P_0c06b48a: /* original ed81, guest PC 0x0c06b48a */
if(!s->budget--) { s->failed_pc=0x0c06b48au; return 0; }
r[13]=0xffffff81u;
goto P_0c06b48c;
P_0c06b48c: /* original 1f32, guest PC 0x0c06b48c */
if(!s->budget--) { s->failed_pc=0x0c06b48cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c06b48e;
P_0c06b48e: /* original 6c43, guest PC 0x0c06b48e */
if(!s->budget--) { s->failed_pc=0x0c06b48eu; return 0; }
r[12]=r[4];
goto P_0c06b490;
P_0c06b490: /* original 59f2, guest PC 0x0c06b490 */
if(!s->budget--) { s->failed_pc=0x0c06b490u; return 0; }
r[9]=read(ram,r[15]+8,4);
goto P_0c06b492;
P_0c06b492: /* original e307, guest PC 0x0c06b492 */
if(!s->budget--) { s->failed_pc=0x0c06b492u; return 0; }
r[3]=0x00000007u;
goto P_0c06b494;
P_0c06b494: /* original ea0e, guest PC 0x0c06b494 */
if(!s->budget--) { s->failed_pc=0x0c06b494u; return 0; }
r[10]=0x0000000eu;
goto P_0c06b496;
P_0c06b496: /* original 65f2, guest PC 0x0c06b496 */
if(!s->budget--) { s->failed_pc=0x0c06b496u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06b498;
P_0c06b498: /* original 493c, guest PC 0x0c06b498 */
if(!s->budget--) { s->failed_pc=0x0c06b498u; return 0; }
r[9]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[9]>>((-r[3])&31u)):((int32_t)r[9]<0?0xffffffffu:0)):r[9]<<(r[3]&31u);
goto P_0c06b49a;
P_0c06b49a: /* original 6093, guest PC 0x0c06b49a */
if(!s->budget--) { s->failed_pc=0x0c06b49au; return 0; }
r[0]=r[9];
goto P_0c06b49c;
P_0c06b49c: /* original 20d9, guest PC 0x0c06b49c */
if(!s->budget--) { s->failed_pc=0x0c06b49cu; return 0; }
r[0]&=r[13];
goto P_0c06b49e;
P_0c06b49e: /* original 2a0b, guest PC 0x0c06b49e */
if(!s->budget--) { s->failed_pc=0x0c06b49eu; return 0; }
r[10]|=r[0];
goto P_0c06b4a0;
P_0c06b4a0: /* original d02d, guest PC 0x0c06b4a0 */
if(!s->budget--) { s->failed_pc=0x0c06b4a0u; return 0; }
r[0]=read(ram,0x0c06b558u,4);
goto P_0c06b4a2;
P_0c06b4a2: /* original 4508, guest PC 0x0c06b4a2 */
if(!s->budget--) { s->failed_pc=0x0c06b4a2u; return 0; }
r[5]<<=2;
goto P_0c06b4a4;
P_0c06b4a4: /* original 055e, guest PC 0x0c06b4a4 */
if(!s->budget--) { s->failed_pc=0x0c06b4a4u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c06b4a6;
P_0c06b4a6: /* original e601, guest PC 0x0c06b4a6 */
if(!s->budget--) { s->failed_pc=0x0c06b4a6u; return 0; }
r[6]=0x00000001u;
goto P_0c06b4a8;
P_0c06b4a8: /* original 4b0b, guest PC 0x0c06b4a8 */
if(!s->budget--) { s->failed_pc=0x0c06b4a8u; return 0; }
target=r[11];
r[16]=code_base|0x0c06b4acu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4acu) { target=s->pc; goto dispatch; }
goto P_0c06b4ac;
P_0c06b4aa: /* original 64a3, guest PC 0x0c06b4aa */
if(!s->budget--) { s->failed_pc=0x0c06b4aau; return 0; }
r[4]=r[10];
goto P_0c06b4ac;
P_0c06b4ac: /* original 9446, guest PC 0x0c06b4ac */
if(!s->budget--) { s->failed_pc=0x0c06b4acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b53cu,2);
goto P_0c06b4ae;
P_0c06b4ae: /* original 6ac3, guest PC 0x0c06b4ae */
if(!s->budget--) { s->failed_pc=0x0c06b4aeu; return 0; }
r[10]=r[12];
goto P_0c06b4b0;
P_0c06b4b0: /* original d32a, guest PC 0x0c06b4b0 */
if(!s->budget--) { s->failed_pc=0x0c06b4b0u; return 0; }
r[3]=read(ram,0x0c06b55cu,4);
goto P_0c06b4b2;
P_0c06b4b2: /* original 4a08, guest PC 0x0c06b4b2 */
if(!s->budget--) { s->failed_pc=0x0c06b4b2u; return 0; }
r[10]<<=2;
goto P_0c06b4b4;
P_0c06b4b4: /* original 34ec, guest PC 0x0c06b4b4 */
if(!s->budget--) { s->failed_pc=0x0c06b4b4u; return 0; }
r[4]+=r[14];
goto P_0c06b4b6;
P_0c06b4b6: /* original 430b, guest PC 0x0c06b4b6 */
if(!s->budget--) { s->failed_pc=0x0c06b4b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b4bau;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4bau) { target=s->pc; goto dispatch; }
goto P_0c06b4ba;
P_0c06b4b8: /* original 34ac, guest PC 0x0c06b4b8 */
if(!s->budget--) { s->failed_pc=0x0c06b4b8u; return 0; }
r[4]+=r[10];
goto P_0c06b4ba;
P_0c06b4ba: /* original 9440, guest PC 0x0c06b4ba */
if(!s->budget--) { s->failed_pc=0x0c06b4bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b53eu,2);
goto P_0c06b4bc;
P_0c06b4bc: /* original d327, guest PC 0x0c06b4bc */
if(!s->budget--) { s->failed_pc=0x0c06b4bcu; return 0; }
r[3]=read(ram,0x0c06b55cu,4);
goto P_0c06b4be;
P_0c06b4be: /* original 34ec, guest PC 0x0c06b4be */
if(!s->budget--) { s->failed_pc=0x0c06b4beu; return 0; }
r[4]+=r[14];
goto P_0c06b4c0;
P_0c06b4c0: /* original ff0c, guest PC 0x0c06b4c0 */
if(!s->budget--) { s->failed_pc=0x0c06b4c0u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c06b4c2;
P_0c06b4c2: /* original 430b, guest PC 0x0c06b4c2 */
if(!s->budget--) { s->failed_pc=0x0c06b4c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06b4c6u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4c6u) { target=s->pc; goto dispatch; }
goto P_0c06b4c6;
P_0c06b4c4: /* original 34ac, guest PC 0x0c06b4c4 */
if(!s->budget--) { s->failed_pc=0x0c06b4c4u; return 0; }
r[4]+=r[10];
goto P_0c06b4c6;
P_0c06b4c6: /* original 943b, guest PC 0x0c06b4c6 */
if(!s->budget--) { s->failed_pc=0x0c06b4c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b540u,2);
goto P_0c06b4c8;
P_0c06b4c8: /* original fe0c, guest PC 0x0c06b4c8 */
if(!s->budget--) { s->failed_pc=0x0c06b4c8u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06b4ca;
P_0c06b4ca: /* original 34ec, guest PC 0x0c06b4ca */
if(!s->budget--) { s->failed_pc=0x0c06b4cau; return 0; }
r[4]+=r[14];
goto P_0c06b4cc;
P_0c06b4cc: /* original 480b, guest PC 0x0c06b4cc */
if(!s->budget--) { s->failed_pc=0x0c06b4ccu; return 0; }
target=r[8];
r[16]=code_base|0x0c06b4d0u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4d0u) { target=s->pc; goto dispatch; }
goto P_0c06b4d0;
P_0c06b4ce: /* original 34ac, guest PC 0x0c06b4ce */
if(!s->budget--) { s->failed_pc=0x0c06b4ceu; return 0; }
r[4]+=r[10];
goto P_0c06b4d0;
P_0c06b4d0: /* original 1f01, guest PC 0x0c06b4d0 */
if(!s->budget--) { s->failed_pc=0x0c06b4d0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06b4d2;
P_0c06b4d2: /* original 9436, guest PC 0x0c06b4d2 */
if(!s->budget--) { s->failed_pc=0x0c06b4d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b542u,2);
goto P_0c06b4d4;
P_0c06b4d4: /* original 34ec, guest PC 0x0c06b4d4 */
if(!s->budget--) { s->failed_pc=0x0c06b4d4u; return 0; }
r[4]+=r[14];
goto P_0c06b4d6;
P_0c06b4d6: /* original 480b, guest PC 0x0c06b4d6 */
if(!s->budget--) { s->failed_pc=0x0c06b4d6u; return 0; }
target=r[8];
r[16]=code_base|0x0c06b4dau;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4dau) { target=s->pc; goto dispatch; }
goto P_0c06b4da;
P_0c06b4d8: /* original 34ac, guest PC 0x0c06b4d8 */
if(!s->budget--) { s->failed_pc=0x0c06b4d8u; return 0; }
r[4]+=r[10];
goto P_0c06b4da;
P_0c06b4da: /* original 53f1, guest PC 0x0c06b4da */
if(!s->budget--) { s->failed_pc=0x0c06b4dau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06b4dc;
P_0c06b4dc: /* original 6503, guest PC 0x0c06b4dc */
if(!s->budget--) { s->failed_pc=0x0c06b4dcu; return 0; }
r[5]=r[0];
goto P_0c06b4de;
P_0c06b4de: /* original 6093, guest PC 0x0c06b4de */
if(!s->budget--) { s->failed_pc=0x0c06b4deu; return 0; }
r[0]=r[9];
goto P_0c06b4e0;
P_0c06b4e0: /* original ea1e, guest PC 0x0c06b4e0 */
if(!s->budget--) { s->failed_pc=0x0c06b4e0u; return 0; }
r[10]=0x0000001eu;
goto P_0c06b4e2;
P_0c06b4e2: /* original 2f36, guest PC 0x0c06b4e2 */
if(!s->budget--) { s->failed_pc=0x0c06b4e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b4e4;
P_0c06b4e4: /* original 20d9, guest PC 0x0c06b4e4 */
if(!s->budget--) { s->failed_pc=0x0c06b4e4u; return 0; }
r[0]&=r[13];
goto P_0c06b4e6;
P_0c06b4e6: /* original 2f56, guest PC 0x0c06b4e6 */
if(!s->budget--) { s->failed_pc=0x0c06b4e6u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b4e8;
P_0c06b4e8: /* original 2a0b, guest PC 0x0c06b4e8 */
if(!s->budget--) { s->failed_pc=0x0c06b4e8u; return 0; }
r[10]|=r[0];
goto P_0c06b4ea;
P_0c06b4ea: /* original ffeb, guest PC 0x0c06b4ea */
if(!s->budget--) { s->failed_pc=0x0c06b4eau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06b4ec;
P_0c06b4ec: /* original fffb, guest PC 0x0c06b4ec */
if(!s->budget--) { s->failed_pc=0x0c06b4ecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06b4ee;
P_0c06b4ee: /* original d31c, guest PC 0x0c06b4ee */
if(!s->budget--) { s->failed_pc=0x0c06b4eeu; return 0; }
r[3]=read(ram,0x0c06b560u,4);
goto P_0c06b4f0;
P_0c06b4f0: /* original 2f36, guest PC 0x0c06b4f0 */
if(!s->budget--) { s->failed_pc=0x0c06b4f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b4f2;
P_0c06b4f2: /* original d21c, guest PC 0x0c06b4f2 */
if(!s->budget--) { s->failed_pc=0x0c06b4f2u; return 0; }
r[2]=read(ram,0x0c06b564u,4);
goto P_0c06b4f4;
P_0c06b4f4: /* original 420b, guest PC 0x0c06b4f4 */
if(!s->budget--) { s->failed_pc=0x0c06b4f4u; return 0; }
target=r[2];
r[16]=code_base|0x0c06b4f8u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b4f8u) { target=s->pc; goto dispatch; }
goto P_0c06b4f8;
P_0c06b4f6: /* original 64a3, guest PC 0x0c06b4f6 */
if(!s->budget--) { s->failed_pc=0x0c06b4f6u; return 0; }
r[4]=r[10];
goto P_0c06b4f8;
P_0c06b4f8: /* original 7f14, guest PC 0x0c06b4f8 */
if(!s->budget--) { s->failed_pc=0x0c06b4f8u; return 0; }
r[15]+=0x00000014u;
goto P_0c06b4fa;
P_0c06b4fa: /* original 9323, guest PC 0x0c06b4fa */
if(!s->budget--) { s->failed_pc=0x0c06b4fau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b544u,2);
goto P_0c06b4fc;
P_0c06b4fc: /* original 52f1, guest PC 0x0c06b4fc */
if(!s->budget--) { s->failed_pc=0x0c06b4fcu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06b4fe;
P_0c06b4fe: /* original 6a03, guest PC 0x0c06b4fe */
if(!s->budget--) { s->failed_pc=0x0c06b4feu; return 0; }
r[10]=r[0];
goto P_0c06b500;
P_0c06b500: /* original 3233, guest PC 0x0c06b500 */
if(!s->budget--) { s->failed_pc=0x0c06b500u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c06b502;
P_0c06b502: /* original 8b03, guest PC 0x0c06b502 */
if(!s->budget--) { s->failed_pc=0x0c06b502u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06b50c; }
goto P_0c06b504;
P_0c06b504: /* original d518, guest PC 0x0c06b504 */
if(!s->budget--) { s->failed_pc=0x0c06b504u; return 0; }
r[5]=read(ram,0x0c06b568u,4);
goto P_0c06b506;
P_0c06b506: /* original e601, guest PC 0x0c06b506 */
if(!s->budget--) { s->failed_pc=0x0c06b506u; return 0; }
r[6]=0x00000001u;
goto P_0c06b508;
P_0c06b508: /* original 4b0b, guest PC 0x0c06b508 */
if(!s->budget--) { s->failed_pc=0x0c06b508u; return 0; }
target=r[11];
r[16]=code_base|0x0c06b50cu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b50cu) { target=s->pc; goto dispatch; }
goto P_0c06b50c;
P_0c06b50a: /* original 64a3, guest PC 0x0c06b50a */
if(!s->budget--) { s->failed_pc=0x0c06b50au; return 0; }
r[4]=r[10];
goto P_0c06b50c;
P_0c06b50c: /* original 63f2, guest PC 0x0c06b50c */
if(!s->budget--) { s->failed_pc=0x0c06b50cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06b50e;
P_0c06b50e: /* original e10d, guest PC 0x0c06b50e */
if(!s->budget--) { s->failed_pc=0x0c06b50eu; return 0; }
r[1]=0x0000000du;
goto P_0c06b510;
P_0c06b510: /* original 7c01, guest PC 0x0c06b510 */
if(!s->budget--) { s->failed_pc=0x0c06b510u; return 0; }
r[12]+=0x00000001u;
goto P_0c06b512;
P_0c06b512: /* original 7301, guest PC 0x0c06b512 */
if(!s->budget--) { s->failed_pc=0x0c06b512u; return 0; }
r[3]+=0x00000001u;
goto P_0c06b514;
P_0c06b514: /* original 3c13, guest PC 0x0c06b514 */
if(!s->budget--) { s->failed_pc=0x0c06b514u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[1])!=0);
goto P_0c06b516;
P_0c06b516: /* original 2f32, guest PC 0x0c06b516 */
if(!s->budget--) { s->failed_pc=0x0c06b516u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06b518;
P_0c06b518: /* original 52f2, guest PC 0x0c06b518 */
if(!s->budget--) { s->failed_pc=0x0c06b518u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06b51a;
P_0c06b51a: /* original 7202, guest PC 0x0c06b51a */
if(!s->budget--) { s->failed_pc=0x0c06b51au; return 0; }
r[2]+=0x00000002u;
goto P_0c06b51c;
P_0c06b51c: /* original 8fb8, guest PC 0x0c06b51c */
if(!s->budget--) { s->failed_pc=0x0c06b51cu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c06b490; }
goto P_0c06b520;
P_0c06b51e: /* original 1f22, guest PC 0x0c06b51e */
if(!s->budget--) { s->failed_pc=0x0c06b51eu; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c06b520;
P_0c06b520: /* original 7f0c, guest PC 0x0c06b520 */
if(!s->budget--) { s->failed_pc=0x0c06b520u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06b522;
P_0c06b522: /* original 4f26, guest PC 0x0c06b522 */
if(!s->budget--) { s->failed_pc=0x0c06b522u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b524;
P_0c06b524: /* original fef9, guest PC 0x0c06b524 */
if(!s->budget--) { s->failed_pc=0x0c06b524u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b526;
P_0c06b526: /* original fff9, guest PC 0x0c06b526 */
if(!s->budget--) { s->failed_pc=0x0c06b526u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06b528;
P_0c06b528: /* original 68f6, guest PC 0x0c06b528 */
if(!s->budget--) { s->failed_pc=0x0c06b528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06b52a;
P_0c06b52a: /* original 69f6, guest PC 0x0c06b52a */
if(!s->budget--) { s->failed_pc=0x0c06b52au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06b52c;
P_0c06b52c: /* original 6af6, guest PC 0x0c06b52c */
if(!s->budget--) { s->failed_pc=0x0c06b52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b52e;
P_0c06b52e: /* original 6bf6, guest PC 0x0c06b52e */
if(!s->budget--) { s->failed_pc=0x0c06b52eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b530;
P_0c06b530: /* original 6cf6, guest PC 0x0c06b530 */
if(!s->budget--) { s->failed_pc=0x0c06b530u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b532;
P_0c06b532: /* original 6df6, guest PC 0x0c06b532 */
if(!s->budget--) { s->failed_pc=0x0c06b532u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b534;
P_0c06b534: /* original 000b, guest PC 0x0c06b534 */
if(!s->budget--) { s->failed_pc=0x0c06b534u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b536: /* original 6ef6, guest PC 0x0c06b536 */
if(!s->budget--) { s->failed_pc=0x0c06b536u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b538u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b538u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
