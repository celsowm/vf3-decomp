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
int vf3_away_batch160_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b398u: goto P_0c07b398;
case 0x0c07b39au: goto P_0c07b39a;
case 0x0c07b39cu: goto P_0c07b39c;
case 0x0c07b39eu: goto P_0c07b39e;
case 0x0c07b3a0u: goto P_0c07b3a0;
case 0x0c07b3a2u: goto P_0c07b3a2;
case 0x0c07b3a4u: goto P_0c07b3a4;
case 0x0c07b3a6u: goto P_0c07b3a6;
case 0x0c07b3a8u: goto P_0c07b3a8;
case 0x0c07b3aau: goto P_0c07b3aa;
case 0x0c07b3acu: goto P_0c07b3ac;
case 0x0c07b3aeu: goto P_0c07b3ae;
case 0x0c07b3b0u: goto P_0c07b3b0;
case 0x0c07b3b2u: goto P_0c07b3b2;
case 0x0c07b3b4u: goto P_0c07b3b4;
case 0x0c07b3b6u: goto P_0c07b3b6;
case 0x0c07b3b8u: goto P_0c07b3b8;
case 0x0c07b3bau: goto P_0c07b3ba;
case 0x0c07b3bcu: goto P_0c07b3bc;
case 0x0c07b3beu: goto P_0c07b3be;
case 0x0c07b3c0u: goto P_0c07b3c0;
case 0x0c07b3c2u: goto P_0c07b3c2;
case 0x0c07b3c4u: goto P_0c07b3c4;
case 0x0c07b3c6u: goto P_0c07b3c6;
case 0x0c07b3c8u: goto P_0c07b3c8;
case 0x0c07b3cau: goto P_0c07b3ca;
case 0x0c07b3ccu: goto P_0c07b3cc;
case 0x0c07b3ceu: goto P_0c07b3ce;
case 0x0c07b3d0u: goto P_0c07b3d0;
case 0x0c07b4d4u: goto P_0c07b4d4;
case 0x0c07b4d6u: goto P_0c07b4d6;
case 0x0c07b4d8u: goto P_0c07b4d8;
case 0x0c07b4dau: goto P_0c07b4da;
case 0x0c07b4dcu: goto P_0c07b4dc;
case 0x0c07b4deu: goto P_0c07b4de;
case 0x0c07b4e0u: goto P_0c07b4e0;
case 0x0c07b4e2u: goto P_0c07b4e2;
case 0x0c07b4e4u: goto P_0c07b4e4;
case 0x0c07b4e6u: goto P_0c07b4e6;
case 0x0c07b4e8u: goto P_0c07b4e8;
case 0x0c07b4eau: goto P_0c07b4ea;
case 0x0c07b4ecu: goto P_0c07b4ec;
case 0x0c07b4eeu: goto P_0c07b4ee;
case 0x0c07b4f0u: goto P_0c07b4f0;
case 0x0c07b4f2u: goto P_0c07b4f2;
case 0x0c07b4f4u: goto P_0c07b4f4;
case 0x0c07b4f6u: goto P_0c07b4f6;
case 0x0c07b4f8u: goto P_0c07b4f8;
case 0x0c07b4fau: goto P_0c07b4fa;
case 0x0c07b4fcu: goto P_0c07b4fc;
case 0x0c07b4feu: goto P_0c07b4fe;
case 0x0c07b500u: goto P_0c07b500;
case 0x0c07b502u: goto P_0c07b502;
case 0x0c07b504u: goto P_0c07b504;
case 0x0c07b506u: goto P_0c07b506;
case 0x0c07b508u: goto P_0c07b508;
case 0x0c07b50au: goto P_0c07b50a;
case 0x0c07b50cu: goto P_0c07b50c;
case 0x0c07b50eu: goto P_0c07b50e;
case 0x0c07b510u: goto P_0c07b510;
case 0x0c07b512u: goto P_0c07b512;
case 0x0c07b514u: goto P_0c07b514;
case 0x0c07b516u: goto P_0c07b516;
case 0x0c07b518u: goto P_0c07b518;
case 0x0c07b51au: goto P_0c07b51a;
case 0x0c07b51cu: goto P_0c07b51c;
case 0x0c07b51eu: goto P_0c07b51e;
case 0x0c07b520u: goto P_0c07b520;
case 0x0c07b522u: goto P_0c07b522;
case 0x0c07b524u: goto P_0c07b524;
case 0x0c07b526u: goto P_0c07b526;
case 0x0c07b528u: goto P_0c07b528;
case 0x0c07b52au: goto P_0c07b52a;
case 0x0c07b52cu: goto P_0c07b52c;
case 0x0c07b52eu: goto P_0c07b52e;
case 0x0c07b530u: goto P_0c07b530;
case 0x0c07b532u: goto P_0c07b532;
case 0x0c07b534u: goto P_0c07b534;
case 0x0c07b536u: goto P_0c07b536;
case 0x0c07b538u: goto P_0c07b538;
case 0x0c07b53au: goto P_0c07b53a;
case 0x0c07b53cu: goto P_0c07b53c;
case 0x0c07b53eu: goto P_0c07b53e;
case 0x0c07b540u: goto P_0c07b540;
case 0x0c07b542u: goto P_0c07b542;
case 0x0c07b544u: goto P_0c07b544;
case 0x0c07b546u: goto P_0c07b546;
case 0x0c07b548u: goto P_0c07b548;
case 0x0c07b54au: goto P_0c07b54a;
case 0x0c07b54cu: goto P_0c07b54c;
case 0x0c07b54eu: goto P_0c07b54e;
case 0x0c07b550u: goto P_0c07b550;
case 0x0c07b552u: goto P_0c07b552;
case 0x0c07b554u: goto P_0c07b554;
case 0x0c07b556u: goto P_0c07b556;
case 0x0c07b558u: goto P_0c07b558;
case 0x0c07b55au: goto P_0c07b55a;
case 0x0c07b55cu: goto P_0c07b55c;
case 0x0c07b55eu: goto P_0c07b55e;
case 0x0c07b560u: goto P_0c07b560;
case 0x0c07b562u: goto P_0c07b562;
case 0x0c07b564u: goto P_0c07b564;
case 0x0c07b566u: goto P_0c07b566;
case 0x0c07b568u: goto P_0c07b568;
case 0x0c07b56au: goto P_0c07b56a;
case 0x0c07b56cu: goto P_0c07b56c;
case 0x0c07b56eu: goto P_0c07b56e;
case 0x0c07b570u: goto P_0c07b570;
case 0x0c07b572u: goto P_0c07b572;
case 0x0c07b574u: goto P_0c07b574;
case 0x0c07b576u: goto P_0c07b576;
case 0x0c07b578u: goto P_0c07b578;
case 0x0c07b57au: goto P_0c07b57a;
case 0x0c07b57cu: goto P_0c07b57c;
case 0x0c07b57eu: goto P_0c07b57e;
case 0x0c07b580u: goto P_0c07b580;
case 0x0c07b582u: goto P_0c07b582;
case 0x0c07b584u: goto P_0c07b584;
case 0x0c07b586u: goto P_0c07b586;
case 0x0c07b588u: goto P_0c07b588;
case 0x0c07b58au: goto P_0c07b58a;
case 0x0c07b58cu: goto P_0c07b58c;
case 0x0c07b58eu: goto P_0c07b58e;
case 0x0c07b590u: goto P_0c07b590;
case 0x0c07b592u: goto P_0c07b592;
case 0x0c07b594u: goto P_0c07b594;
case 0x0c07b596u: goto P_0c07b596;
case 0x0c07b598u: goto P_0c07b598;
case 0x0c07b59au: goto P_0c07b59a;
case 0x0c07b59cu: goto P_0c07b59c;
case 0x0c07b59eu: goto P_0c07b59e;
case 0x0c07b5a0u: goto P_0c07b5a0;
case 0x0c07b5a2u: goto P_0c07b5a2;
case 0x0c07b5a4u: goto P_0c07b5a4;
case 0x0c07b5a6u: goto P_0c07b5a6;
case 0x0c07b5a8u: goto P_0c07b5a8;
case 0x0c07b5aau: goto P_0c07b5aa;
case 0x0c07b5acu: goto P_0c07b5ac;
case 0x0c07b5aeu: goto P_0c07b5ae;
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
P_0c07b398: /* original c748, guest PC 0x0c07b398 */
if(!s->budget--) { s->failed_pc=0x0c07b398u; return 0; }
r[0]=code_base|0x0007b4bcu;
goto P_0c07b39a;
P_0c07b39a: /* original f24c, guest PC 0x0c07b39a */
if(!s->budget--) { s->failed_pc=0x0c07b39au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b39c;
P_0c07b39c: /* original f308, guest PC 0x0c07b39c */
if(!s->budget--) { s->failed_pc=0x0c07b39cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b39e;
P_0c07b39e: /* original e018, guest PC 0x0c07b39e */
if(!s->budget--) { s->failed_pc=0x0c07b39eu; return 0; }
r[0]=0x00000018u;
goto P_0c07b3a0;
P_0c07b3a0: /* original f460, guest PC 0x0c07b3a0 */
if(!s->budget--) { s->failed_pc=0x0c07b3a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07b3a2;
P_0c07b3a2: /* original f230, guest PC 0x0c07b3a2 */
if(!s->budget--) { s->failed_pc=0x0c07b3a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c07b3a4;
P_0c07b3a4: /* original f282, guest PC 0x0c07b3a4 */
if(!s->budget--) { s->failed_pc=0x0c07b3a4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c07b3a6;
P_0c07b3a6: /* original f427, guest PC 0x0c07b3a6 */
if(!s->budget--) { s->failed_pc=0x0c07b3a6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07b3a8;
P_0c07b3a8: /* original c745, guest PC 0x0c07b3a8 */
if(!s->budget--) { s->failed_pc=0x0c07b3a8u; return 0; }
r[0]=code_base|0x0007b4c0u;
goto P_0c07b3aa;
P_0c07b3aa: /* original f208, guest PC 0x0c07b3aa */
if(!s->budget--) { s->failed_pc=0x0c07b3aau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b3ac;
P_0c07b3ac: /* original e01c, guest PC 0x0c07b3ac */
if(!s->budget--) { s->failed_pc=0x0c07b3acu; return 0; }
r[0]=0x0000001cu;
goto P_0c07b3ae;
P_0c07b3ae: /* original f15c, guest PC 0x0c07b3ae */
if(!s->budget--) { s->failed_pc=0x0c07b3aeu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c07b3b0;
P_0c07b3b0: /* original f570, guest PC 0x0c07b3b0 */
if(!s->budget--) { s->failed_pc=0x0c07b3b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c07b3b2;
P_0c07b3b2: /* original f120, guest PC 0x0c07b3b2 */
if(!s->budget--) { s->failed_pc=0x0c07b3b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c07b3b4;
P_0c07b3b4: /* original f192, guest PC 0x0c07b3b4 */
if(!s->budget--) { s->failed_pc=0x0c07b3b4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07b3b6;
P_0c07b3b6: /* original f417, guest PC 0x0c07b3b6 */
if(!s->budget--) { s->failed_pc=0x0c07b3b6u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c07b3b8;
P_0c07b3b8: /* original c742, guest PC 0x0c07b3b8 */
if(!s->budget--) { s->failed_pc=0x0c07b3b8u; return 0; }
r[0]=code_base|0x0007b4c4u;
goto P_0c07b3ba;
P_0c07b3ba: /* original f108, guest PC 0x0c07b3ba */
if(!s->budget--) { s->failed_pc=0x0c07b3bau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c07b3bc;
P_0c07b3bc: /* original e020, guest PC 0x0c07b3bc */
if(!s->budget--) { s->failed_pc=0x0c07b3bcu; return 0; }
r[0]=0x00000020u;
goto P_0c07b3be;
P_0c07b3be: /* original f410, guest PC 0x0c07b3be */
if(!s->budget--) { s->failed_pc=0x0c07b3beu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'+');
goto P_0c07b3c0;
P_0c07b3c0: /* original f482, guest PC 0x0c07b3c0 */
if(!s->budget--) { s->failed_pc=0x0c07b3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c07b3c2;
P_0c07b3c2: /* original f447, guest PC 0x0c07b3c2 */
if(!s->budget--) { s->failed_pc=0x0c07b3c2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c07b3c4;
P_0c07b3c4: /* original c740, guest PC 0x0c07b3c4 */
if(!s->budget--) { s->failed_pc=0x0c07b3c4u; return 0; }
r[0]=code_base|0x0007b4c8u;
goto P_0c07b3c6;
P_0c07b3c6: /* original f308, guest PC 0x0c07b3c6 */
if(!s->budget--) { s->failed_pc=0x0c07b3c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07b3c8;
P_0c07b3c8: /* original e024, guest PC 0x0c07b3c8 */
if(!s->budget--) { s->failed_pc=0x0c07b3c8u; return 0; }
r[0]=0x00000024u;
goto P_0c07b3ca;
P_0c07b3ca: /* original f530, guest PC 0x0c07b3ca */
if(!s->budget--) { s->failed_pc=0x0c07b3cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c07b3cc;
P_0c07b3cc: /* original f592, guest PC 0x0c07b3cc */
if(!s->budget--) { s->failed_pc=0x0c07b3ccu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[9],r[18],'*');
goto P_0c07b3ce;
P_0c07b3ce: /* original 000b, guest PC 0x0c07b3ce */
if(!s->budget--) { s->failed_pc=0x0c07b3ceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c07b3d0: /* original f457, guest PC 0x0c07b3d0 */
if(!s->budget--) { s->failed_pc=0x0c07b3d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c07b3d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b3d2u; return 0; } return 1;
P_0c07b4d4: /* original 654d, guest PC 0x0c07b4d4 */
if(!s->budget--) { s->failed_pc=0x0c07b4d4u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b4d6;
P_0c07b4d6: /* original 2fe6, guest PC 0x0c07b4d6 */
if(!s->budget--) { s->failed_pc=0x0c07b4d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4d8;
P_0c07b4d8: /* original 2fd6, guest PC 0x0c07b4d8 */
if(!s->budget--) { s->failed_pc=0x0c07b4d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b4da;
P_0c07b4da: /* original 9378, guest PC 0x0c07b4da */
if(!s->budget--) { s->failed_pc=0x0c07b4dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b4dc;
P_0c07b4dc: /* original 2358, guest PC 0x0c07b4dc */
if(!s->budget--) { s->failed_pc=0x0c07b4dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07b4de;
P_0c07b4de: /* original 8912, guest PC 0x0c07b4de */
if(!s->budget--) { s->failed_pc=0x0c07b4deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b506; }
goto P_0c07b4e0;
P_0c07b4e0: /* original 9476, guest PC 0x0c07b4e0 */
if(!s->budget--) { s->failed_pc=0x0c07b4e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b4e2;
P_0c07b4e2: /* original d23c, guest PC 0x0c07b4e2 */
if(!s->budget--) { s->failed_pc=0x0c07b4e2u; return 0; }
r[2]=read(ram,0x0c07b5d4u,4);
goto P_0c07b4e4;
P_0c07b4e4: /* original 2459, guest PC 0x0c07b4e4 */
if(!s->budget--) { s->failed_pc=0x0c07b4e4u; return 0; }
r[4]&=r[5];
goto P_0c07b4e6;
P_0c07b4e6: /* original 6343, guest PC 0x0c07b4e6 */
if(!s->budget--) { s->failed_pc=0x0c07b4e6u; return 0; }
r[3]=r[4];
goto P_0c07b4e8;
P_0c07b4e8: /* original 6543, guest PC 0x0c07b4e8 */
if(!s->budget--) { s->failed_pc=0x0c07b4e8u; return 0; }
r[5]=r[4];
goto P_0c07b4ea;
P_0c07b4ea: /* original 4308, guest PC 0x0c07b4ea */
if(!s->budget--) { s->failed_pc=0x0c07b4eau; return 0; }
r[3]<<=2;
goto P_0c07b4ec;
P_0c07b4ec: /* original 4500, guest PC 0x0c07b4ec */
if(!s->budget--) { s->failed_pc=0x0c07b4ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b4ee;
P_0c07b4ee: /* original 353c, guest PC 0x0c07b4ee */
if(!s->budget--) { s->failed_pc=0x0c07b4eeu; return 0; }
r[5]+=r[3];
goto P_0c07b4f0;
P_0c07b4f0: /* original 352c, guest PC 0x0c07b4f0 */
if(!s->budget--) { s->failed_pc=0x0c07b4f0u; return 0; }
r[5]+=r[2];
goto P_0c07b4f2;
P_0c07b4f2: /* original 8452, guest PC 0x0c07b4f2 */
if(!s->budget--) { s->failed_pc=0x0c07b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+2,1);
goto P_0c07b4f4;
P_0c07b4f4: /* original 6451, guest PC 0x0c07b4f4 */
if(!s->budget--) { s->failed_pc=0x0c07b4f4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c07b4f6;
P_0c07b4f6: /* original 660c, guest PC 0x0c07b4f6 */
if(!s->budget--) { s->failed_pc=0x0c07b4f6u; return 0; }
r[6]=r[0]&255u;
goto P_0c07b4f8;
P_0c07b4f8: /* original 8453, guest PC 0x0c07b4f8 */
if(!s->budget--) { s->failed_pc=0x0c07b4f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+3,1);
goto P_0c07b4fa;
P_0c07b4fa: /* original 670c, guest PC 0x0c07b4fa */
if(!s->budget--) { s->failed_pc=0x0c07b4fau; return 0; }
r[7]=r[0]&255u;
goto P_0c07b4fc;
P_0c07b4fc: /* original 8454, guest PC 0x0c07b4fc */
if(!s->budget--) { s->failed_pc=0x0c07b4fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+4,1);
goto P_0c07b4fe;
P_0c07b4fe: /* original 6e0c, guest PC 0x0c07b4fe */
if(!s->budget--) { s->failed_pc=0x0c07b4feu; return 0; }
r[14]=r[0]&255u;
goto P_0c07b500;
P_0c07b500: /* original 8455, guest PC 0x0c07b500 */
if(!s->budget--) { s->failed_pc=0x0c07b500u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+5,1);
goto P_0c07b502;
P_0c07b502: /* original a00a, guest PC 0x0c07b502 */
if(!s->budget--) { s->failed_pc=0x0c07b502u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b51a;
P_0c07b504: /* original 6d0c, guest PC 0x0c07b504 */
if(!s->budget--) { s->failed_pc=0x0c07b504u; return 0; }
r[13]=r[0]&255u;
goto P_0c07b506;
P_0c07b506: /* original e500, guest PC 0x0c07b506 */
if(!s->budget--) { s->failed_pc=0x0c07b506u; return 0; }
r[5]=0x00000000u;
goto P_0c07b508;
P_0c07b508: /* original d333, guest PC 0x0c07b508 */
if(!s->budget--) { s->failed_pc=0x0c07b508u; return 0; }
r[3]=read(ram,0x0c07b5d8u,4);
goto P_0c07b50a;
P_0c07b50a: /* original 6753, guest PC 0x0c07b50a */
if(!s->budget--) { s->failed_pc=0x0c07b50au; return 0; }
r[7]=r[5];
goto P_0c07b50c;
P_0c07b50c: /* original 6653, guest PC 0x0c07b50c */
if(!s->budget--) { s->failed_pc=0x0c07b50cu; return 0; }
r[6]=r[5];
goto P_0c07b50e;
P_0c07b50e: /* original 654d, guest PC 0x0c07b50e */
if(!s->budget--) { s->failed_pc=0x0c07b50eu; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b510;
P_0c07b510: /* original 4508, guest PC 0x0c07b510 */
if(!s->budget--) { s->failed_pc=0x0c07b510u; return 0; }
r[5]<<=2;
goto P_0c07b512;
P_0c07b512: /* original 353c, guest PC 0x0c07b512 */
if(!s->budget--) { s->failed_pc=0x0c07b512u; return 0; }
r[5]+=r[3];
goto P_0c07b514;
P_0c07b514: /* original 8551, guest PC 0x0c07b514 */
if(!s->budget--) { s->failed_pc=0x0c07b514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b516;
P_0c07b516: /* original 6e51, guest PC 0x0c07b516 */
if(!s->budget--) { s->failed_pc=0x0c07b516u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[14]=tmp;
goto P_0c07b518;
P_0c07b518: /* original 6d03, guest PC 0x0c07b518 */
if(!s->budget--) { s->failed_pc=0x0c07b518u; return 0; }
r[13]=r[0];
goto P_0c07b51a;
P_0c07b51a: /* original 666d, guest PC 0x0c07b51a */
if(!s->budget--) { s->failed_pc=0x0c07b51au; return 0; }
r[6]=r[6]&65535u;
goto P_0c07b51c;
P_0c07b51c: /* original d22f, guest PC 0x0c07b51c */
if(!s->budget--) { s->failed_pc=0x0c07b51cu; return 0; }
r[2]=read(ram,0x0c07b5dcu,4);
goto P_0c07b51e;
P_0c07b51e: /* original 4608, guest PC 0x0c07b51e */
if(!s->budget--) { s->failed_pc=0x0c07b51eu; return 0; }
r[6]<<=2;
goto P_0c07b520;
P_0c07b520: /* original 4600, guest PC 0x0c07b520 */
if(!s->budget--) { s->failed_pc=0x0c07b520u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07b522;
P_0c07b522: /* original 677d, guest PC 0x0c07b522 */
if(!s->budget--) { s->failed_pc=0x0c07b522u; return 0; }
r[7]=r[7]&65535u;
goto P_0c07b524;
P_0c07b524: /* original 4708, guest PC 0x0c07b524 */
if(!s->budget--) { s->failed_pc=0x0c07b524u; return 0; }
r[7]<<=2;
goto P_0c07b526;
P_0c07b526: /* original 634d, guest PC 0x0c07b526 */
if(!s->budget--) { s->failed_pc=0x0c07b526u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b528;
P_0c07b528: /* original 2232, guest PC 0x0c07b528 */
if(!s->budget--) { s->failed_pc=0x0c07b528u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07b52a;
P_0c07b52a: /* original 4700, guest PC 0x0c07b52a */
if(!s->budget--) { s->failed_pc=0x0c07b52au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c07b52c;
P_0c07b52c: /* original 465a, guest PC 0x0c07b52c */
if(!s->budget--) { s->failed_pc=0x0c07b52cu; return 0; }
r[53]=r[6];
goto P_0c07b52e;
P_0c07b52e: /* original 6eed, guest PC 0x0c07b52e */
if(!s->budget--) { s->failed_pc=0x0c07b52eu; return 0; }
r[14]=r[14]&65535u;
goto P_0c07b530;
P_0c07b530: /* original d32b, guest PC 0x0c07b530 */
if(!s->budget--) { s->failed_pc=0x0c07b530u; return 0; }
r[3]=read(ram,0x0c07b5e0u,4);
goto P_0c07b532;
P_0c07b532: /* original 4e08, guest PC 0x0c07b532 */
if(!s->budget--) { s->failed_pc=0x0c07b532u; return 0; }
r[14]<<=2;
goto P_0c07b534;
P_0c07b534: /* original 4e00, guest PC 0x0c07b534 */
if(!s->budget--) { s->failed_pc=0x0c07b534u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07b536;
P_0c07b536: /* original f32d, guest PC 0x0c07b536 */
if(!s->budget--) { s->failed_pc=0x0c07b536u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b538;
P_0c07b538: /* original 6ddd, guest PC 0x0c07b538 */
if(!s->budget--) { s->failed_pc=0x0c07b538u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b53a;
P_0c07b53a: /* original 4d08, guest PC 0x0c07b53a */
if(!s->budget--) { s->failed_pc=0x0c07b53au; return 0; }
r[13]<<=2;
goto P_0c07b53c;
P_0c07b53c: /* original 4d00, guest PC 0x0c07b53c */
if(!s->budget--) { s->failed_pc=0x0c07b53cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b53e;
P_0c07b53e: /* original 72e8, guest PC 0x0c07b53e */
if(!s->budget--) { s->failed_pc=0x0c07b53eu; return 0; }
r[2]+=0xffffffe8u;
goto P_0c07b540;
P_0c07b540: /* original 654d, guest PC 0x0c07b540 */
if(!s->budget--) { s->failed_pc=0x0c07b540u; return 0; }
r[5]=r[4]&65535u;
goto P_0c07b542;
P_0c07b542: /* original f33a, guest PC 0x0c07b542 */
if(!s->budget--) { s->failed_pc=0x0c07b542u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b544;
P_0c07b544: /* original 730c, guest PC 0x0c07b544 */
if(!s->budget--) { s->failed_pc=0x0c07b544u; return 0; }
r[3]+=0x0000000cu;
goto P_0c07b546;
P_0c07b546: /* original 475a, guest PC 0x0c07b546 */
if(!s->budget--) { s->failed_pc=0x0c07b546u; return 0; }
r[53]=r[7];
goto P_0c07b548;
P_0c07b548: /* original d126, guest PC 0x0c07b548 */
if(!s->budget--) { s->failed_pc=0x0c07b548u; return 0; }
r[1]=read(ram,0x0c07b5e4u,4);
goto P_0c07b54a;
P_0c07b54a: /* original f32d, guest PC 0x0c07b54a */
if(!s->budget--) { s->failed_pc=0x0c07b54au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b54c;
P_0c07b54c: /* original f13a, guest PC 0x0c07b54c */
if(!s->budget--) { s->failed_pc=0x0c07b54cu; return 0; }
vf3_matrix_store(s,ram,3,r[1]);
goto P_0c07b54e;
P_0c07b54e: /* original 4e5a, guest PC 0x0c07b54e */
if(!s->budget--) { s->failed_pc=0x0c07b54eu; return 0; }
r[53]=r[14];
goto P_0c07b550;
P_0c07b550: /* original f32d, guest PC 0x0c07b550 */
if(!s->budget--) { s->failed_pc=0x0c07b550u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b552;
P_0c07b552: /* original f23a, guest PC 0x0c07b552 */
if(!s->budget--) { s->failed_pc=0x0c07b552u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c07b554;
P_0c07b554: /* original 4d5a, guest PC 0x0c07b554 */
if(!s->budget--) { s->failed_pc=0x0c07b554u; return 0; }
r[53]=r[13];
goto P_0c07b556;
P_0c07b556: /* original f32d, guest PC 0x0c07b556 */
if(!s->budget--) { s->failed_pc=0x0c07b556u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b558;
P_0c07b558: /* original f33a, guest PC 0x0c07b558 */
if(!s->budget--) { s->failed_pc=0x0c07b558u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c07b55a;
P_0c07b55a: /* original d11f, guest PC 0x0c07b55a */
if(!s->budget--) { s->failed_pc=0x0c07b55au; return 0; }
r[1]=read(ram,0x0c07b5d8u,4);
goto P_0c07b55c;
P_0c07b55c: /* original 4508, guest PC 0x0c07b55c */
if(!s->budget--) { s->failed_pc=0x0c07b55cu; return 0; }
r[5]<<=2;
goto P_0c07b55e;
P_0c07b55e: /* original f49d, guest PC 0x0c07b55e */
if(!s->budget--) { s->failed_pc=0x0c07b55eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c07b560;
P_0c07b560: /* original 7308, guest PC 0x0c07b560 */
if(!s->budget--) { s->failed_pc=0x0c07b560u; return 0; }
r[3]+=0x00000008u;
goto P_0c07b562;
P_0c07b562: /* original 351c, guest PC 0x0c07b562 */
if(!s->budget--) { s->failed_pc=0x0c07b562u; return 0; }
r[5]+=r[1];
goto P_0c07b564;
P_0c07b564: /* original f24c, guest PC 0x0c07b564 */
if(!s->budget--) { s->failed_pc=0x0c07b564u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c07b566;
P_0c07b566: /* original 6251, guest PC 0x0c07b566 */
if(!s->budget--) { s->failed_pc=0x0c07b566u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c07b568;
P_0c07b568: /* original 8551, guest PC 0x0c07b568 */
if(!s->budget--) { s->failed_pc=0x0c07b568u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c07b56a;
P_0c07b56a: /* original 642d, guest PC 0x0c07b56a */
if(!s->budget--) { s->failed_pc=0x0c07b56au; return 0; }
r[4]=r[2]&65535u;
goto P_0c07b56c;
P_0c07b56c: /* original d21e, guest PC 0x0c07b56c */
if(!s->budget--) { s->failed_pc=0x0c07b56cu; return 0; }
r[2]=read(ram,0x0c07b5e8u,4);
goto P_0c07b56e;
P_0c07b56e: /* original 4408, guest PC 0x0c07b56e */
if(!s->budget--) { s->failed_pc=0x0c07b56eu; return 0; }
r[4]<<=2;
goto P_0c07b570;
P_0c07b570: /* original 4400, guest PC 0x0c07b570 */
if(!s->budget--) { s->failed_pc=0x0c07b570u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b572;
P_0c07b572: /* original 6123, guest PC 0x0c07b572 */
if(!s->budget--) { s->failed_pc=0x0c07b572u; return 0; }
r[1]=r[2];
goto P_0c07b574;
P_0c07b574: /* original 644d, guest PC 0x0c07b574 */
if(!s->budget--) { s->failed_pc=0x0c07b574u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b576;
P_0c07b576: /* original 445a, guest PC 0x0c07b576 */
if(!s->budget--) { s->failed_pc=0x0c07b576u; return 0; }
r[53]=r[4];
goto P_0c07b578;
P_0c07b578: /* original 650d, guest PC 0x0c07b578 */
if(!s->budget--) { s->failed_pc=0x0c07b578u; return 0; }
r[5]=r[0]&65535u;
goto P_0c07b57a;
P_0c07b57a: /* original 4508, guest PC 0x0c07b57a */
if(!s->budget--) { s->failed_pc=0x0c07b57au; return 0; }
r[5]<<=2;
goto P_0c07b57c;
P_0c07b57c: /* original 4500, guest PC 0x0c07b57c */
if(!s->budget--) { s->failed_pc=0x0c07b57cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b57e;
P_0c07b57e: /* original f32d, guest PC 0x0c07b57e */
if(!s->budget--) { s->failed_pc=0x0c07b57eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b580;
P_0c07b580: /* original 655d, guest PC 0x0c07b580 */
if(!s->budget--) { s->failed_pc=0x0c07b580u; return 0; }
r[5]=r[5]&65535u;
goto P_0c07b582;
P_0c07b582: /* original f233, guest PC 0x0c07b582 */
if(!s->budget--) { s->failed_pc=0x0c07b582u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c07b584;
P_0c07b584: /* original f22a, guest PC 0x0c07b584 */
if(!s->budget--) { s->failed_pc=0x0c07b584u; return 0; }
vf3_matrix_store(s,ram,2,r[2]);
goto P_0c07b586;
P_0c07b586: /* original 72f8, guest PC 0x0c07b586 */
if(!s->budget--) { s->failed_pc=0x0c07b586u; return 0; }
r[2]+=0xfffffff8u;
goto P_0c07b588;
P_0c07b588: /* original 455a, guest PC 0x0c07b588 */
if(!s->budget--) { s->failed_pc=0x0c07b588u; return 0; }
r[53]=r[5];
goto P_0c07b58a;
P_0c07b58a: /* original f32d, guest PC 0x0c07b58a */
if(!s->budget--) { s->failed_pc=0x0c07b58au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07b58c;
P_0c07b58c: /* original f433, guest PC 0x0c07b58c */
if(!s->budget--) { s->failed_pc=0x0c07b58cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c07b58e;
P_0c07b58e: /* original f34a, guest PC 0x0c07b58e */
if(!s->budget--) { s->failed_pc=0x0c07b58eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c07b590;
P_0c07b590: /* original 7304, guest PC 0x0c07b590 */
if(!s->budget--) { s->failed_pc=0x0c07b590u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b592;
P_0c07b592: /* original f318, guest PC 0x0c07b592 */
if(!s->budget--) { s->failed_pc=0x0c07b592u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c07b594;
P_0c07b594: /* original f228, guest PC 0x0c07b594 */
if(!s->budget--) { s->failed_pc=0x0c07b594u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c07b596;
P_0c07b596: /* original f232, guest PC 0x0c07b596 */
if(!s->budget--) { s->failed_pc=0x0c07b596u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b598;
P_0c07b598: /* original f32a, guest PC 0x0c07b598 */
if(!s->budget--) { s->failed_pc=0x0c07b598u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b59a;
P_0c07b59a: /* original d014, guest PC 0x0c07b59a */
if(!s->budget--) { s->failed_pc=0x0c07b59au; return 0; }
r[0]=read(ram,0x0c07b5ecu,4);
goto P_0c07b59c;
P_0c07b59c: /* original 720c, guest PC 0x0c07b59c */
if(!s->budget--) { s->failed_pc=0x0c07b59cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c07b59e;
P_0c07b59e: /* original f328, guest PC 0x0c07b59e */
if(!s->budget--) { s->failed_pc=0x0c07b59eu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c07b5a0;
P_0c07b5a0: /* original 7304, guest PC 0x0c07b5a0 */
if(!s->budget--) { s->failed_pc=0x0c07b5a0u; return 0; }
r[3]+=0x00000004u;
goto P_0c07b5a2;
P_0c07b5a2: /* original f208, guest PC 0x0c07b5a2 */
if(!s->budget--) { s->failed_pc=0x0c07b5a2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07b5a4;
P_0c07b5a4: /* original 70f4, guest PC 0x0c07b5a4 */
if(!s->budget--) { s->failed_pc=0x0c07b5a4u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c07b5a6;
P_0c07b5a6: /* original f232, guest PC 0x0c07b5a6 */
if(!s->budget--) { s->failed_pc=0x0c07b5a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07b5a8;
P_0c07b5a8: /* original f32a, guest PC 0x0c07b5a8 */
if(!s->budget--) { s->failed_pc=0x0c07b5a8u; return 0; }
vf3_matrix_store(s,ram,2,r[3]);
goto P_0c07b5aa;
P_0c07b5aa: /* original 6df6, guest PC 0x0c07b5aa */
if(!s->budget--) { s->failed_pc=0x0c07b5aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b5ac;
P_0c07b5ac: /* original 000b, guest PC 0x0c07b5ac */
if(!s->budget--) { s->failed_pc=0x0c07b5acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b5ae: /* original 6ef6, guest PC 0x0c07b5ae */
if(!s->budget--) { s->failed_pc=0x0c07b5aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b5b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5b0u; return 0; } return 1;
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
