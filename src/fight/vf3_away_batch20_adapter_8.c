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
int vf3_away_batch20_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042d68u: goto P_0c042d68;
case 0x0c042d6au: goto P_0c042d6a;
case 0x0c042d6cu: goto P_0c042d6c;
case 0x0c042d6eu: goto P_0c042d6e;
case 0x0c042d70u: goto P_0c042d70;
case 0x0c042d72u: goto P_0c042d72;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c046aeeu: goto P_0c046aee;
case 0x0c046af0u: goto P_0c046af0;
case 0x0c046af2u: goto P_0c046af2;
case 0x0c046af4u: goto P_0c046af4;
case 0x0c046af6u: goto P_0c046af6;
case 0x0c046af8u: goto P_0c046af8;
case 0x0c046afau: goto P_0c046afa;
case 0x0c046afcu: goto P_0c046afc;
case 0x0c046afeu: goto P_0c046afe;
case 0x0c046b00u: goto P_0c046b00;
case 0x0c046b02u: goto P_0c046b02;
case 0x0c046b04u: goto P_0c046b04;
case 0x0c046b06u: goto P_0c046b06;
case 0x0c046b08u: goto P_0c046b08;
case 0x0c046b0au: goto P_0c046b0a;
case 0x0c046b0cu: goto P_0c046b0c;
case 0x0c046b0eu: goto P_0c046b0e;
case 0x0c046b10u: goto P_0c046b10;
case 0x0c046b12u: goto P_0c046b12;
case 0x0c046b14u: goto P_0c046b14;
case 0x0c046b16u: goto P_0c046b16;
case 0x0c046b18u: goto P_0c046b18;
case 0x0c046b1au: goto P_0c046b1a;
case 0x0c046b1cu: goto P_0c046b1c;
case 0x0c046b1eu: goto P_0c046b1e;
case 0x0c046b20u: goto P_0c046b20;
case 0x0c046b22u: goto P_0c046b22;
case 0x0c046b24u: goto P_0c046b24;
case 0x0c046b26u: goto P_0c046b26;
case 0x0c046b28u: goto P_0c046b28;
case 0x0c046b2au: goto P_0c046b2a;
case 0x0c046b2cu: goto P_0c046b2c;
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
case 0x0c0475aau: goto P_0c0475aa;
case 0x0c0475acu: goto P_0c0475ac;
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
case 0x0c04a330u: goto P_0c04a330;
case 0x0c04a332u: goto P_0c04a332;
case 0x0c04a334u: goto P_0c04a334;
case 0x0c04a336u: goto P_0c04a336;
case 0x0c04a338u: goto P_0c04a338;
case 0x0c04a33au: goto P_0c04a33a;
case 0x0c04a33cu: goto P_0c04a33c;
case 0x0c04a33eu: goto P_0c04a33e;
case 0x0c04a340u: goto P_0c04a340;
case 0x0c04a342u: goto P_0c04a342;
case 0x0c04a344u: goto P_0c04a344;
case 0x0c04a346u: goto P_0c04a346;
case 0x0c04a348u: goto P_0c04a348;
case 0x0c04a34au: goto P_0c04a34a;
case 0x0c04a34cu: goto P_0c04a34c;
case 0x0c04a34eu: goto P_0c04a34e;
case 0x0c04a350u: goto P_0c04a350;
case 0x0c04a352u: goto P_0c04a352;
case 0x0c04a354u: goto P_0c04a354;
case 0x0c04a356u: goto P_0c04a356;
case 0x0c04a358u: goto P_0c04a358;
case 0x0c04a35au: goto P_0c04a35a;
case 0x0c04a35cu: goto P_0c04a35c;
case 0x0c04a35eu: goto P_0c04a35e;
case 0x0c04a360u: goto P_0c04a360;
case 0x0c04a362u: goto P_0c04a362;
case 0x0c04a364u: goto P_0c04a364;
case 0x0c04a366u: goto P_0c04a366;
case 0x0c04a368u: goto P_0c04a368;
case 0x0c04a36au: goto P_0c04a36a;
case 0x0c04a36cu: goto P_0c04a36c;
case 0x0c04a36eu: goto P_0c04a36e;
case 0x0c04a370u: goto P_0c04a370;
case 0x0c04a372u: goto P_0c04a372;
case 0x0c04a374u: goto P_0c04a374;
case 0x0c04a376u: goto P_0c04a376;
case 0x0c04a378u: goto P_0c04a378;
case 0x0c04a37au: goto P_0c04a37a;
case 0x0c04a37cu: goto P_0c04a37c;
case 0x0c04a37eu: goto P_0c04a37e;
case 0x0c04a380u: goto P_0c04a380;
case 0x0c04a382u: goto P_0c04a382;
case 0x0c04a384u: goto P_0c04a384;
case 0x0c04a386u: goto P_0c04a386;
case 0x0c04a388u: goto P_0c04a388;
case 0x0c04a38au: goto P_0c04a38a;
case 0x0c04a38cu: goto P_0c04a38c;
case 0x0c04a38eu: goto P_0c04a38e;
case 0x0c04a390u: goto P_0c04a390;
case 0x0c04a392u: goto P_0c04a392;
case 0x0c04a394u: goto P_0c04a394;
case 0x0c04a396u: goto P_0c04a396;
case 0x0c04a398u: goto P_0c04a398;
case 0x0c04a39au: goto P_0c04a39a;
case 0x0c04a39cu: goto P_0c04a39c;
case 0x0c04a39eu: goto P_0c04a39e;
case 0x0c04a3a0u: goto P_0c04a3a0;
case 0x0c04a3a2u: goto P_0c04a3a2;
case 0x0c04a3a4u: goto P_0c04a3a4;
case 0x0c04a3a6u: goto P_0c04a3a6;
case 0x0c04a3a8u: goto P_0c04a3a8;
case 0x0c04a3aau: goto P_0c04a3aa;
case 0x0c04a3acu: goto P_0c04a3ac;
case 0x0c04a3aeu: goto P_0c04a3ae;
case 0x0c04a3b0u: goto P_0c04a3b0;
case 0x0c04a3b2u: goto P_0c04a3b2;
case 0x0c04a3b4u: goto P_0c04a3b4;
case 0x0c04a3b6u: goto P_0c04a3b6;
case 0x0c04a3b8u: goto P_0c04a3b8;
case 0x0c04a3bau: goto P_0c04a3ba;
case 0x0c04a3bcu: goto P_0c04a3bc;
case 0x0c04a3beu: goto P_0c04a3be;
case 0x0c04a3c0u: goto P_0c04a3c0;
case 0x0c04a3c2u: goto P_0c04a3c2;
case 0x0c04a3c4u: goto P_0c04a3c4;
case 0x0c04a3c6u: goto P_0c04a3c6;
case 0x0c04a3c8u: goto P_0c04a3c8;
case 0x0c04a3cau: goto P_0c04a3ca;
case 0x0c04a3ccu: goto P_0c04a3cc;
case 0x0c04a3ceu: goto P_0c04a3ce;
case 0x0c04a3d0u: goto P_0c04a3d0;
case 0x0c04a3d2u: goto P_0c04a3d2;
case 0x0c04a3d4u: goto P_0c04a3d4;
case 0x0c04a3d6u: goto P_0c04a3d6;
case 0x0c04a3d8u: goto P_0c04a3d8;
case 0x0c04a3dau: goto P_0c04a3da;
case 0x0c04a3dcu: goto P_0c04a3dc;
case 0x0c04a3deu: goto P_0c04a3de;
case 0x0c04a3e0u: goto P_0c04a3e0;
case 0x0c04a3e2u: goto P_0c04a3e2;
case 0x0c04a3e4u: goto P_0c04a3e4;
case 0x0c04a3e6u: goto P_0c04a3e6;
case 0x0c04a3e8u: goto P_0c04a3e8;
case 0x0c04a3eau: goto P_0c04a3ea;
case 0x0c04a3ecu: goto P_0c04a3ec;
case 0x0c04a3eeu: goto P_0c04a3ee;
case 0x0c04a3f0u: goto P_0c04a3f0;
case 0x0c04a3f2u: goto P_0c04a3f2;
case 0x0c04a3f4u: goto P_0c04a3f4;
case 0x0c04a3f6u: goto P_0c04a3f6;
case 0x0c04a3f8u: goto P_0c04a3f8;
case 0x0c04a3fau: goto P_0c04a3fa;
case 0x0c04a3fcu: goto P_0c04a3fc;
case 0x0c04a3feu: goto P_0c04a3fe;
case 0x0c04a400u: goto P_0c04a400;
case 0x0c04a402u: goto P_0c04a402;
case 0x0c04a404u: goto P_0c04a404;
case 0x0c04a406u: goto P_0c04a406;
case 0x0c04a408u: goto P_0c04a408;
case 0x0c04a40au: goto P_0c04a40a;
case 0x0c04a40cu: goto P_0c04a40c;
case 0x0c04a40eu: goto P_0c04a40e;
case 0x0c04a410u: goto P_0c04a410;
case 0x0c04a412u: goto P_0c04a412;
case 0x0c04a414u: goto P_0c04a414;
case 0x0c04a416u: goto P_0c04a416;
case 0x0c04a418u: goto P_0c04a418;
case 0x0c04a41au: goto P_0c04a41a;
case 0x0c04a41cu: goto P_0c04a41c;
case 0x0c04a41eu: goto P_0c04a41e;
case 0x0c04a420u: goto P_0c04a420;
case 0x0c04a422u: goto P_0c04a422;
case 0x0c04a424u: goto P_0c04a424;
case 0x0c04a426u: goto P_0c04a426;
case 0x0c04a428u: goto P_0c04a428;
case 0x0c04a42au: goto P_0c04a42a;
case 0x0c04a42cu: goto P_0c04a42c;
case 0x0c04a42eu: goto P_0c04a42e;
case 0x0c04a430u: goto P_0c04a430;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042d68: /* original d202, guest PC 0x0c042d68 */
if(!s->budget--) { s->failed_pc=0x0c042d68u; return 0; }
r[2]=read(ram,0x0c042d74u,4);
goto P_0c042d6a;
P_0c042d6a: /* original d103, guest PC 0x0c042d6a */
if(!s->budget--) { s->failed_pc=0x0c042d6au; return 0; }
r[1]=read(ram,0x0c042d78u,4);
goto P_0c042d6c;
P_0c042d6c: /* original e000, guest PC 0x0c042d6c */
if(!s->budget--) { s->failed_pc=0x0c042d6cu; return 0; }
r[0]=0x00000000u;
goto P_0c042d6e;
P_0c042d6e: /* original 2212, guest PC 0x0c042d6e */
if(!s->budget--) { s->failed_pc=0x0c042d6eu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042d70;
P_0c042d70: /* original 000b, guest PC 0x0c042d70 */
if(!s->budget--) { s->failed_pc=0x0c042d70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042d72: /* original 62f6, guest PC 0x0c042d72 */
if(!s->budget--) { s->failed_pc=0x0c042d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042d74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042d74u; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c046aee: /* original 4f22, guest PC 0x0c046aee */
if(!s->budget--) { s->failed_pc=0x0c046aeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046af0;
P_0c046af0: /* original d36f, guest PC 0x0c046af0 */
if(!s->budget--) { s->failed_pc=0x0c046af0u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046af2;
P_0c046af2: /* original 430b, guest PC 0x0c046af2 */
if(!s->budget--) { s->failed_pc=0x0c046af2u; return 0; }
target=r[3];
r[16]=code_base|0x0c046af6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046af6u) { target=s->pc; goto dispatch; }
goto P_0c046af6;
P_0c046af4: /* original 0009, guest PC 0x0c046af4 */
if(!s->budget--) { s->failed_pc=0x0c046af4u; return 0; }
goto P_0c046af6;
P_0c046af6: /* original 2008, guest PC 0x0c046af6 */
if(!s->budget--) { s->failed_pc=0x0c046af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046af8;
P_0c046af8: /* original 8902, guest PC 0x0c046af8 */
if(!s->budget--) { s->failed_pc=0x0c046af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046b00; }
goto P_0c046afa;
P_0c046afa: /* original 4f26, guest PC 0x0c046afa */
if(!s->budget--) { s->failed_pc=0x0c046afau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046afc;
P_0c046afc: /* original 000b, guest PC 0x0c046afc */
if(!s->budget--) { s->failed_pc=0x0c046afcu; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046afe: /* original e0ff, guest PC 0x0c046afe */
if(!s->budget--) { s->failed_pc=0x0c046afeu; return 0; }
r[0]=0xffffffffu;
goto P_0c046b00;
P_0c046b00: /* original e000, guest PC 0x0c046b00 */
if(!s->budget--) { s->failed_pc=0x0c046b00u; return 0; }
r[0]=0x00000000u;
goto P_0c046b02;
P_0c046b02: /* original 4f26, guest PC 0x0c046b02 */
if(!s->budget--) { s->failed_pc=0x0c046b02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046b04;
P_0c046b04: /* original 000b, guest PC 0x0c046b04 */
if(!s->budget--) { s->failed_pc=0x0c046b04u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046b06: /* original 0009, guest PC 0x0c046b06 */
if(!s->budget--) { s->failed_pc=0x0c046b06u; return 0; }
goto P_0c046b08;
P_0c046b08: /* original 4f22, guest PC 0x0c046b08 */
if(!s->budget--) { s->failed_pc=0x0c046b08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046b0a;
P_0c046b0a: /* original d369, guest PC 0x0c046b0a */
if(!s->budget--) { s->failed_pc=0x0c046b0au; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046b0c;
P_0c046b0c: /* original 7ffc, guest PC 0x0c046b0c */
if(!s->budget--) { s->failed_pc=0x0c046b0cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c046b0e;
P_0c046b0e: /* original 430b, guest PC 0x0c046b0e */
if(!s->budget--) { s->failed_pc=0x0c046b0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c046b12u;
write(ram,r[15],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046b12u) { target=s->pc; goto dispatch; }
goto P_0c046b12;
P_0c046b10: /* original 2f42, guest PC 0x0c046b10 */
if(!s->budget--) { s->failed_pc=0x0c046b10u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046b12;
P_0c046b12: /* original 2008, guest PC 0x0c046b12 */
if(!s->budget--) { s->failed_pc=0x0c046b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046b14;
P_0c046b14: /* original 8903, guest PC 0x0c046b14 */
if(!s->budget--) { s->failed_pc=0x0c046b14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046b1e; }
goto P_0c046b16;
P_0c046b16: /* original 7f04, guest PC 0x0c046b16 */
if(!s->budget--) { s->failed_pc=0x0c046b16u; return 0; }
r[15]+=0x00000004u;
goto P_0c046b18;
P_0c046b18: /* original 4f26, guest PC 0x0c046b18 */
if(!s->budget--) { s->failed_pc=0x0c046b18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046b1a;
P_0c046b1a: /* original 000b, guest PC 0x0c046b1a */
if(!s->budget--) { s->failed_pc=0x0c046b1au; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046b1c: /* original e0ff, guest PC 0x0c046b1c */
if(!s->budget--) { s->failed_pc=0x0c046b1cu; return 0; }
r[0]=0xffffffffu;
goto P_0c046b1e;
P_0c046b1e: /* original 60f2, guest PC 0x0c046b1e */
if(!s->budget--) { s->failed_pc=0x0c046b1eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c046b20;
P_0c046b20: /* original d167, guest PC 0x0c046b20 */
if(!s->budget--) { s->failed_pc=0x0c046b20u; return 0; }
r[1]=read(ram,0x0c046cc0u,4);
goto P_0c046b22;
P_0c046b22: /* original 4008, guest PC 0x0c046b22 */
if(!s->budget--) { s->failed_pc=0x0c046b22u; return 0; }
r[0]<<=2;
goto P_0c046b24;
P_0c046b24: /* original 001e, guest PC 0x0c046b24 */
if(!s->budget--) { s->failed_pc=0x0c046b24u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c046b26;
P_0c046b26: /* original 7f04, guest PC 0x0c046b26 */
if(!s->budget--) { s->failed_pc=0x0c046b26u; return 0; }
r[15]+=0x00000004u;
goto P_0c046b28;
P_0c046b28: /* original 4f26, guest PC 0x0c046b28 */
if(!s->budget--) { s->failed_pc=0x0c046b28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046b2a;
P_0c046b2a: /* original 000b, guest PC 0x0c046b2a */
if(!s->budget--) { s->failed_pc=0x0c046b2au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046b2c: /* original 0009, guest PC 0x0c046b2c */
if(!s->budget--) { s->failed_pc=0x0c046b2cu; return 0; }
if(!vf3_matrix_family(0x0c046b2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046b2eu; return 0; } return 1;
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
P_0c0475aa: /* original 000b, guest PC 0x0c0475aa */
if(!s->budget--) { s->failed_pc=0x0c0475aau; return 0; }
target=r[16];
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
s->pc=target; return ram->oob==0;
P_0c0475ac: /* original 0483, guest PC 0x0c0475ac */
if(!s->budget--) { s->failed_pc=0x0c0475acu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
if(!vf3_matrix_family(0x0c0475aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0475aeu; return 0; } return 1;
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
P_0c04a330: /* original 6e43, guest PC 0x0c04a330 */
if(!s->budget--) { s->failed_pc=0x0c04a330u; return 0; }
r[14]=r[4];
goto P_0c04a332;
P_0c04a332: /* original 6042, guest PC 0x0c04a332 */
if(!s->budget--) { s->failed_pc=0x0c04a332u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a334;
P_0c04a334: /* original 7420, guest PC 0x0c04a334 */
if(!s->budget--) { s->failed_pc=0x0c04a334u; return 0; }
r[4]+=0x00000020u;
goto P_0c04a336;
P_0c04a336: /* original f18d, guest PC 0x0c04a336 */
if(!s->budget--) { s->failed_pc=0x0c04a336u; return 0; }
fr[1]=0;
goto P_0c04a338;
P_0c04a338: /* original c801, guest PC 0x0c04a338 */
if(!s->budget--) { s->failed_pc=0x0c04a338u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a33a;
P_0c04a33a: /* original 0483, guest PC 0x0c04a33a */
if(!s->budget--) { s->failed_pc=0x0c04a33au; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a33c;
P_0c04a33c: /* original 8b02, guest PC 0x0c04a33c */
if(!s->budget--) { s->failed_pc=0x0c04a33cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a344; }
goto P_0c04a33e;
P_0c04a33e: /* original 5ee1, guest PC 0x0c04a33e */
if(!s->budget--) { s->failed_pc=0x0c04a33eu; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a340;
P_0c04a340: /* original 74e8, guest PC 0x0c04a340 */
if(!s->budget--) { s->failed_pc=0x0c04a340u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a342;
P_0c04a342: /* original 3e4c, guest PC 0x0c04a342 */
if(!s->budget--) { s->failed_pc=0x0c04a342u; return 0; }
r[14]+=r[4];
goto P_0c04a344;
P_0c04a344: /* original f4e9, guest PC 0x0c04a344 */
if(!s->budget--) { s->failed_pc=0x0c04a344u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a346;
P_0c04a346: /* original f6e9, guest PC 0x0c04a346 */
if(!s->budget--) { s->failed_pc=0x0c04a346u; return 0; }
vf3_matrix_load(s,ram,6,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a348;
P_0c04a348: /* original f72d, guest PC 0x0c04a348 */
if(!s->budget--) { s->failed_pc=0x0c04a348u; return 0; }
fr[7]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a34a;
P_0c04a34a: /* original 6e43, guest PC 0x0c04a34a */
if(!s->budget--) { s->failed_pc=0x0c04a34au; return 0; }
r[14]=r[4];
goto P_0c04a34c;
P_0c04a34c: /* original 6042, guest PC 0x0c04a34c */
if(!s->budget--) { s->failed_pc=0x0c04a34cu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a34e;
P_0c04a34e: /* original 7420, guest PC 0x0c04a34e */
if(!s->budget--) { s->failed_pc=0x0c04a34eu; return 0; }
r[4]+=0x00000020u;
goto P_0c04a350;
P_0c04a350: /* original f5fd, guest PC 0x0c04a350 */
if(!s->budget--) { s->failed_pc=0x0c04a350u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04a352;
P_0c04a352: /* original c801, guest PC 0x0c04a352 */
if(!s->budget--) { s->failed_pc=0x0c04a352u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a354;
P_0c04a354: /* original 0483, guest PC 0x0c04a354 */
if(!s->budget--) { s->failed_pc=0x0c04a354u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a356;
P_0c04a356: /* original 8b02, guest PC 0x0c04a356 */
if(!s->budget--) { s->failed_pc=0x0c04a356u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a35e; }
goto P_0c04a358;
P_0c04a358: /* original 5ee1, guest PC 0x0c04a358 */
if(!s->budget--) { s->failed_pc=0x0c04a358u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a35a;
P_0c04a35a: /* original 74e8, guest PC 0x0c04a35a */
if(!s->budget--) { s->failed_pc=0x0c04a35au; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a35c;
P_0c04a35c: /* original 3e4c, guest PC 0x0c04a35c */
if(!s->budget--) { s->failed_pc=0x0c04a35cu; return 0; }
r[14]+=r[4];
goto P_0c04a35e;
P_0c04a35e: /* original f8e9, guest PC 0x0c04a35e */
if(!s->budget--) { s->failed_pc=0x0c04a35eu; return 0; }
vf3_matrix_load(s,ram,8,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a360;
P_0c04a360: /* original f170, guest PC 0x0c04a360 */
if(!s->budget--) { s->failed_pc=0x0c04a360u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[7],r[18],'+');
goto P_0c04a362;
P_0c04a362: /* original f79d, guest PC 0x0c04a362 */
if(!s->budget--) { s->failed_pc=0x0c04a362u; return 0; }
fr[7]=0x3f800000u;
goto P_0c04a364;
P_0c04a364: /* original f743, guest PC 0x0c04a364 */
if(!s->budget--) { s->failed_pc=0x0c04a364u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c04a366;
P_0c04a366: /* original fae9, guest PC 0x0c04a366 */
if(!s->budget--) { s->failed_pc=0x0c04a366u; return 0; }
vf3_matrix_load(s,ram,10,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a368;
P_0c04a368: /* original fb2d, guest PC 0x0c04a368 */
if(!s->budget--) { s->failed_pc=0x0c04a368u; return 0; }
fr[11]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a36a;
P_0c04a36a: /* original f48d, guest PC 0x0c04a36a */
if(!s->budget--) { s->failed_pc=0x0c04a36au; return 0; }
fr[4]=0;
goto P_0c04a36c;
P_0c04a36c: /* original f410, guest PC 0x0c04a36c */
if(!s->budget--) { s->failed_pc=0x0c04a36cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c04a36e;
P_0c04a36e: /* original 6e43, guest PC 0x0c04a36e */
if(!s->budget--) { s->failed_pc=0x0c04a36eu; return 0; }
r[14]=r[4];
goto P_0c04a370;
P_0c04a370: /* original 6042, guest PC 0x0c04a370 */
if(!s->budget--) { s->failed_pc=0x0c04a370u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a372;
P_0c04a372: /* original 7420, guest PC 0x0c04a372 */
if(!s->budget--) { s->failed_pc=0x0c04a372u; return 0; }
r[4]+=0x00000020u;
goto P_0c04a374;
P_0c04a374: /* original f9fd, guest PC 0x0c04a374 */
if(!s->budget--) { s->failed_pc=0x0c04a374u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c04a376;
P_0c04a376: /* original f18d, guest PC 0x0c04a376 */
if(!s->budget--) { s->failed_pc=0x0c04a376u; return 0; }
fr[1]=0;
goto P_0c04a378;
P_0c04a378: /* original c801, guest PC 0x0c04a378 */
if(!s->budget--) { s->failed_pc=0x0c04a378u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c04a37a;
P_0c04a37a: /* original 0483, guest PC 0x0c04a37a */
if(!s->budget--) { s->failed_pc=0x0c04a37au; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c04a37c;
P_0c04a37c: /* original 8b02, guest PC 0x0c04a37c */
if(!s->budget--) { s->failed_pc=0x0c04a37cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a384; }
goto P_0c04a37e;
P_0c04a37e: /* original 5ee1, guest PC 0x0c04a37e */
if(!s->budget--) { s->failed_pc=0x0c04a37eu; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c04a380;
P_0c04a380: /* original 74e8, guest PC 0x0c04a380 */
if(!s->budget--) { s->failed_pc=0x0c04a380u; return 0; }
r[4]+=0xffffffe8u;
goto P_0c04a382;
P_0c04a382: /* original 3e4c, guest PC 0x0c04a382 */
if(!s->budget--) { s->failed_pc=0x0c04a382u; return 0; }
r[14]+=r[4];
goto P_0c04a384;
P_0c04a384: /* original f1b0, guest PC 0x0c04a384 */
if(!s->budget--) { s->failed_pc=0x0c04a384u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'+');
goto P_0c04a386;
P_0c04a386: /* original fb9d, guest PC 0x0c04a386 */
if(!s->budget--) { s->failed_pc=0x0c04a386u; return 0; }
fr[11]=0x3f800000u;
goto P_0c04a388;
P_0c04a388: /* original fb83, guest PC 0x0c04a388 */
if(!s->budget--) { s->failed_pc=0x0c04a388u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[8],r[18],'/');
goto P_0c04a38a;
P_0c04a38a: /* original fce9, guest PC 0x0c04a38a */
if(!s->budget--) { s->failed_pc=0x0c04a38au; return 0; }
vf3_matrix_load(s,ram,12,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a38c;
P_0c04a38c: /* original fee9, guest PC 0x0c04a38c */
if(!s->budget--) { s->failed_pc=0x0c04a38cu; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c04a38e;
P_0c04a38e: /* original ff2d, guest PC 0x0c04a38e */
if(!s->budget--) { s->failed_pc=0x0c04a38eu; return 0; }
fr[15]=vf3_fpu_float(r[53],r[18]);
goto P_0c04a390;
P_0c04a390: /* original f88d, guest PC 0x0c04a390 */
if(!s->budget--) { s->failed_pc=0x0c04a390u; return 0; }
fr[8]=0;
goto P_0c04a392;
P_0c04a392: /* original f810, guest PC 0x0c04a392 */
if(!s->budget--) { s->failed_pc=0x0c04a392u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[1],r[18],'+');
goto P_0c04a394;
P_0c04a394: /* original fdfd, guest PC 0x0c04a394 */
if(!s->budget--) { s->failed_pc=0x0c04a394u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c04a396;
P_0c04a396: /* original f18d, guest PC 0x0c04a396 */
if(!s->budget--) { s->failed_pc=0x0c04a396u; return 0; }
fr[1]=0;
goto P_0c04a398;
P_0c04a398: /* original f1f0, guest PC 0x0c04a398 */
if(!s->budget--) { s->failed_pc=0x0c04a398u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'+');
goto P_0c04a39a;
P_0c04a39a: /* original ff9d, guest PC 0x0c04a39a */
if(!s->budget--) { s->failed_pc=0x0c04a39au; return 0; }
fr[15]=0x3f800000u;
goto P_0c04a39c;
P_0c04a39c: /* original ffc3, guest PC 0x0c04a39c */
if(!s->budget--) { s->failed_pc=0x0c04a39cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'/');
goto P_0c04a39e;
P_0c04a39e: /* original fc8d, guest PC 0x0c04a39e */
if(!s->budget--) { s->failed_pc=0x0c04a39eu; return 0; }
fr[12]=0;
goto P_0c04a3a0;
P_0c04a3a0: /* original fc10, guest PC 0x0c04a3a0 */
if(!s->budget--) { s->failed_pc=0x0c04a3a0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[1],r[18],'+');
goto P_0c04a3a2;
P_0c04a3a2: /* original e000, guest PC 0x0c04a3a2 */
if(!s->budget--) { s->failed_pc=0x0c04a3a2u; return 0; }
r[0]=0x00000000u;
goto P_0c04a3a4;
P_0c04a3a4: /* original f425, guest PC 0x0c04a3a4 */
if(!s->budget--) { s->failed_pc=0x0c04a3a4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c04a3a6;
P_0c04a3a6: /* original 4024, guest PC 0x0c04a3a6 */
if(!s->budget--) { s->failed_pc=0x0c04a3a6u; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3a8;
P_0c04a3a8: /* original f825, guest PC 0x0c04a3a8 */
if(!s->budget--) { s->failed_pc=0x0c04a3a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[2]))!=0);
goto P_0c04a3aa;
P_0c04a3aa: /* original 4024, guest PC 0x0c04a3aa */
if(!s->budget--) { s->failed_pc=0x0c04a3aau; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3ac;
P_0c04a3ac: /* original fc25, guest PC 0x0c04a3ac */
if(!s->budget--) { s->failed_pc=0x0c04a3acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[2]))!=0);
goto P_0c04a3ae;
P_0c04a3ae: /* original 4024, guest PC 0x0c04a3ae */
if(!s->budget--) { s->failed_pc=0x0c04a3aeu; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04a3b0;
P_0c04a3b0: /* original c807, guest PC 0x0c04a3b0 */
if(!s->budget--) { s->failed_pc=0x0c04a3b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c04a3b2;
P_0c04a3b2: /* original 8b41, guest PC 0x0c04a3b2 */
if(!s->budget--) { s->failed_pc=0x0c04a3b2u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c04a438u,s,ram); }
goto P_0c04a3b4;
P_0c04a3b4: /* original fb1d, guest PC 0x0c04a3b4 */
if(!s->budget--) { s->failed_pc=0x0c04a3b4u; return 0; }
r[53]=fr[11];
goto P_0c04a3b6;
P_0c04a3b6: /* original e018, guest PC 0x0c04a3b6 */
if(!s->budget--) { s->failed_pc=0x0c04a3b6u; return 0; }
r[0]=0x00000018u;
goto P_0c04a3b8;
P_0c04a3b8: /* original 7610, guest PC 0x0c04a3b8 */
if(!s->budget--) { s->failed_pc=0x0c04a3b8u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a3ba;
P_0c04a3ba: /* original f672, guest PC 0x0c04a3ba */
if(!s->budget--) { s->failed_pc=0x0c04a3bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a3bc;
P_0c04a3bc: /* original f572, guest PC 0x0c04a3bc */
if(!s->budget--) { s->failed_pc=0x0c04a3bcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a3be;
P_0c04a3be: /* original 015a, guest PC 0x0c04a3be */
if(!s->budget--) { s->failed_pc=0x0c04a3beu; return 0; }
r[1]=r[53];
goto P_0c04a3c0;
P_0c04a3c0: /* original f66b, guest PC 0x0c04a3c0 */
if(!s->budget--) { s->failed_pc=0x0c04a3c0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a3c2;
P_0c04a3c2: /* original fef2, guest PC 0x0c04a3c2 */
if(!s->budget--) { s->failed_pc=0x0c04a3c2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c04a3c4;
P_0c04a3c4: /* original f64b, guest PC 0x0c04a3c4 */
if(!s->budget--) { s->failed_pc=0x0c04a3c4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a3c6;
P_0c04a3c6: /* original fdf2, guest PC 0x0c04a3c6 */
if(!s->budget--) { s->failed_pc=0x0c04a3c6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c04a3c8;
P_0c04a3c8: /* original f6c7, guest PC 0x0c04a3c8 */
if(!s->budget--) { s->failed_pc=0x0c04a3c8u; return 0; }
vf3_matrix_store(s,ram,12,r[6]+r[0]);
goto P_0c04a3ca;
P_0c04a3ca: /* original fab2, guest PC 0x0c04a3ca */
if(!s->budget--) { s->failed_pc=0x0c04a3cau; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c04a3cc;
P_0c04a3cc: /* original e020, guest PC 0x0c04a3cc */
if(!s->budget--) { s->failed_pc=0x0c04a3ccu; return 0; }
r[0]=0x00000020u;
goto P_0c04a3ce;
P_0c04a3ce: /* original f9b2, guest PC 0x0c04a3ce */
if(!s->budget--) { s->failed_pc=0x0c04a3ceu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c04a3d0;
P_0c04a3d0: /* original f6e7, guest PC 0x0c04a3d0 */
if(!s->budget--) { s->failed_pc=0x0c04a3d0u; return 0; }
vf3_matrix_store(s,ram,14,r[6]+r[0]);
goto P_0c04a3d2;
P_0c04a3d2: /* original e0ff, guest PC 0x0c04a3d2 */
if(!s->budget--) { s->failed_pc=0x0c04a3d2u; return 0; }
r[0]=0xffffffffu;
goto P_0c04a3d4;
P_0c04a3d4: /* original 1616, guest PC 0x0c04a3d4 */
if(!s->budget--) { s->failed_pc=0x0c04a3d4u; return 0; }
write(ram,r[6]+24,r[1],4);
goto P_0c04a3d6;
P_0c04a3d6: /* original f3fd, guest PC 0x0c04a3d6 */
if(!s->budget--) { s->failed_pc=0x0c04a3d6u; return 0; }
r[18]^=0x100000u;
goto P_0c04a3d8;
P_0c04a3d8: /* original 2602, guest PC 0x0c04a3d8 */
if(!s->budget--) { s->failed_pc=0x0c04a3d8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a3da;
P_0c04a3da: /* original e010, guest PC 0x0c04a3da */
if(!s->budget--) { s->failed_pc=0x0c04a3dau; return 0; }
r[0]=0x00000010u;
goto P_0c04a3dc;
P_0c04a3dc: /* original f697, guest PC 0x0c04a3dc */
if(!s->budget--) { s->failed_pc=0x0c04a3dcu; return 0; }
vf3_matrix_store(s,ram,9,r[6]+r[0]);
goto P_0c04a3de;
P_0c04a3de: /* original e014, guest PC 0x0c04a3de */
if(!s->budget--) { s->failed_pc=0x0c04a3deu; return 0; }
r[0]=0x00000014u;
goto P_0c04a3e0;
P_0c04a3e0: /* original f6a7, guest PC 0x0c04a3e0 */
if(!s->budget--) { s->failed_pc=0x0c04a3e0u; return 0; }
vf3_matrix_store(s,ram,10,r[6]+r[0]);
goto P_0c04a3e2;
P_0c04a3e2: /* original 7540, guest PC 0x0c04a3e2 */
if(!s->budget--) { s->failed_pc=0x0c04a3e2u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a3e4;
P_0c04a3e4: /* original 0683, guest PC 0x0c04a3e4 */
if(!s->budget--) { s->failed_pc=0x0c04a3e4u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a3e6;
P_0c04a3e6: /* original 7620, guest PC 0x0c04a3e6 */
if(!s->budget--) { s->failed_pc=0x0c04a3e6u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3e8;
P_0c04a3e8: /* original eb01, guest PC 0x0c04a3e8 */
if(!s->budget--) { s->failed_pc=0x0c04a3e8u; return 0; }
r[11]=0x00000001u;
goto P_0c04a3ea;
P_0c04a3ea: /* original f3fd, guest PC 0x0c04a3ea */
if(!s->budget--) { s->failed_pc=0x0c04a3eau; return 0; }
r[18]^=0x100000u;
goto P_0c04a3ec;
P_0c04a3ec: /* original 4b5a, guest PC 0x0c04a3ec */
if(!s->budget--) { s->failed_pc=0x0c04a3ecu; return 0; }
r[53]=r[11];
goto P_0c04a3ee;
P_0c04a3ee: /* original 0683, guest PC 0x0c04a3ee */
if(!s->budget--) { s->failed_pc=0x0c04a3eeu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a3f0;
P_0c04a3f0: /* original 7620, guest PC 0x0c04a3f0 */
if(!s->budget--) { s->failed_pc=0x0c04a3f0u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a3f2;
P_0c04a3f2: /* original 4310, guest PC 0x0c04a3f2 */
if(!s->budget--) { s->failed_pc=0x0c04a3f2u; return 0; }
--r[3];
r[17]=(r[17]&~1u)|((r[3]==0)!=0);
goto P_0c04a3f4;
P_0c04a3f4: /* original 6042, guest PC 0x0c04a3f4 */
if(!s->budget--) { s->failed_pc=0x0c04a3f4u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c04a3f6;
P_0c04a3f6: /* original 8b9b, guest PC 0x0c04a3f6 */
if(!s->budget--) { s->failed_pc=0x0c04a3f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a330; }
goto P_0c04a3f8;
P_0c04a3f8: /* original 4015, guest PC 0x0c04a3f8 */
if(!s->budget--) { s->failed_pc=0x0c04a3f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c04a3fa;
P_0c04a3fa: /* original 8b04, guest PC 0x0c04a3fa */
if(!s->budget--) { s->failed_pc=0x0c04a3fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04a406; }
goto P_0c04a3fc;
P_0c04a3fc: /* original c880, guest PC 0x0c04a3fc */
if(!s->budget--) { s->failed_pc=0x0c04a3fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c04a3fe;
P_0c04a3fe: /* original 7404, guest PC 0x0c04a3fe */
if(!s->budget--) { s->failed_pc=0x0c04a3feu; return 0; }
r[4]+=0x00000004u;
goto P_0c04a400;
P_0c04a400: /* original 8f96, guest PC 0x0c04a400 */
if(!s->budget--) { s->failed_pc=0x0c04a400u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
if(!cond) { goto P_0c04a330; }
goto P_0c04a404;
P_0c04a402: /* original 6346, guest PC 0x0c04a402 */
if(!s->budget--) { s->failed_pc=0x0c04a402u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[3]=tmp;
goto P_0c04a404;
P_0c04a404: /* original 74f8, guest PC 0x0c04a404 */
if(!s->budget--) { s->failed_pc=0x0c04a404u; return 0; }
r[4]+=0xfffffff8u;
goto P_0c04a406;
P_0c04a406: /* original 2bb8, guest PC 0x0c04a406 */
if(!s->budget--) { s->failed_pc=0x0c04a406u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04a408;
P_0c04a408: /* original f3fd, guest PC 0x0c04a408 */
if(!s->budget--) { s->failed_pc=0x0c04a408u; return 0; }
r[18]^=0x100000u;
goto P_0c04a40a;
P_0c04a40a: /* original 8912, guest PC 0x0c04a40a */
if(!s->budget--) { s->failed_pc=0x0c04a40au; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c04a432u,s,ram); }
goto P_0c04a40c;
P_0c04a40c: /* original 0683, guest PC 0x0c04a40c */
if(!s->budget--) { s->failed_pc=0x0c04a40cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a40e;
P_0c04a40e: /* original 7620, guest PC 0x0c04a40e */
if(!s->budget--) { s->failed_pc=0x0c04a40eu; return 0; }
r[6]+=0x00000020u;
goto P_0c04a410;
P_0c04a410: /* original 50f5, guest PC 0x0c04a410 */
if(!s->budget--) { s->failed_pc=0x0c04a410u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c04a412;
P_0c04a412: /* original 7540, guest PC 0x0c04a412 */
if(!s->budget--) { s->failed_pc=0x0c04a412u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a414;
P_0c04a414: /* original 51f6, guest PC 0x0c04a414 */
if(!s->budget--) { s->failed_pc=0x0c04a414u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c04a416;
P_0c04a416: /* original 52f7, guest PC 0x0c04a416 */
if(!s->budget--) { s->failed_pc=0x0c04a416u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c04a418;
P_0c04a418: /* original 0683, guest PC 0x0c04a418 */
if(!s->budget--) { s->failed_pc=0x0c04a418u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a41a;
P_0c04a41a: /* original 76a0, guest PC 0x0c04a41a */
if(!s->budget--) { s->failed_pc=0x0c04a41au; return 0; }
r[6]+=0xffffffa0u;
goto P_0c04a41c;
P_0c04a41c: /* original 2602, guest PC 0x0c04a41c */
if(!s->budget--) { s->failed_pc=0x0c04a41cu; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a41e;
P_0c04a41e: /* original cb40, guest PC 0x0c04a41e */
if(!s->budget--) { s->failed_pc=0x0c04a41eu; return 0; }
r[0]|=64u;
goto P_0c04a420;
P_0c04a420: /* original 1611, guest PC 0x0c04a420 */
if(!s->budget--) { s->failed_pc=0x0c04a420u; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c04a422;
P_0c04a422: /* original 221b, guest PC 0x0c04a422 */
if(!s->budget--) { s->failed_pc=0x0c04a422u; return 0; }
r[2]|=r[1];
goto P_0c04a424;
P_0c04a424: /* original 0683, guest PC 0x0c04a424 */
if(!s->budget--) { s->failed_pc=0x0c04a424u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a426;
P_0c04a426: /* original 7620, guest PC 0x0c04a426 */
if(!s->budget--) { s->failed_pc=0x0c04a426u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a428;
P_0c04a428: /* original 2602, guest PC 0x0c04a428 */
if(!s->budget--) { s->failed_pc=0x0c04a428u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a42a;
P_0c04a42a: /* original 1621, guest PC 0x0c04a42a */
if(!s->budget--) { s->failed_pc=0x0c04a42au; return 0; }
write(ram,r[6]+4,r[2],4);
goto P_0c04a42c;
P_0c04a42c: /* original 0683, guest PC 0x0c04a42c */
if(!s->budget--) { s->failed_pc=0x0c04a42cu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a42e;
P_0c04a42e: /* original 000b, guest PC 0x0c04a42e */
if(!s->budget--) { s->failed_pc=0x0c04a42eu; return 0; }
target=r[16];
r[6]+=0x00000060u;
s->pc=target; return ram->oob==0;
P_0c04a430: /* original 7660, guest PC 0x0c04a430 */
if(!s->budget--) { s->failed_pc=0x0c04a430u; return 0; }
r[6]+=0x00000060u;
return vf3_matrix_family(0x0c04a432u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
