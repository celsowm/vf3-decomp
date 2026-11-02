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
int vf3_away_batch20_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c04c47cu: goto P_0c04c47c;
case 0x0c04c47eu: goto P_0c04c47e;
case 0x0c04c480u: goto P_0c04c480;
case 0x0c04c482u: goto P_0c04c482;
case 0x0c04c484u: goto P_0c04c484;
case 0x0c04c486u: goto P_0c04c486;
case 0x0c04c488u: goto P_0c04c488;
case 0x0c04c48au: goto P_0c04c48a;
case 0x0c055d40u: goto P_0c055d40;
case 0x0c055d42u: goto P_0c055d42;
case 0x0c055d44u: goto P_0c055d44;
case 0x0c055d46u: goto P_0c055d46;
case 0x0c055d48u: goto P_0c055d48;
case 0x0c055d4au: goto P_0c055d4a;
case 0x0c055d4cu: goto P_0c055d4c;
case 0x0c055d4eu: goto P_0c055d4e;
case 0x0c055d50u: goto P_0c055d50;
case 0x0c055d52u: goto P_0c055d52;
case 0x0c055d54u: goto P_0c055d54;
case 0x0c055d56u: goto P_0c055d56;
case 0x0c055d58u: goto P_0c055d58;
case 0x0c055d5au: goto P_0c055d5a;
case 0x0c055d5cu: goto P_0c055d5c;
case 0x0c055d5eu: goto P_0c055d5e;
case 0x0c055d60u: goto P_0c055d60;
case 0x0c055d62u: goto P_0c055d62;
case 0x0c055d64u: goto P_0c055d64;
case 0x0c055d66u: goto P_0c055d66;
case 0x0c055d68u: goto P_0c055d68;
case 0x0c055d6au: goto P_0c055d6a;
case 0x0c055d6cu: goto P_0c055d6c;
case 0x0c055d6eu: goto P_0c055d6e;
case 0x0c055d70u: goto P_0c055d70;
case 0x0c055d72u: goto P_0c055d72;
case 0x0c055d74u: goto P_0c055d74;
case 0x0c055d76u: goto P_0c055d76;
case 0x0c055d78u: goto P_0c055d78;
case 0x0c055d7au: goto P_0c055d7a;
case 0x0c055d7cu: goto P_0c055d7c;
case 0x0c055d7eu: goto P_0c055d7e;
case 0x0c055d80u: goto P_0c055d80;
case 0x0c055d82u: goto P_0c055d82;
case 0x0c055d84u: goto P_0c055d84;
case 0x0c055d86u: goto P_0c055d86;
case 0x0c055d88u: goto P_0c055d88;
case 0x0c055d8au: goto P_0c055d8a;
case 0x0c055d8cu: goto P_0c055d8c;
case 0x0c055d8eu: goto P_0c055d8e;
case 0x0c055d90u: goto P_0c055d90;
case 0x0c055d92u: goto P_0c055d92;
case 0x0c055d94u: goto P_0c055d94;
case 0x0c055d96u: goto P_0c055d96;
case 0x0c055d98u: goto P_0c055d98;
case 0x0c055d9au: goto P_0c055d9a;
case 0x0c055d9cu: goto P_0c055d9c;
case 0x0c055d9eu: goto P_0c055d9e;
case 0x0c055da0u: goto P_0c055da0;
case 0x0c055da2u: goto P_0c055da2;
case 0x0c055da4u: goto P_0c055da4;
case 0x0c055da6u: goto P_0c055da6;
case 0x0c055da8u: goto P_0c055da8;
case 0x0c055daau: goto P_0c055daa;
case 0x0c055dacu: goto P_0c055dac;
case 0x0c055daeu: goto P_0c055dae;
case 0x0c055db0u: goto P_0c055db0;
case 0x0c055db2u: goto P_0c055db2;
case 0x0c055db4u: goto P_0c055db4;
case 0x0c055db6u: goto P_0c055db6;
case 0x0c055db8u: goto P_0c055db8;
case 0x0c059840u: goto P_0c059840;
case 0x0c059842u: goto P_0c059842;
case 0x0c059844u: goto P_0c059844;
case 0x0c059846u: goto P_0c059846;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
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
P_0c04c47c: /* original 4408, guest PC 0x0c04c47c */
if(!s->budget--) { s->failed_pc=0x0c04c47cu; return 0; }
r[4]<<=2;
goto P_0c04c47e;
P_0c04c47e: /* original d31b, guest PC 0x0c04c47e */
if(!s->budget--) { s->failed_pc=0x0c04c47eu; return 0; }
r[3]=read(ram,0x0c04c4ecu,4);
goto P_0c04c480;
P_0c04c480: /* original 4408, guest PC 0x0c04c480 */
if(!s->budget--) { s->failed_pc=0x0c04c480u; return 0; }
r[4]<<=2;
goto P_0c04c482;
P_0c04c482: /* original 4408, guest PC 0x0c04c482 */
if(!s->budget--) { s->failed_pc=0x0c04c482u; return 0; }
r[4]<<=2;
goto P_0c04c484;
P_0c04c484: /* original 4400, guest PC 0x0c04c484 */
if(!s->budget--) { s->failed_pc=0x0c04c484u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c04c486;
P_0c04c486: /* original 343c, guest PC 0x0c04c486 */
if(!s->budget--) { s->failed_pc=0x0c04c486u; return 0; }
r[4]+=r[3];
goto P_0c04c488;
P_0c04c488: /* original 000b, guest PC 0x0c04c488 */
if(!s->budget--) { s->failed_pc=0x0c04c488u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+4,4);
s->pc=target; return ram->oob==0;
P_0c04c48a: /* original 5041, guest PC 0x0c04c48a */
if(!s->budget--) { s->failed_pc=0x0c04c48au; return 0; }
r[0]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(0x0c04c48cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c48cu; return 0; } return 1;
P_0c055d40: /* original 4f22, guest PC 0x0c055d40 */
if(!s->budget--) { s->failed_pc=0x0c055d40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d42;
P_0c055d42: /* original d01f, guest PC 0x0c055d42 */
if(!s->budget--) { s->failed_pc=0x0c055d42u; return 0; }
r[0]=read(ram,0x0c055dc0u,4);
goto P_0c055d44;
P_0c055d44: /* original 6102, guest PC 0x0c055d44 */
if(!s->budget--) { s->failed_pc=0x0c055d44u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c055d46;
P_0c055d46: /* original 4115, guest PC 0x0c055d46 */
if(!s->budget--) { s->failed_pc=0x0c055d46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d48;
P_0c055d48: /* original d01c, guest PC 0x0c055d48 */
if(!s->budget--) { s->failed_pc=0x0c055d48u; return 0; }
r[0]=read(ram,0x0c055dbcu,4);
goto P_0c055d4a;
P_0c055d4a: /* original 8d0e, guest PC 0x0c055d4a */
if(!s->budget--) { s->failed_pc=0x0c055d4au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c055d6a; }
goto P_0c055d4e;
P_0c055d4c: /* original 6403, guest PC 0x0c055d4c */
if(!s->budget--) { s->failed_pc=0x0c055d4cu; return 0; }
r[4]=r[0];
goto P_0c055d4e;
P_0c055d4e: /* original 7440, guest PC 0x0c055d4e */
if(!s->budget--) { s->failed_pc=0x0c055d4eu; return 0; }
r[4]+=0x00000040u;
goto P_0c055d50;
P_0c055d50: /* original 6503, guest PC 0x0c055d50 */
if(!s->budget--) { s->failed_pc=0x0c055d50u; return 0; }
r[5]=r[0];
goto P_0c055d52;
P_0c055d52: /* original d31c, guest PC 0x0c055d52 */
if(!s->budget--) { s->failed_pc=0x0c055d52u; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d54;
P_0c055d54: /* original 430b, guest PC 0x0c055d54 */
if(!s->budget--) { s->failed_pc=0x0c055d54u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d58u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d58u) { target=s->pc; goto dispatch; }
goto P_0c055d58;
P_0c055d56: /* original 7568, guest PC 0x0c055d56 */
if(!s->budget--) { s->failed_pc=0x0c055d56u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d58;
P_0c055d58: /* original d01c, guest PC 0x0c055d58 */
if(!s->budget--) { s->failed_pc=0x0c055d58u; return 0; }
r[0]=read(ram,0x0c055dccu,4);
goto P_0c055d5a;
P_0c055d5a: /* original d11f, guest PC 0x0c055d5a */
if(!s->budget--) { s->failed_pc=0x0c055d5au; return 0; }
r[1]=read(ram,0x0c055dd8u,4);
goto P_0c055d5c;
P_0c055d5c: /* original d220, guest PC 0x0c055d5c */
if(!s->budget--) { s->failed_pc=0x0c055d5cu; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055d5e;
P_0c055d5e: /* original c204, guest PC 0x0c055d5e */
if(!s->budget--) { s->failed_pc=0x0c055d5eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055d60;
P_0c055d60: /* original 6013, guest PC 0x0c055d60 */
if(!s->budget--) { s->failed_pc=0x0c055d60u; return 0; }
r[0]=r[1];
goto P_0c055d62;
P_0c055d62: /* original c205, guest PC 0x0c055d62 */
if(!s->budget--) { s->failed_pc=0x0c055d62u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055d64;
P_0c055d64: /* original 6023, guest PC 0x0c055d64 */
if(!s->budget--) { s->failed_pc=0x0c055d64u; return 0; }
r[0]=r[2];
goto P_0c055d66;
P_0c055d66: /* original a025, guest PC 0x0c055d66 */
if(!s->budget--) { s->failed_pc=0x0c055d66u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055d68: /* original c203, guest PC 0x0c055d68 */
if(!s->budget--) { s->failed_pc=0x0c055d68u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055d6a;
P_0c055d6a: /* original 2fe6, guest PC 0x0c055d6a */
if(!s->budget--) { s->failed_pc=0x0c055d6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6c;
P_0c055d6c: /* original 2fd6, guest PC 0x0c055d6c */
if(!s->budget--) { s->failed_pc=0x0c055d6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6e;
P_0c055d6e: /* original 6e03, guest PC 0x0c055d6e */
if(!s->budget--) { s->failed_pc=0x0c055d6eu; return 0; }
r[14]=r[0];
goto P_0c055d70;
P_0c055d70: /* original ed10, guest PC 0x0c055d70 */
if(!s->budget--) { s->failed_pc=0x0c055d70u; return 0; }
r[13]=0x00000010u;
goto P_0c055d72;
P_0c055d72: /* original 61e2, guest PC 0x0c055d72 */
if(!s->budget--) { s->failed_pc=0x0c055d72u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c055d74;
P_0c055d74: /* original 4115, guest PC 0x0c055d74 */
if(!s->budget--) { s->failed_pc=0x0c055d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d76;
P_0c055d76: /* original 8f0b, guest PC 0x0c055d76 */
if(!s->budget--) { s->failed_pc=0x0c055d76u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(!cond) { goto P_0c055d90; }
goto P_0c055d7a;
P_0c055d78: /* original 64e3, guest PC 0x0c055d78 */
if(!s->budget--) { s->failed_pc=0x0c055d78u; return 0; }
r[4]=r[14];
goto P_0c055d7a;
P_0c055d7a: /* original 7440, guest PC 0x0c055d7a */
if(!s->budget--) { s->failed_pc=0x0c055d7au; return 0; }
r[4]+=0x00000040u;
goto P_0c055d7c;
P_0c055d7c: /* original 65e3, guest PC 0x0c055d7c */
if(!s->budget--) { s->failed_pc=0x0c055d7cu; return 0; }
r[5]=r[14];
goto P_0c055d7e;
P_0c055d7e: /* original d311, guest PC 0x0c055d7e */
if(!s->budget--) { s->failed_pc=0x0c055d7eu; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d80;
P_0c055d80: /* original 430b, guest PC 0x0c055d80 */
if(!s->budget--) { s->failed_pc=0x0c055d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d84u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d84u) { target=s->pc; goto dispatch; }
goto P_0c055d84;
P_0c055d82: /* original 7568, guest PC 0x0c055d82 */
if(!s->budget--) { s->failed_pc=0x0c055d82u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d84;
P_0c055d84: /* original 64e3, guest PC 0x0c055d84 */
if(!s->budget--) { s->failed_pc=0x0c055d84u; return 0; }
r[4]=r[14];
goto P_0c055d86;
P_0c055d86: /* original 7434, guest PC 0x0c055d86 */
if(!s->budget--) { s->failed_pc=0x0c055d86u; return 0; }
r[4]+=0x00000034u;
goto P_0c055d88;
P_0c055d88: /* original 65e3, guest PC 0x0c055d88 */
if(!s->budget--) { s->failed_pc=0x0c055d88u; return 0; }
r[5]=r[14];
goto P_0c055d8a;
P_0c055d8a: /* original d30f, guest PC 0x0c055d8a */
if(!s->budget--) { s->failed_pc=0x0c055d8au; return 0; }
r[3]=read(ram,0x0c055dc8u,4);
goto P_0c055d8c;
P_0c055d8c: /* original 430b, guest PC 0x0c055d8c */
if(!s->budget--) { s->failed_pc=0x0c055d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055d90u;
r[5]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d90u) { target=s->pc; goto dispatch; }
goto P_0c055d90;
P_0c055d8e: /* original 755c, guest PC 0x0c055d8e */
if(!s->budget--) { s->failed_pc=0x0c055d8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c055d90;
P_0c055d90: /* original e3b0, guest PC 0x0c055d90 */
if(!s->budget--) { s->failed_pc=0x0c055d90u; return 0; }
r[3]=0xffffffb0u;
goto P_0c055d92;
P_0c055d92: /* original 623c, guest PC 0x0c055d92 */
if(!s->budget--) { s->failed_pc=0x0c055d92u; return 0; }
r[2]=r[3]&255u;
goto P_0c055d94;
P_0c055d94: /* original 4d10, guest PC 0x0c055d94 */
if(!s->budget--) { s->failed_pc=0x0c055d94u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c055d96;
P_0c055d96: /* original 8fec, guest PC 0x0c055d96 */
if(!s->budget--) { s->failed_pc=0x0c055d96u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c055d72; }
goto P_0c055d9a;
P_0c055d98: /* original 3e2c, guest PC 0x0c055d98 */
if(!s->budget--) { s->failed_pc=0x0c055d98u; return 0; }
r[14]+=r[2];
goto P_0c055d9a;
P_0c055d9a: /* original 6df6, guest PC 0x0c055d9a */
if(!s->budget--) { s->failed_pc=0x0c055d9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055d9c;
P_0c055d9c: /* original 6ef6, guest PC 0x0c055d9c */
if(!s->budget--) { s->failed_pc=0x0c055d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055d9e;
P_0c055d9e: /* original d00c, guest PC 0x0c055d9e */
if(!s->budget--) { s->failed_pc=0x0c055d9eu; return 0; }
r[0]=read(ram,0x0c055dd0u,4);
goto P_0c055da0;
P_0c055da0: /* original e380, guest PC 0x0c055da0 */
if(!s->budget--) { s->failed_pc=0x0c055da0u; return 0; }
r[3]=0xffffff80u;
goto P_0c055da2;
P_0c055da2: /* original d10e, guest PC 0x0c055da2 */
if(!s->budget--) { s->failed_pc=0x0c055da2u; return 0; }
r[1]=read(ram,0x0c055ddcu,4);
goto P_0c055da4;
P_0c055da4: /* original 633c, guest PC 0x0c055da4 */
if(!s->budget--) { s->failed_pc=0x0c055da4u; return 0; }
r[3]=r[3]&255u;
goto P_0c055da6;
P_0c055da6: /* original d20e, guest PC 0x0c055da6 */
if(!s->budget--) { s->failed_pc=0x0c055da6u; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055da8;
P_0c055da8: /* original c204, guest PC 0x0c055da8 */
if(!s->budget--) { s->failed_pc=0x0c055da8u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055daa;
P_0c055daa: /* original 6013, guest PC 0x0c055daa */
if(!s->budget--) { s->failed_pc=0x0c055daau; return 0; }
r[0]=r[1];
goto P_0c055dac;
P_0c055dac: /* original c205, guest PC 0x0c055dac */
if(!s->budget--) { s->failed_pc=0x0c055dacu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055dae;
P_0c055dae: /* original 6023, guest PC 0x0c055dae */
if(!s->budget--) { s->failed_pc=0x0c055daeu; return 0; }
r[0]=r[2];
goto P_0c055db0;
P_0c055db0: /* original 303c, guest PC 0x0c055db0 */
if(!s->budget--) { s->failed_pc=0x0c055db0u; return 0; }
r[0]+=r[3];
goto P_0c055db2;
P_0c055db2: /* original c203, guest PC 0x0c055db2 */
if(!s->budget--) { s->failed_pc=0x0c055db2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055db4: /* original 4f26, guest PC 0x0c055db4 */
if(!s->budget--) { s->failed_pc=0x0c055db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055db6;
P_0c055db6: /* original 000b, guest PC 0x0c055db6 */
if(!s->budget--) { s->failed_pc=0x0c055db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055db8: /* original 0009, guest PC 0x0c055db8 */
if(!s->budget--) { s->failed_pc=0x0c055db8u; return 0; }
if(!vf3_matrix_family(0x0c055dbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055dbau; return 0; } return 1;
P_0c059840: /* original 2fe6, guest PC 0x0c059840 */
if(!s->budget--) { s->failed_pc=0x0c059840u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059842;
P_0c059842: /* original 2fd6, guest PC 0x0c059842 */
if(!s->budget--) { s->failed_pc=0x0c059842u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059844;
P_0c059844: /* original 2fc6, guest PC 0x0c059844 */
if(!s->budget--) { s->failed_pc=0x0c059844u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059846;
P_0c059846: /* original 2fb6, guest PC 0x0c059846 */
if(!s->budget--) { s->failed_pc=0x0c059846u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059848;
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c059896u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059896u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
