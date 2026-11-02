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
int vf3_away_batch189_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c11f4u: goto P_0c0c11f4;
case 0x0c0c11f6u: goto P_0c0c11f6;
case 0x0c0c11f8u: goto P_0c0c11f8;
case 0x0c0c11fau: goto P_0c0c11fa;
case 0x0c0c11fcu: goto P_0c0c11fc;
case 0x0c0c11feu: goto P_0c0c11fe;
case 0x0c0c1200u: goto P_0c0c1200;
case 0x0c0c1202u: goto P_0c0c1202;
case 0x0c0c1204u: goto P_0c0c1204;
case 0x0c0c1206u: goto P_0c0c1206;
case 0x0c0c1208u: goto P_0c0c1208;
case 0x0c0c120au: goto P_0c0c120a;
case 0x0c0c120cu: goto P_0c0c120c;
case 0x0c0c120eu: goto P_0c0c120e;
case 0x0c0c1210u: goto P_0c0c1210;
case 0x0c0c1212u: goto P_0c0c1212;
case 0x0c0c1214u: goto P_0c0c1214;
case 0x0c0c1216u: goto P_0c0c1216;
case 0x0c0c1218u: goto P_0c0c1218;
case 0x0c0c121au: goto P_0c0c121a;
case 0x0c0c121cu: goto P_0c0c121c;
case 0x0c0c121eu: goto P_0c0c121e;
case 0x0c0c1220u: goto P_0c0c1220;
case 0x0c0c1222u: goto P_0c0c1222;
case 0x0c0c1224u: goto P_0c0c1224;
case 0x0c0c1226u: goto P_0c0c1226;
case 0x0c0c1228u: goto P_0c0c1228;
case 0x0c0c122au: goto P_0c0c122a;
case 0x0c0c122cu: goto P_0c0c122c;
case 0x0c0c122eu: goto P_0c0c122e;
case 0x0c0c1230u: goto P_0c0c1230;
case 0x0c0c1232u: goto P_0c0c1232;
case 0x0c0c1234u: goto P_0c0c1234;
case 0x0c0c1236u: goto P_0c0c1236;
case 0x0c0c1238u: goto P_0c0c1238;
case 0x0c0c123au: goto P_0c0c123a;
case 0x0c0c123cu: goto P_0c0c123c;
case 0x0c0c123eu: goto P_0c0c123e;
case 0x0c0c1240u: goto P_0c0c1240;
case 0x0c0c1242u: goto P_0c0c1242;
case 0x0c0c1244u: goto P_0c0c1244;
case 0x0c0c1246u: goto P_0c0c1246;
case 0x0c0c1248u: goto P_0c0c1248;
case 0x0c0c124au: goto P_0c0c124a;
case 0x0c0c124cu: goto P_0c0c124c;
case 0x0c0c13c4u: goto P_0c0c13c4;
case 0x0c0c13c6u: goto P_0c0c13c6;
case 0x0c0c13c8u: goto P_0c0c13c8;
case 0x0c0c13cau: goto P_0c0c13ca;
case 0x0c0c13ccu: goto P_0c0c13cc;
case 0x0c0c13ceu: goto P_0c0c13ce;
case 0x0c0c13d0u: goto P_0c0c13d0;
case 0x0c0c13d2u: goto P_0c0c13d2;
case 0x0c0c13d4u: goto P_0c0c13d4;
case 0x0c0c13d6u: goto P_0c0c13d6;
case 0x0c0c13d8u: goto P_0c0c13d8;
case 0x0c0c13dau: goto P_0c0c13da;
case 0x0c0c13dcu: goto P_0c0c13dc;
case 0x0c0c13deu: goto P_0c0c13de;
case 0x0c0c13e0u: goto P_0c0c13e0;
case 0x0c0c13e2u: goto P_0c0c13e2;
case 0x0c0c13e4u: goto P_0c0c13e4;
case 0x0c0c13e6u: goto P_0c0c13e6;
case 0x0c0c13e8u: goto P_0c0c13e8;
case 0x0c0c13eau: goto P_0c0c13ea;
case 0x0c0c13ecu: goto P_0c0c13ec;
case 0x0c0c13eeu: goto P_0c0c13ee;
case 0x0c0c13f0u: goto P_0c0c13f0;
case 0x0c0c13f2u: goto P_0c0c13f2;
case 0x0c0c13f4u: goto P_0c0c13f4;
case 0x0c0c13f6u: goto P_0c0c13f6;
case 0x0c0c13f8u: goto P_0c0c13f8;
case 0x0c0c13fau: goto P_0c0c13fa;
case 0x0c0c13fcu: goto P_0c0c13fc;
case 0x0c0c13feu: goto P_0c0c13fe;
case 0x0c0c1400u: goto P_0c0c1400;
case 0x0c0c1402u: goto P_0c0c1402;
case 0x0c0c1404u: goto P_0c0c1404;
case 0x0c0c1406u: goto P_0c0c1406;
case 0x0c0c1408u: goto P_0c0c1408;
case 0x0c0c140au: goto P_0c0c140a;
case 0x0c0c140cu: goto P_0c0c140c;
case 0x0c0c140eu: goto P_0c0c140e;
case 0x0c0c1410u: goto P_0c0c1410;
case 0x0c0c1412u: goto P_0c0c1412;
case 0x0c0c1414u: goto P_0c0c1414;
case 0x0c0c1416u: goto P_0c0c1416;
case 0x0c0c1418u: goto P_0c0c1418;
case 0x0c0c141au: goto P_0c0c141a;
case 0x0c0c141cu: goto P_0c0c141c;
case 0x0c0c141eu: goto P_0c0c141e;
case 0x0c0c1420u: goto P_0c0c1420;
case 0x0c0c1422u: goto P_0c0c1422;
case 0x0c0c1424u: goto P_0c0c1424;
case 0x0c0c1426u: goto P_0c0c1426;
case 0x0c0c1428u: goto P_0c0c1428;
case 0x0c0c142au: goto P_0c0c142a;
case 0x0c0c142cu: goto P_0c0c142c;
case 0x0c0c142eu: goto P_0c0c142e;
case 0x0c0c1430u: goto P_0c0c1430;
case 0x0c0c1432u: goto P_0c0c1432;
case 0x0c0c1434u: goto P_0c0c1434;
case 0x0c0c1436u: goto P_0c0c1436;
case 0x0c0c1438u: goto P_0c0c1438;
case 0x0c0c143au: goto P_0c0c143a;
case 0x0c0c143cu: goto P_0c0c143c;
case 0x0c0c143eu: goto P_0c0c143e;
case 0x0c0c1440u: goto P_0c0c1440;
case 0x0c0c1442u: goto P_0c0c1442;
case 0x0c0c1444u: goto P_0c0c1444;
case 0x0c0c1446u: goto P_0c0c1446;
case 0x0c0c1448u: goto P_0c0c1448;
case 0x0c0c144au: goto P_0c0c144a;
case 0x0c0c144cu: goto P_0c0c144c;
case 0x0c0c144eu: goto P_0c0c144e;
case 0x0c0c1450u: goto P_0c0c1450;
case 0x0c0c1452u: goto P_0c0c1452;
case 0x0c0c1454u: goto P_0c0c1454;
case 0x0c0c1456u: goto P_0c0c1456;
case 0x0c0c1458u: goto P_0c0c1458;
case 0x0c0c145au: goto P_0c0c145a;
case 0x0c0c145cu: goto P_0c0c145c;
case 0x0c0c145eu: goto P_0c0c145e;
case 0x0c0c1460u: goto P_0c0c1460;
case 0x0c0c1462u: goto P_0c0c1462;
case 0x0c0c1464u: goto P_0c0c1464;
case 0x0c0c1466u: goto P_0c0c1466;
case 0x0c0c1468u: goto P_0c0c1468;
case 0x0c0c146au: goto P_0c0c146a;
case 0x0c0c146cu: goto P_0c0c146c;
case 0x0c0c146eu: goto P_0c0c146e;
case 0x0c0c1470u: goto P_0c0c1470;
case 0x0c0c1472u: goto P_0c0c1472;
case 0x0c0c1474u: goto P_0c0c1474;
case 0x0c0c1476u: goto P_0c0c1476;
case 0x0c0c1478u: goto P_0c0c1478;
case 0x0c0c147au: goto P_0c0c147a;
case 0x0c0c147cu: goto P_0c0c147c;
case 0x0c0c147eu: goto P_0c0c147e;
case 0x0c0c1480u: goto P_0c0c1480;
case 0x0c0c1482u: goto P_0c0c1482;
case 0x0c0c1484u: goto P_0c0c1484;
case 0x0c0c1486u: goto P_0c0c1486;
case 0x0c0c1488u: goto P_0c0c1488;
case 0x0c0c14a4u: goto P_0c0c14a4;
case 0x0c0c14a6u: goto P_0c0c14a6;
case 0x0c0c14a8u: goto P_0c0c14a8;
case 0x0c0c14aau: goto P_0c0c14aa;
case 0x0c0c14acu: goto P_0c0c14ac;
case 0x0c0c14aeu: goto P_0c0c14ae;
case 0x0c0c14b0u: goto P_0c0c14b0;
case 0x0c0c14b2u: goto P_0c0c14b2;
case 0x0c0c14b4u: goto P_0c0c14b4;
case 0x0c0c14b6u: goto P_0c0c14b6;
case 0x0c0c14b8u: goto P_0c0c14b8;
case 0x0c0c14bau: goto P_0c0c14ba;
case 0x0c0c14bcu: goto P_0c0c14bc;
case 0x0c0c14beu: goto P_0c0c14be;
case 0x0c0c14c0u: goto P_0c0c14c0;
case 0x0c0c14c2u: goto P_0c0c14c2;
case 0x0c0c14c4u: goto P_0c0c14c4;
case 0x0c0c14c6u: goto P_0c0c14c6;
case 0x0c0c14c8u: goto P_0c0c14c8;
case 0x0c0c14cau: goto P_0c0c14ca;
case 0x0c0c14ccu: goto P_0c0c14cc;
case 0x0c0c14ceu: goto P_0c0c14ce;
case 0x0c0c14d0u: goto P_0c0c14d0;
case 0x0c0c14d2u: goto P_0c0c14d2;
case 0x0c0c14d4u: goto P_0c0c14d4;
case 0x0c0c14d6u: goto P_0c0c14d6;
case 0x0c0c14d8u: goto P_0c0c14d8;
case 0x0c0c14dau: goto P_0c0c14da;
case 0x0c0c14dcu: goto P_0c0c14dc;
case 0x0c0c14deu: goto P_0c0c14de;
case 0x0c0c14e0u: goto P_0c0c14e0;
case 0x0c0c14e2u: goto P_0c0c14e2;
case 0x0c0c14e4u: goto P_0c0c14e4;
case 0x0c0c14e6u: goto P_0c0c14e6;
case 0x0c0c14e8u: goto P_0c0c14e8;
case 0x0c0c14eau: goto P_0c0c14ea;
case 0x0c0c14ecu: goto P_0c0c14ec;
case 0x0c0c14eeu: goto P_0c0c14ee;
case 0x0c0c14f0u: goto P_0c0c14f0;
case 0x0c0c14f2u: goto P_0c0c14f2;
case 0x0c0c14f4u: goto P_0c0c14f4;
case 0x0c0c14f6u: goto P_0c0c14f6;
case 0x0c0c14f8u: goto P_0c0c14f8;
case 0x0c0c14fau: goto P_0c0c14fa;
case 0x0c0c14fcu: goto P_0c0c14fc;
case 0x0c0c14feu: goto P_0c0c14fe;
case 0x0c0c1500u: goto P_0c0c1500;
case 0x0c0c1502u: goto P_0c0c1502;
case 0x0c0c1504u: goto P_0c0c1504;
case 0x0c0c1506u: goto P_0c0c1506;
case 0x0c0c1508u: goto P_0c0c1508;
case 0x0c0c150au: goto P_0c0c150a;
case 0x0c0c150cu: goto P_0c0c150c;
case 0x0c0c150eu: goto P_0c0c150e;
case 0x0c0c1510u: goto P_0c0c1510;
case 0x0c0c1512u: goto P_0c0c1512;
case 0x0c0c1514u: goto P_0c0c1514;
case 0x0c0c1516u: goto P_0c0c1516;
case 0x0c0c1518u: goto P_0c0c1518;
case 0x0c0c151au: goto P_0c0c151a;
case 0x0c0c151cu: goto P_0c0c151c;
case 0x0c0c151eu: goto P_0c0c151e;
case 0x0c0c1520u: goto P_0c0c1520;
case 0x0c0c1522u: goto P_0c0c1522;
case 0x0c0c1524u: goto P_0c0c1524;
case 0x0c0c1526u: goto P_0c0c1526;
case 0x0c0c1528u: goto P_0c0c1528;
case 0x0c0c152au: goto P_0c0c152a;
case 0x0c0c152cu: goto P_0c0c152c;
case 0x0c0c152eu: goto P_0c0c152e;
case 0x0c0c1530u: goto P_0c0c1530;
case 0x0c0c1532u: goto P_0c0c1532;
case 0x0c0c1534u: goto P_0c0c1534;
case 0x0c0c1536u: goto P_0c0c1536;
case 0x0c0c1538u: goto P_0c0c1538;
case 0x0c0c153au: goto P_0c0c153a;
case 0x0c0c153cu: goto P_0c0c153c;
case 0x0c0c153eu: goto P_0c0c153e;
case 0x0c0c1540u: goto P_0c0c1540;
case 0x0c0c1542u: goto P_0c0c1542;
case 0x0c0c1544u: goto P_0c0c1544;
case 0x0c0c1546u: goto P_0c0c1546;
case 0x0c0c1548u: goto P_0c0c1548;
case 0x0c0c154au: goto P_0c0c154a;
case 0x0c0c154cu: goto P_0c0c154c;
case 0x0c0c154eu: goto P_0c0c154e;
case 0x0c0c1550u: goto P_0c0c1550;
case 0x0c0c1552u: goto P_0c0c1552;
case 0x0c0c1554u: goto P_0c0c1554;
case 0x0c0c1556u: goto P_0c0c1556;
case 0x0c0c1558u: goto P_0c0c1558;
case 0x0c0c155au: goto P_0c0c155a;
case 0x0c0c155cu: goto P_0c0c155c;
case 0x0c0c155eu: goto P_0c0c155e;
case 0x0c0c1560u: goto P_0c0c1560;
case 0x0c0c1562u: goto P_0c0c1562;
case 0x0c0c1564u: goto P_0c0c1564;
case 0x0c0c1566u: goto P_0c0c1566;
case 0x0c0c1568u: goto P_0c0c1568;
case 0x0c0c156au: goto P_0c0c156a;
case 0x0c0c156cu: goto P_0c0c156c;
case 0x0c0c156eu: goto P_0c0c156e;
case 0x0c0c1570u: goto P_0c0c1570;
case 0x0c0c1572u: goto P_0c0c1572;
case 0x0c0c1574u: goto P_0c0c1574;
case 0x0c0c1576u: goto P_0c0c1576;
case 0x0c0c1578u: goto P_0c0c1578;
case 0x0c0c157au: goto P_0c0c157a;
case 0x0c0c157cu: goto P_0c0c157c;
case 0x0c0c157eu: goto P_0c0c157e;
case 0x0c0c1580u: goto P_0c0c1580;
case 0x0c0c1582u: goto P_0c0c1582;
case 0x0c0c1584u: goto P_0c0c1584;
case 0x0c0c1586u: goto P_0c0c1586;
case 0x0c0c1588u: goto P_0c0c1588;
case 0x0c0c158au: goto P_0c0c158a;
case 0x0c0c158cu: goto P_0c0c158c;
case 0x0c0c158eu: goto P_0c0c158e;
case 0x0c0c1590u: goto P_0c0c1590;
case 0x0c0c1592u: goto P_0c0c1592;
case 0x0c0c1594u: goto P_0c0c1594;
case 0x0c0c1596u: goto P_0c0c1596;
case 0x0c0c1598u: goto P_0c0c1598;
case 0x0c0c159au: goto P_0c0c159a;
case 0x0c0c159cu: goto P_0c0c159c;
case 0x0c0c159eu: goto P_0c0c159e;
case 0x0c0c15a0u: goto P_0c0c15a0;
case 0x0c0c15a2u: goto P_0c0c15a2;
case 0x0c0c15a4u: goto P_0c0c15a4;
case 0x0c0c15a6u: goto P_0c0c15a6;
case 0x0c0c15a8u: goto P_0c0c15a8;
case 0x0c0c15aau: goto P_0c0c15aa;
case 0x0c0c15acu: goto P_0c0c15ac;
case 0x0c0c15aeu: goto P_0c0c15ae;
case 0x0c0c15b0u: goto P_0c0c15b0;
case 0x0c0c15b2u: goto P_0c0c15b2;
case 0x0c0c15b4u: goto P_0c0c15b4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c11f4: /* original 7ff4, guest PC 0x0c0c11f4 */
if(!s->budget--) { s->failed_pc=0x0c0c11f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c11f6;
P_0c0c11f6: /* original 6763, guest PC 0x0c0c11f6 */
if(!s->budget--) { s->failed_pc=0x0c0c11f6u; return 0; }
r[7]=r[6];
goto P_0c0c11f8;
P_0c0c11f8: /* original 1f41, guest PC 0x0c0c11f8 */
if(!s->budget--) { s->failed_pc=0x0c0c11f8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c11fa;
P_0c0c11fa: /* original 2f52, guest PC 0x0c0c11fa */
if(!s->budget--) { s->failed_pc=0x0c0c11fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c11fc;
P_0c0c11fc: /* original 1f62, guest PC 0x0c0c11fc */
if(!s->budget--) { s->failed_pc=0x0c0c11fcu; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c11fe;
P_0c0c11fe: /* original 55f1, guest PC 0x0c0c11fe */
if(!s->budget--) { s->failed_pc=0x0c0c11feu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c1200;
P_0c0c1200: /* original 66f2, guest PC 0x0c0c1200 */
if(!s->budget--) { s->failed_pc=0x0c0c1200u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0c1202;
P_0c0c1202: /* original d438, guest PC 0x0c0c1202 */
if(!s->budget--) { s->failed_pc=0x0c0c1202u; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1204;
P_0c0c1204: /* original a2a6, guest PC 0x0c0c1204 */
if(!s->budget--) { s->failed_pc=0x0c0c1204u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0c1754u,s,ram);
P_0c0c1206: /* original 7f0c, guest PC 0x0c0c1206 */
if(!s->budget--) { s->failed_pc=0x0c0c1206u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c1208;
P_0c0c1208: /* original 2fe6, guest PC 0x0c0c1208 */
if(!s->budget--) { s->failed_pc=0x0c0c1208u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c120a;
P_0c0c120a: /* original e603, guest PC 0x0c0c120a */
if(!s->budget--) { s->failed_pc=0x0c0c120au; return 0; }
r[6]=0x00000003u;
goto P_0c0c120c;
P_0c0c120c: /* original 4f22, guest PC 0x0c0c120c */
if(!s->budget--) { s->failed_pc=0x0c0c120cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c120e;
P_0c0c120e: /* original 9063, guest PC 0x0c0c120e */
if(!s->budget--) { s->failed_pc=0x0c0c120eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12d8u,2);
goto P_0c0c1210;
P_0c0c1210: /* original 3f0c, guest PC 0x0c0c1210 */
if(!s->budget--) { s->failed_pc=0x0c0c1210u; return 0; }
r[15]+=r[0];
goto P_0c0c1212;
P_0c0c1212: /* original 2f42, guest PC 0x0c0c1212 */
if(!s->budget--) { s->failed_pc=0x0c0c1212u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c1214;
P_0c0c1214: /* original 6ef3, guest PC 0x0c0c1214 */
if(!s->budget--) { s->failed_pc=0x0c0c1214u; return 0; }
r[14]=r[15];
goto P_0c0c1216;
P_0c0c1216: /* original 9060, guest PC 0x0c0c1216 */
if(!s->budget--) { s->failed_pc=0x0c0c1216u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1218;
P_0c0c1218: /* original 30fc, guest PC 0x0c0c1218 */
if(!s->budget--) { s->failed_pc=0x0c0c1218u; return 0; }
r[0]+=r[15];
goto P_0c0c121a;
P_0c0c121a: /* original 7004, guest PC 0x0c0c121a */
if(!s->budget--) { s->failed_pc=0x0c0c121au; return 0; }
r[0]+=0x00000004u;
goto P_0c0c121c;
P_0c0c121c: /* original 2608, guest PC 0x0c0c121c */
if(!s->budget--) { s->failed_pc=0x0c0c121cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c0c121e;
P_0c0c121e: /* original 8d04, guest PC 0x0c0c121e */
if(!s->budget--) { s->failed_pc=0x0c0c121eu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(cond) { goto P_0c0c122a; }
goto P_0c0c1222;
P_0c0c1220: /* original 7e04, guest PC 0x0c0c1220 */
if(!s->budget--) { s->failed_pc=0x0c0c1220u; return 0; }
r[14]+=0x00000004u;
goto P_0c0c1222;
P_0c0c1222: /* original 965a, guest PC 0x0c0c1222 */
if(!s->budget--) { s->failed_pc=0x0c0c1222u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1224;
P_0c0c1224: /* original 36fc, guest PC 0x0c0c1224 */
if(!s->budget--) { s->failed_pc=0x0c0c1224u; return 0; }
r[6]+=r[15];
goto P_0c0c1226;
P_0c0c1226: /* original a003, guest PC 0x0c0c1226 */
if(!s->budget--) { s->failed_pc=0x0c0c1226u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c1230;
P_0c0c1228: /* original 7608, guest PC 0x0c0c1228 */
if(!s->budget--) { s->failed_pc=0x0c0c1228u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c122a;
P_0c0c122a: /* original 9656, guest PC 0x0c0c122a */
if(!s->budget--) { s->failed_pc=0x0c0c122au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c122c;
P_0c0c122c: /* original 36fc, guest PC 0x0c0c122c */
if(!s->budget--) { s->failed_pc=0x0c0c122cu; return 0; }
r[6]+=r[15];
goto P_0c0c122e;
P_0c0c122e: /* original 7604, guest PC 0x0c0c122e */
if(!s->budget--) { s->failed_pc=0x0c0c122eu; return 0; }
r[6]+=0x00000004u;
goto P_0c0c1230;
P_0c0c1230: /* original 9053, guest PC 0x0c0c1230 */
if(!s->budget--) { s->failed_pc=0x0c0c1230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dau,2);
goto P_0c0c1232;
P_0c0c1232: /* original d32d, guest PC 0x0c0c1232 */
if(!s->budget--) { s->failed_pc=0x0c0c1232u; return 0; }
r[3]=read(ram,0x0c0c12e8u,4);
goto P_0c0c1234;
P_0c0c1234: /* original 05fe, guest PC 0x0c0c1234 */
if(!s->budget--) { s->failed_pc=0x0c0c1234u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0c1236;
P_0c0c1236: /* original 430b, guest PC 0x0c0c1236 */
if(!s->budget--) { s->failed_pc=0x0c0c1236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c123au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c123au) { target=s->pc; goto dispatch; }
goto P_0c0c123a;
P_0c0c1238: /* original 64e3, guest PC 0x0c0c1238 */
if(!s->budget--) { s->failed_pc=0x0c0c1238u; return 0; }
r[4]=r[14];
goto P_0c0c123a;
P_0c0c123a: /* original d42a, guest PC 0x0c0c123a */
if(!s->budget--) { s->failed_pc=0x0c0c123au; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c123c;
P_0c0c123c: /* original 66e3, guest PC 0x0c0c123c */
if(!s->budget--) { s->failed_pc=0x0c0c123cu; return 0; }
r[6]=r[14];
goto P_0c0c123e;
P_0c0c123e: /* original e701, guest PC 0x0c0c123e */
if(!s->budget--) { s->failed_pc=0x0c0c123eu; return 0; }
r[7]=0x00000001u;
goto P_0c0c1240;
P_0c0c1240: /* original b288, guest PC 0x0c0c1240 */
if(!s->budget--) { s->failed_pc=0x0c0c1240u; return 0; }
target=code_base|0x0c0c1754u; r[16]=code_base|0x0c0c1244u;
tmp=read(ram,r[15],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1244u) { target=s->pc; goto dispatch; }
goto P_0c0c1244;
P_0c0c1242: /* original 65f2, guest PC 0x0c0c1242 */
if(!s->budget--) { s->failed_pc=0x0c0c1242u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c1244;
P_0c0c1244: /* original 914a, guest PC 0x0c0c1244 */
if(!s->budget--) { s->failed_pc=0x0c0c1244u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c12dcu,2);
goto P_0c0c1246;
P_0c0c1246: /* original 3f1c, guest PC 0x0c0c1246 */
if(!s->budget--) { s->failed_pc=0x0c0c1246u; return 0; }
r[15]+=r[1];
goto P_0c0c1248;
P_0c0c1248: /* original 4f26, guest PC 0x0c0c1248 */
if(!s->budget--) { s->failed_pc=0x0c0c1248u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c124a;
P_0c0c124a: /* original 000b, guest PC 0x0c0c124a */
if(!s->budget--) { s->failed_pc=0x0c0c124au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c124c: /* original 6ef6, guest PC 0x0c0c124c */
if(!s->budget--) { s->failed_pc=0x0c0c124cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c124eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c124eu; return 0; } return 1;
P_0c0c13c4: /* original 2fe6, guest PC 0x0c0c13c4 */
if(!s->budget--) { s->failed_pc=0x0c0c13c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c13c6;
P_0c0c13c6: /* original 6353, guest PC 0x0c0c13c6 */
if(!s->budget--) { s->failed_pc=0x0c0c13c6u; return 0; }
r[3]=r[5];
goto P_0c0c13c8;
P_0c0c13c8: /* original 2fd6, guest PC 0x0c0c13c8 */
if(!s->budget--) { s->failed_pc=0x0c0c13c8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c13ca;
P_0c0c13ca: /* original 4301, guest PC 0x0c0c13ca */
if(!s->budget--) { s->failed_pc=0x0c0c13cau; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c0c13cc;
P_0c0c13cc: /* original 2fc6, guest PC 0x0c0c13cc */
if(!s->budget--) { s->failed_pc=0x0c0c13ccu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c13ce;
P_0c0c13ce: /* original c730, guest PC 0x0c0c13ce */
if(!s->budget--) { s->failed_pc=0x0c0c13ceu; return 0; }
r[0]=code_base|0x000c1490u;
goto P_0c0c13d0;
P_0c0c13d0: /* original 2fb6, guest PC 0x0c0c13d0 */
if(!s->budget--) { s->failed_pc=0x0c0c13d0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c13d2;
P_0c0c13d2: /* original 6c53, guest PC 0x0c0c13d2 */
if(!s->budget--) { s->failed_pc=0x0c0c13d2u; return 0; }
r[12]=r[5];
goto P_0c0c13d4;
P_0c0c13d4: /* original fffb, guest PC 0x0c0c13d4 */
if(!s->budget--) { s->failed_pc=0x0c0c13d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c13d6;
P_0c0c13d6: /* original 6e63, guest PC 0x0c0c13d6 */
if(!s->budget--) { s->failed_pc=0x0c0c13d6u; return 0; }
r[14]=r[6];
goto P_0c0c13d8;
P_0c0c13d8: /* original ffeb, guest PC 0x0c0c13d8 */
if(!s->budget--) { s->failed_pc=0x0c0c13d8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c13da;
P_0c0c13da: /* original 6b73, guest PC 0x0c0c13da */
if(!s->budget--) { s->failed_pc=0x0c0c13dau; return 0; }
r[11]=r[7];
goto P_0c0c13dc;
P_0c0c13dc: /* original ffdb, guest PC 0x0c0c13dc */
if(!s->budget--) { s->failed_pc=0x0c0c13dcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c13de;
P_0c0c13de: /* original 4f22, guest PC 0x0c0c13de */
if(!s->budget--) { s->failed_pc=0x0c0c13deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c13e0;
P_0c0c13e0: /* original 7fb8, guest PC 0x0c0c13e0 */
if(!s->budget--) { s->failed_pc=0x0c0c13e0u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c0c13e2;
P_0c0c13e2: /* original 2f42, guest PC 0x0c0c13e2 */
if(!s->budget--) { s->failed_pc=0x0c0c13e2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c13e4;
P_0c0c13e4: /* original e43f, guest PC 0x0c0c13e4 */
if(!s->budget--) { s->failed_pc=0x0c0c13e4u; return 0; }
r[4]=0x0000003fu;
goto P_0c0c13e6;
P_0c0c13e6: /* original 2349, guest PC 0x0c0c13e6 */
if(!s->budget--) { s->failed_pc=0x0c0c13e6u; return 0; }
r[3]&=r[4];
goto P_0c0c13e8;
P_0c0c13e8: /* original fd08, guest PC 0x0c0c13e8 */
if(!s->budget--) { s->failed_pc=0x0c0c13e8u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0c13ea;
P_0c0c13ea: /* original 435a, guest PC 0x0c0c13ea */
if(!s->budget--) { s->failed_pc=0x0c0c13eau; return 0; }
r[53]=r[3];
goto P_0c0c13ec;
P_0c0c13ec: /* original 4311, guest PC 0x0c0c13ec */
if(!s->budget--) { s->failed_pc=0x0c0c13ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c13ee;
P_0c0c13ee: /* original 8d04, guest PC 0x0c0c13ee */
if(!s->budget--) { s->failed_pc=0x0c0c13eeu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c13fa; }
goto P_0c0c13f2;
P_0c0c13f0: /* original f32d, guest PC 0x0c0c13f0 */
if(!s->budget--) { s->failed_pc=0x0c0c13f0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c13f2;
P_0c0c13f2: /* original d228, guest PC 0x0c0c13f2 */
if(!s->budget--) { s->failed_pc=0x0c0c13f2u; return 0; }
r[2]=read(ram,0x0c0c1494u,4);
goto P_0c0c13f4;
P_0c0c13f4: /* original 425a, guest PC 0x0c0c13f4 */
if(!s->budget--) { s->failed_pc=0x0c0c13f4u; return 0; }
r[53]=r[2];
goto P_0c0c13f6;
P_0c0c13f6: /* original f20d, guest PC 0x0c0c13f6 */
if(!s->budget--) { s->failed_pc=0x0c0c13f6u; return 0; }
fr[2]=r[53];
goto P_0c0c13f8;
P_0c0c13f8: /* original f320, guest PC 0x0c0c13f8 */
if(!s->budget--) { s->failed_pc=0x0c0c13f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c13fa;
P_0c0c13fa: /* original 63c3, guest PC 0x0c0c13fa */
if(!s->budget--) { s->failed_pc=0x0c0c13fau; return 0; }
r[3]=r[12];
goto P_0c0c13fc;
P_0c0c13fc: /* original e2f9, guest PC 0x0c0c13fc */
if(!s->budget--) { s->failed_pc=0x0c0c13fcu; return 0; }
r[2]=0xfffffff9u;
goto P_0c0c13fe;
P_0c0c13fe: /* original f3d2, guest PC 0x0c0c13fe */
if(!s->budget--) { s->failed_pc=0x0c0c13feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c0c1400;
P_0c0c1400: /* original 432d, guest PC 0x0c0c1400 */
if(!s->budget--) { s->failed_pc=0x0c0c1400u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c0c1402;
P_0c0c1402: /* original 2349, guest PC 0x0c0c1402 */
if(!s->budget--) { s->failed_pc=0x0c0c1402u; return 0; }
r[3]&=r[4];
goto P_0c0c1404;
P_0c0c1404: /* original e010, guest PC 0x0c0c1404 */
if(!s->budget--) { s->failed_pc=0x0c0c1404u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1406;
P_0c0c1406: /* original 4311, guest PC 0x0c0c1406 */
if(!s->budget--) { s->failed_pc=0x0c0c1406u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c1408;
P_0c0c1408: /* original ff37, guest PC 0x0c0c1408 */
if(!s->budget--) { s->failed_pc=0x0c0c1408u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c140a;
P_0c0c140a: /* original 435a, guest PC 0x0c0c140a */
if(!s->budget--) { s->failed_pc=0x0c0c140au; return 0; }
r[53]=r[3];
goto P_0c0c140c;
P_0c0c140c: /* original 8d04, guest PC 0x0c0c140c */
if(!s->budget--) { s->failed_pc=0x0c0c140cu; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1418; }
goto P_0c0c1410;
P_0c0c140e: /* original f22d, guest PC 0x0c0c140e */
if(!s->budget--) { s->failed_pc=0x0c0c140eu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1410;
P_0c0c1410: /* original d120, guest PC 0x0c0c1410 */
if(!s->budget--) { s->failed_pc=0x0c0c1410u; return 0; }
r[1]=read(ram,0x0c0c1494u,4);
goto P_0c0c1412;
P_0c0c1412: /* original 415a, guest PC 0x0c0c1412 */
if(!s->budget--) { s->failed_pc=0x0c0c1412u; return 0; }
r[53]=r[1];
goto P_0c0c1414;
P_0c0c1414: /* original f10d, guest PC 0x0c0c1414 */
if(!s->budget--) { s->failed_pc=0x0c0c1414u; return 0; }
fr[1]=r[53];
goto P_0c0c1416;
P_0c0c1416: /* original f210, guest PC 0x0c0c1416 */
if(!s->budget--) { s->failed_pc=0x0c0c1416u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c0c1418;
P_0c0c1418: /* original f2d2, guest PC 0x0c0c1418 */
if(!s->budget--) { s->failed_pc=0x0c0c1418u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0c141a;
P_0c0c141a: /* original e004, guest PC 0x0c0c141a */
if(!s->budget--) { s->failed_pc=0x0c0c141au; return 0; }
r[0]=0x00000004u;
goto P_0c0c141c;
P_0c0c141c: /* original ff27, guest PC 0x0c0c141c */
if(!s->budget--) { s->failed_pc=0x0c0c141cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c141e;
P_0c0c141e: /* original d31e, guest PC 0x0c0c141e */
if(!s->budget--) { s->failed_pc=0x0c0c141eu; return 0; }
r[3]=read(ram,0x0c0c1498u,4);
goto P_0c0c1420;
P_0c0c1420: /* original 430b, guest PC 0x0c0c1420 */
if(!s->budget--) { s->failed_pc=0x0c0c1420u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1424u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1424u) { target=s->pc; goto dispatch; }
goto P_0c0c1424;
P_0c0c1422: /* original 64b3, guest PC 0x0c0c1422 */
if(!s->budget--) { s->failed_pc=0x0c0c1422u; return 0; }
r[4]=r[11];
goto P_0c0c1424;
P_0c0c1424: /* original 6d03, guest PC 0x0c0c1424 */
if(!s->budget--) { s->failed_pc=0x0c0c1424u; return 0; }
r[13]=r[0];
goto P_0c0c1426;
P_0c0c1426: /* original c71d, guest PC 0x0c0c1426 */
if(!s->budget--) { s->failed_pc=0x0c0c1426u; return 0; }
r[0]=code_base|0x000c149cu;
goto P_0c0c1428;
P_0c0c1428: /* original f408, guest PC 0x0c0c1428 */
if(!s->budget--) { s->failed_pc=0x0c0c1428u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c142a;
P_0c0c142a: /* original 60b3, guest PC 0x0c0c142a */
if(!s->budget--) { s->failed_pc=0x0c0c142au; return 0; }
r[0]=r[11];
goto P_0c0c142c;
P_0c0c142c: /* original 8800, guest PC 0x0c0c142c */
if(!s->budget--) { s->failed_pc=0x0c0c142cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c142e;
P_0c0c142e: /* original 890c, guest PC 0x0c0c142e */
if(!s->budget--) { s->failed_pc=0x0c0c142eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c144a; }
goto P_0c0c1430;
P_0c0c1430: /* original 8853, guest PC 0x0c0c1430 */
if(!s->budget--) { s->failed_pc=0x0c0c1430u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000053u)!=0);
goto P_0c0c1432;
P_0c0c1432: /* original 8918, guest PC 0x0c0c1432 */
if(!s->budget--) { s->failed_pc=0x0c0c1432u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1466; }
goto P_0c0c1434;
P_0c0c1434: /* original 9129, guest PC 0x0c0c1434 */
if(!s->budget--) { s->failed_pc=0x0c0c1434u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c148au,2);
goto P_0c0c1436;
P_0c0c1436: /* original 3010, guest PC 0x0c0c1436 */
if(!s->budget--) { s->failed_pc=0x0c0c1436u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c1438;
P_0c0c1438: /* original 8904, guest PC 0x0c0c1438 */
if(!s->budget--) { s->failed_pc=0x0c0c1438u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1444; }
goto P_0c0c143a;
P_0c0c143a: /* original 9127, guest PC 0x0c0c143a */
if(!s->budget--) { s->failed_pc=0x0c0c143au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c148cu,2);
goto P_0c0c143c;
P_0c0c143c: /* original 3010, guest PC 0x0c0c143c */
if(!s->budget--) { s->failed_pc=0x0c0c143cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c143e;
P_0c0c143e: /* original 8908, guest PC 0x0c0c143e */
if(!s->budget--) { s->failed_pc=0x0c0c143eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1452; }
goto P_0c0c1440;
P_0c0c1440: /* original a01b, guest PC 0x0c0c1440 */
if(!s->budget--) { s->failed_pc=0x0c0c1440u; return 0; }
goto P_0c0c147a;
P_0c0c1442: /* original 0009, guest PC 0x0c0c1442 */
if(!s->budget--) { s->failed_pc=0x0c0c1442u; return 0; }
goto P_0c0c1444;
P_0c0c1444: /* original fedc, guest PC 0x0c0c1444 */
if(!s->budget--) { s->failed_pc=0x0c0c1444u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1446;
P_0c0c1446: /* original a002, guest PC 0x0c0c1446 */
if(!s->budget--) { s->failed_pc=0x0c0c1446u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0c144e;
P_0c0c1448: /* original ffdc, guest PC 0x0c0c1448 */
if(!s->budget--) { s->failed_pc=0x0c0c1448u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0c144a;
P_0c0c144a: /* original ff4c, guest PC 0x0c0c144a */
if(!s->budget--) { s->failed_pc=0x0c0c144au; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c144c;
P_0c0c144c: /* original fedc, guest PC 0x0c0c144c */
if(!s->budget--) { s->failed_pc=0x0c0c144cu; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c144e;
P_0c0c144e: /* original a029, guest PC 0x0c0c144e */
if(!s->budget--) { s->failed_pc=0x0c0c144eu; return 0; }
r[12]+=0x00000002u;
goto P_0c0c14a4;
P_0c0c1450: /* original 7c02, guest PC 0x0c0c1450 */
if(!s->budget--) { s->failed_pc=0x0c0c1450u; return 0; }
r[12]+=0x00000002u;
goto P_0c0c1452;
P_0c0c1452: /* original e261, guest PC 0x0c0c1452 */
if(!s->budget--) { s->failed_pc=0x0c0c1452u; return 0; }
r[2]=0x00000061u;
goto P_0c0c1454;
P_0c0c1454: /* original 3e22, guest PC 0x0c0c1454 */
if(!s->budget--) { s->failed_pc=0x0c0c1454u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c0c1456;
P_0c0c1456: /* original 8b00, guest PC 0x0c0c1456 */
if(!s->budget--) { s->failed_pc=0x0c0c1456u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c145a; }
goto P_0c0c1458;
P_0c0c1458: /* original 7ee0, guest PC 0x0c0c1458 */
if(!s->budget--) { s->failed_pc=0x0c0c1458u; return 0; }
r[14]+=0xffffffe0u;
goto P_0c0c145a;
P_0c0c145a: /* original c711, guest PC 0x0c0c145a */
if(!s->budget--) { s->failed_pc=0x0c0c145au; return 0; }
r[0]=code_base|0x000c14a0u;
goto P_0c0c145c;
P_0c0c145c: /* original fe4c, guest PC 0x0c0c145c */
if(!s->budget--) { s->failed_pc=0x0c0c145cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0c145e;
P_0c0c145e: /* original ff08, guest PC 0x0c0c145e */
if(!s->budget--) { s->failed_pc=0x0c0c145eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c1460;
P_0c0c1460: /* original 7ee0, guest PC 0x0c0c1460 */
if(!s->budget--) { s->failed_pc=0x0c0c1460u; return 0; }
r[14]+=0xffffffe0u;
goto P_0c0c1462;
P_0c0c1462: /* original a01f, guest PC 0x0c0c1462 */
if(!s->budget--) { s->failed_pc=0x0c0c1462u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c14a4;
P_0c0c1464: /* original 7c04, guest PC 0x0c0c1464 */
if(!s->budget--) { s->failed_pc=0x0c0c1464u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c1466;
P_0c0c1466: /* original 60e3, guest PC 0x0c0c1466 */
if(!s->budget--) { s->failed_pc=0x0c0c1466u; return 0; }
r[0]=r[14];
goto P_0c0c1468;
P_0c0c1468: /* original 8820, guest PC 0x0c0c1468 */
if(!s->budget--) { s->failed_pc=0x0c0c1468u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c146a;
P_0c0c146a: /* original fe4c, guest PC 0x0c0c146a */
if(!s->budget--) { s->failed_pc=0x0c0c146au; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0c146c;
P_0c0c146c: /* original ff4c, guest PC 0x0c0c146c */
if(!s->budget--) { s->failed_pc=0x0c0c146cu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c146e;
P_0c0c146e: /* original 8f02, guest PC 0x0c0c146e */
if(!s->budget--) { s->failed_pc=0x0c0c146eu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c0c1476; }
goto P_0c0c1472;
P_0c0c1470: /* original 7c04, guest PC 0x0c0c1470 */
if(!s->budget--) { s->failed_pc=0x0c0c1470u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c1472;
P_0c0c1472: /* original a095, guest PC 0x0c0c1472 */
if(!s->budget--) { s->failed_pc=0x0c0c1472u; return 0; }
goto P_0c0c15a0;
P_0c0c1474: /* original 0009, guest PC 0x0c0c1474 */
if(!s->budget--) { s->failed_pc=0x0c0c1474u; return 0; }
goto P_0c0c1476;
P_0c0c1476: /* original a018, guest PC 0x0c0c1476 */
if(!s->budget--) { s->failed_pc=0x0c0c1476u; return 0; }
r[14]+=0xfffffff0u;
goto P_0c0c14aa;
P_0c0c1478: /* original 7ef0, guest PC 0x0c0c1478 */
if(!s->budget--) { s->failed_pc=0x0c0c1478u; return 0; }
r[14]+=0xfffffff0u;
goto P_0c0c147a;
P_0c0c147a: /* original 7ed0, guest PC 0x0c0c147a */
if(!s->budget--) { s->failed_pc=0x0c0c147au; return 0; }
r[14]+=0xffffffd0u;
goto P_0c0c147c;
P_0c0c147c: /* original 65c3, guest PC 0x0c0c147c */
if(!s->budget--) { s->failed_pc=0x0c0c147cu; return 0; }
r[5]=r[12];
goto P_0c0c147e;
P_0c0c147e: /* original 66e3, guest PC 0x0c0c147e */
if(!s->budget--) { s->failed_pc=0x0c0c147eu; return 0; }
r[6]=r[14];
goto P_0c0c1480;
P_0c0c1480: /* original 67b3, guest PC 0x0c0c1480 */
if(!s->budget--) { s->failed_pc=0x0c0c1480u; return 0; }
r[7]=r[11];
goto P_0c0c1482;
P_0c0c1482: /* original b0b1, guest PC 0x0c0c1482 */
if(!s->budget--) { s->failed_pc=0x0c0c1482u; return 0; }
target=code_base|0x0c0c15e8u; r[16]=code_base|0x0c0c1486u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1486u) { target=s->pc; goto dispatch; }
goto P_0c0c1486;
P_0c0c1484: /* original 64f2, guest PC 0x0c0c1484 */
if(!s->budget--) { s->failed_pc=0x0c0c1484u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c1486;
P_0c0c1486: /* original a08c, guest PC 0x0c0c1486 */
if(!s->budget--) { s->failed_pc=0x0c0c1486u; return 0; }
goto P_0c0c15a2;
P_0c0c1488: /* original 0009, guest PC 0x0c0c1488 */
if(!s->budget--) { s->failed_pc=0x0c0c1488u; return 0; }
if(!vf3_matrix_family(0x0c0c148au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c148au; return 0; } return 1;
P_0c0c14a4: /* original 60e3, guest PC 0x0c0c14a4 */
if(!s->budget--) { s->failed_pc=0x0c0c14a4u; return 0; }
r[0]=r[14];
goto P_0c0c14a6;
P_0c0c14a6: /* original 8820, guest PC 0x0c0c14a6 */
if(!s->budget--) { s->failed_pc=0x0c0c14a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c14a8;
P_0c0c14a8: /* original 897a, guest PC 0x0c0c14a8 */
if(!s->budget--) { s->failed_pc=0x0c0c14a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c15a0; }
goto P_0c0c14aa;
P_0c0c14aa: /* original e30f, guest PC 0x0c0c14aa */
if(!s->budget--) { s->failed_pc=0x0c0c14aau; return 0; }
r[3]=0x0000000fu;
goto P_0c0c14ac;
P_0c0c14ac: /* original 23e9, guest PC 0x0c0c14ac */
if(!s->budget--) { s->failed_pc=0x0c0c14acu; return 0; }
r[3]&=r[14];
goto P_0c0c14ae;
P_0c0c14ae: /* original 435a, guest PC 0x0c0c14ae */
if(!s->budget--) { s->failed_pc=0x0c0c14aeu; return 0; }
r[53]=r[3];
goto P_0c0c14b0;
P_0c0c14b0: /* original 4311, guest PC 0x0c0c14b0 */
if(!s->budget--) { s->failed_pc=0x0c0c14b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c14b2;
P_0c0c14b2: /* original 8d04, guest PC 0x0c0c14b2 */
if(!s->budget--) { s->failed_pc=0x0c0c14b2u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14be; }
goto P_0c0c14b6;
P_0c0c14b4: /* original f32d, guest PC 0x0c0c14b4 */
if(!s->budget--) { s->failed_pc=0x0c0c14b4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14b6;
P_0c0c14b6: /* original d242, guest PC 0x0c0c14b6 */
if(!s->budget--) { s->failed_pc=0x0c0c14b6u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14b8;
P_0c0c14b8: /* original 425a, guest PC 0x0c0c14b8 */
if(!s->budget--) { s->failed_pc=0x0c0c14b8u; return 0; }
r[53]=r[2];
goto P_0c0c14ba;
P_0c0c14ba: /* original f20d, guest PC 0x0c0c14ba */
if(!s->budget--) { s->failed_pc=0x0c0c14bau; return 0; }
fr[2]=r[53];
goto P_0c0c14bc;
P_0c0c14bc: /* original f320, guest PC 0x0c0c14bc */
if(!s->budget--) { s->failed_pc=0x0c0c14bcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14be;
P_0c0c14be: /* original f1d8, guest PC 0x0c0c14be */
if(!s->budget--) { s->failed_pc=0x0c0c14beu; return 0; }
vf3_matrix_load(s,ram,1,r[13]);
goto P_0c0c14c0;
P_0c0c14c0: /* original e008, guest PC 0x0c0c14c0 */
if(!s->budget--) { s->failed_pc=0x0c0c14c0u; return 0; }
r[0]=0x00000008u;
goto P_0c0c14c2;
P_0c0c14c2: /* original f0ec, guest PC 0x0c0c14c2 */
if(!s->budget--) { s->failed_pc=0x0c0c14c2u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0c14c4;
P_0c0c14c4: /* original f13e, guest PC 0x0c0c14c4 */
if(!s->budget--) { s->failed_pc=0x0c0c14c4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14c6;
P_0c0c14c6: /* original ff17, guest PC 0x0c0c14c6 */
if(!s->budget--) { s->failed_pc=0x0c0c14c6u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14c8;
P_0c0c14c8: /* original 9375, guest PC 0x0c0c14c8 */
if(!s->budget--) { s->failed_pc=0x0c0c14c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b6u,2);
goto P_0c0c14ca;
P_0c0c14ca: /* original 2e39, guest PC 0x0c0c14ca */
if(!s->budget--) { s->failed_pc=0x0c0c14cau; return 0; }
r[14]&=r[3];
goto P_0c0c14cc;
P_0c0c14cc: /* original 4e09, guest PC 0x0c0c14cc */
if(!s->budget--) { s->failed_pc=0x0c0c14ccu; return 0; }
r[14]>>=2;
goto P_0c0c14ce;
P_0c0c14ce: /* original 4e09, guest PC 0x0c0c14ce */
if(!s->budget--) { s->failed_pc=0x0c0c14ceu; return 0; }
r[14]>>=2;
goto P_0c0c14d0;
P_0c0c14d0: /* original 4e5a, guest PC 0x0c0c14d0 */
if(!s->budget--) { s->failed_pc=0x0c0c14d0u; return 0; }
r[53]=r[14];
goto P_0c0c14d2;
P_0c0c14d2: /* original 4e11, guest PC 0x0c0c14d2 */
if(!s->budget--) { s->failed_pc=0x0c0c14d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c14d4;
P_0c0c14d4: /* original 8d04, guest PC 0x0c0c14d4 */
if(!s->budget--) { s->failed_pc=0x0c0c14d4u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14e0; }
goto P_0c0c14d8;
P_0c0c14d6: /* original f32d, guest PC 0x0c0c14d6 */
if(!s->budget--) { s->failed_pc=0x0c0c14d6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14d8;
P_0c0c14d8: /* original d239, guest PC 0x0c0c14d8 */
if(!s->budget--) { s->failed_pc=0x0c0c14d8u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14da;
P_0c0c14da: /* original 425a, guest PC 0x0c0c14da */
if(!s->budget--) { s->failed_pc=0x0c0c14dau; return 0; }
r[53]=r[2];
goto P_0c0c14dc;
P_0c0c14dc: /* original f20d, guest PC 0x0c0c14dc */
if(!s->budget--) { s->failed_pc=0x0c0c14dcu; return 0; }
fr[2]=r[53];
goto P_0c0c14de;
P_0c0c14de: /* original f320, guest PC 0x0c0c14de */
if(!s->budget--) { s->failed_pc=0x0c0c14deu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14e0;
P_0c0c14e0: /* original e004, guest PC 0x0c0c14e0 */
if(!s->budget--) { s->failed_pc=0x0c0c14e0u; return 0; }
r[0]=0x00000004u;
goto P_0c0c14e2;
P_0c0c14e2: /* original f0fc, guest PC 0x0c0c14e2 */
if(!s->budget--) { s->failed_pc=0x0c0c14e2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c14e4;
P_0c0c14e4: /* original f1d6, guest PC 0x0c0c14e4 */
if(!s->budget--) { s->failed_pc=0x0c0c14e4u; return 0; }
vf3_matrix_load(s,ram,1,r[13]+r[0]);
goto P_0c0c14e6;
P_0c0c14e6: /* original e00c, guest PC 0x0c0c14e6 */
if(!s->budget--) { s->failed_pc=0x0c0c14e6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c14e8;
P_0c0c14e8: /* original 64f3, guest PC 0x0c0c14e8 */
if(!s->budget--) { s->failed_pc=0x0c0c14e8u; return 0; }
r[4]=r[15];
goto P_0c0c14ea;
P_0c0c14ea: /* original f13e, guest PC 0x0c0c14ea */
if(!s->budget--) { s->failed_pc=0x0c0c14eau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14ec;
P_0c0c14ec: /* original ff17, guest PC 0x0c0c14ec */
if(!s->budget--) { s->failed_pc=0x0c0c14ecu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14ee;
P_0c0c14ee: /* original e010, guest PC 0x0c0c14ee */
if(!s->budget--) { s->failed_pc=0x0c0c14eeu; return 0; }
r[0]=0x00000010u;
goto P_0c0c14f0;
P_0c0c14f0: /* original f3d6, guest PC 0x0c0c14f0 */
if(!s->budget--) { s->failed_pc=0x0c0c14f0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14f2;
P_0c0c14f2: /* original e014, guest PC 0x0c0c14f2 */
if(!s->budget--) { s->failed_pc=0x0c0c14f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0c14f4;
P_0c0c14f4: /* original f6ec, guest PC 0x0c0c14f4 */
if(!s->budget--) { s->failed_pc=0x0c0c14f4u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c14f6;
P_0c0c14f6: /* original f632, guest PC 0x0c0c14f6 */
if(!s->budget--) { s->failed_pc=0x0c0c14f6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c14f8;
P_0c0c14f8: /* original 62f2, guest PC 0x0c0c14f8 */
if(!s->budget--) { s->failed_pc=0x0c0c14f8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c14fa;
P_0c0c14fa: /* original f3d6, guest PC 0x0c0c14fa */
if(!s->budget--) { s->failed_pc=0x0c0c14fau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14fc;
P_0c0c14fc: /* original e024, guest PC 0x0c0c14fc */
if(!s->budget--) { s->failed_pc=0x0c0c14fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0c14fe;
P_0c0c14fe: /* original 012d, guest PC 0x0c0c14fe */
if(!s->budget--) { s->failed_pc=0x0c0c14feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c1500;
P_0c0c1500: /* original d030, guest PC 0x0c0c1500 */
if(!s->budget--) { s->failed_pc=0x0c0c1500u; return 0; }
r[0]=read(ram,0x0c0c15c4u,4);
goto P_0c0c1502;
P_0c0c1502: /* original 611d, guest PC 0x0c0c1502 */
if(!s->budget--) { s->failed_pc=0x0c0c1502u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1504;
P_0c0c1504: /* original f70c, guest PC 0x0c0c1504 */
if(!s->budget--) { s->failed_pc=0x0c0c1504u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0c1506;
P_0c0c1506: /* original 4108, guest PC 0x0c0c1506 */
if(!s->budget--) { s->failed_pc=0x0c0c1506u; return 0; }
r[1]<<=2;
goto P_0c0c1508;
P_0c0c1508: /* original f732, guest PC 0x0c0c1508 */
if(!s->budget--) { s->failed_pc=0x0c0c1508u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c150a;
P_0c0c150a: /* original f816, guest PC 0x0c0c150a */
if(!s->budget--) { s->failed_pc=0x0c0c150au; return 0; }
vf3_matrix_load(s,ram,8,r[1]+r[0]);
goto P_0c0c150c;
P_0c0c150c: /* original e004, guest PC 0x0c0c150c */
if(!s->budget--) { s->failed_pc=0x0c0c150cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c150e;
P_0c0c150e: /* original f5f6, guest PC 0x0c0c150e */
if(!s->budget--) { s->failed_pc=0x0c0c150eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1510;
P_0c0c1510: /* original e010, guest PC 0x0c0c1510 */
if(!s->budget--) { s->failed_pc=0x0c0c1510u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1512;
P_0c0c1512: /* original d22d, guest PC 0x0c0c1512 */
if(!s->budget--) { s->failed_pc=0x0c0c1512u; return 0; }
r[2]=read(ram,0x0c0c15c8u,4);
goto P_0c0c1514;
P_0c0c1514: /* original f4f6, guest PC 0x0c0c1514 */
if(!s->budget--) { s->failed_pc=0x0c0c1514u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c1516;
P_0c0c1516: /* original 420b, guest PC 0x0c0c1516 */
if(!s->budget--) { s->failed_pc=0x0c0c1516u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c151au;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c151au) { target=s->pc; goto dispatch; }
goto P_0c0c151a;
P_0c0c1518: /* original 7414, guest PC 0x0c0c1518 */
if(!s->budget--) { s->failed_pc=0x0c0c1518u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c151a;
P_0c0c151a: /* original e014, guest PC 0x0c0c151a */
if(!s->budget--) { s->failed_pc=0x0c0c151au; return 0; }
r[0]=0x00000014u;
goto P_0c0c151c;
P_0c0c151c: /* original d32b, guest PC 0x0c0c151c */
if(!s->budget--) { s->failed_pc=0x0c0c151cu; return 0; }
r[3]=read(ram,0x0c0c15ccu,4);
goto P_0c0c151e;
P_0c0c151e: /* original f9d6, guest PC 0x0c0c151e */
if(!s->budget--) { s->failed_pc=0x0c0c151eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0c1520;
P_0c0c1520: /* original e010, guest PC 0x0c0c1520 */
if(!s->budget--) { s->failed_pc=0x0c0c1520u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1522;
P_0c0c1522: /* original f8d6, guest PC 0x0c0c1522 */
if(!s->budget--) { s->failed_pc=0x0c0c1522u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0c1524;
P_0c0c1524: /* original e00c, guest PC 0x0c0c1524 */
if(!s->budget--) { s->failed_pc=0x0c0c1524u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1526;
P_0c0c1526: /* original f5f6, guest PC 0x0c0c1526 */
if(!s->budget--) { s->failed_pc=0x0c0c1526u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1528;
P_0c0c1528: /* original e008, guest PC 0x0c0c1528 */
if(!s->budget--) { s->failed_pc=0x0c0c1528u; return 0; }
r[0]=0x00000008u;
goto P_0c0c152a;
P_0c0c152a: /* original f4f6, guest PC 0x0c0c152a */
if(!s->budget--) { s->failed_pc=0x0c0c152au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c152c;
P_0c0c152c: /* original 64f3, guest PC 0x0c0c152c */
if(!s->budget--) { s->failed_pc=0x0c0c152cu; return 0; }
r[4]=r[15];
goto P_0c0c152e;
P_0c0c152e: /* original f7fc, guest PC 0x0c0c152e */
if(!s->budget--) { s->failed_pc=0x0c0c152eu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1530;
P_0c0c1530: /* original f6ec, guest PC 0x0c0c1530 */
if(!s->budget--) { s->failed_pc=0x0c0c1530u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1532;
P_0c0c1532: /* original 430b, guest PC 0x0c0c1532 */
if(!s->budget--) { s->failed_pc=0x0c0c1532u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1536u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1536u) { target=s->pc; goto dispatch; }
goto P_0c0c1536;
P_0c0c1534: /* original 7414, guest PC 0x0c0c1534 */
if(!s->budget--) { s->failed_pc=0x0c0c1534u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c1536;
P_0c0c1536: /* original f39d, guest PC 0x0c0c1536 */
if(!s->budget--) { s->failed_pc=0x0c0c1536u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1538;
P_0c0c1538: /* original e044, guest PC 0x0c0c1538 */
if(!s->budget--) { s->failed_pc=0x0c0c1538u; return 0; }
r[0]=0x00000044u;
goto P_0c0c153a;
P_0c0c153a: /* original 943d, guest PC 0x0c0c153a */
if(!s->budget--) { s->failed_pc=0x0c0c153au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b8u,2);
goto P_0c0c153c;
P_0c0c153c: /* original ff37, guest PC 0x0c0c153c */
if(!s->budget--) { s->failed_pc=0x0c0c153cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c153e;
P_0c0c153e: /* original d324, guest PC 0x0c0c153e */
if(!s->budget--) { s->failed_pc=0x0c0c153eu; return 0; }
r[3]=read(ram,0x0c0c15d0u,4);
goto P_0c0c1540;
P_0c0c1540: /* original 923c, guest PC 0x0c0c1540 */
if(!s->budget--) { s->failed_pc=0x0c0c1540u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bcu,2);
goto P_0c0c1542;
P_0c0c1542: /* original 6532, guest PC 0x0c0c1542 */
if(!s->budget--) { s->failed_pc=0x0c0c1542u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c1544;
P_0c0c1544: /* original 9639, guest PC 0x0c0c1544 */
if(!s->budget--) { s->failed_pc=0x0c0c1544u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bau,2);
goto P_0c0c1546;
P_0c0c1546: /* original 2258, guest PC 0x0c0c1546 */
if(!s->budget--) { s->failed_pc=0x0c0c1546u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c1548;
P_0c0c1548: /* original 8901, guest PC 0x0c0c1548 */
if(!s->budget--) { s->failed_pc=0x0c0c1548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c154e; }
goto P_0c0c154a;
P_0c0c154a: /* original a01b, guest PC 0x0c0c154a */
if(!s->budget--) { s->failed_pc=0x0c0c154au; return 0; }
r[4]=r[6];
goto P_0c0c1584;
P_0c0c154c: /* original 6463, guest PC 0x0c0c154c */
if(!s->budget--) { s->failed_pc=0x0c0c154cu; return 0; }
r[4]=r[6];
goto P_0c0c154e;
P_0c0c154e: /* original 9136, guest PC 0x0c0c154e */
if(!s->budget--) { s->failed_pc=0x0c0c154eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15beu,2);
goto P_0c0c1550;
P_0c0c1550: /* original 2518, guest PC 0x0c0c1550 */
if(!s->budget--) { s->failed_pc=0x0c0c1550u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c1552;
P_0c0c1552: /* original 8917, guest PC 0x0c0c1552 */
if(!s->budget--) { s->failed_pc=0x0c0c1552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1584; }
goto P_0c0c1554;
P_0c0c1554: /* original c71f, guest PC 0x0c0c1554 */
if(!s->budget--) { s->failed_pc=0x0c0c1554u; return 0; }
r[0]=code_base|0x000c15d4u;
goto P_0c0c1556;
P_0c0c1556: /* original 6463, guest PC 0x0c0c1556 */
if(!s->budget--) { s->failed_pc=0x0c0c1556u; return 0; }
r[4]=r[6];
goto P_0c0c1558;
P_0c0c1558: /* original f308, guest PC 0x0c0c1558 */
if(!s->budget--) { s->failed_pc=0x0c0c1558u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c155a;
P_0c0c155a: /* original e044, guest PC 0x0c0c155a */
if(!s->budget--) { s->failed_pc=0x0c0c155au; return 0; }
r[0]=0x00000044u;
goto P_0c0c155c;
P_0c0c155c: /* original ff37, guest PC 0x0c0c155c */
if(!s->budget--) { s->failed_pc=0x0c0c155cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c155e;
P_0c0c155e: /* original c71e, guest PC 0x0c0c155e */
if(!s->budget--) { s->failed_pc=0x0c0c155eu; return 0; }
r[0]=code_base|0x000c15d8u;
goto P_0c0c1560;
P_0c0c1560: /* original f308, guest PC 0x0c0c1560 */
if(!s->budget--) { s->failed_pc=0x0c0c1560u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1562;
P_0c0c1562: /* original e024, guest PC 0x0c0c1562 */
if(!s->budget--) { s->failed_pc=0x0c0c1562u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1564;
P_0c0c1564: /* original f2f6, guest PC 0x0c0c1564 */
if(!s->budget--) { s->failed_pc=0x0c0c1564u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1566;
P_0c0c1566: /* original e024, guest PC 0x0c0c1566 */
if(!s->budget--) { s->failed_pc=0x0c0c1566u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1568;
P_0c0c1568: /* original f231, guest PC 0x0c0c1568 */
if(!s->budget--) { s->failed_pc=0x0c0c1568u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c156a;
P_0c0c156a: /* original ff27, guest PC 0x0c0c156a */
if(!s->budget--) { s->failed_pc=0x0c0c156au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c156c;
P_0c0c156c: /* original c71b, guest PC 0x0c0c156c */
if(!s->budget--) { s->failed_pc=0x0c0c156cu; return 0; }
r[0]=code_base|0x000c15dcu;
goto P_0c0c156e;
P_0c0c156e: /* original f408, guest PC 0x0c0c156e */
if(!s->budget--) { s->failed_pc=0x0c0c156eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c1570;
P_0c0c1570: /* original e02c, guest PC 0x0c0c1570 */
if(!s->budget--) { s->failed_pc=0x0c0c1570u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1572;
P_0c0c1572: /* original f2f6, guest PC 0x0c0c1572 */
if(!s->budget--) { s->failed_pc=0x0c0c1572u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1574;
P_0c0c1574: /* original e02c, guest PC 0x0c0c1574 */
if(!s->budget--) { s->failed_pc=0x0c0c1574u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1576;
P_0c0c1576: /* original f240, guest PC 0x0c0c1576 */
if(!s->budget--) { s->failed_pc=0x0c0c1576u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1578;
P_0c0c1578: /* original ff27, guest PC 0x0c0c1578 */
if(!s->budget--) { s->failed_pc=0x0c0c1578u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c157a;
P_0c0c157a: /* original e034, guest PC 0x0c0c157a */
if(!s->budget--) { s->failed_pc=0x0c0c157au; return 0; }
r[0]=0x00000034u;
goto P_0c0c157c;
P_0c0c157c: /* original f2f6, guest PC 0x0c0c157c */
if(!s->budget--) { s->failed_pc=0x0c0c157cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c157e;
P_0c0c157e: /* original e034, guest PC 0x0c0c157e */
if(!s->budget--) { s->failed_pc=0x0c0c157eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c1580;
P_0c0c1580: /* original f241, guest PC 0x0c0c1580 */
if(!s->budget--) { s->failed_pc=0x0c0c1580u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c0c1582;
P_0c0c1582: /* original ff27, guest PC 0x0c0c1582 */
if(!s->budget--) { s->failed_pc=0x0c0c1582u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1584;
P_0c0c1584: /* original 53d8, guest PC 0x0c0c1584 */
if(!s->budget--) { s->failed_pc=0x0c0c1584u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c0c1586;
P_0c0c1586: /* original d016, guest PC 0x0c0c1586 */
if(!s->budget--) { s->failed_pc=0x0c0c1586u; return 0; }
r[0]=read(ram,0x0c0c15e0u,4);
goto P_0c0c1588;
P_0c0c1588: /* original 4300, guest PC 0x0c0c1588 */
if(!s->budget--) { s->failed_pc=0x0c0c1588u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c158a;
P_0c0c158a: /* original 023d, guest PC 0x0c0c158a */
if(!s->budget--) { s->failed_pc=0x0c0c158au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c158c;
P_0c0c158c: /* original e300, guest PC 0x0c0c158c */
if(!s->budget--) { s->failed_pc=0x0c0c158cu; return 0; }
r[3]=0x00000000u;
goto P_0c0c158e;
P_0c0c158e: /* original e040, guest PC 0x0c0c158e */
if(!s->budget--) { s->failed_pc=0x0c0c158eu; return 0; }
r[0]=0x00000040u;
goto P_0c0c1590;
P_0c0c1590: /* original 622d, guest PC 0x0c0c1590 */
if(!s->budget--) { s->failed_pc=0x0c0c1590u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1592;
P_0c0c1592: /* original 1f25, guest PC 0x0c0c1592 */
if(!s->budget--) { s->failed_pc=0x0c0c1592u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0c1594;
P_0c0c1594: /* original 1f3f, guest PC 0x0c0c1594 */
if(!s->budget--) { s->failed_pc=0x0c0c1594u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0c1596;
P_0c0c1596: /* original 0f46, guest PC 0x0c0c1596 */
if(!s->budget--) { s->failed_pc=0x0c0c1596u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c0c1598;
P_0c0c1598: /* original 64f3, guest PC 0x0c0c1598 */
if(!s->budget--) { s->failed_pc=0x0c0c1598u; return 0; }
r[4]=r[15];
goto P_0c0c159a;
P_0c0c159a: /* original d312, guest PC 0x0c0c159a */
if(!s->budget--) { s->failed_pc=0x0c0c159au; return 0; }
r[3]=read(ram,0x0c0c15e4u,4);
goto P_0c0c159c;
P_0c0c159c: /* original 430b, guest PC 0x0c0c159c */
if(!s->budget--) { s->failed_pc=0x0c0c159cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c15a0u;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c15a0u) { target=s->pc; goto dispatch; }
goto P_0c0c15a0;
P_0c0c159e: /* original 7414, guest PC 0x0c0c159e */
if(!s->budget--) { s->failed_pc=0x0c0c159eu; return 0; }
r[4]+=0x00000014u;
goto P_0c0c15a0;
P_0c0c15a0: /* original 60c3, guest PC 0x0c0c15a0 */
if(!s->budget--) { s->failed_pc=0x0c0c15a0u; return 0; }
r[0]=r[12];
goto P_0c0c15a2;
P_0c0c15a2: /* original 7f48, guest PC 0x0c0c15a2 */
if(!s->budget--) { s->failed_pc=0x0c0c15a2u; return 0; }
r[15]+=0x00000048u;
goto P_0c0c15a4;
P_0c0c15a4: /* original 4f26, guest PC 0x0c0c15a4 */
if(!s->budget--) { s->failed_pc=0x0c0c15a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c15a6;
P_0c0c15a6: /* original fdf9, guest PC 0x0c0c15a6 */
if(!s->budget--) { s->failed_pc=0x0c0c15a6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15a8;
P_0c0c15a8: /* original fef9, guest PC 0x0c0c15a8 */
if(!s->budget--) { s->failed_pc=0x0c0c15a8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15aa;
P_0c0c15aa: /* original fff9, guest PC 0x0c0c15aa */
if(!s->budget--) { s->failed_pc=0x0c0c15aau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15ac;
P_0c0c15ac: /* original 6bf6, guest PC 0x0c0c15ac */
if(!s->budget--) { s->failed_pc=0x0c0c15acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c15ae;
P_0c0c15ae: /* original 6cf6, guest PC 0x0c0c15ae */
if(!s->budget--) { s->failed_pc=0x0c0c15aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c15b0;
P_0c0c15b0: /* original 6df6, guest PC 0x0c0c15b0 */
if(!s->budget--) { s->failed_pc=0x0c0c15b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c15b2;
P_0c0c15b2: /* original 000b, guest PC 0x0c0c15b2 */
if(!s->budget--) { s->failed_pc=0x0c0c15b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c15b4: /* original 6ef6, guest PC 0x0c0c15b4 */
if(!s->budget--) { s->failed_pc=0x0c0c15b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c15b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c15b6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
