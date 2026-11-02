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
int vf3_away_batch11_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06951au: goto P_0c06951a;
case 0x0c06951cu: goto P_0c06951c;
case 0x0c06951eu: goto P_0c06951e;
case 0x0c069520u: goto P_0c069520;
case 0x0c069522u: goto P_0c069522;
case 0x0c069524u: goto P_0c069524;
case 0x0c069526u: goto P_0c069526;
case 0x0c069528u: goto P_0c069528;
case 0x0c06952au: goto P_0c06952a;
case 0x0c06952cu: goto P_0c06952c;
case 0x0c06952eu: goto P_0c06952e;
case 0x0c069530u: goto P_0c069530;
case 0x0c069532u: goto P_0c069532;
case 0x0c069534u: goto P_0c069534;
case 0x0c069536u: goto P_0c069536;
case 0x0c069538u: goto P_0c069538;
case 0x0c06953au: goto P_0c06953a;
case 0x0c06953cu: goto P_0c06953c;
case 0x0c06953eu: goto P_0c06953e;
case 0x0c069540u: goto P_0c069540;
case 0x0c069542u: goto P_0c069542;
case 0x0c069544u: goto P_0c069544;
case 0x0c069546u: goto P_0c069546;
case 0x0c069548u: goto P_0c069548;
case 0x0c06954au: goto P_0c06954a;
case 0x0c06954cu: goto P_0c06954c;
case 0x0c06954eu: goto P_0c06954e;
case 0x0c069550u: goto P_0c069550;
case 0x0c069552u: goto P_0c069552;
case 0x0c069554u: goto P_0c069554;
case 0x0c069556u: goto P_0c069556;
case 0x0c069558u: goto P_0c069558;
case 0x0c06955au: goto P_0c06955a;
case 0x0c06955cu: goto P_0c06955c;
case 0x0c06955eu: goto P_0c06955e;
case 0x0c069560u: goto P_0c069560;
case 0x0c069562u: goto P_0c069562;
case 0x0c069564u: goto P_0c069564;
case 0x0c069566u: goto P_0c069566;
case 0x0c069568u: goto P_0c069568;
case 0x0c06956au: goto P_0c06956a;
case 0x0c06956cu: goto P_0c06956c;
case 0x0c06956eu: goto P_0c06956e;
case 0x0c069570u: goto P_0c069570;
case 0x0c069572u: goto P_0c069572;
case 0x0c069574u: goto P_0c069574;
case 0x0c069576u: goto P_0c069576;
case 0x0c069578u: goto P_0c069578;
case 0x0c06957au: goto P_0c06957a;
case 0x0c06957cu: goto P_0c06957c;
case 0x0c06957eu: goto P_0c06957e;
case 0x0c069580u: goto P_0c069580;
case 0x0c069582u: goto P_0c069582;
case 0x0c069584u: goto P_0c069584;
case 0x0c069586u: goto P_0c069586;
case 0x0c069588u: goto P_0c069588;
case 0x0c06958au: goto P_0c06958a;
case 0x0c06958cu: goto P_0c06958c;
case 0x0c06958eu: goto P_0c06958e;
case 0x0c069590u: goto P_0c069590;
case 0x0c069592u: goto P_0c069592;
case 0x0c069594u: goto P_0c069594;
case 0x0c069596u: goto P_0c069596;
case 0x0c069598u: goto P_0c069598;
case 0x0c06959au: goto P_0c06959a;
case 0x0c06959cu: goto P_0c06959c;
case 0x0c06959eu: goto P_0c06959e;
case 0x0c0695a0u: goto P_0c0695a0;
case 0x0c0695a2u: goto P_0c0695a2;
case 0x0c0695a4u: goto P_0c0695a4;
case 0x0c0695a6u: goto P_0c0695a6;
case 0x0c0695a8u: goto P_0c0695a8;
case 0x0c0695aau: goto P_0c0695aa;
case 0x0c0695acu: goto P_0c0695ac;
case 0x0c0695aeu: goto P_0c0695ae;
case 0x0c0695b0u: goto P_0c0695b0;
case 0x0c0695b2u: goto P_0c0695b2;
case 0x0c0695b4u: goto P_0c0695b4;
case 0x0c0695b6u: goto P_0c0695b6;
case 0x0c0695b8u: goto P_0c0695b8;
case 0x0c0695bau: goto P_0c0695ba;
case 0x0c0695bcu: goto P_0c0695bc;
case 0x0c0695beu: goto P_0c0695be;
case 0x0c0695c0u: goto P_0c0695c0;
case 0x0c0695c2u: goto P_0c0695c2;
case 0x0c0695c4u: goto P_0c0695c4;
case 0x0c0695c6u: goto P_0c0695c6;
case 0x0c0695c8u: goto P_0c0695c8;
case 0x0c0695cau: goto P_0c0695ca;
case 0x0c0695ccu: goto P_0c0695cc;
case 0x0c0695ceu: goto P_0c0695ce;
case 0x0c0695d0u: goto P_0c0695d0;
case 0x0c0695d2u: goto P_0c0695d2;
case 0x0c0695d4u: goto P_0c0695d4;
case 0x0c0695d6u: goto P_0c0695d6;
case 0x0c0695d8u: goto P_0c0695d8;
case 0x0c0695dau: goto P_0c0695da;
case 0x0c0695dcu: goto P_0c0695dc;
case 0x0c0695deu: goto P_0c0695de;
case 0x0c0695e0u: goto P_0c0695e0;
case 0x0c0695e2u: goto P_0c0695e2;
case 0x0c0695e4u: goto P_0c0695e4;
case 0x0c0695e6u: goto P_0c0695e6;
case 0x0c0695e8u: goto P_0c0695e8;
case 0x0c0695eau: goto P_0c0695ea;
case 0x0c0695ecu: goto P_0c0695ec;
case 0x0c0695eeu: goto P_0c0695ee;
case 0x0c0695f0u: goto P_0c0695f0;
case 0x0c0695f2u: goto P_0c0695f2;
case 0x0c0695f4u: goto P_0c0695f4;
case 0x0c0695f6u: goto P_0c0695f6;
case 0x0c0695f8u: goto P_0c0695f8;
case 0x0c0695fau: goto P_0c0695fa;
case 0x0c0695fcu: goto P_0c0695fc;
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c06c5c8u: goto P_0c06c5c8;
case 0x0c06c5cau: goto P_0c06c5ca;
case 0x0c06c5ccu: goto P_0c06c5cc;
case 0x0c06c5ceu: goto P_0c06c5ce;
case 0x0c06c5d0u: goto P_0c06c5d0;
case 0x0c06c5d2u: goto P_0c06c5d2;
case 0x0c06c5d4u: goto P_0c06c5d4;
case 0x0c06c5d6u: goto P_0c06c5d6;
case 0x0c06c5d8u: goto P_0c06c5d8;
case 0x0c06c5dau: goto P_0c06c5da;
case 0x0c06c5dcu: goto P_0c06c5dc;
case 0x0c06c5deu: goto P_0c06c5de;
case 0x0c06c5e0u: goto P_0c06c5e0;
case 0x0c06c5e2u: goto P_0c06c5e2;
case 0x0c06c5e4u: goto P_0c06c5e4;
case 0x0c06c5e6u: goto P_0c06c5e6;
case 0x0c06c5e8u: goto P_0c06c5e8;
case 0x0c06c5eau: goto P_0c06c5ea;
case 0x0c06c5ecu: goto P_0c06c5ec;
case 0x0c06c5eeu: goto P_0c06c5ee;
case 0x0c06c5f0u: goto P_0c06c5f0;
case 0x0c06c5f2u: goto P_0c06c5f2;
case 0x0c06c5f4u: goto P_0c06c5f4;
case 0x0c06c5f6u: goto P_0c06c5f6;
case 0x0c06c5f8u: goto P_0c06c5f8;
case 0x0c06c5fau: goto P_0c06c5fa;
case 0x0c06c5fcu: goto P_0c06c5fc;
case 0x0c06c5feu: goto P_0c06c5fe;
case 0x0c06c600u: goto P_0c06c600;
case 0x0c06c602u: goto P_0c06c602;
case 0x0c06c604u: goto P_0c06c604;
case 0x0c06c606u: goto P_0c06c606;
case 0x0c06c608u: goto P_0c06c608;
case 0x0c06c60au: goto P_0c06c60a;
case 0x0c06c60cu: goto P_0c06c60c;
case 0x0c06c60eu: goto P_0c06c60e;
case 0x0c06c610u: goto P_0c06c610;
case 0x0c06c612u: goto P_0c06c612;
case 0x0c06c614u: goto P_0c06c614;
case 0x0c06c616u: goto P_0c06c616;
case 0x0c06c618u: goto P_0c06c618;
case 0x0c06c61au: goto P_0c06c61a;
case 0x0c06c61cu: goto P_0c06c61c;
case 0x0c06c61eu: goto P_0c06c61e;
case 0x0c06c620u: goto P_0c06c620;
case 0x0c06c622u: goto P_0c06c622;
case 0x0c06c624u: goto P_0c06c624;
case 0x0c06c626u: goto P_0c06c626;
case 0x0c06c628u: goto P_0c06c628;
case 0x0c06c62au: goto P_0c06c62a;
case 0x0c06c62cu: goto P_0c06c62c;
case 0x0c06c62eu: goto P_0c06c62e;
case 0x0c06c630u: goto P_0c06c630;
case 0x0c06c632u: goto P_0c06c632;
case 0x0c06c634u: goto P_0c06c634;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06951a: /* original 4f22, guest PC 0x0c06951a */
if(!s->budget--) { s->failed_pc=0x0c06951au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06951c;
P_0c06951c: /* original e004, guest PC 0x0c06951c */
if(!s->budget--) { s->failed_pc=0x0c06951cu; return 0; }
r[0]=0x00000004u;
goto P_0c06951e;
P_0c06951e: /* original e40f, guest PC 0x0c06951e */
if(!s->budget--) { s->failed_pc=0x0c06951eu; return 0; }
r[4]=0x0000000fu;
goto P_0c069520;
P_0c069520: /* original 7fdc, guest PC 0x0c069520 */
if(!s->budget--) { s->failed_pc=0x0c069520u; return 0; }
r[15]+=0xffffffdcu;
goto P_0c069522;
P_0c069522: /* original ff47, guest PC 0x0c069522 */
if(!s->budget--) { s->failed_pc=0x0c069522u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c069524;
P_0c069524: /* original ff5a, guest PC 0x0c069524 */
if(!s->budget--) { s->failed_pc=0x0c069524u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c069526;
P_0c069526: /* original d338, guest PC 0x0c069526 */
if(!s->budget--) { s->failed_pc=0x0c069526u; return 0; }
r[3]=read(ram,0x0c069608u,4);
goto P_0c069528;
P_0c069528: /* original d238, guest PC 0x0c069528 */
if(!s->budget--) { s->failed_pc=0x0c069528u; return 0; }
r[2]=read(ram,0x0c06960cu,4);
goto P_0c06952a;
P_0c06952a: /* original 6030, guest PC 0x0c06952a */
if(!s->budget--) { s->failed_pc=0x0c06952au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c06952c;
P_0c06952c: /* original 600c, guest PC 0x0c06952c */
if(!s->budget--) { s->failed_pc=0x0c06952cu; return 0; }
r[0]=r[0]&255u;
goto P_0c06952e;
P_0c06952e: /* original 2409, guest PC 0x0c06952e */
if(!s->budget--) { s->failed_pc=0x0c06952eu; return 0; }
r[4]&=r[0];
goto P_0c069530;
P_0c069530: /* original 6043, guest PC 0x0c069530 */
if(!s->budget--) { s->failed_pc=0x0c069530u; return 0; }
r[0]=r[4];
goto P_0c069532;
P_0c069532: /* original 8802, guest PC 0x0c069532 */
if(!s->budget--) { s->failed_pc=0x0c069532u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c069534;
P_0c069534: /* original 8d03, guest PC 0x0c069534 */
if(!s->budget--) { s->failed_pc=0x0c069534u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(cond) { goto P_0c06953e; }
goto P_0c069538;
P_0c069536: /* original 6522, guest PC 0x0c069536 */
if(!s->budget--) { s->failed_pc=0x0c069536u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c069538;
P_0c069538: /* original 6043, guest PC 0x0c069538 */
if(!s->budget--) { s->failed_pc=0x0c069538u; return 0; }
r[0]=r[4];
goto P_0c06953a;
P_0c06953a: /* original 8807, guest PC 0x0c06953a */
if(!s->budget--) { s->failed_pc=0x0c06953au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c06953c;
P_0c06953c: /* original 8b09, guest PC 0x0c06953c */
if(!s->budget--) { s->failed_pc=0x0c06953cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069552; }
goto P_0c06953e;
P_0c06953e: /* original c734, guest PC 0x0c06953e */
if(!s->budget--) { s->failed_pc=0x0c06953eu; return 0; }
r[0]=code_base|0x00069610u;
goto P_0c069540;
P_0c069540: /* original f408, guest PC 0x0c069540 */
if(!s->budget--) { s->failed_pc=0x0c069540u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069542;
P_0c069542: /* original e004, guest PC 0x0c069542 */
if(!s->budget--) { s->failed_pc=0x0c069542u; return 0; }
r[0]=0x00000004u;
goto P_0c069544;
P_0c069544: /* original f3f6, guest PC 0x0c069544 */
if(!s->budget--) { s->failed_pc=0x0c069544u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069546;
P_0c069546: /* original e004, guest PC 0x0c069546 */
if(!s->budget--) { s->failed_pc=0x0c069546u; return 0; }
r[0]=0x00000004u;
goto P_0c069548;
P_0c069548: /* original f342, guest PC 0x0c069548 */
if(!s->budget--) { s->failed_pc=0x0c069548u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06954a;
P_0c06954a: /* original ff37, guest PC 0x0c06954a */
if(!s->budget--) { s->failed_pc=0x0c06954au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06954c;
P_0c06954c: /* original f2f8, guest PC 0x0c06954c */
if(!s->budget--) { s->failed_pc=0x0c06954cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c06954e;
P_0c06954e: /* original f242, guest PC 0x0c06954e */
if(!s->budget--) { s->failed_pc=0x0c06954eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c069550;
P_0c069550: /* original ff2a, guest PC 0x0c069550 */
if(!s->budget--) { s->failed_pc=0x0c069550u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c069552;
P_0c069552: /* original 2558, guest PC 0x0c069552 */
if(!s->budget--) { s->failed_pc=0x0c069552u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c069554;
P_0c069554: /* original 8b08, guest PC 0x0c069554 */
if(!s->budget--) { s->failed_pc=0x0c069554u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069568; }
goto P_0c069556;
P_0c069556: /* original f5f8, guest PC 0x0c069556 */
if(!s->budget--) { s->failed_pc=0x0c069556u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c069558;
P_0c069558: /* original 64f3, guest PC 0x0c069558 */
if(!s->budget--) { s->failed_pc=0x0c069558u; return 0; }
r[4]=r[15];
goto P_0c06955a;
P_0c06955a: /* original e004, guest PC 0x0c06955a */
if(!s->budget--) { s->failed_pc=0x0c06955au; return 0; }
r[0]=0x00000004u;
goto P_0c06955c;
P_0c06955c: /* original 7418, guest PC 0x0c06955c */
if(!s->budget--) { s->failed_pc=0x0c06955cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06955e;
P_0c06955e: /* original bc41, guest PC 0x0c06955e */
if(!s->budget--) { s->failed_pc=0x0c06955eu; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c069562u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069562u) { target=s->pc; goto dispatch; }
goto P_0c069562;
P_0c069560: /* original f4f6, guest PC 0x0c069560 */
if(!s->budget--) { s->failed_pc=0x0c069560u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c069562;
P_0c069562: /* original e008, guest PC 0x0c069562 */
if(!s->budget--) { s->failed_pc=0x0c069562u; return 0; }
r[0]=0x00000008u;
goto P_0c069564;
P_0c069564: /* original a045, guest PC 0x0c069564 */
if(!s->budget--) { s->failed_pc=0x0c069564u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0695f2;
P_0c069566: /* original ff07, guest PC 0x0c069566 */
if(!s->budget--) { s->failed_pc=0x0c069566u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c069568;
P_0c069568: /* original c72a, guest PC 0x0c069568 */
if(!s->budget--) { s->failed_pc=0x0c069568u; return 0; }
r[0]=code_base|0x00069614u;
goto P_0c06956a;
P_0c06956a: /* original f408, guest PC 0x0c06956a */
if(!s->budget--) { s->failed_pc=0x0c06956au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06956c;
P_0c06956c: /* original e004, guest PC 0x0c06956c */
if(!s->budget--) { s->failed_pc=0x0c06956cu; return 0; }
r[0]=0x00000004u;
goto P_0c06956e;
P_0c06956e: /* original f3f6, guest PC 0x0c06956e */
if(!s->budget--) { s->failed_pc=0x0c06956eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069570;
P_0c069570: /* original f345, guest PC 0x0c069570 */
if(!s->budget--) { s->failed_pc=0x0c069570u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069572;
P_0c069572: /* original 8901, guest PC 0x0c069572 */
if(!s->budget--) { s->failed_pc=0x0c069572u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069578; }
goto P_0c069574;
P_0c069574: /* original e004, guest PC 0x0c069574 */
if(!s->budget--) { s->failed_pc=0x0c069574u; return 0; }
r[0]=0x00000004u;
goto P_0c069576;
P_0c069576: /* original ff47, guest PC 0x0c069576 */
if(!s->budget--) { s->failed_pc=0x0c069576u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c069578;
P_0c069578: /* original f3f8, guest PC 0x0c069578 */
if(!s->budget--) { s->failed_pc=0x0c069578u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c06957a;
P_0c06957a: /* original f345, guest PC 0x0c06957a */
if(!s->budget--) { s->failed_pc=0x0c06957au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06957c;
P_0c06957c: /* original 8900, guest PC 0x0c06957c */
if(!s->budget--) { s->failed_pc=0x0c06957cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069580; }
goto P_0c06957e;
P_0c06957e: /* original ff4a, guest PC 0x0c06957e */
if(!s->budget--) { s->failed_pc=0x0c06957eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c069580;
P_0c069580: /* original c725, guest PC 0x0c069580 */
if(!s->budget--) { s->failed_pc=0x0c069580u; return 0; }
r[0]=code_base|0x00069618u;
goto P_0c069582;
P_0c069582: /* original f408, guest PC 0x0c069582 */
if(!s->budget--) { s->failed_pc=0x0c069582u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069584;
P_0c069584: /* original e004, guest PC 0x0c069584 */
if(!s->budget--) { s->failed_pc=0x0c069584u; return 0; }
r[0]=0x00000004u;
goto P_0c069586;
P_0c069586: /* original f3f6, guest PC 0x0c069586 */
if(!s->budget--) { s->failed_pc=0x0c069586u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069588;
P_0c069588: /* original f435, guest PC 0x0c069588 */
if(!s->budget--) { s->failed_pc=0x0c069588u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c06958a;
P_0c06958a: /* original 8901, guest PC 0x0c06958a */
if(!s->budget--) { s->failed_pc=0x0c06958au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069590; }
goto P_0c06958c;
P_0c06958c: /* original e004, guest PC 0x0c06958c */
if(!s->budget--) { s->failed_pc=0x0c06958cu; return 0; }
r[0]=0x00000004u;
goto P_0c06958e;
P_0c06958e: /* original ff47, guest PC 0x0c06958e */
if(!s->budget--) { s->failed_pc=0x0c06958eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c069590;
P_0c069590: /* original f3f8, guest PC 0x0c069590 */
if(!s->budget--) { s->failed_pc=0x0c069590u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069592;
P_0c069592: /* original f435, guest PC 0x0c069592 */
if(!s->budget--) { s->failed_pc=0x0c069592u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c069594;
P_0c069594: /* original 8900, guest PC 0x0c069594 */
if(!s->budget--) { s->failed_pc=0x0c069594u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069598; }
goto P_0c069596;
P_0c069596: /* original ff4a, guest PC 0x0c069596 */
if(!s->budget--) { s->failed_pc=0x0c069596u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c069598;
P_0c069598: /* original c720, guest PC 0x0c069598 */
if(!s->budget--) { s->failed_pc=0x0c069598u; return 0; }
r[0]=code_base|0x0006961cu;
goto P_0c06959a;
P_0c06959a: /* original f508, guest PC 0x0c06959a */
if(!s->budget--) { s->failed_pc=0x0c06959au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06959c;
P_0c06959c: /* original c720, guest PC 0x0c06959c */
if(!s->budget--) { s->failed_pc=0x0c06959cu; return 0; }
r[0]=code_base|0x00069620u;
goto P_0c06959e;
P_0c06959e: /* original f408, guest PC 0x0c06959e */
if(!s->budget--) { s->failed_pc=0x0c06959eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0695a0;
P_0c0695a0: /* original e004, guest PC 0x0c0695a0 */
if(!s->budget--) { s->failed_pc=0x0c0695a0u; return 0; }
r[0]=0x00000004u;
goto P_0c0695a2;
P_0c0695a2: /* original f2f6, guest PC 0x0c0695a2 */
if(!s->budget--) { s->failed_pc=0x0c0695a2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0695a4;
P_0c0695a4: /* original e307, guest PC 0x0c0695a4 */
if(!s->budget--) { s->failed_pc=0x0c0695a4u; return 0; }
r[3]=0x00000007u;
goto P_0c0695a6;
P_0c0695a6: /* original f34c, guest PC 0x0c0695a6 */
if(!s->budget--) { s->failed_pc=0x0c0695a6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0695a8;
P_0c0695a8: /* original e00c, guest PC 0x0c0695a8 */
if(!s->budget--) { s->failed_pc=0x0c0695a8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0695aa;
P_0c0695aa: /* original f05c, guest PC 0x0c0695aa */
if(!s->budget--) { s->failed_pc=0x0c0695aau; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0695ac;
P_0c0695ac: /* original f32e, guest PC 0x0c0695ac */
if(!s->budget--) { s->failed_pc=0x0c0695acu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0695ae;
P_0c0695ae: /* original f33d, guest PC 0x0c0695ae */
if(!s->budget--) { s->failed_pc=0x0c0695aeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0695b0;
P_0c0695b0: /* original ff37, guest PC 0x0c0695b0 */
if(!s->budget--) { s->failed_pc=0x0c0695b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0695b2;
P_0c0695b2: /* original f2f8, guest PC 0x0c0695b2 */
if(!s->budget--) { s->failed_pc=0x0c0695b2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0695b4;
P_0c0695b4: /* original f42e, guest PC 0x0c0695b4 */
if(!s->budget--) { s->failed_pc=0x0c0695b4u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[2],fr[4],r[18]);
goto P_0c0695b6;
P_0c0695b6: /* original 065a, guest PC 0x0c0695b6 */
if(!s->budget--) { s->failed_pc=0x0c0695b6u; return 0; }
r[6]=r[53];
goto P_0c0695b8;
P_0c0695b8: /* original f43d, guest PC 0x0c0695b8 */
if(!s->budget--) { s->failed_pc=0x0c0695b8u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0695ba;
P_0c0695ba: /* original 075a, guest PC 0x0c0695ba */
if(!s->budget--) { s->failed_pc=0x0c0695bau; return 0; }
r[7]=r[53];
goto P_0c0695bc;
P_0c0695bc: /* original 473c, guest PC 0x0c0695bc */
if(!s->budget--) { s->failed_pc=0x0c0695bcu; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[7]>>((-r[3])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[3]&31u);
goto P_0c0695be;
P_0c0695be: /* original 367c, guest PC 0x0c0695be */
if(!s->budget--) { s->failed_pc=0x0c0695beu; return 0; }
r[6]+=r[7];
goto P_0c0695c0;
P_0c0695c0: /* original 6063, guest PC 0x0c0695c0 */
if(!s->budget--) { s->failed_pc=0x0c0695c0u; return 0; }
r[0]=r[6];
goto P_0c0695c2;
P_0c0695c2: /* original 4008, guest PC 0x0c0695c2 */
if(!s->budget--) { s->failed_pc=0x0c0695c2u; return 0; }
r[0]<<=2;
goto P_0c0695c4;
P_0c0695c4: /* original f356, guest PC 0x0c0695c4 */
if(!s->budget--) { s->failed_pc=0x0c0695c4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0695c6;
P_0c0695c6: /* original e008, guest PC 0x0c0695c6 */
if(!s->budget--) { s->failed_pc=0x0c0695c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0695c8;
P_0c0695c8: /* original ff37, guest PC 0x0c0695c8 */
if(!s->budget--) { s->failed_pc=0x0c0695c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0695ca;
P_0c0695ca: /* original 6043, guest PC 0x0c0695ca */
if(!s->budget--) { s->failed_pc=0x0c0695cau; return 0; }
r[0]=r[4];
goto P_0c0695cc;
P_0c0695cc: /* original 880b, guest PC 0x0c0695cc */
if(!s->budget--) { s->failed_pc=0x0c0695ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0695ce;
P_0c0695ce: /* original 8b10, guest PC 0x0c0695ce */
if(!s->budget--) { s->failed_pc=0x0c0695ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0695f2; }
goto P_0c0695d0;
P_0c0695d0: /* original 61f3, guest PC 0x0c0695d0 */
if(!s->budget--) { s->failed_pc=0x0c0695d0u; return 0; }
r[1]=r[15];
goto P_0c0695d2;
P_0c0695d2: /* original 710c, guest PC 0x0c0695d2 */
if(!s->budget--) { s->failed_pc=0x0c0695d2u; return 0; }
r[1]+=0x0000000cu;
goto P_0c0695d4;
P_0c0695d4: /* original 2f16, guest PC 0x0c0695d4 */
if(!s->budget--) { s->failed_pc=0x0c0695d4u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0695d6;
P_0c0695d6: /* original 62f3, guest PC 0x0c0695d6 */
if(!s->budget--) { s->failed_pc=0x0c0695d6u; return 0; }
r[2]=r[15];
goto P_0c0695d8;
P_0c0695d8: /* original 7218, guest PC 0x0c0695d8 */
if(!s->budget--) { s->failed_pc=0x0c0695d8u; return 0; }
r[2]+=0x00000018u;
goto P_0c0695da;
P_0c0695da: /* original 2f26, guest PC 0x0c0695da */
if(!s->budget--) { s->failed_pc=0x0c0695dau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0695dc;
P_0c0695dc: /* original 65f3, guest PC 0x0c0695dc */
if(!s->budget--) { s->failed_pc=0x0c0695dcu; return 0; }
r[5]=r[15];
goto P_0c0695de;
P_0c0695de: /* original d109, guest PC 0x0c0695de */
if(!s->budget--) { s->failed_pc=0x0c0695deu; return 0; }
r[1]=read(ram,0x0c069604u,4);
goto P_0c0695e0;
P_0c0695e0: /* original 66f3, guest PC 0x0c0695e0 */
if(!s->budget--) { s->failed_pc=0x0c0695e0u; return 0; }
r[6]=r[15];
goto P_0c0695e2;
P_0c0695e2: /* original 67f3, guest PC 0x0c0695e2 */
if(!s->budget--) { s->failed_pc=0x0c0695e2u; return 0; }
r[7]=r[15];
goto P_0c0695e4;
P_0c0695e4: /* original 64f3, guest PC 0x0c0695e4 */
if(!s->budget--) { s->failed_pc=0x0c0695e4u; return 0; }
r[4]=r[15];
goto P_0c0695e6;
P_0c0695e6: /* original 7510, guest PC 0x0c0695e6 */
if(!s->budget--) { s->failed_pc=0x0c0695e6u; return 0; }
r[5]+=0x00000010u;
goto P_0c0695e8;
P_0c0695e8: /* original 7608, guest PC 0x0c0695e8 */
if(!s->budget--) { s->failed_pc=0x0c0695e8u; return 0; }
r[6]+=0x00000008u;
goto P_0c0695ea;
P_0c0695ea: /* original 7718, guest PC 0x0c0695ea */
if(!s->budget--) { s->failed_pc=0x0c0695eau; return 0; }
r[7]+=0x00000018u;
goto P_0c0695ec;
P_0c0695ec: /* original 410b, guest PC 0x0c0695ec */
if(!s->budget--) { s->failed_pc=0x0c0695ecu; return 0; }
target=r[1];
r[16]=code_base|0x0c0695f0u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0695f0u) { target=s->pc; goto dispatch; }
goto P_0c0695f0;
P_0c0695ee: /* original 740c, guest PC 0x0c0695ee */
if(!s->budget--) { s->failed_pc=0x0c0695eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0695f0;
P_0c0695f0: /* original 7f08, guest PC 0x0c0695f0 */
if(!s->budget--) { s->failed_pc=0x0c0695f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0695f2;
P_0c0695f2: /* original e008, guest PC 0x0c0695f2 */
if(!s->budget--) { s->failed_pc=0x0c0695f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0695f4;
P_0c0695f4: /* original f0f6, guest PC 0x0c0695f4 */
if(!s->budget--) { s->failed_pc=0x0c0695f4u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0695f6;
P_0c0695f6: /* original 7f24, guest PC 0x0c0695f6 */
if(!s->budget--) { s->failed_pc=0x0c0695f6u; return 0; }
r[15]+=0x00000024u;
goto P_0c0695f8;
P_0c0695f8: /* original 4f26, guest PC 0x0c0695f8 */
if(!s->budget--) { s->failed_pc=0x0c0695f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0695fa;
P_0c0695fa: /* original 000b, guest PC 0x0c0695fa */
if(!s->budget--) { s->failed_pc=0x0c0695fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0695fc: /* original 0009, guest PC 0x0c0695fc */
if(!s->budget--) { s->failed_pc=0x0c0695fcu; return 0; }
if(!vf3_matrix_family(0x0c0695feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0695feu; return 0; } return 1;
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=code_base|0x000696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
if(!vf3_matrix_family(0x0c06969eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06969eu; return 0; } return 1;
P_0c06c5c8: /* original 2fe6, guest PC 0x0c06c5c8 */
if(!s->budget--) { s->failed_pc=0x0c06c5c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c5ca;
P_0c06c5ca: /* original d346, guest PC 0x0c06c5ca */
if(!s->budget--) { s->failed_pc=0x0c06c5cau; return 0; }
r[3]=read(ram,0x0c06c6e4u,4);
goto P_0c06c5cc;
P_0c06c5cc: /* original d246, guest PC 0x0c06c5cc */
if(!s->budget--) { s->failed_pc=0x0c06c5ccu; return 0; }
r[2]=read(ram,0x0c06c6e8u,4);
goto P_0c06c5ce;
P_0c06c5ce: /* original 6530, guest PC 0x0c06c5ce */
if(!s->budget--) { s->failed_pc=0x0c06c5ceu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c06c5d0;
P_0c06c5d0: /* original 4f22, guest PC 0x0c06c5d0 */
if(!s->budget--) { s->failed_pc=0x0c06c5d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c5d2;
P_0c06c5d2: /* original 6422, guest PC 0x0c06c5d2 */
if(!s->budget--) { s->failed_pc=0x0c06c5d2u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c5d4;
P_0c06c5d4: /* original 655c, guest PC 0x0c06c5d4 */
if(!s->budget--) { s->failed_pc=0x0c06c5d4u; return 0; }
r[5]=r[5]&255u;
goto P_0c06c5d6;
P_0c06c5d6: /* original de42, guest PC 0x0c06c5d6 */
if(!s->budget--) { s->failed_pc=0x0c06c5d6u; return 0; }
r[14]=read(ram,0x0c06c6e0u,4);
goto P_0c06c5d8;
P_0c06c5d8: /* original 2558, guest PC 0x0c06c5d8 */
if(!s->budget--) { s->failed_pc=0x0c06c5d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c5da;
P_0c06c5da: /* original 8d0f, guest PC 0x0c06c5da */
if(!s->budget--) { s->failed_pc=0x0c06c5dau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06c5fc; }
goto P_0c06c5de;
P_0c06c5dc: /* original 7401, guest PC 0x0c06c5dc */
if(!s->budget--) { s->failed_pc=0x0c06c5dcu; return 0; }
r[4]+=0x00000001u;
goto P_0c06c5de;
P_0c06c5de: /* original 6053, guest PC 0x0c06c5de */
if(!s->budget--) { s->failed_pc=0x0c06c5deu; return 0; }
r[0]=r[5];
goto P_0c06c5e0;
P_0c06c5e0: /* original 8801, guest PC 0x0c06c5e0 */
if(!s->budget--) { s->failed_pc=0x0c06c5e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c5e2;
P_0c06c5e2: /* original 8b05, guest PC 0x0c06c5e2 */
if(!s->budget--) { s->failed_pc=0x0c06c5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c5f0; }
goto P_0c06c5e4;
P_0c06c5e4: /* original 4f26, guest PC 0x0c06c5e4 */
if(!s->budget--) { s->failed_pc=0x0c06c5e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5e6;
P_0c06c5e6: /* original 6543, guest PC 0x0c06c5e6 */
if(!s->budget--) { s->failed_pc=0x0c06c5e6u; return 0; }
r[5]=r[4];
goto P_0c06c5e8;
P_0c06c5e8: /* original e404, guest PC 0x0c06c5e8 */
if(!s->budget--) { s->failed_pc=0x0c06c5e8u; return 0; }
r[4]=0x00000004u;
goto P_0c06c5ea;
P_0c06c5ea: /* original e627, guest PC 0x0c06c5ea */
if(!s->budget--) { s->failed_pc=0x0c06c5eau; return 0; }
r[6]=0x00000027u;
goto P_0c06c5ec;
P_0c06c5ec: /* original a023, guest PC 0x0c06c5ec */
if(!s->budget--) { s->failed_pc=0x0c06c5ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
P_0c06c5ee: /* original 6ef6, guest PC 0x0c06c5ee */
if(!s->budget--) { s->failed_pc=0x0c06c5eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5f0;
P_0c06c5f0: /* original 4f26, guest PC 0x0c06c5f0 */
if(!s->budget--) { s->failed_pc=0x0c06c5f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5f2;
P_0c06c5f2: /* original 6543, guest PC 0x0c06c5f2 */
if(!s->budget--) { s->failed_pc=0x0c06c5f2u; return 0; }
r[5]=r[4];
goto P_0c06c5f4;
P_0c06c5f4: /* original e427, guest PC 0x0c06c5f4 */
if(!s->budget--) { s->failed_pc=0x0c06c5f4u; return 0; }
r[4]=0x00000027u;
goto P_0c06c5f6;
P_0c06c5f6: /* original e604, guest PC 0x0c06c5f6 */
if(!s->budget--) { s->failed_pc=0x0c06c5f6u; return 0; }
r[6]=0x00000004u;
goto P_0c06c5f8;
P_0c06c5f8: /* original a01d, guest PC 0x0c06c5f8 */
if(!s->budget--) { s->failed_pc=0x0c06c5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
P_0c06c5fa: /* original 6ef6, guest PC 0x0c06c5fa */
if(!s->budget--) { s->failed_pc=0x0c06c5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5fc;
P_0c06c5fc: /* original e307, guest PC 0x0c06c5fc */
if(!s->budget--) { s->failed_pc=0x0c06c5fcu; return 0; }
r[3]=0x00000007u;
goto P_0c06c5fe;
P_0c06c5fe: /* original e220, guest PC 0x0c06c5fe */
if(!s->budget--) { s->failed_pc=0x0c06c5feu; return 0; }
r[2]=0x00000020u;
goto P_0c06c600;
P_0c06c600: /* original e508, guest PC 0x0c06c600 */
if(!s->budget--) { s->failed_pc=0x0c06c600u; return 0; }
r[5]=0x00000008u;
goto P_0c06c602;
P_0c06c602: /* original 2f26, guest PC 0x0c06c602 */
if(!s->budget--) { s->failed_pc=0x0c06c602u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c604;
P_0c06c604: /* original d139, guest PC 0x0c06c604 */
if(!s->budget--) { s->failed_pc=0x0c06c604u; return 0; }
r[1]=read(ram,0x0c06c6ecu,4);
goto P_0c06c606;
P_0c06c606: /* original 443c, guest PC 0x0c06c606 */
if(!s->budget--) { s->failed_pc=0x0c06c606u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06c608;
P_0c06c608: /* original e615, guest PC 0x0c06c608 */
if(!s->budget--) { s->failed_pc=0x0c06c608u; return 0; }
r[6]=0x00000015u;
goto P_0c06c60a;
P_0c06c60a: /* original e701, guest PC 0x0c06c60a */
if(!s->budget--) { s->failed_pc=0x0c06c60au; return 0; }
r[7]=0x00000001u;
goto P_0c06c60c;
P_0c06c60c: /* original 254b, guest PC 0x0c06c60c */
if(!s->budget--) { s->failed_pc=0x0c06c60cu; return 0; }
r[5]|=r[4];
goto P_0c06c60e;
P_0c06c60e: /* original 410b, guest PC 0x0c06c60e */
if(!s->budget--) { s->failed_pc=0x0c06c60eu; return 0; }
target=r[1];
r[16]=code_base|0x0c06c612u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c612u) { target=s->pc; goto dispatch; }
goto P_0c06c612;
P_0c06c610: /* original 64e3, guest PC 0x0c06c610 */
if(!s->budget--) { s->failed_pc=0x0c06c610u; return 0; }
r[4]=r[14];
goto P_0c06c612;
P_0c06c612: /* original d335, guest PC 0x0c06c612 */
if(!s->budget--) { s->failed_pc=0x0c06c612u; return 0; }
r[3]=read(ram,0x0c06c6e8u,4);
goto P_0c06c614;
P_0c06c614: /* original e207, guest PC 0x0c06c614 */
if(!s->budget--) { s->failed_pc=0x0c06c614u; return 0; }
r[2]=0x00000007u;
goto P_0c06c616;
P_0c06c616: /* original e120, guest PC 0x0c06c616 */
if(!s->budget--) { s->failed_pc=0x0c06c616u; return 0; }
r[1]=0x00000020u;
goto P_0c06c618;
P_0c06c618: /* original 6032, guest PC 0x0c06c618 */
if(!s->budget--) { s->failed_pc=0x0c06c618u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c61a;
P_0c06c61a: /* original e54e, guest PC 0x0c06c61a */
if(!s->budget--) { s->failed_pc=0x0c06c61au; return 0; }
r[5]=0x0000004eu;
goto P_0c06c61c;
P_0c06c61c: /* original e615, guest PC 0x0c06c61c */
if(!s->budget--) { s->failed_pc=0x0c06c61cu; return 0; }
r[6]=0x00000015u;
goto P_0c06c61e;
P_0c06c61e: /* original 2f16, guest PC 0x0c06c61e */
if(!s->budget--) { s->failed_pc=0x0c06c61eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c620;
P_0c06c620: /* original 7001, guest PC 0x0c06c620 */
if(!s->budget--) { s->failed_pc=0x0c06c620u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c622;
P_0c06c622: /* original d332, guest PC 0x0c06c622 */
if(!s->budget--) { s->failed_pc=0x0c06c622u; return 0; }
r[3]=read(ram,0x0c06c6ecu,4);
goto P_0c06c624;
P_0c06c624: /* original 402c, guest PC 0x0c06c624 */
if(!s->budget--) { s->failed_pc=0x0c06c624u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c06c626;
P_0c06c626: /* original e701, guest PC 0x0c06c626 */
if(!s->budget--) { s->failed_pc=0x0c06c626u; return 0; }
r[7]=0x00000001u;
goto P_0c06c628;
P_0c06c628: /* original 250b, guest PC 0x0c06c628 */
if(!s->budget--) { s->failed_pc=0x0c06c628u; return 0; }
r[5]|=r[0];
goto P_0c06c62a;
P_0c06c62a: /* original 430b, guest PC 0x0c06c62a */
if(!s->budget--) { s->failed_pc=0x0c06c62au; return 0; }
target=r[3];
r[16]=code_base|0x0c06c62eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c62eu) { target=s->pc; goto dispatch; }
goto P_0c06c62e;
P_0c06c62c: /* original 64e3, guest PC 0x0c06c62c */
if(!s->budget--) { s->failed_pc=0x0c06c62cu; return 0; }
r[4]=r[14];
goto P_0c06c62e;
P_0c06c62e: /* original 7f08, guest PC 0x0c06c62e */
if(!s->budget--) { s->failed_pc=0x0c06c62eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c630;
P_0c06c630: /* original 4f26, guest PC 0x0c06c630 */
if(!s->budget--) { s->failed_pc=0x0c06c630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c632;
P_0c06c632: /* original 000b, guest PC 0x0c06c632 */
if(!s->budget--) { s->failed_pc=0x0c06c632u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c634: /* original 6ef6, guest PC 0x0c06c634 */
if(!s->budget--) { s->failed_pc=0x0c06c634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c636u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
