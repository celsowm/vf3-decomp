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
int vf3_away_batch14_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c088fe0u: goto P_0c088fe0;
case 0x0c088fe2u: goto P_0c088fe2;
case 0x0c088fe4u: goto P_0c088fe4;
case 0x0c088fe6u: goto P_0c088fe6;
case 0x0c088fe8u: goto P_0c088fe8;
case 0x0c088feau: goto P_0c088fea;
case 0x0c088fecu: goto P_0c088fec;
case 0x0c088feeu: goto P_0c088fee;
case 0x0c088ff0u: goto P_0c088ff0;
case 0x0c088ff2u: goto P_0c088ff2;
case 0x0c088ff4u: goto P_0c088ff4;
case 0x0c088ff6u: goto P_0c088ff6;
case 0x0c088ff8u: goto P_0c088ff8;
case 0x0c088ffau: goto P_0c088ffa;
case 0x0c088ffcu: goto P_0c088ffc;
case 0x0c088ffeu: goto P_0c088ffe;
case 0x0c089000u: goto P_0c089000;
case 0x0c089002u: goto P_0c089002;
case 0x0c089004u: goto P_0c089004;
case 0x0c089006u: goto P_0c089006;
case 0x0c089008u: goto P_0c089008;
case 0x0c08900au: goto P_0c08900a;
case 0x0c08900cu: goto P_0c08900c;
case 0x0c08900eu: goto P_0c08900e;
case 0x0c089010u: goto P_0c089010;
case 0x0c089012u: goto P_0c089012;
case 0x0c089014u: goto P_0c089014;
case 0x0c089016u: goto P_0c089016;
case 0x0c089018u: goto P_0c089018;
case 0x0c08901au: goto P_0c08901a;
case 0x0c08901cu: goto P_0c08901c;
case 0x0c08901eu: goto P_0c08901e;
case 0x0c089020u: goto P_0c089020;
case 0x0c089022u: goto P_0c089022;
case 0x0c089024u: goto P_0c089024;
case 0x0c089026u: goto P_0c089026;
case 0x0c089028u: goto P_0c089028;
case 0x0c08902au: goto P_0c08902a;
case 0x0c08902cu: goto P_0c08902c;
case 0x0c08902eu: goto P_0c08902e;
case 0x0c089030u: goto P_0c089030;
case 0x0c089032u: goto P_0c089032;
case 0x0c089034u: goto P_0c089034;
case 0x0c089036u: goto P_0c089036;
case 0x0c089038u: goto P_0c089038;
case 0x0c08903au: goto P_0c08903a;
case 0x0c08903cu: goto P_0c08903c;
case 0x0c08903eu: goto P_0c08903e;
case 0x0c089040u: goto P_0c089040;
case 0x0c089042u: goto P_0c089042;
case 0x0c089044u: goto P_0c089044;
case 0x0c089046u: goto P_0c089046;
case 0x0c089048u: goto P_0c089048;
case 0x0c08904au: goto P_0c08904a;
case 0x0c08904cu: goto P_0c08904c;
case 0x0c08904eu: goto P_0c08904e;
case 0x0c089050u: goto P_0c089050;
case 0x0c089052u: goto P_0c089052;
case 0x0c089054u: goto P_0c089054;
case 0x0c089056u: goto P_0c089056;
case 0x0c089058u: goto P_0c089058;
case 0x0c08905au: goto P_0c08905a;
case 0x0c08905cu: goto P_0c08905c;
case 0x0c08905eu: goto P_0c08905e;
case 0x0c089060u: goto P_0c089060;
case 0x0c089062u: goto P_0c089062;
case 0x0c089064u: goto P_0c089064;
case 0x0c089066u: goto P_0c089066;
case 0x0c089068u: goto P_0c089068;
case 0x0c08906au: goto P_0c08906a;
case 0x0c08906cu: goto P_0c08906c;
case 0x0c08906eu: goto P_0c08906e;
case 0x0c089070u: goto P_0c089070;
case 0x0c089072u: goto P_0c089072;
case 0x0c089074u: goto P_0c089074;
case 0x0c089076u: goto P_0c089076;
case 0x0c089078u: goto P_0c089078;
case 0x0c08907au: goto P_0c08907a;
case 0x0c08907cu: goto P_0c08907c;
case 0x0c08907eu: goto P_0c08907e;
case 0x0c089080u: goto P_0c089080;
case 0x0c089082u: goto P_0c089082;
case 0x0c089084u: goto P_0c089084;
case 0x0c089086u: goto P_0c089086;
case 0x0c089088u: goto P_0c089088;
case 0x0c08908au: goto P_0c08908a;
case 0x0c08908cu: goto P_0c08908c;
case 0x0c08908eu: goto P_0c08908e;
case 0x0c089090u: goto P_0c089090;
case 0x0c089092u: goto P_0c089092;
case 0x0c089094u: goto P_0c089094;
case 0x0c089096u: goto P_0c089096;
case 0x0c089098u: goto P_0c089098;
case 0x0c08909au: goto P_0c08909a;
case 0x0c08909cu: goto P_0c08909c;
case 0x0c08909eu: goto P_0c08909e;
case 0x0c0890a0u: goto P_0c0890a0;
case 0x0c0890a2u: goto P_0c0890a2;
case 0x0c0890a4u: goto P_0c0890a4;
case 0x0c0890a6u: goto P_0c0890a6;
case 0x0c0890a8u: goto P_0c0890a8;
case 0x0c0890aau: goto P_0c0890aa;
case 0x0c0890acu: goto P_0c0890ac;
case 0x0c0890aeu: goto P_0c0890ae;
case 0x0c0890b0u: goto P_0c0890b0;
case 0x0c0890b2u: goto P_0c0890b2;
case 0x0c0890b4u: goto P_0c0890b4;
case 0x0c0890b6u: goto P_0c0890b6;
case 0x0c0890b8u: goto P_0c0890b8;
case 0x0c0890bau: goto P_0c0890ba;
case 0x0c0890bcu: goto P_0c0890bc;
case 0x0c0890beu: goto P_0c0890be;
case 0x0c0890c0u: goto P_0c0890c0;
case 0x0c0890c2u: goto P_0c0890c2;
case 0x0c0890c4u: goto P_0c0890c4;
case 0x0c0890c6u: goto P_0c0890c6;
case 0x0c0890c8u: goto P_0c0890c8;
case 0x0c0890cau: goto P_0c0890ca;
case 0x0c0890ccu: goto P_0c0890cc;
case 0x0c0890ceu: goto P_0c0890ce;
case 0x0c0890d0u: goto P_0c0890d0;
case 0x0c0890d2u: goto P_0c0890d2;
case 0x0c0890d4u: goto P_0c0890d4;
case 0x0c0890d6u: goto P_0c0890d6;
case 0x0c0890d8u: goto P_0c0890d8;
case 0x0c0890dau: goto P_0c0890da;
case 0x0c0890dcu: goto P_0c0890dc;
case 0x0c0890deu: goto P_0c0890de;
case 0x0c0890e0u: goto P_0c0890e0;
case 0x0c0890e2u: goto P_0c0890e2;
case 0x0c0890e4u: goto P_0c0890e4;
case 0x0c0890e6u: goto P_0c0890e6;
case 0x0c0890e8u: goto P_0c0890e8;
case 0x0c0890eau: goto P_0c0890ea;
case 0x0c0890ecu: goto P_0c0890ec;
case 0x0c0890eeu: goto P_0c0890ee;
case 0x0c0890f0u: goto P_0c0890f0;
case 0x0c0890f2u: goto P_0c0890f2;
case 0x0c0890f4u: goto P_0c0890f4;
case 0x0c0890f6u: goto P_0c0890f6;
case 0x0c0890f8u: goto P_0c0890f8;
case 0x0c0890fau: goto P_0c0890fa;
case 0x0c0890fcu: goto P_0c0890fc;
case 0x0c0890feu: goto P_0c0890fe;
case 0x0c089100u: goto P_0c089100;
case 0x0c089102u: goto P_0c089102;
case 0x0c089104u: goto P_0c089104;
case 0x0c089106u: goto P_0c089106;
case 0x0c089108u: goto P_0c089108;
case 0x0c08910au: goto P_0c08910a;
case 0x0c08910cu: goto P_0c08910c;
case 0x0c08910eu: goto P_0c08910e;
case 0x0c089110u: goto P_0c089110;
case 0x0c089112u: goto P_0c089112;
case 0x0c089114u: goto P_0c089114;
case 0x0c089116u: goto P_0c089116;
case 0x0c089118u: goto P_0c089118;
case 0x0c08911au: goto P_0c08911a;
case 0x0c08911cu: goto P_0c08911c;
case 0x0c08911eu: goto P_0c08911e;
case 0x0c089120u: goto P_0c089120;
case 0x0c089122u: goto P_0c089122;
case 0x0c089124u: goto P_0c089124;
case 0x0c089126u: goto P_0c089126;
case 0x0c089128u: goto P_0c089128;
case 0x0c08912au: goto P_0c08912a;
case 0x0c08912cu: goto P_0c08912c;
case 0x0c08912eu: goto P_0c08912e;
case 0x0c089130u: goto P_0c089130;
case 0x0c089132u: goto P_0c089132;
case 0x0c089134u: goto P_0c089134;
case 0x0c089136u: goto P_0c089136;
case 0x0c089138u: goto P_0c089138;
case 0x0c08913au: goto P_0c08913a;
case 0x0c08913cu: goto P_0c08913c;
case 0x0c08913eu: goto P_0c08913e;
case 0x0c089140u: goto P_0c089140;
case 0x0c089142u: goto P_0c089142;
case 0x0c089144u: goto P_0c089144;
case 0x0c089174u: goto P_0c089174;
case 0x0c089176u: goto P_0c089176;
case 0x0c089178u: goto P_0c089178;
case 0x0c08917au: goto P_0c08917a;
case 0x0c08917cu: goto P_0c08917c;
case 0x0c08917eu: goto P_0c08917e;
case 0x0c089180u: goto P_0c089180;
case 0x0c089182u: goto P_0c089182;
case 0x0c089184u: goto P_0c089184;
case 0x0c089186u: goto P_0c089186;
case 0x0c089188u: goto P_0c089188;
case 0x0c08918au: goto P_0c08918a;
case 0x0c08918cu: goto P_0c08918c;
case 0x0c08918eu: goto P_0c08918e;
case 0x0c089190u: goto P_0c089190;
case 0x0c089192u: goto P_0c089192;
case 0x0c089194u: goto P_0c089194;
case 0x0c089196u: goto P_0c089196;
case 0x0c089198u: goto P_0c089198;
case 0x0c08919au: goto P_0c08919a;
case 0x0c08919cu: goto P_0c08919c;
case 0x0c08919eu: goto P_0c08919e;
case 0x0c0891a0u: goto P_0c0891a0;
case 0x0c0891a2u: goto P_0c0891a2;
case 0x0c0891a4u: goto P_0c0891a4;
case 0x0c0891a6u: goto P_0c0891a6;
case 0x0c0891a8u: goto P_0c0891a8;
case 0x0c0891aau: goto P_0c0891aa;
case 0x0c0891acu: goto P_0c0891ac;
case 0x0c0891aeu: goto P_0c0891ae;
case 0x0c0891b0u: goto P_0c0891b0;
case 0x0c0891b2u: goto P_0c0891b2;
case 0x0c0891b4u: goto P_0c0891b4;
case 0x0c0891b6u: goto P_0c0891b6;
case 0x0c0891b8u: goto P_0c0891b8;
case 0x0c0891bau: goto P_0c0891ba;
case 0x0c0891bcu: goto P_0c0891bc;
case 0x0c0891beu: goto P_0c0891be;
case 0x0c0891c0u: goto P_0c0891c0;
case 0x0c0891c2u: goto P_0c0891c2;
case 0x0c0891c4u: goto P_0c0891c4;
case 0x0c0891c6u: goto P_0c0891c6;
case 0x0c0891c8u: goto P_0c0891c8;
case 0x0c0891cau: goto P_0c0891ca;
case 0x0c0891ccu: goto P_0c0891cc;
case 0x0c0891ceu: goto P_0c0891ce;
case 0x0c0891d0u: goto P_0c0891d0;
case 0x0c0891d2u: goto P_0c0891d2;
case 0x0c0891d4u: goto P_0c0891d4;
case 0x0c0891d6u: goto P_0c0891d6;
case 0x0c0891d8u: goto P_0c0891d8;
case 0x0c0891dau: goto P_0c0891da;
case 0x0c0891dcu: goto P_0c0891dc;
case 0x0c0891deu: goto P_0c0891de;
case 0x0c0891e0u: goto P_0c0891e0;
case 0x0c0891e2u: goto P_0c0891e2;
case 0x0c0891e4u: goto P_0c0891e4;
case 0x0c0891e6u: goto P_0c0891e6;
case 0x0c0891e8u: goto P_0c0891e8;
case 0x0c0891eau: goto P_0c0891ea;
case 0x0c0891ecu: goto P_0c0891ec;
case 0x0c0891eeu: goto P_0c0891ee;
case 0x0c0891f0u: goto P_0c0891f0;
case 0x0c0891f2u: goto P_0c0891f2;
case 0x0c0891f4u: goto P_0c0891f4;
case 0x0c0891f6u: goto P_0c0891f6;
case 0x0c0891f8u: goto P_0c0891f8;
case 0x0c0891fau: goto P_0c0891fa;
case 0x0c0891fcu: goto P_0c0891fc;
case 0x0c0891feu: goto P_0c0891fe;
case 0x0c089200u: goto P_0c089200;
case 0x0c089202u: goto P_0c089202;
case 0x0c089204u: goto P_0c089204;
case 0x0c089206u: goto P_0c089206;
case 0x0c089208u: goto P_0c089208;
case 0x0c08920au: goto P_0c08920a;
case 0x0c08920cu: goto P_0c08920c;
case 0x0c08920eu: goto P_0c08920e;
case 0x0c089210u: goto P_0c089210;
case 0x0c089212u: goto P_0c089212;
case 0x0c089214u: goto P_0c089214;
case 0x0c089216u: goto P_0c089216;
case 0x0c089218u: goto P_0c089218;
case 0x0c08921au: goto P_0c08921a;
case 0x0c08921cu: goto P_0c08921c;
case 0x0c08921eu: goto P_0c08921e;
case 0x0c089220u: goto P_0c089220;
case 0x0c089222u: goto P_0c089222;
case 0x0c089224u: goto P_0c089224;
case 0x0c089226u: goto P_0c089226;
case 0x0c089228u: goto P_0c089228;
case 0x0c08922au: goto P_0c08922a;
case 0x0c08922cu: goto P_0c08922c;
case 0x0c08922eu: goto P_0c08922e;
case 0x0c089230u: goto P_0c089230;
case 0x0c089232u: goto P_0c089232;
case 0x0c089234u: goto P_0c089234;
case 0x0c089236u: goto P_0c089236;
case 0x0c089238u: goto P_0c089238;
case 0x0c08923au: goto P_0c08923a;
case 0x0c08923cu: goto P_0c08923c;
case 0x0c08923eu: goto P_0c08923e;
case 0x0c089240u: goto P_0c089240;
case 0x0c089242u: goto P_0c089242;
case 0x0c089244u: goto P_0c089244;
case 0x0c089246u: goto P_0c089246;
case 0x0c089248u: goto P_0c089248;
case 0x0c08924au: goto P_0c08924a;
case 0x0c08924cu: goto P_0c08924c;
case 0x0c08924eu: goto P_0c08924e;
case 0x0c089250u: goto P_0c089250;
case 0x0c089252u: goto P_0c089252;
case 0x0c089254u: goto P_0c089254;
case 0x0c089256u: goto P_0c089256;
case 0x0c089258u: goto P_0c089258;
case 0x0c08925au: goto P_0c08925a;
case 0x0c08925cu: goto P_0c08925c;
case 0x0c08925eu: goto P_0c08925e;
case 0x0c089260u: goto P_0c089260;
case 0x0c089262u: goto P_0c089262;
case 0x0c089264u: goto P_0c089264;
case 0x0c089266u: goto P_0c089266;
case 0x0c089268u: goto P_0c089268;
case 0x0c08926au: goto P_0c08926a;
case 0x0c08926cu: goto P_0c08926c;
case 0x0c08926eu: goto P_0c08926e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c088fe0: /* original 2fe6, guest PC 0x0c088fe0 */
if(!s->budget--) { s->failed_pc=0x0c088fe0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088fe2;
P_0c088fe2: /* original c759, guest PC 0x0c088fe2 */
if(!s->budget--) { s->failed_pc=0x0c088fe2u; return 0; }
r[0]=code_base|0x00089148u;
goto P_0c088fe4;
P_0c088fe4: /* original 2fd6, guest PC 0x0c088fe4 */
if(!s->budget--) { s->failed_pc=0x0c088fe4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088fe6;
P_0c088fe6: /* original 6d43, guest PC 0x0c088fe6 */
if(!s->budget--) { s->failed_pc=0x0c088fe6u; return 0; }
r[13]=r[4];
goto P_0c088fe8;
P_0c088fe8: /* original 4f22, guest PC 0x0c088fe8 */
if(!s->budget--) { s->failed_pc=0x0c088fe8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088fea;
P_0c088fea: /* original 7ff8, guest PC 0x0c088fea */
if(!s->budget--) { s->failed_pc=0x0c088feau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c088fec;
P_0c088fec: /* original 2f52, guest PC 0x0c088fec */
if(!s->budget--) { s->failed_pc=0x0c088fecu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c088fee;
P_0c088fee: /* original f308, guest PC 0x0c088fee */
if(!s->budget--) { s->failed_pc=0x0c088feeu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c088ff0;
P_0c088ff0: /* original e004, guest PC 0x0c088ff0 */
if(!s->budget--) { s->failed_pc=0x0c088ff0u; return 0; }
r[0]=0x00000004u;
goto P_0c088ff2;
P_0c088ff2: /* original ff37, guest PC 0x0c088ff2 */
if(!s->budget--) { s->failed_pc=0x0c088ff2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c088ff4;
P_0c088ff4: /* original d355, guest PC 0x0c088ff4 */
if(!s->budget--) { s->failed_pc=0x0c088ff4u; return 0; }
r[3]=read(ram,0x0c08914cu,4);
goto P_0c088ff6;
P_0c088ff6: /* original 430b, guest PC 0x0c088ff6 */
if(!s->budget--) { s->failed_pc=0x0c088ff6u; return 0; }
target=r[3];
r[16]=code_base|0x0c088ffau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ffau) { target=s->pc; goto dispatch; }
goto P_0c088ffa;
P_0c088ff8: /* original 64d3, guest PC 0x0c088ff8 */
if(!s->budget--) { s->failed_pc=0x0c088ff8u; return 0; }
r[4]=r[13];
goto P_0c088ffa;
P_0c088ffa: /* original 88ff, guest PC 0x0c088ffa */
if(!s->budget--) { s->failed_pc=0x0c088ffau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c088ffc;
P_0c088ffc: /* original 8d3f, guest PC 0x0c088ffc */
if(!s->budget--) { s->failed_pc=0x0c088ffcu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c08907e; }
goto P_0c089000;
P_0c088ffe: /* original 6403, guest PC 0x0c088ffe */
if(!s->budget--) { s->failed_pc=0x0c088ffeu; return 0; }
r[4]=r[0];
goto P_0c089000;
P_0c089000: /* original 93a1, guest PC 0x0c089000 */
if(!s->budget--) { s->failed_pc=0x0c089000u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c089146u,2);
goto P_0c089002;
P_0c089002: /* original 6e43, guest PC 0x0c089002 */
if(!s->budget--) { s->failed_pc=0x0c089002u; return 0; }
r[14]=r[4];
goto P_0c089004;
P_0c089004: /* original e024, guest PC 0x0c089004 */
if(!s->budget--) { s->failed_pc=0x0c089004u; return 0; }
r[0]=0x00000024u;
goto P_0c089006;
P_0c089006: /* original 0e35, guest PC 0x0c089006 */
if(!s->budget--) { s->failed_pc=0x0c089006u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c089008;
P_0c089008: /* original e388, guest PC 0x0c089008 */
if(!s->budget--) { s->failed_pc=0x0c089008u; return 0; }
r[3]=0xffffff88u;
goto P_0c08900a;
P_0c08900a: /* original 64f2, guest PC 0x0c08900a */
if(!s->budget--) { s->failed_pc=0x0c08900au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08900c;
P_0c08900c: /* original d050, guest PC 0x0c08900c */
if(!s->budget--) { s->failed_pc=0x0c08900cu; return 0; }
r[0]=read(ram,0x0c089150u,4);
goto P_0c08900e;
P_0c08900e: /* original 74ff, guest PC 0x0c08900e */
if(!s->budget--) { s->failed_pc=0x0c08900eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c089010;
P_0c089010: /* original f38d, guest PC 0x0c089010 */
if(!s->budget--) { s->failed_pc=0x0c089010u; return 0; }
fr[3]=0;
goto P_0c089012;
P_0c089012: /* original 4408, guest PC 0x0c089012 */
if(!s->budget--) { s->failed_pc=0x0c089012u; return 0; }
r[4]<<=2;
goto P_0c089014;
P_0c089014: /* original 044e, guest PC 0x0c089014 */
if(!s->budget--) { s->failed_pc=0x0c089014u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c089016;
P_0c089016: /* original e008, guest PC 0x0c089016 */
if(!s->budget--) { s->failed_pc=0x0c089016u; return 0; }
r[0]=0x00000008u;
goto P_0c089018;
P_0c089018: /* original f548, guest PC 0x0c089018 */
if(!s->budget--) { s->failed_pc=0x0c089018u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c08901a;
P_0c08901a: /* original f446, guest PC 0x0c08901a */
if(!s->budget--) { s->failed_pc=0x0c08901au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c08901c;
P_0c08901c: /* original c74d, guest PC 0x0c08901c */
if(!s->budget--) { s->failed_pc=0x0c08901cu; return 0; }
r[0]=code_base|0x00089154u;
goto P_0c08901e;
P_0c08901e: /* original f530, guest PC 0x0c08901e */
if(!s->budget--) { s->failed_pc=0x0c08901eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c089020;
P_0c089020: /* original f208, guest PC 0x0c089020 */
if(!s->budget--) { s->failed_pc=0x0c089020u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c089022;
P_0c089022: /* original e00c, guest PC 0x0c089022 */
if(!s->budget--) { s->failed_pc=0x0c089022u; return 0; }
r[0]=0x0000000cu;
goto P_0c089024;
P_0c089024: /* original f420, guest PC 0x0c089024 */
if(!s->budget--) { s->failed_pc=0x0c089024u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c089026;
P_0c089026: /* original fe57, guest PC 0x0c089026 */
if(!s->budget--) { s->failed_pc=0x0c089026u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c089028;
P_0c089028: /* original e004, guest PC 0x0c089028 */
if(!s->budget--) { s->failed_pc=0x0c089028u; return 0; }
r[0]=0x00000004u;
goto P_0c08902a;
P_0c08902a: /* original f1f6, guest PC 0x0c08902a */
if(!s->budget--) { s->failed_pc=0x0c08902au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c08902c;
P_0c08902c: /* original e010, guest PC 0x0c08902c */
if(!s->budget--) { s->failed_pc=0x0c08902cu; return 0; }
r[0]=0x00000010u;
goto P_0c08902e;
P_0c08902e: /* original fe17, guest PC 0x0c08902e */
if(!s->budget--) { s->failed_pc=0x0c08902eu; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c089030;
P_0c089030: /* original e014, guest PC 0x0c089030 */
if(!s->budget--) { s->failed_pc=0x0c089030u; return 0; }
r[0]=0x00000014u;
goto P_0c089032;
P_0c089032: /* original fe47, guest PC 0x0c089032 */
if(!s->budget--) { s->failed_pc=0x0c089032u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c089034;
P_0c089034: /* original e026, guest PC 0x0c089034 */
if(!s->budget--) { s->failed_pc=0x0c089034u; return 0; }
r[0]=0x00000026u;
goto P_0c089036;
P_0c089036: /* original d248, guest PC 0x0c089036 */
if(!s->budget--) { s->failed_pc=0x0c089036u; return 0; }
r[2]=read(ram,0x0c089158u,4);
goto P_0c089038;
P_0c089038: /* original 420b, guest PC 0x0c089038 */
if(!s->budget--) { s->failed_pc=0x0c089038u; return 0; }
target=r[2];
r[16]=code_base|0x0c08903cu;
write(ram,r[14]+r[0],r[3],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08903cu) { target=s->pc; goto dispatch; }
goto P_0c08903c;
P_0c08903a: /* original 0e34, guest PC 0x0c08903a */
if(!s->budget--) { s->failed_pc=0x0c08903au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08903c;
P_0c08903c: /* original e307, guest PC 0x0c08903c */
if(!s->budget--) { s->failed_pc=0x0c08903cu; return 0; }
r[3]=0x00000007u;
goto P_0c08903e;
P_0c08903e: /* original 6403, guest PC 0x0c08903e */
if(!s->budget--) { s->failed_pc=0x0c08903eu; return 0; }
r[4]=r[0];
goto P_0c089040;
P_0c089040: /* original 2439, guest PC 0x0c089040 */
if(!s->budget--) { s->failed_pc=0x0c089040u; return 0; }
r[4]&=r[3];
goto P_0c089042;
P_0c089042: /* original 445a, guest PC 0x0c089042 */
if(!s->budget--) { s->failed_pc=0x0c089042u; return 0; }
r[53]=r[4];
goto P_0c089044;
P_0c089044: /* original c745, guest PC 0x0c089044 */
if(!s->budget--) { s->failed_pc=0x0c089044u; return 0; }
r[0]=code_base|0x0008915cu;
goto P_0c089046;
P_0c089046: /* original e201, guest PC 0x0c089046 */
if(!s->budget--) { s->failed_pc=0x0c089046u; return 0; }
r[2]=0x00000001u;
goto P_0c089048;
P_0c089048: /* original 2428, guest PC 0x0c089048 */
if(!s->budget--) { s->failed_pc=0x0c089048u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08904a;
P_0c08904a: /* original f32d, guest PC 0x0c08904a */
if(!s->budget--) { s->failed_pc=0x0c08904au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08904c;
P_0c08904c: /* original f43c, guest PC 0x0c08904c */
if(!s->budget--) { s->failed_pc=0x0c08904cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08904e;
P_0c08904e: /* original f308, guest PC 0x0c08904e */
if(!s->budget--) { s->failed_pc=0x0c08904eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089050;
P_0c089050: /* original 8d01, guest PC 0x0c089050 */
if(!s->budget--) { s->failed_pc=0x0c089050u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
if(cond) { goto P_0c089056; }
goto P_0c089054;
P_0c089052: /* original f432, guest PC 0x0c089052 */
if(!s->budget--) { s->failed_pc=0x0c089052u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c089054;
P_0c089054: /* original f44d, guest PC 0x0c089054 */
if(!s->budget--) { s->failed_pc=0x0c089054u; return 0; }
fr[4]^=0x80000000u;
goto P_0c089056;
P_0c089056: /* original e01c, guest PC 0x0c089056 */
if(!s->budget--) { s->failed_pc=0x0c089056u; return 0; }
r[0]=0x0000001cu;
goto P_0c089058;
P_0c089058: /* original 64e3, guest PC 0x0c089058 */
if(!s->budget--) { s->failed_pc=0x0c089058u; return 0; }
r[4]=r[14];
goto P_0c08905a;
P_0c08905a: /* original f5d6, guest PC 0x0c08905a */
if(!s->budget--) { s->failed_pc=0x0c08905au; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c08905c;
P_0c08905c: /* original e018, guest PC 0x0c08905c */
if(!s->budget--) { s->failed_pc=0x0c08905cu; return 0; }
r[0]=0x00000018u;
goto P_0c08905e;
P_0c08905e: /* original 7f08, guest PC 0x0c08905e */
if(!s->budget--) { s->failed_pc=0x0c08905eu; return 0; }
r[15]+=0x00000008u;
goto P_0c089060;
P_0c089060: /* original f540, guest PC 0x0c089060 */
if(!s->budget--) { s->failed_pc=0x0c089060u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c089062;
P_0c089062: /* original 4f26, guest PC 0x0c089062 */
if(!s->budget--) { s->failed_pc=0x0c089062u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089064;
P_0c089064: /* original fe57, guest PC 0x0c089064 */
if(!s->budget--) { s->failed_pc=0x0c089064u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c089066;
P_0c089066: /* original e01c, guest PC 0x0c089066 */
if(!s->budget--) { s->failed_pc=0x0c089066u; return 0; }
r[0]=0x0000001cu;
goto P_0c089068;
P_0c089068: /* original f38d, guest PC 0x0c089068 */
if(!s->budget--) { s->failed_pc=0x0c089068u; return 0; }
fr[3]=0;
goto P_0c08906a;
P_0c08906a: /* original fe37, guest PC 0x0c08906a */
if(!s->budget--) { s->failed_pc=0x0c08906au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08906c;
P_0c08906c: /* original c73c, guest PC 0x0c08906c */
if(!s->budget--) { s->failed_pc=0x0c08906cu; return 0; }
r[0]=code_base|0x00089160u;
goto P_0c08906e;
P_0c08906e: /* original f308, guest PC 0x0c08906e */
if(!s->budget--) { s->failed_pc=0x0c08906eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c089070;
P_0c089070: /* original e020, guest PC 0x0c089070 */
if(!s->budget--) { s->failed_pc=0x0c089070u; return 0; }
r[0]=0x00000020u;
goto P_0c089072;
P_0c089072: /* original fe37, guest PC 0x0c089072 */
if(!s->budget--) { s->failed_pc=0x0c089072u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089074;
P_0c089074: /* original 55da, guest PC 0x0c089074 */
if(!s->budget--) { s->failed_pc=0x0c089074u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c089076;
P_0c089076: /* original d33b, guest PC 0x0c089076 */
if(!s->budget--) { s->failed_pc=0x0c089076u; return 0; }
r[3]=read(ram,0x0c089164u,4);
goto P_0c089078;
P_0c089078: /* original 6df6, guest PC 0x0c089078 */
if(!s->budget--) { s->failed_pc=0x0c089078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08907a;
P_0c08907a: /* original 432b, guest PC 0x0c08907a */
if(!s->budget--) { s->failed_pc=0x0c08907au; return 0; }
target=r[3];
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
P_0c08907c: /* original 6ef6, guest PC 0x0c08907c */
if(!s->budget--) { s->failed_pc=0x0c08907cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08907e;
P_0c08907e: /* original 7f08, guest PC 0x0c08907e */
if(!s->budget--) { s->failed_pc=0x0c08907eu; return 0; }
r[15]+=0x00000008u;
goto P_0c089080;
P_0c089080: /* original 4f26, guest PC 0x0c089080 */
if(!s->budget--) { s->failed_pc=0x0c089080u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089082;
P_0c089082: /* original 6df6, guest PC 0x0c089082 */
if(!s->budget--) { s->failed_pc=0x0c089082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089084;
P_0c089084: /* original 000b, guest PC 0x0c089084 */
if(!s->budget--) { s->failed_pc=0x0c089084u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089086: /* original 6ef6, guest PC 0x0c089086 */
if(!s->budget--) { s->failed_pc=0x0c089086u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c089088;
P_0c089088: /* original 2fe6, guest PC 0x0c089088 */
if(!s->budget--) { s->failed_pc=0x0c089088u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08908a;
P_0c08908a: /* original 2fd6, guest PC 0x0c08908a */
if(!s->budget--) { s->failed_pc=0x0c08908au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08908c;
P_0c08908c: /* original 6d43, guest PC 0x0c08908c */
if(!s->budget--) { s->failed_pc=0x0c08908cu; return 0; }
r[13]=r[4];
goto P_0c08908e;
P_0c08908e: /* original fffb, guest PC 0x0c08908e */
if(!s->budget--) { s->failed_pc=0x0c08908eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089090;
P_0c089090: /* original ffeb, guest PC 0x0c089090 */
if(!s->budget--) { s->failed_pc=0x0c089090u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c089092;
P_0c089092: /* original ffdb, guest PC 0x0c089092 */
if(!s->budget--) { s->failed_pc=0x0c089092u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c089094;
P_0c089094: /* original ffcb, guest PC 0x0c089094 */
if(!s->budget--) { s->failed_pc=0x0c089094u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c089096;
P_0c089096: /* original 4f22, guest PC 0x0c089096 */
if(!s->budget--) { s->failed_pc=0x0c089096u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c089098;
P_0c089098: /* original 7ff4, guest PC 0x0c089098 */
if(!s->budget--) { s->failed_pc=0x0c089098u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08909a;
P_0c08909a: /* original 1f51, guest PC 0x0c08909a */
if(!s->budget--) { s->failed_pc=0x0c08909au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c08909c;
P_0c08909c: /* original d32b, guest PC 0x0c08909c */
if(!s->budget--) { s->failed_pc=0x0c08909cu; return 0; }
r[3]=read(ram,0x0c08914cu,4);
goto P_0c08909e;
P_0c08909e: /* original 430b, guest PC 0x0c08909e */
if(!s->budget--) { s->failed_pc=0x0c08909eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0890a2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0890a2u) { target=s->pc; goto dispatch; }
goto P_0c0890a2;
P_0c0890a0: /* original 64d3, guest PC 0x0c0890a0 */
if(!s->budget--) { s->failed_pc=0x0c0890a0u; return 0; }
r[4]=r[13];
goto P_0c0890a2;
P_0c0890a2: /* original 88ff, guest PC 0x0c0890a2 */
if(!s->budget--) { s->failed_pc=0x0c0890a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0890a4;
P_0c0890a4: /* original 8d66, guest PC 0x0c0890a4 */
if(!s->budget--) { s->failed_pc=0x0c0890a4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c089174; }
goto P_0c0890a8;
P_0c0890a6: /* original 6403, guest PC 0x0c0890a6 */
if(!s->budget--) { s->failed_pc=0x0c0890a6u; return 0; }
r[4]=r[0];
goto P_0c0890a8;
P_0c0890a8: /* original c72f, guest PC 0x0c0890a8 */
if(!s->budget--) { s->failed_pc=0x0c0890a8u; return 0; }
r[0]=code_base|0x00089168u;
goto P_0c0890aa;
P_0c0890aa: /* original d330, guest PC 0x0c0890aa */
if(!s->budget--) { s->failed_pc=0x0c0890aau; return 0; }
r[3]=read(ram,0x0c08916cu,4);
goto P_0c0890ac;
P_0c0890ac: /* original fd08, guest PC 0x0c0890ac */
if(!s->budget--) { s->failed_pc=0x0c0890acu; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0890ae;
P_0c0890ae: /* original 6e43, guest PC 0x0c0890ae */
if(!s->budget--) { s->failed_pc=0x0c0890aeu; return 0; }
r[14]=r[4];
goto P_0c0890b0;
P_0c0890b0: /* original e02e, guest PC 0x0c0890b0 */
if(!s->budget--) { s->failed_pc=0x0c0890b0u; return 0; }
r[0]=0x0000002eu;
goto P_0c0890b2;
P_0c0890b2: /* original 430b, guest PC 0x0c0890b2 */
if(!s->budget--) { s->failed_pc=0x0c0890b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0890b6u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0890b6u) { target=s->pc; goto dispatch; }
goto P_0c0890b6;
P_0c0890b4: /* original 04dd, guest PC 0x0c0890b4 */
if(!s->budget--) { s->failed_pc=0x0c0890b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0890b6;
P_0c0890b6: /* original e02d, guest PC 0x0c0890b6 */
if(!s->budget--) { s->failed_pc=0x0c0890b6u; return 0; }
r[0]=0x0000002du;
goto P_0c0890b8;
P_0c0890b8: /* original f40c, guest PC 0x0c0890b8 */
if(!s->budget--) { s->failed_pc=0x0c0890b8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0890ba;
P_0c0890ba: /* original 02dc, guest PC 0x0c0890ba */
if(!s->budget--) { s->failed_pc=0x0c0890bau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0890bc;
P_0c0890bc: /* original e024, guest PC 0x0c0890bc */
if(!s->budget--) { s->failed_pc=0x0c0890bcu; return 0; }
r[0]=0x00000024u;
goto P_0c0890be;
P_0c0890be: /* original fd42, guest PC 0x0c0890be */
if(!s->budget--) { s->failed_pc=0x0c0890beu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c0890c0;
P_0c0890c0: /* original 0e25, guest PC 0x0c0890c0 */
if(!s->budget--) { s->failed_pc=0x0c0890c0u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0890c2;
P_0c0890c2: /* original 54f1, guest PC 0x0c0890c2 */
if(!s->budget--) { s->failed_pc=0x0c0890c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0890c4;
P_0c0890c4: /* original d022, guest PC 0x0c0890c4 */
if(!s->budget--) { s->failed_pc=0x0c0890c4u; return 0; }
r[0]=read(ram,0x0c089150u,4);
goto P_0c0890c6;
P_0c0890c6: /* original 74ff, guest PC 0x0c0890c6 */
if(!s->budget--) { s->failed_pc=0x0c0890c6u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0890c8;
P_0c0890c8: /* original 4408, guest PC 0x0c0890c8 */
if(!s->budget--) { s->failed_pc=0x0c0890c8u; return 0; }
r[4]<<=2;
goto P_0c0890ca;
P_0c0890ca: /* original 044e, guest PC 0x0c0890ca */
if(!s->budget--) { s->failed_pc=0x0c0890cau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0890cc;
P_0c0890cc: /* original e004, guest PC 0x0c0890cc */
if(!s->budget--) { s->failed_pc=0x0c0890ccu; return 0; }
r[0]=0x00000004u;
goto P_0c0890ce;
P_0c0890ce: /* original f346, guest PC 0x0c0890ce */
if(!s->budget--) { s->failed_pc=0x0c0890ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0890d0;
P_0c0890d0: /* original e008, guest PC 0x0c0890d0 */
if(!s->budget--) { s->failed_pc=0x0c0890d0u; return 0; }
r[0]=0x00000008u;
goto P_0c0890d2;
P_0c0890d2: /* original ff48, guest PC 0x0c0890d2 */
if(!s->budget--) { s->failed_pc=0x0c0890d2u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c0890d4;
P_0c0890d4: /* original ff37, guest PC 0x0c0890d4 */
if(!s->budget--) { s->failed_pc=0x0c0890d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0890d6;
P_0c0890d6: /* original e008, guest PC 0x0c0890d6 */
if(!s->budget--) { s->failed_pc=0x0c0890d6u; return 0; }
r[0]=0x00000008u;
goto P_0c0890d8;
P_0c0890d8: /* original fc46, guest PC 0x0c0890d8 */
if(!s->budget--) { s->failed_pc=0x0c0890d8u; return 0; }
vf3_matrix_load(s,ram,12,r[4]+r[0]);
goto P_0c0890da;
P_0c0890da: /* original e00c, guest PC 0x0c0890da */
if(!s->budget--) { s->failed_pc=0x0c0890dau; return 0; }
r[0]=0x0000000cu;
goto P_0c0890dc;
P_0c0890dc: /* original f346, guest PC 0x0c0890dc */
if(!s->budget--) { s->failed_pc=0x0c0890dcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0890de;
P_0c0890de: /* original e010, guest PC 0x0c0890de */
if(!s->budget--) { s->failed_pc=0x0c0890deu; return 0; }
r[0]=0x00000010u;
goto P_0c0890e0;
P_0c0890e0: /* original ff3a, guest PC 0x0c0890e0 */
if(!s->budget--) { s->failed_pc=0x0c0890e0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0890e2;
P_0c0890e2: /* original d31d, guest PC 0x0c0890e2 */
if(!s->budget--) { s->failed_pc=0x0c0890e2u; return 0; }
r[3]=read(ram,0x0c089158u,4);
goto P_0c0890e4;
P_0c0890e4: /* original 430b, guest PC 0x0c0890e4 */
if(!s->budget--) { s->failed_pc=0x0c0890e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0890e8u;
vf3_matrix_load(s,ram,14,r[4]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0890e8u) { target=s->pc; goto dispatch; }
goto P_0c0890e8;
P_0c0890e6: /* original fe46, guest PC 0x0c0890e6 */
if(!s->budget--) { s->failed_pc=0x0c0890e6u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0890e8;
P_0c0890e8: /* original e207, guest PC 0x0c0890e8 */
if(!s->budget--) { s->failed_pc=0x0c0890e8u; return 0; }
r[2]=0x00000007u;
goto P_0c0890ea;
P_0c0890ea: /* original 6403, guest PC 0x0c0890ea */
if(!s->budget--) { s->failed_pc=0x0c0890eau; return 0; }
r[4]=r[0];
goto P_0c0890ec;
P_0c0890ec: /* original 2429, guest PC 0x0c0890ec */
if(!s->budget--) { s->failed_pc=0x0c0890ecu; return 0; }
r[4]&=r[2];
goto P_0c0890ee;
P_0c0890ee: /* original fed0, guest PC 0x0c0890ee */
if(!s->budget--) { s->failed_pc=0x0c0890eeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[13],r[18],'+');
goto P_0c0890f0;
P_0c0890f0: /* original 445a, guest PC 0x0c0890f0 */
if(!s->budget--) { s->failed_pc=0x0c0890f0u; return 0; }
r[53]=r[4];
goto P_0c0890f2;
P_0c0890f2: /* original c71f, guest PC 0x0c0890f2 */
if(!s->budget--) { s->failed_pc=0x0c0890f2u; return 0; }
r[0]=code_base|0x00089170u;
goto P_0c0890f4;
P_0c0890f4: /* original f408, guest PC 0x0c0890f4 */
if(!s->budget--) { s->failed_pc=0x0c0890f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0890f6;
P_0c0890f6: /* original e00c, guest PC 0x0c0890f6 */
if(!s->budget--) { s->failed_pc=0x0c0890f6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0890f8;
P_0c0890f8: /* original f32d, guest PC 0x0c0890f8 */
if(!s->budget--) { s->failed_pc=0x0c0890f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0890fa;
P_0c0890fa: /* original f04c, guest PC 0x0c0890fa */
if(!s->budget--) { s->failed_pc=0x0c0890fau; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0890fc;
P_0c0890fc: /* original fce0, guest PC 0x0c0890fc */
if(!s->budget--) { s->failed_pc=0x0c0890fcu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[14],r[18],'+');
goto P_0c0890fe;
P_0c0890fe: /* original f53c, guest PC 0x0c0890fe */
if(!s->budget--) { s->failed_pc=0x0c0890feu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c089100;
P_0c089100: /* original f3fc, guest PC 0x0c089100 */
if(!s->budget--) { s->failed_pc=0x0c089100u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c089102;
P_0c089102: /* original f35e, guest PC 0x0c089102 */
if(!s->budget--) { s->failed_pc=0x0c089102u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c089104;
P_0c089104: /* original ff3c, guest PC 0x0c089104 */
if(!s->budget--) { s->failed_pc=0x0c089104u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c089106;
P_0c089106: /* original fef7, guest PC 0x0c089106 */
if(!s->budget--) { s->failed_pc=0x0c089106u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089108;
P_0c089108: /* original e008, guest PC 0x0c089108 */
if(!s->budget--) { s->failed_pc=0x0c089108u; return 0; }
r[0]=0x00000008u;
goto P_0c08910a;
P_0c08910a: /* original f3f6, guest PC 0x0c08910a */
if(!s->budget--) { s->failed_pc=0x0c08910au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08910c;
P_0c08910c: /* original e010, guest PC 0x0c08910c */
if(!s->budget--) { s->failed_pc=0x0c08910cu; return 0; }
r[0]=0x00000010u;
goto P_0c08910e;
P_0c08910e: /* original fe37, guest PC 0x0c08910e */
if(!s->budget--) { s->failed_pc=0x0c08910eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089110;
P_0c089110: /* original e014, guest PC 0x0c089110 */
if(!s->budget--) { s->failed_pc=0x0c089110u; return 0; }
r[0]=0x00000014u;
goto P_0c089112;
P_0c089112: /* original fec7, guest PC 0x0c089112 */
if(!s->budget--) { s->failed_pc=0x0c089112u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c089114;
P_0c089114: /* original e018, guest PC 0x0c089114 */
if(!s->budget--) { s->failed_pc=0x0c089114u; return 0; }
r[0]=0x00000018u;
goto P_0c089116;
P_0c089116: /* original f3f8, guest PC 0x0c089116 */
if(!s->budget--) { s->failed_pc=0x0c089116u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c089118;
P_0c089118: /* original f342, guest PC 0x0c089118 */
if(!s->budget--) { s->failed_pc=0x0c089118u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08911a;
P_0c08911a: /* original ff3a, guest PC 0x0c08911a */
if(!s->budget--) { s->failed_pc=0x0c08911au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08911c;
P_0c08911c: /* original fe37, guest PC 0x0c08911c */
if(!s->budget--) { s->failed_pc=0x0c08911cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08911e;
P_0c08911e: /* original e01c, guest PC 0x0c08911e */
if(!s->budget--) { s->failed_pc=0x0c08911eu; return 0; }
r[0]=0x0000001cu;
goto P_0c089120;
P_0c089120: /* original f38d, guest PC 0x0c089120 */
if(!s->budget--) { s->failed_pc=0x0c089120u; return 0; }
fr[3]=0;
goto P_0c089122;
P_0c089122: /* original fe37, guest PC 0x0c089122 */
if(!s->budget--) { s->failed_pc=0x0c089122u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089124;
P_0c089124: /* original e020, guest PC 0x0c089124 */
if(!s->budget--) { s->failed_pc=0x0c089124u; return 0; }
r[0]=0x00000020u;
goto P_0c089126;
P_0c089126: /* original fee7, guest PC 0x0c089126 */
if(!s->budget--) { s->failed_pc=0x0c089126u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c089128;
P_0c089128: /* original 7f0c, guest PC 0x0c089128 */
if(!s->budget--) { s->failed_pc=0x0c089128u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08912a;
P_0c08912a: /* original 64e3, guest PC 0x0c08912a */
if(!s->budget--) { s->failed_pc=0x0c08912au; return 0; }
r[4]=r[14];
goto P_0c08912c;
P_0c08912c: /* original 4f26, guest PC 0x0c08912c */
if(!s->budget--) { s->failed_pc=0x0c08912cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08912e;
P_0c08912e: /* original e300, guest PC 0x0c08912e */
if(!s->budget--) { s->failed_pc=0x0c08912eu; return 0; }
r[3]=0x00000000u;
goto P_0c089130;
P_0c089130: /* original e026, guest PC 0x0c089130 */
if(!s->budget--) { s->failed_pc=0x0c089130u; return 0; }
r[0]=0x00000026u;
goto P_0c089132;
P_0c089132: /* original 0e34, guest PC 0x0c089132 */
if(!s->budget--) { s->failed_pc=0x0c089132u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c089134;
P_0c089134: /* original fcf9, guest PC 0x0c089134 */
if(!s->budget--) { s->failed_pc=0x0c089134u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089136;
P_0c089136: /* original 55d9, guest PC 0x0c089136 */
if(!s->budget--) { s->failed_pc=0x0c089136u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c089138;
P_0c089138: /* original fdf9, guest PC 0x0c089138 */
if(!s->budget--) { s->failed_pc=0x0c089138u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08913a;
P_0c08913a: /* original d30a, guest PC 0x0c08913a */
if(!s->budget--) { s->failed_pc=0x0c08913au; return 0; }
r[3]=read(ram,0x0c089164u,4);
goto P_0c08913c;
P_0c08913c: /* original fef9, guest PC 0x0c08913c */
if(!s->budget--) { s->failed_pc=0x0c08913cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08913e;
P_0c08913e: /* original fff9, guest PC 0x0c08913e */
if(!s->budget--) { s->failed_pc=0x0c08913eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089140;
P_0c089140: /* original 6df6, guest PC 0x0c089140 */
if(!s->budget--) { s->failed_pc=0x0c089140u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089142;
P_0c089142: /* original 432b, guest PC 0x0c089142 */
if(!s->budget--) { s->failed_pc=0x0c089142u; return 0; }
target=r[3];
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
P_0c089144: /* original 6ef6, guest PC 0x0c089144 */
if(!s->budget--) { s->failed_pc=0x0c089144u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c089146u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c089146u; return 0; } return 1;
P_0c089174: /* original 7f0c, guest PC 0x0c089174 */
if(!s->budget--) { s->failed_pc=0x0c089174u; return 0; }
r[15]+=0x0000000cu;
goto P_0c089176;
P_0c089176: /* original 4f26, guest PC 0x0c089176 */
if(!s->budget--) { s->failed_pc=0x0c089176u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c089178;
P_0c089178: /* original fcf9, guest PC 0x0c089178 */
if(!s->budget--) { s->failed_pc=0x0c089178u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917a;
P_0c08917a: /* original fdf9, guest PC 0x0c08917a */
if(!s->budget--) { s->failed_pc=0x0c08917au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917c;
P_0c08917c: /* original fef9, guest PC 0x0c08917c */
if(!s->budget--) { s->failed_pc=0x0c08917cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08917e;
P_0c08917e: /* original fff9, guest PC 0x0c08917e */
if(!s->budget--) { s->failed_pc=0x0c08917eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089180;
P_0c089180: /* original 6df6, guest PC 0x0c089180 */
if(!s->budget--) { s->failed_pc=0x0c089180u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089182;
P_0c089182: /* original 000b, guest PC 0x0c089182 */
if(!s->budget--) { s->failed_pc=0x0c089182u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c089184: /* original 6ef6, guest PC 0x0c089184 */
if(!s->budget--) { s->failed_pc=0x0c089184u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c089186;
P_0c089186: /* original 2fe6, guest PC 0x0c089186 */
if(!s->budget--) { s->failed_pc=0x0c089186u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089188;
P_0c089188: /* original 2fd6, guest PC 0x0c089188 */
if(!s->budget--) { s->failed_pc=0x0c089188u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08918a;
P_0c08918a: /* original 2fc6, guest PC 0x0c08918a */
if(!s->budget--) { s->failed_pc=0x0c08918au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08918c;
P_0c08918c: /* original 2fb6, guest PC 0x0c08918c */
if(!s->budget--) { s->failed_pc=0x0c08918cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08918e;
P_0c08918e: /* original 2fa6, guest PC 0x0c08918e */
if(!s->budget--) { s->failed_pc=0x0c08918eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089190;
P_0c089190: /* original 2f96, guest PC 0x0c089190 */
if(!s->budget--) { s->failed_pc=0x0c089190u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089192;
P_0c089192: /* original 6943, guest PC 0x0c089192 */
if(!s->budget--) { s->failed_pc=0x0c089192u; return 0; }
r[9]=r[4];
goto P_0c089194;
P_0c089194: /* original 2f86, guest PC 0x0c089194 */
if(!s->budget--) { s->failed_pc=0x0c089194u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089196;
P_0c089196: /* original fffb, guest PC 0x0c089196 */
if(!s->budget--) { s->failed_pc=0x0c089196u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c089198;
P_0c089198: /* original d141, guest PC 0x0c089198 */
if(!s->budget--) { s->failed_pc=0x0c089198u; return 0; }
r[1]=read(ram,0x0c0892a0u,4);
goto P_0c08919a;
P_0c08919a: /* original d340, guest PC 0x0c08919a */
if(!s->budget--) { s->failed_pc=0x0c08919au; return 0; }
r[3]=read(ram,0x0c08929cu,4);
goto P_0c08919c;
P_0c08919c: /* original 6212, guest PC 0x0c08919c */
if(!s->budget--) { s->failed_pc=0x0c08919cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08919e;
P_0c08919e: /* original 4f22, guest PC 0x0c08919e */
if(!s->budget--) { s->failed_pc=0x0c08919eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0891a0;
P_0c0891a0: /* original 2238, guest PC 0x0c0891a0 */
if(!s->budget--) { s->failed_pc=0x0c0891a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0891a2;
P_0c0891a2: /* original 8f5b, guest PC 0x0c0891a2 */
if(!s->budget--) { s->failed_pc=0x0c0891a2u; return 0; }
cond=r[17]&1u;
r[8]=r[4];
if(!cond) { goto P_0c08925c; }
goto P_0c0891a6;
P_0c0891a4: /* original 6843, guest PC 0x0c0891a4 */
if(!s->budget--) { s->failed_pc=0x0c0891a4u; return 0; }
r[8]=r[4];
goto P_0c0891a6;
P_0c0891a6: /* original c73f, guest PC 0x0c0891a6 */
if(!s->budget--) { s->failed_pc=0x0c0891a6u; return 0; }
r[0]=code_base|0x000892a4u;
goto P_0c0891a8;
P_0c0891a8: /* original 6e93, guest PC 0x0c0891a8 */
if(!s->budget--) { s->failed_pc=0x0c0891a8u; return 0; }
r[14]=r[9];
goto P_0c0891aa;
P_0c0891aa: /* original e300, guest PC 0x0c0891aa */
if(!s->budget--) { s->failed_pc=0x0c0891aau; return 0; }
r[3]=0x00000000u;
goto P_0c0891ac;
P_0c0891ac: /* original 7e18, guest PC 0x0c0891ac */
if(!s->budget--) { s->failed_pc=0x0c0891acu; return 0; }
r[14]+=0x00000018u;
goto P_0c0891ae;
P_0c0891ae: /* original 1835, guest PC 0x0c0891ae */
if(!s->budget--) { s->failed_pc=0x0c0891aeu; return 0; }
write(ram,r[8]+20,r[3],4);
goto P_0c0891b0;
P_0c0891b0: /* original da3d, guest PC 0x0c0891b0 */
if(!s->budget--) { s->failed_pc=0x0c0891b0u; return 0; }
r[10]=read(ram,0x0c0892a8u,4);
goto P_0c0891b2;
P_0c0891b2: /* original ff08, guest PC 0x0c0891b2 */
if(!s->budget--) { s->failed_pc=0x0c0891b2u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0891b4;
P_0c0891b4: /* original dc3d, guest PC 0x0c0891b4 */
if(!s->budget--) { s->failed_pc=0x0c0891b4u; return 0; }
r[12]=read(ram,0x0c0892acu,4);
goto P_0c0891b6;
P_0c0891b6: /* original a048, guest PC 0x0c0891b6 */
if(!s->budget--) { s->failed_pc=0x0c0891b6u; return 0; }
r[11]=0x00000005u;
goto P_0c08924a;
P_0c0891b8: /* original eb05, guest PC 0x0c0891b8 */
if(!s->budget--) { s->failed_pc=0x0c0891b8u; return 0; }
r[11]=0x00000005u;
goto P_0c0891ba;
P_0c0891ba: /* original 6db3, guest PC 0x0c0891ba */
if(!s->budget--) { s->failed_pc=0x0c0891bau; return 0; }
r[13]=r[11];
goto P_0c0891bc;
P_0c0891bc: /* original 7dff, guest PC 0x0c0891bc */
if(!s->budget--) { s->failed_pc=0x0c0891bcu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0891be;
P_0c0891be: /* original 64d3, guest PC 0x0c0891be */
if(!s->budget--) { s->failed_pc=0x0c0891beu; return 0; }
r[4]=r[13];
goto P_0c0891c0;
P_0c0891c0: /* original 4400, guest PC 0x0c0891c0 */
if(!s->budget--) { s->failed_pc=0x0c0891c0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0891c2;
P_0c0891c2: /* original 62d3, guest PC 0x0c0891c2 */
if(!s->budget--) { s->failed_pc=0x0c0891c2u; return 0; }
r[2]=r[13];
goto P_0c0891c4;
P_0c0891c4: /* original 6043, guest PC 0x0c0891c4 */
if(!s->budget--) { s->failed_pc=0x0c0891c4u; return 0; }
r[0]=r[4];
goto P_0c0891c6;
P_0c0891c6: /* original 4208, guest PC 0x0c0891c6 */
if(!s->budget--) { s->failed_pc=0x0c0891c6u; return 0; }
r[2]<<=2;
goto P_0c0891c8;
P_0c0891c8: /* original 6383, guest PC 0x0c0891c8 */
if(!s->budget--) { s->failed_pc=0x0c0891c8u; return 0; }
r[3]=r[8];
goto P_0c0891ca;
P_0c0891ca: /* original 4008, guest PC 0x0c0891ca */
if(!s->budget--) { s->failed_pc=0x0c0891cau; return 0; }
r[0]<<=2;
goto P_0c0891cc;
P_0c0891cc: /* original 323c, guest PC 0x0c0891cc */
if(!s->budget--) { s->failed_pc=0x0c0891ccu; return 0; }
r[2]+=r[3];
goto P_0c0891ce;
P_0c0891ce: /* original e12c, guest PC 0x0c0891ce */
if(!s->budget--) { s->failed_pc=0x0c0891ceu; return 0; }
r[1]=0x0000002cu;
goto P_0c0891d0;
P_0c0891d0: /* original 22e2, guest PC 0x0c0891d0 */
if(!s->budget--) { s->failed_pc=0x0c0891d0u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c0891d2;
P_0c0891d2: /* original 03ae, guest PC 0x0c0891d2 */
if(!s->budget--) { s->failed_pc=0x0c0891d2u; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0891d4;
P_0c0891d4: /* original 6043, guest PC 0x0c0891d4 */
if(!s->budget--) { s->failed_pc=0x0c0891d4u; return 0; }
r[0]=r[4];
goto P_0c0891d6;
P_0c0891d6: /* original 7001, guest PC 0x0c0891d6 */
if(!s->budget--) { s->failed_pc=0x0c0891d6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0891d8;
P_0c0891d8: /* original 64d3, guest PC 0x0c0891d8 */
if(!s->budget--) { s->failed_pc=0x0c0891d8u; return 0; }
r[4]=r[13];
goto P_0c0891da;
P_0c0891da: /* original 4008, guest PC 0x0c0891da */
if(!s->budget--) { s->failed_pc=0x0c0891dau; return 0; }
r[0]<<=2;
goto P_0c0891dc;
P_0c0891dc: /* original 1e39, guest PC 0x0c0891dc */
if(!s->budget--) { s->failed_pc=0x0c0891dcu; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c0891de;
P_0c0891de: /* original 03ae, guest PC 0x0c0891de */
if(!s->budget--) { s->failed_pc=0x0c0891deu; return 0; }
r[3]=read(ram,r[10]+r[0],4);
goto P_0c0891e0;
P_0c0891e0: /* original 4408, guest PC 0x0c0891e0 */
if(!s->budget--) { s->failed_pc=0x0c0891e0u; return 0; }
r[4]<<=2;
goto P_0c0891e2;
P_0c0891e2: /* original 4400, guest PC 0x0c0891e2 */
if(!s->budget--) { s->failed_pc=0x0c0891e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0891e4;
P_0c0891e4: /* original 1e3a, guest PC 0x0c0891e4 */
if(!s->budget--) { s->failed_pc=0x0c0891e4u; return 0; }
write(ram,r[14]+40,r[3],4);
goto P_0c0891e6;
P_0c0891e6: /* original 31ec, guest PC 0x0c0891e6 */
if(!s->budget--) { s->failed_pc=0x0c0891e6u; return 0; }
r[1]+=r[14];
goto P_0c0891e8;
P_0c0891e8: /* original d331, guest PC 0x0c0891e8 */
if(!s->budget--) { s->failed_pc=0x0c0891e8u; return 0; }
r[3]=read(ram,0x0c0892b0u,4);
goto P_0c0891ea;
P_0c0891ea: /* original e22d, guest PC 0x0c0891ea */
if(!s->budget--) { s->failed_pc=0x0c0891eau; return 0; }
r[2]=0x0000002du;
goto P_0c0891ec;
P_0c0891ec: /* original 32ec, guest PC 0x0c0891ec */
if(!s->budget--) { s->failed_pc=0x0c0891ecu; return 0; }
r[2]+=r[14];
goto P_0c0891ee;
P_0c0891ee: /* original 343c, guest PC 0x0c0891ee */
if(!s->budget--) { s->failed_pc=0x0c0891eeu; return 0; }
r[4]+=r[3];
goto P_0c0891f0;
P_0c0891f0: /* original 8442, guest PC 0x0c0891f0 */
if(!s->budget--) { s->failed_pc=0x0c0891f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0891f2;
P_0c0891f2: /* original 2100, guest PC 0x0c0891f2 */
if(!s->budget--) { s->failed_pc=0x0c0891f2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0891f4;
P_0c0891f4: /* original 8443, guest PC 0x0c0891f4 */
if(!s->budget--) { s->failed_pc=0x0c0891f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0891f6;
P_0c0891f6: /* original 2200, guest PC 0x0c0891f6 */
if(!s->budget--) { s->failed_pc=0x0c0891f6u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0891f8;
P_0c0891f8: /* original e004, guest PC 0x0c0891f8 */
if(!s->budget--) { s->failed_pc=0x0c0891f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0891fa;
P_0c0891fa: /* original f346, guest PC 0x0c0891fa */
if(!s->budget--) { s->failed_pc=0x0c0891fau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0891fc;
P_0c0891fc: /* original e01c, guest PC 0x0c0891fc */
if(!s->budget--) { s->failed_pc=0x0c0891fcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0891fe;
P_0c0891fe: /* original e528, guest PC 0x0c0891fe */
if(!s->budget--) { s->failed_pc=0x0c0891feu; return 0; }
r[5]=0x00000028u;
goto P_0c089200;
P_0c089200: /* original fe37, guest PC 0x0c089200 */
if(!s->budget--) { s->failed_pc=0x0c089200u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089202;
P_0c089202: /* original e634, guest PC 0x0c089202 */
if(!s->budget--) { s->failed_pc=0x0c089202u; return 0; }
r[6]=0x00000034u;
goto P_0c089204;
P_0c089204: /* original 6741, guest PC 0x0c089204 */
if(!s->budget--) { s->failed_pc=0x0c089204u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[7]=tmp;
goto P_0c089206;
P_0c089206: /* original d22b, guest PC 0x0c089206 */
if(!s->budget--) { s->failed_pc=0x0c089206u; return 0; }
r[2]=read(ram,0x0c0892b4u,4);
goto P_0c089208;
P_0c089208: /* original 420b, guest PC 0x0c089208 */
if(!s->budget--) { s->failed_pc=0x0c089208u; return 0; }
target=r[2];
r[16]=code_base|0x0c08920cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08920cu) { target=s->pc; goto dispatch; }
goto P_0c08920c;
P_0c08920a: /* original 64e3, guest PC 0x0c08920a */
if(!s->budget--) { s->failed_pc=0x0c08920au; return 0; }
r[4]=r[14];
goto P_0c08920c;
P_0c08920c: /* original 64d3, guest PC 0x0c08920c */
if(!s->budget--) { s->failed_pc=0x0c08920cu; return 0; }
r[4]=r[13];
goto P_0c08920e;
P_0c08920e: /* original 4408, guest PC 0x0c08920e */
if(!s->budget--) { s->failed_pc=0x0c08920eu; return 0; }
r[4]<<=2;
goto P_0c089210;
P_0c089210: /* original 6503, guest PC 0x0c089210 */
if(!s->budget--) { s->failed_pc=0x0c089210u; return 0; }
r[5]=r[0];
goto P_0c089212;
P_0c089212: /* original 6043, guest PC 0x0c089212 */
if(!s->budget--) { s->failed_pc=0x0c089212u; return 0; }
r[0]=r[4];
goto P_0c089214;
P_0c089214: /* original 4008, guest PC 0x0c089214 */
if(!s->budget--) { s->failed_pc=0x0c089214u; return 0; }
r[0]<<=2;
goto P_0c089216;
P_0c089216: /* original f3c6, guest PC 0x0c089216 */
if(!s->budget--) { s->failed_pc=0x0c089216u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089218;
P_0c089218: /* original e00c, guest PC 0x0c089218 */
if(!s->budget--) { s->failed_pc=0x0c089218u; return 0; }
r[0]=0x0000000cu;
goto P_0c08921a;
P_0c08921a: /* original 7bff, guest PC 0x0c08921a */
if(!s->budget--) { s->failed_pc=0x0c08921au; return 0; }
r[11]+=0xffffffffu;
goto P_0c08921c;
P_0c08921c: /* original fe37, guest PC 0x0c08921c */
if(!s->budget--) { s->failed_pc=0x0c08921cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08921e;
P_0c08921e: /* original 6043, guest PC 0x0c08921e */
if(!s->budget--) { s->failed_pc=0x0c08921eu; return 0; }
r[0]=r[4];
goto P_0c089220;
P_0c089220: /* original 7001, guest PC 0x0c089220 */
if(!s->budget--) { s->failed_pc=0x0c089220u; return 0; }
r[0]+=0x00000001u;
goto P_0c089222;
P_0c089222: /* original 4008, guest PC 0x0c089222 */
if(!s->budget--) { s->failed_pc=0x0c089222u; return 0; }
r[0]<<=2;
goto P_0c089224;
P_0c089224: /* original f3c6, guest PC 0x0c089224 */
if(!s->budget--) { s->failed_pc=0x0c089224u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089226;
P_0c089226: /* original e010, guest PC 0x0c089226 */
if(!s->budget--) { s->failed_pc=0x0c089226u; return 0; }
r[0]=0x00000010u;
goto P_0c089228;
P_0c089228: /* original fe37, guest PC 0x0c089228 */
if(!s->budget--) { s->failed_pc=0x0c089228u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08922a;
P_0c08922a: /* original 6043, guest PC 0x0c08922a */
if(!s->budget--) { s->failed_pc=0x0c08922au; return 0; }
r[0]=r[4];
goto P_0c08922c;
P_0c08922c: /* original 7002, guest PC 0x0c08922c */
if(!s->budget--) { s->failed_pc=0x0c08922cu; return 0; }
r[0]+=0x00000002u;
goto P_0c08922e;
P_0c08922e: /* original 4008, guest PC 0x0c08922e */
if(!s->budget--) { s->failed_pc=0x0c08922eu; return 0; }
r[0]<<=2;
goto P_0c089230;
P_0c089230: /* original f3c6, guest PC 0x0c089230 */
if(!s->budget--) { s->failed_pc=0x0c089230u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089232;
P_0c089232: /* original e014, guest PC 0x0c089232 */
if(!s->budget--) { s->failed_pc=0x0c089232u; return 0; }
r[0]=0x00000014u;
goto P_0c089234;
P_0c089234: /* original fe37, guest PC 0x0c089234 */
if(!s->budget--) { s->failed_pc=0x0c089234u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089236;
P_0c089236: /* original 6043, guest PC 0x0c089236 */
if(!s->budget--) { s->failed_pc=0x0c089236u; return 0; }
r[0]=r[4];
goto P_0c089238;
P_0c089238: /* original 7003, guest PC 0x0c089238 */
if(!s->budget--) { s->failed_pc=0x0c089238u; return 0; }
r[0]+=0x00000003u;
goto P_0c08923a;
P_0c08923a: /* original 4008, guest PC 0x0c08923a */
if(!s->budget--) { s->failed_pc=0x0c08923au; return 0; }
r[0]<<=2;
goto P_0c08923c;
P_0c08923c: /* original f3c6, guest PC 0x0c08923c */
if(!s->budget--) { s->failed_pc=0x0c08923cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08923e;
P_0c08923e: /* original e018, guest PC 0x0c08923e */
if(!s->budget--) { s->failed_pc=0x0c08923eu; return 0; }
r[0]=0x00000018u;
goto P_0c089240;
P_0c089240: /* original fe37, guest PC 0x0c089240 */
if(!s->budget--) { s->failed_pc=0x0c089240u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089242;
P_0c089242: /* original e020, guest PC 0x0c089242 */
if(!s->budget--) { s->failed_pc=0x0c089242u; return 0; }
r[0]=0x00000020u;
goto P_0c089244;
P_0c089244: /* original fef7, guest PC 0x0c089244 */
if(!s->budget--) { s->failed_pc=0x0c089244u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089246;
P_0c089246: /* original 6e53, guest PC 0x0c089246 */
if(!s->budget--) { s->failed_pc=0x0c089246u; return 0; }
r[14]=r[5];
goto P_0c089248;
P_0c089248: /* original 7e28, guest PC 0x0c089248 */
if(!s->budget--) { s->failed_pc=0x0c089248u; return 0; }
r[14]+=0x00000028u;
goto P_0c08924a;
P_0c08924a: /* original 2bb8, guest PC 0x0c08924a */
if(!s->budget--) { s->failed_pc=0x0c08924au; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c08924c;
P_0c08924c: /* original 8bb5, guest PC 0x0c08924c */
if(!s->budget--) { s->failed_pc=0x0c08924cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0891ba; }
goto P_0c08924e;
P_0c08924e: /* original a003, guest PC 0x0c08924e */
if(!s->budget--) { s->failed_pc=0x0c08924eu; return 0; }
r[14]=0x0000003cu;
goto P_0c089258;
P_0c089250: /* original ee3c, guest PC 0x0c089250 */
if(!s->budget--) { s->failed_pc=0x0c089250u; return 0; }
r[14]=0x0000003cu;
goto P_0c089252;
P_0c089252: /* original b00d, guest PC 0x0c089252 */
if(!s->budget--) { s->failed_pc=0x0c089252u; return 0; }
target=code_base|0x0c089270u; r[16]=code_base|0x0c089256u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c089256u) { target=s->pc; goto dispatch; }
goto P_0c089256;
P_0c089254: /* original 6493, guest PC 0x0c089254 */
if(!s->budget--) { s->failed_pc=0x0c089254u; return 0; }
r[4]=r[9];
goto P_0c089256;
P_0c089256: /* original 7eff, guest PC 0x0c089256 */
if(!s->budget--) { s->failed_pc=0x0c089256u; return 0; }
r[14]+=0xffffffffu;
goto P_0c089258;
P_0c089258: /* original 2ee8, guest PC 0x0c089258 */
if(!s->budget--) { s->failed_pc=0x0c089258u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08925a;
P_0c08925a: /* original 8bfa, guest PC 0x0c08925a */
if(!s->budget--) { s->failed_pc=0x0c08925au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c089252; }
goto P_0c08925c;
P_0c08925c: /* original 4f26, guest PC 0x0c08925c */
if(!s->budget--) { s->failed_pc=0x0c08925cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08925e;
P_0c08925e: /* original fff9, guest PC 0x0c08925e */
if(!s->budget--) { s->failed_pc=0x0c08925eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c089260;
P_0c089260: /* original 68f6, guest PC 0x0c089260 */
if(!s->budget--) { s->failed_pc=0x0c089260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c089262;
P_0c089262: /* original 69f6, guest PC 0x0c089262 */
if(!s->budget--) { s->failed_pc=0x0c089262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089264;
P_0c089264: /* original 6af6, guest PC 0x0c089264 */
if(!s->budget--) { s->failed_pc=0x0c089264u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089266;
P_0c089266: /* original 6bf6, guest PC 0x0c089266 */
if(!s->budget--) { s->failed_pc=0x0c089266u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089268;
P_0c089268: /* original 6cf6, guest PC 0x0c089268 */
if(!s->budget--) { s->failed_pc=0x0c089268u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08926a;
P_0c08926a: /* original 6df6, guest PC 0x0c08926a */
if(!s->budget--) { s->failed_pc=0x0c08926au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08926c;
P_0c08926c: /* original 000b, guest PC 0x0c08926c */
if(!s->budget--) { s->failed_pc=0x0c08926cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08926e: /* original 6ef6, guest PC 0x0c08926e */
if(!s->budget--) { s->failed_pc=0x0c08926eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c089270u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
