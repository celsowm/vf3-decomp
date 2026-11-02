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
int vf3_away_batch57_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08a2ccu: goto P_0c08a2cc;
case 0x0c08a2ceu: goto P_0c08a2ce;
case 0x0c08a2d0u: goto P_0c08a2d0;
case 0x0c08a2d2u: goto P_0c08a2d2;
case 0x0c08a2d4u: goto P_0c08a2d4;
case 0x0c08a2d6u: goto P_0c08a2d6;
case 0x0c08a2d8u: goto P_0c08a2d8;
case 0x0c08a2dau: goto P_0c08a2da;
case 0x0c08a2dcu: goto P_0c08a2dc;
case 0x0c08a2deu: goto P_0c08a2de;
case 0x0c08a2e0u: goto P_0c08a2e0;
case 0x0c08a2e2u: goto P_0c08a2e2;
case 0x0c08a2e4u: goto P_0c08a2e4;
case 0x0c08a2e6u: goto P_0c08a2e6;
case 0x0c08a2e8u: goto P_0c08a2e8;
case 0x0c08a2eau: goto P_0c08a2ea;
case 0x0c08a2ecu: goto P_0c08a2ec;
case 0x0c08a2eeu: goto P_0c08a2ee;
case 0x0c08a2f0u: goto P_0c08a2f0;
case 0x0c08a2f2u: goto P_0c08a2f2;
case 0x0c08a2f4u: goto P_0c08a2f4;
case 0x0c08a2f6u: goto P_0c08a2f6;
case 0x0c08a2f8u: goto P_0c08a2f8;
case 0x0c08a2fau: goto P_0c08a2fa;
case 0x0c08a2fcu: goto P_0c08a2fc;
case 0x0c08a2feu: goto P_0c08a2fe;
case 0x0c08a300u: goto P_0c08a300;
case 0x0c08a302u: goto P_0c08a302;
case 0x0c08a304u: goto P_0c08a304;
case 0x0c08a306u: goto P_0c08a306;
case 0x0c08a308u: goto P_0c08a308;
case 0x0c08a30au: goto P_0c08a30a;
case 0x0c08a30cu: goto P_0c08a30c;
case 0x0c08a30eu: goto P_0c08a30e;
case 0x0c08a310u: goto P_0c08a310;
case 0x0c08a312u: goto P_0c08a312;
case 0x0c08a314u: goto P_0c08a314;
case 0x0c08a316u: goto P_0c08a316;
case 0x0c08a318u: goto P_0c08a318;
case 0x0c08a31au: goto P_0c08a31a;
case 0x0c08a31cu: goto P_0c08a31c;
case 0x0c08a31eu: goto P_0c08a31e;
case 0x0c08a320u: goto P_0c08a320;
case 0x0c08a322u: goto P_0c08a322;
case 0x0c08a324u: goto P_0c08a324;
case 0x0c08a326u: goto P_0c08a326;
case 0x0c08a328u: goto P_0c08a328;
case 0x0c08a32au: goto P_0c08a32a;
case 0x0c08a32cu: goto P_0c08a32c;
case 0x0c08a32eu: goto P_0c08a32e;
case 0x0c08a330u: goto P_0c08a330;
case 0x0c08a332u: goto P_0c08a332;
case 0x0c08a334u: goto P_0c08a334;
case 0x0c08a336u: goto P_0c08a336;
case 0x0c08a338u: goto P_0c08a338;
case 0x0c08a33au: goto P_0c08a33a;
case 0x0c08a33cu: goto P_0c08a33c;
case 0x0c08a33eu: goto P_0c08a33e;
case 0x0c08a340u: goto P_0c08a340;
case 0x0c08a342u: goto P_0c08a342;
case 0x0c08a344u: goto P_0c08a344;
case 0x0c08a346u: goto P_0c08a346;
case 0x0c08a348u: goto P_0c08a348;
case 0x0c08a34au: goto P_0c08a34a;
case 0x0c08a34cu: goto P_0c08a34c;
case 0x0c08a34eu: goto P_0c08a34e;
case 0x0c08a350u: goto P_0c08a350;
case 0x0c08a352u: goto P_0c08a352;
case 0x0c08a354u: goto P_0c08a354;
case 0x0c08a356u: goto P_0c08a356;
case 0x0c08a358u: goto P_0c08a358;
case 0x0c08a35au: goto P_0c08a35a;
case 0x0c08a35cu: goto P_0c08a35c;
case 0x0c08a35eu: goto P_0c08a35e;
case 0x0c08a360u: goto P_0c08a360;
case 0x0c08a362u: goto P_0c08a362;
case 0x0c08a364u: goto P_0c08a364;
case 0x0c08a366u: goto P_0c08a366;
case 0x0c08a368u: goto P_0c08a368;
case 0x0c08a36au: goto P_0c08a36a;
case 0x0c08a36cu: goto P_0c08a36c;
case 0x0c08a36eu: goto P_0c08a36e;
case 0x0c08a370u: goto P_0c08a370;
case 0x0c08a372u: goto P_0c08a372;
case 0x0c08a374u: goto P_0c08a374;
case 0x0c08a376u: goto P_0c08a376;
case 0x0c08a378u: goto P_0c08a378;
case 0x0c08a37au: goto P_0c08a37a;
case 0x0c08a37cu: goto P_0c08a37c;
case 0x0c08a3bcu: goto P_0c08a3bc;
case 0x0c08a3beu: goto P_0c08a3be;
case 0x0c08a3c0u: goto P_0c08a3c0;
case 0x0c08a3c2u: goto P_0c08a3c2;
case 0x0c08a3c4u: goto P_0c08a3c4;
case 0x0c08a3c6u: goto P_0c08a3c6;
case 0x0c08a3c8u: goto P_0c08a3c8;
case 0x0c08a3cau: goto P_0c08a3ca;
case 0x0c08a3ccu: goto P_0c08a3cc;
case 0x0c08a3ceu: goto P_0c08a3ce;
case 0x0c08a3d0u: goto P_0c08a3d0;
case 0x0c08a3d2u: goto P_0c08a3d2;
case 0x0c08a3d4u: goto P_0c08a3d4;
case 0x0c08a3d6u: goto P_0c08a3d6;
case 0x0c08a3d8u: goto P_0c08a3d8;
case 0x0c08a3dau: goto P_0c08a3da;
case 0x0c08a3dcu: goto P_0c08a3dc;
case 0x0c08a3deu: goto P_0c08a3de;
case 0x0c08a3e0u: goto P_0c08a3e0;
case 0x0c08a3e2u: goto P_0c08a3e2;
case 0x0c08a3e4u: goto P_0c08a3e4;
case 0x0c08a3e6u: goto P_0c08a3e6;
case 0x0c08a3e8u: goto P_0c08a3e8;
case 0x0c08a3eau: goto P_0c08a3ea;
case 0x0c08a3ecu: goto P_0c08a3ec;
case 0x0c08a3eeu: goto P_0c08a3ee;
case 0x0c08a3f0u: goto P_0c08a3f0;
case 0x0c08a3f2u: goto P_0c08a3f2;
case 0x0c08a3f4u: goto P_0c08a3f4;
case 0x0c08a3f6u: goto P_0c08a3f6;
case 0x0c08a3f8u: goto P_0c08a3f8;
case 0x0c08a3fau: goto P_0c08a3fa;
case 0x0c08a3fcu: goto P_0c08a3fc;
case 0x0c08a3feu: goto P_0c08a3fe;
case 0x0c08a400u: goto P_0c08a400;
case 0x0c08a402u: goto P_0c08a402;
case 0x0c08a404u: goto P_0c08a404;
case 0x0c08a406u: goto P_0c08a406;
case 0x0c08a408u: goto P_0c08a408;
case 0x0c08a40au: goto P_0c08a40a;
case 0x0c08a40cu: goto P_0c08a40c;
case 0x0c08a40eu: goto P_0c08a40e;
case 0x0c08a410u: goto P_0c08a410;
case 0x0c08a412u: goto P_0c08a412;
case 0x0c08a414u: goto P_0c08a414;
case 0x0c08a416u: goto P_0c08a416;
case 0x0c08a418u: goto P_0c08a418;
case 0x0c08a41au: goto P_0c08a41a;
case 0x0c08a41cu: goto P_0c08a41c;
case 0x0c08a41eu: goto P_0c08a41e;
case 0x0c08a420u: goto P_0c08a420;
case 0x0c08a422u: goto P_0c08a422;
case 0x0c08a424u: goto P_0c08a424;
case 0x0c08a426u: goto P_0c08a426;
case 0x0c08a428u: goto P_0c08a428;
case 0x0c08a42au: goto P_0c08a42a;
case 0x0c08a42cu: goto P_0c08a42c;
case 0x0c08a42eu: goto P_0c08a42e;
case 0x0c08a430u: goto P_0c08a430;
case 0x0c08a432u: goto P_0c08a432;
case 0x0c08a434u: goto P_0c08a434;
case 0x0c08a436u: goto P_0c08a436;
case 0x0c08a438u: goto P_0c08a438;
case 0x0c08a43au: goto P_0c08a43a;
case 0x0c08a43cu: goto P_0c08a43c;
case 0x0c08a43eu: goto P_0c08a43e;
case 0x0c08a440u: goto P_0c08a440;
case 0x0c08a442u: goto P_0c08a442;
case 0x0c08a444u: goto P_0c08a444;
case 0x0c08a446u: goto P_0c08a446;
case 0x0c08a448u: goto P_0c08a448;
case 0x0c08a44au: goto P_0c08a44a;
case 0x0c08a44cu: goto P_0c08a44c;
case 0x0c08a44eu: goto P_0c08a44e;
case 0x0c08a450u: goto P_0c08a450;
case 0x0c08a452u: goto P_0c08a452;
case 0x0c08a454u: goto P_0c08a454;
case 0x0c08a456u: goto P_0c08a456;
case 0x0c08a458u: goto P_0c08a458;
case 0x0c08a45au: goto P_0c08a45a;
case 0x0c08a45cu: goto P_0c08a45c;
case 0x0c08a45eu: goto P_0c08a45e;
case 0x0c08a460u: goto P_0c08a460;
case 0x0c08a462u: goto P_0c08a462;
case 0x0c08a464u: goto P_0c08a464;
case 0x0c08a466u: goto P_0c08a466;
case 0x0c08a468u: goto P_0c08a468;
case 0x0c08a46au: goto P_0c08a46a;
case 0x0c08a46cu: goto P_0c08a46c;
case 0x0c08a46eu: goto P_0c08a46e;
case 0x0c08a470u: goto P_0c08a470;
case 0x0c08a472u: goto P_0c08a472;
case 0x0c08a474u: goto P_0c08a474;
case 0x0c08a476u: goto P_0c08a476;
case 0x0c08a478u: goto P_0c08a478;
case 0x0c08a47au: goto P_0c08a47a;
case 0x0c08a47cu: goto P_0c08a47c;
case 0x0c08a47eu: goto P_0c08a47e;
case 0x0c08a480u: goto P_0c08a480;
case 0x0c08a482u: goto P_0c08a482;
case 0x0c08a484u: goto P_0c08a484;
case 0x0c08a486u: goto P_0c08a486;
case 0x0c08a488u: goto P_0c08a488;
case 0x0c08a48au: goto P_0c08a48a;
case 0x0c08a48cu: goto P_0c08a48c;
case 0x0c08a48eu: goto P_0c08a48e;
case 0x0c08a490u: goto P_0c08a490;
case 0x0c08a492u: goto P_0c08a492;
case 0x0c08a494u: goto P_0c08a494;
case 0x0c08a496u: goto P_0c08a496;
case 0x0c08a498u: goto P_0c08a498;
case 0x0c08a49au: goto P_0c08a49a;
case 0x0c08a49cu: goto P_0c08a49c;
case 0x0c08a49eu: goto P_0c08a49e;
case 0x0c08a4a0u: goto P_0c08a4a0;
case 0x0c08a4a2u: goto P_0c08a4a2;
case 0x0c08a4a4u: goto P_0c08a4a4;
case 0x0c08a4a6u: goto P_0c08a4a6;
case 0x0c08a4a8u: goto P_0c08a4a8;
case 0x0c08a4aau: goto P_0c08a4aa;
case 0x0c08a4acu: goto P_0c08a4ac;
case 0x0c08a4aeu: goto P_0c08a4ae;
case 0x0c08a4b0u: goto P_0c08a4b0;
case 0x0c08a4b2u: goto P_0c08a4b2;
case 0x0c08a4b4u: goto P_0c08a4b4;
case 0x0c08a4b6u: goto P_0c08a4b6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08a2cc: /* original 2fe6, guest PC 0x0c08a2cc */
if(!s->budget--) { s->failed_pc=0x0c08a2ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a2ce;
P_0c08a2ce: /* original 2fd6, guest PC 0x0c08a2ce */
if(!s->budget--) { s->failed_pc=0x0c08a2ceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a2d0;
P_0c08a2d0: /* original 2fc6, guest PC 0x0c08a2d0 */
if(!s->budget--) { s->failed_pc=0x0c08a2d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a2d2;
P_0c08a2d2: /* original 2fb6, guest PC 0x0c08a2d2 */
if(!s->budget--) { s->failed_pc=0x0c08a2d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a2d4;
P_0c08a2d4: /* original eb00, guest PC 0x0c08a2d4 */
if(!s->budget--) { s->failed_pc=0x0c08a2d4u; return 0; }
r[11]=0x00000000u;
goto P_0c08a2d6;
P_0c08a2d6: /* original fffb, guest PC 0x0c08a2d6 */
if(!s->budget--) { s->failed_pc=0x0c08a2d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a2d8;
P_0c08a2d8: /* original ffeb, guest PC 0x0c08a2d8 */
if(!s->budget--) { s->failed_pc=0x0c08a2d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08a2da;
P_0c08a2da: /* original ffdb, guest PC 0x0c08a2da */
if(!s->budget--) { s->failed_pc=0x0c08a2dau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08a2dc;
P_0c08a2dc: /* original 4f22, guest PC 0x0c08a2dc */
if(!s->budget--) { s->failed_pc=0x0c08a2dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a2de;
P_0c08a2de: /* original d330, guest PC 0x0c08a2de */
if(!s->budget--) { s->failed_pc=0x0c08a2deu; return 0; }
r[3]=read(ram,0x0c08a3a0u,4);
goto P_0c08a2e0;
P_0c08a2e0: /* original 7fd8, guest PC 0x0c08a2e0 */
if(!s->budget--) { s->failed_pc=0x0c08a2e0u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c08a2e2;
P_0c08a2e2: /* original 2f32, guest PC 0x0c08a2e2 */
if(!s->budget--) { s->failed_pc=0x0c08a2e2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08a2e4;
P_0c08a2e4: /* original d22f, guest PC 0x0c08a2e4 */
if(!s->budget--) { s->failed_pc=0x0c08a2e4u; return 0; }
r[2]=read(ram,0x0c08a3a4u,4);
goto P_0c08a2e6;
P_0c08a2e6: /* original 904a, guest PC 0x0c08a2e6 */
if(!s->budget--) { s->failed_pc=0x0c08a2e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a37eu,2);
goto P_0c08a2e8;
P_0c08a2e8: /* original 6422, guest PC 0x0c08a2e8 */
if(!s->budget--) { s->failed_pc=0x0c08a2e8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a2ea;
P_0c08a2ea: /* original 9e49, guest PC 0x0c08a2ea */
if(!s->budget--) { s->failed_pc=0x0c08a2eau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a380u,2);
goto P_0c08a2ec;
P_0c08a2ec: /* original 9549, guest PC 0x0c08a2ec */
if(!s->budget--) { s->failed_pc=0x0c08a2ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a382u,2);
goto P_0c08a2ee;
P_0c08a2ee: /* original 9d49, guest PC 0x0c08a2ee */
if(!s->budget--) { s->failed_pc=0x0c08a2eeu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a384u,2);
goto P_0c08a2f0;
P_0c08a2f0: /* original 044e, guest PC 0x0c08a2f0 */
if(!s->budget--) { s->failed_pc=0x0c08a2f0u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08a2f2;
P_0c08a2f2: /* original 3d4c, guest PC 0x0c08a2f2 */
if(!s->budget--) { s->failed_pc=0x0c08a2f2u; return 0; }
r[13]+=r[4];
goto P_0c08a2f4;
P_0c08a2f4: /* original 354c, guest PC 0x0c08a2f4 */
if(!s->budget--) { s->failed_pc=0x0c08a2f4u; return 0; }
r[5]+=r[4];
goto P_0c08a2f6;
P_0c08a2f6: /* original 3e4c, guest PC 0x0c08a2f6 */
if(!s->budget--) { s->failed_pc=0x0c08a2f6u; return 0; }
r[14]+=r[4];
goto P_0c08a2f8;
P_0c08a2f8: /* original 25b2, guest PC 0x0c08a2f8 */
if(!s->budget--) { s->failed_pc=0x0c08a2f8u; return 0; }
write(ram,r[5],r[11],4);
goto P_0c08a2fa;
P_0c08a2fa: /* original d32b, guest PC 0x0c08a2fa */
if(!s->budget--) { s->failed_pc=0x0c08a2fau; return 0; }
r[3]=read(ram,0x0c08a3a8u,4);
goto P_0c08a2fc;
P_0c08a2fc: /* original 64e3, guest PC 0x0c08a2fc */
if(!s->budget--) { s->failed_pc=0x0c08a2fcu; return 0; }
r[4]=r[14];
goto P_0c08a2fe;
P_0c08a2fe: /* original 430b, guest PC 0x0c08a2fe */
if(!s->budget--) { s->failed_pc=0x0c08a2feu; return 0; }
target=r[3];
r[16]=code_base|0x0c08a302u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a302u) { target=s->pc; goto dispatch; }
goto P_0c08a302;
P_0c08a300: /* original 7410, guest PC 0x0c08a300 */
if(!s->budget--) { s->failed_pc=0x0c08a300u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a302;
P_0c08a302: /* original e040, guest PC 0x0c08a302 */
if(!s->budget--) { s->failed_pc=0x0c08a302u; return 0; }
r[0]=0x00000040u;
goto P_0c08a304;
P_0c08a304: /* original f3e6, guest PC 0x0c08a304 */
if(!s->budget--) { s->failed_pc=0x0c08a304u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a306;
P_0c08a306: /* original e01c, guest PC 0x0c08a306 */
if(!s->budget--) { s->failed_pc=0x0c08a306u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a308;
P_0c08a308: /* original ff37, guest PC 0x0c08a308 */
if(!s->budget--) { s->failed_pc=0x0c08a308u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a30a;
P_0c08a30a: /* original e044, guest PC 0x0c08a30a */
if(!s->budget--) { s->failed_pc=0x0c08a30au; return 0; }
r[0]=0x00000044u;
goto P_0c08a30c;
P_0c08a30c: /* original f3e6, guest PC 0x0c08a30c */
if(!s->budget--) { s->failed_pc=0x0c08a30cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a30e;
P_0c08a30e: /* original e020, guest PC 0x0c08a30e */
if(!s->budget--) { s->failed_pc=0x0c08a30eu; return 0; }
r[0]=0x00000020u;
goto P_0c08a310;
P_0c08a310: /* original ff37, guest PC 0x0c08a310 */
if(!s->budget--) { s->failed_pc=0x0c08a310u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a312;
P_0c08a312: /* original e048, guest PC 0x0c08a312 */
if(!s->budget--) { s->failed_pc=0x0c08a312u; return 0; }
r[0]=0x00000048u;
goto P_0c08a314;
P_0c08a314: /* original f3e6, guest PC 0x0c08a314 */
if(!s->budget--) { s->failed_pc=0x0c08a314u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a316;
P_0c08a316: /* original e024, guest PC 0x0c08a316 */
if(!s->budget--) { s->failed_pc=0x0c08a316u; return 0; }
r[0]=0x00000024u;
goto P_0c08a318;
P_0c08a318: /* original ff37, guest PC 0x0c08a318 */
if(!s->budget--) { s->failed_pc=0x0c08a318u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a31a;
P_0c08a31a: /* original 9034, guest PC 0x0c08a31a */
if(!s->budget--) { s->failed_pc=0x0c08a31au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a386u,2);
goto P_0c08a31c;
P_0c08a31c: /* original 6cf2, guest PC 0x0c08a31c */
if(!s->budget--) { s->failed_pc=0x0c08a31cu; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c08a31e;
P_0c08a31e: /* original 0cce, guest PC 0x0c08a31e */
if(!s->budget--) { s->failed_pc=0x0c08a31eu; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c08a320;
P_0c08a320: /* original 9032, guest PC 0x0c08a320 */
if(!s->budget--) { s->failed_pc=0x0c08a320u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a388u,2);
goto P_0c08a322;
P_0c08a322: /* original ffc6, guest PC 0x0c08a322 */
if(!s->budget--) { s->failed_pc=0x0c08a322u; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c08a324;
P_0c08a324: /* original 7008, guest PC 0x0c08a324 */
if(!s->budget--) { s->failed_pc=0x0c08a324u; return 0; }
r[0]+=0x00000008u;
goto P_0c08a326;
P_0c08a326: /* original fec6, guest PC 0x0c08a326 */
if(!s->budget--) { s->failed_pc=0x0c08a326u; return 0; }
vf3_matrix_load(s,ram,14,r[12]+r[0]);
goto P_0c08a328;
P_0c08a328: /* original c720, guest PC 0x0c08a328 */
if(!s->budget--) { s->failed_pc=0x0c08a328u; return 0; }
r[0]=code_base|0x0008a3acu;
goto P_0c08a32a;
P_0c08a32a: /* original fd08, guest PC 0x0c08a32a */
if(!s->budget--) { s->failed_pc=0x0c08a32au; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c08a32c;
P_0c08a32c: /* original e01c, guest PC 0x0c08a32c */
if(!s->budget--) { s->failed_pc=0x0c08a32cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08a32e;
P_0c08a32e: /* original f3f6, guest PC 0x0c08a32e */
if(!s->budget--) { s->failed_pc=0x0c08a32eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a330;
P_0c08a330: /* original e024, guest PC 0x0c08a330 */
if(!s->budget--) { s->failed_pc=0x0c08a330u; return 0; }
r[0]=0x00000024u;
goto P_0c08a332;
P_0c08a332: /* original ff31, guest PC 0x0c08a332 */
if(!s->budget--) { s->failed_pc=0x0c08a332u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c08a334;
P_0c08a334: /* original f3f6, guest PC 0x0c08a334 */
if(!s->budget--) { s->failed_pc=0x0c08a334u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a336;
P_0c08a336: /* original fe31, guest PC 0x0c08a336 */
if(!s->budget--) { s->failed_pc=0x0c08a336u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c08a338;
P_0c08a338: /* original fff2, guest PC 0x0c08a338 */
if(!s->budget--) { s->failed_pc=0x0c08a338u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[15],r[18],'*');
goto P_0c08a33a;
P_0c08a33a: /* original f0ec, guest PC 0x0c08a33a */
if(!s->budget--) { s->failed_pc=0x0c08a33au; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c08a33c;
P_0c08a33c: /* original f3fc, guest PC 0x0c08a33c */
if(!s->budget--) { s->failed_pc=0x0c08a33cu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08a33e;
P_0c08a33e: /* original f3ee, guest PC 0x0c08a33e */
if(!s->budget--) { s->failed_pc=0x0c08a33eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c08a340;
P_0c08a340: /* original ff3c, guest PC 0x0c08a340 */
if(!s->budget--) { s->failed_pc=0x0c08a340u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c08a342;
P_0c08a342: /* original ffd5, guest PC 0x0c08a342 */
if(!s->budget--) { s->failed_pc=0x0c08a342u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[13]))!=0);
goto P_0c08a344;
P_0c08a344: /* original 8b3a, guest PC 0x0c08a344 */
if(!s->budget--) { s->failed_pc=0x0c08a344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08a3bc; }
goto P_0c08a346;
P_0c08a346: /* original e024, guest PC 0x0c08a346 */
if(!s->budget--) { s->failed_pc=0x0c08a346u; return 0; }
r[0]=0x00000024u;
goto P_0c08a348;
P_0c08a348: /* original 64f3, guest PC 0x0c08a348 */
if(!s->budget--) { s->failed_pc=0x0c08a348u; return 0; }
r[4]=r[15];
goto P_0c08a34a;
P_0c08a34a: /* original f5f6, guest PC 0x0c08a34a */
if(!s->budget--) { s->failed_pc=0x0c08a34au; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08a34c;
P_0c08a34c: /* original 65f3, guest PC 0x0c08a34c */
if(!s->budget--) { s->failed_pc=0x0c08a34cu; return 0; }
r[5]=r[15];
goto P_0c08a34e;
P_0c08a34e: /* original d318, guest PC 0x0c08a34e */
if(!s->budget--) { s->failed_pc=0x0c08a34eu; return 0; }
r[3]=read(ram,0x0c08a3b0u,4);
goto P_0c08a350;
P_0c08a350: /* original e01c, guest PC 0x0c08a350 */
if(!s->budget--) { s->failed_pc=0x0c08a350u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a352;
P_0c08a352: /* original 7420, guest PC 0x0c08a352 */
if(!s->budget--) { s->failed_pc=0x0c08a352u; return 0; }
r[4]+=0x00000020u;
goto P_0c08a354;
P_0c08a354: /* original f54d, guest PC 0x0c08a354 */
if(!s->budget--) { s->failed_pc=0x0c08a354u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08a356;
P_0c08a356: /* original 751c, guest PC 0x0c08a356 */
if(!s->budget--) { s->failed_pc=0x0c08a356u; return 0; }
r[5]+=0x0000001cu;
goto P_0c08a358;
P_0c08a358: /* original 430b, guest PC 0x0c08a358 */
if(!s->budget--) { s->failed_pc=0x0c08a358u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a35cu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a35cu) { target=s->pc; goto dispatch; }
goto P_0c08a35c;
P_0c08a35a: /* original f4f6, guest PC 0x0c08a35a */
if(!s->budget--) { s->failed_pc=0x0c08a35au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08a35c;
P_0c08a35c: /* original d215, guest PC 0x0c08a35c */
if(!s->budget--) { s->failed_pc=0x0c08a35cu; return 0; }
r[2]=read(ram,0x0c08a3b4u,4);
goto P_0c08a35e;
P_0c08a35e: /* original 64f3, guest PC 0x0c08a35e */
if(!s->budget--) { s->failed_pc=0x0c08a35eu; return 0; }
r[4]=r[15];
goto P_0c08a360;
P_0c08a360: /* original 420b, guest PC 0x0c08a360 */
if(!s->budget--) { s->failed_pc=0x0c08a360u; return 0; }
target=r[2];
r[16]=code_base|0x0c08a364u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a364u) { target=s->pc; goto dispatch; }
goto P_0c08a364;
P_0c08a362: /* original 741c, guest PC 0x0c08a362 */
if(!s->budget--) { s->failed_pc=0x0c08a362u; return 0; }
r[4]+=0x0000001cu;
goto P_0c08a364;
P_0c08a364: /* original e024, guest PC 0x0c08a364 */
if(!s->budget--) { s->failed_pc=0x0c08a364u; return 0; }
r[0]=0x00000024u;
goto P_0c08a366;
P_0c08a366: /* original f3f6, guest PC 0x0c08a366 */
if(!s->budget--) { s->failed_pc=0x0c08a366u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a368;
P_0c08a368: /* original e024, guest PC 0x0c08a368 */
if(!s->budget--) { s->failed_pc=0x0c08a368u; return 0; }
r[0]=0x00000024u;
goto P_0c08a36a;
P_0c08a36a: /* original f34d, guest PC 0x0c08a36a */
if(!s->budget--) { s->failed_pc=0x0c08a36au; return 0; }
fr[3]^=0x80000000u;
goto P_0c08a36c;
P_0c08a36c: /* original ff37, guest PC 0x0c08a36c */
if(!s->budget--) { s->failed_pc=0x0c08a36cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a36e;
P_0c08a36e: /* original c712, guest PC 0x0c08a36e */
if(!s->budget--) { s->failed_pc=0x0c08a36eu; return 0; }
r[0]=code_base|0x0008a3b8u;
goto P_0c08a370;
P_0c08a370: /* original f408, guest PC 0x0c08a370 */
if(!s->budget--) { s->failed_pc=0x0c08a370u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a372;
P_0c08a372: /* original e020, guest PC 0x0c08a372 */
if(!s->budget--) { s->failed_pc=0x0c08a372u; return 0; }
r[0]=0x00000020u;
goto P_0c08a374;
P_0c08a374: /* original f3f6, guest PC 0x0c08a374 */
if(!s->budget--) { s->failed_pc=0x0c08a374u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a376;
P_0c08a376: /* original e020, guest PC 0x0c08a376 */
if(!s->budget--) { s->failed_pc=0x0c08a376u; return 0; }
r[0]=0x00000020u;
goto P_0c08a378;
P_0c08a378: /* original f340, guest PC 0x0c08a378 */
if(!s->budget--) { s->failed_pc=0x0c08a378u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a37a;
P_0c08a37a: /* original a027, guest PC 0x0c08a37a */
if(!s->budget--) { s->failed_pc=0x0c08a37au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a3cc;
P_0c08a37c: /* original ff37, guest PC 0x0c08a37c */
if(!s->budget--) { s->failed_pc=0x0c08a37cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c08a37eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a37eu; return 0; } return 1;
P_0c08a3bc: /* original c740, guest PC 0x0c08a3bc */
if(!s->budget--) { s->failed_pc=0x0c08a3bcu; return 0; }
r[0]=code_base|0x0008a4c0u;
goto P_0c08a3be;
P_0c08a3be: /* original f308, guest PC 0x0c08a3be */
if(!s->budget--) { s->failed_pc=0x0c08a3beu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a3c0;
P_0c08a3c0: /* original e020, guest PC 0x0c08a3c0 */
if(!s->budget--) { s->failed_pc=0x0c08a3c0u; return 0; }
r[0]=0x00000020u;
goto P_0c08a3c2;
P_0c08a3c2: /* original ff37, guest PC 0x0c08a3c2 */
if(!s->budget--) { s->failed_pc=0x0c08a3c2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a3c4;
P_0c08a3c4: /* original f48d, guest PC 0x0c08a3c4 */
if(!s->budget--) { s->failed_pc=0x0c08a3c4u; return 0; }
fr[4]=0;
goto P_0c08a3c6;
P_0c08a3c6: /* original fe9d, guest PC 0x0c08a3c6 */
if(!s->budget--) { s->failed_pc=0x0c08a3c6u; return 0; }
fr[14]=0x3f800000u;
goto P_0c08a3c8;
P_0c08a3c8: /* original fd4c, guest PC 0x0c08a3c8 */
if(!s->budget--) { s->failed_pc=0x0c08a3c8u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c08a3ca;
P_0c08a3ca: /* original ff4c, guest PC 0x0c08a3ca */
if(!s->budget--) { s->failed_pc=0x0c08a3cau; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c08a3cc;
P_0c08a3cc: /* original e01c, guest PC 0x0c08a3cc */
if(!s->budget--) { s->failed_pc=0x0c08a3ccu; return 0; }
r[0]=0x0000001cu;
goto P_0c08a3ce;
P_0c08a3ce: /* original f3f6, guest PC 0x0c08a3ce */
if(!s->budget--) { s->failed_pc=0x0c08a3ceu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a3d0;
P_0c08a3d0: /* original e018, guest PC 0x0c08a3d0 */
if(!s->budget--) { s->failed_pc=0x0c08a3d0u; return 0; }
r[0]=0x00000018u;
goto P_0c08a3d2;
P_0c08a3d2: /* original fd37, guest PC 0x0c08a3d2 */
if(!s->budget--) { s->failed_pc=0x0c08a3d2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a3d4;
P_0c08a3d4: /* original e020, guest PC 0x0c08a3d4 */
if(!s->budget--) { s->failed_pc=0x0c08a3d4u; return 0; }
r[0]=0x00000020u;
goto P_0c08a3d6;
P_0c08a3d6: /* original f3f6, guest PC 0x0c08a3d6 */
if(!s->budget--) { s->failed_pc=0x0c08a3d6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a3d8;
P_0c08a3d8: /* original e01c, guest PC 0x0c08a3d8 */
if(!s->budget--) { s->failed_pc=0x0c08a3d8u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a3da;
P_0c08a3da: /* original fd37, guest PC 0x0c08a3da */
if(!s->budget--) { s->failed_pc=0x0c08a3dau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a3dc;
P_0c08a3dc: /* original e024, guest PC 0x0c08a3dc */
if(!s->budget--) { s->failed_pc=0x0c08a3dcu; return 0; }
r[0]=0x00000024u;
goto P_0c08a3de;
P_0c08a3de: /* original f3f6, guest PC 0x0c08a3de */
if(!s->budget--) { s->failed_pc=0x0c08a3deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a3e0;
P_0c08a3e0: /* original e020, guest PC 0x0c08a3e0 */
if(!s->budget--) { s->failed_pc=0x0c08a3e0u; return 0; }
r[0]=0x00000020u;
goto P_0c08a3e2;
P_0c08a3e2: /* original fd37, guest PC 0x0c08a3e2 */
if(!s->budget--) { s->failed_pc=0x0c08a3e2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a3e4;
P_0c08a3e4: /* original e004, guest PC 0x0c08a3e4 */
if(!s->budget--) { s->failed_pc=0x0c08a3e4u; return 0; }
r[0]=0x00000004u;
goto P_0c08a3e6;
P_0c08a3e6: /* original fdfa, guest PC 0x0c08a3e6 */
if(!s->budget--) { s->failed_pc=0x0c08a3e6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c08a3e8;
P_0c08a3e8: /* original fde7, guest PC 0x0c08a3e8 */
if(!s->budget--) { s->failed_pc=0x0c08a3e8u; return 0; }
vf3_matrix_store(s,ram,14,r[13]+r[0]);
goto P_0c08a3ea;
P_0c08a3ea: /* original e008, guest PC 0x0c08a3ea */
if(!s->budget--) { s->failed_pc=0x0c08a3eau; return 0; }
r[0]=0x00000008u;
goto P_0c08a3ec;
P_0c08a3ec: /* original fdd7, guest PC 0x0c08a3ec */
if(!s->budget--) { s->failed_pc=0x0c08a3ecu; return 0; }
vf3_matrix_store(s,ram,13,r[13]+r[0]);
goto P_0c08a3ee;
P_0c08a3ee: /* original c735, guest PC 0x0c08a3ee */
if(!s->budget--) { s->failed_pc=0x0c08a3eeu; return 0; }
r[0]=code_base|0x0008a4c4u;
goto P_0c08a3f0;
P_0c08a3f0: /* original f408, guest PC 0x0c08a3f0 */
if(!s->budget--) { s->failed_pc=0x0c08a3f0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a3f2;
P_0c08a3f2: /* original e01c, guest PC 0x0c08a3f2 */
if(!s->budget--) { s->failed_pc=0x0c08a3f2u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a3f4;
P_0c08a3f4: /* original f3f6, guest PC 0x0c08a3f4 */
if(!s->budget--) { s->failed_pc=0x0c08a3f4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a3f6;
P_0c08a3f6: /* original e01c, guest PC 0x0c08a3f6 */
if(!s->budget--) { s->failed_pc=0x0c08a3f6u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a3f8;
P_0c08a3f8: /* original f04c, guest PC 0x0c08a3f8 */
if(!s->budget--) { s->failed_pc=0x0c08a3f8u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08a3fa;
P_0c08a3fa: /* original f3fe, guest PC 0x0c08a3fa */
if(!s->budget--) { s->failed_pc=0x0c08a3fau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c08a3fc;
P_0c08a3fc: /* original ff37, guest PC 0x0c08a3fc */
if(!s->budget--) { s->failed_pc=0x0c08a3fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a3fe;
P_0c08a3fe: /* original e020, guest PC 0x0c08a3fe */
if(!s->budget--) { s->failed_pc=0x0c08a3feu; return 0; }
r[0]=0x00000020u;
goto P_0c08a400;
P_0c08a400: /* original f3f6, guest PC 0x0c08a400 */
if(!s->budget--) { s->failed_pc=0x0c08a400u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a402;
P_0c08a402: /* original e020, guest PC 0x0c08a402 */
if(!s->budget--) { s->failed_pc=0x0c08a402u; return 0; }
r[0]=0x00000020u;
goto P_0c08a404;
P_0c08a404: /* original f3ee, guest PC 0x0c08a404 */
if(!s->budget--) { s->failed_pc=0x0c08a404u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c08a406;
P_0c08a406: /* original ff37, guest PC 0x0c08a406 */
if(!s->budget--) { s->failed_pc=0x0c08a406u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a408;
P_0c08a408: /* original e024, guest PC 0x0c08a408 */
if(!s->budget--) { s->failed_pc=0x0c08a408u; return 0; }
r[0]=0x00000024u;
goto P_0c08a40a;
P_0c08a40a: /* original f3f6, guest PC 0x0c08a40a */
if(!s->budget--) { s->failed_pc=0x0c08a40au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a40c;
P_0c08a40c: /* original f3de, guest PC 0x0c08a40c */
if(!s->budget--) { s->failed_pc=0x0c08a40cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[13],fr[3],r[18]);
goto P_0c08a40e;
P_0c08a40e: /* original e024, guest PC 0x0c08a40e */
if(!s->budget--) { s->failed_pc=0x0c08a40eu; return 0; }
r[0]=0x00000024u;
goto P_0c08a410;
P_0c08a410: /* original ff37, guest PC 0x0c08a410 */
if(!s->budget--) { s->failed_pc=0x0c08a410u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a412;
P_0c08a412: /* original e01c, guest PC 0x0c08a412 */
if(!s->budget--) { s->failed_pc=0x0c08a412u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a414;
P_0c08a414: /* original f3f6, guest PC 0x0c08a414 */
if(!s->budget--) { s->failed_pc=0x0c08a414u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a416;
P_0c08a416: /* original e00c, guest PC 0x0c08a416 */
if(!s->budget--) { s->failed_pc=0x0c08a416u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a418;
P_0c08a418: /* original fd37, guest PC 0x0c08a418 */
if(!s->budget--) { s->failed_pc=0x0c08a418u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a41a;
P_0c08a41a: /* original e020, guest PC 0x0c08a41a */
if(!s->budget--) { s->failed_pc=0x0c08a41au; return 0; }
r[0]=0x00000020u;
goto P_0c08a41c;
P_0c08a41c: /* original f3f6, guest PC 0x0c08a41c */
if(!s->budget--) { s->failed_pc=0x0c08a41cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a41e;
P_0c08a41e: /* original e010, guest PC 0x0c08a41e */
if(!s->budget--) { s->failed_pc=0x0c08a41eu; return 0; }
r[0]=0x00000010u;
goto P_0c08a420;
P_0c08a420: /* original fd37, guest PC 0x0c08a420 */
if(!s->budget--) { s->failed_pc=0x0c08a420u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a422;
P_0c08a422: /* original e024, guest PC 0x0c08a422 */
if(!s->budget--) { s->failed_pc=0x0c08a422u; return 0; }
r[0]=0x00000024u;
goto P_0c08a424;
P_0c08a424: /* original f3f6, guest PC 0x0c08a424 */
if(!s->budget--) { s->failed_pc=0x0c08a424u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a426;
P_0c08a426: /* original e014, guest PC 0x0c08a426 */
if(!s->budget--) { s->failed_pc=0x0c08a426u; return 0; }
r[0]=0x00000014u;
goto P_0c08a428;
P_0c08a428: /* original fd37, guest PC 0x0c08a428 */
if(!s->budget--) { s->failed_pc=0x0c08a428u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08a42a;
P_0c08a42a: /* original e044, guest PC 0x0c08a42a */
if(!s->budget--) { s->failed_pc=0x0c08a42au; return 0; }
r[0]=0x00000044u;
goto P_0c08a42c;
P_0c08a42c: /* original f3e6, guest PC 0x0c08a42c */
if(!s->budget--) { s->failed_pc=0x0c08a42cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08a42e;
P_0c08a42e: /* original 9043, guest PC 0x0c08a42e */
if(!s->budget--) { s->failed_pc=0x0c08a42eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a4b8u,2);
goto P_0c08a430;
P_0c08a430: /* original f2c6, guest PC 0x0c08a430 */
if(!s->budget--) { s->failed_pc=0x0c08a430u; return 0; }
vf3_matrix_load(s,ram,2,r[12]+r[0]);
goto P_0c08a432;
P_0c08a432: /* original f235, guest PC 0x0c08a432 */
if(!s->budget--) { s->failed_pc=0x0c08a432u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08a434;
P_0c08a434: /* original 8b01, guest PC 0x0c08a434 */
if(!s->budget--) { s->failed_pc=0x0c08a434u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08a43a; }
goto P_0c08a436;
P_0c08a436: /* original a001, guest PC 0x0c08a436 */
if(!s->budget--) { s->failed_pc=0x0c08a436u; return 0; }
r[4]=0x00000001u;
goto P_0c08a43c;
P_0c08a438: /* original e401, guest PC 0x0c08a438 */
if(!s->budget--) { s->failed_pc=0x0c08a438u; return 0; }
r[4]=0x00000001u;
goto P_0c08a43a;
P_0c08a43a: /* original 64b3, guest PC 0x0c08a43a */
if(!s->budget--) { s->failed_pc=0x0c08a43au; return 0; }
r[4]=r[11];
goto P_0c08a43c;
P_0c08a43c: /* original 903d, guest PC 0x0c08a43c */
if(!s->budget--) { s->failed_pc=0x0c08a43cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a4bau,2);
goto P_0c08a43e;
P_0c08a43e: /* original 03ed, guest PC 0x0c08a43e */
if(!s->budget--) { s->failed_pc=0x0c08a43eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a440;
P_0c08a440: /* original 4315, guest PC 0x0c08a440 */
if(!s->budget--) { s->failed_pc=0x0c08a440u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c08a442;
P_0c08a442: /* original 8b00, guest PC 0x0c08a442 */
if(!s->budget--) { s->failed_pc=0x0c08a442u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08a446; }
goto P_0c08a444;
P_0c08a444: /* original 64b3, guest PC 0x0c08a444 */
if(!s->budget--) { s->failed_pc=0x0c08a444u; return 0; }
r[4]=r[11];
goto P_0c08a446;
P_0c08a446: /* original 2448, guest PC 0x0c08a446 */
if(!s->budget--) { s->failed_pc=0x0c08a446u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08a448;
P_0c08a448: /* original 8902, guest PC 0x0c08a448 */
if(!s->budget--) { s->failed_pc=0x0c08a448u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a450; }
goto P_0c08a44a;
P_0c08a44a: /* original 03ed, guest PC 0x0c08a44a */
if(!s->budget--) { s->failed_pc=0x0c08a44au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a44c;
P_0c08a44c: /* original 7301, guest PC 0x0c08a44c */
if(!s->budget--) { s->failed_pc=0x0c08a44cu; return 0; }
r[3]+=0x00000001u;
goto P_0c08a44e;
P_0c08a44e: /* original 0e35, guest PC 0x0c08a44e */
if(!s->budget--) { s->failed_pc=0x0c08a44eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08a450;
P_0c08a450: /* original 64f3, guest PC 0x0c08a450 */
if(!s->budget--) { s->failed_pc=0x0c08a450u; return 0; }
r[4]=r[15];
goto P_0c08a452;
P_0c08a452: /* original 7410, guest PC 0x0c08a452 */
if(!s->budget--) { s->failed_pc=0x0c08a452u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a454;
P_0c08a454: /* original f348, guest PC 0x0c08a454 */
if(!s->budget--) { s->failed_pc=0x0c08a454u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c08a456;
P_0c08a456: /* original e01c, guest PC 0x0c08a456 */
if(!s->budget--) { s->failed_pc=0x0c08a456u; return 0; }
r[0]=0x0000001cu;
goto P_0c08a458;
P_0c08a458: /* original ff37, guest PC 0x0c08a458 */
if(!s->budget--) { s->failed_pc=0x0c08a458u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a45a;
P_0c08a45a: /* original e004, guest PC 0x0c08a45a */
if(!s->budget--) { s->failed_pc=0x0c08a45au; return 0; }
r[0]=0x00000004u;
goto P_0c08a45c;
P_0c08a45c: /* original f346, guest PC 0x0c08a45c */
if(!s->budget--) { s->failed_pc=0x0c08a45cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a45e;
P_0c08a45e: /* original e020, guest PC 0x0c08a45e */
if(!s->budget--) { s->failed_pc=0x0c08a45eu; return 0; }
r[0]=0x00000020u;
goto P_0c08a460;
P_0c08a460: /* original ff37, guest PC 0x0c08a460 */
if(!s->budget--) { s->failed_pc=0x0c08a460u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a462;
P_0c08a462: /* original e008, guest PC 0x0c08a462 */
if(!s->budget--) { s->failed_pc=0x0c08a462u; return 0; }
r[0]=0x00000008u;
goto P_0c08a464;
P_0c08a464: /* original f346, guest PC 0x0c08a464 */
if(!s->budget--) { s->failed_pc=0x0c08a464u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a466;
P_0c08a466: /* original e024, guest PC 0x0c08a466 */
if(!s->budget--) { s->failed_pc=0x0c08a466u; return 0; }
r[0]=0x00000024u;
goto P_0c08a468;
P_0c08a468: /* original ff37, guest PC 0x0c08a468 */
if(!s->budget--) { s->failed_pc=0x0c08a468u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a46a;
P_0c08a46a: /* original 9026, guest PC 0x0c08a46a */
if(!s->budget--) { s->failed_pc=0x0c08a46au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a4bau,2);
goto P_0c08a46c;
P_0c08a46c: /* original 03ed, guest PC 0x0c08a46c */
if(!s->budget--) { s->failed_pc=0x0c08a46cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08a46e;
P_0c08a46e: /* original 2338, guest PC 0x0c08a46e */
if(!s->budget--) { s->failed_pc=0x0c08a46eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08a470;
P_0c08a470: /* original 8916, guest PC 0x0c08a470 */
if(!s->budget--) { s->failed_pc=0x0c08a470u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a4a0; }
goto P_0c08a472;
P_0c08a472: /* original d215, guest PC 0x0c08a472 */
if(!s->budget--) { s->failed_pc=0x0c08a472u; return 0; }
r[2]=read(ram,0x0c08a4c8u,4);
goto P_0c08a474;
P_0c08a474: /* original 9622, guest PC 0x0c08a474 */
if(!s->budget--) { s->failed_pc=0x0c08a474u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a4bcu,2);
goto P_0c08a476;
P_0c08a476: /* original 6522, guest PC 0x0c08a476 */
if(!s->budget--) { s->failed_pc=0x0c08a476u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c08a478;
P_0c08a478: /* original 5455, guest PC 0x0c08a478 */
if(!s->budget--) { s->failed_pc=0x0c08a478u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c08a47a;
P_0c08a47a: /* original 6743, guest PC 0x0c08a47a */
if(!s->budget--) { s->failed_pc=0x0c08a47au; return 0; }
r[7]=r[4];
goto P_0c08a47c;
P_0c08a47c: /* original 2778, guest PC 0x0c08a47c */
if(!s->budget--) { s->failed_pc=0x0c08a47cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c08a47e;
P_0c08a47e: /* original 7401, guest PC 0x0c08a47e */
if(!s->budget--) { s->failed_pc=0x0c08a47eu; return 0; }
r[4]+=0x00000001u;
goto P_0c08a480;
P_0c08a480: /* original 8d0b, guest PC 0x0c08a480 */
if(!s->budget--) { s->failed_pc=0x0c08a480u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+20,r[4],4);
if(cond) { goto P_0c08a49a; }
goto P_0c08a484;
P_0c08a482: /* original 1545, guest PC 0x0c08a482 */
if(!s->budget--) { s->failed_pc=0x0c08a482u; return 0; }
write(ram,r[5]+20,r[4],4);
goto P_0c08a484;
P_0c08a484: /* original 6043, guest PC 0x0c08a484 */
if(!s->budget--) { s->failed_pc=0x0c08a484u; return 0; }
r[0]=r[4];
goto P_0c08a486;
P_0c08a486: /* original 961a, guest PC 0x0c08a486 */
if(!s->budget--) { s->failed_pc=0x0c08a486u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a4beu,2);
goto P_0c08a488;
P_0c08a488: /* original 8803, guest PC 0x0c08a488 */
if(!s->budget--) { s->failed_pc=0x0c08a488u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c08a48a;
P_0c08a48a: /* original 8906, guest PC 0x0c08a48a */
if(!s->budget--) { s->failed_pc=0x0c08a48au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a49a; }
goto P_0c08a48c;
P_0c08a48c: /* original e73f, guest PC 0x0c08a48c */
if(!s->budget--) { s->failed_pc=0x0c08a48cu; return 0; }
r[7]=0x0000003fu;
goto P_0c08a48e;
P_0c08a48e: /* original 2749, guest PC 0x0c08a48e */
if(!s->budget--) { s->failed_pc=0x0c08a48eu; return 0; }
r[7]&=r[4];
goto P_0c08a490;
P_0c08a490: /* original 2778, guest PC 0x0c08a490 */
if(!s->budget--) { s->failed_pc=0x0c08a490u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c08a492;
P_0c08a492: /* original 8b05, guest PC 0x0c08a492 */
if(!s->budget--) { s->failed_pc=0x0c08a492u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08a4a0; }
goto P_0c08a494;
P_0c08a494: /* original e340, guest PC 0x0c08a494 */
if(!s->budget--) { s->failed_pc=0x0c08a494u; return 0; }
r[3]=0x00000040u;
goto P_0c08a496;
P_0c08a496: /* original 3437, guest PC 0x0c08a496 */
if(!s->budget--) { s->failed_pc=0x0c08a496u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c08a498;
P_0c08a498: /* original 8902, guest PC 0x0c08a498 */
if(!s->budget--) { s->failed_pc=0x0c08a498u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08a4a0; }
goto P_0c08a49a;
P_0c08a49a: /* original 6452, guest PC 0x0c08a49a */
if(!s->budget--) { s->failed_pc=0x0c08a49au; return 0; }
tmp=read(ram,r[5],4);
r[4]=tmp;
goto P_0c08a49c;
P_0c08a49c: /* original 246b, guest PC 0x0c08a49c */
if(!s->budget--) { s->failed_pc=0x0c08a49cu; return 0; }
r[4]|=r[6];
goto P_0c08a49e;
P_0c08a49e: /* original 2542, guest PC 0x0c08a49e */
if(!s->budget--) { s->failed_pc=0x0c08a49eu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c08a4a0;
P_0c08a4a0: /* original b014, guest PC 0x0c08a4a0 */
if(!s->budget--) { s->failed_pc=0x0c08a4a0u; return 0; }
target=code_base|0x0c08a4ccu; r[16]=code_base|0x0c08a4a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a4a4u) { target=s->pc; goto dispatch; }
goto P_0c08a4a4;
P_0c08a4a2: /* original 64e3, guest PC 0x0c08a4a2 */
if(!s->budget--) { s->failed_pc=0x0c08a4a2u; return 0; }
r[4]=r[14];
goto P_0c08a4a4;
P_0c08a4a4: /* original 7f28, guest PC 0x0c08a4a4 */
if(!s->budget--) { s->failed_pc=0x0c08a4a4u; return 0; }
r[15]+=0x00000028u;
goto P_0c08a4a6;
P_0c08a4a6: /* original 4f26, guest PC 0x0c08a4a6 */
if(!s->budget--) { s->failed_pc=0x0c08a4a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a4a8;
P_0c08a4a8: /* original fdf9, guest PC 0x0c08a4a8 */
if(!s->budget--) { s->failed_pc=0x0c08a4a8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a4aa;
P_0c08a4aa: /* original fef9, guest PC 0x0c08a4aa */
if(!s->budget--) { s->failed_pc=0x0c08a4aau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a4ac;
P_0c08a4ac: /* original fff9, guest PC 0x0c08a4ac */
if(!s->budget--) { s->failed_pc=0x0c08a4acu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a4ae;
P_0c08a4ae: /* original 6bf6, guest PC 0x0c08a4ae */
if(!s->budget--) { s->failed_pc=0x0c08a4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a4b0;
P_0c08a4b0: /* original 6cf6, guest PC 0x0c08a4b0 */
if(!s->budget--) { s->failed_pc=0x0c08a4b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a4b2;
P_0c08a4b2: /* original 6df6, guest PC 0x0c08a4b2 */
if(!s->budget--) { s->failed_pc=0x0c08a4b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a4b4;
P_0c08a4b4: /* original 000b, guest PC 0x0c08a4b4 */
if(!s->budget--) { s->failed_pc=0x0c08a4b4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a4b6: /* original 6ef6, guest PC 0x0c08a4b6 */
if(!s->budget--) { s->failed_pc=0x0c08a4b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a4b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a4b8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
