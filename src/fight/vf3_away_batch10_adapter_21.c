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
int vf3_away_batch10_adapter_21(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06e31cu: goto P_0c06e31c;
case 0x0c06e31eu: goto P_0c06e31e;
case 0x0c06e320u: goto P_0c06e320;
case 0x0c06e322u: goto P_0c06e322;
case 0x0c06e324u: goto P_0c06e324;
case 0x0c06e326u: goto P_0c06e326;
case 0x0c06e328u: goto P_0c06e328;
case 0x0c06e32au: goto P_0c06e32a;
case 0x0c06e32cu: goto P_0c06e32c;
case 0x0c06e32eu: goto P_0c06e32e;
case 0x0c06e330u: goto P_0c06e330;
case 0x0c06e332u: goto P_0c06e332;
case 0x0c06e334u: goto P_0c06e334;
case 0x0c06e336u: goto P_0c06e336;
case 0x0c06e338u: goto P_0c06e338;
case 0x0c06e33au: goto P_0c06e33a;
case 0x0c06e33cu: goto P_0c06e33c;
case 0x0c06e33eu: goto P_0c06e33e;
case 0x0c06e340u: goto P_0c06e340;
case 0x0c06e342u: goto P_0c06e342;
case 0x0c06e344u: goto P_0c06e344;
case 0x0c06e346u: goto P_0c06e346;
case 0x0c06e348u: goto P_0c06e348;
case 0x0c06e34au: goto P_0c06e34a;
case 0x0c06e34cu: goto P_0c06e34c;
case 0x0c06e34eu: goto P_0c06e34e;
case 0x0c06e350u: goto P_0c06e350;
case 0x0c06e352u: goto P_0c06e352;
case 0x0c06e354u: goto P_0c06e354;
case 0x0c06e356u: goto P_0c06e356;
case 0x0c06e358u: goto P_0c06e358;
case 0x0c06e35au: goto P_0c06e35a;
case 0x0c06e35cu: goto P_0c06e35c;
case 0x0c06e35eu: goto P_0c06e35e;
case 0x0c06e360u: goto P_0c06e360;
case 0x0c06e362u: goto P_0c06e362;
case 0x0c06e364u: goto P_0c06e364;
case 0x0c06e366u: goto P_0c06e366;
case 0x0c06e368u: goto P_0c06e368;
case 0x0c06e36au: goto P_0c06e36a;
case 0x0c06e36cu: goto P_0c06e36c;
case 0x0c06e36eu: goto P_0c06e36e;
case 0x0c06e370u: goto P_0c06e370;
case 0x0c06e372u: goto P_0c06e372;
case 0x0c06e374u: goto P_0c06e374;
case 0x0c06e376u: goto P_0c06e376;
case 0x0c06e378u: goto P_0c06e378;
case 0x0c06e37au: goto P_0c06e37a;
case 0x0c06e37cu: goto P_0c06e37c;
case 0x0c06e37eu: goto P_0c06e37e;
case 0x0c06e380u: goto P_0c06e380;
case 0x0c06e382u: goto P_0c06e382;
case 0x0c06e384u: goto P_0c06e384;
case 0x0c06e386u: goto P_0c06e386;
case 0x0c06e388u: goto P_0c06e388;
case 0x0c06e38au: goto P_0c06e38a;
case 0x0c06e38cu: goto P_0c06e38c;
case 0x0c06e38eu: goto P_0c06e38e;
case 0x0c06e390u: goto P_0c06e390;
case 0x0c06e392u: goto P_0c06e392;
case 0x0c06e394u: goto P_0c06e394;
case 0x0c06e396u: goto P_0c06e396;
case 0x0c06e398u: goto P_0c06e398;
case 0x0c06e39au: goto P_0c06e39a;
case 0x0c06e39cu: goto P_0c06e39c;
case 0x0c06e39eu: goto P_0c06e39e;
case 0x0c06e3a0u: goto P_0c06e3a0;
case 0x0c06e3a2u: goto P_0c06e3a2;
case 0x0c06e3a4u: goto P_0c06e3a4;
case 0x0c06e3a6u: goto P_0c06e3a6;
case 0x0c06e3a8u: goto P_0c06e3a8;
case 0x0c06e3aau: goto P_0c06e3aa;
case 0x0c06e3acu: goto P_0c06e3ac;
case 0x0c06e3aeu: goto P_0c06e3ae;
case 0x0c06e3b0u: goto P_0c06e3b0;
case 0x0c06e3b2u: goto P_0c06e3b2;
case 0x0c06e3b4u: goto P_0c06e3b4;
case 0x0c06e3b6u: goto P_0c06e3b6;
case 0x0c06e3b8u: goto P_0c06e3b8;
case 0x0c06e3bau: goto P_0c06e3ba;
case 0x0c06e3bcu: goto P_0c06e3bc;
case 0x0c06e3beu: goto P_0c06e3be;
case 0x0c06e3c0u: goto P_0c06e3c0;
case 0x0c06e3c2u: goto P_0c06e3c2;
case 0x0c06e3c4u: goto P_0c06e3c4;
case 0x0c06e3c6u: goto P_0c06e3c6;
case 0x0c06e3c8u: goto P_0c06e3c8;
case 0x0c06e3cau: goto P_0c06e3ca;
case 0x0c06e3ccu: goto P_0c06e3cc;
case 0x0c06e3ceu: goto P_0c06e3ce;
case 0x0c06e3d0u: goto P_0c06e3d0;
case 0x0c06e3d2u: goto P_0c06e3d2;
case 0x0c06e3d4u: goto P_0c06e3d4;
case 0x0c06e3d6u: goto P_0c06e3d6;
case 0x0c06e3d8u: goto P_0c06e3d8;
case 0x0c06e3dau: goto P_0c06e3da;
case 0x0c06e3dcu: goto P_0c06e3dc;
case 0x0c06e3deu: goto P_0c06e3de;
case 0x0c06e3e0u: goto P_0c06e3e0;
case 0x0c06e3e2u: goto P_0c06e3e2;
case 0x0c06e3e4u: goto P_0c06e3e4;
case 0x0c06e3e6u: goto P_0c06e3e6;
case 0x0c06e3e8u: goto P_0c06e3e8;
case 0x0c06e3eau: goto P_0c06e3ea;
case 0x0c06e3ecu: goto P_0c06e3ec;
case 0x0c06e3eeu: goto P_0c06e3ee;
case 0x0c06e3f0u: goto P_0c06e3f0;
case 0x0c06e3f2u: goto P_0c06e3f2;
case 0x0c06e3f4u: goto P_0c06e3f4;
case 0x0c06e3f6u: goto P_0c06e3f6;
case 0x0c06e3f8u: goto P_0c06e3f8;
case 0x0c06e3fau: goto P_0c06e3fa;
case 0x0c06e3fcu: goto P_0c06e3fc;
case 0x0c06e3feu: goto P_0c06e3fe;
case 0x0c06e400u: goto P_0c06e400;
case 0x0c06e402u: goto P_0c06e402;
case 0x0c06e404u: goto P_0c06e404;
case 0x0c06e406u: goto P_0c06e406;
case 0x0c06e408u: goto P_0c06e408;
case 0x0c06e40au: goto P_0c06e40a;
case 0x0c06e40cu: goto P_0c06e40c;
case 0x0c06e40eu: goto P_0c06e40e;
case 0x0c06e410u: goto P_0c06e410;
case 0x0c06e412u: goto P_0c06e412;
case 0x0c06e414u: goto P_0c06e414;
case 0x0c06e416u: goto P_0c06e416;
case 0x0c06e418u: goto P_0c06e418;
case 0x0c06e41au: goto P_0c06e41a;
case 0x0c06e41cu: goto P_0c06e41c;
case 0x0c06e41eu: goto P_0c06e41e;
case 0x0c06e420u: goto P_0c06e420;
case 0x0c06e422u: goto P_0c06e422;
case 0x0c06e424u: goto P_0c06e424;
case 0x0c06e426u: goto P_0c06e426;
case 0x0c06e428u: goto P_0c06e428;
case 0x0c06e42au: goto P_0c06e42a;
case 0x0c06e42cu: goto P_0c06e42c;
case 0x0c06e42eu: goto P_0c06e42e;
case 0x0c06e430u: goto P_0c06e430;
case 0x0c06e432u: goto P_0c06e432;
case 0x0c06e434u: goto P_0c06e434;
case 0x0c06e436u: goto P_0c06e436;
case 0x0c06e438u: goto P_0c06e438;
case 0x0c06e43au: goto P_0c06e43a;
case 0x0c06e43cu: goto P_0c06e43c;
case 0x0c06e43eu: goto P_0c06e43e;
case 0x0c06e440u: goto P_0c06e440;
case 0x0c06e442u: goto P_0c06e442;
case 0x0c06e444u: goto P_0c06e444;
case 0x0c06e446u: goto P_0c06e446;
case 0x0c06e448u: goto P_0c06e448;
case 0x0c06e44au: goto P_0c06e44a;
case 0x0c06e44cu: goto P_0c06e44c;
case 0x0c06e44eu: goto P_0c06e44e;
case 0x0c06e450u: goto P_0c06e450;
case 0x0c06e452u: goto P_0c06e452;
case 0x0c06e454u: goto P_0c06e454;
case 0x0c06e456u: goto P_0c06e456;
case 0x0c06e458u: goto P_0c06e458;
case 0x0c06e45au: goto P_0c06e45a;
case 0x0c06e45cu: goto P_0c06e45c;
case 0x0c06e45eu: goto P_0c06e45e;
case 0x0c06e460u: goto P_0c06e460;
case 0x0c06e462u: goto P_0c06e462;
case 0x0c06e464u: goto P_0c06e464;
case 0x0c06e466u: goto P_0c06e466;
case 0x0c06e468u: goto P_0c06e468;
case 0x0c06e46au: goto P_0c06e46a;
case 0x0c06e46cu: goto P_0c06e46c;
case 0x0c06e46eu: goto P_0c06e46e;
case 0x0c06e470u: goto P_0c06e470;
case 0x0c06e472u: goto P_0c06e472;
case 0x0c06e474u: goto P_0c06e474;
case 0x0c06e476u: goto P_0c06e476;
case 0x0c06e478u: goto P_0c06e478;
case 0x0c06e47au: goto P_0c06e47a;
case 0x0c06e47cu: goto P_0c06e47c;
case 0x0c06e47eu: goto P_0c06e47e;
case 0x0c06e480u: goto P_0c06e480;
case 0x0c06e482u: goto P_0c06e482;
case 0x0c06e484u: goto P_0c06e484;
case 0x0c06e486u: goto P_0c06e486;
case 0x0c06e488u: goto P_0c06e488;
case 0x0c06e48au: goto P_0c06e48a;
case 0x0c06e48cu: goto P_0c06e48c;
case 0x0c06e48eu: goto P_0c06e48e;
case 0x0c06e490u: goto P_0c06e490;
case 0x0c06e492u: goto P_0c06e492;
case 0x0c06e494u: goto P_0c06e494;
case 0x0c06e496u: goto P_0c06e496;
case 0x0c06e4b0u: goto P_0c06e4b0;
case 0x0c06e4b2u: goto P_0c06e4b2;
case 0x0c06e4b4u: goto P_0c06e4b4;
case 0x0c06e4b6u: goto P_0c06e4b6;
case 0x0c06e4b8u: goto P_0c06e4b8;
case 0x0c06e4bau: goto P_0c06e4ba;
case 0x0c06e4bcu: goto P_0c06e4bc;
case 0x0c06e4beu: goto P_0c06e4be;
case 0x0c06e4c0u: goto P_0c06e4c0;
case 0x0c06e4c2u: goto P_0c06e4c2;
case 0x0c06e4c4u: goto P_0c06e4c4;
case 0x0c06e4c6u: goto P_0c06e4c6;
case 0x0c06e4c8u: goto P_0c06e4c8;
case 0x0c06e4cau: goto P_0c06e4ca;
case 0x0c06e4ccu: goto P_0c06e4cc;
case 0x0c06e4ceu: goto P_0c06e4ce;
case 0x0c06e4d0u: goto P_0c06e4d0;
case 0x0c06e4d2u: goto P_0c06e4d2;
case 0x0c06e4d4u: goto P_0c06e4d4;
case 0x0c06e4d6u: goto P_0c06e4d6;
case 0x0c06e4d8u: goto P_0c06e4d8;
case 0x0c06e4dau: goto P_0c06e4da;
case 0x0c06e4dcu: goto P_0c06e4dc;
case 0x0c06e4deu: goto P_0c06e4de;
case 0x0c06e4e0u: goto P_0c06e4e0;
case 0x0c06e4e2u: goto P_0c06e4e2;
case 0x0c06e4e4u: goto P_0c06e4e4;
case 0x0c06e4e6u: goto P_0c06e4e6;
case 0x0c06e4e8u: goto P_0c06e4e8;
case 0x0c06e4eau: goto P_0c06e4ea;
case 0x0c06e4ecu: goto P_0c06e4ec;
case 0x0c06e4eeu: goto P_0c06e4ee;
case 0x0c06e4f0u: goto P_0c06e4f0;
case 0x0c06e4f2u: goto P_0c06e4f2;
case 0x0c06e4f4u: goto P_0c06e4f4;
case 0x0c06e4f6u: goto P_0c06e4f6;
case 0x0c06e4f8u: goto P_0c06e4f8;
case 0x0c06e4fau: goto P_0c06e4fa;
case 0x0c06e4fcu: goto P_0c06e4fc;
case 0x0c06e4feu: goto P_0c06e4fe;
case 0x0c06e500u: goto P_0c06e500;
case 0x0c06e502u: goto P_0c06e502;
case 0x0c06e504u: goto P_0c06e504;
case 0x0c06e506u: goto P_0c06e506;
case 0x0c06e508u: goto P_0c06e508;
case 0x0c06e50au: goto P_0c06e50a;
case 0x0c06e50cu: goto P_0c06e50c;
case 0x0c06e50eu: goto P_0c06e50e;
case 0x0c06e510u: goto P_0c06e510;
case 0x0c06e512u: goto P_0c06e512;
case 0x0c06e514u: goto P_0c06e514;
case 0x0c06e516u: goto P_0c06e516;
case 0x0c06e518u: goto P_0c06e518;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06e31c: /* original 2fe6, guest PC 0x0c06e31c */
if(!s->budget--) { s->failed_pc=0x0c06e31cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e31e;
P_0c06e31e: /* original 2fd6, guest PC 0x0c06e31e */
if(!s->budget--) { s->failed_pc=0x0c06e31eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e320;
P_0c06e320: /* original 6d43, guest PC 0x0c06e320 */
if(!s->budget--) { s->failed_pc=0x0c06e320u; return 0; }
r[13]=r[4];
goto P_0c06e322;
P_0c06e322: /* original 2fc6, guest PC 0x0c06e322 */
if(!s->budget--) { s->failed_pc=0x0c06e322u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e324;
P_0c06e324: /* original 2fb6, guest PC 0x0c06e324 */
if(!s->budget--) { s->failed_pc=0x0c06e324u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e326;
P_0c06e326: /* original 2fa6, guest PC 0x0c06e326 */
if(!s->budget--) { s->failed_pc=0x0c06e326u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e328;
P_0c06e328: /* original 2f96, guest PC 0x0c06e328 */
if(!s->budget--) { s->failed_pc=0x0c06e328u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e32a;
P_0c06e32a: /* original e904, guest PC 0x0c06e32a */
if(!s->budget--) { s->failed_pc=0x0c06e32au; return 0; }
r[9]=0x00000004u;
goto P_0c06e32c;
P_0c06e32c: /* original 2f86, guest PC 0x0c06e32c */
if(!s->budget--) { s->failed_pc=0x0c06e32cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e32e;
P_0c06e32e: /* original fffb, guest PC 0x0c06e32e */
if(!s->budget--) { s->failed_pc=0x0c06e32eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e330;
P_0c06e330: /* original ffeb, guest PC 0x0c06e330 */
if(!s->budget--) { s->failed_pc=0x0c06e330u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e332;
P_0c06e332: /* original ffdb, guest PC 0x0c06e332 */
if(!s->budget--) { s->failed_pc=0x0c06e332u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e334;
P_0c06e334: /* original ffcb, guest PC 0x0c06e334 */
if(!s->budget--) { s->failed_pc=0x0c06e334u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06e336;
P_0c06e336: /* original 90af, guest PC 0x0c06e336 */
if(!s->budget--) { s->failed_pc=0x0c06e336u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e498u,2);
goto P_0c06e338;
P_0c06e338: /* original 4f22, guest PC 0x0c06e338 */
if(!s->budget--) { s->failed_pc=0x0c06e338u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e33a;
P_0c06e33a: /* original 0bdd, guest PC 0x0c06e33a */
if(!s->budget--) { s->failed_pc=0x0c06e33au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c06e33c;
P_0c06e33c: /* original c75a, guest PC 0x0c06e33c */
if(!s->budget--) { s->failed_pc=0x0c06e33cu; return 0; }
r[0]=code_base|0x0006e4a8u;
goto P_0c06e33e;
P_0c06e33e: /* original f308, guest PC 0x0c06e33e */
if(!s->budget--) { s->failed_pc=0x0c06e33eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e340;
P_0c06e340: /* original e014, guest PC 0x0c06e340 */
if(!s->budget--) { s->failed_pc=0x0c06e340u; return 0; }
r[0]=0x00000014u;
goto P_0c06e342;
P_0c06e342: /* original 7fdc, guest PC 0x0c06e342 */
if(!s->budget--) { s->failed_pc=0x0c06e342u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c06e344;
P_0c06e344: /* original d356, guest PC 0x0c06e344 */
if(!s->budget--) { s->failed_pc=0x0c06e344u; return 0; }
r[3]=read(ram,0x0c06e4a0u,4);
goto P_0c06e346;
P_0c06e346: /* original dc57, guest PC 0x0c06e346 */
if(!s->budget--) { s->failed_pc=0x0c06e346u; return 0; }
r[12]=read(ram,0x0c06e4a4u,4);
goto P_0c06e348;
P_0c06e348: /* original 6832, guest PC 0x0c06e348 */
if(!s->budget--) { s->failed_pc=0x0c06e348u; return 0; }
tmp=read(ram,r[3],4);
r[8]=tmp;
goto P_0c06e34a;
P_0c06e34a: /* original ff37, guest PC 0x0c06e34a */
if(!s->budget--) { s->failed_pc=0x0c06e34au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e34c;
P_0c06e34c: /* original e020, guest PC 0x0c06e34c */
if(!s->budget--) { s->failed_pc=0x0c06e34cu; return 0; }
r[0]=0x00000020u;
goto P_0c06e34e;
P_0c06e34e: /* original f38d, guest PC 0x0c06e34e */
if(!s->budget--) { s->failed_pc=0x0c06e34eu; return 0; }
fr[3]=0;
goto P_0c06e350;
P_0c06e350: /* original 7cfe, guest PC 0x0c06e350 */
if(!s->budget--) { s->failed_pc=0x0c06e350u; return 0; }
r[12]+=0xfffffffeu;
goto P_0c06e352;
P_0c06e352: /* original ff37, guest PC 0x0c06e352 */
if(!s->budget--) { s->failed_pc=0x0c06e352u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e354;
P_0c06e354: /* original 90a1, guest PC 0x0c06e354 */
if(!s->budget--) { s->failed_pc=0x0c06e354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e49au,2);
goto P_0c06e356;
P_0c06e356: /* original f3d6, guest PC 0x0c06e356 */
if(!s->budget--) { s->failed_pc=0x0c06e356u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06e358;
P_0c06e358: /* original e004, guest PC 0x0c06e358 */
if(!s->budget--) { s->failed_pc=0x0c06e358u; return 0; }
r[0]=0x00000004u;
goto P_0c06e35a;
P_0c06e35a: /* original ff37, guest PC 0x0c06e35a */
if(!s->budget--) { s->failed_pc=0x0c06e35au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e35c;
P_0c06e35c: /* original 909e, guest PC 0x0c06e35c */
if(!s->budget--) { s->failed_pc=0x0c06e35cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e49cu,2);
goto P_0c06e35e;
P_0c06e35e: /* original f3d6, guest PC 0x0c06e35e */
if(!s->budget--) { s->failed_pc=0x0c06e35eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c06e360;
P_0c06e360: /* original f34d, guest PC 0x0c06e360 */
if(!s->budget--) { s->failed_pc=0x0c06e360u; return 0; }
fr[3]^=0x80000000u;
goto P_0c06e362;
P_0c06e362: /* original a0c8, guest PC 0x0c06e362 */
if(!s->budget--) { s->failed_pc=0x0c06e362u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e4f6;
P_0c06e364: /* original ff3a, guest PC 0x0c06e364 */
if(!s->budget--) { s->failed_pc=0x0c06e364u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e366;
P_0c06e366: /* original e010, guest PC 0x0c06e366 */
if(!s->budget--) { s->failed_pc=0x0c06e366u; return 0; }
r[0]=0x00000010u;
goto P_0c06e368;
P_0c06e368: /* original 63f3, guest PC 0x0c06e368 */
if(!s->budget--) { s->failed_pc=0x0c06e368u; return 0; }
r[3]=r[15];
goto P_0c06e36a;
P_0c06e36a: /* original 64bb, guest PC 0x0c06e36a */
if(!s->budget--) { s->failed_pc=0x0c06e36au; return 0; }
r[4]=0u-r[11];
goto P_0c06e36c;
P_0c06e36c: /* original 62f3, guest PC 0x0c06e36c */
if(!s->budget--) { s->failed_pc=0x0c06e36cu; return 0; }
r[2]=r[15];
goto P_0c06e36e;
P_0c06e36e: /* original 445a, guest PC 0x0c06e36e */
if(!s->budget--) { s->failed_pc=0x0c06e36eu; return 0; }
r[53]=r[4];
goto P_0c06e370;
P_0c06e370: /* original 7308, guest PC 0x0c06e370 */
if(!s->budget--) { s->failed_pc=0x0c06e370u; return 0; }
r[3]+=0x00000008u;
goto P_0c06e372;
P_0c06e372: /* original 7210, guest PC 0x0c06e372 */
if(!s->budget--) { s->failed_pc=0x0c06e372u; return 0; }
r[2]+=0x00000010u;
goto P_0c06e374;
P_0c06e374: /* original f0fd, guest PC 0x0c06e374 */
if(!s->budget--) { s->failed_pc=0x0c06e374u; return 0; }
vf3_fpu_fsca(r[53],fr+0);
goto P_0c06e376;
P_0c06e376: /* original f20a, guest PC 0x0c06e376 */
if(!s->budget--) { s->failed_pc=0x0c06e376u; return 0; }
vf3_matrix_store(s,ram,0,r[2]);
goto P_0c06e378;
P_0c06e378: /* original f31a, guest PC 0x0c06e378 */
if(!s->budget--) { s->failed_pc=0x0c06e378u; return 0; }
vf3_matrix_store(s,ram,1,r[3]);
goto P_0c06e37a;
P_0c06e37a: /* original fbf6, guest PC 0x0c06e37a */
if(!s->budget--) { s->failed_pc=0x0c06e37au; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c06e37c;
P_0c06e37c: /* original e008, guest PC 0x0c06e37c */
if(!s->budget--) { s->failed_pc=0x0c06e37cu; return 0; }
r[0]=0x00000008u;
goto P_0c06e37e;
P_0c06e37e: /* original faf6, guest PC 0x0c06e37e */
if(!s->budget--) { s->failed_pc=0x0c06e37eu; return 0; }
vf3_matrix_load(s,ram,10,r[15]+r[0]);
goto P_0c06e380;
P_0c06e380: /* original e014, guest PC 0x0c06e380 */
if(!s->budget--) { s->failed_pc=0x0c06e380u; return 0; }
r[0]=0x00000014u;
goto P_0c06e382;
P_0c06e382: /* original f3f6, guest PC 0x0c06e382 */
if(!s->budget--) { s->failed_pc=0x0c06e382u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e384;
P_0c06e384: /* original e004, guest PC 0x0c06e384 */
if(!s->budget--) { s->failed_pc=0x0c06e384u; return 0; }
r[0]=0x00000004u;
goto P_0c06e386;
P_0c06e386: /* original f7f6, guest PC 0x0c06e386 */
if(!s->budget--) { s->failed_pc=0x0c06e386u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c06e388;
P_0c06e388: /* original fb32, guest PC 0x0c06e388 */
if(!s->budget--) { s->failed_pc=0x0c06e388u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'*');
goto P_0c06e38a;
P_0c06e38a: /* original f4f8, guest PC 0x0c06e38a */
if(!s->budget--) { s->failed_pc=0x0c06e38au; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c06e38c;
P_0c06e38c: /* original fa32, guest PC 0x0c06e38c */
if(!s->budget--) { s->failed_pc=0x0c06e38cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'*');
goto P_0c06e38e;
P_0c06e38e: /* original f37c, guest PC 0x0c06e38e */
if(!s->budget--) { s->failed_pc=0x0c06e38eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e390;
P_0c06e390: /* original f84c, guest PC 0x0c06e390 */
if(!s->budget--) { s->failed_pc=0x0c06e390u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c06e392;
P_0c06e392: /* original fb70, guest PC 0x0c06e392 */
if(!s->budget--) { s->failed_pc=0x0c06e392u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'+');
goto P_0c06e394;
P_0c06e394: /* original fa40, guest PC 0x0c06e394 */
if(!s->budget--) { s->failed_pc=0x0c06e394u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'+');
goto P_0c06e396;
P_0c06e396: /* original f5bc, guest PC 0x0c06e396 */
if(!s->budget--) { s->failed_pc=0x0c06e396u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c06e398;
P_0c06e398: /* original f542, guest PC 0x0c06e398 */
if(!s->budget--) { s->failed_pc=0x0c06e398u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c06e39a;
P_0c06e39a: /* original f9bc, guest PC 0x0c06e39a */
if(!s->budget--) { s->failed_pc=0x0c06e39au; return 0; }
vf3_matrix_move(s,9,11);
goto P_0c06e39c;
P_0c06e39c: /* original f3a2, guest PC 0x0c06e39c */
if(!s->budget--) { s->failed_pc=0x0c06e39cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c06e39e;
P_0c06e39e: /* original f971, guest PC 0x0c06e39e */
if(!s->budget--) { s->failed_pc=0x0c06e39eu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'-');
goto P_0c06e3a0;
P_0c06e3a0: /* original f8a1, guest PC 0x0c06e3a0 */
if(!s->budget--) { s->failed_pc=0x0c06e3a0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'-');
goto P_0c06e3a2;
P_0c06e3a2: /* original f25c, guest PC 0x0c06e3a2 */
if(!s->budget--) { s->failed_pc=0x0c06e3a2u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c06e3a4;
P_0c06e3a4: /* original f53c, guest PC 0x0c06e3a4 */
if(!s->budget--) { s->failed_pc=0x0c06e3a4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c06e3a6;
P_0c06e3a6: /* original 907a, guest PC 0x0c06e3a6 */
if(!s->budget--) { s->failed_pc=0x0c06e3a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e49eu,2);
goto P_0c06e3a8;
P_0c06e3a8: /* original f521, guest PC 0x0c06e3a8 */
if(!s->budget--) { s->failed_pc=0x0c06e3a8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c06e3aa;
P_0c06e3aa: /* original 048e, guest PC 0x0c06e3aa */
if(!s->budget--) { s->failed_pc=0x0c06e3aau; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c06e3ac;
P_0c06e3ac: /* original 6546, guest PC 0x0c06e3ac */
if(!s->budget--) { s->failed_pc=0x0c06e3acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c06e3ae;
P_0c06e3ae: /* original ff49, guest PC 0x0c06e3ae */
if(!s->budget--) { s->failed_pc=0x0c06e3aeu; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e3b0;
P_0c06e3b0: /* original a08c, guest PC 0x0c06e3b0 */
if(!s->budget--) { s->failed_pc=0x0c06e3b0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e4cc;
P_0c06e3b2: /* original f649, guest PC 0x0c06e3b2 */
if(!s->budget--) { s->failed_pc=0x0c06e3b2u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e3b4;
P_0c06e3b4: /* original e00c, guest PC 0x0c06e3b4 */
if(!s->budget--) { s->failed_pc=0x0c06e3b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e3b6;
P_0c06e3b6: /* original fcfc, guest PC 0x0c06e3b6 */
if(!s->budget--) { s->failed_pc=0x0c06e3b6u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c06e3b8;
P_0c06e3b8: /* original ff67, guest PC 0x0c06e3b8 */
if(!s->budget--) { s->failed_pc=0x0c06e3b8u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06e3ba;
P_0c06e3ba: /* original e00c, guest PC 0x0c06e3ba */
if(!s->budget--) { s->failed_pc=0x0c06e3bau; return 0; }
r[0]=0x0000000cu;
goto P_0c06e3bc;
P_0c06e3bc: /* original fef6, guest PC 0x0c06e3bc */
if(!s->budget--) { s->failed_pc=0x0c06e3bcu; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c06e3be;
P_0c06e3be: /* original e00c, guest PC 0x0c06e3be */
if(!s->budget--) { s->failed_pc=0x0c06e3beu; return 0; }
r[0]=0x0000000cu;
goto P_0c06e3c0;
P_0c06e3c0: /* original ff49, guest PC 0x0c06e3c0 */
if(!s->budget--) { s->failed_pc=0x0c06e3c0u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e3c2;
P_0c06e3c2: /* original f3f6, guest PC 0x0c06e3c2 */
if(!s->budget--) { s->failed_pc=0x0c06e3c2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e3c4;
P_0c06e3c4: /* original e004, guest PC 0x0c06e3c4 */
if(!s->budget--) { s->failed_pc=0x0c06e3c4u; return 0; }
r[0]=0x00000004u;
goto P_0c06e3c6;
P_0c06e3c6: /* original f649, guest PC 0x0c06e3c6 */
if(!s->budget--) { s->failed_pc=0x0c06e3c6u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e3c8;
P_0c06e3c8: /* original f4fc, guest PC 0x0c06e3c8 */
if(!s->budget--) { s->failed_pc=0x0c06e3c8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e3ca;
P_0c06e3ca: /* original f432, guest PC 0x0c06e3ca */
if(!s->budget--) { s->failed_pc=0x0c06e3cau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06e3cc;
P_0c06e3cc: /* original f2cc, guest PC 0x0c06e3cc */
if(!s->budget--) { s->failed_pc=0x0c06e3ccu; return 0; }
vf3_matrix_move(s,2,12);
goto P_0c06e3ce;
P_0c06e3ce: /* original f262, guest PC 0x0c06e3ce */
if(!s->budget--) { s->failed_pc=0x0c06e3ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c06e3d0;
P_0c06e3d0: /* original fe61, guest PC 0x0c06e3d0 */
if(!s->budget--) { s->failed_pc=0x0c06e3d0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'-');
goto P_0c06e3d2;
P_0c06e3d2: /* original f7fc, guest PC 0x0c06e3d2 */
if(!s->budget--) { s->failed_pc=0x0c06e3d2u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e3d4;
P_0c06e3d4: /* original f7c1, guest PC 0x0c06e3d4 */
if(!s->budget--) { s->failed_pc=0x0c06e3d4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'-');
goto P_0c06e3d6;
P_0c06e3d6: /* original f14c, guest PC 0x0c06e3d6 */
if(!s->budget--) { s->failed_pc=0x0c06e3d6u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c06e3d8;
P_0c06e3d8: /* original f42c, guest PC 0x0c06e3d8 */
if(!s->budget--) { s->failed_pc=0x0c06e3d8u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06e3da;
P_0c06e3da: /* original f411, guest PC 0x0c06e3da */
if(!s->budget--) { s->failed_pc=0x0c06e3dau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'-');
goto P_0c06e3dc;
P_0c06e3dc: /* original f2f6, guest PC 0x0c06e3dc */
if(!s->budget--) { s->failed_pc=0x0c06e3dcu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e3de;
P_0c06e3de: /* original e01c, guest PC 0x0c06e3de */
if(!s->budget--) { s->failed_pc=0x0c06e3deu; return 0; }
r[0]=0x0000001cu;
goto P_0c06e3e0;
P_0c06e3e0: /* original f0ec, guest PC 0x0c06e3e0 */
if(!s->budget--) { s->failed_pc=0x0c06e3e0u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e3e2;
P_0c06e3e2: /* original f1f8, guest PC 0x0c06e3e2 */
if(!s->budget--) { s->failed_pc=0x0c06e3e2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c06e3e4;
P_0c06e3e4: /* original fd4c, guest PC 0x0c06e3e4 */
if(!s->budget--) { s->failed_pc=0x0c06e3e4u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e3e6;
P_0c06e3e6: /* original fd2e, guest PC 0x0c06e3e6 */
if(!s->budget--) { s->failed_pc=0x0c06e3e6u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[2],fr[13],r[18]);
goto P_0c06e3e8;
P_0c06e3e8: /* original f07c, guest PC 0x0c06e3e8 */
if(!s->budget--) { s->failed_pc=0x0c06e3e8u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e3ea;
P_0c06e3ea: /* original f2dc, guest PC 0x0c06e3ea */
if(!s->budget--) { s->failed_pc=0x0c06e3eau; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c06e3ec;
P_0c06e3ec: /* original f21e, guest PC 0x0c06e3ec */
if(!s->budget--) { s->failed_pc=0x0c06e3ecu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[1],fr[2],r[18]);
goto P_0c06e3ee;
P_0c06e3ee: /* original fd2c, guest PC 0x0c06e3ee */
if(!s->budget--) { s->failed_pc=0x0c06e3eeu; return 0; }
vf3_matrix_move(s,13,2);
goto P_0c06e3f0;
P_0c06e3f0: /* original ffd7, guest PC 0x0c06e3f0 */
if(!s->budget--) { s->failed_pc=0x0c06e3f0u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c06e3f2;
P_0c06e3f2: /* original fd4c, guest PC 0x0c06e3f2 */
if(!s->budget--) { s->failed_pc=0x0c06e3f2u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e3f4;
P_0c06e3f4: /* original f0ec, guest PC 0x0c06e3f4 */
if(!s->budget--) { s->failed_pc=0x0c06e3f4u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e3f6;
P_0c06e3f6: /* original fdbe, guest PC 0x0c06e3f6 */
if(!s->budget--) { s->failed_pc=0x0c06e3f6u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[11],fr[13],r[18]);
goto P_0c06e3f8;
P_0c06e3f8: /* original f07c, guest PC 0x0c06e3f8 */
if(!s->budget--) { s->failed_pc=0x0c06e3f8u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e3fa;
P_0c06e3fa: /* original e01c, guest PC 0x0c06e3fa */
if(!s->budget--) { s->failed_pc=0x0c06e3fau; return 0; }
r[0]=0x0000001cu;
goto P_0c06e3fc;
P_0c06e3fc: /* original f1f6, guest PC 0x0c06e3fc */
if(!s->budget--) { s->failed_pc=0x0c06e3fcu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c06e3fe;
P_0c06e3fe: /* original e01c, guest PC 0x0c06e3fe */
if(!s->budget--) { s->failed_pc=0x0c06e3feu; return 0; }
r[0]=0x0000001cu;
goto P_0c06e400;
P_0c06e400: /* original f2dc, guest PC 0x0c06e400 */
if(!s->budget--) { s->failed_pc=0x0c06e400u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c06e402;
P_0c06e402: /* original f2ae, guest PC 0x0c06e402 */
if(!s->budget--) { s->failed_pc=0x0c06e402u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[10],fr[2],r[18]);
goto P_0c06e404;
P_0c06e404: /* original fd2c, guest PC 0x0c06e404 */
if(!s->budget--) { s->failed_pc=0x0c06e404u; return 0; }
vf3_matrix_move(s,13,2);
goto P_0c06e406;
P_0c06e406: /* original f1d2, guest PC 0x0c06e406 */
if(!s->budget--) { s->failed_pc=0x0c06e406u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[13],r[18],'*');
goto P_0c06e408;
P_0c06e408: /* original f28d, guest PC 0x0c06e408 */
if(!s->budget--) { s->failed_pc=0x0c06e408u; return 0; }
fr[2]=0;
goto P_0c06e40a;
P_0c06e40a: /* original f125, guest PC 0x0c06e40a */
if(!s->budget--) { s->failed_pc=0x0c06e40au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[2]))!=0);
goto P_0c06e40c;
P_0c06e40c: /* original 8d5d, guest PC 0x0c06e40c */
if(!s->budget--) { s->failed_pc=0x0c06e40cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,1,r[15]+r[0]);
if(cond) { goto P_0c06e4ca; }
goto P_0c06e410;
P_0c06e40e: /* original ff17, guest PC 0x0c06e40e */
if(!s->budget--) { s->failed_pc=0x0c06e40eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c06e410;
P_0c06e410: /* original f08c, guest PC 0x0c06e410 */
if(!s->budget--) { s->failed_pc=0x0c06e410u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c06e412;
P_0c06e412: /* original e00c, guest PC 0x0c06e412 */
if(!s->budget--) { s->failed_pc=0x0c06e412u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e414;
P_0c06e414: /* original fd5c, guest PC 0x0c06e414 */
if(!s->budget--) { s->failed_pc=0x0c06e414u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c06e416;
P_0c06e416: /* original fdce, guest PC 0x0c06e416 */
if(!s->budget--) { s->failed_pc=0x0c06e416u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c06e418;
P_0c06e418: /* original f2f6, guest PC 0x0c06e418 */
if(!s->budget--) { s->failed_pc=0x0c06e418u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e41a;
P_0c06e41a: /* original e018, guest PC 0x0c06e41a */
if(!s->budget--) { s->failed_pc=0x0c06e41au; return 0; }
r[0]=0x00000018u;
goto P_0c06e41c;
P_0c06e41c: /* original f09c, guest PC 0x0c06e41c */
if(!s->budget--) { s->failed_pc=0x0c06e41cu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06e41e;
P_0c06e41e: /* original f3dc, guest PC 0x0c06e41e */
if(!s->budget--) { s->failed_pc=0x0c06e41eu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c06e420;
P_0c06e420: /* original f32e, guest PC 0x0c06e420 */
if(!s->budget--) { s->failed_pc=0x0c06e420u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c06e422;
P_0c06e422: /* original fd3c, guest PC 0x0c06e422 */
if(!s->budget--) { s->failed_pc=0x0c06e422u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c06e424;
P_0c06e424: /* original ffd7, guest PC 0x0c06e424 */
if(!s->budget--) { s->failed_pc=0x0c06e424u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c06e426;
P_0c06e426: /* original e018, guest PC 0x0c06e426 */
if(!s->budget--) { s->failed_pc=0x0c06e426u; return 0; }
r[0]=0x00000018u;
goto P_0c06e428;
P_0c06e428: /* original f08c, guest PC 0x0c06e428 */
if(!s->budget--) { s->failed_pc=0x0c06e428u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c06e42a;
P_0c06e42a: /* original fd5c, guest PC 0x0c06e42a */
if(!s->budget--) { s->failed_pc=0x0c06e42au; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c06e42c;
P_0c06e42c: /* original fdfe, guest PC 0x0c06e42c */
if(!s->budget--) { s->failed_pc=0x0c06e42cu; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[15],fr[13],r[18]);
goto P_0c06e42e;
P_0c06e42e: /* original f09c, guest PC 0x0c06e42e */
if(!s->budget--) { s->failed_pc=0x0c06e42eu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06e430;
P_0c06e430: /* original f2f6, guest PC 0x0c06e430 */
if(!s->budget--) { s->failed_pc=0x0c06e430u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e432;
P_0c06e432: /* original e018, guest PC 0x0c06e432 */
if(!s->budget--) { s->failed_pc=0x0c06e432u; return 0; }
r[0]=0x00000018u;
goto P_0c06e434;
P_0c06e434: /* original f3dc, guest PC 0x0c06e434 */
if(!s->budget--) { s->failed_pc=0x0c06e434u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c06e436;
P_0c06e436: /* original f36e, guest PC 0x0c06e436 */
if(!s->budget--) { s->failed_pc=0x0c06e436u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c06e438;
P_0c06e438: /* original fd3c, guest PC 0x0c06e438 */
if(!s->budget--) { s->failed_pc=0x0c06e438u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c06e43a;
P_0c06e43a: /* original f2d2, guest PC 0x0c06e43a */
if(!s->budget--) { s->failed_pc=0x0c06e43au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c06e43c;
P_0c06e43c: /* original f38d, guest PC 0x0c06e43c */
if(!s->budget--) { s->failed_pc=0x0c06e43cu; return 0; }
fr[3]=0;
goto P_0c06e43e;
P_0c06e43e: /* original f235, guest PC 0x0c06e43e */
if(!s->budget--) { s->failed_pc=0x0c06e43eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06e440;
P_0c06e440: /* original 8d43, guest PC 0x0c06e440 */
if(!s->budget--) { s->failed_pc=0x0c06e440u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[15]+r[0]);
if(cond) { goto P_0c06e4ca; }
goto P_0c06e444;
P_0c06e442: /* original ff27, guest PC 0x0c06e442 */
if(!s->budget--) { s->failed_pc=0x0c06e442u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e444;
P_0c06e444: /* original fa5c, guest PC 0x0c06e444 */
if(!s->budget--) { s->failed_pc=0x0c06e444u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e446;
P_0c06e446: /* original fa72, guest PC 0x0c06e446 */
if(!s->budget--) { s->failed_pc=0x0c06e446u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c06e448;
P_0c06e448: /* original fb9c, guest PC 0x0c06e448 */
if(!s->budget--) { s->failed_pc=0x0c06e448u; return 0; }
vf3_matrix_move(s,11,9);
goto P_0c06e44a;
P_0c06e44a: /* original fbe2, guest PC 0x0c06e44a */
if(!s->budget--) { s->failed_pc=0x0c06e44au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[14],r[18],'*');
goto P_0c06e44c;
P_0c06e44c: /* original f39c, guest PC 0x0c06e44c */
if(!s->budget--) { s->failed_pc=0x0c06e44cu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c06e44e;
P_0c06e44e: /* original f342, guest PC 0x0c06e44e */
if(!s->budget--) { s->failed_pc=0x0c06e44eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06e450;
P_0c06e450: /* original f98c, guest PC 0x0c06e450 */
if(!s->budget--) { s->failed_pc=0x0c06e450u; return 0; }
vf3_matrix_move(s,9,8);
goto P_0c06e452;
P_0c06e452: /* original f972, guest PC 0x0c06e452 */
if(!s->budget--) { s->failed_pc=0x0c06e452u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'*');
goto P_0c06e454;
P_0c06e454: /* original f2ac, guest PC 0x0c06e454 */
if(!s->budget--) { s->failed_pc=0x0c06e454u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c06e456;
P_0c06e456: /* original f5e2, guest PC 0x0c06e456 */
if(!s->budget--) { s->failed_pc=0x0c06e456u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'*');
goto P_0c06e458;
P_0c06e458: /* original f842, guest PC 0x0c06e458 */
if(!s->budget--) { s->failed_pc=0x0c06e458u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c06e45a;
P_0c06e45a: /* original f4bc, guest PC 0x0c06e45a */
if(!s->budget--) { s->failed_pc=0x0c06e45au; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c06e45c;
P_0c06e45c: /* original fa3c, guest PC 0x0c06e45c */
if(!s->budget--) { s->failed_pc=0x0c06e45cu; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c06e45e;
P_0c06e45e: /* original fa21, guest PC 0x0c06e45e */
if(!s->budget--) { s->failed_pc=0x0c06e45eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'-');
goto P_0c06e460;
P_0c06e460: /* original f69c, guest PC 0x0c06e460 */
if(!s->budget--) { s->failed_pc=0x0c06e460u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c06e462;
P_0c06e462: /* original e004, guest PC 0x0c06e462 */
if(!s->budget--) { s->failed_pc=0x0c06e462u; return 0; }
r[0]=0x00000004u;
goto P_0c06e464;
P_0c06e464: /* original f3bc, guest PC 0x0c06e464 */
if(!s->budget--) { s->failed_pc=0x0c06e464u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c06e466;
P_0c06e466: /* original f631, guest PC 0x0c06e466 */
if(!s->budget--) { s->failed_pc=0x0c06e466u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c06e468;
P_0c06e468: /* original f2f8, guest PC 0x0c06e468 */
if(!s->budget--) { s->failed_pc=0x0c06e468u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c06e46a;
P_0c06e46a: /* original f36c, guest PC 0x0c06e46a */
if(!s->budget--) { s->failed_pc=0x0c06e46au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c06e46c;
P_0c06e46c: /* original f6ac, guest PC 0x0c06e46c */
if(!s->budget--) { s->failed_pc=0x0c06e46cu; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c06e46e;
P_0c06e46e: /* original f633, guest PC 0x0c06e46e */
if(!s->budget--) { s->failed_pc=0x0c06e46eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c06e470;
P_0c06e470: /* original f35c, guest PC 0x0c06e470 */
if(!s->budget--) { s->failed_pc=0x0c06e470u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06e472;
P_0c06e472: /* original f58c, guest PC 0x0c06e472 */
if(!s->budget--) { s->failed_pc=0x0c06e472u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c06e474;
P_0c06e474: /* original f531, guest PC 0x0c06e474 */
if(!s->budget--) { s->failed_pc=0x0c06e474u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06e476;
P_0c06e476: /* original f39c, guest PC 0x0c06e476 */
if(!s->budget--) { s->failed_pc=0x0c06e476u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c06e478;
P_0c06e478: /* original f431, guest PC 0x0c06e478 */
if(!s->budget--) { s->failed_pc=0x0c06e478u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e47a;
P_0c06e47a: /* original f3f6, guest PC 0x0c06e47a */
if(!s->budget--) { s->failed_pc=0x0c06e47au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e47c;
P_0c06e47c: /* original f543, guest PC 0x0c06e47c */
if(!s->budget--) { s->failed_pc=0x0c06e47cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c06e47e;
P_0c06e47e: /* original f46c, guest PC 0x0c06e47e */
if(!s->budget--) { s->failed_pc=0x0c06e47eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c06e480;
P_0c06e480: /* original f431, guest PC 0x0c06e480 */
if(!s->budget--) { s->failed_pc=0x0c06e480u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e482;
P_0c06e482: /* original f442, guest PC 0x0c06e482 */
if(!s->budget--) { s->failed_pc=0x0c06e482u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e484;
P_0c06e484: /* original f521, guest PC 0x0c06e484 */
if(!s->budget--) { s->failed_pc=0x0c06e484u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c06e486;
P_0c06e486: /* original c709, guest PC 0x0c06e486 */
if(!s->budget--) { s->failed_pc=0x0c06e486u; return 0; }
r[0]=code_base|0x0006e4acu;
goto P_0c06e488;
P_0c06e488: /* original f05c, guest PC 0x0c06e488 */
if(!s->budget--) { s->failed_pc=0x0c06e488u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c06e48a;
P_0c06e48a: /* original f45e, guest PC 0x0c06e48a */
if(!s->budget--) { s->failed_pc=0x0c06e48au; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c06e48c;
P_0c06e48c: /* original fd4c, guest PC 0x0c06e48c */
if(!s->budget--) { s->failed_pc=0x0c06e48cu; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e48e;
P_0c06e48e: /* original f408, guest PC 0x0c06e48e */
if(!s->budget--) { s->failed_pc=0x0c06e48eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06e490;
P_0c06e490: /* original f4d5, guest PC 0x0c06e490 */
if(!s->budget--) { s->failed_pc=0x0c06e490u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[13]))!=0);
goto P_0c06e492;
P_0c06e492: /* original 8b0d, guest PC 0x0c06e492 */
if(!s->budget--) { s->failed_pc=0x0c06e492u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e4b0; }
goto P_0c06e494;
P_0c06e494: /* original a00e, guest PC 0x0c06e494 */
if(!s->budget--) { s->failed_pc=0x0c06e494u; return 0; }
fr[1]=0;
goto P_0c06e4b4;
P_0c06e496: /* original f18d, guest PC 0x0c06e496 */
if(!s->budget--) { s->failed_pc=0x0c06e496u; return 0; }
fr[1]=0;
if(!vf3_matrix_family(0x0c06e498u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e498u; return 0; } return 1;
P_0c06e4b0: /* original f1dc, guest PC 0x0c06e4b0 */
if(!s->budget--) { s->failed_pc=0x0c06e4b0u; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c06e4b2;
P_0c06e4b2: /* original f17d, guest PC 0x0c06e4b2 */
if(!s->budget--) { s->failed_pc=0x0c06e4b2u; return 0; }
if(!vf3_fpu_fsrra(fr[1],r[18],&fr[1])) goto unsupported;
goto P_0c06e4b4;
P_0c06e4b4: /* original fd12, guest PC 0x0c06e4b4 */
if(!s->budget--) { s->failed_pc=0x0c06e4b4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[1],r[18],'*');
goto P_0c06e4b6;
P_0c06e4b6: /* original e008, guest PC 0x0c06e4b6 */
if(!s->budget--) { s->failed_pc=0x0c06e4b6u; return 0; }
r[0]=0x00000008u;
goto P_0c06e4b8;
P_0c06e4b8: /* original ff17, guest PC 0x0c06e4b8 */
if(!s->budget--) { s->failed_pc=0x0c06e4b8u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c06e4ba;
P_0c06e4ba: /* original da56, guest PC 0x0c06e4ba */
if(!s->budget--) { s->failed_pc=0x0c06e4bau; return 0; }
r[10]=read(ram,0x0c06e614u,4);
goto P_0c06e4bc;
P_0c06e4bc: /* original f4cc, guest PC 0x0c06e4bc */
if(!s->budget--) { s->failed_pc=0x0c06e4bcu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c06e4be;
P_0c06e4be: /* original f5ec, guest PC 0x0c06e4be */
if(!s->budget--) { s->failed_pc=0x0c06e4beu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c06e4c0;
P_0c06e4c0: /* original 4a0b, guest PC 0x0c06e4c0 */
if(!s->budget--) { s->failed_pc=0x0c06e4c0u; return 0; }
target=r[10];
r[16]=code_base|0x0c06e4c4u;
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06e4c4u) { target=s->pc; goto dispatch; }
goto P_0c06e4c4;
P_0c06e4c2: /* original f4f1, guest PC 0x0c06e4c2 */
if(!s->budget--) { s->failed_pc=0x0c06e4c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c06e4c4;
P_0c06e4c4: /* original 640f, guest PC 0x0c06e4c4 */
if(!s->budget--) { s->failed_pc=0x0c06e4c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06e4c6;
P_0c06e4c6: /* original a00b, guest PC 0x0c06e4c6 */
if(!s->budget--) { s->failed_pc=0x0c06e4c6u; return 0; }
r[4]+=r[14];
goto P_0c06e4e0;
P_0c06e4c8: /* original 34ec, guest PC 0x0c06e4c8 */
if(!s->budget--) { s->failed_pc=0x0c06e4c8u; return 0; }
r[4]+=r[14];
goto P_0c06e4ca;
P_0c06e4ca: /* original 75ff, guest PC 0x0c06e4ca */
if(!s->budget--) { s->failed_pc=0x0c06e4cau; return 0; }
r[5]+=0xffffffffu;
goto P_0c06e4cc;
P_0c06e4cc: /* original e200, guest PC 0x0c06e4cc */
if(!s->budget--) { s->failed_pc=0x0c06e4ccu; return 0; }
r[2]=0x00000000u;
goto P_0c06e4ce;
P_0c06e4ce: /* original 9e9d, guest PC 0x0c06e4ce */
if(!s->budget--) { s->failed_pc=0x0c06e4ceu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e60cu,2);
goto P_0c06e4d0;
P_0c06e4d0: /* original 3526, guest PC 0x0c06e4d0 */
if(!s->budget--) { s->failed_pc=0x0c06e4d0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[2])!=0);
goto P_0c06e4d2;
P_0c06e4d2: /* original 8b01, guest PC 0x0c06e4d2 */
if(!s->budget--) { s->failed_pc=0x0c06e4d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e4d8; }
goto P_0c06e4d4;
P_0c06e4d4: /* original af6e, guest PC 0x0c06e4d4 */
if(!s->budget--) { s->failed_pc=0x0c06e4d4u; return 0; }
goto P_0c06e3b4;
P_0c06e4d6: /* original 0009, guest PC 0x0c06e4d6 */
if(!s->budget--) { s->failed_pc=0x0c06e4d6u; return 0; }
goto P_0c06e4d8;
P_0c06e4d8: /* original e020, guest PC 0x0c06e4d8 */
if(!s->budget--) { s->failed_pc=0x0c06e4d8u; return 0; }
r[0]=0x00000020u;
goto P_0c06e4da;
P_0c06e4da: /* original e500, guest PC 0x0c06e4da */
if(!s->budget--) { s->failed_pc=0x0c06e4dau; return 0; }
r[5]=0x00000000u;
goto P_0c06e4dc;
P_0c06e4dc: /* original fdf6, guest PC 0x0c06e4dc */
if(!s->budget--) { s->failed_pc=0x0c06e4dcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c06e4de;
P_0c06e4de: /* original 6453, guest PC 0x0c06e4de */
if(!s->budget--) { s->failed_pc=0x0c06e4deu; return 0; }
r[4]=r[5];
goto P_0c06e4e0;
P_0c06e4e0: /* original 7c02, guest PC 0x0c06e4e0 */
if(!s->budget--) { s->failed_pc=0x0c06e4e0u; return 0; }
r[12]+=0x00000002u;
goto P_0c06e4e2;
P_0c06e4e2: /* original 65c5, guest PC 0x0c06e4e2 */
if(!s->budget--) { s->failed_pc=0x0c06e4e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]+=2;
r[5]=tmp;
goto P_0c06e4e4;
P_0c06e4e4: /* original 79ff, guest PC 0x0c06e4e4 */
if(!s->budget--) { s->failed_pc=0x0c06e4e4u; return 0; }
r[9]+=0xffffffffu;
goto P_0c06e4e6;
P_0c06e4e6: /* original 3bec, guest PC 0x0c06e4e6 */
if(!s->budget--) { s->failed_pc=0x0c06e4e6u; return 0; }
r[11]+=r[14];
goto P_0c06e4e8;
P_0c06e4e8: /* original 655d, guest PC 0x0c06e4e8 */
if(!s->budget--) { s->failed_pc=0x0c06e4e8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c06e4ea;
P_0c06e4ea: /* original 35dc, guest PC 0x0c06e4ea */
if(!s->budget--) { s->failed_pc=0x0c06e4eau; return 0; }
r[5]+=r[13];
goto P_0c06e4ec;
P_0c06e4ec: /* original f5da, guest PC 0x0c06e4ec */
if(!s->budget--) { s->failed_pc=0x0c06e4ecu; return 0; }
vf3_matrix_store(s,ram,13,r[5]);
goto P_0c06e4ee;
P_0c06e4ee: /* original 65c1, guest PC 0x0c06e4ee */
if(!s->budget--) { s->failed_pc=0x0c06e4eeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[5]=tmp;
goto P_0c06e4f0;
P_0c06e4f0: /* original 655d, guest PC 0x0c06e4f0 */
if(!s->budget--) { s->failed_pc=0x0c06e4f0u; return 0; }
r[5]=r[5]&65535u;
goto P_0c06e4f2;
P_0c06e4f2: /* original 35dc, guest PC 0x0c06e4f2 */
if(!s->budget--) { s->failed_pc=0x0c06e4f2u; return 0; }
r[5]+=r[13];
goto P_0c06e4f4;
P_0c06e4f4: /* original 2541, guest PC 0x0c06e4f4 */
if(!s->budget--) { s->failed_pc=0x0c06e4f4u; return 0; }
write(ram,r[5],r[4],2);
goto P_0c06e4f6;
P_0c06e4f6: /* original 4915, guest PC 0x0c06e4f6 */
if(!s->budget--) { s->failed_pc=0x0c06e4f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>0)!=0);
goto P_0c06e4f8;
P_0c06e4f8: /* original 8b01, guest PC 0x0c06e4f8 */
if(!s->budget--) { s->failed_pc=0x0c06e4f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e4fe; }
goto P_0c06e4fa;
P_0c06e4fa: /* original af34, guest PC 0x0c06e4fa */
if(!s->budget--) { s->failed_pc=0x0c06e4fau; return 0; }
goto P_0c06e366;
P_0c06e4fc: /* original 0009, guest PC 0x0c06e4fc */
if(!s->budget--) { s->failed_pc=0x0c06e4fcu; return 0; }
goto P_0c06e4fe;
P_0c06e4fe: /* original 7f24, guest PC 0x0c06e4fe */
if(!s->budget--) { s->failed_pc=0x0c06e4feu; return 0; }
r[15]+=0x00000024u;
goto P_0c06e500;
P_0c06e500: /* original 4f26, guest PC 0x0c06e500 */
if(!s->budget--) { s->failed_pc=0x0c06e500u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06e502;
P_0c06e502: /* original fcf9, guest PC 0x0c06e502 */
if(!s->budget--) { s->failed_pc=0x0c06e502u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e504;
P_0c06e504: /* original fdf9, guest PC 0x0c06e504 */
if(!s->budget--) { s->failed_pc=0x0c06e504u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e506;
P_0c06e506: /* original fef9, guest PC 0x0c06e506 */
if(!s->budget--) { s->failed_pc=0x0c06e506u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e508;
P_0c06e508: /* original fff9, guest PC 0x0c06e508 */
if(!s->budget--) { s->failed_pc=0x0c06e508u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e50a;
P_0c06e50a: /* original 68f6, guest PC 0x0c06e50a */
if(!s->budget--) { s->failed_pc=0x0c06e50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06e50c;
P_0c06e50c: /* original 69f6, guest PC 0x0c06e50c */
if(!s->budget--) { s->failed_pc=0x0c06e50cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06e50e;
P_0c06e50e: /* original 6af6, guest PC 0x0c06e50e */
if(!s->budget--) { s->failed_pc=0x0c06e50eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06e510;
P_0c06e510: /* original 6bf6, guest PC 0x0c06e510 */
if(!s->budget--) { s->failed_pc=0x0c06e510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06e512;
P_0c06e512: /* original 6cf6, guest PC 0x0c06e512 */
if(!s->budget--) { s->failed_pc=0x0c06e512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06e514;
P_0c06e514: /* original 6df6, guest PC 0x0c06e514 */
if(!s->budget--) { s->failed_pc=0x0c06e514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06e516;
P_0c06e516: /* original 000b, guest PC 0x0c06e516 */
if(!s->budget--) { s->failed_pc=0x0c06e516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06e518: /* original 6ef6, guest PC 0x0c06e518 */
if(!s->budget--) { s->failed_pc=0x0c06e518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06e51au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
