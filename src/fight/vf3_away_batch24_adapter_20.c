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
int vf3_away_batch24_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c1192u: goto P_0c0c1192;
case 0x0c0c1194u: goto P_0c0c1194;
case 0x0c0c1196u: goto P_0c0c1196;
case 0x0c0c1198u: goto P_0c0c1198;
case 0x0c0c119au: goto P_0c0c119a;
case 0x0c0c119cu: goto P_0c0c119c;
case 0x0c0c119eu: goto P_0c0c119e;
case 0x0c0c11a0u: goto P_0c0c11a0;
case 0x0c0c11a2u: goto P_0c0c11a2;
case 0x0c0c11a4u: goto P_0c0c11a4;
case 0x0c0c11a6u: goto P_0c0c11a6;
case 0x0c0c11a8u: goto P_0c0c11a8;
case 0x0c0c11aau: goto P_0c0c11aa;
case 0x0c0c11acu: goto P_0c0c11ac;
case 0x0c0c11aeu: goto P_0c0c11ae;
case 0x0c0c11b0u: goto P_0c0c11b0;
case 0x0c0c11b2u: goto P_0c0c11b2;
case 0x0c0c11b4u: goto P_0c0c11b4;
case 0x0c0c11b6u: goto P_0c0c11b6;
case 0x0c0c11b8u: goto P_0c0c11b8;
case 0x0c0c11bau: goto P_0c0c11ba;
case 0x0c0c11bcu: goto P_0c0c11bc;
case 0x0c0c11beu: goto P_0c0c11be;
case 0x0c0c11c0u: goto P_0c0c11c0;
case 0x0c0c11c2u: goto P_0c0c11c2;
case 0x0c0c11c4u: goto P_0c0c11c4;
case 0x0c0c11c6u: goto P_0c0c11c6;
case 0x0c0c11c8u: goto P_0c0c11c8;
case 0x0c0c11cau: goto P_0c0c11ca;
case 0x0c0c11ccu: goto P_0c0c11cc;
case 0x0c0c12f0u: goto P_0c0c12f0;
case 0x0c0c12f2u: goto P_0c0c12f2;
case 0x0c0c12f4u: goto P_0c0c12f4;
case 0x0c0c12f6u: goto P_0c0c12f6;
case 0x0c0c12f8u: goto P_0c0c12f8;
case 0x0c0c12fau: goto P_0c0c12fa;
case 0x0c0c12fcu: goto P_0c0c12fc;
case 0x0c0c12feu: goto P_0c0c12fe;
case 0x0c0c1300u: goto P_0c0c1300;
case 0x0c0c1302u: goto P_0c0c1302;
case 0x0c0c1304u: goto P_0c0c1304;
case 0x0c0c1306u: goto P_0c0c1306;
case 0x0c0c1308u: goto P_0c0c1308;
case 0x0c0c130au: goto P_0c0c130a;
case 0x0c0c130cu: goto P_0c0c130c;
case 0x0c0c130eu: goto P_0c0c130e;
case 0x0c0c1310u: goto P_0c0c1310;
case 0x0c0c1312u: goto P_0c0c1312;
case 0x0c0c1314u: goto P_0c0c1314;
case 0x0c0c1316u: goto P_0c0c1316;
case 0x0c0c1318u: goto P_0c0c1318;
case 0x0c0c131au: goto P_0c0c131a;
case 0x0c0c131cu: goto P_0c0c131c;
case 0x0c0c131eu: goto P_0c0c131e;
case 0x0c0c1320u: goto P_0c0c1320;
case 0x0c0c1322u: goto P_0c0c1322;
case 0x0c0c1324u: goto P_0c0c1324;
case 0x0c0c1326u: goto P_0c0c1326;
case 0x0c0c1328u: goto P_0c0c1328;
case 0x0c0c132au: goto P_0c0c132a;
case 0x0c0c132cu: goto P_0c0c132c;
case 0x0c0c132eu: goto P_0c0c132e;
case 0x0c0c1330u: goto P_0c0c1330;
case 0x0c0c1332u: goto P_0c0c1332;
case 0x0c0c1334u: goto P_0c0c1334;
case 0x0c0c1336u: goto P_0c0c1336;
case 0x0c0c1338u: goto P_0c0c1338;
case 0x0c0c133au: goto P_0c0c133a;
case 0x0c0c133cu: goto P_0c0c133c;
case 0x0c0c133eu: goto P_0c0c133e;
case 0x0c0c1340u: goto P_0c0c1340;
case 0x0c0c1342u: goto P_0c0c1342;
case 0x0c0c1344u: goto P_0c0c1344;
case 0x0c0c1346u: goto P_0c0c1346;
case 0x0c0c1348u: goto P_0c0c1348;
case 0x0c0c134au: goto P_0c0c134a;
case 0x0c0c134cu: goto P_0c0c134c;
case 0x0c0c134eu: goto P_0c0c134e;
case 0x0c0c1350u: goto P_0c0c1350;
case 0x0c0c1352u: goto P_0c0c1352;
case 0x0c0c1354u: goto P_0c0c1354;
case 0x0c0c1356u: goto P_0c0c1356;
case 0x0c0c1358u: goto P_0c0c1358;
case 0x0c0c135au: goto P_0c0c135a;
case 0x0c0c135cu: goto P_0c0c135c;
case 0x0c0c135eu: goto P_0c0c135e;
case 0x0c0c1360u: goto P_0c0c1360;
case 0x0c0c1362u: goto P_0c0c1362;
case 0x0c0c1364u: goto P_0c0c1364;
case 0x0c0c1366u: goto P_0c0c1366;
case 0x0c0c1368u: goto P_0c0c1368;
case 0x0c0c136au: goto P_0c0c136a;
case 0x0c0c136cu: goto P_0c0c136c;
case 0x0c0c136eu: goto P_0c0c136e;
case 0x0c0c1370u: goto P_0c0c1370;
case 0x0c0c1372u: goto P_0c0c1372;
case 0x0c0c1374u: goto P_0c0c1374;
case 0x0c0c1376u: goto P_0c0c1376;
case 0x0c0c1378u: goto P_0c0c1378;
case 0x0c0c137au: goto P_0c0c137a;
case 0x0c0c137cu: goto P_0c0c137c;
case 0x0c0c137eu: goto P_0c0c137e;
case 0x0c0c1380u: goto P_0c0c1380;
case 0x0c0c1382u: goto P_0c0c1382;
case 0x0c0c1384u: goto P_0c0c1384;
case 0x0c0c1386u: goto P_0c0c1386;
case 0x0c0c1388u: goto P_0c0c1388;
case 0x0c0c138au: goto P_0c0c138a;
case 0x0c0c138cu: goto P_0c0c138c;
case 0x0c0c138eu: goto P_0c0c138e;
case 0x0c0c1390u: goto P_0c0c1390;
case 0x0c0c1392u: goto P_0c0c1392;
case 0x0c0c1394u: goto P_0c0c1394;
case 0x0c0c1396u: goto P_0c0c1396;
case 0x0c0c1398u: goto P_0c0c1398;
case 0x0c0c139au: goto P_0c0c139a;
case 0x0c0c139cu: goto P_0c0c139c;
case 0x0c0c139eu: goto P_0c0c139e;
case 0x0c0c13a0u: goto P_0c0c13a0;
case 0x0c0c13a2u: goto P_0c0c13a2;
case 0x0c0c13a4u: goto P_0c0c13a4;
case 0x0c0c13a6u: goto P_0c0c13a6;
case 0x0c0c13a8u: goto P_0c0c13a8;
case 0x0c0c13aau: goto P_0c0c13aa;
case 0x0c0c13acu: goto P_0c0c13ac;
case 0x0c0c13aeu: goto P_0c0c13ae;
case 0x0c0c13b0u: goto P_0c0c13b0;
case 0x0c0c13b2u: goto P_0c0c13b2;
case 0x0c0c13b4u: goto P_0c0c13b4;
case 0x0c0c15e8u: goto P_0c0c15e8;
case 0x0c0c15eau: goto P_0c0c15ea;
case 0x0c0c15ecu: goto P_0c0c15ec;
case 0x0c0c15eeu: goto P_0c0c15ee;
case 0x0c0c15f0u: goto P_0c0c15f0;
case 0x0c0c15f2u: goto P_0c0c15f2;
case 0x0c0c15f4u: goto P_0c0c15f4;
case 0x0c0c15f6u: goto P_0c0c15f6;
case 0x0c0c15f8u: goto P_0c0c15f8;
case 0x0c0c15fau: goto P_0c0c15fa;
case 0x0c0c15fcu: goto P_0c0c15fc;
case 0x0c0c15feu: goto P_0c0c15fe;
case 0x0c0c1600u: goto P_0c0c1600;
case 0x0c0c1602u: goto P_0c0c1602;
case 0x0c0c1604u: goto P_0c0c1604;
case 0x0c0c1606u: goto P_0c0c1606;
case 0x0c0c1608u: goto P_0c0c1608;
case 0x0c0c160au: goto P_0c0c160a;
case 0x0c0c160cu: goto P_0c0c160c;
case 0x0c0c160eu: goto P_0c0c160e;
case 0x0c0c1610u: goto P_0c0c1610;
case 0x0c0c1612u: goto P_0c0c1612;
case 0x0c0c1614u: goto P_0c0c1614;
case 0x0c0c1616u: goto P_0c0c1616;
case 0x0c0c1618u: goto P_0c0c1618;
case 0x0c0c1620u: goto P_0c0c1620;
case 0x0c0c1622u: goto P_0c0c1622;
case 0x0c0c1624u: goto P_0c0c1624;
case 0x0c0c1626u: goto P_0c0c1626;
case 0x0c0c1628u: goto P_0c0c1628;
case 0x0c0c162au: goto P_0c0c162a;
case 0x0c0c162cu: goto P_0c0c162c;
case 0x0c0c162eu: goto P_0c0c162e;
case 0x0c0c1630u: goto P_0c0c1630;
case 0x0c0c1632u: goto P_0c0c1632;
case 0x0c0c1634u: goto P_0c0c1634;
case 0x0c0c1636u: goto P_0c0c1636;
case 0x0c0c1638u: goto P_0c0c1638;
case 0x0c0c163au: goto P_0c0c163a;
case 0x0c0c163cu: goto P_0c0c163c;
case 0x0c0c163eu: goto P_0c0c163e;
case 0x0c0c1640u: goto P_0c0c1640;
case 0x0c0c1642u: goto P_0c0c1642;
case 0x0c0c1644u: goto P_0c0c1644;
case 0x0c0c1646u: goto P_0c0c1646;
case 0x0c0c1648u: goto P_0c0c1648;
case 0x0c0c164au: goto P_0c0c164a;
case 0x0c0c164cu: goto P_0c0c164c;
case 0x0c0c164eu: goto P_0c0c164e;
case 0x0c0c1650u: goto P_0c0c1650;
case 0x0c0c1652u: goto P_0c0c1652;
case 0x0c0c1654u: goto P_0c0c1654;
case 0x0c0c1656u: goto P_0c0c1656;
case 0x0c0c1658u: goto P_0c0c1658;
case 0x0c0c165au: goto P_0c0c165a;
case 0x0c0c165cu: goto P_0c0c165c;
case 0x0c0c165eu: goto P_0c0c165e;
case 0x0c0c1660u: goto P_0c0c1660;
case 0x0c0c1662u: goto P_0c0c1662;
case 0x0c0c1664u: goto P_0c0c1664;
case 0x0c0c1666u: goto P_0c0c1666;
case 0x0c0c1668u: goto P_0c0c1668;
case 0x0c0c166au: goto P_0c0c166a;
case 0x0c0c166cu: goto P_0c0c166c;
case 0x0c0c166eu: goto P_0c0c166e;
case 0x0c0c1670u: goto P_0c0c1670;
case 0x0c0c1672u: goto P_0c0c1672;
case 0x0c0c1674u: goto P_0c0c1674;
case 0x0c0c1676u: goto P_0c0c1676;
case 0x0c0c1678u: goto P_0c0c1678;
case 0x0c0c167au: goto P_0c0c167a;
case 0x0c0c167cu: goto P_0c0c167c;
case 0x0c0c167eu: goto P_0c0c167e;
case 0x0c0c1680u: goto P_0c0c1680;
case 0x0c0c1682u: goto P_0c0c1682;
case 0x0c0c1684u: goto P_0c0c1684;
case 0x0c0c1686u: goto P_0c0c1686;
case 0x0c0c1688u: goto P_0c0c1688;
case 0x0c0c168au: goto P_0c0c168a;
case 0x0c0c168cu: goto P_0c0c168c;
case 0x0c0c168eu: goto P_0c0c168e;
case 0x0c0c1690u: goto P_0c0c1690;
case 0x0c0c1692u: goto P_0c0c1692;
case 0x0c0c1694u: goto P_0c0c1694;
case 0x0c0c1696u: goto P_0c0c1696;
case 0x0c0c1698u: goto P_0c0c1698;
case 0x0c0c169au: goto P_0c0c169a;
case 0x0c0c169cu: goto P_0c0c169c;
case 0x0c0c169eu: goto P_0c0c169e;
case 0x0c0c16a0u: goto P_0c0c16a0;
case 0x0c0c16a2u: goto P_0c0c16a2;
case 0x0c0c16a4u: goto P_0c0c16a4;
case 0x0c0c16a6u: goto P_0c0c16a6;
case 0x0c0c16a8u: goto P_0c0c16a8;
case 0x0c0c16aau: goto P_0c0c16aa;
case 0x0c0c16acu: goto P_0c0c16ac;
case 0x0c0c16aeu: goto P_0c0c16ae;
case 0x0c0c16b0u: goto P_0c0c16b0;
case 0x0c0c16b2u: goto P_0c0c16b2;
case 0x0c0c16b4u: goto P_0c0c16b4;
case 0x0c0c16b6u: goto P_0c0c16b6;
case 0x0c0c16b8u: goto P_0c0c16b8;
case 0x0c0c16bau: goto P_0c0c16ba;
case 0x0c0c16bcu: goto P_0c0c16bc;
case 0x0c0c16beu: goto P_0c0c16be;
case 0x0c0c16c0u: goto P_0c0c16c0;
case 0x0c0c16c2u: goto P_0c0c16c2;
case 0x0c0c16c4u: goto P_0c0c16c4;
case 0x0c0c16c6u: goto P_0c0c16c6;
case 0x0c0c16c8u: goto P_0c0c16c8;
case 0x0c0c16cau: goto P_0c0c16ca;
case 0x0c0c16ccu: goto P_0c0c16cc;
case 0x0c0c16ceu: goto P_0c0c16ce;
case 0x0c0c16d0u: goto P_0c0c16d0;
case 0x0c0c16d2u: goto P_0c0c16d2;
case 0x0c0c16d4u: goto P_0c0c16d4;
case 0x0c0c16d6u: goto P_0c0c16d6;
case 0x0c0c16d8u: goto P_0c0c16d8;
case 0x0c0c16dau: goto P_0c0c16da;
case 0x0c0c16dcu: goto P_0c0c16dc;
case 0x0c0c16deu: goto P_0c0c16de;
case 0x0c0c16e0u: goto P_0c0c16e0;
case 0x0c0c16e2u: goto P_0c0c16e2;
case 0x0c0c16e4u: goto P_0c0c16e4;
case 0x0c0c16e6u: goto P_0c0c16e6;
case 0x0c0c16e8u: goto P_0c0c16e8;
case 0x0c0c16eau: goto P_0c0c16ea;
case 0x0c0c16ecu: goto P_0c0c16ec;
case 0x0c0c16eeu: goto P_0c0c16ee;
case 0x0c0c16f0u: goto P_0c0c16f0;
case 0x0c0c16f2u: goto P_0c0c16f2;
case 0x0c0c16f4u: goto P_0c0c16f4;
case 0x0c0c16f6u: goto P_0c0c16f6;
case 0x0c0c16f8u: goto P_0c0c16f8;
case 0x0c0c16fau: goto P_0c0c16fa;
case 0x0c0c16fcu: goto P_0c0c16fc;
case 0x0c0c16feu: goto P_0c0c16fe;
case 0x0c0c1700u: goto P_0c0c1700;
case 0x0c0c1702u: goto P_0c0c1702;
case 0x0c0c1704u: goto P_0c0c1704;
case 0x0c0c1706u: goto P_0c0c1706;
case 0x0c0c1708u: goto P_0c0c1708;
case 0x0c0c170au: goto P_0c0c170a;
case 0x0c0c170cu: goto P_0c0c170c;
case 0x0c0c170eu: goto P_0c0c170e;
case 0x0c0c1710u: goto P_0c0c1710;
case 0x0c0c1712u: goto P_0c0c1712;
case 0x0c0c1714u: goto P_0c0c1714;
case 0x0c0c1716u: goto P_0c0c1716;
case 0x0c0c1718u: goto P_0c0c1718;
case 0x0c0c171au: goto P_0c0c171a;
case 0x0c0c171cu: goto P_0c0c171c;
case 0x0c0c171eu: goto P_0c0c171e;
case 0x0c0c1720u: goto P_0c0c1720;
case 0x0c0c1722u: goto P_0c0c1722;
case 0x0c0c1724u: goto P_0c0c1724;
case 0x0c0c1726u: goto P_0c0c1726;
case 0x0c0c1728u: goto P_0c0c1728;
case 0x0c0c172au: goto P_0c0c172a;
case 0x0c0c172cu: goto P_0c0c172c;
case 0x0c0c172eu: goto P_0c0c172e;
case 0x0c0c1730u: goto P_0c0c1730;
case 0x0c0c1732u: goto P_0c0c1732;
case 0x0c0c1734u: goto P_0c0c1734;
case 0x0c0c1736u: goto P_0c0c1736;
case 0x0c0c1738u: goto P_0c0c1738;
case 0x0c0c173au: goto P_0c0c173a;
case 0x0c0c173cu: goto P_0c0c173c;
case 0x0c0c173eu: goto P_0c0c173e;
case 0x0c0c1740u: goto P_0c0c1740;
case 0x0c0c1742u: goto P_0c0c1742;
case 0x0c0c1744u: goto P_0c0c1744;
case 0x0c0c1746u: goto P_0c0c1746;
case 0x0c0c1748u: goto P_0c0c1748;
case 0x0c0c174au: goto P_0c0c174a;
case 0x0c0c174cu: goto P_0c0c174c;
case 0x0c0c174eu: goto P_0c0c174e;
case 0x0c0c1750u: goto P_0c0c1750;
case 0x0c0c1752u: goto P_0c0c1752;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c1192: /* original 2fe6, guest PC 0x0c0c1192 */
if(!s->budget--) { s->failed_pc=0x0c0c1192u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1194;
P_0c0c1194: /* original d314, guest PC 0x0c0c1194 */
if(!s->budget--) { s->failed_pc=0x0c0c1194u; return 0; }
r[3]=read(ram,0x0c0c11e8u,4);
goto P_0c0c1196;
P_0c0c1196: /* original 7ffc, guest PC 0x0c0c1196 */
if(!s->budget--) { s->failed_pc=0x0c0c1196u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c1198;
P_0c0c1198: /* original d114, guest PC 0x0c0c1198 */
if(!s->budget--) { s->failed_pc=0x0c0c1198u; return 0; }
r[1]=read(ram,0x0c0c11ecu,4);
goto P_0c0c119a;
P_0c0c119a: /* original 6e32, guest PC 0x0c0c119a */
if(!s->budget--) { s->failed_pc=0x0c0c119au; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0c119c;
P_0c0c119c: /* original 6210, guest PC 0x0c0c119c */
if(!s->budget--) { s->failed_pc=0x0c0c119cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0c119e;
P_0c0c119e: /* original 622c, guest PC 0x0c0c119e */
if(!s->budget--) { s->failed_pc=0x0c0c119eu; return 0; }
r[2]=r[2]&255u;
goto P_0c0c11a0;
P_0c0c11a0: /* original 2f22, guest PC 0x0c0c11a0 */
if(!s->budget--) { s->failed_pc=0x0c0c11a0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c11a2;
P_0c0c11a2: /* original d313, guest PC 0x0c0c11a2 */
if(!s->budget--) { s->failed_pc=0x0c0c11a2u; return 0; }
r[3]=read(ram,0x0c0c11f0u,4);
goto P_0c0c11a4;
P_0c0c11a4: /* original 2e39, guest PC 0x0c0c11a4 */
if(!s->budget--) { s->failed_pc=0x0c0c11a4u; return 0; }
r[14]&=r[3];
goto P_0c0c11a6;
P_0c0c11a6: /* original 2ee8, guest PC 0x0c0c11a6 */
if(!s->budget--) { s->failed_pc=0x0c0c11a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c11a8;
P_0c0c11a8: /* original 8b0e, guest PC 0x0c0c11a8 */
if(!s->budget--) { s->failed_pc=0x0c0c11a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c11c8; }
goto P_0c0c11aa;
P_0c0c11aa: /* original 60f2, guest PC 0x0c0c11aa */
if(!s->budget--) { s->failed_pc=0x0c0c11aau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c11ac;
P_0c0c11ac: /* original 8801, guest PC 0x0c0c11ac */
if(!s->budget--) { s->failed_pc=0x0c0c11acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c11ae;
P_0c0c11ae: /* original 890b, guest PC 0x0c0c11ae */
if(!s->budget--) { s->failed_pc=0x0c0c11aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c11c8; }
goto P_0c0c11b0;
P_0c0c11b0: /* original ee3f, guest PC 0x0c0c11b0 */
if(!s->budget--) { s->failed_pc=0x0c0c11b0u; return 0; }
r[14]=0x0000003fu;
goto P_0c0c11b2;
P_0c0c11b2: /* original 26e9, guest PC 0x0c0c11b2 */
if(!s->budget--) { s->failed_pc=0x0c0c11b2u; return 0; }
r[6]&=r[14];
goto P_0c0c11b4;
P_0c0c11b4: /* original 4618, guest PC 0x0c0c11b4 */
if(!s->budget--) { s->failed_pc=0x0c0c11b4u; return 0; }
r[6]<<=8;
goto P_0c0c11b6;
P_0c0c11b6: /* original 25e9, guest PC 0x0c0c11b6 */
if(!s->budget--) { s->failed_pc=0x0c0c11b6u; return 0; }
r[5]&=r[14];
goto P_0c0c11b8;
P_0c0c11b8: /* original 27e9, guest PC 0x0c0c11b8 */
if(!s->budget--) { s->failed_pc=0x0c0c11b8u; return 0; }
r[7]&=r[14];
goto P_0c0c11ba;
P_0c0c11ba: /* original 4728, guest PC 0x0c0c11ba */
if(!s->budget--) { s->failed_pc=0x0c0c11bau; return 0; }
r[7]<<=16;
goto P_0c0c11bc;
P_0c0c11bc: /* original 4508, guest PC 0x0c0c11bc */
if(!s->budget--) { s->failed_pc=0x0c0c11bcu; return 0; }
r[5]<<=2;
goto P_0c0c11be;
P_0c0c11be: /* original 4608, guest PC 0x0c0c11be */
if(!s->budget--) { s->failed_pc=0x0c0c11beu; return 0; }
r[6]<<=2;
goto P_0c0c11c0;
P_0c0c11c0: /* original 4708, guest PC 0x0c0c11c0 */
if(!s->budget--) { s->failed_pc=0x0c0c11c0u; return 0; }
r[7]<<=2;
goto P_0c0c11c2;
P_0c0c11c2: /* original 256b, guest PC 0x0c0c11c2 */
if(!s->budget--) { s->failed_pc=0x0c0c11c2u; return 0; }
r[5]|=r[6];
goto P_0c0c11c4;
P_0c0c11c4: /* original 257b, guest PC 0x0c0c11c4 */
if(!s->budget--) { s->failed_pc=0x0c0c11c4u; return 0; }
r[5]|=r[7];
goto P_0c0c11c6;
P_0c0c11c6: /* original 2452, guest PC 0x0c0c11c6 */
if(!s->budget--) { s->failed_pc=0x0c0c11c6u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0c11c8;
P_0c0c11c8: /* original 7f04, guest PC 0x0c0c11c8 */
if(!s->budget--) { s->failed_pc=0x0c0c11c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c11ca;
P_0c0c11ca: /* original 000b, guest PC 0x0c0c11ca */
if(!s->budget--) { s->failed_pc=0x0c0c11cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c11cc: /* original 6ef6, guest PC 0x0c0c11cc */
if(!s->budget--) { s->failed_pc=0x0c0c11ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c11ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c11ceu; return 0; } return 1;
P_0c0c12f0: /* original 2fe6, guest PC 0x0c0c12f0 */
if(!s->budget--) { s->failed_pc=0x0c0c12f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f2;
P_0c0c12f2: /* original 6353, guest PC 0x0c0c12f2 */
if(!s->budget--) { s->failed_pc=0x0c0c12f2u; return 0; }
r[3]=r[5];
goto P_0c0c12f4;
P_0c0c12f4: /* original 2fc6, guest PC 0x0c0c12f4 */
if(!s->budget--) { s->failed_pc=0x0c0c12f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12f6;
P_0c0c12f6: /* original 6c53, guest PC 0x0c0c12f6 */
if(!s->budget--) { s->failed_pc=0x0c0c12f6u; return 0; }
r[12]=r[5];
goto P_0c0c12f8;
P_0c0c12f8: /* original 2fb6, guest PC 0x0c0c12f8 */
if(!s->budget--) { s->failed_pc=0x0c0c12f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fa;
P_0c0c12fa: /* original 6b53, guest PC 0x0c0c12fa */
if(!s->budget--) { s->failed_pc=0x0c0c12fau; return 0; }
r[11]=r[5];
goto P_0c0c12fc;
P_0c0c12fc: /* original 2fa6, guest PC 0x0c0c12fc */
if(!s->budget--) { s->failed_pc=0x0c0c12fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c12fe;
P_0c0c12fe: /* original 4c29, guest PC 0x0c0c12fe */
if(!s->budget--) { s->failed_pc=0x0c0c12feu; return 0; }
r[12]>>=16;
goto P_0c0c1300;
P_0c0c1300: /* original 2f96, guest PC 0x0c0c1300 */
if(!s->budget--) { s->failed_pc=0x0c0c1300u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1302;
P_0c0c1302: /* original 6ccc, guest PC 0x0c0c1302 */
if(!s->budget--) { s->failed_pc=0x0c0c1302u; return 0; }
r[12]=r[12]&255u;
goto P_0c0c1304;
P_0c0c1304: /* original 2f86, guest PC 0x0c0c1304 */
if(!s->budget--) { s->failed_pc=0x0c0c1304u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1306;
P_0c0c1306: /* original 655c, guest PC 0x0c0c1306 */
if(!s->budget--) { s->failed_pc=0x0c0c1306u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c1308;
P_0c0c1308: /* original 35cc, guest PC 0x0c0c1308 */
if(!s->budget--) { s->failed_pc=0x0c0c1308u; return 0; }
r[5]+=r[12];
goto P_0c0c130a;
P_0c0c130a: /* original 5743, guest PC 0x0c0c130a */
if(!s->budget--) { s->failed_pc=0x0c0c130au; return 0; }
r[7]=read(ram,r[4]+12,4);
goto P_0c0c130c;
P_0c0c130c: /* original 7ff8, guest PC 0x0c0c130c */
if(!s->budget--) { s->failed_pc=0x0c0c130cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c130e;
P_0c0c130e: /* original 4b29, guest PC 0x0c0c130e */
if(!s->budget--) { s->failed_pc=0x0c0c130eu; return 0; }
r[11]>>=16;
goto P_0c0c1310;
P_0c0c1310: /* original 4319, guest PC 0x0c0c1310 */
if(!s->budget--) { s->failed_pc=0x0c0c1310u; return 0; }
r[3]>>=8;
goto P_0c0c1312;
P_0c0c1312: /* original 4b19, guest PC 0x0c0c1312 */
if(!s->budget--) { s->failed_pc=0x0c0c1312u; return 0; }
r[11]>>=8;
goto P_0c0c1314;
P_0c0c1314: /* original 6bbc, guest PC 0x0c0c1314 */
if(!s->budget--) { s->failed_pc=0x0c0c1314u; return 0; }
r[11]=r[11]&255u;
goto P_0c0c1316;
P_0c0c1316: /* original 633c, guest PC 0x0c0c1316 */
if(!s->budget--) { s->failed_pc=0x0c0c1316u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c1318;
P_0c0c1318: /* original 33bc, guest PC 0x0c0c1318 */
if(!s->budget--) { s->failed_pc=0x0c0c1318u; return 0; }
r[3]+=r[11];
goto P_0c0c131a;
P_0c0c131a: /* original c727, guest PC 0x0c0c131a */
if(!s->budget--) { s->failed_pc=0x0c0c131au; return 0; }
r[0]=code_base|0x000c13b8u;
goto P_0c0c131c;
P_0c0c131c: /* original 1f31, guest PC 0x0c0c131c */
if(!s->budget--) { s->failed_pc=0x0c0c131cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c131e;
P_0c0c131e: /* original 2f52, guest PC 0x0c0c131e */
if(!s->budget--) { s->failed_pc=0x0c0c131eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1320;
P_0c0c1320: /* original 6563, guest PC 0x0c0c1320 */
if(!s->budget--) { s->failed_pc=0x0c0c1320u; return 0; }
r[5]=r[6];
goto P_0c0c1322;
P_0c0c1322: /* original 4529, guest PC 0x0c0c1322 */
if(!s->budget--) { s->failed_pc=0x0c0c1322u; return 0; }
r[5]>>=16;
goto P_0c0c1324;
P_0c0c1324: /* original 4629, guest PC 0x0c0c1324 */
if(!s->budget--) { s->failed_pc=0x0c0c1324u; return 0; }
r[6]>>=16;
goto P_0c0c1326;
P_0c0c1326: /* original 4519, guest PC 0x0c0c1326 */
if(!s->budget--) { s->failed_pc=0x0c0c1326u; return 0; }
r[5]>>=8;
goto P_0c0c1328;
P_0c0c1328: /* original 666c, guest PC 0x0c0c1328 */
if(!s->budget--) { s->failed_pc=0x0c0c1328u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c132a;
P_0c0c132a: /* original 655c, guest PC 0x0c0c132a */
if(!s->budget--) { s->failed_pc=0x0c0c132au; return 0; }
r[5]=r[5]&255u;
goto P_0c0c132c;
P_0c0c132c: /* original 36c8, guest PC 0x0c0c132c */
if(!s->budget--) { s->failed_pc=0x0c0c132cu; return 0; }
r[6]-=r[12];
goto P_0c0c132e;
P_0c0c132e: /* original 35b8, guest PC 0x0c0c132e */
if(!s->budget--) { s->failed_pc=0x0c0c132eu; return 0; }
r[5]-=r[11];
goto P_0c0c1330;
P_0c0c1330: /* original 455a, guest PC 0x0c0c1330 */
if(!s->budget--) { s->failed_pc=0x0c0c1330u; return 0; }
r[53]=r[5];
goto P_0c0c1332;
P_0c0c1332: /* original ea00, guest PC 0x0c0c1332 */
if(!s->budget--) { s->failed_pc=0x0c0c1332u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1334;
P_0c0c1334: /* original d221, guest PC 0x0c0c1334 */
if(!s->budget--) { s->failed_pc=0x0c0c1334u; return 0; }
r[2]=read(ram,0x0c0c13bcu,4);
goto P_0c0c1336;
P_0c0c1336: /* original e901, guest PC 0x0c0c1336 */
if(!s->budget--) { s->failed_pc=0x0c0c1336u; return 0; }
r[9]=0x00000001u;
goto P_0c0c1338;
P_0c0c1338: /* original d121, guest PC 0x0c0c1338 */
if(!s->budget--) { s->failed_pc=0x0c0c1338u; return 0; }
r[1]=read(ram,0x0c0c13c0u,4);
goto P_0c0c133a;
P_0c0c133a: /* original e878, guest PC 0x0c0c133a */
if(!s->budget--) { s->failed_pc=0x0c0c133au; return 0; }
r[8]=0x00000078u;
goto P_0c0c133c;
P_0c0c133c: /* original f32d, guest PC 0x0c0c133c */
if(!s->budget--) { s->failed_pc=0x0c0c133cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c133e;
P_0c0c133e: /* original f228, guest PC 0x0c0c133e */
if(!s->budget--) { s->failed_pc=0x0c0c133eu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1340;
P_0c0c1340: /* original 465a, guest PC 0x0c0c1340 */
if(!s->budget--) { s->failed_pc=0x0c0c1340u; return 0; }
r[53]=r[6];
goto P_0c0c1342;
P_0c0c1342: /* original f118, guest PC 0x0c0c1342 */
if(!s->budget--) { s->failed_pc=0x0c0c1342u; return 0; }
vf3_matrix_load(s,ram,1,r[1]);
goto P_0c0c1344;
P_0c0c1344: /* original f608, guest PC 0x0c0c1344 */
if(!s->budget--) { s->failed_pc=0x0c0c1344u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c1346;
P_0c0c1346: /* original f322, guest PC 0x0c0c1346 */
if(!s->budget--) { s->failed_pc=0x0c0c1346u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1348;
P_0c0c1348: /* original f53c, guest PC 0x0c0c1348 */
if(!s->budget--) { s->failed_pc=0x0c0c1348u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c134a;
P_0c0c134a: /* original f32d, guest PC 0x0c0c134a */
if(!s->budget--) { s->failed_pc=0x0c0c134au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c134c;
P_0c0c134c: /* original f562, guest PC 0x0c0c134c */
if(!s->budget--) { s->failed_pc=0x0c0c134cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0c134e;
P_0c0c134e: /* original f312, guest PC 0x0c0c134e */
if(!s->budget--) { s->failed_pc=0x0c0c134eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0c1350;
P_0c0c1350: /* original f43c, guest PC 0x0c0c1350 */
if(!s->budget--) { s->failed_pc=0x0c0c1350u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c1352;
P_0c0c1352: /* original f462, guest PC 0x0c0c1352 */
if(!s->budget--) { s->failed_pc=0x0c0c1352u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0c1354;
P_0c0c1354: /* original 6371, guest PC 0x0c0c1354 */
if(!s->budget--) { s->failed_pc=0x0c0c1354u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[3]=tmp;
goto P_0c0c1356;
P_0c0c1356: /* original 633d, guest PC 0x0c0c1356 */
if(!s->budget--) { s->failed_pc=0x0c0c1356u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1358;
P_0c0c1358: /* original 2398, guest PC 0x0c0c1358 */
if(!s->budget--) { s->failed_pc=0x0c0c1358u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c135a;
P_0c0c135a: /* original 891b, guest PC 0x0c0c135a */
if(!s->budget--) { s->failed_pc=0x0c0c135au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c135c;
P_0c0c135c: /* original 8573, guest PC 0x0c0c135c */
if(!s->budget--) { s->failed_pc=0x0c0c135cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c135e;
P_0c0c135e: /* original 610d, guest PC 0x0c0c135e */
if(!s->budget--) { s->failed_pc=0x0c0c135eu; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c1360;
P_0c0c1360: /* original 8574, guest PC 0x0c0c1360 */
if(!s->budget--) { s->failed_pc=0x0c0c1360u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1362;
P_0c0c1362: /* original 31b3, guest PC 0x0c0c1362 */
if(!s->budget--) { s->failed_pc=0x0c0c1362u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[11])!=0);
goto P_0c0c1364;
P_0c0c1364: /* original 8f16, guest PC 0x0c0c1364 */
if(!s->budget--) { s->failed_pc=0x0c0c1364u; return 0; }
cond=r[17]&1u;
r[14]=r[0]&65535u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1368;
P_0c0c1366: /* original 6e0d, guest PC 0x0c0c1366 */
if(!s->budget--) { s->failed_pc=0x0c0c1366u; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c1368;
P_0c0c1368: /* original 52f1, guest PC 0x0c0c1368 */
if(!s->budget--) { s->failed_pc=0x0c0c1368u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c136a;
P_0c0c136a: /* original 3127, guest PC 0x0c0c136a */
if(!s->budget--) { s->failed_pc=0x0c0c136au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c0c136c;
P_0c0c136c: /* original 8912, guest PC 0x0c0c136c */
if(!s->budget--) { s->failed_pc=0x0c0c136cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c136e;
P_0c0c136e: /* original 3ec3, guest PC 0x0c0c136e */
if(!s->budget--) { s->failed_pc=0x0c0c136eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c0c1370;
P_0c0c1370: /* original 8b10, guest PC 0x0c0c1370 */
if(!s->budget--) { s->failed_pc=0x0c0c1370u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1394; }
goto P_0c0c1372;
P_0c0c1372: /* original 63f2, guest PC 0x0c0c1372 */
if(!s->budget--) { s->failed_pc=0x0c0c1372u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1374;
P_0c0c1374: /* original 3e37, guest PC 0x0c0c1374 */
if(!s->budget--) { s->failed_pc=0x0c0c1374u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c0c1376;
P_0c0c1376: /* original 890d, guest PC 0x0c0c1376 */
if(!s->budget--) { s->failed_pc=0x0c0c1376u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1394; }
goto P_0c0c1378;
P_0c0c1378: /* original 8573, guest PC 0x0c0c1378 */
if(!s->budget--) { s->failed_pc=0x0c0c1378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+6,2);
goto P_0c0c137a;
P_0c0c137a: /* original 305c, guest PC 0x0c0c137a */
if(!s->budget--) { s->failed_pc=0x0c0c137au; return 0; }
r[0]+=r[5];
goto P_0c0c137c;
P_0c0c137c: /* original 8173, guest PC 0x0c0c137c */
if(!s->budget--) { s->failed_pc=0x0c0c137cu; return 0; }
write(ram,r[7]+6,r[0],2);
goto P_0c0c137e;
P_0c0c137e: /* original 8574, guest PC 0x0c0c137e */
if(!s->budget--) { s->failed_pc=0x0c0c137eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+8,2);
goto P_0c0c1380;
P_0c0c1380: /* original 306c, guest PC 0x0c0c1380 */
if(!s->budget--) { s->failed_pc=0x0c0c1380u; return 0; }
r[0]+=r[6];
goto P_0c0c1382;
P_0c0c1382: /* original 8174, guest PC 0x0c0c1382 */
if(!s->budget--) { s->failed_pc=0x0c0c1382u; return 0; }
write(ram,r[7]+8,r[0],2);
goto P_0c0c1384;
P_0c0c1384: /* original e014, guest PC 0x0c0c1384 */
if(!s->budget--) { s->failed_pc=0x0c0c1384u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1386;
P_0c0c1386: /* original f376, guest PC 0x0c0c1386 */
if(!s->budget--) { s->failed_pc=0x0c0c1386u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0c1388;
P_0c0c1388: /* original f350, guest PC 0x0c0c1388 */
if(!s->budget--) { s->failed_pc=0x0c0c1388u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0c138a;
P_0c0c138a: /* original f737, guest PC 0x0c0c138a */
if(!s->budget--) { s->failed_pc=0x0c0c138au; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c0c138c;
P_0c0c138c: /* original e018, guest PC 0x0c0c138c */
if(!s->budget--) { s->failed_pc=0x0c0c138cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c138e;
P_0c0c138e: /* original f276, guest PC 0x0c0c138e */
if(!s->budget--) { s->failed_pc=0x0c0c138eu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0c1390;
P_0c0c1390: /* original f240, guest PC 0x0c0c1390 */
if(!s->budget--) { s->failed_pc=0x0c0c1390u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1392;
P_0c0c1392: /* original f727, guest PC 0x0c0c1392 */
if(!s->budget--) { s->failed_pc=0x0c0c1392u; return 0; }
vf3_matrix_store(s,ram,2,r[7]+r[0]);
goto P_0c0c1394;
P_0c0c1394: /* original 7a01, guest PC 0x0c0c1394 */
if(!s->budget--) { s->failed_pc=0x0c0c1394u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c1396;
P_0c0c1396: /* original 3a82, guest PC 0x0c0c1396 */
if(!s->budget--) { s->failed_pc=0x0c0c1396u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[8])!=0);
goto P_0c0c1398;
P_0c0c1398: /* original 8fdc, guest PC 0x0c0c1398 */
if(!s->budget--) { s->failed_pc=0x0c0c1398u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000044u;
if(!cond) { goto P_0c0c1354; }
goto P_0c0c139c;
P_0c0c139a: /* original 7744, guest PC 0x0c0c139a */
if(!s->budget--) { s->failed_pc=0x0c0c139au; return 0; }
r[7]+=0x00000044u;
goto P_0c0c139c;
P_0c0c139c: /* original 7f08, guest PC 0x0c0c139c */
if(!s->budget--) { s->failed_pc=0x0c0c139cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c139e;
P_0c0c139e: /* original e022, guest PC 0x0c0c139e */
if(!s->budget--) { s->failed_pc=0x0c0c139eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c13a0;
P_0c0c13a0: /* original 024d, guest PC 0x0c0c13a0 */
if(!s->budget--) { s->failed_pc=0x0c0c13a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c13a2;
P_0c0c13a2: /* original e301, guest PC 0x0c0c13a2 */
if(!s->budget--) { s->failed_pc=0x0c0c13a2u; return 0; }
r[3]=0x00000001u;
goto P_0c0c13a4;
P_0c0c13a4: /* original 223b, guest PC 0x0c0c13a4 */
if(!s->budget--) { s->failed_pc=0x0c0c13a4u; return 0; }
r[2]|=r[3];
goto P_0c0c13a6;
P_0c0c13a6: /* original 0425, guest PC 0x0c0c13a6 */
if(!s->budget--) { s->failed_pc=0x0c0c13a6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c13a8;
P_0c0c13a8: /* original 68f6, guest PC 0x0c0c13a8 */
if(!s->budget--) { s->failed_pc=0x0c0c13a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c13aa;
P_0c0c13aa: /* original 69f6, guest PC 0x0c0c13aa */
if(!s->budget--) { s->failed_pc=0x0c0c13aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c13ac;
P_0c0c13ac: /* original 6af6, guest PC 0x0c0c13ac */
if(!s->budget--) { s->failed_pc=0x0c0c13acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c13ae;
P_0c0c13ae: /* original 6bf6, guest PC 0x0c0c13ae */
if(!s->budget--) { s->failed_pc=0x0c0c13aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c13b0;
P_0c0c13b0: /* original 6cf6, guest PC 0x0c0c13b0 */
if(!s->budget--) { s->failed_pc=0x0c0c13b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c13b2;
P_0c0c13b2: /* original 000b, guest PC 0x0c0c13b2 */
if(!s->budget--) { s->failed_pc=0x0c0c13b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c13b4: /* original 6ef6, guest PC 0x0c0c13b4 */
if(!s->budget--) { s->failed_pc=0x0c0c13b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c13b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c13b6u; return 0; } return 1;
P_0c0c15e8: /* original 2fe6, guest PC 0x0c0c15e8 */
if(!s->budget--) { s->failed_pc=0x0c0c15e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c15ea;
P_0c0c15ea: /* original e200, guest PC 0x0c0c15ea */
if(!s->budget--) { s->failed_pc=0x0c0c15eau; return 0; }
r[2]=0x00000000u;
goto P_0c0c15ec;
P_0c0c15ec: /* original 2fd6, guest PC 0x0c0c15ec */
if(!s->budget--) { s->failed_pc=0x0c0c15ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c15ee;
P_0c0c15ee: /* original e024, guest PC 0x0c0c15ee */
if(!s->budget--) { s->failed_pc=0x0c0c15eeu; return 0; }
r[0]=0x00000024u;
goto P_0c0c15f0;
P_0c0c15f0: /* original 2fc6, guest PC 0x0c0c15f0 */
if(!s->budget--) { s->failed_pc=0x0c0c15f0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c15f2;
P_0c0c15f2: /* original 6c53, guest PC 0x0c0c15f2 */
if(!s->budget--) { s->failed_pc=0x0c0c15f2u; return 0; }
r[12]=r[5];
goto P_0c0c15f4;
P_0c0c15f4: /* original fffb, guest PC 0x0c0c15f4 */
if(!s->budget--) { s->failed_pc=0x0c0c15f4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c15f6;
P_0c0c15f6: /* original ffeb, guest PC 0x0c0c15f6 */
if(!s->budget--) { s->failed_pc=0x0c0c15f6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c15f8;
P_0c0c15f8: /* original 4f22, guest PC 0x0c0c15f8 */
if(!s->budget--) { s->failed_pc=0x0c0c15f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c15fa;
P_0c0c15fa: /* original 7fb4, guest PC 0x0c0c15fa */
if(!s->budget--) { s->failed_pc=0x0c0c15fau; return 0; }
r[15]+=0xffffffb4u;
goto P_0c0c15fc;
P_0c0c15fc: /* original 1f41, guest PC 0x0c0c15fc */
if(!s->budget--) { s->failed_pc=0x0c0c15fcu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c15fe;
P_0c0c15fe: /* original 2f62, guest PC 0x0c0c15fe */
if(!s->budget--) { s->failed_pc=0x0c0c15feu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c1600;
P_0c0c1600: /* original 53f1, guest PC 0x0c0c1600 */
if(!s->budget--) { s->failed_pc=0x0c0c1600u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1602;
P_0c0c1602: /* original de06, guest PC 0x0c0c1602 */
if(!s->budget--) { s->failed_pc=0x0c0c1602u; return 0; }
r[14]=read(ram,0x0c0c161cu,4);
goto P_0c0c1604;
P_0c0c1604: /* original 0325, guest PC 0x0c0c1604 */
if(!s->budget--) { s->failed_pc=0x0c0c1604u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c1606;
P_0c0c1606: /* original 61e1, guest PC 0x0c0c1606 */
if(!s->budget--) { s->failed_pc=0x0c0c1606u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[1]=tmp;
goto P_0c0c1608;
P_0c0c1608: /* original 3170, guest PC 0x0c0c1608 */
if(!s->budget--) { s->failed_pc=0x0c0c1608u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[7])!=0);
goto P_0c0c160a;
P_0c0c160a: /* original 8909, guest PC 0x0c0c160a */
if(!s->budget--) { s->failed_pc=0x0c0c160au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1620; }
goto P_0c0c160c;
P_0c0c160c: /* original 60e1, guest PC 0x0c0c160c */
if(!s->budget--) { s->failed_pc=0x0c0c160cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0c160e;
P_0c0c160e: /* original 88ff, guest PC 0x0c0c160e */
if(!s->budget--) { s->failed_pc=0x0c0c160eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c1610;
P_0c0c1610: /* original 8b01, guest PC 0x0c0c1610 */
if(!s->budget--) { s->failed_pc=0x0c0c1610u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1616; }
goto P_0c0c1612;
P_0c0c1612: /* original a096, guest PC 0x0c0c1612 */
if(!s->budget--) { s->failed_pc=0x0c0c1612u; return 0; }
goto P_0c0c1742;
P_0c0c1614: /* original 0009, guest PC 0x0c0c1614 */
if(!s->budget--) { s->failed_pc=0x0c0c1614u; return 0; }
goto P_0c0c1616;
P_0c0c1616: /* original aff6, guest PC 0x0c0c1616 */
if(!s->budget--) { s->failed_pc=0x0c0c1616u; return 0; }
r[14]+=0x00000006u;
goto P_0c0c1606;
P_0c0c1618: /* original 7e06, guest PC 0x0c0c1618 */
if(!s->budget--) { s->failed_pc=0x0c0c1618u; return 0; }
r[14]+=0x00000006u;
if(!vf3_matrix_family(0x0c0c161au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c161au; return 0; } return 1;
P_0c0c1620: /* original 63c3, guest PC 0x0c0c1620 */
if(!s->budget--) { s->failed_pc=0x0c0c1620u; return 0; }
r[3]=r[12];
goto P_0c0c1622;
P_0c0c1622: /* original 4301, guest PC 0x0c0c1622 */
if(!s->budget--) { s->failed_pc=0x0c0c1622u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c0c1624;
P_0c0c1624: /* original e43f, guest PC 0x0c0c1624 */
if(!s->budget--) { s->failed_pc=0x0c0c1624u; return 0; }
r[4]=0x0000003fu;
goto P_0c0c1626;
P_0c0c1626: /* original 2349, guest PC 0x0c0c1626 */
if(!s->budget--) { s->failed_pc=0x0c0c1626u; return 0; }
r[3]&=r[4];
goto P_0c0c1628;
P_0c0c1628: /* original 435a, guest PC 0x0c0c1628 */
if(!s->budget--) { s->failed_pc=0x0c0c1628u; return 0; }
r[53]=r[3];
goto P_0c0c162a;
P_0c0c162a: /* original c757, guest PC 0x0c0c162a */
if(!s->budget--) { s->failed_pc=0x0c0c162au; return 0; }
r[0]=code_base|0x000c1788u;
goto P_0c0c162c;
P_0c0c162c: /* original f408, guest PC 0x0c0c162c */
if(!s->budget--) { s->failed_pc=0x0c0c162cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c162e;
P_0c0c162e: /* original 4311, guest PC 0x0c0c162e */
if(!s->budget--) { s->failed_pc=0x0c0c162eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c1630;
P_0c0c1630: /* original 8d04, guest PC 0x0c0c1630 */
if(!s->budget--) { s->failed_pc=0x0c0c1630u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c163c; }
goto P_0c0c1634;
P_0c0c1632: /* original f32d, guest PC 0x0c0c1632 */
if(!s->budget--) { s->failed_pc=0x0c0c1632u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1634;
P_0c0c1634: /* original d255, guest PC 0x0c0c1634 */
if(!s->budget--) { s->failed_pc=0x0c0c1634u; return 0; }
r[2]=read(ram,0x0c0c178cu,4);
goto P_0c0c1636;
P_0c0c1636: /* original 425a, guest PC 0x0c0c1636 */
if(!s->budget--) { s->failed_pc=0x0c0c1636u; return 0; }
r[53]=r[2];
goto P_0c0c1638;
P_0c0c1638: /* original f20d, guest PC 0x0c0c1638 */
if(!s->budget--) { s->failed_pc=0x0c0c1638u; return 0; }
fr[2]=r[53];
goto P_0c0c163a;
P_0c0c163a: /* original f320, guest PC 0x0c0c163a */
if(!s->budget--) { s->failed_pc=0x0c0c163au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c163c;
P_0c0c163c: /* original 63c3, guest PC 0x0c0c163c */
if(!s->budget--) { s->failed_pc=0x0c0c163cu; return 0; }
r[3]=r[12];
goto P_0c0c163e;
P_0c0c163e: /* original e2f9, guest PC 0x0c0c163e */
if(!s->budget--) { s->failed_pc=0x0c0c163eu; return 0; }
r[2]=0xfffffff9u;
goto P_0c0c1640;
P_0c0c1640: /* original f342, guest PC 0x0c0c1640 */
if(!s->budget--) { s->failed_pc=0x0c0c1640u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0c1642;
P_0c0c1642: /* original 432d, guest PC 0x0c0c1642 */
if(!s->budget--) { s->failed_pc=0x0c0c1642u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c0c1644;
P_0c0c1644: /* original 2349, guest PC 0x0c0c1644 */
if(!s->budget--) { s->failed_pc=0x0c0c1644u; return 0; }
r[3]&=r[4];
goto P_0c0c1646;
P_0c0c1646: /* original e010, guest PC 0x0c0c1646 */
if(!s->budget--) { s->failed_pc=0x0c0c1646u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1648;
P_0c0c1648: /* original 4311, guest PC 0x0c0c1648 */
if(!s->budget--) { s->failed_pc=0x0c0c1648u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c164a;
P_0c0c164a: /* original ff37, guest PC 0x0c0c164a */
if(!s->budget--) { s->failed_pc=0x0c0c164au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c164c;
P_0c0c164c: /* original 435a, guest PC 0x0c0c164c */
if(!s->budget--) { s->failed_pc=0x0c0c164cu; return 0; }
r[53]=r[3];
goto P_0c0c164e;
P_0c0c164e: /* original 8d04, guest PC 0x0c0c164e */
if(!s->budget--) { s->failed_pc=0x0c0c164eu; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c165a; }
goto P_0c0c1652;
P_0c0c1650: /* original f22d, guest PC 0x0c0c1650 */
if(!s->budget--) { s->failed_pc=0x0c0c1650u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1652;
P_0c0c1652: /* original d14e, guest PC 0x0c0c1652 */
if(!s->budget--) { s->failed_pc=0x0c0c1652u; return 0; }
r[1]=read(ram,0x0c0c178cu,4);
goto P_0c0c1654;
P_0c0c1654: /* original 415a, guest PC 0x0c0c1654 */
if(!s->budget--) { s->failed_pc=0x0c0c1654u; return 0; }
r[53]=r[1];
goto P_0c0c1656;
P_0c0c1656: /* original f10d, guest PC 0x0c0c1656 */
if(!s->budget--) { s->failed_pc=0x0c0c1656u; return 0; }
fr[1]=r[53];
goto P_0c0c1658;
P_0c0c1658: /* original f210, guest PC 0x0c0c1658 */
if(!s->budget--) { s->failed_pc=0x0c0c1658u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c0c165a;
P_0c0c165a: /* original f242, guest PC 0x0c0c165a */
if(!s->budget--) { s->failed_pc=0x0c0c165au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0c165c;
P_0c0c165c: /* original e014, guest PC 0x0c0c165c */
if(!s->budget--) { s->failed_pc=0x0c0c165cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c165e;
P_0c0c165e: /* original ff27, guest PC 0x0c0c165e */
if(!s->budget--) { s->failed_pc=0x0c0c165eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1660;
P_0c0c1660: /* original 85e1, guest PC 0x0c0c1660 */
if(!s->budget--) { s->failed_pc=0x0c0c1660u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c1662;
P_0c0c1662: /* original d34b, guest PC 0x0c0c1662 */
if(!s->budget--) { s->failed_pc=0x0c0c1662u; return 0; }
r[3]=read(ram,0x0c0c1790u,4);
goto P_0c0c1664;
P_0c0c1664: /* original 600d, guest PC 0x0c0c1664 */
if(!s->budget--) { s->failed_pc=0x0c0c1664u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1666;
P_0c0c1666: /* original 4009, guest PC 0x0c0c1666 */
if(!s->budget--) { s->failed_pc=0x0c0c1666u; return 0; }
r[0]>>=2;
goto P_0c0c1668;
P_0c0c1668: /* original 4001, guest PC 0x0c0c1668 */
if(!s->budget--) { s->failed_pc=0x0c0c1668u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c166a;
P_0c0c166a: /* original 4000, guest PC 0x0c0c166a */
if(!s->budget--) { s->failed_pc=0x0c0c166au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c166c;
P_0c0c166c: /* original 3c0c, guest PC 0x0c0c166c */
if(!s->budget--) { s->failed_pc=0x0c0c166cu; return 0; }
r[12]+=r[0];
goto P_0c0c166e;
P_0c0c166e: /* original 430b, guest PC 0x0c0c166e */
if(!s->budget--) { s->failed_pc=0x0c0c166eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1672u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1672u) { target=s->pc; goto dispatch; }
goto P_0c0c1672;
P_0c0c1670: /* original 64e1, guest PC 0x0c0c1670 */
if(!s->budget--) { s->failed_pc=0x0c0c1670u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c0c1672;
P_0c0c1672: /* original 6d03, guest PC 0x0c0c1672 */
if(!s->budget--) { s->failed_pc=0x0c0c1672u; return 0; }
r[13]=r[0];
goto P_0c0c1674;
P_0c0c1674: /* original 85e1, guest PC 0x0c0c1674 */
if(!s->budget--) { s->failed_pc=0x0c0c1674u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c1676;
P_0c0c1676: /* original 630d, guest PC 0x0c0c1676 */
if(!s->budget--) { s->failed_pc=0x0c0c1676u; return 0; }
r[3]=r[0]&65535u;
goto P_0c0c1678;
P_0c0c1678: /* original 85e2, guest PC 0x0c0c1678 */
if(!s->budget--) { s->failed_pc=0x0c0c1678u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+4,2);
goto P_0c0c167a;
P_0c0c167a: /* original 435a, guest PC 0x0c0c167a */
if(!s->budget--) { s->failed_pc=0x0c0c167au; return 0; }
r[53]=r[3];
goto P_0c0c167c;
P_0c0c167c: /* original 630d, guest PC 0x0c0c167c */
if(!s->budget--) { s->failed_pc=0x0c0c167cu; return 0; }
r[3]=r[0]&65535u;
goto P_0c0c167e;
P_0c0c167e: /* original 60f2, guest PC 0x0c0c167e */
if(!s->budget--) { s->failed_pc=0x0c0c167eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c1680;
P_0c0c1680: /* original fe2d, guest PC 0x0c0c1680 */
if(!s->budget--) { s->failed_pc=0x0c0c1680u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1682;
P_0c0c1682: /* original 435a, guest PC 0x0c0c1682 */
if(!s->budget--) { s->failed_pc=0x0c0c1682u; return 0; }
r[53]=r[3];
goto P_0c0c1684;
P_0c0c1684: /* original c90f, guest PC 0x0c0c1684 */
if(!s->budget--) { s->failed_pc=0x0c0c1684u; return 0; }
r[0]&=15u;
goto P_0c0c1686;
P_0c0c1686: /* original 4011, guest PC 0x0c0c1686 */
if(!s->budget--) { s->failed_pc=0x0c0c1686u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0c1688;
P_0c0c1688: /* original ff2d, guest PC 0x0c0c1688 */
if(!s->budget--) { s->failed_pc=0x0c0c1688u; return 0; }
fr[15]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c168a;
P_0c0c168a: /* original 405a, guest PC 0x0c0c168a */
if(!s->budget--) { s->failed_pc=0x0c0c168au; return 0; }
r[53]=r[0];
goto P_0c0c168c;
P_0c0c168c: /* original 8d04, guest PC 0x0c0c168c */
if(!s->budget--) { s->failed_pc=0x0c0c168cu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1698; }
goto P_0c0c1690;
P_0c0c168e: /* original f32d, guest PC 0x0c0c168e */
if(!s->budget--) { s->failed_pc=0x0c0c168eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1690;
P_0c0c1690: /* original d33e, guest PC 0x0c0c1690 */
if(!s->budget--) { s->failed_pc=0x0c0c1690u; return 0; }
r[3]=read(ram,0x0c0c178cu,4);
goto P_0c0c1692;
P_0c0c1692: /* original 435a, guest PC 0x0c0c1692 */
if(!s->budget--) { s->failed_pc=0x0c0c1692u; return 0; }
r[53]=r[3];
goto P_0c0c1694;
P_0c0c1694: /* original f20d, guest PC 0x0c0c1694 */
if(!s->budget--) { s->failed_pc=0x0c0c1694u; return 0; }
fr[2]=r[53];
goto P_0c0c1696;
P_0c0c1696: /* original f320, guest PC 0x0c0c1696 */
if(!s->budget--) { s->failed_pc=0x0c0c1696u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1698;
P_0c0c1698: /* original f1d8, guest PC 0x0c0c1698 */
if(!s->budget--) { s->failed_pc=0x0c0c1698u; return 0; }
vf3_matrix_load(s,ram,1,r[13]);
goto P_0c0c169a;
P_0c0c169a: /* original e008, guest PC 0x0c0c169a */
if(!s->budget--) { s->failed_pc=0x0c0c169au; return 0; }
r[0]=0x00000008u;
goto P_0c0c169c;
P_0c0c169c: /* original f0ec, guest PC 0x0c0c169c */
if(!s->budget--) { s->failed_pc=0x0c0c169cu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0c169e;
P_0c0c169e: /* original f13e, guest PC 0x0c0c169e */
if(!s->budget--) { s->failed_pc=0x0c0c169eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c16a0;
P_0c0c16a0: /* original ff17, guest PC 0x0c0c16a0 */
if(!s->budget--) { s->failed_pc=0x0c0c16a0u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c16a2;
P_0c0c16a2: /* original 60f2, guest PC 0x0c0c16a2 */
if(!s->budget--) { s->failed_pc=0x0c0c16a2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c16a4;
P_0c0c16a4: /* original c9f0, guest PC 0x0c0c16a4 */
if(!s->budget--) { s->failed_pc=0x0c0c16a4u; return 0; }
r[0]&=240u;
goto P_0c0c16a6;
P_0c0c16a6: /* original 4009, guest PC 0x0c0c16a6 */
if(!s->budget--) { s->failed_pc=0x0c0c16a6u; return 0; }
r[0]>>=2;
goto P_0c0c16a8;
P_0c0c16a8: /* original 4009, guest PC 0x0c0c16a8 */
if(!s->budget--) { s->failed_pc=0x0c0c16a8u; return 0; }
r[0]>>=2;
goto P_0c0c16aa;
P_0c0c16aa: /* original 405a, guest PC 0x0c0c16aa */
if(!s->budget--) { s->failed_pc=0x0c0c16aau; return 0; }
r[53]=r[0];
goto P_0c0c16ac;
P_0c0c16ac: /* original 4011, guest PC 0x0c0c16ac */
if(!s->budget--) { s->failed_pc=0x0c0c16acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0c16ae;
P_0c0c16ae: /* original 8d04, guest PC 0x0c0c16ae */
if(!s->budget--) { s->failed_pc=0x0c0c16aeu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c16ba; }
goto P_0c0c16b2;
P_0c0c16b0: /* original f32d, guest PC 0x0c0c16b0 */
if(!s->budget--) { s->failed_pc=0x0c0c16b0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c16b2;
P_0c0c16b2: /* original d336, guest PC 0x0c0c16b2 */
if(!s->budget--) { s->failed_pc=0x0c0c16b2u; return 0; }
r[3]=read(ram,0x0c0c178cu,4);
goto P_0c0c16b4;
P_0c0c16b4: /* original 435a, guest PC 0x0c0c16b4 */
if(!s->budget--) { s->failed_pc=0x0c0c16b4u; return 0; }
r[53]=r[3];
goto P_0c0c16b6;
P_0c0c16b6: /* original f20d, guest PC 0x0c0c16b6 */
if(!s->budget--) { s->failed_pc=0x0c0c16b6u; return 0; }
fr[2]=r[53];
goto P_0c0c16b8;
P_0c0c16b8: /* original f320, guest PC 0x0c0c16b8 */
if(!s->budget--) { s->failed_pc=0x0c0c16b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c16ba;
P_0c0c16ba: /* original e004, guest PC 0x0c0c16ba */
if(!s->budget--) { s->failed_pc=0x0c0c16bau; return 0; }
r[0]=0x00000004u;
goto P_0c0c16bc;
P_0c0c16bc: /* original f0fc, guest PC 0x0c0c16bc */
if(!s->budget--) { s->failed_pc=0x0c0c16bcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c16be;
P_0c0c16be: /* original f1d6, guest PC 0x0c0c16be */
if(!s->budget--) { s->failed_pc=0x0c0c16beu; return 0; }
vf3_matrix_load(s,ram,1,r[13]+r[0]);
goto P_0c0c16c0;
P_0c0c16c0: /* original e00c, guest PC 0x0c0c16c0 */
if(!s->budget--) { s->failed_pc=0x0c0c16c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c16c2;
P_0c0c16c2: /* original 64f3, guest PC 0x0c0c16c2 */
if(!s->budget--) { s->failed_pc=0x0c0c16c2u; return 0; }
r[4]=r[15];
goto P_0c0c16c4;
P_0c0c16c4: /* original f13e, guest PC 0x0c0c16c4 */
if(!s->budget--) { s->failed_pc=0x0c0c16c4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c16c6;
P_0c0c16c6: /* original ff17, guest PC 0x0c0c16c6 */
if(!s->budget--) { s->failed_pc=0x0c0c16c6u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c16c8;
P_0c0c16c8: /* original e010, guest PC 0x0c0c16c8 */
if(!s->budget--) { s->failed_pc=0x0c0c16c8u; return 0; }
r[0]=0x00000010u;
goto P_0c0c16ca;
P_0c0c16ca: /* original f3d6, guest PC 0x0c0c16ca */
if(!s->budget--) { s->failed_pc=0x0c0c16cau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c16cc;
P_0c0c16cc: /* original e014, guest PC 0x0c0c16cc */
if(!s->budget--) { s->failed_pc=0x0c0c16ccu; return 0; }
r[0]=0x00000014u;
goto P_0c0c16ce;
P_0c0c16ce: /* original f6ec, guest PC 0x0c0c16ce */
if(!s->budget--) { s->failed_pc=0x0c0c16ceu; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c16d0;
P_0c0c16d0: /* original f632, guest PC 0x0c0c16d0 */
if(!s->budget--) { s->failed_pc=0x0c0c16d0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c16d2;
P_0c0c16d2: /* original 53f1, guest PC 0x0c0c16d2 */
if(!s->budget--) { s->failed_pc=0x0c0c16d2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c16d4;
P_0c0c16d4: /* original f3d6, guest PC 0x0c0c16d4 */
if(!s->budget--) { s->failed_pc=0x0c0c16d4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c16d6;
P_0c0c16d6: /* original e024, guest PC 0x0c0c16d6 */
if(!s->budget--) { s->failed_pc=0x0c0c16d6u; return 0; }
r[0]=0x00000024u;
goto P_0c0c16d8;
P_0c0c16d8: /* original 023d, guest PC 0x0c0c16d8 */
if(!s->budget--) { s->failed_pc=0x0c0c16d8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c16da;
P_0c0c16da: /* original d02e, guest PC 0x0c0c16da */
if(!s->budget--) { s->failed_pc=0x0c0c16dau; return 0; }
r[0]=read(ram,0x0c0c1794u,4);
goto P_0c0c16dc;
P_0c0c16dc: /* original 622d, guest PC 0x0c0c16dc */
if(!s->budget--) { s->failed_pc=0x0c0c16dcu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c16de;
P_0c0c16de: /* original f70c, guest PC 0x0c0c16de */
if(!s->budget--) { s->failed_pc=0x0c0c16deu; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0c16e0;
P_0c0c16e0: /* original 4208, guest PC 0x0c0c16e0 */
if(!s->budget--) { s->failed_pc=0x0c0c16e0u; return 0; }
r[2]<<=2;
goto P_0c0c16e2;
P_0c0c16e2: /* original f732, guest PC 0x0c0c16e2 */
if(!s->budget--) { s->failed_pc=0x0c0c16e2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c16e4;
P_0c0c16e4: /* original f826, guest PC 0x0c0c16e4 */
if(!s->budget--) { s->failed_pc=0x0c0c16e4u; return 0; }
vf3_matrix_load(s,ram,8,r[2]+r[0]);
goto P_0c0c16e6;
P_0c0c16e6: /* original e014, guest PC 0x0c0c16e6 */
if(!s->budget--) { s->failed_pc=0x0c0c16e6u; return 0; }
r[0]=0x00000014u;
goto P_0c0c16e8;
P_0c0c16e8: /* original f5f6, guest PC 0x0c0c16e8 */
if(!s->budget--) { s->failed_pc=0x0c0c16e8u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c16ea;
P_0c0c16ea: /* original e010, guest PC 0x0c0c16ea */
if(!s->budget--) { s->failed_pc=0x0c0c16eau; return 0; }
r[0]=0x00000010u;
goto P_0c0c16ec;
P_0c0c16ec: /* original d32a, guest PC 0x0c0c16ec */
if(!s->budget--) { s->failed_pc=0x0c0c16ecu; return 0; }
r[3]=read(ram,0x0c0c1798u,4);
goto P_0c0c16ee;
P_0c0c16ee: /* original f4f6, guest PC 0x0c0c16ee */
if(!s->budget--) { s->failed_pc=0x0c0c16eeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c16f0;
P_0c0c16f0: /* original 430b, guest PC 0x0c0c16f0 */
if(!s->budget--) { s->failed_pc=0x0c0c16f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c16f4u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c16f4u) { target=s->pc; goto dispatch; }
goto P_0c0c16f4;
P_0c0c16f2: /* original 7418, guest PC 0x0c0c16f2 */
if(!s->budget--) { s->failed_pc=0x0c0c16f2u; return 0; }
r[4]+=0x00000018u;
goto P_0c0c16f4;
P_0c0c16f4: /* original e014, guest PC 0x0c0c16f4 */
if(!s->budget--) { s->failed_pc=0x0c0c16f4u; return 0; }
r[0]=0x00000014u;
goto P_0c0c16f6;
P_0c0c16f6: /* original d329, guest PC 0x0c0c16f6 */
if(!s->budget--) { s->failed_pc=0x0c0c16f6u; return 0; }
r[3]=read(ram,0x0c0c179cu,4);
goto P_0c0c16f8;
P_0c0c16f8: /* original f9d6, guest PC 0x0c0c16f8 */
if(!s->budget--) { s->failed_pc=0x0c0c16f8u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0c16fa;
P_0c0c16fa: /* original e010, guest PC 0x0c0c16fa */
if(!s->budget--) { s->failed_pc=0x0c0c16fau; return 0; }
r[0]=0x00000010u;
goto P_0c0c16fc;
P_0c0c16fc: /* original f8d6, guest PC 0x0c0c16fc */
if(!s->budget--) { s->failed_pc=0x0c0c16fcu; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0c16fe;
P_0c0c16fe: /* original e00c, guest PC 0x0c0c16fe */
if(!s->budget--) { s->failed_pc=0x0c0c16feu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1700;
P_0c0c1700: /* original f5f6, guest PC 0x0c0c1700 */
if(!s->budget--) { s->failed_pc=0x0c0c1700u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1702;
P_0c0c1702: /* original e008, guest PC 0x0c0c1702 */
if(!s->budget--) { s->failed_pc=0x0c0c1702u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1704;
P_0c0c1704: /* original f4f6, guest PC 0x0c0c1704 */
if(!s->budget--) { s->failed_pc=0x0c0c1704u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c1706;
P_0c0c1706: /* original 64f3, guest PC 0x0c0c1706 */
if(!s->budget--) { s->failed_pc=0x0c0c1706u; return 0; }
r[4]=r[15];
goto P_0c0c1708;
P_0c0c1708: /* original f7fc, guest PC 0x0c0c1708 */
if(!s->budget--) { s->failed_pc=0x0c0c1708u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c170a;
P_0c0c170a: /* original f6ec, guest PC 0x0c0c170a */
if(!s->budget--) { s->failed_pc=0x0c0c170au; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c170c;
P_0c0c170c: /* original 430b, guest PC 0x0c0c170c */
if(!s->budget--) { s->failed_pc=0x0c0c170cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1710u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1710u) { target=s->pc; goto dispatch; }
goto P_0c0c1710;
P_0c0c170e: /* original 7418, guest PC 0x0c0c170e */
if(!s->budget--) { s->failed_pc=0x0c0c170eu; return 0; }
r[4]+=0x00000018u;
goto P_0c0c1710;
P_0c0c1710: /* original d123, guest PC 0x0c0c1710 */
if(!s->budget--) { s->failed_pc=0x0c0c1710u; return 0; }
r[1]=read(ram,0x0c0c17a0u,4);
goto P_0c0c1712;
P_0c0c1712: /* original 9337, guest PC 0x0c0c1712 */
if(!s->budget--) { s->failed_pc=0x0c0c1712u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1784u,2);
goto P_0c0c1714;
P_0c0c1714: /* original 6212, guest PC 0x0c0c1714 */
if(!s->budget--) { s->failed_pc=0x0c0c1714u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c1716;
P_0c0c1716: /* original 9434, guest PC 0x0c0c1716 */
if(!s->budget--) { s->failed_pc=0x0c0c1716u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1782u,2);
goto P_0c0c1718;
P_0c0c1718: /* original 2238, guest PC 0x0c0c1718 */
if(!s->budget--) { s->failed_pc=0x0c0c1718u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c171a;
P_0c0c171a: /* original 8900, guest PC 0x0c0c171a */
if(!s->budget--) { s->failed_pc=0x0c0c171au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c171e; }
goto P_0c0c171c;
P_0c0c171c: /* original 9433, guest PC 0x0c0c171c */
if(!s->budget--) { s->failed_pc=0x0c0c171cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1786u,2);
goto P_0c0c171e;
P_0c0c171e: /* original 53d8, guest PC 0x0c0c171e */
if(!s->budget--) { s->failed_pc=0x0c0c171eu; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c0c1720;
P_0c0c1720: /* original d020, guest PC 0x0c0c1720 */
if(!s->budget--) { s->failed_pc=0x0c0c1720u; return 0; }
r[0]=read(ram,0x0c0c17a4u,4);
goto P_0c0c1722;
P_0c0c1722: /* original 4300, guest PC 0x0c0c1722 */
if(!s->budget--) { s->failed_pc=0x0c0c1722u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c1724;
P_0c0c1724: /* original 023d, guest PC 0x0c0c1724 */
if(!s->budget--) { s->failed_pc=0x0c0c1724u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1726;
P_0c0c1726: /* original e300, guest PC 0x0c0c1726 */
if(!s->budget--) { s->failed_pc=0x0c0c1726u; return 0; }
r[3]=0x00000000u;
goto P_0c0c1728;
P_0c0c1728: /* original e040, guest PC 0x0c0c1728 */
if(!s->budget--) { s->failed_pc=0x0c0c1728u; return 0; }
r[0]=0x00000040u;
goto P_0c0c172a;
P_0c0c172a: /* original 622d, guest PC 0x0c0c172a */
if(!s->budget--) { s->failed_pc=0x0c0c172au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c172c;
P_0c0c172c: /* original 1f26, guest PC 0x0c0c172c */
if(!s->budget--) { s->failed_pc=0x0c0c172cu; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0c172e;
P_0c0c172e: /* original 0f36, guest PC 0x0c0c172e */
if(!s->budget--) { s->failed_pc=0x0c0c172eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c1730;
P_0c0c1730: /* original e044, guest PC 0x0c0c1730 */
if(!s->budget--) { s->failed_pc=0x0c0c1730u; return 0; }
r[0]=0x00000044u;
goto P_0c0c1732;
P_0c0c1732: /* original 0f46, guest PC 0x0c0c1732 */
if(!s->budget--) { s->failed_pc=0x0c0c1732u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c0c1734;
P_0c0c1734: /* original e048, guest PC 0x0c0c1734 */
if(!s->budget--) { s->failed_pc=0x0c0c1734u; return 0; }
r[0]=0x00000048u;
goto P_0c0c1736;
P_0c0c1736: /* original f39d, guest PC 0x0c0c1736 */
if(!s->budget--) { s->failed_pc=0x0c0c1736u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1738;
P_0c0c1738: /* original 64f3, guest PC 0x0c0c1738 */
if(!s->budget--) { s->failed_pc=0x0c0c1738u; return 0; }
r[4]=r[15];
goto P_0c0c173a;
P_0c0c173a: /* original ff37, guest PC 0x0c0c173a */
if(!s->budget--) { s->failed_pc=0x0c0c173au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c173c;
P_0c0c173c: /* original d31a, guest PC 0x0c0c173c */
if(!s->budget--) { s->failed_pc=0x0c0c173cu; return 0; }
r[3]=read(ram,0x0c0c17a8u,4);
goto P_0c0c173e;
P_0c0c173e: /* original 430b, guest PC 0x0c0c173e */
if(!s->budget--) { s->failed_pc=0x0c0c173eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c1742u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c1742u) { target=s->pc; goto dispatch; }
goto P_0c0c1742;
P_0c0c1740: /* original 7418, guest PC 0x0c0c1740 */
if(!s->budget--) { s->failed_pc=0x0c0c1740u; return 0; }
r[4]+=0x00000018u;
goto P_0c0c1742;
P_0c0c1742: /* original 7f4c, guest PC 0x0c0c1742 */
if(!s->budget--) { s->failed_pc=0x0c0c1742u; return 0; }
r[15]+=0x0000004cu;
goto P_0c0c1744;
P_0c0c1744: /* original 60c3, guest PC 0x0c0c1744 */
if(!s->budget--) { s->failed_pc=0x0c0c1744u; return 0; }
r[0]=r[12];
goto P_0c0c1746;
P_0c0c1746: /* original 4f26, guest PC 0x0c0c1746 */
if(!s->budget--) { s->failed_pc=0x0c0c1746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1748;
P_0c0c1748: /* original fef9, guest PC 0x0c0c1748 */
if(!s->budget--) { s->failed_pc=0x0c0c1748u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c174a;
P_0c0c174a: /* original fff9, guest PC 0x0c0c174a */
if(!s->budget--) { s->failed_pc=0x0c0c174au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c174c;
P_0c0c174c: /* original 6cf6, guest PC 0x0c0c174c */
if(!s->budget--) { s->failed_pc=0x0c0c174cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c174e;
P_0c0c174e: /* original 6df6, guest PC 0x0c0c174e */
if(!s->budget--) { s->failed_pc=0x0c0c174eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1750;
P_0c0c1750: /* original 000b, guest PC 0x0c0c1750 */
if(!s->budget--) { s->failed_pc=0x0c0c1750u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1752: /* original 6ef6, guest PC 0x0c0c1752 */
if(!s->budget--) { s->failed_pc=0x0c0c1752u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c1754u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1754u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
