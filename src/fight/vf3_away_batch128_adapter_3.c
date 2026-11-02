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
int vf3_away_batch128_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05fcc4u: goto P_0c05fcc4;
case 0x0c05fcc6u: goto P_0c05fcc6;
case 0x0c05fcc8u: goto P_0c05fcc8;
case 0x0c05fccau: goto P_0c05fcca;
case 0x0c05fcccu: goto P_0c05fccc;
case 0x0c05fcceu: goto P_0c05fcce;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0a1204u: goto P_0c0a1204;
case 0x0c0a1206u: goto P_0c0a1206;
case 0x0c0a1208u: goto P_0c0a1208;
case 0x0c0a120au: goto P_0c0a120a;
case 0x0c0a120cu: goto P_0c0a120c;
case 0x0c0a120eu: goto P_0c0a120e;
case 0x0c0a1210u: goto P_0c0a1210;
case 0x0c0a1212u: goto P_0c0a1212;
case 0x0c0a1214u: goto P_0c0a1214;
case 0x0c0a1216u: goto P_0c0a1216;
case 0x0c0a1218u: goto P_0c0a1218;
case 0x0c0a121au: goto P_0c0a121a;
case 0x0c0a121cu: goto P_0c0a121c;
case 0x0c0a121eu: goto P_0c0a121e;
case 0x0c0a1220u: goto P_0c0a1220;
case 0x0c0a1222u: goto P_0c0a1222;
case 0x0c0a1224u: goto P_0c0a1224;
case 0x0c0a1226u: goto P_0c0a1226;
case 0x0c0a1228u: goto P_0c0a1228;
case 0x0c0a122au: goto P_0c0a122a;
case 0x0c0a122cu: goto P_0c0a122c;
case 0x0c0a122eu: goto P_0c0a122e;
case 0x0c0a1230u: goto P_0c0a1230;
case 0x0c0a1232u: goto P_0c0a1232;
case 0x0c0a1234u: goto P_0c0a1234;
case 0x0c0a1236u: goto P_0c0a1236;
case 0x0c0a1238u: goto P_0c0a1238;
case 0x0c0a123au: goto P_0c0a123a;
case 0x0c0a123cu: goto P_0c0a123c;
case 0x0c0a123eu: goto P_0c0a123e;
case 0x0c0a1240u: goto P_0c0a1240;
case 0x0c0a1242u: goto P_0c0a1242;
case 0x0c0a1244u: goto P_0c0a1244;
case 0x0c0a1246u: goto P_0c0a1246;
case 0x0c0a1248u: goto P_0c0a1248;
case 0x0c0a124au: goto P_0c0a124a;
case 0x0c0a124cu: goto P_0c0a124c;
case 0x0c0a124eu: goto P_0c0a124e;
case 0x0c0a1250u: goto P_0c0a1250;
case 0x0c0a1252u: goto P_0c0a1252;
case 0x0c0a1254u: goto P_0c0a1254;
case 0x0c0a1256u: goto P_0c0a1256;
case 0x0c0a1258u: goto P_0c0a1258;
case 0x0c0a125au: goto P_0c0a125a;
case 0x0c0a125cu: goto P_0c0a125c;
case 0x0c0a125eu: goto P_0c0a125e;
case 0x0c0a1260u: goto P_0c0a1260;
case 0x0c0a1262u: goto P_0c0a1262;
case 0x0c0a1264u: goto P_0c0a1264;
case 0x0c0a1266u: goto P_0c0a1266;
case 0x0c0a1268u: goto P_0c0a1268;
case 0x0c0a126au: goto P_0c0a126a;
case 0x0c0a126cu: goto P_0c0a126c;
case 0x0c0a126eu: goto P_0c0a126e;
case 0x0c0a1270u: goto P_0c0a1270;
case 0x0c0a1272u: goto P_0c0a1272;
case 0x0c0a1274u: goto P_0c0a1274;
case 0x0c0a1276u: goto P_0c0a1276;
case 0x0c0a1278u: goto P_0c0a1278;
case 0x0c0a127au: goto P_0c0a127a;
case 0x0c0a127cu: goto P_0c0a127c;
case 0x0c0a127eu: goto P_0c0a127e;
case 0x0c0a1280u: goto P_0c0a1280;
case 0x0c0a13c2u: goto P_0c0a13c2;
case 0x0c0a13c4u: goto P_0c0a13c4;
case 0x0c0a13c6u: goto P_0c0a13c6;
case 0x0c0a13c8u: goto P_0c0a13c8;
case 0x0c0a13cau: goto P_0c0a13ca;
case 0x0c0a13ccu: goto P_0c0a13cc;
case 0x0c0a13ceu: goto P_0c0a13ce;
case 0x0c0a13d0u: goto P_0c0a13d0;
case 0x0c0a13d2u: goto P_0c0a13d2;
case 0x0c0a13d4u: goto P_0c0a13d4;
case 0x0c0a2000u: goto P_0c0a2000;
case 0x0c0a2002u: goto P_0c0a2002;
case 0x0c0a2004u: goto P_0c0a2004;
case 0x0c0a2006u: goto P_0c0a2006;
case 0x0c0a2008u: goto P_0c0a2008;
case 0x0c0a200au: goto P_0c0a200a;
case 0x0c0a200cu: goto P_0c0a200c;
case 0x0c0a200eu: goto P_0c0a200e;
case 0x0c0a2010u: goto P_0c0a2010;
case 0x0c0a2012u: goto P_0c0a2012;
case 0x0c0a2014u: goto P_0c0a2014;
case 0x0c0a2016u: goto P_0c0a2016;
case 0x0c0a2018u: goto P_0c0a2018;
case 0x0c0a201au: goto P_0c0a201a;
case 0x0c0a201cu: goto P_0c0a201c;
case 0x0c0a201eu: goto P_0c0a201e;
case 0x0c0a2020u: goto P_0c0a2020;
case 0x0c0a2022u: goto P_0c0a2022;
case 0x0c0a2024u: goto P_0c0a2024;
case 0x0c0a2026u: goto P_0c0a2026;
case 0x0c0a2028u: goto P_0c0a2028;
case 0x0c0a202au: goto P_0c0a202a;
case 0x0c0a202cu: goto P_0c0a202c;
case 0x0c0a202eu: goto P_0c0a202e;
case 0x0c0a2030u: goto P_0c0a2030;
case 0x0c0a2032u: goto P_0c0a2032;
case 0x0c0a2034u: goto P_0c0a2034;
case 0x0c0a2036u: goto P_0c0a2036;
case 0x0c0a2038u: goto P_0c0a2038;
case 0x0c0a203au: goto P_0c0a203a;
case 0x0c0a203cu: goto P_0c0a203c;
case 0x0c0a203eu: goto P_0c0a203e;
case 0x0c0a2040u: goto P_0c0a2040;
case 0x0c0a2042u: goto P_0c0a2042;
case 0x0c0a2044u: goto P_0c0a2044;
case 0x0c0a2046u: goto P_0c0a2046;
case 0x0c0a2048u: goto P_0c0a2048;
case 0x0c0a204au: goto P_0c0a204a;
case 0x0c0a204cu: goto P_0c0a204c;
case 0x0c0a204eu: goto P_0c0a204e;
case 0x0c0a2050u: goto P_0c0a2050;
case 0x0c0a2052u: goto P_0c0a2052;
case 0x0c0a2054u: goto P_0c0a2054;
case 0x0c0a2056u: goto P_0c0a2056;
case 0x0c0a2058u: goto P_0c0a2058;
case 0x0c0a205au: goto P_0c0a205a;
case 0x0c0a205cu: goto P_0c0a205c;
case 0x0c0a205eu: goto P_0c0a205e;
case 0x0c0a2060u: goto P_0c0a2060;
case 0x0c0a2062u: goto P_0c0a2062;
case 0x0c0a2064u: goto P_0c0a2064;
case 0x0c0a2066u: goto P_0c0a2066;
case 0x0c0a2068u: goto P_0c0a2068;
case 0x0c0a206au: goto P_0c0a206a;
case 0x0c0a206cu: goto P_0c0a206c;
case 0x0c0a206eu: goto P_0c0a206e;
case 0x0c0a2070u: goto P_0c0a2070;
case 0x0c0a2072u: goto P_0c0a2072;
case 0x0c0a2074u: goto P_0c0a2074;
case 0x0c0a2076u: goto P_0c0a2076;
case 0x0c0a2078u: goto P_0c0a2078;
case 0x0c0a207au: goto P_0c0a207a;
case 0x0c0a207cu: goto P_0c0a207c;
case 0x0c0a207eu: goto P_0c0a207e;
case 0x0c0a2080u: goto P_0c0a2080;
case 0x0c0a2082u: goto P_0c0a2082;
case 0x0c0a2084u: goto P_0c0a2084;
case 0x0c0a2086u: goto P_0c0a2086;
case 0x0c0a2088u: goto P_0c0a2088;
case 0x0c0a208au: goto P_0c0a208a;
case 0x0c0a208cu: goto P_0c0a208c;
case 0x0c0a208eu: goto P_0c0a208e;
case 0x0c0a2090u: goto P_0c0a2090;
case 0x0c0a2092u: goto P_0c0a2092;
case 0x0c0a2094u: goto P_0c0a2094;
case 0x0c0a2096u: goto P_0c0a2096;
case 0x0c0a2098u: goto P_0c0a2098;
case 0x0c0a209au: goto P_0c0a209a;
case 0x0c0a209cu: goto P_0c0a209c;
case 0x0c0a209eu: goto P_0c0a209e;
case 0x0c0a20a0u: goto P_0c0a20a0;
case 0x0c0a20a2u: goto P_0c0a20a2;
case 0x0c0a20a4u: goto P_0c0a20a4;
case 0x0c0a20a6u: goto P_0c0a20a6;
case 0x0c0a20a8u: goto P_0c0a20a8;
case 0x0c0a20aau: goto P_0c0a20aa;
case 0x0c0a20acu: goto P_0c0a20ac;
case 0x0c0a20aeu: goto P_0c0a20ae;
case 0x0c0a20b0u: goto P_0c0a20b0;
case 0x0c0a20b2u: goto P_0c0a20b2;
case 0x0c0a20b4u: goto P_0c0a20b4;
case 0x0c0a20b6u: goto P_0c0a20b6;
case 0x0c0a20b8u: goto P_0c0a20b8;
case 0x0c0a20bau: goto P_0c0a20ba;
case 0x0c0a20bcu: goto P_0c0a20bc;
case 0x0c0a20beu: goto P_0c0a20be;
case 0x0c0a20c0u: goto P_0c0a20c0;
case 0x0c0a20c2u: goto P_0c0a20c2;
case 0x0c0a20c4u: goto P_0c0a20c4;
case 0x0c0a20c6u: goto P_0c0a20c6;
case 0x0c0a20c8u: goto P_0c0a20c8;
case 0x0c0a20cau: goto P_0c0a20ca;
case 0x0c0a20ccu: goto P_0c0a20cc;
case 0x0c0a20ceu: goto P_0c0a20ce;
case 0x0c0a20d0u: goto P_0c0a20d0;
case 0x0c0a20d2u: goto P_0c0a20d2;
case 0x0c0a20d4u: goto P_0c0a20d4;
case 0x0c0a20d6u: goto P_0c0a20d6;
case 0x0c0a20d8u: goto P_0c0a20d8;
case 0x0c0a20dau: goto P_0c0a20da;
case 0x0c0a20dcu: goto P_0c0a20dc;
case 0x0c0a20deu: goto P_0c0a20de;
case 0x0c0a20e0u: goto P_0c0a20e0;
case 0x0c0a20e2u: goto P_0c0a20e2;
case 0x0c0a20e4u: goto P_0c0a20e4;
case 0x0c0a20e6u: goto P_0c0a20e6;
case 0x0c0a20e8u: goto P_0c0a20e8;
case 0x0c0a20eau: goto P_0c0a20ea;
case 0x0c0a20ecu: goto P_0c0a20ec;
case 0x0c0a20eeu: goto P_0c0a20ee;
case 0x0c0a20f0u: goto P_0c0a20f0;
case 0x0c0a20f2u: goto P_0c0a20f2;
case 0x0c0a20f4u: goto P_0c0a20f4;
case 0x0c0a20f6u: goto P_0c0a20f6;
case 0x0c0a20f8u: goto P_0c0a20f8;
case 0x0c0a20fau: goto P_0c0a20fa;
case 0x0c0a20fcu: goto P_0c0a20fc;
case 0x0c0a20feu: goto P_0c0a20fe;
case 0x0c0a2100u: goto P_0c0a2100;
case 0x0c0a2102u: goto P_0c0a2102;
case 0x0c0a2104u: goto P_0c0a2104;
case 0x0c0a2106u: goto P_0c0a2106;
case 0x0c0a2108u: goto P_0c0a2108;
case 0x0c0a210au: goto P_0c0a210a;
case 0x0c0a210cu: goto P_0c0a210c;
case 0x0c0a210eu: goto P_0c0a210e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05fcc4: /* original d330, guest PC 0x0c05fcc4 */
if(!s->budget--) { s->failed_pc=0x0c05fcc4u; return 0; }
r[3]=read(ram,0x0c05fd88u,4);
goto P_0c05fcc6;
P_0c05fcc6: /* original 7ffc, guest PC 0x0c05fcc6 */
if(!s->budget--) { s->failed_pc=0x0c05fcc6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05fcc8;
P_0c05fcc8: /* original 2f42, guest PC 0x0c05fcc8 */
if(!s->budget--) { s->failed_pc=0x0c05fcc8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05fcca;
P_0c05fcca: /* original 6232, guest PC 0x0c05fcca */
if(!s->budget--) { s->failed_pc=0x0c05fccau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05fccc;
P_0c05fccc: /* original 422b, guest PC 0x0c05fccc */
if(!s->budget--) { s->failed_pc=0x0c05fcccu; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c05fcce: /* original 7f04, guest PC 0x0c05fcce */
if(!s->budget--) { s->failed_pc=0x0c05fcceu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c05fcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fcd0u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c0a1204: /* original 2fe6, guest PC 0x0c0a1204 */
if(!s->budget--) { s->failed_pc=0x0c0a1204u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1206;
P_0c0a1206: /* original 2fd6, guest PC 0x0c0a1206 */
if(!s->budget--) { s->failed_pc=0x0c0a1206u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1208;
P_0c0a1208: /* original 2fc6, guest PC 0x0c0a1208 */
if(!s->budget--) { s->failed_pc=0x0c0a1208u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a120a;
P_0c0a120a: /* original 2fb6, guest PC 0x0c0a120a */
if(!s->budget--) { s->failed_pc=0x0c0a120au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a120c;
P_0c0a120c: /* original 2fa6, guest PC 0x0c0a120c */
if(!s->budget--) { s->failed_pc=0x0c0a120cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a120e;
P_0c0a120e: /* original 2f96, guest PC 0x0c0a120e */
if(!s->budget--) { s->failed_pc=0x0c0a120eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1210;
P_0c0a1210: /* original 2f86, guest PC 0x0c0a1210 */
if(!s->budget--) { s->failed_pc=0x0c0a1210u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1212;
P_0c0a1212: /* original 4f22, guest PC 0x0c0a1212 */
if(!s->budget--) { s->failed_pc=0x0c0a1212u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1214;
P_0c0a1214: /* original d33b, guest PC 0x0c0a1214 */
if(!s->budget--) { s->failed_pc=0x0c0a1214u; return 0; }
r[3]=read(ram,0x0c0a1304u,4);
goto P_0c0a1216;
P_0c0a1216: /* original de3a, guest PC 0x0c0a1216 */
if(!s->budget--) { s->failed_pc=0x0c0a1216u; return 0; }
r[14]=read(ram,0x0c0a1300u,4);
goto P_0c0a1218;
P_0c0a1218: /* original 430b, guest PC 0x0c0a1218 */
if(!s->budget--) { s->failed_pc=0x0c0a1218u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a121cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a121cu) { target=s->pc; goto dispatch; }
goto P_0c0a121c;
P_0c0a121a: /* original 0009, guest PC 0x0c0a121a */
if(!s->budget--) { s->failed_pc=0x0c0a121au; return 0; }
goto P_0c0a121c;
P_0c0a121c: /* original dc3a, guest PC 0x0c0a121c */
if(!s->budget--) { s->failed_pc=0x0c0a121cu; return 0; }
r[12]=read(ram,0x0c0a1308u,4);
goto P_0c0a121e;
P_0c0a121e: /* original ed00, guest PC 0x0c0a121e */
if(!s->budget--) { s->failed_pc=0x0c0a121eu; return 0; }
r[13]=0x00000000u;
goto P_0c0a1220;
P_0c0a1220: /* original 9b60, guest PC 0x0c0a1220 */
if(!s->budget--) { s->failed_pc=0x0c0a1220u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a12e4u,2);
goto P_0c0a1222;
P_0c0a1222: /* original 6ad3, guest PC 0x0c0a1222 */
if(!s->budget--) { s->failed_pc=0x0c0a1222u; return 0; }
r[10]=r[13];
goto P_0c0a1224;
P_0c0a1224: /* original e8fe, guest PC 0x0c0a1224 */
if(!s->budget--) { s->failed_pc=0x0c0a1224u; return 0; }
r[8]=0xfffffffeu;
goto P_0c0a1226;
P_0c0a1226: /* original e902, guest PC 0x0c0a1226 */
if(!s->budget--) { s->failed_pc=0x0c0a1226u; return 0; }
r[9]=0x00000002u;
goto P_0c0a1228;
P_0c0a1228: /* original 64a3, guest PC 0x0c0a1228 */
if(!s->budget--) { s->failed_pc=0x0c0a1228u; return 0; }
r[4]=r[10];
goto P_0c0a122a;
P_0c0a122a: /* original 63a3, guest PC 0x0c0a122a */
if(!s->budget--) { s->failed_pc=0x0c0a122au; return 0; }
r[3]=r[10];
goto P_0c0a122c;
P_0c0a122c: /* original 4308, guest PC 0x0c0a122c */
if(!s->budget--) { s->failed_pc=0x0c0a122cu; return 0; }
r[3]<<=2;
goto P_0c0a122e;
P_0c0a122e: /* original 1ed2, guest PC 0x0c0a122e */
if(!s->budget--) { s->failed_pc=0x0c0a122eu; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c0a1230;
P_0c0a1230: /* original 4400, guest PC 0x0c0a1230 */
if(!s->budget--) { s->failed_pc=0x0c0a1230u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a1232;
P_0c0a1232: /* original 1ed3, guest PC 0x0c0a1232 */
if(!s->budget--) { s->failed_pc=0x0c0a1232u; return 0; }
write(ram,r[14]+12,r[13],4);
goto P_0c0a1234;
P_0c0a1234: /* original 1ed4, guest PC 0x0c0a1234 */
if(!s->budget--) { s->failed_pc=0x0c0a1234u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c0a1236;
P_0c0a1236: /* original d235, guest PC 0x0c0a1236 */
if(!s->budget--) { s->failed_pc=0x0c0a1236u; return 0; }
r[2]=read(ram,0x0c0a130cu,4);
goto P_0c0a1238;
P_0c0a1238: /* original 420b, guest PC 0x0c0a1238 */
if(!s->budget--) { s->failed_pc=0x0c0a1238u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a123cu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a123cu) { target=s->pc; goto dispatch; }
goto P_0c0a123c;
P_0c0a123a: /* original 343c, guest PC 0x0c0a123a */
if(!s->budget--) { s->failed_pc=0x0c0a123au; return 0; }
r[4]+=r[3];
goto P_0c0a123c;
P_0c0a123c: /* original 6403, guest PC 0x0c0a123c */
if(!s->budget--) { s->failed_pc=0x0c0a123cu; return 0; }
r[4]=r[0];
goto P_0c0a123e;
P_0c0a123e: /* original 5341, guest PC 0x0c0a123e */
if(!s->budget--) { s->failed_pc=0x0c0a123eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a1240;
P_0c0a1240: /* original 23b9, guest PC 0x0c0a1240 */
if(!s->budget--) { s->failed_pc=0x0c0a1240u; return 0; }
r[3]&=r[11];
goto P_0c0a1242;
P_0c0a1242: /* original 33b0, guest PC 0x0c0a1242 */
if(!s->budget--) { s->failed_pc=0x0c0a1242u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0a1244;
P_0c0a1244: /* original 8b01, guest PC 0x0c0a1244 */
if(!s->budget--) { s->failed_pc=0x0c0a1244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a124a; }
goto P_0c0a1246;
P_0c0a1246: /* original a007, guest PC 0x0c0a1246 */
if(!s->budget--) { s->failed_pc=0x0c0a1246u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c0a1258;
P_0c0a1248: /* original 2eb2, guest PC 0x0c0a1248 */
if(!s->budget--) { s->failed_pc=0x0c0a1248u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c0a124a;
P_0c0a124a: /* original 5241, guest PC 0x0c0a124a */
if(!s->budget--) { s->failed_pc=0x0c0a124au; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0a124c;
P_0c0a124c: /* original 22c9, guest PC 0x0c0a124c */
if(!s->budget--) { s->failed_pc=0x0c0a124cu; return 0; }
r[2]&=r[12];
goto P_0c0a124e;
P_0c0a124e: /* original 32c0, guest PC 0x0c0a124e */
if(!s->budget--) { s->failed_pc=0x0c0a124eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[12])!=0);
goto P_0c0a1250;
P_0c0a1250: /* original 8b01, guest PC 0x0c0a1250 */
if(!s->budget--) { s->failed_pc=0x0c0a1250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1256; }
goto P_0c0a1252;
P_0c0a1252: /* original a001, guest PC 0x0c0a1252 */
if(!s->budget--) { s->failed_pc=0x0c0a1252u; return 0; }
write(ram,r[14],r[12],4);
goto P_0c0a1258;
P_0c0a1254: /* original 2ec2, guest PC 0x0c0a1254 */
if(!s->budget--) { s->failed_pc=0x0c0a1254u; return 0; }
write(ram,r[14],r[12],4);
goto P_0c0a1256;
P_0c0a1256: /* original 2e82, guest PC 0x0c0a1256 */
if(!s->budget--) { s->failed_pc=0x0c0a1256u; return 0; }
write(ram,r[14],r[8],4);
goto P_0c0a1258;
P_0c0a1258: /* original 5341, guest PC 0x0c0a1258 */
if(!s->budget--) { s->failed_pc=0x0c0a1258u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a125a;
P_0c0a125a: /* original 7a01, guest PC 0x0c0a125a */
if(!s->budget--) { s->failed_pc=0x0c0a125au; return 0; }
r[10]+=0x00000001u;
goto P_0c0a125c;
P_0c0a125c: /* original 3a93, guest PC 0x0c0a125c */
if(!s->budget--) { s->failed_pc=0x0c0a125cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0a125e;
P_0c0a125e: /* original 1e31, guest PC 0x0c0a125e */
if(!s->budget--) { s->failed_pc=0x0c0a125eu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0a1260;
P_0c0a1260: /* original 5244, guest PC 0x0c0a1260 */
if(!s->budget--) { s->failed_pc=0x0c0a1260u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0a1262;
P_0c0a1262: /* original 1e22, guest PC 0x0c0a1262 */
if(!s->budget--) { s->failed_pc=0x0c0a1262u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0a1264;
P_0c0a1264: /* original 5345, guest PC 0x0c0a1264 */
if(!s->budget--) { s->failed_pc=0x0c0a1264u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0a1266;
P_0c0a1266: /* original 1e33, guest PC 0x0c0a1266 */
if(!s->budget--) { s->failed_pc=0x0c0a1266u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0a1268;
P_0c0a1268: /* original 5242, guest PC 0x0c0a1268 */
if(!s->budget--) { s->failed_pc=0x0c0a1268u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c0a126a;
P_0c0a126a: /* original 1e24, guest PC 0x0c0a126a */
if(!s->budget--) { s->failed_pc=0x0c0a126au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c0a126c;
P_0c0a126c: /* original 8fdc, guest PC 0x0c0a126c */
if(!s->budget--) { s->failed_pc=0x0c0a126cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c0a1228; }
goto P_0c0a1270;
P_0c0a126e: /* original 7e14, guest PC 0x0c0a126e */
if(!s->budget--) { s->failed_pc=0x0c0a126eu; return 0; }
r[14]+=0x00000014u;
goto P_0c0a1270;
P_0c0a1270: /* original 4f26, guest PC 0x0c0a1270 */
if(!s->budget--) { s->failed_pc=0x0c0a1270u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1272;
P_0c0a1272: /* original 68f6, guest PC 0x0c0a1272 */
if(!s->budget--) { s->failed_pc=0x0c0a1272u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a1274;
P_0c0a1274: /* original 69f6, guest PC 0x0c0a1274 */
if(!s->budget--) { s->failed_pc=0x0c0a1274u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a1276;
P_0c0a1276: /* original 6af6, guest PC 0x0c0a1276 */
if(!s->budget--) { s->failed_pc=0x0c0a1276u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a1278;
P_0c0a1278: /* original 6bf6, guest PC 0x0c0a1278 */
if(!s->budget--) { s->failed_pc=0x0c0a1278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a127a;
P_0c0a127a: /* original 6cf6, guest PC 0x0c0a127a */
if(!s->budget--) { s->failed_pc=0x0c0a127au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a127c;
P_0c0a127c: /* original 6df6, guest PC 0x0c0a127c */
if(!s->budget--) { s->failed_pc=0x0c0a127cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a127e;
P_0c0a127e: /* original 000b, guest PC 0x0c0a127e */
if(!s->budget--) { s->failed_pc=0x0c0a127eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a1280: /* original 6ef6, guest PC 0x0c0a1280 */
if(!s->budget--) { s->failed_pc=0x0c0a1280u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a1282u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1282u; return 0; } return 1;
P_0c0a13c2: /* original 4f22, guest PC 0x0c0a13c2 */
if(!s->budget--) { s->failed_pc=0x0c0a13c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a13c4;
P_0c0a13c4: /* original d31f, guest PC 0x0c0a13c4 */
if(!s->budget--) { s->failed_pc=0x0c0a13c4u; return 0; }
r[3]=read(ram,0x0c0a1444u,4);
goto P_0c0a13c6;
P_0c0a13c6: /* original 430b, guest PC 0x0c0a13c6 */
if(!s->budget--) { s->failed_pc=0x0c0a13c6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a13cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a13cau) { target=s->pc; goto dispatch; }
goto P_0c0a13ca;
P_0c0a13c8: /* original 0009, guest PC 0x0c0a13c8 */
if(!s->budget--) { s->failed_pc=0x0c0a13c8u; return 0; }
goto P_0c0a13ca;
P_0c0a13ca: /* original d21f, guest PC 0x0c0a13ca */
if(!s->budget--) { s->failed_pc=0x0c0a13cau; return 0; }
r[2]=read(ram,0x0c0a1448u,4);
goto P_0c0a13cc;
P_0c0a13cc: /* original 420b, guest PC 0x0c0a13cc */
if(!s->budget--) { s->failed_pc=0x0c0a13ccu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a13d0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a13d0u) { target=s->pc; goto dispatch; }
goto P_0c0a13d0;
P_0c0a13ce: /* original 0009, guest PC 0x0c0a13ce */
if(!s->budget--) { s->failed_pc=0x0c0a13ceu; return 0; }
goto P_0c0a13d0;
P_0c0a13d0: /* original d31e, guest PC 0x0c0a13d0 */
if(!s->budget--) { s->failed_pc=0x0c0a13d0u; return 0; }
r[3]=read(ram,0x0c0a144cu,4);
goto P_0c0a13d2;
P_0c0a13d2: /* original 432b, guest PC 0x0c0a13d2 */
if(!s->budget--) { s->failed_pc=0x0c0a13d2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c038cb0u: return vf3_matrix_family(0x0c038cb0u,s,ram);
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
P_0c0a13d4: /* original 4f26, guest PC 0x0c0a13d4 */
if(!s->budget--) { s->failed_pc=0x0c0a13d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a13d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a13d6u; return 0; } return 1;
P_0c0a2000: /* original 2fe6, guest PC 0x0c0a2000 */
if(!s->budget--) { s->failed_pc=0x0c0a2000u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2002;
P_0c0a2002: /* original 2fd6, guest PC 0x0c0a2002 */
if(!s->budget--) { s->failed_pc=0x0c0a2002u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2004;
P_0c0a2004: /* original 2fc6, guest PC 0x0c0a2004 */
if(!s->budget--) { s->failed_pc=0x0c0a2004u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2006;
P_0c0a2006: /* original 2fb6, guest PC 0x0c0a2006 */
if(!s->budget--) { s->failed_pc=0x0c0a2006u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2008;
P_0c0a2008: /* original 2fa6, guest PC 0x0c0a2008 */
if(!s->budget--) { s->failed_pc=0x0c0a2008u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a200a;
P_0c0a200a: /* original 2f96, guest PC 0x0c0a200a */
if(!s->budget--) { s->failed_pc=0x0c0a200au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a200c;
P_0c0a200c: /* original 2f86, guest PC 0x0c0a200c */
if(!s->budget--) { s->failed_pc=0x0c0a200cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a200e;
P_0c0a200e: /* original 4f22, guest PC 0x0c0a200e */
if(!s->budget--) { s->failed_pc=0x0c0a200eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2010;
P_0c0a2010: /* original db42, guest PC 0x0c0a2010 */
if(!s->budget--) { s->failed_pc=0x0c0a2010u; return 0; }
r[11]=read(ram,0x0c0a211cu,4);
goto P_0c0a2012;
P_0c0a2012: /* original 7ff4, guest PC 0x0c0a2012 */
if(!s->budget--) { s->failed_pc=0x0c0a2012u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2014;
P_0c0a2014: /* original 4b0b, guest PC 0x0c0a2014 */
if(!s->budget--) { s->failed_pc=0x0c0a2014u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a2018u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2018u) { target=s->pc; goto dispatch; }
goto P_0c0a2018;
P_0c0a2016: /* original e400, guest PC 0x0c0a2016 */
if(!s->budget--) { s->failed_pc=0x0c0a2016u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2018;
P_0c0a2018: /* original d341, guest PC 0x0c0a2018 */
if(!s->budget--) { s->failed_pc=0x0c0a2018u; return 0; }
r[3]=read(ram,0x0c0a2120u,4);
goto P_0c0a201a;
P_0c0a201a: /* original 430b, guest PC 0x0c0a201a */
if(!s->budget--) { s->failed_pc=0x0c0a201au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a201eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a201eu) { target=s->pc; goto dispatch; }
goto P_0c0a201e;
P_0c0a201c: /* original 0009, guest PC 0x0c0a201c */
if(!s->budget--) { s->failed_pc=0x0c0a201cu; return 0; }
goto P_0c0a201e;
P_0c0a201e: /* original d241, guest PC 0x0c0a201e */
if(!s->budget--) { s->failed_pc=0x0c0a201eu; return 0; }
r[2]=read(ram,0x0c0a2124u,4);
goto P_0c0a2020;
P_0c0a2020: /* original 420b, guest PC 0x0c0a2020 */
if(!s->budget--) { s->failed_pc=0x0c0a2020u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2024u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2024u) { target=s->pc; goto dispatch; }
goto P_0c0a2024;
P_0c0a2022: /* original e400, guest PC 0x0c0a2022 */
if(!s->budget--) { s->failed_pc=0x0c0a2022u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2024;
P_0c0a2024: /* original d340, guest PC 0x0c0a2024 */
if(!s->budget--) { s->failed_pc=0x0c0a2024u; return 0; }
r[3]=read(ram,0x0c0a2128u,4);
goto P_0c0a2026;
P_0c0a2026: /* original 430b, guest PC 0x0c0a2026 */
if(!s->budget--) { s->failed_pc=0x0c0a2026u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a202au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a202au) { target=s->pc; goto dispatch; }
goto P_0c0a202a;
P_0c0a2028: /* original e401, guest PC 0x0c0a2028 */
if(!s->budget--) { s->failed_pc=0x0c0a2028u; return 0; }
r[4]=0x00000001u;
goto P_0c0a202a;
P_0c0a202a: /* original d240, guest PC 0x0c0a202a */
if(!s->budget--) { s->failed_pc=0x0c0a202au; return 0; }
r[2]=read(ram,0x0c0a212cu,4);
goto P_0c0a202c;
P_0c0a202c: /* original 420b, guest PC 0x0c0a202c */
if(!s->budget--) { s->failed_pc=0x0c0a202cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2030u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2030u) { target=s->pc; goto dispatch; }
goto P_0c0a2030;
P_0c0a202e: /* original e400, guest PC 0x0c0a202e */
if(!s->budget--) { s->failed_pc=0x0c0a202eu; return 0; }
r[4]=0x00000000u;
goto P_0c0a2030;
P_0c0a2030: /* original d33f, guest PC 0x0c0a2030 */
if(!s->budget--) { s->failed_pc=0x0c0a2030u; return 0; }
r[3]=read(ram,0x0c0a2130u,4);
goto P_0c0a2032;
P_0c0a2032: /* original e500, guest PC 0x0c0a2032 */
if(!s->budget--) { s->failed_pc=0x0c0a2032u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2034;
P_0c0a2034: /* original 430b, guest PC 0x0c0a2034 */
if(!s->budget--) { s->failed_pc=0x0c0a2034u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2038u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2038u) { target=s->pc; goto dispatch; }
goto P_0c0a2038;
P_0c0a2036: /* original e403, guest PC 0x0c0a2036 */
if(!s->budget--) { s->failed_pc=0x0c0a2036u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2038;
P_0c0a2038: /* original 9c6a, guest PC 0x0c0a2038 */
if(!s->budget--) { s->failed_pc=0x0c0a2038u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2110u,2);
goto P_0c0a203a;
P_0c0a203a: /* original dd41, guest PC 0x0c0a203a */
if(!s->budget--) { s->failed_pc=0x0c0a203au; return 0; }
r[13]=read(ram,0x0c0a2140u,4);
goto P_0c0a203c;
P_0c0a203c: /* original de41, guest PC 0x0c0a203c */
if(!s->budget--) { s->failed_pc=0x0c0a203cu; return 0; }
r[14]=read(ram,0x0c0a2144u,4);
goto P_0c0a203e;
P_0c0a203e: /* original da3d, guest PC 0x0c0a203e */
if(!s->budget--) { s->failed_pc=0x0c0a203eu; return 0; }
r[10]=read(ram,0x0c0a2134u,4);
goto P_0c0a2040;
P_0c0a2040: /* original d83d, guest PC 0x0c0a2040 */
if(!s->budget--) { s->failed_pc=0x0c0a2040u; return 0; }
r[8]=read(ram,0x0c0a2138u,4);
goto P_0c0a2042;
P_0c0a2042: /* original d93e, guest PC 0x0c0a2042 */
if(!s->budget--) { s->failed_pc=0x0c0a2042u; return 0; }
r[9]=read(ram,0x0c0a213cu,4);
goto P_0c0a2044;
P_0c0a2044: /* original e560, guest PC 0x0c0a2044 */
if(!s->budget--) { s->failed_pc=0x0c0a2044u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2046;
P_0c0a2046: /* original 4e0b, guest PC 0x0c0a2046 */
if(!s->budget--) { s->failed_pc=0x0c0a2046u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a204au;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a204au) { target=s->pc; goto dispatch; }
goto P_0c0a204a;
P_0c0a2048: /* original e40c, guest PC 0x0c0a2048 */
if(!s->budget--) { s->failed_pc=0x0c0a2048u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a204a;
P_0c0a204a: /* original d33f, guest PC 0x0c0a204a */
if(!s->budget--) { s->failed_pc=0x0c0a204au; return 0; }
r[3]=read(ram,0x0c0a2148u,4);
goto P_0c0a204c;
P_0c0a204c: /* original 4d0b, guest PC 0x0c0a204c */
if(!s->budget--) { s->failed_pc=0x0c0a204cu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a2050u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2050u) { target=s->pc; goto dispatch; }
goto P_0c0a2050;
P_0c0a204e: /* original 2f36, guest PC 0x0c0a204e */
if(!s->budget--) { s->failed_pc=0x0c0a204eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2050;
P_0c0a2050: /* original 65c3, guest PC 0x0c0a2050 */
if(!s->budget--) { s->failed_pc=0x0c0a2050u; return 0; }
r[5]=r[12];
goto P_0c0a2052;
P_0c0a2052: /* original 4e0b, guest PC 0x0c0a2052 */
if(!s->budget--) { s->failed_pc=0x0c0a2052u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a2056u;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2056u) { target=s->pc; goto dispatch; }
goto P_0c0a2056;
P_0c0a2054: /* original e40c, guest PC 0x0c0a2054 */
if(!s->budget--) { s->failed_pc=0x0c0a2054u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2056;
P_0c0a2056: /* original d23d, guest PC 0x0c0a2056 */
if(!s->budget--) { s->failed_pc=0x0c0a2056u; return 0; }
r[2]=read(ram,0x0c0a214cu,4);
goto P_0c0a2058;
P_0c0a2058: /* original 4d0b, guest PC 0x0c0a2058 */
if(!s->budget--) { s->failed_pc=0x0c0a2058u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a205cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a205cu) { target=s->pc; goto dispatch; }
goto P_0c0a205c;
P_0c0a205a: /* original 2f26, guest PC 0x0c0a205a */
if(!s->budget--) { s->failed_pc=0x0c0a205au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a205c;
P_0c0a205c: /* original 7f08, guest PC 0x0c0a205c */
if(!s->budget--) { s->failed_pc=0x0c0a205cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a205e;
P_0c0a205e: /* original 490b, guest PC 0x0c0a205e */
if(!s->budget--) { s->failed_pc=0x0c0a205eu; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2062u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2062u) { target=s->pc; goto dispatch; }
goto P_0c0a2062;
P_0c0a2060: /* original e403, guest PC 0x0c0a2060 */
if(!s->budget--) { s->failed_pc=0x0c0a2060u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2062;
P_0c0a2062: /* original 480b, guest PC 0x0c0a2062 */
if(!s->budget--) { s->failed_pc=0x0c0a2062u; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2066u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2066u) { target=s->pc; goto dispatch; }
goto P_0c0a2066;
P_0c0a2064: /* original 0009, guest PC 0x0c0a2064 */
if(!s->budget--) { s->failed_pc=0x0c0a2064u; return 0; }
goto P_0c0a2066;
P_0c0a2066: /* original 4a0b, guest PC 0x0c0a2066 */
if(!s->budget--) { s->failed_pc=0x0c0a2066u; return 0; }
target=r[10];
r[16]=code_base|0x0c0a206au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a206au) { target=s->pc; goto dispatch; }
goto P_0c0a206a;
P_0c0a2068: /* original 0009, guest PC 0x0c0a2068 */
if(!s->budget--) { s->failed_pc=0x0c0a2068u; return 0; }
goto P_0c0a206a;
P_0c0a206a: /* original 2008, guest PC 0x0c0a206a */
if(!s->budget--) { s->failed_pc=0x0c0a206au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a206c;
P_0c0a206c: /* original 8903, guest PC 0x0c0a206c */
if(!s->budget--) { s->failed_pc=0x0c0a206cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2076; }
goto P_0c0a206e;
P_0c0a206e: /* original 4b0b, guest PC 0x0c0a206e */
if(!s->budget--) { s->failed_pc=0x0c0a206eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0a2072u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2072u) { target=s->pc; goto dispatch; }
goto P_0c0a2072;
P_0c0a2070: /* original e400, guest PC 0x0c0a2070 */
if(!s->budget--) { s->failed_pc=0x0c0a2070u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2072;
P_0c0a2072: /* original afe7, guest PC 0x0c0a2072 */
if(!s->budget--) { s->failed_pc=0x0c0a2072u; return 0; }
goto P_0c0a2044;
P_0c0a2074: /* original 0009, guest PC 0x0c0a2074 */
if(!s->budget--) { s->failed_pc=0x0c0a2074u; return 0; }
goto P_0c0a2076;
P_0c0a2076: /* original d32a, guest PC 0x0c0a2076 */
if(!s->budget--) { s->failed_pc=0x0c0a2076u; return 0; }
r[3]=read(ram,0x0c0a2120u,4);
goto P_0c0a2078;
P_0c0a2078: /* original 430b, guest PC 0x0c0a2078 */
if(!s->budget--) { s->failed_pc=0x0c0a2078u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a207cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a207cu) { target=s->pc; goto dispatch; }
goto P_0c0a207c;
P_0c0a207a: /* original 0009, guest PC 0x0c0a207a */
if(!s->budget--) { s->failed_pc=0x0c0a207au; return 0; }
goto P_0c0a207c;
P_0c0a207c: /* original d234, guest PC 0x0c0a207c */
if(!s->budget--) { s->failed_pc=0x0c0a207cu; return 0; }
r[2]=read(ram,0x0c0a2150u,4);
goto P_0c0a207e;
P_0c0a207e: /* original 420b, guest PC 0x0c0a207e */
if(!s->budget--) { s->failed_pc=0x0c0a207eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2082u;
r[10]=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2082u) { target=s->pc; goto dispatch; }
goto P_0c0a2082;
P_0c0a2080: /* original ea3c, guest PC 0x0c0a2080 */
if(!s->budget--) { s->failed_pc=0x0c0a2080u; return 0; }
r[10]=0x0000003cu;
goto P_0c0a2082;
P_0c0a2082: /* original 2008, guest PC 0x0c0a2082 */
if(!s->budget--) { s->failed_pc=0x0c0a2082u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2084;
P_0c0a2084: /* original 8d01, guest PC 0x0c0a2084 */
if(!s->budget--) { s->failed_pc=0x0c0a2084u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[0],4);
if(cond) { goto P_0c0a208a; }
goto P_0c0a2088;
P_0c0a2086: /* original 1f01, guest PC 0x0c0a2086 */
if(!s->budget--) { s->failed_pc=0x0c0a2086u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0a2088;
P_0c0a2088: /* original 9a43, guest PC 0x0c0a2088 */
if(!s->budget--) { s->failed_pc=0x0c0a2088u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2112u,2);
goto P_0c0a208a;
P_0c0a208a: /* original d432, guest PC 0x0c0a208a */
if(!s->budget--) { s->failed_pc=0x0c0a208au; return 0; }
r[4]=read(ram,0x0c0a2154u,4);
goto P_0c0a208c;
P_0c0a208c: /* original 6243, guest PC 0x0c0a208c */
if(!s->budget--) { s->failed_pc=0x0c0a208cu; return 0; }
r[2]=r[4];
goto P_0c0a208e;
P_0c0a208e: /* original 7410, guest PC 0x0c0a208e */
if(!s->budget--) { s->failed_pc=0x0c0a208eu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a2090;
P_0c0a2090: /* original 1f22, guest PC 0x0c0a2090 */
if(!s->budget--) { s->failed_pc=0x0c0a2090u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0a2092;
P_0c0a2092: /* original a02e, guest PC 0x0c0a2092 */
if(!s->budget--) { s->failed_pc=0x0c0a2092u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a20f2;
P_0c0a2094: /* original 2f42, guest PC 0x0c0a2094 */
if(!s->budget--) { s->failed_pc=0x0c0a2094u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a2096;
P_0c0a2096: /* original 913d, guest PC 0x0c0a2096 */
if(!s->budget--) { s->failed_pc=0x0c0a2096u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2114u,2);
goto P_0c0a2098;
P_0c0a2098: /* original 50f1, guest PC 0x0c0a2098 */
if(!s->budget--) { s->failed_pc=0x0c0a2098u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a209a;
P_0c0a209a: /* original 3010, guest PC 0x0c0a209a */
if(!s->budget--) { s->failed_pc=0x0c0a209au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0a209c;
P_0c0a209c: /* original 8907, guest PC 0x0c0a209c */
if(!s->budget--) { s->failed_pc=0x0c0a209cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a20ae; }
goto P_0c0a209e;
P_0c0a209e: /* original 8800, guest PC 0x0c0a209e */
if(!s->budget--) { s->failed_pc=0x0c0a209eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a20a0;
P_0c0a20a0: /* original 8b0c, guest PC 0x0c0a20a0 */
if(!s->budget--) { s->failed_pc=0x0c0a20a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a20bc; }
goto P_0c0a20a2;
P_0c0a20a2: /* original e560, guest PC 0x0c0a20a2 */
if(!s->budget--) { s->failed_pc=0x0c0a20a2u; return 0; }
r[5]=0x00000060u;
goto P_0c0a20a4;
P_0c0a20a4: /* original 4e0b, guest PC 0x0c0a20a4 */
if(!s->budget--) { s->failed_pc=0x0c0a20a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a20a8u;
r[4]=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20a8u) { target=s->pc; goto dispatch; }
goto P_0c0a20a8;
P_0c0a20a6: /* original e47c, guest PC 0x0c0a20a6 */
if(!s->budget--) { s->failed_pc=0x0c0a20a6u; return 0; }
r[4]=0x0000007cu;
goto P_0c0a20a8;
P_0c0a20a8: /* original d32b, guest PC 0x0c0a20a8 */
if(!s->budget--) { s->failed_pc=0x0c0a20a8u; return 0; }
r[3]=read(ram,0x0c0a2158u,4);
goto P_0c0a20aa;
P_0c0a20aa: /* original a00c, guest PC 0x0c0a20aa */
if(!s->budget--) { s->failed_pc=0x0c0a20aau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a20c6;
P_0c0a20ac: /* original 2f36, guest PC 0x0c0a20ac */
if(!s->budget--) { s->failed_pc=0x0c0a20acu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a20ae;
P_0c0a20ae: /* original e560, guest PC 0x0c0a20ae */
if(!s->budget--) { s->failed_pc=0x0c0a20aeu; return 0; }
r[5]=0x00000060u;
goto P_0c0a20b0;
P_0c0a20b0: /* original 4e0b, guest PC 0x0c0a20b0 */
if(!s->budget--) { s->failed_pc=0x0c0a20b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0a20b4u;
r[4]=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20b4u) { target=s->pc; goto dispatch; }
goto P_0c0a20b4;
P_0c0a20b2: /* original e44c, guest PC 0x0c0a20b2 */
if(!s->budget--) { s->failed_pc=0x0c0a20b2u; return 0; }
r[4]=0x0000004cu;
goto P_0c0a20b4;
P_0c0a20b4: /* original d329, guest PC 0x0c0a20b4 */
if(!s->budget--) { s->failed_pc=0x0c0a20b4u; return 0; }
r[3]=read(ram,0x0c0a215cu,4);
goto P_0c0a20b6;
P_0c0a20b6: /* original 4d0b, guest PC 0x0c0a20b6 */
if(!s->budget--) { s->failed_pc=0x0c0a20b6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a20bau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20bau) { target=s->pc; goto dispatch; }
goto P_0c0a20ba;
P_0c0a20b8: /* original 2f36, guest PC 0x0c0a20b8 */
if(!s->budget--) { s->failed_pc=0x0c0a20b8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a20ba;
P_0c0a20ba: /* original 7f04, guest PC 0x0c0a20ba */
if(!s->budget--) { s->failed_pc=0x0c0a20bau; return 0; }
r[15]+=0x00000004u;
goto P_0c0a20bc;
P_0c0a20bc: /* original 65c3, guest PC 0x0c0a20bc */
if(!s->budget--) { s->failed_pc=0x0c0a20bcu; return 0; }
r[5]=r[12];
goto P_0c0a20be;
P_0c0a20be: /* original 4e0b, guest PC 0x0c0a20be */
if(!s->budget--) { s->failed_pc=0x0c0a20beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0a20c2u;
r[4]=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20c2u) { target=s->pc; goto dispatch; }
goto P_0c0a20c2;
P_0c0a20c0: /* original e470, guest PC 0x0c0a20c0 */
if(!s->budget--) { s->failed_pc=0x0c0a20c0u; return 0; }
r[4]=0x00000070u;
goto P_0c0a20c2;
P_0c0a20c2: /* original d227, guest PC 0x0c0a20c2 */
if(!s->budget--) { s->failed_pc=0x0c0a20c2u; return 0; }
r[2]=read(ram,0x0c0a2160u,4);
goto P_0c0a20c4;
P_0c0a20c4: /* original 2f26, guest PC 0x0c0a20c4 */
if(!s->budget--) { s->failed_pc=0x0c0a20c4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a20c6;
P_0c0a20c6: /* original 4d0b, guest PC 0x0c0a20c6 */
if(!s->budget--) { s->failed_pc=0x0c0a20c6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a20cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20cau) { target=s->pc; goto dispatch; }
goto P_0c0a20ca;
P_0c0a20c8: /* original 0009, guest PC 0x0c0a20c8 */
if(!s->budget--) { s->failed_pc=0x0c0a20c8u; return 0; }
goto P_0c0a20ca;
P_0c0a20ca: /* original 7f04, guest PC 0x0c0a20ca */
if(!s->budget--) { s->failed_pc=0x0c0a20cau; return 0; }
r[15]+=0x00000004u;
goto P_0c0a20cc;
P_0c0a20cc: /* original 490b, guest PC 0x0c0a20cc */
if(!s->budget--) { s->failed_pc=0x0c0a20ccu; return 0; }
target=r[9];
r[16]=code_base|0x0c0a20d0u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20d0u) { target=s->pc; goto dispatch; }
goto P_0c0a20d0;
P_0c0a20ce: /* original e403, guest PC 0x0c0a20ce */
if(!s->budget--) { s->failed_pc=0x0c0a20ceu; return 0; }
r[4]=0x00000003u;
goto P_0c0a20d0;
P_0c0a20d0: /* original 480b, guest PC 0x0c0a20d0 */
if(!s->budget--) { s->failed_pc=0x0c0a20d0u; return 0; }
target=r[8];
r[16]=code_base|0x0c0a20d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20d4u) { target=s->pc; goto dispatch; }
goto P_0c0a20d4;
P_0c0a20d2: /* original 0009, guest PC 0x0c0a20d2 */
if(!s->budget--) { s->failed_pc=0x0c0a20d2u; return 0; }
goto P_0c0a20d4;
P_0c0a20d4: /* original 921f, guest PC 0x0c0a20d4 */
if(!s->budget--) { s->failed_pc=0x0c0a20d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2116u,2);
goto P_0c0a20d6;
P_0c0a20d6: /* original 3a23, guest PC 0x0c0a20d6 */
if(!s->budget--) { s->failed_pc=0x0c0a20d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[2])!=0);
goto P_0c0a20d8;
P_0c0a20d8: /* original 8909, guest PC 0x0c0a20d8 */
if(!s->budget--) { s->failed_pc=0x0c0a20d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a20ee; }
goto P_0c0a20da;
P_0c0a20da: /* original 51f2, guest PC 0x0c0a20da */
if(!s->budget--) { s->failed_pc=0x0c0a20dau; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0a20dc;
P_0c0a20dc: /* original 63f2, guest PC 0x0c0a20dc */
if(!s->budget--) { s->failed_pc=0x0c0a20dcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a20de;
P_0c0a20de: /* original 8513, guest PC 0x0c0a20de */
if(!s->budget--) { s->failed_pc=0x0c0a20deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+6,2);
goto P_0c0a20e0;
P_0c0a20e0: /* original 620d, guest PC 0x0c0a20e0 */
if(!s->budget--) { s->failed_pc=0x0c0a20e0u; return 0; }
r[2]=r[0]&65535u;
goto P_0c0a20e2;
P_0c0a20e2: /* original 8533, guest PC 0x0c0a20e2 */
if(!s->budget--) { s->failed_pc=0x0c0a20e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+6,2);
goto P_0c0a20e4;
P_0c0a20e4: /* original 9318, guest PC 0x0c0a20e4 */
if(!s->budget--) { s->failed_pc=0x0c0a20e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2118u,2);
goto P_0c0a20e6;
P_0c0a20e6: /* original 600d, guest PC 0x0c0a20e6 */
if(!s->budget--) { s->failed_pc=0x0c0a20e6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a20e8;
P_0c0a20e8: /* original 220b, guest PC 0x0c0a20e8 */
if(!s->budget--) { s->failed_pc=0x0c0a20e8u; return 0; }
r[2]|=r[0];
goto P_0c0a20ea;
P_0c0a20ea: /* original 2238, guest PC 0x0c0a20ea */
if(!s->budget--) { s->failed_pc=0x0c0a20eau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a20ec;
P_0c0a20ec: /* original 8b04, guest PC 0x0c0a20ec */
if(!s->budget--) { s->failed_pc=0x0c0a20ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a20f8; }
goto P_0c0a20ee;
P_0c0a20ee: /* original 4b0b, guest PC 0x0c0a20ee */
if(!s->budget--) { s->failed_pc=0x0c0a20eeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0a20f2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20f2u) { target=s->pc; goto dispatch; }
goto P_0c0a20f2;
P_0c0a20f0: /* original e400, guest PC 0x0c0a20f0 */
if(!s->budget--) { s->failed_pc=0x0c0a20f0u; return 0; }
r[4]=0x00000000u;
goto P_0c0a20f2;
P_0c0a20f2: /* original 2aa8, guest PC 0x0c0a20f2 */
if(!s->budget--) { s->failed_pc=0x0c0a20f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0a20f4;
P_0c0a20f4: /* original 8fcf, guest PC 0x0c0a20f4 */
if(!s->budget--) { s->failed_pc=0x0c0a20f4u; return 0; }
cond=r[17]&1u;
r[10]+=0xffffffffu;
if(!cond) { goto P_0c0a2096; }
goto P_0c0a20f8;
P_0c0a20f6: /* original 7aff, guest PC 0x0c0a20f6 */
if(!s->budget--) { s->failed_pc=0x0c0a20f6u; return 0; }
r[10]+=0xffffffffu;
goto P_0c0a20f8;
P_0c0a20f8: /* original 4b0b, guest PC 0x0c0a20f8 */
if(!s->budget--) { s->failed_pc=0x0c0a20f8u; return 0; }
target=r[11];
r[16]=code_base|0x0c0a20fcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a20fcu) { target=s->pc; goto dispatch; }
goto P_0c0a20fc;
P_0c0a20fa: /* original e400, guest PC 0x0c0a20fa */
if(!s->budget--) { s->failed_pc=0x0c0a20fau; return 0; }
r[4]=0x00000000u;
goto P_0c0a20fc;
P_0c0a20fc: /* original 7f0c, guest PC 0x0c0a20fc */
if(!s->budget--) { s->failed_pc=0x0c0a20fcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a20fe;
P_0c0a20fe: /* original 4f26, guest PC 0x0c0a20fe */
if(!s->budget--) { s->failed_pc=0x0c0a20feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2100;
P_0c0a2100: /* original 68f6, guest PC 0x0c0a2100 */
if(!s->budget--) { s->failed_pc=0x0c0a2100u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2102;
P_0c0a2102: /* original 69f6, guest PC 0x0c0a2102 */
if(!s->budget--) { s->failed_pc=0x0c0a2102u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2104;
P_0c0a2104: /* original 6af6, guest PC 0x0c0a2104 */
if(!s->budget--) { s->failed_pc=0x0c0a2104u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2106;
P_0c0a2106: /* original 6bf6, guest PC 0x0c0a2106 */
if(!s->budget--) { s->failed_pc=0x0c0a2106u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2108;
P_0c0a2108: /* original 6cf6, guest PC 0x0c0a2108 */
if(!s->budget--) { s->failed_pc=0x0c0a2108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a210a;
P_0c0a210a: /* original 6df6, guest PC 0x0c0a210a */
if(!s->budget--) { s->failed_pc=0x0c0a210au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a210c;
P_0c0a210c: /* original 000b, guest PC 0x0c0a210c */
if(!s->budget--) { s->failed_pc=0x0c0a210cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a210e: /* original 6ef6, guest PC 0x0c0a210e */
if(!s->budget--) { s->failed_pc=0x0c0a210eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2110u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2110u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
