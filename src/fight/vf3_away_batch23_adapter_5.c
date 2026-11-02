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
int vf3_away_batch23_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b1550u: goto P_0c0b1550;
case 0x0c0b1552u: goto P_0c0b1552;
case 0x0c0b1554u: goto P_0c0b1554;
case 0x0c0b1556u: goto P_0c0b1556;
case 0x0c0b1558u: goto P_0c0b1558;
case 0x0c0b155au: goto P_0c0b155a;
case 0x0c0b155cu: goto P_0c0b155c;
case 0x0c0b155eu: goto P_0c0b155e;
case 0x0c0b1560u: goto P_0c0b1560;
case 0x0c0b1562u: goto P_0c0b1562;
case 0x0c0b1564u: goto P_0c0b1564;
case 0x0c0b1566u: goto P_0c0b1566;
case 0x0c0b1568u: goto P_0c0b1568;
case 0x0c0b156au: goto P_0c0b156a;
case 0x0c0b156cu: goto P_0c0b156c;
case 0x0c0b156eu: goto P_0c0b156e;
case 0x0c0b1570u: goto P_0c0b1570;
case 0x0c0b1572u: goto P_0c0b1572;
case 0x0c0b1574u: goto P_0c0b1574;
case 0x0c0b1576u: goto P_0c0b1576;
case 0x0c0b1578u: goto P_0c0b1578;
case 0x0c0b157au: goto P_0c0b157a;
case 0x0c0b157cu: goto P_0c0b157c;
case 0x0c0b157eu: goto P_0c0b157e;
case 0x0c0b1580u: goto P_0c0b1580;
case 0x0c0b1582u: goto P_0c0b1582;
case 0x0c0b1584u: goto P_0c0b1584;
case 0x0c0b1586u: goto P_0c0b1586;
case 0x0c0b1588u: goto P_0c0b1588;
case 0x0c0b158au: goto P_0c0b158a;
case 0x0c0b158cu: goto P_0c0b158c;
case 0x0c0b158eu: goto P_0c0b158e;
case 0x0c0b1590u: goto P_0c0b1590;
case 0x0c0b1592u: goto P_0c0b1592;
case 0x0c0b1594u: goto P_0c0b1594;
case 0x0c0b1596u: goto P_0c0b1596;
case 0x0c0b1598u: goto P_0c0b1598;
case 0x0c0b159au: goto P_0c0b159a;
case 0x0c0b159cu: goto P_0c0b159c;
case 0x0c0b159eu: goto P_0c0b159e;
case 0x0c0b15a0u: goto P_0c0b15a0;
case 0x0c0b15a2u: goto P_0c0b15a2;
case 0x0c0b15a4u: goto P_0c0b15a4;
case 0x0c0b15a6u: goto P_0c0b15a6;
case 0x0c0b15a8u: goto P_0c0b15a8;
case 0x0c0b15aau: goto P_0c0b15aa;
case 0x0c0b15acu: goto P_0c0b15ac;
case 0x0c0b15aeu: goto P_0c0b15ae;
case 0x0c0b15b0u: goto P_0c0b15b0;
case 0x0c0b15b2u: goto P_0c0b15b2;
case 0x0c0b15b4u: goto P_0c0b15b4;
case 0x0c0b15b6u: goto P_0c0b15b6;
case 0x0c0b15b8u: goto P_0c0b15b8;
case 0x0c0b15bau: goto P_0c0b15ba;
case 0x0c0b15bcu: goto P_0c0b15bc;
case 0x0c0b15beu: goto P_0c0b15be;
case 0x0c0b15c0u: goto P_0c0b15c0;
case 0x0c0b15c2u: goto P_0c0b15c2;
case 0x0c0b15c4u: goto P_0c0b15c4;
case 0x0c0b15c6u: goto P_0c0b15c6;
case 0x0c0b15c8u: goto P_0c0b15c8;
case 0x0c0b15cau: goto P_0c0b15ca;
case 0x0c0b15ccu: goto P_0c0b15cc;
case 0x0c0b15ceu: goto P_0c0b15ce;
case 0x0c0b15d0u: goto P_0c0b15d0;
case 0x0c0b15d2u: goto P_0c0b15d2;
case 0x0c0b15d4u: goto P_0c0b15d4;
case 0x0c0b15d6u: goto P_0c0b15d6;
case 0x0c0b15d8u: goto P_0c0b15d8;
case 0x0c0b15dau: goto P_0c0b15da;
case 0x0c0b15dcu: goto P_0c0b15dc;
case 0x0c0b15deu: goto P_0c0b15de;
case 0x0c0b15e0u: goto P_0c0b15e0;
case 0x0c0b15e2u: goto P_0c0b15e2;
case 0x0c0b15e4u: goto P_0c0b15e4;
case 0x0c0b15e6u: goto P_0c0b15e6;
case 0x0c0b15e8u: goto P_0c0b15e8;
case 0x0c0b15eau: goto P_0c0b15ea;
case 0x0c0b15ecu: goto P_0c0b15ec;
case 0x0c0b15eeu: goto P_0c0b15ee;
case 0x0c0b15f0u: goto P_0c0b15f0;
case 0x0c0b15f2u: goto P_0c0b15f2;
case 0x0c0b15f4u: goto P_0c0b15f4;
case 0x0c0b15f6u: goto P_0c0b15f6;
case 0x0c0b15f8u: goto P_0c0b15f8;
case 0x0c0b15fau: goto P_0c0b15fa;
case 0x0c0b15fcu: goto P_0c0b15fc;
case 0x0c0b15feu: goto P_0c0b15fe;
case 0x0c0b1600u: goto P_0c0b1600;
case 0x0c0b1602u: goto P_0c0b1602;
case 0x0c0b1604u: goto P_0c0b1604;
case 0x0c0b1606u: goto P_0c0b1606;
case 0x0c0b1608u: goto P_0c0b1608;
case 0x0c0b160au: goto P_0c0b160a;
case 0x0c0b160cu: goto P_0c0b160c;
case 0x0c0b160eu: goto P_0c0b160e;
case 0x0c0b1610u: goto P_0c0b1610;
case 0x0c0b1612u: goto P_0c0b1612;
case 0x0c0b1614u: goto P_0c0b1614;
case 0x0c0b1616u: goto P_0c0b1616;
case 0x0c0b1618u: goto P_0c0b1618;
case 0x0c0b161au: goto P_0c0b161a;
case 0x0c0b161cu: goto P_0c0b161c;
case 0x0c0b161eu: goto P_0c0b161e;
case 0x0c0b1620u: goto P_0c0b1620;
case 0x0c0b1622u: goto P_0c0b1622;
case 0x0c0b1624u: goto P_0c0b1624;
case 0x0c0b1626u: goto P_0c0b1626;
case 0x0c0b1628u: goto P_0c0b1628;
case 0x0c0b162au: goto P_0c0b162a;
case 0x0c0b162cu: goto P_0c0b162c;
case 0x0c0b1660u: goto P_0c0b1660;
case 0x0c0b1662u: goto P_0c0b1662;
case 0x0c0b1664u: goto P_0c0b1664;
case 0x0c0b1666u: goto P_0c0b1666;
case 0x0c0b1668u: goto P_0c0b1668;
case 0x0c0b166au: goto P_0c0b166a;
case 0x0c0b166cu: goto P_0c0b166c;
case 0x0c0b166eu: goto P_0c0b166e;
case 0x0c0b1670u: goto P_0c0b1670;
case 0x0c0b1672u: goto P_0c0b1672;
case 0x0c0b1674u: goto P_0c0b1674;
case 0x0c0b1676u: goto P_0c0b1676;
case 0x0c0b1678u: goto P_0c0b1678;
case 0x0c0b167au: goto P_0c0b167a;
case 0x0c0b167cu: goto P_0c0b167c;
case 0x0c0b167eu: goto P_0c0b167e;
case 0x0c0b1680u: goto P_0c0b1680;
case 0x0c0b1682u: goto P_0c0b1682;
case 0x0c0b1684u: goto P_0c0b1684;
case 0x0c0b1686u: goto P_0c0b1686;
case 0x0c0b1688u: goto P_0c0b1688;
case 0x0c0b168au: goto P_0c0b168a;
case 0x0c0b168cu: goto P_0c0b168c;
case 0x0c0b168eu: goto P_0c0b168e;
case 0x0c0b1690u: goto P_0c0b1690;
case 0x0c0b1692u: goto P_0c0b1692;
case 0x0c0b1694u: goto P_0c0b1694;
case 0x0c0b1696u: goto P_0c0b1696;
case 0x0c0b1698u: goto P_0c0b1698;
case 0x0c0b169au: goto P_0c0b169a;
case 0x0c0b169cu: goto P_0c0b169c;
case 0x0c0b169eu: goto P_0c0b169e;
case 0x0c0b16a0u: goto P_0c0b16a0;
case 0x0c0b16a2u: goto P_0c0b16a2;
case 0x0c0b16a4u: goto P_0c0b16a4;
case 0x0c0b16a6u: goto P_0c0b16a6;
case 0x0c0b16a8u: goto P_0c0b16a8;
case 0x0c0b16aau: goto P_0c0b16aa;
case 0x0c0b16acu: goto P_0c0b16ac;
case 0x0c0b16aeu: goto P_0c0b16ae;
case 0x0c0b16b0u: goto P_0c0b16b0;
case 0x0c0b16b2u: goto P_0c0b16b2;
case 0x0c0b16b4u: goto P_0c0b16b4;
case 0x0c0b16b6u: goto P_0c0b16b6;
case 0x0c0b16b8u: goto P_0c0b16b8;
case 0x0c0b16bau: goto P_0c0b16ba;
case 0x0c0b16bcu: goto P_0c0b16bc;
case 0x0c0b16beu: goto P_0c0b16be;
case 0x0c0b16c0u: goto P_0c0b16c0;
case 0x0c0b16c2u: goto P_0c0b16c2;
case 0x0c0b16c4u: goto P_0c0b16c4;
case 0x0c0b16c6u: goto P_0c0b16c6;
case 0x0c0b16c8u: goto P_0c0b16c8;
case 0x0c0b16cau: goto P_0c0b16ca;
case 0x0c0b16ccu: goto P_0c0b16cc;
case 0x0c0b16ceu: goto P_0c0b16ce;
case 0x0c0b16d0u: goto P_0c0b16d0;
case 0x0c0b16d2u: goto P_0c0b16d2;
case 0x0c0b16d4u: goto P_0c0b16d4;
case 0x0c0b16d6u: goto P_0c0b16d6;
case 0x0c0b16d8u: goto P_0c0b16d8;
case 0x0c0b16dau: goto P_0c0b16da;
case 0x0c0b16dcu: goto P_0c0b16dc;
case 0x0c0b16deu: goto P_0c0b16de;
case 0x0c0b16e0u: goto P_0c0b16e0;
case 0x0c0b16e2u: goto P_0c0b16e2;
case 0x0c0b16e4u: goto P_0c0b16e4;
case 0x0c0b16e6u: goto P_0c0b16e6;
case 0x0c0b16e8u: goto P_0c0b16e8;
case 0x0c0b16eau: goto P_0c0b16ea;
case 0x0c0b16ecu: goto P_0c0b16ec;
case 0x0c0b16eeu: goto P_0c0b16ee;
case 0x0c0b16f0u: goto P_0c0b16f0;
case 0x0c0b16f2u: goto P_0c0b16f2;
case 0x0c0b16f4u: goto P_0c0b16f4;
case 0x0c0b16f6u: goto P_0c0b16f6;
case 0x0c0b16f8u: goto P_0c0b16f8;
case 0x0c0b16fau: goto P_0c0b16fa;
case 0x0c0b16fcu: goto P_0c0b16fc;
case 0x0c0b16feu: goto P_0c0b16fe;
case 0x0c0b1700u: goto P_0c0b1700;
case 0x0c0b1702u: goto P_0c0b1702;
case 0x0c0b1704u: goto P_0c0b1704;
case 0x0c0b1706u: goto P_0c0b1706;
case 0x0c0b1708u: goto P_0c0b1708;
case 0x0c0b170au: goto P_0c0b170a;
case 0x0c0b170cu: goto P_0c0b170c;
case 0x0c0b1728u: goto P_0c0b1728;
case 0x0c0b172au: goto P_0c0b172a;
case 0x0c0b172cu: goto P_0c0b172c;
case 0x0c0b172eu: goto P_0c0b172e;
case 0x0c0b1730u: goto P_0c0b1730;
case 0x0c0b1732u: goto P_0c0b1732;
case 0x0c0b1734u: goto P_0c0b1734;
case 0x0c0b1736u: goto P_0c0b1736;
case 0x0c0b1738u: goto P_0c0b1738;
case 0x0c0b173au: goto P_0c0b173a;
case 0x0c0b173cu: goto P_0c0b173c;
case 0x0c0b173eu: goto P_0c0b173e;
case 0x0c0b1740u: goto P_0c0b1740;
case 0x0c0b1742u: goto P_0c0b1742;
case 0x0c0b1744u: goto P_0c0b1744;
case 0x0c0b1746u: goto P_0c0b1746;
case 0x0c0b1748u: goto P_0c0b1748;
case 0x0c0b174au: goto P_0c0b174a;
case 0x0c0b174cu: goto P_0c0b174c;
case 0x0c0b174eu: goto P_0c0b174e;
case 0x0c0b1750u: goto P_0c0b1750;
case 0x0c0b1752u: goto P_0c0b1752;
case 0x0c0b1754u: goto P_0c0b1754;
case 0x0c0b1756u: goto P_0c0b1756;
case 0x0c0b1758u: goto P_0c0b1758;
case 0x0c0b175au: goto P_0c0b175a;
case 0x0c0b175cu: goto P_0c0b175c;
case 0x0c0b175eu: goto P_0c0b175e;
case 0x0c0b1760u: goto P_0c0b1760;
case 0x0c0b1762u: goto P_0c0b1762;
case 0x0c0b1764u: goto P_0c0b1764;
case 0x0c0b1766u: goto P_0c0b1766;
case 0x0c0b1768u: goto P_0c0b1768;
case 0x0c0b176au: goto P_0c0b176a;
case 0x0c0b176cu: goto P_0c0b176c;
case 0x0c0b176eu: goto P_0c0b176e;
case 0x0c0b1770u: goto P_0c0b1770;
case 0x0c0b1772u: goto P_0c0b1772;
case 0x0c0b1774u: goto P_0c0b1774;
case 0x0c0b1776u: goto P_0c0b1776;
case 0x0c0b1778u: goto P_0c0b1778;
case 0x0c0b177au: goto P_0c0b177a;
case 0x0c0b177cu: goto P_0c0b177c;
case 0x0c0b177eu: goto P_0c0b177e;
case 0x0c0b1780u: goto P_0c0b1780;
case 0x0c0b1782u: goto P_0c0b1782;
case 0x0c0b1784u: goto P_0c0b1784;
case 0x0c0b1786u: goto P_0c0b1786;
case 0x0c0b1788u: goto P_0c0b1788;
case 0x0c0b178au: goto P_0c0b178a;
case 0x0c0b178cu: goto P_0c0b178c;
case 0x0c0b178eu: goto P_0c0b178e;
case 0x0c0b1790u: goto P_0c0b1790;
case 0x0c0b1792u: goto P_0c0b1792;
case 0x0c0b1794u: goto P_0c0b1794;
case 0x0c0b1796u: goto P_0c0b1796;
case 0x0c0b1798u: goto P_0c0b1798;
case 0x0c0b179au: goto P_0c0b179a;
case 0x0c0b179cu: goto P_0c0b179c;
case 0x0c0b179eu: goto P_0c0b179e;
case 0x0c0b17a0u: goto P_0c0b17a0;
case 0x0c0b17a2u: goto P_0c0b17a2;
case 0x0c0b17a4u: goto P_0c0b17a4;
case 0x0c0b17a6u: goto P_0c0b17a6;
case 0x0c0b17a8u: goto P_0c0b17a8;
case 0x0c0b17aau: goto P_0c0b17aa;
case 0x0c0b17acu: goto P_0c0b17ac;
case 0x0c0b17aeu: goto P_0c0b17ae;
case 0x0c0b17b0u: goto P_0c0b17b0;
case 0x0c0b17b2u: goto P_0c0b17b2;
case 0x0c0b17b4u: goto P_0c0b17b4;
case 0x0c0b17b6u: goto P_0c0b17b6;
case 0x0c0b17b8u: goto P_0c0b17b8;
case 0x0c0b17bau: goto P_0c0b17ba;
case 0x0c0b17bcu: goto P_0c0b17bc;
case 0x0c0b17beu: goto P_0c0b17be;
case 0x0c0b17c0u: goto P_0c0b17c0;
case 0x0c0b17c2u: goto P_0c0b17c2;
case 0x0c0b17c4u: goto P_0c0b17c4;
case 0x0c0b17c6u: goto P_0c0b17c6;
case 0x0c0b17c8u: goto P_0c0b17c8;
case 0x0c0b17cau: goto P_0c0b17ca;
case 0x0c0b17ccu: goto P_0c0b17cc;
case 0x0c0b17ceu: goto P_0c0b17ce;
case 0x0c0b17d0u: goto P_0c0b17d0;
case 0x0c0b17d2u: goto P_0c0b17d2;
case 0x0c0b17d4u: goto P_0c0b17d4;
case 0x0c0b17d6u: goto P_0c0b17d6;
case 0x0c0b17d8u: goto P_0c0b17d8;
case 0x0c0b17dau: goto P_0c0b17da;
case 0x0c0b17dcu: goto P_0c0b17dc;
case 0x0c0b17deu: goto P_0c0b17de;
case 0x0c0b17e0u: goto P_0c0b17e0;
case 0x0c0b17e2u: goto P_0c0b17e2;
case 0x0c0b17e4u: goto P_0c0b17e4;
case 0x0c0b17e6u: goto P_0c0b17e6;
case 0x0c0b17e8u: goto P_0c0b17e8;
case 0x0c0b17eau: goto P_0c0b17ea;
case 0x0c0b17ecu: goto P_0c0b17ec;
case 0x0c0b17eeu: goto P_0c0b17ee;
case 0x0c0b17f0u: goto P_0c0b17f0;
case 0x0c0b17f2u: goto P_0c0b17f2;
case 0x0c0b17f4u: goto P_0c0b17f4;
case 0x0c0b17f6u: goto P_0c0b17f6;
case 0x0c0b17f8u: goto P_0c0b17f8;
case 0x0c0b17fau: goto P_0c0b17fa;
case 0x0c0b17fcu: goto P_0c0b17fc;
case 0x0c0b17feu: goto P_0c0b17fe;
case 0x0c0b1800u: goto P_0c0b1800;
case 0x0c0b1802u: goto P_0c0b1802;
case 0x0c0b1804u: goto P_0c0b1804;
case 0x0c0b1806u: goto P_0c0b1806;
case 0x0c0b1828u: goto P_0c0b1828;
case 0x0c0b182au: goto P_0c0b182a;
case 0x0c0b182cu: goto P_0c0b182c;
case 0x0c0b182eu: goto P_0c0b182e;
case 0x0c0b1830u: goto P_0c0b1830;
case 0x0c0b1832u: goto P_0c0b1832;
case 0x0c0b1834u: goto P_0c0b1834;
case 0x0c0b1836u: goto P_0c0b1836;
case 0x0c0b1838u: goto P_0c0b1838;
case 0x0c0b183au: goto P_0c0b183a;
case 0x0c0b183cu: goto P_0c0b183c;
case 0x0c0b183eu: goto P_0c0b183e;
case 0x0c0b1840u: goto P_0c0b1840;
case 0x0c0b1842u: goto P_0c0b1842;
case 0x0c0b1844u: goto P_0c0b1844;
case 0x0c0b1846u: goto P_0c0b1846;
case 0x0c0b1848u: goto P_0c0b1848;
case 0x0c0b184au: goto P_0c0b184a;
case 0x0c0b184cu: goto P_0c0b184c;
case 0x0c0b184eu: goto P_0c0b184e;
case 0x0c0b1850u: goto P_0c0b1850;
case 0x0c0b1852u: goto P_0c0b1852;
case 0x0c0b1854u: goto P_0c0b1854;
case 0x0c0b1856u: goto P_0c0b1856;
case 0x0c0b1858u: goto P_0c0b1858;
case 0x0c0b185au: goto P_0c0b185a;
case 0x0c0b185cu: goto P_0c0b185c;
case 0x0c0b185eu: goto P_0c0b185e;
case 0x0c0b1860u: goto P_0c0b1860;
case 0x0c0b1862u: goto P_0c0b1862;
case 0x0c0b1864u: goto P_0c0b1864;
case 0x0c0b1866u: goto P_0c0b1866;
case 0x0c0b1868u: goto P_0c0b1868;
case 0x0c0b186au: goto P_0c0b186a;
case 0x0c0b186cu: goto P_0c0b186c;
case 0x0c0b186eu: goto P_0c0b186e;
case 0x0c0b1870u: goto P_0c0b1870;
case 0x0c0b187cu: goto P_0c0b187c;
case 0x0c0b187eu: goto P_0c0b187e;
case 0x0c0b1880u: goto P_0c0b1880;
case 0x0c0b1882u: goto P_0c0b1882;
case 0x0c0b1884u: goto P_0c0b1884;
case 0x0c0b1886u: goto P_0c0b1886;
case 0x0c0b1888u: goto P_0c0b1888;
case 0x0c0b188au: goto P_0c0b188a;
case 0x0c0b188cu: goto P_0c0b188c;
case 0x0c0b188eu: goto P_0c0b188e;
case 0x0c0b1890u: goto P_0c0b1890;
case 0x0c0b1892u: goto P_0c0b1892;
case 0x0c0b1894u: goto P_0c0b1894;
case 0x0c0b1896u: goto P_0c0b1896;
case 0x0c0b1898u: goto P_0c0b1898;
case 0x0c0b189au: goto P_0c0b189a;
case 0x0c0b189cu: goto P_0c0b189c;
case 0x0c0b189eu: goto P_0c0b189e;
case 0x0c0b18a0u: goto P_0c0b18a0;
case 0x0c0b18a2u: goto P_0c0b18a2;
case 0x0c0b18a4u: goto P_0c0b18a4;
case 0x0c0b18a6u: goto P_0c0b18a6;
case 0x0c0b18a8u: goto P_0c0b18a8;
case 0x0c0b18aau: goto P_0c0b18aa;
case 0x0c0b18acu: goto P_0c0b18ac;
case 0x0c0b18aeu: goto P_0c0b18ae;
case 0x0c0b18b0u: goto P_0c0b18b0;
case 0x0c0b18b2u: goto P_0c0b18b2;
case 0x0c0b18b4u: goto P_0c0b18b4;
case 0x0c0b18b6u: goto P_0c0b18b6;
case 0x0c0b18b8u: goto P_0c0b18b8;
case 0x0c0b18bau: goto P_0c0b18ba;
case 0x0c0b18bcu: goto P_0c0b18bc;
case 0x0c0b18beu: goto P_0c0b18be;
case 0x0c0b18c0u: goto P_0c0b18c0;
case 0x0c0b18c2u: goto P_0c0b18c2;
case 0x0c0b18c4u: goto P_0c0b18c4;
case 0x0c0b18c6u: goto P_0c0b18c6;
case 0x0c0b18c8u: goto P_0c0b18c8;
case 0x0c0b18cau: goto P_0c0b18ca;
case 0x0c0b18ccu: goto P_0c0b18cc;
case 0x0c0b18ceu: goto P_0c0b18ce;
case 0x0c0b18d0u: goto P_0c0b18d0;
case 0x0c0b18d2u: goto P_0c0b18d2;
case 0x0c0b18d4u: goto P_0c0b18d4;
case 0x0c0b18d6u: goto P_0c0b18d6;
case 0x0c0b18d8u: goto P_0c0b18d8;
case 0x0c0b18dau: goto P_0c0b18da;
case 0x0c0b18dcu: goto P_0c0b18dc;
case 0x0c0b18deu: goto P_0c0b18de;
case 0x0c0b18e0u: goto P_0c0b18e0;
case 0x0c0b18e2u: goto P_0c0b18e2;
case 0x0c0b18e4u: goto P_0c0b18e4;
case 0x0c0b18e6u: goto P_0c0b18e6;
case 0x0c0b18e8u: goto P_0c0b18e8;
case 0x0c0b18eau: goto P_0c0b18ea;
case 0x0c0b18ecu: goto P_0c0b18ec;
case 0x0c0b18eeu: goto P_0c0b18ee;
case 0x0c0b18f0u: goto P_0c0b18f0;
case 0x0c0b18f2u: goto P_0c0b18f2;
case 0x0c0b18f4u: goto P_0c0b18f4;
case 0x0c0b18f6u: goto P_0c0b18f6;
case 0x0c0b18f8u: goto P_0c0b18f8;
case 0x0c0b18fau: goto P_0c0b18fa;
case 0x0c0b18fcu: goto P_0c0b18fc;
case 0x0c0b18feu: goto P_0c0b18fe;
case 0x0c0b1900u: goto P_0c0b1900;
case 0x0c0b1902u: goto P_0c0b1902;
case 0x0c0b1904u: goto P_0c0b1904;
case 0x0c0b1906u: goto P_0c0b1906;
case 0x0c0b1908u: goto P_0c0b1908;
case 0x0c0b190au: goto P_0c0b190a;
case 0x0c0b190cu: goto P_0c0b190c;
case 0x0c0b190eu: goto P_0c0b190e;
case 0x0c0b1910u: goto P_0c0b1910;
case 0x0c0b1912u: goto P_0c0b1912;
case 0x0c0b1914u: goto P_0c0b1914;
case 0x0c0b1916u: goto P_0c0b1916;
case 0x0c0b1918u: goto P_0c0b1918;
case 0x0c0b191au: goto P_0c0b191a;
case 0x0c0b191cu: goto P_0c0b191c;
case 0x0c0b191eu: goto P_0c0b191e;
case 0x0c0b1920u: goto P_0c0b1920;
case 0x0c0b1922u: goto P_0c0b1922;
case 0x0c0b1924u: goto P_0c0b1924;
case 0x0c0b1926u: goto P_0c0b1926;
case 0x0c0b1928u: goto P_0c0b1928;
case 0x0c0b192au: goto P_0c0b192a;
case 0x0c0b192cu: goto P_0c0b192c;
case 0x0c0b192eu: goto P_0c0b192e;
case 0x0c0b1944u: goto P_0c0b1944;
case 0x0c0b1946u: goto P_0c0b1946;
case 0x0c0b1948u: goto P_0c0b1948;
case 0x0c0b194au: goto P_0c0b194a;
case 0x0c0b194cu: goto P_0c0b194c;
case 0x0c0b194eu: goto P_0c0b194e;
case 0x0c0b1950u: goto P_0c0b1950;
case 0x0c0b1952u: goto P_0c0b1952;
case 0x0c0b1954u: goto P_0c0b1954;
case 0x0c0b1956u: goto P_0c0b1956;
case 0x0c0b1958u: goto P_0c0b1958;
case 0x0c0b195au: goto P_0c0b195a;
case 0x0c0b195cu: goto P_0c0b195c;
case 0x0c0b195eu: goto P_0c0b195e;
case 0x0c0b1960u: goto P_0c0b1960;
case 0x0c0b1962u: goto P_0c0b1962;
case 0x0c0b1964u: goto P_0c0b1964;
case 0x0c0b1966u: goto P_0c0b1966;
case 0x0c0b1968u: goto P_0c0b1968;
case 0x0c0b196au: goto P_0c0b196a;
case 0x0c0b196cu: goto P_0c0b196c;
case 0x0c0b196eu: goto P_0c0b196e;
case 0x0c0b1970u: goto P_0c0b1970;
case 0x0c0b1972u: goto P_0c0b1972;
case 0x0c0b1974u: goto P_0c0b1974;
case 0x0c0b1976u: goto P_0c0b1976;
case 0x0c0b1978u: goto P_0c0b1978;
case 0x0c0b197au: goto P_0c0b197a;
case 0x0c0b197cu: goto P_0c0b197c;
case 0x0c0b197eu: goto P_0c0b197e;
case 0x0c0b1980u: goto P_0c0b1980;
case 0x0c0b1982u: goto P_0c0b1982;
case 0x0c0b1984u: goto P_0c0b1984;
case 0x0c0b1986u: goto P_0c0b1986;
case 0x0c0b1988u: goto P_0c0b1988;
case 0x0c0b198au: goto P_0c0b198a;
case 0x0c0b198cu: goto P_0c0b198c;
case 0x0c0b198eu: goto P_0c0b198e;
case 0x0c0b1990u: goto P_0c0b1990;
case 0x0c0b1992u: goto P_0c0b1992;
case 0x0c0b1994u: goto P_0c0b1994;
case 0x0c0b1996u: goto P_0c0b1996;
case 0x0c0b1998u: goto P_0c0b1998;
case 0x0c0b199au: goto P_0c0b199a;
case 0x0c0b199cu: goto P_0c0b199c;
case 0x0c0b199eu: goto P_0c0b199e;
case 0x0c0b19a0u: goto P_0c0b19a0;
case 0x0c0b19a2u: goto P_0c0b19a2;
case 0x0c0b19a4u: goto P_0c0b19a4;
case 0x0c0b19a6u: goto P_0c0b19a6;
case 0x0c0b19a8u: goto P_0c0b19a8;
case 0x0c0b19aau: goto P_0c0b19aa;
case 0x0c0b19acu: goto P_0c0b19ac;
case 0x0c0b19aeu: goto P_0c0b19ae;
case 0x0c0b19b0u: goto P_0c0b19b0;
case 0x0c0b19b2u: goto P_0c0b19b2;
case 0x0c0b19b4u: goto P_0c0b19b4;
case 0x0c0b19b6u: goto P_0c0b19b6;
case 0x0c0b19b8u: goto P_0c0b19b8;
case 0x0c0b19bau: goto P_0c0b19ba;
case 0x0c0b19bcu: goto P_0c0b19bc;
case 0x0c0b19beu: goto P_0c0b19be;
case 0x0c0b19c0u: goto P_0c0b19c0;
case 0x0c0b19c2u: goto P_0c0b19c2;
case 0x0c0b19c4u: goto P_0c0b19c4;
case 0x0c0b19c6u: goto P_0c0b19c6;
case 0x0c0b19c8u: goto P_0c0b19c8;
case 0x0c0b19cau: goto P_0c0b19ca;
case 0x0c0b19ccu: goto P_0c0b19cc;
case 0x0c0b19ceu: goto P_0c0b19ce;
case 0x0c0b19d0u: goto P_0c0b19d0;
case 0x0c0b19d2u: goto P_0c0b19d2;
case 0x0c0b19d4u: goto P_0c0b19d4;
case 0x0c0b19d6u: goto P_0c0b19d6;
case 0x0c0b19d8u: goto P_0c0b19d8;
case 0x0c0b19f4u: goto P_0c0b19f4;
case 0x0c0b19f6u: goto P_0c0b19f6;
case 0x0c0b19f8u: goto P_0c0b19f8;
case 0x0c0b19fau: goto P_0c0b19fa;
case 0x0c0b19fcu: goto P_0c0b19fc;
case 0x0c0b19feu: goto P_0c0b19fe;
case 0x0c0b1a00u: goto P_0c0b1a00;
case 0x0c0b1a02u: goto P_0c0b1a02;
case 0x0c0b1a04u: goto P_0c0b1a04;
case 0x0c0b1a06u: goto P_0c0b1a06;
case 0x0c0b1a08u: goto P_0c0b1a08;
case 0x0c0b1a0au: goto P_0c0b1a0a;
case 0x0c0b1a0cu: goto P_0c0b1a0c;
case 0x0c0b1a0eu: goto P_0c0b1a0e;
case 0x0c0b1a10u: goto P_0c0b1a10;
case 0x0c0b1a12u: goto P_0c0b1a12;
case 0x0c0b1a14u: goto P_0c0b1a14;
case 0x0c0b1a16u: goto P_0c0b1a16;
case 0x0c0b1a18u: goto P_0c0b1a18;
case 0x0c0b1a1au: goto P_0c0b1a1a;
case 0x0c0b1a1cu: goto P_0c0b1a1c;
case 0x0c0b1a1eu: goto P_0c0b1a1e;
case 0x0c0b1a20u: goto P_0c0b1a20;
case 0x0c0b1a22u: goto P_0c0b1a22;
case 0x0c0b1a24u: goto P_0c0b1a24;
case 0x0c0b1a26u: goto P_0c0b1a26;
case 0x0c0b1a28u: goto P_0c0b1a28;
case 0x0c0b1a2au: goto P_0c0b1a2a;
case 0x0c0b1a2cu: goto P_0c0b1a2c;
case 0x0c0b1a2eu: goto P_0c0b1a2e;
case 0x0c0b1a30u: goto P_0c0b1a30;
case 0x0c0b1a32u: goto P_0c0b1a32;
case 0x0c0b1a34u: goto P_0c0b1a34;
case 0x0c0b1a36u: goto P_0c0b1a36;
case 0x0c0b1a38u: goto P_0c0b1a38;
case 0x0c0b1a3au: goto P_0c0b1a3a;
case 0x0c0b1a3cu: goto P_0c0b1a3c;
case 0x0c0b1a3eu: goto P_0c0b1a3e;
case 0x0c0b1a40u: goto P_0c0b1a40;
case 0x0c0b1a42u: goto P_0c0b1a42;
case 0x0c0b1a44u: goto P_0c0b1a44;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b1550: /* original 2fe6, guest PC 0x0c0b1550 */
if(!s->budget--) { s->failed_pc=0x0c0b1550u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1552;
P_0c0b1552: /* original 6e53, guest PC 0x0c0b1552 */
if(!s->budget--) { s->failed_pc=0x0c0b1552u; return 0; }
r[14]=r[5];
goto P_0c0b1554;
P_0c0b1554: /* original 2fd6, guest PC 0x0c0b1554 */
if(!s->budget--) { s->failed_pc=0x0c0b1554u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1556;
P_0c0b1556: /* original 2fc6, guest PC 0x0c0b1556 */
if(!s->budget--) { s->failed_pc=0x0c0b1556u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1558;
P_0c0b1558: /* original 2fb6, guest PC 0x0c0b1558 */
if(!s->budget--) { s->failed_pc=0x0c0b1558u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b155a;
P_0c0b155a: /* original 2fa6, guest PC 0x0c0b155a */
if(!s->budget--) { s->failed_pc=0x0c0b155au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b155c;
P_0c0b155c: /* original 2f96, guest PC 0x0c0b155c */
if(!s->budget--) { s->failed_pc=0x0c0b155cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b155e;
P_0c0b155e: /* original 2f86, guest PC 0x0c0b155e */
if(!s->budget--) { s->failed_pc=0x0c0b155eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1560;
P_0c0b1560: /* original 4f22, guest PC 0x0c0b1560 */
if(!s->budget--) { s->failed_pc=0x0c0b1560u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1562;
P_0c0b1562: /* original 7fc8, guest PC 0x0c0b1562 */
if(!s->budget--) { s->failed_pc=0x0c0b1562u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0b1564;
P_0c0b1564: /* original 1f41, guest PC 0x0c0b1564 */
if(!s->budget--) { s->failed_pc=0x0c0b1564u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0b1566;
P_0c0b1566: /* original d335, guest PC 0x0c0b1566 */
if(!s->budget--) { s->failed_pc=0x0c0b1566u; return 0; }
r[3]=read(ram,0x0c0b163cu,4);
goto P_0c0b1568;
P_0c0b1568: /* original dd33, guest PC 0x0c0b1568 */
if(!s->budget--) { s->failed_pc=0x0c0b1568u; return 0; }
r[13]=read(ram,0x0c0b1638u,4);
goto P_0c0b156a;
P_0c0b156a: /* original 1f33, guest PC 0x0c0b156a */
if(!s->budget--) { s->failed_pc=0x0c0b156au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0b156c;
P_0c0b156c: /* original d335, guest PC 0x0c0b156c */
if(!s->budget--) { s->failed_pc=0x0c0b156cu; return 0; }
r[3]=read(ram,0x0c0b1644u,4);
goto P_0c0b156e;
P_0c0b156e: /* original d234, guest PC 0x0c0b156e */
if(!s->budget--) { s->failed_pc=0x0c0b156eu; return 0; }
r[2]=read(ram,0x0c0b1640u,4);
goto P_0c0b1570;
P_0c0b1570: /* original 430b, guest PC 0x0c0b1570 */
if(!s->budget--) { s->failed_pc=0x0c0b1570u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1574u;
write(ram,r[15],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1574u) { target=s->pc; goto dispatch; }
goto P_0c0b1574;
P_0c0b1572: /* original 2f22, guest PC 0x0c0b1572 */
if(!s->budget--) { s->failed_pc=0x0c0b1572u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1574;
P_0c0b1574: /* original 2008, guest PC 0x0c0b1574 */
if(!s->budget--) { s->failed_pc=0x0c0b1574u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b1576;
P_0c0b1576: /* original 8b01, guest PC 0x0c0b1576 */
if(!s->budget--) { s->failed_pc=0x0c0b1576u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b157c; }
goto P_0c0b1578;
P_0c0b1578: /* original a25b, guest PC 0x0c0b1578 */
if(!s->budget--) { s->failed_pc=0x0c0b1578u; return 0; }
goto P_0c0b1a32;
P_0c0b157a: /* original 0009, guest PC 0x0c0b157a */
if(!s->budget--) { s->failed_pc=0x0c0b157au; return 0; }
goto P_0c0b157c;
P_0c0b157c: /* original e060, guest PC 0x0c0b157c */
if(!s->budget--) { s->failed_pc=0x0c0b157cu; return 0; }
r[0]=0x00000060u;
goto P_0c0b157e;
P_0c0b157e: /* original 0bec, guest PC 0x0c0b157e */
if(!s->budget--) { s->failed_pc=0x0c0b157eu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1580;
P_0c0b1580: /* original 60bc, guest PC 0x0c0b1580 */
if(!s->budget--) { s->failed_pc=0x0c0b1580u; return 0; }
r[0]=r[11]&255u;
goto P_0c0b1582;
P_0c0b1582: /* original 880b, guest PC 0x0c0b1582 */
if(!s->budget--) { s->failed_pc=0x0c0b1582u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0b1584;
P_0c0b1584: /* original 8f06, guest PC 0x0c0b1584 */
if(!s->budget--) { s->failed_pc=0x0c0b1584u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c0b1594; }
goto P_0c0b1588;
P_0c0b1586: /* original 6b03, guest PC 0x0c0b1586 */
if(!s->budget--) { s->failed_pc=0x0c0b1586u; return 0; }
r[11]=r[0];
goto P_0c0b1588;
P_0c0b1588: /* original 9051, guest PC 0x0c0b1588 */
if(!s->budget--) { s->failed_pc=0x0c0b1588u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b162eu,2);
goto P_0c0b158a;
P_0c0b158a: /* original 02dc, guest PC 0x0c0b158a */
if(!s->budget--) { s->failed_pc=0x0c0b158au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0b158c;
P_0c0b158c: /* original 2228, guest PC 0x0c0b158c */
if(!s->budget--) { s->failed_pc=0x0c0b158cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b158e;
P_0c0b158e: /* original 8911, guest PC 0x0c0b158e */
if(!s->budget--) { s->failed_pc=0x0c0b158eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b15b4; }
goto P_0c0b1590;
P_0c0b1590: /* original a010, guest PC 0x0c0b1590 */
if(!s->budget--) { s->failed_pc=0x0c0b1590u; return 0; }
r[11]=0x0000001au;
goto P_0c0b15b4;
P_0c0b1592: /* original eb1a, guest PC 0x0c0b1592 */
if(!s->budget--) { s->failed_pc=0x0c0b1592u; return 0; }
r[11]=0x0000001au;
goto P_0c0b1594;
P_0c0b1594: /* original 60b3, guest PC 0x0c0b1594 */
if(!s->budget--) { s->failed_pc=0x0c0b1594u; return 0; }
r[0]=r[11];
goto P_0c0b1596;
P_0c0b1596: /* original 8818, guest PC 0x0c0b1596 */
if(!s->budget--) { s->failed_pc=0x0c0b1596u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c0b1598;
P_0c0b1598: /* original 8b05, guest PC 0x0c0b1598 */
if(!s->budget--) { s->failed_pc=0x0c0b1598u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b15a6; }
goto P_0c0b159a;
P_0c0b159a: /* original 9048, guest PC 0x0c0b159a */
if(!s->budget--) { s->failed_pc=0x0c0b159au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b162eu,2);
goto P_0c0b159c;
P_0c0b159c: /* original 02dc, guest PC 0x0c0b159c */
if(!s->budget--) { s->failed_pc=0x0c0b159cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0b159e;
P_0c0b159e: /* original 2228, guest PC 0x0c0b159e */
if(!s->budget--) { s->failed_pc=0x0c0b159eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b15a0;
P_0c0b15a0: /* original 8908, guest PC 0x0c0b15a0 */
if(!s->budget--) { s->failed_pc=0x0c0b15a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b15b4; }
goto P_0c0b15a2;
P_0c0b15a2: /* original a007, guest PC 0x0c0b15a2 */
if(!s->budget--) { s->failed_pc=0x0c0b15a2u; return 0; }
r[11]=0x0000001bu;
goto P_0c0b15b4;
P_0c0b15a4: /* original eb1b, guest PC 0x0c0b15a4 */
if(!s->budget--) { s->failed_pc=0x0c0b15a4u; return 0; }
r[11]=0x0000001bu;
goto P_0c0b15a6;
P_0c0b15a6: /* original 880c, guest PC 0x0c0b15a6 */
if(!s->budget--) { s->failed_pc=0x0c0b15a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0b15a8;
P_0c0b15a8: /* original 8b04, guest PC 0x0c0b15a8 */
if(!s->budget--) { s->failed_pc=0x0c0b15a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b15b4; }
goto P_0c0b15aa;
P_0c0b15aa: /* original 9041, guest PC 0x0c0b15aa */
if(!s->budget--) { s->failed_pc=0x0c0b15aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1630u,2);
goto P_0c0b15ac;
P_0c0b15ac: /* original 02dc, guest PC 0x0c0b15ac */
if(!s->budget--) { s->failed_pc=0x0c0b15acu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0b15ae;
P_0c0b15ae: /* original 2228, guest PC 0x0c0b15ae */
if(!s->budget--) { s->failed_pc=0x0c0b15aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b15b0;
P_0c0b15b0: /* original 8900, guest PC 0x0c0b15b0 */
if(!s->budget--) { s->failed_pc=0x0c0b15b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b15b4; }
goto P_0c0b15b2;
P_0c0b15b2: /* original eb1c, guest PC 0x0c0b15b2 */
if(!s->budget--) { s->failed_pc=0x0c0b15b2u; return 0; }
r[11]=0x0000001cu;
goto P_0c0b15b4;
P_0c0b15b4: /* original d024, guest PC 0x0c0b15b4 */
if(!s->budget--) { s->failed_pc=0x0c0b15b4u; return 0; }
r[0]=read(ram,0x0c0b1648u,4);
goto P_0c0b15b6;
P_0c0b15b6: /* original 6ab3, guest PC 0x0c0b15b6 */
if(!s->budget--) { s->failed_pc=0x0c0b15b6u; return 0; }
r[10]=r[11];
goto P_0c0b15b8;
P_0c0b15b8: /* original 4a08, guest PC 0x0c0b15b8 */
if(!s->budget--) { s->failed_pc=0x0c0b15b8u; return 0; }
r[10]<<=2;
goto P_0c0b15ba;
P_0c0b15ba: /* original 65d2, guest PC 0x0c0b15ba */
if(!s->budget--) { s->failed_pc=0x0c0b15bau; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b15bc;
P_0c0b15bc: /* original 0aae, guest PC 0x0c0b15bc */
if(!s->budget--) { s->failed_pc=0x0c0b15bcu; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c0b15be;
P_0c0b15be: /* original d023, guest PC 0x0c0b15be */
if(!s->budget--) { s->failed_pc=0x0c0b15beu; return 0; }
r[0]=read(ram,0x0c0b164cu,4);
goto P_0c0b15c0;
P_0c0b15c0: /* original 6353, guest PC 0x0c0b15c0 */
if(!s->budget--) { s->failed_pc=0x0c0b15c0u; return 0; }
r[3]=r[5];
goto P_0c0b15c2;
P_0c0b15c2: /* original 4a08, guest PC 0x0c0b15c2 */
if(!s->budget--) { s->failed_pc=0x0c0b15c2u; return 0; }
r[10]<<=2;
goto P_0c0b15c4;
P_0c0b15c4: /* original d622, guest PC 0x0c0b15c4 */
if(!s->budget--) { s->failed_pc=0x0c0b15c4u; return 0; }
r[6]=read(ram,0x0c0b1650u,4);
goto P_0c0b15c6;
P_0c0b15c6: /* original 0aae, guest PC 0x0c0b15c6 */
if(!s->budget--) { s->failed_pc=0x0c0b15c6u; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c0b15c8;
P_0c0b15c8: /* original 64e2, guest PC 0x0c0b15c8 */
if(!s->budget--) { s->failed_pc=0x0c0b15c8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0b15ca;
P_0c0b15ca: /* original 2368, guest PC 0x0c0b15ca */
if(!s->budget--) { s->failed_pc=0x0c0b15cau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0b15cc;
P_0c0b15cc: /* original 8d09, guest PC 0x0c0b15cc */
if(!s->budget--) { s->failed_pc=0x0c0b15ccu; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[13]+4,4);
if(cond) { goto P_0c0b15e2; }
goto P_0c0b15d0;
P_0c0b15ce: /* original 57d1, guest PC 0x0c0b15ce */
if(!s->budget--) { s->failed_pc=0x0c0b15ceu; return 0; }
r[7]=read(ram,r[13]+4,4);
goto P_0c0b15d0;
P_0c0b15d0: /* original 902f, guest PC 0x0c0b15d0 */
if(!s->budget--) { s->failed_pc=0x0c0b15d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1632u,2);
goto P_0c0b15d2;
P_0c0b15d2: /* original 61f2, guest PC 0x0c0b15d2 */
if(!s->budget--) { s->failed_pc=0x0c0b15d2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0b15d4;
P_0c0b15d4: /* original 031c, guest PC 0x0c0b15d4 */
if(!s->budget--) { s->failed_pc=0x0c0b15d4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0b15d6;
P_0c0b15d6: /* original 2338, guest PC 0x0c0b15d6 */
if(!s->budget--) { s->failed_pc=0x0c0b15d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b15d8;
P_0c0b15d8: /* original 8901, guest PC 0x0c0b15d8 */
if(!s->budget--) { s->failed_pc=0x0c0b15d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b15de; }
goto P_0c0b15da;
P_0c0b15da: /* original a22a, guest PC 0x0c0b15da */
if(!s->budget--) { s->failed_pc=0x0c0b15dau; return 0; }
goto P_0c0b1a32;
P_0c0b15dc: /* original 0009, guest PC 0x0c0b15dc */
if(!s->budget--) { s->failed_pc=0x0c0b15dcu; return 0; }
goto P_0c0b15de;
P_0c0b15de: /* original a014, guest PC 0x0c0b15de */
if(!s->budget--) { s->failed_pc=0x0c0b15deu; return 0; }
goto P_0c0b160a;
P_0c0b15e0: /* original 0009, guest PC 0x0c0b15e0 */
if(!s->budget--) { s->failed_pc=0x0c0b15e0u; return 0; }
goto P_0c0b15e2;
P_0c0b15e2: /* original d21c, guest PC 0x0c0b15e2 */
if(!s->budget--) { s->failed_pc=0x0c0b15e2u; return 0; }
r[2]=read(ram,0x0c0b1654u,4);
goto P_0c0b15e4;
P_0c0b15e4: /* original 2528, guest PC 0x0c0b15e4 */
if(!s->budget--) { s->failed_pc=0x0c0b15e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0b15e6;
P_0c0b15e6: /* original 8901, guest PC 0x0c0b15e6 */
if(!s->budget--) { s->failed_pc=0x0c0b15e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b15ec; }
goto P_0c0b15e8;
P_0c0b15e8: /* original 2768, guest PC 0x0c0b15e8 */
if(!s->budget--) { s->failed_pc=0x0c0b15e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[6])==0)!=0);
goto P_0c0b15ea;
P_0c0b15ea: /* original 8b0e, guest PC 0x0c0b15ea */
if(!s->budget--) { s->failed_pc=0x0c0b15eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b160a; }
goto P_0c0b15ec;
P_0c0b15ec: /* original e201, guest PC 0x0c0b15ec */
if(!s->budget--) { s->failed_pc=0x0c0b15ecu; return 0; }
r[2]=0x00000001u;
goto P_0c0b15ee;
P_0c0b15ee: /* original 2248, guest PC 0x0c0b15ee */
if(!s->budget--) { s->failed_pc=0x0c0b15eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0b15f0;
P_0c0b15f0: /* original 8b01, guest PC 0x0c0b15f0 */
if(!s->budget--) { s->failed_pc=0x0c0b15f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b15f6; }
goto P_0c0b15f2;
P_0c0b15f2: /* original a21e, guest PC 0x0c0b15f2 */
if(!s->budget--) { s->failed_pc=0x0c0b15f2u; return 0; }
goto P_0c0b1a32;
P_0c0b15f4: /* original 0009, guest PC 0x0c0b15f4 */
if(!s->budget--) { s->failed_pc=0x0c0b15f4u; return 0; }
goto P_0c0b15f6;
P_0c0b15f6: /* original d118, guest PC 0x0c0b15f6 */
if(!s->budget--) { s->failed_pc=0x0c0b15f6u; return 0; }
r[1]=read(ram,0x0c0b1658u,4);
goto P_0c0b15f8;
P_0c0b15f8: /* original 2148, guest PC 0x0c0b15f8 */
if(!s->budget--) { s->failed_pc=0x0c0b15f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0b15fa;
P_0c0b15fa: /* original 8b01, guest PC 0x0c0b15fa */
if(!s->budget--) { s->failed_pc=0x0c0b15fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1600; }
goto P_0c0b15fc;
P_0c0b15fc: /* original a219, guest PC 0x0c0b15fc */
if(!s->budget--) { s->failed_pc=0x0c0b15fcu; return 0; }
goto P_0c0b1a32;
P_0c0b15fe: /* original 0009, guest PC 0x0c0b15fe */
if(!s->budget--) { s->failed_pc=0x0c0b15feu; return 0; }
goto P_0c0b1600;
P_0c0b1600: /* original e202, guest PC 0x0c0b1600 */
if(!s->budget--) { s->failed_pc=0x0c0b1600u; return 0; }
r[2]=0x00000002u;
goto P_0c0b1602;
P_0c0b1602: /* original 2248, guest PC 0x0c0b1602 */
if(!s->budget--) { s->failed_pc=0x0c0b1602u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0b1604;
P_0c0b1604: /* original 8901, guest PC 0x0c0b1604 */
if(!s->budget--) { s->failed_pc=0x0c0b1604u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b160a; }
goto P_0c0b1606;
P_0c0b1606: /* original a214, guest PC 0x0c0b1606 */
if(!s->budget--) { s->failed_pc=0x0c0b1606u; return 0; }
goto P_0c0b1a32;
P_0c0b1608: /* original 0009, guest PC 0x0c0b1608 */
if(!s->budget--) { s->failed_pc=0x0c0b1608u; return 0; }
goto P_0c0b160a;
P_0c0b160a: /* original 2e42, guest PC 0x0c0b160a */
if(!s->budget--) { s->failed_pc=0x0c0b160au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0b160c;
P_0c0b160c: /* original d213, guest PC 0x0c0b160c */
if(!s->budget--) { s->failed_pc=0x0c0b160cu; return 0; }
r[2]=read(ram,0x0c0b165cu,4);
goto P_0c0b160e;
P_0c0b160e: /* original 6022, guest PC 0x0c0b160e */
if(!s->budget--) { s->failed_pc=0x0c0b160eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0b1610;
P_0c0b1610: /* original c810, guest PC 0x0c0b1610 */
if(!s->budget--) { s->failed_pc=0x0c0b1610u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0b1612;
P_0c0b1612: /* original 8903, guest PC 0x0c0b1612 */
if(!s->budget--) { s->failed_pc=0x0c0b1612u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b161c; }
goto P_0c0b1614;
P_0c0b1614: /* original b356, guest PC 0x0c0b1614 */
if(!s->budget--) { s->failed_pc=0x0c0b1614u; return 0; }
target=code_base|0x0c0b1cc4u; r[16]=code_base|0x0c0b1618u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1618u) { target=s->pc; goto dispatch; }
goto P_0c0b1618;
P_0c0b1616: /* original 64e3, guest PC 0x0c0b1616 */
if(!s->budget--) { s->failed_pc=0x0c0b1616u; return 0; }
r[4]=r[14];
goto P_0c0b1618;
P_0c0b1618: /* original a13e, guest PC 0x0c0b1618 */
if(!s->budget--) { s->failed_pc=0x0c0b1618u; return 0; }
goto P_0c0b1898;
P_0c0b161a: /* original 0009, guest PC 0x0c0b161a */
if(!s->budget--) { s->failed_pc=0x0c0b161au; return 0; }
goto P_0c0b161c;
P_0c0b161c: /* original 50f3, guest PC 0x0c0b161c */
if(!s->budget--) { s->failed_pc=0x0c0b161cu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0b161e;
P_0c0b161e: /* original 9909, guest PC 0x0c0b161e */
if(!s->budget--) { s->failed_pc=0x0c0b161eu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1634u,2);
goto P_0c0b1620;
P_0c0b1620: /* original 5001, guest PC 0x0c0b1620 */
if(!s->budget--) { s->failed_pc=0x0c0b1620u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0b1622;
P_0c0b1622: /* original c801, guest PC 0x0c0b1622 */
if(!s->budget--) { s->failed_pc=0x0c0b1622u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0b1624;
P_0c0b1624: /* original 8d1c, guest PC 0x0c0b1624 */
if(!s->budget--) { s->failed_pc=0x0c0b1624u; return 0; }
cond=r[17]&1u;
r[9]+=r[14];
if(cond) { goto P_0c0b1660; }
goto P_0c0b1628;
P_0c0b1626: /* original 39ec, guest PC 0x0c0b1626 */
if(!s->budget--) { s->failed_pc=0x0c0b1626u; return 0; }
r[9]+=r[14];
goto P_0c0b1628;
P_0c0b1628: /* original e201, guest PC 0x0c0b1628 */
if(!s->budget--) { s->failed_pc=0x0c0b1628u; return 0; }
r[2]=0x00000001u;
goto P_0c0b162a;
P_0c0b162a: /* original a01b, guest PC 0x0c0b162a */
if(!s->budget--) { s->failed_pc=0x0c0b162au; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0b1664;
P_0c0b162c: /* original 1f2d, guest PC 0x0c0b162c */
if(!s->budget--) { s->failed_pc=0x0c0b162cu; return 0; }
write(ram,r[15]+52,r[2],4);
if(!vf3_matrix_family(0x0c0b162eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b162eu; return 0; } return 1;
P_0c0b1660: /* original e100, guest PC 0x0c0b1660 */
if(!s->budget--) { s->failed_pc=0x0c0b1660u; return 0; }
r[1]=0x00000000u;
goto P_0c0b1662;
P_0c0b1662: /* original 1f1d, guest PC 0x0c0b1662 */
if(!s->budget--) { s->failed_pc=0x0c0b1662u; return 0; }
write(ram,r[15]+52,r[1],4);
goto P_0c0b1664;
P_0c0b1664: /* original 62e2, guest PC 0x0c0b1664 */
if(!s->budget--) { s->failed_pc=0x0c0b1664u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0b1666;
P_0c0b1666: /* original d32a, guest PC 0x0c0b1666 */
if(!s->budget--) { s->failed_pc=0x0c0b1666u; return 0; }
r[3]=read(ram,0x0c0b1710u,4);
goto P_0c0b1668;
P_0c0b1668: /* original 2238, guest PC 0x0c0b1668 */
if(!s->budget--) { s->failed_pc=0x0c0b1668u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b166a;
P_0c0b166a: /* original 8901, guest PC 0x0c0b166a */
if(!s->budget--) { s->failed_pc=0x0c0b166au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1670; }
goto P_0c0b166c;
P_0c0b166c: /* original a001, guest PC 0x0c0b166c */
if(!s->budget--) { s->failed_pc=0x0c0b166cu; return 0; }
r[4]=0x00000000u;
goto P_0c0b1672;
P_0c0b166e: /* original e400, guest PC 0x0c0b166e */
if(!s->budget--) { s->failed_pc=0x0c0b166eu; return 0; }
r[4]=0x00000000u;
goto P_0c0b1670;
P_0c0b1670: /* original e401, guest PC 0x0c0b1670 */
if(!s->budget--) { s->failed_pc=0x0c0b1670u; return 0; }
r[4]=0x00000001u;
goto P_0c0b1672;
P_0c0b1672: /* original 53f1, guest PC 0x0c0b1672 */
if(!s->budget--) { s->failed_pc=0x0c0b1672u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1674;
P_0c0b1674: /* original d227, guest PC 0x0c0b1674 */
if(!s->budget--) { s->failed_pc=0x0c0b1674u; return 0; }
r[2]=read(ram,0x0c0b1714u,4);
goto P_0c0b1676;
P_0c0b1676: /* original 6132, guest PC 0x0c0b1676 */
if(!s->budget--) { s->failed_pc=0x0c0b1676u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b1678;
P_0c0b1678: /* original 2128, guest PC 0x0c0b1678 */
if(!s->budget--) { s->failed_pc=0x0c0b1678u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0b167a;
P_0c0b167a: /* original 8901, guest PC 0x0c0b167a */
if(!s->budget--) { s->failed_pc=0x0c0b167au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1680; }
goto P_0c0b167c;
P_0c0b167c: /* original a001, guest PC 0x0c0b167c */
if(!s->budget--) { s->failed_pc=0x0c0b167cu; return 0; }
r[5]=0x00000000u;
goto P_0c0b1682;
P_0c0b167e: /* original e500, guest PC 0x0c0b167e */
if(!s->budget--) { s->failed_pc=0x0c0b167eu; return 0; }
r[5]=0x00000000u;
goto P_0c0b1680;
P_0c0b1680: /* original e501, guest PC 0x0c0b1680 */
if(!s->budget--) { s->failed_pc=0x0c0b1680u; return 0; }
r[5]=0x00000001u;
goto P_0c0b1682;
P_0c0b1682: /* original 254b, guest PC 0x0c0b1682 */
if(!s->budget--) { s->failed_pc=0x0c0b1682u; return 0; }
r[5]|=r[4];
goto P_0c0b1684;
P_0c0b1684: /* original 1f5c, guest PC 0x0c0b1684 */
if(!s->budget--) { s->failed_pc=0x0c0b1684u; return 0; }
write(ram,r[15]+48,r[5],4);
goto P_0c0b1686;
P_0c0b1686: /* original 53f1, guest PC 0x0c0b1686 */
if(!s->budget--) { s->failed_pc=0x0c0b1686u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1688;
P_0c0b1688: /* original d223, guest PC 0x0c0b1688 */
if(!s->budget--) { s->failed_pc=0x0c0b1688u; return 0; }
r[2]=read(ram,0x0c0b1718u,4);
goto P_0c0b168a;
P_0c0b168a: /* original 6132, guest PC 0x0c0b168a */
if(!s->budget--) { s->failed_pc=0x0c0b168au; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0b168c;
P_0c0b168c: /* original 2128, guest PC 0x0c0b168c */
if(!s->budget--) { s->failed_pc=0x0c0b168cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0b168e;
P_0c0b168e: /* original 8905, guest PC 0x0c0b168e */
if(!s->budget--) { s->failed_pc=0x0c0b168eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b169c; }
goto P_0c0b1690;
P_0c0b1690: /* original 60e2, guest PC 0x0c0b1690 */
if(!s->budget--) { s->failed_pc=0x0c0b1690u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0b1692;
P_0c0b1692: /* original d31f, guest PC 0x0c0b1692 */
if(!s->budget--) { s->failed_pc=0x0c0b1692u; return 0; }
r[3]=read(ram,0x0c0b1710u,4);
goto P_0c0b1694;
P_0c0b1694: /* original 2038, guest PC 0x0c0b1694 */
if(!s->budget--) { s->failed_pc=0x0c0b1694u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c0b1696;
P_0c0b1696: /* original 8901, guest PC 0x0c0b1696 */
if(!s->budget--) { s->failed_pc=0x0c0b1696u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b169c; }
goto P_0c0b1698;
P_0c0b1698: /* original a001, guest PC 0x0c0b1698 */
if(!s->budget--) { s->failed_pc=0x0c0b1698u; return 0; }
r[2]=0x00000000u;
goto P_0c0b169e;
P_0c0b169a: /* original e200, guest PC 0x0c0b169a */
if(!s->budget--) { s->failed_pc=0x0c0b169au; return 0; }
r[2]=0x00000000u;
goto P_0c0b169c;
P_0c0b169c: /* original e201, guest PC 0x0c0b169c */
if(!s->budget--) { s->failed_pc=0x0c0b169cu; return 0; }
r[2]=0x00000001u;
goto P_0c0b169e;
P_0c0b169e: /* original 1f21, guest PC 0x0c0b169e */
if(!s->budget--) { s->failed_pc=0x0c0b169eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b16a0;
P_0c0b16a0: /* original d21e, guest PC 0x0c0b16a0 */
if(!s->budget--) { s->failed_pc=0x0c0b16a0u; return 0; }
r[2]=read(ram,0x0c0b171cu,4);
goto P_0c0b16a2;
P_0c0b16a2: /* original 84e4, guest PC 0x0c0b16a2 */
if(!s->budget--) { s->failed_pc=0x0c0b16a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0b16a4;
P_0c0b16a4: /* original 6320, guest PC 0x0c0b16a4 */
if(!s->budget--) { s->failed_pc=0x0c0b16a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0b16a6;
P_0c0b16a6: /* original 3030, guest PC 0x0c0b16a6 */
if(!s->budget--) { s->failed_pc=0x0c0b16a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0b16a8;
P_0c0b16a8: /* original 0029, guest PC 0x0c0b16a8 */
if(!s->budget--) { s->failed_pc=0x0c0b16a8u; return 0; }
r[0]=r[17]&1u;
goto P_0c0b16aa;
P_0c0b16aa: /* original 2f02, guest PC 0x0c0b16aa */
if(!s->budget--) { s->failed_pc=0x0c0b16aau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0b16ac;
P_0c0b16ac: /* original e061, guest PC 0x0c0b16ac */
if(!s->budget--) { s->failed_pc=0x0c0b16acu; return 0; }
r[0]=0x00000061u;
goto P_0c0b16ae;
P_0c0b16ae: /* original 03ec, guest PC 0x0c0b16ae */
if(!s->budget--) { s->failed_pc=0x0c0b16aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b16b0;
P_0c0b16b0: /* original 2aa8, guest PC 0x0c0b16b0 */
if(!s->budget--) { s->failed_pc=0x0c0b16b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0b16b2;
P_0c0b16b2: /* original 633c, guest PC 0x0c0b16b2 */
if(!s->budget--) { s->failed_pc=0x0c0b16b2u; return 0; }
r[3]=r[3]&255u;
goto P_0c0b16b4;
P_0c0b16b4: /* original 8d01, guest PC 0x0c0b16b4 */
if(!s->budget--) { s->failed_pc=0x0c0b16b4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[3],4);
if(cond) { goto P_0c0b16ba; }
goto P_0c0b16b8;
P_0c0b16b6: /* original 1f33, guest PC 0x0c0b16b6 */
if(!s->budget--) { s->failed_pc=0x0c0b16b6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0b16b8;
P_0c0b16b8: /* original 6da3, guest PC 0x0c0b16b8 */
if(!s->budget--) { s->failed_pc=0x0c0b16b8u; return 0; }
r[13]=r[10];
goto P_0c0b16ba;
P_0c0b16ba: /* original d319, guest PC 0x0c0b16ba */
if(!s->budget--) { s->failed_pc=0x0c0b16bau; return 0; }
r[3]=read(ram,0x0c0b1720u,4);
goto P_0c0b16bc;
P_0c0b16bc: /* original 430b, guest PC 0x0c0b16bc */
if(!s->budget--) { s->failed_pc=0x0c0b16bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b16c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b16c0u) { target=s->pc; goto dispatch; }
goto P_0c0b16c0;
P_0c0b16be: /* original 0009, guest PC 0x0c0b16be */
if(!s->budget--) { s->failed_pc=0x0c0b16beu; return 0; }
goto P_0c0b16c0;
P_0c0b16c0: /* original 62f2, guest PC 0x0c0b16c0 */
if(!s->budget--) { s->failed_pc=0x0c0b16c0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0b16c2;
P_0c0b16c2: /* original 2228, guest PC 0x0c0b16c2 */
if(!s->budget--) { s->failed_pc=0x0c0b16c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b16c4;
P_0c0b16c4: /* original 8903, guest PC 0x0c0b16c4 */
if(!s->budget--) { s->failed_pc=0x0c0b16c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b16ce; }
goto P_0c0b16c6;
P_0c0b16c6: /* original b391, guest PC 0x0c0b16c6 */
if(!s->budget--) { s->failed_pc=0x0c0b16c6u; return 0; }
target=code_base|0x0c0b1decu; r[16]=code_base|0x0c0b16cau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b16cau) { target=s->pc; goto dispatch; }
goto P_0c0b16ca;
P_0c0b16c8: /* original 64e3, guest PC 0x0c0b16c8 */
if(!s->budget--) { s->failed_pc=0x0c0b16c8u; return 0; }
r[4]=r[14];
goto P_0c0b16ca;
P_0c0b16ca: /* original a15b, guest PC 0x0c0b16ca */
if(!s->budget--) { s->failed_pc=0x0c0b16cau; return 0; }
goto P_0c0b1984;
P_0c0b16cc: /* original 0009, guest PC 0x0c0b16cc */
if(!s->budget--) { s->failed_pc=0x0c0b16ccu; return 0; }
goto P_0c0b16ce;
P_0c0b16ce: /* original 1fd2, guest PC 0x0c0b16ce */
if(!s->budget--) { s->failed_pc=0x0c0b16ceu; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0b16d0;
P_0c0b16d0: /* original 53db, guest PC 0x0c0b16d0 */
if(!s->budget--) { s->failed_pc=0x0c0b16d0u; return 0; }
r[3]=read(ram,r[13]+44,4);
goto P_0c0b16d2;
P_0c0b16d2: /* original 2338, guest PC 0x0c0b16d2 */
if(!s->budget--) { s->failed_pc=0x0c0b16d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b16d4;
P_0c0b16d4: /* original 8b01, guest PC 0x0c0b16d4 */
if(!s->budget--) { s->failed_pc=0x0c0b16d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b16da; }
goto P_0c0b16d6;
P_0c0b16d6: /* original a0df, guest PC 0x0c0b16d6 */
if(!s->budget--) { s->failed_pc=0x0c0b16d6u; return 0; }
goto P_0c0b1898;
P_0c0b16d8: /* original 0009, guest PC 0x0c0b16d8 */
if(!s->budget--) { s->failed_pc=0x0c0b16d8u; return 0; }
goto P_0c0b16da;
P_0c0b16da: /* original 50f3, guest PC 0x0c0b16da */
if(!s->budget--) { s->failed_pc=0x0c0b16dau; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0b16dc;
P_0c0b16dc: /* original 8809, guest PC 0x0c0b16dc */
if(!s->budget--) { s->failed_pc=0x0c0b16dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b16de;
P_0c0b16de: /* original 8b05, guest PC 0x0c0b16de */
if(!s->budget--) { s->failed_pc=0x0c0b16deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b16ec; }
goto P_0c0b16e0;
P_0c0b16e0: /* original 56f1, guest PC 0x0c0b16e0 */
if(!s->budget--) { s->failed_pc=0x0c0b16e0u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0b16e2;
P_0c0b16e2: /* original 65d3, guest PC 0x0c0b16e2 */
if(!s->budget--) { s->failed_pc=0x0c0b16e2u; return 0; }
r[5]=r[13];
goto P_0c0b16e4;
P_0c0b16e4: /* original b3ec, guest PC 0x0c0b16e4 */
if(!s->budget--) { s->failed_pc=0x0c0b16e4u; return 0; }
target=code_base|0x0c0b1ec0u; r[16]=code_base|0x0c0b16e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b16e8u) { target=s->pc; goto dispatch; }
goto P_0c0b16e8;
P_0c0b16e6: /* original 64e3, guest PC 0x0c0b16e6 */
if(!s->budget--) { s->failed_pc=0x0c0b16e6u; return 0; }
r[4]=r[14];
goto P_0c0b16e8;
P_0c0b16e8: /* original a14c, guest PC 0x0c0b16e8 */
if(!s->budget--) { s->failed_pc=0x0c0b16e8u; return 0; }
goto P_0c0b1984;
P_0c0b16ea: /* original 0009, guest PC 0x0c0b16ea */
if(!s->budget--) { s->failed_pc=0x0c0b16eau; return 0; }
goto P_0c0b16ec;
P_0c0b16ec: /* original 60b3, guest PC 0x0c0b16ec */
if(!s->budget--) { s->failed_pc=0x0c0b16ecu; return 0; }
r[0]=r[11];
goto P_0c0b16ee;
P_0c0b16ee: /* original 8805, guest PC 0x0c0b16ee */
if(!s->budget--) { s->failed_pc=0x0c0b16eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b16f0;
P_0c0b16f0: /* original 8905, guest PC 0x0c0b16f0 */
if(!s->budget--) { s->failed_pc=0x0c0b16f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b16fe; }
goto P_0c0b16f2;
P_0c0b16f2: /* original 60b3, guest PC 0x0c0b16f2 */
if(!s->budget--) { s->failed_pc=0x0c0b16f2u; return 0; }
r[0]=r[11];
goto P_0c0b16f4;
P_0c0b16f4: /* original 8812, guest PC 0x0c0b16f4 */
if(!s->budget--) { s->failed_pc=0x0c0b16f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0b16f6;
P_0c0b16f6: /* original 8902, guest PC 0x0c0b16f6 */
if(!s->budget--) { s->failed_pc=0x0c0b16f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b16fe; }
goto P_0c0b16f8;
P_0c0b16f8: /* original 60b3, guest PC 0x0c0b16f8 */
if(!s->budget--) { s->failed_pc=0x0c0b16f8u; return 0; }
r[0]=r[11];
goto P_0c0b16fa;
P_0c0b16fa: /* original 8807, guest PC 0x0c0b16fa */
if(!s->budget--) { s->failed_pc=0x0c0b16fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0b16fc;
P_0c0b16fc: /* original 8b62, guest PC 0x0c0b16fc */
if(!s->budget--) { s->failed_pc=0x0c0b16fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b17c4; }
goto P_0c0b16fe;
P_0c0b16fe: /* original 84e4, guest PC 0x0c0b16fe */
if(!s->budget--) { s->failed_pc=0x0c0b16feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0b1700;
P_0c0b1700: /* original d408, guest PC 0x0c0b1700 */
if(!s->budget--) { s->failed_pc=0x0c0b1700u; return 0; }
r[4]=read(ram,0x0c0b1724u,4);
goto P_0c0b1702;
P_0c0b1702: /* original 2008, guest PC 0x0c0b1702 */
if(!s->budget--) { s->failed_pc=0x0c0b1702u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b1704;
P_0c0b1704: /* original 8b10, guest PC 0x0c0b1704 */
if(!s->budget--) { s->failed_pc=0x0c0b1704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1728; }
goto P_0c0b1706;
P_0c0b1706: /* original e068, guest PC 0x0c0b1706 */
if(!s->budget--) { s->failed_pc=0x0c0b1706u; return 0; }
r[0]=0x00000068u;
goto P_0c0b1708;
P_0c0b1708: /* original 024e, guest PC 0x0c0b1708 */
if(!s->budget--) { s->failed_pc=0x0c0b1708u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0b170a;
P_0c0b170a: /* original a010, guest PC 0x0c0b170a */
if(!s->budget--) { s->failed_pc=0x0c0b170au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b172e;
P_0c0b170c: /* original 2f22, guest PC 0x0c0b170c */
if(!s->budget--) { s->failed_pc=0x0c0b170cu; return 0; }
write(ram,r[15],r[2],4);
if(!vf3_matrix_family(0x0c0b170eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b170eu; return 0; } return 1;
P_0c0b1728: /* original e06c, guest PC 0x0c0b1728 */
if(!s->budget--) { s->failed_pc=0x0c0b1728u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b172a;
P_0c0b172a: /* original 014e, guest PC 0x0c0b172a */
if(!s->budget--) { s->failed_pc=0x0c0b172au; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0b172c;
P_0c0b172c: /* original 2f12, guest PC 0x0c0b172c */
if(!s->budget--) { s->failed_pc=0x0c0b172cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0b172e;
P_0c0b172e: /* original 63f2, guest PC 0x0c0b172e */
if(!s->budget--) { s->failed_pc=0x0c0b172eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1730;
P_0c0b1730: /* original 946a, guest PC 0x0c0b1730 */
if(!s->budget--) { s->failed_pc=0x0c0b1730u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1808u,2);
goto P_0c0b1732;
P_0c0b1732: /* original 334c, guest PC 0x0c0b1732 */
if(!s->budget--) { s->failed_pc=0x0c0b1732u; return 0; }
r[3]+=r[4];
goto P_0c0b1734;
P_0c0b1734: /* original 1f33, guest PC 0x0c0b1734 */
if(!s->budget--) { s->failed_pc=0x0c0b1734u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0b1736;
P_0c0b1736: /* original 334c, guest PC 0x0c0b1736 */
if(!s->budget--) { s->failed_pc=0x0c0b1736u; return 0; }
r[3]+=r[4];
goto P_0c0b1738;
P_0c0b1738: /* original 6233, guest PC 0x0c0b1738 */
if(!s->budget--) { s->failed_pc=0x0c0b1738u; return 0; }
r[2]=r[3];
goto P_0c0b173a;
P_0c0b173a: /* original 324c, guest PC 0x0c0b173a */
if(!s->budget--) { s->failed_pc=0x0c0b173au; return 0; }
r[2]+=r[4];
goto P_0c0b173c;
P_0c0b173c: /* original 1f35, guest PC 0x0c0b173c */
if(!s->budget--) { s->failed_pc=0x0c0b173cu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0b173e;
P_0c0b173e: /* original 1f24, guest PC 0x0c0b173e */
if(!s->budget--) { s->failed_pc=0x0c0b173eu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0b1740;
P_0c0b1740: /* original 324c, guest PC 0x0c0b1740 */
if(!s->budget--) { s->failed_pc=0x0c0b1740u; return 0; }
r[2]+=r[4];
goto P_0c0b1742;
P_0c0b1742: /* original 1f26, guest PC 0x0c0b1742 */
if(!s->budget--) { s->failed_pc=0x0c0b1742u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0b1744;
P_0c0b1744: /* original 60f2, guest PC 0x0c0b1744 */
if(!s->budget--) { s->failed_pc=0x0c0b1744u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0b1746;
P_0c0b1746: /* original 6002, guest PC 0x0c0b1746 */
if(!s->budget--) { s->failed_pc=0x0c0b1746u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0b1748;
P_0c0b1748: /* original c801, guest PC 0x0c0b1748 */
if(!s->budget--) { s->failed_pc=0x0c0b1748u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0b174a;
P_0c0b174a: /* original 893b, guest PC 0x0c0b174a */
if(!s->budget--) { s->failed_pc=0x0c0b174au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b17c4; }
goto P_0c0b174c;
P_0c0b174c: /* original 52a1, guest PC 0x0c0b174c */
if(!s->budget--) { s->failed_pc=0x0c0b174cu; return 0; }
r[2]=read(ram,r[10]+4,4);
goto P_0c0b174e;
P_0c0b174e: /* original 5321, guest PC 0x0c0b174e */
if(!s->budget--) { s->failed_pc=0x0c0b174eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0b1750;
P_0c0b1750: /* original 1f37, guest PC 0x0c0b1750 */
if(!s->budget--) { s->failed_pc=0x0c0b1750u; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0b1752;
P_0c0b1752: /* original 905a, guest PC 0x0c0b1752 */
if(!s->budget--) { s->failed_pc=0x0c0b1752u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180au,2);
goto P_0c0b1754;
P_0c0b1754: /* original 62f2, guest PC 0x0c0b1754 */
if(!s->budget--) { s->failed_pc=0x0c0b1754u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0b1756;
P_0c0b1756: /* original 032e, guest PC 0x0c0b1756 */
if(!s->budget--) { s->failed_pc=0x0c0b1756u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0b1758;
P_0c0b1758: /* original 2338, guest PC 0x0c0b1758 */
if(!s->budget--) { s->failed_pc=0x0c0b1758u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b175a;
P_0c0b175a: /* original 8902, guest PC 0x0c0b175a */
if(!s->budget--) { s->failed_pc=0x0c0b175au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1762; }
goto P_0c0b175c;
P_0c0b175c: /* original d22c, guest PC 0x0c0b175c */
if(!s->budget--) { s->failed_pc=0x0c0b175cu; return 0; }
r[2]=read(ram,0x0c0b1810u,4);
goto P_0c0b175e;
P_0c0b175e: /* original 53a1, guest PC 0x0c0b175e */
if(!s->budget--) { s->failed_pc=0x0c0b175eu; return 0; }
r[3]=read(ram,r[10]+4,4);
goto P_0c0b1760;
P_0c0b1760: /* original 1321, guest PC 0x0c0b1760 */
if(!s->budget--) { s->failed_pc=0x0c0b1760u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c0b1762;
P_0c0b1762: /* original 54ab, guest PC 0x0c0b1762 */
if(!s->budget--) { s->failed_pc=0x0c0b1762u; return 0; }
r[4]=read(ram,r[10]+44,4);
goto P_0c0b1764;
P_0c0b1764: /* original 5341, guest PC 0x0c0b1764 */
if(!s->budget--) { s->failed_pc=0x0c0b1764u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0b1766;
P_0c0b1766: /* original 5231, guest PC 0x0c0b1766 */
if(!s->budget--) { s->failed_pc=0x0c0b1766u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0b1768;
P_0c0b1768: /* original 1f28, guest PC 0x0c0b1768 */
if(!s->budget--) { s->failed_pc=0x0c0b1768u; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c0b176a;
P_0c0b176a: /* original 53f5, guest PC 0x0c0b176a */
if(!s->budget--) { s->failed_pc=0x0c0b176au; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0b176c;
P_0c0b176c: /* original 904d, guest PC 0x0c0b176c */
if(!s->budget--) { s->failed_pc=0x0c0b176cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180au,2);
goto P_0c0b176e;
P_0c0b176e: /* original 023e, guest PC 0x0c0b176e */
if(!s->budget--) { s->failed_pc=0x0c0b176eu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b1770;
P_0c0b1770: /* original 2228, guest PC 0x0c0b1770 */
if(!s->budget--) { s->failed_pc=0x0c0b1770u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b1772;
P_0c0b1772: /* original 8902, guest PC 0x0c0b1772 */
if(!s->budget--) { s->failed_pc=0x0c0b1772u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b177a; }
goto P_0c0b1774;
P_0c0b1774: /* original d327, guest PC 0x0c0b1774 */
if(!s->budget--) { s->failed_pc=0x0c0b1774u; return 0; }
r[3]=read(ram,0x0c0b1814u,4);
goto P_0c0b1776;
P_0c0b1776: /* original 5241, guest PC 0x0c0b1776 */
if(!s->budget--) { s->failed_pc=0x0c0b1776u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b1778;
P_0c0b1778: /* original 1231, guest PC 0x0c0b1778 */
if(!s->budget--) { s->failed_pc=0x0c0b1778u; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b177a;
P_0c0b177a: /* original 544b, guest PC 0x0c0b177a */
if(!s->budget--) { s->failed_pc=0x0c0b177au; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0b177c;
P_0c0b177c: /* original 5241, guest PC 0x0c0b177c */
if(!s->budget--) { s->failed_pc=0x0c0b177cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b177e;
P_0c0b177e: /* original 5321, guest PC 0x0c0b177e */
if(!s->budget--) { s->failed_pc=0x0c0b177eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0b1780;
P_0c0b1780: /* original 1f39, guest PC 0x0c0b1780 */
if(!s->budget--) { s->failed_pc=0x0c0b1780u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c0b1782;
P_0c0b1782: /* original 52f3, guest PC 0x0c0b1782 */
if(!s->budget--) { s->failed_pc=0x0c0b1782u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0b1784;
P_0c0b1784: /* original 9041, guest PC 0x0c0b1784 */
if(!s->budget--) { s->failed_pc=0x0c0b1784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180au,2);
goto P_0c0b1786;
P_0c0b1786: /* original 032e, guest PC 0x0c0b1786 */
if(!s->budget--) { s->failed_pc=0x0c0b1786u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0b1788;
P_0c0b1788: /* original 2338, guest PC 0x0c0b1788 */
if(!s->budget--) { s->failed_pc=0x0c0b1788u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b178a;
P_0c0b178a: /* original 8902, guest PC 0x0c0b178a */
if(!s->budget--) { s->failed_pc=0x0c0b178au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1792; }
goto P_0c0b178c;
P_0c0b178c: /* original d222, guest PC 0x0c0b178c */
if(!s->budget--) { s->failed_pc=0x0c0b178cu; return 0; }
r[2]=read(ram,0x0c0b1818u,4);
goto P_0c0b178e;
P_0c0b178e: /* original 5341, guest PC 0x0c0b178e */
if(!s->budget--) { s->failed_pc=0x0c0b178eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0b1790;
P_0c0b1790: /* original 1321, guest PC 0x0c0b1790 */
if(!s->budget--) { s->failed_pc=0x0c0b1790u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c0b1792;
P_0c0b1792: /* original 54ab, guest PC 0x0c0b1792 */
if(!s->budget--) { s->failed_pc=0x0c0b1792u; return 0; }
r[4]=read(ram,r[10]+44,4);
goto P_0c0b1794;
P_0c0b1794: /* original 544c, guest PC 0x0c0b1794 */
if(!s->budget--) { s->failed_pc=0x0c0b1794u; return 0; }
r[4]=read(ram,r[4]+48,4);
goto P_0c0b1796;
P_0c0b1796: /* original 5341, guest PC 0x0c0b1796 */
if(!s->budget--) { s->failed_pc=0x0c0b1796u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0b1798;
P_0c0b1798: /* original 5231, guest PC 0x0c0b1798 */
if(!s->budget--) { s->failed_pc=0x0c0b1798u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0b179a;
P_0c0b179a: /* original 1f2a, guest PC 0x0c0b179a */
if(!s->budget--) { s->failed_pc=0x0c0b179au; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0b179c;
P_0c0b179c: /* original 53f6, guest PC 0x0c0b179c */
if(!s->budget--) { s->failed_pc=0x0c0b179cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0b179e;
P_0c0b179e: /* original 9034, guest PC 0x0c0b179e */
if(!s->budget--) { s->failed_pc=0x0c0b179eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180au,2);
goto P_0c0b17a0;
P_0c0b17a0: /* original 023e, guest PC 0x0c0b17a0 */
if(!s->budget--) { s->failed_pc=0x0c0b17a0u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b17a2;
P_0c0b17a2: /* original 2228, guest PC 0x0c0b17a2 */
if(!s->budget--) { s->failed_pc=0x0c0b17a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b17a4;
P_0c0b17a4: /* original 8902, guest PC 0x0c0b17a4 */
if(!s->budget--) { s->failed_pc=0x0c0b17a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b17ac; }
goto P_0c0b17a6;
P_0c0b17a6: /* original d31d, guest PC 0x0c0b17a6 */
if(!s->budget--) { s->failed_pc=0x0c0b17a6u; return 0; }
r[3]=read(ram,0x0c0b181cu,4);
goto P_0c0b17a8;
P_0c0b17a8: /* original 5241, guest PC 0x0c0b17a8 */
if(!s->budget--) { s->failed_pc=0x0c0b17a8u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b17aa;
P_0c0b17aa: /* original 1231, guest PC 0x0c0b17aa */
if(!s->budget--) { s->failed_pc=0x0c0b17aau; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b17ac;
P_0c0b17ac: /* original 544b, guest PC 0x0c0b17ac */
if(!s->budget--) { s->failed_pc=0x0c0b17acu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0b17ae;
P_0c0b17ae: /* original 5241, guest PC 0x0c0b17ae */
if(!s->budget--) { s->failed_pc=0x0c0b17aeu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b17b0;
P_0c0b17b0: /* original 5321, guest PC 0x0c0b17b0 */
if(!s->budget--) { s->failed_pc=0x0c0b17b0u; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0b17b2;
P_0c0b17b2: /* original 1f3b, guest PC 0x0c0b17b2 */
if(!s->budget--) { s->failed_pc=0x0c0b17b2u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c0b17b4;
P_0c0b17b4: /* original 52f4, guest PC 0x0c0b17b4 */
if(!s->budget--) { s->failed_pc=0x0c0b17b4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0b17b6;
P_0c0b17b6: /* original 9028, guest PC 0x0c0b17b6 */
if(!s->budget--) { s->failed_pc=0x0c0b17b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180au,2);
goto P_0c0b17b8;
P_0c0b17b8: /* original 032e, guest PC 0x0c0b17b8 */
if(!s->budget--) { s->failed_pc=0x0c0b17b8u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0b17ba;
P_0c0b17ba: /* original 2338, guest PC 0x0c0b17ba */
if(!s->budget--) { s->failed_pc=0x0c0b17bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b17bc;
P_0c0b17bc: /* original 8902, guest PC 0x0c0b17bc */
if(!s->budget--) { s->failed_pc=0x0c0b17bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b17c4; }
goto P_0c0b17be;
P_0c0b17be: /* original d218, guest PC 0x0c0b17be */
if(!s->budget--) { s->failed_pc=0x0c0b17beu; return 0; }
r[2]=read(ram,0x0c0b1820u,4);
goto P_0c0b17c0;
P_0c0b17c0: /* original 5341, guest PC 0x0c0b17c0 */
if(!s->budget--) { s->failed_pc=0x0c0b17c0u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0b17c2;
P_0c0b17c2: /* original 1321, guest PC 0x0c0b17c2 */
if(!s->budget--) { s->failed_pc=0x0c0b17c2u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c0b17c4;
P_0c0b17c4: /* original a065, guest PC 0x0c0b17c4 */
if(!s->budget--) { s->failed_pc=0x0c0b17c4u; return 0; }
r[12]=0x00000000u;
goto P_0c0b1892;
P_0c0b17c6: /* original ec00, guest PC 0x0c0b17c6 */
if(!s->budget--) { s->failed_pc=0x0c0b17c6u; return 0; }
r[12]=0x00000000u;
goto P_0c0b17c8;
P_0c0b17c8: /* original 52f1, guest PC 0x0c0b17c8 */
if(!s->budget--) { s->failed_pc=0x0c0b17c8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0b17ca;
P_0c0b17ca: /* original 2228, guest PC 0x0c0b17ca */
if(!s->budget--) { s->failed_pc=0x0c0b17cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b17cc;
P_0c0b17cc: /* original 8959, guest PC 0x0c0b17cc */
if(!s->budget--) { s->failed_pc=0x0c0b17ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1882; }
goto P_0c0b17ce;
P_0c0b17ce: /* original 60c3, guest PC 0x0c0b17ce */
if(!s->budget--) { s->failed_pc=0x0c0b17ceu; return 0; }
r[0]=r[12];
goto P_0c0b17d0;
P_0c0b17d0: /* original d814, guest PC 0x0c0b17d0 */
if(!s->budget--) { s->failed_pc=0x0c0b17d0u; return 0; }
r[8]=read(ram,0x0c0b1824u,4);
goto P_0c0b17d2;
P_0c0b17d2: /* original 8805, guest PC 0x0c0b17d2 */
if(!s->budget--) { s->failed_pc=0x0c0b17d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b17d4;
P_0c0b17d4: /* original 8b0a, guest PC 0x0c0b17d4 */
if(!s->budget--) { s->failed_pc=0x0c0b17d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b17ec; }
goto P_0c0b17d6;
P_0c0b17d6: /* original 9519, guest PC 0x0c0b17d6 */
if(!s->budget--) { s->failed_pc=0x0c0b17d6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180cu,2);
goto P_0c0b17d8;
P_0c0b17d8: /* original e701, guest PC 0x0c0b17d8 */
if(!s->budget--) { s->failed_pc=0x0c0b17d8u; return 0; }
r[7]=0x00000001u;
goto P_0c0b17da;
P_0c0b17da: /* original 6693, guest PC 0x0c0b17da */
if(!s->budget--) { s->failed_pc=0x0c0b17dau; return 0; }
r[6]=r[9];
goto P_0c0b17dc;
P_0c0b17dc: /* original 35ec, guest PC 0x0c0b17dc */
if(!s->budget--) { s->failed_pc=0x0c0b17dcu; return 0; }
r[5]+=r[14];
goto P_0c0b17de;
P_0c0b17de: /* original 480b, guest PC 0x0c0b17de */
if(!s->budget--) { s->failed_pc=0x0c0b17deu; return 0; }
target=r[8];
r[16]=code_base|0x0c0b17e2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b17e2u) { target=s->pc; goto dispatch; }
goto P_0c0b17e2;
P_0c0b17e0: /* original 64e3, guest PC 0x0c0b17e0 */
if(!s->budget--) { s->failed_pc=0x0c0b17e0u; return 0; }
r[4]=r[14];
goto P_0c0b17e2;
P_0c0b17e2: /* original 5df2, guest PC 0x0c0b17e2 */
if(!s->budget--) { s->failed_pc=0x0c0b17e2u; return 0; }
r[13]=read(ram,r[15]+8,4);
goto P_0c0b17e4;
P_0c0b17e4: /* original 2dd8, guest PC 0x0c0b17e4 */
if(!s->budget--) { s->failed_pc=0x0c0b17e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0b17e6;
P_0c0b17e6: /* original 8b0c, guest PC 0x0c0b17e6 */
if(!s->budget--) { s->failed_pc=0x0c0b17e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1802; }
goto P_0c0b17e8;
P_0c0b17e8: /* original a04b, guest PC 0x0c0b17e8 */
if(!s->budget--) { s->failed_pc=0x0c0b17e8u; return 0; }
goto P_0c0b1882;
P_0c0b17ea: /* original 0009, guest PC 0x0c0b17ea */
if(!s->budget--) { s->failed_pc=0x0c0b17eau; return 0; }
goto P_0c0b17ec;
P_0c0b17ec: /* original 8809, guest PC 0x0c0b17ec */
if(!s->budget--) { s->failed_pc=0x0c0b17ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b17ee;
P_0c0b17ee: /* original 8b1b, guest PC 0x0c0b17ee */
if(!s->budget--) { s->failed_pc=0x0c0b17eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1828; }
goto P_0c0b17f0;
P_0c0b17f0: /* original 950d, guest PC 0x0c0b17f0 */
if(!s->budget--) { s->failed_pc=0x0c0b17f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b180eu,2);
goto P_0c0b17f2;
P_0c0b17f2: /* original e700, guest PC 0x0c0b17f2 */
if(!s->budget--) { s->failed_pc=0x0c0b17f2u; return 0; }
r[7]=0x00000000u;
goto P_0c0b17f4;
P_0c0b17f4: /* original 6693, guest PC 0x0c0b17f4 */
if(!s->budget--) { s->failed_pc=0x0c0b17f4u; return 0; }
r[6]=r[9];
goto P_0c0b17f6;
P_0c0b17f6: /* original 35ec, guest PC 0x0c0b17f6 */
if(!s->budget--) { s->failed_pc=0x0c0b17f6u; return 0; }
r[5]+=r[14];
goto P_0c0b17f8;
P_0c0b17f8: /* original 480b, guest PC 0x0c0b17f8 */
if(!s->budget--) { s->failed_pc=0x0c0b17f8u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b17fcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b17fcu) { target=s->pc; goto dispatch; }
goto P_0c0b17fc;
P_0c0b17fa: /* original 64e3, guest PC 0x0c0b17fa */
if(!s->budget--) { s->failed_pc=0x0c0b17fau; return 0; }
r[4]=r[14];
goto P_0c0b17fc;
P_0c0b17fc: /* original 5df2, guest PC 0x0c0b17fc */
if(!s->budget--) { s->failed_pc=0x0c0b17fcu; return 0; }
r[13]=read(ram,r[15]+8,4);
goto P_0c0b17fe;
P_0c0b17fe: /* original 2dd8, guest PC 0x0c0b17fe */
if(!s->budget--) { s->failed_pc=0x0c0b17feu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0b1800;
P_0c0b1800: /* original 893f, guest PC 0x0c0b1800 */
if(!s->budget--) { s->failed_pc=0x0c0b1800u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1882; }
goto P_0c0b1802;
P_0c0b1802: /* original 52dc, guest PC 0x0c0b1802 */
if(!s->budget--) { s->failed_pc=0x0c0b1802u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c0b1804;
P_0c0b1804: /* original a03d, guest PC 0x0c0b1804 */
if(!s->budget--) { s->failed_pc=0x0c0b1804u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0b1882;
P_0c0b1806: /* original 1f22, guest PC 0x0c0b1806 */
if(!s->budget--) { s->failed_pc=0x0c0b1806u; return 0; }
write(ram,r[15]+8,r[2],4);
if(!vf3_matrix_family(0x0c0b1808u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1808u; return 0; } return 1;
P_0c0b1828: /* original 60c3, guest PC 0x0c0b1828 */
if(!s->budget--) { s->failed_pc=0x0c0b1828u; return 0; }
r[0]=r[12];
goto P_0c0b182a;
P_0c0b182a: /* original d812, guest PC 0x0c0b182a */
if(!s->budget--) { s->failed_pc=0x0c0b182au; return 0; }
r[8]=read(ram,0x0c0b1874u,4);
goto P_0c0b182c;
P_0c0b182c: /* original 8802, guest PC 0x0c0b182c */
if(!s->budget--) { s->failed_pc=0x0c0b182cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0b182e;
P_0c0b182e: /* original 8907, guest PC 0x0c0b182e */
if(!s->budget--) { s->failed_pc=0x0c0b182eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1840; }
goto P_0c0b1830;
P_0c0b1830: /* original 8806, guest PC 0x0c0b1830 */
if(!s->budget--) { s->failed_pc=0x0c0b1830u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0b1832;
P_0c0b1832: /* original 8905, guest PC 0x0c0b1832 */
if(!s->budget--) { s->failed_pc=0x0c0b1832u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1840; }
goto P_0c0b1834;
P_0c0b1834: /* original 880a, guest PC 0x0c0b1834 */
if(!s->budget--) { s->failed_pc=0x0c0b1834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0b1836;
P_0c0b1836: /* original 890a, guest PC 0x0c0b1836 */
if(!s->budget--) { s->failed_pc=0x0c0b1836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b184e; }
goto P_0c0b1838;
P_0c0b1838: /* original 880f, guest PC 0x0c0b1838 */
if(!s->budget--) { s->failed_pc=0x0c0b1838u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0b183a;
P_0c0b183a: /* original 8908, guest PC 0x0c0b183a */
if(!s->budget--) { s->failed_pc=0x0c0b183au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b184e; }
goto P_0c0b183c;
P_0c0b183c: /* original a009, guest PC 0x0c0b183c */
if(!s->budget--) { s->failed_pc=0x0c0b183cu; return 0; }
goto P_0c0b1852;
P_0c0b183e: /* original 0009, guest PC 0x0c0b183e */
if(!s->budget--) { s->failed_pc=0x0c0b183eu; return 0; }
goto P_0c0b1840;
P_0c0b1840: /* original 480b, guest PC 0x0c0b1840 */
if(!s->budget--) { s->failed_pc=0x0c0b1840u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1844u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1844u) { target=s->pc; goto dispatch; }
goto P_0c0b1844;
P_0c0b1842: /* original 0009, guest PC 0x0c0b1842 */
if(!s->budget--) { s->failed_pc=0x0c0b1842u; return 0; }
goto P_0c0b1844;
P_0c0b1844: /* original d20c, guest PC 0x0c0b1844 */
if(!s->budget--) { s->failed_pc=0x0c0b1844u; return 0; }
r[2]=read(ram,0x0c0b1878u,4);
goto P_0c0b1846;
P_0c0b1846: /* original 420b, guest PC 0x0c0b1846 */
if(!s->budget--) { s->failed_pc=0x0c0b1846u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b184au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b184au) { target=s->pc; goto dispatch; }
goto P_0c0b184a;
P_0c0b1848: /* original 0009, guest PC 0x0c0b1848 */
if(!s->budget--) { s->failed_pc=0x0c0b1848u; return 0; }
goto P_0c0b184a;
P_0c0b184a: /* original a002, guest PC 0x0c0b184a */
if(!s->budget--) { s->failed_pc=0x0c0b184au; return 0; }
goto P_0c0b1852;
P_0c0b184c: /* original 0009, guest PC 0x0c0b184c */
if(!s->budget--) { s->failed_pc=0x0c0b184cu; return 0; }
goto P_0c0b184e;
P_0c0b184e: /* original 480b, guest PC 0x0c0b184e */
if(!s->budget--) { s->failed_pc=0x0c0b184eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1852u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1852u) { target=s->pc; goto dispatch; }
goto P_0c0b1852;
P_0c0b1850: /* original 0009, guest PC 0x0c0b1850 */
if(!s->budget--) { s->failed_pc=0x0c0b1850u; return 0; }
goto P_0c0b1852;
P_0c0b1852: /* original 2fc6, guest PC 0x0c0b1852 */
if(!s->budget--) { s->failed_pc=0x0c0b1852u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1854;
P_0c0b1854: /* original 65d3, guest PC 0x0c0b1854 */
if(!s->budget--) { s->failed_pc=0x0c0b1854u; return 0; }
r[5]=r[13];
goto P_0c0b1856;
P_0c0b1856: /* original 66f3, guest PC 0x0c0b1856 */
if(!s->budget--) { s->failed_pc=0x0c0b1856u; return 0; }
r[6]=r[15];
goto P_0c0b1858;
P_0c0b1858: /* original 760c, guest PC 0x0c0b1858 */
if(!s->budget--) { s->failed_pc=0x0c0b1858u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0b185a;
P_0c0b185a: /* original 6793, guest PC 0x0c0b185a */
if(!s->budget--) { s->failed_pc=0x0c0b185au; return 0; }
r[7]=r[9];
goto P_0c0b185c;
P_0c0b185c: /* original b0f3, guest PC 0x0c0b185c */
if(!s->budget--) { s->failed_pc=0x0c0b185cu; return 0; }
target=code_base|0x0c0b1a46u; r[16]=code_base|0x0c0b1860u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1860u) { target=s->pc; goto dispatch; }
goto P_0c0b1860;
P_0c0b185e: /* original 64e3, guest PC 0x0c0b185e */
if(!s->budget--) { s->failed_pc=0x0c0b185eu; return 0; }
r[4]=r[14];
goto P_0c0b1860;
P_0c0b1860: /* original 6d03, guest PC 0x0c0b1860 */
if(!s->budget--) { s->failed_pc=0x0c0b1860u; return 0; }
r[13]=r[0];
goto P_0c0b1862;
P_0c0b1862: /* original 60c3, guest PC 0x0c0b1862 */
if(!s->budget--) { s->failed_pc=0x0c0b1862u; return 0; }
r[0]=r[12];
goto P_0c0b1864;
P_0c0b1864: /* original 8800, guest PC 0x0c0b1864 */
if(!s->budget--) { s->failed_pc=0x0c0b1864u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0b1866;
P_0c0b1866: /* original 8d09, guest PC 0x0c0b1866 */
if(!s->budget--) { s->failed_pc=0x0c0b1866u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0b187c; }
goto P_0c0b186a;
P_0c0b1868: /* original 7f04, guest PC 0x0c0b1868 */
if(!s->budget--) { s->failed_pc=0x0c0b1868u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b186a;
P_0c0b186a: /* original 880b, guest PC 0x0c0b186a */
if(!s->budget--) { s->failed_pc=0x0c0b186au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0b186c;
P_0c0b186c: /* original 8906, guest PC 0x0c0b186c */
if(!s->budget--) { s->failed_pc=0x0c0b186cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b187c; }
goto P_0c0b186e;
P_0c0b186e: /* original a008, guest PC 0x0c0b186e */
if(!s->budget--) { s->failed_pc=0x0c0b186eu; return 0; }
goto P_0c0b1882;
P_0c0b1870: /* original 0009, guest PC 0x0c0b1870 */
if(!s->budget--) { s->failed_pc=0x0c0b1870u; return 0; }
if(!vf3_matrix_family(0x0c0b1872u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1872u; return 0; } return 1;
P_0c0b187c: /* original d22d, guest PC 0x0c0b187c */
if(!s->budget--) { s->failed_pc=0x0c0b187cu; return 0; }
r[2]=read(ram,0x0c0b1934u,4);
goto P_0c0b187e;
P_0c0b187e: /* original 420b, guest PC 0x0c0b187e */
if(!s->budget--) { s->failed_pc=0x0c0b187eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1882u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1882u) { target=s->pc; goto dispatch; }
goto P_0c0b1882;
P_0c0b1880: /* original 0009, guest PC 0x0c0b1880 */
if(!s->budget--) { s->failed_pc=0x0c0b1880u; return 0; }
goto P_0c0b1882;
P_0c0b1882: /* original 53f1, guest PC 0x0c0b1882 */
if(!s->budget--) { s->failed_pc=0x0c0b1882u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1884;
P_0c0b1884: /* original 2338, guest PC 0x0c0b1884 */
if(!s->budget--) { s->failed_pc=0x0c0b1884u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b1886;
P_0c0b1886: /* original 8902, guest PC 0x0c0b1886 */
if(!s->budget--) { s->failed_pc=0x0c0b1886u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b188e; }
goto P_0c0b1888;
P_0c0b1888: /* original 65c3, guest PC 0x0c0b1888 */
if(!s->budget--) { s->failed_pc=0x0c0b1888u; return 0; }
r[5]=r[12];
goto P_0c0b188a;
P_0c0b188a: /* original b150, guest PC 0x0c0b188a */
if(!s->budget--) { s->failed_pc=0x0c0b188au; return 0; }
target=code_base|0x0c0b1b2eu; r[16]=code_base|0x0c0b188eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b188eu) { target=s->pc; goto dispatch; }
goto P_0c0b188e;
P_0c0b188c: /* original 64e3, guest PC 0x0c0b188c */
if(!s->budget--) { s->failed_pc=0x0c0b188cu; return 0; }
r[4]=r[14];
goto P_0c0b188e;
P_0c0b188e: /* original 7c01, guest PC 0x0c0b188e */
if(!s->budget--) { s->failed_pc=0x0c0b188eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0b1890;
P_0c0b1890: /* original 7940, guest PC 0x0c0b1890 */
if(!s->budget--) { s->failed_pc=0x0c0b1890u; return 0; }
r[9]+=0x00000040u;
goto P_0c0b1892;
P_0c0b1892: /* original e312, guest PC 0x0c0b1892 */
if(!s->budget--) { s->failed_pc=0x0c0b1892u; return 0; }
r[3]=0x00000012u;
goto P_0c0b1894;
P_0c0b1894: /* original 3c33, guest PC 0x0c0b1894 */
if(!s->budget--) { s->failed_pc=0x0c0b1894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c0b1896;
P_0c0b1896: /* original 8b97, guest PC 0x0c0b1896 */
if(!s->budget--) { s->failed_pc=0x0c0b1896u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b17c8; }
goto P_0c0b1898;
P_0c0b1898: /* original d127, guest PC 0x0c0b1898 */
if(!s->budget--) { s->failed_pc=0x0c0b1898u; return 0; }
r[1]=read(ram,0x0c0b1938u,4);
goto P_0c0b189a;
P_0c0b189a: /* original 410b, guest PC 0x0c0b189a */
if(!s->budget--) { s->failed_pc=0x0c0b189au; return 0; }
target=r[1];
r[16]=code_base|0x0c0b189eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b189eu) { target=s->pc; goto dispatch; }
goto P_0c0b189e;
P_0c0b189c: /* original 0009, guest PC 0x0c0b189c */
if(!s->budget--) { s->failed_pc=0x0c0b189cu; return 0; }
goto P_0c0b189e;
P_0c0b189e: /* original 60b3, guest PC 0x0c0b189e */
if(!s->budget--) { s->failed_pc=0x0c0b189eu; return 0; }
r[0]=r[11];
goto P_0c0b18a0;
P_0c0b18a0: /* original 8805, guest PC 0x0c0b18a0 */
if(!s->budget--) { s->failed_pc=0x0c0b18a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b18a2;
P_0c0b18a2: /* original 8905, guest PC 0x0c0b18a2 */
if(!s->budget--) { s->failed_pc=0x0c0b18a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b18b0; }
goto P_0c0b18a4;
P_0c0b18a4: /* original 60b3, guest PC 0x0c0b18a4 */
if(!s->budget--) { s->failed_pc=0x0c0b18a4u; return 0; }
r[0]=r[11];
goto P_0c0b18a6;
P_0c0b18a6: /* original 8812, guest PC 0x0c0b18a6 */
if(!s->budget--) { s->failed_pc=0x0c0b18a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0b18a8;
P_0c0b18a8: /* original 8902, guest PC 0x0c0b18a8 */
if(!s->budget--) { s->failed_pc=0x0c0b18a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b18b0; }
goto P_0c0b18aa;
P_0c0b18aa: /* original 60b3, guest PC 0x0c0b18aa */
if(!s->budget--) { s->failed_pc=0x0c0b18aau; return 0; }
r[0]=r[11];
goto P_0c0b18ac;
P_0c0b18ac: /* original 8807, guest PC 0x0c0b18ac */
if(!s->budget--) { s->failed_pc=0x0c0b18acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0b18ae;
P_0c0b18ae: /* original 8b30, guest PC 0x0c0b18ae */
if(!s->budget--) { s->failed_pc=0x0c0b18aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1912; }
goto P_0c0b18b0;
P_0c0b18b0: /* original 60f2, guest PC 0x0c0b18b0 */
if(!s->budget--) { s->failed_pc=0x0c0b18b0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0b18b2;
P_0c0b18b2: /* original 6002, guest PC 0x0c0b18b2 */
if(!s->budget--) { s->failed_pc=0x0c0b18b2u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0b18b4;
P_0c0b18b4: /* original c801, guest PC 0x0c0b18b4 */
if(!s->budget--) { s->failed_pc=0x0c0b18b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0b18b6;
P_0c0b18b6: /* original 892c, guest PC 0x0c0b18b6 */
if(!s->budget--) { s->failed_pc=0x0c0b18b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1912; }
goto P_0c0b18b8;
P_0c0b18b8: /* original 903a, guest PC 0x0c0b18b8 */
if(!s->budget--) { s->failed_pc=0x0c0b18b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1930u,2);
goto P_0c0b18ba;
P_0c0b18ba: /* original 62f2, guest PC 0x0c0b18ba */
if(!s->budget--) { s->failed_pc=0x0c0b18bau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0b18bc;
P_0c0b18bc: /* original 032e, guest PC 0x0c0b18bc */
if(!s->budget--) { s->failed_pc=0x0c0b18bcu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0b18be;
P_0c0b18be: /* original 2338, guest PC 0x0c0b18be */
if(!s->budget--) { s->failed_pc=0x0c0b18beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0b18c0;
P_0c0b18c0: /* original 8902, guest PC 0x0c0b18c0 */
if(!s->budget--) { s->failed_pc=0x0c0b18c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b18c8; }
goto P_0c0b18c2;
P_0c0b18c2: /* original 52f7, guest PC 0x0c0b18c2 */
if(!s->budget--) { s->failed_pc=0x0c0b18c2u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0b18c4;
P_0c0b18c4: /* original 53a1, guest PC 0x0c0b18c4 */
if(!s->budget--) { s->failed_pc=0x0c0b18c4u; return 0; }
r[3]=read(ram,r[10]+4,4);
goto P_0c0b18c6;
P_0c0b18c6: /* original 1321, guest PC 0x0c0b18c6 */
if(!s->budget--) { s->failed_pc=0x0c0b18c6u; return 0; }
write(ram,r[3]+4,r[2],4);
goto P_0c0b18c8;
P_0c0b18c8: /* original 9032, guest PC 0x0c0b18c8 */
if(!s->budget--) { s->failed_pc=0x0c0b18c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1930u,2);
goto P_0c0b18ca;
P_0c0b18ca: /* original 53f5, guest PC 0x0c0b18ca */
if(!s->budget--) { s->failed_pc=0x0c0b18cau; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0b18cc;
P_0c0b18cc: /* original 023e, guest PC 0x0c0b18cc */
if(!s->budget--) { s->failed_pc=0x0c0b18ccu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b18ce;
P_0c0b18ce: /* original 2228, guest PC 0x0c0b18ce */
if(!s->budget--) { s->failed_pc=0x0c0b18ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b18d0;
P_0c0b18d0: /* original 8d03, guest PC 0x0c0b18d0 */
if(!s->budget--) { s->failed_pc=0x0c0b18d0u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[10]+44,4);
if(cond) { goto P_0c0b18da; }
goto P_0c0b18d4;
P_0c0b18d2: /* original 54ab, guest PC 0x0c0b18d2 */
if(!s->budget--) { s->failed_pc=0x0c0b18d2u; return 0; }
r[4]=read(ram,r[10]+44,4);
goto P_0c0b18d4;
P_0c0b18d4: /* original 53f8, guest PC 0x0c0b18d4 */
if(!s->budget--) { s->failed_pc=0x0c0b18d4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0b18d6;
P_0c0b18d6: /* original 5241, guest PC 0x0c0b18d6 */
if(!s->budget--) { s->failed_pc=0x0c0b18d6u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b18d8;
P_0c0b18d8: /* original 1231, guest PC 0x0c0b18d8 */
if(!s->budget--) { s->failed_pc=0x0c0b18d8u; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b18da;
P_0c0b18da: /* original 9029, guest PC 0x0c0b18da */
if(!s->budget--) { s->failed_pc=0x0c0b18dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1930u,2);
goto P_0c0b18dc;
P_0c0b18dc: /* original 53f3, guest PC 0x0c0b18dc */
if(!s->budget--) { s->failed_pc=0x0c0b18dcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0b18de;
P_0c0b18de: /* original 023e, guest PC 0x0c0b18de */
if(!s->budget--) { s->failed_pc=0x0c0b18deu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b18e0;
P_0c0b18e0: /* original 2228, guest PC 0x0c0b18e0 */
if(!s->budget--) { s->failed_pc=0x0c0b18e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b18e2;
P_0c0b18e2: /* original 8d03, guest PC 0x0c0b18e2 */
if(!s->budget--) { s->failed_pc=0x0c0b18e2u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[4]+44,4);
if(cond) { goto P_0c0b18ec; }
goto P_0c0b18e6;
P_0c0b18e4: /* original 544b, guest PC 0x0c0b18e4 */
if(!s->budget--) { s->failed_pc=0x0c0b18e4u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0b18e6;
P_0c0b18e6: /* original 53f9, guest PC 0x0c0b18e6 */
if(!s->budget--) { s->failed_pc=0x0c0b18e6u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0b18e8;
P_0c0b18e8: /* original 5241, guest PC 0x0c0b18e8 */
if(!s->budget--) { s->failed_pc=0x0c0b18e8u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b18ea;
P_0c0b18ea: /* original 1231, guest PC 0x0c0b18ea */
if(!s->budget--) { s->failed_pc=0x0c0b18eau; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b18ec;
P_0c0b18ec: /* original 9020, guest PC 0x0c0b18ec */
if(!s->budget--) { s->failed_pc=0x0c0b18ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1930u,2);
goto P_0c0b18ee;
P_0c0b18ee: /* original 53f6, guest PC 0x0c0b18ee */
if(!s->budget--) { s->failed_pc=0x0c0b18eeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0b18f0;
P_0c0b18f0: /* original 54ab, guest PC 0x0c0b18f0 */
if(!s->budget--) { s->failed_pc=0x0c0b18f0u; return 0; }
r[4]=read(ram,r[10]+44,4);
goto P_0c0b18f2;
P_0c0b18f2: /* original 023e, guest PC 0x0c0b18f2 */
if(!s->budget--) { s->failed_pc=0x0c0b18f2u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b18f4;
P_0c0b18f4: /* original 2228, guest PC 0x0c0b18f4 */
if(!s->budget--) { s->failed_pc=0x0c0b18f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b18f6;
P_0c0b18f6: /* original 8d03, guest PC 0x0c0b18f6 */
if(!s->budget--) { s->failed_pc=0x0c0b18f6u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[4]+48,4);
if(cond) { goto P_0c0b1900; }
goto P_0c0b18fa;
P_0c0b18f8: /* original 544c, guest PC 0x0c0b18f8 */
if(!s->budget--) { s->failed_pc=0x0c0b18f8u; return 0; }
r[4]=read(ram,r[4]+48,4);
goto P_0c0b18fa;
P_0c0b18fa: /* original 53fa, guest PC 0x0c0b18fa */
if(!s->budget--) { s->failed_pc=0x0c0b18fau; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c0b18fc;
P_0c0b18fc: /* original 5241, guest PC 0x0c0b18fc */
if(!s->budget--) { s->failed_pc=0x0c0b18fcu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b18fe;
P_0c0b18fe: /* original 1231, guest PC 0x0c0b18fe */
if(!s->budget--) { s->failed_pc=0x0c0b18feu; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b1900;
P_0c0b1900: /* original 9016, guest PC 0x0c0b1900 */
if(!s->budget--) { s->failed_pc=0x0c0b1900u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1930u,2);
goto P_0c0b1902;
P_0c0b1902: /* original 53f4, guest PC 0x0c0b1902 */
if(!s->budget--) { s->failed_pc=0x0c0b1902u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0b1904;
P_0c0b1904: /* original 023e, guest PC 0x0c0b1904 */
if(!s->budget--) { s->failed_pc=0x0c0b1904u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0b1906;
P_0c0b1906: /* original 2228, guest PC 0x0c0b1906 */
if(!s->budget--) { s->failed_pc=0x0c0b1906u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b1908;
P_0c0b1908: /* original 8d03, guest PC 0x0c0b1908 */
if(!s->budget--) { s->failed_pc=0x0c0b1908u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[4]+44,4);
if(cond) { goto P_0c0b1912; }
goto P_0c0b190c;
P_0c0b190a: /* original 544b, guest PC 0x0c0b190a */
if(!s->budget--) { s->failed_pc=0x0c0b190au; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0b190c;
P_0c0b190c: /* original 53fb, guest PC 0x0c0b190c */
if(!s->budget--) { s->failed_pc=0x0c0b190cu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0b190e;
P_0c0b190e: /* original 5241, guest PC 0x0c0b190e */
if(!s->budget--) { s->failed_pc=0x0c0b190eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0b1910;
P_0c0b1910: /* original 1231, guest PC 0x0c0b1910 */
if(!s->budget--) { s->failed_pc=0x0c0b1910u; return 0; }
write(ram,r[2]+4,r[3],4);
goto P_0c0b1912;
P_0c0b1912: /* original 52f1, guest PC 0x0c0b1912 */
if(!s->budget--) { s->failed_pc=0x0c0b1912u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0b1914;
P_0c0b1914: /* original 2228, guest PC 0x0c0b1914 */
if(!s->budget--) { s->failed_pc=0x0c0b1914u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b1916;
P_0c0b1916: /* original 8b01, guest PC 0x0c0b1916 */
if(!s->budget--) { s->failed_pc=0x0c0b1916u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b191c; }
goto P_0c0b1918;
P_0c0b1918: /* original a088, guest PC 0x0c0b1918 */
if(!s->budget--) { s->failed_pc=0x0c0b1918u; return 0; }
goto P_0c0b1a2c;
P_0c0b191a: /* original 0009, guest PC 0x0c0b191a */
if(!s->budget--) { s->failed_pc=0x0c0b191au; return 0; }
goto P_0c0b191c;
P_0c0b191c: /* original d107, guest PC 0x0c0b191c */
if(!s->budget--) { s->failed_pc=0x0c0b191cu; return 0; }
r[1]=read(ram,0x0c0b193cu,4);
goto P_0c0b191e;
P_0c0b191e: /* original 410b, guest PC 0x0c0b191e */
if(!s->budget--) { s->failed_pc=0x0c0b191eu; return 0; }
target=r[1];
r[16]=code_base|0x0c0b1922u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1922u) { target=s->pc; goto dispatch; }
goto P_0c0b1922;
P_0c0b1920: /* original 0009, guest PC 0x0c0b1920 */
if(!s->budget--) { s->failed_pc=0x0c0b1920u; return 0; }
goto P_0c0b1922;
P_0c0b1922: /* original 9c06, guest PC 0x0c0b1922 */
if(!s->budget--) { s->failed_pc=0x0c0b1922u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1932u,2);
goto P_0c0b1924;
P_0c0b1924: /* original 6be3, guest PC 0x0c0b1924 */
if(!s->budget--) { s->failed_pc=0x0c0b1924u; return 0; }
r[11]=r[14];
goto P_0c0b1926;
P_0c0b1926: /* original da06, guest PC 0x0c0b1926 */
if(!s->budget--) { s->failed_pc=0x0c0b1926u; return 0; }
r[10]=read(ram,0x0c0b1940u,4);
goto P_0c0b1928;
P_0c0b1928: /* original 7b6c, guest PC 0x0c0b1928 */
if(!s->budget--) { s->failed_pc=0x0c0b1928u; return 0; }
r[11]+=0x0000006cu;
goto P_0c0b192a;
P_0c0b192a: /* original 3cec, guest PC 0x0c0b192a */
if(!s->budget--) { s->failed_pc=0x0c0b192au; return 0; }
r[12]+=r[14];
goto P_0c0b192c;
P_0c0b192c: /* original a021, guest PC 0x0c0b192c */
if(!s->budget--) { s->failed_pc=0x0c0b192cu; return 0; }
r[13]=0x00000000u;
goto P_0c0b1972;
P_0c0b192e: /* original ed00, guest PC 0x0c0b192e */
if(!s->budget--) { s->failed_pc=0x0c0b192eu; return 0; }
r[13]=0x00000000u;
if(!vf3_matrix_family(0x0c0b1930u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1930u; return 0; } return 1;
P_0c0b1944: /* original 60d3, guest PC 0x0c0b1944 */
if(!s->budget--) { s->failed_pc=0x0c0b1944u; return 0; }
r[0]=r[13];
goto P_0c0b1946;
P_0c0b1946: /* original 8805, guest PC 0x0c0b1946 */
if(!s->budget--) { s->failed_pc=0x0c0b1946u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b1948;
P_0c0b1948: /* original 8910, guest PC 0x0c0b1948 */
if(!s->budget--) { s->failed_pc=0x0c0b1948u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b196c; }
goto P_0c0b194a;
P_0c0b194a: /* original 60d3, guest PC 0x0c0b194a */
if(!s->budget--) { s->failed_pc=0x0c0b194au; return 0; }
r[0]=r[13];
goto P_0c0b194c;
P_0c0b194c: /* original 8809, guest PC 0x0c0b194c */
if(!s->budget--) { s->failed_pc=0x0c0b194cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b194e;
P_0c0b194e: /* original 890d, guest PC 0x0c0b194e */
if(!s->budget--) { s->failed_pc=0x0c0b194eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b196c; }
goto P_0c0b1950;
P_0c0b1950: /* original 60d3, guest PC 0x0c0b1950 */
if(!s->budget--) { s->failed_pc=0x0c0b1950u; return 0; }
r[0]=r[13];
goto P_0c0b1952;
P_0c0b1952: /* original 880e, guest PC 0x0c0b1952 */
if(!s->budget--) { s->failed_pc=0x0c0b1952u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0b1954;
P_0c0b1954: /* original 890a, guest PC 0x0c0b1954 */
if(!s->budget--) { s->failed_pc=0x0c0b1954u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b196c; }
goto P_0c0b1956;
P_0c0b1956: /* original 60d3, guest PC 0x0c0b1956 */
if(!s->budget--) { s->failed_pc=0x0c0b1956u; return 0; }
r[0]=r[13];
goto P_0c0b1958;
P_0c0b1958: /* original 8811, guest PC 0x0c0b1958 */
if(!s->budget--) { s->failed_pc=0x0c0b1958u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c0b195a;
P_0c0b195a: /* original 8907, guest PC 0x0c0b195a */
if(!s->budget--) { s->failed_pc=0x0c0b195au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b196c; }
goto P_0c0b195c;
P_0c0b195c: /* original 60d3, guest PC 0x0c0b195c */
if(!s->budget--) { s->failed_pc=0x0c0b195cu; return 0; }
r[0]=r[13];
goto P_0c0b195e;
P_0c0b195e: /* original 8801, guest PC 0x0c0b195e */
if(!s->budget--) { s->failed_pc=0x0c0b195eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0b1960;
P_0c0b1960: /* original 8904, guest PC 0x0c0b1960 */
if(!s->budget--) { s->failed_pc=0x0c0b1960u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b196c; }
goto P_0c0b1962;
P_0c0b1962: /* original d31f, guest PC 0x0c0b1962 */
if(!s->budget--) { s->failed_pc=0x0c0b1962u; return 0; }
r[3]=read(ram,0x0c0b19e0u,4);
goto P_0c0b1964;
P_0c0b1964: /* original 430b, guest PC 0x0c0b1964 */
if(!s->budget--) { s->failed_pc=0x0c0b1964u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1968u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1968u) { target=s->pc; goto dispatch; }
goto P_0c0b1968;
P_0c0b1966: /* original 64c3, guest PC 0x0c0b1966 */
if(!s->budget--) { s->failed_pc=0x0c0b1966u; return 0; }
r[4]=r[12];
goto P_0c0b1968;
P_0c0b1968: /* original 4a0b, guest PC 0x0c0b1968 */
if(!s->budget--) { s->failed_pc=0x0c0b1968u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b196cu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b196cu) { target=s->pc; goto dispatch; }
goto P_0c0b196c;
P_0c0b196a: /* original 64b2, guest PC 0x0c0b196a */
if(!s->budget--) { s->failed_pc=0x0c0b196au; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0b196c;
P_0c0b196c: /* original 7d01, guest PC 0x0c0b196c */
if(!s->budget--) { s->failed_pc=0x0c0b196cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b196e;
P_0c0b196e: /* original 7b04, guest PC 0x0c0b196e */
if(!s->budget--) { s->failed_pc=0x0c0b196eu; return 0; }
r[11]+=0x00000004u;
goto P_0c0b1970;
P_0c0b1970: /* original 7c40, guest PC 0x0c0b1970 */
if(!s->budget--) { s->failed_pc=0x0c0b1970u; return 0; }
r[12]+=0x00000040u;
goto P_0c0b1972;
P_0c0b1972: /* original e212, guest PC 0x0c0b1972 */
if(!s->budget--) { s->failed_pc=0x0c0b1972u; return 0; }
r[2]=0x00000012u;
goto P_0c0b1974;
P_0c0b1974: /* original 3d23, guest PC 0x0c0b1974 */
if(!s->budget--) { s->failed_pc=0x0c0b1974u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c0b1976;
P_0c0b1976: /* original 8be5, guest PC 0x0c0b1976 */
if(!s->budget--) { s->failed_pc=0x0c0b1976u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1944; }
goto P_0c0b1978;
P_0c0b1978: /* original d11a, guest PC 0x0c0b1978 */
if(!s->budget--) { s->failed_pc=0x0c0b1978u; return 0; }
r[1]=read(ram,0x0c0b19e4u,4);
goto P_0c0b197a;
P_0c0b197a: /* original 410b, guest PC 0x0c0b197a */
if(!s->budget--) { s->failed_pc=0x0c0b197au; return 0; }
target=r[1];
r[16]=code_base|0x0c0b197eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b197eu) { target=s->pc; goto dispatch; }
goto P_0c0b197e;
P_0c0b197c: /* original 0009, guest PC 0x0c0b197c */
if(!s->budget--) { s->failed_pc=0x0c0b197cu; return 0; }
goto P_0c0b197e;
P_0c0b197e: /* original d31a, guest PC 0x0c0b197e */
if(!s->budget--) { s->failed_pc=0x0c0b197eu; return 0; }
r[3]=read(ram,0x0c0b19e8u,4);
goto P_0c0b1980;
P_0c0b1980: /* original 430b, guest PC 0x0c0b1980 */
if(!s->budget--) { s->failed_pc=0x0c0b1980u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1984u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1984u) { target=s->pc; goto dispatch; }
goto P_0c0b1984;
P_0c0b1982: /* original 64e3, guest PC 0x0c0b1982 */
if(!s->budget--) { s->failed_pc=0x0c0b1982u; return 0; }
r[4]=r[14];
goto P_0c0b1984;
P_0c0b1984: /* original d119, guest PC 0x0c0b1984 */
if(!s->budget--) { s->failed_pc=0x0c0b1984u; return 0; }
r[1]=read(ram,0x0c0b19ecu,4);
goto P_0c0b1986;
P_0c0b1986: /* original 9328, guest PC 0x0c0b1986 */
if(!s->budget--) { s->failed_pc=0x0c0b1986u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b19dau,2);
goto P_0c0b1988;
P_0c0b1988: /* original 6212, guest PC 0x0c0b1988 */
if(!s->budget--) { s->failed_pc=0x0c0b1988u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0b198a;
P_0c0b198a: /* original 2238, guest PC 0x0c0b198a */
if(!s->budget--) { s->failed_pc=0x0c0b198au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0b198c;
P_0c0b198c: /* original 8b4e, guest PC 0x0c0b198c */
if(!s->budget--) { s->failed_pc=0x0c0b198cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1a2c; }
goto P_0c0b198e;
P_0c0b198e: /* original d318, guest PC 0x0c0b198e */
if(!s->budget--) { s->failed_pc=0x0c0b198eu; return 0; }
r[3]=read(ram,0x0c0b19f0u,4);
goto P_0c0b1990;
P_0c0b1990: /* original 430b, guest PC 0x0c0b1990 */
if(!s->budget--) { s->failed_pc=0x0c0b1990u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1994u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1994u) { target=s->pc; goto dispatch; }
goto P_0c0b1994;
P_0c0b1992: /* original 0009, guest PC 0x0c0b1992 */
if(!s->budget--) { s->failed_pc=0x0c0b1992u; return 0; }
goto P_0c0b1994;
P_0c0b1994: /* original 50f1, guest PC 0x0c0b1994 */
if(!s->budget--) { s->failed_pc=0x0c0b1994u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0b1996;
P_0c0b1996: /* original 2008, guest PC 0x0c0b1996 */
if(!s->budget--) { s->failed_pc=0x0c0b1996u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b1998;
P_0c0b1998: /* original 8945, guest PC 0x0c0b1998 */
if(!s->budget--) { s->failed_pc=0x0c0b1998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a26; }
goto P_0c0b199a;
P_0c0b199a: /* original 50fd, guest PC 0x0c0b199a */
if(!s->budget--) { s->failed_pc=0x0c0b199au; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c0b199c;
P_0c0b199c: /* original 2008, guest PC 0x0c0b199c */
if(!s->budget--) { s->failed_pc=0x0c0b199cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b199e;
P_0c0b199e: /* original 8b42, guest PC 0x0c0b199e */
if(!s->budget--) { s->failed_pc=0x0c0b199eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1a26; }
goto P_0c0b19a0;
P_0c0b19a0: /* original 50fc, guest PC 0x0c0b19a0 */
if(!s->budget--) { s->failed_pc=0x0c0b19a0u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c0b19a2;
P_0c0b19a2: /* original 2008, guest PC 0x0c0b19a2 */
if(!s->budget--) { s->failed_pc=0x0c0b19a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b19a4;
P_0c0b19a4: /* original 893f, guest PC 0x0c0b19a4 */
if(!s->budget--) { s->failed_pc=0x0c0b19a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a26; }
goto P_0c0b19a6;
P_0c0b19a6: /* original 9b19, guest PC 0x0c0b19a6 */
if(!s->budget--) { s->failed_pc=0x0c0b19a6u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b19dcu,2);
goto P_0c0b19a8;
P_0c0b19a8: /* original 9219, guest PC 0x0c0b19a8 */
if(!s->budget--) { s->failed_pc=0x0c0b19a8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b19deu,2);
goto P_0c0b19aa;
P_0c0b19aa: /* original 3bec, guest PC 0x0c0b19aa */
if(!s->budget--) { s->failed_pc=0x0c0b19aau; return 0; }
r[11]+=r[14];
goto P_0c0b19ac;
P_0c0b19ac: /* original 3e2c, guest PC 0x0c0b19ac */
if(!s->budget--) { s->failed_pc=0x0c0b19acu; return 0; }
r[14]+=r[2];
goto P_0c0b19ae;
P_0c0b19ae: /* original a037, guest PC 0x0c0b19ae */
if(!s->budget--) { s->failed_pc=0x0c0b19aeu; return 0; }
r[13]=0x00000000u;
goto P_0c0b1a20;
P_0c0b19b0: /* original ed00, guest PC 0x0c0b19b0 */
if(!s->budget--) { s->failed_pc=0x0c0b19b0u; return 0; }
r[13]=0x00000000u;
goto P_0c0b19b2;
P_0c0b19b2: /* original 60d3, guest PC 0x0c0b19b2 */
if(!s->budget--) { s->failed_pc=0x0c0b19b2u; return 0; }
r[0]=r[13];
goto P_0c0b19b4;
P_0c0b19b4: /* original 8802, guest PC 0x0c0b19b4 */
if(!s->budget--) { s->failed_pc=0x0c0b19b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0b19b6;
P_0c0b19b6: /* original 8d1d, guest PC 0x0c0b19b6 */
if(!s->budget--) { s->failed_pc=0x0c0b19b6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[11],4);
r[11]+=4;
r[12]=tmp;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19ba;
P_0c0b19b8: /* original 6cb6, guest PC 0x0c0b19b8 */
if(!s->budget--) { s->failed_pc=0x0c0b19b8u; return 0; }
tmp=read(ram,r[11],4);
r[11]+=4;
r[12]=tmp;
goto P_0c0b19ba;
P_0c0b19ba: /* original 8803, guest PC 0x0c0b19ba */
if(!s->budget--) { s->failed_pc=0x0c0b19bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0b19bc;
P_0c0b19bc: /* original 891a, guest PC 0x0c0b19bc */
if(!s->budget--) { s->failed_pc=0x0c0b19bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19be;
P_0c0b19be: /* original 8805, guest PC 0x0c0b19be */
if(!s->budget--) { s->failed_pc=0x0c0b19beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b19c0;
P_0c0b19c0: /* original 8918, guest PC 0x0c0b19c0 */
if(!s->budget--) { s->failed_pc=0x0c0b19c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19c2;
P_0c0b19c2: /* original 8806, guest PC 0x0c0b19c2 */
if(!s->budget--) { s->failed_pc=0x0c0b19c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0b19c4;
P_0c0b19c4: /* original 8916, guest PC 0x0c0b19c4 */
if(!s->budget--) { s->failed_pc=0x0c0b19c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19c6;
P_0c0b19c6: /* original 8809, guest PC 0x0c0b19c6 */
if(!s->budget--) { s->failed_pc=0x0c0b19c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b19c8;
P_0c0b19c8: /* original 8914, guest PC 0x0c0b19c8 */
if(!s->budget--) { s->failed_pc=0x0c0b19c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19ca;
P_0c0b19ca: /* original 880a, guest PC 0x0c0b19ca */
if(!s->budget--) { s->failed_pc=0x0c0b19cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0b19cc;
P_0c0b19cc: /* original 8912, guest PC 0x0c0b19cc */
if(!s->budget--) { s->failed_pc=0x0c0b19ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19ce;
P_0c0b19ce: /* original 880c, guest PC 0x0c0b19ce */
if(!s->budget--) { s->failed_pc=0x0c0b19ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0b19d0;
P_0c0b19d0: /* original 8910, guest PC 0x0c0b19d0 */
if(!s->budget--) { s->failed_pc=0x0c0b19d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19d2;
P_0c0b19d2: /* original 880d, guest PC 0x0c0b19d2 */
if(!s->budget--) { s->failed_pc=0x0c0b19d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0b19d4;
P_0c0b19d4: /* original 890e, guest PC 0x0c0b19d4 */
if(!s->budget--) { s->failed_pc=0x0c0b19d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b19f4; }
goto P_0c0b19d6;
P_0c0b19d6: /* original a018, guest PC 0x0c0b19d6 */
if(!s->budget--) { s->failed_pc=0x0c0b19d6u; return 0; }
goto P_0c0b1a0a;
P_0c0b19d8: /* original 0009, guest PC 0x0c0b19d8 */
if(!s->budget--) { s->failed_pc=0x0c0b19d8u; return 0; }
if(!vf3_matrix_family(0x0c0b19dau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b19dau; return 0; } return 1;
P_0c0b19f4: /* original 65e3, guest PC 0x0c0b19f4 */
if(!s->budget--) { s->failed_pc=0x0c0b19f4u; return 0; }
r[5]=r[14];
goto P_0c0b19f6;
P_0c0b19f6: /* original e034, guest PC 0x0c0b19f6 */
if(!s->budget--) { s->failed_pc=0x0c0b19f6u; return 0; }
r[0]=0x00000034u;
goto P_0c0b19f8;
P_0c0b19f8: /* original 7e40, guest PC 0x0c0b19f8 */
if(!s->budget--) { s->failed_pc=0x0c0b19f8u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b19fa;
P_0c0b19fa: /* original f556, guest PC 0x0c0b19fa */
if(!s->budget--) { s->failed_pc=0x0c0b19fau; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0b19fc;
P_0c0b19fc: /* original f4e6, guest PC 0x0c0b19fc */
if(!s->budget--) { s->failed_pc=0x0c0b19fcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0b19fe;
P_0c0b19fe: /* original f455, guest PC 0x0c0b19fe */
if(!s->budget--) { s->failed_pc=0x0c0b19feu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0b1a00;
P_0c0b1a00: /* original 8b00, guest PC 0x0c0b1a00 */
if(!s->budget--) { s->failed_pc=0x0c0b1a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1a04; }
goto P_0c0b1a02;
P_0c0b1a02: /* original f547, guest PC 0x0c0b1a02 */
if(!s->budget--) { s->failed_pc=0x0c0b1a02u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c0b1a04;
P_0c0b1a04: /* original da29, guest PC 0x0c0b1a04 */
if(!s->budget--) { s->failed_pc=0x0c0b1a04u; return 0; }
r[10]=read(ram,0x0c0b1aacu,4);
goto P_0c0b1a06;
P_0c0b1a06: /* original 4a0b, guest PC 0x0c0b1a06 */
if(!s->budget--) { s->failed_pc=0x0c0b1a06u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b1a0au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a0au) { target=s->pc; goto dispatch; }
goto P_0c0b1a0a;
P_0c0b1a08: /* original 64e3, guest PC 0x0c0b1a08 */
if(!s->budget--) { s->failed_pc=0x0c0b1a08u; return 0; }
r[4]=r[14];
goto P_0c0b1a0a;
P_0c0b1a0a: /* original 60c3, guest PC 0x0c0b1a0a */
if(!s->budget--) { s->failed_pc=0x0c0b1a0au; return 0; }
r[0]=r[12];
goto P_0c0b1a0c;
P_0c0b1a0c: /* original 88ff, guest PC 0x0c0b1a0c */
if(!s->budget--) { s->failed_pc=0x0c0b1a0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0b1a0e;
P_0c0b1a0e: /* original 8905, guest PC 0x0c0b1a0e */
if(!s->budget--) { s->failed_pc=0x0c0b1a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a1c; }
goto P_0c0b1a10;
P_0c0b1a10: /* original d227, guest PC 0x0c0b1a10 */
if(!s->budget--) { s->failed_pc=0x0c0b1a10u; return 0; }
r[2]=read(ram,0x0c0b1ab0u,4);
goto P_0c0b1a12;
P_0c0b1a12: /* original 420b, guest PC 0x0c0b1a12 */
if(!s->budget--) { s->failed_pc=0x0c0b1a12u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1a16u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a16u) { target=s->pc; goto dispatch; }
goto P_0c0b1a16;
P_0c0b1a14: /* original 64e3, guest PC 0x0c0b1a14 */
if(!s->budget--) { s->failed_pc=0x0c0b1a14u; return 0; }
r[4]=r[14];
goto P_0c0b1a16;
P_0c0b1a16: /* original da27, guest PC 0x0c0b1a16 */
if(!s->budget--) { s->failed_pc=0x0c0b1a16u; return 0; }
r[10]=read(ram,0x0c0b1ab4u,4);
goto P_0c0b1a18;
P_0c0b1a18: /* original 4a0b, guest PC 0x0c0b1a18 */
if(!s->budget--) { s->failed_pc=0x0c0b1a18u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b1a1cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a1cu) { target=s->pc; goto dispatch; }
goto P_0c0b1a1c;
P_0c0b1a1a: /* original 64c3, guest PC 0x0c0b1a1a */
if(!s->budget--) { s->failed_pc=0x0c0b1a1au; return 0; }
r[4]=r[12];
goto P_0c0b1a1c;
P_0c0b1a1c: /* original 7d01, guest PC 0x0c0b1a1c */
if(!s->budget--) { s->failed_pc=0x0c0b1a1cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1a1e;
P_0c0b1a1e: /* original 7e40, guest PC 0x0c0b1a1e */
if(!s->budget--) { s->failed_pc=0x0c0b1a1eu; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1a20;
P_0c0b1a20: /* original e40f, guest PC 0x0c0b1a20 */
if(!s->budget--) { s->failed_pc=0x0c0b1a20u; return 0; }
r[4]=0x0000000fu;
goto P_0c0b1a22;
P_0c0b1a22: /* original 3d43, guest PC 0x0c0b1a22 */
if(!s->budget--) { s->failed_pc=0x0c0b1a22u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[4])!=0);
goto P_0c0b1a24;
P_0c0b1a24: /* original 8bc5, guest PC 0x0c0b1a24 */
if(!s->budget--) { s->failed_pc=0x0c0b1a24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b19b2; }
goto P_0c0b1a26;
P_0c0b1a26: /* original d224, guest PC 0x0c0b1a26 */
if(!s->budget--) { s->failed_pc=0x0c0b1a26u; return 0; }
r[2]=read(ram,0x0c0b1ab8u,4);
goto P_0c0b1a28;
P_0c0b1a28: /* original 420b, guest PC 0x0c0b1a28 */
if(!s->budget--) { s->failed_pc=0x0c0b1a28u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1a2cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a2cu) { target=s->pc; goto dispatch; }
goto P_0c0b1a2c;
P_0c0b1a2a: /* original 0009, guest PC 0x0c0b1a2a */
if(!s->budget--) { s->failed_pc=0x0c0b1a2au; return 0; }
goto P_0c0b1a2c;
P_0c0b1a2c: /* original d322, guest PC 0x0c0b1a2c */
if(!s->budget--) { s->failed_pc=0x0c0b1a2cu; return 0; }
r[3]=read(ram,0x0c0b1ab8u,4);
goto P_0c0b1a2e;
P_0c0b1a2e: /* original 430b, guest PC 0x0c0b1a2e */
if(!s->budget--) { s->failed_pc=0x0c0b1a2eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1a32u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a32u) { target=s->pc; goto dispatch; }
goto P_0c0b1a32;
P_0c0b1a30: /* original 0009, guest PC 0x0c0b1a30 */
if(!s->budget--) { s->failed_pc=0x0c0b1a30u; return 0; }
goto P_0c0b1a32;
P_0c0b1a32: /* original 7f38, guest PC 0x0c0b1a32 */
if(!s->budget--) { s->failed_pc=0x0c0b1a32u; return 0; }
r[15]+=0x00000038u;
goto P_0c0b1a34;
P_0c0b1a34: /* original 4f26, guest PC 0x0c0b1a34 */
if(!s->budget--) { s->failed_pc=0x0c0b1a34u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1a36;
P_0c0b1a36: /* original 68f6, guest PC 0x0c0b1a36 */
if(!s->budget--) { s->failed_pc=0x0c0b1a36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b1a38;
P_0c0b1a38: /* original 69f6, guest PC 0x0c0b1a38 */
if(!s->budget--) { s->failed_pc=0x0c0b1a38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b1a3a;
P_0c0b1a3a: /* original 6af6, guest PC 0x0c0b1a3a */
if(!s->budget--) { s->failed_pc=0x0c0b1a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b1a3c;
P_0c0b1a3c: /* original 6bf6, guest PC 0x0c0b1a3c */
if(!s->budget--) { s->failed_pc=0x0c0b1a3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b1a3e;
P_0c0b1a3e: /* original 6cf6, guest PC 0x0c0b1a3e */
if(!s->budget--) { s->failed_pc=0x0c0b1a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1a40;
P_0c0b1a40: /* original 6df6, guest PC 0x0c0b1a40 */
if(!s->budget--) { s->failed_pc=0x0c0b1a40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1a42;
P_0c0b1a42: /* original 000b, guest PC 0x0c0b1a42 */
if(!s->budget--) { s->failed_pc=0x0c0b1a42u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1a44: /* original 6ef6, guest PC 0x0c0b1a44 */
if(!s->budget--) { s->failed_pc=0x0c0b1a44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b1a46u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
