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
int vf3_away_batch210_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0b12acu: goto P_0c0b12ac;
case 0x0c0b12aeu: goto P_0c0b12ae;
case 0x0c0b12b0u: goto P_0c0b12b0;
case 0x0c0b12d4u: goto P_0c0b12d4;
case 0x0c0b12d6u: goto P_0c0b12d6;
case 0x0c0b12d8u: goto P_0c0b12d8;
case 0x0c0b12dau: goto P_0c0b12da;
case 0x0c0b12dcu: goto P_0c0b12dc;
case 0x0c0b12deu: goto P_0c0b12de;
case 0x0c0b12e0u: goto P_0c0b12e0;
case 0x0c0b12e2u: goto P_0c0b12e2;
case 0x0c0b12e4u: goto P_0c0b12e4;
case 0x0c0b12e6u: goto P_0c0b12e6;
case 0x0c0b12e8u: goto P_0c0b12e8;
case 0x0c0b12eau: goto P_0c0b12ea;
case 0x0c0b12ecu: goto P_0c0b12ec;
case 0x0c0b12eeu: goto P_0c0b12ee;
case 0x0c0b12f0u: goto P_0c0b12f0;
case 0x0c0b12f2u: goto P_0c0b12f2;
case 0x0c0b12f4u: goto P_0c0b12f4;
case 0x0c0b12f6u: goto P_0c0b12f6;
case 0x0c0b12f8u: goto P_0c0b12f8;
case 0x0c0b12fau: goto P_0c0b12fa;
case 0x0c0b12fcu: goto P_0c0b12fc;
case 0x0c0b12feu: goto P_0c0b12fe;
case 0x0c0b1300u: goto P_0c0b1300;
case 0x0c0b1302u: goto P_0c0b1302;
case 0x0c0b1304u: goto P_0c0b1304;
case 0x0c0b1306u: goto P_0c0b1306;
case 0x0c0b1308u: goto P_0c0b1308;
case 0x0c0b130au: goto P_0c0b130a;
case 0x0c0b130cu: goto P_0c0b130c;
case 0x0c0b130eu: goto P_0c0b130e;
case 0x0c0b1310u: goto P_0c0b1310;
case 0x0c0b1312u: goto P_0c0b1312;
case 0x0c0b1314u: goto P_0c0b1314;
case 0x0c0b1316u: goto P_0c0b1316;
case 0x0c0b1318u: goto P_0c0b1318;
case 0x0c0b131au: goto P_0c0b131a;
case 0x0c0b131cu: goto P_0c0b131c;
case 0x0c0b131eu: goto P_0c0b131e;
case 0x0c0b1320u: goto P_0c0b1320;
case 0x0c0b1322u: goto P_0c0b1322;
case 0x0c0b1324u: goto P_0c0b1324;
case 0x0c0b1326u: goto P_0c0b1326;
case 0x0c0b1328u: goto P_0c0b1328;
case 0x0c0b132au: goto P_0c0b132a;
case 0x0c0b132cu: goto P_0c0b132c;
case 0x0c0b132eu: goto P_0c0b132e;
case 0x0c0b1330u: goto P_0c0b1330;
case 0x0c0b1332u: goto P_0c0b1332;
case 0x0c0b1334u: goto P_0c0b1334;
case 0x0c0b1336u: goto P_0c0b1336;
case 0x0c0b1464u: goto P_0c0b1464;
case 0x0c0b1466u: goto P_0c0b1466;
case 0x0c0b1468u: goto P_0c0b1468;
case 0x0c0b146au: goto P_0c0b146a;
case 0x0c0b146cu: goto P_0c0b146c;
case 0x0c0b146eu: goto P_0c0b146e;
case 0x0c0b1470u: goto P_0c0b1470;
case 0x0c0b1472u: goto P_0c0b1472;
case 0x0c0b1474u: goto P_0c0b1474;
case 0x0c0b1476u: goto P_0c0b1476;
case 0x0c0b1478u: goto P_0c0b1478;
case 0x0c0b147au: goto P_0c0b147a;
case 0x0c0b147cu: goto P_0c0b147c;
case 0x0c0b147eu: goto P_0c0b147e;
case 0x0c0b1480u: goto P_0c0b1480;
case 0x0c0b1482u: goto P_0c0b1482;
case 0x0c0b1484u: goto P_0c0b1484;
case 0x0c0b1486u: goto P_0c0b1486;
case 0x0c0b1488u: goto P_0c0b1488;
case 0x0c0b148au: goto P_0c0b148a;
case 0x0c0b148cu: goto P_0c0b148c;
case 0x0c0b148eu: goto P_0c0b148e;
case 0x0c0b1490u: goto P_0c0b1490;
case 0x0c0b1492u: goto P_0c0b1492;
case 0x0c0b1494u: goto P_0c0b1494;
case 0x0c0b1496u: goto P_0c0b1496;
case 0x0c0b1498u: goto P_0c0b1498;
case 0x0c0b149au: goto P_0c0b149a;
case 0x0c0b149cu: goto P_0c0b149c;
case 0x0c0b149eu: goto P_0c0b149e;
case 0x0c0b14a0u: goto P_0c0b14a0;
case 0x0c0b14a2u: goto P_0c0b14a2;
case 0x0c0b14a4u: goto P_0c0b14a4;
case 0x0c0b14a6u: goto P_0c0b14a6;
case 0x0c0b14a8u: goto P_0c0b14a8;
case 0x0c0b14aau: goto P_0c0b14aa;
case 0x0c0b14acu: goto P_0c0b14ac;
case 0x0c0b14aeu: goto P_0c0b14ae;
case 0x0c0b14b0u: goto P_0c0b14b0;
case 0x0c0b14b2u: goto P_0c0b14b2;
case 0x0c0b14b4u: goto P_0c0b14b4;
case 0x0c0b14b6u: goto P_0c0b14b6;
case 0x0c0b14b8u: goto P_0c0b14b8;
case 0x0c0b14bau: goto P_0c0b14ba;
case 0x0c0b14bcu: goto P_0c0b14bc;
case 0x0c0b14beu: goto P_0c0b14be;
case 0x0c0b14c0u: goto P_0c0b14c0;
case 0x0c0b14c2u: goto P_0c0b14c2;
case 0x0c0b14c4u: goto P_0c0b14c4;
case 0x0c0b14c6u: goto P_0c0b14c6;
case 0x0c0b14c8u: goto P_0c0b14c8;
case 0x0c0b14cau: goto P_0c0b14ca;
case 0x0c0b14ccu: goto P_0c0b14cc;
case 0x0c0b14ceu: goto P_0c0b14ce;
case 0x0c0b14d0u: goto P_0c0b14d0;
case 0x0c0b14d2u: goto P_0c0b14d2;
case 0x0c0b14d4u: goto P_0c0b14d4;
case 0x0c0b14d6u: goto P_0c0b14d6;
case 0x0c0b14d8u: goto P_0c0b14d8;
case 0x0c0b14dau: goto P_0c0b14da;
case 0x0c0b14dcu: goto P_0c0b14dc;
case 0x0c0b14deu: goto P_0c0b14de;
case 0x0c0b14e0u: goto P_0c0b14e0;
case 0x0c0b14e2u: goto P_0c0b14e2;
case 0x0c0b14e4u: goto P_0c0b14e4;
case 0x0c0b14e6u: goto P_0c0b14e6;
case 0x0c0b14e8u: goto P_0c0b14e8;
case 0x0c0b14eau: goto P_0c0b14ea;
case 0x0c0b14ecu: goto P_0c0b14ec;
case 0x0c0b14eeu: goto P_0c0b14ee;
case 0x0c0b14f0u: goto P_0c0b14f0;
case 0x0c0b14f2u: goto P_0c0b14f2;
case 0x0c0b14f4u: goto P_0c0b14f4;
case 0x0c0b14f6u: goto P_0c0b14f6;
case 0x0c0b14f8u: goto P_0c0b14f8;
case 0x0c0b14fau: goto P_0c0b14fa;
case 0x0c0b14fcu: goto P_0c0b14fc;
case 0x0c0b14feu: goto P_0c0b14fe;
case 0x0c0b1500u: goto P_0c0b1500;
case 0x0c0b1502u: goto P_0c0b1502;
case 0x0c0b1504u: goto P_0c0b1504;
case 0x0c0b1506u: goto P_0c0b1506;
case 0x0c0b1508u: goto P_0c0b1508;
case 0x0c0b150au: goto P_0c0b150a;
case 0x0c0b150cu: goto P_0c0b150c;
case 0x0c0b150eu: goto P_0c0b150e;
case 0x0c0b1510u: goto P_0c0b1510;
case 0x0c0b1512u: goto P_0c0b1512;
case 0x0c0b1514u: goto P_0c0b1514;
case 0x0c0b1516u: goto P_0c0b1516;
case 0x0c0b1518u: goto P_0c0b1518;
case 0x0c0b151au: goto P_0c0b151a;
case 0x0c0b151cu: goto P_0c0b151c;
case 0x0c0b151eu: goto P_0c0b151e;
case 0x0c0bfee2u: goto P_0c0bfee2;
case 0x0c0bfee4u: goto P_0c0bfee4;
case 0x0c0bfee6u: goto P_0c0bfee6;
case 0x0c0bfee8u: goto P_0c0bfee8;
case 0x0c0bfeeau: goto P_0c0bfeea;
case 0x0c0bfeecu: goto P_0c0bfeec;
case 0x0c0bfeeeu: goto P_0c0bfeee;
case 0x0c0bfef0u: goto P_0c0bfef0;
case 0x0c0bfef2u: goto P_0c0bfef2;
case 0x0c0bfef4u: goto P_0c0bfef4;
case 0x0c0bfef6u: goto P_0c0bfef6;
case 0x0c0bfef8u: goto P_0c0bfef8;
case 0x0c0bfefau: goto P_0c0bfefa;
case 0x0c0bfefcu: goto P_0c0bfefc;
case 0x0c0bfefeu: goto P_0c0bfefe;
case 0x0c0bff00u: goto P_0c0bff00;
case 0x0c0bff02u: goto P_0c0bff02;
case 0x0c0bff04u: goto P_0c0bff04;
case 0x0c0bff06u: goto P_0c0bff06;
case 0x0c0bff08u: goto P_0c0bff08;
case 0x0c0bff0au: goto P_0c0bff0a;
case 0x0c0bff0cu: goto P_0c0bff0c;
case 0x0c0bff0eu: goto P_0c0bff0e;
case 0x0c0bff10u: goto P_0c0bff10;
case 0x0c0bff12u: goto P_0c0bff12;
case 0x0c0bff14u: goto P_0c0bff14;
case 0x0c0bff16u: goto P_0c0bff16;
case 0x0c0bff18u: goto P_0c0bff18;
case 0x0c0bff1au: goto P_0c0bff1a;
case 0x0c0bff1cu: goto P_0c0bff1c;
case 0x0c0bff1eu: goto P_0c0bff1e;
case 0x0c0bff20u: goto P_0c0bff20;
case 0x0c0bff22u: goto P_0c0bff22;
case 0x0c0bff24u: goto P_0c0bff24;
case 0x0c0bff4cu: goto P_0c0bff4c;
case 0x0c0bff4eu: goto P_0c0bff4e;
case 0x0c0bff50u: goto P_0c0bff50;
case 0x0c0bff52u: goto P_0c0bff52;
case 0x0c0bff54u: goto P_0c0bff54;
case 0x0c0bff56u: goto P_0c0bff56;
case 0x0c0bff58u: goto P_0c0bff58;
case 0x0c0bff5au: goto P_0c0bff5a;
case 0x0c0bff5cu: goto P_0c0bff5c;
case 0x0c0bff5eu: goto P_0c0bff5e;
case 0x0c0bff60u: goto P_0c0bff60;
case 0x0c0bff62u: goto P_0c0bff62;
case 0x0c0bff64u: goto P_0c0bff64;
case 0x0c0bff66u: goto P_0c0bff66;
case 0x0c0bff68u: goto P_0c0bff68;
case 0x0c0bff6au: goto P_0c0bff6a;
case 0x0c0bff6cu: goto P_0c0bff6c;
case 0x0c0bff6eu: goto P_0c0bff6e;
case 0x0c0bff70u: goto P_0c0bff70;
case 0x0c0bff72u: goto P_0c0bff72;
case 0x0c0bff74u: goto P_0c0bff74;
case 0x0c0bff76u: goto P_0c0bff76;
case 0x0c0bff78u: goto P_0c0bff78;
case 0x0c0bff7au: goto P_0c0bff7a;
case 0x0c0bff7cu: goto P_0c0bff7c;
case 0x0c0bff7eu: goto P_0c0bff7e;
case 0x0c0bff80u: goto P_0c0bff80;
case 0x0c0bff82u: goto P_0c0bff82;
case 0x0c0bff84u: goto P_0c0bff84;
case 0x0c0bff86u: goto P_0c0bff86;
case 0x0c0bff88u: goto P_0c0bff88;
case 0x0c0bff8au: goto P_0c0bff8a;
case 0x0c0bff8cu: goto P_0c0bff8c;
case 0x0c0bff8eu: goto P_0c0bff8e;
case 0x0c0bff90u: goto P_0c0bff90;
case 0x0c0bff92u: goto P_0c0bff92;
case 0x0c0bff94u: goto P_0c0bff94;
case 0x0c0bff96u: goto P_0c0bff96;
case 0x0c0bff98u: goto P_0c0bff98;
case 0x0c0bff9au: goto P_0c0bff9a;
case 0x0c0bff9cu: goto P_0c0bff9c;
case 0x0c0bff9eu: goto P_0c0bff9e;
case 0x0c0bffa0u: goto P_0c0bffa0;
case 0x0c0bffa2u: goto P_0c0bffa2;
case 0x0c0bffa4u: goto P_0c0bffa4;
case 0x0c0bffa6u: goto P_0c0bffa6;
case 0x0c0bffa8u: goto P_0c0bffa8;
case 0x0c0bffaau: goto P_0c0bffaa;
case 0x0c0bffacu: goto P_0c0bffac;
case 0x0c0bffaeu: goto P_0c0bffae;
case 0x0c0bffb0u: goto P_0c0bffb0;
case 0x0c0bffb2u: goto P_0c0bffb2;
case 0x0c0bffb4u: goto P_0c0bffb4;
case 0x0c0bffb6u: goto P_0c0bffb6;
case 0x0c0bffb8u: goto P_0c0bffb8;
case 0x0c0bffbau: goto P_0c0bffba;
case 0x0c0bffbcu: goto P_0c0bffbc;
case 0x0c0bffbeu: goto P_0c0bffbe;
case 0x0c0bffc0u: goto P_0c0bffc0;
case 0x0c0bffc2u: goto P_0c0bffc2;
case 0x0c0bffc4u: goto P_0c0bffc4;
case 0x0c0bffc6u: goto P_0c0bffc6;
case 0x0c0bffc8u: goto P_0c0bffc8;
case 0x0c0bffcau: goto P_0c0bffca;
case 0x0c0bffccu: goto P_0c0bffcc;
case 0x0c0bffceu: goto P_0c0bffce;
case 0x0c0bffd0u: goto P_0c0bffd0;
case 0x0c0bffd2u: goto P_0c0bffd2;
case 0x0c0bffd4u: goto P_0c0bffd4;
case 0x0c0bffd6u: goto P_0c0bffd6;
case 0x0c0bffd8u: goto P_0c0bffd8;
case 0x0c0bffdau: goto P_0c0bffda;
case 0x0c0bffdcu: goto P_0c0bffdc;
case 0x0c0bffdeu: goto P_0c0bffde;
case 0x0c0bffe0u: goto P_0c0bffe0;
case 0x0c0bffe2u: goto P_0c0bffe2;
case 0x0c0bffe4u: goto P_0c0bffe4;
case 0x0c0bffe6u: goto P_0c0bffe6;
case 0x0c0bffe8u: goto P_0c0bffe8;
case 0x0c0bffeau: goto P_0c0bffea;
case 0x0c0bffecu: goto P_0c0bffec;
case 0x0c0bffeeu: goto P_0c0bffee;
case 0x0c0bfff0u: goto P_0c0bfff0;
case 0x0c0bfff2u: goto P_0c0bfff2;
case 0x0c0bfff4u: goto P_0c0bfff4;
case 0x0c0bfff6u: goto P_0c0bfff6;
case 0x0c0bfff8u: goto P_0c0bfff8;
case 0x0c0bfffau: goto P_0c0bfffa;
case 0x0c0bfffcu: goto P_0c0bfffc;
case 0x0c0bfffeu: goto P_0c0bfffe;
case 0x0c0c0000u: goto P_0c0c0000;
case 0x0c0c0002u: goto P_0c0c0002;
case 0x0c0c0004u: goto P_0c0c0004;
case 0x0c0c0006u: goto P_0c0c0006;
case 0x0c0c0008u: goto P_0c0c0008;
case 0x0c0c000au: goto P_0c0c000a;
case 0x0c0c000cu: goto P_0c0c000c;
case 0x0c0c000eu: goto P_0c0c000e;
case 0x0c0c0010u: goto P_0c0c0010;
case 0x0c0c0012u: goto P_0c0c0012;
case 0x0c0c0014u: goto P_0c0c0014;
case 0x0c0c0016u: goto P_0c0c0016;
case 0x0c0c0018u: goto P_0c0c0018;
case 0x0c0c001au: goto P_0c0c001a;
case 0x0c0c001cu: goto P_0c0c001c;
case 0x0c0c001eu: goto P_0c0c001e;
case 0x0c0c0020u: goto P_0c0c0020;
case 0x0c0c0022u: goto P_0c0c0022;
case 0x0c0c0024u: goto P_0c0c0024;
case 0x0c0c0026u: goto P_0c0c0026;
case 0x0c0c0028u: goto P_0c0c0028;
case 0x0c0c002au: goto P_0c0c002a;
case 0x0c0c002cu: goto P_0c0c002c;
case 0x0c0c002eu: goto P_0c0c002e;
case 0x0c0c0030u: goto P_0c0c0030;
case 0x0c0c0032u: goto P_0c0c0032;
case 0x0c0c0034u: goto P_0c0c0034;
case 0x0c0c0036u: goto P_0c0c0036;
case 0x0c0c0038u: goto P_0c0c0038;
case 0x0c0c003au: goto P_0c0c003a;
case 0x0c0c003cu: goto P_0c0c003c;
case 0x0c0c003eu: goto P_0c0c003e;
case 0x0c0c0040u: goto P_0c0c0040;
case 0x0c0c0042u: goto P_0c0c0042;
case 0x0c0c0044u: goto P_0c0c0044;
case 0x0c0c0046u: goto P_0c0c0046;
case 0x0c0c0048u: goto P_0c0c0048;
case 0x0c0c0080u: goto P_0c0c0080;
case 0x0c0c0082u: goto P_0c0c0082;
case 0x0c0c0084u: goto P_0c0c0084;
case 0x0c0c0086u: goto P_0c0c0086;
case 0x0c0c0088u: goto P_0c0c0088;
case 0x0c0c008au: goto P_0c0c008a;
case 0x0c0c008cu: goto P_0c0c008c;
case 0x0c0c008eu: goto P_0c0c008e;
case 0x0c0c0090u: goto P_0c0c0090;
case 0x0c0c0092u: goto P_0c0c0092;
case 0x0c0c0094u: goto P_0c0c0094;
case 0x0c0c0096u: goto P_0c0c0096;
case 0x0c0c0098u: goto P_0c0c0098;
case 0x0c0c009au: goto P_0c0c009a;
case 0x0c0c009cu: goto P_0c0c009c;
case 0x0c0c009eu: goto P_0c0c009e;
case 0x0c0c00a0u: goto P_0c0c00a0;
case 0x0c0c00a2u: goto P_0c0c00a2;
case 0x0c0c00a4u: goto P_0c0c00a4;
case 0x0c0c00a6u: goto P_0c0c00a6;
case 0x0c0c00a8u: goto P_0c0c00a8;
case 0x0c0c00aau: goto P_0c0c00aa;
case 0x0c0c00acu: goto P_0c0c00ac;
case 0x0c0c00aeu: goto P_0c0c00ae;
case 0x0c0c00b0u: goto P_0c0c00b0;
case 0x0c0c00b2u: goto P_0c0c00b2;
case 0x0c0c00b4u: goto P_0c0c00b4;
case 0x0c0c00b6u: goto P_0c0c00b6;
case 0x0c0c00b8u: goto P_0c0c00b8;
case 0x0c0c00bau: goto P_0c0c00ba;
case 0x0c0c00bcu: goto P_0c0c00bc;
case 0x0c0c00beu: goto P_0c0c00be;
case 0x0c0c00c0u: goto P_0c0c00c0;
case 0x0c0c00c2u: goto P_0c0c00c2;
case 0x0c0c00c4u: goto P_0c0c00c4;
case 0x0c0c00c6u: goto P_0c0c00c6;
case 0x0c0c00c8u: goto P_0c0c00c8;
case 0x0c0c00cau: goto P_0c0c00ca;
case 0x0c0c00ccu: goto P_0c0c00cc;
case 0x0c0c00ceu: goto P_0c0c00ce;
case 0x0c0c00d0u: goto P_0c0c00d0;
case 0x0c0c00d2u: goto P_0c0c00d2;
case 0x0c0c00d4u: goto P_0c0c00d4;
case 0x0c0c00d6u: goto P_0c0c00d6;
case 0x0c0c00d8u: goto P_0c0c00d8;
case 0x0c0c00dau: goto P_0c0c00da;
case 0x0c0c00dcu: goto P_0c0c00dc;
case 0x0c0c00deu: goto P_0c0c00de;
case 0x0c0c00e0u: goto P_0c0c00e0;
case 0x0c0c00e2u: goto P_0c0c00e2;
case 0x0c0c00e4u: goto P_0c0c00e4;
case 0x0c0c00e6u: goto P_0c0c00e6;
case 0x0c0c00e8u: goto P_0c0c00e8;
case 0x0c0c00eau: goto P_0c0c00ea;
case 0x0c0c00ecu: goto P_0c0c00ec;
case 0x0c0c00eeu: goto P_0c0c00ee;
case 0x0c0c00f0u: goto P_0c0c00f0;
case 0x0c0c00f2u: goto P_0c0c00f2;
case 0x0c0c00f4u: goto P_0c0c00f4;
case 0x0c0c00f6u: goto P_0c0c00f6;
case 0x0c0c00f8u: goto P_0c0c00f8;
case 0x0c0c00fau: goto P_0c0c00fa;
case 0x0c0c00fcu: goto P_0c0c00fc;
case 0x0c0c00feu: goto P_0c0c00fe;
case 0x0c0c0100u: goto P_0c0c0100;
case 0x0c0c0102u: goto P_0c0c0102;
case 0x0c0c0104u: goto P_0c0c0104;
case 0x0c0c0106u: goto P_0c0c0106;
case 0x0c0c0108u: goto P_0c0c0108;
case 0x0c0c010au: goto P_0c0c010a;
case 0x0c0c010cu: goto P_0c0c010c;
case 0x0c0c010eu: goto P_0c0c010e;
case 0x0c0c0110u: goto P_0c0c0110;
case 0x0c0c0112u: goto P_0c0c0112;
case 0x0c0c0114u: goto P_0c0c0114;
case 0x0c0c0116u: goto P_0c0c0116;
case 0x0c0c0118u: goto P_0c0c0118;
case 0x0c0c011au: goto P_0c0c011a;
case 0x0c0c011cu: goto P_0c0c011c;
case 0x0c0c011eu: goto P_0c0c011e;
case 0x0c0c0120u: goto P_0c0c0120;
case 0x0c0c0122u: goto P_0c0c0122;
case 0x0c0c0124u: goto P_0c0c0124;
case 0x0c0c0126u: goto P_0c0c0126;
case 0x0c0c0128u: goto P_0c0c0128;
case 0x0c0c012au: goto P_0c0c012a;
case 0x0c0c012cu: goto P_0c0c012c;
case 0x0c0c012eu: goto P_0c0c012e;
case 0x0c0c0130u: goto P_0c0c0130;
case 0x0c0c0132u: goto P_0c0c0132;
case 0x0c0c0134u: goto P_0c0c0134;
case 0x0c0c0136u: goto P_0c0c0136;
case 0x0c0c0138u: goto P_0c0c0138;
case 0x0c0c013au: goto P_0c0c013a;
case 0x0c0c013cu: goto P_0c0c013c;
case 0x0c0c013eu: goto P_0c0c013e;
case 0x0c0c0140u: goto P_0c0c0140;
case 0x0c0c0142u: goto P_0c0c0142;
case 0x0c0c0144u: goto P_0c0c0144;
case 0x0c0c0146u: goto P_0c0c0146;
case 0x0c0c0148u: goto P_0c0c0148;
case 0x0c0c014au: goto P_0c0c014a;
case 0x0c0c014cu: goto P_0c0c014c;
case 0x0c0c014eu: goto P_0c0c014e;
case 0x0c0c0150u: goto P_0c0c0150;
case 0x0c0c0152u: goto P_0c0c0152;
case 0x0c0c0154u: goto P_0c0c0154;
case 0x0c0c0156u: goto P_0c0c0156;
case 0x0c0c0158u: goto P_0c0c0158;
case 0x0c0c015au: goto P_0c0c015a;
case 0x0c0c015cu: goto P_0c0c015c;
case 0x0c0c015eu: goto P_0c0c015e;
case 0x0c0c0160u: goto P_0c0c0160;
case 0x0c0c0162u: goto P_0c0c0162;
case 0x0c0c0164u: goto P_0c0c0164;
case 0x0c0c0166u: goto P_0c0c0166;
case 0x0c0c0168u: goto P_0c0c0168;
case 0x0c0c016au: goto P_0c0c016a;
case 0x0c0c016cu: goto P_0c0c016c;
case 0x0c0c016eu: goto P_0c0c016e;
case 0x0c0c0170u: goto P_0c0c0170;
case 0x0c0c0172u: goto P_0c0c0172;
case 0x0c0c0174u: goto P_0c0c0174;
case 0x0c0c0176u: goto P_0c0c0176;
case 0x0c0c0178u: goto P_0c0c0178;
case 0x0c0c017au: goto P_0c0c017a;
case 0x0c0c017cu: goto P_0c0c017c;
case 0x0c0c017eu: goto P_0c0c017e;
case 0x0c0c0180u: goto P_0c0c0180;
case 0x0c0c0182u: goto P_0c0c0182;
case 0x0c0c0184u: goto P_0c0c0184;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad58au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad58au; return 0; } return 1;
P_0c0b12ac: /* original 9005, guest PC 0x0c0b12ac */
if(!s->budget--) { s->failed_pc=0x0c0b12acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b12bau,2);
goto P_0c0b12ae;
P_0c0b12ae: /* original a011, guest PC 0x0c0b12ae */
if(!s->budget--) { s->failed_pc=0x0c0b12aeu; return 0; }
write(ram,r[4]+r[0],r[6],2);
goto P_0c0b12d4;
P_0c0b12b0: /* original 0465, guest PC 0x0c0b12b0 */
if(!s->budget--) { s->failed_pc=0x0c0b12b0u; return 0; }
write(ram,r[4]+r[0],r[6],2);
if(!vf3_matrix_family(0x0c0b12b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b12b2u; return 0; } return 1;
P_0c0b12d4: /* original e046, guest PC 0x0c0b12d4 */
if(!s->budget--) { s->failed_pc=0x0c0b12d4u; return 0; }
r[0]=0x00000046u;
goto P_0c0b12d6;
P_0c0b12d6: /* original 2fe6, guest PC 0x0c0b12d6 */
if(!s->budget--) { s->failed_pc=0x0c0b12d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b12d8;
P_0c0b12d8: /* original d31f, guest PC 0x0c0b12d8 */
if(!s->budget--) { s->failed_pc=0x0c0b12d8u; return 0; }
r[3]=read(ram,0x0c0b1358u,4);
goto P_0c0b12da;
P_0c0b12da: /* original 7ffc, guest PC 0x0c0b12da */
if(!s->budget--) { s->failed_pc=0x0c0b12dau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b12dc;
P_0c0b12dc: /* original 2f32, guest PC 0x0c0b12dc */
if(!s->budget--) { s->failed_pc=0x0c0b12dcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b12de;
P_0c0b12de: /* original 074d, guest PC 0x0c0b12de */
if(!s->budget--) { s->failed_pc=0x0c0b12deu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b12e0;
P_0c0b12e0: /* original de1e, guest PC 0x0c0b12e0 */
if(!s->budget--) { s->failed_pc=0x0c0b12e0u; return 0; }
r[14]=read(ram,0x0c0b135cu,4);
goto P_0c0b12e2;
P_0c0b12e2: /* original 677d, guest PC 0x0c0b12e2 */
if(!s->budget--) { s->failed_pc=0x0c0b12e2u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0b12e4;
P_0c0b12e4: /* original 4715, guest PC 0x0c0b12e4 */
if(!s->budget--) { s->failed_pc=0x0c0b12e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0b12e6;
P_0c0b12e6: /* original 8b0b, guest PC 0x0c0b12e6 */
if(!s->budget--) { s->failed_pc=0x0c0b12e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12e8;
P_0c0b12e8: /* original 9032, guest PC 0x0c0b12e8 */
if(!s->budget--) { s->failed_pc=0x0c0b12e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1350u,2);
goto P_0c0b12ea;
P_0c0b12ea: /* original 4615, guest PC 0x0c0b12ea */
if(!s->budget--) { s->failed_pc=0x0c0b12eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0b12ec;
P_0c0b12ec: /* original 8f08, guest PC 0x0c0b12ec */
if(!s->budget--) { s->failed_pc=0x0c0b12ecu; return 0; }
cond=r[17]&1u;
write(ram,r[5]+r[0],r[6],2);
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12f0;
P_0c0b12ee: /* original 0565, guest PC 0x0c0b12ee */
if(!s->budget--) { s->failed_pc=0x0c0b12eeu; return 0; }
write(ram,r[5]+r[0],r[6],2);
goto P_0c0b12f0;
P_0c0b12f0: /* original e061, guest PC 0x0c0b12f0 */
if(!s->budget--) { s->failed_pc=0x0c0b12f0u; return 0; }
r[0]=0x00000061u;
goto P_0c0b12f2;
P_0c0b12f2: /* original 004c, guest PC 0x0c0b12f2 */
if(!s->budget--) { s->failed_pc=0x0c0b12f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b12f4;
P_0c0b12f4: /* original 600c, guest PC 0x0c0b12f4 */
if(!s->budget--) { s->failed_pc=0x0c0b12f4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b12f6;
P_0c0b12f6: /* original 8809, guest PC 0x0c0b12f6 */
if(!s->budget--) { s->failed_pc=0x0c0b12f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b12f8;
P_0c0b12f8: /* original 8b02, guest PC 0x0c0b12f8 */
if(!s->budget--) { s->failed_pc=0x0c0b12f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1300; }
goto P_0c0b12fa;
P_0c0b12fa: /* original 902a, guest PC 0x0c0b12fa */
if(!s->budget--) { s->failed_pc=0x0c0b12fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1352u,2);
goto P_0c0b12fc;
P_0c0b12fc: /* original e320, guest PC 0x0c0b12fc */
if(!s->budget--) { s->failed_pc=0x0c0b12fcu; return 0; }
r[3]=0x00000020u;
goto P_0c0b12fe;
P_0c0b12fe: /* original 0e34, guest PC 0x0c0b12fe */
if(!s->budget--) { s->failed_pc=0x0c0b12feu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0b1300;
P_0c0b1300: /* original 65f2, guest PC 0x0c0b1300 */
if(!s->budget--) { s->failed_pc=0x0c0b1300u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b1302;
P_0c0b1302: /* original 9327, guest PC 0x0c0b1302 */
if(!s->budget--) { s->failed_pc=0x0c0b1302u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1354u,2);
goto P_0c0b1304;
P_0c0b1304: /* original 6552, guest PC 0x0c0b1304 */
if(!s->budget--) { s->failed_pc=0x0c0b1304u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b1306;
P_0c0b1306: /* original 2358, guest PC 0x0c0b1306 */
if(!s->budget--) { s->failed_pc=0x0c0b1306u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0b1308;
P_0c0b1308: /* original 8b11, guest PC 0x0c0b1308 */
if(!s->budget--) { s->failed_pc=0x0c0b1308u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b132e; }
goto P_0c0b130a;
P_0c0b130a: /* original d215, guest PC 0x0c0b130a */
if(!s->budget--) { s->failed_pc=0x0c0b130au; return 0; }
r[2]=read(ram,0x0c0b1360u,4);
goto P_0c0b130c;
P_0c0b130c: /* original 2258, guest PC 0x0c0b130c */
if(!s->budget--) { s->failed_pc=0x0c0b130cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0b130e;
P_0c0b130e: /* original 8b10, guest PC 0x0c0b130e */
if(!s->budget--) { s->failed_pc=0x0c0b130eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1332; }
goto P_0c0b1310;
P_0c0b1310: /* original d314, guest PC 0x0c0b1310 */
if(!s->budget--) { s->failed_pc=0x0c0b1310u; return 0; }
r[3]=read(ram,0x0c0b1364u,4);
goto P_0c0b1312;
P_0c0b1312: /* original 2538, guest PC 0x0c0b1312 */
if(!s->budget--) { s->failed_pc=0x0c0b1312u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0b1314;
P_0c0b1314: /* original 8b0d, guest PC 0x0c0b1314 */
if(!s->budget--) { s->failed_pc=0x0c0b1314u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1332; }
goto P_0c0b1316;
P_0c0b1316: /* original 52e2, guest PC 0x0c0b1316 */
if(!s->budget--) { s->failed_pc=0x0c0b1316u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0b1318;
P_0c0b1318: /* original d313, guest PC 0x0c0b1318 */
if(!s->budget--) { s->failed_pc=0x0c0b1318u; return 0; }
r[3]=read(ram,0x0c0b1368u,4);
goto P_0c0b131a;
P_0c0b131a: /* original 2238, guest PC 0x0c0b131a */
if(!s->budget--) { s->failed_pc=0x0c0b131au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b131c;
P_0c0b131c: /* original 8b00, guest PC 0x0c0b131c */
if(!s->budget--) { s->failed_pc=0x0c0b131cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1320; }
goto P_0c0b131e;
P_0c0b131e: /* original 3768, guest PC 0x0c0b131e */
if(!s->budget--) { s->failed_pc=0x0c0b131eu; return 0; }
r[7]-=r[6];
goto P_0c0b1320;
P_0c0b1320: /* original 4715, guest PC 0x0c0b1320 */
if(!s->budget--) { s->failed_pc=0x0c0b1320u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0b1322;
P_0c0b1322: /* original 8904, guest PC 0x0c0b1322 */
if(!s->budget--) { s->failed_pc=0x0c0b1322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b132e; }
goto P_0c0b1324;
P_0c0b1324: /* original 6242, guest PC 0x0c0b1324 */
if(!s->budget--) { s->failed_pc=0x0c0b1324u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0b1326;
P_0c0b1326: /* original e700, guest PC 0x0c0b1326 */
if(!s->budget--) { s->failed_pc=0x0c0b1326u; return 0; }
r[7]=0x00000000u;
goto P_0c0b1328;
P_0c0b1328: /* original d310, guest PC 0x0c0b1328 */
if(!s->budget--) { s->failed_pc=0x0c0b1328u; return 0; }
r[3]=read(ram,0x0c0b136cu,4);
goto P_0c0b132a;
P_0c0b132a: /* original 223b, guest PC 0x0c0b132a */
if(!s->budget--) { s->failed_pc=0x0c0b132au; return 0; }
r[2]|=r[3];
goto P_0c0b132c;
P_0c0b132c: /* original 2422, guest PC 0x0c0b132c */
if(!s->budget--) { s->failed_pc=0x0c0b132cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0b132e;
P_0c0b132e: /* original e046, guest PC 0x0c0b132e */
if(!s->budget--) { s->failed_pc=0x0c0b132eu; return 0; }
r[0]=0x00000046u;
goto P_0c0b1330;
P_0c0b1330: /* original 0475, guest PC 0x0c0b1330 */
if(!s->budget--) { s->failed_pc=0x0c0b1330u; return 0; }
write(ram,r[4]+r[0],r[7],2);
goto P_0c0b1332;
P_0c0b1332: /* original 7f04, guest PC 0x0c0b1332 */
if(!s->budget--) { s->failed_pc=0x0c0b1332u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b1334;
P_0c0b1334: /* original 000b, guest PC 0x0c0b1334 */
if(!s->budget--) { s->failed_pc=0x0c0b1334u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1336: /* original 6ef6, guest PC 0x0c0b1336 */
if(!s->budget--) { s->failed_pc=0x0c0b1336u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1338u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1338u; return 0; } return 1;
P_0c0b1464: /* original 2fe6, guest PC 0x0c0b1464 */
if(!s->budget--) { s->failed_pc=0x0c0b1464u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1466;
P_0c0b1466: /* original 6e53, guest PC 0x0c0b1466 */
if(!s->budget--) { s->failed_pc=0x0c0b1466u; return 0; }
r[14]=r[5];
goto P_0c0b1468;
P_0c0b1468: /* original 2fd6, guest PC 0x0c0b1468 */
if(!s->budget--) { s->failed_pc=0x0c0b1468u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b146a;
P_0c0b146a: /* original ed01, guest PC 0x0c0b146a */
if(!s->budget--) { s->failed_pc=0x0c0b146au; return 0; }
r[13]=0x00000001u;
goto P_0c0b146c;
P_0c0b146c: /* original 2fc6, guest PC 0x0c0b146c */
if(!s->budget--) { s->failed_pc=0x0c0b146cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b146e;
P_0c0b146e: /* original 905a, guest PC 0x0c0b146e */
if(!s->budget--) { s->failed_pc=0x0c0b146eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1526u,2);
goto P_0c0b1470;
P_0c0b1470: /* original 4f22, guest PC 0x0c0b1470 */
if(!s->budget--) { s->failed_pc=0x0c0b1470u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1472;
P_0c0b1472: /* original 034c, guest PC 0x0c0b1472 */
if(!s->budget--) { s->failed_pc=0x0c0b1472u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b1474;
P_0c0b1474: /* original dc2f, guest PC 0x0c0b1474 */
if(!s->budget--) { s->failed_pc=0x0c0b1474u; return 0; }
r[12]=read(ram,0x0c0b1534u,4);
goto P_0c0b1476;
P_0c0b1476: /* original 633c, guest PC 0x0c0b1476 */
if(!s->budget--) { s->failed_pc=0x0c0b1476u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b1478;
P_0c0b1478: /* original 33d3, guest PC 0x0c0b1478 */
if(!s->budget--) { s->failed_pc=0x0c0b1478u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[13])!=0);
goto P_0c0b147a;
P_0c0b147a: /* original 8d07, guest PC 0x0c0b147a */
if(!s->budget--) { s->failed_pc=0x0c0b147au; return 0; }
cond=r[17]&1u;
r[5]=r[6];
if(cond) { goto P_0c0b148c; }
goto P_0c0b147e;
P_0c0b147c: /* original 6563, guest PC 0x0c0b147c */
if(!s->budget--) { s->failed_pc=0x0c0b147cu; return 0; }
r[5]=r[6];
goto P_0c0b147e;
P_0c0b147e: /* original 9053, guest PC 0x0c0b147e */
if(!s->budget--) { s->failed_pc=0x0c0b147eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1528u,2);
goto P_0c0b1480;
P_0c0b1480: /* original 034c, guest PC 0x0c0b1480 */
if(!s->budget--) { s->failed_pc=0x0c0b1480u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b1482;
P_0c0b1482: /* original 633c, guest PC 0x0c0b1482 */
if(!s->budget--) { s->failed_pc=0x0c0b1482u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b1484;
P_0c0b1484: /* original 33d3, guest PC 0x0c0b1484 */
if(!s->budget--) { s->failed_pc=0x0c0b1484u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[13])!=0);
goto P_0c0b1486;
P_0c0b1486: /* original 8901, guest PC 0x0c0b1486 */
if(!s->budget--) { s->failed_pc=0x0c0b1486u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b148c; }
goto P_0c0b1488;
P_0c0b1488: /* original 37d6, guest PC 0x0c0b1488 */
if(!s->budget--) { s->failed_pc=0x0c0b1488u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[13])!=0);
goto P_0c0b148a;
P_0c0b148a: /* original 8b03, guest PC 0x0c0b148a */
if(!s->budget--) { s->failed_pc=0x0c0b148au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1494; }
goto P_0c0b148c;
P_0c0b148c: /* original 904d, guest PC 0x0c0b148c */
if(!s->budget--) { s->failed_pc=0x0c0b148cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152au,2);
goto P_0c0b148e;
P_0c0b148e: /* original 05ed, guest PC 0x0c0b148e */
if(!s->budget--) { s->failed_pc=0x0c0b148eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0b1490;
P_0c0b1490: /* original 655d, guest PC 0x0c0b1490 */
if(!s->budget--) { s->failed_pc=0x0c0b1490u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0b1492;
P_0c0b1492: /* original 356c, guest PC 0x0c0b1492 */
if(!s->budget--) { s->failed_pc=0x0c0b1492u; return 0; }
r[5]+=r[6];
goto P_0c0b1494;
P_0c0b1494: /* original 9049, guest PC 0x0c0b1494 */
if(!s->budget--) { s->failed_pc=0x0c0b1494u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152au,2);
goto P_0c0b1496;
P_0c0b1496: /* original 0e55, guest PC 0x0c0b1496 */
if(!s->budget--) { s->failed_pc=0x0c0b1496u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0b1498;
P_0c0b1498: /* original 67c2, guest PC 0x0c0b1498 */
if(!s->budget--) { s->failed_pc=0x0c0b1498u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c0b149a;
P_0c0b149a: /* original 9347, guest PC 0x0c0b149a */
if(!s->budget--) { s->failed_pc=0x0c0b149au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152cu,2);
goto P_0c0b149c;
P_0c0b149c: /* original 2378, guest PC 0x0c0b149c */
if(!s->budget--) { s->failed_pc=0x0c0b149cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0b149e;
P_0c0b149e: /* original 8f3a, guest PC 0x0c0b149e */
if(!s->budget--) { s->failed_pc=0x0c0b149eu; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[12]+4,4);
if(!cond) { goto P_0c0b1516; }
goto P_0c0b14a2;
P_0c0b14a0: /* original 56c1, guest PC 0x0c0b14a0 */
if(!s->budget--) { s->failed_pc=0x0c0b14a0u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c0b14a2;
P_0c0b14a2: /* original d125, guest PC 0x0c0b14a2 */
if(!s->budget--) { s->failed_pc=0x0c0b14a2u; return 0; }
r[1]=read(ram,0x0c0b1538u,4);
goto P_0c0b14a4;
P_0c0b14a4: /* original 2718, guest PC 0x0c0b14a4 */
if(!s->budget--) { s->failed_pc=0x0c0b14a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[1])==0)!=0);
goto P_0c0b14a6;
P_0c0b14a6: /* original 8936, guest PC 0x0c0b14a6 */
if(!s->budget--) { s->failed_pc=0x0c0b14a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b14a8;
P_0c0b14a8: /* original d324, guest PC 0x0c0b14a8 */
if(!s->budget--) { s->failed_pc=0x0c0b14a8u; return 0; }
r[3]=read(ram,0x0c0b153cu,4);
goto P_0c0b14aa;
P_0c0b14aa: /* original 2638, guest PC 0x0c0b14aa */
if(!s->budget--) { s->failed_pc=0x0c0b14aau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0b14ac;
P_0c0b14ac: /* original 8933, guest PC 0x0c0b14ac */
if(!s->budget--) { s->failed_pc=0x0c0b14acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b14ae;
P_0c0b14ae: /* original d224, guest PC 0x0c0b14ae */
if(!s->budget--) { s->failed_pc=0x0c0b14aeu; return 0; }
r[2]=read(ram,0x0c0b1540u,4);
goto P_0c0b14b0;
P_0c0b14b0: /* original 6020, guest PC 0x0c0b14b0 */
if(!s->budget--) { s->failed_pc=0x0c0b14b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0b14b2;
P_0c0b14b2: /* original 600c, guest PC 0x0c0b14b2 */
if(!s->budget--) { s->failed_pc=0x0c0b14b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b14b4;
P_0c0b14b4: /* original 8803, guest PC 0x0c0b14b4 */
if(!s->budget--) { s->failed_pc=0x0c0b14b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0b14b6;
P_0c0b14b6: /* original 8b2e, guest PC 0x0c0b14b6 */
if(!s->budget--) { s->failed_pc=0x0c0b14b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1516; }
goto P_0c0b14b8;
P_0c0b14b8: /* original e061, guest PC 0x0c0b14b8 */
if(!s->budget--) { s->failed_pc=0x0c0b14b8u; return 0; }
r[0]=0x00000061u;
goto P_0c0b14ba;
P_0c0b14ba: /* original 9338, guest PC 0x0c0b14ba */
if(!s->budget--) { s->failed_pc=0x0c0b14bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152eu,2);
goto P_0c0b14bc;
P_0c0b14bc: /* original 06ec, guest PC 0x0c0b14bc */
if(!s->budget--) { s->failed_pc=0x0c0b14bcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14be;
P_0c0b14be: /* original dd21, guest PC 0x0c0b14be */
if(!s->budget--) { s->failed_pc=0x0c0b14beu; return 0; }
r[13]=read(ram,0x0c0b1544u,4);
goto P_0c0b14c0;
P_0c0b14c0: /* original 666c, guest PC 0x0c0b14c0 */
if(!s->budget--) { s->failed_pc=0x0c0b14c0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0b14c2;
P_0c0b14c2: /* original 33dc, guest PC 0x0c0b14c2 */
if(!s->budget--) { s->failed_pc=0x0c0b14c2u; return 0; }
r[3]+=r[13];
goto P_0c0b14c4;
P_0c0b14c4: /* original 4608, guest PC 0x0c0b14c4 */
if(!s->budget--) { s->failed_pc=0x0c0b14c4u; return 0; }
r[6]<<=2;
goto P_0c0b14c6;
P_0c0b14c6: /* original 363c, guest PC 0x0c0b14c6 */
if(!s->budget--) { s->failed_pc=0x0c0b14c6u; return 0; }
r[6]+=r[3];
goto P_0c0b14c8;
P_0c0b14c8: /* original 6662, guest PC 0x0c0b14c8 */
if(!s->budget--) { s->failed_pc=0x0c0b14c8u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0b14ca;
P_0c0b14ca: /* original 3653, guest PC 0x0c0b14ca */
if(!s->budget--) { s->failed_pc=0x0c0b14cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0b14cc;
P_0c0b14cc: /* original 8906, guest PC 0x0c0b14cc */
if(!s->budget--) { s->failed_pc=0x0c0b14ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b14dc; }
goto P_0c0b14ce;
P_0c0b14ce: /* original 02ec, guest PC 0x0c0b14ce */
if(!s->budget--) { s->failed_pc=0x0c0b14ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14d0;
P_0c0b14d0: /* original 932d, guest PC 0x0c0b14d0 */
if(!s->budget--) { s->failed_pc=0x0c0b14d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b152eu,2);
goto P_0c0b14d2;
P_0c0b14d2: /* original 622c, guest PC 0x0c0b14d2 */
if(!s->budget--) { s->failed_pc=0x0c0b14d2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0b14d4;
P_0c0b14d4: /* original 33dc, guest PC 0x0c0b14d4 */
if(!s->budget--) { s->failed_pc=0x0c0b14d4u; return 0; }
r[3]+=r[13];
goto P_0c0b14d6;
P_0c0b14d6: /* original 4208, guest PC 0x0c0b14d6 */
if(!s->budget--) { s->failed_pc=0x0c0b14d6u; return 0; }
r[2]<<=2;
goto P_0c0b14d8;
P_0c0b14d8: /* original 323c, guest PC 0x0c0b14d8 */
if(!s->budget--) { s->failed_pc=0x0c0b14d8u; return 0; }
r[2]+=r[3];
goto P_0c0b14da;
P_0c0b14da: /* original 2252, guest PC 0x0c0b14da */
if(!s->budget--) { s->failed_pc=0x0c0b14dau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0b14dc;
P_0c0b14dc: /* original 9023, guest PC 0x0c0b14dc */
if(!s->budget--) { s->failed_pc=0x0c0b14dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1526u,2);
goto P_0c0b14de;
P_0c0b14de: /* original 9328, guest PC 0x0c0b14de */
if(!s->budget--) { s->failed_pc=0x0c0b14deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1532u,2);
goto P_0c0b14e0;
P_0c0b14e0: /* original 0c4c, guest PC 0x0c0b14e0 */
if(!s->budget--) { s->failed_pc=0x0c0b14e0u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b14e2;
P_0c0b14e2: /* original 9025, guest PC 0x0c0b14e2 */
if(!s->budget--) { s->failed_pc=0x0c0b14e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1530u,2);
goto P_0c0b14e4;
P_0c0b14e4: /* original 33dc, guest PC 0x0c0b14e4 */
if(!s->budget--) { s->failed_pc=0x0c0b14e4u; return 0; }
r[3]+=r[13];
goto P_0c0b14e6;
P_0c0b14e6: /* original 6ccc, guest PC 0x0c0b14e6 */
if(!s->budget--) { s->failed_pc=0x0c0b14e6u; return 0; }
r[12]=r[12]&255u;
goto P_0c0b14e8;
P_0c0b14e8: /* original d217, guest PC 0x0c0b14e8 */
if(!s->budget--) { s->failed_pc=0x0c0b14e8u; return 0; }
r[2]=read(ram,0x0c0b1548u,4);
goto P_0c0b14ea;
P_0c0b14ea: /* original 044c, guest PC 0x0c0b14ea */
if(!s->budget--) { s->failed_pc=0x0c0b14eau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0b14ec;
P_0c0b14ec: /* original e061, guest PC 0x0c0b14ec */
if(!s->budget--) { s->failed_pc=0x0c0b14ecu; return 0; }
r[0]=0x00000061u;
goto P_0c0b14ee;
P_0c0b14ee: /* original 644c, guest PC 0x0c0b14ee */
if(!s->budget--) { s->failed_pc=0x0c0b14eeu; return 0; }
r[4]=r[4]&255u;
goto P_0c0b14f0;
P_0c0b14f0: /* original 3c4c, guest PC 0x0c0b14f0 */
if(!s->budget--) { s->failed_pc=0x0c0b14f0u; return 0; }
r[12]+=r[4];
goto P_0c0b14f2;
P_0c0b14f2: /* original 04ec, guest PC 0x0c0b14f2 */
if(!s->budget--) { s->failed_pc=0x0c0b14f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b14f4;
P_0c0b14f4: /* original 644c, guest PC 0x0c0b14f4 */
if(!s->budget--) { s->failed_pc=0x0c0b14f4u; return 0; }
r[4]=r[4]&255u;
goto P_0c0b14f6;
P_0c0b14f6: /* original 4408, guest PC 0x0c0b14f6 */
if(!s->budget--) { s->failed_pc=0x0c0b14f6u; return 0; }
r[4]<<=2;
goto P_0c0b14f8;
P_0c0b14f8: /* original 420b, guest PC 0x0c0b14f8 */
if(!s->budget--) { s->failed_pc=0x0c0b14f8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b14fcu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b14fcu) { target=s->pc; goto dispatch; }
goto P_0c0b14fc;
P_0c0b14fa: /* original 343c, guest PC 0x0c0b14fa */
if(!s->budget--) { s->failed_pc=0x0c0b14fau; return 0; }
r[4]+=r[3];
goto P_0c0b14fc;
P_0c0b14fc: /* original 6403, guest PC 0x0c0b14fc */
if(!s->budget--) { s->failed_pc=0x0c0b14fcu; return 0; }
r[4]=r[0];
goto P_0c0b14fe;
P_0c0b14fe: /* original 34c3, guest PC 0x0c0b14fe */
if(!s->budget--) { s->failed_pc=0x0c0b14feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c0b1500;
P_0c0b1500: /* original 8909, guest PC 0x0c0b1500 */
if(!s->budget--) { s->failed_pc=0x0c0b1500u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1516; }
goto P_0c0b1502;
P_0c0b1502: /* original e061, guest PC 0x0c0b1502 */
if(!s->budget--) { s->failed_pc=0x0c0b1502u; return 0; }
r[0]=0x00000061u;
goto P_0c0b1504;
P_0c0b1504: /* original 9315, guest PC 0x0c0b1504 */
if(!s->budget--) { s->failed_pc=0x0c0b1504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1532u,2);
goto P_0c0b1506;
P_0c0b1506: /* original 04ec, guest PC 0x0c0b1506 */
if(!s->budget--) { s->failed_pc=0x0c0b1506u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1508;
P_0c0b1508: /* original 65c3, guest PC 0x0c0b1508 */
if(!s->budget--) { s->failed_pc=0x0c0b1508u; return 0; }
r[5]=r[12];
goto P_0c0b150a;
P_0c0b150a: /* original d210, guest PC 0x0c0b150a */
if(!s->budget--) { s->failed_pc=0x0c0b150au; return 0; }
r[2]=read(ram,0x0c0b154cu,4);
goto P_0c0b150c;
P_0c0b150c: /* original 33dc, guest PC 0x0c0b150c */
if(!s->budget--) { s->failed_pc=0x0c0b150cu; return 0; }
r[3]+=r[13];
goto P_0c0b150e;
P_0c0b150e: /* original 644c, guest PC 0x0c0b150e */
if(!s->budget--) { s->failed_pc=0x0c0b150eu; return 0; }
r[4]=r[4]&255u;
goto P_0c0b1510;
P_0c0b1510: /* original 4408, guest PC 0x0c0b1510 */
if(!s->budget--) { s->failed_pc=0x0c0b1510u; return 0; }
r[4]<<=2;
goto P_0c0b1512;
P_0c0b1512: /* original 420b, guest PC 0x0c0b1512 */
if(!s->budget--) { s->failed_pc=0x0c0b1512u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1516u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1516u) { target=s->pc; goto dispatch; }
goto P_0c0b1516;
P_0c0b1514: /* original 343c, guest PC 0x0c0b1514 */
if(!s->budget--) { s->failed_pc=0x0c0b1514u; return 0; }
r[4]+=r[3];
goto P_0c0b1516;
P_0c0b1516: /* original 4f26, guest PC 0x0c0b1516 */
if(!s->budget--) { s->failed_pc=0x0c0b1516u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1518;
P_0c0b1518: /* original 6cf6, guest PC 0x0c0b1518 */
if(!s->budget--) { s->failed_pc=0x0c0b1518u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b151a;
P_0c0b151a: /* original 6df6, guest PC 0x0c0b151a */
if(!s->budget--) { s->failed_pc=0x0c0b151au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b151c;
P_0c0b151c: /* original 000b, guest PC 0x0c0b151c */
if(!s->budget--) { s->failed_pc=0x0c0b151cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b151e: /* original 6ef6, guest PC 0x0c0b151e */
if(!s->budget--) { s->failed_pc=0x0c0b151eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1520u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1520u; return 0; } return 1;
P_0c0bfee2: /* original 2fe6, guest PC 0x0c0bfee2 */
if(!s->budget--) { s->failed_pc=0x0c0bfee2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfee4;
P_0c0bfee4: /* original 6e43, guest PC 0x0c0bfee4 */
if(!s->budget--) { s->failed_pc=0x0c0bfee4u; return 0; }
r[14]=r[4];
goto P_0c0bfee6;
P_0c0bfee6: /* original 2fd6, guest PC 0x0c0bfee6 */
if(!s->budget--) { s->failed_pc=0x0c0bfee6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfee8;
P_0c0bfee8: /* original 2fc6, guest PC 0x0c0bfee8 */
if(!s->budget--) { s->failed_pc=0x0c0bfee8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfeea;
P_0c0bfeea: /* original 2fb6, guest PC 0x0c0bfeea */
if(!s->budget--) { s->failed_pc=0x0c0bfeeau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfeec;
P_0c0bfeec: /* original 2fa6, guest PC 0x0c0bfeec */
if(!s->budget--) { s->failed_pc=0x0c0bfeecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfeee;
P_0c0bfeee: /* original 2f96, guest PC 0x0c0bfeee */
if(!s->budget--) { s->failed_pc=0x0c0bfeeeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfef0;
P_0c0bfef0: /* original 2f86, guest PC 0x0c0bfef0 */
if(!s->budget--) { s->failed_pc=0x0c0bfef0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bfef2;
P_0c0bfef2: /* original fffb, guest PC 0x0c0bfef2 */
if(!s->budget--) { s->failed_pc=0x0c0bfef2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0bfef4;
P_0c0bfef4: /* original 4f22, guest PC 0x0c0bfef4 */
if(!s->budget--) { s->failed_pc=0x0c0bfef4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bfef6;
P_0c0bfef6: /* original d311, guest PC 0x0c0bfef6 */
if(!s->budget--) { s->failed_pc=0x0c0bfef6u; return 0; }
r[3]=read(ram,0x0c0bff3cu,4);
goto P_0c0bfef8;
P_0c0bfef8: /* original dc0f, guest PC 0x0c0bfef8 */
if(!s->budget--) { s->failed_pc=0x0c0bfef8u; return 0; }
r[12]=read(ram,0x0c0bff38u,4);
goto P_0c0bfefa;
P_0c0bfefa: /* original 7fd8, guest PC 0x0c0bfefa */
if(!s->budget--) { s->failed_pc=0x0c0bfefau; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0bfefc;
P_0c0bfefc: /* original 1f33, guest PC 0x0c0bfefc */
if(!s->budget--) { s->failed_pc=0x0c0bfefcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0bfefe;
P_0c0bfefe: /* original d311, guest PC 0x0c0bfefe */
if(!s->budget--) { s->failed_pc=0x0c0bfefeu; return 0; }
r[3]=read(ram,0x0c0bff44u,4);
goto P_0c0bff00;
P_0c0bff00: /* original 62e2, guest PC 0x0c0bff00 */
if(!s->budget--) { s->failed_pc=0x0c0bff00u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0bff02;
P_0c0bff02: /* original d40f, guest PC 0x0c0bff02 */
if(!s->budget--) { s->failed_pc=0x0c0bff02u; return 0; }
r[4]=read(ram,0x0c0bff40u,4);
goto P_0c0bff04;
P_0c0bff04: /* original 2238, guest PC 0x0c0bff04 */
if(!s->budget--) { s->failed_pc=0x0c0bff04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0bff06;
P_0c0bff06: /* original 8d0c, guest PC 0x0c0bff06 */
if(!s->budget--) { s->failed_pc=0x0c0bff06u; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(cond) { goto P_0c0bff22; }
goto P_0c0bff0a;
P_0c0bff08: /* original e900, guest PC 0x0c0bff08 */
if(!s->budget--) { s->failed_pc=0x0c0bff08u; return 0; }
r[9]=0x00000000u;
goto P_0c0bff0a;
P_0c0bff0a: /* original e04c, guest PC 0x0c0bff0a */
if(!s->budget--) { s->failed_pc=0x0c0bff0au; return 0; }
r[0]=0x0000004cu;
goto P_0c0bff0c;
P_0c0bff0c: /* original d30e, guest PC 0x0c0bff0c */
if(!s->budget--) { s->failed_pc=0x0c0bff0cu; return 0; }
r[3]=read(ram,0x0c0bff48u,4);
goto P_0c0bff0e;
P_0c0bff0e: /* original 0dee, guest PC 0x0c0bff0e */
if(!s->budget--) { s->failed_pc=0x0c0bff0eu; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0bff10;
P_0c0bff10: /* original 23d8, guest PC 0x0c0bff10 */
if(!s->budget--) { s->failed_pc=0x0c0bff10u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0bff12;
P_0c0bff12: /* original 8b06, guest PC 0x0c0bff12 */
if(!s->budget--) { s->failed_pc=0x0c0bff12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bff22; }
goto P_0c0bff14;
P_0c0bff14: /* original 50f3, guest PC 0x0c0bff14 */
if(!s->budget--) { s->failed_pc=0x0c0bff14u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0bff16;
P_0c0bff16: /* original e11c, guest PC 0x0c0bff16 */
if(!s->budget--) { s->failed_pc=0x0c0bff16u; return 0; }
r[1]=0x0000001cu;
goto P_0c0bff18;
P_0c0bff18: /* original 001c, guest PC 0x0c0bff18 */
if(!s->budget--) { s->failed_pc=0x0c0bff18u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0bff1a;
P_0c0bff1a: /* original 600c, guest PC 0x0c0bff1a */
if(!s->budget--) { s->failed_pc=0x0c0bff1au; return 0; }
r[0]=r[0]&255u;
goto P_0c0bff1c;
P_0c0bff1c: /* original c90f, guest PC 0x0c0bff1c */
if(!s->budget--) { s->failed_pc=0x0c0bff1cu; return 0; }
r[0]&=15u;
goto P_0c0bff1e;
P_0c0bff1e: /* original 880d, guest PC 0x0c0bff1e */
if(!s->budget--) { s->failed_pc=0x0c0bff1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0bff20;
P_0c0bff20: /* original 8b14, guest PC 0x0c0bff20 */
if(!s->budget--) { s->failed_pc=0x0c0bff20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bff4c; }
goto P_0c0bff22;
P_0c0bff22: /* original a125, guest PC 0x0c0bff22 */
if(!s->budget--) { s->failed_pc=0x0c0bff22u; return 0; }
r[0]=0x00000000u;
goto P_0c0c0170;
P_0c0bff24: /* original e000, guest PC 0x0c0bff24 */
if(!s->budget--) { s->failed_pc=0x0c0bff24u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c0bff26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bff26u; return 0; } return 1;
P_0c0bff4c: /* original e048, guest PC 0x0c0bff4c */
if(!s->budget--) { s->failed_pc=0x0c0bff4cu; return 0; }
r[0]=0x00000048u;
goto P_0c0bff4e;
P_0c0bff4e: /* original 9a7d, guest PC 0x0c0bff4e */
if(!s->budget--) { s->failed_pc=0x0c0bff4eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c004cu,2);
goto P_0c0bff50;
P_0c0bff50: /* original 08ee, guest PC 0x0c0bff50 */
if(!s->budget--) { s->failed_pc=0x0c0bff50u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0bff52;
P_0c0bff52: /* original 907a, guest PC 0x0c0bff52 */
if(!s->budget--) { s->failed_pc=0x0c0bff52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c004au,2);
goto P_0c0bff54;
P_0c0bff54: /* original 2a89, guest PC 0x0c0bff54 */
if(!s->budget--) { s->failed_pc=0x0c0bff54u; return 0; }
r[10]&=r[8];
goto P_0c0bff56;
P_0c0bff56: /* original 03ed, guest PC 0x0c0bff56 */
if(!s->budget--) { s->failed_pc=0x0c0bff56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0bff58;
P_0c0bff58: /* original 2aa8, guest PC 0x0c0bff58 */
if(!s->budget--) { s->failed_pc=0x0c0bff58u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0bff5a;
P_0c0bff5a: /* original 8d35, guest PC 0x0c0bff5a */
if(!s->budget--) { s->failed_pc=0x0c0bff5au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+36,r[3],4);
if(cond) { goto P_0c0bffc8; }
goto P_0c0bff5e;
P_0c0bff5c: /* original 1f39, guest PC 0x0c0bff5c */
if(!s->budget--) { s->failed_pc=0x0c0bff5cu; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c0bff5e;
P_0c0bff5e: /* original 5345, guest PC 0x0c0bff5e */
if(!s->budget--) { s->failed_pc=0x0c0bff5eu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0bff60;
P_0c0bff60: /* original 4315, guest PC 0x0c0bff60 */
if(!s->budget--) { s->failed_pc=0x0c0bff60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0bff62;
P_0c0bff62: /* original 8b31, guest PC 0x0c0bff62 */
if(!s->budget--) { s->failed_pc=0x0c0bff62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0bffc8; }
goto P_0c0bff64;
P_0c0bff64: /* original 9073, guest PC 0x0c0bff64 */
if(!s->budget--) { s->failed_pc=0x0c0bff64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c004eu,2);
goto P_0c0bff66;
P_0c0bff66: /* original 02ed, guest PC 0x0c0bff66 */
if(!s->budget--) { s->failed_pc=0x0c0bff66u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0bff68;
P_0c0bff68: /* original e03e, guest PC 0x0c0bff68 */
if(!s->budget--) { s->failed_pc=0x0c0bff68u; return 0; }
r[0]=0x0000003eu;
goto P_0c0bff6a;
P_0c0bff6a: /* original 6323, guest PC 0x0c0bff6a */
if(!s->budget--) { s->failed_pc=0x0c0bff6au; return 0; }
r[3]=r[2];
goto P_0c0bff6c;
P_0c0bff6c: /* original 2f22, guest PC 0x0c0bff6c */
if(!s->budget--) { s->failed_pc=0x0c0bff6cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0bff6e;
P_0c0bff6e: /* original 04ed, guest PC 0x0c0bff6e */
if(!s->budget--) { s->failed_pc=0x0c0bff6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0bff70;
P_0c0bff70: /* original 644d, guest PC 0x0c0bff70 */
if(!s->budget--) { s->failed_pc=0x0c0bff70u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0bff72;
P_0c0bff72: /* original 3346, guest PC 0x0c0bff72 */
if(!s->budget--) { s->failed_pc=0x0c0bff72u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0bff74;
P_0c0bff74: /* original 8928, guest PC 0x0c0bff74 */
if(!s->budget--) { s->failed_pc=0x0c0bff74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0bffc8; }
goto P_0c0bff76;
P_0c0bff76: /* original 906b, guest PC 0x0c0bff76 */
if(!s->budget--) { s->failed_pc=0x0c0bff76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0050u,2);
goto P_0c0bff78;
P_0c0bff78: /* original e300, guest PC 0x0c0bff78 */
if(!s->budget--) { s->failed_pc=0x0c0bff78u; return 0; }
r[3]=0x00000000u;
goto P_0c0bff7a;
P_0c0bff7a: /* original 0bec, guest PC 0x0c0bff7a */
if(!s->budget--) { s->failed_pc=0x0c0bff7au; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0bff7c;
P_0c0bff7c: /* original 9069, guest PC 0x0c0bff7c */
if(!s->budget--) { s->failed_pc=0x0c0bff7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0052u,2);
goto P_0c0bff7e;
P_0c0bff7e: /* original 6bbc, guest PC 0x0c0bff7e */
if(!s->budget--) { s->failed_pc=0x0c0bff7eu; return 0; }
r[11]=r[11]&255u;
goto P_0c0bff80;
P_0c0bff80: /* original 04ed, guest PC 0x0c0bff80 */
if(!s->budget--) { s->failed_pc=0x0c0bff80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0bff82;
P_0c0bff82: /* original 2bb8, guest PC 0x0c0bff82 */
if(!s->budget--) { s->failed_pc=0x0c0bff82u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0bff84;
P_0c0bff84: /* original 0e35, guest PC 0x0c0bff84 */
if(!s->budget--) { s->failed_pc=0x0c0bff84u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0bff86;
P_0c0bff86: /* original e066, guest PC 0x0c0bff86 */
if(!s->budget--) { s->failed_pc=0x0c0bff86u; return 0; }
r[0]=0x00000066u;
goto P_0c0bff88;
P_0c0bff88: /* original 34bc, guest PC 0x0c0bff88 */
if(!s->budget--) { s->failed_pc=0x0c0bff88u; return 0; }
r[4]+=r[11];
goto P_0c0bff8a;
P_0c0bff8a: /* original 8d1d, guest PC 0x0c0bff8a */
if(!s->budget--) { s->failed_pc=0x0c0bff8au; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c0bffc8; }
goto P_0c0bff8e;
P_0c0bff8c: /* original 0e45, guest PC 0x0c0bff8c */
if(!s->budget--) { s->failed_pc=0x0c0bff8cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0bff8e;
P_0c0bff8e: /* original 84e4, guest PC 0x0c0bff8e */
if(!s->budget--) { s->failed_pc=0x0c0bff8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0bff90;
P_0c0bff90: /* original 2008, guest PC 0x0c0bff90 */
if(!s->budget--) { s->failed_pc=0x0c0bff90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0bff92;
P_0c0bff92: /* original 8d03, guest PC 0x0c0bff92 */
if(!s->budget--) { s->failed_pc=0x0c0bff92u; return 0; }
cond=r[17]&1u;
r[6]=r[11];
if(cond) { goto P_0c0bff9c; }
goto P_0c0bff96;
P_0c0bff94: /* original 66b3, guest PC 0x0c0bff94 */
if(!s->budget--) { s->failed_pc=0x0c0bff94u; return 0; }
r[6]=r[11];
goto P_0c0bff96;
P_0c0bff96: /* original 52c4, guest PC 0x0c0bff96 */
if(!s->budget--) { s->failed_pc=0x0c0bff96u; return 0; }
r[2]=read(ram,r[12]+16,4);
goto P_0c0bff98;
P_0c0bff98: /* original a002, guest PC 0x0c0bff98 */
if(!s->budget--) { s->failed_pc=0x0c0bff98u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0bffa0;
P_0c0bff9a: /* original 1f22, guest PC 0x0c0bff9a */
if(!s->budget--) { s->failed_pc=0x0c0bff9au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0bff9c;
P_0c0bff9c: /* original 51c5, guest PC 0x0c0bff9c */
if(!s->budget--) { s->failed_pc=0x0c0bff9cu; return 0; }
r[1]=read(ram,r[12]+20,4);
goto P_0c0bff9e;
P_0c0bff9e: /* original 1f12, guest PC 0x0c0bff9e */
if(!s->budget--) { s->failed_pc=0x0c0bff9eu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0bffa0;
P_0c0bffa0: /* original d330, guest PC 0x0c0bffa0 */
if(!s->budget--) { s->failed_pc=0x0c0bffa0u; return 0; }
r[3]=read(ram,0x0c0c0064u,4);
goto P_0c0bffa2;
P_0c0bffa2: /* original 55f2, guest PC 0x0c0bffa2 */
if(!s->budget--) { s->failed_pc=0x0c0bffa2u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0bffa4;
P_0c0bffa4: /* original 430b, guest PC 0x0c0bffa4 */
if(!s->budget--) { s->failed_pc=0x0c0bffa4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0bffa8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bffa8u) { target=s->pc; goto dispatch; }
goto P_0c0bffa8;
P_0c0bffa6: /* original 64e3, guest PC 0x0c0bffa6 */
if(!s->budget--) { s->failed_pc=0x0c0bffa6u; return 0; }
r[4]=r[14];
goto P_0c0bffa8;
P_0c0bffa8: /* original 9054, guest PC 0x0c0bffa8 */
if(!s->budget--) { s->failed_pc=0x0c0bffa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0054u,2);
goto P_0c0bffaa;
P_0c0bffaa: /* original 66b3, guest PC 0x0c0bffaa */
if(!s->budget--) { s->failed_pc=0x0c0bffaau; return 0; }
r[6]=r[11];
goto P_0c0bffac;
P_0c0bffac: /* original 02ec, guest PC 0x0c0bffac */
if(!s->budget--) { s->failed_pc=0x0c0bffacu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0bffae;
P_0c0bffae: /* original 7201, guest PC 0x0c0bffae */
if(!s->budget--) { s->failed_pc=0x0c0bffaeu; return 0; }
r[2]+=0x00000001u;
goto P_0c0bffb0;
P_0c0bffb0: /* original 0e24, guest PC 0x0c0bffb0 */
if(!s->budget--) { s->failed_pc=0x0c0bffb0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0bffb2;
P_0c0bffb2: /* original 03ec, guest PC 0x0c0bffb2 */
if(!s->budget--) { s->failed_pc=0x0c0bffb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0bffb4;
P_0c0bffb4: /* original 633c, guest PC 0x0c0bffb4 */
if(!s->budget--) { s->failed_pc=0x0c0bffb4u; return 0; }
r[3]=r[3]&255u;
goto P_0c0bffb6;
P_0c0bffb6: /* original 1f36, guest PC 0x0c0bffb6 */
if(!s->budget--) { s->failed_pc=0x0c0bffb6u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0bffb8;
P_0c0bffb8: /* original 6733, guest PC 0x0c0bffb8 */
if(!s->budget--) { s->failed_pc=0x0c0bffb8u; return 0; }
r[7]=r[3];
goto P_0c0bffba;
P_0c0bffba: /* original 55f2, guest PC 0x0c0bffba */
if(!s->budget--) { s->failed_pc=0x0c0bffbau; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0bffbc;
P_0c0bffbc: /* original d22a, guest PC 0x0c0bffbc */
if(!s->budget--) { s->failed_pc=0x0c0bffbcu; return 0; }
r[2]=read(ram,0x0c0c0068u,4);
goto P_0c0bffbe;
P_0c0bffbe: /* original 420b, guest PC 0x0c0bffbe */
if(!s->budget--) { s->failed_pc=0x0c0bffbeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0bffc2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bffc2u) { target=s->pc; goto dispatch; }
goto P_0c0bffc2;
P_0c0bffc0: /* original 64e3, guest PC 0x0c0bffc0 */
if(!s->budget--) { s->failed_pc=0x0c0bffc0u; return 0; }
r[4]=r[14];
goto P_0c0bffc2;
P_0c0bffc2: /* original 9045, guest PC 0x0c0bffc2 */
if(!s->budget--) { s->failed_pc=0x0c0bffc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0050u,2);
goto P_0c0bffc4;
P_0c0bffc4: /* original e300, guest PC 0x0c0bffc4 */
if(!s->budget--) { s->failed_pc=0x0c0bffc4u; return 0; }
r[3]=0x00000000u;
goto P_0c0bffc6;
P_0c0bffc6: /* original 0e34, guest PC 0x0c0bffc6 */
if(!s->budget--) { s->failed_pc=0x0c0bffc6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0bffc8;
P_0c0bffc8: /* original 9045, guest PC 0x0c0bffc8 */
if(!s->budget--) { s->failed_pc=0x0c0bffc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0056u,2);
goto P_0c0bffca;
P_0c0bffca: /* original 63f3, guest PC 0x0c0bffca */
if(!s->budget--) { s->failed_pc=0x0c0bffcau; return 0; }
r[3]=r[15];
goto P_0c0bffcc;
P_0c0bffcc: /* original f3e6, guest PC 0x0c0bffcc */
if(!s->budget--) { s->failed_pc=0x0c0bffccu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bffce;
P_0c0bffce: /* original e020, guest PC 0x0c0bffce */
if(!s->budget--) { s->failed_pc=0x0c0bffceu; return 0; }
r[0]=0x00000020u;
goto P_0c0bffd0;
P_0c0bffd0: /* original ff37, guest PC 0x0c0bffd0 */
if(!s->budget--) { s->failed_pc=0x0c0bffd0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bffd2;
P_0c0bffd2: /* original 9041, guest PC 0x0c0bffd2 */
if(!s->budget--) { s->failed_pc=0x0c0bffd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0058u,2);
goto P_0c0bffd4;
P_0c0bffd4: /* original ffe6, guest PC 0x0c0bffd4 */
if(!s->budget--) { s->failed_pc=0x0c0bffd4u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0bffd6;
P_0c0bffd6: /* original 7004, guest PC 0x0c0bffd6 */
if(!s->budget--) { s->failed_pc=0x0c0bffd6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0bffd8;
P_0c0bffd8: /* original f3e6, guest PC 0x0c0bffd8 */
if(!s->budget--) { s->failed_pc=0x0c0bffd8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bffda;
P_0c0bffda: /* original e01c, guest PC 0x0c0bffda */
if(!s->budget--) { s->failed_pc=0x0c0bffdau; return 0; }
r[0]=0x0000001cu;
goto P_0c0bffdc;
P_0c0bffdc: /* original ff37, guest PC 0x0c0bffdc */
if(!s->budget--) { s->failed_pc=0x0c0bffdcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bffde;
P_0c0bffde: /* original 903c, guest PC 0x0c0bffde */
if(!s->budget--) { s->failed_pc=0x0c0bffdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c005au,2);
goto P_0c0bffe0;
P_0c0bffe0: /* original f3e6, guest PC 0x0c0bffe0 */
if(!s->budget--) { s->failed_pc=0x0c0bffe0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0bffe2;
P_0c0bffe2: /* original e004, guest PC 0x0c0bffe2 */
if(!s->budget--) { s->failed_pc=0x0c0bffe2u; return 0; }
r[0]=0x00000004u;
goto P_0c0bffe4;
P_0c0bffe4: /* original ff31, guest PC 0x0c0bffe4 */
if(!s->budget--) { s->failed_pc=0x0c0bffe4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0bffe6;
P_0c0bffe6: /* original ff37, guest PC 0x0c0bffe6 */
if(!s->budget--) { s->failed_pc=0x0c0bffe6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0bffe8;
P_0c0bffe8: /* original 2f36, guest PC 0x0c0bffe8 */
if(!s->budget--) { s->failed_pc=0x0c0bffe8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bffea;
P_0c0bffea: /* original 65f3, guest PC 0x0c0bffea */
if(!s->budget--) { s->failed_pc=0x0c0bffeau; return 0; }
r[5]=r[15];
goto P_0c0bffec;
P_0c0bffec: /* original d21f, guest PC 0x0c0bffec */
if(!s->budget--) { s->failed_pc=0x0c0bffecu; return 0; }
r[2]=read(ram,0x0c0c006cu,4);
goto P_0c0bffee;
P_0c0bffee: /* original 66f3, guest PC 0x0c0bffee */
if(!s->budget--) { s->failed_pc=0x0c0bffeeu; return 0; }
r[6]=r[15];
goto P_0c0bfff0;
P_0c0bfff0: /* original 67f3, guest PC 0x0c0bfff0 */
if(!s->budget--) { s->failed_pc=0x0c0bfff0u; return 0; }
r[7]=r[15];
goto P_0c0bfff2;
P_0c0bfff2: /* original 7508, guest PC 0x0c0bfff2 */
if(!s->budget--) { s->failed_pc=0x0c0bfff2u; return 0; }
r[5]+=0x00000008u;
goto P_0c0bfff4;
P_0c0bfff4: /* original 7614, guest PC 0x0c0bfff4 */
if(!s->budget--) { s->failed_pc=0x0c0bfff4u; return 0; }
r[6]+=0x00000014u;
goto P_0c0bfff6;
P_0c0bfff6: /* original 7718, guest PC 0x0c0bfff6 */
if(!s->budget--) { s->failed_pc=0x0c0bfff6u; return 0; }
r[7]+=0x00000018u;
goto P_0c0bfff8;
P_0c0bfff8: /* original 420b, guest PC 0x0c0bfff8 */
if(!s->budget--) { s->failed_pc=0x0c0bfff8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0bfffcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bfffcu) { target=s->pc; goto dispatch; }
goto P_0c0bfffc;
P_0c0bfffa: /* original 64e3, guest PC 0x0c0bfffa */
if(!s->budget--) { s->failed_pc=0x0c0bfffau; return 0; }
r[4]=r[14];
goto P_0c0bfffc;
P_0c0bfffc: /* original 7f04, guest PC 0x0c0bfffc */
if(!s->budget--) { s->failed_pc=0x0c0bfffcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0bfffe;
P_0c0bfffe: /* original 922d, guest PC 0x0c0bfffe */
if(!s->budget--) { s->failed_pc=0x0c0bfffeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c005cu,2);
goto P_0c0c0000;
P_0c0c0000: /* original 63f2, guest PC 0x0c0c0000 */
if(!s->budget--) { s->failed_pc=0x0c0c0000u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0002;
P_0c0c0002: /* original 2aa8, guest PC 0x0c0c0002 */
if(!s->budget--) { s->failed_pc=0x0c0c0002u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c0004;
P_0c0c0004: /* original 3238, guest PC 0x0c0c0004 */
if(!s->budget--) { s->failed_pc=0x0c0c0004u; return 0; }
r[2]-=r[3];
goto P_0c0c0006;
P_0c0c0006: /* original 622f, guest PC 0x0c0c0006 */
if(!s->budget--) { s->failed_pc=0x0c0c0006u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0c0008;
P_0c0c0008: /* original 6523, guest PC 0x0c0c0008 */
if(!s->budget--) { s->failed_pc=0x0c0c0008u; return 0; }
r[5]=r[2];
goto P_0c0c000a;
P_0c0c000a: /* original 6423, guest PC 0x0c0c000a */
if(!s->budget--) { s->failed_pc=0x0c0c000au; return 0; }
r[4]=r[2];
goto P_0c0c000c;
P_0c0c000c: /* original 2f22, guest PC 0x0c0c000c */
if(!s->budget--) { s->failed_pc=0x0c0c000cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c000e;
P_0c0c000e: /* original d618, guest PC 0x0c0c000e */
if(!s->budget--) { s->failed_pc=0x0c0c000eu; return 0; }
r[6]=read(ram,0x0c0c0070u,4);
goto P_0c0c0010;
P_0c0c0010: /* original 8f65, guest PC 0x0c0c0010 */
if(!s->budget--) { s->failed_pc=0x0c0c0010u; return 0; }
cond=r[17]&1u;
r[5]^=r[6];
if(!cond) { goto P_0c0c00de; }
goto P_0c0c0014;
P_0c0c0012: /* original 256a, guest PC 0x0c0c0012 */
if(!s->budget--) { s->failed_pc=0x0c0c0012u; return 0; }
r[5]^=r[6];
goto P_0c0c0014;
P_0c0c0014: /* original 53f9, guest PC 0x0c0c0014 */
if(!s->budget--) { s->failed_pc=0x0c0c0014u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0c0016;
P_0c0c0016: /* original c718, guest PC 0x0c0c0016 */
if(!s->budget--) { s->failed_pc=0x0c0c0016u; return 0; }
r[0]=code_base|0x000c0078u;
goto P_0c0c0018;
P_0c0c0018: /* original 9221, guest PC 0x0c0c0018 */
if(!s->budget--) { s->failed_pc=0x0c0c0018u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c005eu,2);
goto P_0c0c001a;
P_0c0c001a: /* original 3348, guest PC 0x0c0c001a */
if(!s->budget--) { s->failed_pc=0x0c0c001au; return 0; }
r[3]-=r[4];
goto P_0c0c001c;
P_0c0c001c: /* original d715, guest PC 0x0c0c001c */
if(!s->budget--) { s->failed_pc=0x0c0c001cu; return 0; }
r[7]=read(ram,0x0c0c0074u,4);
goto P_0c0c001e;
P_0c0c001e: /* original 6433, guest PC 0x0c0c001e */
if(!s->budget--) { s->failed_pc=0x0c0c001eu; return 0; }
r[4]=r[3];
goto P_0c0c0020;
P_0c0c0020: /* original 342c, guest PC 0x0c0c0020 */
if(!s->budget--) { s->failed_pc=0x0c0c0020u; return 0; }
r[4]+=r[2];
goto P_0c0c0022;
P_0c0c0022: /* original 931d, guest PC 0x0c0c0022 */
if(!s->budget--) { s->failed_pc=0x0c0c0022u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0060u,2);
goto P_0c0c0024;
P_0c0c0024: /* original 2479, guest PC 0x0c0c0024 */
if(!s->budget--) { s->failed_pc=0x0c0c0024u; return 0; }
r[4]&=r[7];
goto P_0c0c0026;
P_0c0c0026: /* original d715, guest PC 0x0c0c0026 */
if(!s->budget--) { s->failed_pc=0x0c0c0026u; return 0; }
r[7]=read(ram,0x0c0c007cu,4);
goto P_0c0c0028;
P_0c0c0028: /* original f408, guest PC 0x0c0c0028 */
if(!s->budget--) { s->failed_pc=0x0c0c0028u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c002a;
P_0c0c002a: /* original 3436, guest PC 0x0c0c002a */
if(!s->budget--) { s->failed_pc=0x0c0c002au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0c002c;
P_0c0c002c: /* original 8f06, guest PC 0x0c0c002c */
if(!s->budget--) { s->failed_pc=0x0c0c002cu; return 0; }
cond=r[17]&1u;
r[7]&=r[8];
if(!cond) { goto P_0c0c003c; }
goto P_0c0c0030;
P_0c0c002e: /* original 2789, guest PC 0x0c0c002e */
if(!s->budget--) { s->failed_pc=0x0c0c002eu; return 0; }
r[7]&=r[8];
goto P_0c0c0030;
P_0c0c0030: /* original 9316, guest PC 0x0c0c0030 */
if(!s->budget--) { s->failed_pc=0x0c0c0030u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0060u,2);
goto P_0c0c0032;
P_0c0c0032: /* original 246a, guest PC 0x0c0c0032 */
if(!s->budget--) { s->failed_pc=0x0c0c0032u; return 0; }
r[4]^=r[6];
goto P_0c0c0034;
P_0c0c0034: /* original 3436, guest PC 0x0c0c0034 */
if(!s->budget--) { s->failed_pc=0x0c0c0034u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0c0036;
P_0c0c0036: /* original 8b23, guest PC 0x0c0c0036 */
if(!s->budget--) { s->failed_pc=0x0c0c0036u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0080; }
goto P_0c0c0038;
P_0c0c0038: /* original a051, guest PC 0x0c0c0038 */
if(!s->budget--) { s->failed_pc=0x0c0c0038u; return 0; }
goto P_0c0c00de;
P_0c0c003a: /* original 0009, guest PC 0x0c0c003a */
if(!s->budget--) { s->failed_pc=0x0c0c003au; return 0; }
goto P_0c0c003c;
P_0c0c003c: /* original 2778, guest PC 0x0c0c003c */
if(!s->budget--) { s->failed_pc=0x0c0c003cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c003e;
P_0c0c003e: /* original 894e, guest PC 0x0c0c003e */
if(!s->budget--) { s->failed_pc=0x0c0c003eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c00de; }
goto P_0c0c0040;
P_0c0c0040: /* original f4f5, guest PC 0x0c0c0040 */
if(!s->budget--) { s->failed_pc=0x0c0c0040u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c0042;
P_0c0c0042: /* original 894c, guest PC 0x0c0c0042 */
if(!s->budget--) { s->failed_pc=0x0c0c0042u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c00de; }
goto P_0c0c0044;
P_0c0c0044: /* original 940d, guest PC 0x0c0c0044 */
if(!s->budget--) { s->failed_pc=0x0c0c0044u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0062u,2);
goto P_0c0c0046;
P_0c0c0046: /* original a027, guest PC 0x0c0c0046 */
if(!s->budget--) { s->failed_pc=0x0c0c0046u; return 0; }
goto P_0c0c0098;
P_0c0c0048: /* original 0009, guest PC 0x0c0c0048 */
if(!s->budget--) { s->failed_pc=0x0c0c0048u; return 0; }
if(!vf3_matrix_family(0x0c0c004au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c004au; return 0; } return 1;
P_0c0c0080: /* original 2778, guest PC 0x0c0c0080 */
if(!s->budget--) { s->failed_pc=0x0c0c0080u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c0082;
P_0c0c0082: /* original 8b2c, guest PC 0x0c0c0082 */
if(!s->budget--) { s->failed_pc=0x0c0c0082u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c00de; }
goto P_0c0c0084;
P_0c0c0084: /* original f4f5, guest PC 0x0c0c0084 */
if(!s->budget--) { s->failed_pc=0x0c0c0084u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c0086;
P_0c0c0086: /* original 892a, guest PC 0x0c0c0086 */
if(!s->budget--) { s->failed_pc=0x0c0c0086u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c00de; }
goto P_0c0c0088;
P_0c0c0088: /* original c742, guest PC 0x0c0c0088 */
if(!s->budget--) { s->failed_pc=0x0c0c0088u; return 0; }
r[0]=code_base|0x000c0194u;
goto P_0c0c008a;
P_0c0c008a: /* original f308, guest PC 0x0c0c008a */
if(!s->budget--) { s->failed_pc=0x0c0c008au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c008c;
P_0c0c008c: /* original ff35, guest PC 0x0c0c008c */
if(!s->budget--) { s->failed_pc=0x0c0c008cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c008e;
P_0c0c008e: /* original 8902, guest PC 0x0c0c008e */
if(!s->budget--) { s->failed_pc=0x0c0c008eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0096; }
goto P_0c0c0090;
P_0c0c0090: /* original 9479, guest PC 0x0c0c0090 */
if(!s->budget--) { s->failed_pc=0x0c0c0090u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0186u,2);
goto P_0c0c0092;
P_0c0c0092: /* original a001, guest PC 0x0c0c0092 */
if(!s->budget--) { s->failed_pc=0x0c0c0092u; return 0; }
goto P_0c0c0098;
P_0c0c0094: /* original 0009, guest PC 0x0c0c0094 */
if(!s->budget--) { s->failed_pc=0x0c0c0094u; return 0; }
goto P_0c0c0096;
P_0c0c0096: /* original 9477, guest PC 0x0c0c0096 */
if(!s->budget--) { s->failed_pc=0x0c0c0096u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0188u,2);
goto P_0c0c0098;
P_0c0c0098: /* original 6053, guest PC 0x0c0c0098 */
if(!s->budget--) { s->failed_pc=0x0c0c0098u; return 0; }
r[0]=r[5];
goto P_0c0c009a;
P_0c0c009a: /* original 81ef, guest PC 0x0c0c009a */
if(!s->budget--) { s->failed_pc=0x0c0c009au; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c009c;
P_0c0c009c: /* original e020, guest PC 0x0c0c009c */
if(!s->budget--) { s->failed_pc=0x0c0c009cu; return 0; }
r[0]=0x00000020u;
goto P_0c0c009e;
P_0c0c009e: /* original f3f6, guest PC 0x0c0c009e */
if(!s->budget--) { s->failed_pc=0x0c0c009eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c00a0;
P_0c0c00a0: /* original e010, guest PC 0x0c0c00a0 */
if(!s->budget--) { s->failed_pc=0x0c0c00a0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c00a2;
P_0c0c00a2: /* original fe37, guest PC 0x0c0c00a2 */
if(!s->budget--) { s->failed_pc=0x0c0c00a2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c00a4;
P_0c0c00a4: /* original e01c, guest PC 0x0c0c00a4 */
if(!s->budget--) { s->failed_pc=0x0c0c00a4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c00a6;
P_0c0c00a6: /* original f3f6, guest PC 0x0c0c00a6 */
if(!s->budget--) { s->failed_pc=0x0c0c00a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c00a8;
P_0c0c00a8: /* original e018, guest PC 0x0c0c00a8 */
if(!s->budget--) { s->failed_pc=0x0c0c00a8u; return 0; }
r[0]=0x00000018u;
goto P_0c0c00aa;
P_0c0c00aa: /* original fe37, guest PC 0x0c0c00aa */
if(!s->budget--) { s->failed_pc=0x0c0c00aau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0c00ac;
P_0c0c00ac: /* original e024, guest PC 0x0c0c00ac */
if(!s->budget--) { s->failed_pc=0x0c0c00acu; return 0; }
r[0]=0x00000024u;
goto P_0c0c00ae;
P_0c0c00ae: /* original f6e6, guest PC 0x0c0c00ae */
if(!s->budget--) { s->failed_pc=0x0c0c00aeu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c00b0;
P_0c0c00b0: /* original e02c, guest PC 0x0c0c00b0 */
if(!s->budget--) { s->failed_pc=0x0c0c00b0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c00b2;
P_0c0c00b2: /* original f5e6, guest PC 0x0c0c00b2 */
if(!s->budget--) { s->failed_pc=0x0c0c00b2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c00b4;
P_0c0c00b4: /* original e028, guest PC 0x0c0c00b4 */
if(!s->budget--) { s->failed_pc=0x0c0c00b4u; return 0; }
r[0]=0x00000028u;
goto P_0c0c00b6;
P_0c0c00b6: /* original f4e6, guest PC 0x0c0c00b6 */
if(!s->budget--) { s->failed_pc=0x0c0c00b6u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c00b8;
P_0c0c00b8: /* original f38d, guest PC 0x0c0c00b8 */
if(!s->budget--) { s->failed_pc=0x0c0c00b8u; return 0; }
fr[3]=0;
goto P_0c0c00ba;
P_0c0c00ba: /* original f345, guest PC 0x0c0c00ba */
if(!s->budget--) { s->failed_pc=0x0c0c00bau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0c00bc;
P_0c0c00bc: /* original 8902, guest PC 0x0c0c00bc */
if(!s->budget--) { s->failed_pc=0x0c0c00bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c00c4; }
goto P_0c0c00be;
P_0c0c00be: /* original c736, guest PC 0x0c0c00be */
if(!s->budget--) { s->failed_pc=0x0c0c00beu; return 0; }
r[0]=code_base|0x000c0198u;
goto P_0c0c00c0;
P_0c0c00c0: /* original f308, guest PC 0x0c0c00c0 */
if(!s->budget--) { s->failed_pc=0x0c0c00c0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c00c2;
P_0c0c00c2: /* original f432, guest PC 0x0c0c00c2 */
if(!s->budget--) { s->failed_pc=0x0c0c00c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c00c4;
P_0c0c00c4: /* original e024, guest PC 0x0c0c00c4 */
if(!s->budget--) { s->failed_pc=0x0c0c00c4u; return 0; }
r[0]=0x00000024u;
goto P_0c0c00c6;
P_0c0c00c6: /* original fe67, guest PC 0x0c0c00c6 */
if(!s->budget--) { s->failed_pc=0x0c0c00c6u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0c00c8;
P_0c0c00c8: /* original e028, guest PC 0x0c0c00c8 */
if(!s->budget--) { s->failed_pc=0x0c0c00c8u; return 0; }
r[0]=0x00000028u;
goto P_0c0c00ca;
P_0c0c00ca: /* original fe47, guest PC 0x0c0c00ca */
if(!s->budget--) { s->failed_pc=0x0c0c00cau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c00cc;
P_0c0c00cc: /* original e02c, guest PC 0x0c0c00cc */
if(!s->budget--) { s->failed_pc=0x0c0c00ccu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c00ce;
P_0c0c00ce: /* original fe57, guest PC 0x0c0c00ce */
if(!s->budget--) { s->failed_pc=0x0c0c00ceu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c00d0;
P_0c0c00d0: /* original e31f, guest PC 0x0c0c00d0 */
if(!s->budget--) { s->failed_pc=0x0c0c00d0u; return 0; }
r[3]=0x0000001fu;
goto P_0c0c00d2;
P_0c0c00d2: /* original 905a, guest PC 0x0c0c00d2 */
if(!s->budget--) { s->failed_pc=0x0c0c00d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c018au,2);
goto P_0c0c00d4;
P_0c0c00d4: /* original 0e34, guest PC 0x0c0c00d4 */
if(!s->budget--) { s->failed_pc=0x0c0c00d4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c00d6;
P_0c0c00d6: /* original 9059, guest PC 0x0c0c00d6 */
if(!s->budget--) { s->failed_pc=0x0c0c00d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c018cu,2);
goto P_0c0c00d8;
P_0c0c00d8: /* original 0e46, guest PC 0x0c0c00d8 */
if(!s->budget--) { s->failed_pc=0x0c0c00d8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c00da;
P_0c0c00da: /* original a027, guest PC 0x0c0c00da */
if(!s->budget--) { s->failed_pc=0x0c0c00dau; return 0; }
r[9]=0x00000001u;
goto P_0c0c012c;
P_0c0c00dc: /* original e901, guest PC 0x0c0c00dc */
if(!s->budget--) { s->failed_pc=0x0c0c00dcu; return 0; }
r[9]=0x00000001u;
goto P_0c0c00de;
P_0c0c00de: /* original e024, guest PC 0x0c0c00de */
if(!s->budget--) { s->failed_pc=0x0c0c00deu; return 0; }
r[0]=0x00000024u;
goto P_0c0c00e0;
P_0c0c00e0: /* original f4e6, guest PC 0x0c0c00e0 */
if(!s->budget--) { s->failed_pc=0x0c0c00e0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0c00e2;
P_0c0c00e2: /* original e028, guest PC 0x0c0c00e2 */
if(!s->budget--) { s->failed_pc=0x0c0c00e2u; return 0; }
r[0]=0x00000028u;
goto P_0c0c00e4;
P_0c0c00e4: /* original f6e6, guest PC 0x0c0c00e4 */
if(!s->budget--) { s->failed_pc=0x0c0c00e4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c00e6;
P_0c0c00e6: /* original e02c, guest PC 0x0c0c00e6 */
if(!s->budget--) { s->failed_pc=0x0c0c00e6u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c00e8;
P_0c0c00e8: /* original f5e6, guest PC 0x0c0c00e8 */
if(!s->budget--) { s->failed_pc=0x0c0c00e8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c00ea;
P_0c0c00ea: /* original c72b, guest PC 0x0c0c00ea */
if(!s->budget--) { s->failed_pc=0x0c0c00eau; return 0; }
r[0]=code_base|0x000c0198u;
goto P_0c0c00ec;
P_0c0c00ec: /* original f308, guest PC 0x0c0c00ec */
if(!s->budget--) { s->failed_pc=0x0c0c00ecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c00ee;
P_0c0c00ee: /* original e004, guest PC 0x0c0c00ee */
if(!s->budget--) { s->failed_pc=0x0c0c00eeu; return 0; }
r[0]=0x00000004u;
goto P_0c0c00f0;
P_0c0c00f0: /* original e403, guest PC 0x0c0c00f0 */
if(!s->budget--) { s->failed_pc=0x0c0c00f0u; return 0; }
r[4]=0x00000003u;
goto P_0c0c00f2;
P_0c0c00f2: /* original ff37, guest PC 0x0c0c00f2 */
if(!s->budget--) { s->failed_pc=0x0c0c00f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c00f4;
P_0c0c00f4: /* original c729, guest PC 0x0c0c00f4 */
if(!s->budget--) { s->failed_pc=0x0c0c00f4u; return 0; }
r[0]=code_base|0x000c019cu;
goto P_0c0c00f6;
P_0c0c00f6: /* original f532, guest PC 0x0c0c00f6 */
if(!s->budget--) { s->failed_pc=0x0c0c00f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0c00f8;
P_0c0c00f8: /* original f432, guest PC 0x0c0c00f8 */
if(!s->budget--) { s->failed_pc=0x0c0c00f8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c00fa;
P_0c0c00fa: /* original f308, guest PC 0x0c0c00fa */
if(!s->budget--) { s->failed_pc=0x0c0c00fau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c00fc;
P_0c0c00fc: /* original e004, guest PC 0x0c0c00fc */
if(!s->budget--) { s->failed_pc=0x0c0c00fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0c00fe;
P_0c0c00fe: /* original ff37, guest PC 0x0c0c00fe */
if(!s->budget--) { s->failed_pc=0x0c0c00feu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c0100;
P_0c0c0100: /* original 9045, guest PC 0x0c0c0100 */
if(!s->budget--) { s->failed_pc=0x0c0c0100u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c018eu,2);
goto P_0c0c0102;
P_0c0c0102: /* original 03ec, guest PC 0x0c0c0102 */
if(!s->budget--) { s->failed_pc=0x0c0c0102u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c0104;
P_0c0c0104: /* original 633c, guest PC 0x0c0c0104 */
if(!s->budget--) { s->failed_pc=0x0c0c0104u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c0106;
P_0c0c0106: /* original 2348, guest PC 0x0c0c0106 */
if(!s->budget--) { s->failed_pc=0x0c0c0106u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c0108;
P_0c0c0108: /* original 8d03, guest PC 0x0c0c0108 */
if(!s->budget--) { s->failed_pc=0x0c0c0108u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c0c0112; }
goto P_0c0c010c;
P_0c0c010a: /* original 2f32, guest PC 0x0c0c010a */
if(!s->budget--) { s->failed_pc=0x0c0c010au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c010c;
P_0c0c010c: /* original e004, guest PC 0x0c0c010c */
if(!s->budget--) { s->failed_pc=0x0c0c010cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c010e;
P_0c0c010e: /* original f3f6, guest PC 0x0c0c010e */
if(!s->budget--) { s->failed_pc=0x0c0c010eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c0110;
P_0c0c0110: /* original f432, guest PC 0x0c0c0110 */
if(!s->budget--) { s->failed_pc=0x0c0c0110u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c0112;
P_0c0c0112: /* original 63f2, guest PC 0x0c0c0112 */
if(!s->budget--) { s->failed_pc=0x0c0c0112u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0114;
P_0c0c0114: /* original e40c, guest PC 0x0c0c0114 */
if(!s->budget--) { s->failed_pc=0x0c0c0114u; return 0; }
r[4]=0x0000000cu;
goto P_0c0c0116;
P_0c0c0116: /* original 2438, guest PC 0x0c0c0116 */
if(!s->budget--) { s->failed_pc=0x0c0c0116u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c0118;
P_0c0c0118: /* original 8902, guest PC 0x0c0c0118 */
if(!s->budget--) { s->failed_pc=0x0c0c0118u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0120; }
goto P_0c0c011a;
P_0c0c011a: /* original e004, guest PC 0x0c0c011a */
if(!s->budget--) { s->failed_pc=0x0c0c011au; return 0; }
r[0]=0x00000004u;
goto P_0c0c011c;
P_0c0c011c: /* original f3f6, guest PC 0x0c0c011c */
if(!s->budget--) { s->failed_pc=0x0c0c011cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c011e;
P_0c0c011e: /* original f532, guest PC 0x0c0c011e */
if(!s->budget--) { s->failed_pc=0x0c0c011eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0c0120;
P_0c0c0120: /* original e024, guest PC 0x0c0c0120 */
if(!s->budget--) { s->failed_pc=0x0c0c0120u; return 0; }
r[0]=0x00000024u;
goto P_0c0c0122;
P_0c0c0122: /* original fe47, guest PC 0x0c0c0122 */
if(!s->budget--) { s->failed_pc=0x0c0c0122u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c0124;
P_0c0c0124: /* original e028, guest PC 0x0c0c0124 */
if(!s->budget--) { s->failed_pc=0x0c0c0124u; return 0; }
r[0]=0x00000028u;
goto P_0c0c0126;
P_0c0c0126: /* original fe67, guest PC 0x0c0c0126 */
if(!s->budget--) { s->failed_pc=0x0c0c0126u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0c0128;
P_0c0c0128: /* original e02c, guest PC 0x0c0c0128 */
if(!s->budget--) { s->failed_pc=0x0c0c0128u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c012a;
P_0c0c012a: /* original fe57, guest PC 0x0c0c012a */
if(!s->budget--) { s->failed_pc=0x0c0c012au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0c012c;
P_0c0c012c: /* original 9030, guest PC 0x0c0c012c */
if(!s->budget--) { s->failed_pc=0x0c0c012cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0190u,2);
goto P_0c0c012e;
P_0c0c012e: /* original 03ed, guest PC 0x0c0c012e */
if(!s->budget--) { s->failed_pc=0x0c0c012eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0130;
P_0c0c0130: /* original e03e, guest PC 0x0c0c0130 */
if(!s->budget--) { s->failed_pc=0x0c0c0130u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c0132;
P_0c0c0132: /* original 2f32, guest PC 0x0c0c0132 */
if(!s->budget--) { s->failed_pc=0x0c0c0132u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c0134;
P_0c0c0134: /* original 04ed, guest PC 0x0c0c0134 */
if(!s->budget--) { s->failed_pc=0x0c0c0134u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0136;
P_0c0c0136: /* original 644d, guest PC 0x0c0c0136 */
if(!s->budget--) { s->failed_pc=0x0c0c0136u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0c0138;
P_0c0c0138: /* original 3342, guest PC 0x0c0c0138 */
if(!s->budget--) { s->failed_pc=0x0c0c0138u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0c013a;
P_0c0c013a: /* original 8918, guest PC 0x0c0c013a */
if(!s->budget--) { s->failed_pc=0x0c0c013au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c016e; }
goto P_0c0c013c;
P_0c0c013c: /* original d218, guest PC 0x0c0c013c */
if(!s->budget--) { s->failed_pc=0x0c0c013cu; return 0; }
r[2]=read(ram,0x0c0c01a0u,4);
goto P_0c0c013e;
P_0c0c013e: /* original e04c, guest PC 0x0c0c013e */
if(!s->budget--) { s->failed_pc=0x0c0c013eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0c0140;
P_0c0c0140: /* original e11c, guest PC 0x0c0c0140 */
if(!s->budget--) { s->failed_pc=0x0c0c0140u; return 0; }
r[1]=0x0000001cu;
goto P_0c0c0142;
P_0c0c0142: /* original 2d2b, guest PC 0x0c0c0142 */
if(!s->budget--) { s->failed_pc=0x0c0c0142u; return 0; }
r[13]|=r[2];
goto P_0c0c0144;
P_0c0c0144: /* original 0ed6, guest PC 0x0c0c0144 */
if(!s->budget--) { s->failed_pc=0x0c0c0144u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0c0146;
P_0c0c0146: /* original 50f3, guest PC 0x0c0c0146 */
if(!s->budget--) { s->failed_pc=0x0c0c0146u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0c0148;
P_0c0c0148: /* original d316, guest PC 0x0c0c0148 */
if(!s->budget--) { s->failed_pc=0x0c0c0148u; return 0; }
r[3]=read(ram,0x0c0c01a4u,4);
goto P_0c0c014a;
P_0c0c014a: /* original 001c, guest PC 0x0c0c014a */
if(!s->budget--) { s->failed_pc=0x0c0c014au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c014c;
P_0c0c014c: /* original 600c, guest PC 0x0c0c014c */
if(!s->budget--) { s->failed_pc=0x0c0c014cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0c014e;
P_0c0c014e: /* original c90f, guest PC 0x0c0c014e */
if(!s->budget--) { s->failed_pc=0x0c0c014eu; return 0; }
r[0]&=15u;
goto P_0c0c0150;
P_0c0c0150: /* original 4008, guest PC 0x0c0c0150 */
if(!s->budget--) { s->failed_pc=0x0c0c0150u; return 0; }
r[0]<<=2;
goto P_0c0c0152;
P_0c0c0152: /* original 033e, guest PC 0x0c0c0152 */
if(!s->budget--) { s->failed_pc=0x0c0c0152u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c0c0154;
P_0c0c0154: /* original 6433, guest PC 0x0c0c0154 */
if(!s->budget--) { s->failed_pc=0x0c0c0154u; return 0; }
r[4]=r[3];
goto P_0c0c0156;
P_0c0c0156: /* original 2f32, guest PC 0x0c0c0156 */
if(!s->budget--) { s->failed_pc=0x0c0c0156u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c0158;
P_0c0c0158: /* original d313, guest PC 0x0c0c0158 */
if(!s->budget--) { s->failed_pc=0x0c0c0158u; return 0; }
r[3]=read(ram,0x0c0c01a8u,4);
goto P_0c0c015a;
P_0c0c015a: /* original 430b, guest PC 0x0c0c015a */
if(!s->budget--) { s->failed_pc=0x0c0c015au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c015eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c015eu) { target=s->pc; goto dispatch; }
goto P_0c0c015e;
P_0c0c015c: /* original 0009, guest PC 0x0c0c015c */
if(!s->budget--) { s->failed_pc=0x0c0c015cu; return 0; }
goto P_0c0c015e;
P_0c0c015e: /* original d313, guest PC 0x0c0c015e */
if(!s->budget--) { s->failed_pc=0x0c0c015eu; return 0; }
r[3]=read(ram,0x0c0c01acu,4);
goto P_0c0c0160;
P_0c0c0160: /* original 430b, guest PC 0x0c0c0160 */
if(!s->budget--) { s->failed_pc=0x0c0c0160u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c0164u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0164u) { target=s->pc; goto dispatch; }
goto P_0c0c0164;
P_0c0c0162: /* original 64f2, guest PC 0x0c0c0162 */
if(!s->budget--) { s->failed_pc=0x0c0c0162u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c0164;
P_0c0c0164: /* original c712, guest PC 0x0c0c0164 */
if(!s->budget--) { s->failed_pc=0x0c0c0164u; return 0; }
r[0]=code_base|0x000c01b0u;
goto P_0c0c0166;
P_0c0c0166: /* original 54c8, guest PC 0x0c0c0166 */
if(!s->budget--) { s->failed_pc=0x0c0c0166u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0c0168;
P_0c0c0168: /* original f308, guest PC 0x0c0c0168 */
if(!s->budget--) { s->failed_pc=0x0c0c0168u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c016a;
P_0c0c016a: /* original 9012, guest PC 0x0c0c016a */
if(!s->budget--) { s->failed_pc=0x0c0c016au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0192u,2);
goto P_0c0c016c;
P_0c0c016c: /* original f437, guest PC 0x0c0c016c */
if(!s->budget--) { s->failed_pc=0x0c0c016cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0c016e;
P_0c0c016e: /* original 6093, guest PC 0x0c0c016e */
if(!s->budget--) { s->failed_pc=0x0c0c016eu; return 0; }
r[0]=r[9];
goto P_0c0c0170;
P_0c0c0170: /* original 7f28, guest PC 0x0c0c0170 */
if(!s->budget--) { s->failed_pc=0x0c0c0170u; return 0; }
r[15]+=0x00000028u;
goto P_0c0c0172;
P_0c0c0172: /* original 4f26, guest PC 0x0c0c0172 */
if(!s->budget--) { s->failed_pc=0x0c0c0172u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0174;
P_0c0c0174: /* original fff9, guest PC 0x0c0c0174 */
if(!s->budget--) { s->failed_pc=0x0c0c0174u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c0176;
P_0c0c0176: /* original 68f6, guest PC 0x0c0c0176 */
if(!s->budget--) { s->failed_pc=0x0c0c0176u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c0178;
P_0c0c0178: /* original 69f6, guest PC 0x0c0c0178 */
if(!s->budget--) { s->failed_pc=0x0c0c0178u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c017a;
P_0c0c017a: /* original 6af6, guest PC 0x0c0c017a */
if(!s->budget--) { s->failed_pc=0x0c0c017au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c017c;
P_0c0c017c: /* original 6bf6, guest PC 0x0c0c017c */
if(!s->budget--) { s->failed_pc=0x0c0c017cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c017e;
P_0c0c017e: /* original 6cf6, guest PC 0x0c0c017e */
if(!s->budget--) { s->failed_pc=0x0c0c017eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0180;
P_0c0c0180: /* original 6df6, guest PC 0x0c0c0180 */
if(!s->budget--) { s->failed_pc=0x0c0c0180u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0182;
P_0c0c0182: /* original 000b, guest PC 0x0c0c0182 */
if(!s->budget--) { s->failed_pc=0x0c0c0182u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c0184: /* original 6ef6, guest PC 0x0c0c0184 */
if(!s->budget--) { s->failed_pc=0x0c0c0184u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c0186u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0186u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
