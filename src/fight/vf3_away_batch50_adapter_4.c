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
int vf3_away_batch50_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c084434u: goto P_0c084434;
case 0x0c084436u: goto P_0c084436;
case 0x0c084438u: goto P_0c084438;
case 0x0c08443au: goto P_0c08443a;
case 0x0c08443cu: goto P_0c08443c;
case 0x0c08443eu: goto P_0c08443e;
case 0x0c084440u: goto P_0c084440;
case 0x0c084442u: goto P_0c084442;
case 0x0c084444u: goto P_0c084444;
case 0x0c084446u: goto P_0c084446;
case 0x0c084448u: goto P_0c084448;
case 0x0c08444au: goto P_0c08444a;
case 0x0c08444cu: goto P_0c08444c;
case 0x0c08444eu: goto P_0c08444e;
case 0x0c084450u: goto P_0c084450;
case 0x0c084452u: goto P_0c084452;
case 0x0c084454u: goto P_0c084454;
case 0x0c084456u: goto P_0c084456;
case 0x0c084458u: goto P_0c084458;
case 0x0c08445au: goto P_0c08445a;
case 0x0c08445cu: goto P_0c08445c;
case 0x0c08445eu: goto P_0c08445e;
case 0x0c084460u: goto P_0c084460;
case 0x0c084462u: goto P_0c084462;
case 0x0c084464u: goto P_0c084464;
case 0x0c084466u: goto P_0c084466;
case 0x0c084468u: goto P_0c084468;
case 0x0c08446au: goto P_0c08446a;
case 0x0c08446cu: goto P_0c08446c;
case 0x0c08446eu: goto P_0c08446e;
case 0x0c084470u: goto P_0c084470;
case 0x0c084472u: goto P_0c084472;
case 0x0c084474u: goto P_0c084474;
case 0x0c084476u: goto P_0c084476;
case 0x0c084478u: goto P_0c084478;
case 0x0c08447au: goto P_0c08447a;
case 0x0c08447cu: goto P_0c08447c;
case 0x0c08447eu: goto P_0c08447e;
case 0x0c084480u: goto P_0c084480;
case 0x0c084482u: goto P_0c084482;
case 0x0c084484u: goto P_0c084484;
case 0x0c084486u: goto P_0c084486;
case 0x0c084488u: goto P_0c084488;
case 0x0c08448au: goto P_0c08448a;
case 0x0c08448cu: goto P_0c08448c;
case 0x0c08448eu: goto P_0c08448e;
case 0x0c084490u: goto P_0c084490;
case 0x0c084492u: goto P_0c084492;
case 0x0c084494u: goto P_0c084494;
case 0x0c084496u: goto P_0c084496;
case 0x0c084498u: goto P_0c084498;
case 0x0c08449au: goto P_0c08449a;
case 0x0c08449cu: goto P_0c08449c;
case 0x0c08449eu: goto P_0c08449e;
case 0x0c0844a0u: goto P_0c0844a0;
case 0x0c0844a2u: goto P_0c0844a2;
case 0x0c0844a4u: goto P_0c0844a4;
case 0x0c0844a6u: goto P_0c0844a6;
case 0x0c0844a8u: goto P_0c0844a8;
case 0x0c0844aau: goto P_0c0844aa;
case 0x0c0844acu: goto P_0c0844ac;
case 0x0c0844aeu: goto P_0c0844ae;
case 0x0c0844b0u: goto P_0c0844b0;
case 0x0c0844b2u: goto P_0c0844b2;
case 0x0c0844b4u: goto P_0c0844b4;
case 0x0c0844b6u: goto P_0c0844b6;
case 0x0c0844b8u: goto P_0c0844b8;
case 0x0c0844bau: goto P_0c0844ba;
case 0x0c0844bcu: goto P_0c0844bc;
case 0x0c0844beu: goto P_0c0844be;
case 0x0c0844c0u: goto P_0c0844c0;
case 0x0c0844c2u: goto P_0c0844c2;
case 0x0c0844c4u: goto P_0c0844c4;
case 0x0c0844c6u: goto P_0c0844c6;
case 0x0c0844c8u: goto P_0c0844c8;
case 0x0c0844cau: goto P_0c0844ca;
case 0x0c0844ccu: goto P_0c0844cc;
case 0x0c0844ceu: goto P_0c0844ce;
case 0x0c0844d0u: goto P_0c0844d0;
case 0x0c0844d2u: goto P_0c0844d2;
case 0x0c0844d4u: goto P_0c0844d4;
case 0x0c0844d6u: goto P_0c0844d6;
case 0x0c0844d8u: goto P_0c0844d8;
case 0x0c0844dau: goto P_0c0844da;
case 0x0c0844dcu: goto P_0c0844dc;
case 0x0c0844deu: goto P_0c0844de;
case 0x0c0844e0u: goto P_0c0844e0;
case 0x0c0844e2u: goto P_0c0844e2;
case 0x0c0844e4u: goto P_0c0844e4;
case 0x0c0844e6u: goto P_0c0844e6;
case 0x0c0844e8u: goto P_0c0844e8;
case 0x0c0844eau: goto P_0c0844ea;
case 0x0c0844ecu: goto P_0c0844ec;
case 0x0c0844eeu: goto P_0c0844ee;
case 0x0c0844f0u: goto P_0c0844f0;
case 0x0c0844f2u: goto P_0c0844f2;
case 0x0c0844f4u: goto P_0c0844f4;
case 0x0c0844f6u: goto P_0c0844f6;
case 0x0c0844f8u: goto P_0c0844f8;
case 0x0c0844fau: goto P_0c0844fa;
case 0x0c0844fcu: goto P_0c0844fc;
case 0x0c0844feu: goto P_0c0844fe;
case 0x0c084500u: goto P_0c084500;
case 0x0c084502u: goto P_0c084502;
case 0x0c084504u: goto P_0c084504;
case 0x0c084506u: goto P_0c084506;
case 0x0c084508u: goto P_0c084508;
case 0x0c08450au: goto P_0c08450a;
case 0x0c08450cu: goto P_0c08450c;
case 0x0c08450eu: goto P_0c08450e;
case 0x0c084510u: goto P_0c084510;
case 0x0c084512u: goto P_0c084512;
case 0x0c084514u: goto P_0c084514;
case 0x0c084516u: goto P_0c084516;
case 0x0c084518u: goto P_0c084518;
case 0x0c08451au: goto P_0c08451a;
case 0x0c08451cu: goto P_0c08451c;
case 0x0c08451eu: goto P_0c08451e;
case 0x0c084520u: goto P_0c084520;
case 0x0c084522u: goto P_0c084522;
case 0x0c084524u: goto P_0c084524;
case 0x0c084526u: goto P_0c084526;
case 0x0c084528u: goto P_0c084528;
case 0x0c08452au: goto P_0c08452a;
case 0x0c08452cu: goto P_0c08452c;
case 0x0c08452eu: goto P_0c08452e;
case 0x0c084530u: goto P_0c084530;
case 0x0c084532u: goto P_0c084532;
case 0x0c084534u: goto P_0c084534;
case 0x0c084536u: goto P_0c084536;
case 0x0c084538u: goto P_0c084538;
case 0x0c08453au: goto P_0c08453a;
case 0x0c08453cu: goto P_0c08453c;
case 0x0c08453eu: goto P_0c08453e;
case 0x0c084568u: goto P_0c084568;
case 0x0c08456au: goto P_0c08456a;
case 0x0c08456cu: goto P_0c08456c;
case 0x0c08456eu: goto P_0c08456e;
case 0x0c084570u: goto P_0c084570;
case 0x0c084572u: goto P_0c084572;
case 0x0c084574u: goto P_0c084574;
case 0x0c084576u: goto P_0c084576;
case 0x0c084578u: goto P_0c084578;
case 0x0c08457au: goto P_0c08457a;
case 0x0c08457cu: goto P_0c08457c;
case 0x0c08457eu: goto P_0c08457e;
case 0x0c084580u: goto P_0c084580;
case 0x0c084582u: goto P_0c084582;
case 0x0c084584u: goto P_0c084584;
case 0x0c084586u: goto P_0c084586;
case 0x0c084588u: goto P_0c084588;
case 0x0c08458au: goto P_0c08458a;
case 0x0c08458cu: goto P_0c08458c;
case 0x0c08458eu: goto P_0c08458e;
case 0x0c084590u: goto P_0c084590;
case 0x0c084592u: goto P_0c084592;
case 0x0c084594u: goto P_0c084594;
case 0x0c084596u: goto P_0c084596;
case 0x0c084598u: goto P_0c084598;
case 0x0c08459au: goto P_0c08459a;
case 0x0c08459cu: goto P_0c08459c;
case 0x0c08459eu: goto P_0c08459e;
case 0x0c0845a0u: goto P_0c0845a0;
case 0x0c0845a2u: goto P_0c0845a2;
case 0x0c0845a4u: goto P_0c0845a4;
case 0x0c0845a6u: goto P_0c0845a6;
case 0x0c0845a8u: goto P_0c0845a8;
case 0x0c0845aau: goto P_0c0845aa;
case 0x0c0845acu: goto P_0c0845ac;
case 0x0c0845aeu: goto P_0c0845ae;
case 0x0c0845b0u: goto P_0c0845b0;
case 0x0c0845b2u: goto P_0c0845b2;
case 0x0c0845b4u: goto P_0c0845b4;
case 0x0c0845b6u: goto P_0c0845b6;
case 0x0c0845b8u: goto P_0c0845b8;
case 0x0c0845bau: goto P_0c0845ba;
case 0x0c0845bcu: goto P_0c0845bc;
case 0x0c0845beu: goto P_0c0845be;
case 0x0c0845c0u: goto P_0c0845c0;
case 0x0c0845c2u: goto P_0c0845c2;
case 0x0c0845c4u: goto P_0c0845c4;
case 0x0c0845c6u: goto P_0c0845c6;
case 0x0c0845c8u: goto P_0c0845c8;
case 0x0c0845cau: goto P_0c0845ca;
case 0x0c0845ccu: goto P_0c0845cc;
case 0x0c0845ceu: goto P_0c0845ce;
case 0x0c0845d0u: goto P_0c0845d0;
case 0x0c0845d2u: goto P_0c0845d2;
case 0x0c0845d4u: goto P_0c0845d4;
case 0x0c0845d6u: goto P_0c0845d6;
case 0x0c0845d8u: goto P_0c0845d8;
case 0x0c0845dau: goto P_0c0845da;
case 0x0c0845dcu: goto P_0c0845dc;
case 0x0c0845deu: goto P_0c0845de;
case 0x0c0845e0u: goto P_0c0845e0;
case 0x0c0845e2u: goto P_0c0845e2;
case 0x0c0845e4u: goto P_0c0845e4;
case 0x0c0845e6u: goto P_0c0845e6;
case 0x0c0845e8u: goto P_0c0845e8;
case 0x0c0845eau: goto P_0c0845ea;
case 0x0c0845ecu: goto P_0c0845ec;
case 0x0c0845eeu: goto P_0c0845ee;
case 0x0c0845f0u: goto P_0c0845f0;
case 0x0c0845f2u: goto P_0c0845f2;
case 0x0c0845f4u: goto P_0c0845f4;
case 0x0c0845f6u: goto P_0c0845f6;
case 0x0c0845f8u: goto P_0c0845f8;
case 0x0c0845fau: goto P_0c0845fa;
case 0x0c0845fcu: goto P_0c0845fc;
case 0x0c0845feu: goto P_0c0845fe;
case 0x0c084600u: goto P_0c084600;
case 0x0c084602u: goto P_0c084602;
case 0x0c084604u: goto P_0c084604;
case 0x0c084606u: goto P_0c084606;
case 0x0c084608u: goto P_0c084608;
case 0x0c08460au: goto P_0c08460a;
case 0x0c08460cu: goto P_0c08460c;
case 0x0c08460eu: goto P_0c08460e;
case 0x0c084610u: goto P_0c084610;
case 0x0c084612u: goto P_0c084612;
case 0x0c084614u: goto P_0c084614;
case 0x0c084616u: goto P_0c084616;
case 0x0c084618u: goto P_0c084618;
case 0x0c08461au: goto P_0c08461a;
case 0x0c08461cu: goto P_0c08461c;
case 0x0c08461eu: goto P_0c08461e;
case 0x0c084620u: goto P_0c084620;
case 0x0c084622u: goto P_0c084622;
case 0x0c084624u: goto P_0c084624;
case 0x0c084626u: goto P_0c084626;
case 0x0c084628u: goto P_0c084628;
case 0x0c08462au: goto P_0c08462a;
case 0x0c08462cu: goto P_0c08462c;
case 0x0c08462eu: goto P_0c08462e;
case 0x0c084630u: goto P_0c084630;
case 0x0c084632u: goto P_0c084632;
case 0x0c084634u: goto P_0c084634;
case 0x0c084636u: goto P_0c084636;
case 0x0c084638u: goto P_0c084638;
case 0x0c08463au: goto P_0c08463a;
case 0x0c08463cu: goto P_0c08463c;
case 0x0c08463eu: goto P_0c08463e;
case 0x0c084640u: goto P_0c084640;
case 0x0c084642u: goto P_0c084642;
case 0x0c084644u: goto P_0c084644;
case 0x0c084646u: goto P_0c084646;
case 0x0c084648u: goto P_0c084648;
case 0x0c08464au: goto P_0c08464a;
case 0x0c08464cu: goto P_0c08464c;
case 0x0c08464eu: goto P_0c08464e;
case 0x0c084650u: goto P_0c084650;
case 0x0c084652u: goto P_0c084652;
case 0x0c084654u: goto P_0c084654;
case 0x0c084656u: goto P_0c084656;
case 0x0c084658u: goto P_0c084658;
case 0x0c08465au: goto P_0c08465a;
case 0x0c08465cu: goto P_0c08465c;
case 0x0c08465eu: goto P_0c08465e;
case 0x0c084660u: goto P_0c084660;
case 0x0c084662u: goto P_0c084662;
case 0x0c084664u: goto P_0c084664;
case 0x0c084666u: goto P_0c084666;
case 0x0c084668u: goto P_0c084668;
default: return vf3_matrix_family(target,s,ram);
}
P_0c084434: /* original 2fe6, guest PC 0x0c084434 */
if(!s->budget--) { s->failed_pc=0x0c084434u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084436;
P_0c084436: /* original 6e43, guest PC 0x0c084436 */
if(!s->budget--) { s->failed_pc=0x0c084436u; return 0; }
r[14]=r[4];
goto P_0c084438;
P_0c084438: /* original 2fd6, guest PC 0x0c084438 */
if(!s->budget--) { s->failed_pc=0x0c084438u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08443a;
P_0c08443a: /* original e40f, guest PC 0x0c08443a */
if(!s->budget--) { s->failed_pc=0x0c08443au; return 0; }
r[4]=0x0000000fu;
goto P_0c08443c;
P_0c08443c: /* original 2fc6, guest PC 0x0c08443c */
if(!s->budget--) { s->failed_pc=0x0c08443cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08443e;
P_0c08443e: /* original 2fb6, guest PC 0x0c08443e */
if(!s->budget--) { s->failed_pc=0x0c08443eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084440;
P_0c084440: /* original 2fa6, guest PC 0x0c084440 */
if(!s->budget--) { s->failed_pc=0x0c084440u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084442;
P_0c084442: /* original 2f96, guest PC 0x0c084442 */
if(!s->budget--) { s->failed_pc=0x0c084442u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084444;
P_0c084444: /* original 2f86, guest PC 0x0c084444 */
if(!s->budget--) { s->failed_pc=0x0c084444u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084446;
P_0c084446: /* original fffb, guest PC 0x0c084446 */
if(!s->budget--) { s->failed_pc=0x0c084446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084448;
P_0c084448: /* original ffeb, guest PC 0x0c084448 */
if(!s->budget--) { s->failed_pc=0x0c084448u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08444a;
P_0c08444a: /* original 4f22, guest PC 0x0c08444a */
if(!s->budget--) { s->failed_pc=0x0c08444au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08444c;
P_0c08444c: /* original 7ff0, guest PC 0x0c08444c */
if(!s->budget--) { s->failed_pc=0x0c08444cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08444e;
P_0c08444e: /* original 2f52, guest PC 0x0c08444e */
if(!s->budget--) { s->failed_pc=0x0c08444eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c084450;
P_0c084450: /* original d33c, guest PC 0x0c084450 */
if(!s->budget--) { s->failed_pc=0x0c084450u; return 0; }
r[3]=read(ram,0x0c084544u,4);
goto P_0c084452;
P_0c084452: /* original db3d, guest PC 0x0c084452 */
if(!s->budget--) { s->failed_pc=0x0c084452u; return 0; }
r[11]=read(ram,0x0c084548u,4);
goto P_0c084454;
P_0c084454: /* original 6030, guest PC 0x0c084454 */
if(!s->budget--) { s->failed_pc=0x0c084454u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c084456;
P_0c084456: /* original 600c, guest PC 0x0c084456 */
if(!s->budget--) { s->failed_pc=0x0c084456u; return 0; }
r[0]=r[0]&255u;
goto P_0c084458;
P_0c084458: /* original 2409, guest PC 0x0c084458 */
if(!s->budget--) { s->failed_pc=0x0c084458u; return 0; }
r[4]&=r[0];
goto P_0c08445a;
P_0c08445a: /* original 604f, guest PC 0x0c08445a */
if(!s->budget--) { s->failed_pc=0x0c08445au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08445c;
P_0c08445c: /* original 8801, guest PC 0x0c08445c */
if(!s->budget--) { s->failed_pc=0x0c08445cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08445e;
P_0c08445e: /* original 8f03, guest PC 0x0c08445e */
if(!s->budget--) { s->failed_pc=0x0c08445eu; return 0; }
cond=r[17]&1u;
r[10]=0x0000000eu;
if(!cond) { goto P_0c084468; }
goto P_0c084462;
P_0c084460: /* original ea0e, guest PC 0x0c084460 */
if(!s->budget--) { s->failed_pc=0x0c084460u; return 0; }
r[10]=0x0000000eu;
goto P_0c084462;
P_0c084462: /* original e100, guest PC 0x0c084462 */
if(!s->budget--) { s->failed_pc=0x0c084462u; return 0; }
r[1]=0x00000000u;
goto P_0c084464;
P_0c084464: /* original a002, guest PC 0x0c084464 */
if(!s->budget--) { s->failed_pc=0x0c084464u; return 0; }
write(ram,r[11],r[1],2);
goto P_0c08446c;
P_0c084466: /* original 2b11, guest PC 0x0c084466 */
if(!s->budget--) { s->failed_pc=0x0c084466u; return 0; }
write(ram,r[11],r[1],2);
goto P_0c084468;
P_0c084468: /* original e001, guest PC 0x0c084468 */
if(!s->budget--) { s->failed_pc=0x0c084468u; return 0; }
r[0]=0x00000001u;
goto P_0c08446a;
P_0c08446a: /* original 2b01, guest PC 0x0c08446a */
if(!s->budget--) { s->failed_pc=0x0c08446au; return 0; }
write(ram,r[11],r[0],2);
goto P_0c08446c;
P_0c08446c: /* original d337, guest PC 0x0c08446c */
if(!s->budget--) { s->failed_pc=0x0c08446cu; return 0; }
r[3]=read(ram,0x0c08454cu,4);
goto P_0c08446e;
P_0c08446e: /* original 430b, guest PC 0x0c08446e */
if(!s->budget--) { s->failed_pc=0x0c08446eu; return 0; }
target=r[3];
r[16]=code_base|0x0c084472u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084472u) { target=s->pc; goto dispatch; }
goto P_0c084472;
P_0c084470: /* original e400, guest PC 0x0c084470 */
if(!s->budget--) { s->failed_pc=0x0c084470u; return 0; }
r[4]=0x00000000u;
goto P_0c084472;
P_0c084472: /* original c739, guest PC 0x0c084472 */
if(!s->budget--) { s->failed_pc=0x0c084472u; return 0; }
r[0]=code_base|0x00084558u;
goto P_0c084474;
P_0c084474: /* original d836, guest PC 0x0c084474 */
if(!s->budget--) { s->failed_pc=0x0c084474u; return 0; }
r[8]=read(ram,0x0c084550u,4);
goto P_0c084476;
P_0c084476: /* original fe08, guest PC 0x0c084476 */
if(!s->budget--) { s->failed_pc=0x0c084476u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c084478;
P_0c084478: /* original ec00, guest PC 0x0c084478 */
if(!s->budget--) { s->failed_pc=0x0c084478u; return 0; }
r[12]=0x00000000u;
goto P_0c08447a;
P_0c08447a: /* original d936, guest PC 0x0c08447a */
if(!s->budget--) { s->failed_pc=0x0c08447au; return 0; }
r[9]=read(ram,0x0c084554u,4);
goto P_0c08447c;
P_0c08447c: /* original ff8d, guest PC 0x0c08447c */
if(!s->budget--) { s->failed_pc=0x0c08447cu; return 0; }
fr[15]=0;
goto P_0c08447e;
P_0c08447e: /* original 6dc3, guest PC 0x0c08447e */
if(!s->budget--) { s->failed_pc=0x0c08447eu; return 0; }
r[13]=r[12];
goto P_0c084480;
P_0c084480: /* original 4d08, guest PC 0x0c084480 */
if(!s->budget--) { s->failed_pc=0x0c084480u; return 0; }
r[13]<<=2;
goto P_0c084482;
P_0c084482: /* original 63c3, guest PC 0x0c084482 */
if(!s->budget--) { s->failed_pc=0x0c084482u; return 0; }
r[3]=r[12];
goto P_0c084484;
P_0c084484: /* original 3d3c, guest PC 0x0c084484 */
if(!s->budget--) { s->failed_pc=0x0c084484u; return 0; }
r[13]+=r[3];
goto P_0c084486;
P_0c084486: /* original 4d08, guest PC 0x0c084486 */
if(!s->budget--) { s->failed_pc=0x0c084486u; return 0; }
r[13]<<=2;
goto P_0c084488;
P_0c084488: /* original d234, guest PC 0x0c084488 */
if(!s->budget--) { s->failed_pc=0x0c084488u; return 0; }
r[2]=read(ram,0x0c08455cu,4);
goto P_0c08448a;
P_0c08448a: /* original 4d00, guest PC 0x0c08448a */
if(!s->budget--) { s->failed_pc=0x0c08448au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c08448c;
P_0c08448c: /* original 64f2, guest PC 0x0c08448c */
if(!s->budget--) { s->failed_pc=0x0c08448cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08448e;
P_0c08448e: /* original 9357, guest PC 0x0c08448e */
if(!s->budget--) { s->failed_pc=0x0c08448eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084540u,2);
goto P_0c084490;
P_0c084490: /* original 6ddf, guest PC 0x0c084490 */
if(!s->budget--) { s->failed_pc=0x0c084490u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c084492;
P_0c084492: /* original d133, guest PC 0x0c084492 */
if(!s->budget--) { s->failed_pc=0x0c084492u; return 0; }
r[1]=read(ram,0x0c084560u,4);
goto P_0c084494;
P_0c084494: /* original 3d2c, guest PC 0x0c084494 */
if(!s->budget--) { s->failed_pc=0x0c084494u; return 0; }
r[13]+=r[2];
goto P_0c084496;
P_0c084496: /* original 410b, guest PC 0x0c084496 */
if(!s->budget--) { s->failed_pc=0x0c084496u; return 0; }
target=r[1];
r[16]=code_base|0x0c08449au;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08449au) { target=s->pc; goto dispatch; }
goto P_0c08449a;
P_0c084498: /* original 343c, guest PC 0x0c084498 */
if(!s->budget--) { s->failed_pc=0x0c084498u; return 0; }
r[4]+=r[3];
goto P_0c08449a;
P_0c08449a: /* original e004, guest PC 0x0c08449a */
if(!s->budget--) { s->failed_pc=0x0c08449au; return 0; }
r[0]=0x00000004u;
goto P_0c08449c;
P_0c08449c: /* original 65f3, guest PC 0x0c08449c */
if(!s->budget--) { s->failed_pc=0x0c08449cu; return 0; }
r[5]=r[15];
goto P_0c08449e;
P_0c08449e: /* original fff7, guest PC 0x0c08449e */
if(!s->budget--) { s->failed_pc=0x0c08449eu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0844a0;
P_0c0844a0: /* original e008, guest PC 0x0c0844a0 */
if(!s->budget--) { s->failed_pc=0x0c0844a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0844a2;
P_0c0844a2: /* original fff7, guest PC 0x0c0844a2 */
if(!s->budget--) { s->failed_pc=0x0c0844a2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0844a4;
P_0c0844a4: /* original e00c, guest PC 0x0c0844a4 */
if(!s->budget--) { s->failed_pc=0x0c0844a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0844a6;
P_0c0844a6: /* original 64f3, guest PC 0x0c0844a6 */
if(!s->budget--) { s->failed_pc=0x0c0844a6u; return 0; }
r[4]=r[15];
goto P_0c0844a8;
P_0c0844a8: /* original 7504, guest PC 0x0c0844a8 */
if(!s->budget--) { s->failed_pc=0x0c0844a8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0844aa;
P_0c0844aa: /* original ffe7, guest PC 0x0c0844aa */
if(!s->budget--) { s->failed_pc=0x0c0844aau; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0844ac;
P_0c0844ac: /* original 490b, guest PC 0x0c0844ac */
if(!s->budget--) { s->failed_pc=0x0c0844acu; return 0; }
target=r[9];
r[16]=code_base|0x0c0844b0u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0844b0u) { target=s->pc; goto dispatch; }
goto P_0c0844b0;
P_0c0844ae: /* original 7404, guest PC 0x0c0844ae */
if(!s->budget--) { s->failed_pc=0x0c0844aeu; return 0; }
r[4]+=0x00000004u;
goto P_0c0844b0;
P_0c0844b0: /* original e004, guest PC 0x0c0844b0 */
if(!s->budget--) { s->failed_pc=0x0c0844b0u; return 0; }
r[0]=0x00000004u;
goto P_0c0844b2;
P_0c0844b2: /* original 52d9, guest PC 0x0c0844b2 */
if(!s->budget--) { s->failed_pc=0x0c0844b2u; return 0; }
r[2]=read(ram,r[13]+36,4);
goto P_0c0844b4;
P_0c0844b4: /* original f6f6, guest PC 0x0c0844b4 */
if(!s->budget--) { s->failed_pc=0x0c0844b4u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0844b6;
P_0c0844b6: /* original e008, guest PC 0x0c0844b6 */
if(!s->budget--) { s->failed_pc=0x0c0844b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0844b8;
P_0c0844b8: /* original f4f6, guest PC 0x0c0844b8 */
if(!s->budget--) { s->failed_pc=0x0c0844b8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0844ba;
P_0c0844ba: /* original e00c, guest PC 0x0c0844ba */
if(!s->budget--) { s->failed_pc=0x0c0844bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0844bc;
P_0c0844bc: /* original f5f6, guest PC 0x0c0844bc */
if(!s->budget--) { s->failed_pc=0x0c0844bcu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0844be;
P_0c0844be: /* original 60b0, guest PC 0x0c0844be */
if(!s->budget--) { s->failed_pc=0x0c0844beu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[0]=tmp;
goto P_0c0844c0;
P_0c0844c0: /* original 6303, guest PC 0x0c0844c0 */
if(!s->budget--) { s->failed_pc=0x0c0844c0u; return 0; }
r[3]=r[0];
goto P_0c0844c2;
P_0c0844c2: /* original 4308, guest PC 0x0c0844c2 */
if(!s->budget--) { s->failed_pc=0x0c0844c2u; return 0; }
r[3]<<=2;
goto P_0c0844c4;
P_0c0844c4: /* original 4000, guest PC 0x0c0844c4 */
if(!s->budget--) { s->failed_pc=0x0c0844c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0844c6;
P_0c0844c6: /* original 303c, guest PC 0x0c0844c6 */
if(!s->budget--) { s->failed_pc=0x0c0844c6u; return 0; }
r[0]+=r[3];
goto P_0c0844c8;
P_0c0844c8: /* original 600e, guest PC 0x0c0844c8 */
if(!s->budget--) { s->failed_pc=0x0c0844c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0844ca;
P_0c0844ca: /* original 4200, guest PC 0x0c0844ca */
if(!s->budget--) { s->failed_pc=0x0c0844cau; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0844cc;
P_0c0844cc: /* original 308c, guest PC 0x0c0844cc */
if(!s->budget--) { s->failed_pc=0x0c0844ccu; return 0; }
r[0]+=r[8];
goto P_0c0844ce;
P_0c0844ce: /* original 032d, guest PC 0x0c0844ce */
if(!s->budget--) { s->failed_pc=0x0c0844ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0844d0;
P_0c0844d0: /* original e028, guest PC 0x0c0844d0 */
if(!s->budget--) { s->failed_pc=0x0c0844d0u; return 0; }
r[0]=0x00000028u;
goto P_0c0844d2;
P_0c0844d2: /* original 0e35, guest PC 0x0c0844d2 */
if(!s->budget--) { s->failed_pc=0x0c0844d2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0844d4;
P_0c0844d4: /* original e018, guest PC 0x0c0844d4 */
if(!s->budget--) { s->failed_pc=0x0c0844d4u; return 0; }
r[0]=0x00000018u;
goto P_0c0844d6;
P_0c0844d6: /* original f3d8, guest PC 0x0c0844d6 */
if(!s->budget--) { s->failed_pc=0x0c0844d6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c0844d8;
P_0c0844d8: /* original fe37, guest PC 0x0c0844d8 */
if(!s->budget--) { s->failed_pc=0x0c0844d8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0844da;
P_0c0844da: /* original e004, guest PC 0x0c0844da */
if(!s->budget--) { s->failed_pc=0x0c0844dau; return 0; }
r[0]=0x00000004u;
goto P_0c0844dc;
P_0c0844dc: /* original f3d6, guest PC 0x0c0844dc */
if(!s->budget--) { s->failed_pc=0x0c0844dcu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0844de;
P_0c0844de: /* original e01c, guest PC 0x0c0844de */
if(!s->budget--) { s->failed_pc=0x0c0844deu; return 0; }
r[0]=0x0000001cu;
goto P_0c0844e0;
P_0c0844e0: /* original fe37, guest PC 0x0c0844e0 */
if(!s->budget--) { s->failed_pc=0x0c0844e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0844e2;
P_0c0844e2: /* original e004, guest PC 0x0c0844e2 */
if(!s->budget--) { s->failed_pc=0x0c0844e2u; return 0; }
r[0]=0x00000004u;
goto P_0c0844e4;
P_0c0844e4: /* original fe6a, guest PC 0x0c0844e4 */
if(!s->budget--) { s->failed_pc=0x0c0844e4u; return 0; }
vf3_matrix_store(s,ram,6,r[14]);
goto P_0c0844e6;
P_0c0844e6: /* original fe47, guest PC 0x0c0844e6 */
if(!s->budget--) { s->failed_pc=0x0c0844e6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0844e8;
P_0c0844e8: /* original e008, guest PC 0x0c0844e8 */
if(!s->budget--) { s->failed_pc=0x0c0844e8u; return 0; }
r[0]=0x00000008u;
goto P_0c0844ea;
P_0c0844ea: /* original fe57, guest PC 0x0c0844ea */
if(!s->budget--) { s->failed_pc=0x0c0844eau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0844ec;
P_0c0844ec: /* original e020, guest PC 0x0c0844ec */
if(!s->budget--) { s->failed_pc=0x0c0844ecu; return 0; }
r[0]=0x00000020u;
goto P_0c0844ee;
P_0c0844ee: /* original 53d5, guest PC 0x0c0844ee */
if(!s->budget--) { s->failed_pc=0x0c0844eeu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0844f0;
P_0c0844f0: /* original 0e35, guest PC 0x0c0844f0 */
if(!s->budget--) { s->failed_pc=0x0c0844f0u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0844f2;
P_0c0844f2: /* original e022, guest PC 0x0c0844f2 */
if(!s->budget--) { s->failed_pc=0x0c0844f2u; return 0; }
r[0]=0x00000022u;
goto P_0c0844f4;
P_0c0844f4: /* original 52d6, guest PC 0x0c0844f4 */
if(!s->budget--) { s->failed_pc=0x0c0844f4u; return 0; }
r[2]=read(ram,r[13]+24,4);
goto P_0c0844f6;
P_0c0844f6: /* original 7aff, guest PC 0x0c0844f6 */
if(!s->budget--) { s->failed_pc=0x0c0844f6u; return 0; }
r[10]+=0xffffffffu;
goto P_0c0844f8;
P_0c0844f8: /* original 4a15, guest PC 0x0c0844f8 */
if(!s->budget--) { s->failed_pc=0x0c0844f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c0844fa;
P_0c0844fa: /* original 0e25, guest PC 0x0c0844fa */
if(!s->budget--) { s->failed_pc=0x0c0844fau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0844fc;
P_0c0844fc: /* original e024, guest PC 0x0c0844fc */
if(!s->budget--) { s->failed_pc=0x0c0844fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0844fe;
P_0c0844fe: /* original 53d7, guest PC 0x0c0844fe */
if(!s->budget--) { s->failed_pc=0x0c0844feu; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c084500;
P_0c084500: /* original 0e35, guest PC 0x0c084500 */
if(!s->budget--) { s->failed_pc=0x0c084500u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c084502;
P_0c084502: /* original e026, guest PC 0x0c084502 */
if(!s->budget--) { s->failed_pc=0x0c084502u; return 0; }
r[0]=0x00000026u;
goto P_0c084504;
P_0c084504: /* original 52d8, guest PC 0x0c084504 */
if(!s->budget--) { s->failed_pc=0x0c084504u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c084506;
P_0c084506: /* original 0e25, guest PC 0x0c084506 */
if(!s->budget--) { s->failed_pc=0x0c084506u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c084508;
P_0c084508: /* original e008, guest PC 0x0c084508 */
if(!s->budget--) { s->failed_pc=0x0c084508u; return 0; }
r[0]=0x00000008u;
goto P_0c08450a;
P_0c08450a: /* original f3d6, guest PC 0x0c08450a */
if(!s->budget--) { s->failed_pc=0x0c08450au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08450c;
P_0c08450c: /* original e014, guest PC 0x0c08450c */
if(!s->budget--) { s->failed_pc=0x0c08450cu; return 0; }
r[0]=0x00000014u;
goto P_0c08450e;
P_0c08450e: /* original fe37, guest PC 0x0c08450e */
if(!s->budget--) { s->failed_pc=0x0c08450eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084510;
P_0c084510: /* original e00c, guest PC 0x0c084510 */
if(!s->budget--) { s->failed_pc=0x0c084510u; return 0; }
r[0]=0x0000000cu;
goto P_0c084512;
P_0c084512: /* original f3d6, guest PC 0x0c084512 */
if(!s->budget--) { s->failed_pc=0x0c084512u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c084514;
P_0c084514: /* original fe37, guest PC 0x0c084514 */
if(!s->budget--) { s->failed_pc=0x0c084514u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084516;
P_0c084516: /* original e010, guest PC 0x0c084516 */
if(!s->budget--) { s->failed_pc=0x0c084516u; return 0; }
r[0]=0x00000010u;
goto P_0c084518;
P_0c084518: /* original f3d6, guest PC 0x0c084518 */
if(!s->budget--) { s->failed_pc=0x0c084518u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08451a;
P_0c08451a: /* original fe37, guest PC 0x0c08451a */
if(!s->budget--) { s->failed_pc=0x0c08451au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08451c;
P_0c08451c: /* original 7e2c, guest PC 0x0c08451c */
if(!s->budget--) { s->failed_pc=0x0c08451cu; return 0; }
r[14]+=0x0000002cu;
goto P_0c08451e;
P_0c08451e: /* original 8dae, guest PC 0x0c08451e */
if(!s->budget--) { s->failed_pc=0x0c08451eu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(cond) { goto P_0c08447e; }
goto P_0c084522;
P_0c084520: /* original 7c01, guest PC 0x0c084520 */
if(!s->budget--) { s->failed_pc=0x0c084520u; return 0; }
r[12]+=0x00000001u;
goto P_0c084522;
P_0c084522: /* original d210, guest PC 0x0c084522 */
if(!s->budget--) { s->failed_pc=0x0c084522u; return 0; }
r[2]=read(ram,0x0c084564u,4);
goto P_0c084524;
P_0c084524: /* original 420b, guest PC 0x0c084524 */
if(!s->budget--) { s->failed_pc=0x0c084524u; return 0; }
target=r[2];
r[16]=code_base|0x0c084528u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084528u) { target=s->pc; goto dispatch; }
goto P_0c084528;
P_0c084526: /* original e401, guest PC 0x0c084526 */
if(!s->budget--) { s->failed_pc=0x0c084526u; return 0; }
r[4]=0x00000001u;
goto P_0c084528;
P_0c084528: /* original 7f10, guest PC 0x0c084528 */
if(!s->budget--) { s->failed_pc=0x0c084528u; return 0; }
r[15]+=0x00000010u;
goto P_0c08452a;
P_0c08452a: /* original 4f26, guest PC 0x0c08452a */
if(!s->budget--) { s->failed_pc=0x0c08452au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08452c;
P_0c08452c: /* original fef9, guest PC 0x0c08452c */
if(!s->budget--) { s->failed_pc=0x0c08452cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08452e;
P_0c08452e: /* original fff9, guest PC 0x0c08452e */
if(!s->budget--) { s->failed_pc=0x0c08452eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084530;
P_0c084530: /* original 68f6, guest PC 0x0c084530 */
if(!s->budget--) { s->failed_pc=0x0c084530u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c084532;
P_0c084532: /* original 69f6, guest PC 0x0c084532 */
if(!s->budget--) { s->failed_pc=0x0c084532u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084534;
P_0c084534: /* original 6af6, guest PC 0x0c084534 */
if(!s->budget--) { s->failed_pc=0x0c084534u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084536;
P_0c084536: /* original 6bf6, guest PC 0x0c084536 */
if(!s->budget--) { s->failed_pc=0x0c084536u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084538;
P_0c084538: /* original 6cf6, guest PC 0x0c084538 */
if(!s->budget--) { s->failed_pc=0x0c084538u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08453a;
P_0c08453a: /* original 6df6, guest PC 0x0c08453a */
if(!s->budget--) { s->failed_pc=0x0c08453au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08453c;
P_0c08453c: /* original 000b, guest PC 0x0c08453c */
if(!s->budget--) { s->failed_pc=0x0c08453cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08453e: /* original 6ef6, guest PC 0x0c08453e */
if(!s->budget--) { s->failed_pc=0x0c08453eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084540u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084540u; return 0; } return 1;
P_0c084568: /* original 2fe6, guest PC 0x0c084568 */
if(!s->budget--) { s->failed_pc=0x0c084568u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08456a;
P_0c08456a: /* original 6e43, guest PC 0x0c08456a */
if(!s->budget--) { s->failed_pc=0x0c08456au; return 0; }
r[14]=r[4];
goto P_0c08456c;
P_0c08456c: /* original 2fd6, guest PC 0x0c08456c */
if(!s->budget--) { s->failed_pc=0x0c08456cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08456e;
P_0c08456e: /* original 4f22, guest PC 0x0c08456e */
if(!s->budget--) { s->failed_pc=0x0c08456eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084570;
P_0c084570: /* original 7fe8, guest PC 0x0c084570 */
if(!s->budget--) { s->failed_pc=0x0c084570u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c084572;
P_0c084572: /* original 1f52, guest PC 0x0c084572 */
if(!s->budget--) { s->failed_pc=0x0c084572u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c084574;
P_0c084574: /* original 2f62, guest PC 0x0c084574 */
if(!s->budget--) { s->failed_pc=0x0c084574u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c084576;
P_0c084576: /* original d34d, guest PC 0x0c084576 */
if(!s->budget--) { s->failed_pc=0x0c084576u; return 0; }
r[3]=read(ram,0x0c0846acu,4);
goto P_0c084578;
P_0c084578: /* original 430b, guest PC 0x0c084578 */
if(!s->budget--) { s->failed_pc=0x0c084578u; return 0; }
target=r[3];
r[16]=code_base|0x0c08457cu;
write(ram,r[15]+4,r[7],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08457cu) { target=s->pc; goto dispatch; }
goto P_0c08457c;
P_0c08457a: /* original 1f71, guest PC 0x0c08457a */
if(!s->budget--) { s->failed_pc=0x0c08457au; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c08457c;
P_0c08457c: /* original e20f, guest PC 0x0c08457c */
if(!s->budget--) { s->failed_pc=0x0c08457cu; return 0; }
r[2]=0x0000000fu;
goto P_0c08457e;
P_0c08457e: /* original 6403, guest PC 0x0c08457e */
if(!s->budget--) { s->failed_pc=0x0c08457eu; return 0; }
r[4]=r[0];
goto P_0c084580;
P_0c084580: /* original 2429, guest PC 0x0c084580 */
if(!s->budget--) { s->failed_pc=0x0c084580u; return 0; }
r[4]&=r[2];
goto P_0c084582;
P_0c084582: /* original d14b, guest PC 0x0c084582 */
if(!s->budget--) { s->failed_pc=0x0c084582u; return 0; }
r[1]=read(ram,0x0c0846b0u,4);
goto P_0c084584;
P_0c084584: /* original 6d43, guest PC 0x0c084584 */
if(!s->budget--) { s->failed_pc=0x0c084584u; return 0; }
r[13]=r[4];
goto P_0c084586;
P_0c084586: /* original 4d08, guest PC 0x0c084586 */
if(!s->budget--) { s->failed_pc=0x0c084586u; return 0; }
r[13]<<=2;
goto P_0c084588;
P_0c084588: /* original 6343, guest PC 0x0c084588 */
if(!s->budget--) { s->failed_pc=0x0c084588u; return 0; }
r[3]=r[4];
goto P_0c08458a;
P_0c08458a: /* original 3d3c, guest PC 0x0c08458a */
if(!s->budget--) { s->failed_pc=0x0c08458au; return 0; }
r[13]+=r[3];
goto P_0c08458c;
P_0c08458c: /* original 4d08, guest PC 0x0c08458c */
if(!s->budget--) { s->failed_pc=0x0c08458cu; return 0; }
r[13]<<=2;
goto P_0c08458e;
P_0c08458e: /* original d349, guest PC 0x0c08458e */
if(!s->budget--) { s->failed_pc=0x0c08458eu; return 0; }
r[3]=read(ram,0x0c0846b4u,4);
goto P_0c084590;
P_0c084590: /* original 4d00, guest PC 0x0c084590 */
if(!s->budget--) { s->failed_pc=0x0c084590u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c084592;
P_0c084592: /* original 6ddf, guest PC 0x0c084592 */
if(!s->budget--) { s->failed_pc=0x0c084592u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c084594;
P_0c084594: /* original 3d1c, guest PC 0x0c084594 */
if(!s->budget--) { s->failed_pc=0x0c084594u; return 0; }
r[13]+=r[1];
goto P_0c084596;
P_0c084596: /* original 430b, guest PC 0x0c084596 */
if(!s->budget--) { s->failed_pc=0x0c084596u; return 0; }
target=r[3];
r[16]=code_base|0x0c08459au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08459au) { target=s->pc; goto dispatch; }
goto P_0c08459a;
P_0c084598: /* original e400, guest PC 0x0c084598 */
if(!s->budget--) { s->failed_pc=0x0c084598u; return 0; }
r[4]=0x00000000u;
goto P_0c08459a;
P_0c08459a: /* original d247, guest PC 0x0c08459a */
if(!s->budget--) { s->failed_pc=0x0c08459au; return 0; }
r[2]=read(ram,0x0c0846b8u,4);
goto P_0c08459c;
P_0c08459c: /* original 9384, guest PC 0x0c08459c */
if(!s->budget--) { s->failed_pc=0x0c08459cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0846a8u,2);
goto P_0c08459e;
P_0c08459e: /* original 54f2, guest PC 0x0c08459e */
if(!s->budget--) { s->failed_pc=0x0c08459eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0845a0;
P_0c0845a0: /* original 420b, guest PC 0x0c0845a0 */
if(!s->budget--) { s->failed_pc=0x0c0845a0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0845a4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0845a4u) { target=s->pc; goto dispatch; }
goto P_0c0845a4;
P_0c0845a2: /* original 343c, guest PC 0x0c0845a2 */
if(!s->budget--) { s->failed_pc=0x0c0845a2u; return 0; }
r[4]+=r[3];
goto P_0c0845a4;
P_0c0845a4: /* original e00c, guest PC 0x0c0845a4 */
if(!s->budget--) { s->failed_pc=0x0c0845a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0845a6;
P_0c0845a6: /* original f48d, guest PC 0x0c0845a6 */
if(!s->budget--) { s->failed_pc=0x0c0845a6u; return 0; }
fr[4]=0;
goto P_0c0845a8;
P_0c0845a8: /* original ff47, guest PC 0x0c0845a8 */
if(!s->budget--) { s->failed_pc=0x0c0845a8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0845aa;
P_0c0845aa: /* original e010, guest PC 0x0c0845aa */
if(!s->budget--) { s->failed_pc=0x0c0845aau; return 0; }
r[0]=0x00000010u;
goto P_0c0845ac;
P_0c0845ac: /* original ff47, guest PC 0x0c0845ac */
if(!s->budget--) { s->failed_pc=0x0c0845acu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0845ae;
P_0c0845ae: /* original c743, guest PC 0x0c0845ae */
if(!s->budget--) { s->failed_pc=0x0c0845aeu; return 0; }
r[0]=code_base|0x000846bcu;
goto P_0c0845b0;
P_0c0845b0: /* original f308, guest PC 0x0c0845b0 */
if(!s->budget--) { s->failed_pc=0x0c0845b0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0845b2;
P_0c0845b2: /* original 65f3, guest PC 0x0c0845b2 */
if(!s->budget--) { s->failed_pc=0x0c0845b2u; return 0; }
r[5]=r[15];
goto P_0c0845b4;
P_0c0845b4: /* original e014, guest PC 0x0c0845b4 */
if(!s->budget--) { s->failed_pc=0x0c0845b4u; return 0; }
r[0]=0x00000014u;
goto P_0c0845b6;
P_0c0845b6: /* original 64f3, guest PC 0x0c0845b6 */
if(!s->budget--) { s->failed_pc=0x0c0845b6u; return 0; }
r[4]=r[15];
goto P_0c0845b8;
P_0c0845b8: /* original ff37, guest PC 0x0c0845b8 */
if(!s->budget--) { s->failed_pc=0x0c0845b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0845ba;
P_0c0845ba: /* original 750c, guest PC 0x0c0845ba */
if(!s->budget--) { s->failed_pc=0x0c0845bau; return 0; }
r[5]+=0x0000000cu;
goto P_0c0845bc;
P_0c0845bc: /* original d340, guest PC 0x0c0845bc */
if(!s->budget--) { s->failed_pc=0x0c0845bcu; return 0; }
r[3]=read(ram,0x0c0846c0u,4);
goto P_0c0845be;
P_0c0845be: /* original 430b, guest PC 0x0c0845be */
if(!s->budget--) { s->failed_pc=0x0c0845beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0845c2u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0845c2u) { target=s->pc; goto dispatch; }
goto P_0c0845c2;
P_0c0845c0: /* original 740c, guest PC 0x0c0845c0 */
if(!s->budget--) { s->failed_pc=0x0c0845c0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0845c2;
P_0c0845c2: /* original e00c, guest PC 0x0c0845c2 */
if(!s->budget--) { s->failed_pc=0x0c0845c2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0845c4;
P_0c0845c4: /* original 62f2, guest PC 0x0c0845c4 */
if(!s->budget--) { s->failed_pc=0x0c0845c4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0845c6;
P_0c0845c6: /* original f3f6, guest PC 0x0c0845c6 */
if(!s->budget--) { s->failed_pc=0x0c0845c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0845c8;
P_0c0845c8: /* original e010, guest PC 0x0c0845c8 */
if(!s->budget--) { s->failed_pc=0x0c0845c8u; return 0; }
r[0]=0x00000010u;
goto P_0c0845ca;
P_0c0845ca: /* original f23a, guest PC 0x0c0845ca */
if(!s->budget--) { s->failed_pc=0x0c0845cau; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c0845cc;
P_0c0845cc: /* original f3f6, guest PC 0x0c0845cc */
if(!s->budget--) { s->failed_pc=0x0c0845ccu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0845ce;
P_0c0845ce: /* original e014, guest PC 0x0c0845ce */
if(!s->budget--) { s->failed_pc=0x0c0845ceu; return 0; }
r[0]=0x00000014u;
goto P_0c0845d0;
P_0c0845d0: /* original 53f1, guest PC 0x0c0845d0 */
if(!s->budget--) { s->failed_pc=0x0c0845d0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0845d2;
P_0c0845d2: /* original f33a, guest PC 0x0c0845d2 */
if(!s->budget--) { s->failed_pc=0x0c0845d2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0845d4;
P_0c0845d4: /* original f3f6, guest PC 0x0c0845d4 */
if(!s->budget--) { s->failed_pc=0x0c0845d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0845d6;
P_0c0845d6: /* original 53f9, guest PC 0x0c0845d6 */
if(!s->budget--) { s->failed_pc=0x0c0845d6u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0845d8;
P_0c0845d8: /* original f33a, guest PC 0x0c0845d8 */
if(!s->budget--) { s->failed_pc=0x0c0845d8u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0845da;
P_0c0845da: /* original 52d5, guest PC 0x0c0845da */
if(!s->budget--) { s->failed_pc=0x0c0845dau; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0845dc;
P_0c0845dc: /* original 53fa, guest PC 0x0c0845dc */
if(!s->budget--) { s->failed_pc=0x0c0845dcu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c0845de;
P_0c0845de: /* original 2321, guest PC 0x0c0845de */
if(!s->budget--) { s->failed_pc=0x0c0845deu; return 0; }
write(ram,r[3],r[2],2);
goto P_0c0845e0;
P_0c0845e0: /* original 52d6, guest PC 0x0c0845e0 */
if(!s->budget--) { s->failed_pc=0x0c0845e0u; return 0; }
r[2]=read(ram,r[13]+24,4);
goto P_0c0845e2;
P_0c0845e2: /* original 53fb, guest PC 0x0c0845e2 */
if(!s->budget--) { s->failed_pc=0x0c0845e2u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0845e4;
P_0c0845e4: /* original 2321, guest PC 0x0c0845e4 */
if(!s->budget--) { s->failed_pc=0x0c0845e4u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c0845e6;
P_0c0845e6: /* original d137, guest PC 0x0c0845e6 */
if(!s->budget--) { s->failed_pc=0x0c0845e6u; return 0; }
r[1]=read(ram,0x0c0846c4u,4);
goto P_0c0845e8;
P_0c0845e8: /* original d237, guest PC 0x0c0845e8 */
if(!s->budget--) { s->failed_pc=0x0c0845e8u; return 0; }
r[2]=read(ram,0x0c0846c8u,4);
goto P_0c0845ea;
P_0c0845ea: /* original 6010, guest PC 0x0c0845ea */
if(!s->budget--) { s->failed_pc=0x0c0845eau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c0845ec;
P_0c0845ec: /* original 6303, guest PC 0x0c0845ec */
if(!s->budget--) { s->failed_pc=0x0c0845ecu; return 0; }
r[3]=r[0];
goto P_0c0845ee;
P_0c0845ee: /* original 4308, guest PC 0x0c0845ee */
if(!s->budget--) { s->failed_pc=0x0c0845eeu; return 0; }
r[3]<<=2;
goto P_0c0845f0;
P_0c0845f0: /* original 4000, guest PC 0x0c0845f0 */
if(!s->budget--) { s->failed_pc=0x0c0845f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0845f2;
P_0c0845f2: /* original 303c, guest PC 0x0c0845f2 */
if(!s->budget--) { s->failed_pc=0x0c0845f2u; return 0; }
r[0]+=r[3];
goto P_0c0845f4;
P_0c0845f4: /* original 53d9, guest PC 0x0c0845f4 */
if(!s->budget--) { s->failed_pc=0x0c0845f4u; return 0; }
r[3]=read(ram,r[13]+36,4);
goto P_0c0845f6;
P_0c0845f6: /* original 600e, guest PC 0x0c0845f6 */
if(!s->budget--) { s->failed_pc=0x0c0845f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0845f8;
P_0c0845f8: /* original 320c, guest PC 0x0c0845f8 */
if(!s->budget--) { s->failed_pc=0x0c0845f8u; return 0; }
r[2]+=r[0];
goto P_0c0845fa;
P_0c0845fa: /* original 4300, guest PC 0x0c0845fa */
if(!s->budget--) { s->failed_pc=0x0c0845fau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0845fc;
P_0c0845fc: /* original 332c, guest PC 0x0c0845fc */
if(!s->budget--) { s->failed_pc=0x0c0845fcu; return 0; }
r[3]+=r[2];
goto P_0c0845fe;
P_0c0845fe: /* original 6031, guest PC 0x0c0845fe */
if(!s->budget--) { s->failed_pc=0x0c0845feu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[0]=tmp;
goto P_0c084600;
P_0c084600: /* original e228, guest PC 0x0c084600 */
if(!s->budget--) { s->failed_pc=0x0c084600u; return 0; }
r[2]=0x00000028u;
goto P_0c084602;
P_0c084602: /* original 32ec, guest PC 0x0c084602 */
if(!s->budget--) { s->failed_pc=0x0c084602u; return 0; }
r[2]+=r[14];
goto P_0c084604;
P_0c084604: /* original 2201, guest PC 0x0c084604 */
if(!s->budget--) { s->failed_pc=0x0c084604u; return 0; }
write(ram,r[2],r[0],2);
goto P_0c084606;
P_0c084606: /* original e018, guest PC 0x0c084606 */
if(!s->budget--) { s->failed_pc=0x0c084606u; return 0; }
r[0]=0x00000018u;
goto P_0c084608;
P_0c084608: /* original f3d8, guest PC 0x0c084608 */
if(!s->budget--) { s->failed_pc=0x0c084608u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08460a;
P_0c08460a: /* original fe37, guest PC 0x0c08460a */
if(!s->budget--) { s->failed_pc=0x0c08460au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08460c;
P_0c08460c: /* original e004, guest PC 0x0c08460c */
if(!s->budget--) { s->failed_pc=0x0c08460cu; return 0; }
r[0]=0x00000004u;
goto P_0c08460e;
P_0c08460e: /* original f3d6, guest PC 0x0c08460e */
if(!s->budget--) { s->failed_pc=0x0c08460eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c084610;
P_0c084610: /* original e01c, guest PC 0x0c084610 */
if(!s->budget--) { s->failed_pc=0x0c084610u; return 0; }
r[0]=0x0000001cu;
goto P_0c084612;
P_0c084612: /* original fe37, guest PC 0x0c084612 */
if(!s->budget--) { s->failed_pc=0x0c084612u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084614;
P_0c084614: /* original e004, guest PC 0x0c084614 */
if(!s->budget--) { s->failed_pc=0x0c084614u; return 0; }
r[0]=0x00000004u;
goto P_0c084616;
P_0c084616: /* original 63f2, guest PC 0x0c084616 */
if(!s->budget--) { s->failed_pc=0x0c084616u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c084618;
P_0c084618: /* original f338, guest PC 0x0c084618 */
if(!s->budget--) { s->failed_pc=0x0c084618u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c08461a;
P_0c08461a: /* original fe3a, guest PC 0x0c08461a */
if(!s->budget--) { s->failed_pc=0x0c08461au; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c08461c;
P_0c08461c: /* original 53f1, guest PC 0x0c08461c */
if(!s->budget--) { s->failed_pc=0x0c08461cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c08461e;
P_0c08461e: /* original f338, guest PC 0x0c08461e */
if(!s->budget--) { s->failed_pc=0x0c08461eu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c084620;
P_0c084620: /* original fe37, guest PC 0x0c084620 */
if(!s->budget--) { s->failed_pc=0x0c084620u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084622;
P_0c084622: /* original e008, guest PC 0x0c084622 */
if(!s->budget--) { s->failed_pc=0x0c084622u; return 0; }
r[0]=0x00000008u;
goto P_0c084624;
P_0c084624: /* original 53f9, guest PC 0x0c084624 */
if(!s->budget--) { s->failed_pc=0x0c084624u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c084626;
P_0c084626: /* original f338, guest PC 0x0c084626 */
if(!s->budget--) { s->failed_pc=0x0c084626u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c084628;
P_0c084628: /* original fe37, guest PC 0x0c084628 */
if(!s->budget--) { s->failed_pc=0x0c084628u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08462a;
P_0c08462a: /* original e020, guest PC 0x0c08462a */
if(!s->budget--) { s->failed_pc=0x0c08462au; return 0; }
r[0]=0x00000020u;
goto P_0c08462c;
P_0c08462c: /* original 53fa, guest PC 0x0c08462c */
if(!s->budget--) { s->failed_pc=0x0c08462cu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c08462e;
P_0c08462e: /* original 6231, guest PC 0x0c08462e */
if(!s->budget--) { s->failed_pc=0x0c08462eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c084630;
P_0c084630: /* original 0e25, guest PC 0x0c084630 */
if(!s->budget--) { s->failed_pc=0x0c084630u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c084632;
P_0c084632: /* original e022, guest PC 0x0c084632 */
if(!s->budget--) { s->failed_pc=0x0c084632u; return 0; }
r[0]=0x00000022u;
goto P_0c084634;
P_0c084634: /* original 53fb, guest PC 0x0c084634 */
if(!s->budget--) { s->failed_pc=0x0c084634u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c084636;
P_0c084636: /* original 6231, guest PC 0x0c084636 */
if(!s->budget--) { s->failed_pc=0x0c084636u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c084638;
P_0c084638: /* original 0e25, guest PC 0x0c084638 */
if(!s->budget--) { s->failed_pc=0x0c084638u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08463a;
P_0c08463a: /* original e024, guest PC 0x0c08463a */
if(!s->budget--) { s->failed_pc=0x0c08463au; return 0; }
r[0]=0x00000024u;
goto P_0c08463c;
P_0c08463c: /* original 53d7, guest PC 0x0c08463c */
if(!s->budget--) { s->failed_pc=0x0c08463cu; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c08463e;
P_0c08463e: /* original 0e35, guest PC 0x0c08463e */
if(!s->budget--) { s->failed_pc=0x0c08463eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c084640;
P_0c084640: /* original 52d8, guest PC 0x0c084640 */
if(!s->budget--) { s->failed_pc=0x0c084640u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c084642;
P_0c084642: /* original e026, guest PC 0x0c084642 */
if(!s->budget--) { s->failed_pc=0x0c084642u; return 0; }
r[0]=0x00000026u;
goto P_0c084644;
P_0c084644: /* original 0e25, guest PC 0x0c084644 */
if(!s->budget--) { s->failed_pc=0x0c084644u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c084646;
P_0c084646: /* original e008, guest PC 0x0c084646 */
if(!s->budget--) { s->failed_pc=0x0c084646u; return 0; }
r[0]=0x00000008u;
goto P_0c084648;
P_0c084648: /* original f3d6, guest PC 0x0c084648 */
if(!s->budget--) { s->failed_pc=0x0c084648u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08464a;
P_0c08464a: /* original e014, guest PC 0x0c08464a */
if(!s->budget--) { s->failed_pc=0x0c08464au; return 0; }
r[0]=0x00000014u;
goto P_0c08464c;
P_0c08464c: /* original fe37, guest PC 0x0c08464c */
if(!s->budget--) { s->failed_pc=0x0c08464cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08464e;
P_0c08464e: /* original e00c, guest PC 0x0c08464e */
if(!s->budget--) { s->failed_pc=0x0c08464eu; return 0; }
r[0]=0x0000000cu;
goto P_0c084650;
P_0c084650: /* original f3d6, guest PC 0x0c084650 */
if(!s->budget--) { s->failed_pc=0x0c084650u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c084652;
P_0c084652: /* original fe37, guest PC 0x0c084652 */
if(!s->budget--) { s->failed_pc=0x0c084652u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084654;
P_0c084654: /* original e010, guest PC 0x0c084654 */
if(!s->budget--) { s->failed_pc=0x0c084654u; return 0; }
r[0]=0x00000010u;
goto P_0c084656;
P_0c084656: /* original f3d6, guest PC 0x0c084656 */
if(!s->budget--) { s->failed_pc=0x0c084656u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c084658;
P_0c084658: /* original fe37, guest PC 0x0c084658 */
if(!s->budget--) { s->failed_pc=0x0c084658u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08465a;
P_0c08465a: /* original d31c, guest PC 0x0c08465a */
if(!s->budget--) { s->failed_pc=0x0c08465au; return 0; }
r[3]=read(ram,0x0c0846ccu,4);
goto P_0c08465c;
P_0c08465c: /* original 430b, guest PC 0x0c08465c */
if(!s->budget--) { s->failed_pc=0x0c08465cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084660u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084660u) { target=s->pc; goto dispatch; }
goto P_0c084660;
P_0c08465e: /* original e401, guest PC 0x0c08465e */
if(!s->budget--) { s->failed_pc=0x0c08465eu; return 0; }
r[4]=0x00000001u;
goto P_0c084660;
P_0c084660: /* original 7f18, guest PC 0x0c084660 */
if(!s->budget--) { s->failed_pc=0x0c084660u; return 0; }
r[15]+=0x00000018u;
goto P_0c084662;
P_0c084662: /* original 4f26, guest PC 0x0c084662 */
if(!s->budget--) { s->failed_pc=0x0c084662u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084664;
P_0c084664: /* original 6df6, guest PC 0x0c084664 */
if(!s->budget--) { s->failed_pc=0x0c084664u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084666;
P_0c084666: /* original 000b, guest PC 0x0c084666 */
if(!s->budget--) { s->failed_pc=0x0c084666u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084668: /* original 6ef6, guest PC 0x0c084668 */
if(!s->budget--) { s->failed_pc=0x0c084668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08466au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
