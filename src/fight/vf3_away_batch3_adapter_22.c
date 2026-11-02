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
int vf3_away_batch3_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0459fcu: goto P_0c0459fc;
case 0x0c0459feu: goto P_0c0459fe;
case 0x0c045a00u: goto P_0c045a00;
case 0x0c045a02u: goto P_0c045a02;
case 0x0c045a04u: goto P_0c045a04;
case 0x0c045a06u: goto P_0c045a06;
case 0x0c045a08u: goto P_0c045a08;
case 0x0c045a0au: goto P_0c045a0a;
case 0x0c045a0cu: goto P_0c045a0c;
case 0x0c045a0eu: goto P_0c045a0e;
case 0x0c045a10u: goto P_0c045a10;
case 0x0c045a12u: goto P_0c045a12;
case 0x0c045a14u: goto P_0c045a14;
case 0x0c045a16u: goto P_0c045a16;
case 0x0c045a18u: goto P_0c045a18;
case 0x0c045a1au: goto P_0c045a1a;
case 0x0c045a1cu: goto P_0c045a1c;
case 0x0c045a1eu: goto P_0c045a1e;
case 0x0c045a20u: goto P_0c045a20;
case 0x0c045a22u: goto P_0c045a22;
case 0x0c045a24u: goto P_0c045a24;
case 0x0c045a26u: goto P_0c045a26;
case 0x0c045a28u: goto P_0c045a28;
case 0x0c045a2au: goto P_0c045a2a;
case 0x0c045a2cu: goto P_0c045a2c;
case 0x0c045a2eu: goto P_0c045a2e;
case 0x0c045a30u: goto P_0c045a30;
case 0x0c045b0au: goto P_0c045b0a;
case 0x0c045b0cu: goto P_0c045b0c;
case 0x0c045b0eu: goto P_0c045b0e;
case 0x0c045b10u: goto P_0c045b10;
case 0x0c045b12u: goto P_0c045b12;
case 0x0c045b14u: goto P_0c045b14;
case 0x0c045b16u: goto P_0c045b16;
case 0x0c045b18u: goto P_0c045b18;
case 0x0c045b1au: goto P_0c045b1a;
case 0x0c045b1cu: goto P_0c045b1c;
case 0x0c045b1eu: goto P_0c045b1e;
case 0x0c045b20u: goto P_0c045b20;
case 0x0c045b22u: goto P_0c045b22;
case 0x0c045b24u: goto P_0c045b24;
case 0x0c045b26u: goto P_0c045b26;
case 0x0c045b28u: goto P_0c045b28;
case 0x0c045b2au: goto P_0c045b2a;
case 0x0c045b2cu: goto P_0c045b2c;
case 0x0c045b2eu: goto P_0c045b2e;
case 0x0c045b30u: goto P_0c045b30;
case 0x0c045b32u: goto P_0c045b32;
case 0x0c045b60u: goto P_0c045b60;
case 0x0c045b62u: goto P_0c045b62;
case 0x0c045b64u: goto P_0c045b64;
case 0x0c045b66u: goto P_0c045b66;
case 0x0c045b68u: goto P_0c045b68;
case 0x0c045b6au: goto P_0c045b6a;
case 0x0c045b6cu: goto P_0c045b6c;
case 0x0c045b6eu: goto P_0c045b6e;
case 0x0c045b70u: goto P_0c045b70;
case 0x0c045b72u: goto P_0c045b72;
case 0x0c045b74u: goto P_0c045b74;
case 0x0c045b76u: goto P_0c045b76;
case 0x0c045ebeu: goto P_0c045ebe;
case 0x0c045ec0u: goto P_0c045ec0;
case 0x0c045ec2u: goto P_0c045ec2;
case 0x0c045ec4u: goto P_0c045ec4;
case 0x0c045ec6u: goto P_0c045ec6;
case 0x0c045ec8u: goto P_0c045ec8;
case 0x0c045ecau: goto P_0c045eca;
case 0x0c045eccu: goto P_0c045ecc;
case 0x0c045eceu: goto P_0c045ece;
case 0x0c045ed0u: goto P_0c045ed0;
case 0x0c045ef4u: goto P_0c045ef4;
case 0x0c045ef6u: goto P_0c045ef6;
case 0x0c045ef8u: goto P_0c045ef8;
case 0x0c045efau: goto P_0c045efa;
case 0x0c045efcu: goto P_0c045efc;
case 0x0c045efeu: goto P_0c045efe;
case 0x0c045f00u: goto P_0c045f00;
case 0x0c045f02u: goto P_0c045f02;
case 0x0c045f04u: goto P_0c045f04;
case 0x0c045f06u: goto P_0c045f06;
case 0x0c045f08u: goto P_0c045f08;
case 0x0c045f0au: goto P_0c045f0a;
case 0x0c045f0cu: goto P_0c045f0c;
case 0x0c045f0eu: goto P_0c045f0e;
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
P_0c0459fc: /* original 4f22, guest PC 0x0c0459fc */
if(!s->budget--) { s->failed_pc=0x0c0459fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0459fe;
P_0c0459fe: /* original 6353, guest PC 0x0c0459fe */
if(!s->budget--) { s->failed_pc=0x0c0459feu; return 0; }
r[3]=r[5];
goto P_0c045a00;
P_0c045a00: /* original 7ff4, guest PC 0x0c045a00 */
if(!s->budget--) { s->failed_pc=0x0c045a00u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c045a02;
P_0c045a02: /* original 1f41, guest PC 0x0c045a02 */
if(!s->budget--) { s->failed_pc=0x0c045a02u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c045a04;
P_0c045a04: /* original 1f52, guest PC 0x0c045a04 */
if(!s->budget--) { s->failed_pc=0x0c045a04u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c045a06;
P_0c045a06: /* original 2f56, guest PC 0x0c045a06 */
if(!s->budget--) { s->failed_pc=0x0c045a06u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a08;
P_0c045a08: /* original 52f2, guest PC 0x0c045a08 */
if(!s->budget--) { s->failed_pc=0x0c045a08u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c045a0a;
P_0c045a0a: /* original 2f26, guest PC 0x0c045a0a */
if(!s->budget--) { s->failed_pc=0x0c045a0au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a0c;
P_0c045a0c: /* original d395, guest PC 0x0c045a0c */
if(!s->budget--) { s->failed_pc=0x0c045a0cu; return 0; }
r[3]=read(ram,0x0c045c64u,4);
goto P_0c045a0e;
P_0c045a0e: /* original d296, guest PC 0x0c045a0e */
if(!s->budget--) { s->failed_pc=0x0c045a0eu; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045a10;
P_0c045a10: /* original 420b, guest PC 0x0c045a10 */
if(!s->budget--) { s->failed_pc=0x0c045a10u; return 0; }
target=r[2];
r[16]=code_base|0x0c045a14u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045a14u) { target=s->pc; goto dispatch; }
goto P_0c045a14;
P_0c045a12: /* original 2f36, guest PC 0x0c045a12 */
if(!s->budget--) { s->failed_pc=0x0c045a12u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a14;
P_0c045a14: /* original 51f5, guest PC 0x0c045a14 */
if(!s->budget--) { s->failed_pc=0x0c045a14u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c045a16;
P_0c045a16: /* original e300, guest PC 0x0c045a16 */
if(!s->budget--) { s->failed_pc=0x0c045a16u; return 0; }
r[3]=0x00000000u;
goto P_0c045a18;
P_0c045a18: /* original e509, guest PC 0x0c045a18 */
if(!s->budget--) { s->failed_pc=0x0c045a18u; return 0; }
r[5]=0x00000009u;
goto P_0c045a1a;
P_0c045a1a: /* original 1f13, guest PC 0x0c045a1a */
if(!s->budget--) { s->failed_pc=0x0c045a1au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c045a1c;
P_0c045a1c: /* original e701, guest PC 0x0c045a1c */
if(!s->budget--) { s->failed_pc=0x0c045a1cu; return 0; }
r[7]=0x00000001u;
goto P_0c045a1e;
P_0c045a1e: /* original 2f36, guest PC 0x0c045a1e */
if(!s->budget--) { s->failed_pc=0x0c045a1eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a20;
P_0c045a20: /* original 2f36, guest PC 0x0c045a20 */
if(!s->budget--) { s->failed_pc=0x0c045a20u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a22;
P_0c045a22: /* original 66f3, guest PC 0x0c045a22 */
if(!s->budget--) { s->failed_pc=0x0c045a22u; return 0; }
r[6]=r[15];
goto P_0c045a24;
P_0c045a24: /* original 7614, guest PC 0x0c045a24 */
if(!s->budget--) { s->failed_pc=0x0c045a24u; return 0; }
r[6]+=0x00000014u;
goto P_0c045a26;
P_0c045a26: /* original b94b, guest PC 0x0c045a26 */
if(!s->budget--) { s->failed_pc=0x0c045a26u; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045a2au;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045a2au) { target=s->pc; goto dispatch; }
goto P_0c045a2a;
P_0c045a28: /* original 54f6, guest PC 0x0c045a28 */
if(!s->budget--) { s->failed_pc=0x0c045a28u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c045a2a;
P_0c045a2a: /* original 7f20, guest PC 0x0c045a2a */
if(!s->budget--) { s->failed_pc=0x0c045a2au; return 0; }
r[15]+=0x00000020u;
goto P_0c045a2c;
P_0c045a2c: /* original 4f26, guest PC 0x0c045a2c */
if(!s->budget--) { s->failed_pc=0x0c045a2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a2e;
P_0c045a2e: /* original 000b, guest PC 0x0c045a2e */
if(!s->budget--) { s->failed_pc=0x0c045a2eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045a30: /* original 0009, guest PC 0x0c045a30 */
if(!s->budget--) { s->failed_pc=0x0c045a30u; return 0; }
if(!vf3_matrix_family(0x0c045a32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045a32u; return 0; } return 1;
P_0c045b0a: /* original 4f22, guest PC 0x0c045b0a */
if(!s->budget--) { s->failed_pc=0x0c045b0au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045b0c;
P_0c045b0c: /* original 6343, guest PC 0x0c045b0c */
if(!s->budget--) { s->failed_pc=0x0c045b0cu; return 0; }
r[3]=r[4];
goto P_0c045b0e;
P_0c045b0e: /* original 7ffc, guest PC 0x0c045b0e */
if(!s->budget--) { s->failed_pc=0x0c045b0eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c045b10;
P_0c045b10: /* original 2f42, guest PC 0x0c045b10 */
if(!s->budget--) { s->failed_pc=0x0c045b10u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c045b12;
P_0c045b12: /* original 2f46, guest PC 0x0c045b12 */
if(!s->budget--) { s->failed_pc=0x0c045b12u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b14;
P_0c045b14: /* original d259, guest PC 0x0c045b14 */
if(!s->budget--) { s->failed_pc=0x0c045b14u; return 0; }
r[2]=read(ram,0x0c045c7cu,4);
goto P_0c045b16;
P_0c045b16: /* original d354, guest PC 0x0c045b16 */
if(!s->budget--) { s->failed_pc=0x0c045b16u; return 0; }
r[3]=read(ram,0x0c045c68u,4);
goto P_0c045b18;
P_0c045b18: /* original 430b, guest PC 0x0c045b18 */
if(!s->budget--) { s->failed_pc=0x0c045b18u; return 0; }
target=r[3];
r[16]=code_base|0x0c045b1cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045b1cu) { target=s->pc; goto dispatch; }
goto P_0c045b1c;
P_0c045b1a: /* original 2f26, guest PC 0x0c045b1a */
if(!s->budget--) { s->failed_pc=0x0c045b1au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b1c;
P_0c045b1c: /* original e100, guest PC 0x0c045b1c */
if(!s->budget--) { s->failed_pc=0x0c045b1cu; return 0; }
r[1]=0x00000000u;
goto P_0c045b1e;
P_0c045b1e: /* original 2f16, guest PC 0x0c045b1e */
if(!s->budget--) { s->failed_pc=0x0c045b1eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b20;
P_0c045b20: /* original 6613, guest PC 0x0c045b20 */
if(!s->budget--) { s->failed_pc=0x0c045b20u; return 0; }
r[6]=r[1];
goto P_0c045b22;
P_0c045b22: /* original e503, guest PC 0x0c045b22 */
if(!s->budget--) { s->failed_pc=0x0c045b22u; return 0; }
r[5]=0x00000003u;
goto P_0c045b24;
P_0c045b24: /* original 2f16, guest PC 0x0c045b24 */
if(!s->budget--) { s->failed_pc=0x0c045b24u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b26;
P_0c045b26: /* original 6713, guest PC 0x0c045b26 */
if(!s->budget--) { s->failed_pc=0x0c045b26u; return 0; }
r[7]=r[1];
goto P_0c045b28;
P_0c045b28: /* original b8ca, guest PC 0x0c045b28 */
if(!s->budget--) { s->failed_pc=0x0c045b28u; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045b2cu;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045b2cu) { target=s->pc; goto dispatch; }
goto P_0c045b2c;
P_0c045b2a: /* original 54f4, guest PC 0x0c045b2a */
if(!s->budget--) { s->failed_pc=0x0c045b2au; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c045b2c;
P_0c045b2c: /* original 7f14, guest PC 0x0c045b2c */
if(!s->budget--) { s->failed_pc=0x0c045b2cu; return 0; }
r[15]+=0x00000014u;
goto P_0c045b2e;
P_0c045b2e: /* original 4f26, guest PC 0x0c045b2e */
if(!s->budget--) { s->failed_pc=0x0c045b2eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b30;
P_0c045b30: /* original 000b, guest PC 0x0c045b30 */
if(!s->budget--) { s->failed_pc=0x0c045b30u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045b32: /* original 0009, guest PC 0x0c045b32 */
if(!s->budget--) { s->failed_pc=0x0c045b32u; return 0; }
if(!vf3_matrix_family(0x0c045b34u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045b34u; return 0; } return 1;
P_0c045b60: /* original 4f22, guest PC 0x0c045b60 */
if(!s->budget--) { s->failed_pc=0x0c045b60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045b62;
P_0c045b62: /* original e300, guest PC 0x0c045b62 */
if(!s->budget--) { s->failed_pc=0x0c045b62u; return 0; }
r[3]=0x00000000u;
goto P_0c045b64;
P_0c045b64: /* original 6633, guest PC 0x0c045b64 */
if(!s->budget--) { s->failed_pc=0x0c045b64u; return 0; }
r[6]=r[3];
goto P_0c045b66;
P_0c045b66: /* original 6733, guest PC 0x0c045b66 */
if(!s->budget--) { s->failed_pc=0x0c045b66u; return 0; }
r[7]=r[3];
goto P_0c045b68;
P_0c045b68: /* original 2f36, guest PC 0x0c045b68 */
if(!s->budget--) { s->failed_pc=0x0c045b68u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b6a;
P_0c045b6a: /* original 2f36, guest PC 0x0c045b6a */
if(!s->budget--) { s->failed_pc=0x0c045b6au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b6c;
P_0c045b6c: /* original b8a8, guest PC 0x0c045b6c */
if(!s->budget--) { s->failed_pc=0x0c045b6cu; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045b70u;
r[5]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045b70u) { target=s->pc; goto dispatch; }
goto P_0c045b70;
P_0c045b6e: /* original e502, guest PC 0x0c045b6e */
if(!s->budget--) { s->failed_pc=0x0c045b6eu; return 0; }
r[5]=0x00000002u;
goto P_0c045b70;
P_0c045b70: /* original 7f08, guest PC 0x0c045b70 */
if(!s->budget--) { s->failed_pc=0x0c045b70u; return 0; }
r[15]+=0x00000008u;
goto P_0c045b72;
P_0c045b72: /* original 4f26, guest PC 0x0c045b72 */
if(!s->budget--) { s->failed_pc=0x0c045b72u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b74;
P_0c045b74: /* original 000b, guest PC 0x0c045b74 */
if(!s->budget--) { s->failed_pc=0x0c045b74u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045b76: /* original 0009, guest PC 0x0c045b76 */
if(!s->budget--) { s->failed_pc=0x0c045b76u; return 0; }
if(!vf3_matrix_family(0x0c045b78u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045b78u; return 0; } return 1;
P_0c045ebe: /* original d30b, guest PC 0x0c045ebe */
if(!s->budget--) { s->failed_pc=0x0c045ebeu; return 0; }
r[3]=read(ram,0x0c045eecu,4);
goto P_0c045ec0;
P_0c045ec0: /* original 9007, guest PC 0x0c045ec0 */
if(!s->budget--) { s->failed_pc=0x0c045ec0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045ed2u,2);
goto P_0c045ec2;
P_0c045ec2: /* original 6432, guest PC 0x0c045ec2 */
if(!s->budget--) { s->failed_pc=0x0c045ec2u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c045ec4;
P_0c045ec4: /* original d20a, guest PC 0x0c045ec4 */
if(!s->budget--) { s->failed_pc=0x0c045ec4u; return 0; }
r[2]=read(ram,0x0c045ef0u,4);
goto P_0c045ec6;
P_0c045ec6: /* original 044e, guest PC 0x0c045ec6 */
if(!s->budget--) { s->failed_pc=0x0c045ec6u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c045ec8;
P_0c045ec8: /* original 6142, guest PC 0x0c045ec8 */
if(!s->budget--) { s->failed_pc=0x0c045ec8u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c045eca;
P_0c045eca: /* original 212b, guest PC 0x0c045eca */
if(!s->budget--) { s->failed_pc=0x0c045ecau; return 0; }
r[1]|=r[2];
goto P_0c045ecc;
P_0c045ecc: /* original 2412, guest PC 0x0c045ecc */
if(!s->budget--) { s->failed_pc=0x0c045eccu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c045ece;
P_0c045ece: /* original 000b, guest PC 0x0c045ece */
if(!s->budget--) { s->failed_pc=0x0c045eceu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c045ed0: /* original e000, guest PC 0x0c045ed0 */
if(!s->budget--) { s->failed_pc=0x0c045ed0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c045ed2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045ed2u; return 0; } return 1;
P_0c045ef4: /* original 4615, guest PC 0x0c045ef4 */
if(!s->budget--) { s->failed_pc=0x0c045ef4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c045ef6;
P_0c045ef6: /* original e700, guest PC 0x0c045ef6 */
if(!s->budget--) { s->failed_pc=0x0c045ef6u; return 0; }
r[7]=0x00000000u;
goto P_0c045ef8;
P_0c045ef8: /* original 8f05, guest PC 0x0c045ef8 */
if(!s->budget--) { s->failed_pc=0x0c045ef8u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c045f06; }
goto P_0c045efc;
P_0c045efa: /* original 6043, guest PC 0x0c045efa */
if(!s->budget--) { s->failed_pc=0x0c045efau; return 0; }
r[0]=r[4];
goto P_0c045efc;
P_0c045efc: /* original 7701, guest PC 0x0c045efc */
if(!s->budget--) { s->failed_pc=0x0c045efcu; return 0; }
r[7]+=0x00000001u;
goto P_0c045efe;
P_0c045efe: /* original 2052, guest PC 0x0c045efe */
if(!s->budget--) { s->failed_pc=0x0c045efeu; return 0; }
write(ram,r[0],r[5],4);
goto P_0c045f00;
P_0c045f00: /* original 3763, guest PC 0x0c045f00 */
if(!s->budget--) { s->failed_pc=0x0c045f00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c045f02;
P_0c045f02: /* original 8ffb, guest PC 0x0c045f02 */
if(!s->budget--) { s->failed_pc=0x0c045f02u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000004u;
if(!cond) { goto P_0c045efc; }
goto P_0c045f06;
P_0c045f04: /* original 7004, guest PC 0x0c045f04 */
if(!s->budget--) { s->failed_pc=0x0c045f04u; return 0; }
r[0]+=0x00000004u;
goto P_0c045f06;
P_0c045f06: /* original 000b, guest PC 0x0c045f06 */
if(!s->budget--) { s->failed_pc=0x0c045f06u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c045f08: /* original 6063, guest PC 0x0c045f08 */
if(!s->budget--) { s->failed_pc=0x0c045f08u; return 0; }
r[0]=r[6];
goto P_0c045f0a;
P_0c045f0a: /* original d006, guest PC 0x0c045f0a */
if(!s->budget--) { s->failed_pc=0x0c045f0au; return 0; }
r[0]=read(ram,0x0c045f24u,4);
goto P_0c045f0c;
P_0c045f0c: /* original 000b, guest PC 0x0c045f0c */
if(!s->budget--) { s->failed_pc=0x0c045f0cu; return 0; }
target=r[16];
r[0]&=r[4];
s->pc=target; return ram->oob==0;
P_0c045f0e: /* original 2049, guest PC 0x0c045f0e */
if(!s->budget--) { s->failed_pc=0x0c045f0eu; return 0; }
r[0]&=r[4];
if(!vf3_matrix_family(0x0c045f10u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045f10u; return 0; } return 1;
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
