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
int vf3_away_batch34_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06938cu: goto P_0c06938c;
case 0x0c06938eu: goto P_0c06938e;
case 0x0c069390u: goto P_0c069390;
case 0x0c069392u: goto P_0c069392;
case 0x0c069394u: goto P_0c069394;
case 0x0c069396u: goto P_0c069396;
case 0x0c069398u: goto P_0c069398;
case 0x0c06939au: goto P_0c06939a;
case 0x0c06939cu: goto P_0c06939c;
case 0x0c06939eu: goto P_0c06939e;
case 0x0c0693a0u: goto P_0c0693a0;
case 0x0c0693a2u: goto P_0c0693a2;
case 0x0c0693a4u: goto P_0c0693a4;
case 0x0c0693a6u: goto P_0c0693a6;
case 0x0c0693a8u: goto P_0c0693a8;
case 0x0c0693aau: goto P_0c0693aa;
case 0x0c0693acu: goto P_0c0693ac;
case 0x0c0693aeu: goto P_0c0693ae;
case 0x0c0693b0u: goto P_0c0693b0;
case 0x0c0693b2u: goto P_0c0693b2;
case 0x0c0693b4u: goto P_0c0693b4;
case 0x0c0693b6u: goto P_0c0693b6;
case 0x0c0693b8u: goto P_0c0693b8;
case 0x0c0693bau: goto P_0c0693ba;
case 0x0c0693bcu: goto P_0c0693bc;
case 0x0c0693beu: goto P_0c0693be;
case 0x0c0693c0u: goto P_0c0693c0;
case 0x0c0693c2u: goto P_0c0693c2;
case 0x0c0693c4u: goto P_0c0693c4;
case 0x0c0693c6u: goto P_0c0693c6;
case 0x0c0693c8u: goto P_0c0693c8;
case 0x0c0693cau: goto P_0c0693ca;
case 0x0c0693ccu: goto P_0c0693cc;
case 0x0c0693ceu: goto P_0c0693ce;
case 0x0c0693d0u: goto P_0c0693d0;
case 0x0c0693d2u: goto P_0c0693d2;
case 0x0c0693d4u: goto P_0c0693d4;
case 0x0c0693d6u: goto P_0c0693d6;
case 0x0c0693d8u: goto P_0c0693d8;
case 0x0c0693dau: goto P_0c0693da;
case 0x0c0693dcu: goto P_0c0693dc;
case 0x0c0693deu: goto P_0c0693de;
case 0x0c0693e0u: goto P_0c0693e0;
case 0x0c0693e2u: goto P_0c0693e2;
case 0x0c0693e4u: goto P_0c0693e4;
case 0x0c0693e6u: goto P_0c0693e6;
case 0x0c0693e8u: goto P_0c0693e8;
case 0x0c0693eau: goto P_0c0693ea;
case 0x0c0693ecu: goto P_0c0693ec;
case 0x0c0693eeu: goto P_0c0693ee;
case 0x0c0693f0u: goto P_0c0693f0;
case 0x0c0693f2u: goto P_0c0693f2;
case 0x0c0693f4u: goto P_0c0693f4;
case 0x0c0693f6u: goto P_0c0693f6;
case 0x0c0693f8u: goto P_0c0693f8;
case 0x0c0693fau: goto P_0c0693fa;
case 0x0c0693fcu: goto P_0c0693fc;
case 0x0c0693feu: goto P_0c0693fe;
case 0x0c069400u: goto P_0c069400;
case 0x0c069402u: goto P_0c069402;
case 0x0c069404u: goto P_0c069404;
case 0x0c069406u: goto P_0c069406;
case 0x0c069408u: goto P_0c069408;
case 0x0c06940au: goto P_0c06940a;
case 0x0c06940cu: goto P_0c06940c;
case 0x0c06940eu: goto P_0c06940e;
case 0x0c069410u: goto P_0c069410;
case 0x0c069412u: goto P_0c069412;
case 0x0c069414u: goto P_0c069414;
case 0x0c069416u: goto P_0c069416;
case 0x0c069418u: goto P_0c069418;
case 0x0c06941au: goto P_0c06941a;
case 0x0c06941cu: goto P_0c06941c;
case 0x0c06941eu: goto P_0c06941e;
case 0x0c069420u: goto P_0c069420;
case 0x0c069422u: goto P_0c069422;
case 0x0c069424u: goto P_0c069424;
case 0x0c069426u: goto P_0c069426;
case 0x0c069428u: goto P_0c069428;
case 0x0c06942au: goto P_0c06942a;
case 0x0c06942cu: goto P_0c06942c;
case 0x0c06942eu: goto P_0c06942e;
case 0x0c069430u: goto P_0c069430;
case 0x0c069432u: goto P_0c069432;
case 0x0c069434u: goto P_0c069434;
case 0x0c069436u: goto P_0c069436;
case 0x0c069438u: goto P_0c069438;
case 0x0c06943au: goto P_0c06943a;
case 0x0c06943cu: goto P_0c06943c;
case 0x0c06943eu: goto P_0c06943e;
case 0x0c069440u: goto P_0c069440;
case 0x0c069442u: goto P_0c069442;
case 0x0c069444u: goto P_0c069444;
case 0x0c069446u: goto P_0c069446;
case 0x0c069448u: goto P_0c069448;
case 0x0c06944au: goto P_0c06944a;
case 0x0c06944cu: goto P_0c06944c;
case 0x0c06944eu: goto P_0c06944e;
case 0x0c069450u: goto P_0c069450;
case 0x0c069452u: goto P_0c069452;
case 0x0c069454u: goto P_0c069454;
case 0x0c069456u: goto P_0c069456;
case 0x0c069458u: goto P_0c069458;
case 0x0c06945au: goto P_0c06945a;
case 0x0c06945cu: goto P_0c06945c;
case 0x0c06945eu: goto P_0c06945e;
case 0x0c069460u: goto P_0c069460;
case 0x0c069462u: goto P_0c069462;
case 0x0c069464u: goto P_0c069464;
case 0x0c069466u: goto P_0c069466;
case 0x0c069468u: goto P_0c069468;
case 0x0c06946au: goto P_0c06946a;
case 0x0c06946cu: goto P_0c06946c;
case 0x0c06946eu: goto P_0c06946e;
case 0x0c069470u: goto P_0c069470;
case 0x0c069472u: goto P_0c069472;
case 0x0c069474u: goto P_0c069474;
case 0x0c069476u: goto P_0c069476;
case 0x0c069478u: goto P_0c069478;
case 0x0c06947au: goto P_0c06947a;
case 0x0c06947cu: goto P_0c06947c;
case 0x0c06947eu: goto P_0c06947e;
case 0x0c069480u: goto P_0c069480;
case 0x0c069482u: goto P_0c069482;
case 0x0c069484u: goto P_0c069484;
case 0x0c069486u: goto P_0c069486;
case 0x0c069488u: goto P_0c069488;
case 0x0c06948au: goto P_0c06948a;
case 0x0c06948cu: goto P_0c06948c;
case 0x0c06948eu: goto P_0c06948e;
case 0x0c069490u: goto P_0c069490;
case 0x0c069492u: goto P_0c069492;
case 0x0c069494u: goto P_0c069494;
case 0x0c0694b0u: goto P_0c0694b0;
case 0x0c0694b2u: goto P_0c0694b2;
case 0x0c0694b4u: goto P_0c0694b4;
case 0x0c0694b6u: goto P_0c0694b6;
case 0x0c0694b8u: goto P_0c0694b8;
case 0x0c0694bau: goto P_0c0694ba;
case 0x0c0694bcu: goto P_0c0694bc;
case 0x0c0694beu: goto P_0c0694be;
case 0x0c0694c0u: goto P_0c0694c0;
case 0x0c0694c2u: goto P_0c0694c2;
case 0x0c0694c4u: goto P_0c0694c4;
case 0x0c0694c6u: goto P_0c0694c6;
case 0x0c0694c8u: goto P_0c0694c8;
case 0x0c0694cau: goto P_0c0694ca;
case 0x0c0694ccu: goto P_0c0694cc;
case 0x0c0694ceu: goto P_0c0694ce;
case 0x0c0694d0u: goto P_0c0694d0;
case 0x0c0694d2u: goto P_0c0694d2;
case 0x0c0694d4u: goto P_0c0694d4;
case 0x0c0694d6u: goto P_0c0694d6;
case 0x0c0694d8u: goto P_0c0694d8;
case 0x0c0694dau: goto P_0c0694da;
case 0x0c0694dcu: goto P_0c0694dc;
case 0x0c0694deu: goto P_0c0694de;
case 0x0c0694e0u: goto P_0c0694e0;
case 0x0c0694e2u: goto P_0c0694e2;
case 0x0c0694e4u: goto P_0c0694e4;
case 0x0c0694e6u: goto P_0c0694e6;
case 0x0c0694e8u: goto P_0c0694e8;
case 0x0c0694eau: goto P_0c0694ea;
case 0x0c0694ecu: goto P_0c0694ec;
case 0x0c0694eeu: goto P_0c0694ee;
case 0x0c0694f0u: goto P_0c0694f0;
case 0x0c0694f2u: goto P_0c0694f2;
case 0x0c0694f4u: goto P_0c0694f4;
case 0x0c0694f6u: goto P_0c0694f6;
case 0x0c0694f8u: goto P_0c0694f8;
case 0x0c0694fau: goto P_0c0694fa;
case 0x0c0694fcu: goto P_0c0694fc;
case 0x0c0694feu: goto P_0c0694fe;
case 0x0c069500u: goto P_0c069500;
case 0x0c069502u: goto P_0c069502;
case 0x0c069504u: goto P_0c069504;
case 0x0c069506u: goto P_0c069506;
case 0x0c069508u: goto P_0c069508;
case 0x0c06950au: goto P_0c06950a;
case 0x0c06950cu: goto P_0c06950c;
case 0x0c06950eu: goto P_0c06950e;
case 0x0c069510u: goto P_0c069510;
case 0x0c069512u: goto P_0c069512;
case 0x0c069514u: goto P_0c069514;
case 0x0c069516u: goto P_0c069516;
case 0x0c069518u: goto P_0c069518;
case 0x0c0696c6u: goto P_0c0696c6;
case 0x0c0696c8u: goto P_0c0696c8;
case 0x0c0696cau: goto P_0c0696ca;
case 0x0c0696ccu: goto P_0c0696cc;
case 0x0c0696ceu: goto P_0c0696ce;
case 0x0c0696d0u: goto P_0c0696d0;
case 0x0c0696d2u: goto P_0c0696d2;
case 0x0c0696d4u: goto P_0c0696d4;
case 0x0c0696d6u: goto P_0c0696d6;
case 0x0c0696d8u: goto P_0c0696d8;
case 0x0c0696dau: goto P_0c0696da;
case 0x0c0696dcu: goto P_0c0696dc;
case 0x0c0696deu: goto P_0c0696de;
case 0x0c0696e0u: goto P_0c0696e0;
case 0x0c0696e2u: goto P_0c0696e2;
case 0x0c0696e4u: goto P_0c0696e4;
case 0x0c06972au: goto P_0c06972a;
case 0x0c06972cu: goto P_0c06972c;
case 0x0c06972eu: goto P_0c06972e;
case 0x0c069730u: goto P_0c069730;
case 0x0c069732u: goto P_0c069732;
case 0x0c069734u: goto P_0c069734;
case 0x0c069736u: goto P_0c069736;
case 0x0c069738u: goto P_0c069738;
case 0x0c06973au: goto P_0c06973a;
case 0x0c06973cu: goto P_0c06973c;
case 0x0c06973eu: goto P_0c06973e;
case 0x0c069740u: goto P_0c069740;
case 0x0c069742u: goto P_0c069742;
case 0x0c069744u: goto P_0c069744;
case 0x0c069746u: goto P_0c069746;
case 0x0c069748u: goto P_0c069748;
case 0x0c06974au: goto P_0c06974a;
case 0x0c06974cu: goto P_0c06974c;
case 0x0c06974eu: goto P_0c06974e;
case 0x0c069750u: goto P_0c069750;
case 0x0c069752u: goto P_0c069752;
case 0x0c069754u: goto P_0c069754;
case 0x0c069756u: goto P_0c069756;
case 0x0c069758u: goto P_0c069758;
case 0x0c06975au: goto P_0c06975a;
case 0x0c06975cu: goto P_0c06975c;
case 0x0c06975eu: goto P_0c06975e;
case 0x0c069760u: goto P_0c069760;
case 0x0c069762u: goto P_0c069762;
case 0x0c069764u: goto P_0c069764;
case 0x0c069766u: goto P_0c069766;
case 0x0c069768u: goto P_0c069768;
case 0x0c06976au: goto P_0c06976a;
case 0x0c06976cu: goto P_0c06976c;
case 0x0c06976eu: goto P_0c06976e;
case 0x0c069770u: goto P_0c069770;
case 0x0c069772u: goto P_0c069772;
case 0x0c069774u: goto P_0c069774;
case 0x0c069776u: goto P_0c069776;
case 0x0c069778u: goto P_0c069778;
case 0x0c06977au: goto P_0c06977a;
case 0x0c06977cu: goto P_0c06977c;
case 0x0c06977eu: goto P_0c06977e;
case 0x0c069780u: goto P_0c069780;
case 0x0c069782u: goto P_0c069782;
case 0x0c069784u: goto P_0c069784;
case 0x0c069786u: goto P_0c069786;
case 0x0c069788u: goto P_0c069788;
case 0x0c06978au: goto P_0c06978a;
case 0x0c06978cu: goto P_0c06978c;
case 0x0c06978eu: goto P_0c06978e;
case 0x0c069790u: goto P_0c069790;
case 0x0c069792u: goto P_0c069792;
case 0x0c069794u: goto P_0c069794;
case 0x0c069796u: goto P_0c069796;
case 0x0c069798u: goto P_0c069798;
case 0x0c06979au: goto P_0c06979a;
case 0x0c06979cu: goto P_0c06979c;
case 0x0c06979eu: goto P_0c06979e;
case 0x0c0697a0u: goto P_0c0697a0;
case 0x0c0697a2u: goto P_0c0697a2;
case 0x0c0697a4u: goto P_0c0697a4;
case 0x0c0697a6u: goto P_0c0697a6;
case 0x0c0697a8u: goto P_0c0697a8;
case 0x0c0697aau: goto P_0c0697aa;
case 0x0c0697acu: goto P_0c0697ac;
case 0x0c0697f0u: goto P_0c0697f0;
case 0x0c0697f2u: goto P_0c0697f2;
case 0x0c0697f4u: goto P_0c0697f4;
case 0x0c0697f6u: goto P_0c0697f6;
case 0x0c0697f8u: goto P_0c0697f8;
case 0x0c0697fau: goto P_0c0697fa;
case 0x0c0697fcu: goto P_0c0697fc;
case 0x0c0697feu: goto P_0c0697fe;
case 0x0c069800u: goto P_0c069800;
case 0x0c069802u: goto P_0c069802;
case 0x0c069804u: goto P_0c069804;
case 0x0c069806u: goto P_0c069806;
case 0x0c069808u: goto P_0c069808;
case 0x0c06980au: goto P_0c06980a;
case 0x0c06980cu: goto P_0c06980c;
case 0x0c06980eu: goto P_0c06980e;
case 0x0c069810u: goto P_0c069810;
case 0x0c069812u: goto P_0c069812;
case 0x0c069814u: goto P_0c069814;
case 0x0c069816u: goto P_0c069816;
case 0x0c069818u: goto P_0c069818;
case 0x0c06981au: goto P_0c06981a;
case 0x0c06981cu: goto P_0c06981c;
case 0x0c06981eu: goto P_0c06981e;
case 0x0c069820u: goto P_0c069820;
case 0x0c069822u: goto P_0c069822;
case 0x0c069824u: goto P_0c069824;
case 0x0c069826u: goto P_0c069826;
case 0x0c069828u: goto P_0c069828;
case 0x0c06982au: goto P_0c06982a;
case 0x0c06982cu: goto P_0c06982c;
case 0x0c06982eu: goto P_0c06982e;
case 0x0c069830u: goto P_0c069830;
case 0x0c069832u: goto P_0c069832;
case 0x0c069834u: goto P_0c069834;
case 0x0c069836u: goto P_0c069836;
case 0x0c069838u: goto P_0c069838;
case 0x0c06983au: goto P_0c06983a;
case 0x0c06983cu: goto P_0c06983c;
case 0x0c06983eu: goto P_0c06983e;
case 0x0c069840u: goto P_0c069840;
case 0x0c069842u: goto P_0c069842;
case 0x0c069844u: goto P_0c069844;
case 0x0c069846u: goto P_0c069846;
case 0x0c069848u: goto P_0c069848;
case 0x0c06984au: goto P_0c06984a;
case 0x0c06984cu: goto P_0c06984c;
case 0x0c06984eu: goto P_0c06984e;
case 0x0c069850u: goto P_0c069850;
case 0x0c069852u: goto P_0c069852;
case 0x0c069854u: goto P_0c069854;
case 0x0c069856u: goto P_0c069856;
case 0x0c069858u: goto P_0c069858;
case 0x0c06985au: goto P_0c06985a;
case 0x0c06985cu: goto P_0c06985c;
case 0x0c06985eu: goto P_0c06985e;
case 0x0c069860u: goto P_0c069860;
case 0x0c069862u: goto P_0c069862;
case 0x0c069864u: goto P_0c069864;
case 0x0c069866u: goto P_0c069866;
case 0x0c069868u: goto P_0c069868;
case 0x0c06986au: goto P_0c06986a;
case 0x0c06986cu: goto P_0c06986c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06938c: /* original 2fe6, guest PC 0x0c06938c */
if(!s->budget--) { s->failed_pc=0x0c06938cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06938e;
P_0c06938e: /* original e004, guest PC 0x0c06938e */
if(!s->budget--) { s->failed_pc=0x0c06938eu; return 0; }
r[0]=0x00000004u;
goto P_0c069390;
P_0c069390: /* original 2fd6, guest PC 0x0c069390 */
if(!s->budget--) { s->failed_pc=0x0c069390u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069392;
P_0c069392: /* original 6d43, guest PC 0x0c069392 */
if(!s->budget--) { s->failed_pc=0x0c069392u; return 0; }
r[13]=r[4];
goto P_0c069394;
P_0c069394: /* original 2fc6, guest PC 0x0c069394 */
if(!s->budget--) { s->failed_pc=0x0c069394u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069396;
P_0c069396: /* original ec0f, guest PC 0x0c069396 */
if(!s->budget--) { s->failed_pc=0x0c069396u; return 0; }
r[12]=0x0000000fu;
goto P_0c069398;
P_0c069398: /* original 2fb6, guest PC 0x0c069398 */
if(!s->budget--) { s->failed_pc=0x0c069398u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06939a;
P_0c06939a: /* original 6b53, guest PC 0x0c06939a */
if(!s->budget--) { s->failed_pc=0x0c06939au; return 0; }
r[11]=r[5];
goto P_0c06939c;
P_0c06939c: /* original fffb, guest PC 0x0c06939c */
if(!s->budget--) { s->failed_pc=0x0c06939cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06939e;
P_0c06939e: /* original 4f22, guest PC 0x0c06939e */
if(!s->budget--) { s->failed_pc=0x0c06939eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0693a0;
P_0c0693a0: /* original 7fd8, guest PC 0x0c0693a0 */
if(!s->budget--) { s->failed_pc=0x0c0693a0u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0693a2;
P_0c0693a2: /* original 66f3, guest PC 0x0c0693a2 */
if(!s->budget--) { s->failed_pc=0x0c0693a2u; return 0; }
r[6]=r[15];
goto P_0c0693a4;
P_0c0693a4: /* original 65f3, guest PC 0x0c0693a4 */
if(!s->budget--) { s->failed_pc=0x0c0693a4u; return 0; }
r[5]=r[15];
goto P_0c0693a6;
P_0c0693a6: /* original 7604, guest PC 0x0c0693a6 */
if(!s->budget--) { s->failed_pc=0x0c0693a6u; return 0; }
r[6]+=0x00000004u;
goto P_0c0693a8;
P_0c0693a8: /* original ff4a, guest PC 0x0c0693a8 */
if(!s->budget--) { s->failed_pc=0x0c0693a8u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0693aa;
P_0c0693aa: /* original ff57, guest PC 0x0c0693aa */
if(!s->budget--) { s->failed_pc=0x0c0693aau; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0693ac;
P_0c0693ac: /* original d33a, guest PC 0x0c0693ac */
if(!s->budget--) { s->failed_pc=0x0c0693acu; return 0; }
r[3]=read(ram,0x0c069498u,4);
goto P_0c0693ae;
P_0c0693ae: /* original 6030, guest PC 0x0c0693ae */
if(!s->budget--) { s->failed_pc=0x0c0693aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0693b0;
P_0c0693b0: /* original 600c, guest PC 0x0c0693b0 */
if(!s->budget--) { s->failed_pc=0x0c0693b0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0693b2;
P_0c0693b2: /* original 2c09, guest PC 0x0c0693b2 */
if(!s->budget--) { s->failed_pc=0x0c0693b2u; return 0; }
r[12]&=r[0];
goto P_0c0693b4;
P_0c0693b4: /* original bcce, guest PC 0x0c0693b4 */
if(!s->budget--) { s->failed_pc=0x0c0693b4u; return 0; }
target=code_base|0x0c068d54u; r[16]=code_base|0x0c0693b8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693b8u) { target=s->pc; goto dispatch; }
goto P_0c0693b8;
P_0c0693b6: /* original 64c3, guest PC 0x0c0693b6 */
if(!s->budget--) { s->failed_pc=0x0c0693b6u; return 0; }
r[4]=r[12];
goto P_0c0693b8;
P_0c0693b8: /* original 906d, guest PC 0x0c0693b8 */
if(!s->budget--) { s->failed_pc=0x0c0693b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c0693ba;
P_0c0693ba: /* original d538, guest PC 0x0c0693ba */
if(!s->budget--) { s->failed_pc=0x0c0693bau; return 0; }
r[5]=read(ram,0x0c06949cu,4);
goto P_0c0693bc;
P_0c0693bc: /* original 035e, guest PC 0x0c0693bc */
if(!s->budget--) { s->failed_pc=0x0c0693bcu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0693be;
P_0c0693be: /* original 2338, guest PC 0x0c0693be */
if(!s->budget--) { s->failed_pc=0x0c0693beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0693c0;
P_0c0693c0: /* original 8b07, guest PC 0x0c0693c0 */
if(!s->budget--) { s->failed_pc=0x0c0693c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693d2; }
goto P_0c0693c2;
P_0c0693c2: /* original e004, guest PC 0x0c0693c2 */
if(!s->budget--) { s->failed_pc=0x0c0693c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0693c4;
P_0c0693c4: /* original 64b3, guest PC 0x0c0693c4 */
if(!s->budget--) { s->failed_pc=0x0c0693c4u; return 0; }
r[4]=r[11];
goto P_0c0693c6;
P_0c0693c6: /* original f5f6, guest PC 0x0c0693c6 */
if(!s->budget--) { s->failed_pc=0x0c0693c6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0693c8;
P_0c0693c8: /* original bd0c, guest PC 0x0c0693c8 */
if(!s->budget--) { s->failed_pc=0x0c0693c8u; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c0693ccu;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0693ccu) { target=s->pc; goto dispatch; }
goto P_0c0693cc;
P_0c0693ca: /* original f4f8, guest PC 0x0c0693ca */
if(!s->budget--) { s->failed_pc=0x0c0693cau; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0693cc;
P_0c0693cc: /* original fd0a, guest PC 0x0c0693cc */
if(!s->budget--) { s->failed_pc=0x0c0693ccu; return 0; }
vf3_matrix_store(s,ram,0,r[13]);
goto P_0c0693ce;
P_0c0693ce: /* original a09c, guest PC 0x0c0693ce */
if(!s->budget--) { s->failed_pc=0x0c0693ceu; return 0; }
r[0]=0x00000000u;
goto P_0c06950a;
P_0c0693d0: /* original e000, guest PC 0x0c0693d0 */
if(!s->budget--) { s->failed_pc=0x0c0693d0u; return 0; }
r[0]=0x00000000u;
goto P_0c0693d2;
P_0c0693d2: /* original c733, guest PC 0x0c0693d2 */
if(!s->budget--) { s->failed_pc=0x0c0693d2u; return 0; }
r[0]=code_base|0x000694a0u;
goto P_0c0693d4;
P_0c0693d4: /* original f3f8, guest PC 0x0c0693d4 */
if(!s->budget--) { s->failed_pc=0x0c0693d4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0693d6;
P_0c0693d6: /* original f408, guest PC 0x0c0693d6 */
if(!s->budget--) { s->failed_pc=0x0c0693d6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0693d8;
P_0c0693d8: /* original f435, guest PC 0x0c0693d8 */
if(!s->budget--) { s->failed_pc=0x0c0693d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0693da;
P_0c0693da: /* original 8f0c, guest PC 0x0c0693da */
if(!s->budget--) { s->failed_pc=0x0c0693dau; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693de;
P_0c0693dc: /* original ff8d, guest PC 0x0c0693dc */
if(!s->budget--) { s->failed_pc=0x0c0693dcu; return 0; }
fr[15]=0;
goto P_0c0693de;
P_0c0693de: /* original e004, guest PC 0x0c0693de */
if(!s->budget--) { s->failed_pc=0x0c0693deu; return 0; }
r[0]=0x00000004u;
goto P_0c0693e0;
P_0c0693e0: /* original f2f6, guest PC 0x0c0693e0 */
if(!s->budget--) { s->failed_pc=0x0c0693e0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0693e2;
P_0c0693e2: /* original f425, guest PC 0x0c0693e2 */
if(!s->budget--) { s->failed_pc=0x0c0693e2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0693e4;
P_0c0693e4: /* original 8b07, guest PC 0x0c0693e4 */
if(!s->budget--) { s->failed_pc=0x0c0693e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693e6;
P_0c0693e6: /* original c72f, guest PC 0x0c0693e6 */
if(!s->budget--) { s->failed_pc=0x0c0693e6u; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693e8;
P_0c0693e8: /* original f108, guest PC 0x0c0693e8 */
if(!s->budget--) { s->failed_pc=0x0c0693e8u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0693ea;
P_0c0693ea: /* original f315, guest PC 0x0c0693ea */
if(!s->budget--) { s->failed_pc=0x0c0693eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c0693ec;
P_0c0693ec: /* original 8b03, guest PC 0x0c0693ec */
if(!s->budget--) { s->failed_pc=0x0c0693ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0693f6; }
goto P_0c0693ee;
P_0c0693ee: /* original c72d, guest PC 0x0c0693ee */
if(!s->budget--) { s->failed_pc=0x0c0693eeu; return 0; }
r[0]=code_base|0x000694a4u;
goto P_0c0693f0;
P_0c0693f0: /* original f308, guest PC 0x0c0693f0 */
if(!s->budget--) { s->failed_pc=0x0c0693f0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0693f2;
P_0c0693f2: /* original f235, guest PC 0x0c0693f2 */
if(!s->budget--) { s->failed_pc=0x0c0693f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0693f4;
P_0c0693f4: /* original 8902, guest PC 0x0c0693f4 */
if(!s->budget--) { s->failed_pc=0x0c0693f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0693fc; }
goto P_0c0693f6;
P_0c0693f6: /* original fdfa, guest PC 0x0c0693f6 */
if(!s->budget--) { s->failed_pc=0x0c0693f6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0693f8;
P_0c0693f8: /* original a05c, guest PC 0x0c0693f8 */
if(!s->budget--) { s->failed_pc=0x0c0693f8u; return 0; }
r[14]=0x00000001u;
goto P_0c0694b4;
P_0c0693fa: /* original ee01, guest PC 0x0c0693fa */
if(!s->budget--) { s->failed_pc=0x0c0693fau; return 0; }
r[14]=0x00000001u;
goto P_0c0693fc;
P_0c0693fc: /* original c72a, guest PC 0x0c0693fc */
if(!s->budget--) { s->failed_pc=0x0c0693fcu; return 0; }
r[0]=code_base|0x000694a8u;
goto P_0c0693fe;
P_0c0693fe: /* original f3f8, guest PC 0x0c0693fe */
if(!s->budget--) { s->failed_pc=0x0c0693feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069400;
P_0c069400: /* original f408, guest PC 0x0c069400 */
if(!s->budget--) { s->failed_pc=0x0c069400u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069402;
P_0c069402: /* original e00c, guest PC 0x0c069402 */
if(!s->budget--) { s->failed_pc=0x0c069402u; return 0; }
r[0]=0x0000000cu;
goto P_0c069404;
P_0c069404: /* original ff37, guest PC 0x0c069404 */
if(!s->budget--) { s->failed_pc=0x0c069404u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069406;
P_0c069406: /* original e004, guest PC 0x0c069406 */
if(!s->budget--) { s->failed_pc=0x0c069406u; return 0; }
r[0]=0x00000004u;
goto P_0c069408;
P_0c069408: /* original f3f6, guest PC 0x0c069408 */
if(!s->budget--) { s->failed_pc=0x0c069408u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06940a;
P_0c06940a: /* original e008, guest PC 0x0c06940a */
if(!s->budget--) { s->failed_pc=0x0c06940au; return 0; }
r[0]=0x00000008u;
goto P_0c06940c;
P_0c06940c: /* original e71f, guest PC 0x0c06940c */
if(!s->budget--) { s->failed_pc=0x0c06940cu; return 0; }
r[7]=0x0000001fu;
goto P_0c06940e;
P_0c06940e: /* original ff37, guest PC 0x0c06940e */
if(!s->budget--) { s->failed_pc=0x0c06940eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069410;
P_0c069410: /* original e00c, guest PC 0x0c069410 */
if(!s->budget--) { s->failed_pc=0x0c069410u; return 0; }
r[0]=0x0000000cu;
goto P_0c069412;
P_0c069412: /* original f5f6, guest PC 0x0c069412 */
if(!s->budget--) { s->failed_pc=0x0c069412u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069414;
P_0c069414: /* original e008, guest PC 0x0c069414 */
if(!s->budget--) { s->failed_pc=0x0c069414u; return 0; }
r[0]=0x00000008u;
goto P_0c069416;
P_0c069416: /* original f34c, guest PC 0x0c069416 */
if(!s->budget--) { s->failed_pc=0x0c069416u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c069418;
P_0c069418: /* original f540, guest PC 0x0c069418 */
if(!s->budget--) { s->failed_pc=0x0c069418u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c06941a;
P_0c06941a: /* original f4f6, guest PC 0x0c06941a */
if(!s->budget--) { s->failed_pc=0x0c06941au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06941c;
P_0c06941c: /* original 903b, guest PC 0x0c06941c */
if(!s->budget--) { s->failed_pc=0x0c06941cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c069496u,2);
goto P_0c06941e;
P_0c06941e: /* original f430, guest PC 0x0c06941e */
if(!s->budget--) { s->failed_pc=0x0c06941eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c069420;
P_0c069420: /* original 035e, guest PC 0x0c069420 */
if(!s->budget--) { s->failed_pc=0x0c069420u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c069422;
P_0c069422: /* original f53d, guest PC 0x0c069422 */
if(!s->budget--) { s->failed_pc=0x0c069422u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c069424;
P_0c069424: /* original 045a, guest PC 0x0c069424 */
if(!s->budget--) { s->failed_pc=0x0c069424u; return 0; }
r[4]=r[53];
goto P_0c069426;
P_0c069426: /* original f43d, guest PC 0x0c069426 */
if(!s->budget--) { s->failed_pc=0x0c069426u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c069428;
P_0c069428: /* original 2479, guest PC 0x0c069428 */
if(!s->budget--) { s->failed_pc=0x0c069428u; return 0; }
r[4]&=r[7];
goto P_0c06942a;
P_0c06942a: /* original 065a, guest PC 0x0c06942a */
if(!s->budget--) { s->failed_pc=0x0c06942au; return 0; }
r[6]=r[53];
goto P_0c06942c;
P_0c06942c: /* original 2679, guest PC 0x0c06942c */
if(!s->budget--) { s->failed_pc=0x0c06942cu; return 0; }
r[6]&=r[7];
goto P_0c06942e;
P_0c06942e: /* original 4608, guest PC 0x0c06942e */
if(!s->budget--) { s->failed_pc=0x0c06942eu; return 0; }
r[6]<<=2;
goto P_0c069430;
P_0c069430: /* original 4608, guest PC 0x0c069430 */
if(!s->budget--) { s->failed_pc=0x0c069430u; return 0; }
r[6]<<=2;
goto P_0c069432;
P_0c069432: /* original 4600, guest PC 0x0c069432 */
if(!s->budget--) { s->failed_pc=0x0c069432u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c069434;
P_0c069434: /* original 246b, guest PC 0x0c069434 */
if(!s->budget--) { s->failed_pc=0x0c069434u; return 0; }
r[4]|=r[6];
goto P_0c069436;
P_0c069436: /* original 4408, guest PC 0x0c069436 */
if(!s->budget--) { s->failed_pc=0x0c069436u; return 0; }
r[4]<<=2;
goto P_0c069438;
P_0c069438: /* original 343c, guest PC 0x0c069438 */
if(!s->budget--) { s->failed_pc=0x0c069438u; return 0; }
r[4]+=r[3];
goto P_0c06943a;
P_0c06943a: /* original 6442, guest PC 0x0c06943a */
if(!s->budget--) { s->failed_pc=0x0c06943au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c06943c;
P_0c06943c: /* original 6043, guest PC 0x0c06943c */
if(!s->budget--) { s->failed_pc=0x0c06943cu; return 0; }
r[0]=r[4];
goto P_0c06943e;
P_0c06943e: /* original 88ff, guest PC 0x0c06943e */
if(!s->budget--) { s->failed_pc=0x0c06943eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c069440;
P_0c069440: /* original 8936, guest PC 0x0c069440 */
if(!s->budget--) { s->failed_pc=0x0c069440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0694b0; }
goto P_0c069442;
P_0c069442: /* original d21a, guest PC 0x0c069442 */
if(!s->budget--) { s->failed_pc=0x0c069442u; return 0; }
r[2]=read(ram,0x0c0694acu,4);
goto P_0c069444;
P_0c069444: /* original 6322, guest PC 0x0c069444 */
if(!s->budget--) { s->failed_pc=0x0c069444u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c069446;
P_0c069446: /* original 343c, guest PC 0x0c069446 */
if(!s->budget--) { s->failed_pc=0x0c069446u; return 0; }
r[4]+=r[3];
goto P_0c069448;
P_0c069448: /* original 6e43, guest PC 0x0c069448 */
if(!s->budget--) { s->failed_pc=0x0c069448u; return 0; }
r[14]=r[4];
goto P_0c06944a;
P_0c06944a: /* original 60e2, guest PC 0x0c06944a */
if(!s->budget--) { s->failed_pc=0x0c06944au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c06944c;
P_0c06944c: /* original 88ff, guest PC 0x0c06944c */
if(!s->budget--) { s->failed_pc=0x0c06944cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c06944e;
P_0c06944e: /* original 8d2f, guest PC 0x0c06944e */
if(!s->budget--) { s->failed_pc=0x0c06944eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0694b0; }
goto P_0c069452;
P_0c069450: /* original 6403, guest PC 0x0c069450 */
if(!s->budget--) { s->failed_pc=0x0c069450u; return 0; }
r[4]=r[0];
goto P_0c069452;
P_0c069452: /* original e008, guest PC 0x0c069452 */
if(!s->budget--) { s->failed_pc=0x0c069452u; return 0; }
r[0]=0x00000008u;
goto P_0c069454;
P_0c069454: /* original f5f6, guest PC 0x0c069454 */
if(!s->budget--) { s->failed_pc=0x0c069454u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069456;
P_0c069456: /* original e00c, guest PC 0x0c069456 */
if(!s->budget--) { s->failed_pc=0x0c069456u; return 0; }
r[0]=0x0000000cu;
goto P_0c069458;
P_0c069458: /* original f4f6, guest PC 0x0c069458 */
if(!s->budget--) { s->failed_pc=0x0c069458u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06945a;
P_0c06945a: /* original bdc3, guest PC 0x0c06945a */
if(!s->budget--) { s->failed_pc=0x0c06945au; return 0; }
target=code_base|0x0c068fe4u; r[16]=code_base|0x0c06945eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06945eu) { target=s->pc; goto dispatch; }
goto P_0c06945e;
P_0c06945c: /* original 64e3, guest PC 0x0c06945c */
if(!s->budget--) { s->failed_pc=0x0c06945cu; return 0; }
r[4]=r[14];
goto P_0c06945e;
P_0c06945e: /* original 6703, guest PC 0x0c06945e */
if(!s->budget--) { s->failed_pc=0x0c06945eu; return 0; }
r[7]=r[0];
goto P_0c069460;
P_0c069460: /* original 2778, guest PC 0x0c069460 */
if(!s->budget--) { s->failed_pc=0x0c069460u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c069462;
P_0c069462: /* original 8916, guest PC 0x0c069462 */
if(!s->budget--) { s->failed_pc=0x0c069462u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069492; }
goto P_0c069464;
P_0c069464: /* original e008, guest PC 0x0c069464 */
if(!s->budget--) { s->failed_pc=0x0c069464u; return 0; }
r[0]=0x00000008u;
goto P_0c069466;
P_0c069466: /* original 66f3, guest PC 0x0c069466 */
if(!s->budget--) { s->failed_pc=0x0c069466u; return 0; }
r[6]=r[15];
goto P_0c069468;
P_0c069468: /* original f5f6, guest PC 0x0c069468 */
if(!s->budget--) { s->failed_pc=0x0c069468u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06946a;
P_0c06946a: /* original e00c, guest PC 0x0c06946a */
if(!s->budget--) { s->failed_pc=0x0c06946au; return 0; }
r[0]=0x0000000cu;
goto P_0c06946c;
P_0c06946c: /* original f4f6, guest PC 0x0c06946c */
if(!s->budget--) { s->failed_pc=0x0c06946cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06946e;
P_0c06946e: /* original 761c, guest PC 0x0c06946e */
if(!s->budget--) { s->failed_pc=0x0c06946eu; return 0; }
r[6]+=0x0000001cu;
goto P_0c069470;
P_0c069470: /* original 65d3, guest PC 0x0c069470 */
if(!s->budget--) { s->failed_pc=0x0c069470u; return 0; }
r[5]=r[13];
goto P_0c069472;
P_0c069472: /* original bf18, guest PC 0x0c069472 */
if(!s->budget--) { s->failed_pc=0x0c069472u; return 0; }
target=code_base|0x0c0692a6u; r[16]=code_base|0x0c069476u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069476u) { target=s->pc; goto dispatch; }
goto P_0c069476;
P_0c069474: /* original 64e3, guest PC 0x0c069474 */
if(!s->budget--) { s->failed_pc=0x0c069474u; return 0; }
r[4]=r[14];
goto P_0c069476;
P_0c069476: /* original 6e03, guest PC 0x0c069476 */
if(!s->budget--) { s->failed_pc=0x0c069476u; return 0; }
r[14]=r[0];
goto P_0c069478;
P_0c069478: /* original e01c, guest PC 0x0c069478 */
if(!s->budget--) { s->failed_pc=0x0c069478u; return 0; }
r[0]=0x0000001cu;
goto P_0c06947a;
P_0c06947a: /* original f3f6, guest PC 0x0c06947a */
if(!s->budget--) { s->failed_pc=0x0c06947au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06947c;
P_0c06947c: /* original e014, guest PC 0x0c06947c */
if(!s->budget--) { s->failed_pc=0x0c06947cu; return 0; }
r[0]=0x00000014u;
goto P_0c06947e;
P_0c06947e: /* original ff37, guest PC 0x0c06947e */
if(!s->budget--) { s->failed_pc=0x0c06947eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069480;
P_0c069480: /* original e020, guest PC 0x0c069480 */
if(!s->budget--) { s->failed_pc=0x0c069480u; return 0; }
r[0]=0x00000020u;
goto P_0c069482;
P_0c069482: /* original f3f6, guest PC 0x0c069482 */
if(!s->budget--) { s->failed_pc=0x0c069482u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069484;
P_0c069484: /* original e018, guest PC 0x0c069484 */
if(!s->budget--) { s->failed_pc=0x0c069484u; return 0; }
r[0]=0x00000018u;
goto P_0c069486;
P_0c069486: /* original ff37, guest PC 0x0c069486 */
if(!s->budget--) { s->failed_pc=0x0c069486u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069488;
P_0c069488: /* original e024, guest PC 0x0c069488 */
if(!s->budget--) { s->failed_pc=0x0c069488u; return 0; }
r[0]=0x00000024u;
goto P_0c06948a;
P_0c06948a: /* original f3f6, guest PC 0x0c06948a */
if(!s->budget--) { s->failed_pc=0x0c06948au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06948c;
P_0c06948c: /* original e010, guest PC 0x0c06948c */
if(!s->budget--) { s->failed_pc=0x0c06948cu; return 0; }
r[0]=0x00000010u;
goto P_0c06948e;
P_0c06948e: /* original a018, guest PC 0x0c06948e */
if(!s->budget--) { s->failed_pc=0x0c06948eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694c2;
P_0c069490: /* original ff37, guest PC 0x0c069490 */
if(!s->budget--) { s->failed_pc=0x0c069490u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069492;
P_0c069492: /* original afda, guest PC 0x0c069492 */
if(!s->budget--) { s->failed_pc=0x0c069492u; return 0; }
r[14]+=0x00000008u;
goto P_0c06944a;
P_0c069494: /* original 7e08, guest PC 0x0c069494 */
if(!s->budget--) { s->failed_pc=0x0c069494u; return 0; }
r[14]+=0x00000008u;
if(!vf3_matrix_family(0x0c069496u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069496u; return 0; } return 1;
P_0c0694b0: /* original fdfa, guest PC 0x0c0694b0 */
if(!s->budget--) { s->failed_pc=0x0c0694b0u; return 0; }
vf3_matrix_store(s,ram,15,r[13]);
goto P_0c0694b2;
P_0c0694b2: /* original ee02, guest PC 0x0c0694b2 */
if(!s->budget--) { s->failed_pc=0x0c0694b2u; return 0; }
r[14]=0x00000002u;
goto P_0c0694b4;
P_0c0694b4: /* original e018, guest PC 0x0c0694b4 */
if(!s->budget--) { s->failed_pc=0x0c0694b4u; return 0; }
r[0]=0x00000018u;
goto P_0c0694b6;
P_0c0694b6: /* original f39d, guest PC 0x0c0694b6 */
if(!s->budget--) { s->failed_pc=0x0c0694b6u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0694b8;
P_0c0694b8: /* original ff37, guest PC 0x0c0694b8 */
if(!s->budget--) { s->failed_pc=0x0c0694b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0694ba;
P_0c0694ba: /* original e010, guest PC 0x0c0694ba */
if(!s->budget--) { s->failed_pc=0x0c0694bau; return 0; }
r[0]=0x00000010u;
goto P_0c0694bc;
P_0c0694bc: /* original fff7, guest PC 0x0c0694bc */
if(!s->budget--) { s->failed_pc=0x0c0694bcu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694be;
P_0c0694be: /* original e014, guest PC 0x0c0694be */
if(!s->budget--) { s->failed_pc=0x0c0694beu; return 0; }
r[0]=0x00000014u;
goto P_0c0694c0;
P_0c0694c0: /* original fff7, guest PC 0x0c0694c0 */
if(!s->budget--) { s->failed_pc=0x0c0694c0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0694c2;
P_0c0694c2: /* original 60c3, guest PC 0x0c0694c2 */
if(!s->budget--) { s->failed_pc=0x0c0694c2u; return 0; }
r[0]=r[12];
goto P_0c0694c4;
P_0c0694c4: /* original 880d, guest PC 0x0c0694c4 */
if(!s->budget--) { s->failed_pc=0x0c0694c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0694c6;
P_0c0694c6: /* original 8b02, guest PC 0x0c0694c6 */
if(!s->budget--) { s->failed_pc=0x0c0694c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694ce; }
goto P_0c0694c8;
P_0c0694c8: /* original e204, guest PC 0x0c0694c8 */
if(!s->budget--) { s->failed_pc=0x0c0694c8u; return 0; }
r[2]=0x00000004u;
goto P_0c0694ca;
P_0c0694ca: /* original a012, guest PC 0x0c0694ca */
if(!s->budget--) { s->failed_pc=0x0c0694cau; return 0; }
r[14]|=r[2];
goto P_0c0694f2;
P_0c0694cc: /* original 2e2b, guest PC 0x0c0694cc */
if(!s->budget--) { s->failed_pc=0x0c0694ccu; return 0; }
r[14]|=r[2];
goto P_0c0694ce;
P_0c0694ce: /* original 880b, guest PC 0x0c0694ce */
if(!s->budget--) { s->failed_pc=0x0c0694ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0694d0;
P_0c0694d0: /* original 8b0f, guest PC 0x0c0694d0 */
if(!s->budget--) { s->failed_pc=0x0c0694d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0694f2; }
goto P_0c0694d2;
P_0c0694d2: /* original 63f3, guest PC 0x0c0694d2 */
if(!s->budget--) { s->failed_pc=0x0c0694d2u; return 0; }
r[3]=r[15];
goto P_0c0694d4;
P_0c0694d4: /* original 7310, guest PC 0x0c0694d4 */
if(!s->budget--) { s->failed_pc=0x0c0694d4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0694d6;
P_0c0694d6: /* original 2f36, guest PC 0x0c0694d6 */
if(!s->budget--) { s->failed_pc=0x0c0694d6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694d8;
P_0c0694d8: /* original 65d3, guest PC 0x0c0694d8 */
if(!s->budget--) { s->failed_pc=0x0c0694d8u; return 0; }
r[5]=r[13];
goto P_0c0694da;
P_0c0694da: /* original 62f3, guest PC 0x0c0694da */
if(!s->budget--) { s->failed_pc=0x0c0694dau; return 0; }
r[2]=r[15];
goto P_0c0694dc;
P_0c0694dc: /* original 721c, guest PC 0x0c0694dc */
if(!s->budget--) { s->failed_pc=0x0c0694dcu; return 0; }
r[2]+=0x0000001cu;
goto P_0c0694de;
P_0c0694de: /* original 2f26, guest PC 0x0c0694de */
if(!s->budget--) { s->failed_pc=0x0c0694deu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0694e0;
P_0c0694e0: /* original 66f3, guest PC 0x0c0694e0 */
if(!s->budget--) { s->failed_pc=0x0c0694e0u; return 0; }
r[6]=r[15];
goto P_0c0694e2;
P_0c0694e2: /* original d348, guest PC 0x0c0694e2 */
if(!s->budget--) { s->failed_pc=0x0c0694e2u; return 0; }
r[3]=read(ram,0x0c069604u,4);
goto P_0c0694e4;
P_0c0694e4: /* original 67f3, guest PC 0x0c0694e4 */
if(!s->budget--) { s->failed_pc=0x0c0694e4u; return 0; }
r[7]=r[15];
goto P_0c0694e6;
P_0c0694e6: /* original 64f3, guest PC 0x0c0694e6 */
if(!s->budget--) { s->failed_pc=0x0c0694e6u; return 0; }
r[4]=r[15];
goto P_0c0694e8;
P_0c0694e8: /* original 771c, guest PC 0x0c0694e8 */
if(!s->budget--) { s->failed_pc=0x0c0694e8u; return 0; }
r[7]+=0x0000001cu;
goto P_0c0694ea;
P_0c0694ea: /* original 7610, guest PC 0x0c0694ea */
if(!s->budget--) { s->failed_pc=0x0c0694eau; return 0; }
r[6]+=0x00000010u;
goto P_0c0694ec;
P_0c0694ec: /* original 430b, guest PC 0x0c0694ec */
if(!s->budget--) { s->failed_pc=0x0c0694ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0694f0u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0694f0u) { target=s->pc; goto dispatch; }
goto P_0c0694f0;
P_0c0694ee: /* original 7414, guest PC 0x0c0694ee */
if(!s->budget--) { s->failed_pc=0x0c0694eeu; return 0; }
r[4]+=0x00000014u;
goto P_0c0694f0;
P_0c0694f0: /* original 7f08, guest PC 0x0c0694f0 */
if(!s->budget--) { s->failed_pc=0x0c0694f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0694f2;
P_0c0694f2: /* original e014, guest PC 0x0c0694f2 */
if(!s->budget--) { s->failed_pc=0x0c0694f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0694f4;
P_0c0694f4: /* original f3f6, guest PC 0x0c0694f4 */
if(!s->budget--) { s->failed_pc=0x0c0694f4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694f6;
P_0c0694f6: /* original e018, guest PC 0x0c0694f6 */
if(!s->budget--) { s->failed_pc=0x0c0694f6u; return 0; }
r[0]=0x00000018u;
goto P_0c0694f8;
P_0c0694f8: /* original fb3a, guest PC 0x0c0694f8 */
if(!s->budget--) { s->failed_pc=0x0c0694f8u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c0694fa;
P_0c0694fa: /* original f3f6, guest PC 0x0c0694fa */
if(!s->budget--) { s->failed_pc=0x0c0694fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0694fc;
P_0c0694fc: /* original e004, guest PC 0x0c0694fc */
if(!s->budget--) { s->failed_pc=0x0c0694fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0694fe;
P_0c0694fe: /* original fb37, guest PC 0x0c0694fe */
if(!s->budget--) { s->failed_pc=0x0c0694feu; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069500;
P_0c069500: /* original e010, guest PC 0x0c069500 */
if(!s->budget--) { s->failed_pc=0x0c069500u; return 0; }
r[0]=0x00000010u;
goto P_0c069502;
P_0c069502: /* original f3f6, guest PC 0x0c069502 */
if(!s->budget--) { s->failed_pc=0x0c069502u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069504;
P_0c069504: /* original e008, guest PC 0x0c069504 */
if(!s->budget--) { s->failed_pc=0x0c069504u; return 0; }
r[0]=0x00000008u;
goto P_0c069506;
P_0c069506: /* original fb37, guest PC 0x0c069506 */
if(!s->budget--) { s->failed_pc=0x0c069506u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c069508;
P_0c069508: /* original 60e3, guest PC 0x0c069508 */
if(!s->budget--) { s->failed_pc=0x0c069508u; return 0; }
r[0]=r[14];
goto P_0c06950a;
P_0c06950a: /* original 7f28, guest PC 0x0c06950a */
if(!s->budget--) { s->failed_pc=0x0c06950au; return 0; }
r[15]+=0x00000028u;
goto P_0c06950c;
P_0c06950c: /* original 4f26, guest PC 0x0c06950c */
if(!s->budget--) { s->failed_pc=0x0c06950cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06950e;
P_0c06950e: /* original fff9, guest PC 0x0c06950e */
if(!s->budget--) { s->failed_pc=0x0c06950eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069510;
P_0c069510: /* original 6bf6, guest PC 0x0c069510 */
if(!s->budget--) { s->failed_pc=0x0c069510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c069512;
P_0c069512: /* original 6cf6, guest PC 0x0c069512 */
if(!s->budget--) { s->failed_pc=0x0c069512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069514;
P_0c069514: /* original 6df6, guest PC 0x0c069514 */
if(!s->budget--) { s->failed_pc=0x0c069514u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069516;
P_0c069516: /* original 000b, guest PC 0x0c069516 */
if(!s->budget--) { s->failed_pc=0x0c069516u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069518: /* original 6ef6, guest PC 0x0c069518 */
if(!s->budget--) { s->failed_pc=0x0c069518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06951au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06951au; return 0; } return 1;
P_0c0696c6: /* original 4f22, guest PC 0x0c0696c6 */
if(!s->budget--) { s->failed_pc=0x0c0696c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0696c8;
P_0c0696c8: /* original 7ff8, guest PC 0x0c0696c8 */
if(!s->budget--) { s->failed_pc=0x0c0696c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0696ca;
P_0c0696ca: /* original 1f41, guest PC 0x0c0696ca */
if(!s->budget--) { s->failed_pc=0x0c0696cau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0696cc;
P_0c0696cc: /* original 2f52, guest PC 0x0c0696cc */
if(!s->budget--) { s->failed_pc=0x0c0696ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0696ce;
P_0c0696ce: /* original d33c, guest PC 0x0c0696ce */
if(!s->budget--) { s->failed_pc=0x0c0696ceu; return 0; }
r[3]=read(ram,0x0c0697c0u,4);
goto P_0c0696d0;
P_0c0696d0: /* original 430b, guest PC 0x0c0696d0 */
if(!s->budget--) { s->failed_pc=0x0c0696d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0696d4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0696d4u) { target=s->pc; goto dispatch; }
goto P_0c0696d4;
P_0c0696d2: /* original 54f1, guest PC 0x0c0696d2 */
if(!s->budget--) { s->failed_pc=0x0c0696d2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696d4;
P_0c0696d4: /* original 62f2, guest PC 0x0c0696d4 */
if(!s->budget--) { s->failed_pc=0x0c0696d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0696d6;
P_0c0696d6: /* original 302c, guest PC 0x0c0696d6 */
if(!s->budget--) { s->failed_pc=0x0c0696d6u; return 0; }
r[0]+=r[2];
goto P_0c0696d8;
P_0c0696d8: /* original 2f02, guest PC 0x0c0696d8 */
if(!s->budget--) { s->failed_pc=0x0c0696d8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0696da;
P_0c0696da: /* original 6503, guest PC 0x0c0696da */
if(!s->budget--) { s->failed_pc=0x0c0696dau; return 0; }
r[5]=r[0];
goto P_0c0696dc;
P_0c0696dc: /* original 54f1, guest PC 0x0c0696dc */
if(!s->budget--) { s->failed_pc=0x0c0696dcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696de;
P_0c0696de: /* original 7f08, guest PC 0x0c0696de */
if(!s->budget--) { s->failed_pc=0x0c0696deu; return 0; }
r[15]+=0x00000008u;
goto P_0c0696e0;
P_0c0696e0: /* original d338, guest PC 0x0c0696e0 */
if(!s->budget--) { s->failed_pc=0x0c0696e0u; return 0; }
r[3]=read(ram,0x0c0697c4u,4);
goto P_0c0696e2;
P_0c0696e2: /* original 432b, guest PC 0x0c0696e2 */
if(!s->budget--) { s->failed_pc=0x0c0696e2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0c66d8u: return vf3_matrix_family(0x0c0c66d8u,s,ram);
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
P_0c0696e4: /* original 4f26, guest PC 0x0c0696e4 */
if(!s->budget--) { s->failed_pc=0x0c0696e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0696e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0696e6u; return 0; } return 1;
P_0c06972a: /* original 2fe6, guest PC 0x0c06972a */
if(!s->budget--) { s->failed_pc=0x0c06972au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06972c;
P_0c06972c: /* original e029, guest PC 0x0c06972c */
if(!s->budget--) { s->failed_pc=0x0c06972cu; return 0; }
r[0]=0x00000029u;
goto P_0c06972e;
P_0c06972e: /* original 2fd6, guest PC 0x0c06972e */
if(!s->budget--) { s->failed_pc=0x0c06972eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069730;
P_0c069730: /* original 2fc6, guest PC 0x0c069730 */
if(!s->budget--) { s->failed_pc=0x0c069730u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069732;
P_0c069732: /* original d427, guest PC 0x0c069732 */
if(!s->budget--) { s->failed_pc=0x0c069732u; return 0; }
r[4]=read(ram,0x0c0697d0u,4);
goto P_0c069734;
P_0c069734: /* original 4f22, guest PC 0x0c069734 */
if(!s->budget--) { s->failed_pc=0x0c069734u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c069736;
P_0c069736: /* original 5341, guest PC 0x0c069736 */
if(!s->budget--) { s->failed_pc=0x0c069736u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c069738;
P_0c069738: /* original 6c42, guest PC 0x0c069738 */
if(!s->budget--) { s->failed_pc=0x0c069738u; return 0; }
tmp=read(ram,r[4],4);
r[12]=tmp;
goto P_0c06973a;
P_0c06973a: /* original 7ff8, guest PC 0x0c06973a */
if(!s->budget--) { s->failed_pc=0x0c06973au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06973c;
P_0c06973c: /* original dd1f, guest PC 0x0c06973c */
if(!s->budget--) { s->failed_pc=0x0c06973cu; return 0; }
r[13]=read(ram,0x0c0697bcu,4);
goto P_0c06973e;
P_0c06973e: /* original 1f31, guest PC 0x0c06973e */
if(!s->budget--) { s->failed_pc=0x0c06973eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c069740;
P_0c069740: /* original de24, guest PC 0x0c069740 */
if(!s->budget--) { s->failed_pc=0x0c069740u; return 0; }
r[14]=read(ram,0x0c0697d4u,4);
goto P_0c069742;
P_0c069742: /* original 9236, guest PC 0x0c069742 */
if(!s->budget--) { s->failed_pc=0x0c069742u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b2u,2);
goto P_0c069744;
P_0c069744: /* original 03ec, guest PC 0x0c069744 */
if(!s->budget--) { s->failed_pc=0x0c069744u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c069746;
P_0c069746: /* original 22c8, guest PC 0x0c069746 */
if(!s->budget--) { s->failed_pc=0x0c069746u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c069748;
P_0c069748: /* original 633c, guest PC 0x0c069748 */
if(!s->budget--) { s->failed_pc=0x0c069748u; return 0; }
r[3]=r[3]&255u;
goto P_0c06974a;
P_0c06974a: /* original 8f55, guest PC 0x0c06974a */
if(!s->budget--) { s->failed_pc=0x0c06974au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c0697f8; }
goto P_0c06974e;
P_0c06974c: /* original 2f32, guest PC 0x0c06974c */
if(!s->budget--) { s->failed_pc=0x0c06974cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06974e;
P_0c06974e: /* original 64d3, guest PC 0x0c06974e */
if(!s->budget--) { s->failed_pc=0x0c06974eu; return 0; }
r[4]=r[13];
goto P_0c069750;
P_0c069750: /* original e501, guest PC 0x0c069750 */
if(!s->budget--) { s->failed_pc=0x0c069750u; return 0; }
r[5]=0x00000001u;
goto P_0c069752;
P_0c069752: /* original bfb8, guest PC 0x0c069752 */
if(!s->budget--) { s->failed_pc=0x0c069752u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069756u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069756u) { target=s->pc; goto dispatch; }
goto P_0c069756;
P_0c069754: /* original 741c, guest PC 0x0c069754 */
if(!s->budget--) { s->failed_pc=0x0c069754u; return 0; }
r[4]+=0x0000001cu;
goto P_0c069756;
P_0c069756: /* original d220, guest PC 0x0c069756 */
if(!s->budget--) { s->failed_pc=0x0c069756u; return 0; }
r[2]=read(ram,0x0c0697d8u,4);
goto P_0c069758;
P_0c069758: /* original 22c8, guest PC 0x0c069758 */
if(!s->budget--) { s->failed_pc=0x0c069758u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c06975a;
P_0c06975a: /* original 8b4d, guest PC 0x0c06975a */
if(!s->budget--) { s->failed_pc=0x0c06975au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0697f8; }
goto P_0c06975c;
P_0c06975c: /* original d31f, guest PC 0x0c06975c */
if(!s->budget--) { s->failed_pc=0x0c06975cu; return 0; }
r[3]=read(ram,0x0c0697dcu,4);
goto P_0c06975e;
P_0c06975e: /* original 23c8, guest PC 0x0c06975e */
if(!s->budget--) { s->failed_pc=0x0c06975eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c069760;
P_0c069760: /* original 8b46, guest PC 0x0c069760 */
if(!s->budget--) { s->failed_pc=0x0c069760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0697f0; }
goto P_0c069762;
P_0c069762: /* original d120, guest PC 0x0c069762 */
if(!s->budget--) { s->failed_pc=0x0c069762u; return 0; }
r[1]=read(ram,0x0c0697e4u,4);
goto P_0c069764;
P_0c069764: /* original d31e, guest PC 0x0c069764 */
if(!s->budget--) { s->failed_pc=0x0c069764u; return 0; }
r[3]=read(ram,0x0c0697e0u,4);
goto P_0c069766;
P_0c069766: /* original 6212, guest PC 0x0c069766 */
if(!s->budget--) { s->failed_pc=0x0c069766u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c069768;
P_0c069768: /* original 2238, guest PC 0x0c069768 */
if(!s->budget--) { s->failed_pc=0x0c069768u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06976a;
P_0c06976a: /* original 8b41, guest PC 0x0c06976a */
if(!s->budget--) { s->failed_pc=0x0c06976au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0697f0; }
goto P_0c06976c;
P_0c06976c: /* original 9420, guest PC 0x0c06976c */
if(!s->budget--) { s->failed_pc=0x0c06976cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b0u,2);
goto P_0c06976e;
P_0c06976e: /* original e501, guest PC 0x0c06976e */
if(!s->budget--) { s->failed_pc=0x0c06976eu; return 0; }
r[5]=0x00000001u;
goto P_0c069770;
P_0c069770: /* original bfa9, guest PC 0x0c069770 */
if(!s->budget--) { s->failed_pc=0x0c069770u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069774u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069774u) { target=s->pc; goto dispatch; }
goto P_0c069774;
P_0c069772: /* original 34dc, guest PC 0x0c069772 */
if(!s->budget--) { s->failed_pc=0x0c069772u; return 0; }
r[4]+=r[13];
goto P_0c069774;
P_0c069774: /* original d21c, guest PC 0x0c069774 */
if(!s->budget--) { s->failed_pc=0x0c069774u; return 0; }
r[2]=read(ram,0x0c0697e8u,4);
goto P_0c069776;
P_0c069776: /* original 2c28, guest PC 0x0c069776 */
if(!s->budget--) { s->failed_pc=0x0c069776u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[2])==0)!=0);
goto P_0c069778;
P_0c069778: /* original 8914, guest PC 0x0c069778 */
if(!s->budget--) { s->failed_pc=0x0c069778u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0697a4; }
goto P_0c06977a;
P_0c06977a: /* original 51f1, guest PC 0x0c06977a */
if(!s->budget--) { s->failed_pc=0x0c06977au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06977c;
P_0c06977c: /* original d31b, guest PC 0x0c06977c */
if(!s->budget--) { s->failed_pc=0x0c06977cu; return 0; }
r[3]=read(ram,0x0c0697ecu,4);
goto P_0c06977e;
P_0c06977e: /* original 2138, guest PC 0x0c06977e */
if(!s->budget--) { s->failed_pc=0x0c06977eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c069780;
P_0c069780: /* original 8910, guest PC 0x0c069780 */
if(!s->budget--) { s->failed_pc=0x0c069780u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0697a4; }
goto P_0c069782;
P_0c069782: /* original 60f2, guest PC 0x0c069782 */
if(!s->budget--) { s->failed_pc=0x0c069782u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c069784;
P_0c069784: /* original 8803, guest PC 0x0c069784 */
if(!s->budget--) { s->failed_pc=0x0c069784u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c069786;
P_0c069786: /* original 8904, guest PC 0x0c069786 */
if(!s->budget--) { s->failed_pc=0x0c069786u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069792; }
goto P_0c069788;
P_0c069788: /* original 9014, guest PC 0x0c069788 */
if(!s->budget--) { s->failed_pc=0x0c069788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b4u,2);
goto P_0c06978a;
P_0c06978a: /* original 03ee, guest PC 0x0c06978a */
if(!s->budget--) { s->failed_pc=0x0c06978au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c06978c;
P_0c06978c: /* original 7301, guest PC 0x0c06978c */
if(!s->budget--) { s->failed_pc=0x0c06978cu; return 0; }
r[3]+=0x00000001u;
goto P_0c06978e;
P_0c06978e: /* original a033, guest PC 0x0c06978e */
if(!s->budget--) { s->failed_pc=0x0c06978eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0697f8;
P_0c069790: /* original 0e36, guest PC 0x0c069790 */
if(!s->budget--) { s->failed_pc=0x0c069790u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c069792;
P_0c069792: /* original 9010, guest PC 0x0c069792 */
if(!s->budget--) { s->failed_pc=0x0c069792u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b6u,2);
goto P_0c069794;
P_0c069794: /* original 03ee, guest PC 0x0c069794 */
if(!s->budget--) { s->failed_pc=0x0c069794u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c069796;
P_0c069796: /* original 7301, guest PC 0x0c069796 */
if(!s->budget--) { s->failed_pc=0x0c069796u; return 0; }
r[3]+=0x00000001u;
goto P_0c069798;
P_0c069798: /* original 0e36, guest PC 0x0c069798 */
if(!s->budget--) { s->failed_pc=0x0c069798u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c06979a;
P_0c06979a: /* original 900d, guest PC 0x0c06979a */
if(!s->budget--) { s->failed_pc=0x0c06979au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b8u,2);
goto P_0c06979c;
P_0c06979c: /* original 02ee, guest PC 0x0c06979c */
if(!s->budget--) { s->failed_pc=0x0c06979cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c06979e;
P_0c06979e: /* original 7201, guest PC 0x0c06979e */
if(!s->budget--) { s->failed_pc=0x0c06979eu; return 0; }
r[2]+=0x00000001u;
goto P_0c0697a0;
P_0c0697a0: /* original a02a, guest PC 0x0c0697a0 */
if(!s->budget--) { s->failed_pc=0x0c0697a0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0697f8;
P_0c0697a2: /* original 0e26, guest PC 0x0c0697a2 */
if(!s->budget--) { s->failed_pc=0x0c0697a2u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0697a4;
P_0c0697a4: /* original 9009, guest PC 0x0c0697a4 */
if(!s->budget--) { s->failed_pc=0x0c0697a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697bau,2);
goto P_0c0697a6;
P_0c0697a6: /* original 02ee, guest PC 0x0c0697a6 */
if(!s->budget--) { s->failed_pc=0x0c0697a6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0697a8;
P_0c0697a8: /* original 7201, guest PC 0x0c0697a8 */
if(!s->budget--) { s->failed_pc=0x0c0697a8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0697aa;
P_0c0697aa: /* original a025, guest PC 0x0c0697aa */
if(!s->budget--) { s->failed_pc=0x0c0697aau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0697f8;
P_0c0697ac: /* original 0e26, guest PC 0x0c0697ac */
if(!s->budget--) { s->failed_pc=0x0c0697acu; return 0; }
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c0697aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0697aeu; return 0; } return 1;
P_0c0697f0: /* original 64d3, guest PC 0x0c0697f0 */
if(!s->budget--) { s->failed_pc=0x0c0697f0u; return 0; }
r[4]=r[13];
goto P_0c0697f2;
P_0c0697f2: /* original e501, guest PC 0x0c0697f2 */
if(!s->budget--) { s->failed_pc=0x0c0697f2u; return 0; }
r[5]=0x00000001u;
goto P_0c0697f4;
P_0c0697f4: /* original bf67, guest PC 0x0c0697f4 */
if(!s->budget--) { s->failed_pc=0x0c0697f4u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c0697f8u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0697f8u) { target=s->pc; goto dispatch; }
goto P_0c0697f8;
P_0c0697f6: /* original 7434, guest PC 0x0c0697f6 */
if(!s->budget--) { s->failed_pc=0x0c0697f6u; return 0; }
r[4]+=0x00000034u;
goto P_0c0697f8;
P_0c0697f8: /* original 9071, guest PC 0x0c0697f8 */
if(!s->budget--) { s->failed_pc=0x0c0697f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0698deu,2);
goto P_0c0697fa;
P_0c0697fa: /* original 64d3, guest PC 0x0c0697fa */
if(!s->budget--) { s->failed_pc=0x0c0697fau; return 0; }
r[4]=r[13];
goto P_0c0697fc;
P_0c0697fc: /* original 05ec, guest PC 0x0c0697fc */
if(!s->budget--) { s->failed_pc=0x0c0697fcu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0697fe;
P_0c0697fe: /* original 7001, guest PC 0x0c0697fe */
if(!s->budget--) { s->failed_pc=0x0c0697feu; return 0; }
r[0]+=0x00000001u;
goto P_0c069800;
P_0c069800: /* original 0cec, guest PC 0x0c069800 */
if(!s->budget--) { s->failed_pc=0x0c069800u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c069802;
P_0c069802: /* original 6353, guest PC 0x0c069802 */
if(!s->budget--) { s->failed_pc=0x0c069802u; return 0; }
r[3]=r[5];
goto P_0c069804;
P_0c069804: /* original 33cc, guest PC 0x0c069804 */
if(!s->budget--) { s->failed_pc=0x0c069804u; return 0; }
r[3]+=r[12];
goto P_0c069806;
P_0c069806: /* original 2f32, guest PC 0x0c069806 */
if(!s->budget--) { s->failed_pc=0x0c069806u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c069808;
P_0c069808: /* original bf5d, guest PC 0x0c069808 */
if(!s->budget--) { s->failed_pc=0x0c069808u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06980cu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06980cu) { target=s->pc; goto dispatch; }
goto P_0c06980c;
P_0c06980a: /* original 7404, guest PC 0x0c06980a */
if(!s->budget--) { s->failed_pc=0x0c06980au; return 0; }
r[4]+=0x00000004u;
goto P_0c06980c;
P_0c06980c: /* original 64d3, guest PC 0x0c06980c */
if(!s->budget--) { s->failed_pc=0x0c06980cu; return 0; }
r[4]=r[13];
goto P_0c06980e;
P_0c06980e: /* original 65c3, guest PC 0x0c06980e */
if(!s->budget--) { s->failed_pc=0x0c06980eu; return 0; }
r[5]=r[12];
goto P_0c069810;
P_0c069810: /* original bf59, guest PC 0x0c069810 */
if(!s->budget--) { s->failed_pc=0x0c069810u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069814u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069814u) { target=s->pc; goto dispatch; }
goto P_0c069814;
P_0c069812: /* original 7408, guest PC 0x0c069812 */
if(!s->budget--) { s->failed_pc=0x0c069812u; return 0; }
r[4]+=0x00000008u;
goto P_0c069814;
P_0c069814: /* original 65f2, guest PC 0x0c069814 */
if(!s->budget--) { s->failed_pc=0x0c069814u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c069816;
P_0c069816: /* original bf56, guest PC 0x0c069816 */
if(!s->budget--) { s->failed_pc=0x0c069816u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06981au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06981au) { target=s->pc; goto dispatch; }
goto P_0c06981a;
P_0c069818: /* original 64d3, guest PC 0x0c069818 */
if(!s->budget--) { s->failed_pc=0x0c069818u; return 0; }
r[4]=r[13];
goto P_0c06981a;
P_0c06981a: /* original 9061, guest PC 0x0c06981a */
if(!s->budget--) { s->failed_pc=0x0c06981au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0698e0u,2);
goto P_0c06981c;
P_0c06981c: /* original 64d3, guest PC 0x0c06981c */
if(!s->budget--) { s->failed_pc=0x0c06981cu; return 0; }
r[4]=r[13];
goto P_0c06981e;
P_0c06981e: /* original 05ec, guest PC 0x0c06981e */
if(!s->budget--) { s->failed_pc=0x0c06981eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c069820;
P_0c069820: /* original 7001, guest PC 0x0c069820 */
if(!s->budget--) { s->failed_pc=0x0c069820u; return 0; }
r[0]+=0x00000001u;
goto P_0c069822;
P_0c069822: /* original 0cec, guest PC 0x0c069822 */
if(!s->budget--) { s->failed_pc=0x0c069822u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c069824;
P_0c069824: /* original 7001, guest PC 0x0c069824 */
if(!s->budget--) { s->failed_pc=0x0c069824u; return 0; }
r[0]+=0x00000001u;
goto P_0c069826;
P_0c069826: /* original 6253, guest PC 0x0c069826 */
if(!s->budget--) { s->failed_pc=0x0c069826u; return 0; }
r[2]=r[5];
goto P_0c069828;
P_0c069828: /* original 03ec, guest PC 0x0c069828 */
if(!s->budget--) { s->failed_pc=0x0c069828u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06982a;
P_0c06982a: /* original 32cc, guest PC 0x0c06982a */
if(!s->budget--) { s->failed_pc=0x0c06982au; return 0; }
r[2]+=r[12];
goto P_0c06982c;
P_0c06982c: /* original 1f31, guest PC 0x0c06982c */
if(!s->budget--) { s->failed_pc=0x0c06982cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06982e;
P_0c06982e: /* original 2f22, guest PC 0x0c06982e */
if(!s->budget--) { s->failed_pc=0x0c06982eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c069830;
P_0c069830: /* original bf49, guest PC 0x0c069830 */
if(!s->budget--) { s->failed_pc=0x0c069830u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069834u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069834u) { target=s->pc; goto dispatch; }
goto P_0c069834;
P_0c069832: /* original 7410, guest PC 0x0c069832 */
if(!s->budget--) { s->failed_pc=0x0c069832u; return 0; }
r[4]+=0x00000010u;
goto P_0c069834;
P_0c069834: /* original 64d3, guest PC 0x0c069834 */
if(!s->budget--) { s->failed_pc=0x0c069834u; return 0; }
r[4]=r[13];
goto P_0c069836;
P_0c069836: /* original 65c3, guest PC 0x0c069836 */
if(!s->budget--) { s->failed_pc=0x0c069836u; return 0; }
r[5]=r[12];
goto P_0c069838;
P_0c069838: /* original bf45, guest PC 0x0c069838 */
if(!s->budget--) { s->failed_pc=0x0c069838u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06983cu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06983cu) { target=s->pc; goto dispatch; }
goto P_0c06983c;
P_0c06983a: /* original 7414, guest PC 0x0c06983a */
if(!s->budget--) { s->failed_pc=0x0c06983au; return 0; }
r[4]+=0x00000014u;
goto P_0c06983c;
P_0c06983c: /* original 65f2, guest PC 0x0c06983c */
if(!s->budget--) { s->failed_pc=0x0c06983cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06983e;
P_0c06983e: /* original 64d3, guest PC 0x0c06983e */
if(!s->budget--) { s->failed_pc=0x0c06983eu; return 0; }
r[4]=r[13];
goto P_0c069840;
P_0c069840: /* original bf41, guest PC 0x0c069840 */
if(!s->budget--) { s->failed_pc=0x0c069840u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c069844u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069844u) { target=s->pc; goto dispatch; }
goto P_0c069844;
P_0c069842: /* original 740c, guest PC 0x0c069842 */
if(!s->budget--) { s->failed_pc=0x0c069842u; return 0; }
r[4]+=0x0000000cu;
goto P_0c069844;
P_0c069844: /* original 55f1, guest PC 0x0c069844 */
if(!s->budget--) { s->failed_pc=0x0c069844u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c069846;
P_0c069846: /* original 64d3, guest PC 0x0c069846 */
if(!s->budget--) { s->failed_pc=0x0c069846u; return 0; }
r[4]=r[13];
goto P_0c069848;
P_0c069848: /* original bf3d, guest PC 0x0c069848 */
if(!s->budget--) { s->failed_pc=0x0c069848u; return 0; }
target=code_base|0x0c0696c6u; r[16]=code_base|0x0c06984cu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06984cu) { target=s->pc; goto dispatch; }
goto P_0c06984c;
P_0c06984a: /* original 7418, guest PC 0x0c06984a */
if(!s->budget--) { s->failed_pc=0x0c06984au; return 0; }
r[4]+=0x00000018u;
goto P_0c06984c;
P_0c06984c: /* original 9047, guest PC 0x0c06984c */
if(!s->budget--) { s->failed_pc=0x0c06984cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0698deu,2);
goto P_0c06984e;
P_0c06984e: /* original e400, guest PC 0x0c06984e */
if(!s->budget--) { s->failed_pc=0x0c06984eu; return 0; }
r[4]=0x00000000u;
goto P_0c069850;
P_0c069850: /* original 7f08, guest PC 0x0c069850 */
if(!s->budget--) { s->failed_pc=0x0c069850u; return 0; }
r[15]+=0x00000008u;
goto P_0c069852;
P_0c069852: /* original 0e44, guest PC 0x0c069852 */
if(!s->budget--) { s->failed_pc=0x0c069852u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c069854;
P_0c069854: /* original 7001, guest PC 0x0c069854 */
if(!s->budget--) { s->failed_pc=0x0c069854u; return 0; }
r[0]+=0x00000001u;
goto P_0c069856;
P_0c069856: /* original 4f26, guest PC 0x0c069856 */
if(!s->budget--) { s->failed_pc=0x0c069856u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c069858;
P_0c069858: /* original 0e44, guest PC 0x0c069858 */
if(!s->budget--) { s->failed_pc=0x0c069858u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06985a;
P_0c06985a: /* original 7001, guest PC 0x0c06985a */
if(!s->budget--) { s->failed_pc=0x0c06985au; return 0; }
r[0]+=0x00000001u;
goto P_0c06985c;
P_0c06985c: /* original 0e44, guest PC 0x0c06985c */
if(!s->budget--) { s->failed_pc=0x0c06985cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06985e;
P_0c06985e: /* original 7001, guest PC 0x0c06985e */
if(!s->budget--) { s->failed_pc=0x0c06985eu; return 0; }
r[0]+=0x00000001u;
goto P_0c069860;
P_0c069860: /* original 0e44, guest PC 0x0c069860 */
if(!s->budget--) { s->failed_pc=0x0c069860u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c069862;
P_0c069862: /* original 7001, guest PC 0x0c069862 */
if(!s->budget--) { s->failed_pc=0x0c069862u; return 0; }
r[0]+=0x00000001u;
goto P_0c069864;
P_0c069864: /* original 0e44, guest PC 0x0c069864 */
if(!s->budget--) { s->failed_pc=0x0c069864u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c069866;
P_0c069866: /* original 6cf6, guest PC 0x0c069866 */
if(!s->budget--) { s->failed_pc=0x0c069866u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069868;
P_0c069868: /* original 6df6, guest PC 0x0c069868 */
if(!s->budget--) { s->failed_pc=0x0c069868u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06986a;
P_0c06986a: /* original 000b, guest PC 0x0c06986a */
if(!s->budget--) { s->failed_pc=0x0c06986au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06986c: /* original 6ef6, guest PC 0x0c06986c */
if(!s->budget--) { s->failed_pc=0x0c06986cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06986eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06986eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
