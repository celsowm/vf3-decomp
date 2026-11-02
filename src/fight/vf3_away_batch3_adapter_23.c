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
int vf3_away_batch3_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c050c60u: goto P_0c050c60;
case 0x0c050c62u: goto P_0c050c62;
case 0x0c050c64u: goto P_0c050c64;
case 0x0c050c66u: goto P_0c050c66;
case 0x0c050c68u: goto P_0c050c68;
case 0x0c050c6au: goto P_0c050c6a;
case 0x0c050c6cu: goto P_0c050c6c;
case 0x0c050c6eu: goto P_0c050c6e;
case 0x0c050c70u: goto P_0c050c70;
case 0x0c050c72u: goto P_0c050c72;
case 0x0c050c74u: goto P_0c050c74;
case 0x0c050c76u: goto P_0c050c76;
case 0x0c050c78u: goto P_0c050c78;
case 0x0c050c7au: goto P_0c050c7a;
case 0x0c050c7cu: goto P_0c050c7c;
case 0x0c050c7eu: goto P_0c050c7e;
case 0x0c050c80u: goto P_0c050c80;
case 0x0c050c82u: goto P_0c050c82;
case 0x0c050c84u: goto P_0c050c84;
case 0x0c050c86u: goto P_0c050c86;
case 0x0c050c88u: goto P_0c050c88;
case 0x0c050c8au: goto P_0c050c8a;
case 0x0c050c8cu: goto P_0c050c8c;
case 0x0c050c8eu: goto P_0c050c8e;
case 0x0c050c90u: goto P_0c050c90;
case 0x0c050ca4u: goto P_0c050ca4;
case 0x0c050ca6u: goto P_0c050ca6;
case 0x0c050ca8u: goto P_0c050ca8;
case 0x0c050caau: goto P_0c050caa;
case 0x0c050cacu: goto P_0c050cac;
case 0x0c050caeu: goto P_0c050cae;
case 0x0c050cb0u: goto P_0c050cb0;
case 0x0c050cb2u: goto P_0c050cb2;
case 0x0c050cb4u: goto P_0c050cb4;
case 0x0c050cb6u: goto P_0c050cb6;
case 0x0c050cb8u: goto P_0c050cb8;
case 0x0c050cbau: goto P_0c050cba;
case 0x0c050cbcu: goto P_0c050cbc;
case 0x0c050cbeu: goto P_0c050cbe;
case 0x0c050cc0u: goto P_0c050cc0;
case 0x0c050cc2u: goto P_0c050cc2;
case 0x0c050cc4u: goto P_0c050cc4;
case 0x0c050cc6u: goto P_0c050cc6;
case 0x0c050cc8u: goto P_0c050cc8;
case 0x0c050ccau: goto P_0c050cca;
case 0x0c050cccu: goto P_0c050ccc;
case 0x0c050cceu: goto P_0c050cce;
case 0x0c050cd0u: goto P_0c050cd0;
case 0x0c050cd8u: goto P_0c050cd8;
case 0x0c050cdau: goto P_0c050cda;
case 0x0c050cdcu: goto P_0c050cdc;
case 0x0c050cdeu: goto P_0c050cde;
case 0x0c050ce0u: goto P_0c050ce0;
case 0x0c050e84u: goto P_0c050e84;
case 0x0c050e86u: goto P_0c050e86;
case 0x0c050e88u: goto P_0c050e88;
case 0x0c050e8au: goto P_0c050e8a;
case 0x0c050e8cu: goto P_0c050e8c;
case 0x0c050e8eu: goto P_0c050e8e;
case 0x0c050e90u: goto P_0c050e90;
case 0x0c050e92u: goto P_0c050e92;
case 0x0c050e94u: goto P_0c050e94;
case 0x0c050e96u: goto P_0c050e96;
case 0x0c050e98u: goto P_0c050e98;
case 0x0c050e9au: goto P_0c050e9a;
case 0x0c050e9cu: goto P_0c050e9c;
case 0x0c050e9eu: goto P_0c050e9e;
case 0x0c050ea0u: goto P_0c050ea0;
case 0x0c050ea2u: goto P_0c050ea2;
case 0x0c050ea4u: goto P_0c050ea4;
case 0x0c050ea6u: goto P_0c050ea6;
case 0x0c050ea8u: goto P_0c050ea8;
case 0x0c050eaau: goto P_0c050eaa;
case 0x0c050eacu: goto P_0c050eac;
case 0x0c050eaeu: goto P_0c050eae;
case 0x0c050eb0u: goto P_0c050eb0;
case 0x0c050eb2u: goto P_0c050eb2;
case 0x0c050eb4u: goto P_0c050eb4;
case 0x0c050eb6u: goto P_0c050eb6;
case 0x0c050eb8u: goto P_0c050eb8;
case 0x0c050ebau: goto P_0c050eba;
case 0x0c050ed0u: goto P_0c050ed0;
case 0x0c050ed2u: goto P_0c050ed2;
case 0x0c050ed4u: goto P_0c050ed4;
case 0x0c050ed6u: goto P_0c050ed6;
case 0x0c050ed8u: goto P_0c050ed8;
case 0x0c050edau: goto P_0c050eda;
case 0x0c050edcu: goto P_0c050edc;
case 0x0c050edeu: goto P_0c050ede;
case 0x0c050ee0u: goto P_0c050ee0;
case 0x0c050ee2u: goto P_0c050ee2;
case 0x0c050ee4u: goto P_0c050ee4;
case 0x0c050ee6u: goto P_0c050ee6;
case 0x0c050ee8u: goto P_0c050ee8;
case 0x0c050eeau: goto P_0c050eea;
case 0x0c050eecu: goto P_0c050eec;
case 0x0c050eeeu: goto P_0c050eee;
case 0x0c050ef0u: goto P_0c050ef0;
case 0x0c050ef2u: goto P_0c050ef2;
case 0x0c050ef4u: goto P_0c050ef4;
case 0x0c050ef6u: goto P_0c050ef6;
case 0x0c050ef8u: goto P_0c050ef8;
case 0x0c050efau: goto P_0c050efa;
case 0x0c050efcu: goto P_0c050efc;
case 0x0c050f04u: goto P_0c050f04;
case 0x0c050f06u: goto P_0c050f06;
case 0x0c050f08u: goto P_0c050f08;
case 0x0c050f0au: goto P_0c050f0a;
case 0x0c050f0cu: goto P_0c050f0c;
case 0x0c0510b0u: goto P_0c0510b0;
case 0x0c0510b2u: goto P_0c0510b2;
case 0x0c0510b4u: goto P_0c0510b4;
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
P_0c050c60: /* original 7fdc, guest PC 0x0c050c60 */
if(!s->budget--) { s->failed_pc=0x0c050c60u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c050c62;
P_0c050c62: /* original 1f48, guest PC 0x0c050c62 */
if(!s->budget--) { s->failed_pc=0x0c050c62u; return 0; }
write(ram,r[15]+32,r[4],4);
goto P_0c050c64;
P_0c050c64: /* original 1f57, guest PC 0x0c050c64 */
if(!s->budget--) { s->failed_pc=0x0c050c64u; return 0; }
write(ram,r[15]+28,r[5],4);
goto P_0c050c66;
P_0c050c66: /* original 53f7, guest PC 0x0c050c66 */
if(!s->budget--) { s->failed_pc=0x0c050c66u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c050c68;
P_0c050c68: /* original 2338, guest PC 0x0c050c68 */
if(!s->budget--) { s->failed_pc=0x0c050c68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c050c6a;
P_0c050c6a: /* original 8b02, guest PC 0x0c050c6a */
if(!s->budget--) { s->failed_pc=0x0c050c6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050c72; }
goto P_0c050c6c;
P_0c050c6c: /* original d309, guest PC 0x0c050c6c */
if(!s->budget--) { s->failed_pc=0x0c050c6cu; return 0; }
r[3]=read(ram,0x0c050c94u,4);
goto P_0c050c6e;
P_0c050c6e: /* original 432b, guest PC 0x0c050c6e */
if(!s->budget--) { s->failed_pc=0x0c050c6eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c050e84u: goto P_0c050e84;
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
P_0c050c70: /* original 0009, guest PC 0x0c050c70 */
if(!s->budget--) { s->failed_pc=0x0c050c70u; return 0; }
goto P_0c050c72;
P_0c050c72: /* original d309, guest PC 0x0c050c72 */
if(!s->budget--) { s->failed_pc=0x0c050c72u; return 0; }
r[3]=read(ram,0x0c050c98u,4);
goto P_0c050c74;
P_0c050c74: /* original 52f7, guest PC 0x0c050c74 */
if(!s->budget--) { s->failed_pc=0x0c050c74u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c050c76;
P_0c050c76: /* original 3232, guest PC 0x0c050c76 */
if(!s->budget--) { s->failed_pc=0x0c050c76u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c050c78;
P_0c050c78: /* original 8b02, guest PC 0x0c050c78 */
if(!s->budget--) { s->failed_pc=0x0c050c78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050c80; }
goto P_0c050c7a;
P_0c050c7a: /* original d108, guest PC 0x0c050c7a */
if(!s->budget--) { s->failed_pc=0x0c050c7au; return 0; }
r[1]=read(ram,0x0c050c9cu,4);
goto P_0c050c7c;
P_0c050c7c: /* original 412b, guest PC 0x0c050c7c */
if(!s->budget--) { s->failed_pc=0x0c050c7cu; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c050cbau: goto P_0c050cba;
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
P_0c050c7e: /* original 0009, guest PC 0x0c050c7e */
if(!s->budget--) { s->failed_pc=0x0c050c7eu; return 0; }
goto P_0c050c80;
P_0c050c80: /* original 50f8, guest PC 0x0c050c80 */
if(!s->budget--) { s->failed_pc=0x0c050c80u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c050c82;
P_0c050c82: /* original c91f, guest PC 0x0c050c82 */
if(!s->budget--) { s->failed_pc=0x0c050c82u; return 0; }
r[0]&=31u;
goto P_0c050c84;
P_0c050c84: /* original 55f7, guest PC 0x0c050c84 */
if(!s->budget--) { s->failed_pc=0x0c050c84u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c050c86;
P_0c050c86: /* original 350c, guest PC 0x0c050c86 */
if(!s->budget--) { s->failed_pc=0x0c050c86u; return 0; }
r[5]+=r[0];
goto P_0c050c88;
P_0c050c88: /* original d205, guest PC 0x0c050c88 */
if(!s->budget--) { s->failed_pc=0x0c050c88u; return 0; }
r[2]=read(ram,0x0c050ca0u,4);
goto P_0c050c8a;
P_0c050c8a: /* original 54f8, guest PC 0x0c050c8a */
if(!s->budget--) { s->failed_pc=0x0c050c8au; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c050c8c;
P_0c050c8c: /* original 2429, guest PC 0x0c050c8c */
if(!s->budget--) { s->failed_pc=0x0c050c8cu; return 0; }
r[4]&=r[2];
goto P_0c050c8e;
P_0c050c8e: /* original a009, guest PC 0x0c050c8e */
if(!s->budget--) { s->failed_pc=0x0c050c8eu; return 0; }
goto P_0c050ca4;
P_0c050c90: /* original 0009, guest PC 0x0c050c90 */
if(!s->budget--) { s->failed_pc=0x0c050c90u; return 0; }
if(!vf3_matrix_family(0x0c050c92u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050c92u; return 0; } return 1;
P_0c050ca4: /* original 751f, guest PC 0x0c050ca4 */
if(!s->budget--) { s->failed_pc=0x0c050ca4u; return 0; }
r[5]+=0x0000001fu;
goto P_0c050ca6;
P_0c050ca6: /* original 4509, guest PC 0x0c050ca6 */
if(!s->budget--) { s->failed_pc=0x0c050ca6u; return 0; }
r[5]>>=2;
goto P_0c050ca8;
P_0c050ca8: /* original 4509, guest PC 0x0c050ca8 */
if(!s->budget--) { s->failed_pc=0x0c050ca8u; return 0; }
r[5]>>=2;
goto P_0c050caa;
P_0c050caa: /* original 4501, guest PC 0x0c050caa */
if(!s->budget--) { s->failed_pc=0x0c050caau; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c050cac;
P_0c050cac: /* original 0493, guest PC 0x0c050cac */
if(!s->budget--) { s->failed_pc=0x0c050cacu; return 0; }
goto P_0c050cae;
P_0c050cae: /* original 4510, guest PC 0x0c050cae */
if(!s->budget--) { s->failed_pc=0x0c050caeu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c050cb0;
P_0c050cb0: /* original 8ffc, guest PC 0x0c050cb0 */
if(!s->budget--) { s->failed_pc=0x0c050cb0u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000020u;
if(!cond) { goto P_0c050cac; }
goto P_0c050cb4;
P_0c050cb2: /* original 7420, guest PC 0x0c050cb2 */
if(!s->budget--) { s->failed_pc=0x0c050cb2u; return 0; }
r[4]+=0x00000020u;
goto P_0c050cb4;
P_0c050cb4: /* original d307, guest PC 0x0c050cb4 */
if(!s->budget--) { s->failed_pc=0x0c050cb4u; return 0; }
r[3]=read(ram,0x0c050cd4u,4);
goto P_0c050cb6;
P_0c050cb6: /* original 432b, guest PC 0x0c050cb6 */
if(!s->budget--) { s->failed_pc=0x0c050cb6u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c050e84u: goto P_0c050e84;
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
P_0c050cb8: /* original 0009, guest PC 0x0c050cb8 */
if(!s->budget--) { s->failed_pc=0x0c050cb8u; return 0; }
goto P_0c050cba;
P_0c050cba: /* original 0002, guest PC 0x0c050cba */
if(!s->budget--) { s->failed_pc=0x0c050cbau; return 0; }
r[0]=r[17];
goto P_0c050cbc;
P_0c050cbc: /* original 4009, guest PC 0x0c050cbc */
if(!s->budget--) { s->failed_pc=0x0c050cbcu; return 0; }
r[0]>>=2;
goto P_0c050cbe;
P_0c050cbe: /* original 4009, guest PC 0x0c050cbe */
if(!s->budget--) { s->failed_pc=0x0c050cbeu; return 0; }
r[0]>>=2;
goto P_0c050cc0;
P_0c050cc0: /* original c90f, guest PC 0x0c050cc0 */
if(!s->budget--) { s->failed_pc=0x0c050cc0u; return 0; }
r[0]&=15u;
goto P_0c050cc2;
P_0c050cc2: /* original 81f1, guest PC 0x0c050cc2 */
if(!s->budget--) { s->failed_pc=0x0c050cc2u; return 0; }
write(ram,r[15]+2,r[0],2);
goto P_0c050cc4;
P_0c050cc4: /* original 0002, guest PC 0x0c050cc4 */
if(!s->budget--) { s->failed_pc=0x0c050cc4u; return 0; }
r[0]=r[17];
goto P_0c050cc6;
P_0c050cc6: /* original 9204, guest PC 0x0c050cc6 */
if(!s->budget--) { s->failed_pc=0x0c050cc6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050cd2u,2);
goto P_0c050cc8;
P_0c050cc8: /* original 2029, guest PC 0x0c050cc8 */
if(!s->budget--) { s->failed_pc=0x0c050cc8u; return 0; }
r[0]&=r[2];
goto P_0c050cca;
P_0c050cca: /* original cbf0, guest PC 0x0c050cca */
if(!s->budget--) { s->failed_pc=0x0c050ccau; return 0; }
r[0]|=240u;
goto P_0c050ccc;
P_0c050ccc: /* original 400e, guest PC 0x0c050ccc */
if(!s->budget--) { s->failed_pc=0x0c050cccu; return 0; }
r[17]=r[0];
goto P_0c050cce;
P_0c050cce: /* original a003, guest PC 0x0c050cce */
if(!s->budget--) { s->failed_pc=0x0c050cceu; return 0; }
goto P_0c050cd8;
P_0c050cd0: /* original 0009, guest PC 0x0c050cd0 */
if(!s->budget--) { s->failed_pc=0x0c050cd0u; return 0; }
if(!vf3_matrix_family(0x0c050cd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050cd2u; return 0; } return 1;
P_0c050cd8: /* original c703, guest PC 0x0c050cd8 */
if(!s->budget--) { s->failed_pc=0x0c050cd8u; return 0; }
r[0]=code_base|0x00050ce8u;
goto P_0c050cda;
P_0c050cda: /* original d102, guest PC 0x0c050cda */
if(!s->budget--) { s->failed_pc=0x0c050cdau; return 0; }
r[1]=read(ram,0x0c050ce4u,4);
goto P_0c050cdc;
P_0c050cdc: /* original 210b, guest PC 0x0c050cdc */
if(!s->budget--) { s->failed_pc=0x0c050cdcu; return 0; }
r[1]|=r[0];
goto P_0c050cde;
P_0c050cde: /* original 412b, guest PC 0x0c050cde */
if(!s->budget--) { s->failed_pc=0x0c050cdeu; return 0; }
target=r[1];
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
P_0c050ce0: /* original 0009, guest PC 0x0c050ce0 */
if(!s->budget--) { s->failed_pc=0x0c050ce0u; return 0; }
if(!vf3_matrix_family(0x0c050ce2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050ce2u; return 0; } return 1;
P_0c050e84: /* original 7f24, guest PC 0x0c050e84 */
if(!s->budget--) { s->failed_pc=0x0c050e84u; return 0; }
r[15]+=0x00000024u;
goto P_0c050e86;
P_0c050e86: /* original 000b, guest PC 0x0c050e86 */
if(!s->budget--) { s->failed_pc=0x0c050e86u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c050e88: /* original 0009, guest PC 0x0c050e88 */
if(!s->budget--) { s->failed_pc=0x0c050e88u; return 0; }
goto P_0c050e8a;
P_0c050e8a: /* original 7fdc, guest PC 0x0c050e8a */
if(!s->budget--) { s->failed_pc=0x0c050e8au; return 0; }
r[15]+=0xffffffdcu;
goto P_0c050e8c;
P_0c050e8c: /* original 1f48, guest PC 0x0c050e8c */
if(!s->budget--) { s->failed_pc=0x0c050e8cu; return 0; }
write(ram,r[15]+32,r[4],4);
goto P_0c050e8e;
P_0c050e8e: /* original 1f57, guest PC 0x0c050e8e */
if(!s->budget--) { s->failed_pc=0x0c050e8eu; return 0; }
write(ram,r[15]+28,r[5],4);
goto P_0c050e90;
P_0c050e90: /* original 51f7, guest PC 0x0c050e90 */
if(!s->budget--) { s->failed_pc=0x0c050e90u; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c050e92;
P_0c050e92: /* original 2118, guest PC 0x0c050e92 */
if(!s->budget--) { s->failed_pc=0x0c050e92u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c050e94;
P_0c050e94: /* original 8b02, guest PC 0x0c050e94 */
if(!s->budget--) { s->failed_pc=0x0c050e94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050e9c; }
goto P_0c050e96;
P_0c050e96: /* original d10a, guest PC 0x0c050e96 */
if(!s->budget--) { s->failed_pc=0x0c050e96u; return 0; }
r[1]=read(ram,0x0c050ec0u,4);
goto P_0c050e98;
P_0c050e98: /* original 412b, guest PC 0x0c050e98 */
if(!s->budget--) { s->failed_pc=0x0c050e98u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0510b0u: goto P_0c0510b0;
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
P_0c050e9a: /* original 0009, guest PC 0x0c050e9a */
if(!s->budget--) { s->failed_pc=0x0c050e9au; return 0; }
goto P_0c050e9c;
P_0c050e9c: /* original d109, guest PC 0x0c050e9c */
if(!s->budget--) { s->failed_pc=0x0c050e9cu; return 0; }
r[1]=read(ram,0x0c050ec4u,4);
goto P_0c050e9e;
P_0c050e9e: /* original 50f7, guest PC 0x0c050e9e */
if(!s->budget--) { s->failed_pc=0x0c050e9eu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c050ea0;
P_0c050ea0: /* original 3012, guest PC 0x0c050ea0 */
if(!s->budget--) { s->failed_pc=0x0c050ea0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c050ea2;
P_0c050ea2: /* original 8b02, guest PC 0x0c050ea2 */
if(!s->budget--) { s->failed_pc=0x0c050ea2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050eaa; }
goto P_0c050ea4;
P_0c050ea4: /* original d308, guest PC 0x0c050ea4 */
if(!s->budget--) { s->failed_pc=0x0c050ea4u; return 0; }
r[3]=read(ram,0x0c050ec8u,4);
goto P_0c050ea6;
P_0c050ea6: /* original 432b, guest PC 0x0c050ea6 */
if(!s->budget--) { s->failed_pc=0x0c050ea6u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c050ee6u: goto P_0c050ee6;
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
P_0c050ea8: /* original 0009, guest PC 0x0c050ea8 */
if(!s->budget--) { s->failed_pc=0x0c050ea8u; return 0; }
goto P_0c050eaa;
P_0c050eaa: /* original 50f8, guest PC 0x0c050eaa */
if(!s->budget--) { s->failed_pc=0x0c050eaau; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c050eac;
P_0c050eac: /* original c91f, guest PC 0x0c050eac */
if(!s->budget--) { s->failed_pc=0x0c050eacu; return 0; }
r[0]&=31u;
goto P_0c050eae;
P_0c050eae: /* original 55f7, guest PC 0x0c050eae */
if(!s->budget--) { s->failed_pc=0x0c050eaeu; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c050eb0;
P_0c050eb0: /* original 350c, guest PC 0x0c050eb0 */
if(!s->budget--) { s->failed_pc=0x0c050eb0u; return 0; }
r[5]+=r[0];
goto P_0c050eb2;
P_0c050eb2: /* original d306, guest PC 0x0c050eb2 */
if(!s->budget--) { s->failed_pc=0x0c050eb2u; return 0; }
r[3]=read(ram,0x0c050eccu,4);
goto P_0c050eb4;
P_0c050eb4: /* original 54f8, guest PC 0x0c050eb4 */
if(!s->budget--) { s->failed_pc=0x0c050eb4u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c050eb6;
P_0c050eb6: /* original 2439, guest PC 0x0c050eb6 */
if(!s->budget--) { s->failed_pc=0x0c050eb6u; return 0; }
r[4]&=r[3];
goto P_0c050eb8;
P_0c050eb8: /* original a00a, guest PC 0x0c050eb8 */
if(!s->budget--) { s->failed_pc=0x0c050eb8u; return 0; }
goto P_0c050ed0;
P_0c050eba: /* original 0009, guest PC 0x0c050eba */
if(!s->budget--) { s->failed_pc=0x0c050ebau; return 0; }
if(!vf3_matrix_family(0x0c050ebcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050ebcu; return 0; } return 1;
P_0c050ed0: /* original 751f, guest PC 0x0c050ed0 */
if(!s->budget--) { s->failed_pc=0x0c050ed0u; return 0; }
r[5]+=0x0000001fu;
goto P_0c050ed2;
P_0c050ed2: /* original 4509, guest PC 0x0c050ed2 */
if(!s->budget--) { s->failed_pc=0x0c050ed2u; return 0; }
r[5]>>=2;
goto P_0c050ed4;
P_0c050ed4: /* original 4509, guest PC 0x0c050ed4 */
if(!s->budget--) { s->failed_pc=0x0c050ed4u; return 0; }
r[5]>>=2;
goto P_0c050ed6;
P_0c050ed6: /* original 4501, guest PC 0x0c050ed6 */
if(!s->budget--) { s->failed_pc=0x0c050ed6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c050ed8;
P_0c050ed8: /* original 04a3, guest PC 0x0c050ed8 */
if(!s->budget--) { s->failed_pc=0x0c050ed8u; return 0; }
goto P_0c050eda;
P_0c050eda: /* original 4510, guest PC 0x0c050eda */
if(!s->budget--) { s->failed_pc=0x0c050edau; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c050edc;
P_0c050edc: /* original 8ffc, guest PC 0x0c050edc */
if(!s->budget--) { s->failed_pc=0x0c050edcu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000020u;
if(!cond) { goto P_0c050ed8; }
goto P_0c050ee0;
P_0c050ede: /* original 7420, guest PC 0x0c050ede */
if(!s->budget--) { s->failed_pc=0x0c050edeu; return 0; }
r[4]+=0x00000020u;
goto P_0c050ee0;
P_0c050ee0: /* original d307, guest PC 0x0c050ee0 */
if(!s->budget--) { s->failed_pc=0x0c050ee0u; return 0; }
r[3]=read(ram,0x0c050f00u,4);
goto P_0c050ee2;
P_0c050ee2: /* original 432b, guest PC 0x0c050ee2 */
if(!s->budget--) { s->failed_pc=0x0c050ee2u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0510b0u: goto P_0c0510b0;
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
P_0c050ee4: /* original 0009, guest PC 0x0c050ee4 */
if(!s->budget--) { s->failed_pc=0x0c050ee4u; return 0; }
goto P_0c050ee6;
P_0c050ee6: /* original 0002, guest PC 0x0c050ee6 */
if(!s->budget--) { s->failed_pc=0x0c050ee6u; return 0; }
r[0]=r[17];
goto P_0c050ee8;
P_0c050ee8: /* original 4009, guest PC 0x0c050ee8 */
if(!s->budget--) { s->failed_pc=0x0c050ee8u; return 0; }
r[0]>>=2;
goto P_0c050eea;
P_0c050eea: /* original 4009, guest PC 0x0c050eea */
if(!s->budget--) { s->failed_pc=0x0c050eeau; return 0; }
r[0]>>=2;
goto P_0c050eec;
P_0c050eec: /* original c90f, guest PC 0x0c050eec */
if(!s->budget--) { s->failed_pc=0x0c050eecu; return 0; }
r[0]&=15u;
goto P_0c050eee;
P_0c050eee: /* original 81f1, guest PC 0x0c050eee */
if(!s->budget--) { s->failed_pc=0x0c050eeeu; return 0; }
write(ram,r[15]+2,r[0],2);
goto P_0c050ef0;
P_0c050ef0: /* original 0002, guest PC 0x0c050ef0 */
if(!s->budget--) { s->failed_pc=0x0c050ef0u; return 0; }
r[0]=r[17];
goto P_0c050ef2;
P_0c050ef2: /* original 9304, guest PC 0x0c050ef2 */
if(!s->budget--) { s->failed_pc=0x0c050ef2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050efeu,2);
goto P_0c050ef4;
P_0c050ef4: /* original 2039, guest PC 0x0c050ef4 */
if(!s->budget--) { s->failed_pc=0x0c050ef4u; return 0; }
r[0]&=r[3];
goto P_0c050ef6;
P_0c050ef6: /* original cbf0, guest PC 0x0c050ef6 */
if(!s->budget--) { s->failed_pc=0x0c050ef6u; return 0; }
r[0]|=240u;
goto P_0c050ef8;
P_0c050ef8: /* original 400e, guest PC 0x0c050ef8 */
if(!s->budget--) { s->failed_pc=0x0c050ef8u; return 0; }
r[17]=r[0];
goto P_0c050efa;
P_0c050efa: /* original a003, guest PC 0x0c050efa */
if(!s->budget--) { s->failed_pc=0x0c050efau; return 0; }
goto P_0c050f04;
P_0c050efc: /* original 0009, guest PC 0x0c050efc */
if(!s->budget--) { s->failed_pc=0x0c050efcu; return 0; }
if(!vf3_matrix_family(0x0c050efeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050efeu; return 0; } return 1;
P_0c050f04: /* original c703, guest PC 0x0c050f04 */
if(!s->budget--) { s->failed_pc=0x0c050f04u; return 0; }
r[0]=code_base|0x00050f14u;
goto P_0c050f06;
P_0c050f06: /* original d102, guest PC 0x0c050f06 */
if(!s->budget--) { s->failed_pc=0x0c050f06u; return 0; }
r[1]=read(ram,0x0c050f10u,4);
goto P_0c050f08;
P_0c050f08: /* original 210b, guest PC 0x0c050f08 */
if(!s->budget--) { s->failed_pc=0x0c050f08u; return 0; }
r[1]|=r[0];
goto P_0c050f0a;
P_0c050f0a: /* original 412b, guest PC 0x0c050f0a */
if(!s->budget--) { s->failed_pc=0x0c050f0au; return 0; }
target=r[1];
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
P_0c050f0c: /* original 0009, guest PC 0x0c050f0c */
if(!s->budget--) { s->failed_pc=0x0c050f0cu; return 0; }
if(!vf3_matrix_family(0x0c050f0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050f0eu; return 0; } return 1;
P_0c0510b0: /* original 7f24, guest PC 0x0c0510b0 */
if(!s->budget--) { s->failed_pc=0x0c0510b0u; return 0; }
r[15]+=0x00000024u;
goto P_0c0510b2;
P_0c0510b2: /* original 000b, guest PC 0x0c0510b2 */
if(!s->budget--) { s->failed_pc=0x0c0510b2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0510b4: /* original 0009, guest PC 0x0c0510b4 */
if(!s->budget--) { s->failed_pc=0x0c0510b4u; return 0; }
if(!vf3_matrix_family(0x0c0510b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0510b6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
