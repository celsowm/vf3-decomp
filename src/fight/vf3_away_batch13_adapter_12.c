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
int vf3_away_batch13_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085250u: goto P_0c085250;
case 0x0c085252u: goto P_0c085252;
case 0x0c085254u: goto P_0c085254;
case 0x0c085256u: goto P_0c085256;
case 0x0c085258u: goto P_0c085258;
case 0x0c08525au: goto P_0c08525a;
case 0x0c08525cu: goto P_0c08525c;
case 0x0c08525eu: goto P_0c08525e;
case 0x0c085260u: goto P_0c085260;
case 0x0c085262u: goto P_0c085262;
case 0x0c085264u: goto P_0c085264;
case 0x0c085266u: goto P_0c085266;
case 0x0c085268u: goto P_0c085268;
case 0x0c08526au: goto P_0c08526a;
case 0x0c08526cu: goto P_0c08526c;
case 0x0c08526eu: goto P_0c08526e;
case 0x0c085270u: goto P_0c085270;
case 0x0c085272u: goto P_0c085272;
case 0x0c085274u: goto P_0c085274;
case 0x0c085276u: goto P_0c085276;
case 0x0c085278u: goto P_0c085278;
case 0x0c08527au: goto P_0c08527a;
case 0x0c08527cu: goto P_0c08527c;
case 0x0c08527eu: goto P_0c08527e;
case 0x0c085280u: goto P_0c085280;
case 0x0c085282u: goto P_0c085282;
case 0x0c085284u: goto P_0c085284;
case 0x0c085286u: goto P_0c085286;
case 0x0c085288u: goto P_0c085288;
case 0x0c08528au: goto P_0c08528a;
case 0x0c08528cu: goto P_0c08528c;
case 0x0c08528eu: goto P_0c08528e;
case 0x0c085290u: goto P_0c085290;
case 0x0c085292u: goto P_0c085292;
case 0x0c085294u: goto P_0c085294;
case 0x0c085296u: goto P_0c085296;
case 0x0c085298u: goto P_0c085298;
case 0x0c08529au: goto P_0c08529a;
case 0x0c08529cu: goto P_0c08529c;
case 0x0c08529eu: goto P_0c08529e;
case 0x0c0852a0u: goto P_0c0852a0;
case 0x0c0852a2u: goto P_0c0852a2;
case 0x0c0852a4u: goto P_0c0852a4;
case 0x0c0852a6u: goto P_0c0852a6;
case 0x0c0852a8u: goto P_0c0852a8;
case 0x0c0852aau: goto P_0c0852aa;
case 0x0c0852acu: goto P_0c0852ac;
case 0x0c0852aeu: goto P_0c0852ae;
case 0x0c0852b0u: goto P_0c0852b0;
case 0x0c0852b2u: goto P_0c0852b2;
case 0x0c0852b4u: goto P_0c0852b4;
case 0x0c0852b6u: goto P_0c0852b6;
case 0x0c0852b8u: goto P_0c0852b8;
case 0x0c0852bau: goto P_0c0852ba;
case 0x0c0852bcu: goto P_0c0852bc;
case 0x0c0852beu: goto P_0c0852be;
case 0x0c0852c0u: goto P_0c0852c0;
case 0x0c0852c2u: goto P_0c0852c2;
case 0x0c0852c4u: goto P_0c0852c4;
case 0x0c0852c6u: goto P_0c0852c6;
case 0x0c0852c8u: goto P_0c0852c8;
case 0x0c0852cau: goto P_0c0852ca;
case 0x0c0852ccu: goto P_0c0852cc;
case 0x0c0852ceu: goto P_0c0852ce;
case 0x0c0852d0u: goto P_0c0852d0;
case 0x0c0852d2u: goto P_0c0852d2;
case 0x0c0852d4u: goto P_0c0852d4;
case 0x0c0852d6u: goto P_0c0852d6;
case 0x0c0852d8u: goto P_0c0852d8;
case 0x0c0852dau: goto P_0c0852da;
case 0x0c0852dcu: goto P_0c0852dc;
case 0x0c0852deu: goto P_0c0852de;
case 0x0c0852e0u: goto P_0c0852e0;
case 0x0c0852e2u: goto P_0c0852e2;
case 0x0c0852e4u: goto P_0c0852e4;
case 0x0c0852e6u: goto P_0c0852e6;
case 0x0c0852e8u: goto P_0c0852e8;
case 0x0c0852eau: goto P_0c0852ea;
case 0x0c0852ecu: goto P_0c0852ec;
case 0x0c0852eeu: goto P_0c0852ee;
case 0x0c0852f0u: goto P_0c0852f0;
case 0x0c0852f2u: goto P_0c0852f2;
case 0x0c0852f4u: goto P_0c0852f4;
case 0x0c0852f6u: goto P_0c0852f6;
case 0x0c0852f8u: goto P_0c0852f8;
case 0x0c0852fau: goto P_0c0852fa;
case 0x0c0852fcu: goto P_0c0852fc;
case 0x0c0852feu: goto P_0c0852fe;
case 0x0c085300u: goto P_0c085300;
case 0x0c085302u: goto P_0c085302;
case 0x0c085304u: goto P_0c085304;
case 0x0c085306u: goto P_0c085306;
case 0x0c085308u: goto P_0c085308;
case 0x0c08530au: goto P_0c08530a;
case 0x0c08530cu: goto P_0c08530c;
case 0x0c08530eu: goto P_0c08530e;
case 0x0c085310u: goto P_0c085310;
case 0x0c085312u: goto P_0c085312;
case 0x0c085314u: goto P_0c085314;
case 0x0c085316u: goto P_0c085316;
case 0x0c085318u: goto P_0c085318;
case 0x0c08531au: goto P_0c08531a;
case 0x0c08531cu: goto P_0c08531c;
case 0x0c08531eu: goto P_0c08531e;
case 0x0c085320u: goto P_0c085320;
case 0x0c085322u: goto P_0c085322;
case 0x0c085324u: goto P_0c085324;
case 0x0c085326u: goto P_0c085326;
case 0x0c085328u: goto P_0c085328;
case 0x0c08532au: goto P_0c08532a;
case 0x0c08532cu: goto P_0c08532c;
case 0x0c08532eu: goto P_0c08532e;
case 0x0c085330u: goto P_0c085330;
case 0x0c085332u: goto P_0c085332;
case 0x0c085334u: goto P_0c085334;
case 0x0c085336u: goto P_0c085336;
case 0x0c085338u: goto P_0c085338;
case 0x0c08533au: goto P_0c08533a;
case 0x0c08533cu: goto P_0c08533c;
case 0x0c08533eu: goto P_0c08533e;
case 0x0c085340u: goto P_0c085340;
case 0x0c085342u: goto P_0c085342;
case 0x0c085344u: goto P_0c085344;
case 0x0c085346u: goto P_0c085346;
case 0x0c085348u: goto P_0c085348;
case 0x0c08534au: goto P_0c08534a;
case 0x0c08534cu: goto P_0c08534c;
case 0x0c08534eu: goto P_0c08534e;
case 0x0c085350u: goto P_0c085350;
case 0x0c085352u: goto P_0c085352;
case 0x0c085354u: goto P_0c085354;
case 0x0c08538cu: goto P_0c08538c;
case 0x0c08538eu: goto P_0c08538e;
case 0x0c085390u: goto P_0c085390;
case 0x0c085392u: goto P_0c085392;
case 0x0c085394u: goto P_0c085394;
case 0x0c085396u: goto P_0c085396;
case 0x0c085398u: goto P_0c085398;
case 0x0c08539au: goto P_0c08539a;
case 0x0c08539cu: goto P_0c08539c;
case 0x0c08539eu: goto P_0c08539e;
case 0x0c0853a0u: goto P_0c0853a0;
case 0x0c0853a2u: goto P_0c0853a2;
case 0x0c0853a4u: goto P_0c0853a4;
case 0x0c0853a6u: goto P_0c0853a6;
case 0x0c0853a8u: goto P_0c0853a8;
case 0x0c0853aau: goto P_0c0853aa;
case 0x0c0853acu: goto P_0c0853ac;
case 0x0c0853aeu: goto P_0c0853ae;
case 0x0c0853b0u: goto P_0c0853b0;
case 0x0c0853b2u: goto P_0c0853b2;
case 0x0c0853b4u: goto P_0c0853b4;
case 0x0c0853b6u: goto P_0c0853b6;
case 0x0c0853b8u: goto P_0c0853b8;
case 0x0c0853bau: goto P_0c0853ba;
case 0x0c0853bcu: goto P_0c0853bc;
case 0x0c0853beu: goto P_0c0853be;
case 0x0c0853c0u: goto P_0c0853c0;
case 0x0c0853c2u: goto P_0c0853c2;
case 0x0c0853c4u: goto P_0c0853c4;
case 0x0c0853c6u: goto P_0c0853c6;
case 0x0c0853c8u: goto P_0c0853c8;
case 0x0c0853cau: goto P_0c0853ca;
case 0x0c0853ccu: goto P_0c0853cc;
case 0x0c0853ceu: goto P_0c0853ce;
case 0x0c0853d0u: goto P_0c0853d0;
case 0x0c0853d2u: goto P_0c0853d2;
case 0x0c0853d4u: goto P_0c0853d4;
case 0x0c0853d6u: goto P_0c0853d6;
case 0x0c0853d8u: goto P_0c0853d8;
case 0x0c0853dau: goto P_0c0853da;
case 0x0c0853dcu: goto P_0c0853dc;
case 0x0c0853deu: goto P_0c0853de;
case 0x0c0853e0u: goto P_0c0853e0;
case 0x0c0853e2u: goto P_0c0853e2;
case 0x0c0853e4u: goto P_0c0853e4;
case 0x0c0853e6u: goto P_0c0853e6;
case 0x0c0853e8u: goto P_0c0853e8;
case 0x0c0853eau: goto P_0c0853ea;
case 0x0c0853ecu: goto P_0c0853ec;
case 0x0c0853eeu: goto P_0c0853ee;
case 0x0c0853f0u: goto P_0c0853f0;
case 0x0c0853f2u: goto P_0c0853f2;
case 0x0c0853f4u: goto P_0c0853f4;
case 0x0c0853f6u: goto P_0c0853f6;
case 0x0c0853f8u: goto P_0c0853f8;
case 0x0c0853fau: goto P_0c0853fa;
case 0x0c0853fcu: goto P_0c0853fc;
case 0x0c0853feu: goto P_0c0853fe;
case 0x0c085400u: goto P_0c085400;
case 0x0c085402u: goto P_0c085402;
case 0x0c085404u: goto P_0c085404;
case 0x0c085406u: goto P_0c085406;
case 0x0c085408u: goto P_0c085408;
case 0x0c08540au: goto P_0c08540a;
case 0x0c08540cu: goto P_0c08540c;
case 0x0c08540eu: goto P_0c08540e;
case 0x0c085410u: goto P_0c085410;
case 0x0c085412u: goto P_0c085412;
case 0x0c085414u: goto P_0c085414;
case 0x0c085416u: goto P_0c085416;
case 0x0c085418u: goto P_0c085418;
case 0x0c08541au: goto P_0c08541a;
case 0x0c08541cu: goto P_0c08541c;
case 0x0c08541eu: goto P_0c08541e;
case 0x0c085420u: goto P_0c085420;
case 0x0c085422u: goto P_0c085422;
case 0x0c085424u: goto P_0c085424;
case 0x0c085426u: goto P_0c085426;
case 0x0c085428u: goto P_0c085428;
case 0x0c08542au: goto P_0c08542a;
case 0x0c08542cu: goto P_0c08542c;
case 0x0c08542eu: goto P_0c08542e;
case 0x0c085430u: goto P_0c085430;
case 0x0c085432u: goto P_0c085432;
case 0x0c085434u: goto P_0c085434;
case 0x0c085436u: goto P_0c085436;
case 0x0c085438u: goto P_0c085438;
case 0x0c08543au: goto P_0c08543a;
case 0x0c08543cu: goto P_0c08543c;
case 0x0c08543eu: goto P_0c08543e;
case 0x0c085440u: goto P_0c085440;
case 0x0c085442u: goto P_0c085442;
case 0x0c085444u: goto P_0c085444;
case 0x0c085446u: goto P_0c085446;
case 0x0c085448u: goto P_0c085448;
case 0x0c08544au: goto P_0c08544a;
case 0x0c08544cu: goto P_0c08544c;
case 0x0c08544eu: goto P_0c08544e;
case 0x0c085450u: goto P_0c085450;
case 0x0c085452u: goto P_0c085452;
case 0x0c085480u: goto P_0c085480;
case 0x0c085482u: goto P_0c085482;
case 0x0c085484u: goto P_0c085484;
case 0x0c085486u: goto P_0c085486;
case 0x0c085488u: goto P_0c085488;
case 0x0c08548au: goto P_0c08548a;
case 0x0c08548cu: goto P_0c08548c;
case 0x0c08548eu: goto P_0c08548e;
case 0x0c085490u: goto P_0c085490;
case 0x0c085492u: goto P_0c085492;
case 0x0c085494u: goto P_0c085494;
case 0x0c085496u: goto P_0c085496;
case 0x0c085498u: goto P_0c085498;
case 0x0c08549au: goto P_0c08549a;
case 0x0c08549cu: goto P_0c08549c;
case 0x0c08549eu: goto P_0c08549e;
case 0x0c0854a0u: goto P_0c0854a0;
case 0x0c0854a2u: goto P_0c0854a2;
case 0x0c0854a4u: goto P_0c0854a4;
case 0x0c0854a6u: goto P_0c0854a6;
case 0x0c0854a8u: goto P_0c0854a8;
case 0x0c0854aau: goto P_0c0854aa;
case 0x0c0854acu: goto P_0c0854ac;
case 0x0c0854aeu: goto P_0c0854ae;
case 0x0c0854b0u: goto P_0c0854b0;
case 0x0c0854b2u: goto P_0c0854b2;
case 0x0c0854b4u: goto P_0c0854b4;
case 0x0c0854b6u: goto P_0c0854b6;
case 0x0c0854b8u: goto P_0c0854b8;
case 0x0c0854bau: goto P_0c0854ba;
case 0x0c0854bcu: goto P_0c0854bc;
case 0x0c0854beu: goto P_0c0854be;
case 0x0c0854c0u: goto P_0c0854c0;
case 0x0c0854c2u: goto P_0c0854c2;
case 0x0c0854c4u: goto P_0c0854c4;
case 0x0c0854c6u: goto P_0c0854c6;
case 0x0c0854c8u: goto P_0c0854c8;
case 0x0c0854cau: goto P_0c0854ca;
case 0x0c0854ccu: goto P_0c0854cc;
case 0x0c0854ceu: goto P_0c0854ce;
case 0x0c0854d0u: goto P_0c0854d0;
case 0x0c0854d2u: goto P_0c0854d2;
case 0x0c0854d4u: goto P_0c0854d4;
case 0x0c0854d6u: goto P_0c0854d6;
case 0x0c0854d8u: goto P_0c0854d8;
case 0x0c0854dau: goto P_0c0854da;
case 0x0c0854dcu: goto P_0c0854dc;
case 0x0c0854deu: goto P_0c0854de;
case 0x0c0854e0u: goto P_0c0854e0;
case 0x0c0854e2u: goto P_0c0854e2;
case 0x0c0854e4u: goto P_0c0854e4;
case 0x0c0854e6u: goto P_0c0854e6;
case 0x0c0854e8u: goto P_0c0854e8;
case 0x0c0854eau: goto P_0c0854ea;
case 0x0c0854ecu: goto P_0c0854ec;
case 0x0c0854eeu: goto P_0c0854ee;
case 0x0c0854f0u: goto P_0c0854f0;
case 0x0c0854f2u: goto P_0c0854f2;
case 0x0c0854f4u: goto P_0c0854f4;
case 0x0c0854f6u: goto P_0c0854f6;
case 0x0c0854f8u: goto P_0c0854f8;
case 0x0c0854fau: goto P_0c0854fa;
case 0x0c0854fcu: goto P_0c0854fc;
case 0x0c0854feu: goto P_0c0854fe;
case 0x0c085500u: goto P_0c085500;
case 0x0c085502u: goto P_0c085502;
case 0x0c085504u: goto P_0c085504;
case 0x0c085506u: goto P_0c085506;
case 0x0c085508u: goto P_0c085508;
case 0x0c08550au: goto P_0c08550a;
case 0x0c08550cu: goto P_0c08550c;
case 0x0c08550eu: goto P_0c08550e;
case 0x0c085510u: goto P_0c085510;
case 0x0c085512u: goto P_0c085512;
case 0x0c085514u: goto P_0c085514;
case 0x0c085516u: goto P_0c085516;
case 0x0c085518u: goto P_0c085518;
case 0x0c08551au: goto P_0c08551a;
case 0x0c08551cu: goto P_0c08551c;
case 0x0c08551eu: goto P_0c08551e;
case 0x0c085520u: goto P_0c085520;
case 0x0c085522u: goto P_0c085522;
case 0x0c085524u: goto P_0c085524;
case 0x0c085526u: goto P_0c085526;
case 0x0c085528u: goto P_0c085528;
case 0x0c08552au: goto P_0c08552a;
case 0x0c08552cu: goto P_0c08552c;
case 0x0c08552eu: goto P_0c08552e;
case 0x0c085530u: goto P_0c085530;
case 0x0c085532u: goto P_0c085532;
case 0x0c085534u: goto P_0c085534;
case 0x0c085536u: goto P_0c085536;
case 0x0c085538u: goto P_0c085538;
case 0x0c08553au: goto P_0c08553a;
case 0x0c08553cu: goto P_0c08553c;
case 0x0c08553eu: goto P_0c08553e;
case 0x0c085540u: goto P_0c085540;
case 0x0c085542u: goto P_0c085542;
case 0x0c085544u: goto P_0c085544;
case 0x0c085546u: goto P_0c085546;
case 0x0c085548u: goto P_0c085548;
case 0x0c08554au: goto P_0c08554a;
case 0x0c08554cu: goto P_0c08554c;
case 0x0c08554eu: goto P_0c08554e;
case 0x0c085550u: goto P_0c085550;
case 0x0c085552u: goto P_0c085552;
case 0x0c085554u: goto P_0c085554;
case 0x0c085556u: goto P_0c085556;
case 0x0c085558u: goto P_0c085558;
case 0x0c08555au: goto P_0c08555a;
case 0x0c08555cu: goto P_0c08555c;
case 0x0c08555eu: goto P_0c08555e;
case 0x0c085560u: goto P_0c085560;
case 0x0c085562u: goto P_0c085562;
case 0x0c085564u: goto P_0c085564;
case 0x0c085566u: goto P_0c085566;
case 0x0c085568u: goto P_0c085568;
case 0x0c08556au: goto P_0c08556a;
case 0x0c08556cu: goto P_0c08556c;
case 0x0c08556eu: goto P_0c08556e;
case 0x0c085570u: goto P_0c085570;
case 0x0c085572u: goto P_0c085572;
case 0x0c085574u: goto P_0c085574;
default: return vf3_matrix_family(target,s,ram);
}
P_0c085250: /* original 2fe6, guest PC 0x0c085250 */
if(!s->budget--) { s->failed_pc=0x0c085250u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085252;
P_0c085252: /* original 2fd6, guest PC 0x0c085252 */
if(!s->budget--) { s->failed_pc=0x0c085252u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085254;
P_0c085254: /* original 2fc6, guest PC 0x0c085254 */
if(!s->budget--) { s->failed_pc=0x0c085254u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085256;
P_0c085256: /* original 2fb6, guest PC 0x0c085256 */
if(!s->budget--) { s->failed_pc=0x0c085256u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085258;
P_0c085258: /* original 2fa6, guest PC 0x0c085258 */
if(!s->budget--) { s->failed_pc=0x0c085258u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08525a;
P_0c08525a: /* original 6a43, guest PC 0x0c08525a */
if(!s->budget--) { s->failed_pc=0x0c08525au; return 0; }
r[10]=r[4];
goto P_0c08525c;
P_0c08525c: /* original 2f96, guest PC 0x0c08525c */
if(!s->budget--) { s->failed_pc=0x0c08525cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08525e;
P_0c08525e: /* original 2f86, guest PC 0x0c08525e */
if(!s->budget--) { s->failed_pc=0x0c08525eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085260;
P_0c085260: /* original fffb, guest PC 0x0c085260 */
if(!s->budget--) { s->failed_pc=0x0c085260u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085262;
P_0c085262: /* original ffeb, guest PC 0x0c085262 */
if(!s->budget--) { s->failed_pc=0x0c085262u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085264;
P_0c085264: /* original ffdb, guest PC 0x0c085264 */
if(!s->budget--) { s->failed_pc=0x0c085264u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085266;
P_0c085266: /* original ffcb, guest PC 0x0c085266 */
if(!s->budget--) { s->failed_pc=0x0c085266u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085268;
P_0c085268: /* original d33d, guest PC 0x0c085268 */
if(!s->budget--) { s->failed_pc=0x0c085268u; return 0; }
r[3]=read(ram,0x0c085360u,4);
goto P_0c08526a;
P_0c08526a: /* original 4f22, guest PC 0x0c08526a */
if(!s->budget--) { s->failed_pc=0x0c08526au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08526c;
P_0c08526c: /* original 6030, guest PC 0x0c08526c */
if(!s->budget--) { s->failed_pc=0x0c08526cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08526e;
P_0c08526e: /* original 9e72, guest PC 0x0c08526e */
if(!s->budget--) { s->failed_pc=0x0c08526eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085356u,2);
goto P_0c085270;
P_0c085270: /* original 600c, guest PC 0x0c085270 */
if(!s->budget--) { s->failed_pc=0x0c085270u; return 0; }
r[0]=r[0]&255u;
goto P_0c085272;
P_0c085272: /* original 6da1, guest PC 0x0c085272 */
if(!s->budget--) { s->failed_pc=0x0c085272u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[13]=tmp;
goto P_0c085274;
P_0c085274: /* original c90f, guest PC 0x0c085274 */
if(!s->budget--) { s->failed_pc=0x0c085274u; return 0; }
r[0]&=15u;
goto P_0c085276;
P_0c085276: /* original d439, guest PC 0x0c085276 */
if(!s->budget--) { s->failed_pc=0x0c085276u; return 0; }
r[4]=read(ram,0x0c08535cu,4);
goto P_0c085278;
P_0c085278: /* original 880c, guest PC 0x0c085278 */
if(!s->budget--) { s->failed_pc=0x0c085278u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c08527a;
P_0c08527a: /* original 3eac, guest PC 0x0c08527a */
if(!s->budget--) { s->failed_pc=0x0c08527au; return 0; }
r[14]+=r[10];
goto P_0c08527c;
P_0c08527c: /* original 7ff8, guest PC 0x0c08527c */
if(!s->budget--) { s->failed_pc=0x0c08527cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08527e;
P_0c08527e: /* original 8f02, guest PC 0x0c08527e */
if(!s->budget--) { s->failed_pc=0x0c08527eu; return 0; }
cond=r[17]&1u;
r[13]=r[13]&65535u;
if(!cond) { goto P_0c085286; }
goto P_0c085282;
P_0c085280: /* original 6ddd, guest PC 0x0c085280 */
if(!s->budget--) { s->failed_pc=0x0c085280u; return 0; }
r[13]=r[13]&65535u;
goto P_0c085282;
P_0c085282: /* original a001, guest PC 0x0c085282 */
if(!s->budget--) { s->failed_pc=0x0c085282u; return 0; }
tmp=read(ram,r[4],4);
r[11]=tmp;
goto P_0c085288;
P_0c085284: /* original 6b42, guest PC 0x0c085284 */
if(!s->budget--) { s->failed_pc=0x0c085284u; return 0; }
tmp=read(ram,r[4],4);
r[11]=tmp;
goto P_0c085286;
P_0c085286: /* original 5b41, guest PC 0x0c085286 */
if(!s->budget--) { s->failed_pc=0x0c085286u; return 0; }
r[11]=read(ram,r[4]+4,4);
goto P_0c085288;
P_0c085288: /* original d336, guest PC 0x0c085288 */
if(!s->budget--) { s->failed_pc=0x0c085288u; return 0; }
r[3]=read(ram,0x0c085364u,4);
goto P_0c08528a;
P_0c08528a: /* original 430b, guest PC 0x0c08528a */
if(!s->budget--) { s->failed_pc=0x0c08528au; return 0; }
target=r[3];
r[16]=code_base|0x0c08528eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08528eu) { target=s->pc; goto dispatch; }
goto P_0c08528e;
P_0c08528c: /* original e400, guest PC 0x0c08528c */
if(!s->budget--) { s->failed_pc=0x0c08528cu; return 0; }
r[4]=0x00000000u;
goto P_0c08528e;
P_0c08528e: /* original a050, guest PC 0x0c08528e */
if(!s->budget--) { s->failed_pc=0x0c08528eu; return 0; }
r[9]=0x00000002u;
goto P_0c085332;
P_0c085290: /* original e902, guest PC 0x0c085290 */
if(!s->budget--) { s->failed_pc=0x0c085290u; return 0; }
r[9]=0x00000002u;
goto P_0c085292;
P_0c085292: /* original 2dd8, guest PC 0x0c085292 */
if(!s->budget--) { s->failed_pc=0x0c085292u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c085294;
P_0c085294: /* original 8948, guest PC 0x0c085294 */
if(!s->budget--) { s->failed_pc=0x0c085294u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085328; }
goto P_0c085296;
P_0c085296: /* original 6cb3, guest PC 0x0c085296 */
if(!s->budget--) { s->failed_pc=0x0c085296u; return 0; }
r[12]=r[11];
goto P_0c085298;
P_0c085298: /* original a044, guest PC 0x0c085298 */
if(!s->budget--) { s->failed_pc=0x0c085298u; return 0; }
r[13]=0x0000000fu;
goto P_0c085324;
P_0c08529a: /* original ed0f, guest PC 0x0c08529a */
if(!s->budget--) { s->failed_pc=0x0c08529au; return 0; }
r[13]=0x0000000fu;
goto P_0c08529c;
P_0c08529c: /* original e004, guest PC 0x0c08529c */
if(!s->budget--) { s->failed_pc=0x0c08529cu; return 0; }
r[0]=0x00000004u;
goto P_0c08529e;
P_0c08529e: /* original f2e8, guest PC 0x0c08529e */
if(!s->budget--) { s->failed_pc=0x0c08529eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
goto P_0c0852a0;
P_0c0852a0: /* original fce6, guest PC 0x0c0852a0 */
if(!s->budget--) { s->failed_pc=0x0c0852a0u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0852a2;
P_0c0852a2: /* original e008, guest PC 0x0c0852a2 */
if(!s->budget--) { s->failed_pc=0x0c0852a2u; return 0; }
r[0]=0x00000008u;
goto P_0c0852a4;
P_0c0852a4: /* original fde6, guest PC 0x0c0852a4 */
if(!s->budget--) { s->failed_pc=0x0c0852a4u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0852a6;
P_0c0852a6: /* original e00c, guest PC 0x0c0852a6 */
if(!s->budget--) { s->failed_pc=0x0c0852a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0852a8;
P_0c0852a8: /* original f5e6, guest PC 0x0c0852a8 */
if(!s->budget--) { s->failed_pc=0x0c0852a8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0852aa;
P_0c0852aa: /* original e010, guest PC 0x0c0852aa */
if(!s->budget--) { s->failed_pc=0x0c0852aau; return 0; }
r[0]=0x00000010u;
goto P_0c0852ac;
P_0c0852ac: /* original f6e6, guest PC 0x0c0852ac */
if(!s->budget--) { s->failed_pc=0x0c0852acu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0852ae;
P_0c0852ae: /* original e014, guest PC 0x0c0852ae */
if(!s->budget--) { s->failed_pc=0x0c0852aeu; return 0; }
r[0]=0x00000014u;
goto P_0c0852b0;
P_0c0852b0: /* original ffe6, guest PC 0x0c0852b0 */
if(!s->budget--) { s->failed_pc=0x0c0852b0u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0852b2;
P_0c0852b2: /* original e510, guest PC 0x0c0852b2 */
if(!s->budget--) { s->failed_pc=0x0c0852b2u; return 0; }
r[5]=0x00000010u;
goto P_0c0852b4;
P_0c0852b4: /* original 85ec, guest PC 0x0c0852b4 */
if(!s->budget--) { s->failed_pc=0x0c0852b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c0852b6;
P_0c0852b6: /* original 6403, guest PC 0x0c0852b6 */
if(!s->budget--) { s->failed_pc=0x0c0852b6u; return 0; }
r[4]=r[0];
goto P_0c0852b8;
P_0c0852b8: /* original 445a, guest PC 0x0c0852b8 */
if(!s->budget--) { s->failed_pc=0x0c0852b8u; return 0; }
r[53]=r[4];
goto P_0c0852ba;
P_0c0852ba: /* original c72b, guest PC 0x0c0852ba */
if(!s->budget--) { s->failed_pc=0x0c0852bau; return 0; }
r[0]=code_base|0x00085368u;
goto P_0c0852bc;
P_0c0852bc: /* original 6343, guest PC 0x0c0852bc */
if(!s->budget--) { s->failed_pc=0x0c0852bcu; return 0; }
r[3]=r[4];
goto P_0c0852be;
P_0c0852be: /* original 2358, guest PC 0x0c0852be */
if(!s->budget--) { s->failed_pc=0x0c0852beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0852c0;
P_0c0852c0: /* original f32d, guest PC 0x0c0852c0 */
if(!s->budget--) { s->failed_pc=0x0c0852c0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0852c2;
P_0c0852c2: /* original f03c, guest PC 0x0c0852c2 */
if(!s->budget--) { s->failed_pc=0x0c0852c2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0852c4;
P_0c0852c4: /* original f25e, guest PC 0x0c0852c4 */
if(!s->budget--) { s->failed_pc=0x0c0852c4u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c0852c6;
P_0c0852c6: /* original f43c, guest PC 0x0c0852c6 */
if(!s->budget--) { s->failed_pc=0x0c0852c6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0852c8;
P_0c0852c8: /* original f3dc, guest PC 0x0c0852c8 */
if(!s->budget--) { s->failed_pc=0x0c0852c8u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0852ca;
P_0c0852ca: /* original f36e, guest PC 0x0c0852ca */
if(!s->budget--) { s->failed_pc=0x0c0852cau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0852cc;
P_0c0852cc: /* original f508, guest PC 0x0c0852cc */
if(!s->budget--) { s->failed_pc=0x0c0852ccu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0852ce;
P_0c0852ce: /* original fe2c, guest PC 0x0c0852ce */
if(!s->budget--) { s->failed_pc=0x0c0852ceu; return 0; }
vf3_matrix_move(s,14,2);
goto P_0c0852d0;
P_0c0852d0: /* original fd3c, guest PC 0x0c0852d0 */
if(!s->budget--) { s->failed_pc=0x0c0852d0u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0852d2;
P_0c0852d2: /* original 8f21, guest PC 0x0c0852d2 */
if(!s->budget--) { s->failed_pc=0x0c0852d2u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!cond) { goto P_0c085318; }
goto P_0c0852d6;
P_0c0852d4: /* original f452, guest PC 0x0c0852d4 */
if(!s->budget--) { s->failed_pc=0x0c0852d4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0852d6;
P_0c0852d6: /* original 6043, guest PC 0x0c0852d6 */
if(!s->budget--) { s->failed_pc=0x0c0852d6u; return 0; }
r[0]=r[4];
goto P_0c0852d8;
P_0c0852d8: /* original 4000, guest PC 0x0c0852d8 */
if(!s->budget--) { s->failed_pc=0x0c0852d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0852da;
P_0c0852da: /* original 03cd, guest PC 0x0c0852da */
if(!s->budget--) { s->failed_pc=0x0c0852dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0852dc;
P_0c0852dc: /* original 1f31, guest PC 0x0c0852dc */
if(!s->budget--) { s->failed_pc=0x0c0852dcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0852de;
P_0c0852de: /* original d423, guest PC 0x0c0852de */
if(!s->budget--) { s->failed_pc=0x0c0852deu; return 0; }
r[4]=read(ram,0x0c08536cu,4);
goto P_0c0852e0;
P_0c0852e0: /* original 5448, guest PC 0x0c0852e0 */
if(!s->budget--) { s->failed_pc=0x0c0852e0u; return 0; }
r[4]=read(ram,r[4]+32,4);
goto P_0c0852e2;
P_0c0852e2: /* original 854f, guest PC 0x0c0852e2 */
if(!s->budget--) { s->failed_pc=0x0c0852e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0852e4;
P_0c0852e4: /* original 2f02, guest PC 0x0c0852e4 */
if(!s->budget--) { s->failed_pc=0x0c0852e4u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0852e6;
P_0c0852e6: /* original 854e, guest PC 0x0c0852e6 */
if(!s->budget--) { s->failed_pc=0x0c0852e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0852e8;
P_0c0852e8: /* original d321, guest PC 0x0c0852e8 */
if(!s->budget--) { s->failed_pc=0x0c0852e8u; return 0; }
r[3]=read(ram,0x0c085370u,4);
goto P_0c0852ea;
P_0c0852ea: /* original 6803, guest PC 0x0c0852ea */
if(!s->budget--) { s->failed_pc=0x0c0852eau; return 0; }
r[8]=r[0];
goto P_0c0852ec;
P_0c0852ec: /* original 430b, guest PC 0x0c0852ec */
if(!s->budget--) { s->failed_pc=0x0c0852ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0852f0u;
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0852f0u) { target=s->pc; goto dispatch; }
goto P_0c0852f0;
P_0c0852ee: /* original fc40, guest PC 0x0c0852ee */
if(!s->budget--) { s->failed_pc=0x0c0852eeu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
goto P_0c0852f0;
P_0c0852f0: /* original d220, guest PC 0x0c0852f0 */
if(!s->budget--) { s->failed_pc=0x0c0852f0u; return 0; }
r[2]=read(ram,0x0c085374u,4);
goto P_0c0852f2;
P_0c0852f2: /* original f6dc, guest PC 0x0c0852f2 */
if(!s->budget--) { s->failed_pc=0x0c0852f2u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0852f4;
P_0c0852f4: /* original f5cc, guest PC 0x0c0852f4 */
if(!s->budget--) { s->failed_pc=0x0c0852f4u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0852f6;
P_0c0852f6: /* original f64d, guest PC 0x0c0852f6 */
if(!s->budget--) { s->failed_pc=0x0c0852f6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0852f8;
P_0c0852f8: /* original 420b, guest PC 0x0c0852f8 */
if(!s->budget--) { s->failed_pc=0x0c0852f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0852fcu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0852fcu) { target=s->pc; goto dispatch; }
goto P_0c0852fc;
P_0c0852fa: /* original f4ec, guest PC 0x0c0852fa */
if(!s->budget--) { s->failed_pc=0x0c0852fau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0852fc;
P_0c0852fc: /* original d31e, guest PC 0x0c0852fc */
if(!s->budget--) { s->failed_pc=0x0c0852fcu; return 0; }
r[3]=read(ram,0x0c085378u,4);
goto P_0c0852fe;
P_0c0852fe: /* original 430b, guest PC 0x0c0852fe */
if(!s->budget--) { s->failed_pc=0x0c0852feu; return 0; }
target=r[3];
r[16]=code_base|0x0c085302u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085302u) { target=s->pc; goto dispatch; }
goto P_0c085302;
P_0c085300: /* original 64f2, guest PC 0x0c085300 */
if(!s->budget--) { s->failed_pc=0x0c085300u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c085302;
P_0c085302: /* original d21e, guest PC 0x0c085302 */
if(!s->budget--) { s->failed_pc=0x0c085302u; return 0; }
r[2]=read(ram,0x0c08537cu,4);
goto P_0c085304;
P_0c085304: /* original 420b, guest PC 0x0c085304 */
if(!s->budget--) { s->failed_pc=0x0c085304u; return 0; }
target=r[2];
r[16]=code_base|0x0c085308u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085308u) { target=s->pc; goto dispatch; }
goto P_0c085308;
P_0c085306: /* original 6483, guest PC 0x0c085306 */
if(!s->budget--) { s->failed_pc=0x0c085306u; return 0; }
r[4]=r[8];
goto P_0c085308;
P_0c085308: /* original d81d, guest PC 0x0c085308 */
if(!s->budget--) { s->failed_pc=0x0c085308u; return 0; }
r[8]=read(ram,0x0c085380u,4);
goto P_0c08530a;
P_0c08530a: /* original f5fc, guest PC 0x0c08530a */
if(!s->budget--) { s->failed_pc=0x0c08530au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08530c;
P_0c08530c: /* original f6fc, guest PC 0x0c08530c */
if(!s->budget--) { s->failed_pc=0x0c08530cu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c08530e;
P_0c08530e: /* original 480b, guest PC 0x0c08530e */
if(!s->budget--) { s->failed_pc=0x0c08530eu; return 0; }
target=r[8];
r[16]=code_base|0x0c085312u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085312u) { target=s->pc; goto dispatch; }
goto P_0c085312;
P_0c085310: /* original f4fc, guest PC 0x0c085310 */
if(!s->budget--) { s->failed_pc=0x0c085310u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085312;
P_0c085312: /* original d81c, guest PC 0x0c085312 */
if(!s->budget--) { s->failed_pc=0x0c085312u; return 0; }
r[8]=read(ram,0x0c085384u,4);
goto P_0c085314;
P_0c085314: /* original 480b, guest PC 0x0c085314 */
if(!s->budget--) { s->failed_pc=0x0c085314u; return 0; }
target=r[8];
r[16]=code_base|0x0c085318u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085318u) { target=s->pc; goto dispatch; }
goto P_0c085318;
P_0c085316: /* original 54f1, guest PC 0x0c085316 */
if(!s->budget--) { s->failed_pc=0x0c085316u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c085318;
P_0c085318: /* original 60d3, guest PC 0x0c085318 */
if(!s->budget--) { s->failed_pc=0x0c085318u; return 0; }
r[0]=r[13];
goto P_0c08531a;
P_0c08531a: /* original 880f, guest PC 0x0c08531a */
if(!s->budget--) { s->failed_pc=0x0c08531au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c08531c;
P_0c08531c: /* original 8f01, guest PC 0x0c08531c */
if(!s->budget--) { s->failed_pc=0x0c08531cu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000001cu;
if(!cond) { goto P_0c085322; }
goto P_0c085320;
P_0c08531e: /* original 7e1c, guest PC 0x0c08531e */
if(!s->budget--) { s->failed_pc=0x0c08531eu; return 0; }
r[14]+=0x0000001cu;
goto P_0c085320;
P_0c085320: /* original 6cb3, guest PC 0x0c085320 */
if(!s->budget--) { s->failed_pc=0x0c085320u; return 0; }
r[12]=r[11];
goto P_0c085322;
P_0c085322: /* original 7dff, guest PC 0x0c085322 */
if(!s->budget--) { s->failed_pc=0x0c085322u; return 0; }
r[13]+=0xffffffffu;
goto P_0c085324;
P_0c085324: /* original 2dd8, guest PC 0x0c085324 */
if(!s->budget--) { s->failed_pc=0x0c085324u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c085326;
P_0c085326: /* original 8bb9, guest PC 0x0c085326 */
if(!s->budget--) { s->failed_pc=0x0c085326u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08529c; }
goto P_0c085328;
P_0c085328: /* original 9e16, guest PC 0x0c085328 */
if(!s->budget--) { s->failed_pc=0x0c085328u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085358u,2);
goto P_0c08532a;
P_0c08532a: /* original 79ff, guest PC 0x0c08532a */
if(!s->budget--) { s->failed_pc=0x0c08532au; return 0; }
r[9]+=0xffffffffu;
goto P_0c08532c;
P_0c08532c: /* original 85a1, guest PC 0x0c08532c */
if(!s->budget--) { s->failed_pc=0x0c08532cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+2,2);
goto P_0c08532e;
P_0c08532e: /* original 3eac, guest PC 0x0c08532e */
if(!s->budget--) { s->failed_pc=0x0c08532eu; return 0; }
r[14]+=r[10];
goto P_0c085330;
P_0c085330: /* original 6d0d, guest PC 0x0c085330 */
if(!s->budget--) { s->failed_pc=0x0c085330u; return 0; }
r[13]=r[0]&65535u;
goto P_0c085332;
P_0c085332: /* original 2998, guest PC 0x0c085332 */
if(!s->budget--) { s->failed_pc=0x0c085332u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c085334;
P_0c085334: /* original 8bad, guest PC 0x0c085334 */
if(!s->budget--) { s->failed_pc=0x0c085334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085292; }
goto P_0c085336;
P_0c085336: /* original 7f08, guest PC 0x0c085336 */
if(!s->budget--) { s->failed_pc=0x0c085336u; return 0; }
r[15]+=0x00000008u;
goto P_0c085338;
P_0c085338: /* original d213, guest PC 0x0c085338 */
if(!s->budget--) { s->failed_pc=0x0c085338u; return 0; }
r[2]=read(ram,0x0c085388u,4);
goto P_0c08533a;
P_0c08533a: /* original 4f26, guest PC 0x0c08533a */
if(!s->budget--) { s->failed_pc=0x0c08533au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08533c;
P_0c08533c: /* original e401, guest PC 0x0c08533c */
if(!s->budget--) { s->failed_pc=0x0c08533cu; return 0; }
r[4]=0x00000001u;
goto P_0c08533e;
P_0c08533e: /* original fcf9, guest PC 0x0c08533e */
if(!s->budget--) { s->failed_pc=0x0c08533eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085340;
P_0c085340: /* original fdf9, guest PC 0x0c085340 */
if(!s->budget--) { s->failed_pc=0x0c085340u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085342;
P_0c085342: /* original fef9, guest PC 0x0c085342 */
if(!s->budget--) { s->failed_pc=0x0c085342u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085344;
P_0c085344: /* original fff9, guest PC 0x0c085344 */
if(!s->budget--) { s->failed_pc=0x0c085344u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085346;
P_0c085346: /* original 68f6, guest PC 0x0c085346 */
if(!s->budget--) { s->failed_pc=0x0c085346u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085348;
P_0c085348: /* original 69f6, guest PC 0x0c085348 */
if(!s->budget--) { s->failed_pc=0x0c085348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08534a;
P_0c08534a: /* original 6af6, guest PC 0x0c08534a */
if(!s->budget--) { s->failed_pc=0x0c08534au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08534c;
P_0c08534c: /* original 6bf6, guest PC 0x0c08534c */
if(!s->budget--) { s->failed_pc=0x0c08534cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08534e;
P_0c08534e: /* original 6cf6, guest PC 0x0c08534e */
if(!s->budget--) { s->failed_pc=0x0c08534eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085350;
P_0c085350: /* original 6df6, guest PC 0x0c085350 */
if(!s->budget--) { s->failed_pc=0x0c085350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085352;
P_0c085352: /* original 422b, guest PC 0x0c085352 */
if(!s->budget--) { s->failed_pc=0x0c085352u; return 0; }
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
P_0c085354: /* original 6ef6, guest PC 0x0c085354 */
if(!s->budget--) { s->failed_pc=0x0c085354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085356u; return 0; } return 1;
P_0c08538c: /* original 2fe6, guest PC 0x0c08538c */
if(!s->budget--) { s->failed_pc=0x0c08538cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08538e;
P_0c08538e: /* original 6e43, guest PC 0x0c08538e */
if(!s->budget--) { s->failed_pc=0x0c08538eu; return 0; }
r[14]=r[4];
goto P_0c085390;
P_0c085390: /* original 2fd6, guest PC 0x0c085390 */
if(!s->budget--) { s->failed_pc=0x0c085390u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085392;
P_0c085392: /* original 2fc6, guest PC 0x0c085392 */
if(!s->budget--) { s->failed_pc=0x0c085392u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085394;
P_0c085394: /* original ec0d, guest PC 0x0c085394 */
if(!s->budget--) { s->failed_pc=0x0c085394u; return 0; }
r[12]=0x0000000du;
goto P_0c085396;
P_0c085396: /* original 2fb6, guest PC 0x0c085396 */
if(!s->budget--) { s->failed_pc=0x0c085396u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085398;
P_0c085398: /* original 2fa6, guest PC 0x0c085398 */
if(!s->budget--) { s->failed_pc=0x0c085398u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08539a;
P_0c08539a: /* original 2f96, guest PC 0x0c08539a */
if(!s->budget--) { s->failed_pc=0x0c08539au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08539c;
P_0c08539c: /* original fffb, guest PC 0x0c08539c */
if(!s->budget--) { s->failed_pc=0x0c08539cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08539e;
P_0c08539e: /* original ffeb, guest PC 0x0c08539e */
if(!s->budget--) { s->failed_pc=0x0c08539eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0853a0;
P_0c0853a0: /* original ffdb, guest PC 0x0c0853a0 */
if(!s->budget--) { s->failed_pc=0x0c0853a0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0853a2;
P_0c0853a2: /* original 4f22, guest PC 0x0c0853a2 */
if(!s->budget--) { s->failed_pc=0x0c0853a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0853a4;
P_0c0853a4: /* original da2d, guest PC 0x0c0853a4 */
if(!s->budget--) { s->failed_pc=0x0c0853a4u; return 0; }
r[10]=read(ram,0x0c08545cu,4);
goto P_0c0853a6;
P_0c0853a6: /* original d92e, guest PC 0x0c0853a6 */
if(!s->budget--) { s->failed_pc=0x0c0853a6u; return 0; }
r[9]=read(ram,0x0c085460u,4);
goto P_0c0853a8;
P_0c0853a8: /* original dd2b, guest PC 0x0c0853a8 */
if(!s->budget--) { s->failed_pc=0x0c0853a8u; return 0; }
r[13]=read(ram,0x0c085458u,4);
goto P_0c0853aa;
P_0c0853aa: /* original fe8d, guest PC 0x0c0853aa */
if(!s->budget--) { s->failed_pc=0x0c0853aau; return 0; }
fr[14]=0;
goto P_0c0853ac;
P_0c0853ac: /* original e010, guest PC 0x0c0853ac */
if(!s->budget--) { s->failed_pc=0x0c0853acu; return 0; }
r[0]=0x00000010u;
goto P_0c0853ae;
P_0c0853ae: /* original fdd6, guest PC 0x0c0853ae */
if(!s->budget--) { s->failed_pc=0x0c0853aeu; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c0853b0;
P_0c0853b0: /* original e014, guest PC 0x0c0853b0 */
if(!s->budget--) { s->failed_pc=0x0c0853b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0853b2;
P_0c0853b2: /* original ffd6, guest PC 0x0c0853b2 */
if(!s->budget--) { s->failed_pc=0x0c0853b2u; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c0853b4;
P_0c0853b4: /* original 7d20, guest PC 0x0c0853b4 */
if(!s->budget--) { s->failed_pc=0x0c0853b4u; return 0; }
r[13]+=0x00000020u;
goto P_0c0853b6;
P_0c0853b6: /* original 490b, guest PC 0x0c0853b6 */
if(!s->budget--) { s->failed_pc=0x0c0853b6u; return 0; }
target=r[9];
r[16]=code_base|0x0c0853bau;
tmp=read(ram,r[10],4);
r[10]+=4;
r[11]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0853bau) { target=s->pc; goto dispatch; }
goto P_0c0853ba;
P_0c0853b8: /* original 6ba6, guest PC 0x0c0853b8 */
if(!s->budget--) { s->failed_pc=0x0c0853b8u; return 0; }
tmp=read(ram,r[10],4);
r[10]+=4;
r[11]=tmp;
goto P_0c0853ba;
P_0c0853ba: /* original 81e6, guest PC 0x0c0853ba */
if(!s->budget--) { s->failed_pc=0x0c0853bau; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0853bc;
P_0c0853bc: /* original 6403, guest PC 0x0c0853bc */
if(!s->budget--) { s->failed_pc=0x0c0853bcu; return 0; }
r[4]=r[0];
goto P_0c0853be;
P_0c0853be: /* original e004, guest PC 0x0c0853be */
if(!s->budget--) { s->failed_pc=0x0c0853beu; return 0; }
r[0]=0x00000004u;
goto P_0c0853c0;
P_0c0853c0: /* original 1eb5, guest PC 0x0c0853c0 */
if(!s->budget--) { s->failed_pc=0x0c0853c0u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c0853c2;
P_0c0853c2: /* original 4c10, guest PC 0x0c0853c2 */
if(!s->budget--) { s->failed_pc=0x0c0853c2u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c0853c4;
P_0c0853c4: /* original feda, guest PC 0x0c0853c4 */
if(!s->budget--) { s->failed_pc=0x0c0853c4u; return 0; }
vf3_matrix_store(s,ram,13,r[14]);
goto P_0c0853c6;
P_0c0853c6: /* original fee7, guest PC 0x0c0853c6 */
if(!s->budget--) { s->failed_pc=0x0c0853c6u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c0853c8;
P_0c0853c8: /* original e008, guest PC 0x0c0853c8 */
if(!s->budget--) { s->failed_pc=0x0c0853c8u; return 0; }
r[0]=0x00000008u;
goto P_0c0853ca;
P_0c0853ca: /* original fef7, guest PC 0x0c0853ca */
if(!s->budget--) { s->failed_pc=0x0c0853cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0853cc;
P_0c0853cc: /* original 8fee, guest PC 0x0c0853cc */
if(!s->budget--) { s->failed_pc=0x0c0853ccu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c0853ac; }
goto P_0c0853d0;
P_0c0853ce: /* original 7e18, guest PC 0x0c0853ce */
if(!s->budget--) { s->failed_pc=0x0c0853ceu; return 0; }
r[14]+=0x00000018u;
goto P_0c0853d0;
P_0c0853d0: /* original 4f26, guest PC 0x0c0853d0 */
if(!s->budget--) { s->failed_pc=0x0c0853d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0853d2;
P_0c0853d2: /* original fdf9, guest PC 0x0c0853d2 */
if(!s->budget--) { s->failed_pc=0x0c0853d2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d4;
P_0c0853d4: /* original fef9, guest PC 0x0c0853d4 */
if(!s->budget--) { s->failed_pc=0x0c0853d4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d6;
P_0c0853d6: /* original fff9, guest PC 0x0c0853d6 */
if(!s->budget--) { s->failed_pc=0x0c0853d6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0853d8;
P_0c0853d8: /* original 69f6, guest PC 0x0c0853d8 */
if(!s->budget--) { s->failed_pc=0x0c0853d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0853da;
P_0c0853da: /* original 6af6, guest PC 0x0c0853da */
if(!s->budget--) { s->failed_pc=0x0c0853dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0853dc;
P_0c0853dc: /* original 6bf6, guest PC 0x0c0853dc */
if(!s->budget--) { s->failed_pc=0x0c0853dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0853de;
P_0c0853de: /* original 6cf6, guest PC 0x0c0853de */
if(!s->budget--) { s->failed_pc=0x0c0853deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0853e0;
P_0c0853e0: /* original 6df6, guest PC 0x0c0853e0 */
if(!s->budget--) { s->failed_pc=0x0c0853e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0853e2;
P_0c0853e2: /* original 000b, guest PC 0x0c0853e2 */
if(!s->budget--) { s->failed_pc=0x0c0853e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0853e4: /* original 6ef6, guest PC 0x0c0853e4 */
if(!s->budget--) { s->failed_pc=0x0c0853e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0853e6;
P_0c0853e6: /* original 2fe6, guest PC 0x0c0853e6 */
if(!s->budget--) { s->failed_pc=0x0c0853e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853e8;
P_0c0853e8: /* original 2fd6, guest PC 0x0c0853e8 */
if(!s->budget--) { s->failed_pc=0x0c0853e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ea;
P_0c0853ea: /* original 2fc6, guest PC 0x0c0853ea */
if(!s->budget--) { s->failed_pc=0x0c0853eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ec;
P_0c0853ec: /* original 2fb6, guest PC 0x0c0853ec */
if(!s->budget--) { s->failed_pc=0x0c0853ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853ee;
P_0c0853ee: /* original 2fa6, guest PC 0x0c0853ee */
if(!s->budget--) { s->failed_pc=0x0c0853eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f0;
P_0c0853f0: /* original 2f96, guest PC 0x0c0853f0 */
if(!s->budget--) { s->failed_pc=0x0c0853f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f2;
P_0c0853f2: /* original 2f86, guest PC 0x0c0853f2 */
if(!s->budget--) { s->failed_pc=0x0c0853f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0853f4;
P_0c0853f4: /* original fffb, guest PC 0x0c0853f4 */
if(!s->budget--) { s->failed_pc=0x0c0853f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0853f6;
P_0c0853f6: /* original ffeb, guest PC 0x0c0853f6 */
if(!s->budget--) { s->failed_pc=0x0c0853f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0853f8;
P_0c0853f8: /* original ffdb, guest PC 0x0c0853f8 */
if(!s->budget--) { s->failed_pc=0x0c0853f8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0853fa;
P_0c0853fa: /* original ffcb, guest PC 0x0c0853fa */
if(!s->budget--) { s->failed_pc=0x0c0853fau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0853fc;
P_0c0853fc: /* original d11a, guest PC 0x0c0853fc */
if(!s->budget--) { s->failed_pc=0x0c0853fcu; return 0; }
r[1]=read(ram,0x0c085468u,4);
goto P_0c0853fe;
P_0c0853fe: /* original 4f22, guest PC 0x0c0853fe */
if(!s->budget--) { s->failed_pc=0x0c0853feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085400;
P_0c085400: /* original d318, guest PC 0x0c085400 */
if(!s->budget--) { s->failed_pc=0x0c085400u; return 0; }
r[3]=read(ram,0x0c085464u,4);
goto P_0c085402;
P_0c085402: /* original 6212, guest PC 0x0c085402 */
if(!s->budget--) { s->failed_pc=0x0c085402u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085404;
P_0c085404: /* original 7ff0, guest PC 0x0c085404 */
if(!s->budget--) { s->failed_pc=0x0c085404u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c085406;
P_0c085406: /* original 2238, guest PC 0x0c085406 */
if(!s->budget--) { s->failed_pc=0x0c085406u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085408;
P_0c085408: /* original 8d02, guest PC 0x0c085408 */
if(!s->budget--) { s->failed_pc=0x0c085408u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(cond) { goto P_0c085410; }
goto P_0c08540c;
P_0c08540a: /* original eb00, guest PC 0x0c08540a */
if(!s->budget--) { s->failed_pc=0x0c08540au; return 0; }
r[11]=0x00000000u;
goto P_0c08540c;
P_0c08540c: /* original a0a5, guest PC 0x0c08540c */
if(!s->budget--) { s->failed_pc=0x0c08540cu; return 0; }
goto P_0c08555a;
P_0c08540e: /* original 0009, guest PC 0x0c08540e */
if(!s->budget--) { s->failed_pc=0x0c08540eu; return 0; }
goto P_0c085410;
P_0c085410: /* original d316, guest PC 0x0c085410 */
if(!s->budget--) { s->failed_pc=0x0c085410u; return 0; }
r[3]=read(ram,0x0c08546cu,4);
goto P_0c085412;
P_0c085412: /* original 6543, guest PC 0x0c085412 */
if(!s->budget--) { s->failed_pc=0x0c085412u; return 0; }
r[5]=r[4];
goto P_0c085414;
P_0c085414: /* original d216, guest PC 0x0c085414 */
if(!s->budget--) { s->failed_pc=0x0c085414u; return 0; }
r[2]=read(ram,0x0c085470u,4);
goto P_0c085416;
P_0c085416: /* original 6a32, guest PC 0x0c085416 */
if(!s->budget--) { s->failed_pc=0x0c085416u; return 0; }
tmp=read(ram,r[3],4);
r[10]=tmp;
goto P_0c085418;
P_0c085418: /* original 85af, guest PC 0x0c085418 */
if(!s->budget--) { s->failed_pc=0x0c085418u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c08541a;
P_0c08541a: /* original 6403, guest PC 0x0c08541a */
if(!s->budget--) { s->failed_pc=0x0c08541au; return 0; }
r[4]=r[0];
goto P_0c08541c;
P_0c08541c: /* original 3427, guest PC 0x0c08541c */
if(!s->budget--) { s->failed_pc=0x0c08541cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[2])!=0);
goto P_0c08541e;
P_0c08541e: /* original 8b02, guest PC 0x0c08541e */
if(!s->budget--) { s->failed_pc=0x0c08541eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085426; }
goto P_0c085420;
P_0c085420: /* original d80e, guest PC 0x0c085420 */
if(!s->budget--) { s->failed_pc=0x0c085420u; return 0; }
r[8]=read(ram,0x0c08545cu,4);
goto P_0c085422;
P_0c085422: /* original a001, guest PC 0x0c085422 */
if(!s->budget--) { s->failed_pc=0x0c085422u; return 0; }
goto P_0c085428;
P_0c085424: /* original 0009, guest PC 0x0c085424 */
if(!s->budget--) { s->failed_pc=0x0c085424u; return 0; }
goto P_0c085426;
P_0c085426: /* original d813, guest PC 0x0c085426 */
if(!s->budget--) { s->failed_pc=0x0c085426u; return 0; }
r[8]=read(ram,0x0c085474u,4);
goto P_0c085428;
P_0c085428: /* original dc0b, guest PC 0x0c085428 */
if(!s->budget--) { s->failed_pc=0x0c085428u; return 0; }
r[12]=read(ram,0x0c085458u,4);
goto P_0c08542a;
P_0c08542a: /* original 6e53, guest PC 0x0c08542a */
if(!s->budget--) { s->failed_pc=0x0c08542au; return 0; }
r[14]=r[5];
goto P_0c08542c;
P_0c08542c: /* original 2fb2, guest PC 0x0c08542c */
if(!s->budget--) { s->failed_pc=0x0c08542cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c08542e;
P_0c08542e: /* original d312, guest PC 0x0c08542e */
if(!s->budget--) { s->failed_pc=0x0c08542eu; return 0; }
r[3]=read(ram,0x0c085478u,4);
goto P_0c085430;
P_0c085430: /* original a08d, guest PC 0x0c085430 */
if(!s->budget--) { s->failed_pc=0x0c085430u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08554e;
P_0c085432: /* original 1f32, guest PC 0x0c085432 */
if(!s->budget--) { s->failed_pc=0x0c085432u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c085434;
P_0c085434: /* original e008, guest PC 0x0c085434 */
if(!s->budget--) { s->failed_pc=0x0c085434u; return 0; }
r[0]=0x00000008u;
goto P_0c085436;
P_0c085436: /* original fee6, guest PC 0x0c085436 */
if(!s->budget--) { s->failed_pc=0x0c085436u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c085438;
P_0c085438: /* original 85e6, guest PC 0x0c085438 */
if(!s->budget--) { s->failed_pc=0x0c085438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c08543a;
P_0c08543a: /* original 6d03, guest PC 0x0c08543a */
if(!s->budget--) { s->failed_pc=0x0c08543au; return 0; }
r[13]=r[0];
goto P_0c08543c;
P_0c08543c: /* original 2dd8, guest PC 0x0c08543c */
if(!s->budget--) { s->failed_pc=0x0c08543cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c08543e;
P_0c08543e: /* original 8f1f, guest PC 0x0c08543e */
if(!s->budget--) { s->failed_pc=0x0c08543eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]);
if(!cond) { goto P_0c085480; }
goto P_0c085442;
P_0c085440: /* original ffe8, guest PC 0x0c085440 */
if(!s->budget--) { s->failed_pc=0x0c085440u; return 0; }
vf3_matrix_load(s,ram,15,r[14]);
goto P_0c085442;
P_0c085442: /* original d10e, guest PC 0x0c085442 */
if(!s->budget--) { s->failed_pc=0x0c085442u; return 0; }
r[1]=read(ram,0x0c08547cu,4);
goto P_0c085444;
P_0c085444: /* original 9206, guest PC 0x0c085444 */
if(!s->budget--) { s->failed_pc=0x0c085444u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085454u,2);
goto P_0c085446;
P_0c085446: /* original 6312, guest PC 0x0c085446 */
if(!s->budget--) { s->failed_pc=0x0c085446u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c085448;
P_0c085448: /* original 3327, guest PC 0x0c085448 */
if(!s->budget--) { s->failed_pc=0x0c085448u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c08544a;
P_0c08544a: /* original 8b19, guest PC 0x0c08544a */
if(!s->budget--) { s->failed_pc=0x0c08544au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085480; }
goto P_0c08544c;
P_0c08544c: /* original 50f2, guest PC 0x0c08544c */
if(!s->budget--) { s->failed_pc=0x0c08544cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c08544e;
P_0c08544e: /* original 6001, guest PC 0x0c08544e */
if(!s->budget--) { s->failed_pc=0x0c08544eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[0]=tmp;
goto P_0c085450;
P_0c085450: /* original a079, guest PC 0x0c085450 */
if(!s->budget--) { s->failed_pc=0x0c085450u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c085546;
P_0c085452: /* original 81e7, guest PC 0x0c085452 */
if(!s->budget--) { s->failed_pc=0x0c085452u; return 0; }
write(ram,r[14]+14,r[0],2);
if(!vf3_matrix_family(0x0c085454u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085454u; return 0; } return 1;
P_0c085480: /* original 85e8, guest PC 0x0c085480 */
if(!s->budget--) { s->failed_pc=0x0c085480u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c085482;
P_0c085482: /* original f4c8, guest PC 0x0c085482 */
if(!s->budget--) { s->failed_pc=0x0c085482u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c085484;
P_0c085484: /* original 6903, guest PC 0x0c085484 */
if(!s->budget--) { s->failed_pc=0x0c085484u; return 0; }
r[9]=r[0];
goto P_0c085486;
P_0c085486: /* original e010, guest PC 0x0c085486 */
if(!s->budget--) { s->failed_pc=0x0c085486u; return 0; }
r[0]=0x00000010u;
goto P_0c085488;
P_0c085488: /* original fca6, guest PC 0x0c085488 */
if(!s->budget--) { s->failed_pc=0x0c085488u; return 0; }
vf3_matrix_load(s,ram,12,r[10]+r[0]);
goto P_0c08548a;
P_0c08548a: /* original e018, guest PC 0x0c08548a */
if(!s->budget--) { s->failed_pc=0x0c08548au; return 0; }
r[0]=0x00000018u;
goto P_0c08548c;
P_0c08548c: /* original fda6, guest PC 0x0c08548c */
if(!s->budget--) { s->failed_pc=0x0c08548cu; return 0; }
vf3_matrix_load(s,ram,13,r[10]+r[0]);
goto P_0c08548e;
P_0c08548e: /* original ff40, guest PC 0x0c08548e */
if(!s->budget--) { s->failed_pc=0x0c08548eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c085490;
P_0c085490: /* original 85af, guest PC 0x0c085490 */
if(!s->budget--) { s->failed_pc=0x0c085490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+30,2);
goto P_0c085492;
P_0c085492: /* original 53c6, guest PC 0x0c085492 */
if(!s->budget--) { s->failed_pc=0x0c085492u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c085494;
P_0c085494: /* original 6503, guest PC 0x0c085494 */
if(!s->budget--) { s->failed_pc=0x0c085494u; return 0; }
r[5]=r[0];
goto P_0c085496;
P_0c085496: /* original e004, guest PC 0x0c085496 */
if(!s->budget--) { s->failed_pc=0x0c085496u; return 0; }
r[0]=0x00000004u;
goto P_0c085498;
P_0c085498: /* original f5c6, guest PC 0x0c085498 */
if(!s->budget--) { s->failed_pc=0x0c085498u; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c08549a;
P_0c08549a: /* original e008, guest PC 0x0c08549a */
if(!s->budget--) { s->failed_pc=0x0c08549au; return 0; }
r[0]=0x00000008u;
goto P_0c08549c;
P_0c08549c: /* original f9c6, guest PC 0x0c08549c */
if(!s->budget--) { s->failed_pc=0x0c08549cu; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c08549e;
P_0c08549e: /* original e00c, guest PC 0x0c08549e */
if(!s->budget--) { s->failed_pc=0x0c08549eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0854a0;
P_0c0854a0: /* original f7c6, guest PC 0x0c0854a0 */
if(!s->budget--) { s->failed_pc=0x0c0854a0u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c0854a2;
P_0c0854a2: /* original e010, guest PC 0x0c0854a2 */
if(!s->budget--) { s->failed_pc=0x0c0854a2u; return 0; }
r[0]=0x00000010u;
goto P_0c0854a4;
P_0c0854a4: /* original f8c6, guest PC 0x0c0854a4 */
if(!s->budget--) { s->failed_pc=0x0c0854a4u; return 0; }
vf3_matrix_load(s,ram,8,r[12]+r[0]);
goto P_0c0854a6;
P_0c0854a6: /* original ff95, guest PC 0x0c0854a6 */
if(!s->budget--) { s->failed_pc=0x0c0854a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[9]))!=0);
goto P_0c0854a8;
P_0c0854a8: /* original e014, guest PC 0x0c0854a8 */
if(!s->budget--) { s->failed_pc=0x0c0854a8u; return 0; }
r[0]=0x00000014u;
goto P_0c0854aa;
P_0c0854aa: /* original f6c6, guest PC 0x0c0854aa */
if(!s->budget--) { s->failed_pc=0x0c0854aau; return 0; }
vf3_matrix_load(s,ram,6,r[12]+r[0]);
goto P_0c0854ac;
P_0c0854ac: /* original 1f31, guest PC 0x0c0854ac */
if(!s->budget--) { s->failed_pc=0x0c0854acu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0854ae;
P_0c0854ae: /* original 54c7, guest PC 0x0c0854ae */
if(!s->budget--) { s->failed_pc=0x0c0854aeu; return 0; }
r[4]=read(ram,r[12]+28,4);
goto P_0c0854b0;
P_0c0854b0: /* original 7c20, guest PC 0x0c0854b0 */
if(!s->budget--) { s->failed_pc=0x0c0854b0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0854b2;
P_0c0854b2: /* original 1fd3, guest PC 0x0c0854b2 */
if(!s->budget--) { s->failed_pc=0x0c0854b2u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0854b4;
P_0c0854b4: /* original 345c, guest PC 0x0c0854b4 */
if(!s->budget--) { s->failed_pc=0x0c0854b4u; return 0; }
r[4]+=r[5];
goto P_0c0854b6;
P_0c0854b6: /* original 955e, guest PC 0x0c0854b6 */
if(!s->budget--) { s->failed_pc=0x0c0854b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085576u,2);
goto P_0c0854b8;
P_0c0854b8: /* original 345c, guest PC 0x0c0854b8 */
if(!s->budget--) { s->failed_pc=0x0c0854b8u; return 0; }
r[4]+=r[5];
goto P_0c0854ba;
P_0c0854ba: /* original 6043, guest PC 0x0c0854ba */
if(!s->budget--) { s->failed_pc=0x0c0854bau; return 0; }
r[0]=r[4];
goto P_0c0854bc;
P_0c0854bc: /* original 81e9, guest PC 0x0c0854bc */
if(!s->budget--) { s->failed_pc=0x0c0854bcu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0854be;
P_0c0854be: /* original 8d04, guest PC 0x0c0854be */
if(!s->budget--) { s->failed_pc=0x0c0854beu; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
if(cond) { goto P_0c0854ca; }
goto P_0c0854c2;
P_0c0854c0: /* original fe50, guest PC 0x0c0854c0 */
if(!s->budget--) { s->failed_pc=0x0c0854c0u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'+');
goto P_0c0854c2;
P_0c0854c2: /* original 2dd8, guest PC 0x0c0854c2 */
if(!s->budget--) { s->failed_pc=0x0c0854c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854c4;
P_0c0854c4: /* original 8f01, guest PC 0x0c0854c4 */
if(!s->budget--) { s->failed_pc=0x0c0854c4u; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
if(!cond) { goto P_0c0854ca; }
goto P_0c0854c8;
P_0c0854c6: /* original ff41, guest PC 0x0c0854c6 */
if(!s->budget--) { s->failed_pc=0x0c0854c6u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c0854c8;
P_0c0854c8: /* original ff8c, guest PC 0x0c0854c8 */
if(!s->budget--) { s->failed_pc=0x0c0854c8u; return 0; }
vf3_matrix_move(s,15,8);
goto P_0c0854ca;
P_0c0854ca: /* original fe75, guest PC 0x0c0854ca */
if(!s->budget--) { s->failed_pc=0x0c0854cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[7]))!=0);
goto P_0c0854cc;
P_0c0854cc: /* original 8903, guest PC 0x0c0854cc */
if(!s->budget--) { s->failed_pc=0x0c0854ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0854d6; }
goto P_0c0854ce;
P_0c0854ce: /* original 2dd8, guest PC 0x0c0854ce */
if(!s->budget--) { s->failed_pc=0x0c0854ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0854d0;
P_0c0854d0: /* original 8f01, guest PC 0x0c0854d0 */
if(!s->budget--) { s->failed_pc=0x0c0854d0u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
if(!cond) { goto P_0c0854d6; }
goto P_0c0854d4;
P_0c0854d2: /* original fe51, guest PC 0x0c0854d2 */
if(!s->budget--) { s->failed_pc=0x0c0854d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
goto P_0c0854d4;
P_0c0854d4: /* original fe6c, guest PC 0x0c0854d4 */
if(!s->budget--) { s->failed_pc=0x0c0854d4u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c0854d6;
P_0c0854d6: /* original d328, guest PC 0x0c0854d6 */
if(!s->budget--) { s->failed_pc=0x0c0854d6u; return 0; }
r[3]=read(ram,0x0c085578u,4);
goto P_0c0854d8;
P_0c0854d8: /* original f5ec, guest PC 0x0c0854d8 */
if(!s->budget--) { s->failed_pc=0x0c0854d8u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0854da;
P_0c0854da: /* original 430b, guest PC 0x0c0854da */
if(!s->budget--) { s->failed_pc=0x0c0854dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0854deu;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0854deu) { target=s->pc; goto dispatch; }
goto P_0c0854de;
P_0c0854dc: /* original f4fc, guest PC 0x0c0854dc */
if(!s->budget--) { s->failed_pc=0x0c0854dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0854de;
P_0c0854de: /* original 7901, guest PC 0x0c0854de */
if(!s->budget--) { s->failed_pc=0x0c0854deu; return 0; }
r[9]+=0x00000001u;
goto P_0c0854e0;
P_0c0854e0: /* original 6293, guest PC 0x0c0854e0 */
if(!s->budget--) { s->failed_pc=0x0c0854e0u; return 0; }
r[2]=r[9];
goto P_0c0854e2;
P_0c0854e2: /* original e401, guest PC 0x0c0854e2 */
if(!s->budget--) { s->failed_pc=0x0c0854e2u; return 0; }
r[4]=0x00000001u;
goto P_0c0854e4;
P_0c0854e4: /* original 2248, guest PC 0x0c0854e4 */
if(!s->budget--) { s->failed_pc=0x0c0854e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0854e6;
P_0c0854e6: /* original 8d01, guest PC 0x0c0854e6 */
if(!s->budget--) { s->failed_pc=0x0c0854e6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,0);
if(cond) { goto P_0c0854ec; }
goto P_0c0854ea;
P_0c0854e8: /* original f50c, guest PC 0x0c0854e8 */
if(!s->budget--) { s->failed_pc=0x0c0854e8u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0854ea;
P_0c0854ea: /* original 7d01, guest PC 0x0c0854ea */
if(!s->budget--) { s->failed_pc=0x0c0854eau; return 0; }
r[13]+=0x00000001u;
goto P_0c0854ec;
P_0c0854ec: /* original fde1, guest PC 0x0c0854ec */
if(!s->budget--) { s->failed_pc=0x0c0854ecu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c0854ee;
P_0c0854ee: /* original 649d, guest PC 0x0c0854ee */
if(!s->budget--) { s->failed_pc=0x0c0854eeu; return 0; }
r[4]=r[9]&65535u;
goto P_0c0854f0;
P_0c0854f0: /* original fcf1, guest PC 0x0c0854f0 */
if(!s->budget--) { s->failed_pc=0x0c0854f0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'-');
goto P_0c0854f2;
P_0c0854f2: /* original 52f1, guest PC 0x0c0854f2 */
if(!s->budget--) { s->failed_pc=0x0c0854f2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0854f4;
P_0c0854f4: /* original 6043, guest PC 0x0c0854f4 */
if(!s->budget--) { s->failed_pc=0x0c0854f4u; return 0; }
r[0]=r[4];
goto P_0c0854f6;
P_0c0854f6: /* original 81e8, guest PC 0x0c0854f6 */
if(!s->budget--) { s->failed_pc=0x0c0854f6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0854f8;
P_0c0854f8: /* original 2d29, guest PC 0x0c0854f8 */
if(!s->budget--) { s->failed_pc=0x0c0854f8u; return 0; }
r[13]&=r[2];
goto P_0c0854fa;
P_0c0854fa: /* original 60d3, guest PC 0x0c0854fa */
if(!s->budget--) { s->failed_pc=0x0c0854fau; return 0; }
r[0]=r[13];
goto P_0c0854fc;
P_0c0854fc: /* original 81e6, guest PC 0x0c0854fc */
if(!s->budget--) { s->failed_pc=0x0c0854fcu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c0854fe;
P_0c0854fe: /* original f3dc, guest PC 0x0c0854fe */
if(!s->budget--) { s->failed_pc=0x0c0854feu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085500;
P_0c085500: /* original f3d2, guest PC 0x0c085500 */
if(!s->budget--) { s->failed_pc=0x0c085500u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c085502;
P_0c085502: /* original f0cc, guest PC 0x0c085502 */
if(!s->budget--) { s->failed_pc=0x0c085502u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c085504;
P_0c085504: /* original c71d, guest PC 0x0c085504 */
if(!s->budget--) { s->failed_pc=0x0c085504u; return 0; }
r[0]=code_base|0x0008557cu;
goto P_0c085506;
P_0c085506: /* original 53f3, guest PC 0x0c085506 */
if(!s->budget--) { s->failed_pc=0x0c085506u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c085508;
P_0c085508: /* original f608, guest PC 0x0c085508 */
if(!s->budget--) { s->failed_pc=0x0c085508u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08550a;
P_0c08550a: /* original f3ce, guest PC 0x0c08550a */
if(!s->budget--) { s->failed_pc=0x0c08550au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[12],fr[3],r[18]);
goto P_0c08550c;
P_0c08550c: /* original 2338, guest PC 0x0c08550c */
if(!s->budget--) { s->failed_pc=0x0c08550cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08550e;
P_0c08550e: /* original f43c, guest PC 0x0c08550e */
if(!s->budget--) { s->failed_pc=0x0c08550eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085510;
P_0c085510: /* original 8f06, guest PC 0x0c085510 */
if(!s->budget--) { s->failed_pc=0x0c085510u; return 0; }
cond=r[17]&1u;
fr[4]&=0x7fffffffu;
if(!cond) { goto P_0c085520; }
goto P_0c085514;
P_0c085512: /* original f45d, guest PC 0x0c085512 */
if(!s->budget--) { s->failed_pc=0x0c085512u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c085514;
P_0c085514: /* original f465, guest PC 0x0c085514 */
if(!s->budget--) { s->failed_pc=0x0c085514u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c085516;
P_0c085516: /* original 6482, guest PC 0x0c085516 */
if(!s->budget--) { s->failed_pc=0x0c085516u; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c085518;
P_0c085518: /* original 8d0a, guest PC 0x0c085518 */
if(!s->budget--) { s->failed_pc=0x0c085518u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[4],4);
if(cond) { goto P_0c085530; }
goto P_0c08551c;
P_0c08551a: /* original 1e45, guest PC 0x0c08551a */
if(!s->budget--) { s->failed_pc=0x0c08551au; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c08551c;
P_0c08551c: /* original a006, guest PC 0x0c08551c */
if(!s->budget--) { s->failed_pc=0x0c08551cu; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08551e: /* original 6db3, guest PC 0x0c08551e */
if(!s->budget--) { s->failed_pc=0x0c08551eu; return 0; }
r[13]=r[11];
goto P_0c085520;
P_0c085520: /* original e43e, guest PC 0x0c085520 */
if(!s->budget--) { s->failed_pc=0x0c085520u; return 0; }
r[4]=0x0000003eu;
goto P_0c085522;
P_0c085522: /* original 3d43, guest PC 0x0c085522 */
if(!s->budget--) { s->failed_pc=0x0c085522u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[4])!=0);
goto P_0c085524;
P_0c085524: /* original 8b04, guest PC 0x0c085524 */
if(!s->budget--) { s->failed_pc=0x0c085524u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085530; }
goto P_0c085526;
P_0c085526: /* original f645, guest PC 0x0c085526 */
if(!s->budget--) { s->failed_pc=0x0c085526u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[4]))!=0);
goto P_0c085528;
P_0c085528: /* original 8d02, guest PC 0x0c085528 */
if(!s->budget--) { s->failed_pc=0x0c085528u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c085530; }
goto P_0c08552c;
P_0c08552a: /* original 6db3, guest PC 0x0c08552a */
if(!s->budget--) { s->failed_pc=0x0c08552au; return 0; }
r[13]=r[11];
goto P_0c08552c;
P_0c08552c: /* original 60b3, guest PC 0x0c08552c */
if(!s->budget--) { s->failed_pc=0x0c08552cu; return 0; }
r[0]=r[11];
goto P_0c08552e;
P_0c08552e: /* original 81e6, guest PC 0x0c08552e */
if(!s->budget--) { s->failed_pc=0x0c08552eu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c085530;
P_0c085530: /* original 60d3, guest PC 0x0c085530 */
if(!s->budget--) { s->failed_pc=0x0c085530u; return 0; }
r[0]=r[13];
goto P_0c085532;
P_0c085532: /* original 54e5, guest PC 0x0c085532 */
if(!s->budget--) { s->failed_pc=0x0c085532u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c085534;
P_0c085534: /* original 4000, guest PC 0x0c085534 */
if(!s->budget--) { s->failed_pc=0x0c085534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c085536;
P_0c085536: /* original 004d, guest PC 0x0c085536 */
if(!s->budget--) { s->failed_pc=0x0c085536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c085538;
P_0c085538: /* original 7804, guest PC 0x0c085538 */
if(!s->budget--) { s->failed_pc=0x0c085538u; return 0; }
r[8]+=0x00000004u;
goto P_0c08553a;
P_0c08553a: /* original 81e7, guest PC 0x0c08553a */
if(!s->budget--) { s->failed_pc=0x0c08553au; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c08553c;
P_0c08553c: /* original e004, guest PC 0x0c08553c */
if(!s->budget--) { s->failed_pc=0x0c08553cu; return 0; }
r[0]=0x00000004u;
goto P_0c08553e;
P_0c08553e: /* original fefa, guest PC 0x0c08553e */
if(!s->budget--) { s->failed_pc=0x0c08553eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c085540;
P_0c085540: /* original fe57, guest PC 0x0c085540 */
if(!s->budget--) { s->failed_pc=0x0c085540u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c085542;
P_0c085542: /* original e008, guest PC 0x0c085542 */
if(!s->budget--) { s->failed_pc=0x0c085542u; return 0; }
r[0]=0x00000008u;
goto P_0c085544;
P_0c085544: /* original fee7, guest PC 0x0c085544 */
if(!s->budget--) { s->failed_pc=0x0c085544u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c085546;
P_0c085546: /* original 63f2, guest PC 0x0c085546 */
if(!s->budget--) { s->failed_pc=0x0c085546u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085548;
P_0c085548: /* original 7e18, guest PC 0x0c085548 */
if(!s->budget--) { s->failed_pc=0x0c085548u; return 0; }
r[14]+=0x00000018u;
goto P_0c08554a;
P_0c08554a: /* original 7301, guest PC 0x0c08554a */
if(!s->budget--) { s->failed_pc=0x0c08554au; return 0; }
r[3]+=0x00000001u;
goto P_0c08554c;
P_0c08554c: /* original 2f32, guest PC 0x0c08554c */
if(!s->budget--) { s->failed_pc=0x0c08554cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08554e;
P_0c08554e: /* original 63f2, guest PC 0x0c08554e */
if(!s->budget--) { s->failed_pc=0x0c08554eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085550;
P_0c085550: /* original e40d, guest PC 0x0c085550 */
if(!s->budget--) { s->failed_pc=0x0c085550u; return 0; }
r[4]=0x0000000du;
goto P_0c085552;
P_0c085552: /* original 3343, guest PC 0x0c085552 */
if(!s->budget--) { s->failed_pc=0x0c085552u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c085554;
P_0c085554: /* original 8901, guest PC 0x0c085554 */
if(!s->budget--) { s->failed_pc=0x0c085554u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08555a; }
goto P_0c085556;
P_0c085556: /* original af6d, guest PC 0x0c085556 */
if(!s->budget--) { s->failed_pc=0x0c085556u; return 0; }
goto P_0c085434;
P_0c085558: /* original 0009, guest PC 0x0c085558 */
if(!s->budget--) { s->failed_pc=0x0c085558u; return 0; }
goto P_0c08555a;
P_0c08555a: /* original 7f10, guest PC 0x0c08555a */
if(!s->budget--) { s->failed_pc=0x0c08555au; return 0; }
r[15]+=0x00000010u;
goto P_0c08555c;
P_0c08555c: /* original 4f26, guest PC 0x0c08555c */
if(!s->budget--) { s->failed_pc=0x0c08555cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08555e;
P_0c08555e: /* original fcf9, guest PC 0x0c08555e */
if(!s->budget--) { s->failed_pc=0x0c08555eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085560;
P_0c085560: /* original fdf9, guest PC 0x0c085560 */
if(!s->budget--) { s->failed_pc=0x0c085560u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085562;
P_0c085562: /* original fef9, guest PC 0x0c085562 */
if(!s->budget--) { s->failed_pc=0x0c085562u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085564;
P_0c085564: /* original fff9, guest PC 0x0c085564 */
if(!s->budget--) { s->failed_pc=0x0c085564u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085566;
P_0c085566: /* original 68f6, guest PC 0x0c085566 */
if(!s->budget--) { s->failed_pc=0x0c085566u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085568;
P_0c085568: /* original 69f6, guest PC 0x0c085568 */
if(!s->budget--) { s->failed_pc=0x0c085568u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08556a;
P_0c08556a: /* original 6af6, guest PC 0x0c08556a */
if(!s->budget--) { s->failed_pc=0x0c08556au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08556c;
P_0c08556c: /* original 6bf6, guest PC 0x0c08556c */
if(!s->budget--) { s->failed_pc=0x0c08556cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08556e;
P_0c08556e: /* original 6cf6, guest PC 0x0c08556e */
if(!s->budget--) { s->failed_pc=0x0c08556eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085570;
P_0c085570: /* original 6df6, guest PC 0x0c085570 */
if(!s->budget--) { s->failed_pc=0x0c085570u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085572;
P_0c085572: /* original 000b, guest PC 0x0c085572 */
if(!s->budget--) { s->failed_pc=0x0c085572u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085574: /* original 6ef6, guest PC 0x0c085574 */
if(!s->budget--) { s->failed_pc=0x0c085574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085576u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085576u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
