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
int vf3_away_batch72_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0401a4u: goto P_0c0401a4;
case 0x0c0401a6u: goto P_0c0401a6;
case 0x0c0401a8u: goto P_0c0401a8;
case 0x0c0401aau: goto P_0c0401aa;
case 0x0c0401acu: goto P_0c0401ac;
case 0x0c0401aeu: goto P_0c0401ae;
case 0x0c0401b0u: goto P_0c0401b0;
case 0x0c0401b2u: goto P_0c0401b2;
case 0x0c0401b4u: goto P_0c0401b4;
case 0x0c0401b6u: goto P_0c0401b6;
case 0x0c0401b8u: goto P_0c0401b8;
case 0x0c0401bau: goto P_0c0401ba;
case 0x0c0401bcu: goto P_0c0401bc;
case 0x0c0401beu: goto P_0c0401be;
case 0x0c0401c0u: goto P_0c0401c0;
case 0x0c0401c2u: goto P_0c0401c2;
case 0x0c0401c4u: goto P_0c0401c4;
case 0x0c0401c6u: goto P_0c0401c6;
case 0x0c0401c8u: goto P_0c0401c8;
case 0x0c0401cau: goto P_0c0401ca;
case 0x0c0401ccu: goto P_0c0401cc;
case 0x0c0401ceu: goto P_0c0401ce;
case 0x0c0401d0u: goto P_0c0401d0;
case 0x0c0401d2u: goto P_0c0401d2;
case 0x0c0401d4u: goto P_0c0401d4;
case 0x0c0401d6u: goto P_0c0401d6;
case 0x0c0401d8u: goto P_0c0401d8;
case 0x0c0401dau: goto P_0c0401da;
case 0x0c0401dcu: goto P_0c0401dc;
case 0x0c0401deu: goto P_0c0401de;
case 0x0c0401e0u: goto P_0c0401e0;
case 0x0c0401e2u: goto P_0c0401e2;
case 0x0c0401e4u: goto P_0c0401e4;
case 0x0c0401e6u: goto P_0c0401e6;
case 0x0c0401e8u: goto P_0c0401e8;
case 0x0c0401eau: goto P_0c0401ea;
case 0x0c0401ecu: goto P_0c0401ec;
case 0x0c0401eeu: goto P_0c0401ee;
case 0x0c0401f0u: goto P_0c0401f0;
case 0x0c0401f2u: goto P_0c0401f2;
case 0x0c0401f4u: goto P_0c0401f4;
case 0x0c0401f6u: goto P_0c0401f6;
case 0x0c0401f8u: goto P_0c0401f8;
case 0x0c0401fau: goto P_0c0401fa;
case 0x0c0401fcu: goto P_0c0401fc;
case 0x0c0401feu: goto P_0c0401fe;
case 0x0c040200u: goto P_0c040200;
case 0x0c040202u: goto P_0c040202;
case 0x0c040204u: goto P_0c040204;
case 0x0c040206u: goto P_0c040206;
case 0x0c040222u: goto P_0c040222;
case 0x0c040224u: goto P_0c040224;
case 0x0c040226u: goto P_0c040226;
case 0x0c040228u: goto P_0c040228;
case 0x0c04022au: goto P_0c04022a;
case 0x0c04022cu: goto P_0c04022c;
case 0x0c04022eu: goto P_0c04022e;
case 0x0c040230u: goto P_0c040230;
case 0x0c040232u: goto P_0c040232;
case 0x0c040234u: goto P_0c040234;
case 0x0c040236u: goto P_0c040236;
case 0x0c040238u: goto P_0c040238;
case 0x0c04023au: goto P_0c04023a;
case 0x0c04023cu: goto P_0c04023c;
case 0x0c04023eu: goto P_0c04023e;
case 0x0c040240u: goto P_0c040240;
case 0x0c040242u: goto P_0c040242;
case 0x0c040244u: goto P_0c040244;
case 0x0c040246u: goto P_0c040246;
case 0x0c040248u: goto P_0c040248;
case 0x0c04024au: goto P_0c04024a;
case 0x0c04024cu: goto P_0c04024c;
case 0x0c04024eu: goto P_0c04024e;
case 0x0c040250u: goto P_0c040250;
case 0x0c040252u: goto P_0c040252;
case 0x0c040254u: goto P_0c040254;
case 0x0c040256u: goto P_0c040256;
case 0x0c040258u: goto P_0c040258;
case 0x0c04025au: goto P_0c04025a;
case 0x0c04025cu: goto P_0c04025c;
case 0x0c04025eu: goto P_0c04025e;
case 0x0c040260u: goto P_0c040260;
case 0x0c040262u: goto P_0c040262;
case 0x0c040264u: goto P_0c040264;
case 0x0c040266u: goto P_0c040266;
case 0x0c040268u: goto P_0c040268;
case 0x0c04026au: goto P_0c04026a;
case 0x0c04026cu: goto P_0c04026c;
case 0x0c04026eu: goto P_0c04026e;
case 0x0c040270u: goto P_0c040270;
case 0x0c040272u: goto P_0c040272;
case 0x0c040274u: goto P_0c040274;
case 0x0c040276u: goto P_0c040276;
case 0x0c040288u: goto P_0c040288;
case 0x0c04028au: goto P_0c04028a;
case 0x0c04028cu: goto P_0c04028c;
case 0x0c04028eu: goto P_0c04028e;
case 0x0c040290u: goto P_0c040290;
case 0x0c040292u: goto P_0c040292;
case 0x0c040294u: goto P_0c040294;
case 0x0c040296u: goto P_0c040296;
case 0x0c040298u: goto P_0c040298;
case 0x0c04029au: goto P_0c04029a;
case 0x0c04029cu: goto P_0c04029c;
case 0x0c04029eu: goto P_0c04029e;
case 0x0c0402a0u: goto P_0c0402a0;
case 0x0c0402a2u: goto P_0c0402a2;
case 0x0c0402a4u: goto P_0c0402a4;
case 0x0c0402a6u: goto P_0c0402a6;
case 0x0c0402a8u: goto P_0c0402a8;
case 0x0c0402aau: goto P_0c0402aa;
case 0x0c0402acu: goto P_0c0402ac;
case 0x0c0402aeu: goto P_0c0402ae;
case 0x0c0402b0u: goto P_0c0402b0;
case 0x0c0402b2u: goto P_0c0402b2;
case 0x0c0402b4u: goto P_0c0402b4;
case 0x0c0402b6u: goto P_0c0402b6;
case 0x0c0402b8u: goto P_0c0402b8;
case 0x0c0402bau: goto P_0c0402ba;
case 0x0c0402bcu: goto P_0c0402bc;
case 0x0c0402beu: goto P_0c0402be;
case 0x0c0402c0u: goto P_0c0402c0;
case 0x0c0402c2u: goto P_0c0402c2;
case 0x0c0402c4u: goto P_0c0402c4;
case 0x0c0402c6u: goto P_0c0402c6;
case 0x0c0402c8u: goto P_0c0402c8;
case 0x0c0402cau: goto P_0c0402ca;
case 0x0c0402ccu: goto P_0c0402cc;
case 0x0c0402ceu: goto P_0c0402ce;
case 0x0c0402d0u: goto P_0c0402d0;
case 0x0c0402d2u: goto P_0c0402d2;
case 0x0c0402d4u: goto P_0c0402d4;
case 0x0c0402d6u: goto P_0c0402d6;
case 0x0c0402d8u: goto P_0c0402d8;
case 0x0c0402dau: goto P_0c0402da;
case 0x0c0402dcu: goto P_0c0402dc;
case 0x0c0402deu: goto P_0c0402de;
case 0x0c0402e0u: goto P_0c0402e0;
case 0x0c0402e2u: goto P_0c0402e2;
case 0x0c0402e4u: goto P_0c0402e4;
case 0x0c0402e6u: goto P_0c0402e6;
case 0x0c0402e8u: goto P_0c0402e8;
case 0x0c0402eau: goto P_0c0402ea;
case 0x0c0402ecu: goto P_0c0402ec;
case 0x0c0402eeu: goto P_0c0402ee;
case 0x0c0402f0u: goto P_0c0402f0;
case 0x0c0402f2u: goto P_0c0402f2;
case 0x0c0402f4u: goto P_0c0402f4;
case 0x0c0402f6u: goto P_0c0402f6;
case 0x0c0402f8u: goto P_0c0402f8;
case 0x0c040308u: goto P_0c040308;
case 0x0c04030au: goto P_0c04030a;
case 0x0c04030cu: goto P_0c04030c;
case 0x0c04030eu: goto P_0c04030e;
case 0x0c040310u: goto P_0c040310;
case 0x0c040312u: goto P_0c040312;
case 0x0c040314u: goto P_0c040314;
case 0x0c040316u: goto P_0c040316;
case 0x0c040318u: goto P_0c040318;
case 0x0c04031au: goto P_0c04031a;
case 0x0c04031cu: goto P_0c04031c;
case 0x0c04031eu: goto P_0c04031e;
case 0x0c040320u: goto P_0c040320;
case 0x0c040322u: goto P_0c040322;
case 0x0c040324u: goto P_0c040324;
case 0x0c040326u: goto P_0c040326;
case 0x0c040328u: goto P_0c040328;
case 0x0c04032au: goto P_0c04032a;
case 0x0c04032cu: goto P_0c04032c;
case 0x0c04032eu: goto P_0c04032e;
case 0x0c040330u: goto P_0c040330;
case 0x0c040332u: goto P_0c040332;
case 0x0c040334u: goto P_0c040334;
case 0x0c040336u: goto P_0c040336;
case 0x0c040338u: goto P_0c040338;
case 0x0c04033au: goto P_0c04033a;
case 0x0c04033cu: goto P_0c04033c;
case 0x0c04033eu: goto P_0c04033e;
case 0x0c040340u: goto P_0c040340;
case 0x0c040342u: goto P_0c040342;
case 0x0c040344u: goto P_0c040344;
case 0x0c040346u: goto P_0c040346;
case 0x0c040348u: goto P_0c040348;
case 0x0c04034au: goto P_0c04034a;
case 0x0c04034cu: goto P_0c04034c;
case 0x0c04034eu: goto P_0c04034e;
case 0x0c040350u: goto P_0c040350;
case 0x0c040352u: goto P_0c040352;
case 0x0c040354u: goto P_0c040354;
case 0x0c040356u: goto P_0c040356;
case 0x0c040358u: goto P_0c040358;
case 0x0c04035au: goto P_0c04035a;
case 0x0c04035cu: goto P_0c04035c;
case 0x0c04035eu: goto P_0c04035e;
case 0x0c040360u: goto P_0c040360;
case 0x0c040362u: goto P_0c040362;
case 0x0c040378u: goto P_0c040378;
case 0x0c04037au: goto P_0c04037a;
case 0x0c04037cu: goto P_0c04037c;
case 0x0c04037eu: goto P_0c04037e;
case 0x0c040380u: goto P_0c040380;
case 0x0c040382u: goto P_0c040382;
case 0x0c040384u: goto P_0c040384;
case 0x0c040386u: goto P_0c040386;
case 0x0c040388u: goto P_0c040388;
case 0x0c04038au: goto P_0c04038a;
case 0x0c04038cu: goto P_0c04038c;
case 0x0c04038eu: goto P_0c04038e;
case 0x0c040390u: goto P_0c040390;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0401a4: /* original 52f3, guest PC 0x0c0401a4 */
if(!s->budget--) { s->failed_pc=0x0c0401a4u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0401a6;
P_0c0401a6: /* original 7201, guest PC 0x0c0401a6 */
if(!s->budget--) { s->failed_pc=0x0c0401a6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0401a8;
P_0c0401a8: /* original 1f23, guest PC 0x0c0401a8 */
if(!s->budget--) { s->failed_pc=0x0c0401a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0401aa;
P_0c0401aa: /* original e304, guest PC 0x0c0401aa */
if(!s->budget--) { s->failed_pc=0x0c0401aau; return 0; }
r[3]=0x00000004u;
goto P_0c0401ac;
P_0c0401ac: /* original 51f3, guest PC 0x0c0401ac */
if(!s->budget--) { s->failed_pc=0x0c0401acu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0401ae;
P_0c0401ae: /* original 3133, guest PC 0x0c0401ae */
if(!s->budget--) { s->failed_pc=0x0c0401aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0401b0;
P_0c0401b0: /* original 8be8, guest PC 0x0c0401b0 */
if(!s->budget--) { s->failed_pc=0x0c0401b0u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c040184u,s,ram); }
goto P_0c0401b2;
P_0c0401b2: /* original 50f6, guest PC 0x0c0401b2 */
if(!s->budget--) { s->failed_pc=0x0c0401b2u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0401b4;
P_0c0401b4: /* original 6303, guest PC 0x0c0401b4 */
if(!s->budget--) { s->failed_pc=0x0c0401b4u; return 0; }
r[3]=r[0];
goto P_0c0401b6;
P_0c0401b6: /* original 4000, guest PC 0x0c0401b6 */
if(!s->budget--) { s->failed_pc=0x0c0401b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0401b8;
P_0c0401b8: /* original 303c, guest PC 0x0c0401b8 */
if(!s->budget--) { s->failed_pc=0x0c0401b8u; return 0; }
r[0]+=r[3];
goto P_0c0401ba;
P_0c0401ba: /* original 4008, guest PC 0x0c0401ba */
if(!s->budget--) { s->failed_pc=0x0c0401bau; return 0; }
r[0]<<=2;
goto P_0c0401bc;
P_0c0401bc: /* original 600e, guest PC 0x0c0401bc */
if(!s->budget--) { s->failed_pc=0x0c0401bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0401be;
P_0c0401be: /* original d113, guest PC 0x0c0401be */
if(!s->budget--) { s->failed_pc=0x0c0401beu; return 0; }
r[1]=read(ram,0x0c04020cu,4);
goto P_0c0401c0;
P_0c0401c0: /* original 001e, guest PC 0x0c0401c0 */
if(!s->budget--) { s->failed_pc=0x0c0401c0u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0401c2;
P_0c0401c2: /* original 88ff, guest PC 0x0c0401c2 */
if(!s->budget--) { s->failed_pc=0x0c0401c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0401c4;
P_0c0401c4: /* original 8903, guest PC 0x0c0401c4 */
if(!s->budget--) { s->failed_pc=0x0c0401c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0401ce; }
goto P_0c0401c6;
P_0c0401c6: /* original e0fd, guest PC 0x0c0401c6 */
if(!s->budget--) { s->failed_pc=0x0c0401c6u; return 0; }
r[0]=0xfffffffdu;
goto P_0c0401c8;
P_0c0401c8: /* original 7f20, guest PC 0x0c0401c8 */
if(!s->budget--) { s->failed_pc=0x0c0401c8u; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ca;
P_0c0401ca: /* original 000b, guest PC 0x0c0401ca */
if(!s->budget--) { s->failed_pc=0x0c0401cau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401cc: /* original 0009, guest PC 0x0c0401cc */
if(!s->budget--) { s->failed_pc=0x0c0401ccu; return 0; }
goto P_0c0401ce;
P_0c0401ce: /* original 52f7, guest PC 0x0c0401ce */
if(!s->budget--) { s->failed_pc=0x0c0401ceu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0401d0;
P_0c0401d0: /* original 5322, guest PC 0x0c0401d0 */
if(!s->budget--) { s->failed_pc=0x0c0401d0u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0401d2;
P_0c0401d2: /* original 1f34, guest PC 0x0c0401d2 */
if(!s->budget--) { s->failed_pc=0x0c0401d2u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0401d4;
P_0c0401d4: /* original d30e, guest PC 0x0c0401d4 */
if(!s->budget--) { s->failed_pc=0x0c0401d4u; return 0; }
r[3]=read(ram,0x0c040210u,4);
goto P_0c0401d6;
P_0c0401d6: /* original 6132, guest PC 0x0c0401d6 */
if(!s->budget--) { s->failed_pc=0x0c0401d6u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0401d8;
P_0c0401d8: /* original 1f15, guest PC 0x0c0401d8 */
if(!s->budget--) { s->failed_pc=0x0c0401d8u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0401da;
P_0c0401da: /* original 51f4, guest PC 0x0c0401da */
if(!s->budget--) { s->failed_pc=0x0c0401dau; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0401dc;
P_0c0401dc: /* original d20d, guest PC 0x0c0401dc */
if(!s->budget--) { s->failed_pc=0x0c0401dcu; return 0; }
r[2]=read(ram,0x0c040214u,4);
goto P_0c0401de;
P_0c0401de: /* original 6022, guest PC 0x0c0401de */
if(!s->budget--) { s->failed_pc=0x0c0401deu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0401e0;
P_0c0401e0: /* original 301c, guest PC 0x0c0401e0 */
if(!s->budget--) { s->failed_pc=0x0c0401e0u; return 0; }
r[0]+=r[1];
goto P_0c0401e2;
P_0c0401e2: /* original 52f5, guest PC 0x0c0401e2 */
if(!s->budget--) { s->failed_pc=0x0c0401e2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0401e4;
P_0c0401e4: /* original 3027, guest PC 0x0c0401e4 */
if(!s->budget--) { s->failed_pc=0x0c0401e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c0401e6;
P_0c0401e6: /* original 8b03, guest PC 0x0c0401e6 */
if(!s->budget--) { s->failed_pc=0x0c0401e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0401f0; }
goto P_0c0401e8;
P_0c0401e8: /* original e0fc, guest PC 0x0c0401e8 */
if(!s->budget--) { s->failed_pc=0x0c0401e8u; return 0; }
r[0]=0xfffffffcu;
goto P_0c0401ea;
P_0c0401ea: /* original 7f20, guest PC 0x0c0401ea */
if(!s->budget--) { s->failed_pc=0x0c0401eau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401ec;
P_0c0401ec: /* original 000b, guest PC 0x0c0401ec */
if(!s->budget--) { s->failed_pc=0x0c0401ecu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401ee: /* original 0009, guest PC 0x0c0401ee */
if(!s->budget--) { s->failed_pc=0x0c0401eeu; return 0; }
goto P_0c0401f0;
P_0c0401f0: /* original d209, guest PC 0x0c0401f0 */
if(!s->budget--) { s->failed_pc=0x0c0401f0u; return 0; }
r[2]=read(ram,0x0c040218u,4);
goto P_0c0401f2;
P_0c0401f2: /* original 6322, guest PC 0x0c0401f2 */
if(!s->budget--) { s->failed_pc=0x0c0401f2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0401f4;
P_0c0401f4: /* original 2338, guest PC 0x0c0401f4 */
if(!s->budget--) { s->failed_pc=0x0c0401f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0401f6;
P_0c0401f6: /* original 8903, guest PC 0x0c0401f6 */
if(!s->budget--) { s->failed_pc=0x0c0401f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040200; }
goto P_0c0401f8;
P_0c0401f8: /* original e0fb, guest PC 0x0c0401f8 */
if(!s->budget--) { s->failed_pc=0x0c0401f8u; return 0; }
r[0]=0xfffffffbu;
goto P_0c0401fa;
P_0c0401fa: /* original 7f20, guest PC 0x0c0401fa */
if(!s->budget--) { s->failed_pc=0x0c0401fau; return 0; }
r[15]+=0x00000020u;
goto P_0c0401fc;
P_0c0401fc: /* original 000b, guest PC 0x0c0401fc */
if(!s->budget--) { s->failed_pc=0x0c0401fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0401fe: /* original 0009, guest PC 0x0c0401fe */
if(!s->budget--) { s->failed_pc=0x0c0401feu; return 0; }
goto P_0c040200;
P_0c040200: /* original e000, guest PC 0x0c040200 */
if(!s->budget--) { s->failed_pc=0x0c040200u; return 0; }
r[0]=0x00000000u;
goto P_0c040202;
P_0c040202: /* original 7f20, guest PC 0x0c040202 */
if(!s->budget--) { s->failed_pc=0x0c040202u; return 0; }
r[15]+=0x00000020u;
goto P_0c040204;
P_0c040204: /* original 000b, guest PC 0x0c040204 */
if(!s->budget--) { s->failed_pc=0x0c040204u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040206: /* original 0009, guest PC 0x0c040206 */
if(!s->budget--) { s->failed_pc=0x0c040206u; return 0; }
if(!vf3_matrix_family(0x0c040208u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040208u; return 0; } return 1;
P_0c040222: /* original 7fe4, guest PC 0x0c040222 */
if(!s->budget--) { s->failed_pc=0x0c040222u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c040224;
P_0c040224: /* original 1f46, guest PC 0x0c040224 */
if(!s->budget--) { s->failed_pc=0x0c040224u; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c040226;
P_0c040226: /* original 1f55, guest PC 0x0c040226 */
if(!s->budget--) { s->failed_pc=0x0c040226u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c040228;
P_0c040228: /* original 1f64, guest PC 0x0c040228 */
if(!s->budget--) { s->failed_pc=0x0c040228u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c04022a;
P_0c04022a: /* original 1f73, guest PC 0x0c04022a */
if(!s->budget--) { s->failed_pc=0x0c04022au; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c04022c;
P_0c04022c: /* original d312, guest PC 0x0c04022c */
if(!s->budget--) { s->failed_pc=0x0c04022cu; return 0; }
r[3]=read(ram,0x0c040278u,4);
goto P_0c04022e;
P_0c04022e: /* original 52f4, guest PC 0x0c04022e */
if(!s->budget--) { s->failed_pc=0x0c04022eu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c040230;
P_0c040230: /* original 6132, guest PC 0x0c040230 */
if(!s->budget--) { s->failed_pc=0x0c040230u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040232;
P_0c040232: /* original 312c, guest PC 0x0c040232 */
if(!s->budget--) { s->failed_pc=0x0c040232u; return 0; }
r[1]+=r[2];
goto P_0c040234;
P_0c040234: /* original 2312, guest PC 0x0c040234 */
if(!s->budget--) { s->failed_pc=0x0c040234u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040236;
P_0c040236: /* original 53f6, guest PC 0x0c040236 */
if(!s->budget--) { s->failed_pc=0x0c040236u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c040238;
P_0c040238: /* original 6033, guest PC 0x0c040238 */
if(!s->budget--) { s->failed_pc=0x0c040238u; return 0; }
r[0]=r[3];
goto P_0c04023a;
P_0c04023a: /* original 0009, guest PC 0x0c04023a */
if(!s->budget--) { s->failed_pc=0x0c04023au; return 0; }
goto P_0c04023c;
P_0c04023c: /* original 4300, guest PC 0x0c04023c */
if(!s->budget--) { s->failed_pc=0x0c04023cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c04023e;
P_0c04023e: /* original 330c, guest PC 0x0c04023e */
if(!s->budget--) { s->failed_pc=0x0c04023eu; return 0; }
r[3]+=r[0];
goto P_0c040240;
P_0c040240: /* original 4308, guest PC 0x0c040240 */
if(!s->budget--) { s->failed_pc=0x0c040240u; return 0; }
r[3]<<=2;
goto P_0c040242;
P_0c040242: /* original 633e, guest PC 0x0c040242 */
if(!s->budget--) { s->failed_pc=0x0c040242u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040244;
P_0c040244: /* original 52f5, guest PC 0x0c040244 */
if(!s->budget--) { s->failed_pc=0x0c040244u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c040246;
P_0c040246: /* original d00d, guest PC 0x0c040246 */
if(!s->budget--) { s->failed_pc=0x0c040246u; return 0; }
r[0]=read(ram,0x0c04027cu,4);
goto P_0c040248;
P_0c040248: /* original 0326, guest PC 0x0c040248 */
if(!s->budget--) { s->failed_pc=0x0c040248u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c04024a;
P_0c04024a: /* original 53f6, guest PC 0x0c04024a */
if(!s->budget--) { s->failed_pc=0x0c04024au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04024c;
P_0c04024c: /* original 6233, guest PC 0x0c04024c */
if(!s->budget--) { s->failed_pc=0x0c04024cu; return 0; }
r[2]=r[3];
goto P_0c04024e;
P_0c04024e: /* original 4300, guest PC 0x0c04024e */
if(!s->budget--) { s->failed_pc=0x0c04024eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c040250;
P_0c040250: /* original 332c, guest PC 0x0c040250 */
if(!s->budget--) { s->failed_pc=0x0c040250u; return 0; }
r[3]+=r[2];
goto P_0c040252;
P_0c040252: /* original 4308, guest PC 0x0c040252 */
if(!s->budget--) { s->failed_pc=0x0c040252u; return 0; }
r[3]<<=2;
goto P_0c040254;
P_0c040254: /* original 633e, guest PC 0x0c040254 */
if(!s->budget--) { s->failed_pc=0x0c040254u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c040256;
P_0c040256: /* original 51f4, guest PC 0x0c040256 */
if(!s->budget--) { s->failed_pc=0x0c040256u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c040258;
P_0c040258: /* original d009, guest PC 0x0c040258 */
if(!s->budget--) { s->failed_pc=0x0c040258u; return 0; }
r[0]=read(ram,0x0c040280u,4);
goto P_0c04025a;
P_0c04025a: /* original 0316, guest PC 0x0c04025a */
if(!s->budget--) { s->failed_pc=0x0c04025au; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c04025c;
P_0c04025c: /* original 53f6, guest PC 0x0c04025c */
if(!s->budget--) { s->failed_pc=0x0c04025cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04025e;
P_0c04025e: /* original 4308, guest PC 0x0c04025e */
if(!s->budget--) { s->failed_pc=0x0c04025eu; return 0; }
r[3]<<=2;
goto P_0c040260;
P_0c040260: /* original d208, guest PC 0x0c040260 */
if(!s->budget--) { s->failed_pc=0x0c040260u; return 0; }
r[2]=read(ram,0x0c040284u,4);
goto P_0c040262;
P_0c040262: /* original 332c, guest PC 0x0c040262 */
if(!s->budget--) { s->failed_pc=0x0c040262u; return 0; }
r[3]+=r[2];
goto P_0c040264;
P_0c040264: /* original 51f5, guest PC 0x0c040264 */
if(!s->budget--) { s->failed_pc=0x0c040264u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c040266;
P_0c040266: /* original 2312, guest PC 0x0c040266 */
if(!s->budget--) { s->failed_pc=0x0c040266u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c040268;
P_0c040268: /* original e300, guest PC 0x0c040268 */
if(!s->budget--) { s->failed_pc=0x0c040268u; return 0; }
r[3]=0x00000000u;
goto P_0c04026a;
P_0c04026a: /* original 1f32, guest PC 0x0c04026a */
if(!s->budget--) { s->failed_pc=0x0c04026au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04026c;
P_0c04026c: /* original 2f32, guest PC 0x0c04026c */
if(!s->budget--) { s->failed_pc=0x0c04026cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04026e;
P_0c04026e: /* original 51f6, guest PC 0x0c04026e */
if(!s->budget--) { s->failed_pc=0x0c04026eu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c040270;
P_0c040270: /* original 71ff, guest PC 0x0c040270 */
if(!s->budget--) { s->failed_pc=0x0c040270u; return 0; }
r[1]+=0xffffffffu;
goto P_0c040272;
P_0c040272: /* original 1f11, guest PC 0x0c040272 */
if(!s->budget--) { s->failed_pc=0x0c040272u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c040274;
P_0c040274: /* original a02a, guest PC 0x0c040274 */
if(!s->budget--) { s->failed_pc=0x0c040274u; return 0; }
goto P_0c0402cc;
P_0c040276: /* original 0009, guest PC 0x0c040276 */
if(!s->budget--) { s->failed_pc=0x0c040276u; return 0; }
if(!vf3_matrix_family(0x0c040278u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040278u; return 0; } return 1;
P_0c040288: /* original 84f4, guest PC 0x0c040288 */
if(!s->budget--) { s->failed_pc=0x0c040288u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04028a;
P_0c04028a: /* original 6303, guest PC 0x0c04028a */
if(!s->budget--) { s->failed_pc=0x0c04028au; return 0; }
r[3]=r[0];
goto P_0c04028c;
P_0c04028c: /* original 4000, guest PC 0x0c04028c */
if(!s->budget--) { s->failed_pc=0x0c04028cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04028e;
P_0c04028e: /* original 303c, guest PC 0x0c04028e */
if(!s->budget--) { s->failed_pc=0x0c04028eu; return 0; }
r[0]+=r[3];
goto P_0c040290;
P_0c040290: /* original 4008, guest PC 0x0c040290 */
if(!s->budget--) { s->failed_pc=0x0c040290u; return 0; }
r[0]<<=2;
goto P_0c040292;
P_0c040292: /* original 600e, guest PC 0x0c040292 */
if(!s->budget--) { s->failed_pc=0x0c040292u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040294;
P_0c040294: /* original d119, guest PC 0x0c040294 */
if(!s->budget--) { s->failed_pc=0x0c040294u; return 0; }
r[1]=read(ram,0x0c0402fcu,4);
goto P_0c040296;
P_0c040296: /* original 001e, guest PC 0x0c040296 */
if(!s->budget--) { s->failed_pc=0x0c040296u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040298;
P_0c040298: /* original 88ff, guest PC 0x0c040298 */
if(!s->budget--) { s->failed_pc=0x0c040298u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04029a;
P_0c04029a: /* original 8914, guest PC 0x0c04029a */
if(!s->budget--) { s->failed_pc=0x0c04029au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0402c6; }
goto P_0c04029c;
P_0c04029c: /* original 52f1, guest PC 0x0c04029c */
if(!s->budget--) { s->failed_pc=0x0c04029cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04029e;
P_0c04029e: /* original 6323, guest PC 0x0c04029e */
if(!s->budget--) { s->failed_pc=0x0c04029eu; return 0; }
r[3]=r[2];
goto P_0c0402a0;
P_0c0402a0: /* original 4200, guest PC 0x0c0402a0 */
if(!s->budget--) { s->failed_pc=0x0c0402a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0402a2;
P_0c0402a2: /* original 323c, guest PC 0x0c0402a2 */
if(!s->budget--) { s->failed_pc=0x0c0402a2u; return 0; }
r[2]+=r[3];
goto P_0c0402a4;
P_0c0402a4: /* original 4208, guest PC 0x0c0402a4 */
if(!s->budget--) { s->failed_pc=0x0c0402a4u; return 0; }
r[2]<<=2;
goto P_0c0402a6;
P_0c0402a6: /* original 622e, guest PC 0x0c0402a6 */
if(!s->budget--) { s->failed_pc=0x0c0402a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0402a8;
P_0c0402a8: /* original 50f1, guest PC 0x0c0402a8 */
if(!s->budget--) { s->failed_pc=0x0c0402a8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0402aa;
P_0c0402aa: /* original 6303, guest PC 0x0c0402aa */
if(!s->budget--) { s->failed_pc=0x0c0402aau; return 0; }
r[3]=r[0];
goto P_0c0402ac;
P_0c0402ac: /* original 4000, guest PC 0x0c0402ac */
if(!s->budget--) { s->failed_pc=0x0c0402acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0402ae;
P_0c0402ae: /* original 303c, guest PC 0x0c0402ae */
if(!s->budget--) { s->failed_pc=0x0c0402aeu; return 0; }
r[0]+=r[3];
goto P_0c0402b0;
P_0c0402b0: /* original 4008, guest PC 0x0c0402b0 */
if(!s->budget--) { s->failed_pc=0x0c0402b0u; return 0; }
r[0]<<=2;
goto P_0c0402b2;
P_0c0402b2: /* original 600e, guest PC 0x0c0402b2 */
if(!s->budget--) { s->failed_pc=0x0c0402b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0402b4;
P_0c0402b4: /* original 6313, guest PC 0x0c0402b4 */
if(!s->budget--) { s->failed_pc=0x0c0402b4u; return 0; }
r[3]=r[1];
goto P_0c0402b6;
P_0c0402b6: /* original 303c, guest PC 0x0c0402b6 */
if(!s->budget--) { s->failed_pc=0x0c0402b6u; return 0; }
r[0]+=r[3];
goto P_0c0402b8;
P_0c0402b8: /* original 5302, guest PC 0x0c0402b8 */
if(!s->budget--) { s->failed_pc=0x0c0402b8u; return 0; }
r[3]=read(ram,r[0]+8,4);
goto P_0c0402ba;
P_0c0402ba: /* original d011, guest PC 0x0c0402ba */
if(!s->budget--) { s->failed_pc=0x0c0402bau; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402bc;
P_0c0402bc: /* original 022e, guest PC 0x0c0402bc */
if(!s->budget--) { s->failed_pc=0x0c0402bcu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c0402be;
P_0c0402be: /* original 323c, guest PC 0x0c0402be */
if(!s->budget--) { s->failed_pc=0x0c0402beu; return 0; }
r[2]+=r[3];
goto P_0c0402c0;
P_0c0402c0: /* original 2f22, guest PC 0x0c0402c0 */
if(!s->budget--) { s->failed_pc=0x0c0402c0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402c2;
P_0c0402c2: /* original a006, guest PC 0x0c0402c2 */
if(!s->budget--) { s->failed_pc=0x0c0402c2u; return 0; }
goto P_0c0402d2;
P_0c0402c4: /* original 0009, guest PC 0x0c0402c4 */
if(!s->budget--) { s->failed_pc=0x0c0402c4u; return 0; }
goto P_0c0402c6;
P_0c0402c6: /* original 51f1, guest PC 0x0c0402c6 */
if(!s->budget--) { s->failed_pc=0x0c0402c6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0402c8;
P_0c0402c8: /* original 71ff, guest PC 0x0c0402c8 */
if(!s->budget--) { s->failed_pc=0x0c0402c8u; return 0; }
r[1]+=0xffffffffu;
goto P_0c0402ca;
P_0c0402ca: /* original 1f11, guest PC 0x0c0402ca */
if(!s->budget--) { s->failed_pc=0x0c0402cau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0402cc;
P_0c0402cc: /* original 53f1, guest PC 0x0c0402cc */
if(!s->budget--) { s->failed_pc=0x0c0402ccu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0402ce;
P_0c0402ce: /* original 4311, guest PC 0x0c0402ce */
if(!s->budget--) { s->failed_pc=0x0c0402ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0402d0;
P_0c0402d0: /* original 89da, guest PC 0x0c0402d0 */
if(!s->budget--) { s->failed_pc=0x0c0402d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040288; }
goto P_0c0402d2;
P_0c0402d2: /* original 61f2, guest PC 0x0c0402d2 */
if(!s->budget--) { s->failed_pc=0x0c0402d2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402d4;
P_0c0402d4: /* original 2118, guest PC 0x0c0402d4 */
if(!s->budget--) { s->failed_pc=0x0c0402d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0402d6;
P_0c0402d6: /* original 8b02, guest PC 0x0c0402d6 */
if(!s->budget--) { s->failed_pc=0x0c0402d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0402de; }
goto P_0c0402d8;
P_0c0402d8: /* original d10a, guest PC 0x0c0402d8 */
if(!s->budget--) { s->failed_pc=0x0c0402d8u; return 0; }
r[1]=read(ram,0x0c040304u,4);
goto P_0c0402da;
P_0c0402da: /* original 6212, guest PC 0x0c0402da */
if(!s->budget--) { s->failed_pc=0x0c0402dau; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0402dc;
P_0c0402dc: /* original 2f22, guest PC 0x0c0402dc */
if(!s->budget--) { s->failed_pc=0x0c0402dcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0402de;
P_0c0402de: /* original 53f6, guest PC 0x0c0402de */
if(!s->budget--) { s->failed_pc=0x0c0402deu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402e0;
P_0c0402e0: /* original 6233, guest PC 0x0c0402e0 */
if(!s->budget--) { s->failed_pc=0x0c0402e0u; return 0; }
r[2]=r[3];
goto P_0c0402e2;
P_0c0402e2: /* original 4300, guest PC 0x0c0402e2 */
if(!s->budget--) { s->failed_pc=0x0c0402e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0402e4;
P_0c0402e4: /* original 332c, guest PC 0x0c0402e4 */
if(!s->budget--) { s->failed_pc=0x0c0402e4u; return 0; }
r[3]+=r[2];
goto P_0c0402e6;
P_0c0402e6: /* original 4308, guest PC 0x0c0402e6 */
if(!s->budget--) { s->failed_pc=0x0c0402e6u; return 0; }
r[3]<<=2;
goto P_0c0402e8;
P_0c0402e8: /* original 633e, guest PC 0x0c0402e8 */
if(!s->budget--) { s->failed_pc=0x0c0402e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[3];
goto P_0c0402ea;
P_0c0402ea: /* original 61f2, guest PC 0x0c0402ea */
if(!s->budget--) { s->failed_pc=0x0c0402eau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0402ec;
P_0c0402ec: /* original d004, guest PC 0x0c0402ec */
if(!s->budget--) { s->failed_pc=0x0c0402ecu; return 0; }
r[0]=read(ram,0x0c040300u,4);
goto P_0c0402ee;
P_0c0402ee: /* original 0316, guest PC 0x0c0402ee */
if(!s->budget--) { s->failed_pc=0x0c0402eeu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c0402f0;
P_0c0402f0: /* original 53f6, guest PC 0x0c0402f0 */
if(!s->budget--) { s->failed_pc=0x0c0402f0u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0402f2;
P_0c0402f2: /* original 7301, guest PC 0x0c0402f2 */
if(!s->budget--) { s->failed_pc=0x0c0402f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c0402f4;
P_0c0402f4: /* original 1f31, guest PC 0x0c0402f4 */
if(!s->budget--) { s->failed_pc=0x0c0402f4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0402f6;
P_0c0402f6: /* original a02a, guest PC 0x0c0402f6 */
if(!s->budget--) { s->failed_pc=0x0c0402f6u; return 0; }
goto P_0c04034e;
P_0c0402f8: /* original 0009, guest PC 0x0c0402f8 */
if(!s->budget--) { s->failed_pc=0x0c0402f8u; return 0; }
if(!vf3_matrix_family(0x0c0402fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0402fau; return 0; } return 1;
P_0c040308: /* original 84f4, guest PC 0x0c040308 */
if(!s->budget--) { s->failed_pc=0x0c040308u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c04030a;
P_0c04030a: /* original 6303, guest PC 0x0c04030a */
if(!s->budget--) { s->failed_pc=0x0c04030au; return 0; }
r[3]=r[0];
goto P_0c04030c;
P_0c04030c: /* original 4000, guest PC 0x0c04030c */
if(!s->budget--) { s->failed_pc=0x0c04030cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04030e;
P_0c04030e: /* original 303c, guest PC 0x0c04030e */
if(!s->budget--) { s->failed_pc=0x0c04030eu; return 0; }
r[0]+=r[3];
goto P_0c040310;
P_0c040310: /* original 4008, guest PC 0x0c040310 */
if(!s->budget--) { s->failed_pc=0x0c040310u; return 0; }
r[0]<<=2;
goto P_0c040312;
P_0c040312: /* original 600e, guest PC 0x0c040312 */
if(!s->budget--) { s->failed_pc=0x0c040312u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c040314;
P_0c040314: /* original d115, guest PC 0x0c040314 */
if(!s->budget--) { s->failed_pc=0x0c040314u; return 0; }
r[1]=read(ram,0x0c04036cu,4);
goto P_0c040316;
P_0c040316: /* original 001e, guest PC 0x0c040316 */
if(!s->budget--) { s->failed_pc=0x0c040316u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c040318;
P_0c040318: /* original 88ff, guest PC 0x0c040318 */
if(!s->budget--) { s->failed_pc=0x0c040318u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04031a;
P_0c04031a: /* original 8915, guest PC 0x0c04031a */
if(!s->budget--) { s->failed_pc=0x0c04031au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040348; }
goto P_0c04031c;
P_0c04031c: /* original 52f1, guest PC 0x0c04031c */
if(!s->budget--) { s->failed_pc=0x0c04031cu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04031e;
P_0c04031e: /* original 6323, guest PC 0x0c04031e */
if(!s->budget--) { s->failed_pc=0x0c04031eu; return 0; }
r[3]=r[2];
goto P_0c040320;
P_0c040320: /* original 4200, guest PC 0x0c040320 */
if(!s->budget--) { s->failed_pc=0x0c040320u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040322;
P_0c040322: /* original 323c, guest PC 0x0c040322 */
if(!s->budget--) { s->failed_pc=0x0c040322u; return 0; }
r[2]+=r[3];
goto P_0c040324;
P_0c040324: /* original 4208, guest PC 0x0c040324 */
if(!s->budget--) { s->failed_pc=0x0c040324u; return 0; }
r[2]<<=2;
goto P_0c040326;
P_0c040326: /* original 622e, guest PC 0x0c040326 */
if(!s->budget--) { s->failed_pc=0x0c040326u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c040328;
P_0c040328: /* original d011, guest PC 0x0c040328 */
if(!s->budget--) { s->failed_pc=0x0c040328u; return 0; }
r[0]=read(ram,0x0c040370u,4);
goto P_0c04032a;
P_0c04032a: /* original 032e, guest PC 0x0c04032a */
if(!s->budget--) { s->failed_pc=0x0c04032au; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c04032c;
P_0c04032c: /* original 50f2, guest PC 0x0c04032c */
if(!s->budget--) { s->failed_pc=0x0c04032cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c04032e;
P_0c04032e: /* original 303c, guest PC 0x0c04032e */
if(!s->budget--) { s->failed_pc=0x0c04032eu; return 0; }
r[0]+=r[3];
goto P_0c040330;
P_0c040330: /* original 1f02, guest PC 0x0c040330 */
if(!s->budget--) { s->failed_pc=0x0c040330u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c040332;
P_0c040332: /* original 52f1, guest PC 0x0c040332 */
if(!s->budget--) { s->failed_pc=0x0c040332u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c040334;
P_0c040334: /* original 6323, guest PC 0x0c040334 */
if(!s->budget--) { s->failed_pc=0x0c040334u; return 0; }
r[3]=r[2];
goto P_0c040336;
P_0c040336: /* original 4200, guest PC 0x0c040336 */
if(!s->budget--) { s->failed_pc=0x0c040336u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c040338;
P_0c040338: /* original 323c, guest PC 0x0c040338 */
if(!s->budget--) { s->failed_pc=0x0c040338u; return 0; }
r[2]+=r[3];
goto P_0c04033a;
P_0c04033a: /* original 4208, guest PC 0x0c04033a */
if(!s->budget--) { s->failed_pc=0x0c04033au; return 0; }
r[2]<<=2;
goto P_0c04033c;
P_0c04033c: /* original 622e, guest PC 0x0c04033c */
if(!s->budget--) { s->failed_pc=0x0c04033cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c04033e;
P_0c04033e: /* original d00d, guest PC 0x0c04033e */
if(!s->budget--) { s->failed_pc=0x0c04033eu; return 0; }
r[0]=read(ram,0x0c040374u,4);
goto P_0c040340;
P_0c040340: /* original 53f4, guest PC 0x0c040340 */
if(!s->budget--) { s->failed_pc=0x0c040340u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040342;
P_0c040342: /* original 012e, guest PC 0x0c040342 */
if(!s->budget--) { s->failed_pc=0x0c040342u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c040344;
P_0c040344: /* original 313c, guest PC 0x0c040344 */
if(!s->budget--) { s->failed_pc=0x0c040344u; return 0; }
r[1]+=r[3];
goto P_0c040346;
P_0c040346: /* original 0216, guest PC 0x0c040346 */
if(!s->budget--) { s->failed_pc=0x0c040346u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c040348;
P_0c040348: /* original 52f1, guest PC 0x0c040348 */
if(!s->budget--) { s->failed_pc=0x0c040348u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04034a;
P_0c04034a: /* original 7201, guest PC 0x0c04034a */
if(!s->budget--) { s->failed_pc=0x0c04034au; return 0; }
r[2]+=0x00000001u;
goto P_0c04034c;
P_0c04034c: /* original 1f21, guest PC 0x0c04034c */
if(!s->budget--) { s->failed_pc=0x0c04034cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c04034e;
P_0c04034e: /* original e308, guest PC 0x0c04034e */
if(!s->budget--) { s->failed_pc=0x0c04034eu; return 0; }
r[3]=0x00000008u;
goto P_0c040350;
P_0c040350: /* original 51f1, guest PC 0x0c040350 */
if(!s->budget--) { s->failed_pc=0x0c040350u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c040352;
P_0c040352: /* original 3133, guest PC 0x0c040352 */
if(!s->budget--) { s->failed_pc=0x0c040352u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040354;
P_0c040354: /* original 8bd8, guest PC 0x0c040354 */
if(!s->budget--) { s->failed_pc=0x0c040354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040308; }
goto P_0c040356;
P_0c040356: /* original 53f3, guest PC 0x0c040356 */
if(!s->budget--) { s->failed_pc=0x0c040356u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040358;
P_0c040358: /* original 52f2, guest PC 0x0c040358 */
if(!s->budget--) { s->failed_pc=0x0c040358u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04035a;
P_0c04035a: /* original 2322, guest PC 0x0c04035a */
if(!s->budget--) { s->failed_pc=0x0c04035au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04035c;
P_0c04035c: /* original 60f2, guest PC 0x0c04035c */
if(!s->budget--) { s->failed_pc=0x0c04035cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04035e;
P_0c04035e: /* original 7f1c, guest PC 0x0c04035e */
if(!s->budget--) { s->failed_pc=0x0c04035eu; return 0; }
r[15]+=0x0000001cu;
goto P_0c040360;
P_0c040360: /* original 000b, guest PC 0x0c040360 */
if(!s->budget--) { s->failed_pc=0x0c040360u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040362: /* original 0009, guest PC 0x0c040362 */
if(!s->budget--) { s->failed_pc=0x0c040362u; return 0; }
if(!vf3_matrix_family(0x0c040364u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040364u; return 0; } return 1;
P_0c040378: /* original 7ffc, guest PC 0x0c040378 */
if(!s->budget--) { s->failed_pc=0x0c040378u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04037a;
P_0c04037a: /* original 2f42, guest PC 0x0c04037a */
if(!s->budget--) { s->failed_pc=0x0c04037au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04037c;
P_0c04037c: /* original 62f2, guest PC 0x0c04037c */
if(!s->budget--) { s->failed_pc=0x0c04037cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04037e;
P_0c04037e: /* original 4211, guest PC 0x0c04037e */
if(!s->budget--) { s->failed_pc=0x0c04037eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c040380;
P_0c040380: /* original 8b03, guest PC 0x0c040380 */
if(!s->budget--) { s->failed_pc=0x0c040380u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04038a; }
goto P_0c040382;
P_0c040382: /* original e108, guest PC 0x0c040382 */
if(!s->budget--) { s->failed_pc=0x0c040382u; return 0; }
r[1]=0x00000008u;
goto P_0c040384;
P_0c040384: /* original 63f2, guest PC 0x0c040384 */
if(!s->budget--) { s->failed_pc=0x0c040384u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040386;
P_0c040386: /* original 3313, guest PC 0x0c040386 */
if(!s->budget--) { s->failed_pc=0x0c040386u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c040388;
P_0c040388: /* original 8b03, guest PC 0x0c040388 */
if(!s->budget--) { s->failed_pc=0x0c040388u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c040392u,s,ram); }
goto P_0c04038a;
P_0c04038a: /* original e0ff, guest PC 0x0c04038a */
if(!s->budget--) { s->failed_pc=0x0c04038au; return 0; }
r[0]=0xffffffffu;
goto P_0c04038c;
P_0c04038c: /* original 7f04, guest PC 0x0c04038c */
if(!s->budget--) { s->failed_pc=0x0c04038cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04038e;
P_0c04038e: /* original 000b, guest PC 0x0c04038e */
if(!s->budget--) { s->failed_pc=0x0c04038eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040390: /* original 0009, guest PC 0x0c040390 */
if(!s->budget--) { s->failed_pc=0x0c040390u; return 0; }
return vf3_matrix_family(0x0c040392u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
