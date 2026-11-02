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
int vf3_away_batch5_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04e170u: goto P_0c04e170;
case 0x0c04e172u: goto P_0c04e172;
case 0x0c04e174u: goto P_0c04e174;
case 0x0c04e176u: goto P_0c04e176;
case 0x0c04e178u: goto P_0c04e178;
case 0x0c04e17au: goto P_0c04e17a;
case 0x0c04e17cu: goto P_0c04e17c;
case 0x0c04e17eu: goto P_0c04e17e;
case 0x0c04e180u: goto P_0c04e180;
case 0x0c04e182u: goto P_0c04e182;
case 0x0c04e184u: goto P_0c04e184;
case 0x0c04e186u: goto P_0c04e186;
case 0x0c04e188u: goto P_0c04e188;
case 0x0c04e18au: goto P_0c04e18a;
case 0x0c04e18cu: goto P_0c04e18c;
case 0x0c04e18eu: goto P_0c04e18e;
case 0x0c04e190u: goto P_0c04e190;
case 0x0c04e192u: goto P_0c04e192;
case 0x0c04e194u: goto P_0c04e194;
case 0x0c04e196u: goto P_0c04e196;
case 0x0c04e198u: goto P_0c04e198;
case 0x0c04e19au: goto P_0c04e19a;
case 0x0c04e19cu: goto P_0c04e19c;
case 0x0c04e19eu: goto P_0c04e19e;
case 0x0c04e1a0u: goto P_0c04e1a0;
case 0x0c04e1a2u: goto P_0c04e1a2;
case 0x0c04e1a4u: goto P_0c04e1a4;
case 0x0c04e1a6u: goto P_0c04e1a6;
case 0x0c04e1a8u: goto P_0c04e1a8;
case 0x0c04e1aau: goto P_0c04e1aa;
case 0x0c04e1acu: goto P_0c04e1ac;
case 0x0c04e1aeu: goto P_0c04e1ae;
case 0x0c04e1b0u: goto P_0c04e1b0;
case 0x0c04e1b2u: goto P_0c04e1b2;
case 0x0c04e1b4u: goto P_0c04e1b4;
case 0x0c04e1b6u: goto P_0c04e1b6;
case 0x0c04e1b8u: goto P_0c04e1b8;
case 0x0c04e1bau: goto P_0c04e1ba;
case 0x0c04e1bcu: goto P_0c04e1bc;
case 0x0c04e1beu: goto P_0c04e1be;
case 0x0c04e1c0u: goto P_0c04e1c0;
case 0x0c04e1c2u: goto P_0c04e1c2;
case 0x0c04e1c4u: goto P_0c04e1c4;
case 0x0c04e1c6u: goto P_0c04e1c6;
case 0x0c04e1c8u: goto P_0c04e1c8;
case 0x0c04e1cau: goto P_0c04e1ca;
case 0x0c04e1ccu: goto P_0c04e1cc;
case 0x0c04e1ceu: goto P_0c04e1ce;
case 0x0c04e1d0u: goto P_0c04e1d0;
case 0x0c04e1d2u: goto P_0c04e1d2;
case 0x0c04e1d4u: goto P_0c04e1d4;
case 0x0c04e1d6u: goto P_0c04e1d6;
case 0x0c04e1d8u: goto P_0c04e1d8;
case 0x0c04e1dau: goto P_0c04e1da;
case 0x0c04e1dcu: goto P_0c04e1dc;
case 0x0c04e1deu: goto P_0c04e1de;
case 0x0c04e1e0u: goto P_0c04e1e0;
case 0x0c04e1e2u: goto P_0c04e1e2;
case 0x0c04e1e4u: goto P_0c04e1e4;
case 0x0c04e1e6u: goto P_0c04e1e6;
case 0x0c04e1e8u: goto P_0c04e1e8;
case 0x0c04e1eau: goto P_0c04e1ea;
case 0x0c04e1ecu: goto P_0c04e1ec;
case 0x0c04e1eeu: goto P_0c04e1ee;
case 0x0c04e1f0u: goto P_0c04e1f0;
case 0x0c04e1f2u: goto P_0c04e1f2;
case 0x0c04e1f4u: goto P_0c04e1f4;
case 0x0c04e1f6u: goto P_0c04e1f6;
case 0x0c04e1f8u: goto P_0c04e1f8;
case 0x0c04e1fau: goto P_0c04e1fa;
case 0x0c04e1fcu: goto P_0c04e1fc;
case 0x0c04e1feu: goto P_0c04e1fe;
case 0x0c04e200u: goto P_0c04e200;
case 0x0c04e202u: goto P_0c04e202;
case 0x0c04e204u: goto P_0c04e204;
case 0x0c04e206u: goto P_0c04e206;
case 0x0c04e208u: goto P_0c04e208;
case 0x0c04e20au: goto P_0c04e20a;
case 0x0c04e20cu: goto P_0c04e20c;
case 0x0c04e20eu: goto P_0c04e20e;
case 0x0c04e210u: goto P_0c04e210;
case 0x0c04e212u: goto P_0c04e212;
case 0x0c04e214u: goto P_0c04e214;
case 0x0c04e216u: goto P_0c04e216;
case 0x0c04e218u: goto P_0c04e218;
case 0x0c04e21au: goto P_0c04e21a;
case 0x0c04e258u: goto P_0c04e258;
case 0x0c04e25au: goto P_0c04e25a;
case 0x0c04e25cu: goto P_0c04e25c;
case 0x0c04e25eu: goto P_0c04e25e;
case 0x0c04e260u: goto P_0c04e260;
case 0x0c04e262u: goto P_0c04e262;
case 0x0c04e264u: goto P_0c04e264;
case 0x0c04e266u: goto P_0c04e266;
case 0x0c04e268u: goto P_0c04e268;
case 0x0c04e26au: goto P_0c04e26a;
case 0x0c04e26cu: goto P_0c04e26c;
case 0x0c04e26eu: goto P_0c04e26e;
case 0x0c04e270u: goto P_0c04e270;
case 0x0c04e272u: goto P_0c04e272;
case 0x0c04e274u: goto P_0c04e274;
case 0x0c04e276u: goto P_0c04e276;
case 0x0c04e278u: goto P_0c04e278;
case 0x0c04e27au: goto P_0c04e27a;
case 0x0c04e27cu: goto P_0c04e27c;
case 0x0c04e27eu: goto P_0c04e27e;
case 0x0c04e280u: goto P_0c04e280;
case 0x0c04e282u: goto P_0c04e282;
case 0x0c04e284u: goto P_0c04e284;
case 0x0c04e286u: goto P_0c04e286;
case 0x0c04e288u: goto P_0c04e288;
case 0x0c04e28au: goto P_0c04e28a;
case 0x0c04e28cu: goto P_0c04e28c;
case 0x0c04e28eu: goto P_0c04e28e;
case 0x0c04e290u: goto P_0c04e290;
case 0x0c04e292u: goto P_0c04e292;
case 0x0c04e294u: goto P_0c04e294;
case 0x0c04e296u: goto P_0c04e296;
case 0x0c04e298u: goto P_0c04e298;
case 0x0c04e29au: goto P_0c04e29a;
case 0x0c04e29cu: goto P_0c04e29c;
case 0x0c04e29eu: goto P_0c04e29e;
case 0x0c04e2a0u: goto P_0c04e2a0;
case 0x0c04e2a2u: goto P_0c04e2a2;
case 0x0c04e2a4u: goto P_0c04e2a4;
case 0x0c04e2a6u: goto P_0c04e2a6;
case 0x0c04e2a8u: goto P_0c04e2a8;
case 0x0c04e2aau: goto P_0c04e2aa;
case 0x0c04e2acu: goto P_0c04e2ac;
case 0x0c04e2aeu: goto P_0c04e2ae;
case 0x0c04e2b0u: goto P_0c04e2b0;
case 0x0c04e2b2u: goto P_0c04e2b2;
case 0x0c04e2b4u: goto P_0c04e2b4;
case 0x0c04e2b6u: goto P_0c04e2b6;
case 0x0c04e2b8u: goto P_0c04e2b8;
case 0x0c04e2bau: goto P_0c04e2ba;
case 0x0c04e2bcu: goto P_0c04e2bc;
case 0x0c04e2beu: goto P_0c04e2be;
case 0x0c04e2c0u: goto P_0c04e2c0;
case 0x0c04e2c2u: goto P_0c04e2c2;
case 0x0c04e2c4u: goto P_0c04e2c4;
case 0x0c04e2c6u: goto P_0c04e2c6;
case 0x0c04e2c8u: goto P_0c04e2c8;
case 0x0c04e2cau: goto P_0c04e2ca;
case 0x0c04e2ccu: goto P_0c04e2cc;
case 0x0c04e2ceu: goto P_0c04e2ce;
case 0x0c04e2d0u: goto P_0c04e2d0;
case 0x0c04e2d2u: goto P_0c04e2d2;
case 0x0c04e2d4u: goto P_0c04e2d4;
case 0x0c04e2d6u: goto P_0c04e2d6;
case 0x0c04e2d8u: goto P_0c04e2d8;
case 0x0c04e2dau: goto P_0c04e2da;
case 0x0c04e2dcu: goto P_0c04e2dc;
case 0x0c04e2deu: goto P_0c04e2de;
case 0x0c04e2e0u: goto P_0c04e2e0;
case 0x0c04e2e2u: goto P_0c04e2e2;
case 0x0c04e2e4u: goto P_0c04e2e4;
case 0x0c04e2e6u: goto P_0c04e2e6;
case 0x0c04e2e8u: goto P_0c04e2e8;
case 0x0c04e2eau: goto P_0c04e2ea;
case 0x0c04e2ecu: goto P_0c04e2ec;
case 0x0c04e2eeu: goto P_0c04e2ee;
case 0x0c04e2f0u: goto P_0c04e2f0;
case 0x0c04e2f2u: goto P_0c04e2f2;
case 0x0c04e2f4u: goto P_0c04e2f4;
case 0x0c04e2f6u: goto P_0c04e2f6;
case 0x0c04e2f8u: goto P_0c04e2f8;
case 0x0c04e2fau: goto P_0c04e2fa;
case 0x0c04e2fcu: goto P_0c04e2fc;
case 0x0c04e2feu: goto P_0c04e2fe;
case 0x0c04e300u: goto P_0c04e300;
case 0x0c04e302u: goto P_0c04e302;
case 0x0c04e304u: goto P_0c04e304;
case 0x0c04e306u: goto P_0c04e306;
case 0x0c04e308u: goto P_0c04e308;
case 0x0c04e30au: goto P_0c04e30a;
case 0x0c04e30cu: goto P_0c04e30c;
case 0x0c04e30eu: goto P_0c04e30e;
case 0x0c04e310u: goto P_0c04e310;
case 0x0c04e312u: goto P_0c04e312;
case 0x0c04e314u: goto P_0c04e314;
case 0x0c04e316u: goto P_0c04e316;
case 0x0c04e318u: goto P_0c04e318;
case 0x0c04e31au: goto P_0c04e31a;
case 0x0c04e31cu: goto P_0c04e31c;
case 0x0c04e31eu: goto P_0c04e31e;
case 0x0c04e320u: goto P_0c04e320;
case 0x0c04e322u: goto P_0c04e322;
case 0x0c04e324u: goto P_0c04e324;
case 0x0c04e326u: goto P_0c04e326;
case 0x0c04e328u: goto P_0c04e328;
case 0x0c04e32au: goto P_0c04e32a;
case 0x0c04e32cu: goto P_0c04e32c;
case 0x0c04e32eu: goto P_0c04e32e;
case 0x0c04e330u: goto P_0c04e330;
case 0x0c04e332u: goto P_0c04e332;
case 0x0c04e334u: goto P_0c04e334;
case 0x0c04e336u: goto P_0c04e336;
case 0x0c04e338u: goto P_0c04e338;
case 0x0c04e33au: goto P_0c04e33a;
case 0x0c04e33cu: goto P_0c04e33c;
case 0x0c04e368u: goto P_0c04e368;
case 0x0c04e36au: goto P_0c04e36a;
case 0x0c04e36cu: goto P_0c04e36c;
case 0x0c04e36eu: goto P_0c04e36e;
case 0x0c04e370u: goto P_0c04e370;
case 0x0c04e372u: goto P_0c04e372;
case 0x0c04e374u: goto P_0c04e374;
case 0x0c04e376u: goto P_0c04e376;
case 0x0c04e378u: goto P_0c04e378;
case 0x0c04e37au: goto P_0c04e37a;
case 0x0c04e37cu: goto P_0c04e37c;
case 0x0c04e37eu: goto P_0c04e37e;
case 0x0c04e380u: goto P_0c04e380;
case 0x0c04e382u: goto P_0c04e382;
case 0x0c04e384u: goto P_0c04e384;
case 0x0c04e386u: goto P_0c04e386;
case 0x0c04e388u: goto P_0c04e388;
case 0x0c04e38au: goto P_0c04e38a;
case 0x0c04e38cu: goto P_0c04e38c;
case 0x0c04e38eu: goto P_0c04e38e;
case 0x0c04e390u: goto P_0c04e390;
case 0x0c04e392u: goto P_0c04e392;
case 0x0c04e394u: goto P_0c04e394;
case 0x0c04e396u: goto P_0c04e396;
case 0x0c04e398u: goto P_0c04e398;
case 0x0c04e39au: goto P_0c04e39a;
case 0x0c04e39cu: goto P_0c04e39c;
case 0x0c04e39eu: goto P_0c04e39e;
case 0x0c04e3a0u: goto P_0c04e3a0;
case 0x0c04e3a2u: goto P_0c04e3a2;
case 0x0c04e3a4u: goto P_0c04e3a4;
case 0x0c04e3a6u: goto P_0c04e3a6;
case 0x0c04e3a8u: goto P_0c04e3a8;
case 0x0c04e3aau: goto P_0c04e3aa;
case 0x0c04e3acu: goto P_0c04e3ac;
case 0x0c04e3aeu: goto P_0c04e3ae;
case 0x0c04e3b0u: goto P_0c04e3b0;
case 0x0c04e3b2u: goto P_0c04e3b2;
case 0x0c04e3b4u: goto P_0c04e3b4;
case 0x0c04e3b6u: goto P_0c04e3b6;
case 0x0c04e3b8u: goto P_0c04e3b8;
case 0x0c04e3bau: goto P_0c04e3ba;
case 0x0c04e3bcu: goto P_0c04e3bc;
case 0x0c04e3beu: goto P_0c04e3be;
case 0x0c04e3c0u: goto P_0c04e3c0;
case 0x0c04e3c2u: goto P_0c04e3c2;
case 0x0c04e3c4u: goto P_0c04e3c4;
case 0x0c04e3c6u: goto P_0c04e3c6;
case 0x0c04e3c8u: goto P_0c04e3c8;
case 0x0c04e3cau: goto P_0c04e3ca;
case 0x0c04e3ccu: goto P_0c04e3cc;
case 0x0c04e3ceu: goto P_0c04e3ce;
case 0x0c04e3d0u: goto P_0c04e3d0;
case 0x0c04e3d2u: goto P_0c04e3d2;
case 0x0c04e3d4u: goto P_0c04e3d4;
case 0x0c04e3d6u: goto P_0c04e3d6;
case 0x0c04e3d8u: goto P_0c04e3d8;
case 0x0c04e3dau: goto P_0c04e3da;
case 0x0c04e3dcu: goto P_0c04e3dc;
case 0x0c04e3deu: goto P_0c04e3de;
case 0x0c04e3e0u: goto P_0c04e3e0;
case 0x0c04e3e2u: goto P_0c04e3e2;
case 0x0c04e3e4u: goto P_0c04e3e4;
case 0x0c04e3e6u: goto P_0c04e3e6;
case 0x0c04e3e8u: goto P_0c04e3e8;
case 0x0c04e3eau: goto P_0c04e3ea;
case 0x0c04e3ecu: goto P_0c04e3ec;
case 0x0c04e3eeu: goto P_0c04e3ee;
case 0x0c04e3f0u: goto P_0c04e3f0;
case 0x0c04e3f2u: goto P_0c04e3f2;
case 0x0c04e3f4u: goto P_0c04e3f4;
case 0x0c04e3f6u: goto P_0c04e3f6;
case 0x0c04e3f8u: goto P_0c04e3f8;
case 0x0c04e3fau: goto P_0c04e3fa;
case 0x0c04e3fcu: goto P_0c04e3fc;
case 0x0c04e3feu: goto P_0c04e3fe;
case 0x0c04e400u: goto P_0c04e400;
case 0x0c04e402u: goto P_0c04e402;
case 0x0c04e404u: goto P_0c04e404;
case 0x0c04e406u: goto P_0c04e406;
case 0x0c04e408u: goto P_0c04e408;
case 0x0c04e40au: goto P_0c04e40a;
case 0x0c04e40cu: goto P_0c04e40c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04e170: /* original 2fe6, guest PC 0x0c04e170 */
if(!s->budget--) { s->failed_pc=0x0c04e170u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e172;
P_0c04e172: /* original 6e43, guest PC 0x0c04e172 */
if(!s->budget--) { s->failed_pc=0x0c04e172u; return 0; }
r[14]=r[4];
goto P_0c04e174;
P_0c04e174: /* original 2fd6, guest PC 0x0c04e174 */
if(!s->budget--) { s->failed_pc=0x0c04e174u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e176;
P_0c04e176: /* original 2fc6, guest PC 0x0c04e176 */
if(!s->budget--) { s->failed_pc=0x0c04e176u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e178;
P_0c04e178: /* original 2fb6, guest PC 0x0c04e178 */
if(!s->budget--) { s->failed_pc=0x0c04e178u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e17a;
P_0c04e17a: /* original 4f22, guest PC 0x0c04e17a */
if(!s->budget--) { s->failed_pc=0x0c04e17au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e17c;
P_0c04e17c: /* original 4f12, guest PC 0x0c04e17c */
if(!s->budget--) { s->failed_pc=0x0c04e17cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e17e;
P_0c04e17e: /* original 7ff8, guest PC 0x0c04e17e */
if(!s->budget--) { s->failed_pc=0x0c04e17eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04e180;
P_0c04e180: /* original 2f52, guest PC 0x0c04e180 */
if(!s->budget--) { s->failed_pc=0x0c04e180u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04e182;
P_0c04e182: /* original 53ea, guest PC 0x0c04e182 */
if(!s->budget--) { s->failed_pc=0x0c04e182u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04e184;
P_0c04e184: /* original 924a, guest PC 0x0c04e184 */
if(!s->budget--) { s->failed_pc=0x0c04e184u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e21cu,2);
goto P_0c04e186;
P_0c04e186: /* original d129, guest PC 0x0c04e186 */
if(!s->budget--) { s->failed_pc=0x0c04e186u; return 0; }
r[1]=read(ram,0x0c04e22cu,4);
goto P_0c04e188;
P_0c04e188: /* original 232f, guest PC 0x0c04e188 */
if(!s->budget--) { s->failed_pc=0x0c04e188u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04e18a;
P_0c04e18a: /* original 031a, guest PC 0x0c04e18a */
if(!s->budget--) { s->failed_pc=0x0c04e18au; return 0; }
r[3]=r[19];
goto P_0c04e18c;
P_0c04e18c: /* original 633f, guest PC 0x0c04e18c */
if(!s->budget--) { s->failed_pc=0x0c04e18cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04e18e;
P_0c04e18e: /* original 331c, guest PC 0x0c04e18e */
if(!s->budget--) { s->failed_pc=0x0c04e18eu; return 0; }
r[3]+=r[1];
goto P_0c04e190;
P_0c04e190: /* original 1f31, guest PC 0x0c04e190 */
if(!s->budget--) { s->failed_pc=0x0c04e190u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04e192;
P_0c04e192: /* original d328, guest PC 0x0c04e192 */
if(!s->budget--) { s->failed_pc=0x0c04e192u; return 0; }
r[3]=read(ram,0x0c04e234u,4);
goto P_0c04e194;
P_0c04e194: /* original d226, guest PC 0x0c04e194 */
if(!s->budget--) { s->failed_pc=0x0c04e194u; return 0; }
r[2]=read(ram,0x0c04e230u,4);
goto P_0c04e196;
P_0c04e196: /* original 430b, guest PC 0x0c04e196 */
if(!s->budget--) { s->failed_pc=0x0c04e196u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e19au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e19au) { target=s->pc; goto dispatch; }
goto P_0c04e19a;
P_0c04e198: /* original 2f26, guest PC 0x0c04e198 */
if(!s->budget--) { s->failed_pc=0x0c04e198u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e19a;
P_0c04e19a: /* original d227, guest PC 0x0c04e19a */
if(!s->budget--) { s->failed_pc=0x0c04e19au; return 0; }
r[2]=read(ram,0x0c04e238u,4);
goto P_0c04e19c;
P_0c04e19c: /* original 7f04, guest PC 0x0c04e19c */
if(!s->budget--) { s->failed_pc=0x0c04e19cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04e19e;
P_0c04e19e: /* original 420b, guest PC 0x0c04e19e */
if(!s->budget--) { s->failed_pc=0x0c04e19eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04e1a2u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e1a2u) { target=s->pc; goto dispatch; }
goto P_0c04e1a2;
P_0c04e1a0: /* original 54ea, guest PC 0x0c04e1a0 */
if(!s->budget--) { s->failed_pc=0x0c04e1a0u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e1a2;
P_0c04e1a2: /* original 2008, guest PC 0x0c04e1a2 */
if(!s->budget--) { s->failed_pc=0x0c04e1a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e1a4;
P_0c04e1a4: /* original 8b04, guest PC 0x0c04e1a4 */
if(!s->budget--) { s->failed_pc=0x0c04e1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e1b0; }
goto P_0c04e1a6;
P_0c04e1a6: /* original d225, guest PC 0x0c04e1a6 */
if(!s->budget--) { s->failed_pc=0x0c04e1a6u; return 0; }
r[2]=read(ram,0x0c04e23cu,4);
goto P_0c04e1a8;
P_0c04e1a8: /* original 420b, guest PC 0x0c04e1a8 */
if(!s->budget--) { s->failed_pc=0x0c04e1a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e1acu;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e1acu) { target=s->pc; goto dispatch; }
goto P_0c04e1ac;
P_0c04e1aa: /* original 54ea, guest PC 0x0c04e1aa */
if(!s->budget--) { s->failed_pc=0x0c04e1aau; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e1ac;
P_0c04e1ac: /* original a00e, guest PC 0x0c04e1ac */
if(!s->budget--) { s->failed_pc=0x0c04e1acu; return 0; }
goto P_0c04e1cc;
P_0c04e1ae: /* original 0009, guest PC 0x0c04e1ae */
if(!s->budget--) { s->failed_pc=0x0c04e1aeu; return 0; }
goto P_0c04e1b0;
P_0c04e1b0: /* original d323, guest PC 0x0c04e1b0 */
if(!s->budget--) { s->failed_pc=0x0c04e1b0u; return 0; }
r[3]=read(ram,0x0c04e240u,4);
goto P_0c04e1b2;
P_0c04e1b2: /* original 430b, guest PC 0x0c04e1b2 */
if(!s->budget--) { s->failed_pc=0x0c04e1b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e1b6u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e1b6u) { target=s->pc; goto dispatch; }
goto P_0c04e1b6;
P_0c04e1b4: /* original 54ea, guest PC 0x0c04e1b4 */
if(!s->budget--) { s->failed_pc=0x0c04e1b4u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e1b6;
P_0c04e1b6: /* original 2008, guest PC 0x0c04e1b6 */
if(!s->budget--) { s->failed_pc=0x0c04e1b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e1b8;
P_0c04e1b8: /* original 8908, guest PC 0x0c04e1b8 */
if(!s->budget--) { s->failed_pc=0x0c04e1b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e1cc; }
goto P_0c04e1ba;
P_0c04e1ba: /* original 932f, guest PC 0x0c04e1ba */
if(!s->budget--) { s->failed_pc=0x0c04e1bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e21cu,2);
goto P_0c04e1bc;
P_0c04e1bc: /* original 52ea, guest PC 0x0c04e1bc */
if(!s->budget--) { s->failed_pc=0x0c04e1bcu; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04e1be;
P_0c04e1be: /* original d021, guest PC 0x0c04e1be */
if(!s->budget--) { s->failed_pc=0x0c04e1beu; return 0; }
r[0]=read(ram,0x0c04e244u,4);
goto P_0c04e1c0;
P_0c04e1c0: /* original 223f, guest PC 0x0c04e1c0 */
if(!s->budget--) { s->failed_pc=0x0c04e1c0u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[3]);
goto P_0c04e1c2;
P_0c04e1c2: /* original 021a, guest PC 0x0c04e1c2 */
if(!s->budget--) { s->failed_pc=0x0c04e1c2u; return 0; }
r[2]=r[19];
goto P_0c04e1c4;
P_0c04e1c4: /* original 622f, guest PC 0x0c04e1c4 */
if(!s->budget--) { s->failed_pc=0x0c04e1c4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e1c6;
P_0c04e1c6: /* original 012c, guest PC 0x0c04e1c6 */
if(!s->budget--) { s->failed_pc=0x0c04e1c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c04e1c8;
P_0c04e1c8: /* original 2118, guest PC 0x0c04e1c8 */
if(!s->budget--) { s->failed_pc=0x0c04e1c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04e1ca;
P_0c04e1ca: /* original 8b02, guest PC 0x0c04e1ca */
if(!s->budget--) { s->failed_pc=0x0c04e1cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e1d2; }
goto P_0c04e1cc;
P_0c04e1cc: /* original 9027, guest PC 0x0c04e1cc */
if(!s->budget--) { s->failed_pc=0x0c04e1ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e21eu,2);
goto P_0c04e1ce;
P_0c04e1ce: /* original a059, guest PC 0x0c04e1ce */
if(!s->budget--) { s->failed_pc=0x0c04e1ceu; return 0; }
goto P_0c04e284;
P_0c04e1d0: /* original 0009, guest PC 0x0c04e1d0 */
if(!s->budget--) { s->failed_pc=0x0c04e1d0u; return 0; }
goto P_0c04e1d2;
P_0c04e1d2: /* original d31d, guest PC 0x0c04e1d2 */
if(!s->budget--) { s->failed_pc=0x0c04e1d2u; return 0; }
r[3]=read(ram,0x0c04e248u,4);
goto P_0c04e1d4;
P_0c04e1d4: /* original 430b, guest PC 0x0c04e1d4 */
if(!s->budget--) { s->failed_pc=0x0c04e1d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e1d8u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e1d8u) { target=s->pc; goto dispatch; }
goto P_0c04e1d8;
P_0c04e1d6: /* original 54ea, guest PC 0x0c04e1d6 */
if(!s->budget--) { s->failed_pc=0x0c04e1d6u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e1d8;
P_0c04e1d8: /* original 4011, guest PC 0x0c04e1d8 */
if(!s->budget--) { s->failed_pc=0x0c04e1d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e1da;
P_0c04e1da: /* original 8902, guest PC 0x0c04e1da */
if(!s->budget--) { s->failed_pc=0x0c04e1dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e1e2; }
goto P_0c04e1dc;
P_0c04e1dc: /* original 9020, guest PC 0x0c04e1dc */
if(!s->budget--) { s->failed_pc=0x0c04e1dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e220u,2);
goto P_0c04e1de;
P_0c04e1de: /* original a051, guest PC 0x0c04e1de */
if(!s->budget--) { s->failed_pc=0x0c04e1deu; return 0; }
goto P_0c04e284;
P_0c04e1e0: /* original 0009, guest PC 0x0c04e1e0 */
if(!s->budget--) { s->failed_pc=0x0c04e1e0u; return 0; }
goto P_0c04e1e2;
P_0c04e1e2: /* original 5dec, guest PC 0x0c04e1e2 */
if(!s->budget--) { s->failed_pc=0x0c04e1e2u; return 0; }
r[13]=read(ram,r[14]+48,4);
goto P_0c04e1e4;
P_0c04e1e4: /* original d319, guest PC 0x0c04e1e4 */
if(!s->budget--) { s->failed_pc=0x0c04e1e4u; return 0; }
r[3]=read(ram,0x0c04e24cu,4);
goto P_0c04e1e6;
P_0c04e1e6: /* original 5cea, guest PC 0x0c04e1e6 */
if(!s->budget--) { s->failed_pc=0x0c04e1e6u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c04e1e8;
P_0c04e1e8: /* original 65d3, guest PC 0x0c04e1e8 */
if(!s->budget--) { s->failed_pc=0x0c04e1e8u; return 0; }
r[5]=r[13];
goto P_0c04e1ea;
P_0c04e1ea: /* original 430b, guest PC 0x0c04e1ea */
if(!s->budget--) { s->failed_pc=0x0c04e1eau; return 0; }
target=r[3];
r[16]=code_base|0x0c04e1eeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e1eeu) { target=s->pc; goto dispatch; }
goto P_0c04e1ee;
P_0c04e1ec: /* original 64c3, guest PC 0x0c04e1ec */
if(!s->budget--) { s->failed_pc=0x0c04e1ecu; return 0; }
r[4]=r[12];
goto P_0c04e1ee;
P_0c04e1ee: /* original d218, guest PC 0x0c04e1ee */
if(!s->budget--) { s->failed_pc=0x0c04e1eeu; return 0; }
r[2]=read(ram,0x0c04e250u,4);
goto P_0c04e1f0;
P_0c04e1f0: /* original 600d, guest PC 0x0c04e1f0 */
if(!s->budget--) { s->failed_pc=0x0c04e1f0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04e1f2;
P_0c04e1f2: /* original 3020, guest PC 0x0c04e1f2 */
if(!s->budget--) { s->failed_pc=0x0c04e1f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04e1f4;
P_0c04e1f4: /* original 8b05, guest PC 0x0c04e1f4 */
if(!s->budget--) { s->failed_pc=0x0c04e1f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e202; }
goto P_0c04e1f6;
P_0c04e1f6: /* original 53f1, guest PC 0x0c04e1f6 */
if(!s->budget--) { s->failed_pc=0x0c04e1f6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04e1f8;
P_0c04e1f8: /* original 50ec, guest PC 0x0c04e1f8 */
if(!s->budget--) { s->failed_pc=0x0c04e1f8u; return 0; }
r[0]=read(ram,r[14]+48,4);
goto P_0c04e1fa;
P_0c04e1fa: /* original 5237, guest PC 0x0c04e1fa */
if(!s->budget--) { s->failed_pc=0x0c04e1fau; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c04e1fc;
P_0c04e1fc: /* original 512e, guest PC 0x0c04e1fc */
if(!s->budget--) { s->failed_pc=0x0c04e1fcu; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c04e1fe;
P_0c04e1fe: /* original 3013, guest PC 0x0c04e1fe */
if(!s->budget--) { s->failed_pc=0x0c04e1feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c04e200;
P_0c04e200: /* original 8b02, guest PC 0x0c04e200 */
if(!s->budget--) { s->failed_pc=0x0c04e200u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e208; }
goto P_0c04e202;
P_0c04e202: /* original 900e, guest PC 0x0c04e202 */
if(!s->budget--) { s->failed_pc=0x0c04e202u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e222u,2);
goto P_0c04e204;
P_0c04e204: /* original a03e, guest PC 0x0c04e204 */
if(!s->budget--) { s->failed_pc=0x0c04e204u; return 0; }
goto P_0c04e284;
P_0c04e206: /* original 0009, guest PC 0x0c04e206 */
if(!s->budget--) { s->failed_pc=0x0c04e206u; return 0; }
goto P_0c04e208;
P_0c04e208: /* original d312, guest PC 0x0c04e208 */
if(!s->budget--) { s->failed_pc=0x0c04e208u; return 0; }
r[3]=read(ram,0x0c04e254u,4);
goto P_0c04e20a;
P_0c04e20a: /* original 65d3, guest PC 0x0c04e20a */
if(!s->budget--) { s->failed_pc=0x0c04e20au; return 0; }
r[5]=r[13];
goto P_0c04e20c;
P_0c04e20c: /* original 66f2, guest PC 0x0c04e20c */
if(!s->budget--) { s->failed_pc=0x0c04e20cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04e20e;
P_0c04e20e: /* original 430b, guest PC 0x0c04e20e */
if(!s->budget--) { s->failed_pc=0x0c04e20eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e212u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e212u) { target=s->pc; goto dispatch; }
goto P_0c04e212;
P_0c04e210: /* original 64c3, guest PC 0x0c04e210 */
if(!s->budget--) { s->failed_pc=0x0c04e210u; return 0; }
r[4]=r[12];
goto P_0c04e212;
P_0c04e212: /* original 6403, guest PC 0x0c04e212 */
if(!s->budget--) { s->failed_pc=0x0c04e212u; return 0; }
r[4]=r[0];
goto P_0c04e214;
P_0c04e214: /* original 4411, guest PC 0x0c04e214 */
if(!s->budget--) { s->failed_pc=0x0c04e214u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04e216;
P_0c04e216: /* original 891f, guest PC 0x0c04e216 */
if(!s->budget--) { s->failed_pc=0x0c04e216u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e258; }
goto P_0c04e218;
P_0c04e218: /* original a034, guest PC 0x0c04e218 */
if(!s->budget--) { s->failed_pc=0x0c04e218u; return 0; }
r[0]=r[4];
goto P_0c04e284;
P_0c04e21a: /* original 6043, guest PC 0x0c04e21a */
if(!s->budget--) { s->failed_pc=0x0c04e21au; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04e21cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e21cu; return 0; } return 1;
P_0c04e258: /* original d33c, guest PC 0x0c04e258 */
if(!s->budget--) { s->failed_pc=0x0c04e258u; return 0; }
r[3]=read(ram,0x0c04e34cu,4);
goto P_0c04e25a;
P_0c04e25a: /* original 65d3, guest PC 0x0c04e25a */
if(!s->budget--) { s->failed_pc=0x0c04e25au; return 0; }
r[5]=r[13];
goto P_0c04e25c;
P_0c04e25c: /* original d63a, guest PC 0x0c04e25c */
if(!s->budget--) { s->failed_pc=0x0c04e25cu; return 0; }
r[6]=read(ram,0x0c04e348u,4);
goto P_0c04e25e;
P_0c04e25e: /* original 430b, guest PC 0x0c04e25e */
if(!s->budget--) { s->failed_pc=0x0c04e25eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e262u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e262u) { target=s->pc; goto dispatch; }
goto P_0c04e262;
P_0c04e260: /* original 64c3, guest PC 0x0c04e260 */
if(!s->budget--) { s->failed_pc=0x0c04e260u; return 0; }
r[4]=r[12];
goto P_0c04e262;
P_0c04e262: /* original 53ee, guest PC 0x0c04e262 */
if(!s->budget--) { s->failed_pc=0x0c04e262u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c04e264;
P_0c04e264: /* original d23a, guest PC 0x0c04e264 */
if(!s->budget--) { s->failed_pc=0x0c04e264u; return 0; }
r[2]=read(ram,0x0c04e350u,4);
goto P_0c04e266;
P_0c04e266: /* original 3320, guest PC 0x0c04e266 */
if(!s->budget--) { s->failed_pc=0x0c04e266u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c04e268;
P_0c04e268: /* original 8f02, guest PC 0x0c04e268 */
if(!s->budget--) { s->failed_pc=0x0c04e268u; return 0; }
cond=r[17]&1u;
r[11]=(uint32_t)(int32_t)(int16_t)r[13];
if(!cond) { goto P_0c04e270; }
goto P_0c04e26c;
P_0c04e26a: /* original 6bdf, guest PC 0x0c04e26a */
if(!s->budget--) { s->failed_pc=0x0c04e26au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04e26c;
P_0c04e26c: /* original a005, guest PC 0x0c04e26c */
if(!s->budget--) { s->failed_pc=0x0c04e26cu; return 0; }
write(ram,r[14]+56,r[11],4);
goto P_0c04e27a;
P_0c04e26e: /* original 1ebe, guest PC 0x0c04e26e */
if(!s->budget--) { s->failed_pc=0x0c04e26eu; return 0; }
write(ram,r[14]+56,r[11],4);
goto P_0c04e270;
P_0c04e270: /* original d136, guest PC 0x0c04e270 */
if(!s->budget--) { s->failed_pc=0x0c04e270u; return 0; }
r[1]=read(ram,0x0c04e34cu,4);
goto P_0c04e272;
P_0c04e272: /* original 66d3, guest PC 0x0c04e272 */
if(!s->budget--) { s->failed_pc=0x0c04e272u; return 0; }
r[6]=r[13];
goto P_0c04e274;
P_0c04e274: /* original 55ef, guest PC 0x0c04e274 */
if(!s->budget--) { s->failed_pc=0x0c04e274u; return 0; }
r[5]=read(ram,r[14]+60,4);
goto P_0c04e276;
P_0c04e276: /* original 410b, guest PC 0x0c04e276 */
if(!s->budget--) { s->failed_pc=0x0c04e276u; return 0; }
target=r[1];
r[16]=code_base|0x0c04e27au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e27au) { target=s->pc; goto dispatch; }
goto P_0c04e27a;
P_0c04e278: /* original 64c3, guest PC 0x0c04e278 */
if(!s->budget--) { s->failed_pc=0x0c04e278u; return 0; }
r[4]=r[12];
goto P_0c04e27a;
P_0c04e27a: /* original e000, guest PC 0x0c04e27a */
if(!s->budget--) { s->failed_pc=0x0c04e27au; return 0; }
r[0]=0x00000000u;
goto P_0c04e27c;
P_0c04e27c: /* original 1ebf, guest PC 0x0c04e27c */
if(!s->budget--) { s->failed_pc=0x0c04e27cu; return 0; }
write(ram,r[14]+60,r[11],4);
goto P_0c04e27e;
P_0c04e27e: /* original 53ec, guest PC 0x0c04e27e */
if(!s->budget--) { s->failed_pc=0x0c04e27eu; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c04e280;
P_0c04e280: /* original 7301, guest PC 0x0c04e280 */
if(!s->budget--) { s->failed_pc=0x0c04e280u; return 0; }
r[3]+=0x00000001u;
goto P_0c04e282;
P_0c04e282: /* original 1e3c, guest PC 0x0c04e282 */
if(!s->budget--) { s->failed_pc=0x0c04e282u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c04e284;
P_0c04e284: /* original 7f08, guest PC 0x0c04e284 */
if(!s->budget--) { s->failed_pc=0x0c04e284u; return 0; }
r[15]+=0x00000008u;
goto P_0c04e286;
P_0c04e286: /* original 4f16, guest PC 0x0c04e286 */
if(!s->budget--) { s->failed_pc=0x0c04e286u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e288;
P_0c04e288: /* original 4f26, guest PC 0x0c04e288 */
if(!s->budget--) { s->failed_pc=0x0c04e288u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e28a;
P_0c04e28a: /* original 6bf6, guest PC 0x0c04e28a */
if(!s->budget--) { s->failed_pc=0x0c04e28au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e28c;
P_0c04e28c: /* original 6cf6, guest PC 0x0c04e28c */
if(!s->budget--) { s->failed_pc=0x0c04e28cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e28e;
P_0c04e28e: /* original 6df6, guest PC 0x0c04e28e */
if(!s->budget--) { s->failed_pc=0x0c04e28eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e290;
P_0c04e290: /* original 000b, guest PC 0x0c04e290 */
if(!s->budget--) { s->failed_pc=0x0c04e290u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e292: /* original 6ef6, guest PC 0x0c04e292 */
if(!s->budget--) { s->failed_pc=0x0c04e292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e294;
P_0c04e294: /* original 2fe6, guest PC 0x0c04e294 */
if(!s->budget--) { s->failed_pc=0x0c04e294u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e296;
P_0c04e296: /* original 6e43, guest PC 0x0c04e296 */
if(!s->budget--) { s->failed_pc=0x0c04e296u; return 0; }
r[14]=r[4];
goto P_0c04e298;
P_0c04e298: /* original 2fd6, guest PC 0x0c04e298 */
if(!s->budget--) { s->failed_pc=0x0c04e298u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e29a;
P_0c04e29a: /* original 2ee8, guest PC 0x0c04e29a */
if(!s->budget--) { s->failed_pc=0x0c04e29au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04e29c;
P_0c04e29c: /* original 2fc6, guest PC 0x0c04e29c */
if(!s->budget--) { s->failed_pc=0x0c04e29cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e29e;
P_0c04e29e: /* original 2fb6, guest PC 0x0c04e29e */
if(!s->budget--) { s->failed_pc=0x0c04e29eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e2a0;
P_0c04e2a0: /* original 2fa6, guest PC 0x0c04e2a0 */
if(!s->budget--) { s->failed_pc=0x0c04e2a0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e2a2;
P_0c04e2a2: /* original 4f22, guest PC 0x0c04e2a2 */
if(!s->budget--) { s->failed_pc=0x0c04e2a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e2a4;
P_0c04e2a4: /* original 4f12, guest PC 0x0c04e2a4 */
if(!s->budget--) { s->failed_pc=0x0c04e2a4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e2a6;
P_0c04e2a6: /* original 8f03, guest PC 0x0c04e2a6 */
if(!s->budget--) { s->failed_pc=0x0c04e2a6u; return 0; }
cond=r[17]&1u;
r[11]=r[6];
if(!cond) { goto P_0c04e2b0; }
goto P_0c04e2aa;
P_0c04e2a8: /* original 6b63, guest PC 0x0c04e2a8 */
if(!s->budget--) { s->failed_pc=0x0c04e2a8u; return 0; }
r[11]=r[6];
goto P_0c04e2aa;
P_0c04e2aa: /* original 9048, guest PC 0x0c04e2aa */
if(!s->budget--) { s->failed_pc=0x0c04e2aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e33eu,2);
goto P_0c04e2ac;
P_0c04e2ac: /* original a028, guest PC 0x0c04e2ac */
if(!s->budget--) { s->failed_pc=0x0c04e2acu; return 0; }
goto P_0c04e300;
P_0c04e2ae: /* original 0009, guest PC 0x0c04e2ae */
if(!s->budget--) { s->failed_pc=0x0c04e2aeu; return 0; }
goto P_0c04e2b0;
P_0c04e2b0: /* original 9346, guest PC 0x0c04e2b0 */
if(!s->budget--) { s->failed_pc=0x0c04e2b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e340u,2);
goto P_0c04e2b2;
P_0c04e2b2: /* original 52ea, guest PC 0x0c04e2b2 */
if(!s->budget--) { s->failed_pc=0x0c04e2b2u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04e2b4;
P_0c04e2b4: /* original d427, guest PC 0x0c04e2b4 */
if(!s->budget--) { s->failed_pc=0x0c04e2b4u; return 0; }
r[4]=read(ram,0x0c04e354u,4);
goto P_0c04e2b6;
P_0c04e2b6: /* original 223f, guest PC 0x0c04e2b6 */
if(!s->budget--) { s->failed_pc=0x0c04e2b6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[3]);
goto P_0c04e2b8;
P_0c04e2b8: /* original 021a, guest PC 0x0c04e2b8 */
if(!s->budget--) { s->failed_pc=0x0c04e2b8u; return 0; }
r[2]=r[19];
goto P_0c04e2ba;
P_0c04e2ba: /* original 622f, guest PC 0x0c04e2ba */
if(!s->budget--) { s->failed_pc=0x0c04e2bau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e2bc;
P_0c04e2bc: /* original 324c, guest PC 0x0c04e2bc */
if(!s->budget--) { s->failed_pc=0x0c04e2bcu; return 0; }
r[2]+=r[4];
goto P_0c04e2be;
P_0c04e2be: /* original 8422, guest PC 0x0c04e2be */
if(!s->budget--) { s->failed_pc=0x0c04e2beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04e2c0;
P_0c04e2c0: /* original 2008, guest PC 0x0c04e2c0 */
if(!s->budget--) { s->failed_pc=0x0c04e2c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e2c2;
P_0c04e2c2: /* original 8b02, guest PC 0x0c04e2c2 */
if(!s->budget--) { s->failed_pc=0x0c04e2c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e2ca; }
goto P_0c04e2c4;
P_0c04e2c4: /* original 903d, guest PC 0x0c04e2c4 */
if(!s->budget--) { s->failed_pc=0x0c04e2c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e342u,2);
goto P_0c04e2c6;
P_0c04e2c6: /* original a01b, guest PC 0x0c04e2c6 */
if(!s->budget--) { s->failed_pc=0x0c04e2c6u; return 0; }
goto P_0c04e300;
P_0c04e2c8: /* original 0009, guest PC 0x0c04e2c8 */
if(!s->budget--) { s->failed_pc=0x0c04e2c8u; return 0; }
goto P_0c04e2ca;
P_0c04e2ca: /* original 9239, guest PC 0x0c04e2ca */
if(!s->budget--) { s->failed_pc=0x0c04e2cau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e340u,2);
goto P_0c04e2cc;
P_0c04e2cc: /* original 4b15, guest PC 0x0c04e2cc */
if(!s->budget--) { s->failed_pc=0x0c04e2ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c04e2ce;
P_0c04e2ce: /* original 53ea, guest PC 0x0c04e2ce */
if(!s->budget--) { s->failed_pc=0x0c04e2ceu; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04e2d0;
P_0c04e2d0: /* original 6d53, guest PC 0x0c04e2d0 */
if(!s->budget--) { s->failed_pc=0x0c04e2d0u; return 0; }
r[13]=r[5];
goto P_0c04e2d2;
P_0c04e2d2: /* original 232f, guest PC 0x0c04e2d2 */
if(!s->budget--) { s->failed_pc=0x0c04e2d2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04e2d4;
P_0c04e2d4: /* original 031a, guest PC 0x0c04e2d4 */
if(!s->budget--) { s->failed_pc=0x0c04e2d4u; return 0; }
r[3]=r[19];
goto P_0c04e2d6;
P_0c04e2d6: /* original 633f, guest PC 0x0c04e2d6 */
if(!s->budget--) { s->failed_pc=0x0c04e2d6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04e2d8;
P_0c04e2d8: /* original 343c, guest PC 0x0c04e2d8 */
if(!s->budget--) { s->failed_pc=0x0c04e2d8u; return 0; }
r[4]+=r[3];
goto P_0c04e2da;
P_0c04e2da: /* original e301, guest PC 0x0c04e2da */
if(!s->budget--) { s->failed_pc=0x0c04e2dau; return 0; }
r[3]=0x00000001u;
goto P_0c04e2dc;
P_0c04e2dc: /* original 143c, guest PC 0x0c04e2dc */
if(!s->budget--) { s->failed_pc=0x0c04e2dcu; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04e2de;
P_0c04e2de: /* original 14bd, guest PC 0x0c04e2de */
if(!s->budget--) { s->failed_pc=0x0c04e2deu; return 0; }
write(ram,r[4]+52,r[11],4);
goto P_0c04e2e0;
P_0c04e2e0: /* original 9a30, guest PC 0x0c04e2e0 */
if(!s->budget--) { s->failed_pc=0x0c04e2e0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e344u,2);
goto P_0c04e2e2;
P_0c04e2e2: /* original 8f0c, guest PC 0x0c04e2e2 */
if(!s->budget--) { s->failed_pc=0x0c04e2e2u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c04e2fe; }
goto P_0c04e2e6;
P_0c04e2e4: /* original ec00, guest PC 0x0c04e2e4 */
if(!s->budget--) { s->failed_pc=0x0c04e2e4u; return 0; }
r[12]=0x00000000u;
goto P_0c04e2e6;
P_0c04e2e6: /* original 65d3, guest PC 0x0c04e2e6 */
if(!s->budget--) { s->failed_pc=0x0c04e2e6u; return 0; }
r[5]=r[13];
goto P_0c04e2e8;
P_0c04e2e8: /* original b012, guest PC 0x0c04e2e8 */
if(!s->budget--) { s->failed_pc=0x0c04e2e8u; return 0; }
target=code_base|0x0c04e310u; r[16]=code_base|0x0c04e2ecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e2ecu) { target=s->pc; goto dispatch; }
goto P_0c04e2ec;
P_0c04e2ea: /* original 64e3, guest PC 0x0c04e2ea */
if(!s->budget--) { s->failed_pc=0x0c04e2eau; return 0; }
r[4]=r[14];
goto P_0c04e2ec;
P_0c04e2ec: /* original 6403, guest PC 0x0c04e2ec */
if(!s->budget--) { s->failed_pc=0x0c04e2ecu; return 0; }
r[4]=r[0];
goto P_0c04e2ee;
P_0c04e2ee: /* original 4411, guest PC 0x0c04e2ee */
if(!s->budget--) { s->failed_pc=0x0c04e2eeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04e2f0;
P_0c04e2f0: /* original 8901, guest PC 0x0c04e2f0 */
if(!s->budget--) { s->failed_pc=0x0c04e2f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e2f6; }
goto P_0c04e2f2;
P_0c04e2f2: /* original a005, guest PC 0x0c04e2f2 */
if(!s->budget--) { s->failed_pc=0x0c04e2f2u; return 0; }
r[0]=r[4];
goto P_0c04e300;
P_0c04e2f4: /* original 6043, guest PC 0x0c04e2f4 */
if(!s->budget--) { s->failed_pc=0x0c04e2f4u; return 0; }
r[0]=r[4];
goto P_0c04e2f6;
P_0c04e2f6: /* original 7c01, guest PC 0x0c04e2f6 */
if(!s->budget--) { s->failed_pc=0x0c04e2f6u; return 0; }
r[12]+=0x00000001u;
goto P_0c04e2f8;
P_0c04e2f8: /* original 3cb3, guest PC 0x0c04e2f8 */
if(!s->budget--) { s->failed_pc=0x0c04e2f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c04e2fa;
P_0c04e2fa: /* original 8ff4, guest PC 0x0c04e2fa */
if(!s->budget--) { s->failed_pc=0x0c04e2fau; return 0; }
cond=r[17]&1u;
r[13]+=r[10];
if(!cond) { goto P_0c04e2e6; }
goto P_0c04e2fe;
P_0c04e2fc: /* original 3dac, guest PC 0x0c04e2fc */
if(!s->budget--) { s->failed_pc=0x0c04e2fcu; return 0; }
r[13]+=r[10];
goto P_0c04e2fe;
P_0c04e2fe: /* original e000, guest PC 0x0c04e2fe */
if(!s->budget--) { s->failed_pc=0x0c04e2feu; return 0; }
r[0]=0x00000000u;
goto P_0c04e300;
P_0c04e300: /* original 4f16, guest PC 0x0c04e300 */
if(!s->budget--) { s->failed_pc=0x0c04e300u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e302;
P_0c04e302: /* original 4f26, guest PC 0x0c04e302 */
if(!s->budget--) { s->failed_pc=0x0c04e302u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e304;
P_0c04e304: /* original 6af6, guest PC 0x0c04e304 */
if(!s->budget--) { s->failed_pc=0x0c04e304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e306;
P_0c04e306: /* original 6bf6, guest PC 0x0c04e306 */
if(!s->budget--) { s->failed_pc=0x0c04e306u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e308;
P_0c04e308: /* original 6cf6, guest PC 0x0c04e308 */
if(!s->budget--) { s->failed_pc=0x0c04e308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e30a;
P_0c04e30a: /* original 6df6, guest PC 0x0c04e30a */
if(!s->budget--) { s->failed_pc=0x0c04e30au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e30c;
P_0c04e30c: /* original 000b, guest PC 0x0c04e30c */
if(!s->budget--) { s->failed_pc=0x0c04e30cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e30e: /* original 6ef6, guest PC 0x0c04e30e */
if(!s->budget--) { s->failed_pc=0x0c04e30eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e310;
P_0c04e310: /* original 2fe6, guest PC 0x0c04e310 */
if(!s->budget--) { s->failed_pc=0x0c04e310u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e312;
P_0c04e312: /* original 6e43, guest PC 0x0c04e312 */
if(!s->budget--) { s->failed_pc=0x0c04e312u; return 0; }
r[14]=r[4];
goto P_0c04e314;
P_0c04e314: /* original 2fd6, guest PC 0x0c04e314 */
if(!s->budget--) { s->failed_pc=0x0c04e314u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e316;
P_0c04e316: /* original 2fc6, guest PC 0x0c04e316 */
if(!s->budget--) { s->failed_pc=0x0c04e316u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e318;
P_0c04e318: /* original 4f22, guest PC 0x0c04e318 */
if(!s->budget--) { s->failed_pc=0x0c04e318u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e31a;
P_0c04e31a: /* original 4f12, guest PC 0x0c04e31a */
if(!s->budget--) { s->failed_pc=0x0c04e31au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e31c;
P_0c04e31c: /* original 7ffc, guest PC 0x0c04e31c */
if(!s->budget--) { s->failed_pc=0x0c04e31cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e31e;
P_0c04e31e: /* original 2f52, guest PC 0x0c04e31e */
if(!s->budget--) { s->failed_pc=0x0c04e31eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04e320;
P_0c04e320: /* original d30d, guest PC 0x0c04e320 */
if(!s->budget--) { s->failed_pc=0x0c04e320u; return 0; }
r[3]=read(ram,0x0c04e358u,4);
goto P_0c04e322;
P_0c04e322: /* original d20e, guest PC 0x0c04e322 */
if(!s->budget--) { s->failed_pc=0x0c04e322u; return 0; }
r[2]=read(ram,0x0c04e35cu,4);
goto P_0c04e324;
P_0c04e324: /* original 420b, guest PC 0x0c04e324 */
if(!s->budget--) { s->failed_pc=0x0c04e324u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e328u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e328u) { target=s->pc; goto dispatch; }
goto P_0c04e328;
P_0c04e326: /* original 2f36, guest PC 0x0c04e326 */
if(!s->budget--) { s->failed_pc=0x0c04e326u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e328;
P_0c04e328: /* original d30d, guest PC 0x0c04e328 */
if(!s->budget--) { s->failed_pc=0x0c04e328u; return 0; }
r[3]=read(ram,0x0c04e360u,4);
goto P_0c04e32a;
P_0c04e32a: /* original 7f04, guest PC 0x0c04e32a */
if(!s->budget--) { s->failed_pc=0x0c04e32au; return 0; }
r[15]+=0x00000004u;
goto P_0c04e32c;
P_0c04e32c: /* original 430b, guest PC 0x0c04e32c */
if(!s->budget--) { s->failed_pc=0x0c04e32cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e330u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e330u) { target=s->pc; goto dispatch; }
goto P_0c04e330;
P_0c04e32e: /* original 54ea, guest PC 0x0c04e32e */
if(!s->budget--) { s->failed_pc=0x0c04e32eu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e330;
P_0c04e330: /* original 2008, guest PC 0x0c04e330 */
if(!s->budget--) { s->failed_pc=0x0c04e330u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e332;
P_0c04e332: /* original 8b19, guest PC 0x0c04e332 */
if(!s->budget--) { s->failed_pc=0x0c04e332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e368; }
goto P_0c04e334;
P_0c04e334: /* original d30b, guest PC 0x0c04e334 */
if(!s->budget--) { s->failed_pc=0x0c04e334u; return 0; }
r[3]=read(ram,0x0c04e364u,4);
goto P_0c04e336;
P_0c04e336: /* original 430b, guest PC 0x0c04e336 */
if(!s->budget--) { s->failed_pc=0x0c04e336u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e33au;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e33au) { target=s->pc; goto dispatch; }
goto P_0c04e33a;
P_0c04e338: /* original 54ea, guest PC 0x0c04e338 */
if(!s->budget--) { s->failed_pc=0x0c04e338u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e33a;
P_0c04e33a: /* original a023, guest PC 0x0c04e33a */
if(!s->budget--) { s->failed_pc=0x0c04e33au; return 0; }
goto P_0c04e384;
P_0c04e33c: /* original 0009, guest PC 0x0c04e33c */
if(!s->budget--) { s->failed_pc=0x0c04e33cu; return 0; }
if(!vf3_matrix_family(0x0c04e33eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e33eu; return 0; } return 1;
P_0c04e368: /* original d23b, guest PC 0x0c04e368 */
if(!s->budget--) { s->failed_pc=0x0c04e368u; return 0; }
r[2]=read(ram,0x0c04e458u,4);
goto P_0c04e36a;
P_0c04e36a: /* original 420b, guest PC 0x0c04e36a */
if(!s->budget--) { s->failed_pc=0x0c04e36au; return 0; }
target=r[2];
r[16]=code_base|0x0c04e36eu;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e36eu) { target=s->pc; goto dispatch; }
goto P_0c04e36e;
P_0c04e36c: /* original 54ea, guest PC 0x0c04e36c */
if(!s->budget--) { s->failed_pc=0x0c04e36cu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e36e;
P_0c04e36e: /* original 2008, guest PC 0x0c04e36e */
if(!s->budget--) { s->failed_pc=0x0c04e36eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e370;
P_0c04e370: /* original 8908, guest PC 0x0c04e370 */
if(!s->budget--) { s->failed_pc=0x0c04e370u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e384; }
goto P_0c04e372;
P_0c04e372: /* original 926c, guest PC 0x0c04e372 */
if(!s->budget--) { s->failed_pc=0x0c04e372u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e44eu,2);
goto P_0c04e374;
P_0c04e374: /* original 53ea, guest PC 0x0c04e374 */
if(!s->budget--) { s->failed_pc=0x0c04e374u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04e376;
P_0c04e376: /* original d039, guest PC 0x0c04e376 */
if(!s->budget--) { s->failed_pc=0x0c04e376u; return 0; }
r[0]=read(ram,0x0c04e45cu,4);
goto P_0c04e378;
P_0c04e378: /* original 232f, guest PC 0x0c04e378 */
if(!s->budget--) { s->failed_pc=0x0c04e378u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04e37a;
P_0c04e37a: /* original 031a, guest PC 0x0c04e37a */
if(!s->budget--) { s->failed_pc=0x0c04e37au; return 0; }
r[3]=r[19];
goto P_0c04e37c;
P_0c04e37c: /* original 633f, guest PC 0x0c04e37c */
if(!s->budget--) { s->failed_pc=0x0c04e37cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04e37e;
P_0c04e37e: /* original 013c, guest PC 0x0c04e37e */
if(!s->budget--) { s->failed_pc=0x0c04e37eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04e380;
P_0c04e380: /* original 2118, guest PC 0x0c04e380 */
if(!s->budget--) { s->failed_pc=0x0c04e380u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04e382;
P_0c04e382: /* original 8b02, guest PC 0x0c04e382 */
if(!s->budget--) { s->failed_pc=0x0c04e382u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e38a; }
goto P_0c04e384;
P_0c04e384: /* original 9064, guest PC 0x0c04e384 */
if(!s->budget--) { s->failed_pc=0x0c04e384u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e450u,2);
goto P_0c04e386;
P_0c04e386: /* original a03b, guest PC 0x0c04e386 */
if(!s->budget--) { s->failed_pc=0x0c04e386u; return 0; }
goto P_0c04e400;
P_0c04e388: /* original 0009, guest PC 0x0c04e388 */
if(!s->budget--) { s->failed_pc=0x0c04e388u; return 0; }
goto P_0c04e38a;
P_0c04e38a: /* original d335, guest PC 0x0c04e38a */
if(!s->budget--) { s->failed_pc=0x0c04e38au; return 0; }
r[3]=read(ram,0x0c04e460u,4);
goto P_0c04e38c;
P_0c04e38c: /* original 430b, guest PC 0x0c04e38c */
if(!s->budget--) { s->failed_pc=0x0c04e38cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e390u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e390u) { target=s->pc; goto dispatch; }
goto P_0c04e390;
P_0c04e38e: /* original 54ea, guest PC 0x0c04e38e */
if(!s->budget--) { s->failed_pc=0x0c04e38eu; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c04e390;
P_0c04e390: /* original 4011, guest PC 0x0c04e390 */
if(!s->budget--) { s->failed_pc=0x0c04e390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e392;
P_0c04e392: /* original 8902, guest PC 0x0c04e392 */
if(!s->budget--) { s->failed_pc=0x0c04e392u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e39a; }
goto P_0c04e394;
P_0c04e394: /* original 905d, guest PC 0x0c04e394 */
if(!s->budget--) { s->failed_pc=0x0c04e394u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e452u,2);
goto P_0c04e396;
P_0c04e396: /* original a033, guest PC 0x0c04e396 */
if(!s->budget--) { s->failed_pc=0x0c04e396u; return 0; }
goto P_0c04e400;
P_0c04e398: /* original 0009, guest PC 0x0c04e398 */
if(!s->budget--) { s->failed_pc=0x0c04e398u; return 0; }
goto P_0c04e39a;
P_0c04e39a: /* original e040, guest PC 0x0c04e39a */
if(!s->budget--) { s->failed_pc=0x0c04e39au; return 0; }
r[0]=0x00000040u;
goto P_0c04e39c;
P_0c04e39c: /* original d331, guest PC 0x0c04e39c */
if(!s->budget--) { s->failed_pc=0x0c04e39cu; return 0; }
r[3]=read(ram,0x0c04e464u,4);
goto P_0c04e39e;
P_0c04e39e: /* original 02ee, guest PC 0x0c04e39e */
if(!s->budget--) { s->failed_pc=0x0c04e39eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04e3a0;
P_0c04e3a0: /* original 3230, guest PC 0x0c04e3a0 */
if(!s->budget--) { s->failed_pc=0x0c04e3a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04e3a2;
P_0c04e3a2: /* original 8f06, guest PC 0x0c04e3a2 */
if(!s->budget--) { s->failed_pc=0x0c04e3a2u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[14]+40,4);
if(!cond) { goto P_0c04e3b2; }
goto P_0c04e3a6;
P_0c04e3a4: /* original 5dea, guest PC 0x0c04e3a4 */
if(!s->budget--) { s->failed_pc=0x0c04e3a4u; return 0; }
r[13]=read(ram,r[14]+40,4);
goto P_0c04e3a6;
P_0c04e3a6: /* original 52ed, guest PC 0x0c04e3a6 */
if(!s->budget--) { s->failed_pc=0x0c04e3a6u; return 0; }
r[2]=read(ram,r[14]+52,4);
goto P_0c04e3a8;
P_0c04e3a8: /* original 2228, guest PC 0x0c04e3a8 */
if(!s->budget--) { s->failed_pc=0x0c04e3a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04e3aa;
P_0c04e3aa: /* original 8905, guest PC 0x0c04e3aa */
if(!s->budget--) { s->failed_pc=0x0c04e3aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e3b8; }
goto P_0c04e3ac;
P_0c04e3ac: /* original d02e, guest PC 0x0c04e3ac */
if(!s->budget--) { s->failed_pc=0x0c04e3acu; return 0; }
r[0]=read(ram,0x0c04e468u,4);
goto P_0c04e3ae;
P_0c04e3ae: /* original a027, guest PC 0x0c04e3ae */
if(!s->budget--) { s->failed_pc=0x0c04e3aeu; return 0; }
goto P_0c04e400;
P_0c04e3b0: /* original 0009, guest PC 0x0c04e3b0 */
if(!s->budget--) { s->failed_pc=0x0c04e3b0u; return 0; }
goto P_0c04e3b2;
P_0c04e3b2: /* original 52ed, guest PC 0x0c04e3b2 */
if(!s->budget--) { s->failed_pc=0x0c04e3b2u; return 0; }
r[2]=read(ram,r[14]+52,4);
goto P_0c04e3b4;
P_0c04e3b4: /* original 2228, guest PC 0x0c04e3b4 */
if(!s->budget--) { s->failed_pc=0x0c04e3b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04e3b6;
P_0c04e3b6: /* original 8b01, guest PC 0x0c04e3b6 */
if(!s->budget--) { s->failed_pc=0x0c04e3b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e3bc; }
goto P_0c04e3b8;
P_0c04e3b8: /* original a022, guest PC 0x0c04e3b8 */
if(!s->budget--) { s->failed_pc=0x0c04e3b8u; return 0; }
r[0]=0x00000000u;
goto P_0c04e400;
P_0c04e3ba: /* original e000, guest PC 0x0c04e3ba */
if(!s->budget--) { s->failed_pc=0x0c04e3bau; return 0; }
r[0]=0x00000000u;
goto P_0c04e3bc;
P_0c04e3bc: /* original 02ee, guest PC 0x0c04e3bc */
if(!s->budget--) { s->failed_pc=0x0c04e3bcu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04e3be;
P_0c04e3be: /* original d32b, guest PC 0x0c04e3be */
if(!s->budget--) { s->failed_pc=0x0c04e3beu; return 0; }
r[3]=read(ram,0x0c04e46cu,4);
goto P_0c04e3c0;
P_0c04e3c0: /* original 3230, guest PC 0x0c04e3c0 */
if(!s->budget--) { s->failed_pc=0x0c04e3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04e3c2;
P_0c04e3c2: /* original 8903, guest PC 0x0c04e3c2 */
if(!s->budget--) { s->failed_pc=0x0c04e3c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e3cc; }
goto P_0c04e3c4;
P_0c04e3c4: /* original 02ee, guest PC 0x0c04e3c4 */
if(!s->budget--) { s->failed_pc=0x0c04e3c4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c04e3c6;
P_0c04e3c6: /* original d32a, guest PC 0x0c04e3c6 */
if(!s->budget--) { s->failed_pc=0x0c04e3c6u; return 0; }
r[3]=read(ram,0x0c04e470u,4);
goto P_0c04e3c8;
P_0c04e3c8: /* original 3230, guest PC 0x0c04e3c8 */
if(!s->budget--) { s->failed_pc=0x0c04e3c8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04e3ca;
P_0c04e3ca: /* original 8b02, guest PC 0x0c04e3ca */
if(!s->budget--) { s->failed_pc=0x0c04e3cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e3d2; }
goto P_0c04e3cc;
P_0c04e3cc: /* original 9042, guest PC 0x0c04e3cc */
if(!s->budget--) { s->failed_pc=0x0c04e3ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e454u,2);
goto P_0c04e3ce;
P_0c04e3ce: /* original a017, guest PC 0x0c04e3ce */
if(!s->budget--) { s->failed_pc=0x0c04e3ceu; return 0; }
goto P_0c04e400;
P_0c04e3d0: /* original 0009, guest PC 0x0c04e3d0 */
if(!s->budget--) { s->failed_pc=0x0c04e3d0u; return 0; }
goto P_0c04e3d2;
P_0c04e3d2: /* original 0cee, guest PC 0x0c04e3d2 */
if(!s->budget--) { s->failed_pc=0x0c04e3d2u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c04e3d4;
P_0c04e3d4: /* original d327, guest PC 0x0c04e3d4 */
if(!s->budget--) { s->failed_pc=0x0c04e3d4u; return 0; }
r[3]=read(ram,0x0c04e474u,4);
goto P_0c04e3d6;
P_0c04e3d6: /* original 66f2, guest PC 0x0c04e3d6 */
if(!s->budget--) { s->failed_pc=0x0c04e3d6u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04e3d8;
P_0c04e3d8: /* original 65c3, guest PC 0x0c04e3d8 */
if(!s->budget--) { s->failed_pc=0x0c04e3d8u; return 0; }
r[5]=r[12];
goto P_0c04e3da;
P_0c04e3da: /* original 430b, guest PC 0x0c04e3da */
if(!s->budget--) { s->failed_pc=0x0c04e3dau; return 0; }
target=r[3];
r[16]=code_base|0x0c04e3deu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e3deu) { target=s->pc; goto dispatch; }
goto P_0c04e3de;
P_0c04e3dc: /* original 64d3, guest PC 0x0c04e3dc */
if(!s->budget--) { s->failed_pc=0x0c04e3dcu; return 0; }
r[4]=r[13];
goto P_0c04e3de;
P_0c04e3de: /* original 6403, guest PC 0x0c04e3de */
if(!s->budget--) { s->failed_pc=0x0c04e3deu; return 0; }
r[4]=r[0];
goto P_0c04e3e0;
P_0c04e3e0: /* original 4411, guest PC 0x0c04e3e0 */
if(!s->budget--) { s->failed_pc=0x0c04e3e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04e3e2;
P_0c04e3e2: /* original 8901, guest PC 0x0c04e3e2 */
if(!s->budget--) { s->failed_pc=0x0c04e3e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e3e8; }
goto P_0c04e3e4;
P_0c04e3e4: /* original a00c, guest PC 0x0c04e3e4 */
if(!s->budget--) { s->failed_pc=0x0c04e3e4u; return 0; }
r[0]=r[4];
goto P_0c04e400;
P_0c04e3e6: /* original 6043, guest PC 0x0c04e3e6 */
if(!s->budget--) { s->failed_pc=0x0c04e3e6u; return 0; }
r[0]=r[4];
goto P_0c04e3e8;
P_0c04e3e8: /* original d323, guest PC 0x0c04e3e8 */
if(!s->budget--) { s->failed_pc=0x0c04e3e8u; return 0; }
r[3]=read(ram,0x0c04e478u,4);
goto P_0c04e3ea;
P_0c04e3ea: /* original 65c3, guest PC 0x0c04e3ea */
if(!s->budget--) { s->failed_pc=0x0c04e3eau; return 0; }
r[5]=r[12];
goto P_0c04e3ec;
P_0c04e3ec: /* original 430b, guest PC 0x0c04e3ec */
if(!s->budget--) { s->failed_pc=0x0c04e3ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e3f0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e3f0u) { target=s->pc; goto dispatch; }
goto P_0c04e3f0;
P_0c04e3ee: /* original 64d3, guest PC 0x0c04e3ee */
if(!s->budget--) { s->failed_pc=0x0c04e3eeu; return 0; }
r[4]=r[13];
goto P_0c04e3f0;
P_0c04e3f0: /* original e140, guest PC 0x0c04e3f0 */
if(!s->budget--) { s->failed_pc=0x0c04e3f0u; return 0; }
r[1]=0x00000040u;
goto P_0c04e3f2;
P_0c04e3f2: /* original 31ec, guest PC 0x0c04e3f2 */
if(!s->budget--) { s->failed_pc=0x0c04e3f2u; return 0; }
r[1]+=r[14];
goto P_0c04e3f4;
P_0c04e3f4: /* original 600d, guest PC 0x0c04e3f4 */
if(!s->budget--) { s->failed_pc=0x0c04e3f4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04e3f6;
P_0c04e3f6: /* original 2102, guest PC 0x0c04e3f6 */
if(!s->budget--) { s->failed_pc=0x0c04e3f6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c04e3f8;
P_0c04e3f8: /* original 53ed, guest PC 0x0c04e3f8 */
if(!s->budget--) { s->failed_pc=0x0c04e3f8u; return 0; }
r[3]=read(ram,r[14]+52,4);
goto P_0c04e3fa;
P_0c04e3fa: /* original 73ff, guest PC 0x0c04e3fa */
if(!s->budget--) { s->failed_pc=0x0c04e3fau; return 0; }
r[3]+=0xffffffffu;
goto P_0c04e3fc;
P_0c04e3fc: /* original 6033, guest PC 0x0c04e3fc */
if(!s->budget--) { s->failed_pc=0x0c04e3fcu; return 0; }
r[0]=r[3];
goto P_0c04e3fe;
P_0c04e3fe: /* original 1e3d, guest PC 0x0c04e3fe */
if(!s->budget--) { s->failed_pc=0x0c04e3feu; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c04e400;
P_0c04e400: /* original 7f04, guest PC 0x0c04e400 */
if(!s->budget--) { s->failed_pc=0x0c04e400u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e402;
P_0c04e402: /* original 4f16, guest PC 0x0c04e402 */
if(!s->budget--) { s->failed_pc=0x0c04e402u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e404;
P_0c04e404: /* original 4f26, guest PC 0x0c04e404 */
if(!s->budget--) { s->failed_pc=0x0c04e404u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e406;
P_0c04e406: /* original 6cf6, guest PC 0x0c04e406 */
if(!s->budget--) { s->failed_pc=0x0c04e406u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e408;
P_0c04e408: /* original 6df6, guest PC 0x0c04e408 */
if(!s->budget--) { s->failed_pc=0x0c04e408u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e40a;
P_0c04e40a: /* original 000b, guest PC 0x0c04e40a */
if(!s->budget--) { s->failed_pc=0x0c04e40au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e40c: /* original 6ef6, guest PC 0x0c04e40c */
if(!s->budget--) { s->failed_pc=0x0c04e40cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04e40eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e40eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
