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
int vf3_away_batch23_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a7662u: goto P_0c0a7662;
case 0x0c0a7664u: goto P_0c0a7664;
case 0x0c0a7666u: goto P_0c0a7666;
case 0x0c0a7668u: goto P_0c0a7668;
case 0x0c0a766au: goto P_0c0a766a;
case 0x0c0a766cu: goto P_0c0a766c;
case 0x0c0a766eu: goto P_0c0a766e;
case 0x0c0a7670u: goto P_0c0a7670;
case 0x0c0a7672u: goto P_0c0a7672;
case 0x0c0a7674u: goto P_0c0a7674;
case 0x0c0a7676u: goto P_0c0a7676;
case 0x0c0a7678u: goto P_0c0a7678;
case 0x0c0a767au: goto P_0c0a767a;
case 0x0c0a767cu: goto P_0c0a767c;
case 0x0c0a767eu: goto P_0c0a767e;
case 0x0c0a7680u: goto P_0c0a7680;
case 0x0c0a7682u: goto P_0c0a7682;
case 0x0c0a7684u: goto P_0c0a7684;
case 0x0c0a7686u: goto P_0c0a7686;
case 0x0c0a7688u: goto P_0c0a7688;
case 0x0c0a768au: goto P_0c0a768a;
case 0x0c0a768cu: goto P_0c0a768c;
case 0x0c0a768eu: goto P_0c0a768e;
case 0x0c0a7690u: goto P_0c0a7690;
case 0x0c0a7692u: goto P_0c0a7692;
case 0x0c0a7694u: goto P_0c0a7694;
case 0x0c0a7696u: goto P_0c0a7696;
case 0x0c0a7698u: goto P_0c0a7698;
case 0x0c0a769au: goto P_0c0a769a;
case 0x0c0a769cu: goto P_0c0a769c;
case 0x0c0a769eu: goto P_0c0a769e;
case 0x0c0a76a0u: goto P_0c0a76a0;
case 0x0c0a76a2u: goto P_0c0a76a2;
case 0x0c0a76a4u: goto P_0c0a76a4;
case 0x0c0a76a6u: goto P_0c0a76a6;
case 0x0c0a76a8u: goto P_0c0a76a8;
case 0x0c0a76aau: goto P_0c0a76aa;
case 0x0c0a76acu: goto P_0c0a76ac;
case 0x0c0a76aeu: goto P_0c0a76ae;
case 0x0c0a76b0u: goto P_0c0a76b0;
case 0x0c0a76b2u: goto P_0c0a76b2;
case 0x0c0a76b4u: goto P_0c0a76b4;
case 0x0c0a76b6u: goto P_0c0a76b6;
case 0x0c0a76b8u: goto P_0c0a76b8;
case 0x0c0a76bau: goto P_0c0a76ba;
case 0x0c0a76bcu: goto P_0c0a76bc;
case 0x0c0a76ecu: goto P_0c0a76ec;
case 0x0c0a76eeu: goto P_0c0a76ee;
case 0x0c0a76f0u: goto P_0c0a76f0;
case 0x0c0a76f2u: goto P_0c0a76f2;
case 0x0c0a76f4u: goto P_0c0a76f4;
case 0x0c0a76f6u: goto P_0c0a76f6;
case 0x0c0a76f8u: goto P_0c0a76f8;
case 0x0c0a76fau: goto P_0c0a76fa;
case 0x0c0a76fcu: goto P_0c0a76fc;
case 0x0c0a76feu: goto P_0c0a76fe;
case 0x0c0a7700u: goto P_0c0a7700;
case 0x0c0a7702u: goto P_0c0a7702;
case 0x0c0a7704u: goto P_0c0a7704;
case 0x0c0a7706u: goto P_0c0a7706;
case 0x0c0a7708u: goto P_0c0a7708;
case 0x0c0a770au: goto P_0c0a770a;
case 0x0c0a770cu: goto P_0c0a770c;
case 0x0c0a770eu: goto P_0c0a770e;
case 0x0c0a7710u: goto P_0c0a7710;
case 0x0c0a7712u: goto P_0c0a7712;
case 0x0c0a7714u: goto P_0c0a7714;
case 0x0c0a7716u: goto P_0c0a7716;
case 0x0c0a7718u: goto P_0c0a7718;
case 0x0c0a771au: goto P_0c0a771a;
case 0x0c0a771cu: goto P_0c0a771c;
case 0x0c0a771eu: goto P_0c0a771e;
case 0x0c0a7720u: goto P_0c0a7720;
case 0x0c0a7722u: goto P_0c0a7722;
case 0x0c0a7724u: goto P_0c0a7724;
case 0x0c0a7726u: goto P_0c0a7726;
case 0x0c0a7728u: goto P_0c0a7728;
case 0x0c0a772au: goto P_0c0a772a;
case 0x0c0a772cu: goto P_0c0a772c;
case 0x0c0a772eu: goto P_0c0a772e;
case 0x0c0a7730u: goto P_0c0a7730;
case 0x0c0a7732u: goto P_0c0a7732;
case 0x0c0a7734u: goto P_0c0a7734;
case 0x0c0a7736u: goto P_0c0a7736;
case 0x0c0a7738u: goto P_0c0a7738;
case 0x0c0a773au: goto P_0c0a773a;
case 0x0c0a773cu: goto P_0c0a773c;
case 0x0c0a773eu: goto P_0c0a773e;
case 0x0c0a7740u: goto P_0c0a7740;
case 0x0c0a7742u: goto P_0c0a7742;
case 0x0c0a7744u: goto P_0c0a7744;
case 0x0c0a7746u: goto P_0c0a7746;
case 0x0c0a7748u: goto P_0c0a7748;
case 0x0c0a774au: goto P_0c0a774a;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a7662: /* original 2fe6, guest PC 0x0c0a7662 */
if(!s->budget--) { s->failed_pc=0x0c0a7662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7664;
P_0c0a7664: /* original 932b, guest PC 0x0c0a7664 */
if(!s->budget--) { s->failed_pc=0x0c0a7664u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7666;
P_0c0a7666: /* original 4f22, guest PC 0x0c0a7666 */
if(!s->budget--) { s->failed_pc=0x0c0a7666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7668;
P_0c0a7668: /* original 3433, guest PC 0x0c0a7668 */
if(!s->budget--) { s->failed_pc=0x0c0a7668u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a766a;
P_0c0a766a: /* original 8925, guest PC 0x0c0a766a */
if(!s->budget--) { s->failed_pc=0x0c0a766au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a766c;
P_0c0a766c: /* original d014, guest PC 0x0c0a766c */
if(!s->budget--) { s->failed_pc=0x0c0a766cu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a766e;
P_0c0a766e: /* original 6e43, guest PC 0x0c0a766e */
if(!s->budget--) { s->failed_pc=0x0c0a766eu; return 0; }
r[14]=r[4];
goto P_0c0a7670;
P_0c0a7670: /* original 4e08, guest PC 0x0c0a7670 */
if(!s->budget--) { s->failed_pc=0x0c0a7670u; return 0; }
r[14]<<=2;
goto P_0c0a7672;
P_0c0a7672: /* original 0eee, guest PC 0x0c0a7672 */
if(!s->budget--) { s->failed_pc=0x0c0a7672u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7674;
P_0c0a7674: /* original 2ee8, guest PC 0x0c0a7674 */
if(!s->budget--) { s->failed_pc=0x0c0a7674u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7676;
P_0c0a7676: /* original 891f, guest PC 0x0c0a7676 */
if(!s->budget--) { s->failed_pc=0x0c0a7676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a7678;
P_0c0a7678: /* original 60e3, guest PC 0x0c0a7678 */
if(!s->budget--) { s->failed_pc=0x0c0a7678u; return 0; }
r[0]=r[14];
goto P_0c0a767a;
P_0c0a767a: /* original 88ff, guest PC 0x0c0a767a */
if(!s->budget--) { s->failed_pc=0x0c0a767au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a767c;
P_0c0a767c: /* original 891c, guest PC 0x0c0a767c */
if(!s->budget--) { s->failed_pc=0x0c0a767cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76b8; }
goto P_0c0a767e;
P_0c0a767e: /* original d311, guest PC 0x0c0a767e */
if(!s->budget--) { s->failed_pc=0x0c0a767eu; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7680;
P_0c0a7680: /* original 430b, guest PC 0x0c0a7680 */
if(!s->budget--) { s->failed_pc=0x0c0a7680u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7684u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7684u) { target=s->pc; goto dispatch; }
goto P_0c0a7684;
P_0c0a7682: /* original e400, guest PC 0x0c0a7682 */
if(!s->budget--) { s->failed_pc=0x0c0a7682u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7684;
P_0c0a7684: /* original d211, guest PC 0x0c0a7684 */
if(!s->budget--) { s->failed_pc=0x0c0a7684u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7686;
P_0c0a7686: /* original d410, guest PC 0x0c0a7686 */
if(!s->budget--) { s->failed_pc=0x0c0a7686u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a7688;
P_0c0a7688: /* original 420b, guest PC 0x0c0a7688 */
if(!s->budget--) { s->failed_pc=0x0c0a7688u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a768cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a768cu) { target=s->pc; goto dispatch; }
goto P_0c0a768c;
P_0c0a768a: /* original 0009, guest PC 0x0c0a768a */
if(!s->budget--) { s->failed_pc=0x0c0a768au; return 0; }
goto P_0c0a768c;
P_0c0a768c: /* original 50e1, guest PC 0x0c0a768c */
if(!s->budget--) { s->failed_pc=0x0c0a768cu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a768e;
P_0c0a768e: /* original c801, guest PC 0x0c0a768e */
if(!s->budget--) { s->failed_pc=0x0c0a768eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7690;
P_0c0a7690: /* original 8904, guest PC 0x0c0a7690 */
if(!s->budget--) { s->failed_pc=0x0c0a7690u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a769c; }
goto P_0c0a7692;
P_0c0a7692: /* original d213, guest PC 0x0c0a7692 */
if(!s->budget--) { s->failed_pc=0x0c0a7692u; return 0; }
r[2]=read(ram,0x0c0a76e0u,4);
goto P_0c0a7694;
P_0c0a7694: /* original 420b, guest PC 0x0c0a7694 */
if(!s->budget--) { s->failed_pc=0x0c0a7694u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7698u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7698u) { target=s->pc; goto dispatch; }
goto P_0c0a7698;
P_0c0a7696: /* original 64e3, guest PC 0x0c0a7696 */
if(!s->budget--) { s->failed_pc=0x0c0a7696u; return 0; }
r[4]=r[14];
goto P_0c0a7698;
P_0c0a7698: /* original a009, guest PC 0x0c0a7698 */
if(!s->budget--) { s->failed_pc=0x0c0a7698u; return 0; }
goto P_0c0a76ae;
P_0c0a769a: /* original 0009, guest PC 0x0c0a769a */
if(!s->budget--) { s->failed_pc=0x0c0a769au; return 0; }
goto P_0c0a769c;
P_0c0a769c: /* original d20d, guest PC 0x0c0a769c */
if(!s->budget--) { s->failed_pc=0x0c0a769cu; return 0; }
r[2]=read(ram,0x0c0a76d4u,4);
goto P_0c0a769e;
P_0c0a769e: /* original 420b, guest PC 0x0c0a769e */
if(!s->budget--) { s->failed_pc=0x0c0a769eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a76a2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76a2u) { target=s->pc; goto dispatch; }
goto P_0c0a76a2;
P_0c0a76a0: /* original 0009, guest PC 0x0c0a76a0 */
if(!s->budget--) { s->failed_pc=0x0c0a76a0u; return 0; }
goto P_0c0a76a2;
P_0c0a76a2: /* original d310, guest PC 0x0c0a76a2 */
if(!s->budget--) { s->failed_pc=0x0c0a76a2u; return 0; }
r[3]=read(ram,0x0c0a76e4u,4);
goto P_0c0a76a4;
P_0c0a76a4: /* original 23e8, guest PC 0x0c0a76a4 */
if(!s->budget--) { s->failed_pc=0x0c0a76a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a76a6;
P_0c0a76a6: /* original 8902, guest PC 0x0c0a76a6 */
if(!s->budget--) { s->failed_pc=0x0c0a76a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a76ae; }
goto P_0c0a76a8;
P_0c0a76a8: /* original d30f, guest PC 0x0c0a76a8 */
if(!s->budget--) { s->failed_pc=0x0c0a76a8u; return 0; }
r[3]=read(ram,0x0c0a76e8u,4);
goto P_0c0a76aa;
P_0c0a76aa: /* original 430b, guest PC 0x0c0a76aa */
if(!s->budget--) { s->failed_pc=0x0c0a76aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76aeu) { target=s->pc; goto dispatch; }
goto P_0c0a76ae;
P_0c0a76ac: /* original 64e3, guest PC 0x0c0a76ac */
if(!s->budget--) { s->failed_pc=0x0c0a76acu; return 0; }
r[4]=r[14];
goto P_0c0a76ae;
P_0c0a76ae: /* original 4f26, guest PC 0x0c0a76ae */
if(!s->budget--) { s->failed_pc=0x0c0a76aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76b0;
P_0c0a76b0: /* original d30a, guest PC 0x0c0a76b0 */
if(!s->budget--) { s->failed_pc=0x0c0a76b0u; return 0; }
r[3]=read(ram,0x0c0a76dcu,4);
goto P_0c0a76b2;
P_0c0a76b2: /* original e401, guest PC 0x0c0a76b2 */
if(!s->budget--) { s->failed_pc=0x0c0a76b2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a76b4;
P_0c0a76b4: /* original 432b, guest PC 0x0c0a76b4 */
if(!s->budget--) { s->failed_pc=0x0c0a76b4u; return 0; }
target=r[3];
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
P_0c0a76b6: /* original 6ef6, guest PC 0x0c0a76b6 */
if(!s->budget--) { s->failed_pc=0x0c0a76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a76b8;
P_0c0a76b8: /* original 4f26, guest PC 0x0c0a76b8 */
if(!s->budget--) { s->failed_pc=0x0c0a76b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a76ba;
P_0c0a76ba: /* original 000b, guest PC 0x0c0a76ba */
if(!s->budget--) { s->failed_pc=0x0c0a76bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a76bc: /* original 6ef6, guest PC 0x0c0a76bc */
if(!s->budget--) { s->failed_pc=0x0c0a76bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a76beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a76beu; return 0; } return 1;
P_0c0a76ec: /* original 2fe6, guest PC 0x0c0a76ec */
if(!s->budget--) { s->failed_pc=0x0c0a76ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a76ee;
P_0c0a76ee: /* original 4f22, guest PC 0x0c0a76ee */
if(!s->budget--) { s->failed_pc=0x0c0a76eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a76f0;
P_0c0a76f0: /* original 7ff8, guest PC 0x0c0a76f0 */
if(!s->budget--) { s->failed_pc=0x0c0a76f0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a76f2;
P_0c0a76f2: /* original 1f41, guest PC 0x0c0a76f2 */
if(!s->budget--) { s->failed_pc=0x0c0a76f2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a76f4;
P_0c0a76f4: /* original ff4a, guest PC 0x0c0a76f4 */
if(!s->budget--) { s->failed_pc=0x0c0a76f4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a76f6;
P_0c0a76f6: /* original d34b, guest PC 0x0c0a76f6 */
if(!s->budget--) { s->failed_pc=0x0c0a76f6u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a76f8;
P_0c0a76f8: /* original 430b, guest PC 0x0c0a76f8 */
if(!s->budget--) { s->failed_pc=0x0c0a76f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76fcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76fcu) { target=s->pc; goto dispatch; }
goto P_0c0a76fc;
P_0c0a76fa: /* original e400, guest PC 0x0c0a76fa */
if(!s->budget--) { s->failed_pc=0x0c0a76fau; return 0; }
r[4]=0x00000000u;
goto P_0c0a76fc;
P_0c0a76fc: /* original 5ef1, guest PC 0x0c0a76fc */
if(!s->budget--) { s->failed_pc=0x0c0a76fcu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0a76fe;
P_0c0a76fe: /* original e301, guest PC 0x0c0a76fe */
if(!s->budget--) { s->failed_pc=0x0c0a76feu; return 0; }
r[3]=0x00000001u;
goto P_0c0a7700;
P_0c0a7700: /* original 5ee1, guest PC 0x0c0a7700 */
if(!s->budget--) { s->failed_pc=0x0c0a7700u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c0a7702;
P_0c0a7702: /* original 23e8, guest PC 0x0c0a7702 */
if(!s->budget--) { s->failed_pc=0x0c0a7702u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a7704;
P_0c0a7704: /* original 8b1e, guest PC 0x0c0a7704 */
if(!s->budget--) { s->failed_pc=0x0c0a7704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7744; }
goto P_0c0a7706;
P_0c0a7706: /* original 2ee8, guest PC 0x0c0a7706 */
if(!s->budget--) { s->failed_pc=0x0c0a7706u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7708;
P_0c0a7708: /* original 8916, guest PC 0x0c0a7708 */
if(!s->budget--) { s->failed_pc=0x0c0a7708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a770a;
P_0c0a770a: /* original d348, guest PC 0x0c0a770a */
if(!s->budget--) { s->failed_pc=0x0c0a770au; return 0; }
r[3]=read(ram,0x0c0a782cu,4);
goto P_0c0a770c;
P_0c0a770c: /* original d446, guest PC 0x0c0a770c */
if(!s->budget--) { s->failed_pc=0x0c0a770cu; return 0; }
r[4]=read(ram,0x0c0a7828u,4);
goto P_0c0a770e;
P_0c0a770e: /* original 430b, guest PC 0x0c0a770e */
if(!s->budget--) { s->failed_pc=0x0c0a770eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7712u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7712u) { target=s->pc; goto dispatch; }
goto P_0c0a7712;
P_0c0a7710: /* original 0009, guest PC 0x0c0a7710 */
if(!s->budget--) { s->failed_pc=0x0c0a7710u; return 0; }
goto P_0c0a7712;
P_0c0a7712: /* original d247, guest PC 0x0c0a7712 */
if(!s->budget--) { s->failed_pc=0x0c0a7712u; return 0; }
r[2]=read(ram,0x0c0a7830u,4);
goto P_0c0a7714;
P_0c0a7714: /* original 420b, guest PC 0x0c0a7714 */
if(!s->budget--) { s->failed_pc=0x0c0a7714u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7718u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7718u) { target=s->pc; goto dispatch; }
goto P_0c0a7718;
P_0c0a7716: /* original 0009, guest PC 0x0c0a7716 */
if(!s->budget--) { s->failed_pc=0x0c0a7716u; return 0; }
goto P_0c0a7718;
P_0c0a7718: /* original f2f8, guest PC 0x0c0a7718 */
if(!s->budget--) { s->failed_pc=0x0c0a7718u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a771a;
P_0c0a771a: /* original f39d, guest PC 0x0c0a771a */
if(!s->budget--) { s->failed_pc=0x0c0a771au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0a771c;
P_0c0a771c: /* original f325, guest PC 0x0c0a771c */
if(!s->budget--) { s->failed_pc=0x0c0a771cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0a771e;
P_0c0a771e: /* original 8907, guest PC 0x0c0a771e */
if(!s->budget--) { s->failed_pc=0x0c0a771eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7730; }
goto P_0c0a7720;
P_0c0a7720: /* original d244, guest PC 0x0c0a7720 */
if(!s->budget--) { s->failed_pc=0x0c0a7720u; return 0; }
r[2]=read(ram,0x0c0a7834u,4);
goto P_0c0a7722;
P_0c0a7722: /* original 22e8, guest PC 0x0c0a7722 */
if(!s->budget--) { s->failed_pc=0x0c0a7722u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0a7724;
P_0c0a7724: /* original 8908, guest PC 0x0c0a7724 */
if(!s->budget--) { s->failed_pc=0x0c0a7724u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a7726;
P_0c0a7726: /* original d244, guest PC 0x0c0a7726 */
if(!s->budget--) { s->failed_pc=0x0c0a7726u; return 0; }
r[2]=read(ram,0x0c0a7838u,4);
goto P_0c0a7728;
P_0c0a7728: /* original 420b, guest PC 0x0c0a7728 */
if(!s->budget--) { s->failed_pc=0x0c0a7728u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a772cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a772cu) { target=s->pc; goto dispatch; }
goto P_0c0a772c;
P_0c0a772a: /* original 64e3, guest PC 0x0c0a772a */
if(!s->budget--) { s->failed_pc=0x0c0a772au; return 0; }
r[4]=r[14];
goto P_0c0a772c;
P_0c0a772c: /* original a004, guest PC 0x0c0a772c */
if(!s->budget--) { s->failed_pc=0x0c0a772cu; return 0; }
goto P_0c0a7738;
P_0c0a772e: /* original 0009, guest PC 0x0c0a772e */
if(!s->budget--) { s->failed_pc=0x0c0a772eu; return 0; }
goto P_0c0a7730;
P_0c0a7730: /* original d342, guest PC 0x0c0a7730 */
if(!s->budget--) { s->failed_pc=0x0c0a7730u; return 0; }
r[3]=read(ram,0x0c0a783cu,4);
goto P_0c0a7732;
P_0c0a7732: /* original f42c, guest PC 0x0c0a7732 */
if(!s->budget--) { s->failed_pc=0x0c0a7732u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a7734;
P_0c0a7734: /* original 430b, guest PC 0x0c0a7734 */
if(!s->budget--) { s->failed_pc=0x0c0a7734u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7738u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7738u) { target=s->pc; goto dispatch; }
goto P_0c0a7738;
P_0c0a7736: /* original 64e3, guest PC 0x0c0a7736 */
if(!s->budget--) { s->failed_pc=0x0c0a7736u; return 0; }
r[4]=r[14];
goto P_0c0a7738;
P_0c0a7738: /* original 7f08, guest PC 0x0c0a7738 */
if(!s->budget--) { s->failed_pc=0x0c0a7738u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a773a;
P_0c0a773a: /* original d241, guest PC 0x0c0a773a */
if(!s->budget--) { s->failed_pc=0x0c0a773au; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a773c;
P_0c0a773c: /* original 4f26, guest PC 0x0c0a773c */
if(!s->budget--) { s->failed_pc=0x0c0a773cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a773e;
P_0c0a773e: /* original e401, guest PC 0x0c0a773e */
if(!s->budget--) { s->failed_pc=0x0c0a773eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a7740;
P_0c0a7740: /* original 422b, guest PC 0x0c0a7740 */
if(!s->budget--) { s->failed_pc=0x0c0a7740u; return 0; }
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
P_0c0a7742: /* original 6ef6, guest PC 0x0c0a7742 */
if(!s->budget--) { s->failed_pc=0x0c0a7742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7744;
P_0c0a7744: /* original 7f08, guest PC 0x0c0a7744 */
if(!s->budget--) { s->failed_pc=0x0c0a7744u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a7746;
P_0c0a7746: /* original 4f26, guest PC 0x0c0a7746 */
if(!s->budget--) { s->failed_pc=0x0c0a7746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7748;
P_0c0a7748: /* original 000b, guest PC 0x0c0a7748 */
if(!s->budget--) { s->failed_pc=0x0c0a7748u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a774a: /* original 6ef6, guest PC 0x0c0a774a */
if(!s->budget--) { s->failed_pc=0x0c0a774au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a774cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a774cu; return 0; } return 1;
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
