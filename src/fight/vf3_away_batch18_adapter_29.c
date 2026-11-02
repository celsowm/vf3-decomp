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
int vf3_away_batch18_adapter_29(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08b430u: goto P_0c08b430;
case 0x0c08b432u: goto P_0c08b432;
case 0x0c08b434u: goto P_0c08b434;
case 0x0c08b436u: goto P_0c08b436;
case 0x0c08b438u: goto P_0c08b438;
case 0x0c08b43au: goto P_0c08b43a;
case 0x0c08b43cu: goto P_0c08b43c;
case 0x0c08b43eu: goto P_0c08b43e;
case 0x0c08b440u: goto P_0c08b440;
case 0x0c08b442u: goto P_0c08b442;
case 0x0c08b444u: goto P_0c08b444;
case 0x0c08b446u: goto P_0c08b446;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
case 0x0c08b4deu: goto P_0c08b4de;
case 0x0c08b4e0u: goto P_0c08b4e0;
case 0x0c08b4e2u: goto P_0c08b4e2;
case 0x0c08b4e4u: goto P_0c08b4e4;
case 0x0c08b4e6u: goto P_0c08b4e6;
case 0x0c08b4e8u: goto P_0c08b4e8;
case 0x0c08b4eau: goto P_0c08b4ea;
case 0x0c08b4ecu: goto P_0c08b4ec;
case 0x0c08b4eeu: goto P_0c08b4ee;
case 0x0c08b4f0u: goto P_0c08b4f0;
case 0x0c08b4f2u: goto P_0c08b4f2;
case 0x0c08b4f4u: goto P_0c08b4f4;
case 0x0c08b4f6u: goto P_0c08b4f6;
case 0x0c08b4f8u: goto P_0c08b4f8;
case 0x0c08b544u: goto P_0c08b544;
case 0x0c08b546u: goto P_0c08b546;
case 0x0c08b548u: goto P_0c08b548;
case 0x0c08b54au: goto P_0c08b54a;
case 0x0c08b54cu: goto P_0c08b54c;
case 0x0c08b54eu: goto P_0c08b54e;
case 0x0c08b550u: goto P_0c08b550;
case 0x0c08b552u: goto P_0c08b552;
case 0x0c08b554u: goto P_0c08b554;
case 0x0c08b556u: goto P_0c08b556;
case 0x0c08b558u: goto P_0c08b558;
case 0x0c08b55au: goto P_0c08b55a;
case 0x0c08b55cu: goto P_0c08b55c;
case 0x0c08b55eu: goto P_0c08b55e;
case 0x0c08b560u: goto P_0c08b560;
case 0x0c08b562u: goto P_0c08b562;
case 0x0c08b564u: goto P_0c08b564;
case 0x0c08b566u: goto P_0c08b566;
case 0x0c08b568u: goto P_0c08b568;
case 0x0c08b56au: goto P_0c08b56a;
case 0x0c08b56cu: goto P_0c08b56c;
case 0x0c08b56eu: goto P_0c08b56e;
case 0x0c08b570u: goto P_0c08b570;
case 0x0c08b572u: goto P_0c08b572;
case 0x0c08b574u: goto P_0c08b574;
case 0x0c08b576u: goto P_0c08b576;
case 0x0c08b578u: goto P_0c08b578;
case 0x0c08b57au: goto P_0c08b57a;
case 0x0c08b57cu: goto P_0c08b57c;
case 0x0c08b57eu: goto P_0c08b57e;
case 0x0c08b580u: goto P_0c08b580;
case 0x0c08b582u: goto P_0c08b582;
case 0x0c08b584u: goto P_0c08b584;
case 0x0c08b586u: goto P_0c08b586;
case 0x0c08b588u: goto P_0c08b588;
case 0x0c08b58au: goto P_0c08b58a;
case 0x0c08b58cu: goto P_0c08b58c;
case 0x0c08b58eu: goto P_0c08b58e;
case 0x0c08b590u: goto P_0c08b590;
case 0x0c08b592u: goto P_0c08b592;
case 0x0c08b594u: goto P_0c08b594;
case 0x0c08b596u: goto P_0c08b596;
case 0x0c08b598u: goto P_0c08b598;
case 0x0c08b59au: goto P_0c08b59a;
case 0x0c08b59cu: goto P_0c08b59c;
case 0x0c08b59eu: goto P_0c08b59e;
case 0x0c08b5a0u: goto P_0c08b5a0;
case 0x0c08b5a2u: goto P_0c08b5a2;
case 0x0c08b5a4u: goto P_0c08b5a4;
case 0x0c08b5a6u: goto P_0c08b5a6;
case 0x0c08b5a8u: goto P_0c08b5a8;
case 0x0c08b5aau: goto P_0c08b5aa;
case 0x0c09532cu: goto P_0c09532c;
case 0x0c09532eu: goto P_0c09532e;
case 0x0c095330u: goto P_0c095330;
case 0x0c095332u: goto P_0c095332;
case 0x0c095334u: goto P_0c095334;
case 0x0c095336u: goto P_0c095336;
case 0x0c095338u: goto P_0c095338;
case 0x0c09533au: goto P_0c09533a;
case 0x0c09533cu: goto P_0c09533c;
case 0x0c09533eu: goto P_0c09533e;
case 0x0c095340u: goto P_0c095340;
case 0x0c095342u: goto P_0c095342;
case 0x0c095344u: goto P_0c095344;
case 0x0c095346u: goto P_0c095346;
case 0x0c095348u: goto P_0c095348;
case 0x0c09534au: goto P_0c09534a;
case 0x0c09534cu: goto P_0c09534c;
case 0x0c09534eu: goto P_0c09534e;
case 0x0c095350u: goto P_0c095350;
case 0x0c095352u: goto P_0c095352;
case 0x0c095354u: goto P_0c095354;
case 0x0c095356u: goto P_0c095356;
case 0x0c095358u: goto P_0c095358;
case 0x0c09535au: goto P_0c09535a;
case 0x0c09535cu: goto P_0c09535c;
case 0x0c09535eu: goto P_0c09535e;
case 0x0c095360u: goto P_0c095360;
case 0x0c095362u: goto P_0c095362;
case 0x0c095364u: goto P_0c095364;
case 0x0c095366u: goto P_0c095366;
case 0x0c095368u: goto P_0c095368;
case 0x0c09536au: goto P_0c09536a;
case 0x0c09536cu: goto P_0c09536c;
case 0x0c09536eu: goto P_0c09536e;
case 0x0c095370u: goto P_0c095370;
case 0x0c095372u: goto P_0c095372;
case 0x0c095374u: goto P_0c095374;
case 0x0c095376u: goto P_0c095376;
case 0x0c095378u: goto P_0c095378;
case 0x0c09537au: goto P_0c09537a;
case 0x0c09537cu: goto P_0c09537c;
case 0x0c09537eu: goto P_0c09537e;
case 0x0c095380u: goto P_0c095380;
case 0x0c095382u: goto P_0c095382;
case 0x0c095384u: goto P_0c095384;
case 0x0c095386u: goto P_0c095386;
case 0x0c095388u: goto P_0c095388;
case 0x0c09538au: goto P_0c09538a;
case 0x0c09538cu: goto P_0c09538c;
case 0x0c09538eu: goto P_0c09538e;
case 0x0c095390u: goto P_0c095390;
case 0x0c095392u: goto P_0c095392;
case 0x0c095394u: goto P_0c095394;
case 0x0c095396u: goto P_0c095396;
case 0x0c095398u: goto P_0c095398;
case 0x0c09539au: goto P_0c09539a;
case 0x0c09539cu: goto P_0c09539c;
case 0x0c09539eu: goto P_0c09539e;
case 0x0c0953a0u: goto P_0c0953a0;
case 0x0c0953a2u: goto P_0c0953a2;
case 0x0c0953a4u: goto P_0c0953a4;
case 0x0c0953a6u: goto P_0c0953a6;
case 0x0c0953a8u: goto P_0c0953a8;
case 0x0c0953aau: goto P_0c0953aa;
case 0x0c0953acu: goto P_0c0953ac;
case 0x0c0953aeu: goto P_0c0953ae;
case 0x0c0953b0u: goto P_0c0953b0;
case 0x0c0953b2u: goto P_0c0953b2;
case 0x0c0953b4u: goto P_0c0953b4;
case 0x0c0953b6u: goto P_0c0953b6;
case 0x0c0953b8u: goto P_0c0953b8;
case 0x0c0953bau: goto P_0c0953ba;
case 0x0c0953bcu: goto P_0c0953bc;
case 0x0c0953beu: goto P_0c0953be;
case 0x0c0953c0u: goto P_0c0953c0;
case 0x0c0953c2u: goto P_0c0953c2;
case 0x0c0953c4u: goto P_0c0953c4;
case 0x0c0953c6u: goto P_0c0953c6;
case 0x0c0953c8u: goto P_0c0953c8;
case 0x0c0953cau: goto P_0c0953ca;
case 0x0c0953ccu: goto P_0c0953cc;
case 0x0c0953ceu: goto P_0c0953ce;
case 0x0c0953d0u: goto P_0c0953d0;
case 0x0c0953d2u: goto P_0c0953d2;
case 0x0c0953d4u: goto P_0c0953d4;
case 0x0c0953f0u: goto P_0c0953f0;
case 0x0c0953f2u: goto P_0c0953f2;
case 0x0c0953f4u: goto P_0c0953f4;
case 0x0c0953f6u: goto P_0c0953f6;
case 0x0c0953f8u: goto P_0c0953f8;
case 0x0c0953fau: goto P_0c0953fa;
case 0x0c0953fcu: goto P_0c0953fc;
case 0x0c0953feu: goto P_0c0953fe;
case 0x0c095400u: goto P_0c095400;
case 0x0c095402u: goto P_0c095402;
case 0x0c095404u: goto P_0c095404;
case 0x0c095406u: goto P_0c095406;
case 0x0c095408u: goto P_0c095408;
case 0x0c09540au: goto P_0c09540a;
case 0x0c09540cu: goto P_0c09540c;
case 0x0c09540eu: goto P_0c09540e;
case 0x0c095410u: goto P_0c095410;
case 0x0c095412u: goto P_0c095412;
case 0x0c095414u: goto P_0c095414;
case 0x0c095416u: goto P_0c095416;
case 0x0c095418u: goto P_0c095418;
case 0x0c09541au: goto P_0c09541a;
case 0x0c09541cu: goto P_0c09541c;
case 0x0c09541eu: goto P_0c09541e;
case 0x0c095420u: goto P_0c095420;
case 0x0c095422u: goto P_0c095422;
case 0x0c095424u: goto P_0c095424;
case 0x0c095426u: goto P_0c095426;
case 0x0c095428u: goto P_0c095428;
case 0x0c09542au: goto P_0c09542a;
case 0x0c09542cu: goto P_0c09542c;
case 0x0c09542eu: goto P_0c09542e;
case 0x0c095430u: goto P_0c095430;
case 0x0c095432u: goto P_0c095432;
case 0x0c095434u: goto P_0c095434;
case 0x0c095436u: goto P_0c095436;
case 0x0c095438u: goto P_0c095438;
case 0x0c09543au: goto P_0c09543a;
case 0x0c09543cu: goto P_0c09543c;
case 0x0c09543eu: goto P_0c09543e;
case 0x0c095440u: goto P_0c095440;
case 0x0c095442u: goto P_0c095442;
case 0x0c095444u: goto P_0c095444;
case 0x0c095446u: goto P_0c095446;
case 0x0c095448u: goto P_0c095448;
case 0x0c09544au: goto P_0c09544a;
case 0x0c09544cu: goto P_0c09544c;
case 0x0c09544eu: goto P_0c09544e;
case 0x0c095450u: goto P_0c095450;
case 0x0c095452u: goto P_0c095452;
case 0x0c095454u: goto P_0c095454;
case 0x0c095456u: goto P_0c095456;
case 0x0c095458u: goto P_0c095458;
case 0x0c09545au: goto P_0c09545a;
case 0x0c09545cu: goto P_0c09545c;
case 0x0c09545eu: goto P_0c09545e;
case 0x0c095460u: goto P_0c095460;
case 0x0c095462u: goto P_0c095462;
case 0x0c095464u: goto P_0c095464;
case 0x0c095466u: goto P_0c095466;
case 0x0c095468u: goto P_0c095468;
case 0x0c09546au: goto P_0c09546a;
case 0x0c09546cu: goto P_0c09546c;
case 0x0c09546eu: goto P_0c09546e;
case 0x0c095470u: goto P_0c095470;
case 0x0c095472u: goto P_0c095472;
case 0x0c095474u: goto P_0c095474;
case 0x0c095476u: goto P_0c095476;
case 0x0c095478u: goto P_0c095478;
case 0x0c09547au: goto P_0c09547a;
case 0x0c09547cu: goto P_0c09547c;
case 0x0c09547eu: goto P_0c09547e;
case 0x0c095480u: goto P_0c095480;
case 0x0c095482u: goto P_0c095482;
case 0x0c095484u: goto P_0c095484;
case 0x0c095486u: goto P_0c095486;
case 0x0c095488u: goto P_0c095488;
case 0x0c09548au: goto P_0c09548a;
case 0x0c09548cu: goto P_0c09548c;
case 0x0c09548eu: goto P_0c09548e;
case 0x0c095490u: goto P_0c095490;
case 0x0c095492u: goto P_0c095492;
case 0x0c095494u: goto P_0c095494;
case 0x0c095496u: goto P_0c095496;
case 0x0c095498u: goto P_0c095498;
case 0x0c09549au: goto P_0c09549a;
case 0x0c09549cu: goto P_0c09549c;
case 0x0c09549eu: goto P_0c09549e;
case 0x0c0954a0u: goto P_0c0954a0;
case 0x0c0954a2u: goto P_0c0954a2;
case 0x0c0954a4u: goto P_0c0954a4;
case 0x0c0954a6u: goto P_0c0954a6;
case 0x0c0954a8u: goto P_0c0954a8;
case 0x0c0954aau: goto P_0c0954aa;
case 0x0c0954acu: goto P_0c0954ac;
case 0x0c0954aeu: goto P_0c0954ae;
case 0x0c0954b0u: goto P_0c0954b0;
case 0x0c0954b2u: goto P_0c0954b2;
case 0x0c0954b4u: goto P_0c0954b4;
case 0x0c0954b6u: goto P_0c0954b6;
case 0x0c0954b8u: goto P_0c0954b8;
case 0x0c0954bau: goto P_0c0954ba;
case 0x0c0954bcu: goto P_0c0954bc;
case 0x0c0954beu: goto P_0c0954be;
case 0x0c0954c0u: goto P_0c0954c0;
case 0x0c0954c2u: goto P_0c0954c2;
case 0x0c0954c4u: goto P_0c0954c4;
case 0x0c0954c6u: goto P_0c0954c6;
case 0x0c0954c8u: goto P_0c0954c8;
case 0x0c0954cau: goto P_0c0954ca;
case 0x0c0954ccu: goto P_0c0954cc;
case 0x0c0954ceu: goto P_0c0954ce;
case 0x0c0954d0u: goto P_0c0954d0;
case 0x0c0954d2u: goto P_0c0954d2;
case 0x0c0954d4u: goto P_0c0954d4;
case 0x0c0954d6u: goto P_0c0954d6;
case 0x0c0954d8u: goto P_0c0954d8;
case 0x0c0954dau: goto P_0c0954da;
case 0x0c0954dcu: goto P_0c0954dc;
case 0x0c0954deu: goto P_0c0954de;
case 0x0c0954e0u: goto P_0c0954e0;
case 0x0c0954e2u: goto P_0c0954e2;
case 0x0c0954e4u: goto P_0c0954e4;
case 0x0c0954e6u: goto P_0c0954e6;
case 0x0c0954e8u: goto P_0c0954e8;
case 0x0c0954eau: goto P_0c0954ea;
case 0x0c0954ecu: goto P_0c0954ec;
case 0x0c0954eeu: goto P_0c0954ee;
case 0x0c0954f0u: goto P_0c0954f0;
case 0x0c0954f2u: goto P_0c0954f2;
case 0x0c0954f4u: goto P_0c0954f4;
case 0x0c0954f6u: goto P_0c0954f6;
case 0x0c0954f8u: goto P_0c0954f8;
case 0x0c0954fau: goto P_0c0954fa;
case 0x0c0954fcu: goto P_0c0954fc;
case 0x0c0954feu: goto P_0c0954fe;
case 0x0c095500u: goto P_0c095500;
case 0x0c095502u: goto P_0c095502;
case 0x0c095504u: goto P_0c095504;
case 0x0c095506u: goto P_0c095506;
case 0x0c095508u: goto P_0c095508;
case 0x0c09550au: goto P_0c09550a;
case 0x0c09550cu: goto P_0c09550c;
case 0x0c09550eu: goto P_0c09550e;
case 0x0c095522u: goto P_0c095522;
case 0x0c095524u: goto P_0c095524;
case 0x0c095526u: goto P_0c095526;
case 0x0c095528u: goto P_0c095528;
case 0x0c09552au: goto P_0c09552a;
case 0x0c09552cu: goto P_0c09552c;
case 0x0c09552eu: goto P_0c09552e;
case 0x0c095530u: goto P_0c095530;
case 0x0c095532u: goto P_0c095532;
case 0x0c095534u: goto P_0c095534;
case 0x0c095536u: goto P_0c095536;
case 0x0c095538u: goto P_0c095538;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08b430: /* original 2fe6, guest PC 0x0c08b430 */
if(!s->budget--) { s->failed_pc=0x0c08b430u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b432;
P_0c08b432: /* original 6e73, guest PC 0x0c08b432 */
if(!s->budget--) { s->failed_pc=0x0c08b432u; return 0; }
r[14]=r[7];
goto P_0c08b434;
P_0c08b434: /* original 2fd6, guest PC 0x0c08b434 */
if(!s->budget--) { s->failed_pc=0x0c08b434u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b436;
P_0c08b436: /* original 2fc6, guest PC 0x0c08b436 */
if(!s->budget--) { s->failed_pc=0x0c08b436u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b438;
P_0c08b438: /* original 6c53, guest PC 0x0c08b438 */
if(!s->budget--) { s->failed_pc=0x0c08b438u; return 0; }
r[12]=r[5];
goto P_0c08b43a;
P_0c08b43a: /* original 2fb6, guest PC 0x0c08b43a */
if(!s->budget--) { s->failed_pc=0x0c08b43au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43c;
P_0c08b43c: /* original 2fa6, guest PC 0x0c08b43c */
if(!s->budget--) { s->failed_pc=0x0c08b43cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43e;
P_0c08b43e: /* original 2f96, guest PC 0x0c08b43e */
if(!s->budget--) { s->failed_pc=0x0c08b43eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b440;
P_0c08b440: /* original 6943, guest PC 0x0c08b440 */
if(!s->budget--) { s->failed_pc=0x0c08b440u; return 0; }
r[9]=r[4];
goto P_0c08b442;
P_0c08b442: /* original 2f86, guest PC 0x0c08b442 */
if(!s->budget--) { s->failed_pc=0x0c08b442u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b444;
P_0c08b444: /* original 7964, guest PC 0x0c08b444 */
if(!s->budget--) { s->failed_pc=0x0c08b444u; return 0; }
r[9]+=0x00000064u;
goto P_0c08b446;
P_0c08b446: /* original fffb, guest PC 0x0c08b446 */
if(!s->budget--) { s->failed_pc=0x0c08b446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b448;
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=code_base|0x0008b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08b480u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c08b4b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b4de;
P_0c08b4de: /* original d50e, guest PC 0x0c08b4de */
if(!s->budget--) { s->failed_pc=0x0c08b4deu; return 0; }
r[5]=read(ram,0x0c08b518u,4);
goto P_0c08b4e0;
P_0c08b4e0: /* original a007, guest PC 0x0c08b4e0 */
if(!s->budget--) { s->failed_pc=0x0c08b4e0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4f2;
P_0c08b4e2: /* original 664e, guest PC 0x0c08b4e2 */
if(!s->budget--) { s->failed_pc=0x0c08b4e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4e4;
P_0c08b4e4: /* original 7501, guest PC 0x0c08b4e4 */
if(!s->budget--) { s->failed_pc=0x0c08b4e4u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4e6;
P_0c08b4e6: /* original 6450, guest PC 0x0c08b4e6 */
if(!s->budget--) { s->failed_pc=0x0c08b4e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[4]=tmp;
goto P_0c08b4e8;
P_0c08b4e8: /* original 644e, guest PC 0x0c08b4e8 */
if(!s->budget--) { s->failed_pc=0x0c08b4e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c08b4ea;
P_0c08b4ea: /* original 2448, guest PC 0x0c08b4ea */
if(!s->budget--) { s->failed_pc=0x0c08b4eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08b4ec;
P_0c08b4ec: /* original 8bfa, guest PC 0x0c08b4ec */
if(!s->budget--) { s->failed_pc=0x0c08b4ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4e4; }
goto P_0c08b4ee;
P_0c08b4ee: /* original 76ff, guest PC 0x0c08b4ee */
if(!s->budget--) { s->failed_pc=0x0c08b4eeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08b4f0;
P_0c08b4f0: /* original 7501, guest PC 0x0c08b4f0 */
if(!s->budget--) { s->failed_pc=0x0c08b4f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c08b4f2;
P_0c08b4f2: /* original 4615, guest PC 0x0c08b4f2 */
if(!s->budget--) { s->failed_pc=0x0c08b4f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c08b4f4;
P_0c08b4f4: /* original 89f7, guest PC 0x0c08b4f4 */
if(!s->budget--) { s->failed_pc=0x0c08b4f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4e6; }
goto P_0c08b4f6;
P_0c08b4f6: /* original 000b, guest PC 0x0c08b4f6 */
if(!s->budget--) { s->failed_pc=0x0c08b4f6u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c08b4f8: /* original 6053, guest PC 0x0c08b4f8 */
if(!s->budget--) { s->failed_pc=0x0c08b4f8u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c08b4fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b4fau; return 0; } return 1;
P_0c08b544: /* original 2fe6, guest PC 0x0c08b544 */
if(!s->budget--) { s->failed_pc=0x0c08b544u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b546;
P_0c08b546: /* original e41e, guest PC 0x0c08b546 */
if(!s->budget--) { s->failed_pc=0x0c08b546u; return 0; }
r[4]=0x0000001eu;
goto P_0c08b548;
P_0c08b548: /* original d33b, guest PC 0x0c08b548 */
if(!s->budget--) { s->failed_pc=0x0c08b548u; return 0; }
r[3]=read(ram,0x0c08b638u,4);
goto P_0c08b54a;
P_0c08b54a: /* original e500, guest PC 0x0c08b54a */
if(!s->budget--) { s->failed_pc=0x0c08b54au; return 0; }
r[5]=0x00000000u;
goto P_0c08b54c;
P_0c08b54c: /* original 4f22, guest PC 0x0c08b54c */
if(!s->budget--) { s->failed_pc=0x0c08b54cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b54e;
P_0c08b54e: /* original 6e32, guest PC 0x0c08b54e */
if(!s->budget--) { s->failed_pc=0x0c08b54eu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c08b550;
P_0c08b550: /* original 66e3, guest PC 0x0c08b550 */
if(!s->budget--) { s->failed_pc=0x0c08b550u; return 0; }
r[6]=r[14];
goto P_0c08b552;
P_0c08b552: /* original 7664, guest PC 0x0c08b552 */
if(!s->budget--) { s->failed_pc=0x0c08b552u; return 0; }
r[6]+=0x00000064u;
goto P_0c08b554;
P_0c08b554: /* original 4410, guest PC 0x0c08b554 */
if(!s->budget--) { s->failed_pc=0x0c08b554u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08b556;
P_0c08b556: /* original 2652, guest PC 0x0c08b556 */
if(!s->budget--) { s->failed_pc=0x0c08b556u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c08b558;
P_0c08b558: /* original 8ffc, guest PC 0x0c08b558 */
if(!s->budget--) { s->failed_pc=0x0c08b558u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c08b554; }
goto P_0c08b55c;
P_0c08b55a: /* original 7604, guest PC 0x0c08b55a */
if(!s->budget--) { s->failed_pc=0x0c08b55au; return 0; }
r[6]+=0x00000004u;
goto P_0c08b55c;
P_0c08b55c: /* original d337, guest PC 0x0c08b55c */
if(!s->budget--) { s->failed_pc=0x0c08b55cu; return 0; }
r[3]=read(ram,0x0c08b63cu,4);
goto P_0c08b55e;
P_0c08b55e: /* original e010, guest PC 0x0c08b55e */
if(!s->budget--) { s->failed_pc=0x0c08b55eu; return 0; }
r[0]=0x00000010u;
goto P_0c08b560;
P_0c08b560: /* original 6230, guest PC 0x0c08b560 */
if(!s->budget--) { s->failed_pc=0x0c08b560u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c08b562;
P_0c08b562: /* original 0e24, guest PC 0x0c08b562 */
if(!s->budget--) { s->failed_pc=0x0c08b562u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08b564;
P_0c08b564: /* original bfbb, guest PC 0x0c08b564 */
if(!s->budget--) { s->failed_pc=0x0c08b564u; return 0; }
target=code_base|0x0c08b4deu; r[16]=code_base|0x0c08b568u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b568u) { target=s->pc; goto dispatch; }
goto P_0c08b568;
P_0c08b566: /* original 04ec, guest PC 0x0c08b566 */
if(!s->budget--) { s->failed_pc=0x0c08b566u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b568;
P_0c08b568: /* original e504, guest PC 0x0c08b568 */
if(!s->budget--) { s->failed_pc=0x0c08b568u; return 0; }
r[5]=0x00000004u;
goto P_0c08b56a;
P_0c08b56a: /* original 6703, guest PC 0x0c08b56a */
if(!s->budget--) { s->failed_pc=0x0c08b56au; return 0; }
r[7]=r[0];
goto P_0c08b56c;
P_0c08b56c: /* original e600, guest PC 0x0c08b56c */
if(!s->budget--) { s->failed_pc=0x0c08b56cu; return 0; }
r[6]=0x00000000u;
goto P_0c08b56e;
P_0c08b56e: /* original bf5f, guest PC 0x0c08b56e */
if(!s->budget--) { s->failed_pc=0x0c08b56eu; return 0; }
target=code_base|0x0c08b430u; r[16]=code_base|0x0c08b572u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b572u) { target=s->pc; goto dispatch; }
goto P_0c08b572;
P_0c08b570: /* original 64e3, guest PC 0x0c08b570 */
if(!s->budget--) { s->failed_pc=0x0c08b570u; return 0; }
r[4]=r[14];
goto P_0c08b572;
P_0c08b572: /* original 6403, guest PC 0x0c08b572 */
if(!s->budget--) { s->failed_pc=0x0c08b572u; return 0; }
r[4]=r[0];
goto P_0c08b574;
P_0c08b574: /* original 9058, guest PC 0x0c08b574 */
if(!s->budget--) { s->failed_pc=0x0c08b574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b628u,2);
goto P_0c08b576;
P_0c08b576: /* original 4f26, guest PC 0x0c08b576 */
if(!s->budget--) { s->failed_pc=0x0c08b576u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b578;
P_0c08b578: /* original 0e46, guest PC 0x0c08b578 */
if(!s->budget--) { s->failed_pc=0x0c08b578u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c08b57a;
P_0c08b57a: /* original 000b, guest PC 0x0c08b57a */
if(!s->budget--) { s->failed_pc=0x0c08b57au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b57c: /* original 6ef6, guest PC 0x0c08b57c */
if(!s->budget--) { s->failed_pc=0x0c08b57cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b57e;
P_0c08b57e: /* original 2fe6, guest PC 0x0c08b57e */
if(!s->budget--) { s->failed_pc=0x0c08b57eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b580;
P_0c08b580: /* original e200, guest PC 0x0c08b580 */
if(!s->budget--) { s->failed_pc=0x0c08b580u; return 0; }
r[2]=0x00000000u;
goto P_0c08b582;
P_0c08b582: /* original d32d, guest PC 0x0c08b582 */
if(!s->budget--) { s->failed_pc=0x0c08b582u; return 0; }
r[3]=read(ram,0x0c08b638u,4);
goto P_0c08b584;
P_0c08b584: /* original e010, guest PC 0x0c08b584 */
if(!s->budget--) { s->failed_pc=0x0c08b584u; return 0; }
r[0]=0x00000010u;
goto P_0c08b586;
P_0c08b586: /* original 4f22, guest PC 0x0c08b586 */
if(!s->budget--) { s->failed_pc=0x0c08b586u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b588;
P_0c08b588: /* original 6e32, guest PC 0x0c08b588 */
if(!s->budget--) { s->failed_pc=0x0c08b588u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c08b58a;
P_0c08b58a: /* original 1e25, guest PC 0x0c08b58a */
if(!s->budget--) { s->failed_pc=0x0c08b58au; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c08b58c;
P_0c08b58c: /* original 924d, guest PC 0x0c08b58c */
if(!s->budget--) { s->failed_pc=0x0c08b58cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b62au,2);
goto P_0c08b58e;
P_0c08b58e: /* original 04ec, guest PC 0x0c08b58e */
if(!s->budget--) { s->failed_pc=0x0c08b58eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b590;
P_0c08b590: /* original 3420, guest PC 0x0c08b590 */
if(!s->budget--) { s->failed_pc=0x0c08b590u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c08b592;
P_0c08b592: /* original 8908, guest PC 0x0c08b592 */
if(!s->budget--) { s->failed_pc=0x0c08b592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b5a6; }
goto P_0c08b594;
P_0c08b594: /* original bfa3, guest PC 0x0c08b594 */
if(!s->budget--) { s->failed_pc=0x0c08b594u; return 0; }
target=code_base|0x0c08b4deu; r[16]=code_base|0x0c08b598u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b598u) { target=s->pc; goto dispatch; }
goto P_0c08b598;
P_0c08b596: /* original 04ec, guest PC 0x0c08b596 */
if(!s->budget--) { s->failed_pc=0x0c08b596u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08b598;
P_0c08b598: /* original 4f26, guest PC 0x0c08b598 */
if(!s->budget--) { s->failed_pc=0x0c08b598u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b59a;
P_0c08b59a: /* original 64e3, guest PC 0x0c08b59a */
if(!s->budget--) { s->failed_pc=0x0c08b59au; return 0; }
r[4]=r[14];
goto P_0c08b59c;
P_0c08b59c: /* original e508, guest PC 0x0c08b59c */
if(!s->budget--) { s->failed_pc=0x0c08b59cu; return 0; }
r[5]=0x00000008u;
goto P_0c08b59e;
P_0c08b59e: /* original 6703, guest PC 0x0c08b59e */
if(!s->budget--) { s->failed_pc=0x0c08b59eu; return 0; }
r[7]=r[0];
goto P_0c08b5a0;
P_0c08b5a0: /* original e600, guest PC 0x0c08b5a0 */
if(!s->budget--) { s->failed_pc=0x0c08b5a0u; return 0; }
r[6]=0x00000000u;
goto P_0c08b5a2;
P_0c08b5a2: /* original af45, guest PC 0x0c08b5a2 */
if(!s->budget--) { s->failed_pc=0x0c08b5a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b430;
P_0c08b5a4: /* original 6ef6, guest PC 0x0c08b5a4 */
if(!s->budget--) { s->failed_pc=0x0c08b5a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b5a6;
P_0c08b5a6: /* original 4f26, guest PC 0x0c08b5a6 */
if(!s->budget--) { s->failed_pc=0x0c08b5a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b5a8;
P_0c08b5a8: /* original 000b, guest PC 0x0c08b5a8 */
if(!s->budget--) { s->failed_pc=0x0c08b5a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b5aa: /* original 6ef6, guest PC 0x0c08b5aa */
if(!s->budget--) { s->failed_pc=0x0c08b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08b5acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08b5acu; return 0; } return 1;
P_0c09532c: /* original 2fe6, guest PC 0x0c09532c */
if(!s->budget--) { s->failed_pc=0x0c09532cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09532e;
P_0c09532e: /* original 2fd6, guest PC 0x0c09532e */
if(!s->budget--) { s->failed_pc=0x0c09532eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095330;
P_0c095330: /* original 2fc6, guest PC 0x0c095330 */
if(!s->budget--) { s->failed_pc=0x0c095330u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095332;
P_0c095332: /* original 2fb6, guest PC 0x0c095332 */
if(!s->budget--) { s->failed_pc=0x0c095332u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095334;
P_0c095334: /* original 2fa6, guest PC 0x0c095334 */
if(!s->budget--) { s->failed_pc=0x0c095334u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095336;
P_0c095336: /* original d12c, guest PC 0x0c095336 */
if(!s->budget--) { s->failed_pc=0x0c095336u; return 0; }
r[1]=read(ram,0x0c0953e8u,4);
goto P_0c095338;
P_0c095338: /* original 7ffc, guest PC 0x0c095338 */
if(!s->budget--) { s->failed_pc=0x0c095338u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09533a;
P_0c09533a: /* original d32a, guest PC 0x0c09533a */
if(!s->budget--) { s->failed_pc=0x0c09533au; return 0; }
r[3]=read(ram,0x0c0953e4u,4);
goto P_0c09533c;
P_0c09533c: /* original 6212, guest PC 0x0c09533c */
if(!s->budget--) { s->failed_pc=0x0c09533cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09533e;
P_0c09533e: /* original 2238, guest PC 0x0c09533e */
if(!s->budget--) { s->failed_pc=0x0c09533eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c095340;
P_0c095340: /* original 8901, guest PC 0x0c095340 */
if(!s->budget--) { s->failed_pc=0x0c095340u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095346; }
goto P_0c095342;
P_0c095342: /* original a0f3, guest PC 0x0c095342 */
if(!s->budget--) { s->failed_pc=0x0c095342u; return 0; }
goto P_0c09552c;
P_0c095344: /* original 0009, guest PC 0x0c095344 */
if(!s->budget--) { s->failed_pc=0x0c095344u; return 0; }
goto P_0c095346;
P_0c095346: /* original 9046, guest PC 0x0c095346 */
if(!s->budget--) { s->failed_pc=0x0c095346u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953d6u,2);
goto P_0c095348;
P_0c095348: /* original ed04, guest PC 0x0c095348 */
if(!s->budget--) { s->failed_pc=0x0c095348u; return 0; }
r[13]=0x00000004u;
goto P_0c09534a;
P_0c09534a: /* original d328, guest PC 0x0c09534a */
if(!s->budget--) { s->failed_pc=0x0c09534au; return 0; }
r[3]=read(ram,0x0c0953ecu,4);
goto P_0c09534c;
P_0c09534c: /* original eb01, guest PC 0x0c09534c */
if(!s->budget--) { s->failed_pc=0x0c09534cu; return 0; }
r[11]=0x00000001u;
goto P_0c09534e;
P_0c09534e: /* original 054e, guest PC 0x0c09534e */
if(!s->budget--) { s->failed_pc=0x0c09534eu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c095350;
P_0c095350: /* original 706f, guest PC 0x0c095350 */
if(!s->budget--) { s->failed_pc=0x0c095350u; return 0; }
r[0]+=0x0000006fu;
goto P_0c095352;
P_0c095352: /* original 064c, guest PC 0x0c095352 */
if(!s->budget--) { s->failed_pc=0x0c095352u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c095354;
P_0c095354: /* original ec02, guest PC 0x0c095354 */
if(!s->budget--) { s->failed_pc=0x0c095354u; return 0; }
r[12]=0x00000002u;
goto P_0c095356;
P_0c095356: /* original 2538, guest PC 0x0c095356 */
if(!s->budget--) { s->failed_pc=0x0c095356u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c095358;
P_0c095358: /* original 666c, guest PC 0x0c095358 */
if(!s->budget--) { s->failed_pc=0x0c095358u; return 0; }
r[6]=r[6]&255u;
goto P_0c09535a;
P_0c09535a: /* original 8d74, guest PC 0x0c09535a */
if(!s->budget--) { s->failed_pc=0x0c09535au; return 0; }
cond=r[17]&1u;
r[14]=0x00000008u;
if(cond) { goto P_0c095446; }
goto P_0c09535e;
P_0c09535c: /* original ee08, guest PC 0x0c09535c */
if(!s->budget--) { s->failed_pc=0x0c09535cu; return 0; }
r[14]=0x00000008u;
goto P_0c09535e;
P_0c09535e: /* original 2668, guest PC 0x0c09535e */
if(!s->budget--) { s->failed_pc=0x0c09535eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c095360;
P_0c095360: /* original 8971, guest PC 0x0c095360 */
if(!s->budget--) { s->failed_pc=0x0c095360u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095446; }
goto P_0c095362;
P_0c095362: /* original e063, guest PC 0x0c095362 */
if(!s->budget--) { s->failed_pc=0x0c095362u; return 0; }
r[0]=0x00000063u;
goto P_0c095364;
P_0c095364: /* original 054c, guest PC 0x0c095364 */
if(!s->budget--) { s->failed_pc=0x0c095364u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c095366;
P_0c095366: /* original 655c, guest PC 0x0c095366 */
if(!s->budget--) { s->failed_pc=0x0c095366u; return 0; }
r[5]=r[5]&255u;
goto P_0c095368;
P_0c095368: /* original 6053, guest PC 0x0c095368 */
if(!s->budget--) { s->failed_pc=0x0c095368u; return 0; }
r[0]=r[5];
goto P_0c09536a;
P_0c09536a: /* original 8801, guest PC 0x0c09536a */
if(!s->budget--) { s->failed_pc=0x0c09536au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09536c;
P_0c09536c: /* original 0729, guest PC 0x0c09536c */
if(!s->budget--) { s->failed_pc=0x0c09536cu; return 0; }
r[7]=r[17]&1u;
goto P_0c09536e;
P_0c09536e: /* original 2558, guest PC 0x0c09536e */
if(!s->budget--) { s->failed_pc=0x0c09536eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c095370;
P_0c095370: /* original 8b03, guest PC 0x0c095370 */
if(!s->budget--) { s->failed_pc=0x0c095370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09537a; }
goto P_0c095372;
P_0c095372: /* original 9031, guest PC 0x0c095372 */
if(!s->budget--) { s->failed_pc=0x0c095372u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953d8u,2);
goto P_0c095374;
P_0c095374: /* original e300, guest PC 0x0c095374 */
if(!s->budget--) { s->failed_pc=0x0c095374u; return 0; }
r[3]=0x00000000u;
goto P_0c095376;
P_0c095376: /* original a066, guest PC 0x0c095376 */
if(!s->budget--) { s->failed_pc=0x0c095376u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c095446;
P_0c095378: /* original 0434, guest PC 0x0c095378 */
if(!s->budget--) { s->failed_pc=0x0c095378u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09537a;
P_0c09537a: /* original e03e, guest PC 0x0c09537a */
if(!s->budget--) { s->failed_pc=0x0c09537au; return 0; }
r[0]=0x0000003eu;
goto P_0c09537c;
P_0c09537c: /* original 054d, guest PC 0x0c09537c */
if(!s->budget--) { s->failed_pc=0x0c09537cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09537e;
P_0c09537e: /* original e040, guest PC 0x0c09537e */
if(!s->budget--) { s->failed_pc=0x0c09537eu; return 0; }
r[0]=0x00000040u;
goto P_0c095380;
P_0c095380: /* original 034d, guest PC 0x0c095380 */
if(!s->budget--) { s->failed_pc=0x0c095380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c095382;
P_0c095382: /* original e2f8, guest PC 0x0c095382 */
if(!s->budget--) { s->failed_pc=0x0c095382u; return 0; }
r[2]=0xfffffff8u;
goto P_0c095384;
P_0c095384: /* original 655d, guest PC 0x0c095384 */
if(!s->budget--) { s->failed_pc=0x0c095384u; return 0; }
r[5]=r[5]&65535u;
goto P_0c095386;
P_0c095386: /* original 4528, guest PC 0x0c095386 */
if(!s->budget--) { s->failed_pc=0x0c095386u; return 0; }
r[5]<<=16;
goto P_0c095388;
P_0c095388: /* original 633d, guest PC 0x0c095388 */
if(!s->budget--) { s->failed_pc=0x0c095388u; return 0; }
r[3]=r[3]&65535u;
goto P_0c09538a;
P_0c09538a: /* original 2778, guest PC 0x0c09538a */
if(!s->budget--) { s->failed_pc=0x0c09538au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09538c;
P_0c09538c: /* original 2f32, guest PC 0x0c09538c */
if(!s->budget--) { s->failed_pc=0x0c09538cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09538e;
P_0c09538e: /* original 253b, guest PC 0x0c09538e */
if(!s->budget--) { s->failed_pc=0x0c09538eu; return 0; }
r[5]|=r[3];
goto P_0c095390;
P_0c095390: /* original 8f09, guest PC 0x0c095390 */
if(!s->budget--) { s->failed_pc=0x0c095390u; return 0; }
cond=r[17]&1u;
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
if(!cond) { goto P_0c0953a6; }
goto P_0c095394;
P_0c095392: /* original 452c, guest PC 0x0c095392 */
if(!s->budget--) { s->failed_pc=0x0c095392u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c095394;
P_0c095394: /* original 9021, guest PC 0x0c095394 */
if(!s->budget--) { s->failed_pc=0x0c095394u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953dau,2);
goto P_0c095396;
P_0c095396: /* original 074d, guest PC 0x0c095396 */
if(!s->budget--) { s->failed_pc=0x0c095396u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c095398;
P_0c095398: /* original 677d, guest PC 0x0c095398 */
if(!s->budget--) { s->failed_pc=0x0c095398u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09539a;
P_0c09539a: /* original 4718, guest PC 0x0c09539a */
if(!s->budget--) { s->failed_pc=0x0c09539au; return 0; }
r[7]<<=8;
goto P_0c09539c;
P_0c09539c: /* original 6373, guest PC 0x0c09539c */
if(!s->budget--) { s->failed_pc=0x0c09539cu; return 0; }
r[3]=r[7];
goto P_0c09539e;
P_0c09539e: /* original 3358, guest PC 0x0c09539e */
if(!s->budget--) { s->failed_pc=0x0c09539eu; return 0; }
r[3]-=r[5];
goto P_0c0953a0;
P_0c0953a0: /* original 6533, guest PC 0x0c0953a0 */
if(!s->budget--) { s->failed_pc=0x0c0953a0u; return 0; }
r[5]=r[3];
goto P_0c0953a2;
P_0c0953a2: /* original a001, guest PC 0x0c0953a2 */
if(!s->budget--) { s->failed_pc=0x0c0953a2u; return 0; }
r[0]+=0x0000007cu;
goto P_0c0953a8;
P_0c0953a4: /* original 707c, guest PC 0x0c0953a4 */
if(!s->budget--) { s->failed_pc=0x0c0953a4u; return 0; }
r[0]+=0x0000007cu;
goto P_0c0953a6;
P_0c0953a6: /* original 9019, guest PC 0x0c0953a6 */
if(!s->budget--) { s->failed_pc=0x0c0953a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953dcu,2);
goto P_0c0953a8;
P_0c0953a8: /* original 455a, guest PC 0x0c0953a8 */
if(!s->budget--) { s->failed_pc=0x0c0953a8u; return 0; }
r[53]=r[5];
goto P_0c0953aa;
P_0c0953aa: /* original f446, guest PC 0x0c0953aa */
if(!s->budget--) { s->failed_pc=0x0c0953aau; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0953ac;
P_0c0953ac: /* original 9017, guest PC 0x0c0953ac */
if(!s->budget--) { s->failed_pc=0x0c0953acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953deu,2);
goto P_0c0953ae;
P_0c0953ae: /* original f32d, guest PC 0x0c0953ae */
if(!s->budget--) { s->failed_pc=0x0c0953aeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0953b0;
P_0c0953b0: /* original 074c, guest PC 0x0c0953b0 */
if(!s->budget--) { s->failed_pc=0x0c0953b0u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0953b2;
P_0c0953b2: /* original 677c, guest PC 0x0c0953b2 */
if(!s->budget--) { s->failed_pc=0x0c0953b2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0953b4;
P_0c0953b4: /* original 2778, guest PC 0x0c0953b4 */
if(!s->budget--) { s->failed_pc=0x0c0953b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0953b6;
P_0c0953b6: /* original f53c, guest PC 0x0c0953b6 */
if(!s->budget--) { s->failed_pc=0x0c0953b6u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0953b8;
P_0c0953b8: /* original 8d32, guest PC 0x0c0953b8 */
if(!s->budget--) { s->failed_pc=0x0c0953b8u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(cond) { goto P_0c095420; }
goto P_0c0953bc;
P_0c0953ba: /* original f452, guest PC 0x0c0953ba */
if(!s->budget--) { s->failed_pc=0x0c0953bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0953bc;
P_0c0953bc: /* original 9010, guest PC 0x0c0953bc */
if(!s->budget--) { s->failed_pc=0x0c0953bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953e0u,2);
goto P_0c0953be;
P_0c0953be: /* original 054d, guest PC 0x0c0953be */
if(!s->budget--) { s->failed_pc=0x0c0953beu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0953c0;
P_0c0953c0: /* original 900f, guest PC 0x0c0953c0 */
if(!s->budget--) { s->failed_pc=0x0c0953c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953e2u,2);
goto P_0c0953c2;
P_0c0953c2: /* original 75ff, guest PC 0x0c0953c2 */
if(!s->budget--) { s->failed_pc=0x0c0953c2u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0953c4;
P_0c0953c4: /* original f546, guest PC 0x0c0953c4 */
if(!s->budget--) { s->failed_pc=0x0c0953c4u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0953c6;
P_0c0953c6: /* original 4515, guest PC 0x0c0953c6 */
if(!s->budget--) { s->failed_pc=0x0c0953c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c0953c8;
P_0c0953c8: /* original 900a, guest PC 0x0c0953c8 */
if(!s->budget--) { s->failed_pc=0x0c0953c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953e0u,2);
goto P_0c0953ca;
P_0c0953ca: /* original 8d11, guest PC 0x0c0953ca */
if(!s->budget--) { s->failed_pc=0x0c0953cau; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[5],2);
if(cond) { goto P_0c0953f0; }
goto P_0c0953ce;
P_0c0953cc: /* original 0455, guest PC 0x0c0953cc */
if(!s->budget--) { s->failed_pc=0x0c0953ccu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0953ce;
P_0c0953ce: /* original 9006, guest PC 0x0c0953ce */
if(!s->budget--) { s->failed_pc=0x0c0953ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0953deu,2);
goto P_0c0953d0;
P_0c0953d0: /* original e300, guest PC 0x0c0953d0 */
if(!s->budget--) { s->failed_pc=0x0c0953d0u; return 0; }
r[3]=0x00000000u;
goto P_0c0953d2;
P_0c0953d2: /* original a025, guest PC 0x0c0953d2 */
if(!s->budget--) { s->failed_pc=0x0c0953d2u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c095420;
P_0c0953d4: /* original 0434, guest PC 0x0c0953d4 */
if(!s->budget--) { s->failed_pc=0x0c0953d4u; return 0; }
write(ram,r[4]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0953d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0953d6u; return 0; } return 1;
P_0c0953f0: /* original 4518, guest PC 0x0c0953f0 */
if(!s->budget--) { s->failed_pc=0x0c0953f0u; return 0; }
r[5]<<=8;
goto P_0c0953f2;
P_0c0953f2: /* original 6373, guest PC 0x0c0953f2 */
if(!s->budget--) { s->failed_pc=0x0c0953f2u; return 0; }
r[3]=r[7];
goto P_0c0953f4;
P_0c0953f4: /* original 455a, guest PC 0x0c0953f4 */
if(!s->budget--) { s->failed_pc=0x0c0953f4u; return 0; }
r[53]=r[5];
goto P_0c0953f6;
P_0c0953f6: /* original 23b8, guest PC 0x0c0953f6 */
if(!s->budget--) { s->failed_pc=0x0c0953f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0953f8;
P_0c0953f8: /* original f32d, guest PC 0x0c0953f8 */
if(!s->budget--) { s->failed_pc=0x0c0953f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0953fa;
P_0c0953fa: /* original f63c, guest PC 0x0c0953fa */
if(!s->budget--) { s->failed_pc=0x0c0953fau; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0953fc;
P_0c0953fc: /* original 8d02, guest PC 0x0c0953fc */
if(!s->budget--) { s->failed_pc=0x0c0953fcu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
if(cond) { goto P_0c095404; }
goto P_0c095400;
P_0c0953fe: /* original f562, guest PC 0x0c0953fe */
if(!s->budget--) { s->failed_pc=0x0c0953feu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c095400;
P_0c095400: /* original 9086, guest PC 0x0c095400 */
if(!s->budget--) { s->failed_pc=0x0c095400u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095510u,2);
goto P_0c095402;
P_0c095402: /* original f457, guest PC 0x0c095402 */
if(!s->budget--) { s->failed_pc=0x0c095402u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c095404;
P_0c095404: /* original 6373, guest PC 0x0c095404 */
if(!s->budget--) { s->failed_pc=0x0c095404u; return 0; }
r[3]=r[7];
goto P_0c095406;
P_0c095406: /* original 23c8, guest PC 0x0c095406 */
if(!s->budget--) { s->failed_pc=0x0c095406u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c095408;
P_0c095408: /* original 8d02, guest PC 0x0c095408 */
if(!s->budget--) { s->failed_pc=0x0c095408u; return 0; }
cond=r[17]&1u;
r[3]=r[7];
if(cond) { goto P_0c095410; }
goto P_0c09540c;
P_0c09540a: /* original 6373, guest PC 0x0c09540a */
if(!s->budget--) { s->failed_pc=0x0c09540au; return 0; }
r[3]=r[7];
goto P_0c09540c;
P_0c09540c: /* original 9081, guest PC 0x0c09540c */
if(!s->budget--) { s->failed_pc=0x0c09540cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095512u,2);
goto P_0c09540e;
P_0c09540e: /* original f457, guest PC 0x0c09540e */
if(!s->budget--) { s->failed_pc=0x0c09540eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c095410;
P_0c095410: /* original 23d8, guest PC 0x0c095410 */
if(!s->budget--) { s->failed_pc=0x0c095410u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c095412;
P_0c095412: /* original 8901, guest PC 0x0c095412 */
if(!s->budget--) { s->failed_pc=0x0c095412u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095418; }
goto P_0c095414;
P_0c095414: /* original 907e, guest PC 0x0c095414 */
if(!s->budget--) { s->failed_pc=0x0c095414u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095514u,2);
goto P_0c095416;
P_0c095416: /* original f457, guest PC 0x0c095416 */
if(!s->budget--) { s->failed_pc=0x0c095416u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c095418;
P_0c095418: /* original 27e8, guest PC 0x0c095418 */
if(!s->budget--) { s->failed_pc=0x0c095418u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[14])==0)!=0);
goto P_0c09541a;
P_0c09541a: /* original 8901, guest PC 0x0c09541a */
if(!s->budget--) { s->failed_pc=0x0c09541au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095420; }
goto P_0c09541c;
P_0c09541c: /* original 907b, guest PC 0x0c09541c */
if(!s->budget--) { s->failed_pc=0x0c09541cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095516u,2);
goto P_0c09541e;
P_0c09541e: /* original f457, guest PC 0x0c09541e */
if(!s->budget--) { s->failed_pc=0x0c09541eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c095420;
P_0c095420: /* original 6363, guest PC 0x0c095420 */
if(!s->budget--) { s->failed_pc=0x0c095420u; return 0; }
r[3]=r[6];
goto P_0c095422;
P_0c095422: /* original 23b8, guest PC 0x0c095422 */
if(!s->budget--) { s->failed_pc=0x0c095422u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c095424;
P_0c095424: /* original 8d02, guest PC 0x0c095424 */
if(!s->budget--) { s->failed_pc=0x0c095424u; return 0; }
cond=r[17]&1u;
r[3]=r[6];
if(cond) { goto P_0c09542c; }
goto P_0c095428;
P_0c095426: /* original 6363, guest PC 0x0c095426 */
if(!s->budget--) { s->failed_pc=0x0c095426u; return 0; }
r[3]=r[6];
goto P_0c095428;
P_0c095428: /* original 9072, guest PC 0x0c095428 */
if(!s->budget--) { s->failed_pc=0x0c095428u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095510u,2);
goto P_0c09542a;
P_0c09542a: /* original f447, guest PC 0x0c09542a */
if(!s->budget--) { s->failed_pc=0x0c09542au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09542c;
P_0c09542c: /* original 23c8, guest PC 0x0c09542c */
if(!s->budget--) { s->failed_pc=0x0c09542cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09542e;
P_0c09542e: /* original 8d02, guest PC 0x0c09542e */
if(!s->budget--) { s->failed_pc=0x0c09542eu; return 0; }
cond=r[17]&1u;
r[3]=r[6];
if(cond) { goto P_0c095436; }
goto P_0c095432;
P_0c095430: /* original 6363, guest PC 0x0c095430 */
if(!s->budget--) { s->failed_pc=0x0c095430u; return 0; }
r[3]=r[6];
goto P_0c095432;
P_0c095432: /* original 906e, guest PC 0x0c095432 */
if(!s->budget--) { s->failed_pc=0x0c095432u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095512u,2);
goto P_0c095434;
P_0c095434: /* original f447, guest PC 0x0c095434 */
if(!s->budget--) { s->failed_pc=0x0c095434u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c095436;
P_0c095436: /* original 23d8, guest PC 0x0c095436 */
if(!s->budget--) { s->failed_pc=0x0c095436u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c095438;
P_0c095438: /* original 8901, guest PC 0x0c095438 */
if(!s->budget--) { s->failed_pc=0x0c095438u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09543e; }
goto P_0c09543a;
P_0c09543a: /* original 906b, guest PC 0x0c09543a */
if(!s->budget--) { s->failed_pc=0x0c09543au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095514u,2);
goto P_0c09543c;
P_0c09543c: /* original f447, guest PC 0x0c09543c */
if(!s->budget--) { s->failed_pc=0x0c09543cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09543e;
P_0c09543e: /* original 26e8, guest PC 0x0c09543e */
if(!s->budget--) { s->failed_pc=0x0c09543eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[14])==0)!=0);
goto P_0c095440;
P_0c095440: /* original 8901, guest PC 0x0c095440 */
if(!s->budget--) { s->failed_pc=0x0c095440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c095446; }
goto P_0c095442;
P_0c095442: /* original 9068, guest PC 0x0c095442 */
if(!s->budget--) { s->failed_pc=0x0c095442u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095516u,2);
goto P_0c095444;
P_0c095444: /* original f447, guest PC 0x0c095444 */
if(!s->budget--) { s->failed_pc=0x0c095444u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c095446;
P_0c095446: /* original 9067, guest PC 0x0c095446 */
if(!s->budget--) { s->failed_pc=0x0c095446u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095518u,2);
goto P_0c095448;
P_0c095448: /* original 074c, guest PC 0x0c095448 */
if(!s->budget--) { s->failed_pc=0x0c095448u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09544a;
P_0c09544a: /* original 7001, guest PC 0x0c09544a */
if(!s->budget--) { s->failed_pc=0x0c09544au; return 0; }
r[0]+=0x00000001u;
goto P_0c09544c;
P_0c09544c: /* original 0a4c, guest PC 0x0c09544c */
if(!s->budget--) { s->failed_pc=0x0c09544cu; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09544e;
P_0c09544e: /* original 677c, guest PC 0x0c09544e */
if(!s->budget--) { s->failed_pc=0x0c09544eu; return 0; }
r[7]=r[7]&255u;
goto P_0c095450;
P_0c095450: /* original 2778, guest PC 0x0c095450 */
if(!s->budget--) { s->failed_pc=0x0c095450u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c095452;
P_0c095452: /* original 6073, guest PC 0x0c095452 */
if(!s->budget--) { s->failed_pc=0x0c095452u; return 0; }
r[0]=r[7];
goto P_0c095454;
P_0c095454: /* original 6aac, guest PC 0x0c095454 */
if(!s->budget--) { s->failed_pc=0x0c095454u; return 0; }
r[10]=r[10]&255u;
goto P_0c095456;
P_0c095456: /* original 0529, guest PC 0x0c095456 */
if(!s->budget--) { s->failed_pc=0x0c095456u; return 0; }
r[5]=r[17]&1u;
goto P_0c095458;
P_0c095458: /* original 2aa8, guest PC 0x0c095458 */
if(!s->budget--) { s->failed_pc=0x0c095458u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c09545a;
P_0c09545a: /* original 0629, guest PC 0x0c09545a */
if(!s->budget--) { s->failed_pc=0x0c09545au; return 0; }
r[6]=r[17]&1u;
goto P_0c09545c;
P_0c09545c: /* original 8801, guest PC 0x0c09545c */
if(!s->budget--) { s->failed_pc=0x0c09545cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09545e;
P_0c09545e: /* original 0029, guest PC 0x0c09545e */
if(!s->budget--) { s->failed_pc=0x0c09545eu; return 0; }
r[0]=r[17]&1u;
goto P_0c095460;
P_0c095460: /* original 2558, guest PC 0x0c095460 */
if(!s->budget--) { s->failed_pc=0x0c095460u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c095462;
P_0c095462: /* original 2f02, guest PC 0x0c095462 */
if(!s->budget--) { s->failed_pc=0x0c095462u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c095464;
P_0c095464: /* original 475a, guest PC 0x0c095464 */
if(!s->budget--) { s->failed_pc=0x0c095464u; return 0; }
r[53]=r[7];
goto P_0c095466;
P_0c095466: /* original f32d, guest PC 0x0c095466 */
if(!s->budget--) { s->failed_pc=0x0c095466u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c095468;
P_0c095468: /* original f83c, guest PC 0x0c095468 */
if(!s->budget--) { s->failed_pc=0x0c095468u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c09546a;
P_0c09546a: /* original 8f5f, guest PC 0x0c09546a */
if(!s->budget--) { s->failed_pc=0x0c09546au; return 0; }
cond=r[17]&1u;
r[7]+=0xffffffffu;
if(!cond) { goto P_0c09552c; }
goto P_0c09546e;
P_0c09546c: /* original 77ff, guest PC 0x0c09546c */
if(!s->budget--) { s->failed_pc=0x0c09546cu; return 0; }
r[7]+=0xffffffffu;
goto P_0c09546e;
P_0c09546e: /* original 2668, guest PC 0x0c09546e */
if(!s->budget--) { s->failed_pc=0x0c09546eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c095470;
P_0c095470: /* original 8b38, guest PC 0x0c095470 */
if(!s->budget--) { s->failed_pc=0x0c095470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0954e4; }
goto P_0c095472;
P_0c095472: /* original 9052, guest PC 0x0c095472 */
if(!s->budget--) { s->failed_pc=0x0c095472u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09551au,2);
goto P_0c095474;
P_0c095474: /* original 2ba8, guest PC 0x0c095474 */
if(!s->budget--) { s->failed_pc=0x0c095474u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[10])==0)!=0);
goto P_0c095476;
P_0c095476: /* original f646, guest PC 0x0c095476 */
if(!s->budget--) { s->failed_pc=0x0c095476u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c095478;
P_0c095478: /* original 7004, guest PC 0x0c095478 */
if(!s->budget--) { s->failed_pc=0x0c095478u; return 0; }
r[0]+=0x00000004u;
goto P_0c09547a;
P_0c09547a: /* original f446, guest PC 0x0c09547a */
if(!s->budget--) { s->failed_pc=0x0c09547au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c09547c;
P_0c09547c: /* original 7004, guest PC 0x0c09547c */
if(!s->budget--) { s->failed_pc=0x0c09547cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09547e;
P_0c09547e: /* original f682, guest PC 0x0c09547e */
if(!s->budget--) { s->failed_pc=0x0c09547eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'*');
goto P_0c095480;
P_0c095480: /* original f546, guest PC 0x0c095480 */
if(!s->budget--) { s->failed_pc=0x0c095480u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c095482;
P_0c095482: /* original f482, guest PC 0x0c095482 */
if(!s->budget--) { s->failed_pc=0x0c095482u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c095484;
P_0c095484: /* original 8d0a, guest PC 0x0c095484 */
if(!s->budget--) { s->failed_pc=0x0c095484u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
if(cond) { goto P_0c09549c; }
goto P_0c095488;
P_0c095486: /* original f582, guest PC 0x0c095486 */
if(!s->budget--) { s->failed_pc=0x0c095486u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c095488;
P_0c095488: /* original 9042, guest PC 0x0c095488 */
if(!s->budget--) { s->failed_pc=0x0c095488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095510u,2);
goto P_0c09548a;
P_0c09548a: /* original f346, guest PC 0x0c09548a */
if(!s->budget--) { s->failed_pc=0x0c09548au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09548c;
P_0c09548c: /* original 70fc, guest PC 0x0c09548c */
if(!s->budget--) { s->failed_pc=0x0c09548cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09548e;
P_0c09548e: /* original f467, guest PC 0x0c09548e */
if(!s->budget--) { s->failed_pc=0x0c09548eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c095490;
P_0c095490: /* original 7008, guest PC 0x0c095490 */
if(!s->budget--) { s->failed_pc=0x0c095490u; return 0; }
r[0]+=0x00000008u;
goto P_0c095492;
P_0c095492: /* original f74c, guest PC 0x0c095492 */
if(!s->budget--) { s->failed_pc=0x0c095492u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c095494;
P_0c095494: /* original f730, guest PC 0x0c095494 */
if(!s->budget--) { s->failed_pc=0x0c095494u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c095496;
P_0c095496: /* original f457, guest PC 0x0c095496 */
if(!s->budget--) { s->failed_pc=0x0c095496u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c095498;
P_0c095498: /* original 70fc, guest PC 0x0c095498 */
if(!s->budget--) { s->failed_pc=0x0c095498u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09549a;
P_0c09549a: /* original f477, guest PC 0x0c09549a */
if(!s->budget--) { s->failed_pc=0x0c09549au; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c09549c;
P_0c09549c: /* original 2ca8, guest PC 0x0c09549c */
if(!s->budget--) { s->failed_pc=0x0c09549cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[10])==0)!=0);
goto P_0c09549e;
P_0c09549e: /* original 8909, guest PC 0x0c09549e */
if(!s->budget--) { s->failed_pc=0x0c09549eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0954b4; }
goto P_0c0954a0;
P_0c0954a0: /* original 9037, guest PC 0x0c0954a0 */
if(!s->budget--) { s->failed_pc=0x0c0954a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095512u,2);
goto P_0c0954a2;
P_0c0954a2: /* original f346, guest PC 0x0c0954a2 */
if(!s->budget--) { s->failed_pc=0x0c0954a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0954a4;
P_0c0954a4: /* original 70fc, guest PC 0x0c0954a4 */
if(!s->budget--) { s->failed_pc=0x0c0954a4u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954a6;
P_0c0954a6: /* original f467, guest PC 0x0c0954a6 */
if(!s->budget--) { s->failed_pc=0x0c0954a6u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0954a8;
P_0c0954a8: /* original 7008, guest PC 0x0c0954a8 */
if(!s->budget--) { s->failed_pc=0x0c0954a8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0954aa;
P_0c0954aa: /* original f74c, guest PC 0x0c0954aa */
if(!s->budget--) { s->failed_pc=0x0c0954aau; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0954ac;
P_0c0954ac: /* original f730, guest PC 0x0c0954ac */
if(!s->budget--) { s->failed_pc=0x0c0954acu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c0954ae;
P_0c0954ae: /* original f457, guest PC 0x0c0954ae */
if(!s->budget--) { s->failed_pc=0x0c0954aeu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0954b0;
P_0c0954b0: /* original 70fc, guest PC 0x0c0954b0 */
if(!s->budget--) { s->failed_pc=0x0c0954b0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954b2;
P_0c0954b2: /* original f477, guest PC 0x0c0954b2 */
if(!s->budget--) { s->failed_pc=0x0c0954b2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0954b4;
P_0c0954b4: /* original 2da8, guest PC 0x0c0954b4 */
if(!s->budget--) { s->failed_pc=0x0c0954b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[10])==0)!=0);
goto P_0c0954b6;
P_0c0954b6: /* original 8909, guest PC 0x0c0954b6 */
if(!s->budget--) { s->failed_pc=0x0c0954b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0954cc; }
goto P_0c0954b8;
P_0c0954b8: /* original 902c, guest PC 0x0c0954b8 */
if(!s->budget--) { s->failed_pc=0x0c0954b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095514u,2);
goto P_0c0954ba;
P_0c0954ba: /* original f346, guest PC 0x0c0954ba */
if(!s->budget--) { s->failed_pc=0x0c0954bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0954bc;
P_0c0954bc: /* original 70fc, guest PC 0x0c0954bc */
if(!s->budget--) { s->failed_pc=0x0c0954bcu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954be;
P_0c0954be: /* original f467, guest PC 0x0c0954be */
if(!s->budget--) { s->failed_pc=0x0c0954beu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0954c0;
P_0c0954c0: /* original 7008, guest PC 0x0c0954c0 */
if(!s->budget--) { s->failed_pc=0x0c0954c0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0954c2;
P_0c0954c2: /* original f74c, guest PC 0x0c0954c2 */
if(!s->budget--) { s->failed_pc=0x0c0954c2u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0954c4;
P_0c0954c4: /* original f730, guest PC 0x0c0954c4 */
if(!s->budget--) { s->failed_pc=0x0c0954c4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c0954c6;
P_0c0954c6: /* original f457, guest PC 0x0c0954c6 */
if(!s->budget--) { s->failed_pc=0x0c0954c6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0954c8;
P_0c0954c8: /* original 70fc, guest PC 0x0c0954c8 */
if(!s->budget--) { s->failed_pc=0x0c0954c8u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954ca;
P_0c0954ca: /* original f477, guest PC 0x0c0954ca */
if(!s->budget--) { s->failed_pc=0x0c0954cau; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0954cc;
P_0c0954cc: /* original 2ae8, guest PC 0x0c0954cc */
if(!s->budget--) { s->failed_pc=0x0c0954ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[14])==0)!=0);
goto P_0c0954ce;
P_0c0954ce: /* original 8909, guest PC 0x0c0954ce */
if(!s->budget--) { s->failed_pc=0x0c0954ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0954e4; }
goto P_0c0954d0;
P_0c0954d0: /* original 9021, guest PC 0x0c0954d0 */
if(!s->budget--) { s->failed_pc=0x0c0954d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095516u,2);
goto P_0c0954d2;
P_0c0954d2: /* original f346, guest PC 0x0c0954d2 */
if(!s->budget--) { s->failed_pc=0x0c0954d2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0954d4;
P_0c0954d4: /* original 70fc, guest PC 0x0c0954d4 */
if(!s->budget--) { s->failed_pc=0x0c0954d4u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954d6;
P_0c0954d6: /* original f467, guest PC 0x0c0954d6 */
if(!s->budget--) { s->failed_pc=0x0c0954d6u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0954d8;
P_0c0954d8: /* original 7008, guest PC 0x0c0954d8 */
if(!s->budget--) { s->failed_pc=0x0c0954d8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0954da;
P_0c0954da: /* original f74c, guest PC 0x0c0954da */
if(!s->budget--) { s->failed_pc=0x0c0954dau; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0954dc;
P_0c0954dc: /* original f730, guest PC 0x0c0954dc */
if(!s->budget--) { s->failed_pc=0x0c0954dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c0954de;
P_0c0954de: /* original f457, guest PC 0x0c0954de */
if(!s->budget--) { s->failed_pc=0x0c0954deu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0954e0;
P_0c0954e0: /* original 70fc, guest PC 0x0c0954e0 */
if(!s->budget--) { s->failed_pc=0x0c0954e0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0954e2;
P_0c0954e2: /* original f477, guest PC 0x0c0954e2 */
if(!s->budget--) { s->failed_pc=0x0c0954e2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0954e4;
P_0c0954e4: /* original 901a, guest PC 0x0c0954e4 */
if(!s->budget--) { s->failed_pc=0x0c0954e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09551cu,2);
goto P_0c0954e6;
P_0c0954e6: /* original f48c, guest PC 0x0c0954e6 */
if(!s->budget--) { s->failed_pc=0x0c0954e6u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0954e8;
P_0c0954e8: /* original f346, guest PC 0x0c0954e8 */
if(!s->budget--) { s->failed_pc=0x0c0954e8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0954ea;
P_0c0954ea: /* original 7004, guest PC 0x0c0954ea */
if(!s->budget--) { s->failed_pc=0x0c0954eau; return 0; }
r[0]+=0x00000004u;
goto P_0c0954ec;
P_0c0954ec: /* original f546, guest PC 0x0c0954ec */
if(!s->budget--) { s->failed_pc=0x0c0954ecu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0954ee;
P_0c0954ee: /* original f432, guest PC 0x0c0954ee */
if(!s->budget--) { s->failed_pc=0x0c0954eeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0954f0;
P_0c0954f0: /* original 9015, guest PC 0x0c0954f0 */
if(!s->budget--) { s->failed_pc=0x0c0954f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09551eu,2);
goto P_0c0954f2;
P_0c0954f2: /* original f35c, guest PC 0x0c0954f2 */
if(!s->budget--) { s->failed_pc=0x0c0954f2u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0954f4;
P_0c0954f4: /* original f58c, guest PC 0x0c0954f4 */
if(!s->budget--) { s->failed_pc=0x0c0954f4u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0954f6;
P_0c0954f6: /* original f532, guest PC 0x0c0954f6 */
if(!s->budget--) { s->failed_pc=0x0c0954f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0954f8;
P_0c0954f8: /* original f447, guest PC 0x0c0954f8 */
if(!s->budget--) { s->failed_pc=0x0c0954f8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0954fa;
P_0c0954fa: /* original 7008, guest PC 0x0c0954fa */
if(!s->budget--) { s->failed_pc=0x0c0954fau; return 0; }
r[0]+=0x00000008u;
goto P_0c0954fc;
P_0c0954fc: /* original f457, guest PC 0x0c0954fc */
if(!s->budget--) { s->failed_pc=0x0c0954fcu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0954fe;
P_0c0954fe: /* original 70a6, guest PC 0x0c0954fe */
if(!s->budget--) { s->failed_pc=0x0c0954feu; return 0; }
r[0]+=0xffffffa6u;
goto P_0c095500;
P_0c095500: /* original 0474, guest PC 0x0c095500 */
if(!s->budget--) { s->failed_pc=0x0c095500u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c095502;
P_0c095502: /* original 63f2, guest PC 0x0c095502 */
if(!s->budget--) { s->failed_pc=0x0c095502u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c095504;
P_0c095504: /* original 2338, guest PC 0x0c095504 */
if(!s->budget--) { s->failed_pc=0x0c095504u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c095506;
P_0c095506: /* original 8911, guest PC 0x0c095506 */
if(!s->budget--) { s->failed_pc=0x0c095506u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09552c; }
goto P_0c095508;
P_0c095508: /* original 920a, guest PC 0x0c095508 */
if(!s->budget--) { s->failed_pc=0x0c095508u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095520u,2);
goto P_0c09550a;
P_0c09550a: /* original e042, guest PC 0x0c09550a */
if(!s->budget--) { s->failed_pc=0x0c09550au; return 0; }
r[0]=0x00000042u;
goto P_0c09550c;
P_0c09550c: /* original a009, guest PC 0x0c09550c */
if(!s->budget--) { s->failed_pc=0x0c09550cu; return 0; }
goto P_0c095522;
P_0c09550e: /* original 0009, guest PC 0x0c09550e */
if(!s->budget--) { s->failed_pc=0x0c09550eu; return 0; }
if(!vf3_matrix_family(0x0c095510u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095510u; return 0; } return 1;
P_0c095522: /* original 0425, guest PC 0x0c095522 */
if(!s->budget--) { s->failed_pc=0x0c095522u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c095524;
P_0c095524: /* original e040, guest PC 0x0c095524 */
if(!s->budget--) { s->failed_pc=0x0c095524u; return 0; }
r[0]=0x00000040u;
goto P_0c095526;
P_0c095526: /* original 0475, guest PC 0x0c095526 */
if(!s->budget--) { s->failed_pc=0x0c095526u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c095528;
P_0c095528: /* original 9007, guest PC 0x0c095528 */
if(!s->budget--) { s->failed_pc=0x0c095528u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09553au,2);
goto P_0c09552a;
P_0c09552a: /* original 0474, guest PC 0x0c09552a */
if(!s->budget--) { s->failed_pc=0x0c09552au; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c09552c;
P_0c09552c: /* original 7f04, guest PC 0x0c09552c */
if(!s->budget--) { s->failed_pc=0x0c09552cu; return 0; }
r[15]+=0x00000004u;
goto P_0c09552e;
P_0c09552e: /* original 6af6, guest PC 0x0c09552e */
if(!s->budget--) { s->failed_pc=0x0c09552eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c095530;
P_0c095530: /* original 6bf6, guest PC 0x0c095530 */
if(!s->budget--) { s->failed_pc=0x0c095530u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c095532;
P_0c095532: /* original 6cf6, guest PC 0x0c095532 */
if(!s->budget--) { s->failed_pc=0x0c095532u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c095534;
P_0c095534: /* original 6df6, guest PC 0x0c095534 */
if(!s->budget--) { s->failed_pc=0x0c095534u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095536;
P_0c095536: /* original 000b, guest PC 0x0c095536 */
if(!s->budget--) { s->failed_pc=0x0c095536u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095538: /* original 6ef6, guest PC 0x0c095538 */
if(!s->budget--) { s->failed_pc=0x0c095538u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09553au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09553au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
