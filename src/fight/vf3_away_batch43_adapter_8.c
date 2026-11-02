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
int vf3_away_batch43_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04a432u: goto P_0c04a432;
case 0x0c04a434u: goto P_0c04a434;
case 0x0c04a436u: goto P_0c04a436;
case 0x0c04a438u: goto P_0c04a438;
case 0x0c04a43au: goto P_0c04a43a;
case 0x0c04a43cu: goto P_0c04a43c;
case 0x0c04a43eu: goto P_0c04a43e;
case 0x0c04a440u: goto P_0c04a440;
case 0x0c04a442u: goto P_0c04a442;
case 0x0c04a444u: goto P_0c04a444;
case 0x0c04a446u: goto P_0c04a446;
case 0x0c04a448u: goto P_0c04a448;
case 0x0c04a4c4u: goto P_0c04a4c4;
case 0x0c04a4c6u: goto P_0c04a4c6;
case 0x0c04a4c8u: goto P_0c04a4c8;
case 0x0c04a4cau: goto P_0c04a4ca;
case 0x0c04a4ccu: goto P_0c04a4cc;
case 0x0c04a4ceu: goto P_0c04a4ce;
case 0x0c04a4d0u: goto P_0c04a4d0;
case 0x0c04a4d2u: goto P_0c04a4d2;
case 0x0c04a4d4u: goto P_0c04a4d4;
case 0x0c04a4d6u: goto P_0c04a4d6;
case 0x0c04a4d8u: goto P_0c04a4d8;
case 0x0c04a4dau: goto P_0c04a4da;
case 0x0c04a4dcu: goto P_0c04a4dc;
case 0x0c04a4deu: goto P_0c04a4de;
case 0x0c04a4e0u: goto P_0c04a4e0;
case 0x0c04a4e2u: goto P_0c04a4e2;
case 0x0c04a4e4u: goto P_0c04a4e4;
case 0x0c04a4e6u: goto P_0c04a4e6;
case 0x0c04a4e8u: goto P_0c04a4e8;
case 0x0c04a4eau: goto P_0c04a4ea;
case 0x0c04a4ecu: goto P_0c04a4ec;
case 0x0c04a4eeu: goto P_0c04a4ee;
case 0x0c04a4f0u: goto P_0c04a4f0;
case 0x0c04a4f2u: goto P_0c04a4f2;
case 0x0c04a4f4u: goto P_0c04a4f4;
case 0x0c04a4f6u: goto P_0c04a4f6;
case 0x0c04a4f8u: goto P_0c04a4f8;
case 0x0c04a4fau: goto P_0c04a4fa;
case 0x0c04a4fcu: goto P_0c04a4fc;
case 0x0c04a4feu: goto P_0c04a4fe;
case 0x0c04a500u: goto P_0c04a500;
case 0x0c04a502u: goto P_0c04a502;
case 0x0c04a504u: goto P_0c04a504;
case 0x0c04a506u: goto P_0c04a506;
case 0x0c04a508u: goto P_0c04a508;
case 0x0c04a50au: goto P_0c04a50a;
case 0x0c04a50cu: goto P_0c04a50c;
case 0x0c04a50eu: goto P_0c04a50e;
case 0x0c04a510u: goto P_0c04a510;
case 0x0c04a512u: goto P_0c04a512;
case 0x0c04a514u: goto P_0c04a514;
case 0x0c04a516u: goto P_0c04a516;
case 0x0c04a518u: goto P_0c04a518;
case 0x0c04a51au: goto P_0c04a51a;
case 0x0c04a51cu: goto P_0c04a51c;
case 0x0c04a51eu: goto P_0c04a51e;
case 0x0c04a520u: goto P_0c04a520;
case 0x0c04a522u: goto P_0c04a522;
case 0x0c04a524u: goto P_0c04a524;
case 0x0c04a526u: goto P_0c04a526;
case 0x0c04a528u: goto P_0c04a528;
case 0x0c04a52au: goto P_0c04a52a;
case 0x0c04a52cu: goto P_0c04a52c;
case 0x0c04a52eu: goto P_0c04a52e;
case 0x0c04a530u: goto P_0c04a530;
case 0x0c04a532u: goto P_0c04a532;
case 0x0c04a534u: goto P_0c04a534;
case 0x0c04a536u: goto P_0c04a536;
case 0x0c04a538u: goto P_0c04a538;
case 0x0c04a53au: goto P_0c04a53a;
case 0x0c04a53cu: goto P_0c04a53c;
case 0x0c04a53eu: goto P_0c04a53e;
case 0x0c04a540u: goto P_0c04a540;
case 0x0c04a542u: goto P_0c04a542;
case 0x0c04a544u: goto P_0c04a544;
case 0x0c04a546u: goto P_0c04a546;
case 0x0c04a548u: goto P_0c04a548;
case 0x0c04a54au: goto P_0c04a54a;
case 0x0c04a54cu: goto P_0c04a54c;
case 0x0c04a54eu: goto P_0c04a54e;
case 0x0c04a550u: goto P_0c04a550;
case 0x0c04a552u: goto P_0c04a552;
case 0x0c04a554u: goto P_0c04a554;
case 0x0c04a556u: goto P_0c04a556;
case 0x0c04a558u: goto P_0c04a558;
case 0x0c04a55au: goto P_0c04a55a;
case 0x0c04a55cu: goto P_0c04a55c;
case 0x0c04a55eu: goto P_0c04a55e;
case 0x0c04a560u: goto P_0c04a560;
case 0x0c04a562u: goto P_0c04a562;
case 0x0c04a564u: goto P_0c04a564;
case 0x0c04a566u: goto P_0c04a566;
case 0x0c04a568u: goto P_0c04a568;
case 0x0c04a56au: goto P_0c04a56a;
case 0x0c04a56cu: goto P_0c04a56c;
case 0x0c04a56eu: goto P_0c04a56e;
case 0x0c04a570u: goto P_0c04a570;
case 0x0c04a572u: goto P_0c04a572;
case 0x0c04a574u: goto P_0c04a574;
case 0x0c04a576u: goto P_0c04a576;
case 0x0c04a578u: goto P_0c04a578;
case 0x0c04a57au: goto P_0c04a57a;
case 0x0c04a57cu: goto P_0c04a57c;
case 0x0c04a57eu: goto P_0c04a57e;
case 0x0c04a580u: goto P_0c04a580;
case 0x0c04a582u: goto P_0c04a582;
case 0x0c04a584u: goto P_0c04a584;
case 0x0c04a586u: goto P_0c04a586;
case 0x0c04a588u: goto P_0c04a588;
case 0x0c04a58au: goto P_0c04a58a;
case 0x0c04a58cu: goto P_0c04a58c;
case 0x0c04a58eu: goto P_0c04a58e;
case 0x0c04a590u: goto P_0c04a590;
case 0x0c04a592u: goto P_0c04a592;
case 0x0c04a594u: goto P_0c04a594;
case 0x0c04a596u: goto P_0c04a596;
case 0x0c04a598u: goto P_0c04a598;
case 0x0c04a59au: goto P_0c04a59a;
case 0x0c04a59cu: goto P_0c04a59c;
case 0x0c04a59eu: goto P_0c04a59e;
case 0x0c04a5a0u: goto P_0c04a5a0;
case 0x0c04a5a2u: goto P_0c04a5a2;
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
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
P_0c04a432: /* original 76e0, guest PC 0x0c04a432 */
if(!s->budget--) { s->failed_pc=0x0c04a432u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c04a434;
P_0c04a434: /* original 000b, guest PC 0x0c04a434 */
if(!s->budget--) { s->failed_pc=0x0c04a434u; return 0; }
target=r[16];
r[5]+=0xffffffe0u;
s->pc=target; return ram->oob==0;
P_0c04a436: /* original 75e0, guest PC 0x0c04a436 */
if(!s->budget--) { s->failed_pc=0x0c04a436u; return 0; }
r[5]+=0xffffffe0u;
goto P_0c04a438;
P_0c04a438: /* original 8807, guest PC 0x0c04a438 */
if(!s->budget--) { s->failed_pc=0x0c04a438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c04a43a;
P_0c04a43a: /* original 70fe, guest PC 0x0c04a43a */
if(!s->budget--) { s->failed_pc=0x0c04a43au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c04a43c;
P_0c04a43c: /* original 89d9, guest PC 0x0c04a43c */
if(!s->budget--) { s->failed_pc=0x0c04a43cu; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c04a3f2u,s,ram); }
goto P_0c04a43e;
P_0c04a43e: /* original 4008, guest PC 0x0c04a43e */
if(!s->budget--) { s->failed_pc=0x0c04a43eu; return 0; }
r[0]<<=2;
goto P_0c04a440;
P_0c04a440: /* original 88fc, guest PC 0x0c04a440 */
if(!s->budget--) { s->failed_pc=0x0c04a440u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffcu)!=0);
goto P_0c04a442;
P_0c04a442: /* original 4008, guest PC 0x0c04a442 */
if(!s->budget--) { s->failed_pc=0x0c04a442u; return 0; }
r[0]<<=2;
goto P_0c04a444;
P_0c04a444: /* original 8955, guest PC 0x0c04a444 */
if(!s->budget--) { s->failed_pc=0x0c04a444u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04a4f2; }
goto P_0c04a446;
P_0c04a446: /* original 0023, guest PC 0x0c04a446 */
if(!s->budget--) { s->failed_pc=0x0c04a446u; return 0; }
target=r[0]+0x0c04a44au;
vf3_matrix_move(s,2,6);
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
P_0c04a448: /* original f26c, guest PC 0x0c04a448 */
if(!s->budget--) { s->failed_pc=0x0c04a448u; return 0; }
vf3_matrix_move(s,2,6);
if(!vf3_matrix_family(0x0c04a44au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a44au; return 0; } return 1;
P_0c04a4c4: /* original f60b, guest PC 0x0c04a4c4 */
if(!s->budget--) { s->failed_pc=0x0c04a4c4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04a4c6;
P_0c04a4c6: /* original f3fd, guest PC 0x0c04a4c6 */
if(!s->budget--) { s->failed_pc=0x0c04a4c6u; return 0; }
r[18]^=0x100000u;
goto P_0c04a4c8;
P_0c04a4c8: /* original f0ec, guest PC 0x0c04a4c8 */
if(!s->budget--) { s->failed_pc=0x0c04a4c8u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c04a4ca;
P_0c04a4ca: /* original fcae, guest PC 0x0c04a4ca */
if(!s->budget--) { s->failed_pc=0x0c04a4cau; return 0; }
fr[12]=vf3_fpu_mac(fr[0],fr[10],fr[12],r[18]);
goto P_0c04a4cc;
P_0c04a4cc: /* original 2602, guest PC 0x0c04a4cc */
if(!s->budget--) { s->failed_pc=0x0c04a4ccu; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a4ce;
P_0c04a4ce: /* original ff9e, guest PC 0x0c04a4ce */
if(!s->budget--) { s->failed_pc=0x0c04a4ceu; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c04a4d0;
P_0c04a4d0: /* original 761c, guest PC 0x0c04a4d0 */
if(!s->budget--) { s->failed_pc=0x0c04a4d0u; return 0; }
r[6]+=0x0000001cu;
goto P_0c04a4d2;
P_0c04a4d2: /* original f63b, guest PC 0x0c04a4d2 */
if(!s->budget--) { s->failed_pc=0x0c04a4d2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c04a4d4;
P_0c04a4d4: /* original fc32, guest PC 0x0c04a4d4 */
if(!s->budget--) { s->failed_pc=0x0c04a4d4u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c04a4d6;
P_0c04a4d6: /* original ff32, guest PC 0x0c04a4d6 */
if(!s->budget--) { s->failed_pc=0x0c04a4d6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c04a4d8;
P_0c04a4d8: /* original f6cb, guest PC 0x0c04a4d8 */
if(!s->budget--) { s->failed_pc=0x0c04a4d8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[6]);
goto P_0c04a4da;
P_0c04a4da: /* original f6fb, guest PC 0x0c04a4da */
if(!s->budget--) { s->failed_pc=0x0c04a4dau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[6]);
goto P_0c04a4dc;
P_0c04a4dc: /* original 0683, guest PC 0x0c04a4dc */
if(!s->budget--) { s->failed_pc=0x0c04a4dcu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a4de;
P_0c04a4de: /* original f3fd, guest PC 0x0c04a4de */
if(!s->budget--) { s->failed_pc=0x0c04a4deu; return 0; }
r[18]^=0x100000u;
goto P_0c04a4e0;
P_0c04a4e0: /* original 7610, guest PC 0x0c04a4e0 */
if(!s->budget--) { s->failed_pc=0x0c04a4e0u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a4e2;
P_0c04a4e2: /* original 4c5a, guest PC 0x0c04a4e2 */
if(!s->budget--) { s->failed_pc=0x0c04a4e2u; return 0; }
r[53]=r[12];
goto P_0c04a4e4;
P_0c04a4e4: /* original eb01, guest PC 0x0c04a4e4 */
if(!s->budget--) { s->failed_pc=0x0c04a4e4u; return 0; }
r[11]=0x00000001u;
goto P_0c04a4e6;
P_0c04a4e6: /* original f20d, guest PC 0x0c04a4e6 */
if(!s->budget--) { s->failed_pc=0x0c04a4e6u; return 0; }
fr[2]=r[53];
goto P_0c04a4e8;
P_0c04a4e8: /* original 7540, guest PC 0x0c04a4e8 */
if(!s->budget--) { s->failed_pc=0x0c04a4e8u; return 0; }
r[5]+=0x00000040u;
goto P_0c04a4ea;
P_0c04a4ea: /* original 4b5a, guest PC 0x0c04a4ea */
if(!s->budget--) { s->failed_pc=0x0c04a4eau; return 0; }
r[53]=r[11];
goto P_0c04a4ec;
P_0c04a4ec: /* original 0683, guest PC 0x0c04a4ec */
if(!s->budget--) { s->failed_pc=0x0c04a4ecu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a4ee;
P_0c04a4ee: /* original af80, guest PC 0x0c04a4ee */
if(!s->budget--) { s->failed_pc=0x0c04a4eeu; return 0; }
r[6]+=0x00000020u;
return vf3_matrix_family(0x0c04a3f2u,s,ram);
P_0c04a4f0: /* original 7620, guest PC 0x0c04a4f0 */
if(!s->budget--) { s->failed_pc=0x0c04a4f0u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a4f2;
P_0c04a4f2: /* original 4c5a, guest PC 0x0c04a4f2 */
if(!s->budget--) { s->failed_pc=0x0c04a4f2u; return 0; }
r[53]=r[12];
goto P_0c04a4f4;
P_0c04a4f4: /* original 7628, guest PC 0x0c04a4f4 */
if(!s->budget--) { s->failed_pc=0x0c04a4f4u; return 0; }
r[6]+=0x00000028u;
goto P_0c04a4f6;
P_0c04a4f6: /* original f26c, guest PC 0x0c04a4f6 */
if(!s->budget--) { s->failed_pc=0x0c04a4f6u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c04a4f8;
P_0c04a4f8: /* original f672, guest PC 0x0c04a4f8 */
if(!s->budget--) { s->failed_pc=0x0c04a4f8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a4fa;
P_0c04a4fa: /* original f04c, guest PC 0x0c04a4fa */
if(!s->budget--) { s->failed_pc=0x0c04a4fau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c04a4fc;
P_0c04a4fc: /* original f572, guest PC 0x0c04a4fc */
if(!s->budget--) { s->failed_pc=0x0c04a4fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a4fe;
P_0c04a4fe: /* original f00d, guest PC 0x0c04a4fe */
if(!s->budget--) { s->failed_pc=0x0c04a4feu; return 0; }
fr[0]=r[53];
goto P_0c04a500;
P_0c04a500: /* original f041, guest PC 0x0c04a500 */
if(!s->budget--) { s->failed_pc=0x0c04a500u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'-');
goto P_0c04a502;
P_0c04a502: /* original fc1d, guest PC 0x0c04a502 */
if(!s->budget--) { s->failed_pc=0x0c04a502u; return 0; }
r[53]=fr[12];
goto P_0c04a504;
P_0c04a504: /* original ff0d, guest PC 0x0c04a504 */
if(!s->budget--) { s->failed_pc=0x0c04a504u; return 0; }
fr[15]=r[53];
goto P_0c04a506;
P_0c04a506: /* original ff41, guest PC 0x0c04a506 */
if(!s->budget--) { s->failed_pc=0x0c04a506u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c04a508;
P_0c04a508: /* original fe1d, guest PC 0x0c04a508 */
if(!s->budget--) { s->failed_pc=0x0c04a508u; return 0; }
r[53]=fr[14];
goto P_0c04a50a;
P_0c04a50a: /* original f66b, guest PC 0x0c04a50a */
if(!s->budget--) { s->failed_pc=0x0c04a50au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a50c;
P_0c04a50c: /* original f64b, guest PC 0x0c04a50c */
if(!s->budget--) { s->failed_pc=0x0c04a50cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a50e;
P_0c04a50e: /* original f0f3, guest PC 0x0c04a50e */
if(!s->budget--) { s->failed_pc=0x0c04a50eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'/');
goto P_0c04a510;
P_0c04a510: /* original f6ac, guest PC 0x0c04a510 */
if(!s->budget--) { s->failed_pc=0x0c04a510u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c04a512;
P_0c04a512: /* original f672, guest PC 0x0c04a512 */
if(!s->budget--) { s->failed_pc=0x0c04a512u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04a514;
P_0c04a514: /* original f48c, guest PC 0x0c04a514 */
if(!s->budget--) { s->failed_pc=0x0c04a514u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c04a516;
P_0c04a516: /* original f572, guest PC 0x0c04a516 */
if(!s->budget--) { s->failed_pc=0x0c04a516u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c04a518;
P_0c04a518: /* original 76f8, guest PC 0x0c04a518 */
if(!s->budget--) { s->failed_pc=0x0c04a518u; return 0; }
r[6]+=0xfffffff8u;
goto P_0c04a51a;
P_0c04a51a: /* original f66b, guest PC 0x0c04a51a */
if(!s->budget--) { s->failed_pc=0x0c04a51au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04a51c;
P_0c04a51c: /* original e0ff, guest PC 0x0c04a51c */
if(!s->budget--) { s->failed_pc=0x0c04a51cu; return 0; }
r[0]=0xffffffffu;
goto P_0c04a51e;
P_0c04a51e: /* original f64b, guest PC 0x0c04a51e */
if(!s->budget--) { s->failed_pc=0x0c04a51eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04a520;
P_0c04a520: /* original f3fd, guest PC 0x0c04a520 */
if(!s->budget--) { s->failed_pc=0x0c04a520u; return 0; }
r[18]^=0x100000u;
goto P_0c04a522;
P_0c04a522: /* original 2602, guest PC 0x0c04a522 */
if(!s->budget--) { s->failed_pc=0x0c04a522u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c04a524;
P_0c04a524: /* original f60d, guest PC 0x0c04a524 */
if(!s->budget--) { s->failed_pc=0x0c04a524u; return 0; }
fr[6]=r[53];
goto P_0c04a526;
P_0c04a526: /* original f621, guest PC 0x0c04a526 */
if(!s->budget--) { s->failed_pc=0x0c04a526u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c04a528;
P_0c04a528: /* original fd1d, guest PC 0x0c04a528 */
if(!s->budget--) { s->failed_pc=0x0c04a528u; return 0; }
r[53]=fr[13];
goto P_0c04a52a;
P_0c04a52a: /* original e004, guest PC 0x0c04a52a */
if(!s->budget--) { s->failed_pc=0x0c04a52au; return 0; }
r[0]=0x00000004u;
goto P_0c04a52c;
P_0c04a52c: /* original f50d, guest PC 0x0c04a52c */
if(!s->budget--) { s->failed_pc=0x0c04a52cu; return 0; }
fr[5]=r[53];
goto P_0c04a52e;
P_0c04a52e: /* original f511, guest PC 0x0c04a52e */
if(!s->budget--) { s->failed_pc=0x0c04a52eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'-');
goto P_0c04a530;
P_0c04a530: /* original 7610, guest PC 0x0c04a530 */
if(!s->budget--) { s->failed_pc=0x0c04a530u; return 0; }
r[6]+=0x00000010u;
goto P_0c04a532;
P_0c04a532: /* original f26e, guest PC 0x0c04a532 */
if(!s->budget--) { s->failed_pc=0x0c04a532u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c04a534;
P_0c04a534: /* original 475a, guest PC 0x0c04a534 */
if(!s->budget--) { s->failed_pc=0x0c04a534u; return 0; }
r[53]=r[7];
goto P_0c04a536;
P_0c04a536: /* original f15e, guest PC 0x0c04a536 */
if(!s->budget--) { s->failed_pc=0x0c04a536u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[5],fr[1],r[18]);
goto P_0c04a538;
P_0c04a538: /* original f00d, guest PC 0x0c04a538 */
if(!s->budget--) { s->failed_pc=0x0c04a538u; return 0; }
fr[0]=r[53];
goto P_0c04a53a;
P_0c04a53a: /* original f202, guest PC 0x0c04a53a */
if(!s->budget--) { s->failed_pc=0x0c04a53au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'*');
goto P_0c04a53c;
P_0c04a53c: /* original 1672, guest PC 0x0c04a53c */
if(!s->budget--) { s->failed_pc=0x0c04a53cu; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c04a53e;
P_0c04a53e: /* original f102, guest PC 0x0c04a53e */
if(!s->budget--) { s->failed_pc=0x0c04a53eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c04a540;
P_0c04a540: /* original f627, guest PC 0x0c04a540 */
if(!s->budget--) { s->failed_pc=0x0c04a540u; return 0; }
vf3_matrix_store(s,ram,2,r[6]+r[0]);
goto P_0c04a542;
P_0c04a542: /* original f61a, guest PC 0x0c04a542 */
if(!s->budget--) { s->failed_pc=0x0c04a542u; return 0; }
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c04a544;
P_0c04a544: /* original 76f0, guest PC 0x0c04a544 */
if(!s->budget--) { s->failed_pc=0x0c04a544u; return 0; }
r[6]+=0xfffffff0u;
goto P_0c04a546;
P_0c04a546: /* original 0683, guest PC 0x0c04a546 */
if(!s->budget--) { s->failed_pc=0x0c04a546u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a548;
P_0c04a548: /* original f3fd, guest PC 0x0c04a548 */
if(!s->budget--) { s->failed_pc=0x0c04a548u; return 0; }
r[18]^=0x100000u;
goto P_0c04a54a;
P_0c04a54a: /* original 7620, guest PC 0x0c04a54a */
if(!s->budget--) { s->failed_pc=0x0c04a54au; return 0; }
r[6]+=0x00000020u;
goto P_0c04a54c;
P_0c04a54c: /* original 7540, guest PC 0x0c04a54c */
if(!s->budget--) { s->failed_pc=0x0c04a54cu; return 0; }
r[5]+=0x00000040u;
goto P_0c04a54e;
P_0c04a54e: /* original 0683, guest PC 0x0c04a54e */
if(!s->budget--) { s->failed_pc=0x0c04a54eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a550;
P_0c04a550: /* original 7620, guest PC 0x0c04a550 */
if(!s->budget--) { s->failed_pc=0x0c04a550u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a552;
P_0c04a552: /* original 4c5a, guest PC 0x0c04a552 */
if(!s->budget--) { s->failed_pc=0x0c04a552u; return 0; }
r[53]=r[12];
goto P_0c04a554;
P_0c04a554: /* original 7628, guest PC 0x0c04a554 */
if(!s->budget--) { s->failed_pc=0x0c04a554u; return 0; }
r[6]+=0x00000028u;
goto P_0c04a556;
P_0c04a556: /* original f2ac, guest PC 0x0c04a556 */
if(!s->budget--) { s->failed_pc=0x0c04a556u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c04a558;
P_0c04a558: /* original fab2, guest PC 0x0c04a558 */
if(!s->budget--) { s->failed_pc=0x0c04a558u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c04a55a;
P_0c04a55a: /* original f08c, guest PC 0x0c04a55a */
if(!s->budget--) { s->failed_pc=0x0c04a55au; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c04a55c;
P_0c04a55c: /* original f9b2, guest PC 0x0c04a55c */
if(!s->budget--) { s->failed_pc=0x0c04a55cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c04a55e;
P_0c04a55e: /* original f00d, guest PC 0x0c04a55e */
if(!s->budget--) { s->failed_pc=0x0c04a55eu; return 0; }
fr[0]=r[53];
goto P_0c04a560;
P_0c04a560: /* original f081, guest PC 0x0c04a560 */
if(!s->budget--) { s->failed_pc=0x0c04a560u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c04a562;
P_0c04a562: /* original fc1d, guest PC 0x0c04a562 */
if(!s->budget--) { s->failed_pc=0x0c04a562u; return 0; }
r[53]=fr[12];
goto P_0c04a564;
P_0c04a564: /* original ff0d, guest PC 0x0c04a564 */
if(!s->budget--) { s->failed_pc=0x0c04a564u; return 0; }
fr[15]=r[53];
goto P_0c04a566;
P_0c04a566: /* original ff81, guest PC 0x0c04a566 */
if(!s->budget--) { s->failed_pc=0x0c04a566u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[8],r[18],'-');
goto P_0c04a568;
P_0c04a568: /* original f6ab, guest PC 0x0c04a568 */
if(!s->budget--) { s->failed_pc=0x0c04a568u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[6]);
goto P_0c04a56a;
P_0c04a56a: /* original f68b, guest PC 0x0c04a56a */
if(!s->budget--) { s->failed_pc=0x0c04a56au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[6]);
goto P_0c04a56c;
P_0c04a56c: /* original f0f3, guest PC 0x0c04a56c */
if(!s->budget--) { s->failed_pc=0x0c04a56cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'/');
goto P_0c04a56e;
P_0c04a56e: /* original f3fd, guest PC 0x0c04a56e */
if(!s->budget--) { s->failed_pc=0x0c04a56eu; return 0; }
r[18]^=0x100000u;
goto P_0c04a570;
P_0c04a570: /* original 2672, guest PC 0x0c04a570 */
if(!s->budget--) { s->failed_pc=0x0c04a570u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c04a572;
P_0c04a572: /* original fe21, guest PC 0x0c04a572 */
if(!s->budget--) { s->failed_pc=0x0c04a572u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'-');
goto P_0c04a574;
P_0c04a574: /* original e004, guest PC 0x0c04a574 */
if(!s->budget--) { s->failed_pc=0x0c04a574u; return 0; }
r[0]=0x00000004u;
goto P_0c04a576;
P_0c04a576: /* original fd11, guest PC 0x0c04a576 */
if(!s->budget--) { s->failed_pc=0x0c04a576u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[1],r[18],'-');
goto P_0c04a578;
P_0c04a578: /* original 76ec, guest PC 0x0c04a578 */
if(!s->budget--) { s->failed_pc=0x0c04a578u; return 0; }
r[6]+=0xffffffecu;
goto P_0c04a57a;
P_0c04a57a: /* original f2ee, guest PC 0x0c04a57a */
if(!s->budget--) { s->failed_pc=0x0c04a57au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c04a57c;
P_0c04a57c: /* original 475a, guest PC 0x0c04a57c */
if(!s->budget--) { s->failed_pc=0x0c04a57cu; return 0; }
r[53]=r[7];
goto P_0c04a57e;
P_0c04a57e: /* original f1de, guest PC 0x0c04a57e */
if(!s->budget--) { s->failed_pc=0x0c04a57eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[13],fr[1],r[18]);
goto P_0c04a580;
P_0c04a580: /* original f00d, guest PC 0x0c04a580 */
if(!s->budget--) { s->failed_pc=0x0c04a580u; return 0; }
fr[0]=r[53];
goto P_0c04a582;
P_0c04a582: /* original f202, guest PC 0x0c04a582 */
if(!s->budget--) { s->failed_pc=0x0c04a582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[0],r[18],'*');
goto P_0c04a584;
P_0c04a584: /* original 1672, guest PC 0x0c04a584 */
if(!s->budget--) { s->failed_pc=0x0c04a584u; return 0; }
write(ram,r[6]+8,r[7],4);
goto P_0c04a586;
P_0c04a586: /* original f102, guest PC 0x0c04a586 */
if(!s->budget--) { s->failed_pc=0x0c04a586u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c04a588;
P_0c04a588: /* original f627, guest PC 0x0c04a588 */
if(!s->budget--) { s->failed_pc=0x0c04a588u; return 0; }
vf3_matrix_store(s,ram,2,r[6]+r[0]);
goto P_0c04a58a;
P_0c04a58a: /* original f61a, guest PC 0x0c04a58a */
if(!s->budget--) { s->failed_pc=0x0c04a58au; return 0; }
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c04a58c;
P_0c04a58c: /* original 76fc, guest PC 0x0c04a58c */
if(!s->budget--) { s->failed_pc=0x0c04a58cu; return 0; }
r[6]+=0xfffffffcu;
goto P_0c04a58e;
P_0c04a58e: /* original 0683, guest PC 0x0c04a58e */
if(!s->budget--) { s->failed_pc=0x0c04a58eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a590;
P_0c04a590: /* original f3fd, guest PC 0x0c04a590 */
if(!s->budget--) { s->failed_pc=0x0c04a590u; return 0; }
r[18]^=0x100000u;
goto P_0c04a592;
P_0c04a592: /* original 7620, guest PC 0x0c04a592 */
if(!s->budget--) { s->failed_pc=0x0c04a592u; return 0; }
r[6]+=0x00000020u;
goto P_0c04a594;
P_0c04a594: /* original 4c5a, guest PC 0x0c04a594 */
if(!s->budget--) { s->failed_pc=0x0c04a594u; return 0; }
r[53]=r[12];
goto P_0c04a596;
P_0c04a596: /* original eb01, guest PC 0x0c04a596 */
if(!s->budget--) { s->failed_pc=0x0c04a596u; return 0; }
r[11]=0x00000001u;
goto P_0c04a598;
P_0c04a598: /* original f20d, guest PC 0x0c04a598 */
if(!s->budget--) { s->failed_pc=0x0c04a598u; return 0; }
fr[2]=r[53];
goto P_0c04a59a;
P_0c04a59a: /* original 7540, guest PC 0x0c04a59a */
if(!s->budget--) { s->failed_pc=0x0c04a59au; return 0; }
r[5]+=0x00000040u;
goto P_0c04a59c;
P_0c04a59c: /* original 4b5a, guest PC 0x0c04a59c */
if(!s->budget--) { s->failed_pc=0x0c04a59cu; return 0; }
r[53]=r[11];
goto P_0c04a59e;
P_0c04a59e: /* original 0683, guest PC 0x0c04a59e */
if(!s->budget--) { s->failed_pc=0x0c04a59eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c04a5a0;
P_0c04a5a0: /* original af27, guest PC 0x0c04a5a0 */
if(!s->budget--) { s->failed_pc=0x0c04a5a0u; return 0; }
r[6]+=0x00000020u;
return vf3_matrix_family(0x0c04a3f2u,s,ram);
P_0c04a5a2: /* original 7620, guest PC 0x0c04a5a2 */
if(!s->budget--) { s->failed_pc=0x0c04a5a2u; return 0; }
r[6]+=0x00000020u;
if(!vf3_matrix_family(0x0c04a5a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04a5a4u; return 0; } return 1;
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
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
