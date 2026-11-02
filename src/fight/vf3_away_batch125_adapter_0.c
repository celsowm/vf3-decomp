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
int vf3_away_batch125_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c09f6d0u: goto P_0c09f6d0;
case 0x0c09f6d2u: goto P_0c09f6d2;
case 0x0c09f6d4u: goto P_0c09f6d4;
case 0x0c09f6d6u: goto P_0c09f6d6;
case 0x0c09f6d8u: goto P_0c09f6d8;
case 0x0c09f6dau: goto P_0c09f6da;
case 0x0c09f6dcu: goto P_0c09f6dc;
case 0x0c09f6deu: goto P_0c09f6de;
case 0x0c09f6e0u: goto P_0c09f6e0;
case 0x0c09f6e2u: goto P_0c09f6e2;
case 0x0c09f6e4u: goto P_0c09f6e4;
case 0x0c09f6e6u: goto P_0c09f6e6;
case 0x0c09f6e8u: goto P_0c09f6e8;
case 0x0c09f6eau: goto P_0c09f6ea;
case 0x0c09f6ecu: goto P_0c09f6ec;
case 0x0c09f6eeu: goto P_0c09f6ee;
case 0x0c09f6f0u: goto P_0c09f6f0;
case 0x0c09f6f2u: goto P_0c09f6f2;
case 0x0c09f6f4u: goto P_0c09f6f4;
case 0x0c09f6f6u: goto P_0c09f6f6;
case 0x0c09f6f8u: goto P_0c09f6f8;
case 0x0c09f6fau: goto P_0c09f6fa;
case 0x0c09f6fcu: goto P_0c09f6fc;
case 0x0c09f6feu: goto P_0c09f6fe;
case 0x0c09f700u: goto P_0c09f700;
case 0x0c09f702u: goto P_0c09f702;
case 0x0c09f704u: goto P_0c09f704;
case 0x0c09f706u: goto P_0c09f706;
case 0x0c09f708u: goto P_0c09f708;
case 0x0c09f70au: goto P_0c09f70a;
case 0x0c09f70cu: goto P_0c09f70c;
case 0x0c09f70eu: goto P_0c09f70e;
case 0x0c09f710u: goto P_0c09f710;
case 0x0c09f712u: goto P_0c09f712;
case 0x0c09f714u: goto P_0c09f714;
case 0x0c09f716u: goto P_0c09f716;
case 0x0c09f718u: goto P_0c09f718;
case 0x0c09f71au: goto P_0c09f71a;
case 0x0c09f71cu: goto P_0c09f71c;
case 0x0c09f71eu: goto P_0c09f71e;
case 0x0c09f720u: goto P_0c09f720;
case 0x0c09f722u: goto P_0c09f722;
case 0x0c09f724u: goto P_0c09f724;
case 0x0c09f726u: goto P_0c09f726;
case 0x0c09f728u: goto P_0c09f728;
case 0x0c09f72au: goto P_0c09f72a;
case 0x0c09f72cu: goto P_0c09f72c;
case 0x0c09f72eu: goto P_0c09f72e;
case 0x0c09f730u: goto P_0c09f730;
case 0x0c09f732u: goto P_0c09f732;
case 0x0c09f734u: goto P_0c09f734;
case 0x0c09f736u: goto P_0c09f736;
case 0x0c09f738u: goto P_0c09f738;
case 0x0c09f73au: goto P_0c09f73a;
case 0x0c09f73cu: goto P_0c09f73c;
case 0x0c09f73eu: goto P_0c09f73e;
case 0x0c09f740u: goto P_0c09f740;
case 0x0c09f742u: goto P_0c09f742;
case 0x0c09f744u: goto P_0c09f744;
case 0x0c09f746u: goto P_0c09f746;
case 0x0c09f748u: goto P_0c09f748;
case 0x0c09f74au: goto P_0c09f74a;
case 0x0c09f74cu: goto P_0c09f74c;
case 0x0c09f74eu: goto P_0c09f74e;
case 0x0c09f750u: goto P_0c09f750;
case 0x0c09f752u: goto P_0c09f752;
case 0x0c09f754u: goto P_0c09f754;
case 0x0c09f756u: goto P_0c09f756;
case 0x0c09f758u: goto P_0c09f758;
case 0x0c09f75au: goto P_0c09f75a;
case 0x0c09f75cu: goto P_0c09f75c;
case 0x0c09f75eu: goto P_0c09f75e;
case 0x0c09f760u: goto P_0c09f760;
case 0x0c09f762u: goto P_0c09f762;
case 0x0c09f764u: goto P_0c09f764;
case 0x0c09f766u: goto P_0c09f766;
case 0x0c09f768u: goto P_0c09f768;
case 0x0c09f76au: goto P_0c09f76a;
case 0x0c09f76cu: goto P_0c09f76c;
case 0x0c09f76eu: goto P_0c09f76e;
case 0x0c09f770u: goto P_0c09f770;
case 0x0c09f772u: goto P_0c09f772;
case 0x0c09f774u: goto P_0c09f774;
case 0x0c09f776u: goto P_0c09f776;
case 0x0c09f778u: goto P_0c09f778;
case 0x0c09f77au: goto P_0c09f77a;
case 0x0c09f77cu: goto P_0c09f77c;
case 0x0c09f77eu: goto P_0c09f77e;
case 0x0c09f780u: goto P_0c09f780;
case 0x0c09f782u: goto P_0c09f782;
case 0x0c09f784u: goto P_0c09f784;
case 0x0c09f786u: goto P_0c09f786;
case 0x0c09f788u: goto P_0c09f788;
case 0x0c09f78au: goto P_0c09f78a;
case 0x0c09f78cu: goto P_0c09f78c;
case 0x0c09f78eu: goto P_0c09f78e;
case 0x0c09f790u: goto P_0c09f790;
case 0x0c09f792u: goto P_0c09f792;
case 0x0c09f794u: goto P_0c09f794;
case 0x0c09f796u: goto P_0c09f796;
case 0x0c09f798u: goto P_0c09f798;
case 0x0c09f79au: goto P_0c09f79a;
case 0x0c09f79cu: goto P_0c09f79c;
case 0x0c09f79eu: goto P_0c09f79e;
case 0x0c09f7a0u: goto P_0c09f7a0;
case 0x0c09f7a2u: goto P_0c09f7a2;
case 0x0c09f7a4u: goto P_0c09f7a4;
case 0x0c09f7a6u: goto P_0c09f7a6;
case 0x0c09f7a8u: goto P_0c09f7a8;
case 0x0c09f7aau: goto P_0c09f7aa;
case 0x0c09f7acu: goto P_0c09f7ac;
case 0x0c09f7aeu: goto P_0c09f7ae;
case 0x0c09f7b0u: goto P_0c09f7b0;
case 0x0c09f7b2u: goto P_0c09f7b2;
case 0x0c09f7d4u: goto P_0c09f7d4;
case 0x0c09f7d6u: goto P_0c09f7d6;
case 0x0c09f7d8u: goto P_0c09f7d8;
case 0x0c09f7dau: goto P_0c09f7da;
case 0x0c09f7dcu: goto P_0c09f7dc;
case 0x0c09f7deu: goto P_0c09f7de;
case 0x0c09f7e0u: goto P_0c09f7e0;
case 0x0c09f7e2u: goto P_0c09f7e2;
case 0x0c09f7e4u: goto P_0c09f7e4;
case 0x0c09f7e6u: goto P_0c09f7e6;
case 0x0c09f7e8u: goto P_0c09f7e8;
case 0x0c09f7eau: goto P_0c09f7ea;
case 0x0c09f7ecu: goto P_0c09f7ec;
case 0x0c09f7eeu: goto P_0c09f7ee;
case 0x0c09f7f0u: goto P_0c09f7f0;
case 0x0c09f7f2u: goto P_0c09f7f2;
case 0x0c09f7f4u: goto P_0c09f7f4;
case 0x0c09f7f6u: goto P_0c09f7f6;
case 0x0c09f7f8u: goto P_0c09f7f8;
case 0x0c09f7fau: goto P_0c09f7fa;
case 0x0c09f7fcu: goto P_0c09f7fc;
case 0x0c09f7feu: goto P_0c09f7fe;
case 0x0c09f800u: goto P_0c09f800;
case 0x0c09f802u: goto P_0c09f802;
case 0x0c09f804u: goto P_0c09f804;
case 0x0c09f806u: goto P_0c09f806;
case 0x0c09f808u: goto P_0c09f808;
case 0x0c09f80au: goto P_0c09f80a;
case 0x0c09f80cu: goto P_0c09f80c;
case 0x0c09f80eu: goto P_0c09f80e;
case 0x0c09f810u: goto P_0c09f810;
case 0x0c09f812u: goto P_0c09f812;
case 0x0c09f814u: goto P_0c09f814;
case 0x0c09f816u: goto P_0c09f816;
case 0x0c09f818u: goto P_0c09f818;
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
if(!vf3_matrix_family(0x0c09f432u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f432u; return 0; } return 1;
P_0c09f6d0: /* original 2fe6, guest PC 0x0c09f6d0 */
if(!s->budget--) { s->failed_pc=0x0c09f6d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d2;
P_0c09f6d2: /* original 2fd6, guest PC 0x0c09f6d2 */
if(!s->budget--) { s->failed_pc=0x0c09f6d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d4;
P_0c09f6d4: /* original ed0e, guest PC 0x0c09f6d4 */
if(!s->budget--) { s->failed_pc=0x0c09f6d4u; return 0; }
r[13]=0x0000000eu;
goto P_0c09f6d6;
P_0c09f6d6: /* original 2fc6, guest PC 0x0c09f6d6 */
if(!s->budget--) { s->failed_pc=0x0c09f6d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d8;
P_0c09f6d8: /* original 9c6d, guest PC 0x0c09f6d8 */
if(!s->budget--) { s->failed_pc=0x0c09f6d8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b6u,2);
goto P_0c09f6da;
P_0c09f6da: /* original 9e6b, guest PC 0x0c09f6da */
if(!s->budget--) { s->failed_pc=0x0c09f6dau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b4u,2);
goto P_0c09f6dc;
P_0c09f6dc: /* original 4f22, guest PC 0x0c09f6dc */
if(!s->budget--) { s->failed_pc=0x0c09f6dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f6de;
P_0c09f6de: /* original 3c4c, guest PC 0x0c09f6de */
if(!s->budget--) { s->failed_pc=0x0c09f6deu; return 0; }
r[12]+=r[4];
goto P_0c09f6e0;
P_0c09f6e0: /* original 3e4c, guest PC 0x0c09f6e0 */
if(!s->budget--) { s->failed_pc=0x0c09f6e0u; return 0; }
r[14]+=r[4];
goto P_0c09f6e2;
P_0c09f6e2: /* original 65c3, guest PC 0x0c09f6e2 */
if(!s->budget--) { s->failed_pc=0x0c09f6e2u; return 0; }
r[5]=r[12];
goto P_0c09f6e4;
P_0c09f6e4: /* original b00a, guest PC 0x0c09f6e4 */
if(!s->budget--) { s->failed_pc=0x0c09f6e4u; return 0; }
target=code_base|0x0c09f6fcu; r[16]=code_base|0x0c09f6e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f6e8u) { target=s->pc; goto dispatch; }
goto P_0c09f6e8;
P_0c09f6e6: /* original 64e3, guest PC 0x0c09f6e6 */
if(!s->budget--) { s->failed_pc=0x0c09f6e6u; return 0; }
r[4]=r[14];
goto P_0c09f6e8;
P_0c09f6e8: /* original 7dff, guest PC 0x0c09f6e8 */
if(!s->budget--) { s->failed_pc=0x0c09f6e8u; return 0; }
r[13]+=0xffffffffu;
goto P_0c09f6ea;
P_0c09f6ea: /* original 4d15, guest PC 0x0c09f6ea */
if(!s->budget--) { s->failed_pc=0x0c09f6eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c09f6ec;
P_0c09f6ec: /* original 7e0c, guest PC 0x0c09f6ec */
if(!s->budget--) { s->failed_pc=0x0c09f6ecu; return 0; }
r[14]+=0x0000000cu;
goto P_0c09f6ee;
P_0c09f6ee: /* original 8df8, guest PC 0x0c09f6ee */
if(!s->budget--) { s->failed_pc=0x0c09f6eeu; return 0; }
cond=r[17]&1u;
r[12]+=0x0000000cu;
if(cond) { goto P_0c09f6e2; }
goto P_0c09f6f2;
P_0c09f6f0: /* original 7c0c, guest PC 0x0c09f6f0 */
if(!s->budget--) { s->failed_pc=0x0c09f6f0u; return 0; }
r[12]+=0x0000000cu;
goto P_0c09f6f2;
P_0c09f6f2: /* original 4f26, guest PC 0x0c09f6f2 */
if(!s->budget--) { s->failed_pc=0x0c09f6f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f6f4;
P_0c09f6f4: /* original 6cf6, guest PC 0x0c09f6f4 */
if(!s->budget--) { s->failed_pc=0x0c09f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f6f6;
P_0c09f6f6: /* original 6df6, guest PC 0x0c09f6f6 */
if(!s->budget--) { s->failed_pc=0x0c09f6f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f6f8;
P_0c09f6f8: /* original 000b, guest PC 0x0c09f6f8 */
if(!s->budget--) { s->failed_pc=0x0c09f6f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f6fa: /* original 6ef6, guest PC 0x0c09f6fa */
if(!s->budget--) { s->failed_pc=0x0c09f6fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09f6fc;
P_0c09f6fc: /* original c72e, guest PC 0x0c09f6fc */
if(!s->budget--) { s->failed_pc=0x0c09f6fcu; return 0; }
r[0]=code_base|0x0009f7b8u;
goto P_0c09f6fe;
P_0c09f6fe: /* original ffdb, guest PC 0x0c09f6fe */
if(!s->budget--) { s->failed_pc=0x0c09f6feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f700;
P_0c09f700: /* original f908, guest PC 0x0c09f700 */
if(!s->budget--) { s->failed_pc=0x0c09f700u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c09f702;
P_0c09f702: /* original c72e, guest PC 0x0c09f702 */
if(!s->budget--) { s->failed_pc=0x0c09f702u; return 0; }
r[0]=code_base|0x0009f7bcu;
goto P_0c09f704;
P_0c09f704: /* original fa08, guest PC 0x0c09f704 */
if(!s->budget--) { s->failed_pc=0x0c09f704u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09f706;
P_0c09f706: /* original c72e, guest PC 0x0c09f706 */
if(!s->budget--) { s->failed_pc=0x0c09f706u; return 0; }
r[0]=code_base|0x0009f7c0u;
goto P_0c09f708;
P_0c09f708: /* original fb08, guest PC 0x0c09f708 */
if(!s->budget--) { s->failed_pc=0x0c09f708u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c09f70a;
P_0c09f70a: /* original c72e, guest PC 0x0c09f70a */
if(!s->budget--) { s->failed_pc=0x0c09f70au; return 0; }
r[0]=code_base|0x0009f7c4u;
goto P_0c09f70c;
P_0c09f70c: /* original f808, guest PC 0x0c09f70c */
if(!s->budget--) { s->failed_pc=0x0c09f70cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c09f70e;
P_0c09f70e: /* original c72e, guest PC 0x0c09f70e */
if(!s->budget--) { s->failed_pc=0x0c09f70eu; return 0; }
r[0]=code_base|0x0009f7c8u;
goto P_0c09f710;
P_0c09f710: /* original f708, guest PC 0x0c09f710 */
if(!s->budget--) { s->failed_pc=0x0c09f710u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09f712;
P_0c09f712: /* original e004, guest PC 0x0c09f712 */
if(!s->budget--) { s->failed_pc=0x0c09f712u; return 0; }
r[0]=0x00000004u;
goto P_0c09f714;
P_0c09f714: /* original f348, guest PC 0x0c09f714 */
if(!s->budget--) { s->failed_pc=0x0c09f714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09f716;
P_0c09f716: /* original 7ff4, guest PC 0x0c09f716 */
if(!s->budget--) { s->failed_pc=0x0c09f716u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f718;
P_0c09f718: /* original 6653, guest PC 0x0c09f718 */
if(!s->budget--) { s->failed_pc=0x0c09f718u; return 0; }
r[6]=r[5];
goto P_0c09f71a;
P_0c09f71a: /* original 7604, guest PC 0x0c09f71a */
if(!s->budget--) { s->failed_pc=0x0c09f71au; return 0; }
r[6]+=0x00000004u;
goto P_0c09f71c;
P_0c09f71c: /* original ff37, guest PC 0x0c09f71c */
if(!s->budget--) { s->failed_pc=0x0c09f71cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f71e;
P_0c09f71e: /* original e004, guest PC 0x0c09f71e */
if(!s->budget--) { s->failed_pc=0x0c09f71eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f720;
P_0c09f720: /* original f346, guest PC 0x0c09f720 */
if(!s->budget--) { s->failed_pc=0x0c09f720u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f722;
P_0c09f722: /* original e008, guest PC 0x0c09f722 */
if(!s->budget--) { s->failed_pc=0x0c09f722u; return 0; }
r[0]=0x00000008u;
goto P_0c09f724;
P_0c09f724: /* original f558, guest PC 0x0c09f724 */
if(!s->budget--) { s->failed_pc=0x0c09f724u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09f726;
P_0c09f726: /* original ff3a, guest PC 0x0c09f726 */
if(!s->budget--) { s->failed_pc=0x0c09f726u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f728;
P_0c09f728: /* original f346, guest PC 0x0c09f728 */
if(!s->budget--) { s->failed_pc=0x0c09f728u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f72a;
P_0c09f72a: /* original 6453, guest PC 0x0c09f72a */
if(!s->budget--) { s->failed_pc=0x0c09f72au; return 0; }
r[4]=r[5];
goto P_0c09f72c;
P_0c09f72c: /* original 7408, guest PC 0x0c09f72c */
if(!s->budget--) { s->failed_pc=0x0c09f72cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09f72e;
P_0c09f72e: /* original f668, guest PC 0x0c09f72e */
if(!s->budget--) { s->failed_pc=0x0c09f72eu; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c09f730;
P_0c09f730: /* original e008, guest PC 0x0c09f730 */
if(!s->budget--) { s->failed_pc=0x0c09f730u; return 0; }
r[0]=0x00000008u;
goto P_0c09f732;
P_0c09f732: /* original ff37, guest PC 0x0c09f732 */
if(!s->budget--) { s->failed_pc=0x0c09f732u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f734;
P_0c09f734: /* original f448, guest PC 0x0c09f734 */
if(!s->budget--) { s->failed_pc=0x0c09f734u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09f736;
P_0c09f736: /* original e004, guest PC 0x0c09f736 */
if(!s->budget--) { s->failed_pc=0x0c09f736u; return 0; }
r[0]=0x00000004u;
goto P_0c09f738;
P_0c09f738: /* original f28d, guest PC 0x0c09f738 */
if(!s->budget--) { s->failed_pc=0x0c09f738u; return 0; }
fr[2]=0;
goto P_0c09f73a;
P_0c09f73a: /* original f1f6, guest PC 0x0c09f73a */
if(!s->budget--) { s->failed_pc=0x0c09f73au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c09f73c;
P_0c09f73c: /* original c723, guest PC 0x0c09f73c */
if(!s->budget--) { s->failed_pc=0x0c09f73cu; return 0; }
r[0]=code_base|0x0009f7ccu;
goto P_0c09f73e;
P_0c09f73e: /* original f151, guest PC 0x0c09f73e */
if(!s->budget--) { s->failed_pc=0x0c09f73eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09f740;
P_0c09f740: /* original f01c, guest PC 0x0c09f740 */
if(!s->budget--) { s->failed_pc=0x0c09f740u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c09f742;
P_0c09f742: /* original f05d, guest PC 0x0c09f742 */
if(!s->budget--) { s->failed_pc=0x0c09f742u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c09f744;
P_0c09f744: /* original f705, guest PC 0x0c09f744 */
if(!s->budget--) { s->failed_pc=0x0c09f744u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[0]))!=0);
goto P_0c09f746;
P_0c09f746: /* original 8f17, guest PC 0x0c09f746 */
if(!s->budget--) { s->failed_pc=0x0c09f746u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[0]);
if(!cond) { goto P_0c09f778; }
goto P_0c09f74a;
P_0c09f748: /* original fd08, guest PC 0x0c09f748 */
if(!s->budget--) { s->failed_pc=0x0c09f748u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09f74a;
P_0c09f74a: /* original f805, guest PC 0x0c09f74a */
if(!s->budget--) { s->failed_pc=0x0c09f74au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c09f74c;
P_0c09f74c: /* original 8b08, guest PC 0x0c09f74c */
if(!s->budget--) { s->failed_pc=0x0c09f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f760; }
goto P_0c09f74e;
P_0c09f74e: /* original f905, guest PC 0x0c09f74e */
if(!s->budget--) { s->failed_pc=0x0c09f74eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[0]))!=0);
goto P_0c09f750;
P_0c09f750: /* original 8913, guest PC 0x0c09f750 */
if(!s->budget--) { s->failed_pc=0x0c09f750u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f77a; }
goto P_0c09f752;
P_0c09f752: /* original f38d, guest PC 0x0c09f752 */
if(!s->budget--) { s->failed_pc=0x0c09f752u; return 0; }
fr[3]=0;
goto P_0c09f754;
P_0c09f754: /* original f315, guest PC 0x0c09f754 */
if(!s->budget--) { s->failed_pc=0x0c09f754u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f756;
P_0c09f756: /* original 8901, guest PC 0x0c09f756 */
if(!s->budget--) { s->failed_pc=0x0c09f756u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f75c; }
goto P_0c09f758;
P_0c09f758: /* original a009, guest PC 0x0c09f758 */
if(!s->budget--) { s->failed_pc=0x0c09f758u; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f76e;
P_0c09f75a: /* original f1ac, guest PC 0x0c09f75a */
if(!s->budget--) { s->failed_pc=0x0c09f75au; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f75c;
P_0c09f75c: /* original a007, guest PC 0x0c09f75c */
if(!s->budget--) { s->failed_pc=0x0c09f75cu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f76e;
P_0c09f75e: /* original f1dc, guest PC 0x0c09f75e */
if(!s->budget--) { s->failed_pc=0x0c09f75eu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f760;
P_0c09f760: /* original f38d, guest PC 0x0c09f760 */
if(!s->budget--) { s->failed_pc=0x0c09f760u; return 0; }
fr[3]=0;
goto P_0c09f762;
P_0c09f762: /* original f315, guest PC 0x0c09f762 */
if(!s->budget--) { s->failed_pc=0x0c09f762u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f764;
P_0c09f764: /* original 8901, guest PC 0x0c09f764 */
if(!s->budget--) { s->failed_pc=0x0c09f764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f76a; }
goto P_0c09f766;
P_0c09f766: /* original a002, guest PC 0x0c09f766 */
if(!s->budget--) { s->failed_pc=0x0c09f766u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76e;
P_0c09f768: /* original f1bc, guest PC 0x0c09f768 */
if(!s->budget--) { s->failed_pc=0x0c09f768u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76a;
P_0c09f76a: /* original c719, guest PC 0x0c09f76a */
if(!s->budget--) { s->failed_pc=0x0c09f76au; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f76c;
P_0c09f76c: /* original f108, guest PC 0x0c09f76c */
if(!s->budget--) { s->failed_pc=0x0c09f76cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f76e;
P_0c09f76e: /* original f35c, guest PC 0x0c09f76e */
if(!s->budget--) { s->failed_pc=0x0c09f76eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09f770;
P_0c09f770: /* original f51c, guest PC 0x0c09f770 */
if(!s->budget--) { s->failed_pc=0x0c09f770u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c09f772;
P_0c09f772: /* original f530, guest PC 0x0c09f772 */
if(!s->budget--) { s->failed_pc=0x0c09f772u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c09f774;
P_0c09f774: /* original afdf, guest PC 0x0c09f774 */
if(!s->budget--) { s->failed_pc=0x0c09f774u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f736;
P_0c09f776: /* original f55a, guest PC 0x0c09f776 */
if(!s->budget--) { s->failed_pc=0x0c09f776u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f778;
P_0c09f778: /* original f52a, guest PC 0x0c09f778 */
if(!s->budget--) { s->failed_pc=0x0c09f778u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f77a;
P_0c09f77a: /* original f5f8, guest PC 0x0c09f77a */
if(!s->budget--) { s->failed_pc=0x0c09f77au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f77c;
P_0c09f77c: /* original f561, guest PC 0x0c09f77c */
if(!s->budget--) { s->failed_pc=0x0c09f77cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c09f77e;
P_0c09f77e: /* original f15c, guest PC 0x0c09f77e */
if(!s->budget--) { s->failed_pc=0x0c09f77eu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c09f780;
P_0c09f780: /* original f15d, guest PC 0x0c09f780 */
if(!s->budget--) { s->failed_pc=0x0c09f780u; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c09f782;
P_0c09f782: /* original f715, guest PC 0x0c09f782 */
if(!s->budget--) { s->failed_pc=0x0c09f782u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c09f784;
P_0c09f784: /* original 8b26, guest PC 0x0c09f784 */
if(!s->budget--) { s->failed_pc=0x0c09f784u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7d4; }
goto P_0c09f786;
P_0c09f786: /* original f815, guest PC 0x0c09f786 */
if(!s->budget--) { s->failed_pc=0x0c09f786u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c09f788;
P_0c09f788: /* original 8b08, guest PC 0x0c09f788 */
if(!s->budget--) { s->failed_pc=0x0c09f788u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f79c; }
goto P_0c09f78a;
P_0c09f78a: /* original f915, guest PC 0x0c09f78a */
if(!s->budget--) { s->failed_pc=0x0c09f78au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c09f78c;
P_0c09f78c: /* original 8923, guest PC 0x0c09f78c */
if(!s->budget--) { s->failed_pc=0x0c09f78cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7d6; }
goto P_0c09f78e;
P_0c09f78e: /* original f38d, guest PC 0x0c09f78e */
if(!s->budget--) { s->failed_pc=0x0c09f78eu; return 0; }
fr[3]=0;
goto P_0c09f790;
P_0c09f790: /* original f355, guest PC 0x0c09f790 */
if(!s->budget--) { s->failed_pc=0x0c09f790u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f792;
P_0c09f792: /* original 8901, guest PC 0x0c09f792 */
if(!s->budget--) { s->failed_pc=0x0c09f792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f798; }
goto P_0c09f794;
P_0c09f794: /* original a009, guest PC 0x0c09f794 */
if(!s->budget--) { s->failed_pc=0x0c09f794u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7aa;
P_0c09f796: /* original f5ac, guest PC 0x0c09f796 */
if(!s->budget--) { s->failed_pc=0x0c09f796u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f798;
P_0c09f798: /* original a007, guest PC 0x0c09f798 */
if(!s->budget--) { s->failed_pc=0x0c09f798u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7aa;
P_0c09f79a: /* original f5dc, guest PC 0x0c09f79a */
if(!s->budget--) { s->failed_pc=0x0c09f79au; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f79c;
P_0c09f79c: /* original f38d, guest PC 0x0c09f79c */
if(!s->budget--) { s->failed_pc=0x0c09f79cu; return 0; }
fr[3]=0;
goto P_0c09f79e;
P_0c09f79e: /* original f355, guest PC 0x0c09f79e */
if(!s->budget--) { s->failed_pc=0x0c09f79eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f7a0;
P_0c09f7a0: /* original 8901, guest PC 0x0c09f7a0 */
if(!s->budget--) { s->failed_pc=0x0c09f7a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7a6; }
goto P_0c09f7a2;
P_0c09f7a2: /* original a002, guest PC 0x0c09f7a2 */
if(!s->budget--) { s->failed_pc=0x0c09f7a2u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7aa;
P_0c09f7a4: /* original f5bc, guest PC 0x0c09f7a4 */
if(!s->budget--) { s->failed_pc=0x0c09f7a4u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7a6;
P_0c09f7a6: /* original c70a, guest PC 0x0c09f7a6 */
if(!s->budget--) { s->failed_pc=0x0c09f7a6u; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f7a8;
P_0c09f7a8: /* original f508, guest PC 0x0c09f7a8 */
if(!s->budget--) { s->failed_pc=0x0c09f7a8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f7aa;
P_0c09f7aa: /* original f36c, guest PC 0x0c09f7aa */
if(!s->budget--) { s->failed_pc=0x0c09f7aau; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09f7ac;
P_0c09f7ac: /* original f65c, guest PC 0x0c09f7ac */
if(!s->budget--) { s->failed_pc=0x0c09f7acu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09f7ae;
P_0c09f7ae: /* original f630, guest PC 0x0c09f7ae */
if(!s->budget--) { s->failed_pc=0x0c09f7aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c09f7b0;
P_0c09f7b0: /* original afe3, guest PC 0x0c09f7b0 */
if(!s->budget--) { s->failed_pc=0x0c09f7b0u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c09f77a;
P_0c09f7b2: /* original f66a, guest PC 0x0c09f7b2 */
if(!s->budget--) { s->failed_pc=0x0c09f7b2u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
if(!vf3_matrix_family(0x0c09f7b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f7b4u; return 0; } return 1;
P_0c09f7d4: /* original f62a, guest PC 0x0c09f7d4 */
if(!s->budget--) { s->failed_pc=0x0c09f7d4u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c09f7d6;
P_0c09f7d6: /* original e008, guest PC 0x0c09f7d6 */
if(!s->budget--) { s->failed_pc=0x0c09f7d6u; return 0; }
r[0]=0x00000008u;
goto P_0c09f7d8;
P_0c09f7d8: /* original f6f6, guest PC 0x0c09f7d8 */
if(!s->budget--) { s->failed_pc=0x0c09f7d8u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f7da;
P_0c09f7da: /* original f641, guest PC 0x0c09f7da */
if(!s->budget--) { s->failed_pc=0x0c09f7dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c09f7dc;
P_0c09f7dc: /* original f56c, guest PC 0x0c09f7dc */
if(!s->budget--) { s->failed_pc=0x0c09f7dcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09f7de;
P_0c09f7de: /* original f55d, guest PC 0x0c09f7de */
if(!s->budget--) { s->failed_pc=0x0c09f7deu; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c09f7e0;
P_0c09f7e0: /* original f755, guest PC 0x0c09f7e0 */
if(!s->budget--) { s->failed_pc=0x0c09f7e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09f7e2;
P_0c09f7e2: /* original 8b16, guest PC 0x0c09f7e2 */
if(!s->budget--) { s->failed_pc=0x0c09f7e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f812; }
goto P_0c09f7e4;
P_0c09f7e4: /* original f855, guest PC 0x0c09f7e4 */
if(!s->budget--) { s->failed_pc=0x0c09f7e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c09f7e6;
P_0c09f7e6: /* original 8b08, guest PC 0x0c09f7e6 */
if(!s->budget--) { s->failed_pc=0x0c09f7e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7fa; }
goto P_0c09f7e8;
P_0c09f7e8: /* original f955, guest PC 0x0c09f7e8 */
if(!s->budget--) { s->failed_pc=0x0c09f7e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c09f7ea;
P_0c09f7ea: /* original 8913, guest PC 0x0c09f7ea */
if(!s->budget--) { s->failed_pc=0x0c09f7eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f814; }
goto P_0c09f7ec;
P_0c09f7ec: /* original f38d, guest PC 0x0c09f7ec */
if(!s->budget--) { s->failed_pc=0x0c09f7ecu; return 0; }
fr[3]=0;
goto P_0c09f7ee;
P_0c09f7ee: /* original f365, guest PC 0x0c09f7ee */
if(!s->budget--) { s->failed_pc=0x0c09f7eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7f0;
P_0c09f7f0: /* original 8901, guest PC 0x0c09f7f0 */
if(!s->budget--) { s->failed_pc=0x0c09f7f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7f6; }
goto P_0c09f7f2;
P_0c09f7f2: /* original a009, guest PC 0x0c09f7f2 */
if(!s->budget--) { s->failed_pc=0x0c09f7f2u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f808;
P_0c09f7f4: /* original f5ac, guest PC 0x0c09f7f4 */
if(!s->budget--) { s->failed_pc=0x0c09f7f4u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7f6;
P_0c09f7f6: /* original a007, guest PC 0x0c09f7f6 */
if(!s->budget--) { s->failed_pc=0x0c09f7f6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f808;
P_0c09f7f8: /* original f5dc, guest PC 0x0c09f7f8 */
if(!s->budget--) { s->failed_pc=0x0c09f7f8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7fa;
P_0c09f7fa: /* original f38d, guest PC 0x0c09f7fa */
if(!s->budget--) { s->failed_pc=0x0c09f7fau; return 0; }
fr[3]=0;
goto P_0c09f7fc;
P_0c09f7fc: /* original f365, guest PC 0x0c09f7fc */
if(!s->budget--) { s->failed_pc=0x0c09f7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7fe;
P_0c09f7fe: /* original 8901, guest PC 0x0c09f7fe */
if(!s->budget--) { s->failed_pc=0x0c09f7feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f804; }
goto P_0c09f800;
P_0c09f800: /* original a002, guest PC 0x0c09f800 */
if(!s->budget--) { s->failed_pc=0x0c09f800u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f808;
P_0c09f802: /* original f5bc, guest PC 0x0c09f802 */
if(!s->budget--) { s->failed_pc=0x0c09f802u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f804;
P_0c09f804: /* original c733, guest PC 0x0c09f804 */
if(!s->budget--) { s->failed_pc=0x0c09f804u; return 0; }
r[0]=code_base|0x0009f8d4u;
goto P_0c09f806;
P_0c09f806: /* original f508, guest PC 0x0c09f806 */
if(!s->budget--) { s->failed_pc=0x0c09f806u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f808;
P_0c09f808: /* original f34c, guest PC 0x0c09f808 */
if(!s->budget--) { s->failed_pc=0x0c09f808u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09f80a;
P_0c09f80a: /* original f45c, guest PC 0x0c09f80a */
if(!s->budget--) { s->failed_pc=0x0c09f80au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09f80c;
P_0c09f80c: /* original f430, guest PC 0x0c09f80c */
if(!s->budget--) { s->failed_pc=0x0c09f80cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c09f80e;
P_0c09f80e: /* original afe2, guest PC 0x0c09f80e */
if(!s->budget--) { s->failed_pc=0x0c09f80eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f7d6;
P_0c09f810: /* original f44a, guest PC 0x0c09f810 */
if(!s->budget--) { s->failed_pc=0x0c09f810u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f812;
P_0c09f812: /* original f42a, guest PC 0x0c09f812 */
if(!s->budget--) { s->failed_pc=0x0c09f812u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09f814;
P_0c09f814: /* original 7f0c, guest PC 0x0c09f814 */
if(!s->budget--) { s->failed_pc=0x0c09f814u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f816;
P_0c09f816: /* original 000b, guest PC 0x0c09f816 */
if(!s->budget--) { s->failed_pc=0x0c09f816u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c09f818: /* original fdf9, guest PC 0x0c09f818 */
if(!s->budget--) { s->failed_pc=0x0c09f818u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c09f81au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f81au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
