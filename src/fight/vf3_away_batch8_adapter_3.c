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
int vf3_away_batch8_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05d1fcu: goto P_0c05d1fc;
case 0x0c05d1feu: goto P_0c05d1fe;
case 0x0c05d200u: goto P_0c05d200;
case 0x0c05d202u: goto P_0c05d202;
case 0x0c05d204u: goto P_0c05d204;
case 0x0c05d206u: goto P_0c05d206;
case 0x0c05d208u: goto P_0c05d208;
case 0x0c05d20au: goto P_0c05d20a;
case 0x0c05d20cu: goto P_0c05d20c;
case 0x0c05d20eu: goto P_0c05d20e;
case 0x0c05d210u: goto P_0c05d210;
case 0x0c05d212u: goto P_0c05d212;
case 0x0c05d214u: goto P_0c05d214;
case 0x0c05d216u: goto P_0c05d216;
case 0x0c05d218u: goto P_0c05d218;
case 0x0c05d21au: goto P_0c05d21a;
case 0x0c05d21cu: goto P_0c05d21c;
case 0x0c05d21eu: goto P_0c05d21e;
case 0x0c05d220u: goto P_0c05d220;
case 0x0c05d222u: goto P_0c05d222;
case 0x0c05d224u: goto P_0c05d224;
case 0x0c05d226u: goto P_0c05d226;
case 0x0c05d228u: goto P_0c05d228;
case 0x0c05d22au: goto P_0c05d22a;
case 0x0c05d22cu: goto P_0c05d22c;
case 0x0c05d22eu: goto P_0c05d22e;
case 0x0c05d230u: goto P_0c05d230;
case 0x0c05d232u: goto P_0c05d232;
case 0x0c05d234u: goto P_0c05d234;
case 0x0c05d236u: goto P_0c05d236;
case 0x0c05d238u: goto P_0c05d238;
case 0x0c05d23au: goto P_0c05d23a;
case 0x0c05d23cu: goto P_0c05d23c;
case 0x0c05d23eu: goto P_0c05d23e;
case 0x0c05d240u: goto P_0c05d240;
case 0x0c05d242u: goto P_0c05d242;
case 0x0c05d244u: goto P_0c05d244;
case 0x0c05d246u: goto P_0c05d246;
case 0x0c05d248u: goto P_0c05d248;
case 0x0c05d24au: goto P_0c05d24a;
case 0x0c05d24cu: goto P_0c05d24c;
case 0x0c05d24eu: goto P_0c05d24e;
case 0x0c05d250u: goto P_0c05d250;
case 0x0c05d252u: goto P_0c05d252;
case 0x0c05d254u: goto P_0c05d254;
case 0x0c05d256u: goto P_0c05d256;
case 0x0c05d258u: goto P_0c05d258;
case 0x0c05d25au: goto P_0c05d25a;
case 0x0c05d25cu: goto P_0c05d25c;
case 0x0c05d25eu: goto P_0c05d25e;
case 0x0c05d260u: goto P_0c05d260;
case 0x0c05d262u: goto P_0c05d262;
case 0x0c05d264u: goto P_0c05d264;
case 0x0c05d266u: goto P_0c05d266;
case 0x0c05d268u: goto P_0c05d268;
case 0x0c05d26au: goto P_0c05d26a;
case 0x0c05d26cu: goto P_0c05d26c;
case 0x0c05d26eu: goto P_0c05d26e;
case 0x0c05d270u: goto P_0c05d270;
case 0x0c05d272u: goto P_0c05d272;
case 0x0c05d274u: goto P_0c05d274;
case 0x0c05d276u: goto P_0c05d276;
case 0x0c05d278u: goto P_0c05d278;
case 0x0c05d27au: goto P_0c05d27a;
case 0x0c05d27cu: goto P_0c05d27c;
case 0x0c05d27eu: goto P_0c05d27e;
case 0x0c05d280u: goto P_0c05d280;
case 0x0c05d282u: goto P_0c05d282;
case 0x0c05d284u: goto P_0c05d284;
case 0x0c05d286u: goto P_0c05d286;
case 0x0c05d288u: goto P_0c05d288;
case 0x0c05d28au: goto P_0c05d28a;
case 0x0c05d28cu: goto P_0c05d28c;
case 0x0c05d28eu: goto P_0c05d28e;
case 0x0c05d290u: goto P_0c05d290;
case 0x0c05d292u: goto P_0c05d292;
case 0x0c05d294u: goto P_0c05d294;
case 0x0c05d296u: goto P_0c05d296;
case 0x0c05d298u: goto P_0c05d298;
case 0x0c05d29au: goto P_0c05d29a;
case 0x0c05d29cu: goto P_0c05d29c;
case 0x0c05d29eu: goto P_0c05d29e;
case 0x0c05d2a0u: goto P_0c05d2a0;
case 0x0c05d2a2u: goto P_0c05d2a2;
case 0x0c05d2a4u: goto P_0c05d2a4;
case 0x0c05d2a6u: goto P_0c05d2a6;
case 0x0c05d2a8u: goto P_0c05d2a8;
case 0x0c05d2aau: goto P_0c05d2aa;
case 0x0c05d2acu: goto P_0c05d2ac;
case 0x0c05d2aeu: goto P_0c05d2ae;
case 0x0c05d2b0u: goto P_0c05d2b0;
case 0x0c05d2b2u: goto P_0c05d2b2;
case 0x0c05d2b4u: goto P_0c05d2b4;
case 0x0c05d2b6u: goto P_0c05d2b6;
case 0x0c05d2b8u: goto P_0c05d2b8;
case 0x0c05d2bau: goto P_0c05d2ba;
case 0x0c05d2bcu: goto P_0c05d2bc;
case 0x0c05d2beu: goto P_0c05d2be;
case 0x0c05d2c0u: goto P_0c05d2c0;
case 0x0c05d2c2u: goto P_0c05d2c2;
case 0x0c05d2c4u: goto P_0c05d2c4;
case 0x0c05d2c6u: goto P_0c05d2c6;
case 0x0c05d2c8u: goto P_0c05d2c8;
case 0x0c05d2cau: goto P_0c05d2ca;
case 0x0c05d2ccu: goto P_0c05d2cc;
case 0x0c05d2ceu: goto P_0c05d2ce;
case 0x0c05d2d0u: goto P_0c05d2d0;
case 0x0c05d2d2u: goto P_0c05d2d2;
case 0x0c05d2d4u: goto P_0c05d2d4;
case 0x0c05d2d6u: goto P_0c05d2d6;
case 0x0c05d2d8u: goto P_0c05d2d8;
case 0x0c05d2dau: goto P_0c05d2da;
case 0x0c05d2dcu: goto P_0c05d2dc;
case 0x0c05d2deu: goto P_0c05d2de;
case 0x0c05d2e0u: goto P_0c05d2e0;
case 0x0c05d2e2u: goto P_0c05d2e2;
case 0x0c05d2e4u: goto P_0c05d2e4;
case 0x0c05d2e6u: goto P_0c05d2e6;
case 0x0c05d2e8u: goto P_0c05d2e8;
case 0x0c05d2eau: goto P_0c05d2ea;
case 0x0c05d2ecu: goto P_0c05d2ec;
case 0x0c05d2eeu: goto P_0c05d2ee;
case 0x0c05d2f0u: goto P_0c05d2f0;
case 0x0c05d2f2u: goto P_0c05d2f2;
case 0x0c05d2f4u: goto P_0c05d2f4;
case 0x0c05d2f6u: goto P_0c05d2f6;
case 0x0c05d2f8u: goto P_0c05d2f8;
case 0x0c05d2fau: goto P_0c05d2fa;
case 0x0c05d2fcu: goto P_0c05d2fc;
case 0x0c05d2feu: goto P_0c05d2fe;
case 0x0c05d300u: goto P_0c05d300;
case 0x0c05d302u: goto P_0c05d302;
case 0x0c05d304u: goto P_0c05d304;
case 0x0c05d306u: goto P_0c05d306;
case 0x0c05d308u: goto P_0c05d308;
case 0x0c05d30au: goto P_0c05d30a;
case 0x0c05d30cu: goto P_0c05d30c;
case 0x0c05d30eu: goto P_0c05d30e;
case 0x0c05d310u: goto P_0c05d310;
case 0x0c05d312u: goto P_0c05d312;
case 0x0c05d314u: goto P_0c05d314;
case 0x0c05d316u: goto P_0c05d316;
case 0x0c05d318u: goto P_0c05d318;
case 0x0c05d31au: goto P_0c05d31a;
case 0x0c05d31cu: goto P_0c05d31c;
case 0x0c05d31eu: goto P_0c05d31e;
case 0x0c05d320u: goto P_0c05d320;
case 0x0c05d322u: goto P_0c05d322;
case 0x0c05d324u: goto P_0c05d324;
case 0x0c05d326u: goto P_0c05d326;
case 0x0c05d328u: goto P_0c05d328;
case 0x0c05d32au: goto P_0c05d32a;
case 0x0c05d32cu: goto P_0c05d32c;
case 0x0c05d32eu: goto P_0c05d32e;
case 0x0c05d330u: goto P_0c05d330;
case 0x0c05d332u: goto P_0c05d332;
case 0x0c05d334u: goto P_0c05d334;
case 0x0c05d336u: goto P_0c05d336;
case 0x0c05d338u: goto P_0c05d338;
case 0x0c05d33au: goto P_0c05d33a;
case 0x0c05d33cu: goto P_0c05d33c;
case 0x0c05d33eu: goto P_0c05d33e;
case 0x0c05d340u: goto P_0c05d340;
case 0x0c05d342u: goto P_0c05d342;
case 0x0c05d344u: goto P_0c05d344;
case 0x0c05d346u: goto P_0c05d346;
case 0x0c05d348u: goto P_0c05d348;
case 0x0c05d34au: goto P_0c05d34a;
case 0x0c05d34cu: goto P_0c05d34c;
case 0x0c05d34eu: goto P_0c05d34e;
case 0x0c05d350u: goto P_0c05d350;
case 0x0c05d352u: goto P_0c05d352;
case 0x0c05d354u: goto P_0c05d354;
case 0x0c05d356u: goto P_0c05d356;
case 0x0c05d358u: goto P_0c05d358;
case 0x0c05d35au: goto P_0c05d35a;
case 0x0c05d35cu: goto P_0c05d35c;
case 0x0c05d35eu: goto P_0c05d35e;
case 0x0c05d360u: goto P_0c05d360;
case 0x0c05d362u: goto P_0c05d362;
case 0x0c05d364u: goto P_0c05d364;
case 0x0c05d366u: goto P_0c05d366;
case 0x0c05d368u: goto P_0c05d368;
case 0x0c05d36au: goto P_0c05d36a;
case 0x0c05d36cu: goto P_0c05d36c;
case 0x0c05d36eu: goto P_0c05d36e;
case 0x0c05d370u: goto P_0c05d370;
case 0x0c05d372u: goto P_0c05d372;
case 0x0c05d374u: goto P_0c05d374;
case 0x0c05d376u: goto P_0c05d376;
case 0x0c05d378u: goto P_0c05d378;
case 0x0c05d37au: goto P_0c05d37a;
case 0x0c05d37cu: goto P_0c05d37c;
case 0x0c05d37eu: goto P_0c05d37e;
case 0x0c05d380u: goto P_0c05d380;
case 0x0c05d382u: goto P_0c05d382;
case 0x0c05d384u: goto P_0c05d384;
case 0x0c05d386u: goto P_0c05d386;
case 0x0c05d388u: goto P_0c05d388;
case 0x0c05d38au: goto P_0c05d38a;
case 0x0c05d38cu: goto P_0c05d38c;
case 0x0c05d38eu: goto P_0c05d38e;
case 0x0c05d390u: goto P_0c05d390;
case 0x0c05d392u: goto P_0c05d392;
case 0x0c05d394u: goto P_0c05d394;
case 0x0c05d396u: goto P_0c05d396;
case 0x0c05d398u: goto P_0c05d398;
case 0x0c05d39au: goto P_0c05d39a;
case 0x0c05d39cu: goto P_0c05d39c;
case 0x0c05d39eu: goto P_0c05d39e;
case 0x0c05d3a0u: goto P_0c05d3a0;
case 0x0c05d3a2u: goto P_0c05d3a2;
case 0x0c05d3a4u: goto P_0c05d3a4;
case 0x0c05d3a6u: goto P_0c05d3a6;
case 0x0c05d3a8u: goto P_0c05d3a8;
case 0x0c05d3aau: goto P_0c05d3aa;
case 0x0c05d3acu: goto P_0c05d3ac;
case 0x0c05d3aeu: goto P_0c05d3ae;
case 0x0c05d3b0u: goto P_0c05d3b0;
case 0x0c05d3b2u: goto P_0c05d3b2;
case 0x0c05d3b4u: goto P_0c05d3b4;
case 0x0c05d3b6u: goto P_0c05d3b6;
case 0x0c05d3b8u: goto P_0c05d3b8;
case 0x0c05d3bau: goto P_0c05d3ba;
case 0x0c05d3bcu: goto P_0c05d3bc;
case 0x0c05d3beu: goto P_0c05d3be;
case 0x0c05d3c0u: goto P_0c05d3c0;
case 0x0c05d3c2u: goto P_0c05d3c2;
case 0x0c05d3c4u: goto P_0c05d3c4;
case 0x0c05d3c6u: goto P_0c05d3c6;
case 0x0c05d3c8u: goto P_0c05d3c8;
case 0x0c05d3cau: goto P_0c05d3ca;
case 0x0c05d3ccu: goto P_0c05d3cc;
case 0x0c05d3ceu: goto P_0c05d3ce;
case 0x0c05d3d0u: goto P_0c05d3d0;
case 0x0c05d3d2u: goto P_0c05d3d2;
case 0x0c05d3d4u: goto P_0c05d3d4;
case 0x0c05d3d6u: goto P_0c05d3d6;
case 0x0c05d3d8u: goto P_0c05d3d8;
case 0x0c05d3dau: goto P_0c05d3da;
case 0x0c05d3dcu: goto P_0c05d3dc;
case 0x0c05d3deu: goto P_0c05d3de;
case 0x0c05d3e0u: goto P_0c05d3e0;
case 0x0c05d3e2u: goto P_0c05d3e2;
case 0x0c05d3e4u: goto P_0c05d3e4;
case 0x0c05d3e6u: goto P_0c05d3e6;
case 0x0c05d3e8u: goto P_0c05d3e8;
case 0x0c05d3eau: goto P_0c05d3ea;
case 0x0c05d3ecu: goto P_0c05d3ec;
case 0x0c05d3eeu: goto P_0c05d3ee;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05d1fc: /* original 2fe6, guest PC 0x0c05d1fc */
if(!s->budget--) { s->failed_pc=0x0c05d1fcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d1fe;
P_0c05d1fe: /* original e005, guest PC 0x0c05d1fe */
if(!s->budget--) { s->failed_pc=0x0c05d1feu; return 0; }
r[0]=0x00000005u;
goto P_0c05d200;
P_0c05d200: /* original 2fd6, guest PC 0x0c05d200 */
if(!s->budget--) { s->failed_pc=0x0c05d200u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d202;
P_0c05d202: /* original ed00, guest PC 0x0c05d202 */
if(!s->budget--) { s->failed_pc=0x0c05d202u; return 0; }
r[13]=0x00000000u;
goto P_0c05d204;
P_0c05d204: /* original 2fc6, guest PC 0x0c05d204 */
if(!s->budget--) { s->failed_pc=0x0c05d204u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d206;
P_0c05d206: /* original 61d3, guest PC 0x0c05d206 */
if(!s->budget--) { s->failed_pc=0x0c05d206u; return 0; }
r[1]=r[13];
goto P_0c05d208;
P_0c05d208: /* original 2fa6, guest PC 0x0c05d208 */
if(!s->budget--) { s->failed_pc=0x0c05d208u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d20a;
P_0c05d20a: /* original ea00, guest PC 0x0c05d20a */
if(!s->budget--) { s->failed_pc=0x0c05d20au; return 0; }
r[10]=0x00000000u;
goto P_0c05d20c;
P_0c05d20c: /* original 2f86, guest PC 0x0c05d20c */
if(!s->budget--) { s->failed_pc=0x0c05d20cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d20e;
P_0c05d20e: /* original 7fec, guest PC 0x0c05d20e */
if(!s->budget--) { s->failed_pc=0x0c05d20eu; return 0; }
r[15]+=0xffffffecu;
goto P_0c05d210;
P_0c05d210: /* original 6ef3, guest PC 0x0c05d210 */
if(!s->budget--) { s->failed_pc=0x0c05d210u; return 0; }
r[14]=r[15];
goto P_0c05d212;
P_0c05d212: /* original 68e3, guest PC 0x0c05d212 */
if(!s->budget--) { s->failed_pc=0x0c05d212u; return 0; }
r[8]=r[14];
goto P_0c05d214;
P_0c05d214: /* original 6ce3, guest PC 0x0c05d214 */
if(!s->budget--) { s->failed_pc=0x0c05d214u; return 0; }
r[12]=r[14];
goto P_0c05d216;
P_0c05d216: /* original 7101, guest PC 0x0c05d216 */
if(!s->budget--) { s->failed_pc=0x0c05d216u; return 0; }
r[1]+=0x00000001u;
goto P_0c05d218;
P_0c05d218: /* original 2ca2, guest PC 0x0c05d218 */
if(!s->budget--) { s->failed_pc=0x0c05d218u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c05d21a;
P_0c05d21a: /* original 3102, guest PC 0x0c05d21a */
if(!s->budget--) { s->failed_pc=0x0c05d21au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[0])!=0);
goto P_0c05d21c;
P_0c05d21c: /* original 8ffb, guest PC 0x0c05d21c */
if(!s->budget--) { s->failed_pc=0x0c05d21cu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c05d216; }
goto P_0c05d220;
P_0c05d21e: /* original 7c04, guest PC 0x0c05d21e */
if(!s->budget--) { s->failed_pc=0x0c05d21eu; return 0; }
r[12]+=0x00000004u;
goto P_0c05d220;
P_0c05d220: /* original d273, guest PC 0x0c05d220 */
if(!s->budget--) { s->failed_pc=0x0c05d220u; return 0; }
r[2]=read(ram,0x0c05d3f0u,4);
goto P_0c05d222;
P_0c05d222: /* original 6022, guest PC 0x0c05d222 */
if(!s->budget--) { s->failed_pc=0x0c05d222u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d224;
P_0c05d224: /* original 8801, guest PC 0x0c05d224 */
if(!s->budget--) { s->failed_pc=0x0c05d224u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d226;
P_0c05d226: /* original 8f19, guest PC 0x0c05d226 */
if(!s->budget--) { s->failed_pc=0x0c05d226u; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c05d25c; }
goto P_0c05d22a;
P_0c05d228: /* original ec01, guest PC 0x0c05d228 */
if(!s->budget--) { s->failed_pc=0x0c05d228u; return 0; }
r[12]=0x00000001u;
goto P_0c05d22a;
P_0c05d22a: /* original d172, guest PC 0x0c05d22a */
if(!s->budget--) { s->failed_pc=0x0c05d22au; return 0; }
r[1]=read(ram,0x0c05d3f4u,4);
goto P_0c05d22c;
P_0c05d22c: /* original 6012, guest PC 0x0c05d22c */
if(!s->budget--) { s->failed_pc=0x0c05d22cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d22e;
P_0c05d22e: /* original 8820, guest PC 0x0c05d22e */
if(!s->budget--) { s->failed_pc=0x0c05d22eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05d230;
P_0c05d230: /* original 8b00, guest PC 0x0c05d230 */
if(!s->budget--) { s->failed_pc=0x0c05d230u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d234; }
goto P_0c05d232;
P_0c05d232: /* original 28c2, guest PC 0x0c05d232 */
if(!s->budget--) { s->failed_pc=0x0c05d232u; return 0; }
write(ram,r[8],r[12],4);
goto P_0c05d234;
P_0c05d234: /* original d26f, guest PC 0x0c05d234 */
if(!s->budget--) { s->failed_pc=0x0c05d234u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d236;
P_0c05d236: /* original 6022, guest PC 0x0c05d236 */
if(!s->budget--) { s->failed_pc=0x0c05d236u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d238;
P_0c05d238: /* original 8821, guest PC 0x0c05d238 */
if(!s->budget--) { s->failed_pc=0x0c05d238u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c05d23a;
P_0c05d23a: /* original 8b00, guest PC 0x0c05d23a */
if(!s->budget--) { s->failed_pc=0x0c05d23au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d23e; }
goto P_0c05d23c;
P_0c05d23c: /* original 1ec1, guest PC 0x0c05d23c */
if(!s->budget--) { s->failed_pc=0x0c05d23cu; return 0; }
write(ram,r[14]+4,r[12],4);
goto P_0c05d23e;
P_0c05d23e: /* original d26d, guest PC 0x0c05d23e */
if(!s->budget--) { s->failed_pc=0x0c05d23eu; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d240;
P_0c05d240: /* original 6022, guest PC 0x0c05d240 */
if(!s->budget--) { s->failed_pc=0x0c05d240u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d242;
P_0c05d242: /* original 8822, guest PC 0x0c05d242 */
if(!s->budget--) { s->failed_pc=0x0c05d242u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000022u)!=0);
goto P_0c05d244;
P_0c05d244: /* original 8b00, guest PC 0x0c05d244 */
if(!s->budget--) { s->failed_pc=0x0c05d244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d248; }
goto P_0c05d246;
P_0c05d246: /* original 1ec2, guest PC 0x0c05d246 */
if(!s->budget--) { s->failed_pc=0x0c05d246u; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c05d248;
P_0c05d248: /* original d26a, guest PC 0x0c05d248 */
if(!s->budget--) { s->failed_pc=0x0c05d248u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d24a;
P_0c05d24a: /* original 6022, guest PC 0x0c05d24a */
if(!s->budget--) { s->failed_pc=0x0c05d24au; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d24c;
P_0c05d24c: /* original 8823, guest PC 0x0c05d24c */
if(!s->budget--) { s->failed_pc=0x0c05d24cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000023u)!=0);
goto P_0c05d24e;
P_0c05d24e: /* original 8b00, guest PC 0x0c05d24e */
if(!s->budget--) { s->failed_pc=0x0c05d24eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d252; }
goto P_0c05d250;
P_0c05d250: /* original 1ec3, guest PC 0x0c05d250 */
if(!s->budget--) { s->failed_pc=0x0c05d250u; return 0; }
write(ram,r[14]+12,r[12],4);
goto P_0c05d252;
P_0c05d252: /* original d268, guest PC 0x0c05d252 */
if(!s->budget--) { s->failed_pc=0x0c05d252u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d254;
P_0c05d254: /* original 6022, guest PC 0x0c05d254 */
if(!s->budget--) { s->failed_pc=0x0c05d254u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d256;
P_0c05d256: /* original 8824, guest PC 0x0c05d256 */
if(!s->budget--) { s->failed_pc=0x0c05d256u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000024u)!=0);
goto P_0c05d258;
P_0c05d258: /* original 8b00, guest PC 0x0c05d258 */
if(!s->budget--) { s->failed_pc=0x0c05d258u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d25c; }
goto P_0c05d25a;
P_0c05d25a: /* original 1ec4, guest PC 0x0c05d25a */
if(!s->budget--) { s->failed_pc=0x0c05d25au; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c05d25c;
P_0c05d25c: /* original 6282, guest PC 0x0c05d25c */
if(!s->budget--) { s->failed_pc=0x0c05d25cu; return 0; }
tmp=read(ram,r[8],4);
r[2]=tmp;
goto P_0c05d25e;
P_0c05d25e: /* original 342c, guest PC 0x0c05d25e */
if(!s->budget--) { s->failed_pc=0x0c05d25eu; return 0; }
r[4]+=r[2];
goto P_0c05d260;
P_0c05d260: /* original 53e1, guest PC 0x0c05d260 */
if(!s->budget--) { s->failed_pc=0x0c05d260u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c05d262;
P_0c05d262: /* original 2448, guest PC 0x0c05d262 */
if(!s->budget--) { s->failed_pc=0x0c05d262u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05d264;
P_0c05d264: /* original 52e2, guest PC 0x0c05d264 */
if(!s->budget--) { s->failed_pc=0x0c05d264u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c05d266;
P_0c05d266: /* original 353c, guest PC 0x0c05d266 */
if(!s->budget--) { s->failed_pc=0x0c05d266u; return 0; }
r[5]+=r[3];
goto P_0c05d268;
P_0c05d268: /* original d163, guest PC 0x0c05d268 */
if(!s->budget--) { s->failed_pc=0x0c05d268u; return 0; }
r[1]=read(ram,0x0c05d3f8u,4);
goto P_0c05d26a;
P_0c05d26a: /* original 362c, guest PC 0x0c05d26a */
if(!s->budget--) { s->failed_pc=0x0c05d26au; return 0; }
r[6]+=r[2];
goto P_0c05d26c;
P_0c05d26c: /* original 53e3, guest PC 0x0c05d26c */
if(!s->budget--) { s->failed_pc=0x0c05d26cu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c05d26e;
P_0c05d26e: /* original 373c, guest PC 0x0c05d26e */
if(!s->budget--) { s->failed_pc=0x0c05d26eu; return 0; }
r[7]+=r[3];
goto P_0c05d270;
P_0c05d270: /* original 53e4, guest PC 0x0c05d270 */
if(!s->budget--) { s->failed_pc=0x0c05d270u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c05d272;
P_0c05d272: /* original 52fa, guest PC 0x0c05d272 */
if(!s->budget--) { s->failed_pc=0x0c05d272u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c05d274;
P_0c05d274: /* original 323c, guest PC 0x0c05d274 */
if(!s->budget--) { s->failed_pc=0x0c05d274u; return 0; }
r[2]+=r[3];
goto P_0c05d276;
P_0c05d276: /* original 1f2a, guest PC 0x0c05d276 */
if(!s->budget--) { s->failed_pc=0x0c05d276u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c05d278;
P_0c05d278: /* original 8d04, guest PC 0x0c05d278 */
if(!s->budget--) { s->failed_pc=0x0c05d278u; return 0; }
cond=r[17]&1u;
write(ram,r[1],r[10],4);
if(cond) { goto P_0c05d284; }
goto P_0c05d27c;
P_0c05d27a: /* original 21a2, guest PC 0x0c05d27a */
if(!s->budget--) { s->failed_pc=0x0c05d27au; return 0; }
write(ram,r[1],r[10],4);
goto P_0c05d27c;
P_0c05d27c: /* original 6012, guest PC 0x0c05d27c */
if(!s->budget--) { s->failed_pc=0x0c05d27cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d27e;
P_0c05d27e: /* original 20cb, guest PC 0x0c05d27e */
if(!s->budget--) { s->failed_pc=0x0c05d27eu; return 0; }
r[0]|=r[12];
goto P_0c05d280;
P_0c05d280: /* original 2102, guest PC 0x0c05d280 */
if(!s->budget--) { s->failed_pc=0x0c05d280u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c05d282;
P_0c05d282: /* original 7d01, guest PC 0x0c05d282 */
if(!s->budget--) { s->failed_pc=0x0c05d282u; return 0; }
r[13]+=0x00000001u;
goto P_0c05d284;
P_0c05d284: /* original 2558, guest PC 0x0c05d284 */
if(!s->budget--) { s->failed_pc=0x0c05d284u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05d286;
P_0c05d286: /* original 8904, guest PC 0x0c05d286 */
if(!s->budget--) { s->failed_pc=0x0c05d286u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d292; }
goto P_0c05d288;
P_0c05d288: /* original d35b, guest PC 0x0c05d288 */
if(!s->budget--) { s->failed_pc=0x0c05d288u; return 0; }
r[3]=read(ram,0x0c05d3f8u,4);
goto P_0c05d28a;
P_0c05d28a: /* original 6032, guest PC 0x0c05d28a */
if(!s->budget--) { s->failed_pc=0x0c05d28au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d28c;
P_0c05d28c: /* original cb02, guest PC 0x0c05d28c */
if(!s->budget--) { s->failed_pc=0x0c05d28cu; return 0; }
r[0]|=2u;
goto P_0c05d28e;
P_0c05d28e: /* original 2302, guest PC 0x0c05d28e */
if(!s->budget--) { s->failed_pc=0x0c05d28eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d290;
P_0c05d290: /* original 7d01, guest PC 0x0c05d290 */
if(!s->budget--) { s->failed_pc=0x0c05d290u; return 0; }
r[13]+=0x00000001u;
goto P_0c05d292;
P_0c05d292: /* original 2668, guest PC 0x0c05d292 */
if(!s->budget--) { s->failed_pc=0x0c05d292u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05d294;
P_0c05d294: /* original 8904, guest PC 0x0c05d294 */
if(!s->budget--) { s->failed_pc=0x0c05d294u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d2a0; }
goto P_0c05d296;
P_0c05d296: /* original d358, guest PC 0x0c05d296 */
if(!s->budget--) { s->failed_pc=0x0c05d296u; return 0; }
r[3]=read(ram,0x0c05d3f8u,4);
goto P_0c05d298;
P_0c05d298: /* original 6032, guest PC 0x0c05d298 */
if(!s->budget--) { s->failed_pc=0x0c05d298u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d29a;
P_0c05d29a: /* original cb04, guest PC 0x0c05d29a */
if(!s->budget--) { s->failed_pc=0x0c05d29au; return 0; }
r[0]|=4u;
goto P_0c05d29c;
P_0c05d29c: /* original 2302, guest PC 0x0c05d29c */
if(!s->budget--) { s->failed_pc=0x0c05d29cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d29e;
P_0c05d29e: /* original 7d01, guest PC 0x0c05d29e */
if(!s->budget--) { s->failed_pc=0x0c05d29eu; return 0; }
r[13]+=0x00000001u;
goto P_0c05d2a0;
P_0c05d2a0: /* original 2778, guest PC 0x0c05d2a0 */
if(!s->budget--) { s->failed_pc=0x0c05d2a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05d2a2;
P_0c05d2a2: /* original 8904, guest PC 0x0c05d2a2 */
if(!s->budget--) { s->failed_pc=0x0c05d2a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d2ae; }
goto P_0c05d2a4;
P_0c05d2a4: /* original d354, guest PC 0x0c05d2a4 */
if(!s->budget--) { s->failed_pc=0x0c05d2a4u; return 0; }
r[3]=read(ram,0x0c05d3f8u,4);
goto P_0c05d2a6;
P_0c05d2a6: /* original 6032, guest PC 0x0c05d2a6 */
if(!s->budget--) { s->failed_pc=0x0c05d2a6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d2a8;
P_0c05d2a8: /* original cb08, guest PC 0x0c05d2a8 */
if(!s->budget--) { s->failed_pc=0x0c05d2a8u; return 0; }
r[0]|=8u;
goto P_0c05d2aa;
P_0c05d2aa: /* original 2302, guest PC 0x0c05d2aa */
if(!s->budget--) { s->failed_pc=0x0c05d2aau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d2ac;
P_0c05d2ac: /* original 7d01, guest PC 0x0c05d2ac */
if(!s->budget--) { s->failed_pc=0x0c05d2acu; return 0; }
r[13]+=0x00000001u;
goto P_0c05d2ae;
P_0c05d2ae: /* original 52fa, guest PC 0x0c05d2ae */
if(!s->budget--) { s->failed_pc=0x0c05d2aeu; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c05d2b0;
P_0c05d2b0: /* original 2228, guest PC 0x0c05d2b0 */
if(!s->budget--) { s->failed_pc=0x0c05d2b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d2b2;
P_0c05d2b2: /* original 8904, guest PC 0x0c05d2b2 */
if(!s->budget--) { s->failed_pc=0x0c05d2b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d2be; }
goto P_0c05d2b4;
P_0c05d2b4: /* original d350, guest PC 0x0c05d2b4 */
if(!s->budget--) { s->failed_pc=0x0c05d2b4u; return 0; }
r[3]=read(ram,0x0c05d3f8u,4);
goto P_0c05d2b6;
P_0c05d2b6: /* original 6032, guest PC 0x0c05d2b6 */
if(!s->budget--) { s->failed_pc=0x0c05d2b6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d2b8;
P_0c05d2b8: /* original cb10, guest PC 0x0c05d2b8 */
if(!s->budget--) { s->failed_pc=0x0c05d2b8u; return 0; }
r[0]|=16u;
goto P_0c05d2ba;
P_0c05d2ba: /* original 2302, guest PC 0x0c05d2ba */
if(!s->budget--) { s->failed_pc=0x0c05d2bau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05d2bc;
P_0c05d2bc: /* original 7d01, guest PC 0x0c05d2bc */
if(!s->budget--) { s->failed_pc=0x0c05d2bcu; return 0; }
r[13]+=0x00000001u;
goto P_0c05d2be;
P_0c05d2be: /* original 60d3, guest PC 0x0c05d2be */
if(!s->budget--) { s->failed_pc=0x0c05d2beu; return 0; }
r[0]=r[13];
goto P_0c05d2c0;
P_0c05d2c0: /* original 0009, guest PC 0x0c05d2c0 */
if(!s->budget--) { s->failed_pc=0x0c05d2c0u; return 0; }
goto P_0c05d2c2;
P_0c05d2c2: /* original 7f14, guest PC 0x0c05d2c2 */
if(!s->budget--) { s->failed_pc=0x0c05d2c2u; return 0; }
r[15]+=0x00000014u;
goto P_0c05d2c4;
P_0c05d2c4: /* original 68f6, guest PC 0x0c05d2c4 */
if(!s->budget--) { s->failed_pc=0x0c05d2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05d2c6;
P_0c05d2c6: /* original 6af6, guest PC 0x0c05d2c6 */
if(!s->budget--) { s->failed_pc=0x0c05d2c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05d2c8;
P_0c05d2c8: /* original 6cf6, guest PC 0x0c05d2c8 */
if(!s->budget--) { s->failed_pc=0x0c05d2c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05d2ca;
P_0c05d2ca: /* original 6df6, guest PC 0x0c05d2ca */
if(!s->budget--) { s->failed_pc=0x0c05d2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05d2cc;
P_0c05d2cc: /* original 000b, guest PC 0x0c05d2cc */
if(!s->budget--) { s->failed_pc=0x0c05d2ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05d2ce: /* original 6ef6, guest PC 0x0c05d2ce */
if(!s->budget--) { s->failed_pc=0x0c05d2ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05d2d0;
P_0c05d2d0: /* original 2fe6, guest PC 0x0c05d2d0 */
if(!s->budget--) { s->failed_pc=0x0c05d2d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2d2;
P_0c05d2d2: /* original 2fd6, guest PC 0x0c05d2d2 */
if(!s->budget--) { s->failed_pc=0x0c05d2d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2d4;
P_0c05d2d4: /* original 2fc6, guest PC 0x0c05d2d4 */
if(!s->budget--) { s->failed_pc=0x0c05d2d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2d6;
P_0c05d2d6: /* original 2fb6, guest PC 0x0c05d2d6 */
if(!s->budget--) { s->failed_pc=0x0c05d2d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2d8;
P_0c05d2d8: /* original 2fa6, guest PC 0x0c05d2d8 */
if(!s->budget--) { s->failed_pc=0x0c05d2d8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2da;
P_0c05d2da: /* original 2f96, guest PC 0x0c05d2da */
if(!s->budget--) { s->failed_pc=0x0c05d2dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d2dc;
P_0c05d2dc: /* original 4f22, guest PC 0x0c05d2dc */
if(!s->budget--) { s->failed_pc=0x0c05d2dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05d2de;
P_0c05d2de: /* original 7ff0, guest PC 0x0c05d2de */
if(!s->budget--) { s->failed_pc=0x0c05d2deu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c05d2e0;
P_0c05d2e0: /* original d246, guest PC 0x0c05d2e0 */
if(!s->budget--) { s->failed_pc=0x0c05d2e0u; return 0; }
r[2]=read(ram,0x0c05d3fcu,4);
goto P_0c05d2e2;
P_0c05d2e2: /* original 61f3, guest PC 0x0c05d2e2 */
if(!s->budget--) { s->failed_pc=0x0c05d2e2u; return 0; }
r[1]=r[15];
goto P_0c05d2e4;
P_0c05d2e4: /* original d346, guest PC 0x0c05d2e4 */
if(!s->budget--) { s->failed_pc=0x0c05d2e4u; return 0; }
r[3]=read(ram,0x0c05d400u,4);
goto P_0c05d2e6;
P_0c05d2e6: /* original 430b, guest PC 0x0c05d2e6 */
if(!s->budget--) { s->failed_pc=0x0c05d2e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d2eau;
r[0]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d2eau) { target=s->pc; goto dispatch; }
goto P_0c05d2ea;
P_0c05d2e8: /* original e010, guest PC 0x0c05d2e8 */
if(!s->budget--) { s->failed_pc=0x0c05d2e8u; return 0; }
r[0]=0x00000010u;
goto P_0c05d2ea;
P_0c05d2ea: /* original d146, guest PC 0x0c05d2ea */
if(!s->budget--) { s->failed_pc=0x0c05d2eau; return 0; }
r[1]=read(ram,0x0c05d404u,4);
goto P_0c05d2ec;
P_0c05d2ec: /* original 6912, guest PC 0x0c05d2ec */
if(!s->budget--) { s->failed_pc=0x0c05d2ecu; return 0; }
tmp=read(ram,r[1],4);
r[9]=tmp;
goto P_0c05d2ee;
P_0c05d2ee: /* original 699c, guest PC 0x0c05d2ee */
if(!s->budget--) { s->failed_pc=0x0c05d2eeu; return 0; }
r[9]=r[9]&255u;
goto P_0c05d2f0;
P_0c05d2f0: /* original ec00, guest PC 0x0c05d2f0 */
if(!s->budget--) { s->failed_pc=0x0c05d2f0u; return 0; }
r[12]=0x00000000u;
goto P_0c05d2f2;
P_0c05d2f2: /* original 6ac3, guest PC 0x0c05d2f2 */
if(!s->budget--) { s->failed_pc=0x0c05d2f2u; return 0; }
r[10]=r[12];
goto P_0c05d2f4;
P_0c05d2f4: /* original 6dc3, guest PC 0x0c05d2f4 */
if(!s->budget--) { s->failed_pc=0x0c05d2f4u; return 0; }
r[13]=r[12];
goto P_0c05d2f6;
P_0c05d2f6: /* original 6bc3, guest PC 0x0c05d2f6 */
if(!s->budget--) { s->failed_pc=0x0c05d2f6u; return 0; }
r[11]=r[12];
goto P_0c05d2f8;
P_0c05d2f8: /* original 2558, guest PC 0x0c05d2f8 */
if(!s->budget--) { s->failed_pc=0x0c05d2f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05d2fa;
P_0c05d2fa: /* original 8d01, guest PC 0x0c05d2fa */
if(!s->budget--) { s->failed_pc=0x0c05d2fau; return 0; }
cond=r[17]&1u;
r[14]=r[12];
if(cond) { goto P_0c05d300; }
goto P_0c05d2fe;
P_0c05d2fc: /* original 6ec3, guest PC 0x0c05d2fc */
if(!s->budget--) { s->failed_pc=0x0c05d2fcu; return 0; }
r[14]=r[12];
goto P_0c05d2fe;
P_0c05d2fe: /* original eb01, guest PC 0x0c05d2fe */
if(!s->budget--) { s->failed_pc=0x0c05d2feu; return 0; }
r[11]=0x00000001u;
goto P_0c05d300;
P_0c05d300: /* original 2778, guest PC 0x0c05d300 */
if(!s->budget--) { s->failed_pc=0x0c05d300u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05d302;
P_0c05d302: /* original 8900, guest PC 0x0c05d302 */
if(!s->budget--) { s->failed_pc=0x0c05d302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d306; }
goto P_0c05d304;
P_0c05d304: /* original ea01, guest PC 0x0c05d304 */
if(!s->budget--) { s->failed_pc=0x0c05d304u; return 0; }
r[10]=0x00000001u;
goto P_0c05d306;
P_0c05d306: /* original 53fb, guest PC 0x0c05d306 */
if(!s->budget--) { s->failed_pc=0x0c05d306u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c05d308;
P_0c05d308: /* original 2338, guest PC 0x0c05d308 */
if(!s->budget--) { s->failed_pc=0x0c05d308u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05d30a;
P_0c05d30a: /* original 8900, guest PC 0x0c05d30a */
if(!s->budget--) { s->failed_pc=0x0c05d30au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d30e; }
goto P_0c05d30c;
P_0c05d30c: /* original ec02, guest PC 0x0c05d30c */
if(!s->budget--) { s->failed_pc=0x0c05d30cu; return 0; }
r[12]=0x00000002u;
goto P_0c05d30e;
P_0c05d30e: /* original 50fc, guest PC 0x0c05d30e */
if(!s->budget--) { s->failed_pc=0x0c05d30eu; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c05d310;
P_0c05d310: /* original 8801, guest PC 0x0c05d310 */
if(!s->budget--) { s->failed_pc=0x0c05d310u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d312;
P_0c05d312: /* original 8b06, guest PC 0x0c05d312 */
if(!s->budget--) { s->failed_pc=0x0c05d312u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d322; }
goto P_0c05d314;
P_0c05d314: /* original 2448, guest PC 0x0c05d314 */
if(!s->budget--) { s->failed_pc=0x0c05d314u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05d316;
P_0c05d316: /* original 8900, guest PC 0x0c05d316 */
if(!s->budget--) { s->failed_pc=0x0c05d316u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d31a; }
goto P_0c05d318;
P_0c05d318: /* original ee02, guest PC 0x0c05d318 */
if(!s->budget--) { s->failed_pc=0x0c05d318u; return 0; }
r[14]=0x00000002u;
goto P_0c05d31a;
P_0c05d31a: /* original 2668, guest PC 0x0c05d31a */
if(!s->budget--) { s->failed_pc=0x0c05d31au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05d31c;
P_0c05d31c: /* original 8b0f, guest PC 0x0c05d31c */
if(!s->budget--) { s->failed_pc=0x0c05d31cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d33e; }
goto P_0c05d31e;
P_0c05d31e: /* original a00f, guest PC 0x0c05d31e */
if(!s->budget--) { s->failed_pc=0x0c05d31eu; return 0; }
goto P_0c05d340;
P_0c05d320: /* original 0009, guest PC 0x0c05d320 */
if(!s->budget--) { s->failed_pc=0x0c05d320u; return 0; }
goto P_0c05d322;
P_0c05d322: /* original 2448, guest PC 0x0c05d322 */
if(!s->budget--) { s->failed_pc=0x0c05d322u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05d324;
P_0c05d324: /* original 8900, guest PC 0x0c05d324 */
if(!s->budget--) { s->failed_pc=0x0c05d324u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d328; }
goto P_0c05d326;
P_0c05d326: /* original ee03, guest PC 0x0c05d326 */
if(!s->budget--) { s->failed_pc=0x0c05d326u; return 0; }
r[14]=0x00000003u;
goto P_0c05d328;
P_0c05d328: /* original 2668, guest PC 0x0c05d328 */
if(!s->budget--) { s->failed_pc=0x0c05d328u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05d32a;
P_0c05d32a: /* original 8900, guest PC 0x0c05d32a */
if(!s->budget--) { s->failed_pc=0x0c05d32au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d32e; }
goto P_0c05d32c;
P_0c05d32c: /* original ed03, guest PC 0x0c05d32c */
if(!s->budget--) { s->failed_pc=0x0c05d32cu; return 0; }
r[13]=0x00000003u;
goto P_0c05d32e;
P_0c05d32e: /* original 2448, guest PC 0x0c05d32e */
if(!s->budget--) { s->failed_pc=0x0c05d32eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05d330;
P_0c05d330: /* original 8906, guest PC 0x0c05d330 */
if(!s->budget--) { s->failed_pc=0x0c05d330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d340; }
goto P_0c05d332;
P_0c05d332: /* original 2668, guest PC 0x0c05d332 */
if(!s->budget--) { s->failed_pc=0x0c05d332u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05d334;
P_0c05d334: /* original 8904, guest PC 0x0c05d334 */
if(!s->budget--) { s->failed_pc=0x0c05d334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d340; }
goto P_0c05d336;
P_0c05d336: /* original 3462, guest PC 0x0c05d336 */
if(!s->budget--) { s->failed_pc=0x0c05d336u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c05d338;
P_0c05d338: /* original 8901, guest PC 0x0c05d338 */
if(!s->budget--) { s->failed_pc=0x0c05d338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d33e; }
goto P_0c05d33a;
P_0c05d33a: /* original a001, guest PC 0x0c05d33a */
if(!s->budget--) { s->failed_pc=0x0c05d33au; return 0; }
r[14]=0x00000002u;
goto P_0c05d340;
P_0c05d33c: /* original ee02, guest PC 0x0c05d33c */
if(!s->budget--) { s->failed_pc=0x0c05d33cu; return 0; }
r[14]=0x00000002u;
goto P_0c05d33e;
P_0c05d33e: /* original ed02, guest PC 0x0c05d33e */
if(!s->budget--) { s->failed_pc=0x0c05d33eu; return 0; }
r[13]=0x00000002u;
goto P_0c05d340;
P_0c05d340: /* original d22b, guest PC 0x0c05d340 */
if(!s->budget--) { s->failed_pc=0x0c05d340u; return 0; }
r[2]=read(ram,0x0c05d3f0u,4);
goto P_0c05d342;
P_0c05d342: /* original 6022, guest PC 0x0c05d342 */
if(!s->budget--) { s->failed_pc=0x0c05d342u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d344;
P_0c05d344: /* original 8801, guest PC 0x0c05d344 */
if(!s->budget--) { s->failed_pc=0x0c05d344u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d346;
P_0c05d346: /* original 8b18, guest PC 0x0c05d346 */
if(!s->budget--) { s->failed_pc=0x0c05d346u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d37a; }
goto P_0c05d348;
P_0c05d348: /* original d12a, guest PC 0x0c05d348 */
if(!s->budget--) { s->failed_pc=0x0c05d348u; return 0; }
r[1]=read(ram,0x0c05d3f4u,4);
goto P_0c05d34a;
P_0c05d34a: /* original 6012, guest PC 0x0c05d34a */
if(!s->budget--) { s->failed_pc=0x0c05d34au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d34c;
P_0c05d34c: /* original 8820, guest PC 0x0c05d34c */
if(!s->budget--) { s->failed_pc=0x0c05d34cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05d34e;
P_0c05d34e: /* original 8b00, guest PC 0x0c05d34e */
if(!s->budget--) { s->failed_pc=0x0c05d34eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d352; }
goto P_0c05d350;
P_0c05d350: /* original ee03, guest PC 0x0c05d350 */
if(!s->budget--) { s->failed_pc=0x0c05d350u; return 0; }
r[14]=0x00000003u;
goto P_0c05d352;
P_0c05d352: /* original d228, guest PC 0x0c05d352 */
if(!s->budget--) { s->failed_pc=0x0c05d352u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d354;
P_0c05d354: /* original 6022, guest PC 0x0c05d354 */
if(!s->budget--) { s->failed_pc=0x0c05d354u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d356;
P_0c05d356: /* original 8821, guest PC 0x0c05d356 */
if(!s->budget--) { s->failed_pc=0x0c05d356u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000021u)!=0);
goto P_0c05d358;
P_0c05d358: /* original 8b00, guest PC 0x0c05d358 */
if(!s->budget--) { s->failed_pc=0x0c05d358u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d35c; }
goto P_0c05d35a;
P_0c05d35a: /* original eb02, guest PC 0x0c05d35a */
if(!s->budget--) { s->failed_pc=0x0c05d35au; return 0; }
r[11]=0x00000002u;
goto P_0c05d35c;
P_0c05d35c: /* original d225, guest PC 0x0c05d35c */
if(!s->budget--) { s->failed_pc=0x0c05d35cu; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d35e;
P_0c05d35e: /* original 6022, guest PC 0x0c05d35e */
if(!s->budget--) { s->failed_pc=0x0c05d35eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d360;
P_0c05d360: /* original 8822, guest PC 0x0c05d360 */
if(!s->budget--) { s->failed_pc=0x0c05d360u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000022u)!=0);
goto P_0c05d362;
P_0c05d362: /* original 8b00, guest PC 0x0c05d362 */
if(!s->budget--) { s->failed_pc=0x0c05d362u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d366; }
goto P_0c05d364;
P_0c05d364: /* original ed03, guest PC 0x0c05d364 */
if(!s->budget--) { s->failed_pc=0x0c05d364u; return 0; }
r[13]=0x00000003u;
goto P_0c05d366;
P_0c05d366: /* original d223, guest PC 0x0c05d366 */
if(!s->budget--) { s->failed_pc=0x0c05d366u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d368;
P_0c05d368: /* original 6022, guest PC 0x0c05d368 */
if(!s->budget--) { s->failed_pc=0x0c05d368u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d36a;
P_0c05d36a: /* original 8823, guest PC 0x0c05d36a */
if(!s->budget--) { s->failed_pc=0x0c05d36au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000023u)!=0);
goto P_0c05d36c;
P_0c05d36c: /* original 8b00, guest PC 0x0c05d36c */
if(!s->budget--) { s->failed_pc=0x0c05d36cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d370; }
goto P_0c05d36e;
P_0c05d36e: /* original ea02, guest PC 0x0c05d36e */
if(!s->budget--) { s->failed_pc=0x0c05d36eu; return 0; }
r[10]=0x00000002u;
goto P_0c05d370;
P_0c05d370: /* original d220, guest PC 0x0c05d370 */
if(!s->budget--) { s->failed_pc=0x0c05d370u; return 0; }
r[2]=read(ram,0x0c05d3f4u,4);
goto P_0c05d372;
P_0c05d372: /* original 6022, guest PC 0x0c05d372 */
if(!s->budget--) { s->failed_pc=0x0c05d372u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d374;
P_0c05d374: /* original 8824, guest PC 0x0c05d374 */
if(!s->budget--) { s->failed_pc=0x0c05d374u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000024u)!=0);
goto P_0c05d376;
P_0c05d376: /* original 8b00, guest PC 0x0c05d376 */
if(!s->budget--) { s->failed_pc=0x0c05d376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d37a; }
goto P_0c05d378;
P_0c05d378: /* original ec03, guest PC 0x0c05d378 */
if(!s->budget--) { s->failed_pc=0x0c05d378u; return 0; }
r[12]=0x00000003u;
goto P_0c05d37a;
P_0c05d37a: /* original 4e28, guest PC 0x0c05d37a */
if(!s->budget--) { s->failed_pc=0x0c05d37au; return 0; }
r[14]<<=16;
goto P_0c05d37c;
P_0c05d37c: /* original d222, guest PC 0x0c05d37c */
if(!s->budget--) { s->failed_pc=0x0c05d37cu; return 0; }
r[2]=read(ram,0x0c05d408u,4);
goto P_0c05d37e;
P_0c05d37e: /* original 63b3, guest PC 0x0c05d37e */
if(!s->budget--) { s->failed_pc=0x0c05d37eu; return 0; }
r[3]=r[11];
goto P_0c05d380;
P_0c05d380: /* original d122, guest PC 0x0c05d380 */
if(!s->budget--) { s->failed_pc=0x0c05d380u; return 0; }
r[1]=read(ram,0x0c05d40cu,4);
goto P_0c05d382;
P_0c05d382: /* original 4e00, guest PC 0x0c05d382 */
if(!s->budget--) { s->failed_pc=0x0c05d382u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c05d384;
P_0c05d384: /* original 2e29, guest PC 0x0c05d384 */
if(!s->budget--) { s->failed_pc=0x0c05d384u; return 0; }
r[14]&=r[2];
goto P_0c05d386;
P_0c05d386: /* original 4328, guest PC 0x0c05d386 */
if(!s->budget--) { s->failed_pc=0x0c05d386u; return 0; }
r[3]<<=16;
goto P_0c05d388;
P_0c05d388: /* original 4308, guest PC 0x0c05d388 */
if(!s->budget--) { s->failed_pc=0x0c05d388u; return 0; }
r[3]<<=2;
goto P_0c05d38a;
P_0c05d38a: /* original 4300, guest PC 0x0c05d38a */
if(!s->budget--) { s->failed_pc=0x0c05d38au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05d38c;
P_0c05d38c: /* original 2319, guest PC 0x0c05d38c */
if(!s->budget--) { s->failed_pc=0x0c05d38cu; return 0; }
r[3]&=r[1];
goto P_0c05d38e;
P_0c05d38e: /* original 2e3b, guest PC 0x0c05d38e */
if(!s->budget--) { s->failed_pc=0x0c05d38eu; return 0; }
r[14]|=r[3];
goto P_0c05d390;
P_0c05d390: /* original e315, guest PC 0x0c05d390 */
if(!s->budget--) { s->failed_pc=0x0c05d390u; return 0; }
r[3]=0x00000015u;
goto P_0c05d392;
P_0c05d392: /* original 60d3, guest PC 0x0c05d392 */
if(!s->budget--) { s->failed_pc=0x0c05d392u; return 0; }
r[0]=r[13];
goto P_0c05d394;
P_0c05d394: /* original 0009, guest PC 0x0c05d394 */
if(!s->budget--) { s->failed_pc=0x0c05d394u; return 0; }
goto P_0c05d396;
P_0c05d396: /* original 403d, guest PC 0x0c05d396 */
if(!s->budget--) { s->failed_pc=0x0c05d396u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c05d398;
P_0c05d398: /* original d21d, guest PC 0x0c05d398 */
if(!s->budget--) { s->failed_pc=0x0c05d398u; return 0; }
r[2]=read(ram,0x0c05d410u,4);
goto P_0c05d39a;
P_0c05d39a: /* original e317, guest PC 0x0c05d39a */
if(!s->budget--) { s->failed_pc=0x0c05d39au; return 0; }
r[3]=0x00000017u;
goto P_0c05d39c;
P_0c05d39c: /* original 2029, guest PC 0x0c05d39c */
if(!s->budget--) { s->failed_pc=0x0c05d39cu; return 0; }
r[0]&=r[2];
goto P_0c05d39e;
P_0c05d39e: /* original 2e0b, guest PC 0x0c05d39e */
if(!s->budget--) { s->failed_pc=0x0c05d39eu; return 0; }
r[14]|=r[0];
goto P_0c05d3a0;
P_0c05d3a0: /* original d01c, guest PC 0x0c05d3a0 */
if(!s->budget--) { s->failed_pc=0x0c05d3a0u; return 0; }
r[0]=read(ram,0x0c05d414u,4);
goto P_0c05d3a2;
P_0c05d3a2: /* original 4a3d, guest PC 0x0c05d3a2 */
if(!s->budget--) { s->failed_pc=0x0c05d3a2u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?r[10]>>((-r[3])&31u):0):r[10]<<(r[3]&31u);
goto P_0c05d3a4;
P_0c05d3a4: /* original 4208, guest PC 0x0c05d3a4 */
if(!s->budget--) { s->failed_pc=0x0c05d3a4u; return 0; }
r[2]<<=2;
goto P_0c05d3a6;
P_0c05d3a6: /* original 2a29, guest PC 0x0c05d3a6 */
if(!s->budget--) { s->failed_pc=0x0c05d3a6u; return 0; }
r[10]&=r[2];
goto P_0c05d3a8;
P_0c05d3a8: /* original 2eab, guest PC 0x0c05d3a8 */
if(!s->budget--) { s->failed_pc=0x0c05d3a8u; return 0; }
r[14]|=r[10];
goto P_0c05d3aa;
P_0c05d3aa: /* original 63c3, guest PC 0x0c05d3aa */
if(!s->budget--) { s->failed_pc=0x0c05d3aau; return 0; }
r[3]=r[12];
goto P_0c05d3ac;
P_0c05d3ac: /* original 4328, guest PC 0x0c05d3ac */
if(!s->budget--) { s->failed_pc=0x0c05d3acu; return 0; }
r[3]<<=16;
goto P_0c05d3ae;
P_0c05d3ae: /* original 4318, guest PC 0x0c05d3ae */
if(!s->budget--) { s->failed_pc=0x0c05d3aeu; return 0; }
r[3]<<=8;
goto P_0c05d3b0;
P_0c05d3b0: /* original 4300, guest PC 0x0c05d3b0 */
if(!s->budget--) { s->failed_pc=0x0c05d3b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05d3b2;
P_0c05d3b2: /* original 2309, guest PC 0x0c05d3b2 */
if(!s->budget--) { s->failed_pc=0x0c05d3b2u; return 0; }
r[3]&=r[0];
goto P_0c05d3b4;
P_0c05d3b4: /* original 2e3b, guest PC 0x0c05d3b4 */
if(!s->budget--) { s->failed_pc=0x0c05d3b4u; return 0; }
r[14]|=r[3];
goto P_0c05d3b6;
P_0c05d3b6: /* original d318, guest PC 0x0c05d3b6 */
if(!s->budget--) { s->failed_pc=0x0c05d3b6u; return 0; }
r[3]=read(ram,0x0c05d418u,4);
goto P_0c05d3b8;
P_0c05d3b8: /* original d218, guest PC 0x0c05d3b8 */
if(!s->budget--) { s->failed_pc=0x0c05d3b8u; return 0; }
r[2]=read(ram,0x0c05d41cu,4);
goto P_0c05d3ba;
P_0c05d3ba: /* original 2e3b, guest PC 0x0c05d3ba */
if(!s->budget--) { s->failed_pc=0x0c05d3bau; return 0; }
r[14]|=r[3];
goto P_0c05d3bc;
P_0c05d3bc: /* original 6022, guest PC 0x0c05d3bc */
if(!s->budget--) { s->failed_pc=0x0c05d3bcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d3be;
P_0c05d3be: /* original c820, guest PC 0x0c05d3be */
if(!s->budget--) { s->failed_pc=0x0c05d3beu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05d3c0;
P_0c05d3c0: /* original 8d0b, guest PC 0x0c05d3c0 */
if(!s->budget--) { s->failed_pc=0x0c05d3c0u; return 0; }
cond=r[17]&1u;
r[9]|=r[14];
if(cond) { goto P_0c05d3da; }
goto P_0c05d3c4;
P_0c05d3c2: /* original 29eb, guest PC 0x0c05d3c2 */
if(!s->budget--) { s->failed_pc=0x0c05d3c2u; return 0; }
r[9]|=r[14];
goto P_0c05d3c4;
P_0c05d3c4: /* original 2bb8, guest PC 0x0c05d3c4 */
if(!s->budget--) { s->failed_pc=0x0c05d3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05d3c6;
P_0c05d3c6: /* original 8905, guest PC 0x0c05d3c6 */
if(!s->budget--) { s->failed_pc=0x0c05d3c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d3d4; }
goto P_0c05d3c8;
P_0c05d3c8: /* original 2dd8, guest PC 0x0c05d3c8 */
if(!s->budget--) { s->failed_pc=0x0c05d3c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05d3ca;
P_0c05d3ca: /* original 8903, guest PC 0x0c05d3ca */
if(!s->budget--) { s->failed_pc=0x0c05d3cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d3d4; }
goto P_0c05d3cc;
P_0c05d3cc: /* original 2cc8, guest PC 0x0c05d3cc */
if(!s->budget--) { s->failed_pc=0x0c05d3ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c05d3ce;
P_0c05d3ce: /* original 8901, guest PC 0x0c05d3ce */
if(!s->budget--) { s->failed_pc=0x0c05d3ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d3d4; }
goto P_0c05d3d0;
P_0c05d3d0: /* original a001, guest PC 0x0c05d3d0 */
if(!s->budget--) { s->failed_pc=0x0c05d3d0u; return 0; }
r[3]=0x00000001u;
goto P_0c05d3d6;
P_0c05d3d2: /* original e301, guest PC 0x0c05d3d2 */
if(!s->budget--) { s->failed_pc=0x0c05d3d2u; return 0; }
r[3]=0x00000001u;
goto P_0c05d3d4;
P_0c05d3d4: /* original e300, guest PC 0x0c05d3d4 */
if(!s->budget--) { s->failed_pc=0x0c05d3d4u; return 0; }
r[3]=0x00000000u;
goto P_0c05d3d6;
P_0c05d3d6: /* original d212, guest PC 0x0c05d3d6 */
if(!s->budget--) { s->failed_pc=0x0c05d3d6u; return 0; }
r[2]=read(ram,0x0c05d420u,4);
goto P_0c05d3d8;
P_0c05d3d8: /* original 2232, guest PC 0x0c05d3d8 */
if(!s->budget--) { s->failed_pc=0x0c05d3d8u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05d3da;
P_0c05d3da: /* original 6093, guest PC 0x0c05d3da */
if(!s->budget--) { s->failed_pc=0x0c05d3dau; return 0; }
r[0]=r[9];
goto P_0c05d3dc;
P_0c05d3dc: /* original 0009, guest PC 0x0c05d3dc */
if(!s->budget--) { s->failed_pc=0x0c05d3dcu; return 0; }
goto P_0c05d3de;
P_0c05d3de: /* original 7f10, guest PC 0x0c05d3de */
if(!s->budget--) { s->failed_pc=0x0c05d3deu; return 0; }
r[15]+=0x00000010u;
goto P_0c05d3e0;
P_0c05d3e0: /* original 4f26, guest PC 0x0c05d3e0 */
if(!s->budget--) { s->failed_pc=0x0c05d3e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05d3e2;
P_0c05d3e2: /* original 69f6, guest PC 0x0c05d3e2 */
if(!s->budget--) { s->failed_pc=0x0c05d3e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05d3e4;
P_0c05d3e4: /* original 6af6, guest PC 0x0c05d3e4 */
if(!s->budget--) { s->failed_pc=0x0c05d3e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05d3e6;
P_0c05d3e6: /* original 6bf6, guest PC 0x0c05d3e6 */
if(!s->budget--) { s->failed_pc=0x0c05d3e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05d3e8;
P_0c05d3e8: /* original 6cf6, guest PC 0x0c05d3e8 */
if(!s->budget--) { s->failed_pc=0x0c05d3e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05d3ea;
P_0c05d3ea: /* original 6df6, guest PC 0x0c05d3ea */
if(!s->budget--) { s->failed_pc=0x0c05d3eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05d3ec;
P_0c05d3ec: /* original 000b, guest PC 0x0c05d3ec */
if(!s->budget--) { s->failed_pc=0x0c05d3ecu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05d3ee: /* original 6ef6, guest PC 0x0c05d3ee */
if(!s->budget--) { s->failed_pc=0x0c05d3eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05d3f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d3f0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
