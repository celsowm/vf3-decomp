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
int vf3_away_batch172_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ca338u: goto P_0c0ca338;
case 0x0c0ca33au: goto P_0c0ca33a;
case 0x0c0ca33cu: goto P_0c0ca33c;
case 0x0c0ca33eu: goto P_0c0ca33e;
case 0x0c0ca340u: goto P_0c0ca340;
case 0x0c0ca342u: goto P_0c0ca342;
case 0x0c0ca344u: goto P_0c0ca344;
case 0x0c0ca346u: goto P_0c0ca346;
case 0x0c0ca348u: goto P_0c0ca348;
case 0x0c0ca34au: goto P_0c0ca34a;
case 0x0c0ca38au: goto P_0c0ca38a;
case 0x0c0ca38cu: goto P_0c0ca38c;
case 0x0c0ca38eu: goto P_0c0ca38e;
case 0x0c0ca390u: goto P_0c0ca390;
case 0x0c0ca392u: goto P_0c0ca392;
case 0x0c0ca394u: goto P_0c0ca394;
case 0x0c0ca396u: goto P_0c0ca396;
case 0x0c0ca398u: goto P_0c0ca398;
case 0x0c0ca39au: goto P_0c0ca39a;
case 0x0c0ca39cu: goto P_0c0ca39c;
case 0x0c0ca39eu: goto P_0c0ca39e;
case 0x0c0ca3a0u: goto P_0c0ca3a0;
case 0x0c0ca3a2u: goto P_0c0ca3a2;
case 0x0c0ca3a4u: goto P_0c0ca3a4;
case 0x0c0ca3a6u: goto P_0c0ca3a6;
case 0x0c0ca3a8u: goto P_0c0ca3a8;
case 0x0c0ca3aau: goto P_0c0ca3aa;
case 0x0c0ca3acu: goto P_0c0ca3ac;
case 0x0c0ca3aeu: goto P_0c0ca3ae;
case 0x0c0ca3b0u: goto P_0c0ca3b0;
case 0x0c0ca3b2u: goto P_0c0ca3b2;
case 0x0c0ca3b4u: goto P_0c0ca3b4;
case 0x0c0ca3b6u: goto P_0c0ca3b6;
case 0x0c0ca3b8u: goto P_0c0ca3b8;
case 0x0c0ca3bau: goto P_0c0ca3ba;
case 0x0c0ca3bcu: goto P_0c0ca3bc;
case 0x0c0ca3beu: goto P_0c0ca3be;
case 0x0c0ca3c0u: goto P_0c0ca3c0;
case 0x0c0ca3c2u: goto P_0c0ca3c2;
case 0x0c0ca3c4u: goto P_0c0ca3c4;
case 0x0c0ca3c6u: goto P_0c0ca3c6;
case 0x0c0ca3c8u: goto P_0c0ca3c8;
case 0x0c0ca3cau: goto P_0c0ca3ca;
case 0x0c0ca3ccu: goto P_0c0ca3cc;
case 0x0c0ca3ceu: goto P_0c0ca3ce;
case 0x0c0ca3d0u: goto P_0c0ca3d0;
case 0x0c0ca3d2u: goto P_0c0ca3d2;
case 0x0c0ca3d4u: goto P_0c0ca3d4;
case 0x0c0ca3d6u: goto P_0c0ca3d6;
case 0x0c0ca3d8u: goto P_0c0ca3d8;
case 0x0c0ca3dau: goto P_0c0ca3da;
case 0x0c0ca3dcu: goto P_0c0ca3dc;
case 0x0c0ca3deu: goto P_0c0ca3de;
case 0x0c0ca3e0u: goto P_0c0ca3e0;
case 0x0c0ca3e2u: goto P_0c0ca3e2;
case 0x0c0ca3e4u: goto P_0c0ca3e4;
case 0x0c0ca3e6u: goto P_0c0ca3e6;
case 0x0c0ca3e8u: goto P_0c0ca3e8;
case 0x0c0ca3eau: goto P_0c0ca3ea;
case 0x0c0ca3ecu: goto P_0c0ca3ec;
case 0x0c0ca3eeu: goto P_0c0ca3ee;
case 0x0c0ca3f0u: goto P_0c0ca3f0;
case 0x0c0ca3f2u: goto P_0c0ca3f2;
case 0x0c0ca3f4u: goto P_0c0ca3f4;
case 0x0c0ca3f6u: goto P_0c0ca3f6;
case 0x0c0ca3f8u: goto P_0c0ca3f8;
case 0x0c0ca3fau: goto P_0c0ca3fa;
case 0x0c0ca3fcu: goto P_0c0ca3fc;
case 0x0c0ca3feu: goto P_0c0ca3fe;
case 0x0c0ca400u: goto P_0c0ca400;
case 0x0c0ca402u: goto P_0c0ca402;
case 0x0c0ca404u: goto P_0c0ca404;
case 0x0c0ca406u: goto P_0c0ca406;
case 0x0c0ca408u: goto P_0c0ca408;
case 0x0c0ca40au: goto P_0c0ca40a;
case 0x0c0ca40cu: goto P_0c0ca40c;
case 0x0c0ca40eu: goto P_0c0ca40e;
case 0x0c0ca410u: goto P_0c0ca410;
case 0x0c0ca412u: goto P_0c0ca412;
case 0x0c0ca414u: goto P_0c0ca414;
case 0x0c0ca416u: goto P_0c0ca416;
case 0x0c0ca418u: goto P_0c0ca418;
case 0x0c0ca41au: goto P_0c0ca41a;
case 0x0c0ca41cu: goto P_0c0ca41c;
case 0x0c0ca41eu: goto P_0c0ca41e;
case 0x0c0ca420u: goto P_0c0ca420;
case 0x0c0ca422u: goto P_0c0ca422;
case 0x0c0ca424u: goto P_0c0ca424;
case 0x0c0ca448u: goto P_0c0ca448;
case 0x0c0ca44au: goto P_0c0ca44a;
case 0x0c0ca44cu: goto P_0c0ca44c;
case 0x0c0ca44eu: goto P_0c0ca44e;
case 0x0c0ca450u: goto P_0c0ca450;
case 0x0c0ca452u: goto P_0c0ca452;
case 0x0c0ca454u: goto P_0c0ca454;
case 0x0c0ca456u: goto P_0c0ca456;
case 0x0c0ca458u: goto P_0c0ca458;
case 0x0c0ca45au: goto P_0c0ca45a;
case 0x0c0ca45cu: goto P_0c0ca45c;
case 0x0c0ca45eu: goto P_0c0ca45e;
case 0x0c0ca460u: goto P_0c0ca460;
case 0x0c0ca462u: goto P_0c0ca462;
case 0x0c0ca464u: goto P_0c0ca464;
case 0x0c0ca466u: goto P_0c0ca466;
case 0x0c0ca468u: goto P_0c0ca468;
case 0x0c0ca46au: goto P_0c0ca46a;
case 0x0c0ca46cu: goto P_0c0ca46c;
case 0x0c0ca46eu: goto P_0c0ca46e;
case 0x0c0ca470u: goto P_0c0ca470;
case 0x0c0ca472u: goto P_0c0ca472;
case 0x0c0ca474u: goto P_0c0ca474;
case 0x0c0ca476u: goto P_0c0ca476;
case 0x0c0ca478u: goto P_0c0ca478;
case 0x0c0ca47au: goto P_0c0ca47a;
case 0x0c0ca47cu: goto P_0c0ca47c;
case 0x0c0ca47eu: goto P_0c0ca47e;
case 0x0c0ca480u: goto P_0c0ca480;
case 0x0c0ca482u: goto P_0c0ca482;
case 0x0c0ca484u: goto P_0c0ca484;
case 0x0c0ca486u: goto P_0c0ca486;
case 0x0c0ca488u: goto P_0c0ca488;
case 0x0c0ca48au: goto P_0c0ca48a;
case 0x0c0ca48cu: goto P_0c0ca48c;
case 0x0c0ca48eu: goto P_0c0ca48e;
case 0x0c0ca490u: goto P_0c0ca490;
case 0x0c0ca492u: goto P_0c0ca492;
case 0x0c0ca494u: goto P_0c0ca494;
case 0x0c0ca496u: goto P_0c0ca496;
case 0x0c0ca498u: goto P_0c0ca498;
case 0x0c0ca49au: goto P_0c0ca49a;
case 0x0c0ca49cu: goto P_0c0ca49c;
case 0x0c0ca49eu: goto P_0c0ca49e;
case 0x0c0ca4a0u: goto P_0c0ca4a0;
case 0x0c0ca4a2u: goto P_0c0ca4a2;
case 0x0c0ca838u: goto P_0c0ca838;
case 0x0c0ca83au: goto P_0c0ca83a;
case 0x0c0ca83cu: goto P_0c0ca83c;
case 0x0c0ca83eu: goto P_0c0ca83e;
case 0x0c0ca840u: goto P_0c0ca840;
case 0x0c0ca842u: goto P_0c0ca842;
case 0x0c0ca844u: goto P_0c0ca844;
case 0x0c0ca846u: goto P_0c0ca846;
case 0x0c0ca848u: goto P_0c0ca848;
case 0x0c0ca84au: goto P_0c0ca84a;
case 0x0c0ca84cu: goto P_0c0ca84c;
case 0x0c0ca84eu: goto P_0c0ca84e;
case 0x0c0ca850u: goto P_0c0ca850;
case 0x0c0ca852u: goto P_0c0ca852;
case 0x0c0ca854u: goto P_0c0ca854;
case 0x0c0ca856u: goto P_0c0ca856;
case 0x0c0ca858u: goto P_0c0ca858;
case 0x0c0ca85au: goto P_0c0ca85a;
case 0x0c0ca85cu: goto P_0c0ca85c;
case 0x0c0ca85eu: goto P_0c0ca85e;
case 0x0c0ca860u: goto P_0c0ca860;
case 0x0c0ca862u: goto P_0c0ca862;
case 0x0c0ca864u: goto P_0c0ca864;
case 0x0c0ca866u: goto P_0c0ca866;
case 0x0c0ca868u: goto P_0c0ca868;
case 0x0c0ca86au: goto P_0c0ca86a;
case 0x0c0ca86cu: goto P_0c0ca86c;
case 0x0c0ca86eu: goto P_0c0ca86e;
case 0x0c0ca870u: goto P_0c0ca870;
case 0x0c0ca872u: goto P_0c0ca872;
case 0x0c0ca874u: goto P_0c0ca874;
case 0x0c0ca876u: goto P_0c0ca876;
case 0x0c0ca878u: goto P_0c0ca878;
case 0x0c0ca87au: goto P_0c0ca87a;
case 0x0c0ca87cu: goto P_0c0ca87c;
case 0x0c0ca87eu: goto P_0c0ca87e;
case 0x0c0ca880u: goto P_0c0ca880;
case 0x0c0ca882u: goto P_0c0ca882;
case 0x0c0ca884u: goto P_0c0ca884;
case 0x0c0ca886u: goto P_0c0ca886;
case 0x0c0ca888u: goto P_0c0ca888;
case 0x0c0ca88au: goto P_0c0ca88a;
case 0x0c0ca88cu: goto P_0c0ca88c;
case 0x0c0ca88eu: goto P_0c0ca88e;
case 0x0c0ca890u: goto P_0c0ca890;
case 0x0c0ca892u: goto P_0c0ca892;
case 0x0c0ca894u: goto P_0c0ca894;
case 0x0c0ca896u: goto P_0c0ca896;
case 0x0c0ca898u: goto P_0c0ca898;
case 0x0c0ca89au: goto P_0c0ca89a;
case 0x0c0ca89cu: goto P_0c0ca89c;
case 0x0c0ca89eu: goto P_0c0ca89e;
case 0x0c0ca8a0u: goto P_0c0ca8a0;
case 0x0c0ca8a2u: goto P_0c0ca8a2;
case 0x0c0ca8a4u: goto P_0c0ca8a4;
case 0x0c0ca8a6u: goto P_0c0ca8a6;
case 0x0c0ca8a8u: goto P_0c0ca8a8;
case 0x0c0ca8aau: goto P_0c0ca8aa;
case 0x0c0ca8acu: goto P_0c0ca8ac;
case 0x0c0ca8aeu: goto P_0c0ca8ae;
case 0x0c0ca8b0u: goto P_0c0ca8b0;
case 0x0c0ca8b2u: goto P_0c0ca8b2;
case 0x0c0ca8b4u: goto P_0c0ca8b4;
case 0x0c0ca8b6u: goto P_0c0ca8b6;
case 0x0c0ca8b8u: goto P_0c0ca8b8;
case 0x0c0ca8bau: goto P_0c0ca8ba;
case 0x0c0ca8bcu: goto P_0c0ca8bc;
case 0x0c0ca8beu: goto P_0c0ca8be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ca338: /* original 9075, guest PC 0x0c0ca338 */
if(!s->budget--) { s->failed_pc=0x0c0ca338u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca426u,2);
goto P_0c0ca33a;
P_0c0ca33a: /* original f358, guest PC 0x0c0ca33a */
if(!s->budget--) { s->failed_pc=0x0c0ca33au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c0ca33c;
P_0c0ca33c: /* original f437, guest PC 0x0c0ca33c */
if(!s->budget--) { s->failed_pc=0x0c0ca33cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ca33e;
P_0c0ca33e: /* original e004, guest PC 0x0c0ca33e */
if(!s->budget--) { s->failed_pc=0x0c0ca33eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ca340;
P_0c0ca340: /* original f356, guest PC 0x0c0ca340 */
if(!s->budget--) { s->failed_pc=0x0c0ca340u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0ca342;
P_0c0ca342: /* original 9071, guest PC 0x0c0ca342 */
if(!s->budget--) { s->failed_pc=0x0c0ca342u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca428u,2);
goto P_0c0ca344;
P_0c0ca344: /* original f34d, guest PC 0x0c0ca344 */
if(!s->budget--) { s->failed_pc=0x0c0ca344u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0ca346;
P_0c0ca346: /* original f437, guest PC 0x0c0ca346 */
if(!s->budget--) { s->failed_pc=0x0c0ca346u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ca348;
P_0c0ca348: /* original 000b, guest PC 0x0c0ca348 */
if(!s->budget--) { s->failed_pc=0x0c0ca348u; return 0; }
target=r[16];
r[0]=read(ram,r[5]+8,4);
s->pc=target; return ram->oob==0;
P_0c0ca34a: /* original 5052, guest PC 0x0c0ca34a */
if(!s->budget--) { s->failed_pc=0x0c0ca34au; return 0; }
r[0]=read(ram,r[5]+8,4);
if(!vf3_matrix_family(0x0c0ca34cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca34cu; return 0; } return 1;
P_0c0ca38a: /* original 2fe6, guest PC 0x0c0ca38a */
if(!s->budget--) { s->failed_pc=0x0c0ca38au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca38c;
P_0c0ca38c: /* original 6e43, guest PC 0x0c0ca38c */
if(!s->budget--) { s->failed_pc=0x0c0ca38cu; return 0; }
r[14]=r[4];
goto P_0c0ca38e;
P_0c0ca38e: /* original 2fd6, guest PC 0x0c0ca38e */
if(!s->budget--) { s->failed_pc=0x0c0ca38eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca390;
P_0c0ca390: /* original 6d53, guest PC 0x0c0ca390 */
if(!s->budget--) { s->failed_pc=0x0c0ca390u; return 0; }
r[13]=r[5];
goto P_0c0ca392;
P_0c0ca392: /* original 2fc6, guest PC 0x0c0ca392 */
if(!s->budget--) { s->failed_pc=0x0c0ca392u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca394;
P_0c0ca394: /* original e600, guest PC 0x0c0ca394 */
if(!s->budget--) { s->failed_pc=0x0c0ca394u; return 0; }
r[6]=0x00000000u;
goto P_0c0ca396;
P_0c0ca396: /* original 2fb6, guest PC 0x0c0ca396 */
if(!s->budget--) { s->failed_pc=0x0c0ca396u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca398;
P_0c0ca398: /* original ec1c, guest PC 0x0c0ca398 */
if(!s->budget--) { s->failed_pc=0x0c0ca398u; return 0; }
r[12]=0x0000001cu;
goto P_0c0ca39a;
P_0c0ca39a: /* original fffb, guest PC 0x0c0ca39a */
if(!s->budget--) { s->failed_pc=0x0c0ca39au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca39c;
P_0c0ca39c: /* original ffeb, guest PC 0x0c0ca39c */
if(!s->budget--) { s->failed_pc=0x0c0ca39cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ca39e;
P_0c0ca39e: /* original 9046, guest PC 0x0c0ca39e */
if(!s->budget--) { s->failed_pc=0x0c0ca39eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca42eu,2);
goto P_0c0ca3a0;
P_0c0ca3a0: /* original 4f22, guest PC 0x0c0ca3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca3a2;
P_0c0ca3a2: /* original 0bee, guest PC 0x0c0ca3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a2u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0ca3a4;
P_0c0ca3a4: /* original 70bc, guest PC 0x0c0ca3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a4u; return 0; }
r[0]+=0xffffffbcu;
goto P_0c0ca3a6;
P_0c0ca3a6: /* original 04ee, guest PC 0x0c0ca3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0ca3a8;
P_0c0ca3a8: /* original d524, guest PC 0x0c0ca3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3a8u; return 0; }
r[5]=read(ram,0x0c0ca43cu,4);
goto P_0c0ca3aa;
P_0c0ca3aa: /* original 7fec, guest PC 0x0c0ca3aa */
if(!s->budget--) { s->failed_pc=0x0c0ca3aau; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca3ac;
P_0c0ca3ac: /* original 1f44, guest PC 0x0c0ca3ac */
if(!s->budget--) { s->failed_pc=0x0c0ca3acu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0ca3ae;
P_0c0ca3ae: /* original 6753, guest PC 0x0c0ca3ae */
if(!s->budget--) { s->failed_pc=0x0c0ca3aeu; return 0; }
r[7]=r[5];
goto P_0c0ca3b0;
P_0c0ca3b0: /* original 6353, guest PC 0x0c0ca3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b0u; return 0; }
r[3]=r[5];
goto P_0c0ca3b2;
P_0c0ca3b2: /* original 23b8, guest PC 0x0c0ca3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0ca3b4;
P_0c0ca3b4: /* original 8b12, guest PC 0x0c0ca3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca3dc; }
goto P_0c0ca3b6;
P_0c0ca3b6: /* original 7601, guest PC 0x0c0ca3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b6u; return 0; }
r[6]+=0x00000001u;
goto P_0c0ca3b8;
P_0c0ca3b8: /* original 4521, guest PC 0x0c0ca3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3b8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0ca3ba;
P_0c0ca3ba: /* original 36c3, guest PC 0x0c0ca3ba */
if(!s->budget--) { s->failed_pc=0x0c0ca3bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[12])!=0);
goto P_0c0ca3bc;
P_0c0ca3bc: /* original 8ff8, guest PC 0x0c0ca3bc */
if(!s->budget--) { s->failed_pc=0x0c0ca3bcu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c0ca3b0; }
goto P_0c0ca3c0;
P_0c0ca3be: /* original 740c, guest PC 0x0c0ca3be */
if(!s->budget--) { s->failed_pc=0x0c0ca3beu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ca3c0;
P_0c0ca3c0: /* original 9036, guest PC 0x0c0ca3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca430u,2);
goto P_0c0ca3c2;
P_0c0ca3c2: /* original e61a, guest PC 0x0c0ca3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c2u; return 0; }
r[6]=0x0000001au;
goto P_0c0ca3c4;
P_0c0ca3c4: /* original e500, guest PC 0x0c0ca3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c4u; return 0; }
r[5]=0x00000000u;
goto P_0c0ca3c6;
P_0c0ca3c6: /* original 02ee, guest PC 0x0c0ca3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ca3c8;
P_0c0ca3c8: /* original 2f22, guest PC 0x0c0ca3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3c8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ca3ca;
P_0c0ca3ca: /* original 54f4, guest PC 0x0c0ca3ca */
if(!s->budget--) { s->failed_pc=0x0c0ca3cau; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0ca3cc;
P_0c0ca3cc: /* original 63f2, guest PC 0x0c0ca3cc */
if(!s->budget--) { s->failed_pc=0x0c0ca3ccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca3ce;
P_0c0ca3ce: /* original 2378, guest PC 0x0c0ca3ce */
if(!s->budget--) { s->failed_pc=0x0c0ca3ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0ca3d0;
P_0c0ca3d0: /* original 8b04, guest PC 0x0c0ca3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca3dc; }
goto P_0c0ca3d2;
P_0c0ca3d2: /* original 7501, guest PC 0x0c0ca3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0ca3d4;
P_0c0ca3d4: /* original 4721, guest PC 0x0c0ca3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]=(uint32_t)((int32_t)r[7]>>1);
goto P_0c0ca3d6;
P_0c0ca3d6: /* original 3563, guest PC 0x0c0ca3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0ca3d8;
P_0c0ca3d8: /* original 8ff8, guest PC 0x0c0ca3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3d8u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c0ca3cc; }
goto P_0c0ca3dc;
P_0c0ca3da: /* original 740c, guest PC 0x0c0ca3da */
if(!s->budget--) { s->failed_pc=0x0c0ca3dau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0ca3dc;
P_0c0ca3dc: /* original d315, guest PC 0x0c0ca3dc */
if(!s->budget--) { s->failed_pc=0x0c0ca3dcu; return 0; }
r[3]=read(ram,0x0c0ca434u,4);
goto P_0c0ca3de;
P_0c0ca3de: /* original e008, guest PC 0x0c0ca3de */
if(!s->budget--) { s->failed_pc=0x0c0ca3deu; return 0; }
r[0]=0x00000008u;
goto P_0c0ca3e0;
P_0c0ca3e0: /* original ff46, guest PC 0x0c0ca3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e0u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c0ca3e2;
P_0c0ca3e2: /* original 6030, guest PC 0x0c0ca3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0ca3e4;
P_0c0ca3e4: /* original 9c25, guest PC 0x0c0ca3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca432u,2);
goto P_0c0ca3e6;
P_0c0ca3e6: /* original 600c, guest PC 0x0c0ca3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca3e8;
P_0c0ca3e8: /* original fe48, guest PC 0x0c0ca3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3e8u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
goto P_0c0ca3ea;
P_0c0ca3ea: /* original c90f, guest PC 0x0c0ca3ea */
if(!s->budget--) { s->failed_pc=0x0c0ca3eau; return 0; }
r[0]&=15u;
goto P_0c0ca3ec;
P_0c0ca3ec: /* original ff4d, guest PC 0x0c0ca3ec */
if(!s->budget--) { s->failed_pc=0x0c0ca3ecu; return 0; }
fr[15]^=0x80000000u;
goto P_0c0ca3ee;
P_0c0ca3ee: /* original 880f, guest PC 0x0c0ca3ee */
if(!s->budget--) { s->failed_pc=0x0c0ca3eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ca3f0;
P_0c0ca3f0: /* original 8d2a, guest PC 0x0c0ca3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f0u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0ca448; }
goto P_0c0ca3f4;
P_0c0ca3f2: /* original 2f02, guest PC 0x0c0ca3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0ca3f4;
P_0c0ca3f4: /* original 64f3, guest PC 0x0c0ca3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f4u; return 0; }
r[4]=r[15];
goto P_0c0ca3f6;
P_0c0ca3f6: /* original 65f3, guest PC 0x0c0ca3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f6u; return 0; }
r[5]=r[15];
goto P_0c0ca3f8;
P_0c0ca3f8: /* original d111, guest PC 0x0c0ca3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca3f8u; return 0; }
r[1]=read(ram,0x0c0ca440u,4);
goto P_0c0ca3fa;
P_0c0ca3fa: /* original 66f3, guest PC 0x0c0ca3fa */
if(!s->budget--) { s->failed_pc=0x0c0ca3fau; return 0; }
r[6]=r[15];
goto P_0c0ca3fc;
P_0c0ca3fc: /* original 7404, guest PC 0x0c0ca3fc */
if(!s->budget--) { s->failed_pc=0x0c0ca3fcu; return 0; }
r[4]+=0x00000004u;
goto P_0c0ca3fe;
P_0c0ca3fe: /* original f5fc, guest PC 0x0c0ca3fe */
if(!s->budget--) { s->failed_pc=0x0c0ca3feu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0ca400;
P_0c0ca400: /* original 67f3, guest PC 0x0c0ca400 */
if(!s->budget--) { s->failed_pc=0x0c0ca400u; return 0; }
r[7]=r[15];
goto P_0c0ca402;
P_0c0ca402: /* original 760c, guest PC 0x0c0ca402 */
if(!s->budget--) { s->failed_pc=0x0c0ca402u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0ca404;
P_0c0ca404: /* original 7508, guest PC 0x0c0ca404 */
if(!s->budget--) { s->failed_pc=0x0c0ca404u; return 0; }
r[5]+=0x00000008u;
goto P_0c0ca406;
P_0c0ca406: /* original 410b, guest PC 0x0c0ca406 */
if(!s->budget--) { s->failed_pc=0x0c0ca406u; return 0; }
target=r[1];
r[16]=code_base|0x0c0ca40au;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca40au) { target=s->pc; goto dispatch; }
goto P_0c0ca40a;
P_0c0ca408: /* original f4ec, guest PC 0x0c0ca408 */
if(!s->budget--) { s->failed_pc=0x0c0ca408u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0ca40a;
P_0c0ca40a: /* original 63f2, guest PC 0x0c0ca40a */
if(!s->budget--) { s->failed_pc=0x0c0ca40au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca40c;
P_0c0ca40c: /* original d40d, guest PC 0x0c0ca40c */
if(!s->budget--) { s->failed_pc=0x0c0ca40cu; return 0; }
r[4]=read(ram,0x0c0ca444u,4);
goto P_0c0ca40e;
P_0c0ca40e: /* original 633b, guest PC 0x0c0ca40e */
if(!s->budget--) { s->failed_pc=0x0c0ca40eu; return 0; }
r[3]=0u-r[3];
goto P_0c0ca410;
P_0c0ca410: /* original 4311, guest PC 0x0c0ca410 */
if(!s->budget--) { s->failed_pc=0x0c0ca410u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0ca412;
P_0c0ca412: /* original 8d04, guest PC 0x0c0ca412 */
if(!s->budget--) { s->failed_pc=0x0c0ca412u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c0ca41e; }
goto P_0c0ca416;
P_0c0ca414: /* original 2f32, guest PC 0x0c0ca414 */
if(!s->budget--) { s->failed_pc=0x0c0ca414u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca416;
P_0c0ca416: /* original 61f2, guest PC 0x0c0ca416 */
if(!s->budget--) { s->failed_pc=0x0c0ca416u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0ca418;
P_0c0ca418: /* original 314c, guest PC 0x0c0ca418 */
if(!s->budget--) { s->failed_pc=0x0c0ca418u; return 0; }
r[1]+=r[4];
goto P_0c0ca41a;
P_0c0ca41a: /* original a01d, guest PC 0x0c0ca41a */
if(!s->budget--) { s->failed_pc=0x0c0ca41au; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ca458;
P_0c0ca41c: /* original 2f12, guest PC 0x0c0ca41c */
if(!s->budget--) { s->failed_pc=0x0c0ca41cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ca41e;
P_0c0ca41e: /* original 62f2, guest PC 0x0c0ca41e */
if(!s->budget--) { s->failed_pc=0x0c0ca41eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ca420;
P_0c0ca420: /* original 3248, guest PC 0x0c0ca420 */
if(!s->budget--) { s->failed_pc=0x0c0ca420u; return 0; }
r[2]-=r[4];
goto P_0c0ca422;
P_0c0ca422: /* original a019, guest PC 0x0c0ca422 */
if(!s->budget--) { s->failed_pc=0x0c0ca422u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ca458;
P_0c0ca424: /* original 2f22, guest PC 0x0c0ca424 */
if(!s->budget--) { s->failed_pc=0x0c0ca424u; return 0; }
write(ram,r[15],r[2],4);
if(!vf3_matrix_family(0x0c0ca426u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca426u; return 0; } return 1;
P_0c0ca448: /* original d249, guest PC 0x0c0ca448 */
if(!s->budget--) { s->failed_pc=0x0c0ca448u; return 0; }
r[2]=read(ram,0x0c0ca570u,4);
goto P_0c0ca44a;
P_0c0ca44a: /* original f5ec, guest PC 0x0c0ca44a */
if(!s->budget--) { s->failed_pc=0x0c0ca44au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0ca44c;
P_0c0ca44c: /* original 420b, guest PC 0x0c0ca44c */
if(!s->budget--) { s->failed_pc=0x0c0ca44cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ca450u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca450u) { target=s->pc; goto dispatch; }
goto P_0c0ca450;
P_0c0ca44e: /* original f4fc, guest PC 0x0c0ca44e */
if(!s->budget--) { s->failed_pc=0x0c0ca44eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ca450;
P_0c0ca450: /* original 600f, guest PC 0x0c0ca450 */
if(!s->budget--) { s->failed_pc=0x0c0ca450u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ca452;
P_0c0ca452: /* original 6303, guest PC 0x0c0ca452 */
if(!s->budget--) { s->failed_pc=0x0c0ca452u; return 0; }
r[3]=r[0];
goto P_0c0ca454;
P_0c0ca454: /* original 33c8, guest PC 0x0c0ca454 */
if(!s->budget--) { s->failed_pc=0x0c0ca454u; return 0; }
r[3]-=r[12];
goto P_0c0ca456;
P_0c0ca456: /* original 2f32, guest PC 0x0c0ca456 */
if(!s->budget--) { s->failed_pc=0x0c0ca456u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca458;
P_0c0ca458: /* original 64f2, guest PC 0x0c0ca458 */
if(!s->budget--) { s->failed_pc=0x0c0ca458u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ca45a;
P_0c0ca45a: /* original d346, guest PC 0x0c0ca45a */
if(!s->budget--) { s->failed_pc=0x0c0ca45au; return 0; }
r[3]=read(ram,0x0c0ca574u,4);
goto P_0c0ca45c;
P_0c0ca45c: /* original 34cc, guest PC 0x0c0ca45c */
if(!s->budget--) { s->failed_pc=0x0c0ca45cu; return 0; }
r[4]+=r[12];
goto P_0c0ca45e;
P_0c0ca45e: /* original 430b, guest PC 0x0c0ca45e */
if(!s->budget--) { s->failed_pc=0x0c0ca45eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ca462u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca462u) { target=s->pc; goto dispatch; }
goto P_0c0ca462;
P_0c0ca460: /* original 644f, guest PC 0x0c0ca460 */
if(!s->budget--) { s->failed_pc=0x0c0ca460u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ca462;
P_0c0ca462: /* original e008, guest PC 0x0c0ca462 */
if(!s->budget--) { s->failed_pc=0x0c0ca462u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca464;
P_0c0ca464: /* original ff07, guest PC 0x0c0ca464 */
if(!s->budget--) { s->failed_pc=0x0c0ca464u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ca466;
P_0c0ca466: /* original 64f2, guest PC 0x0c0ca466 */
if(!s->budget--) { s->failed_pc=0x0c0ca466u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0ca468;
P_0c0ca468: /* original d343, guest PC 0x0c0ca468 */
if(!s->budget--) { s->failed_pc=0x0c0ca468u; return 0; }
r[3]=read(ram,0x0c0ca578u,4);
goto P_0c0ca46a;
P_0c0ca46a: /* original 34cc, guest PC 0x0c0ca46a */
if(!s->budget--) { s->failed_pc=0x0c0ca46au; return 0; }
r[4]+=r[12];
goto P_0c0ca46c;
P_0c0ca46c: /* original 430b, guest PC 0x0c0ca46c */
if(!s->budget--) { s->failed_pc=0x0c0ca46cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ca470u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca470u) { target=s->pc; goto dispatch; }
goto P_0c0ca470;
P_0c0ca46e: /* original 644f, guest PC 0x0c0ca46e */
if(!s->budget--) { s->failed_pc=0x0c0ca46eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ca470;
P_0c0ca470: /* original e004, guest PC 0x0c0ca470 */
if(!s->budget--) { s->failed_pc=0x0c0ca470u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca472;
P_0c0ca472: /* original 65d3, guest PC 0x0c0ca472 */
if(!s->budget--) { s->failed_pc=0x0c0ca472u; return 0; }
r[5]=r[13];
goto P_0c0ca474;
P_0c0ca474: /* original ff07, guest PC 0x0c0ca474 */
if(!s->budget--) { s->failed_pc=0x0c0ca474u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ca476;
P_0c0ca476: /* original c741, guest PC 0x0c0ca476 */
if(!s->budget--) { s->failed_pc=0x0c0ca476u; return 0; }
r[0]=code_base|0x000ca57cu;
goto P_0c0ca478;
P_0c0ca478: /* original f408, guest PC 0x0c0ca478 */
if(!s->budget--) { s->failed_pc=0x0c0ca478u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ca47a;
P_0c0ca47a: /* original e008, guest PC 0x0c0ca47a */
if(!s->budget--) { s->failed_pc=0x0c0ca47au; return 0; }
r[0]=0x00000008u;
goto P_0c0ca47c;
P_0c0ca47c: /* original f30c, guest PC 0x0c0ca47c */
if(!s->budget--) { s->failed_pc=0x0c0ca47cu; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ca47e;
P_0c0ca47e: /* original f342, guest PC 0x0c0ca47e */
if(!s->budget--) { s->failed_pc=0x0c0ca47eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ca480;
P_0c0ca480: /* original fd3a, guest PC 0x0c0ca480 */
if(!s->budget--) { s->failed_pc=0x0c0ca480u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0ca482;
P_0c0ca482: /* original f3f6, guest PC 0x0c0ca482 */
if(!s->budget--) { s->failed_pc=0x0c0ca482u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca484;
P_0c0ca484: /* original e004, guest PC 0x0c0ca484 */
if(!s->budget--) { s->failed_pc=0x0c0ca484u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca486;
P_0c0ca486: /* original f342, guest PC 0x0c0ca486 */
if(!s->budget--) { s->failed_pc=0x0c0ca486u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ca488;
P_0c0ca488: /* original fd37, guest PC 0x0c0ca488 */
if(!s->budget--) { s->failed_pc=0x0c0ca488u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0ca48a;
P_0c0ca48a: /* original 63f2, guest PC 0x0c0ca48a */
if(!s->budget--) { s->failed_pc=0x0c0ca48au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca48c;
P_0c0ca48c: /* original 1d32, guest PC 0x0c0ca48c */
if(!s->budget--) { s->failed_pc=0x0c0ca48cu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0ca48e;
P_0c0ca48e: /* original bf53, guest PC 0x0c0ca48e */
if(!s->budget--) { s->failed_pc=0x0c0ca48eu; return 0; }
target=code_base|0x0c0ca338u; r[16]=code_base|0x0c0ca492u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca492u) { target=s->pc; goto dispatch; }
goto P_0c0ca492;
P_0c0ca490: /* original 64e3, guest PC 0x0c0ca490 */
if(!s->budget--) { s->failed_pc=0x0c0ca490u; return 0; }
r[4]=r[14];
goto P_0c0ca492;
P_0c0ca492: /* original 7f14, guest PC 0x0c0ca492 */
if(!s->budget--) { s->failed_pc=0x0c0ca492u; return 0; }
r[15]+=0x00000014u;
goto P_0c0ca494;
P_0c0ca494: /* original 4f26, guest PC 0x0c0ca494 */
if(!s->budget--) { s->failed_pc=0x0c0ca494u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca496;
P_0c0ca496: /* original fef9, guest PC 0x0c0ca496 */
if(!s->budget--) { s->failed_pc=0x0c0ca496u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca498;
P_0c0ca498: /* original fff9, guest PC 0x0c0ca498 */
if(!s->budget--) { s->failed_pc=0x0c0ca498u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca49a;
P_0c0ca49a: /* original 6bf6, guest PC 0x0c0ca49a */
if(!s->budget--) { s->failed_pc=0x0c0ca49au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ca49c;
P_0c0ca49c: /* original 6cf6, guest PC 0x0c0ca49c */
if(!s->budget--) { s->failed_pc=0x0c0ca49cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ca49e;
P_0c0ca49e: /* original 6df6, guest PC 0x0c0ca49e */
if(!s->budget--) { s->failed_pc=0x0c0ca49eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca4a0;
P_0c0ca4a0: /* original 000b, guest PC 0x0c0ca4a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca4a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca4a2: /* original 6ef6, guest PC 0x0c0ca4a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca4a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ca4a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca4a4u; return 0; } return 1;
P_0c0ca838: /* original fffb, guest PC 0x0c0ca838 */
if(!s->budget--) { s->failed_pc=0x0c0ca838u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca83a;
P_0c0ca83a: /* original c734, guest PC 0x0c0ca83a */
if(!s->budget--) { s->failed_pc=0x0c0ca83au; return 0; }
r[0]=code_base|0x000ca90cu;
goto P_0c0ca83c;
P_0c0ca83c: /* original f548, guest PC 0x0c0ca83c */
if(!s->budget--) { s->failed_pc=0x0c0ca83cu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c0ca83e;
P_0c0ca83e: /* original f458, guest PC 0x0c0ca83e */
if(!s->budget--) { s->failed_pc=0x0c0ca83eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c0ca840;
P_0c0ca840: /* original f65c, guest PC 0x0c0ca840 */
if(!s->budget--) { s->failed_pc=0x0c0ca840u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0ca842;
P_0c0ca842: /* original f652, guest PC 0x0c0ca842 */
if(!s->budget--) { s->failed_pc=0x0c0ca842u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0ca844;
P_0c0ca844: /* original f74c, guest PC 0x0c0ca844 */
if(!s->budget--) { s->failed_pc=0x0c0ca844u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0ca846;
P_0c0ca846: /* original f742, guest PC 0x0c0ca846 */
if(!s->budget--) { s->failed_pc=0x0c0ca846u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0ca848;
P_0c0ca848: /* original f39d, guest PC 0x0c0ca848 */
if(!s->budget--) { s->failed_pc=0x0c0ca848u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0ca84a;
P_0c0ca84a: /* original f868, guest PC 0x0c0ca84a */
if(!s->budget--) { s->failed_pc=0x0c0ca84au; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c0ca84c;
P_0c0ca84c: /* original ff6c, guest PC 0x0c0ca84c */
if(!s->budget--) { s->failed_pc=0x0c0ca84cu; return 0; }
vf3_matrix_move(s,15,6);
goto P_0c0ca84e;
P_0c0ca84e: /* original ff30, guest PC 0x0c0ca84e */
if(!s->budget--) { s->failed_pc=0x0c0ca84eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0ca850;
P_0c0ca850: /* original f96c, guest PC 0x0c0ca850 */
if(!s->budget--) { s->failed_pc=0x0c0ca850u; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c0ca852;
P_0c0ca852: /* original f972, guest PC 0x0c0ca852 */
if(!s->budget--) { s->failed_pc=0x0c0ca852u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'*');
goto P_0c0ca854;
P_0c0ca854: /* original f781, guest PC 0x0c0ca854 */
if(!s->budget--) { s->failed_pc=0x0c0ca854u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c0ca856;
P_0c0ca856: /* original f108, guest PC 0x0c0ca856 */
if(!s->budget--) { s->failed_pc=0x0c0ca856u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0ca858;
P_0c0ca858: /* original f6fc, guest PC 0x0c0ca858 */
if(!s->budget--) { s->failed_pc=0x0c0ca858u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0ca85a;
P_0c0ca85a: /* original f672, guest PC 0x0c0ca85a */
if(!s->budget--) { s->failed_pc=0x0c0ca85au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0ca85c;
P_0c0ca85c: /* original f26c, guest PC 0x0c0ca85c */
if(!s->budget--) { s->failed_pc=0x0c0ca85cu; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ca85e;
P_0c0ca85e: /* original f69c, guest PC 0x0c0ca85e */
if(!s->budget--) { s->failed_pc=0x0c0ca85eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c0ca860;
P_0c0ca860: /* original f621, guest PC 0x0c0ca860 */
if(!s->budget--) { s->failed_pc=0x0c0ca860u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c0ca862;
P_0c0ca862: /* original f165, guest PC 0x0c0ca862 */
if(!s->budget--) { s->failed_pc=0x0c0ca862u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[6]))!=0);
goto P_0c0ca864;
P_0c0ca864: /* original 8b01, guest PC 0x0c0ca864 */
if(!s->budget--) { s->failed_pc=0x0c0ca864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca86a; }
goto P_0c0ca866;
P_0c0ca866: /* original a002, guest PC 0x0c0ca866 */
if(!s->budget--) { s->failed_pc=0x0c0ca866u; return 0; }
fr[8]=0;
goto P_0c0ca86e;
P_0c0ca868: /* original f88d, guest PC 0x0c0ca868 */
if(!s->budget--) { s->failed_pc=0x0c0ca868u; return 0; }
fr[8]=0;
goto P_0c0ca86a;
P_0c0ca86a: /* original f86c, guest PC 0x0c0ca86a */
if(!s->budget--) { s->failed_pc=0x0c0ca86au; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c0ca86c;
P_0c0ca86c: /* original f86d, guest PC 0x0c0ca86c */
if(!s->budget--) { s->failed_pc=0x0c0ca86cu; return 0; }
fr[8]=vf3_fpu_sqrt(fr[8],r[18]);
goto P_0c0ca86e;
P_0c0ca86e: /* original f65c, guest PC 0x0c0ca86e */
if(!s->budget--) { s->failed_pc=0x0c0ca86eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0ca870;
P_0c0ca870: /* original f642, guest PC 0x0c0ca870 */
if(!s->budget--) { s->failed_pc=0x0c0ca870u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0ca872;
P_0c0ca872: /* original f94c, guest PC 0x0c0ca872 */
if(!s->budget--) { s->failed_pc=0x0c0ca872u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c0ca874;
P_0c0ca874: /* original f05c, guest PC 0x0c0ca874 */
if(!s->budget--) { s->failed_pc=0x0c0ca874u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ca876;
P_0c0ca876: /* original f76c, guest PC 0x0c0ca876 */
if(!s->budget--) { s->failed_pc=0x0c0ca876u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c0ca878;
P_0c0ca878: /* original f68c, guest PC 0x0c0ca878 */
if(!s->budget--) { s->failed_pc=0x0c0ca878u; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c0ca87a;
P_0c0ca87a: /* original f74d, guest PC 0x0c0ca87a */
if(!s->budget--) { s->failed_pc=0x0c0ca87au; return 0; }
fr[7]^=0x80000000u;
goto P_0c0ca87c;
P_0c0ca87c: /* original f670, guest PC 0x0c0ca87c */
if(!s->budget--) { s->failed_pc=0x0c0ca87cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c0ca87e;
P_0c0ca87e: /* original f781, guest PC 0x0c0ca87e */
if(!s->budget--) { s->failed_pc=0x0c0ca87eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c0ca880;
P_0c0ca880: /* original f6f3, guest PC 0x0c0ca880 */
if(!s->budget--) { s->failed_pc=0x0c0ca880u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'/');
goto P_0c0ca882;
P_0c0ca882: /* original f7f3, guest PC 0x0c0ca882 */
if(!s->budget--) { s->failed_pc=0x0c0ca882u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'/');
goto P_0c0ca884;
P_0c0ca884: /* original f96e, guest PC 0x0c0ca884 */
if(!s->budget--) { s->failed_pc=0x0c0ca884u; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[6],fr[9],r[18]);
goto P_0c0ca886;
P_0c0ca886: /* original f46a, guest PC 0x0c0ca886 */
if(!s->budget--) { s->failed_pc=0x0c0ca886u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c0ca888;
P_0c0ca888: /* original f47e, guest PC 0x0c0ca888 */
if(!s->budget--) { s->failed_pc=0x0c0ca888u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[7],fr[4],r[18]);
goto P_0c0ca88a;
P_0c0ca88a: /* original f59a, guest PC 0x0c0ca88a */
if(!s->budget--) { s->failed_pc=0x0c0ca88au; return 0; }
vf3_matrix_store(s,ram,9,r[5]);
goto P_0c0ca88c;
P_0c0ca88c: /* original f67a, guest PC 0x0c0ca88c */
if(!s->budget--) { s->failed_pc=0x0c0ca88cu; return 0; }
vf3_matrix_store(s,ram,7,r[6]);
goto P_0c0ca88e;
P_0c0ca88e: /* original f74a, guest PC 0x0c0ca88e */
if(!s->budget--) { s->failed_pc=0x0c0ca88eu; return 0; }
vf3_matrix_store(s,ram,4,r[7]);
goto P_0c0ca890;
P_0c0ca890: /* original 000b, guest PC 0x0c0ca890 */
if(!s->budget--) { s->failed_pc=0x0c0ca890u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c0ca892: /* original fff9, guest PC 0x0c0ca892 */
if(!s->budget--) { s->failed_pc=0x0c0ca892u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ca894;
P_0c0ca894: /* original f048, guest PC 0x0c0ca894 */
if(!s->budget--) { s->failed_pc=0x0c0ca894u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
goto P_0c0ca896;
P_0c0ca896: /* original c71d, guest PC 0x0c0ca896 */
if(!s->budget--) { s->failed_pc=0x0c0ca896u; return 0; }
r[0]=code_base|0x000ca90cu;
goto P_0c0ca898;
P_0c0ca898: /* original f30c, guest PC 0x0c0ca898 */
if(!s->budget--) { s->failed_pc=0x0c0ca898u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ca89a;
P_0c0ca89a: /* original f302, guest PC 0x0c0ca89a */
if(!s->budget--) { s->failed_pc=0x0c0ca89au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c0ca89c;
P_0c0ca89c: /* original f43a, guest PC 0x0c0ca89c */
if(!s->budget--) { s->failed_pc=0x0c0ca89cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c0ca89e;
P_0c0ca89e: /* original f268, guest PC 0x0c0ca89e */
if(!s->budget--) { s->failed_pc=0x0c0ca89eu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0ca8a0;
P_0c0ca8a0: /* original f231, guest PC 0x0c0ca8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8a0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0ca8a2;
P_0c0ca8a2: /* original f42a, guest PC 0x0c0ca8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8a2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0ca8a4;
P_0c0ca8a4: /* original f42c, guest PC 0x0c0ca8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8a4u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0ca8a6;
P_0c0ca8a6: /* original f208, guest PC 0x0c0ca8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8a6u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ca8a8;
P_0c0ca8a8: /* original f245, guest PC 0x0c0ca8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0ca8aa;
P_0c0ca8aa: /* original 8b01, guest PC 0x0c0ca8aa */
if(!s->budget--) { s->failed_pc=0x0c0ca8aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca8b0; }
goto P_0c0ca8ac;
P_0c0ca8ac: /* original a002, guest PC 0x0c0ca8ac */
if(!s->budget--) { s->failed_pc=0x0c0ca8acu; return 0; }
fr[3]=0;
goto P_0c0ca8b4;
P_0c0ca8ae: /* original f38d, guest PC 0x0c0ca8ae */
if(!s->budget--) { s->failed_pc=0x0c0ca8aeu; return 0; }
fr[3]=0;
goto P_0c0ca8b0;
P_0c0ca8b0: /* original f34c, guest PC 0x0c0ca8b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8b0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ca8b2;
P_0c0ca8b2: /* original f36d, guest PC 0x0c0ca8b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8b2u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c0ca8b4;
P_0c0ca8b4: /* original f53a, guest PC 0x0c0ca8b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8b4u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0ca8b6;
P_0c0ca8b6: /* original f34d, guest PC 0x0c0ca8b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8b6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0ca8b8;
P_0c0ca8b8: /* original f73a, guest PC 0x0c0ca8b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8b8u; return 0; }
vf3_matrix_store(s,ram,3,r[7]);
goto P_0c0ca8ba;
P_0c0ca8ba: /* original f40a, guest PC 0x0c0ca8ba */
if(!s->budget--) { s->failed_pc=0x0c0ca8bau; return 0; }
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0ca8bc;
P_0c0ca8bc: /* original 000b, guest PC 0x0c0ca8bc */
if(!s->budget--) { s->failed_pc=0x0c0ca8bcu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,0,r[6]);
s->pc=target; return ram->oob==0;
P_0c0ca8be: /* original f60a, guest PC 0x0c0ca8be */
if(!s->budget--) { s->failed_pc=0x0c0ca8beu; return 0; }
vf3_matrix_store(s,ram,0,r[6]);
return vf3_matrix_family(0x0c0ca8c0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
