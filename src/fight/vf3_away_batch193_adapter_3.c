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
int vf3_away_batch193_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042b70u: goto P_0c042b70;
case 0x0c042b72u: goto P_0c042b72;
case 0x0c042b74u: goto P_0c042b74;
case 0x0c042b76u: goto P_0c042b76;
case 0x0c042b78u: goto P_0c042b78;
case 0x0c042b7au: goto P_0c042b7a;
case 0x0c042b7cu: goto P_0c042b7c;
case 0x0c042b7eu: goto P_0c042b7e;
case 0x0c042b80u: goto P_0c042b80;
case 0x0c042b82u: goto P_0c042b82;
case 0x0c042b84u: goto P_0c042b84;
case 0x0c042b86u: goto P_0c042b86;
case 0x0c042b88u: goto P_0c042b88;
case 0x0c042b8au: goto P_0c042b8a;
case 0x0c042b8cu: goto P_0c042b8c;
case 0x0c042bb0u: goto P_0c042bb0;
case 0x0c042bb2u: goto P_0c042bb2;
case 0x0c042bb4u: goto P_0c042bb4;
case 0x0c042bb6u: goto P_0c042bb6;
case 0x0c042bb8u: goto P_0c042bb8;
case 0x0c042bbau: goto P_0c042bba;
case 0x0c042bbcu: goto P_0c042bbc;
case 0x0c042bbeu: goto P_0c042bbe;
case 0x0c042bc0u: goto P_0c042bc0;
case 0x0c042bc2u: goto P_0c042bc2;
case 0x0c042bc4u: goto P_0c042bc4;
case 0x0c042bc6u: goto P_0c042bc6;
case 0x0c042bc8u: goto P_0c042bc8;
case 0x0c042bcau: goto P_0c042bca;
case 0x0c042bccu: goto P_0c042bcc;
case 0x0c042bceu: goto P_0c042bce;
case 0x0c042bd0u: goto P_0c042bd0;
case 0x0c042be0u: goto P_0c042be0;
case 0x0c042be2u: goto P_0c042be2;
case 0x0c042be4u: goto P_0c042be4;
case 0x0c042be6u: goto P_0c042be6;
case 0x0c042be8u: goto P_0c042be8;
case 0x0c042beau: goto P_0c042bea;
case 0x0c042becu: goto P_0c042bec;
case 0x0c042beeu: goto P_0c042bee;
case 0x0c042bf0u: goto P_0c042bf0;
case 0x0c042bf2u: goto P_0c042bf2;
case 0x0c042bf4u: goto P_0c042bf4;
case 0x0c042bf6u: goto P_0c042bf6;
case 0x0c042bf8u: goto P_0c042bf8;
case 0x0c042bfau: goto P_0c042bfa;
case 0x0c042c00u: goto P_0c042c00;
case 0x0c042c02u: goto P_0c042c02;
case 0x0c042c04u: goto P_0c042c04;
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c0475aau: goto P_0c0475aa;
case 0x0c0475acu: goto P_0c0475ac;
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
P_0c042b70: /* original 9212, guest PC 0x0c042b70 */
if(!s->budget--) { s->failed_pc=0x0c042b70u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b98u,2);
goto P_0c042b72;
P_0c042b72: /* original 3468, guest PC 0x0c042b72 */
if(!s->budget--) { s->failed_pc=0x0c042b72u; return 0; }
r[4]-=r[6];
goto P_0c042b74;
P_0c042b74: /* original 3423, guest PC 0x0c042b74 */
if(!s->budget--) { s->failed_pc=0x0c042b74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b76;
P_0c042b76: /* original 891b, guest PC 0x0c042b76 */
if(!s->budget--) { s->failed_pc=0x0c042b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042bb0; }
goto P_0c042b78;
P_0c042b78: /* original 6043, guest PC 0x0c042b78 */
if(!s->budget--) { s->failed_pc=0x0c042b78u; return 0; }
r[0]=r[4];
goto P_0c042b7a;
P_0c042b7a: /* original 0009, guest PC 0x0c042b7a */
if(!s->budget--) { s->failed_pc=0x0c042b7au; return 0; }
goto P_0c042b7c;
P_0c042b7c: /* original 4008, guest PC 0x0c042b7c */
if(!s->budget--) { s->failed_pc=0x0c042b7cu; return 0; }
r[0]<<=2;
goto P_0c042b7e;
P_0c042b7e: /* original 6343, guest PC 0x0c042b7e */
if(!s->budget--) { s->failed_pc=0x0c042b7eu; return 0; }
r[3]=r[4];
goto P_0c042b80;
P_0c042b80: /* original 4000, guest PC 0x0c042b80 */
if(!s->budget--) { s->failed_pc=0x0c042b80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b82;
P_0c042b82: /* original 910a, guest PC 0x0c042b82 */
if(!s->budget--) { s->failed_pc=0x0c042b82u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b9au,2);
goto P_0c042b84;
P_0c042b84: /* original 303c, guest PC 0x0c042b84 */
if(!s->budget--) { s->failed_pc=0x0c042b84u; return 0; }
r[0]+=r[3];
goto P_0c042b86;
P_0c042b86: /* original 4008, guest PC 0x0c042b86 */
if(!s->budget--) { s->failed_pc=0x0c042b86u; return 0; }
r[0]<<=2;
goto P_0c042b88;
P_0c042b88: /* original 4000, guest PC 0x0c042b88 */
if(!s->budget--) { s->failed_pc=0x0c042b88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b8a;
P_0c042b8a: /* original 000b, guest PC 0x0c042b8a */
if(!s->budget--) { s->failed_pc=0x0c042b8au; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042b8c: /* original 301c, guest PC 0x0c042b8c */
if(!s->budget--) { s->failed_pc=0x0c042b8cu; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042b8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b8eu; return 0; } return 1;
P_0c042bb0: /* original 9329, guest PC 0x0c042bb0 */
if(!s->budget--) { s->failed_pc=0x0c042bb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c06u,2);
goto P_0c042bb2;
P_0c042bb2: /* original 3433, guest PC 0x0c042bb2 */
if(!s->budget--) { s->failed_pc=0x0c042bb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bb4;
P_0c042bb4: /* original 8b24, guest PC 0x0c042bb4 */
if(!s->budget--) { s->failed_pc=0x0c042bb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042c00; }
goto P_0c042bb6;
P_0c042bb6: /* original 9327, guest PC 0x0c042bb6 */
if(!s->budget--) { s->failed_pc=0x0c042bb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c08u,2);
goto P_0c042bb8;
P_0c042bb8: /* original 3433, guest PC 0x0c042bb8 */
if(!s->budget--) { s->failed_pc=0x0c042bb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bba;
P_0c042bba: /* original 8911, guest PC 0x0c042bba */
if(!s->budget--) { s->failed_pc=0x0c042bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042be0; }
goto P_0c042bbc;
P_0c042bbc: /* original 9025, guest PC 0x0c042bbc */
if(!s->budget--) { s->failed_pc=0x0c042bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0au,2);
goto P_0c042bbe;
P_0c042bbe: /* original d115, guest PC 0x0c042bbe */
if(!s->budget--) { s->failed_pc=0x0c042bbeu; return 0; }
r[1]=read(ram,0x0c042c14u,4);
goto P_0c042bc0;
P_0c042bc0: /* original 304c, guest PC 0x0c042bc0 */
if(!s->budget--) { s->failed_pc=0x0c042bc0u; return 0; }
r[0]+=r[4];
goto P_0c042bc2;
P_0c042bc2: /* original 6203, guest PC 0x0c042bc2 */
if(!s->budget--) { s->failed_pc=0x0c042bc2u; return 0; }
r[2]=r[0];
goto P_0c042bc4;
P_0c042bc4: /* original 4008, guest PC 0x0c042bc4 */
if(!s->budget--) { s->failed_pc=0x0c042bc4u; return 0; }
r[0]<<=2;
goto P_0c042bc6;
P_0c042bc6: /* original 4000, guest PC 0x0c042bc6 */
if(!s->budget--) { s->failed_pc=0x0c042bc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bc8;
P_0c042bc8: /* original 302c, guest PC 0x0c042bc8 */
if(!s->budget--) { s->failed_pc=0x0c042bc8u; return 0; }
r[0]+=r[2];
goto P_0c042bca;
P_0c042bca: /* original 4008, guest PC 0x0c042bca */
if(!s->budget--) { s->failed_pc=0x0c042bcau; return 0; }
r[0]<<=2;
goto P_0c042bcc;
P_0c042bcc: /* original 4000, guest PC 0x0c042bcc */
if(!s->budget--) { s->failed_pc=0x0c042bccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bce;
P_0c042bce: /* original 000b, guest PC 0x0c042bce */
if(!s->budget--) { s->failed_pc=0x0c042bceu; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bd0: /* original 301c, guest PC 0x0c042bd0 */
if(!s->budget--) { s->failed_pc=0x0c042bd0u; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042bd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042bd2u; return 0; } return 1;
P_0c042be0: /* original 9314, guest PC 0x0c042be0 */
if(!s->budget--) { s->failed_pc=0x0c042be0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0cu,2);
goto P_0c042be2;
P_0c042be2: /* original 3433, guest PC 0x0c042be2 */
if(!s->budget--) { s->failed_pc=0x0c042be2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042be4;
P_0c042be4: /* original 890c, guest PC 0x0c042be4 */
if(!s->budget--) { s->failed_pc=0x0c042be4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042c00; }
goto P_0c042be6;
P_0c042be6: /* original 9012, guest PC 0x0c042be6 */
if(!s->budget--) { s->failed_pc=0x0c042be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0eu,2);
goto P_0c042be8;
P_0c042be8: /* original d10b, guest PC 0x0c042be8 */
if(!s->budget--) { s->failed_pc=0x0c042be8u; return 0; }
r[1]=read(ram,0x0c042c18u,4);
goto P_0c042bea;
P_0c042bea: /* original 304c, guest PC 0x0c042bea */
if(!s->budget--) { s->failed_pc=0x0c042beau; return 0; }
r[0]+=r[4];
goto P_0c042bec;
P_0c042bec: /* original 6203, guest PC 0x0c042bec */
if(!s->budget--) { s->failed_pc=0x0c042becu; return 0; }
r[2]=r[0];
goto P_0c042bee;
P_0c042bee: /* original 4008, guest PC 0x0c042bee */
if(!s->budget--) { s->failed_pc=0x0c042beeu; return 0; }
r[0]<<=2;
goto P_0c042bf0;
P_0c042bf0: /* original 4000, guest PC 0x0c042bf0 */
if(!s->budget--) { s->failed_pc=0x0c042bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf2;
P_0c042bf2: /* original 302c, guest PC 0x0c042bf2 */
if(!s->budget--) { s->failed_pc=0x0c042bf2u; return 0; }
r[0]+=r[2];
goto P_0c042bf4;
P_0c042bf4: /* original 4008, guest PC 0x0c042bf4 */
if(!s->budget--) { s->failed_pc=0x0c042bf4u; return 0; }
r[0]<<=2;
goto P_0c042bf6;
P_0c042bf6: /* original 4000, guest PC 0x0c042bf6 */
if(!s->budget--) { s->failed_pc=0x0c042bf6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf8;
P_0c042bf8: /* original 000b, guest PC 0x0c042bf8 */
if(!s->budget--) { s->failed_pc=0x0c042bf8u; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bfa: /* original 301c, guest PC 0x0c042bfa */
if(!s->budget--) { s->failed_pc=0x0c042bfau; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042bfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042bfcu; return 0; } return 1;
P_0c042c00: /* original 9006, guest PC 0x0c042c00 */
if(!s->budget--) { s->failed_pc=0x0c042c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c10u,2);
goto P_0c042c02;
P_0c042c02: /* original 000b, guest PC 0x0c042c02 */
if(!s->budget--) { s->failed_pc=0x0c042c02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042c04: /* original 0009, guest PC 0x0c042c04 */
if(!s->budget--) { s->failed_pc=0x0c042c04u; return 0; }
if(!vf3_matrix_family(0x0c042c06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042c06u; return 0; } return 1;
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
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
P_0c0475aa: /* original 000b, guest PC 0x0c0475aa */
if(!s->budget--) { s->failed_pc=0x0c0475aau; return 0; }
target=r[16];
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
s->pc=target; return ram->oob==0;
P_0c0475ac: /* original 0483, guest PC 0x0c0475ac */
if(!s->budget--) { s->failed_pc=0x0c0475acu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
if(!vf3_matrix_family(0x0c0475aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0475aeu; return 0; } return 1;
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
