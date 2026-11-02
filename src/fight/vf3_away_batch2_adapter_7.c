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
int vf3_away_batch2_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03e130u: goto P_0c03e130;
case 0x0c03e132u: goto P_0c03e132;
case 0x0c03e134u: goto P_0c03e134;
case 0x0c03e136u: goto P_0c03e136;
case 0x0c03e138u: goto P_0c03e138;
case 0x0c03e13au: goto P_0c03e13a;
case 0x0c03e13cu: goto P_0c03e13c;
case 0x0c03e13eu: goto P_0c03e13e;
case 0x0c03e140u: goto P_0c03e140;
case 0x0c03e142u: goto P_0c03e142;
case 0x0c03e144u: goto P_0c03e144;
case 0x0c03e146u: goto P_0c03e146;
case 0x0c03e148u: goto P_0c03e148;
case 0x0c03e14au: goto P_0c03e14a;
case 0x0c03e150u: goto P_0c03e150;
case 0x0c03e152u: goto P_0c03e152;
case 0x0c03e154u: goto P_0c03e154;
case 0x0c03e156u: goto P_0c03e156;
case 0x0c03e158u: goto P_0c03e158;
case 0x0c03e15au: goto P_0c03e15a;
case 0x0c03e160u: goto P_0c03e160;
case 0x0c03e162u: goto P_0c03e162;
case 0x0c03e164u: goto P_0c03e164;
case 0x0c03e166u: goto P_0c03e166;
case 0x0c03e168u: goto P_0c03e168;
case 0x0c03e16au: goto P_0c03e16a;
case 0x0c03e16cu: goto P_0c03e16c;
case 0x0c03e16eu: goto P_0c03e16e;
case 0x0c03e170u: goto P_0c03e170;
case 0x0c03e172u: goto P_0c03e172;
case 0x0c03e174u: goto P_0c03e174;
case 0x0c03e176u: goto P_0c03e176;
case 0x0c03e178u: goto P_0c03e178;
case 0x0c03e17au: goto P_0c03e17a;
case 0x0c03e17cu: goto P_0c03e17c;
case 0x0c03e17eu: goto P_0c03e17e;
case 0x0c03e180u: goto P_0c03e180;
case 0x0c03e182u: goto P_0c03e182;
case 0x0c03e184u: goto P_0c03e184;
case 0x0c03e186u: goto P_0c03e186;
case 0x0c03e188u: goto P_0c03e188;
case 0x0c03e18au: goto P_0c03e18a;
case 0x0c03e18cu: goto P_0c03e18c;
case 0x0c03e2a0u: goto P_0c03e2a0;
case 0x0c03e2a2u: goto P_0c03e2a2;
case 0x0c03e2b0u: goto P_0c03e2b0;
case 0x0c03e2b2u: goto P_0c03e2b2;
case 0x0c03e2b4u: goto P_0c03e2b4;
case 0x0c03e2b6u: goto P_0c03e2b6;
case 0x0c03e2b8u: goto P_0c03e2b8;
case 0x0c03e2bau: goto P_0c03e2ba;
case 0x0c03e2bcu: goto P_0c03e2bc;
case 0x0c03e2beu: goto P_0c03e2be;
case 0x0c03e2c0u: goto P_0c03e2c0;
case 0x0c03e2c2u: goto P_0c03e2c2;
case 0x0c03e2c4u: goto P_0c03e2c4;
case 0x0c03e2c6u: goto P_0c03e2c6;
case 0x0c03e2c8u: goto P_0c03e2c8;
case 0x0c03e2cau: goto P_0c03e2ca;
case 0x0c03e2ccu: goto P_0c03e2cc;
case 0x0c03e2ceu: goto P_0c03e2ce;
case 0x0c03e2d0u: goto P_0c03e2d0;
case 0x0c03e2d2u: goto P_0c03e2d2;
case 0x0c03e2d4u: goto P_0c03e2d4;
case 0x0c03e2d6u: goto P_0c03e2d6;
case 0x0c03e2d8u: goto P_0c03e2d8;
case 0x0c03e2dau: goto P_0c03e2da;
case 0x0c03e2dcu: goto P_0c03e2dc;
case 0x0c03e2deu: goto P_0c03e2de;
case 0x0c03e2f0u: goto P_0c03e2f0;
case 0x0c03e2f2u: goto P_0c03e2f2;
case 0x0c03e2f4u: goto P_0c03e2f4;
case 0x0c03e2f6u: goto P_0c03e2f6;
case 0x0c03e2f8u: goto P_0c03e2f8;
case 0x0c03e2fau: goto P_0c03e2fa;
case 0x0c03e2fcu: goto P_0c03e2fc;
case 0x0c03e2feu: goto P_0c03e2fe;
case 0x0c03e300u: goto P_0c03e300;
case 0x0c03e302u: goto P_0c03e302;
case 0x0c03e304u: goto P_0c03e304;
case 0x0c03e306u: goto P_0c03e306;
case 0x0c03e308u: goto P_0c03e308;
case 0x0c03e30au: goto P_0c03e30a;
case 0x0c03e30cu: goto P_0c03e30c;
case 0x0c03e30eu: goto P_0c03e30e;
case 0x0c03e310u: goto P_0c03e310;
case 0x0c03e312u: goto P_0c03e312;
case 0x0c03e314u: goto P_0c03e314;
case 0x0c03e316u: goto P_0c03e316;
case 0x0c03e318u: goto P_0c03e318;
case 0x0c03e31au: goto P_0c03e31a;
case 0x0c03e31cu: goto P_0c03e31c;
case 0x0c03e31eu: goto P_0c03e31e;
case 0x0c03e320u: goto P_0c03e320;
case 0x0c03e322u: goto P_0c03e322;
case 0x0c03e324u: goto P_0c03e324;
case 0x0c03e326u: goto P_0c03e326;
case 0x0c03e330u: goto P_0c03e330;
case 0x0c03e332u: goto P_0c03e332;
case 0x0c03e334u: goto P_0c03e334;
case 0x0c03e336u: goto P_0c03e336;
case 0x0c03e338u: goto P_0c03e338;
case 0x0c03e350u: goto P_0c03e350;
case 0x0c03e352u: goto P_0c03e352;
case 0x0c03e354u: goto P_0c03e354;
case 0x0c03e356u: goto P_0c03e356;
case 0x0c03e358u: goto P_0c03e358;
case 0x0c03e35au: goto P_0c03e35a;
case 0x0c03e35cu: goto P_0c03e35c;
case 0x0c03e35eu: goto P_0c03e35e;
case 0x0c03e360u: goto P_0c03e360;
case 0x0c03e362u: goto P_0c03e362;
case 0x0c03e364u: goto P_0c03e364;
case 0x0c03e366u: goto P_0c03e366;
case 0x0c03e368u: goto P_0c03e368;
case 0x0c03e36au: goto P_0c03e36a;
case 0x0c03e36cu: goto P_0c03e36c;
case 0x0c03e36eu: goto P_0c03e36e;
case 0x0c03e370u: goto P_0c03e370;
case 0x0c03e380u: goto P_0c03e380;
case 0x0c03e382u: goto P_0c03e382;
case 0x0c03e384u: goto P_0c03e384;
case 0x0c03e386u: goto P_0c03e386;
case 0x0c03e388u: goto P_0c03e388;
case 0x0c03e38au: goto P_0c03e38a;
case 0x0c03e38cu: goto P_0c03e38c;
case 0x0c03e38eu: goto P_0c03e38e;
case 0x0c03e390u: goto P_0c03e390;
case 0x0c03e392u: goto P_0c03e392;
case 0x0c03e394u: goto P_0c03e394;
case 0x0c03e396u: goto P_0c03e396;
case 0x0c03e398u: goto P_0c03e398;
case 0x0c03e39au: goto P_0c03e39a;
case 0x0c03e39cu: goto P_0c03e39c;
case 0x0c03e39eu: goto P_0c03e39e;
case 0x0c03e3a0u: goto P_0c03e3a0;
case 0x0c03e3a2u: goto P_0c03e3a2;
case 0x0c03e3a4u: goto P_0c03e3a4;
case 0x0c03e3a6u: goto P_0c03e3a6;
case 0x0c03e3a8u: goto P_0c03e3a8;
case 0x0c03e3aau: goto P_0c03e3aa;
case 0x0c03e3acu: goto P_0c03e3ac;
case 0x0c03e3aeu: goto P_0c03e3ae;
case 0x0c03e3b0u: goto P_0c03e3b0;
case 0x0c03e3b2u: goto P_0c03e3b2;
case 0x0c03e3b4u: goto P_0c03e3b4;
case 0x0c03e3b6u: goto P_0c03e3b6;
case 0x0c03e3b8u: goto P_0c03e3b8;
case 0x0c03e3bau: goto P_0c03e3ba;
case 0x0c03e3bcu: goto P_0c03e3bc;
case 0x0c03e3beu: goto P_0c03e3be;
case 0x0c03e3c0u: goto P_0c03e3c0;
case 0x0c03e3c2u: goto P_0c03e3c2;
case 0x0c03e3c4u: goto P_0c03e3c4;
case 0x0c03e3c6u: goto P_0c03e3c6;
case 0x0c03e3c8u: goto P_0c03e3c8;
case 0x0c03e3cau: goto P_0c03e3ca;
case 0x0c03e3ccu: goto P_0c03e3cc;
case 0x0c03e3ceu: goto P_0c03e3ce;
case 0x0c03e3d0u: goto P_0c03e3d0;
case 0x0c03e3d2u: goto P_0c03e3d2;
case 0x0c03e3d4u: goto P_0c03e3d4;
case 0x0c03e3d6u: goto P_0c03e3d6;
case 0x0c03e3d8u: goto P_0c03e3d8;
case 0x0c03e3dau: goto P_0c03e3da;
case 0x0c03e3dcu: goto P_0c03e3dc;
case 0x0c03e3deu: goto P_0c03e3de;
case 0x0c03e3e0u: goto P_0c03e3e0;
case 0x0c03e3e2u: goto P_0c03e3e2;
case 0x0c03e3e4u: goto P_0c03e3e4;
case 0x0c03e3e6u: goto P_0c03e3e6;
case 0x0c03e3e8u: goto P_0c03e3e8;
case 0x0c03e3eau: goto P_0c03e3ea;
case 0x0c03e3ecu: goto P_0c03e3ec;
case 0x0c03e3eeu: goto P_0c03e3ee;
case 0x0c03e3f0u: goto P_0c03e3f0;
case 0x0c03e3f2u: goto P_0c03e3f2;
case 0x0c03e3f4u: goto P_0c03e3f4;
case 0x0c03e3f6u: goto P_0c03e3f6;
case 0x0c03e3f8u: goto P_0c03e3f8;
case 0x0c03e3fau: goto P_0c03e3fa;
case 0x0c03e3fcu: goto P_0c03e3fc;
case 0x0c03e3feu: goto P_0c03e3fe;
case 0x0c03e400u: goto P_0c03e400;
case 0x0c03e402u: goto P_0c03e402;
case 0x0c03e404u: goto P_0c03e404;
case 0x0c03e406u: goto P_0c03e406;
case 0x0c03e408u: goto P_0c03e408;
case 0x0c03e40au: goto P_0c03e40a;
case 0x0c03e40cu: goto P_0c03e40c;
case 0x0c03e40eu: goto P_0c03e40e;
case 0x0c03e410u: goto P_0c03e410;
case 0x0c03e412u: goto P_0c03e412;
case 0x0c03e414u: goto P_0c03e414;
case 0x0c03e416u: goto P_0c03e416;
case 0x0c03e418u: goto P_0c03e418;
case 0x0c03e41au: goto P_0c03e41a;
case 0x0c03e41cu: goto P_0c03e41c;
case 0x0c03e41eu: goto P_0c03e41e;
case 0x0c03e420u: goto P_0c03e420;
case 0x0c03e422u: goto P_0c03e422;
case 0x0c03e424u: goto P_0c03e424;
case 0x0c03e426u: goto P_0c03e426;
case 0x0c03e428u: goto P_0c03e428;
case 0x0c03e42au: goto P_0c03e42a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03e130: /* original 2fe6, guest PC 0x0c03e130 */
if(!s->budget--) { s->failed_pc=0x0c03e130u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e132;
P_0c03e132: /* original 2558, guest PC 0x0c03e132 */
if(!s->budget--) { s->failed_pc=0x0c03e132u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03e134;
P_0c03e134: /* original 2fd6, guest PC 0x0c03e134 */
if(!s->budget--) { s->failed_pc=0x0c03e134u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e136;
P_0c03e136: /* original 2fc6, guest PC 0x0c03e136 */
if(!s->budget--) { s->failed_pc=0x0c03e136u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e138;
P_0c03e138: /* original 2fb6, guest PC 0x0c03e138 */
if(!s->budget--) { s->failed_pc=0x0c03e138u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13a;
P_0c03e13a: /* original 2fa6, guest PC 0x0c03e13a */
if(!s->budget--) { s->failed_pc=0x0c03e13au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13c;
P_0c03e13c: /* original 2f96, guest PC 0x0c03e13c */
if(!s->budget--) { s->failed_pc=0x0c03e13cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e13e;
P_0c03e13e: /* original 2f86, guest PC 0x0c03e13e */
if(!s->budget--) { s->failed_pc=0x0c03e13eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e140;
P_0c03e140: /* original 4f22, guest PC 0x0c03e140 */
if(!s->budget--) { s->failed_pc=0x0c03e140u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e142;
P_0c03e142: /* original 7ff8, guest PC 0x0c03e142 */
if(!s->budget--) { s->failed_pc=0x0c03e142u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e144;
P_0c03e144: /* original 8d04, guest PC 0x0c03e144 */
if(!s->budget--) { s->failed_pc=0x0c03e144u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c03e150; }
goto P_0c03e148;
P_0c03e146: /* original ec00, guest PC 0x0c03e146 */
if(!s->budget--) { s->failed_pc=0x0c03e146u; return 0; }
r[12]=0x00000000u;
goto P_0c03e148;
P_0c03e148: /* original a003, guest PC 0x0c03e148 */
if(!s->budget--) { s->failed_pc=0x0c03e148u; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
goto P_0c03e152;
P_0c03e14a: /* original 6852, guest PC 0x0c03e14a */
if(!s->budget--) { s->failed_pc=0x0c03e14au; return 0; }
tmp=read(ram,r[5],4);
r[8]=tmp;
if(!vf3_matrix_family(0x0c03e14cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e14cu; return 0; } return 1;
P_0c03e150: /* original 68c3, guest PC 0x0c03e150 */
if(!s->budget--) { s->failed_pc=0x0c03e150u; return 0; }
r[8]=r[12];
goto P_0c03e152;
P_0c03e152: /* original 2668, guest PC 0x0c03e152 */
if(!s->budget--) { s->failed_pc=0x0c03e152u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c03e154;
P_0c03e154: /* original 8904, guest PC 0x0c03e154 */
if(!s->budget--) { s->failed_pc=0x0c03e154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e160; }
goto P_0c03e156;
P_0c03e156: /* original 6262, guest PC 0x0c03e156 */
if(!s->budget--) { s->failed_pc=0x0c03e156u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c03e158;
P_0c03e158: /* original a003, guest PC 0x0c03e158 */
if(!s->budget--) { s->failed_pc=0x0c03e158u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03e162;
P_0c03e15a: /* original 1f21, guest PC 0x0c03e15a */
if(!s->budget--) { s->failed_pc=0x0c03e15au; return 0; }
write(ram,r[15]+4,r[2],4);
if(!vf3_matrix_family(0x0c03e15cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e15cu; return 0; } return 1;
P_0c03e160: /* original 1fc1, guest PC 0x0c03e160 */
if(!s->budget--) { s->failed_pc=0x0c03e160u; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c03e162;
P_0c03e162: /* original d90b, guest PC 0x0c03e162 */
if(!s->budget--) { s->failed_pc=0x0c03e162u; return 0; }
r[9]=read(ram,0x0c03e190u,4);
goto P_0c03e164;
P_0c03e164: /* original 6ec3, guest PC 0x0c03e164 */
if(!s->budget--) { s->failed_pc=0x0c03e164u; return 0; }
r[14]=r[12];
goto P_0c03e166;
P_0c03e166: /* original da0b, guest PC 0x0c03e166 */
if(!s->budget--) { s->failed_pc=0x0c03e166u; return 0; }
r[10]=read(ram,0x0c03e194u,4);
goto P_0c03e168;
P_0c03e168: /* original ebff, guest PC 0x0c03e168 */
if(!s->budget--) { s->failed_pc=0x0c03e168u; return 0; }
r[11]=0xffffffffu;
goto P_0c03e16a;
P_0c03e16a: /* original 5d43, guest PC 0x0c03e16a */
if(!s->budget--) { s->failed_pc=0x0c03e16au; return 0; }
r[13]=read(ram,r[4]+12,4);
goto P_0c03e16c;
P_0c03e16c: /* original 64d5, guest PC 0x0c03e16c */
if(!s->budget--) { s->failed_pc=0x0c03e16cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[4]=tmp;
goto P_0c03e16e;
P_0c03e16e: /* original 4415, guest PC 0x0c03e16e */
if(!s->budget--) { s->failed_pc=0x0c03e16eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c03e170;
P_0c03e170: /* original 8901, guest PC 0x0c03e170 */
if(!s->budget--) { s->failed_pc=0x0c03e170u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e176; }
goto P_0c03e172;
P_0c03e172: /* original a09d, guest PC 0x0c03e172 */
if(!s->budget--) { s->failed_pc=0x0c03e172u; return 0; }
goto P_0c03e2b0;
P_0c03e174: /* original 0009, guest PC 0x0c03e174 */
if(!s->budget--) { s->failed_pc=0x0c03e174u; return 0; }
goto P_0c03e176;
P_0c03e176: /* original 604c, guest PC 0x0c03e176 */
if(!s->budget--) { s->failed_pc=0x0c03e176u; return 0; }
r[0]=r[4]&255u;
goto P_0c03e178;
P_0c03e178: /* original e11e, guest PC 0x0c03e178 */
if(!s->budget--) { s->failed_pc=0x0c03e178u; return 0; }
r[1]=0x0000001eu;
goto P_0c03e17a;
P_0c03e17a: /* original 3012, guest PC 0x0c03e17a */
if(!s->budget--) { s->failed_pc=0x0c03e17au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c03e17c;
P_0c03e17c: /* original 8b01, guest PC 0x0c03e17c */
if(!s->budget--) { s->failed_pc=0x0c03e17cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e182; }
goto P_0c03e17e;
P_0c03e17e: /* original a08f, guest PC 0x0c03e17e */
if(!s->budget--) { s->failed_pc=0x0c03e17eu; return 0; }
goto P_0c03e2a0;
P_0c03e180: /* original 0009, guest PC 0x0c03e180 */
if(!s->budget--) { s->failed_pc=0x0c03e180u; return 0; }
goto P_0c03e182;
P_0c03e182: /* original 4000, guest PC 0x0c03e182 */
if(!s->budget--) { s->failed_pc=0x0c03e182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03e184;
P_0c03e184: /* original 6103, guest PC 0x0c03e184 */
if(!s->budget--) { s->failed_pc=0x0c03e184u; return 0; }
r[1]=r[0];
goto P_0c03e186;
P_0c03e186: /* original c704, guest PC 0x0c03e186 */
if(!s->budget--) { s->failed_pc=0x0c03e186u; return 0; }
r[0]=code_base|0x0003e198u;
goto P_0c03e188;
P_0c03e188: /* original 001d, guest PC 0x0c03e188 */
if(!s->budget--) { s->failed_pc=0x0c03e188u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c03e18a;
P_0c03e18a: /* original 0023, guest PC 0x0c03e18a */
if(!s->budget--) { s->failed_pc=0x0c03e18au; return 0; }
target=r[0]+0x0c03e18eu;
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
P_0c03e18c: /* original 0009, guest PC 0x0c03e18c */
if(!s->budget--) { s->failed_pc=0x0c03e18cu; return 0; }
if(!vf3_matrix_family(0x0c03e18eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e18eu; return 0; } return 1;
P_0c03e2a0: /* original a014, guest PC 0x0c03e2a0 */
if(!s->budget--) { s->failed_pc=0x0c03e2a0u; return 0; }
r[0]=0xffffffffu;
goto P_0c03e2cc;
P_0c03e2a2: /* original e0ff, guest PC 0x0c03e2a2 */
if(!s->budget--) { s->failed_pc=0x0c03e2a2u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c03e2a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2a4u; return 0; } return 1;
P_0c03e2b0: /* original 2ee8, guest PC 0x0c03e2b0 */
if(!s->budget--) { s->failed_pc=0x0c03e2b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c03e2b2;
P_0c03e2b2: /* original 890a, guest PC 0x0c03e2b2 */
if(!s->budget--) { s->failed_pc=0x0c03e2b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e2ca; }
goto P_0c03e2b4;
P_0c03e2b4: /* original d20b, guest PC 0x0c03e2b4 */
if(!s->budget--) { s->failed_pc=0x0c03e2b4u; return 0; }
r[2]=read(ram,0x0c03e2e4u,4);
goto P_0c03e2b6;
P_0c03e2b6: /* original 420b, guest PC 0x0c03e2b6 */
if(!s->budget--) { s->failed_pc=0x0c03e2b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c03e2bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e2bau) { target=s->pc; goto dispatch; }
goto P_0c03e2ba;
P_0c03e2b8: /* original 64e3, guest PC 0x0c03e2b8 */
if(!s->budget--) { s->failed_pc=0x0c03e2b8u; return 0; }
r[4]=r[14];
goto P_0c03e2ba;
P_0c03e2ba: /* original 60e2, guest PC 0x0c03e2ba */
if(!s->budget--) { s->failed_pc=0x0c03e2bau; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03e2bc;
P_0c03e2bc: /* original cb0d, guest PC 0x0c03e2bc */
if(!s->budget--) { s->failed_pc=0x0c03e2bcu; return 0; }
r[0]|=13u;
goto P_0c03e2be;
P_0c03e2be: /* original 2e02, guest PC 0x0c03e2be */
if(!s->budget--) { s->failed_pc=0x0c03e2beu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c03e2c0;
P_0c03e2c0: /* original 50e2, guest PC 0x0c03e2c0 */
if(!s->budget--) { s->failed_pc=0x0c03e2c0u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03e2c2;
P_0c03e2c2: /* original 930d, guest PC 0x0c03e2c2 */
if(!s->budget--) { s->failed_pc=0x0c03e2c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e2e0u,2);
goto P_0c03e2c4;
P_0c03e2c4: /* original 2039, guest PC 0x0c03e2c4 */
if(!s->budget--) { s->failed_pc=0x0c03e2c4u; return 0; }
r[0]&=r[3];
goto P_0c03e2c6;
P_0c03e2c6: /* original cbc0, guest PC 0x0c03e2c6 */
if(!s->budget--) { s->failed_pc=0x0c03e2c6u; return 0; }
r[0]|=192u;
goto P_0c03e2c8;
P_0c03e2c8: /* original 1e02, guest PC 0x0c03e2c8 */
if(!s->budget--) { s->failed_pc=0x0c03e2c8u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03e2ca;
P_0c03e2ca: /* original e000, guest PC 0x0c03e2ca */
if(!s->budget--) { s->failed_pc=0x0c03e2cau; return 0; }
r[0]=0x00000000u;
goto P_0c03e2cc;
P_0c03e2cc: /* original 7f08, guest PC 0x0c03e2cc */
if(!s->budget--) { s->failed_pc=0x0c03e2ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c03e2ce;
P_0c03e2ce: /* original 4f26, guest PC 0x0c03e2ce */
if(!s->budget--) { s->failed_pc=0x0c03e2ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e2d0;
P_0c03e2d0: /* original 68f6, guest PC 0x0c03e2d0 */
if(!s->budget--) { s->failed_pc=0x0c03e2d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03e2d2;
P_0c03e2d2: /* original 69f6, guest PC 0x0c03e2d2 */
if(!s->budget--) { s->failed_pc=0x0c03e2d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03e2d4;
P_0c03e2d4: /* original 6af6, guest PC 0x0c03e2d4 */
if(!s->budget--) { s->failed_pc=0x0c03e2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e2d6;
P_0c03e2d6: /* original 6bf6, guest PC 0x0c03e2d6 */
if(!s->budget--) { s->failed_pc=0x0c03e2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e2d8;
P_0c03e2d8: /* original 6cf6, guest PC 0x0c03e2d8 */
if(!s->budget--) { s->failed_pc=0x0c03e2d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e2da;
P_0c03e2da: /* original 6df6, guest PC 0x0c03e2da */
if(!s->budget--) { s->failed_pc=0x0c03e2dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e2dc;
P_0c03e2dc: /* original 000b, guest PC 0x0c03e2dc */
if(!s->budget--) { s->failed_pc=0x0c03e2dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e2de: /* original 6ef6, guest PC 0x0c03e2de */
if(!s->budget--) { s->failed_pc=0x0c03e2deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e2e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e2e0u; return 0; } return 1;
P_0c03e2f0: /* original 2fe6, guest PC 0x0c03e2f0 */
if(!s->budget--) { s->failed_pc=0x0c03e2f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f2;
P_0c03e2f2: /* original 6e43, guest PC 0x0c03e2f2 */
if(!s->budget--) { s->failed_pc=0x0c03e2f2u; return 0; }
r[14]=r[4];
goto P_0c03e2f4;
P_0c03e2f4: /* original 2fd6, guest PC 0x0c03e2f4 */
if(!s->budget--) { s->failed_pc=0x0c03e2f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2f6;
P_0c03e2f6: /* original 6d63, guest PC 0x0c03e2f6 */
if(!s->budget--) { s->failed_pc=0x0c03e2f6u; return 0; }
r[13]=r[6];
goto P_0c03e2f8;
P_0c03e2f8: /* original 2fc6, guest PC 0x0c03e2f8 */
if(!s->budget--) { s->failed_pc=0x0c03e2f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e2fa;
P_0c03e2fa: /* original 6c53, guest PC 0x0c03e2fa */
if(!s->budget--) { s->failed_pc=0x0c03e2fau; return 0; }
r[12]=r[5];
goto P_0c03e2fc;
P_0c03e2fc: /* original 4f22, guest PC 0x0c03e2fc */
if(!s->budget--) { s->failed_pc=0x0c03e2fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e2fe;
P_0c03e2fe: /* original 53e1, guest PC 0x0c03e2fe */
if(!s->budget--) { s->failed_pc=0x0c03e2feu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c03e300;
P_0c03e300: /* original 2338, guest PC 0x0c03e300 */
if(!s->budget--) { s->failed_pc=0x0c03e300u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03e302;
P_0c03e302: /* original 8903, guest PC 0x0c03e302 */
if(!s->budget--) { s->failed_pc=0x0c03e302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e30c; }
goto P_0c03e304;
P_0c03e304: /* original 65c3, guest PC 0x0c03e304 */
if(!s->budget--) { s->failed_pc=0x0c03e304u; return 0; }
r[5]=r[12];
goto P_0c03e306;
P_0c03e306: /* original 66d3, guest PC 0x0c03e306 */
if(!s->budget--) { s->failed_pc=0x0c03e306u; return 0; }
r[6]=r[13];
goto P_0c03e308;
P_0c03e308: /* original bf12, guest PC 0x0c03e308 */
if(!s->budget--) { s->failed_pc=0x0c03e308u; return 0; }
target=code_base|0x0c03e130u; r[16]=code_base|0x0c03e30cu;
r[4]=read(ram,r[14]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e30cu) { target=s->pc; goto dispatch; }
goto P_0c03e30c;
P_0c03e30a: /* original 54e1, guest PC 0x0c03e30a */
if(!s->budget--) { s->failed_pc=0x0c03e30au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c03e30c;
P_0c03e30c: /* original 52eb, guest PC 0x0c03e30c */
if(!s->budget--) { s->failed_pc=0x0c03e30cu; return 0; }
r[2]=read(ram,r[14]+44,4);
goto P_0c03e30e;
P_0c03e30e: /* original 2228, guest PC 0x0c03e30e */
if(!s->budget--) { s->failed_pc=0x0c03e30eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e310;
P_0c03e310: /* original 8903, guest PC 0x0c03e310 */
if(!s->budget--) { s->failed_pc=0x0c03e310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e31a; }
goto P_0c03e312;
P_0c03e312: /* original 65c3, guest PC 0x0c03e312 */
if(!s->budget--) { s->failed_pc=0x0c03e312u; return 0; }
r[5]=r[12];
goto P_0c03e314;
P_0c03e314: /* original 66d3, guest PC 0x0c03e314 */
if(!s->budget--) { s->failed_pc=0x0c03e314u; return 0; }
r[6]=r[13];
goto P_0c03e316;
P_0c03e316: /* original bfeb, guest PC 0x0c03e316 */
if(!s->budget--) { s->failed_pc=0x0c03e316u; return 0; }
target=code_base|0x0c03e2f0u; r[16]=code_base|0x0c03e31au;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e31au) { target=s->pc; goto dispatch; }
goto P_0c03e31a;
P_0c03e318: /* original 54eb, guest PC 0x0c03e318 */
if(!s->budget--) { s->failed_pc=0x0c03e318u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c03e31a;
P_0c03e31a: /* original 52ec, guest PC 0x0c03e31a */
if(!s->budget--) { s->failed_pc=0x0c03e31au; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c03e31c;
P_0c03e31c: /* original 2228, guest PC 0x0c03e31c */
if(!s->budget--) { s->failed_pc=0x0c03e31cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03e31e;
P_0c03e31e: /* original 8907, guest PC 0x0c03e31e */
if(!s->budget--) { s->failed_pc=0x0c03e31eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03e330; }
goto P_0c03e320;
P_0c03e320: /* original 64c3, guest PC 0x0c03e320 */
if(!s->budget--) { s->failed_pc=0x0c03e320u; return 0; }
r[4]=r[12];
goto P_0c03e322;
P_0c03e322: /* original 65d3, guest PC 0x0c03e322 */
if(!s->budget--) { s->failed_pc=0x0c03e322u; return 0; }
r[5]=r[13];
goto P_0c03e324;
P_0c03e324: /* original afeb, guest PC 0x0c03e324 */
if(!s->budget--) { s->failed_pc=0x0c03e324u; return 0; }
r[14]=read(ram,r[14]+48,4);
goto P_0c03e2fe;
P_0c03e326: /* original 5eec, guest PC 0x0c03e326 */
if(!s->budget--) { s->failed_pc=0x0c03e326u; return 0; }
r[14]=read(ram,r[14]+48,4);
if(!vf3_matrix_family(0x0c03e328u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e328u; return 0; } return 1;
P_0c03e330: /* original 4f26, guest PC 0x0c03e330 */
if(!s->budget--) { s->failed_pc=0x0c03e330u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e332;
P_0c03e332: /* original 6cf6, guest PC 0x0c03e332 */
if(!s->budget--) { s->failed_pc=0x0c03e332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e334;
P_0c03e334: /* original 6df6, guest PC 0x0c03e334 */
if(!s->budget--) { s->failed_pc=0x0c03e334u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e336;
P_0c03e336: /* original 000b, guest PC 0x0c03e336 */
if(!s->budget--) { s->failed_pc=0x0c03e336u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e338: /* original 6ef6, guest PC 0x0c03e338 */
if(!s->budget--) { s->failed_pc=0x0c03e338u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e33au; return 0; } return 1;
P_0c03e350: /* original 2fe6, guest PC 0x0c03e350 */
if(!s->budget--) { s->failed_pc=0x0c03e350u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e352;
P_0c03e352: /* original 2448, guest PC 0x0c03e352 */
if(!s->budget--) { s->failed_pc=0x0c03e352u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03e354;
P_0c03e354: /* original 2fd6, guest PC 0x0c03e354 */
if(!s->budget--) { s->failed_pc=0x0c03e354u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e356;
P_0c03e356: /* original 2fc6, guest PC 0x0c03e356 */
if(!s->budget--) { s->failed_pc=0x0c03e356u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e358;
P_0c03e358: /* original 2fb6, guest PC 0x0c03e358 */
if(!s->budget--) { s->failed_pc=0x0c03e358u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e35a;
P_0c03e35a: /* original 2fa6, guest PC 0x0c03e35a */
if(!s->budget--) { s->failed_pc=0x0c03e35au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e35c;
P_0c03e35c: /* original 2f96, guest PC 0x0c03e35c */
if(!s->budget--) { s->failed_pc=0x0c03e35cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e35e;
P_0c03e35e: /* original 2f86, guest PC 0x0c03e35e */
if(!s->budget--) { s->failed_pc=0x0c03e35eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e360;
P_0c03e360: /* original 4f22, guest PC 0x0c03e360 */
if(!s->budget--) { s->failed_pc=0x0c03e360u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e362;
P_0c03e362: /* original 4f12, guest PC 0x0c03e362 */
if(!s->budget--) { s->failed_pc=0x0c03e362u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e364;
P_0c03e364: /* original 7ff8, guest PC 0x0c03e364 */
if(!s->budget--) { s->failed_pc=0x0c03e364u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03e366;
P_0c03e366: /* original 1f51, guest PC 0x0c03e366 */
if(!s->budget--) { s->failed_pc=0x0c03e366u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c03e368;
P_0c03e368: /* original 2f62, guest PC 0x0c03e368 */
if(!s->budget--) { s->failed_pc=0x0c03e368u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c03e36a;
P_0c03e36a: /* original 8f09, guest PC 0x0c03e36a */
if(!s->budget--) { s->failed_pc=0x0c03e36au; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c03e380; }
goto P_0c03e36e;
P_0c03e36c: /* original e800, guest PC 0x0c03e36c */
if(!s->budget--) { s->failed_pc=0x0c03e36cu; return 0; }
r[8]=0x00000000u;
goto P_0c03e36e;
P_0c03e36e: /* original a052, guest PC 0x0c03e36e */
if(!s->budget--) { s->failed_pc=0x0c03e36eu; return 0; }
r[0]=0x00000000u;
goto P_0c03e416;
P_0c03e370: /* original e000, guest PC 0x0c03e370 */
if(!s->budget--) { s->failed_pc=0x0c03e370u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c03e372u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e372u; return 0; } return 1;
P_0c03e380: /* original 5b41, guest PC 0x0c03e380 */
if(!s->budget--) { s->failed_pc=0x0c03e380u; return 0; }
r[11]=read(ram,r[4]+4,4);
goto P_0c03e382;
P_0c03e382: /* original de8b, guest PC 0x0c03e382 */
if(!s->budget--) { s->failed_pc=0x0c03e382u; return 0; }
r[14]=read(ram,0x0c03e5b0u,4);
goto P_0c03e384;
P_0c03e384: /* original 2bb8, guest PC 0x0c03e384 */
if(!s->budget--) { s->failed_pc=0x0c03e384u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c03e386;
P_0c03e386: /* original 8d45, guest PC 0x0c03e386 */
if(!s->budget--) { s->failed_pc=0x0c03e386u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[4],4);
r[9]=tmp;
if(cond) { goto P_0c03e414; }
goto P_0c03e38a;
P_0c03e388: /* original 6942, guest PC 0x0c03e388 */
if(!s->budget--) { s->failed_pc=0x0c03e388u; return 0; }
tmp=read(ram,r[4],4);
r[9]=tmp;
goto P_0c03e38a;
P_0c03e38a: /* original d388, guest PC 0x0c03e38a */
if(!s->budget--) { s->failed_pc=0x0c03e38au; return 0; }
r[3]=read(ram,0x0c03e5acu,4);
goto P_0c03e38c;
P_0c03e38c: /* original 6a92, guest PC 0x0c03e38c */
if(!s->budget--) { s->failed_pc=0x0c03e38cu; return 0; }
tmp=read(ram,r[9],4);
r[10]=tmp;
goto P_0c03e38e;
P_0c03e38e: /* original 6d32, guest PC 0x0c03e38e */
if(!s->budget--) { s->failed_pc=0x0c03e38eu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03e390;
P_0c03e390: /* original 61e2, guest PC 0x0c03e390 */
if(!s->budget--) { s->failed_pc=0x0c03e390u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03e392;
P_0c03e392: /* original 3dac, guest PC 0x0c03e392 */
if(!s->budget--) { s->failed_pc=0x0c03e392u; return 0; }
r[13]+=r[10];
goto P_0c03e394;
P_0c03e394: /* original 62d3, guest PC 0x0c03e394 */
if(!s->budget--) { s->failed_pc=0x0c03e394u; return 0; }
r[2]=r[13];
goto P_0c03e396;
P_0c03e396: /* original 4208, guest PC 0x0c03e396 */
if(!s->budget--) { s->failed_pc=0x0c03e396u; return 0; }
r[2]<<=2;
goto P_0c03e398;
P_0c03e398: /* original 4200, guest PC 0x0c03e398 */
if(!s->budget--) { s->failed_pc=0x0c03e398u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c03e39a;
P_0c03e39a: /* original 321c, guest PC 0x0c03e39a */
if(!s->budget--) { s->failed_pc=0x0c03e39au; return 0; }
r[2]+=r[1];
goto P_0c03e39c;
P_0c03e39c: /* original 6022, guest PC 0x0c03e39c */
if(!s->budget--) { s->failed_pc=0x0c03e39cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c03e39e;
P_0c03e39e: /* original 2008, guest PC 0x0c03e39e */
if(!s->budget--) { s->failed_pc=0x0c03e39eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03e3a0;
P_0c03e3a0: /* original 8b0b, guest PC 0x0c03e3a0 */
if(!s->budget--) { s->failed_pc=0x0c03e3a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e3ba; }
goto P_0c03e3a2;
P_0c03e3a2: /* original 60d3, guest PC 0x0c03e3a2 */
if(!s->budget--) { s->failed_pc=0x0c03e3a2u; return 0; }
r[0]=r[13];
goto P_0c03e3a4;
P_0c03e3a4: /* original 62e2, guest PC 0x0c03e3a4 */
if(!s->budget--) { s->failed_pc=0x0c03e3a4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03e3a6;
P_0c03e3a6: /* original 4008, guest PC 0x0c03e3a6 */
if(!s->budget--) { s->failed_pc=0x0c03e3a6u; return 0; }
r[0]<<=2;
goto P_0c03e3a8;
P_0c03e3a8: /* original d182, guest PC 0x0c03e3a8 */
if(!s->budget--) { s->failed_pc=0x0c03e3a8u; return 0; }
r[1]=read(ram,0x0c03e5b4u,4);
goto P_0c03e3aa;
P_0c03e3aa: /* original 4000, guest PC 0x0c03e3aa */
if(!s->budget--) { s->failed_pc=0x0c03e3aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03e3ac;
P_0c03e3ac: /* original e304, guest PC 0x0c03e3ac */
if(!s->budget--) { s->failed_pc=0x0c03e3acu; return 0; }
r[3]=0x00000004u;
goto P_0c03e3ae;
P_0c03e3ae: /* original 302c, guest PC 0x0c03e3ae */
if(!s->budget--) { s->failed_pc=0x0c03e3aeu; return 0; }
r[0]+=r[2];
goto P_0c03e3b0;
P_0c03e3b0: /* original 330c, guest PC 0x0c03e3b0 */
if(!s->budget--) { s->failed_pc=0x0c03e3b0u; return 0; }
r[3]+=r[0];
goto P_0c03e3b2;
P_0c03e3b2: /* original 410b, guest PC 0x0c03e3b2 */
if(!s->budget--) { s->failed_pc=0x0c03e3b2u; return 0; }
target=r[1];
r[16]=code_base|0x0c03e3b6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e3b6u) { target=s->pc; goto dispatch; }
goto P_0c03e3b6;
P_0c03e3b4: /* original 2f36, guest PC 0x0c03e3b4 */
if(!s->budget--) { s->failed_pc=0x0c03e3b4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e3b6;
P_0c03e3b6: /* original 62f6, guest PC 0x0c03e3b6 */
if(!s->budget--) { s->failed_pc=0x0c03e3b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c03e3b8;
P_0c03e3b8: /* original 2202, guest PC 0x0c03e3b8 */
if(!s->budget--) { s->failed_pc=0x0c03e3b8u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c03e3ba;
P_0c03e3ba: /* original 64d3, guest PC 0x0c03e3ba */
if(!s->budget--) { s->failed_pc=0x0c03e3bau; return 0; }
r[4]=r[13];
goto P_0c03e3bc;
P_0c03e3bc: /* original 4408, guest PC 0x0c03e3bc */
if(!s->budget--) { s->failed_pc=0x0c03e3bcu; return 0; }
r[4]<<=2;
goto P_0c03e3be;
P_0c03e3be: /* original 63e2, guest PC 0x0c03e3be */
if(!s->budget--) { s->failed_pc=0x0c03e3beu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03e3c0;
P_0c03e3c0: /* original 4400, guest PC 0x0c03e3c0 */
if(!s->budget--) { s->failed_pc=0x0c03e3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03e3c2;
P_0c03e3c2: /* original ec3c, guest PC 0x0c03e3c2 */
if(!s->budget--) { s->failed_pc=0x0c03e3c2u; return 0; }
r[12]=0x0000003cu;
goto P_0c03e3c4;
P_0c03e3c4: /* original 334c, guest PC 0x0c03e3c4 */
if(!s->budget--) { s->failed_pc=0x0c03e3c4u; return 0; }
r[3]+=r[4];
goto P_0c03e3c6;
P_0c03e3c6: /* original 6232, guest PC 0x0c03e3c6 */
if(!s->budget--) { s->failed_pc=0x0c03e3c6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03e3c8;
P_0c03e3c8: /* original 7201, guest PC 0x0c03e3c8 */
if(!s->budget--) { s->failed_pc=0x0c03e3c8u; return 0; }
r[2]+=0x00000001u;
goto P_0c03e3ca;
P_0c03e3ca: /* original 2322, guest PC 0x0c03e3ca */
if(!s->budget--) { s->failed_pc=0x0c03e3cau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c03e3cc;
P_0c03e3cc: /* original 6de2, guest PC 0x0c03e3cc */
if(!s->budget--) { s->failed_pc=0x0c03e3ccu; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c03e3ce;
P_0c03e3ce: /* original d27a, guest PC 0x0c03e3ce */
if(!s->budget--) { s->failed_pc=0x0c03e3ceu; return 0; }
r[2]=read(ram,0x0c03e5b8u,4);
goto P_0c03e3d0;
P_0c03e3d0: /* original 3d4c, guest PC 0x0c03e3d0 */
if(!s->budget--) { s->failed_pc=0x0c03e3d0u; return 0; }
r[13]+=r[4];
goto P_0c03e3d2;
P_0c03e3d2: /* original 5dd1, guest PC 0x0c03e3d2 */
if(!s->budget--) { s->failed_pc=0x0c03e3d2u; return 0; }
r[13]=read(ram,r[13]+4,4);
goto P_0c03e3d4;
P_0c03e3d4: /* original 6322, guest PC 0x0c03e3d4 */
if(!s->budget--) { s->failed_pc=0x0c03e3d4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03e3d6;
P_0c03e3d6: /* original 0dc7, guest PC 0x0c03e3d6 */
if(!s->budget--) { s->failed_pc=0x0c03e3d6u; return 0; }
r[19]=r[13]*r[12];
goto P_0c03e3d8;
P_0c03e3d8: /* original 0c1a, guest PC 0x0c03e3d8 */
if(!s->budget--) { s->failed_pc=0x0c03e3d8u; return 0; }
r[12]=r[19];
goto P_0c03e3da;
P_0c03e3da: /* original 3c3c, guest PC 0x0c03e3da */
if(!s->budget--) { s->failed_pc=0x0c03e3dau; return 0; }
r[12]+=r[3];
goto P_0c03e3dc;
P_0c03e3dc: /* original 51cb, guest PC 0x0c03e3dc */
if(!s->budget--) { s->failed_pc=0x0c03e3dcu; return 0; }
r[1]=read(ram,r[12]+44,4);
goto P_0c03e3de;
P_0c03e3de: /* original 2118, guest PC 0x0c03e3de */
if(!s->budget--) { s->failed_pc=0x0c03e3deu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03e3e0;
P_0c03e3e0: /* original 8b12, guest PC 0x0c03e3e0 */
if(!s->budget--) { s->failed_pc=0x0c03e3e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03e408; }
goto P_0c03e3e2;
P_0c03e3e2: /* original 64a3, guest PC 0x0c03e3e2 */
if(!s->budget--) { s->failed_pc=0x0c03e3e2u; return 0; }
r[4]=r[10];
goto P_0c03e3e4;
P_0c03e3e4: /* original 53f1, guest PC 0x0c03e3e4 */
if(!s->budget--) { s->failed_pc=0x0c03e3e4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c03e3e6;
P_0c03e3e6: /* original 4408, guest PC 0x0c03e3e6 */
if(!s->budget--) { s->failed_pc=0x0c03e3e6u; return 0; }
r[4]<<=2;
goto P_0c03e3e8;
P_0c03e3e8: /* original d174, guest PC 0x0c03e3e8 */
if(!s->budget--) { s->failed_pc=0x0c03e3e8u; return 0; }
r[1]=read(ram,0x0c03e5bcu,4);
goto P_0c03e3ea;
P_0c03e3ea: /* original 4408, guest PC 0x0c03e3ea */
if(!s->budget--) { s->failed_pc=0x0c03e3eau; return 0; }
r[4]<<=2;
goto P_0c03e3ec;
P_0c03e3ec: /* original 343c, guest PC 0x0c03e3ec */
if(!s->budget--) { s->failed_pc=0x0c03e3ecu; return 0; }
r[4]+=r[3];
goto P_0c03e3ee;
P_0c03e3ee: /* original 63f2, guest PC 0x0c03e3ee */
if(!s->budget--) { s->failed_pc=0x0c03e3eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03e3f0;
P_0c03e3f0: /* original 5a42, guest PC 0x0c03e3f0 */
if(!s->budget--) { s->failed_pc=0x0c03e3f0u; return 0; }
r[10]=read(ram,r[4]+8,4);
goto P_0c03e3f2;
P_0c03e3f2: /* original 4a09, guest PC 0x0c03e3f2 */
if(!s->budget--) { s->failed_pc=0x0c03e3f2u; return 0; }
r[10]>>=2;
goto P_0c03e3f4;
P_0c03e3f4: /* original 66a3, guest PC 0x0c03e3f4 */
if(!s->budget--) { s->failed_pc=0x0c03e3f4u; return 0; }
r[6]=r[10];
goto P_0c03e3f6;
P_0c03e3f6: /* original 4608, guest PC 0x0c03e3f6 */
if(!s->budget--) { s->failed_pc=0x0c03e3f6u; return 0; }
r[6]<<=2;
goto P_0c03e3f8;
P_0c03e3f8: /* original 363c, guest PC 0x0c03e3f8 */
if(!s->budget--) { s->failed_pc=0x0c03e3f8u; return 0; }
r[6]+=r[3];
goto P_0c03e3fa;
P_0c03e3fa: /* original 410b, guest PC 0x0c03e3fa */
if(!s->budget--) { s->failed_pc=0x0c03e3fau; return 0; }
target=r[1];
r[16]=code_base|0x0c03e3feu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e3feu) { target=s->pc; goto dispatch; }
goto P_0c03e3fe;
P_0c03e3fc: /* original 65d3, guest PC 0x0c03e3fc */
if(!s->budget--) { s->failed_pc=0x0c03e3fcu; return 0; }
r[5]=r[13];
goto P_0c03e3fe;
P_0c03e3fe: /* original d370, guest PC 0x0c03e3fe */
if(!s->budget--) { s->failed_pc=0x0c03e3feu; return 0; }
r[3]=read(ram,0x0c03e5c0u,4);
goto P_0c03e400;
P_0c03e400: /* original 280b, guest PC 0x0c03e400 */
if(!s->budget--) { s->failed_pc=0x0c03e400u; return 0; }
r[8]|=r[0];
goto P_0c03e402;
P_0c03e402: /* original 430b, guest PC 0x0c03e402 */
if(!s->budget--) { s->failed_pc=0x0c03e402u; return 0; }
target=r[3];
r[16]=code_base|0x0c03e406u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03e406u) { target=s->pc; goto dispatch; }
goto P_0c03e406;
P_0c03e404: /* original 64d3, guest PC 0x0c03e404 */
if(!s->budget--) { s->failed_pc=0x0c03e404u; return 0; }
r[4]=r[13];
goto P_0c03e406;
P_0c03e406: /* original 1cde, guest PC 0x0c03e406 */
if(!s->budget--) { s->failed_pc=0x0c03e406u; return 0; }
write(ram,r[12]+56,r[13],4);
goto P_0c03e408;
P_0c03e408: /* original 52cb, guest PC 0x0c03e408 */
if(!s->budget--) { s->failed_pc=0x0c03e408u; return 0; }
r[2]=read(ram,r[12]+44,4);
goto P_0c03e40a;
P_0c03e40a: /* original 4b10, guest PC 0x0c03e40a */
if(!s->budget--) { s->failed_pc=0x0c03e40au; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c03e40c;
P_0c03e40c: /* original 7201, guest PC 0x0c03e40c */
if(!s->budget--) { s->failed_pc=0x0c03e40cu; return 0; }
r[2]+=0x00000001u;
goto P_0c03e40e;
P_0c03e40e: /* original 1c2b, guest PC 0x0c03e40e */
if(!s->budget--) { s->failed_pc=0x0c03e40eu; return 0; }
write(ram,r[12]+44,r[2],4);
goto P_0c03e410;
P_0c03e410: /* original 8fbb, guest PC 0x0c03e410 */
if(!s->budget--) { s->failed_pc=0x0c03e410u; return 0; }
cond=r[17]&1u;
r[9]+=0x0000000cu;
if(!cond) { goto P_0c03e38a; }
goto P_0c03e414;
P_0c03e412: /* original 790c, guest PC 0x0c03e412 */
if(!s->budget--) { s->failed_pc=0x0c03e412u; return 0; }
r[9]+=0x0000000cu;
goto P_0c03e414;
P_0c03e414: /* original 6083, guest PC 0x0c03e414 */
if(!s->budget--) { s->failed_pc=0x0c03e414u; return 0; }
r[0]=r[8];
goto P_0c03e416;
P_0c03e416: /* original 7f08, guest PC 0x0c03e416 */
if(!s->budget--) { s->failed_pc=0x0c03e416u; return 0; }
r[15]+=0x00000008u;
goto P_0c03e418;
P_0c03e418: /* original 4f16, guest PC 0x0c03e418 */
if(!s->budget--) { s->failed_pc=0x0c03e418u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e41a;
P_0c03e41a: /* original 4f26, guest PC 0x0c03e41a */
if(!s->budget--) { s->failed_pc=0x0c03e41au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e41c;
P_0c03e41c: /* original 68f6, guest PC 0x0c03e41c */
if(!s->budget--) { s->failed_pc=0x0c03e41cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03e41e;
P_0c03e41e: /* original 69f6, guest PC 0x0c03e41e */
if(!s->budget--) { s->failed_pc=0x0c03e41eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03e420;
P_0c03e420: /* original 6af6, guest PC 0x0c03e420 */
if(!s->budget--) { s->failed_pc=0x0c03e420u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03e422;
P_0c03e422: /* original 6bf6, guest PC 0x0c03e422 */
if(!s->budget--) { s->failed_pc=0x0c03e422u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03e424;
P_0c03e424: /* original 6cf6, guest PC 0x0c03e424 */
if(!s->budget--) { s->failed_pc=0x0c03e424u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03e426;
P_0c03e426: /* original 6df6, guest PC 0x0c03e426 */
if(!s->budget--) { s->failed_pc=0x0c03e426u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03e428;
P_0c03e428: /* original 000b, guest PC 0x0c03e428 */
if(!s->budget--) { s->failed_pc=0x0c03e428u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03e42a: /* original 6ef6, guest PC 0x0c03e42a */
if(!s->budget--) { s->failed_pc=0x0c03e42au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e42cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e42cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
