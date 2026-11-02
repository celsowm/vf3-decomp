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
int vf3_away_batch2_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03f2d0u: goto P_0c03f2d0;
case 0x0c03f2d2u: goto P_0c03f2d2;
case 0x0c03f2d4u: goto P_0c03f2d4;
case 0x0c03f2d6u: goto P_0c03f2d6;
case 0x0c03f2d8u: goto P_0c03f2d8;
case 0x0c03f2dau: goto P_0c03f2da;
case 0x0c03f2dcu: goto P_0c03f2dc;
case 0x0c03f2deu: goto P_0c03f2de;
case 0x0c03f2e0u: goto P_0c03f2e0;
case 0x0c03f2e2u: goto P_0c03f2e2;
case 0x0c03f2e4u: goto P_0c03f2e4;
case 0x0c03f2e6u: goto P_0c03f2e6;
case 0x0c03f2e8u: goto P_0c03f2e8;
case 0x0c03f2eau: goto P_0c03f2ea;
case 0x0c03f2ecu: goto P_0c03f2ec;
case 0x0c03f2eeu: goto P_0c03f2ee;
case 0x0c03f2f0u: goto P_0c03f2f0;
case 0x0c03f350u: goto P_0c03f350;
case 0x0c03f352u: goto P_0c03f352;
case 0x0c03f354u: goto P_0c03f354;
case 0x0c03f356u: goto P_0c03f356;
case 0x0c03f358u: goto P_0c03f358;
case 0x0c03f35au: goto P_0c03f35a;
case 0x0c03f35cu: goto P_0c03f35c;
case 0x0c03f35eu: goto P_0c03f35e;
case 0x0c03f360u: goto P_0c03f360;
case 0x0c03f362u: goto P_0c03f362;
case 0x0c03f364u: goto P_0c03f364;
case 0x0c03f366u: goto P_0c03f366;
case 0x0c03f368u: goto P_0c03f368;
case 0x0c03f36au: goto P_0c03f36a;
case 0x0c03f36cu: goto P_0c03f36c;
case 0x0c03f36eu: goto P_0c03f36e;
case 0x0c03f370u: goto P_0c03f370;
case 0x0c03f372u: goto P_0c03f372;
case 0x0c03f374u: goto P_0c03f374;
case 0x0c03f376u: goto P_0c03f376;
case 0x0c03f378u: goto P_0c03f378;
case 0x0c03f37au: goto P_0c03f37a;
case 0x0c03f37cu: goto P_0c03f37c;
case 0x0c03f37eu: goto P_0c03f37e;
case 0x0c03f380u: goto P_0c03f380;
case 0x0c03f390u: goto P_0c03f390;
case 0x0c03f392u: goto P_0c03f392;
case 0x0c03f394u: goto P_0c03f394;
case 0x0c03f396u: goto P_0c03f396;
case 0x0c03f398u: goto P_0c03f398;
case 0x0c03f39au: goto P_0c03f39a;
case 0x0c03f39cu: goto P_0c03f39c;
case 0x0c03f39eu: goto P_0c03f39e;
case 0x0c03f3a0u: goto P_0c03f3a0;
case 0x0c03f3a2u: goto P_0c03f3a2;
case 0x0c03f3b0u: goto P_0c03f3b0;
case 0x0c03f3b2u: goto P_0c03f3b2;
case 0x0c03f3b4u: goto P_0c03f3b4;
case 0x0c03f3b6u: goto P_0c03f3b6;
case 0x0c03f3b8u: goto P_0c03f3b8;
case 0x0c03f3bau: goto P_0c03f3ba;
case 0x0c03f3bcu: goto P_0c03f3bc;
case 0x0c03f3beu: goto P_0c03f3be;
case 0x0c03f3c0u: goto P_0c03f3c0;
case 0x0c03f3c2u: goto P_0c03f3c2;
case 0x0c03f3c4u: goto P_0c03f3c4;
case 0x0c03f3c6u: goto P_0c03f3c6;
case 0x0c03f3c8u: goto P_0c03f3c8;
case 0x0c03f3cau: goto P_0c03f3ca;
case 0x0c03f3ccu: goto P_0c03f3cc;
case 0x0c03f3ceu: goto P_0c03f3ce;
case 0x0c03f3d0u: goto P_0c03f3d0;
case 0x0c03f3d2u: goto P_0c03f3d2;
case 0x0c03f3d4u: goto P_0c03f3d4;
case 0x0c03f3d6u: goto P_0c03f3d6;
case 0x0c03f3d8u: goto P_0c03f3d8;
case 0x0c03f3dau: goto P_0c03f3da;
case 0x0c03f3e0u: goto P_0c03f3e0;
case 0x0c03f3e2u: goto P_0c03f3e2;
case 0x0c03f3e4u: goto P_0c03f3e4;
case 0x0c03f3e6u: goto P_0c03f3e6;
case 0x0c03f3e8u: goto P_0c03f3e8;
case 0x0c03f3eau: goto P_0c03f3ea;
case 0x0c03f3ecu: goto P_0c03f3ec;
case 0x0c03f3eeu: goto P_0c03f3ee;
case 0x0c03f3f0u: goto P_0c03f3f0;
case 0x0c03f3f2u: goto P_0c03f3f2;
case 0x0c03f3f4u: goto P_0c03f3f4;
case 0x0c03f3f6u: goto P_0c03f3f6;
case 0x0c03f3f8u: goto P_0c03f3f8;
case 0x0c03f3fau: goto P_0c03f3fa;
case 0x0c03f3fcu: goto P_0c03f3fc;
case 0x0c03f3feu: goto P_0c03f3fe;
case 0x0c03f400u: goto P_0c03f400;
case 0x0c03f402u: goto P_0c03f402;
case 0x0c03f404u: goto P_0c03f404;
case 0x0c03f406u: goto P_0c03f406;
case 0x0c03f410u: goto P_0c03f410;
case 0x0c03f412u: goto P_0c03f412;
case 0x0c03f414u: goto P_0c03f414;
case 0x0c03f416u: goto P_0c03f416;
case 0x0c03f418u: goto P_0c03f418;
case 0x0c03f41au: goto P_0c03f41a;
case 0x0c03f41cu: goto P_0c03f41c;
case 0x0c03f41eu: goto P_0c03f41e;
case 0x0c03f420u: goto P_0c03f420;
case 0x0c03f422u: goto P_0c03f422;
case 0x0c03f424u: goto P_0c03f424;
case 0x0c03f426u: goto P_0c03f426;
case 0x0c03f428u: goto P_0c03f428;
case 0x0c03f42au: goto P_0c03f42a;
case 0x0c03f42cu: goto P_0c03f42c;
case 0x0c03f42eu: goto P_0c03f42e;
case 0x0c03f430u: goto P_0c03f430;
case 0x0c03f432u: goto P_0c03f432;
case 0x0c03f434u: goto P_0c03f434;
case 0x0c03f436u: goto P_0c03f436;
case 0x0c03f438u: goto P_0c03f438;
case 0x0c03f43au: goto P_0c03f43a;
case 0x0c03f43cu: goto P_0c03f43c;
case 0x0c03f43eu: goto P_0c03f43e;
case 0x0c03f440u: goto P_0c03f440;
case 0x0c03f442u: goto P_0c03f442;
case 0x0c03f444u: goto P_0c03f444;
case 0x0c03f446u: goto P_0c03f446;
case 0x0c03f448u: goto P_0c03f448;
case 0x0c03f44au: goto P_0c03f44a;
case 0x0c03f44cu: goto P_0c03f44c;
case 0x0c03f44eu: goto P_0c03f44e;
case 0x0c03f450u: goto P_0c03f450;
case 0x0c03f452u: goto P_0c03f452;
case 0x0c03f454u: goto P_0c03f454;
case 0x0c03f456u: goto P_0c03f456;
case 0x0c03f458u: goto P_0c03f458;
case 0x0c03f45au: goto P_0c03f45a;
case 0x0c03f45cu: goto P_0c03f45c;
case 0x0c03f45eu: goto P_0c03f45e;
case 0x0c03f460u: goto P_0c03f460;
case 0x0c03f462u: goto P_0c03f462;
case 0x0c03f464u: goto P_0c03f464;
case 0x0c03f466u: goto P_0c03f466;
case 0x0c03f468u: goto P_0c03f468;
case 0x0c03f46au: goto P_0c03f46a;
case 0x0c03f46cu: goto P_0c03f46c;
case 0x0c03f46eu: goto P_0c03f46e;
case 0x0c03f470u: goto P_0c03f470;
case 0x0c03f472u: goto P_0c03f472;
case 0x0c03f474u: goto P_0c03f474;
case 0x0c03f476u: goto P_0c03f476;
case 0x0c03f478u: goto P_0c03f478;
case 0x0c03f47au: goto P_0c03f47a;
case 0x0c03f47cu: goto P_0c03f47c;
case 0x0c03f47eu: goto P_0c03f47e;
case 0x0c03f480u: goto P_0c03f480;
case 0x0c03f482u: goto P_0c03f482;
case 0x0c03f484u: goto P_0c03f484;
case 0x0c03f486u: goto P_0c03f486;
case 0x0c03f488u: goto P_0c03f488;
case 0x0c03f48au: goto P_0c03f48a;
case 0x0c03f48cu: goto P_0c03f48c;
case 0x0c03f48eu: goto P_0c03f48e;
case 0x0c03f490u: goto P_0c03f490;
case 0x0c03f492u: goto P_0c03f492;
case 0x0c03f494u: goto P_0c03f494;
case 0x0c03f496u: goto P_0c03f496;
case 0x0c03f498u: goto P_0c03f498;
case 0x0c03f49au: goto P_0c03f49a;
case 0x0c03f49cu: goto P_0c03f49c;
case 0x0c03f49eu: goto P_0c03f49e;
case 0x0c03f4a0u: goto P_0c03f4a0;
case 0x0c03f4a2u: goto P_0c03f4a2;
case 0x0c03f4a4u: goto P_0c03f4a4;
case 0x0c03f4a6u: goto P_0c03f4a6;
case 0x0c03f4a8u: goto P_0c03f4a8;
case 0x0c03f4aau: goto P_0c03f4aa;
case 0x0c03f4acu: goto P_0c03f4ac;
case 0x0c03f4aeu: goto P_0c03f4ae;
case 0x0c03f4b0u: goto P_0c03f4b0;
case 0x0c03f4b2u: goto P_0c03f4b2;
case 0x0c03f4b4u: goto P_0c03f4b4;
case 0x0c03f4b6u: goto P_0c03f4b6;
case 0x0c03f4b8u: goto P_0c03f4b8;
case 0x0c03f4bau: goto P_0c03f4ba;
case 0x0c03f4bcu: goto P_0c03f4bc;
case 0x0c03f4beu: goto P_0c03f4be;
case 0x0c03f4c0u: goto P_0c03f4c0;
case 0x0c03f4c2u: goto P_0c03f4c2;
case 0x0c03f4c4u: goto P_0c03f4c4;
case 0x0c03f4c6u: goto P_0c03f4c6;
case 0x0c03f4c8u: goto P_0c03f4c8;
case 0x0c03f4cau: goto P_0c03f4ca;
case 0x0c03f4ccu: goto P_0c03f4cc;
case 0x0c03f4ceu: goto P_0c03f4ce;
case 0x0c03f4d0u: goto P_0c03f4d0;
case 0x0c03f4d2u: goto P_0c03f4d2;
case 0x0c03f4d4u: goto P_0c03f4d4;
case 0x0c03f4d6u: goto P_0c03f4d6;
case 0x0c03f4d8u: goto P_0c03f4d8;
case 0x0c03f4dau: goto P_0c03f4da;
case 0x0c03f4dcu: goto P_0c03f4dc;
case 0x0c043eccu: goto P_0c043ecc;
case 0x0c043eceu: goto P_0c043ece;
case 0x0c043ed0u: goto P_0c043ed0;
case 0x0c043ed2u: goto P_0c043ed2;
case 0x0c043ed4u: goto P_0c043ed4;
case 0x0c043ed6u: goto P_0c043ed6;
case 0x0c043ed8u: goto P_0c043ed8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03f2d0: /* original 2fe6, guest PC 0x0c03f2d0 */
if(!s->budget--) { s->failed_pc=0x0c03f2d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d2;
P_0c03f2d2: /* original 2fd6, guest PC 0x0c03f2d2 */
if(!s->budget--) { s->failed_pc=0x0c03f2d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d4;
P_0c03f2d4: /* original 2fc6, guest PC 0x0c03f2d4 */
if(!s->budget--) { s->failed_pc=0x0c03f2d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d6;
P_0c03f2d6: /* original 2fb6, guest PC 0x0c03f2d6 */
if(!s->budget--) { s->failed_pc=0x0c03f2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2d8;
P_0c03f2d8: /* original 2fa6, guest PC 0x0c03f2d8 */
if(!s->budget--) { s->failed_pc=0x0c03f2d8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2da;
P_0c03f2da: /* original 2f96, guest PC 0x0c03f2da */
if(!s->budget--) { s->failed_pc=0x0c03f2dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2dc;
P_0c03f2dc: /* original 2f86, guest PC 0x0c03f2dc */
if(!s->budget--) { s->failed_pc=0x0c03f2dcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f2de;
P_0c03f2de: /* original 6342, guest PC 0x0c03f2de */
if(!s->budget--) { s->failed_pc=0x0c03f2deu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f2e0;
P_0c03f2e0: /* original 4f22, guest PC 0x0c03f2e0 */
if(!s->budget--) { s->failed_pc=0x0c03f2e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f2e2;
P_0c03f2e2: /* original 4311, guest PC 0x0c03f2e2 */
if(!s->budget--) { s->failed_pc=0x0c03f2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c03f2e4;
P_0c03f2e4: /* original 8f03, guest PC 0x0c03f2e4 */
if(!s->budget--) { s->failed_pc=0x0c03f2e4u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c03f2ee; }
goto P_0c03f2e8;
P_0c03f2e6: /* original ec00, guest PC 0x0c03f2e6 */
if(!s->budget--) { s->failed_pc=0x0c03f2e6u; return 0; }
r[12]=0x00000000u;
goto P_0c03f2e8;
P_0c03f2e8: /* original 5146, guest PC 0x0c03f2e8 */
if(!s->budget--) { s->failed_pc=0x0c03f2e8u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f2ea;
P_0c03f2ea: /* original 2118, guest PC 0x0c03f2ea */
if(!s->budget--) { s->failed_pc=0x0c03f2eau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f2ec;
P_0c03f2ec: /* original 8b30, guest PC 0x0c03f2ec */
if(!s->budget--) { s->failed_pc=0x0c03f2ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f350; }
goto P_0c03f2ee;
P_0c03f2ee: /* original a06c, guest PC 0x0c03f2ee */
if(!s->budget--) { s->failed_pc=0x0c03f2eeu; return 0; }
r[0]=0x00000000u;
goto P_0c03f3ca;
P_0c03f2f0: /* original e000, guest PC 0x0c03f2f0 */
if(!s->budget--) { s->failed_pc=0x0c03f2f0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c03f2f2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f2f2u; return 0; } return 1;
P_0c03f350: /* original da65, guest PC 0x0c03f350 */
if(!s->budget--) { s->failed_pc=0x0c03f350u; return 0; }
r[10]=read(ram,0x0c03f4e8u,4);
goto P_0c03f352;
P_0c03f352: /* original 6d43, guest PC 0x0c03f352 */
if(!s->budget--) { s->failed_pc=0x0c03f352u; return 0; }
r[13]=r[4];
goto P_0c03f354;
P_0c03f354: /* original e901, guest PC 0x0c03f354 */
if(!s->budget--) { s->failed_pc=0x0c03f354u; return 0; }
r[9]=0x00000001u;
goto P_0c03f356;
P_0c03f356: /* original 7d18, guest PC 0x0c03f356 */
if(!s->budget--) { s->failed_pc=0x0c03f356u; return 0; }
r[13]+=0x00000018u;
goto P_0c03f358;
P_0c03f358: /* original e8ff, guest PC 0x0c03f358 */
if(!s->budget--) { s->failed_pc=0x0c03f358u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f35a;
P_0c03f35a: /* original 6ed3, guest PC 0x0c03f35a */
if(!s->budget--) { s->failed_pc=0x0c03f35au; return 0; }
r[14]=r[13];
goto P_0c03f35c;
P_0c03f35c: /* original 55e8, guest PC 0x0c03f35c */
if(!s->budget--) { s->failed_pc=0x0c03f35cu; return 0; }
r[5]=read(ram,r[14]+32,4);
goto P_0c03f35e;
P_0c03f35e: /* original 4511, guest PC 0x0c03f35e */
if(!s->budget--) { s->failed_pc=0x0c03f35eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f360;
P_0c03f360: /* original 8f17, guest PC 0x0c03f360 */
if(!s->budget--) { s->failed_pc=0x0c03f360u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000050u;
if(!cond) { goto P_0c03f392; }
goto P_0c03f364;
P_0c03f362: /* original 7d50, guest PC 0x0c03f362 */
if(!s->budget--) { s->failed_pc=0x0c03f362u; return 0; }
r[13]+=0x00000050u;
goto P_0c03f364;
P_0c03f364: /* original d261, guest PC 0x0c03f364 */
if(!s->budget--) { s->failed_pc=0x0c03f364u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f366;
P_0c03f366: /* original d062, guest PC 0x0c03f366 */
if(!s->budget--) { s->failed_pc=0x0c03f366u; return 0; }
r[0]=read(ram,0x0c03f4f0u,4);
goto P_0c03f368;
P_0c03f368: /* original 6322, guest PC 0x0c03f368 */
if(!s->budget--) { s->failed_pc=0x0c03f368u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f36a;
P_0c03f36a: /* original 6102, guest PC 0x0c03f36a */
if(!s->budget--) { s->failed_pc=0x0c03f36au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03f36c;
P_0c03f36c: /* original 353c, guest PC 0x0c03f36c */
if(!s->budget--) { s->failed_pc=0x0c03f36cu; return 0; }
r[5]+=r[3];
goto P_0c03f36e;
P_0c03f36e: /* original 6453, guest PC 0x0c03f36e */
if(!s->budget--) { s->failed_pc=0x0c03f36eu; return 0; }
r[4]=r[5];
goto P_0c03f370;
P_0c03f370: /* original 4408, guest PC 0x0c03f370 */
if(!s->budget--) { s->failed_pc=0x0c03f370u; return 0; }
r[4]<<=2;
goto P_0c03f372;
P_0c03f372: /* original 4400, guest PC 0x0c03f372 */
if(!s->budget--) { s->failed_pc=0x0c03f372u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f374;
P_0c03f374: /* original 341c, guest PC 0x0c03f374 */
if(!s->budget--) { s->failed_pc=0x0c03f374u; return 0; }
r[4]+=r[1];
goto P_0c03f376;
P_0c03f376: /* original 6342, guest PC 0x0c03f376 */
if(!s->budget--) { s->failed_pc=0x0c03f376u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03f378;
P_0c03f378: /* original 2338, guest PC 0x0c03f378 */
if(!s->budget--) { s->failed_pc=0x0c03f378u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f37a;
P_0c03f37a: /* original 8b09, guest PC 0x0c03f37a */
if(!s->budget--) { s->failed_pc=0x0c03f37au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f390; }
goto P_0c03f37c;
P_0c03f37c: /* original 6c93, guest PC 0x0c03f37c */
if(!s->budget--) { s->failed_pc=0x0c03f37cu; return 0; }
r[12]=r[9];
goto P_0c03f37e;
P_0c03f37e: /* original a008, guest PC 0x0c03f37e */
if(!s->budget--) { s->failed_pc=0x0c03f37eu; return 0; }
r[5]=r[8];
goto P_0c03f392;
P_0c03f380: /* original 6583, guest PC 0x0c03f380 */
if(!s->budget--) { s->failed_pc=0x0c03f380u; return 0; }
r[5]=r[8];
if(!vf3_matrix_family(0x0c03f382u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f382u; return 0; } return 1;
P_0c03f390: /* original 5541, guest PC 0x0c03f390 */
if(!s->budget--) { s->failed_pc=0x0c03f390u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f392;
P_0c03f392: /* original 5be3, guest PC 0x0c03f392 */
if(!s->budget--) { s->failed_pc=0x0c03f392u; return 0; }
r[11]=read(ram,r[14]+12,4);
goto P_0c03f394;
P_0c03f394: /* original 4511, guest PC 0x0c03f394 */
if(!s->budget--) { s->failed_pc=0x0c03f394u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c03f396;
P_0c03f396: /* original 8f0b, guest PC 0x0c03f396 */
if(!s->budget--) { s->failed_pc=0x0c03f396u; return 0; }
cond=r[17]&1u;
r[11]&=r[10];
if(!cond) { goto P_0c03f3b0; }
goto P_0c03f39a;
P_0c03f398: /* original 2ba9, guest PC 0x0c03f398 */
if(!s->budget--) { s->failed_pc=0x0c03f398u; return 0; }
r[11]&=r[10];
goto P_0c03f39a;
P_0c03f39a: /* original d356, guest PC 0x0c03f39a */
if(!s->budget--) { s->failed_pc=0x0c03f39au; return 0; }
r[3]=read(ram,0x0c03f4f4u,4);
goto P_0c03f39c;
P_0c03f39c: /* original 430b, guest PC 0x0c03f39c */
if(!s->budget--) { s->failed_pc=0x0c03f39cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3a0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3a0u) { target=s->pc; goto dispatch; }
goto P_0c03f3a0;
P_0c03f39e: /* original 64e3, guest PC 0x0c03f39e */
if(!s->budget--) { s->failed_pc=0x0c03f39eu; return 0; }
r[4]=r[14];
goto P_0c03f3a0;
P_0c03f3a0: /* original a009, guest PC 0x0c03f3a0 */
if(!s->budget--) { s->failed_pc=0x0c03f3a0u; return 0; }
goto P_0c03f3b6;
P_0c03f3a2: /* original 0009, guest PC 0x0c03f3a2 */
if(!s->budget--) { s->failed_pc=0x0c03f3a2u; return 0; }
if(!vf3_matrix_family(0x0c03f3a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3a4u; return 0; } return 1;
P_0c03f3b0: /* original d351, guest PC 0x0c03f3b0 */
if(!s->budget--) { s->failed_pc=0x0c03f3b0u; return 0; }
r[3]=read(ram,0x0c03f4f8u,4);
goto P_0c03f3b2;
P_0c03f3b2: /* original 430b, guest PC 0x0c03f3b2 */
if(!s->budget--) { s->failed_pc=0x0c03f3b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f3b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f3b6u) { target=s->pc; goto dispatch; }
goto P_0c03f3b6;
P_0c03f3b4: /* original 64e3, guest PC 0x0c03f3b4 */
if(!s->budget--) { s->failed_pc=0x0c03f3b4u; return 0; }
r[4]=r[14];
goto P_0c03f3b6;
P_0c03f3b6: /* original e04c, guest PC 0x0c03f3b6 */
if(!s->budget--) { s->failed_pc=0x0c03f3b6u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f3b8;
P_0c03f3b8: /* original 52e3, guest PC 0x0c03f3b8 */
if(!s->budget--) { s->failed_pc=0x0c03f3b8u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f3ba;
P_0c03f3ba: /* original 22bb, guest PC 0x0c03f3ba */
if(!s->budget--) { s->failed_pc=0x0c03f3bau; return 0; }
r[2]|=r[11];
goto P_0c03f3bc;
P_0c03f3bc: /* original 1e23, guest PC 0x0c03f3bc */
if(!s->budget--) { s->failed_pc=0x0c03f3bcu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f3be;
P_0c03f3be: /* original 03ee, guest PC 0x0c03f3be */
if(!s->budget--) { s->failed_pc=0x0c03f3beu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f3c0;
P_0c03f3c0: /* original 3d3c, guest PC 0x0c03f3c0 */
if(!s->budget--) { s->failed_pc=0x0c03f3c0u; return 0; }
r[13]+=r[3];
goto P_0c03f3c2;
P_0c03f3c2: /* original 64d2, guest PC 0x0c03f3c2 */
if(!s->budget--) { s->failed_pc=0x0c03f3c2u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c03f3c4;
P_0c03f3c4: /* original 2448, guest PC 0x0c03f3c4 */
if(!s->budget--) { s->failed_pc=0x0c03f3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f3c6;
P_0c03f3c6: /* original 8bc8, guest PC 0x0c03f3c6 */
if(!s->budget--) { s->failed_pc=0x0c03f3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f35a; }
goto P_0c03f3c8;
P_0c03f3c8: /* original 60c3, guest PC 0x0c03f3c8 */
if(!s->budget--) { s->failed_pc=0x0c03f3c8u; return 0; }
r[0]=r[12];
goto P_0c03f3ca;
P_0c03f3ca: /* original 4f26, guest PC 0x0c03f3ca */
if(!s->budget--) { s->failed_pc=0x0c03f3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f3cc;
P_0c03f3cc: /* original 68f6, guest PC 0x0c03f3cc */
if(!s->budget--) { s->failed_pc=0x0c03f3ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f3ce;
P_0c03f3ce: /* original 69f6, guest PC 0x0c03f3ce */
if(!s->budget--) { s->failed_pc=0x0c03f3ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f3d0;
P_0c03f3d0: /* original 6af6, guest PC 0x0c03f3d0 */
if(!s->budget--) { s->failed_pc=0x0c03f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f3d2;
P_0c03f3d2: /* original 6bf6, guest PC 0x0c03f3d2 */
if(!s->budget--) { s->failed_pc=0x0c03f3d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f3d4;
P_0c03f3d4: /* original 6cf6, guest PC 0x0c03f3d4 */
if(!s->budget--) { s->failed_pc=0x0c03f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f3d6;
P_0c03f3d6: /* original 6df6, guest PC 0x0c03f3d6 */
if(!s->budget--) { s->failed_pc=0x0c03f3d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f3d8;
P_0c03f3d8: /* original 000b, guest PC 0x0c03f3d8 */
if(!s->budget--) { s->failed_pc=0x0c03f3d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f3da: /* original 6ef6, guest PC 0x0c03f3da */
if(!s->budget--) { s->failed_pc=0x0c03f3dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f3dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f3dcu; return 0; } return 1;
P_0c03f3e0: /* original 2fe6, guest PC 0x0c03f3e0 */
if(!s->budget--) { s->failed_pc=0x0c03f3e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3e2;
P_0c03f3e2: /* original e300, guest PC 0x0c03f3e2 */
if(!s->budget--) { s->failed_pc=0x0c03f3e2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f3e4;
P_0c03f3e4: /* original 2fd6, guest PC 0x0c03f3e4 */
if(!s->budget--) { s->failed_pc=0x0c03f3e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3e6;
P_0c03f3e6: /* original 2fc6, guest PC 0x0c03f3e6 */
if(!s->budget--) { s->failed_pc=0x0c03f3e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3e8;
P_0c03f3e8: /* original 2fb6, guest PC 0x0c03f3e8 */
if(!s->budget--) { s->failed_pc=0x0c03f3e8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3ea;
P_0c03f3ea: /* original 2fa6, guest PC 0x0c03f3ea */
if(!s->budget--) { s->failed_pc=0x0c03f3eau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3ec;
P_0c03f3ec: /* original 2f96, guest PC 0x0c03f3ec */
if(!s->budget--) { s->failed_pc=0x0c03f3ecu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3ee;
P_0c03f3ee: /* original 2f86, guest PC 0x0c03f3ee */
if(!s->budget--) { s->failed_pc=0x0c03f3eeu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f3f0;
P_0c03f3f0: /* original 4f22, guest PC 0x0c03f3f0 */
if(!s->budget--) { s->failed_pc=0x0c03f3f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f3f2;
P_0c03f3f2: /* original 4f12, guest PC 0x0c03f3f2 */
if(!s->budget--) { s->failed_pc=0x0c03f3f2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f3f4;
P_0c03f3f4: /* original 7ff8, guest PC 0x0c03f3f4 */
if(!s->budget--) { s->failed_pc=0x0c03f3f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03f3f6;
P_0c03f3f6: /* original 1f31, guest PC 0x0c03f3f6 */
if(!s->budget--) { s->failed_pc=0x0c03f3f6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f3f8;
P_0c03f3f8: /* original 6242, guest PC 0x0c03f3f8 */
if(!s->budget--) { s->failed_pc=0x0c03f3f8u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c03f3fa;
P_0c03f3fa: /* original 4211, guest PC 0x0c03f3fa */
if(!s->budget--) { s->failed_pc=0x0c03f3fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c03f3fc;
P_0c03f3fc: /* original 8b02, guest PC 0x0c03f3fc */
if(!s->budget--) { s->failed_pc=0x0c03f3fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f404; }
goto P_0c03f3fe;
P_0c03f3fe: /* original 5146, guest PC 0x0c03f3fe */
if(!s->budget--) { s->failed_pc=0x0c03f3feu; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f400;
P_0c03f400: /* original 2118, guest PC 0x0c03f400 */
if(!s->budget--) { s->failed_pc=0x0c03f400u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f402;
P_0c03f402: /* original 8b05, guest PC 0x0c03f402 */
if(!s->budget--) { s->failed_pc=0x0c03f402u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f410; }
goto P_0c03f404;
P_0c03f404: /* original a060, guest PC 0x0c03f404 */
if(!s->budget--) { s->failed_pc=0x0c03f404u; return 0; }
r[0]=0x00000000u;
goto P_0c03f4c8;
P_0c03f406: /* original e000, guest PC 0x0c03f406 */
if(!s->budget--) { s->failed_pc=0x0c03f406u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c03f408u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f408u; return 0; } return 1;
P_0c03f410: /* original db3a, guest PC 0x0c03f410 */
if(!s->budget--) { s->failed_pc=0x0c03f410u; return 0; }
r[11]=read(ram,0x0c03f4fcu,4);
goto P_0c03f412;
P_0c03f412: /* original 6a43, guest PC 0x0c03f412 */
if(!s->budget--) { s->failed_pc=0x0c03f412u; return 0; }
r[10]=r[4];
goto P_0c03f414;
P_0c03f414: /* original de36, guest PC 0x0c03f414 */
if(!s->budget--) { s->failed_pc=0x0c03f414u; return 0; }
r[14]=read(ram,0x0c03f4f0u,4);
goto P_0c03f416;
P_0c03f416: /* original 7a18, guest PC 0x0c03f416 */
if(!s->budget--) { s->failed_pc=0x0c03f416u; return 0; }
r[10]+=0x00000018u;
goto P_0c03f418;
P_0c03f418: /* original e8ff, guest PC 0x0c03f418 */
if(!s->budget--) { s->failed_pc=0x0c03f418u; return 0; }
r[8]=0xffffffffu;
goto P_0c03f41a;
P_0c03f41a: /* original 6ca3, guest PC 0x0c03f41a */
if(!s->budget--) { s->failed_pc=0x0c03f41au; return 0; }
r[12]=r[10];
goto P_0c03f41c;
P_0c03f41c: /* original 54c8, guest PC 0x0c03f41c */
if(!s->budget--) { s->failed_pc=0x0c03f41cu; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c03f41e;
P_0c03f41e: /* original 4411, guest PC 0x0c03f41e */
if(!s->budget--) { s->failed_pc=0x0c03f41eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c03f420;
P_0c03f420: /* original 8f39, guest PC 0x0c03f420 */
if(!s->budget--) { s->failed_pc=0x0c03f420u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000050u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f424;
P_0c03f422: /* original 7a50, guest PC 0x0c03f422 */
if(!s->budget--) { s->failed_pc=0x0c03f422u; return 0; }
r[10]+=0x00000050u;
goto P_0c03f424;
P_0c03f424: /* original d231, guest PC 0x0c03f424 */
if(!s->budget--) { s->failed_pc=0x0c03f424u; return 0; }
r[2]=read(ram,0x0c03f4ecu,4);
goto P_0c03f426;
P_0c03f426: /* original 61e2, guest PC 0x0c03f426 */
if(!s->budget--) { s->failed_pc=0x0c03f426u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f428;
P_0c03f428: /* original 6322, guest PC 0x0c03f428 */
if(!s->budget--) { s->failed_pc=0x0c03f428u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f42a;
P_0c03f42a: /* original 343c, guest PC 0x0c03f42a */
if(!s->budget--) { s->failed_pc=0x0c03f42au; return 0; }
r[4]+=r[3];
goto P_0c03f42c;
P_0c03f42c: /* original 6d43, guest PC 0x0c03f42c */
if(!s->budget--) { s->failed_pc=0x0c03f42cu; return 0; }
r[13]=r[4];
goto P_0c03f42e;
P_0c03f42e: /* original 4d08, guest PC 0x0c03f42e */
if(!s->budget--) { s->failed_pc=0x0c03f42eu; return 0; }
r[13]<<=2;
goto P_0c03f430;
P_0c03f430: /* original 4d00, guest PC 0x0c03f430 */
if(!s->budget--) { s->failed_pc=0x0c03f430u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f432;
P_0c03f432: /* original 31dc, guest PC 0x0c03f432 */
if(!s->budget--) { s->failed_pc=0x0c03f432u; return 0; }
r[1]+=r[13];
goto P_0c03f434;
P_0c03f434: /* original 6012, guest PC 0x0c03f434 */
if(!s->budget--) { s->failed_pc=0x0c03f434u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f436;
P_0c03f436: /* original e300, guest PC 0x0c03f436 */
if(!s->budget--) { s->failed_pc=0x0c03f436u; return 0; }
r[3]=0x00000000u;
goto P_0c03f438;
P_0c03f438: /* original 3036, guest PC 0x0c03f438 */
if(!s->budget--) { s->failed_pc=0x0c03f438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c03f43a;
P_0c03f43a: /* original 8b2c, guest PC 0x0c03f43a */
if(!s->budget--) { s->failed_pc=0x0c03f43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f43c;
P_0c03f43c: /* original 61e2, guest PC 0x0c03f43c */
if(!s->budget--) { s->failed_pc=0x0c03f43cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f43e;
P_0c03f43e: /* original 31dc, guest PC 0x0c03f43e */
if(!s->budget--) { s->failed_pc=0x0c03f43eu; return 0; }
r[1]+=r[13];
goto P_0c03f440;
P_0c03f440: /* original 6012, guest PC 0x0c03f440 */
if(!s->budget--) { s->failed_pc=0x0c03f440u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f442;
P_0c03f442: /* original 70ff, guest PC 0x0c03f442 */
if(!s->budget--) { s->failed_pc=0x0c03f442u; return 0; }
r[0]+=0xffffffffu;
goto P_0c03f444;
P_0c03f444: /* original 2102, guest PC 0x0c03f444 */
if(!s->budget--) { s->failed_pc=0x0c03f444u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03f446;
P_0c03f446: /* original 61e2, guest PC 0x0c03f446 */
if(!s->budget--) { s->failed_pc=0x0c03f446u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f448;
P_0c03f448: /* original 31dc, guest PC 0x0c03f448 */
if(!s->budget--) { s->failed_pc=0x0c03f448u; return 0; }
r[1]+=r[13];
goto P_0c03f44a;
P_0c03f44a: /* original 6012, guest PC 0x0c03f44a */
if(!s->budget--) { s->failed_pc=0x0c03f44au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f44c;
P_0c03f44c: /* original 2008, guest PC 0x0c03f44c */
if(!s->budget--) { s->failed_pc=0x0c03f44cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f44e;
P_0c03f44e: /* original 8b22, guest PC 0x0c03f44e */
if(!s->budget--) { s->failed_pc=0x0c03f44eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f496; }
goto P_0c03f450;
P_0c03f450: /* original 60e2, guest PC 0x0c03f450 */
if(!s->budget--) { s->failed_pc=0x0c03f450u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f452;
P_0c03f452: /* original 30dc, guest PC 0x0c03f452 */
if(!s->budget--) { s->failed_pc=0x0c03f452u; return 0; }
r[0]+=r[13];
goto P_0c03f454;
P_0c03f454: /* original 5101, guest PC 0x0c03f454 */
if(!s->budget--) { s->failed_pc=0x0c03f454u; return 0; }
r[1]=read(ram,r[0]+4,4);
goto P_0c03f456;
P_0c03f456: /* original 2f12, guest PC 0x0c03f456 */
if(!s->budget--) { s->failed_pc=0x0c03f456u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c03f458;
P_0c03f458: /* original e13c, guest PC 0x0c03f458 */
if(!s->budget--) { s->failed_pc=0x0c03f458u; return 0; }
r[1]=0x0000003cu;
goto P_0c03f45a;
P_0c03f45a: /* original 60f2, guest PC 0x0c03f45a */
if(!s->budget--) { s->failed_pc=0x0c03f45au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f45c;
P_0c03f45c: /* original 62b2, guest PC 0x0c03f45c */
if(!s->budget--) { s->failed_pc=0x0c03f45cu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c03f45e;
P_0c03f45e: /* original 0017, guest PC 0x0c03f45e */
if(!s->budget--) { s->failed_pc=0x0c03f45eu; return 0; }
r[19]=r[0]*r[1];
goto P_0c03f460;
P_0c03f460: /* original 091a, guest PC 0x0c03f460 */
if(!s->budget--) { s->failed_pc=0x0c03f460u; return 0; }
r[9]=r[19];
goto P_0c03f462;
P_0c03f462: /* original 329c, guest PC 0x0c03f462 */
if(!s->budget--) { s->failed_pc=0x0c03f462u; return 0; }
r[2]+=r[9];
goto P_0c03f464;
P_0c03f464: /* original 502a, guest PC 0x0c03f464 */
if(!s->budget--) { s->failed_pc=0x0c03f464u; return 0; }
r[0]=read(ram,r[2]+40,4);
goto P_0c03f466;
P_0c03f466: /* original 2008, guest PC 0x0c03f466 */
if(!s->budget--) { s->failed_pc=0x0c03f466u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f468;
P_0c03f468: /* original 8b08, guest PC 0x0c03f468 */
if(!s->budget--) { s->failed_pc=0x0c03f468u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f47c; }
goto P_0c03f46a;
P_0c03f46a: /* original d225, guest PC 0x0c03f46a */
if(!s->budget--) { s->failed_pc=0x0c03f46au; return 0; }
r[2]=read(ram,0x0c03f500u,4);
goto P_0c03f46c;
P_0c03f46c: /* original 64b2, guest PC 0x0c03f46c */
if(!s->budget--) { s->failed_pc=0x0c03f46cu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c03f46e;
P_0c03f46e: /* original 420b, guest PC 0x0c03f46e */
if(!s->budget--) { s->failed_pc=0x0c03f46eu; return 0; }
target=r[2];
r[16]=code_base|0x0c03f472u;
r[4]+=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f472u) { target=s->pc; goto dispatch; }
goto P_0c03f472;
P_0c03f470: /* original 349c, guest PC 0x0c03f470 */
if(!s->budget--) { s->failed_pc=0x0c03f470u; return 0; }
r[4]+=r[9];
goto P_0c03f472;
P_0c03f472: /* original 6403, guest PC 0x0c03f472 */
if(!s->budget--) { s->failed_pc=0x0c03f472u; return 0; }
r[4]=r[0];
goto P_0c03f474;
P_0c03f474: /* original 2448, guest PC 0x0c03f474 */
if(!s->budget--) { s->failed_pc=0x0c03f474u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f476;
P_0c03f476: /* original 8901, guest PC 0x0c03f476 */
if(!s->budget--) { s->failed_pc=0x0c03f476u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f47c; }
goto P_0c03f478;
P_0c03f478: /* original e201, guest PC 0x0c03f478 */
if(!s->budget--) { s->failed_pc=0x0c03f478u; return 0; }
r[2]=0x00000001u;
goto P_0c03f47a;
P_0c03f47a: /* original 1f21, guest PC 0x0c03f47a */
if(!s->budget--) { s->failed_pc=0x0c03f47au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f47c;
P_0c03f47c: /* original 63b2, guest PC 0x0c03f47c */
if(!s->budget--) { s->failed_pc=0x0c03f47cu; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c03f47e;
P_0c03f47e: /* original e200, guest PC 0x0c03f47e */
if(!s->budget--) { s->failed_pc=0x0c03f47eu; return 0; }
r[2]=0x00000000u;
goto P_0c03f480;
P_0c03f480: /* original 339c, guest PC 0x0c03f480 */
if(!s->budget--) { s->failed_pc=0x0c03f480u; return 0; }
r[3]+=r[9];
goto P_0c03f482;
P_0c03f482: /* original 132b, guest PC 0x0c03f482 */
if(!s->budget--) { s->failed_pc=0x0c03f482u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f484;
P_0c03f484: /* original 63b2, guest PC 0x0c03f484 */
if(!s->budget--) { s->failed_pc=0x0c03f484u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c03f486;
P_0c03f486: /* original 339c, guest PC 0x0c03f486 */
if(!s->budget--) { s->failed_pc=0x0c03f486u; return 0; }
r[3]+=r[9];
goto P_0c03f488;
P_0c03f488: /* original 138e, guest PC 0x0c03f488 */
if(!s->budget--) { s->failed_pc=0x0c03f488u; return 0; }
write(ram,r[3]+56,r[8],4);
goto P_0c03f48a;
P_0c03f48a: /* original d31e, guest PC 0x0c03f48a */
if(!s->budget--) { s->failed_pc=0x0c03f48au; return 0; }
r[3]=read(ram,0x0c03f504u,4);
goto P_0c03f48c;
P_0c03f48c: /* original 430b, guest PC 0x0c03f48c */
if(!s->budget--) { s->failed_pc=0x0c03f48cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f490u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f490u) { target=s->pc; goto dispatch; }
goto P_0c03f490;
P_0c03f48e: /* original 64f2, guest PC 0x0c03f48e */
if(!s->budget--) { s->failed_pc=0x0c03f48eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03f490;
P_0c03f490: /* original 62e2, guest PC 0x0c03f490 */
if(!s->budget--) { s->failed_pc=0x0c03f490u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f492;
P_0c03f492: /* original 32dc, guest PC 0x0c03f492 */
if(!s->budget--) { s->failed_pc=0x0c03f492u; return 0; }
r[2]+=r[13];
goto P_0c03f494;
P_0c03f494: /* original 1281, guest PC 0x0c03f494 */
if(!s->budget--) { s->failed_pc=0x0c03f494u; return 0; }
write(ram,r[2]+4,r[8],4);
goto P_0c03f496;
P_0c03f496: /* original 50c3, guest PC 0x0c03f496 */
if(!s->budget--) { s->failed_pc=0x0c03f496u; return 0; }
r[0]=read(ram,r[12]+12,4);
goto P_0c03f498;
P_0c03f498: /* original e3e5, guest PC 0x0c03f498 */
if(!s->budget--) { s->failed_pc=0x0c03f498u; return 0; }
r[3]=0xffffffe5u;
goto P_0c03f49a;
P_0c03f49a: /* original e407, guest PC 0x0c03f49a */
if(!s->budget--) { s->failed_pc=0x0c03f49au; return 0; }
r[4]=0x00000007u;
goto P_0c03f49c;
P_0c03f49c: /* original 403d, guest PC 0x0c03f49c */
if(!s->budget--) { s->failed_pc=0x0c03f49cu; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c03f49e;
P_0c03f49e: /* original d31a, guest PC 0x0c03f49e */
if(!s->budget--) { s->failed_pc=0x0c03f49eu; return 0; }
r[3]=read(ram,0x0c03f508u,4);
goto P_0c03f4a0;
P_0c03f4a0: /* original 6232, guest PC 0x0c03f4a0 */
if(!s->budget--) { s->failed_pc=0x0c03f4a0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f4a2;
P_0c03f4a2: /* original 2228, guest PC 0x0c03f4a2 */
if(!s->budget--) { s->failed_pc=0x0c03f4a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f4a4;
P_0c03f4a4: /* original 8d09, guest PC 0x0c03f4a4 */
if(!s->budget--) { s->failed_pc=0x0c03f4a4u; return 0; }
cond=r[17]&1u;
r[4]&=r[0];
if(cond) { goto P_0c03f4ba; }
goto P_0c03f4a8;
P_0c03f4a6: /* original 2409, guest PC 0x0c03f4a6 */
if(!s->budget--) { s->failed_pc=0x0c03f4a6u; return 0; }
r[4]&=r[0];
goto P_0c03f4a8;
P_0c03f4a8: /* original 6043, guest PC 0x0c03f4a8 */
if(!s->budget--) { s->failed_pc=0x0c03f4a8u; return 0; }
r[0]=r[4];
goto P_0c03f4aa;
P_0c03f4aa: /* original 8805, guest PC 0x0c03f4aa */
if(!s->budget--) { s->failed_pc=0x0c03f4aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03f4ac;
P_0c03f4ac: /* original 8902, guest PC 0x0c03f4ac */
if(!s->budget--) { s->failed_pc=0x0c03f4acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f4b4; }
goto P_0c03f4ae;
P_0c03f4ae: /* original 6043, guest PC 0x0c03f4ae */
if(!s->budget--) { s->failed_pc=0x0c03f4aeu; return 0; }
r[0]=r[4];
goto P_0c03f4b0;
P_0c03f4b0: /* original 8806, guest PC 0x0c03f4b0 */
if(!s->budget--) { s->failed_pc=0x0c03f4b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c03f4b2;
P_0c03f4b2: /* original 8b02, guest PC 0x0c03f4b2 */
if(!s->budget--) { s->failed_pc=0x0c03f4b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f4ba; }
goto P_0c03f4b4;
P_0c03f4b4: /* original d315, guest PC 0x0c03f4b4 */
if(!s->budget--) { s->failed_pc=0x0c03f4b4u; return 0; }
r[3]=read(ram,0x0c03f50cu,4);
goto P_0c03f4b6;
P_0c03f4b6: /* original 430b, guest PC 0x0c03f4b6 */
if(!s->budget--) { s->failed_pc=0x0c03f4b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f4bau;
r[4]=read(ram,r[12]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f4bau) { target=s->pc; goto dispatch; }
goto P_0c03f4ba;
P_0c03f4b8: /* original 54cf, guest PC 0x0c03f4b8 */
if(!s->budget--) { s->failed_pc=0x0c03f4b8u; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c03f4ba;
P_0c03f4ba: /* original e04c, guest PC 0x0c03f4ba */
if(!s->budget--) { s->failed_pc=0x0c03f4bau; return 0; }
r[0]=0x0000004cu;
goto P_0c03f4bc;
P_0c03f4bc: /* original 02ce, guest PC 0x0c03f4bc */
if(!s->budget--) { s->failed_pc=0x0c03f4bcu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c03f4be;
P_0c03f4be: /* original 3a2c, guest PC 0x0c03f4be */
if(!s->budget--) { s->failed_pc=0x0c03f4beu; return 0; }
r[10]+=r[2];
goto P_0c03f4c0;
P_0c03f4c0: /* original 64a2, guest PC 0x0c03f4c0 */
if(!s->budget--) { s->failed_pc=0x0c03f4c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c03f4c2;
P_0c03f4c2: /* original 2448, guest PC 0x0c03f4c2 */
if(!s->budget--) { s->failed_pc=0x0c03f4c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f4c4;
P_0c03f4c4: /* original 8ba9, guest PC 0x0c03f4c4 */
if(!s->budget--) { s->failed_pc=0x0c03f4c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f41a; }
goto P_0c03f4c6;
P_0c03f4c6: /* original 50f1, guest PC 0x0c03f4c6 */
if(!s->budget--) { s->failed_pc=0x0c03f4c6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c03f4c8;
P_0c03f4c8: /* original 7f08, guest PC 0x0c03f4c8 */
if(!s->budget--) { s->failed_pc=0x0c03f4c8u; return 0; }
r[15]+=0x00000008u;
goto P_0c03f4ca;
P_0c03f4ca: /* original 4f16, guest PC 0x0c03f4ca */
if(!s->budget--) { s->failed_pc=0x0c03f4cau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f4cc;
P_0c03f4cc: /* original 4f26, guest PC 0x0c03f4cc */
if(!s->budget--) { s->failed_pc=0x0c03f4ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f4ce;
P_0c03f4ce: /* original 68f6, guest PC 0x0c03f4ce */
if(!s->budget--) { s->failed_pc=0x0c03f4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f4d0;
P_0c03f4d0: /* original 69f6, guest PC 0x0c03f4d0 */
if(!s->budget--) { s->failed_pc=0x0c03f4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f4d2;
P_0c03f4d2: /* original 6af6, guest PC 0x0c03f4d2 */
if(!s->budget--) { s->failed_pc=0x0c03f4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f4d4;
P_0c03f4d4: /* original 6bf6, guest PC 0x0c03f4d4 */
if(!s->budget--) { s->failed_pc=0x0c03f4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f4d6;
P_0c03f4d6: /* original 6cf6, guest PC 0x0c03f4d6 */
if(!s->budget--) { s->failed_pc=0x0c03f4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f4d8;
P_0c03f4d8: /* original 6df6, guest PC 0x0c03f4d8 */
if(!s->budget--) { s->failed_pc=0x0c03f4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f4da;
P_0c03f4da: /* original 000b, guest PC 0x0c03f4da */
if(!s->budget--) { s->failed_pc=0x0c03f4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f4dc: /* original 6ef6, guest PC 0x0c03f4dc */
if(!s->budget--) { s->failed_pc=0x0c03f4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f4deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f4deu; return 0; } return 1;
P_0c043ecc: /* original 4f22, guest PC 0x0c043ecc */
if(!s->budget--) { s->failed_pc=0x0c043eccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ece;
P_0c043ece: /* original d317, guest PC 0x0c043ece */
if(!s->budget--) { s->failed_pc=0x0c043eceu; return 0; }
r[3]=read(ram,0x0c043f2cu,4);
goto P_0c043ed0;
P_0c043ed0: /* original 430b, guest PC 0x0c043ed0 */
if(!s->budget--) { s->failed_pc=0x0c043ed0u; return 0; }
target=r[3];
r[16]=code_base|0x0c043ed4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ed4u) { target=s->pc; goto dispatch; }
goto P_0c043ed4;
P_0c043ed2: /* original 0009, guest PC 0x0c043ed2 */
if(!s->budget--) { s->failed_pc=0x0c043ed2u; return 0; }
goto P_0c043ed4;
P_0c043ed4: /* original 4f26, guest PC 0x0c043ed4 */
if(!s->budget--) { s->failed_pc=0x0c043ed4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043ed6;
P_0c043ed6: /* original 000b, guest PC 0x0c043ed6 */
if(!s->budget--) { s->failed_pc=0x0c043ed6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043ed8: /* original 0009, guest PC 0x0c043ed8 */
if(!s->budget--) { s->failed_pc=0x0c043ed8u; return 0; }
if(!vf3_matrix_family(0x0c043edau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043edau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
