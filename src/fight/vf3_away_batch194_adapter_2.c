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
int vf3_away_batch194_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0474d0u: goto P_0c0474d0;
case 0x0c0474d2u: goto P_0c0474d2;
case 0x0c0474d4u: goto P_0c0474d4;
case 0x0c0474d6u: goto P_0c0474d6;
case 0x0c0474d8u: goto P_0c0474d8;
case 0x0c0474dau: goto P_0c0474da;
case 0x0c0474dcu: goto P_0c0474dc;
case 0x0c0474deu: goto P_0c0474de;
case 0x0c0474e0u: goto P_0c0474e0;
case 0x0c0474e2u: goto P_0c0474e2;
case 0x0c0474e4u: goto P_0c0474e4;
case 0x0c0474e6u: goto P_0c0474e6;
case 0x0c0474e8u: goto P_0c0474e8;
case 0x0c0474eau: goto P_0c0474ea;
case 0x0c0474ecu: goto P_0c0474ec;
case 0x0c0474eeu: goto P_0c0474ee;
case 0x0c0474f0u: goto P_0c0474f0;
case 0x0c0474f2u: goto P_0c0474f2;
case 0x0c0474f4u: goto P_0c0474f4;
case 0x0c0474f6u: goto P_0c0474f6;
case 0x0c0474f8u: goto P_0c0474f8;
case 0x0c0474fau: goto P_0c0474fa;
case 0x0c0474fcu: goto P_0c0474fc;
case 0x0c047520u: goto P_0c047520;
case 0x0c047522u: goto P_0c047522;
case 0x0c047524u: goto P_0c047524;
case 0x0c047526u: goto P_0c047526;
case 0x0c047528u: goto P_0c047528;
case 0x0c04752au: goto P_0c04752a;
case 0x0c04752cu: goto P_0c04752c;
case 0x0c04752eu: goto P_0c04752e;
case 0x0c047530u: goto P_0c047530;
case 0x0c047532u: goto P_0c047532;
case 0x0c047534u: goto P_0c047534;
case 0x0c047536u: goto P_0c047536;
case 0x0c047538u: goto P_0c047538;
case 0x0c04753au: goto P_0c04753a;
case 0x0c0475f0u: goto P_0c0475f0;
case 0x0c0475f2u: goto P_0c0475f2;
case 0x0c0475f4u: goto P_0c0475f4;
case 0x0c0475f6u: goto P_0c0475f6;
case 0x0c0475f8u: goto P_0c0475f8;
case 0x0c0475fau: goto P_0c0475fa;
case 0x0c0475fcu: goto P_0c0475fc;
case 0x0c0475feu: goto P_0c0475fe;
case 0x0c047600u: goto P_0c047600;
case 0x0c047602u: goto P_0c047602;
case 0x0c047604u: goto P_0c047604;
case 0x0c047606u: goto P_0c047606;
case 0x0c047608u: goto P_0c047608;
case 0x0c04760au: goto P_0c04760a;
case 0x0c04760cu: goto P_0c04760c;
case 0x0c04760eu: goto P_0c04760e;
case 0x0c047610u: goto P_0c047610;
case 0x0c047612u: goto P_0c047612;
case 0x0c047614u: goto P_0c047614;
case 0x0c047616u: goto P_0c047616;
case 0x0c047618u: goto P_0c047618;
case 0x0c04761au: goto P_0c04761a;
case 0x0c05e754u: goto P_0c05e754;
case 0x0c05e756u: goto P_0c05e756;
case 0x0c05e758u: goto P_0c05e758;
case 0x0c05e75au: goto P_0c05e75a;
case 0x0c05e75cu: goto P_0c05e75c;
case 0x0c05e75eu: goto P_0c05e75e;
case 0x0c05e760u: goto P_0c05e760;
case 0x0c05e762u: goto P_0c05e762;
case 0x0c05e764u: goto P_0c05e764;
case 0x0c05e766u: goto P_0c05e766;
case 0x0c05e768u: goto P_0c05e768;
case 0x0c05e76au: goto P_0c05e76a;
case 0x0c05e76cu: goto P_0c05e76c;
case 0x0c05e76eu: goto P_0c05e76e;
case 0x0c05e770u: goto P_0c05e770;
case 0x0c05e772u: goto P_0c05e772;
case 0x0c05e774u: goto P_0c05e774;
case 0x0c05e776u: goto P_0c05e776;
case 0x0c05e778u: goto P_0c05e778;
case 0x0c05e77au: goto P_0c05e77a;
case 0x0c05e77cu: goto P_0c05e77c;
case 0x0c05e77eu: goto P_0c05e77e;
case 0x0c05e780u: goto P_0c05e780;
case 0x0c05e782u: goto P_0c05e782;
case 0x0c05e784u: goto P_0c05e784;
case 0x0c05e786u: goto P_0c05e786;
case 0x0c05e788u: goto P_0c05e788;
case 0x0c05e78au: goto P_0c05e78a;
case 0x0c05e78cu: goto P_0c05e78c;
case 0x0c05e78eu: goto P_0c05e78e;
case 0x0c05e790u: goto P_0c05e790;
case 0x0c05e792u: goto P_0c05e792;
case 0x0c05e794u: goto P_0c05e794;
case 0x0c05e94eu: goto P_0c05e94e;
case 0x0c05e950u: goto P_0c05e950;
case 0x0c05e952u: goto P_0c05e952;
case 0x0c05e954u: goto P_0c05e954;
case 0x0c05e956u: goto P_0c05e956;
case 0x0c05e958u: goto P_0c05e958;
case 0x0c05e95au: goto P_0c05e95a;
case 0x0c05e95cu: goto P_0c05e95c;
case 0x0c05e95eu: goto P_0c05e95e;
case 0x0c05e960u: goto P_0c05e960;
case 0x0c05e962u: goto P_0c05e962;
case 0x0c05e964u: goto P_0c05e964;
case 0x0c05e966u: goto P_0c05e966;
case 0x0c05e968u: goto P_0c05e968;
case 0x0c05e96au: goto P_0c05e96a;
case 0x0c05e96cu: goto P_0c05e96c;
case 0x0c05e96eu: goto P_0c05e96e;
case 0x0c05e970u: goto P_0c05e970;
case 0x0c05e972u: goto P_0c05e972;
case 0x0c05e974u: goto P_0c05e974;
case 0x0c05e976u: goto P_0c05e976;
case 0x0c05e978u: goto P_0c05e978;
case 0x0c05e97au: goto P_0c05e97a;
case 0x0c05e97cu: goto P_0c05e97c;
case 0x0c05e97eu: goto P_0c05e97e;
case 0x0c05e980u: goto P_0c05e980;
case 0x0c05e982u: goto P_0c05e982;
case 0x0c05e984u: goto P_0c05e984;
case 0x0c05e986u: goto P_0c05e986;
case 0x0c05e988u: goto P_0c05e988;
case 0x0c05e98au: goto P_0c05e98a;
case 0x0c05e98cu: goto P_0c05e98c;
case 0x0c05e98eu: goto P_0c05e98e;
case 0x0c05e990u: goto P_0c05e990;
case 0x0c05e992u: goto P_0c05e992;
case 0x0c05e994u: goto P_0c05e994;
case 0x0c05e996u: goto P_0c05e996;
case 0x0c05e998u: goto P_0c05e998;
case 0x0c05e99au: goto P_0c05e99a;
case 0x0c05e99cu: goto P_0c05e99c;
case 0x0c05e99eu: goto P_0c05e99e;
case 0x0c05e9a0u: goto P_0c05e9a0;
case 0x0c05e9a2u: goto P_0c05e9a2;
case 0x0c05e9a4u: goto P_0c05e9a4;
case 0x0c05e9a6u: goto P_0c05e9a6;
case 0x0c05e9a8u: goto P_0c05e9a8;
case 0x0c05e9aau: goto P_0c05e9aa;
case 0x0c05e9acu: goto P_0c05e9ac;
case 0x0c05e9aeu: goto P_0c05e9ae;
case 0x0c05e9b0u: goto P_0c05e9b0;
case 0x0c05e9b2u: goto P_0c05e9b2;
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
P_0c0474d0: /* original 6343, guest PC 0x0c0474d0 */
if(!s->budget--) { s->failed_pc=0x0c0474d0u; return 0; }
r[3]=r[4];
goto P_0c0474d2;
P_0c0474d2: /* original e2fc, guest PC 0x0c0474d2 */
if(!s->budget--) { s->failed_pc=0x0c0474d2u; return 0; }
r[2]=0xfffffffcu;
goto P_0c0474d4;
P_0c0474d4: /* original 2fe6, guest PC 0x0c0474d4 */
if(!s->budget--) { s->failed_pc=0x0c0474d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0474d6;
P_0c0474d6: /* original 432c, guest PC 0x0c0474d6 */
if(!s->budget--) { s->failed_pc=0x0c0474d6u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0474d8;
P_0c0474d8: /* original e701, guest PC 0x0c0474d8 */
if(!s->budget--) { s->failed_pc=0x0c0474d8u; return 0; }
r[7]=0x00000001u;
goto P_0c0474da;
P_0c0474da: /* original 6633, guest PC 0x0c0474da */
if(!s->budget--) { s->failed_pc=0x0c0474dau; return 0; }
r[6]=r[3];
goto P_0c0474dc;
P_0c0474dc: /* original e20f, guest PC 0x0c0474dc */
if(!s->budget--) { s->failed_pc=0x0c0474dcu; return 0; }
r[2]=0x0000000fu;
goto P_0c0474de;
P_0c0474de: /* original 6173, guest PC 0x0c0474de */
if(!s->budget--) { s->failed_pc=0x0c0474deu; return 0; }
r[1]=r[7];
goto P_0c0474e0;
P_0c0474e0: /* original 7ff8, guest PC 0x0c0474e0 */
if(!s->budget--) { s->failed_pc=0x0c0474e0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0474e2;
P_0c0474e2: /* original 2429, guest PC 0x0c0474e2 */
if(!s->budget--) { s->failed_pc=0x0c0474e2u; return 0; }
r[4]&=r[2];
goto P_0c0474e4;
P_0c0474e4: /* original 2f52, guest PC 0x0c0474e4 */
if(!s->budget--) { s->failed_pc=0x0c0474e4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0474e6;
P_0c0474e6: /* original 414c, guest PC 0x0c0474e6 */
if(!s->budget--) { s->failed_pc=0x0c0474e6u; return 0; }
r[1]=(r[4]&0x80000000u)?((r[4]&31u)?(uint32_t)((int32_t)r[1]>>((-r[4])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[4]&31u);
goto P_0c0474e8;
P_0c0474e8: /* original 1f31, guest PC 0x0c0474e8 */
if(!s->budget--) { s->failed_pc=0x0c0474e8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0474ea;
P_0c0474ea: /* original 65f2, guest PC 0x0c0474ea */
if(!s->budget--) { s->failed_pc=0x0c0474eau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0474ec;
P_0c0474ec: /* original 6413, guest PC 0x0c0474ec */
if(!s->budget--) { s->failed_pc=0x0c0474ecu; return 0; }
r[4]=r[1];
goto P_0c0474ee;
P_0c0474ee: /* original e1fc, guest PC 0x0c0474ee */
if(!s->budget--) { s->failed_pc=0x0c0474eeu; return 0; }
r[1]=0xfffffffcu;
goto P_0c0474f0;
P_0c0474f0: /* original de07, guest PC 0x0c0474f0 */
if(!s->budget--) { s->failed_pc=0x0c0474f0u; return 0; }
r[14]=read(ram,0x0c047510u,4);
goto P_0c0474f2;
P_0c0474f2: /* original 352c, guest PC 0x0c0474f2 */
if(!s->budget--) { s->failed_pc=0x0c0474f2u; return 0; }
r[5]+=r[2];
goto P_0c0474f4;
P_0c0474f4: /* original 451c, guest PC 0x0c0474f4 */
if(!s->budget--) { s->failed_pc=0x0c0474f4u; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c0474f6;
P_0c0474f6: /* original d103, guest PC 0x0c0474f6 */
if(!s->budget--) { s->failed_pc=0x0c0474f6u; return 0; }
r[1]=read(ram,0x0c047504u,4);
goto P_0c0474f8;
P_0c0474f8: /* original 4600, guest PC 0x0c0474f8 */
if(!s->budget--) { s->failed_pc=0x0c0474f8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0474fa;
P_0c0474fa: /* original a019, guest PC 0x0c0474fa */
if(!s->budget--) { s->failed_pc=0x0c0474fau; return 0; }
r[6]+=r[1];
goto P_0c047530;
P_0c0474fc: /* original 361c, guest PC 0x0c0474fc */
if(!s->budget--) { s->failed_pc=0x0c0474fcu; return 0; }
r[6]+=r[1];
if(!vf3_matrix_family(0x0c0474feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0474feu; return 0; } return 1;
P_0c047520: /* original 6361, guest PC 0x0c047520 */
if(!s->budget--) { s->failed_pc=0x0c047520u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c047522;
P_0c047522: /* original 234b, guest PC 0x0c047522 */
if(!s->budget--) { s->failed_pc=0x0c047522u; return 0; }
r[3]|=r[4];
goto P_0c047524;
P_0c047524: /* original 344c, guest PC 0x0c047524 */
if(!s->budget--) { s->failed_pc=0x0c047524u; return 0; }
r[4]+=r[4];
goto P_0c047526;
P_0c047526: /* original 34e3, guest PC 0x0c047526 */
if(!s->budget--) { s->failed_pc=0x0c047526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c047528;
P_0c047528: /* original 8f02, guest PC 0x0c047528 */
if(!s->budget--) { s->failed_pc=0x0c047528u; return 0; }
cond=r[17]&1u;
write(ram,r[6],r[3],2);
if(!cond) { goto P_0c047530; }
goto P_0c04752c;
P_0c04752a: /* original 2631, guest PC 0x0c04752a */
if(!s->budget--) { s->failed_pc=0x0c04752au; return 0; }
write(ram,r[6],r[3],2);
goto P_0c04752c;
P_0c04752c: /* original 6473, guest PC 0x0c04752c */
if(!s->budget--) { s->failed_pc=0x0c04752cu; return 0; }
r[4]=r[7];
goto P_0c04752e;
P_0c04752e: /* original 7602, guest PC 0x0c04752e */
if(!s->budget--) { s->failed_pc=0x0c04752eu; return 0; }
r[6]+=0x00000002u;
goto P_0c047530;
P_0c047530: /* original 4515, guest PC 0x0c047530 */
if(!s->budget--) { s->failed_pc=0x0c047530u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c047532;
P_0c047532: /* original 8df5, guest PC 0x0c047532 */
if(!s->budget--) { s->failed_pc=0x0c047532u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c047520; }
goto P_0c047536;
P_0c047534: /* original 75ff, guest PC 0x0c047534 */
if(!s->budget--) { s->failed_pc=0x0c047534u; return 0; }
r[5]+=0xffffffffu;
goto P_0c047536;
P_0c047536: /* original 7f08, guest PC 0x0c047536 */
if(!s->budget--) { s->failed_pc=0x0c047536u; return 0; }
r[15]+=0x00000008u;
goto P_0c047538;
P_0c047538: /* original 000b, guest PC 0x0c047538 */
if(!s->budget--) { s->failed_pc=0x0c047538u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04753a: /* original 6ef6, guest PC 0x0c04753a */
if(!s->budget--) { s->failed_pc=0x0c04753au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04753cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04753cu; return 0; } return 1;
P_0c0475f0: /* original c401, guest PC 0x0c0475f0 */
if(!s->budget--) { s->failed_pc=0x0c0475f0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,s->gbr+1,1);
goto P_0c0475f2;
P_0c0475f2: /* original d20a, guest PC 0x0c0475f2 */
if(!s->budget--) { s->failed_pc=0x0c0475f2u; return 0; }
r[2]=read(ram,0x0c04761cu,4);
goto P_0c0475f4;
P_0c0475f4: /* original 8803, guest PC 0x0c0475f4 */
if(!s->budget--) { s->failed_pc=0x0c0475f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0475f6;
P_0c0475f6: /* original 4408, guest PC 0x0c0475f6 */
if(!s->budget--) { s->failed_pc=0x0c0475f6u; return 0; }
r[4]<<=2;
goto P_0c0475f8;
P_0c0475f8: /* original 6023, guest PC 0x0c0475f8 */
if(!s->budget--) { s->failed_pc=0x0c0475f8u; return 0; }
r[0]=r[2];
goto P_0c0475fa;
P_0c0475fa: /* original 8907, guest PC 0x0c0475fa */
if(!s->budget--) { s->failed_pc=0x0c0475fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04760c; }
goto P_0c0475fc;
P_0c0475fc: /* original 6155, guest PC 0x0c0475fc */
if(!s->budget--) { s->failed_pc=0x0c0475fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c0475fe;
P_0c0475fe: /* original 4610, guest PC 0x0c0475fe */
if(!s->budget--) { s->failed_pc=0x0c0475feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047600;
P_0c047600: /* original 0415, guest PC 0x0c047600 */
if(!s->budget--) { s->failed_pc=0x0c047600u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c047602;
P_0c047602: /* original 8ffb, guest PC 0x0c047602 */
if(!s->budget--) { s->failed_pc=0x0c047602u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0475fc; }
goto P_0c047606;
P_0c047604: /* original 7404, guest PC 0x0c047604 */
if(!s->budget--) { s->failed_pc=0x0c047604u; return 0; }
r[4]+=0x00000004u;
goto P_0c047606;
P_0c047606: /* original e001, guest PC 0x0c047606 */
if(!s->budget--) { s->failed_pc=0x0c047606u; return 0; }
r[0]=0x00000001u;
goto P_0c047608;
P_0c047608: /* original 000b, guest PC 0x0c047608 */
if(!s->budget--) { s->failed_pc=0x0c047608u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04760a: /* original c000, guest PC 0x0c04760a */
if(!s->budget--) { s->failed_pc=0x0c04760au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
goto P_0c04760c;
P_0c04760c: /* original 6156, guest PC 0x0c04760c */
if(!s->budget--) { s->failed_pc=0x0c04760cu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c04760e;
P_0c04760e: /* original 4610, guest PC 0x0c04760e */
if(!s->budget--) { s->failed_pc=0x0c04760eu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047610;
P_0c047610: /* original 0416, guest PC 0x0c047610 */
if(!s->budget--) { s->failed_pc=0x0c047610u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c047612;
P_0c047612: /* original 8ffb, guest PC 0x0c047612 */
if(!s->budget--) { s->failed_pc=0x0c047612u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c04760c; }
goto P_0c047616;
P_0c047614: /* original 7404, guest PC 0x0c047614 */
if(!s->budget--) { s->failed_pc=0x0c047614u; return 0; }
r[4]+=0x00000004u;
goto P_0c047616;
P_0c047616: /* original e001, guest PC 0x0c047616 */
if(!s->budget--) { s->failed_pc=0x0c047616u; return 0; }
r[0]=0x00000001u;
goto P_0c047618;
P_0c047618: /* original 000b, guest PC 0x0c047618 */
if(!s->budget--) { s->failed_pc=0x0c047618u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04761a: /* original c000, guest PC 0x0c04761a */
if(!s->budget--) { s->failed_pc=0x0c04761au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
if(!vf3_matrix_family(0x0c04761cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04761cu; return 0; } return 1;
P_0c05e754: /* original 2fe6, guest PC 0x0c05e754 */
if(!s->budget--) { s->failed_pc=0x0c05e754u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e756;
P_0c05e756: /* original 2fd6, guest PC 0x0c05e756 */
if(!s->budget--) { s->failed_pc=0x0c05e756u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e758;
P_0c05e758: /* original 4f22, guest PC 0x0c05e758 */
if(!s->budget--) { s->failed_pc=0x0c05e758u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e75a;
P_0c05e75a: /* original b383, guest PC 0x0c05e75a */
if(!s->budget--) { s->failed_pc=0x0c05e75au; return 0; }
target=code_base|0x0c05ee64u; r[16]=code_base|0x0c05e75eu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e75eu) { target=s->pc; goto dispatch; }
goto P_0c05e75e;
P_0c05e75c: /* original 6e43, guest PC 0x0c05e75c */
if(!s->budget--) { s->failed_pc=0x0c05e75cu; return 0; }
r[14]=r[4];
goto P_0c05e75e;
P_0c05e75e: /* original 6d03, guest PC 0x0c05e75e */
if(!s->budget--) { s->failed_pc=0x0c05e75eu; return 0; }
r[13]=r[0];
goto P_0c05e760;
P_0c05e760: /* original 2dd8, guest PC 0x0c05e760 */
if(!s->budget--) { s->failed_pc=0x0c05e760u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05e762;
P_0c05e762: /* original 8b12, guest PC 0x0c05e762 */
if(!s->budget--) { s->failed_pc=0x0c05e762u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e78a; }
goto P_0c05e764;
P_0c05e764: /* original 60e2, guest PC 0x0c05e764 */
if(!s->budget--) { s->failed_pc=0x0c05e764u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05e766;
P_0c05e766: /* original 600d, guest PC 0x0c05e766 */
if(!s->budget--) { s->failed_pc=0x0c05e766u; return 0; }
r[0]=r[0]&65535u;
goto P_0c05e768;
P_0c05e768: /* original 8803, guest PC 0x0c05e768 */
if(!s->budget--) { s->failed_pc=0x0c05e768u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e76a;
P_0c05e76a: /* original 8b04, guest PC 0x0c05e76a */
if(!s->budget--) { s->failed_pc=0x0c05e76au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e776; }
goto P_0c05e76c;
P_0c05e76c: /* original d235, guest PC 0x0c05e76c */
if(!s->budget--) { s->failed_pc=0x0c05e76cu; return 0; }
r[2]=read(ram,0x0c05e844u,4);
goto P_0c05e76e;
P_0c05e76e: /* original 420b, guest PC 0x0c05e76e */
if(!s->budget--) { s->failed_pc=0x0c05e76eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05e772u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e772u) { target=s->pc; goto dispatch; }
goto P_0c05e772;
P_0c05e770: /* original 64e3, guest PC 0x0c05e770 */
if(!s->budget--) { s->failed_pc=0x0c05e770u; return 0; }
r[4]=r[14];
goto P_0c05e772;
P_0c05e772: /* original a004, guest PC 0x0c05e772 */
if(!s->budget--) { s->failed_pc=0x0c05e772u; return 0; }
goto P_0c05e77e;
P_0c05e774: /* original 0009, guest PC 0x0c05e774 */
if(!s->budget--) { s->failed_pc=0x0c05e774u; return 0; }
goto P_0c05e776;
P_0c05e776: /* original 65e3, guest PC 0x0c05e776 */
if(!s->budget--) { s->failed_pc=0x0c05e776u; return 0; }
r[5]=r[14];
goto P_0c05e778;
P_0c05e778: /* original d233, guest PC 0x0c05e778 */
if(!s->budget--) { s->failed_pc=0x0c05e778u; return 0; }
r[2]=read(ram,0x0c05e848u,4);
goto P_0c05e77a;
P_0c05e77a: /* original 420b, guest PC 0x0c05e77a */
if(!s->budget--) { s->failed_pc=0x0c05e77au; return 0; }
target=r[2];
r[16]=code_base|0x0c05e77eu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e77eu) { target=s->pc; goto dispatch; }
goto P_0c05e77e;
P_0c05e77c: /* original 54e5, guest PC 0x0c05e77c */
if(!s->budget--) { s->failed_pc=0x0c05e77cu; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c05e77e;
P_0c05e77e: /* original 8803, guest PC 0x0c05e77e */
if(!s->budget--) { s->failed_pc=0x0c05e77eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e780;
P_0c05e780: /* original 8f03, guest PC 0x0c05e780 */
if(!s->budget--) { s->failed_pc=0x0c05e780u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(!cond) { goto P_0c05e78a; }
goto P_0c05e784;
P_0c05e782: /* original 6d03, guest PC 0x0c05e782 */
if(!s->budget--) { s->failed_pc=0x0c05e782u; return 0; }
r[13]=r[0];
goto P_0c05e784;
P_0c05e784: /* original d231, guest PC 0x0c05e784 */
if(!s->budget--) { s->failed_pc=0x0c05e784u; return 0; }
r[2]=read(ram,0x0c05e84cu,4);
goto P_0c05e786;
P_0c05e786: /* original 420b, guest PC 0x0c05e786 */
if(!s->budget--) { s->failed_pc=0x0c05e786u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e78au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e78au) { target=s->pc; goto dispatch; }
goto P_0c05e78a;
P_0c05e788: /* original e403, guest PC 0x0c05e788 */
if(!s->budget--) { s->failed_pc=0x0c05e788u; return 0; }
r[4]=0x00000003u;
goto P_0c05e78a;
P_0c05e78a: /* original 60d3, guest PC 0x0c05e78a */
if(!s->budget--) { s->failed_pc=0x0c05e78au; return 0; }
r[0]=r[13];
goto P_0c05e78c;
P_0c05e78c: /* original 0009, guest PC 0x0c05e78c */
if(!s->budget--) { s->failed_pc=0x0c05e78cu; return 0; }
goto P_0c05e78e;
P_0c05e78e: /* original 4f26, guest PC 0x0c05e78e */
if(!s->budget--) { s->failed_pc=0x0c05e78eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e790;
P_0c05e790: /* original 6df6, guest PC 0x0c05e790 */
if(!s->budget--) { s->failed_pc=0x0c05e790u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05e792;
P_0c05e792: /* original 000b, guest PC 0x0c05e792 */
if(!s->budget--) { s->failed_pc=0x0c05e792u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e794: /* original 6ef6, guest PC 0x0c05e794 */
if(!s->budget--) { s->failed_pc=0x0c05e794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05e796u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e796u; return 0; } return 1;
P_0c05e94e: /* original 2fe6, guest PC 0x0c05e94e */
if(!s->budget--) { s->failed_pc=0x0c05e94eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e950;
P_0c05e950: /* original 4f22, guest PC 0x0c05e950 */
if(!s->budget--) { s->failed_pc=0x0c05e950u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e952;
P_0c05e952: /* original 6063, guest PC 0x0c05e952 */
if(!s->budget--) { s->failed_pc=0x0c05e952u; return 0; }
r[0]=r[6];
goto P_0c05e954;
P_0c05e954: /* original 0009, guest PC 0x0c05e954 */
if(!s->budget--) { s->failed_pc=0x0c05e954u; return 0; }
goto P_0c05e956;
P_0c05e956: /* original 8801, guest PC 0x0c05e956 */
if(!s->budget--) { s->failed_pc=0x0c05e956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05e958;
P_0c05e958: /* original 8d04, guest PC 0x0c05e958 */
if(!s->budget--) { s->failed_pc=0x0c05e958u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c05e964; }
goto P_0c05e95c;
P_0c05e95a: /* original 6e43, guest PC 0x0c05e95a */
if(!s->budget--) { s->failed_pc=0x0c05e95au; return 0; }
r[14]=r[4];
goto P_0c05e95c;
P_0c05e95c: /* original 6073, guest PC 0x0c05e95c */
if(!s->budget--) { s->failed_pc=0x0c05e95cu; return 0; }
r[0]=r[7];
goto P_0c05e95e;
P_0c05e95e: /* original 0009, guest PC 0x0c05e95e */
if(!s->budget--) { s->failed_pc=0x0c05e95eu; return 0; }
goto P_0c05e960;
P_0c05e960: /* original 8801, guest PC 0x0c05e960 */
if(!s->budget--) { s->failed_pc=0x0c05e960u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05e962;
P_0c05e962: /* original 8b03, guest PC 0x0c05e962 */
if(!s->budget--) { s->failed_pc=0x0c05e962u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e96c; }
goto P_0c05e964;
P_0c05e964: /* original 4f26, guest PC 0x0c05e964 */
if(!s->budget--) { s->failed_pc=0x0c05e964u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e966;
P_0c05e966: /* original e004, guest PC 0x0c05e966 */
if(!s->budget--) { s->failed_pc=0x0c05e966u; return 0; }
r[0]=0x00000004u;
goto P_0c05e968;
P_0c05e968: /* original 000b, guest PC 0x0c05e968 */
if(!s->budget--) { s->failed_pc=0x0c05e968u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e96a: /* original 6ef6, guest PC 0x0c05e96a */
if(!s->budget--) { s->failed_pc=0x0c05e96au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05e96c;
P_0c05e96c: /* original 60e2, guest PC 0x0c05e96c */
if(!s->budget--) { s->failed_pc=0x0c05e96cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05e96e;
P_0c05e96e: /* original 600d, guest PC 0x0c05e96e */
if(!s->budget--) { s->failed_pc=0x0c05e96eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05e970;
P_0c05e970: /* original 8803, guest PC 0x0c05e970 */
if(!s->budget--) { s->failed_pc=0x0c05e970u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e972;
P_0c05e972: /* original 8b05, guest PC 0x0c05e972 */
if(!s->budget--) { s->failed_pc=0x0c05e972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e980; }
goto P_0c05e974;
P_0c05e974: /* original 57e6, guest PC 0x0c05e974 */
if(!s->budget--) { s->failed_pc=0x0c05e974u; return 0; }
r[7]=read(ram,r[14]+24,4);
goto P_0c05e976;
P_0c05e976: /* original 56e3, guest PC 0x0c05e976 */
if(!s->budget--) { s->failed_pc=0x0c05e976u; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05e978;
P_0c05e978: /* original b4f3, guest PC 0x0c05e978 */
if(!s->budget--) { s->failed_pc=0x0c05e978u; return 0; }
target=code_base|0x0c05f362u; r[16]=code_base|0x0c05e97cu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e97cu) { target=s->pc; goto dispatch; }
goto P_0c05e97c;
P_0c05e97a: /* original 54e7, guest PC 0x0c05e97a */
if(!s->budget--) { s->failed_pc=0x0c05e97au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e97c;
P_0c05e97c: /* original a016, guest PC 0x0c05e97c */
if(!s->budget--) { s->failed_pc=0x0c05e97cu; return 0; }
goto P_0c05e9ac;
P_0c05e97e: /* original 0009, guest PC 0x0c05e97e */
if(!s->budget--) { s->failed_pc=0x0c05e97eu; return 0; }
goto P_0c05e980;
P_0c05e980: /* original 54e6, guest PC 0x0c05e980 */
if(!s->budget--) { s->failed_pc=0x0c05e980u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c05e982;
P_0c05e982: /* original e204, guest PC 0x0c05e982 */
if(!s->budget--) { s->failed_pc=0x0c05e982u; return 0; }
r[2]=0x00000004u;
goto P_0c05e984;
P_0c05e984: /* original 2248, guest PC 0x0c05e984 */
if(!s->budget--) { s->failed_pc=0x0c05e984u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c05e986;
P_0c05e986: /* original 890d, guest PC 0x0c05e986 */
if(!s->budget--) { s->failed_pc=0x0c05e986u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e9a4; }
goto P_0c05e988;
P_0c05e988: /* original e101, guest PC 0x0c05e988 */
if(!s->budget--) { s->failed_pc=0x0c05e988u; return 0; }
r[1]=0x00000001u;
goto P_0c05e98a;
P_0c05e98a: /* original 2148, guest PC 0x0c05e98a */
if(!s->budget--) { s->failed_pc=0x0c05e98au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c05e98c;
P_0c05e98c: /* original 890a, guest PC 0x0c05e98c */
if(!s->budget--) { s->failed_pc=0x0c05e98cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e9a4; }
goto P_0c05e98e;
P_0c05e98e: /* original e208, guest PC 0x0c05e98e */
if(!s->budget--) { s->failed_pc=0x0c05e98eu; return 0; }
r[2]=0x00000008u;
goto P_0c05e990;
P_0c05e990: /* original 2248, guest PC 0x0c05e990 */
if(!s->budget--) { s->failed_pc=0x0c05e990u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c05e992;
P_0c05e992: /* original 8b07, guest PC 0x0c05e992 */
if(!s->budget--) { s->failed_pc=0x0c05e992u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e9a4; }
goto P_0c05e994;
P_0c05e994: /* original e120, guest PC 0x0c05e994 */
if(!s->budget--) { s->failed_pc=0x0c05e994u; return 0; }
r[1]=0x00000020u;
goto P_0c05e996;
P_0c05e996: /* original 2148, guest PC 0x0c05e996 */
if(!s->budget--) { s->failed_pc=0x0c05e996u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c05e998;
P_0c05e998: /* original 8b04, guest PC 0x0c05e998 */
if(!s->budget--) { s->failed_pc=0x0c05e998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e9a4; }
goto P_0c05e99a;
P_0c05e99a: /* original 56e3, guest PC 0x0c05e99a */
if(!s->budget--) { s->failed_pc=0x0c05e99au; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05e99c;
P_0c05e99c: /* original b4b8, guest PC 0x0c05e99c */
if(!s->budget--) { s->failed_pc=0x0c05e99cu; return 0; }
target=code_base|0x0c05f310u; r[16]=code_base|0x0c05e9a0u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e9a0u) { target=s->pc; goto dispatch; }
goto P_0c05e9a0;
P_0c05e99e: /* original 54e7, guest PC 0x0c05e99e */
if(!s->budget--) { s->failed_pc=0x0c05e99eu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e9a0;
P_0c05e9a0: /* original a004, guest PC 0x0c05e9a0 */
if(!s->budget--) { s->failed_pc=0x0c05e9a0u; return 0; }
goto P_0c05e9ac;
P_0c05e9a2: /* original 0009, guest PC 0x0c05e9a2 */
if(!s->budget--) { s->failed_pc=0x0c05e9a2u; return 0; }
goto P_0c05e9a4;
P_0c05e9a4: /* original 56e5, guest PC 0x0c05e9a4 */
if(!s->budget--) { s->failed_pc=0x0c05e9a4u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c05e9a6;
P_0c05e9a6: /* original d236, guest PC 0x0c05e9a6 */
if(!s->budget--) { s->failed_pc=0x0c05e9a6u; return 0; }
r[2]=read(ram,0x0c05ea80u,4);
goto P_0c05e9a8;
P_0c05e9a8: /* original 420b, guest PC 0x0c05e9a8 */
if(!s->budget--) { s->failed_pc=0x0c05e9a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e9acu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e9acu) { target=s->pc; goto dispatch; }
goto P_0c05e9ac;
P_0c05e9aa: /* original 54e7, guest PC 0x0c05e9aa */
if(!s->budget--) { s->failed_pc=0x0c05e9aau; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e9ac;
P_0c05e9ac: /* original e000, guest PC 0x0c05e9ac */
if(!s->budget--) { s->failed_pc=0x0c05e9acu; return 0; }
r[0]=0x00000000u;
goto P_0c05e9ae;
P_0c05e9ae: /* original 4f26, guest PC 0x0c05e9ae */
if(!s->budget--) { s->failed_pc=0x0c05e9aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e9b0;
P_0c05e9b0: /* original 000b, guest PC 0x0c05e9b0 */
if(!s->budget--) { s->failed_pc=0x0c05e9b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e9b2: /* original 6ef6, guest PC 0x0c05e9b2 */
if(!s->budget--) { s->failed_pc=0x0c05e9b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05e9b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e9b4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
