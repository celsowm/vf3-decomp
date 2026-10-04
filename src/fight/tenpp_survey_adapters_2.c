/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_tenpp_survey_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c054eccu: goto P_0c054ecc;
case 0x0c054eceu: goto P_0c054ece;
case 0x0c054ed0u: goto P_0c054ed0;
case 0x0c054ed2u: goto P_0c054ed2;
case 0x0c054ed4u: goto P_0c054ed4;
case 0x0c054ed6u: goto P_0c054ed6;
case 0x0c054ed8u: goto P_0c054ed8;
case 0x0c054edau: goto P_0c054eda;
case 0x0c054edcu: goto P_0c054edc;
case 0x0c054edeu: goto P_0c054ede;
case 0x0c054ee0u: goto P_0c054ee0;
case 0x0c054ee2u: goto P_0c054ee2;
case 0x0c054ee4u: goto P_0c054ee4;
case 0x0c054ee6u: goto P_0c054ee6;
case 0x0c054ee8u: goto P_0c054ee8;
case 0x0c054eeau: goto P_0c054eea;
case 0x0c054eecu: goto P_0c054eec;
case 0x0c054eeeu: goto P_0c054eee;
case 0x0c055330u: goto P_0c055330;
case 0x0c055332u: goto P_0c055332;
case 0x0c055334u: goto P_0c055334;
case 0x0c055336u: goto P_0c055336;
case 0x0c055338u: goto P_0c055338;
case 0x0c05533au: goto P_0c05533a;
case 0x0c05533cu: goto P_0c05533c;
case 0x0c05533eu: goto P_0c05533e;
case 0x0c055340u: goto P_0c055340;
case 0x0c055342u: goto P_0c055342;
case 0x0c055344u: goto P_0c055344;
case 0x0c055346u: goto P_0c055346;
case 0x0c055348u: goto P_0c055348;
case 0x0c05534au: goto P_0c05534a;
case 0x0c05534cu: goto P_0c05534c;
case 0x0c05534eu: goto P_0c05534e;
case 0x0c055350u: goto P_0c055350;
case 0x0c055352u: goto P_0c055352;
case 0x0c055354u: goto P_0c055354;
case 0x0c055356u: goto P_0c055356;
case 0x0c055358u: goto P_0c055358;
case 0x0c05535au: goto P_0c05535a;
case 0x0c05535cu: goto P_0c05535c;
case 0x0c05535eu: goto P_0c05535e;
case 0x0c055360u: goto P_0c055360;
case 0x0c055362u: goto P_0c055362;
case 0x0c055364u: goto P_0c055364;
case 0x0c055366u: goto P_0c055366;
case 0x0c055368u: goto P_0c055368;
case 0x0c05536au: goto P_0c05536a;
case 0x0c05536cu: goto P_0c05536c;
case 0x0c05536eu: goto P_0c05536e;
case 0x0c055370u: goto P_0c055370;
case 0x0c055372u: goto P_0c055372;
case 0x0c055374u: goto P_0c055374;
case 0x0c055376u: goto P_0c055376;
case 0x0c055378u: goto P_0c055378;
case 0x0c05537au: goto P_0c05537a;
case 0x0c05537cu: goto P_0c05537c;
case 0x0c05537eu: goto P_0c05537e;
case 0x0c055380u: goto P_0c055380;
case 0x0c055382u: goto P_0c055382;
case 0x0c055384u: goto P_0c055384;
case 0x0c055386u: goto P_0c055386;
case 0x0c055388u: goto P_0c055388;
case 0x0c05538au: goto P_0c05538a;
case 0x0c05538cu: goto P_0c05538c;
case 0x0c05538eu: goto P_0c05538e;
case 0x0c055390u: goto P_0c055390;
case 0x0c055392u: goto P_0c055392;
case 0x0c055394u: goto P_0c055394;
case 0x0c055396u: goto P_0c055396;
case 0x0c055398u: goto P_0c055398;
case 0x0c05539au: goto P_0c05539a;
case 0x0c05539cu: goto P_0c05539c;
case 0x0c05539eu: goto P_0c05539e;
case 0x0c0553a0u: goto P_0c0553a0;
case 0x0c0553a2u: goto P_0c0553a2;
case 0x0c0553a4u: goto P_0c0553a4;
case 0x0c0553a6u: goto P_0c0553a6;
case 0x0c0553a8u: goto P_0c0553a8;
case 0x0c0553aau: goto P_0c0553aa;
case 0x0c0553acu: goto P_0c0553ac;
case 0x0c0553aeu: goto P_0c0553ae;
case 0x0c0553b0u: goto P_0c0553b0;
case 0x0c0553b2u: goto P_0c0553b2;
case 0x0c0553b4u: goto P_0c0553b4;
case 0x0c0553b6u: goto P_0c0553b6;
case 0x0c0553b8u: goto P_0c0553b8;
case 0x0c0553bau: goto P_0c0553ba;
case 0x0c0553c4u: goto P_0c0553c4;
case 0x0c0553c6u: goto P_0c0553c6;
case 0x0c0553c8u: goto P_0c0553c8;
case 0x0c0553cau: goto P_0c0553ca;
case 0x0c0553ccu: goto P_0c0553cc;
case 0x0c0553ceu: goto P_0c0553ce;
case 0x0c0553d0u: goto P_0c0553d0;
case 0x0c0553d2u: goto P_0c0553d2;
case 0x0c0553d4u: goto P_0c0553d4;
case 0x0c0553d6u: goto P_0c0553d6;
case 0x0c0553d8u: goto P_0c0553d8;
case 0x0c0553dau: goto P_0c0553da;
case 0x0c0553dcu: goto P_0c0553dc;
case 0x0c0553deu: goto P_0c0553de;
case 0x0c0553e0u: goto P_0c0553e0;
case 0x0c0553e2u: goto P_0c0553e2;
case 0x0c0553e4u: goto P_0c0553e4;
case 0x0c0553e6u: goto P_0c0553e6;
case 0x0c0553e8u: goto P_0c0553e8;
case 0x0c0553eau: goto P_0c0553ea;
case 0x0c0553ecu: goto P_0c0553ec;
case 0x0c0553eeu: goto P_0c0553ee;
case 0x0c0553f0u: goto P_0c0553f0;
case 0x0c0553f2u: goto P_0c0553f2;
case 0x0c0553f4u: goto P_0c0553f4;
case 0x0c0553f6u: goto P_0c0553f6;
case 0x0c0553f8u: goto P_0c0553f8;
case 0x0c0553fau: goto P_0c0553fa;
case 0x0c0553fcu: goto P_0c0553fc;
case 0x0c0553feu: goto P_0c0553fe;
case 0x0c055400u: goto P_0c055400;
case 0x0c055420u: goto P_0c055420;
case 0x0c055422u: goto P_0c055422;
case 0x0c055424u: goto P_0c055424;
case 0x0c055426u: goto P_0c055426;
case 0x0c055428u: goto P_0c055428;
case 0x0c05542au: goto P_0c05542a;
case 0x0c05542cu: goto P_0c05542c;
case 0x0c05542eu: goto P_0c05542e;
case 0x0c055430u: goto P_0c055430;
case 0x0c055432u: goto P_0c055432;
case 0x0c055434u: goto P_0c055434;
case 0x0c055436u: goto P_0c055436;
case 0x0c055438u: goto P_0c055438;
case 0x0c05543au: goto P_0c05543a;
case 0x0c05543cu: goto P_0c05543c;
case 0x0c05543eu: goto P_0c05543e;
case 0x0c055440u: goto P_0c055440;
case 0x0c055442u: goto P_0c055442;
case 0x0c055444u: goto P_0c055444;
case 0x0c055446u: goto P_0c055446;
case 0x0c055448u: goto P_0c055448;
case 0x0c05544au: goto P_0c05544a;
case 0x0c05544cu: goto P_0c05544c;
case 0x0c05544eu: goto P_0c05544e;
case 0x0c055450u: goto P_0c055450;
case 0x0c055452u: goto P_0c055452;
case 0x0c055454u: goto P_0c055454;
case 0x0c055456u: goto P_0c055456;
case 0x0c055458u: goto P_0c055458;
case 0x0c05545au: goto P_0c05545a;
case 0x0c05545cu: goto P_0c05545c;
case 0x0c05545eu: goto P_0c05545e;
case 0x0c055460u: goto P_0c055460;
case 0x0c055462u: goto P_0c055462;
case 0x0c055464u: goto P_0c055464;
case 0x0c055466u: goto P_0c055466;
case 0x0c055468u: goto P_0c055468;
case 0x0c05546au: goto P_0c05546a;
case 0x0c05546cu: goto P_0c05546c;
case 0x0c05546eu: goto P_0c05546e;
case 0x0c055470u: goto P_0c055470;
case 0x0c055472u: goto P_0c055472;
case 0x0c055474u: goto P_0c055474;
case 0x0c055476u: goto P_0c055476;
case 0x0c055478u: goto P_0c055478;
case 0x0c05547au: goto P_0c05547a;
case 0x0c05547cu: goto P_0c05547c;
case 0x0c05547eu: goto P_0c05547e;
case 0x0c055480u: goto P_0c055480;
case 0x0c055482u: goto P_0c055482;
case 0x0c055484u: goto P_0c055484;
case 0x0c055486u: goto P_0c055486;
case 0x0c055488u: goto P_0c055488;
case 0x0c05548au: goto P_0c05548a;
case 0x0c05548cu: goto P_0c05548c;
case 0x0c05548eu: goto P_0c05548e;
case 0x0c055490u: goto P_0c055490;
case 0x0c055492u: goto P_0c055492;
case 0x0c055494u: goto P_0c055494;
case 0x0c055496u: goto P_0c055496;
case 0x0c055498u: goto P_0c055498;
case 0x0c05549au: goto P_0c05549a;
case 0x0c05549cu: goto P_0c05549c;
case 0x0c05549eu: goto P_0c05549e;
case 0x0c0554a0u: goto P_0c0554a0;
case 0x0c0554a2u: goto P_0c0554a2;
case 0x0c0554a4u: goto P_0c0554a4;
case 0x0c0554a6u: goto P_0c0554a6;
case 0x0c0554a8u: goto P_0c0554a8;
case 0x0c0554aau: goto P_0c0554aa;
case 0x0c0554acu: goto P_0c0554ac;
case 0x0c0554aeu: goto P_0c0554ae;
case 0x0c0554b0u: goto P_0c0554b0;
case 0x0c0554b2u: goto P_0c0554b2;
case 0x0c0554b4u: goto P_0c0554b4;
case 0x0c0554b6u: goto P_0c0554b6;
case 0x0c0554b8u: goto P_0c0554b8;
case 0x0c0554bau: goto P_0c0554ba;
case 0x0c0554bcu: goto P_0c0554bc;
case 0x0c0554beu: goto P_0c0554be;
case 0x0c0554c0u: goto P_0c0554c0;
case 0x0c0554c2u: goto P_0c0554c2;
case 0x0c0554c4u: goto P_0c0554c4;
case 0x0c0554c6u: goto P_0c0554c6;
case 0x0c0554c8u: goto P_0c0554c8;
case 0x0c0554cau: goto P_0c0554ca;
case 0x0c0554ecu: goto P_0c0554ec;
case 0x0c0554eeu: goto P_0c0554ee;
case 0x0c0554f0u: goto P_0c0554f0;
case 0x0c0554f2u: goto P_0c0554f2;
case 0x0c0554f4u: goto P_0c0554f4;
case 0x0c0554f6u: goto P_0c0554f6;
case 0x0c0554f8u: goto P_0c0554f8;
case 0x0c0554fau: goto P_0c0554fa;
case 0x0c0554fcu: goto P_0c0554fc;
case 0x0c0554feu: goto P_0c0554fe;
case 0x0c055500u: goto P_0c055500;
case 0x0c055502u: goto P_0c055502;
case 0x0c055504u: goto P_0c055504;
case 0x0c055506u: goto P_0c055506;
case 0x0c055508u: goto P_0c055508;
case 0x0c05550au: goto P_0c05550a;
case 0x0c05550cu: goto P_0c05550c;
case 0x0c05550eu: goto P_0c05550e;
case 0x0c055510u: goto P_0c055510;
case 0x0c055512u: goto P_0c055512;
case 0x0c055514u: goto P_0c055514;
case 0x0c055516u: goto P_0c055516;
case 0x0c055518u: goto P_0c055518;
case 0x0c05551au: goto P_0c05551a;
case 0x0c05551cu: goto P_0c05551c;
case 0x0c05551eu: goto P_0c05551e;
case 0x0c055520u: goto P_0c055520;
case 0x0c055522u: goto P_0c055522;
case 0x0c055524u: goto P_0c055524;
case 0x0c055526u: goto P_0c055526;
case 0x0c055528u: goto P_0c055528;
case 0x0c05552au: goto P_0c05552a;
case 0x0c05552cu: goto P_0c05552c;
case 0x0c05552eu: goto P_0c05552e;
case 0x0c055530u: goto P_0c055530;
case 0x0c055532u: goto P_0c055532;
case 0x0c055534u: goto P_0c055534;
case 0x0c055536u: goto P_0c055536;
case 0x0c055538u: goto P_0c055538;
case 0x0c05553au: goto P_0c05553a;
case 0x0c05553cu: goto P_0c05553c;
case 0x0c05553eu: goto P_0c05553e;
case 0x0c055540u: goto P_0c055540;
case 0x0c055542u: goto P_0c055542;
case 0x0c055544u: goto P_0c055544;
case 0x0c055546u: goto P_0c055546;
case 0x0c055548u: goto P_0c055548;
case 0x0c05554au: goto P_0c05554a;
case 0x0c05554cu: goto P_0c05554c;
case 0x0c05554eu: goto P_0c05554e;
case 0x0c055550u: goto P_0c055550;
case 0x0c055552u: goto P_0c055552;
case 0x0c055554u: goto P_0c055554;
case 0x0c055556u: goto P_0c055556;
case 0x0c055558u: goto P_0c055558;
case 0x0c05555au: goto P_0c05555a;
case 0x0c05555cu: goto P_0c05555c;
case 0x0c05555eu: goto P_0c05555e;
case 0x0c055560u: goto P_0c055560;
case 0x0c055562u: goto P_0c055562;
case 0x0c0555c0u: goto P_0c0555c0;
case 0x0c0555c2u: goto P_0c0555c2;
case 0x0c0555c4u: goto P_0c0555c4;
case 0x0c0555c6u: goto P_0c0555c6;
case 0x0c0555c8u: goto P_0c0555c8;
case 0x0c0555cau: goto P_0c0555ca;
case 0x0c0555ccu: goto P_0c0555cc;
case 0x0c0555ceu: goto P_0c0555ce;
case 0x0c0555d0u: goto P_0c0555d0;
case 0x0c0555d2u: goto P_0c0555d2;
case 0x0c0555d4u: goto P_0c0555d4;
case 0x0c0555d6u: goto P_0c0555d6;
case 0x0c0555d8u: goto P_0c0555d8;
case 0x0c0555dau: goto P_0c0555da;
case 0x0c0555dcu: goto P_0c0555dc;
case 0x0c0555deu: goto P_0c0555de;
case 0x0c0555e0u: goto P_0c0555e0;
case 0x0c0555e2u: goto P_0c0555e2;
case 0x0c057020u: goto P_0c057020;
case 0x0c057022u: goto P_0c057022;
case 0x0c057024u: goto P_0c057024;
case 0x0c057026u: goto P_0c057026;
case 0x0c057028u: goto P_0c057028;
case 0x0c05702au: goto P_0c05702a;
case 0x0c05702cu: goto P_0c05702c;
case 0x0c05702eu: goto P_0c05702e;
case 0x0c057030u: goto P_0c057030;
case 0x0c057032u: goto P_0c057032;
case 0x0c057034u: goto P_0c057034;
case 0x0c057036u: goto P_0c057036;
case 0x0c057038u: goto P_0c057038;
case 0x0c05703au: goto P_0c05703a;
case 0x0c05703cu: goto P_0c05703c;
case 0x0c05703eu: goto P_0c05703e;
case 0x0c057040u: goto P_0c057040;
case 0x0c057042u: goto P_0c057042;
case 0x0c057044u: goto P_0c057044;
case 0x0c057046u: goto P_0c057046;
case 0x0c057048u: goto P_0c057048;
case 0x0c05704au: goto P_0c05704a;
case 0x0c05704cu: goto P_0c05704c;
case 0x0c05704eu: goto P_0c05704e;
case 0x0c057050u: goto P_0c057050;
case 0x0c057052u: goto P_0c057052;
case 0x0c057054u: goto P_0c057054;
case 0x0c057056u: goto P_0c057056;
case 0x0c059524u: goto P_0c059524;
case 0x0c059526u: goto P_0c059526;
case 0x0c059528u: goto P_0c059528;
case 0x0c05952au: goto P_0c05952a;
case 0x0c05952cu: goto P_0c05952c;
case 0x0c05952eu: goto P_0c05952e;
case 0x0c059530u: goto P_0c059530;
case 0x0c059532u: goto P_0c059532;
case 0x0c059534u: goto P_0c059534;
case 0x0c059536u: goto P_0c059536;
case 0x0c059538u: goto P_0c059538;
case 0x0c05953au: goto P_0c05953a;
case 0x0c05953cu: goto P_0c05953c;
case 0x0c05953eu: goto P_0c05953e;
case 0x0c059540u: goto P_0c059540;
case 0x0c059542u: goto P_0c059542;
case 0x0c059544u: goto P_0c059544;
case 0x0c05b1fcu: goto P_0c05b1fc;
case 0x0c05b1feu: goto P_0c05b1fe;
case 0x0c05b200u: goto P_0c05b200;
case 0x0c05b202u: goto P_0c05b202;
case 0x0c05b204u: goto P_0c05b204;
case 0x0c05b206u: goto P_0c05b206;
case 0x0c05b208u: goto P_0c05b208;
case 0x0c05b20au: goto P_0c05b20a;
case 0x0c05b20cu: goto P_0c05b20c;
case 0x0c05b890u: goto P_0c05b890;
case 0x0c05b892u: goto P_0c05b892;
case 0x0c05b894u: goto P_0c05b894;
case 0x0c05b896u: goto P_0c05b896;
case 0x0c05b898u: goto P_0c05b898;
case 0x0c05b89au: goto P_0c05b89a;
case 0x0c05b89cu: goto P_0c05b89c;
case 0x0c05b89eu: goto P_0c05b89e;
case 0x0c05b8a0u: goto P_0c05b8a0;
case 0x0c05b8a2u: goto P_0c05b8a2;
case 0x0c05b8a4u: goto P_0c05b8a4;
case 0x0c05b8a6u: goto P_0c05b8a6;
case 0x0c05b8a8u: goto P_0c05b8a8;
case 0x0c05b8aau: goto P_0c05b8aa;
case 0x0c05b8acu: goto P_0c05b8ac;
case 0x0c05b8aeu: goto P_0c05b8ae;
case 0x0c05b8b0u: goto P_0c05b8b0;
case 0x0c05b8b2u: goto P_0c05b8b2;
case 0x0c05b8b4u: goto P_0c05b8b4;
case 0x0c05b8b6u: goto P_0c05b8b6;
case 0x0c05b8b8u: goto P_0c05b8b8;
case 0x0c05b8bau: goto P_0c05b8ba;
case 0x0c05b8bcu: goto P_0c05b8bc;
case 0x0c05b8beu: goto P_0c05b8be;
case 0x0c05b8c0u: goto P_0c05b8c0;
case 0x0c05b8c2u: goto P_0c05b8c2;
case 0x0c05b8c4u: goto P_0c05b8c4;
case 0x0c05b8c6u: goto P_0c05b8c6;
case 0x0c05b8c8u: goto P_0c05b8c8;
case 0x0c05b8cau: goto P_0c05b8ca;
case 0x0c05b8ccu: goto P_0c05b8cc;
case 0x0c05b8ceu: goto P_0c05b8ce;
case 0x0c05b8d0u: goto P_0c05b8d0;
case 0x0c05b8d2u: goto P_0c05b8d2;
case 0x0c05b8d4u: goto P_0c05b8d4;
case 0x0c05b8d6u: goto P_0c05b8d6;
case 0x0c05b8d8u: goto P_0c05b8d8;
case 0x0c05b8dau: goto P_0c05b8da;
case 0x0c05b8dcu: goto P_0c05b8dc;
case 0x0c05b8deu: goto P_0c05b8de;
case 0x0c05b8e0u: goto P_0c05b8e0;
case 0x0c05b8e2u: goto P_0c05b8e2;
case 0x0c05b8e4u: goto P_0c05b8e4;
case 0x0c05b8e6u: goto P_0c05b8e6;
case 0x0c05b8e8u: goto P_0c05b8e8;
case 0x0c05b8eau: goto P_0c05b8ea;
case 0x0c05b8ecu: goto P_0c05b8ec;
case 0x0c05b8eeu: goto P_0c05b8ee;
case 0x0c05b8f0u: goto P_0c05b8f0;
case 0x0c05b8f2u: goto P_0c05b8f2;
case 0x0c05b8f4u: goto P_0c05b8f4;
case 0x0c05b8f6u: goto P_0c05b8f6;
case 0x0c05b8f8u: goto P_0c05b8f8;
case 0x0c05b8fau: goto P_0c05b8fa;
case 0x0c05b8fcu: goto P_0c05b8fc;
case 0x0c05b8feu: goto P_0c05b8fe;
case 0x0c05b900u: goto P_0c05b900;
case 0x0c05b902u: goto P_0c05b902;
case 0x0c05b904u: goto P_0c05b904;
case 0x0c05b906u: goto P_0c05b906;
case 0x0c05b908u: goto P_0c05b908;
case 0x0c05b90au: goto P_0c05b90a;
case 0x0c05b90cu: goto P_0c05b90c;
case 0x0c05b90eu: goto P_0c05b90e;
case 0x0c05b910u: goto P_0c05b910;
case 0x0c05b912u: goto P_0c05b912;
case 0x0c05b914u: goto P_0c05b914;
case 0x0c05b916u: goto P_0c05b916;
case 0x0c05b918u: goto P_0c05b918;
case 0x0c05b91au: goto P_0c05b91a;
case 0x0c05b91cu: goto P_0c05b91c;
case 0x0c05b91eu: goto P_0c05b91e;
case 0x0c05b920u: goto P_0c05b920;
case 0x0c05b922u: goto P_0c05b922;
case 0x0c05b924u: goto P_0c05b924;
case 0x0c05b926u: goto P_0c05b926;
case 0x0c05b928u: goto P_0c05b928;
case 0x0c05b92au: goto P_0c05b92a;
case 0x0c05b92cu: goto P_0c05b92c;
case 0x0c05b92eu: goto P_0c05b92e;
case 0x0c05b930u: goto P_0c05b930;
case 0x0c05b932u: goto P_0c05b932;
case 0x0c05b934u: goto P_0c05b934;
case 0x0c05b936u: goto P_0c05b936;
case 0x0c05b938u: goto P_0c05b938;
case 0x0c05b93au: goto P_0c05b93a;
case 0x0c05b93cu: goto P_0c05b93c;
case 0x0c05b93eu: goto P_0c05b93e;
case 0x0c05b940u: goto P_0c05b940;
case 0x0c05b942u: goto P_0c05b942;
case 0x0c05b944u: goto P_0c05b944;
case 0x0c05b946u: goto P_0c05b946;
case 0x0c05b948u: goto P_0c05b948;
case 0x0c05b94au: goto P_0c05b94a;
case 0x0c05b94cu: goto P_0c05b94c;
case 0x0c05b94eu: goto P_0c05b94e;
case 0x0c05b950u: goto P_0c05b950;
case 0x0c05b952u: goto P_0c05b952;
case 0x0c05b954u: goto P_0c05b954;
case 0x0c05b956u: goto P_0c05b956;
case 0x0c05b958u: goto P_0c05b958;
case 0x0c05b95au: goto P_0c05b95a;
case 0x0c05b95cu: goto P_0c05b95c;
case 0x0c05b95eu: goto P_0c05b95e;
case 0x0c05b960u: goto P_0c05b960;
case 0x0c05b962u: goto P_0c05b962;
case 0x0c05b964u: goto P_0c05b964;
case 0x0c05b966u: goto P_0c05b966;
case 0x0c05b968u: goto P_0c05b968;
case 0x0c05b96au: goto P_0c05b96a;
case 0x0c05b96cu: goto P_0c05b96c;
case 0x0c05b96eu: goto P_0c05b96e;
case 0x0c05b970u: goto P_0c05b970;
case 0x0c05b972u: goto P_0c05b972;
case 0x0c05b974u: goto P_0c05b974;
case 0x0c05b976u: goto P_0c05b976;
case 0x0c05b978u: goto P_0c05b978;
case 0x0c05b97au: goto P_0c05b97a;
case 0x0c05b97cu: goto P_0c05b97c;
case 0x0c05b97eu: goto P_0c05b97e;
case 0x0c05b980u: goto P_0c05b980;
case 0x0c05b982u: goto P_0c05b982;
case 0x0c05b984u: goto P_0c05b984;
case 0x0c05b986u: goto P_0c05b986;
case 0x0c05b988u: goto P_0c05b988;
case 0x0c05b98au: goto P_0c05b98a;
case 0x0c05b98cu: goto P_0c05b98c;
case 0x0c05b98eu: goto P_0c05b98e;
case 0x0c05b990u: goto P_0c05b990;
case 0x0c05b992u: goto P_0c05b992;
case 0x0c05b994u: goto P_0c05b994;
case 0x0c05b996u: goto P_0c05b996;
case 0x0c05b998u: goto P_0c05b998;
case 0x0c05b99au: goto P_0c05b99a;
case 0x0c05b99cu: goto P_0c05b99c;
case 0x0c05b99eu: goto P_0c05b99e;
case 0x0c05b9a0u: goto P_0c05b9a0;
case 0x0c05b9a2u: goto P_0c05b9a2;
case 0x0c05b9a4u: goto P_0c05b9a4;
case 0x0c05b9a6u: goto P_0c05b9a6;
case 0x0c05b9a8u: goto P_0c05b9a8;
case 0x0c05b9aau: goto P_0c05b9aa;
case 0x0c05b9acu: goto P_0c05b9ac;
case 0x0c05b9aeu: goto P_0c05b9ae;
case 0x0c05b9b0u: goto P_0c05b9b0;
case 0x0c05b9b2u: goto P_0c05b9b2;
case 0x0c05b9b4u: goto P_0c05b9b4;
case 0x0c05b9b6u: goto P_0c05b9b6;
case 0x0c05b9b8u: goto P_0c05b9b8;
case 0x0c05b9bau: goto P_0c05b9ba;
case 0x0c05b9bcu: goto P_0c05b9bc;
case 0x0c05b9beu: goto P_0c05b9be;
case 0x0c05b9c0u: goto P_0c05b9c0;
case 0x0c05b9c2u: goto P_0c05b9c2;
case 0x0c05b9c4u: goto P_0c05b9c4;
case 0x0c05b9c6u: goto P_0c05b9c6;
case 0x0c05b9c8u: goto P_0c05b9c8;
case 0x0c05b9f4u: goto P_0c05b9f4;
case 0x0c05b9f6u: goto P_0c05b9f6;
case 0x0c05b9f8u: goto P_0c05b9f8;
case 0x0c05b9fau: goto P_0c05b9fa;
case 0x0c05b9fcu: goto P_0c05b9fc;
case 0x0c05b9feu: goto P_0c05b9fe;
case 0x0c05ba00u: goto P_0c05ba00;
case 0x0c05ba02u: goto P_0c05ba02;
case 0x0c05ba04u: goto P_0c05ba04;
case 0x0c05ba06u: goto P_0c05ba06;
case 0x0c05ba08u: goto P_0c05ba08;
case 0x0c05ba0au: goto P_0c05ba0a;
case 0x0c05ba0cu: goto P_0c05ba0c;
case 0x0c05ba0eu: goto P_0c05ba0e;
case 0x0c05ba10u: goto P_0c05ba10;
case 0x0c05ba12u: goto P_0c05ba12;
case 0x0c05ba14u: goto P_0c05ba14;
case 0x0c05ba16u: goto P_0c05ba16;
case 0x0c05ba18u: goto P_0c05ba18;
case 0x0c05ba1au: goto P_0c05ba1a;
case 0x0c05ba1cu: goto P_0c05ba1c;
case 0x0c05ba1eu: goto P_0c05ba1e;
case 0x0c05ba20u: goto P_0c05ba20;
case 0x0c05ba22u: goto P_0c05ba22;
case 0x0c05ba24u: goto P_0c05ba24;
case 0x0c05ba26u: goto P_0c05ba26;
case 0x0c05ba28u: goto P_0c05ba28;
case 0x0c05ba2au: goto P_0c05ba2a;
case 0x0c05ba2cu: goto P_0c05ba2c;
case 0x0c05ba2eu: goto P_0c05ba2e;
case 0x0c05ba30u: goto P_0c05ba30;
case 0x0c05ba32u: goto P_0c05ba32;
case 0x0c05ba34u: goto P_0c05ba34;
case 0x0c05ba36u: goto P_0c05ba36;
case 0x0c05ba38u: goto P_0c05ba38;
case 0x0c05ba3au: goto P_0c05ba3a;
case 0x0c05ba3cu: goto P_0c05ba3c;
case 0x0c05ba3eu: goto P_0c05ba3e;
case 0x0c05ba40u: goto P_0c05ba40;
case 0x0c05ba42u: goto P_0c05ba42;
case 0x0c05ba44u: goto P_0c05ba44;
case 0x0c05ba46u: goto P_0c05ba46;
case 0x0c05ba48u: goto P_0c05ba48;
case 0x0c05ba4au: goto P_0c05ba4a;
case 0x0c05ba4cu: goto P_0c05ba4c;
case 0x0c05ba4eu: goto P_0c05ba4e;
case 0x0c05ba50u: goto P_0c05ba50;
case 0x0c05ba52u: goto P_0c05ba52;
case 0x0c05ba54u: goto P_0c05ba54;
case 0x0c05ba56u: goto P_0c05ba56;
case 0x0c05ba58u: goto P_0c05ba58;
case 0x0c05ba5au: goto P_0c05ba5a;
case 0x0c05ba5cu: goto P_0c05ba5c;
case 0x0c05ba5eu: goto P_0c05ba5e;
case 0x0c05ba60u: goto P_0c05ba60;
case 0x0c05ba62u: goto P_0c05ba62;
case 0x0c05ba64u: goto P_0c05ba64;
case 0x0c05ba66u: goto P_0c05ba66;
case 0x0c05ba68u: goto P_0c05ba68;
case 0x0c05ba6au: goto P_0c05ba6a;
case 0x0c05ba6cu: goto P_0c05ba6c;
case 0x0c05ba6eu: goto P_0c05ba6e;
case 0x0c05ba70u: goto P_0c05ba70;
case 0x0c05ba72u: goto P_0c05ba72;
case 0x0c05ba74u: goto P_0c05ba74;
case 0x0c05ba76u: goto P_0c05ba76;
case 0x0c05ba78u: goto P_0c05ba78;
case 0x0c05ba7au: goto P_0c05ba7a;
case 0x0c05ba7cu: goto P_0c05ba7c;
case 0x0c05ba7eu: goto P_0c05ba7e;
case 0x0c05ba80u: goto P_0c05ba80;
case 0x0c05ba82u: goto P_0c05ba82;
case 0x0c05ba84u: goto P_0c05ba84;
case 0x0c05ba86u: goto P_0c05ba86;
case 0x0c05ba88u: goto P_0c05ba88;
case 0x0c05ba8au: goto P_0c05ba8a;
case 0x0c05ba8cu: goto P_0c05ba8c;
case 0x0c05ba8eu: goto P_0c05ba8e;
case 0x0c05ba90u: goto P_0c05ba90;
case 0x0c05ba92u: goto P_0c05ba92;
case 0x0c05ba94u: goto P_0c05ba94;
case 0x0c05ba96u: goto P_0c05ba96;
case 0x0c05ba98u: goto P_0c05ba98;
case 0x0c05ba9au: goto P_0c05ba9a;
case 0x0c05ba9cu: goto P_0c05ba9c;
case 0x0c05ba9eu: goto P_0c05ba9e;
case 0x0c05baa0u: goto P_0c05baa0;
case 0x0c05baa2u: goto P_0c05baa2;
case 0x0c05baa4u: goto P_0c05baa4;
case 0x0c05baa6u: goto P_0c05baa6;
case 0x0c05baa8u: goto P_0c05baa8;
case 0x0c05baaau: goto P_0c05baaa;
case 0x0c05baacu: goto P_0c05baac;
case 0x0c05baaeu: goto P_0c05baae;
case 0x0c05bab0u: goto P_0c05bab0;
case 0x0c05bab2u: goto P_0c05bab2;
case 0x0c05bab4u: goto P_0c05bab4;
case 0x0c05bab6u: goto P_0c05bab6;
case 0x0c05bab8u: goto P_0c05bab8;
case 0x0c05babau: goto P_0c05baba;
case 0x0c05babcu: goto P_0c05babc;
case 0x0c05babeu: goto P_0c05babe;
case 0x0c05bac0u: goto P_0c05bac0;
case 0x0c05bac2u: goto P_0c05bac2;
case 0x0c05bac4u: goto P_0c05bac4;
case 0x0c05bac6u: goto P_0c05bac6;
case 0x0c05bac8u: goto P_0c05bac8;
case 0x0c05bacau: goto P_0c05baca;
case 0x0c05baccu: goto P_0c05bacc;
case 0x0c05baceu: goto P_0c05bace;
case 0x0c05bad0u: goto P_0c05bad0;
case 0x0c05bad2u: goto P_0c05bad2;
case 0x0c05bad4u: goto P_0c05bad4;
case 0x0c05bad6u: goto P_0c05bad6;
case 0x0c05bad8u: goto P_0c05bad8;
case 0x0c05badau: goto P_0c05bada;
case 0x0c05badcu: goto P_0c05badc;
case 0x0c05badeu: goto P_0c05bade;
case 0x0c05bae0u: goto P_0c05bae0;
case 0x0c05bae2u: goto P_0c05bae2;
case 0x0c05bae4u: goto P_0c05bae4;
case 0x0c05bae6u: goto P_0c05bae6;
case 0x0c05bae8u: goto P_0c05bae8;
case 0x0c05baeau: goto P_0c05baea;
case 0x0c05baecu: goto P_0c05baec;
case 0x0c05baeeu: goto P_0c05baee;
case 0x0c05baf0u: goto P_0c05baf0;
case 0x0c05baf2u: goto P_0c05baf2;
case 0x0c05baf4u: goto P_0c05baf4;
case 0x0c05baf6u: goto P_0c05baf6;
case 0x0c05baf8u: goto P_0c05baf8;
case 0x0c05bafau: goto P_0c05bafa;
case 0x0c05bafcu: goto P_0c05bafc;
case 0x0c05bafeu: goto P_0c05bafe;
case 0x0c05bb00u: goto P_0c05bb00;
case 0x0c05bb02u: goto P_0c05bb02;
case 0x0c05bb04u: goto P_0c05bb04;
case 0x0c05bb06u: goto P_0c05bb06;
case 0x0c05bb08u: goto P_0c05bb08;
case 0x0c05bb0au: goto P_0c05bb0a;
case 0x0c05bb0cu: goto P_0c05bb0c;
case 0x0c05bb0eu: goto P_0c05bb0e;
case 0x0c05bb10u: goto P_0c05bb10;
case 0x0c05bb12u: goto P_0c05bb12;
case 0x0c05bb14u: goto P_0c05bb14;
case 0x0c05bb16u: goto P_0c05bb16;
case 0x0c05bb18u: goto P_0c05bb18;
case 0x0c05bb1au: goto P_0c05bb1a;
case 0x0c05bb1cu: goto P_0c05bb1c;
case 0x0c05bb1eu: goto P_0c05bb1e;
case 0x0c05bb20u: goto P_0c05bb20;
case 0x0c05bb22u: goto P_0c05bb22;
case 0x0c05bb24u: goto P_0c05bb24;
case 0x0c05bb26u: goto P_0c05bb26;
case 0x0c05bb28u: goto P_0c05bb28;
case 0x0c05bb2au: goto P_0c05bb2a;
case 0x0c05bb2cu: goto P_0c05bb2c;
case 0x0c05bb2eu: goto P_0c05bb2e;
case 0x0c05db42u: goto P_0c05db42;
case 0x0c05db44u: goto P_0c05db44;
case 0x0c05db46u: goto P_0c05db46;
case 0x0c05db48u: goto P_0c05db48;
case 0x0c05db4au: goto P_0c05db4a;
case 0x0c05db4cu: goto P_0c05db4c;
case 0x0c05db4eu: goto P_0c05db4e;
case 0x0c05db50u: goto P_0c05db50;
case 0x0c05db52u: goto P_0c05db52;
case 0x0c05db54u: goto P_0c05db54;
case 0x0c05db56u: goto P_0c05db56;
case 0x0c05db58u: goto P_0c05db58;
case 0x0c05db5au: goto P_0c05db5a;
case 0x0c05db5cu: goto P_0c05db5c;
case 0x0c05db5eu: goto P_0c05db5e;
case 0x0c05db60u: goto P_0c05db60;
case 0x0c05db62u: goto P_0c05db62;
case 0x0c05db64u: goto P_0c05db64;
case 0x0c05db66u: goto P_0c05db66;
case 0x0c05db68u: goto P_0c05db68;
case 0x0c05db6au: goto P_0c05db6a;
case 0x0c05db6cu: goto P_0c05db6c;
case 0x0c05db6eu: goto P_0c05db6e;
case 0x0c05db70u: goto P_0c05db70;
case 0x0c05db72u: goto P_0c05db72;
case 0x0c05db74u: goto P_0c05db74;
case 0x0c05db76u: goto P_0c05db76;
case 0x0c05db78u: goto P_0c05db78;
case 0x0c05db7au: goto P_0c05db7a;
case 0x0c05db7cu: goto P_0c05db7c;
case 0x0c05db7eu: goto P_0c05db7e;
case 0x0c05db80u: goto P_0c05db80;
case 0x0c05db82u: goto P_0c05db82;
case 0x0c05db84u: goto P_0c05db84;
case 0x0c05db86u: goto P_0c05db86;
case 0x0c05db88u: goto P_0c05db88;
case 0x0c05db8au: goto P_0c05db8a;
case 0x0c05db8cu: goto P_0c05db8c;
case 0x0c05db8eu: goto P_0c05db8e;
case 0x0c05db90u: goto P_0c05db90;
case 0x0c05db92u: goto P_0c05db92;
case 0x0c05db94u: goto P_0c05db94;
case 0x0c05db96u: goto P_0c05db96;
case 0x0c05db98u: goto P_0c05db98;
case 0x0c05db9au: goto P_0c05db9a;
case 0x0c05e1eeu: goto P_0c05e1ee;
case 0x0c05e1f0u: goto P_0c05e1f0;
case 0x0c05e1f2u: goto P_0c05e1f2;
case 0x0c05e1f4u: goto P_0c05e1f4;
case 0x0c05e1f6u: goto P_0c05e1f6;
case 0x0c05e1f8u: goto P_0c05e1f8;
case 0x0c05e1fau: goto P_0c05e1fa;
case 0x0c05e1fcu: goto P_0c05e1fc;
case 0x0c05e1feu: goto P_0c05e1fe;
case 0x0c05e200u: goto P_0c05e200;
case 0x0c05e202u: goto P_0c05e202;
case 0x0c05e204u: goto P_0c05e204;
case 0x0c05e206u: goto P_0c05e206;
case 0x0c05e208u: goto P_0c05e208;
case 0x0c05e20au: goto P_0c05e20a;
case 0x0c05e20cu: goto P_0c05e20c;
case 0x0c05e20eu: goto P_0c05e20e;
case 0x0c05e210u: goto P_0c05e210;
case 0x0c05e212u: goto P_0c05e212;
case 0x0c05e214u: goto P_0c05e214;
case 0x0c05e216u: goto P_0c05e216;
case 0x0c05e218u: goto P_0c05e218;
case 0x0c05e21au: goto P_0c05e21a;
case 0x0c05e21cu: goto P_0c05e21c;
case 0x0c05e21eu: goto P_0c05e21e;
case 0x0c05e220u: goto P_0c05e220;
case 0x0c05e222u: goto P_0c05e222;
case 0x0c05e224u: goto P_0c05e224;
case 0x0c05e226u: goto P_0c05e226;
case 0x0c05e228u: goto P_0c05e228;
case 0x0c05e22au: goto P_0c05e22a;
case 0x0c05e22cu: goto P_0c05e22c;
case 0x0c05e22eu: goto P_0c05e22e;
case 0x0c05e230u: goto P_0c05e230;
case 0x0c05e232u: goto P_0c05e232;
case 0x0c05e234u: goto P_0c05e234;
case 0x0c05e236u: goto P_0c05e236;
case 0x0c05e238u: goto P_0c05e238;
case 0x0c05e23au: goto P_0c05e23a;
case 0x0c05e342u: goto P_0c05e342;
case 0x0c05e344u: goto P_0c05e344;
case 0x0c05e346u: goto P_0c05e346;
case 0x0c05e348u: goto P_0c05e348;
case 0x0c05e34au: goto P_0c05e34a;
case 0x0c05e34cu: goto P_0c05e34c;
case 0x0c05e34eu: goto P_0c05e34e;
case 0x0c05e350u: goto P_0c05e350;
case 0x0c05e352u: goto P_0c05e352;
case 0x0c05e354u: goto P_0c05e354;
case 0x0c05e356u: goto P_0c05e356;
case 0x0c05e358u: goto P_0c05e358;
case 0x0c05e35au: goto P_0c05e35a;
case 0x0c05e35cu: goto P_0c05e35c;
case 0x0c05e35eu: goto P_0c05e35e;
case 0x0c05e360u: goto P_0c05e360;
case 0x0c05e362u: goto P_0c05e362;
case 0x0c05e364u: goto P_0c05e364;
case 0x0c05e366u: goto P_0c05e366;
case 0x0c05e368u: goto P_0c05e368;
case 0x0c05e36au: goto P_0c05e36a;
case 0x0c05e36cu: goto P_0c05e36c;
case 0x0c05e36eu: goto P_0c05e36e;
case 0x0c05e370u: goto P_0c05e370;
case 0x0c05e372u: goto P_0c05e372;
case 0x0c05e374u: goto P_0c05e374;
case 0x0c05e376u: goto P_0c05e376;
case 0x0c05e378u: goto P_0c05e378;
case 0x0c05e37au: goto P_0c05e37a;
case 0x0c05e37cu: goto P_0c05e37c;
case 0x0c05e37eu: goto P_0c05e37e;
case 0x0c05e380u: goto P_0c05e380;
case 0x0c05e382u: goto P_0c05e382;
case 0x0c05e384u: goto P_0c05e384;
case 0x0c05e386u: goto P_0c05e386;
case 0x0c05e388u: goto P_0c05e388;
case 0x0c05e38au: goto P_0c05e38a;
case 0x0c05e38cu: goto P_0c05e38c;
case 0x0c05e38eu: goto P_0c05e38e;
case 0x0c05e390u: goto P_0c05e390;
case 0x0c05e392u: goto P_0c05e392;
case 0x0c05e394u: goto P_0c05e394;
case 0x0c05e396u: goto P_0c05e396;
case 0x0c05e398u: goto P_0c05e398;
case 0x0c05e39au: goto P_0c05e39a;
case 0x0c05e39cu: goto P_0c05e39c;
case 0x0c05e39eu: goto P_0c05e39e;
case 0x0c05e3a0u: goto P_0c05e3a0;
case 0x0c05e3a2u: goto P_0c05e3a2;
case 0x0c05e3a4u: goto P_0c05e3a4;
case 0x0c05e3a6u: goto P_0c05e3a6;
case 0x0c05e3a8u: goto P_0c05e3a8;
case 0x0c05e3aau: goto P_0c05e3aa;
case 0x0c05e3acu: goto P_0c05e3ac;
case 0x0c05e3aeu: goto P_0c05e3ae;
case 0x0c05e3b0u: goto P_0c05e3b0;
case 0x0c05e3b2u: goto P_0c05e3b2;
case 0x0c05e3b4u: goto P_0c05e3b4;
case 0x0c05e3b6u: goto P_0c05e3b6;
case 0x0c05e3b8u: goto P_0c05e3b8;
case 0x0c05e3bau: goto P_0c05e3ba;
case 0x0c05e3bcu: goto P_0c05e3bc;
case 0x0c05e3beu: goto P_0c05e3be;
case 0x0c05e3c0u: goto P_0c05e3c0;
case 0x0c05e3c2u: goto P_0c05e3c2;
case 0x0c05e3c4u: goto P_0c05e3c4;
case 0x0c05e3c6u: goto P_0c05e3c6;
case 0x0c05e3c8u: goto P_0c05e3c8;
case 0x0c05e3cau: goto P_0c05e3ca;
case 0x0c05e3ccu: goto P_0c05e3cc;
case 0x0c05e3ceu: goto P_0c05e3ce;
case 0x0c05e3d0u: goto P_0c05e3d0;
case 0x0c05e3d2u: goto P_0c05e3d2;
case 0x0c05e3d4u: goto P_0c05e3d4;
case 0x0c05ed38u: goto P_0c05ed38;
case 0x0c05ed3au: goto P_0c05ed3a;
case 0x0c05ed3cu: goto P_0c05ed3c;
case 0x0c05ed3eu: goto P_0c05ed3e;
case 0x0c05ed40u: goto P_0c05ed40;
case 0x0c05ed42u: goto P_0c05ed42;
case 0x0c05ed44u: goto P_0c05ed44;
case 0x0c05ed46u: goto P_0c05ed46;
case 0x0c05ed48u: goto P_0c05ed48;
case 0x0c05ed4au: goto P_0c05ed4a;
case 0x0c05ed4cu: goto P_0c05ed4c;
case 0x0c05ed4eu: goto P_0c05ed4e;
case 0x0c05ed50u: goto P_0c05ed50;
case 0x0c05ed52u: goto P_0c05ed52;
case 0x0c05ed54u: goto P_0c05ed54;
case 0x0c05ed56u: goto P_0c05ed56;
case 0x0c05ed58u: goto P_0c05ed58;
case 0x0c05ed5au: goto P_0c05ed5a;
case 0x0c05ed5cu: goto P_0c05ed5c;
case 0x0c05ed5eu: goto P_0c05ed5e;
case 0x0c05ed60u: goto P_0c05ed60;
case 0x0c05ed62u: goto P_0c05ed62;
case 0x0c05ed64u: goto P_0c05ed64;
case 0x0c05ed66u: goto P_0c05ed66;
case 0x0c05ed68u: goto P_0c05ed68;
case 0x0c05ed6au: goto P_0c05ed6a;
case 0x0c05ed6cu: goto P_0c05ed6c;
case 0x0c05ed6eu: goto P_0c05ed6e;
case 0x0c060cf2u: goto P_0c060cf2;
case 0x0c060cf4u: goto P_0c060cf4;
case 0x0c060ea6u: goto P_0c060ea6;
case 0x0c060ea8u: goto P_0c060ea8;
case 0x0c060eaau: goto P_0c060eaa;
case 0x0c060eacu: goto P_0c060eac;
case 0x0c060eaeu: goto P_0c060eae;
case 0x0c060eb0u: goto P_0c060eb0;
case 0x0c060eb2u: goto P_0c060eb2;
case 0x0c060eb4u: goto P_0c060eb4;
case 0x0c060eb6u: goto P_0c060eb6;
case 0x0c060eb8u: goto P_0c060eb8;
case 0x0c060ebau: goto P_0c060eba;
case 0x0c060ebcu: goto P_0c060ebc;
case 0x0c060ebeu: goto P_0c060ebe;
case 0x0c060ec0u: goto P_0c060ec0;
case 0x0c060ec2u: goto P_0c060ec2;
case 0x0c060ec4u: goto P_0c060ec4;
case 0x0c060ec6u: goto P_0c060ec6;
case 0x0c060ec8u: goto P_0c060ec8;
case 0x0c060ecau: goto P_0c060eca;
case 0x0c060eccu: goto P_0c060ecc;
case 0x0c060eceu: goto P_0c060ece;
case 0x0c060ed0u: goto P_0c060ed0;
case 0x0c060ed2u: goto P_0c060ed2;
case 0x0c060ed4u: goto P_0c060ed4;
case 0x0c060ed6u: goto P_0c060ed6;
case 0x0c060ed8u: goto P_0c060ed8;
case 0x0c060edau: goto P_0c060eda;
case 0x0c060edcu: goto P_0c060edc;
case 0x0c060edeu: goto P_0c060ede;
case 0x0c060ee0u: goto P_0c060ee0;
case 0x0c060ee2u: goto P_0c060ee2;
case 0x0c060ee4u: goto P_0c060ee4;
case 0x0c060ee6u: goto P_0c060ee6;
case 0x0c060ee8u: goto P_0c060ee8;
case 0x0c060eeau: goto P_0c060eea;
case 0x0c060eecu: goto P_0c060eec;
case 0x0c060eeeu: goto P_0c060eee;
case 0x0c060ef0u: goto P_0c060ef0;
case 0x0c060ef2u: goto P_0c060ef2;
case 0x0c0612fcu: goto P_0c0612fc;
case 0x0c0612feu: goto P_0c0612fe;
case 0x0c061300u: goto P_0c061300;
case 0x0c061302u: goto P_0c061302;
case 0x0c061304u: goto P_0c061304;
case 0x0c061306u: goto P_0c061306;
case 0x0c061308u: goto P_0c061308;
case 0x0c06130au: goto P_0c06130a;
case 0x0c06130cu: goto P_0c06130c;
case 0x0c06130eu: goto P_0c06130e;
case 0x0c061310u: goto P_0c061310;
case 0x0c061312u: goto P_0c061312;
case 0x0c061314u: goto P_0c061314;
case 0x0c061316u: goto P_0c061316;
case 0x0c061318u: goto P_0c061318;
case 0x0c06131au: goto P_0c06131a;
case 0x0c06131cu: goto P_0c06131c;
case 0x0c06131eu: goto P_0c06131e;
case 0x0c061320u: goto P_0c061320;
case 0x0c061322u: goto P_0c061322;
case 0x0c061324u: goto P_0c061324;
case 0x0c061326u: goto P_0c061326;
case 0x0c061328u: goto P_0c061328;
case 0x0c06132au: goto P_0c06132a;
case 0x0c06132cu: goto P_0c06132c;
case 0x0c06132eu: goto P_0c06132e;
case 0x0c061330u: goto P_0c061330;
case 0x0c061332u: goto P_0c061332;
case 0x0c061334u: goto P_0c061334;
case 0x0c061336u: goto P_0c061336;
case 0x0c061338u: goto P_0c061338;
case 0x0c061644u: goto P_0c061644;
case 0x0c061646u: goto P_0c061646;
case 0x0c061648u: goto P_0c061648;
case 0x0c06164au: goto P_0c06164a;
case 0x0c06164cu: goto P_0c06164c;
case 0x0c06164eu: goto P_0c06164e;
case 0x0c061650u: goto P_0c061650;
case 0x0c061652u: goto P_0c061652;
case 0x0c061654u: goto P_0c061654;
case 0x0c061656u: goto P_0c061656;
case 0x0c061658u: goto P_0c061658;
case 0x0c06165au: goto P_0c06165a;
case 0x0c06165cu: goto P_0c06165c;
case 0x0c06165eu: goto P_0c06165e;
case 0x0c061660u: goto P_0c061660;
case 0x0c061662u: goto P_0c061662;
case 0x0c061664u: goto P_0c061664;
case 0x0c061666u: goto P_0c061666;
case 0x0c061668u: goto P_0c061668;
case 0x0c06166au: goto P_0c06166a;
case 0x0c06166cu: goto P_0c06166c;
case 0x0c06166eu: goto P_0c06166e;
case 0x0c061670u: goto P_0c061670;
case 0x0c061672u: goto P_0c061672;
case 0x0c061764u: goto P_0c061764;
case 0x0c061766u: goto P_0c061766;
case 0x0c061768u: goto P_0c061768;
case 0x0c06176au: goto P_0c06176a;
case 0x0c06176cu: goto P_0c06176c;
case 0x0c06176eu: goto P_0c06176e;
case 0x0c061770u: goto P_0c061770;
case 0x0c061772u: goto P_0c061772;
case 0x0c061774u: goto P_0c061774;
case 0x0c061776u: goto P_0c061776;
case 0x0c061778u: goto P_0c061778;
case 0x0c06177au: goto P_0c06177a;
case 0x0c06177cu: goto P_0c06177c;
case 0x0c06177eu: goto P_0c06177e;
case 0x0c061780u: goto P_0c061780;
case 0x0c061782u: goto P_0c061782;
case 0x0c061784u: goto P_0c061784;
case 0x0c061786u: goto P_0c061786;
case 0x0c061788u: goto P_0c061788;
case 0x0c06178au: goto P_0c06178a;
case 0x0c06178cu: goto P_0c06178c;
case 0x0c06178eu: goto P_0c06178e;
case 0x0c061790u: goto P_0c061790;
case 0x0c061792u: goto P_0c061792;
case 0x0c061794u: goto P_0c061794;
case 0x0c061796u: goto P_0c061796;
case 0x0c061798u: goto P_0c061798;
case 0x0c06179au: goto P_0c06179a;
case 0x0c06179cu: goto P_0c06179c;
case 0x0c06179eu: goto P_0c06179e;
case 0x0c0617a0u: goto P_0c0617a0;
case 0x0c0617a2u: goto P_0c0617a2;
case 0x0c0617a4u: goto P_0c0617a4;
case 0x0c0617a6u: goto P_0c0617a6;
case 0x0c0617a8u: goto P_0c0617a8;
case 0x0c0617aau: goto P_0c0617aa;
case 0x0c0617acu: goto P_0c0617ac;
case 0x0c0617aeu: goto P_0c0617ae;
case 0x0c0617b0u: goto P_0c0617b0;
case 0x0c0617b2u: goto P_0c0617b2;
case 0x0c0617b4u: goto P_0c0617b4;
case 0x0c0617b6u: goto P_0c0617b6;
case 0x0c0617b8u: goto P_0c0617b8;
case 0x0c0617bau: goto P_0c0617ba;
case 0x0c0617bcu: goto P_0c0617bc;
case 0x0c0617beu: goto P_0c0617be;
case 0x0c0617c0u: goto P_0c0617c0;
case 0x0c0617c2u: goto P_0c0617c2;
case 0x0c0617c4u: goto P_0c0617c4;
case 0x0c0617c6u: goto P_0c0617c6;
case 0x0c0617c8u: goto P_0c0617c8;
case 0x0c0617cau: goto P_0c0617ca;
case 0x0c0617ccu: goto P_0c0617cc;
case 0x0c0617ceu: goto P_0c0617ce;
case 0x0c0617d0u: goto P_0c0617d0;
case 0x0c0617d2u: goto P_0c0617d2;
case 0x0c0617d4u: goto P_0c0617d4;
case 0x0c0617d6u: goto P_0c0617d6;
case 0x0c0617d8u: goto P_0c0617d8;
case 0x0c0617dau: goto P_0c0617da;
case 0x0c0617dcu: goto P_0c0617dc;
case 0x0c0617deu: goto P_0c0617de;
case 0x0c0617e0u: goto P_0c0617e0;
case 0x0c0617e2u: goto P_0c0617e2;
case 0x0c0617e4u: goto P_0c0617e4;
case 0x0c0617e6u: goto P_0c0617e6;
case 0x0c0617e8u: goto P_0c0617e8;
case 0x0c0617eau: goto P_0c0617ea;
case 0x0c0617ecu: goto P_0c0617ec;
case 0x0c0617eeu: goto P_0c0617ee;
case 0x0c0617f0u: goto P_0c0617f0;
case 0x0c0617f2u: goto P_0c0617f2;
case 0x0c0617f4u: goto P_0c0617f4;
case 0x0c0617f6u: goto P_0c0617f6;
case 0x0c0617f8u: goto P_0c0617f8;
case 0x0c0617fau: goto P_0c0617fa;
case 0x0c0617fcu: goto P_0c0617fc;
case 0x0c0617feu: goto P_0c0617fe;
case 0x0c061800u: goto P_0c061800;
case 0x0c061802u: goto P_0c061802;
case 0x0c061804u: goto P_0c061804;
case 0x0c061806u: goto P_0c061806;
case 0x0c061808u: goto P_0c061808;
case 0x0c06180au: goto P_0c06180a;
case 0x0c06180cu: goto P_0c06180c;
case 0x0c06180eu: goto P_0c06180e;
case 0x0c061810u: goto P_0c061810;
case 0x0c061812u: goto P_0c061812;
case 0x0c061814u: goto P_0c061814;
case 0x0c061816u: goto P_0c061816;
case 0x0c061818u: goto P_0c061818;
case 0x0c06181au: goto P_0c06181a;
case 0x0c06181cu: goto P_0c06181c;
case 0x0c06181eu: goto P_0c06181e;
case 0x0c061820u: goto P_0c061820;
case 0x0c061822u: goto P_0c061822;
case 0x0c061824u: goto P_0c061824;
case 0x0c061826u: goto P_0c061826;
case 0x0c061828u: goto P_0c061828;
case 0x0c06182au: goto P_0c06182a;
case 0x0c06182cu: goto P_0c06182c;
case 0x0c06182eu: goto P_0c06182e;
case 0x0c061830u: goto P_0c061830;
case 0x0c061832u: goto P_0c061832;
case 0x0c061834u: goto P_0c061834;
case 0x0c061836u: goto P_0c061836;
case 0x0c061838u: goto P_0c061838;
case 0x0c06183au: goto P_0c06183a;
case 0x0c06183cu: goto P_0c06183c;
case 0x0c061854u: goto P_0c061854;
case 0x0c061856u: goto P_0c061856;
case 0x0c061858u: goto P_0c061858;
case 0x0c06185au: goto P_0c06185a;
case 0x0c06185cu: goto P_0c06185c;
case 0x0c06185eu: goto P_0c06185e;
case 0x0c061860u: goto P_0c061860;
case 0x0c061862u: goto P_0c061862;
case 0x0c061864u: goto P_0c061864;
case 0x0c061866u: goto P_0c061866;
case 0x0c061868u: goto P_0c061868;
case 0x0c06186au: goto P_0c06186a;
case 0x0c06186cu: goto P_0c06186c;
case 0x0c06186eu: goto P_0c06186e;
case 0x0c061870u: goto P_0c061870;
case 0x0c061872u: goto P_0c061872;
case 0x0c061874u: goto P_0c061874;
case 0x0c061876u: goto P_0c061876;
case 0x0c061878u: goto P_0c061878;
case 0x0c06187au: goto P_0c06187a;
case 0x0c06187cu: goto P_0c06187c;
case 0x0c06187eu: goto P_0c06187e;
case 0x0c061880u: goto P_0c061880;
case 0x0c061882u: goto P_0c061882;
case 0x0c061884u: goto P_0c061884;
case 0x0c061886u: goto P_0c061886;
case 0x0c061888u: goto P_0c061888;
case 0x0c06188au: goto P_0c06188a;
case 0x0c06188cu: goto P_0c06188c;
case 0x0c06188eu: goto P_0c06188e;
case 0x0c061890u: goto P_0c061890;
case 0x0c061892u: goto P_0c061892;
case 0x0c061894u: goto P_0c061894;
case 0x0c061896u: goto P_0c061896;
case 0x0c061898u: goto P_0c061898;
case 0x0c06189au: goto P_0c06189a;
case 0x0c06189cu: goto P_0c06189c;
case 0x0c06189eu: goto P_0c06189e;
case 0x0c0618a0u: goto P_0c0618a0;
case 0x0c0618a2u: goto P_0c0618a2;
case 0x0c0618a4u: goto P_0c0618a4;
case 0x0c0618a6u: goto P_0c0618a6;
case 0x0c0618a8u: goto P_0c0618a8;
case 0x0c0618aau: goto P_0c0618aa;
case 0x0c0618acu: goto P_0c0618ac;
case 0x0c0618aeu: goto P_0c0618ae;
case 0x0c0618b0u: goto P_0c0618b0;
case 0x0c0618b2u: goto P_0c0618b2;
case 0x0c0618b4u: goto P_0c0618b4;
case 0x0c0618b6u: goto P_0c0618b6;
case 0x0c0618b8u: goto P_0c0618b8;
case 0x0c0618bau: goto P_0c0618ba;
case 0x0c0618bcu: goto P_0c0618bc;
case 0x0c0618beu: goto P_0c0618be;
case 0x0c0618c0u: goto P_0c0618c0;
case 0x0c0618c2u: goto P_0c0618c2;
case 0x0c0618c4u: goto P_0c0618c4;
case 0x0c0618c6u: goto P_0c0618c6;
case 0x0c0618c8u: goto P_0c0618c8;
case 0x0c0618cau: goto P_0c0618ca;
case 0x0c0618ccu: goto P_0c0618cc;
case 0x0c0618ceu: goto P_0c0618ce;
case 0x0c0618d0u: goto P_0c0618d0;
case 0x0c0618d2u: goto P_0c0618d2;
case 0x0c0618d4u: goto P_0c0618d4;
case 0x0c0618d6u: goto P_0c0618d6;
case 0x0c0618d8u: goto P_0c0618d8;
case 0x0c0618dau: goto P_0c0618da;
case 0x0c0618dcu: goto P_0c0618dc;
case 0x0c0618deu: goto P_0c0618de;
case 0x0c0618e0u: goto P_0c0618e0;
case 0x0c0618e2u: goto P_0c0618e2;
case 0x0c0618e4u: goto P_0c0618e4;
case 0x0c0618e6u: goto P_0c0618e6;
case 0x0c0618e8u: goto P_0c0618e8;
case 0x0c0618eau: goto P_0c0618ea;
case 0x0c0618ecu: goto P_0c0618ec;
case 0x0c0618eeu: goto P_0c0618ee;
case 0x0c0618f0u: goto P_0c0618f0;
case 0x0c0618f2u: goto P_0c0618f2;
case 0x0c0618f4u: goto P_0c0618f4;
case 0x0c0618f6u: goto P_0c0618f6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c054ecc: /* original ea00, guest PC 0x0c054ecc */
if(!s->budget--) { s->failed_pc=0x0c054eccu; return 0; }
r[10]=0x00000000u;
goto P_0c054ece;
P_0c054ece: /* original e800, guest PC 0x0c054ece */
if(!s->budget--) { s->failed_pc=0x0c054eceu; return 0; }
r[8]=0x00000000u;
goto P_0c054ed0;
P_0c054ed0: /* original e400, guest PC 0x0c054ed0 */
if(!s->budget--) { s->failed_pc=0x0c054ed0u; return 0; }
r[4]=0x00000000u;
goto P_0c054ed2;
P_0c054ed2: /* original afdc, guest PC 0x0c054ed2 */
if(!s->budget--) { s->failed_pc=0x0c054ed2u; return 0; }
r[5]=0x00000000u;
return vf3_matrix_family(0x0c054e8eu,s,ram);
P_0c054ed4: /* original e500, guest PC 0x0c054ed4 */
if(!s->budget--) { s->failed_pc=0x0c054ed4u; return 0; }
r[5]=0x00000000u;
goto P_0c054ed6;
P_0c054ed6: /* original 2baa, guest PC 0x0c054ed6 */
if(!s->budget--) { s->failed_pc=0x0c054ed6u; return 0; }
r[11]^=r[10];
goto P_0c054ed8;
P_0c054ed8: /* original 2aba, guest PC 0x0c054ed8 */
if(!s->budget--) { s->failed_pc=0x0c054ed8u; return 0; }
r[10]^=r[11];
goto P_0c054eda;
P_0c054eda: /* original 2baa, guest PC 0x0c054eda */
if(!s->budget--) { s->failed_pc=0x0c054edau; return 0; }
r[11]^=r[10];
goto P_0c054edc;
P_0c054edc: /* original 298a, guest PC 0x0c054edc */
if(!s->budget--) { s->failed_pc=0x0c054edcu; return 0; }
r[9]^=r[8];
goto P_0c054ede;
P_0c054ede: /* original 289a, guest PC 0x0c054ede */
if(!s->budget--) { s->failed_pc=0x0c054edeu; return 0; }
r[8]^=r[9];
goto P_0c054ee0;
P_0c054ee0: /* original 298a, guest PC 0x0c054ee0 */
if(!s->budget--) { s->failed_pc=0x0c054ee0u; return 0; }
r[9]^=r[8];
goto P_0c054ee2;
P_0c054ee2: /* original 264a, guest PC 0x0c054ee2 */
if(!s->budget--) { s->failed_pc=0x0c054ee2u; return 0; }
r[6]^=r[4];
goto P_0c054ee4;
P_0c054ee4: /* original 246a, guest PC 0x0c054ee4 */
if(!s->budget--) { s->failed_pc=0x0c054ee4u; return 0; }
r[4]^=r[6];
goto P_0c054ee6;
P_0c054ee6: /* original 264a, guest PC 0x0c054ee6 */
if(!s->budget--) { s->failed_pc=0x0c054ee6u; return 0; }
r[6]^=r[4];
goto P_0c054ee8;
P_0c054ee8: /* original 275a, guest PC 0x0c054ee8 */
if(!s->budget--) { s->failed_pc=0x0c054ee8u; return 0; }
r[7]^=r[5];
goto P_0c054eea;
P_0c054eea: /* original 257a, guest PC 0x0c054eea */
if(!s->budget--) { s->failed_pc=0x0c054eeau; return 0; }
r[5]^=r[7];
goto P_0c054eec;
P_0c054eec: /* original aeeb, guest PC 0x0c054eec */
if(!s->budget--) { s->failed_pc=0x0c054eecu; return 0; }
r[7]^=r[5];
return vf3_matrix_family(0x0c054cc6u,s,ram);
P_0c054eee: /* original 275a, guest PC 0x0c054eee */
if(!s->budget--) { s->failed_pc=0x0c054eeeu; return 0; }
r[7]^=r[5];
return vf3_matrix_family(0x0c054ef0u,s,ram);
P_0c055330: /* original 2f46, guest PC 0x0c055330 */
if(!s->budget--) { s->failed_pc=0x0c055330u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c055332;
P_0c055332: /* original 2f56, guest PC 0x0c055332 */
if(!s->budget--) { s->failed_pc=0x0c055332u; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c055334;
P_0c055334: /* original 2f66, guest PC 0x0c055334 */
if(!s->budget--) { s->failed_pc=0x0c055334u; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c055336;
P_0c055336: /* original 2f76, guest PC 0x0c055336 */
if(!s->budget--) { s->failed_pc=0x0c055336u; return 0; }
r[15]-=4; write(ram,r[15],r[7],4);
goto P_0c055338;
P_0c055338: /* original 55f6, guest PC 0x0c055338 */
if(!s->budget--) { s->failed_pc=0x0c055338u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c05533a;
P_0c05533a: /* original 54f7, guest PC 0x0c05533a */
if(!s->budget--) { s->failed_pc=0x0c05533au; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c05533c;
P_0c05533c: /* original 57f4, guest PC 0x0c05533c */
if(!s->budget--) { s->failed_pc=0x0c05533cu; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c05533e;
P_0c05533e: /* original 56f5, guest PC 0x0c05533e */
if(!s->budget--) { s->failed_pc=0x0c05533eu; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c055340;
P_0c055340: /* original 2f86, guest PC 0x0c055340 */
if(!s->budget--) { s->failed_pc=0x0c055340u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c055342;
P_0c055342: /* original 2f96, guest PC 0x0c055342 */
if(!s->budget--) { s->failed_pc=0x0c055342u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c055344;
P_0c055344: /* original 2fa6, guest PC 0x0c055344 */
if(!s->budget--) { s->failed_pc=0x0c055344u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c055346;
P_0c055346: /* original 2fb6, guest PC 0x0c055346 */
if(!s->budget--) { s->failed_pc=0x0c055346u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c055348;
P_0c055348: /* original d01c, guest PC 0x0c055348 */
if(!s->budget--) { s->failed_pc=0x0c055348u; return 0; }
r[0]=read(ram,0x0c0553bcu,4);
goto P_0c05534a;
P_0c05534a: /* original 6a43, guest PC 0x0c05534a */
if(!s->budget--) { s->failed_pc=0x0c05534au; return 0; }
r[10]=r[4];
goto P_0c05534c;
P_0c05534c: /* original 6b63, guest PC 0x0c05534c */
if(!s->budget--) { s->failed_pc=0x0c05534cu; return 0; }
r[11]=r[6];
goto P_0c05534e;
P_0c05534e: /* original 6843, guest PC 0x0c05534e */
if(!s->budget--) { s->failed_pc=0x0c05534eu; return 0; }
r[8]=r[4];
goto P_0c055350;
P_0c055350: /* original 2809, guest PC 0x0c055350 */
if(!s->budget--) { s->failed_pc=0x0c055350u; return 0; }
r[8]&=r[0];
goto P_0c055352;
P_0c055352: /* original 6963, guest PC 0x0c055352 */
if(!s->budget--) { s->failed_pc=0x0c055352u; return 0; }
r[9]=r[6];
goto P_0c055354;
P_0c055354: /* original 2909, guest PC 0x0c055354 */
if(!s->budget--) { s->failed_pc=0x0c055354u; return 0; }
r[9]&=r[0];
goto P_0c055356;
P_0c055356: /* original d01a, guest PC 0x0c055356 */
if(!s->budget--) { s->failed_pc=0x0c055356u; return 0; }
r[0]=read(ram,0x0c0553c0u,4);
goto P_0c055358;
P_0c055358: /* original 2409, guest PC 0x0c055358 */
if(!s->budget--) { s->failed_pc=0x0c055358u; return 0; }
r[4]&=r[0];
goto P_0c05535a;
P_0c05535a: /* original 2609, guest PC 0x0c05535a */
if(!s->budget--) { s->failed_pc=0x0c05535au; return 0; }
r[6]&=r[0];
goto P_0c05535c;
P_0c05535c: /* original d017, guest PC 0x0c05535c */
if(!s->budget--) { s->failed_pc=0x0c05535cu; return 0; }
r[0]=read(ram,0x0c0553bcu,4);
goto P_0c05535e;
P_0c05535e: /* original 3800, guest PC 0x0c05535e */
if(!s->budget--) { s->failed_pc=0x0c05535eu; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[0])!=0);
goto P_0c055360;
P_0c055360: /* original 8914, guest PC 0x0c055360 */
if(!s->budget--) { s->failed_pc=0x0c055360u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05538c; }
goto P_0c055362;
P_0c055362: /* original 3900, guest PC 0x0c055362 */
if(!s->budget--) { s->failed_pc=0x0c055362u; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[0])!=0);
goto P_0c055364;
P_0c055364: /* original 8918, guest PC 0x0c055364 */
if(!s->budget--) { s->failed_pc=0x0c055364u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055398; }
goto P_0c055366;
P_0c055366: /* original 2888, guest PC 0x0c055366 */
if(!s->budget--) { s->failed_pc=0x0c055366u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c055368;
P_0c055368: /* original 891c, guest PC 0x0c055368 */
if(!s->budget--) { s->failed_pc=0x0c055368u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0553a4; }
goto P_0c05536a;
P_0c05536a: /* original 3ba0, guest PC 0x0c05536a */
if(!s->budget--) { s->failed_pc=0x0c05536au; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[10])!=0);
goto P_0c05536c;
P_0c05536c: /* original 8b03, guest PC 0x0c05536c */
if(!s->budget--) { s->failed_pc=0x0c05536cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c05536e;
P_0c05536e: /* original 3750, guest PC 0x0c05536e */
if(!s->budget--) { s->failed_pc=0x0c05536eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[5])!=0);
goto P_0c055370;
P_0c055370: /* original 8b01, guest PC 0x0c055370 */
if(!s->budget--) { s->failed_pc=0x0c055370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055372;
P_0c055372: /* original a001, guest PC 0x0c055372 */
if(!s->budget--) { s->failed_pc=0x0c055372u; return 0; }
r[0]=0x00000000u;
goto P_0c055378;
P_0c055374: /* original e000, guest PC 0x0c055374 */
if(!s->budget--) { s->failed_pc=0x0c055374u; return 0; }
r[0]=0x00000000u;
goto P_0c055376;
P_0c055376: /* original e001, guest PC 0x0c055376 */
if(!s->budget--) { s->failed_pc=0x0c055376u; return 0; }
r[0]=0x00000001u;
goto P_0c055378;
P_0c055378: /* original 6bf6, guest PC 0x0c055378 */
if(!s->budget--) { s->failed_pc=0x0c055378u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05537a;
P_0c05537a: /* original 6af6, guest PC 0x0c05537a */
if(!s->budget--) { s->failed_pc=0x0c05537au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05537c;
P_0c05537c: /* original 69f6, guest PC 0x0c05537c */
if(!s->budget--) { s->failed_pc=0x0c05537cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05537e;
P_0c05537e: /* original 68f6, guest PC 0x0c05537e */
if(!s->budget--) { s->failed_pc=0x0c05537eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055380;
P_0c055380: /* original 67f6, guest PC 0x0c055380 */
if(!s->budget--) { s->failed_pc=0x0c055380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c055382;
P_0c055382: /* original 66f6, guest PC 0x0c055382 */
if(!s->budget--) { s->failed_pc=0x0c055382u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c055384;
P_0c055384: /* original 65f6, guest PC 0x0c055384 */
if(!s->budget--) { s->failed_pc=0x0c055384u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c055386;
P_0c055386: /* original 64f6, guest PC 0x0c055386 */
if(!s->budget--) { s->failed_pc=0x0c055386u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c055388;
P_0c055388: /* original 000b, guest PC 0x0c055388 */
if(!s->budget--) { s->failed_pc=0x0c055388u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c05538a: /* original 7f10, guest PC 0x0c05538a */
if(!s->budget--) { s->failed_pc=0x0c05538au; return 0; }
r[15]+=0x00000010u;
goto P_0c05538c;
P_0c05538c: /* original 2448, guest PC 0x0c05538c */
if(!s->budget--) { s->failed_pc=0x0c05538cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05538e;
P_0c05538e: /* original 8bf2, guest PC 0x0c05538e */
if(!s->budget--) { s->failed_pc=0x0c05538eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055390;
P_0c055390: /* original 2558, guest PC 0x0c055390 */
if(!s->budget--) { s->failed_pc=0x0c055390u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055392;
P_0c055392: /* original 8bf0, guest PC 0x0c055392 */
if(!s->budget--) { s->failed_pc=0x0c055392u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c055394;
P_0c055394: /* original afe5, guest PC 0x0c055394 */
if(!s->budget--) { s->failed_pc=0x0c055394u; return 0; }
goto P_0c055362;
P_0c055396: /* original 0009, guest PC 0x0c055396 */
if(!s->budget--) { s->failed_pc=0x0c055396u; return 0; }
goto P_0c055398;
P_0c055398: /* original 2668, guest PC 0x0c055398 */
if(!s->budget--) { s->failed_pc=0x0c055398u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05539a;
P_0c05539a: /* original 8bec, guest PC 0x0c05539a */
if(!s->budget--) { s->failed_pc=0x0c05539au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c05539c;
P_0c05539c: /* original 2778, guest PC 0x0c05539c */
if(!s->budget--) { s->failed_pc=0x0c05539cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05539e;
P_0c05539e: /* original 8bea, guest PC 0x0c05539e */
if(!s->budget--) { s->failed_pc=0x0c05539eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553a0;
P_0c0553a0: /* original afe1, guest PC 0x0c0553a0 */
if(!s->budget--) { s->failed_pc=0x0c0553a0u; return 0; }
goto P_0c055366;
P_0c0553a2: /* original 0009, guest PC 0x0c0553a2 */
if(!s->budget--) { s->failed_pc=0x0c0553a2u; return 0; }
goto P_0c0553a4;
P_0c0553a4: /* original 2998, guest PC 0x0c0553a4 */
if(!s->budget--) { s->failed_pc=0x0c0553a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0553a6;
P_0c0553a6: /* original 8be6, guest PC 0x0c0553a6 */
if(!s->budget--) { s->failed_pc=0x0c0553a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553a8;
P_0c0553a8: /* original 2448, guest PC 0x0c0553a8 */
if(!s->budget--) { s->failed_pc=0x0c0553a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0553aa;
P_0c0553aa: /* original 8bde, guest PC 0x0c0553aa */
if(!s->budget--) { s->failed_pc=0x0c0553aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05536a; }
goto P_0c0553ac;
P_0c0553ac: /* original 2558, guest PC 0x0c0553ac */
if(!s->budget--) { s->failed_pc=0x0c0553acu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0553ae;
P_0c0553ae: /* original 8bdc, guest PC 0x0c0553ae */
if(!s->budget--) { s->failed_pc=0x0c0553aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05536a; }
goto P_0c0553b0;
P_0c0553b0: /* original 2668, guest PC 0x0c0553b0 */
if(!s->budget--) { s->failed_pc=0x0c0553b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0553b2;
P_0c0553b2: /* original 8be0, guest PC 0x0c0553b2 */
if(!s->budget--) { s->failed_pc=0x0c0553b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553b4;
P_0c0553b4: /* original 2778, guest PC 0x0c0553b4 */
if(!s->budget--) { s->failed_pc=0x0c0553b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0553b6;
P_0c0553b6: /* original 8bde, guest PC 0x0c0553b6 */
if(!s->budget--) { s->failed_pc=0x0c0553b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055376; }
goto P_0c0553b8;
P_0c0553b8: /* original afde, guest PC 0x0c0553b8 */
if(!s->budget--) { s->failed_pc=0x0c0553b8u; return 0; }
r[0]=0x00000000u;
goto P_0c055378;
P_0c0553ba: /* original e000, guest PC 0x0c0553ba */
if(!s->budget--) { s->failed_pc=0x0c0553bau; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c0553bcu,s,ram);
P_0c0553c4: /* original 2fe6, guest PC 0x0c0553c4 */
if(!s->budget--) { s->failed_pc=0x0c0553c4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0553c6;
P_0c0553c6: /* original e700, guest PC 0x0c0553c6 */
if(!s->budget--) { s->failed_pc=0x0c0553c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0553c8;
P_0c0553c8: /* original 2fd6, guest PC 0x0c0553c8 */
if(!s->budget--) { s->failed_pc=0x0c0553c8u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0553ca;
P_0c0553ca: /* original 76ff, guest PC 0x0c0553ca */
if(!s->budget--) { s->failed_pc=0x0c0553cau; return 0; }
r[6]+=0xffffffffu;
goto P_0c0553cc;
P_0c0553cc: /* original 4f22, guest PC 0x0c0553cc */
if(!s->budget--) { s->failed_pc=0x0c0553ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0553ce;
P_0c0553ce: /* original 356c, guest PC 0x0c0553ce */
if(!s->budget--) { s->failed_pc=0x0c0553ceu; return 0; }
r[5]+=r[6];
goto P_0c0553d0;
P_0c0553d0: /* original 9d17, guest PC 0x0c0553d0 */
if(!s->budget--) { s->failed_pc=0x0c0553d0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c055402u,2);
goto P_0c0553d2;
P_0c0553d2: /* original 4611, guest PC 0x0c0553d2 */
if(!s->budget--) { s->failed_pc=0x0c0553d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0553d4;
P_0c0553d4: /* original 8f11, guest PC 0x0c0553d4 */
if(!s->budget--) { s->failed_pc=0x0c0553d4u; return 0; }
cond=r[17]&1u;
r[4]+=r[6];
if(!cond) { goto P_0c0553fa; }
goto P_0c0553d8;
P_0c0553d6: /* original 346c, guest PC 0x0c0553d6 */
if(!s->budget--) { s->failed_pc=0x0c0553d6u; return 0; }
r[4]+=r[6];
goto P_0c0553d8;
P_0c0553d8: /* original 6e40, guest PC 0x0c0553d8 */
if(!s->budget--) { s->failed_pc=0x0c0553d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[14]=tmp;
goto P_0c0553da;
P_0c0553da: /* original 6eec, guest PC 0x0c0553da */
if(!s->budget--) { s->failed_pc=0x0c0553dau; return 0; }
r[14]=r[14]&255u;
goto P_0c0553dc;
P_0c0553dc: /* original 6350, guest PC 0x0c0553dc */
if(!s->budget--) { s->failed_pc=0x0c0553dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c0553de;
P_0c0553de: /* original 633c, guest PC 0x0c0553de */
if(!s->budget--) { s->failed_pc=0x0c0553deu; return 0; }
r[3]=r[3]&255u;
goto P_0c0553e0;
P_0c0553e0: /* original d208, guest PC 0x0c0553e0 */
if(!s->budget--) { s->failed_pc=0x0c0553e0u; return 0; }
r[2]=read(ram,0x0c055404u,4);
goto P_0c0553e2;
P_0c0553e2: /* original 3e3c, guest PC 0x0c0553e2 */
if(!s->budget--) { s->failed_pc=0x0c0553e2u; return 0; }
r[14]+=r[3];
goto P_0c0553e4;
P_0c0553e4: /* original 3e7c, guest PC 0x0c0553e4 */
if(!s->budget--) { s->failed_pc=0x0c0553e4u; return 0; }
r[14]+=r[7];
goto P_0c0553e6;
P_0c0553e6: /* original 61e3, guest PC 0x0c0553e6 */
if(!s->budget--) { s->failed_pc=0x0c0553e6u; return 0; }
r[1]=r[14];
goto P_0c0553e8;
P_0c0553e8: /* original 24e0, guest PC 0x0c0553e8 */
if(!s->budget--) { s->failed_pc=0x0c0553e8u; return 0; }
write(ram,r[4],r[14],1);
goto P_0c0553ea;
P_0c0553ea: /* original 420b, guest PC 0x0c0553ea */
if(!s->budget--) { s->failed_pc=0x0c0553eau; return 0; }
target=r[2];
r[16]=0x0c0553eeu;
r[0]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0553eeu) { target=s->pc; goto dispatch; }
goto P_0c0553ee;
P_0c0553ec: /* original 60d3, guest PC 0x0c0553ec */
if(!s->budget--) { s->failed_pc=0x0c0553ecu; return 0; }
r[0]=r[13];
goto P_0c0553ee;
P_0c0553ee: /* original 6703, guest PC 0x0c0553ee */
if(!s->budget--) { s->failed_pc=0x0c0553eeu; return 0; }
r[7]=r[0];
goto P_0c0553f0;
P_0c0553f0: /* original 76ff, guest PC 0x0c0553f0 */
if(!s->budget--) { s->failed_pc=0x0c0553f0u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0553f2;
P_0c0553f2: /* original 75ff, guest PC 0x0c0553f2 */
if(!s->budget--) { s->failed_pc=0x0c0553f2u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0553f4;
P_0c0553f4: /* original 4611, guest PC 0x0c0553f4 */
if(!s->budget--) { s->failed_pc=0x0c0553f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0553f6;
P_0c0553f6: /* original 8def, guest PC 0x0c0553f6 */
if(!s->budget--) { s->failed_pc=0x0c0553f6u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0553d8; }
goto P_0c0553fa;
P_0c0553f8: /* original 74ff, guest PC 0x0c0553f8 */
if(!s->budget--) { s->failed_pc=0x0c0553f8u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0553fa;
P_0c0553fa: /* original 4f26, guest PC 0x0c0553fa */
if(!s->budget--) { s->failed_pc=0x0c0553fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0553fc;
P_0c0553fc: /* original 6df6, guest PC 0x0c0553fc */
if(!s->budget--) { s->failed_pc=0x0c0553fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0553fe;
P_0c0553fe: /* original 000b, guest PC 0x0c0553fe */
if(!s->budget--) { s->failed_pc=0x0c0553feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c055400: /* original 6ef6, guest PC 0x0c055400 */
if(!s->budget--) { s->failed_pc=0x0c055400u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c055402u,s,ram);
P_0c055420: /* original 4f22, guest PC 0x0c055420 */
if(!s->budget--) { s->failed_pc=0x0c055420u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055422;
P_0c055422: /* original 4f12, guest PC 0x0c055422 */
if(!s->budget--) { s->failed_pc=0x0c055422u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c055424;
P_0c055424: /* original 7fe8, guest PC 0x0c055424 */
if(!s->budget--) { s->failed_pc=0x0c055424u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c055426;
P_0c055426: /* original 1f41, guest PC 0x0c055426 */
if(!s->budget--) { s->failed_pc=0x0c055426u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c055428;
P_0c055428: /* original 430b, guest PC 0x0c055428 */
if(!s->budget--) { s->failed_pc=0x0c055428u; return 0; }
target=r[3];
r[16]=0x0c05542cu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05542cu) { target=s->pc; goto dispatch; }
goto P_0c05542c;
P_0c05542a: /* original 64a3, guest PC 0x0c05542a */
if(!s->budget--) { s->failed_pc=0x0c05542au; return 0; }
r[4]=r[10];
goto P_0c05542c;
P_0c05542c: /* original d828, guest PC 0x0c05542c */
if(!s->budget--) { s->failed_pc=0x0c05542cu; return 0; }
r[8]=read(ram,0x0c0554d0u,4);
goto P_0c05542e;
P_0c05542e: /* original 6df3, guest PC 0x0c05542e */
if(!s->budget--) { s->failed_pc=0x0c05542eu; return 0; }
r[13]=r[15];
goto P_0c055430;
P_0c055430: /* original 7d08, guest PC 0x0c055430 */
if(!s->budget--) { s->failed_pc=0x0c055430u; return 0; }
r[13]+=0x00000008u;
goto P_0c055432;
P_0c055432: /* original eb07, guest PC 0x0c055432 */
if(!s->budget--) { s->failed_pc=0x0c055432u; return 0; }
r[11]=0x00000007u;
goto P_0c055434;
P_0c055434: /* original 6ebf, guest PC 0x0c055434 */
if(!s->budget--) { s->failed_pc=0x0c055434u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c055436;
P_0c055436: /* original 60e3, guest PC 0x0c055436 */
if(!s->budget--) { s->failed_pc=0x0c055436u; return 0; }
r[0]=r[14];
goto P_0c055438;
P_0c055438: /* original 0009, guest PC 0x0c055438 */
if(!s->budget--) { s->failed_pc=0x0c055438u; return 0; }
goto P_0c05543a;
P_0c05543a: /* original 039c, guest PC 0x0c05543a */
if(!s->budget--) { s->failed_pc=0x0c05543au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c05543c;
P_0c05543c: /* original 633c, guest PC 0x0c05543c */
if(!s->budget--) { s->failed_pc=0x0c05543cu; return 0; }
r[3]=r[3]&255u;
goto P_0c05543e;
P_0c05543e: /* original 2338, guest PC 0x0c05543e */
if(!s->budget--) { s->failed_pc=0x0c05543eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c055440;
P_0c055440: /* original 8d34, guest PC 0x0c055440 */
if(!s->budget--) { s->failed_pc=0x0c055440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0554ac; }
goto P_0c055444;
P_0c055442: /* original 0009, guest PC 0x0c055442 */
if(!s->budget--) { s->failed_pc=0x0c055442u; return 0; }
goto P_0c055444;
P_0c055444: /* original d221, guest PC 0x0c055444 */
if(!s->budget--) { s->failed_pc=0x0c055444u; return 0; }
r[2]=read(ram,0x0c0554ccu,4);
goto P_0c055446;
P_0c055446: /* original e610, guest PC 0x0c055446 */
if(!s->budget--) { s->failed_pc=0x0c055446u; return 0; }
r[6]=0x00000010u;
goto P_0c055448;
P_0c055448: /* original e500, guest PC 0x0c055448 */
if(!s->budget--) { s->failed_pc=0x0c055448u; return 0; }
r[5]=0x00000000u;
goto P_0c05544a;
P_0c05544a: /* original 420b, guest PC 0x0c05544a */
if(!s->budget--) { s->failed_pc=0x0c05544au; return 0; }
target=r[2];
r[16]=0x0c05544eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05544eu) { target=s->pc; goto dispatch; }
goto P_0c05544e;
P_0c05544c: /* original 64d3, guest PC 0x0c05544c */
if(!s->budget--) { s->failed_pc=0x0c05544cu; return 0; }
r[4]=r[13];
goto P_0c05544e;
P_0c05544e: /* original ec07, guest PC 0x0c05544e */
if(!s->budget--) { s->failed_pc=0x0c05544eu; return 0; }
r[12]=0x00000007u;
goto P_0c055450;
P_0c055450: /* original 50f1, guest PC 0x0c055450 */
if(!s->budget--) { s->failed_pc=0x0c055450u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c055452;
P_0c055452: /* original 65cf, guest PC 0x0c055452 */
if(!s->budget--) { s->failed_pc=0x0c055452u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c055454;
P_0c055454: /* original 065c, guest PC 0x0c055454 */
if(!s->budget--) { s->failed_pc=0x0c055454u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c055456;
P_0c055456: /* original 666c, guest PC 0x0c055456 */
if(!s->budget--) { s->failed_pc=0x0c055456u; return 0; }
r[6]=r[6]&255u;
goto P_0c055458;
P_0c055458: /* original 6093, guest PC 0x0c055458 */
if(!s->budget--) { s->failed_pc=0x0c055458u; return 0; }
r[0]=r[9];
goto P_0c05545a;
P_0c05545a: /* original 0009, guest PC 0x0c05545a */
if(!s->budget--) { s->failed_pc=0x0c05545au; return 0; }
goto P_0c05545c;
P_0c05545c: /* original 03ec, guest PC 0x0c05545c */
if(!s->budget--) { s->failed_pc=0x0c05545cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c05545e;
P_0c05545e: /* original 64e3, guest PC 0x0c05545e */
if(!s->budget--) { s->failed_pc=0x0c05545eu; return 0; }
r[4]=r[14];
goto P_0c055460;
P_0c055460: /* original 633c, guest PC 0x0c055460 */
if(!s->budget--) { s->failed_pc=0x0c055460u; return 0; }
r[3]=r[3]&255u;
goto P_0c055462;
P_0c055462: /* original 345c, guest PC 0x0c055462 */
if(!s->budget--) { s->failed_pc=0x0c055462u; return 0; }
r[4]+=r[5];
goto P_0c055464;
P_0c055464: /* original 263e, guest PC 0x0c055464 */
if(!s->budget--) { s->failed_pc=0x0c055464u; return 0; }
r[19]=(r[6]&65535u)*(r[3]&65535u);
goto P_0c055466;
P_0c055466: /* original 34dc, guest PC 0x0c055466 */
if(!s->budget--) { s->failed_pc=0x0c055466u; return 0; }
r[4]+=r[13];
goto P_0c055468;
P_0c055468: /* original 8441, guest PC 0x0c055468 */
if(!s->budget--) { s->failed_pc=0x0c055468u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c05546a;
P_0c05546a: /* original 061a, guest PC 0x0c05546a */
if(!s->budget--) { s->failed_pc=0x0c05546au; return 0; }
r[6]=r[19];
goto P_0c05546c;
P_0c05546c: /* original 600c, guest PC 0x0c05546c */
if(!s->budget--) { s->failed_pc=0x0c05546cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05546e;
P_0c05546e: /* original 2f01, guest PC 0x0c05546e */
if(!s->budget--) { s->failed_pc=0x0c05546eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c055470;
P_0c055470: /* original 63f1, guest PC 0x0c055470 */
if(!s->budget--) { s->failed_pc=0x0c055470u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c055472;
P_0c055472: /* original 336c, guest PC 0x0c055472 */
if(!s->budget--) { s->failed_pc=0x0c055472u; return 0; }
r[3]+=r[6];
goto P_0c055474;
P_0c055474: /* original 2f31, guest PC 0x0c055474 */
if(!s->budget--) { s->failed_pc=0x0c055474u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c055476;
P_0c055476: /* original 480b, guest PC 0x0c055476 */
if(!s->budget--) { s->failed_pc=0x0c055476u; return 0; }
target=r[8];
r[16]=0x0c05547au;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05547au) { target=s->pc; goto dispatch; }
goto P_0c05547a;
P_0c055478: /* original 65f3, guest PC 0x0c055478 */
if(!s->budget--) { s->failed_pc=0x0c055478u; return 0; }
r[5]=r[15];
goto P_0c05547a;
P_0c05547a: /* original 7cff, guest PC 0x0c05547a */
if(!s->budget--) { s->failed_pc=0x0c05547au; return 0; }
r[12]+=0xffffffffu;
goto P_0c05547c;
P_0c05547c: /* original 63cf, guest PC 0x0c05547c */
if(!s->budget--) { s->failed_pc=0x0c05547cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c05547e;
P_0c05547e: /* original 4311, guest PC 0x0c05547e */
if(!s->budget--) { s->failed_pc=0x0c05547eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c055480;
P_0c055480: /* original 8de6, guest PC 0x0c055480 */
if(!s->budget--) { s->failed_pc=0x0c055480u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055450; }
goto P_0c055484;
P_0c055482: /* original 0009, guest PC 0x0c055482 */
if(!s->budget--) { s->failed_pc=0x0c055482u; return 0; }
goto P_0c055484;
P_0c055484: /* original 60bf, guest PC 0x0c055484 */
if(!s->budget--) { s->failed_pc=0x0c055484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c055486;
P_0c055486: /* original 8807, guest PC 0x0c055486 */
if(!s->budget--) { s->failed_pc=0x0c055486u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c055488;
P_0c055488: /* original 8f09, guest PC 0x0c055488 */
if(!s->budget--) { s->failed_pc=0x0c055488u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05549e; }
goto P_0c05548c;
P_0c05548a: /* original 0009, guest PC 0x0c05548a */
if(!s->budget--) { s->failed_pc=0x0c05548au; return 0; }
goto P_0c05548c;
P_0c05548c: /* original d211, guest PC 0x0c05548c */
if(!s->budget--) { s->failed_pc=0x0c05548cu; return 0; }
r[2]=read(ram,0x0c0554d4u,4);
goto P_0c05548e;
P_0c05548e: /* original e609, guest PC 0x0c05548e */
if(!s->budget--) { s->failed_pc=0x0c05548eu; return 0; }
r[6]=0x00000009u;
goto P_0c055490;
P_0c055490: /* original 65e3, guest PC 0x0c055490 */
if(!s->budget--) { s->failed_pc=0x0c055490u; return 0; }
r[5]=r[14];
goto P_0c055492;
P_0c055492: /* original 35dc, guest PC 0x0c055492 */
if(!s->budget--) { s->failed_pc=0x0c055492u; return 0; }
r[5]+=r[13];
goto P_0c055494;
P_0c055494: /* original 64e3, guest PC 0x0c055494 */
if(!s->budget--) { s->failed_pc=0x0c055494u; return 0; }
r[4]=r[14];
goto P_0c055496;
P_0c055496: /* original 420b, guest PC 0x0c055496 */
if(!s->budget--) { s->failed_pc=0x0c055496u; return 0; }
target=r[2];
r[16]=0x0c05549au;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05549au) { target=s->pc; goto dispatch; }
goto P_0c05549a;
P_0c055498: /* original 34ac, guest PC 0x0c055498 */
if(!s->budget--) { s->failed_pc=0x0c055498u; return 0; }
r[4]+=r[10];
goto P_0c05549a;
P_0c05549a: /* original a007, guest PC 0x0c05549a */
if(!s->budget--) { s->failed_pc=0x0c05549au; return 0; }
goto P_0c0554ac;
P_0c05549c: /* original 0009, guest PC 0x0c05549c */
if(!s->budget--) { s->failed_pc=0x0c05549cu; return 0; }
goto P_0c05549e;
P_0c05549e: /* original e609, guest PC 0x0c05549e */
if(!s->budget--) { s->failed_pc=0x0c05549eu; return 0; }
r[6]=0x00000009u;
goto P_0c0554a0;
P_0c0554a0: /* original d20d, guest PC 0x0c0554a0 */
if(!s->budget--) { s->failed_pc=0x0c0554a0u; return 0; }
r[2]=read(ram,0x0c0554d8u,4);
goto P_0c0554a2;
P_0c0554a2: /* original 65e3, guest PC 0x0c0554a2 */
if(!s->budget--) { s->failed_pc=0x0c0554a2u; return 0; }
r[5]=r[14];
goto P_0c0554a4;
P_0c0554a4: /* original 35dc, guest PC 0x0c0554a4 */
if(!s->budget--) { s->failed_pc=0x0c0554a4u; return 0; }
r[5]+=r[13];
goto P_0c0554a6;
P_0c0554a6: /* original 64e3, guest PC 0x0c0554a6 */
if(!s->budget--) { s->failed_pc=0x0c0554a6u; return 0; }
r[4]=r[14];
goto P_0c0554a8;
P_0c0554a8: /* original 420b, guest PC 0x0c0554a8 */
if(!s->budget--) { s->failed_pc=0x0c0554a8u; return 0; }
target=r[2];
r[16]=0x0c0554acu;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0554acu) { target=s->pc; goto dispatch; }
goto P_0c0554ac;
P_0c0554aa: /* original 34ac, guest PC 0x0c0554aa */
if(!s->budget--) { s->failed_pc=0x0c0554aau; return 0; }
r[4]+=r[10];
goto P_0c0554ac;
P_0c0554ac: /* original 7bff, guest PC 0x0c0554ac */
if(!s->budget--) { s->failed_pc=0x0c0554acu; return 0; }
r[11]+=0xffffffffu;
goto P_0c0554ae;
P_0c0554ae: /* original 63bf, guest PC 0x0c0554ae */
if(!s->budget--) { s->failed_pc=0x0c0554aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c0554b0;
P_0c0554b0: /* original 4311, guest PC 0x0c0554b0 */
if(!s->budget--) { s->failed_pc=0x0c0554b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0554b2;
P_0c0554b2: /* original 8dbf, guest PC 0x0c0554b2 */
if(!s->budget--) { s->failed_pc=0x0c0554b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055434; }
goto P_0c0554b6;
P_0c0554b4: /* original 0009, guest PC 0x0c0554b4 */
if(!s->budget--) { s->failed_pc=0x0c0554b4u; return 0; }
goto P_0c0554b6;
P_0c0554b6: /* original 7f18, guest PC 0x0c0554b6 */
if(!s->budget--) { s->failed_pc=0x0c0554b6u; return 0; }
r[15]+=0x00000018u;
goto P_0c0554b8;
P_0c0554b8: /* original 4f16, guest PC 0x0c0554b8 */
if(!s->budget--) { s->failed_pc=0x0c0554b8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0554ba;
P_0c0554ba: /* original 4f26, guest PC 0x0c0554ba */
if(!s->budget--) { s->failed_pc=0x0c0554bau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0554bc;
P_0c0554bc: /* original 68f6, guest PC 0x0c0554bc */
if(!s->budget--) { s->failed_pc=0x0c0554bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0554be;
P_0c0554be: /* original 69f6, guest PC 0x0c0554be */
if(!s->budget--) { s->failed_pc=0x0c0554beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0554c0;
P_0c0554c0: /* original 6af6, guest PC 0x0c0554c0 */
if(!s->budget--) { s->failed_pc=0x0c0554c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0554c2;
P_0c0554c2: /* original 6bf6, guest PC 0x0c0554c2 */
if(!s->budget--) { s->failed_pc=0x0c0554c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0554c4;
P_0c0554c4: /* original 6cf6, guest PC 0x0c0554c4 */
if(!s->budget--) { s->failed_pc=0x0c0554c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0554c6;
P_0c0554c6: /* original 6df6, guest PC 0x0c0554c6 */
if(!s->budget--) { s->failed_pc=0x0c0554c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0554c8;
P_0c0554c8: /* original 000b, guest PC 0x0c0554c8 */
if(!s->budget--) { s->failed_pc=0x0c0554c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0554ca: /* original 6ef6, guest PC 0x0c0554ca */
if(!s->budget--) { s->failed_pc=0x0c0554cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0554ccu,s,ram);
P_0c0554ec: /* original 4f22, guest PC 0x0c0554ec */
if(!s->budget--) { s->failed_pc=0x0c0554ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0554ee;
P_0c0554ee: /* original 7ff0, guest PC 0x0c0554ee */
if(!s->budget--) { s->failed_pc=0x0c0554eeu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0554f0;
P_0c0554f0: /* original 2f62, guest PC 0x0c0554f0 */
if(!s->budget--) { s->failed_pc=0x0c0554f0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0554f2;
P_0c0554f2: /* original 65f3, guest PC 0x0c0554f2 */
if(!s->budget--) { s->failed_pc=0x0c0554f2u; return 0; }
r[5]=r[15];
goto P_0c0554f4;
P_0c0554f4: /* original 2d31, guest PC 0x0c0554f4 */
if(!s->budget--) { s->failed_pc=0x0c0554f4u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0554f6;
P_0c0554f6: /* original 420b, guest PC 0x0c0554f6 */
if(!s->budget--) { s->failed_pc=0x0c0554f6u; return 0; }
target=r[2];
r[16]=0x0c0554fau;
r[5]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0554fau) { target=s->pc; goto dispatch; }
goto P_0c0554fa;
P_0c0554f8: /* original 7508, guest PC 0x0c0554f8 */
if(!s->budget--) { s->failed_pc=0x0c0554f8u; return 0; }
r[5]+=0x00000008u;
goto P_0c0554fa;
P_0c0554fa: /* original e608, guest PC 0x0c0554fa */
if(!s->budget--) { s->failed_pc=0x0c0554fau; return 0; }
r[6]=0x00000008u;
goto P_0c0554fc;
P_0c0554fc: /* original d31b, guest PC 0x0c0554fc */
if(!s->budget--) { s->failed_pc=0x0c0554fcu; return 0; }
r[3]=read(ram,0x0c05556cu,4);
goto P_0c0554fe;
P_0c0554fe: /* original e500, guest PC 0x0c0554fe */
if(!s->budget--) { s->failed_pc=0x0c0554feu; return 0; }
r[5]=0x00000000u;
goto P_0c055500;
P_0c055500: /* original 430b, guest PC 0x0c055500 */
if(!s->budget--) { s->failed_pc=0x0c055500u; return 0; }
target=r[3];
r[16]=0x0c055504u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055504u) { target=s->pc; goto dispatch; }
goto P_0c055504;
P_0c055502: /* original 64f2, guest PC 0x0c055502 */
if(!s->budget--) { s->failed_pc=0x0c055502u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c055504;
P_0c055504: /* original eb00, guest PC 0x0c055504 */
if(!s->budget--) { s->failed_pc=0x0c055504u; return 0; }
r[11]=0x00000000u;
goto P_0c055506;
P_0c055506: /* original 6cb3, guest PC 0x0c055506 */
if(!s->budget--) { s->failed_pc=0x0c055506u; return 0; }
r[12]=r[11];
goto P_0c055508;
P_0c055508: /* original 6ef3, guest PC 0x0c055508 */
if(!s->budget--) { s->failed_pc=0x0c055508u; return 0; }
r[14]=r[15];
goto P_0c05550a;
P_0c05550a: /* original a005, guest PC 0x0c05550a */
if(!s->budget--) { s->failed_pc=0x0c05550au; return 0; }
r[14]+=0x00000008u;
goto P_0c055518;
P_0c05550c: /* original 7e08, guest PC 0x0c05550c */
if(!s->budget--) { s->failed_pc=0x0c05550cu; return 0; }
r[14]+=0x00000008u;
goto P_0c05550e;
P_0c05550e: /* original 7e01, guest PC 0x0c05550e */
if(!s->budget--) { s->failed_pc=0x0c05550eu; return 0; }
r[14]+=0x00000001u;
goto P_0c055510;
P_0c055510: /* original 63d1, guest PC 0x0c055510 */
if(!s->budget--) { s->failed_pc=0x0c055510u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c055512;
P_0c055512: /* original 7b01, guest PC 0x0c055512 */
if(!s->budget--) { s->failed_pc=0x0c055512u; return 0; }
r[11]+=0x00000001u;
goto P_0c055514;
P_0c055514: /* original 73f8, guest PC 0x0c055514 */
if(!s->budget--) { s->failed_pc=0x0c055514u; return 0; }
r[3]+=0xfffffff8u;
goto P_0c055516;
P_0c055516: /* original 2d31, guest PC 0x0c055516 */
if(!s->budget--) { s->failed_pc=0x0c055516u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c055518;
P_0c055518: /* original 62e0, guest PC 0x0c055518 */
if(!s->budget--) { s->failed_pc=0x0c055518u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c05551a;
P_0c05551a: /* original 2228, guest PC 0x0c05551a */
if(!s->budget--) { s->failed_pc=0x0c05551au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05551c;
P_0c05551c: /* original 8df7, guest PC 0x0c05551c */
if(!s->budget--) { s->failed_pc=0x0c05551cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05550e; }
goto P_0c055520;
P_0c05551e: /* original 0009, guest PC 0x0c05551e */
if(!s->budget--) { s->failed_pc=0x0c05551eu; return 0; }
goto P_0c055520;
P_0c055520: /* original 9420, guest PC 0x0c055520 */
if(!s->budget--) { s->failed_pc=0x0c055520u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c055564u,2);
goto P_0c055522;
P_0c055522: /* original a003, guest PC 0x0c055522 */
if(!s->budget--) { s->failed_pc=0x0c055522u; return 0; }
goto P_0c05552c;
P_0c055524: /* original 0009, guest PC 0x0c055524 */
if(!s->budget--) { s->failed_pc=0x0c055524u; return 0; }
goto P_0c055526;
P_0c055526: /* original 644c, guest PC 0x0c055526 */
if(!s->budget--) { s->failed_pc=0x0c055526u; return 0; }
r[4]=r[4]&255u;
goto P_0c055528;
P_0c055528: /* original 4401, guest PC 0x0c055528 */
if(!s->budget--) { s->failed_pc=0x0c055528u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05552a;
P_0c05552a: /* original 7c01, guest PC 0x0c05552a */
if(!s->budget--) { s->failed_pc=0x0c05552au; return 0; }
r[12]+=0x00000001u;
goto P_0c05552c;
P_0c05552c: /* original 63e0, guest PC 0x0c05552c */
if(!s->budget--) { s->failed_pc=0x0c05552cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c05552e;
P_0c05552e: /* original 624c, guest PC 0x0c05552e */
if(!s->budget--) { s->failed_pc=0x0c05552eu; return 0; }
r[2]=r[4]&255u;
goto P_0c055530;
P_0c055530: /* original 633c, guest PC 0x0c055530 */
if(!s->budget--) { s->failed_pc=0x0c055530u; return 0; }
r[3]=r[3]&255u;
goto P_0c055532;
P_0c055532: /* original 2328, guest PC 0x0c055532 */
if(!s->budget--) { s->failed_pc=0x0c055532u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c055534;
P_0c055534: /* original 8df7, guest PC 0x0c055534 */
if(!s->budget--) { s->failed_pc=0x0c055534u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055526; }
goto P_0c055538;
P_0c055536: /* original 0009, guest PC 0x0c055536 */
if(!s->budget--) { s->failed_pc=0x0c055536u; return 0; }
goto P_0c055538;
P_0c055538: /* original d30d, guest PC 0x0c055538 */
if(!s->budget--) { s->failed_pc=0x0c055538u; return 0; }
r[3]=read(ram,0x0c055570u,4);
goto P_0c05553a;
P_0c05553a: /* original 66c3, guest PC 0x0c05553a */
if(!s->budget--) { s->failed_pc=0x0c05553au; return 0; }
r[6]=r[12];
goto P_0c05553c;
P_0c05553c: /* original e508, guest PC 0x0c05553c */
if(!s->budget--) { s->failed_pc=0x0c05553cu; return 0; }
r[5]=0x00000008u;
goto P_0c05553e;
P_0c05553e: /* original 35b8, guest PC 0x0c05553e */
if(!s->budget--) { s->failed_pc=0x0c05553eu; return 0; }
r[5]-=r[11];
goto P_0c055540;
P_0c055540: /* original 1f51, guest PC 0x0c055540 */
if(!s->budget--) { s->failed_pc=0x0c055540u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c055542;
P_0c055542: /* original 430b, guest PC 0x0c055542 */
if(!s->budget--) { s->failed_pc=0x0c055542u; return 0; }
target=r[3];
r[16]=0x0c055546u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055546u) { target=s->pc; goto dispatch; }
goto P_0c055546;
P_0c055544: /* original 64e3, guest PC 0x0c055544 */
if(!s->budget--) { s->failed_pc=0x0c055544u; return 0; }
r[4]=r[14];
goto P_0c055546;
P_0c055546: /* original 65e3, guest PC 0x0c055546 */
if(!s->budget--) { s->failed_pc=0x0c055546u; return 0; }
r[5]=r[14];
goto P_0c055548;
P_0c055548: /* original d30a, guest PC 0x0c055548 */
if(!s->budget--) { s->failed_pc=0x0c055548u; return 0; }
r[3]=read(ram,0x0c055574u,4);
goto P_0c05554a;
P_0c05554a: /* original 62d1, guest PC 0x0c05554a */
if(!s->budget--) { s->failed_pc=0x0c05554au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c05554c;
P_0c05554c: /* original 32c8, guest PC 0x0c05554c */
if(!s->budget--) { s->failed_pc=0x0c05554cu; return 0; }
r[2]-=r[12];
goto P_0c05554e;
P_0c05554e: /* original 2d21, guest PC 0x0c05554e */
if(!s->budget--) { s->failed_pc=0x0c05554eu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c055550;
P_0c055550: /* original 56f1, guest PC 0x0c055550 */
if(!s->budget--) { s->failed_pc=0x0c055550u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c055552;
P_0c055552: /* original 430b, guest PC 0x0c055552 */
if(!s->budget--) { s->failed_pc=0x0c055552u; return 0; }
target=r[3];
r[16]=0x0c055556u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c055556u) { target=s->pc; goto dispatch; }
goto P_0c055556;
P_0c055554: /* original 64f2, guest PC 0x0c055554 */
if(!s->budget--) { s->failed_pc=0x0c055554u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c055556;
P_0c055556: /* original 7f10, guest PC 0x0c055556 */
if(!s->budget--) { s->failed_pc=0x0c055556u; return 0; }
r[15]+=0x00000010u;
goto P_0c055558;
P_0c055558: /* original 4f26, guest PC 0x0c055558 */
if(!s->budget--) { s->failed_pc=0x0c055558u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05555a;
P_0c05555a: /* original 6bf6, guest PC 0x0c05555a */
if(!s->budget--) { s->failed_pc=0x0c05555au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05555c;
P_0c05555c: /* original 6cf6, guest PC 0x0c05555c */
if(!s->budget--) { s->failed_pc=0x0c05555cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05555e;
P_0c05555e: /* original 6df6, guest PC 0x0c05555e */
if(!s->budget--) { s->failed_pc=0x0c05555eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055560;
P_0c055560: /* original 000b, guest PC 0x0c055560 */
if(!s->budget--) { s->failed_pc=0x0c055560u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c055562: /* original 6ef6, guest PC 0x0c055562 */
if(!s->budget--) { s->failed_pc=0x0c055562u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c055564u,s,ram);
P_0c0555c0: /* original e100, guest PC 0x0c0555c0 */
if(!s->budget--) { s->failed_pc=0x0c0555c0u; return 0; }
r[1]=0x00000000u;
goto P_0c0555c2;
P_0c0555c2: /* original e608, guest PC 0x0c0555c2 */
if(!s->budget--) { s->failed_pc=0x0c0555c2u; return 0; }
r[6]=0x00000008u;
goto P_0c0555c4;
P_0c0555c4: /* original e002, guest PC 0x0c0555c4 */
if(!s->budget--) { s->failed_pc=0x0c0555c4u; return 0; }
r[0]=0x00000002u;
goto P_0c0555c6;
P_0c0555c6: /* original e700, guest PC 0x0c0555c6 */
if(!s->budget--) { s->failed_pc=0x0c0555c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0555c8;
P_0c0555c8: /* original 374c, guest PC 0x0c0555c8 */
if(!s->budget--) { s->failed_pc=0x0c0555c8u; return 0; }
r[7]+=r[4];
goto P_0c0555ca;
P_0c0555ca: /* original 626b, guest PC 0x0c0555ca */
if(!s->budget--) { s->failed_pc=0x0c0555cau; return 0; }
r[2]=0u-r[6];
goto P_0c0555cc;
P_0c0555cc: /* original 6351, guest PC 0x0c0555cc */
if(!s->budget--) { s->failed_pc=0x0c0555ccu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c0555ce;
P_0c0555ce: /* original 633d, guest PC 0x0c0555ce */
if(!s->budget--) { s->failed_pc=0x0c0555ceu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0555d0;
P_0c0555d0: /* original 0009, guest PC 0x0c0555d0 */
if(!s->budget--) { s->failed_pc=0x0c0555d0u; return 0; }
goto P_0c0555d2;
P_0c0555d2: /* original 432d, guest PC 0x0c0555d2 */
if(!s->budget--) { s->failed_pc=0x0c0555d2u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c0555d4;
P_0c0555d4: /* original 2730, guest PC 0x0c0555d4 */
if(!s->budget--) { s->failed_pc=0x0c0555d4u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c0555d6;
P_0c0555d6: /* original 7101, guest PC 0x0c0555d6 */
if(!s->budget--) { s->failed_pc=0x0c0555d6u; return 0; }
r[1]+=0x00000001u;
goto P_0c0555d8;
P_0c0555d8: /* original 76f8, guest PC 0x0c0555d8 */
if(!s->budget--) { s->failed_pc=0x0c0555d8u; return 0; }
r[6]+=0xfffffff8u;
goto P_0c0555da;
P_0c0555da: /* original 3103, guest PC 0x0c0555da */
if(!s->budget--) { s->failed_pc=0x0c0555dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[0])!=0);
goto P_0c0555dc;
P_0c0555dc: /* original 8ff5, guest PC 0x0c0555dc */
if(!s->budget--) { s->failed_pc=0x0c0555dcu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0555ca; }
goto P_0c0555e0;
P_0c0555de: /* original 7701, guest PC 0x0c0555de */
if(!s->budget--) { s->failed_pc=0x0c0555deu; return 0; }
r[7]+=0x00000001u;
goto P_0c0555e0;
P_0c0555e0: /* original 000b, guest PC 0x0c0555e0 */
if(!s->budget--) { s->failed_pc=0x0c0555e0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0555e2: /* original 0009, guest PC 0x0c0555e2 */
if(!s->budget--) { s->failed_pc=0x0c0555e2u; return 0; }
return vf3_matrix_family(0x0c0555e4u,s,ram);
P_0c057020: /* original 4f22, guest PC 0x0c057020 */
if(!s->budget--) { s->failed_pc=0x0c057020u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c057022;
P_0c057022: /* original 0c83, guest PC 0x0c057022 */
if(!s->budget--) { s->failed_pc=0x0c057022u; return 0; }
goto P_0c057024;
P_0c057024: /* original 7804, guest PC 0x0c057024 */
if(!s->budget--) { s->failed_pc=0x0c057024u; return 0; }
r[8]+=0x00000004u;
goto P_0c057026;
P_0c057026: /* original 6085, guest PC 0x0c057026 */
if(!s->budget--) { s->failed_pc=0x0c057026u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[8]+=2;
r[0]=tmp;
goto P_0c057028;
P_0c057028: /* original 4008, guest PC 0x0c057028 */
if(!s->budget--) { s->failed_pc=0x0c057028u; return 0; }
r[0]<<=2;
goto P_0c05702a;
P_0c05702a: /* original 4000, guest PC 0x0c05702a */
if(!s->budget--) { s->failed_pc=0x0c05702au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05702c;
P_0c05702c: /* original 011a, guest PC 0x0c05702c */
if(!s->budget--) { s->failed_pc=0x0c05702cu; return 0; }
r[1]=r[19];
goto P_0c05702e;
P_0c05702e: /* original f016, guest PC 0x0c05702e */
if(!s->budget--) { s->failed_pc=0x0c05702eu; return 0; }
vf3_matrix_load(s,ram,0,r[1]+r[0]);
goto P_0c057030;
P_0c057030: /* original 71fc, guest PC 0x0c057030 */
if(!s->budget--) { s->failed_pc=0x0c057030u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c057032;
P_0c057032: /* original f216, guest PC 0x0c057032 */
if(!s->budget--) { s->failed_pc=0x0c057032u; return 0; }
vf3_matrix_load(s,ram,2,r[1]+r[0]);
goto P_0c057034;
P_0c057034: /* original d308, guest PC 0x0c057034 */
if(!s->budget--) { s->failed_pc=0x0c057034u; return 0; }
r[3]=read(ram,0x0c057058u,4);
goto P_0c057036;
P_0c057036: /* original 430b, guest PC 0x0c057036 */
if(!s->budget--) { s->failed_pc=0x0c057036u; return 0; }
target=r[3];
r[16]=0x0c05703au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05703au) { target=s->pc; goto dispatch; }
goto P_0c05703a;
P_0c057038: /* original 0009, guest PC 0x0c057038 */
if(!s->budget--) { s->failed_pc=0x0c057038u; return 0; }
goto P_0c05703a;
P_0c05703a: /* original 7c30, guest PC 0x0c05703a */
if(!s->budget--) { s->failed_pc=0x0c05703au; return 0; }
r[12]+=0x00000030u;
goto P_0c05703c;
P_0c05703c: /* original fceb, guest PC 0x0c05703c */
if(!s->budget--) { s->failed_pc=0x0c05703cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c05703e;
P_0c05703e: /* original fcdb, guest PC 0x0c05703e */
if(!s->budget--) { s->failed_pc=0x0c05703eu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c057040;
P_0c057040: /* original 78fa, guest PC 0x0c057040 */
if(!s->budget--) { s->failed_pc=0x0c057040u; return 0; }
r[8]+=0xfffffffau;
goto P_0c057042;
P_0c057042: /* original fccb, guest PC 0x0c057042 */
if(!s->budget--) { s->failed_pc=0x0c057042u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[12]);
goto P_0c057044;
P_0c057044: /* original 2c66, guest PC 0x0c057044 */
if(!s->budget--) { s->failed_pc=0x0c057044u; return 0; }
r[12]-=4; write(ram,r[12],r[6],4);
goto P_0c057046;
P_0c057046: /* original e010, guest PC 0x0c057046 */
if(!s->budget--) { s->failed_pc=0x0c057046u; return 0; }
r[0]=0x00000010u;
goto P_0c057048;
P_0c057048: /* original fc27, guest PC 0x0c057048 */
if(!s->budget--) { s->failed_pc=0x0c057048u; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c05704a;
P_0c05704a: /* original e018, guest PC 0x0c05704a */
if(!s->budget--) { s->failed_pc=0x0c05704au; return 0; }
r[0]=0x00000018u;
goto P_0c05704c;
P_0c05704c: /* original fcf7, guest PC 0x0c05704c */
if(!s->budget--) { s->failed_pc=0x0c05704cu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c05704e;
P_0c05704e: /* original e01c, guest PC 0x0c05704e */
if(!s->budget--) { s->failed_pc=0x0c05704eu; return 0; }
r[0]=0x0000001cu;
goto P_0c057050;
P_0c057050: /* original fc07, guest PC 0x0c057050 */
if(!s->budget--) { s->failed_pc=0x0c057050u; return 0; }
vf3_matrix_store(s,ram,0,r[12]+r[0]);
goto P_0c057052;
P_0c057052: /* original 4f26, guest PC 0x0c057052 */
if(!s->budget--) { s->failed_pc=0x0c057052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c057054;
P_0c057054: /* original 000b, guest PC 0x0c057054 */
if(!s->budget--) { s->failed_pc=0x0c057054u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c057056: /* original 0009, guest PC 0x0c057056 */
if(!s->budget--) { s->failed_pc=0x0c057056u; return 0; }
return vf3_matrix_family(0x0c057058u,s,ram);
P_0c059524: /* original 4f22, guest PC 0x0c059524 */
if(!s->budget--) { s->failed_pc=0x0c059524u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059526;
P_0c059526: /* original 7ff8, guest PC 0x0c059526 */
if(!s->budget--) { s->failed_pc=0x0c059526u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059528;
P_0c059528: /* original d31f, guest PC 0x0c059528 */
if(!s->budget--) { s->failed_pc=0x0c059528u; return 0; }
r[3]=read(ram,0x0c0595a8u,4);
goto P_0c05952a;
P_0c05952a: /* original 2f42, guest PC 0x0c05952a */
if(!s->budget--) { s->failed_pc=0x0c05952au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05952c;
P_0c05952c: /* original 1f51, guest PC 0x0c05952c */
if(!s->budget--) { s->failed_pc=0x0c05952cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05952e;
P_0c05952e: /* original 430b, guest PC 0x0c05952e */
if(!s->budget--) { s->failed_pc=0x0c05952eu; return 0; }
target=r[3];
r[16]=0x0c059532u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059532u) { target=s->pc; goto dispatch; }
goto P_0c059532;
P_0c059530: /* original e401, guest PC 0x0c059530 */
if(!s->budget--) { s->failed_pc=0x0c059530u; return 0; }
r[4]=0x00000001u;
goto P_0c059532;
P_0c059532: /* original e501, guest PC 0x0c059532 */
if(!s->budget--) { s->failed_pc=0x0c059532u; return 0; }
r[5]=0x00000001u;
goto P_0c059534;
P_0c059534: /* original d31b, guest PC 0x0c059534 */
if(!s->budget--) { s->failed_pc=0x0c059534u; return 0; }
r[3]=read(ram,0x0c0595a4u,4);
goto P_0c059536;
P_0c059536: /* original 57f1, guest PC 0x0c059536 */
if(!s->budget--) { s->failed_pc=0x0c059536u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c059538;
P_0c059538: /* original 66f2, guest PC 0x0c059538 */
if(!s->budget--) { s->failed_pc=0x0c059538u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05953a;
P_0c05953a: /* original bfbb, guest PC 0x0c05953a */
if(!s->budget--) { s->failed_pc=0x0c05953au; return 0; }
target=0x0c0594b4u; r[16]=0x0c05953eu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05953eu) { target=s->pc; goto dispatch; }
goto P_0c05953e;
P_0c05953c: /* original 6432, guest PC 0x0c05953c */
if(!s->budget--) { s->failed_pc=0x0c05953cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05953e;
P_0c05953e: /* original 7f08, guest PC 0x0c05953e */
if(!s->budget--) { s->failed_pc=0x0c05953eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059540;
P_0c059540: /* original 4f26, guest PC 0x0c059540 */
if(!s->budget--) { s->failed_pc=0x0c059540u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059542;
P_0c059542: /* original 000b, guest PC 0x0c059542 */
if(!s->budget--) { s->failed_pc=0x0c059542u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059544: /* original e000, guest PC 0x0c059544 */
if(!s->budget--) { s->failed_pc=0x0c059544u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c059546u,s,ram);
P_0c05b1fc: /* original 2fe6, guest PC 0x0c05b1fc */
if(!s->budget--) { s->failed_pc=0x0c05b1fcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c05b1fe;
P_0c05b1fe: /* original 2fd6, guest PC 0x0c05b1fe */
if(!s->budget--) { s->failed_pc=0x0c05b1feu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c05b200;
P_0c05b200: /* original 2fc6, guest PC 0x0c05b200 */
if(!s->budget--) { s->failed_pc=0x0c05b200u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c05b202;
P_0c05b202: /* original 6d43, guest PC 0x0c05b202 */
if(!s->budget--) { s->failed_pc=0x0c05b202u; return 0; }
r[13]=r[4];
goto P_0c05b204;
P_0c05b204: /* original 9070, guest PC 0x0c05b204 */
if(!s->budget--) { s->failed_pc=0x0c05b204u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b2e8u,2);
goto P_0c05b206;
P_0c05b206: /* original 2fb6, guest PC 0x0c05b206 */
if(!s->budget--) { s->failed_pc=0x0c05b206u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c05b208;
P_0c05b208: /* original 2fa6, guest PC 0x0c05b208 */
if(!s->budget--) { s->failed_pc=0x0c05b208u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c05b20a;
P_0c05b20a: /* original 2f96, guest PC 0x0c05b20a */
if(!s->budget--) { s->failed_pc=0x0c05b20au; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c05b20c;
P_0c05b20c: /* original 2f86, guest PC 0x0c05b20c */
if(!s->budget--) { s->failed_pc=0x0c05b20cu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
return vf3_matrix_family(0x0c05b20eu,s,ram);
P_0c05b890: /* original 2fe6, guest PC 0x0c05b890 */
if(!s->budget--) { s->failed_pc=0x0c05b890u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c05b892;
P_0c05b892: /* original 2fd6, guest PC 0x0c05b892 */
if(!s->budget--) { s->failed_pc=0x0c05b892u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c05b894;
P_0c05b894: /* original d74e, guest PC 0x0c05b894 */
if(!s->budget--) { s->failed_pc=0x0c05b894u; return 0; }
r[7]=read(ram,0x0c05b9d0u,4);
goto P_0c05b896;
P_0c05b896: /* original d64f, guest PC 0x0c05b896 */
if(!s->budget--) { s->failed_pc=0x0c05b896u; return 0; }
r[6]=read(ram,0x0c05b9d4u,4);
goto P_0c05b898;
P_0c05b898: /* original de4f, guest PC 0x0c05b898 */
if(!s->budget--) { s->failed_pc=0x0c05b898u; return 0; }
r[14]=read(ram,0x0c05b9d8u,4);
goto P_0c05b89a;
P_0c05b89a: /* original 9096, guest PC 0x0c05b89a */
if(!s->budget--) { s->failed_pc=0x0c05b89au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b9cau,2);
goto P_0c05b89c;
P_0c05b89c: /* original 034e, guest PC 0x0c05b89c */
if(!s->budget--) { s->failed_pc=0x0c05b89cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b89e;
P_0c05b89e: /* original 7004, guest PC 0x0c05b89e */
if(!s->budget--) { s->failed_pc=0x0c05b89eu; return 0; }
r[0]+=0x00000004u;
goto P_0c05b8a0;
P_0c05b8a0: /* original 2e32, guest PC 0x0c05b8a0 */
if(!s->budget--) { s->failed_pc=0x0c05b8a0u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c05b8a2;
P_0c05b8a2: /* original 024e, guest PC 0x0c05b8a2 */
if(!s->budget--) { s->failed_pc=0x0c05b8a2u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c05b8a4;
P_0c05b8a4: /* original 1e24, guest PC 0x0c05b8a4 */
if(!s->budget--) { s->failed_pc=0x0c05b8a4u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c05b8a6;
P_0c05b8a6: /* original 7004, guest PC 0x0c05b8a6 */
if(!s->budget--) { s->failed_pc=0x0c05b8a6u; return 0; }
r[0]+=0x00000004u;
goto P_0c05b8a8;
P_0c05b8a8: /* original 034e, guest PC 0x0c05b8a8 */
if(!s->budget--) { s->failed_pc=0x0c05b8a8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b8aa;
P_0c05b8aa: /* original 1e35, guest PC 0x0c05b8aa */
if(!s->budget--) { s->failed_pc=0x0c05b8aau; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c05b8ac;
P_0c05b8ac: /* original 60e2, guest PC 0x0c05b8ac */
if(!s->budget--) { s->failed_pc=0x0c05b8acu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05b8ae;
P_0c05b8ae: /* original 4029, guest PC 0x0c05b8ae */
if(!s->budget--) { s->failed_pc=0x0c05b8aeu; return 0; }
r[0]>>=16;
goto P_0c05b8b0;
P_0c05b8b0: /* original 4019, guest PC 0x0c05b8b0 */
if(!s->budget--) { s->failed_pc=0x0c05b8b0u; return 0; }
r[0]>>=8;
goto P_0c05b8b2;
P_0c05b8b2: /* original c807, guest PC 0x0c05b8b2 */
if(!s->budget--) { s->failed_pc=0x0c05b8b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c05b8b4;
P_0c05b8b4: /* original 8b07, guest PC 0x0c05b8b4 */
if(!s->budget--) { s->failed_pc=0x0c05b8b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b8c6; }
goto P_0c05b8b6;
P_0c05b8b6: /* original 65e3, guest PC 0x0c05b8b6 */
if(!s->budget--) { s->failed_pc=0x0c05b8b6u; return 0; }
r[5]=r[14];
goto P_0c05b8b8;
P_0c05b8b8: /* original d348, guest PC 0x0c05b8b8 */
if(!s->budget--) { s->failed_pc=0x0c05b8b8u; return 0; }
r[3]=read(ram,0x0c05b9dcu,4);
goto P_0c05b8ba;
P_0c05b8ba: /* original 7510, guest PC 0x0c05b8ba */
if(!s->budget--) { s->failed_pc=0x0c05b8bau; return 0; }
r[5]+=0x00000010u;
goto P_0c05b8bc;
P_0c05b8bc: /* original d148, guest PC 0x0c05b8bc */
if(!s->budget--) { s->failed_pc=0x0c05b8bcu; return 0; }
r[1]=read(ram,0x0c05b9e0u,4);
goto P_0c05b8be;
P_0c05b8be: /* original 5251, guest PC 0x0c05b8be */
if(!s->budget--) { s->failed_pc=0x0c05b8beu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c05b8c0;
P_0c05b8c0: /* original 2239, guest PC 0x0c05b8c0 */
if(!s->budget--) { s->failed_pc=0x0c05b8c0u; return 0; }
r[2]&=r[3];
goto P_0c05b8c2;
P_0c05b8c2: /* original 221b, guest PC 0x0c05b8c2 */
if(!s->budget--) { s->failed_pc=0x0c05b8c2u; return 0; }
r[2]|=r[1];
goto P_0c05b8c4;
P_0c05b8c4: /* original 1521, guest PC 0x0c05b8c4 */
if(!s->budget--) { s->failed_pc=0x0c05b8c4u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c05b8c6;
P_0c05b8c6: /* original 9081, guest PC 0x0c05b8c6 */
if(!s->budget--) { s->failed_pc=0x0c05b8c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b9ccu,2);
goto P_0c05b8c8;
P_0c05b8c8: /* original 034e, guest PC 0x0c05b8c8 */
if(!s->budget--) { s->failed_pc=0x0c05b8c8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b8ca;
P_0c05b8ca: /* original e070, guest PC 0x0c05b8ca */
if(!s->budget--) { s->failed_pc=0x0c05b8cau; return 0; }
r[0]=0x00000070u;
goto P_0c05b8cc;
P_0c05b8cc: /* original 1e36, guest PC 0x0c05b8cc */
if(!s->budget--) { s->failed_pc=0x0c05b8ccu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c05b8ce;
P_0c05b8ce: /* original f346, guest PC 0x0c05b8ce */
if(!s->budget--) { s->failed_pc=0x0c05b8ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8d0;
P_0c05b8d0: /* original e020, guest PC 0x0c05b8d0 */
if(!s->budget--) { s->failed_pc=0x0c05b8d0u; return 0; }
r[0]=0x00000020u;
goto P_0c05b8d2;
P_0c05b8d2: /* original fe37, guest PC 0x0c05b8d2 */
if(!s->budget--) { s->failed_pc=0x0c05b8d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8d4;
P_0c05b8d4: /* original e074, guest PC 0x0c05b8d4 */
if(!s->budget--) { s->failed_pc=0x0c05b8d4u; return 0; }
r[0]=0x00000074u;
goto P_0c05b8d6;
P_0c05b8d6: /* original f346, guest PC 0x0c05b8d6 */
if(!s->budget--) { s->failed_pc=0x0c05b8d6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8d8;
P_0c05b8d8: /* original e024, guest PC 0x0c05b8d8 */
if(!s->budget--) { s->failed_pc=0x0c05b8d8u; return 0; }
r[0]=0x00000024u;
goto P_0c05b8da;
P_0c05b8da: /* original fe37, guest PC 0x0c05b8da */
if(!s->budget--) { s->failed_pc=0x0c05b8dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8dc;
P_0c05b8dc: /* original e078, guest PC 0x0c05b8dc */
if(!s->budget--) { s->failed_pc=0x0c05b8dcu; return 0; }
r[0]=0x00000078u;
goto P_0c05b8de;
P_0c05b8de: /* original f346, guest PC 0x0c05b8de */
if(!s->budget--) { s->failed_pc=0x0c05b8deu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8e0;
P_0c05b8e0: /* original e028, guest PC 0x0c05b8e0 */
if(!s->budget--) { s->failed_pc=0x0c05b8e0u; return 0; }
r[0]=0x00000028u;
goto P_0c05b8e2;
P_0c05b8e2: /* original fe37, guest PC 0x0c05b8e2 */
if(!s->budget--) { s->failed_pc=0x0c05b8e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8e4;
P_0c05b8e4: /* original e07c, guest PC 0x0c05b8e4 */
if(!s->budget--) { s->failed_pc=0x0c05b8e4u; return 0; }
r[0]=0x0000007cu;
goto P_0c05b8e6;
P_0c05b8e6: /* original f346, guest PC 0x0c05b8e6 */
if(!s->budget--) { s->failed_pc=0x0c05b8e6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8e8;
P_0c05b8e8: /* original e02c, guest PC 0x0c05b8e8 */
if(!s->budget--) { s->failed_pc=0x0c05b8e8u; return 0; }
r[0]=0x0000002cu;
goto P_0c05b8ea;
P_0c05b8ea: /* original fe37, guest PC 0x0c05b8ea */
if(!s->budget--) { s->failed_pc=0x0c05b8eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8ec;
P_0c05b8ec: /* original 7054, guest PC 0x0c05b8ec */
if(!s->budget--) { s->failed_pc=0x0c05b8ecu; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8ee;
P_0c05b8ee: /* original f346, guest PC 0x0c05b8ee */
if(!s->budget--) { s->failed_pc=0x0c05b8eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8f0;
P_0c05b8f0: /* original e030, guest PC 0x0c05b8f0 */
if(!s->budget--) { s->failed_pc=0x0c05b8f0u; return 0; }
r[0]=0x00000030u;
goto P_0c05b8f2;
P_0c05b8f2: /* original fe37, guest PC 0x0c05b8f2 */
if(!s->budget--) { s->failed_pc=0x0c05b8f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8f4;
P_0c05b8f4: /* original 7054, guest PC 0x0c05b8f4 */
if(!s->budget--) { s->failed_pc=0x0c05b8f4u; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8f6;
P_0c05b8f6: /* original f346, guest PC 0x0c05b8f6 */
if(!s->budget--) { s->failed_pc=0x0c05b8f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8f8;
P_0c05b8f8: /* original e034, guest PC 0x0c05b8f8 */
if(!s->budget--) { s->failed_pc=0x0c05b8f8u; return 0; }
r[0]=0x00000034u;
goto P_0c05b8fa;
P_0c05b8fa: /* original fe37, guest PC 0x0c05b8fa */
if(!s->budget--) { s->failed_pc=0x0c05b8fau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8fc;
P_0c05b8fc: /* original 7054, guest PC 0x0c05b8fc */
if(!s->budget--) { s->failed_pc=0x0c05b8fcu; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8fe;
P_0c05b8fe: /* original f346, guest PC 0x0c05b8fe */
if(!s->budget--) { s->failed_pc=0x0c05b8feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b900;
P_0c05b900: /* original e038, guest PC 0x0c05b900 */
if(!s->budget--) { s->failed_pc=0x0c05b900u; return 0; }
r[0]=0x00000038u;
goto P_0c05b902;
P_0c05b902: /* original fe37, guest PC 0x0c05b902 */
if(!s->budget--) { s->failed_pc=0x0c05b902u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b904;
P_0c05b904: /* original d537, guest PC 0x0c05b904 */
if(!s->budget--) { s->failed_pc=0x0c05b904u; return 0; }
r[5]=read(ram,0x0c05b9e4u,4);
goto P_0c05b906;
P_0c05b906: /* original e120, guest PC 0x0c05b906 */
if(!s->budget--) { s->failed_pc=0x0c05b906u; return 0; }
r[1]=0x00000020u;
goto P_0c05b908;
P_0c05b908: /* original d237, guest PC 0x0c05b908 */
if(!s->budget--) { s->failed_pc=0x0c05b908u; return 0; }
r[2]=read(ram,0x0c05b9e8u,4);
goto P_0c05b90a;
P_0c05b90a: /* original 7054, guest PC 0x0c05b90a */
if(!s->budget--) { s->failed_pc=0x0c05b90au; return 0; }
r[0]+=0x00000054u;
goto P_0c05b90c;
P_0c05b90c: /* original f346, guest PC 0x0c05b90c */
if(!s->budget--) { s->failed_pc=0x0c05b90cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b90e;
P_0c05b90e: /* original e03c, guest PC 0x0c05b90e */
if(!s->budget--) { s->failed_pc=0x0c05b90eu; return 0; }
r[0]=0x0000003cu;
goto P_0c05b910;
P_0c05b910: /* original fe37, guest PC 0x0c05b910 */
if(!s->budget--) { s->failed_pc=0x0c05b910u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b912;
P_0c05b912: /* original 7064, guest PC 0x0c05b912 */
if(!s->budget--) { s->failed_pc=0x0c05b912u; return 0; }
r[0]+=0x00000064u;
goto P_0c05b914;
P_0c05b914: /* original 034e, guest PC 0x0c05b914 */
if(!s->budget--) { s->failed_pc=0x0c05b914u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b916;
P_0c05b916: /* original e040, guest PC 0x0c05b916 */
if(!s->budget--) { s->failed_pc=0x0c05b916u; return 0; }
r[0]=0x00000040u;
goto P_0c05b918;
P_0c05b918: /* original 0e36, guest PC 0x0c05b918 */
if(!s->budget--) { s->failed_pc=0x0c05b918u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c05b91a;
P_0c05b91a: /* original 6473, guest PC 0x0c05b91a */
if(!s->budget--) { s->failed_pc=0x0c05b91au; return 0; }
r[4]=r[7];
goto P_0c05b91c;
P_0c05b91c: /* original 6de2, guest PC 0x0c05b91c */
if(!s->budget--) { s->failed_pc=0x0c05b91cu; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c05b91e;
P_0c05b91e: /* original d330, guest PC 0x0c05b91e */
if(!s->budget--) { s->failed_pc=0x0c05b91eu; return 0; }
r[3]=read(ram,0x0c05b9e0u,4);
goto P_0c05b920;
P_0c05b920: /* original 23d9, guest PC 0x0c05b920 */
if(!s->budget--) { s->failed_pc=0x0c05b920u; return 0; }
r[3]&=r[13];
goto P_0c05b922;
P_0c05b922: /* original 4329, guest PC 0x0c05b922 */
if(!s->budget--) { s->failed_pc=0x0c05b922u; return 0; }
r[3]>>=16;
goto P_0c05b924;
P_0c05b924: /* original 4319, guest PC 0x0c05b924 */
if(!s->budget--) { s->failed_pc=0x0c05b924u; return 0; }
r[3]>>=8;
goto P_0c05b926;
P_0c05b926: /* original 22d9, guest PC 0x0c05b926 */
if(!s->budget--) { s->failed_pc=0x0c05b926u; return 0; }
r[2]&=r[13];
goto P_0c05b928;
P_0c05b928: /* original 4229, guest PC 0x0c05b928 */
if(!s->budget--) { s->failed_pc=0x0c05b928u; return 0; }
r[2]>>=16;
goto P_0c05b92a;
P_0c05b92a: /* original 4209, guest PC 0x0c05b92a */
if(!s->budget--) { s->failed_pc=0x0c05b92au; return 0; }
r[2]>>=2;
goto P_0c05b92c;
P_0c05b92c: /* original 4209, guest PC 0x0c05b92c */
if(!s->budget--) { s->failed_pc=0x0c05b92cu; return 0; }
r[2]>>=2;
goto P_0c05b92e;
P_0c05b92e: /* original 232b, guest PC 0x0c05b92e */
if(!s->budget--) { s->failed_pc=0x0c05b92eu; return 0; }
r[3]|=r[2];
goto P_0c05b930;
P_0c05b930: /* original 20d9, guest PC 0x0c05b930 */
if(!s->budget--) { s->failed_pc=0x0c05b930u; return 0; }
r[0]&=r[13];
goto P_0c05b932;
P_0c05b932: /* original 4009, guest PC 0x0c05b932 */
if(!s->budget--) { s->failed_pc=0x0c05b932u; return 0; }
r[0]>>=2;
goto P_0c05b934;
P_0c05b934: /* original 4001, guest PC 0x0c05b934 */
if(!s->budget--) { s->failed_pc=0x0c05b934u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05b936;
P_0c05b936: /* original 230b, guest PC 0x0c05b936 */
if(!s->budget--) { s->failed_pc=0x0c05b936u; return 0; }
r[3]|=r[0];
goto P_0c05b938;
P_0c05b938: /* original 21d9, guest PC 0x0c05b938 */
if(!s->budget--) { s->failed_pc=0x0c05b938u; return 0; }
r[1]&=r[13];
goto P_0c05b93a;
P_0c05b93a: /* original 4109, guest PC 0x0c05b93a */
if(!s->budget--) { s->failed_pc=0x0c05b93au; return 0; }
r[1]>>=2;
goto P_0c05b93c;
P_0c05b93c: /* original 4101, guest PC 0x0c05b93c */
if(!s->budget--) { s->failed_pc=0x0c05b93cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05b93e;
P_0c05b93e: /* original 231b, guest PC 0x0c05b93e */
if(!s->budget--) { s->failed_pc=0x0c05b93eu; return 0; }
r[3]|=r[1];
goto P_0c05b940;
P_0c05b940: /* original e210, guest PC 0x0c05b940 */
if(!s->budget--) { s->failed_pc=0x0c05b940u; return 0; }
r[2]=0x00000010u;
goto P_0c05b942;
P_0c05b942: /* original 22d9, guest PC 0x0c05b942 */
if(!s->budget--) { s->failed_pc=0x0c05b942u; return 0; }
r[2]&=r[13];
goto P_0c05b944;
P_0c05b944: /* original d029, guest PC 0x0c05b944 */
if(!s->budget--) { s->failed_pc=0x0c05b944u; return 0; }
r[0]=read(ram,0x0c05b9ecu,4);
goto P_0c05b946;
P_0c05b946: /* original 4209, guest PC 0x0c05b946 */
if(!s->budget--) { s->failed_pc=0x0c05b946u; return 0; }
r[2]>>=2;
goto P_0c05b948;
P_0c05b948: /* original 4201, guest PC 0x0c05b948 */
if(!s->budget--) { s->failed_pc=0x0c05b948u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05b94a;
P_0c05b94a: /* original 232b, guest PC 0x0c05b94a */
if(!s->budget--) { s->failed_pc=0x0c05b94au; return 0; }
r[3]|=r[2];
goto P_0c05b94c;
P_0c05b94c: /* original e104, guest PC 0x0c05b94c */
if(!s->budget--) { s->failed_pc=0x0c05b94cu; return 0; }
r[1]=0x00000004u;
goto P_0c05b94e;
P_0c05b94e: /* original 21d9, guest PC 0x0c05b94e */
if(!s->budget--) { s->failed_pc=0x0c05b94eu; return 0; }
r[1]&=r[13];
goto P_0c05b950;
P_0c05b950: /* original 4109, guest PC 0x0c05b950 */
if(!s->budget--) { s->failed_pc=0x0c05b950u; return 0; }
r[1]>>=2;
goto P_0c05b952;
P_0c05b952: /* original 231b, guest PC 0x0c05b952 */
if(!s->budget--) { s->failed_pc=0x0c05b952u; return 0; }
r[3]|=r[1];
goto P_0c05b954;
P_0c05b954: /* original 4308, guest PC 0x0c05b954 */
if(!s->budget--) { s->failed_pc=0x0c05b954u; return 0; }
r[3]<<=2;
goto P_0c05b956;
P_0c05b956: /* original 023e, guest PC 0x0c05b956 */
if(!s->budget--) { s->failed_pc=0x0c05b956u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05b958;
P_0c05b958: /* original d325, guest PC 0x0c05b958 */
if(!s->budget--) { s->failed_pc=0x0c05b958u; return 0; }
r[3]=read(ram,0x0c05b9f0u,4);
goto P_0c05b95a;
P_0c05b95a: /* original 2522, guest PC 0x0c05b95a */
if(!s->budget--) { s->failed_pc=0x0c05b95au; return 0; }
write(ram,r[5],r[2],4);
goto P_0c05b95c;
P_0c05b95c: /* original 62e2, guest PC 0x0c05b95c */
if(!s->budget--) { s->failed_pc=0x0c05b95cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c05b95e;
P_0c05b95e: /* original 2422, guest PC 0x0c05b95e */
if(!s->budget--) { s->failed_pc=0x0c05b95eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b960;
P_0c05b960: /* original 61e2, guest PC 0x0c05b960 */
if(!s->budget--) { s->failed_pc=0x0c05b960u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c05b962;
P_0c05b962: /* original 7404, guest PC 0x0c05b962 */
if(!s->budget--) { s->failed_pc=0x0c05b962u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b964;
P_0c05b964: /* original 2139, guest PC 0x0c05b964 */
if(!s->budget--) { s->failed_pc=0x0c05b964u; return 0; }
r[1]&=r[3];
goto P_0c05b966;
P_0c05b966: /* original 4129, guest PC 0x0c05b966 */
if(!s->budget--) { s->failed_pc=0x0c05b966u; return 0; }
r[1]>>=16;
goto P_0c05b968;
P_0c05b968: /* original 4119, guest PC 0x0c05b968 */
if(!s->budget--) { s->failed_pc=0x0c05b968u; return 0; }
r[1]>>=8;
goto P_0c05b96a;
P_0c05b96a: /* original 6013, guest PC 0x0c05b96a */
if(!s->budget--) { s->failed_pc=0x0c05b96au; return 0; }
r[0]=r[1];
goto P_0c05b96c;
P_0c05b96c: /* original 0009, guest PC 0x0c05b96c */
if(!s->budget--) { s->failed_pc=0x0c05b96cu; return 0; }
goto P_0c05b96e;
P_0c05b96e: /* original c801, guest PC 0x0c05b96e */
if(!s->budget--) { s->failed_pc=0x0c05b96eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05b970;
P_0c05b970: /* original 8d02, guest PC 0x0c05b970 */
if(!s->budget--) { s->failed_pc=0x0c05b970u; return 0; }
cond=r[17]&1u;
write(ram,r[6],r[1],4);
if(cond) { goto P_0c05b978; }
goto P_0c05b974;
P_0c05b972: /* original 2612, guest PC 0x0c05b972 */
if(!s->budget--) { s->failed_pc=0x0c05b972u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c05b974;
P_0c05b974: /* original a0cf, guest PC 0x0c05b974 */
if(!s->budget--) { s->failed_pc=0x0c05b974u; return 0; }
goto P_0c05bb16;
P_0c05b976: /* original 0009, guest PC 0x0c05b976 */
if(!s->budget--) { s->failed_pc=0x0c05b976u; return 0; }
goto P_0c05b978;
P_0c05b978: /* original 52e4, guest PC 0x0c05b978 */
if(!s->budget--) { s->failed_pc=0x0c05b978u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c05b97a;
P_0c05b97a: /* original 6de3, guest PC 0x0c05b97a */
if(!s->budget--) { s->failed_pc=0x0c05b97au; return 0; }
r[13]=r[14];
goto P_0c05b97c;
P_0c05b97c: /* original 2422, guest PC 0x0c05b97c */
if(!s->budget--) { s->failed_pc=0x0c05b97cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b97e;
P_0c05b97e: /* original 7d10, guest PC 0x0c05b97e */
if(!s->budget--) { s->failed_pc=0x0c05b97eu; return 0; }
r[13]+=0x00000010u;
goto P_0c05b980;
P_0c05b980: /* original 52e5, guest PC 0x0c05b980 */
if(!s->budget--) { s->failed_pc=0x0c05b980u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c05b982;
P_0c05b982: /* original 7404, guest PC 0x0c05b982 */
if(!s->budget--) { s->failed_pc=0x0c05b982u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b984;
P_0c05b984: /* original 2422, guest PC 0x0c05b984 */
if(!s->budget--) { s->failed_pc=0x0c05b984u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b986;
P_0c05b986: /* original 7404, guest PC 0x0c05b986 */
if(!s->budget--) { s->failed_pc=0x0c05b986u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b988;
P_0c05b988: /* original 52e6, guest PC 0x0c05b988 */
if(!s->budget--) { s->failed_pc=0x0c05b988u; return 0; }
r[2]=read(ram,r[14]+24,4);
goto P_0c05b98a;
P_0c05b98a: /* original 2422, guest PC 0x0c05b98a */
if(!s->budget--) { s->failed_pc=0x0c05b98au; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b98c;
P_0c05b98c: /* original 6052, guest PC 0x0c05b98c */
if(!s->budget--) { s->failed_pc=0x0c05b98cu; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c05b98e;
P_0c05b98e: /* original 8800, guest PC 0x0c05b98e */
if(!s->budget--) { s->failed_pc=0x0c05b98eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05b990;
P_0c05b990: /* original 8d0c, guest PC 0x0c05b990 */
if(!s->budget--) { s->failed_pc=0x0c05b990u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c05b9ac; }
goto P_0c05b994;
P_0c05b992: /* original 7404, guest PC 0x0c05b992 */
if(!s->budget--) { s->failed_pc=0x0c05b992u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b994;
P_0c05b994: /* original 8801, guest PC 0x0c05b994 */
if(!s->budget--) { s->failed_pc=0x0c05b994u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b996;
P_0c05b996: /* original 890b, guest PC 0x0c05b996 */
if(!s->budget--) { s->failed_pc=0x0c05b996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b9b0; }
goto P_0c05b998;
P_0c05b998: /* original 8802, guest PC 0x0c05b998 */
if(!s->budget--) { s->failed_pc=0x0c05b998u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05b99a;
P_0c05b99a: /* original 892b, guest PC 0x0c05b99a */
if(!s->budget--) { s->failed_pc=0x0c05b99au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b9f4; }
goto P_0c05b99c;
P_0c05b99c: /* original 8803, guest PC 0x0c05b99c */
if(!s->budget--) { s->failed_pc=0x0c05b99cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05b99e;
P_0c05b99e: /* original 8946, guest PC 0x0c05b99e */
if(!s->budget--) { s->failed_pc=0x0c05b99eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba2e; }
goto P_0c05b9a0;
P_0c05b9a0: /* original 8804, guest PC 0x0c05b9a0 */
if(!s->budget--) { s->failed_pc=0x0c05b9a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05b9a2;
P_0c05b9a2: /* original 894c, guest PC 0x0c05b9a2 */
if(!s->budget--) { s->failed_pc=0x0c05b9a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba3e; }
goto P_0c05b9a4;
P_0c05b9a4: /* original 8810, guest PC 0x0c05b9a4 */
if(!s->budget--) { s->failed_pc=0x0c05b9a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05b9a6;
P_0c05b9a6: /* original 8977, guest PC 0x0c05b9a6 */
if(!s->budget--) { s->failed_pc=0x0c05b9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba98; }
goto P_0c05b9a8;
P_0c05b9a8: /* original a0b9, guest PC 0x0c05b9a8 */
if(!s->budget--) { s->failed_pc=0x0c05b9a8u; return 0; }
goto P_0c05bb1e;
P_0c05b9aa: /* original 0009, guest PC 0x0c05b9aa */
if(!s->budget--) { s->failed_pc=0x0c05b9aau; return 0; }
goto P_0c05b9ac;
P_0c05b9ac: /* original a0b7, guest PC 0x0c05b9ac */
if(!s->budget--) { s->failed_pc=0x0c05b9acu; return 0; }
r[4]+=0x00000010u;
goto P_0c05bb1e;
P_0c05b9ae: /* original 7410, guest PC 0x0c05b9ae */
if(!s->budget--) { s->failed_pc=0x0c05b9aeu; return 0; }
r[4]+=0x00000010u;
goto P_0c05b9b0;
P_0c05b9b0: /* original 61d3, guest PC 0x0c05b9b0 */
if(!s->budget--) { s->failed_pc=0x0c05b9b0u; return 0; }
r[1]=r[13];
goto P_0c05b9b2;
P_0c05b9b2: /* original 5014, guest PC 0x0c05b9b2 */
if(!s->budget--) { s->failed_pc=0x0c05b9b2u; return 0; }
r[0]=read(ram,r[1]+16,4);
goto P_0c05b9b4;
P_0c05b9b4: /* original 2402, guest PC 0x0c05b9b4 */
if(!s->budget--) { s->failed_pc=0x0c05b9b4u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9b6;
P_0c05b9b6: /* original 7404, guest PC 0x0c05b9b6 */
if(!s->budget--) { s->failed_pc=0x0c05b9b6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9b8;
P_0c05b9b8: /* original 61e3, guest PC 0x0c05b9b8 */
if(!s->budget--) { s->failed_pc=0x0c05b9b8u; return 0; }
r[1]=r[14];
goto P_0c05b9ba;
P_0c05b9ba: /* original 5019, guest PC 0x0c05b9ba */
if(!s->budget--) { s->failed_pc=0x0c05b9bau; return 0; }
r[0]=read(ram,r[1]+36,4);
goto P_0c05b9bc;
P_0c05b9bc: /* original 2402, guest PC 0x0c05b9bc */
if(!s->budget--) { s->failed_pc=0x0c05b9bcu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9be;
P_0c05b9be: /* original 7404, guest PC 0x0c05b9be */
if(!s->budget--) { s->failed_pc=0x0c05b9beu; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9c0;
P_0c05b9c0: /* original 501a, guest PC 0x0c05b9c0 */
if(!s->budget--) { s->failed_pc=0x0c05b9c0u; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c05b9c2;
P_0c05b9c2: /* original 2402, guest PC 0x0c05b9c2 */
if(!s->budget--) { s->failed_pc=0x0c05b9c2u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9c4;
P_0c05b9c4: /* original 7404, guest PC 0x0c05b9c4 */
if(!s->budget--) { s->failed_pc=0x0c05b9c4u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9c6;
P_0c05b9c6: /* original a02f, guest PC 0x0c05b9c6 */
if(!s->budget--) { s->failed_pc=0x0c05b9c6u; return 0; }
r[1]+=0x0000002cu;
goto P_0c05ba28;
P_0c05b9c8: /* original 712c, guest PC 0x0c05b9c8 */
if(!s->budget--) { s->failed_pc=0x0c05b9c8u; return 0; }
r[1]+=0x0000002cu;
return vf3_matrix_family(0x0c05b9cau,s,ram);
P_0c05b9f4: /* original 7410, guest PC 0x0c05b9f4 */
if(!s->budget--) { s->failed_pc=0x0c05b9f4u; return 0; }
r[4]+=0x00000010u;
goto P_0c05b9f6;
P_0c05b9f6: /* original 62d3, guest PC 0x0c05b9f6 */
if(!s->budget--) { s->failed_pc=0x0c05b9f6u; return 0; }
r[2]=r[13];
goto P_0c05b9f8;
P_0c05b9f8: /* original 7210, guest PC 0x0c05b9f8 */
if(!s->budget--) { s->failed_pc=0x0c05b9f8u; return 0; }
r[2]+=0x00000010u;
goto P_0c05b9fa;
P_0c05b9fa: /* original 61e3, guest PC 0x0c05b9fa */
if(!s->budget--) { s->failed_pc=0x0c05b9fau; return 0; }
r[1]=r[14];
goto P_0c05b9fc;
P_0c05b9fc: /* original 6022, guest PC 0x0c05b9fc */
if(!s->budget--) { s->failed_pc=0x0c05b9fcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05b9fe;
P_0c05b9fe: /* original 2402, guest PC 0x0c05b9fe */
if(!s->budget--) { s->failed_pc=0x0c05b9feu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba00;
P_0c05ba00: /* original 5019, guest PC 0x0c05ba00 */
if(!s->budget--) { s->failed_pc=0x0c05ba00u; return 0; }
r[0]=read(ram,r[1]+36,4);
goto P_0c05ba02;
P_0c05ba02: /* original 7404, guest PC 0x0c05ba02 */
if(!s->budget--) { s->failed_pc=0x0c05ba02u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba04;
P_0c05ba04: /* original 2402, guest PC 0x0c05ba04 */
if(!s->budget--) { s->failed_pc=0x0c05ba04u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba06;
P_0c05ba06: /* original 7404, guest PC 0x0c05ba06 */
if(!s->budget--) { s->failed_pc=0x0c05ba06u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba08;
P_0c05ba08: /* original 501a, guest PC 0x0c05ba08 */
if(!s->budget--) { s->failed_pc=0x0c05ba08u; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c05ba0a;
P_0c05ba0a: /* original 2402, guest PC 0x0c05ba0a */
if(!s->budget--) { s->failed_pc=0x0c05ba0au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba0c;
P_0c05ba0c: /* original 501b, guest PC 0x0c05ba0c */
if(!s->budget--) { s->failed_pc=0x0c05ba0cu; return 0; }
r[0]=read(ram,r[1]+44,4);
goto P_0c05ba0e;
P_0c05ba0e: /* original 7404, guest PC 0x0c05ba0e */
if(!s->budget--) { s->failed_pc=0x0c05ba0eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba10;
P_0c05ba10: /* original 2402, guest PC 0x0c05ba10 */
if(!s->budget--) { s->failed_pc=0x0c05ba10u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba12;
P_0c05ba12: /* original 7404, guest PC 0x0c05ba12 */
if(!s->budget--) { s->failed_pc=0x0c05ba12u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba14;
P_0c05ba14: /* original 501c, guest PC 0x0c05ba14 */
if(!s->budget--) { s->failed_pc=0x0c05ba14u; return 0; }
r[0]=read(ram,r[1]+48,4);
goto P_0c05ba16;
P_0c05ba16: /* original 2402, guest PC 0x0c05ba16 */
if(!s->budget--) { s->failed_pc=0x0c05ba16u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba18;
P_0c05ba18: /* original 501d, guest PC 0x0c05ba18 */
if(!s->budget--) { s->failed_pc=0x0c05ba18u; return 0; }
r[0]=read(ram,r[1]+52,4);
goto P_0c05ba1a;
P_0c05ba1a: /* original 7404, guest PC 0x0c05ba1a */
if(!s->budget--) { s->failed_pc=0x0c05ba1au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba1c;
P_0c05ba1c: /* original 2402, guest PC 0x0c05ba1c */
if(!s->budget--) { s->failed_pc=0x0c05ba1cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba1e;
P_0c05ba1e: /* original 7404, guest PC 0x0c05ba1e */
if(!s->budget--) { s->failed_pc=0x0c05ba1eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba20;
P_0c05ba20: /* original 501e, guest PC 0x0c05ba20 */
if(!s->budget--) { s->failed_pc=0x0c05ba20u; return 0; }
r[0]=read(ram,r[1]+56,4);
goto P_0c05ba22;
P_0c05ba22: /* original 713c, guest PC 0x0c05ba22 */
if(!s->budget--) { s->failed_pc=0x0c05ba22u; return 0; }
r[1]+=0x0000003cu;
goto P_0c05ba24;
P_0c05ba24: /* original 2402, guest PC 0x0c05ba24 */
if(!s->budget--) { s->failed_pc=0x0c05ba24u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba26;
P_0c05ba26: /* original 7404, guest PC 0x0c05ba26 */
if(!s->budget--) { s->failed_pc=0x0c05ba26u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba28;
P_0c05ba28: /* original 6012, guest PC 0x0c05ba28 */
if(!s->budget--) { s->failed_pc=0x0c05ba28u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05ba2a;
P_0c05ba2a: /* original a033, guest PC 0x0c05ba2a */
if(!s->budget--) { s->failed_pc=0x0c05ba2au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba94;
P_0c05ba2c: /* original 2402, guest PC 0x0c05ba2c */
if(!s->budget--) { s->failed_pc=0x0c05ba2cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba2e;
P_0c05ba2e: /* original e044, guest PC 0x0c05ba2e */
if(!s->budget--) { s->failed_pc=0x0c05ba2eu; return 0; }
r[0]=0x00000044u;
goto P_0c05ba30;
P_0c05ba30: /* original 02ee, guest PC 0x0c05ba30 */
if(!s->budget--) { s->failed_pc=0x0c05ba30u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba32;
P_0c05ba32: /* original e048, guest PC 0x0c05ba32 */
if(!s->budget--) { s->failed_pc=0x0c05ba32u; return 0; }
r[0]=0x00000048u;
goto P_0c05ba34;
P_0c05ba34: /* original 2422, guest PC 0x0c05ba34 */
if(!s->budget--) { s->failed_pc=0x0c05ba34u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba36;
P_0c05ba36: /* original 7404, guest PC 0x0c05ba36 */
if(!s->budget--) { s->failed_pc=0x0c05ba36u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba38;
P_0c05ba38: /* original 02ee, guest PC 0x0c05ba38 */
if(!s->budget--) { s->failed_pc=0x0c05ba38u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba3a;
P_0c05ba3a: /* original a06a, guest PC 0x0c05ba3a */
if(!s->budget--) { s->failed_pc=0x0c05ba3au; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05bb12;
P_0c05ba3c: /* original 2422, guest PC 0x0c05ba3c */
if(!s->budget--) { s->failed_pc=0x0c05ba3cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba3e;
P_0c05ba3e: /* original e044, guest PC 0x0c05ba3e */
if(!s->budget--) { s->failed_pc=0x0c05ba3eu; return 0; }
r[0]=0x00000044u;
goto P_0c05ba40;
P_0c05ba40: /* original 02ee, guest PC 0x0c05ba40 */
if(!s->budget--) { s->failed_pc=0x0c05ba40u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba42;
P_0c05ba42: /* original 61e3, guest PC 0x0c05ba42 */
if(!s->budget--) { s->failed_pc=0x0c05ba42u; return 0; }
r[1]=r[14];
goto P_0c05ba44;
P_0c05ba44: /* original 2422, guest PC 0x0c05ba44 */
if(!s->budget--) { s->failed_pc=0x0c05ba44u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba46;
P_0c05ba46: /* original e048, guest PC 0x0c05ba46 */
if(!s->budget--) { s->failed_pc=0x0c05ba46u; return 0; }
r[0]=0x00000048u;
goto P_0c05ba48;
P_0c05ba48: /* original 02ee, guest PC 0x0c05ba48 */
if(!s->budget--) { s->failed_pc=0x0c05ba48u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba4a;
P_0c05ba4a: /* original 7404, guest PC 0x0c05ba4a */
if(!s->budget--) { s->failed_pc=0x0c05ba4au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba4c;
P_0c05ba4c: /* original 2422, guest PC 0x0c05ba4c */
if(!s->budget--) { s->failed_pc=0x0c05ba4cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba4e;
P_0c05ba4e: /* original 740c, guest PC 0x0c05ba4e */
if(!s->budget--) { s->failed_pc=0x0c05ba4eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c05ba50;
P_0c05ba50: /* original 5118, guest PC 0x0c05ba50 */
if(!s->budget--) { s->failed_pc=0x0c05ba50u; return 0; }
r[1]=read(ram,r[1]+32,4);
goto P_0c05ba52;
P_0c05ba52: /* original 2412, guest PC 0x0c05ba52 */
if(!s->budget--) { s->failed_pc=0x0c05ba52u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba54;
P_0c05ba54: /* original 7404, guest PC 0x0c05ba54 */
if(!s->budget--) { s->failed_pc=0x0c05ba54u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba56;
P_0c05ba56: /* original 61e3, guest PC 0x0c05ba56 */
if(!s->budget--) { s->failed_pc=0x0c05ba56u; return 0; }
r[1]=r[14];
goto P_0c05ba58;
P_0c05ba58: /* original 5119, guest PC 0x0c05ba58 */
if(!s->budget--) { s->failed_pc=0x0c05ba58u; return 0; }
r[1]=read(ram,r[1]+36,4);
goto P_0c05ba5a;
P_0c05ba5a: /* original 2412, guest PC 0x0c05ba5a */
if(!s->budget--) { s->failed_pc=0x0c05ba5au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba5c;
P_0c05ba5c: /* original 7404, guest PC 0x0c05ba5c */
if(!s->budget--) { s->failed_pc=0x0c05ba5cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba5e;
P_0c05ba5e: /* original 61e3, guest PC 0x0c05ba5e */
if(!s->budget--) { s->failed_pc=0x0c05ba5eu; return 0; }
r[1]=r[14];
goto P_0c05ba60;
P_0c05ba60: /* original 511a, guest PC 0x0c05ba60 */
if(!s->budget--) { s->failed_pc=0x0c05ba60u; return 0; }
r[1]=read(ram,r[1]+40,4);
goto P_0c05ba62;
P_0c05ba62: /* original 2412, guest PC 0x0c05ba62 */
if(!s->budget--) { s->failed_pc=0x0c05ba62u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba64;
P_0c05ba64: /* original 7404, guest PC 0x0c05ba64 */
if(!s->budget--) { s->failed_pc=0x0c05ba64u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba66;
P_0c05ba66: /* original 61e3, guest PC 0x0c05ba66 */
if(!s->budget--) { s->failed_pc=0x0c05ba66u; return 0; }
r[1]=r[14];
goto P_0c05ba68;
P_0c05ba68: /* original 511b, guest PC 0x0c05ba68 */
if(!s->budget--) { s->failed_pc=0x0c05ba68u; return 0; }
r[1]=read(ram,r[1]+44,4);
goto P_0c05ba6a;
P_0c05ba6a: /* original 2412, guest PC 0x0c05ba6a */
if(!s->budget--) { s->failed_pc=0x0c05ba6au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba6c;
P_0c05ba6c: /* original 7404, guest PC 0x0c05ba6c */
if(!s->budget--) { s->failed_pc=0x0c05ba6cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba6e;
P_0c05ba6e: /* original 61e3, guest PC 0x0c05ba6e */
if(!s->budget--) { s->failed_pc=0x0c05ba6eu; return 0; }
r[1]=r[14];
goto P_0c05ba70;
P_0c05ba70: /* original 7150, guest PC 0x0c05ba70 */
if(!s->budget--) { s->failed_pc=0x0c05ba70u; return 0; }
r[1]+=0x00000050u;
goto P_0c05ba72;
P_0c05ba72: /* original 6112, guest PC 0x0c05ba72 */
if(!s->budget--) { s->failed_pc=0x0c05ba72u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba74;
P_0c05ba74: /* original 2412, guest PC 0x0c05ba74 */
if(!s->budget--) { s->failed_pc=0x0c05ba74u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba76;
P_0c05ba76: /* original 7404, guest PC 0x0c05ba76 */
if(!s->budget--) { s->failed_pc=0x0c05ba76u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba78;
P_0c05ba78: /* original 61e3, guest PC 0x0c05ba78 */
if(!s->budget--) { s->failed_pc=0x0c05ba78u; return 0; }
r[1]=r[14];
goto P_0c05ba7a;
P_0c05ba7a: /* original 7154, guest PC 0x0c05ba7a */
if(!s->budget--) { s->failed_pc=0x0c05ba7au; return 0; }
r[1]+=0x00000054u;
goto P_0c05ba7c;
P_0c05ba7c: /* original 6112, guest PC 0x0c05ba7c */
if(!s->budget--) { s->failed_pc=0x0c05ba7cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba7e;
P_0c05ba7e: /* original 2412, guest PC 0x0c05ba7e */
if(!s->budget--) { s->failed_pc=0x0c05ba7eu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba80;
P_0c05ba80: /* original 7404, guest PC 0x0c05ba80 */
if(!s->budget--) { s->failed_pc=0x0c05ba80u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba82;
P_0c05ba82: /* original 61e3, guest PC 0x0c05ba82 */
if(!s->budget--) { s->failed_pc=0x0c05ba82u; return 0; }
r[1]=r[14];
goto P_0c05ba84;
P_0c05ba84: /* original 7158, guest PC 0x0c05ba84 */
if(!s->budget--) { s->failed_pc=0x0c05ba84u; return 0; }
r[1]+=0x00000058u;
goto P_0c05ba86;
P_0c05ba86: /* original 6112, guest PC 0x0c05ba86 */
if(!s->budget--) { s->failed_pc=0x0c05ba86u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba88;
P_0c05ba88: /* original 2412, guest PC 0x0c05ba88 */
if(!s->budget--) { s->failed_pc=0x0c05ba88u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba8a;
P_0c05ba8a: /* original 7404, guest PC 0x0c05ba8a */
if(!s->budget--) { s->failed_pc=0x0c05ba8au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba8c;
P_0c05ba8c: /* original 61e3, guest PC 0x0c05ba8c */
if(!s->budget--) { s->failed_pc=0x0c05ba8cu; return 0; }
r[1]=r[14];
goto P_0c05ba8e;
P_0c05ba8e: /* original 715c, guest PC 0x0c05ba8e */
if(!s->budget--) { s->failed_pc=0x0c05ba8eu; return 0; }
r[1]+=0x0000005cu;
goto P_0c05ba90;
P_0c05ba90: /* original 6112, guest PC 0x0c05ba90 */
if(!s->budget--) { s->failed_pc=0x0c05ba90u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba92;
P_0c05ba92: /* original 2412, guest PC 0x0c05ba92 */
if(!s->budget--) { s->failed_pc=0x0c05ba92u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba94;
P_0c05ba94: /* original a043, guest PC 0x0c05ba94 */
if(!s->budget--) { s->failed_pc=0x0c05ba94u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bb1e;
P_0c05ba96: /* original 7404, guest PC 0x0c05ba96 */
if(!s->budget--) { s->failed_pc=0x0c05ba96u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba98;
P_0c05ba98: /* original c725, guest PC 0x0c05ba98 */
if(!s->budget--) { s->failed_pc=0x0c05ba98u; return 0; }
r[0]=0x0c05bb30u;
goto P_0c05ba9a;
P_0c05ba9a: /* original f408, guest PC 0x0c05ba9a */
if(!s->budget--) { s->failed_pc=0x0c05ba9au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c05ba9c;
P_0c05ba9c: /* original e010, guest PC 0x0c05ba9c */
if(!s->budget--) { s->failed_pc=0x0c05ba9cu; return 0; }
r[0]=0x00000010u;
goto P_0c05ba9e;
P_0c05ba9e: /* original f3d6, guest PC 0x0c05ba9e */
if(!s->budget--) { s->failed_pc=0x0c05ba9eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baa0;
P_0c05baa0: /* original f342, guest PC 0x0c05baa0 */
if(!s->budget--) { s->failed_pc=0x0c05baa0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05baa2;
P_0c05baa2: /* original e014, guest PC 0x0c05baa2 */
if(!s->budget--) { s->failed_pc=0x0c05baa2u; return 0; }
r[0]=0x00000014u;
goto P_0c05baa4;
P_0c05baa4: /* original f33d, guest PC 0x0c05baa4 */
if(!s->budget--) { s->failed_pc=0x0c05baa4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05baa6;
P_0c05baa6: /* original 015a, guest PC 0x0c05baa6 */
if(!s->budget--) { s->failed_pc=0x0c05baa6u; return 0; }
r[1]=r[53];
goto P_0c05baa8;
P_0c05baa8: /* original f3d6, guest PC 0x0c05baa8 */
if(!s->budget--) { s->failed_pc=0x0c05baa8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baaa;
P_0c05baaa: /* original 4128, guest PC 0x0c05baaa */
if(!s->budget--) { s->failed_pc=0x0c05baaau; return 0; }
r[1]<<=16;
goto P_0c05baac;
P_0c05baac: /* original 4118, guest PC 0x0c05baac */
if(!s->budget--) { s->failed_pc=0x0c05baacu; return 0; }
r[1]<<=8;
goto P_0c05baae;
P_0c05baae: /* original f342, guest PC 0x0c05baae */
if(!s->budget--) { s->failed_pc=0x0c05baaeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bab0;
P_0c05bab0: /* original f33d, guest PC 0x0c05bab0 */
if(!s->budget--) { s->failed_pc=0x0c05bab0u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bab2;
P_0c05bab2: /* original 005a, guest PC 0x0c05bab2 */
if(!s->budget--) { s->failed_pc=0x0c05bab2u; return 0; }
r[0]=r[53];
goto P_0c05bab4;
P_0c05bab4: /* original 4028, guest PC 0x0c05bab4 */
if(!s->budget--) { s->failed_pc=0x0c05bab4u; return 0; }
r[0]<<=16;
goto P_0c05bab6;
P_0c05bab6: /* original 210b, guest PC 0x0c05bab6 */
if(!s->budget--) { s->failed_pc=0x0c05bab6u; return 0; }
r[1]|=r[0];
goto P_0c05bab8;
P_0c05bab8: /* original e018, guest PC 0x0c05bab8 */
if(!s->budget--) { s->failed_pc=0x0c05bab8u; return 0; }
r[0]=0x00000018u;
goto P_0c05baba;
P_0c05baba: /* original f3d6, guest PC 0x0c05baba */
if(!s->budget--) { s->failed_pc=0x0c05babau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05babc;
P_0c05babc: /* original f342, guest PC 0x0c05babc */
if(!s->budget--) { s->failed_pc=0x0c05babcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05babe;
P_0c05babe: /* original f33d, guest PC 0x0c05babe */
if(!s->budget--) { s->failed_pc=0x0c05babeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bac0;
P_0c05bac0: /* original 005a, guest PC 0x0c05bac0 */
if(!s->budget--) { s->failed_pc=0x0c05bac0u; return 0; }
r[0]=r[53];
goto P_0c05bac2;
P_0c05bac2: /* original 4018, guest PC 0x0c05bac2 */
if(!s->budget--) { s->failed_pc=0x0c05bac2u; return 0; }
r[0]<<=8;
goto P_0c05bac4;
P_0c05bac4: /* original 210b, guest PC 0x0c05bac4 */
if(!s->budget--) { s->failed_pc=0x0c05bac4u; return 0; }
r[1]|=r[0];
goto P_0c05bac6;
P_0c05bac6: /* original e01c, guest PC 0x0c05bac6 */
if(!s->budget--) { s->failed_pc=0x0c05bac6u; return 0; }
r[0]=0x0000001cu;
goto P_0c05bac8;
P_0c05bac8: /* original f3d6, guest PC 0x0c05bac8 */
if(!s->budget--) { s->failed_pc=0x0c05bac8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baca;
P_0c05baca: /* original f342, guest PC 0x0c05baca */
if(!s->budget--) { s->failed_pc=0x0c05bacau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bacc;
P_0c05bacc: /* original f33d, guest PC 0x0c05bacc */
if(!s->budget--) { s->failed_pc=0x0c05baccu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bace;
P_0c05bace: /* original 005a, guest PC 0x0c05bace */
if(!s->budget--) { s->failed_pc=0x0c05baceu; return 0; }
r[0]=r[53];
goto P_0c05bad0;
P_0c05bad0: /* original 210b, guest PC 0x0c05bad0 */
if(!s->budget--) { s->failed_pc=0x0c05bad0u; return 0; }
r[1]|=r[0];
goto P_0c05bad2;
P_0c05bad2: /* original 2412, guest PC 0x0c05bad2 */
if(!s->budget--) { s->failed_pc=0x0c05bad2u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bad4;
P_0c05bad4: /* original 7404, guest PC 0x0c05bad4 */
if(!s->budget--) { s->failed_pc=0x0c05bad4u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bad6;
P_0c05bad6: /* original 65e3, guest PC 0x0c05bad6 */
if(!s->budget--) { s->failed_pc=0x0c05bad6u; return 0; }
r[5]=r[14];
goto P_0c05bad8;
P_0c05bad8: /* original 7510, guest PC 0x0c05bad8 */
if(!s->budget--) { s->failed_pc=0x0c05bad8u; return 0; }
r[5]+=0x00000010u;
goto P_0c05bada;
P_0c05bada: /* original e020, guest PC 0x0c05bada */
if(!s->budget--) { s->failed_pc=0x0c05badau; return 0; }
r[0]=0x00000020u;
goto P_0c05badc;
P_0c05badc: /* original f356, guest PC 0x0c05badc */
if(!s->budget--) { s->failed_pc=0x0c05badcu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bade;
P_0c05bade: /* original e024, guest PC 0x0c05bade */
if(!s->budget--) { s->failed_pc=0x0c05badeu; return 0; }
r[0]=0x00000024u;
goto P_0c05bae0;
P_0c05bae0: /* original f342, guest PC 0x0c05bae0 */
if(!s->budget--) { s->failed_pc=0x0c05bae0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bae2;
P_0c05bae2: /* original f33d, guest PC 0x0c05bae2 */
if(!s->budget--) { s->failed_pc=0x0c05bae2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bae4;
P_0c05bae4: /* original f356, guest PC 0x0c05bae4 */
if(!s->budget--) { s->failed_pc=0x0c05bae4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bae6;
P_0c05bae6: /* original 015a, guest PC 0x0c05bae6 */
if(!s->budget--) { s->failed_pc=0x0c05bae6u; return 0; }
r[1]=r[53];
goto P_0c05bae8;
P_0c05bae8: /* original 4128, guest PC 0x0c05bae8 */
if(!s->budget--) { s->failed_pc=0x0c05bae8u; return 0; }
r[1]<<=16;
goto P_0c05baea;
P_0c05baea: /* original 4118, guest PC 0x0c05baea */
if(!s->budget--) { s->failed_pc=0x0c05baeau; return 0; }
r[1]<<=8;
goto P_0c05baec;
P_0c05baec: /* original f342, guest PC 0x0c05baec */
if(!s->budget--) { s->failed_pc=0x0c05baecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05baee;
P_0c05baee: /* original f33d, guest PC 0x0c05baee */
if(!s->budget--) { s->failed_pc=0x0c05baeeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05baf0;
P_0c05baf0: /* original 005a, guest PC 0x0c05baf0 */
if(!s->budget--) { s->failed_pc=0x0c05baf0u; return 0; }
r[0]=r[53];
goto P_0c05baf2;
P_0c05baf2: /* original 4028, guest PC 0x0c05baf2 */
if(!s->budget--) { s->failed_pc=0x0c05baf2u; return 0; }
r[0]<<=16;
goto P_0c05baf4;
P_0c05baf4: /* original 210b, guest PC 0x0c05baf4 */
if(!s->budget--) { s->failed_pc=0x0c05baf4u; return 0; }
r[1]|=r[0];
goto P_0c05baf6;
P_0c05baf6: /* original e028, guest PC 0x0c05baf6 */
if(!s->budget--) { s->failed_pc=0x0c05baf6u; return 0; }
r[0]=0x00000028u;
goto P_0c05baf8;
P_0c05baf8: /* original f356, guest PC 0x0c05baf8 */
if(!s->budget--) { s->failed_pc=0x0c05baf8u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bafa;
P_0c05bafa: /* original f342, guest PC 0x0c05bafa */
if(!s->budget--) { s->failed_pc=0x0c05bafau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bafc;
P_0c05bafc: /* original f33d, guest PC 0x0c05bafc */
if(!s->budget--) { s->failed_pc=0x0c05bafcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bafe;
P_0c05bafe: /* original 005a, guest PC 0x0c05bafe */
if(!s->budget--) { s->failed_pc=0x0c05bafeu; return 0; }
r[0]=r[53];
goto P_0c05bb00;
P_0c05bb00: /* original 4018, guest PC 0x0c05bb00 */
if(!s->budget--) { s->failed_pc=0x0c05bb00u; return 0; }
r[0]<<=8;
goto P_0c05bb02;
P_0c05bb02: /* original 210b, guest PC 0x0c05bb02 */
if(!s->budget--) { s->failed_pc=0x0c05bb02u; return 0; }
r[1]|=r[0];
goto P_0c05bb04;
P_0c05bb04: /* original e02c, guest PC 0x0c05bb04 */
if(!s->budget--) { s->failed_pc=0x0c05bb04u; return 0; }
r[0]=0x0000002cu;
goto P_0c05bb06;
P_0c05bb06: /* original f356, guest PC 0x0c05bb06 */
if(!s->budget--) { s->failed_pc=0x0c05bb06u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bb08;
P_0c05bb08: /* original f342, guest PC 0x0c05bb08 */
if(!s->budget--) { s->failed_pc=0x0c05bb08u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bb0a;
P_0c05bb0a: /* original f33d, guest PC 0x0c05bb0a */
if(!s->budget--) { s->failed_pc=0x0c05bb0au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bb0c;
P_0c05bb0c: /* original 005a, guest PC 0x0c05bb0c */
if(!s->budget--) { s->failed_pc=0x0c05bb0cu; return 0; }
r[0]=r[53];
goto P_0c05bb0e;
P_0c05bb0e: /* original 210b, guest PC 0x0c05bb0e */
if(!s->budget--) { s->failed_pc=0x0c05bb0eu; return 0; }
r[1]|=r[0];
goto P_0c05bb10;
P_0c05bb10: /* original 2412, guest PC 0x0c05bb10 */
if(!s->budget--) { s->failed_pc=0x0c05bb10u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bb12;
P_0c05bb12: /* original a004, guest PC 0x0c05bb12 */
if(!s->budget--) { s->failed_pc=0x0c05bb12u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bb1e;
P_0c05bb14: /* original 740c, guest PC 0x0c05bb14 */
if(!s->budget--) { s->failed_pc=0x0c05bb14u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bb16;
P_0c05bb16: /* original e040, guest PC 0x0c05bb16 */
if(!s->budget--) { s->failed_pc=0x0c05bb16u; return 0; }
r[0]=0x00000040u;
goto P_0c05bb18;
P_0c05bb18: /* original 01ee, guest PC 0x0c05bb18 */
if(!s->budget--) { s->failed_pc=0x0c05bb18u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c05bb1a;
P_0c05bb1a: /* original 2412, guest PC 0x0c05bb1a */
if(!s->budget--) { s->failed_pc=0x0c05bb1au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bb1c;
P_0c05bb1c: /* original 741c, guest PC 0x0c05bb1c */
if(!s->budget--) { s->failed_pc=0x0c05bb1cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c05bb1e;
P_0c05bb1e: /* original 3478, guest PC 0x0c05bb1e */
if(!s->budget--) { s->failed_pc=0x0c05bb1eu; return 0; }
r[4]-=r[7];
goto P_0c05bb20;
P_0c05bb20: /* original d504, guest PC 0x0c05bb20 */
if(!s->budget--) { s->failed_pc=0x0c05bb20u; return 0; }
r[5]=read(ram,0x0c05bb34u,4);
goto P_0c05bb22;
P_0c05bb22: /* original e000, guest PC 0x0c05bb22 */
if(!s->budget--) { s->failed_pc=0x0c05bb22u; return 0; }
r[0]=0x00000000u;
goto P_0c05bb24;
P_0c05bb24: /* original 6362, guest PC 0x0c05bb24 */
if(!s->budget--) { s->failed_pc=0x0c05bb24u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c05bb26;
P_0c05bb26: /* original 2532, guest PC 0x0c05bb26 */
if(!s->budget--) { s->failed_pc=0x0c05bb26u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c05bb28;
P_0c05bb28: /* original 1541, guest PC 0x0c05bb28 */
if(!s->budget--) { s->failed_pc=0x0c05bb28u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c05bb2a;
P_0c05bb2a: /* original 6df6, guest PC 0x0c05bb2a */
if(!s->budget--) { s->failed_pc=0x0c05bb2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05bb2c;
P_0c05bb2c: /* original 000b, guest PC 0x0c05bb2c */
if(!s->budget--) { s->failed_pc=0x0c05bb2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05bb2e: /* original 6ef6, guest PC 0x0c05bb2e */
if(!s->budget--) { s->failed_pc=0x0c05bb2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05bb30u,s,ram);
P_0c05db42: /* original 4f22, guest PC 0x0c05db42 */
if(!s->budget--) { s->failed_pc=0x0c05db42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05db44;
P_0c05db44: /* original de29, guest PC 0x0c05db44 */
if(!s->budget--) { s->failed_pc=0x0c05db44u; return 0; }
r[14]=read(ram,0x0c05dbecu,4);
goto P_0c05db46;
P_0c05db46: /* original d32a, guest PC 0x0c05db46 */
if(!s->budget--) { s->failed_pc=0x0c05db46u; return 0; }
r[3]=read(ram,0x0c05dbf0u,4);
goto P_0c05db48;
P_0c05db48: /* original 6532, guest PC 0x0c05db48 */
if(!s->budget--) { s->failed_pc=0x0c05db48u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db4a;
P_0c05db4a: /* original 4e0b, guest PC 0x0c05db4a */
if(!s->budget--) { s->failed_pc=0x0c05db4au; return 0; }
target=r[14];
r[16]=0x0c05db4eu;
r[4]=0x00000068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db4eu) { target=s->pc; goto dispatch; }
goto P_0c05db4e;
P_0c05db4c: /* original e468, guest PC 0x0c05db4c */
if(!s->budget--) { s->failed_pc=0x0c05db4cu; return 0; }
r[4]=0x00000068u;
goto P_0c05db4e;
P_0c05db4e: /* original d229, guest PC 0x0c05db4e */
if(!s->budget--) { s->failed_pc=0x0c05db4eu; return 0; }
r[2]=read(ram,0x0c05dbf4u,4);
goto P_0c05db50;
P_0c05db50: /* original 6522, guest PC 0x0c05db50 */
if(!s->budget--) { s->failed_pc=0x0c05db50u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db52;
P_0c05db52: /* original 4e0b, guest PC 0x0c05db52 */
if(!s->budget--) { s->failed_pc=0x0c05db52u; return 0; }
target=r[14];
r[16]=0x0c05db56u;
r[4]=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db56u) { target=s->pc; goto dispatch; }
goto P_0c05db56;
P_0c05db54: /* original e46c, guest PC 0x0c05db54 */
if(!s->budget--) { s->failed_pc=0x0c05db54u; return 0; }
r[4]=0x0000006cu;
goto P_0c05db56;
P_0c05db56: /* original d328, guest PC 0x0c05db56 */
if(!s->budget--) { s->failed_pc=0x0c05db56u; return 0; }
r[3]=read(ram,0x0c05dbf8u,4);
goto P_0c05db58;
P_0c05db58: /* original 6532, guest PC 0x0c05db58 */
if(!s->budget--) { s->failed_pc=0x0c05db58u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db5a;
P_0c05db5a: /* original 4e0b, guest PC 0x0c05db5a */
if(!s->budget--) { s->failed_pc=0x0c05db5au; return 0; }
target=r[14];
r[16]=0x0c05db5eu;
r[4]=0x0000005cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db5eu) { target=s->pc; goto dispatch; }
goto P_0c05db5e;
P_0c05db5c: /* original e45c, guest PC 0x0c05db5c */
if(!s->budget--) { s->failed_pc=0x0c05db5cu; return 0; }
r[4]=0x0000005cu;
goto P_0c05db5e;
P_0c05db5e: /* original d227, guest PC 0x0c05db5e */
if(!s->budget--) { s->failed_pc=0x0c05db5eu; return 0; }
r[2]=read(ram,0x0c05dbfcu,4);
goto P_0c05db60;
P_0c05db60: /* original 6522, guest PC 0x0c05db60 */
if(!s->budget--) { s->failed_pc=0x0c05db60u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db62;
P_0c05db62: /* original 4e0b, guest PC 0x0c05db62 */
if(!s->budget--) { s->failed_pc=0x0c05db62u; return 0; }
target=r[14];
r[16]=0x0c05db66u;
r[4]=0x0000004cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db66u) { target=s->pc; goto dispatch; }
goto P_0c05db66;
P_0c05db64: /* original e44c, guest PC 0x0c05db64 */
if(!s->budget--) { s->failed_pc=0x0c05db64u; return 0; }
r[4]=0x0000004cu;
goto P_0c05db66;
P_0c05db66: /* original d326, guest PC 0x0c05db66 */
if(!s->budget--) { s->failed_pc=0x0c05db66u; return 0; }
r[3]=read(ram,0x0c05dc00u,4);
goto P_0c05db68;
P_0c05db68: /* original 943c, guest PC 0x0c05db68 */
if(!s->budget--) { s->failed_pc=0x0c05db68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe4u,2);
goto P_0c05db6a;
P_0c05db6a: /* original 4e0b, guest PC 0x0c05db6a */
if(!s->budget--) { s->failed_pc=0x0c05db6au; return 0; }
target=r[14];
r[16]=0x0c05db6eu;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db6eu) { target=s->pc; goto dispatch; }
goto P_0c05db6e;
P_0c05db6c: /* original 6532, guest PC 0x0c05db6c */
if(!s->budget--) { s->failed_pc=0x0c05db6cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db6e;
P_0c05db6e: /* original d225, guest PC 0x0c05db6e */
if(!s->budget--) { s->failed_pc=0x0c05db6eu; return 0; }
r[2]=read(ram,0x0c05dc04u,4);
goto P_0c05db70;
P_0c05db70: /* original 9439, guest PC 0x0c05db70 */
if(!s->budget--) { s->failed_pc=0x0c05db70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe6u,2);
goto P_0c05db72;
P_0c05db72: /* original 4e0b, guest PC 0x0c05db72 */
if(!s->budget--) { s->failed_pc=0x0c05db72u; return 0; }
target=r[14];
r[16]=0x0c05db76u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db76u) { target=s->pc; goto dispatch; }
goto P_0c05db76;
P_0c05db74: /* original 6522, guest PC 0x0c05db74 */
if(!s->budget--) { s->failed_pc=0x0c05db74u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db76;
P_0c05db76: /* original d324, guest PC 0x0c05db76 */
if(!s->budget--) { s->failed_pc=0x0c05db76u; return 0; }
r[3]=read(ram,0x0c05dc08u,4);
goto P_0c05db78;
P_0c05db78: /* original 6532, guest PC 0x0c05db78 */
if(!s->budget--) { s->failed_pc=0x0c05db78u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db7a;
P_0c05db7a: /* original 4e0b, guest PC 0x0c05db7a */
if(!s->budget--) { s->failed_pc=0x0c05db7au; return 0; }
target=r[14];
r[16]=0x0c05db7eu;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db7eu) { target=s->pc; goto dispatch; }
goto P_0c05db7e;
P_0c05db7c: /* original e448, guest PC 0x0c05db7c */
if(!s->budget--) { s->failed_pc=0x0c05db7cu; return 0; }
r[4]=0x00000048u;
goto P_0c05db7e;
P_0c05db7e: /* original e3fe, guest PC 0x0c05db7e */
if(!s->budget--) { s->failed_pc=0x0c05db7eu; return 0; }
r[3]=0xfffffffeu;
goto P_0c05db80;
P_0c05db80: /* original d222, guest PC 0x0c05db80 */
if(!s->budget--) { s->failed_pc=0x0c05db80u; return 0; }
r[2]=read(ram,0x0c05dc0cu,4);
goto P_0c05db82;
P_0c05db82: /* original 6522, guest PC 0x0c05db82 */
if(!s->budget--) { s->failed_pc=0x0c05db82u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db84;
P_0c05db84: /* original 2539, guest PC 0x0c05db84 */
if(!s->budget--) { s->failed_pc=0x0c05db84u; return 0; }
r[5]&=r[3];
goto P_0c05db86;
P_0c05db86: /* original 4e0b, guest PC 0x0c05db86 */
if(!s->budget--) { s->failed_pc=0x0c05db86u; return 0; }
target=r[14];
r[16]=0x0c05db8au;
r[4]=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db8au) { target=s->pc; goto dispatch; }
goto P_0c05db8a;
P_0c05db88: /* original e444, guest PC 0x0c05db88 */
if(!s->budget--) { s->failed_pc=0x0c05db88u; return 0; }
r[4]=0x00000044u;
goto P_0c05db8a;
P_0c05db8a: /* original d321, guest PC 0x0c05db8a */
if(!s->budget--) { s->failed_pc=0x0c05db8au; return 0; }
r[3]=read(ram,0x0c05dc10u,4);
goto P_0c05db8c;
P_0c05db8c: /* original 6032, guest PC 0x0c05db8c */
if(!s->budget--) { s->failed_pc=0x0c05db8cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05db8e;
P_0c05db8e: /* original cb08, guest PC 0x0c05db8e */
if(!s->budget--) { s->failed_pc=0x0c05db8eu; return 0; }
r[0]|=8u;
goto P_0c05db90;
P_0c05db90: /* original 942a, guest PC 0x0c05db90 */
if(!s->budget--) { s->failed_pc=0x0c05db90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe8u,2);
goto P_0c05db92;
P_0c05db92: /* original 4e0b, guest PC 0x0c05db92 */
if(!s->budget--) { s->failed_pc=0x0c05db92u; return 0; }
target=r[14];
r[16]=0x0c05db96u;
r[5]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05db96u) { target=s->pc; goto dispatch; }
goto P_0c05db96;
P_0c05db94: /* original 6503, guest PC 0x0c05db94 */
if(!s->budget--) { s->failed_pc=0x0c05db94u; return 0; }
r[5]=r[0];
goto P_0c05db96;
P_0c05db96: /* original 4f26, guest PC 0x0c05db96 */
if(!s->budget--) { s->failed_pc=0x0c05db96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05db98;
P_0c05db98: /* original 000b, guest PC 0x0c05db98 */
if(!s->budget--) { s->failed_pc=0x0c05db98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05db9a: /* original 6ef6, guest PC 0x0c05db9a */
if(!s->budget--) { s->failed_pc=0x0c05db9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05db9cu,s,ram);
P_0c05e1ee: /* original 4f22, guest PC 0x0c05e1ee */
if(!s->budget--) { s->failed_pc=0x0c05e1eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1f0;
P_0c05e1f0: /* original ff08, guest PC 0x0c05e1f0 */
if(!s->budget--) { s->failed_pc=0x0c05e1f0u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c05e1f2;
P_0c05e1f2: /* original 9045, guest PC 0x0c05e1f2 */
if(!s->budget--) { s->failed_pc=0x0c05e1f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e280u,2);
goto P_0c05e1f4;
P_0c05e1f4: /* original f3a6, guest PC 0x0c05e1f4 */
if(!s->budget--) { s->failed_pc=0x0c05e1f4u; return 0; }
vf3_matrix_load(s,ram,3,r[10]+r[0]);
goto P_0c05e1f6;
P_0c05e1f6: /* original f23c, guest PC 0x0c05e1f6 */
if(!s->budget--) { s->failed_pc=0x0c05e1f6u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c05e1f8;
P_0c05e1f8: /* original f2f2, guest PC 0x0c05e1f8 */
if(!s->budget--) { s->failed_pc=0x0c05e1f8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c05e1fa;
P_0c05e1fa: /* original f23d, guest PC 0x0c05e1fa */
if(!s->budget--) { s->failed_pc=0x0c05e1fau; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c05e1fc;
P_0c05e1fc: /* original 0d5a, guest PC 0x0c05e1fc */
if(!s->budget--) { s->failed_pc=0x0c05e1fcu; return 0; }
r[13]=r[53];
goto P_0c05e1fe;
P_0c05e1fe: /* original 2dc9, guest PC 0x0c05e1fe */
if(!s->budget--) { s->failed_pc=0x0c05e1feu; return 0; }
r[13]&=r[12];
goto P_0c05e200;
P_0c05e200: /* original 7eff, guest PC 0x0c05e200 */
if(!s->budget--) { s->failed_pc=0x0c05e200u; return 0; }
r[14]+=0xffffffffu;
goto P_0c05e202;
P_0c05e202: /* original 64d3, guest PC 0x0c05e202 */
if(!s->budget--) { s->failed_pc=0x0c05e202u; return 0; }
r[4]=r[13];
goto P_0c05e204;
P_0c05e204: /* original 60e3, guest PC 0x0c05e204 */
if(!s->budget--) { s->failed_pc=0x0c05e204u; return 0; }
r[0]=r[14];
goto P_0c05e206;
P_0c05e206: /* original 0009, guest PC 0x0c05e206 */
if(!s->budget--) { s->failed_pc=0x0c05e206u; return 0; }
goto P_0c05e208;
P_0c05e208: /* original 4008, guest PC 0x0c05e208 */
if(!s->budget--) { s->failed_pc=0x0c05e208u; return 0; }
r[0]<<=2;
goto P_0c05e20a;
P_0c05e20a: /* original f2a6, guest PC 0x0c05e20a */
if(!s->budget--) { s->failed_pc=0x0c05e20au; return 0; }
vf3_matrix_load(s,ram,2,r[10]+r[0]);
goto P_0c05e20c;
P_0c05e20c: /* original f2f2, guest PC 0x0c05e20c */
if(!s->budget--) { s->failed_pc=0x0c05e20cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c05e20e;
P_0c05e20e: /* original f23d, guest PC 0x0c05e20e */
if(!s->budget--) { s->failed_pc=0x0c05e20eu; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c05e210;
P_0c05e210: /* original 0d5a, guest PC 0x0c05e210 */
if(!s->budget--) { s->failed_pc=0x0c05e210u; return 0; }
r[13]=r[53];
goto P_0c05e212;
P_0c05e212: /* original 2dc9, guest PC 0x0c05e212 */
if(!s->budget--) { s->failed_pc=0x0c05e212u; return 0; }
r[13]&=r[12];
goto P_0c05e214;
P_0c05e214: /* original 65d3, guest PC 0x0c05e214 */
if(!s->budget--) { s->failed_pc=0x0c05e214u; return 0; }
r[5]=r[13];
goto P_0c05e216;
P_0c05e216: /* original 4518, guest PC 0x0c05e216 */
if(!s->budget--) { s->failed_pc=0x0c05e216u; return 0; }
r[5]<<=8;
goto P_0c05e218;
P_0c05e218: /* original 254b, guest PC 0x0c05e218 */
if(!s->budget--) { s->failed_pc=0x0c05e218u; return 0; }
r[5]|=r[4];
goto P_0c05e21a;
P_0c05e21a: /* original 655d, guest PC 0x0c05e21a */
if(!s->budget--) { s->failed_pc=0x0c05e21au; return 0; }
r[5]=r[5]&65535u;
goto P_0c05e21c;
P_0c05e21c: /* original 64e3, guest PC 0x0c05e21c */
if(!s->budget--) { s->failed_pc=0x0c05e21cu; return 0; }
r[4]=r[14];
goto P_0c05e21e;
P_0c05e21e: /* original 4408, guest PC 0x0c05e21e */
if(!s->budget--) { s->failed_pc=0x0c05e21eu; return 0; }
r[4]<<=2;
goto P_0c05e220;
P_0c05e220: /* original 490b, guest PC 0x0c05e220 */
if(!s->budget--) { s->failed_pc=0x0c05e220u; return 0; }
target=r[9];
r[16]=0x0c05e224u;
r[4]+=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e224u) { target=s->pc; goto dispatch; }
goto P_0c05e224;
P_0c05e222: /* original 34bc, guest PC 0x0c05e222 */
if(!s->budget--) { s->failed_pc=0x0c05e222u; return 0; }
r[4]+=r[11];
goto P_0c05e224;
P_0c05e224: /* original 2ee8, guest PC 0x0c05e224 */
if(!s->budget--) { s->failed_pc=0x0c05e224u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c05e226;
P_0c05e226: /* original 8beb, guest PC 0x0c05e226 */
if(!s->budget--) { s->failed_pc=0x0c05e226u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e200; }
goto P_0c05e228;
P_0c05e228: /* original 4f26, guest PC 0x0c05e228 */
if(!s->budget--) { s->failed_pc=0x0c05e228u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e22a;
P_0c05e22a: /* original e000, guest PC 0x0c05e22a */
if(!s->budget--) { s->failed_pc=0x0c05e22au; return 0; }
r[0]=0x00000000u;
goto P_0c05e22c;
P_0c05e22c: /* original fff9, guest PC 0x0c05e22c */
if(!s->budget--) { s->failed_pc=0x0c05e22cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c05e22e;
P_0c05e22e: /* original 69f6, guest PC 0x0c05e22e */
if(!s->budget--) { s->failed_pc=0x0c05e22eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05e230;
P_0c05e230: /* original 6af6, guest PC 0x0c05e230 */
if(!s->budget--) { s->failed_pc=0x0c05e230u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05e232;
P_0c05e232: /* original 6bf6, guest PC 0x0c05e232 */
if(!s->budget--) { s->failed_pc=0x0c05e232u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05e234;
P_0c05e234: /* original 6cf6, guest PC 0x0c05e234 */
if(!s->budget--) { s->failed_pc=0x0c05e234u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05e236;
P_0c05e236: /* original 6df6, guest PC 0x0c05e236 */
if(!s->budget--) { s->failed_pc=0x0c05e236u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05e238;
P_0c05e238: /* original 000b, guest PC 0x0c05e238 */
if(!s->budget--) { s->failed_pc=0x0c05e238u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e23a: /* original 6ef6, guest PC 0x0c05e23a */
if(!s->budget--) { s->failed_pc=0x0c05e23au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05e23cu,s,ram);
P_0c05e342: /* original c731, guest PC 0x0c05e342 */
if(!s->budget--) { s->failed_pc=0x0c05e342u; return 0; }
r[0]=0x0c05e408u;
goto P_0c05e344;
P_0c05e344: /* original d131, guest PC 0x0c05e344 */
if(!s->budget--) { s->failed_pc=0x0c05e344u; return 0; }
r[1]=read(ram,0x0c05e40cu,4);
goto P_0c05e346;
P_0c05e346: /* original f408, guest PC 0x0c05e346 */
if(!s->budget--) { s->failed_pc=0x0c05e346u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c05e348;
P_0c05e348: /* original e070, guest PC 0x0c05e348 */
if(!s->budget--) { s->failed_pc=0x0c05e348u; return 0; }
r[0]=0x00000070u;
goto P_0c05e34a;
P_0c05e34a: /* original f346, guest PC 0x0c05e34a */
if(!s->budget--) { s->failed_pc=0x0c05e34au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e34c;
P_0c05e34c: /* original f342, guest PC 0x0c05e34c */
if(!s->budget--) { s->failed_pc=0x0c05e34cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e34e;
P_0c05e34e: /* original e074, guest PC 0x0c05e34e */
if(!s->budget--) { s->failed_pc=0x0c05e34eu; return 0; }
r[0]=0x00000074u;
goto P_0c05e350;
P_0c05e350: /* original f33d, guest PC 0x0c05e350 */
if(!s->budget--) { s->failed_pc=0x0c05e350u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e352;
P_0c05e352: /* original 035a, guest PC 0x0c05e352 */
if(!s->budget--) { s->failed_pc=0x0c05e352u; return 0; }
r[3]=r[53];
goto P_0c05e354;
P_0c05e354: /* original f346, guest PC 0x0c05e354 */
if(!s->budget--) { s->failed_pc=0x0c05e354u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e356;
P_0c05e356: /* original 4328, guest PC 0x0c05e356 */
if(!s->budget--) { s->failed_pc=0x0c05e356u; return 0; }
r[3]<<=16;
goto P_0c05e358;
P_0c05e358: /* original 4318, guest PC 0x0c05e358 */
if(!s->budget--) { s->failed_pc=0x0c05e358u; return 0; }
r[3]<<=8;
goto P_0c05e35a;
P_0c05e35a: /* original f342, guest PC 0x0c05e35a */
if(!s->budget--) { s->failed_pc=0x0c05e35au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e35c;
P_0c05e35c: /* original f33d, guest PC 0x0c05e35c */
if(!s->budget--) { s->failed_pc=0x0c05e35cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e35e;
P_0c05e35e: /* original e078, guest PC 0x0c05e35e */
if(!s->budget--) { s->failed_pc=0x0c05e35eu; return 0; }
r[0]=0x00000078u;
goto P_0c05e360;
P_0c05e360: /* original f346, guest PC 0x0c05e360 */
if(!s->budget--) { s->failed_pc=0x0c05e360u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e362;
P_0c05e362: /* original 025a, guest PC 0x0c05e362 */
if(!s->budget--) { s->failed_pc=0x0c05e362u; return 0; }
r[2]=r[53];
goto P_0c05e364;
P_0c05e364: /* original 4228, guest PC 0x0c05e364 */
if(!s->budget--) { s->failed_pc=0x0c05e364u; return 0; }
r[2]<<=16;
goto P_0c05e366;
P_0c05e366: /* original 232b, guest PC 0x0c05e366 */
if(!s->budget--) { s->failed_pc=0x0c05e366u; return 0; }
r[3]|=r[2];
goto P_0c05e368;
P_0c05e368: /* original f342, guest PC 0x0c05e368 */
if(!s->budget--) { s->failed_pc=0x0c05e368u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e36a;
P_0c05e36a: /* original e07c, guest PC 0x0c05e36a */
if(!s->budget--) { s->failed_pc=0x0c05e36au; return 0; }
r[0]=0x0000007cu;
goto P_0c05e36c;
P_0c05e36c: /* original f33d, guest PC 0x0c05e36c */
if(!s->budget--) { s->failed_pc=0x0c05e36cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e36e;
P_0c05e36e: /* original 025a, guest PC 0x0c05e36e */
if(!s->budget--) { s->failed_pc=0x0c05e36eu; return 0; }
r[2]=r[53];
goto P_0c05e370;
P_0c05e370: /* original f346, guest PC 0x0c05e370 */
if(!s->budget--) { s->failed_pc=0x0c05e370u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e372;
P_0c05e372: /* original 4218, guest PC 0x0c05e372 */
if(!s->budget--) { s->failed_pc=0x0c05e372u; return 0; }
r[2]<<=8;
goto P_0c05e374;
P_0c05e374: /* original 232b, guest PC 0x0c05e374 */
if(!s->budget--) { s->failed_pc=0x0c05e374u; return 0; }
r[3]|=r[2];
goto P_0c05e376;
P_0c05e376: /* original f342, guest PC 0x0c05e376 */
if(!s->budget--) { s->failed_pc=0x0c05e376u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e378;
P_0c05e378: /* original f33d, guest PC 0x0c05e378 */
if(!s->budget--) { s->failed_pc=0x0c05e378u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e37a;
P_0c05e37a: /* original 025a, guest PC 0x0c05e37a */
if(!s->budget--) { s->failed_pc=0x0c05e37au; return 0; }
r[2]=r[53];
goto P_0c05e37c;
P_0c05e37c: /* original 232b, guest PC 0x0c05e37c */
if(!s->budget--) { s->failed_pc=0x0c05e37cu; return 0; }
r[3]|=r[2];
goto P_0c05e37e;
P_0c05e37e: /* original 2132, guest PC 0x0c05e37e */
if(!s->budget--) { s->failed_pc=0x0c05e37eu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05e380;
P_0c05e380: /* original 7004, guest PC 0x0c05e380 */
if(!s->budget--) { s->failed_pc=0x0c05e380u; return 0; }
r[0]+=0x00000004u;
goto P_0c05e382;
P_0c05e382: /* original f346, guest PC 0x0c05e382 */
if(!s->budget--) { s->failed_pc=0x0c05e382u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e384;
P_0c05e384: /* original f342, guest PC 0x0c05e384 */
if(!s->budget--) { s->failed_pc=0x0c05e384u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e386;
P_0c05e386: /* original 7004, guest PC 0x0c05e386 */
if(!s->budget--) { s->failed_pc=0x0c05e386u; return 0; }
r[0]+=0x00000004u;
goto P_0c05e388;
P_0c05e388: /* original f33d, guest PC 0x0c05e388 */
if(!s->budget--) { s->failed_pc=0x0c05e388u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e38a;
P_0c05e38a: /* original 035a, guest PC 0x0c05e38a */
if(!s->budget--) { s->failed_pc=0x0c05e38au; return 0; }
r[3]=r[53];
goto P_0c05e38c;
P_0c05e38c: /* original f346, guest PC 0x0c05e38c */
if(!s->budget--) { s->failed_pc=0x0c05e38cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e38e;
P_0c05e38e: /* original 4328, guest PC 0x0c05e38e */
if(!s->budget--) { s->failed_pc=0x0c05e38eu; return 0; }
r[3]<<=16;
goto P_0c05e390;
P_0c05e390: /* original 4318, guest PC 0x0c05e390 */
if(!s->budget--) { s->failed_pc=0x0c05e390u; return 0; }
r[3]<<=8;
goto P_0c05e392;
P_0c05e392: /* original f342, guest PC 0x0c05e392 */
if(!s->budget--) { s->failed_pc=0x0c05e392u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e394;
P_0c05e394: /* original f33d, guest PC 0x0c05e394 */
if(!s->budget--) { s->failed_pc=0x0c05e394u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e396;
P_0c05e396: /* original 7004, guest PC 0x0c05e396 */
if(!s->budget--) { s->failed_pc=0x0c05e396u; return 0; }
r[0]+=0x00000004u;
goto P_0c05e398;
P_0c05e398: /* original f346, guest PC 0x0c05e398 */
if(!s->budget--) { s->failed_pc=0x0c05e398u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e39a;
P_0c05e39a: /* original 025a, guest PC 0x0c05e39a */
if(!s->budget--) { s->failed_pc=0x0c05e39au; return 0; }
r[2]=r[53];
goto P_0c05e39c;
P_0c05e39c: /* original 4228, guest PC 0x0c05e39c */
if(!s->budget--) { s->failed_pc=0x0c05e39cu; return 0; }
r[2]<<=16;
goto P_0c05e39e;
P_0c05e39e: /* original 232b, guest PC 0x0c05e39e */
if(!s->budget--) { s->failed_pc=0x0c05e39eu; return 0; }
r[3]|=r[2];
goto P_0c05e3a0;
P_0c05e3a0: /* original f342, guest PC 0x0c05e3a0 */
if(!s->budget--) { s->failed_pc=0x0c05e3a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e3a2;
P_0c05e3a2: /* original 7004, guest PC 0x0c05e3a2 */
if(!s->budget--) { s->failed_pc=0x0c05e3a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c05e3a4;
P_0c05e3a4: /* original f33d, guest PC 0x0c05e3a4 */
if(!s->budget--) { s->failed_pc=0x0c05e3a4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e3a6;
P_0c05e3a6: /* original 025a, guest PC 0x0c05e3a6 */
if(!s->budget--) { s->failed_pc=0x0c05e3a6u; return 0; }
r[2]=r[53];
goto P_0c05e3a8;
P_0c05e3a8: /* original f346, guest PC 0x0c05e3a8 */
if(!s->budget--) { s->failed_pc=0x0c05e3a8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05e3aa;
P_0c05e3aa: /* original 4218, guest PC 0x0c05e3aa */
if(!s->budget--) { s->failed_pc=0x0c05e3aau; return 0; }
r[2]<<=8;
goto P_0c05e3ac;
P_0c05e3ac: /* original d018, guest PC 0x0c05e3ac */
if(!s->budget--) { s->failed_pc=0x0c05e3acu; return 0; }
r[0]=read(ram,0x0c05e410u,4);
goto P_0c05e3ae;
P_0c05e3ae: /* original f342, guest PC 0x0c05e3ae */
if(!s->budget--) { s->failed_pc=0x0c05e3aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05e3b0;
P_0c05e3b0: /* original 232b, guest PC 0x0c05e3b0 */
if(!s->budget--) { s->failed_pc=0x0c05e3b0u; return 0; }
r[3]|=r[2];
goto P_0c05e3b2;
P_0c05e3b2: /* original f33d, guest PC 0x0c05e3b2 */
if(!s->budget--) { s->failed_pc=0x0c05e3b2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05e3b4;
P_0c05e3b4: /* original 025a, guest PC 0x0c05e3b4 */
if(!s->budget--) { s->failed_pc=0x0c05e3b4u; return 0; }
r[2]=r[53];
goto P_0c05e3b6;
P_0c05e3b6: /* original 232b, guest PC 0x0c05e3b6 */
if(!s->budget--) { s->failed_pc=0x0c05e3b6u; return 0; }
r[3]|=r[2];
goto P_0c05e3b8;
P_0c05e3b8: /* original 2032, guest PC 0x0c05e3b8 */
if(!s->budget--) { s->failed_pc=0x0c05e3b8u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c05e3ba;
P_0c05e3ba: /* original 9021, guest PC 0x0c05e3ba */
if(!s->budget--) { s->failed_pc=0x0c05e3bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e400u,2);
goto P_0c05e3bc;
P_0c05e3bc: /* original d315, guest PC 0x0c05e3bc */
if(!s->budget--) { s->failed_pc=0x0c05e3bcu; return 0; }
r[3]=read(ram,0x0c05e414u,4);
goto P_0c05e3be;
P_0c05e3be: /* original 024e, guest PC 0x0c05e3be */
if(!s->budget--) { s->failed_pc=0x0c05e3beu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c05e3c0;
P_0c05e3c0: /* original 2322, guest PC 0x0c05e3c0 */
if(!s->budget--) { s->failed_pc=0x0c05e3c0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05e3c2;
P_0c05e3c2: /* original 7004, guest PC 0x0c05e3c2 */
if(!s->budget--) { s->failed_pc=0x0c05e3c2u; return 0; }
r[0]+=0x00000004u;
goto P_0c05e3c4;
P_0c05e3c4: /* original d214, guest PC 0x0c05e3c4 */
if(!s->budget--) { s->failed_pc=0x0c05e3c4u; return 0; }
r[2]=read(ram,0x0c05e418u,4);
goto P_0c05e3c6;
P_0c05e3c6: /* original 014e, guest PC 0x0c05e3c6 */
if(!s->budget--) { s->failed_pc=0x0c05e3c6u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c05e3c8;
P_0c05e3c8: /* original 2212, guest PC 0x0c05e3c8 */
if(!s->budget--) { s->failed_pc=0x0c05e3c8u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05e3ca;
P_0c05e3ca: /* original 7004, guest PC 0x0c05e3ca */
if(!s->budget--) { s->failed_pc=0x0c05e3cau; return 0; }
r[0]+=0x00000004u;
goto P_0c05e3cc;
P_0c05e3cc: /* original d113, guest PC 0x0c05e3cc */
if(!s->budget--) { s->failed_pc=0x0c05e3ccu; return 0; }
r[1]=read(ram,0x0c05e41cu,4);
goto P_0c05e3ce;
P_0c05e3ce: /* original 034e, guest PC 0x0c05e3ce */
if(!s->budget--) { s->failed_pc=0x0c05e3ceu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05e3d0;
P_0c05e3d0: /* original 2132, guest PC 0x0c05e3d0 */
if(!s->budget--) { s->failed_pc=0x0c05e3d0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05e3d2;
P_0c05e3d2: /* original 000b, guest PC 0x0c05e3d2 */
if(!s->budget--) { s->failed_pc=0x0c05e3d2u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e3d4: /* original e000, guest PC 0x0c05e3d4 */
if(!s->budget--) { s->failed_pc=0x0c05e3d4u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e3d6u,s,ram);
P_0c05ed38: /* original 4f22, guest PC 0x0c05ed38 */
if(!s->budget--) { s->failed_pc=0x0c05ed38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ed3a;
P_0c05ed3a: /* original 7fe8, guest PC 0x0c05ed3a */
if(!s->budget--) { s->failed_pc=0x0c05ed3au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c05ed3c;
P_0c05ed3c: /* original d342, guest PC 0x0c05ed3c */
if(!s->budget--) { s->failed_pc=0x0c05ed3cu; return 0; }
r[3]=read(ram,0x0c05ee48u,4);
goto P_0c05ed3e;
P_0c05ed3e: /* original 67f3, guest PC 0x0c05ed3e */
if(!s->budget--) { s->failed_pc=0x0c05ed3eu; return 0; }
r[7]=r[15];
goto P_0c05ed40;
P_0c05ed40: /* original 1f45, guest PC 0x0c05ed40 */
if(!s->budget--) { s->failed_pc=0x0c05ed40u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c05ed42;
P_0c05ed42: /* original 66f3, guest PC 0x0c05ed42 */
if(!s->budget--) { s->failed_pc=0x0c05ed42u; return 0; }
r[6]=r[15];
goto P_0c05ed44;
P_0c05ed44: /* original 1f54, guest PC 0x0c05ed44 */
if(!s->budget--) { s->failed_pc=0x0c05ed44u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c05ed46;
P_0c05ed46: /* original 770c, guest PC 0x0c05ed46 */
if(!s->budget--) { s->failed_pc=0x0c05ed46u; return 0; }
r[7]+=0x0000000cu;
goto P_0c05ed48;
P_0c05ed48: /* original 7608, guest PC 0x0c05ed48 */
if(!s->budget--) { s->failed_pc=0x0c05ed48u; return 0; }
r[6]+=0x00000008u;
goto P_0c05ed4a;
P_0c05ed4a: /* original 65f3, guest PC 0x0c05ed4a */
if(!s->budget--) { s->failed_pc=0x0c05ed4au; return 0; }
r[5]=r[15];
goto P_0c05ed4c;
P_0c05ed4c: /* original 7504, guest PC 0x0c05ed4c */
if(!s->budget--) { s->failed_pc=0x0c05ed4cu; return 0; }
r[5]+=0x00000004u;
goto P_0c05ed4e;
P_0c05ed4e: /* original 430b, guest PC 0x0c05ed4e */
if(!s->budget--) { s->failed_pc=0x0c05ed4eu; return 0; }
target=r[3];
r[16]=0x0c05ed52u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ed52u) { target=s->pc; goto dispatch; }
goto P_0c05ed52;
P_0c05ed50: /* original 64f3, guest PC 0x0c05ed50 */
if(!s->budget--) { s->failed_pc=0x0c05ed50u; return 0; }
r[4]=r[15];
goto P_0c05ed52;
P_0c05ed52: /* original 6403, guest PC 0x0c05ed52 */
if(!s->budget--) { s->failed_pc=0x0c05ed52u; return 0; }
r[4]=r[0];
goto P_0c05ed54;
P_0c05ed54: /* original 52f5, guest PC 0x0c05ed54 */
if(!s->budget--) { s->failed_pc=0x0c05ed54u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c05ed56;
P_0c05ed56: /* original 53f1, guest PC 0x0c05ed56 */
if(!s->budget--) { s->failed_pc=0x0c05ed56u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05ed58;
P_0c05ed58: /* original 61f2, guest PC 0x0c05ed58 */
if(!s->budget--) { s->failed_pc=0x0c05ed58u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05ed5a;
P_0c05ed5a: /* original 313c, guest PC 0x0c05ed5a */
if(!s->budget--) { s->failed_pc=0x0c05ed5au; return 0; }
r[1]+=r[3];
goto P_0c05ed5c;
P_0c05ed5c: /* original 50f2, guest PC 0x0c05ed5c */
if(!s->budget--) { s->failed_pc=0x0c05ed5cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c05ed5e;
P_0c05ed5e: /* original 310c, guest PC 0x0c05ed5e */
if(!s->budget--) { s->failed_pc=0x0c05ed5eu; return 0; }
r[1]+=r[0];
goto P_0c05ed60;
P_0c05ed60: /* original 2212, guest PC 0x0c05ed60 */
if(!s->budget--) { s->failed_pc=0x0c05ed60u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05ed62;
P_0c05ed62: /* original 53f4, guest PC 0x0c05ed62 */
if(!s->budget--) { s->failed_pc=0x0c05ed62u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c05ed64;
P_0c05ed64: /* original 52f3, guest PC 0x0c05ed64 */
if(!s->budget--) { s->failed_pc=0x0c05ed64u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c05ed66;
P_0c05ed66: /* original 2322, guest PC 0x0c05ed66 */
if(!s->budget--) { s->failed_pc=0x0c05ed66u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05ed68;
P_0c05ed68: /* original 7f18, guest PC 0x0c05ed68 */
if(!s->budget--) { s->failed_pc=0x0c05ed68u; return 0; }
r[15]+=0x00000018u;
goto P_0c05ed6a;
P_0c05ed6a: /* original 4f26, guest PC 0x0c05ed6a */
if(!s->budget--) { s->failed_pc=0x0c05ed6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ed6c;
P_0c05ed6c: /* original 000b, guest PC 0x0c05ed6c */
if(!s->budget--) { s->failed_pc=0x0c05ed6cu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c05ed6e: /* original 6043, guest PC 0x0c05ed6e */
if(!s->budget--) { s->failed_pc=0x0c05ed6eu; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c05ed70u,s,ram);
P_0c060cf2: /* original 000b, guest PC 0x0c060cf2 */
if(!s->budget--) { s->failed_pc=0x0c060cf2u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060cf4: /* original e001, guest PC 0x0c060cf4 */
if(!s->budget--) { s->failed_pc=0x0c060cf4u; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c060cf6u,s,ram);
P_0c060ea6: /* original 0002, guest PC 0x0c060ea6 */
if(!s->budget--) { s->failed_pc=0x0c060ea6u; return 0; }
r[0]=r[17];
goto P_0c060ea8;
P_0c060ea8: /* original 9324, guest PC 0x0c060ea8 */
if(!s->budget--) { s->failed_pc=0x0c060ea8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060ef4u,2);
goto P_0c060eaa;
P_0c060eaa: /* original 4009, guest PC 0x0c060eaa */
if(!s->budget--) { s->failed_pc=0x0c060eaau; return 0; }
r[0]>>=2;
goto P_0c060eac;
P_0c060eac: /* original 4009, guest PC 0x0c060eac */
if(!s->budget--) { s->failed_pc=0x0c060eacu; return 0; }
r[0]>>=2;
goto P_0c060eae;
P_0c060eae: /* original c90f, guest PC 0x0c060eae */
if(!s->budget--) { s->failed_pc=0x0c060eaeu; return 0; }
r[0]&=15u;
goto P_0c060eb0;
P_0c060eb0: /* original 6503, guest PC 0x0c060eb0 */
if(!s->budget--) { s->failed_pc=0x0c060eb0u; return 0; }
r[5]=r[0];
goto P_0c060eb2;
P_0c060eb2: /* original 0002, guest PC 0x0c060eb2 */
if(!s->budget--) { s->failed_pc=0x0c060eb2u; return 0; }
r[0]=r[17];
goto P_0c060eb4;
P_0c060eb4: /* original 2039, guest PC 0x0c060eb4 */
if(!s->budget--) { s->failed_pc=0x0c060eb4u; return 0; }
r[0]&=r[3];
goto P_0c060eb6;
P_0c060eb6: /* original cbf0, guest PC 0x0c060eb6 */
if(!s->budget--) { s->failed_pc=0x0c060eb6u; return 0; }
r[0]|=240u;
goto P_0c060eb8;
P_0c060eb8: /* original 400e, guest PC 0x0c060eb8 */
if(!s->budget--) { s->failed_pc=0x0c060eb8u; return 0; }
r[17]=r[0];
goto P_0c060eba;
P_0c060eba: /* original 0222, guest PC 0x0c060eba */
if(!s->budget--) { s->failed_pc=0x0c060ebau; return 0; }
s->failed_pc=0x0c060ebau; return 0;
goto P_0c060ebc;
P_0c060ebc: /* original 901b, guest PC 0x0c060ebc */
if(!s->budget--) { s->failed_pc=0x0c060ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060ef6u,2);
goto P_0c060ebe;
P_0c060ebe: /* original 0246, guest PC 0x0c060ebe */
if(!s->budget--) { s->failed_pc=0x0c060ebeu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c060ec0;
P_0c060ec0: /* original d60f, guest PC 0x0c060ec0 */
if(!s->budget--) { s->failed_pc=0x0c060ec0u; return 0; }
r[6]=read(ram,0x0c060f00u,4);
goto P_0c060ec2;
P_0c060ec2: /* original e400, guest PC 0x0c060ec2 */
if(!s->budget--) { s->failed_pc=0x0c060ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c060ec4;
P_0c060ec4: /* original 2642, guest PC 0x0c060ec4 */
if(!s->budget--) { s->failed_pc=0x0c060ec4u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c060ec6;
P_0c060ec6: /* original d70f, guest PC 0x0c060ec6 */
if(!s->budget--) { s->failed_pc=0x0c060ec6u; return 0; }
r[7]=read(ram,0x0c060f04u,4);
goto P_0c060ec8;
P_0c060ec8: /* original 2742, guest PC 0x0c060ec8 */
if(!s->budget--) { s->failed_pc=0x0c060ec8u; return 0; }
write(ram,r[7],r[4],4);
goto P_0c060eca;
P_0c060eca: /* original e4ff, guest PC 0x0c060eca */
if(!s->budget--) { s->failed_pc=0x0c060ecau; return 0; }
r[4]=0xffffffffu;
goto P_0c060ecc;
P_0c060ecc: /* original d30e, guest PC 0x0c060ecc */
if(!s->budget--) { s->failed_pc=0x0c060eccu; return 0; }
r[3]=read(ram,0x0c060f08u,4);
goto P_0c060ece;
P_0c060ece: /* original 2342, guest PC 0x0c060ece */
if(!s->budget--) { s->failed_pc=0x0c060eceu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c060ed0;
P_0c060ed0: /* original d20e, guest PC 0x0c060ed0 */
if(!s->budget--) { s->failed_pc=0x0c060ed0u; return 0; }
r[2]=read(ram,0x0c060f0cu,4);
goto P_0c060ed2;
P_0c060ed2: /* original 2242, guest PC 0x0c060ed2 */
if(!s->budget--) { s->failed_pc=0x0c060ed2u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c060ed4;
P_0c060ed4: /* original d10e, guest PC 0x0c060ed4 */
if(!s->budget--) { s->failed_pc=0x0c060ed4u; return 0; }
r[1]=read(ram,0x0c060f10u,4);
goto P_0c060ed6;
P_0c060ed6: /* original 2612, guest PC 0x0c060ed6 */
if(!s->budget--) { s->failed_pc=0x0c060ed6u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c060ed8;
P_0c060ed8: /* original e00e, guest PC 0x0c060ed8 */
if(!s->budget--) { s->failed_pc=0x0c060ed8u; return 0; }
r[0]=0x0000000eu;
goto P_0c060eda;
P_0c060eda: /* original 2702, guest PC 0x0c060eda */
if(!s->budget--) { s->failed_pc=0x0c060edau; return 0; }
write(ram,r[7],r[0],4);
goto P_0c060edc;
P_0c060edc: /* original 6053, guest PC 0x0c060edc */
if(!s->budget--) { s->failed_pc=0x0c060edcu; return 0; }
r[0]=r[5];
goto P_0c060ede;
P_0c060ede: /* original 0009, guest PC 0x0c060ede */
if(!s->budget--) { s->failed_pc=0x0c060edeu; return 0; }
goto P_0c060ee0;
P_0c060ee0: /* original c90f, guest PC 0x0c060ee0 */
if(!s->budget--) { s->failed_pc=0x0c060ee0u; return 0; }
r[0]&=15u;
goto P_0c060ee2;
P_0c060ee2: /* original 4008, guest PC 0x0c060ee2 */
if(!s->budget--) { s->failed_pc=0x0c060ee2u; return 0; }
r[0]<<=2;
goto P_0c060ee4;
P_0c060ee4: /* original 9306, guest PC 0x0c060ee4 */
if(!s->budget--) { s->failed_pc=0x0c060ee4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060ef4u,2);
goto P_0c060ee6;
P_0c060ee6: /* original 4008, guest PC 0x0c060ee6 */
if(!s->budget--) { s->failed_pc=0x0c060ee6u; return 0; }
r[0]<<=2;
goto P_0c060ee8;
P_0c060ee8: /* original 0102, guest PC 0x0c060ee8 */
if(!s->budget--) { s->failed_pc=0x0c060ee8u; return 0; }
r[1]=r[17];
goto P_0c060eea;
P_0c060eea: /* original 2139, guest PC 0x0c060eea */
if(!s->budget--) { s->failed_pc=0x0c060eeau; return 0; }
r[1]&=r[3];
goto P_0c060eec;
P_0c060eec: /* original 201b, guest PC 0x0c060eec */
if(!s->budget--) { s->failed_pc=0x0c060eecu; return 0; }
r[0]|=r[1];
goto P_0c060eee;
P_0c060eee: /* original 400e, guest PC 0x0c060eee */
if(!s->budget--) { s->failed_pc=0x0c060eeeu; return 0; }
r[17]=r[0];
goto P_0c060ef0;
P_0c060ef0: /* original 000b, guest PC 0x0c060ef0 */
if(!s->budget--) { s->failed_pc=0x0c060ef0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c060ef2: /* original 0009, guest PC 0x0c060ef2 */
if(!s->budget--) { s->failed_pc=0x0c060ef2u; return 0; }
return vf3_matrix_family(0x0c060ef4u,s,ram);
P_0c0612fc: /* original 4f22, guest PC 0x0c0612fc */
if(!s->budget--) { s->failed_pc=0x0c0612fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0612fe;
P_0c0612fe: /* original 7ff0, guest PC 0x0c0612fe */
if(!s->budget--) { s->failed_pc=0x0c0612feu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c061300;
P_0c061300: /* original d32c, guest PC 0x0c061300 */
if(!s->budget--) { s->failed_pc=0x0c061300u; return 0; }
r[3]=read(ram,0x0c0613b4u,4);
goto P_0c061302;
P_0c061302: /* original 1f42, guest PC 0x0c061302 */
if(!s->budget--) { s->failed_pc=0x0c061302u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c061304;
P_0c061304: /* original 1f53, guest PC 0x0c061304 */
if(!s->budget--) { s->failed_pc=0x0c061304u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c061306;
P_0c061306: /* original 6032, guest PC 0x0c061306 */
if(!s->budget--) { s->failed_pc=0x0c061306u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c061308;
P_0c061308: /* original c804, guest PC 0x0c061308 */
if(!s->budget--) { s->failed_pc=0x0c061308u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c06130a;
P_0c06130a: /* original 890d, guest PC 0x0c06130a */
if(!s->budget--) { s->failed_pc=0x0c06130au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061328; }
goto P_0c06130c;
P_0c06130c: /* original 65f3, guest PC 0x0c06130c */
if(!s->budget--) { s->failed_pc=0x0c06130cu; return 0; }
r[5]=r[15];
goto P_0c06130e;
P_0c06130e: /* original 7504, guest PC 0x0c06130e */
if(!s->budget--) { s->failed_pc=0x0c06130eu; return 0; }
r[5]+=0x00000004u;
goto P_0c061310;
P_0c061310: /* original b2fe, guest PC 0x0c061310 */
if(!s->budget--) { s->failed_pc=0x0c061310u; return 0; }
target=0x0c061910u; r[16]=0x0c061314u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061314u) { target=s->pc; goto dispatch; }
goto P_0c061314;
P_0c061312: /* original 64f3, guest PC 0x0c061312 */
if(!s->budget--) { s->failed_pc=0x0c061312u; return 0; }
r[4]=r[15];
goto P_0c061314;
P_0c061314: /* original 53f1, guest PC 0x0c061314 */
if(!s->budget--) { s->failed_pc=0x0c061314u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c061316;
P_0c061316: /* original 62f2, guest PC 0x0c061316 */
if(!s->budget--) { s->failed_pc=0x0c061316u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c061318;
P_0c061318: /* original 3233, guest PC 0x0c061318 */
if(!s->budget--) { s->failed_pc=0x0c061318u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c06131a;
P_0c06131a: /* original 8b05, guest PC 0x0c06131a */
if(!s->budget--) { s->failed_pc=0x0c06131au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061328; }
goto P_0c06131c;
P_0c06131c: /* original 56f3, guest PC 0x0c06131c */
if(!s->budget--) { s->failed_pc=0x0c06131cu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c06131e;
P_0c06131e: /* original 55f2, guest PC 0x0c06131e */
if(!s->budget--) { s->failed_pc=0x0c06131eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c061320;
P_0c061320: /* original b653, guest PC 0x0c061320 */
if(!s->budget--) { s->failed_pc=0x0c061320u; return 0; }
target=0x0c061fcau; r[16]=0x0c061324u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061324u) { target=s->pc; goto dispatch; }
goto P_0c061324;
P_0c061322: /* original e400, guest PC 0x0c061322 */
if(!s->budget--) { s->failed_pc=0x0c061322u; return 0; }
r[4]=0x00000000u;
goto P_0c061324;
P_0c061324: /* original a005, guest PC 0x0c061324 */
if(!s->budget--) { s->failed_pc=0x0c061324u; return 0; }
r[4]=r[0];
goto P_0c061332;
P_0c061326: /* original 6403, guest PC 0x0c061326 */
if(!s->budget--) { s->failed_pc=0x0c061326u; return 0; }
r[4]=r[0];
goto P_0c061328;
P_0c061328: /* original 56f3, guest PC 0x0c061328 */
if(!s->budget--) { s->failed_pc=0x0c061328u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c06132a;
P_0c06132a: /* original 55f2, guest PC 0x0c06132a */
if(!s->budget--) { s->failed_pc=0x0c06132au; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c06132c;
P_0c06132c: /* original b64d, guest PC 0x0c06132c */
if(!s->budget--) { s->failed_pc=0x0c06132cu; return 0; }
target=0x0c061fcau; r[16]=0x0c061330u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061330u) { target=s->pc; goto dispatch; }
goto P_0c061330;
P_0c06132e: /* original e401, guest PC 0x0c06132e */
if(!s->budget--) { s->failed_pc=0x0c06132eu; return 0; }
r[4]=0x00000001u;
goto P_0c061330;
P_0c061330: /* original 6403, guest PC 0x0c061330 */
if(!s->budget--) { s->failed_pc=0x0c061330u; return 0; }
r[4]=r[0];
goto P_0c061332;
P_0c061332: /* original 7f10, guest PC 0x0c061332 */
if(!s->budget--) { s->failed_pc=0x0c061332u; return 0; }
r[15]+=0x00000010u;
goto P_0c061334;
P_0c061334: /* original 4f26, guest PC 0x0c061334 */
if(!s->budget--) { s->failed_pc=0x0c061334u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061336;
P_0c061336: /* original 000b, guest PC 0x0c061336 */
if(!s->budget--) { s->failed_pc=0x0c061336u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c061338: /* original 6043, guest PC 0x0c061338 */
if(!s->budget--) { s->failed_pc=0x0c061338u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c06133au,s,ram);
P_0c061644: /* original 4f22, guest PC 0x0c061644 */
if(!s->budget--) { s->failed_pc=0x0c061644u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c061646;
P_0c061646: /* original 7ff8, guest PC 0x0c061646 */
if(!s->budget--) { s->failed_pc=0x0c061646u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c061648;
P_0c061648: /* original d340, guest PC 0x0c061648 */
if(!s->budget--) { s->failed_pc=0x0c061648u; return 0; }
r[3]=read(ram,0x0c06174cu,4);
goto P_0c06164a;
P_0c06164a: /* original 2f42, guest PC 0x0c06164a */
if(!s->budget--) { s->failed_pc=0x0c06164au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06164c;
P_0c06164c: /* original 1f51, guest PC 0x0c06164c */
if(!s->budget--) { s->failed_pc=0x0c06164cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06164e;
P_0c06164e: /* original 430b, guest PC 0x0c06164e */
if(!s->budget--) { s->failed_pc=0x0c06164eu; return 0; }
target=r[3];
r[16]=0x0c061652u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061652u) { target=s->pc; goto dispatch; }
goto P_0c061652;
P_0c061650: /* original 64f2, guest PC 0x0c061650 */
if(!s->budget--) { s->failed_pc=0x0c061650u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c061652;
P_0c061652: /* original 2f02, guest PC 0x0c061652 */
if(!s->budget--) { s->failed_pc=0x0c061652u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c061654;
P_0c061654: /* original bf9f, guest PC 0x0c061654 */
if(!s->budget--) { s->failed_pc=0x0c061654u; return 0; }
target=0x0c061596u; r[16]=0x0c061658u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061658u) { target=s->pc; goto dispatch; }
goto P_0c061658;
P_0c061656: /* original 6403, guest PC 0x0c061656 */
if(!s->budget--) { s->failed_pc=0x0c061656u; return 0; }
r[4]=r[0];
goto P_0c061658;
P_0c061658: /* original 6403, guest PC 0x0c061658 */
if(!s->budget--) { s->failed_pc=0x0c061658u; return 0; }
r[4]=r[0];
goto P_0c06165a;
P_0c06165a: /* original 2448, guest PC 0x0c06165a */
if(!s->budget--) { s->failed_pc=0x0c06165au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06165c;
P_0c06165c: /* original 8906, guest PC 0x0c06165c */
if(!s->budget--) { s->failed_pc=0x0c06165cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06166c; }
goto P_0c06165e;
P_0c06165e: /* original d33b, guest PC 0x0c06165e */
if(!s->budget--) { s->failed_pc=0x0c06165eu; return 0; }
r[3]=read(ram,0x0c06174cu,4);
goto P_0c061660;
P_0c061660: /* original 430b, guest PC 0x0c061660 */
if(!s->budget--) { s->failed_pc=0x0c061660u; return 0; }
target=r[3];
r[16]=0x0c061664u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061664u) { target=s->pc; goto dispatch; }
goto P_0c061664;
P_0c061662: /* original 54f1, guest PC 0x0c061662 */
if(!s->budget--) { s->failed_pc=0x0c061662u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c061664;
P_0c061664: /* original 2f02, guest PC 0x0c061664 */
if(!s->budget--) { s->failed_pc=0x0c061664u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c061666;
P_0c061666: /* original bf96, guest PC 0x0c061666 */
if(!s->budget--) { s->failed_pc=0x0c061666u; return 0; }
target=0x0c061596u; r[16]=0x0c06166au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06166au) { target=s->pc; goto dispatch; }
goto P_0c06166a;
P_0c061668: /* original 6403, guest PC 0x0c061668 */
if(!s->budget--) { s->failed_pc=0x0c061668u; return 0; }
r[4]=r[0];
goto P_0c06166a;
P_0c06166a: /* original 6403, guest PC 0x0c06166a */
if(!s->budget--) { s->failed_pc=0x0c06166au; return 0; }
r[4]=r[0];
goto P_0c06166c;
P_0c06166c: /* original 7f08, guest PC 0x0c06166c */
if(!s->budget--) { s->failed_pc=0x0c06166cu; return 0; }
r[15]+=0x00000008u;
goto P_0c06166e;
P_0c06166e: /* original 4f26, guest PC 0x0c06166e */
if(!s->budget--) { s->failed_pc=0x0c06166eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061670;
P_0c061670: /* original 000b, guest PC 0x0c061670 */
if(!s->budget--) { s->failed_pc=0x0c061670u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c061672: /* original 6043, guest PC 0x0c061672 */
if(!s->budget--) { s->failed_pc=0x0c061672u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c061674u,s,ram);
P_0c061764: /* original 2fe6, guest PC 0x0c061764 */
if(!s->budget--) { s->failed_pc=0x0c061764u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c061766;
P_0c061766: /* original e300, guest PC 0x0c061766 */
if(!s->budget--) { s->failed_pc=0x0c061766u; return 0; }
r[3]=0x00000000u;
goto P_0c061768;
P_0c061768: /* original 2fd6, guest PC 0x0c061768 */
if(!s->budget--) { s->failed_pc=0x0c061768u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06176a;
P_0c06176a: /* original 6233, guest PC 0x0c06176a */
if(!s->budget--) { s->failed_pc=0x0c06176au; return 0; }
r[2]=r[3];
goto P_0c06176c;
P_0c06176c: /* original 2fc6, guest PC 0x0c06176c */
if(!s->budget--) { s->failed_pc=0x0c06176cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06176e;
P_0c06176e: /* original 2fb6, guest PC 0x0c06176e */
if(!s->budget--) { s->failed_pc=0x0c06176eu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c061770;
P_0c061770: /* original 2fa6, guest PC 0x0c061770 */
if(!s->budget--) { s->failed_pc=0x0c061770u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c061772;
P_0c061772: /* original 6b33, guest PC 0x0c061772 */
if(!s->budget--) { s->failed_pc=0x0c061772u; return 0; }
r[11]=r[3];
goto P_0c061774;
P_0c061774: /* original dc34, guest PC 0x0c061774 */
if(!s->budget--) { s->failed_pc=0x0c061774u; return 0; }
r[12]=read(ram,0x0c061848u,4);
goto P_0c061776;
P_0c061776: /* original 6a33, guest PC 0x0c061776 */
if(!s->budget--) { s->failed_pc=0x0c061776u; return 0; }
r[10]=r[3];
goto P_0c061778;
P_0c061778: /* original 2f86, guest PC 0x0c061778 */
if(!s->budget--) { s->failed_pc=0x0c061778u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c06177a;
P_0c06177a: /* original 7fe8, guest PC 0x0c06177a */
if(!s->budget--) { s->failed_pc=0x0c06177au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c06177c;
P_0c06177c: /* original 1f31, guest PC 0x0c06177c */
if(!s->budget--) { s->failed_pc=0x0c06177cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06177e;
P_0c06177e: /* original 1f33, guest PC 0x0c06177e */
if(!s->budget--) { s->failed_pc=0x0c06177eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c061780;
P_0c061780: /* original 2f32, guest PC 0x0c061780 */
if(!s->budget--) { s->failed_pc=0x0c061780u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c061782;
P_0c061782: /* original 1f32, guest PC 0x0c061782 */
if(!s->budget--) { s->failed_pc=0x0c061782u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c061784;
P_0c061784: /* original 1f24, guest PC 0x0c061784 */
if(!s->budget--) { s->failed_pc=0x0c061784u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c061786;
P_0c061786: /* original 5ec2, guest PC 0x0c061786 */
if(!s->budget--) { s->failed_pc=0x0c061786u; return 0; }
r[14]=read(ram,r[12]+8,4);
goto P_0c061788;
P_0c061788: /* original 2ee8, guest PC 0x0c061788 */
if(!s->budget--) { s->failed_pc=0x0c061788u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06178a;
P_0c06178a: /* original 890a, guest PC 0x0c06178a */
if(!s->budget--) { s->failed_pc=0x0c06178au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0617a2; }
goto P_0c06178c;
P_0c06178c: /* original 52e4, guest PC 0x0c06178c */
if(!s->budget--) { s->failed_pc=0x0c06178cu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c06178e;
P_0c06178e: /* original 32b7, guest PC 0x0c06178e */
if(!s->budget--) { s->failed_pc=0x0c06178eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c061790;
P_0c061790: /* original 8b00, guest PC 0x0c061790 */
if(!s->budget--) { s->failed_pc=0x0c061790u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061794; }
goto P_0c061792;
P_0c061792: /* original 5be4, guest PC 0x0c061792 */
if(!s->budget--) { s->failed_pc=0x0c061792u; return 0; }
r[11]=read(ram,r[14]+16,4);
goto P_0c061794;
P_0c061794: /* original 53e4, guest PC 0x0c061794 */
if(!s->budget--) { s->failed_pc=0x0c061794u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c061796;
P_0c061796: /* original 52f2, guest PC 0x0c061796 */
if(!s->budget--) { s->failed_pc=0x0c061796u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c061798;
P_0c061798: /* original 323c, guest PC 0x0c061798 */
if(!s->budget--) { s->failed_pc=0x0c061798u; return 0; }
r[2]+=r[3];
goto P_0c06179a;
P_0c06179a: /* original 1f22, guest PC 0x0c06179a */
if(!s->budget--) { s->failed_pc=0x0c06179au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c06179c;
P_0c06179c: /* original 5ee2, guest PC 0x0c06179c */
if(!s->budget--) { s->failed_pc=0x0c06179cu; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c06179e;
P_0c06179e: /* original 2ee8, guest PC 0x0c06179e */
if(!s->budget--) { s->failed_pc=0x0c06179eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617a0;
P_0c0617a0: /* original 8bf4, guest PC 0x0c0617a0 */
if(!s->budget--) { s->failed_pc=0x0c0617a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06178c; }
goto P_0c0617a2;
P_0c0617a2: /* original 6ec2, guest PC 0x0c0617a2 */
if(!s->budget--) { s->failed_pc=0x0c0617a2u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c0617a4;
P_0c0617a4: /* original 2ee8, guest PC 0x0c0617a4 */
if(!s->budget--) { s->failed_pc=0x0c0617a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617a6;
P_0c0617a6: /* original 8d0f, guest PC 0x0c0617a6 */
if(!s->budget--) { s->failed_pc=0x0c0617a6u; return 0; }
cond=r[17]&1u;
r[13]=0x00000004u;
if(cond) { goto P_0c0617c8; }
goto P_0c0617aa;
P_0c0617a8: /* original ed04, guest PC 0x0c0617a8 */
if(!s->budget--) { s->failed_pc=0x0c0617a8u; return 0; }
r[13]=0x00000004u;
goto P_0c0617aa;
P_0c0617aa: /* original 63e1, guest PC 0x0c0617aa */
if(!s->budget--) { s->failed_pc=0x0c0617aau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0617ac;
P_0c0617ac: /* original 633d, guest PC 0x0c0617ac */
if(!s->budget--) { s->failed_pc=0x0c0617acu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0617ae;
P_0c0617ae: /* original 23d8, guest PC 0x0c0617ae */
if(!s->budget--) { s->failed_pc=0x0c0617aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0617b0;
P_0c0617b0: /* original 8b07, guest PC 0x0c0617b0 */
if(!s->budget--) { s->failed_pc=0x0c0617b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617c2; }
goto P_0c0617b2;
P_0c0617b2: /* original 51e4, guest PC 0x0c0617b2 */
if(!s->budget--) { s->failed_pc=0x0c0617b2u; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c0617b4;
P_0c0617b4: /* original 31b7, guest PC 0x0c0617b4 */
if(!s->budget--) { s->failed_pc=0x0c0617b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[11])!=0);
goto P_0c0617b6;
P_0c0617b6: /* original 8b00, guest PC 0x0c0617b6 */
if(!s->budget--) { s->failed_pc=0x0c0617b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617ba; }
goto P_0c0617b8;
P_0c0617b8: /* original 5be4, guest PC 0x0c0617b8 */
if(!s->budget--) { s->failed_pc=0x0c0617b8u; return 0; }
r[11]=read(ram,r[14]+16,4);
goto P_0c0617ba;
P_0c0617ba: /* original 53e4, guest PC 0x0c0617ba */
if(!s->budget--) { s->failed_pc=0x0c0617bau; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0617bc;
P_0c0617bc: /* original 52f3, guest PC 0x0c0617bc */
if(!s->budget--) { s->failed_pc=0x0c0617bcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0617be;
P_0c0617be: /* original 323c, guest PC 0x0c0617be */
if(!s->budget--) { s->failed_pc=0x0c0617beu; return 0; }
r[2]+=r[3];
goto P_0c0617c0;
P_0c0617c0: /* original 1f23, guest PC 0x0c0617c0 */
if(!s->budget--) { s->failed_pc=0x0c0617c0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0617c2;
P_0c0617c2: /* original 5ee2, guest PC 0x0c0617c2 */
if(!s->budget--) { s->failed_pc=0x0c0617c2u; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c0617c4;
P_0c0617c4: /* original 2ee8, guest PC 0x0c0617c4 */
if(!s->budget--) { s->failed_pc=0x0c0617c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617c6;
P_0c0617c6: /* original 8bf0, guest PC 0x0c0617c6 */
if(!s->budget--) { s->failed_pc=0x0c0617c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617aa; }
goto P_0c0617c8;
P_0c0617c8: /* original 6ec3, guest PC 0x0c0617c8 */
if(!s->budget--) { s->failed_pc=0x0c0617c8u; return 0; }
r[14]=r[12];
goto P_0c0617ca;
P_0c0617ca: /* original 7e14, guest PC 0x0c0617ca */
if(!s->budget--) { s->failed_pc=0x0c0617cau; return 0; }
r[14]+=0x00000014u;
goto P_0c0617cc;
P_0c0617cc: /* original 1fe5, guest PC 0x0c0617cc */
if(!s->budget--) { s->failed_pc=0x0c0617ccu; return 0; }
write(ram,r[15]+20,r[14],4);
goto P_0c0617ce;
P_0c0617ce: /* original 5ee2, guest PC 0x0c0617ce */
if(!s->budget--) { s->failed_pc=0x0c0617ceu; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c0617d0;
P_0c0617d0: /* original 2ee8, guest PC 0x0c0617d0 */
if(!s->budget--) { s->failed_pc=0x0c0617d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617d2;
P_0c0617d2: /* original 890a, guest PC 0x0c0617d2 */
if(!s->budget--) { s->failed_pc=0x0c0617d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0617ea; }
goto P_0c0617d4;
P_0c0617d4: /* original 52e4, guest PC 0x0c0617d4 */
if(!s->budget--) { s->failed_pc=0x0c0617d4u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0617d6;
P_0c0617d6: /* original 32a7, guest PC 0x0c0617d6 */
if(!s->budget--) { s->failed_pc=0x0c0617d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[10])!=0);
goto P_0c0617d8;
P_0c0617d8: /* original 8b00, guest PC 0x0c0617d8 */
if(!s->budget--) { s->failed_pc=0x0c0617d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617dc; }
goto P_0c0617da;
P_0c0617da: /* original 5ae4, guest PC 0x0c0617da */
if(!s->budget--) { s->failed_pc=0x0c0617dau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0617dc;
P_0c0617dc: /* original 53e4, guest PC 0x0c0617dc */
if(!s->budget--) { s->failed_pc=0x0c0617dcu; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0617de;
P_0c0617de: /* original 62f2, guest PC 0x0c0617de */
if(!s->budget--) { s->failed_pc=0x0c0617deu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0617e0;
P_0c0617e0: /* original 323c, guest PC 0x0c0617e0 */
if(!s->budget--) { s->failed_pc=0x0c0617e0u; return 0; }
r[2]+=r[3];
goto P_0c0617e2;
P_0c0617e2: /* original 2f22, guest PC 0x0c0617e2 */
if(!s->budget--) { s->failed_pc=0x0c0617e2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0617e4;
P_0c0617e4: /* original 5ee2, guest PC 0x0c0617e4 */
if(!s->budget--) { s->failed_pc=0x0c0617e4u; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c0617e6;
P_0c0617e6: /* original 2ee8, guest PC 0x0c0617e6 */
if(!s->budget--) { s->failed_pc=0x0c0617e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617e8;
P_0c0617e8: /* original 8bf4, guest PC 0x0c0617e8 */
if(!s->budget--) { s->failed_pc=0x0c0617e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617d4; }
goto P_0c0617ea;
P_0c0617ea: /* original 5ef5, guest PC 0x0c0617ea */
if(!s->budget--) { s->failed_pc=0x0c0617eau; return 0; }
r[14]=read(ram,r[15]+20,4);
goto P_0c0617ec;
P_0c0617ec: /* original 6ee2, guest PC 0x0c0617ec */
if(!s->budget--) { s->failed_pc=0x0c0617ecu; return 0; }
tmp=read(ram,r[14],4);
r[14]=tmp;
goto P_0c0617ee;
P_0c0617ee: /* original 2ee8, guest PC 0x0c0617ee */
if(!s->budget--) { s->failed_pc=0x0c0617eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0617f0;
P_0c0617f0: /* original 890e, guest PC 0x0c0617f0 */
if(!s->budget--) { s->failed_pc=0x0c0617f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061810; }
goto P_0c0617f2;
P_0c0617f2: /* original 62e1, guest PC 0x0c0617f2 */
if(!s->budget--) { s->failed_pc=0x0c0617f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0617f4;
P_0c0617f4: /* original 622d, guest PC 0x0c0617f4 */
if(!s->budget--) { s->failed_pc=0x0c0617f4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0617f6;
P_0c0617f6: /* original 22d8, guest PC 0x0c0617f6 */
if(!s->budget--) { s->failed_pc=0x0c0617f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0617f8;
P_0c0617f8: /* original 8b07, guest PC 0x0c0617f8 */
if(!s->budget--) { s->failed_pc=0x0c0617f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06180a; }
goto P_0c0617fa;
P_0c0617fa: /* original 51e4, guest PC 0x0c0617fa */
if(!s->budget--) { s->failed_pc=0x0c0617fau; return 0; }
r[1]=read(ram,r[14]+16,4);
goto P_0c0617fc;
P_0c0617fc: /* original 31a7, guest PC 0x0c0617fc */
if(!s->budget--) { s->failed_pc=0x0c0617fcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[10])!=0);
goto P_0c0617fe;
P_0c0617fe: /* original 8b00, guest PC 0x0c0617fe */
if(!s->budget--) { s->failed_pc=0x0c0617feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061802; }
goto P_0c061800;
P_0c061800: /* original 5ae4, guest PC 0x0c061800 */
if(!s->budget--) { s->failed_pc=0x0c061800u; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c061802;
P_0c061802: /* original 53e4, guest PC 0x0c061802 */
if(!s->budget--) { s->failed_pc=0x0c061802u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c061804;
P_0c061804: /* original 52f1, guest PC 0x0c061804 */
if(!s->budget--) { s->failed_pc=0x0c061804u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c061806;
P_0c061806: /* original 323c, guest PC 0x0c061806 */
if(!s->budget--) { s->failed_pc=0x0c061806u; return 0; }
r[2]+=r[3];
goto P_0c061808;
P_0c061808: /* original 1f21, guest PC 0x0c061808 */
if(!s->budget--) { s->failed_pc=0x0c061808u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06180a;
P_0c06180a: /* original 5ee2, guest PC 0x0c06180a */
if(!s->budget--) { s->failed_pc=0x0c06180au; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c06180c;
P_0c06180c: /* original 2ee8, guest PC 0x0c06180c */
if(!s->budget--) { s->failed_pc=0x0c06180cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06180e;
P_0c06180e: /* original 8bf0, guest PC 0x0c06180e */
if(!s->budget--) { s->failed_pc=0x0c06180eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0617f2; }
goto P_0c061810;
P_0c061810: /* original d20e, guest PC 0x0c061810 */
if(!s->budget--) { s->failed_pc=0x0c061810u; return 0; }
r[2]=read(ram,0x0c06184cu,4);
goto P_0c061812;
P_0c061812: /* original 6c22, guest PC 0x0c061812 */
if(!s->budget--) { s->failed_pc=0x0c061812u; return 0; }
tmp=read(ram,r[2],4);
r[12]=tmp;
goto P_0c061814;
P_0c061814: /* original 2cc8, guest PC 0x0c061814 */
if(!s->budget--) { s->failed_pc=0x0c061814u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c061816;
P_0c061816: /* original 8956, guest PC 0x0c061816 */
if(!s->budget--) { s->failed_pc=0x0c061816u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0618c6; }
goto P_0c061818;
P_0c061818: /* original de0d, guest PC 0x0c061818 */
if(!s->budget--) { s->failed_pc=0x0c061818u; return 0; }
r[14]=read(ram,0x0c061850u,4);
goto P_0c06181a;
P_0c06181a: /* original 60c1, guest PC 0x0c06181a */
if(!s->budget--) { s->failed_pc=0x0c06181au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[0]=tmp;
goto P_0c06181c;
P_0c06181c: /* original 910f, guest PC 0x0c06181c */
if(!s->budget--) { s->failed_pc=0x0c06181cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06183eu,2);
goto P_0c06181e;
P_0c06181e: /* original 600d, guest PC 0x0c06181e */
if(!s->budget--) { s->failed_pc=0x0c06181eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c061820;
P_0c061820: /* original 20e9, guest PC 0x0c061820 */
if(!s->budget--) { s->failed_pc=0x0c061820u; return 0; }
r[0]&=r[14];
goto P_0c061822;
P_0c061822: /* original 3010, guest PC 0x0c061822 */
if(!s->budget--) { s->failed_pc=0x0c061822u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061824;
P_0c061824: /* original 8923, guest PC 0x0c061824 */
if(!s->budget--) { s->failed_pc=0x0c061824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06186e; }
goto P_0c061826;
P_0c061826: /* original 910b, guest PC 0x0c061826 */
if(!s->budget--) { s->failed_pc=0x0c061826u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061840u,2);
goto P_0c061828;
P_0c061828: /* original 3010, guest PC 0x0c061828 */
if(!s->budget--) { s->failed_pc=0x0c061828u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c06182a;
P_0c06182a: /* original 8923, guest PC 0x0c06182a */
if(!s->budget--) { s->failed_pc=0x0c06182au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061874; }
goto P_0c06182c;
P_0c06182c: /* original 9109, guest PC 0x0c06182c */
if(!s->budget--) { s->failed_pc=0x0c06182cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061842u,2);
goto P_0c06182e;
P_0c06182e: /* original 3010, guest PC 0x0c06182e */
if(!s->budget--) { s->failed_pc=0x0c06182eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061830;
P_0c061830: /* original 8923, guest PC 0x0c061830 */
if(!s->budget--) { s->failed_pc=0x0c061830u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06187a; }
goto P_0c061832;
P_0c061832: /* original 9107, guest PC 0x0c061832 */
if(!s->budget--) { s->failed_pc=0x0c061832u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061844u,2);
goto P_0c061834;
P_0c061834: /* original 3010, guest PC 0x0c061834 */
if(!s->budget--) { s->failed_pc=0x0c061834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061836;
P_0c061836: /* original 8923, guest PC 0x0c061836 */
if(!s->budget--) { s->failed_pc=0x0c061836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061880; }
goto P_0c061838;
P_0c061838: /* original 9105, guest PC 0x0c061838 */
if(!s->budget--) { s->failed_pc=0x0c061838u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061846u,2);
goto P_0c06183a;
P_0c06183a: /* original a00b, guest PC 0x0c06183a */
if(!s->budget--) { s->failed_pc=0x0c06183au; return 0; }
goto P_0c061854;
P_0c06183c: /* original 0009, guest PC 0x0c06183c */
if(!s->budget--) { s->failed_pc=0x0c06183cu; return 0; }
return vf3_matrix_family(0x0c06183eu,s,ram);
P_0c061854: /* original 3010, guest PC 0x0c061854 */
if(!s->budget--) { s->failed_pc=0x0c061854u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061856;
P_0c061856: /* original 8916, guest PC 0x0c061856 */
if(!s->budget--) { s->failed_pc=0x0c061856u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061886; }
goto P_0c061858;
P_0c061858: /* original 914e, guest PC 0x0c061858 */
if(!s->budget--) { s->failed_pc=0x0c061858u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0618f8u,2);
goto P_0c06185a;
P_0c06185a: /* original 3010, guest PC 0x0c06185a */
if(!s->budget--) { s->failed_pc=0x0c06185au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c06185c;
P_0c06185c: /* original 8916, guest PC 0x0c06185c */
if(!s->budget--) { s->failed_pc=0x0c06185cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06188c; }
goto P_0c06185e;
P_0c06185e: /* original 914c, guest PC 0x0c06185e */
if(!s->budget--) { s->failed_pc=0x0c06185eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0618fau,2);
goto P_0c061860;
P_0c061860: /* original 3010, guest PC 0x0c061860 */
if(!s->budget--) { s->failed_pc=0x0c061860u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061862;
P_0c061862: /* original 8916, guest PC 0x0c061862 */
if(!s->budget--) { s->failed_pc=0x0c061862u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061892; }
goto P_0c061864;
P_0c061864: /* original d129, guest PC 0x0c061864 */
if(!s->budget--) { s->failed_pc=0x0c061864u; return 0; }
r[1]=read(ram,0x0c06190cu,4);
goto P_0c061866;
P_0c061866: /* original 3010, guest PC 0x0c061866 */
if(!s->budget--) { s->failed_pc=0x0c061866u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c061868;
P_0c061868: /* original 8916, guest PC 0x0c061868 */
if(!s->budget--) { s->failed_pc=0x0c061868u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061898; }
goto P_0c06186a;
P_0c06186a: /* original a018, guest PC 0x0c06186a */
if(!s->budget--) { s->failed_pc=0x0c06186au; return 0; }
goto P_0c06189e;
P_0c06186c: /* original 0009, guest PC 0x0c06186c */
if(!s->budget--) { s->failed_pc=0x0c06186cu; return 0; }
goto P_0c06186e;
P_0c06186e: /* original 9e45, guest PC 0x0c06186e */
if(!s->budget--) { s->failed_pc=0x0c06186eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0618fcu,2);
goto P_0c061870;
P_0c061870: /* original a007, guest PC 0x0c061870 */
if(!s->budget--) { s->failed_pc=0x0c061870u; return 0; }
goto P_0c061882;
P_0c061872: /* original 0009, guest PC 0x0c061872 */
if(!s->budget--) { s->failed_pc=0x0c061872u; return 0; }
goto P_0c061874;
P_0c061874: /* original 9e43, guest PC 0x0c061874 */
if(!s->budget--) { s->failed_pc=0x0c061874u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0618feu,2);
goto P_0c061876;
P_0c061876: /* original a004, guest PC 0x0c061876 */
if(!s->budget--) { s->failed_pc=0x0c061876u; return 0; }
goto P_0c061882;
P_0c061878: /* original 0009, guest PC 0x0c061878 */
if(!s->budget--) { s->failed_pc=0x0c061878u; return 0; }
goto P_0c06187a;
P_0c06187a: /* original 9e41, guest PC 0x0c06187a */
if(!s->budget--) { s->failed_pc=0x0c06187au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061900u,2);
goto P_0c06187c;
P_0c06187c: /* original a001, guest PC 0x0c06187c */
if(!s->budget--) { s->failed_pc=0x0c06187cu; return 0; }
goto P_0c061882;
P_0c06187e: /* original 0009, guest PC 0x0c06187e */
if(!s->budget--) { s->failed_pc=0x0c06187eu; return 0; }
goto P_0c061880;
P_0c061880: /* original 9e3f, guest PC 0x0c061880 */
if(!s->budget--) { s->failed_pc=0x0c061880u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061902u,2);
goto P_0c061882;
P_0c061882: /* original a00e, guest PC 0x0c061882 */
if(!s->budget--) { s->failed_pc=0x0c061882u; return 0; }
r[13]=0x00000010u;
goto P_0c0618a2;
P_0c061884: /* original ed10, guest PC 0x0c061884 */
if(!s->budget--) { s->failed_pc=0x0c061884u; return 0; }
r[13]=0x00000010u;
goto P_0c061886;
P_0c061886: /* original 9e3d, guest PC 0x0c061886 */
if(!s->budget--) { s->failed_pc=0x0c061886u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061904u,2);
goto P_0c061888;
P_0c061888: /* original a00b, guest PC 0x0c061888 */
if(!s->budget--) { s->failed_pc=0x0c061888u; return 0; }
r[13]=0x00000008u;
goto P_0c0618a2;
P_0c06188a: /* original ed08, guest PC 0x0c06188a */
if(!s->budget--) { s->failed_pc=0x0c06188au; return 0; }
r[13]=0x00000008u;
goto P_0c06188c;
P_0c06188c: /* original 9e3b, guest PC 0x0c06188c */
if(!s->budget--) { s->failed_pc=0x0c06188cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061906u,2);
goto P_0c06188e;
P_0c06188e: /* original a008, guest PC 0x0c06188e */
if(!s->budget--) { s->failed_pc=0x0c06188eu; return 0; }
r[13]=0x00000004u;
goto P_0c0618a2;
P_0c061890: /* original ed04, guest PC 0x0c061890 */
if(!s->budget--) { s->failed_pc=0x0c061890u; return 0; }
r[13]=0x00000004u;
goto P_0c061892;
P_0c061892: /* original 9e39, guest PC 0x0c061892 */
if(!s->budget--) { s->failed_pc=0x0c061892u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c061908u,2);
goto P_0c061894;
P_0c061894: /* original a005, guest PC 0x0c061894 */
if(!s->budget--) { s->failed_pc=0x0c061894u; return 0; }
r[13]=0x00000002u;
goto P_0c0618a2;
P_0c061896: /* original ed02, guest PC 0x0c061896 */
if(!s->budget--) { s->failed_pc=0x0c061896u; return 0; }
r[13]=0x00000002u;
goto P_0c061898;
P_0c061898: /* original 9e37, guest PC 0x0c061898 */
if(!s->budget--) { s->failed_pc=0x0c061898u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06190au,2);
goto P_0c06189a;
P_0c06189a: /* original a002, guest PC 0x0c06189a */
if(!s->budget--) { s->failed_pc=0x0c06189au; return 0; }
r[13]=0x00000001u;
goto P_0c0618a2;
P_0c06189c: /* original ed01, guest PC 0x0c06189c */
if(!s->budget--) { s->failed_pc=0x0c06189cu; return 0; }
r[13]=0x00000001u;
goto P_0c06189e;
P_0c06189e: /* original ee00, guest PC 0x0c06189e */
if(!s->budget--) { s->failed_pc=0x0c06189eu; return 0; }
r[14]=0x00000000u;
goto P_0c0618a0;
P_0c0618a0: /* original 6de3, guest PC 0x0c0618a0 */
if(!s->budget--) { s->failed_pc=0x0c0618a0u; return 0; }
r[13]=r[14];
goto P_0c0618a2;
P_0c0618a2: /* original e800, guest PC 0x0c0618a2 */
if(!s->budget--) { s->failed_pc=0x0c0618a2u; return 0; }
r[8]=0x00000000u;
goto P_0c0618a4;
P_0c0618a4: /* original 61c3, guest PC 0x0c0618a4 */
if(!s->budget--) { s->failed_pc=0x0c0618a4u; return 0; }
r[1]=r[12];
goto P_0c0618a6;
P_0c0618a6: /* original 4d15, guest PC 0x0c0618a6 */
if(!s->budget--) { s->failed_pc=0x0c0618a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c0618a8;
P_0c0618a8: /* original 8f0a, guest PC 0x0c0618a8 */
if(!s->budget--) { s->failed_pc=0x0c0618a8u; return 0; }
cond=r[17]&1u;
r[1]+=0x0000000cu;
if(!cond) { goto P_0c0618c0; }
goto P_0c0618ac;
P_0c0618aa: /* original 710c, guest PC 0x0c0618aa */
if(!s->budget--) { s->failed_pc=0x0c0618aau; return 0; }
r[1]+=0x0000000cu;
goto P_0c0618ac;
P_0c0618ac: /* original 6312, guest PC 0x0c0618ac */
if(!s->budget--) { s->failed_pc=0x0c0618acu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0618ae;
P_0c0618ae: /* original 2338, guest PC 0x0c0618ae */
if(!s->budget--) { s->failed_pc=0x0c0618aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0618b0;
P_0c0618b0: /* original 8f03, guest PC 0x0c0618b0 */
if(!s->budget--) { s->failed_pc=0x0c0618b0u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(!cond) { goto P_0c0618ba; }
goto P_0c0618b4;
P_0c0618b2: /* original 7801, guest PC 0x0c0618b2 */
if(!s->budget--) { s->failed_pc=0x0c0618b2u; return 0; }
r[8]+=0x00000001u;
goto P_0c0618b4;
P_0c0618b4: /* original 53f4, guest PC 0x0c0618b4 */
if(!s->budget--) { s->failed_pc=0x0c0618b4u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0618b6;
P_0c0618b6: /* original 33ec, guest PC 0x0c0618b6 */
if(!s->budget--) { s->failed_pc=0x0c0618b6u; return 0; }
r[3]+=r[14];
goto P_0c0618b8;
P_0c0618b8: /* original 1f34, guest PC 0x0c0618b8 */
if(!s->budget--) { s->failed_pc=0x0c0618b8u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0618ba;
P_0c0618ba: /* original 38d3, guest PC 0x0c0618ba */
if(!s->budget--) { s->failed_pc=0x0c0618bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c0618bc;
P_0c0618bc: /* original 8ff6, guest PC 0x0c0618bc */
if(!s->budget--) { s->failed_pc=0x0c0618bcu; return 0; }
cond=r[17]&1u;
r[1]+=0x00000004u;
if(!cond) { goto P_0c0618ac; }
goto P_0c0618c0;
P_0c0618be: /* original 7104, guest PC 0x0c0618be */
if(!s->budget--) { s->failed_pc=0x0c0618beu; return 0; }
r[1]+=0x00000004u;
goto P_0c0618c0;
P_0c0618c0: /* original 5cc1, guest PC 0x0c0618c0 */
if(!s->budget--) { s->failed_pc=0x0c0618c0u; return 0; }
r[12]=read(ram,r[12]+4,4);
goto P_0c0618c2;
P_0c0618c2: /* original 2cc8, guest PC 0x0c0618c2 */
if(!s->budget--) { s->failed_pc=0x0c0618c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0618c4;
P_0c0618c4: /* original 8ba8, guest PC 0x0c0618c4 */
if(!s->budget--) { s->failed_pc=0x0c0618c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061818; }
goto P_0c0618c6;
P_0c0618c6: /* original 3ba3, guest PC 0x0c0618c6 */
if(!s->budget--) { s->failed_pc=0x0c0618c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[10])!=0);
goto P_0c0618c8;
P_0c0618c8: /* original 53f3, guest PC 0x0c0618c8 */
if(!s->budget--) { s->failed_pc=0x0c0618c8u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0618ca;
P_0c0618ca: /* original 52f2, guest PC 0x0c0618ca */
if(!s->budget--) { s->failed_pc=0x0c0618cau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0618cc;
P_0c0618cc: /* original 323c, guest PC 0x0c0618cc */
if(!s->budget--) { s->failed_pc=0x0c0618ccu; return 0; }
r[2]+=r[3];
goto P_0c0618ce;
P_0c0618ce: /* original 2422, guest PC 0x0c0618ce */
if(!s->budget--) { s->failed_pc=0x0c0618ceu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0618d0;
P_0c0618d0: /* original 53f1, guest PC 0x0c0618d0 */
if(!s->budget--) { s->failed_pc=0x0c0618d0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0618d2;
P_0c0618d2: /* original 61f2, guest PC 0x0c0618d2 */
if(!s->budget--) { s->failed_pc=0x0c0618d2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0618d4;
P_0c0618d4: /* original 313c, guest PC 0x0c0618d4 */
if(!s->budget--) { s->failed_pc=0x0c0618d4u; return 0; }
r[1]+=r[3];
goto P_0c0618d6;
P_0c0618d6: /* original 2512, guest PC 0x0c0618d6 */
if(!s->budget--) { s->failed_pc=0x0c0618d6u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c0618d8;
P_0c0618d8: /* original 53f4, guest PC 0x0c0618d8 */
if(!s->budget--) { s->failed_pc=0x0c0618d8u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0618da;
P_0c0618da: /* original 2632, guest PC 0x0c0618da */
if(!s->budget--) { s->failed_pc=0x0c0618dau; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0618dc;
P_0c0618dc: /* original 8901, guest PC 0x0c0618dc */
if(!s->budget--) { s->failed_pc=0x0c0618dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0618e2; }
goto P_0c0618de;
P_0c0618de: /* original a001, guest PC 0x0c0618de */
if(!s->budget--) { s->failed_pc=0x0c0618deu; return 0; }
r[2]=r[10];
goto P_0c0618e4;
P_0c0618e0: /* original 62a3, guest PC 0x0c0618e0 */
if(!s->budget--) { s->failed_pc=0x0c0618e0u; return 0; }
r[2]=r[10];
goto P_0c0618e2;
P_0c0618e2: /* original 62b3, guest PC 0x0c0618e2 */
if(!s->budget--) { s->failed_pc=0x0c0618e2u; return 0; }
r[2]=r[11];
goto P_0c0618e4;
P_0c0618e4: /* original 2722, guest PC 0x0c0618e4 */
if(!s->budget--) { s->failed_pc=0x0c0618e4u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c0618e6;
P_0c0618e6: /* original e000, guest PC 0x0c0618e6 */
if(!s->budget--) { s->failed_pc=0x0c0618e6u; return 0; }
r[0]=0x00000000u;
goto P_0c0618e8;
P_0c0618e8: /* original 7f18, guest PC 0x0c0618e8 */
if(!s->budget--) { s->failed_pc=0x0c0618e8u; return 0; }
r[15]+=0x00000018u;
goto P_0c0618ea;
P_0c0618ea: /* original 68f6, guest PC 0x0c0618ea */
if(!s->budget--) { s->failed_pc=0x0c0618eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0618ec;
P_0c0618ec: /* original 6af6, guest PC 0x0c0618ec */
if(!s->budget--) { s->failed_pc=0x0c0618ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0618ee;
P_0c0618ee: /* original 6bf6, guest PC 0x0c0618ee */
if(!s->budget--) { s->failed_pc=0x0c0618eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0618f0;
P_0c0618f0: /* original 6cf6, guest PC 0x0c0618f0 */
if(!s->budget--) { s->failed_pc=0x0c0618f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0618f2;
P_0c0618f2: /* original 6df6, guest PC 0x0c0618f2 */
if(!s->budget--) { s->failed_pc=0x0c0618f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0618f4;
P_0c0618f4: /* original 000b, guest PC 0x0c0618f4 */
if(!s->budget--) { s->failed_pc=0x0c0618f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0618f6: /* original 6ef6, guest PC 0x0c0618f6 */
if(!s->budget--) { s->failed_pc=0x0c0618f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0618f8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
