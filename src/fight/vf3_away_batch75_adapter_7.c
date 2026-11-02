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
int vf3_away_batch75_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f354u: goto P_0c09f354;
case 0x0c09f356u: goto P_0c09f356;
case 0x0c09f358u: goto P_0c09f358;
case 0x0c09f35au: goto P_0c09f35a;
case 0x0c09f35cu: goto P_0c09f35c;
case 0x0c09f35eu: goto P_0c09f35e;
case 0x0c09f360u: goto P_0c09f360;
case 0x0c09f362u: goto P_0c09f362;
case 0x0c09f364u: goto P_0c09f364;
case 0x0c09f366u: goto P_0c09f366;
case 0x0c09f368u: goto P_0c09f368;
case 0x0c09f36au: goto P_0c09f36a;
case 0x0c09f36cu: goto P_0c09f36c;
case 0x0c09f36eu: goto P_0c09f36e;
case 0x0c09f370u: goto P_0c09f370;
case 0x0c09f372u: goto P_0c09f372;
case 0x0c09f374u: goto P_0c09f374;
case 0x0c09f376u: goto P_0c09f376;
case 0x0c09f378u: goto P_0c09f378;
case 0x0c09f37au: goto P_0c09f37a;
case 0x0c09f37cu: goto P_0c09f37c;
case 0x0c09f37eu: goto P_0c09f37e;
case 0x0c09f380u: goto P_0c09f380;
case 0x0c09f382u: goto P_0c09f382;
case 0x0c09f384u: goto P_0c09f384;
case 0x0c09f386u: goto P_0c09f386;
case 0x0c09f388u: goto P_0c09f388;
case 0x0c09f38au: goto P_0c09f38a;
case 0x0c09f38cu: goto P_0c09f38c;
case 0x0c09f38eu: goto P_0c09f38e;
case 0x0c09f390u: goto P_0c09f390;
case 0x0c09f392u: goto P_0c09f392;
case 0x0c09f394u: goto P_0c09f394;
case 0x0c09f396u: goto P_0c09f396;
case 0x0c09f398u: goto P_0c09f398;
case 0x0c09f39au: goto P_0c09f39a;
case 0x0c09f39cu: goto P_0c09f39c;
case 0x0c09f39eu: goto P_0c09f39e;
case 0x0c09f3a0u: goto P_0c09f3a0;
case 0x0c09f3a2u: goto P_0c09f3a2;
case 0x0c09f3a4u: goto P_0c09f3a4;
case 0x0c09f3a6u: goto P_0c09f3a6;
case 0x0c09f3a8u: goto P_0c09f3a8;
case 0x0c09f3aau: goto P_0c09f3aa;
case 0x0c09f3acu: goto P_0c09f3ac;
case 0x0c09f3aeu: goto P_0c09f3ae;
case 0x0c09f3b0u: goto P_0c09f3b0;
case 0x0c09f3b2u: goto P_0c09f3b2;
case 0x0c09f3b4u: goto P_0c09f3b4;
case 0x0c09f3b6u: goto P_0c09f3b6;
case 0x0c09f3b8u: goto P_0c09f3b8;
case 0x0c09f3bau: goto P_0c09f3ba;
case 0x0c09f3bcu: goto P_0c09f3bc;
case 0x0c09f3beu: goto P_0c09f3be;
case 0x0c09f3c0u: goto P_0c09f3c0;
case 0x0c09f3c2u: goto P_0c09f3c2;
case 0x0c09f3c4u: goto P_0c09f3c4;
case 0x0c09f3c6u: goto P_0c09f3c6;
case 0x0c09f3c8u: goto P_0c09f3c8;
case 0x0c09f3cau: goto P_0c09f3ca;
case 0x0c09f3ccu: goto P_0c09f3cc;
case 0x0c09f3ceu: goto P_0c09f3ce;
case 0x0c09f3d0u: goto P_0c09f3d0;
case 0x0c09f3d2u: goto P_0c09f3d2;
case 0x0c09f3d4u: goto P_0c09f3d4;
case 0x0c09f3d6u: goto P_0c09f3d6;
case 0x0c09f3d8u: goto P_0c09f3d8;
case 0x0c09f3dau: goto P_0c09f3da;
case 0x0c09f3dcu: goto P_0c09f3dc;
case 0x0c09f3deu: goto P_0c09f3de;
case 0x0c09f3e0u: goto P_0c09f3e0;
case 0x0c09f3e2u: goto P_0c09f3e2;
case 0x0c09f3e4u: goto P_0c09f3e4;
case 0x0c09f3e6u: goto P_0c09f3e6;
case 0x0c09f3e8u: goto P_0c09f3e8;
case 0x0c09f3eau: goto P_0c09f3ea;
case 0x0c09f3ecu: goto P_0c09f3ec;
case 0x0c09f3eeu: goto P_0c09f3ee;
case 0x0c09f3f0u: goto P_0c09f3f0;
case 0x0c09f3f2u: goto P_0c09f3f2;
case 0x0c09f3f4u: goto P_0c09f3f4;
case 0x0c09f3f6u: goto P_0c09f3f6;
case 0x0c09f3f8u: goto P_0c09f3f8;
case 0x0c09f3fau: goto P_0c09f3fa;
case 0x0c09f3fcu: goto P_0c09f3fc;
case 0x0c09f3feu: goto P_0c09f3fe;
case 0x0c09f400u: goto P_0c09f400;
case 0x0c09f402u: goto P_0c09f402;
case 0x0c09f404u: goto P_0c09f404;
case 0x0c09f406u: goto P_0c09f406;
case 0x0c09f408u: goto P_0c09f408;
case 0x0c09f40au: goto P_0c09f40a;
case 0x0c09f40cu: goto P_0c09f40c;
case 0x0c09f40eu: goto P_0c09f40e;
case 0x0c09f410u: goto P_0c09f410;
case 0x0c09f412u: goto P_0c09f412;
case 0x0c09f414u: goto P_0c09f414;
case 0x0c09f416u: goto P_0c09f416;
case 0x0c09f418u: goto P_0c09f418;
case 0x0c09f41au: goto P_0c09f41a;
case 0x0c09f41cu: goto P_0c09f41c;
case 0x0c09f41eu: goto P_0c09f41e;
case 0x0c09f420u: goto P_0c09f420;
case 0x0c09f422u: goto P_0c09f422;
case 0x0c09f424u: goto P_0c09f424;
case 0x0c09f426u: goto P_0c09f426;
case 0x0c09f428u: goto P_0c09f428;
case 0x0c09f42au: goto P_0c09f42a;
case 0x0c09f42cu: goto P_0c09f42c;
case 0x0c09f42eu: goto P_0c09f42e;
case 0x0c09f430u: goto P_0c09f430;
case 0x0c09f432u: goto P_0c09f432;
case 0x0c09f434u: goto P_0c09f434;
case 0x0c09f436u: goto P_0c09f436;
case 0x0c09f438u: goto P_0c09f438;
case 0x0c09f43au: goto P_0c09f43a;
case 0x0c09f43cu: goto P_0c09f43c;
case 0x0c09f43eu: goto P_0c09f43e;
case 0x0c09f440u: goto P_0c09f440;
case 0x0c09f442u: goto P_0c09f442;
case 0x0c09f444u: goto P_0c09f444;
case 0x0c09f446u: goto P_0c09f446;
case 0x0c09f448u: goto P_0c09f448;
case 0x0c09f44au: goto P_0c09f44a;
case 0x0c09f44cu: goto P_0c09f44c;
case 0x0c09f44eu: goto P_0c09f44e;
case 0x0c09f450u: goto P_0c09f450;
case 0x0c09f452u: goto P_0c09f452;
case 0x0c09f454u: goto P_0c09f454;
case 0x0c09f456u: goto P_0c09f456;
case 0x0c09f458u: goto P_0c09f458;
case 0x0c09f45au: goto P_0c09f45a;
case 0x0c09f45cu: goto P_0c09f45c;
case 0x0c09f45eu: goto P_0c09f45e;
case 0x0c09f460u: goto P_0c09f460;
case 0x0c09f462u: goto P_0c09f462;
case 0x0c09f464u: goto P_0c09f464;
case 0x0c09f466u: goto P_0c09f466;
case 0x0c09f468u: goto P_0c09f468;
case 0x0c09f46au: goto P_0c09f46a;
case 0x0c09f46cu: goto P_0c09f46c;
case 0x0c09f46eu: goto P_0c09f46e;
case 0x0c09f470u: goto P_0c09f470;
case 0x0c09f472u: goto P_0c09f472;
case 0x0c09f474u: goto P_0c09f474;
case 0x0c09f476u: goto P_0c09f476;
case 0x0c09f478u: goto P_0c09f478;
case 0x0c09f47au: goto P_0c09f47a;
case 0x0c09f47cu: goto P_0c09f47c;
case 0x0c09f47eu: goto P_0c09f47e;
case 0x0c09f480u: goto P_0c09f480;
case 0x0c09f482u: goto P_0c09f482;
case 0x0c09f484u: goto P_0c09f484;
case 0x0c09f486u: goto P_0c09f486;
case 0x0c09f488u: goto P_0c09f488;
case 0x0c09f48au: goto P_0c09f48a;
case 0x0c09f48cu: goto P_0c09f48c;
case 0x0c09f48eu: goto P_0c09f48e;
case 0x0c09f490u: goto P_0c09f490;
case 0x0c09f492u: goto P_0c09f492;
case 0x0c09f494u: goto P_0c09f494;
case 0x0c09f496u: goto P_0c09f496;
case 0x0c09f498u: goto P_0c09f498;
case 0x0c09f49au: goto P_0c09f49a;
case 0x0c09f49cu: goto P_0c09f49c;
case 0x0c09f49eu: goto P_0c09f49e;
case 0x0c09f4a0u: goto P_0c09f4a0;
case 0x0c09f4a2u: goto P_0c09f4a2;
case 0x0c09f4a4u: goto P_0c09f4a4;
case 0x0c09f4a6u: goto P_0c09f4a6;
case 0x0c09f4a8u: goto P_0c09f4a8;
case 0x0c09f4aau: goto P_0c09f4aa;
case 0x0c09f4acu: goto P_0c09f4ac;
case 0x0c09f4aeu: goto P_0c09f4ae;
case 0x0c09f4b0u: goto P_0c09f4b0;
case 0x0c09f4b2u: goto P_0c09f4b2;
case 0x0c09f4b4u: goto P_0c09f4b4;
case 0x0c09f4b6u: goto P_0c09f4b6;
case 0x0c09f4b8u: goto P_0c09f4b8;
case 0x0c09f4bau: goto P_0c09f4ba;
case 0x0c09f4bcu: goto P_0c09f4bc;
case 0x0c09f4beu: goto P_0c09f4be;
case 0x0c09f4c0u: goto P_0c09f4c0;
case 0x0c09f4c2u: goto P_0c09f4c2;
case 0x0c09f4c4u: goto P_0c09f4c4;
case 0x0c09f4c6u: goto P_0c09f4c6;
case 0x0c09f4c8u: goto P_0c09f4c8;
case 0x0c09f4cau: goto P_0c09f4ca;
case 0x0c09f4ccu: goto P_0c09f4cc;
case 0x0c09f4ceu: goto P_0c09f4ce;
case 0x0c09f4d0u: goto P_0c09f4d0;
case 0x0c09f4d2u: goto P_0c09f4d2;
case 0x0c09f4d4u: goto P_0c09f4d4;
case 0x0c09f4d6u: goto P_0c09f4d6;
case 0x0c09f4d8u: goto P_0c09f4d8;
case 0x0c09f4dau: goto P_0c09f4da;
case 0x0c09f4dcu: goto P_0c09f4dc;
case 0x0c09f4deu: goto P_0c09f4de;
case 0x0c09f4e0u: goto P_0c09f4e0;
case 0x0c09f4e2u: goto P_0c09f4e2;
case 0x0c09f4e4u: goto P_0c09f4e4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f354: /* original e612, guest PC 0x0c09f354 */
if(!s->budget--) { s->failed_pc=0x0c09f354u; return 0; }
r[6]=0x00000012u;
goto P_0c09f356;
P_0c09f356: /* original 7ffc, guest PC 0x0c09f356 */
if(!s->budget--) { s->failed_pc=0x0c09f356u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09f358;
P_0c09f358: /* original e004, guest PC 0x0c09f358 */
if(!s->budget--) { s->failed_pc=0x0c09f358u; return 0; }
r[0]=0x00000004u;
goto P_0c09f35a;
P_0c09f35a: /* original 6343, guest PC 0x0c09f35a */
if(!s->budget--) { s->failed_pc=0x0c09f35au; return 0; }
r[3]=r[4];
goto P_0c09f35c;
P_0c09f35c: /* original 6743, guest PC 0x0c09f35c */
if(!s->budget--) { s->failed_pc=0x0c09f35cu; return 0; }
r[7]=r[4];
goto P_0c09f35e;
P_0c09f35e: /* original 7308, guest PC 0x0c09f35e */
if(!s->budget--) { s->failed_pc=0x0c09f35eu; return 0; }
r[3]+=0x00000008u;
goto P_0c09f360;
P_0c09f360: /* original 7704, guest PC 0x0c09f360 */
if(!s->budget--) { s->failed_pc=0x0c09f360u; return 0; }
r[7]+=0x00000004u;
goto P_0c09f362;
P_0c09f362: /* original f648, guest PC 0x0c09f362 */
if(!s->budget--) { s->failed_pc=0x0c09f362u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c09f364;
P_0c09f364: /* original f878, guest PC 0x0c09f364 */
if(!s->budget--) { s->failed_pc=0x0c09f364u; return 0; }
vf3_matrix_load(s,ram,8,r[7]);
goto P_0c09f366;
P_0c09f366: /* original 4610, guest PC 0x0c09f366 */
if(!s->budget--) { s->failed_pc=0x0c09f366u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c09f368;
P_0c09f368: /* original 2f32, guest PC 0x0c09f368 */
if(!s->budget--) { s->failed_pc=0x0c09f368u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f36a;
P_0c09f36a: /* original f956, guest PC 0x0c09f36a */
if(!s->budget--) { s->failed_pc=0x0c09f36au; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c09f36c;
P_0c09f36c: /* original e008, guest PC 0x0c09f36c */
if(!s->budget--) { s->failed_pc=0x0c09f36cu; return 0; }
r[0]=0x00000008u;
goto P_0c09f36e;
P_0c09f36e: /* original f756, guest PC 0x0c09f36e */
if(!s->budget--) { s->failed_pc=0x0c09f36eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]+r[0]);
goto P_0c09f370;
P_0c09f370: /* original f538, guest PC 0x0c09f370 */
if(!s->budget--) { s->failed_pc=0x0c09f370u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c09f372;
P_0c09f372: /* original f891, guest PC 0x0c09f372 */
if(!s->budget--) { s->failed_pc=0x0c09f372u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[9],r[18],'-');
goto P_0c09f374;
P_0c09f374: /* original fa58, guest PC 0x0c09f374 */
if(!s->budget--) { s->failed_pc=0x0c09f374u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c09f376;
P_0c09f376: /* original 750c, guest PC 0x0c09f376 */
if(!s->budget--) { s->failed_pc=0x0c09f376u; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f378;
P_0c09f378: /* original f571, guest PC 0x0c09f378 */
if(!s->budget--) { s->failed_pc=0x0c09f378u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c09f37a;
P_0c09f37a: /* original f04c, guest PC 0x0c09f37a */
if(!s->budget--) { s->failed_pc=0x0c09f37au; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09f37c;
P_0c09f37c: /* original f6a1, guest PC 0x0c09f37c */
if(!s->budget--) { s->failed_pc=0x0c09f37cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c09f37e;
P_0c09f37e: /* original f98e, guest PC 0x0c09f37e */
if(!s->budget--) { s->failed_pc=0x0c09f37eu; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c09f380;
P_0c09f380: /* original f75e, guest PC 0x0c09f380 */
if(!s->budget--) { s->failed_pc=0x0c09f380u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[5],fr[7],r[18]);
goto P_0c09f382;
P_0c09f382: /* original fa6e, guest PC 0x0c09f382 */
if(!s->budget--) { s->failed_pc=0x0c09f382u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[6],fr[10],r[18]);
goto P_0c09f384;
P_0c09f384: /* original f89c, guest PC 0x0c09f384 */
if(!s->budget--) { s->failed_pc=0x0c09f384u; return 0; }
vf3_matrix_move(s,8,9);
goto P_0c09f386;
P_0c09f386: /* original f57c, guest PC 0x0c09f386 */
if(!s->budget--) { s->failed_pc=0x0c09f386u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c09f388;
P_0c09f388: /* original f6ac, guest PC 0x0c09f388 */
if(!s->budget--) { s->failed_pc=0x0c09f388u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c09f38a;
P_0c09f38a: /* original f46a, guest PC 0x0c09f38a */
if(!s->budget--) { s->failed_pc=0x0c09f38au; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c09f38c;
P_0c09f38c: /* original f78a, guest PC 0x0c09f38c */
if(!s->budget--) { s->failed_pc=0x0c09f38cu; return 0; }
vf3_matrix_store(s,ram,8,r[7]);
goto P_0c09f38e;
P_0c09f38e: /* original 63f2, guest PC 0x0c09f38e */
if(!s->budget--) { s->failed_pc=0x0c09f38eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09f390;
P_0c09f390: /* original f35a, guest PC 0x0c09f390 */
if(!s->budget--) { s->failed_pc=0x0c09f390u; return 0; }
vf3_matrix_store(s,ram,5,r[3]);
goto P_0c09f392;
P_0c09f392: /* original 8fe1, guest PC 0x0c09f392 */
if(!s->budget--) { s->failed_pc=0x0c09f392u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09f358; }
goto P_0c09f396;
P_0c09f394: /* original 740c, guest PC 0x0c09f394 */
if(!s->budget--) { s->failed_pc=0x0c09f394u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f396;
P_0c09f396: /* original 6643, guest PC 0x0c09f396 */
if(!s->budget--) { s->failed_pc=0x0c09f396u; return 0; }
r[6]=r[4];
goto P_0c09f398;
P_0c09f398: /* original fa58, guest PC 0x0c09f398 */
if(!s->budget--) { s->failed_pc=0x0c09f398u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c09f39a;
P_0c09f39a: /* original e004, guest PC 0x0c09f39a */
if(!s->budget--) { s->failed_pc=0x0c09f39au; return 0; }
r[0]=0x00000004u;
goto P_0c09f39c;
P_0c09f39c: /* original f648, guest PC 0x0c09f39c */
if(!s->budget--) { s->failed_pc=0x0c09f39cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c09f39e;
P_0c09f39e: /* original 7604, guest PC 0x0c09f39e */
if(!s->budget--) { s->failed_pc=0x0c09f39eu; return 0; }
r[6]+=0x00000004u;
goto P_0c09f3a0;
P_0c09f3a0: /* original f956, guest PC 0x0c09f3a0 */
if(!s->budget--) { s->failed_pc=0x0c09f3a0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c09f3a2;
P_0c09f3a2: /* original f768, guest PC 0x0c09f3a2 */
if(!s->budget--) { s->failed_pc=0x0c09f3a2u; return 0; }
vf3_matrix_load(s,ram,7,r[6]);
goto P_0c09f3a4;
P_0c09f3a4: /* original 6743, guest PC 0x0c09f3a4 */
if(!s->budget--) { s->failed_pc=0x0c09f3a4u; return 0; }
r[7]=r[4];
goto P_0c09f3a6;
P_0c09f3a6: /* original f6a1, guest PC 0x0c09f3a6 */
if(!s->budget--) { s->failed_pc=0x0c09f3a6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'-');
goto P_0c09f3a8;
P_0c09f3a8: /* original e008, guest PC 0x0c09f3a8 */
if(!s->budget--) { s->failed_pc=0x0c09f3a8u; return 0; }
r[0]=0x00000008u;
goto P_0c09f3aa;
P_0c09f3aa: /* original f791, guest PC 0x0c09f3aa */
if(!s->budget--) { s->failed_pc=0x0c09f3aau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c09f3ac;
P_0c09f3ac: /* original 7708, guest PC 0x0c09f3ac */
if(!s->budget--) { s->failed_pc=0x0c09f3acu; return 0; }
r[7]+=0x00000008u;
goto P_0c09f3ae;
P_0c09f3ae: /* original f578, guest PC 0x0c09f3ae */
if(!s->budget--) { s->failed_pc=0x0c09f3aeu; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c09f3b0;
P_0c09f3b0: /* original f856, guest PC 0x0c09f3b0 */
if(!s->budget--) { s->failed_pc=0x0c09f3b0u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c09f3b2;
P_0c09f3b2: /* original 750c, guest PC 0x0c09f3b2 */
if(!s->budget--) { s->failed_pc=0x0c09f3b2u; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f3b4;
P_0c09f3b4: /* original f04c, guest PC 0x0c09f3b4 */
if(!s->budget--) { s->failed_pc=0x0c09f3b4u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09f3b6;
P_0c09f3b6: /* original fa6e, guest PC 0x0c09f3b6 */
if(!s->budget--) { s->failed_pc=0x0c09f3b6u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[6],fr[10],r[18]);
goto P_0c09f3b8;
P_0c09f3b8: /* original f581, guest PC 0x0c09f3b8 */
if(!s->budget--) { s->failed_pc=0x0c09f3b8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c09f3ba;
P_0c09f3ba: /* original f97e, guest PC 0x0c09f3ba */
if(!s->budget--) { s->failed_pc=0x0c09f3bau; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[7],fr[9],r[18]);
goto P_0c09f3bc;
P_0c09f3bc: /* original f6ac, guest PC 0x0c09f3bc */
if(!s->budget--) { s->failed_pc=0x0c09f3bcu; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c09f3be;
P_0c09f3be: /* original f85e, guest PC 0x0c09f3be */
if(!s->budget--) { s->failed_pc=0x0c09f3beu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[5],fr[8],r[18]);
goto P_0c09f3c0;
P_0c09f3c0: /* original f79c, guest PC 0x0c09f3c0 */
if(!s->budget--) { s->failed_pc=0x0c09f3c0u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c09f3c2;
P_0c09f3c2: /* original f58c, guest PC 0x0c09f3c2 */
if(!s->budget--) { s->failed_pc=0x0c09f3c2u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c09f3c4;
P_0c09f3c4: /* original f46a, guest PC 0x0c09f3c4 */
if(!s->budget--) { s->failed_pc=0x0c09f3c4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c09f3c6;
P_0c09f3c6: /* original 740c, guest PC 0x0c09f3c6 */
if(!s->budget--) { s->failed_pc=0x0c09f3c6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f3c8;
P_0c09f3c8: /* original f67a, guest PC 0x0c09f3c8 */
if(!s->budget--) { s->failed_pc=0x0c09f3c8u; return 0; }
vf3_matrix_store(s,ram,7,r[6]);
goto P_0c09f3ca;
P_0c09f3ca: /* original 6643, guest PC 0x0c09f3ca */
if(!s->budget--) { s->failed_pc=0x0c09f3cau; return 0; }
r[6]=r[4];
goto P_0c09f3cc;
P_0c09f3cc: /* original 7604, guest PC 0x0c09f3cc */
if(!s->budget--) { s->failed_pc=0x0c09f3ccu; return 0; }
r[6]+=0x00000004u;
goto P_0c09f3ce;
P_0c09f3ce: /* original f75a, guest PC 0x0c09f3ce */
if(!s->budget--) { s->failed_pc=0x0c09f3ceu; return 0; }
vf3_matrix_store(s,ram,5,r[7]);
goto P_0c09f3d0;
P_0c09f3d0: /* original f768, guest PC 0x0c09f3d0 */
if(!s->budget--) { s->failed_pc=0x0c09f3d0u; return 0; }
vf3_matrix_load(s,ram,7,r[6]);
goto P_0c09f3d2;
P_0c09f3d2: /* original 6743, guest PC 0x0c09f3d2 */
if(!s->budget--) { s->failed_pc=0x0c09f3d2u; return 0; }
r[7]=r[4];
goto P_0c09f3d4;
P_0c09f3d4: /* original f648, guest PC 0x0c09f3d4 */
if(!s->budget--) { s->failed_pc=0x0c09f3d4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c09f3d6;
P_0c09f3d6: /* original e004, guest PC 0x0c09f3d6 */
if(!s->budget--) { s->failed_pc=0x0c09f3d6u; return 0; }
r[0]=0x00000004u;
goto P_0c09f3d8;
P_0c09f3d8: /* original f858, guest PC 0x0c09f3d8 */
if(!s->budget--) { s->failed_pc=0x0c09f3d8u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
goto P_0c09f3da;
P_0c09f3da: /* original f956, guest PC 0x0c09f3da */
if(!s->budget--) { s->failed_pc=0x0c09f3dau; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c09f3dc;
P_0c09f3dc: /* original e008, guest PC 0x0c09f3dc */
if(!s->budget--) { s->failed_pc=0x0c09f3dcu; return 0; }
r[0]=0x00000008u;
goto P_0c09f3de;
P_0c09f3de: /* original 7708, guest PC 0x0c09f3de */
if(!s->budget--) { s->failed_pc=0x0c09f3deu; return 0; }
r[7]+=0x00000008u;
goto P_0c09f3e0;
P_0c09f3e0: /* original fa56, guest PC 0x0c09f3e0 */
if(!s->budget--) { s->failed_pc=0x0c09f3e0u; return 0; }
vf3_matrix_load(s,ram,10,r[5]+r[0]);
goto P_0c09f3e2;
P_0c09f3e2: /* original f578, guest PC 0x0c09f3e2 */
if(!s->budget--) { s->failed_pc=0x0c09f3e2u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c09f3e4;
P_0c09f3e4: /* original f791, guest PC 0x0c09f3e4 */
if(!s->budget--) { s->failed_pc=0x0c09f3e4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c09f3e6;
P_0c09f3e6: /* original f681, guest PC 0x0c09f3e6 */
if(!s->budget--) { s->failed_pc=0x0c09f3e6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c09f3e8;
P_0c09f3e8: /* original e004, guest PC 0x0c09f3e8 */
if(!s->budget--) { s->failed_pc=0x0c09f3e8u; return 0; }
r[0]=0x00000004u;
goto P_0c09f3ea;
P_0c09f3ea: /* original f5a1, guest PC 0x0c09f3ea */
if(!s->budget--) { s->failed_pc=0x0c09f3eau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
goto P_0c09f3ec;
P_0c09f3ec: /* original 750c, guest PC 0x0c09f3ec */
if(!s->budget--) { s->failed_pc=0x0c09f3ecu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f3ee;
P_0c09f3ee: /* original f97e, guest PC 0x0c09f3ee */
if(!s->budget--) { s->failed_pc=0x0c09f3eeu; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[7],fr[9],r[18]);
goto P_0c09f3f0;
P_0c09f3f0: /* original f86e, guest PC 0x0c09f3f0 */
if(!s->budget--) { s->failed_pc=0x0c09f3f0u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[6],fr[8],r[18]);
goto P_0c09f3f2;
P_0c09f3f2: /* original fa5e, guest PC 0x0c09f3f2 */
if(!s->budget--) { s->failed_pc=0x0c09f3f2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[5],fr[10],r[18]);
goto P_0c09f3f4;
P_0c09f3f4: /* original f69c, guest PC 0x0c09f3f4 */
if(!s->budget--) { s->failed_pc=0x0c09f3f4u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c09f3f6;
P_0c09f3f6: /* original f5ac, guest PC 0x0c09f3f6 */
if(!s->budget--) { s->failed_pc=0x0c09f3f6u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f3f8;
P_0c09f3f8: /* original f48a, guest PC 0x0c09f3f8 */
if(!s->budget--) { s->failed_pc=0x0c09f3f8u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c09f3fa;
P_0c09f3fa: /* original 740c, guest PC 0x0c09f3fa */
if(!s->budget--) { s->failed_pc=0x0c09f3fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f3fc;
P_0c09f3fc: /* original f66a, guest PC 0x0c09f3fc */
if(!s->budget--) { s->failed_pc=0x0c09f3fcu; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c09f3fe;
P_0c09f3fe: /* original 6643, guest PC 0x0c09f3fe */
if(!s->budget--) { s->failed_pc=0x0c09f3feu; return 0; }
r[6]=r[4];
goto P_0c09f400;
P_0c09f400: /* original f75a, guest PC 0x0c09f400 */
if(!s->budget--) { s->failed_pc=0x0c09f400u; return 0; }
vf3_matrix_store(s,ram,5,r[7]);
goto P_0c09f402;
P_0c09f402: /* original 6743, guest PC 0x0c09f402 */
if(!s->budget--) { s->failed_pc=0x0c09f402u; return 0; }
r[7]=r[4];
goto P_0c09f404;
P_0c09f404: /* original f956, guest PC 0x0c09f404 */
if(!s->budget--) { s->failed_pc=0x0c09f404u; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c09f406;
P_0c09f406: /* original 7608, guest PC 0x0c09f406 */
if(!s->budget--) { s->failed_pc=0x0c09f406u; return 0; }
r[6]+=0x00000008u;
goto P_0c09f408;
P_0c09f408: /* original e008, guest PC 0x0c09f408 */
if(!s->budget--) { s->failed_pc=0x0c09f408u; return 0; }
r[0]=0x00000008u;
goto P_0c09f40a;
P_0c09f40a: /* original f848, guest PC 0x0c09f40a */
if(!s->budget--) { s->failed_pc=0x0c09f40au; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c09f40c;
P_0c09f40c: /* original 7704, guest PC 0x0c09f40c */
if(!s->budget--) { s->failed_pc=0x0c09f40cu; return 0; }
r[7]+=0x00000004u;
goto P_0c09f40e;
P_0c09f40e: /* original f656, guest PC 0x0c09f40e */
if(!s->budget--) { s->failed_pc=0x0c09f40eu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c09f410;
P_0c09f410: /* original f778, guest PC 0x0c09f410 */
if(!s->budget--) { s->failed_pc=0x0c09f410u; return 0; }
vf3_matrix_load(s,ram,7,r[7]);
goto P_0c09f412;
P_0c09f412: /* original fa58, guest PC 0x0c09f412 */
if(!s->budget--) { s->failed_pc=0x0c09f412u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c09f414;
P_0c09f414: /* original f568, guest PC 0x0c09f414 */
if(!s->budget--) { s->failed_pc=0x0c09f414u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c09f416;
P_0c09f416: /* original f561, guest PC 0x0c09f416 */
if(!s->budget--) { s->failed_pc=0x0c09f416u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c09f418;
P_0c09f418: /* original f791, guest PC 0x0c09f418 */
if(!s->budget--) { s->failed_pc=0x0c09f418u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c09f41a;
P_0c09f41a: /* original f8a1, guest PC 0x0c09f41a */
if(!s->budget--) { s->failed_pc=0x0c09f41au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'-');
goto P_0c09f41c;
P_0c09f41c: /* original f65e, guest PC 0x0c09f41c */
if(!s->budget--) { s->failed_pc=0x0c09f41cu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[5],fr[6],r[18]);
goto P_0c09f41e;
P_0c09f41e: /* original f97e, guest PC 0x0c09f41e */
if(!s->budget--) { s->failed_pc=0x0c09f41eu; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[7],fr[9],r[18]);
goto P_0c09f420;
P_0c09f420: /* original fa8e, guest PC 0x0c09f420 */
if(!s->budget--) { s->failed_pc=0x0c09f420u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[8],fr[10],r[18]);
goto P_0c09f422;
P_0c09f422: /* original f46c, guest PC 0x0c09f422 */
if(!s->budget--) { s->failed_pc=0x0c09f422u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09f424;
P_0c09f424: /* original f79c, guest PC 0x0c09f424 */
if(!s->budget--) { s->failed_pc=0x0c09f424u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c09f426;
P_0c09f426: /* original f8ac, guest PC 0x0c09f426 */
if(!s->budget--) { s->failed_pc=0x0c09f426u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c09f428;
P_0c09f428: /* original f48a, guest PC 0x0c09f428 */
if(!s->budget--) { s->failed_pc=0x0c09f428u; return 0; }
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c09f42a;
P_0c09f42a: /* original f77a, guest PC 0x0c09f42a */
if(!s->budget--) { s->failed_pc=0x0c09f42au; return 0; }
vf3_matrix_store(s,ram,7,r[7]);
goto P_0c09f42c;
P_0c09f42c: /* original f64a, guest PC 0x0c09f42c */
if(!s->budget--) { s->failed_pc=0x0c09f42cu; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c09f42e;
P_0c09f42e: /* original 000b, guest PC 0x0c09f42e */
if(!s->budget--) { s->failed_pc=0x0c09f42eu; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c09f430: /* original 7f04, guest PC 0x0c09f430 */
if(!s->budget--) { s->failed_pc=0x0c09f430u; return 0; }
r[15]+=0x00000004u;
goto P_0c09f432;
P_0c09f432: /* original 2fe6, guest PC 0x0c09f432 */
if(!s->budget--) { s->failed_pc=0x0c09f432u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f434;
P_0c09f434: /* original c72d, guest PC 0x0c09f434 */
if(!s->budget--) { s->failed_pc=0x0c09f434u; return 0; }
r[0]=code_base|0x0009f4ecu;
goto P_0c09f436;
P_0c09f436: /* original fffb, guest PC 0x0c09f436 */
if(!s->budget--) { s->failed_pc=0x0c09f436u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09f438;
P_0c09f438: /* original 6e43, guest PC 0x0c09f438 */
if(!s->budget--) { s->failed_pc=0x0c09f438u; return 0; }
r[14]=r[4];
goto P_0c09f43a;
P_0c09f43a: /* original ffeb, guest PC 0x0c09f43a */
if(!s->budget--) { s->failed_pc=0x0c09f43au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09f43c;
P_0c09f43c: /* original ffdb, guest PC 0x0c09f43c */
if(!s->budget--) { s->failed_pc=0x0c09f43cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f43e;
P_0c09f43e: /* original ffcb, guest PC 0x0c09f43e */
if(!s->budget--) { s->failed_pc=0x0c09f43eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c09f440;
P_0c09f440: /* original 4f22, guest PC 0x0c09f440 */
if(!s->budget--) { s->failed_pc=0x0c09f440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f442;
P_0c09f442: /* original f308, guest PC 0x0c09f442 */
if(!s->budget--) { s->failed_pc=0x0c09f442u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f444;
P_0c09f444: /* original c72a, guest PC 0x0c09f444 */
if(!s->budget--) { s->failed_pc=0x0c09f444u; return 0; }
r[0]=code_base|0x0009f4f0u;
goto P_0c09f446;
P_0c09f446: /* original 944e, guest PC 0x0c09f446 */
if(!s->budget--) { s->failed_pc=0x0c09f446u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e6u,2);
goto P_0c09f448;
P_0c09f448: /* original 7ff4, guest PC 0x0c09f448 */
if(!s->budget--) { s->failed_pc=0x0c09f448u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f44a;
P_0c09f44a: /* original ff3a, guest PC 0x0c09f44a */
if(!s->budget--) { s->failed_pc=0x0c09f44au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f44c;
P_0c09f44c: /* original 34ec, guest PC 0x0c09f44c */
if(!s->budget--) { s->failed_pc=0x0c09f44cu; return 0; }
r[4]+=r[14];
goto P_0c09f44e;
P_0c09f44e: /* original ff08, guest PC 0x0c09f44e */
if(!s->budget--) { s->failed_pc=0x0c09f44eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09f450;
P_0c09f450: /* original c728, guest PC 0x0c09f450 */
if(!s->budget--) { s->failed_pc=0x0c09f450u; return 0; }
r[0]=code_base|0x0009f4f4u;
goto P_0c09f452;
P_0c09f452: /* original f308, guest PC 0x0c09f452 */
if(!s->budget--) { s->failed_pc=0x0c09f452u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09f454;
P_0c09f454: /* original e004, guest PC 0x0c09f454 */
if(!s->budget--) { s->failed_pc=0x0c09f454u; return 0; }
r[0]=0x00000004u;
goto P_0c09f456;
P_0c09f456: /* original ff37, guest PC 0x0c09f456 */
if(!s->budget--) { s->failed_pc=0x0c09f456u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f458;
P_0c09f458: /* original c727, guest PC 0x0c09f458 */
if(!s->budget--) { s->failed_pc=0x0c09f458u; return 0; }
r[0]=code_base|0x0009f4f8u;
goto P_0c09f45a;
P_0c09f45a: /* original fc08, guest PC 0x0c09f45a */
if(!s->budget--) { s->failed_pc=0x0c09f45au; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c09f45c;
P_0c09f45c: /* original c727, guest PC 0x0c09f45c */
if(!s->budget--) { s->failed_pc=0x0c09f45cu; return 0; }
r[0]=code_base|0x0009f4fcu;
goto P_0c09f45e;
P_0c09f45e: /* original fe08, guest PC 0x0c09f45e */
if(!s->budget--) { s->failed_pc=0x0c09f45eu; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c09f460;
P_0c09f460: /* original f5f8, guest PC 0x0c09f460 */
if(!s->budget--) { s->failed_pc=0x0c09f460u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f462;
P_0c09f462: /* original fd8d, guest PC 0x0c09f462 */
if(!s->budget--) { s->failed_pc=0x0c09f462u; return 0; }
fr[13]=0;
goto P_0c09f464;
P_0c09f464: /* original f7cc, guest PC 0x0c09f464 */
if(!s->budget--) { s->failed_pc=0x0c09f464u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f466;
P_0c09f466: /* original f63c, guest PC 0x0c09f466 */
if(!s->budget--) { s->failed_pc=0x0c09f466u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c09f468;
P_0c09f468: /* original f9ec, guest PC 0x0c09f468 */
if(!s->budget--) { s->failed_pc=0x0c09f468u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f46a;
P_0c09f46a: /* original f8dc, guest PC 0x0c09f46a */
if(!s->budget--) { s->failed_pc=0x0c09f46au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f46c;
P_0c09f46c: /* original b0c4, guest PC 0x0c09f46c */
if(!s->budget--) { s->failed_pc=0x0c09f46cu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f470u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f470u) { target=s->pc; goto dispatch; }
goto P_0c09f470;
P_0c09f46e: /* original f4fc, guest PC 0x0c09f46e */
if(!s->budget--) { s->failed_pc=0x0c09f46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f470;
P_0c09f470: /* original 6403, guest PC 0x0c09f470 */
if(!s->budget--) { s->failed_pc=0x0c09f470u; return 0; }
r[4]=r[0];
goto P_0c09f472;
P_0c09f472: /* original e004, guest PC 0x0c09f472 */
if(!s->budget--) { s->failed_pc=0x0c09f472u; return 0; }
r[0]=0x00000004u;
goto P_0c09f474;
P_0c09f474: /* original f6f6, guest PC 0x0c09f474 */
if(!s->budget--) { s->failed_pc=0x0c09f474u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f476;
P_0c09f476: /* original f5f8, guest PC 0x0c09f476 */
if(!s->budget--) { s->failed_pc=0x0c09f476u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f478;
P_0c09f478: /* original f9ec, guest PC 0x0c09f478 */
if(!s->budget--) { s->failed_pc=0x0c09f478u; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f47a;
P_0c09f47a: /* original f8dc, guest PC 0x0c09f47a */
if(!s->budget--) { s->failed_pc=0x0c09f47au; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f47c;
P_0c09f47c: /* original f7cc, guest PC 0x0c09f47c */
if(!s->budget--) { s->failed_pc=0x0c09f47cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f47e;
P_0c09f47e: /* original b0bb, guest PC 0x0c09f47e */
if(!s->budget--) { s->failed_pc=0x0c09f47eu; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f482u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f482u) { target=s->pc; goto dispatch; }
goto P_0c09f482;
P_0c09f480: /* original f4fc, guest PC 0x0c09f480 */
if(!s->budget--) { s->failed_pc=0x0c09f480u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f482;
P_0c09f482: /* original 6403, guest PC 0x0c09f482 */
if(!s->budget--) { s->failed_pc=0x0c09f482u; return 0; }
r[4]=r[0];
goto P_0c09f484;
P_0c09f484: /* original e004, guest PC 0x0c09f484 */
if(!s->budget--) { s->failed_pc=0x0c09f484u; return 0; }
r[0]=0x00000004u;
goto P_0c09f486;
P_0c09f486: /* original f6f6, guest PC 0x0c09f486 */
if(!s->budget--) { s->failed_pc=0x0c09f486u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f488;
P_0c09f488: /* original 7454, guest PC 0x0c09f488 */
if(!s->budget--) { s->failed_pc=0x0c09f488u; return 0; }
r[4]+=0x00000054u;
goto P_0c09f48a;
P_0c09f48a: /* original f5f8, guest PC 0x0c09f48a */
if(!s->budget--) { s->failed_pc=0x0c09f48au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f48c;
P_0c09f48c: /* original f7cc, guest PC 0x0c09f48c */
if(!s->budget--) { s->failed_pc=0x0c09f48cu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f48e;
P_0c09f48e: /* original f9ec, guest PC 0x0c09f48e */
if(!s->budget--) { s->failed_pc=0x0c09f48eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f490;
P_0c09f490: /* original f8dc, guest PC 0x0c09f490 */
if(!s->budget--) { s->failed_pc=0x0c09f490u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f492;
P_0c09f492: /* original b0b1, guest PC 0x0c09f492 */
if(!s->budget--) { s->failed_pc=0x0c09f492u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f496u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f496u) { target=s->pc; goto dispatch; }
goto P_0c09f496;
P_0c09f494: /* original f4fc, guest PC 0x0c09f494 */
if(!s->budget--) { s->failed_pc=0x0c09f494u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f496;
P_0c09f496: /* original 6403, guest PC 0x0c09f496 */
if(!s->budget--) { s->failed_pc=0x0c09f496u; return 0; }
r[4]=r[0];
goto P_0c09f498;
P_0c09f498: /* original e004, guest PC 0x0c09f498 */
if(!s->budget--) { s->failed_pc=0x0c09f498u; return 0; }
r[0]=0x00000004u;
goto P_0c09f49a;
P_0c09f49a: /* original f6f6, guest PC 0x0c09f49a */
if(!s->budget--) { s->failed_pc=0x0c09f49au; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f49c;
P_0c09f49c: /* original f5f8, guest PC 0x0c09f49c */
if(!s->budget--) { s->failed_pc=0x0c09f49cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f49e;
P_0c09f49e: /* original f9ec, guest PC 0x0c09f49e */
if(!s->budget--) { s->failed_pc=0x0c09f49eu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4a0;
P_0c09f4a0: /* original f8dc, guest PC 0x0c09f4a0 */
if(!s->budget--) { s->failed_pc=0x0c09f4a0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4a2;
P_0c09f4a2: /* original f7cc, guest PC 0x0c09f4a2 */
if(!s->budget--) { s->failed_pc=0x0c09f4a2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4a4;
P_0c09f4a4: /* original b0a8, guest PC 0x0c09f4a4 */
if(!s->budget--) { s->failed_pc=0x0c09f4a4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4a8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4a8u) { target=s->pc; goto dispatch; }
goto P_0c09f4a8;
P_0c09f4a6: /* original f4fc, guest PC 0x0c09f4a6 */
if(!s->budget--) { s->failed_pc=0x0c09f4a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4a8;
P_0c09f4a8: /* original 921e, guest PC 0x0c09f4a8 */
if(!s->budget--) { s->failed_pc=0x0c09f4a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4e8u,2);
goto P_0c09f4aa;
P_0c09f4aa: /* original 6503, guest PC 0x0c09f4aa */
if(!s->budget--) { s->failed_pc=0x0c09f4aau; return 0; }
r[5]=r[0];
goto P_0c09f4ac;
P_0c09f4ac: /* original 32ec, guest PC 0x0c09f4ac */
if(!s->budget--) { s->failed_pc=0x0c09f4acu; return 0; }
r[2]+=r[14];
goto P_0c09f4ae;
P_0c09f4ae: /* original 6623, guest PC 0x0c09f4ae */
if(!s->budget--) { s->failed_pc=0x0c09f4aeu; return 0; }
r[6]=r[2];
goto P_0c09f4b0;
P_0c09f4b0: /* original 1f22, guest PC 0x0c09f4b0 */
if(!s->budget--) { s->failed_pc=0x0c09f4b0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4b2;
P_0c09f4b2: /* original b025, guest PC 0x0c09f4b2 */
if(!s->budget--) { s->failed_pc=0x0c09f4b2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4b6u) { target=s->pc; goto dispatch; }
goto P_0c09f4b6;
P_0c09f4b4: /* original 64e3, guest PC 0x0c09f4b4 */
if(!s->budget--) { s->failed_pc=0x0c09f4b4u; return 0; }
r[4]=r[14];
goto P_0c09f4b6;
P_0c09f4b6: /* original 6403, guest PC 0x0c09f4b6 */
if(!s->budget--) { s->failed_pc=0x0c09f4b6u; return 0; }
r[4]=r[0];
goto P_0c09f4b8;
P_0c09f4b8: /* original e004, guest PC 0x0c09f4b8 */
if(!s->budget--) { s->failed_pc=0x0c09f4b8u; return 0; }
r[0]=0x00000004u;
goto P_0c09f4ba;
P_0c09f4ba: /* original f6f6, guest PC 0x0c09f4ba */
if(!s->budget--) { s->failed_pc=0x0c09f4bau; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f4bc;
P_0c09f4bc: /* original f5f8, guest PC 0x0c09f4bc */
if(!s->budget--) { s->failed_pc=0x0c09f4bcu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f4be;
P_0c09f4be: /* original f9ec, guest PC 0x0c09f4be */
if(!s->budget--) { s->failed_pc=0x0c09f4beu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c09f4c0;
P_0c09f4c0: /* original f8dc, guest PC 0x0c09f4c0 */
if(!s->budget--) { s->failed_pc=0x0c09f4c0u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c09f4c2;
P_0c09f4c2: /* original f7cc, guest PC 0x0c09f4c2 */
if(!s->budget--) { s->failed_pc=0x0c09f4c2u; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c09f4c4;
P_0c09f4c4: /* original b098, guest PC 0x0c09f4c4 */
if(!s->budget--) { s->failed_pc=0x0c09f4c4u; return 0; }
target=code_base|0x0c09f5f8u; r[16]=code_base|0x0c09f4c8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4c8u) { target=s->pc; goto dispatch; }
goto P_0c09f4c8;
P_0c09f4c6: /* original f4fc, guest PC 0x0c09f4c6 */
if(!s->budget--) { s->failed_pc=0x0c09f4c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09f4c8;
P_0c09f4c8: /* original 920f, guest PC 0x0c09f4c8 */
if(!s->budget--) { s->failed_pc=0x0c09f4c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f4eau,2);
goto P_0c09f4ca;
P_0c09f4ca: /* original 6503, guest PC 0x0c09f4ca */
if(!s->budget--) { s->failed_pc=0x0c09f4cau; return 0; }
r[5]=r[0];
goto P_0c09f4cc;
P_0c09f4cc: /* original 32ec, guest PC 0x0c09f4cc */
if(!s->budget--) { s->failed_pc=0x0c09f4ccu; return 0; }
r[2]+=r[14];
goto P_0c09f4ce;
P_0c09f4ce: /* original 6623, guest PC 0x0c09f4ce */
if(!s->budget--) { s->failed_pc=0x0c09f4ceu; return 0; }
r[6]=r[2];
goto P_0c09f4d0;
P_0c09f4d0: /* original 1f22, guest PC 0x0c09f4d0 */
if(!s->budget--) { s->failed_pc=0x0c09f4d0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f4d2;
P_0c09f4d2: /* original b015, guest PC 0x0c09f4d2 */
if(!s->budget--) { s->failed_pc=0x0c09f4d2u; return 0; }
target=code_base|0x0c09f500u; r[16]=code_base|0x0c09f4d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f4d6u) { target=s->pc; goto dispatch; }
goto P_0c09f4d6;
P_0c09f4d4: /* original 64e3, guest PC 0x0c09f4d4 */
if(!s->budget--) { s->failed_pc=0x0c09f4d4u; return 0; }
r[4]=r[14];
goto P_0c09f4d6;
P_0c09f4d6: /* original 7f0c, guest PC 0x0c09f4d6 */
if(!s->budget--) { s->failed_pc=0x0c09f4d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f4d8;
P_0c09f4d8: /* original 4f26, guest PC 0x0c09f4d8 */
if(!s->budget--) { s->failed_pc=0x0c09f4d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f4da;
P_0c09f4da: /* original fcf9, guest PC 0x0c09f4da */
if(!s->budget--) { s->failed_pc=0x0c09f4dau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4dc;
P_0c09f4dc: /* original fdf9, guest PC 0x0c09f4dc */
if(!s->budget--) { s->failed_pc=0x0c09f4dcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4de;
P_0c09f4de: /* original fef9, guest PC 0x0c09f4de */
if(!s->budget--) { s->failed_pc=0x0c09f4deu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e0;
P_0c09f4e0: /* original fff9, guest PC 0x0c09f4e0 */
if(!s->budget--) { s->failed_pc=0x0c09f4e0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09f4e2;
P_0c09f4e2: /* original 000b, guest PC 0x0c09f4e2 */
if(!s->budget--) { s->failed_pc=0x0c09f4e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f4e4: /* original 6ef6, guest PC 0x0c09f4e4 */
if(!s->budget--) { s->failed_pc=0x0c09f4e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09f4e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f4e6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
