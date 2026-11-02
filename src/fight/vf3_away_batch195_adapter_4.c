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
int vf3_away_batch195_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05f28au: goto P_0c05f28a;
case 0x0c05f28cu: goto P_0c05f28c;
case 0x0c05f28eu: goto P_0c05f28e;
case 0x0c05f290u: goto P_0c05f290;
case 0x0c05f292u: goto P_0c05f292;
case 0x0c05f294u: goto P_0c05f294;
case 0x0c05f296u: goto P_0c05f296;
case 0x0c05f298u: goto P_0c05f298;
case 0x0c05f29au: goto P_0c05f29a;
case 0x0c05f29cu: goto P_0c05f29c;
case 0x0c05f29eu: goto P_0c05f29e;
case 0x0c05f2a0u: goto P_0c05f2a0;
case 0x0c05f2a2u: goto P_0c05f2a2;
case 0x0c05f2a4u: goto P_0c05f2a4;
case 0x0c05f2a6u: goto P_0c05f2a6;
case 0x0c05f2a8u: goto P_0c05f2a8;
case 0x0c05f2aau: goto P_0c05f2aa;
case 0x0c05f2acu: goto P_0c05f2ac;
case 0x0c05f2aeu: goto P_0c05f2ae;
case 0x0c05f2b0u: goto P_0c05f2b0;
case 0x0c05f2b2u: goto P_0c05f2b2;
case 0x0c05f2b4u: goto P_0c05f2b4;
case 0x0c05f2b6u: goto P_0c05f2b6;
case 0x0c05f2b8u: goto P_0c05f2b8;
case 0x0c05f2bau: goto P_0c05f2ba;
case 0x0c05f2bcu: goto P_0c05f2bc;
case 0x0c05f2beu: goto P_0c05f2be;
case 0x0c05f2c0u: goto P_0c05f2c0;
case 0x0c05f2c2u: goto P_0c05f2c2;
case 0x0c05f2c4u: goto P_0c05f2c4;
case 0x0c05f2c6u: goto P_0c05f2c6;
case 0x0c05f2c8u: goto P_0c05f2c8;
case 0x0c05f2cau: goto P_0c05f2ca;
case 0x0c05f2ccu: goto P_0c05f2cc;
case 0x0c05f2ceu: goto P_0c05f2ce;
case 0x0c05f2d0u: goto P_0c05f2d0;
case 0x0c05f2d2u: goto P_0c05f2d2;
case 0x0c05f2d4u: goto P_0c05f2d4;
case 0x0c05f2d6u: goto P_0c05f2d6;
case 0x0c05f2d8u: goto P_0c05f2d8;
case 0x0c05f2dau: goto P_0c05f2da;
case 0x0c05f2dcu: goto P_0c05f2dc;
case 0x0c05f2deu: goto P_0c05f2de;
case 0x0c05f2e0u: goto P_0c05f2e0;
case 0x0c05f2e2u: goto P_0c05f2e2;
case 0x0c05f2e4u: goto P_0c05f2e4;
case 0x0c05f2e6u: goto P_0c05f2e6;
case 0x0c05f2e8u: goto P_0c05f2e8;
case 0x0c05f2eau: goto P_0c05f2ea;
case 0x0c05f2ecu: goto P_0c05f2ec;
case 0x0c05f2eeu: goto P_0c05f2ee;
case 0x0c05f2f0u: goto P_0c05f2f0;
case 0x0c05f2f2u: goto P_0c05f2f2;
case 0x0c05f2f4u: goto P_0c05f2f4;
case 0x0c05f2f6u: goto P_0c05f2f6;
case 0x0c05f2f8u: goto P_0c05f2f8;
case 0x0c05f2fau: goto P_0c05f2fa;
case 0x0c05f2fcu: goto P_0c05f2fc;
case 0x0c05f2feu: goto P_0c05f2fe;
case 0x0c05f300u: goto P_0c05f300;
case 0x0c05f302u: goto P_0c05f302;
case 0x0c05f304u: goto P_0c05f304;
case 0x0c05f306u: goto P_0c05f306;
case 0x0c05f308u: goto P_0c05f308;
case 0x0c05f30au: goto P_0c05f30a;
case 0x0c05f30cu: goto P_0c05f30c;
case 0x0c05f30eu: goto P_0c05f30e;
case 0x0c05f310u: goto P_0c05f310;
case 0x0c05f312u: goto P_0c05f312;
case 0x0c05f314u: goto P_0c05f314;
case 0x0c05f316u: goto P_0c05f316;
case 0x0c05f318u: goto P_0c05f318;
case 0x0c05f31au: goto P_0c05f31a;
case 0x0c05f31cu: goto P_0c05f31c;
case 0x0c05f31eu: goto P_0c05f31e;
case 0x0c05f320u: goto P_0c05f320;
case 0x0c05f322u: goto P_0c05f322;
case 0x0c05f324u: goto P_0c05f324;
case 0x0c05f326u: goto P_0c05f326;
case 0x0c05f328u: goto P_0c05f328;
case 0x0c05f32au: goto P_0c05f32a;
case 0x0c05f32cu: goto P_0c05f32c;
case 0x0c05f32eu: goto P_0c05f32e;
case 0x0c05f330u: goto P_0c05f330;
case 0x0c05f332u: goto P_0c05f332;
case 0x0c05f334u: goto P_0c05f334;
case 0x0c05f336u: goto P_0c05f336;
case 0x0c05f338u: goto P_0c05f338;
case 0x0c05f362u: goto P_0c05f362;
case 0x0c05f364u: goto P_0c05f364;
case 0x0c05f366u: goto P_0c05f366;
case 0x0c05f368u: goto P_0c05f368;
case 0x0c05f36au: goto P_0c05f36a;
case 0x0c05f36cu: goto P_0c05f36c;
case 0x0c05f36eu: goto P_0c05f36e;
case 0x0c05f370u: goto P_0c05f370;
case 0x0c05f372u: goto P_0c05f372;
case 0x0c05f374u: goto P_0c05f374;
case 0x0c05f376u: goto P_0c05f376;
case 0x0c05f378u: goto P_0c05f378;
case 0x0c05f37au: goto P_0c05f37a;
case 0x0c05f37cu: goto P_0c05f37c;
case 0x0c05f37eu: goto P_0c05f37e;
case 0x0c05f380u: goto P_0c05f380;
case 0x0c05f382u: goto P_0c05f382;
case 0x0c05f384u: goto P_0c05f384;
case 0x0c05f386u: goto P_0c05f386;
case 0x0c05f388u: goto P_0c05f388;
case 0x0c05f38au: goto P_0c05f38a;
case 0x0c05f38cu: goto P_0c05f38c;
case 0x0c05f38eu: goto P_0c05f38e;
case 0x0c05f390u: goto P_0c05f390;
case 0x0c05f392u: goto P_0c05f392;
case 0x0c05f3b0u: goto P_0c05f3b0;
case 0x0c05f3b2u: goto P_0c05f3b2;
case 0x0c05f3b4u: goto P_0c05f3b4;
case 0x0c05f3b6u: goto P_0c05f3b6;
case 0x0c05f3b8u: goto P_0c05f3b8;
case 0x0c05f3bau: goto P_0c05f3ba;
case 0x0c05f3bcu: goto P_0c05f3bc;
case 0x0c05f3beu: goto P_0c05f3be;
case 0x0c05f3c0u: goto P_0c05f3c0;
case 0x0c05f3c2u: goto P_0c05f3c2;
case 0x0c05f3c4u: goto P_0c05f3c4;
case 0x0c05f3c6u: goto P_0c05f3c6;
case 0x0c05f3c8u: goto P_0c05f3c8;
case 0x0c05f3cau: goto P_0c05f3ca;
case 0x0c05f3ccu: goto P_0c05f3cc;
case 0x0c05f3ceu: goto P_0c05f3ce;
case 0x0c05f3d0u: goto P_0c05f3d0;
case 0x0c05f3d2u: goto P_0c05f3d2;
case 0x0c05f3d4u: goto P_0c05f3d4;
case 0x0c05f3d6u: goto P_0c05f3d6;
case 0x0c05f3d8u: goto P_0c05f3d8;
case 0x0c05f3dau: goto P_0c05f3da;
case 0x0c05f3dcu: goto P_0c05f3dc;
case 0x0c06149eu: goto P_0c06149e;
case 0x0c0614a0u: goto P_0c0614a0;
case 0x0c0614a2u: goto P_0c0614a2;
case 0x0c0614a4u: goto P_0c0614a4;
case 0x0c0614a6u: goto P_0c0614a6;
case 0x0c0614a8u: goto P_0c0614a8;
case 0x0c0614aau: goto P_0c0614aa;
case 0x0c0614acu: goto P_0c0614ac;
case 0x0c0614aeu: goto P_0c0614ae;
case 0x0c0614b0u: goto P_0c0614b0;
case 0x0c0614b2u: goto P_0c0614b2;
case 0x0c0614b4u: goto P_0c0614b4;
case 0x0c0614b6u: goto P_0c0614b6;
case 0x0c0614b8u: goto P_0c0614b8;
case 0x0c0614bau: goto P_0c0614ba;
case 0x0c0614bcu: goto P_0c0614bc;
case 0x0c0614beu: goto P_0c0614be;
case 0x0c0614c0u: goto P_0c0614c0;
case 0x0c0614c2u: goto P_0c0614c2;
case 0x0c0614c4u: goto P_0c0614c4;
case 0x0c0614c6u: goto P_0c0614c6;
case 0x0c0614c8u: goto P_0c0614c8;
case 0x0c0614cau: goto P_0c0614ca;
case 0x0c0614ccu: goto P_0c0614cc;
case 0x0c0614ceu: goto P_0c0614ce;
case 0x0c0614d0u: goto P_0c0614d0;
case 0x0c0614d2u: goto P_0c0614d2;
case 0x0c0614d4u: goto P_0c0614d4;
case 0x0c0614d6u: goto P_0c0614d6;
case 0x0c0614d8u: goto P_0c0614d8;
case 0x0c0614dau: goto P_0c0614da;
case 0x0c0614dcu: goto P_0c0614dc;
case 0x0c0614deu: goto P_0c0614de;
case 0x0c0614e0u: goto P_0c0614e0;
case 0x0c0614e2u: goto P_0c0614e2;
case 0x0c0614e4u: goto P_0c0614e4;
case 0x0c0614e6u: goto P_0c0614e6;
case 0x0c0614e8u: goto P_0c0614e8;
case 0x0c0614eau: goto P_0c0614ea;
case 0x0c0614ecu: goto P_0c0614ec;
case 0x0c0614eeu: goto P_0c0614ee;
case 0x0c0614f0u: goto P_0c0614f0;
case 0x0c0614f2u: goto P_0c0614f2;
case 0x0c0614f4u: goto P_0c0614f4;
case 0x0c0614f6u: goto P_0c0614f6;
case 0x0c0614f8u: goto P_0c0614f8;
case 0x0c0614fau: goto P_0c0614fa;
case 0x0c0614fcu: goto P_0c0614fc;
case 0x0c0614feu: goto P_0c0614fe;
case 0x0c061500u: goto P_0c061500;
case 0x0c061502u: goto P_0c061502;
case 0x0c061504u: goto P_0c061504;
case 0x0c061506u: goto P_0c061506;
case 0x0c061508u: goto P_0c061508;
case 0x0c06150au: goto P_0c06150a;
case 0x0c06150cu: goto P_0c06150c;
case 0x0c06150eu: goto P_0c06150e;
case 0x0c061510u: goto P_0c061510;
case 0x0c061512u: goto P_0c061512;
case 0x0c061514u: goto P_0c061514;
case 0x0c061516u: goto P_0c061516;
case 0x0c061518u: goto P_0c061518;
case 0x0c06151au: goto P_0c06151a;
case 0x0c06151cu: goto P_0c06151c;
case 0x0c06151eu: goto P_0c06151e;
case 0x0c061520u: goto P_0c061520;
case 0x0c061522u: goto P_0c061522;
case 0x0c061524u: goto P_0c061524;
case 0x0c061526u: goto P_0c061526;
case 0x0c061528u: goto P_0c061528;
case 0x0c06152au: goto P_0c06152a;
case 0x0c06152cu: goto P_0c06152c;
case 0x0c06152eu: goto P_0c06152e;
case 0x0c061530u: goto P_0c061530;
case 0x0c061532u: goto P_0c061532;
case 0x0c061534u: goto P_0c061534;
case 0x0c061536u: goto P_0c061536;
case 0x0c061538u: goto P_0c061538;
case 0x0c06153au: goto P_0c06153a;
case 0x0c06153cu: goto P_0c06153c;
case 0x0c06153eu: goto P_0c06153e;
case 0x0c061540u: goto P_0c061540;
case 0x0c061542u: goto P_0c061542;
case 0x0c061544u: goto P_0c061544;
case 0x0c061546u: goto P_0c061546;
case 0x0c061548u: goto P_0c061548;
case 0x0c06154au: goto P_0c06154a;
case 0x0c06154cu: goto P_0c06154c;
case 0x0c06154eu: goto P_0c06154e;
case 0x0c061550u: goto P_0c061550;
case 0x0c061552u: goto P_0c061552;
case 0x0c061554u: goto P_0c061554;
case 0x0c061556u: goto P_0c061556;
case 0x0c061558u: goto P_0c061558;
case 0x0c06155au: goto P_0c06155a;
case 0x0c06155cu: goto P_0c06155c;
case 0x0c06155eu: goto P_0c06155e;
case 0x0c061560u: goto P_0c061560;
case 0x0c061562u: goto P_0c061562;
case 0x0c061564u: goto P_0c061564;
case 0x0c061566u: goto P_0c061566;
case 0x0c061568u: goto P_0c061568;
case 0x0c06156au: goto P_0c06156a;
case 0x0c06156cu: goto P_0c06156c;
case 0x0c06156eu: goto P_0c06156e;
case 0x0c061570u: goto P_0c061570;
case 0x0c061572u: goto P_0c061572;
case 0x0c061574u: goto P_0c061574;
case 0x0c061576u: goto P_0c061576;
case 0x0c061578u: goto P_0c061578;
case 0x0c06157au: goto P_0c06157a;
case 0x0c06157cu: goto P_0c06157c;
case 0x0c06157eu: goto P_0c06157e;
case 0x0c061580u: goto P_0c061580;
case 0x0c061582u: goto P_0c061582;
case 0x0c061584u: goto P_0c061584;
case 0x0c061586u: goto P_0c061586;
case 0x0c061588u: goto P_0c061588;
case 0x0c06158au: goto P_0c06158a;
case 0x0c06158cu: goto P_0c06158c;
case 0x0c06158eu: goto P_0c06158e;
case 0x0c061590u: goto P_0c061590;
case 0x0c061592u: goto P_0c061592;
case 0x0c061594u: goto P_0c061594;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05f28a: /* original 2fe6, guest PC 0x0c05f28a */
if(!s->budget--) { s->failed_pc=0x0c05f28au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f28c;
P_0c05f28c: /* original 2fd6, guest PC 0x0c05f28c */
if(!s->budget--) { s->failed_pc=0x0c05f28cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f28e;
P_0c05f28e: /* original 2fc6, guest PC 0x0c05f28e */
if(!s->budget--) { s->failed_pc=0x0c05f28eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f290;
P_0c05f290: /* original 2fb6, guest PC 0x0c05f290 */
if(!s->budget--) { s->failed_pc=0x0c05f290u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f292;
P_0c05f292: /* original 6b43, guest PC 0x0c05f292 */
if(!s->budget--) { s->failed_pc=0x0c05f292u; return 0; }
r[11]=r[4];
goto P_0c05f294;
P_0c05f294: /* original 4f22, guest PC 0x0c05f294 */
if(!s->budget--) { s->failed_pc=0x0c05f294u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f296;
P_0c05f296: /* original 7ff8, guest PC 0x0c05f296 */
if(!s->budget--) { s->failed_pc=0x0c05f296u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05f298;
P_0c05f298: /* original 5db3, guest PC 0x0c05f298 */
if(!s->budget--) { s->failed_pc=0x0c05f298u; return 0; }
r[13]=read(ram,r[11]+12,4);
goto P_0c05f29a;
P_0c05f29a: /* original 1fd1, guest PC 0x0c05f29a */
if(!s->budget--) { s->failed_pc=0x0c05f29au; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c05f29c;
P_0c05f29c: /* original 5eb4, guest PC 0x0c05f29c */
if(!s->budget--) { s->failed_pc=0x0c05f29cu; return 0; }
r[14]=read(ram,r[11]+16,4);
goto P_0c05f29e;
P_0c05f29e: /* original 4d01, guest PC 0x0c05f29e */
if(!s->budget--) { s->failed_pc=0x0c05f29eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c05f2a0;
P_0c05f2a0: /* original 2fe2, guest PC 0x0c05f2a0 */
if(!s->budget--) { s->failed_pc=0x0c05f2a0u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c05f2a2;
P_0c05f2a2: /* original 4e01, guest PC 0x0c05f2a2 */
if(!s->budget--) { s->failed_pc=0x0c05f2a2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]>>=1;
goto P_0c05f2a4;
P_0c05f2a4: /* original 65f2, guest PC 0x0c05f2a4 */
if(!s->budget--) { s->failed_pc=0x0c05f2a4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f2a6;
P_0c05f2a6: /* original 0de7, guest PC 0x0c05f2a6 */
if(!s->budget--) { s->failed_pc=0x0c05f2a6u; return 0; }
r[19]=r[13]*r[14];
goto P_0c05f2a8;
P_0c05f2a8: /* original 0c1a, guest PC 0x0c05f2a8 */
if(!s->budget--) { s->failed_pc=0x0c05f2a8u; return 0; }
r[12]=r[19];
goto P_0c05f2aa;
P_0c05f2aa: /* original bf05, guest PC 0x0c05f2aa */
if(!s->budget--) { s->failed_pc=0x0c05f2aau; return 0; }
target=code_base|0x0c05f0b8u; r[16]=code_base|0x0c05f2aeu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f2aeu) { target=s->pc; goto dispatch; }
goto P_0c05f2ae;
P_0c05f2ac: /* original 54f1, guest PC 0x0c05f2ac */
if(!s->budget--) { s->failed_pc=0x0c05f2acu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05f2ae;
P_0c05f2ae: /* original 6503, guest PC 0x0c05f2ae */
if(!s->budget--) { s->failed_pc=0x0c05f2aeu; return 0; }
r[5]=r[0];
goto P_0c05f2b0;
P_0c05f2b0: /* original 52b6, guest PC 0x0c05f2b0 */
if(!s->budget--) { s->failed_pc=0x0c05f2b0u; return 0; }
r[2]=read(ram,r[11]+24,4);
goto P_0c05f2b2;
P_0c05f2b2: /* original e401, guest PC 0x0c05f2b2 */
if(!s->budget--) { s->failed_pc=0x0c05f2b2u; return 0; }
r[4]=0x00000001u;
goto P_0c05f2b4;
P_0c05f2b4: /* original 6603, guest PC 0x0c05f2b4 */
if(!s->budget--) { s->failed_pc=0x0c05f2b4u; return 0; }
r[6]=r[0];
goto P_0c05f2b6;
P_0c05f2b6: /* original 2248, guest PC 0x0c05f2b6 */
if(!s->budget--) { s->failed_pc=0x0c05f2b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c05f2b8;
P_0c05f2b8: /* original 8d1e, guest PC 0x0c05f2b8 */
if(!s->budget--) { s->failed_pc=0x0c05f2b8u; return 0; }
cond=r[17]&1u;
r[6]<<=2;
if(cond) { goto P_0c05f2f8; }
goto P_0c05f2bc;
P_0c05f2ba: /* original 4608, guest PC 0x0c05f2ba */
if(!s->budget--) { s->failed_pc=0x0c05f2bau; return 0; }
r[6]<<=2;
goto P_0c05f2bc;
P_0c05f2bc: /* original 4d01, guest PC 0x0c05f2bc */
if(!s->budget--) { s->failed_pc=0x0c05f2bcu; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c05f2be;
P_0c05f2be: /* original 4e01, guest PC 0x0c05f2be */
if(!s->budget--) { s->failed_pc=0x0c05f2beu; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]>>=1;
goto P_0c05f2c0;
P_0c05f2c0: /* original 3de2, guest PC 0x0c05f2c0 */
if(!s->budget--) { s->failed_pc=0x0c05f2c0u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[14])!=0);
goto P_0c05f2c2;
P_0c05f2c2: /* original 8901, guest PC 0x0c05f2c2 */
if(!s->budget--) { s->failed_pc=0x0c05f2c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f2c8; }
goto P_0c05f2c4;
P_0c05f2c4: /* original a001, guest PC 0x0c05f2c4 */
if(!s->budget--) { s->failed_pc=0x0c05f2c4u; return 0; }
r[5]=r[13];
goto P_0c05f2ca;
P_0c05f2c6: /* original 65d3, guest PC 0x0c05f2c6 */
if(!s->budget--) { s->failed_pc=0x0c05f2c6u; return 0; }
r[5]=r[13];
goto P_0c05f2c8;
P_0c05f2c8: /* original 65e3, guest PC 0x0c05f2c8 */
if(!s->budget--) { s->failed_pc=0x0c05f2c8u; return 0; }
r[5]=r[14];
goto P_0c05f2ca;
P_0c05f2ca: /* original 3546, guest PC 0x0c05f2ca */
if(!s->budget--) { s->failed_pc=0x0c05f2cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c05f2cc;
P_0c05f2cc: /* original 8b07, guest PC 0x0c05f2cc */
if(!s->budget--) { s->failed_pc=0x0c05f2ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f2de; }
goto P_0c05f2ce;
P_0c05f2ce: /* original 0de7, guest PC 0x0c05f2ce */
if(!s->budget--) { s->failed_pc=0x0c05f2ceu; return 0; }
r[19]=r[13]*r[14];
goto P_0c05f2d0;
P_0c05f2d0: /* original 031a, guest PC 0x0c05f2d0 */
if(!s->budget--) { s->failed_pc=0x0c05f2d0u; return 0; }
r[3]=r[19];
goto P_0c05f2d2;
P_0c05f2d2: /* original 4d01, guest PC 0x0c05f2d2 */
if(!s->budget--) { s->failed_pc=0x0c05f2d2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c05f2d4;
P_0c05f2d4: /* original 4e01, guest PC 0x0c05f2d4 */
if(!s->budget--) { s->failed_pc=0x0c05f2d4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]>>=1;
goto P_0c05f2d6;
P_0c05f2d6: /* original 4501, guest PC 0x0c05f2d6 */
if(!s->budget--) { s->failed_pc=0x0c05f2d6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f2d8;
P_0c05f2d8: /* original 3546, guest PC 0x0c05f2d8 */
if(!s->budget--) { s->failed_pc=0x0c05f2d8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c05f2da;
P_0c05f2da: /* original 8df8, guest PC 0x0c05f2da */
if(!s->budget--) { s->failed_pc=0x0c05f2dau; return 0; }
cond=r[17]&1u;
r[12]+=r[3];
if(cond) { goto P_0c05f2ce; }
goto P_0c05f2de;
P_0c05f2dc: /* original 3c3c, guest PC 0x0c05f2dc */
if(!s->budget--) { s->failed_pc=0x0c05f2dcu; return 0; }
r[12]+=r[3];
goto P_0c05f2de;
P_0c05f2de: /* original 3de0, guest PC 0x0c05f2de */
if(!s->budget--) { s->failed_pc=0x0c05f2deu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[14])!=0);
goto P_0c05f2e0;
P_0c05f2e0: /* original 8b01, guest PC 0x0c05f2e0 */
if(!s->budget--) { s->failed_pc=0x0c05f2e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f2e6; }
goto P_0c05f2e2;
P_0c05f2e2: /* original a003, guest PC 0x0c05f2e2 */
if(!s->budget--) { s->failed_pc=0x0c05f2e2u; return 0; }
r[12]+=0x00000002u;
goto P_0c05f2ec;
P_0c05f2e4: /* original 7c02, guest PC 0x0c05f2e4 */
if(!s->budget--) { s->failed_pc=0x0c05f2e4u; return 0; }
r[12]+=0x00000002u;
goto P_0c05f2e6;
P_0c05f2e6: /* original 0de7, guest PC 0x0c05f2e6 */
if(!s->budget--) { s->failed_pc=0x0c05f2e6u; return 0; }
r[19]=r[13]*r[14];
goto P_0c05f2e8;
P_0c05f2e8: /* original 0d1a, guest PC 0x0c05f2e8 */
if(!s->budget--) { s->failed_pc=0x0c05f2e8u; return 0; }
r[13]=r[19];
goto P_0c05f2ea;
P_0c05f2ea: /* original 3cdc, guest PC 0x0c05f2ea */
if(!s->budget--) { s->failed_pc=0x0c05f2eau; return 0; }
r[12]+=r[13];
goto P_0c05f2ec;
P_0c05f2ec: /* original d02a, guest PC 0x0c05f2ec */
if(!s->budget--) { s->failed_pc=0x0c05f2ecu; return 0; }
r[0]=read(ram,0x0c05f398u,4);
goto P_0c05f2ee;
P_0c05f2ee: /* original 7c0a, guest PC 0x0c05f2ee */
if(!s->budget--) { s->failed_pc=0x0c05f2eeu; return 0; }
r[12]+=0x0000000au;
goto P_0c05f2f0;
P_0c05f2f0: /* original 036e, guest PC 0x0c05f2f0 */
if(!s->budget--) { s->failed_pc=0x0c05f2f0u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c05f2f2;
P_0c05f2f2: /* original 3c3c, guest PC 0x0c05f2f2 */
if(!s->budget--) { s->failed_pc=0x0c05f2f2u; return 0; }
r[12]+=r[3];
goto P_0c05f2f4;
P_0c05f2f4: /* original a003, guest PC 0x0c05f2f4 */
if(!s->budget--) { s->failed_pc=0x0c05f2f4u; return 0; }
goto P_0c05f2fe;
P_0c05f2f6: /* original 0009, guest PC 0x0c05f2f6 */
if(!s->budget--) { s->failed_pc=0x0c05f2f6u; return 0; }
goto P_0c05f2f8;
P_0c05f2f8: /* original d028, guest PC 0x0c05f2f8 */
if(!s->budget--) { s->failed_pc=0x0c05f2f8u; return 0; }
r[0]=read(ram,0x0c05f39cu,4);
goto P_0c05f2fa;
P_0c05f2fa: /* original 036e, guest PC 0x0c05f2fa */
if(!s->budget--) { s->failed_pc=0x0c05f2fau; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c05f2fc;
P_0c05f2fc: /* original 3c3c, guest PC 0x0c05f2fc */
if(!s->budget--) { s->failed_pc=0x0c05f2fcu; return 0; }
r[12]+=r[3];
goto P_0c05f2fe;
P_0c05f2fe: /* original 60c3, guest PC 0x0c05f2fe */
if(!s->budget--) { s->failed_pc=0x0c05f2feu; return 0; }
r[0]=r[12];
goto P_0c05f300;
P_0c05f300: /* original 0009, guest PC 0x0c05f300 */
if(!s->budget--) { s->failed_pc=0x0c05f300u; return 0; }
goto P_0c05f302;
P_0c05f302: /* original 7f08, guest PC 0x0c05f302 */
if(!s->budget--) { s->failed_pc=0x0c05f302u; return 0; }
r[15]+=0x00000008u;
goto P_0c05f304;
P_0c05f304: /* original 4f26, guest PC 0x0c05f304 */
if(!s->budget--) { s->failed_pc=0x0c05f304u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f306;
P_0c05f306: /* original 6bf6, guest PC 0x0c05f306 */
if(!s->budget--) { s->failed_pc=0x0c05f306u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05f308;
P_0c05f308: /* original 6cf6, guest PC 0x0c05f308 */
if(!s->budget--) { s->failed_pc=0x0c05f308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f30a;
P_0c05f30a: /* original 6df6, guest PC 0x0c05f30a */
if(!s->budget--) { s->failed_pc=0x0c05f30au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f30c;
P_0c05f30c: /* original 000b, guest PC 0x0c05f30c */
if(!s->budget--) { s->failed_pc=0x0c05f30cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05f30e: /* original 6ef6, guest PC 0x0c05f30e */
if(!s->budget--) { s->failed_pc=0x0c05f30eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05f310;
P_0c05f310: /* original 4f22, guest PC 0x0c05f310 */
if(!s->budget--) { s->failed_pc=0x0c05f310u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f312;
P_0c05f312: /* original 7404, guest PC 0x0c05f312 */
if(!s->budget--) { s->failed_pc=0x0c05f312u; return 0; }
r[4]+=0x00000004u;
goto P_0c05f314;
P_0c05f314: /* original 7ff4, guest PC 0x0c05f314 */
if(!s->budget--) { s->failed_pc=0x0c05f314u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c05f316;
P_0c05f316: /* original 2f62, guest PC 0x0c05f316 */
if(!s->budget--) { s->failed_pc=0x0c05f316u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05f318;
P_0c05f318: /* original 1f52, guest PC 0x0c05f318 */
if(!s->budget--) { s->failed_pc=0x0c05f318u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c05f31a;
P_0c05f31a: /* original 1f41, guest PC 0x0c05f31a */
if(!s->budget--) { s->failed_pc=0x0c05f31au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05f31c;
P_0c05f31c: /* original 65f2, guest PC 0x0c05f31c */
if(!s->budget--) { s->failed_pc=0x0c05f31cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f31e;
P_0c05f31e: /* original becb, guest PC 0x0c05f31e */
if(!s->budget--) { s->failed_pc=0x0c05f31eu; return 0; }
target=code_base|0x0c05f0b8u; r[16]=code_base|0x0c05f322u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f322u) { target=s->pc; goto dispatch; }
goto P_0c05f322;
P_0c05f320: /* original 6453, guest PC 0x0c05f320 */
if(!s->budget--) { s->failed_pc=0x0c05f320u; return 0; }
r[4]=r[5];
goto P_0c05f322;
P_0c05f322: /* original 6603, guest PC 0x0c05f322 */
if(!s->budget--) { s->failed_pc=0x0c05f322u; return 0; }
r[6]=r[0];
goto P_0c05f324;
P_0c05f324: /* original d31f, guest PC 0x0c05f324 */
if(!s->budget--) { s->failed_pc=0x0c05f324u; return 0; }
r[3]=read(ram,0x0c05f3a4u,4);
goto P_0c05f326;
P_0c05f326: /* original 4608, guest PC 0x0c05f326 */
if(!s->budget--) { s->failed_pc=0x0c05f326u; return 0; }
r[6]<<=2;
goto P_0c05f328;
P_0c05f328: /* original 2f02, guest PC 0x0c05f328 */
if(!s->budget--) { s->failed_pc=0x0c05f328u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05f32a;
P_0c05f32a: /* original d01d, guest PC 0x0c05f32a */
if(!s->budget--) { s->failed_pc=0x0c05f32au; return 0; }
r[0]=read(ram,0x0c05f3a0u,4);
goto P_0c05f32c;
P_0c05f32c: /* original 55f2, guest PC 0x0c05f32c */
if(!s->budget--) { s->failed_pc=0x0c05f32cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c05f32e;
P_0c05f32e: /* original 066e, guest PC 0x0c05f32e */
if(!s->budget--) { s->failed_pc=0x0c05f32eu; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c05f330;
P_0c05f330: /* original 54f1, guest PC 0x0c05f330 */
if(!s->budget--) { s->failed_pc=0x0c05f330u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05f332;
P_0c05f332: /* original 7604, guest PC 0x0c05f332 */
if(!s->budget--) { s->failed_pc=0x0c05f332u; return 0; }
r[6]+=0x00000004u;
goto P_0c05f334;
P_0c05f334: /* original 7f0c, guest PC 0x0c05f334 */
if(!s->budget--) { s->failed_pc=0x0c05f334u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05f336;
P_0c05f336: /* original 432b, guest PC 0x0c05f336 */
if(!s->budget--) { s->failed_pc=0x0c05f336u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c05f338: /* original 4f26, guest PC 0x0c05f338 */
if(!s->budget--) { s->failed_pc=0x0c05f338u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c05f33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f33au; return 0; } return 1;
P_0c05f362: /* original 2fe6, guest PC 0x0c05f362 */
if(!s->budget--) { s->failed_pc=0x0c05f362u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f364;
P_0c05f364: /* original 2fd6, guest PC 0x0c05f364 */
if(!s->budget--) { s->failed_pc=0x0c05f364u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f366;
P_0c05f366: /* original 6e43, guest PC 0x0c05f366 */
if(!s->budget--) { s->failed_pc=0x0c05f366u; return 0; }
r[14]=r[4];
goto P_0c05f368;
P_0c05f368: /* original 2fc6, guest PC 0x0c05f368 */
if(!s->budget--) { s->failed_pc=0x0c05f368u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f36a;
P_0c05f36a: /* original 6d53, guest PC 0x0c05f36a */
if(!s->budget--) { s->failed_pc=0x0c05f36au; return 0; }
r[13]=r[5];
goto P_0c05f36c;
P_0c05f36c: /* original 2fa6, guest PC 0x0c05f36c */
if(!s->budget--) { s->failed_pc=0x0c05f36cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f36e;
P_0c05f36e: /* original 4f22, guest PC 0x0c05f36e */
if(!s->budget--) { s->failed_pc=0x0c05f36eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f370;
P_0c05f370: /* original 7ff8, guest PC 0x0c05f370 */
if(!s->budget--) { s->failed_pc=0x0c05f370u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05f372;
P_0c05f372: /* original 2f62, guest PC 0x0c05f372 */
if(!s->budget--) { s->failed_pc=0x0c05f372u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05f374;
P_0c05f374: /* original 1f71, guest PC 0x0c05f374 */
if(!s->budget--) { s->failed_pc=0x0c05f374u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c05f376;
P_0c05f376: /* original 65f2, guest PC 0x0c05f376 */
if(!s->budget--) { s->failed_pc=0x0c05f376u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f378;
P_0c05f378: /* original be9e, guest PC 0x0c05f378 */
if(!s->budget--) { s->failed_pc=0x0c05f378u; return 0; }
target=code_base|0x0c05f0b8u; r[16]=code_base|0x0c05f37cu;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f37cu) { target=s->pc; goto dispatch; }
goto P_0c05f37c;
P_0c05f37a: /* original 6453, guest PC 0x0c05f37a */
if(!s->budget--) { s->failed_pc=0x0c05f37au; return 0; }
r[4]=r[5];
goto P_0c05f37c;
P_0c05f37c: /* original 6403, guest PC 0x0c05f37c */
if(!s->budget--) { s->failed_pc=0x0c05f37cu; return 0; }
r[4]=r[0];
goto P_0c05f37e;
P_0c05f37e: /* original 6203, guest PC 0x0c05f37e */
if(!s->budget--) { s->failed_pc=0x0c05f37eu; return 0; }
r[2]=r[0];
goto P_0c05f380;
P_0c05f380: /* original 50f1, guest PC 0x0c05f380 */
if(!s->budget--) { s->failed_pc=0x0c05f380u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05f382;
P_0c05f382: /* original c801, guest PC 0x0c05f382 */
if(!s->budget--) { s->failed_pc=0x0c05f382u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05f384;
P_0c05f384: /* original 8d14, guest PC 0x0c05f384 */
if(!s->budget--) { s->failed_pc=0x0c05f384u; return 0; }
cond=r[17]&1u;
r[2]<<=2;
if(cond) { goto P_0c05f3b0; }
goto P_0c05f388;
P_0c05f386: /* original 4208, guest PC 0x0c05f386 */
if(!s->budget--) { s->failed_pc=0x0c05f386u; return 0; }
r[2]<<=2;
goto P_0c05f388;
P_0c05f388: /* original d003, guest PC 0x0c05f388 */
if(!s->budget--) { s->failed_pc=0x0c05f388u; return 0; }
r[0]=read(ram,0x0c05f398u,4);
goto P_0c05f38a;
P_0c05f38a: /* original 0c2e, guest PC 0x0c05f38a */
if(!s->budget--) { s->failed_pc=0x0c05f38au; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f38c;
P_0c05f38c: /* original d007, guest PC 0x0c05f38c */
if(!s->budget--) { s->failed_pc=0x0c05f38cu; return 0; }
r[0]=read(ram,0x0c05f3acu,4);
goto P_0c05f38e;
P_0c05f38e: /* original 0a2e, guest PC 0x0c05f38e */
if(!s->budget--) { s->failed_pc=0x0c05f38eu; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f390;
P_0c05f390: /* original a012, guest PC 0x0c05f390 */
if(!s->budget--) { s->failed_pc=0x0c05f390u; return 0; }
r[10]+=0x0000000au;
goto P_0c05f3b8;
P_0c05f392: /* original 7a0a, guest PC 0x0c05f392 */
if(!s->budget--) { s->failed_pc=0x0c05f392u; return 0; }
r[10]+=0x0000000au;
if(!vf3_matrix_family(0x0c05f394u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f394u; return 0; } return 1;
P_0c05f3b0: /* original d044, guest PC 0x0c05f3b0 */
if(!s->budget--) { s->failed_pc=0x0c05f3b0u; return 0; }
r[0]=read(ram,0x0c05f4c4u,4);
goto P_0c05f3b2;
P_0c05f3b2: /* original 0c2e, guest PC 0x0c05f3b2 */
if(!s->budget--) { s->failed_pc=0x0c05f3b2u; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f3b4;
P_0c05f3b4: /* original d044, guest PC 0x0c05f3b4 */
if(!s->budget--) { s->failed_pc=0x0c05f3b4u; return 0; }
r[0]=read(ram,0x0c05f4c8u,4);
goto P_0c05f3b6;
P_0c05f3b6: /* original 0a2e, guest PC 0x0c05f3b6 */
if(!s->budget--) { s->failed_pc=0x0c05f3b6u; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f3b8;
P_0c05f3b8: /* original d244, guest PC 0x0c05f3b8 */
if(!s->budget--) { s->failed_pc=0x0c05f3b8u; return 0; }
r[2]=read(ram,0x0c05f4ccu,4);
goto P_0c05f3ba;
P_0c05f3ba: /* original 66c3, guest PC 0x0c05f3ba */
if(!s->budget--) { s->failed_pc=0x0c05f3bau; return 0; }
r[6]=r[12];
goto P_0c05f3bc;
P_0c05f3bc: /* original 65d3, guest PC 0x0c05f3bc */
if(!s->budget--) { s->failed_pc=0x0c05f3bcu; return 0; }
r[5]=r[13];
goto P_0c05f3be;
P_0c05f3be: /* original 420b, guest PC 0x0c05f3be */
if(!s->budget--) { s->failed_pc=0x0c05f3beu; return 0; }
target=r[2];
r[16]=code_base|0x0c05f3c2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f3c2u) { target=s->pc; goto dispatch; }
goto P_0c05f3c2;
P_0c05f3c0: /* original 64e3, guest PC 0x0c05f3c0 */
if(!s->budget--) { s->failed_pc=0x0c05f3c0u; return 0; }
r[4]=r[14];
goto P_0c05f3c2;
P_0c05f3c2: /* original 3dcc, guest PC 0x0c05f3c2 */
if(!s->budget--) { s->failed_pc=0x0c05f3c2u; return 0; }
r[13]+=r[12];
goto P_0c05f3c4;
P_0c05f3c4: /* original 937d, guest PC 0x0c05f3c4 */
if(!s->budget--) { s->failed_pc=0x0c05f3c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f4c2u,2);
goto P_0c05f3c6;
P_0c05f3c6: /* original 66a3, guest PC 0x0c05f3c6 */
if(!s->budget--) { s->failed_pc=0x0c05f3c6u; return 0; }
r[6]=r[10];
goto P_0c05f3c8;
P_0c05f3c8: /* original d240, guest PC 0x0c05f3c8 */
if(!s->budget--) { s->failed_pc=0x0c05f3c8u; return 0; }
r[2]=read(ram,0x0c05f4ccu,4);
goto P_0c05f3ca;
P_0c05f3ca: /* original 7f08, guest PC 0x0c05f3ca */
if(!s->budget--) { s->failed_pc=0x0c05f3cau; return 0; }
r[15]+=0x00000008u;
goto P_0c05f3cc;
P_0c05f3cc: /* original 4f26, guest PC 0x0c05f3cc */
if(!s->budget--) { s->failed_pc=0x0c05f3ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f3ce;
P_0c05f3ce: /* original 3e3c, guest PC 0x0c05f3ce */
if(!s->budget--) { s->failed_pc=0x0c05f3ceu; return 0; }
r[14]+=r[3];
goto P_0c05f3d0;
P_0c05f3d0: /* original 6af6, guest PC 0x0c05f3d0 */
if(!s->budget--) { s->failed_pc=0x0c05f3d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05f3d2;
P_0c05f3d2: /* original 65d3, guest PC 0x0c05f3d2 */
if(!s->budget--) { s->failed_pc=0x0c05f3d2u; return 0; }
r[5]=r[13];
goto P_0c05f3d4;
P_0c05f3d4: /* original 6cf6, guest PC 0x0c05f3d4 */
if(!s->budget--) { s->failed_pc=0x0c05f3d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f3d6;
P_0c05f3d6: /* original 64e3, guest PC 0x0c05f3d6 */
if(!s->budget--) { s->failed_pc=0x0c05f3d6u; return 0; }
r[4]=r[14];
goto P_0c05f3d8;
P_0c05f3d8: /* original 6df6, guest PC 0x0c05f3d8 */
if(!s->budget--) { s->failed_pc=0x0c05f3d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f3da;
P_0c05f3da: /* original 422b, guest PC 0x0c05f3da */
if(!s->budget--) { s->failed_pc=0x0c05f3dau; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c05f3dc: /* original 6ef6, guest PC 0x0c05f3dc */
if(!s->budget--) { s->failed_pc=0x0c05f3dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05f3deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f3deu; return 0; } return 1;
P_0c06149e: /* original 6543, guest PC 0x0c06149e */
if(!s->budget--) { s->failed_pc=0x0c06149eu; return 0; }
r[5]=r[4];
goto P_0c0614a0;
P_0c0614a0: /* original d352, guest PC 0x0c0614a0 */
if(!s->budget--) { s->failed_pc=0x0c0614a0u; return 0; }
r[3]=read(ram,0x0c0615ecu,4);
goto P_0c0614a2;
P_0c0614a2: /* original 2fe6, guest PC 0x0c0614a2 */
if(!s->budget--) { s->failed_pc=0x0c0614a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a4;
P_0c0614a4: /* original 2fd6, guest PC 0x0c0614a4 */
if(!s->budget--) { s->failed_pc=0x0c0614a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a6;
P_0c0614a6: /* original 2fc6, guest PC 0x0c0614a6 */
if(!s->budget--) { s->failed_pc=0x0c0614a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a8;
P_0c0614a8: /* original 2fb6, guest PC 0x0c0614a8 */
if(!s->budget--) { s->failed_pc=0x0c0614a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614aa;
P_0c0614aa: /* original 6b43, guest PC 0x0c0614aa */
if(!s->budget--) { s->failed_pc=0x0c0614aau; return 0; }
r[11]=r[4];
goto P_0c0614ac;
P_0c0614ac: /* original 4f22, guest PC 0x0c0614ac */
if(!s->budget--) { s->failed_pc=0x0c0614acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0614ae;
P_0c0614ae: /* original 7fe4, guest PC 0x0c0614ae */
if(!s->budget--) { s->failed_pc=0x0c0614aeu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0614b0;
P_0c0614b0: /* original 64f3, guest PC 0x0c0614b0 */
if(!s->budget--) { s->failed_pc=0x0c0614b0u; return 0; }
r[4]=r[15];
goto P_0c0614b2;
P_0c0614b2: /* original 430b, guest PC 0x0c0614b2 */
if(!s->budget--) { s->failed_pc=0x0c0614b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0614b6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0614b6u) { target=s->pc; goto dispatch; }
goto P_0c0614b6;
P_0c0614b4: /* original 7408, guest PC 0x0c0614b4 */
if(!s->budget--) { s->failed_pc=0x0c0614b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0614b6;
P_0c0614b6: /* original d24e, guest PC 0x0c0614b6 */
if(!s->budget--) { s->failed_pc=0x0c0614b6u; return 0; }
r[2]=read(ram,0x0c0615f0u,4);
goto P_0c0614b8;
P_0c0614b8: /* original 6422, guest PC 0x0c0614b8 */
if(!s->budget--) { s->failed_pc=0x0c0614b8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0614ba;
P_0c0614ba: /* original 2448, guest PC 0x0c0614ba */
if(!s->budget--) { s->failed_pc=0x0c0614bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614bc;
P_0c0614bc: /* original 8d1e, guest PC 0x0c0614bc */
if(!s->budget--) { s->failed_pc=0x0c0614bcu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(cond) { goto P_0c0614fc; }
goto P_0c0614c0;
P_0c0614be: /* original ee00, guest PC 0x0c0614be */
if(!s->budget--) { s->failed_pc=0x0c0614beu; return 0; }
r[14]=0x00000000u;
goto P_0c0614c0;
P_0c0614c0: /* original d74c, guest PC 0x0c0614c0 */
if(!s->budget--) { s->failed_pc=0x0c0614c0u; return 0; }
r[7]=read(ram,0x0c0615f4u,4);
goto P_0c0614c2;
P_0c0614c2: /* original 6241, guest PC 0x0c0614c2 */
if(!s->budget--) { s->failed_pc=0x0c0614c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c0614c4;
P_0c0614c4: /* original 53f2, guest PC 0x0c0614c4 */
if(!s->budget--) { s->failed_pc=0x0c0614c4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0614c6;
P_0c0614c6: /* original 622d, guest PC 0x0c0614c6 */
if(!s->budget--) { s->failed_pc=0x0c0614c6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0614c8;
P_0c0614c8: /* original 2279, guest PC 0x0c0614c8 */
if(!s->budget--) { s->failed_pc=0x0c0614c8u; return 0; }
r[2]&=r[7];
goto P_0c0614ca;
P_0c0614ca: /* original 3230, guest PC 0x0c0614ca */
if(!s->budget--) { s->failed_pc=0x0c0614cau; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0614cc;
P_0c0614cc: /* original 8b11, guest PC 0x0c0614cc */
if(!s->budget--) { s->failed_pc=0x0c0614ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f2; }
goto P_0c0614ce;
P_0c0614ce: /* original e500, guest PC 0x0c0614ce */
if(!s->budget--) { s->failed_pc=0x0c0614ceu; return 0; }
r[5]=0x00000000u;
goto P_0c0614d0;
P_0c0614d0: /* original a00d, guest PC 0x0c0614d0 */
if(!s->budget--) { s->failed_pc=0x0c0614d0u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614ee;
P_0c0614d2: /* original 56f6, guest PC 0x0c0614d2 */
if(!s->budget--) { s->failed_pc=0x0c0614d2u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614d4;
P_0c0614d4: /* original 6253, guest PC 0x0c0614d4 */
if(!s->budget--) { s->failed_pc=0x0c0614d4u; return 0; }
r[2]=r[5];
goto P_0c0614d6;
P_0c0614d6: /* original 4208, guest PC 0x0c0614d6 */
if(!s->budget--) { s->failed_pc=0x0c0614d6u; return 0; }
r[2]<<=2;
goto P_0c0614d8;
P_0c0614d8: /* original 6343, guest PC 0x0c0614d8 */
if(!s->budget--) { s->failed_pc=0x0c0614d8u; return 0; }
r[3]=r[4];
goto P_0c0614da;
P_0c0614da: /* original 730c, guest PC 0x0c0614da */
if(!s->budget--) { s->failed_pc=0x0c0614dau; return 0; }
r[3]+=0x0000000cu;
goto P_0c0614dc;
P_0c0614dc: /* original 323c, guest PC 0x0c0614dc */
if(!s->budget--) { s->failed_pc=0x0c0614dcu; return 0; }
r[2]+=r[3];
goto P_0c0614de;
P_0c0614de: /* original 6122, guest PC 0x0c0614de */
if(!s->budget--) { s->failed_pc=0x0c0614deu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0614e0;
P_0c0614e0: /* original 2118, guest PC 0x0c0614e0 */
if(!s->budget--) { s->failed_pc=0x0c0614e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0614e2;
P_0c0614e2: /* original 8b03, guest PC 0x0c0614e2 */
if(!s->budget--) { s->failed_pc=0x0c0614e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614ec; }
goto P_0c0614e4;
P_0c0614e4: /* original 6e43, guest PC 0x0c0614e4 */
if(!s->budget--) { s->failed_pc=0x0c0614e4u; return 0; }
r[14]=r[4];
goto P_0c0614e6;
P_0c0614e6: /* original 6d53, guest PC 0x0c0614e6 */
if(!s->budget--) { s->failed_pc=0x0c0614e6u; return 0; }
r[13]=r[5];
goto P_0c0614e8;
P_0c0614e8: /* original 6563, guest PC 0x0c0614e8 */
if(!s->budget--) { s->failed_pc=0x0c0614e8u; return 0; }
r[5]=r[6];
goto P_0c0614ea;
P_0c0614ea: /* original e400, guest PC 0x0c0614ea */
if(!s->budget--) { s->failed_pc=0x0c0614eau; return 0; }
r[4]=0x00000000u;
goto P_0c0614ec;
P_0c0614ec: /* original 7501, guest PC 0x0c0614ec */
if(!s->budget--) { s->failed_pc=0x0c0614ecu; return 0; }
r[5]+=0x00000001u;
goto P_0c0614ee;
P_0c0614ee: /* original 3562, guest PC 0x0c0614ee */
if(!s->budget--) { s->failed_pc=0x0c0614eeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c0614f0;
P_0c0614f0: /* original 8bf0, guest PC 0x0c0614f0 */
if(!s->budget--) { s->failed_pc=0x0c0614f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614d4; }
goto P_0c0614f2;
P_0c0614f2: /* original 2ee8, guest PC 0x0c0614f2 */
if(!s->budget--) { s->failed_pc=0x0c0614f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614f4;
P_0c0614f4: /* original 8b00, guest PC 0x0c0614f4 */
if(!s->budget--) { s->failed_pc=0x0c0614f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f8; }
goto P_0c0614f6;
P_0c0614f6: /* original 5441, guest PC 0x0c0614f6 */
if(!s->budget--) { s->failed_pc=0x0c0614f6u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0614f8;
P_0c0614f8: /* original 2448, guest PC 0x0c0614f8 */
if(!s->budget--) { s->failed_pc=0x0c0614f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614fa;
P_0c0614fa: /* original 8be2, guest PC 0x0c0614fa */
if(!s->budget--) { s->failed_pc=0x0c0614fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614c2; }
goto P_0c0614fc;
P_0c0614fc: /* original 2ee8, guest PC 0x0c0614fc */
if(!s->budget--) { s->failed_pc=0x0c0614fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614fe;
P_0c0614fe: /* original 8b32, guest PC 0x0c0614fe */
if(!s->budget--) { s->failed_pc=0x0c0614feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061566; }
goto P_0c061500;
P_0c061500: /* original d33d, guest PC 0x0c061500 */
if(!s->budget--) { s->failed_pc=0x0c061500u; return 0; }
r[3]=read(ram,0x0c0615f8u,4);
goto P_0c061502;
P_0c061502: /* original 430b, guest PC 0x0c061502 */
if(!s->budget--) { s->failed_pc=0x0c061502u; return 0; }
target=r[3];
r[16]=code_base|0x0c061506u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061506u) { target=s->pc; goto dispatch; }
goto P_0c061506;
P_0c061504: /* original 0009, guest PC 0x0c061504 */
if(!s->budget--) { s->failed_pc=0x0c061504u; return 0; }
goto P_0c061506;
P_0c061506: /* original 6e03, guest PC 0x0c061506 */
if(!s->budget--) { s->failed_pc=0x0c061506u; return 0; }
r[14]=r[0];
goto P_0c061508;
P_0c061508: /* original 2ee8, guest PC 0x0c061508 */
if(!s->budget--) { s->failed_pc=0x0c061508u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06150a;
P_0c06150a: /* original 892a, guest PC 0x0c06150a */
if(!s->budget--) { s->failed_pc=0x0c06150au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061562; }
goto P_0c06150c;
P_0c06150c: /* original a001, guest PC 0x0c06150c */
if(!s->budget--) { s->failed_pc=0x0c06150cu; return 0; }
r[4]=0x00000010u;
goto P_0c061512;
P_0c06150e: /* original e410, guest PC 0x0c06150e */
if(!s->budget--) { s->failed_pc=0x0c06150eu; return 0; }
r[4]=0x00000010u;
goto P_0c061510;
P_0c061510: /* original 74ff, guest PC 0x0c061510 */
if(!s->budget--) { s->failed_pc=0x0c061510u; return 0; }
r[4]+=0xffffffffu;
goto P_0c061512;
P_0c061512: /* original 2448, guest PC 0x0c061512 */
if(!s->budget--) { s->failed_pc=0x0c061512u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061514;
P_0c061514: /* original 8bfc, guest PC 0x0c061514 */
if(!s->budget--) { s->failed_pc=0x0c061514u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061510; }
goto P_0c061516;
P_0c061516: /* original ed00, guest PC 0x0c061516 */
if(!s->budget--) { s->failed_pc=0x0c061516u; return 0; }
r[13]=0x00000000u;
goto P_0c061518;
P_0c061518: /* original d435, guest PC 0x0c061518 */
if(!s->budget--) { s->failed_pc=0x0c061518u; return 0; }
r[4]=read(ram,0x0c0615f0u,4);
goto P_0c06151a;
P_0c06151a: /* original d238, guest PC 0x0c06151a */
if(!s->budget--) { s->failed_pc=0x0c06151au; return 0; }
r[2]=read(ram,0x0c0615fcu,4);
goto P_0c06151c;
P_0c06151c: /* original 420b, guest PC 0x0c06151c */
if(!s->budget--) { s->failed_pc=0x0c06151cu; return 0; }
target=r[2];
r[16]=code_base|0x0c061520u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061520u) { target=s->pc; goto dispatch; }
goto P_0c061520;
P_0c06151e: /* original 65e3, guest PC 0x0c06151e */
if(!s->budget--) { s->failed_pc=0x0c06151eu; return 0; }
r[5]=r[14];
goto P_0c061520;
P_0c061520: /* original 53f2, guest PC 0x0c061520 */
if(!s->budget--) { s->failed_pc=0x0c061520u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c061522;
P_0c061522: /* original 62e1, guest PC 0x0c061522 */
if(!s->budget--) { s->failed_pc=0x0c061522u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061524;
P_0c061524: /* original 223b, guest PC 0x0c061524 */
if(!s->budget--) { s->failed_pc=0x0c061524u; return 0; }
r[2]|=r[3];
goto P_0c061526;
P_0c061526: /* original 2e21, guest PC 0x0c061526 */
if(!s->budget--) { s->failed_pc=0x0c061526u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061528;
P_0c061528: /* original 5cf5, guest PC 0x0c061528 */
if(!s->budget--) { s->failed_pc=0x0c061528u; return 0; }
r[12]=read(ram,r[15]+20,4);
goto P_0c06152a;
P_0c06152a: /* original d335, guest PC 0x0c06152a */
if(!s->budget--) { s->failed_pc=0x0c06152au; return 0; }
r[3]=read(ram,0x0c061600u,4);
goto P_0c06152c;
P_0c06152c: /* original 6032, guest PC 0x0c06152c */
if(!s->budget--) { s->failed_pc=0x0c06152cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06152e;
P_0c06152e: /* original c804, guest PC 0x0c06152e */
if(!s->budget--) { s->failed_pc=0x0c06152eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c061530;
P_0c061530: /* original 890d, guest PC 0x0c061530 */
if(!s->budget--) { s->failed_pc=0x0c061530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06154e; }
goto P_0c061532;
P_0c061532: /* original 65f3, guest PC 0x0c061532 */
if(!s->budget--) { s->failed_pc=0x0c061532u; return 0; }
r[5]=r[15];
goto P_0c061534;
P_0c061534: /* original 7504, guest PC 0x0c061534 */
if(!s->budget--) { s->failed_pc=0x0c061534u; return 0; }
r[5]+=0x00000004u;
goto P_0c061536;
P_0c061536: /* original b1eb, guest PC 0x0c061536 */
if(!s->budget--) { s->failed_pc=0x0c061536u; return 0; }
target=code_base|0x0c061910u; r[16]=code_base|0x0c06153au;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06153au) { target=s->pc; goto dispatch; }
goto P_0c06153a;
P_0c061538: /* original 64f3, guest PC 0x0c061538 */
if(!s->budget--) { s->failed_pc=0x0c061538u; return 0; }
r[4]=r[15];
goto P_0c06153a;
P_0c06153a: /* original 53f1, guest PC 0x0c06153a */
if(!s->budget--) { s->failed_pc=0x0c06153au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06153c;
P_0c06153c: /* original 62f2, guest PC 0x0c06153c */
if(!s->budget--) { s->failed_pc=0x0c06153cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06153e;
P_0c06153e: /* original 3233, guest PC 0x0c06153e */
if(!s->budget--) { s->failed_pc=0x0c06153eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c061540;
P_0c061540: /* original 8b05, guest PC 0x0c061540 */
if(!s->budget--) { s->failed_pc=0x0c061540u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06154e; }
goto P_0c061542;
P_0c061542: /* original 66e3, guest PC 0x0c061542 */
if(!s->budget--) { s->failed_pc=0x0c061542u; return 0; }
r[6]=r[14];
goto P_0c061544;
P_0c061544: /* original 65c3, guest PC 0x0c061544 */
if(!s->budget--) { s->failed_pc=0x0c061544u; return 0; }
r[5]=r[12];
goto P_0c061546;
P_0c061546: /* original b5cd, guest PC 0x0c061546 */
if(!s->budget--) { s->failed_pc=0x0c061546u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c06154au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06154au) { target=s->pc; goto dispatch; }
goto P_0c06154a;
P_0c061548: /* original e400, guest PC 0x0c061548 */
if(!s->budget--) { s->failed_pc=0x0c061548u; return 0; }
r[4]=0x00000000u;
goto P_0c06154a;
P_0c06154a: /* original a005, guest PC 0x0c06154a */
if(!s->budget--) { s->failed_pc=0x0c06154au; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c06154c: /* original 6403, guest PC 0x0c06154c */
if(!s->budget--) { s->failed_pc=0x0c06154cu; return 0; }
r[4]=r[0];
goto P_0c06154e;
P_0c06154e: /* original 66e3, guest PC 0x0c06154e */
if(!s->budget--) { s->failed_pc=0x0c06154eu; return 0; }
r[6]=r[14];
goto P_0c061550;
P_0c061550: /* original 65c3, guest PC 0x0c061550 */
if(!s->budget--) { s->failed_pc=0x0c061550u; return 0; }
r[5]=r[12];
goto P_0c061552;
P_0c061552: /* original b5c7, guest PC 0x0c061552 */
if(!s->budget--) { s->failed_pc=0x0c061552u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c061556u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061556u) { target=s->pc; goto dispatch; }
goto P_0c061556;
P_0c061554: /* original e401, guest PC 0x0c061554 */
if(!s->budget--) { s->failed_pc=0x0c061554u; return 0; }
r[4]=0x00000001u;
goto P_0c061556;
P_0c061556: /* original 6403, guest PC 0x0c061556 */
if(!s->budget--) { s->failed_pc=0x0c061556u; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c061558: /* original 2448, guest PC 0x0c061558 */
if(!s->budget--) { s->failed_pc=0x0c061558u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06155a;
P_0c06155a: /* original 8904, guest PC 0x0c06155a */
if(!s->budget--) { s->failed_pc=0x0c06155au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061566; }
goto P_0c06155c;
P_0c06155c: /* original d229, guest PC 0x0c06155c */
if(!s->budget--) { s->failed_pc=0x0c06155cu; return 0; }
r[2]=read(ram,0x0c061604u,4);
goto P_0c06155e;
P_0c06155e: /* original 420b, guest PC 0x0c06155e */
if(!s->budget--) { s->failed_pc=0x0c06155eu; return 0; }
target=r[2];
r[16]=code_base|0x0c061562u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061562u) { target=s->pc; goto dispatch; }
goto P_0c061562;
P_0c061560: /* original 64e3, guest PC 0x0c061560 */
if(!s->budget--) { s->failed_pc=0x0c061560u; return 0; }
r[4]=r[14];
goto P_0c061562;
P_0c061562: /* original a011, guest PC 0x0c061562 */
if(!s->budget--) { s->failed_pc=0x0c061562u; return 0; }
r[0]=0x00000003u;
goto P_0c061588;
P_0c061564: /* original e003, guest PC 0x0c061564 */
if(!s->budget--) { s->failed_pc=0x0c061564u; return 0; }
r[0]=0x00000003u;
goto P_0c061566;
P_0c061566: /* original 53f3, guest PC 0x0c061566 */
if(!s->budget--) { s->failed_pc=0x0c061566u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c061568;
P_0c061568: /* original 52e2, guest PC 0x0c061568 */
if(!s->budget--) { s->failed_pc=0x0c061568u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c06156a;
P_0c06156a: /* original 4309, guest PC 0x0c06156a */
if(!s->budget--) { s->failed_pc=0x0c06156au; return 0; }
r[3]>>=2;
goto P_0c06156c;
P_0c06156c: /* original 0d37, guest PC 0x0c06156c */
if(!s->budget--) { s->failed_pc=0x0c06156cu; return 0; }
r[19]=r[13]*r[3];
goto P_0c06156e;
P_0c06156e: /* original 4d08, guest PC 0x0c06156e */
if(!s->budget--) { s->failed_pc=0x0c06156eu; return 0; }
r[13]<<=2;
goto P_0c061570;
P_0c061570: /* original 031a, guest PC 0x0c061570 */
if(!s->budget--) { s->failed_pc=0x0c061570u; return 0; }
r[3]=r[19];
goto P_0c061572;
P_0c061572: /* original 4308, guest PC 0x0c061572 */
if(!s->budget--) { s->failed_pc=0x0c061572u; return 0; }
r[3]<<=2;
goto P_0c061574;
P_0c061574: /* original 332c, guest PC 0x0c061574 */
if(!s->budget--) { s->failed_pc=0x0c061574u; return 0; }
r[3]+=r[2];
goto P_0c061576;
P_0c061576: /* original 1b37, guest PC 0x0c061576 */
if(!s->budget--) { s->failed_pc=0x0c061576u; return 0; }
write(ram,r[11]+28,r[3],4);
goto P_0c061578;
P_0c061578: /* original 63e3, guest PC 0x0c061578 */
if(!s->budget--) { s->failed_pc=0x0c061578u; return 0; }
r[3]=r[14];
goto P_0c06157a;
P_0c06157a: /* original 730c, guest PC 0x0c06157a */
if(!s->budget--) { s->failed_pc=0x0c06157au; return 0; }
r[3]+=0x0000000cu;
goto P_0c06157c;
P_0c06157c: /* original 3d3c, guest PC 0x0c06157c */
if(!s->budget--) { s->failed_pc=0x0c06157cu; return 0; }
r[13]+=r[3];
goto P_0c06157e;
P_0c06157e: /* original 2db2, guest PC 0x0c06157e */
if(!s->budget--) { s->failed_pc=0x0c06157eu; return 0; }
write(ram,r[13],r[11],4);
goto P_0c061580;
P_0c061580: /* original 60e1, guest PC 0x0c061580 */
if(!s->budget--) { s->failed_pc=0x0c061580u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c061582;
P_0c061582: /* original cb02, guest PC 0x0c061582 */
if(!s->budget--) { s->failed_pc=0x0c061582u; return 0; }
r[0]|=2u;
goto P_0c061584;
P_0c061584: /* original 2e01, guest PC 0x0c061584 */
if(!s->budget--) { s->failed_pc=0x0c061584u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c061586;
P_0c061586: /* original e000, guest PC 0x0c061586 */
if(!s->budget--) { s->failed_pc=0x0c061586u; return 0; }
r[0]=0x00000000u;
goto P_0c061588;
P_0c061588: /* original 7f1c, guest PC 0x0c061588 */
if(!s->budget--) { s->failed_pc=0x0c061588u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06158a;
P_0c06158a: /* original 4f26, guest PC 0x0c06158a */
if(!s->budget--) { s->failed_pc=0x0c06158au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06158c;
P_0c06158c: /* original 6bf6, guest PC 0x0c06158c */
if(!s->budget--) { s->failed_pc=0x0c06158cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06158e;
P_0c06158e: /* original 6cf6, guest PC 0x0c06158e */
if(!s->budget--) { s->failed_pc=0x0c06158eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061590;
P_0c061590: /* original 6df6, guest PC 0x0c061590 */
if(!s->budget--) { s->failed_pc=0x0c061590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061592;
P_0c061592: /* original 000b, guest PC 0x0c061592 */
if(!s->budget--) { s->failed_pc=0x0c061592u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061594: /* original 6ef6, guest PC 0x0c061594 */
if(!s->budget--) { s->failed_pc=0x0c061594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061596u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061596u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
