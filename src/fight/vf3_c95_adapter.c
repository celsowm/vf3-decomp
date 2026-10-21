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
int vf3_c95_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c035270u: goto P_0c035270;
case 0x0c035272u: goto P_0c035272;
case 0x0c035274u: goto P_0c035274;
case 0x0c035276u: goto P_0c035276;
case 0x0c035278u: goto P_0c035278;
case 0x0c03527au: goto P_0c03527a;
case 0x0c03527cu: goto P_0c03527c;
case 0x0c03527eu: goto P_0c03527e;
case 0x0c035280u: goto P_0c035280;
case 0x0c035282u: goto P_0c035282;
case 0x0c035284u: goto P_0c035284;
case 0x0c035286u: goto P_0c035286;
case 0x0c035288u: goto P_0c035288;
case 0x0c03528au: goto P_0c03528a;
case 0x0c03528cu: goto P_0c03528c;
case 0x0c03528eu: goto P_0c03528e;
case 0x0c035290u: goto P_0c035290;
case 0x0c035292u: goto P_0c035292;
case 0x0c035294u: goto P_0c035294;
case 0x0c035296u: goto P_0c035296;
case 0x0c035298u: goto P_0c035298;
case 0x0c03529au: goto P_0c03529a;
case 0x0c03529cu: goto P_0c03529c;
case 0x0c03529eu: goto P_0c03529e;
case 0x0c0352a0u: goto P_0c0352a0;
case 0x0c0352a2u: goto P_0c0352a2;
case 0x0c0352a4u: goto P_0c0352a4;
case 0x0c0352a6u: goto P_0c0352a6;
case 0x0c0352a8u: goto P_0c0352a8;
case 0x0c0352aau: goto P_0c0352aa;
case 0x0c0352acu: goto P_0c0352ac;
case 0x0c0352aeu: goto P_0c0352ae;
case 0x0c0352b0u: goto P_0c0352b0;
case 0x0c0352b2u: goto P_0c0352b2;
case 0x0c0352b4u: goto P_0c0352b4;
case 0x0c0352b6u: goto P_0c0352b6;
case 0x0c0352b8u: goto P_0c0352b8;
case 0x0c0352bau: goto P_0c0352ba;
case 0x0c0352bcu: goto P_0c0352bc;
case 0x0c0352beu: goto P_0c0352be;
case 0x0c0352c0u: goto P_0c0352c0;
case 0x0c0352c2u: goto P_0c0352c2;
case 0x0c0352c4u: goto P_0c0352c4;
case 0x0c0352c6u: goto P_0c0352c6;
case 0x0c0352c8u: goto P_0c0352c8;
case 0x0c0352cau: goto P_0c0352ca;
case 0x0c0352ccu: goto P_0c0352cc;
case 0x0c0352ceu: goto P_0c0352ce;
case 0x0c0352d0u: goto P_0c0352d0;
case 0x0c0352d2u: goto P_0c0352d2;
case 0x0c0352d4u: goto P_0c0352d4;
case 0x0c0352d6u: goto P_0c0352d6;
case 0x0c0352d8u: goto P_0c0352d8;
case 0x0c035306u: goto P_0c035306;
case 0x0c035308u: goto P_0c035308;
case 0x0c03530au: goto P_0c03530a;
case 0x0c03530cu: goto P_0c03530c;
case 0x0c03530eu: goto P_0c03530e;
case 0x0c035310u: goto P_0c035310;
case 0x0c035312u: goto P_0c035312;
case 0x0c035314u: goto P_0c035314;
case 0x0c035316u: goto P_0c035316;
case 0x0c035318u: goto P_0c035318;
case 0x0c03531au: goto P_0c03531a;
case 0x0c03531cu: goto P_0c03531c;
case 0x0c03531eu: goto P_0c03531e;
case 0x0c035320u: goto P_0c035320;
case 0x0c035322u: goto P_0c035322;
case 0x0c035324u: goto P_0c035324;
case 0x0c035326u: goto P_0c035326;
case 0x0c035328u: goto P_0c035328;
case 0x0c03532au: goto P_0c03532a;
case 0x0c03532cu: goto P_0c03532c;
case 0x0c03532eu: goto P_0c03532e;
case 0x0c035330u: goto P_0c035330;
case 0x0c035332u: goto P_0c035332;
case 0x0c035334u: goto P_0c035334;
case 0x0c035336u: goto P_0c035336;
case 0x0c035338u: goto P_0c035338;
case 0x0c03533au: goto P_0c03533a;
case 0x0c03533cu: goto P_0c03533c;
case 0x0c03533eu: goto P_0c03533e;
case 0x0c035340u: goto P_0c035340;
case 0x0c035342u: goto P_0c035342;
case 0x0c035344u: goto P_0c035344;
case 0x0c035346u: goto P_0c035346;
case 0x0c035348u: goto P_0c035348;
case 0x0c03534au: goto P_0c03534a;
case 0x0c03534cu: goto P_0c03534c;
case 0x0c03534eu: goto P_0c03534e;
case 0x0c035350u: goto P_0c035350;
case 0x0c035352u: goto P_0c035352;
case 0x0c035354u: goto P_0c035354;
case 0x0c035356u: goto P_0c035356;
case 0x0c035358u: goto P_0c035358;
case 0x0c03535au: goto P_0c03535a;
case 0x0c03535cu: goto P_0c03535c;
case 0x0c03535eu: goto P_0c03535e;
case 0x0c035360u: goto P_0c035360;
case 0x0c035362u: goto P_0c035362;
case 0x0c035364u: goto P_0c035364;
case 0x0c035366u: goto P_0c035366;
case 0x0c035368u: goto P_0c035368;
case 0x0c03536au: goto P_0c03536a;
case 0x0c035370u: goto P_0c035370;
case 0x0c035372u: goto P_0c035372;
case 0x0c035374u: goto P_0c035374;
case 0x0c035376u: goto P_0c035376;
case 0x0c035378u: goto P_0c035378;
case 0x0c03537au: goto P_0c03537a;
case 0x0c03537cu: goto P_0c03537c;
case 0x0c03537eu: goto P_0c03537e;
case 0x0c035380u: goto P_0c035380;
case 0x0c035382u: goto P_0c035382;
case 0x0c035384u: goto P_0c035384;
case 0x0c035386u: goto P_0c035386;
case 0x0c035388u: goto P_0c035388;
case 0x0c03538au: goto P_0c03538a;
case 0x0c03538cu: goto P_0c03538c;
case 0x0c03538eu: goto P_0c03538e;
case 0x0c035390u: goto P_0c035390;
case 0x0c035392u: goto P_0c035392;
case 0x0c035394u: goto P_0c035394;
case 0x0c035396u: goto P_0c035396;
case 0x0c035398u: goto P_0c035398;
case 0x0c03539au: goto P_0c03539a;
case 0x0c03539cu: goto P_0c03539c;
case 0x0c03539eu: goto P_0c03539e;
case 0x0c0353a0u: goto P_0c0353a0;
case 0x0c0353a2u: goto P_0c0353a2;
case 0x0c0353a4u: goto P_0c0353a4;
case 0x0c0353a6u: goto P_0c0353a6;
case 0x0c0353a8u: goto P_0c0353a8;
case 0x0c0353aau: goto P_0c0353aa;
case 0x0c0353acu: goto P_0c0353ac;
case 0x0c0353aeu: goto P_0c0353ae;
case 0x0c0353b0u: goto P_0c0353b0;
case 0x0c0353b2u: goto P_0c0353b2;
case 0x0c0353b4u: goto P_0c0353b4;
case 0x0c0353b6u: goto P_0c0353b6;
case 0x0c0353b8u: goto P_0c0353b8;
case 0x0c0353bau: goto P_0c0353ba;
case 0x0c0353bcu: goto P_0c0353bc;
case 0x0c0353beu: goto P_0c0353be;
case 0x0c0353c0u: goto P_0c0353c0;
case 0x0c0353c2u: goto P_0c0353c2;
case 0x0c0353c4u: goto P_0c0353c4;
case 0x0c0353c6u: goto P_0c0353c6;
case 0x0c0353c8u: goto P_0c0353c8;
case 0x0c0353cau: goto P_0c0353ca;
case 0x0c0353ccu: goto P_0c0353cc;
case 0x0c0353ceu: goto P_0c0353ce;
case 0x0c0353d0u: goto P_0c0353d0;
case 0x0c0353d2u: goto P_0c0353d2;
case 0x0c0353d4u: goto P_0c0353d4;
case 0x0c0354a4u: goto P_0c0354a4;
case 0x0c0354a6u: goto P_0c0354a6;
case 0x0c0354a8u: goto P_0c0354a8;
case 0x0c0354aau: goto P_0c0354aa;
case 0x0c0354acu: goto P_0c0354ac;
case 0x0c0354aeu: goto P_0c0354ae;
case 0x0c0354b0u: goto P_0c0354b0;
case 0x0c0354b2u: goto P_0c0354b2;
case 0x0c0354b4u: goto P_0c0354b4;
case 0x0c0354b6u: goto P_0c0354b6;
case 0x0c0354b8u: goto P_0c0354b8;
case 0x0c0354bau: goto P_0c0354ba;
case 0x0c0354bcu: goto P_0c0354bc;
case 0x0c0354beu: goto P_0c0354be;
case 0x0c0354c0u: goto P_0c0354c0;
case 0x0c0354c2u: goto P_0c0354c2;
case 0x0c0354c4u: goto P_0c0354c4;
case 0x0c0354c6u: goto P_0c0354c6;
case 0x0c0354c8u: goto P_0c0354c8;
case 0x0c0354cau: goto P_0c0354ca;
case 0x0c0354ccu: goto P_0c0354cc;
case 0x0c0354ceu: goto P_0c0354ce;
case 0x0c0354d0u: goto P_0c0354d0;
case 0x0c0354d2u: goto P_0c0354d2;
case 0x0c0354d4u: goto P_0c0354d4;
case 0x0c0354d6u: goto P_0c0354d6;
case 0x0c0354d8u: goto P_0c0354d8;
case 0x0c0354dau: goto P_0c0354da;
case 0x0c0354dcu: goto P_0c0354dc;
case 0x0c0354deu: goto P_0c0354de;
case 0x0c0354e0u: goto P_0c0354e0;
case 0x0c0354e2u: goto P_0c0354e2;
case 0x0c0354e4u: goto P_0c0354e4;
case 0x0c0354e6u: goto P_0c0354e6;
case 0x0c0354e8u: goto P_0c0354e8;
case 0x0c0354eau: goto P_0c0354ea;
case 0x0c0354ecu: goto P_0c0354ec;
case 0x0c0354eeu: goto P_0c0354ee;
case 0x0c0354f0u: goto P_0c0354f0;
case 0x0c0354f2u: goto P_0c0354f2;
case 0x0c0354f4u: goto P_0c0354f4;
case 0x0c0354f6u: goto P_0c0354f6;
case 0x0c0354f8u: goto P_0c0354f8;
case 0x0c0354fau: goto P_0c0354fa;
case 0x0c0354fcu: goto P_0c0354fc;
case 0x0c0354feu: goto P_0c0354fe;
case 0x0c035500u: goto P_0c035500;
case 0x0c035518u: goto P_0c035518;
case 0x0c03551au: goto P_0c03551a;
case 0x0c03551cu: goto P_0c03551c;
case 0x0c03551eu: goto P_0c03551e;
case 0x0c035520u: goto P_0c035520;
case 0x0c035522u: goto P_0c035522;
case 0x0c035524u: goto P_0c035524;
case 0x0c035526u: goto P_0c035526;
case 0x0c035528u: goto P_0c035528;
case 0x0c03552au: goto P_0c03552a;
case 0x0c03552cu: goto P_0c03552c;
case 0x0c03552eu: goto P_0c03552e;
case 0x0c035530u: goto P_0c035530;
case 0x0c035532u: goto P_0c035532;
case 0x0c035534u: goto P_0c035534;
case 0x0c035536u: goto P_0c035536;
case 0x0c035538u: goto P_0c035538;
case 0x0c03553au: goto P_0c03553a;
case 0x0c03553cu: goto P_0c03553c;
case 0x0c03553eu: goto P_0c03553e;
case 0x0c035540u: goto P_0c035540;
case 0x0c035542u: goto P_0c035542;
case 0x0c035544u: goto P_0c035544;
case 0x0c035546u: goto P_0c035546;
case 0x0c035548u: goto P_0c035548;
case 0x0c03554au: goto P_0c03554a;
case 0x0c03554cu: goto P_0c03554c;
case 0x0c03554eu: goto P_0c03554e;
case 0x0c035550u: goto P_0c035550;
case 0x0c035552u: goto P_0c035552;
case 0x0c035554u: goto P_0c035554;
case 0x0c035556u: goto P_0c035556;
case 0x0c035558u: goto P_0c035558;
case 0x0c03555au: goto P_0c03555a;
case 0x0c03555cu: goto P_0c03555c;
case 0x0c03555eu: goto P_0c03555e;
case 0x0c035560u: goto P_0c035560;
case 0x0c035562u: goto P_0c035562;
case 0x0c035564u: goto P_0c035564;
case 0x0c035566u: goto P_0c035566;
case 0x0c035568u: goto P_0c035568;
case 0x0c03556au: goto P_0c03556a;
case 0x0c03556cu: goto P_0c03556c;
case 0x0c03556eu: goto P_0c03556e;
case 0x0c035570u: goto P_0c035570;
case 0x0c035572u: goto P_0c035572;
case 0x0c035574u: goto P_0c035574;
case 0x0c035576u: goto P_0c035576;
case 0x0c035578u: goto P_0c035578;
case 0x0c03557au: goto P_0c03557a;
case 0x0c03557cu: goto P_0c03557c;
case 0x0c03557eu: goto P_0c03557e;
case 0x0c035580u: goto P_0c035580;
case 0x0c035582u: goto P_0c035582;
case 0x0c035584u: goto P_0c035584;
case 0x0c035586u: goto P_0c035586;
case 0x0c035588u: goto P_0c035588;
case 0x0c03558au: goto P_0c03558a;
case 0x0c03558cu: goto P_0c03558c;
case 0x0c03746au: goto P_0c03746a;
case 0x0c03746cu: goto P_0c03746c;
case 0x0c03746eu: goto P_0c03746e;
case 0x0c037470u: goto P_0c037470;
case 0x0c037472u: goto P_0c037472;
case 0x0c037474u: goto P_0c037474;
case 0x0c037476u: goto P_0c037476;
case 0x0c037478u: goto P_0c037478;
case 0x0c03747au: goto P_0c03747a;
case 0x0c03747cu: goto P_0c03747c;
case 0x0c03747eu: goto P_0c03747e;
case 0x0c037480u: goto P_0c037480;
case 0x0c037482u: goto P_0c037482;
case 0x0c037484u: goto P_0c037484;
case 0x0c037486u: goto P_0c037486;
case 0x0c037488u: goto P_0c037488;
case 0x0c03748au: goto P_0c03748a;
case 0x0c03748cu: goto P_0c03748c;
case 0x0c03748eu: goto P_0c03748e;
case 0x0c037490u: goto P_0c037490;
case 0x0c037492u: goto P_0c037492;
case 0x0c037494u: goto P_0c037494;
case 0x0c037496u: goto P_0c037496;
case 0x0c037498u: goto P_0c037498;
case 0x0c03749au: goto P_0c03749a;
case 0x0c03749cu: goto P_0c03749c;
case 0x0c03749eu: goto P_0c03749e;
case 0x0c0374a0u: goto P_0c0374a0;
case 0x0c0374a2u: goto P_0c0374a2;
case 0x0c0374a4u: goto P_0c0374a4;
case 0x0c0374a6u: goto P_0c0374a6;
case 0x0c0374a8u: goto P_0c0374a8;
case 0x0c0374aau: goto P_0c0374aa;
case 0x0c0374acu: goto P_0c0374ac;
case 0x0c0374aeu: goto P_0c0374ae;
case 0x0c0374b0u: goto P_0c0374b0;
case 0x0c0374b2u: goto P_0c0374b2;
case 0x0c0374b4u: goto P_0c0374b4;
case 0x0c0374b6u: goto P_0c0374b6;
case 0x0c0374b8u: goto P_0c0374b8;
case 0x0c0374bau: goto P_0c0374ba;
case 0x0c0374bcu: goto P_0c0374bc;
case 0x0c0374beu: goto P_0c0374be;
case 0x0c0374c0u: goto P_0c0374c0;
case 0x0c0374c2u: goto P_0c0374c2;
case 0x0c0374c4u: goto P_0c0374c4;
case 0x0c0374c6u: goto P_0c0374c6;
case 0x0c0374c8u: goto P_0c0374c8;
case 0x0c0374cau: goto P_0c0374ca;
case 0x0c0374ccu: goto P_0c0374cc;
case 0x0c0374ceu: goto P_0c0374ce;
case 0x0c0374d0u: goto P_0c0374d0;
case 0x0c0374d2u: goto P_0c0374d2;
case 0x0c0374d4u: goto P_0c0374d4;
case 0x0c0374d6u: goto P_0c0374d6;
case 0x0c0374d8u: goto P_0c0374d8;
case 0x0c0374dau: goto P_0c0374da;
case 0x0c0374dcu: goto P_0c0374dc;
case 0x0c0374deu: goto P_0c0374de;
case 0x0c0374e0u: goto P_0c0374e0;
case 0x0c0374e2u: goto P_0c0374e2;
case 0x0c0374e4u: goto P_0c0374e4;
case 0x0c0374e6u: goto P_0c0374e6;
case 0x0c0374e8u: goto P_0c0374e8;
case 0x0c0374eau: goto P_0c0374ea;
case 0x0c0374ecu: goto P_0c0374ec;
case 0x0c0374eeu: goto P_0c0374ee;
case 0x0c0374f0u: goto P_0c0374f0;
case 0x0c0374f2u: goto P_0c0374f2;
case 0x0c0374f4u: goto P_0c0374f4;
case 0x0c0374f6u: goto P_0c0374f6;
case 0x0c0374f8u: goto P_0c0374f8;
case 0x0c0374fau: goto P_0c0374fa;
case 0x0c0374fcu: goto P_0c0374fc;
case 0x0c0374feu: goto P_0c0374fe;
case 0x0c037500u: goto P_0c037500;
case 0x0c0377a8u: goto P_0c0377a8;
case 0x0c0377aau: goto P_0c0377aa;
case 0x0c0377acu: goto P_0c0377ac;
case 0x0c0377aeu: goto P_0c0377ae;
case 0x0c0377b0u: goto P_0c0377b0;
case 0x0c0377b2u: goto P_0c0377b2;
case 0x0c0377b4u: goto P_0c0377b4;
case 0x0c0377b6u: goto P_0c0377b6;
case 0x0c0377b8u: goto P_0c0377b8;
case 0x0c0377bau: goto P_0c0377ba;
case 0x0c0377bcu: goto P_0c0377bc;
case 0x0c0377beu: goto P_0c0377be;
case 0x0c0377c0u: goto P_0c0377c0;
case 0x0c0377c2u: goto P_0c0377c2;
case 0x0c0377c4u: goto P_0c0377c4;
case 0x0c0377c6u: goto P_0c0377c6;
case 0x0c0377c8u: goto P_0c0377c8;
case 0x0c0377cau: goto P_0c0377ca;
case 0x0c0377ccu: goto P_0c0377cc;
case 0x0c0377ceu: goto P_0c0377ce;
case 0x0c0377d0u: goto P_0c0377d0;
case 0x0c0377d2u: goto P_0c0377d2;
case 0x0c0377d4u: goto P_0c0377d4;
case 0x0c0377d6u: goto P_0c0377d6;
case 0x0c0377d8u: goto P_0c0377d8;
case 0x0c0377dau: goto P_0c0377da;
case 0x0c0377dcu: goto P_0c0377dc;
case 0x0c0377deu: goto P_0c0377de;
case 0x0c0377e0u: goto P_0c0377e0;
case 0x0c0377e2u: goto P_0c0377e2;
case 0x0c0377e4u: goto P_0c0377e4;
case 0x0c0377e6u: goto P_0c0377e6;
case 0x0c0377e8u: goto P_0c0377e8;
case 0x0c0377eau: goto P_0c0377ea;
case 0x0c0377ecu: goto P_0c0377ec;
case 0x0c0377eeu: goto P_0c0377ee;
case 0x0c0377f0u: goto P_0c0377f0;
case 0x0c0377f2u: goto P_0c0377f2;
case 0x0c0377f4u: goto P_0c0377f4;
case 0x0c0377f6u: goto P_0c0377f6;
case 0x0c0377f8u: goto P_0c0377f8;
case 0x0c0377fau: goto P_0c0377fa;
case 0x0c03780cu: goto P_0c03780c;
case 0x0c03780eu: goto P_0c03780e;
case 0x0c037810u: goto P_0c037810;
case 0x0c037812u: goto P_0c037812;
case 0x0c037814u: goto P_0c037814;
case 0x0c037816u: goto P_0c037816;
case 0x0c037818u: goto P_0c037818;
case 0x0c03781au: goto P_0c03781a;
case 0x0c03781cu: goto P_0c03781c;
case 0x0c03781eu: goto P_0c03781e;
case 0x0c037820u: goto P_0c037820;
case 0x0c037822u: goto P_0c037822;
case 0x0c037824u: goto P_0c037824;
case 0x0c037826u: goto P_0c037826;
case 0x0c037828u: goto P_0c037828;
case 0x0c03782au: goto P_0c03782a;
case 0x0c03782cu: goto P_0c03782c;
case 0x0c03782eu: goto P_0c03782e;
case 0x0c037830u: goto P_0c037830;
case 0x0c037832u: goto P_0c037832;
case 0x0c037834u: goto P_0c037834;
case 0x0c037836u: goto P_0c037836;
case 0x0c037838u: goto P_0c037838;
case 0x0c03783au: goto P_0c03783a;
case 0x0c03783cu: goto P_0c03783c;
case 0x0c03783eu: goto P_0c03783e;
case 0x0c037840u: goto P_0c037840;
case 0x0c037842u: goto P_0c037842;
case 0x0c037844u: goto P_0c037844;
case 0x0c037846u: goto P_0c037846;
case 0x0c037848u: goto P_0c037848;
case 0x0c03784au: goto P_0c03784a;
case 0x0c03784cu: goto P_0c03784c;
case 0x0c03784eu: goto P_0c03784e;
case 0x0c037850u: goto P_0c037850;
case 0x0c037852u: goto P_0c037852;
case 0x0c037854u: goto P_0c037854;
case 0x0c037856u: goto P_0c037856;
case 0x0c03bbd2u: goto P_0c03bbd2;
case 0x0c03bbd4u: goto P_0c03bbd4;
case 0x0c03bbd6u: goto P_0c03bbd6;
case 0x0c03bbd8u: goto P_0c03bbd8;
case 0x0c03bbdau: goto P_0c03bbda;
case 0x0c03bbdcu: goto P_0c03bbdc;
case 0x0c03bbdeu: goto P_0c03bbde;
case 0x0c03bbe0u: goto P_0c03bbe0;
case 0x0c03bbe2u: goto P_0c03bbe2;
case 0x0c03bbe4u: goto P_0c03bbe4;
case 0x0c03bbe6u: goto P_0c03bbe6;
case 0x0c03bbe8u: goto P_0c03bbe8;
case 0x0c03bbeau: goto P_0c03bbea;
case 0x0c03bbecu: goto P_0c03bbec;
case 0x0c03bbeeu: goto P_0c03bbee;
case 0x0c03bbf0u: goto P_0c03bbf0;
case 0x0c03bbf2u: goto P_0c03bbf2;
case 0x0c03bbf4u: goto P_0c03bbf4;
case 0x0c03bbf6u: goto P_0c03bbf6;
case 0x0c03bbf8u: goto P_0c03bbf8;
case 0x0c03bbfau: goto P_0c03bbfa;
case 0x0c03bbfcu: goto P_0c03bbfc;
case 0x0c03bbfeu: goto P_0c03bbfe;
case 0x0c03bc00u: goto P_0c03bc00;
case 0x0c03bc02u: goto P_0c03bc02;
case 0x0c03bc04u: goto P_0c03bc04;
case 0x0c03bc06u: goto P_0c03bc06;
case 0x0c03bc08u: goto P_0c03bc08;
case 0x0c03bc0au: goto P_0c03bc0a;
case 0x0c03bc0cu: goto P_0c03bc0c;
case 0x0c03bc0eu: goto P_0c03bc0e;
case 0x0c03bc10u: goto P_0c03bc10;
case 0x0c03bc12u: goto P_0c03bc12;
case 0x0c03bc14u: goto P_0c03bc14;
case 0x0c03bc16u: goto P_0c03bc16;
case 0x0c03bc18u: goto P_0c03bc18;
case 0x0c03bc1au: goto P_0c03bc1a;
case 0x0c03bc1cu: goto P_0c03bc1c;
case 0x0c03bc1eu: goto P_0c03bc1e;
case 0x0c03bc20u: goto P_0c03bc20;
case 0x0c03bc22u: goto P_0c03bc22;
case 0x0c03bc24u: goto P_0c03bc24;
case 0x0c03bc26u: goto P_0c03bc26;
case 0x0c03bc28u: goto P_0c03bc28;
case 0x0c03bc2au: goto P_0c03bc2a;
case 0x0c03bc2cu: goto P_0c03bc2c;
case 0x0c03bc2eu: goto P_0c03bc2e;
case 0x0c03bc30u: goto P_0c03bc30;
case 0x0c03bc32u: goto P_0c03bc32;
case 0x0c03bc34u: goto P_0c03bc34;
case 0x0c03bc36u: goto P_0c03bc36;
case 0x0c03bc38u: goto P_0c03bc38;
case 0x0c03bc3au: goto P_0c03bc3a;
case 0x0c03bc3cu: goto P_0c03bc3c;
case 0x0c03bc3eu: goto P_0c03bc3e;
case 0x0c03bc40u: goto P_0c03bc40;
case 0x0c03bc42u: goto P_0c03bc42;
case 0x0c03bc44u: goto P_0c03bc44;
case 0x0c03bc46u: goto P_0c03bc46;
case 0x0c03bc48u: goto P_0c03bc48;
case 0x0c03bc4au: goto P_0c03bc4a;
case 0x0c03bc4cu: goto P_0c03bc4c;
case 0x0c03bc4eu: goto P_0c03bc4e;
case 0x0c03bc50u: goto P_0c03bc50;
case 0x0c03bc52u: goto P_0c03bc52;
case 0x0c03bc54u: goto P_0c03bc54;
case 0x0c03bc56u: goto P_0c03bc56;
case 0x0c03bc58u: goto P_0c03bc58;
case 0x0c03bc5au: goto P_0c03bc5a;
case 0x0c03bc5cu: goto P_0c03bc5c;
case 0x0c03bc5eu: goto P_0c03bc5e;
case 0x0c03bc60u: goto P_0c03bc60;
case 0x0c03bc62u: goto P_0c03bc62;
case 0x0c03bc64u: goto P_0c03bc64;
case 0x0c03bc66u: goto P_0c03bc66;
case 0x0c03bc68u: goto P_0c03bc68;
case 0x0c03bc6au: goto P_0c03bc6a;
case 0x0c03bc6cu: goto P_0c03bc6c;
case 0x0c03bc6eu: goto P_0c03bc6e;
case 0x0c03bc70u: goto P_0c03bc70;
case 0x0c03bc72u: goto P_0c03bc72;
case 0x0c03bc74u: goto P_0c03bc74;
case 0x0c03bc76u: goto P_0c03bc76;
case 0x0c03bc78u: goto P_0c03bc78;
case 0x0c03bc7au: goto P_0c03bc7a;
case 0x0c03bc7cu: goto P_0c03bc7c;
case 0x0c03bc7eu: goto P_0c03bc7e;
case 0x0c03bc80u: goto P_0c03bc80;
case 0x0c03bc82u: goto P_0c03bc82;
case 0x0c03bc84u: goto P_0c03bc84;
case 0x0c03bc86u: goto P_0c03bc86;
case 0x0c03bc88u: goto P_0c03bc88;
case 0x0c03bc8au: goto P_0c03bc8a;
case 0x0c03bc8cu: goto P_0c03bc8c;
case 0x0c03bc8eu: goto P_0c03bc8e;
case 0x0c03bc90u: goto P_0c03bc90;
case 0x0c03bc92u: goto P_0c03bc92;
case 0x0c042672u: goto P_0c042672;
case 0x0c042674u: goto P_0c042674;
case 0x0c042676u: goto P_0c042676;
case 0x0c042678u: goto P_0c042678;
case 0x0c04267au: goto P_0c04267a;
case 0x0c04267cu: goto P_0c04267c;
case 0x0c04267eu: goto P_0c04267e;
case 0x0c042680u: goto P_0c042680;
case 0x0c042682u: goto P_0c042682;
case 0x0c042684u: goto P_0c042684;
case 0x0c042686u: goto P_0c042686;
case 0x0c042688u: goto P_0c042688;
case 0x0c04268au: goto P_0c04268a;
case 0x0c04268cu: goto P_0c04268c;
case 0x0c04268eu: goto P_0c04268e;
case 0x0c042690u: goto P_0c042690;
case 0x0c042692u: goto P_0c042692;
case 0x0c042694u: goto P_0c042694;
case 0x0c042696u: goto P_0c042696;
case 0x0c042698u: goto P_0c042698;
case 0x0c04269au: goto P_0c04269a;
case 0x0c04269cu: goto P_0c04269c;
case 0x0c04269eu: goto P_0c04269e;
case 0x0c0426a0u: goto P_0c0426a0;
case 0x0c0426a2u: goto P_0c0426a2;
case 0x0c0426a4u: goto P_0c0426a4;
case 0x0c0426a6u: goto P_0c0426a6;
case 0x0c0426a8u: goto P_0c0426a8;
case 0x0c0426aau: goto P_0c0426aa;
case 0x0c0426acu: goto P_0c0426ac;
case 0x0c0426aeu: goto P_0c0426ae;
case 0x0c0426b0u: goto P_0c0426b0;
case 0x0c0426b2u: goto P_0c0426b2;
case 0x0c0426b4u: goto P_0c0426b4;
case 0x0c0426b6u: goto P_0c0426b6;
case 0x0c0426b8u: goto P_0c0426b8;
case 0x0c0426bau: goto P_0c0426ba;
case 0x0c0426c0u: goto P_0c0426c0;
case 0x0c0426c2u: goto P_0c0426c2;
case 0x0c0426c4u: goto P_0c0426c4;
case 0x0c0426c6u: goto P_0c0426c6;
case 0x0c0426d0u: goto P_0c0426d0;
case 0x0c0426d2u: goto P_0c0426d2;
case 0x0c0426d4u: goto P_0c0426d4;
case 0x0c0426d6u: goto P_0c0426d6;
case 0x0c0426d8u: goto P_0c0426d8;
case 0x0c0426dau: goto P_0c0426da;
case 0x0c0426dcu: goto P_0c0426dc;
case 0x0c0426deu: goto P_0c0426de;
case 0x0c0426e0u: goto P_0c0426e0;
case 0x0c0426e2u: goto P_0c0426e2;
case 0x0c0426e4u: goto P_0c0426e4;
case 0x0c0426e6u: goto P_0c0426e6;
case 0x0c0426e8u: goto P_0c0426e8;
case 0x0c0426eau: goto P_0c0426ea;
case 0x0c0426ecu: goto P_0c0426ec;
case 0x0c0426eeu: goto P_0c0426ee;
case 0x0c0426f0u: goto P_0c0426f0;
case 0x0c0426f2u: goto P_0c0426f2;
case 0x0c0426f4u: goto P_0c0426f4;
case 0x0c0426f6u: goto P_0c0426f6;
case 0x0c0426f8u: goto P_0c0426f8;
case 0x0c0426fau: goto P_0c0426fa;
case 0x0c0426fcu: goto P_0c0426fc;
case 0x0c0426feu: goto P_0c0426fe;
case 0x0c042700u: goto P_0c042700;
case 0x0c042702u: goto P_0c042702;
case 0x0c042704u: goto P_0c042704;
case 0x0c042706u: goto P_0c042706;
case 0x0c042708u: goto P_0c042708;
case 0x0c04270au: goto P_0c04270a;
case 0x0c04270cu: goto P_0c04270c;
case 0x0c04270eu: goto P_0c04270e;
case 0x0c042710u: goto P_0c042710;
case 0x0c042740u: goto P_0c042740;
case 0x0c042742u: goto P_0c042742;
case 0x0c042744u: goto P_0c042744;
case 0x0c042746u: goto P_0c042746;
case 0x0c042748u: goto P_0c042748;
case 0x0c04274au: goto P_0c04274a;
case 0x0c04274cu: goto P_0c04274c;
case 0x0c04274eu: goto P_0c04274e;
case 0x0c042750u: goto P_0c042750;
case 0x0c042752u: goto P_0c042752;
case 0x0c042754u: goto P_0c042754;
case 0x0c042756u: goto P_0c042756;
case 0x0c042758u: goto P_0c042758;
case 0x0c04275au: goto P_0c04275a;
case 0x0c04275cu: goto P_0c04275c;
case 0x0c04275eu: goto P_0c04275e;
case 0x0c042760u: goto P_0c042760;
case 0x0c042762u: goto P_0c042762;
case 0x0c042764u: goto P_0c042764;
case 0x0c042766u: goto P_0c042766;
case 0x0c042768u: goto P_0c042768;
case 0x0c04276au: goto P_0c04276a;
case 0x0c04276cu: goto P_0c04276c;
case 0x0c04276eu: goto P_0c04276e;
case 0x0c042770u: goto P_0c042770;
case 0x0c042772u: goto P_0c042772;
case 0x0c042774u: goto P_0c042774;
case 0x0c042776u: goto P_0c042776;
case 0x0c042778u: goto P_0c042778;
case 0x0c04277au: goto P_0c04277a;
case 0x0c04277cu: goto P_0c04277c;
case 0x0c04277eu: goto P_0c04277e;
case 0x0c042780u: goto P_0c042780;
case 0x0c042782u: goto P_0c042782;
case 0x0c042784u: goto P_0c042784;
case 0x0c042786u: goto P_0c042786;
case 0x0c04326cu: goto P_0c04326c;
case 0x0c04326eu: goto P_0c04326e;
case 0x0c043270u: goto P_0c043270;
case 0x0c043272u: goto P_0c043272;
case 0x0c043274u: goto P_0c043274;
case 0x0c043276u: goto P_0c043276;
case 0x0c043278u: goto P_0c043278;
case 0x0c04327au: goto P_0c04327a;
case 0x0c04327cu: goto P_0c04327c;
case 0x0c04327eu: goto P_0c04327e;
case 0x0c043280u: goto P_0c043280;
case 0x0c043282u: goto P_0c043282;
case 0x0c043284u: goto P_0c043284;
case 0x0c0432e2u: goto P_0c0432e2;
case 0x0c0432e4u: goto P_0c0432e4;
case 0x0c0432e6u: goto P_0c0432e6;
case 0x0c0432e8u: goto P_0c0432e8;
case 0x0c0432eau: goto P_0c0432ea;
case 0x0c0432ecu: goto P_0c0432ec;
case 0x0c0432eeu: goto P_0c0432ee;
case 0x0c0432f0u: goto P_0c0432f0;
case 0x0c0432f2u: goto P_0c0432f2;
case 0x0c0432f4u: goto P_0c0432f4;
case 0x0c0432f6u: goto P_0c0432f6;
case 0x0c0432f8u: goto P_0c0432f8;
case 0x0c0432fau: goto P_0c0432fa;
case 0x0c0432fcu: goto P_0c0432fc;
case 0x0c0432feu: goto P_0c0432fe;
case 0x0c043300u: goto P_0c043300;
case 0x0c043302u: goto P_0c043302;
case 0x0c043304u: goto P_0c043304;
case 0x0c043306u: goto P_0c043306;
case 0x0c043308u: goto P_0c043308;
case 0x0c04330au: goto P_0c04330a;
case 0x0c04330cu: goto P_0c04330c;
case 0x0c04330eu: goto P_0c04330e;
case 0x0c043310u: goto P_0c043310;
case 0x0c043312u: goto P_0c043312;
case 0x0c043314u: goto P_0c043314;
case 0x0c043316u: goto P_0c043316;
case 0x0c043318u: goto P_0c043318;
case 0x0c04331au: goto P_0c04331a;
case 0x0c04331cu: goto P_0c04331c;
case 0x0c04331eu: goto P_0c04331e;
case 0x0c043320u: goto P_0c043320;
case 0x0c043322u: goto P_0c043322;
case 0x0c043324u: goto P_0c043324;
case 0x0c043344u: goto P_0c043344;
case 0x0c043346u: goto P_0c043346;
case 0x0c043348u: goto P_0c043348;
case 0x0c04334au: goto P_0c04334a;
case 0x0c04334cu: goto P_0c04334c;
case 0x0c04334eu: goto P_0c04334e;
case 0x0c043350u: goto P_0c043350;
case 0x0c043352u: goto P_0c043352;
case 0x0c043354u: goto P_0c043354;
case 0x0c043356u: goto P_0c043356;
case 0x0c043358u: goto P_0c043358;
case 0x0c04335au: goto P_0c04335a;
case 0x0c04335cu: goto P_0c04335c;
case 0x0c0433aeu: goto P_0c0433ae;
case 0x0c0433b0u: goto P_0c0433b0;
case 0x0c0433b2u: goto P_0c0433b2;
case 0x0c0433b4u: goto P_0c0433b4;
case 0x0c0433b6u: goto P_0c0433b6;
case 0x0c0433b8u: goto P_0c0433b8;
case 0x0c0433bau: goto P_0c0433ba;
case 0x0c0433c6u: goto P_0c0433c6;
case 0x0c0433c8u: goto P_0c0433c8;
case 0x0c0433cau: goto P_0c0433ca;
case 0x0c0433ccu: goto P_0c0433cc;
case 0x0c0433ceu: goto P_0c0433ce;
case 0x0c0433d0u: goto P_0c0433d0;
case 0x0c0433d2u: goto P_0c0433d2;
case 0x0c0433d4u: goto P_0c0433d4;
case 0x0c0433d6u: goto P_0c0433d6;
case 0x0c0433d8u: goto P_0c0433d8;
case 0x0c0433dau: goto P_0c0433da;
case 0x0c0433dcu: goto P_0c0433dc;
case 0x0c0433deu: goto P_0c0433de;
case 0x0c0433e0u: goto P_0c0433e0;
case 0x0c0433e2u: goto P_0c0433e2;
case 0x0c0433e4u: goto P_0c0433e4;
case 0x0c0433e6u: goto P_0c0433e6;
case 0x0c0433e8u: goto P_0c0433e8;
case 0x0c0433eau: goto P_0c0433ea;
case 0x0c0433ecu: goto P_0c0433ec;
case 0x0c0433eeu: goto P_0c0433ee;
case 0x0c04340cu: goto P_0c04340c;
case 0x0c04340eu: goto P_0c04340e;
case 0x0c043410u: goto P_0c043410;
case 0x0c043412u: goto P_0c043412;
case 0x0c043414u: goto P_0c043414;
case 0x0c043416u: goto P_0c043416;
case 0x0c043418u: goto P_0c043418;
case 0x0c04341eu: goto P_0c04341e;
case 0x0c043420u: goto P_0c043420;
case 0x0c043422u: goto P_0c043422;
case 0x0c043424u: goto P_0c043424;
case 0x0c043426u: goto P_0c043426;
case 0x0c043428u: goto P_0c043428;
case 0x0c04342au: goto P_0c04342a;
case 0x0c04342cu: goto P_0c04342c;
case 0x0c04342eu: goto P_0c04342e;
case 0x0c043430u: goto P_0c043430;
case 0x0c043432u: goto P_0c043432;
case 0x0c043434u: goto P_0c043434;
case 0x0c043436u: goto P_0c043436;
case 0x0c043438u: goto P_0c043438;
case 0x0c04343au: goto P_0c04343a;
case 0x0c043440u: goto P_0c043440;
case 0x0c043442u: goto P_0c043442;
case 0x0c043444u: goto P_0c043444;
case 0x0c043446u: goto P_0c043446;
case 0x0c043448u: goto P_0c043448;
case 0x0c04344au: goto P_0c04344a;
case 0x0c04344cu: goto P_0c04344c;
case 0x0c04344eu: goto P_0c04344e;
case 0x0c043450u: goto P_0c043450;
case 0x0c043452u: goto P_0c043452;
case 0x0c043454u: goto P_0c043454;
case 0x0c043456u: goto P_0c043456;
case 0x0c043458u: goto P_0c043458;
case 0x0c04345au: goto P_0c04345a;
case 0x0c04345cu: goto P_0c04345c;
case 0x0c04345eu: goto P_0c04345e;
case 0x0c043460u: goto P_0c043460;
case 0x0c043462u: goto P_0c043462;
case 0x0c043464u: goto P_0c043464;
case 0x0c043466u: goto P_0c043466;
case 0x0c043468u: goto P_0c043468;
case 0x0c04346au: goto P_0c04346a;
case 0x0c04346cu: goto P_0c04346c;
case 0x0c043472u: goto P_0c043472;
case 0x0c043474u: goto P_0c043474;
case 0x0c043476u: goto P_0c043476;
case 0x0c043478u: goto P_0c043478;
case 0x0c04347au: goto P_0c04347a;
case 0x0c04347cu: goto P_0c04347c;
case 0x0c04347eu: goto P_0c04347e;
case 0x0c043480u: goto P_0c043480;
case 0x0c043482u: goto P_0c043482;
case 0x0c043484u: goto P_0c043484;
case 0x0c043486u: goto P_0c043486;
case 0x0c043488u: goto P_0c043488;
case 0x0c04348au: goto P_0c04348a;
case 0x0c04348eu: goto P_0c04348e;
case 0x0c043490u: goto P_0c043490;
case 0x0c043492u: goto P_0c043492;
case 0x0c043494u: goto P_0c043494;
case 0x0c043496u: goto P_0c043496;
case 0x0c043498u: goto P_0c043498;
case 0x0c04349au: goto P_0c04349a;
case 0x0c04349cu: goto P_0c04349c;
case 0x0c04349eu: goto P_0c04349e;
case 0x0c0434a0u: goto P_0c0434a0;
case 0x0c0434a2u: goto P_0c0434a2;
case 0x0c0434a4u: goto P_0c0434a4;
case 0x0c0434a6u: goto P_0c0434a6;
case 0x0c0434aau: goto P_0c0434aa;
case 0x0c0434acu: goto P_0c0434ac;
case 0x0c0434aeu: goto P_0c0434ae;
case 0x0c0434b0u: goto P_0c0434b0;
case 0x0c0434b2u: goto P_0c0434b2;
case 0x0c0434b4u: goto P_0c0434b4;
case 0x0c0434b6u: goto P_0c0434b6;
case 0x0c0434b8u: goto P_0c0434b8;
case 0x0c0434bau: goto P_0c0434ba;
case 0x0c0434bcu: goto P_0c0434bc;
case 0x0c0434beu: goto P_0c0434be;
case 0x0c0434c0u: goto P_0c0434c0;
case 0x0c0434c2u: goto P_0c0434c2;
case 0x0c0434c4u: goto P_0c0434c4;
case 0x0c0434c6u: goto P_0c0434c6;
case 0x0c047230u: goto P_0c047230;
case 0x0c047232u: goto P_0c047232;
case 0x0c047234u: goto P_0c047234;
case 0x0c047236u: goto P_0c047236;
case 0x0c047238u: goto P_0c047238;
case 0x0c04723au: goto P_0c04723a;
case 0x0c04723cu: goto P_0c04723c;
case 0x0c04723eu: goto P_0c04723e;
case 0x0c047240u: goto P_0c047240;
case 0x0c047242u: goto P_0c047242;
case 0x0c047244u: goto P_0c047244;
case 0x0c047246u: goto P_0c047246;
case 0x0c047248u: goto P_0c047248;
case 0x0c04724au: goto P_0c04724a;
case 0x0c04724cu: goto P_0c04724c;
case 0x0c04724eu: goto P_0c04724e;
case 0x0c047250u: goto P_0c047250;
case 0x0c047252u: goto P_0c047252;
case 0x0c047254u: goto P_0c047254;
case 0x0c047256u: goto P_0c047256;
case 0x0c047258u: goto P_0c047258;
case 0x0c04725au: goto P_0c04725a;
case 0x0c04725cu: goto P_0c04725c;
case 0x0c04725eu: goto P_0c04725e;
case 0x0c047260u: goto P_0c047260;
case 0x0c047262u: goto P_0c047262;
case 0x0c047264u: goto P_0c047264;
case 0x0c047266u: goto P_0c047266;
case 0x0c047268u: goto P_0c047268;
case 0x0c04726au: goto P_0c04726a;
case 0x0c04726cu: goto P_0c04726c;
case 0x0c04726eu: goto P_0c04726e;
case 0x0c047270u: goto P_0c047270;
case 0x0c047272u: goto P_0c047272;
case 0x0c047274u: goto P_0c047274;
case 0x0c047276u: goto P_0c047276;
case 0x0c047278u: goto P_0c047278;
case 0x0c04727au: goto P_0c04727a;
case 0x0c04727cu: goto P_0c04727c;
case 0x0c04727eu: goto P_0c04727e;
case 0x0c047280u: goto P_0c047280;
case 0x0c047282u: goto P_0c047282;
case 0x0c047284u: goto P_0c047284;
case 0x0c047286u: goto P_0c047286;
case 0x0c047288u: goto P_0c047288;
case 0x0c04728au: goto P_0c04728a;
case 0x0c04728cu: goto P_0c04728c;
case 0x0c0482f0u: goto P_0c0482f0;
case 0x0c0482f2u: goto P_0c0482f2;
case 0x0c0482f4u: goto P_0c0482f4;
case 0x0c0482f6u: goto P_0c0482f6;
case 0x0c0482f8u: goto P_0c0482f8;
case 0x0c0482fau: goto P_0c0482fa;
case 0x0c0482fcu: goto P_0c0482fc;
case 0x0c0482feu: goto P_0c0482fe;
case 0x0c048300u: goto P_0c048300;
case 0x0c048302u: goto P_0c048302;
case 0x0c048304u: goto P_0c048304;
case 0x0c048306u: goto P_0c048306;
case 0x0c048308u: goto P_0c048308;
case 0x0c04830au: goto P_0c04830a;
case 0x0c04830cu: goto P_0c04830c;
case 0x0c04830eu: goto P_0c04830e;
case 0x0c048310u: goto P_0c048310;
case 0x0c048312u: goto P_0c048312;
case 0x0c048314u: goto P_0c048314;
case 0x0c048316u: goto P_0c048316;
case 0x0c048318u: goto P_0c048318;
case 0x0c04831au: goto P_0c04831a;
case 0x0c04831cu: goto P_0c04831c;
case 0x0c04831eu: goto P_0c04831e;
case 0x0c048320u: goto P_0c048320;
case 0x0c048322u: goto P_0c048322;
case 0x0c048324u: goto P_0c048324;
case 0x0c048326u: goto P_0c048326;
case 0x0c048328u: goto P_0c048328;
case 0x0c04832au: goto P_0c04832a;
case 0x0c04832cu: goto P_0c04832c;
case 0x0c04832eu: goto P_0c04832e;
case 0x0c048330u: goto P_0c048330;
case 0x0c048332u: goto P_0c048332;
case 0x0c048334u: goto P_0c048334;
case 0x0c048336u: goto P_0c048336;
case 0x0c048338u: goto P_0c048338;
case 0x0c04833au: goto P_0c04833a;
case 0x0c04833cu: goto P_0c04833c;
case 0x0c04833eu: goto P_0c04833e;
case 0x0c048340u: goto P_0c048340;
case 0x0c048342u: goto P_0c048342;
case 0x0c048344u: goto P_0c048344;
case 0x0c048346u: goto P_0c048346;
case 0x0c048348u: goto P_0c048348;
case 0x0c04834au: goto P_0c04834a;
case 0x0c04834cu: goto P_0c04834c;
case 0x0c04834eu: goto P_0c04834e;
case 0x0c048350u: goto P_0c048350;
case 0x0c048352u: goto P_0c048352;
case 0x0c048354u: goto P_0c048354;
case 0x0c048356u: goto P_0c048356;
case 0x0c048358u: goto P_0c048358;
case 0x0c04835au: goto P_0c04835a;
case 0x0c04835cu: goto P_0c04835c;
case 0x0c04835eu: goto P_0c04835e;
case 0x0c048360u: goto P_0c048360;
case 0x0c048362u: goto P_0c048362;
case 0x0c048364u: goto P_0c048364;
case 0x0c048366u: goto P_0c048366;
case 0x0c048368u: goto P_0c048368;
case 0x0c04836au: goto P_0c04836a;
case 0x0c04836cu: goto P_0c04836c;
case 0x0c04836eu: goto P_0c04836e;
case 0x0c048370u: goto P_0c048370;
case 0x0c048372u: goto P_0c048372;
case 0x0c048374u: goto P_0c048374;
case 0x0c048376u: goto P_0c048376;
case 0x0c048378u: goto P_0c048378;
case 0x0c04837au: goto P_0c04837a;
case 0x0c04837cu: goto P_0c04837c;
case 0x0c04837eu: goto P_0c04837e;
case 0x0c048380u: goto P_0c048380;
case 0x0c048382u: goto P_0c048382;
case 0x0c048384u: goto P_0c048384;
case 0x0c048386u: goto P_0c048386;
case 0x0c048388u: goto P_0c048388;
case 0x0c04838au: goto P_0c04838a;
case 0x0c04838cu: goto P_0c04838c;
case 0x0c04838eu: goto P_0c04838e;
case 0x0c048390u: goto P_0c048390;
case 0x0c048392u: goto P_0c048392;
case 0x0c048394u: goto P_0c048394;
case 0x0c048396u: goto P_0c048396;
case 0x0c048398u: goto P_0c048398;
case 0x0c04839au: goto P_0c04839a;
case 0x0c04839cu: goto P_0c04839c;
case 0x0c0483a0u: goto P_0c0483a0;
case 0x0c0483a2u: goto P_0c0483a2;
case 0x0c0483a4u: goto P_0c0483a4;
case 0x0c0483a6u: goto P_0c0483a6;
case 0x0c0483a8u: goto P_0c0483a8;
case 0x0c0483aau: goto P_0c0483aa;
case 0x0c0483acu: goto P_0c0483ac;
case 0x0c0483aeu: goto P_0c0483ae;
case 0x0c0483b0u: goto P_0c0483b0;
case 0x0c0483b2u: goto P_0c0483b2;
case 0x0c0483b4u: goto P_0c0483b4;
case 0x0c0483b6u: goto P_0c0483b6;
case 0x0c0483b8u: goto P_0c0483b8;
case 0x0c0483bau: goto P_0c0483ba;
case 0x0c0483bcu: goto P_0c0483bc;
case 0x0c0483beu: goto P_0c0483be;
case 0x0c0483c0u: goto P_0c0483c0;
case 0x0c0483c2u: goto P_0c0483c2;
case 0x0c0483c4u: goto P_0c0483c4;
case 0x0c0483c6u: goto P_0c0483c6;
case 0x0c0483c8u: goto P_0c0483c8;
case 0x0c0483cau: goto P_0c0483ca;
case 0x0c0483ccu: goto P_0c0483cc;
case 0x0c0483ceu: goto P_0c0483ce;
case 0x0c0483d0u: goto P_0c0483d0;
case 0x0c0483d2u: goto P_0c0483d2;
case 0x0c0483d4u: goto P_0c0483d4;
case 0x0c0483d6u: goto P_0c0483d6;
case 0x0c0483d8u: goto P_0c0483d8;
case 0x0c0483dau: goto P_0c0483da;
case 0x0c0483dcu: goto P_0c0483dc;
case 0x0c0483deu: goto P_0c0483de;
case 0x0c0483e0u: goto P_0c0483e0;
case 0x0c0483e2u: goto P_0c0483e2;
case 0x0c0483e4u: goto P_0c0483e4;
case 0x0c0483e6u: goto P_0c0483e6;
case 0x0c0483e8u: goto P_0c0483e8;
case 0x0c0483eau: goto P_0c0483ea;
case 0x0c0483ecu: goto P_0c0483ec;
case 0x0c0483eeu: goto P_0c0483ee;
case 0x0c0483f0u: goto P_0c0483f0;
case 0x0c0483f2u: goto P_0c0483f2;
case 0x0c0483f4u: goto P_0c0483f4;
case 0x0c0483f6u: goto P_0c0483f6;
case 0x0c0483f8u: goto P_0c0483f8;
case 0x0c0483fau: goto P_0c0483fa;
case 0x0c0483fcu: goto P_0c0483fc;
case 0x0c0483feu: goto P_0c0483fe;
case 0x0c048400u: goto P_0c048400;
case 0x0c048402u: goto P_0c048402;
case 0x0c048404u: goto P_0c048404;
case 0x0c048408u: goto P_0c048408;
case 0x0c04840au: goto P_0c04840a;
case 0x0c04840cu: goto P_0c04840c;
case 0x0c04840eu: goto P_0c04840e;
case 0x0c048410u: goto P_0c048410;
case 0x0c048412u: goto P_0c048412;
case 0x0c048414u: goto P_0c048414;
case 0x0c048416u: goto P_0c048416;
case 0x0c048418u: goto P_0c048418;
case 0x0c04841au: goto P_0c04841a;
case 0x0c04841cu: goto P_0c04841c;
case 0x0c04841eu: goto P_0c04841e;
case 0x0c048420u: goto P_0c048420;
case 0x0c048422u: goto P_0c048422;
case 0x0c048424u: goto P_0c048424;
case 0x0c048426u: goto P_0c048426;
case 0x0c048428u: goto P_0c048428;
case 0x0c04842au: goto P_0c04842a;
case 0x0c04842cu: goto P_0c04842c;
case 0x0c04842eu: goto P_0c04842e;
case 0x0c048430u: goto P_0c048430;
case 0x0c048432u: goto P_0c048432;
case 0x0c048434u: goto P_0c048434;
case 0x0c048436u: goto P_0c048436;
case 0x0c048438u: goto P_0c048438;
case 0x0c04843au: goto P_0c04843a;
case 0x0c04843cu: goto P_0c04843c;
case 0x0c04843eu: goto P_0c04843e;
case 0x0c048440u: goto P_0c048440;
case 0x0c048442u: goto P_0c048442;
case 0x0c048444u: goto P_0c048444;
case 0x0c048446u: goto P_0c048446;
case 0x0c048448u: goto P_0c048448;
case 0x0c04844au: goto P_0c04844a;
case 0x0c04844cu: goto P_0c04844c;
case 0x0c04844eu: goto P_0c04844e;
case 0x0c048450u: goto P_0c048450;
case 0x0c048452u: goto P_0c048452;
case 0x0c048454u: goto P_0c048454;
case 0x0c048456u: goto P_0c048456;
case 0x0c048458u: goto P_0c048458;
case 0x0c04845au: goto P_0c04845a;
case 0x0c04845cu: goto P_0c04845c;
case 0x0c04845eu: goto P_0c04845e;
case 0x0c048460u: goto P_0c048460;
case 0x0c048462u: goto P_0c048462;
case 0x0c048464u: goto P_0c048464;
case 0x0c048466u: goto P_0c048466;
case 0x0c048468u: goto P_0c048468;
case 0x0c04846au: goto P_0c04846a;
case 0x0c04846cu: goto P_0c04846c;
case 0x0c04846eu: goto P_0c04846e;
case 0x0c048470u: goto P_0c048470;
case 0x0c048472u: goto P_0c048472;
case 0x0c048474u: goto P_0c048474;
case 0x0c048476u: goto P_0c048476;
case 0x0c048478u: goto P_0c048478;
case 0x0c04847au: goto P_0c04847a;
case 0x0c04847cu: goto P_0c04847c;
case 0x0c04847eu: goto P_0c04847e;
case 0x0c048480u: goto P_0c048480;
case 0x0c048482u: goto P_0c048482;
case 0x0c048484u: goto P_0c048484;
case 0x0c048486u: goto P_0c048486;
case 0x0c048488u: goto P_0c048488;
case 0x0c04848au: goto P_0c04848a;
case 0x0c04848cu: goto P_0c04848c;
case 0x0c04848eu: goto P_0c04848e;
case 0x0c048490u: goto P_0c048490;
case 0x0c048492u: goto P_0c048492;
case 0x0c048494u: goto P_0c048494;
case 0x0c048496u: goto P_0c048496;
case 0x0c048498u: goto P_0c048498;
case 0x0c04849au: goto P_0c04849a;
case 0x0c04849cu: goto P_0c04849c;
case 0x0c04849eu: goto P_0c04849e;
case 0x0c0484a0u: goto P_0c0484a0;
case 0x0c0484a2u: goto P_0c0484a2;
case 0x0c0484a4u: goto P_0c0484a4;
case 0x0c0484a8u: goto P_0c0484a8;
case 0x0c0484aau: goto P_0c0484aa;
case 0x0c0484acu: goto P_0c0484ac;
case 0x0c0484aeu: goto P_0c0484ae;
case 0x0c0484b0u: goto P_0c0484b0;
case 0x0c0484b2u: goto P_0c0484b2;
case 0x0c0484b4u: goto P_0c0484b4;
case 0x0c0484b6u: goto P_0c0484b6;
case 0x0c0484b8u: goto P_0c0484b8;
case 0x0c0484bau: goto P_0c0484ba;
case 0x0c0484bcu: goto P_0c0484bc;
case 0x0c0484beu: goto P_0c0484be;
case 0x0c0484c0u: goto P_0c0484c0;
case 0x0c0484c4u: goto P_0c0484c4;
case 0x0c0484c6u: goto P_0c0484c6;
case 0x0c0484c8u: goto P_0c0484c8;
case 0x0c0484cau: goto P_0c0484ca;
case 0x0c0484ccu: goto P_0c0484cc;
case 0x0c0484ceu: goto P_0c0484ce;
case 0x0c0484d0u: goto P_0c0484d0;
case 0x0c0484d2u: goto P_0c0484d2;
case 0x0c0484d4u: goto P_0c0484d4;
case 0x0c0484d6u: goto P_0c0484d6;
case 0x0c0484d8u: goto P_0c0484d8;
case 0x0c0484dau: goto P_0c0484da;
case 0x0c0484dcu: goto P_0c0484dc;
case 0x0c0484deu: goto P_0c0484de;
case 0x0c0484e0u: goto P_0c0484e0;
case 0x0c0484e2u: goto P_0c0484e2;
case 0x0c0484e4u: goto P_0c0484e4;
case 0x0c0484e6u: goto P_0c0484e6;
case 0x0c0484e8u: goto P_0c0484e8;
case 0x0c0484eau: goto P_0c0484ea;
case 0x0c0484ecu: goto P_0c0484ec;
case 0x0c0484eeu: goto P_0c0484ee;
case 0x0c0484f0u: goto P_0c0484f0;
case 0x0c0484f4u: goto P_0c0484f4;
case 0x0c0484f6u: goto P_0c0484f6;
case 0x0c0484f8u: goto P_0c0484f8;
case 0x0c0484fau: goto P_0c0484fa;
case 0x0c0484fcu: goto P_0c0484fc;
case 0x0c0484feu: goto P_0c0484fe;
case 0x0c048500u: goto P_0c048500;
case 0x0c048502u: goto P_0c048502;
case 0x0c048504u: goto P_0c048504;
case 0x0c048506u: goto P_0c048506;
case 0x0c048508u: goto P_0c048508;
case 0x0c04850au: goto P_0c04850a;
case 0x0c04850cu: goto P_0c04850c;
case 0x0c04850eu: goto P_0c04850e;
case 0x0c048510u: goto P_0c048510;
case 0x0c048512u: goto P_0c048512;
case 0x0c048514u: goto P_0c048514;
case 0x0c048516u: goto P_0c048516;
case 0x0c048518u: goto P_0c048518;
case 0x0c04851au: goto P_0c04851a;
case 0x0c04851cu: goto P_0c04851c;
case 0x0c04851eu: goto P_0c04851e;
case 0x0c048520u: goto P_0c048520;
case 0x0c048522u: goto P_0c048522;
case 0x0c048524u: goto P_0c048524;
case 0x0c048526u: goto P_0c048526;
case 0x0c048528u: goto P_0c048528;
case 0x0c04852au: goto P_0c04852a;
case 0x0c04852cu: goto P_0c04852c;
case 0x0c04852eu: goto P_0c04852e;
case 0x0c048530u: goto P_0c048530;
case 0x0c048532u: goto P_0c048532;
case 0x0c048534u: goto P_0c048534;
case 0x0c048536u: goto P_0c048536;
case 0x0c048538u: goto P_0c048538;
case 0x0c04853au: goto P_0c04853a;
case 0x0c04853cu: goto P_0c04853c;
case 0x0c04853eu: goto P_0c04853e;
case 0x0c048540u: goto P_0c048540;
case 0x0c048542u: goto P_0c048542;
case 0x0c048544u: goto P_0c048544;
case 0x0c048546u: goto P_0c048546;
case 0x0c048548u: goto P_0c048548;
case 0x0c04854au: goto P_0c04854a;
case 0x0c04854cu: goto P_0c04854c;
case 0x0c04854eu: goto P_0c04854e;
case 0x0c048550u: goto P_0c048550;
case 0x0c048552u: goto P_0c048552;
case 0x0c048554u: goto P_0c048554;
case 0x0c048556u: goto P_0c048556;
case 0x0c048558u: goto P_0c048558;
case 0x0c04855au: goto P_0c04855a;
case 0x0c04855cu: goto P_0c04855c;
case 0x0c04855eu: goto P_0c04855e;
case 0x0c048560u: goto P_0c048560;
case 0x0c04856cu: goto P_0c04856c;
case 0x0c04856eu: goto P_0c04856e;
case 0x0c048570u: goto P_0c048570;
case 0x0c048572u: goto P_0c048572;
case 0x0c048574u: goto P_0c048574;
case 0x0c048576u: goto P_0c048576;
case 0x0c048578u: goto P_0c048578;
case 0x0c04857au: goto P_0c04857a;
case 0x0c04857cu: goto P_0c04857c;
case 0x0c04857eu: goto P_0c04857e;
case 0x0c048580u: goto P_0c048580;
case 0x0c048582u: goto P_0c048582;
case 0x0c048584u: goto P_0c048584;
case 0x0c048586u: goto P_0c048586;
case 0x0c048588u: goto P_0c048588;
case 0x0c04858au: goto P_0c04858a;
case 0x0c04858cu: goto P_0c04858c;
case 0x0c04858eu: goto P_0c04858e;
case 0x0c048590u: goto P_0c048590;
case 0x0c048592u: goto P_0c048592;
case 0x0c048594u: goto P_0c048594;
case 0x0c048596u: goto P_0c048596;
case 0x0c048598u: goto P_0c048598;
case 0x0c04859cu: goto P_0c04859c;
case 0x0c04859eu: goto P_0c04859e;
case 0x0c0485a0u: goto P_0c0485a0;
case 0x0c0485a2u: goto P_0c0485a2;
case 0x0c0485a4u: goto P_0c0485a4;
case 0x0c0485a6u: goto P_0c0485a6;
case 0x0c0485a8u: goto P_0c0485a8;
case 0x0c0485aau: goto P_0c0485aa;
case 0x0c0485acu: goto P_0c0485ac;
case 0x0c0485aeu: goto P_0c0485ae;
case 0x0c0485b0u: goto P_0c0485b0;
case 0x0c0485b2u: goto P_0c0485b2;
case 0x0c0485b4u: goto P_0c0485b4;
case 0x0c0485b6u: goto P_0c0485b6;
case 0x0c0485b8u: goto P_0c0485b8;
case 0x0c0485bcu: goto P_0c0485bc;
case 0x0c0485beu: goto P_0c0485be;
case 0x0c04c024u: goto P_0c04c024;
case 0x0c04c026u: goto P_0c04c026;
case 0x0c04c028u: goto P_0c04c028;
case 0x0c04c02au: goto P_0c04c02a;
case 0x0c04c02cu: goto P_0c04c02c;
case 0x0c04c02eu: goto P_0c04c02e;
case 0x0c04c030u: goto P_0c04c030;
case 0x0c04c032u: goto P_0c04c032;
case 0x0c04c034u: goto P_0c04c034;
case 0x0c04c036u: goto P_0c04c036;
case 0x0c04c038u: goto P_0c04c038;
case 0x0c04c03au: goto P_0c04c03a;
case 0x0c04c03cu: goto P_0c04c03c;
case 0x0c04c03eu: goto P_0c04c03e;
case 0x0c04c040u: goto P_0c04c040;
case 0x0c04c042u: goto P_0c04c042;
case 0x0c04c044u: goto P_0c04c044;
case 0x0c04c046u: goto P_0c04c046;
case 0x0c04c048u: goto P_0c04c048;
case 0x0c04c04au: goto P_0c04c04a;
case 0x0c04c04cu: goto P_0c04c04c;
case 0x0c04c04eu: goto P_0c04c04e;
case 0x0c04c050u: goto P_0c04c050;
case 0x0c04c052u: goto P_0c04c052;
case 0x0c04c054u: goto P_0c04c054;
case 0x0c04c056u: goto P_0c04c056;
case 0x0c04c058u: goto P_0c04c058;
case 0x0c04c05au: goto P_0c04c05a;
case 0x0c04c05cu: goto P_0c04c05c;
case 0x0c04c05eu: goto P_0c04c05e;
case 0x0c04c060u: goto P_0c04c060;
case 0x0c04c062u: goto P_0c04c062;
case 0x0c04c064u: goto P_0c04c064;
case 0x0c04c066u: goto P_0c04c066;
case 0x0c04c068u: goto P_0c04c068;
case 0x0c04c06au: goto P_0c04c06a;
case 0x0c04c06cu: goto P_0c04c06c;
case 0x0c04c06eu: goto P_0c04c06e;
case 0x0c04c070u: goto P_0c04c070;
case 0x0c04c072u: goto P_0c04c072;
case 0x0c04c074u: goto P_0c04c074;
case 0x0c04c076u: goto P_0c04c076;
case 0x0c04c078u: goto P_0c04c078;
case 0x0c04c07au: goto P_0c04c07a;
case 0x0c04c07cu: goto P_0c04c07c;
case 0x0c04c07eu: goto P_0c04c07e;
case 0x0c04c080u: goto P_0c04c080;
case 0x0c04c082u: goto P_0c04c082;
case 0x0c04c084u: goto P_0c04c084;
case 0x0c04c086u: goto P_0c04c086;
case 0x0c04c088u: goto P_0c04c088;
case 0x0c04c08au: goto P_0c04c08a;
case 0x0c04c08cu: goto P_0c04c08c;
case 0x0c04c08eu: goto P_0c04c08e;
case 0x0c04c090u: goto P_0c04c090;
case 0x0c04c092u: goto P_0c04c092;
case 0x0c04c094u: goto P_0c04c094;
case 0x0c04c096u: goto P_0c04c096;
case 0x0c04c098u: goto P_0c04c098;
case 0x0c04c09au: goto P_0c04c09a;
case 0x0c04c09cu: goto P_0c04c09c;
case 0x0c04c09eu: goto P_0c04c09e;
case 0x0c04c0a0u: goto P_0c04c0a0;
case 0x0c04c0a2u: goto P_0c04c0a2;
case 0x0c04c0a4u: goto P_0c04c0a4;
case 0x0c04c0a6u: goto P_0c04c0a6;
case 0x0c04c0a8u: goto P_0c04c0a8;
case 0x0c04c0aau: goto P_0c04c0aa;
case 0x0c04c0acu: goto P_0c04c0ac;
case 0x0c04c0aeu: goto P_0c04c0ae;
case 0x0c04c0b0u: goto P_0c04c0b0;
case 0x0c04c0b2u: goto P_0c04c0b2;
case 0x0c04c0b4u: goto P_0c04c0b4;
case 0x0c04c0b6u: goto P_0c04c0b6;
case 0x0c04c0b8u: goto P_0c04c0b8;
case 0x0c04c0bau: goto P_0c04c0ba;
case 0x0c04c0bcu: goto P_0c04c0bc;
case 0x0c04c0beu: goto P_0c04c0be;
case 0x0c04c0c0u: goto P_0c04c0c0;
case 0x0c04c0c2u: goto P_0c04c0c2;
case 0x0c04c0c4u: goto P_0c04c0c4;
case 0x0c04c0c6u: goto P_0c04c0c6;
case 0x0c04c0c8u: goto P_0c04c0c8;
case 0x0c04c0cau: goto P_0c04c0ca;
case 0x0c04c0ccu: goto P_0c04c0cc;
case 0x0c04c0ceu: goto P_0c04c0ce;
case 0x0c04c0d0u: goto P_0c04c0d0;
case 0x0c04e03eu: goto P_0c04e03e;
case 0x0c04e040u: goto P_0c04e040;
case 0x0c04e042u: goto P_0c04e042;
case 0x0c04e044u: goto P_0c04e044;
case 0x0c04e046u: goto P_0c04e046;
case 0x0c04e048u: goto P_0c04e048;
case 0x0c04e04au: goto P_0c04e04a;
case 0x0c04e04cu: goto P_0c04e04c;
case 0x0c04e04eu: goto P_0c04e04e;
case 0x0c04e050u: goto P_0c04e050;
case 0x0c04e052u: goto P_0c04e052;
case 0x0c04e054u: goto P_0c04e054;
case 0x0c04e056u: goto P_0c04e056;
case 0x0c04e058u: goto P_0c04e058;
case 0x0c04e05au: goto P_0c04e05a;
case 0x0c04e05cu: goto P_0c04e05c;
case 0x0c04e05eu: goto P_0c04e05e;
case 0x0c04e060u: goto P_0c04e060;
case 0x0c04e062u: goto P_0c04e062;
case 0x0c04e064u: goto P_0c04e064;
case 0x0c04e066u: goto P_0c04e066;
case 0x0c04e068u: goto P_0c04e068;
case 0x0c04e06au: goto P_0c04e06a;
case 0x0c04e06cu: goto P_0c04e06c;
case 0x0c04e06eu: goto P_0c04e06e;
case 0x0c04e070u: goto P_0c04e070;
case 0x0c04e072u: goto P_0c04e072;
case 0x0c04e074u: goto P_0c04e074;
case 0x0c04e076u: goto P_0c04e076;
case 0x0c04e078u: goto P_0c04e078;
case 0x0c04e07au: goto P_0c04e07a;
case 0x0c04e07cu: goto P_0c04e07c;
case 0x0c04e07eu: goto P_0c04e07e;
case 0x0c04e080u: goto P_0c04e080;
case 0x0c04e082u: goto P_0c04e082;
case 0x0c04e084u: goto P_0c04e084;
case 0x0c04e086u: goto P_0c04e086;
case 0x0c04e088u: goto P_0c04e088;
case 0x0c04e08au: goto P_0c04e08a;
case 0x0c04e08cu: goto P_0c04e08c;
case 0x0c04e08eu: goto P_0c04e08e;
case 0x0c04e090u: goto P_0c04e090;
case 0x0c04e092u: goto P_0c04e092;
case 0x0c04e094u: goto P_0c04e094;
case 0x0c04e096u: goto P_0c04e096;
case 0x0c04e098u: goto P_0c04e098;
case 0x0c04e09au: goto P_0c04e09a;
case 0x0c04e09cu: goto P_0c04e09c;
case 0x0c04e09eu: goto P_0c04e09e;
case 0x0c04e0a0u: goto P_0c04e0a0;
case 0x0c04e0a2u: goto P_0c04e0a2;
case 0x0c04e0a4u: goto P_0c04e0a4;
case 0x0c04e0a6u: goto P_0c04e0a6;
case 0x0c04e0a8u: goto P_0c04e0a8;
case 0x0c04e0aau: goto P_0c04e0aa;
case 0x0c04e0acu: goto P_0c04e0ac;
case 0x0c04e0aeu: goto P_0c04e0ae;
case 0x0c04e0b0u: goto P_0c04e0b0;
case 0x0c04e0b2u: goto P_0c04e0b2;
case 0x0c04e0b4u: goto P_0c04e0b4;
case 0x0c04e0b6u: goto P_0c04e0b6;
case 0x0c04e0b8u: goto P_0c04e0b8;
case 0x0c04e0bau: goto P_0c04e0ba;
case 0x0c04e0bcu: goto P_0c04e0bc;
case 0x0c04e0beu: goto P_0c04e0be;
case 0x0c04e0c0u: goto P_0c04e0c0;
case 0x0c04e0c2u: goto P_0c04e0c2;
case 0x0c04e0c4u: goto P_0c04e0c4;
case 0x0c04e0c6u: goto P_0c04e0c6;
case 0x0c04e0c8u: goto P_0c04e0c8;
case 0x0c04e0cau: goto P_0c04e0ca;
case 0x0c04e0ccu: goto P_0c04e0cc;
case 0x0c04e0ceu: goto P_0c04e0ce;
case 0x0c04e0d0u: goto P_0c04e0d0;
case 0x0c04e0d2u: goto P_0c04e0d2;
case 0x0c04e0d4u: goto P_0c04e0d4;
case 0x0c04e0d6u: goto P_0c04e0d6;
case 0x0c04e0d8u: goto P_0c04e0d8;
case 0x0c04e0dau: goto P_0c04e0da;
case 0x0c04e0dcu: goto P_0c04e0dc;
case 0x0c04e0deu: goto P_0c04e0de;
case 0x0c04e0e0u: goto P_0c04e0e0;
case 0x0c04e0e2u: goto P_0c04e0e2;
case 0x0c04e0e4u: goto P_0c04e0e4;
case 0x0c04e0e6u: goto P_0c04e0e6;
case 0x0c04e124u: goto P_0c04e124;
case 0x0c04e126u: goto P_0c04e126;
case 0x0c04e128u: goto P_0c04e128;
case 0x0c04e12au: goto P_0c04e12a;
case 0x0c04e12cu: goto P_0c04e12c;
case 0x0c04e12eu: goto P_0c04e12e;
case 0x0c04e130u: goto P_0c04e130;
case 0x0c04e132u: goto P_0c04e132;
case 0x0c04e134u: goto P_0c04e134;
case 0x0c04e136u: goto P_0c04e136;
case 0x0c04e138u: goto P_0c04e138;
case 0x0c04e13au: goto P_0c04e13a;
case 0x0c04e13cu: goto P_0c04e13c;
case 0x0c04e13eu: goto P_0c04e13e;
case 0x0c04e140u: goto P_0c04e140;
case 0x0c04e142u: goto P_0c04e142;
case 0x0c04e144u: goto P_0c04e144;
case 0x0c04e146u: goto P_0c04e146;
case 0x0c04e148u: goto P_0c04e148;
case 0x0c04e14au: goto P_0c04e14a;
case 0x0c04e14cu: goto P_0c04e14c;
case 0x0c04e14eu: goto P_0c04e14e;
case 0x0c04e150u: goto P_0c04e150;
case 0x0c04e152u: goto P_0c04e152;
case 0x0c04e154u: goto P_0c04e154;
case 0x0c04e156u: goto P_0c04e156;
case 0x0c04e158u: goto P_0c04e158;
case 0x0c04e15au: goto P_0c04e15a;
case 0x0c04e15cu: goto P_0c04e15c;
case 0x0c04e15eu: goto P_0c04e15e;
case 0x0c04e160u: goto P_0c04e160;
case 0x0c04e162u: goto P_0c04e162;
case 0x0c04e164u: goto P_0c04e164;
case 0x0c04e166u: goto P_0c04e166;
case 0x0c04e168u: goto P_0c04e168;
case 0x0c04e16au: goto P_0c04e16a;
case 0x0c04e16cu: goto P_0c04e16c;
case 0x0c04e16eu: goto P_0c04e16e;
case 0x0c04e8f8u: goto P_0c04e8f8;
case 0x0c04e8fau: goto P_0c04e8fa;
case 0x0c04e8fcu: goto P_0c04e8fc;
case 0x0c04e8feu: goto P_0c04e8fe;
case 0x0c04e900u: goto P_0c04e900;
case 0x0c04e902u: goto P_0c04e902;
case 0x0c04e904u: goto P_0c04e904;
case 0x0c04e906u: goto P_0c04e906;
case 0x0c04e908u: goto P_0c04e908;
case 0x0c04e90au: goto P_0c04e90a;
case 0x0c04e90cu: goto P_0c04e90c;
case 0x0c04e90eu: goto P_0c04e90e;
case 0x0c04e910u: goto P_0c04e910;
case 0x0c04e912u: goto P_0c04e912;
case 0x0c04e914u: goto P_0c04e914;
case 0x0c04e916u: goto P_0c04e916;
case 0x0c04e918u: goto P_0c04e918;
case 0x0c04e91au: goto P_0c04e91a;
case 0x0c04e91cu: goto P_0c04e91c;
case 0x0c04e91eu: goto P_0c04e91e;
case 0x0c04e920u: goto P_0c04e920;
case 0x0c04e922u: goto P_0c04e922;
case 0x0c04e924u: goto P_0c04e924;
case 0x0c04e926u: goto P_0c04e926;
case 0x0c04e928u: goto P_0c04e928;
case 0x0c04e92au: goto P_0c04e92a;
case 0x0c04e92cu: goto P_0c04e92c;
case 0x0c04e92eu: goto P_0c04e92e;
case 0x0c04e930u: goto P_0c04e930;
case 0x0c04e932u: goto P_0c04e932;
case 0x0c04e934u: goto P_0c04e934;
case 0x0c04e936u: goto P_0c04e936;
case 0x0c04e938u: goto P_0c04e938;
case 0x0c04e93au: goto P_0c04e93a;
case 0x0c04e93cu: goto P_0c04e93c;
case 0x0c04e93eu: goto P_0c04e93e;
case 0x0c04e940u: goto P_0c04e940;
case 0x0c04e942u: goto P_0c04e942;
case 0x0c04e944u: goto P_0c04e944;
case 0x0c04e946u: goto P_0c04e946;
case 0x0c04e948u: goto P_0c04e948;
case 0x0c04e94au: goto P_0c04e94a;
case 0x0c04e94cu: goto P_0c04e94c;
case 0x0c04e94eu: goto P_0c04e94e;
case 0x0c04e950u: goto P_0c04e950;
case 0x0c04e952u: goto P_0c04e952;
case 0x0c04e954u: goto P_0c04e954;
case 0x0c04e956u: goto P_0c04e956;
case 0x0c04e958u: goto P_0c04e958;
case 0x0c04e95au: goto P_0c04e95a;
case 0x0c04e95cu: goto P_0c04e95c;
case 0x0c04e95eu: goto P_0c04e95e;
case 0x0c04e960u: goto P_0c04e960;
case 0x0c04e962u: goto P_0c04e962;
case 0x0c04e964u: goto P_0c04e964;
case 0x0c04e966u: goto P_0c04e966;
case 0x0c04e968u: goto P_0c04e968;
case 0x0c04e96au: goto P_0c04e96a;
case 0x0c04e96cu: goto P_0c04e96c;
case 0x0c04e96eu: goto P_0c04e96e;
case 0x0c04e970u: goto P_0c04e970;
case 0x0c04e972u: goto P_0c04e972;
case 0x0c04e974u: goto P_0c04e974;
case 0x0c04e976u: goto P_0c04e976;
case 0x0c04e978u: goto P_0c04e978;
case 0x0c04e97au: goto P_0c04e97a;
case 0x0c04e97cu: goto P_0c04e97c;
case 0x0c04e97eu: goto P_0c04e97e;
case 0x0c04e980u: goto P_0c04e980;
case 0x0c04e982u: goto P_0c04e982;
case 0x0c04e984u: goto P_0c04e984;
case 0x0c04e986u: goto P_0c04e986;
case 0x0c04e988u: goto P_0c04e988;
case 0x0c04e98au: goto P_0c04e98a;
case 0x0c04e98cu: goto P_0c04e98c;
case 0x0c04e98eu: goto P_0c04e98e;
case 0x0c04e990u: goto P_0c04e990;
case 0x0c04e992u: goto P_0c04e992;
case 0x0c04e994u: goto P_0c04e994;
case 0x0c04e996u: goto P_0c04e996;
case 0x0c04e998u: goto P_0c04e998;
case 0x0c04e99au: goto P_0c04e99a;
case 0x0c04e99cu: goto P_0c04e99c;
case 0x0c04e99eu: goto P_0c04e99e;
case 0x0c04e9ccu: goto P_0c04e9cc;
case 0x0c04e9ceu: goto P_0c04e9ce;
case 0x0c04e9d0u: goto P_0c04e9d0;
case 0x0c04e9d2u: goto P_0c04e9d2;
case 0x0c04e9d4u: goto P_0c04e9d4;
case 0x0c04e9d6u: goto P_0c04e9d6;
case 0x0c04e9d8u: goto P_0c04e9d8;
case 0x0c04e9dau: goto P_0c04e9da;
case 0x0c04e9dcu: goto P_0c04e9dc;
case 0x0c04e9deu: goto P_0c04e9de;
case 0x0c04e9e0u: goto P_0c04e9e0;
case 0x0c04e9e2u: goto P_0c04e9e2;
case 0x0c04e9e4u: goto P_0c04e9e4;
case 0x0c04e9e6u: goto P_0c04e9e6;
case 0x0c04e9e8u: goto P_0c04e9e8;
case 0x0c04e9eau: goto P_0c04e9ea;
case 0x0c04e9ecu: goto P_0c04e9ec;
case 0x0c04e9eeu: goto P_0c04e9ee;
case 0x0c04e9f0u: goto P_0c04e9f0;
case 0x0c04e9f2u: goto P_0c04e9f2;
case 0x0c04e9f4u: goto P_0c04e9f4;
case 0x0c04e9f6u: goto P_0c04e9f6;
case 0x0c04e9f8u: goto P_0c04e9f8;
case 0x0c04e9fau: goto P_0c04e9fa;
case 0x0c04e9fcu: goto P_0c04e9fc;
case 0x0c04e9feu: goto P_0c04e9fe;
case 0x0c04ea00u: goto P_0c04ea00;
case 0x0c04ea02u: goto P_0c04ea02;
case 0x0c04ea04u: goto P_0c04ea04;
case 0x0c04ea06u: goto P_0c04ea06;
case 0x0c04ea08u: goto P_0c04ea08;
case 0x0c04ea0au: goto P_0c04ea0a;
case 0x0c04ea0cu: goto P_0c04ea0c;
case 0x0c04ea0eu: goto P_0c04ea0e;
case 0x0c04ea10u: goto P_0c04ea10;
case 0x0c04ea12u: goto P_0c04ea12;
case 0x0c04ea14u: goto P_0c04ea14;
case 0x0c04ea16u: goto P_0c04ea16;
case 0x0c04ea18u: goto P_0c04ea18;
case 0x0c04ea1au: goto P_0c04ea1a;
case 0x0c04ea1cu: goto P_0c04ea1c;
case 0x0c04ea1eu: goto P_0c04ea1e;
case 0x0c04ea20u: goto P_0c04ea20;
case 0x0c04ea22u: goto P_0c04ea22;
case 0x0c04ea24u: goto P_0c04ea24;
case 0x0c04ea26u: goto P_0c04ea26;
case 0x0c04ea28u: goto P_0c04ea28;
case 0x0c04ea2au: goto P_0c04ea2a;
case 0x0c04ea2cu: goto P_0c04ea2c;
case 0x0c04ea2eu: goto P_0c04ea2e;
case 0x0c04ea30u: goto P_0c04ea30;
case 0x0c04ea32u: goto P_0c04ea32;
case 0x0c04ea34u: goto P_0c04ea34;
case 0x0c04ea36u: goto P_0c04ea36;
case 0x0c04ea38u: goto P_0c04ea38;
case 0x0c04ea3au: goto P_0c04ea3a;
case 0x0c04ea3cu: goto P_0c04ea3c;
case 0x0c04ea3eu: goto P_0c04ea3e;
case 0x0c04ea40u: goto P_0c04ea40;
case 0x0c04ea42u: goto P_0c04ea42;
case 0x0c04fbecu: goto P_0c04fbec;
case 0x0c04fbeeu: goto P_0c04fbee;
case 0x0c04fbf0u: goto P_0c04fbf0;
case 0x0c04fbf2u: goto P_0c04fbf2;
case 0x0c04fbf4u: goto P_0c04fbf4;
case 0x0c04fbf6u: goto P_0c04fbf6;
case 0x0c04fbf8u: goto P_0c04fbf8;
case 0x0c04fbfau: goto P_0c04fbfa;
case 0x0c04fbfcu: goto P_0c04fbfc;
case 0x0c04fbfeu: goto P_0c04fbfe;
case 0x0c04fc00u: goto P_0c04fc00;
case 0x0c04fc02u: goto P_0c04fc02;
case 0x0c04fc04u: goto P_0c04fc04;
case 0x0c04fc06u: goto P_0c04fc06;
case 0x0c04fc08u: goto P_0c04fc08;
case 0x0c04fc0au: goto P_0c04fc0a;
case 0x0c04fc0cu: goto P_0c04fc0c;
case 0x0c04fc0eu: goto P_0c04fc0e;
case 0x0c04fc10u: goto P_0c04fc10;
case 0x0c04fc12u: goto P_0c04fc12;
case 0x0c04fc14u: goto P_0c04fc14;
case 0x0c04fc16u: goto P_0c04fc16;
case 0x0c04fc18u: goto P_0c04fc18;
case 0x0c04fc1au: goto P_0c04fc1a;
case 0x0c04fc1cu: goto P_0c04fc1c;
case 0x0c04fc1eu: goto P_0c04fc1e;
case 0x0c04fc20u: goto P_0c04fc20;
case 0x0c04fc22u: goto P_0c04fc22;
case 0x0c04fc24u: goto P_0c04fc24;
case 0x0c04fc26u: goto P_0c04fc26;
case 0x0c04fc28u: goto P_0c04fc28;
case 0x0c04fc2au: goto P_0c04fc2a;
case 0x0c04fc2cu: goto P_0c04fc2c;
case 0x0c04fc2eu: goto P_0c04fc2e;
case 0x0c04fc30u: goto P_0c04fc30;
case 0x0c04fc32u: goto P_0c04fc32;
case 0x0c04fc34u: goto P_0c04fc34;
case 0x0c04fc36u: goto P_0c04fc36;
case 0x0c04fc38u: goto P_0c04fc38;
case 0x0c04fc3au: goto P_0c04fc3a;
case 0x0c04fc3cu: goto P_0c04fc3c;
case 0x0c04fc3eu: goto P_0c04fc3e;
case 0x0c04fc40u: goto P_0c04fc40;
case 0x0c04fc42u: goto P_0c04fc42;
case 0x0c04fc44u: goto P_0c04fc44;
case 0x0c04fc46u: goto P_0c04fc46;
case 0x0c04fc48u: goto P_0c04fc48;
case 0x0c04fc4au: goto P_0c04fc4a;
case 0x0c04fc4cu: goto P_0c04fc4c;
case 0x0c04fc4eu: goto P_0c04fc4e;
case 0x0c04fc50u: goto P_0c04fc50;
case 0x0c04fc52u: goto P_0c04fc52;
case 0x0c04fc54u: goto P_0c04fc54;
case 0x0c04fc56u: goto P_0c04fc56;
case 0x0c04fc58u: goto P_0c04fc58;
case 0x0c04fc5au: goto P_0c04fc5a;
case 0x0c04fc5cu: goto P_0c04fc5c;
case 0x0c04fc5eu: goto P_0c04fc5e;
case 0x0c04fc60u: goto P_0c04fc60;
case 0x0c04fc62u: goto P_0c04fc62;
case 0x0c04fc64u: goto P_0c04fc64;
case 0x0c04fc66u: goto P_0c04fc66;
case 0x0c04fc68u: goto P_0c04fc68;
case 0x0c04fc6au: goto P_0c04fc6a;
case 0x0c04fc6cu: goto P_0c04fc6c;
case 0x0c04fc6eu: goto P_0c04fc6e;
case 0x0c04fc70u: goto P_0c04fc70;
case 0x0c04fc72u: goto P_0c04fc72;
case 0x0c04fc74u: goto P_0c04fc74;
case 0x0c04fc76u: goto P_0c04fc76;
case 0x0c04fc78u: goto P_0c04fc78;
case 0x0c04fc7au: goto P_0c04fc7a;
case 0x0c04fc7cu: goto P_0c04fc7c;
case 0x0c04fc7eu: goto P_0c04fc7e;
case 0x0c04fc80u: goto P_0c04fc80;
case 0x0c04fc82u: goto P_0c04fc82;
case 0x0c04fc84u: goto P_0c04fc84;
case 0x0c0512dcu: goto P_0c0512dc;
case 0x0c0512deu: goto P_0c0512de;
case 0x0c0512e0u: goto P_0c0512e0;
case 0x0c058348u: goto P_0c058348;
case 0x0c05834au: goto P_0c05834a;
case 0x0c05834cu: goto P_0c05834c;
case 0x0c05834eu: goto P_0c05834e;
case 0x0c058350u: goto P_0c058350;
case 0x0c058352u: goto P_0c058352;
case 0x0c058354u: goto P_0c058354;
case 0x0c058356u: goto P_0c058356;
case 0x0c058358u: goto P_0c058358;
case 0x0c05835au: goto P_0c05835a;
case 0x0c05835cu: goto P_0c05835c;
case 0x0c05835eu: goto P_0c05835e;
case 0x0c058360u: goto P_0c058360;
case 0x0c058362u: goto P_0c058362;
case 0x0c058364u: goto P_0c058364;
case 0x0c058366u: goto P_0c058366;
case 0x0c058368u: goto P_0c058368;
case 0x0c05836au: goto P_0c05836a;
case 0x0c05836cu: goto P_0c05836c;
case 0x0c05836eu: goto P_0c05836e;
case 0x0c058370u: goto P_0c058370;
case 0x0c058372u: goto P_0c058372;
case 0x0c058374u: goto P_0c058374;
case 0x0c058376u: goto P_0c058376;
case 0x0c058378u: goto P_0c058378;
case 0x0c05837au: goto P_0c05837a;
case 0x0c05837cu: goto P_0c05837c;
case 0x0c05837eu: goto P_0c05837e;
case 0x0c058380u: goto P_0c058380;
case 0x0c058382u: goto P_0c058382;
case 0x0c058384u: goto P_0c058384;
case 0x0c058386u: goto P_0c058386;
case 0x0c058388u: goto P_0c058388;
case 0x0c05838au: goto P_0c05838a;
case 0x0c05838cu: goto P_0c05838c;
case 0x0c05838eu: goto P_0c05838e;
case 0x0c058390u: goto P_0c058390;
case 0x0c058392u: goto P_0c058392;
case 0x0c058394u: goto P_0c058394;
case 0x0c058396u: goto P_0c058396;
case 0x0c058398u: goto P_0c058398;
case 0x0c05839au: goto P_0c05839a;
case 0x0c05839cu: goto P_0c05839c;
case 0x0c05839eu: goto P_0c05839e;
case 0x0c0583a0u: goto P_0c0583a0;
case 0x0c0583a2u: goto P_0c0583a2;
case 0x0c0583a4u: goto P_0c0583a4;
case 0x0c0583a6u: goto P_0c0583a6;
case 0x0c0583a8u: goto P_0c0583a8;
case 0x0c0583aau: goto P_0c0583aa;
case 0x0c0583acu: goto P_0c0583ac;
case 0x0c0583aeu: goto P_0c0583ae;
case 0x0c0583b0u: goto P_0c0583b0;
case 0x0c0583b2u: goto P_0c0583b2;
case 0x0c0583b4u: goto P_0c0583b4;
case 0x0c0583b6u: goto P_0c0583b6;
case 0x0c0583b8u: goto P_0c0583b8;
case 0x0c0583bau: goto P_0c0583ba;
case 0x0c0583bcu: goto P_0c0583bc;
case 0x0c0583beu: goto P_0c0583be;
case 0x0c0583c0u: goto P_0c0583c0;
case 0x0c0583c2u: goto P_0c0583c2;
case 0x0c0583c4u: goto P_0c0583c4;
case 0x0c0583c6u: goto P_0c0583c6;
case 0x0c0583c8u: goto P_0c0583c8;
case 0x0c0583cau: goto P_0c0583ca;
case 0x0c0583ccu: goto P_0c0583cc;
case 0x0c0583ceu: goto P_0c0583ce;
case 0x0c0583d0u: goto P_0c0583d0;
case 0x0c0583d2u: goto P_0c0583d2;
case 0x0c0583d4u: goto P_0c0583d4;
case 0x0c0583d6u: goto P_0c0583d6;
case 0x0c0583d8u: goto P_0c0583d8;
case 0x0c0583dau: goto P_0c0583da;
case 0x0c0583dcu: goto P_0c0583dc;
case 0x0c0583deu: goto P_0c0583de;
case 0x0c0583e0u: goto P_0c0583e0;
case 0x0c0583e2u: goto P_0c0583e2;
case 0x0c0583e4u: goto P_0c0583e4;
case 0x0c0583e6u: goto P_0c0583e6;
case 0x0c0583e8u: goto P_0c0583e8;
case 0x0c0583eau: goto P_0c0583ea;
case 0x0c0583ecu: goto P_0c0583ec;
case 0x0c0583eeu: goto P_0c0583ee;
case 0x0c0583f0u: goto P_0c0583f0;
case 0x0c0583f2u: goto P_0c0583f2;
case 0x0c0583f4u: goto P_0c0583f4;
case 0x0c0583f6u: goto P_0c0583f6;
case 0x0c0583f8u: goto P_0c0583f8;
case 0x0c0583fau: goto P_0c0583fa;
case 0x0c0583fcu: goto P_0c0583fc;
case 0x0c0583feu: goto P_0c0583fe;
case 0x0c058400u: goto P_0c058400;
case 0x0c058402u: goto P_0c058402;
case 0x0c058404u: goto P_0c058404;
case 0x0c058406u: goto P_0c058406;
case 0x0c058408u: goto P_0c058408;
case 0x0c05840au: goto P_0c05840a;
case 0x0c05840cu: goto P_0c05840c;
case 0x0c05840eu: goto P_0c05840e;
case 0x0c058410u: goto P_0c058410;
case 0x0c058412u: goto P_0c058412;
case 0x0c058414u: goto P_0c058414;
case 0x0c058416u: goto P_0c058416;
case 0x0c058418u: goto P_0c058418;
case 0x0c05841au: goto P_0c05841a;
case 0x0c05841cu: goto P_0c05841c;
case 0x0c05841eu: goto P_0c05841e;
case 0x0c058420u: goto P_0c058420;
case 0x0c058422u: goto P_0c058422;
case 0x0c058424u: goto P_0c058424;
case 0x0c058426u: goto P_0c058426;
case 0x0c058428u: goto P_0c058428;
case 0x0c05842au: goto P_0c05842a;
case 0x0c05842cu: goto P_0c05842c;
case 0x0c05842eu: goto P_0c05842e;
case 0x0c058430u: goto P_0c058430;
case 0x0c058432u: goto P_0c058432;
case 0x0c058434u: goto P_0c058434;
case 0x0c058436u: goto P_0c058436;
case 0x0c058438u: goto P_0c058438;
case 0x0c05843au: goto P_0c05843a;
case 0x0c05843cu: goto P_0c05843c;
case 0x0c05843eu: goto P_0c05843e;
case 0x0c058440u: goto P_0c058440;
case 0x0c058442u: goto P_0c058442;
case 0x0c058444u: goto P_0c058444;
case 0x0c058446u: goto P_0c058446;
case 0x0c058448u: goto P_0c058448;
case 0x0c05844au: goto P_0c05844a;
case 0x0c05844cu: goto P_0c05844c;
case 0x0c05844eu: goto P_0c05844e;
case 0x0c058450u: goto P_0c058450;
case 0x0c058452u: goto P_0c058452;
case 0x0c058454u: goto P_0c058454;
case 0x0c058456u: goto P_0c058456;
case 0x0c058458u: goto P_0c058458;
case 0x0c05845au: goto P_0c05845a;
case 0x0c05845cu: goto P_0c05845c;
case 0x0c05845eu: goto P_0c05845e;
case 0x0c058460u: goto P_0c058460;
case 0x0c058462u: goto P_0c058462;
case 0x0c058464u: goto P_0c058464;
case 0x0c058466u: goto P_0c058466;
case 0x0c058468u: goto P_0c058468;
case 0x0c05846au: goto P_0c05846a;
case 0x0c05846cu: goto P_0c05846c;
case 0x0c05846eu: goto P_0c05846e;
case 0x0c058470u: goto P_0c058470;
case 0x0c058472u: goto P_0c058472;
case 0x0c058474u: goto P_0c058474;
case 0x0c058476u: goto P_0c058476;
case 0x0c058478u: goto P_0c058478;
case 0x0c05847au: goto P_0c05847a;
case 0x0c05847cu: goto P_0c05847c;
case 0x0c05847eu: goto P_0c05847e;
case 0x0c058480u: goto P_0c058480;
case 0x0c058482u: goto P_0c058482;
case 0x0c058484u: goto P_0c058484;
case 0x0c058486u: goto P_0c058486;
case 0x0c058488u: goto P_0c058488;
case 0x0c05848au: goto P_0c05848a;
case 0x0c05848cu: goto P_0c05848c;
case 0x0c05848eu: goto P_0c05848e;
case 0x0c058490u: goto P_0c058490;
case 0x0c058492u: goto P_0c058492;
case 0x0c058494u: goto P_0c058494;
case 0x0c058496u: goto P_0c058496;
case 0x0c058498u: goto P_0c058498;
case 0x0c05849au: goto P_0c05849a;
case 0x0c05849cu: goto P_0c05849c;
case 0x0c05849eu: goto P_0c05849e;
case 0x0c0584a0u: goto P_0c0584a0;
case 0x0c0584a2u: goto P_0c0584a2;
case 0x0c0584a4u: goto P_0c0584a4;
case 0x0c0584a6u: goto P_0c0584a6;
case 0x0c0584a8u: goto P_0c0584a8;
case 0x0c0584aau: goto P_0c0584aa;
case 0x0c0584acu: goto P_0c0584ac;
case 0x0c0584aeu: goto P_0c0584ae;
case 0x0c0584b0u: goto P_0c0584b0;
case 0x0c0584b2u: goto P_0c0584b2;
case 0x0c0584b4u: goto P_0c0584b4;
case 0x0c0584b6u: goto P_0c0584b6;
case 0x0c0584b8u: goto P_0c0584b8;
case 0x0c0584bau: goto P_0c0584ba;
case 0x0c0584bcu: goto P_0c0584bc;
case 0x0c0584beu: goto P_0c0584be;
case 0x0c0584c0u: goto P_0c0584c0;
case 0x0c0584c2u: goto P_0c0584c2;
case 0x0c0584c4u: goto P_0c0584c4;
case 0x0c0584c6u: goto P_0c0584c6;
case 0x0c0584c8u: goto P_0c0584c8;
case 0x0c0584cau: goto P_0c0584ca;
case 0x0c0584ccu: goto P_0c0584cc;
case 0x0c0584ceu: goto P_0c0584ce;
case 0x0c0584d0u: goto P_0c0584d0;
case 0x0c0584d2u: goto P_0c0584d2;
case 0x0c0584d4u: goto P_0c0584d4;
case 0x0c0584d6u: goto P_0c0584d6;
case 0x0c0584d8u: goto P_0c0584d8;
case 0x0c0584dau: goto P_0c0584da;
case 0x0c0584dcu: goto P_0c0584dc;
case 0x0c0584deu: goto P_0c0584de;
case 0x0c0584e0u: goto P_0c0584e0;
case 0x0c058780u: goto P_0c058780;
case 0x0c058782u: goto P_0c058782;
case 0x0c058784u: goto P_0c058784;
case 0x0c058786u: goto P_0c058786;
case 0x0c058788u: goto P_0c058788;
case 0x0c05878cu: goto P_0c05878c;
case 0x0c05878eu: goto P_0c05878e;
case 0x0c058790u: goto P_0c058790;
case 0x0c058816u: goto P_0c058816;
case 0x0c058818u: goto P_0c058818;
case 0x0c05881au: goto P_0c05881a;
case 0x0c05881cu: goto P_0c05881c;
case 0x0c05881eu: goto P_0c05881e;
case 0x0c058820u: goto P_0c058820;
case 0x0c058822u: goto P_0c058822;
case 0x0c058824u: goto P_0c058824;
case 0x0c058826u: goto P_0c058826;
case 0x0c058828u: goto P_0c058828;
case 0x0c05882au: goto P_0c05882a;
case 0x0c05882cu: goto P_0c05882c;
case 0x0c05882eu: goto P_0c05882e;
case 0x0c058830u: goto P_0c058830;
case 0x0c058832u: goto P_0c058832;
case 0x0c058834u: goto P_0c058834;
case 0x0c058836u: goto P_0c058836;
case 0x0c058838u: goto P_0c058838;
case 0x0c05883au: goto P_0c05883a;
case 0x0c05883cu: goto P_0c05883c;
case 0x0c05883eu: goto P_0c05883e;
case 0x0c058840u: goto P_0c058840;
case 0x0c058842u: goto P_0c058842;
case 0x0c058844u: goto P_0c058844;
case 0x0c058846u: goto P_0c058846;
case 0x0c058848u: goto P_0c058848;
case 0x0c05884au: goto P_0c05884a;
case 0x0c05884cu: goto P_0c05884c;
case 0x0c05884eu: goto P_0c05884e;
case 0x0c058850u: goto P_0c058850;
case 0x0c058852u: goto P_0c058852;
case 0x0c058854u: goto P_0c058854;
case 0x0c058856u: goto P_0c058856;
case 0x0c058858u: goto P_0c058858;
case 0x0c05885au: goto P_0c05885a;
case 0x0c05885cu: goto P_0c05885c;
case 0x0c05885eu: goto P_0c05885e;
case 0x0c058860u: goto P_0c058860;
case 0x0c058862u: goto P_0c058862;
case 0x0c058864u: goto P_0c058864;
case 0x0c058866u: goto P_0c058866;
case 0x0c058868u: goto P_0c058868;
case 0x0c05886au: goto P_0c05886a;
case 0x0c05886cu: goto P_0c05886c;
case 0x0c05886eu: goto P_0c05886e;
case 0x0c058870u: goto P_0c058870;
case 0x0c058872u: goto P_0c058872;
case 0x0c058874u: goto P_0c058874;
case 0x0c058876u: goto P_0c058876;
case 0x0c058878u: goto P_0c058878;
case 0x0c05887au: goto P_0c05887a;
case 0x0c05887cu: goto P_0c05887c;
case 0x0c05887eu: goto P_0c05887e;
case 0x0c058880u: goto P_0c058880;
case 0x0c058882u: goto P_0c058882;
case 0x0c058884u: goto P_0c058884;
case 0x0c058886u: goto P_0c058886;
case 0x0c058888u: goto P_0c058888;
case 0x0c05888au: goto P_0c05888a;
case 0x0c05888cu: goto P_0c05888c;
case 0x0c05888eu: goto P_0c05888e;
case 0x0c058890u: goto P_0c058890;
case 0x0c058892u: goto P_0c058892;
case 0x0c058894u: goto P_0c058894;
case 0x0c058896u: goto P_0c058896;
case 0x0c058898u: goto P_0c058898;
case 0x0c05889au: goto P_0c05889a;
case 0x0c05889cu: goto P_0c05889c;
case 0x0c05889eu: goto P_0c05889e;
case 0x0c0588a0u: goto P_0c0588a0;
case 0x0c0588a2u: goto P_0c0588a2;
case 0x0c0588a4u: goto P_0c0588a4;
case 0x0c0588a6u: goto P_0c0588a6;
case 0x0c0588a8u: goto P_0c0588a8;
case 0x0c0588aau: goto P_0c0588aa;
case 0x0c0588acu: goto P_0c0588ac;
case 0x0c0588aeu: goto P_0c0588ae;
case 0x0c0588b0u: goto P_0c0588b0;
case 0x0c0588b2u: goto P_0c0588b2;
case 0x0c0588b4u: goto P_0c0588b4;
case 0x0c0588b6u: goto P_0c0588b6;
case 0x0c0588b8u: goto P_0c0588b8;
case 0x0c0588bau: goto P_0c0588ba;
case 0x0c0588bcu: goto P_0c0588bc;
case 0x0c0588beu: goto P_0c0588be;
case 0x0c0588c0u: goto P_0c0588c0;
case 0x0c0588c2u: goto P_0c0588c2;
case 0x0c0588c4u: goto P_0c0588c4;
case 0x0c0588c6u: goto P_0c0588c6;
case 0x0c0588c8u: goto P_0c0588c8;
case 0x0c0588cau: goto P_0c0588ca;
case 0x0c0588ccu: goto P_0c0588cc;
case 0x0c0588ceu: goto P_0c0588ce;
case 0x0c0588d0u: goto P_0c0588d0;
case 0x0c0588d2u: goto P_0c0588d2;
case 0x0c0588d4u: goto P_0c0588d4;
case 0x0c0588d6u: goto P_0c0588d6;
case 0x0c0588d8u: goto P_0c0588d8;
case 0x0c0588dau: goto P_0c0588da;
case 0x0c0588dcu: goto P_0c0588dc;
case 0x0c0588deu: goto P_0c0588de;
case 0x0c0588e0u: goto P_0c0588e0;
case 0x0c0588e2u: goto P_0c0588e2;
case 0x0c0588e4u: goto P_0c0588e4;
case 0x0c0588e6u: goto P_0c0588e6;
case 0x0c0588e8u: goto P_0c0588e8;
case 0x0c0588eau: goto P_0c0588ea;
case 0x0c0588ecu: goto P_0c0588ec;
case 0x0c0588eeu: goto P_0c0588ee;
case 0x0c0588f0u: goto P_0c0588f0;
case 0x0c0588f2u: goto P_0c0588f2;
case 0x0c0588f4u: goto P_0c0588f4;
case 0x0c0588f6u: goto P_0c0588f6;
case 0x0c0588f8u: goto P_0c0588f8;
case 0x0c0588fau: goto P_0c0588fa;
case 0x0c0588fcu: goto P_0c0588fc;
case 0x0c0588feu: goto P_0c0588fe;
case 0x0c058900u: goto P_0c058900;
case 0x0c058902u: goto P_0c058902;
case 0x0c058904u: goto P_0c058904;
case 0x0c058906u: goto P_0c058906;
case 0x0c058908u: goto P_0c058908;
case 0x0c05890au: goto P_0c05890a;
case 0x0c05890cu: goto P_0c05890c;
case 0x0c05890eu: goto P_0c05890e;
case 0x0c058910u: goto P_0c058910;
case 0x0c058912u: goto P_0c058912;
case 0x0c058914u: goto P_0c058914;
case 0x0c058916u: goto P_0c058916;
case 0x0c058918u: goto P_0c058918;
case 0x0c05891au: goto P_0c05891a;
case 0x0c05891cu: goto P_0c05891c;
case 0x0c05891eu: goto P_0c05891e;
case 0x0c058920u: goto P_0c058920;
case 0x0c058922u: goto P_0c058922;
case 0x0c058924u: goto P_0c058924;
case 0x0c058926u: goto P_0c058926;
case 0x0c058928u: goto P_0c058928;
case 0x0c05892au: goto P_0c05892a;
case 0x0c05892cu: goto P_0c05892c;
case 0x0c05892eu: goto P_0c05892e;
case 0x0c058930u: goto P_0c058930;
case 0x0c058932u: goto P_0c058932;
case 0x0c058934u: goto P_0c058934;
case 0x0c058936u: goto P_0c058936;
case 0x0c058938u: goto P_0c058938;
case 0x0c05893au: goto P_0c05893a;
case 0x0c05893cu: goto P_0c05893c;
case 0x0c05893eu: goto P_0c05893e;
case 0x0c058940u: goto P_0c058940;
case 0x0c058942u: goto P_0c058942;
case 0x0c058944u: goto P_0c058944;
case 0x0c058946u: goto P_0c058946;
case 0x0c058948u: goto P_0c058948;
case 0x0c05894au: goto P_0c05894a;
case 0x0c05894cu: goto P_0c05894c;
case 0x0c05894eu: goto P_0c05894e;
case 0x0c058950u: goto P_0c058950;
case 0x0c058952u: goto P_0c058952;
case 0x0c058954u: goto P_0c058954;
case 0x0c058956u: goto P_0c058956;
case 0x0c058958u: goto P_0c058958;
case 0x0c05895au: goto P_0c05895a;
case 0x0c05895cu: goto P_0c05895c;
case 0x0c05895eu: goto P_0c05895e;
case 0x0c058960u: goto P_0c058960;
case 0x0c058962u: goto P_0c058962;
case 0x0c058964u: goto P_0c058964;
case 0x0c058966u: goto P_0c058966;
case 0x0c058968u: goto P_0c058968;
case 0x0c05896au: goto P_0c05896a;
case 0x0c05896cu: goto P_0c05896c;
case 0x0c05896eu: goto P_0c05896e;
case 0x0c058970u: goto P_0c058970;
case 0x0c058972u: goto P_0c058972;
case 0x0c058974u: goto P_0c058974;
case 0x0c058976u: goto P_0c058976;
case 0x0c0589d0u: goto P_0c0589d0;
case 0x0c0589d2u: goto P_0c0589d2;
case 0x0c0589d4u: goto P_0c0589d4;
case 0x0c0589d6u: goto P_0c0589d6;
case 0x0c0589d8u: goto P_0c0589d8;
case 0x0c0589dau: goto P_0c0589da;
case 0x0c0589dcu: goto P_0c0589dc;
case 0x0c0589deu: goto P_0c0589de;
case 0x0c0589e0u: goto P_0c0589e0;
case 0x0c0589e2u: goto P_0c0589e2;
case 0x0c0589e4u: goto P_0c0589e4;
case 0x0c0589e6u: goto P_0c0589e6;
case 0x0c0589e8u: goto P_0c0589e8;
case 0x0c0589eau: goto P_0c0589ea;
case 0x0c0589ecu: goto P_0c0589ec;
case 0x0c0589eeu: goto P_0c0589ee;
case 0x0c0589f0u: goto P_0c0589f0;
case 0x0c0589f2u: goto P_0c0589f2;
case 0x0c0589f4u: goto P_0c0589f4;
case 0x0c0589f6u: goto P_0c0589f6;
case 0x0c0589f8u: goto P_0c0589f8;
case 0x0c0589fau: goto P_0c0589fa;
case 0x0c0589fcu: goto P_0c0589fc;
case 0x0c0589feu: goto P_0c0589fe;
case 0x0c058a00u: goto P_0c058a00;
case 0x0c058a02u: goto P_0c058a02;
case 0x0c058a04u: goto P_0c058a04;
case 0x0c058a06u: goto P_0c058a06;
case 0x0c058a08u: goto P_0c058a08;
case 0x0c058a0au: goto P_0c058a0a;
case 0x0c058a0cu: goto P_0c058a0c;
case 0x0c058a0eu: goto P_0c058a0e;
case 0x0c058a10u: goto P_0c058a10;
case 0x0c058a12u: goto P_0c058a12;
case 0x0c058a14u: goto P_0c058a14;
case 0x0c058a16u: goto P_0c058a16;
case 0x0c058a18u: goto P_0c058a18;
case 0x0c058a1au: goto P_0c058a1a;
case 0x0c058a1cu: goto P_0c058a1c;
case 0x0c058a1eu: goto P_0c058a1e;
case 0x0c058a20u: goto P_0c058a20;
case 0x0c058a22u: goto P_0c058a22;
case 0x0c058a24u: goto P_0c058a24;
case 0x0c058a26u: goto P_0c058a26;
case 0x0c058a28u: goto P_0c058a28;
case 0x0c058a2au: goto P_0c058a2a;
case 0x0c058a2cu: goto P_0c058a2c;
case 0x0c058a2eu: goto P_0c058a2e;
case 0x0c058a30u: goto P_0c058a30;
case 0x0c058a32u: goto P_0c058a32;
case 0x0c058a34u: goto P_0c058a34;
case 0x0c058a36u: goto P_0c058a36;
case 0x0c058a38u: goto P_0c058a38;
case 0x0c058a3au: goto P_0c058a3a;
case 0x0c058a3cu: goto P_0c058a3c;
case 0x0c058a3eu: goto P_0c058a3e;
case 0x0c058a40u: goto P_0c058a40;
case 0x0c058a42u: goto P_0c058a42;
case 0x0c058a44u: goto P_0c058a44;
case 0x0c058a46u: goto P_0c058a46;
case 0x0c058a48u: goto P_0c058a48;
case 0x0c058a4au: goto P_0c058a4a;
case 0x0c058a4cu: goto P_0c058a4c;
case 0x0c058a4eu: goto P_0c058a4e;
case 0x0c058a50u: goto P_0c058a50;
case 0x0c058a52u: goto P_0c058a52;
case 0x0c058a54u: goto P_0c058a54;
case 0x0c058a56u: goto P_0c058a56;
case 0x0c059aeau: goto P_0c059aea;
case 0x0c059aecu: goto P_0c059aec;
case 0x0c059aeeu: goto P_0c059aee;
case 0x0c059af0u: goto P_0c059af0;
case 0x0c059af2u: goto P_0c059af2;
case 0x0c059af4u: goto P_0c059af4;
case 0x0c059af6u: goto P_0c059af6;
case 0x0c059af8u: goto P_0c059af8;
case 0x0c059afau: goto P_0c059afa;
case 0x0c059afcu: goto P_0c059afc;
case 0x0c059afeu: goto P_0c059afe;
case 0x0c059b00u: goto P_0c059b00;
case 0x0c059b02u: goto P_0c059b02;
case 0x0c059b04u: goto P_0c059b04;
case 0x0c059b06u: goto P_0c059b06;
case 0x0c059b08u: goto P_0c059b08;
case 0x0c059b0au: goto P_0c059b0a;
case 0x0c059b0cu: goto P_0c059b0c;
case 0x0c059b40u: goto P_0c059b40;
case 0x0c059b42u: goto P_0c059b42;
case 0x0c059b44u: goto P_0c059b44;
case 0x0c059b46u: goto P_0c059b46;
case 0x0c059b48u: goto P_0c059b48;
case 0x0c059b4au: goto P_0c059b4a;
case 0x0c059b4cu: goto P_0c059b4c;
case 0x0c059b4eu: goto P_0c059b4e;
case 0x0c059b50u: goto P_0c059b50;
case 0x0c059b52u: goto P_0c059b52;
case 0x0c059b54u: goto P_0c059b54;
case 0x0c059b56u: goto P_0c059b56;
case 0x0c059b58u: goto P_0c059b58;
case 0x0c059b5au: goto P_0c059b5a;
case 0x0c059b5cu: goto P_0c059b5c;
case 0x0c059b5eu: goto P_0c059b5e;
case 0x0c059b60u: goto P_0c059b60;
case 0x0c059b62u: goto P_0c059b62;
case 0x0c059b64u: goto P_0c059b64;
case 0x0c059b66u: goto P_0c059b66;
case 0x0c059b68u: goto P_0c059b68;
case 0x0c059b6au: goto P_0c059b6a;
case 0x0c059b6cu: goto P_0c059b6c;
case 0x0c059b6eu: goto P_0c059b6e;
case 0x0c059b70u: goto P_0c059b70;
case 0x0c059b72u: goto P_0c059b72;
case 0x0c059b74u: goto P_0c059b74;
case 0x0c059b76u: goto P_0c059b76;
case 0x0c059b78u: goto P_0c059b78;
case 0x0c059b7au: goto P_0c059b7a;
case 0x0c059b7cu: goto P_0c059b7c;
case 0x0c059b7eu: goto P_0c059b7e;
case 0x0c059b80u: goto P_0c059b80;
case 0x0c059b82u: goto P_0c059b82;
case 0x0c059b84u: goto P_0c059b84;
case 0x0c059b86u: goto P_0c059b86;
case 0x0c059b88u: goto P_0c059b88;
case 0x0c059b8au: goto P_0c059b8a;
case 0x0c059b8cu: goto P_0c059b8c;
case 0x0c059b8eu: goto P_0c059b8e;
case 0x0c059b90u: goto P_0c059b90;
case 0x0c059b92u: goto P_0c059b92;
case 0x0c059b94u: goto P_0c059b94;
case 0x0c059b96u: goto P_0c059b96;
case 0x0c059b98u: goto P_0c059b98;
case 0x0c059b9au: goto P_0c059b9a;
case 0x0c059b9cu: goto P_0c059b9c;
case 0x0c059b9eu: goto P_0c059b9e;
case 0x0c059ba0u: goto P_0c059ba0;
case 0x0c059ba2u: goto P_0c059ba2;
case 0x0c059ba4u: goto P_0c059ba4;
case 0x0c059ba6u: goto P_0c059ba6;
case 0x0c059ba8u: goto P_0c059ba8;
case 0x0c059baau: goto P_0c059baa;
case 0x0c059bacu: goto P_0c059bac;
case 0x0c059baeu: goto P_0c059bae;
case 0x0c059bb0u: goto P_0c059bb0;
case 0x0c059bb2u: goto P_0c059bb2;
case 0x0c059bb4u: goto P_0c059bb4;
case 0x0c059bb6u: goto P_0c059bb6;
case 0x0c059bb8u: goto P_0c059bb8;
case 0x0c059bbau: goto P_0c059bba;
case 0x0c059bbcu: goto P_0c059bbc;
case 0x0c059bbeu: goto P_0c059bbe;
case 0x0c059bc0u: goto P_0c059bc0;
case 0x0c059bc2u: goto P_0c059bc2;
case 0x0c059bc4u: goto P_0c059bc4;
case 0x0c059bc6u: goto P_0c059bc6;
case 0x0c059bc8u: goto P_0c059bc8;
case 0x0c059bcau: goto P_0c059bca;
case 0x0c059bccu: goto P_0c059bcc;
case 0x0c059bceu: goto P_0c059bce;
case 0x0c059bd0u: goto P_0c059bd0;
case 0x0c059bd2u: goto P_0c059bd2;
case 0x0c059bd4u: goto P_0c059bd4;
case 0x0c059bd6u: goto P_0c059bd6;
case 0x0c059bd8u: goto P_0c059bd8;
case 0x0c059bdau: goto P_0c059bda;
case 0x0c059bdcu: goto P_0c059bdc;
case 0x0c059bdeu: goto P_0c059bde;
case 0x0c059be0u: goto P_0c059be0;
case 0x0c059be2u: goto P_0c059be2;
case 0x0c059be4u: goto P_0c059be4;
case 0x0c059be6u: goto P_0c059be6;
case 0x0c059be8u: goto P_0c059be8;
case 0x0c059beau: goto P_0c059bea;
case 0x0c059becu: goto P_0c059bec;
case 0x0c059beeu: goto P_0c059bee;
case 0x0c059bf0u: goto P_0c059bf0;
case 0x0c059bf2u: goto P_0c059bf2;
case 0x0c059bf4u: goto P_0c059bf4;
case 0x0c059bf6u: goto P_0c059bf6;
case 0x0c059bf8u: goto P_0c059bf8;
case 0x0c059bfau: goto P_0c059bfa;
case 0x0c059bfcu: goto P_0c059bfc;
case 0x0c059bfeu: goto P_0c059bfe;
case 0x0c059c00u: goto P_0c059c00;
case 0x0c059c02u: goto P_0c059c02;
case 0x0c059c04u: goto P_0c059c04;
case 0x0c059c06u: goto P_0c059c06;
case 0x0c059c08u: goto P_0c059c08;
case 0x0c059c0au: goto P_0c059c0a;
case 0x0c059c0cu: goto P_0c059c0c;
case 0x0c059c0eu: goto P_0c059c0e;
case 0x0c059c10u: goto P_0c059c10;
case 0x0c059c12u: goto P_0c059c12;
case 0x0c059c14u: goto P_0c059c14;
case 0x0c059c16u: goto P_0c059c16;
case 0x0c059c18u: goto P_0c059c18;
case 0x0c059c1au: goto P_0c059c1a;
case 0x0c059c1cu: goto P_0c059c1c;
case 0x0c059c1eu: goto P_0c059c1e;
case 0x0c059c88u: goto P_0c059c88;
case 0x0c059c8au: goto P_0c059c8a;
case 0x0c059c8cu: goto P_0c059c8c;
case 0x0c059c8eu: goto P_0c059c8e;
case 0x0c059c90u: goto P_0c059c90;
case 0x0c059c92u: goto P_0c059c92;
case 0x0c059c94u: goto P_0c059c94;
case 0x0c059c96u: goto P_0c059c96;
case 0x0c059c98u: goto P_0c059c98;
case 0x0c059c9au: goto P_0c059c9a;
case 0x0c059c9cu: goto P_0c059c9c;
case 0x0c059c9eu: goto P_0c059c9e;
case 0x0c059ca0u: goto P_0c059ca0;
case 0x0c059ca2u: goto P_0c059ca2;
case 0x0c059ca4u: goto P_0c059ca4;
case 0x0c059ca6u: goto P_0c059ca6;
case 0x0c059ca8u: goto P_0c059ca8;
case 0x0c059caau: goto P_0c059caa;
case 0x0c059cacu: goto P_0c059cac;
case 0x0c059caeu: goto P_0c059cae;
case 0x0c059cb0u: goto P_0c059cb0;
case 0x0c059cb2u: goto P_0c059cb2;
case 0x0c059cb4u: goto P_0c059cb4;
case 0x0c059cb6u: goto P_0c059cb6;
case 0x0c059cb8u: goto P_0c059cb8;
case 0x0c059cbau: goto P_0c059cba;
case 0x0c059cbcu: goto P_0c059cbc;
case 0x0c059cbeu: goto P_0c059cbe;
case 0x0c059cc0u: goto P_0c059cc0;
case 0x0c059cc2u: goto P_0c059cc2;
case 0x0c059cc4u: goto P_0c059cc4;
case 0x0c059cc6u: goto P_0c059cc6;
case 0x0c059cc8u: goto P_0c059cc8;
case 0x0c059ccau: goto P_0c059cca;
case 0x0c059cccu: goto P_0c059ccc;
case 0x0c059cceu: goto P_0c059cce;
case 0x0c059cd0u: goto P_0c059cd0;
case 0x0c059cd2u: goto P_0c059cd2;
case 0x0c059cd4u: goto P_0c059cd4;
case 0x0c059cd6u: goto P_0c059cd6;
case 0x0c059cd8u: goto P_0c059cd8;
case 0x0c059cdau: goto P_0c059cda;
case 0x0c059cdcu: goto P_0c059cdc;
case 0x0c059cdeu: goto P_0c059cde;
case 0x0c059ce0u: goto P_0c059ce0;
case 0x0c059ce2u: goto P_0c059ce2;
case 0x0c059ce4u: goto P_0c059ce4;
case 0x0c059ce6u: goto P_0c059ce6;
case 0x0c059ce8u: goto P_0c059ce8;
case 0x0c059ceau: goto P_0c059cea;
case 0x0c059cecu: goto P_0c059cec;
case 0x0c059ceeu: goto P_0c059cee;
case 0x0c059cf0u: goto P_0c059cf0;
case 0x0c059cf2u: goto P_0c059cf2;
case 0x0c059cf4u: goto P_0c059cf4;
case 0x0c059cf6u: goto P_0c059cf6;
case 0x0c059cf8u: goto P_0c059cf8;
case 0x0c059cfau: goto P_0c059cfa;
case 0x0c059cfcu: goto P_0c059cfc;
case 0x0c059cfeu: goto P_0c059cfe;
case 0x0c059d00u: goto P_0c059d00;
case 0x0c059d02u: goto P_0c059d02;
case 0x0c059d04u: goto P_0c059d04;
case 0x0c059d06u: goto P_0c059d06;
case 0x0c059d08u: goto P_0c059d08;
case 0x0c059d0au: goto P_0c059d0a;
case 0x0c059d0cu: goto P_0c059d0c;
case 0x0c059d0eu: goto P_0c059d0e;
case 0x0c059d10u: goto P_0c059d10;
case 0x0c059d12u: goto P_0c059d12;
case 0x0c059d14u: goto P_0c059d14;
case 0x0c059d16u: goto P_0c059d16;
case 0x0c059d18u: goto P_0c059d18;
case 0x0c059d1au: goto P_0c059d1a;
case 0x0c059d1cu: goto P_0c059d1c;
case 0x0c059d1eu: goto P_0c059d1e;
case 0x0c059d20u: goto P_0c059d20;
case 0x0c059d22u: goto P_0c059d22;
case 0x0c059d24u: goto P_0c059d24;
case 0x0c059d26u: goto P_0c059d26;
case 0x0c059d28u: goto P_0c059d28;
case 0x0c059d2au: goto P_0c059d2a;
case 0x0c059d2cu: goto P_0c059d2c;
case 0x0c059d2eu: goto P_0c059d2e;
case 0x0c059d30u: goto P_0c059d30;
case 0x0c059d32u: goto P_0c059d32;
case 0x0c059d34u: goto P_0c059d34;
case 0x0c059d36u: goto P_0c059d36;
case 0x0c059d38u: goto P_0c059d38;
case 0x0c059d3au: goto P_0c059d3a;
case 0x0c059d3cu: goto P_0c059d3c;
case 0x0c059d3eu: goto P_0c059d3e;
case 0x0c059d40u: goto P_0c059d40;
case 0x0c059d42u: goto P_0c059d42;
case 0x0c059d44u: goto P_0c059d44;
case 0x0c059d46u: goto P_0c059d46;
case 0x0c059d48u: goto P_0c059d48;
case 0x0c059d4au: goto P_0c059d4a;
case 0x0c059d4cu: goto P_0c059d4c;
case 0x0c059d4eu: goto P_0c059d4e;
case 0x0c059d50u: goto P_0c059d50;
case 0x0c059d52u: goto P_0c059d52;
case 0x0c059d54u: goto P_0c059d54;
case 0x0c059d56u: goto P_0c059d56;
case 0x0c059d58u: goto P_0c059d58;
case 0x0c059d5au: goto P_0c059d5a;
case 0x0c059d5cu: goto P_0c059d5c;
case 0x0c059d5eu: goto P_0c059d5e;
case 0x0c059d60u: goto P_0c059d60;
case 0x0c059d62u: goto P_0c059d62;
case 0x0c059d64u: goto P_0c059d64;
case 0x0c059d66u: goto P_0c059d66;
case 0x0c059d68u: goto P_0c059d68;
case 0x0c059d6au: goto P_0c059d6a;
case 0x0c059d6cu: goto P_0c059d6c;
case 0x0c059d6eu: goto P_0c059d6e;
case 0x0c059d70u: goto P_0c059d70;
case 0x0c05e12eu: goto P_0c05e12e;
case 0x0c05e130u: goto P_0c05e130;
case 0x0c05e132u: goto P_0c05e132;
case 0x0c05e134u: goto P_0c05e134;
case 0x0c05e136u: goto P_0c05e136;
case 0x0c05e138u: goto P_0c05e138;
case 0x0c05e13au: goto P_0c05e13a;
case 0x0c05e13cu: goto P_0c05e13c;
case 0x0c05e13eu: goto P_0c05e13e;
case 0x0c05e140u: goto P_0c05e140;
case 0x0c05e142u: goto P_0c05e142;
case 0x0c05e144u: goto P_0c05e144;
case 0x0c05e146u: goto P_0c05e146;
case 0x0c05e148u: goto P_0c05e148;
case 0x0c05e14au: goto P_0c05e14a;
case 0x0c05e14cu: goto P_0c05e14c;
case 0x0c05e14eu: goto P_0c05e14e;
case 0x0c05e150u: goto P_0c05e150;
case 0x0c05e152u: goto P_0c05e152;
case 0x0c05e154u: goto P_0c05e154;
case 0x0c05e156u: goto P_0c05e156;
case 0x0c05e158u: goto P_0c05e158;
case 0x0c05e15au: goto P_0c05e15a;
case 0x0c05e15cu: goto P_0c05e15c;
case 0x0c05e15eu: goto P_0c05e15e;
case 0x0c05e160u: goto P_0c05e160;
case 0x0c05e162u: goto P_0c05e162;
case 0x0c05e164u: goto P_0c05e164;
case 0x0c05e166u: goto P_0c05e166;
case 0x0c05e168u: goto P_0c05e168;
case 0x0c05e16au: goto P_0c05e16a;
case 0x0c05e16cu: goto P_0c05e16c;
case 0x0c05e16eu: goto P_0c05e16e;
case 0x0c05e170u: goto P_0c05e170;
case 0x0c05e172u: goto P_0c05e172;
case 0x0c05e174u: goto P_0c05e174;
case 0x0c05e176u: goto P_0c05e176;
case 0x0c05e178u: goto P_0c05e178;
case 0x0c05e17au: goto P_0c05e17a;
case 0x0c05e17cu: goto P_0c05e17c;
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
case 0x0c063446u: goto P_0c063446;
case 0x0c063448u: goto P_0c063448;
case 0x0c06344au: goto P_0c06344a;
case 0x0c06344cu: goto P_0c06344c;
case 0x0c06344eu: goto P_0c06344e;
case 0x0c063450u: goto P_0c063450;
case 0x0c063452u: goto P_0c063452;
case 0x0c063454u: goto P_0c063454;
case 0x0c063456u: goto P_0c063456;
case 0x0c063458u: goto P_0c063458;
case 0x0c06345au: goto P_0c06345a;
case 0x0c06345cu: goto P_0c06345c;
case 0x0c06345eu: goto P_0c06345e;
case 0x0c063460u: goto P_0c063460;
case 0x0c063462u: goto P_0c063462;
case 0x0c063464u: goto P_0c063464;
case 0x0c063466u: goto P_0c063466;
case 0x0c063468u: goto P_0c063468;
case 0x0c06346au: goto P_0c06346a;
case 0x0c06346cu: goto P_0c06346c;
case 0x0c06346eu: goto P_0c06346e;
case 0x0c063470u: goto P_0c063470;
case 0x0c063472u: goto P_0c063472;
case 0x0c063474u: goto P_0c063474;
case 0x0c063476u: goto P_0c063476;
case 0x0c063478u: goto P_0c063478;
case 0x0c06347au: goto P_0c06347a;
case 0x0c06347cu: goto P_0c06347c;
case 0x0c06347eu: goto P_0c06347e;
case 0x0c063480u: goto P_0c063480;
case 0x0c063482u: goto P_0c063482;
case 0x0c063484u: goto P_0c063484;
case 0x0c063486u: goto P_0c063486;
case 0x0c063488u: goto P_0c063488;
case 0x0c06348au: goto P_0c06348a;
case 0x0c06348cu: goto P_0c06348c;
case 0x0c06348eu: goto P_0c06348e;
case 0x0c063490u: goto P_0c063490;
case 0x0c063492u: goto P_0c063492;
case 0x0c063494u: goto P_0c063494;
case 0x0c063496u: goto P_0c063496;
case 0x0c063498u: goto P_0c063498;
case 0x0c06349au: goto P_0c06349a;
case 0x0c06349cu: goto P_0c06349c;
case 0x0c06349eu: goto P_0c06349e;
case 0x0c0634a0u: goto P_0c0634a0;
case 0x0c0634a2u: goto P_0c0634a2;
case 0x0c0634a4u: goto P_0c0634a4;
case 0x0c0634a6u: goto P_0c0634a6;
case 0x0c0634a8u: goto P_0c0634a8;
case 0x0c0634aau: goto P_0c0634aa;
case 0x0c0634acu: goto P_0c0634ac;
case 0x0c0634aeu: goto P_0c0634ae;
case 0x0c0634b0u: goto P_0c0634b0;
case 0x0c0634b2u: goto P_0c0634b2;
case 0x0c0634b4u: goto P_0c0634b4;
case 0x0c0634b6u: goto P_0c0634b6;
case 0x0c0634b8u: goto P_0c0634b8;
case 0x0c0634bau: goto P_0c0634ba;
case 0x0c0634bcu: goto P_0c0634bc;
case 0x0c0634beu: goto P_0c0634be;
case 0x0c0634c0u: goto P_0c0634c0;
case 0x0c0634c2u: goto P_0c0634c2;
case 0x0c0634c4u: goto P_0c0634c4;
case 0x0c0634c6u: goto P_0c0634c6;
case 0x0c0634c8u: goto P_0c0634c8;
case 0x0c0634cau: goto P_0c0634ca;
case 0x0c0634ccu: goto P_0c0634cc;
case 0x0c0634ceu: goto P_0c0634ce;
case 0x0c0634d0u: goto P_0c0634d0;
case 0x0c0634d2u: goto P_0c0634d2;
case 0x0c0634d4u: goto P_0c0634d4;
case 0x0c0634d6u: goto P_0c0634d6;
case 0x0c0634d8u: goto P_0c0634d8;
case 0x0c0634dau: goto P_0c0634da;
case 0x0c0634dcu: goto P_0c0634dc;
case 0x0c0634deu: goto P_0c0634de;
case 0x0c0634e0u: goto P_0c0634e0;
case 0x0c0634e2u: goto P_0c0634e2;
case 0x0c0634e4u: goto P_0c0634e4;
case 0x0c0634e6u: goto P_0c0634e6;
case 0x0c0634e8u: goto P_0c0634e8;
case 0x0c0634eau: goto P_0c0634ea;
case 0x0c0634ecu: goto P_0c0634ec;
case 0x0c06351cu: goto P_0c06351c;
case 0x0c06351eu: goto P_0c06351e;
case 0x0c063520u: goto P_0c063520;
case 0x0c063522u: goto P_0c063522;
case 0x0c063524u: goto P_0c063524;
case 0x0c063526u: goto P_0c063526;
case 0x0c063528u: goto P_0c063528;
case 0x0c06352au: goto P_0c06352a;
case 0x0c06352cu: goto P_0c06352c;
case 0x0c06352eu: goto P_0c06352e;
case 0x0c063530u: goto P_0c063530;
case 0x0c063532u: goto P_0c063532;
case 0x0c063534u: goto P_0c063534;
case 0x0c063536u: goto P_0c063536;
case 0x0c063538u: goto P_0c063538;
case 0x0c06353au: goto P_0c06353a;
case 0x0c06353cu: goto P_0c06353c;
case 0x0c06353eu: goto P_0c06353e;
case 0x0c063540u: goto P_0c063540;
case 0x0c063542u: goto P_0c063542;
case 0x0c063544u: goto P_0c063544;
case 0x0c063546u: goto P_0c063546;
case 0x0c063548u: goto P_0c063548;
case 0x0c06354au: goto P_0c06354a;
case 0x0c06354cu: goto P_0c06354c;
case 0x0c06354eu: goto P_0c06354e;
case 0x0c063550u: goto P_0c063550;
case 0x0c063552u: goto P_0c063552;
case 0x0c063554u: goto P_0c063554;
case 0x0c063556u: goto P_0c063556;
case 0x0c063558u: goto P_0c063558;
case 0x0c06355au: goto P_0c06355a;
case 0x0c06355cu: goto P_0c06355c;
case 0x0c06355eu: goto P_0c06355e;
case 0x0c063560u: goto P_0c063560;
case 0x0c063562u: goto P_0c063562;
case 0x0c063564u: goto P_0c063564;
case 0x0c063566u: goto P_0c063566;
case 0x0c063568u: goto P_0c063568;
case 0x0c06356au: goto P_0c06356a;
case 0x0c06356cu: goto P_0c06356c;
case 0x0c06356eu: goto P_0c06356e;
case 0x0c063570u: goto P_0c063570;
case 0x0c063572u: goto P_0c063572;
case 0x0c063574u: goto P_0c063574;
case 0x0c063576u: goto P_0c063576;
case 0x0c063578u: goto P_0c063578;
case 0x0c06357au: goto P_0c06357a;
case 0x0c06357cu: goto P_0c06357c;
case 0x0c06357eu: goto P_0c06357e;
case 0x0c063580u: goto P_0c063580;
case 0x0c063582u: goto P_0c063582;
case 0x0c063584u: goto P_0c063584;
case 0x0c063586u: goto P_0c063586;
case 0x0c063588u: goto P_0c063588;
case 0x0c06358au: goto P_0c06358a;
case 0x0c06358cu: goto P_0c06358c;
case 0x0c06358eu: goto P_0c06358e;
case 0x0c063590u: goto P_0c063590;
case 0x0c063592u: goto P_0c063592;
case 0x0c063594u: goto P_0c063594;
case 0x0c063596u: goto P_0c063596;
case 0x0c063598u: goto P_0c063598;
case 0x0c06359au: goto P_0c06359a;
case 0x0c06359cu: goto P_0c06359c;
case 0x0c06359eu: goto P_0c06359e;
case 0x0c0635a0u: goto P_0c0635a0;
case 0x0c0635a2u: goto P_0c0635a2;
case 0x0c0635a4u: goto P_0c0635a4;
case 0x0c0635a6u: goto P_0c0635a6;
case 0x0c0635a8u: goto P_0c0635a8;
case 0x0c0635aau: goto P_0c0635aa;
case 0x0c0635acu: goto P_0c0635ac;
case 0x0c0635aeu: goto P_0c0635ae;
case 0x0c0635b0u: goto P_0c0635b0;
case 0x0c0635b2u: goto P_0c0635b2;
case 0x0c0635b4u: goto P_0c0635b4;
case 0x0c0635b6u: goto P_0c0635b6;
case 0x0c0635b8u: goto P_0c0635b8;
case 0x0c0635bau: goto P_0c0635ba;
case 0x0c0635bcu: goto P_0c0635bc;
case 0x0c0635beu: goto P_0c0635be;
case 0x0c0635c0u: goto P_0c0635c0;
case 0x0c0635c2u: goto P_0c0635c2;
case 0x0c0635c4u: goto P_0c0635c4;
case 0x0c0635c6u: goto P_0c0635c6;
case 0x0c0635c8u: goto P_0c0635c8;
case 0x0c0635cau: goto P_0c0635ca;
case 0x0c0635ccu: goto P_0c0635cc;
case 0x0c0635ceu: goto P_0c0635ce;
case 0x0c0635d0u: goto P_0c0635d0;
case 0x0c0635d2u: goto P_0c0635d2;
case 0x0c0635d4u: goto P_0c0635d4;
case 0x0c0635d6u: goto P_0c0635d6;
case 0x0c0635d8u: goto P_0c0635d8;
case 0x0c0635dau: goto P_0c0635da;
case 0x0c0635dcu: goto P_0c0635dc;
case 0x0c0635deu: goto P_0c0635de;
case 0x0c0635e0u: goto P_0c0635e0;
case 0x0c0635e2u: goto P_0c0635e2;
case 0x0c0635e4u: goto P_0c0635e4;
case 0x0c0635e6u: goto P_0c0635e6;
case 0x0c0635e8u: goto P_0c0635e8;
case 0x0c0635eau: goto P_0c0635ea;
case 0x0c0635ecu: goto P_0c0635ec;
case 0x0c0635eeu: goto P_0c0635ee;
case 0x0c0635f0u: goto P_0c0635f0;
case 0x0c0635f2u: goto P_0c0635f2;
case 0x0c0635f4u: goto P_0c0635f4;
case 0x0c0635f6u: goto P_0c0635f6;
case 0x0c0635f8u: goto P_0c0635f8;
case 0x0c0635fau: goto P_0c0635fa;
case 0x0c0635fcu: goto P_0c0635fc;
case 0x0c0635feu: goto P_0c0635fe;
case 0x0c063600u: goto P_0c063600;
case 0x0c063602u: goto P_0c063602;
case 0x0c063604u: goto P_0c063604;
case 0x0c063606u: goto P_0c063606;
case 0x0c063608u: goto P_0c063608;
case 0x0c06360au: goto P_0c06360a;
case 0x0c06360cu: goto P_0c06360c;
case 0x0c06360eu: goto P_0c06360e;
case 0x0c063610u: goto P_0c063610;
case 0x0c063612u: goto P_0c063612;
case 0x0c063614u: goto P_0c063614;
case 0x0c063680u: goto P_0c063680;
case 0x0c063682u: goto P_0c063682;
case 0x0c063684u: goto P_0c063684;
case 0x0c063686u: goto P_0c063686;
case 0x0c063688u: goto P_0c063688;
case 0x0c06368au: goto P_0c06368a;
case 0x0c06368cu: goto P_0c06368c;
case 0x0c06368eu: goto P_0c06368e;
case 0x0c063690u: goto P_0c063690;
case 0x0c063692u: goto P_0c063692;
case 0x0c063694u: goto P_0c063694;
case 0x0c063696u: goto P_0c063696;
case 0x0c063698u: goto P_0c063698;
case 0x0c06369au: goto P_0c06369a;
case 0x0c06369cu: goto P_0c06369c;
case 0x0c06369eu: goto P_0c06369e;
case 0x0c06371cu: goto P_0c06371c;
case 0x0c06371eu: goto P_0c06371e;
case 0x0c063720u: goto P_0c063720;
case 0x0c063722u: goto P_0c063722;
case 0x0c063724u: goto P_0c063724;
case 0x0c063726u: goto P_0c063726;
case 0x0c063728u: goto P_0c063728;
case 0x0c06372au: goto P_0c06372a;
case 0x0c06372cu: goto P_0c06372c;
case 0x0c06372eu: goto P_0c06372e;
case 0x0c063730u: goto P_0c063730;
case 0x0c063732u: goto P_0c063732;
case 0x0c063734u: goto P_0c063734;
case 0x0c063736u: goto P_0c063736;
case 0x0c063738u: goto P_0c063738;
case 0x0c06373au: goto P_0c06373a;
case 0x0c06373cu: goto P_0c06373c;
case 0x0c06373eu: goto P_0c06373e;
case 0x0c063740u: goto P_0c063740;
case 0x0c063742u: goto P_0c063742;
case 0x0c063744u: goto P_0c063744;
case 0x0c063746u: goto P_0c063746;
case 0x0c063748u: goto P_0c063748;
case 0x0c06374au: goto P_0c06374a;
case 0x0c06374cu: goto P_0c06374c;
case 0x0c06374eu: goto P_0c06374e;
case 0x0c063750u: goto P_0c063750;
case 0x0c063752u: goto P_0c063752;
case 0x0c063754u: goto P_0c063754;
case 0x0c063756u: goto P_0c063756;
case 0x0c063758u: goto P_0c063758;
case 0x0c06375au: goto P_0c06375a;
case 0x0c06375cu: goto P_0c06375c;
case 0x0c06375eu: goto P_0c06375e;
case 0x0c063760u: goto P_0c063760;
case 0x0c063762u: goto P_0c063762;
case 0x0c063764u: goto P_0c063764;
case 0x0c063766u: goto P_0c063766;
case 0x0c063768u: goto P_0c063768;
case 0x0c06376au: goto P_0c06376a;
case 0x0c0734feu: goto P_0c0734fe;
case 0x0c073500u: goto P_0c073500;
case 0x0c073502u: goto P_0c073502;
case 0x0c073504u: goto P_0c073504;
case 0x0c073506u: goto P_0c073506;
case 0x0c073508u: goto P_0c073508;
case 0x0c07350au: goto P_0c07350a;
case 0x0c07350cu: goto P_0c07350c;
case 0x0c07350eu: goto P_0c07350e;
case 0x0c073510u: goto P_0c073510;
case 0x0c073512u: goto P_0c073512;
case 0x0c073514u: goto P_0c073514;
case 0x0c073516u: goto P_0c073516;
case 0x0c073518u: goto P_0c073518;
case 0x0c07351au: goto P_0c07351a;
case 0x0c07351cu: goto P_0c07351c;
case 0x0c07351eu: goto P_0c07351e;
case 0x0c073520u: goto P_0c073520;
case 0x0c073522u: goto P_0c073522;
case 0x0c073524u: goto P_0c073524;
case 0x0c073526u: goto P_0c073526;
case 0x0c073528u: goto P_0c073528;
case 0x0c07352au: goto P_0c07352a;
case 0x0c07352cu: goto P_0c07352c;
case 0x0c07352eu: goto P_0c07352e;
case 0x0c073530u: goto P_0c073530;
case 0x0c073532u: goto P_0c073532;
case 0x0c073534u: goto P_0c073534;
case 0x0c073536u: goto P_0c073536;
case 0x0c073538u: goto P_0c073538;
case 0x0c07353au: goto P_0c07353a;
case 0x0c07353cu: goto P_0c07353c;
case 0x0c07353eu: goto P_0c07353e;
case 0x0c073540u: goto P_0c073540;
case 0x0c09457eu: goto P_0c09457e;
case 0x0c094580u: goto P_0c094580;
case 0x0c094582u: goto P_0c094582;
case 0x0c094584u: goto P_0c094584;
case 0x0c094586u: goto P_0c094586;
case 0x0c094588u: goto P_0c094588;
case 0x0c09458au: goto P_0c09458a;
case 0x0c09458cu: goto P_0c09458c;
case 0x0c09458eu: goto P_0c09458e;
case 0x0c094590u: goto P_0c094590;
case 0x0c094592u: goto P_0c094592;
case 0x0c094594u: goto P_0c094594;
case 0x0c094596u: goto P_0c094596;
case 0x0c094598u: goto P_0c094598;
case 0x0c09459au: goto P_0c09459a;
case 0x0c09459cu: goto P_0c09459c;
case 0x0c09459eu: goto P_0c09459e;
case 0x0c0945a0u: goto P_0c0945a0;
case 0x0c0945a2u: goto P_0c0945a2;
case 0x0c0945a4u: goto P_0c0945a4;
case 0x0c0945a6u: goto P_0c0945a6;
case 0x0c0945a8u: goto P_0c0945a8;
case 0x0c0945aau: goto P_0c0945aa;
case 0x0c0945acu: goto P_0c0945ac;
case 0x0c0945aeu: goto P_0c0945ae;
case 0x0c0945b0u: goto P_0c0945b0;
case 0x0c0945b2u: goto P_0c0945b2;
case 0x0c0945b4u: goto P_0c0945b4;
case 0x0c0945b6u: goto P_0c0945b6;
case 0x0c0945b8u: goto P_0c0945b8;
case 0x0c0945bau: goto P_0c0945ba;
case 0x0c0945bcu: goto P_0c0945bc;
case 0x0c0945beu: goto P_0c0945be;
case 0x0c0945c0u: goto P_0c0945c0;
case 0x0c0945c2u: goto P_0c0945c2;
case 0x0c0945c4u: goto P_0c0945c4;
case 0x0c0945c6u: goto P_0c0945c6;
case 0x0c0945c8u: goto P_0c0945c8;
case 0x0c0945cau: goto P_0c0945ca;
case 0x0c0945ccu: goto P_0c0945cc;
case 0x0c0945ceu: goto P_0c0945ce;
case 0x0c0945d0u: goto P_0c0945d0;
case 0x0c0945d2u: goto P_0c0945d2;
case 0x0c0945d4u: goto P_0c0945d4;
case 0x0c0945d6u: goto P_0c0945d6;
case 0x0c0945d8u: goto P_0c0945d8;
case 0x0c0945dau: goto P_0c0945da;
case 0x0c0945dcu: goto P_0c0945dc;
case 0x0c0945deu: goto P_0c0945de;
case 0x0c0945e0u: goto P_0c0945e0;
case 0x0c0945e2u: goto P_0c0945e2;
case 0x0c0945e4u: goto P_0c0945e4;
case 0x0c0945e6u: goto P_0c0945e6;
case 0x0c0945e8u: goto P_0c0945e8;
case 0x0c0945eau: goto P_0c0945ea;
case 0x0c0945ecu: goto P_0c0945ec;
case 0x0c0945eeu: goto P_0c0945ee;
case 0x0c0945f0u: goto P_0c0945f0;
case 0x0c097ff4u: goto P_0c097ff4;
case 0x0c097ff6u: goto P_0c097ff6;
case 0x0c097ff8u: goto P_0c097ff8;
case 0x0c097ffau: goto P_0c097ffa;
case 0x0c097ffcu: goto P_0c097ffc;
case 0x0c097ffeu: goto P_0c097ffe;
case 0x0c098000u: goto P_0c098000;
case 0x0c098002u: goto P_0c098002;
case 0x0c098004u: goto P_0c098004;
case 0x0c098006u: goto P_0c098006;
case 0x0c098008u: goto P_0c098008;
case 0x0c09800au: goto P_0c09800a;
case 0x0c09800cu: goto P_0c09800c;
case 0x0c09800eu: goto P_0c09800e;
case 0x0c098010u: goto P_0c098010;
case 0x0c098012u: goto P_0c098012;
case 0x0c098014u: goto P_0c098014;
case 0x0c098016u: goto P_0c098016;
case 0x0c098018u: goto P_0c098018;
case 0x0c09801au: goto P_0c09801a;
case 0x0c09801cu: goto P_0c09801c;
case 0x0c09801eu: goto P_0c09801e;
case 0x0c098020u: goto P_0c098020;
case 0x0c098022u: goto P_0c098022;
case 0x0c098024u: goto P_0c098024;
case 0x0c098026u: goto P_0c098026;
case 0x0c098028u: goto P_0c098028;
case 0x0c09802au: goto P_0c09802a;
case 0x0c09802cu: goto P_0c09802c;
case 0x0c09802eu: goto P_0c09802e;
case 0x0c098030u: goto P_0c098030;
case 0x0c098032u: goto P_0c098032;
case 0x0c098034u: goto P_0c098034;
case 0x0c098036u: goto P_0c098036;
case 0x0c098038u: goto P_0c098038;
case 0x0c09803au: goto P_0c09803a;
case 0x0c09803cu: goto P_0c09803c;
case 0x0c09803eu: goto P_0c09803e;
case 0x0c0983c6u: goto P_0c0983c6;
case 0x0c0983c8u: goto P_0c0983c8;
case 0x0c0983cau: goto P_0c0983ca;
case 0x0c0983ccu: goto P_0c0983cc;
case 0x0c0983ceu: goto P_0c0983ce;
case 0x0c0983d0u: goto P_0c0983d0;
case 0x0c0983d2u: goto P_0c0983d2;
case 0x0c0983d4u: goto P_0c0983d4;
case 0x0c0983d6u: goto P_0c0983d6;
case 0x0c0983d8u: goto P_0c0983d8;
case 0x0c0983dau: goto P_0c0983da;
case 0x0c0983dcu: goto P_0c0983dc;
case 0x0c0983deu: goto P_0c0983de;
case 0x0c0983e0u: goto P_0c0983e0;
case 0x0c0983e2u: goto P_0c0983e2;
case 0x0c0983e4u: goto P_0c0983e4;
case 0x0c0983e6u: goto P_0c0983e6;
case 0x0c0983e8u: goto P_0c0983e8;
case 0x0c0983eau: goto P_0c0983ea;
case 0x0c0983ecu: goto P_0c0983ec;
case 0x0c0983eeu: goto P_0c0983ee;
case 0x0c0983f0u: goto P_0c0983f0;
case 0x0c0983f2u: goto P_0c0983f2;
case 0x0c0983f4u: goto P_0c0983f4;
case 0x0c0983f6u: goto P_0c0983f6;
case 0x0c0983f8u: goto P_0c0983f8;
case 0x0c0983fau: goto P_0c0983fa;
case 0x0c0983fcu: goto P_0c0983fc;
case 0x0c0983feu: goto P_0c0983fe;
case 0x0c098400u: goto P_0c098400;
case 0x0c098402u: goto P_0c098402;
case 0x0c098404u: goto P_0c098404;
case 0x0c098406u: goto P_0c098406;
case 0x0c098408u: goto P_0c098408;
case 0x0c09840au: goto P_0c09840a;
case 0x0c09840cu: goto P_0c09840c;
case 0x0c09840eu: goto P_0c09840e;
case 0x0c098410u: goto P_0c098410;
case 0x0c098412u: goto P_0c098412;
case 0x0c098414u: goto P_0c098414;
case 0x0c098416u: goto P_0c098416;
case 0x0c098418u: goto P_0c098418;
case 0x0c09841au: goto P_0c09841a;
case 0x0c09841cu: goto P_0c09841c;
case 0x0c09841eu: goto P_0c09841e;
case 0x0c098420u: goto P_0c098420;
case 0x0c098422u: goto P_0c098422;
case 0x0c098424u: goto P_0c098424;
case 0x0c098426u: goto P_0c098426;
case 0x0c098428u: goto P_0c098428;
case 0x0c09842au: goto P_0c09842a;
case 0x0c09842cu: goto P_0c09842c;
case 0x0c09842eu: goto P_0c09842e;
case 0x0c098430u: goto P_0c098430;
case 0x0c098432u: goto P_0c098432;
case 0x0c09aa14u: goto P_0c09aa14;
case 0x0c09aa16u: goto P_0c09aa16;
case 0x0c09aa18u: goto P_0c09aa18;
case 0x0c09aa1au: goto P_0c09aa1a;
case 0x0c09aa1cu: goto P_0c09aa1c;
case 0x0c09aa1eu: goto P_0c09aa1e;
case 0x0c09aa20u: goto P_0c09aa20;
case 0x0c09aa22u: goto P_0c09aa22;
case 0x0c09aa24u: goto P_0c09aa24;
case 0x0c09aa26u: goto P_0c09aa26;
case 0x0c09aa28u: goto P_0c09aa28;
case 0x0c09aa2au: goto P_0c09aa2a;
case 0x0c09aa2cu: goto P_0c09aa2c;
case 0x0c09aa2eu: goto P_0c09aa2e;
case 0x0c09aa30u: goto P_0c09aa30;
case 0x0c09aa32u: goto P_0c09aa32;
case 0x0c09aa34u: goto P_0c09aa34;
case 0x0c09aa36u: goto P_0c09aa36;
case 0x0c09aa38u: goto P_0c09aa38;
case 0x0c09aa3au: goto P_0c09aa3a;
case 0x0c09aa3cu: goto P_0c09aa3c;
case 0x0c09aa3eu: goto P_0c09aa3e;
case 0x0c09aa40u: goto P_0c09aa40;
case 0x0c09aa42u: goto P_0c09aa42;
case 0x0c09aa44u: goto P_0c09aa44;
case 0x0c09aa46u: goto P_0c09aa46;
case 0x0c09aa48u: goto P_0c09aa48;
case 0x0c09aa4au: goto P_0c09aa4a;
case 0x0c09aa4cu: goto P_0c09aa4c;
case 0x0c09aa4eu: goto P_0c09aa4e;
case 0x0c09aa50u: goto P_0c09aa50;
case 0x0c09aa52u: goto P_0c09aa52;
case 0x0c09aa54u: goto P_0c09aa54;
case 0x0c09aa56u: goto P_0c09aa56;
case 0x0c09aa58u: goto P_0c09aa58;
case 0x0c09aa5au: goto P_0c09aa5a;
case 0x0c09aa5cu: goto P_0c09aa5c;
case 0x0c09aa5eu: goto P_0c09aa5e;
case 0x0c09aa60u: goto P_0c09aa60;
case 0x0c09aa62u: goto P_0c09aa62;
case 0x0c09aa64u: goto P_0c09aa64;
case 0x0c09aa66u: goto P_0c09aa66;
case 0x0c09aa68u: goto P_0c09aa68;
case 0x0c09aa6au: goto P_0c09aa6a;
case 0x0c09aa6cu: goto P_0c09aa6c;
case 0x0c09aa6eu: goto P_0c09aa6e;
case 0x0c09aa70u: goto P_0c09aa70;
case 0x0c09aa72u: goto P_0c09aa72;
case 0x0c09aa74u: goto P_0c09aa74;
case 0x0c09aa76u: goto P_0c09aa76;
case 0x0c09aa78u: goto P_0c09aa78;
case 0x0c09aa7au: goto P_0c09aa7a;
case 0x0c09aa7cu: goto P_0c09aa7c;
case 0x0c09aa7eu: goto P_0c09aa7e;
case 0x0c09aa80u: goto P_0c09aa80;
case 0x0c09aa82u: goto P_0c09aa82;
case 0x0c09aa84u: goto P_0c09aa84;
case 0x0c09aa86u: goto P_0c09aa86;
case 0x0c09aa88u: goto P_0c09aa88;
case 0x0c09aa8au: goto P_0c09aa8a;
case 0x0c09aa8cu: goto P_0c09aa8c;
case 0x0c09aa8eu: goto P_0c09aa8e;
case 0x0c09aa90u: goto P_0c09aa90;
case 0x0c09aa92u: goto P_0c09aa92;
case 0x0c09aa94u: goto P_0c09aa94;
case 0x0c09aa96u: goto P_0c09aa96;
case 0x0c09aa98u: goto P_0c09aa98;
case 0x0c09aa9au: goto P_0c09aa9a;
case 0x0c09aa9cu: goto P_0c09aa9c;
case 0x0c09aa9eu: goto P_0c09aa9e;
case 0x0c09aaa0u: goto P_0c09aaa0;
case 0x0c09aaa2u: goto P_0c09aaa2;
case 0x0c09aaa4u: goto P_0c09aaa4;
case 0x0c09aaa6u: goto P_0c09aaa6;
case 0x0c09aaa8u: goto P_0c09aaa8;
case 0x0c09aaaau: goto P_0c09aaaa;
case 0x0c09aaacu: goto P_0c09aaac;
case 0x0c09aaaeu: goto P_0c09aaae;
case 0x0c09aab0u: goto P_0c09aab0;
case 0x0c09aab2u: goto P_0c09aab2;
case 0x0c09aab4u: goto P_0c09aab4;
case 0x0c09aab6u: goto P_0c09aab6;
case 0x0c09aab8u: goto P_0c09aab8;
case 0x0c09aabau: goto P_0c09aaba;
case 0x0c09aabcu: goto P_0c09aabc;
case 0x0c09aabeu: goto P_0c09aabe;
case 0x0c09aac0u: goto P_0c09aac0;
case 0x0c09aac2u: goto P_0c09aac2;
case 0x0c09aac4u: goto P_0c09aac4;
case 0x0c09aac6u: goto P_0c09aac6;
case 0x0c09aac8u: goto P_0c09aac8;
case 0x0c09aacau: goto P_0c09aaca;
case 0x0c09aaccu: goto P_0c09aacc;
case 0x0c09aaceu: goto P_0c09aace;
case 0x0c09aad0u: goto P_0c09aad0;
case 0x0c09aad2u: goto P_0c09aad2;
case 0x0c09aad4u: goto P_0c09aad4;
case 0x0c09aad6u: goto P_0c09aad6;
case 0x0c09aad8u: goto P_0c09aad8;
case 0x0c09aadau: goto P_0c09aada;
case 0x0c09aadcu: goto P_0c09aadc;
case 0x0c09aadeu: goto P_0c09aade;
case 0x0c09aae0u: goto P_0c09aae0;
case 0x0c09aae2u: goto P_0c09aae2;
case 0x0c09aae4u: goto P_0c09aae4;
case 0x0c09aae6u: goto P_0c09aae6;
case 0x0c09aae8u: goto P_0c09aae8;
case 0x0c09aaeau: goto P_0c09aaea;
case 0x0c09aaecu: goto P_0c09aaec;
case 0x0c09aaeeu: goto P_0c09aaee;
case 0x0c09aaf0u: goto P_0c09aaf0;
case 0x0c09aaf2u: goto P_0c09aaf2;
case 0x0c09aaf4u: goto P_0c09aaf4;
case 0x0c09aaf6u: goto P_0c09aaf6;
case 0x0c09aaf8u: goto P_0c09aaf8;
case 0x0c09aafau: goto P_0c09aafa;
case 0x0c09aafcu: goto P_0c09aafc;
case 0x0c09aafeu: goto P_0c09aafe;
case 0x0c09ab00u: goto P_0c09ab00;
case 0x0c09ab02u: goto P_0c09ab02;
case 0x0c09ab04u: goto P_0c09ab04;
case 0x0c09ab06u: goto P_0c09ab06;
case 0x0c09ab08u: goto P_0c09ab08;
case 0x0c09ab0au: goto P_0c09ab0a;
case 0x0c09ab0cu: goto P_0c09ab0c;
case 0x0c09ab0eu: goto P_0c09ab0e;
case 0x0c09ab10u: goto P_0c09ab10;
case 0x0c09ab12u: goto P_0c09ab12;
case 0x0c09ab14u: goto P_0c09ab14;
case 0x0c09ab16u: goto P_0c09ab16;
case 0x0c09ab18u: goto P_0c09ab18;
case 0x0c09ab1au: goto P_0c09ab1a;
case 0x0c09ab1cu: goto P_0c09ab1c;
case 0x0c09ab1eu: goto P_0c09ab1e;
case 0x0c09ab20u: goto P_0c09ab20;
case 0x0c09ab22u: goto P_0c09ab22;
case 0x0c09ab24u: goto P_0c09ab24;
case 0x0c09ab26u: goto P_0c09ab26;
case 0x0c09ab28u: goto P_0c09ab28;
case 0x0c09ab2au: goto P_0c09ab2a;
case 0x0c09ab2cu: goto P_0c09ab2c;
case 0x0c09ab2eu: goto P_0c09ab2e;
case 0x0c09ab30u: goto P_0c09ab30;
case 0x0c09ab32u: goto P_0c09ab32;
case 0x0c09ab34u: goto P_0c09ab34;
case 0x0c09ab36u: goto P_0c09ab36;
case 0x0c09ab38u: goto P_0c09ab38;
case 0x0c09ab3au: goto P_0c09ab3a;
case 0x0c09ab3cu: goto P_0c09ab3c;
case 0x0c09ab3eu: goto P_0c09ab3e;
case 0x0c09ab40u: goto P_0c09ab40;
case 0x0c09ab42u: goto P_0c09ab42;
case 0x0c09ab44u: goto P_0c09ab44;
case 0x0c09ab46u: goto P_0c09ab46;
case 0x0c09ab48u: goto P_0c09ab48;
case 0x0c09ab4au: goto P_0c09ab4a;
case 0x0c09ab4cu: goto P_0c09ab4c;
case 0x0c09ab4eu: goto P_0c09ab4e;
case 0x0c09ab50u: goto P_0c09ab50;
case 0x0c09ab52u: goto P_0c09ab52;
case 0x0c09ab54u: goto P_0c09ab54;
case 0x0c09ab56u: goto P_0c09ab56;
case 0x0c09ab58u: goto P_0c09ab58;
case 0x0c09ab5au: goto P_0c09ab5a;
case 0x0c09ab5cu: goto P_0c09ab5c;
case 0x0c09ab5eu: goto P_0c09ab5e;
case 0x0c09ab60u: goto P_0c09ab60;
case 0x0c09ab62u: goto P_0c09ab62;
case 0x0c0a1294u: goto P_0c0a1294;
case 0x0c0a1296u: goto P_0c0a1296;
case 0x0c0a1298u: goto P_0c0a1298;
case 0x0c0a129au: goto P_0c0a129a;
case 0x0c0a129cu: goto P_0c0a129c;
case 0x0c0a129eu: goto P_0c0a129e;
case 0x0c0a12a0u: goto P_0c0a12a0;
case 0x0c0a12a2u: goto P_0c0a12a2;
case 0x0c0a12a4u: goto P_0c0a12a4;
case 0x0c0a12a6u: goto P_0c0a12a6;
case 0x0c0a12a8u: goto P_0c0a12a8;
case 0x0c0a12aau: goto P_0c0a12aa;
case 0x0c0a12acu: goto P_0c0a12ac;
case 0x0c0a12aeu: goto P_0c0a12ae;
case 0x0c0a12b0u: goto P_0c0a12b0;
case 0x0c0a12b2u: goto P_0c0a12b2;
case 0x0c0a12b4u: goto P_0c0a12b4;
case 0x0c0a12b6u: goto P_0c0a12b6;
case 0x0c0a12b8u: goto P_0c0a12b8;
case 0x0c0a12bau: goto P_0c0a12ba;
case 0x0c0a12bcu: goto P_0c0a12bc;
case 0x0c0a12beu: goto P_0c0a12be;
case 0x0c0a12c0u: goto P_0c0a12c0;
case 0x0c0a2a84u: goto P_0c0a2a84;
case 0x0c0a2a86u: goto P_0c0a2a86;
case 0x0c0a2a88u: goto P_0c0a2a88;
case 0x0c0a2a8au: goto P_0c0a2a8a;
case 0x0c0a2a8cu: goto P_0c0a2a8c;
case 0x0c0a2a8eu: goto P_0c0a2a8e;
case 0x0c0a2a90u: goto P_0c0a2a90;
case 0x0c0a2a92u: goto P_0c0a2a92;
case 0x0c0a2a94u: goto P_0c0a2a94;
case 0x0c0a2a96u: goto P_0c0a2a96;
case 0x0c0a2a98u: goto P_0c0a2a98;
case 0x0c0a2a9au: goto P_0c0a2a9a;
case 0x0c0a2a9cu: goto P_0c0a2a9c;
case 0x0c0a2a9eu: goto P_0c0a2a9e;
case 0x0c0a2aa0u: goto P_0c0a2aa0;
case 0x0c0a2aa2u: goto P_0c0a2aa2;
case 0x0c0a2aa4u: goto P_0c0a2aa4;
case 0x0c0a2aa6u: goto P_0c0a2aa6;
case 0x0c0a2aa8u: goto P_0c0a2aa8;
case 0x0c0a2aaau: goto P_0c0a2aaa;
case 0x0c0a2aacu: goto P_0c0a2aac;
case 0x0c0a2aaeu: goto P_0c0a2aae;
case 0x0c0a2ab0u: goto P_0c0a2ab0;
case 0x0c0a2ab2u: goto P_0c0a2ab2;
case 0x0c0a2ab4u: goto P_0c0a2ab4;
case 0x0c0a2ab6u: goto P_0c0a2ab6;
case 0x0c0a2ab8u: goto P_0c0a2ab8;
case 0x0c0a2abau: goto P_0c0a2aba;
case 0x0c0a2abcu: goto P_0c0a2abc;
case 0x0c0a2abeu: goto P_0c0a2abe;
case 0x0c0a2ac0u: goto P_0c0a2ac0;
case 0x0c0a2ac2u: goto P_0c0a2ac2;
case 0x0c0a2ac4u: goto P_0c0a2ac4;
case 0x0c0a2ac6u: goto P_0c0a2ac6;
case 0x0c0a2ac8u: goto P_0c0a2ac8;
case 0x0c0a2acau: goto P_0c0a2aca;
case 0x0c0a2accu: goto P_0c0a2acc;
case 0x0c0a2aceu: goto P_0c0a2ace;
case 0x0c0a2ad0u: goto P_0c0a2ad0;
case 0x0c0a2ad2u: goto P_0c0a2ad2;
case 0x0c0a2ad4u: goto P_0c0a2ad4;
case 0x0c0a2ad6u: goto P_0c0a2ad6;
case 0x0c0a2ad8u: goto P_0c0a2ad8;
case 0x0c0a2adau: goto P_0c0a2ada;
case 0x0c0a2adcu: goto P_0c0a2adc;
case 0x0c0a2adeu: goto P_0c0a2ade;
case 0x0c0a2ae0u: goto P_0c0a2ae0;
case 0x0c0a2ae2u: goto P_0c0a2ae2;
case 0x0c0a2ae4u: goto P_0c0a2ae4;
case 0x0c0a2ae6u: goto P_0c0a2ae6;
case 0x0c0a2ae8u: goto P_0c0a2ae8;
case 0x0c0a2aeau: goto P_0c0a2aea;
case 0x0c0a2aecu: goto P_0c0a2aec;
case 0x0c0a2aeeu: goto P_0c0a2aee;
case 0x0c0a2af0u: goto P_0c0a2af0;
case 0x0c0a2af2u: goto P_0c0a2af2;
case 0x0c0a2af4u: goto P_0c0a2af4;
case 0x0c0a2af6u: goto P_0c0a2af6;
case 0x0c0a2af8u: goto P_0c0a2af8;
case 0x0c0a2afau: goto P_0c0a2afa;
case 0x0c0a2afcu: goto P_0c0a2afc;
case 0x0c0a2afeu: goto P_0c0a2afe;
case 0x0c0a2b00u: goto P_0c0a2b00;
case 0x0c0a2b02u: goto P_0c0a2b02;
case 0x0c0a2b04u: goto P_0c0a2b04;
case 0x0c0a2b06u: goto P_0c0a2b06;
case 0x0c0a2b08u: goto P_0c0a2b08;
case 0x0c0a2b0au: goto P_0c0a2b0a;
case 0x0c0a2b0cu: goto P_0c0a2b0c;
case 0x0c0a2b0eu: goto P_0c0a2b0e;
case 0x0c0a2b10u: goto P_0c0a2b10;
case 0x0c0a2b12u: goto P_0c0a2b12;
case 0x0c0a2b14u: goto P_0c0a2b14;
case 0x0c0a2b16u: goto P_0c0a2b16;
case 0x0c0a2b18u: goto P_0c0a2b18;
case 0x0c0a2b1au: goto P_0c0a2b1a;
case 0x0c0a2b1cu: goto P_0c0a2b1c;
case 0x0c0a2b1eu: goto P_0c0a2b1e;
case 0x0c0a2b20u: goto P_0c0a2b20;
case 0x0c0a2b22u: goto P_0c0a2b22;
case 0x0c0a2b24u: goto P_0c0a2b24;
case 0x0c0a2b26u: goto P_0c0a2b26;
case 0x0c0a2b28u: goto P_0c0a2b28;
case 0x0c0a2b2au: goto P_0c0a2b2a;
case 0x0c0a2b2cu: goto P_0c0a2b2c;
case 0x0c0a2b2eu: goto P_0c0a2b2e;
case 0x0c0a2b30u: goto P_0c0a2b30;
case 0x0c0a2b32u: goto P_0c0a2b32;
case 0x0c0a2b34u: goto P_0c0a2b34;
case 0x0c0a2b36u: goto P_0c0a2b36;
case 0x0c0a2b38u: goto P_0c0a2b38;
case 0x0c0a2b3au: goto P_0c0a2b3a;
case 0x0c0a2b3cu: goto P_0c0a2b3c;
case 0x0c0a2b3eu: goto P_0c0a2b3e;
case 0x0c0a2b40u: goto P_0c0a2b40;
case 0x0c0a2b42u: goto P_0c0a2b42;
case 0x0c0a2b44u: goto P_0c0a2b44;
case 0x0c0a2b46u: goto P_0c0a2b46;
case 0x0c0a2b48u: goto P_0c0a2b48;
case 0x0c0a2b4au: goto P_0c0a2b4a;
case 0x0c0a2b4cu: goto P_0c0a2b4c;
case 0x0c0a2b4eu: goto P_0c0a2b4e;
case 0x0c0a2b50u: goto P_0c0a2b50;
case 0x0c0a2b52u: goto P_0c0a2b52;
case 0x0c0a2b54u: goto P_0c0a2b54;
case 0x0c0a2b56u: goto P_0c0a2b56;
case 0x0c0a2b58u: goto P_0c0a2b58;
case 0x0c0a2b5au: goto P_0c0a2b5a;
case 0x0c0a2b5cu: goto P_0c0a2b5c;
case 0x0c0a2b5eu: goto P_0c0a2b5e;
case 0x0c0a2b60u: goto P_0c0a2b60;
case 0x0c0a2b62u: goto P_0c0a2b62;
case 0x0c0a2b64u: goto P_0c0a2b64;
case 0x0c0a2b66u: goto P_0c0a2b66;
case 0x0c0a2b68u: goto P_0c0a2b68;
case 0x0c0a2b6au: goto P_0c0a2b6a;
case 0x0c0a2b6cu: goto P_0c0a2b6c;
case 0x0c0a2b6eu: goto P_0c0a2b6e;
case 0x0c0a2b70u: goto P_0c0a2b70;
case 0x0c0a2b72u: goto P_0c0a2b72;
case 0x0c0a2b74u: goto P_0c0a2b74;
case 0x0c0a2b76u: goto P_0c0a2b76;
case 0x0c0a2b78u: goto P_0c0a2b78;
case 0x0c0a2b7au: goto P_0c0a2b7a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c035270: /* original 4f22, guest PC 0x0c035270 */
if(!s->budget--) { s->failed_pc=0x0c035270u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035272;
P_0c035272: /* original 6673, guest PC 0x0c035272 */
if(!s->budget--) { s->failed_pc=0x0c035272u; return 0; }
r[6]=r[7];
goto P_0c035274;
P_0c035274: /* original 7ff8, guest PC 0x0c035274 */
if(!s->budget--) { s->failed_pc=0x0c035274u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c035276;
P_0c035276: /* original 1f41, guest PC 0x0c035276 */
if(!s->budget--) { s->failed_pc=0x0c035276u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c035278;
P_0c035278: /* original 2f52, guest PC 0x0c035278 */
if(!s->budget--) { s->failed_pc=0x0c035278u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03527a;
P_0c03527a: /* original 6573, guest PC 0x0c03527a */
if(!s->budget--) { s->failed_pc=0x0c03527au; return 0; }
r[5]=r[7];
goto P_0c03527c;
P_0c03527c: /* original de83, guest PC 0x0c03527c */
if(!s->budget--) { s->failed_pc=0x0c03527cu; return 0; }
r[14]=read(ram,0x0c03548cu,4);
goto P_0c03527e;
P_0c03527e: /* original d384, guest PC 0x0c03527e */
if(!s->budget--) { s->failed_pc=0x0c03527eu; return 0; }
r[3]=read(ram,0x0c035490u,4);
goto P_0c035280;
P_0c035280: /* original 64e2, guest PC 0x0c035280 */
if(!s->budget--) { s->failed_pc=0x0c035280u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c035282;
P_0c035282: /* original 430b, guest PC 0x0c035282 */
if(!s->budget--) { s->failed_pc=0x0c035282u; return 0; }
target=r[3];
r[16]=code_base|0x0c035286u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035286u) { target=s->pc; goto dispatch; }
goto P_0c035286;
P_0c035284: /* original 544b, guest PC 0x0c035284 */
if(!s->budget--) { s->failed_pc=0x0c035284u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c035286;
P_0c035286: /* original 2008, guest PC 0x0c035286 */
if(!s->budget--) { s->failed_pc=0x0c035286u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c035288;
P_0c035288: /* original 8908, guest PC 0x0c035288 */
if(!s->budget--) { s->failed_pc=0x0c035288u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03529c; }
goto P_0c03528a;
P_0c03528a: /* original 63e2, guest PC 0x0c03528a */
if(!s->budget--) { s->failed_pc=0x0c03528au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03528c;
P_0c03528c: /* original 65f2, guest PC 0x0c03528c */
if(!s->budget--) { s->failed_pc=0x0c03528cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03528e;
P_0c03528e: /* original 5235, guest PC 0x0c03528e */
if(!s->budget--) { s->failed_pc=0x0c03528eu; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c035290;
P_0c035290: /* original 512e, guest PC 0x0c035290 */
if(!s->budget--) { s->failed_pc=0x0c035290u; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c035292;
P_0c035292: /* original 410b, guest PC 0x0c035292 */
if(!s->budget--) { s->failed_pc=0x0c035292u; return 0; }
target=r[1];
r[16]=code_base|0x0c035296u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035296u) { target=s->pc; goto dispatch; }
goto P_0c035296;
P_0c035294: /* original 54f1, guest PC 0x0c035294 */
if(!s->budget--) { s->failed_pc=0x0c035294u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c035296;
P_0c035296: /* original 6403, guest PC 0x0c035296 */
if(!s->budget--) { s->failed_pc=0x0c035296u; return 0; }
r[4]=r[0];
goto P_0c035298;
P_0c035298: /* original 2448, guest PC 0x0c035298 */
if(!s->budget--) { s->failed_pc=0x0c035298u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03529a;
P_0c03529a: /* original 8b04, guest PC 0x0c03529a */
if(!s->budget--) { s->failed_pc=0x0c03529au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0352a6; }
goto P_0c03529c;
P_0c03529c: /* original 7f08, guest PC 0x0c03529c */
if(!s->budget--) { s->failed_pc=0x0c03529cu; return 0; }
r[15]+=0x00000008u;
goto P_0c03529e;
P_0c03529e: /* original 4f26, guest PC 0x0c03529e */
if(!s->budget--) { s->failed_pc=0x0c03529eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352a0;
P_0c0352a0: /* original e0f3, guest PC 0x0c0352a0 */
if(!s->budget--) { s->failed_pc=0x0c0352a0u; return 0; }
r[0]=0xfffffff3u;
goto P_0c0352a2;
P_0c0352a2: /* original 000b, guest PC 0x0c0352a2 */
if(!s->budget--) { s->failed_pc=0x0c0352a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0352a4: /* original 6ef6, guest PC 0x0c0352a4 */
if(!s->budget--) { s->failed_pc=0x0c0352a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0352a6;
P_0c0352a6: /* original 62e2, guest PC 0x0c0352a6 */
if(!s->budget--) { s->failed_pc=0x0c0352a6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0352a8;
P_0c0352a8: /* original e04c, guest PC 0x0c0352a8 */
if(!s->budget--) { s->failed_pc=0x0c0352a8u; return 0; }
r[0]=0x0000004cu;
goto P_0c0352aa;
P_0c0352aa: /* original e104, guest PC 0x0c0352aa */
if(!s->budget--) { s->failed_pc=0x0c0352aau; return 0; }
r[1]=0x00000004u;
goto P_0c0352ac;
P_0c0352ac: /* original 532b, guest PC 0x0c0352ac */
if(!s->budget--) { s->failed_pc=0x0c0352acu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0352ae;
P_0c0352ae: /* original 134f, guest PC 0x0c0352ae */
if(!s->budget--) { s->failed_pc=0x0c0352aeu; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c0352b0;
P_0c0352b0: /* original 62e2, guest PC 0x0c0352b0 */
if(!s->budget--) { s->failed_pc=0x0c0352b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0352b2;
P_0c0352b2: /* original 532b, guest PC 0x0c0352b2 */
if(!s->budget--) { s->failed_pc=0x0c0352b2u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0352b4;
P_0c0352b4: /* original 0315, guest PC 0x0c0352b4 */
if(!s->budget--) { s->failed_pc=0x0c0352b4u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0352b6;
P_0c0352b6: /* original 63e2, guest PC 0x0c0352b6 */
if(!s->budget--) { s->failed_pc=0x0c0352b6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0352b8;
P_0c0352b8: /* original 6233, guest PC 0x0c0352b8 */
if(!s->budget--) { s->failed_pc=0x0c0352b8u; return 0; }
r[2]=r[3];
goto P_0c0352ba;
P_0c0352ba: /* original 512b, guest PC 0x0c0352ba */
if(!s->budget--) { s->failed_pc=0x0c0352bau; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c0352bc;
P_0c0352bc: /* original 131a, guest PC 0x0c0352bc */
if(!s->budget--) { s->failed_pc=0x0c0352bcu; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c0352be;
P_0c0352be: /* original d376, guest PC 0x0c0352be */
if(!s->budget--) { s->failed_pc=0x0c0352beu; return 0; }
r[3]=read(ram,0x0c035498u,4);
goto P_0c0352c0;
P_0c0352c0: /* original 64e2, guest PC 0x0c0352c0 */
if(!s->budget--) { s->failed_pc=0x0c0352c0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0352c2;
P_0c0352c2: /* original 430b, guest PC 0x0c0352c2 */
if(!s->budget--) { s->failed_pc=0x0c0352c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0352c6u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0352c6u) { target=s->pc; goto dispatch; }
goto P_0c0352c6;
P_0c0352c4: /* original 544b, guest PC 0x0c0352c4 */
if(!s->budget--) { s->failed_pc=0x0c0352c4u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0352c6;
P_0c0352c6: /* original 2f02, guest PC 0x0c0352c6 */
if(!s->budget--) { s->failed_pc=0x0c0352c6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0352c8;
P_0c0352c8: /* original d374, guest PC 0x0c0352c8 */
if(!s->budget--) { s->failed_pc=0x0c0352c8u; return 0; }
r[3]=read(ram,0x0c03549cu,4);
goto P_0c0352ca;
P_0c0352ca: /* original 64e2, guest PC 0x0c0352ca */
if(!s->budget--) { s->failed_pc=0x0c0352cau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0352cc;
P_0c0352cc: /* original 430b, guest PC 0x0c0352cc */
if(!s->budget--) { s->failed_pc=0x0c0352ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0352d0u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0352d0u) { target=s->pc; goto dispatch; }
goto P_0c0352d0;
P_0c0352ce: /* original 544b, guest PC 0x0c0352ce */
if(!s->budget--) { s->failed_pc=0x0c0352ceu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0352d0;
P_0c0352d0: /* original 60f2, guest PC 0x0c0352d0 */
if(!s->budget--) { s->failed_pc=0x0c0352d0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0352d2;
P_0c0352d2: /* original 7f08, guest PC 0x0c0352d2 */
if(!s->budget--) { s->failed_pc=0x0c0352d2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0352d4;
P_0c0352d4: /* original 4f26, guest PC 0x0c0352d4 */
if(!s->budget--) { s->failed_pc=0x0c0352d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352d6;
P_0c0352d6: /* original 000b, guest PC 0x0c0352d6 */
if(!s->budget--) { s->failed_pc=0x0c0352d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0352d8: /* original 6ef6, guest PC 0x0c0352d8 */
if(!s->budget--) { s->failed_pc=0x0c0352d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0352dau,s,ram);
P_0c035306: /* original 4f22, guest PC 0x0c035306 */
if(!s->budget--) { s->failed_pc=0x0c035306u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035308;
P_0c035308: /* original 7ff4, guest PC 0x0c035308 */
if(!s->budget--) { s->failed_pc=0x0c035308u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c03530a;
P_0c03530a: /* original 1f41, guest PC 0x0c03530a */
if(!s->budget--) { s->failed_pc=0x0c03530au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03530c;
P_0c03530c: /* original 2f52, guest PC 0x0c03530c */
if(!s->budget--) { s->failed_pc=0x0c03530cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03530e;
P_0c03530e: /* original 6573, guest PC 0x0c03530e */
if(!s->budget--) { s->failed_pc=0x0c03530eu; return 0; }
r[5]=r[7];
goto P_0c035310;
P_0c035310: /* original 1f62, guest PC 0x0c035310 */
if(!s->budget--) { s->failed_pc=0x0c035310u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c035312;
P_0c035312: /* original 6673, guest PC 0x0c035312 */
if(!s->budget--) { s->failed_pc=0x0c035312u; return 0; }
r[6]=r[7];
goto P_0c035314;
P_0c035314: /* original de5d, guest PC 0x0c035314 */
if(!s->budget--) { s->failed_pc=0x0c035314u; return 0; }
r[14]=read(ram,0x0c03548cu,4);
goto P_0c035316;
P_0c035316: /* original d35e, guest PC 0x0c035316 */
if(!s->budget--) { s->failed_pc=0x0c035316u; return 0; }
r[3]=read(ram,0x0c035490u,4);
goto P_0c035318;
P_0c035318: /* original 64e2, guest PC 0x0c035318 */
if(!s->budget--) { s->failed_pc=0x0c035318u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03531a;
P_0c03531a: /* original 430b, guest PC 0x0c03531a */
if(!s->budget--) { s->failed_pc=0x0c03531au; return 0; }
target=r[3];
r[16]=code_base|0x0c03531eu;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03531eu) { target=s->pc; goto dispatch; }
goto P_0c03531e;
P_0c03531c: /* original 544b, guest PC 0x0c03531c */
if(!s->budget--) { s->failed_pc=0x0c03531cu; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c03531e;
P_0c03531e: /* original 2008, guest PC 0x0c03531e */
if(!s->budget--) { s->failed_pc=0x0c03531eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c035320;
P_0c035320: /* original 8909, guest PC 0x0c035320 */
if(!s->budget--) { s->failed_pc=0x0c035320u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035336; }
goto P_0c035322;
P_0c035322: /* original 63e2, guest PC 0x0c035322 */
if(!s->budget--) { s->failed_pc=0x0c035322u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035324;
P_0c035324: /* original 65f2, guest PC 0x0c035324 */
if(!s->budget--) { s->failed_pc=0x0c035324u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c035326;
P_0c035326: /* original 5235, guest PC 0x0c035326 */
if(!s->budget--) { s->failed_pc=0x0c035326u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c035328;
P_0c035328: /* original 56f2, guest PC 0x0c035328 */
if(!s->budget--) { s->failed_pc=0x0c035328u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c03532a;
P_0c03532a: /* original 512a, guest PC 0x0c03532a */
if(!s->budget--) { s->failed_pc=0x0c03532au; return 0; }
r[1]=read(ram,r[2]+40,4);
goto P_0c03532c;
P_0c03532c: /* original 410b, guest PC 0x0c03532c */
if(!s->budget--) { s->failed_pc=0x0c03532cu; return 0; }
target=r[1];
r[16]=code_base|0x0c035330u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035330u) { target=s->pc; goto dispatch; }
goto P_0c035330;
P_0c03532e: /* original 54f1, guest PC 0x0c03532e */
if(!s->budget--) { s->failed_pc=0x0c03532eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c035330;
P_0c035330: /* original 6403, guest PC 0x0c035330 */
if(!s->budget--) { s->failed_pc=0x0c035330u; return 0; }
r[4]=r[0];
goto P_0c035332;
P_0c035332: /* original 2448, guest PC 0x0c035332 */
if(!s->budget--) { s->failed_pc=0x0c035332u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035334;
P_0c035334: /* original 8b04, guest PC 0x0c035334 */
if(!s->budget--) { s->failed_pc=0x0c035334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035340; }
goto P_0c035336;
P_0c035336: /* original 7f0c, guest PC 0x0c035336 */
if(!s->budget--) { s->failed_pc=0x0c035336u; return 0; }
r[15]+=0x0000000cu;
goto P_0c035338;
P_0c035338: /* original 4f26, guest PC 0x0c035338 */
if(!s->budget--) { s->failed_pc=0x0c035338u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03533a;
P_0c03533a: /* original e0f3, guest PC 0x0c03533a */
if(!s->budget--) { s->failed_pc=0x0c03533au; return 0; }
r[0]=0xfffffff3u;
goto P_0c03533c;
P_0c03533c: /* original 000b, guest PC 0x0c03533c */
if(!s->budget--) { s->failed_pc=0x0c03533cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03533e: /* original 6ef6, guest PC 0x0c03533e */
if(!s->budget--) { s->failed_pc=0x0c03533eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035340;
P_0c035340: /* original 62e2, guest PC 0x0c035340 */
if(!s->budget--) { s->failed_pc=0x0c035340u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035342;
P_0c035342: /* original e04c, guest PC 0x0c035342 */
if(!s->budget--) { s->failed_pc=0x0c035342u; return 0; }
r[0]=0x0000004cu;
goto P_0c035344;
P_0c035344: /* original e104, guest PC 0x0c035344 */
if(!s->budget--) { s->failed_pc=0x0c035344u; return 0; }
r[1]=0x00000004u;
goto P_0c035346;
P_0c035346: /* original 532b, guest PC 0x0c035346 */
if(!s->budget--) { s->failed_pc=0x0c035346u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c035348;
P_0c035348: /* original 134f, guest PC 0x0c035348 */
if(!s->budget--) { s->failed_pc=0x0c035348u; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c03534a;
P_0c03534a: /* original 62e2, guest PC 0x0c03534a */
if(!s->budget--) { s->failed_pc=0x0c03534au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03534c;
P_0c03534c: /* original 532b, guest PC 0x0c03534c */
if(!s->budget--) { s->failed_pc=0x0c03534cu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c03534e;
P_0c03534e: /* original 0315, guest PC 0x0c03534e */
if(!s->budget--) { s->failed_pc=0x0c03534eu; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c035350;
P_0c035350: /* original e044, guest PC 0x0c035350 */
if(!s->budget--) { s->failed_pc=0x0c035350u; return 0; }
r[0]=0x00000044u;
goto P_0c035352;
P_0c035352: /* original 63e2, guest PC 0x0c035352 */
if(!s->budget--) { s->failed_pc=0x0c035352u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c035354;
P_0c035354: /* original e106, guest PC 0x0c035354 */
if(!s->budget--) { s->failed_pc=0x0c035354u; return 0; }
r[1]=0x00000006u;
goto P_0c035356;
P_0c035356: /* original 523b, guest PC 0x0c035356 */
if(!s->budget--) { s->failed_pc=0x0c035356u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c035358;
P_0c035358: /* original 0215, guest PC 0x0c035358 */
if(!s->budget--) { s->failed_pc=0x0c035358u; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c03535a;
P_0c03535a: /* original 63e2, guest PC 0x0c03535a */
if(!s->budget--) { s->failed_pc=0x0c03535au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03535c;
P_0c03535c: /* original 6233, guest PC 0x0c03535c */
if(!s->budget--) { s->failed_pc=0x0c03535cu; return 0; }
r[2]=r[3];
goto P_0c03535e;
P_0c03535e: /* original 512b, guest PC 0x0c03535e */
if(!s->budget--) { s->failed_pc=0x0c03535eu; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c035360;
P_0c035360: /* original 131a, guest PC 0x0c035360 */
if(!s->budget--) { s->failed_pc=0x0c035360u; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c035362;
P_0c035362: /* original e000, guest PC 0x0c035362 */
if(!s->budget--) { s->failed_pc=0x0c035362u; return 0; }
r[0]=0x00000000u;
goto P_0c035364;
P_0c035364: /* original 7f0c, guest PC 0x0c035364 */
if(!s->budget--) { s->failed_pc=0x0c035364u; return 0; }
r[15]+=0x0000000cu;
goto P_0c035366;
P_0c035366: /* original 4f26, guest PC 0x0c035366 */
if(!s->budget--) { s->failed_pc=0x0c035366u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035368;
P_0c035368: /* original 000b, guest PC 0x0c035368 */
if(!s->budget--) { s->failed_pc=0x0c035368u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03536a: /* original 6ef6, guest PC 0x0c03536a */
if(!s->budget--) { s->failed_pc=0x0c03536au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03536cu,s,ram);
P_0c035370: /* original 4f22, guest PC 0x0c035370 */
if(!s->budget--) { s->failed_pc=0x0c035370u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c035372;
P_0c035372: /* original 7ff4, guest PC 0x0c035372 */
if(!s->budget--) { s->failed_pc=0x0c035372u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c035374;
P_0c035374: /* original 1f41, guest PC 0x0c035374 */
if(!s->budget--) { s->failed_pc=0x0c035374u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c035376;
P_0c035376: /* original 2f52, guest PC 0x0c035376 */
if(!s->budget--) { s->failed_pc=0x0c035376u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c035378;
P_0c035378: /* original 6573, guest PC 0x0c035378 */
if(!s->budget--) { s->failed_pc=0x0c035378u; return 0; }
r[5]=r[7];
goto P_0c03537a;
P_0c03537a: /* original 1f62, guest PC 0x0c03537a */
if(!s->budget--) { s->failed_pc=0x0c03537au; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c03537c;
P_0c03537c: /* original 6673, guest PC 0x0c03537c */
if(!s->budget--) { s->failed_pc=0x0c03537cu; return 0; }
r[6]=r[7];
goto P_0c03537e;
P_0c03537e: /* original de43, guest PC 0x0c03537e */
if(!s->budget--) { s->failed_pc=0x0c03537eu; return 0; }
r[14]=read(ram,0x0c03548cu,4);
goto P_0c035380;
P_0c035380: /* original d343, guest PC 0x0c035380 */
if(!s->budget--) { s->failed_pc=0x0c035380u; return 0; }
r[3]=read(ram,0x0c035490u,4);
goto P_0c035382;
P_0c035382: /* original 64e2, guest PC 0x0c035382 */
if(!s->budget--) { s->failed_pc=0x0c035382u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c035384;
P_0c035384: /* original 430b, guest PC 0x0c035384 */
if(!s->budget--) { s->failed_pc=0x0c035384u; return 0; }
target=r[3];
r[16]=code_base|0x0c035388u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035388u) { target=s->pc; goto dispatch; }
goto P_0c035388;
P_0c035386: /* original 544b, guest PC 0x0c035386 */
if(!s->budget--) { s->failed_pc=0x0c035386u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c035388;
P_0c035388: /* original 2008, guest PC 0x0c035388 */
if(!s->budget--) { s->failed_pc=0x0c035388u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03538a;
P_0c03538a: /* original 8909, guest PC 0x0c03538a */
if(!s->budget--) { s->failed_pc=0x0c03538au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0353a0; }
goto P_0c03538c;
P_0c03538c: /* original 63e2, guest PC 0x0c03538c */
if(!s->budget--) { s->failed_pc=0x0c03538cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03538e;
P_0c03538e: /* original 65f2, guest PC 0x0c03538e */
if(!s->budget--) { s->failed_pc=0x0c03538eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c035390;
P_0c035390: /* original 5235, guest PC 0x0c035390 */
if(!s->budget--) { s->failed_pc=0x0c035390u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c035392;
P_0c035392: /* original 56f2, guest PC 0x0c035392 */
if(!s->budget--) { s->failed_pc=0x0c035392u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c035394;
P_0c035394: /* original 512b, guest PC 0x0c035394 */
if(!s->budget--) { s->failed_pc=0x0c035394u; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c035396;
P_0c035396: /* original 410b, guest PC 0x0c035396 */
if(!s->budget--) { s->failed_pc=0x0c035396u; return 0; }
target=r[1];
r[16]=code_base|0x0c03539au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03539au) { target=s->pc; goto dispatch; }
goto P_0c03539a;
P_0c035398: /* original 54f1, guest PC 0x0c035398 */
if(!s->budget--) { s->failed_pc=0x0c035398u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03539a;
P_0c03539a: /* original 6403, guest PC 0x0c03539a */
if(!s->budget--) { s->failed_pc=0x0c03539au; return 0; }
r[4]=r[0];
goto P_0c03539c;
P_0c03539c: /* original 2448, guest PC 0x0c03539c */
if(!s->budget--) { s->failed_pc=0x0c03539cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03539e;
P_0c03539e: /* original 8b04, guest PC 0x0c03539e */
if(!s->budget--) { s->failed_pc=0x0c03539eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0353aa; }
goto P_0c0353a0;
P_0c0353a0: /* original 7f0c, guest PC 0x0c0353a0 */
if(!s->budget--) { s->failed_pc=0x0c0353a0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0353a2;
P_0c0353a2: /* original 4f26, guest PC 0x0c0353a2 */
if(!s->budget--) { s->failed_pc=0x0c0353a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0353a4;
P_0c0353a4: /* original e0f3, guest PC 0x0c0353a4 */
if(!s->budget--) { s->failed_pc=0x0c0353a4u; return 0; }
r[0]=0xfffffff3u;
goto P_0c0353a6;
P_0c0353a6: /* original 000b, guest PC 0x0c0353a6 */
if(!s->budget--) { s->failed_pc=0x0c0353a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0353a8: /* original 6ef6, guest PC 0x0c0353a8 */
if(!s->budget--) { s->failed_pc=0x0c0353a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0353aa;
P_0c0353aa: /* original 62e2, guest PC 0x0c0353aa */
if(!s->budget--) { s->failed_pc=0x0c0353aau; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0353ac;
P_0c0353ac: /* original e04c, guest PC 0x0c0353ac */
if(!s->budget--) { s->failed_pc=0x0c0353acu; return 0; }
r[0]=0x0000004cu;
goto P_0c0353ae;
P_0c0353ae: /* original e104, guest PC 0x0c0353ae */
if(!s->budget--) { s->failed_pc=0x0c0353aeu; return 0; }
r[1]=0x00000004u;
goto P_0c0353b0;
P_0c0353b0: /* original 532b, guest PC 0x0c0353b0 */
if(!s->budget--) { s->failed_pc=0x0c0353b0u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0353b2;
P_0c0353b2: /* original 134f, guest PC 0x0c0353b2 */
if(!s->budget--) { s->failed_pc=0x0c0353b2u; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c0353b4;
P_0c0353b4: /* original 62e2, guest PC 0x0c0353b4 */
if(!s->budget--) { s->failed_pc=0x0c0353b4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0353b6;
P_0c0353b6: /* original 532b, guest PC 0x0c0353b6 */
if(!s->budget--) { s->failed_pc=0x0c0353b6u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0353b8;
P_0c0353b8: /* original 0315, guest PC 0x0c0353b8 */
if(!s->budget--) { s->failed_pc=0x0c0353b8u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0353ba;
P_0c0353ba: /* original e044, guest PC 0x0c0353ba */
if(!s->budget--) { s->failed_pc=0x0c0353bau; return 0; }
r[0]=0x00000044u;
goto P_0c0353bc;
P_0c0353bc: /* original 63e2, guest PC 0x0c0353bc */
if(!s->budget--) { s->failed_pc=0x0c0353bcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0353be;
P_0c0353be: /* original e106, guest PC 0x0c0353be */
if(!s->budget--) { s->failed_pc=0x0c0353beu; return 0; }
r[1]=0x00000006u;
goto P_0c0353c0;
P_0c0353c0: /* original 523b, guest PC 0x0c0353c0 */
if(!s->budget--) { s->failed_pc=0x0c0353c0u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0353c2;
P_0c0353c2: /* original 0215, guest PC 0x0c0353c2 */
if(!s->budget--) { s->failed_pc=0x0c0353c2u; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c0353c4;
P_0c0353c4: /* original 63e2, guest PC 0x0c0353c4 */
if(!s->budget--) { s->failed_pc=0x0c0353c4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0353c6;
P_0c0353c6: /* original 6233, guest PC 0x0c0353c6 */
if(!s->budget--) { s->failed_pc=0x0c0353c6u; return 0; }
r[2]=r[3];
goto P_0c0353c8;
P_0c0353c8: /* original 512b, guest PC 0x0c0353c8 */
if(!s->budget--) { s->failed_pc=0x0c0353c8u; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c0353ca;
P_0c0353ca: /* original 131a, guest PC 0x0c0353ca */
if(!s->budget--) { s->failed_pc=0x0c0353cau; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c0353cc;
P_0c0353cc: /* original e000, guest PC 0x0c0353cc */
if(!s->budget--) { s->failed_pc=0x0c0353ccu; return 0; }
r[0]=0x00000000u;
goto P_0c0353ce;
P_0c0353ce: /* original 7f0c, guest PC 0x0c0353ce */
if(!s->budget--) { s->failed_pc=0x0c0353ceu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0353d0;
P_0c0353d0: /* original 4f26, guest PC 0x0c0353d0 */
if(!s->budget--) { s->failed_pc=0x0c0353d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0353d2;
P_0c0353d2: /* original 000b, guest PC 0x0c0353d2 */
if(!s->budget--) { s->failed_pc=0x0c0353d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0353d4: /* original 6ef6, guest PC 0x0c0353d4 */
if(!s->budget--) { s->failed_pc=0x0c0353d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0353d6u,s,ram);
P_0c0354a4: /* original 4f22, guest PC 0x0c0354a4 */
if(!s->budget--) { s->failed_pc=0x0c0354a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0354a6;
P_0c0354a6: /* original 6673, guest PC 0x0c0354a6 */
if(!s->budget--) { s->failed_pc=0x0c0354a6u; return 0; }
r[6]=r[7];
goto P_0c0354a8;
P_0c0354a8: /* original 6573, guest PC 0x0c0354a8 */
if(!s->budget--) { s->failed_pc=0x0c0354a8u; return 0; }
r[5]=r[7];
goto P_0c0354aa;
P_0c0354aa: /* original 7ffc, guest PC 0x0c0354aa */
if(!s->budget--) { s->failed_pc=0x0c0354aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0354ac;
P_0c0354ac: /* original 2f42, guest PC 0x0c0354ac */
if(!s->budget--) { s->failed_pc=0x0c0354acu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0354ae;
P_0c0354ae: /* original de15, guest PC 0x0c0354ae */
if(!s->budget--) { s->failed_pc=0x0c0354aeu; return 0; }
r[14]=read(ram,0x0c035504u,4);
goto P_0c0354b0;
P_0c0354b0: /* original d315, guest PC 0x0c0354b0 */
if(!s->budget--) { s->failed_pc=0x0c0354b0u; return 0; }
r[3]=read(ram,0x0c035508u,4);
goto P_0c0354b2;
P_0c0354b2: /* original 64e2, guest PC 0x0c0354b2 */
if(!s->budget--) { s->failed_pc=0x0c0354b2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0354b4;
P_0c0354b4: /* original 430b, guest PC 0x0c0354b4 */
if(!s->budget--) { s->failed_pc=0x0c0354b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0354b8u;
r[4]=read(ram,r[4]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0354b8u) { target=s->pc; goto dispatch; }
goto P_0c0354b8;
P_0c0354b6: /* original 544b, guest PC 0x0c0354b6 */
if(!s->budget--) { s->failed_pc=0x0c0354b6u; return 0; }
r[4]=read(ram,r[4]+44,4);
goto P_0c0354b8;
P_0c0354b8: /* original 2008, guest PC 0x0c0354b8 */
if(!s->budget--) { s->failed_pc=0x0c0354b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0354ba;
P_0c0354ba: /* original 8907, guest PC 0x0c0354ba */
if(!s->budget--) { s->failed_pc=0x0c0354bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0354cc; }
goto P_0c0354bc;
P_0c0354bc: /* original 63e2, guest PC 0x0c0354bc */
if(!s->budget--) { s->failed_pc=0x0c0354bcu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0354be;
P_0c0354be: /* original 5235, guest PC 0x0c0354be */
if(!s->budget--) { s->failed_pc=0x0c0354beu; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c0354c0;
P_0c0354c0: /* original 512d, guest PC 0x0c0354c0 */
if(!s->budget--) { s->failed_pc=0x0c0354c0u; return 0; }
r[1]=read(ram,r[2]+52,4);
goto P_0c0354c2;
P_0c0354c2: /* original 410b, guest PC 0x0c0354c2 */
if(!s->budget--) { s->failed_pc=0x0c0354c2u; return 0; }
target=r[1];
r[16]=code_base|0x0c0354c6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0354c6u) { target=s->pc; goto dispatch; }
goto P_0c0354c6;
P_0c0354c4: /* original 64f2, guest PC 0x0c0354c4 */
if(!s->budget--) { s->failed_pc=0x0c0354c4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0354c6;
P_0c0354c6: /* original 6403, guest PC 0x0c0354c6 */
if(!s->budget--) { s->failed_pc=0x0c0354c6u; return 0; }
r[4]=r[0];
goto P_0c0354c8;
P_0c0354c8: /* original 2448, guest PC 0x0c0354c8 */
if(!s->budget--) { s->failed_pc=0x0c0354c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0354ca;
P_0c0354ca: /* original 8b04, guest PC 0x0c0354ca */
if(!s->budget--) { s->failed_pc=0x0c0354cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0354d6; }
goto P_0c0354cc;
P_0c0354cc: /* original 7f04, guest PC 0x0c0354cc */
if(!s->budget--) { s->failed_pc=0x0c0354ccu; return 0; }
r[15]+=0x00000004u;
goto P_0c0354ce;
P_0c0354ce: /* original 4f26, guest PC 0x0c0354ce */
if(!s->budget--) { s->failed_pc=0x0c0354ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0354d0;
P_0c0354d0: /* original e0f3, guest PC 0x0c0354d0 */
if(!s->budget--) { s->failed_pc=0x0c0354d0u; return 0; }
r[0]=0xfffffff3u;
goto P_0c0354d2;
P_0c0354d2: /* original 000b, guest PC 0x0c0354d2 */
if(!s->budget--) { s->failed_pc=0x0c0354d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0354d4: /* original 6ef6, guest PC 0x0c0354d4 */
if(!s->budget--) { s->failed_pc=0x0c0354d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0354d6;
P_0c0354d6: /* original 62e2, guest PC 0x0c0354d6 */
if(!s->budget--) { s->failed_pc=0x0c0354d6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0354d8;
P_0c0354d8: /* original e04c, guest PC 0x0c0354d8 */
if(!s->budget--) { s->failed_pc=0x0c0354d8u; return 0; }
r[0]=0x0000004cu;
goto P_0c0354da;
P_0c0354da: /* original e104, guest PC 0x0c0354da */
if(!s->budget--) { s->failed_pc=0x0c0354dau; return 0; }
r[1]=0x00000004u;
goto P_0c0354dc;
P_0c0354dc: /* original 532b, guest PC 0x0c0354dc */
if(!s->budget--) { s->failed_pc=0x0c0354dcu; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0354de;
P_0c0354de: /* original 134f, guest PC 0x0c0354de */
if(!s->budget--) { s->failed_pc=0x0c0354deu; return 0; }
write(ram,r[3]+60,r[4],4);
goto P_0c0354e0;
P_0c0354e0: /* original 62e2, guest PC 0x0c0354e0 */
if(!s->budget--) { s->failed_pc=0x0c0354e0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0354e2;
P_0c0354e2: /* original 532b, guest PC 0x0c0354e2 */
if(!s->budget--) { s->failed_pc=0x0c0354e2u; return 0; }
r[3]=read(ram,r[2]+44,4);
goto P_0c0354e4;
P_0c0354e4: /* original 0315, guest PC 0x0c0354e4 */
if(!s->budget--) { s->failed_pc=0x0c0354e4u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0354e6;
P_0c0354e6: /* original e044, guest PC 0x0c0354e6 */
if(!s->budget--) { s->failed_pc=0x0c0354e6u; return 0; }
r[0]=0x00000044u;
goto P_0c0354e8;
P_0c0354e8: /* original 63e2, guest PC 0x0c0354e8 */
if(!s->budget--) { s->failed_pc=0x0c0354e8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0354ea;
P_0c0354ea: /* original e106, guest PC 0x0c0354ea */
if(!s->budget--) { s->failed_pc=0x0c0354eau; return 0; }
r[1]=0x00000006u;
goto P_0c0354ec;
P_0c0354ec: /* original 523b, guest PC 0x0c0354ec */
if(!s->budget--) { s->failed_pc=0x0c0354ecu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0354ee;
P_0c0354ee: /* original 0215, guest PC 0x0c0354ee */
if(!s->budget--) { s->failed_pc=0x0c0354eeu; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c0354f0;
P_0c0354f0: /* original 63e2, guest PC 0x0c0354f0 */
if(!s->budget--) { s->failed_pc=0x0c0354f0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0354f2;
P_0c0354f2: /* original 6233, guest PC 0x0c0354f2 */
if(!s->budget--) { s->failed_pc=0x0c0354f2u; return 0; }
r[2]=r[3];
goto P_0c0354f4;
P_0c0354f4: /* original 512b, guest PC 0x0c0354f4 */
if(!s->budget--) { s->failed_pc=0x0c0354f4u; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c0354f6;
P_0c0354f6: /* original 131a, guest PC 0x0c0354f6 */
if(!s->budget--) { s->failed_pc=0x0c0354f6u; return 0; }
write(ram,r[3]+40,r[1],4);
goto P_0c0354f8;
P_0c0354f8: /* original e000, guest PC 0x0c0354f8 */
if(!s->budget--) { s->failed_pc=0x0c0354f8u; return 0; }
r[0]=0x00000000u;
goto P_0c0354fa;
P_0c0354fa: /* original 7f04, guest PC 0x0c0354fa */
if(!s->budget--) { s->failed_pc=0x0c0354fau; return 0; }
r[15]+=0x00000004u;
goto P_0c0354fc;
P_0c0354fc: /* original 4f26, guest PC 0x0c0354fc */
if(!s->budget--) { s->failed_pc=0x0c0354fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0354fe;
P_0c0354fe: /* original 000b, guest PC 0x0c0354fe */
if(!s->budget--) { s->failed_pc=0x0c0354feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035500: /* original 6ef6, guest PC 0x0c035500 */
if(!s->budget--) { s->failed_pc=0x0c035500u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c035502u,s,ram);
P_0c035518: /* original 4f22, guest PC 0x0c035518 */
if(!s->budget--) { s->failed_pc=0x0c035518u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03551a;
P_0c03551a: /* original d333, guest PC 0x0c03551a */
if(!s->budget--) { s->failed_pc=0x0c03551au; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c03551c;
P_0c03551c: /* original 6d32, guest PC 0x0c03551c */
if(!s->budget--) { s->failed_pc=0x0c03551cu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c03551e;
P_0c03551e: /* original 9c61, guest PC 0x0c03551e */
if(!s->budget--) { s->failed_pc=0x0c03551eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0355e4u,2);
goto P_0c035520;
P_0c035520: /* original da32, guest PC 0x0c035520 */
if(!s->budget--) { s->failed_pc=0x0c035520u; return 0; }
r[10]=read(ram,0x0c0355ecu,4);
goto P_0c035522;
P_0c035522: /* original 5be6, guest PC 0x0c035522 */
if(!s->budget--) { s->failed_pc=0x0c035522u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c035524;
P_0c035524: /* original 60e2, guest PC 0x0c035524 */
if(!s->budget--) { s->failed_pc=0x0c035524u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c035526;
P_0c035526: /* original 5009, guest PC 0x0c035526 */
if(!s->budget--) { s->failed_pc=0x0c035526u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c035528;
P_0c035528: /* original 8802, guest PC 0x0c035528 */
if(!s->budget--) { s->failed_pc=0x0c035528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03552a;
P_0c03552a: /* original 8901, guest PC 0x0c03552a */
if(!s->budget--) { s->failed_pc=0x0c03552au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035530; }
goto P_0c03552c;
P_0c03552c: /* original 4a0b, guest PC 0x0c03552c */
if(!s->budget--) { s->failed_pc=0x0c03552cu; return 0; }
target=r[10];
r[16]=code_base|0x0c035530u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035530u) { target=s->pc; goto dispatch; }
goto P_0c035530;
P_0c03552e: /* original 0009, guest PC 0x0c03552e */
if(!s->budget--) { s->failed_pc=0x0c03552eu; return 0; }
goto P_0c035530;
P_0c035530: /* original b276, guest PC 0x0c035530 */
if(!s->budget--) { s->failed_pc=0x0c035530u; return 0; }
target=0x0c035a20u; r[16]=code_base|0x0c035534u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035534u) { target=s->pc; goto dispatch; }
goto P_0c035534;
P_0c035532: /* original 64e3, guest PC 0x0c035532 */
if(!s->budget--) { s->failed_pc=0x0c035532u; return 0; }
r[4]=r[14];
goto P_0c035534;
P_0c035534: /* original 8800, guest PC 0x0c035534 */
if(!s->budget--) { s->failed_pc=0x0c035534u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c035536;
P_0c035536: /* original 8d0e, guest PC 0x0c035536 */
if(!s->budget--) { s->failed_pc=0x0c035536u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c035556; }
goto P_0c03553a;
P_0c035538: /* original 6403, guest PC 0x0c035538 */
if(!s->budget--) { s->failed_pc=0x0c035538u; return 0; }
r[4]=r[0];
goto P_0c03553a;
P_0c03553a: /* original 8801, guest PC 0x0c03553a */
if(!s->budget--) { s->failed_pc=0x0c03553au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03553c;
P_0c03553c: /* original 890d, guest PC 0x0c03553c */
if(!s->budget--) { s->failed_pc=0x0c03553cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555a; }
goto P_0c03553e;
P_0c03553e: /* original 8802, guest PC 0x0c03553e */
if(!s->budget--) { s->failed_pc=0x0c03553eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c035540;
P_0c035540: /* original 890d, guest PC 0x0c035540 */
if(!s->budget--) { s->failed_pc=0x0c035540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035542;
P_0c035542: /* original 8803, guest PC 0x0c035542 */
if(!s->budget--) { s->failed_pc=0x0c035542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c035544;
P_0c035544: /* original 890b, guest PC 0x0c035544 */
if(!s->budget--) { s->failed_pc=0x0c035544u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c035546;
P_0c035546: /* original 8804, guest PC 0x0c035546 */
if(!s->budget--) { s->failed_pc=0x0c035546u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c035548;
P_0c035548: /* original 8909, guest PC 0x0c035548 */
if(!s->budget--) { s->failed_pc=0x0c035548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03555e; }
goto P_0c03554a;
P_0c03554a: /* original 8805, guest PC 0x0c03554a */
if(!s->budget--) { s->failed_pc=0x0c03554au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03554c;
P_0c03554c: /* original 890d, guest PC 0x0c03554c */
if(!s->budget--) { s->failed_pc=0x0c03554cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c03554e;
P_0c03554e: /* original 8806, guest PC 0x0c03554e */
if(!s->budget--) { s->failed_pc=0x0c03554eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c035550;
P_0c035550: /* original 890b, guest PC 0x0c035550 */
if(!s->budget--) { s->failed_pc=0x0c035550u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03556a; }
goto P_0c035552;
P_0c035552: /* original a00d, guest PC 0x0c035552 */
if(!s->budget--) { s->failed_pc=0x0c035552u; return 0; }
goto P_0c035570;
P_0c035554: /* original 0009, guest PC 0x0c035554 */
if(!s->budget--) { s->failed_pc=0x0c035554u; return 0; }
goto P_0c035556;
P_0c035556: /* original a013, guest PC 0x0c035556 */
if(!s->budget--) { s->failed_pc=0x0c035556u; return 0; }
r[0]=0xffffffe0u;
goto P_0c035580;
P_0c035558: /* original e0e0, guest PC 0x0c035558 */
if(!s->budget--) { s->failed_pc=0x0c035558u; return 0; }
r[0]=0xffffffe0u;
goto P_0c03555a;
P_0c03555a: /* original a011, guest PC 0x0c03555a */
if(!s->budget--) { s->failed_pc=0x0c03555au; return 0; }
r[0]=0x00000000u;
goto P_0c035580;
P_0c03555c: /* original e000, guest PC 0x0c03555c */
if(!s->budget--) { s->failed_pc=0x0c03555cu; return 0; }
r[0]=0x00000000u;
goto P_0c03555e;
P_0c03555e: /* original 53e6, guest PC 0x0c03555e */
if(!s->budget--) { s->failed_pc=0x0c03555eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c035560;
P_0c035560: /* original 3b30, guest PC 0x0c035560 */
if(!s->budget--) { s->failed_pc=0x0c035560u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c035562;
P_0c035562: /* original 8907, guest PC 0x0c035562 */
if(!s->budget--) { s->failed_pc=0x0c035562u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035574; }
goto P_0c035564;
P_0c035564: /* original d120, guest PC 0x0c035564 */
if(!s->budget--) { s->failed_pc=0x0c035564u; return 0; }
r[1]=read(ram,0x0c0355e8u,4);
goto P_0c035566;
P_0c035566: /* original a005, guest PC 0x0c035566 */
if(!s->budget--) { s->failed_pc=0x0c035566u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c035574;
P_0c035568: /* original 6d12, guest PC 0x0c035568 */
if(!s->budget--) { s->failed_pc=0x0c035568u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03556a;
P_0c03556a: /* original e04e, guest PC 0x0c03556a */
if(!s->budget--) { s->failed_pc=0x0c03556au; return 0; }
r[0]=0x0000004eu;
goto P_0c03556c;
P_0c03556c: /* original a008, guest PC 0x0c03556c */
if(!s->budget--) { s->failed_pc=0x0c03556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035580;
P_0c03556e: /* original 00ed, guest PC 0x0c03556e */
if(!s->budget--) { s->failed_pc=0x0c03556eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035570;
P_0c035570: /* original a006, guest PC 0x0c035570 */
if(!s->budget--) { s->failed_pc=0x0c035570u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035580;
P_0c035572: /* original e0e7, guest PC 0x0c035572 */
if(!s->budget--) { s->failed_pc=0x0c035572u; return 0; }
r[0]=0xffffffe7u;
goto P_0c035574;
P_0c035574: /* original d31c, guest PC 0x0c035574 */
if(!s->budget--) { s->failed_pc=0x0c035574u; return 0; }
r[3]=read(ram,0x0c0355e8u,4);
goto P_0c035576;
P_0c035576: /* original 6432, guest PC 0x0c035576 */
if(!s->budget--) { s->failed_pc=0x0c035576u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c035578;
P_0c035578: /* original 34d8, guest PC 0x0c035578 */
if(!s->budget--) { s->failed_pc=0x0c035578u; return 0; }
r[4]-=r[13];
goto P_0c03557a;
P_0c03557a: /* original 34c6, guest PC 0x0c03557a */
if(!s->budget--) { s->failed_pc=0x0c03557au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[12])!=0);
goto P_0c03557c;
P_0c03557c: /* original 8bd2, guest PC 0x0c03557c */
if(!s->budget--) { s->failed_pc=0x0c03557cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035524; }
goto P_0c03557e;
P_0c03557e: /* original e0eb, guest PC 0x0c03557e */
if(!s->budget--) { s->failed_pc=0x0c03557eu; return 0; }
r[0]=0xffffffebu;
goto P_0c035580;
P_0c035580: /* original 4f26, guest PC 0x0c035580 */
if(!s->budget--) { s->failed_pc=0x0c035580u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035582;
P_0c035582: /* original 6af6, guest PC 0x0c035582 */
if(!s->budget--) { s->failed_pc=0x0c035582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c035584;
P_0c035584: /* original 6bf6, guest PC 0x0c035584 */
if(!s->budget--) { s->failed_pc=0x0c035584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c035586;
P_0c035586: /* original 6cf6, guest PC 0x0c035586 */
if(!s->budget--) { s->failed_pc=0x0c035586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c035588;
P_0c035588: /* original 6df6, guest PC 0x0c035588 */
if(!s->budget--) { s->failed_pc=0x0c035588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03558a;
P_0c03558a: /* original 000b, guest PC 0x0c03558a */
if(!s->budget--) { s->failed_pc=0x0c03558au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03558c: /* original 6ef6, guest PC 0x0c03558c */
if(!s->budget--) { s->failed_pc=0x0c03558cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03558eu,s,ram);
P_0c03746a: /* original ff0b, guest PC 0x0c03746a */
if(!s->budget--) { s->failed_pc=0x0c03746au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03746c;
P_0c03746c: /* original ff10, guest PC 0x0c03746c */
if(!s->budget--) { s->failed_pc=0x0c03746cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'+');
goto P_0c03746e;
P_0c03746e: /* original 0c0c, guest PC 0x0c03746e */
if(!s->budget--) { s->failed_pc=0x0c03746eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037470;
P_0c037470: /* original cc2c, guest PC 0x0c037470 */
if(!s->budget--) { s->failed_pc=0x0c037470u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&44u)==0)!=0);
goto P_0c037472;
P_0c037472: /* original 0c0c, guest PC 0x0c037472 */
if(!s->budget--) { s->failed_pc=0x0c037472u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037474;
P_0c037474: /* original cc30, guest PC 0x0c037474 */
if(!s->budget--) { s->failed_pc=0x0c037474u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&48u)==0)!=0);
goto P_0c037476;
P_0c037476: /* original 0c0c, guest PC 0x0c037476 */
if(!s->budget--) { s->failed_pc=0x0c037476u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037478;
P_0c037478: /* original cc38, guest PC 0x0c037478 */
if(!s->budget--) { s->failed_pc=0x0c037478u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&56u)==0)!=0);
goto P_0c03747a;
P_0c03747a: /* original 0c0c, guest PC 0x0c03747a */
if(!s->budget--) { s->failed_pc=0x0c03747au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c03747c;
P_0c03747c: /* original cc4c, guest PC 0x0c03747c */
if(!s->budget--) { s->failed_pc=0x0c03747cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&76u)==0)!=0);
goto P_0c03747e;
P_0c03747e: /* original 0c0c, guest PC 0x0c03747e */
if(!s->budget--) { s->failed_pc=0x0c03747eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037480;
P_0c037480: /* original cc5c, guest PC 0x0c037480 */
if(!s->budget--) { s->failed_pc=0x0c037480u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&92u)==0)!=0);
goto P_0c037482;
P_0c037482: /* original 0c0c, guest PC 0x0c037482 */
if(!s->budget--) { s->failed_pc=0x0c037482u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037484;
P_0c037484: /* original cc6c, guest PC 0x0c037484 */
if(!s->budget--) { s->failed_pc=0x0c037484u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&108u)==0)!=0);
goto P_0c037486;
P_0c037486: /* original 0c0c, guest PC 0x0c037486 */
if(!s->budget--) { s->failed_pc=0x0c037486u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037488;
P_0c037488: /* original cc78, guest PC 0x0c037488 */
if(!s->budget--) { s->failed_pc=0x0c037488u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&120u)==0)!=0);
goto P_0c03748a;
P_0c03748a: /* original 0c0c, guest PC 0x0c03748a */
if(!s->budget--) { s->failed_pc=0x0c03748au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c03748c;
P_0c03748c: /* original cc84, guest PC 0x0c03748c */
if(!s->budget--) { s->failed_pc=0x0c03748cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&132u)==0)!=0);
goto P_0c03748e;
P_0c03748e: /* original 0c0c, guest PC 0x0c03748e */
if(!s->budget--) { s->failed_pc=0x0c03748eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037490;
P_0c037490: /* original cc90, guest PC 0x0c037490 */
if(!s->budget--) { s->failed_pc=0x0c037490u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&144u)==0)!=0);
goto P_0c037492;
P_0c037492: /* original 0c0c, guest PC 0x0c037492 */
if(!s->budget--) { s->failed_pc=0x0c037492u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037494;
P_0c037494: /* original cca0, guest PC 0x0c037494 */
if(!s->budget--) { s->failed_pc=0x0c037494u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&160u)==0)!=0);
goto P_0c037496;
P_0c037496: /* original 0c0c, guest PC 0x0c037496 */
if(!s->budget--) { s->failed_pc=0x0c037496u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c037498;
P_0c037498: /* original ccac, guest PC 0x0c037498 */
if(!s->budget--) { s->failed_pc=0x0c037498u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&172u)==0)!=0);
goto P_0c03749a;
P_0c03749a: /* original 0c0c, guest PC 0x0c03749a */
if(!s->budget--) { s->failed_pc=0x0c03749au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c03749c;
P_0c03749c: /* original ccbc, guest PC 0x0c03749c */
if(!s->budget--) { s->failed_pc=0x0c03749cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&188u)==0)!=0);
goto P_0c03749e;
P_0c03749e: /* original 0c0c, guest PC 0x0c03749e */
if(!s->budget--) { s->failed_pc=0x0c03749eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c0374a0;
P_0c0374a0: /* original cccc, guest PC 0x0c0374a0 */
if(!s->budget--) { s->failed_pc=0x0c0374a0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&204u)==0)!=0);
goto P_0c0374a2;
P_0c0374a2: /* original 0c0c, guest PC 0x0c0374a2 */
if(!s->budget--) { s->failed_pc=0x0c0374a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c0374a4;
P_0c0374a4: /* original cce4, guest PC 0x0c0374a4 */
if(!s->budget--) { s->failed_pc=0x0c0374a4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&228u)==0)!=0);
goto P_0c0374a6;
P_0c0374a6: /* original 0c0c, guest PC 0x0c0374a6 */
if(!s->budget--) { s->failed_pc=0x0c0374a6u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c0374a8;
P_0c0374a8: /* original ccf4, guest PC 0x0c0374a8 */
if(!s->budget--) { s->failed_pc=0x0c0374a8u; return 0; }
if(!s->gbr_known) goto unsupported;
r[17]=(r[17]&~1u)|(((read(ram,s->gbr+r[0],1)&244u)==0)!=0);
goto P_0c0374aa;
P_0c0374aa: /* original 0c0c, guest PC 0x0c0374aa */
if(!s->budget--) { s->failed_pc=0x0c0374aau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c0374ac;
P_0c0374ac: /* original cd04, guest PC 0x0c0374ac */
if(!s->budget--) { s->failed_pc=0x0c0374acu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+r[0],read(ram,s->gbr+r[0],1)&4u,1);
goto P_0c0374ae;
P_0c0374ae: /* original 0c0c, guest PC 0x0c0374ae */
if(!s->budget--) { s->failed_pc=0x0c0374aeu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c0374b0;
P_0c0374b0: /* original 6043, guest PC 0x0c0374b0 */
if(!s->budget--) { s->failed_pc=0x0c0374b0u; return 0; }
r[0]=r[4];
goto P_0c0374b2;
P_0c0374b2: /* original 8800, guest PC 0x0c0374b2 */
if(!s->budget--) { s->failed_pc=0x0c0374b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0374b4;
P_0c0374b4: /* original 890d, guest PC 0x0c0374b4 */
if(!s->budget--) { s->failed_pc=0x0c0374b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374d2; }
goto P_0c0374b6;
P_0c0374b6: /* original 8801, guest PC 0x0c0374b6 */
if(!s->budget--) { s->failed_pc=0x0c0374b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0374b8;
P_0c0374b8: /* original 890e, guest PC 0x0c0374b8 */
if(!s->budget--) { s->failed_pc=0x0c0374b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374d8; }
goto P_0c0374ba;
P_0c0374ba: /* original 8802, guest PC 0x0c0374ba */
if(!s->budget--) { s->failed_pc=0x0c0374bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0374bc;
P_0c0374bc: /* original 890f, guest PC 0x0c0374bc */
if(!s->budget--) { s->failed_pc=0x0c0374bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374de; }
goto P_0c0374be;
P_0c0374be: /* original 8803, guest PC 0x0c0374be */
if(!s->budget--) { s->failed_pc=0x0c0374beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0374c0;
P_0c0374c0: /* original 8910, guest PC 0x0c0374c0 */
if(!s->budget--) { s->failed_pc=0x0c0374c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374e4; }
goto P_0c0374c2;
P_0c0374c2: /* original 8807, guest PC 0x0c0374c2 */
if(!s->budget--) { s->failed_pc=0x0c0374c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0374c4;
P_0c0374c4: /* original 8911, guest PC 0x0c0374c4 */
if(!s->budget--) { s->failed_pc=0x0c0374c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374ea; }
goto P_0c0374c6;
P_0c0374c6: /* original 880b, guest PC 0x0c0374c6 */
if(!s->budget--) { s->failed_pc=0x0c0374c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0374c8;
P_0c0374c8: /* original 8912, guest PC 0x0c0374c8 */
if(!s->budget--) { s->failed_pc=0x0c0374c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374f0; }
goto P_0c0374ca;
P_0c0374ca: /* original 880c, guest PC 0x0c0374ca */
if(!s->budget--) { s->failed_pc=0x0c0374cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0374cc;
P_0c0374cc: /* original 8913, guest PC 0x0c0374cc */
if(!s->budget--) { s->failed_pc=0x0c0374ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0374f6; }
goto P_0c0374ce;
P_0c0374ce: /* original a015, guest PC 0x0c0374ce */
if(!s->budget--) { s->failed_pc=0x0c0374ceu; return 0; }
goto P_0c0374fc;
P_0c0374d0: /* original 0009, guest PC 0x0c0374d0 */
if(!s->budget--) { s->failed_pc=0x0c0374d0u; return 0; }
goto P_0c0374d2;
P_0c0374d2: /* original d01e, guest PC 0x0c0374d2 */
if(!s->budget--) { s->failed_pc=0x0c0374d2u; return 0; }
r[0]=read(ram,0x0c03754cu,4);
goto P_0c0374d4;
P_0c0374d4: /* original 000b, guest PC 0x0c0374d4 */
if(!s->budget--) { s->failed_pc=0x0c0374d4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374d6: /* original 0009, guest PC 0x0c0374d6 */
if(!s->budget--) { s->failed_pc=0x0c0374d6u; return 0; }
goto P_0c0374d8;
P_0c0374d8: /* original d01d, guest PC 0x0c0374d8 */
if(!s->budget--) { s->failed_pc=0x0c0374d8u; return 0; }
r[0]=read(ram,0x0c037550u,4);
goto P_0c0374da;
P_0c0374da: /* original 000b, guest PC 0x0c0374da */
if(!s->budget--) { s->failed_pc=0x0c0374dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374dc: /* original 0009, guest PC 0x0c0374dc */
if(!s->budget--) { s->failed_pc=0x0c0374dcu; return 0; }
goto P_0c0374de;
P_0c0374de: /* original d01d, guest PC 0x0c0374de */
if(!s->budget--) { s->failed_pc=0x0c0374deu; return 0; }
r[0]=read(ram,0x0c037554u,4);
goto P_0c0374e0;
P_0c0374e0: /* original 000b, guest PC 0x0c0374e0 */
if(!s->budget--) { s->failed_pc=0x0c0374e0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374e2: /* original 0009, guest PC 0x0c0374e2 */
if(!s->budget--) { s->failed_pc=0x0c0374e2u; return 0; }
goto P_0c0374e4;
P_0c0374e4: /* original d01c, guest PC 0x0c0374e4 */
if(!s->budget--) { s->failed_pc=0x0c0374e4u; return 0; }
r[0]=read(ram,0x0c037558u,4);
goto P_0c0374e6;
P_0c0374e6: /* original 000b, guest PC 0x0c0374e6 */
if(!s->budget--) { s->failed_pc=0x0c0374e6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374e8: /* original 0009, guest PC 0x0c0374e8 */
if(!s->budget--) { s->failed_pc=0x0c0374e8u; return 0; }
goto P_0c0374ea;
P_0c0374ea: /* original d01c, guest PC 0x0c0374ea */
if(!s->budget--) { s->failed_pc=0x0c0374eau; return 0; }
r[0]=read(ram,0x0c03755cu,4);
goto P_0c0374ec;
P_0c0374ec: /* original 000b, guest PC 0x0c0374ec */
if(!s->budget--) { s->failed_pc=0x0c0374ecu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374ee: /* original 0009, guest PC 0x0c0374ee */
if(!s->budget--) { s->failed_pc=0x0c0374eeu; return 0; }
goto P_0c0374f0;
P_0c0374f0: /* original d01b, guest PC 0x0c0374f0 */
if(!s->budget--) { s->failed_pc=0x0c0374f0u; return 0; }
r[0]=read(ram,0x0c037560u,4);
goto P_0c0374f2;
P_0c0374f2: /* original 000b, guest PC 0x0c0374f2 */
if(!s->budget--) { s->failed_pc=0x0c0374f2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374f4: /* original 0009, guest PC 0x0c0374f4 */
if(!s->budget--) { s->failed_pc=0x0c0374f4u; return 0; }
goto P_0c0374f6;
P_0c0374f6: /* original d01b, guest PC 0x0c0374f6 */
if(!s->budget--) { s->failed_pc=0x0c0374f6u; return 0; }
r[0]=read(ram,0x0c037564u,4);
goto P_0c0374f8;
P_0c0374f8: /* original 000b, guest PC 0x0c0374f8 */
if(!s->budget--) { s->failed_pc=0x0c0374f8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0374fa: /* original 0009, guest PC 0x0c0374fa */
if(!s->budget--) { s->failed_pc=0x0c0374fau; return 0; }
goto P_0c0374fc;
P_0c0374fc: /* original d01a, guest PC 0x0c0374fc */
if(!s->budget--) { s->failed_pc=0x0c0374fcu; return 0; }
r[0]=read(ram,0x0c037568u,4);
goto P_0c0374fe;
P_0c0374fe: /* original 000b, guest PC 0x0c0374fe */
if(!s->budget--) { s->failed_pc=0x0c0374feu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037500: /* original 0009, guest PC 0x0c037500 */
if(!s->budget--) { s->failed_pc=0x0c037500u; return 0; }
return vf3_matrix_family(0x0c037502u,s,ram);
P_0c0377a8: /* original 4f22, guest PC 0x0c0377a8 */
if(!s->budget--) { s->failed_pc=0x0c0377a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0377aa;
P_0c0377aa: /* original 7ff8, guest PC 0x0c0377aa */
if(!s->budget--) { s->failed_pc=0x0c0377aau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0377ac;
P_0c0377ac: /* original e400, guest PC 0x0c0377ac */
if(!s->budget--) { s->failed_pc=0x0c0377acu; return 0; }
r[4]=0x00000000u;
goto P_0c0377ae;
P_0c0377ae: /* original d315, guest PC 0x0c0377ae */
if(!s->budget--) { s->failed_pc=0x0c0377aeu; return 0; }
r[3]=read(ram,0x0c037804u,4);
goto P_0c0377b0;
P_0c0377b0: /* original 430b, guest PC 0x0c0377b0 */
if(!s->budget--) { s->failed_pc=0x0c0377b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0377b4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0377b4u) { target=s->pc; goto dispatch; }
goto P_0c0377b4;
P_0c0377b2: /* original 0009, guest PC 0x0c0377b2 */
if(!s->budget--) { s->failed_pc=0x0c0377b2u; return 0; }
goto P_0c0377b4;
P_0c0377b4: /* original d214, guest PC 0x0c0377b4 */
if(!s->budget--) { s->failed_pc=0x0c0377b4u; return 0; }
r[2]=read(ram,0x0c037808u,4);
goto P_0c0377b6;
P_0c0377b6: /* original 420b, guest PC 0x0c0377b6 */
if(!s->budget--) { s->failed_pc=0x0c0377b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0377bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0377bau) { target=s->pc; goto dispatch; }
goto P_0c0377ba;
P_0c0377b8: /* original 0009, guest PC 0x0c0377b8 */
if(!s->budget--) { s->failed_pc=0x0c0377b8u; return 0; }
goto P_0c0377ba;
P_0c0377ba: /* original 1f01, guest PC 0x0c0377ba */
if(!s->budget--) { s->failed_pc=0x0c0377bau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0377bc;
P_0c0377bc: /* original 840c, guest PC 0x0c0377bc */
if(!s->budget--) { s->failed_pc=0x0c0377bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+12,1);
goto P_0c0377be;
P_0c0377be: /* original 8830, guest PC 0x0c0377be */
if(!s->budget--) { s->failed_pc=0x0c0377beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000030u)!=0);
goto P_0c0377c0;
P_0c0377c0: /* original 8913, guest PC 0x0c0377c0 */
if(!s->budget--) { s->failed_pc=0x0c0377c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0377ea; }
goto P_0c0377c2;
P_0c0377c2: /* original 8831, guest PC 0x0c0377c2 */
if(!s->budget--) { s->failed_pc=0x0c0377c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000031u)!=0);
goto P_0c0377c4;
P_0c0377c4: /* original 8905, guest PC 0x0c0377c4 */
if(!s->budget--) { s->failed_pc=0x0c0377c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0377d2; }
goto P_0c0377c6;
P_0c0377c6: /* original 8832, guest PC 0x0c0377c6 */
if(!s->budget--) { s->failed_pc=0x0c0377c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000032u)!=0);
goto P_0c0377c8;
P_0c0377c8: /* original 8907, guest PC 0x0c0377c8 */
if(!s->budget--) { s->failed_pc=0x0c0377c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0377da; }
goto P_0c0377ca;
P_0c0377ca: /* original 8833, guest PC 0x0c0377ca */
if(!s->budget--) { s->failed_pc=0x0c0377cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c0377cc;
P_0c0377cc: /* original 8909, guest PC 0x0c0377cc */
if(!s->budget--) { s->failed_pc=0x0c0377ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0377e2; }
goto P_0c0377ce;
P_0c0377ce: /* original a00c, guest PC 0x0c0377ce */
if(!s->budget--) { s->failed_pc=0x0c0377ceu; return 0; }
goto P_0c0377ea;
P_0c0377d0: /* original 0009, guest PC 0x0c0377d0 */
if(!s->budget--) { s->failed_pc=0x0c0377d0u; return 0; }
goto P_0c0377d2;
P_0c0377d2: /* original e301, guest PC 0x0c0377d2 */
if(!s->budget--) { s->failed_pc=0x0c0377d2u; return 0; }
r[3]=0x00000001u;
goto P_0c0377d4;
P_0c0377d4: /* original 2f32, guest PC 0x0c0377d4 */
if(!s->budget--) { s->failed_pc=0x0c0377d4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0377d6;
P_0c0377d6: /* original a00c, guest PC 0x0c0377d6 */
if(!s->budget--) { s->failed_pc=0x0c0377d6u; return 0; }
goto P_0c0377f2;
P_0c0377d8: /* original 0009, guest PC 0x0c0377d8 */
if(!s->budget--) { s->failed_pc=0x0c0377d8u; return 0; }
goto P_0c0377da;
P_0c0377da: /* original e102, guest PC 0x0c0377da */
if(!s->budget--) { s->failed_pc=0x0c0377dau; return 0; }
r[1]=0x00000002u;
goto P_0c0377dc;
P_0c0377dc: /* original 2f12, guest PC 0x0c0377dc */
if(!s->budget--) { s->failed_pc=0x0c0377dcu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0377de;
P_0c0377de: /* original a008, guest PC 0x0c0377de */
if(!s->budget--) { s->failed_pc=0x0c0377deu; return 0; }
goto P_0c0377f2;
P_0c0377e0: /* original 0009, guest PC 0x0c0377e0 */
if(!s->budget--) { s->failed_pc=0x0c0377e0u; return 0; }
goto P_0c0377e2;
P_0c0377e2: /* original e203, guest PC 0x0c0377e2 */
if(!s->budget--) { s->failed_pc=0x0c0377e2u; return 0; }
r[2]=0x00000003u;
goto P_0c0377e4;
P_0c0377e4: /* original 2f22, guest PC 0x0c0377e4 */
if(!s->budget--) { s->failed_pc=0x0c0377e4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0377e6;
P_0c0377e6: /* original a004, guest PC 0x0c0377e6 */
if(!s->budget--) { s->failed_pc=0x0c0377e6u; return 0; }
goto P_0c0377f2;
P_0c0377e8: /* original 0009, guest PC 0x0c0377e8 */
if(!s->budget--) { s->failed_pc=0x0c0377e8u; return 0; }
goto P_0c0377ea;
P_0c0377ea: /* original e100, guest PC 0x0c0377ea */
if(!s->budget--) { s->failed_pc=0x0c0377eau; return 0; }
r[1]=0x00000000u;
goto P_0c0377ec;
P_0c0377ec: /* original 2f12, guest PC 0x0c0377ec */
if(!s->budget--) { s->failed_pc=0x0c0377ecu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0377ee;
P_0c0377ee: /* original a000, guest PC 0x0c0377ee */
if(!s->budget--) { s->failed_pc=0x0c0377eeu; return 0; }
goto P_0c0377f2;
P_0c0377f0: /* original 0009, guest PC 0x0c0377f0 */
if(!s->budget--) { s->failed_pc=0x0c0377f0u; return 0; }
goto P_0c0377f2;
P_0c0377f2: /* original 60f2, guest PC 0x0c0377f2 */
if(!s->budget--) { s->failed_pc=0x0c0377f2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0377f4;
P_0c0377f4: /* original 7f08, guest PC 0x0c0377f4 */
if(!s->budget--) { s->failed_pc=0x0c0377f4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0377f6;
P_0c0377f6: /* original 4f26, guest PC 0x0c0377f6 */
if(!s->budget--) { s->failed_pc=0x0c0377f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0377f8;
P_0c0377f8: /* original 000b, guest PC 0x0c0377f8 */
if(!s->budget--) { s->failed_pc=0x0c0377f8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0377fa: /* original 0009, guest PC 0x0c0377fa */
if(!s->budget--) { s->failed_pc=0x0c0377fau; return 0; }
return vf3_matrix_family(0x0c0377fcu,s,ram);
P_0c03780c: /* original 4f22, guest PC 0x0c03780c */
if(!s->budget--) { s->failed_pc=0x0c03780cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03780e;
P_0c03780e: /* original 7ff4, guest PC 0x0c03780e */
if(!s->budget--) { s->failed_pc=0x0c03780eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c037810;
P_0c037810: /* original d313, guest PC 0x0c037810 */
if(!s->budget--) { s->failed_pc=0x0c037810u; return 0; }
r[3]=read(ram,0x0c037860u,4);
goto P_0c037812;
P_0c037812: /* original 430b, guest PC 0x0c037812 */
if(!s->budget--) { s->failed_pc=0x0c037812u; return 0; }
target=r[3];
r[16]=code_base|0x0c037816u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037816u) { target=s->pc; goto dispatch; }
goto P_0c037816;
P_0c037814: /* original 0009, guest PC 0x0c037814 */
if(!s->budget--) { s->failed_pc=0x0c037814u; return 0; }
goto P_0c037816;
P_0c037816: /* original 1f01, guest PC 0x0c037816 */
if(!s->budget--) { s->failed_pc=0x0c037816u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c037818;
P_0c037818: /* original bfc6, guest PC 0x0c037818 */
if(!s->budget--) { s->failed_pc=0x0c037818u; return 0; }
target=0x0c0377a8u; r[16]=code_base|0x0c03781cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03781cu) { target=s->pc; goto dispatch; }
goto P_0c03781c;
P_0c03781a: /* original 0009, guest PC 0x0c03781a */
if(!s->budget--) { s->failed_pc=0x0c03781au; return 0; }
goto P_0c03781c;
P_0c03781c: /* original 2f02, guest PC 0x0c03781c */
if(!s->budget--) { s->failed_pc=0x0c03781cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c03781e;
P_0c03781e: /* original 53f1, guest PC 0x0c03781e */
if(!s->budget--) { s->failed_pc=0x0c03781eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c037820;
P_0c037820: /* original 2338, guest PC 0x0c037820 */
if(!s->budget--) { s->failed_pc=0x0c037820u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c037822;
P_0c037822: /* original 8b04, guest PC 0x0c037822 */
if(!s->budget--) { s->failed_pc=0x0c037822u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03782e; }
goto P_0c037824;
P_0c037824: /* original e001, guest PC 0x0c037824 */
if(!s->budget--) { s->failed_pc=0x0c037824u; return 0; }
r[0]=0x00000001u;
goto P_0c037826;
P_0c037826: /* original 7f0c, guest PC 0x0c037826 */
if(!s->budget--) { s->failed_pc=0x0c037826u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037828;
P_0c037828: /* original 4f26, guest PC 0x0c037828 */
if(!s->budget--) { s->failed_pc=0x0c037828u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03782a;
P_0c03782a: /* original 000b, guest PC 0x0c03782a */
if(!s->budget--) { s->failed_pc=0x0c03782au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03782c: /* original 0009, guest PC 0x0c03782c */
if(!s->budget--) { s->failed_pc=0x0c03782cu; return 0; }
goto P_0c03782e;
P_0c03782e: /* original 60f2, guest PC 0x0c03782e */
if(!s->budget--) { s->failed_pc=0x0c03782eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c037830;
P_0c037830: /* original 8800, guest PC 0x0c037830 */
if(!s->budget--) { s->failed_pc=0x0c037830u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c037832;
P_0c037832: /* original 890c, guest PC 0x0c037832 */
if(!s->budget--) { s->failed_pc=0x0c037832u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03784e; }
goto P_0c037834;
P_0c037834: /* original 8801, guest PC 0x0c037834 */
if(!s->budget--) { s->failed_pc=0x0c037834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c037836;
P_0c037836: /* original 8905, guest PC 0x0c037836 */
if(!s->budget--) { s->failed_pc=0x0c037836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037844; }
goto P_0c037838;
P_0c037838: /* original 8802, guest PC 0x0c037838 */
if(!s->budget--) { s->failed_pc=0x0c037838u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03783a;
P_0c03783a: /* original 8908, guest PC 0x0c03783a */
if(!s->budget--) { s->failed_pc=0x0c03783au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03784e; }
goto P_0c03783c;
P_0c03783c: /* original 8803, guest PC 0x0c03783c */
if(!s->budget--) { s->failed_pc=0x0c03783cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c03783e;
P_0c03783e: /* original 8901, guest PC 0x0c03783e */
if(!s->budget--) { s->failed_pc=0x0c03783eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037844; }
goto P_0c037840;
P_0c037840: /* original a005, guest PC 0x0c037840 */
if(!s->budget--) { s->failed_pc=0x0c037840u; return 0; }
goto P_0c03784e;
P_0c037842: /* original 0009, guest PC 0x0c037842 */
if(!s->budget--) { s->failed_pc=0x0c037842u; return 0; }
goto P_0c037844;
P_0c037844: /* original e002, guest PC 0x0c037844 */
if(!s->budget--) { s->failed_pc=0x0c037844u; return 0; }
r[0]=0x00000002u;
goto P_0c037846;
P_0c037846: /* original 7f0c, guest PC 0x0c037846 */
if(!s->budget--) { s->failed_pc=0x0c037846u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037848;
P_0c037848: /* original 4f26, guest PC 0x0c037848 */
if(!s->budget--) { s->failed_pc=0x0c037848u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03784a;
P_0c03784a: /* original 000b, guest PC 0x0c03784a */
if(!s->budget--) { s->failed_pc=0x0c03784au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03784c: /* original 0009, guest PC 0x0c03784c */
if(!s->budget--) { s->failed_pc=0x0c03784cu; return 0; }
goto P_0c03784e;
P_0c03784e: /* original e000, guest PC 0x0c03784e */
if(!s->budget--) { s->failed_pc=0x0c03784eu; return 0; }
r[0]=0x00000000u;
goto P_0c037850;
P_0c037850: /* original 7f0c, guest PC 0x0c037850 */
if(!s->budget--) { s->failed_pc=0x0c037850u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037852;
P_0c037852: /* original 4f26, guest PC 0x0c037852 */
if(!s->budget--) { s->failed_pc=0x0c037852u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037854;
P_0c037854: /* original 000b, guest PC 0x0c037854 */
if(!s->budget--) { s->failed_pc=0x0c037854u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037856: /* original 0009, guest PC 0x0c037856 */
if(!s->budget--) { s->failed_pc=0x0c037856u; return 0; }
return vf3_matrix_family(0x0c037858u,s,ram);
P_0c03bbd2: /* original 4f22, guest PC 0x0c03bbd2 */
if(!s->budget--) { s->failed_pc=0x0c03bbd2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03bbd4;
P_0c03bbd4: /* original 7f94, guest PC 0x0c03bbd4 */
if(!s->budget--) { s->failed_pc=0x0c03bbd4u; return 0; }
r[15]+=0xffffff94u;
goto P_0c03bbd6;
P_0c03bbd6: /* original 2f42, guest PC 0x0c03bbd6 */
if(!s->budget--) { s->failed_pc=0x0c03bbd6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03bbd8;
P_0c03bbd8: /* original 64f3, guest PC 0x0c03bbd8 */
if(!s->budget--) { s->failed_pc=0x0c03bbd8u; return 0; }
r[4]=r[15];
goto P_0c03bbda;
P_0c03bbda: /* original 1f61, guest PC 0x0c03bbda */
if(!s->budget--) { s->failed_pc=0x0c03bbdau; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c03bbdc;
P_0c03bbdc: /* original d370, guest PC 0x0c03bbdc */
if(!s->budget--) { s->failed_pc=0x0c03bbdcu; return 0; }
r[3]=read(ram,0x0c03bda0u,4);
goto P_0c03bbde;
P_0c03bbde: /* original 66f2, guest PC 0x0c03bbde */
if(!s->budget--) { s->failed_pc=0x0c03bbdeu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03bbe0;
P_0c03bbe0: /* original 430b, guest PC 0x0c03bbe0 */
if(!s->budget--) { s->failed_pc=0x0c03bbe0u; return 0; }
target=r[3];
r[16]=code_base|0x0c03bbe4u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bbe4u) { target=s->pc; goto dispatch; }
goto P_0c03bbe4;
P_0c03bbe2: /* original 7408, guest PC 0x0c03bbe2 */
if(!s->budget--) { s->failed_pc=0x0c03bbe2u; return 0; }
r[4]+=0x00000008u;
goto P_0c03bbe4;
P_0c03bbe4: /* original 65f3, guest PC 0x0c03bbe4 */
if(!s->budget--) { s->failed_pc=0x0c03bbe4u; return 0; }
r[5]=r[15];
goto P_0c03bbe6;
P_0c03bbe6: /* original d36f, guest PC 0x0c03bbe6 */
if(!s->budget--) { s->failed_pc=0x0c03bbe6u; return 0; }
r[3]=read(ram,0x0c03bda4u,4);
goto P_0c03bbe8;
P_0c03bbe8: /* original 66f3, guest PC 0x0c03bbe8 */
if(!s->budget--) { s->failed_pc=0x0c03bbe8u; return 0; }
r[6]=r[15];
goto P_0c03bbea;
P_0c03bbea: /* original 7508, guest PC 0x0c03bbea */
if(!s->budget--) { s->failed_pc=0x0c03bbeau; return 0; }
r[5]+=0x00000008u;
goto P_0c03bbec;
P_0c03bbec: /* original 7620, guest PC 0x0c03bbec */
if(!s->budget--) { s->failed_pc=0x0c03bbecu; return 0; }
r[6]+=0x00000020u;
goto P_0c03bbee;
P_0c03bbee: /* original 430b, guest PC 0x0c03bbee */
if(!s->budget--) { s->failed_pc=0x0c03bbeeu; return 0; }
target=r[3];
r[16]=code_base|0x0c03bbf2u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bbf2u) { target=s->pc; goto dispatch; }
goto P_0c03bbf2;
P_0c03bbf0: /* original 54f1, guest PC 0x0c03bbf0 */
if(!s->budget--) { s->failed_pc=0x0c03bbf0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03bbf2;
P_0c03bbf2: /* original 65f3, guest PC 0x0c03bbf2 */
if(!s->budget--) { s->failed_pc=0x0c03bbf2u; return 0; }
r[5]=r[15];
goto P_0c03bbf4;
P_0c03bbf4: /* original d26b, guest PC 0x0c03bbf4 */
if(!s->budget--) { s->failed_pc=0x0c03bbf4u; return 0; }
r[2]=read(ram,0x0c03bda4u,4);
goto P_0c03bbf6;
P_0c03bbf6: /* original 66f3, guest PC 0x0c03bbf6 */
if(!s->budget--) { s->failed_pc=0x0c03bbf6u; return 0; }
r[6]=r[15];
goto P_0c03bbf8;
P_0c03bbf8: /* original 64f3, guest PC 0x0c03bbf8 */
if(!s->budget--) { s->failed_pc=0x0c03bbf8u; return 0; }
r[4]=r[15];
goto P_0c03bbfa;
P_0c03bbfa: /* original 7614, guest PC 0x0c03bbfa */
if(!s->budget--) { s->failed_pc=0x0c03bbfau; return 0; }
r[6]+=0x00000014u;
goto P_0c03bbfc;
P_0c03bbfc: /* original 7520, guest PC 0x0c03bbfc */
if(!s->budget--) { s->failed_pc=0x0c03bbfcu; return 0; }
r[5]+=0x00000020u;
goto P_0c03bbfe;
P_0c03bbfe: /* original 420b, guest PC 0x0c03bbfe */
if(!s->budget--) { s->failed_pc=0x0c03bbfeu; return 0; }
target=r[2];
r[16]=code_base|0x0c03bc02u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc02u) { target=s->pc; goto dispatch; }
goto P_0c03bc02;
P_0c03bc00: /* original 7408, guest PC 0x0c03bc00 */
if(!s->budget--) { s->failed_pc=0x0c03bc00u; return 0; }
r[4]+=0x00000008u;
goto P_0c03bc02;
P_0c03bc02: /* original de69, guest PC 0x0c03bc02 */
if(!s->budget--) { s->failed_pc=0x0c03bc02u; return 0; }
r[14]=read(ram,0x0c03bda8u,4);
goto P_0c03bc04;
P_0c03bc04: /* original 64f3, guest PC 0x0c03bc04 */
if(!s->budget--) { s->failed_pc=0x0c03bc04u; return 0; }
r[4]=r[15];
goto P_0c03bc06;
P_0c03bc06: /* original 4e0b, guest PC 0x0c03bc06 */
if(!s->budget--) { s->failed_pc=0x0c03bc06u; return 0; }
target=r[14];
r[16]=code_base|0x0c03bc0au;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc0au) { target=s->pc; goto dispatch; }
goto P_0c03bc0a;
P_0c03bc08: /* original 7420, guest PC 0x0c03bc08 */
if(!s->budget--) { s->failed_pc=0x0c03bc08u; return 0; }
r[4]+=0x00000020u;
goto P_0c03bc0a;
P_0c03bc0a: /* original 64f3, guest PC 0x0c03bc0a */
if(!s->budget--) { s->failed_pc=0x0c03bc0au; return 0; }
r[4]=r[15];
goto P_0c03bc0c;
P_0c03bc0c: /* original 4e0b, guest PC 0x0c03bc0c */
if(!s->budget--) { s->failed_pc=0x0c03bc0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c03bc10u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc10u) { target=s->pc; goto dispatch; }
goto P_0c03bc10;
P_0c03bc0e: /* original 7414, guest PC 0x0c03bc0e */
if(!s->budget--) { s->failed_pc=0x0c03bc0eu; return 0; }
r[4]+=0x00000014u;
goto P_0c03bc10;
P_0c03bc10: /* original 64f3, guest PC 0x0c03bc10 */
if(!s->budget--) { s->failed_pc=0x0c03bc10u; return 0; }
r[4]=r[15];
goto P_0c03bc12;
P_0c03bc12: /* original 4e0b, guest PC 0x0c03bc12 */
if(!s->budget--) { s->failed_pc=0x0c03bc12u; return 0; }
target=r[14];
r[16]=code_base|0x0c03bc16u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc16u) { target=s->pc; goto dispatch; }
goto P_0c03bc16;
P_0c03bc14: /* original 7408, guest PC 0x0c03bc14 */
if(!s->budget--) { s->failed_pc=0x0c03bc14u; return 0; }
r[4]+=0x00000008u;
goto P_0c03bc16;
P_0c03bc16: /* original e020, guest PC 0x0c03bc16 */
if(!s->budget--) { s->failed_pc=0x0c03bc16u; return 0; }
r[0]=0x00000020u;
goto P_0c03bc18;
P_0c03bc18: /* original f3f6, guest PC 0x0c03bc18 */
if(!s->budget--) { s->failed_pc=0x0c03bc18u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc1a;
P_0c03bc1a: /* original e02c, guest PC 0x0c03bc1a */
if(!s->budget--) { s->failed_pc=0x0c03bc1au; return 0; }
r[0]=0x0000002cu;
goto P_0c03bc1c;
P_0c03bc1c: /* original ff37, guest PC 0x0c03bc1c */
if(!s->budget--) { s->failed_pc=0x0c03bc1cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc1e;
P_0c03bc1e: /* original e024, guest PC 0x0c03bc1e */
if(!s->budget--) { s->failed_pc=0x0c03bc1eu; return 0; }
r[0]=0x00000024u;
goto P_0c03bc20;
P_0c03bc20: /* original f3f6, guest PC 0x0c03bc20 */
if(!s->budget--) { s->failed_pc=0x0c03bc20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc22;
P_0c03bc22: /* original e03c, guest PC 0x0c03bc22 */
if(!s->budget--) { s->failed_pc=0x0c03bc22u; return 0; }
r[0]=0x0000003cu;
goto P_0c03bc24;
P_0c03bc24: /* original ff37, guest PC 0x0c03bc24 */
if(!s->budget--) { s->failed_pc=0x0c03bc24u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc26;
P_0c03bc26: /* original e028, guest PC 0x0c03bc26 */
if(!s->budget--) { s->failed_pc=0x0c03bc26u; return 0; }
r[0]=0x00000028u;
goto P_0c03bc28;
P_0c03bc28: /* original f3f6, guest PC 0x0c03bc28 */
if(!s->budget--) { s->failed_pc=0x0c03bc28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc2a;
P_0c03bc2a: /* original e04c, guest PC 0x0c03bc2a */
if(!s->budget--) { s->failed_pc=0x0c03bc2au; return 0; }
r[0]=0x0000004cu;
goto P_0c03bc2c;
P_0c03bc2c: /* original ff37, guest PC 0x0c03bc2c */
if(!s->budget--) { s->failed_pc=0x0c03bc2cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc2e;
P_0c03bc2e: /* original e05c, guest PC 0x0c03bc2e */
if(!s->budget--) { s->failed_pc=0x0c03bc2eu; return 0; }
r[0]=0x0000005cu;
goto P_0c03bc30;
P_0c03bc30: /* original f48d, guest PC 0x0c03bc30 */
if(!s->budget--) { s->failed_pc=0x0c03bc30u; return 0; }
fr[4]=0;
goto P_0c03bc32;
P_0c03bc32: /* original ff47, guest PC 0x0c03bc32 */
if(!s->budget--) { s->failed_pc=0x0c03bc32u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc34;
P_0c03bc34: /* original e014, guest PC 0x0c03bc34 */
if(!s->budget--) { s->failed_pc=0x0c03bc34u; return 0; }
r[0]=0x00000014u;
goto P_0c03bc36;
P_0c03bc36: /* original f3f6, guest PC 0x0c03bc36 */
if(!s->budget--) { s->failed_pc=0x0c03bc36u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc38;
P_0c03bc38: /* original e030, guest PC 0x0c03bc38 */
if(!s->budget--) { s->failed_pc=0x0c03bc38u; return 0; }
r[0]=0x00000030u;
goto P_0c03bc3a;
P_0c03bc3a: /* original ff37, guest PC 0x0c03bc3a */
if(!s->budget--) { s->failed_pc=0x0c03bc3au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc3c;
P_0c03bc3c: /* original e018, guest PC 0x0c03bc3c */
if(!s->budget--) { s->failed_pc=0x0c03bc3cu; return 0; }
r[0]=0x00000018u;
goto P_0c03bc3e;
P_0c03bc3e: /* original f3f6, guest PC 0x0c03bc3e */
if(!s->budget--) { s->failed_pc=0x0c03bc3eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc40;
P_0c03bc40: /* original e040, guest PC 0x0c03bc40 */
if(!s->budget--) { s->failed_pc=0x0c03bc40u; return 0; }
r[0]=0x00000040u;
goto P_0c03bc42;
P_0c03bc42: /* original ff37, guest PC 0x0c03bc42 */
if(!s->budget--) { s->failed_pc=0x0c03bc42u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc44;
P_0c03bc44: /* original e01c, guest PC 0x0c03bc44 */
if(!s->budget--) { s->failed_pc=0x0c03bc44u; return 0; }
r[0]=0x0000001cu;
goto P_0c03bc46;
P_0c03bc46: /* original f3f6, guest PC 0x0c03bc46 */
if(!s->budget--) { s->failed_pc=0x0c03bc46u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc48;
P_0c03bc48: /* original e050, guest PC 0x0c03bc48 */
if(!s->budget--) { s->failed_pc=0x0c03bc48u; return 0; }
r[0]=0x00000050u;
goto P_0c03bc4a;
P_0c03bc4a: /* original ff37, guest PC 0x0c03bc4a */
if(!s->budget--) { s->failed_pc=0x0c03bc4au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc4c;
P_0c03bc4c: /* original e060, guest PC 0x0c03bc4c */
if(!s->budget--) { s->failed_pc=0x0c03bc4cu; return 0; }
r[0]=0x00000060u;
goto P_0c03bc4e;
P_0c03bc4e: /* original ff47, guest PC 0x0c03bc4e */
if(!s->budget--) { s->failed_pc=0x0c03bc4eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc50;
P_0c03bc50: /* original e008, guest PC 0x0c03bc50 */
if(!s->budget--) { s->failed_pc=0x0c03bc50u; return 0; }
r[0]=0x00000008u;
goto P_0c03bc52;
P_0c03bc52: /* original f3f6, guest PC 0x0c03bc52 */
if(!s->budget--) { s->failed_pc=0x0c03bc52u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc54;
P_0c03bc54: /* original e034, guest PC 0x0c03bc54 */
if(!s->budget--) { s->failed_pc=0x0c03bc54u; return 0; }
r[0]=0x00000034u;
goto P_0c03bc56;
P_0c03bc56: /* original ff37, guest PC 0x0c03bc56 */
if(!s->budget--) { s->failed_pc=0x0c03bc56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc58;
P_0c03bc58: /* original e00c, guest PC 0x0c03bc58 */
if(!s->budget--) { s->failed_pc=0x0c03bc58u; return 0; }
r[0]=0x0000000cu;
goto P_0c03bc5a;
P_0c03bc5a: /* original f3f6, guest PC 0x0c03bc5a */
if(!s->budget--) { s->failed_pc=0x0c03bc5au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc5c;
P_0c03bc5c: /* original e044, guest PC 0x0c03bc5c */
if(!s->budget--) { s->failed_pc=0x0c03bc5cu; return 0; }
r[0]=0x00000044u;
goto P_0c03bc5e;
P_0c03bc5e: /* original 64f3, guest PC 0x0c03bc5e */
if(!s->budget--) { s->failed_pc=0x0c03bc5eu; return 0; }
r[4]=r[15];
goto P_0c03bc60;
P_0c03bc60: /* original ff37, guest PC 0x0c03bc60 */
if(!s->budget--) { s->failed_pc=0x0c03bc60u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc62;
P_0c03bc62: /* original e010, guest PC 0x0c03bc62 */
if(!s->budget--) { s->failed_pc=0x0c03bc62u; return 0; }
r[0]=0x00000010u;
goto P_0c03bc64;
P_0c03bc64: /* original f3f6, guest PC 0x0c03bc64 */
if(!s->budget--) { s->failed_pc=0x0c03bc64u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c03bc66;
P_0c03bc66: /* original e054, guest PC 0x0c03bc66 */
if(!s->budget--) { s->failed_pc=0x0c03bc66u; return 0; }
r[0]=0x00000054u;
goto P_0c03bc68;
P_0c03bc68: /* original ff37, guest PC 0x0c03bc68 */
if(!s->budget--) { s->failed_pc=0x0c03bc68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc6a;
P_0c03bc6a: /* original e064, guest PC 0x0c03bc6a */
if(!s->budget--) { s->failed_pc=0x0c03bc6au; return 0; }
r[0]=0x00000064u;
goto P_0c03bc6c;
P_0c03bc6c: /* original ff47, guest PC 0x0c03bc6c */
if(!s->budget--) { s->failed_pc=0x0c03bc6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc6e;
P_0c03bc6e: /* original e038, guest PC 0x0c03bc6e */
if(!s->budget--) { s->failed_pc=0x0c03bc6eu; return 0; }
r[0]=0x00000038u;
goto P_0c03bc70;
P_0c03bc70: /* original ff47, guest PC 0x0c03bc70 */
if(!s->budget--) { s->failed_pc=0x0c03bc70u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc72;
P_0c03bc72: /* original e048, guest PC 0x0c03bc72 */
if(!s->budget--) { s->failed_pc=0x0c03bc72u; return 0; }
r[0]=0x00000048u;
goto P_0c03bc74;
P_0c03bc74: /* original ff47, guest PC 0x0c03bc74 */
if(!s->budget--) { s->failed_pc=0x0c03bc74u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc76;
P_0c03bc76: /* original e058, guest PC 0x0c03bc76 */
if(!s->budget--) { s->failed_pc=0x0c03bc76u; return 0; }
r[0]=0x00000058u;
goto P_0c03bc78;
P_0c03bc78: /* original ff47, guest PC 0x0c03bc78 */
if(!s->budget--) { s->failed_pc=0x0c03bc78u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03bc7a;
P_0c03bc7a: /* original e068, guest PC 0x0c03bc7a */
if(!s->budget--) { s->failed_pc=0x0c03bc7au; return 0; }
r[0]=0x00000068u;
goto P_0c03bc7c;
P_0c03bc7c: /* original f39d, guest PC 0x0c03bc7c */
if(!s->budget--) { s->failed_pc=0x0c03bc7cu; return 0; }
fr[3]=0x3f800000u;
goto P_0c03bc7e;
P_0c03bc7e: /* original ff37, guest PC 0x0c03bc7e */
if(!s->budget--) { s->failed_pc=0x0c03bc7eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03bc80;
P_0c03bc80: /* original d34a, guest PC 0x0c03bc80 */
if(!s->budget--) { s->failed_pc=0x0c03bc80u; return 0; }
r[3]=read(ram,0x0c03bdacu,4);
goto P_0c03bc82;
P_0c03bc82: /* original 430b, guest PC 0x0c03bc82 */
if(!s->budget--) { s->failed_pc=0x0c03bc82u; return 0; }
target=r[3];
r[16]=code_base|0x0c03bc86u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc86u) { target=s->pc; goto dispatch; }
goto P_0c03bc86;
P_0c03bc84: /* original 742c, guest PC 0x0c03bc84 */
if(!s->budget--) { s->failed_pc=0x0c03bc84u; return 0; }
r[4]+=0x0000002cu;
goto P_0c03bc86;
P_0c03bc86: /* original d345, guest PC 0x0c03bc86 */
if(!s->budget--) { s->failed_pc=0x0c03bc86u; return 0; }
r[3]=read(ram,0x0c03bd9cu,4);
goto P_0c03bc88;
P_0c03bc88: /* original 430b, guest PC 0x0c03bc88 */
if(!s->budget--) { s->failed_pc=0x0c03bc88u; return 0; }
target=r[3];
r[16]=code_base|0x0c03bc8cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03bc8cu) { target=s->pc; goto dispatch; }
goto P_0c03bc8c;
P_0c03bc8a: /* original 64f2, guest PC 0x0c03bc8a */
if(!s->budget--) { s->failed_pc=0x0c03bc8au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03bc8c;
P_0c03bc8c: /* original 7f6c, guest PC 0x0c03bc8c */
if(!s->budget--) { s->failed_pc=0x0c03bc8cu; return 0; }
r[15]+=0x0000006cu;
goto P_0c03bc8e;
P_0c03bc8e: /* original 4f26, guest PC 0x0c03bc8e */
if(!s->budget--) { s->failed_pc=0x0c03bc8eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03bc90;
P_0c03bc90: /* original 000b, guest PC 0x0c03bc90 */
if(!s->budget--) { s->failed_pc=0x0c03bc90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03bc92: /* original 6ef6, guest PC 0x0c03bc92 */
if(!s->budget--) { s->failed_pc=0x0c03bc92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03bc94u,s,ram);
P_0c042672: /* original 4f22, guest PC 0x0c042672 */
if(!s->budget--) { s->failed_pc=0x0c042672u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042674;
P_0c042674: /* original 7fa4, guest PC 0x0c042674 */
if(!s->budget--) { s->failed_pc=0x0c042674u; return 0; }
r[15]+=0xffffffa4u;
goto P_0c042676;
P_0c042676: /* original 6df3, guest PC 0x0c042676 */
if(!s->budget--) { s->failed_pc=0x0c042676u; return 0; }
r[13]=r[15];
goto P_0c042678;
P_0c042678: /* original 7d58, guest PC 0x0c042678 */
if(!s->budget--) { s->failed_pc=0x0c042678u; return 0; }
r[13]+=0x00000058u;
goto P_0c04267a;
P_0c04267a: /* original 6043, guest PC 0x0c04267a */
if(!s->budget--) { s->failed_pc=0x0c04267au; return 0; }
r[0]=r[4];
goto P_0c04267c;
P_0c04267c: /* original 0009, guest PC 0x0c04267c */
if(!s->budget--) { s->failed_pc=0x0c04267cu; return 0; }
goto P_0c04267e;
P_0c04267e: /* original 80d1, guest PC 0x0c04267e */
if(!s->budget--) { s->failed_pc=0x0c04267eu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c042680;
P_0c042680: /* original 9347, guest PC 0x0c042680 */
if(!s->budget--) { s->failed_pc=0x0c042680u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c042682;
P_0c042682: /* original 3e33, guest PC 0x0c042682 */
if(!s->budget--) { s->failed_pc=0x0c042682u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c042684;
P_0c042684: /* original 8d02, guest PC 0x0c042684 */
if(!s->budget--) { s->failed_pc=0x0c042684u; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[0],1);
if(cond) { goto P_0c04268c; }
goto P_0c042688;
P_0c042686: /* original 2d00, guest PC 0x0c042686 */
if(!s->budget--) { s->failed_pc=0x0c042686u; return 0; }
write(ram,r[13],r[0],1);
goto P_0c042688;
P_0c042688: /* original e10c, guest PC 0x0c042688 */
if(!s->budget--) { s->failed_pc=0x0c042688u; return 0; }
r[1]=0x0000000cu;
goto P_0c04268a;
P_0c04268a: /* original 2d10, guest PC 0x0c04268a */
if(!s->budget--) { s->failed_pc=0x0c04268au; return 0; }
write(ram,r[13],r[1],1);
goto P_0c04268c;
P_0c04268c: /* original d222, guest PC 0x0c04268c */
if(!s->budget--) { s->failed_pc=0x0c04268cu; return 0; }
r[2]=read(ram,0x0c042718u,4);
goto P_0c04268e;
P_0c04268e: /* original 6320, guest PC 0x0c04268e */
if(!s->budget--) { s->failed_pc=0x0c04268eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c042690;
P_0c042690: /* original 1f32, guest PC 0x0c042690 */
if(!s->budget--) { s->failed_pc=0x0c042690u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c042692;
P_0c042692: /* original d323, guest PC 0x0c042692 */
if(!s->budget--) { s->failed_pc=0x0c042692u; return 0; }
r[3]=read(ram,0x0c042720u,4);
goto P_0c042694;
P_0c042694: /* original d121, guest PC 0x0c042694 */
if(!s->budget--) { s->failed_pc=0x0c042694u; return 0; }
r[1]=read(ram,0x0c04271cu,4);
goto P_0c042696;
P_0c042696: /* original 6030, guest PC 0x0c042696 */
if(!s->budget--) { s->failed_pc=0x0c042696u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c042698;
P_0c042698: /* original 8801, guest PC 0x0c042698 */
if(!s->budget--) { s->failed_pc=0x0c042698u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04269a;
P_0c04269a: /* original 8f01, guest PC 0x0c04269a */
if(!s->budget--) { s->failed_pc=0x0c04269au; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
if(!cond) { goto P_0c0426a0; }
goto P_0c04269e;
P_0c04269c: /* original 6810, guest PC 0x0c04269c */
if(!s->budget--) { s->failed_pc=0x0c04269cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[8]=tmp;
goto P_0c04269e;
P_0c04269e: /* original e8ff, guest PC 0x0c04269e */
if(!s->budget--) { s->failed_pc=0x0c04269eu; return 0; }
r[8]=0xffffffffu;
goto P_0c0426a0;
P_0c0426a0: /* original b21e, guest PC 0x0c0426a0 */
if(!s->budget--) { s->failed_pc=0x0c0426a0u; return 0; }
target=0x0c042ae0u; r[16]=code_base|0x0c0426a4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0426a4u) { target=s->pc; goto dispatch; }
goto P_0c0426a4;
P_0c0426a2: /* original 64e3, guest PC 0x0c0426a2 */
if(!s->budget--) { s->failed_pc=0x0c0426a2u; return 0; }
r[4]=r[14];
goto P_0c0426a4;
P_0c0426a4: /* original d21f, guest PC 0x0c0426a4 */
if(!s->budget--) { s->failed_pc=0x0c0426a4u; return 0; }
r[2]=read(ram,0x0c042724u,4);
goto P_0c0426a6;
P_0c0426a6: /* original d320, guest PC 0x0c0426a6 */
if(!s->budget--) { s->failed_pc=0x0c0426a6u; return 0; }
r[3]=read(ram,0x0c042728u,4);
goto P_0c0426a8;
P_0c0426a8: /* original 6c22, guest PC 0x0c0426a8 */
if(!s->budget--) { s->failed_pc=0x0c0426a8u; return 0; }
tmp=read(ram,r[2],4);
r[12]=tmp;
goto P_0c0426aa;
P_0c0426aa: /* original 430b, guest PC 0x0c0426aa */
if(!s->budget--) { s->failed_pc=0x0c0426aau; return 0; }
target=r[3];
r[16]=code_base|0x0c0426aeu;
r[12]+=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0426aeu) { target=s->pc; goto dispatch; }
goto P_0c0426ae;
P_0c0426ac: /* original 3c0c, guest PC 0x0c0426ac */
if(!s->budget--) { s->failed_pc=0x0c0426acu; return 0; }
r[12]+=r[0];
goto P_0c0426ae;
P_0c0426ae: /* original 2008, guest PC 0x0c0426ae */
if(!s->budget--) { s->failed_pc=0x0c0426aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0426b0;
P_0c0426b0: /* original 8b5a, guest PC 0x0c0426b0 */
if(!s->budget--) { s->failed_pc=0x0c0426b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042768; }
goto P_0c0426b2;
P_0c0426b2: /* original 932e, guest PC 0x0c0426b2 */
if(!s->budget--) { s->failed_pc=0x0c0426b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042712u,2);
goto P_0c0426b4;
P_0c0426b4: /* original 3e33, guest PC 0x0c0426b4 */
if(!s->budget--) { s->failed_pc=0x0c0426b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0426b6;
P_0c0426b6: /* original 8903, guest PC 0x0c0426b6 */
if(!s->budget--) { s->failed_pc=0x0c0426b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0426c0; }
goto P_0c0426b8;
P_0c0426b8: /* original a003, guest PC 0x0c0426b8 */
if(!s->budget--) { s->failed_pc=0x0c0426b8u; return 0; }
r[4]=0x00000024u;
goto P_0c0426c2;
P_0c0426ba: /* original e424, guest PC 0x0c0426ba */
if(!s->budget--) { s->failed_pc=0x0c0426bau; return 0; }
r[4]=0x00000024u;
return vf3_matrix_family(0x0c0426bcu,s,ram);
P_0c0426c0: /* original e448, guest PC 0x0c0426c0 */
if(!s->budget--) { s->failed_pc=0x0c0426c0u; return 0; }
r[4]=0x00000048u;
goto P_0c0426c2;
P_0c0426c2: /* original 65f3, guest PC 0x0c0426c2 */
if(!s->budget--) { s->failed_pc=0x0c0426c2u; return 0; }
r[5]=r[15];
goto P_0c0426c4;
P_0c0426c4: /* original a007, guest PC 0x0c0426c4 */
if(!s->budget--) { s->failed_pc=0x0c0426c4u; return 0; }
r[5]+=0x00000010u;
goto P_0c0426d6;
P_0c0426c6: /* original 7510, guest PC 0x0c0426c6 */
if(!s->budget--) { s->failed_pc=0x0c0426c6u; return 0; }
r[5]+=0x00000010u;
return vf3_matrix_family(0x0c0426c8u,s,ram);
P_0c0426d0: /* original 63c4, guest PC 0x0c0426d0 */
if(!s->budget--) { s->failed_pc=0x0c0426d0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c0426d2;
P_0c0426d2: /* original 2530, guest PC 0x0c0426d2 */
if(!s->budget--) { s->failed_pc=0x0c0426d2u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c0426d4;
P_0c0426d4: /* original 7501, guest PC 0x0c0426d4 */
if(!s->budget--) { s->failed_pc=0x0c0426d4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0426d6;
P_0c0426d6: /* original 4415, guest PC 0x0c0426d6 */
if(!s->budget--) { s->failed_pc=0x0c0426d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0426d8;
P_0c0426d8: /* original 8dfa, guest PC 0x0c0426d8 */
if(!s->budget--) { s->failed_pc=0x0c0426d8u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c0426d0; }
goto P_0c0426dc;
P_0c0426da: /* original 74ff, guest PC 0x0c0426da */
if(!s->budget--) { s->failed_pc=0x0c0426dau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0426dc;
P_0c0426dc: /* original d213, guest PC 0x0c0426dc */
if(!s->budget--) { s->failed_pc=0x0c0426dcu; return 0; }
r[2]=read(ram,0x0c04272cu,4);
goto P_0c0426de;
P_0c0426de: /* original 420b, guest PC 0x0c0426de */
if(!s->budget--) { s->failed_pc=0x0c0426deu; return 0; }
target=r[2];
r[16]=code_base|0x0c0426e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0426e2u) { target=s->pc; goto dispatch; }
goto P_0c0426e2;
P_0c0426e0: /* original 0009, guest PC 0x0c0426e0 */
if(!s->budget--) { s->failed_pc=0x0c0426e0u; return 0; }
goto P_0c0426e2;
P_0c0426e2: /* original 63f3, guest PC 0x0c0426e2 */
if(!s->budget--) { s->failed_pc=0x0c0426e2u; return 0; }
r[3]=r[15];
goto P_0c0426e4;
P_0c0426e4: /* original 7310, guest PC 0x0c0426e4 */
if(!s->budget--) { s->failed_pc=0x0c0426e4u; return 0; }
r[3]+=0x00000010u;
goto P_0c0426e6;
P_0c0426e6: /* original 1f33, guest PC 0x0c0426e6 */
if(!s->budget--) { s->failed_pc=0x0c0426e6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0426e8;
P_0c0426e8: /* original e900, guest PC 0x0c0426e8 */
if(!s->budget--) { s->failed_pc=0x0c0426e8u; return 0; }
r[9]=0x00000000u;
goto P_0c0426ea;
P_0c0426ea: /* original d111, guest PC 0x0c0426ea */
if(!s->budget--) { s->failed_pc=0x0c0426eau; return 0; }
r[1]=read(ram,0x0c042730u,4);
goto P_0c0426ec;
P_0c0426ec: /* original 6c93, guest PC 0x0c0426ec */
if(!s->budget--) { s->failed_pc=0x0c0426ecu; return 0; }
r[12]=r[9];
goto P_0c0426ee;
P_0c0426ee: /* original 6e93, guest PC 0x0c0426ee */
if(!s->budget--) { s->failed_pc=0x0c0426eeu; return 0; }
r[14]=r[9];
goto P_0c0426f0;
P_0c0426f0: /* original 6212, guest PC 0x0c0426f0 */
if(!s->budget--) { s->failed_pc=0x0c0426f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0426f2;
P_0c0426f2: /* original 2f22, guest PC 0x0c0426f2 */
if(!s->budget--) { s->failed_pc=0x0c0426f2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0426f4;
P_0c0426f4: /* original d20f, guest PC 0x0c0426f4 */
if(!s->budget--) { s->failed_pc=0x0c0426f4u; return 0; }
r[2]=read(ram,0x0c042734u,4);
goto P_0c0426f6;
P_0c0426f6: /* original 6322, guest PC 0x0c0426f6 */
if(!s->budget--) { s->failed_pc=0x0c0426f6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0426f8;
P_0c0426f8: /* original 1f31, guest PC 0x0c0426f8 */
if(!s->budget--) { s->failed_pc=0x0c0426f8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0426fa;
P_0c0426fa: /* original 5bf3, guest PC 0x0c0426fa */
if(!s->budget--) { s->failed_pc=0x0c0426fau; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c0426fc;
P_0c0426fc: /* original ea08, guest PC 0x0c0426fc */
if(!s->budget--) { s->failed_pc=0x0c0426fcu; return 0; }
r[10]=0x00000008u;
goto P_0c0426fe;
P_0c0426fe: /* original 7b01, guest PC 0x0c0426fe */
if(!s->budget--) { s->failed_pc=0x0c0426feu; return 0; }
r[11]+=0x00000001u;
goto P_0c042700;
P_0c042700: /* original 1fb3, guest PC 0x0c042700 */
if(!s->budget--) { s->failed_pc=0x0c042700u; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c042702;
P_0c042702: /* original 7bff, guest PC 0x0c042702 */
if(!s->budget--) { s->failed_pc=0x0c042702u; return 0; }
r[11]+=0xffffffffu;
goto P_0c042704;
P_0c042704: /* original 6bb0, guest PC 0x0c042704 */
if(!s->budget--) { s->failed_pc=0x0c042704u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c042706;
P_0c042706: /* original 9605, guest PC 0x0c042706 */
if(!s->budget--) { s->failed_pc=0x0c042706u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042714u,2);
goto P_0c042708;
P_0c042708: /* original 60bc, guest PC 0x0c042708 */
if(!s->budget--) { s->failed_pc=0x0c042708u; return 0; }
r[0]=r[11]&255u;
goto P_0c04270a;
P_0c04270a: /* original 2608, guest PC 0x0c04270a */
if(!s->budget--) { s->failed_pc=0x0c04270au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[0])==0)!=0);
goto P_0c04270c;
P_0c04270c: /* original 8918, guest PC 0x0c04270c */
if(!s->budget--) { s->failed_pc=0x0c04270cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042740; }
goto P_0c04270e;
P_0c04270e: /* original a018, guest PC 0x0c04270e */
if(!s->budget--) { s->failed_pc=0x0c04270eu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c042742;
P_0c042710: /* original 56f2, guest PC 0x0c042710 */
if(!s->budget--) { s->failed_pc=0x0c042710u; return 0; }
r[6]=read(ram,r[15]+8,4);
return vf3_matrix_family(0x0c042712u,s,ram);
P_0c042740: /* original 6683, guest PC 0x0c042740 */
if(!s->budget--) { s->failed_pc=0x0c042740u; return 0; }
r[6]=r[8];
goto P_0c042742;
P_0c042742: /* original 55f1, guest PC 0x0c042742 */
if(!s->budget--) { s->failed_pc=0x0c042742u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042744;
P_0c042744: /* original 64f2, guest PC 0x0c042744 */
if(!s->budget--) { s->failed_pc=0x0c042744u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c042746;
P_0c042746: /* original 35cc, guest PC 0x0c042746 */
if(!s->budget--) { s->failed_pc=0x0c042746u; return 0; }
r[5]+=r[12];
goto P_0c042748;
P_0c042748: /* original b132, guest PC 0x0c042748 */
if(!s->budget--) { s->failed_pc=0x0c042748u; return 0; }
target=0x0c0429b0u; r[16]=code_base|0x0c04274cu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04274cu) { target=s->pc; goto dispatch; }
goto P_0c04274c;
P_0c04274a: /* original 34ec, guest PC 0x0c04274a */
if(!s->budget--) { s->failed_pc=0x0c04274au; return 0; }
r[4]+=r[14];
goto P_0c04274c;
P_0c04274c: /* original 62d0, guest PC 0x0c04274c */
if(!s->budget--) { s->failed_pc=0x0c04274cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c04274e;
P_0c04274e: /* original 7e01, guest PC 0x0c04274e */
if(!s->budget--) { s->failed_pc=0x0c04274eu; return 0; }
r[14]+=0x00000001u;
goto P_0c042750;
P_0c042750: /* original 4b00, guest PC 0x0c042750 */
if(!s->budget--) { s->failed_pc=0x0c042750u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042752;
P_0c042752: /* original 622c, guest PC 0x0c042752 */
if(!s->budget--) { s->failed_pc=0x0c042752u; return 0; }
r[2]=r[2]&255u;
goto P_0c042754;
P_0c042754: /* original 3e23, guest PC 0x0c042754 */
if(!s->budget--) { s->failed_pc=0x0c042754u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c042756;
P_0c042756: /* original 8b01, guest PC 0x0c042756 */
if(!s->budget--) { s->failed_pc=0x0c042756u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04275c; }
goto P_0c042758;
P_0c042758: /* original 7c01, guest PC 0x0c042758 */
if(!s->budget--) { s->failed_pc=0x0c042758u; return 0; }
r[12]+=0x00000001u;
goto P_0c04275a;
P_0c04275a: /* original 6e93, guest PC 0x0c04275a */
if(!s->budget--) { s->failed_pc=0x0c04275au; return 0; }
r[14]=r[9];
goto P_0c04275c;
P_0c04275c: /* original 4a10, guest PC 0x0c04275c */
if(!s->budget--) { s->failed_pc=0x0c04275cu; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c04275e;
P_0c04275e: /* original 8bd2, guest PC 0x0c04275e */
if(!s->budget--) { s->failed_pc=0x0c04275eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042706; }
goto P_0c042760;
P_0c042760: /* original 84d1, guest PC 0x0c042760 */
if(!s->budget--) { s->failed_pc=0x0c042760u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c042762;
P_0c042762: /* original 600c, guest PC 0x0c042762 */
if(!s->budget--) { s->failed_pc=0x0c042762u; return 0; }
r[0]=r[0]&255u;
goto P_0c042764;
P_0c042764: /* original 3c03, guest PC 0x0c042764 */
if(!s->budget--) { s->failed_pc=0x0c042764u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c042766;
P_0c042766: /* original 8bc8, guest PC 0x0c042766 */
if(!s->budget--) { s->failed_pc=0x0c042766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0426fa; }
goto P_0c042768;
P_0c042768: /* original 7f5c, guest PC 0x0c042768 */
if(!s->budget--) { s->failed_pc=0x0c042768u; return 0; }
r[15]+=0x0000005cu;
goto P_0c04276a;
P_0c04276a: /* original d230, guest PC 0x0c04276a */
if(!s->budget--) { s->failed_pc=0x0c04276au; return 0; }
r[2]=read(ram,0x0c04282cu,4);
goto P_0c04276c;
P_0c04276c: /* original 4f26, guest PC 0x0c04276c */
if(!s->budget--) { s->failed_pc=0x0c04276cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04276e;
P_0c04276e: /* original 63d0, guest PC 0x0c04276e */
if(!s->budget--) { s->failed_pc=0x0c04276eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c042770;
P_0c042770: /* original 6122, guest PC 0x0c042770 */
if(!s->budget--) { s->failed_pc=0x0c042770u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c042772;
P_0c042772: /* original 633c, guest PC 0x0c042772 */
if(!s->budget--) { s->failed_pc=0x0c042772u; return 0; }
r[3]=r[3]&255u;
goto P_0c042774;
P_0c042774: /* original 313c, guest PC 0x0c042774 */
if(!s->budget--) { s->failed_pc=0x0c042774u; return 0; }
r[1]+=r[3];
goto P_0c042776;
P_0c042776: /* original 2212, guest PC 0x0c042776 */
if(!s->budget--) { s->failed_pc=0x0c042776u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042778;
P_0c042778: /* original 68f6, guest PC 0x0c042778 */
if(!s->budget--) { s->failed_pc=0x0c042778u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04277a;
P_0c04277a: /* original 69f6, guest PC 0x0c04277a */
if(!s->budget--) { s->failed_pc=0x0c04277au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04277c;
P_0c04277c: /* original 6af6, guest PC 0x0c04277c */
if(!s->budget--) { s->failed_pc=0x0c04277cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04277e;
P_0c04277e: /* original 6bf6, guest PC 0x0c04277e */
if(!s->budget--) { s->failed_pc=0x0c04277eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042780;
P_0c042780: /* original 6cf6, guest PC 0x0c042780 */
if(!s->budget--) { s->failed_pc=0x0c042780u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042782;
P_0c042782: /* original 6df6, guest PC 0x0c042782 */
if(!s->budget--) { s->failed_pc=0x0c042782u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042784;
P_0c042784: /* original 000b, guest PC 0x0c042784 */
if(!s->budget--) { s->failed_pc=0x0c042784u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042786: /* original 6ef6, guest PC 0x0c042786 */
if(!s->budget--) { s->failed_pc=0x0c042786u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c042788u,s,ram);
P_0c04326c: /* original 4f22, guest PC 0x0c04326c */
if(!s->budget--) { s->failed_pc=0x0c04326cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04326e;
P_0c04326e: /* original 7ff8, guest PC 0x0c04326e */
if(!s->budget--) { s->failed_pc=0x0c04326eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043270;
P_0c043270: /* original 6ef3, guest PC 0x0c043270 */
if(!s->budget--) { s->failed_pc=0x0c043270u; return 0; }
r[14]=r[15];
goto P_0c043272;
P_0c043272: /* original 2e42, guest PC 0x0c043272 */
if(!s->budget--) { s->failed_pc=0x0c043272u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043274;
P_0c043274: /* original 1e51, guest PC 0x0c043274 */
if(!s->budget--) { s->failed_pc=0x0c043274u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043276;
P_0c043276: /* original 65e3, guest PC 0x0c043276 */
if(!s->budget--) { s->failed_pc=0x0c043276u; return 0; }
r[5]=r[14];
goto P_0c043278;
P_0c043278: /* original d32e, guest PC 0x0c043278 */
if(!s->budget--) { s->failed_pc=0x0c043278u; return 0; }
r[3]=read(ram,0x0c043334u,4);
goto P_0c04327a;
P_0c04327a: /* original 430b, guest PC 0x0c04327a */
if(!s->budget--) { s->failed_pc=0x0c04327au; return 0; }
target=r[3];
r[16]=code_base|0x0c04327eu;
r[4]=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04327eu) { target=s->pc; goto dispatch; }
goto P_0c04327e;
P_0c04327c: /* original e41c, guest PC 0x0c04327c */
if(!s->budget--) { s->failed_pc=0x0c04327cu; return 0; }
r[4]=0x0000001cu;
goto P_0c04327e;
P_0c04327e: /* original 7f08, guest PC 0x0c04327e */
if(!s->budget--) { s->failed_pc=0x0c04327eu; return 0; }
r[15]+=0x00000008u;
goto P_0c043280;
P_0c043280: /* original 4f26, guest PC 0x0c043280 */
if(!s->budget--) { s->failed_pc=0x0c043280u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043282;
P_0c043282: /* original 000b, guest PC 0x0c043282 */
if(!s->budget--) { s->failed_pc=0x0c043282u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043284: /* original 6ef6, guest PC 0x0c043284 */
if(!s->budget--) { s->failed_pc=0x0c043284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043286u,s,ram);
P_0c0432e2: /* original 4f22, guest PC 0x0c0432e2 */
if(!s->budget--) { s->failed_pc=0x0c0432e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0432e4;
P_0c0432e4: /* original d316, guest PC 0x0c0432e4 */
if(!s->budget--) { s->failed_pc=0x0c0432e4u; return 0; }
r[3]=read(ram,0x0c043340u,4);
goto P_0c0432e6;
P_0c0432e6: /* original 7ff0, guest PC 0x0c0432e6 */
if(!s->budget--) { s->failed_pc=0x0c0432e6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0432e8;
P_0c0432e8: /* original 430b, guest PC 0x0c0432e8 */
if(!s->budget--) { s->failed_pc=0x0c0432e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0432ecu;
r[5]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0432ecu) { target=s->pc; goto dispatch; }
goto P_0c0432ec;
P_0c0432ea: /* original 65f3, guest PC 0x0c0432ea */
if(!s->budget--) { s->failed_pc=0x0c0432eau; return 0; }
r[5]=r[15];
goto P_0c0432ec;
P_0c0432ec: /* original 6403, guest PC 0x0c0432ec */
if(!s->budget--) { s->failed_pc=0x0c0432ecu; return 0; }
r[4]=r[0];
goto P_0c0432ee;
P_0c0432ee: /* original 6043, guest PC 0x0c0432ee */
if(!s->budget--) { s->failed_pc=0x0c0432eeu; return 0; }
r[0]=r[4];
goto P_0c0432f0;
P_0c0432f0: /* original 55f2, guest PC 0x0c0432f0 */
if(!s->budget--) { s->failed_pc=0x0c0432f0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0432f2;
P_0c0432f2: /* original 88ff, guest PC 0x0c0432f2 */
if(!s->budget--) { s->failed_pc=0x0c0432f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0432f4;
P_0c0432f4: /* original 8d26, guest PC 0x0c0432f4 */
if(!s->budget--) { s->failed_pc=0x0c0432f4u; return 0; }
cond=r[17]&1u;
r[6]=0x00000004u;
if(cond) { goto P_0c043344; }
goto P_0c0432f8;
P_0c0432f6: /* original e604, guest PC 0x0c0432f6 */
if(!s->budget--) { s->failed_pc=0x0c0432f6u; return 0; }
r[6]=0x00000004u;
goto P_0c0432f8;
P_0c0432f8: /* original 8800, guest PC 0x0c0432f8 */
if(!s->budget--) { s->failed_pc=0x0c0432f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0432fa;
P_0c0432fa: /* original 8909, guest PC 0x0c0432fa */
if(!s->budget--) { s->failed_pc=0x0c0432fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043310; }
goto P_0c0432fc;
P_0c0432fc: /* original 8801, guest PC 0x0c0432fc */
if(!s->budget--) { s->failed_pc=0x0c0432fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0432fe;
P_0c0432fe: /* original 8909, guest PC 0x0c0432fe */
if(!s->budget--) { s->failed_pc=0x0c0432feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043314; }
goto P_0c043300;
P_0c043300: /* original 8802, guest PC 0x0c043300 */
if(!s->budget--) { s->failed_pc=0x0c043300u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c043302;
P_0c043302: /* original 8909, guest PC 0x0c043302 */
if(!s->budget--) { s->failed_pc=0x0c043302u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043318; }
goto P_0c043304;
P_0c043304: /* original 8803, guest PC 0x0c043304 */
if(!s->budget--) { s->failed_pc=0x0c043304u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c043306;
P_0c043306: /* original 890a, guest PC 0x0c043306 */
if(!s->budget--) { s->failed_pc=0x0c043306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04331e; }
goto P_0c043308;
P_0c043308: /* original 8804, guest PC 0x0c043308 */
if(!s->budget--) { s->failed_pc=0x0c043308u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c04330a;
P_0c04330a: /* original 890a, guest PC 0x0c04330a */
if(!s->budget--) { s->failed_pc=0x0c04330au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043322; }
goto P_0c04330c;
P_0c04330c: /* original a051, guest PC 0x0c04330c */
if(!s->budget--) { s->failed_pc=0x0c04330cu; return 0; }
goto P_0c0433b2;
P_0c04330e: /* original 0009, guest PC 0x0c04330e */
if(!s->budget--) { s->failed_pc=0x0c04330eu; return 0; }
goto P_0c043310;
P_0c043310: /* original a04f, guest PC 0x0c043310 */
if(!s->budget--) { s->failed_pc=0x0c043310u; return 0; }
r[4]=0x00000000u;
goto P_0c0433b2;
P_0c043312: /* original e400, guest PC 0x0c043312 */
if(!s->budget--) { s->failed_pc=0x0c043312u; return 0; }
r[4]=0x00000000u;
goto P_0c043314;
P_0c043314: /* original a001, guest PC 0x0c043314 */
if(!s->budget--) { s->failed_pc=0x0c043314u; return 0; }
r[4]=r[6];
goto P_0c04331a;
P_0c043316: /* original 6463, guest PC 0x0c043316 */
if(!s->budget--) { s->failed_pc=0x0c043316u; return 0; }
r[4]=r[6];
goto P_0c043318;
P_0c043318: /* original e401, guest PC 0x0c043318 */
if(!s->budget--) { s->failed_pc=0x0c043318u; return 0; }
r[4]=0x00000001u;
goto P_0c04331a;
P_0c04331a: /* original a04a, guest PC 0x0c04331a */
if(!s->budget--) { s->failed_pc=0x0c04331au; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0433b2;
P_0c04331c: /* original 2e52, guest PC 0x0c04331c */
if(!s->budget--) { s->failed_pc=0x0c04331cu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c04331e;
P_0c04331e: /* original a048, guest PC 0x0c04331e */
if(!s->budget--) { s->failed_pc=0x0c04331eu; return 0; }
r[4]=0x00000007u;
goto P_0c0433b2;
P_0c043320: /* original e407, guest PC 0x0c043320 */
if(!s->budget--) { s->failed_pc=0x0c043320u; return 0; }
r[4]=0x00000007u;
goto P_0c043322;
P_0c043322: /* original a046, guest PC 0x0c043322 */
if(!s->budget--) { s->failed_pc=0x0c043322u; return 0; }
r[4]=r[6];
goto P_0c0433b2;
P_0c043324: /* original 6463, guest PC 0x0c043324 */
if(!s->budget--) { s->failed_pc=0x0c043324u; return 0; }
r[4]=r[6];
return vf3_matrix_family(0x0c043326u,s,ram);
P_0c043344: /* original 52f1, guest PC 0x0c043344 */
if(!s->budget--) { s->failed_pc=0x0c043344u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c043346;
P_0c043346: /* original e405, guest PC 0x0c043346 */
if(!s->budget--) { s->failed_pc=0x0c043346u; return 0; }
r[4]=0x00000005u;
goto P_0c043348;
P_0c043348: /* original 1e21, guest PC 0x0c043348 */
if(!s->budget--) { s->failed_pc=0x0c043348u; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c04334a;
P_0c04334a: /* original 60f2, guest PC 0x0c04334a */
if(!s->budget--) { s->failed_pc=0x0c04334au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04334c;
P_0c04334c: /* original e111, guest PC 0x0c04334c */
if(!s->budget--) { s->failed_pc=0x0c04334cu; return 0; }
r[1]=0x00000011u;
goto P_0c04334e;
P_0c04334e: /* original 3012, guest PC 0x0c04334e */
if(!s->budget--) { s->failed_pc=0x0c04334eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c043350;
P_0c043350: /* original 892d, guest PC 0x0c043350 */
if(!s->budget--) { s->failed_pc=0x0c043350u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0433ae; }
goto P_0c043352;
P_0c043352: /* original 4000, guest PC 0x0c043352 */
if(!s->budget--) { s->failed_pc=0x0c043352u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043354;
P_0c043354: /* original 6103, guest PC 0x0c043354 */
if(!s->budget--) { s->failed_pc=0x0c043354u; return 0; }
r[1]=r[0];
goto P_0c043356;
P_0c043356: /* original c702, guest PC 0x0c043356 */
if(!s->budget--) { s->failed_pc=0x0c043356u; return 0; }
r[0]=0x0c043360u;
goto P_0c043358;
P_0c043358: /* original 001d, guest PC 0x0c043358 */
if(!s->budget--) { s->failed_pc=0x0c043358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c04335a;
P_0c04335a: /* original 0023, guest PC 0x0c04335a */
if(!s->budget--) { s->failed_pc=0x0c04335au; return 0; }
target=r[0]+0x0c04335eu;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c04335c: /* original 0009, guest PC 0x0c04335c */
if(!s->budget--) { s->failed_pc=0x0c04335cu; return 0; }
return vf3_matrix_family(0x0c04335eu,s,ram);
P_0c0433ae: /* original e2e6, guest PC 0x0c0433ae */
if(!s->budget--) { s->failed_pc=0x0c0433aeu; return 0; }
r[2]=0xffffffe6u;
goto P_0c0433b0;
P_0c0433b0: /* original 2e22, guest PC 0x0c0433b0 */
if(!s->budget--) { s->failed_pc=0x0c0433b0u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0433b2;
P_0c0433b2: /* original 7f10, guest PC 0x0c0433b2 */
if(!s->budget--) { s->failed_pc=0x0c0433b2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0433b4;
P_0c0433b4: /* original 6043, guest PC 0x0c0433b4 */
if(!s->budget--) { s->failed_pc=0x0c0433b4u; return 0; }
r[0]=r[4];
goto P_0c0433b6;
P_0c0433b6: /* original 4f26, guest PC 0x0c0433b6 */
if(!s->budget--) { s->failed_pc=0x0c0433b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433b8;
P_0c0433b8: /* original 000b, guest PC 0x0c0433b8 */
if(!s->budget--) { s->failed_pc=0x0c0433b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433ba: /* original 6ef6, guest PC 0x0c0433ba */
if(!s->budget--) { s->failed_pc=0x0c0433bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0433bcu,s,ram);
P_0c0433c6: /* original 4f22, guest PC 0x0c0433c6 */
if(!s->budget--) { s->failed_pc=0x0c0433c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0433c8;
P_0c0433c8: /* original 7ff8, guest PC 0x0c0433c8 */
if(!s->budget--) { s->failed_pc=0x0c0433c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0433ca;
P_0c0433ca: /* original 6ef3, guest PC 0x0c0433ca */
if(!s->budget--) { s->failed_pc=0x0c0433cau; return 0; }
r[14]=r[15];
goto P_0c0433cc;
P_0c0433cc: /* original 65e3, guest PC 0x0c0433cc */
if(!s->budget--) { s->failed_pc=0x0c0433ccu; return 0; }
r[5]=r[14];
goto P_0c0433ce;
P_0c0433ce: /* original 2e42, guest PC 0x0c0433ce */
if(!s->budget--) { s->failed_pc=0x0c0433ceu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0433d0;
P_0c0433d0: /* original 1e31, guest PC 0x0c0433d0 */
if(!s->budget--) { s->failed_pc=0x0c0433d0u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0433d2;
P_0c0433d2: /* original d245, guest PC 0x0c0433d2 */
if(!s->budget--) { s->failed_pc=0x0c0433d2u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c0433d4;
P_0c0433d4: /* original 420b, guest PC 0x0c0433d4 */
if(!s->budget--) { s->failed_pc=0x0c0433d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0433d8u;
r[4]=0x0000001bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0433d8u) { target=s->pc; goto dispatch; }
goto P_0c0433d8;
P_0c0433d6: /* original e41b, guest PC 0x0c0433d6 */
if(!s->budget--) { s->failed_pc=0x0c0433d6u; return 0; }
r[4]=0x0000001bu;
goto P_0c0433d8;
P_0c0433d8: /* original 7f08, guest PC 0x0c0433d8 */
if(!s->budget--) { s->failed_pc=0x0c0433d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0433da;
P_0c0433da: /* original 4f26, guest PC 0x0c0433da */
if(!s->budget--) { s->failed_pc=0x0c0433dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433dc;
P_0c0433dc: /* original 000b, guest PC 0x0c0433dc */
if(!s->budget--) { s->failed_pc=0x0c0433dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433de: /* original 6ef6, guest PC 0x0c0433de */
if(!s->budget--) { s->failed_pc=0x0c0433deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0433e0;
P_0c0433e0: /* original 4f22, guest PC 0x0c0433e0 */
if(!s->budget--) { s->failed_pc=0x0c0433e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0433e2;
P_0c0433e2: /* original d341, guest PC 0x0c0433e2 */
if(!s->budget--) { s->failed_pc=0x0c0433e2u; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c0433e4;
P_0c0433e4: /* original e500, guest PC 0x0c0433e4 */
if(!s->budget--) { s->failed_pc=0x0c0433e4u; return 0; }
r[5]=0x00000000u;
goto P_0c0433e6;
P_0c0433e6: /* original 430b, guest PC 0x0c0433e6 */
if(!s->budget--) { s->failed_pc=0x0c0433e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0433eau;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0433eau) { target=s->pc; goto dispatch; }
goto P_0c0433ea;
P_0c0433e8: /* original e418, guest PC 0x0c0433e8 */
if(!s->budget--) { s->failed_pc=0x0c0433e8u; return 0; }
r[4]=0x00000018u;
goto P_0c0433ea;
P_0c0433ea: /* original 4f26, guest PC 0x0c0433ea */
if(!s->budget--) { s->failed_pc=0x0c0433eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433ec;
P_0c0433ec: /* original 000b, guest PC 0x0c0433ec */
if(!s->budget--) { s->failed_pc=0x0c0433ecu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0433ee: /* original 0009, guest PC 0x0c0433ee */
if(!s->budget--) { s->failed_pc=0x0c0433eeu; return 0; }
return vf3_matrix_family(0x0c0433f0u,s,ram);
P_0c04340c: /* original 4f22, guest PC 0x0c04340c */
if(!s->budget--) { s->failed_pc=0x0c04340cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04340e;
P_0c04340e: /* original d338, guest PC 0x0c04340e */
if(!s->budget--) { s->failed_pc=0x0c04340eu; return 0; }
r[3]=read(ram,0x0c0434f0u,4);
goto P_0c043410;
P_0c043410: /* original 430b, guest PC 0x0c043410 */
if(!s->budget--) { s->failed_pc=0x0c043410u; return 0; }
target=r[3];
r[16]=code_base|0x0c043414u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043414u) { target=s->pc; goto dispatch; }
goto P_0c043414;
P_0c043412: /* original 0009, guest PC 0x0c043412 */
if(!s->budget--) { s->failed_pc=0x0c043412u; return 0; }
goto P_0c043414;
P_0c043414: /* original 4f26, guest PC 0x0c043414 */
if(!s->budget--) { s->failed_pc=0x0c043414u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043416;
P_0c043416: /* original 000b, guest PC 0x0c043416 */
if(!s->budget--) { s->failed_pc=0x0c043416u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043418: /* original 0009, guest PC 0x0c043418 */
if(!s->budget--) { s->failed_pc=0x0c043418u; return 0; }
return vf3_matrix_family(0x0c04341au,s,ram);
P_0c04341e: /* original 4f22, guest PC 0x0c04341e */
if(!s->budget--) { s->failed_pc=0x0c04341eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043420;
P_0c043420: /* original 7ff0, guest PC 0x0c043420 */
if(!s->budget--) { s->failed_pc=0x0c043420u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043422;
P_0c043422: /* original 6ef3, guest PC 0x0c043422 */
if(!s->budget--) { s->failed_pc=0x0c043422u; return 0; }
r[14]=r[15];
goto P_0c043424;
P_0c043424: /* original 2e42, guest PC 0x0c043424 */
if(!s->budget--) { s->failed_pc=0x0c043424u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043426;
P_0c043426: /* original 1e51, guest PC 0x0c043426 */
if(!s->budget--) { s->failed_pc=0x0c043426u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043428;
P_0c043428: /* original 65e3, guest PC 0x0c043428 */
if(!s->budget--) { s->failed_pc=0x0c043428u; return 0; }
r[5]=r[14];
goto P_0c04342a;
P_0c04342a: /* original 1e62, guest PC 0x0c04342a */
if(!s->budget--) { s->failed_pc=0x0c04342au; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04342c;
P_0c04342c: /* original 1e33, guest PC 0x0c04342c */
if(!s->budget--) { s->failed_pc=0x0c04342cu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c04342e;
P_0c04342e: /* original d22e, guest PC 0x0c04342e */
if(!s->budget--) { s->failed_pc=0x0c04342eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043430;
P_0c043430: /* original 420b, guest PC 0x0c043430 */
if(!s->budget--) { s->failed_pc=0x0c043430u; return 0; }
target=r[2];
r[16]=code_base|0x0c043434u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043434u) { target=s->pc; goto dispatch; }
goto P_0c043434;
P_0c043432: /* original e414, guest PC 0x0c043432 */
if(!s->budget--) { s->failed_pc=0x0c043432u; return 0; }
r[4]=0x00000014u;
goto P_0c043434;
P_0c043434: /* original 7f10, guest PC 0x0c043434 */
if(!s->budget--) { s->failed_pc=0x0c043434u; return 0; }
r[15]+=0x00000010u;
goto P_0c043436;
P_0c043436: /* original 4f26, guest PC 0x0c043436 */
if(!s->budget--) { s->failed_pc=0x0c043436u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043438;
P_0c043438: /* original 000b, guest PC 0x0c043438 */
if(!s->budget--) { s->failed_pc=0x0c043438u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04343a: /* original 6ef6, guest PC 0x0c04343a */
if(!s->budget--) { s->failed_pc=0x0c04343au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04343cu,s,ram);
P_0c043440: /* original 4f22, guest PC 0x0c043440 */
if(!s->budget--) { s->failed_pc=0x0c043440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043442;
P_0c043442: /* original 7ff0, guest PC 0x0c043442 */
if(!s->budget--) { s->failed_pc=0x0c043442u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043444;
P_0c043444: /* original 6ef3, guest PC 0x0c043444 */
if(!s->budget--) { s->failed_pc=0x0c043444u; return 0; }
r[14]=r[15];
goto P_0c043446;
P_0c043446: /* original 2e42, guest PC 0x0c043446 */
if(!s->budget--) { s->failed_pc=0x0c043446u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043448;
P_0c043448: /* original 1e51, guest PC 0x0c043448 */
if(!s->budget--) { s->failed_pc=0x0c043448u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c04344a;
P_0c04344a: /* original 65e3, guest PC 0x0c04344a */
if(!s->budget--) { s->failed_pc=0x0c04344au; return 0; }
r[5]=r[14];
goto P_0c04344c;
P_0c04344c: /* original 1e62, guest PC 0x0c04344c */
if(!s->budget--) { s->failed_pc=0x0c04344cu; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04344e;
P_0c04344e: /* original 1e33, guest PC 0x0c04344e */
if(!s->budget--) { s->failed_pc=0x0c04344eu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c043450;
P_0c043450: /* original d225, guest PC 0x0c043450 */
if(!s->budget--) { s->failed_pc=0x0c043450u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043452;
P_0c043452: /* original 420b, guest PC 0x0c043452 */
if(!s->budget--) { s->failed_pc=0x0c043452u; return 0; }
target=r[2];
r[16]=code_base|0x0c043456u;
r[4]=0x00000015u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043456u) { target=s->pc; goto dispatch; }
goto P_0c043456;
P_0c043454: /* original e415, guest PC 0x0c043454 */
if(!s->budget--) { s->failed_pc=0x0c043454u; return 0; }
r[4]=0x00000015u;
goto P_0c043456;
P_0c043456: /* original 7f10, guest PC 0x0c043456 */
if(!s->budget--) { s->failed_pc=0x0c043456u; return 0; }
r[15]+=0x00000010u;
goto P_0c043458;
P_0c043458: /* original 4f26, guest PC 0x0c043458 */
if(!s->budget--) { s->failed_pc=0x0c043458u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04345a;
P_0c04345a: /* original 000b, guest PC 0x0c04345a */
if(!s->budget--) { s->failed_pc=0x0c04345au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04345c: /* original 6ef6, guest PC 0x0c04345c */
if(!s->budget--) { s->failed_pc=0x0c04345cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04345e;
P_0c04345e: /* original 4f22, guest PC 0x0c04345e */
if(!s->budget--) { s->failed_pc=0x0c04345eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043460;
P_0c043460: /* original d321, guest PC 0x0c043460 */
if(!s->budget--) { s->failed_pc=0x0c043460u; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c043462;
P_0c043462: /* original e500, guest PC 0x0c043462 */
if(!s->budget--) { s->failed_pc=0x0c043462u; return 0; }
r[5]=0x00000000u;
goto P_0c043464;
P_0c043464: /* original 430b, guest PC 0x0c043464 */
if(!s->budget--) { s->failed_pc=0x0c043464u; return 0; }
target=r[3];
r[16]=code_base|0x0c043468u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043468u) { target=s->pc; goto dispatch; }
goto P_0c043468;
P_0c043466: /* original e416, guest PC 0x0c043466 */
if(!s->budget--) { s->failed_pc=0x0c043466u; return 0; }
r[4]=0x00000016u;
goto P_0c043468;
P_0c043468: /* original 4f26, guest PC 0x0c043468 */
if(!s->budget--) { s->failed_pc=0x0c043468u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04346a;
P_0c04346a: /* original 000b, guest PC 0x0c04346a */
if(!s->budget--) { s->failed_pc=0x0c04346au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04346c: /* original 0009, guest PC 0x0c04346c */
if(!s->budget--) { s->failed_pc=0x0c04346cu; return 0; }
return vf3_matrix_family(0x0c04346eu,s,ram);
P_0c043472: /* original 4f22, guest PC 0x0c043472 */
if(!s->budget--) { s->failed_pc=0x0c043472u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043474;
P_0c043474: /* original 7ff8, guest PC 0x0c043474 */
if(!s->budget--) { s->failed_pc=0x0c043474u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043476;
P_0c043476: /* original 6ef3, guest PC 0x0c043476 */
if(!s->budget--) { s->failed_pc=0x0c043476u; return 0; }
r[14]=r[15];
goto P_0c043478;
P_0c043478: /* original 65e3, guest PC 0x0c043478 */
if(!s->budget--) { s->failed_pc=0x0c043478u; return 0; }
r[5]=r[14];
goto P_0c04347a;
P_0c04347a: /* original 2e42, guest PC 0x0c04347a */
if(!s->budget--) { s->failed_pc=0x0c04347au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c04347c;
P_0c04347c: /* original 1e31, guest PC 0x0c04347c */
if(!s->budget--) { s->failed_pc=0x0c04347cu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04347e;
P_0c04347e: /* original d21a, guest PC 0x0c04347e */
if(!s->budget--) { s->failed_pc=0x0c04347eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043480;
P_0c043480: /* original 420b, guest PC 0x0c043480 */
if(!s->budget--) { s->failed_pc=0x0c043480u; return 0; }
target=r[2];
r[16]=code_base|0x0c043484u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043484u) { target=s->pc; goto dispatch; }
goto P_0c043484;
P_0c043482: /* original e417, guest PC 0x0c043482 */
if(!s->budget--) { s->failed_pc=0x0c043482u; return 0; }
r[4]=0x00000017u;
goto P_0c043484;
P_0c043484: /* original 7f08, guest PC 0x0c043484 */
if(!s->budget--) { s->failed_pc=0x0c043484u; return 0; }
r[15]+=0x00000008u;
goto P_0c043486;
P_0c043486: /* original 4f26, guest PC 0x0c043486 */
if(!s->budget--) { s->failed_pc=0x0c043486u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043488;
P_0c043488: /* original 000b, guest PC 0x0c043488 */
if(!s->budget--) { s->failed_pc=0x0c043488u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04348a: /* original 6ef6, guest PC 0x0c04348a */
if(!s->budget--) { s->failed_pc=0x0c04348au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04348cu,s,ram);
P_0c04348e: /* original 4f22, guest PC 0x0c04348e */
if(!s->budget--) { s->failed_pc=0x0c04348eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043490;
P_0c043490: /* original 7ff8, guest PC 0x0c043490 */
if(!s->budget--) { s->failed_pc=0x0c043490u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043492;
P_0c043492: /* original 6ef3, guest PC 0x0c043492 */
if(!s->budget--) { s->failed_pc=0x0c043492u; return 0; }
r[14]=r[15];
goto P_0c043494;
P_0c043494: /* original 2e42, guest PC 0x0c043494 */
if(!s->budget--) { s->failed_pc=0x0c043494u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043496;
P_0c043496: /* original 1e51, guest PC 0x0c043496 */
if(!s->budget--) { s->failed_pc=0x0c043496u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043498;
P_0c043498: /* original 65e3, guest PC 0x0c043498 */
if(!s->budget--) { s->failed_pc=0x0c043498u; return 0; }
r[5]=r[14];
goto P_0c04349a;
P_0c04349a: /* original d313, guest PC 0x0c04349a */
if(!s->budget--) { s->failed_pc=0x0c04349au; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c04349c;
P_0c04349c: /* original 430b, guest PC 0x0c04349c */
if(!s->budget--) { s->failed_pc=0x0c04349cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0434a0u;
r[4]=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434a0u) { target=s->pc; goto dispatch; }
goto P_0c0434a0;
P_0c04349e: /* original e413, guest PC 0x0c04349e */
if(!s->budget--) { s->failed_pc=0x0c04349eu; return 0; }
r[4]=0x00000013u;
goto P_0c0434a0;
P_0c0434a0: /* original 7f08, guest PC 0x0c0434a0 */
if(!s->budget--) { s->failed_pc=0x0c0434a0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0434a2;
P_0c0434a2: /* original 4f26, guest PC 0x0c0434a2 */
if(!s->budget--) { s->failed_pc=0x0c0434a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434a4;
P_0c0434a4: /* original 000b, guest PC 0x0c0434a4 */
if(!s->budget--) { s->failed_pc=0x0c0434a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434a6: /* original 6ef6, guest PC 0x0c0434a6 */
if(!s->budget--) { s->failed_pc=0x0c0434a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434a8u,s,ram);
P_0c0434aa: /* original 4f22, guest PC 0x0c0434aa */
if(!s->budget--) { s->failed_pc=0x0c0434aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0434ac;
P_0c0434ac: /* original 7ff0, guest PC 0x0c0434ac */
if(!s->budget--) { s->failed_pc=0x0c0434acu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0434ae;
P_0c0434ae: /* original 6ef3, guest PC 0x0c0434ae */
if(!s->budget--) { s->failed_pc=0x0c0434aeu; return 0; }
r[14]=r[15];
goto P_0c0434b0;
P_0c0434b0: /* original 2e42, guest PC 0x0c0434b0 */
if(!s->budget--) { s->failed_pc=0x0c0434b0u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0434b2;
P_0c0434b2: /* original 1e51, guest PC 0x0c0434b2 */
if(!s->budget--) { s->failed_pc=0x0c0434b2u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c0434b4;
P_0c0434b4: /* original 65e3, guest PC 0x0c0434b4 */
if(!s->budget--) { s->failed_pc=0x0c0434b4u; return 0; }
r[5]=r[14];
goto P_0c0434b6;
P_0c0434b6: /* original 1e62, guest PC 0x0c0434b6 */
if(!s->budget--) { s->failed_pc=0x0c0434b6u; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c0434b8;
P_0c0434b8: /* original 1e73, guest PC 0x0c0434b8 */
if(!s->budget--) { s->failed_pc=0x0c0434b8u; return 0; }
write(ram,r[14]+12,r[7],4);
goto P_0c0434ba;
P_0c0434ba: /* original d30b, guest PC 0x0c0434ba */
if(!s->budget--) { s->failed_pc=0x0c0434bau; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c0434bc;
P_0c0434bc: /* original 430b, guest PC 0x0c0434bc */
if(!s->budget--) { s->failed_pc=0x0c0434bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0434c0u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434c0u) { target=s->pc; goto dispatch; }
goto P_0c0434c0;
P_0c0434be: /* original e41d, guest PC 0x0c0434be */
if(!s->budget--) { s->failed_pc=0x0c0434beu; return 0; }
r[4]=0x0000001du;
goto P_0c0434c0;
P_0c0434c0: /* original 7f10, guest PC 0x0c0434c0 */
if(!s->budget--) { s->failed_pc=0x0c0434c0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0434c2;
P_0c0434c2: /* original 4f26, guest PC 0x0c0434c2 */
if(!s->budget--) { s->failed_pc=0x0c0434c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434c4;
P_0c0434c4: /* original 000b, guest PC 0x0c0434c4 */
if(!s->budget--) { s->failed_pc=0x0c0434c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434c6: /* original 6ef6, guest PC 0x0c0434c6 */
if(!s->budget--) { s->failed_pc=0x0c0434c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434c8u,s,ram);
P_0c047230: /* original 4f22, guest PC 0x0c047230 */
if(!s->budget--) { s->failed_pc=0x0c047230u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c047232;
P_0c047232: /* original 7ff0, guest PC 0x0c047232 */
if(!s->budget--) { s->failed_pc=0x0c047232u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c047234;
P_0c047234: /* original 1f43, guest PC 0x0c047234 */
if(!s->budget--) { s->failed_pc=0x0c047234u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c047236;
P_0c047236: /* original 54f3, guest PC 0x0c047236 */
if(!s->budget--) { s->failed_pc=0x0c047236u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c047238;
P_0c047238: /* original d317, guest PC 0x0c047238 */
if(!s->budget--) { s->failed_pc=0x0c047238u; return 0; }
r[3]=read(ram,0x0c047298u,4);
goto P_0c04723a;
P_0c04723a: /* original 430b, guest PC 0x0c04723a */
if(!s->budget--) { s->failed_pc=0x0c04723au; return 0; }
target=r[3];
r[16]=code_base|0x0c04723eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04723eu) { target=s->pc; goto dispatch; }
goto P_0c04723e;
P_0c04723c: /* original 0009, guest PC 0x0c04723c */
if(!s->budget--) { s->failed_pc=0x0c04723cu; return 0; }
goto P_0c04723e;
P_0c04723e: /* original 1f02, guest PC 0x0c04723e */
if(!s->budget--) { s->failed_pc=0x0c04723eu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c047240;
P_0c047240: /* original e602, guest PC 0x0c047240 */
if(!s->budget--) { s->failed_pc=0x0c047240u; return 0; }
r[6]=0x00000002u;
goto P_0c047242;
P_0c047242: /* original 65f3, guest PC 0x0c047242 */
if(!s->budget--) { s->failed_pc=0x0c047242u; return 0; }
r[5]=r[15];
goto P_0c047244;
P_0c047244: /* original 7504, guest PC 0x0c047244 */
if(!s->budget--) { s->failed_pc=0x0c047244u; return 0; }
r[5]+=0x00000004u;
goto P_0c047246;
P_0c047246: /* original d415, guest PC 0x0c047246 */
if(!s->budget--) { s->failed_pc=0x0c047246u; return 0; }
r[4]=read(ram,0x0c04729cu,4);
goto P_0c047248;
P_0c047248: /* original d315, guest PC 0x0c047248 */
if(!s->budget--) { s->failed_pc=0x0c047248u; return 0; }
r[3]=read(ram,0x0c0472a0u,4);
goto P_0c04724a;
P_0c04724a: /* original 430b, guest PC 0x0c04724a */
if(!s->budget--) { s->failed_pc=0x0c04724au; return 0; }
target=r[3];
r[16]=code_base|0x0c04724eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04724eu) { target=s->pc; goto dispatch; }
goto P_0c04724e;
P_0c04724c: /* original 0009, guest PC 0x0c04724c */
if(!s->budget--) { s->failed_pc=0x0c04724cu; return 0; }
goto P_0c04724e;
P_0c04724e: /* original 2008, guest PC 0x0c04724e */
if(!s->budget--) { s->failed_pc=0x0c04724eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c047250;
P_0c047250: /* original 8b18, guest PC 0x0c047250 */
if(!s->budget--) { s->failed_pc=0x0c047250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047284; }
goto P_0c047252;
P_0c047252: /* original 84f4, guest PC 0x0c047252 */
if(!s->budget--) { s->failed_pc=0x0c047252u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c047254;
P_0c047254: /* original 600c, guest PC 0x0c047254 */
if(!s->budget--) { s->failed_pc=0x0c047254u; return 0; }
r[0]=r[0]&255u;
goto P_0c047256;
P_0c047256: /* original 931e, guest PC 0x0c047256 */
if(!s->budget--) { s->failed_pc=0x0c047256u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047296u,2);
goto P_0c047258;
P_0c047258: /* original 3030, guest PC 0x0c047258 */
if(!s->budget--) { s->failed_pc=0x0c047258u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c04725a;
P_0c04725a: /* original 8b03, guest PC 0x0c04725a */
if(!s->budget--) { s->failed_pc=0x0c04725au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047264; }
goto P_0c04725c;
P_0c04725c: /* original 84f5, guest PC 0x0c04725c */
if(!s->budget--) { s->failed_pc=0x0c04725cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+5,1);
goto P_0c04725e;
P_0c04725e: /* original 600c, guest PC 0x0c04725e */
if(!s->budget--) { s->failed_pc=0x0c04725eu; return 0; }
r[0]=r[0]&255u;
goto P_0c047260;
P_0c047260: /* original 3030, guest PC 0x0c047260 */
if(!s->budget--) { s->failed_pc=0x0c047260u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c047262;
P_0c047262: /* original 890f, guest PC 0x0c047262 */
if(!s->budget--) { s->failed_pc=0x0c047262u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047284; }
goto P_0c047264;
P_0c047264: /* original d30f, guest PC 0x0c047264 */
if(!s->budget--) { s->failed_pc=0x0c047264u; return 0; }
r[3]=read(ram,0x0c0472a4u,4);
goto P_0c047266;
P_0c047266: /* original 2f32, guest PC 0x0c047266 */
if(!s->budget--) { s->failed_pc=0x0c047266u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c047268;
P_0c047268: /* original 62f2, guest PC 0x0c047268 */
if(!s->budget--) { s->failed_pc=0x0c047268u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04726a;
P_0c04726a: /* original 7201, guest PC 0x0c04726a */
if(!s->budget--) { s->failed_pc=0x0c04726au; return 0; }
r[2]+=0x00000001u;
goto P_0c04726c;
P_0c04726c: /* original 2f22, guest PC 0x0c04726c */
if(!s->budget--) { s->failed_pc=0x0c04726cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04726e;
P_0c04726e: /* original 72ff, guest PC 0x0c04726e */
if(!s->budget--) { s->failed_pc=0x0c04726eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c047270;
P_0c047270: /* original 84f4, guest PC 0x0c047270 */
if(!s->budget--) { s->failed_pc=0x0c047270u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c047272;
P_0c047272: /* original 2200, guest PC 0x0c047272 */
if(!s->budget--) { s->failed_pc=0x0c047272u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c047274;
P_0c047274: /* original 63f2, guest PC 0x0c047274 */
if(!s->budget--) { s->failed_pc=0x0c047274u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c047276;
P_0c047276: /* original 84f5, guest PC 0x0c047276 */
if(!s->budget--) { s->failed_pc=0x0c047276u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+5,1);
goto P_0c047278;
P_0c047278: /* original 2300, guest PC 0x0c047278 */
if(!s->budget--) { s->failed_pc=0x0c047278u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c04727a;
P_0c04727a: /* original e502, guest PC 0x0c04727a */
if(!s->budget--) { s->failed_pc=0x0c04727au; return 0; }
r[5]=0x00000002u;
goto P_0c04727c;
P_0c04727c: /* original d409, guest PC 0x0c04727c */
if(!s->budget--) { s->failed_pc=0x0c04727cu; return 0; }
r[4]=read(ram,0x0c0472a4u,4);
goto P_0c04727e;
P_0c04727e: /* original d30a, guest PC 0x0c04727e */
if(!s->budget--) { s->failed_pc=0x0c04727eu; return 0; }
r[3]=read(ram,0x0c0472a8u,4);
goto P_0c047280;
P_0c047280: /* original 430b, guest PC 0x0c047280 */
if(!s->budget--) { s->failed_pc=0x0c047280u; return 0; }
target=r[3];
r[16]=code_base|0x0c047284u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c047284u) { target=s->pc; goto dispatch; }
goto P_0c047284;
P_0c047282: /* original 0009, guest PC 0x0c047282 */
if(!s->budget--) { s->failed_pc=0x0c047282u; return 0; }
goto P_0c047284;
P_0c047284: /* original 50f2, guest PC 0x0c047284 */
if(!s->budget--) { s->failed_pc=0x0c047284u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c047286;
P_0c047286: /* original 7f10, guest PC 0x0c047286 */
if(!s->budget--) { s->failed_pc=0x0c047286u; return 0; }
r[15]+=0x00000010u;
goto P_0c047288;
P_0c047288: /* original 4f26, guest PC 0x0c047288 */
if(!s->budget--) { s->failed_pc=0x0c047288u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04728a;
P_0c04728a: /* original 000b, guest PC 0x0c04728a */
if(!s->budget--) { s->failed_pc=0x0c04728au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04728c: /* original 0009, guest PC 0x0c04728c */
if(!s->budget--) { s->failed_pc=0x0c04728cu; return 0; }
return vf3_matrix_family(0x0c04728eu,s,ram);
P_0c0482f0: /* original 63f3, guest PC 0x0c0482f0 */
if(!s->budget--) { s->failed_pc=0x0c0482f0u; return 0; }
r[3]=r[15];
goto P_0c0482f2;
P_0c0482f2: /* original fb39, guest PC 0x0c0482f2 */
if(!s->budget--) { s->failed_pc=0x0c0482f2u; return 0; }
vf3_matrix_load(s,ram,11,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f4;
P_0c0482f4: /* original f79d, guest PC 0x0c0482f4 */
if(!s->budget--) { s->failed_pc=0x0c0482f4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0482f6;
P_0c0482f6: /* original f7b5, guest PC 0x0c0482f6 */
if(!s->budget--) { s->failed_pc=0x0c0482f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[11]))!=0);
goto P_0c0482f8;
P_0c0482f8: /* original 6043, guest PC 0x0c0482f8 */
if(!s->budget--) { s->failed_pc=0x0c0482f8u; return 0; }
r[0]=r[4];
goto P_0c0482fa;
P_0c0482fa: /* original 7030, guest PC 0x0c0482fa */
if(!s->budget--) { s->failed_pc=0x0c0482fau; return 0; }
r[0]+=0x00000030u;
goto P_0c0482fc;
P_0c0482fc: /* original 8f15, guest PC 0x0c0482fc */
if(!s->budget--) { s->failed_pc=0x0c0482fcu; return 0; }
cond=r[17]&1u;
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
if(!cond) { goto P_0c04832a; }
goto P_0c048300;
P_0c0482fe: /* original 0083, guest PC 0x0c0482fe */
if(!s->budget--) { s->failed_pc=0x0c0482feu; return 0; }
if((r[0]&0xFC000000u)==0xE0000000u) pref(ram,r[0]);
goto P_0c048300;
P_0c048300: /* original e202, guest PC 0x0c048300 */
if(!s->budget--) { s->failed_pc=0x0c048300u; return 0; }
r[2]=0x00000002u;
goto P_0c048302;
P_0c048302: /* original f21d, guest PC 0x0c048302 */
if(!s->budget--) { s->failed_pc=0x0c048302u; return 0; }
r[53]=fr[2];
goto P_0c048304;
P_0c048304: /* original 4228, guest PC 0x0c048304 */
if(!s->budget--) { s->failed_pc=0x0c048304u; return 0; }
r[2]<<=16;
goto P_0c048306;
P_0c048306: /* original 005a, guest PC 0x0c048306 */
if(!s->budget--) { s->failed_pc=0x0c048306u; return 0; }
r[0]=r[53];
goto P_0c048308;
P_0c048308: /* original 4218, guest PC 0x0c048308 */
if(!s->budget--) { s->failed_pc=0x0c048308u; return 0; }
r[2]<<=8;
goto P_0c04830a;
P_0c04830a: /* original d9b7, guest PC 0x0c04830a */
if(!s->budget--) { s->failed_pc=0x0c04830au; return 0; }
r[9]=read(ram,0x0c0485e8u,4);
goto P_0c04830c;
P_0c04830c: /* original 282b, guest PC 0x0c04830c */
if(!s->budget--) { s->failed_pc=0x0c04830cu; return 0; }
r[8]|=r[2];
goto P_0c04830e;
P_0c04830e: /* original cbc0, guest PC 0x0c04830e */
if(!s->budget--) { s->failed_pc=0x0c04830eu; return 0; }
r[0]|=192u;
goto P_0c048310;
P_0c048310: /* original 6009, guest PC 0x0c048310 */
if(!s->budget--) { s->failed_pc=0x0c048310u; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048312;
P_0c048312: /* original 6992, guest PC 0x0c048312 */
if(!s->budget--) { s->failed_pc=0x0c048312u; return 0; }
tmp=read(ram,r[9],4);
r[9]=tmp;
goto P_0c048314;
P_0c048314: /* original cb10, guest PC 0x0c048314 */
if(!s->budget--) { s->failed_pc=0x0c048314u; return 0; }
r[0]|=16u;
goto P_0c048316;
P_0c048316: /* original 6008, guest PC 0x0c048316 */
if(!s->budget--) { s->failed_pc=0x0c048316u; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c048318;
P_0c048318: /* original cbfc, guest PC 0x0c048318 */
if(!s->budget--) { s->failed_pc=0x0c048318u; return 0; }
r[0]|=252u;
goto P_0c04831a;
P_0c04831a: /* original 209a, guest PC 0x0c04831a */
if(!s->budget--) { s->failed_pc=0x0c04831au; return 0; }
r[0]^=r[9];
goto P_0c04831c;
P_0c04831c: /* original 6008, guest PC 0x0c04831c */
if(!s->budget--) { s->failed_pc=0x0c04831cu; return 0; }
r[0]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c04831e;
P_0c04831e: /* original 6009, guest PC 0x0c04831e */
if(!s->budget--) { s->failed_pc=0x0c04831eu; return 0; }
r[0]=(r[0]<<16)|(r[0]>>16);
goto P_0c048320;
P_0c048320: /* original 322c, guest PC 0x0c048320 */
if(!s->budget--) { s->failed_pc=0x0c048320u; return 0; }
r[2]+=r[2];
goto P_0c048322;
P_0c048322: /* original 405a, guest PC 0x0c048322 */
if(!s->budget--) { s->failed_pc=0x0c048322u; return 0; }
r[53]=r[0];
goto P_0c048324;
P_0c048324: /* original 6227, guest PC 0x0c048324 */
if(!s->budget--) { s->failed_pc=0x0c048324u; return 0; }
r[2]=~r[2];
goto P_0c048326;
P_0c048326: /* original f20d, guest PC 0x0c048326 */
if(!s->budget--) { s->failed_pc=0x0c048326u; return 0; }
fr[2]=r[53];
goto P_0c048328;
P_0c048328: /* original 2829, guest PC 0x0c048328 */
if(!s->budget--) { s->failed_pc=0x0c048328u; return 0; }
r[8]&=r[2];
goto P_0c04832a;
P_0c04832a: /* original 6083, guest PC 0x0c04832a */
if(!s->budget--) { s->failed_pc=0x0c04832au; return 0; }
r[0]=r[8];
goto P_0c04832c;
P_0c04832c: /* original f449, guest PC 0x0c04832c */
if(!s->budget--) { s->failed_pc=0x0c04832cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c04832e;
P_0c04832e: /* original 4029, guest PC 0x0c04832e */
if(!s->budget--) { s->failed_pc=0x0c04832eu; return 0; }
r[0]>>=16;
goto P_0c048330;
P_0c048330: /* original f549, guest PC 0x0c048330 */
if(!s->budget--) { s->failed_pc=0x0c048330u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048332;
P_0c048332: /* original 4019, guest PC 0x0c048332 */
if(!s->budget--) { s->failed_pc=0x0c048332u; return 0; }
r[0]>>=8;
goto P_0c048334;
P_0c048334: /* original f649, guest PC 0x0c048334 */
if(!s->budget--) { s->failed_pc=0x0c048334u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048336;
P_0c048336: /* original c907, guest PC 0x0c048336 */
if(!s->budget--) { s->failed_pc=0x0c048336u; return 0; }
r[0]&=7u;
goto P_0c048338;
P_0c048338: /* original e204, guest PC 0x0c048338 */
if(!s->budget--) { s->failed_pc=0x0c048338u; return 0; }
r[2]=0x00000004u;
goto P_0c04833a;
P_0c04833a: /* original 4008, guest PC 0x0c04833a */
if(!s->budget--) { s->failed_pc=0x0c04833au; return 0; }
r[0]<<=2;
goto P_0c04833c;
P_0c04833c: /* original f5fd, guest PC 0x0c04833c */
if(!s->budget--) { s->failed_pc=0x0c04833cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04833e;
P_0c04833e: /* original f139, guest PC 0x0c04833e */
if(!s->budget--) { s->failed_pc=0x0c04833eu; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048340;
P_0c048340: /* original 4218, guest PC 0x0c048340 */
if(!s->budget--) { s->failed_pc=0x0c048340u; return 0; }
r[2]<<=8;
goto P_0c048342;
P_0c048342: /* original f049, guest PC 0x0c048342 */
if(!s->budget--) { s->failed_pc=0x0c048342u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048344;
P_0c048344: /* original 3b00, guest PC 0x0c048344 */
if(!s->budget--) { s->failed_pc=0x0c048344u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[0])!=0);
goto P_0c048346;
P_0c048346: /* original 6b03, guest PC 0x0c048346 */
if(!s->budget--) { s->failed_pc=0x0c048346u; return 0; }
r[11]=r[0];
goto P_0c048348;
P_0c048348: /* original e6e0, guest PC 0x0c048348 */
if(!s->budget--) { s->failed_pc=0x0c048348u; return 0; }
r[6]=0xffffffe0u;
goto P_0c04834a;
P_0c04834a: /* original f012, guest PC 0x0c04834a */
if(!s->budget--) { s->failed_pc=0x0c04834au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'*');
goto P_0c04834c;
P_0c04834c: /* original 4228, guest PC 0x0c04834c */
if(!s->budget--) { s->failed_pc=0x0c04834cu; return 0; }
r[2]<<=16;
goto P_0c04834e;
P_0c04834e: /* original 8d09, guest PC 0x0c04834e */
if(!s->budget--) { s->failed_pc=0x0c04834eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c048364; }
goto P_0c048352;
P_0c048350: /* original 05ae, guest PC 0x0c048350 */
if(!s->budget--) { s->failed_pc=0x0c048350u; return 0; }
r[5]=read(ram,r[10]+r[0],4);
goto P_0c048352;
P_0c048352: /* original e0ff, guest PC 0x0c048352 */
if(!s->budget--) { s->failed_pc=0x0c048352u; return 0; }
r[0]=0xffffffffu;
goto P_0c048354;
P_0c048354: /* original 4028, guest PC 0x0c048354 */
if(!s->budget--) { s->failed_pc=0x0c048354u; return 0; }
r[0]<<=16;
goto P_0c048356;
P_0c048356: /* original 4018, guest PC 0x0c048356 */
if(!s->budget--) { s->failed_pc=0x0c048356u; return 0; }
r[0]<<=8;
goto P_0c048358;
P_0c048358: /* original cb38, guest PC 0x0c048358 */
if(!s->budget--) { s->failed_pc=0x0c048358u; return 0; }
r[0]|=56u;
goto P_0c04835a;
P_0c04835a: /* original 6953, guest PC 0x0c04835a */
if(!s->budget--) { s->failed_pc=0x0c04835au; return 0; }
r[9]=r[5];
goto P_0c04835c;
P_0c04835c: /* original 4929, guest PC 0x0c04835c */
if(!s->budget--) { s->failed_pc=0x0c04835cu; return 0; }
r[9]>>=16;
goto P_0c04835e;
P_0c04835e: /* original 4919, guest PC 0x0c04835e */
if(!s->budget--) { s->failed_pc=0x0c04835eu; return 0; }
r[9]>>=8;
goto P_0c048360;
P_0c048360: /* original 2092, guest PC 0x0c048360 */
if(!s->budget--) { s->failed_pc=0x0c048360u; return 0; }
write(ram,r[0],r[9],4);
goto P_0c048362;
P_0c048362: /* original 1091, guest PC 0x0c048362 */
if(!s->budget--) { s->failed_pc=0x0c048362u; return 0; }
write(ram,r[0]+4,r[9],4);
goto P_0c048364;
P_0c048364: /* original 72ff, guest PC 0x0c048364 */
if(!s->budget--) { s->failed_pc=0x0c048364u; return 0; }
r[2]+=0xffffffffu;
goto P_0c048366;
P_0c048366: /* original 4c5a, guest PC 0x0c048366 */
if(!s->budget--) { s->failed_pc=0x0c048366u; return 0; }
r[53]=r[12];
goto P_0c048368;
P_0c048368: /* original e0fe, guest PC 0x0c048368 */
if(!s->budget--) { s->failed_pc=0x0c048368u; return 0; }
r[0]=0xfffffffeu;
goto P_0c04836a;
P_0c04836a: /* original f700, guest PC 0x0c04836a */
if(!s->budget--) { s->failed_pc=0x0c04836au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'+');
goto P_0c04836c;
P_0c04836c: /* original 2259, guest PC 0x0c04836c */
if(!s->budget--) { s->failed_pc=0x0c04836cu; return 0; }
r[2]&=r[5];
goto P_0c04836e;
P_0c04836e: /* original f10d, guest PC 0x0c04836e */
if(!s->budget--) { s->failed_pc=0x0c04836eu; return 0; }
fr[1]=r[53];
goto P_0c048370;
P_0c048370: /* original 4618, guest PC 0x0c048370 */
if(!s->budget--) { s->failed_pc=0x0c048370u; return 0; }
r[6]<<=8;
goto P_0c048372;
P_0c048372: /* original f715, guest PC 0x0c048372 */
if(!s->budget--) { s->failed_pc=0x0c048372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048374;
P_0c048374: /* original 4628, guest PC 0x0c048374 */
if(!s->budget--) { s->failed_pc=0x0c048374u; return 0; }
r[6]<<=16;
goto P_0c048376;
P_0c048376: /* original 262b, guest PC 0x0c048376 */
if(!s->budget--) { s->failed_pc=0x0c048376u; return 0; }
r[6]|=r[2];
goto P_0c048378;
P_0c048378: /* original f701, guest PC 0x0c048378 */
if(!s->budget--) { s->failed_pc=0x0c048378u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c04837a;
P_0c04837a: /* original 2c09, guest PC 0x0c04837a */
if(!s->budget--) { s->failed_pc=0x0c04837au; return 0; }
r[12]&=r[0];
goto P_0c04837c;
P_0c04837c: /* original 59f9, guest PC 0x0c04837c */
if(!s->budget--) { s->failed_pc=0x0c04837cu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c04837e;
P_0c04837e: /* original 8f43, guest PC 0x0c04837e */
if(!s->budget--) { s->failed_pc=0x0c04837eu; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
if(!cond) { goto P_0c048408; }
goto P_0c048382;
P_0c048380: /* original f701, guest PC 0x0c048380 */
if(!s->budget--) { s->failed_pc=0x0c048380u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c048382;
P_0c048382: /* original f715, guest PC 0x0c048382 */
if(!s->budget--) { s->failed_pc=0x0c048382u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c048384;
P_0c048384: /* original 8f40, guest PC 0x0c048384 */
if(!s->budget--) { s->failed_pc=0x0c048384u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c048408; }
goto P_0c048388;
P_0c048386: /* original 7c01, guest PC 0x0c048386 */
if(!s->budget--) { s->failed_pc=0x0c048386u; return 0; }
r[12]+=0x00000001u;
goto P_0c048388;
P_0c048388: /* original 6243, guest PC 0x0c048388 */
if(!s->budget--) { s->failed_pc=0x0c048388u; return 0; }
r[2]=r[4];
goto P_0c04838a;
P_0c04838a: /* original 742c, guest PC 0x0c04838a */
if(!s->budget--) { s->failed_pc=0x0c04838au; return 0; }
r[4]+=0x0000002cu;
goto P_0c04838c;
P_0c04838c: /* original 6046, guest PC 0x0c04838c */
if(!s->budget--) { s->failed_pc=0x0c04838cu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04838e;
P_0c04838e: /* original 2682, guest PC 0x0c04838e */
if(!s->budget--) { s->failed_pc=0x0c04838eu; return 0; }
write(ram,r[6],r[8],4);
goto P_0c048390;
P_0c048390: /* original 6183, guest PC 0x0c048390 */
if(!s->budget--) { s->failed_pc=0x0c048390u; return 0; }
r[1]=r[8];
goto P_0c048392;
P_0c048392: /* original 340c, guest PC 0x0c048392 */
if(!s->budget--) { s->failed_pc=0x0c048392u; return 0; }
r[4]+=r[0];
goto P_0c048394;
P_0c048394: /* original 6846, guest PC 0x0c048394 */
if(!s->budget--) { s->failed_pc=0x0c048394u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[8]=tmp;
goto P_0c048396;
P_0c048396: /* original 2888, guest PC 0x0c048396 */
if(!s->budget--) { s->failed_pc=0x0c048396u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c048398;
P_0c048398: /* original 8b02, guest PC 0x0c048398 */
if(!s->budget--) { s->failed_pc=0x0c048398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0483a0; }
goto P_0c04839a;
P_0c04839a: /* original a0ef, guest PC 0x0c04839a */
if(!s->budget--) { s->failed_pc=0x0c04839au; return 0; }
goto P_0c04857c;
P_0c04839c: /* original 0009, guest PC 0x0c04839c */
if(!s->budget--) { s->failed_pc=0x0c04839cu; return 0; }
return vf3_matrix_family(0x0c04839eu,s,ram);
P_0c0483a0: /* original 69f3, guest PC 0x0c0483a0 */
if(!s->budget--) { s->failed_pc=0x0c0483a0u; return 0; }
r[9]=r[15];
goto P_0c0483a2;
P_0c0483a2: /* original 7918, guest PC 0x0c0483a2 */
if(!s->budget--) { s->failed_pc=0x0c0483a2u; return 0; }
r[9]+=0x00000018u;
goto P_0c0483a4;
P_0c0483a4: /* original f599, guest PC 0x0c0483a4 */
if(!s->budget--) { s->failed_pc=0x0c0483a4u; return 0; }
vf3_matrix_load(s,ram,5,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a6;
P_0c0483a6: /* original f699, guest PC 0x0c0483a6 */
if(!s->budget--) { s->failed_pc=0x0c0483a6u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483a8;
P_0c0483a8: /* original 7208, guest PC 0x0c0483a8 */
if(!s->budget--) { s->failed_pc=0x0c0483a8u; return 0; }
r[2]+=0x00000008u;
goto P_0c0483aa;
P_0c0483aa: /* original f799, guest PC 0x0c0483aa */
if(!s->budget--) { s->failed_pc=0x0c0483aau; return 0; }
vf3_matrix_load(s,ram,7,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ac;
P_0c0483ac: /* original 6026, guest PC 0x0c0483ac */
if(!s->budget--) { s->failed_pc=0x0c0483acu; return 0; }
tmp=read(ram,r[2],4);
r[2]+=4;
r[0]=tmp;
goto P_0c0483ae;
P_0c0483ae: /* original c801, guest PC 0x0c0483ae */
if(!s->budget--) { s->failed_pc=0x0c0483aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0483b0;
P_0c0483b0: /* original 6013, guest PC 0x0c0483b0 */
if(!s->budget--) { s->failed_pc=0x0c0483b0u; return 0; }
r[0]=r[1];
goto P_0c0483b2;
P_0c0483b2: /* original 8f24, guest PC 0x0c0483b2 */
if(!s->budget--) { s->failed_pc=0x0c0483b2u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!cond) { goto P_0c0483fe; }
goto P_0c0483b6;
P_0c0483b4: /* original c820, guest PC 0x0c0483b4 */
if(!s->budget--) { s->failed_pc=0x0c0483b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0483b6;
P_0c0483b6: /* original 8922, guest PC 0x0c0483b6 */
if(!s->budget--) { s->failed_pc=0x0c0483b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0483fe; }
goto P_0c0483b8;
P_0c0483b8: /* original f029, guest PC 0x0c0483b8 */
if(!s->budget--) { s->failed_pc=0x0c0483b8u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ba;
P_0c0483ba: /* original f129, guest PC 0x0c0483ba */
if(!s->budget--) { s->failed_pc=0x0c0483bau; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483bc;
P_0c0483bc: /* original f229, guest PC 0x0c0483bc */
if(!s->budget--) { s->failed_pc=0x0c0483bcu; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483be;
P_0c0483be: /* original f329, guest PC 0x0c0483be */
if(!s->budget--) { s->failed_pc=0x0c0483beu; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c0;
P_0c0483c0: /* original f0b2, guest PC 0x0c0483c0 */
if(!s->budget--) { s->failed_pc=0x0c0483c0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c0483c2;
P_0c0483c2: /* original fb5c, guest PC 0x0c0483c2 */
if(!s->budget--) { s->failed_pc=0x0c0483c2u; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c0483c4;
P_0c0483c4: /* original f152, guest PC 0x0c0483c4 */
if(!s->budget--) { s->failed_pc=0x0c0483c4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c0483c6;
P_0c0483c6: /* original f429, guest PC 0x0c0483c6 */
if(!s->budget--) { s->failed_pc=0x0c0483c6u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483c8;
P_0c0483c8: /* original f529, guest PC 0x0c0483c8 */
if(!s->budget--) { s->failed_pc=0x0c0483c8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483ca;
P_0c0483ca: /* original f5b2, guest PC 0x0c0483ca */
if(!s->budget--) { s->failed_pc=0x0c0483cau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c0483cc;
P_0c0483cc: /* original fb6c, guest PC 0x0c0483cc */
if(!s->budget--) { s->failed_pc=0x0c0483ccu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c0483ce;
P_0c0483ce: /* original f262, guest PC 0x0c0483ce */
if(!s->budget--) { s->failed_pc=0x0c0483ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0483d0;
P_0c0483d0: /* original f629, guest PC 0x0c0483d0 */
if(!s->budget--) { s->failed_pc=0x0c0483d0u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483d2;
P_0c0483d2: /* original f6b2, guest PC 0x0c0483d2 */
if(!s->budget--) { s->failed_pc=0x0c0483d2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0483d4;
P_0c0483d4: /* original fb7c, guest PC 0x0c0483d4 */
if(!s->budget--) { s->failed_pc=0x0c0483d4u; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c0483d6;
P_0c0483d6: /* original f372, guest PC 0x0c0483d6 */
if(!s->budget--) { s->failed_pc=0x0c0483d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0483d8;
P_0c0483d8: /* original f729, guest PC 0x0c0483d8 */
if(!s->budget--) { s->failed_pc=0x0c0483d8u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c0483da;
P_0c0483da: /* original f3fd, guest PC 0x0c0483da */
if(!s->budget--) { s->failed_pc=0x0c0483dau; return 0; }
r[18]^=0x100000u;
goto P_0c0483dc;
P_0c0483dc: /* original f7b2, guest PC 0x0c0483dc */
if(!s->budget--) { s->failed_pc=0x0c0483dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0483de;
P_0c0483de: /* original e000, guest PC 0x0c0483de */
if(!s->budget--) { s->failed_pc=0x0c0483deu; return 0; }
r[0]=0x00000000u;
goto P_0c0483e0;
P_0c0483e0: /* original 1601, guest PC 0x0c0483e0 */
if(!s->budget--) { s->failed_pc=0x0c0483e0u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0483e2;
P_0c0483e2: /* original 1602, guest PC 0x0c0483e2 */
if(!s->budget--) { s->failed_pc=0x0c0483e2u; return 0; }
write(ram,r[6]+8,r[0],4);
goto P_0c0483e4;
P_0c0483e4: /* original 1603, guest PC 0x0c0483e4 */
if(!s->budget--) { s->failed_pc=0x0c0483e4u; return 0; }
write(ram,r[6]+12,r[0],4);
goto P_0c0483e6;
P_0c0483e6: /* original 0683, guest PC 0x0c0483e6 */
if(!s->budget--) { s->failed_pc=0x0c0483e6u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c0483e8;
P_0c0483e8: /* original 7640, guest PC 0x0c0483e8 */
if(!s->budget--) { s->failed_pc=0x0c0483e8u; return 0; }
r[6]+=0x00000040u;
goto P_0c0483ea;
P_0c0483ea: /* original f66b, guest PC 0x0c0483ea */
if(!s->budget--) { s->failed_pc=0x0c0483eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0483ec;
P_0c0483ec: /* original f64b, guest PC 0x0c0483ec */
if(!s->budget--) { s->failed_pc=0x0c0483ecu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0483ee;
P_0c0483ee: /* original 60b3, guest PC 0x0c0483ee */
if(!s->budget--) { s->failed_pc=0x0c0483eeu; return 0; }
r[0]=r[11];
goto P_0c0483f0;
P_0c0483f0: /* original f62b, guest PC 0x0c0483f0 */
if(!s->budget--) { s->failed_pc=0x0c0483f0u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0483f2;
P_0c0483f2: /* original 7540, guest PC 0x0c0483f2 */
if(!s->budget--) { s->failed_pc=0x0c0483f2u; return 0; }
r[5]+=0x00000040u;
goto P_0c0483f4;
P_0c0483f4: /* original f60b, guest PC 0x0c0483f4 */
if(!s->budget--) { s->failed_pc=0x0c0483f4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0483f6;
P_0c0483f6: /* original f3fd, guest PC 0x0c0483f6 */
if(!s->budget--) { s->failed_pc=0x0c0483f6u; return 0; }
r[18]^=0x100000u;
goto P_0c0483f8;
P_0c0483f8: /* original 0683, guest PC 0x0c0483f8 */
if(!s->budget--) { s->failed_pc=0x0c0483f8u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c0483fa;
P_0c0483fa: /* original 7620, guest PC 0x0c0483fa */
if(!s->budget--) { s->failed_pc=0x0c0483fau; return 0; }
r[6]+=0x00000020u;
goto P_0c0483fc;
P_0c0483fc: /* original 0a56, guest PC 0x0c0483fc */
if(!s->budget--) { s->failed_pc=0x0c0483fcu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0483fe;
P_0c0483fe: /* original 6146, guest PC 0x0c0483fe */
if(!s->budget--) { s->failed_pc=0x0c0483feu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c048400;
P_0c048400: /* original f249, guest PC 0x0c048400 */
if(!s->budget--) { s->failed_pc=0x0c048400u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048402;
P_0c048402: /* original af75, guest PC 0x0c048402 */
if(!s->budget--) { s->failed_pc=0x0c048402u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c048404: /* original f349, guest PC 0x0c048404 */
if(!s->budget--) { s->failed_pc=0x0c048404u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c048406u,s,ram);
P_0c048408: /* original f139, guest PC 0x0c048408 */
if(!s->budget--) { s->failed_pc=0x0c048408u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04840a;
P_0c04840a: /* original 7910, guest PC 0x0c04840a */
if(!s->budget--) { s->failed_pc=0x0c04840au; return 0; }
r[9]+=0x00000010u;
goto P_0c04840c;
P_0c04840c: /* original f04d, guest PC 0x0c04840c */
if(!s->budget--) { s->failed_pc=0x0c04840cu; return 0; }
fr[0]^=0x80000000u;
goto P_0c04840e;
P_0c04840e: /* original f102, guest PC 0x0c04840e */
if(!s->budget--) { s->failed_pc=0x0c04840eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[0],r[18],'*');
goto P_0c048410;
P_0c048410: /* original f93b, guest PC 0x0c048410 */
if(!s->budget--) { s->failed_pc=0x0c048410u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c048412;
P_0c048412: /* original 6243, guest PC 0x0c048412 */
if(!s->budget--) { s->failed_pc=0x0c048412u; return 0; }
r[2]=r[4];
goto P_0c048414;
P_0c048414: /* original f339, guest PC 0x0c048414 */
if(!s->budget--) { s->failed_pc=0x0c048414u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048416;
P_0c048416: /* original f515, guest PC 0x0c048416 */
if(!s->budget--) { s->failed_pc=0x0c048416u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[1]))!=0);
goto P_0c048418;
P_0c048418: /* original f92b, guest PC 0x0c048418 */
if(!s->budget--) { s->failed_pc=0x0c048418u; return 0; }
r[9]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[9]);
goto P_0c04841a;
P_0c04841a: /* original f302, guest PC 0x0c04841a */
if(!s->budget--) { s->failed_pc=0x0c04841au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c04841c;
P_0c04841c: /* original f039, guest PC 0x0c04841c */
if(!s->budget--) { s->failed_pc=0x0c04841cu; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04841e;
P_0c04841e: /* original 8fb3, guest PC 0x0c04841e */
if(!s->budget--) { s->failed_pc=0x0c04841eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c048422;
P_0c048420: /* original f635, guest PC 0x0c048420 */
if(!s->budget--) { s->failed_pc=0x0c048420u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c048422;
P_0c048422: /* original f739, guest PC 0x0c048422 */
if(!s->budget--) { s->failed_pc=0x0c048422u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048424;
P_0c048424: /* original f042, guest PC 0x0c048424 */
if(!s->budget--) { s->failed_pc=0x0c048424u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c048426;
P_0c048426: /* original 5022, guest PC 0x0c048426 */
if(!s->budget--) { s->failed_pc=0x0c048426u; return 0; }
r[0]=read(ram,r[2]+8,4);
goto P_0c048428;
P_0c048428: /* original f011, guest PC 0x0c048428 */
if(!s->budget--) { s->failed_pc=0x0c048428u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c04842a;
P_0c04842a: /* original 8fad, guest PC 0x0c04842a */
if(!s->budget--) { s->failed_pc=0x0c04842au; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
if(!cond) { goto P_0c048388; }
goto P_0c04842e;
P_0c04842c: /* original f505, guest PC 0x0c04842c */
if(!s->budget--) { s->failed_pc=0x0c04842cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[0]))!=0);
goto P_0c04842e;
P_0c04842e: /* original f539, guest PC 0x0c04842e */
if(!s->budget--) { s->failed_pc=0x0c04842eu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048430;
P_0c048430: /* original f742, guest PC 0x0c048430 */
if(!s->budget--) { s->failed_pc=0x0c048430u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c048432;
P_0c048432: /* original 8da9, guest PC 0x0c048432 */
if(!s->budget--) { s->failed_pc=0x0c048432u; return 0; }
cond=r[17]&1u;
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
if(cond) { goto P_0c048388; }
goto P_0c048436;
P_0c048434: /* original 2916, guest PC 0x0c048434 */
if(!s->budget--) { s->failed_pc=0x0c048434u; return 0; }
tmp=r[1]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c048436;
P_0c048436: /* original f731, guest PC 0x0c048436 */
if(!s->budget--) { s->failed_pc=0x0c048436u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c048438;
P_0c048438: /* original 2986, guest PC 0x0c048438 */
if(!s->budget--) { s->failed_pc=0x0c048438u; return 0; }
tmp=r[8]; r[9]-=4; write(ram,r[9],tmp,4);
goto P_0c04843a;
P_0c04843a: /* original e108, guest PC 0x0c04843a */
if(!s->budget--) { s->failed_pc=0x0c04843au; return 0; }
r[1]=0x00000008u;
goto P_0c04843c;
P_0c04843c: /* original f675, guest PC 0x0c04843c */
if(!s->budget--) { s->failed_pc=0x0c04843cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c04843e;
P_0c04843e: /* original f639, guest PC 0x0c04843e */
if(!s->budget--) { s->failed_pc=0x0c04843eu; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c048440;
P_0c048440: /* original 89a2, guest PC 0x0c048440 */
if(!s->budget--) { s->failed_pc=0x0c048440u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048388; }
goto P_0c048442;
P_0c048442: /* original c801, guest PC 0x0c048442 */
if(!s->budget--) { s->failed_pc=0x0c048442u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c048444;
P_0c048444: /* original 8424, guest PC 0x0c048444 */
if(!s->budget--) { s->failed_pc=0x0c048444u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+4,1);
goto P_0c048446;
P_0c048446: /* original 7208, guest PC 0x0c048446 */
if(!s->budget--) { s->failed_pc=0x0c048446u; return 0; }
r[2]+=0x00000008u;
goto P_0c048448;
P_0c048448: /* original f739, guest PC 0x0c048448 */
if(!s->budget--) { s->failed_pc=0x0c048448u; return 0; }
vf3_matrix_load(s,ram,7,r[3]);
r[3]+=(r[18]&0x100000u)?8:4;
goto P_0c04844a;
P_0c04844a: /* original 6803, guest PC 0x0c04844a */
if(!s->budget--) { s->failed_pc=0x0c04844au; return 0; }
r[8]=r[0];
goto P_0c04844c;
P_0c04844c: /* original ff29, guest PC 0x0c04844c */
if(!s->budget--) { s->failed_pc=0x0c04844cu; return 0; }
vf3_matrix_load(s,ram,15,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04844e;
P_0c04844e: /* original 8f1a, guest PC 0x0c04844e */
if(!s->budget--) { s->failed_pc=0x0c04844eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000030u;
if(!cond) { goto P_0c048486; }
goto P_0c048452;
P_0c048450: /* original 7430, guest PC 0x0c048450 */
if(!s->budget--) { s->failed_pc=0x0c048450u; return 0; }
r[4]+=0x00000030u;
goto P_0c048452;
P_0c048452: /* original f029, guest PC 0x0c048452 */
if(!s->budget--) { s->failed_pc=0x0c048452u; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048454;
P_0c048454: /* original f129, guest PC 0x0c048454 */
if(!s->budget--) { s->failed_pc=0x0c048454u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048456;
P_0c048456: /* original f229, guest PC 0x0c048456 */
if(!s->budget--) { s->failed_pc=0x0c048456u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048458;
P_0c048458: /* original f329, guest PC 0x0c048458 */
if(!s->budget--) { s->failed_pc=0x0c048458u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04845a;
P_0c04845a: /* original f0b2, guest PC 0x0c04845a */
if(!s->budget--) { s->failed_pc=0x0c04845au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'*');
goto P_0c04845c;
P_0c04845c: /* original fb5c, guest PC 0x0c04845c */
if(!s->budget--) { s->failed_pc=0x0c04845cu; return 0; }
vf3_matrix_move(s,11,5);
goto P_0c04845e;
P_0c04845e: /* original f152, guest PC 0x0c04845e */
if(!s->budget--) { s->failed_pc=0x0c04845eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'*');
goto P_0c048460;
P_0c048460: /* original f429, guest PC 0x0c048460 */
if(!s->budget--) { s->failed_pc=0x0c048460u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048462;
P_0c048462: /* original f529, guest PC 0x0c048462 */
if(!s->budget--) { s->failed_pc=0x0c048462u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048464;
P_0c048464: /* original f5b2, guest PC 0x0c048464 */
if(!s->budget--) { s->failed_pc=0x0c048464u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'*');
goto P_0c048466;
P_0c048466: /* original fb6c, guest PC 0x0c048466 */
if(!s->budget--) { s->failed_pc=0x0c048466u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c048468;
P_0c048468: /* original f262, guest PC 0x0c048468 */
if(!s->budget--) { s->failed_pc=0x0c048468u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c04846a;
P_0c04846a: /* original f629, guest PC 0x0c04846a */
if(!s->budget--) { s->failed_pc=0x0c04846au; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c04846c;
P_0c04846c: /* original f6b2, guest PC 0x0c04846c */
if(!s->budget--) { s->failed_pc=0x0c04846cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c04846e;
P_0c04846e: /* original fb7c, guest PC 0x0c04846e */
if(!s->budget--) { s->failed_pc=0x0c04846eu; return 0; }
vf3_matrix_move(s,11,7);
goto P_0c048470;
P_0c048470: /* original f372, guest PC 0x0c048470 */
if(!s->budget--) { s->failed_pc=0x0c048470u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c048472;
P_0c048472: /* original f729, guest PC 0x0c048472 */
if(!s->budget--) { s->failed_pc=0x0c048472u; return 0; }
vf3_matrix_load(s,ram,7,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c048474;
P_0c048474: /* original 7640, guest PC 0x0c048474 */
if(!s->budget--) { s->failed_pc=0x0c048474u; return 0; }
r[6]+=0x00000040u;
goto P_0c048476;
P_0c048476: /* original f7b2, guest PC 0x0c048476 */
if(!s->budget--) { s->failed_pc=0x0c048476u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c048478;
P_0c048478: /* original f3fd, guest PC 0x0c048478 */
if(!s->budget--) { s->failed_pc=0x0c048478u; return 0; }
r[18]^=0x100000u;
goto P_0c04847a;
P_0c04847a: /* original f66b, guest PC 0x0c04847a */
if(!s->budget--) { s->failed_pc=0x0c04847au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c04847c;
P_0c04847c: /* original f64b, guest PC 0x0c04847c */
if(!s->budget--) { s->failed_pc=0x0c04847cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c04847e;
P_0c04847e: /* original f62b, guest PC 0x0c04847e */
if(!s->budget--) { s->failed_pc=0x0c04847eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048480;
P_0c048480: /* original f60b, guest PC 0x0c048480 */
if(!s->budget--) { s->failed_pc=0x0c048480u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048482;
P_0c048482: /* original f3fd, guest PC 0x0c048482 */
if(!s->budget--) { s->failed_pc=0x0c048482u; return 0; }
r[18]^=0x100000u;
goto P_0c048484;
P_0c048484: /* original 76e0, guest PC 0x0c048484 */
if(!s->budget--) { s->failed_pc=0x0c048484u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c048486;
P_0c048486: /* original 4811, guest PC 0x0c048486 */
if(!s->budget--) { s->failed_pc=0x0c048486u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c048488;
P_0c048488: /* original 4d5a, guest PC 0x0c048488 */
if(!s->budget--) { s->failed_pc=0x0c048488u; return 0; }
r[53]=r[13];
goto P_0c04848a;
P_0c04848a: /* original 891b, guest PC 0x0c04848a */
if(!s->budget--) { s->failed_pc=0x0c04848au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484c4; }
goto P_0c04848c;
P_0c04848c: /* original 6083, guest PC 0x0c04848c */
if(!s->budget--) { s->failed_pc=0x0c04848cu; return 0; }
r[0]=r[8];
goto P_0c04848e;
P_0c04848e: /* original 88ff, guest PC 0x0c04848e */
if(!s->budget--) { s->failed_pc=0x0c04848eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c048490;
P_0c048490: /* original 8d14, guest PC 0x0c048490 */
if(!s->budget--) { s->failed_pc=0x0c048490u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
if(cond) { goto P_0c0484bc; }
goto P_0c048494;
P_0c048492: /* original 88fe, guest PC 0x0c048492 */
if(!s->budget--) { s->failed_pc=0x0c048492u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c048494;
P_0c048494: /* original 8b08, guest PC 0x0c048494 */
if(!s->budget--) { s->failed_pc=0x0c048494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484a8; }
goto P_0c048496;
P_0c048496: /* original d052, guest PC 0x0c048496 */
if(!s->budget--) { s->failed_pc=0x0c048496u; return 0; }
r[0]=read(ram,0x0c0485e0u,4);
goto P_0c048498;
P_0c048498: /* original 400b, guest PC 0x0c048498 */
if(!s->budget--) { s->failed_pc=0x0c048498u; return 0; }
target=r[0];
r[16]=code_base|0x0c04849cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04849cu) { target=s->pc; goto dispatch; }
goto P_0c04849c;
P_0c04849a: /* original 0009, guest PC 0x0c04849a */
if(!s->budget--) { s->failed_pc=0x0c04849au; return 0; }
goto P_0c04849c;
P_0c04849c: /* original 896e, guest PC 0x0c04849c */
if(!s->budget--) { s->failed_pc=0x0c04849cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c04849e;
P_0c04849e: /* original 6146, guest PC 0x0c04849e */
if(!s->budget--) { s->failed_pc=0x0c04849eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484a0;
P_0c0484a0: /* original f249, guest PC 0x0c0484a0 */
if(!s->budget--) { s->failed_pc=0x0c0484a0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484a2;
P_0c0484a2: /* original af25, guest PC 0x0c0484a2 */
if(!s->budget--) { s->failed_pc=0x0c0484a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484a4: /* original f349, guest PC 0x0c0484a4 */
if(!s->budget--) { s->failed_pc=0x0c0484a4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484a6u,s,ram);
P_0c0484a8: /* original 88fd, guest PC 0x0c0484a8 */
if(!s->budget--) { s->failed_pc=0x0c0484a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffdu)!=0);
goto P_0c0484aa;
P_0c0484aa: /* original 8b07, guest PC 0x0c0484aa */
if(!s->budget--) { s->failed_pc=0x0c0484aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0484bc; }
goto P_0c0484ac;
P_0c0484ac: /* original d04d, guest PC 0x0c0484ac */
if(!s->budget--) { s->failed_pc=0x0c0484acu; return 0; }
r[0]=read(ram,0x0c0485e4u,4);
goto P_0c0484ae;
P_0c0484ae: /* original 400b, guest PC 0x0c0484ae */
if(!s->budget--) { s->failed_pc=0x0c0484aeu; return 0; }
target=r[0];
r[16]=code_base|0x0c0484b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0484b2u) { target=s->pc; goto dispatch; }
goto P_0c0484b2;
P_0c0484b0: /* original 0009, guest PC 0x0c0484b0 */
if(!s->budget--) { s->failed_pc=0x0c0484b0u; return 0; }
goto P_0c0484b2;
P_0c0484b2: /* original 8963, guest PC 0x0c0484b2 */
if(!s->budget--) { s->failed_pc=0x0c0484b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484b4;
P_0c0484b4: /* original 6146, guest PC 0x0c0484b4 */
if(!s->budget--) { s->failed_pc=0x0c0484b4u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484b6;
P_0c0484b6: /* original f249, guest PC 0x0c0484b6 */
if(!s->budget--) { s->failed_pc=0x0c0484b6u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484b8;
P_0c0484b8: /* original af1a, guest PC 0x0c0484b8 */
if(!s->budget--) { s->failed_pc=0x0c0484b8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484ba: /* original f349, guest PC 0x0c0484ba */
if(!s->budget--) { s->failed_pc=0x0c0484bau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484bc;
P_0c0484bc: /* original e800, guest PC 0x0c0484bc */
if(!s->budget--) { s->failed_pc=0x0c0484bcu; return 0; }
r[8]=0x00000000u;
goto P_0c0484be;
P_0c0484be: /* original a00b, guest PC 0x0c0484be */
if(!s->budget--) { s->failed_pc=0x0c0484beu; return 0; }
fr[15]=0x3f800000u;
goto P_0c0484d8;
P_0c0484c0: /* original ff9d, guest PC 0x0c0484c0 */
if(!s->budget--) { s->failed_pc=0x0c0484c0u; return 0; }
fr[15]=0x3f800000u;
return vf3_matrix_family(0x0c0484c2u,s,ram);
P_0c0484c4: /* original 3817, guest PC 0x0c0484c4 */
if(!s->budget--) { s->failed_pc=0x0c0484c4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>(int32_t)r[1])!=0);
goto P_0c0484c6;
P_0c0484c6: /* original f10d, guest PC 0x0c0484c6 */
if(!s->budget--) { s->failed_pc=0x0c0484c6u; return 0; }
fr[1]=r[53];
goto P_0c0484c8;
P_0c0484c8: /* original 4808, guest PC 0x0c0484c8 */
if(!s->budget--) { s->failed_pc=0x0c0484c8u; return 0; }
r[8]<<=2;
goto P_0c0484ca;
P_0c0484ca: /* original 8f05, guest PC 0x0c0484ca */
if(!s->budget--) { s->failed_pc=0x0c0484cau; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
if(!cond) { goto P_0c0484d8; }
goto P_0c0484ce;
P_0c0484cc: /* original ff12, guest PC 0x0c0484cc */
if(!s->budget--) { s->failed_pc=0x0c0484ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'*');
goto P_0c0484ce;
P_0c0484ce: /* original 6083, guest PC 0x0c0484ce */
if(!s->budget--) { s->failed_pc=0x0c0484ceu; return 0; }
r[0]=r[8];
goto P_0c0484d0;
P_0c0484d0: /* original 8840, guest PC 0x0c0484d0 */
if(!s->budget--) { s->failed_pc=0x0c0484d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c0484d2;
P_0c0484d2: /* original e824, guest PC 0x0c0484d2 */
if(!s->budget--) { s->failed_pc=0x0c0484d2u; return 0; }
r[8]=0x00000024u;
goto P_0c0484d4;
P_0c0484d4: /* original 8900, guest PC 0x0c0484d4 */
if(!s->budget--) { s->failed_pc=0x0c0484d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0484d8; }
goto P_0c0484d6;
P_0c0484d6: /* original e828, guest PC 0x0c0484d6 */
if(!s->budget--) { s->failed_pc=0x0c0484d6u; return 0; }
r[8]=0x00000028u;
goto P_0c0484d8;
P_0c0484d8: /* original 6046, guest PC 0x0c0484d8 */
if(!s->budget--) { s->failed_pc=0x0c0484d8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0484da: /* original 4015, guest PC 0x0c0484da */
if(!s->budget--) { s->failed_pc=0x0c0484dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0484dc;
P_0c0484dc: /* original 59f9, guest PC 0x0c0484dc */
if(!s->budget--) { s->failed_pc=0x0c0484dcu; return 0; }
r[9]=read(ram,r[15]+36,4);
goto P_0c0484de;
P_0c0484de: /* original 8d09, guest PC 0x0c0484de */
if(!s->budget--) { s->failed_pc=0x0c0484deu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
if(cond) { goto P_0c0484f4; }
goto P_0c0484e2;
P_0c0484e0: /* original 4011, guest PC 0x0c0484e0 */
if(!s->budget--) { s->failed_pc=0x0c0484e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0484e2;
P_0c0484e2: /* original 6803, guest PC 0x0c0484e2 */
if(!s->budget--) { s->failed_pc=0x0c0484e2u; return 0; }
r[8]=r[0];
goto P_0c0484e4;
P_0c0484e4: /* original 60b3, guest PC 0x0c0484e4 */
if(!s->budget--) { s->failed_pc=0x0c0484e4u; return 0; }
r[0]=r[11];
goto P_0c0484e6;
P_0c0484e6: /* original 0a56, guest PC 0x0c0484e6 */
if(!s->budget--) { s->failed_pc=0x0c0484e6u; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c0484e8;
P_0c0484e8: /* original 8948, guest PC 0x0c0484e8 */
if(!s->budget--) { s->failed_pc=0x0c0484e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04857c; }
goto P_0c0484ea;
P_0c0484ea: /* original 6146, guest PC 0x0c0484ea */
if(!s->budget--) { s->failed_pc=0x0c0484eau; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c0484ec;
P_0c0484ec: /* original f249, guest PC 0x0c0484ec */
if(!s->budget--) { s->failed_pc=0x0c0484ecu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0484ee;
P_0c0484ee: /* original aeff, guest PC 0x0c0484ee */
if(!s->budget--) { s->failed_pc=0x0c0484eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0482f0;
P_0c0484f0: /* original f349, guest PC 0x0c0484f0 */
if(!s->budget--) { s->failed_pc=0x0c0484f0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0484f2u,s,ram);
P_0c0484f4: /* original 6103, guest PC 0x0c0484f4 */
if(!s->budget--) { s->failed_pc=0x0c0484f4u; return 0; }
r[1]=r[0];
goto P_0c0484f6;
P_0c0484f6: /* original e2fb, guest PC 0x0c0484f6 */
if(!s->budget--) { s->failed_pc=0x0c0484f6u; return 0; }
r[2]=0xfffffffbu;
goto P_0c0484f8;
P_0c0484f8: /* original 6396, guest PC 0x0c0484f8 */
if(!s->budget--) { s->failed_pc=0x0c0484f8u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[3]=tmp;
goto P_0c0484fa;
P_0c0484fa: /* original c940, guest PC 0x0c0484fa */
if(!s->budget--) { s->failed_pc=0x0c0484fau; return 0; }
r[0]&=64u;
goto P_0c0484fc;
P_0c0484fc: /* original 402d, guest PC 0x0c0484fc */
if(!s->budget--) { s->failed_pc=0x0c0484fcu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c0484fe;
P_0c0484fe: /* original e2fd, guest PC 0x0c0484fe */
if(!s->budget--) { s->failed_pc=0x0c0484feu; return 0; }
r[2]=0xfffffffdu;
goto P_0c048500;
P_0c048500: /* original 2329, guest PC 0x0c048500 */
if(!s->budget--) { s->failed_pc=0x0c048500u; return 0; }
r[3]&=r[2];
goto P_0c048502;
P_0c048502: /* original 203b, guest PC 0x0c048502 */
if(!s->budget--) { s->failed_pc=0x0c048502u; return 0; }
r[0]|=r[3];
goto P_0c048504;
P_0c048504: /* original c810, guest PC 0x0c048504 */
if(!s->budget--) { s->failed_pc=0x0c048504u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c048506;
P_0c048506: /* original 7420, guest PC 0x0c048506 */
if(!s->budget--) { s->failed_pc=0x0c048506u; return 0; }
r[4]+=0x00000020u;
goto P_0c048508;
P_0c048508: /* original 8f03, guest PC 0x0c048508 */
if(!s->budget--) { s->failed_pc=0x0c048508u; return 0; }
cond=r[17]&1u;
r[53]=r[0];
if(!cond) { goto P_0c048512; }
goto P_0c04850c;
P_0c04850a: /* original 405a, guest PC 0x0c04850a */
if(!s->budget--) { s->failed_pc=0x0c04850au; return 0; }
r[53]=r[0];
goto P_0c04850c;
P_0c04850c: /* original cb10, guest PC 0x0c04850c */
if(!s->budget--) { s->failed_pc=0x0c04850cu; return 0; }
r[0]|=16u;
goto P_0c04850e;
P_0c04850e: /* original 6293, guest PC 0x0c04850e */
if(!s->budget--) { s->failed_pc=0x0c04850eu; return 0; }
r[2]=r[9];
goto P_0c048510;
P_0c048510: /* original 2206, guest PC 0x0c048510 */
if(!s->budget--) { s->failed_pc=0x0c048510u; return 0; }
tmp=r[0]; r[2]-=4; write(ram,r[2],tmp,4);
goto P_0c048512;
P_0c048512: /* original 6013, guest PC 0x0c048512 */
if(!s->budget--) { s->failed_pc=0x0c048512u; return 0; }
r[0]=r[1];
goto P_0c048514;
P_0c048514: /* original e21b, guest PC 0x0c048514 */
if(!s->budget--) { s->failed_pc=0x0c048514u; return 0; }
r[2]=0x0000001bu;
goto P_0c048516;
P_0c048516: /* original c903, guest PC 0x0c048516 */
if(!s->budget--) { s->failed_pc=0x0c048516u; return 0; }
r[0]&=3u;
goto P_0c048518;
P_0c048518: /* original 402d, guest PC 0x0c048518 */
if(!s->budget--) { s->failed_pc=0x0c048518u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c04851a;
P_0c04851a: /* original e303, guest PC 0x0c04851a */
if(!s->budget--) { s->failed_pc=0x0c04851au; return 0; }
r[3]=0x00000003u;
goto P_0c04851c;
P_0c04851c: /* original f3fd, guest PC 0x0c04851c */
if(!s->budget--) { s->failed_pc=0x0c04851cu; return 0; }
r[18]^=0x100000u;
goto P_0c04851e;
P_0c04851e: /* original 432d, guest PC 0x0c04851e */
if(!s->budget--) { s->failed_pc=0x0c04851eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c048520;
P_0c048520: /* original 0483, guest PC 0x0c048520 */
if(!s->budget--) { s->failed_pc=0x0c048520u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c048522;
P_0c048522: /* original 6337, guest PC 0x0c048522 */
if(!s->budget--) { s->failed_pc=0x0c048522u; return 0; }
r[3]=~r[3];
goto P_0c048524;
P_0c048524: /* original 6296, guest PC 0x0c048524 */
if(!s->budget--) { s->failed_pc=0x0c048524u; return 0; }
tmp=read(ram,r[9],4);
r[9]+=4;
r[2]=tmp;
goto P_0c048526;
P_0c048526: /* original 2239, guest PC 0x0c048526 */
if(!s->budget--) { s->failed_pc=0x0c048526u; return 0; }
r[2]&=r[3];
goto P_0c048528;
P_0c048528: /* original f00d, guest PC 0x0c048528 */
if(!s->budget--) { s->failed_pc=0x0c048528u; return 0; }
fr[0]=r[53];
goto P_0c04852a;
P_0c04852a: /* original 220b, guest PC 0x0c04852a */
if(!s->budget--) { s->failed_pc=0x0c04852au; return 0; }
r[2]|=r[0];
goto P_0c04852c;
P_0c04852c: /* original 425a, guest PC 0x0c04852c */
if(!s->budget--) { s->failed_pc=0x0c04852cu; return 0; }
r[53]=r[2];
goto P_0c04852e;
P_0c04852e: /* original 74e0, guest PC 0x0c04852e */
if(!s->budget--) { s->failed_pc=0x0c04852eu; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048530;
P_0c048530: /* original f10d, guest PC 0x0c048530 */
if(!s->budget--) { s->failed_pc=0x0c048530u; return 0; }
fr[1]=r[53];
goto P_0c048532;
P_0c048532: /* original 7610, guest PC 0x0c048532 */
if(!s->budget--) { s->failed_pc=0x0c048532u; return 0; }
r[6]+=0x00000010u;
goto P_0c048534;
P_0c048534: /* original f299, guest PC 0x0c048534 */
if(!s->budget--) { s->failed_pc=0x0c048534u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c048536;
P_0c048536: /* original f62b, guest PC 0x0c048536 */
if(!s->budget--) { s->failed_pc=0x0c048536u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c048538;
P_0c048538: /* original 7520, guest PC 0x0c048538 */
if(!s->budget--) { s->failed_pc=0x0c048538u; return 0; }
r[5]+=0x00000020u;
goto P_0c04853a;
P_0c04853a: /* original f60b, guest PC 0x0c04853a */
if(!s->budget--) { s->failed_pc=0x0c04853au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04853c;
P_0c04853c: /* original f3fd, guest PC 0x0c04853c */
if(!s->budget--) { s->failed_pc=0x0c04853cu; return 0; }
r[18]^=0x100000u;
goto P_0c04853e;
P_0c04853e: /* original 0683, guest PC 0x0c04853e */
if(!s->budget--) { s->failed_pc=0x0c04853eu; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c048540;
P_0c048540: /* original 8f03, guest PC 0x0c048540 */
if(!s->budget--) { s->failed_pc=0x0c048540u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c04854a; }
goto P_0c048544;
P_0c048542: /* original 7620, guest PC 0x0c048542 */
if(!s->budget--) { s->failed_pc=0x0c048542u; return 0; }
r[6]+=0x00000020u;
goto P_0c048544;
P_0c048544: /* original 0683, guest PC 0x0c048544 */
if(!s->budget--) { s->failed_pc=0x0c048544u; return 0; }
if((r[6]&0xFC000000u)==0xE0000000u) pref(ram,r[6]);
goto P_0c048546;
P_0c048546: /* original 7620, guest PC 0x0c048546 */
if(!s->budget--) { s->failed_pc=0x0c048546u; return 0; }
r[6]+=0x00000020u;
goto P_0c048548;
P_0c048548: /* original 7520, guest PC 0x0c048548 */
if(!s->budget--) { s->failed_pc=0x0c048548u; return 0; }
r[5]+=0x00000020u;
goto P_0c04854a;
P_0c04854a: /* original 4c25, guest PC 0x0c04854a */
if(!s->budget--) { s->failed_pc=0x0c04854au; return 0; }
tmp=r[12]&1u; r[12]=(r[12]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c04854c;
P_0c04854c: /* original 6013, guest PC 0x0c04854c */
if(!s->budget--) { s->failed_pc=0x0c04854cu; return 0; }
r[0]=r[1];
goto P_0c04854e;
P_0c04854e: /* original 8d25, guest PC 0x0c04854e */
if(!s->budget--) { s->failed_pc=0x0c04854eu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
if(cond) { goto P_0c04859c; }
goto P_0c048552;
P_0c048550: /* original 4c00, guest PC 0x0c048550 */
if(!s->budget--) { s->failed_pc=0x0c048550u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c048552;
P_0c048552: /* original c808, guest PC 0x0c048552 */
if(!s->budget--) { s->failed_pc=0x0c048552u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c048554;
P_0c048554: /* original 8f0e, guest PC 0x0c048554 */
if(!s->budget--) { s->failed_pc=0x0c048554u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
if(!cond) { goto P_0c048574; }
goto P_0c048558;
P_0c048556: /* original c804, guest PC 0x0c048556 */
if(!s->budget--) { s->failed_pc=0x0c048556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c048558;
P_0c048558: /* original 8b08, guest PC 0x0c048558 */
if(!s->budget--) { s->failed_pc=0x0c048558u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04856c; }
goto P_0c04855a;
P_0c04855a: /* original b121, guest PC 0x0c04855a */
if(!s->budget--) { s->failed_pc=0x0c04855au; return 0; }
target=0x0c0487a0u; r[16]=code_base|0x0c04855eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04855eu) { target=s->pc; goto dispatch; }
goto P_0c04855e;
P_0c04855c: /* original 0009, guest PC 0x0c04855c */
if(!s->budget--) { s->failed_pc=0x0c04855cu; return 0; }
goto P_0c04855e;
P_0c04855e: /* original afbc, guest PC 0x0c04855e */
if(!s->budget--) { s->failed_pc=0x0c04855eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048560: /* original 6046, guest PC 0x0c048560 */
if(!s->budget--) { s->failed_pc=0x0c048560u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c048562u,s,ram);
P_0c04856c: /* original b048, guest PC 0x0c04856c */
if(!s->budget--) { s->failed_pc=0x0c04856cu; return 0; }
target=0x0c048600u; r[16]=code_base|0x0c048570u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048570u) { target=s->pc; goto dispatch; }
goto P_0c048570;
P_0c04856e: /* original 0009, guest PC 0x0c04856e */
if(!s->budget--) { s->failed_pc=0x0c04856eu; return 0; }
goto P_0c048570;
P_0c048570: /* original afb3, guest PC 0x0c048570 */
if(!s->budget--) { s->failed_pc=0x0c048570u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c048572: /* original 6046, guest PC 0x0c048572 */
if(!s->budget--) { s->failed_pc=0x0c048572u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c048574;
P_0c048574: /* original b4f4, guest PC 0x0c048574 */
if(!s->budget--) { s->failed_pc=0x0c048574u; return 0; }
target=0x0c048f60u; r[16]=code_base|0x0c048578u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c048578u) { target=s->pc; goto dispatch; }
goto P_0c048578;
P_0c048576: /* original 0009, guest PC 0x0c048576 */
if(!s->budget--) { s->failed_pc=0x0c048576u; return 0; }
goto P_0c048578;
P_0c048578: /* original afaf, guest PC 0x0c048578 */
if(!s->budget--) { s->failed_pc=0x0c048578u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c04857a: /* original 6046, guest PC 0x0c04857a */
if(!s->budget--) { s->failed_pc=0x0c04857au; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c04857c;
P_0c04857c: /* original 7f28, guest PC 0x0c04857c */
if(!s->budget--) { s->failed_pc=0x0c04857cu; return 0; }
r[15]+=0x00000028u;
goto P_0c04857e;
P_0c04857e: /* original 4f26, guest PC 0x0c04857e */
if(!s->budget--) { s->failed_pc=0x0c04857eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c048580;
P_0c048580: /* original 68f6, guest PC 0x0c048580 */
if(!s->budget--) { s->failed_pc=0x0c048580u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c048582;
P_0c048582: /* original 69f6, guest PC 0x0c048582 */
if(!s->budget--) { s->failed_pc=0x0c048582u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c048584;
P_0c048584: /* original 6af6, guest PC 0x0c048584 */
if(!s->budget--) { s->failed_pc=0x0c048584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c048586;
P_0c048586: /* original 6bf6, guest PC 0x0c048586 */
if(!s->budget--) { s->failed_pc=0x0c048586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c048588;
P_0c048588: /* original 6cf6, guest PC 0x0c048588 */
if(!s->budget--) { s->failed_pc=0x0c048588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04858a;
P_0c04858a: /* original 6df6, guest PC 0x0c04858a */
if(!s->budget--) { s->failed_pc=0x0c04858au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04858c;
P_0c04858c: /* original 6ef6, guest PC 0x0c04858c */
if(!s->budget--) { s->failed_pc=0x0c04858cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04858e;
P_0c04858e: /* original fcf9, guest PC 0x0c04858e */
if(!s->budget--) { s->failed_pc=0x0c04858eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048590;
P_0c048590: /* original fdf9, guest PC 0x0c048590 */
if(!s->budget--) { s->failed_pc=0x0c048590u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048592;
P_0c048592: /* original fef9, guest PC 0x0c048592 */
if(!s->budget--) { s->failed_pc=0x0c048592u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048594;
P_0c048594: /* original fff9, guest PC 0x0c048594 */
if(!s->budget--) { s->failed_pc=0x0c048594u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c048596;
P_0c048596: /* original 000b, guest PC 0x0c048596 */
if(!s->budget--) { s->failed_pc=0x0c048596u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c048598: /* original 0009, guest PC 0x0c048598 */
if(!s->budget--) { s->failed_pc=0x0c048598u; return 0; }
return vf3_matrix_family(0x0c04859au,s,ram);
P_0c04859c: /* original e100, guest PC 0x0c04859c */
if(!s->budget--) { s->failed_pc=0x0c04859cu; return 0; }
r[1]=0x00000000u;
goto P_0c04859e;
P_0c04859e: /* original c840, guest PC 0x0c04859e */
if(!s->budget--) { s->failed_pc=0x0c04859eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0485a0;
P_0c0485a0: /* original 3c1e, guest PC 0x0c0485a0 */
if(!s->budget--) { s->failed_pc=0x0c0485a0u; return 0; }
wide=(uint64_t)r[12]+r[1]+(r[17]&1u); r[12]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0485a2;
P_0c0485a2: /* original c810, guest PC 0x0c0485a2 */
if(!s->budget--) { s->failed_pc=0x0c0485a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0485a4;
P_0c0485a4: /* original 8d04, guest PC 0x0c0485a4 */
if(!s->budget--) { s->failed_pc=0x0c0485a4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
if(cond) { goto P_0c0485b0; }
goto P_0c0485a8;
P_0c0485a6: /* original c808, guest PC 0x0c0485a6 */
if(!s->budget--) { s->failed_pc=0x0c0485a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0485a8;
P_0c0485a8: /* original b19a, guest PC 0x0c0485a8 */
if(!s->budget--) { s->failed_pc=0x0c0485a8u; return 0; }
target=0x0c0488e0u; r[16]=code_base|0x0c0485acu;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485acu) { target=s->pc; goto dispatch; }
goto P_0c0485ac;
P_0c0485aa: /* original c820, guest PC 0x0c0485aa */
if(!s->budget--) { s->failed_pc=0x0c0485aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485ac;
P_0c0485ac: /* original af95, guest PC 0x0c0485ac */
if(!s->budget--) { s->failed_pc=0x0c0485acu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485ae: /* original 6046, guest PC 0x0c0485ae */
if(!s->budget--) { s->failed_pc=0x0c0485aeu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0485b0;
P_0c0485b0: /* original 8904, guest PC 0x0c0485b0 */
if(!s->budget--) { s->failed_pc=0x0c0485b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0485bc; }
goto P_0c0485b2;
P_0c0485b2: /* original b3d5, guest PC 0x0c0485b2 */
if(!s->budget--) { s->failed_pc=0x0c0485b2u; return 0; }
target=0x0c048d60u; r[16]=code_base|0x0c0485b6u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0485b6u) { target=s->pc; goto dispatch; }
goto P_0c0485b6;
P_0c0485b4: /* original c820, guest PC 0x0c0485b4 */
if(!s->budget--) { s->failed_pc=0x0c0485b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0485b6;
P_0c0485b6: /* original af90, guest PC 0x0c0485b6 */
if(!s->budget--) { s->failed_pc=0x0c0485b6u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0484da;
P_0c0485b8: /* original 6046, guest PC 0x0c0485b8 */
if(!s->budget--) { s->failed_pc=0x0c0485b8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
return vf3_matrix_family(0x0c0485bau,s,ram);
P_0c0485bc: /* original affe, guest PC 0x0c0485bc */
if(!s->budget--) { s->failed_pc=0x0c0485bcu; return 0; }
goto P_0c0485bc;
P_0c0485be: /* original 0009, guest PC 0x0c0485be */
if(!s->budget--) { s->failed_pc=0x0c0485beu; return 0; }
return vf3_matrix_family(0x0c0485c0u,s,ram);
P_0c04c024: /* original 4f22, guest PC 0x0c04c024 */
if(!s->budget--) { s->failed_pc=0x0c04c024u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c026;
P_0c04c026: /* original d32c, guest PC 0x0c04c026 */
if(!s->budget--) { s->failed_pc=0x0c04c026u; return 0; }
r[3]=read(ram,0x0c04c0d8u,4);
goto P_0c04c028;
P_0c04c028: /* original 4f12, guest PC 0x0c04c028 */
if(!s->budget--) { s->failed_pc=0x0c04c028u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c02a;
P_0c04c02a: /* original 6932, guest PC 0x0c04c02a */
if(!s->budget--) { s->failed_pc=0x0c04c02au; return 0; }
tmp=read(ram,r[3],4);
r[9]=tmp;
goto P_0c04c02c;
P_0c04c02c: /* original 7ffc, guest PC 0x0c04c02c */
if(!s->budget--) { s->failed_pc=0x0c04c02cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c02e;
P_0c04c02e: /* original 2f66, guest PC 0x0c04c02e */
if(!s->budget--) { s->failed_pc=0x0c04c02eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c030;
P_0c04c030: /* original 2fa6, guest PC 0x0c04c030 */
if(!s->budget--) { s->failed_pc=0x0c04c030u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c032;
P_0c04c032: /* original 2fe6, guest PC 0x0c04c032 */
if(!s->budget--) { s->failed_pc=0x0c04c032u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c034;
P_0c04c034: /* original d12a, guest PC 0x0c04c034 */
if(!s->budget--) { s->failed_pc=0x0c04c034u; return 0; }
r[1]=read(ram,0x0c04c0e0u,4);
goto P_0c04c036;
P_0c04c036: /* original d229, guest PC 0x0c04c036 */
if(!s->budget--) { s->failed_pc=0x0c04c036u; return 0; }
r[2]=read(ram,0x0c04c0dcu,4);
goto P_0c04c038;
P_0c04c038: /* original 410b, guest PC 0x0c04c038 */
if(!s->budget--) { s->failed_pc=0x0c04c038u; return 0; }
target=r[1];
r[16]=code_base|0x0c04c03cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04c03cu) { target=s->pc; goto dispatch; }
goto P_0c04c03c;
P_0c04c03a: /* original 2f26, guest PC 0x0c04c03a */
if(!s->budget--) { s->failed_pc=0x0c04c03au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c03c;
P_0c04c03c: /* original 9d49, guest PC 0x0c04c03c */
if(!s->budget--) { s->failed_pc=0x0c04c03cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d2u,2);
goto P_0c04c03e;
P_0c04c03e: /* original 7f10, guest PC 0x0c04c03e */
if(!s->budget--) { s->failed_pc=0x0c04c03eu; return 0; }
r[15]+=0x00000010u;
goto P_0c04c040;
P_0c04c040: /* original 0ed7, guest PC 0x0c04c040 */
if(!s->budget--) { s->failed_pc=0x0c04c040u; return 0; }
r[19]=r[14]*r[13];
goto P_0c04c042;
P_0c04c042: /* original 0d1a, guest PC 0x0c04c042 */
if(!s->budget--) { s->failed_pc=0x0c04c042u; return 0; }
r[13]=r[19];
goto P_0c04c044;
P_0c04c044: /* original 2fd2, guest PC 0x0c04c044 */
if(!s->budget--) { s->failed_pc=0x0c04c044u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04c046;
P_0c04c046: /* original d327, guest PC 0x0c04c046 */
if(!s->budget--) { s->failed_pc=0x0c04c046u; return 0; }
r[3]=read(ram,0x0c04c0e4u,4);
goto P_0c04c048;
P_0c04c048: /* original d827, guest PC 0x0c04c048 */
if(!s->budget--) { s->failed_pc=0x0c04c048u; return 0; }
r[8]=read(ram,0x0c04c0e8u,4);
goto P_0c04c04a;
P_0c04c04a: /* original 3d3c, guest PC 0x0c04c04a */
if(!s->budget--) { s->failed_pc=0x0c04c04au; return 0; }
r[13]+=r[3];
goto P_0c04c04c;
P_0c04c04c: /* original 65a3, guest PC 0x0c04c04c */
if(!s->budget--) { s->failed_pc=0x0c04c04cu; return 0; }
r[5]=r[10];
goto P_0c04c04e;
P_0c04c04e: /* original 66b3, guest PC 0x0c04c04e */
if(!s->budget--) { s->failed_pc=0x0c04c04eu; return 0; }
r[6]=r[11];
goto P_0c04c050;
P_0c04c050: /* original 480b, guest PC 0x0c04c050 */
if(!s->budget--) { s->failed_pc=0x0c04c050u; return 0; }
target=r[8];
r[16]=code_base|0x0c04c054u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04c054u) { target=s->pc; goto dispatch; }
goto P_0c04c054;
P_0c04c052: /* original 64e3, guest PC 0x0c04c052 */
if(!s->budget--) { s->failed_pc=0x0c04c052u; return 0; }
r[4]=r[14];
goto P_0c04c054;
P_0c04c054: /* original 6c03, guest PC 0x0c04c054 */
if(!s->budget--) { s->failed_pc=0x0c04c054u; return 0; }
r[12]=r[0];
goto P_0c04c056;
P_0c04c056: /* original 2cc8, guest PC 0x0c04c056 */
if(!s->budget--) { s->failed_pc=0x0c04c056u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04c058;
P_0c04c058: /* original 8909, guest PC 0x0c04c058 */
if(!s->budget--) { s->failed_pc=0x0c04c058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c06e; }
goto P_0c04c05a;
P_0c04c05a: /* original 52dd, guest PC 0x0c04c05a */
if(!s->budget--) { s->failed_pc=0x0c04c05au; return 0; }
r[2]=read(ram,r[13]+52,4);
goto P_0c04c05c;
P_0c04c05c: /* original 2998, guest PC 0x0c04c05c */
if(!s->budget--) { s->failed_pc=0x0c04c05cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c04c05e;
P_0c04c05e: /* original 7201, guest PC 0x0c04c05e */
if(!s->budget--) { s->failed_pc=0x0c04c05eu; return 0; }
r[2]+=0x00000001u;
goto P_0c04c060;
P_0c04c060: /* original 1d2d, guest PC 0x0c04c060 */
if(!s->budget--) { s->failed_pc=0x0c04c060u; return 0; }
write(ram,r[13]+52,r[2],4);
goto P_0c04c062;
P_0c04c062: /* original 8ff3, guest PC 0x0c04c062 */
if(!s->budget--) { s->failed_pc=0x0c04c062u; return 0; }
cond=r[17]&1u;
r[9]+=0xffffffffu;
if(!cond) { goto P_0c04c04c; }
goto P_0c04c066;
P_0c04c064: /* original 79ff, guest PC 0x0c04c064 */
if(!s->budget--) { s->failed_pc=0x0c04c064u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04c066;
P_0c04c066: /* original d11c, guest PC 0x0c04c066 */
if(!s->budget--) { s->failed_pc=0x0c04c066u; return 0; }
r[1]=read(ram,0x0c04c0d8u,4);
goto P_0c04c068;
P_0c04c068: /* original 6012, guest PC 0x0c04c068 */
if(!s->budget--) { s->failed_pc=0x0c04c068u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04c06a;
P_0c04c06a: /* original 88ff, guest PC 0x0c04c06a */
if(!s->budget--) { s->failed_pc=0x0c04c06au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04c06c;
P_0c04c06c: /* original 89ee, guest PC 0x0c04c06c */
if(!s->budget--) { s->failed_pc=0x0c04c06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c04c; }
goto P_0c04c06e;
P_0c04c06e: /* original 6df2, guest PC 0x0c04c06e */
if(!s->budget--) { s->failed_pc=0x0c04c06eu; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04c070;
P_0c04c070: /* original 62e3, guest PC 0x0c04c070 */
if(!s->budget--) { s->failed_pc=0x0c04c070u; return 0; }
r[2]=r[14];
goto P_0c04c072;
P_0c04c072: /* original d31c, guest PC 0x0c04c072 */
if(!s->budget--) { s->failed_pc=0x0c04c072u; return 0; }
r[3]=read(ram,0x0c04c0e4u,4);
goto P_0c04c074;
P_0c04c074: /* original 4208, guest PC 0x0c04c074 */
if(!s->budget--) { s->failed_pc=0x0c04c074u; return 0; }
r[2]<<=2;
goto P_0c04c076;
P_0c04c076: /* original 4208, guest PC 0x0c04c076 */
if(!s->budget--) { s->failed_pc=0x0c04c076u; return 0; }
r[2]<<=2;
goto P_0c04c078;
P_0c04c078: /* original d11c, guest PC 0x0c04c078 */
if(!s->budget--) { s->failed_pc=0x0c04c078u; return 0; }
r[1]=read(ram,0x0c04c0ecu,4);
goto P_0c04c07a;
P_0c04c07a: /* original 3d3c, guest PC 0x0c04c07a */
if(!s->budget--) { s->failed_pc=0x0c04c07au; return 0; }
r[13]+=r[3];
goto P_0c04c07c;
P_0c04c07c: /* original 4208, guest PC 0x0c04c07c */
if(!s->budget--) { s->failed_pc=0x0c04c07cu; return 0; }
r[2]<<=2;
goto P_0c04c07e;
P_0c04c07e: /* original 4200, guest PC 0x0c04c07e */
if(!s->budget--) { s->failed_pc=0x0c04c07eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04c080;
P_0c04c080: /* original 321c, guest PC 0x0c04c080 */
if(!s->budget--) { s->failed_pc=0x0c04c080u; return 0; }
r[2]+=r[1];
goto P_0c04c082;
P_0c04c082: /* original 2f22, guest PC 0x0c04c082 */
if(!s->budget--) { s->failed_pc=0x0c04c082u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04c084;
P_0c04c084: /* original 56dc, guest PC 0x0c04c084 */
if(!s->budget--) { s->failed_pc=0x0c04c084u; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04c086;
P_0c04c086: /* original 57dd, guest PC 0x0c04c086 */
if(!s->budget--) { s->failed_pc=0x0c04c086u; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04c088;
P_0c04c088: /* original 7601, guest PC 0x0c04c088 */
if(!s->budget--) { s->failed_pc=0x0c04c088u; return 0; }
r[6]+=0x00000001u;
goto P_0c04c08a;
P_0c04c08a: /* original 1d6c, guest PC 0x0c04c08a */
if(!s->budget--) { s->failed_pc=0x0c04c08au; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04c08c;
P_0c04c08c: /* original 76ff, guest PC 0x0c04c08c */
if(!s->budget--) { s->failed_pc=0x0c04c08cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c04c08e;
P_0c04c08e: /* original 65f2, guest PC 0x0c04c08e */
if(!s->budget--) { s->failed_pc=0x0c04c08eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04c090;
P_0c04c090: /* original d317, guest PC 0x0c04c090 */
if(!s->budget--) { s->failed_pc=0x0c04c090u; return 0; }
r[3]=read(ram,0x0c04c0f0u,4);
goto P_0c04c092;
P_0c04c092: /* original 5552, guest PC 0x0c04c092 */
if(!s->budget--) { s->failed_pc=0x0c04c092u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04c094;
P_0c04c094: /* original 430b, guest PC 0x0c04c094 */
if(!s->budget--) { s->failed_pc=0x0c04c094u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c098u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04c098u) { target=s->pc; goto dispatch; }
goto P_0c04c098;
P_0c04c096: /* original 64e3, guest PC 0x0c04c096 */
if(!s->budget--) { s->failed_pc=0x0c04c096u; return 0; }
r[4]=r[14];
goto P_0c04c098;
P_0c04c098: /* original 911c, guest PC 0x0c04c098 */
if(!s->budget--) { s->failed_pc=0x0c04c098u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d4u,2);
goto P_0c04c09a;
P_0c04c09a: /* original 60c3, guest PC 0x0c04c09a */
if(!s->budget--) { s->failed_pc=0x0c04c09au; return 0; }
r[0]=r[12];
goto P_0c04c09c;
P_0c04c09c: /* original 3010, guest PC 0x0c04c09c */
if(!s->budget--) { s->failed_pc=0x0c04c09cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04c09e;
P_0c04c09e: /* original 8906, guest PC 0x0c04c09e */
if(!s->budget--) { s->failed_pc=0x0c04c09eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c0ae; }
goto P_0c04c0a0;
P_0c04c0a0: /* original 9119, guest PC 0x0c04c0a0 */
if(!s->budget--) { s->failed_pc=0x0c04c0a0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d6u,2);
goto P_0c04c0a2;
P_0c04c0a2: /* original 3010, guest PC 0x0c04c0a2 */
if(!s->budget--) { s->failed_pc=0x0c04c0a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04c0a4;
P_0c04c0a4: /* original 8906, guest PC 0x0c04c0a4 */
if(!s->budget--) { s->failed_pc=0x0c04c0a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c0b4; }
goto P_0c04c0a6;
P_0c04c0a6: /* original 8800, guest PC 0x0c04c0a6 */
if(!s->budget--) { s->failed_pc=0x0c04c0a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04c0a8;
P_0c04c0a8: /* original 8b07, guest PC 0x0c04c0a8 */
if(!s->budget--) { s->failed_pc=0x0c04c0a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04c0ba; }
goto P_0c04c0aa;
P_0c04c0aa: /* original a007, guest PC 0x0c04c0aa */
if(!s->budget--) { s->failed_pc=0x0c04c0aau; return 0; }
r[0]=0x00000000u;
goto P_0c04c0bc;
P_0c04c0ac: /* original e000, guest PC 0x0c04c0ac */
if(!s->budget--) { s->failed_pc=0x0c04c0acu; return 0; }
r[0]=0x00000000u;
goto P_0c04c0ae;
P_0c04c0ae: /* original 9011, guest PC 0x0c04c0ae */
if(!s->budget--) { s->failed_pc=0x0c04c0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d4u,2);
goto P_0c04c0b0;
P_0c04c0b0: /* original a004, guest PC 0x0c04c0b0 */
if(!s->budget--) { s->failed_pc=0x0c04c0b0u; return 0; }
goto P_0c04c0bc;
P_0c04c0b2: /* original 0009, guest PC 0x0c04c0b2 */
if(!s->budget--) { s->failed_pc=0x0c04c0b2u; return 0; }
goto P_0c04c0b4;
P_0c04c0b4: /* original 900f, guest PC 0x0c04c0b4 */
if(!s->budget--) { s->failed_pc=0x0c04c0b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d6u,2);
goto P_0c04c0b6;
P_0c04c0b6: /* original a001, guest PC 0x0c04c0b6 */
if(!s->budget--) { s->failed_pc=0x0c04c0b6u; return 0; }
goto P_0c04c0bc;
P_0c04c0b8: /* original 0009, guest PC 0x0c04c0b8 */
if(!s->budget--) { s->failed_pc=0x0c04c0b8u; return 0; }
goto P_0c04c0ba;
P_0c04c0ba: /* original d00e, guest PC 0x0c04c0ba */
if(!s->budget--) { s->failed_pc=0x0c04c0bau; return 0; }
r[0]=read(ram,0x0c04c0f4u,4);
goto P_0c04c0bc;
P_0c04c0bc: /* original 7f04, guest PC 0x0c04c0bc */
if(!s->budget--) { s->failed_pc=0x0c04c0bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04c0be;
P_0c04c0be: /* original 4f16, guest PC 0x0c04c0be */
if(!s->budget--) { s->failed_pc=0x0c04c0beu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c0c0;
P_0c04c0c0: /* original 4f26, guest PC 0x0c04c0c0 */
if(!s->budget--) { s->failed_pc=0x0c04c0c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c0c2;
P_0c04c0c2: /* original 68f6, guest PC 0x0c04c0c2 */
if(!s->budget--) { s->failed_pc=0x0c04c0c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04c0c4;
P_0c04c0c4: /* original 69f6, guest PC 0x0c04c0c4 */
if(!s->budget--) { s->failed_pc=0x0c04c0c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04c0c6;
P_0c04c0c6: /* original 6af6, guest PC 0x0c04c0c6 */
if(!s->budget--) { s->failed_pc=0x0c04c0c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04c0c8;
P_0c04c0c8: /* original 6bf6, guest PC 0x0c04c0c8 */
if(!s->budget--) { s->failed_pc=0x0c04c0c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c0ca;
P_0c04c0ca: /* original 6cf6, guest PC 0x0c04c0ca */
if(!s->budget--) { s->failed_pc=0x0c04c0cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c0cc;
P_0c04c0cc: /* original 6df6, guest PC 0x0c04c0cc */
if(!s->budget--) { s->failed_pc=0x0c04c0ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c0ce;
P_0c04c0ce: /* original 000b, guest PC 0x0c04c0ce */
if(!s->budget--) { s->failed_pc=0x0c04c0ceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c0d0: /* original 6ef6, guest PC 0x0c04c0d0 */
if(!s->budget--) { s->failed_pc=0x0c04c0d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04c0d2u,s,ram);
P_0c04e03e: /* original 4f22, guest PC 0x0c04e03e */
if(!s->budget--) { s->failed_pc=0x0c04e03eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e040;
P_0c04e040: /* original d32b, guest PC 0x0c04e040 */
if(!s->budget--) { s->failed_pc=0x0c04e040u; return 0; }
r[3]=read(ram,0x0c04e0f0u,4);
goto P_0c04e042;
P_0c04e042: /* original d22c, guest PC 0x0c04e042 */
if(!s->budget--) { s->failed_pc=0x0c04e042u; return 0; }
r[2]=read(ram,0x0c04e0f4u,4);
goto P_0c04e044;
P_0c04e044: /* original 4f12, guest PC 0x0c04e044 */
if(!s->budget--) { s->failed_pc=0x0c04e044u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e046;
P_0c04e046: /* original 420b, guest PC 0x0c04e046 */
if(!s->budget--) { s->failed_pc=0x0c04e046u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e04au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e04au) { target=s->pc; goto dispatch; }
goto P_0c04e04a;
P_0c04e048: /* original 2f36, guest PC 0x0c04e048 */
if(!s->budget--) { s->failed_pc=0x0c04e048u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e04a;
P_0c04e04a: /* original d32b, guest PC 0x0c04e04a */
if(!s->budget--) { s->failed_pc=0x0c04e04au; return 0; }
r[3]=read(ram,0x0c04e0f8u,4);
goto P_0c04e04c;
P_0c04e04c: /* original 7f04, guest PC 0x0c04e04c */
if(!s->budget--) { s->failed_pc=0x0c04e04cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04e04e;
P_0c04e04e: /* original 430b, guest PC 0x0c04e04e */
if(!s->budget--) { s->failed_pc=0x0c04e04eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e052u;
r[4]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e052u) { target=s->pc; goto dispatch; }
goto P_0c04e052;
P_0c04e050: /* original 54da, guest PC 0x0c04e050 */
if(!s->budget--) { s->failed_pc=0x0c04e050u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e052;
P_0c04e052: /* original 2008, guest PC 0x0c04e052 */
if(!s->budget--) { s->failed_pc=0x0c04e052u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e054;
P_0c04e054: /* original 8b04, guest PC 0x0c04e054 */
if(!s->budget--) { s->failed_pc=0x0c04e054u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e060; }
goto P_0c04e056;
P_0c04e056: /* original d329, guest PC 0x0c04e056 */
if(!s->budget--) { s->failed_pc=0x0c04e056u; return 0; }
r[3]=read(ram,0x0c04e0fcu,4);
goto P_0c04e058;
P_0c04e058: /* original 430b, guest PC 0x0c04e058 */
if(!s->budget--) { s->failed_pc=0x0c04e058u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e05cu;
r[4]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e05cu) { target=s->pc; goto dispatch; }
goto P_0c04e05c;
P_0c04e05a: /* original 54da, guest PC 0x0c04e05a */
if(!s->budget--) { s->failed_pc=0x0c04e05au; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e05c;
P_0c04e05c: /* original a00e, guest PC 0x0c04e05c */
if(!s->budget--) { s->failed_pc=0x0c04e05cu; return 0; }
goto P_0c04e07c;
P_0c04e05e: /* original 0009, guest PC 0x0c04e05e */
if(!s->budget--) { s->failed_pc=0x0c04e05eu; return 0; }
goto P_0c04e060;
P_0c04e060: /* original d227, guest PC 0x0c04e060 */
if(!s->budget--) { s->failed_pc=0x0c04e060u; return 0; }
r[2]=read(ram,0x0c04e100u,4);
goto P_0c04e062;
P_0c04e062: /* original 420b, guest PC 0x0c04e062 */
if(!s->budget--) { s->failed_pc=0x0c04e062u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e066u;
r[4]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e066u) { target=s->pc; goto dispatch; }
goto P_0c04e066;
P_0c04e064: /* original 54da, guest PC 0x0c04e064 */
if(!s->budget--) { s->failed_pc=0x0c04e064u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e066;
P_0c04e066: /* original 2008, guest PC 0x0c04e066 */
if(!s->budget--) { s->failed_pc=0x0c04e066u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e068;
P_0c04e068: /* original 8908, guest PC 0x0c04e068 */
if(!s->budget--) { s->failed_pc=0x0c04e068u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e07c; }
goto P_0c04e06a;
P_0c04e06a: /* original 923d, guest PC 0x0c04e06a */
if(!s->budget--) { s->failed_pc=0x0c04e06au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0e8u,2);
goto P_0c04e06c;
P_0c04e06c: /* original 53da, guest PC 0x0c04e06c */
if(!s->budget--) { s->failed_pc=0x0c04e06cu; return 0; }
r[3]=read(ram,r[13]+40,4);
goto P_0c04e06e;
P_0c04e06e: /* original d025, guest PC 0x0c04e06e */
if(!s->budget--) { s->failed_pc=0x0c04e06eu; return 0; }
r[0]=read(ram,0x0c04e104u,4);
goto P_0c04e070;
P_0c04e070: /* original 232f, guest PC 0x0c04e070 */
if(!s->budget--) { s->failed_pc=0x0c04e070u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04e072;
P_0c04e072: /* original 031a, guest PC 0x0c04e072 */
if(!s->budget--) { s->failed_pc=0x0c04e072u; return 0; }
r[3]=r[19];
goto P_0c04e074;
P_0c04e074: /* original 633f, guest PC 0x0c04e074 */
if(!s->budget--) { s->failed_pc=0x0c04e074u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04e076;
P_0c04e076: /* original 013c, guest PC 0x0c04e076 */
if(!s->budget--) { s->failed_pc=0x0c04e076u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04e078;
P_0c04e078: /* original 2118, guest PC 0x0c04e078 */
if(!s->budget--) { s->failed_pc=0x0c04e078u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04e07a;
P_0c04e07a: /* original 8b02, guest PC 0x0c04e07a */
if(!s->budget--) { s->failed_pc=0x0c04e07au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e082; }
goto P_0c04e07c;
P_0c04e07c: /* original 9035, guest PC 0x0c04e07c */
if(!s->budget--) { s->failed_pc=0x0c04e07cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eau,2);
goto P_0c04e07e;
P_0c04e07e: /* original a06d, guest PC 0x0c04e07e */
if(!s->budget--) { s->failed_pc=0x0c04e07eu; return 0; }
goto P_0c04e15c;
P_0c04e080: /* original 0009, guest PC 0x0c04e080 */
if(!s->budget--) { s->failed_pc=0x0c04e080u; return 0; }
goto P_0c04e082;
P_0c04e082: /* original d321, guest PC 0x0c04e082 */
if(!s->budget--) { s->failed_pc=0x0c04e082u; return 0; }
r[3]=read(ram,0x0c04e108u,4);
goto P_0c04e084;
P_0c04e084: /* original 430b, guest PC 0x0c04e084 */
if(!s->budget--) { s->failed_pc=0x0c04e084u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e088u;
r[4]=read(ram,r[13]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e088u) { target=s->pc; goto dispatch; }
goto P_0c04e088;
P_0c04e086: /* original 54da, guest PC 0x0c04e086 */
if(!s->budget--) { s->failed_pc=0x0c04e086u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e088;
P_0c04e088: /* original 4011, guest PC 0x0c04e088 */
if(!s->budget--) { s->failed_pc=0x0c04e088u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e08a;
P_0c04e08a: /* original 8902, guest PC 0x0c04e08a */
if(!s->budget--) { s->failed_pc=0x0c04e08au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e092; }
goto P_0c04e08c;
P_0c04e08c: /* original 902e, guest PC 0x0c04e08c */
if(!s->budget--) { s->failed_pc=0x0c04e08cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0ecu,2);
goto P_0c04e08e;
P_0c04e08e: /* original a065, guest PC 0x0c04e08e */
if(!s->budget--) { s->failed_pc=0x0c04e08eu; return 0; }
goto P_0c04e15c;
P_0c04e090: /* original 0009, guest PC 0x0c04e090 */
if(!s->budget--) { s->failed_pc=0x0c04e090u; return 0; }
goto P_0c04e092;
P_0c04e092: /* original da1e, guest PC 0x0c04e092 */
if(!s->budget--) { s->failed_pc=0x0c04e092u; return 0; }
r[10]=read(ram,0x0c04e10cu,4);
goto P_0c04e094;
P_0c04e094: /* original d31e, guest PC 0x0c04e094 */
if(!s->budget--) { s->failed_pc=0x0c04e094u; return 0; }
r[3]=read(ram,0x0c04e110u,4);
goto P_0c04e096;
P_0c04e096: /* original 5cda, guest PC 0x0c04e096 */
if(!s->budget--) { s->failed_pc=0x0c04e096u; return 0; }
r[12]=read(ram,r[13]+40,4);
goto P_0c04e098;
P_0c04e098: /* original 65a3, guest PC 0x0c04e098 */
if(!s->budget--) { s->failed_pc=0x0c04e098u; return 0; }
r[5]=r[10];
goto P_0c04e09a;
P_0c04e09a: /* original 430b, guest PC 0x0c04e09a */
if(!s->budget--) { s->failed_pc=0x0c04e09au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e09eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e09eu) { target=s->pc; goto dispatch; }
goto P_0c04e09e;
P_0c04e09c: /* original 64c3, guest PC 0x0c04e09c */
if(!s->budget--) { s->failed_pc=0x0c04e09cu; return 0; }
r[4]=r[12];
goto P_0c04e09e;
P_0c04e09e: /* original 6e03, guest PC 0x0c04e09e */
if(!s->budget--) { s->failed_pc=0x0c04e09eu; return 0; }
r[14]=r[0];
goto P_0c04e0a0;
P_0c04e0a0: /* original 4e11, guest PC 0x0c04e0a0 */
if(!s->budget--) { s->failed_pc=0x0c04e0a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04e0a2;
P_0c04e0a2: /* original 8b1e, guest PC 0x0c04e0a2 */
if(!s->budget--) { s->failed_pc=0x0c04e0a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0e2; }
goto P_0c04e0a4;
P_0c04e0a4: /* original d91b, guest PC 0x0c04e0a4 */
if(!s->budget--) { s->failed_pc=0x0c04e0a4u; return 0; }
r[9]=read(ram,0x0c04e114u,4);
goto P_0c04e0a6;
P_0c04e0a6: /* original 65e3, guest PC 0x0c04e0a6 */
if(!s->budget--) { s->failed_pc=0x0c04e0a6u; return 0; }
r[5]=r[14];
goto P_0c04e0a8;
P_0c04e0a8: /* original 6683, guest PC 0x0c04e0a8 */
if(!s->budget--) { s->failed_pc=0x0c04e0a8u; return 0; }
r[6]=r[8];
goto P_0c04e0aa;
P_0c04e0aa: /* original 490b, guest PC 0x0c04e0aa */
if(!s->budget--) { s->failed_pc=0x0c04e0aau; return 0; }
target=r[9];
r[16]=code_base|0x0c04e0aeu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e0aeu) { target=s->pc; goto dispatch; }
goto P_0c04e0ae;
P_0c04e0ac: /* original 64c3, guest PC 0x0c04e0ac */
if(!s->budget--) { s->failed_pc=0x0c04e0acu; return 0; }
r[4]=r[12];
goto P_0c04e0ae;
P_0c04e0ae: /* original db1a, guest PC 0x0c04e0ae */
if(!s->budget--) { s->failed_pc=0x0c04e0aeu; return 0; }
r[11]=read(ram,0x0c04e118u,4);
goto P_0c04e0b0;
P_0c04e0b0: /* original 6403, guest PC 0x0c04e0b0 */
if(!s->budget--) { s->failed_pc=0x0c04e0b0u; return 0; }
r[4]=r[0];
goto P_0c04e0b2;
P_0c04e0b2: /* original 4411, guest PC 0x0c04e0b2 */
if(!s->budget--) { s->failed_pc=0x0c04e0b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04e0b4;
P_0c04e0b4: /* original 893d, guest PC 0x0c04e0b4 */
if(!s->budget--) { s->failed_pc=0x0c04e0b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e132; }
goto P_0c04e0b6;
P_0c04e0b6: /* original 9318, guest PC 0x0c04e0b6 */
if(!s->budget--) { s->failed_pc=0x0c04e0b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eau,2);
goto P_0c04e0b8;
P_0c04e0b8: /* original 3430, guest PC 0x0c04e0b8 */
if(!s->budget--) { s->failed_pc=0x0c04e0b8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c04e0ba;
P_0c04e0ba: /* original 8b01, guest PC 0x0c04e0ba */
if(!s->budget--) { s->failed_pc=0x0c04e0bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0c0; }
goto P_0c04e0bc;
P_0c04e0bc: /* original a04e, guest PC 0x0c04e0bc */
if(!s->budget--) { s->failed_pc=0x0c04e0bcu; return 0; }
r[0]=r[4];
goto P_0c04e15c;
P_0c04e0be: /* original 6043, guest PC 0x0c04e0be */
if(!s->budget--) { s->failed_pc=0x0c04e0beu; return 0; }
r[0]=r[4];
goto P_0c04e0c0;
P_0c04e0c0: /* original d20c, guest PC 0x0c04e0c0 */
if(!s->budget--) { s->failed_pc=0x0c04e0c0u; return 0; }
r[2]=read(ram,0x0c04e0f4u,4);
goto P_0c04e0c2;
P_0c04e0c2: /* original d316, guest PC 0x0c04e0c2 */
if(!s->budget--) { s->failed_pc=0x0c04e0c2u; return 0; }
r[3]=read(ram,0x0c04e11cu,4);
goto P_0c04e0c4;
P_0c04e0c4: /* original 420b, guest PC 0x0c04e0c4 */
if(!s->budget--) { s->failed_pc=0x0c04e0c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e0c8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e0c8u) { target=s->pc; goto dispatch; }
goto P_0c04e0c8;
P_0c04e0c6: /* original 2f36, guest PC 0x0c04e0c6 */
if(!s->budget--) { s->failed_pc=0x0c04e0c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e0c8;
P_0c04e0c8: /* original 7f04, guest PC 0x0c04e0c8 */
if(!s->budget--) { s->failed_pc=0x0c04e0c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e0ca;
P_0c04e0ca: /* original d315, guest PC 0x0c04e0ca */
if(!s->budget--) { s->failed_pc=0x0c04e0cau; return 0; }
r[3]=read(ram,0x0c04e120u,4);
goto P_0c04e0cc;
P_0c04e0cc: /* original 65e3, guest PC 0x0c04e0cc */
if(!s->budget--) { s->failed_pc=0x0c04e0ccu; return 0; }
r[5]=r[14];
goto P_0c04e0ce;
P_0c04e0ce: /* original 66b3, guest PC 0x0c04e0ce */
if(!s->budget--) { s->failed_pc=0x0c04e0ceu; return 0; }
r[6]=r[11];
goto P_0c04e0d0;
P_0c04e0d0: /* original 430b, guest PC 0x0c04e0d0 */
if(!s->budget--) { s->failed_pc=0x0c04e0d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e0d4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e0d4u) { target=s->pc; goto dispatch; }
goto P_0c04e0d4;
P_0c04e0d2: /* original 64c3, guest PC 0x0c04e0d2 */
if(!s->budget--) { s->failed_pc=0x0c04e0d2u; return 0; }
r[4]=r[12];
goto P_0c04e0d4;
P_0c04e0d4: /* original d20e, guest PC 0x0c04e0d4 */
if(!s->budget--) { s->failed_pc=0x0c04e0d4u; return 0; }
r[2]=read(ram,0x0c04e110u,4);
goto P_0c04e0d6;
P_0c04e0d6: /* original 65a3, guest PC 0x0c04e0d6 */
if(!s->budget--) { s->failed_pc=0x0c04e0d6u; return 0; }
r[5]=r[10];
goto P_0c04e0d8;
P_0c04e0d8: /* original 420b, guest PC 0x0c04e0d8 */
if(!s->budget--) { s->failed_pc=0x0c04e0d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e0dcu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e0dcu) { target=s->pc; goto dispatch; }
goto P_0c04e0dc;
P_0c04e0da: /* original 64c3, guest PC 0x0c04e0da */
if(!s->budget--) { s->failed_pc=0x0c04e0dau; return 0; }
r[4]=r[12];
goto P_0c04e0dc;
P_0c04e0dc: /* original 6e03, guest PC 0x0c04e0dc */
if(!s->budget--) { s->failed_pc=0x0c04e0dcu; return 0; }
r[14]=r[0];
goto P_0c04e0de;
P_0c04e0de: /* original 4e11, guest PC 0x0c04e0de */
if(!s->budget--) { s->failed_pc=0x0c04e0deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04e0e0;
P_0c04e0e0: /* original 8920, guest PC 0x0c04e0e0 */
if(!s->budget--) { s->failed_pc=0x0c04e0e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e124; }
goto P_0c04e0e2;
P_0c04e0e2: /* original 9004, guest PC 0x0c04e0e2 */
if(!s->budget--) { s->failed_pc=0x0c04e0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eeu,2);
goto P_0c04e0e4;
P_0c04e0e4: /* original a03a, guest PC 0x0c04e0e4 */
if(!s->budget--) { s->failed_pc=0x0c04e0e4u; return 0; }
goto P_0c04e15c;
P_0c04e0e6: /* original 0009, guest PC 0x0c04e0e6 */
if(!s->budget--) { s->failed_pc=0x0c04e0e6u; return 0; }
return vf3_matrix_family(0x0c04e0e8u,s,ram);
P_0c04e124: /* original 65e3, guest PC 0x0c04e124 */
if(!s->budget--) { s->failed_pc=0x0c04e124u; return 0; }
r[5]=r[14];
goto P_0c04e126;
P_0c04e126: /* original 6683, guest PC 0x0c04e126 */
if(!s->budget--) { s->failed_pc=0x0c04e126u; return 0; }
r[6]=r[8];
goto P_0c04e128;
P_0c04e128: /* original 490b, guest PC 0x0c04e128 */
if(!s->budget--) { s->failed_pc=0x0c04e128u; return 0; }
target=r[9];
r[16]=code_base|0x0c04e12cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e12cu) { target=s->pc; goto dispatch; }
goto P_0c04e12c;
P_0c04e12a: /* original 64c3, guest PC 0x0c04e12a */
if(!s->budget--) { s->failed_pc=0x0c04e12au; return 0; }
r[4]=r[12];
goto P_0c04e12c;
P_0c04e12c: /* original 6403, guest PC 0x0c04e12c */
if(!s->budget--) { s->failed_pc=0x0c04e12cu; return 0; }
r[4]=r[0];
goto P_0c04e12e;
P_0c04e12e: /* original 2448, guest PC 0x0c04e12e */
if(!s->budget--) { s->failed_pc=0x0c04e12eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04e130;
P_0c04e130: /* original 8bcb, guest PC 0x0c04e130 */
if(!s->budget--) { s->failed_pc=0x0c04e130u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0ca; }
goto P_0c04e132;
P_0c04e132: /* original d33d, guest PC 0x0c04e132 */
if(!s->budget--) { s->failed_pc=0x0c04e132u; return 0; }
r[3]=read(ram,0x0c04e228u,4);
goto P_0c04e134;
P_0c04e134: /* original 65e3, guest PC 0x0c04e134 */
if(!s->budget--) { s->failed_pc=0x0c04e134u; return 0; }
r[5]=r[14];
goto P_0c04e136;
P_0c04e136: /* original d63b, guest PC 0x0c04e136 */
if(!s->budget--) { s->failed_pc=0x0c04e136u; return 0; }
r[6]=read(ram,0x0c04e224u,4);
goto P_0c04e138;
P_0c04e138: /* original 430b, guest PC 0x0c04e138 */
if(!s->budget--) { s->failed_pc=0x0c04e138u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e13cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e13cu) { target=s->pc; goto dispatch; }
goto P_0c04e13c;
P_0c04e13a: /* original 64c3, guest PC 0x0c04e13a */
if(!s->budget--) { s->failed_pc=0x0c04e13au; return 0; }
r[4]=r[12];
goto P_0c04e13c;
P_0c04e13c: /* original 52de, guest PC 0x0c04e13c */
if(!s->budget--) { s->failed_pc=0x0c04e13cu; return 0; }
r[2]=read(ram,r[13]+56,4);
goto P_0c04e13e;
P_0c04e13e: /* original 32b0, guest PC 0x0c04e13e */
if(!s->budget--) { s->failed_pc=0x0c04e13eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c04e140;
P_0c04e140: /* original 8f02, guest PC 0x0c04e140 */
if(!s->budget--) { s->failed_pc=0x0c04e140u; return 0; }
cond=r[17]&1u;
r[10]=(uint32_t)(int32_t)(int16_t)r[14];
if(!cond) { goto P_0c04e148; }
goto P_0c04e144;
P_0c04e142: /* original 6aef, guest PC 0x0c04e142 */
if(!s->budget--) { s->failed_pc=0x0c04e142u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04e144;
P_0c04e144: /* original a005, guest PC 0x0c04e144 */
if(!s->budget--) { s->failed_pc=0x0c04e144u; return 0; }
write(ram,r[13]+56,r[10],4);
goto P_0c04e152;
P_0c04e146: /* original 1dae, guest PC 0x0c04e146 */
if(!s->budget--) { s->failed_pc=0x0c04e146u; return 0; }
write(ram,r[13]+56,r[10],4);
goto P_0c04e148;
P_0c04e148: /* original d337, guest PC 0x0c04e148 */
if(!s->budget--) { s->failed_pc=0x0c04e148u; return 0; }
r[3]=read(ram,0x0c04e228u,4);
goto P_0c04e14a;
P_0c04e14a: /* original 66e3, guest PC 0x0c04e14a */
if(!s->budget--) { s->failed_pc=0x0c04e14au; return 0; }
r[6]=r[14];
goto P_0c04e14c;
P_0c04e14c: /* original 55df, guest PC 0x0c04e14c */
if(!s->budget--) { s->failed_pc=0x0c04e14cu; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c04e14e;
P_0c04e14e: /* original 430b, guest PC 0x0c04e14e */
if(!s->budget--) { s->failed_pc=0x0c04e14eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e152u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e152u) { target=s->pc; goto dispatch; }
goto P_0c04e152;
P_0c04e150: /* original 64c3, guest PC 0x0c04e150 */
if(!s->budget--) { s->failed_pc=0x0c04e150u; return 0; }
r[4]=r[12];
goto P_0c04e152;
P_0c04e152: /* original e000, guest PC 0x0c04e152 */
if(!s->budget--) { s->failed_pc=0x0c04e152u; return 0; }
r[0]=0x00000000u;
goto P_0c04e154;
P_0c04e154: /* original 1daf, guest PC 0x0c04e154 */
if(!s->budget--) { s->failed_pc=0x0c04e154u; return 0; }
write(ram,r[13]+60,r[10],4);
goto P_0c04e156;
P_0c04e156: /* original 52dc, guest PC 0x0c04e156 */
if(!s->budget--) { s->failed_pc=0x0c04e156u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c04e158;
P_0c04e158: /* original 7201, guest PC 0x0c04e158 */
if(!s->budget--) { s->failed_pc=0x0c04e158u; return 0; }
r[2]+=0x00000001u;
goto P_0c04e15a;
P_0c04e15a: /* original 1d2c, guest PC 0x0c04e15a */
if(!s->budget--) { s->failed_pc=0x0c04e15au; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04e15c;
P_0c04e15c: /* original 4f16, guest PC 0x0c04e15c */
if(!s->budget--) { s->failed_pc=0x0c04e15cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e15e;
P_0c04e15e: /* original 4f26, guest PC 0x0c04e15e */
if(!s->budget--) { s->failed_pc=0x0c04e15eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e160;
P_0c04e160: /* original 68f6, guest PC 0x0c04e160 */
if(!s->budget--) { s->failed_pc=0x0c04e160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04e162;
P_0c04e162: /* original 69f6, guest PC 0x0c04e162 */
if(!s->budget--) { s->failed_pc=0x0c04e162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e164;
P_0c04e164: /* original 6af6, guest PC 0x0c04e164 */
if(!s->budget--) { s->failed_pc=0x0c04e164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e166;
P_0c04e166: /* original 6bf6, guest PC 0x0c04e166 */
if(!s->budget--) { s->failed_pc=0x0c04e166u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e168;
P_0c04e168: /* original 6cf6, guest PC 0x0c04e168 */
if(!s->budget--) { s->failed_pc=0x0c04e168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e16a;
P_0c04e16a: /* original 6df6, guest PC 0x0c04e16a */
if(!s->budget--) { s->failed_pc=0x0c04e16au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e16c;
P_0c04e16c: /* original 000b, guest PC 0x0c04e16c */
if(!s->budget--) { s->failed_pc=0x0c04e16cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e16e: /* original 6ef6, guest PC 0x0c04e16e */
if(!s->budget--) { s->failed_pc=0x0c04e16eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e170u,s,ram);
P_0c04e8f8: /* original 4f22, guest PC 0x0c04e8f8 */
if(!s->budget--) { s->failed_pc=0x0c04e8f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e8fa;
P_0c04e8fa: /* original 4f12, guest PC 0x0c04e8fa */
if(!s->budget--) { s->failed_pc=0x0c04e8fau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e8fc;
P_0c04e8fc: /* original 7ffc, guest PC 0x0c04e8fc */
if(!s->budget--) { s->failed_pc=0x0c04e8fcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e8fe;
P_0c04e8fe: /* original 2f66, guest PC 0x0c04e8fe */
if(!s->budget--) { s->failed_pc=0x0c04e8feu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e900;
P_0c04e900: /* original 2fb6, guest PC 0x0c04e900 */
if(!s->budget--) { s->failed_pc=0x0c04e900u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e902;
P_0c04e902: /* original 2fe6, guest PC 0x0c04e902 */
if(!s->budget--) { s->failed_pc=0x0c04e902u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e904;
P_0c04e904: /* original d328, guest PC 0x0c04e904 */
if(!s->budget--) { s->failed_pc=0x0c04e904u; return 0; }
r[3]=read(ram,0x0c04e9a8u,4);
goto P_0c04e906;
P_0c04e906: /* original d229, guest PC 0x0c04e906 */
if(!s->budget--) { s->failed_pc=0x0c04e906u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e908;
P_0c04e908: /* original 420b, guest PC 0x0c04e908 */
if(!s->budget--) { s->failed_pc=0x0c04e908u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e90cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e90cu) { target=s->pc; goto dispatch; }
goto P_0c04e90c;
P_0c04e90a: /* original 2f36, guest PC 0x0c04e90a */
if(!s->budget--) { s->failed_pc=0x0c04e90au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e90c;
P_0c04e90c: /* original 4d15, guest PC 0x0c04e90c */
if(!s->budget--) { s->failed_pc=0x0c04e90cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e90e;
P_0c04e90e: /* original e900, guest PC 0x0c04e90e */
if(!s->budget--) { s->failed_pc=0x0c04e90eu; return 0; }
r[9]=0x00000000u;
goto P_0c04e910;
P_0c04e910: /* original 7f10, guest PC 0x0c04e910 */
if(!s->budget--) { s->failed_pc=0x0c04e910u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e912;
P_0c04e912: /* original 8f0f, guest PC 0x0c04e912 */
if(!s->budget--) { s->failed_pc=0x0c04e912u; return 0; }
cond=r[17]&1u;
r[12]=r[9];
if(!cond) { goto P_0c04e934; }
goto P_0c04e916;
P_0c04e914: /* original 6c93, guest PC 0x0c04e914 */
if(!s->budget--) { s->failed_pc=0x0c04e914u; return 0; }
r[12]=r[9];
goto P_0c04e916;
P_0c04e916: /* original d826, guest PC 0x0c04e916 */
if(!s->budget--) { s->failed_pc=0x0c04e916u; return 0; }
r[8]=read(ram,0x0c04e9b0u,4);
goto P_0c04e918;
P_0c04e918: /* original 6ac3, guest PC 0x0c04e918 */
if(!s->budget--) { s->failed_pc=0x0c04e918u; return 0; }
r[10]=r[12];
goto P_0c04e91a;
P_0c04e91a: /* original 4a08, guest PC 0x0c04e91a */
if(!s->budget--) { s->failed_pc=0x0c04e91au; return 0; }
r[10]<<=2;
goto P_0c04e91c;
P_0c04e91c: /* original 3abc, guest PC 0x0c04e91c */
if(!s->budget--) { s->failed_pc=0x0c04e91cu; return 0; }
r[10]+=r[11];
goto P_0c04e91e;
P_0c04e91e: /* original 2fa6, guest PC 0x0c04e91e */
if(!s->budget--) { s->failed_pc=0x0c04e91eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e920;
P_0c04e920: /* original 63a2, guest PC 0x0c04e920 */
if(!s->budget--) { s->failed_pc=0x0c04e920u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c04e922;
P_0c04e922: /* original 2f36, guest PC 0x0c04e922 */
if(!s->budget--) { s->failed_pc=0x0c04e922u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e924;
P_0c04e924: /* original 2fc6, guest PC 0x0c04e924 */
if(!s->budget--) { s->failed_pc=0x0c04e924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e926;
P_0c04e926: /* original d221, guest PC 0x0c04e926 */
if(!s->budget--) { s->failed_pc=0x0c04e926u; return 0; }
r[2]=read(ram,0x0c04e9acu,4);
goto P_0c04e928;
P_0c04e928: /* original 420b, guest PC 0x0c04e928 */
if(!s->budget--) { s->failed_pc=0x0c04e928u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e92cu;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e92cu) { target=s->pc; goto dispatch; }
goto P_0c04e92c;
P_0c04e92a: /* original 2f86, guest PC 0x0c04e92a */
if(!s->budget--) { s->failed_pc=0x0c04e92au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e92c;
P_0c04e92c: /* original 7c01, guest PC 0x0c04e92c */
if(!s->budget--) { s->failed_pc=0x0c04e92cu; return 0; }
r[12]+=0x00000001u;
goto P_0c04e92e;
P_0c04e92e: /* original 3cd3, guest PC 0x0c04e92e */
if(!s->budget--) { s->failed_pc=0x0c04e92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c04e930;
P_0c04e930: /* original 8ff2, guest PC 0x0c04e930 */
if(!s->budget--) { s->failed_pc=0x0c04e930u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(!cond) { goto P_0c04e918; }
goto P_0c04e934;
P_0c04e932: /* original 7f10, guest PC 0x0c04e932 */
if(!s->budget--) { s->failed_pc=0x0c04e932u; return 0; }
r[15]+=0x00000010u;
goto P_0c04e934;
P_0c04e934: /* original 9c34, guest PC 0x0c04e934 */
if(!s->budget--) { s->failed_pc=0x0c04e934u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a0u,2);
goto P_0c04e936;
P_0c04e936: /* original ea01, guest PC 0x0c04e936 */
if(!s->budget--) { s->failed_pc=0x0c04e936u; return 0; }
r[10]=0x00000001u;
goto P_0c04e938;
P_0c04e938: /* original 2ecf, guest PC 0x0c04e938 */
if(!s->budget--) { s->failed_pc=0x0c04e938u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[12]);
goto P_0c04e93a;
P_0c04e93a: /* original 0c1a, guest PC 0x0c04e93a */
if(!s->budget--) { s->failed_pc=0x0c04e93au; return 0; }
r[12]=r[19];
goto P_0c04e93c;
P_0c04e93c: /* original 6ccf, guest PC 0x0c04e93c */
if(!s->budget--) { s->failed_pc=0x0c04e93cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04e93e;
P_0c04e93e: /* original 2fc2, guest PC 0x0c04e93e */
if(!s->budget--) { s->failed_pc=0x0c04e93eu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c04e940;
P_0c04e940: /* original d31c, guest PC 0x0c04e940 */
if(!s->budget--) { s->failed_pc=0x0c04e940u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e942;
P_0c04e942: /* original 3c3c, guest PC 0x0c04e942 */
if(!s->budget--) { s->failed_pc=0x0c04e942u; return 0; }
r[12]+=r[3];
goto P_0c04e944;
P_0c04e944: /* original 1cac, guest PC 0x0c04e944 */
if(!s->budget--) { s->failed_pc=0x0c04e944u; return 0; }
write(ram,r[12]+48,r[10],4);
goto P_0c04e946;
P_0c04e946: /* original 52c1, guest PC 0x0c04e946 */
if(!s->budget--) { s->failed_pc=0x0c04e946u; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c04e948;
P_0c04e948: /* original d01b, guest PC 0x0c04e948 */
if(!s->budget--) { s->failed_pc=0x0c04e948u; return 0; }
r[0]=read(ram,0x0c04e9b8u,4);
goto P_0c04e94a;
P_0c04e94a: /* original 6123, guest PC 0x0c04e94a */
if(!s->budget--) { s->failed_pc=0x0c04e94au; return 0; }
r[1]=r[2];
goto P_0c04e94c;
P_0c04e94c: /* original 4208, guest PC 0x0c04e94c */
if(!s->budget--) { s->failed_pc=0x0c04e94cu; return 0; }
r[2]<<=2;
goto P_0c04e94e;
P_0c04e94e: /* original 321c, guest PC 0x0c04e94e */
if(!s->budget--) { s->failed_pc=0x0c04e94eu; return 0; }
r[2]+=r[1];
goto P_0c04e950;
P_0c04e950: /* original 4208, guest PC 0x0c04e950 */
if(!s->budget--) { s->failed_pc=0x0c04e950u; return 0; }
r[2]<<=2;
goto P_0c04e952;
P_0c04e952: /* original 4208, guest PC 0x0c04e952 */
if(!s->budget--) { s->failed_pc=0x0c04e952u; return 0; }
r[2]<<=2;
goto P_0c04e954;
P_0c04e954: /* original 622f, guest PC 0x0c04e954 */
if(!s->budget--) { s->failed_pc=0x0c04e954u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04e956;
P_0c04e956: /* original 002e, guest PC 0x0c04e956 */
if(!s->budget--) { s->failed_pc=0x0c04e956u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
goto P_0c04e958;
P_0c04e958: /* original 1c0d, guest PC 0x0c04e958 */
if(!s->budget--) { s->failed_pc=0x0c04e958u; return 0; }
write(ram,r[12]+52,r[0],4);
goto P_0c04e95a;
P_0c04e95a: /* original 84c2, guest PC 0x0c04e95a */
if(!s->budget--) { s->failed_pc=0x0c04e95au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c04e95c;
P_0c04e95c: /* original 2008, guest PC 0x0c04e95c */
if(!s->budget--) { s->failed_pc=0x0c04e95cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e95e;
P_0c04e95e: /* original 8914, guest PC 0x0c04e95e */
if(!s->budget--) { s->failed_pc=0x0c04e95eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e960;
P_0c04e960: /* original d316, guest PC 0x0c04e960 */
if(!s->budget--) { s->failed_pc=0x0c04e960u; return 0; }
r[3]=read(ram,0x0c04e9bcu,4);
goto P_0c04e962;
P_0c04e962: /* original 430b, guest PC 0x0c04e962 */
if(!s->budget--) { s->failed_pc=0x0c04e962u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e966u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e966u) { target=s->pc; goto dispatch; }
goto P_0c04e966;
P_0c04e964: /* original 64e3, guest PC 0x0c04e964 */
if(!s->budget--) { s->failed_pc=0x0c04e964u; return 0; }
r[4]=r[14];
goto P_0c04e966;
P_0c04e966: /* original 2008, guest PC 0x0c04e966 */
if(!s->budget--) { s->failed_pc=0x0c04e966u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e968;
P_0c04e968: /* original 8b04, guest PC 0x0c04e968 */
if(!s->budget--) { s->failed_pc=0x0c04e968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e974; }
goto P_0c04e96a;
P_0c04e96a: /* original d315, guest PC 0x0c04e96a */
if(!s->budget--) { s->failed_pc=0x0c04e96au; return 0; }
r[3]=read(ram,0x0c04e9c0u,4);
goto P_0c04e96c;
P_0c04e96c: /* original 430b, guest PC 0x0c04e96c */
if(!s->budget--) { s->failed_pc=0x0c04e96cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e970u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e970u) { target=s->pc; goto dispatch; }
goto P_0c04e970;
P_0c04e96e: /* original 64e3, guest PC 0x0c04e96e */
if(!s->budget--) { s->failed_pc=0x0c04e96eu; return 0; }
r[4]=r[14];
goto P_0c04e970;
P_0c04e970: /* original a00b, guest PC 0x0c04e970 */
if(!s->budget--) { s->failed_pc=0x0c04e970u; return 0; }
goto P_0c04e98a;
P_0c04e972: /* original 0009, guest PC 0x0c04e972 */
if(!s->budget--) { s->failed_pc=0x0c04e972u; return 0; }
goto P_0c04e974;
P_0c04e974: /* original d213, guest PC 0x0c04e974 */
if(!s->budget--) { s->failed_pc=0x0c04e974u; return 0; }
r[2]=read(ram,0x0c04e9c4u,4);
goto P_0c04e976;
P_0c04e976: /* original 420b, guest PC 0x0c04e976 */
if(!s->budget--) { s->failed_pc=0x0c04e976u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e97au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e97au) { target=s->pc; goto dispatch; }
goto P_0c04e97a;
P_0c04e978: /* original 64e3, guest PC 0x0c04e978 */
if(!s->budget--) { s->failed_pc=0x0c04e978u; return 0; }
r[4]=r[14];
goto P_0c04e97a;
P_0c04e97a: /* original 2008, guest PC 0x0c04e97a */
if(!s->budget--) { s->failed_pc=0x0c04e97au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e97c;
P_0c04e97c: /* original 8905, guest PC 0x0c04e97c */
if(!s->budget--) { s->failed_pc=0x0c04e97cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e98a; }
goto P_0c04e97e;
P_0c04e97e: /* original 62f2, guest PC 0x0c04e97e */
if(!s->budget--) { s->failed_pc=0x0c04e97eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e980;
P_0c04e980: /* original d30c, guest PC 0x0c04e980 */
if(!s->budget--) { s->failed_pc=0x0c04e980u; return 0; }
r[3]=read(ram,0x0c04e9b4u,4);
goto P_0c04e982;
P_0c04e982: /* original 323c, guest PC 0x0c04e982 */
if(!s->budget--) { s->failed_pc=0x0c04e982u; return 0; }
r[2]+=r[3];
goto P_0c04e984;
P_0c04e984: /* original 8428, guest PC 0x0c04e984 */
if(!s->budget--) { s->failed_pc=0x0c04e984u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e986;
P_0c04e986: /* original 2008, guest PC 0x0c04e986 */
if(!s->budget--) { s->failed_pc=0x0c04e986u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e988;
P_0c04e988: /* original 8b02, guest PC 0x0c04e988 */
if(!s->budget--) { s->failed_pc=0x0c04e988u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e990; }
goto P_0c04e98a;
P_0c04e98a: /* original 900a, guest PC 0x0c04e98a */
if(!s->budget--) { s->failed_pc=0x0c04e98au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a2u,2);
goto P_0c04e98c;
P_0c04e98c: /* original a04f, guest PC 0x0c04e98c */
if(!s->budget--) { s->failed_pc=0x0c04e98cu; return 0; }
goto P_0c04ea2e;
P_0c04e98e: /* original 0009, guest PC 0x0c04e98e */
if(!s->budget--) { s->failed_pc=0x0c04e98eu; return 0; }
goto P_0c04e990;
P_0c04e990: /* original d30d, guest PC 0x0c04e990 */
if(!s->budget--) { s->failed_pc=0x0c04e990u; return 0; }
r[3]=read(ram,0x0c04e9c8u,4);
goto P_0c04e992;
P_0c04e992: /* original 430b, guest PC 0x0c04e992 */
if(!s->budget--) { s->failed_pc=0x0c04e992u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e996u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e996u) { target=s->pc; goto dispatch; }
goto P_0c04e996;
P_0c04e994: /* original 64e3, guest PC 0x0c04e994 */
if(!s->budget--) { s->failed_pc=0x0c04e994u; return 0; }
r[4]=r[14];
goto P_0c04e996;
P_0c04e996: /* original 4011, guest PC 0x0c04e996 */
if(!s->budget--) { s->failed_pc=0x0c04e996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e998;
P_0c04e998: /* original 8918, guest PC 0x0c04e998 */
if(!s->budget--) { s->failed_pc=0x0c04e998u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e9cc; }
goto P_0c04e99a;
P_0c04e99a: /* original 9003, guest PC 0x0c04e99a */
if(!s->budget--) { s->failed_pc=0x0c04e99au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e9a4u,2);
goto P_0c04e99c;
P_0c04e99c: /* original a047, guest PC 0x0c04e99c */
if(!s->budget--) { s->failed_pc=0x0c04e99cu; return 0; }
goto P_0c04ea2e;
P_0c04e99e: /* original 0009, guest PC 0x0c04e99e */
if(!s->budget--) { s->failed_pc=0x0c04e99eu; return 0; }
return vf3_matrix_family(0x0c04e9a0u,s,ram);
P_0c04e9cc: /* original 4d15, guest PC 0x0c04e9cc */
if(!s->budget--) { s->failed_pc=0x0c04e9ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ce;
P_0c04e9ce: /* original 6893, guest PC 0x0c04e9ce */
if(!s->budget--) { s->failed_pc=0x0c04e9ceu; return 0; }
r[8]=r[9];
goto P_0c04e9d0;
P_0c04e9d0: /* original 8f0a, guest PC 0x0c04e9d0 */
if(!s->budget--) { s->failed_pc=0x0c04e9d0u; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04e9e8; }
goto P_0c04e9d4;
P_0c04e9d2: /* original 6cb3, guest PC 0x0c04e9d2 */
if(!s->budget--) { s->failed_pc=0x0c04e9d2u; return 0; }
r[12]=r[11];
goto P_0c04e9d4;
P_0c04e9d4: /* original d235, guest PC 0x0c04e9d4 */
if(!s->budget--) { s->failed_pc=0x0c04e9d4u; return 0; }
r[2]=read(ram,0x0c04eaacu,4);
goto P_0c04e9d6;
P_0c04e9d6: /* original 65c2, guest PC 0x0c04e9d6 */
if(!s->budget--) { s->failed_pc=0x0c04e9d6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9d8;
P_0c04e9d8: /* original 420b, guest PC 0x0c04e9d8 */
if(!s->budget--) { s->failed_pc=0x0c04e9d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e9dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e9dcu) { target=s->pc; goto dispatch; }
goto P_0c04e9dc;
P_0c04e9da: /* original 64e3, guest PC 0x0c04e9da */
if(!s->budget--) { s->failed_pc=0x0c04e9dau; return 0; }
r[4]=r[14];
goto P_0c04e9dc;
P_0c04e9dc: /* original 4011, guest PC 0x0c04e9dc */
if(!s->budget--) { s->failed_pc=0x0c04e9dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9de;
P_0c04e9de: /* original 8b22, guest PC 0x0c04e9de */
if(!s->budget--) { s->failed_pc=0x0c04e9deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ea26; }
goto P_0c04e9e0;
P_0c04e9e0: /* original 7801, guest PC 0x0c04e9e0 */
if(!s->budget--) { s->failed_pc=0x0c04e9e0u; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9e2;
P_0c04e9e2: /* original 38d3, guest PC 0x0c04e9e2 */
if(!s->budget--) { s->failed_pc=0x0c04e9e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04e9e4;
P_0c04e9e4: /* original 8ff6, guest PC 0x0c04e9e4 */
if(!s->budget--) { s->failed_pc=0x0c04e9e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9d4; }
goto P_0c04e9e8;
P_0c04e9e6: /* original 7c04, guest PC 0x0c04e9e6 */
if(!s->budget--) { s->failed_pc=0x0c04e9e6u; return 0; }
r[12]+=0x00000004u;
goto P_0c04e9e8;
P_0c04e9e8: /* original 4d15, guest PC 0x0c04e9e8 */
if(!s->budget--) { s->failed_pc=0x0c04e9e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c04e9ea;
P_0c04e9ea: /* original 6893, guest PC 0x0c04e9ea */
if(!s->budget--) { s->failed_pc=0x0c04e9eau; return 0; }
r[8]=r[9];
goto P_0c04e9ec;
P_0c04e9ec: /* original 2f92, guest PC 0x0c04e9ec */
if(!s->budget--) { s->failed_pc=0x0c04e9ecu; return 0; }
write(ram,r[15],r[9],4);
goto P_0c04e9ee;
P_0c04e9ee: /* original 8f0a, guest PC 0x0c04e9ee */
if(!s->budget--) { s->failed_pc=0x0c04e9eeu; return 0; }
cond=r[17]&1u;
r[12]=r[11];
if(!cond) { goto P_0c04ea06; }
goto P_0c04e9f2;
P_0c04e9f0: /* original 6cb3, guest PC 0x0c04e9f0 */
if(!s->budget--) { s->failed_pc=0x0c04e9f0u; return 0; }
r[12]=r[11];
goto P_0c04e9f2;
P_0c04e9f2: /* original 65c2, guest PC 0x0c04e9f2 */
if(!s->budget--) { s->failed_pc=0x0c04e9f2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c04e9f4;
P_0c04e9f4: /* original be8d, guest PC 0x0c04e9f4 */
if(!s->budget--) { s->failed_pc=0x0c04e9f4u; return 0; }
target=0x0c04e712u; r[16]=code_base|0x0c04e9f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e9f8u) { target=s->pc; goto dispatch; }
goto P_0c04e9f8;
P_0c04e9f6: /* original 64e3, guest PC 0x0c04e9f6 */
if(!s->budget--) { s->failed_pc=0x0c04e9f6u; return 0; }
r[4]=r[14];
goto P_0c04e9f8;
P_0c04e9f8: /* original 4011, guest PC 0x0c04e9f8 */
if(!s->budget--) { s->failed_pc=0x0c04e9f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e9fa;
P_0c04e9fa: /* original 8d01, guest PC 0x0c04e9fa */
if(!s->budget--) { s->failed_pc=0x0c04e9fau; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(cond) { goto P_0c04ea00; }
goto P_0c04e9fe;
P_0c04e9fc: /* original 7801, guest PC 0x0c04e9fc */
if(!s->budget--) { s->failed_pc=0x0c04e9fcu; return 0; }
r[8]+=0x00000001u;
goto P_0c04e9fe;
P_0c04e9fe: /* original 2fa2, guest PC 0x0c04e9fe */
if(!s->budget--) { s->failed_pc=0x0c04e9feu; return 0; }
write(ram,r[15],r[10],4);
goto P_0c04ea00;
P_0c04ea00: /* original 38d3, guest PC 0x0c04ea00 */
if(!s->budget--) { s->failed_pc=0x0c04ea00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[13])!=0);
goto P_0c04ea02;
P_0c04ea02: /* original 8ff6, guest PC 0x0c04ea02 */
if(!s->budget--) { s->failed_pc=0x0c04ea02u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c04e9f2; }
goto P_0c04ea06;
P_0c04ea04: /* original 7c04, guest PC 0x0c04ea04 */
if(!s->budget--) { s->failed_pc=0x0c04ea04u; return 0; }
r[12]+=0x00000004u;
goto P_0c04ea06;
P_0c04ea06: /* original b6a2, guest PC 0x0c04ea06 */
if(!s->budget--) { s->failed_pc=0x0c04ea06u; return 0; }
target=0x0c04f74eu; r[16]=code_base|0x0c04ea0au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea0au) { target=s->pc; goto dispatch; }
goto P_0c04ea0a;
P_0c04ea08: /* original 64e3, guest PC 0x0c04ea08 */
if(!s->budget--) { s->failed_pc=0x0c04ea08u; return 0; }
r[4]=r[14];
goto P_0c04ea0a;
P_0c04ea0a: /* original 4011, guest PC 0x0c04ea0a */
if(!s->budget--) { s->failed_pc=0x0c04ea0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea0c;
P_0c04ea0c: /* original 8f06, guest PC 0x0c04ea0c */
if(!s->budget--) { s->failed_pc=0x0c04ea0cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c04ea1c; }
goto P_0c04ea10;
P_0c04ea0e: /* original 6403, guest PC 0x0c04ea0e */
if(!s->budget--) { s->failed_pc=0x0c04ea0eu; return 0; }
r[4]=r[0];
goto P_0c04ea10;
P_0c04ea10: /* original d327, guest PC 0x0c04ea10 */
if(!s->budget--) { s->failed_pc=0x0c04ea10u; return 0; }
r[3]=read(ram,0x0c04eab0u,4);
goto P_0c04ea12;
P_0c04ea12: /* original 430b, guest PC 0x0c04ea12 */
if(!s->budget--) { s->failed_pc=0x0c04ea12u; return 0; }
target=r[3];
r[16]=code_base|0x0c04ea16u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ea16u) { target=s->pc; goto dispatch; }
goto P_0c04ea16;
P_0c04ea14: /* original 64e3, guest PC 0x0c04ea14 */
if(!s->budget--) { s->failed_pc=0x0c04ea14u; return 0; }
r[4]=r[14];
goto P_0c04ea16;
P_0c04ea16: /* original 4011, guest PC 0x0c04ea16 */
if(!s->budget--) { s->failed_pc=0x0c04ea16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ea18;
P_0c04ea18: /* original 8d02, guest PC 0x0c04ea18 */
if(!s->budget--) { s->failed_pc=0x0c04ea18u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04ea20; }
goto P_0c04ea1c;
P_0c04ea1a: /* original 6403, guest PC 0x0c04ea1a */
if(!s->budget--) { s->failed_pc=0x0c04ea1au; return 0; }
r[4]=r[0];
goto P_0c04ea1c;
P_0c04ea1c: /* original a007, guest PC 0x0c04ea1c */
if(!s->budget--) { s->failed_pc=0x0c04ea1cu; return 0; }
r[0]=r[4];
goto P_0c04ea2e;
P_0c04ea1e: /* original 6043, guest PC 0x0c04ea1e */
if(!s->budget--) { s->failed_pc=0x0c04ea1eu; return 0; }
r[0]=r[4];
goto P_0c04ea20;
P_0c04ea20: /* original 63f2, guest PC 0x0c04ea20 */
if(!s->budget--) { s->failed_pc=0x0c04ea20u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04ea22;
P_0c04ea22: /* original 2338, guest PC 0x0c04ea22 */
if(!s->budget--) { s->failed_pc=0x0c04ea22u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04ea24;
P_0c04ea24: /* original 8902, guest PC 0x0c04ea24 */
if(!s->budget--) { s->failed_pc=0x0c04ea24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ea2c; }
goto P_0c04ea26;
P_0c04ea26: /* original 903f, guest PC 0x0c04ea26 */
if(!s->budget--) { s->failed_pc=0x0c04ea26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04eaa8u,2);
goto P_0c04ea28;
P_0c04ea28: /* original a001, guest PC 0x0c04ea28 */
if(!s->budget--) { s->failed_pc=0x0c04ea28u; return 0; }
goto P_0c04ea2e;
P_0c04ea2a: /* original 0009, guest PC 0x0c04ea2a */
if(!s->budget--) { s->failed_pc=0x0c04ea2au; return 0; }
goto P_0c04ea2c;
P_0c04ea2c: /* original e000, guest PC 0x0c04ea2c */
if(!s->budget--) { s->failed_pc=0x0c04ea2cu; return 0; }
r[0]=0x00000000u;
goto P_0c04ea2e;
P_0c04ea2e: /* original 7f04, guest PC 0x0c04ea2e */
if(!s->budget--) { s->failed_pc=0x0c04ea2eu; return 0; }
r[15]+=0x00000004u;
goto P_0c04ea30;
P_0c04ea30: /* original 4f16, guest PC 0x0c04ea30 */
if(!s->budget--) { s->failed_pc=0x0c04ea30u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea32;
P_0c04ea32: /* original 4f26, guest PC 0x0c04ea32 */
if(!s->budget--) { s->failed_pc=0x0c04ea32u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ea34;
P_0c04ea34: /* original 68f6, guest PC 0x0c04ea34 */
if(!s->budget--) { s->failed_pc=0x0c04ea34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04ea36;
P_0c04ea36: /* original 69f6, guest PC 0x0c04ea36 */
if(!s->budget--) { s->failed_pc=0x0c04ea36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04ea38;
P_0c04ea38: /* original 6af6, guest PC 0x0c04ea38 */
if(!s->budget--) { s->failed_pc=0x0c04ea38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04ea3a;
P_0c04ea3a: /* original 6bf6, guest PC 0x0c04ea3a */
if(!s->budget--) { s->failed_pc=0x0c04ea3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04ea3c;
P_0c04ea3c: /* original 6cf6, guest PC 0x0c04ea3c */
if(!s->budget--) { s->failed_pc=0x0c04ea3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04ea3e;
P_0c04ea3e: /* original 6df6, guest PC 0x0c04ea3e */
if(!s->budget--) { s->failed_pc=0x0c04ea3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04ea40;
P_0c04ea40: /* original 000b, guest PC 0x0c04ea40 */
if(!s->budget--) { s->failed_pc=0x0c04ea40u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ea42: /* original 6ef6, guest PC 0x0c04ea42 */
if(!s->budget--) { s->failed_pc=0x0c04ea42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ea44u,s,ram);
P_0c04fbec: /* original 4f22, guest PC 0x0c04fbec */
if(!s->budget--) { s->failed_pc=0x0c04fbecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fbee;
P_0c04fbee: /* original 9d7a, guest PC 0x0c04fbee */
if(!s->budget--) { s->failed_pc=0x0c04fbeeu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fce6u,2);
goto P_0c04fbf0;
P_0c04fbf0: /* original d33d, guest PC 0x0c04fbf0 */
if(!s->budget--) { s->failed_pc=0x0c04fbf0u; return 0; }
r[3]=read(ram,0x0c04fce8u,4);
goto P_0c04fbf2;
P_0c04fbf2: /* original 4f12, guest PC 0x0c04fbf2 */
if(!s->budget--) { s->failed_pc=0x0c04fbf2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fbf4;
P_0c04fbf4: /* original 2cdf, guest PC 0x0c04fbf4 */
if(!s->budget--) { s->failed_pc=0x0c04fbf4u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[13]);
goto P_0c04fbf6;
P_0c04fbf6: /* original d23d, guest PC 0x0c04fbf6 */
if(!s->budget--) { s->failed_pc=0x0c04fbf6u; return 0; }
r[2]=read(ram,0x0c04fcecu,4);
goto P_0c04fbf8;
P_0c04fbf8: /* original d13d, guest PC 0x0c04fbf8 */
if(!s->budget--) { s->failed_pc=0x0c04fbf8u; return 0; }
r[1]=read(ram,0x0c04fcf0u,4);
goto P_0c04fbfa;
P_0c04fbfa: /* original 0d1a, guest PC 0x0c04fbfa */
if(!s->budget--) { s->failed_pc=0x0c04fbfau; return 0; }
r[13]=r[19];
goto P_0c04fbfc;
P_0c04fbfc: /* original 6ddf, guest PC 0x0c04fbfc */
if(!s->budget--) { s->failed_pc=0x0c04fbfcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04fbfe;
P_0c04fbfe: /* original 3d3c, guest PC 0x0c04fbfe */
if(!s->budget--) { s->failed_pc=0x0c04fbfeu; return 0; }
r[13]+=r[3];
goto P_0c04fc00;
P_0c04fc00: /* original 410b, guest PC 0x0c04fc00 */
if(!s->budget--) { s->failed_pc=0x0c04fc00u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fc04u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc04u) { target=s->pc; goto dispatch; }
goto P_0c04fc04;
P_0c04fc02: /* original 2f26, guest PC 0x0c04fc02 */
if(!s->budget--) { s->failed_pc=0x0c04fc02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc04;
P_0c04fc04: /* original 5ad7, guest PC 0x0c04fc04 */
if(!s->budget--) { s->failed_pc=0x0c04fc04u; return 0; }
r[10]=read(ram,r[13]+28,4);
goto P_0c04fc06;
P_0c04fc06: /* original 5aa4, guest PC 0x0c04fc06 */
if(!s->budget--) { s->failed_pc=0x0c04fc06u; return 0; }
r[10]=read(ram,r[10]+16,4);
goto P_0c04fc08;
P_0c04fc08: /* original 2fa6, guest PC 0x0c04fc08 */
if(!s->budget--) { s->failed_pc=0x0c04fc08u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc0a;
P_0c04fc0a: /* original d33a, guest PC 0x0c04fc0a */
if(!s->budget--) { s->failed_pc=0x0c04fc0au; return 0; }
r[3]=read(ram,0x0c04fcf4u,4);
goto P_0c04fc0c;
P_0c04fc0c: /* original d238, guest PC 0x0c04fc0c */
if(!s->budget--) { s->failed_pc=0x0c04fc0cu; return 0; }
r[2]=read(ram,0x0c04fcf0u,4);
goto P_0c04fc0e;
P_0c04fc0e: /* original 420b, guest PC 0x0c04fc0e */
if(!s->budget--) { s->failed_pc=0x0c04fc0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c04fc12u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc12u) { target=s->pc; goto dispatch; }
goto P_0c04fc12;
P_0c04fc10: /* original 2f36, guest PC 0x0c04fc10 */
if(!s->budget--) { s->failed_pc=0x0c04fc10u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc12;
P_0c04fc12: /* original d839, guest PC 0x0c04fc12 */
if(!s->budget--) { s->failed_pc=0x0c04fc12u; return 0; }
r[8]=read(ram,0x0c04fcf8u,4);
goto P_0c04fc14;
P_0c04fc14: /* original 4a15, guest PC 0x0c04fc14 */
if(!s->budget--) { s->failed_pc=0x0c04fc14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c04fc16;
P_0c04fc16: /* original ee00, guest PC 0x0c04fc16 */
if(!s->budget--) { s->failed_pc=0x0c04fc16u; return 0; }
r[14]=0x00000000u;
goto P_0c04fc18;
P_0c04fc18: /* original 6983, guest PC 0x0c04fc18 */
if(!s->budget--) { s->failed_pc=0x0c04fc18u; return 0; }
r[9]=r[8];
goto P_0c04fc1a;
P_0c04fc1a: /* original 7f0c, guest PC 0x0c04fc1a */
if(!s->budget--) { s->failed_pc=0x0c04fc1au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04fc1c;
P_0c04fc1c: /* original 8f28, guest PC 0x0c04fc1c */
if(!s->budget--) { s->failed_pc=0x0c04fc1cu; return 0; }
cond=r[17]&1u;
r[9]+=0xfffffffbu;
if(!cond) { goto P_0c04fc70; }
goto P_0c04fc20;
P_0c04fc1e: /* original 79fb, guest PC 0x0c04fc1e */
if(!s->budget--) { s->failed_pc=0x0c04fc1eu; return 0; }
r[9]+=0xfffffffbu;
goto P_0c04fc20;
P_0c04fc20: /* original 52d7, guest PC 0x0c04fc20 */
if(!s->budget--) { s->failed_pc=0x0c04fc20u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04fc22;
P_0c04fc22: /* original 5323, guest PC 0x0c04fc22 */
if(!s->budget--) { s->failed_pc=0x0c04fc22u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c04fc24;
P_0c04fc24: /* original 33ec, guest PC 0x0c04fc24 */
if(!s->budget--) { s->failed_pc=0x0c04fc24u; return 0; }
r[3]+=r[14];
goto P_0c04fc26;
P_0c04fc26: /* original 2f36, guest PC 0x0c04fc26 */
if(!s->budget--) { s->failed_pc=0x0c04fc26u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc28;
P_0c04fc28: /* original d331, guest PC 0x0c04fc28 */
if(!s->budget--) { s->failed_pc=0x0c04fc28u; return 0; }
r[3]=read(ram,0x0c04fcf0u,4);
goto P_0c04fc2a;
P_0c04fc2a: /* original d234, guest PC 0x0c04fc2a */
if(!s->budget--) { s->failed_pc=0x0c04fc2au; return 0; }
r[2]=read(ram,0x0c04fcfcu,4);
goto P_0c04fc2c;
P_0c04fc2c: /* original 430b, guest PC 0x0c04fc2c */
if(!s->budget--) { s->failed_pc=0x0c04fc2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fc30u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc30u) { target=s->pc; goto dispatch; }
goto P_0c04fc30;
P_0c04fc2e: /* original 2f26, guest PC 0x0c04fc2e */
if(!s->budget--) { s->failed_pc=0x0c04fc2eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fc30;
P_0c04fc30: /* original 66e3, guest PC 0x0c04fc30 */
if(!s->budget--) { s->failed_pc=0x0c04fc30u; return 0; }
r[6]=r[14];
goto P_0c04fc32;
P_0c04fc32: /* original 53d9, guest PC 0x0c04fc32 */
if(!s->budget--) { s->failed_pc=0x0c04fc32u; return 0; }
r[3]=read(ram,r[13]+36,4);
goto P_0c04fc34;
P_0c04fc34: /* original 55d7, guest PC 0x0c04fc34 */
if(!s->budget--) { s->failed_pc=0x0c04fc34u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc36;
P_0c04fc36: /* original 4618, guest PC 0x0c04fc36 */
if(!s->budget--) { s->failed_pc=0x0c04fc36u; return 0; }
r[6]<<=8;
goto P_0c04fc38;
P_0c04fc38: /* original 4600, guest PC 0x0c04fc38 */
if(!s->budget--) { s->failed_pc=0x0c04fc38u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c04fc3a;
P_0c04fc3a: /* original 5553, guest PC 0x0c04fc3a */
if(!s->budget--) { s->failed_pc=0x0c04fc3au; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc3c;
P_0c04fc3c: /* original 363c, guest PC 0x0c04fc3c */
if(!s->budget--) { s->failed_pc=0x0c04fc3cu; return 0; }
r[6]+=r[3];
goto P_0c04fc3e;
P_0c04fc3e: /* original d330, guest PC 0x0c04fc3e */
if(!s->budget--) { s->failed_pc=0x0c04fc3eu; return 0; }
r[3]=read(ram,0x0c04fd00u,4);
goto P_0c04fc40;
P_0c04fc40: /* original 7f08, guest PC 0x0c04fc40 */
if(!s->budget--) { s->failed_pc=0x0c04fc40u; return 0; }
r[15]+=0x00000008u;
goto P_0c04fc42;
P_0c04fc42: /* original 35ec, guest PC 0x0c04fc42 */
if(!s->budget--) { s->failed_pc=0x0c04fc42u; return 0; }
r[5]+=r[14];
goto P_0c04fc44;
P_0c04fc44: /* original 430b, guest PC 0x0c04fc44 */
if(!s->budget--) { s->failed_pc=0x0c04fc44u; return 0; }
target=r[3];
r[16]=code_base|0x0c04fc48u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc48u) { target=s->pc; goto dispatch; }
goto P_0c04fc48;
P_0c04fc46: /* original 64c3, guest PC 0x0c04fc46 */
if(!s->budget--) { s->failed_pc=0x0c04fc46u; return 0; }
r[4]=r[12];
goto P_0c04fc48;
P_0c04fc48: /* original 6b03, guest PC 0x0c04fc48 */
if(!s->budget--) { s->failed_pc=0x0c04fc48u; return 0; }
r[11]=r[0];
goto P_0c04fc4a;
P_0c04fc4a: /* original 4b11, guest PC 0x0c04fc4a */
if(!s->budget--) { s->failed_pc=0x0c04fc4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=0)!=0);
goto P_0c04fc4c;
P_0c04fc4c: /* original 8907, guest PC 0x0c04fc4c */
if(!s->budget--) { s->failed_pc=0x0c04fc4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fc5e; }
goto P_0c04fc4e;
P_0c04fc4e: /* original 55d7, guest PC 0x0c04fc4e */
if(!s->budget--) { s->failed_pc=0x0c04fc4eu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc50;
P_0c04fc50: /* original 6683, guest PC 0x0c04fc50 */
if(!s->budget--) { s->failed_pc=0x0c04fc50u; return 0; }
r[6]=r[8];
goto P_0c04fc52;
P_0c04fc52: /* original 5553, guest PC 0x0c04fc52 */
if(!s->budget--) { s->failed_pc=0x0c04fc52u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc54;
P_0c04fc54: /* original 35ec, guest PC 0x0c04fc54 */
if(!s->budget--) { s->failed_pc=0x0c04fc54u; return 0; }
r[5]+=r[14];
goto P_0c04fc56;
P_0c04fc56: /* original b0f3, guest PC 0x0c04fc56 */
if(!s->budget--) { s->failed_pc=0x0c04fc56u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04fc5au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc5au) { target=s->pc; goto dispatch; }
goto P_0c04fc5a;
P_0c04fc58: /* original 64c3, guest PC 0x0c04fc58 */
if(!s->budget--) { s->failed_pc=0x0c04fc58u; return 0; }
r[4]=r[12];
goto P_0c04fc5a;
P_0c04fc5a: /* original a00a, guest PC 0x0c04fc5a */
if(!s->budget--) { s->failed_pc=0x0c04fc5au; return 0; }
r[0]=r[11];
goto P_0c04fc72;
P_0c04fc5c: /* original 60b3, guest PC 0x0c04fc5c */
if(!s->budget--) { s->failed_pc=0x0c04fc5cu; return 0; }
r[0]=r[11];
goto P_0c04fc5e;
P_0c04fc5e: /* original 55d7, guest PC 0x0c04fc5e */
if(!s->budget--) { s->failed_pc=0x0c04fc5eu; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c04fc60;
P_0c04fc60: /* original 6693, guest PC 0x0c04fc60 */
if(!s->budget--) { s->failed_pc=0x0c04fc60u; return 0; }
r[6]=r[9];
goto P_0c04fc62;
P_0c04fc62: /* original 5553, guest PC 0x0c04fc62 */
if(!s->budget--) { s->failed_pc=0x0c04fc62u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c04fc64;
P_0c04fc64: /* original 35ec, guest PC 0x0c04fc64 */
if(!s->budget--) { s->failed_pc=0x0c04fc64u; return 0; }
r[5]+=r[14];
goto P_0c04fc66;
P_0c04fc66: /* original b0eb, guest PC 0x0c04fc66 */
if(!s->budget--) { s->failed_pc=0x0c04fc66u; return 0; }
target=0x0c04fe40u; r[16]=code_base|0x0c04fc6au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fc6au) { target=s->pc; goto dispatch; }
goto P_0c04fc6a;
P_0c04fc68: /* original 64c3, guest PC 0x0c04fc68 */
if(!s->budget--) { s->failed_pc=0x0c04fc68u; return 0; }
r[4]=r[12];
goto P_0c04fc6a;
P_0c04fc6a: /* original 7e01, guest PC 0x0c04fc6a */
if(!s->budget--) { s->failed_pc=0x0c04fc6au; return 0; }
r[14]+=0x00000001u;
goto P_0c04fc6c;
P_0c04fc6c: /* original 3ea3, guest PC 0x0c04fc6c */
if(!s->budget--) { s->failed_pc=0x0c04fc6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[10])!=0);
goto P_0c04fc6e;
P_0c04fc6e: /* original 8bd7, guest PC 0x0c04fc6e */
if(!s->budget--) { s->failed_pc=0x0c04fc6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fc20; }
goto P_0c04fc70;
P_0c04fc70: /* original e000, guest PC 0x0c04fc70 */
if(!s->budget--) { s->failed_pc=0x0c04fc70u; return 0; }
r[0]=0x00000000u;
goto P_0c04fc72;
P_0c04fc72: /* original 4f16, guest PC 0x0c04fc72 */
if(!s->budget--) { s->failed_pc=0x0c04fc72u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fc74;
P_0c04fc74: /* original 4f26, guest PC 0x0c04fc74 */
if(!s->budget--) { s->failed_pc=0x0c04fc74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fc76;
P_0c04fc76: /* original 68f6, guest PC 0x0c04fc76 */
if(!s->budget--) { s->failed_pc=0x0c04fc76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04fc78;
P_0c04fc78: /* original 69f6, guest PC 0x0c04fc78 */
if(!s->budget--) { s->failed_pc=0x0c04fc78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04fc7a;
P_0c04fc7a: /* original 6af6, guest PC 0x0c04fc7a */
if(!s->budget--) { s->failed_pc=0x0c04fc7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fc7c;
P_0c04fc7c: /* original 6bf6, guest PC 0x0c04fc7c */
if(!s->budget--) { s->failed_pc=0x0c04fc7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fc7e;
P_0c04fc7e: /* original 6cf6, guest PC 0x0c04fc7e */
if(!s->budget--) { s->failed_pc=0x0c04fc7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fc80;
P_0c04fc80: /* original 6df6, guest PC 0x0c04fc80 */
if(!s->budget--) { s->failed_pc=0x0c04fc80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fc82;
P_0c04fc82: /* original 000b, guest PC 0x0c04fc82 */
if(!s->budget--) { s->failed_pc=0x0c04fc82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fc84: /* original 6ef6, guest PC 0x0c04fc84 */
if(!s->budget--) { s->failed_pc=0x0c04fc84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fc86u,s,ram);
P_0c0512dc: /* original 7f24, guest PC 0x0c0512dc */
if(!s->budget--) { s->failed_pc=0x0c0512dcu; return 0; }
r[15]+=0x00000024u;
goto P_0c0512de;
P_0c0512de: /* original 000b, guest PC 0x0c0512de */
if(!s->budget--) { s->failed_pc=0x0c0512deu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0512e0: /* original 0009, guest PC 0x0c0512e0 */
if(!s->budget--) { s->failed_pc=0x0c0512e0u; return 0; }
return vf3_matrix_family(0x0c0512e2u,s,ram);
P_0c058348: /* original 4f22, guest PC 0x0c058348 */
if(!s->budget--) { s->failed_pc=0x0c058348u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05834a;
P_0c05834a: /* original f31d, guest PC 0x0c05834a */
if(!s->budget--) { s->failed_pc=0x0c05834au; return 0; }
r[53]=fr[3];
goto P_0c05834c;
P_0c05834c: /* original 7e04, guest PC 0x0c05834c */
if(!s->budget--) { s->failed_pc=0x0c05834cu; return 0; }
r[14]+=0x00000004u;
goto P_0c05834e;
P_0c05834e: /* original 5222, guest PC 0x0c05834e */
if(!s->budget--) { s->failed_pc=0x0c05834eu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c058350;
P_0c058350: /* original 6be5, guest PC 0x0c058350 */
if(!s->budget--) { s->failed_pc=0x0c058350u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[11]=tmp;
goto P_0c058352;
P_0c058352: /* original fbfd, guest PC 0x0c058352 */
if(!s->budget--) { s->failed_pc=0x0c058352u; return 0; }
vf3_matrix_swap(s);
goto P_0c058354;
P_0c058354: /* original 72e0, guest PC 0x0c058354 */
if(!s->budget--) { s->failed_pc=0x0c058354u; return 0; }
r[2]+=0xffffffe0u;
goto P_0c058356;
P_0c058356: /* original f829, guest PC 0x0c058356 */
if(!s->budget--) { s->failed_pc=0x0c058356u; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058358;
P_0c058358: /* original f929, guest PC 0x0c058358 */
if(!s->budget--) { s->failed_pc=0x0c058358u; return 0; }
vf3_matrix_load(s,ram,9,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05835a;
P_0c05835a: /* original fa28, guest PC 0x0c05835a */
if(!s->budget--) { s->failed_pc=0x0c05835au; return 0; }
vf3_matrix_load(s,ram,10,r[2]);
goto P_0c05835c;
P_0c05835c: /* original 72d8, guest PC 0x0c05835c */
if(!s->budget--) { s->failed_pc=0x0c05835cu; return 0; }
r[2]+=0xffffffd8u;
goto P_0c05835e;
P_0c05835e: /* original f029, guest PC 0x0c05835e */
if(!s->budget--) { s->failed_pc=0x0c05835eu; return 0; }
vf3_matrix_load(s,ram,0,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058360;
P_0c058360: /* original f129, guest PC 0x0c058360 */
if(!s->budget--) { s->failed_pc=0x0c058360u; return 0; }
vf3_matrix_load(s,ram,1,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058362;
P_0c058362: /* original f228, guest PC 0x0c058362 */
if(!s->budget--) { s->failed_pc=0x0c058362u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c058364;
P_0c058364: /* original 7208, guest PC 0x0c058364 */
if(!s->budget--) { s->failed_pc=0x0c058364u; return 0; }
r[2]+=0x00000008u;
goto P_0c058366;
P_0c058366: /* original f429, guest PC 0x0c058366 */
if(!s->budget--) { s->failed_pc=0x0c058366u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c058368;
P_0c058368: /* original f529, guest PC 0x0c058368 */
if(!s->budget--) { s->failed_pc=0x0c058368u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
r[2]+=(r[18]&0x100000u)?8:4;
goto P_0c05836a;
P_0c05836a: /* original 7140, guest PC 0x0c05836a */
if(!s->budget--) { s->failed_pc=0x0c05836au; return 0; }
r[1]+=0x00000040u;
goto P_0c05836c;
P_0c05836c: /* original f628, guest PC 0x0c05836c */
if(!s->budget--) { s->failed_pc=0x0c05836cu; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c05836e;
P_0c05836e: /* original fc19, guest PC 0x0c05836e */
if(!s->budget--) { s->failed_pc=0x0c05836eu; return 0; }
vf3_matrix_load(s,ram,12,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058370;
P_0c058370: /* original fd19, guest PC 0x0c058370 */
if(!s->budget--) { s->failed_pc=0x0c058370u; return 0; }
vf3_matrix_load(s,ram,13,r[1]);
r[1]+=(r[18]&0x100000u)?8:4;
goto P_0c058372;
P_0c058372: /* original fe18, guest PC 0x0c058372 */
if(!s->budget--) { s->failed_pc=0x0c058372u; return 0; }
vf3_matrix_load(s,ram,14,r[1]);
goto P_0c058374;
P_0c058374: /* original f3fd, guest PC 0x0c058374 */
if(!s->budget--) { s->failed_pc=0x0c058374u; return 0; }
r[18]^=0x100000u;
goto P_0c058376;
P_0c058376: /* original ff0d, guest PC 0x0c058376 */
if(!s->budget--) { s->failed_pc=0x0c058376u; return 0; }
fr[15]=r[53];
goto P_0c058378;
P_0c058378: /* original fbfd, guest PC 0x0c058378 */
if(!s->budget--) { s->failed_pc=0x0c058378u; return 0; }
vf3_matrix_swap(s);
goto P_0c05837a;
P_0c05837a: /* original 67e5, guest PC 0x0c05837a */
if(!s->budget--) { s->failed_pc=0x0c05837au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c05837c: /* original 68e1, guest PC 0x0c05837c */
if(!s->budget--) { s->failed_pc=0x0c05837cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[8]=tmp;
goto P_0c05837e;
P_0c05837e: /* original e104, guest PC 0x0c05837e */
if(!s->budget--) { s->failed_pc=0x0c05837eu; return 0; }
r[1]=0x00000004u;
goto P_0c058380;
P_0c058380: /* original 85ec, guest PC 0x0c058380 */
if(!s->budget--) { s->failed_pc=0x0c058380u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c058382;
P_0c058382: /* original e500, guest PC 0x0c058382 */
if(!s->budget--) { s->failed_pc=0x0c058382u; return 0; }
r[5]=0x00000000u;
goto P_0c058384;
P_0c058384: /* original 4711, guest PC 0x0c058384 */
if(!s->budget--) { s->failed_pc=0x0c058384u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c058386;
P_0c058386: /* original 481d, guest PC 0x0c058386 */
if(!s->budget--) { s->failed_pc=0x0c058386u; return 0; }
r[8]=(r[1]&0x80000000u)?((r[1]&31u)?r[8]>>((-r[1])&31u):0):r[8]<<(r[1]&31u);
goto P_0c058388;
P_0c058388: /* original 8900, guest PC 0x0c058388 */
if(!s->budget--) { s->failed_pc=0x0c058388u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05838c; }
goto P_0c05838a;
P_0c05838a: /* original 677b, guest PC 0x0c05838a */
if(!s->budget--) { s->failed_pc=0x0c05838au; return 0; }
r[7]=0u-r[7];
goto P_0c05838c;
P_0c05838c: /* original 0329, guest PC 0x0c05838c */
if(!s->budget--) { s->failed_pc=0x0c05838cu; return 0; }
r[3]=r[17]&1u;
goto P_0c05838e;
P_0c05838e: /* original 401d, guest PC 0x0c05838e */
if(!s->budget--) { s->failed_pc=0x0c05838eu; return 0; }
r[0]=(r[1]&0x80000000u)?((r[1]&31u)?r[0]>>((-r[1])&31u):0):r[0]<<(r[1]&31u);
goto P_0c058390;
P_0c058390: /* original 38dc, guest PC 0x0c058390 */
if(!s->budget--) { s->failed_pc=0x0c058390u; return 0; }
r[8]+=r[13];
goto P_0c058392;
P_0c058392: /* original 6903, guest PC 0x0c058392 */
if(!s->budget--) { s->failed_pc=0x0c058392u; return 0; }
r[9]=r[0];
goto P_0c058394;
P_0c058394: /* original f088, guest PC 0x0c058394 */
if(!s->budget--) { s->failed_pc=0x0c058394u; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c058396;
P_0c058396: /* original 39dc, guest PC 0x0c058396 */
if(!s->budget--) { s->failed_pc=0x0c058396u; return 0; }
r[9]+=r[13];
goto P_0c058398;
P_0c058398: /* original 5282, guest PC 0x0c058398 */
if(!s->budget--) { s->failed_pc=0x0c058398u; return 0; }
r[2]=read(ram,r[8]+8,4);
goto P_0c05839a;
P_0c05839a: /* original f498, guest PC 0x0c05839a */
if(!s->budget--) { s->failed_pc=0x0c05839au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05839c;
P_0c05839c: /* original 7e30, guest PC 0x0c05839c */
if(!s->budget--) { s->failed_pc=0x0c05839cu; return 0; }
r[14]+=0x00000030u;
goto P_0c05839e;
P_0c05839e: /* original 5192, guest PC 0x0c05839e */
if(!s->budget--) { s->failed_pc=0x0c05839eu; return 0; }
r[1]=read(ram,r[9]+8,4);
goto P_0c0583a0;
P_0c0583a0: /* original 32a6, guest PC 0x0c0583a0 */
if(!s->budget--) { s->failed_pc=0x0c0583a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583a2;
P_0c0583a2: /* original 77fe, guest PC 0x0c0583a2 */
if(!s->budget--) { s->failed_pc=0x0c0583a2u; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0583a4;
P_0c0583a4: /* original 0429, guest PC 0x0c0583a4 */
if(!s->budget--) { s->failed_pc=0x0c0583a4u; return 0; }
r[4]=r[17]&1u;
goto P_0c0583a6;
P_0c0583a6: /* original 4215, guest PC 0x0c0583a6 */
if(!s->budget--) { s->failed_pc=0x0c0583a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583a8;
P_0c0583a8: /* original 344e, guest PC 0x0c0583a8 */
if(!s->budget--) { s->failed_pc=0x0c0583a8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583aa;
P_0c0583aa: /* original 234a, guest PC 0x0c0583aa */
if(!s->budget--) { s->failed_pc=0x0c0583aau; return 0; }
r[3]^=r[4];
goto P_0c0583ac;
P_0c0583ac: /* original 31a6, guest PC 0x0c0583ac */
if(!s->budget--) { s->failed_pc=0x0c0583acu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[10])!=0);
goto P_0c0583ae;
P_0c0583ae: /* original 66e5, guest PC 0x0c0583ae */
if(!s->budget--) { s->failed_pc=0x0c0583aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0583b0;
P_0c0583b0: /* original 344e, guest PC 0x0c0583b0 */
if(!s->budget--) { s->failed_pc=0x0c0583b0u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b2;
P_0c0583b2: /* original 4115, guest PC 0x0c0583b2 */
if(!s->budget--) { s->failed_pc=0x0c0583b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0583b4;
P_0c0583b4: /* original 344e, guest PC 0x0c0583b4 */
if(!s->budget--) { s->failed_pc=0x0c0583b4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583b6;
P_0c0583b6: /* original 234a, guest PC 0x0c0583b6 */
if(!s->budget--) { s->failed_pc=0x0c0583b6u; return 0; }
r[3]^=r[4];
goto P_0c0583b8;
P_0c0583b8: /* original 4608, guest PC 0x0c0583b8 */
if(!s->budget--) { s->failed_pc=0x0c0583b8u; return 0; }
r[6]<<=2;
goto P_0c0583ba;
P_0c0583ba: /* original 4608, guest PC 0x0c0583ba */
if(!s->budget--) { s->failed_pc=0x0c0583bau; return 0; }
r[6]<<=2;
goto P_0c0583bc;
P_0c0583bc: /* original 36dc, guest PC 0x0c0583bc */
if(!s->budget--) { s->failed_pc=0x0c0583bcu; return 0; }
r[6]+=r[13];
goto P_0c0583be;
P_0c0583be: /* original 5262, guest PC 0x0c0583be */
if(!s->budget--) { s->failed_pc=0x0c0583beu; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0583c0;
P_0c0583c0: /* original f868, guest PC 0x0c0583c0 */
if(!s->budget--) { s->failed_pc=0x0c0583c0u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c0583c2;
P_0c0583c2: /* original 32a6, guest PC 0x0c0583c2 */
if(!s->budget--) { s->failed_pc=0x0c0583c2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c0583c4;
P_0c0583c4: /* original 344e, guest PC 0x0c0583c4 */
if(!s->budget--) { s->failed_pc=0x0c0583c4u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583c6;
P_0c0583c6: /* original 4215, guest PC 0x0c0583c6 */
if(!s->budget--) { s->failed_pc=0x0c0583c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0583c8;
P_0c0583c8: /* original 344e, guest PC 0x0c0583c8 */
if(!s->budget--) { s->failed_pc=0x0c0583c8u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0583ca;
P_0c0583ca: /* original 234a, guest PC 0x0c0583ca */
if(!s->budget--) { s->failed_pc=0x0c0583cau; return 0; }
r[3]^=r[4];
goto P_0c0583cc;
P_0c0583cc: /* original 6043, guest PC 0x0c0583cc */
if(!s->budget--) { s->failed_pc=0x0c0583ccu; return 0; }
r[0]=r[4];
goto P_0c0583ce;
P_0c0583ce: /* original c810, guest PC 0x0c0583ce */
if(!s->budget--) { s->failed_pc=0x0c0583ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0583d0;
P_0c0583d0: /* original 0229, guest PC 0x0c0583d0 */
if(!s->budget--) { s->failed_pc=0x0c0583d0u; return 0; }
r[2]=r[17]&1u;
goto P_0c0583d2;
P_0c0583d2: /* original c92a, guest PC 0x0c0583d2 */
if(!s->budget--) { s->failed_pc=0x0c0583d2u; return 0; }
r[0]&=42u;
goto P_0c0583d4;
P_0c0583d4: /* original 882a, guest PC 0x0c0583d4 */
if(!s->budget--) { s->failed_pc=0x0c0583d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002au)!=0);
goto P_0c0583d6;
P_0c0583d6: /* original f64c, guest PC 0x0c0583d6 */
if(!s->budget--) { s->failed_pc=0x0c0583d6u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0583d8;
P_0c0583d8: /* original 8d54, guest PC 0x0c0583d8 */
if(!s->budget--) { s->failed_pc=0x0c0583d8u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
if(cond) { goto P_0c058484; }
goto P_0c0583dc;
P_0c0583da: /* original f681, guest PC 0x0c0583da */
if(!s->budget--) { s->failed_pc=0x0c0583dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0583dc;
P_0c0583dc: /* original f191, guest PC 0x0c0583dc */
if(!s->budget--) { s->failed_pc=0x0c0583dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c0583de;
P_0c0583de: /* original f791, guest PC 0x0c0583de */
if(!s->budget--) { s->failed_pc=0x0c0583deu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c0583e0;
P_0c0583e0: /* original f081, guest PC 0x0c0583e0 */
if(!s->budget--) { s->failed_pc=0x0c0583e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c0583e2;
P_0c0583e2: /* original f64d, guest PC 0x0c0583e2 */
if(!s->budget--) { s->failed_pc=0x0c0583e2u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583e4;
P_0c0583e4: /* original f612, guest PC 0x0c0583e4 */
if(!s->budget--) { s->failed_pc=0x0c0583e4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c0583e6;
P_0c0583e6: /* original e101, guest PC 0x0c0583e6 */
if(!s->budget--) { s->failed_pc=0x0c0583e6u; return 0; }
r[1]=0x00000001u;
goto P_0c0583e8;
P_0c0583e8: /* original f67e, guest PC 0x0c0583e8 */
if(!s->budget--) { s->failed_pc=0x0c0583e8u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c0583ea;
P_0c0583ea: /* original 2318, guest PC 0x0c0583ea */
if(!s->budget--) { s->failed_pc=0x0c0583eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c0583ec;
P_0c0583ec: /* original f08d, guest PC 0x0c0583ec */
if(!s->budget--) { s->failed_pc=0x0c0583ecu; return 0; }
fr[0]=0;
goto P_0c0583ee;
P_0c0583ee: /* original 8900, guest PC 0x0c0583ee */
if(!s->budget--) { s->failed_pc=0x0c0583eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0583f2; }
goto P_0c0583f0;
P_0c0583f0: /* original f64d, guest PC 0x0c0583f0 */
if(!s->budget--) { s->failed_pc=0x0c0583f0u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0583f2;
P_0c0583f2: /* original f605, guest PC 0x0c0583f2 */
if(!s->budget--) { s->failed_pc=0x0c0583f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c0583f4;
P_0c0583f4: /* original 8d46, guest PC 0x0c0583f4 */
if(!s->budget--) { s->failed_pc=0x0c0583f4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
if(cond) { goto P_0c058484; }
goto P_0c0583f8;
P_0c0583f6: /* original c82a, guest PC 0x0c0583f6 */
if(!s->budget--) { s->failed_pc=0x0c0583f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&42u)==0)!=0);
goto P_0c0583f8;
P_0c0583f8: /* original 232a, guest PC 0x0c0583f8 */
if(!s->budget--) { s->failed_pc=0x0c0583f8u; return 0; }
r[3]^=r[2];
goto P_0c0583fa;
P_0c0583fa: /* original 8b3a, guest PC 0x0c0583fa */
if(!s->budget--) { s->failed_pc=0x0c0583fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c058472; }
goto P_0c0583fc;
P_0c0583fc: /* original 62e3, guest PC 0x0c0583fc */
if(!s->budget--) { s->failed_pc=0x0c0583fcu; return 0; }
r[2]=r[14];
goto P_0c0583fe;
P_0c0583fe: /* original 72d0, guest PC 0x0c0583fe */
if(!s->budget--) { s->failed_pc=0x0c0583feu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058400;
P_0c058400: /* original b07e, guest PC 0x0c058400 */
if(!s->budget--) { s->failed_pc=0x0c058400u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058404u;
r[5]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058404u) { target=s->pc; goto dispatch; }
goto P_0c058404;
P_0c058402: /* original 6583, guest PC 0x0c058402 */
if(!s->budget--) { s->failed_pc=0x0c058402u; return 0; }
r[5]=r[8];
goto P_0c058404;
P_0c058404: /* original 0c83, guest PC 0x0c058404 */
if(!s->budget--) { s->failed_pc=0x0c058404u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058406;
P_0c058406: /* original 7c20, guest PC 0x0c058406 */
if(!s->budget--) { s->failed_pc=0x0c058406u; return 0; }
r[12]+=0x00000020u;
goto P_0c058408;
P_0c058408: /* original 62e3, guest PC 0x0c058408 */
if(!s->budget--) { s->failed_pc=0x0c058408u; return 0; }
r[2]=r[14];
goto P_0c05840a;
P_0c05840a: /* original 72e8, guest PC 0x0c05840a */
if(!s->budget--) { s->failed_pc=0x0c05840au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05840c;
P_0c05840c: /* original b078, guest PC 0x0c05840c */
if(!s->budget--) { s->failed_pc=0x0c05840cu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058410u;
r[5]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058410u) { target=s->pc; goto dispatch; }
goto P_0c058410;
P_0c05840e: /* original 6593, guest PC 0x0c05840e */
if(!s->budget--) { s->failed_pc=0x0c05840eu; return 0; }
r[5]=r[9];
goto P_0c058410;
P_0c058410: /* original 6893, guest PC 0x0c058410 */
if(!s->budget--) { s->failed_pc=0x0c058410u; return 0; }
r[8]=r[9];
goto P_0c058412;
P_0c058412: /* original b095, guest PC 0x0c058412 */
if(!s->budget--) { s->failed_pc=0x0c058412u; return 0; }
target=0x0c058540u; r[16]=code_base|0x0c058416u;
r[9]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058416u) { target=s->pc; goto dispatch; }
goto P_0c058416;
P_0c058414: /* original 6963, guest PC 0x0c058414 */
if(!s->budget--) { s->failed_pc=0x0c058414u; return 0; }
r[9]=r[6];
goto P_0c058416;
P_0c058416: /* original 4710, guest PC 0x0c058416 */
if(!s->budget--) { s->failed_pc=0x0c058416u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c058418;
P_0c058418: /* original 60e1, guest PC 0x0c058418 */
if(!s->budget--) { s->failed_pc=0x0c058418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05841a;
P_0c05841a: /* original 894f, guest PC 0x0c05841a */
if(!s->budget--) { s->failed_pc=0x0c05841au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584bc; }
goto P_0c05841c;
P_0c05841c: /* original 7e02, guest PC 0x0c05841c */
if(!s->budget--) { s->failed_pc=0x0c05841cu; return 0; }
r[14]+=0x00000002u;
goto P_0c05841e;
P_0c05841e: /* original 4008, guest PC 0x0c05841e */
if(!s->budget--) { s->failed_pc=0x0c05841eu; return 0; }
r[0]<<=2;
goto P_0c058420;
P_0c058420: /* original 4008, guest PC 0x0c058420 */
if(!s->budget--) { s->failed_pc=0x0c058420u; return 0; }
r[0]<<=2;
goto P_0c058422;
P_0c058422: /* original 6603, guest PC 0x0c058422 */
if(!s->budget--) { s->failed_pc=0x0c058422u; return 0; }
r[6]=r[0];
goto P_0c058424;
P_0c058424: /* original f8d6, guest PC 0x0c058424 */
if(!s->budget--) { s->failed_pc=0x0c058424u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c058426;
P_0c058426: /* original 36dc, guest PC 0x0c058426 */
if(!s->budget--) { s->failed_pc=0x0c058426u; return 0; }
r[6]+=r[13];
goto P_0c058428;
P_0c058428: /* original 5262, guest PC 0x0c058428 */
if(!s->budget--) { s->failed_pc=0x0c058428u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c05842a;
P_0c05842a: /* original f498, guest PC 0x0c05842a */
if(!s->budget--) { s->failed_pc=0x0c05842au; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c05842c;
P_0c05842c: /* original f088, guest PC 0x0c05842c */
if(!s->budget--) { s->failed_pc=0x0c05842cu; return 0; }
vf3_matrix_load(s,ram,0,r[8]);
goto P_0c05842e;
P_0c05842e: /* original 32a6, guest PC 0x0c05842e */
if(!s->budget--) { s->failed_pc=0x0c05842eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[10])!=0);
goto P_0c058430;
P_0c058430: /* original 344e, guest PC 0x0c058430 */
if(!s->budget--) { s->failed_pc=0x0c058430u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c058432;
P_0c058432: /* original f64c, guest PC 0x0c058432 */
if(!s->budget--) { s->failed_pc=0x0c058432u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c058434;
P_0c058434: /* original f681, guest PC 0x0c058434 */
if(!s->budget--) { s->failed_pc=0x0c058434u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c058436;
P_0c058436: /* original 4215, guest PC 0x0c058436 */
if(!s->budget--) { s->failed_pc=0x0c058436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c058438;
P_0c058438: /* original 344e, guest PC 0x0c058438 */
if(!s->budget--) { s->failed_pc=0x0c058438u; return 0; }
wide=(uint64_t)r[4]+r[4]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05843a;
P_0c05843a: /* original 234a, guest PC 0x0c05843a */
if(!s->budget--) { s->failed_pc=0x0c05843au; return 0; }
r[3]^=r[4];
goto P_0c05843c;
P_0c05843c: /* original 6043, guest PC 0x0c05843c */
if(!s->budget--) { s->failed_pc=0x0c05843cu; return 0; }
r[0]=r[4];
goto P_0c05843e;
P_0c05843e: /* original f191, guest PC 0x0c05843e */
if(!s->budget--) { s->failed_pc=0x0c05843eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'-');
goto P_0c058440;
P_0c058440: /* original c810, guest PC 0x0c058440 */
if(!s->budget--) { s->failed_pc=0x0c058440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c058442;
P_0c058442: /* original f791, guest PC 0x0c058442 */
if(!s->budget--) { s->failed_pc=0x0c058442u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c058444;
P_0c058444: /* original 0229, guest PC 0x0c058444 */
if(!s->budget--) { s->failed_pc=0x0c058444u; return 0; }
r[2]=r[17]&1u;
goto P_0c058446;
P_0c058446: /* original f081, guest PC 0x0c058446 */
if(!s->budget--) { s->failed_pc=0x0c058446u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'-');
goto P_0c058448;
P_0c058448: /* original f64d, guest PC 0x0c058448 */
if(!s->budget--) { s->failed_pc=0x0c058448u; return 0; }
fr[6]^=0x80000000u;
goto P_0c05844a;
P_0c05844a: /* original f612, guest PC 0x0c05844a */
if(!s->budget--) { s->failed_pc=0x0c05844au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c05844c;
P_0c05844c: /* original e101, guest PC 0x0c05844c */
if(!s->budget--) { s->failed_pc=0x0c05844cu; return 0; }
r[1]=0x00000001u;
goto P_0c05844e;
P_0c05844e: /* original f67e, guest PC 0x0c05844e */
if(!s->budget--) { s->failed_pc=0x0c05844eu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[7],fr[6],r[18]);
goto P_0c058450;
P_0c058450: /* original 2318, guest PC 0x0c058450 */
if(!s->budget--) { s->failed_pc=0x0c058450u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c058452;
P_0c058452: /* original f08d, guest PC 0x0c058452 */
if(!s->budget--) { s->failed_pc=0x0c058452u; return 0; }
fr[0]=0;
goto P_0c058454;
P_0c058454: /* original 8900, guest PC 0x0c058454 */
if(!s->budget--) { s->failed_pc=0x0c058454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c058458; }
goto P_0c058456;
P_0c058456: /* original f64d, guest PC 0x0c058456 */
if(!s->budget--) { s->failed_pc=0x0c058456u; return 0; }
fr[6]^=0x80000000u;
goto P_0c058458;
P_0c058458: /* original f605, guest PC 0x0c058458 */
if(!s->budget--) { s->failed_pc=0x0c058458u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[0]))!=0);
goto P_0c05845a;
P_0c05845a: /* original 232a, guest PC 0x0c05845a */
if(!s->budget--) { s->failed_pc=0x0c05845au; return 0; }
r[3]^=r[2];
goto P_0c05845c;
P_0c05845c: /* original 8d1f, guest PC 0x0c05845c */
if(!s->budget--) { s->failed_pc=0x0c05845cu; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
if(cond) { goto P_0c05849e; }
goto P_0c058460;
P_0c05845e: /* original c802, guest PC 0x0c05845e */
if(!s->budget--) { s->failed_pc=0x0c05845eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c058460;
P_0c058460: /* original 8b1b, guest PC 0x0c058460 */
if(!s->budget--) { s->failed_pc=0x0c058460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05849a; }
goto P_0c058462;
P_0c058462: /* original 6893, guest PC 0x0c058462 */
if(!s->budget--) { s->failed_pc=0x0c058462u; return 0; }
r[8]=r[9];
goto P_0c058464;
P_0c058464: /* original b06c, guest PC 0x0c058464 */
if(!s->budget--) { s->failed_pc=0x0c058464u; return 0; }
target=0x0c058540u; r[16]=code_base|0x0c058468u;
r[9]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058468u) { target=s->pc; goto dispatch; }
goto P_0c058468;
P_0c058466: /* original 6963, guest PC 0x0c058466 */
if(!s->budget--) { s->failed_pc=0x0c058466u; return 0; }
r[9]=r[6];
goto P_0c058468;
P_0c058468: /* original 4710, guest PC 0x0c058468 */
if(!s->budget--) { s->failed_pc=0x0c058468u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05846a;
P_0c05846a: /* original 60e1, guest PC 0x0c05846a */
if(!s->budget--) { s->failed_pc=0x0c05846au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c05846c;
P_0c05846c: /* original 8bd6, guest PC 0x0c05846c */
if(!s->budget--) { s->failed_pc=0x0c05846cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05841c; }
goto P_0c05846e;
P_0c05846e: /* original a025, guest PC 0x0c05846e */
if(!s->budget--) { s->failed_pc=0x0c05846eu; return 0; }
goto P_0c0584bc;
P_0c058470: /* original 0009, guest PC 0x0c058470 */
if(!s->budget--) { s->failed_pc=0x0c058470u; return 0; }
goto P_0c058472;
P_0c058472: /* original b179, guest PC 0x0c058472 */
if(!s->budget--) { s->failed_pc=0x0c058472u; return 0; }
target=0x0c058768u; r[16]=code_base|0x0c058476u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058476u) { target=s->pc; goto dispatch; }
goto P_0c058476;
P_0c058474: /* original 0009, guest PC 0x0c058474 */
if(!s->budget--) { s->failed_pc=0x0c058474u; return 0; }
goto P_0c058476;
P_0c058476: /* original 60c3, guest PC 0x0c058476 */
if(!s->budget--) { s->failed_pc=0x0c058476u; return 0; }
r[0]=r[12];
goto P_0c058478;
P_0c058478: /* original 4021, guest PC 0x0c058478 */
if(!s->budget--) { s->failed_pc=0x0c058478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c05847a;
P_0c05847a: /* original e200, guest PC 0x0c05847a */
if(!s->budget--) { s->failed_pc=0x0c05847au; return 0; }
r[2]=0x00000000u;
goto P_0c05847c;
P_0c05847c: /* original 2c02, guest PC 0x0c05847c */
if(!s->budget--) { s->failed_pc=0x0c05847cu; return 0; }
write(ram,r[12],r[0],4);
goto P_0c05847e;
P_0c05847e: /* original e500, guest PC 0x0c05847e */
if(!s->budget--) { s->failed_pc=0x0c05847eu; return 0; }
r[5]=0x00000000u;
goto P_0c058480;
P_0c058480: /* original 0c83, guest PC 0x0c058480 */
if(!s->budget--) { s->failed_pc=0x0c058480u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058482;
P_0c058482: /* original 7c20, guest PC 0x0c058482 */
if(!s->budget--) { s->failed_pc=0x0c058482u; return 0; }
r[12]+=0x00000020u;
goto P_0c058484;
P_0c058484: /* original 232a, guest PC 0x0c058484 */
if(!s->budget--) { s->failed_pc=0x0c058484u; return 0; }
r[3]^=r[2];
goto P_0c058486;
P_0c058486: /* original f04c, guest PC 0x0c058486 */
if(!s->budget--) { s->failed_pc=0x0c058486u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c058488;
P_0c058488: /* original 6893, guest PC 0x0c058488 */
if(!s->budget--) { s->failed_pc=0x0c058488u; return 0; }
r[8]=r[9];
goto P_0c05848a;
P_0c05848a: /* original f48c, guest PC 0x0c05848a */
if(!s->budget--) { s->failed_pc=0x0c05848au; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c05848c;
P_0c05848c: /* original 4710, guest PC 0x0c05848c */
if(!s->budget--) { s->failed_pc=0x0c05848cu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c05848e;
P_0c05848e: /* original 7e16, guest PC 0x0c05848e */
if(!s->budget--) { s->failed_pc=0x0c05848eu; return 0; }
r[14]+=0x00000016u;
goto P_0c058490;
P_0c058490: /* original 6963, guest PC 0x0c058490 */
if(!s->budget--) { s->failed_pc=0x0c058490u; return 0; }
r[9]=r[6];
goto P_0c058492;
P_0c058492: /* original 66e5, guest PC 0x0c058492 */
if(!s->budget--) { s->failed_pc=0x0c058492u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c058494;
P_0c058494: /* original 8b90, guest PC 0x0c058494 */
if(!s->budget--) { s->failed_pc=0x0c058494u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0583b8; }
goto P_0c058496;
P_0c058496: /* original a011, guest PC 0x0c058496 */
if(!s->budget--) { s->failed_pc=0x0c058496u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c058498: /* original 7efe, guest PC 0x0c058498 */
if(!s->budget--) { s->failed_pc=0x0c058498u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c05849a;
P_0c05849a: /* original b2df, guest PC 0x0c05849a */
if(!s->budget--) { s->failed_pc=0x0c05849au; return 0; }
target=0x0c058a5cu; r[16]=code_base|0x0c05849eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05849eu) { target=s->pc; goto dispatch; }
goto P_0c05849e;
P_0c05849c: /* original 0009, guest PC 0x0c05849c */
if(!s->budget--) { s->failed_pc=0x0c05849cu; return 0; }
goto P_0c05849e;
P_0c05849e: /* original 61c3, guest PC 0x0c05849e */
if(!s->budget--) { s->failed_pc=0x0c05849eu; return 0; }
r[1]=r[12];
goto P_0c0584a0;
P_0c0584a0: /* original 4121, guest PC 0x0c0584a0 */
if(!s->budget--) { s->failed_pc=0x0c0584a0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c0584a2;
P_0c0584a2: /* original f04c, guest PC 0x0c0584a2 */
if(!s->budget--) { s->failed_pc=0x0c0584a2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0584a4;
P_0c0584a4: /* original 6893, guest PC 0x0c0584a4 */
if(!s->budget--) { s->failed_pc=0x0c0584a4u; return 0; }
r[8]=r[9];
goto P_0c0584a6;
P_0c0584a6: /* original f48c, guest PC 0x0c0584a6 */
if(!s->budget--) { s->failed_pc=0x0c0584a6u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0584a8;
P_0c0584a8: /* original 2c12, guest PC 0x0c0584a8 */
if(!s->budget--) { s->failed_pc=0x0c0584a8u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0584aa;
P_0c0584aa: /* original 7e16, guest PC 0x0c0584aa */
if(!s->budget--) { s->failed_pc=0x0c0584aau; return 0; }
r[14]+=0x00000016u;
goto P_0c0584ac;
P_0c0584ac: /* original 0c83, guest PC 0x0c0584ac */
if(!s->budget--) { s->failed_pc=0x0c0584acu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584ae;
P_0c0584ae: /* original 4710, guest PC 0x0c0584ae */
if(!s->budget--) { s->failed_pc=0x0c0584aeu; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0584b0;
P_0c0584b0: /* original 6963, guest PC 0x0c0584b0 */
if(!s->budget--) { s->failed_pc=0x0c0584b0u; return 0; }
r[9]=r[6];
goto P_0c0584b2;
P_0c0584b2: /* original 7c20, guest PC 0x0c0584b2 */
if(!s->budget--) { s->failed_pc=0x0c0584b2u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584b4;
P_0c0584b4: /* original 8f80, guest PC 0x0c0584b4 */
if(!s->budget--) { s->failed_pc=0x0c0584b4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
if(!cond) { goto P_0c0583b8; }
goto P_0c0584b8;
P_0c0584b6: /* original 66e5, guest PC 0x0c0584b6 */
if(!s->budget--) { s->failed_pc=0x0c0584b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[6]=tmp;
goto P_0c0584b8;
P_0c0584b8: /* original a007, guest PC 0x0c0584b8 */
if(!s->budget--) { s->failed_pc=0x0c0584b8u; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584ca;
P_0c0584ba: /* original 7efe, guest PC 0x0c0584ba */
if(!s->budget--) { s->failed_pc=0x0c0584bau; return 0; }
r[14]+=0xfffffffeu;
goto P_0c0584bc;
P_0c0584bc: /* original 2558, guest PC 0x0c0584bc */
if(!s->budget--) { s->failed_pc=0x0c0584bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0584be;
P_0c0584be: /* original 8904, guest PC 0x0c0584be */
if(!s->budget--) { s->failed_pc=0x0c0584beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584ca; }
goto P_0c0584c0;
P_0c0584c0: /* original 60c3, guest PC 0x0c0584c0 */
if(!s->budget--) { s->failed_pc=0x0c0584c0u; return 0; }
r[0]=r[12];
goto P_0c0584c2;
P_0c0584c2: /* original 4021, guest PC 0x0c0584c2 */
if(!s->budget--) { s->failed_pc=0x0c0584c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c0584c4;
P_0c0584c4: /* original 2c02, guest PC 0x0c0584c4 */
if(!s->budget--) { s->failed_pc=0x0c0584c4u; return 0; }
write(ram,r[12],r[0],4);
goto P_0c0584c6;
P_0c0584c6: /* original 0c83, guest PC 0x0c0584c6 */
if(!s->budget--) { s->failed_pc=0x0c0584c6u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0584c8;
P_0c0584c8: /* original 7c20, guest PC 0x0c0584c8 */
if(!s->budget--) { s->failed_pc=0x0c0584c8u; return 0; }
r[12]+=0x00000020u;
goto P_0c0584ca;
P_0c0584ca: /* original 4b10, guest PC 0x0c0584ca */
if(!s->budget--) { s->failed_pc=0x0c0584cau; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0584cc;
P_0c0584cc: /* original 8901, guest PC 0x0c0584cc */
if(!s->budget--) { s->failed_pc=0x0c0584ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0584d2; }
goto P_0c0584ce;
P_0c0584ce: /* original af55, guest PC 0x0c0584ce */
if(!s->budget--) { s->failed_pc=0x0c0584ceu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c05837c;
P_0c0584d0: /* original 67e5, guest PC 0x0c0584d0 */
if(!s->budget--) { s->failed_pc=0x0c0584d0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[7]=tmp;
goto P_0c0584d2;
P_0c0584d2: /* original 01b2, guest PC 0x0c0584d2 */
if(!s->budget--) { s->failed_pc=0x0c0584d2u; return 0; }
if(!s->bank_known) goto unsupported;
r[1]=s->bank[3];
goto P_0c0584d4;
P_0c0584d4: /* original 21c2, guest PC 0x0c0584d4 */
if(!s->budget--) { s->failed_pc=0x0c0584d4u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c0584d6;
P_0c0584d6: /* original f2fc, guest PC 0x0c0584d6 */
if(!s->budget--) { s->failed_pc=0x0c0584d6u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0584d8;
P_0c0584d8: /* original f3fd, guest PC 0x0c0584d8 */
if(!s->budget--) { s->failed_pc=0x0c0584d8u; return 0; }
r[18]^=0x100000u;
goto P_0c0584da;
P_0c0584da: /* original 64e3, guest PC 0x0c0584da */
if(!s->budget--) { s->failed_pc=0x0c0584dau; return 0; }
r[4]=r[14];
goto P_0c0584dc;
P_0c0584dc: /* original 4f26, guest PC 0x0c0584dc */
if(!s->budget--) { s->failed_pc=0x0c0584dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0584de;
P_0c0584de: /* original 000b, guest PC 0x0c0584de */
if(!s->budget--) { s->failed_pc=0x0c0584deu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0584e0: /* original 6ef6, guest PC 0x0c0584e0 */
if(!s->budget--) { s->failed_pc=0x0c0584e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0584e2u,s,ram);
P_0c058780: /* original 4f22, guest PC 0x0c058780 */
if(!s->budget--) { s->failed_pc=0x0c058780u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058782;
P_0c058782: /* original a048, guest PC 0x0c058782 */
if(!s->budget--) { s->failed_pc=0x0c058782u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058816;
P_0c058784: /* original 4f22, guest PC 0x0c058784 */
if(!s->budget--) { s->failed_pc=0x0c058784u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058786;
P_0c058786: /* original a0c9, guest PC 0x0c058786 */
if(!s->budget--) { s->failed_pc=0x0c058786u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05891c;
P_0c058788: /* original 4f22, guest PC 0x0c058788 */
if(!s->budget--) { s->failed_pc=0x0c058788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c05878au,s,ram);
P_0c05878c: /* original 4f22, guest PC 0x0c05878c */
if(!s->budget--) { s->failed_pc=0x0c05878cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878e;
P_0c05878e: /* original a0af, guest PC 0x0c05878e */
if(!s->budget--) { s->failed_pc=0x0c05878eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0588f0;
P_0c058790: /* original 4f22, guest PC 0x0c058790 */
if(!s->budget--) { s->failed_pc=0x0c058790u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c058792u,s,ram);
P_0c058816: /* original bf21, guest PC 0x0c058816 */
if(!s->budget--) { s->failed_pc=0x0c058816u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c05881au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05881au) { target=s->pc; goto dispatch; }
goto P_0c05881a;
P_0c058818: /* original 65e3, guest PC 0x0c058818 */
if(!s->budget--) { s->failed_pc=0x0c058818u; return 0; }
r[5]=r[14];
goto P_0c05881a;
P_0c05881a: /* original 2f06, guest PC 0x0c05881a */
if(!s->budget--) { s->failed_pc=0x0c05881au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05881c;
P_0c05881c: /* original e008, guest PC 0x0c05881c */
if(!s->budget--) { s->failed_pc=0x0c05881cu; return 0; }
r[0]=0x00000008u;
goto P_0c05881e;
P_0c05881e: /* original f086, guest PC 0x0c05881e */
if(!s->budget--) { s->failed_pc=0x0c05881eu; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058820;
P_0c058820: /* original 62e3, guest PC 0x0c058820 */
if(!s->budget--) { s->failed_pc=0x0c058820u; return 0; }
r[2]=r[14];
goto P_0c058822;
P_0c058822: /* original 72e8, guest PC 0x0c058822 */
if(!s->budget--) { s->failed_pc=0x0c058822u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058824;
P_0c058824: /* original 6593, guest PC 0x0c058824 */
if(!s->budget--) { s->failed_pc=0x0c058824u; return 0; }
r[5]=r[9];
goto P_0c058826;
P_0c058826: /* original f79d, guest PC 0x0c058826 */
if(!s->budget--) { s->failed_pc=0x0c058826u; return 0; }
fr[7]=0x3f800000u;
goto P_0c058828;
P_0c058828: /* original be6a, guest PC 0x0c058828 */
if(!s->budget--) { s->failed_pc=0x0c058828u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05882cu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05882cu) { target=s->pc; goto dispatch; }
goto P_0c05882c;
P_0c05882a: /* original f703, guest PC 0x0c05882a */
if(!s->budget--) { s->failed_pc=0x0c05882au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c05882c;
P_0c05882c: /* original 0c83, guest PC 0x0c05882c */
if(!s->budget--) { s->failed_pc=0x0c05882cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05882e;
P_0c05882e: /* original 7c20, guest PC 0x0c05882e */
if(!s->budget--) { s->failed_pc=0x0c05882eu; return 0; }
r[12]+=0x00000020u;
goto P_0c058830;
P_0c058830: /* original f80c, guest PC 0x0c058830 */
if(!s->budget--) { s->failed_pc=0x0c058830u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058832;
P_0c058832: /* original fa9d, guest PC 0x0c058832 */
if(!s->budget--) { s->failed_pc=0x0c058832u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058834;
P_0c058834: /* original fa23, guest PC 0x0c058834 */
if(!s->budget--) { s->failed_pc=0x0c058834u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058836;
P_0c058836: /* original fc4c, guest PC 0x0c058836 */
if(!s->budget--) { s->failed_pc=0x0c058836u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c058838;
P_0c058838: /* original 62e3, guest PC 0x0c058838 */
if(!s->budget--) { s->failed_pc=0x0c058838u; return 0; }
r[2]=r[14];
goto P_0c05883a;
P_0c05883a: /* original be61, guest PC 0x0c05883a */
if(!s->budget--) { s->failed_pc=0x0c05883au; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05883eu;
r[5]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05883eu) { target=s->pc; goto dispatch; }
goto P_0c05883e;
P_0c05883c: /* original 6563, guest PC 0x0c05883c */
if(!s->budget--) { s->failed_pc=0x0c05883cu; return 0; }
r[5]=r[6];
goto P_0c05883e;
P_0c05883e: /* original 0c83, guest PC 0x0c05883e */
if(!s->budget--) { s->failed_pc=0x0c05883eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058840;
P_0c058840: /* original fb9d, guest PC 0x0c058840 */
if(!s->budget--) { s->failed_pc=0x0c058840u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058842;
P_0c058842: /* original 62e3, guest PC 0x0c058842 */
if(!s->budget--) { s->failed_pc=0x0c058842u; return 0; }
r[2]=r[14];
goto P_0c058844;
P_0c058844: /* original fb23, guest PC 0x0c058844 */
if(!s->budget--) { s->failed_pc=0x0c058844u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058846;
P_0c058846: /* original 72d0, guest PC 0x0c058846 */
if(!s->budget--) { s->failed_pc=0x0c058846u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058848;
P_0c058848: /* original f288, guest PC 0x0c058848 */
if(!s->budget--) { s->failed_pc=0x0c058848u; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c05884a;
P_0c05884a: /* original 6125, guest PC 0x0c05884a */
if(!s->budget--) { s->failed_pc=0x0c05884au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05884c;
P_0c05884c: /* original f3fd, guest PC 0x0c05884c */
if(!s->budget--) { s->failed_pc=0x0c05884cu; return 0; }
r[18]^=0x100000u;
goto P_0c05884e;
P_0c05884e: /* original 6221, guest PC 0x0c05884e */
if(!s->budget--) { s->failed_pc=0x0c05884eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058850;
P_0c058850: /* original f60c, guest PC 0x0c058850 */
if(!s->budget--) { s->failed_pc=0x0c058850u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058852: /* original c607, guest PC 0x0c058852 */
if(!s->budget--) { s->failed_pc=0x0c058852u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058854;
P_0c058854: /* original f8a2, guest PC 0x0c058854 */
if(!s->budget--) { s->failed_pc=0x0c058854u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058856;
P_0c058856: /* original f9a2, guest PC 0x0c058856 */
if(!s->budget--) { s->failed_pc=0x0c058856u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058858;
P_0c058858: /* original f272, guest PC 0x0c058858 */
if(!s->budget--) { s->failed_pc=0x0c058858u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c05885a;
P_0c05885a: /* original f372, guest PC 0x0c05885a */
if(!s->budget--) { s->failed_pc=0x0c05885au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c05885c;
P_0c05885c: /* original 405a, guest PC 0x0c05885c */
if(!s->budget--) { s->failed_pc=0x0c05885cu; return 0; }
r[53]=r[0];
goto P_0c05885e;
P_0c05885e: /* original fa71, guest PC 0x0c05885e */
if(!s->budget--) { s->failed_pc=0x0c05885eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'-');
goto P_0c058860;
P_0c058860: /* original f00d, guest PC 0x0c058860 */
if(!s->budget--) { s->failed_pc=0x0c058860u; return 0; }
fr[0]=r[53];
goto P_0c058862;
P_0c058862: /* original f071, guest PC 0x0c058862 */
if(!s->budget--) { s->failed_pc=0x0c058862u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[7],r[18],'-');
goto P_0c058864;
P_0c058864: /* original f6b2, guest PC 0x0c058864 */
if(!s->budget--) { s->failed_pc=0x0c058864u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c058866;
P_0c058866: /* original f1b2, guest PC 0x0c058866 */
if(!s->budget--) { s->failed_pc=0x0c058866u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c058868;
P_0c058868: /* original fb71, guest PC 0x0c058868 */
if(!s->budget--) { s->failed_pc=0x0c058868u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c05886a;
P_0c05886a: /* original ff0b, guest PC 0x0c05886a */
if(!s->budget--) { s->failed_pc=0x0c05886au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c05886c;
P_0c05886c: /* original f0a3, guest PC 0x0c05886c */
if(!s->budget--) { s->failed_pc=0x0c05886cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'/');
goto P_0c05886e;
P_0c05886e: /* original f821, guest PC 0x0c05886e */
if(!s->budget--) { s->failed_pc=0x0c05886eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c058870;
P_0c058870: /* original f931, guest PC 0x0c058870 */
if(!s->budget--) { s->failed_pc=0x0c058870u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c058872;
P_0c058872: /* original 425a, guest PC 0x0c058872 */
if(!s->budget--) { s->failed_pc=0x0c058872u; return 0; }
r[53]=r[2];
goto P_0c058874;
P_0c058874: /* original fe2d, guest PC 0x0c058874 */
if(!s->budget--) { s->failed_pc=0x0c058874u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058876;
P_0c058876: /* original 415a, guest PC 0x0c058876 */
if(!s->budget--) { s->failed_pc=0x0c058876u; return 0; }
r[53]=r[1];
goto P_0c058878;
P_0c058878: /* original fa2d, guest PC 0x0c058878 */
if(!s->budget--) { s->failed_pc=0x0c058878u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c05887a;
P_0c05887a: /* original f621, guest PC 0x0c05887a */
if(!s->budget--) { s->failed_pc=0x0c05887au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c05887c;
P_0c05887c: /* original 60f6, guest PC 0x0c05887c */
if(!s->budget--) { s->failed_pc=0x0c05887cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c05887e;
P_0c05887e: /* original f131, guest PC 0x0c05887e */
if(!s->budget--) { s->failed_pc=0x0c05887eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c058880;
P_0c058880: /* original 61f6, guest PC 0x0c058880 */
if(!s->budget--) { s->failed_pc=0x0c058880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058882;
P_0c058882: /* original fef2, guest PC 0x0c058882 */
if(!s->budget--) { s->failed_pc=0x0c058882u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058884;
P_0c058884: /* original faf2, guest PC 0x0c058884 */
if(!s->budget--) { s->failed_pc=0x0c058884u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c058886;
P_0c058886: /* original 4f26, guest PC 0x0c058886 */
if(!s->budget--) { s->failed_pc=0x0c058886u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058888;
P_0c058888: /* original fde1, guest PC 0x0c058888 */
if(!s->budget--) { s->failed_pc=0x0c058888u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c05888a;
P_0c05888a: /* original fca1, guest PC 0x0c05888a */
if(!s->budget--) { s->failed_pc=0x0c05888au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[10],r[18],'-');
goto P_0c05888c;
P_0c05888c: /* original 405a, guest PC 0x0c05888c */
if(!s->budget--) { s->failed_pc=0x0c05888cu; return 0; }
r[53]=r[0];
goto P_0c05888e;
P_0c05888e: /* original f5e1, guest PC 0x0c05888e */
if(!s->budget--) { s->failed_pc=0x0c05888eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c058890;
P_0c058890: /* original 7c3c, guest PC 0x0c058890 */
if(!s->budget--) { s->failed_pc=0x0c058890u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058892;
P_0c058892: /* original f4a1, guest PC 0x0c058892 */
if(!s->budget--) { s->failed_pc=0x0c058892u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c058894;
P_0c058894: /* original ff3c, guest PC 0x0c058894 */
if(!s->budget--) { s->failed_pc=0x0c058894u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c058896;
P_0c058896: /* original ff9e, guest PC 0x0c058896 */
if(!s->budget--) { s->failed_pc=0x0c058896u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c058898;
P_0c058898: /* original f92c, guest PC 0x0c058898 */
if(!s->budget--) { s->failed_pc=0x0c058898u; return 0; }
vf3_matrix_move(s,9,2);
goto P_0c05889a;
P_0c05889a: /* original f98e, guest PC 0x0c05889a */
if(!s->budget--) { s->failed_pc=0x0c05889au; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c05889c;
P_0c05889c: /* original f8ec, guest PC 0x0c05889c */
if(!s->budget--) { s->failed_pc=0x0c05889cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c05889e;
P_0c05889e: /* original f8de, guest PC 0x0c05889e */
if(!s->budget--) { s->failed_pc=0x0c05889eu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c0588a0;
P_0c0588a0: /* original fdac, guest PC 0x0c0588a0 */
if(!s->budget--) { s->failed_pc=0x0c0588a0u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c0588a2;
P_0c0588a2: /* original fdce, guest PC 0x0c0588a2 */
if(!s->budget--) { s->failed_pc=0x0c0588a2u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0588a4;
P_0c0588a4: /* original f00d, guest PC 0x0c0588a4 */
if(!s->budget--) { s->failed_pc=0x0c0588a4u; return 0; }
fr[0]=r[53];
goto P_0c0588a6;
P_0c0588a6: /* original f0b3, guest PC 0x0c0588a6 */
if(!s->budget--) { s->failed_pc=0x0c0588a6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0588a8;
P_0c0588a8: /* original 4a5a, guest PC 0x0c0588a8 */
if(!s->budget--) { s->failed_pc=0x0c0588a8u; return 0; }
r[53]=r[10];
goto P_0c0588aa;
P_0c0588aa: /* original fc0d, guest PC 0x0c0588aa */
if(!s->budget--) { s->failed_pc=0x0c0588aau; return 0; }
fr[12]=r[53];
goto P_0c0588ac;
P_0c0588ac: /* original ffc2, guest PC 0x0c0588ac */
if(!s->budget--) { s->failed_pc=0x0c0588acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0588ae;
P_0c0588ae: /* original c618, guest PC 0x0c0588ae */
if(!s->budget--) { s->failed_pc=0x0c0588aeu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c0588b0;
P_0c0588b0: /* original f9c2, guest PC 0x0c0588b0 */
if(!s->budget--) { s->failed_pc=0x0c0588b0u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0588b2;
P_0c0588b2: /* original 2c12, guest PC 0x0c0588b2 */
if(!s->budget--) { s->failed_pc=0x0c0588b2u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0588b4;
P_0c0588b4: /* original 2c06, guest PC 0x0c0588b4 */
if(!s->budget--) { s->failed_pc=0x0c0588b4u; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588b6;
P_0c0588b6: /* original fc8b, guest PC 0x0c0588b6 */
if(!s->budget--) { s->failed_pc=0x0c0588b6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0588b8;
P_0c0588b8: /* original fcdb, guest PC 0x0c0588b8 */
if(!s->budget--) { s->failed_pc=0x0c0588b8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c0588ba;
P_0c0588ba: /* original 2ca6, guest PC 0x0c0588ba */
if(!s->budget--) { s->failed_pc=0x0c0588bau; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588bc;
P_0c0588bc: /* original fcfb, guest PC 0x0c0588bc */
if(!s->budget--) { s->failed_pc=0x0c0588bcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0588be;
P_0c0588be: /* original fc9b, guest PC 0x0c0588be */
if(!s->budget--) { s->failed_pc=0x0c0588beu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0588c0;
P_0c0588c0: /* original 2cc6, guest PC 0x0c0588c0 */
if(!s->budget--) { s->failed_pc=0x0c0588c0u; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588c2;
P_0c0588c2: /* original 0c83, guest PC 0x0c0588c2 */
if(!s->budget--) { s->failed_pc=0x0c0588c2u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0588c4;
P_0c0588c4: /* original 7c2c, guest PC 0x0c0588c4 */
if(!s->budget--) { s->failed_pc=0x0c0588c4u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0588c6;
P_0c0588c6: /* original f31e, guest PC 0x0c0588c6 */
if(!s->budget--) { s->failed_pc=0x0c0588c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0588c8;
P_0c0588c8: /* original 2ca2, guest PC 0x0c0588c8 */
if(!s->budget--) { s->failed_pc=0x0c0588c8u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c0588ca;
P_0c0588ca: /* original f26e, guest PC 0x0c0588ca */
if(!s->budget--) { s->failed_pc=0x0c0588cau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0588cc;
P_0c0588cc: /* original 7c04, guest PC 0x0c0588cc */
if(!s->budget--) { s->failed_pc=0x0c0588ccu; return 0; }
r[12]+=0x00000004u;
goto P_0c0588ce;
P_0c0588ce: /* original fe5e, guest PC 0x0c0588ce */
if(!s->budget--) { s->failed_pc=0x0c0588ceu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[5],fr[14],r[18]);
goto P_0c0588d0;
P_0c0588d0: /* original 1c02, guest PC 0x0c0588d0 */
if(!s->budget--) { s->failed_pc=0x0c0588d0u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c0588d2;
P_0c0588d2: /* original fa4e, guest PC 0x0c0588d2 */
if(!s->budget--) { s->failed_pc=0x0c0588d2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[4],fr[10],r[18]);
goto P_0c0588d4;
P_0c0588d4: /* original e004, guest PC 0x0c0588d4 */
if(!s->budget--) { s->failed_pc=0x0c0588d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0588d6;
P_0c0588d6: /* original f3c2, guest PC 0x0c0588d6 */
if(!s->budget--) { s->failed_pc=0x0c0588d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0588d8;
P_0c0588d8: /* original 1c13, guest PC 0x0c0588d8 */
if(!s->budget--) { s->failed_pc=0x0c0588d8u; return 0; }
write(ram,r[12]+12,r[1],4);
goto P_0c0588da;
P_0c0588da: /* original f2c2, guest PC 0x0c0588da */
if(!s->budget--) { s->failed_pc=0x0c0588dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'*');
goto P_0c0588dc;
P_0c0588dc: /* original fce7, guest PC 0x0c0588dc */
if(!s->budget--) { s->failed_pc=0x0c0588dcu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c0588de;
P_0c0588de: /* original fcaa, guest PC 0x0c0588de */
if(!s->budget--) { s->failed_pc=0x0c0588deu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0588e0;
P_0c0588e0: /* original 7cf8, guest PC 0x0c0588e0 */
if(!s->budget--) { s->failed_pc=0x0c0588e0u; return 0; }
r[12]+=0xfffffff8u;
goto P_0c0588e2;
P_0c0588e2: /* original fc3a, guest PC 0x0c0588e2 */
if(!s->budget--) { s->failed_pc=0x0c0588e2u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c0588e4;
P_0c0588e4: /* original fc2b, guest PC 0x0c0588e4 */
if(!s->budget--) { s->failed_pc=0x0c0588e4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c0588e6;
P_0c0588e6: /* original f3fd, guest PC 0x0c0588e6 */
if(!s->budget--) { s->failed_pc=0x0c0588e6u; return 0; }
r[18]^=0x100000u;
goto P_0c0588e8;
P_0c0588e8: /* original 7cfc, guest PC 0x0c0588e8 */
if(!s->budget--) { s->failed_pc=0x0c0588e8u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c0588ea;
P_0c0588ea: /* original f498, guest PC 0x0c0588ea */
if(!s->budget--) { s->failed_pc=0x0c0588eau; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c0588ec;
P_0c0588ec: /* original 000b, guest PC 0x0c0588ec */
if(!s->budget--) { s->failed_pc=0x0c0588ecu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c0588ee: /* original f868, guest PC 0x0c0588ee */
if(!s->budget--) { s->failed_pc=0x0c0588eeu; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
goto P_0c0588f0;
P_0c0588f0: /* original beb4, guest PC 0x0c0588f0 */
if(!s->budget--) { s->failed_pc=0x0c0588f0u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c0588f4u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0588f4u) { target=s->pc; goto dispatch; }
goto P_0c0588f4;
P_0c0588f2: /* original 65e3, guest PC 0x0c0588f2 */
if(!s->budget--) { s->failed_pc=0x0c0588f2u; return 0; }
r[5]=r[14];
goto P_0c0588f4;
P_0c0588f4: /* original 2f06, guest PC 0x0c0588f4 */
if(!s->budget--) { s->failed_pc=0x0c0588f4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0588f6;
P_0c0588f6: /* original e008, guest PC 0x0c0588f6 */
if(!s->budget--) { s->failed_pc=0x0c0588f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0588f8;
P_0c0588f8: /* original f096, guest PC 0x0c0588f8 */
if(!s->budget--) { s->failed_pc=0x0c0588f8u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0588fa;
P_0c0588fa: /* original 62e3, guest PC 0x0c0588fa */
if(!s->budget--) { s->failed_pc=0x0c0588fau; return 0; }
r[2]=r[14];
goto P_0c0588fc;
P_0c0588fc: /* original 72d0, guest PC 0x0c0588fc */
if(!s->budget--) { s->failed_pc=0x0c0588fcu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0588fe;
P_0c0588fe: /* original 6583, guest PC 0x0c0588fe */
if(!s->budget--) { s->failed_pc=0x0c0588feu; return 0; }
r[5]=r[8];
goto P_0c058900;
P_0c058900: /* original fb9d, guest PC 0x0c058900 */
if(!s->budget--) { s->failed_pc=0x0c058900u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058902;
P_0c058902: /* original bdfd, guest PC 0x0c058902 */
if(!s->budget--) { s->failed_pc=0x0c058902u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058906u;
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058906u) { target=s->pc; goto dispatch; }
goto P_0c058906;
P_0c058904: /* original fb03, guest PC 0x0c058904 */
if(!s->budget--) { s->failed_pc=0x0c058904u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
goto P_0c058906;
P_0c058906: /* original fa9d, guest PC 0x0c058906 */
if(!s->budget--) { s->failed_pc=0x0c058906u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058908;
P_0c058908: /* original f80c, guest PC 0x0c058908 */
if(!s->budget--) { s->failed_pc=0x0c058908u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c05890a;
P_0c05890a: /* original fa23, guest PC 0x0c05890a */
if(!s->budget--) { s->failed_pc=0x0c05890au; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c05890c;
P_0c05890c: /* original 62e3, guest PC 0x0c05890c */
if(!s->budget--) { s->failed_pc=0x0c05890cu; return 0; }
r[2]=r[14];
goto P_0c05890e;
P_0c05890e: /* original 0c83, guest PC 0x0c05890e */
if(!s->budget--) { s->failed_pc=0x0c05890eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058910;
P_0c058910: /* original 72e8, guest PC 0x0c058910 */
if(!s->budget--) { s->failed_pc=0x0c058910u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058912;
P_0c058912: /* original 6125, guest PC 0x0c058912 */
if(!s->budget--) { s->failed_pc=0x0c058912u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058914;
P_0c058914: /* original 6221, guest PC 0x0c058914 */
if(!s->budget--) { s->failed_pc=0x0c058914u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058916;
P_0c058916: /* original f698, guest PC 0x0c058916 */
if(!s->budget--) { s->failed_pc=0x0c058916u; return 0; }
vf3_matrix_load(s,ram,6,r[9]);
goto P_0c058918;
P_0c058918: /* original a015, guest PC 0x0c058918 */
if(!s->budget--) { s->failed_pc=0x0c058918u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c058946;
P_0c05891a: /* original f268, guest PC 0x0c05891a */
if(!s->budget--) { s->failed_pc=0x0c05891au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c05891c;
P_0c05891c: /* original be9e, guest PC 0x0c05891c */
if(!s->budget--) { s->failed_pc=0x0c05891cu; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c058920u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058920u) { target=s->pc; goto dispatch; }
goto P_0c058920;
P_0c05891e: /* original 65e3, guest PC 0x0c05891e */
if(!s->budget--) { s->failed_pc=0x0c05891eu; return 0; }
r[5]=r[14];
goto P_0c058920;
P_0c058920: /* original 2f06, guest PC 0x0c058920 */
if(!s->budget--) { s->failed_pc=0x0c058920u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c058922;
P_0c058922: /* original e008, guest PC 0x0c058922 */
if(!s->budget--) { s->failed_pc=0x0c058922u; return 0; }
r[0]=0x00000008u;
goto P_0c058924;
P_0c058924: /* original f086, guest PC 0x0c058924 */
if(!s->budget--) { s->failed_pc=0x0c058924u; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058926;
P_0c058926: /* original 62e3, guest PC 0x0c058926 */
if(!s->budget--) { s->failed_pc=0x0c058926u; return 0; }
r[2]=r[14];
goto P_0c058928;
P_0c058928: /* original 72e8, guest PC 0x0c058928 */
if(!s->budget--) { s->failed_pc=0x0c058928u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05892a;
P_0c05892a: /* original 6593, guest PC 0x0c05892a */
if(!s->budget--) { s->failed_pc=0x0c05892au; return 0; }
r[5]=r[9];
goto P_0c05892c;
P_0c05892c: /* original fb9d, guest PC 0x0c05892c */
if(!s->budget--) { s->failed_pc=0x0c05892cu; return 0; }
fr[11]=0x3f800000u;
goto P_0c05892e;
P_0c05892e: /* original bde7, guest PC 0x0c05892e */
if(!s->budget--) { s->failed_pc=0x0c05892eu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058932u;
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058932u) { target=s->pc; goto dispatch; }
goto P_0c058932;
P_0c058930: /* original fb03, guest PC 0x0c058930 */
if(!s->budget--) { s->failed_pc=0x0c058930u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
goto P_0c058932;
P_0c058932: /* original fa9d, guest PC 0x0c058932 */
if(!s->budget--) { s->failed_pc=0x0c058932u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058934;
P_0c058934: /* original f80c, guest PC 0x0c058934 */
if(!s->budget--) { s->failed_pc=0x0c058934u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058936;
P_0c058936: /* original fa23, guest PC 0x0c058936 */
if(!s->budget--) { s->failed_pc=0x0c058936u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058938;
P_0c058938: /* original 62e3, guest PC 0x0c058938 */
if(!s->budget--) { s->failed_pc=0x0c058938u; return 0; }
r[2]=r[14];
goto P_0c05893a;
P_0c05893a: /* original 0c83, guest PC 0x0c05893a */
if(!s->budget--) { s->failed_pc=0x0c05893au; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05893c;
P_0c05893c: /* original 72d0, guest PC 0x0c05893c */
if(!s->budget--) { s->failed_pc=0x0c05893cu; return 0; }
r[2]+=0xffffffd0u;
goto P_0c05893e;
P_0c05893e: /* original 6125, guest PC 0x0c05893e */
if(!s->budget--) { s->failed_pc=0x0c05893eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c058940;
P_0c058940: /* original 6221, guest PC 0x0c058940 */
if(!s->budget--) { s->failed_pc=0x0c058940u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058942;
P_0c058942: /* original f688, guest PC 0x0c058942 */
if(!s->budget--) { s->failed_pc=0x0c058942u; return 0; }
vf3_matrix_load(s,ram,6,r[8]);
goto P_0c058944;
P_0c058944: /* original f268, guest PC 0x0c058944 */
if(!s->budget--) { s->failed_pc=0x0c058944u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c058946;
P_0c058946: /* original f3fd, guest PC 0x0c058946 */
if(!s->budget--) { s->failed_pc=0x0c058946u; return 0; }
r[18]^=0x100000u;
goto P_0c058948;
P_0c058948: /* original 415a, guest PC 0x0c058948 */
if(!s->budget--) { s->failed_pc=0x0c058948u; return 0; }
r[53]=r[1];
goto P_0c05894a;
P_0c05894a: /* original e008, guest PC 0x0c05894a */
if(!s->budget--) { s->failed_pc=0x0c05894au; return 0; }
r[0]=0x00000008u;
goto P_0c05894c;
P_0c05894c: /* original fc2d, guest PC 0x0c05894c */
if(!s->budget--) { s->failed_pc=0x0c05894cu; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c05894e;
P_0c05894e: /* original 425a, guest PC 0x0c05894e */
if(!s->budget--) { s->failed_pc=0x0c05894eu; return 0; }
r[53]=r[2];
goto P_0c058950;
P_0c058950: /* original fd2d, guest PC 0x0c058950 */
if(!s->budget--) { s->failed_pc=0x0c058950u; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c058952;
P_0c058952: /* original fe66, guest PC 0x0c058952 */
if(!s->budget--) { s->failed_pc=0x0c058952u; return 0; }
vf3_matrix_load(s,ram,14,r[6]+r[0]);
goto P_0c058954;
P_0c058954: /* original 62e3, guest PC 0x0c058954 */
if(!s->budget--) { s->failed_pc=0x0c058954u; return 0; }
r[2]=r[14];
goto P_0c058956;
P_0c058956: /* original c607, guest PC 0x0c058956 */
if(!s->budget--) { s->failed_pc=0x0c058956u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058958;
P_0c058958: /* original f6b2, guest PC 0x0c058958 */
if(!s->budget--) { s->failed_pc=0x0c058958u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c05895a;
P_0c05895a: /* original f7b2, guest PC 0x0c05895a */
if(!s->budget--) { s->failed_pc=0x0c05895au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c05895c;
P_0c05895c: /* original fcf2, guest PC 0x0c05895c */
if(!s->budget--) { s->failed_pc=0x0c05895cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c05895e;
P_0c05895e: /* original 7c2c, guest PC 0x0c05895e */
if(!s->budget--) { s->failed_pc=0x0c05895eu; return 0; }
r[12]+=0x0000002cu;
goto P_0c058960;
P_0c058960: /* original fdf2, guest PC 0x0c058960 */
if(!s->budget--) { s->failed_pc=0x0c058960u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c058962;
P_0c058962: /* original 405a, guest PC 0x0c058962 */
if(!s->budget--) { s->failed_pc=0x0c058962u; return 0; }
r[53]=r[0];
goto P_0c058964;
P_0c058964: /* original fba1, guest PC 0x0c058964 */
if(!s->budget--) { s->failed_pc=0x0c058964u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'-');
goto P_0c058966;
P_0c058966: /* original 2ca2, guest PC 0x0c058966 */
if(!s->budget--) { s->failed_pc=0x0c058966u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c058968;
P_0c058968: /* original f00d, guest PC 0x0c058968 */
if(!s->budget--) { s->failed_pc=0x0c058968u; return 0; }
fr[0]=r[53];
goto P_0c05896a;
P_0c05896a: /* original f0a1, guest PC 0x0c05896a */
if(!s->budget--) { s->failed_pc=0x0c05896au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'-');
goto P_0c05896c;
P_0c05896c: /* original 6125, guest PC 0x0c05896c */
if(!s->budget--) { s->failed_pc=0x0c05896cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05896e;
P_0c05896e: /* original 6221, guest PC 0x0c05896e */
if(!s->budget--) { s->failed_pc=0x0c05896eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058970;
P_0c058970: /* original f9a2, guest PC 0x0c058970 */
if(!s->budget--) { s->failed_pc=0x0c058970u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058972;
P_0c058972: /* original f01d, guest PC 0x0c058972 */
if(!s->budget--) { s->failed_pc=0x0c058972u; return 0; }
r[53]=fr[0];
goto P_0c058974;
P_0c058974: /* original a02c, guest PC 0x0c058974 */
if(!s->budget--) { s->failed_pc=0x0c058974u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0589d0;
P_0c058976: /* original f0b3, guest PC 0x0c058976 */
if(!s->budget--) { s->failed_pc=0x0c058976u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
return vf3_matrix_family(0x0c058978u,s,ram);
P_0c0589d0: /* original f8a2, guest PC 0x0c0589d0 */
if(!s->budget--) { s->failed_pc=0x0c0589d0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c0589d2;
P_0c0589d2: /* original f1ec, guest PC 0x0c0589d2 */
if(!s->budget--) { s->failed_pc=0x0c0589d2u; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c0589d4;
P_0c0589d4: /* original fe9d, guest PC 0x0c0589d4 */
if(!s->budget--) { s->failed_pc=0x0c0589d4u; return 0; }
fr[14]=0x3f800000u;
goto P_0c0589d6;
P_0c0589d6: /* original fe13, guest PC 0x0c0589d6 */
if(!s->budget--) { s->failed_pc=0x0c0589d6u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[1],r[18],'/');
goto P_0c0589d8;
P_0c0589d8: /* original 7c08, guest PC 0x0c0589d8 */
if(!s->budget--) { s->failed_pc=0x0c0589d8u; return 0; }
r[12]+=0x00000008u;
goto P_0c0589da;
P_0c0589da: /* original f791, guest PC 0x0c0589da */
if(!s->budget--) { s->failed_pc=0x0c0589dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c0589dc;
P_0c0589dc: /* original f681, guest PC 0x0c0589dc */
if(!s->budget--) { s->failed_pc=0x0c0589dcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0589de;
P_0c0589de: /* original fd51, guest PC 0x0c0589de */
if(!s->budget--) { s->failed_pc=0x0c0589deu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'-');
goto P_0c0589e0;
P_0c0589e0: /* original fc41, guest PC 0x0c0589e0 */
if(!s->budget--) { s->failed_pc=0x0c0589e0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0589e2;
P_0c0589e2: /* original f19c, guest PC 0x0c0589e2 */
if(!s->budget--) { s->failed_pc=0x0c0589e2u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c0589e4;
P_0c0589e4: /* original f17e, guest PC 0x0c0589e4 */
if(!s->budget--) { s->failed_pc=0x0c0589e4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[7],fr[1],r[18]);
goto P_0c0589e6;
P_0c0589e6: /* original f78c, guest PC 0x0c0589e6 */
if(!s->budget--) { s->failed_pc=0x0c0589e6u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c0589e8;
P_0c0589e8: /* original f76e, guest PC 0x0c0589e8 */
if(!s->budget--) { s->failed_pc=0x0c0589e8u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[6],fr[7],r[18]);
goto P_0c0589ea;
P_0c0589ea: /* original f65c, guest PC 0x0c0589ea */
if(!s->budget--) { s->failed_pc=0x0c0589eau; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0589ec;
P_0c0589ec: /* original f6de, guest PC 0x0c0589ec */
if(!s->budget--) { s->failed_pc=0x0c0589ecu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[13],fr[6],r[18]);
goto P_0c0589ee;
P_0c0589ee: /* original fd4c, guest PC 0x0c0589ee */
if(!s->budget--) { s->failed_pc=0x0c0589eeu; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0589f0;
P_0c0589f0: /* original fdce, guest PC 0x0c0589f0 */
if(!s->budget--) { s->failed_pc=0x0c0589f0u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0589f2;
P_0c0589f2: /* original f00d, guest PC 0x0c0589f2 */
if(!s->budget--) { s->failed_pc=0x0c0589f2u; return 0; }
fr[0]=r[53];
goto P_0c0589f4;
P_0c0589f4: /* original f3e2, guest PC 0x0c0589f4 */
if(!s->budget--) { s->failed_pc=0x0c0589f4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0589f6;
P_0c0589f6: /* original 4a5a, guest PC 0x0c0589f6 */
if(!s->budget--) { s->failed_pc=0x0c0589f6u; return 0; }
r[53]=r[10];
goto P_0c0589f8;
P_0c0589f8: /* original f2e2, guest PC 0x0c0589f8 */
if(!s->budget--) { s->failed_pc=0x0c0589f8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0589fa;
P_0c0589fa: /* original fc0d, guest PC 0x0c0589fa */
if(!s->budget--) { s->failed_pc=0x0c0589fau; return 0; }
fr[12]=r[53];
goto P_0c0589fc;
P_0c0589fc: /* original fea1, guest PC 0x0c0589fc */
if(!s->budget--) { s->failed_pc=0x0c0589fcu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[10],r[18],'-');
goto P_0c0589fe;
P_0c0589fe: /* original fc6a, guest PC 0x0c0589fe */
if(!s->budget--) { s->failed_pc=0x0c0589feu; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c058a00;
P_0c058a00: /* original f1c2, guest PC 0x0c058a00 */
if(!s->budget--) { s->failed_pc=0x0c058a00u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[12],r[18],'*');
goto P_0c058a02;
P_0c058a02: /* original fcdb, guest PC 0x0c058a02 */
if(!s->budget--) { s->failed_pc=0x0c058a02u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c058a04;
P_0c058a04: /* original f7c2, guest PC 0x0c058a04 */
if(!s->budget--) { s->failed_pc=0x0c058a04u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'*');
goto P_0c058a06;
P_0c058a06: /* original 2ca6, guest PC 0x0c058a06 */
if(!s->budget--) { s->failed_pc=0x0c058a06u; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058a08;
P_0c058a08: /* original f0e3, guest PC 0x0c058a08 */
if(!s->budget--) { s->failed_pc=0x0c058a08u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'/');
goto P_0c058a0a;
P_0c058a0a: /* original 425a, guest PC 0x0c058a0a */
if(!s->budget--) { s->failed_pc=0x0c058a0au; return 0; }
r[53]=r[2];
goto P_0c058a0c;
P_0c058a0c: /* original fe2d, guest PC 0x0c058a0c */
if(!s->budget--) { s->failed_pc=0x0c058a0cu; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a0e;
P_0c058a0e: /* original 415a, guest PC 0x0c058a0e */
if(!s->budget--) { s->failed_pc=0x0c058a0eu; return 0; }
r[53]=r[1];
goto P_0c058a10;
P_0c058a10: /* original fd2d, guest PC 0x0c058a10 */
if(!s->budget--) { s->failed_pc=0x0c058a10u; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a12;
P_0c058a12: /* original fc1b, guest PC 0x0c058a12 */
if(!s->budget--) { s->failed_pc=0x0c058a12u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[12]);
goto P_0c058a14;
P_0c058a14: /* original f391, guest PC 0x0c058a14 */
if(!s->budget--) { s->failed_pc=0x0c058a14u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'-');
goto P_0c058a16;
P_0c058a16: /* original fc7b, guest PC 0x0c058a16 */
if(!s->budget--) { s->failed_pc=0x0c058a16u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[12]);
goto P_0c058a18;
P_0c058a18: /* original f281, guest PC 0x0c058a18 */
if(!s->budget--) { s->failed_pc=0x0c058a18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'-');
goto P_0c058a1a;
P_0c058a1a: /* original 2cc6, guest PC 0x0c058a1a */
if(!s->budget--) { s->failed_pc=0x0c058a1au; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c058a1c;
P_0c058a1c: /* original 0c83, guest PC 0x0c058a1c */
if(!s->budget--) { s->failed_pc=0x0c058a1cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058a1e;
P_0c058a1e: /* original fef2, guest PC 0x0c058a1e */
if(!s->budget--) { s->failed_pc=0x0c058a1eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058a20;
P_0c058a20: /* original 61f6, guest PC 0x0c058a20 */
if(!s->budget--) { s->failed_pc=0x0c058a20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058a22;
P_0c058a22: /* original fdf2, guest PC 0x0c058a22 */
if(!s->budget--) { s->failed_pc=0x0c058a22u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c058a24;
P_0c058a24: /* original 4f26, guest PC 0x0c058a24 */
if(!s->budget--) { s->failed_pc=0x0c058a24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058a26;
P_0c058a26: /* original fe51, guest PC 0x0c058a26 */
if(!s->budget--) { s->failed_pc=0x0c058a26u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
goto P_0c058a28;
P_0c058a28: /* original c618, guest PC 0x0c058a28 */
if(!s->budget--) { s->failed_pc=0x0c058a28u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c058a2a;
P_0c058a2a: /* original fd41, guest PC 0x0c058a2a */
if(!s->budget--) { s->failed_pc=0x0c058a2au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'-');
goto P_0c058a2c;
P_0c058a2c: /* original 7c2c, guest PC 0x0c058a2c */
if(!s->budget--) { s->failed_pc=0x0c058a2cu; return 0; }
r[12]+=0x0000002cu;
goto P_0c058a2e;
P_0c058a2e: /* original f93e, guest PC 0x0c058a2e */
if(!s->budget--) { s->failed_pc=0x0c058a2eu; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[3],fr[9],r[18]);
goto P_0c058a30;
P_0c058a30: /* original 1c14, guest PC 0x0c058a30 */
if(!s->budget--) { s->failed_pc=0x0c058a30u; return 0; }
write(ram,r[12]+16,r[1],4);
goto P_0c058a32;
P_0c058a32: /* original f82e, guest PC 0x0c058a32 */
if(!s->budget--) { s->failed_pc=0x0c058a32u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[2],fr[8],r[18]);
goto P_0c058a34;
P_0c058a34: /* original 2ca2, guest PC 0x0c058a34 */
if(!s->budget--) { s->failed_pc=0x0c058a34u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c058a36;
P_0c058a36: /* original f5ee, guest PC 0x0c058a36 */
if(!s->budget--) { s->failed_pc=0x0c058a36u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[14],fr[5],r[18]);
goto P_0c058a38;
P_0c058a38: /* original 1c03, guest PC 0x0c058a38 */
if(!s->budget--) { s->failed_pc=0x0c058a38u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c058a3a;
P_0c058a3a: /* original f4de, guest PC 0x0c058a3a */
if(!s->budget--) { s->failed_pc=0x0c058a3au; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[13],fr[4],r[18]);
goto P_0c058a3c;
P_0c058a3c: /* original f9c2, guest PC 0x0c058a3c */
if(!s->budget--) { s->failed_pc=0x0c058a3cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c058a3e;
P_0c058a3e: /* original 7c08, guest PC 0x0c058a3e */
if(!s->budget--) { s->failed_pc=0x0c058a3eu; return 0; }
r[12]+=0x00000008u;
goto P_0c058a40;
P_0c058a40: /* original f8c2, guest PC 0x0c058a40 */
if(!s->budget--) { s->failed_pc=0x0c058a40u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[12],r[18],'*');
goto P_0c058a42;
P_0c058a42: /* original e0fc, guest PC 0x0c058a42 */
if(!s->budget--) { s->failed_pc=0x0c058a42u; return 0; }
r[0]=0xfffffffcu;
goto P_0c058a44;
P_0c058a44: /* original fc5a, guest PC 0x0c058a44 */
if(!s->budget--) { s->failed_pc=0x0c058a44u; return 0; }
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c058a46;
P_0c058a46: /* original fc47, guest PC 0x0c058a46 */
if(!s->budget--) { s->failed_pc=0x0c058a46u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c058a48;
P_0c058a48: /* original 7cf4, guest PC 0x0c058a48 */
if(!s->budget--) { s->failed_pc=0x0c058a48u; return 0; }
r[12]+=0xfffffff4u;
goto P_0c058a4a;
P_0c058a4a: /* original fc9a, guest PC 0x0c058a4a */
if(!s->budget--) { s->failed_pc=0x0c058a4au; return 0; }
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c058a4c;
P_0c058a4c: /* original fc8b, guest PC 0x0c058a4c */
if(!s->budget--) { s->failed_pc=0x0c058a4cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c058a4e;
P_0c058a4e: /* original f3fd, guest PC 0x0c058a4e */
if(!s->budget--) { s->failed_pc=0x0c058a4eu; return 0; }
r[18]^=0x100000u;
goto P_0c058a50;
P_0c058a50: /* original 7cfc, guest PC 0x0c058a50 */
if(!s->budget--) { s->failed_pc=0x0c058a50u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c058a52;
P_0c058a52: /* original f498, guest PC 0x0c058a52 */
if(!s->budget--) { s->failed_pc=0x0c058a52u; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c058a54;
P_0c058a54: /* original 000b, guest PC 0x0c058a54 */
if(!s->budget--) { s->failed_pc=0x0c058a54u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c058a56: /* original f868, guest PC 0x0c058a56 */
if(!s->budget--) { s->failed_pc=0x0c058a56u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
return vf3_matrix_family(0x0c058a58u,s,ram);
P_0c059aea: /* original 4f22, guest PC 0x0c059aea */
if(!s->budget--) { s->failed_pc=0x0c059aeau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059aec;
P_0c059aec: /* original 7ff8, guest PC 0x0c059aec */
if(!s->budget--) { s->failed_pc=0x0c059aecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059aee;
P_0c059aee: /* original 6322, guest PC 0x0c059aee */
if(!s->budget--) { s->failed_pc=0x0c059aeeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059af0;
P_0c059af0: /* original 2338, guest PC 0x0c059af0 */
if(!s->budget--) { s->failed_pc=0x0c059af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059af2;
P_0c059af2: /* original 8f74, guest PC 0x0c059af2 */
if(!s->budget--) { s->failed_pc=0x0c059af2u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c059bde; }
goto P_0c059af6;
P_0c059af4: /* original ed01, guest PC 0x0c059af4 */
if(!s->budget--) { s->failed_pc=0x0c059af4u; return 0; }
r[13]=0x00000001u;
goto P_0c059af6;
P_0c059af6: /* original d110, guest PC 0x0c059af6 */
if(!s->budget--) { s->failed_pc=0x0c059af6u; return 0; }
r[1]=read(ram,0x0c059b38u,4);
goto P_0c059af8;
P_0c059af8: /* original 6312, guest PC 0x0c059af8 */
if(!s->budget--) { s->failed_pc=0x0c059af8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059afa;
P_0c059afa: /* original 2338, guest PC 0x0c059afa */
if(!s->budget--) { s->failed_pc=0x0c059afau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059afc;
P_0c059afc: /* original 8b20, guest PC 0x0c059afc */
if(!s->budget--) { s->failed_pc=0x0c059afcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059b40; }
goto P_0c059afe;
P_0c059afe: /* original d004, guest PC 0x0c059afe */
if(!s->budget--) { s->failed_pc=0x0c059afeu; return 0; }
r[0]=read(ram,0x0c059b10u,4);
goto P_0c059b00;
P_0c059b00: /* original 6302, guest PC 0x0c059b00 */
if(!s->budget--) { s->failed_pc=0x0c059b00u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b02;
P_0c059b02: /* original 70f0, guest PC 0x0c059b02 */
if(!s->budget--) { s->failed_pc=0x0c059b02u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c059b04;
P_0c059b04: /* original 4308, guest PC 0x0c059b04 */
if(!s->budget--) { s->failed_pc=0x0c059b04u; return 0; }
r[3]<<=2;
goto P_0c059b06;
P_0c059b06: /* original 03d6, guest PC 0x0c059b06 */
if(!s->budget--) { s->failed_pc=0x0c059b06u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c059b08;
P_0c059b08: /* original d30c, guest PC 0x0c059b08 */
if(!s->budget--) { s->failed_pc=0x0c059b08u; return 0; }
r[3]=read(ram,0x0c059b3cu,4);
goto P_0c059b0a;
P_0c059b0a: /* original a068, guest PC 0x0c059b0a */
if(!s->budget--) { s->failed_pc=0x0c059b0au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059bde;
P_0c059b0c: /* original 23d2, guest PC 0x0c059b0c */
if(!s->budget--) { s->failed_pc=0x0c059b0cu; return 0; }
write(ram,r[3],r[13],4);
return vf3_matrix_family(0x0c059b0eu,s,ram);
P_0c059b40: /* original d538, guest PC 0x0c059b40 */
if(!s->budget--) { s->failed_pc=0x0c059b40u; return 0; }
r[5]=read(ram,0x0c059c24u,4);
goto P_0c059b42;
P_0c059b42: /* original d039, guest PC 0x0c059b42 */
if(!s->budget--) { s->failed_pc=0x0c059b42u; return 0; }
r[0]=read(ram,0x0c059c28u,4);
goto P_0c059b44;
P_0c059b44: /* original d239, guest PC 0x0c059b44 */
if(!s->budget--) { s->failed_pc=0x0c059b44u; return 0; }
r[2]=read(ram,0x0c059c2cu,4);
goto P_0c059b46;
P_0c059b46: /* original 6302, guest PC 0x0c059b46 */
if(!s->budget--) { s->failed_pc=0x0c059b46u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b48;
P_0c059b48: /* original e048, guest PC 0x0c059b48 */
if(!s->budget--) { s->failed_pc=0x0c059b48u; return 0; }
r[0]=0x00000048u;
goto P_0c059b4a;
P_0c059b4a: /* original 0536, guest PC 0x0c059b4a */
if(!s->budget--) { s->failed_pc=0x0c059b4au; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c059b4c;
P_0c059b4c: /* original 6422, guest PC 0x0c059b4c */
if(!s->budget--) { s->failed_pc=0x0c059b4cu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059b4e;
P_0c059b4e: /* original d338, guest PC 0x0c059b4e */
if(!s->budget--) { s->failed_pc=0x0c059b4eu; return 0; }
r[3]=read(ram,0x0c059c30u,4);
goto P_0c059b50;
P_0c059b50: /* original 2342, guest PC 0x0c059b50 */
if(!s->budget--) { s->failed_pc=0x0c059b50u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b52;
P_0c059b52: /* original d138, guest PC 0x0c059b52 */
if(!s->budget--) { s->failed_pc=0x0c059b52u; return 0; }
r[1]=read(ram,0x0c059c34u,4);
goto P_0c059b54;
P_0c059b54: /* original 21d2, guest PC 0x0c059b54 */
if(!s->budget--) { s->failed_pc=0x0c059b54u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059b56;
P_0c059b56: /* original d238, guest PC 0x0c059b56 */
if(!s->budget--) { s->failed_pc=0x0c059b56u; return 0; }
r[2]=read(ram,0x0c059c38u,4);
goto P_0c059b58;
P_0c059b58: /* original 22c2, guest PC 0x0c059b58 */
if(!s->budget--) { s->failed_pc=0x0c059b58u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059b5a;
P_0c059b5a: /* original d038, guest PC 0x0c059b5a */
if(!s->budget--) { s->failed_pc=0x0c059b5au; return 0; }
r[0]=read(ram,0x0c059c3cu,4);
goto P_0c059b5c;
P_0c059b5c: /* original 6302, guest PC 0x0c059b5c */
if(!s->budget--) { s->failed_pc=0x0c059b5cu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b5e;
P_0c059b5e: /* original d138, guest PC 0x0c059b5e */
if(!s->budget--) { s->failed_pc=0x0c059b5eu; return 0; }
r[1]=read(ram,0x0c059c40u,4);
goto P_0c059b60;
P_0c059b60: /* original 2132, guest PC 0x0c059b60 */
if(!s->budget--) { s->failed_pc=0x0c059b60u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059b62;
P_0c059b62: /* original 7208, guest PC 0x0c059b62 */
if(!s->budget--) { s->failed_pc=0x0c059b62u; return 0; }
r[2]+=0x00000008u;
goto P_0c059b64;
P_0c059b64: /* original 22d2, guest PC 0x0c059b64 */
if(!s->budget--) { s->failed_pc=0x0c059b64u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c059b66;
P_0c059b66: /* original 4408, guest PC 0x0c059b66 */
if(!s->budget--) { s->failed_pc=0x0c059b66u; return 0; }
r[4]<<=2;
goto P_0c059b68;
P_0c059b68: /* original 15c1, guest PC 0x0c059b68 */
if(!s->budget--) { s->failed_pc=0x0c059b68u; return 0; }
write(ram,r[5]+4,r[12],4);
goto P_0c059b6a;
P_0c059b6a: /* original e302, guest PC 0x0c059b6a */
if(!s->budget--) { s->failed_pc=0x0c059b6au; return 0; }
r[3]=0x00000002u;
goto P_0c059b6c;
P_0c059b6c: /* original d035, guest PC 0x0c059b6c */
if(!s->budget--) { s->failed_pc=0x0c059b6cu; return 0; }
r[0]=read(ram,0x0c059c44u,4);
goto P_0c059b6e;
P_0c059b6e: /* original 0436, guest PC 0x0c059b6e */
if(!s->budget--) { s->failed_pc=0x0c059b6eu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c059b70;
P_0c059b70: /* original d135, guest PC 0x0c059b70 */
if(!s->budget--) { s->failed_pc=0x0c059b70u; return 0; }
r[1]=read(ram,0x0c059c48u,4);
goto P_0c059b72;
P_0c059b72: /* original 6012, guest PC 0x0c059b72 */
if(!s->budget--) { s->failed_pc=0x0c059b72u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059b74;
P_0c059b74: /* original c820, guest PC 0x0c059b74 */
if(!s->budget--) { s->failed_pc=0x0c059b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c059b76;
P_0c059b76: /* original 890d, guest PC 0x0c059b76 */
if(!s->budget--) { s->failed_pc=0x0c059b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059b94; }
goto P_0c059b78;
P_0c059b78: /* original d034, guest PC 0x0c059b78 */
if(!s->budget--) { s->failed_pc=0x0c059b78u; return 0; }
r[0]=read(ram,0x0c059c4cu,4);
goto P_0c059b7a;
P_0c059b7a: /* original e410, guest PC 0x0c059b7a */
if(!s->budget--) { s->failed_pc=0x0c059b7au; return 0; }
r[4]=0x00000010u;
goto P_0c059b7c;
P_0c059b7c: /* original 2042, guest PC 0x0c059b7c */
if(!s->budget--) { s->failed_pc=0x0c059b7cu; return 0; }
write(ram,r[0],r[4],4);
goto P_0c059b7e;
P_0c059b7e: /* original d334, guest PC 0x0c059b7e */
if(!s->budget--) { s->failed_pc=0x0c059b7eu; return 0; }
r[3]=read(ram,0x0c059c50u,4);
goto P_0c059b80;
P_0c059b80: /* original 2342, guest PC 0x0c059b80 */
if(!s->budget--) { s->failed_pc=0x0c059b80u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b82;
P_0c059b82: /* original d534, guest PC 0x0c059b82 */
if(!s->budget--) { s->failed_pc=0x0c059b82u; return 0; }
r[5]=read(ram,0x0c059c54u,4);
goto P_0c059b84;
P_0c059b84: /* original d434, guest PC 0x0c059b84 */
if(!s->budget--) { s->failed_pc=0x0c059b84u; return 0; }
r[4]=read(ram,0x0c059c58u,4);
goto P_0c059b86;
P_0c059b86: /* original d235, guest PC 0x0c059b86 */
if(!s->budget--) { s->failed_pc=0x0c059b86u; return 0; }
r[2]=read(ram,0x0c059c5cu,4);
goto P_0c059b88;
P_0c059b88: /* original 420b, guest PC 0x0c059b88 */
if(!s->budget--) { s->failed_pc=0x0c059b88u; return 0; }
target=r[2];
r[16]=code_base|0x0c059b8cu;
r[6]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059b8cu) { target=s->pc; goto dispatch; }
goto P_0c059b8c;
P_0c059b8a: /* original e604, guest PC 0x0c059b8a */
if(!s->budget--) { s->failed_pc=0x0c059b8au; return 0; }
r[6]=0x00000004u;
goto P_0c059b8c;
P_0c059b8c: /* original d332, guest PC 0x0c059b8c */
if(!s->budget--) { s->failed_pc=0x0c059b8cu; return 0; }
r[3]=read(ram,0x0c059c58u,4);
goto P_0c059b8e;
P_0c059b8e: /* original 0383, guest PC 0x0c059b8e */
if(!s->budget--) { s->failed_pc=0x0c059b8eu; return 0; }
if((r[3]&0xFC000000u)==0xE0000000u) pref(ram,r[3]);
goto P_0c059b90;
P_0c059b90: /* original a022, guest PC 0x0c059b90 */
if(!s->budget--) { s->failed_pc=0x0c059b90u; return 0; }
goto P_0c059bd8;
P_0c059b92: /* original 0009, guest PC 0x0c059b92 */
if(!s->budget--) { s->failed_pc=0x0c059b92u; return 0; }
goto P_0c059b94;
P_0c059b94: /* original d025, guest PC 0x0c059b94 */
if(!s->budget--) { s->failed_pc=0x0c059b94u; return 0; }
r[0]=read(ram,0x0c059c2cu,4);
goto P_0c059b96;
P_0c059b96: /* original 6902, guest PC 0x0c059b96 */
if(!s->budget--) { s->failed_pc=0x0c059b96u; return 0; }
tmp=read(ram,r[0],4);
r[9]=tmp;
goto P_0c059b98;
P_0c059b98: /* original d331, guest PC 0x0c059b98 */
if(!s->budget--) { s->failed_pc=0x0c059b98u; return 0; }
r[3]=read(ram,0x0c059c60u,4);
goto P_0c059b9a;
P_0c059b9a: /* original 6203, guest PC 0x0c059b9a */
if(!s->budget--) { s->failed_pc=0x0c059b9au; return 0; }
r[2]=r[0];
goto P_0c059b9c;
P_0c059b9c: /* original 6a22, guest PC 0x0c059b9c */
if(!s->budget--) { s->failed_pc=0x0c059b9cu; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c059b9e;
P_0c059b9e: /* original 4908, guest PC 0x0c059b9e */
if(!s->budget--) { s->failed_pc=0x0c059b9eu; return 0; }
r[9]<<=2;
goto P_0c059ba0;
P_0c059ba0: /* original d030, guest PC 0x0c059ba0 */
if(!s->budget--) { s->failed_pc=0x0c059ba0u; return 0; }
r[0]=read(ram,0x0c059c64u,4);
goto P_0c059ba2;
P_0c059ba2: /* original 4a08, guest PC 0x0c059ba2 */
if(!s->budget--) { s->failed_pc=0x0c059ba2u; return 0; }
r[10]<<=2;
goto P_0c059ba4;
P_0c059ba4: /* original 393c, guest PC 0x0c059ba4 */
if(!s->budget--) { s->failed_pc=0x0c059ba4u; return 0; }
r[9]+=r[3];
goto P_0c059ba6;
P_0c059ba6: /* original 7350, guest PC 0x0c059ba6 */
if(!s->budget--) { s->failed_pc=0x0c059ba6u; return 0; }
r[3]+=0x00000050u;
goto P_0c059ba8;
P_0c059ba8: /* original 3a3c, guest PC 0x0c059ba8 */
if(!s->budget--) { s->failed_pc=0x0c059ba8u; return 0; }
r[10]+=r[3];
goto P_0c059baa;
P_0c059baa: /* original 6102, guest PC 0x0c059baa */
if(!s->budget--) { s->failed_pc=0x0c059baau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059bac;
P_0c059bac: /* original 4108, guest PC 0x0c059bac */
if(!s->budget--) { s->failed_pc=0x0c059bacu; return 0; }
r[1]<<=2;
goto P_0c059bae;
P_0c059bae: /* original 4108, guest PC 0x0c059bae */
if(!s->budget--) { s->failed_pc=0x0c059baeu; return 0; }
r[1]<<=2;
goto P_0c059bb0;
P_0c059bb0: /* original 3a1c, guest PC 0x0c059bb0 */
if(!s->budget--) { s->failed_pc=0x0c059bb0u; return 0; }
r[10]+=r[1];
goto P_0c059bb2;
P_0c059bb2: /* original 6103, guest PC 0x0c059bb2 */
if(!s->budget--) { s->failed_pc=0x0c059bb2u; return 0; }
r[1]=r[0];
goto P_0c059bb4;
P_0c059bb4: /* original 6312, guest PC 0x0c059bb4 */
if(!s->budget--) { s->failed_pc=0x0c059bb4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059bb6;
P_0c059bb6: /* original 4308, guest PC 0x0c059bb6 */
if(!s->budget--) { s->failed_pc=0x0c059bb6u; return 0; }
r[3]<<=2;
goto P_0c059bb8;
P_0c059bb8: /* original d82b, guest PC 0x0c059bb8 */
if(!s->budget--) { s->failed_pc=0x0c059bb8u; return 0; }
r[8]=read(ram,0x0c059c68u,4);
goto P_0c059bba;
P_0c059bba: /* original 4308, guest PC 0x0c059bba */
if(!s->budget--) { s->failed_pc=0x0c059bbau; return 0; }
r[3]<<=2;
goto P_0c059bbc;
P_0c059bbc: /* original db2b, guest PC 0x0c059bbc */
if(!s->budget--) { s->failed_pc=0x0c059bbcu; return 0; }
r[11]=read(ram,0x0c059c6cu,4);
goto P_0c059bbe;
P_0c059bbe: /* original 393c, guest PC 0x0c059bbe */
if(!s->budget--) { s->failed_pc=0x0c059bbeu; return 0; }
r[9]+=r[3];
goto P_0c059bc0;
P_0c059bc0: /* original 9e2e, guest PC 0x0c059bc0 */
if(!s->budget--) { s->failed_pc=0x0c059bc0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059c20u,2);
goto P_0c059bc2;
P_0c059bc2: /* original 62f3, guest PC 0x0c059bc2 */
if(!s->budget--) { s->failed_pc=0x0c059bc2u; return 0; }
r[2]=r[15];
goto P_0c059bc4;
P_0c059bc4: /* original 2f26, guest PC 0x0c059bc4 */
if(!s->budget--) { s->failed_pc=0x0c059bc4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059bc6;
P_0c059bc6: /* original e710, guest PC 0x0c059bc6 */
if(!s->budget--) { s->failed_pc=0x0c059bc6u; return 0; }
r[7]=0x00000010u;
goto P_0c059bc8;
P_0c059bc8: /* original 66a2, guest PC 0x0c059bc8 */
if(!s->budget--) { s->failed_pc=0x0c059bc8u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c059bca;
P_0c059bca: /* original 7620, guest PC 0x0c059bca */
if(!s->budget--) { s->failed_pc=0x0c059bcau; return 0; }
r[6]+=0x00000020u;
goto P_0c059bcc;
P_0c059bcc: /* original 6592, guest PC 0x0c059bcc */
if(!s->budget--) { s->failed_pc=0x0c059bccu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059bce;
P_0c059bce: /* original 480b, guest PC 0x0c059bce */
if(!s->budget--) { s->failed_pc=0x0c059bceu; return 0; }
target=r[8];
r[16]=code_base|0x0c059bd2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059bd2u) { target=s->pc; goto dispatch; }
goto P_0c059bd2;
P_0c059bd0: /* original 64b3, guest PC 0x0c059bd0 */
if(!s->budget--) { s->failed_pc=0x0c059bd0u; return 0; }
r[4]=r[11];
goto P_0c059bd2;
P_0c059bd2: /* original 30e0, guest PC 0x0c059bd2 */
if(!s->budget--) { s->failed_pc=0x0c059bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c059bd4;
P_0c059bd4: /* original 8df5, guest PC 0x0c059bd4 */
if(!s->budget--) { s->failed_pc=0x0c059bd4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059bc2; }
goto P_0c059bd8;
P_0c059bd6: /* original 7f04, guest PC 0x0c059bd6 */
if(!s->budget--) { s->failed_pc=0x0c059bd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059bd8;
P_0c059bd8: /* original d222, guest PC 0x0c059bd8 */
if(!s->budget--) { s->failed_pc=0x0c059bd8u; return 0; }
r[2]=read(ram,0x0c059c64u,4);
goto P_0c059bda;
P_0c059bda: /* original bf21, guest PC 0x0c059bda */
if(!s->budget--) { s->failed_pc=0x0c059bdau; return 0; }
target=0x0c059a20u; r[16]=code_base|0x0c059bdeu;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059bdeu) { target=s->pc; goto dispatch; }
goto P_0c059bde;
P_0c059bdc: /* original 6422, guest PC 0x0c059bdc */
if(!s->budget--) { s->failed_pc=0x0c059bdcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059bde;
P_0c059bde: /* original d124, guest PC 0x0c059bde */
if(!s->budget--) { s->failed_pc=0x0c059bdeu; return 0; }
r[1]=read(ram,0x0c059c70u,4);
goto P_0c059be0;
P_0c059be0: /* original 21c2, guest PC 0x0c059be0 */
if(!s->budget--) { s->failed_pc=0x0c059be0u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c059be2;
P_0c059be2: /* original a010, guest PC 0x0c059be2 */
if(!s->budget--) { s->failed_pc=0x0c059be2u; return 0; }
r[14]=0x00000000u;
goto P_0c059c06;
P_0c059be4: /* original ee00, guest PC 0x0c059be4 */
if(!s->budget--) { s->failed_pc=0x0c059be4u; return 0; }
r[14]=0x00000000u;
goto P_0c059be6;
P_0c059be6: /* original d223, guest PC 0x0c059be6 */
if(!s->budget--) { s->failed_pc=0x0c059be6u; return 0; }
r[2]=read(ram,0x0c059c74u,4);
goto P_0c059be8;
P_0c059be8: /* original 6322, guest PC 0x0c059be8 */
if(!s->budget--) { s->failed_pc=0x0c059be8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bea;
P_0c059bea: /* original 430b, guest PC 0x0c059bea */
if(!s->budget--) { s->failed_pc=0x0c059beau; return 0; }
target=r[3];
r[16]=code_base|0x0c059beeu;
r[4]=read(ram,r[2]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059beeu) { target=s->pc; goto dispatch; }
goto P_0c059bee;
P_0c059bec: /* original 5421, guest PC 0x0c059bec */
if(!s->budget--) { s->failed_pc=0x0c059becu; return 0; }
r[4]=read(ram,r[2]+4,4);
goto P_0c059bee;
P_0c059bee: /* original d022, guest PC 0x0c059bee */
if(!s->budget--) { s->failed_pc=0x0c059beeu; return 0; }
r[0]=read(ram,0x0c059c78u,4);
goto P_0c059bf0;
P_0c059bf0: /* original 6302, guest PC 0x0c059bf0 */
if(!s->budget--) { s->failed_pc=0x0c059bf0u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059bf2;
P_0c059bf2: /* original d222, guest PC 0x0c059bf2 */
if(!s->budget--) { s->failed_pc=0x0c059bf2u; return 0; }
r[2]=read(ram,0x0c059c7cu,4);
goto P_0c059bf4;
P_0c059bf4: /* original 6122, guest PC 0x0c059bf4 */
if(!s->budget--) { s->failed_pc=0x0c059bf4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059bf6;
P_0c059bf6: /* original 313c, guest PC 0x0c059bf6 */
if(!s->budget--) { s->failed_pc=0x0c059bf6u; return 0; }
r[1]+=r[3];
goto P_0c059bf8;
P_0c059bf8: /* original d21d, guest PC 0x0c059bf8 */
if(!s->budget--) { s->failed_pc=0x0c059bf8u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059bfa;
P_0c059bfa: /* original 7101, guest PC 0x0c059bfa */
if(!s->budget--) { s->failed_pc=0x0c059bfau; return 0; }
r[1]+=0x00000001u;
goto P_0c059bfc;
P_0c059bfc: /* original 6322, guest PC 0x0c059bfc */
if(!s->budget--) { s->failed_pc=0x0c059bfcu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bfe;
P_0c059bfe: /* original 3316, guest PC 0x0c059bfe */
if(!s->budget--) { s->failed_pc=0x0c059bfeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c059c00;
P_0c059c00: /* original 8b01, guest PC 0x0c059c00 */
if(!s->budget--) { s->failed_pc=0x0c059c00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c06; }
goto P_0c059c02;
P_0c059c02: /* original a004, guest PC 0x0c059c02 */
if(!s->budget--) { s->failed_pc=0x0c059c02u; return 0; }
r[14]=0x00000001u;
goto P_0c059c0e;
P_0c059c04: /* original ee01, guest PC 0x0c059c04 */
if(!s->budget--) { s->failed_pc=0x0c059c04u; return 0; }
r[14]=0x00000001u;
goto P_0c059c06;
P_0c059c06: /* original d31e, guest PC 0x0c059c06 */
if(!s->budget--) { s->failed_pc=0x0c059c06u; return 0; }
r[3]=read(ram,0x0c059c80u,4);
goto P_0c059c08;
P_0c059c08: /* original 6232, guest PC 0x0c059c08 */
if(!s->budget--) { s->failed_pc=0x0c059c08u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c0a;
P_0c059c0a: /* original 2228, guest PC 0x0c059c0a */
if(!s->budget--) { s->failed_pc=0x0c059c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059c0c;
P_0c059c0c: /* original 8beb, guest PC 0x0c059c0c */
if(!s->budget--) { s->failed_pc=0x0c059c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059be6; }
goto P_0c059c0e;
P_0c059c0e: /* original 2ee8, guest PC 0x0c059c0e */
if(!s->budget--) { s->failed_pc=0x0c059c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c059c10;
P_0c059c10: /* original 894d, guest PC 0x0c059c10 */
if(!s->budget--) { s->failed_pc=0x0c059c10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059c12;
P_0c059c12: /* original d31c, guest PC 0x0c059c12 */
if(!s->budget--) { s->failed_pc=0x0c059c12u; return 0; }
r[3]=read(ram,0x0c059c84u,4);
goto P_0c059c14;
P_0c059c14: /* original 23c2, guest PC 0x0c059c14 */
if(!s->budget--) { s->failed_pc=0x0c059c14u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c059c16;
P_0c059c16: /* original d216, guest PC 0x0c059c16 */
if(!s->budget--) { s->failed_pc=0x0c059c16u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059c18;
P_0c059c18: /* original 22c2, guest PC 0x0c059c18 */
if(!s->budget--) { s->failed_pc=0x0c059c18u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059c1a;
P_0c059c1a: /* original eb00, guest PC 0x0c059c1a */
if(!s->budget--) { s->failed_pc=0x0c059c1au; return 0; }
r[11]=0x00000000u;
goto P_0c059c1c;
P_0c059c1c: /* original a03e, guest PC 0x0c059c1c */
if(!s->budget--) { s->failed_pc=0x0c059c1cu; return 0; }
r[14]=0x00000014u;
goto P_0c059c9c;
P_0c059c1e: /* original ee14, guest PC 0x0c059c1e */
if(!s->budget--) { s->failed_pc=0x0c059c1eu; return 0; }
r[14]=0x00000014u;
return vf3_matrix_family(0x0c059c20u,s,ram);
P_0c059c88: /* original d340, guest PC 0x0c059c88 */
if(!s->budget--) { s->failed_pc=0x0c059c88u; return 0; }
r[3]=read(ram,0x0c059d8cu,4);
goto P_0c059c8a;
P_0c059c8a: /* original 6232, guest PC 0x0c059c8a */
if(!s->budget--) { s->failed_pc=0x0c059c8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c8c;
P_0c059c8c: /* original 420b, guest PC 0x0c059c8c */
if(!s->budget--) { s->failed_pc=0x0c059c8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c059c90u;
r[4]=read(ram,r[3]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059c90u) { target=s->pc; goto dispatch; }
goto P_0c059c90;
P_0c059c8e: /* original 5431, guest PC 0x0c059c8e */
if(!s->budget--) { s->failed_pc=0x0c059c8eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c059c90;
P_0c059c90: /* original d23f, guest PC 0x0c059c90 */
if(!s->budget--) { s->failed_pc=0x0c059c90u; return 0; }
r[2]=read(ram,0x0c059d90u,4);
goto P_0c059c92;
P_0c059c92: /* original 6122, guest PC 0x0c059c92 */
if(!s->budget--) { s->failed_pc=0x0c059c92u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059c94;
P_0c059c94: /* original 31e6, guest PC 0x0c059c94 */
if(!s->budget--) { s->failed_pc=0x0c059c94u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[14])!=0);
goto P_0c059c96;
P_0c059c96: /* original 8b01, guest PC 0x0c059c96 */
if(!s->budget--) { s->failed_pc=0x0c059c96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c9c; }
goto P_0c059c98;
P_0c059c98: /* original a004, guest PC 0x0c059c98 */
if(!s->budget--) { s->failed_pc=0x0c059c98u; return 0; }
r[11]=0x00000001u;
goto P_0c059ca4;
P_0c059c9a: /* original eb01, guest PC 0x0c059c9a */
if(!s->budget--) { s->failed_pc=0x0c059c9au; return 0; }
r[11]=0x00000001u;
goto P_0c059c9c;
P_0c059c9c: /* original d23d, guest PC 0x0c059c9c */
if(!s->budget--) { s->failed_pc=0x0c059c9cu; return 0; }
r[2]=read(ram,0x0c059d94u,4);
goto P_0c059c9e;
P_0c059c9e: /* original 6322, guest PC 0x0c059c9e */
if(!s->budget--) { s->failed_pc=0x0c059c9eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059ca0;
P_0c059ca0: /* original 2338, guest PC 0x0c059ca0 */
if(!s->budget--) { s->failed_pc=0x0c059ca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059ca2;
P_0c059ca2: /* original 8bf1, guest PC 0x0c059ca2 */
if(!s->budget--) { s->failed_pc=0x0c059ca2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c88; }
goto P_0c059ca4;
P_0c059ca4: /* original 2bb8, guest PC 0x0c059ca4 */
if(!s->budget--) { s->failed_pc=0x0c059ca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c059ca6;
P_0c059ca6: /* original 8902, guest PC 0x0c059ca6 */
if(!s->budget--) { s->failed_pc=0x0c059ca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059ca8;
P_0c059ca8: /* original d23b, guest PC 0x0c059ca8 */
if(!s->budget--) { s->failed_pc=0x0c059ca8u; return 0; }
r[2]=read(ram,0x0c059d98u,4);
goto P_0c059caa;
P_0c059caa: /* original 420b, guest PC 0x0c059caa */
if(!s->budget--) { s->failed_pc=0x0c059caau; return 0; }
target=r[2];
r[16]=code_base|0x0c059caeu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059caeu) { target=s->pc; goto dispatch; }
goto P_0c059cae;
P_0c059cac: /* original e404, guest PC 0x0c059cac */
if(!s->budget--) { s->failed_pc=0x0c059cacu; return 0; }
r[4]=0x00000004u;
goto P_0c059cae;
P_0c059cae: /* original d33b, guest PC 0x0c059cae */
if(!s->budget--) { s->failed_pc=0x0c059caeu; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cb0;
P_0c059cb0: /* original 6232, guest PC 0x0c059cb0 */
if(!s->budget--) { s->failed_pc=0x0c059cb0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cb2;
P_0c059cb2: /* original 7201, guest PC 0x0c059cb2 */
if(!s->budget--) { s->failed_pc=0x0c059cb2u; return 0; }
r[2]+=0x00000001u;
goto P_0c059cb4;
P_0c059cb4: /* original 2322, guest PC 0x0c059cb4 */
if(!s->budget--) { s->failed_pc=0x0c059cb4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059cb6;
P_0c059cb6: /* original 6032, guest PC 0x0c059cb6 */
if(!s->budget--) { s->failed_pc=0x0c059cb6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059cb8;
P_0c059cb8: /* original c903, guest PC 0x0c059cb8 */
if(!s->budget--) { s->failed_pc=0x0c059cb8u; return 0; }
r[0]&=3u;
goto P_0c059cba;
P_0c059cba: /* original 2302, guest PC 0x0c059cba */
if(!s->budget--) { s->failed_pc=0x0c059cbau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c059cbc;
P_0c059cbc: /* original d038, guest PC 0x0c059cbc */
if(!s->budget--) { s->failed_pc=0x0c059cbcu; return 0; }
r[0]=read(ram,0x0c059da0u,4);
goto P_0c059cbe;
P_0c059cbe: /* original 6232, guest PC 0x0c059cbe */
if(!s->budget--) { s->failed_pc=0x0c059cbeu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cc0;
P_0c059cc0: /* original 4208, guest PC 0x0c059cc0 */
if(!s->budget--) { s->failed_pc=0x0c059cc0u; return 0; }
r[2]<<=2;
goto P_0c059cc2;
P_0c059cc2: /* original 02c6, guest PC 0x0c059cc2 */
if(!s->budget--) { s->failed_pc=0x0c059cc2u; return 0; }
write(ram,r[2]+r[0],r[12],4);
goto P_0c059cc4;
P_0c059cc4: /* original d237, guest PC 0x0c059cc4 */
if(!s->budget--) { s->failed_pc=0x0c059cc4u; return 0; }
r[2]=read(ram,0x0c059da4u,4);
goto P_0c059cc6;
P_0c059cc6: /* original 6022, guest PC 0x0c059cc6 */
if(!s->budget--) { s->failed_pc=0x0c059cc6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c059cc8;
P_0c059cc8: /* original 8801, guest PC 0x0c059cc8 */
if(!s->budget--) { s->failed_pc=0x0c059cc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cca;
P_0c059cca: /* original 8903, guest PC 0x0c059cca */
if(!s->budget--) { s->failed_pc=0x0c059ccau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cd4; }
goto P_0c059ccc;
P_0c059ccc: /* original d136, guest PC 0x0c059ccc */
if(!s->budget--) { s->failed_pc=0x0c059cccu; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059cce;
P_0c059cce: /* original 6012, guest PC 0x0c059cce */
if(!s->budget--) { s->failed_pc=0x0c059cceu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059cd0;
P_0c059cd0: /* original 8801, guest PC 0x0c059cd0 */
if(!s->budget--) { s->failed_pc=0x0c059cd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cd2;
P_0c059cd2: /* original 8b43, guest PC 0x0c059cd2 */
if(!s->budget--) { s->failed_pc=0x0c059cd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059d5c; }
goto P_0c059cd4;
P_0c059cd4: /* original d331, guest PC 0x0c059cd4 */
if(!s->budget--) { s->failed_pc=0x0c059cd4u; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cd6;
P_0c059cd6: /* original 6232, guest PC 0x0c059cd6 */
if(!s->budget--) { s->failed_pc=0x0c059cd6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cd8;
P_0c059cd8: /* original 22d9, guest PC 0x0c059cd8 */
if(!s->budget--) { s->failed_pc=0x0c059cd8u; return 0; }
r[2]&=r[13];
goto P_0c059cda;
P_0c059cda: /* original e501, guest PC 0x0c059cda */
if(!s->budget--) { s->failed_pc=0x0c059cdau; return 0; }
r[5]=0x00000001u;
goto P_0c059cdc;
P_0c059cdc: /* original 1f21, guest PC 0x0c059cdc */
if(!s->budget--) { s->failed_pc=0x0c059cdcu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c059cde;
P_0c059cde: /* original de33, guest PC 0x0c059cde */
if(!s->budget--) { s->failed_pc=0x0c059cdeu; return 0; }
r[14]=read(ram,0x0c059dacu,4);
goto P_0c059ce0;
P_0c059ce0: /* original 4e0b, guest PC 0x0c059ce0 */
if(!s->budget--) { s->failed_pc=0x0c059ce0u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ce4u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059ce4u) { target=s->pc; goto dispatch; }
goto P_0c059ce4;
P_0c059ce2: /* original e408, guest PC 0x0c059ce2 */
if(!s->budget--) { s->failed_pc=0x0c059ce2u; return 0; }
r[4]=0x00000008u;
goto P_0c059ce4;
P_0c059ce4: /* original e500, guest PC 0x0c059ce4 */
if(!s->budget--) { s->failed_pc=0x0c059ce4u; return 0; }
r[5]=0x00000000u;
goto P_0c059ce6;
P_0c059ce6: /* original 4e0b, guest PC 0x0c059ce6 */
if(!s->budget--) { s->failed_pc=0x0c059ce6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ceau;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059ceau) { target=s->pc; goto dispatch; }
goto P_0c059cea;
P_0c059ce8: /* original e408, guest PC 0x0c059ce8 */
if(!s->budget--) { s->failed_pc=0x0c059ce8u; return 0; }
r[4]=0x00000008u;
goto P_0c059cea;
P_0c059cea: /* original 5bf1, guest PC 0x0c059cea */
if(!s->budget--) { s->failed_pc=0x0c059ceau; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c059cec;
P_0c059cec: /* original d030, guest PC 0x0c059cec */
if(!s->budget--) { s->failed_pc=0x0c059cecu; return 0; }
r[0]=read(ram,0x0c059db0u,4);
goto P_0c059cee;
P_0c059cee: /* original 4b08, guest PC 0x0c059cee */
if(!s->budget--) { s->failed_pc=0x0c059ceeu; return 0; }
r[11]<<=2;
goto P_0c059cf0;
P_0c059cf0: /* original 9445, guest PC 0x0c059cf0 */
if(!s->budget--) { s->failed_pc=0x0c059cf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d7eu,2);
goto P_0c059cf2;
P_0c059cf2: /* original 4b08, guest PC 0x0c059cf2 */
if(!s->budget--) { s->failed_pc=0x0c059cf2u; return 0; }
r[11]<<=2;
goto P_0c059cf4;
P_0c059cf4: /* original 4b00, guest PC 0x0c059cf4 */
if(!s->budget--) { s->failed_pc=0x0c059cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c059cf6;
P_0c059cf6: /* original 4e0b, guest PC 0x0c059cf6 */
if(!s->budget--) { s->failed_pc=0x0c059cf6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059cfau;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059cfau) { target=s->pc; goto dispatch; }
goto P_0c059cfa;
P_0c059cf8: /* original 05be, guest PC 0x0c059cf8 */
if(!s->budget--) { s->failed_pc=0x0c059cf8u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059cfa;
P_0c059cfa: /* original d02e, guest PC 0x0c059cfa */
if(!s->budget--) { s->failed_pc=0x0c059cfau; return 0; }
r[0]=read(ram,0x0c059db4u,4);
goto P_0c059cfc;
P_0c059cfc: /* original 9440, guest PC 0x0c059cfc */
if(!s->budget--) { s->failed_pc=0x0c059cfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d80u,2);
goto P_0c059cfe;
P_0c059cfe: /* original 4e0b, guest PC 0x0c059cfe */
if(!s->budget--) { s->failed_pc=0x0c059cfeu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d02u;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d02u) { target=s->pc; goto dispatch; }
goto P_0c059d02;
P_0c059d00: /* original 05be, guest PC 0x0c059d00 */
if(!s->budget--) { s->failed_pc=0x0c059d00u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d02;
P_0c059d02: /* original d02d, guest PC 0x0c059d02 */
if(!s->budget--) { s->failed_pc=0x0c059d02u; return 0; }
r[0]=read(ram,0x0c059db8u,4);
goto P_0c059d04;
P_0c059d04: /* original 943d, guest PC 0x0c059d04 */
if(!s->budget--) { s->failed_pc=0x0c059d04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d82u,2);
goto P_0c059d06;
P_0c059d06: /* original 4e0b, guest PC 0x0c059d06 */
if(!s->budget--) { s->failed_pc=0x0c059d06u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d0au;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d0au) { target=s->pc; goto dispatch; }
goto P_0c059d0a;
P_0c059d08: /* original 05be, guest PC 0x0c059d08 */
if(!s->budget--) { s->failed_pc=0x0c059d08u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d0a;
P_0c059d0a: /* original d02c, guest PC 0x0c059d0a */
if(!s->budget--) { s->failed_pc=0x0c059d0au; return 0; }
r[0]=read(ram,0x0c059dbcu,4);
goto P_0c059d0c;
P_0c059d0c: /* original 943a, guest PC 0x0c059d0c */
if(!s->budget--) { s->failed_pc=0x0c059d0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d84u,2);
goto P_0c059d0e;
P_0c059d0e: /* original 4e0b, guest PC 0x0c059d0e */
if(!s->budget--) { s->failed_pc=0x0c059d0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d12u;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d12u) { target=s->pc; goto dispatch; }
goto P_0c059d12;
P_0c059d10: /* original 05be, guest PC 0x0c059d10 */
if(!s->budget--) { s->failed_pc=0x0c059d10u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d12;
P_0c059d12: /* original d02b, guest PC 0x0c059d12 */
if(!s->budget--) { s->failed_pc=0x0c059d12u; return 0; }
r[0]=read(ram,0x0c059dc0u,4);
goto P_0c059d14;
P_0c059d14: /* original 9437, guest PC 0x0c059d14 */
if(!s->budget--) { s->failed_pc=0x0c059d14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d86u,2);
goto P_0c059d16;
P_0c059d16: /* original 4e0b, guest PC 0x0c059d16 */
if(!s->budget--) { s->failed_pc=0x0c059d16u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d1au;
r[5]=read(ram,r[11]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d1au) { target=s->pc; goto dispatch; }
goto P_0c059d1a;
P_0c059d18: /* original 05be, guest PC 0x0c059d18 */
if(!s->budget--) { s->failed_pc=0x0c059d18u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d1a;
P_0c059d1a: /* original d52a, guest PC 0x0c059d1a */
if(!s->budget--) { s->failed_pc=0x0c059d1au; return 0; }
r[5]=read(ram,0x0c059dc4u,4);
goto P_0c059d1c;
P_0c059d1c: /* original 9434, guest PC 0x0c059d1c */
if(!s->budget--) { s->failed_pc=0x0c059d1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d1e;
P_0c059d1e: /* original 4e0b, guest PC 0x0c059d1e */
if(!s->budget--) { s->failed_pc=0x0c059d1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d22u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d22u) { target=s->pc; goto dispatch; }
goto P_0c059d22;
P_0c059d20: /* original 0009, guest PC 0x0c059d20 */
if(!s->budget--) { s->failed_pc=0x0c059d20u; return 0; }
goto P_0c059d22;
P_0c059d22: /* original 9431, guest PC 0x0c059d22 */
if(!s->budget--) { s->failed_pc=0x0c059d22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d24;
P_0c059d24: /* original d328, guest PC 0x0c059d24 */
if(!s->budget--) { s->failed_pc=0x0c059d24u; return 0; }
r[3]=read(ram,0x0c059dc8u,4);
goto P_0c059d26;
P_0c059d26: /* original 430b, guest PC 0x0c059d26 */
if(!s->budget--) { s->failed_pc=0x0c059d26u; return 0; }
target=r[3];
r[16]=code_base|0x0c059d2au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059d2au) { target=s->pc; goto dispatch; }
goto P_0c059d2a;
P_0c059d28: /* original 0009, guest PC 0x0c059d28 */
if(!s->budget--) { s->failed_pc=0x0c059d28u; return 0; }
goto P_0c059d2a;
P_0c059d2a: /* original e200, guest PC 0x0c059d2a */
if(!s->budget--) { s->failed_pc=0x0c059d2au; return 0; }
r[2]=0x00000000u;
goto P_0c059d2c;
P_0c059d2c: /* original d327, guest PC 0x0c059d2c */
if(!s->budget--) { s->failed_pc=0x0c059d2cu; return 0; }
r[3]=read(ram,0x0c059dccu,4);
goto P_0c059d2e;
P_0c059d2e: /* original 2322, guest PC 0x0c059d2e */
if(!s->budget--) { s->failed_pc=0x0c059d2eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059d30;
P_0c059d30: /* original d027, guest PC 0x0c059d30 */
if(!s->budget--) { s->failed_pc=0x0c059d30u; return 0; }
r[0]=read(ram,0x0c059dd0u,4);
goto P_0c059d32;
P_0c059d32: /* original 6102, guest PC 0x0c059d32 */
if(!s->budget--) { s->failed_pc=0x0c059d32u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059d34;
P_0c059d34: /* original d227, guest PC 0x0c059d34 */
if(!s->budget--) { s->failed_pc=0x0c059d34u; return 0; }
r[2]=read(ram,0x0c059dd4u,4);
goto P_0c059d36;
P_0c059d36: /* original 2212, guest PC 0x0c059d36 */
if(!s->budget--) { s->failed_pc=0x0c059d36u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059d38;
P_0c059d38: /* original d11b, guest PC 0x0c059d38 */
if(!s->budget--) { s->failed_pc=0x0c059d38u; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059d3a;
P_0c059d3a: /* original 6312, guest PC 0x0c059d3a */
if(!s->budget--) { s->failed_pc=0x0c059d3au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059d3c;
P_0c059d3c: /* original 2338, guest PC 0x0c059d3c */
if(!s->budget--) { s->failed_pc=0x0c059d3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059d3e;
P_0c059d3e: /* original 890d, guest PC 0x0c059d3e */
if(!s->budget--) { s->failed_pc=0x0c059d3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059d5c; }
goto P_0c059d40;
P_0c059d40: /* original d216, guest PC 0x0c059d40 */
if(!s->budget--) { s->failed_pc=0x0c059d40u; return 0; }
r[2]=read(ram,0x0c059d9cu,4);
goto P_0c059d42;
P_0c059d42: /* original 6322, guest PC 0x0c059d42 */
if(!s->budget--) { s->failed_pc=0x0c059d42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059d44;
P_0c059d44: /* original d024, guest PC 0x0c059d44 */
if(!s->budget--) { s->failed_pc=0x0c059d44u; return 0; }
r[0]=read(ram,0x0c059dd8u,4);
goto P_0c059d46;
P_0c059d46: /* original 2032, guest PC 0x0c059d46 */
if(!s->budget--) { s->failed_pc=0x0c059d46u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059d48;
P_0c059d48: /* original 70e8, guest PC 0x0c059d48 */
if(!s->budget--) { s->failed_pc=0x0c059d48u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c059d4a;
P_0c059d4a: /* original 6323, guest PC 0x0c059d4a */
if(!s->budget--) { s->failed_pc=0x0c059d4au; return 0; }
r[3]=r[2];
goto P_0c059d4c;
P_0c059d4c: /* original 6132, guest PC 0x0c059d4c */
if(!s->budget--) { s->failed_pc=0x0c059d4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c059d4e;
P_0c059d4e: /* original e202, guest PC 0x0c059d4e */
if(!s->budget--) { s->failed_pc=0x0c059d4eu; return 0; }
r[2]=0x00000002u;
goto P_0c059d50;
P_0c059d50: /* original 4108, guest PC 0x0c059d50 */
if(!s->budget--) { s->failed_pc=0x0c059d50u; return 0; }
r[1]<<=2;
goto P_0c059d52;
P_0c059d52: /* original 0126, guest PC 0x0c059d52 */
if(!s->budget--) { s->failed_pc=0x0c059d52u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c059d54;
P_0c059d54: /* original d121, guest PC 0x0c059d54 */
if(!s->budget--) { s->failed_pc=0x0c059d54u; return 0; }
r[1]=read(ram,0x0c059ddcu,4);
goto P_0c059d56;
P_0c059d56: /* original 21d2, guest PC 0x0c059d56 */
if(!s->budget--) { s->failed_pc=0x0c059d56u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059d58;
P_0c059d58: /* original 7320, guest PC 0x0c059d58 */
if(!s->budget--) { s->failed_pc=0x0c059d58u; return 0; }
r[3]+=0x00000020u;
goto P_0c059d5a;
P_0c059d5a: /* original 23d2, guest PC 0x0c059d5a */
if(!s->budget--) { s->failed_pc=0x0c059d5au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059d5c;
P_0c059d5c: /* original e000, guest PC 0x0c059d5c */
if(!s->budget--) { s->failed_pc=0x0c059d5cu; return 0; }
r[0]=0x00000000u;
goto P_0c059d5e;
P_0c059d5e: /* original 7f08, guest PC 0x0c059d5e */
if(!s->budget--) { s->failed_pc=0x0c059d5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059d60;
P_0c059d60: /* original 4f26, guest PC 0x0c059d60 */
if(!s->budget--) { s->failed_pc=0x0c059d60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059d62;
P_0c059d62: /* original 68f6, guest PC 0x0c059d62 */
if(!s->budget--) { s->failed_pc=0x0c059d62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059d64;
P_0c059d64: /* original 69f6, guest PC 0x0c059d64 */
if(!s->budget--) { s->failed_pc=0x0c059d64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059d66;
P_0c059d66: /* original 6af6, guest PC 0x0c059d66 */
if(!s->budget--) { s->failed_pc=0x0c059d66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059d68;
P_0c059d68: /* original 6bf6, guest PC 0x0c059d68 */
if(!s->budget--) { s->failed_pc=0x0c059d68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059d6a;
P_0c059d6a: /* original 6cf6, guest PC 0x0c059d6a */
if(!s->budget--) { s->failed_pc=0x0c059d6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059d6c;
P_0c059d6c: /* original 6df6, guest PC 0x0c059d6c */
if(!s->budget--) { s->failed_pc=0x0c059d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059d6e;
P_0c059d6e: /* original 000b, guest PC 0x0c059d6e */
if(!s->budget--) { s->failed_pc=0x0c059d6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059d70: /* original 6ef6, guest PC 0x0c059d70 */
if(!s->budget--) { s->failed_pc=0x0c059d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059d72u,s,ram);
P_0c05e12e: /* original 4f22, guest PC 0x0c05e12e */
if(!s->budget--) { s->failed_pc=0x0c05e12eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e130;
P_0c05e130: /* original cac4, guest PC 0x0c05e130 */
if(!s->budget--) { s->failed_pc=0x0c05e130u; return 0; }
r[0]^=196u;
goto P_0c05e132;
P_0c05e132: /* original 0c16, guest PC 0x0c05e132 */
if(!s->budget--) { s->failed_pc=0x0c05e132u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e134;
P_0c05e134: /* original cadc, guest PC 0x0c05e134 */
if(!s->budget--) { s->failed_pc=0x0c05e134u; return 0; }
r[0]^=220u;
goto P_0c05e136;
P_0c05e136: /* original 0c16, guest PC 0x0c05e136 */
if(!s->budget--) { s->failed_pc=0x0c05e136u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e138;
P_0c05e138: /* original cacc, guest PC 0x0c05e138 */
if(!s->budget--) { s->failed_pc=0x0c05e138u; return 0; }
r[0]^=204u;
goto P_0c05e13a;
P_0c05e13a: /* original 0c16, guest PC 0x0c05e13a */
if(!s->budget--) { s->failed_pc=0x0c05e13au; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e13c;
P_0c05e13c: /* original cd40, guest PC 0x0c05e13c */
if(!s->budget--) { s->failed_pc=0x0c05e13cu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+r[0],read(ram,s->gbr+r[0],1)&64u,1);
goto P_0c05e13e;
P_0c05e13e: /* original 0c16, guest PC 0x0c05e13e */
if(!s->budget--) { s->failed_pc=0x0c05e13eu; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e140;
P_0c05e140: /* original cd48, guest PC 0x0c05e140 */
if(!s->budget--) { s->failed_pc=0x0c05e140u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+r[0],read(ram,s->gbr+r[0],1)&72u,1);
goto P_0c05e142;
P_0c05e142: /* original 0c16, guest PC 0x0c05e142 */
if(!s->budget--) { s->failed_pc=0x0c05e142u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e144;
P_0c05e144: /* original 2fe6, guest PC 0x0c05e144 */
if(!s->budget--) { s->failed_pc=0x0c05e144u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e146;
P_0c05e146: /* original 4f22, guest PC 0x0c05e146 */
if(!s->budget--) { s->failed_pc=0x0c05e146u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e148;
P_0c05e148: /* original d34f, guest PC 0x0c05e148 */
if(!s->budget--) { s->failed_pc=0x0c05e148u; return 0; }
r[3]=read(ram,0x0c05e288u,4);
goto P_0c05e14a;
P_0c05e14a: /* original 2348, guest PC 0x0c05e14a */
if(!s->budget--) { s->failed_pc=0x0c05e14au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c05e14c;
P_0c05e14c: /* original 8900, guest PC 0x0c05e14c */
if(!s->budget--) { s->failed_pc=0x0c05e14cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e150; }
goto P_0c05e14e;
P_0c05e14e: /* original e400, guest PC 0x0c05e14e */
if(!s->budget--) { s->failed_pc=0x0c05e14eu; return 0; }
r[4]=0x00000000u;
goto P_0c05e150;
P_0c05e150: /* original d34e, guest PC 0x0c05e150 */
if(!s->budget--) { s->failed_pc=0x0c05e150u; return 0; }
r[3]=read(ram,0x0c05e28cu,4);
goto P_0c05e152;
P_0c05e152: /* original 2348, guest PC 0x0c05e152 */
if(!s->budget--) { s->failed_pc=0x0c05e152u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c05e154;
P_0c05e154: /* original 8900, guest PC 0x0c05e154 */
if(!s->budget--) { s->failed_pc=0x0c05e154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e158; }
goto P_0c05e156;
P_0c05e156: /* original 948d, guest PC 0x0c05e156 */
if(!s->budget--) { s->failed_pc=0x0c05e156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e274u,2);
goto P_0c05e158;
P_0c05e158: /* original d34d, guest PC 0x0c05e158 */
if(!s->budget--) { s->failed_pc=0x0c05e158u; return 0; }
r[3]=read(ram,0x0c05e290u,4);
goto P_0c05e15a;
P_0c05e15a: /* original 2342, guest PC 0x0c05e15a */
if(!s->budget--) { s->failed_pc=0x0c05e15au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05e15c;
P_0c05e15c: /* original d24d, guest PC 0x0c05e15c */
if(!s->budget--) { s->failed_pc=0x0c05e15cu; return 0; }
r[2]=read(ram,0x0c05e294u,4);
goto P_0c05e15e;
P_0c05e15e: /* original d14e, guest PC 0x0c05e15e */
if(!s->budget--) { s->failed_pc=0x0c05e15eu; return 0; }
r[1]=read(ram,0x0c05e298u,4);
goto P_0c05e160;
P_0c05e160: /* original 6e12, guest PC 0x0c05e160 */
if(!s->budget--) { s->failed_pc=0x0c05e160u; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c05e162;
P_0c05e162: /* original 2e29, guest PC 0x0c05e162 */
if(!s->budget--) { s->failed_pc=0x0c05e162u; return 0; }
r[14]&=r[2];
goto P_0c05e164;
P_0c05e164: /* original 644c, guest PC 0x0c05e164 */
if(!s->budget--) { s->failed_pc=0x0c05e164u; return 0; }
r[4]=r[4]&255u;
goto P_0c05e166;
P_0c05e166: /* original e30f, guest PC 0x0c05e166 */
if(!s->budget--) { s->failed_pc=0x0c05e166u; return 0; }
r[3]=0x0000000fu;
goto P_0c05e168;
P_0c05e168: /* original 443d, guest PC 0x0c05e168 */
if(!s->budget--) { s->failed_pc=0x0c05e168u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05e16a;
P_0c05e16a: /* original 2e4b, guest PC 0x0c05e16a */
if(!s->budget--) { s->failed_pc=0x0c05e16au; return 0; }
r[14]|=r[4];
goto P_0c05e16c;
P_0c05e16c: /* original 21e2, guest PC 0x0c05e16c */
if(!s->budget--) { s->failed_pc=0x0c05e16cu; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05e16e;
P_0c05e16e: /* original 65e3, guest PC 0x0c05e16e */
if(!s->budget--) { s->failed_pc=0x0c05e16eu; return 0; }
r[5]=r[14];
goto P_0c05e170;
P_0c05e170: /* original d24a, guest PC 0x0c05e170 */
if(!s->budget--) { s->failed_pc=0x0c05e170u; return 0; }
r[2]=read(ram,0x0c05e29cu,4);
goto P_0c05e172;
P_0c05e172: /* original 420b, guest PC 0x0c05e172 */
if(!s->budget--) { s->failed_pc=0x0c05e172u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e176u;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e176u) { target=s->pc; goto dispatch; }
goto P_0c05e176;
P_0c05e174: /* original e448, guest PC 0x0c05e174 */
if(!s->budget--) { s->failed_pc=0x0c05e174u; return 0; }
r[4]=0x00000048u;
goto P_0c05e176;
P_0c05e176: /* original e000, guest PC 0x0c05e176 */
if(!s->budget--) { s->failed_pc=0x0c05e176u; return 0; }
r[0]=0x00000000u;
goto P_0c05e178;
P_0c05e178: /* original 4f26, guest PC 0x0c05e178 */
if(!s->budget--) { s->failed_pc=0x0c05e178u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e17a;
P_0c05e17a: /* original 000b, guest PC 0x0c05e17a */
if(!s->budget--) { s->failed_pc=0x0c05e17au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e17c: /* original 6ef6, guest PC 0x0c05e17c */
if(!s->budget--) { s->failed_pc=0x0c05e17cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05e17eu,s,ram);
P_0c060eba: /* original 0222, guest PC 0x0c060eba */
if(!s->budget--) { s->failed_pc=0x0c060ebau; return 0; }
r[2]=0x0c00f400u;
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
P_0c063446: /* original 4f22, guest PC 0x0c063446 */
if(!s->budget--) { s->failed_pc=0x0c063446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c063448;
P_0c063448: /* original dc2a, guest PC 0x0c063448 */
if(!s->budget--) { s->failed_pc=0x0c063448u; return 0; }
r[12]=read(ram,0x0c0634f4u,4);
goto P_0c06344a;
P_0c06344a: /* original 7ff8, guest PC 0x0c06344a */
if(!s->budget--) { s->failed_pc=0x0c06344au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06344c;
P_0c06344c: /* original 2232, guest PC 0x0c06344c */
if(!s->budget--) { s->failed_pc=0x0c06344cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06344e;
P_0c06344e: /* original 6433, guest PC 0x0c06344e */
if(!s->budget--) { s->failed_pc=0x0c06344eu; return 0; }
r[4]=r[3];
goto P_0c063450;
P_0c063450: /* original d32a, guest PC 0x0c063450 */
if(!s->budget--) { s->failed_pc=0x0c063450u; return 0; }
r[3]=read(ram,0x0c0634fcu,4);
goto P_0c063452;
P_0c063452: /* original 430b, guest PC 0x0c063452 */
if(!s->budget--) { s->failed_pc=0x0c063452u; return 0; }
target=r[3];
r[16]=code_base|0x0c063456u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063456u) { target=s->pc; goto dispatch; }
goto P_0c063456;
P_0c063454: /* original 0009, guest PC 0x0c063454 */
if(!s->budget--) { s->failed_pc=0x0c063454u; return 0; }
goto P_0c063456;
P_0c063456: /* original 1f01, guest PC 0x0c063456 */
if(!s->budget--) { s->failed_pc=0x0c063456u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c063458;
P_0c063458: /* original d328, guest PC 0x0c063458 */
if(!s->budget--) { s->failed_pc=0x0c063458u; return 0; }
r[3]=read(ram,0x0c0634fcu,4);
goto P_0c06345a;
P_0c06345a: /* original 430b, guest PC 0x0c06345a */
if(!s->budget--) { s->failed_pc=0x0c06345au; return 0; }
target=r[3];
r[16]=code_base|0x0c06345eu;
r[4]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06345eu) { target=s->pc; goto dispatch; }
goto P_0c06345e;
P_0c06345c: /* original e404, guest PC 0x0c06345c */
if(!s->budget--) { s->failed_pc=0x0c06345cu; return 0; }
r[4]=0x00000004u;
goto P_0c06345e;
P_0c06345e: /* original 6403, guest PC 0x0c06345e */
if(!s->budget--) { s->failed_pc=0x0c06345eu; return 0; }
r[4]=r[0];
goto P_0c063460;
P_0c063460: /* original d227, guest PC 0x0c063460 */
if(!s->budget--) { s->failed_pc=0x0c063460u; return 0; }
r[2]=read(ram,0x0c063500u,4);
goto P_0c063462;
P_0c063462: /* original e505, guest PC 0x0c063462 */
if(!s->budget--) { s->failed_pc=0x0c063462u; return 0; }
r[5]=0x00000005u;
goto P_0c063464;
P_0c063464: /* original 2252, guest PC 0x0c063464 */
if(!s->budget--) { s->failed_pc=0x0c063464u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c063466;
P_0c063466: /* original d327, guest PC 0x0c063466 */
if(!s->budget--) { s->failed_pc=0x0c063466u; return 0; }
r[3]=read(ram,0x0c063504u,4);
goto P_0c063468;
P_0c063468: /* original 51f1, guest PC 0x0c063468 */
if(!s->budget--) { s->failed_pc=0x0c063468u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c06346a;
P_0c06346a: /* original 3130, guest PC 0x0c06346a */
if(!s->budget--) { s->failed_pc=0x0c06346au; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c06346c;
P_0c06346c: /* original 8b03, guest PC 0x0c06346c */
if(!s->budget--) { s->failed_pc=0x0c06346cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063476; }
goto P_0c06346e;
P_0c06346e: /* original 6043, guest PC 0x0c06346e */
if(!s->budget--) { s->failed_pc=0x0c06346eu; return 0; }
r[0]=r[4];
goto P_0c063470;
P_0c063470: /* original 0009, guest PC 0x0c063470 */
if(!s->budget--) { s->failed_pc=0x0c063470u; return 0; }
goto P_0c063472;
P_0c063472: /* original 8801, guest PC 0x0c063472 */
if(!s->budget--) { s->failed_pc=0x0c063472u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063474;
P_0c063474: /* original 8b02, guest PC 0x0c063474 */
if(!s->budget--) { s->failed_pc=0x0c063474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06347c; }
goto P_0c063476;
P_0c063476: /* original d322, guest PC 0x0c063476 */
if(!s->budget--) { s->failed_pc=0x0c063476u; return 0; }
r[3]=read(ram,0x0c063500u,4);
goto P_0c063478;
P_0c063478: /* original a00a, guest PC 0x0c063478 */
if(!s->budget--) { s->failed_pc=0x0c063478u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c063490;
P_0c06347a: /* original 2352, guest PC 0x0c06347a */
if(!s->budget--) { s->failed_pc=0x0c06347au; return 0; }
write(ram,r[3],r[5],4);
goto P_0c06347c;
P_0c06347c: /* original e111, guest PC 0x0c06347c */
if(!s->budget--) { s->failed_pc=0x0c06347cu; return 0; }
r[1]=0x00000011u;
goto P_0c06347e;
P_0c06347e: /* original 3412, guest PC 0x0c06347e */
if(!s->budget--) { s->failed_pc=0x0c06347eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[1])!=0);
goto P_0c063480;
P_0c063480: /* original 8b06, guest PC 0x0c063480 */
if(!s->budget--) { s->failed_pc=0x0c063480u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063490; }
goto P_0c063482;
P_0c063482: /* original e006, guest PC 0x0c063482 */
if(!s->budget--) { s->failed_pc=0x0c063482u; return 0; }
r[0]=0x00000006u;
goto P_0c063484;
P_0c063484: /* original d21e, guest PC 0x0c063484 */
if(!s->budget--) { s->failed_pc=0x0c063484u; return 0; }
r[2]=read(ram,0x0c063500u,4);
goto P_0c063486;
P_0c063486: /* original 2202, guest PC 0x0c063486 */
if(!s->budget--) { s->failed_pc=0x0c063486u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c063488;
P_0c063488: /* original d31f, guest PC 0x0c063488 */
if(!s->budget--) { s->failed_pc=0x0c063488u; return 0; }
r[3]=read(ram,0x0c063508u,4);
goto P_0c06348a;
P_0c06348a: /* original d01b, guest PC 0x0c06348a */
if(!s->budget--) { s->failed_pc=0x0c06348au; return 0; }
r[0]=read(ram,0x0c0634f8u,4);
goto P_0c06348c;
P_0c06348c: /* original 2032, guest PC 0x0c06348c */
if(!s->budget--) { s->failed_pc=0x0c06348cu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c06348e;
P_0c06348e: /* original dc1f, guest PC 0x0c06348e */
if(!s->budget--) { s->failed_pc=0x0c06348eu; return 0; }
r[12]=read(ram,0x0c06350cu,4);
goto P_0c063490;
P_0c063490: /* original d31f, guest PC 0x0c063490 */
if(!s->budget--) { s->failed_pc=0x0c063490u; return 0; }
r[3]=read(ram,0x0c063510u,4);
goto P_0c063492;
P_0c063492: /* original e56f, guest PC 0x0c063492 */
if(!s->budget--) { s->failed_pc=0x0c063492u; return 0; }
r[5]=0x0000006fu;
goto P_0c063494;
P_0c063494: /* original 6632, guest PC 0x0c063494 */
if(!s->budget--) { s->failed_pc=0x0c063494u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c063496;
P_0c063496: /* original 6063, guest PC 0x0c063496 */
if(!s->budget--) { s->failed_pc=0x0c063496u; return 0; }
r[0]=r[6];
goto P_0c063498;
P_0c063498: /* original 0009, guest PC 0x0c063498 */
if(!s->budget--) { s->failed_pc=0x0c063498u; return 0; }
goto P_0c06349a;
P_0c06349a: /* original 8800, guest PC 0x0c06349a */
if(!s->budget--) { s->failed_pc=0x0c06349au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c06349c;
P_0c06349c: /* original 8d10, guest PC 0x0c06349c */
if(!s->budget--) { s->failed_pc=0x0c06349cu; return 0; }
cond=r[17]&1u;
r[4]=0x0000007fu;
if(cond) { goto P_0c0634c0; }
goto P_0c0634a0;
P_0c06349e: /* original e47f, guest PC 0x0c06349e */
if(!s->budget--) { s->failed_pc=0x0c06349eu; return 0; }
r[4]=0x0000007fu;
goto P_0c0634a0;
P_0c0634a0: /* original 8801, guest PC 0x0c0634a0 */
if(!s->budget--) { s->failed_pc=0x0c0634a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0634a2;
P_0c0634a2: /* original 8911, guest PC 0x0c0634a2 */
if(!s->budget--) { s->failed_pc=0x0c0634a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634c8; }
goto P_0c0634a4;
P_0c0634a4: /* original 8802, guest PC 0x0c0634a4 */
if(!s->budget--) { s->failed_pc=0x0c0634a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0634a6;
P_0c0634a6: /* original 8914, guest PC 0x0c0634a6 */
if(!s->budget--) { s->failed_pc=0x0c0634a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634d2; }
goto P_0c0634a8;
P_0c0634a8: /* original 8804, guest PC 0x0c0634a8 */
if(!s->budget--) { s->failed_pc=0x0c0634a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0634aa;
P_0c0634aa: /* original 8916, guest PC 0x0c0634aa */
if(!s->budget--) { s->failed_pc=0x0c0634aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634ac;
P_0c0634ac: /* original 8805, guest PC 0x0c0634ac */
if(!s->budget--) { s->failed_pc=0x0c0634acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0634ae;
P_0c0634ae: /* original 8914, guest PC 0x0c0634ae */
if(!s->budget--) { s->failed_pc=0x0c0634aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634b0;
P_0c0634b0: /* original 8806, guest PC 0x0c0634b0 */
if(!s->budget--) { s->failed_pc=0x0c0634b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0634b2;
P_0c0634b2: /* original 8912, guest PC 0x0c0634b2 */
if(!s->budget--) { s->failed_pc=0x0c0634b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634da; }
goto P_0c0634b4;
P_0c0634b4: /* original 8808, guest PC 0x0c0634b4 */
if(!s->budget--) { s->failed_pc=0x0c0634b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0634b6;
P_0c0634b6: /* original 8914, guest PC 0x0c0634b6 */
if(!s->budget--) { s->failed_pc=0x0c0634b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634e2; }
goto P_0c0634b8;
P_0c0634b8: /* original 8809, guest PC 0x0c0634b8 */
if(!s->budget--) { s->failed_pc=0x0c0634b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0634ba;
P_0c0634ba: /* original 8915, guest PC 0x0c0634ba */
if(!s->budget--) { s->failed_pc=0x0c0634bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0634e8; }
goto P_0c0634bc;
P_0c0634bc: /* original a02e, guest PC 0x0c0634bc */
if(!s->budget--) { s->failed_pc=0x0c0634bcu; return 0; }
goto P_0c06351c;
P_0c0634be: /* original 0009, guest PC 0x0c0634be */
if(!s->budget--) { s->failed_pc=0x0c0634beu; return 0; }
goto P_0c0634c0;
P_0c0634c0: /* original d114, guest PC 0x0c0634c0 */
if(!s->budget--) { s->failed_pc=0x0c0634c0u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634c2;
P_0c0634c2: /* original e200, guest PC 0x0c0634c2 */
if(!s->budget--) { s->failed_pc=0x0c0634c2u; return 0; }
r[2]=0x00000000u;
goto P_0c0634c4;
P_0c0634c4: /* original a003, guest PC 0x0c0634c4 */
if(!s->budget--) { s->failed_pc=0x0c0634c4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634ce;
P_0c0634c6: /* original 2122, guest PC 0x0c0634c6 */
if(!s->budget--) { s->failed_pc=0x0c0634c6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634c8;
P_0c0634c8: /* original d212, guest PC 0x0c0634c8 */
if(!s->budget--) { s->failed_pc=0x0c0634c8u; return 0; }
r[2]=read(ram,0x0c063514u,4);
goto P_0c0634ca;
P_0c0634ca: /* original e001, guest PC 0x0c0634ca */
if(!s->budget--) { s->failed_pc=0x0c0634cau; return 0; }
r[0]=0x00000001u;
goto P_0c0634cc;
P_0c0634cc: /* original 2202, guest PC 0x0c0634cc */
if(!s->budget--) { s->failed_pc=0x0c0634ccu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0634ce;
P_0c0634ce: /* original a028, guest PC 0x0c0634ce */
if(!s->budget--) { s->failed_pc=0x0c0634ceu; return 0; }
r[13]=0x00000000u;
goto P_0c063522;
P_0c0634d0: /* original ed00, guest PC 0x0c0634d0 */
if(!s->budget--) { s->failed_pc=0x0c0634d0u; return 0; }
r[13]=0x00000000u;
goto P_0c0634d2;
P_0c0634d2: /* original e203, guest PC 0x0c0634d2 */
if(!s->budget--) { s->failed_pc=0x0c0634d2u; return 0; }
r[2]=0x00000003u;
goto P_0c0634d4;
P_0c0634d4: /* original d10f, guest PC 0x0c0634d4 */
if(!s->budget--) { s->failed_pc=0x0c0634d4u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634d6;
P_0c0634d6: /* original a023, guest PC 0x0c0634d6 */
if(!s->budget--) { s->failed_pc=0x0c0634d6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c063520;
P_0c0634d8: /* original 2122, guest PC 0x0c0634d8 */
if(!s->budget--) { s->failed_pc=0x0c0634d8u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0634da;
P_0c0634da: /* original d00e, guest PC 0x0c0634da */
if(!s->budget--) { s->failed_pc=0x0c0634dau; return 0; }
r[0]=read(ram,0x0c063514u,4);
goto P_0c0634dc;
P_0c0634dc: /* original dd0e, guest PC 0x0c0634dc */
if(!s->budget--) { s->failed_pc=0x0c0634dcu; return 0; }
r[13]=read(ram,0x0c063518u,4);
goto P_0c0634de;
P_0c0634de: /* original a020, guest PC 0x0c0634de */
if(!s->budget--) { s->failed_pc=0x0c0634deu; return 0; }
write(ram,r[0],r[4],4);
goto P_0c063522;
P_0c0634e0: /* original 2042, guest PC 0x0c0634e0 */
if(!s->budget--) { s->failed_pc=0x0c0634e0u; return 0; }
write(ram,r[0],r[4],4);
goto P_0c0634e2;
P_0c0634e2: /* original d10c, guest PC 0x0c0634e2 */
if(!s->budget--) { s->failed_pc=0x0c0634e2u; return 0; }
r[1]=read(ram,0x0c063514u,4);
goto P_0c0634e4;
P_0c0634e4: /* original a01c, guest PC 0x0c0634e4 */
if(!s->budget--) { s->failed_pc=0x0c0634e4u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c063520;
P_0c0634e6: /* original 2142, guest PC 0x0c0634e6 */
if(!s->budget--) { s->failed_pc=0x0c0634e6u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0634e8;
P_0c0634e8: /* original d20a, guest PC 0x0c0634e8 */
if(!s->budget--) { s->failed_pc=0x0c0634e8u; return 0; }
r[2]=read(ram,0x0c063514u,4);
goto P_0c0634ea;
P_0c0634ea: /* original a019, guest PC 0x0c0634ea */
if(!s->budget--) { s->failed_pc=0x0c0634eau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c063520;
P_0c0634ec: /* original 2252, guest PC 0x0c0634ec */
if(!s->budget--) { s->failed_pc=0x0c0634ecu; return 0; }
write(ram,r[2],r[5],4);
return vf3_matrix_family(0x0c0634eeu,s,ram);
P_0c06351c: /* original d044, guest PC 0x0c06351c */
if(!s->budget--) { s->failed_pc=0x0c06351cu; return 0; }
r[0]=read(ram,0x0c063630u,4);
goto P_0c06351e;
P_0c06351e: /* original 2052, guest PC 0x0c06351e */
if(!s->budget--) { s->failed_pc=0x0c06351eu; return 0; }
write(ram,r[0],r[5],4);
goto P_0c063520;
P_0c063520: /* original 9d79, guest PC 0x0c063520 */
if(!s->budget--) { s->failed_pc=0x0c063520u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063616u,2);
goto P_0c063522;
P_0c063522: /* original de44, guest PC 0x0c063522 */
if(!s->budget--) { s->failed_pc=0x0c063522u; return 0; }
r[14]=read(ram,0x0c063634u,4);
goto P_0c063524;
P_0c063524: /* original 9478, guest PC 0x0c063524 */
if(!s->budget--) { s->failed_pc=0x0c063524u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063618u,2);
goto P_0c063526;
P_0c063526: /* original 4e0b, guest PC 0x0c063526 */
if(!s->budget--) { s->failed_pc=0x0c063526u; return 0; }
target=r[14];
r[16]=code_base|0x0c06352au;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06352au) { target=s->pc; goto dispatch; }
goto P_0c06352a;
P_0c063528: /* original 65c3, guest PC 0x0c063528 */
if(!s->budget--) { s->failed_pc=0x0c063528u; return 0; }
r[5]=r[12];
goto P_0c06352a;
P_0c06352a: /* original 9476, guest PC 0x0c06352a */
if(!s->budget--) { s->failed_pc=0x0c06352au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361au,2);
goto P_0c06352c;
P_0c06352c: /* original 4e0b, guest PC 0x0c06352c */
if(!s->budget--) { s->failed_pc=0x0c06352cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063530u;
r[5]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063530u) { target=s->pc; goto dispatch; }
goto P_0c063530;
P_0c06352e: /* original e520, guest PC 0x0c06352e */
if(!s->budget--) { s->failed_pc=0x0c06352eu; return 0; }
r[5]=0x00000020u;
goto P_0c063530;
P_0c063530: /* original e500, guest PC 0x0c063530 */
if(!s->budget--) { s->failed_pc=0x0c063530u; return 0; }
r[5]=0x00000000u;
goto P_0c063532;
P_0c063532: /* original 4e0b, guest PC 0x0c063532 */
if(!s->budget--) { s->failed_pc=0x0c063532u; return 0; }
target=r[14];
r[16]=code_base|0x0c063536u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063536u) { target=s->pc; goto dispatch; }
goto P_0c063536;
P_0c063534: /* original e408, guest PC 0x0c063534 */
if(!s->budget--) { s->failed_pc=0x0c063534u; return 0; }
r[4]=0x00000008u;
goto P_0c063536;
P_0c063536: /* original 9471, guest PC 0x0c063536 */
if(!s->budget--) { s->failed_pc=0x0c063536u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361cu,2);
goto P_0c063538;
P_0c063538: /* original 4e0b, guest PC 0x0c063538 */
if(!s->budget--) { s->failed_pc=0x0c063538u; return 0; }
target=r[14];
r[16]=code_base|0x0c06353cu;
r[5]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06353cu) { target=s->pc; goto dispatch; }
goto P_0c06353c;
P_0c06353a: /* original e503, guest PC 0x0c06353a */
if(!s->budget--) { s->failed_pc=0x0c06353au; return 0; }
r[5]=0x00000003u;
goto P_0c06353c;
P_0c06353c: /* original e509, guest PC 0x0c06353c */
if(!s->budget--) { s->failed_pc=0x0c06353cu; return 0; }
r[5]=0x00000009u;
goto P_0c06353e;
P_0c06353e: /* original 4e0b, guest PC 0x0c06353e */
if(!s->budget--) { s->failed_pc=0x0c06353eu; return 0; }
target=r[14];
r[16]=code_base|0x0c063542u;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063542u) { target=s->pc; goto dispatch; }
goto P_0c063542;
P_0c063540: /* original e448, guest PC 0x0c063540 */
if(!s->budget--) { s->failed_pc=0x0c063540u; return 0; }
r[4]=0x00000048u;
goto P_0c063542;
P_0c063542: /* original d23d, guest PC 0x0c063542 */
if(!s->budget--) { s->failed_pc=0x0c063542u; return 0; }
r[2]=read(ram,0x0c063638u,4);
goto P_0c063544;
P_0c063544: /* original 6022, guest PC 0x0c063544 */
if(!s->budget--) { s->failed_pc=0x0c063544u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063546;
P_0c063546: /* original c801, guest PC 0x0c063546 */
if(!s->budget--) { s->failed_pc=0x0c063546u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c063548;
P_0c063548: /* original 8d03, guest PC 0x0c063548 */
if(!s->budget--) { s->failed_pc=0x0c063548u; return 0; }
cond=r[17]&1u;
r[4]=0x00000044u;
if(cond) { goto P_0c063552; }
goto P_0c06354c;
P_0c06354a: /* original e444, guest PC 0x0c06354a */
if(!s->budget--) { s->failed_pc=0x0c06354au; return 0; }
r[4]=0x00000044u;
goto P_0c06354c;
P_0c06354c: /* original d53b, guest PC 0x0c06354c */
if(!s->budget--) { s->failed_pc=0x0c06354cu; return 0; }
r[5]=read(ram,0x0c06363cu,4);
goto P_0c06354e;
P_0c06354e: /* original a001, guest PC 0x0c06354e */
if(!s->budget--) { s->failed_pc=0x0c06354eu; return 0; }
goto P_0c063554;
P_0c063550: /* original 0009, guest PC 0x0c063550 */
if(!s->budget--) { s->failed_pc=0x0c063550u; return 0; }
goto P_0c063552;
P_0c063552: /* original e500, guest PC 0x0c063552 */
if(!s->budget--) { s->failed_pc=0x0c063552u; return 0; }
r[5]=0x00000000u;
goto P_0c063554;
P_0c063554: /* original d13a, guest PC 0x0c063554 */
if(!s->budget--) { s->failed_pc=0x0c063554u; return 0; }
r[1]=read(ram,0x0c063640u,4);
goto P_0c063556;
P_0c063556: /* original 410b, guest PC 0x0c063556 */
if(!s->budget--) { s->failed_pc=0x0c063556u; return 0; }
target=r[1];
r[16]=code_base|0x0c06355au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06355au) { target=s->pc; goto dispatch; }
goto P_0c06355a;
P_0c063558: /* original 0009, guest PC 0x0c063558 */
if(!s->budget--) { s->failed_pc=0x0c063558u; return 0; }
goto P_0c06355a;
P_0c06355a: /* original e500, guest PC 0x0c06355a */
if(!s->budget--) { s->failed_pc=0x0c06355au; return 0; }
r[5]=0x00000000u;
goto P_0c06355c;
P_0c06355c: /* original 4e0b, guest PC 0x0c06355c */
if(!s->budget--) { s->failed_pc=0x0c06355cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063560u;
r[4]=0x0000005cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063560u) { target=s->pc; goto dispatch; }
goto P_0c063560;
P_0c06355e: /* original e45c, guest PC 0x0c06355e */
if(!s->budget--) { s->failed_pc=0x0c06355eu; return 0; }
r[4]=0x0000005cu;
goto P_0c063560;
P_0c063560: /* original d538, guest PC 0x0c063560 */
if(!s->budget--) { s->failed_pc=0x0c063560u; return 0; }
r[5]=read(ram,0x0c063644u,4);
goto P_0c063562;
P_0c063562: /* original 4e0b, guest PC 0x0c063562 */
if(!s->budget--) { s->failed_pc=0x0c063562u; return 0; }
target=r[14];
r[16]=code_base|0x0c063566u;
r[4]=0x00000068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063566u) { target=s->pc; goto dispatch; }
goto P_0c063566;
P_0c063564: /* original e468, guest PC 0x0c063564 */
if(!s->budget--) { s->failed_pc=0x0c063564u; return 0; }
r[4]=0x00000068u;
goto P_0c063566;
P_0c063566: /* original d538, guest PC 0x0c063566 */
if(!s->budget--) { s->failed_pc=0x0c063566u; return 0; }
r[5]=read(ram,0x0c063648u,4);
goto P_0c063568;
P_0c063568: /* original 4e0b, guest PC 0x0c063568 */
if(!s->budget--) { s->failed_pc=0x0c063568u; return 0; }
target=r[14];
r[16]=code_base|0x0c06356cu;
r[4]=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06356cu) { target=s->pc; goto dispatch; }
goto P_0c06356c;
P_0c06356a: /* original e46c, guest PC 0x0c06356a */
if(!s->budget--) { s->failed_pc=0x0c06356au; return 0; }
r[4]=0x0000006cu;
goto P_0c06356c;
P_0c06356c: /* original d337, guest PC 0x0c06356c */
if(!s->budget--) { s->failed_pc=0x0c06356cu; return 0; }
r[3]=read(ram,0x0c06364cu,4);
goto P_0c06356e;
P_0c06356e: /* original 6032, guest PC 0x0c06356e */
if(!s->budget--) { s->failed_pc=0x0c06356eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063570;
P_0c063570: /* original 8806, guest PC 0x0c063570 */
if(!s->budget--) { s->failed_pc=0x0c063570u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c063572;
P_0c063572: /* original 8b07, guest PC 0x0c063572 */
if(!s->budget--) { s->failed_pc=0x0c063572u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063584; }
goto P_0c063574;
P_0c063574: /* original d536, guest PC 0x0c063574 */
if(!s->budget--) { s->failed_pc=0x0c063574u; return 0; }
r[5]=read(ram,0x0c063650u,4);
goto P_0c063576;
P_0c063576: /* original 9452, guest PC 0x0c063576 */
if(!s->budget--) { s->failed_pc=0x0c063576u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361eu,2);
goto P_0c063578;
P_0c063578: /* original 4e0b, guest PC 0x0c063578 */
if(!s->budget--) { s->failed_pc=0x0c063578u; return 0; }
target=r[14];
r[16]=code_base|0x0c06357cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06357cu) { target=s->pc; goto dispatch; }
goto P_0c06357c;
P_0c06357a: /* original 0009, guest PC 0x0c06357a */
if(!s->budget--) { s->failed_pc=0x0c06357au; return 0; }
goto P_0c06357c;
P_0c06357c: /* original d335, guest PC 0x0c06357c */
if(!s->budget--) { s->failed_pc=0x0c06357cu; return 0; }
r[3]=read(ram,0x0c063654u,4);
goto P_0c06357e;
P_0c06357e: /* original 944f, guest PC 0x0c06357e */
if(!s->budget--) { s->failed_pc=0x0c06357eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063620u,2);
goto P_0c063580;
P_0c063580: /* original a002, guest PC 0x0c063580 */
if(!s->budget--) { s->failed_pc=0x0c063580u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063588;
P_0c063582: /* original 6532, guest PC 0x0c063582 */
if(!s->budget--) { s->failed_pc=0x0c063582u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063584;
P_0c063584: /* original d534, guest PC 0x0c063584 */
if(!s->budget--) { s->failed_pc=0x0c063584u; return 0; }
r[5]=read(ram,0x0c063658u,4);
goto P_0c063586;
P_0c063586: /* original 944a, guest PC 0x0c063586 */
if(!s->budget--) { s->failed_pc=0x0c063586u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361eu,2);
goto P_0c063588;
P_0c063588: /* original 4e0b, guest PC 0x0c063588 */
if(!s->budget--) { s->failed_pc=0x0c063588u; return 0; }
target=r[14];
r[16]=code_base|0x0c06358cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06358cu) { target=s->pc; goto dispatch; }
goto P_0c06358c;
P_0c06358a: /* original 0009, guest PC 0x0c06358a */
if(!s->budget--) { s->failed_pc=0x0c06358au; return 0; }
goto P_0c06358c;
P_0c06358c: /* original 9545, guest PC 0x0c06358c */
if(!s->budget--) { s->failed_pc=0x0c06358cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06361au,2);
goto P_0c06358e;
P_0c06358e: /* original 4e0b, guest PC 0x0c06358e */
if(!s->budget--) { s->failed_pc=0x0c06358eu; return 0; }
target=r[14];
r[16]=code_base|0x0c063592u;
r[4]=0x0000004cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063592u) { target=s->pc; goto dispatch; }
goto P_0c063592;
P_0c063590: /* original e44c, guest PC 0x0c063590 */
if(!s->budget--) { s->failed_pc=0x0c063590u; return 0; }
r[4]=0x0000004cu;
goto P_0c063592;
P_0c063592: /* original e500, guest PC 0x0c063592 */
if(!s->budget--) { s->failed_pc=0x0c063592u; return 0; }
r[5]=0x00000000u;
goto P_0c063594;
P_0c063594: /* original 4e0b, guest PC 0x0c063594 */
if(!s->budget--) { s->failed_pc=0x0c063594u; return 0; }
target=r[14];
r[16]=code_base|0x0c063598u;
r[4]=0x00000074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063598u) { target=s->pc; goto dispatch; }
goto P_0c063598;
P_0c063596: /* original e474, guest PC 0x0c063596 */
if(!s->budget--) { s->failed_pc=0x0c063596u; return 0; }
r[4]=0x00000074u;
goto P_0c063598;
P_0c063598: /* original d530, guest PC 0x0c063598 */
if(!s->budget--) { s->failed_pc=0x0c063598u; return 0; }
r[5]=read(ram,0x0c06365cu,4);
goto P_0c06359a;
P_0c06359a: /* original 4e0b, guest PC 0x0c06359a */
if(!s->budget--) { s->failed_pc=0x0c06359au; return 0; }
target=r[14];
r[16]=code_base|0x0c06359eu;
r[4]=0x00000078u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06359eu) { target=s->pc; goto dispatch; }
goto P_0c06359e;
P_0c06359c: /* original e478, guest PC 0x0c06359c */
if(!s->budget--) { s->failed_pc=0x0c06359cu; return 0; }
r[4]=0x00000078u;
goto P_0c06359e;
P_0c06359e: /* original 9440, guest PC 0x0c06359e */
if(!s->budget--) { s->failed_pc=0x0c06359eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063622u,2);
goto P_0c0635a0;
P_0c0635a0: /* original 4e0b, guest PC 0x0c0635a0 */
if(!s->budget--) { s->failed_pc=0x0c0635a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635a4u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635a4u) { target=s->pc; goto dispatch; }
goto P_0c0635a4;
P_0c0635a2: /* original e500, guest PC 0x0c0635a2 */
if(!s->budget--) { s->failed_pc=0x0c0635a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0635a4;
P_0c0635a4: /* original 65d3, guest PC 0x0c0635a4 */
if(!s->budget--) { s->failed_pc=0x0c0635a4u; return 0; }
r[5]=r[13];
goto P_0c0635a6;
P_0c0635a6: /* original 4e0b, guest PC 0x0c0635a6 */
if(!s->budget--) { s->failed_pc=0x0c0635a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635aau;
r[4]=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635aau) { target=s->pc; goto dispatch; }
goto P_0c0635aa;
P_0c0635a8: /* original e430, guest PC 0x0c0635a8 */
if(!s->budget--) { s->failed_pc=0x0c0635a8u; return 0; }
r[4]=0x00000030u;
goto P_0c0635aa;
P_0c0635aa: /* original d52d, guest PC 0x0c0635aa */
if(!s->budget--) { s->failed_pc=0x0c0635aau; return 0; }
r[5]=read(ram,0x0c063660u,4);
goto P_0c0635ac;
P_0c0635ac: /* original 943a, guest PC 0x0c0635ac */
if(!s->budget--) { s->failed_pc=0x0c0635acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063624u,2);
goto P_0c0635ae;
P_0c0635ae: /* original 4e0b, guest PC 0x0c0635ae */
if(!s->budget--) { s->failed_pc=0x0c0635aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0635b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635b2u) { target=s->pc; goto dispatch; }
goto P_0c0635b2;
P_0c0635b0: /* original 0009, guest PC 0x0c0635b0 */
if(!s->budget--) { s->failed_pc=0x0c0635b0u; return 0; }
goto P_0c0635b2;
P_0c0635b2: /* original d52b, guest PC 0x0c0635b2 */
if(!s->budget--) { s->failed_pc=0x0c0635b2u; return 0; }
r[5]=read(ram,0x0c063660u,4);
goto P_0c0635b4;
P_0c0635b4: /* original 9437, guest PC 0x0c0635b4 */
if(!s->budget--) { s->failed_pc=0x0c0635b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063626u,2);
goto P_0c0635b6;
P_0c0635b6: /* original 4e0b, guest PC 0x0c0635b6 */
if(!s->budget--) { s->failed_pc=0x0c0635b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635bau) { target=s->pc; goto dispatch; }
goto P_0c0635ba;
P_0c0635b8: /* original 0009, guest PC 0x0c0635b8 */
if(!s->budget--) { s->failed_pc=0x0c0635b8u; return 0; }
goto P_0c0635ba;
P_0c0635ba: /* original 9435, guest PC 0x0c0635ba */
if(!s->budget--) { s->failed_pc=0x0c0635bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063628u,2);
goto P_0c0635bc;
P_0c0635bc: /* original 4e0b, guest PC 0x0c0635bc */
if(!s->budget--) { s->failed_pc=0x0c0635bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0635c0u;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635c0u) { target=s->pc; goto dispatch; }
goto P_0c0635c0;
P_0c0635be: /* original e500, guest PC 0x0c0635be */
if(!s->budget--) { s->failed_pc=0x0c0635beu; return 0; }
r[5]=0x00000000u;
goto P_0c0635c0;
P_0c0635c0: /* original 9433, guest PC 0x0c0635c0 */
if(!s->budget--) { s->failed_pc=0x0c0635c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362au,2);
goto P_0c0635c2;
P_0c0635c2: /* original 4e0b, guest PC 0x0c0635c2 */
if(!s->budget--) { s->failed_pc=0x0c0635c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635c6u;
r[5]=0xffffffffu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635c6u) { target=s->pc; goto dispatch; }
goto P_0c0635c6;
P_0c0635c4: /* original e5ff, guest PC 0x0c0635c4 */
if(!s->budget--) { s->failed_pc=0x0c0635c4u; return 0; }
r[5]=0xffffffffu;
goto P_0c0635c6;
P_0c0635c6: /* original e507, guest PC 0x0c0635c6 */
if(!s->budget--) { s->failed_pc=0x0c0635c6u; return 0; }
r[5]=0x00000007u;
goto P_0c0635c8;
P_0c0635c8: /* original 6453, guest PC 0x0c0635c8 */
if(!s->budget--) { s->failed_pc=0x0c0635c8u; return 0; }
r[4]=r[5];
goto P_0c0635ca;
P_0c0635ca: /* original 4e0b, guest PC 0x0c0635ca */
if(!s->budget--) { s->failed_pc=0x0c0635cau; return 0; }
target=r[14];
r[16]=code_base|0x0c0635ceu;
r[4]+=0x00000079u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635ceu) { target=s->pc; goto dispatch; }
goto P_0c0635ce;
P_0c0635cc: /* original 7479, guest PC 0x0c0635cc */
if(!s->budget--) { s->failed_pc=0x0c0635ccu; return 0; }
r[4]+=0x00000079u;
goto P_0c0635ce;
P_0c0635ce: /* original d525, guest PC 0x0c0635ce */
if(!s->budget--) { s->failed_pc=0x0c0635ceu; return 0; }
r[5]=read(ram,0x0c063664u,4);
goto P_0c0635d0;
P_0c0635d0: /* original 942c, guest PC 0x0c0635d0 */
if(!s->budget--) { s->failed_pc=0x0c0635d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362cu,2);
goto P_0c0635d2;
P_0c0635d2: /* original 4e0b, guest PC 0x0c0635d2 */
if(!s->budget--) { s->failed_pc=0x0c0635d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635d6u) { target=s->pc; goto dispatch; }
goto P_0c0635d6;
P_0c0635d4: /* original 0009, guest PC 0x0c0635d4 */
if(!s->budget--) { s->failed_pc=0x0c0635d4u; return 0; }
goto P_0c0635d6;
P_0c0635d6: /* original d524, guest PC 0x0c0635d6 */
if(!s->budget--) { s->failed_pc=0x0c0635d6u; return 0; }
r[5]=read(ram,0x0c063668u,4);
goto P_0c0635d8;
P_0c0635d8: /* original 9429, guest PC 0x0c0635d8 */
if(!s->budget--) { s->failed_pc=0x0c0635d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06362eu,2);
goto P_0c0635da;
P_0c0635da: /* original 4e0b, guest PC 0x0c0635da */
if(!s->budget--) { s->failed_pc=0x0c0635dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0635deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635deu) { target=s->pc; goto dispatch; }
goto P_0c0635de;
P_0c0635dc: /* original 0009, guest PC 0x0c0635dc */
if(!s->budget--) { s->failed_pc=0x0c0635dcu; return 0; }
goto P_0c0635de;
P_0c0635de: /* original e501, guest PC 0x0c0635de */
if(!s->budget--) { s->failed_pc=0x0c0635deu; return 0; }
r[5]=0x00000001u;
goto P_0c0635e0;
P_0c0635e0: /* original 4e0b, guest PC 0x0c0635e0 */
if(!s->budget--) { s->failed_pc=0x0c0635e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0635e4u;
r[4]=0x00000074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0635e4u) { target=s->pc; goto dispatch; }
goto P_0c0635e4;
P_0c0635e2: /* original e474, guest PC 0x0c0635e2 */
if(!s->budget--) { s->failed_pc=0x0c0635e2u; return 0; }
r[4]=0x00000074u;
goto P_0c0635e4;
P_0c0635e4: /* original d319, guest PC 0x0c0635e4 */
if(!s->budget--) { s->failed_pc=0x0c0635e4u; return 0; }
r[3]=read(ram,0x0c06364cu,4);
goto P_0c0635e6;
P_0c0635e6: /* original 6032, guest PC 0x0c0635e6 */
if(!s->budget--) { s->failed_pc=0x0c0635e6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0635e8;
P_0c0635e8: /* original 8806, guest PC 0x0c0635e8 */
if(!s->budget--) { s->failed_pc=0x0c0635e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0635ea;
P_0c0635ea: /* original 8901, guest PC 0x0c0635ea */
if(!s->budget--) { s->failed_pc=0x0c0635eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0635f0; }
goto P_0c0635ec;
P_0c0635ec: /* original affe, guest PC 0x0c0635ec */
if(!s->budget--) { s->failed_pc=0x0c0635ecu; return 0; }
goto P_0c0635ec;
P_0c0635ee: /* original 0009, guest PC 0x0c0635ee */
if(!s->budget--) { s->failed_pc=0x0c0635eeu; return 0; }
goto P_0c0635f0;
P_0c0635f0: /* original d216, guest PC 0x0c0635f0 */
if(!s->budget--) { s->failed_pc=0x0c0635f0u; return 0; }
r[2]=read(ram,0x0c06364cu,4);
goto P_0c0635f2;
P_0c0635f2: /* original 6022, guest PC 0x0c0635f2 */
if(!s->budget--) { s->failed_pc=0x0c0635f2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0635f4;
P_0c0635f4: /* original 8806, guest PC 0x0c0635f4 */
if(!s->budget--) { s->failed_pc=0x0c0635f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0635f6;
P_0c0635f6: /* original 8f03, guest PC 0x0c0635f6 */
if(!s->budget--) { s->failed_pc=0x0c0635f6u; return 0; }
cond=r[17]&1u;
r[4]=0x0000007cu;
if(!cond) { goto P_0c063600; }
goto P_0c0635fa;
P_0c0635f8: /* original e47c, guest PC 0x0c0635f8 */
if(!s->budget--) { s->failed_pc=0x0c0635f8u; return 0; }
r[4]=0x0000007cu;
goto P_0c0635fa;
P_0c0635fa: /* original d51c, guest PC 0x0c0635fa */
if(!s->budget--) { s->failed_pc=0x0c0635fau; return 0; }
r[5]=read(ram,0x0c06366cu,4);
goto P_0c0635fc;
P_0c0635fc: /* original a001, guest PC 0x0c0635fc */
if(!s->budget--) { s->failed_pc=0x0c0635fcu; return 0; }
goto P_0c063602;
P_0c0635fe: /* original 0009, guest PC 0x0c0635fe */
if(!s->budget--) { s->failed_pc=0x0c0635feu; return 0; }
goto P_0c063600;
P_0c063600: /* original d51b, guest PC 0x0c063600 */
if(!s->budget--) { s->failed_pc=0x0c063600u; return 0; }
r[5]=read(ram,0x0c063670u,4);
goto P_0c063602;
P_0c063602: /* original 4e0b, guest PC 0x0c063602 */
if(!s->budget--) { s->failed_pc=0x0c063602u; return 0; }
target=r[14];
r[16]=code_base|0x0c063606u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063606u) { target=s->pc; goto dispatch; }
goto P_0c063606;
P_0c063604: /* original 0009, guest PC 0x0c063604 */
if(!s->budget--) { s->failed_pc=0x0c063604u; return 0; }
goto P_0c063606;
P_0c063606: /* original e300, guest PC 0x0c063606 */
if(!s->budget--) { s->failed_pc=0x0c063606u; return 0; }
r[3]=0x00000000u;
goto P_0c063608;
P_0c063608: /* original de1a, guest PC 0x0c063608 */
if(!s->budget--) { s->failed_pc=0x0c063608u; return 0; }
r[14]=read(ram,0x0c063674u,4);
goto P_0c06360a;
P_0c06360a: /* original 6d33, guest PC 0x0c06360a */
if(!s->budget--) { s->failed_pc=0x0c06360au; return 0; }
r[13]=r[3];
goto P_0c06360c;
P_0c06360c: /* original db1a, guest PC 0x0c06360c */
if(!s->budget--) { s->failed_pc=0x0c06360cu; return 0; }
r[11]=read(ram,0x0c063678u,4);
goto P_0c06360e;
P_0c06360e: /* original 2f32, guest PC 0x0c06360e */
if(!s->budget--) { s->failed_pc=0x0c06360eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c063610;
P_0c063610: /* original dc1a, guest PC 0x0c063610 */
if(!s->budget--) { s->failed_pc=0x0c063610u; return 0; }
r[12]=read(ram,0x0c06367cu,4);
goto P_0c063612;
P_0c063612: /* original a03b, guest PC 0x0c063612 */
if(!s->budget--) { s->failed_pc=0x0c063612u; return 0; }
goto P_0c06368c;
P_0c063614: /* original 0009, guest PC 0x0c063614 */
if(!s->budget--) { s->failed_pc=0x0c063614u; return 0; }
return vf3_matrix_family(0x0c063616u,s,ram);
P_0c063680: /* original e604, guest PC 0x0c063680 */
if(!s->budget--) { s->failed_pc=0x0c063680u; return 0; }
r[6]=0x00000004u;
goto P_0c063682;
P_0c063682: /* original 65f3, guest PC 0x0c063682 */
if(!s->budget--) { s->failed_pc=0x0c063682u; return 0; }
r[5]=r[15];
goto P_0c063684;
P_0c063684: /* original 4b0b, guest PC 0x0c063684 */
if(!s->budget--) { s->failed_pc=0x0c063684u; return 0; }
target=r[11];
r[16]=code_base|0x0c063688u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063688u) { target=s->pc; goto dispatch; }
goto P_0c063688;
P_0c063686: /* original 64e3, guest PC 0x0c063686 */
if(!s->budget--) { s->failed_pc=0x0c063686u; return 0; }
r[4]=r[14];
goto P_0c063688;
P_0c063688: /* original 7d01, guest PC 0x0c063688 */
if(!s->budget--) { s->failed_pc=0x0c063688u; return 0; }
r[13]+=0x00000001u;
goto P_0c06368a;
P_0c06368a: /* original 7e04, guest PC 0x0c06368a */
if(!s->budget--) { s->failed_pc=0x0c06368au; return 0; }
r[14]+=0x00000004u;
goto P_0c06368c;
P_0c06368c: /* original 3dc3, guest PC 0x0c06368c */
if(!s->budget--) { s->failed_pc=0x0c06368cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[12])!=0);
goto P_0c06368e;
P_0c06368e: /* original 8bf7, guest PC 0x0c06368e */
if(!s->budget--) { s->failed_pc=0x0c06368eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063680; }
goto P_0c063690;
P_0c063690: /* original e001, guest PC 0x0c063690 */
if(!s->budget--) { s->failed_pc=0x0c063690u; return 0; }
r[0]=0x00000001u;
goto P_0c063692;
P_0c063692: /* original 7f08, guest PC 0x0c063692 */
if(!s->budget--) { s->failed_pc=0x0c063692u; return 0; }
r[15]+=0x00000008u;
goto P_0c063694;
P_0c063694: /* original 4f26, guest PC 0x0c063694 */
if(!s->budget--) { s->failed_pc=0x0c063694u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063696;
P_0c063696: /* original 6bf6, guest PC 0x0c063696 */
if(!s->budget--) { s->failed_pc=0x0c063696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c063698;
P_0c063698: /* original 6cf6, guest PC 0x0c063698 */
if(!s->budget--) { s->failed_pc=0x0c063698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06369a;
P_0c06369a: /* original 6df6, guest PC 0x0c06369a */
if(!s->budget--) { s->failed_pc=0x0c06369au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06369c;
P_0c06369c: /* original 000b, guest PC 0x0c06369c */
if(!s->budget--) { s->failed_pc=0x0c06369cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06369e: /* original 6ef6, guest PC 0x0c06369e */
if(!s->budget--) { s->failed_pc=0x0c06369eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0636a0u,s,ram);
P_0c06371c: /* original 4f22, guest PC 0x0c06371c */
if(!s->budget--) { s->failed_pc=0x0c06371cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06371e;
P_0c06371e: /* original d444, guest PC 0x0c06371e */
if(!s->budget--) { s->failed_pc=0x0c06371eu; return 0; }
r[4]=read(ram,0x0c063830u,4);
goto P_0c063720;
P_0c063720: /* original d344, guest PC 0x0c063720 */
if(!s->budget--) { s->failed_pc=0x0c063720u; return 0; }
r[3]=read(ram,0x0c063834u,4);
goto P_0c063722;
P_0c063722: /* original 430b, guest PC 0x0c063722 */
if(!s->budget--) { s->failed_pc=0x0c063722u; return 0; }
target=r[3];
r[16]=code_base|0x0c063726u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063726u) { target=s->pc; goto dispatch; }
goto P_0c063726;
P_0c063724: /* original 0009, guest PC 0x0c063724 */
if(!s->budget--) { s->failed_pc=0x0c063724u; return 0; }
goto P_0c063726;
P_0c063726: /* original e400, guest PC 0x0c063726 */
if(!s->budget--) { s->failed_pc=0x0c063726u; return 0; }
r[4]=0x00000000u;
goto P_0c063728;
P_0c063728: /* original d243, guest PC 0x0c063728 */
if(!s->budget--) { s->failed_pc=0x0c063728u; return 0; }
r[2]=read(ram,0x0c063838u,4);
goto P_0c06372a;
P_0c06372a: /* original 2242, guest PC 0x0c06372a */
if(!s->budget--) { s->failed_pc=0x0c06372au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c06372c;
P_0c06372c: /* original d343, guest PC 0x0c06372c */
if(!s->budget--) { s->failed_pc=0x0c06372cu; return 0; }
r[3]=read(ram,0x0c06383cu,4);
goto P_0c06372e;
P_0c06372e: /* original 2342, guest PC 0x0c06372e */
if(!s->budget--) { s->failed_pc=0x0c06372eu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c063730;
P_0c063730: /* original d143, guest PC 0x0c063730 */
if(!s->budget--) { s->failed_pc=0x0c063730u; return 0; }
r[1]=read(ram,0x0c063840u,4);
goto P_0c063732;
P_0c063732: /* original 2142, guest PC 0x0c063732 */
if(!s->budget--) { s->failed_pc=0x0c063732u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c063734;
P_0c063734: /* original d243, guest PC 0x0c063734 */
if(!s->budget--) { s->failed_pc=0x0c063734u; return 0; }
r[2]=read(ram,0x0c063844u,4);
goto P_0c063736;
P_0c063736: /* original 2242, guest PC 0x0c063736 */
if(!s->budget--) { s->failed_pc=0x0c063736u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c063738;
P_0c063738: /* original d543, guest PC 0x0c063738 */
if(!s->budget--) { s->failed_pc=0x0c063738u; return 0; }
r[5]=read(ram,0x0c063848u,4);
goto P_0c06373a;
P_0c06373a: /* original 6743, guest PC 0x0c06373a */
if(!s->budget--) { s->failed_pc=0x0c06373au; return 0; }
r[7]=r[4];
goto P_0c06373c;
P_0c06373c: /* original d343, guest PC 0x0c06373c */
if(!s->budget--) { s->failed_pc=0x0c06373cu; return 0; }
r[3]=read(ram,0x0c06384cu,4);
goto P_0c06373e;
P_0c06373e: /* original e005, guest PC 0x0c06373e */
if(!s->budget--) { s->failed_pc=0x0c06373eu; return 0; }
r[0]=0x00000005u;
goto P_0c063740;
P_0c063740: /* original 2542, guest PC 0x0c063740 */
if(!s->budget--) { s->failed_pc=0x0c063740u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c063742;
P_0c063742: /* original e600, guest PC 0x0c063742 */
if(!s->budget--) { s->failed_pc=0x0c063742u; return 0; }
r[6]=0x00000000u;
goto P_0c063744;
P_0c063744: /* original 1541, guest PC 0x0c063744 */
if(!s->budget--) { s->failed_pc=0x0c063744u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c063746;
P_0c063746: /* original 1542, guest PC 0x0c063746 */
if(!s->budget--) { s->failed_pc=0x0c063746u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c063748;
P_0c063748: /* original 1543, guest PC 0x0c063748 */
if(!s->budget--) { s->failed_pc=0x0c063748u; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06374a;
P_0c06374a: /* original 1544, guest PC 0x0c06374a */
if(!s->budget--) { s->failed_pc=0x0c06374au; return 0; }
write(ram,r[5]+16,r[4],4);
goto P_0c06374c;
P_0c06374c: /* original 1545, guest PC 0x0c06374c */
if(!s->budget--) { s->failed_pc=0x0c06374cu; return 0; }
write(ram,r[5]+20,r[4],4);
goto P_0c06374e;
P_0c06374e: /* original 1546, guest PC 0x0c06374e */
if(!s->budget--) { s->failed_pc=0x0c06374eu; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c063750;
P_0c063750: /* original 1547, guest PC 0x0c063750 */
if(!s->budget--) { s->failed_pc=0x0c063750u; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c063752;
P_0c063752: /* original 1548, guest PC 0x0c063752 */
if(!s->budget--) { s->failed_pc=0x0c063752u; return 0; }
write(ram,r[5]+32,r[4],4);
goto P_0c063754;
P_0c063754: /* original 2342, guest PC 0x0c063754 */
if(!s->budget--) { s->failed_pc=0x0c063754u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c063756;
P_0c063756: /* original 6253, guest PC 0x0c063756 */
if(!s->budget--) { s->failed_pc=0x0c063756u; return 0; }
r[2]=r[5];
goto P_0c063758;
P_0c063758: /* original 722c, guest PC 0x0c063758 */
if(!s->budget--) { s->failed_pc=0x0c063758u; return 0; }
r[2]+=0x0000002cu;
goto P_0c06375a;
P_0c06375a: /* original 326c, guest PC 0x0c06375a */
if(!s->budget--) { s->failed_pc=0x0c06375au; return 0; }
r[2]+=r[6];
goto P_0c06375c;
P_0c06375c: /* original 2242, guest PC 0x0c06375c */
if(!s->budget--) { s->failed_pc=0x0c06375cu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c06375e;
P_0c06375e: /* original 7701, guest PC 0x0c06375e */
if(!s->budget--) { s->failed_pc=0x0c06375eu; return 0; }
r[7]+=0x00000001u;
goto P_0c063760;
P_0c063760: /* original 3702, guest PC 0x0c063760 */
if(!s->budget--) { s->failed_pc=0x0c063760u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[0])!=0);
goto P_0c063762;
P_0c063762: /* original 8ff8, guest PC 0x0c063762 */
if(!s->budget--) { s->failed_pc=0x0c063762u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c063756; }
goto P_0c063766;
P_0c063764: /* original 7604, guest PC 0x0c063764 */
if(!s->budget--) { s->failed_pc=0x0c063764u; return 0; }
r[6]+=0x00000004u;
goto P_0c063766;
P_0c063766: /* original 4f26, guest PC 0x0c063766 */
if(!s->budget--) { s->failed_pc=0x0c063766u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063768;
P_0c063768: /* original 000b, guest PC 0x0c063768 */
if(!s->budget--) { s->failed_pc=0x0c063768u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06376a: /* original 0009, guest PC 0x0c06376a */
if(!s->budget--) { s->failed_pc=0x0c06376au; return 0; }
return vf3_matrix_family(0x0c06376cu,s,ram);
P_0c0734fe: /* original 4f22, guest PC 0x0c0734fe */
if(!s->budget--) { s->failed_pc=0x0c0734feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073500;
P_0c073500: /* original 66b8, guest PC 0x0c073500 */
if(!s->budget--) { s->failed_pc=0x0c073500u; return 0; }
r[6]=(r[11]&0xffff0000u)|((r[11]&255u)<<8)|((r[11]>>8)&255u);
goto P_0c073502;
P_0c073502: /* original 0c0c, guest PC 0x0c073502 */
if(!s->budget--) { s->failed_pc=0x0c073502u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c073504;
P_0c073504: /* original 11f4, guest PC 0x0c073504 */
if(!s->budget--) { s->failed_pc=0x0c073504u; return 0; }
write(ram,r[1]+16,r[15],4);
goto P_0c073506;
P_0c073506: /* original 0c0c, guest PC 0x0c073506 */
if(!s->budget--) { s->failed_pc=0x0c073506u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c073508;
P_0c073508: /* original 3252, guest PC 0x0c073508 */
if(!s->budget--) { s->failed_pc=0x0c073508u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[5])!=0);
goto P_0c07350a;
P_0c07350a: /* original 0c0f, guest PC 0x0c07350a */
if(!s->budget--) { s->failed_pc=0x0c07350au; return 0; }
wide=(uint64_t)r[19]|((uint64_t)r[20]<<32);
wide+=(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[0],4)*(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[12]+((r[12]==r[0])?4u:0u),4);
r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
r[12]+=4; r[0]+=4;
goto P_0c07350c;
P_0c07350c: /* original 3368, guest PC 0x0c07350c */
if(!s->budget--) { s->failed_pc=0x0c07350cu; return 0; }
r[3]-=r[6];
goto P_0c07350e;
P_0c07350e: /* original 0c0f, guest PC 0x0c07350e */
if(!s->budget--) { s->failed_pc=0x0c07350eu; return 0; }
wide=(uint64_t)r[19]|((uint64_t)r[20]<<32);
wide+=(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[0],4)*(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[12]+((r[12]==r[0])?4u:0u),4);
r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
r[12]+=4; r[0]+=4;
goto P_0c073510;
P_0c073510: /* original 33bc, guest PC 0x0c073510 */
if(!s->budget--) { s->failed_pc=0x0c073510u; return 0; }
r[3]+=r[11];
goto P_0c073512;
P_0c073512: /* original 0c0f, guest PC 0x0c073512 */
if(!s->budget--) { s->failed_pc=0x0c073512u; return 0; }
wide=(uint64_t)r[19]|((uint64_t)r[20]<<32);
wide+=(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[0],4)*(uint64_t)(int64_t)(uint32_t)(int32_t)read(ram,r[12]+((r[12]==r[0])?4u:0u),4);
r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
r[12]+=4; r[0]+=4;
goto P_0c073514;
P_0c073514: /* original 4f22, guest PC 0x0c073514 */
if(!s->budget--) { s->failed_pc=0x0c073514u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073516;
P_0c073516: /* original 7ffc, guest PC 0x0c073516 */
if(!s->budget--) { s->failed_pc=0x0c073516u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c073518;
P_0c073518: /* original 2f42, guest PC 0x0c073518 */
if(!s->budget--) { s->failed_pc=0x0c073518u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07351a;
P_0c07351a: /* original d33a, guest PC 0x0c07351a */
if(!s->budget--) { s->failed_pc=0x0c07351au; return 0; }
r[3]=read(ram,0x0c073604u,4);
goto P_0c07351c;
P_0c07351c: /* original d438, guest PC 0x0c07351c */
if(!s->budget--) { s->failed_pc=0x0c07351cu; return 0; }
r[4]=read(ram,0x0c073600u,4);
goto P_0c07351e;
P_0c07351e: /* original 430b, guest PC 0x0c07351e */
if(!s->budget--) { s->failed_pc=0x0c07351eu; return 0; }
target=r[3];
r[16]=code_base|0x0c073522u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073522u) { target=s->pc; goto dispatch; }
goto P_0c073522;
P_0c073520: /* original 0009, guest PC 0x0c073520 */
if(!s->budget--) { s->failed_pc=0x0c073520u; return 0; }
goto P_0c073522;
P_0c073522: /* original d339, guest PC 0x0c073522 */
if(!s->budget--) { s->failed_pc=0x0c073522u; return 0; }
r[3]=read(ram,0x0c073608u,4);
goto P_0c073524;
P_0c073524: /* original 64f2, guest PC 0x0c073524 */
if(!s->budget--) { s->failed_pc=0x0c073524u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c073526;
P_0c073526: /* original 430b, guest PC 0x0c073526 */
if(!s->budget--) { s->failed_pc=0x0c073526u; return 0; }
target=r[3];
r[16]=code_base|0x0c07352au;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07352au) { target=s->pc; goto dispatch; }
goto P_0c07352a;
P_0c073528: /* original 7417, guest PC 0x0c073528 */
if(!s->budget--) { s->failed_pc=0x0c073528u; return 0; }
r[4]+=0x00000017u;
goto P_0c07352a;
P_0c07352a: /* original 640c, guest PC 0x0c07352a */
if(!s->budget--) { s->failed_pc=0x0c07352au; return 0; }
r[4]=r[0]&255u;
goto P_0c07352c;
P_0c07352c: /* original 6043, guest PC 0x0c07352c */
if(!s->budget--) { s->failed_pc=0x0c07352cu; return 0; }
r[0]=r[4];
goto P_0c07352e;
P_0c07352e: /* original 8801, guest PC 0x0c07352e */
if(!s->budget--) { s->failed_pc=0x0c07352eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c073530;
P_0c073530: /* original 8903, guest PC 0x0c073530 */
if(!s->budget--) { s->failed_pc=0x0c073530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07353a; }
goto P_0c073532;
P_0c073532: /* original d234, guest PC 0x0c073532 */
if(!s->budget--) { s->failed_pc=0x0c073532u; return 0; }
r[2]=read(ram,0x0c073604u,4);
goto P_0c073534;
P_0c073534: /* original d435, guest PC 0x0c073534 */
if(!s->budget--) { s->failed_pc=0x0c073534u; return 0; }
r[4]=read(ram,0x0c07360cu,4);
goto P_0c073536;
P_0c073536: /* original 420b, guest PC 0x0c073536 */
if(!s->budget--) { s->failed_pc=0x0c073536u; return 0; }
target=r[2];
r[16]=code_base|0x0c07353au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07353au) { target=s->pc; goto dispatch; }
goto P_0c07353a;
P_0c073538: /* original 0009, guest PC 0x0c073538 */
if(!s->budget--) { s->failed_pc=0x0c073538u; return 0; }
goto P_0c07353a;
P_0c07353a: /* original 7f04, guest PC 0x0c07353a */
if(!s->budget--) { s->failed_pc=0x0c07353au; return 0; }
r[15]+=0x00000004u;
goto P_0c07353c;
P_0c07353c: /* original 4f26, guest PC 0x0c07353c */
if(!s->budget--) { s->failed_pc=0x0c07353cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07353e;
P_0c07353e: /* original 000b, guest PC 0x0c07353e */
if(!s->budget--) { s->failed_pc=0x0c07353eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c073540: /* original 0009, guest PC 0x0c073540 */
if(!s->budget--) { s->failed_pc=0x0c073540u; return 0; }
return vf3_matrix_family(0x0c073542u,s,ram);
P_0c09457e: /* original 4f22, guest PC 0x0c09457e */
if(!s->budget--) { s->failed_pc=0x0c09457eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094580;
P_0c094580: /* original fd08, guest PC 0x0c094580 */
if(!s->budget--) { s->failed_pc=0x0c094580u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c094582;
P_0c094582: /* original dc39, guest PC 0x0c094582 */
if(!s->budget--) { s->failed_pc=0x0c094582u; return 0; }
r[12]=read(ram,0x0c094668u,4);
goto P_0c094584;
P_0c094584: /* original dd39, guest PC 0x0c094584 */
if(!s->budget--) { s->failed_pc=0x0c094584u; return 0; }
r[13]=read(ram,0x0c09466cu,4);
goto P_0c094586;
P_0c094586: /* original fc8d, guest PC 0x0c094586 */
if(!s->budget--) { s->failed_pc=0x0c094586u; return 0; }
fr[12]=0;
goto P_0c094588;
P_0c094588: /* original c739, guest PC 0x0c094588 */
if(!s->budget--) { s->failed_pc=0x0c094588u; return 0; }
r[0]=0x0c094670u;
goto P_0c09458a;
P_0c09458a: /* original ff08, guest PC 0x0c09458a */
if(!s->budget--) { s->failed_pc=0x0c09458au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09458c;
P_0c09458c: /* original c739, guest PC 0x0c09458c */
if(!s->budget--) { s->failed_pc=0x0c09458cu; return 0; }
r[0]=0x0c094674u;
goto P_0c09458e;
P_0c09458e: /* original 4d0b, guest PC 0x0c09458e */
if(!s->budget--) { s->failed_pc=0x0c09458eu; return 0; }
target=r[13];
r[16]=code_base|0x0c094592u;
vf3_matrix_load(s,ram,14,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094592u) { target=s->pc; goto dispatch; }
goto P_0c094592;
P_0c094590: /* original fe08, guest PC 0x0c094590 */
if(!s->budget--) { s->failed_pc=0x0c094590u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c094592;
P_0c094592: /* original f0f2, guest PC 0x0c094592 */
if(!s->budget--) { s->failed_pc=0x0c094592u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c094594;
P_0c094594: /* original f0e1, guest PC 0x0c094594 */
if(!s->budget--) { s->failed_pc=0x0c094594u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c094596;
P_0c094596: /* original 4d0b, guest PC 0x0c094596 */
if(!s->budget--) { s->failed_pc=0x0c094596u; return 0; }
target=r[13];
r[16]=code_base|0x0c09459au;
vf3_matrix_store(s,ram,0,r[14]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09459au) { target=s->pc; goto dispatch; }
goto P_0c09459a;
P_0c094598: /* original fe0a, guest PC 0x0c094598 */
if(!s->budget--) { s->failed_pc=0x0c094598u; return 0; }
vf3_matrix_store(s,ram,0,r[14]);
goto P_0c09459a;
P_0c09459a: /* original f0f2, guest PC 0x0c09459a */
if(!s->budget--) { s->failed_pc=0x0c09459au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c09459c;
P_0c09459c: /* original e008, guest PC 0x0c09459c */
if(!s->budget--) { s->failed_pc=0x0c09459cu; return 0; }
r[0]=0x00000008u;
goto P_0c09459e;
P_0c09459e: /* original f0e1, guest PC 0x0c09459e */
if(!s->budget--) { s->failed_pc=0x0c09459eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c0945a0;
P_0c0945a0: /* original fe07, guest PC 0x0c0945a0 */
if(!s->budget--) { s->failed_pc=0x0c0945a0u; return 0; }
vf3_matrix_store(s,ram,0,r[14]+r[0]);
goto P_0c0945a2;
P_0c0945a2: /* original c735, guest PC 0x0c0945a2 */
if(!s->budget--) { s->failed_pc=0x0c0945a2u; return 0; }
r[0]=0x0c094678u;
goto P_0c0945a4;
P_0c0945a4: /* original fe08, guest PC 0x0c0945a4 */
if(!s->budget--) { s->failed_pc=0x0c0945a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0945a6;
P_0c0945a6: /* original 4d0b, guest PC 0x0c0945a6 */
if(!s->budget--) { s->failed_pc=0x0c0945a6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0945aau;
vf3_matrix_move(s,15,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0945aau) { target=s->pc; goto dispatch; }
goto P_0c0945aa;
P_0c0945a8: /* original ffdc, guest PC 0x0c0945a8 */
if(!s->budget--) { s->failed_pc=0x0c0945a8u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0945aa;
P_0c0945aa: /* original f30c, guest PC 0x0c0945aa */
if(!s->budget--) { s->failed_pc=0x0c0945aau; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0945ac;
P_0c0945ac: /* original e004, guest PC 0x0c0945ac */
if(!s->budget--) { s->failed_pc=0x0c0945acu; return 0; }
r[0]=0x00000004u;
goto P_0c0945ae;
P_0c0945ae: /* original f0ec, guest PC 0x0c0945ae */
if(!s->budget--) { s->failed_pc=0x0c0945aeu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0945b0;
P_0c0945b0: /* original ff3e, guest PC 0x0c0945b0 */
if(!s->budget--) { s->failed_pc=0x0c0945b0u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[3],fr[15],r[18]);
goto P_0c0945b2;
P_0c0945b2: /* original fef7, guest PC 0x0c0945b2 */
if(!s->budget--) { s->failed_pc=0x0c0945b2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0945b4;
P_0c0945b4: /* original e00c, guest PC 0x0c0945b4 */
if(!s->budget--) { s->failed_pc=0x0c0945b4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0945b6;
P_0c0945b6: /* original 4c0b, guest PC 0x0c0945b6 */
if(!s->budget--) { s->failed_pc=0x0c0945b6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945bau;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0945bau) { target=s->pc; goto dispatch; }
goto P_0c0945ba;
P_0c0945b8: /* original fec7, guest PC 0x0c0945b8 */
if(!s->budget--) { s->failed_pc=0x0c0945b8u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0945ba;
P_0c0945ba: /* original e116, guest PC 0x0c0945ba */
if(!s->budget--) { s->failed_pc=0x0c0945bau; return 0; }
r[1]=0x00000016u;
goto P_0c0945bc;
P_0c0945bc: /* original 31ec, guest PC 0x0c0945bc */
if(!s->budget--) { s->failed_pc=0x0c0945bcu; return 0; }
r[1]+=r[14];
goto P_0c0945be;
P_0c0945be: /* original c90f, guest PC 0x0c0945be */
if(!s->budget--) { s->failed_pc=0x0c0945beu; return 0; }
r[0]&=15u;
goto P_0c0945c0;
P_0c0945c0: /* original 4c0b, guest PC 0x0c0945c0 */
if(!s->budget--) { s->failed_pc=0x0c0945c0u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c4u;
write(ram,r[1],r[0],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0945c4u) { target=s->pc; goto dispatch; }
goto P_0c0945c4;
P_0c0945c2: /* original 2100, guest PC 0x0c0945c2 */
if(!s->budget--) { s->failed_pc=0x0c0945c2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0945c4;
P_0c0945c4: /* original 4c0b, guest PC 0x0c0945c4 */
if(!s->budget--) { s->failed_pc=0x0c0945c4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0945c8u;
write(ram,r[14]+16,r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0945c8u) { target=s->pc; goto dispatch; }
goto P_0c0945c8;
P_0c0945c6: /* original 81e8, guest PC 0x0c0945c6 */
if(!s->budget--) { s->failed_pc=0x0c0945c6u; return 0; }
write(ram,r[14]+16,r[0],2);
goto P_0c0945c8;
P_0c0945c8: /* original c9f0, guest PC 0x0c0945c8 */
if(!s->budget--) { s->failed_pc=0x0c0945c8u; return 0; }
r[0]&=240u;
goto P_0c0945ca;
P_0c0945ca: /* original 81ea, guest PC 0x0c0945ca */
if(!s->budget--) { s->failed_pc=0x0c0945cau; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c0945cc;
P_0c0945cc: /* original 60a3, guest PC 0x0c0945cc */
if(!s->budget--) { s->failed_pc=0x0c0945ccu; return 0; }
r[0]=r[10];
goto P_0c0945ce;
P_0c0945ce: /* original 81e9, guest PC 0x0c0945ce */
if(!s->budget--) { s->failed_pc=0x0c0945ceu; return 0; }
write(ram,r[14]+18,r[0],2);
goto P_0c0945d0;
P_0c0945d0: /* original e017, guest PC 0x0c0945d0 */
if(!s->budget--) { s->failed_pc=0x0c0945d0u; return 0; }
r[0]=0x00000017u;
goto P_0c0945d2;
P_0c0945d2: /* original 4b10, guest PC 0x0c0945d2 */
if(!s->budget--) { s->failed_pc=0x0c0945d2u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0945d4;
P_0c0945d4: /* original 0e94, guest PC 0x0c0945d4 */
if(!s->budget--) { s->failed_pc=0x0c0945d4u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c0945d6;
P_0c0945d6: /* original 8fd7, guest PC 0x0c0945d6 */
if(!s->budget--) { s->failed_pc=0x0c0945d6u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c094588; }
goto P_0c0945da;
P_0c0945d8: /* original 7e18, guest PC 0x0c0945d8 */
if(!s->budget--) { s->failed_pc=0x0c0945d8u; return 0; }
r[14]+=0x00000018u;
goto P_0c0945da;
P_0c0945da: /* original 4f26, guest PC 0x0c0945da */
if(!s->budget--) { s->failed_pc=0x0c0945dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0945dc;
P_0c0945dc: /* original fcf9, guest PC 0x0c0945dc */
if(!s->budget--) { s->failed_pc=0x0c0945dcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945de;
P_0c0945de: /* original fdf9, guest PC 0x0c0945de */
if(!s->budget--) { s->failed_pc=0x0c0945deu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e0;
P_0c0945e0: /* original fef9, guest PC 0x0c0945e0 */
if(!s->budget--) { s->failed_pc=0x0c0945e0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e2;
P_0c0945e2: /* original fff9, guest PC 0x0c0945e2 */
if(!s->budget--) { s->failed_pc=0x0c0945e2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0945e4;
P_0c0945e4: /* original 69f6, guest PC 0x0c0945e4 */
if(!s->budget--) { s->failed_pc=0x0c0945e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0945e6;
P_0c0945e6: /* original 6af6, guest PC 0x0c0945e6 */
if(!s->budget--) { s->failed_pc=0x0c0945e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0945e8;
P_0c0945e8: /* original 6bf6, guest PC 0x0c0945e8 */
if(!s->budget--) { s->failed_pc=0x0c0945e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0945ea;
P_0c0945ea: /* original 6cf6, guest PC 0x0c0945ea */
if(!s->budget--) { s->failed_pc=0x0c0945eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0945ec;
P_0c0945ec: /* original 6df6, guest PC 0x0c0945ec */
if(!s->budget--) { s->failed_pc=0x0c0945ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0945ee;
P_0c0945ee: /* original 000b, guest PC 0x0c0945ee */
if(!s->budget--) { s->failed_pc=0x0c0945eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0945f0: /* original 6ef6, guest PC 0x0c0945f0 */
if(!s->budget--) { s->failed_pc=0x0c0945f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0945f2u,s,ram);
P_0c097ff4: /* original d427, guest PC 0x0c097ff4 */
if(!s->budget--) { s->failed_pc=0x0c097ff4u; return 0; }
r[4]=read(ram,0x0c098094u,4);
goto P_0c097ff6;
P_0c097ff6: /* original d329, guest PC 0x0c097ff6 */
if(!s->budget--) { s->failed_pc=0x0c097ff6u; return 0; }
r[3]=read(ram,0x0c09809cu,4);
goto P_0c097ff8;
P_0c097ff8: /* original 5242, guest PC 0x0c097ff8 */
if(!s->budget--) { s->failed_pc=0x0c097ff8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097ffa;
P_0c097ffa: /* original d627, guest PC 0x0c097ffa */
if(!s->budget--) { s->failed_pc=0x0c097ffau; return 0; }
r[6]=read(ram,0x0c098098u,4);
goto P_0c097ffc;
P_0c097ffc: /* original 2238, guest PC 0x0c097ffc */
if(!s->budget--) { s->failed_pc=0x0c097ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097ffe;
P_0c097ffe: /* original 8b1d, guest PC 0x0c097ffe */
if(!s->budget--) { s->failed_pc=0x0c097ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09803c; }
goto P_0c098000;
P_0c098000: /* original 5142, guest PC 0x0c098000 */
if(!s->budget--) { s->failed_pc=0x0c098000u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c098002;
P_0c098002: /* original d327, guest PC 0x0c098002 */
if(!s->budget--) { s->failed_pc=0x0c098002u; return 0; }
r[3]=read(ram,0x0c0980a0u,4);
goto P_0c098004;
P_0c098004: /* original 2138, guest PC 0x0c098004 */
if(!s->budget--) { s->failed_pc=0x0c098004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098006;
P_0c098006: /* original 8919, guest PC 0x0c098006 */
if(!s->budget--) { s->failed_pc=0x0c098006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09803c; }
goto P_0c098008;
P_0c098008: /* original 5242, guest PC 0x0c098008 */
if(!s->budget--) { s->failed_pc=0x0c098008u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09800a;
P_0c09800a: /* original d326, guest PC 0x0c09800a */
if(!s->budget--) { s->failed_pc=0x0c09800au; return 0; }
r[3]=read(ram,0x0c0980a4u,4);
goto P_0c09800c;
P_0c09800c: /* original 2238, guest PC 0x0c09800c */
if(!s->budget--) { s->failed_pc=0x0c09800cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09800e;
P_0c09800e: /* original 8d0f, guest PC 0x0c09800e */
if(!s->budget--) { s->failed_pc=0x0c09800eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c098030; }
goto P_0c098012;
P_0c098010: /* original e700, guest PC 0x0c098010 */
if(!s->budget--) { s->failed_pc=0x0c098010u; return 0; }
r[7]=0x00000000u;
goto P_0c098012;
P_0c098012: /* original e029, guest PC 0x0c098012 */
if(!s->budget--) { s->failed_pc=0x0c098012u; return 0; }
r[0]=0x00000029u;
goto P_0c098014;
P_0c098014: /* original 004c, guest PC 0x0c098014 */
if(!s->budget--) { s->failed_pc=0x0c098014u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098016;
P_0c098016: /* original 600c, guest PC 0x0c098016 */
if(!s->budget--) { s->failed_pc=0x0c098016u; return 0; }
r[0]=r[0]&255u;
goto P_0c098018;
P_0c098018: /* original 8803, guest PC 0x0c098018 */
if(!s->budget--) { s->failed_pc=0x0c098018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09801a;
P_0c09801a: /* original 8909, guest PC 0x0c09801a */
if(!s->budget--) { s->failed_pc=0x0c09801au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098030; }
goto P_0c09801c;
P_0c09801c: /* original e02b, guest PC 0x0c09801c */
if(!s->budget--) { s->failed_pc=0x0c09801cu; return 0; }
r[0]=0x0000002bu;
goto P_0c09801e;
P_0c09801e: /* original 034c, guest PC 0x0c09801e */
if(!s->budget--) { s->failed_pc=0x0c09801eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098020;
P_0c098020: /* original 7301, guest PC 0x0c098020 */
if(!s->budget--) { s->failed_pc=0x0c098020u; return 0; }
r[3]+=0x00000001u;
goto P_0c098022;
P_0c098022: /* original 0434, guest PC 0x0c098022 */
if(!s->budget--) { s->failed_pc=0x0c098022u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098024;
P_0c098024: /* original 554d, guest PC 0x0c098024 */
if(!s->budget--) { s->failed_pc=0x0c098024u; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c098026;
P_0c098026: /* original 534e, guest PC 0x0c098026 */
if(!s->budget--) { s->failed_pc=0x0c098026u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c098028;
P_0c098028: /* original 353c, guest PC 0x0c098028 */
if(!s->budget--) { s->failed_pc=0x0c098028u; return 0; }
r[5]+=r[3];
goto P_0c09802a;
P_0c09802a: /* original 145c, guest PC 0x0c09802a */
if(!s->budget--) { s->failed_pc=0x0c09802au; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c09802c;
P_0c09802c: /* original 145d, guest PC 0x0c09802c */
if(!s->budget--) { s->failed_pc=0x0c09802cu; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c09802e;
P_0c09802e: /* original 147e, guest PC 0x0c09802e */
if(!s->budget--) { s->failed_pc=0x0c09802eu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c098030;
P_0c098030: /* original e010, guest PC 0x0c098030 */
if(!s->budget--) { s->failed_pc=0x0c098030u; return 0; }
r[0]=0x00000010u;
goto P_0c098032;
P_0c098032: /* original 0674, guest PC 0x0c098032 */
if(!s->budget--) { s->failed_pc=0x0c098032u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c098034;
P_0c098034: /* original e00a, guest PC 0x0c098034 */
if(!s->budget--) { s->failed_pc=0x0c098034u; return 0; }
r[0]=0x0000000au;
goto P_0c098036;
P_0c098036: /* original d31c, guest PC 0x0c098036 */
if(!s->budget--) { s->failed_pc=0x0c098036u; return 0; }
r[3]=read(ram,0x0c0980a8u,4);
goto P_0c098038;
P_0c098038: /* original 432b, guest PC 0x0c098038 */
if(!s->budget--) { s->failed_pc=0x0c098038u; return 0; }
target=r[3];
write(ram,r[6]+10,r[0],1);
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09803a: /* original 806a, guest PC 0x0c09803a */
if(!s->budget--) { s->failed_pc=0x0c09803au; return 0; }
write(ram,r[6]+10,r[0],1);
goto P_0c09803c;
P_0c09803c: /* original 000b, guest PC 0x0c09803c */
if(!s->budget--) { s->failed_pc=0x0c09803cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09803e: /* original 0009, guest PC 0x0c09803e */
if(!s->budget--) { s->failed_pc=0x0c09803eu; return 0; }
return vf3_matrix_family(0x0c098040u,s,ram);
P_0c0983c6: /* original 4f22, guest PC 0x0c0983c6 */
if(!s->budget--) { s->failed_pc=0x0c0983c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0983c8;
P_0c0983c8: /* original 53e3, guest PC 0x0c0983c8 */
if(!s->budget--) { s->failed_pc=0x0c0983c8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c0983ca;
P_0c0983ca: /* original dc1d, guest PC 0x0c0983ca */
if(!s->budget--) { s->failed_pc=0x0c0983cau; return 0; }
r[12]=read(ram,0x0c098440u,4);
goto P_0c0983cc;
P_0c0983cc: /* original 4315, guest PC 0x0c0983cc */
if(!s->budget--) { s->failed_pc=0x0c0983ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0983ce;
P_0c0983ce: /* original 892b, guest PC 0x0c0983ce */
if(!s->budget--) { s->failed_pc=0x0c0983ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098428; }
goto P_0c0983d0;
P_0c0983d0: /* original d21d, guest PC 0x0c0983d0 */
if(!s->budget--) { s->failed_pc=0x0c0983d0u; return 0; }
r[2]=read(ram,0x0c098448u,4);
goto P_0c0983d2;
P_0c0983d2: /* original 420b, guest PC 0x0c0983d2 */
if(!s->budget--) { s->failed_pc=0x0c0983d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983d6u) { target=s->pc; goto dispatch; }
goto P_0c0983d6;
P_0c0983d4: /* original 0009, guest PC 0x0c0983d4 */
if(!s->budget--) { s->failed_pc=0x0c0983d4u; return 0; }
goto P_0c0983d6;
P_0c0983d6: /* original d31d, guest PC 0x0c0983d6 */
if(!s->budget--) { s->failed_pc=0x0c0983d6u; return 0; }
r[3]=read(ram,0x0c09844cu,4);
goto P_0c0983d8;
P_0c0983d8: /* original e500, guest PC 0x0c0983d8 */
if(!s->budget--) { s->failed_pc=0x0c0983d8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983da;
P_0c0983da: /* original ff8d, guest PC 0x0c0983da */
if(!s->budget--) { s->failed_pc=0x0c0983dau; return 0; }
fr[15]=0;
goto P_0c0983dc;
P_0c0983dc: /* original f4fc, guest PC 0x0c0983dc */
if(!s->budget--) { s->failed_pc=0x0c0983dcu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983de;
P_0c0983de: /* original f5fc, guest PC 0x0c0983de */
if(!s->budget--) { s->failed_pc=0x0c0983deu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983e0;
P_0c0983e0: /* original f6fc, guest PC 0x0c0983e0 */
if(!s->budget--) { s->failed_pc=0x0c0983e0u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983e2;
P_0c0983e2: /* original 430b, guest PC 0x0c0983e2 */
if(!s->budget--) { s->failed_pc=0x0c0983e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983e6u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983e6u) { target=s->pc; goto dispatch; }
goto P_0c0983e6;
P_0c0983e4: /* original 6453, guest PC 0x0c0983e4 */
if(!s->budget--) { s->failed_pc=0x0c0983e4u; return 0; }
r[4]=r[5];
goto P_0c0983e6;
P_0c0983e6: /* original d219, guest PC 0x0c0983e6 */
if(!s->budget--) { s->failed_pc=0x0c0983e6u; return 0; }
r[2]=read(ram,0x0c09844cu,4);
goto P_0c0983e8;
P_0c0983e8: /* original e500, guest PC 0x0c0983e8 */
if(!s->budget--) { s->failed_pc=0x0c0983e8u; return 0; }
r[5]=0x00000000u;
goto P_0c0983ea;
P_0c0983ea: /* original f4fc, guest PC 0x0c0983ea */
if(!s->budget--) { s->failed_pc=0x0c0983eau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0983ec;
P_0c0983ec: /* original f5fc, guest PC 0x0c0983ec */
if(!s->budget--) { s->failed_pc=0x0c0983ecu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0983ee;
P_0c0983ee: /* original f6fc, guest PC 0x0c0983ee */
if(!s->budget--) { s->failed_pc=0x0c0983eeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0983f0;
P_0c0983f0: /* original 420b, guest PC 0x0c0983f0 */
if(!s->budget--) { s->failed_pc=0x0c0983f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0983f4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983f4u) { target=s->pc; goto dispatch; }
goto P_0c0983f4;
P_0c0983f2: /* original e401, guest PC 0x0c0983f2 */
if(!s->budget--) { s->failed_pc=0x0c0983f2u; return 0; }
r[4]=0x00000001u;
goto P_0c0983f4;
P_0c0983f4: /* original d316, guest PC 0x0c0983f4 */
if(!s->budget--) { s->failed_pc=0x0c0983f4u; return 0; }
r[3]=read(ram,0x0c098450u,4);
goto P_0c0983f6;
P_0c0983f6: /* original 430b, guest PC 0x0c0983f6 */
if(!s->budget--) { s->failed_pc=0x0c0983f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0983fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0983fau) { target=s->pc; goto dispatch; }
goto P_0c0983fa;
P_0c0983f8: /* original 0009, guest PC 0x0c0983f8 */
if(!s->budget--) { s->failed_pc=0x0c0983f8u; return 0; }
goto P_0c0983fa;
P_0c0983fa: /* original 2008, guest PC 0x0c0983fa */
if(!s->budget--) { s->failed_pc=0x0c0983fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0983fc;
P_0c0983fc: /* original 8b02, guest PC 0x0c0983fc */
if(!s->budget--) { s->failed_pc=0x0c0983fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098404; }
goto P_0c0983fe;
P_0c0983fe: /* original e301, guest PC 0x0c0983fe */
if(!s->budget--) { s->failed_pc=0x0c0983feu; return 0; }
r[3]=0x00000001u;
goto P_0c098400;
P_0c098400: /* original a012, guest PC 0x0c098400 */
if(!s->budget--) { s->failed_pc=0x0c098400u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098428;
P_0c098402: /* original 1e33, guest PC 0x0c098402 */
if(!s->budget--) { s->failed_pc=0x0c098402u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c098404;
P_0c098404: /* original d314, guest PC 0x0c098404 */
if(!s->budget--) { s->failed_pc=0x0c098404u; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c098406;
P_0c098406: /* original dd13, guest PC 0x0c098406 */
if(!s->budget--) { s->failed_pc=0x0c098406u; return 0; }
r[13]=read(ram,0x0c098454u,4);
goto P_0c098408;
P_0c098408: /* original 430b, guest PC 0x0c098408 */
if(!s->budget--) { s->failed_pc=0x0c098408u; return 0; }
target=r[3];
r[16]=code_base|0x0c09840cu;
r[4]=read(ram,r[13]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09840cu) { target=s->pc; goto dispatch; }
goto P_0c09840c;
P_0c09840a: /* original 54d8, guest PC 0x0c09840a */
if(!s->budget--) { s->failed_pc=0x0c09840au; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c09840c;
P_0c09840c: /* original d312, guest PC 0x0c09840c */
if(!s->budget--) { s->failed_pc=0x0c09840cu; return 0; }
r[3]=read(ram,0x0c098458u,4);
goto P_0c09840e;
P_0c09840e: /* original e044, guest PC 0x0c09840e */
if(!s->budget--) { s->failed_pc=0x0c09840eu; return 0; }
r[0]=0x00000044u;
goto P_0c098410;
P_0c098410: /* original 430b, guest PC 0x0c098410 */
if(!s->budget--) { s->failed_pc=0x0c098410u; return 0; }
target=r[3];
r[16]=code_base|0x0c098414u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c098414u) { target=s->pc; goto dispatch; }
goto P_0c098414;
P_0c098412: /* original 04de, guest PC 0x0c098412 */
if(!s->budget--) { s->failed_pc=0x0c098412u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c098414;
P_0c098414: /* original e029, guest PC 0x0c098414 */
if(!s->budget--) { s->failed_pc=0x0c098414u; return 0; }
r[0]=0x00000029u;
goto P_0c098416;
P_0c098416: /* original 02cc, guest PC 0x0c098416 */
if(!s->budget--) { s->failed_pc=0x0c098416u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c098418;
P_0c098418: /* original e300, guest PC 0x0c098418 */
if(!s->budget--) { s->failed_pc=0x0c098418u; return 0; }
r[3]=0x00000000u;
goto P_0c09841a;
P_0c09841a: /* original 900d, guest PC 0x0c09841a */
if(!s->budget--) { s->failed_pc=0x0c09841au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098438u,2);
goto P_0c09841c;
P_0c09841c: /* original 0e24, guest PC 0x0c09841c */
if(!s->budget--) { s->failed_pc=0x0c09841cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09841e;
P_0c09841e: /* original 900c, guest PC 0x0c09841e */
if(!s->budget--) { s->failed_pc=0x0c09841eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09843au,2);
goto P_0c098420;
P_0c098420: /* original 0c34, guest PC 0x0c098420 */
if(!s->budget--) { s->failed_pc=0x0c098420u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c098422;
P_0c098422: /* original 84eb, guest PC 0x0c098422 */
if(!s->budget--) { s->failed_pc=0x0c098422u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c098424;
P_0c098424: /* original 7001, guest PC 0x0c098424 */
if(!s->budget--) { s->failed_pc=0x0c098424u; return 0; }
r[0]+=0x00000001u;
goto P_0c098426;
P_0c098426: /* original 80eb, guest PC 0x0c098426 */
if(!s->budget--) { s->failed_pc=0x0c098426u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c098428;
P_0c098428: /* original 4f26, guest PC 0x0c098428 */
if(!s->budget--) { s->failed_pc=0x0c098428u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09842a;
P_0c09842a: /* original fff9, guest PC 0x0c09842a */
if(!s->budget--) { s->failed_pc=0x0c09842au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09842c;
P_0c09842c: /* original 6cf6, guest PC 0x0c09842c */
if(!s->budget--) { s->failed_pc=0x0c09842cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09842e;
P_0c09842e: /* original 6df6, guest PC 0x0c09842e */
if(!s->budget--) { s->failed_pc=0x0c09842eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098430;
P_0c098430: /* original ade0, guest PC 0x0c098430 */
if(!s->budget--) { s->failed_pc=0x0c098430u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c098432: /* original 6ef6, guest PC 0x0c098432 */
if(!s->budget--) { s->failed_pc=0x0c098432u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c098434u,s,ram);
P_0c09aa14: /* original 4f22, guest PC 0x0c09aa14 */
if(!s->budget--) { s->failed_pc=0x0c09aa14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09aa16;
P_0c09aa16: /* original d35d, guest PC 0x0c09aa16 */
if(!s->budget--) { s->failed_pc=0x0c09aa16u; return 0; }
r[3]=read(ram,0x0c09ab8cu,4);
goto P_0c09aa18;
P_0c09aa18: /* original dc5b, guest PC 0x0c09aa18 */
if(!s->budget--) { s->failed_pc=0x0c09aa18u; return 0; }
r[12]=read(ram,0x0c09ab88u,4);
goto P_0c09aa1a;
P_0c09aa1a: /* original 7ffc, guest PC 0x0c09aa1a */
if(!s->budget--) { s->failed_pc=0x0c09aa1au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09aa1c;
P_0c09aa1c: /* original 6433, guest PC 0x0c09aa1c */
if(!s->budget--) { s->failed_pc=0x0c09aa1cu; return 0; }
r[4]=r[3];
goto P_0c09aa1e;
P_0c09aa1e: /* original d958, guest PC 0x0c09aa1e */
if(!s->budget--) { s->failed_pc=0x0c09aa1eu; return 0; }
r[9]=read(ram,0x0c09ab80u,4);
goto P_0c09aa20;
P_0c09aa20: /* original da58, guest PC 0x0c09aa20 */
if(!s->budget--) { s->failed_pc=0x0c09aa20u; return 0; }
r[10]=read(ram,0x0c09ab84u,4);
goto P_0c09aa22;
P_0c09aa22: /* original 2f32, guest PC 0x0c09aa22 */
if(!s->budget--) { s->failed_pc=0x0c09aa22u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09aa24;
P_0c09aa24: /* original d35a, guest PC 0x0c09aa24 */
if(!s->budget--) { s->failed_pc=0x0c09aa24u; return 0; }
r[3]=read(ram,0x0c09ab90u,4);
goto P_0c09aa26;
P_0c09aa26: /* original 430b, guest PC 0x0c09aa26 */
if(!s->budget--) { s->failed_pc=0x0c09aa26u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa2au;
r[4]+=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa2au) { target=s->pc; goto dispatch; }
goto P_0c09aa2a;
P_0c09aa28: /* original 7430, guest PC 0x0c09aa28 */
if(!s->budget--) { s->failed_pc=0x0c09aa28u; return 0; }
r[4]+=0x00000030u;
goto P_0c09aa2a;
P_0c09aa2a: /* original d25b, guest PC 0x0c09aa2a */
if(!s->budget--) { s->failed_pc=0x0c09aa2au; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa2c;
P_0c09aa2c: /* original de59, guest PC 0x0c09aa2c */
if(!s->budget--) { s->failed_pc=0x0c09aa2cu; return 0; }
r[14]=read(ram,0x0c09ab94u,4);
goto P_0c09aa2e;
P_0c09aa2e: /* original 420b, guest PC 0x0c09aa2e */
if(!s->budget--) { s->failed_pc=0x0c09aa2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa32u;
r[4]=read(ram,r[14]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa32u) { target=s->pc; goto dispatch; }
goto P_0c09aa32;
P_0c09aa30: /* original 54e6, guest PC 0x0c09aa30 */
if(!s->budget--) { s->failed_pc=0x0c09aa30u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09aa32;
P_0c09aa32: /* original d359, guest PC 0x0c09aa32 */
if(!s->budget--) { s->failed_pc=0x0c09aa32u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa34;
P_0c09aa34: /* original 430b, guest PC 0x0c09aa34 */
if(!s->budget--) { s->failed_pc=0x0c09aa34u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa38u;
r[4]=read(ram,r[14]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa38u) { target=s->pc; goto dispatch; }
goto P_0c09aa38;
P_0c09aa36: /* original 54e7, guest PC 0x0c09aa36 */
if(!s->budget--) { s->failed_pc=0x0c09aa36u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09aa38;
P_0c09aa38: /* original d257, guest PC 0x0c09aa38 */
if(!s->budget--) { s->failed_pc=0x0c09aa38u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa3a;
P_0c09aa3a: /* original 420b, guest PC 0x0c09aa3a */
if(!s->budget--) { s->failed_pc=0x0c09aa3au; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa3eu;
r[4]=read(ram,r[14]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa3eu) { target=s->pc; goto dispatch; }
goto P_0c09aa3e;
P_0c09aa3c: /* original 54ef, guest PC 0x0c09aa3c */
if(!s->budget--) { s->failed_pc=0x0c09aa3cu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09aa3e;
P_0c09aa3e: /* original d356, guest PC 0x0c09aa3e */
if(!s->budget--) { s->failed_pc=0x0c09aa3eu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa40;
P_0c09aa40: /* original e040, guest PC 0x0c09aa40 */
if(!s->budget--) { s->failed_pc=0x0c09aa40u; return 0; }
r[0]=0x00000040u;
goto P_0c09aa42;
P_0c09aa42: /* original 430b, guest PC 0x0c09aa42 */
if(!s->budget--) { s->failed_pc=0x0c09aa42u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa46u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa46u) { target=s->pc; goto dispatch; }
goto P_0c09aa46;
P_0c09aa44: /* original 04ee, guest PC 0x0c09aa44 */
if(!s->budget--) { s->failed_pc=0x0c09aa44u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa46;
P_0c09aa46: /* original d254, guest PC 0x0c09aa46 */
if(!s->budget--) { s->failed_pc=0x0c09aa46u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa48;
P_0c09aa48: /* original 420b, guest PC 0x0c09aa48 */
if(!s->budget--) { s->failed_pc=0x0c09aa48u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa4cu;
r[4]=read(ram,r[14]+52,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa4cu) { target=s->pc; goto dispatch; }
goto P_0c09aa4c;
P_0c09aa4a: /* original 54ed, guest PC 0x0c09aa4a */
if(!s->budget--) { s->failed_pc=0x0c09aa4au; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c09aa4c;
P_0c09aa4c: /* original d352, guest PC 0x0c09aa4c */
if(!s->budget--) { s->failed_pc=0x0c09aa4cu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa4e;
P_0c09aa4e: /* original 430b, guest PC 0x0c09aa4e */
if(!s->budget--) { s->failed_pc=0x0c09aa4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa52u;
r[4]=read(ram,r[14]+56,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa52u) { target=s->pc; goto dispatch; }
goto P_0c09aa52;
P_0c09aa50: /* original 54ee, guest PC 0x0c09aa50 */
if(!s->budget--) { s->failed_pc=0x0c09aa50u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c09aa52;
P_0c09aa52: /* original d251, guest PC 0x0c09aa52 */
if(!s->budget--) { s->failed_pc=0x0c09aa52u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa54;
P_0c09aa54: /* original 420b, guest PC 0x0c09aa54 */
if(!s->budget--) { s->failed_pc=0x0c09aa54u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa58u;
r[4]=read(ram,r[14]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa58u) { target=s->pc; goto dispatch; }
goto P_0c09aa58;
P_0c09aa56: /* original 54ea, guest PC 0x0c09aa56 */
if(!s->budget--) { s->failed_pc=0x0c09aa56u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c09aa58;
P_0c09aa58: /* original d34f, guest PC 0x0c09aa58 */
if(!s->budget--) { s->failed_pc=0x0c09aa58u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa5a;
P_0c09aa5a: /* original 430b, guest PC 0x0c09aa5a */
if(!s->budget--) { s->failed_pc=0x0c09aa5au; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa5eu;
r[4]=read(ram,r[14]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa5eu) { target=s->pc; goto dispatch; }
goto P_0c09aa5e;
P_0c09aa5c: /* original 54eb, guest PC 0x0c09aa5c */
if(!s->budget--) { s->failed_pc=0x0c09aa5cu; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c09aa5e;
P_0c09aa5e: /* original d34e, guest PC 0x0c09aa5e */
if(!s->budget--) { s->failed_pc=0x0c09aa5eu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa60;
P_0c09aa60: /* original e050, guest PC 0x0c09aa60 */
if(!s->budget--) { s->failed_pc=0x0c09aa60u; return 0; }
r[0]=0x00000050u;
goto P_0c09aa62;
P_0c09aa62: /* original 430b, guest PC 0x0c09aa62 */
if(!s->budget--) { s->failed_pc=0x0c09aa62u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa66u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa66u) { target=s->pc; goto dispatch; }
goto P_0c09aa66;
P_0c09aa64: /* original 04ee, guest PC 0x0c09aa64 */
if(!s->budget--) { s->failed_pc=0x0c09aa64u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa66;
P_0c09aa66: /* original d34c, guest PC 0x0c09aa66 */
if(!s->budget--) { s->failed_pc=0x0c09aa66u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa68;
P_0c09aa68: /* original e054, guest PC 0x0c09aa68 */
if(!s->budget--) { s->failed_pc=0x0c09aa68u; return 0; }
r[0]=0x00000054u;
goto P_0c09aa6a;
P_0c09aa6a: /* original 430b, guest PC 0x0c09aa6a */
if(!s->budget--) { s->failed_pc=0x0c09aa6au; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa6eu;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa6eu) { target=s->pc; goto dispatch; }
goto P_0c09aa6e;
P_0c09aa6c: /* original 04ee, guest PC 0x0c09aa6c */
if(!s->budget--) { s->failed_pc=0x0c09aa6cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa6e;
P_0c09aa6e: /* original c74b, guest PC 0x0c09aa6e */
if(!s->budget--) { s->failed_pc=0x0c09aa6eu; return 0; }
r[0]=0x0c09ab9cu;
goto P_0c09aa70;
P_0c09aa70: /* original f308, guest PC 0x0c09aa70 */
if(!s->budget--) { s->failed_pc=0x0c09aa70u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09aa72;
P_0c09aa72: /* original e102, guest PC 0x0c09aa72 */
if(!s->budget--) { s->failed_pc=0x0c09aa72u; return 0; }
r[1]=0x00000002u;
goto P_0c09aa74;
P_0c09aa74: /* original f93a, guest PC 0x0c09aa74 */
if(!s->budget--) { s->failed_pc=0x0c09aa74u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c09aa76;
P_0c09aa76: /* original 9375, guest PC 0x0c09aa76 */
if(!s->budget--) { s->failed_pc=0x0c09aa76u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab64u,2);
goto P_0c09aa78;
P_0c09aa78: /* original 5292, guest PC 0x0c09aa78 */
if(!s->budget--) { s->failed_pc=0x0c09aa78u; return 0; }
r[2]=read(ram,r[9]+8,4);
goto P_0c09aa7a;
P_0c09aa7a: /* original 2239, guest PC 0x0c09aa7a */
if(!s->budget--) { s->failed_pc=0x0c09aa7au; return 0; }
r[2]&=r[3];
goto P_0c09aa7c;
P_0c09aa7c: /* original 1922, guest PC 0x0c09aa7c */
if(!s->budget--) { s->failed_pc=0x0c09aa7cu; return 0; }
write(ram,r[9]+8,r[2],4);
goto P_0c09aa7e;
P_0c09aa7e: /* original 5de8, guest PC 0x0c09aa7e */
if(!s->budget--) { s->failed_pc=0x0c09aa7eu; return 0; }
r[13]=read(ram,r[14]+32,4);
goto P_0c09aa80;
P_0c09aa80: /* original 9071, guest PC 0x0c09aa80 */
if(!s->budget--) { s->failed_pc=0x0c09aa80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab66u,2);
goto P_0c09aa82;
P_0c09aa82: /* original 0d14, guest PC 0x0c09aa82 */
if(!s->budget--) { s->failed_pc=0x0c09aa82u; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c09aa84;
P_0c09aa84: /* original 7017, guest PC 0x0c09aa84 */
if(!s->budget--) { s->failed_pc=0x0c09aa84u; return 0; }
r[0]+=0x00000017u;
goto P_0c09aa86;
P_0c09aa86: /* original d246, guest PC 0x0c09aa86 */
if(!s->budget--) { s->failed_pc=0x0c09aa86u; return 0; }
r[2]=read(ram,0x0c09aba0u,4);
goto P_0c09aa88;
P_0c09aa88: /* original 420b, guest PC 0x0c09aa88 */
if(!s->budget--) { s->failed_pc=0x0c09aa88u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa8cu;
write(ram,r[13]+r[0],r[11],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aa8cu) { target=s->pc; goto dispatch; }
goto P_0c09aa8c;
P_0c09aa8a: /* original 0db4, guest PC 0x0c09aa8a */
if(!s->budget--) { s->failed_pc=0x0c09aa8au; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c09aa8c;
P_0c09aa8c: /* original 906c, guest PC 0x0c09aa8c */
if(!s->budget--) { s->failed_pc=0x0c09aa8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab68u,2);
goto P_0c09aa8e;
P_0c09aa8e: /* original 63b3, guest PC 0x0c09aa8e */
if(!s->budget--) { s->failed_pc=0x0c09aa8eu; return 0; }
r[3]=r[11];
goto P_0c09aa90;
P_0c09aa90: /* original 0cb6, guest PC 0x0c09aa90 */
if(!s->budget--) { s->failed_pc=0x0c09aa90u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c09aa92;
P_0c09aa92: /* original 70fc, guest PC 0x0c09aa92 */
if(!s->budget--) { s->failed_pc=0x0c09aa92u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09aa94;
P_0c09aa94: /* original 0c36, guest PC 0x0c09aa94 */
if(!s->budget--) { s->failed_pc=0x0c09aa94u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c09aa96;
P_0c09aa96: /* original 9068, guest PC 0x0c09aa96 */
if(!s->budget--) { s->failed_pc=0x0c09aa96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6au,2);
goto P_0c09aa98;
P_0c09aa98: /* original 0a34, guest PC 0x0c09aa98 */
if(!s->budget--) { s->failed_pc=0x0c09aa98u; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c09aa9a;
P_0c09aa9a: /* original d342, guest PC 0x0c09aa9a */
if(!s->budget--) { s->failed_pc=0x0c09aa9au; return 0; }
r[3]=read(ram,0x0c09aba4u,4);
goto P_0c09aa9c;
P_0c09aa9c: /* original 430b, guest PC 0x0c09aa9c */
if(!s->budget--) { s->failed_pc=0x0c09aa9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09aaa0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aaa0u) { target=s->pc; goto dispatch; }
goto P_0c09aaa0;
P_0c09aa9e: /* original 64c3, guest PC 0x0c09aa9e */
if(!s->budget--) { s->failed_pc=0x0c09aa9eu; return 0; }
r[4]=r[12];
goto P_0c09aaa0;
P_0c09aaa0: /* original d240, guest PC 0x0c09aaa0 */
if(!s->budget--) { s->failed_pc=0x0c09aaa0u; return 0; }
r[2]=read(ram,0x0c09aba4u,4);
goto P_0c09aaa2;
P_0c09aaa2: /* original 64c3, guest PC 0x0c09aaa2 */
if(!s->budget--) { s->failed_pc=0x0c09aaa2u; return 0; }
r[4]=r[12];
goto P_0c09aaa4;
P_0c09aaa4: /* original 420b, guest PC 0x0c09aaa4 */
if(!s->budget--) { s->failed_pc=0x0c09aaa4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aaa8u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aaa8u) { target=s->pc; goto dispatch; }
goto P_0c09aaa8;
P_0c09aaa6: /* original 742c, guest PC 0x0c09aaa6 */
if(!s->budget--) { s->failed_pc=0x0c09aaa6u; return 0; }
r[4]+=0x0000002cu;
goto P_0c09aaa8;
P_0c09aaa8: /* original 9060, guest PC 0x0c09aaa8 */
if(!s->budget--) { s->failed_pc=0x0c09aaa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6cu,2);
goto P_0c09aaaa;
P_0c09aaaa: /* original e40f, guest PC 0x0c09aaaa */
if(!s->budget--) { s->failed_pc=0x0c09aaaau; return 0; }
r[4]=0x0000000fu;
goto P_0c09aaac;
P_0c09aaac: /* original f38d, guest PC 0x0c09aaac */
if(!s->budget--) { s->failed_pc=0x0c09aaacu; return 0; }
fr[3]=0;
goto P_0c09aaae;
P_0c09aaae: /* original fd37, guest PC 0x0c09aaae */
if(!s->budget--) { s->failed_pc=0x0c09aaaeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aab0;
P_0c09aab0: /* original 709f, guest PC 0x0c09aab0 */
if(!s->budget--) { s->failed_pc=0x0c09aab0u; return 0; }
r[0]+=0xffffff9fu;
goto P_0c09aab2;
P_0c09aab2: /* original 0db4, guest PC 0x0c09aab2 */
if(!s->budget--) { s->failed_pc=0x0c09aab2u; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c09aab4;
P_0c09aab4: /* original 60d2, guest PC 0x0c09aab4 */
if(!s->budget--) { s->failed_pc=0x0c09aab4u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c09aab6;
P_0c09aab6: /* original c901, guest PC 0x0c09aab6 */
if(!s->budget--) { s->failed_pc=0x0c09aab6u; return 0; }
r[0]&=1u;
goto P_0c09aab8;
P_0c09aab8: /* original 2d02, guest PC 0x0c09aab8 */
if(!s->budget--) { s->failed_pc=0x0c09aab8u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c09aaba;
P_0c09aaba: /* original e01c, guest PC 0x0c09aaba */
if(!s->budget--) { s->failed_pc=0x0c09aabau; return 0; }
r[0]=0x0000001cu;
goto P_0c09aabc;
P_0c09aabc: /* original 00ac, guest PC 0x0c09aabc */
if(!s->budget--) { s->failed_pc=0x0c09aabcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c09aabe;
P_0c09aabe: /* original d33a, guest PC 0x0c09aabe */
if(!s->budget--) { s->failed_pc=0x0c09aabeu; return 0; }
r[3]=read(ram,0x0c09aba8u,4);
goto P_0c09aac0;
P_0c09aac0: /* original 600c, guest PC 0x0c09aac0 */
if(!s->budget--) { s->failed_pc=0x0c09aac0u; return 0; }
r[0]=r[0]&255u;
goto P_0c09aac2;
P_0c09aac2: /* original 9154, guest PC 0x0c09aac2 */
if(!s->budget--) { s->failed_pc=0x0c09aac2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6eu,2);
goto P_0c09aac4;
P_0c09aac4: /* original 2409, guest PC 0x0c09aac4 */
if(!s->budget--) { s->failed_pc=0x0c09aac4u; return 0; }
r[4]&=r[0];
goto P_0c09aac6;
P_0c09aac6: /* original 4408, guest PC 0x0c09aac6 */
if(!s->budget--) { s->failed_pc=0x0c09aac6u; return 0; }
r[4]<<=2;
goto P_0c09aac8;
P_0c09aac8: /* original 4408, guest PC 0x0c09aac8 */
if(!s->budget--) { s->failed_pc=0x0c09aac8u; return 0; }
r[4]<<=2;
goto P_0c09aaca;
P_0c09aaca: /* original 4408, guest PC 0x0c09aaca */
if(!s->budget--) { s->failed_pc=0x0c09aacau; return 0; }
r[4]<<=2;
goto P_0c09aacc;
P_0c09aacc: /* original 343c, guest PC 0x0c09aacc */
if(!s->budget--) { s->failed_pc=0x0c09aaccu; return 0; }
r[4]+=r[3];
goto P_0c09aace;
P_0c09aace: /* original 8445, guest PC 0x0c09aace */
if(!s->budget--) { s->failed_pc=0x0c09aaceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c09aad0;
P_0c09aad0: /* original 31dc, guest PC 0x0c09aad0 */
if(!s->budget--) { s->failed_pc=0x0c09aad0u; return 0; }
r[1]+=r[13];
goto P_0c09aad2;
P_0c09aad2: /* original 2100, guest PC 0x0c09aad2 */
if(!s->budget--) { s->failed_pc=0x0c09aad2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09aad4;
P_0c09aad4: /* original 924c, guest PC 0x0c09aad4 */
if(!s->budget--) { s->failed_pc=0x0c09aad4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab70u,2);
goto P_0c09aad6;
P_0c09aad6: /* original 8446, guest PC 0x0c09aad6 */
if(!s->budget--) { s->failed_pc=0x0c09aad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c09aad8;
P_0c09aad8: /* original 32dc, guest PC 0x0c09aad8 */
if(!s->budget--) { s->failed_pc=0x0c09aad8u; return 0; }
r[2]+=r[13];
goto P_0c09aada;
P_0c09aada: /* original 2200, guest PC 0x0c09aada */
if(!s->budget--) { s->failed_pc=0x0c09aadau; return 0; }
write(ram,r[2],r[0],1);
goto P_0c09aadc;
P_0c09aadc: /* original 9149, guest PC 0x0c09aadc */
if(!s->budget--) { s->failed_pc=0x0c09aadcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab72u,2);
goto P_0c09aade;
P_0c09aade: /* original 8447, guest PC 0x0c09aade */
if(!s->budget--) { s->failed_pc=0x0c09aadeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c09aae0;
P_0c09aae0: /* original 31dc, guest PC 0x0c09aae0 */
if(!s->budget--) { s->failed_pc=0x0c09aae0u; return 0; }
r[1]+=r[13];
goto P_0c09aae2;
P_0c09aae2: /* original 2100, guest PC 0x0c09aae2 */
if(!s->budget--) { s->failed_pc=0x0c09aae2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09aae4;
P_0c09aae4: /* original e01c, guest PC 0x0c09aae4 */
if(!s->budget--) { s->failed_pc=0x0c09aae4u; return 0; }
r[0]=0x0000001cu;
goto P_0c09aae6;
P_0c09aae6: /* original f346, guest PC 0x0c09aae6 */
if(!s->budget--) { s->failed_pc=0x0c09aae6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aae8;
P_0c09aae8: /* original 9044, guest PC 0x0c09aae8 */
if(!s->budget--) { s->failed_pc=0x0c09aae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab74u,2);
goto P_0c09aaea;
P_0c09aaea: /* original fd37, guest PC 0x0c09aaea */
if(!s->budget--) { s->failed_pc=0x0c09aaeau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aaec;
P_0c09aaec: /* original e020, guest PC 0x0c09aaec */
if(!s->budget--) { s->failed_pc=0x0c09aaecu; return 0; }
r[0]=0x00000020u;
goto P_0c09aaee;
P_0c09aaee: /* original f346, guest PC 0x0c09aaee */
if(!s->budget--) { s->failed_pc=0x0c09aaeeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aaf0;
P_0c09aaf0: /* original 9041, guest PC 0x0c09aaf0 */
if(!s->budget--) { s->failed_pc=0x0c09aaf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab76u,2);
goto P_0c09aaf2;
P_0c09aaf2: /* original fd37, guest PC 0x0c09aaf2 */
if(!s->budget--) { s->failed_pc=0x0c09aaf2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aaf4;
P_0c09aaf4: /* original e024, guest PC 0x0c09aaf4 */
if(!s->budget--) { s->failed_pc=0x0c09aaf4u; return 0; }
r[0]=0x00000024u;
goto P_0c09aaf6;
P_0c09aaf6: /* original f346, guest PC 0x0c09aaf6 */
if(!s->budget--) { s->failed_pc=0x0c09aaf6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aaf8;
P_0c09aaf8: /* original 903e, guest PC 0x0c09aaf8 */
if(!s->budget--) { s->failed_pc=0x0c09aaf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab78u,2);
goto P_0c09aafa;
P_0c09aafa: /* original fd37, guest PC 0x0c09aafa */
if(!s->budget--) { s->failed_pc=0x0c09aafau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aafc;
P_0c09aafc: /* original 963d, guest PC 0x0c09aafc */
if(!s->budget--) { s->failed_pc=0x0c09aafcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab7au,2);
goto P_0c09aafe;
P_0c09aafe: /* original 943d, guest PC 0x0c09aafe */
if(!s->budget--) { s->failed_pc=0x0c09aafeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab7cu,2);
goto P_0c09ab00;
P_0c09ab00: /* original d22a, guest PC 0x0c09ab00 */
if(!s->budget--) { s->failed_pc=0x0c09ab00u; return 0; }
r[2]=read(ram,0x0c09abacu,4);
goto P_0c09ab02;
P_0c09ab02: /* original 36cc, guest PC 0x0c09ab02 */
if(!s->budget--) { s->failed_pc=0x0c09ab02u; return 0; }
r[6]+=r[12];
goto P_0c09ab04;
P_0c09ab04: /* original 420b, guest PC 0x0c09ab04 */
if(!s->budget--) { s->failed_pc=0x0c09ab04u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ab08u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ab08u) { target=s->pc; goto dispatch; }
goto P_0c09ab08;
P_0c09ab06: /* original 65c3, guest PC 0x0c09ab06 */
if(!s->budget--) { s->failed_pc=0x0c09ab06u; return 0; }
r[5]=r[12];
goto P_0c09ab08;
P_0c09ab08: /* original d329, guest PC 0x0c09ab08 */
if(!s->budget--) { s->failed_pc=0x0c09ab08u; return 0; }
r[3]=read(ram,0x0c09abb0u,4);
goto P_0c09ab0a;
P_0c09ab0a: /* original 430b, guest PC 0x0c09ab0a */
if(!s->budget--) { s->failed_pc=0x0c09ab0au; return 0; }
target=r[3];
r[16]=code_base|0x0c09ab0eu;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ab0eu) { target=s->pc; goto dispatch; }
goto P_0c09ab0e;
P_0c09ab0c: /* original 54e4, guest PC 0x0c09ab0c */
if(!s->budget--) { s->failed_pc=0x0c09ab0cu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09ab0e;
P_0c09ab0e: /* original d228, guest PC 0x0c09ab0e */
if(!s->budget--) { s->failed_pc=0x0c09ab0eu; return 0; }
r[2]=read(ram,0x0c09abb0u,4);
goto P_0c09ab10;
P_0c09ab10: /* original 420b, guest PC 0x0c09ab10 */
if(!s->budget--) { s->failed_pc=0x0c09ab10u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ab14u;
r[4]=read(ram,r[14]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ab14u) { target=s->pc; goto dispatch; }
goto P_0c09ab14;
P_0c09ab12: /* original 54e5, guest PC 0x0c09ab12 */
if(!s->budget--) { s->failed_pc=0x0c09ab12u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09ab14;
P_0c09ab14: /* original d328, guest PC 0x0c09ab14 */
if(!s->budget--) { s->failed_pc=0x0c09ab14u; return 0; }
r[3]=read(ram,0x0c09abb8u,4);
goto P_0c09ab16;
P_0c09ab16: /* original d427, guest PC 0x0c09ab16 */
if(!s->budget--) { s->failed_pc=0x0c09ab16u; return 0; }
r[4]=read(ram,0x0c09abb4u,4);
goto P_0c09ab18;
P_0c09ab18: /* original 430b, guest PC 0x0c09ab18 */
if(!s->budget--) { s->failed_pc=0x0c09ab18u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ab1cu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ab1cu) { target=s->pc; goto dispatch; }
goto P_0c09ab1c;
P_0c09ab1a: /* original e500, guest PC 0x0c09ab1a */
if(!s->budget--) { s->failed_pc=0x0c09ab1au; return 0; }
r[5]=0x00000000u;
goto P_0c09ab1c;
P_0c09ab1c: /* original 60b3, guest PC 0x0c09ab1c */
if(!s->budget--) { s->failed_pc=0x0c09ab1cu; return 0; }
r[0]=r[11];
goto P_0c09ab1e;
P_0c09ab1e: /* original 80ab, guest PC 0x0c09ab1e */
if(!s->budget--) { s->failed_pc=0x0c09ab1eu; return 0; }
write(ram,r[10]+11,r[0],1);
goto P_0c09ab20;
P_0c09ab20: /* original e043, guest PC 0x0c09ab20 */
if(!s->budget--) { s->failed_pc=0x0c09ab20u; return 0; }
r[0]=0x00000043u;
goto P_0c09ab22;
P_0c09ab22: /* original e30f, guest PC 0x0c09ab22 */
if(!s->budget--) { s->failed_pc=0x0c09ab22u; return 0; }
r[3]=0x0000000fu;
goto P_0c09ab24;
P_0c09ab24: /* original 0934, guest PC 0x0c09ab24 */
if(!s->budget--) { s->failed_pc=0x0c09ab24u; return 0; }
write(ram,r[9]+r[0],r[3],1);
goto P_0c09ab26;
P_0c09ab26: /* original 7f04, guest PC 0x0c09ab26 */
if(!s->budget--) { s->failed_pc=0x0c09ab26u; return 0; }
r[15]+=0x00000004u;
goto P_0c09ab28;
P_0c09ab28: /* original e044, guest PC 0x0c09ab28 */
if(!s->budget--) { s->failed_pc=0x0c09ab28u; return 0; }
r[0]=0x00000044u;
goto P_0c09ab2a;
P_0c09ab2a: /* original 4f26, guest PC 0x0c09ab2a */
if(!s->budget--) { s->failed_pc=0x0c09ab2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ab2c;
P_0c09ab2c: /* original 09b6, guest PC 0x0c09ab2c */
if(!s->budget--) { s->failed_pc=0x0c09ab2cu; return 0; }
write(ram,r[9]+r[0],r[11],4);
goto P_0c09ab2e;
P_0c09ab2e: /* original 84aa, guest PC 0x0c09ab2e */
if(!s->budget--) { s->failed_pc=0x0c09ab2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+10,1);
goto P_0c09ab30;
P_0c09ab30: /* original 7001, guest PC 0x0c09ab30 */
if(!s->budget--) { s->failed_pc=0x0c09ab30u; return 0; }
r[0]+=0x00000001u;
goto P_0c09ab32;
P_0c09ab32: /* original 80aa, guest PC 0x0c09ab32 */
if(!s->budget--) { s->failed_pc=0x0c09ab32u; return 0; }
write(ram,r[10]+10,r[0],1);
goto P_0c09ab34;
P_0c09ab34: /* original 69f6, guest PC 0x0c09ab34 */
if(!s->budget--) { s->failed_pc=0x0c09ab34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ab36;
P_0c09ab36: /* original 6af6, guest PC 0x0c09ab36 */
if(!s->budget--) { s->failed_pc=0x0c09ab36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ab38;
P_0c09ab38: /* original 6bf6, guest PC 0x0c09ab38 */
if(!s->budget--) { s->failed_pc=0x0c09ab38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ab3a;
P_0c09ab3a: /* original 6cf6, guest PC 0x0c09ab3a */
if(!s->budget--) { s->failed_pc=0x0c09ab3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ab3c;
P_0c09ab3c: /* original 6df6, guest PC 0x0c09ab3c */
if(!s->budget--) { s->failed_pc=0x0c09ab3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ab3e;
P_0c09ab3e: /* original a000, guest PC 0x0c09ab3e */
if(!s->budget--) { s->failed_pc=0x0c09ab3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ab42;
P_0c09ab40: /* original 6ef6, guest PC 0x0c09ab40 */
if(!s->budget--) { s->failed_pc=0x0c09ab40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ab42;
P_0c09ab42: /* original d410, guest PC 0x0c09ab42 */
if(!s->budget--) { s->failed_pc=0x0c09ab42u; return 0; }
r[4]=read(ram,0x0c09ab84u,4);
goto P_0c09ab44;
P_0c09ab44: /* original 7ffc, guest PC 0x0c09ab44 */
if(!s->budget--) { s->failed_pc=0x0c09ab44u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09ab46;
P_0c09ab46: /* original 844b, guest PC 0x0c09ab46 */
if(!s->budget--) { s->failed_pc=0x0c09ab46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c09ab48;
P_0c09ab48: /* original 650c, guest PC 0x0c09ab48 */
if(!s->budget--) { s->failed_pc=0x0c09ab48u; return 0; }
r[5]=r[0]&255u;
goto P_0c09ab4a;
P_0c09ab4a: /* original 6053, guest PC 0x0c09ab4a */
if(!s->budget--) { s->failed_pc=0x0c09ab4au; return 0; }
r[0]=r[5];
goto P_0c09ab4c;
P_0c09ab4c: /* original 8049, guest PC 0x0c09ab4c */
if(!s->budget--) { s->failed_pc=0x0c09ab4cu; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c09ab4e;
P_0c09ab4e: /* original d21b, guest PC 0x0c09ab4e */
if(!s->budget--) { s->failed_pc=0x0c09ab4eu; return 0; }
r[2]=read(ram,0x0c09abbcu,4);
goto P_0c09ab50;
P_0c09ab50: /* original 635b, guest PC 0x0c09ab50 */
if(!s->budget--) { s->failed_pc=0x0c09ab50u; return 0; }
r[3]=0u-r[5];
goto P_0c09ab52;
P_0c09ab52: /* original 4508, guest PC 0x0c09ab52 */
if(!s->budget--) { s->failed_pc=0x0c09ab52u; return 0; }
r[5]<<=2;
goto P_0c09ab54;
P_0c09ab54: /* original 423d, guest PC 0x0c09ab54 */
if(!s->budget--) { s->failed_pc=0x0c09ab54u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c09ab56;
P_0c09ab56: /* original 1421, guest PC 0x0c09ab56 */
if(!s->budget--) { s->failed_pc=0x0c09ab56u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09ab58;
P_0c09ab58: /* original d019, guest PC 0x0c09ab58 */
if(!s->budget--) { s->failed_pc=0x0c09ab58u; return 0; }
r[0]=read(ram,0x0c09abc0u,4);
goto P_0c09ab5a;
P_0c09ab5a: /* original 035e, guest PC 0x0c09ab5a */
if(!s->budget--) { s->failed_pc=0x0c09ab5au; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09ab5c;
P_0c09ab5c: /* original 6233, guest PC 0x0c09ab5c */
if(!s->budget--) { s->failed_pc=0x0c09ab5cu; return 0; }
r[2]=r[3];
goto P_0c09ab5e;
P_0c09ab5e: /* original 2f32, guest PC 0x0c09ab5e */
if(!s->budget--) { s->failed_pc=0x0c09ab5eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ab60;
P_0c09ab60: /* original 422b, guest PC 0x0c09ab60 */
if(!s->budget--) { s->failed_pc=0x0c09ab60u; return 0; }
target=r[2];
r[15]+=0x00000004u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09ab62: /* original 7f04, guest PC 0x0c09ab62 */
if(!s->budget--) { s->failed_pc=0x0c09ab62u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c09ab64u,s,ram);
P_0c0a1294: /* original 4f22, guest PC 0x0c0a1294 */
if(!s->budget--) { s->failed_pc=0x0c0a1294u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1296;
P_0c0a1296: /* original d31e, guest PC 0x0c0a1296 */
if(!s->budget--) { s->failed_pc=0x0c0a1296u; return 0; }
r[3]=read(ram,0x0c0a1310u,4);
goto P_0c0a1298;
P_0c0a1298: /* original 430b, guest PC 0x0c0a1298 */
if(!s->budget--) { s->failed_pc=0x0c0a1298u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a129cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a129cu) { target=s->pc; goto dispatch; }
goto P_0c0a129c;
P_0c0a129a: /* original 0009, guest PC 0x0c0a129a */
if(!s->budget--) { s->failed_pc=0x0c0a129au; return 0; }
goto P_0c0a129c;
P_0c0a129c: /* original d11d, guest PC 0x0c0a129c */
if(!s->budget--) { s->failed_pc=0x0c0a129cu; return 0; }
r[1]=read(ram,0x0c0a1314u,4);
goto P_0c0a129e;
P_0c0a129e: /* original 410b, guest PC 0x0c0a129e */
if(!s->budget--) { s->failed_pc=0x0c0a129eu; return 0; }
target=r[1];
r[16]=code_base|0x0c0a12a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a12a2u) { target=s->pc; goto dispatch; }
goto P_0c0a12a2;
P_0c0a12a0: /* original 0009, guest PC 0x0c0a12a0 */
if(!s->budget--) { s->failed_pc=0x0c0a12a0u; return 0; }
goto P_0c0a12a2;
P_0c0a12a2: /* original 8800, guest PC 0x0c0a12a2 */
if(!s->budget--) { s->failed_pc=0x0c0a12a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a12a4;
P_0c0a12a4: /* original 8909, guest PC 0x0c0a12a4 */
if(!s->budget--) { s->failed_pc=0x0c0a12a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a12ba; }
goto P_0c0a12a6;
P_0c0a12a6: /* original 8801, guest PC 0x0c0a12a6 */
if(!s->budget--) { s->failed_pc=0x0c0a12a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a12a8;
P_0c0a12a8: /* original 8903, guest PC 0x0c0a12a8 */
if(!s->budget--) { s->failed_pc=0x0c0a12a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a12b2; }
goto P_0c0a12aa;
P_0c0a12aa: /* original 8802, guest PC 0x0c0a12aa */
if(!s->budget--) { s->failed_pc=0x0c0a12aau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a12ac;
P_0c0a12ac: /* original 8903, guest PC 0x0c0a12ac */
if(!s->budget--) { s->failed_pc=0x0c0a12acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a12b6; }
goto P_0c0a12ae;
P_0c0a12ae: /* original a004, guest PC 0x0c0a12ae */
if(!s->budget--) { s->failed_pc=0x0c0a12aeu; return 0; }
goto P_0c0a12ba;
P_0c0a12b0: /* original 0009, guest PC 0x0c0a12b0 */
if(!s->budget--) { s->failed_pc=0x0c0a12b0u; return 0; }
goto P_0c0a12b2;
P_0c0a12b2: /* original a003, guest PC 0x0c0a12b2 */
if(!s->budget--) { s->failed_pc=0x0c0a12b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a12bc;
P_0c0a12b4: /* original e400, guest PC 0x0c0a12b4 */
if(!s->budget--) { s->failed_pc=0x0c0a12b4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a12b6;
P_0c0a12b6: /* original a001, guest PC 0x0c0a12b6 */
if(!s->budget--) { s->failed_pc=0x0c0a12b6u; return 0; }
r[4]=0x00000013u;
goto P_0c0a12bc;
P_0c0a12b8: /* original e413, guest PC 0x0c0a12b8 */
if(!s->budget--) { s->failed_pc=0x0c0a12b8u; return 0; }
r[4]=0x00000013u;
goto P_0c0a12ba;
P_0c0a12ba: /* original e409, guest PC 0x0c0a12ba */
if(!s->budget--) { s->failed_pc=0x0c0a12bau; return 0; }
r[4]=0x00000009u;
goto P_0c0a12bc;
P_0c0a12bc: /* original 4f26, guest PC 0x0c0a12bc */
if(!s->budget--) { s->failed_pc=0x0c0a12bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a12be;
P_0c0a12be: /* original 000b, guest PC 0x0c0a12be */
if(!s->budget--) { s->failed_pc=0x0c0a12beu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0a12c0: /* original 6043, guest PC 0x0c0a12c0 */
if(!s->budget--) { s->failed_pc=0x0c0a12c0u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0a12c2u,s,ram);
P_0c0a2a84: /* original 4f22, guest PC 0x0c0a2a84 */
if(!s->budget--) { s->failed_pc=0x0c0a2a84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2a86;
P_0c0a2a86: /* original 7ff4, guest PC 0x0c0a2a86 */
if(!s->budget--) { s->failed_pc=0x0c0a2a86u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2a88;
P_0c0a2a88: /* original 2f61, guest PC 0x0c0a2a88 */
if(!s->budget--) { s->failed_pc=0x0c0a2a88u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a2a8a;
P_0c0a2a8a: /* original 1f72, guest PC 0x0c0a2a8a */
if(!s->budget--) { s->failed_pc=0x0c0a2a8au; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a2a8c;
P_0c0a2a8c: /* original b0d3, guest PC 0x0c0a2a8c */
if(!s->budget--) { s->failed_pc=0x0c0a2a8cu; return 0; }
target=0x0c0a2c36u; r[16]=code_base|0x0c0a2a90u;
r[11]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a90u) { target=s->pc; goto dispatch; }
goto P_0c0a2a90;
P_0c0a2a8e: /* original 6b53, guest PC 0x0c0a2a8e */
if(!s->budget--) { s->failed_pc=0x0c0a2a8eu; return 0; }
r[11]=r[5];
goto P_0c0a2a90;
P_0c0a2a90: /* original 6d03, guest PC 0x0c0a2a90 */
if(!s->budget--) { s->failed_pc=0x0c0a2a90u; return 0; }
r[13]=r[0];
goto P_0c0a2a92;
P_0c0a2a92: /* original 2dd8, guest PC 0x0c0a2a92 */
if(!s->budget--) { s->failed_pc=0x0c0a2a92u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a2a94;
P_0c0a2a94: /* original 8902, guest PC 0x0c0a2a94 */
if(!s->budget--) { s->failed_pc=0x0c0a2a94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a9c; }
goto P_0c0a2a96;
P_0c0a2a96: /* original d339, guest PC 0x0c0a2a96 */
if(!s->budget--) { s->failed_pc=0x0c0a2a96u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a2a98;
P_0c0a2a98: /* original 3d30, guest PC 0x0c0a2a98 */
if(!s->budget--) { s->failed_pc=0x0c0a2a98u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0a2a9a;
P_0c0a2a9a: /* original 8b60, guest PC 0x0c0a2a9a */
if(!s->budget--) { s->failed_pc=0x0c0a2a9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b5e; }
goto P_0c0a2a9c;
P_0c0a2a9c: /* original e020, guest PC 0x0c0a2a9c */
if(!s->budget--) { s->failed_pc=0x0c0a2a9cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2a9e;
P_0c0a2a9e: /* original 01ed, guest PC 0x0c0a2a9e */
if(!s->budget--) { s->failed_pc=0x0c0a2a9eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa0;
P_0c0a2aa0: /* original e022, guest PC 0x0c0a2aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2aa2;
P_0c0a2aa2: /* original 03ed, guest PC 0x0c0a2aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa4;
P_0c0a2aa4: /* original 611d, guest PC 0x0c0a2aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a2aa6;
P_0c0a2aa6: /* original 633d, guest PC 0x0c0a2aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2aa8;
P_0c0a2aa8: /* original 213b, guest PC 0x0c0a2aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa8u; return 0; }
r[1]|=r[3];
goto P_0c0a2aaa;
P_0c0a2aaa: /* original 2118, guest PC 0x0c0a2aaa */
if(!s->budget--) { s->failed_pc=0x0c0a2aaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a2aac;
P_0c0a2aac: /* original 8b5b, guest PC 0x0c0a2aac */
if(!s->budget--) { s->failed_pc=0x0c0a2aacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b66; }
goto P_0c0a2aae;
P_0c0a2aae: /* original e020, guest PC 0x0c0a2aae */
if(!s->budget--) { s->failed_pc=0x0c0a2aaeu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2ab0;
P_0c0a2ab0: /* original 52e4, guest PC 0x0c0a2ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab0u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a2ab2;
P_0c0a2ab2: /* original 1f21, guest PC 0x0c0a2ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab2u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2ab4;
P_0c0a2ab4: /* original 63f1, guest PC 0x0c0a2ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2ab6;
P_0c0a2ab6: /* original 5de5, guest PC 0x0c0a2ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab6u; return 0; }
r[13]=read(ram,r[14]+20,4);
goto P_0c0a2ab8;
P_0c0a2ab8: /* original 0e35, guest PC 0x0c0a2ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a2aba;
P_0c0a2aba: /* original 04ed, guest PC 0x0c0a2aba */
if(!s->budget--) { s->failed_pc=0x0c0a2abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2abc;
P_0c0a2abc: /* original d330, guest PC 0x0c0a2abc */
if(!s->budget--) { s->failed_pc=0x0c0a2abcu; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a2abe;
P_0c0a2abe: /* original 430b, guest PC 0x0c0a2abe */
if(!s->budget--) { s->failed_pc=0x0c0a2abeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac2u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2ac2u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac2;
P_0c0a2ac0: /* original 644d, guest PC 0x0c0a2ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2ac2;
P_0c0a2ac2: /* original d333, guest PC 0x0c0a2ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac2u; return 0; }
r[3]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2ac4;
P_0c0a2ac4: /* original 430b, guest PC 0x0c0a2ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac8u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2ac8u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac8;
P_0c0a2ac6: /* original 54f2, guest PC 0x0c0a2ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a2ac8;
P_0c0a2ac8: /* original ea00, guest PC 0x0c0a2ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac8u; return 0; }
r[10]=0x00000000u;
goto P_0c0a2aca;
P_0c0a2aca: /* original a039, guest PC 0x0c0a2aca */
if(!s->budget--) { s->failed_pc=0x0c0a2acau; return 0; }
r[8]=r[10];
goto P_0c0a2b40;
P_0c0a2acc: /* original 68a3, guest PC 0x0c0a2acc */
if(!s->budget--) { s->failed_pc=0x0c0a2accu; return 0; }
r[8]=r[10];
goto P_0c0a2ace;
P_0c0a2ace: /* original 53f1, guest PC 0x0c0a2ace */
if(!s->budget--) { s->failed_pc=0x0c0a2aceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a2ad0;
P_0c0a2ad0: /* original 6c83, guest PC 0x0c0a2ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad0u; return 0; }
r[12]=r[8];
goto P_0c0a2ad2;
P_0c0a2ad2: /* original 4c08, guest PC 0x0c0a2ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad2u; return 0; }
r[12]<<=2;
goto P_0c0a2ad4;
P_0c0a2ad4: /* original 3c3c, guest PC 0x0c0a2ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad4u; return 0; }
r[12]+=r[3];
goto P_0c0a2ad6;
P_0c0a2ad6: /* original 60c2, guest PC 0x0c0a2ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad6u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0a2ad8;
P_0c0a2ad8: /* original 5001, guest PC 0x0c0a2ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad8u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a2ada;
P_0c0a2ada: /* original c801, guest PC 0x0c0a2ada */
if(!s->budget--) { s->failed_pc=0x0c0a2adau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2adc;
P_0c0a2adc: /* original 8922, guest PC 0x0c0a2adc */
if(!s->budget--) { s->failed_pc=0x0c0a2adcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2b24; }
goto P_0c0a2ade;
P_0c0a2ade: /* original a008, guest PC 0x0c0a2ade */
if(!s->budget--) { s->failed_pc=0x0c0a2adeu; return 0; }
r[4]=r[10];
goto P_0c0a2af2;
P_0c0a2ae0: /* original 64a3, guest PC 0x0c0a2ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae0u; return 0; }
r[4]=r[10];
goto P_0c0a2ae2;
P_0c0a2ae2: /* original 6343, guest PC 0x0c0a2ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae2u; return 0; }
r[3]=r[4];
goto P_0c0a2ae4;
P_0c0a2ae4: /* original 4308, guest PC 0x0c0a2ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae4u; return 0; }
r[3]<<=2;
goto P_0c0a2ae6;
P_0c0a2ae6: /* original 4308, guest PC 0x0c0a2ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae6u; return 0; }
r[3]<<=2;
goto P_0c0a2ae8;
P_0c0a2ae8: /* original 33dc, guest PC 0x0c0a2ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae8u; return 0; }
r[3]+=r[13];
goto P_0c0a2aea;
P_0c0a2aea: /* original 5232, guest PC 0x0c0a2aea */
if(!s->budget--) { s->failed_pc=0x0c0a2aeau; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2aec;
P_0c0a2aec: /* original 7401, guest PC 0x0c0a2aec */
if(!s->budget--) { s->failed_pc=0x0c0a2aecu; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2aee;
P_0c0a2aee: /* original 32bc, guest PC 0x0c0a2aee */
if(!s->budget--) { s->failed_pc=0x0c0a2aeeu; return 0; }
r[2]+=r[11];
goto P_0c0a2af0;
P_0c0a2af0: /* original 1322, guest PC 0x0c0a2af0 */
if(!s->budget--) { s->failed_pc=0x0c0a2af0u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2af2;
P_0c0a2af2: /* original 85e7, guest PC 0x0c0a2af2 */
if(!s->budget--) { s->failed_pc=0x0c0a2af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2af4;
P_0c0a2af4: /* original 600d, guest PC 0x0c0a2af4 */
if(!s->budget--) { s->failed_pc=0x0c0a2af4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2af6;
P_0c0a2af6: /* original 3403, guest PC 0x0c0a2af6 */
if(!s->budget--) { s->failed_pc=0x0c0a2af6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2af8;
P_0c0a2af8: /* original 8bf3, guest PC 0x0c0a2af8 */
if(!s->budget--) { s->failed_pc=0x0c0a2af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ae2; }
goto P_0c0a2afa;
P_0c0a2afa: /* original d222, guest PC 0x0c0a2afa */
if(!s->budget--) { s->failed_pc=0x0c0a2afau; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2afc;
P_0c0a2afc: /* original 65d3, guest PC 0x0c0a2afc */
if(!s->budget--) { s->failed_pc=0x0c0a2afcu; return 0; }
r[5]=r[13];
goto P_0c0a2afe;
P_0c0a2afe: /* original 420b, guest PC 0x0c0a2afe */
if(!s->budget--) { s->failed_pc=0x0c0a2afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b02u;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2b02u) { target=s->pc; goto dispatch; }
goto P_0c0a2b02;
P_0c0a2b00: /* original 64c2, guest PC 0x0c0a2b00 */
if(!s->budget--) { s->failed_pc=0x0c0a2b00u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b02;
P_0c0a2b02: /* original 2008, guest PC 0x0c0a2b02 */
if(!s->budget--) { s->failed_pc=0x0c0a2b02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b04;
P_0c0a2b04: /* original a008, guest PC 0x0c0a2b04 */
if(!s->budget--) { s->failed_pc=0x0c0a2b04u; return 0; }
r[4]=r[10];
goto P_0c0a2b18;
P_0c0a2b06: /* original 64a3, guest PC 0x0c0a2b06 */
if(!s->budget--) { s->failed_pc=0x0c0a2b06u; return 0; }
r[4]=r[10];
goto P_0c0a2b08;
P_0c0a2b08: /* original 6343, guest PC 0x0c0a2b08 */
if(!s->budget--) { s->failed_pc=0x0c0a2b08u; return 0; }
r[3]=r[4];
goto P_0c0a2b0a;
P_0c0a2b0a: /* original 4308, guest PC 0x0c0a2b0a */
if(!s->budget--) { s->failed_pc=0x0c0a2b0au; return 0; }
r[3]<<=2;
goto P_0c0a2b0c;
P_0c0a2b0c: /* original 4308, guest PC 0x0c0a2b0c */
if(!s->budget--) { s->failed_pc=0x0c0a2b0cu; return 0; }
r[3]<<=2;
goto P_0c0a2b0e;
P_0c0a2b0e: /* original 33dc, guest PC 0x0c0a2b0e */
if(!s->budget--) { s->failed_pc=0x0c0a2b0eu; return 0; }
r[3]+=r[13];
goto P_0c0a2b10;
P_0c0a2b10: /* original 5232, guest PC 0x0c0a2b10 */
if(!s->budget--) { s->failed_pc=0x0c0a2b10u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2b12;
P_0c0a2b12: /* original 7401, guest PC 0x0c0a2b12 */
if(!s->budget--) { s->failed_pc=0x0c0a2b12u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2b14;
P_0c0a2b14: /* original 32b8, guest PC 0x0c0a2b14 */
if(!s->budget--) { s->failed_pc=0x0c0a2b14u; return 0; }
r[2]-=r[11];
goto P_0c0a2b16;
P_0c0a2b16: /* original 1322, guest PC 0x0c0a2b16 */
if(!s->budget--) { s->failed_pc=0x0c0a2b16u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2b18;
P_0c0a2b18: /* original 85e7, guest PC 0x0c0a2b18 */
if(!s->budget--) { s->failed_pc=0x0c0a2b18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b1a;
P_0c0a2b1a: /* original 600d, guest PC 0x0c0a2b1a */
if(!s->budget--) { s->failed_pc=0x0c0a2b1au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b1c;
P_0c0a2b1c: /* original 3403, guest PC 0x0c0a2b1c */
if(!s->budget--) { s->failed_pc=0x0c0a2b1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2b1e;
P_0c0a2b1e: /* original 8bf3, guest PC 0x0c0a2b1e */
if(!s->budget--) { s->failed_pc=0x0c0a2b1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b08; }
goto P_0c0a2b20;
P_0c0a2b20: /* original a00d, guest PC 0x0c0a2b20 */
if(!s->budget--) { s->failed_pc=0x0c0a2b20u; return 0; }
goto P_0c0a2b3e;
P_0c0a2b22: /* original 0009, guest PC 0x0c0a2b22 */
if(!s->budget--) { s->failed_pc=0x0c0a2b22u; return 0; }
goto P_0c0a2b24;
P_0c0a2b24: /* original 64c2, guest PC 0x0c0a2b24 */
if(!s->budget--) { s->failed_pc=0x0c0a2b24u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b26;
P_0c0a2b26: /* original 66b3, guest PC 0x0c0a2b26 */
if(!s->budget--) { s->failed_pc=0x0c0a2b26u; return 0; }
r[6]=r[11];
goto P_0c0a2b28;
P_0c0a2b28: /* original d317, guest PC 0x0c0a2b28 */
if(!s->budget--) { s->failed_pc=0x0c0a2b28u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2b2a;
P_0c0a2b2a: /* original 65d3, guest PC 0x0c0a2b2a */
if(!s->budget--) { s->failed_pc=0x0c0a2b2au; return 0; }
r[5]=r[13];
goto P_0c0a2b2c;
P_0c0a2b2c: /* original 430b, guest PC 0x0c0a2b2c */
if(!s->budget--) { s->failed_pc=0x0c0a2b2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b30u;
r[4]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2b30u) { target=s->pc; goto dispatch; }
goto P_0c0a2b30;
P_0c0a2b2e: /* original 5441, guest PC 0x0c0a2b2e */
if(!s->budget--) { s->failed_pc=0x0c0a2b2eu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2b30;
P_0c0a2b30: /* original 69c2, guest PC 0x0c0a2b30 */
if(!s->budget--) { s->failed_pc=0x0c0a2b30u; return 0; }
tmp=read(ram,r[12],4);
r[9]=tmp;
goto P_0c0a2b32;
P_0c0a2b32: /* original 2008, guest PC 0x0c0a2b32 */
if(!s->budget--) { s->failed_pc=0x0c0a2b32u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b34;
P_0c0a2b34: /* original d315, guest PC 0x0c0a2b34 */
if(!s->budget--) { s->failed_pc=0x0c0a2b34u; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2b36;
P_0c0a2b36: /* original 5591, guest PC 0x0c0a2b36 */
if(!s->budget--) { s->failed_pc=0x0c0a2b36u; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2b38;
P_0c0a2b38: /* original 5692, guest PC 0x0c0a2b38 */
if(!s->budget--) { s->failed_pc=0x0c0a2b38u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2b3a;
P_0c0a2b3a: /* original 430b, guest PC 0x0c0a2b3a */
if(!s->budget--) { s->failed_pc=0x0c0a2b3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b3eu;
tmp=read(ram,r[9],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2b3eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b3e;
P_0c0a2b3c: /* original 6492, guest PC 0x0c0a2b3c */
if(!s->budget--) { s->failed_pc=0x0c0a2b3cu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2b3e;
P_0c0a2b3e: /* original 7801, guest PC 0x0c0a2b3e */
if(!s->budget--) { s->failed_pc=0x0c0a2b3eu; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2b40;
P_0c0a2b40: /* original 85e6, guest PC 0x0c0a2b40 */
if(!s->budget--) { s->failed_pc=0x0c0a2b40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2b42;
P_0c0a2b42: /* original 600d, guest PC 0x0c0a2b42 */
if(!s->budget--) { s->failed_pc=0x0c0a2b42u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b44;
P_0c0a2b44: /* original 3803, guest PC 0x0c0a2b44 */
if(!s->budget--) { s->failed_pc=0x0c0a2b44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2b46;
P_0c0a2b46: /* original 8bc2, guest PC 0x0c0a2b46 */
if(!s->budget--) { s->failed_pc=0x0c0a2b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ace; }
goto P_0c0a2b48;
P_0c0a2b48: /* original d211, guest PC 0x0c0a2b48 */
if(!s->budget--) { s->failed_pc=0x0c0a2b48u; return 0; }
r[2]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2b4a;
P_0c0a2b4a: /* original 420b, guest PC 0x0c0a2b4a */
if(!s->budget--) { s->failed_pc=0x0c0a2b4au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b4eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2b4eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b4e;
P_0c0a2b4c: /* original e400, guest PC 0x0c0a2b4c */
if(!s->budget--) { s->failed_pc=0x0c0a2b4cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a2b4e;
P_0c0a2b4e: /* original 63f1, guest PC 0x0c0a2b4e */
if(!s->budget--) { s->failed_pc=0x0c0a2b4eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2b50;
P_0c0a2b50: /* original e222, guest PC 0x0c0a2b50 */
if(!s->budget--) { s->failed_pc=0x0c0a2b50u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2b52;
P_0c0a2b52: /* original 85e7, guest PC 0x0c0a2b52 */
if(!s->budget--) { s->failed_pc=0x0c0a2b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b54;
P_0c0a2b54: /* original 32ec, guest PC 0x0c0a2b54 */
if(!s->budget--) { s->failed_pc=0x0c0a2b54u; return 0; }
r[2]+=r[14];
goto P_0c0a2b56;
P_0c0a2b56: /* original 303c, guest PC 0x0c0a2b56 */
if(!s->budget--) { s->failed_pc=0x0c0a2b56u; return 0; }
r[0]+=r[3];
goto P_0c0a2b58;
P_0c0a2b58: /* original 2201, guest PC 0x0c0a2b58 */
if(!s->budget--) { s->failed_pc=0x0c0a2b58u; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2b5a;
P_0c0a2b5a: /* original a004, guest PC 0x0c0a2b5a */
if(!s->budget--) { s->failed_pc=0x0c0a2b5au; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b66;
P_0c0a2b5c: /* original ed00, guest PC 0x0c0a2b5c */
if(!s->budget--) { s->failed_pc=0x0c0a2b5cu; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b5e;
P_0c0a2b5e: /* original d20d, guest PC 0x0c0a2b5e */
if(!s->budget--) { s->failed_pc=0x0c0a2b5eu; return 0; }
r[2]=read(ram,0x0c0a2b94u,4);
goto P_0c0a2b60;
P_0c0a2b60: /* original e57e, guest PC 0x0c0a2b60 */
if(!s->budget--) { s->failed_pc=0x0c0a2b60u; return 0; }
r[5]=0x0000007eu;
goto P_0c0a2b62;
P_0c0a2b62: /* original 420b, guest PC 0x0c0a2b62 */
if(!s->budget--) { s->failed_pc=0x0c0a2b62u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b66u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2b66u) { target=s->pc; goto dispatch; }
goto P_0c0a2b66;
P_0c0a2b64: /* original e401, guest PC 0x0c0a2b64 */
if(!s->budget--) { s->failed_pc=0x0c0a2b64u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2b66;
P_0c0a2b66: /* original 7f0c, guest PC 0x0c0a2b66 */
if(!s->budget--) { s->failed_pc=0x0c0a2b66u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2b68;
P_0c0a2b68: /* original 60d3, guest PC 0x0c0a2b68 */
if(!s->budget--) { s->failed_pc=0x0c0a2b68u; return 0; }
r[0]=r[13];
goto P_0c0a2b6a;
P_0c0a2b6a: /* original 4f26, guest PC 0x0c0a2b6a */
if(!s->budget--) { s->failed_pc=0x0c0a2b6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2b6c;
P_0c0a2b6c: /* original 68f6, guest PC 0x0c0a2b6c */
if(!s->budget--) { s->failed_pc=0x0c0a2b6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2b6e;
P_0c0a2b6e: /* original 69f6, guest PC 0x0c0a2b6e */
if(!s->budget--) { s->failed_pc=0x0c0a2b6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2b70;
P_0c0a2b70: /* original 6af6, guest PC 0x0c0a2b70 */
if(!s->budget--) { s->failed_pc=0x0c0a2b70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2b72;
P_0c0a2b72: /* original 6bf6, guest PC 0x0c0a2b72 */
if(!s->budget--) { s->failed_pc=0x0c0a2b72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2b74;
P_0c0a2b74: /* original 6cf6, guest PC 0x0c0a2b74 */
if(!s->budget--) { s->failed_pc=0x0c0a2b74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2b76;
P_0c0a2b76: /* original 6df6, guest PC 0x0c0a2b76 */
if(!s->budget--) { s->failed_pc=0x0c0a2b76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2b78;
P_0c0a2b78: /* original 000b, guest PC 0x0c0a2b78 */
if(!s->budget--) { s->failed_pc=0x0c0a2b78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2b7a: /* original 6ef6, guest PC 0x0c0a2b7a */
if(!s->budget--) { s->failed_pc=0x0c0a2b7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2b7cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c035270u,0x0c035272u,0x0c035274u,0x0c035276u,0x0c035278u,0x0c03527au,0x0c03527cu,0x0c03527eu,0x0c035280u,0x0c035282u,0x0c035284u,0x0c035286u,0x0c035288u,0x0c03528au,0x0c03528cu,0x0c03528eu,
0x0c035290u,0x0c035292u,0x0c035294u,0x0c035296u,0x0c035298u,0x0c03529au,0x0c03529cu,0x0c03529eu,0x0c0352a0u,0x0c0352a2u,0x0c0352a4u,0x0c0352a6u,0x0c0352a8u,0x0c0352aau,0x0c0352acu,0x0c0352aeu,
0x0c0352b0u,0x0c0352b2u,0x0c0352b4u,0x0c0352b6u,0x0c0352b8u,0x0c0352bau,0x0c0352bcu,0x0c0352beu,0x0c0352c0u,0x0c0352c2u,0x0c0352c4u,0x0c0352c6u,0x0c0352c8u,0x0c0352cau,0x0c0352ccu,0x0c0352ceu,
0x0c0352d0u,0x0c0352d2u,0x0c0352d4u,0x0c0352d6u,0x0c0352d8u,0x0c035306u,0x0c035308u,0x0c03530au,0x0c03530cu,0x0c03530eu,0x0c035310u,0x0c035312u,0x0c035314u,0x0c035316u,0x0c035318u,0x0c03531au,
0x0c03531cu,0x0c03531eu,0x0c035320u,0x0c035322u,0x0c035324u,0x0c035326u,0x0c035328u,0x0c03532au,0x0c03532cu,0x0c03532eu,0x0c035330u,0x0c035332u,0x0c035334u,0x0c035336u,0x0c035338u,0x0c03533au,
0x0c03533cu,0x0c03533eu,0x0c035340u,0x0c035342u,0x0c035344u,0x0c035346u,0x0c035348u,0x0c03534au,0x0c03534cu,0x0c03534eu,0x0c035350u,0x0c035352u,0x0c035354u,0x0c035356u,0x0c035358u,0x0c03535au,
0x0c03535cu,0x0c03535eu,0x0c035360u,0x0c035362u,0x0c035364u,0x0c035366u,0x0c035368u,0x0c03536au,0x0c035370u,0x0c035372u,0x0c035374u,0x0c035376u,0x0c035378u,0x0c03537au,0x0c03537cu,0x0c03537eu,
0x0c035380u,0x0c035382u,0x0c035384u,0x0c035386u,0x0c035388u,0x0c03538au,0x0c03538cu,0x0c03538eu,0x0c035390u,0x0c035392u,0x0c035394u,0x0c035396u,0x0c035398u,0x0c03539au,0x0c03539cu,0x0c03539eu,
0x0c0353a0u,0x0c0353a2u,0x0c0353a4u,0x0c0353a6u,0x0c0353a8u,0x0c0353aau,0x0c0353acu,0x0c0353aeu,0x0c0353b0u,0x0c0353b2u,0x0c0353b4u,0x0c0353b6u,0x0c0353b8u,0x0c0353bau,0x0c0353bcu,0x0c0353beu,
0x0c0353c0u,0x0c0353c2u,0x0c0353c4u,0x0c0353c6u,0x0c0353c8u,0x0c0353cau,0x0c0353ccu,0x0c0353ceu,0x0c0353d0u,0x0c0353d2u,0x0c0353d4u,0x0c0354a4u,0x0c0354a6u,0x0c0354a8u,0x0c0354aau,0x0c0354acu,
0x0c0354aeu,0x0c0354b0u,0x0c0354b2u,0x0c0354b4u,0x0c0354b6u,0x0c0354b8u,0x0c0354bau,0x0c0354bcu,0x0c0354beu,0x0c0354c0u,0x0c0354c2u,0x0c0354c4u,0x0c0354c6u,0x0c0354c8u,0x0c0354cau,0x0c0354ccu,
0x0c0354ceu,0x0c0354d0u,0x0c0354d2u,0x0c0354d4u,0x0c0354d6u,0x0c0354d8u,0x0c0354dau,0x0c0354dcu,0x0c0354deu,0x0c0354e0u,0x0c0354e2u,0x0c0354e4u,0x0c0354e6u,0x0c0354e8u,0x0c0354eau,0x0c0354ecu,
0x0c0354eeu,0x0c0354f0u,0x0c0354f2u,0x0c0354f4u,0x0c0354f6u,0x0c0354f8u,0x0c0354fau,0x0c0354fcu,0x0c0354feu,0x0c035500u,0x0c035518u,0x0c03551au,0x0c03551cu,0x0c03551eu,0x0c035520u,0x0c035522u,
0x0c035524u,0x0c035526u,0x0c035528u,0x0c03552au,0x0c03552cu,0x0c03552eu,0x0c035530u,0x0c035532u,0x0c035534u,0x0c035536u,0x0c035538u,0x0c03553au,0x0c03553cu,0x0c03553eu,0x0c035540u,0x0c035542u,
0x0c035544u,0x0c035546u,0x0c035548u,0x0c03554au,0x0c03554cu,0x0c03554eu,0x0c035550u,0x0c035552u,0x0c035554u,0x0c035556u,0x0c035558u,0x0c03555au,0x0c03555cu,0x0c03555eu,0x0c035560u,0x0c035562u,
0x0c035564u,0x0c035566u,0x0c035568u,0x0c03556au,0x0c03556cu,0x0c03556eu,0x0c035570u,0x0c035572u,0x0c035574u,0x0c035576u,0x0c035578u,0x0c03557au,0x0c03557cu,0x0c03557eu,0x0c035580u,0x0c035582u,
0x0c035584u,0x0c035586u,0x0c035588u,0x0c03558au,0x0c03558cu,0x0c03746au,0x0c03746cu,0x0c03746eu,0x0c037470u,0x0c037472u,0x0c037474u,0x0c037476u,0x0c037478u,0x0c03747au,0x0c03747cu,0x0c03747eu,
0x0c037480u,0x0c037482u,0x0c037484u,0x0c037486u,0x0c037488u,0x0c03748au,0x0c03748cu,0x0c03748eu,0x0c037490u,0x0c037492u,0x0c037494u,0x0c037496u,0x0c037498u,0x0c03749au,0x0c03749cu,0x0c03749eu,
0x0c0374a0u,0x0c0374a2u,0x0c0374a4u,0x0c0374a6u,0x0c0374a8u,0x0c0374aau,0x0c0374acu,0x0c0374aeu,0x0c0374b0u,0x0c0374b2u,0x0c0374b4u,0x0c0374b6u,0x0c0374b8u,0x0c0374bau,0x0c0374bcu,0x0c0374beu,
0x0c0374c0u,0x0c0374c2u,0x0c0374c4u,0x0c0374c6u,0x0c0374c8u,0x0c0374cau,0x0c0374ccu,0x0c0374ceu,0x0c0374d0u,0x0c0374d2u,0x0c0374d4u,0x0c0374d6u,0x0c0374d8u,0x0c0374dau,0x0c0374dcu,0x0c0374deu,
0x0c0374e0u,0x0c0374e2u,0x0c0374e4u,0x0c0374e6u,0x0c0374e8u,0x0c0374eau,0x0c0374ecu,0x0c0374eeu,0x0c0374f0u,0x0c0374f2u,0x0c0374f4u,0x0c0374f6u,0x0c0374f8u,0x0c0374fau,0x0c0374fcu,0x0c0374feu,
0x0c037500u,0x0c0377a8u,0x0c0377aau,0x0c0377acu,0x0c0377aeu,0x0c0377b0u,0x0c0377b2u,0x0c0377b4u,0x0c0377b6u,0x0c0377b8u,0x0c0377bau,0x0c0377bcu,0x0c0377beu,0x0c0377c0u,0x0c0377c2u,0x0c0377c4u,
0x0c0377c6u,0x0c0377c8u,0x0c0377cau,0x0c0377ccu,0x0c0377ceu,0x0c0377d0u,0x0c0377d2u,0x0c0377d4u,0x0c0377d6u,0x0c0377d8u,0x0c0377dau,0x0c0377dcu,0x0c0377deu,0x0c0377e0u,0x0c0377e2u,0x0c0377e4u,
0x0c0377e6u,0x0c0377e8u,0x0c0377eau,0x0c0377ecu,0x0c0377eeu,0x0c0377f0u,0x0c0377f2u,0x0c0377f4u,0x0c0377f6u,0x0c0377f8u,0x0c0377fau,0x0c03780cu,0x0c03780eu,0x0c037810u,0x0c037812u,0x0c037814u,
0x0c037816u,0x0c037818u,0x0c03781au,0x0c03781cu,0x0c03781eu,0x0c037820u,0x0c037822u,0x0c037824u,0x0c037826u,0x0c037828u,0x0c03782au,0x0c03782cu,0x0c03782eu,0x0c037830u,0x0c037832u,0x0c037834u,
0x0c037836u,0x0c037838u,0x0c03783au,0x0c03783cu,0x0c03783eu,0x0c037840u,0x0c037842u,0x0c037844u,0x0c037846u,0x0c037848u,0x0c03784au,0x0c03784cu,0x0c03784eu,0x0c037850u,0x0c037852u,0x0c037854u,
0x0c037856u,0x0c03bbd2u,0x0c03bbd4u,0x0c03bbd6u,0x0c03bbd8u,0x0c03bbdau,0x0c03bbdcu,0x0c03bbdeu,0x0c03bbe0u,0x0c03bbe2u,0x0c03bbe4u,0x0c03bbe6u,0x0c03bbe8u,0x0c03bbeau,0x0c03bbecu,0x0c03bbeeu,
0x0c03bbf0u,0x0c03bbf2u,0x0c03bbf4u,0x0c03bbf6u,0x0c03bbf8u,0x0c03bbfau,0x0c03bbfcu,0x0c03bbfeu,0x0c03bc00u,0x0c03bc02u,0x0c03bc04u,0x0c03bc06u,0x0c03bc08u,0x0c03bc0au,0x0c03bc0cu,0x0c03bc0eu,
0x0c03bc10u,0x0c03bc12u,0x0c03bc14u,0x0c03bc16u,0x0c03bc18u,0x0c03bc1au,0x0c03bc1cu,0x0c03bc1eu,0x0c03bc20u,0x0c03bc22u,0x0c03bc24u,0x0c03bc26u,0x0c03bc28u,0x0c03bc2au,0x0c03bc2cu,0x0c03bc2eu,
0x0c03bc30u,0x0c03bc32u,0x0c03bc34u,0x0c03bc36u,0x0c03bc38u,0x0c03bc3au,0x0c03bc3cu,0x0c03bc3eu,0x0c03bc40u,0x0c03bc42u,0x0c03bc44u,0x0c03bc46u,0x0c03bc48u,0x0c03bc4au,0x0c03bc4cu,0x0c03bc4eu,
0x0c03bc50u,0x0c03bc52u,0x0c03bc54u,0x0c03bc56u,0x0c03bc58u,0x0c03bc5au,0x0c03bc5cu,0x0c03bc5eu,0x0c03bc60u,0x0c03bc62u,0x0c03bc64u,0x0c03bc66u,0x0c03bc68u,0x0c03bc6au,0x0c03bc6cu,0x0c03bc6eu,
0x0c03bc70u,0x0c03bc72u,0x0c03bc74u,0x0c03bc76u,0x0c03bc78u,0x0c03bc7au,0x0c03bc7cu,0x0c03bc7eu,0x0c03bc80u,0x0c03bc82u,0x0c03bc84u,0x0c03bc86u,0x0c03bc88u,0x0c03bc8au,0x0c03bc8cu,0x0c03bc8eu,
0x0c03bc90u,0x0c03bc92u,0x0c042672u,0x0c042674u,0x0c042676u,0x0c042678u,0x0c04267au,0x0c04267cu,0x0c04267eu,0x0c042680u,0x0c042682u,0x0c042684u,0x0c042686u,0x0c042688u,0x0c04268au,0x0c04268cu,
0x0c04268eu,0x0c042690u,0x0c042692u,0x0c042694u,0x0c042696u,0x0c042698u,0x0c04269au,0x0c04269cu,0x0c04269eu,0x0c0426a0u,0x0c0426a2u,0x0c0426a4u,0x0c0426a6u,0x0c0426a8u,0x0c0426aau,0x0c0426acu,
0x0c0426aeu,0x0c0426b0u,0x0c0426b2u,0x0c0426b4u,0x0c0426b6u,0x0c0426b8u,0x0c0426bau,0x0c0426c0u,0x0c0426c2u,0x0c0426c4u,0x0c0426c6u,0x0c0426d0u,0x0c0426d2u,0x0c0426d4u,0x0c0426d6u,0x0c0426d8u,
0x0c0426dau,0x0c0426dcu,0x0c0426deu,0x0c0426e0u,0x0c0426e2u,0x0c0426e4u,0x0c0426e6u,0x0c0426e8u,0x0c0426eau,0x0c0426ecu,0x0c0426eeu,0x0c0426f0u,0x0c0426f2u,0x0c0426f4u,0x0c0426f6u,0x0c0426f8u,
0x0c0426fau,0x0c0426fcu,0x0c0426feu,0x0c042700u,0x0c042702u,0x0c042704u,0x0c042706u,0x0c042708u,0x0c04270au,0x0c04270cu,0x0c04270eu,0x0c042710u,0x0c042740u,0x0c042742u,0x0c042744u,0x0c042746u,
0x0c042748u,0x0c04274au,0x0c04274cu,0x0c04274eu,0x0c042750u,0x0c042752u,0x0c042754u,0x0c042756u,0x0c042758u,0x0c04275au,0x0c04275cu,0x0c04275eu,0x0c042760u,0x0c042762u,0x0c042764u,0x0c042766u,
0x0c042768u,0x0c04276au,0x0c04276cu,0x0c04276eu,0x0c042770u,0x0c042772u,0x0c042774u,0x0c042776u,0x0c042778u,0x0c04277au,0x0c04277cu,0x0c04277eu,0x0c042780u,0x0c042782u,0x0c042784u,0x0c042786u,
0x0c04326cu,0x0c04326eu,0x0c043270u,0x0c043272u,0x0c043274u,0x0c043276u,0x0c043278u,0x0c04327au,0x0c04327cu,0x0c04327eu,0x0c043280u,0x0c043282u,0x0c043284u,0x0c0432e2u,0x0c0432e4u,0x0c0432e6u,
0x0c0432e8u,0x0c0432eau,0x0c0432ecu,0x0c0432eeu,0x0c0432f0u,0x0c0432f2u,0x0c0432f4u,0x0c0432f6u,0x0c0432f8u,0x0c0432fau,0x0c0432fcu,0x0c0432feu,0x0c043300u,0x0c043302u,0x0c043304u,0x0c043306u,
0x0c043308u,0x0c04330au,0x0c04330cu,0x0c04330eu,0x0c043310u,0x0c043312u,0x0c043314u,0x0c043316u,0x0c043318u,0x0c04331au,0x0c04331cu,0x0c04331eu,0x0c043320u,0x0c043322u,0x0c043324u,0x0c043344u,
0x0c043346u,0x0c043348u,0x0c04334au,0x0c04334cu,0x0c04334eu,0x0c043350u,0x0c043352u,0x0c043354u,0x0c043356u,0x0c043358u,0x0c04335au,0x0c04335cu,0x0c0433aeu,0x0c0433b0u,0x0c0433b2u,0x0c0433b4u,
0x0c0433b6u,0x0c0433b8u,0x0c0433bau,0x0c0433c6u,0x0c0433c8u,0x0c0433cau,0x0c0433ccu,0x0c0433ceu,0x0c0433d0u,0x0c0433d2u,0x0c0433d4u,0x0c0433d6u,0x0c0433d8u,0x0c0433dau,0x0c0433dcu,0x0c0433deu,
0x0c0433e0u,0x0c0433e2u,0x0c0433e4u,0x0c0433e6u,0x0c0433e8u,0x0c0433eau,0x0c0433ecu,0x0c0433eeu,0x0c04340cu,0x0c04340eu,0x0c043410u,0x0c043412u,0x0c043414u,0x0c043416u,0x0c043418u,0x0c04341eu,
0x0c043420u,0x0c043422u,0x0c043424u,0x0c043426u,0x0c043428u,0x0c04342au,0x0c04342cu,0x0c04342eu,0x0c043430u,0x0c043432u,0x0c043434u,0x0c043436u,0x0c043438u,0x0c04343au,0x0c043440u,0x0c043442u,
0x0c043444u,0x0c043446u,0x0c043448u,0x0c04344au,0x0c04344cu,0x0c04344eu,0x0c043450u,0x0c043452u,0x0c043454u,0x0c043456u,0x0c043458u,0x0c04345au,0x0c04345cu,0x0c04345eu,0x0c043460u,0x0c043462u,
0x0c043464u,0x0c043466u,0x0c043468u,0x0c04346au,0x0c04346cu,0x0c043472u,0x0c043474u,0x0c043476u,0x0c043478u,0x0c04347au,0x0c04347cu,0x0c04347eu,0x0c043480u,0x0c043482u,0x0c043484u,0x0c043486u,
0x0c043488u,0x0c04348au,0x0c04348eu,0x0c043490u,0x0c043492u,0x0c043494u,0x0c043496u,0x0c043498u,0x0c04349au,0x0c04349cu,0x0c04349eu,0x0c0434a0u,0x0c0434a2u,0x0c0434a4u,0x0c0434a6u,0x0c0434aau,
0x0c0434acu,0x0c0434aeu,0x0c0434b0u,0x0c0434b2u,0x0c0434b4u,0x0c0434b6u,0x0c0434b8u,0x0c0434bau,0x0c0434bcu,0x0c0434beu,0x0c0434c0u,0x0c0434c2u,0x0c0434c4u,0x0c0434c6u,0x0c047230u,0x0c047232u,
0x0c047234u,0x0c047236u,0x0c047238u,0x0c04723au,0x0c04723cu,0x0c04723eu,0x0c047240u,0x0c047242u,0x0c047244u,0x0c047246u,0x0c047248u,0x0c04724au,0x0c04724cu,0x0c04724eu,0x0c047250u,0x0c047252u,
0x0c047254u,0x0c047256u,0x0c047258u,0x0c04725au,0x0c04725cu,0x0c04725eu,0x0c047260u,0x0c047262u,0x0c047264u,0x0c047266u,0x0c047268u,0x0c04726au,0x0c04726cu,0x0c04726eu,0x0c047270u,0x0c047272u,
0x0c047274u,0x0c047276u,0x0c047278u,0x0c04727au,0x0c04727cu,0x0c04727eu,0x0c047280u,0x0c047282u,0x0c047284u,0x0c047286u,0x0c047288u,0x0c04728au,0x0c04728cu,0x0c0482f0u,0x0c0482f2u,0x0c0482f4u,
0x0c0482f6u,0x0c0482f8u,0x0c0482fau,0x0c0482fcu,0x0c0482feu,0x0c048300u,0x0c048302u,0x0c048304u,0x0c048306u,0x0c048308u,0x0c04830au,0x0c04830cu,0x0c04830eu,0x0c048310u,0x0c048312u,0x0c048314u,
0x0c048316u,0x0c048318u,0x0c04831au,0x0c04831cu,0x0c04831eu,0x0c048320u,0x0c048322u,0x0c048324u,0x0c048326u,0x0c048328u,0x0c04832au,0x0c04832cu,0x0c04832eu,0x0c048330u,0x0c048332u,0x0c048334u,
0x0c048336u,0x0c048338u,0x0c04833au,0x0c04833cu,0x0c04833eu,0x0c048340u,0x0c048342u,0x0c048344u,0x0c048346u,0x0c048348u,0x0c04834au,0x0c04834cu,0x0c04834eu,0x0c048350u,0x0c048352u,0x0c048354u,
0x0c048356u,0x0c048358u,0x0c04835au,0x0c04835cu,0x0c04835eu,0x0c048360u,0x0c048362u,0x0c048364u,0x0c048366u,0x0c048368u,0x0c04836au,0x0c04836cu,0x0c04836eu,0x0c048370u,0x0c048372u,0x0c048374u,
0x0c048376u,0x0c048378u,0x0c04837au,0x0c04837cu,0x0c04837eu,0x0c048380u,0x0c048382u,0x0c048384u,0x0c048386u,0x0c048388u,0x0c04838au,0x0c04838cu,0x0c04838eu,0x0c048390u,0x0c048392u,0x0c048394u,
0x0c048396u,0x0c048398u,0x0c04839au,0x0c04839cu,0x0c0483a0u,0x0c0483a2u,0x0c0483a4u,0x0c0483a6u,0x0c0483a8u,0x0c0483aau,0x0c0483acu,0x0c0483aeu,0x0c0483b0u,0x0c0483b2u,0x0c0483b4u,0x0c0483b6u,
0x0c0483b8u,0x0c0483bau,0x0c0483bcu,0x0c0483beu,0x0c0483c0u,0x0c0483c2u,0x0c0483c4u,0x0c0483c6u,0x0c0483c8u,0x0c0483cau,0x0c0483ccu,0x0c0483ceu,0x0c0483d0u,0x0c0483d2u,0x0c0483d4u,0x0c0483d6u,
0x0c0483d8u,0x0c0483dau,0x0c0483dcu,0x0c0483deu,0x0c0483e0u,0x0c0483e2u,0x0c0483e4u,0x0c0483e6u,0x0c0483e8u,0x0c0483eau,0x0c0483ecu,0x0c0483eeu,0x0c0483f0u,0x0c0483f2u,0x0c0483f4u,0x0c0483f6u,
0x0c0483f8u,0x0c0483fau,0x0c0483fcu,0x0c0483feu,0x0c048400u,0x0c048402u,0x0c048404u,0x0c048408u,0x0c04840au,0x0c04840cu,0x0c04840eu,0x0c048410u,0x0c048412u,0x0c048414u,0x0c048416u,0x0c048418u,
0x0c04841au,0x0c04841cu,0x0c04841eu,0x0c048420u,0x0c048422u,0x0c048424u,0x0c048426u,0x0c048428u,0x0c04842au,0x0c04842cu,0x0c04842eu,0x0c048430u,0x0c048432u,0x0c048434u,0x0c048436u,0x0c048438u,
0x0c04843au,0x0c04843cu,0x0c04843eu,0x0c048440u,0x0c048442u,0x0c048444u,0x0c048446u,0x0c048448u,0x0c04844au,0x0c04844cu,0x0c04844eu,0x0c048450u,0x0c048452u,0x0c048454u,0x0c048456u,0x0c048458u,
0x0c04845au,0x0c04845cu,0x0c04845eu,0x0c048460u,0x0c048462u,0x0c048464u,0x0c048466u,0x0c048468u,0x0c04846au,0x0c04846cu,0x0c04846eu,0x0c048470u,0x0c048472u,0x0c048474u,0x0c048476u,0x0c048478u,
0x0c04847au,0x0c04847cu,0x0c04847eu,0x0c048480u,0x0c048482u,0x0c048484u,0x0c048486u,0x0c048488u,0x0c04848au,0x0c04848cu,0x0c04848eu,0x0c048490u,0x0c048492u,0x0c048494u,0x0c048496u,0x0c048498u,
0x0c04849au,0x0c04849cu,0x0c04849eu,0x0c0484a0u,0x0c0484a2u,0x0c0484a4u,0x0c0484a8u,0x0c0484aau,0x0c0484acu,0x0c0484aeu,0x0c0484b0u,0x0c0484b2u,0x0c0484b4u,0x0c0484b6u,0x0c0484b8u,0x0c0484bau,
0x0c0484bcu,0x0c0484beu,0x0c0484c0u,0x0c0484c4u,0x0c0484c6u,0x0c0484c8u,0x0c0484cau,0x0c0484ccu,0x0c0484ceu,0x0c0484d0u,0x0c0484d2u,0x0c0484d4u,0x0c0484d6u,0x0c0484d8u,0x0c0484dau,0x0c0484dcu,
0x0c0484deu,0x0c0484e0u,0x0c0484e2u,0x0c0484e4u,0x0c0484e6u,0x0c0484e8u,0x0c0484eau,0x0c0484ecu,0x0c0484eeu,0x0c0484f0u,0x0c0484f4u,0x0c0484f6u,0x0c0484f8u,0x0c0484fau,0x0c0484fcu,0x0c0484feu,
0x0c048500u,0x0c048502u,0x0c048504u,0x0c048506u,0x0c048508u,0x0c04850au,0x0c04850cu,0x0c04850eu,0x0c048510u,0x0c048512u,0x0c048514u,0x0c048516u,0x0c048518u,0x0c04851au,0x0c04851cu,0x0c04851eu,
0x0c048520u,0x0c048522u,0x0c048524u,0x0c048526u,0x0c048528u,0x0c04852au,0x0c04852cu,0x0c04852eu,0x0c048530u,0x0c048532u,0x0c048534u,0x0c048536u,0x0c048538u,0x0c04853au,0x0c04853cu,0x0c04853eu,
0x0c048540u,0x0c048542u,0x0c048544u,0x0c048546u,0x0c048548u,0x0c04854au,0x0c04854cu,0x0c04854eu,0x0c048550u,0x0c048552u,0x0c048554u,0x0c048556u,0x0c048558u,0x0c04855au,0x0c04855cu,0x0c04855eu,
0x0c048560u,0x0c04856cu,0x0c04856eu,0x0c048570u,0x0c048572u,0x0c048574u,0x0c048576u,0x0c048578u,0x0c04857au,0x0c04857cu,0x0c04857eu,0x0c048580u,0x0c048582u,0x0c048584u,0x0c048586u,0x0c048588u,
0x0c04858au,0x0c04858cu,0x0c04858eu,0x0c048590u,0x0c048592u,0x0c048594u,0x0c048596u,0x0c048598u,0x0c04859cu,0x0c04859eu,0x0c0485a0u,0x0c0485a2u,0x0c0485a4u,0x0c0485a6u,0x0c0485a8u,0x0c0485aau,
0x0c0485acu,0x0c0485aeu,0x0c0485b0u,0x0c0485b2u,0x0c0485b4u,0x0c0485b6u,0x0c0485b8u,0x0c0485bcu,0x0c0485beu,0x0c04c024u,0x0c04c026u,0x0c04c028u,0x0c04c02au,0x0c04c02cu,0x0c04c02eu,0x0c04c030u,
0x0c04c032u,0x0c04c034u,0x0c04c036u,0x0c04c038u,0x0c04c03au,0x0c04c03cu,0x0c04c03eu,0x0c04c040u,0x0c04c042u,0x0c04c044u,0x0c04c046u,0x0c04c048u,0x0c04c04au,0x0c04c04cu,0x0c04c04eu,0x0c04c050u,
0x0c04c052u,0x0c04c054u,0x0c04c056u,0x0c04c058u,0x0c04c05au,0x0c04c05cu,0x0c04c05eu,0x0c04c060u,0x0c04c062u,0x0c04c064u,0x0c04c066u,0x0c04c068u,0x0c04c06au,0x0c04c06cu,0x0c04c06eu,0x0c04c070u,
0x0c04c072u,0x0c04c074u,0x0c04c076u,0x0c04c078u,0x0c04c07au,0x0c04c07cu,0x0c04c07eu,0x0c04c080u,0x0c04c082u,0x0c04c084u,0x0c04c086u,0x0c04c088u,0x0c04c08au,0x0c04c08cu,0x0c04c08eu,0x0c04c090u,
0x0c04c092u,0x0c04c094u,0x0c04c096u,0x0c04c098u,0x0c04c09au,0x0c04c09cu,0x0c04c09eu,0x0c04c0a0u,0x0c04c0a2u,0x0c04c0a4u,0x0c04c0a6u,0x0c04c0a8u,0x0c04c0aau,0x0c04c0acu,0x0c04c0aeu,0x0c04c0b0u,
0x0c04c0b2u,0x0c04c0b4u,0x0c04c0b6u,0x0c04c0b8u,0x0c04c0bau,0x0c04c0bcu,0x0c04c0beu,0x0c04c0c0u,0x0c04c0c2u,0x0c04c0c4u,0x0c04c0c6u,0x0c04c0c8u,0x0c04c0cau,0x0c04c0ccu,0x0c04c0ceu,0x0c04c0d0u,
0x0c04e03eu,0x0c04e040u,0x0c04e042u,0x0c04e044u,0x0c04e046u,0x0c04e048u,0x0c04e04au,0x0c04e04cu,0x0c04e04eu,0x0c04e050u,0x0c04e052u,0x0c04e054u,0x0c04e056u,0x0c04e058u,0x0c04e05au,0x0c04e05cu,
0x0c04e05eu,0x0c04e060u,0x0c04e062u,0x0c04e064u,0x0c04e066u,0x0c04e068u,0x0c04e06au,0x0c04e06cu,0x0c04e06eu,0x0c04e070u,0x0c04e072u,0x0c04e074u,0x0c04e076u,0x0c04e078u,0x0c04e07au,0x0c04e07cu,
0x0c04e07eu,0x0c04e080u,0x0c04e082u,0x0c04e084u,0x0c04e086u,0x0c04e088u,0x0c04e08au,0x0c04e08cu,0x0c04e08eu,0x0c04e090u,0x0c04e092u,0x0c04e094u,0x0c04e096u,0x0c04e098u,0x0c04e09au,0x0c04e09cu,
0x0c04e09eu,0x0c04e0a0u,0x0c04e0a2u,0x0c04e0a4u,0x0c04e0a6u,0x0c04e0a8u,0x0c04e0aau,0x0c04e0acu,0x0c04e0aeu,0x0c04e0b0u,0x0c04e0b2u,0x0c04e0b4u,0x0c04e0b6u,0x0c04e0b8u,0x0c04e0bau,0x0c04e0bcu,
0x0c04e0beu,0x0c04e0c0u,0x0c04e0c2u,0x0c04e0c4u,0x0c04e0c6u,0x0c04e0c8u,0x0c04e0cau,0x0c04e0ccu,0x0c04e0ceu,0x0c04e0d0u,0x0c04e0d2u,0x0c04e0d4u,0x0c04e0d6u,0x0c04e0d8u,0x0c04e0dau,0x0c04e0dcu,
0x0c04e0deu,0x0c04e0e0u,0x0c04e0e2u,0x0c04e0e4u,0x0c04e0e6u,0x0c04e124u,0x0c04e126u,0x0c04e128u,0x0c04e12au,0x0c04e12cu,0x0c04e12eu,0x0c04e130u,0x0c04e132u,0x0c04e134u,0x0c04e136u,0x0c04e138u,
0x0c04e13au,0x0c04e13cu,0x0c04e13eu,0x0c04e140u,0x0c04e142u,0x0c04e144u,0x0c04e146u,0x0c04e148u,0x0c04e14au,0x0c04e14cu,0x0c04e14eu,0x0c04e150u,0x0c04e152u,0x0c04e154u,0x0c04e156u,0x0c04e158u,
0x0c04e15au,0x0c04e15cu,0x0c04e15eu,0x0c04e160u,0x0c04e162u,0x0c04e164u,0x0c04e166u,0x0c04e168u,0x0c04e16au,0x0c04e16cu,0x0c04e16eu,0x0c04e8f8u,0x0c04e8fau,0x0c04e8fcu,0x0c04e8feu,0x0c04e900u,
0x0c04e902u,0x0c04e904u,0x0c04e906u,0x0c04e908u,0x0c04e90au,0x0c04e90cu,0x0c04e90eu,0x0c04e910u,0x0c04e912u,0x0c04e914u,0x0c04e916u,0x0c04e918u,0x0c04e91au,0x0c04e91cu,0x0c04e91eu,0x0c04e920u,
0x0c04e922u,0x0c04e924u,0x0c04e926u,0x0c04e928u,0x0c04e92au,0x0c04e92cu,0x0c04e92eu,0x0c04e930u,0x0c04e932u,0x0c04e934u,0x0c04e936u,0x0c04e938u,0x0c04e93au,0x0c04e93cu,0x0c04e93eu,0x0c04e940u,
0x0c04e942u,0x0c04e944u,0x0c04e946u,0x0c04e948u,0x0c04e94au,0x0c04e94cu,0x0c04e94eu,0x0c04e950u,0x0c04e952u,0x0c04e954u,0x0c04e956u,0x0c04e958u,0x0c04e95au,0x0c04e95cu,0x0c04e95eu,0x0c04e960u,
0x0c04e962u,0x0c04e964u,0x0c04e966u,0x0c04e968u,0x0c04e96au,0x0c04e96cu,0x0c04e96eu,0x0c04e970u,0x0c04e972u,0x0c04e974u,0x0c04e976u,0x0c04e978u,0x0c04e97au,0x0c04e97cu,0x0c04e97eu,0x0c04e980u,
0x0c04e982u,0x0c04e984u,0x0c04e986u,0x0c04e988u,0x0c04e98au,0x0c04e98cu,0x0c04e98eu,0x0c04e990u,0x0c04e992u,0x0c04e994u,0x0c04e996u,0x0c04e998u,0x0c04e99au,0x0c04e99cu,0x0c04e99eu,0x0c04e9ccu,
0x0c04e9ceu,0x0c04e9d0u,0x0c04e9d2u,0x0c04e9d4u,0x0c04e9d6u,0x0c04e9d8u,0x0c04e9dau,0x0c04e9dcu,0x0c04e9deu,0x0c04e9e0u,0x0c04e9e2u,0x0c04e9e4u,0x0c04e9e6u,0x0c04e9e8u,0x0c04e9eau,0x0c04e9ecu,
0x0c04e9eeu,0x0c04e9f0u,0x0c04e9f2u,0x0c04e9f4u,0x0c04e9f6u,0x0c04e9f8u,0x0c04e9fau,0x0c04e9fcu,0x0c04e9feu,0x0c04ea00u,0x0c04ea02u,0x0c04ea04u,0x0c04ea06u,0x0c04ea08u,0x0c04ea0au,0x0c04ea0cu,
0x0c04ea0eu,0x0c04ea10u,0x0c04ea12u,0x0c04ea14u,0x0c04ea16u,0x0c04ea18u,0x0c04ea1au,0x0c04ea1cu,0x0c04ea1eu,0x0c04ea20u,0x0c04ea22u,0x0c04ea24u,0x0c04ea26u,0x0c04ea28u,0x0c04ea2au,0x0c04ea2cu,
0x0c04ea2eu,0x0c04ea30u,0x0c04ea32u,0x0c04ea34u,0x0c04ea36u,0x0c04ea38u,0x0c04ea3au,0x0c04ea3cu,0x0c04ea3eu,0x0c04ea40u,0x0c04ea42u,0x0c04fbecu,0x0c04fbeeu,0x0c04fbf0u,0x0c04fbf2u,0x0c04fbf4u,
0x0c04fbf6u,0x0c04fbf8u,0x0c04fbfau,0x0c04fbfcu,0x0c04fbfeu,0x0c04fc00u,0x0c04fc02u,0x0c04fc04u,0x0c04fc06u,0x0c04fc08u,0x0c04fc0au,0x0c04fc0cu,0x0c04fc0eu,0x0c04fc10u,0x0c04fc12u,0x0c04fc14u,
0x0c04fc16u,0x0c04fc18u,0x0c04fc1au,0x0c04fc1cu,0x0c04fc1eu,0x0c04fc20u,0x0c04fc22u,0x0c04fc24u,0x0c04fc26u,0x0c04fc28u,0x0c04fc2au,0x0c04fc2cu,0x0c04fc2eu,0x0c04fc30u,0x0c04fc32u,0x0c04fc34u,
0x0c04fc36u,0x0c04fc38u,0x0c04fc3au,0x0c04fc3cu,0x0c04fc3eu,0x0c04fc40u,0x0c04fc42u,0x0c04fc44u,0x0c04fc46u,0x0c04fc48u,0x0c04fc4au,0x0c04fc4cu,0x0c04fc4eu,0x0c04fc50u,0x0c04fc52u,0x0c04fc54u,
0x0c04fc56u,0x0c04fc58u,0x0c04fc5au,0x0c04fc5cu,0x0c04fc5eu,0x0c04fc60u,0x0c04fc62u,0x0c04fc64u,0x0c04fc66u,0x0c04fc68u,0x0c04fc6au,0x0c04fc6cu,0x0c04fc6eu,0x0c04fc70u,0x0c04fc72u,0x0c04fc74u,
0x0c04fc76u,0x0c04fc78u,0x0c04fc7au,0x0c04fc7cu,0x0c04fc7eu,0x0c04fc80u,0x0c04fc82u,0x0c04fc84u,0x0c0512dcu,0x0c0512deu,0x0c0512e0u,0x0c058348u,0x0c05834au,0x0c05834cu,0x0c05834eu,0x0c058350u,
0x0c058352u,0x0c058354u,0x0c058356u,0x0c058358u,0x0c05835au,0x0c05835cu,0x0c05835eu,0x0c058360u,0x0c058362u,0x0c058364u,0x0c058366u,0x0c058368u,0x0c05836au,0x0c05836cu,0x0c05836eu,0x0c058370u,
0x0c058372u,0x0c058374u,0x0c058376u,0x0c058378u,0x0c05837au,0x0c05837cu,0x0c05837eu,0x0c058380u,0x0c058382u,0x0c058384u,0x0c058386u,0x0c058388u,0x0c05838au,0x0c05838cu,0x0c05838eu,0x0c058390u,
0x0c058392u,0x0c058394u,0x0c058396u,0x0c058398u,0x0c05839au,0x0c05839cu,0x0c05839eu,0x0c0583a0u,0x0c0583a2u,0x0c0583a4u,0x0c0583a6u,0x0c0583a8u,0x0c0583aau,0x0c0583acu,0x0c0583aeu,0x0c0583b0u,
0x0c0583b2u,0x0c0583b4u,0x0c0583b6u,0x0c0583b8u,0x0c0583bau,0x0c0583bcu,0x0c0583beu,0x0c0583c0u,0x0c0583c2u,0x0c0583c4u,0x0c0583c6u,0x0c0583c8u,0x0c0583cau,0x0c0583ccu,0x0c0583ceu,0x0c0583d0u,
0x0c0583d2u,0x0c0583d4u,0x0c0583d6u,0x0c0583d8u,0x0c0583dau,0x0c0583dcu,0x0c0583deu,0x0c0583e0u,0x0c0583e2u,0x0c0583e4u,0x0c0583e6u,0x0c0583e8u,0x0c0583eau,0x0c0583ecu,0x0c0583eeu,0x0c0583f0u,
0x0c0583f2u,0x0c0583f4u,0x0c0583f6u,0x0c0583f8u,0x0c0583fau,0x0c0583fcu,0x0c0583feu,0x0c058400u,0x0c058402u,0x0c058404u,0x0c058406u,0x0c058408u,0x0c05840au,0x0c05840cu,0x0c05840eu,0x0c058410u,
0x0c058412u,0x0c058414u,0x0c058416u,0x0c058418u,0x0c05841au,0x0c05841cu,0x0c05841eu,0x0c058420u,0x0c058422u,0x0c058424u,0x0c058426u,0x0c058428u,0x0c05842au,0x0c05842cu,0x0c05842eu,0x0c058430u,
0x0c058432u,0x0c058434u,0x0c058436u,0x0c058438u,0x0c05843au,0x0c05843cu,0x0c05843eu,0x0c058440u,0x0c058442u,0x0c058444u,0x0c058446u,0x0c058448u,0x0c05844au,0x0c05844cu,0x0c05844eu,0x0c058450u,
0x0c058452u,0x0c058454u,0x0c058456u,0x0c058458u,0x0c05845au,0x0c05845cu,0x0c05845eu,0x0c058460u,0x0c058462u,0x0c058464u,0x0c058466u,0x0c058468u,0x0c05846au,0x0c05846cu,0x0c05846eu,0x0c058470u,
0x0c058472u,0x0c058474u,0x0c058476u,0x0c058478u,0x0c05847au,0x0c05847cu,0x0c05847eu,0x0c058480u,0x0c058482u,0x0c058484u,0x0c058486u,0x0c058488u,0x0c05848au,0x0c05848cu,0x0c05848eu,0x0c058490u,
0x0c058492u,0x0c058494u,0x0c058496u,0x0c058498u,0x0c05849au,0x0c05849cu,0x0c05849eu,0x0c0584a0u,0x0c0584a2u,0x0c0584a4u,0x0c0584a6u,0x0c0584a8u,0x0c0584aau,0x0c0584acu,0x0c0584aeu,0x0c0584b0u,
0x0c0584b2u,0x0c0584b4u,0x0c0584b6u,0x0c0584b8u,0x0c0584bau,0x0c0584bcu,0x0c0584beu,0x0c0584c0u,0x0c0584c2u,0x0c0584c4u,0x0c0584c6u,0x0c0584c8u,0x0c0584cau,0x0c0584ccu,0x0c0584ceu,0x0c0584d0u,
0x0c0584d2u,0x0c0584d4u,0x0c0584d6u,0x0c0584d8u,0x0c0584dau,0x0c0584dcu,0x0c0584deu,0x0c0584e0u,0x0c058780u,0x0c058782u,0x0c058784u,0x0c058786u,0x0c058788u,0x0c05878cu,0x0c05878eu,0x0c058790u,
0x0c058816u,0x0c058818u,0x0c05881au,0x0c05881cu,0x0c05881eu,0x0c058820u,0x0c058822u,0x0c058824u,0x0c058826u,0x0c058828u,0x0c05882au,0x0c05882cu,0x0c05882eu,0x0c058830u,0x0c058832u,0x0c058834u,
0x0c058836u,0x0c058838u,0x0c05883au,0x0c05883cu,0x0c05883eu,0x0c058840u,0x0c058842u,0x0c058844u,0x0c058846u,0x0c058848u,0x0c05884au,0x0c05884cu,0x0c05884eu,0x0c058850u,0x0c058852u,0x0c058854u,
0x0c058856u,0x0c058858u,0x0c05885au,0x0c05885cu,0x0c05885eu,0x0c058860u,0x0c058862u,0x0c058864u,0x0c058866u,0x0c058868u,0x0c05886au,0x0c05886cu,0x0c05886eu,0x0c058870u,0x0c058872u,0x0c058874u,
0x0c058876u,0x0c058878u,0x0c05887au,0x0c05887cu,0x0c05887eu,0x0c058880u,0x0c058882u,0x0c058884u,0x0c058886u,0x0c058888u,0x0c05888au,0x0c05888cu,0x0c05888eu,0x0c058890u,0x0c058892u,0x0c058894u,
0x0c058896u,0x0c058898u,0x0c05889au,0x0c05889cu,0x0c05889eu,0x0c0588a0u,0x0c0588a2u,0x0c0588a4u,0x0c0588a6u,0x0c0588a8u,0x0c0588aau,0x0c0588acu,0x0c0588aeu,0x0c0588b0u,0x0c0588b2u,0x0c0588b4u,
0x0c0588b6u,0x0c0588b8u,0x0c0588bau,0x0c0588bcu,0x0c0588beu,0x0c0588c0u,0x0c0588c2u,0x0c0588c4u,0x0c0588c6u,0x0c0588c8u,0x0c0588cau,0x0c0588ccu,0x0c0588ceu,0x0c0588d0u,0x0c0588d2u,0x0c0588d4u,
0x0c0588d6u,0x0c0588d8u,0x0c0588dau,0x0c0588dcu,0x0c0588deu,0x0c0588e0u,0x0c0588e2u,0x0c0588e4u,0x0c0588e6u,0x0c0588e8u,0x0c0588eau,0x0c0588ecu,0x0c0588eeu,0x0c0588f0u,0x0c0588f2u,0x0c0588f4u,
0x0c0588f6u,0x0c0588f8u,0x0c0588fau,0x0c0588fcu,0x0c0588feu,0x0c058900u,0x0c058902u,0x0c058904u,0x0c058906u,0x0c058908u,0x0c05890au,0x0c05890cu,0x0c05890eu,0x0c058910u,0x0c058912u,0x0c058914u,
0x0c058916u,0x0c058918u,0x0c05891au,0x0c05891cu,0x0c05891eu,0x0c058920u,0x0c058922u,0x0c058924u,0x0c058926u,0x0c058928u,0x0c05892au,0x0c05892cu,0x0c05892eu,0x0c058930u,0x0c058932u,0x0c058934u,
0x0c058936u,0x0c058938u,0x0c05893au,0x0c05893cu,0x0c05893eu,0x0c058940u,0x0c058942u,0x0c058944u,0x0c058946u,0x0c058948u,0x0c05894au,0x0c05894cu,0x0c05894eu,0x0c058950u,0x0c058952u,0x0c058954u,
0x0c058956u,0x0c058958u,0x0c05895au,0x0c05895cu,0x0c05895eu,0x0c058960u,0x0c058962u,0x0c058964u,0x0c058966u,0x0c058968u,0x0c05896au,0x0c05896cu,0x0c05896eu,0x0c058970u,0x0c058972u,0x0c058974u,
0x0c058976u,0x0c0589d0u,0x0c0589d2u,0x0c0589d4u,0x0c0589d6u,0x0c0589d8u,0x0c0589dau,0x0c0589dcu,0x0c0589deu,0x0c0589e0u,0x0c0589e2u,0x0c0589e4u,0x0c0589e6u,0x0c0589e8u,0x0c0589eau,0x0c0589ecu,
0x0c0589eeu,0x0c0589f0u,0x0c0589f2u,0x0c0589f4u,0x0c0589f6u,0x0c0589f8u,0x0c0589fau,0x0c0589fcu,0x0c0589feu,0x0c058a00u,0x0c058a02u,0x0c058a04u,0x0c058a06u,0x0c058a08u,0x0c058a0au,0x0c058a0cu,
0x0c058a0eu,0x0c058a10u,0x0c058a12u,0x0c058a14u,0x0c058a16u,0x0c058a18u,0x0c058a1au,0x0c058a1cu,0x0c058a1eu,0x0c058a20u,0x0c058a22u,0x0c058a24u,0x0c058a26u,0x0c058a28u,0x0c058a2au,0x0c058a2cu,
0x0c058a2eu,0x0c058a30u,0x0c058a32u,0x0c058a34u,0x0c058a36u,0x0c058a38u,0x0c058a3au,0x0c058a3cu,0x0c058a3eu,0x0c058a40u,0x0c058a42u,0x0c058a44u,0x0c058a46u,0x0c058a48u,0x0c058a4au,0x0c058a4cu,
0x0c058a4eu,0x0c058a50u,0x0c058a52u,0x0c058a54u,0x0c058a56u,0x0c059aeau,0x0c059aecu,0x0c059aeeu,0x0c059af0u,0x0c059af2u,0x0c059af4u,0x0c059af6u,0x0c059af8u,0x0c059afau,0x0c059afcu,0x0c059afeu,
0x0c059b00u,0x0c059b02u,0x0c059b04u,0x0c059b06u,0x0c059b08u,0x0c059b0au,0x0c059b0cu,0x0c059b40u,0x0c059b42u,0x0c059b44u,0x0c059b46u,0x0c059b48u,0x0c059b4au,0x0c059b4cu,0x0c059b4eu,0x0c059b50u,
0x0c059b52u,0x0c059b54u,0x0c059b56u,0x0c059b58u,0x0c059b5au,0x0c059b5cu,0x0c059b5eu,0x0c059b60u,0x0c059b62u,0x0c059b64u,0x0c059b66u,0x0c059b68u,0x0c059b6au,0x0c059b6cu,0x0c059b6eu,0x0c059b70u,
0x0c059b72u,0x0c059b74u,0x0c059b76u,0x0c059b78u,0x0c059b7au,0x0c059b7cu,0x0c059b7eu,0x0c059b80u,0x0c059b82u,0x0c059b84u,0x0c059b86u,0x0c059b88u,0x0c059b8au,0x0c059b8cu,0x0c059b8eu,0x0c059b90u,
0x0c059b92u,0x0c059b94u,0x0c059b96u,0x0c059b98u,0x0c059b9au,0x0c059b9cu,0x0c059b9eu,0x0c059ba0u,0x0c059ba2u,0x0c059ba4u,0x0c059ba6u,0x0c059ba8u,0x0c059baau,0x0c059bacu,0x0c059baeu,0x0c059bb0u,
0x0c059bb2u,0x0c059bb4u,0x0c059bb6u,0x0c059bb8u,0x0c059bbau,0x0c059bbcu,0x0c059bbeu,0x0c059bc0u,0x0c059bc2u,0x0c059bc4u,0x0c059bc6u,0x0c059bc8u,0x0c059bcau,0x0c059bccu,0x0c059bceu,0x0c059bd0u,
0x0c059bd2u,0x0c059bd4u,0x0c059bd6u,0x0c059bd8u,0x0c059bdau,0x0c059bdcu,0x0c059bdeu,0x0c059be0u,0x0c059be2u,0x0c059be4u,0x0c059be6u,0x0c059be8u,0x0c059beau,0x0c059becu,0x0c059beeu,0x0c059bf0u,
0x0c059bf2u,0x0c059bf4u,0x0c059bf6u,0x0c059bf8u,0x0c059bfau,0x0c059bfcu,0x0c059bfeu,0x0c059c00u,0x0c059c02u,0x0c059c04u,0x0c059c06u,0x0c059c08u,0x0c059c0au,0x0c059c0cu,0x0c059c0eu,0x0c059c10u,
0x0c059c12u,0x0c059c14u,0x0c059c16u,0x0c059c18u,0x0c059c1au,0x0c059c1cu,0x0c059c1eu,0x0c059c88u,0x0c059c8au,0x0c059c8cu,0x0c059c8eu,0x0c059c90u,0x0c059c92u,0x0c059c94u,0x0c059c96u,0x0c059c98u,
0x0c059c9au,0x0c059c9cu,0x0c059c9eu,0x0c059ca0u,0x0c059ca2u,0x0c059ca4u,0x0c059ca6u,0x0c059ca8u,0x0c059caau,0x0c059cacu,0x0c059caeu,0x0c059cb0u,0x0c059cb2u,0x0c059cb4u,0x0c059cb6u,0x0c059cb8u,
0x0c059cbau,0x0c059cbcu,0x0c059cbeu,0x0c059cc0u,0x0c059cc2u,0x0c059cc4u,0x0c059cc6u,0x0c059cc8u,0x0c059ccau,0x0c059cccu,0x0c059cceu,0x0c059cd0u,0x0c059cd2u,0x0c059cd4u,0x0c059cd6u,0x0c059cd8u,
0x0c059cdau,0x0c059cdcu,0x0c059cdeu,0x0c059ce0u,0x0c059ce2u,0x0c059ce4u,0x0c059ce6u,0x0c059ce8u,0x0c059ceau,0x0c059cecu,0x0c059ceeu,0x0c059cf0u,0x0c059cf2u,0x0c059cf4u,0x0c059cf6u,0x0c059cf8u,
0x0c059cfau,0x0c059cfcu,0x0c059cfeu,0x0c059d00u,0x0c059d02u,0x0c059d04u,0x0c059d06u,0x0c059d08u,0x0c059d0au,0x0c059d0cu,0x0c059d0eu,0x0c059d10u,0x0c059d12u,0x0c059d14u,0x0c059d16u,0x0c059d18u,
0x0c059d1au,0x0c059d1cu,0x0c059d1eu,0x0c059d20u,0x0c059d22u,0x0c059d24u,0x0c059d26u,0x0c059d28u,0x0c059d2au,0x0c059d2cu,0x0c059d2eu,0x0c059d30u,0x0c059d32u,0x0c059d34u,0x0c059d36u,0x0c059d38u,
0x0c059d3au,0x0c059d3cu,0x0c059d3eu,0x0c059d40u,0x0c059d42u,0x0c059d44u,0x0c059d46u,0x0c059d48u,0x0c059d4au,0x0c059d4cu,0x0c059d4eu,0x0c059d50u,0x0c059d52u,0x0c059d54u,0x0c059d56u,0x0c059d58u,
0x0c059d5au,0x0c059d5cu,0x0c059d5eu,0x0c059d60u,0x0c059d62u,0x0c059d64u,0x0c059d66u,0x0c059d68u,0x0c059d6au,0x0c059d6cu,0x0c059d6eu,0x0c059d70u,0x0c05e12eu,0x0c05e130u,0x0c05e132u,0x0c05e134u,
0x0c05e136u,0x0c05e138u,0x0c05e13au,0x0c05e13cu,0x0c05e13eu,0x0c05e140u,0x0c05e142u,0x0c05e144u,0x0c05e146u,0x0c05e148u,0x0c05e14au,0x0c05e14cu,0x0c05e14eu,0x0c05e150u,0x0c05e152u,0x0c05e154u,
0x0c05e156u,0x0c05e158u,0x0c05e15au,0x0c05e15cu,0x0c05e15eu,0x0c05e160u,0x0c05e162u,0x0c05e164u,0x0c05e166u,0x0c05e168u,0x0c05e16au,0x0c05e16cu,0x0c05e16eu,0x0c05e170u,0x0c05e172u,0x0c05e174u,
0x0c05e176u,0x0c05e178u,0x0c05e17au,0x0c05e17cu,0x0c060ebau,0x0c060ebcu,0x0c060ebeu,0x0c060ec0u,0x0c060ec2u,0x0c060ec4u,0x0c060ec6u,0x0c060ec8u,0x0c060ecau,0x0c060eccu,0x0c060eceu,0x0c060ed0u,
0x0c060ed2u,0x0c060ed4u,0x0c060ed6u,0x0c060ed8u,0x0c060edau,0x0c060edcu,0x0c060edeu,0x0c060ee0u,0x0c060ee2u,0x0c060ee4u,0x0c060ee6u,0x0c060ee8u,0x0c060eeau,0x0c060eecu,0x0c060eeeu,0x0c060ef0u,
0x0c060ef2u,0x0c063446u,0x0c063448u,0x0c06344au,0x0c06344cu,0x0c06344eu,0x0c063450u,0x0c063452u,0x0c063454u,0x0c063456u,0x0c063458u,0x0c06345au,0x0c06345cu,0x0c06345eu,0x0c063460u,0x0c063462u,
0x0c063464u,0x0c063466u,0x0c063468u,0x0c06346au,0x0c06346cu,0x0c06346eu,0x0c063470u,0x0c063472u,0x0c063474u,0x0c063476u,0x0c063478u,0x0c06347au,0x0c06347cu,0x0c06347eu,0x0c063480u,0x0c063482u,
0x0c063484u,0x0c063486u,0x0c063488u,0x0c06348au,0x0c06348cu,0x0c06348eu,0x0c063490u,0x0c063492u,0x0c063494u,0x0c063496u,0x0c063498u,0x0c06349au,0x0c06349cu,0x0c06349eu,0x0c0634a0u,0x0c0634a2u,
0x0c0634a4u,0x0c0634a6u,0x0c0634a8u,0x0c0634aau,0x0c0634acu,0x0c0634aeu,0x0c0634b0u,0x0c0634b2u,0x0c0634b4u,0x0c0634b6u,0x0c0634b8u,0x0c0634bau,0x0c0634bcu,0x0c0634beu,0x0c0634c0u,0x0c0634c2u,
0x0c0634c4u,0x0c0634c6u,0x0c0634c8u,0x0c0634cau,0x0c0634ccu,0x0c0634ceu,0x0c0634d0u,0x0c0634d2u,0x0c0634d4u,0x0c0634d6u,0x0c0634d8u,0x0c0634dau,0x0c0634dcu,0x0c0634deu,0x0c0634e0u,0x0c0634e2u,
0x0c0634e4u,0x0c0634e6u,0x0c0634e8u,0x0c0634eau,0x0c0634ecu,0x0c06351cu,0x0c06351eu,0x0c063520u,0x0c063522u,0x0c063524u,0x0c063526u,0x0c063528u,0x0c06352au,0x0c06352cu,0x0c06352eu,0x0c063530u,
0x0c063532u,0x0c063534u,0x0c063536u,0x0c063538u,0x0c06353au,0x0c06353cu,0x0c06353eu,0x0c063540u,0x0c063542u,0x0c063544u,0x0c063546u,0x0c063548u,0x0c06354au,0x0c06354cu,0x0c06354eu,0x0c063550u,
0x0c063552u,0x0c063554u,0x0c063556u,0x0c063558u,0x0c06355au,0x0c06355cu,0x0c06355eu,0x0c063560u,0x0c063562u,0x0c063564u,0x0c063566u,0x0c063568u,0x0c06356au,0x0c06356cu,0x0c06356eu,0x0c063570u,
0x0c063572u,0x0c063574u,0x0c063576u,0x0c063578u,0x0c06357au,0x0c06357cu,0x0c06357eu,0x0c063580u,0x0c063582u,0x0c063584u,0x0c063586u,0x0c063588u,0x0c06358au,0x0c06358cu,0x0c06358eu,0x0c063590u,
0x0c063592u,0x0c063594u,0x0c063596u,0x0c063598u,0x0c06359au,0x0c06359cu,0x0c06359eu,0x0c0635a0u,0x0c0635a2u,0x0c0635a4u,0x0c0635a6u,0x0c0635a8u,0x0c0635aau,0x0c0635acu,0x0c0635aeu,0x0c0635b0u,
0x0c0635b2u,0x0c0635b4u,0x0c0635b6u,0x0c0635b8u,0x0c0635bau,0x0c0635bcu,0x0c0635beu,0x0c0635c0u,0x0c0635c2u,0x0c0635c4u,0x0c0635c6u,0x0c0635c8u,0x0c0635cau,0x0c0635ccu,0x0c0635ceu,0x0c0635d0u,
0x0c0635d2u,0x0c0635d4u,0x0c0635d6u,0x0c0635d8u,0x0c0635dau,0x0c0635dcu,0x0c0635deu,0x0c0635e0u,0x0c0635e2u,0x0c0635e4u,0x0c0635e6u,0x0c0635e8u,0x0c0635eau,0x0c0635ecu,0x0c0635eeu,0x0c0635f0u,
0x0c0635f2u,0x0c0635f4u,0x0c0635f6u,0x0c0635f8u,0x0c0635fau,0x0c0635fcu,0x0c0635feu,0x0c063600u,0x0c063602u,0x0c063604u,0x0c063606u,0x0c063608u,0x0c06360au,0x0c06360cu,0x0c06360eu,0x0c063610u,
0x0c063612u,0x0c063614u,0x0c063680u,0x0c063682u,0x0c063684u,0x0c063686u,0x0c063688u,0x0c06368au,0x0c06368cu,0x0c06368eu,0x0c063690u,0x0c063692u,0x0c063694u,0x0c063696u,0x0c063698u,0x0c06369au,
0x0c06369cu,0x0c06369eu,0x0c06371cu,0x0c06371eu,0x0c063720u,0x0c063722u,0x0c063724u,0x0c063726u,0x0c063728u,0x0c06372au,0x0c06372cu,0x0c06372eu,0x0c063730u,0x0c063732u,0x0c063734u,0x0c063736u,
0x0c063738u,0x0c06373au,0x0c06373cu,0x0c06373eu,0x0c063740u,0x0c063742u,0x0c063744u,0x0c063746u,0x0c063748u,0x0c06374au,0x0c06374cu,0x0c06374eu,0x0c063750u,0x0c063752u,0x0c063754u,0x0c063756u,
0x0c063758u,0x0c06375au,0x0c06375cu,0x0c06375eu,0x0c063760u,0x0c063762u,0x0c063764u,0x0c063766u,0x0c063768u,0x0c06376au,0x0c0734feu,0x0c073500u,0x0c073502u,0x0c073504u,0x0c073506u,0x0c073508u,
0x0c07350au,0x0c07350cu,0x0c07350eu,0x0c073510u,0x0c073512u,0x0c073514u,0x0c073516u,0x0c073518u,0x0c07351au,0x0c07351cu,0x0c07351eu,0x0c073520u,0x0c073522u,0x0c073524u,0x0c073526u,0x0c073528u,
0x0c07352au,0x0c07352cu,0x0c07352eu,0x0c073530u,0x0c073532u,0x0c073534u,0x0c073536u,0x0c073538u,0x0c07353au,0x0c07353cu,0x0c07353eu,0x0c073540u,0x0c09457eu,0x0c094580u,0x0c094582u,0x0c094584u,
0x0c094586u,0x0c094588u,0x0c09458au,0x0c09458cu,0x0c09458eu,0x0c094590u,0x0c094592u,0x0c094594u,0x0c094596u,0x0c094598u,0x0c09459au,0x0c09459cu,0x0c09459eu,0x0c0945a0u,0x0c0945a2u,0x0c0945a4u,
0x0c0945a6u,0x0c0945a8u,0x0c0945aau,0x0c0945acu,0x0c0945aeu,0x0c0945b0u,0x0c0945b2u,0x0c0945b4u,0x0c0945b6u,0x0c0945b8u,0x0c0945bau,0x0c0945bcu,0x0c0945beu,0x0c0945c0u,0x0c0945c2u,0x0c0945c4u,
0x0c0945c6u,0x0c0945c8u,0x0c0945cau,0x0c0945ccu,0x0c0945ceu,0x0c0945d0u,0x0c0945d2u,0x0c0945d4u,0x0c0945d6u,0x0c0945d8u,0x0c0945dau,0x0c0945dcu,0x0c0945deu,0x0c0945e0u,0x0c0945e2u,0x0c0945e4u,
0x0c0945e6u,0x0c0945e8u,0x0c0945eau,0x0c0945ecu,0x0c0945eeu,0x0c0945f0u,0x0c097ff4u,0x0c097ff6u,0x0c097ff8u,0x0c097ffau,0x0c097ffcu,0x0c097ffeu,0x0c098000u,0x0c098002u,0x0c098004u,0x0c098006u,
0x0c098008u,0x0c09800au,0x0c09800cu,0x0c09800eu,0x0c098010u,0x0c098012u,0x0c098014u,0x0c098016u,0x0c098018u,0x0c09801au,0x0c09801cu,0x0c09801eu,0x0c098020u,0x0c098022u,0x0c098024u,0x0c098026u,
0x0c098028u,0x0c09802au,0x0c09802cu,0x0c09802eu,0x0c098030u,0x0c098032u,0x0c098034u,0x0c098036u,0x0c098038u,0x0c09803au,0x0c09803cu,0x0c09803eu,0x0c0983c6u,0x0c0983c8u,0x0c0983cau,0x0c0983ccu,
0x0c0983ceu,0x0c0983d0u,0x0c0983d2u,0x0c0983d4u,0x0c0983d6u,0x0c0983d8u,0x0c0983dau,0x0c0983dcu,0x0c0983deu,0x0c0983e0u,0x0c0983e2u,0x0c0983e4u,0x0c0983e6u,0x0c0983e8u,0x0c0983eau,0x0c0983ecu,
0x0c0983eeu,0x0c0983f0u,0x0c0983f2u,0x0c0983f4u,0x0c0983f6u,0x0c0983f8u,0x0c0983fau,0x0c0983fcu,0x0c0983feu,0x0c098400u,0x0c098402u,0x0c098404u,0x0c098406u,0x0c098408u,0x0c09840au,0x0c09840cu,
0x0c09840eu,0x0c098410u,0x0c098412u,0x0c098414u,0x0c098416u,0x0c098418u,0x0c09841au,0x0c09841cu,0x0c09841eu,0x0c098420u,0x0c098422u,0x0c098424u,0x0c098426u,0x0c098428u,0x0c09842au,0x0c09842cu,
0x0c09842eu,0x0c098430u,0x0c098432u,0x0c09aa14u,0x0c09aa16u,0x0c09aa18u,0x0c09aa1au,0x0c09aa1cu,0x0c09aa1eu,0x0c09aa20u,0x0c09aa22u,0x0c09aa24u,0x0c09aa26u,0x0c09aa28u,0x0c09aa2au,0x0c09aa2cu,
0x0c09aa2eu,0x0c09aa30u,0x0c09aa32u,0x0c09aa34u,0x0c09aa36u,0x0c09aa38u,0x0c09aa3au,0x0c09aa3cu,0x0c09aa3eu,0x0c09aa40u,0x0c09aa42u,0x0c09aa44u,0x0c09aa46u,0x0c09aa48u,0x0c09aa4au,0x0c09aa4cu,
0x0c09aa4eu,0x0c09aa50u,0x0c09aa52u,0x0c09aa54u,0x0c09aa56u,0x0c09aa58u,0x0c09aa5au,0x0c09aa5cu,0x0c09aa5eu,0x0c09aa60u,0x0c09aa62u,0x0c09aa64u,0x0c09aa66u,0x0c09aa68u,0x0c09aa6au,0x0c09aa6cu,
0x0c09aa6eu,0x0c09aa70u,0x0c09aa72u,0x0c09aa74u,0x0c09aa76u,0x0c09aa78u,0x0c09aa7au,0x0c09aa7cu,0x0c09aa7eu,0x0c09aa80u,0x0c09aa82u,0x0c09aa84u,0x0c09aa86u,0x0c09aa88u,0x0c09aa8au,0x0c09aa8cu,
0x0c09aa8eu,0x0c09aa90u,0x0c09aa92u,0x0c09aa94u,0x0c09aa96u,0x0c09aa98u,0x0c09aa9au,0x0c09aa9cu,0x0c09aa9eu,0x0c09aaa0u,0x0c09aaa2u,0x0c09aaa4u,0x0c09aaa6u,0x0c09aaa8u,0x0c09aaaau,0x0c09aaacu,
0x0c09aaaeu,0x0c09aab0u,0x0c09aab2u,0x0c09aab4u,0x0c09aab6u,0x0c09aab8u,0x0c09aabau,0x0c09aabcu,0x0c09aabeu,0x0c09aac0u,0x0c09aac2u,0x0c09aac4u,0x0c09aac6u,0x0c09aac8u,0x0c09aacau,0x0c09aaccu,
0x0c09aaceu,0x0c09aad0u,0x0c09aad2u,0x0c09aad4u,0x0c09aad6u,0x0c09aad8u,0x0c09aadau,0x0c09aadcu,0x0c09aadeu,0x0c09aae0u,0x0c09aae2u,0x0c09aae4u,0x0c09aae6u,0x0c09aae8u,0x0c09aaeau,0x0c09aaecu,
0x0c09aaeeu,0x0c09aaf0u,0x0c09aaf2u,0x0c09aaf4u,0x0c09aaf6u,0x0c09aaf8u,0x0c09aafau,0x0c09aafcu,0x0c09aafeu,0x0c09ab00u,0x0c09ab02u,0x0c09ab04u,0x0c09ab06u,0x0c09ab08u,0x0c09ab0au,0x0c09ab0cu,
0x0c09ab0eu,0x0c09ab10u,0x0c09ab12u,0x0c09ab14u,0x0c09ab16u,0x0c09ab18u,0x0c09ab1au,0x0c09ab1cu,0x0c09ab1eu,0x0c09ab20u,0x0c09ab22u,0x0c09ab24u,0x0c09ab26u,0x0c09ab28u,0x0c09ab2au,0x0c09ab2cu,
0x0c09ab2eu,0x0c09ab30u,0x0c09ab32u,0x0c09ab34u,0x0c09ab36u,0x0c09ab38u,0x0c09ab3au,0x0c09ab3cu,0x0c09ab3eu,0x0c09ab40u,0x0c09ab42u,0x0c09ab44u,0x0c09ab46u,0x0c09ab48u,0x0c09ab4au,0x0c09ab4cu,
0x0c09ab4eu,0x0c09ab50u,0x0c09ab52u,0x0c09ab54u,0x0c09ab56u,0x0c09ab58u,0x0c09ab5au,0x0c09ab5cu,0x0c09ab5eu,0x0c09ab60u,0x0c09ab62u,0x0c0a1294u,0x0c0a1296u,0x0c0a1298u,0x0c0a129au,0x0c0a129cu,
0x0c0a129eu,0x0c0a12a0u,0x0c0a12a2u,0x0c0a12a4u,0x0c0a12a6u,0x0c0a12a8u,0x0c0a12aau,0x0c0a12acu,0x0c0a12aeu,0x0c0a12b0u,0x0c0a12b2u,0x0c0a12b4u,0x0c0a12b6u,0x0c0a12b8u,0x0c0a12bau,0x0c0a12bcu,
0x0c0a12beu,0x0c0a12c0u,0x0c0a2a84u,0x0c0a2a86u,0x0c0a2a88u,0x0c0a2a8au,0x0c0a2a8cu,0x0c0a2a8eu,0x0c0a2a90u,0x0c0a2a92u,0x0c0a2a94u,0x0c0a2a96u,0x0c0a2a98u,0x0c0a2a9au,0x0c0a2a9cu,0x0c0a2a9eu,
0x0c0a2aa0u,0x0c0a2aa2u,0x0c0a2aa4u,0x0c0a2aa6u,0x0c0a2aa8u,0x0c0a2aaau,0x0c0a2aacu,0x0c0a2aaeu,0x0c0a2ab0u,0x0c0a2ab2u,0x0c0a2ab4u,0x0c0a2ab6u,0x0c0a2ab8u,0x0c0a2abau,0x0c0a2abcu,0x0c0a2abeu,
0x0c0a2ac0u,0x0c0a2ac2u,0x0c0a2ac4u,0x0c0a2ac6u,0x0c0a2ac8u,0x0c0a2acau,0x0c0a2accu,0x0c0a2aceu,0x0c0a2ad0u,0x0c0a2ad2u,0x0c0a2ad4u,0x0c0a2ad6u,0x0c0a2ad8u,0x0c0a2adau,0x0c0a2adcu,0x0c0a2adeu,
0x0c0a2ae0u,0x0c0a2ae2u,0x0c0a2ae4u,0x0c0a2ae6u,0x0c0a2ae8u,0x0c0a2aeau,0x0c0a2aecu,0x0c0a2aeeu,0x0c0a2af0u,0x0c0a2af2u,0x0c0a2af4u,0x0c0a2af6u,0x0c0a2af8u,0x0c0a2afau,0x0c0a2afcu,0x0c0a2afeu,
0x0c0a2b00u,0x0c0a2b02u,0x0c0a2b04u,0x0c0a2b06u,0x0c0a2b08u,0x0c0a2b0au,0x0c0a2b0cu,0x0c0a2b0eu,0x0c0a2b10u,0x0c0a2b12u,0x0c0a2b14u,0x0c0a2b16u,0x0c0a2b18u,0x0c0a2b1au,0x0c0a2b1cu,0x0c0a2b1eu,
0x0c0a2b20u,0x0c0a2b22u,0x0c0a2b24u,0x0c0a2b26u,0x0c0a2b28u,0x0c0a2b2au,0x0c0a2b2cu,0x0c0a2b2eu,0x0c0a2b30u,0x0c0a2b32u,0x0c0a2b34u,0x0c0a2b36u,0x0c0a2b38u,0x0c0a2b3au,0x0c0a2b3cu,0x0c0a2b3eu,
0x0c0a2b40u,0x0c0a2b42u,0x0c0a2b44u,0x0c0a2b46u,0x0c0a2b48u,0x0c0a2b4au,0x0c0a2b4cu,0x0c0a2b4eu,0x0c0a2b50u,0x0c0a2b52u,0x0c0a2b54u,0x0c0a2b56u,0x0c0a2b58u,0x0c0a2b5au,0x0c0a2b5cu,0x0c0a2b5eu,
0x0c0a2b60u,0x0c0a2b62u,0x0c0a2b64u,0x0c0a2b66u,0x0c0a2b68u,0x0c0a2b6au,0x0c0a2b6cu,0x0c0a2b6eu,0x0c0a2b70u,0x0c0a2b72u,0x0c0a2b74u,0x0c0a2b76u,0x0c0a2b78u,0x0c0a2b7au,
};
static const uint32_t claim_pcs[]={
0x0c035270u,0x0c035306u,0x0c035370u,0x0c0354a4u,0x0c035518u,0x0c03746au,0x0c0377a8u,0x0c03780cu,0x0c03bbd2u,0x0c042672u,0x0c04326cu,0x0c0432e2u,0x0c0433c6u,0x0c0433e0u,0x0c04340cu,0x0c04341eu,
0x0c043440u,0x0c04345eu,0x0c043472u,0x0c04348eu,0x0c0434aau,0x0c047230u,0x0c04853au,0x0c04c024u,0x0c04e03eu,0x0c04e8f8u,0x0c04fbecu,0x0c0512dcu,0x0c058348u,0x0c058780u,0x0c058784u,0x0c058788u,
0x0c05878cu,0x0c059aeau,0x0c05e12eu,0x0c060ebau,0x0c063446u,0x0c0635ecu,0x0c06371cu,0x0c0734feu,0x0c09457eu,0x0c0983c6u,0x0c09aa14u,0x0c0a1294u,0x0c0a2a84u,
};
int vf3_c95_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
