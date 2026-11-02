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
int vf3_away_batch6_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05014cu: goto P_0c05014c;
case 0x0c05014eu: goto P_0c05014e;
case 0x0c050150u: goto P_0c050150;
case 0x0c050152u: goto P_0c050152;
case 0x0c050154u: goto P_0c050154;
case 0x0c050156u: goto P_0c050156;
case 0x0c050158u: goto P_0c050158;
case 0x0c05015au: goto P_0c05015a;
case 0x0c05015cu: goto P_0c05015c;
case 0x0c05015eu: goto P_0c05015e;
case 0x0c050160u: goto P_0c050160;
case 0x0c050162u: goto P_0c050162;
case 0x0c0501eau: goto P_0c0501ea;
case 0x0c0501ecu: goto P_0c0501ec;
case 0x0c0501eeu: goto P_0c0501ee;
case 0x0c0501f0u: goto P_0c0501f0;
case 0x0c0501f2u: goto P_0c0501f2;
case 0x0c0501f4u: goto P_0c0501f4;
case 0x0c0501f6u: goto P_0c0501f6;
case 0x0c0501f8u: goto P_0c0501f8;
case 0x0c0501fau: goto P_0c0501fa;
case 0x0c0501fcu: goto P_0c0501fc;
case 0x0c0501feu: goto P_0c0501fe;
case 0x0c050200u: goto P_0c050200;
case 0x0c050202u: goto P_0c050202;
case 0x0c050204u: goto P_0c050204;
case 0x0c050206u: goto P_0c050206;
case 0x0c050208u: goto P_0c050208;
case 0x0c05020au: goto P_0c05020a;
case 0x0c05020cu: goto P_0c05020c;
case 0x0c05020eu: goto P_0c05020e;
case 0x0c050210u: goto P_0c050210;
case 0x0c050212u: goto P_0c050212;
case 0x0c050214u: goto P_0c050214;
case 0x0c050216u: goto P_0c050216;
case 0x0c050218u: goto P_0c050218;
case 0x0c05021au: goto P_0c05021a;
case 0x0c05021cu: goto P_0c05021c;
case 0x0c05021eu: goto P_0c05021e;
case 0x0c050220u: goto P_0c050220;
case 0x0c050222u: goto P_0c050222;
case 0x0c050224u: goto P_0c050224;
case 0x0c050226u: goto P_0c050226;
case 0x0c050228u: goto P_0c050228;
case 0x0c05022au: goto P_0c05022a;
case 0x0c05022cu: goto P_0c05022c;
case 0x0c05022eu: goto P_0c05022e;
case 0x0c050230u: goto P_0c050230;
case 0x0c050232u: goto P_0c050232;
case 0x0c050234u: goto P_0c050234;
case 0x0c050236u: goto P_0c050236;
case 0x0c050238u: goto P_0c050238;
case 0x0c05023au: goto P_0c05023a;
case 0x0c05023cu: goto P_0c05023c;
case 0x0c05023eu: goto P_0c05023e;
case 0x0c050240u: goto P_0c050240;
case 0x0c050242u: goto P_0c050242;
case 0x0c050244u: goto P_0c050244;
case 0x0c050246u: goto P_0c050246;
case 0x0c050248u: goto P_0c050248;
case 0x0c05024au: goto P_0c05024a;
case 0x0c05024cu: goto P_0c05024c;
case 0x0c05024eu: goto P_0c05024e;
case 0x0c0503bau: goto P_0c0503ba;
case 0x0c0503bcu: goto P_0c0503bc;
case 0x0c0503beu: goto P_0c0503be;
case 0x0c0503c0u: goto P_0c0503c0;
case 0x0c0503c2u: goto P_0c0503c2;
case 0x0c0503c4u: goto P_0c0503c4;
case 0x0c0503c6u: goto P_0c0503c6;
case 0x0c0503c8u: goto P_0c0503c8;
case 0x0c0503cau: goto P_0c0503ca;
case 0x0c0503ccu: goto P_0c0503cc;
case 0x0c0503ceu: goto P_0c0503ce;
case 0x0c0503d0u: goto P_0c0503d0;
case 0x0c0503d2u: goto P_0c0503d2;
case 0x0c0503d4u: goto P_0c0503d4;
case 0x0c0503d6u: goto P_0c0503d6;
case 0x0c0503d8u: goto P_0c0503d8;
case 0x0c0503dau: goto P_0c0503da;
case 0x0c0503dcu: goto P_0c0503dc;
case 0x0c0503deu: goto P_0c0503de;
case 0x0c0503e0u: goto P_0c0503e0;
case 0x0c0503e2u: goto P_0c0503e2;
case 0x0c0503e4u: goto P_0c0503e4;
case 0x0c0503e6u: goto P_0c0503e6;
case 0x0c0503e8u: goto P_0c0503e8;
case 0x0c0503eau: goto P_0c0503ea;
case 0x0c0503ecu: goto P_0c0503ec;
case 0x0c0503eeu: goto P_0c0503ee;
case 0x0c0503f0u: goto P_0c0503f0;
case 0x0c0503f2u: goto P_0c0503f2;
case 0x0c0503f4u: goto P_0c0503f4;
case 0x0c0503f6u: goto P_0c0503f6;
case 0x0c0503f8u: goto P_0c0503f8;
case 0x0c0503fau: goto P_0c0503fa;
case 0x0c0503fcu: goto P_0c0503fc;
case 0x0c0503feu: goto P_0c0503fe;
case 0x0c050400u: goto P_0c050400;
case 0x0c050402u: goto P_0c050402;
case 0x0c050404u: goto P_0c050404;
case 0x0c050406u: goto P_0c050406;
case 0x0c050408u: goto P_0c050408;
case 0x0c05040au: goto P_0c05040a;
case 0x0c05040cu: goto P_0c05040c;
case 0x0c05040eu: goto P_0c05040e;
case 0x0c050410u: goto P_0c050410;
case 0x0c050412u: goto P_0c050412;
case 0x0c050414u: goto P_0c050414;
case 0x0c050416u: goto P_0c050416;
case 0x0c050418u: goto P_0c050418;
case 0x0c05041au: goto P_0c05041a;
case 0x0c05041cu: goto P_0c05041c;
case 0x0c05041eu: goto P_0c05041e;
case 0x0c050420u: goto P_0c050420;
case 0x0c050422u: goto P_0c050422;
case 0x0c050424u: goto P_0c050424;
case 0x0c050426u: goto P_0c050426;
case 0x0c050428u: goto P_0c050428;
case 0x0c05042au: goto P_0c05042a;
case 0x0c05042cu: goto P_0c05042c;
case 0x0c05042eu: goto P_0c05042e;
case 0x0c050430u: goto P_0c050430;
case 0x0c050432u: goto P_0c050432;
case 0x0c050434u: goto P_0c050434;
case 0x0c050436u: goto P_0c050436;
case 0x0c050438u: goto P_0c050438;
case 0x0c05043au: goto P_0c05043a;
case 0x0c05043cu: goto P_0c05043c;
case 0x0c05043eu: goto P_0c05043e;
case 0x0c050440u: goto P_0c050440;
case 0x0c050442u: goto P_0c050442;
case 0x0c050444u: goto P_0c050444;
case 0x0c050446u: goto P_0c050446;
case 0x0c050448u: goto P_0c050448;
case 0x0c05044au: goto P_0c05044a;
case 0x0c05044cu: goto P_0c05044c;
case 0x0c05044eu: goto P_0c05044e;
case 0x0c050450u: goto P_0c050450;
case 0x0c050452u: goto P_0c050452;
case 0x0c050480u: goto P_0c050480;
case 0x0c050482u: goto P_0c050482;
case 0x0c050484u: goto P_0c050484;
case 0x0c050486u: goto P_0c050486;
case 0x0c050488u: goto P_0c050488;
case 0x0c05048au: goto P_0c05048a;
case 0x0c05048cu: goto P_0c05048c;
case 0x0c05048eu: goto P_0c05048e;
case 0x0c050490u: goto P_0c050490;
case 0x0c050492u: goto P_0c050492;
case 0x0c050494u: goto P_0c050494;
case 0x0c050496u: goto P_0c050496;
case 0x0c050498u: goto P_0c050498;
case 0x0c05049au: goto P_0c05049a;
case 0x0c05049cu: goto P_0c05049c;
case 0x0c05049eu: goto P_0c05049e;
case 0x0c0504a0u: goto P_0c0504a0;
case 0x0c0504a2u: goto P_0c0504a2;
case 0x0c0504a4u: goto P_0c0504a4;
case 0x0c0504a6u: goto P_0c0504a6;
case 0x0c0504a8u: goto P_0c0504a8;
case 0x0c0504aau: goto P_0c0504aa;
case 0x0c0504acu: goto P_0c0504ac;
case 0x0c0504aeu: goto P_0c0504ae;
case 0x0c0504b0u: goto P_0c0504b0;
case 0x0c0504b2u: goto P_0c0504b2;
case 0x0c0504b4u: goto P_0c0504b4;
case 0x0c0504b6u: goto P_0c0504b6;
case 0x0c0504b8u: goto P_0c0504b8;
case 0x0c0504bau: goto P_0c0504ba;
case 0x0c0504bcu: goto P_0c0504bc;
case 0x0c0504beu: goto P_0c0504be;
case 0x0c0504c0u: goto P_0c0504c0;
case 0x0c0504c2u: goto P_0c0504c2;
case 0x0c0504c4u: goto P_0c0504c4;
case 0x0c0504c6u: goto P_0c0504c6;
case 0x0c0504c8u: goto P_0c0504c8;
case 0x0c0504cau: goto P_0c0504ca;
case 0x0c0504ccu: goto P_0c0504cc;
case 0x0c0504ceu: goto P_0c0504ce;
case 0x0c0504d0u: goto P_0c0504d0;
case 0x0c0504d2u: goto P_0c0504d2;
case 0x0c0504d4u: goto P_0c0504d4;
case 0x0c0504d6u: goto P_0c0504d6;
case 0x0c0504d8u: goto P_0c0504d8;
case 0x0c0504dau: goto P_0c0504da;
case 0x0c0504dcu: goto P_0c0504dc;
case 0x0c0504deu: goto P_0c0504de;
case 0x0c0504e0u: goto P_0c0504e0;
case 0x0c0504e2u: goto P_0c0504e2;
case 0x0c0504e4u: goto P_0c0504e4;
case 0x0c0504e6u: goto P_0c0504e6;
case 0x0c0504e8u: goto P_0c0504e8;
case 0x0c0504eau: goto P_0c0504ea;
case 0x0c0504ecu: goto P_0c0504ec;
case 0x0c0504eeu: goto P_0c0504ee;
case 0x0c0504f0u: goto P_0c0504f0;
case 0x0c0504f2u: goto P_0c0504f2;
case 0x0c0504f4u: goto P_0c0504f4;
case 0x0c0504f6u: goto P_0c0504f6;
case 0x0c0504f8u: goto P_0c0504f8;
case 0x0c0504fau: goto P_0c0504fa;
case 0x0c0504fcu: goto P_0c0504fc;
case 0x0c0504feu: goto P_0c0504fe;
case 0x0c050500u: goto P_0c050500;
case 0x0c050502u: goto P_0c050502;
case 0x0c050504u: goto P_0c050504;
case 0x0c050506u: goto P_0c050506;
case 0x0c050508u: goto P_0c050508;
case 0x0c05050au: goto P_0c05050a;
case 0x0c05050cu: goto P_0c05050c;
case 0x0c05050eu: goto P_0c05050e;
case 0x0c050510u: goto P_0c050510;
case 0x0c050512u: goto P_0c050512;
case 0x0c050514u: goto P_0c050514;
case 0x0c050516u: goto P_0c050516;
case 0x0c050518u: goto P_0c050518;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05014c: /* original 6543, guest PC 0x0c05014c */
if(!s->budget--) { s->failed_pc=0x0c05014cu; return 0; }
r[5]=r[4];
goto P_0c05014e;
P_0c05014e: /* original 4509, guest PC 0x0c05014e */
if(!s->budget--) { s->failed_pc=0x0c05014eu; return 0; }
r[5]>>=2;
goto P_0c050150;
P_0c050150: /* original 4509, guest PC 0x0c050150 */
if(!s->budget--) { s->failed_pc=0x0c050150u; return 0; }
r[5]>>=2;
goto P_0c050152;
P_0c050152: /* original 6053, guest PC 0x0c050152 */
if(!s->budget--) { s->failed_pc=0x0c050152u; return 0; }
r[0]=r[5];
goto P_0c050154;
P_0c050154: /* original 6253, guest PC 0x0c050154 */
if(!s->budget--) { s->failed_pc=0x0c050154u; return 0; }
r[2]=r[5];
goto P_0c050156;
P_0c050156: /* original 4008, guest PC 0x0c050156 */
if(!s->budget--) { s->failed_pc=0x0c050156u; return 0; }
r[0]<<=2;
goto P_0c050158;
P_0c050158: /* original e30f, guest PC 0x0c050158 */
if(!s->budget--) { s->failed_pc=0x0c050158u; return 0; }
r[3]=0x0000000fu;
goto P_0c05015a;
P_0c05015a: /* original 302c, guest PC 0x0c05015a */
if(!s->budget--) { s->failed_pc=0x0c05015au; return 0; }
r[0]+=r[2];
goto P_0c05015c;
P_0c05015c: /* original 4000, guest PC 0x0c05015c */
if(!s->budget--) { s->failed_pc=0x0c05015cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05015e;
P_0c05015e: /* original 2439, guest PC 0x0c05015e */
if(!s->budget--) { s->failed_pc=0x0c05015eu; return 0; }
r[4]&=r[3];
goto P_0c050160;
P_0c050160: /* original 000b, guest PC 0x0c050160 */
if(!s->budget--) { s->failed_pc=0x0c050160u; return 0; }
target=r[16];
r[0]+=r[4];
s->pc=target; return ram->oob==0;
P_0c050162: /* original 304c, guest PC 0x0c050162 */
if(!s->budget--) { s->failed_pc=0x0c050162u; return 0; }
r[0]+=r[4];
if(!vf3_matrix_family(0x0c050164u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050164u; return 0; } return 1;
P_0c0501ea: /* original 2fe6, guest PC 0x0c0501ea */
if(!s->budget--) { s->failed_pc=0x0c0501eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0501ec;
P_0c0501ec: /* original 6e53, guest PC 0x0c0501ec */
if(!s->budget--) { s->failed_pc=0x0c0501ecu; return 0; }
r[14]=r[5];
goto P_0c0501ee;
P_0c0501ee: /* original 2fd6, guest PC 0x0c0501ee */
if(!s->budget--) { s->failed_pc=0x0c0501eeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0501f0;
P_0c0501f0: /* original 6d43, guest PC 0x0c0501f0 */
if(!s->budget--) { s->failed_pc=0x0c0501f0u; return 0; }
r[13]=r[4];
goto P_0c0501f2;
P_0c0501f2: /* original 2f86, guest PC 0x0c0501f2 */
if(!s->budget--) { s->failed_pc=0x0c0501f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0501f4;
P_0c0501f4: /* original 4f22, guest PC 0x0c0501f4 */
if(!s->budget--) { s->failed_pc=0x0c0501f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0501f6;
P_0c0501f6: /* original 64e0, guest PC 0x0c0501f6 */
if(!s->budget--) { s->failed_pc=0x0c0501f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c0501f8;
P_0c0501f8: /* original 4f12, guest PC 0x0c0501f8 */
if(!s->budget--) { s->failed_pc=0x0c0501f8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0501fa;
P_0c0501fa: /* original bfa7, guest PC 0x0c0501fa */
if(!s->budget--) { s->failed_pc=0x0c0501fau; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c0501feu;
r[4]=r[4]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0501feu) { target=s->pc; goto dispatch; }
goto P_0c0501fe;
P_0c0501fc: /* original 644c, guest PC 0x0c0501fc */
if(!s->budget--) { s->failed_pc=0x0c0501fcu; return 0; }
r[4]=r[4]&255u;
goto P_0c0501fe;
P_0c0501fe: /* original e264, guest PC 0x0c0501fe */
if(!s->budget--) { s->failed_pc=0x0c0501feu; return 0; }
r[2]=0x00000064u;
goto P_0c050200;
P_0c050200: /* original 202e, guest PC 0x0c050200 */
if(!s->budget--) { s->failed_pc=0x0c050200u; return 0; }
r[19]=(r[0]&65535u)*(r[2]&65535u);
goto P_0c050202;
P_0c050202: /* original 001a, guest PC 0x0c050202 */
if(!s->budget--) { s->failed_pc=0x0c050202u; return 0; }
r[0]=r[19];
goto P_0c050204;
P_0c050204: /* original 6803, guest PC 0x0c050204 */
if(!s->budget--) { s->failed_pc=0x0c050204u; return 0; }
r[8]=r[0];
goto P_0c050206;
P_0c050206: /* original 84e1, guest PC 0x0c050206 */
if(!s->budget--) { s->failed_pc=0x0c050206u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c050208;
P_0c050208: /* original bfa0, guest PC 0x0c050208 */
if(!s->budget--) { s->failed_pc=0x0c050208u; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c05020cu;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05020cu) { target=s->pc; goto dispatch; }
goto P_0c05020c;
P_0c05020a: /* original 640c, guest PC 0x0c05020a */
if(!s->budget--) { s->failed_pc=0x0c05020au; return 0; }
r[4]=r[0]&255u;
goto P_0c05020c;
P_0c05020c: /* original 380c, guest PC 0x0c05020c */
if(!s->budget--) { s->failed_pc=0x0c05020cu; return 0; }
r[8]+=r[0];
goto P_0c05020e;
P_0c05020e: /* original 2d81, guest PC 0x0c05020e */
if(!s->budget--) { s->failed_pc=0x0c05020eu; return 0; }
write(ram,r[13],r[8],2);
goto P_0c050210;
P_0c050210: /* original 84e2, guest PC 0x0c050210 */
if(!s->budget--) { s->failed_pc=0x0c050210u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c050212;
P_0c050212: /* original bf9b, guest PC 0x0c050212 */
if(!s->budget--) { s->failed_pc=0x0c050212u; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c050216u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050216u) { target=s->pc; goto dispatch; }
goto P_0c050216;
P_0c050214: /* original 640c, guest PC 0x0c050214 */
if(!s->budget--) { s->failed_pc=0x0c050214u; return 0; }
r[4]=r[0]&255u;
goto P_0c050216;
P_0c050216: /* original 80d2, guest PC 0x0c050216 */
if(!s->budget--) { s->failed_pc=0x0c050216u; return 0; }
write(ram,r[13]+2,r[0],1);
goto P_0c050218;
P_0c050218: /* original 84e3, guest PC 0x0c050218 */
if(!s->budget--) { s->failed_pc=0x0c050218u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c05021a;
P_0c05021a: /* original bf97, guest PC 0x0c05021a */
if(!s->budget--) { s->failed_pc=0x0c05021au; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c05021eu;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05021eu) { target=s->pc; goto dispatch; }
goto P_0c05021e;
P_0c05021c: /* original 640c, guest PC 0x0c05021c */
if(!s->budget--) { s->failed_pc=0x0c05021cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05021e;
P_0c05021e: /* original 80d3, guest PC 0x0c05021e */
if(!s->budget--) { s->failed_pc=0x0c05021eu; return 0; }
write(ram,r[13]+3,r[0],1);
goto P_0c050220;
P_0c050220: /* original 84e4, guest PC 0x0c050220 */
if(!s->budget--) { s->failed_pc=0x0c050220u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c050222;
P_0c050222: /* original bf93, guest PC 0x0c050222 */
if(!s->budget--) { s->failed_pc=0x0c050222u; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c050226u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050226u) { target=s->pc; goto dispatch; }
goto P_0c050226;
P_0c050224: /* original 640c, guest PC 0x0c050224 */
if(!s->budget--) { s->failed_pc=0x0c050224u; return 0; }
r[4]=r[0]&255u;
goto P_0c050226;
P_0c050226: /* original 80d4, guest PC 0x0c050226 */
if(!s->budget--) { s->failed_pc=0x0c050226u; return 0; }
write(ram,r[13]+4,r[0],1);
goto P_0c050228;
P_0c050228: /* original 84e5, guest PC 0x0c050228 */
if(!s->budget--) { s->failed_pc=0x0c050228u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c05022a;
P_0c05022a: /* original bf8f, guest PC 0x0c05022a */
if(!s->budget--) { s->failed_pc=0x0c05022au; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c05022eu;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05022eu) { target=s->pc; goto dispatch; }
goto P_0c05022e;
P_0c05022c: /* original 640c, guest PC 0x0c05022c */
if(!s->budget--) { s->failed_pc=0x0c05022cu; return 0; }
r[4]=r[0]&255u;
goto P_0c05022e;
P_0c05022e: /* original 80d5, guest PC 0x0c05022e */
if(!s->budget--) { s->failed_pc=0x0c05022eu; return 0; }
write(ram,r[13]+5,r[0],1);
goto P_0c050230;
P_0c050230: /* original 84e6, guest PC 0x0c050230 */
if(!s->budget--) { s->failed_pc=0x0c050230u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c050232;
P_0c050232: /* original bf8b, guest PC 0x0c050232 */
if(!s->budget--) { s->failed_pc=0x0c050232u; return 0; }
target=code_base|0x0c05014cu; r[16]=code_base|0x0c050236u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050236u) { target=s->pc; goto dispatch; }
goto P_0c050236;
P_0c050234: /* original 640c, guest PC 0x0c050234 */
if(!s->budget--) { s->failed_pc=0x0c050234u; return 0; }
r[4]=r[0]&255u;
goto P_0c050236;
P_0c050236: /* original 4f16, guest PC 0x0c050236 */
if(!s->budget--) { s->failed_pc=0x0c050236u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050238;
P_0c050238: /* original 80d6, guest PC 0x0c050238 */
if(!s->budget--) { s->failed_pc=0x0c050238u; return 0; }
write(ram,r[13]+6,r[0],1);
goto P_0c05023a;
P_0c05023a: /* original 84e7, guest PC 0x0c05023a */
if(!s->budget--) { s->failed_pc=0x0c05023au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c05023c;
P_0c05023c: /* original 4f26, guest PC 0x0c05023c */
if(!s->budget--) { s->failed_pc=0x0c05023cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05023e;
P_0c05023e: /* original d10c, guest PC 0x0c05023e */
if(!s->budget--) { s->failed_pc=0x0c05023eu; return 0; }
r[1]=read(ram,0x0c050270u,4);
goto P_0c050240;
P_0c050240: /* original 600c, guest PC 0x0c050240 */
if(!s->budget--) { s->failed_pc=0x0c050240u; return 0; }
r[0]=r[0]&255u;
goto P_0c050242;
P_0c050242: /* original c907, guest PC 0x0c050242 */
if(!s->budget--) { s->failed_pc=0x0c050242u; return 0; }
r[0]&=7u;
goto P_0c050244;
P_0c050244: /* original 001c, guest PC 0x0c050244 */
if(!s->budget--) { s->failed_pc=0x0c050244u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c050246;
P_0c050246: /* original 80d7, guest PC 0x0c050246 */
if(!s->budget--) { s->failed_pc=0x0c050246u; return 0; }
write(ram,r[13]+7,r[0],1);
goto P_0c050248;
P_0c050248: /* original 68f6, guest PC 0x0c050248 */
if(!s->budget--) { s->failed_pc=0x0c050248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05024a;
P_0c05024a: /* original 6df6, guest PC 0x0c05024a */
if(!s->budget--) { s->failed_pc=0x0c05024au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05024c;
P_0c05024c: /* original 000b, guest PC 0x0c05024c */
if(!s->budget--) { s->failed_pc=0x0c05024cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05024e: /* original 6ef6, guest PC 0x0c05024e */
if(!s->budget--) { s->failed_pc=0x0c05024eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c050250u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050250u; return 0; } return 1;
P_0c0503ba: /* original 2fe6, guest PC 0x0c0503ba */
if(!s->budget--) { s->failed_pc=0x0c0503bau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503bc;
P_0c0503bc: /* original 6253, guest PC 0x0c0503bc */
if(!s->budget--) { s->failed_pc=0x0c0503bcu; return 0; }
r[2]=r[5];
goto P_0c0503be;
P_0c0503be: /* original 2fd6, guest PC 0x0c0503be */
if(!s->budget--) { s->failed_pc=0x0c0503beu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503c0;
P_0c0503c0: /* original 2fc6, guest PC 0x0c0503c0 */
if(!s->budget--) { s->failed_pc=0x0c0503c0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503c2;
P_0c0503c2: /* original 2fb6, guest PC 0x0c0503c2 */
if(!s->budget--) { s->failed_pc=0x0c0503c2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503c4;
P_0c0503c4: /* original 6b43, guest PC 0x0c0503c4 */
if(!s->budget--) { s->failed_pc=0x0c0503c4u; return 0; }
r[11]=r[4];
goto P_0c0503c6;
P_0c0503c6: /* original 2fa6, guest PC 0x0c0503c6 */
if(!s->budget--) { s->failed_pc=0x0c0503c6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503c8;
P_0c0503c8: /* original 2f96, guest PC 0x0c0503c8 */
if(!s->budget--) { s->failed_pc=0x0c0503c8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503ca;
P_0c0503ca: /* original 2f86, guest PC 0x0c0503ca */
if(!s->budget--) { s->failed_pc=0x0c0503cau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503cc;
P_0c0503cc: /* original 4f22, guest PC 0x0c0503cc */
if(!s->budget--) { s->failed_pc=0x0c0503ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0503ce;
P_0c0503ce: /* original 4f12, guest PC 0x0c0503ce */
if(!s->budget--) { s->failed_pc=0x0c0503ceu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0503d0;
P_0c0503d0: /* original 7ffc, guest PC 0x0c0503d0 */
if(!s->budget--) { s->failed_pc=0x0c0503d0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0503d2;
P_0c0503d2: /* original 2f52, guest PC 0x0c0503d2 */
if(!s->budget--) { s->failed_pc=0x0c0503d2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0503d4;
P_0c0503d4: /* original 9c42, guest PC 0x0c0503d4 */
if(!s->budget--) { s->failed_pc=0x0c0503d4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05045cu,2);
goto P_0c0503d6;
P_0c0503d6: /* original d325, guest PC 0x0c0503d6 */
if(!s->budget--) { s->failed_pc=0x0c0503d6u; return 0; }
r[3]=read(ram,0x0c05046cu,4);
goto P_0c0503d8;
P_0c0503d8: /* original 2bcf, guest PC 0x0c0503d8 */
if(!s->budget--) { s->failed_pc=0x0c0503d8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[12]);
goto P_0c0503da;
P_0c0503da: /* original 2f56, guest PC 0x0c0503da */
if(!s->budget--) { s->failed_pc=0x0c0503dau; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503dc;
P_0c0503dc: /* original 2fb6, guest PC 0x0c0503dc */
if(!s->budget--) { s->failed_pc=0x0c0503dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503de;
P_0c0503de: /* original d224, guest PC 0x0c0503de */
if(!s->budget--) { s->failed_pc=0x0c0503deu; return 0; }
r[2]=read(ram,0x0c050470u,4);
goto P_0c0503e0;
P_0c0503e0: /* original 0c1a, guest PC 0x0c0503e0 */
if(!s->budget--) { s->failed_pc=0x0c0503e0u; return 0; }
r[12]=r[19];
goto P_0c0503e2;
P_0c0503e2: /* original d120, guest PC 0x0c0503e2 */
if(!s->budget--) { s->failed_pc=0x0c0503e2u; return 0; }
r[1]=read(ram,0x0c050464u,4);
goto P_0c0503e4;
P_0c0503e4: /* original 6ccf, guest PC 0x0c0503e4 */
if(!s->budget--) { s->failed_pc=0x0c0503e4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0503e6;
P_0c0503e6: /* original 3c3c, guest PC 0x0c0503e6 */
if(!s->budget--) { s->failed_pc=0x0c0503e6u; return 0; }
r[12]+=r[3];
goto P_0c0503e8;
P_0c0503e8: /* original 410b, guest PC 0x0c0503e8 */
if(!s->budget--) { s->failed_pc=0x0c0503e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0503ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0503ecu) { target=s->pc; goto dispatch; }
goto P_0c0503ec;
P_0c0503ea: /* original 2f26, guest PC 0x0c0503ea */
if(!s->budget--) { s->failed_pc=0x0c0503eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0503ec;
P_0c0503ec: /* original e301, guest PC 0x0c0503ec */
if(!s->budget--) { s->failed_pc=0x0c0503ecu; return 0; }
r[3]=0x00000001u;
goto P_0c0503ee;
P_0c0503ee: /* original 7f0c, guest PC 0x0c0503ee */
if(!s->budget--) { s->failed_pc=0x0c0503eeu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0503f0;
P_0c0503f0: /* original 6df2, guest PC 0x0c0503f0 */
if(!s->budget--) { s->failed_pc=0x0c0503f0u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0503f2;
P_0c0503f2: /* original 1c3c, guest PC 0x0c0503f2 */
if(!s->budget--) { s->failed_pc=0x0c0503f2u; return 0; }
write(ram,r[12]+48,r[3],4);
goto P_0c0503f4;
P_0c0503f4: /* original 52c1, guest PC 0x0c0503f4 */
if(!s->budget--) { s->failed_pc=0x0c0503f4u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0503f6;
P_0c0503f6: /* original d01f, guest PC 0x0c0503f6 */
if(!s->budget--) { s->failed_pc=0x0c0503f6u; return 0; }
r[0]=read(ram,0x0c050474u,4);
goto P_0c0503f8;
P_0c0503f8: /* original 6323, guest PC 0x0c0503f8 */
if(!s->budget--) { s->failed_pc=0x0c0503f8u; return 0; }
r[3]=r[2];
goto P_0c0503fa;
P_0c0503fa: /* original 4208, guest PC 0x0c0503fa */
if(!s->budget--) { s->failed_pc=0x0c0503fau; return 0; }
r[2]<<=2;
goto P_0c0503fc;
P_0c0503fc: /* original 323c, guest PC 0x0c0503fc */
if(!s->budget--) { s->failed_pc=0x0c0503fcu; return 0; }
r[2]+=r[3];
goto P_0c0503fe;
P_0c0503fe: /* original 4208, guest PC 0x0c0503fe */
if(!s->budget--) { s->failed_pc=0x0c0503feu; return 0; }
r[2]<<=2;
goto P_0c050400;
P_0c050400: /* original 4208, guest PC 0x0c050400 */
if(!s->budget--) { s->failed_pc=0x0c050400u; return 0; }
r[2]<<=2;
goto P_0c050402;
P_0c050402: /* original 622f, guest PC 0x0c050402 */
if(!s->budget--) { s->failed_pc=0x0c050402u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c050404;
P_0c050404: /* original 012e, guest PC 0x0c050404 */
if(!s->budget--) { s->failed_pc=0x0c050404u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c050406;
P_0c050406: /* original 1c1d, guest PC 0x0c050406 */
if(!s->budget--) { s->failed_pc=0x0c050406u; return 0; }
write(ram,r[12]+52,r[1],4);
goto P_0c050408;
P_0c050408: /* original d81b, guest PC 0x0c050408 */
if(!s->budget--) { s->failed_pc=0x0c050408u; return 0; }
r[8]=read(ram,0x0c050478u,4);
goto P_0c05040a;
P_0c05040a: /* original d91c, guest PC 0x0c05040a */
if(!s->budget--) { s->failed_pc=0x0c05040au; return 0; }
r[9]=read(ram,0x0c05047cu,4);
goto P_0c05040c;
P_0c05040c: /* original 9a27, guest PC 0x0c05040c */
if(!s->budget--) { s->failed_pc=0x0c05040cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05045eu,2);
goto P_0c05040e;
P_0c05040e: /* original a010, guest PC 0x0c05040e */
if(!s->budget--) { s->failed_pc=0x0c05040eu; return 0; }
r[14]=0x00000000u;
goto P_0c050432;
P_0c050410: /* original ee00, guest PC 0x0c050410 */
if(!s->budget--) { s->failed_pc=0x0c050410u; return 0; }
r[14]=0x00000000u;
goto P_0c050412;
P_0c050412: /* original 2fe6, guest PC 0x0c050412 */
if(!s->budget--) { s->failed_pc=0x0c050412u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050414;
P_0c050414: /* original d213, guest PC 0x0c050414 */
if(!s->budget--) { s->failed_pc=0x0c050414u; return 0; }
r[2]=read(ram,0x0c050464u,4);
goto P_0c050416;
P_0c050416: /* original 420b, guest PC 0x0c050416 */
if(!s->budget--) { s->failed_pc=0x0c050416u; return 0; }
target=r[2];
r[16]=code_base|0x0c05041au;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05041au) { target=s->pc; goto dispatch; }
goto P_0c05041a;
P_0c050418: /* original 2f96, guest PC 0x0c050418 */
if(!s->budget--) { s->failed_pc=0x0c050418u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05041a;
P_0c05041a: /* original 65e3, guest PC 0x0c05041a */
if(!s->budget--) { s->failed_pc=0x0c05041au; return 0; }
r[5]=r[14];
goto P_0c05041c;
P_0c05041c: /* original 66d3, guest PC 0x0c05041c */
if(!s->budget--) { s->failed_pc=0x0c05041cu; return 0; }
r[6]=r[13];
goto P_0c05041e;
P_0c05041e: /* original 7f08, guest PC 0x0c05041e */
if(!s->budget--) { s->failed_pc=0x0c05041eu; return 0; }
r[15]+=0x00000008u;
goto P_0c050420;
P_0c050420: /* original 480b, guest PC 0x0c050420 */
if(!s->budget--) { s->failed_pc=0x0c050420u; return 0; }
target=r[8];
r[16]=code_base|0x0c050424u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050424u) { target=s->pc; goto dispatch; }
goto P_0c050424;
P_0c050422: /* original 64b3, guest PC 0x0c050422 */
if(!s->budget--) { s->failed_pc=0x0c050422u; return 0; }
r[4]=r[11];
goto P_0c050424;
P_0c050424: /* original 6403, guest PC 0x0c050424 */
if(!s->budget--) { s->failed_pc=0x0c050424u; return 0; }
r[4]=r[0];
goto P_0c050426;
P_0c050426: /* original 4411, guest PC 0x0c050426 */
if(!s->budget--) { s->failed_pc=0x0c050426u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c050428;
P_0c050428: /* original 8901, guest PC 0x0c050428 */
if(!s->budget--) { s->failed_pc=0x0c050428u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05042e; }
goto P_0c05042a;
P_0c05042a: /* original a008, guest PC 0x0c05042a */
if(!s->budget--) { s->failed_pc=0x0c05042au; return 0; }
r[0]=r[4];
goto P_0c05043e;
P_0c05042c: /* original 6043, guest PC 0x0c05042c */
if(!s->budget--) { s->failed_pc=0x0c05042cu; return 0; }
r[0]=r[4];
goto P_0c05042e;
P_0c05042e: /* original 7e01, guest PC 0x0c05042e */
if(!s->budget--) { s->failed_pc=0x0c05042eu; return 0; }
r[14]+=0x00000001u;
goto P_0c050430;
P_0c050430: /* original 3dac, guest PC 0x0c050430 */
if(!s->budget--) { s->failed_pc=0x0c050430u; return 0; }
r[13]+=r[10];
goto P_0c050432;
P_0c050432: /* original 52c7, guest PC 0x0c050432 */
if(!s->budget--) { s->failed_pc=0x0c050432u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c050434;
P_0c050434: /* original 6322, guest PC 0x0c050434 */
if(!s->budget--) { s->failed_pc=0x0c050434u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c050436;
P_0c050436: /* original 7301, guest PC 0x0c050436 */
if(!s->budget--) { s->failed_pc=0x0c050436u; return 0; }
r[3]+=0x00000001u;
goto P_0c050438;
P_0c050438: /* original 3e33, guest PC 0x0c050438 */
if(!s->budget--) { s->failed_pc=0x0c050438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c05043a;
P_0c05043a: /* original 8bea, guest PC 0x0c05043a */
if(!s->budget--) { s->failed_pc=0x0c05043au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050412; }
goto P_0c05043c;
P_0c05043c: /* original e000, guest PC 0x0c05043c */
if(!s->budget--) { s->failed_pc=0x0c05043cu; return 0; }
r[0]=0x00000000u;
goto P_0c05043e;
P_0c05043e: /* original 7f04, guest PC 0x0c05043e */
if(!s->budget--) { s->failed_pc=0x0c05043eu; return 0; }
r[15]+=0x00000004u;
goto P_0c050440;
P_0c050440: /* original 4f16, guest PC 0x0c050440 */
if(!s->budget--) { s->failed_pc=0x0c050440u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050442;
P_0c050442: /* original 4f26, guest PC 0x0c050442 */
if(!s->budget--) { s->failed_pc=0x0c050442u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050444;
P_0c050444: /* original 68f6, guest PC 0x0c050444 */
if(!s->budget--) { s->failed_pc=0x0c050444u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c050446;
P_0c050446: /* original 69f6, guest PC 0x0c050446 */
if(!s->budget--) { s->failed_pc=0x0c050446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c050448;
P_0c050448: /* original 6af6, guest PC 0x0c050448 */
if(!s->budget--) { s->failed_pc=0x0c050448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05044a;
P_0c05044a: /* original 6bf6, guest PC 0x0c05044a */
if(!s->budget--) { s->failed_pc=0x0c05044au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05044c;
P_0c05044c: /* original 6cf6, guest PC 0x0c05044c */
if(!s->budget--) { s->failed_pc=0x0c05044cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05044e;
P_0c05044e: /* original 6df6, guest PC 0x0c05044e */
if(!s->budget--) { s->failed_pc=0x0c05044eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050450;
P_0c050450: /* original 000b, guest PC 0x0c050450 */
if(!s->budget--) { s->failed_pc=0x0c050450u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050452: /* original 6ef6, guest PC 0x0c050452 */
if(!s->budget--) { s->failed_pc=0x0c050452u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c050454u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050454u; return 0; } return 1;
P_0c050480: /* original 2fe6, guest PC 0x0c050480 */
if(!s->budget--) { s->failed_pc=0x0c050480u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050482;
P_0c050482: /* original 6253, guest PC 0x0c050482 */
if(!s->budget--) { s->failed_pc=0x0c050482u; return 0; }
r[2]=r[5];
goto P_0c050484;
P_0c050484: /* original 2fd6, guest PC 0x0c050484 */
if(!s->budget--) { s->failed_pc=0x0c050484u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050486;
P_0c050486: /* original 2fc6, guest PC 0x0c050486 */
if(!s->budget--) { s->failed_pc=0x0c050486u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050488;
P_0c050488: /* original 2fb6, guest PC 0x0c050488 */
if(!s->budget--) { s->failed_pc=0x0c050488u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05048a;
P_0c05048a: /* original 6b43, guest PC 0x0c05048a */
if(!s->budget--) { s->failed_pc=0x0c05048au; return 0; }
r[11]=r[4];
goto P_0c05048c;
P_0c05048c: /* original 2fa6, guest PC 0x0c05048c */
if(!s->budget--) { s->failed_pc=0x0c05048cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05048e;
P_0c05048e: /* original 2f96, guest PC 0x0c05048e */
if(!s->budget--) { s->failed_pc=0x0c05048eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050490;
P_0c050490: /* original 2f86, guest PC 0x0c050490 */
if(!s->budget--) { s->failed_pc=0x0c050490u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050492;
P_0c050492: /* original 4f22, guest PC 0x0c050492 */
if(!s->budget--) { s->failed_pc=0x0c050492u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050494;
P_0c050494: /* original 4f12, guest PC 0x0c050494 */
if(!s->budget--) { s->failed_pc=0x0c050494u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c050496;
P_0c050496: /* original 7ffc, guest PC 0x0c050496 */
if(!s->budget--) { s->failed_pc=0x0c050496u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c050498;
P_0c050498: /* original 2f52, guest PC 0x0c050498 */
if(!s->budget--) { s->failed_pc=0x0c050498u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05049a;
P_0c05049a: /* original 9c55, guest PC 0x0c05049a */
if(!s->budget--) { s->failed_pc=0x0c05049au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050548u,2);
goto P_0c05049c;
P_0c05049c: /* original d32b, guest PC 0x0c05049c */
if(!s->budget--) { s->failed_pc=0x0c05049cu; return 0; }
r[3]=read(ram,0x0c05054cu,4);
goto P_0c05049e;
P_0c05049e: /* original 2bcf, guest PC 0x0c05049e */
if(!s->budget--) { s->failed_pc=0x0c05049eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[12]);
goto P_0c0504a0;
P_0c0504a0: /* original 2f56, guest PC 0x0c0504a0 */
if(!s->budget--) { s->failed_pc=0x0c0504a0u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504a2;
P_0c0504a2: /* original 2fb6, guest PC 0x0c0504a2 */
if(!s->budget--) { s->failed_pc=0x0c0504a2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504a4;
P_0c0504a4: /* original d22a, guest PC 0x0c0504a4 */
if(!s->budget--) { s->failed_pc=0x0c0504a4u; return 0; }
r[2]=read(ram,0x0c050550u,4);
goto P_0c0504a6;
P_0c0504a6: /* original 0c1a, guest PC 0x0c0504a6 */
if(!s->budget--) { s->failed_pc=0x0c0504a6u; return 0; }
r[12]=r[19];
goto P_0c0504a8;
P_0c0504a8: /* original d12a, guest PC 0x0c0504a8 */
if(!s->budget--) { s->failed_pc=0x0c0504a8u; return 0; }
r[1]=read(ram,0x0c050554u,4);
goto P_0c0504aa;
P_0c0504aa: /* original 6ccf, guest PC 0x0c0504aa */
if(!s->budget--) { s->failed_pc=0x0c0504aau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0504ac;
P_0c0504ac: /* original 3c3c, guest PC 0x0c0504ac */
if(!s->budget--) { s->failed_pc=0x0c0504acu; return 0; }
r[12]+=r[3];
goto P_0c0504ae;
P_0c0504ae: /* original 410b, guest PC 0x0c0504ae */
if(!s->budget--) { s->failed_pc=0x0c0504aeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0504b2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0504b2u) { target=s->pc; goto dispatch; }
goto P_0c0504b2;
P_0c0504b0: /* original 2f26, guest PC 0x0c0504b0 */
if(!s->budget--) { s->failed_pc=0x0c0504b0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504b2;
P_0c0504b2: /* original e301, guest PC 0x0c0504b2 */
if(!s->budget--) { s->failed_pc=0x0c0504b2u; return 0; }
r[3]=0x00000001u;
goto P_0c0504b4;
P_0c0504b4: /* original 7f0c, guest PC 0x0c0504b4 */
if(!s->budget--) { s->failed_pc=0x0c0504b4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0504b6;
P_0c0504b6: /* original 6df2, guest PC 0x0c0504b6 */
if(!s->budget--) { s->failed_pc=0x0c0504b6u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0504b8;
P_0c0504b8: /* original 1c3c, guest PC 0x0c0504b8 */
if(!s->budget--) { s->failed_pc=0x0c0504b8u; return 0; }
write(ram,r[12]+48,r[3],4);
goto P_0c0504ba;
P_0c0504ba: /* original 52c1, guest PC 0x0c0504ba */
if(!s->budget--) { s->failed_pc=0x0c0504bau; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0504bc;
P_0c0504bc: /* original d026, guest PC 0x0c0504bc */
if(!s->budget--) { s->failed_pc=0x0c0504bcu; return 0; }
r[0]=read(ram,0x0c050558u,4);
goto P_0c0504be;
P_0c0504be: /* original 6323, guest PC 0x0c0504be */
if(!s->budget--) { s->failed_pc=0x0c0504beu; return 0; }
r[3]=r[2];
goto P_0c0504c0;
P_0c0504c0: /* original 4208, guest PC 0x0c0504c0 */
if(!s->budget--) { s->failed_pc=0x0c0504c0u; return 0; }
r[2]<<=2;
goto P_0c0504c2;
P_0c0504c2: /* original 323c, guest PC 0x0c0504c2 */
if(!s->budget--) { s->failed_pc=0x0c0504c2u; return 0; }
r[2]+=r[3];
goto P_0c0504c4;
P_0c0504c4: /* original 4208, guest PC 0x0c0504c4 */
if(!s->budget--) { s->failed_pc=0x0c0504c4u; return 0; }
r[2]<<=2;
goto P_0c0504c6;
P_0c0504c6: /* original 4208, guest PC 0x0c0504c6 */
if(!s->budget--) { s->failed_pc=0x0c0504c6u; return 0; }
r[2]<<=2;
goto P_0c0504c8;
P_0c0504c8: /* original 622f, guest PC 0x0c0504c8 */
if(!s->budget--) { s->failed_pc=0x0c0504c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0504ca;
P_0c0504ca: /* original 012e, guest PC 0x0c0504ca */
if(!s->budget--) { s->failed_pc=0x0c0504cau; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0504cc;
P_0c0504cc: /* original 1c1d, guest PC 0x0c0504cc */
if(!s->budget--) { s->failed_pc=0x0c0504ccu; return 0; }
write(ram,r[12]+52,r[1],4);
goto P_0c0504ce;
P_0c0504ce: /* original d823, guest PC 0x0c0504ce */
if(!s->budget--) { s->failed_pc=0x0c0504ceu; return 0; }
r[8]=read(ram,0x0c05055cu,4);
goto P_0c0504d0;
P_0c0504d0: /* original d923, guest PC 0x0c0504d0 */
if(!s->budget--) { s->failed_pc=0x0c0504d0u; return 0; }
r[9]=read(ram,0x0c050560u,4);
goto P_0c0504d2;
P_0c0504d2: /* original 9a3a, guest PC 0x0c0504d2 */
if(!s->budget--) { s->failed_pc=0x0c0504d2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05054au,2);
goto P_0c0504d4;
P_0c0504d4: /* original a010, guest PC 0x0c0504d4 */
if(!s->budget--) { s->failed_pc=0x0c0504d4u; return 0; }
r[14]=0x00000000u;
goto P_0c0504f8;
P_0c0504d6: /* original ee00, guest PC 0x0c0504d6 */
if(!s->budget--) { s->failed_pc=0x0c0504d6u; return 0; }
r[14]=0x00000000u;
goto P_0c0504d8;
P_0c0504d8: /* original 2fe6, guest PC 0x0c0504d8 */
if(!s->budget--) { s->failed_pc=0x0c0504d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504da;
P_0c0504da: /* original d21e, guest PC 0x0c0504da */
if(!s->budget--) { s->failed_pc=0x0c0504dau; return 0; }
r[2]=read(ram,0x0c050554u,4);
goto P_0c0504dc;
P_0c0504dc: /* original 420b, guest PC 0x0c0504dc */
if(!s->budget--) { s->failed_pc=0x0c0504dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0504e0u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0504e0u) { target=s->pc; goto dispatch; }
goto P_0c0504e0;
P_0c0504de: /* original 2f96, guest PC 0x0c0504de */
if(!s->budget--) { s->failed_pc=0x0c0504deu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0504e0;
P_0c0504e0: /* original 65e3, guest PC 0x0c0504e0 */
if(!s->budget--) { s->failed_pc=0x0c0504e0u; return 0; }
r[5]=r[14];
goto P_0c0504e2;
P_0c0504e2: /* original 66d3, guest PC 0x0c0504e2 */
if(!s->budget--) { s->failed_pc=0x0c0504e2u; return 0; }
r[6]=r[13];
goto P_0c0504e4;
P_0c0504e4: /* original 7f08, guest PC 0x0c0504e4 */
if(!s->budget--) { s->failed_pc=0x0c0504e4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0504e6;
P_0c0504e6: /* original 480b, guest PC 0x0c0504e6 */
if(!s->budget--) { s->failed_pc=0x0c0504e6u; return 0; }
target=r[8];
r[16]=code_base|0x0c0504eau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0504eau) { target=s->pc; goto dispatch; }
goto P_0c0504ea;
P_0c0504e8: /* original 64b3, guest PC 0x0c0504e8 */
if(!s->budget--) { s->failed_pc=0x0c0504e8u; return 0; }
r[4]=r[11];
goto P_0c0504ea;
P_0c0504ea: /* original 6403, guest PC 0x0c0504ea */
if(!s->budget--) { s->failed_pc=0x0c0504eau; return 0; }
r[4]=r[0];
goto P_0c0504ec;
P_0c0504ec: /* original 4411, guest PC 0x0c0504ec */
if(!s->budget--) { s->failed_pc=0x0c0504ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0504ee;
P_0c0504ee: /* original 8901, guest PC 0x0c0504ee */
if(!s->budget--) { s->failed_pc=0x0c0504eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0504f4; }
goto P_0c0504f0;
P_0c0504f0: /* original a008, guest PC 0x0c0504f0 */
if(!s->budget--) { s->failed_pc=0x0c0504f0u; return 0; }
r[0]=r[4];
goto P_0c050504;
P_0c0504f2: /* original 6043, guest PC 0x0c0504f2 */
if(!s->budget--) { s->failed_pc=0x0c0504f2u; return 0; }
r[0]=r[4];
goto P_0c0504f4;
P_0c0504f4: /* original 7e01, guest PC 0x0c0504f4 */
if(!s->budget--) { s->failed_pc=0x0c0504f4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0504f6;
P_0c0504f6: /* original 3dac, guest PC 0x0c0504f6 */
if(!s->budget--) { s->failed_pc=0x0c0504f6u; return 0; }
r[13]+=r[10];
goto P_0c0504f8;
P_0c0504f8: /* original 52c7, guest PC 0x0c0504f8 */
if(!s->budget--) { s->failed_pc=0x0c0504f8u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c0504fa;
P_0c0504fa: /* original 6322, guest PC 0x0c0504fa */
if(!s->budget--) { s->failed_pc=0x0c0504fau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0504fc;
P_0c0504fc: /* original 7301, guest PC 0x0c0504fc */
if(!s->budget--) { s->failed_pc=0x0c0504fcu; return 0; }
r[3]+=0x00000001u;
goto P_0c0504fe;
P_0c0504fe: /* original 3e33, guest PC 0x0c0504fe */
if(!s->budget--) { s->failed_pc=0x0c0504feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c050500;
P_0c050500: /* original 8bea, guest PC 0x0c050500 */
if(!s->budget--) { s->failed_pc=0x0c050500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0504d8; }
goto P_0c050502;
P_0c050502: /* original e000, guest PC 0x0c050502 */
if(!s->budget--) { s->failed_pc=0x0c050502u; return 0; }
r[0]=0x00000000u;
goto P_0c050504;
P_0c050504: /* original 7f04, guest PC 0x0c050504 */
if(!s->budget--) { s->failed_pc=0x0c050504u; return 0; }
r[15]+=0x00000004u;
goto P_0c050506;
P_0c050506: /* original 4f16, guest PC 0x0c050506 */
if(!s->budget--) { s->failed_pc=0x0c050506u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c050508;
P_0c050508: /* original 4f26, guest PC 0x0c050508 */
if(!s->budget--) { s->failed_pc=0x0c050508u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05050a;
P_0c05050a: /* original 68f6, guest PC 0x0c05050a */
if(!s->budget--) { s->failed_pc=0x0c05050au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05050c;
P_0c05050c: /* original 69f6, guest PC 0x0c05050c */
if(!s->budget--) { s->failed_pc=0x0c05050cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05050e;
P_0c05050e: /* original 6af6, guest PC 0x0c05050e */
if(!s->budget--) { s->failed_pc=0x0c05050eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c050510;
P_0c050510: /* original 6bf6, guest PC 0x0c050510 */
if(!s->budget--) { s->failed_pc=0x0c050510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050512;
P_0c050512: /* original 6cf6, guest PC 0x0c050512 */
if(!s->budget--) { s->failed_pc=0x0c050512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050514;
P_0c050514: /* original 6df6, guest PC 0x0c050514 */
if(!s->budget--) { s->failed_pc=0x0c050514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050516;
P_0c050516: /* original 000b, guest PC 0x0c050516 */
if(!s->budget--) { s->failed_pc=0x0c050516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050518: /* original 6ef6, guest PC 0x0c050518 */
if(!s->budget--) { s->failed_pc=0x0c050518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05051au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
