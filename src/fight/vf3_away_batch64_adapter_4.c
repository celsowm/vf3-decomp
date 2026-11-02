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
int vf3_away_batch64_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c091438u: goto P_0c091438;
case 0x0c09143au: goto P_0c09143a;
case 0x0c09143cu: goto P_0c09143c;
case 0x0c09143eu: goto P_0c09143e;
case 0x0c091440u: goto P_0c091440;
case 0x0c091442u: goto P_0c091442;
case 0x0c091444u: goto P_0c091444;
case 0x0c091446u: goto P_0c091446;
case 0x0c091448u: goto P_0c091448;
case 0x0c09144au: goto P_0c09144a;
case 0x0c09144cu: goto P_0c09144c;
case 0x0c09144eu: goto P_0c09144e;
case 0x0c091450u: goto P_0c091450;
case 0x0c091452u: goto P_0c091452;
case 0x0c091454u: goto P_0c091454;
case 0x0c091456u: goto P_0c091456;
case 0x0c091458u: goto P_0c091458;
case 0x0c09145au: goto P_0c09145a;
case 0x0c09145cu: goto P_0c09145c;
case 0x0c09145eu: goto P_0c09145e;
case 0x0c091460u: goto P_0c091460;
case 0x0c091462u: goto P_0c091462;
case 0x0c091464u: goto P_0c091464;
case 0x0c091466u: goto P_0c091466;
case 0x0c091468u: goto P_0c091468;
case 0x0c09146au: goto P_0c09146a;
case 0x0c09146cu: goto P_0c09146c;
case 0x0c09146eu: goto P_0c09146e;
case 0x0c091470u: goto P_0c091470;
case 0x0c091472u: goto P_0c091472;
case 0x0c091474u: goto P_0c091474;
case 0x0c091476u: goto P_0c091476;
case 0x0c091478u: goto P_0c091478;
case 0x0c09147au: goto P_0c09147a;
case 0x0c09147cu: goto P_0c09147c;
case 0x0c09147eu: goto P_0c09147e;
case 0x0c091480u: goto P_0c091480;
case 0x0c091482u: goto P_0c091482;
case 0x0c091484u: goto P_0c091484;
case 0x0c091486u: goto P_0c091486;
case 0x0c091488u: goto P_0c091488;
case 0x0c09148au: goto P_0c09148a;
case 0x0c09148cu: goto P_0c09148c;
case 0x0c09148eu: goto P_0c09148e;
case 0x0c091490u: goto P_0c091490;
case 0x0c091492u: goto P_0c091492;
case 0x0c091494u: goto P_0c091494;
case 0x0c091496u: goto P_0c091496;
case 0x0c091498u: goto P_0c091498;
case 0x0c09149au: goto P_0c09149a;
case 0x0c09149cu: goto P_0c09149c;
case 0x0c09149eu: goto P_0c09149e;
case 0x0c0914a0u: goto P_0c0914a0;
case 0x0c0914a2u: goto P_0c0914a2;
case 0x0c0914a4u: goto P_0c0914a4;
case 0x0c0914a6u: goto P_0c0914a6;
case 0x0c0914a8u: goto P_0c0914a8;
case 0x0c0914aau: goto P_0c0914aa;
case 0x0c0914acu: goto P_0c0914ac;
case 0x0c0914aeu: goto P_0c0914ae;
case 0x0c0914b0u: goto P_0c0914b0;
case 0x0c0914b2u: goto P_0c0914b2;
case 0x0c0914b4u: goto P_0c0914b4;
case 0x0c0914b6u: goto P_0c0914b6;
case 0x0c0914b8u: goto P_0c0914b8;
case 0x0c0914bau: goto P_0c0914ba;
case 0x0c0914bcu: goto P_0c0914bc;
case 0x0c0914beu: goto P_0c0914be;
case 0x0c0914c0u: goto P_0c0914c0;
case 0x0c0914c2u: goto P_0c0914c2;
case 0x0c0914c4u: goto P_0c0914c4;
case 0x0c0914c6u: goto P_0c0914c6;
case 0x0c0914c8u: goto P_0c0914c8;
case 0x0c0914cau: goto P_0c0914ca;
case 0x0c0914ccu: goto P_0c0914cc;
case 0x0c0914ceu: goto P_0c0914ce;
case 0x0c0914d0u: goto P_0c0914d0;
case 0x0c0914d2u: goto P_0c0914d2;
case 0x0c0914d4u: goto P_0c0914d4;
case 0x0c0914d6u: goto P_0c0914d6;
case 0x0c0914d8u: goto P_0c0914d8;
case 0x0c0914dau: goto P_0c0914da;
case 0x0c0914dcu: goto P_0c0914dc;
case 0x0c0914deu: goto P_0c0914de;
case 0x0c0914e0u: goto P_0c0914e0;
case 0x0c0914e2u: goto P_0c0914e2;
case 0x0c0914e4u: goto P_0c0914e4;
case 0x0c0914e6u: goto P_0c0914e6;
case 0x0c0914e8u: goto P_0c0914e8;
case 0x0c0914eau: goto P_0c0914ea;
case 0x0c0914ecu: goto P_0c0914ec;
case 0x0c0914eeu: goto P_0c0914ee;
case 0x0c0914f0u: goto P_0c0914f0;
case 0x0c0914f2u: goto P_0c0914f2;
case 0x0c0914f4u: goto P_0c0914f4;
case 0x0c0914f6u: goto P_0c0914f6;
case 0x0c0914f8u: goto P_0c0914f8;
case 0x0c0914fau: goto P_0c0914fa;
case 0x0c0914fcu: goto P_0c0914fc;
case 0x0c0914feu: goto P_0c0914fe;
case 0x0c091500u: goto P_0c091500;
case 0x0c091502u: goto P_0c091502;
case 0x0c091504u: goto P_0c091504;
case 0x0c091506u: goto P_0c091506;
case 0x0c091508u: goto P_0c091508;
case 0x0c09150au: goto P_0c09150a;
case 0x0c09150cu: goto P_0c09150c;
case 0x0c09150eu: goto P_0c09150e;
case 0x0c091510u: goto P_0c091510;
case 0x0c091512u: goto P_0c091512;
case 0x0c091514u: goto P_0c091514;
case 0x0c091516u: goto P_0c091516;
case 0x0c091518u: goto P_0c091518;
case 0x0c09151au: goto P_0c09151a;
case 0x0c09151cu: goto P_0c09151c;
case 0x0c09151eu: goto P_0c09151e;
case 0x0c091520u: goto P_0c091520;
case 0x0c091522u: goto P_0c091522;
case 0x0c091524u: goto P_0c091524;
case 0x0c091526u: goto P_0c091526;
case 0x0c091528u: goto P_0c091528;
case 0x0c09152au: goto P_0c09152a;
case 0x0c09152cu: goto P_0c09152c;
case 0x0c09152eu: goto P_0c09152e;
case 0x0c091530u: goto P_0c091530;
case 0x0c091532u: goto P_0c091532;
case 0x0c091534u: goto P_0c091534;
case 0x0c091536u: goto P_0c091536;
case 0x0c091538u: goto P_0c091538;
case 0x0c09153au: goto P_0c09153a;
case 0x0c09153cu: goto P_0c09153c;
case 0x0c09153eu: goto P_0c09153e;
case 0x0c091540u: goto P_0c091540;
case 0x0c091542u: goto P_0c091542;
case 0x0c091544u: goto P_0c091544;
case 0x0c091546u: goto P_0c091546;
case 0x0c091548u: goto P_0c091548;
case 0x0c09154au: goto P_0c09154a;
case 0x0c091590u: goto P_0c091590;
case 0x0c091592u: goto P_0c091592;
case 0x0c091594u: goto P_0c091594;
case 0x0c091596u: goto P_0c091596;
case 0x0c091598u: goto P_0c091598;
case 0x0c09159au: goto P_0c09159a;
case 0x0c09159cu: goto P_0c09159c;
case 0x0c09159eu: goto P_0c09159e;
case 0x0c0915a0u: goto P_0c0915a0;
case 0x0c0915a2u: goto P_0c0915a2;
case 0x0c0915a4u: goto P_0c0915a4;
case 0x0c0915a6u: goto P_0c0915a6;
case 0x0c0915a8u: goto P_0c0915a8;
case 0x0c0915aau: goto P_0c0915aa;
case 0x0c0915acu: goto P_0c0915ac;
case 0x0c0915aeu: goto P_0c0915ae;
case 0x0c0915b0u: goto P_0c0915b0;
case 0x0c0915b2u: goto P_0c0915b2;
case 0x0c0915b4u: goto P_0c0915b4;
case 0x0c0915b6u: goto P_0c0915b6;
case 0x0c0915b8u: goto P_0c0915b8;
case 0x0c0915bau: goto P_0c0915ba;
case 0x0c0915bcu: goto P_0c0915bc;
case 0x0c0915beu: goto P_0c0915be;
case 0x0c0915c0u: goto P_0c0915c0;
case 0x0c0915c2u: goto P_0c0915c2;
case 0x0c0915c4u: goto P_0c0915c4;
case 0x0c0915c6u: goto P_0c0915c6;
case 0x0c0915c8u: goto P_0c0915c8;
case 0x0c0915cau: goto P_0c0915ca;
case 0x0c0915ccu: goto P_0c0915cc;
case 0x0c0915ceu: goto P_0c0915ce;
case 0x0c0915d0u: goto P_0c0915d0;
case 0x0c0915d2u: goto P_0c0915d2;
case 0x0c0915d4u: goto P_0c0915d4;
case 0x0c0915d6u: goto P_0c0915d6;
case 0x0c0915d8u: goto P_0c0915d8;
case 0x0c0915dau: goto P_0c0915da;
case 0x0c0915dcu: goto P_0c0915dc;
case 0x0c0915deu: goto P_0c0915de;
case 0x0c0915e0u: goto P_0c0915e0;
case 0x0c0915e2u: goto P_0c0915e2;
case 0x0c0915e4u: goto P_0c0915e4;
case 0x0c0915e6u: goto P_0c0915e6;
case 0x0c0915e8u: goto P_0c0915e8;
case 0x0c0915eau: goto P_0c0915ea;
case 0x0c0915ecu: goto P_0c0915ec;
case 0x0c0915eeu: goto P_0c0915ee;
case 0x0c0915f0u: goto P_0c0915f0;
case 0x0c0915f2u: goto P_0c0915f2;
case 0x0c0915f4u: goto P_0c0915f4;
case 0x0c0915f6u: goto P_0c0915f6;
case 0x0c091618u: goto P_0c091618;
case 0x0c09161au: goto P_0c09161a;
case 0x0c09161cu: goto P_0c09161c;
case 0x0c09161eu: goto P_0c09161e;
case 0x0c091620u: goto P_0c091620;
case 0x0c091622u: goto P_0c091622;
case 0x0c091624u: goto P_0c091624;
case 0x0c091626u: goto P_0c091626;
case 0x0c091628u: goto P_0c091628;
case 0x0c09162au: goto P_0c09162a;
case 0x0c09162cu: goto P_0c09162c;
case 0x0c09162eu: goto P_0c09162e;
case 0x0c091630u: goto P_0c091630;
case 0x0c091632u: goto P_0c091632;
case 0x0c091634u: goto P_0c091634;
case 0x0c091636u: goto P_0c091636;
case 0x0c091638u: goto P_0c091638;
case 0x0c09163au: goto P_0c09163a;
case 0x0c09163cu: goto P_0c09163c;
case 0x0c09163eu: goto P_0c09163e;
case 0x0c091640u: goto P_0c091640;
case 0x0c091642u: goto P_0c091642;
case 0x0c091644u: goto P_0c091644;
case 0x0c091646u: goto P_0c091646;
case 0x0c091648u: goto P_0c091648;
case 0x0c09164au: goto P_0c09164a;
case 0x0c09164cu: goto P_0c09164c;
case 0x0c09164eu: goto P_0c09164e;
case 0x0c091650u: goto P_0c091650;
case 0x0c091652u: goto P_0c091652;
case 0x0c091654u: goto P_0c091654;
case 0x0c091656u: goto P_0c091656;
case 0x0c091658u: goto P_0c091658;
case 0x0c09165au: goto P_0c09165a;
case 0x0c09165cu: goto P_0c09165c;
case 0x0c09165eu: goto P_0c09165e;
case 0x0c091660u: goto P_0c091660;
case 0x0c091662u: goto P_0c091662;
case 0x0c091664u: goto P_0c091664;
case 0x0c091666u: goto P_0c091666;
case 0x0c091668u: goto P_0c091668;
case 0x0c09166au: goto P_0c09166a;
case 0x0c09166cu: goto P_0c09166c;
case 0x0c09166eu: goto P_0c09166e;
case 0x0c091670u: goto P_0c091670;
case 0x0c091672u: goto P_0c091672;
case 0x0c091674u: goto P_0c091674;
case 0x0c091676u: goto P_0c091676;
case 0x0c091678u: goto P_0c091678;
case 0x0c09167au: goto P_0c09167a;
case 0x0c09167cu: goto P_0c09167c;
case 0x0c09167eu: goto P_0c09167e;
case 0x0c091680u: goto P_0c091680;
case 0x0c091682u: goto P_0c091682;
case 0x0c091684u: goto P_0c091684;
case 0x0c091686u: goto P_0c091686;
case 0x0c091688u: goto P_0c091688;
case 0x0c09168au: goto P_0c09168a;
case 0x0c09168cu: goto P_0c09168c;
case 0x0c09168eu: goto P_0c09168e;
case 0x0c091690u: goto P_0c091690;
case 0x0c091692u: goto P_0c091692;
case 0x0c091694u: goto P_0c091694;
case 0x0c091696u: goto P_0c091696;
case 0x0c091698u: goto P_0c091698;
case 0x0c09169au: goto P_0c09169a;
case 0x0c09169cu: goto P_0c09169c;
case 0x0c09169eu: goto P_0c09169e;
case 0x0c0916a0u: goto P_0c0916a0;
case 0x0c0916a2u: goto P_0c0916a2;
case 0x0c0916a4u: goto P_0c0916a4;
case 0x0c0916a6u: goto P_0c0916a6;
case 0x0c0916a8u: goto P_0c0916a8;
case 0x0c0916aau: goto P_0c0916aa;
case 0x0c0916acu: goto P_0c0916ac;
case 0x0c0916aeu: goto P_0c0916ae;
case 0x0c0916b0u: goto P_0c0916b0;
case 0x0c0916b2u: goto P_0c0916b2;
case 0x0c0916b4u: goto P_0c0916b4;
case 0x0c0916b6u: goto P_0c0916b6;
case 0x0c0916b8u: goto P_0c0916b8;
case 0x0c0916bau: goto P_0c0916ba;
case 0x0c0916bcu: goto P_0c0916bc;
case 0x0c0916beu: goto P_0c0916be;
case 0x0c0916c0u: goto P_0c0916c0;
case 0x0c0916c2u: goto P_0c0916c2;
case 0x0c0916c4u: goto P_0c0916c4;
case 0x0c0916c6u: goto P_0c0916c6;
case 0x0c0916c8u: goto P_0c0916c8;
case 0x0c0916cau: goto P_0c0916ca;
case 0x0c0916ccu: goto P_0c0916cc;
case 0x0c0916ceu: goto P_0c0916ce;
case 0x0c0916d0u: goto P_0c0916d0;
case 0x0c0916d2u: goto P_0c0916d2;
case 0x0c0916d4u: goto P_0c0916d4;
case 0x0c0916d6u: goto P_0c0916d6;
case 0x0c0916d8u: goto P_0c0916d8;
case 0x0c0916dau: goto P_0c0916da;
case 0x0c0916dcu: goto P_0c0916dc;
case 0x0c0916deu: goto P_0c0916de;
case 0x0c0916e0u: goto P_0c0916e0;
case 0x0c0916e2u: goto P_0c0916e2;
case 0x0c0916e4u: goto P_0c0916e4;
case 0x0c0916e6u: goto P_0c0916e6;
case 0x0c0916e8u: goto P_0c0916e8;
case 0x0c0916eau: goto P_0c0916ea;
case 0x0c0916ecu: goto P_0c0916ec;
case 0x0c0916eeu: goto P_0c0916ee;
case 0x0c0916f0u: goto P_0c0916f0;
case 0x0c0916f2u: goto P_0c0916f2;
case 0x0c0916f4u: goto P_0c0916f4;
case 0x0c0916f6u: goto P_0c0916f6;
case 0x0c0916f8u: goto P_0c0916f8;
case 0x0c0916fau: goto P_0c0916fa;
case 0x0c0916fcu: goto P_0c0916fc;
case 0x0c0916feu: goto P_0c0916fe;
case 0x0c091700u: goto P_0c091700;
case 0x0c091702u: goto P_0c091702;
case 0x0c091704u: goto P_0c091704;
case 0x0c091706u: goto P_0c091706;
case 0x0c091708u: goto P_0c091708;
case 0x0c09170au: goto P_0c09170a;
case 0x0c09170cu: goto P_0c09170c;
case 0x0c09170eu: goto P_0c09170e;
case 0x0c091710u: goto P_0c091710;
case 0x0c091712u: goto P_0c091712;
case 0x0c091714u: goto P_0c091714;
case 0x0c091716u: goto P_0c091716;
case 0x0c091718u: goto P_0c091718;
case 0x0c09171au: goto P_0c09171a;
case 0x0c09171cu: goto P_0c09171c;
case 0x0c09171eu: goto P_0c09171e;
case 0x0c091720u: goto P_0c091720;
case 0x0c091722u: goto P_0c091722;
case 0x0c091724u: goto P_0c091724;
case 0x0c091726u: goto P_0c091726;
case 0x0c091728u: goto P_0c091728;
case 0x0c09172au: goto P_0c09172a;
case 0x0c09172cu: goto P_0c09172c;
case 0x0c09172eu: goto P_0c09172e;
case 0x0c091730u: goto P_0c091730;
case 0x0c091732u: goto P_0c091732;
case 0x0c091734u: goto P_0c091734;
case 0x0c091736u: goto P_0c091736;
case 0x0c091738u: goto P_0c091738;
case 0x0c09173au: goto P_0c09173a;
case 0x0c09173cu: goto P_0c09173c;
case 0x0c09173eu: goto P_0c09173e;
case 0x0c091740u: goto P_0c091740;
case 0x0c091742u: goto P_0c091742;
case 0x0c091744u: goto P_0c091744;
case 0x0c091780u: goto P_0c091780;
case 0x0c091782u: goto P_0c091782;
case 0x0c091784u: goto P_0c091784;
case 0x0c091786u: goto P_0c091786;
case 0x0c091788u: goto P_0c091788;
case 0x0c09178au: goto P_0c09178a;
case 0x0c09178cu: goto P_0c09178c;
case 0x0c09178eu: goto P_0c09178e;
case 0x0c091790u: goto P_0c091790;
case 0x0c091792u: goto P_0c091792;
case 0x0c091794u: goto P_0c091794;
case 0x0c091796u: goto P_0c091796;
case 0x0c091798u: goto P_0c091798;
case 0x0c09179au: goto P_0c09179a;
case 0x0c09179cu: goto P_0c09179c;
case 0x0c09179eu: goto P_0c09179e;
case 0x0c0917a0u: goto P_0c0917a0;
case 0x0c0917a2u: goto P_0c0917a2;
case 0x0c0917a4u: goto P_0c0917a4;
case 0x0c0917a6u: goto P_0c0917a6;
case 0x0c0917a8u: goto P_0c0917a8;
case 0x0c0917aau: goto P_0c0917aa;
case 0x0c0917acu: goto P_0c0917ac;
case 0x0c0917aeu: goto P_0c0917ae;
case 0x0c0917b0u: goto P_0c0917b0;
case 0x0c0917b2u: goto P_0c0917b2;
case 0x0c0917b4u: goto P_0c0917b4;
case 0x0c0917b6u: goto P_0c0917b6;
case 0x0c0917b8u: goto P_0c0917b8;
case 0x0c0917bau: goto P_0c0917ba;
case 0x0c0917bcu: goto P_0c0917bc;
case 0x0c0917beu: goto P_0c0917be;
case 0x0c0917c0u: goto P_0c0917c0;
case 0x0c0917c2u: goto P_0c0917c2;
case 0x0c0917c4u: goto P_0c0917c4;
case 0x0c0917c6u: goto P_0c0917c6;
case 0x0c0917c8u: goto P_0c0917c8;
case 0x0c0917cau: goto P_0c0917ca;
case 0x0c0917ccu: goto P_0c0917cc;
case 0x0c0917ceu: goto P_0c0917ce;
case 0x0c0917d0u: goto P_0c0917d0;
case 0x0c0917d2u: goto P_0c0917d2;
case 0x0c0917d4u: goto P_0c0917d4;
case 0x0c0917d6u: goto P_0c0917d6;
case 0x0c0917d8u: goto P_0c0917d8;
case 0x0c0917dau: goto P_0c0917da;
case 0x0c0917dcu: goto P_0c0917dc;
case 0x0c0917deu: goto P_0c0917de;
case 0x0c0917e0u: goto P_0c0917e0;
case 0x0c0917e2u: goto P_0c0917e2;
case 0x0c0917e4u: goto P_0c0917e4;
case 0x0c0917e6u: goto P_0c0917e6;
case 0x0c0917e8u: goto P_0c0917e8;
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
P_0c091438: /* original 2fe6, guest PC 0x0c091438 */
if(!s->budget--) { s->failed_pc=0x0c091438u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09143a;
P_0c09143a: /* original e300, guest PC 0x0c09143a */
if(!s->budget--) { s->failed_pc=0x0c09143au; return 0; }
r[3]=0x00000000u;
goto P_0c09143c;
P_0c09143c: /* original 2fd6, guest PC 0x0c09143c */
if(!s->budget--) { s->failed_pc=0x0c09143cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09143e;
P_0c09143e: /* original 2fc6, guest PC 0x0c09143e */
if(!s->budget--) { s->failed_pc=0x0c09143eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091440;
P_0c091440: /* original 2fb6, guest PC 0x0c091440 */
if(!s->budget--) { s->failed_pc=0x0c091440u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091442;
P_0c091442: /* original 6b43, guest PC 0x0c091442 */
if(!s->budget--) { s->failed_pc=0x0c091442u; return 0; }
r[11]=r[4];
goto P_0c091444;
P_0c091444: /* original 2fa6, guest PC 0x0c091444 */
if(!s->budget--) { s->failed_pc=0x0c091444u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091446;
P_0c091446: /* original 2f96, guest PC 0x0c091446 */
if(!s->budget--) { s->failed_pc=0x0c091446u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091448;
P_0c091448: /* original 2f86, guest PC 0x0c091448 */
if(!s->budget--) { s->failed_pc=0x0c091448u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09144a;
P_0c09144a: /* original fffb, guest PC 0x0c09144a */
if(!s->budget--) { s->failed_pc=0x0c09144au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09144c;
P_0c09144c: /* original ffeb, guest PC 0x0c09144c */
if(!s->budget--) { s->failed_pc=0x0c09144cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09144e;
P_0c09144e: /* original 4f22, guest PC 0x0c09144e */
if(!s->budget--) { s->failed_pc=0x0c09144eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091450;
P_0c091450: /* original 907c, guest PC 0x0c091450 */
if(!s->budget--) { s->failed_pc=0x0c091450u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09154cu,2);
goto P_0c091452;
P_0c091452: /* original 9e7c, guest PC 0x0c091452 */
if(!s->budget--) { s->failed_pc=0x0c091452u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09154eu,2);
goto P_0c091454;
P_0c091454: /* original 3f0c, guest PC 0x0c091454 */
if(!s->budget--) { s->failed_pc=0x0c091454u; return 0; }
r[15]+=r[0];
goto P_0c091456;
P_0c091456: /* original 1f38, guest PC 0x0c091456 */
if(!s->budget--) { s->failed_pc=0x0c091456u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c091458;
P_0c091458: /* original 3efc, guest PC 0x0c091458 */
if(!s->budget--) { s->failed_pc=0x0c091458u; return 0; }
r[14]+=r[15];
goto P_0c09145a;
P_0c09145a: /* original d444, guest PC 0x0c09145a */
if(!s->budget--) { s->failed_pc=0x0c09145au; return 0; }
r[4]=read(ram,0x0c09156cu,4);
goto P_0c09145c;
P_0c09145c: /* original 5348, guest PC 0x0c09145c */
if(!s->budget--) { s->failed_pc=0x0c09145cu; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c09145e;
P_0c09145e: /* original 6d33, guest PC 0x0c09145e */
if(!s->budget--) { s->failed_pc=0x0c09145eu; return 0; }
r[13]=r[3];
goto P_0c091460;
P_0c091460: /* original 2f32, guest PC 0x0c091460 */
if(!s->budget--) { s->failed_pc=0x0c091460u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091462;
P_0c091462: /* original 9075, guest PC 0x0c091462 */
if(!s->budget--) { s->failed_pc=0x0c091462u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091550u,2);
goto P_0c091464;
P_0c091464: /* original 5344, guest PC 0x0c091464 */
if(!s->budget--) { s->failed_pc=0x0c091464u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c091466;
P_0c091466: /* original 0dde, guest PC 0x0c091466 */
if(!s->budget--) { s->failed_pc=0x0c091466u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c091468;
P_0c091468: /* original 3b30, guest PC 0x0c091468 */
if(!s->budget--) { s->failed_pc=0x0c091468u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c09146a;
P_0c09146a: /* original 8d04, guest PC 0x0c09146a */
if(!s->budget--) { s->failed_pc=0x0c09146au; return 0; }
cond=r[17]&1u;
r[9]=0x00000001u;
if(cond) { goto P_0c091476; }
goto P_0c09146e;
P_0c09146c: /* original e901, guest PC 0x0c09146c */
if(!s->budget--) { s->failed_pc=0x0c09146cu; return 0; }
r[9]=0x00000001u;
goto P_0c09146e;
P_0c09146e: /* original 906f, guest PC 0x0c09146e */
if(!s->budget--) { s->failed_pc=0x0c09146eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091550u,2);
goto P_0c091470;
P_0c091470: /* original 2d9a, guest PC 0x0c091470 */
if(!s->budget--) { s->failed_pc=0x0c091470u; return 0; }
r[13]^=r[9];
goto P_0c091472;
P_0c091472: /* original 63f2, guest PC 0x0c091472 */
if(!s->budget--) { s->failed_pc=0x0c091472u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091474;
P_0c091474: /* original 03d6, guest PC 0x0c091474 */
if(!s->budget--) { s->failed_pc=0x0c091474u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c091476;
P_0c091476: /* original d23e, guest PC 0x0c091476 */
if(!s->budget--) { s->failed_pc=0x0c091476u; return 0; }
r[2]=read(ram,0x0c091570u,4);
goto P_0c091478;
P_0c091478: /* original 6322, guest PC 0x0c091478 */
if(!s->budget--) { s->failed_pc=0x0c091478u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c09147a;
P_0c09147a: /* original 2398, guest PC 0x0c09147a */
if(!s->budget--) { s->failed_pc=0x0c09147au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c09147c;
P_0c09147c: /* original 8901, guest PC 0x0c09147c */
if(!s->budget--) { s->failed_pc=0x0c09147cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091482; }
goto P_0c09147e;
P_0c09147e: /* original a1a7, guest PC 0x0c09147e */
if(!s->budget--) { s->failed_pc=0x0c09147eu; return 0; }
goto P_0c0917d0;
P_0c091480: /* original 0009, guest PC 0x0c091480 */
if(!s->budget--) { s->failed_pc=0x0c091480u; return 0; }
goto P_0c091482;
P_0c091482: /* original dc3c, guest PC 0x0c091482 */
if(!s->budget--) { s->failed_pc=0x0c091482u; return 0; }
r[12]=read(ram,0x0c091574u,4);
goto P_0c091484;
P_0c091484: /* original d73c, guest PC 0x0c091484 */
if(!s->budget--) { s->failed_pc=0x0c091484u; return 0; }
r[7]=read(ram,0x0c091578u,4);
goto P_0c091486;
P_0c091486: /* original 65c2, guest PC 0x0c091486 */
if(!s->budget--) { s->failed_pc=0x0c091486u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c091488;
P_0c091488: /* original 64b2, guest PC 0x0c091488 */
if(!s->budget--) { s->failed_pc=0x0c091488u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c09148a;
P_0c09148a: /* original 6353, guest PC 0x0c09148a */
if(!s->budget--) { s->failed_pc=0x0c09148au; return 0; }
r[3]=r[5];
goto P_0c09148c;
P_0c09148c: /* original 2378, guest PC 0x0c09148c */
if(!s->budget--) { s->failed_pc=0x0c09148cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c09148e;
P_0c09148e: /* original 8f14, guest PC 0x0c09148e */
if(!s->budget--) { s->failed_pc=0x0c09148eu; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[12]+4,4);
if(!cond) { goto P_0c0914ba; }
goto P_0c091492;
P_0c091490: /* original 56c1, guest PC 0x0c091490 */
if(!s->budget--) { s->failed_pc=0x0c091490u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c091492;
P_0c091492: /* original d23a, guest PC 0x0c091492 */
if(!s->budget--) { s->failed_pc=0x0c091492u; return 0; }
r[2]=read(ram,0x0c09157cu,4);
goto P_0c091494;
P_0c091494: /* original 2528, guest PC 0x0c091494 */
if(!s->budget--) { s->failed_pc=0x0c091494u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c091496;
P_0c091496: /* original 8901, guest PC 0x0c091496 */
if(!s->budget--) { s->failed_pc=0x0c091496u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09149c; }
goto P_0c091498;
P_0c091498: /* original 2678, guest PC 0x0c091498 */
if(!s->budget--) { s->failed_pc=0x0c091498u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[7])==0)!=0);
goto P_0c09149a;
P_0c09149a: /* original 8b0e, guest PC 0x0c09149a */
if(!s->budget--) { s->failed_pc=0x0c09149au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0914ba; }
goto P_0c09149c;
P_0c09149c: /* original 6343, guest PC 0x0c09149c */
if(!s->budget--) { s->failed_pc=0x0c09149cu; return 0; }
r[3]=r[4];
goto P_0c09149e;
P_0c09149e: /* original 2398, guest PC 0x0c09149e */
if(!s->budget--) { s->failed_pc=0x0c09149eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0914a0;
P_0c0914a0: /* original 8b01, guest PC 0x0c0914a0 */
if(!s->budget--) { s->failed_pc=0x0c0914a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0914a6; }
goto P_0c0914a2;
P_0c0914a2: /* original a195, guest PC 0x0c0914a2 */
if(!s->budget--) { s->failed_pc=0x0c0914a2u; return 0; }
goto P_0c0917d0;
P_0c0914a4: /* original 0009, guest PC 0x0c0914a4 */
if(!s->budget--) { s->failed_pc=0x0c0914a4u; return 0; }
goto P_0c0914a6;
P_0c0914a6: /* original d136, guest PC 0x0c0914a6 */
if(!s->budget--) { s->failed_pc=0x0c0914a6u; return 0; }
r[1]=read(ram,0x0c091580u,4);
goto P_0c0914a8;
P_0c0914a8: /* original 2148, guest PC 0x0c0914a8 */
if(!s->budget--) { s->failed_pc=0x0c0914a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0914aa;
P_0c0914aa: /* original 8b01, guest PC 0x0c0914aa */
if(!s->budget--) { s->failed_pc=0x0c0914aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0914b0; }
goto P_0c0914ac;
P_0c0914ac: /* original a190, guest PC 0x0c0914ac */
if(!s->budget--) { s->failed_pc=0x0c0914acu; return 0; }
goto P_0c0917d0;
P_0c0914ae: /* original 0009, guest PC 0x0c0914ae */
if(!s->budget--) { s->failed_pc=0x0c0914aeu; return 0; }
goto P_0c0914b0;
P_0c0914b0: /* original e202, guest PC 0x0c0914b0 */
if(!s->budget--) { s->failed_pc=0x0c0914b0u; return 0; }
r[2]=0x00000002u;
goto P_0c0914b2;
P_0c0914b2: /* original 2428, guest PC 0x0c0914b2 */
if(!s->budget--) { s->failed_pc=0x0c0914b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0914b4;
P_0c0914b4: /* original 8901, guest PC 0x0c0914b4 */
if(!s->budget--) { s->failed_pc=0x0c0914b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0914ba; }
goto P_0c0914b6;
P_0c0914b6: /* original a18b, guest PC 0x0c0914b6 */
if(!s->budget--) { s->failed_pc=0x0c0914b6u; return 0; }
goto P_0c0917d0;
P_0c0914b8: /* original 0009, guest PC 0x0c0914b8 */
if(!s->budget--) { s->failed_pc=0x0c0914b8u; return 0; }
goto P_0c0914ba;
P_0c0914ba: /* original d232, guest PC 0x0c0914ba */
if(!s->budget--) { s->failed_pc=0x0c0914bau; return 0; }
r[2]=read(ram,0x0c091584u,4);
goto P_0c0914bc;
P_0c0914bc: /* original 420b, guest PC 0x0c0914bc */
if(!s->budget--) { s->failed_pc=0x0c0914bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0914c0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0914c0u) { target=s->pc; goto dispatch; }
goto P_0c0914c0;
P_0c0914be: /* original e400, guest PC 0x0c0914be */
if(!s->budget--) { s->failed_pc=0x0c0914beu; return 0; }
r[4]=0x00000000u;
goto P_0c0914c0;
P_0c0914c0: /* original e01c, guest PC 0x0c0914c0 */
if(!s->budget--) { s->failed_pc=0x0c0914c0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0914c2;
P_0c0914c2: /* original 1fd3, guest PC 0x0c0914c2 */
if(!s->budget--) { s->failed_pc=0x0c0914c2u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0914c4;
P_0c0914c4: /* original 00cc, guest PC 0x0c0914c4 */
if(!s->budget--) { s->failed_pc=0x0c0914c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0914c6;
P_0c0914c6: /* original ec0f, guest PC 0x0c0914c6 */
if(!s->budget--) { s->failed_pc=0x0c0914c6u; return 0; }
r[12]=0x0000000fu;
goto P_0c0914c8;
P_0c0914c8: /* original 600c, guest PC 0x0c0914c8 */
if(!s->budget--) { s->failed_pc=0x0c0914c8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0914ca;
P_0c0914ca: /* original 2c09, guest PC 0x0c0914ca */
if(!s->budget--) { s->failed_pc=0x0c0914cau; return 0; }
r[12]&=r[0];
goto P_0c0914cc;
P_0c0914cc: /* original 60c3, guest PC 0x0c0914cc */
if(!s->budget--) { s->failed_pc=0x0c0914ccu; return 0; }
r[0]=r[12];
goto P_0c0914ce;
P_0c0914ce: /* original 8805, guest PC 0x0c0914ce */
if(!s->budget--) { s->failed_pc=0x0c0914ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0914d0;
P_0c0914d0: /* original 890b, guest PC 0x0c0914d0 */
if(!s->budget--) { s->failed_pc=0x0c0914d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0914ea; }
goto P_0c0914d2;
P_0c0914d2: /* original 60c3, guest PC 0x0c0914d2 */
if(!s->budget--) { s->failed_pc=0x0c0914d2u; return 0; }
r[0]=r[12];
goto P_0c0914d4;
P_0c0914d4: /* original 8806, guest PC 0x0c0914d4 */
if(!s->budget--) { s->failed_pc=0x0c0914d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0914d6;
P_0c0914d6: /* original 8908, guest PC 0x0c0914d6 */
if(!s->budget--) { s->failed_pc=0x0c0914d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0914ea; }
goto P_0c0914d8;
P_0c0914d8: /* original 60c3, guest PC 0x0c0914d8 */
if(!s->budget--) { s->failed_pc=0x0c0914d8u; return 0; }
r[0]=r[12];
goto P_0c0914da;
P_0c0914da: /* original 8809, guest PC 0x0c0914da */
if(!s->budget--) { s->failed_pc=0x0c0914dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0914dc;
P_0c0914dc: /* original 8905, guest PC 0x0c0914dc */
if(!s->budget--) { s->failed_pc=0x0c0914dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0914ea; }
goto P_0c0914de;
P_0c0914de: /* original 60c3, guest PC 0x0c0914de */
if(!s->budget--) { s->failed_pc=0x0c0914deu; return 0; }
r[0]=r[12];
goto P_0c0914e0;
P_0c0914e0: /* original 880b, guest PC 0x0c0914e0 */
if(!s->budget--) { s->failed_pc=0x0c0914e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0914e2;
P_0c0914e2: /* original 8902, guest PC 0x0c0914e2 */
if(!s->budget--) { s->failed_pc=0x0c0914e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0914ea; }
goto P_0c0914e4;
P_0c0914e4: /* original 60c3, guest PC 0x0c0914e4 */
if(!s->budget--) { s->failed_pc=0x0c0914e4u; return 0; }
r[0]=r[12];
goto P_0c0914e6;
P_0c0914e6: /* original 880d, guest PC 0x0c0914e6 */
if(!s->budget--) { s->failed_pc=0x0c0914e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0914e8;
P_0c0914e8: /* original 8b03, guest PC 0x0c0914e8 */
if(!s->budget--) { s->failed_pc=0x0c0914e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0914f2; }
goto P_0c0914ea;
P_0c0914ea: /* original 52f3, guest PC 0x0c0914ea */
if(!s->budget--) { s->failed_pc=0x0c0914eau; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0914ec;
P_0c0914ec: /* original e3fe, guest PC 0x0c0914ec */
if(!s->budget--) { s->failed_pc=0x0c0914ecu; return 0; }
r[3]=0xfffffffeu;
goto P_0c0914ee;
P_0c0914ee: /* original 2239, guest PC 0x0c0914ee */
if(!s->budget--) { s->failed_pc=0x0c0914eeu; return 0; }
r[2]&=r[3];
goto P_0c0914f0;
P_0c0914f0: /* original 1f23, guest PC 0x0c0914f0 */
if(!s->budget--) { s->failed_pc=0x0c0914f0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0914f2;
P_0c0914f2: /* original 922e, guest PC 0x0c0914f2 */
if(!s->budget--) { s->failed_pc=0x0c0914f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091552u,2);
goto P_0c0914f4;
P_0c0914f4: /* original e060, guest PC 0x0c0914f4 */
if(!s->budget--) { s->failed_pc=0x0c0914f4u; return 0; }
r[0]=0x00000060u;
goto P_0c0914f6;
P_0c0914f6: /* original 63f2, guest PC 0x0c0914f6 */
if(!s->budget--) { s->failed_pc=0x0c0914f6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0914f8;
P_0c0914f8: /* original 00bc, guest PC 0x0c0914f8 */
if(!s->budget--) { s->failed_pc=0x0c0914f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0914fa;
P_0c0914fa: /* original 323c, guest PC 0x0c0914fa */
if(!s->budget--) { s->failed_pc=0x0c0914fau; return 0; }
r[2]+=r[3];
goto P_0c0914fc;
P_0c0914fc: /* original d522, guest PC 0x0c0914fc */
if(!s->budget--) { s->failed_pc=0x0c0914fcu; return 0; }
r[5]=read(ram,0x0c091588u,4);
goto P_0c0914fe;
P_0c0914fe: /* original 600c, guest PC 0x0c0914fe */
if(!s->budget--) { s->failed_pc=0x0c0914feu; return 0; }
r[0]=r[0]&255u;
goto P_0c091500;
P_0c091500: /* original 4000, guest PC 0x0c091500 */
if(!s->budget--) { s->failed_pc=0x0c091500u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091502;
P_0c091502: /* original 6853, guest PC 0x0c091502 */
if(!s->budget--) { s->failed_pc=0x0c091502u; return 0; }
r[8]=r[5];
goto P_0c091504;
P_0c091504: /* original 045d, guest PC 0x0c091504 */
if(!s->budget--) { s->failed_pc=0x0c091504u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c091506;
P_0c091506: /* original 1f25, guest PC 0x0c091506 */
if(!s->budget--) { s->failed_pc=0x0c091506u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c091508;
P_0c091508: /* original 9324, guest PC 0x0c091508 */
if(!s->budget--) { s->failed_pc=0x0c091508u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091554u,2);
goto P_0c09150a;
P_0c09150a: /* original 644d, guest PC 0x0c09150a */
if(!s->budget--) { s->failed_pc=0x0c09150au; return 0; }
r[4]=r[4]&65535u;
goto P_0c09150c;
P_0c09150c: /* original 3848, guest PC 0x0c09150c */
if(!s->budget--) { s->failed_pc=0x0c09150cu; return 0; }
r[8]-=r[4];
goto P_0c09150e;
P_0c09150e: /* original 33bc, guest PC 0x0c09150e */
if(!s->budget--) { s->failed_pc=0x0c09150eu; return 0; }
r[3]+=r[11];
goto P_0c091510;
P_0c091510: /* original 1f32, guest PC 0x0c091510 */
if(!s->budget--) { s->failed_pc=0x0c091510u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091512;
P_0c091512: /* original 9220, guest PC 0x0c091512 */
if(!s->budget--) { s->failed_pc=0x0c091512u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091556u,2);
goto P_0c091514;
P_0c091514: /* original 32bc, guest PC 0x0c091514 */
if(!s->budget--) { s->failed_pc=0x0c091514u; return 0; }
r[2]+=r[11];
goto P_0c091516;
P_0c091516: /* original 1f21, guest PC 0x0c091516 */
if(!s->budget--) { s->failed_pc=0x0c091516u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c091518;
P_0c091518: /* original d31c, guest PC 0x0c091518 */
if(!s->budget--) { s->failed_pc=0x0c091518u; return 0; }
r[3]=read(ram,0x0c09158cu,4);
goto P_0c09151a;
P_0c09151a: /* original 1f36, guest PC 0x0c09151a */
if(!s->budget--) { s->failed_pc=0x0c09151au; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c09151c;
P_0c09151c: /* original e317, guest PC 0x0c09151c */
if(!s->budget--) { s->failed_pc=0x0c09151cu; return 0; }
r[3]=0x00000017u;
goto P_0c09151e;
P_0c09151e: /* original 9d1b, guest PC 0x0c09151e */
if(!s->budget--) { s->failed_pc=0x0c09151eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091558u,2);
goto P_0c091520;
P_0c091520: /* original 1f34, guest PC 0x0c091520 */
if(!s->budget--) { s->failed_pc=0x0c091520u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c091522;
P_0c091522: /* original 901a, guest PC 0x0c091522 */
if(!s->budget--) { s->failed_pc=0x0c091522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09155au,2);
goto P_0c091524;
P_0c091524: /* original 3dbc, guest PC 0x0c091524 */
if(!s->budget--) { s->failed_pc=0x0c091524u; return 0; }
r[13]+=r[11];
goto P_0c091526;
P_0c091526: /* original 02be, guest PC 0x0c091526 */
if(!s->budget--) { s->failed_pc=0x0c091526u; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c091528;
P_0c091528: /* original 1f27, guest PC 0x0c091528 */
if(!s->budget--) { s->failed_pc=0x0c091528u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c09152a;
P_0c09152a: /* original 9017, guest PC 0x0c09152a */
if(!s->budget--) { s->failed_pc=0x0c09152au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09155cu,2);
goto P_0c09152c;
P_0c09152c: /* original ff8d, guest PC 0x0c09152c */
if(!s->budget--) { s->failed_pc=0x0c09152cu; return 0; }
fr[15]=0;
goto P_0c09152e;
P_0c09152e: /* original fff7, guest PC 0x0c09152e */
if(!s->budget--) { s->failed_pc=0x0c09152eu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c091530;
P_0c091530: /* original 9015, guest PC 0x0c091530 */
if(!s->budget--) { s->failed_pc=0x0c091530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09155eu,2);
goto P_0c091532;
P_0c091532: /* original fff7, guest PC 0x0c091532 */
if(!s->budget--) { s->failed_pc=0x0c091532u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c091534;
P_0c091534: /* original 9014, guest PC 0x0c091534 */
if(!s->budget--) { s->failed_pc=0x0c091534u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091560u,2);
goto P_0c091536;
P_0c091536: /* original fff7, guest PC 0x0c091536 */
if(!s->budget--) { s->failed_pc=0x0c091536u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c091538;
P_0c091538: /* original 9013, guest PC 0x0c091538 */
if(!s->budget--) { s->failed_pc=0x0c091538u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091562u,2);
goto P_0c09153a;
P_0c09153a: /* original fff7, guest PC 0x0c09153a */
if(!s->budget--) { s->failed_pc=0x0c09153au; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c09153c;
P_0c09153c: /* original 9012, guest PC 0x0c09153c */
if(!s->budget--) { s->failed_pc=0x0c09153cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091564u,2);
goto P_0c09153e;
P_0c09153e: /* original f3b6, guest PC 0x0c09153e */
if(!s->budget--) { s->failed_pc=0x0c09153eu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c091540;
P_0c091540: /* original 9011, guest PC 0x0c091540 */
if(!s->budget--) { s->failed_pc=0x0c091540u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091566u,2);
goto P_0c091542;
P_0c091542: /* original ff37, guest PC 0x0c091542 */
if(!s->budget--) { s->failed_pc=0x0c091542u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c091544;
P_0c091544: /* original 9010, guest PC 0x0c091544 */
if(!s->budget--) { s->failed_pc=0x0c091544u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091568u,2);
goto P_0c091546;
P_0c091546: /* original f34d, guest PC 0x0c091546 */
if(!s->budget--) { s->failed_pc=0x0c091546u; return 0; }
fr[3]^=0x80000000u;
goto P_0c091548;
P_0c091548: /* original a139, guest PC 0x0c091548 */
if(!s->budget--) { s->failed_pc=0x0c091548u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0917be;
P_0c09154a: /* original ff37, guest PC 0x0c09154a */
if(!s->budget--) { s->failed_pc=0x0c09154au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c09154cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09154cu; return 0; } return 1;
P_0c091590: /* original d21c, guest PC 0x0c091590 */
if(!s->budget--) { s->failed_pc=0x0c091590u; return 0; }
r[2]=read(ram,0x0c091604u,4);
goto P_0c091592;
P_0c091592: /* original 420b, guest PC 0x0c091592 */
if(!s->budget--) { s->failed_pc=0x0c091592u; return 0; }
target=r[2];
r[16]=code_base|0x0c091596u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091596u) { target=s->pc; goto dispatch; }
goto P_0c091596;
P_0c091594: /* original 0009, guest PC 0x0c091594 */
if(!s->budget--) { s->failed_pc=0x0c091594u; return 0; }
goto P_0c091596;
P_0c091596: /* original 942f, guest PC 0x0c091596 */
if(!s->budget--) { s->failed_pc=0x0c091596u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0915f8u,2);
goto P_0c091598;
P_0c091598: /* original db1b, guest PC 0x0c091598 */
if(!s->budget--) { s->failed_pc=0x0c091598u; return 0; }
r[11]=read(ram,0x0c091608u,4);
goto P_0c09159a;
P_0c09159a: /* original 4b0b, guest PC 0x0c09159a */
if(!s->budget--) { s->failed_pc=0x0c09159au; return 0; }
target=r[11];
r[16]=code_base|0x0c09159eu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09159eu) { target=s->pc; goto dispatch; }
goto P_0c09159e;
P_0c09159c: /* original 34fc, guest PC 0x0c09159c */
if(!s->budget--) { s->failed_pc=0x0c09159cu; return 0; }
r[4]+=r[15];
goto P_0c09159e;
P_0c09159e: /* original da1b, guest PC 0x0c09159e */
if(!s->budget--) { s->failed_pc=0x0c09159eu; return 0; }
r[10]=read(ram,0x0c09160cu,4);
goto P_0c0915a0;
P_0c0915a0: /* original 4a0b, guest PC 0x0c0915a0 */
if(!s->budget--) { s->failed_pc=0x0c0915a0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0915a4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915a4u) { target=s->pc; goto dispatch; }
goto P_0c0915a4;
P_0c0915a2: /* original 54f5, guest PC 0x0c0915a2 */
if(!s->budget--) { s->failed_pc=0x0c0915a2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0915a4;
P_0c0915a4: /* original 9429, guest PC 0x0c0915a4 */
if(!s->budget--) { s->failed_pc=0x0c0915a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0915fau,2);
goto P_0c0915a6;
P_0c0915a6: /* original 4b0b, guest PC 0x0c0915a6 */
if(!s->budget--) { s->failed_pc=0x0c0915a6u; return 0; }
target=r[11];
r[16]=code_base|0x0c0915aau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915aau) { target=s->pc; goto dispatch; }
goto P_0c0915aa;
P_0c0915a8: /* original 34fc, guest PC 0x0c0915a8 */
if(!s->budget--) { s->failed_pc=0x0c0915a8u; return 0; }
r[4]+=r[15];
goto P_0c0915aa;
P_0c0915aa: /* original 4a0b, guest PC 0x0c0915aa */
if(!s->budget--) { s->failed_pc=0x0c0915aau; return 0; }
target=r[10];
r[16]=code_base|0x0c0915aeu;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915aeu) { target=s->pc; goto dispatch; }
goto P_0c0915ae;
P_0c0915ac: /* original 54f2, guest PC 0x0c0915ac */
if(!s->budget--) { s->failed_pc=0x0c0915acu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0915ae;
P_0c0915ae: /* original 4b0b, guest PC 0x0c0915ae */
if(!s->budget--) { s->failed_pc=0x0c0915aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c0915b2u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915b2u) { target=s->pc; goto dispatch; }
goto P_0c0915b2;
P_0c0915b0: /* original 6483, guest PC 0x0c0915b0 */
if(!s->budget--) { s->failed_pc=0x0c0915b0u; return 0; }
r[4]=r[8];
goto P_0c0915b2;
P_0c0915b2: /* original d317, guest PC 0x0c0915b2 */
if(!s->budget--) { s->failed_pc=0x0c0915b2u; return 0; }
r[3]=read(ram,0x0c091610u,4);
goto P_0c0915b4;
P_0c0915b4: /* original 9422, guest PC 0x0c0915b4 */
if(!s->budget--) { s->failed_pc=0x0c0915b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0915fcu,2);
goto P_0c0915b6;
P_0c0915b6: /* original 430b, guest PC 0x0c0915b6 */
if(!s->budget--) { s->failed_pc=0x0c0915b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0915bau;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915bau) { target=s->pc; goto dispatch; }
goto P_0c0915ba;
P_0c0915b8: /* original 34fc, guest PC 0x0c0915b8 */
if(!s->budget--) { s->failed_pc=0x0c0915b8u; return 0; }
r[4]+=r[15];
goto P_0c0915ba;
P_0c0915ba: /* original 52f3, guest PC 0x0c0915ba */
if(!s->budget--) { s->failed_pc=0x0c0915bau; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0915bc;
P_0c0915bc: /* original 2298, guest PC 0x0c0915bc */
if(!s->budget--) { s->failed_pc=0x0c0915bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[9])==0)!=0);
goto P_0c0915be;
P_0c0915be: /* original 8b2b, guest PC 0x0c0915be */
if(!s->budget--) { s->failed_pc=0x0c0915beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091618; }
goto P_0c0915c0;
P_0c0915c0: /* original 901d, guest PC 0x0c0915c0 */
if(!s->budget--) { s->failed_pc=0x0c0915c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0915feu,2);
goto P_0c0915c2;
P_0c0915c2: /* original 65e3, guest PC 0x0c0915c2 */
if(!s->budget--) { s->failed_pc=0x0c0915c2u; return 0; }
r[5]=r[14];
goto P_0c0915c4;
P_0c0915c4: /* original 941c, guest PC 0x0c0915c4 */
if(!s->budget--) { s->failed_pc=0x0c0915c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091600u,2);
goto P_0c0915c6;
P_0c0915c6: /* original f5f6, guest PC 0x0c0915c6 */
if(!s->budget--) { s->failed_pc=0x0c0915c6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0915c8;
P_0c0915c8: /* original d312, guest PC 0x0c0915c8 */
if(!s->budget--) { s->failed_pc=0x0c0915c8u; return 0; }
r[3]=read(ram,0x0c091614u,4);
goto P_0c0915ca;
P_0c0915ca: /* original 34fc, guest PC 0x0c0915ca */
if(!s->budget--) { s->failed_pc=0x0c0915cau; return 0; }
r[4]+=r[15];
goto P_0c0915cc;
P_0c0915cc: /* original 9016, guest PC 0x0c0915cc */
if(!s->budget--) { s->failed_pc=0x0c0915ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0915fcu,2);
goto P_0c0915ce;
P_0c0915ce: /* original f54d, guest PC 0x0c0915ce */
if(!s->budget--) { s->failed_pc=0x0c0915ceu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0915d0;
P_0c0915d0: /* original 430b, guest PC 0x0c0915d0 */
if(!s->budget--) { s->failed_pc=0x0c0915d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0915d4u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0915d4u) { target=s->pc; goto dispatch; }
goto P_0c0915d4;
P_0c0915d2: /* original f4f6, guest PC 0x0c0915d2 */
if(!s->budget--) { s->failed_pc=0x0c0915d2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0915d4;
P_0c0915d4: /* original 2d02, guest PC 0x0c0915d4 */
if(!s->budget--) { s->failed_pc=0x0c0915d4u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0915d6;
P_0c0915d6: /* original 6403, guest PC 0x0c0915d6 */
if(!s->budget--) { s->failed_pc=0x0c0915d6u; return 0; }
r[4]=r[0];
goto P_0c0915d8;
P_0c0915d8: /* original 9012, guest PC 0x0c0915d8 */
if(!s->budget--) { s->failed_pc=0x0c0915d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091600u,2);
goto P_0c0915da;
P_0c0915da: /* original f3f6, guest PC 0x0c0915da */
if(!s->budget--) { s->failed_pc=0x0c0915dau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0915dc;
P_0c0915dc: /* original e004, guest PC 0x0c0915dc */
if(!s->budget--) { s->failed_pc=0x0c0915dcu; return 0; }
r[0]=0x00000004u;
goto P_0c0915de;
P_0c0915de: /* original fd37, guest PC 0x0c0915de */
if(!s->budget--) { s->failed_pc=0x0c0915deu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0915e0;
P_0c0915e0: /* original e008, guest PC 0x0c0915e0 */
if(!s->budget--) { s->failed_pc=0x0c0915e0u; return 0; }
r[0]=0x00000008u;
goto P_0c0915e2;
P_0c0915e2: /* original f3e8, guest PC 0x0c0915e2 */
if(!s->budget--) { s->failed_pc=0x0c0915e2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0915e4;
P_0c0915e4: /* original fd37, guest PC 0x0c0915e4 */
if(!s->budget--) { s->failed_pc=0x0c0915e4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0915e6;
P_0c0915e6: /* original e004, guest PC 0x0c0915e6 */
if(!s->budget--) { s->failed_pc=0x0c0915e6u; return 0; }
r[0]=0x00000004u;
goto P_0c0915e8;
P_0c0915e8: /* original f3e6, guest PC 0x0c0915e8 */
if(!s->budget--) { s->failed_pc=0x0c0915e8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0915ea;
P_0c0915ea: /* original e00c, guest PC 0x0c0915ea */
if(!s->budget--) { s->failed_pc=0x0c0915eau; return 0; }
r[0]=0x0000000cu;
goto P_0c0915ec;
P_0c0915ec: /* original fd37, guest PC 0x0c0915ec */
if(!s->budget--) { s->failed_pc=0x0c0915ecu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0915ee;
P_0c0915ee: /* original e008, guest PC 0x0c0915ee */
if(!s->budget--) { s->failed_pc=0x0c0915eeu; return 0; }
r[0]=0x00000008u;
goto P_0c0915f0;
P_0c0915f0: /* original f3e6, guest PC 0x0c0915f0 */
if(!s->budget--) { s->failed_pc=0x0c0915f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0915f2;
P_0c0915f2: /* original e010, guest PC 0x0c0915f2 */
if(!s->budget--) { s->failed_pc=0x0c0915f2u; return 0; }
r[0]=0x00000010u;
goto P_0c0915f4;
P_0c0915f4: /* original a020, guest PC 0x0c0915f4 */
if(!s->budget--) { s->failed_pc=0x0c0915f4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c091638;
P_0c0915f6: /* original fd37, guest PC 0x0c0915f6 */
if(!s->budget--) { s->failed_pc=0x0c0915f6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
if(!vf3_matrix_family(0x0c0915f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0915f8u; return 0; } return 1;
P_0c091618: /* original e004, guest PC 0x0c091618 */
if(!s->budget--) { s->failed_pc=0x0c091618u; return 0; }
r[0]=0x00000004u;
goto P_0c09161a;
P_0c09161a: /* original 64d2, guest PC 0x0c09161a */
if(!s->budget--) { s->failed_pc=0x0c09161au; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c09161c;
P_0c09161c: /* original f3d6, guest PC 0x0c09161c */
if(!s->budget--) { s->failed_pc=0x0c09161cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09161e;
P_0c09161e: /* original 9092, guest PC 0x0c09161e */
if(!s->budget--) { s->failed_pc=0x0c09161eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091746u,2);
goto P_0c091620;
P_0c091620: /* original ff37, guest PC 0x0c091620 */
if(!s->budget--) { s->failed_pc=0x0c091620u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c091622;
P_0c091622: /* original e008, guest PC 0x0c091622 */
if(!s->budget--) { s->failed_pc=0x0c091622u; return 0; }
r[0]=0x00000008u;
goto P_0c091624;
P_0c091624: /* original f3d6, guest PC 0x0c091624 */
if(!s->budget--) { s->failed_pc=0x0c091624u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c091626;
P_0c091626: /* original e00c, guest PC 0x0c091626 */
if(!s->budget--) { s->failed_pc=0x0c091626u; return 0; }
r[0]=0x0000000cu;
goto P_0c091628;
P_0c091628: /* original fe3a, guest PC 0x0c091628 */
if(!s->budget--) { s->failed_pc=0x0c091628u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09162a;
P_0c09162a: /* original f3d6, guest PC 0x0c09162a */
if(!s->budget--) { s->failed_pc=0x0c09162au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09162c;
P_0c09162c: /* original e004, guest PC 0x0c09162c */
if(!s->budget--) { s->failed_pc=0x0c09162cu; return 0; }
r[0]=0x00000004u;
goto P_0c09162e;
P_0c09162e: /* original fe37, guest PC 0x0c09162e */
if(!s->budget--) { s->failed_pc=0x0c09162eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091630;
P_0c091630: /* original e010, guest PC 0x0c091630 */
if(!s->budget--) { s->failed_pc=0x0c091630u; return 0; }
r[0]=0x00000010u;
goto P_0c091632;
P_0c091632: /* original f3d6, guest PC 0x0c091632 */
if(!s->budget--) { s->failed_pc=0x0c091632u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c091634;
P_0c091634: /* original e008, guest PC 0x0c091634 */
if(!s->budget--) { s->failed_pc=0x0c091634u; return 0; }
r[0]=0x00000008u;
goto P_0c091636;
P_0c091636: /* original fe37, guest PC 0x0c091636 */
if(!s->budget--) { s->failed_pc=0x0c091636u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091638;
P_0c091638: /* original c745, guest PC 0x0c091638 */
if(!s->budget--) { s->failed_pc=0x0c091638u; return 0; }
r[0]=code_base|0x00091750u;
goto P_0c09163a;
P_0c09163a: /* original f408, guest PC 0x0c09163a */
if(!s->budget--) { s->failed_pc=0x0c09163au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09163c;
P_0c09163c: /* original 60c3, guest PC 0x0c09163c */
if(!s->budget--) { s->failed_pc=0x0c09163cu; return 0; }
r[0]=r[12];
goto P_0c09163e;
P_0c09163e: /* original 8801, guest PC 0x0c09163e */
if(!s->budget--) { s->failed_pc=0x0c09163eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c091640;
P_0c091640: /* original 8f07, guest PC 0x0c091640 */
if(!s->budget--) { s->failed_pc=0x0c091640u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,14,4);
if(!cond) { goto P_0c091652; }
goto P_0c091644;
P_0c091642: /* original fe4c, guest PC 0x0c091642 */
if(!s->budget--) { s->failed_pc=0x0c091642u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c091644;
P_0c091644: /* original 9080, guest PC 0x0c091644 */
if(!s->budget--) { s->failed_pc=0x0c091644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091748u,2);
goto P_0c091646;
P_0c091646: /* original 63f2, guest PC 0x0c091646 */
if(!s->budget--) { s->failed_pc=0x0c091646u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091648;
P_0c091648: /* original f436, guest PC 0x0c091648 */
if(!s->budget--) { s->failed_pc=0x0c091648u; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c09164a;
P_0c09164a: /* original 907c, guest PC 0x0c09164a */
if(!s->budget--) { s->failed_pc=0x0c09164au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091746u,2);
goto P_0c09164c;
P_0c09164c: /* original f3f6, guest PC 0x0c09164c */
if(!s->budget--) { s->failed_pc=0x0c09164cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09164e;
P_0c09164e: /* original f345, guest PC 0x0c09164e */
if(!s->budget--) { s->failed_pc=0x0c09164eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c091650;
P_0c091650: /* original 8b0e, guest PC 0x0c091650 */
if(!s->budget--) { s->failed_pc=0x0c091650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091670; }
goto P_0c091652;
P_0c091652: /* original 53f7, guest PC 0x0c091652 */
if(!s->budget--) { s->failed_pc=0x0c091652u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c091654;
P_0c091654: /* original e504, guest PC 0x0c091654 */
if(!s->budget--) { s->failed_pc=0x0c091654u; return 0; }
r[5]=0x00000004u;
goto P_0c091656;
P_0c091656: /* original 2358, guest PC 0x0c091656 */
if(!s->budget--) { s->failed_pc=0x0c091656u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c091658;
P_0c091658: /* original 890a, guest PC 0x0c091658 */
if(!s->budget--) { s->failed_pc=0x0c091658u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091670; }
goto P_0c09165a;
P_0c09165a: /* original 2548, guest PC 0x0c09165a */
if(!s->budget--) { s->failed_pc=0x0c09165au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c09165c;
P_0c09165c: /* original 8908, guest PC 0x0c09165c */
if(!s->budget--) { s->failed_pc=0x0c09165cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091670; }
goto P_0c09165e;
P_0c09165e: /* original d53d, guest PC 0x0c09165e */
if(!s->budget--) { s->failed_pc=0x0c09165eu; return 0; }
r[5]=read(ram,0x0c091754u,4);
goto P_0c091660;
P_0c091660: /* original 2458, guest PC 0x0c091660 */
if(!s->budget--) { s->failed_pc=0x0c091660u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c091662;
P_0c091662: /* original 8b05, guest PC 0x0c091662 */
if(!s->budget--) { s->failed_pc=0x0c091662u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091670; }
goto P_0c091664;
P_0c091664: /* original c73c, guest PC 0x0c091664 */
if(!s->budget--) { s->failed_pc=0x0c091664u; return 0; }
r[0]=code_base|0x00091758u;
goto P_0c091666;
P_0c091666: /* original f408, guest PC 0x0c091666 */
if(!s->budget--) { s->failed_pc=0x0c091666u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c091668;
P_0c091668: /* original e004, guest PC 0x0c091668 */
if(!s->budget--) { s->failed_pc=0x0c091668u; return 0; }
r[0]=0x00000004u;
goto P_0c09166a;
P_0c09166a: /* original f3e6, guest PC 0x0c09166a */
if(!s->budget--) { s->failed_pc=0x0c09166au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09166c;
P_0c09166c: /* original f435, guest PC 0x0c09166c */
if(!s->budget--) { s->failed_pc=0x0c09166cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c09166e;
P_0c09166e: /* original 8b00, guest PC 0x0c09166e */
if(!s->budget--) { s->failed_pc=0x0c09166eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091672; }
goto P_0c091670;
P_0c091670: /* original fefc, guest PC 0x0c091670 */
if(!s->budget--) { s->failed_pc=0x0c091670u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c091672;
P_0c091672: /* original 64f3, guest PC 0x0c091672 */
if(!s->budget--) { s->failed_pc=0x0c091672u; return 0; }
r[4]=r[15];
goto P_0c091674;
P_0c091674: /* original d239, guest PC 0x0c091674 */
if(!s->budget--) { s->failed_pc=0x0c091674u; return 0; }
r[2]=read(ram,0x0c09175cu,4);
goto P_0c091676;
P_0c091676: /* original d33a, guest PC 0x0c091676 */
if(!s->budget--) { s->failed_pc=0x0c091676u; return 0; }
r[3]=read(ram,0x0c091760u,4);
goto P_0c091678;
P_0c091678: /* original 7430, guest PC 0x0c091678 */
if(!s->budget--) { s->failed_pc=0x0c091678u; return 0; }
r[4]+=0x00000030u;
goto P_0c09167a;
P_0c09167a: /* original 6143, guest PC 0x0c09167a */
if(!s->budget--) { s->failed_pc=0x0c09167au; return 0; }
r[1]=r[4];
goto P_0c09167c;
P_0c09167c: /* original 430b, guest PC 0x0c09167c */
if(!s->budget--) { s->failed_pc=0x0c09167cu; return 0; }
target=r[3];
r[16]=code_base|0x0c091680u;
r[0]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091680u) { target=s->pc; goto dispatch; }
goto P_0c091680;
P_0c09167e: /* original e00c, guest PC 0x0c09167e */
if(!s->budget--) { s->failed_pc=0x0c09167eu; return 0; }
r[0]=0x0000000cu;
goto P_0c091680;
P_0c091680: /* original 64f3, guest PC 0x0c091680 */
if(!s->budget--) { s->failed_pc=0x0c091680u; return 0; }
r[4]=r[15];
goto P_0c091682;
P_0c091682: /* original d238, guest PC 0x0c091682 */
if(!s->budget--) { s->failed_pc=0x0c091682u; return 0; }
r[2]=read(ram,0x0c091764u,4);
goto P_0c091684;
P_0c091684: /* original d336, guest PC 0x0c091684 */
if(!s->budget--) { s->failed_pc=0x0c091684u; return 0; }
r[3]=read(ram,0x0c091760u,4);
goto P_0c091686;
P_0c091686: /* original 7424, guest PC 0x0c091686 */
if(!s->budget--) { s->failed_pc=0x0c091686u; return 0; }
r[4]+=0x00000024u;
goto P_0c091688;
P_0c091688: /* original 6143, guest PC 0x0c091688 */
if(!s->budget--) { s->failed_pc=0x0c091688u; return 0; }
r[1]=r[4];
goto P_0c09168a;
P_0c09168a: /* original 430b, guest PC 0x0c09168a */
if(!s->budget--) { s->failed_pc=0x0c09168au; return 0; }
target=r[3];
r[16]=code_base|0x0c09168eu;
r[0]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09168eu) { target=s->pc; goto dispatch; }
goto P_0c09168e;
P_0c09168c: /* original e00c, guest PC 0x0c09168c */
if(!s->budget--) { s->failed_pc=0x0c09168cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09168e;
P_0c09168e: /* original d136, guest PC 0x0c09168e */
if(!s->budget--) { s->failed_pc=0x0c09168eu; return 0; }
r[1]=read(ram,0x0c091768u,4);
goto P_0c091690;
P_0c091690: /* original 410b, guest PC 0x0c091690 */
if(!s->budget--) { s->failed_pc=0x0c091690u; return 0; }
target=r[1];
r[16]=code_base|0x0c091694u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091694u) { target=s->pc; goto dispatch; }
goto P_0c091694;
P_0c091692: /* original 0009, guest PC 0x0c091692 */
if(!s->budget--) { s->failed_pc=0x0c091692u; return 0; }
goto P_0c091694;
P_0c091694: /* original d335, guest PC 0x0c091694 */
if(!s->budget--) { s->failed_pc=0x0c091694u; return 0; }
r[3]=read(ram,0x0c09176cu,4);
goto P_0c091696;
P_0c091696: /* original 9458, guest PC 0x0c091696 */
if(!s->budget--) { s->failed_pc=0x0c091696u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09174au,2);
goto P_0c091698;
P_0c091698: /* original 430b, guest PC 0x0c091698 */
if(!s->budget--) { s->failed_pc=0x0c091698u; return 0; }
target=r[3];
r[16]=code_base|0x0c09169cu;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09169cu) { target=s->pc; goto dispatch; }
goto P_0c09169c;
P_0c09169a: /* original 34fc, guest PC 0x0c09169a */
if(!s->budget--) { s->failed_pc=0x0c09169au; return 0; }
r[4]+=r[15];
goto P_0c09169c;
P_0c09169c: /* original 60c3, guest PC 0x0c09169c */
if(!s->budget--) { s->failed_pc=0x0c09169cu; return 0; }
r[0]=r[12];
goto P_0c09169e;
P_0c09169e: /* original 8802, guest PC 0x0c09169e */
if(!s->budget--) { s->failed_pc=0x0c09169eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0916a0;
P_0c0916a0: /* original 8938, guest PC 0x0c0916a0 */
if(!s->budget--) { s->failed_pc=0x0c0916a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091714; }
goto P_0c0916a2;
P_0c0916a2: /* original 60c3, guest PC 0x0c0916a2 */
if(!s->budget--) { s->failed_pc=0x0c0916a2u; return 0; }
r[0]=r[12];
goto P_0c0916a4;
P_0c0916a4: /* original 8808, guest PC 0x0c0916a4 */
if(!s->budget--) { s->failed_pc=0x0c0916a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0916a6;
P_0c0916a6: /* original 8935, guest PC 0x0c0916a6 */
if(!s->budget--) { s->failed_pc=0x0c0916a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091714; }
goto P_0c0916a8;
P_0c0916a8: /* original 60c3, guest PC 0x0c0916a8 */
if(!s->budget--) { s->failed_pc=0x0c0916a8u; return 0; }
r[0]=r[12];
goto P_0c0916aa;
P_0c0916aa: /* original 880b, guest PC 0x0c0916aa */
if(!s->budget--) { s->failed_pc=0x0c0916aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0916ac;
P_0c0916ac: /* original 8932, guest PC 0x0c0916ac */
if(!s->budget--) { s->failed_pc=0x0c0916acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091714; }
goto P_0c0916ae;
P_0c0916ae: /* original 60c3, guest PC 0x0c0916ae */
if(!s->budget--) { s->failed_pc=0x0c0916aeu; return 0; }
r[0]=r[12];
goto P_0c0916b0;
P_0c0916b0: /* original 880e, guest PC 0x0c0916b0 */
if(!s->budget--) { s->failed_pc=0x0c0916b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0916b2;
P_0c0916b2: /* original 892f, guest PC 0x0c0916b2 */
if(!s->budget--) { s->failed_pc=0x0c0916b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091714; }
goto P_0c0916b4;
P_0c0916b4: /* original 60c3, guest PC 0x0c0916b4 */
if(!s->budget--) { s->failed_pc=0x0c0916b4u; return 0; }
r[0]=r[12];
goto P_0c0916b6;
P_0c0916b6: /* original 880f, guest PC 0x0c0916b6 */
if(!s->budget--) { s->failed_pc=0x0c0916b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0916b8;
P_0c0916b8: /* original 892c, guest PC 0x0c0916b8 */
if(!s->budget--) { s->failed_pc=0x0c0916b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091714; }
goto P_0c0916ba;
P_0c0916ba: /* original 64f3, guest PC 0x0c0916ba */
if(!s->budget--) { s->failed_pc=0x0c0916bau; return 0; }
r[4]=r[15];
goto P_0c0916bc;
P_0c0916bc: /* original 1f98, guest PC 0x0c0916bc */
if(!s->budget--) { s->failed_pc=0x0c0916bcu; return 0; }
write(ram,r[15]+32,r[9],4);
goto P_0c0916be;
P_0c0916be: /* original d32c, guest PC 0x0c0916be */
if(!s->budget--) { s->failed_pc=0x0c0916beu; return 0; }
r[3]=read(ram,0x0c091770u,4);
goto P_0c0916c0;
P_0c0916c0: /* original 430b, guest PC 0x0c0916c0 */
if(!s->budget--) { s->failed_pc=0x0c0916c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0916c4u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0916c4u) { target=s->pc; goto dispatch; }
goto P_0c0916c4;
P_0c0916c2: /* original 7448, guest PC 0x0c0916c2 */
if(!s->budget--) { s->failed_pc=0x0c0916c2u; return 0; }
r[4]+=0x00000048u;
goto P_0c0916c4;
P_0c0916c4: /* original e008, guest PC 0x0c0916c4 */
if(!s->budget--) { s->failed_pc=0x0c0916c4u; return 0; }
r[0]=0x00000008u;
goto P_0c0916c6;
P_0c0916c6: /* original f3e6, guest PC 0x0c0916c6 */
if(!s->budget--) { s->failed_pc=0x0c0916c6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0916c8;
P_0c0916c8: /* original f34d, guest PC 0x0c0916c8 */
if(!s->budget--) { s->failed_pc=0x0c0916c8u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0916ca;
P_0c0916ca: /* original fe37, guest PC 0x0c0916ca */
if(!s->budget--) { s->failed_pc=0x0c0916cau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0916cc;
P_0c0916cc: /* original e004, guest PC 0x0c0916cc */
if(!s->budget--) { s->failed_pc=0x0c0916ccu; return 0; }
r[0]=0x00000004u;
goto P_0c0916ce;
P_0c0916ce: /* original f3e6, guest PC 0x0c0916ce */
if(!s->budget--) { s->failed_pc=0x0c0916ceu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0916d0;
P_0c0916d0: /* original e048, guest PC 0x0c0916d0 */
if(!s->budget--) { s->failed_pc=0x0c0916d0u; return 0; }
r[0]=0x00000048u;
goto P_0c0916d2;
P_0c0916d2: /* original ff37, guest PC 0x0c0916d2 */
if(!s->budget--) { s->failed_pc=0x0c0916d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0916d4;
P_0c0916d4: /* original e04c, guest PC 0x0c0916d4 */
if(!s->budget--) { s->failed_pc=0x0c0916d4u; return 0; }
r[0]=0x0000004cu;
goto P_0c0916d6;
P_0c0916d6: /* original f3e8, guest PC 0x0c0916d6 */
if(!s->budget--) { s->failed_pc=0x0c0916d6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0916d8;
P_0c0916d8: /* original f34d, guest PC 0x0c0916d8 */
if(!s->budget--) { s->failed_pc=0x0c0916d8u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0916da;
P_0c0916da: /* original ff37, guest PC 0x0c0916da */
if(!s->budget--) { s->failed_pc=0x0c0916dau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0916dc;
P_0c0916dc: /* original e050, guest PC 0x0c0916dc */
if(!s->budget--) { s->failed_pc=0x0c0916dcu; return 0; }
r[0]=0x00000050u;
goto P_0c0916de;
P_0c0916de: /* original fff7, guest PC 0x0c0916de */
if(!s->budget--) { s->failed_pc=0x0c0916deu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0916e0;
P_0c0916e0: /* original e058, guest PC 0x0c0916e0 */
if(!s->budget--) { s->failed_pc=0x0c0916e0u; return 0; }
r[0]=0x00000058u;
goto P_0c0916e2;
P_0c0916e2: /* original f3e8, guest PC 0x0c0916e2 */
if(!s->budget--) { s->failed_pc=0x0c0916e2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0916e4;
P_0c0916e4: /* original ff37, guest PC 0x0c0916e4 */
if(!s->budget--) { s->failed_pc=0x0c0916e4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0916e6;
P_0c0916e6: /* original e004, guest PC 0x0c0916e6 */
if(!s->budget--) { s->failed_pc=0x0c0916e6u; return 0; }
r[0]=0x00000004u;
goto P_0c0916e8;
P_0c0916e8: /* original f3e6, guest PC 0x0c0916e8 */
if(!s->budget--) { s->failed_pc=0x0c0916e8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0916ea;
P_0c0916ea: /* original e05c, guest PC 0x0c0916ea */
if(!s->budget--) { s->failed_pc=0x0c0916eau; return 0; }
r[0]=0x0000005cu;
goto P_0c0916ec;
P_0c0916ec: /* original ff37, guest PC 0x0c0916ec */
if(!s->budget--) { s->failed_pc=0x0c0916ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0916ee;
P_0c0916ee: /* original e008, guest PC 0x0c0916ee */
if(!s->budget--) { s->failed_pc=0x0c0916eeu; return 0; }
r[0]=0x00000008u;
goto P_0c0916f0;
P_0c0916f0: /* original f3e6, guest PC 0x0c0916f0 */
if(!s->budget--) { s->failed_pc=0x0c0916f0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0916f2;
P_0c0916f2: /* original e060, guest PC 0x0c0916f2 */
if(!s->budget--) { s->failed_pc=0x0c0916f2u; return 0; }
r[0]=0x00000060u;
goto P_0c0916f4;
P_0c0916f4: /* original ff37, guest PC 0x0c0916f4 */
if(!s->budget--) { s->failed_pc=0x0c0916f4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0916f6;
P_0c0916f6: /* original e068, guest PC 0x0c0916f6 */
if(!s->budget--) { s->failed_pc=0x0c0916f6u; return 0; }
r[0]=0x00000068u;
goto P_0c0916f8;
P_0c0916f8: /* original fff7, guest PC 0x0c0916f8 */
if(!s->budget--) { s->failed_pc=0x0c0916f8u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0916fa;
P_0c0916fa: /* original e008, guest PC 0x0c0916fa */
if(!s->budget--) { s->failed_pc=0x0c0916fau; return 0; }
r[0]=0x00000008u;
goto P_0c0916fc;
P_0c0916fc: /* original f3e6, guest PC 0x0c0916fc */
if(!s->budget--) { s->failed_pc=0x0c0916fcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0916fe;
P_0c0916fe: /* original e06c, guest PC 0x0c0916fe */
if(!s->budget--) { s->failed_pc=0x0c0916feu; return 0; }
r[0]=0x0000006cu;
goto P_0c091700;
P_0c091700: /* original f34d, guest PC 0x0c091700 */
if(!s->budget--) { s->failed_pc=0x0c091700u; return 0; }
fr[3]^=0x80000000u;
goto P_0c091702;
P_0c091702: /* original ff37, guest PC 0x0c091702 */
if(!s->budget--) { s->failed_pc=0x0c091702u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c091704;
P_0c091704: /* original e004, guest PC 0x0c091704 */
if(!s->budget--) { s->failed_pc=0x0c091704u; return 0; }
r[0]=0x00000004u;
goto P_0c091706;
P_0c091706: /* original 64f3, guest PC 0x0c091706 */
if(!s->budget--) { s->failed_pc=0x0c091706u; return 0; }
r[4]=r[15];
goto P_0c091708;
P_0c091708: /* original f3e6, guest PC 0x0c091708 */
if(!s->budget--) { s->failed_pc=0x0c091708u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09170a;
P_0c09170a: /* original e070, guest PC 0x0c09170a */
if(!s->budget--) { s->failed_pc=0x0c09170au; return 0; }
r[0]=0x00000070u;
goto P_0c09170c;
P_0c09170c: /* original ff37, guest PC 0x0c09170c */
if(!s->budget--) { s->failed_pc=0x0c09170cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09170e;
P_0c09170e: /* original d319, guest PC 0x0c09170e */
if(!s->budget--) { s->failed_pc=0x0c09170eu; return 0; }
r[3]=read(ram,0x0c091774u,4);
goto P_0c091710;
P_0c091710: /* original 430b, guest PC 0x0c091710 */
if(!s->budget--) { s->failed_pc=0x0c091710u; return 0; }
target=r[3];
r[16]=code_base|0x0c091714u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091714u) { target=s->pc; goto dispatch; }
goto P_0c091714;
P_0c091712: /* original 7448, guest PC 0x0c091712 */
if(!s->budget--) { s->failed_pc=0x0c091712u; return 0; }
r[4]+=0x00000048u;
goto P_0c091714;
P_0c091714: /* original 901a, guest PC 0x0c091714 */
if(!s->budget--) { s->failed_pc=0x0c091714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09174cu,2);
goto P_0c091716;
P_0c091716: /* original d318, guest PC 0x0c091716 */
if(!s->budget--) { s->failed_pc=0x0c091716u; return 0; }
r[3]=read(ram,0x0c091778u,4);
goto P_0c091718;
P_0c091718: /* original f6f6, guest PC 0x0c091718 */
if(!s->budget--) { s->failed_pc=0x0c091718u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09171a;
P_0c09171a: /* original 9016, guest PC 0x0c09171a */
if(!s->budget--) { s->failed_pc=0x0c09171au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09174au,2);
goto P_0c09171c;
P_0c09171c: /* original f64d, guest PC 0x0c09171c */
if(!s->budget--) { s->failed_pc=0x0c09171cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c09171e;
P_0c09171e: /* original f4f6, guest PC 0x0c09171e */
if(!s->budget--) { s->failed_pc=0x0c09171eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c091720;
P_0c091720: /* original f5fc, guest PC 0x0c091720 */
if(!s->budget--) { s->failed_pc=0x0c091720u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091722;
P_0c091722: /* original 430b, guest PC 0x0c091722 */
if(!s->budget--) { s->failed_pc=0x0c091722u; return 0; }
target=r[3];
r[16]=code_base|0x0c091726u;
fr[4]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091726u) { target=s->pc; goto dispatch; }
goto P_0c091726;
P_0c091724: /* original f44d, guest PC 0x0c091724 */
if(!s->budget--) { s->failed_pc=0x0c091724u; return 0; }
fr[4]^=0x80000000u;
goto P_0c091726;
P_0c091726: /* original 4a0b, guest PC 0x0c091726 */
if(!s->budget--) { s->failed_pc=0x0c091726u; return 0; }
target=r[10];
r[16]=code_base|0x0c09172au;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09172au) { target=s->pc; goto dispatch; }
goto P_0c09172a;
P_0c091728: /* original 54f5, guest PC 0x0c091728 */
if(!s->budget--) { s->failed_pc=0x0c091728u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c09172a;
P_0c09172a: /* original 9410, guest PC 0x0c09172a */
if(!s->budget--) { s->failed_pc=0x0c09172au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09174eu,2);
goto P_0c09172c;
P_0c09172c: /* original 4b0b, guest PC 0x0c09172c */
if(!s->budget--) { s->failed_pc=0x0c09172cu; return 0; }
target=r[11];
r[16]=code_base|0x0c091730u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091730u) { target=s->pc; goto dispatch; }
goto P_0c091730;
P_0c09172e: /* original 34fc, guest PC 0x0c09172e */
if(!s->budget--) { s->failed_pc=0x0c09172eu; return 0; }
r[4]+=r[15];
goto P_0c091730;
P_0c091730: /* original 4a0b, guest PC 0x0c091730 */
if(!s->budget--) { s->failed_pc=0x0c091730u; return 0; }
target=r[10];
r[16]=code_base|0x0c091734u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091734u) { target=s->pc; goto dispatch; }
goto P_0c091734;
P_0c091732: /* original 54f2, guest PC 0x0c091732 */
if(!s->budget--) { s->failed_pc=0x0c091732u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c091734;
P_0c091734: /* original 4b0b, guest PC 0x0c091734 */
if(!s->budget--) { s->failed_pc=0x0c091734u; return 0; }
target=r[11];
r[16]=code_base|0x0c091738u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091738u) { target=s->pc; goto dispatch; }
goto P_0c091738;
P_0c091736: /* original 6483, guest PC 0x0c091736 */
if(!s->budget--) { s->failed_pc=0x0c091736u; return 0; }
r[4]=r[8];
goto P_0c091738;
P_0c091738: /* original db10, guest PC 0x0c091738 */
if(!s->budget--) { s->failed_pc=0x0c091738u; return 0; }
r[11]=read(ram,0x0c09177cu,4);
goto P_0c09173a;
P_0c09173a: /* original f5ec, guest PC 0x0c09173a */
if(!s->budget--) { s->failed_pc=0x0c09173au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c09173c;
P_0c09173c: /* original f6ec, guest PC 0x0c09173c */
if(!s->budget--) { s->failed_pc=0x0c09173cu; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c09173e;
P_0c09173e: /* original 4b0b, guest PC 0x0c09173e */
if(!s->budget--) { s->failed_pc=0x0c09173eu; return 0; }
target=r[11];
r[16]=code_base|0x0c091742u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091742u) { target=s->pc; goto dispatch; }
goto P_0c091742;
P_0c091740: /* original f4ec, guest PC 0x0c091740 */
if(!s->budget--) { s->failed_pc=0x0c091740u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c091742;
P_0c091742: /* original a01d, guest PC 0x0c091742 */
if(!s->budget--) { s->failed_pc=0x0c091742u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c091780;
P_0c091744: /* original 54f1, guest PC 0x0c091744 */
if(!s->budget--) { s->failed_pc=0x0c091744u; return 0; }
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(0x0c091746u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091746u; return 0; } return 1;
P_0c091780: /* original d31b, guest PC 0x0c091780 */
if(!s->budget--) { s->failed_pc=0x0c091780u; return 0; }
r[3]=read(ram,0x0c0917f0u,4);
goto P_0c091782;
P_0c091782: /* original 430b, guest PC 0x0c091782 */
if(!s->budget--) { s->failed_pc=0x0c091782u; return 0; }
target=r[3];
r[16]=code_base|0x0c091786u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091786u) { target=s->pc; goto dispatch; }
goto P_0c091786;
P_0c091784: /* original 0009, guest PC 0x0c091784 */
if(!s->budget--) { s->failed_pc=0x0c091784u; return 0; }
goto P_0c091786;
P_0c091786: /* original 50f8, guest PC 0x0c091786 */
if(!s->budget--) { s->failed_pc=0x0c091786u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c091788;
P_0c091788: /* original 8801, guest PC 0x0c091788 */
if(!s->budget--) { s->failed_pc=0x0c091788u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09178a;
P_0c09178a: /* original 8f08, guest PC 0x0c09178a */
if(!s->budget--) { s->failed_pc=0x0c09178au; return 0; }
cond=r[17]&1u;
r[8]+=0x0000000cu;
if(!cond) { goto P_0c09179e; }
goto P_0c09178e;
P_0c09178c: /* original 780c, guest PC 0x0c09178c */
if(!s->budget--) { s->failed_pc=0x0c09178cu; return 0; }
r[8]+=0x0000000cu;
goto P_0c09178e;
P_0c09178e: /* original c719, guest PC 0x0c09178e */
if(!s->budget--) { s->failed_pc=0x0c09178eu; return 0; }
r[0]=code_base|0x000917f4u;
goto P_0c091790;
P_0c091790: /* original 53f1, guest PC 0x0c091790 */
if(!s->budget--) { s->failed_pc=0x0c091790u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c091792;
P_0c091792: /* original f408, guest PC 0x0c091792 */
if(!s->budget--) { s->failed_pc=0x0c091792u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c091794;
P_0c091794: /* original 9029, guest PC 0x0c091794 */
if(!s->budget--) { s->failed_pc=0x0c091794u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0917eau,2);
goto P_0c091796;
P_0c091796: /* original f3f6, guest PC 0x0c091796 */
if(!s->budget--) { s->failed_pc=0x0c091796u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c091798;
P_0c091798: /* original e034, guest PC 0x0c091798 */
if(!s->budget--) { s->failed_pc=0x0c091798u; return 0; }
r[0]=0x00000034u;
goto P_0c09179a;
P_0c09179a: /* original f340, guest PC 0x0c09179a */
if(!s->budget--) { s->failed_pc=0x0c09179au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c09179c;
P_0c09179c: /* original f337, guest PC 0x0c09179c */
if(!s->budget--) { s->failed_pc=0x0c09179cu; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c09179e;
P_0c09179e: /* original 54f6, guest PC 0x0c09179e */
if(!s->budget--) { s->failed_pc=0x0c09179eu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0917a0;
P_0c0917a0: /* original 7d14, guest PC 0x0c0917a0 */
if(!s->budget--) { s->failed_pc=0x0c0917a0u; return 0; }
r[13]+=0x00000014u;
goto P_0c0917a2;
P_0c0917a2: /* original 7401, guest PC 0x0c0917a2 */
if(!s->budget--) { s->failed_pc=0x0c0917a2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0917a4;
P_0c0917a4: /* original 1f46, guest PC 0x0c0917a4 */
if(!s->budget--) { s->failed_pc=0x0c0917a4u; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c0917a6;
P_0c0917a6: /* original 74ff, guest PC 0x0c0917a6 */
if(!s->budget--) { s->failed_pc=0x0c0917a6u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0917a8;
P_0c0917a8: /* original 6440, guest PC 0x0c0917a8 */
if(!s->budget--) { s->failed_pc=0x0c0917a8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0917aa;
P_0c0917aa: /* original 53f2, guest PC 0x0c0917aa */
if(!s->budget--) { s->failed_pc=0x0c0917aau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0917ac;
P_0c0917ac: /* original 644c, guest PC 0x0c0917ac */
if(!s->budget--) { s->failed_pc=0x0c0917acu; return 0; }
r[4]=r[4]&255u;
goto P_0c0917ae;
P_0c0917ae: /* original 343c, guest PC 0x0c0917ae */
if(!s->budget--) { s->failed_pc=0x0c0917aeu; return 0; }
r[4]+=r[3];
goto P_0c0917b0;
P_0c0917b0: /* original 1f42, guest PC 0x0c0917b0 */
if(!s->budget--) { s->failed_pc=0x0c0917b0u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0917b2;
P_0c0917b2: /* original 53f1, guest PC 0x0c0917b2 */
if(!s->budget--) { s->failed_pc=0x0c0917b2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0917b4;
P_0c0917b4: /* original 7340, guest PC 0x0c0917b4 */
if(!s->budget--) { s->failed_pc=0x0c0917b4u; return 0; }
r[3]+=0x00000040u;
goto P_0c0917b6;
P_0c0917b6: /* original 1f31, guest PC 0x0c0917b6 */
if(!s->budget--) { s->failed_pc=0x0c0917b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0917b8;
P_0c0917b8: /* original 52f4, guest PC 0x0c0917b8 */
if(!s->budget--) { s->failed_pc=0x0c0917b8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0917ba;
P_0c0917ba: /* original 72ff, guest PC 0x0c0917ba */
if(!s->budget--) { s->failed_pc=0x0c0917bau; return 0; }
r[2]+=0xffffffffu;
goto P_0c0917bc;
P_0c0917bc: /* original 1f24, guest PC 0x0c0917bc */
if(!s->budget--) { s->failed_pc=0x0c0917bcu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0917be;
P_0c0917be: /* original 51f4, guest PC 0x0c0917be */
if(!s->budget--) { s->failed_pc=0x0c0917beu; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0917c0;
P_0c0917c0: /* original e300, guest PC 0x0c0917c0 */
if(!s->budget--) { s->failed_pc=0x0c0917c0u; return 0; }
r[3]=0x00000000u;
goto P_0c0917c2;
P_0c0917c2: /* original 3136, guest PC 0x0c0917c2 */
if(!s->budget--) { s->failed_pc=0x0c0917c2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0917c4;
P_0c0917c4: /* original 8b01, guest PC 0x0c0917c4 */
if(!s->budget--) { s->failed_pc=0x0c0917c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0917ca; }
goto P_0c0917c6;
P_0c0917c6: /* original aee3, guest PC 0x0c0917c6 */
if(!s->budget--) { s->failed_pc=0x0c0917c6u; return 0; }
goto P_0c091590;
P_0c0917c8: /* original 0009, guest PC 0x0c0917c8 */
if(!s->budget--) { s->failed_pc=0x0c0917c8u; return 0; }
goto P_0c0917ca;
P_0c0917ca: /* original d30b, guest PC 0x0c0917ca */
if(!s->budget--) { s->failed_pc=0x0c0917cau; return 0; }
r[3]=read(ram,0x0c0917f8u,4);
goto P_0c0917cc;
P_0c0917cc: /* original 430b, guest PC 0x0c0917cc */
if(!s->budget--) { s->failed_pc=0x0c0917ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0917d0u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0917d0u) { target=s->pc; goto dispatch; }
goto P_0c0917d0;
P_0c0917ce: /* original e401, guest PC 0x0c0917ce */
if(!s->budget--) { s->failed_pc=0x0c0917ceu; return 0; }
r[4]=0x00000001u;
goto P_0c0917d0;
P_0c0917d0: /* original 910c, guest PC 0x0c0917d0 */
if(!s->budget--) { s->failed_pc=0x0c0917d0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0917ecu,2);
goto P_0c0917d2;
P_0c0917d2: /* original 3f1c, guest PC 0x0c0917d2 */
if(!s->budget--) { s->failed_pc=0x0c0917d2u; return 0; }
r[15]+=r[1];
goto P_0c0917d4;
P_0c0917d4: /* original 4f26, guest PC 0x0c0917d4 */
if(!s->budget--) { s->failed_pc=0x0c0917d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0917d6;
P_0c0917d6: /* original fef9, guest PC 0x0c0917d6 */
if(!s->budget--) { s->failed_pc=0x0c0917d6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0917d8;
P_0c0917d8: /* original fff9, guest PC 0x0c0917d8 */
if(!s->budget--) { s->failed_pc=0x0c0917d8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0917da;
P_0c0917da: /* original 68f6, guest PC 0x0c0917da */
if(!s->budget--) { s->failed_pc=0x0c0917dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0917dc;
P_0c0917dc: /* original 69f6, guest PC 0x0c0917dc */
if(!s->budget--) { s->failed_pc=0x0c0917dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0917de;
P_0c0917de: /* original 6af6, guest PC 0x0c0917de */
if(!s->budget--) { s->failed_pc=0x0c0917deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0917e0;
P_0c0917e0: /* original 6bf6, guest PC 0x0c0917e0 */
if(!s->budget--) { s->failed_pc=0x0c0917e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0917e2;
P_0c0917e2: /* original 6cf6, guest PC 0x0c0917e2 */
if(!s->budget--) { s->failed_pc=0x0c0917e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0917e4;
P_0c0917e4: /* original 6df6, guest PC 0x0c0917e4 */
if(!s->budget--) { s->failed_pc=0x0c0917e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0917e6;
P_0c0917e6: /* original 000b, guest PC 0x0c0917e6 */
if(!s->budget--) { s->failed_pc=0x0c0917e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0917e8: /* original 6ef6, guest PC 0x0c0917e8 */
if(!s->budget--) { s->failed_pc=0x0c0917e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0917eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0917eau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
