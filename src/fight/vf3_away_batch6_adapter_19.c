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
int vf3_away_batch6_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c053308u: goto P_0c053308;
case 0x0c05330au: goto P_0c05330a;
case 0x0c05330cu: goto P_0c05330c;
case 0x0c05330eu: goto P_0c05330e;
case 0x0c053310u: goto P_0c053310;
case 0x0c053312u: goto P_0c053312;
case 0x0c053314u: goto P_0c053314;
case 0x0c053316u: goto P_0c053316;
case 0x0c053318u: goto P_0c053318;
case 0x0c05331au: goto P_0c05331a;
case 0x0c05331cu: goto P_0c05331c;
case 0x0c05331eu: goto P_0c05331e;
case 0x0c053320u: goto P_0c053320;
case 0x0c053322u: goto P_0c053322;
case 0x0c053324u: goto P_0c053324;
case 0x0c053326u: goto P_0c053326;
case 0x0c053328u: goto P_0c053328;
case 0x0c05332au: goto P_0c05332a;
case 0x0c05332cu: goto P_0c05332c;
case 0x0c05332eu: goto P_0c05332e;
case 0x0c053330u: goto P_0c053330;
case 0x0c053332u: goto P_0c053332;
case 0x0c053334u: goto P_0c053334;
case 0x0c053336u: goto P_0c053336;
case 0x0c053338u: goto P_0c053338;
case 0x0c05333au: goto P_0c05333a;
case 0x0c05333cu: goto P_0c05333c;
case 0x0c05333eu: goto P_0c05333e;
case 0x0c053340u: goto P_0c053340;
case 0x0c053342u: goto P_0c053342;
case 0x0c053344u: goto P_0c053344;
case 0x0c053346u: goto P_0c053346;
case 0x0c053348u: goto P_0c053348;
case 0x0c05334au: goto P_0c05334a;
case 0x0c05334cu: goto P_0c05334c;
case 0x0c05334eu: goto P_0c05334e;
case 0x0c053350u: goto P_0c053350;
case 0x0c053352u: goto P_0c053352;
case 0x0c053354u: goto P_0c053354;
case 0x0c053356u: goto P_0c053356;
case 0x0c053358u: goto P_0c053358;
case 0x0c05335au: goto P_0c05335a;
case 0x0c05335cu: goto P_0c05335c;
case 0x0c05335eu: goto P_0c05335e;
case 0x0c053360u: goto P_0c053360;
case 0x0c053362u: goto P_0c053362;
case 0x0c053364u: goto P_0c053364;
case 0x0c053366u: goto P_0c053366;
case 0x0c053368u: goto P_0c053368;
case 0x0c05336au: goto P_0c05336a;
case 0x0c05336cu: goto P_0c05336c;
case 0x0c05336eu: goto P_0c05336e;
case 0x0c053370u: goto P_0c053370;
case 0x0c053372u: goto P_0c053372;
case 0x0c053374u: goto P_0c053374;
case 0x0c053376u: goto P_0c053376;
case 0x0c053378u: goto P_0c053378;
case 0x0c05337au: goto P_0c05337a;
case 0x0c05337cu: goto P_0c05337c;
case 0x0c05337eu: goto P_0c05337e;
case 0x0c053380u: goto P_0c053380;
case 0x0c053382u: goto P_0c053382;
case 0x0c053384u: goto P_0c053384;
case 0x0c053386u: goto P_0c053386;
case 0x0c053388u: goto P_0c053388;
case 0x0c05338au: goto P_0c05338a;
case 0x0c05338cu: goto P_0c05338c;
case 0x0c05338eu: goto P_0c05338e;
case 0x0c053390u: goto P_0c053390;
case 0x0c053392u: goto P_0c053392;
case 0x0c053450u: goto P_0c053450;
case 0x0c053452u: goto P_0c053452;
case 0x0c053454u: goto P_0c053454;
case 0x0c053456u: goto P_0c053456;
case 0x0c053458u: goto P_0c053458;
case 0x0c05345au: goto P_0c05345a;
case 0x0c05345cu: goto P_0c05345c;
case 0x0c05345eu: goto P_0c05345e;
case 0x0c053460u: goto P_0c053460;
case 0x0c053462u: goto P_0c053462;
case 0x0c053464u: goto P_0c053464;
case 0x0c053466u: goto P_0c053466;
case 0x0c053468u: goto P_0c053468;
case 0x0c05346au: goto P_0c05346a;
case 0x0c05346cu: goto P_0c05346c;
case 0x0c05346eu: goto P_0c05346e;
case 0x0c053470u: goto P_0c053470;
case 0x0c053472u: goto P_0c053472;
case 0x0c053474u: goto P_0c053474;
case 0x0c053476u: goto P_0c053476;
case 0x0c053478u: goto P_0c053478;
case 0x0c05347au: goto P_0c05347a;
case 0x0c05347cu: goto P_0c05347c;
case 0x0c05347eu: goto P_0c05347e;
case 0x0c053480u: goto P_0c053480;
case 0x0c053482u: goto P_0c053482;
case 0x0c053484u: goto P_0c053484;
case 0x0c053486u: goto P_0c053486;
case 0x0c053488u: goto P_0c053488;
case 0x0c05348au: goto P_0c05348a;
case 0x0c05348cu: goto P_0c05348c;
case 0x0c05348eu: goto P_0c05348e;
case 0x0c053490u: goto P_0c053490;
case 0x0c053492u: goto P_0c053492;
case 0x0c053494u: goto P_0c053494;
case 0x0c053496u: goto P_0c053496;
case 0x0c053498u: goto P_0c053498;
case 0x0c05349au: goto P_0c05349a;
case 0x0c05349cu: goto P_0c05349c;
case 0x0c05349eu: goto P_0c05349e;
case 0x0c0534a0u: goto P_0c0534a0;
case 0x0c0534a2u: goto P_0c0534a2;
case 0x0c0534a4u: goto P_0c0534a4;
case 0x0c0534a6u: goto P_0c0534a6;
case 0x0c0534a8u: goto P_0c0534a8;
case 0x0c0534aau: goto P_0c0534aa;
case 0x0c0534acu: goto P_0c0534ac;
case 0x0c0534aeu: goto P_0c0534ae;
case 0x0c0534b0u: goto P_0c0534b0;
case 0x0c0534b2u: goto P_0c0534b2;
case 0x0c0534b4u: goto P_0c0534b4;
case 0x0c0534b6u: goto P_0c0534b6;
case 0x0c0534b8u: goto P_0c0534b8;
case 0x0c0534bau: goto P_0c0534ba;
case 0x0c0534bcu: goto P_0c0534bc;
case 0x0c0534beu: goto P_0c0534be;
case 0x0c0534c0u: goto P_0c0534c0;
case 0x0c0534c2u: goto P_0c0534c2;
case 0x0c0534c4u: goto P_0c0534c4;
case 0x0c0534c6u: goto P_0c0534c6;
case 0x0c0534c8u: goto P_0c0534c8;
case 0x0c0534cau: goto P_0c0534ca;
case 0x0c0534ccu: goto P_0c0534cc;
case 0x0c0534ceu: goto P_0c0534ce;
case 0x0c0534d0u: goto P_0c0534d0;
case 0x0c0534d2u: goto P_0c0534d2;
case 0x0c0534d4u: goto P_0c0534d4;
case 0x0c0534d6u: goto P_0c0534d6;
case 0x0c0534d8u: goto P_0c0534d8;
case 0x0c0534dau: goto P_0c0534da;
case 0x0c0534dcu: goto P_0c0534dc;
case 0x0c0534deu: goto P_0c0534de;
case 0x0c0534e0u: goto P_0c0534e0;
case 0x0c0534e2u: goto P_0c0534e2;
case 0x0c0534e4u: goto P_0c0534e4;
case 0x0c0534e6u: goto P_0c0534e6;
case 0x0c0534e8u: goto P_0c0534e8;
case 0x0c0534eau: goto P_0c0534ea;
case 0x0c0534ecu: goto P_0c0534ec;
case 0x0c0534eeu: goto P_0c0534ee;
case 0x0c0534f0u: goto P_0c0534f0;
case 0x0c0534f2u: goto P_0c0534f2;
case 0x0c0534f4u: goto P_0c0534f4;
case 0x0c0534f6u: goto P_0c0534f6;
case 0x0c0534f8u: goto P_0c0534f8;
case 0x0c0534fau: goto P_0c0534fa;
case 0x0c0534fcu: goto P_0c0534fc;
case 0x0c0534feu: goto P_0c0534fe;
case 0x0c053500u: goto P_0c053500;
case 0x0c053502u: goto P_0c053502;
case 0x0c053504u: goto P_0c053504;
case 0x0c053506u: goto P_0c053506;
case 0x0c053508u: goto P_0c053508;
case 0x0c05350au: goto P_0c05350a;
case 0x0c05350cu: goto P_0c05350c;
case 0x0c05350eu: goto P_0c05350e;
case 0x0c053510u: goto P_0c053510;
case 0x0c053512u: goto P_0c053512;
case 0x0c053514u: goto P_0c053514;
case 0x0c053516u: goto P_0c053516;
case 0x0c053518u: goto P_0c053518;
case 0x0c05351au: goto P_0c05351a;
case 0x0c05351cu: goto P_0c05351c;
case 0x0c05351eu: goto P_0c05351e;
case 0x0c053520u: goto P_0c053520;
case 0x0c053522u: goto P_0c053522;
case 0x0c053524u: goto P_0c053524;
case 0x0c053526u: goto P_0c053526;
case 0x0c053528u: goto P_0c053528;
case 0x0c05352au: goto P_0c05352a;
case 0x0c05352cu: goto P_0c05352c;
case 0x0c05356cu: goto P_0c05356c;
case 0x0c05356eu: goto P_0c05356e;
case 0x0c053570u: goto P_0c053570;
case 0x0c053572u: goto P_0c053572;
case 0x0c053574u: goto P_0c053574;
case 0x0c053576u: goto P_0c053576;
case 0x0c053578u: goto P_0c053578;
case 0x0c05357au: goto P_0c05357a;
case 0x0c05357cu: goto P_0c05357c;
case 0x0c05357eu: goto P_0c05357e;
case 0x0c053580u: goto P_0c053580;
case 0x0c053582u: goto P_0c053582;
case 0x0c053584u: goto P_0c053584;
case 0x0c053586u: goto P_0c053586;
case 0x0c053588u: goto P_0c053588;
case 0x0c05358au: goto P_0c05358a;
case 0x0c05358cu: goto P_0c05358c;
case 0x0c05358eu: goto P_0c05358e;
case 0x0c053590u: goto P_0c053590;
case 0x0c053592u: goto P_0c053592;
case 0x0c053594u: goto P_0c053594;
case 0x0c053596u: goto P_0c053596;
case 0x0c053598u: goto P_0c053598;
case 0x0c05359au: goto P_0c05359a;
case 0x0c05359cu: goto P_0c05359c;
case 0x0c05359eu: goto P_0c05359e;
case 0x0c0535a0u: goto P_0c0535a0;
case 0x0c0535a2u: goto P_0c0535a2;
case 0x0c0535a4u: goto P_0c0535a4;
case 0x0c0535a6u: goto P_0c0535a6;
case 0x0c0535a8u: goto P_0c0535a8;
case 0x0c0535aau: goto P_0c0535aa;
case 0x0c0535acu: goto P_0c0535ac;
case 0x0c0535aeu: goto P_0c0535ae;
case 0x0c0535b0u: goto P_0c0535b0;
case 0x0c0535b2u: goto P_0c0535b2;
case 0x0c0535b4u: goto P_0c0535b4;
case 0x0c0535b6u: goto P_0c0535b6;
case 0x0c0535b8u: goto P_0c0535b8;
case 0x0c0535bau: goto P_0c0535ba;
case 0x0c0535bcu: goto P_0c0535bc;
case 0x0c0535beu: goto P_0c0535be;
case 0x0c0535c0u: goto P_0c0535c0;
case 0x0c0535c2u: goto P_0c0535c2;
case 0x0c0535c4u: goto P_0c0535c4;
case 0x0c0535c6u: goto P_0c0535c6;
case 0x0c0535c8u: goto P_0c0535c8;
case 0x0c0535cau: goto P_0c0535ca;
case 0x0c0535ccu: goto P_0c0535cc;
case 0x0c0535ceu: goto P_0c0535ce;
case 0x0c0535d0u: goto P_0c0535d0;
case 0x0c0535d2u: goto P_0c0535d2;
case 0x0c0535d4u: goto P_0c0535d4;
case 0x0c0535d6u: goto P_0c0535d6;
case 0x0c0535d8u: goto P_0c0535d8;
case 0x0c0535dau: goto P_0c0535da;
case 0x0c0535dcu: goto P_0c0535dc;
case 0x0c0535deu: goto P_0c0535de;
case 0x0c0535e0u: goto P_0c0535e0;
case 0x0c0535e2u: goto P_0c0535e2;
case 0x0c0535e4u: goto P_0c0535e4;
case 0x0c0535e6u: goto P_0c0535e6;
case 0x0c0535e8u: goto P_0c0535e8;
case 0x0c0535eau: goto P_0c0535ea;
case 0x0c0535ecu: goto P_0c0535ec;
case 0x0c0535eeu: goto P_0c0535ee;
case 0x0c0535f0u: goto P_0c0535f0;
case 0x0c0535f2u: goto P_0c0535f2;
case 0x0c0535f4u: goto P_0c0535f4;
case 0x0c0535f6u: goto P_0c0535f6;
case 0x0c0535f8u: goto P_0c0535f8;
case 0x0c0535fau: goto P_0c0535fa;
case 0x0c0535fcu: goto P_0c0535fc;
case 0x0c0535feu: goto P_0c0535fe;
case 0x0c053600u: goto P_0c053600;
case 0x0c053602u: goto P_0c053602;
case 0x0c053604u: goto P_0c053604;
case 0x0c053606u: goto P_0c053606;
case 0x0c053608u: goto P_0c053608;
case 0x0c05360au: goto P_0c05360a;
case 0x0c05360cu: goto P_0c05360c;
case 0x0c05360eu: goto P_0c05360e;
case 0x0c053610u: goto P_0c053610;
case 0x0c053612u: goto P_0c053612;
case 0x0c053614u: goto P_0c053614;
case 0x0c053616u: goto P_0c053616;
case 0x0c053618u: goto P_0c053618;
case 0x0c05361au: goto P_0c05361a;
case 0x0c05361cu: goto P_0c05361c;
case 0x0c05361eu: goto P_0c05361e;
case 0x0c053620u: goto P_0c053620;
case 0x0c053622u: goto P_0c053622;
case 0x0c053624u: goto P_0c053624;
case 0x0c053626u: goto P_0c053626;
case 0x0c053628u: goto P_0c053628;
case 0x0c05362au: goto P_0c05362a;
case 0x0c05362cu: goto P_0c05362c;
case 0x0c05362eu: goto P_0c05362e;
case 0x0c053630u: goto P_0c053630;
case 0x0c053632u: goto P_0c053632;
case 0x0c053634u: goto P_0c053634;
case 0x0c053636u: goto P_0c053636;
case 0x0c053638u: goto P_0c053638;
case 0x0c05363au: goto P_0c05363a;
case 0x0c05363cu: goto P_0c05363c;
case 0x0c05363eu: goto P_0c05363e;
case 0x0c053640u: goto P_0c053640;
case 0x0c053642u: goto P_0c053642;
case 0x0c053644u: goto P_0c053644;
case 0x0c053646u: goto P_0c053646;
case 0x0c053648u: goto P_0c053648;
case 0x0c05364au: goto P_0c05364a;
case 0x0c05364cu: goto P_0c05364c;
case 0x0c05364eu: goto P_0c05364e;
case 0x0c053650u: goto P_0c053650;
case 0x0c053652u: goto P_0c053652;
case 0x0c053654u: goto P_0c053654;
case 0x0c053656u: goto P_0c053656;
case 0x0c053658u: goto P_0c053658;
case 0x0c05365au: goto P_0c05365a;
case 0x0c05365cu: goto P_0c05365c;
case 0x0c05365eu: goto P_0c05365e;
case 0x0c053660u: goto P_0c053660;
case 0x0c053662u: goto P_0c053662;
case 0x0c053664u: goto P_0c053664;
case 0x0c053666u: goto P_0c053666;
case 0x0c053668u: goto P_0c053668;
case 0x0c05366au: goto P_0c05366a;
case 0x0c05366cu: goto P_0c05366c;
case 0x0c05366eu: goto P_0c05366e;
case 0x0c053670u: goto P_0c053670;
case 0x0c053672u: goto P_0c053672;
case 0x0c053674u: goto P_0c053674;
case 0x0c053676u: goto P_0c053676;
case 0x0c053678u: goto P_0c053678;
case 0x0c05367au: goto P_0c05367a;
case 0x0c05367cu: goto P_0c05367c;
case 0x0c05367eu: goto P_0c05367e;
case 0x0c053680u: goto P_0c053680;
case 0x0c053682u: goto P_0c053682;
case 0x0c053684u: goto P_0c053684;
case 0x0c053686u: goto P_0c053686;
case 0x0c053688u: goto P_0c053688;
case 0x0c05368au: goto P_0c05368a;
case 0x0c05368cu: goto P_0c05368c;
case 0x0c05368eu: goto P_0c05368e;
case 0x0c053690u: goto P_0c053690;
case 0x0c053692u: goto P_0c053692;
case 0x0c053694u: goto P_0c053694;
case 0x0c053696u: goto P_0c053696;
case 0x0c053698u: goto P_0c053698;
case 0x0c05369au: goto P_0c05369a;
case 0x0c05369cu: goto P_0c05369c;
case 0x0c05369eu: goto P_0c05369e;
case 0x0c0536a0u: goto P_0c0536a0;
case 0x0c0536a2u: goto P_0c0536a2;
case 0x0c0536a4u: goto P_0c0536a4;
case 0x0c0536a6u: goto P_0c0536a6;
case 0x0c0536a8u: goto P_0c0536a8;
case 0x0c0536aau: goto P_0c0536aa;
case 0x0c0536acu: goto P_0c0536ac;
case 0x0c0536aeu: goto P_0c0536ae;
case 0x0c0536b0u: goto P_0c0536b0;
case 0x0c0536b2u: goto P_0c0536b2;
case 0x0c0536b4u: goto P_0c0536b4;
case 0x0c0536b6u: goto P_0c0536b6;
case 0x0c0536b8u: goto P_0c0536b8;
case 0x0c0536bau: goto P_0c0536ba;
case 0x0c0536bcu: goto P_0c0536bc;
case 0x0c0536beu: goto P_0c0536be;
case 0x0c0536c0u: goto P_0c0536c0;
case 0x0c0536c2u: goto P_0c0536c2;
case 0x0c0536c4u: goto P_0c0536c4;
case 0x0c0536c6u: goto P_0c0536c6;
case 0x0c0536c8u: goto P_0c0536c8;
case 0x0c0536cau: goto P_0c0536ca;
case 0x0c0536ccu: goto P_0c0536cc;
case 0x0c0536ceu: goto P_0c0536ce;
case 0x0c0536d0u: goto P_0c0536d0;
case 0x0c0536d2u: goto P_0c0536d2;
case 0x0c0536d4u: goto P_0c0536d4;
case 0x0c0536d6u: goto P_0c0536d6;
case 0x0c0536d8u: goto P_0c0536d8;
case 0x0c0536dau: goto P_0c0536da;
case 0x0c0536dcu: goto P_0c0536dc;
case 0x0c0536deu: goto P_0c0536de;
case 0x0c0536e0u: goto P_0c0536e0;
case 0x0c05372cu: goto P_0c05372c;
case 0x0c05372eu: goto P_0c05372e;
case 0x0c053730u: goto P_0c053730;
case 0x0c053732u: goto P_0c053732;
case 0x0c053734u: goto P_0c053734;
case 0x0c053736u: goto P_0c053736;
case 0x0c053738u: goto P_0c053738;
case 0x0c05373au: goto P_0c05373a;
case 0x0c05373cu: goto P_0c05373c;
case 0x0c05373eu: goto P_0c05373e;
case 0x0c053740u: goto P_0c053740;
case 0x0c053742u: goto P_0c053742;
case 0x0c053744u: goto P_0c053744;
case 0x0c053746u: goto P_0c053746;
case 0x0c053748u: goto P_0c053748;
case 0x0c05374au: goto P_0c05374a;
case 0x0c05374cu: goto P_0c05374c;
case 0x0c05374eu: goto P_0c05374e;
case 0x0c053750u: goto P_0c053750;
case 0x0c053752u: goto P_0c053752;
case 0x0c053754u: goto P_0c053754;
case 0x0c053756u: goto P_0c053756;
case 0x0c053758u: goto P_0c053758;
case 0x0c05375au: goto P_0c05375a;
case 0x0c05375cu: goto P_0c05375c;
case 0x0c05375eu: goto P_0c05375e;
case 0x0c053760u: goto P_0c053760;
case 0x0c053762u: goto P_0c053762;
case 0x0c053764u: goto P_0c053764;
case 0x0c053766u: goto P_0c053766;
case 0x0c053768u: goto P_0c053768;
case 0x0c05376au: goto P_0c05376a;
case 0x0c05376cu: goto P_0c05376c;
case 0x0c05376eu: goto P_0c05376e;
case 0x0c053770u: goto P_0c053770;
case 0x0c053772u: goto P_0c053772;
case 0x0c053774u: goto P_0c053774;
case 0x0c053776u: goto P_0c053776;
case 0x0c053778u: goto P_0c053778;
case 0x0c05377au: goto P_0c05377a;
case 0x0c05377cu: goto P_0c05377c;
case 0x0c05377eu: goto P_0c05377e;
case 0x0c053780u: goto P_0c053780;
case 0x0c053782u: goto P_0c053782;
case 0x0c053784u: goto P_0c053784;
case 0x0c053786u: goto P_0c053786;
case 0x0c053788u: goto P_0c053788;
case 0x0c05378au: goto P_0c05378a;
case 0x0c05378cu: goto P_0c05378c;
case 0x0c05378eu: goto P_0c05378e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c053308: /* original 2f46, guest PC 0x0c053308 */
if(!s->budget--) { s->failed_pc=0x0c053308u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05330a;
P_0c05330a: /* original 2f56, guest PC 0x0c05330a */
if(!s->budget--) { s->failed_pc=0x0c05330au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05330c;
P_0c05330c: /* original 2f66, guest PC 0x0c05330c */
if(!s->budget--) { s->failed_pc=0x0c05330cu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05330e;
P_0c05330e: /* original 2f76, guest PC 0x0c05330e */
if(!s->budget--) { s->failed_pc=0x0c05330eu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053310;
P_0c053310: /* original 55f6, guest PC 0x0c053310 */
if(!s->budget--) { s->failed_pc=0x0c053310u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c053312;
P_0c053312: /* original 54f7, guest PC 0x0c053312 */
if(!s->budget--) { s->failed_pc=0x0c053312u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c053314;
P_0c053314: /* original 57f4, guest PC 0x0c053314 */
if(!s->budget--) { s->failed_pc=0x0c053314u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c053316;
P_0c053316: /* original 56f5, guest PC 0x0c053316 */
if(!s->budget--) { s->failed_pc=0x0c053316u; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c053318;
P_0c053318: /* original 2f86, guest PC 0x0c053318 */
if(!s->budget--) { s->failed_pc=0x0c053318u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05331a;
P_0c05331a: /* original 2f96, guest PC 0x0c05331a */
if(!s->budget--) { s->failed_pc=0x0c05331au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05331c;
P_0c05331c: /* original 2fa6, guest PC 0x0c05331c */
if(!s->budget--) { s->failed_pc=0x0c05331cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05331e;
P_0c05331e: /* original 2fb6, guest PC 0x0c05331e */
if(!s->budget--) { s->failed_pc=0x0c05331eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053320;
P_0c053320: /* original d01c, guest PC 0x0c053320 */
if(!s->budget--) { s->failed_pc=0x0c053320u; return 0; }
r[0]=read(ram,0x0c053394u,4);
goto P_0c053322;
P_0c053322: /* original 6a43, guest PC 0x0c053322 */
if(!s->budget--) { s->failed_pc=0x0c053322u; return 0; }
r[10]=r[4];
goto P_0c053324;
P_0c053324: /* original 6b63, guest PC 0x0c053324 */
if(!s->budget--) { s->failed_pc=0x0c053324u; return 0; }
r[11]=r[6];
goto P_0c053326;
P_0c053326: /* original 6843, guest PC 0x0c053326 */
if(!s->budget--) { s->failed_pc=0x0c053326u; return 0; }
r[8]=r[4];
goto P_0c053328;
P_0c053328: /* original 2809, guest PC 0x0c053328 */
if(!s->budget--) { s->failed_pc=0x0c053328u; return 0; }
r[8]&=r[0];
goto P_0c05332a;
P_0c05332a: /* original 6963, guest PC 0x0c05332a */
if(!s->budget--) { s->failed_pc=0x0c05332au; return 0; }
r[9]=r[6];
goto P_0c05332c;
P_0c05332c: /* original 2909, guest PC 0x0c05332c */
if(!s->budget--) { s->failed_pc=0x0c05332cu; return 0; }
r[9]&=r[0];
goto P_0c05332e;
P_0c05332e: /* original d01a, guest PC 0x0c05332e */
if(!s->budget--) { s->failed_pc=0x0c05332eu; return 0; }
r[0]=read(ram,0x0c053398u,4);
goto P_0c053330;
P_0c053330: /* original 2409, guest PC 0x0c053330 */
if(!s->budget--) { s->failed_pc=0x0c053330u; return 0; }
r[4]&=r[0];
goto P_0c053332;
P_0c053332: /* original 2609, guest PC 0x0c053332 */
if(!s->budget--) { s->failed_pc=0x0c053332u; return 0; }
r[6]&=r[0];
goto P_0c053334;
P_0c053334: /* original d017, guest PC 0x0c053334 */
if(!s->budget--) { s->failed_pc=0x0c053334u; return 0; }
r[0]=read(ram,0x0c053394u,4);
goto P_0c053336;
P_0c053336: /* original 3800, guest PC 0x0c053336 */
if(!s->budget--) { s->failed_pc=0x0c053336u; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[0])!=0);
goto P_0c053338;
P_0c053338: /* original 8914, guest PC 0x0c053338 */
if(!s->budget--) { s->failed_pc=0x0c053338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053364; }
goto P_0c05333a;
P_0c05333a: /* original 3900, guest PC 0x0c05333a */
if(!s->budget--) { s->failed_pc=0x0c05333au; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[0])!=0);
goto P_0c05333c;
P_0c05333c: /* original 8918, guest PC 0x0c05333c */
if(!s->budget--) { s->failed_pc=0x0c05333cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053370; }
goto P_0c05333e;
P_0c05333e: /* original 2888, guest PC 0x0c05333e */
if(!s->budget--) { s->failed_pc=0x0c05333eu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c053340;
P_0c053340: /* original 891c, guest PC 0x0c053340 */
if(!s->budget--) { s->failed_pc=0x0c053340u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05337c; }
goto P_0c053342;
P_0c053342: /* original 3ba0, guest PC 0x0c053342 */
if(!s->budget--) { s->failed_pc=0x0c053342u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[10])!=0);
goto P_0c053344;
P_0c053344: /* original 8b03, guest PC 0x0c053344 */
if(!s->budget--) { s->failed_pc=0x0c053344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053346;
P_0c053346: /* original 3750, guest PC 0x0c053346 */
if(!s->budget--) { s->failed_pc=0x0c053346u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[5])!=0);
goto P_0c053348;
P_0c053348: /* original 8b01, guest PC 0x0c053348 */
if(!s->budget--) { s->failed_pc=0x0c053348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c05334a;
P_0c05334a: /* original a001, guest PC 0x0c05334a */
if(!s->budget--) { s->failed_pc=0x0c05334au; return 0; }
r[0]=0x00000001u;
goto P_0c053350;
P_0c05334c: /* original e001, guest PC 0x0c05334c */
if(!s->budget--) { s->failed_pc=0x0c05334cu; return 0; }
r[0]=0x00000001u;
goto P_0c05334e;
P_0c05334e: /* original e000, guest PC 0x0c05334e */
if(!s->budget--) { s->failed_pc=0x0c05334eu; return 0; }
r[0]=0x00000000u;
goto P_0c053350;
P_0c053350: /* original 6bf6, guest PC 0x0c053350 */
if(!s->budget--) { s->failed_pc=0x0c053350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c053352;
P_0c053352: /* original 6af6, guest PC 0x0c053352 */
if(!s->budget--) { s->failed_pc=0x0c053352u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c053354;
P_0c053354: /* original 69f6, guest PC 0x0c053354 */
if(!s->budget--) { s->failed_pc=0x0c053354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c053356;
P_0c053356: /* original 68f6, guest PC 0x0c053356 */
if(!s->budget--) { s->failed_pc=0x0c053356u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c053358;
P_0c053358: /* original 67f6, guest PC 0x0c053358 */
if(!s->budget--) { s->failed_pc=0x0c053358u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c05335a;
P_0c05335a: /* original 66f6, guest PC 0x0c05335a */
if(!s->budget--) { s->failed_pc=0x0c05335au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c05335c;
P_0c05335c: /* original 65f6, guest PC 0x0c05335c */
if(!s->budget--) { s->failed_pc=0x0c05335cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c05335e;
P_0c05335e: /* original 64f6, guest PC 0x0c05335e */
if(!s->budget--) { s->failed_pc=0x0c05335eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c053360;
P_0c053360: /* original 000b, guest PC 0x0c053360 */
if(!s->budget--) { s->failed_pc=0x0c053360u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c053362: /* original 7f10, guest PC 0x0c053362 */
if(!s->budget--) { s->failed_pc=0x0c053362u; return 0; }
r[15]+=0x00000010u;
goto P_0c053364;
P_0c053364: /* original 2448, guest PC 0x0c053364 */
if(!s->budget--) { s->failed_pc=0x0c053364u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c053366;
P_0c053366: /* original 8bf2, guest PC 0x0c053366 */
if(!s->budget--) { s->failed_pc=0x0c053366u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053368;
P_0c053368: /* original 2558, guest PC 0x0c053368 */
if(!s->budget--) { s->failed_pc=0x0c053368u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05336a;
P_0c05336a: /* original 8bf0, guest PC 0x0c05336a */
if(!s->budget--) { s->failed_pc=0x0c05336au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c05336c;
P_0c05336c: /* original afe5, guest PC 0x0c05336c */
if(!s->budget--) { s->failed_pc=0x0c05336cu; return 0; }
goto P_0c05333a;
P_0c05336e: /* original 0009, guest PC 0x0c05336e */
if(!s->budget--) { s->failed_pc=0x0c05336eu; return 0; }
goto P_0c053370;
P_0c053370: /* original 2668, guest PC 0x0c053370 */
if(!s->budget--) { s->failed_pc=0x0c053370u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c053372;
P_0c053372: /* original 8bec, guest PC 0x0c053372 */
if(!s->budget--) { s->failed_pc=0x0c053372u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053374;
P_0c053374: /* original 2778, guest PC 0x0c053374 */
if(!s->budget--) { s->failed_pc=0x0c053374u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c053376;
P_0c053376: /* original 8bea, guest PC 0x0c053376 */
if(!s->budget--) { s->failed_pc=0x0c053376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053378;
P_0c053378: /* original afe1, guest PC 0x0c053378 */
if(!s->budget--) { s->failed_pc=0x0c053378u; return 0; }
goto P_0c05333e;
P_0c05337a: /* original 0009, guest PC 0x0c05337a */
if(!s->budget--) { s->failed_pc=0x0c05337au; return 0; }
goto P_0c05337c;
P_0c05337c: /* original 2998, guest PC 0x0c05337c */
if(!s->budget--) { s->failed_pc=0x0c05337cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c05337e;
P_0c05337e: /* original 8be6, guest PC 0x0c05337e */
if(!s->budget--) { s->failed_pc=0x0c05337eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053380;
P_0c053380: /* original 2448, guest PC 0x0c053380 */
if(!s->budget--) { s->failed_pc=0x0c053380u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c053382;
P_0c053382: /* original 8bde, guest PC 0x0c053382 */
if(!s->budget--) { s->failed_pc=0x0c053382u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053342; }
goto P_0c053384;
P_0c053384: /* original 2558, guest PC 0x0c053384 */
if(!s->budget--) { s->failed_pc=0x0c053384u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c053386;
P_0c053386: /* original 8bdc, guest PC 0x0c053386 */
if(!s->budget--) { s->failed_pc=0x0c053386u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053342; }
goto P_0c053388;
P_0c053388: /* original 2668, guest PC 0x0c053388 */
if(!s->budget--) { s->failed_pc=0x0c053388u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05338a;
P_0c05338a: /* original 8be0, guest PC 0x0c05338a */
if(!s->budget--) { s->failed_pc=0x0c05338au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c05338c;
P_0c05338c: /* original 2778, guest PC 0x0c05338c */
if(!s->budget--) { s->failed_pc=0x0c05338cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05338e;
P_0c05338e: /* original 8bde, guest PC 0x0c05338e */
if(!s->budget--) { s->failed_pc=0x0c05338eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05334e; }
goto P_0c053390;
P_0c053390: /* original afde, guest PC 0x0c053390 */
if(!s->budget--) { s->failed_pc=0x0c053390u; return 0; }
r[0]=0x00000001u;
goto P_0c053350;
P_0c053392: /* original e001, guest PC 0x0c053392 */
if(!s->budget--) { s->failed_pc=0x0c053392u; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c053394u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053394u; return 0; } return 1;
P_0c053450: /* original 2fe6, guest PC 0x0c053450 */
if(!s->budget--) { s->failed_pc=0x0c053450u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053452;
P_0c053452: /* original 6e53, guest PC 0x0c053452 */
if(!s->budget--) { s->failed_pc=0x0c053452u; return 0; }
r[14]=r[5];
goto P_0c053454;
P_0c053454: /* original 2fd6, guest PC 0x0c053454 */
if(!s->budget--) { s->failed_pc=0x0c053454u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053456;
P_0c053456: /* original 2fc6, guest PC 0x0c053456 */
if(!s->budget--) { s->failed_pc=0x0c053456u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053458;
P_0c053458: /* original 2fb6, guest PC 0x0c053458 */
if(!s->budget--) { s->failed_pc=0x0c053458u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05345a;
P_0c05345a: /* original 2fa6, guest PC 0x0c05345a */
if(!s->budget--) { s->failed_pc=0x0c05345au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05345c;
P_0c05345c: /* original 2f96, guest PC 0x0c05345c */
if(!s->budget--) { s->failed_pc=0x0c05345cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05345e;
P_0c05345e: /* original 2f86, guest PC 0x0c05345e */
if(!s->budget--) { s->failed_pc=0x0c05345eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053460;
P_0c053460: /* original 4f22, guest PC 0x0c053460 */
if(!s->budget--) { s->failed_pc=0x0c053460u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053462;
P_0c053462: /* original 7fec, guest PC 0x0c053462 */
if(!s->budget--) { s->failed_pc=0x0c053462u; return 0; }
r[15]+=0xffffffecu;
goto P_0c053464;
P_0c053464: /* original 1f41, guest PC 0x0c053464 */
if(!s->budget--) { s->failed_pc=0x0c053464u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c053466;
P_0c053466: /* original dd34, guest PC 0x0c053466 */
if(!s->budget--) { s->failed_pc=0x0c053466u; return 0; }
r[13]=read(ram,0x0c053538u,4);
goto P_0c053468;
P_0c053468: /* original 2f56, guest PC 0x0c053468 */
if(!s->budget--) { s->failed_pc=0x0c053468u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05346a;
P_0c05346a: /* original 53f2, guest PC 0x0c05346a */
if(!s->budget--) { s->failed_pc=0x0c05346au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05346c;
P_0c05346c: /* original 2f36, guest PC 0x0c05346c */
if(!s->budget--) { s->failed_pc=0x0c05346cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05346e;
P_0c05346e: /* original d233, guest PC 0x0c05346e */
if(!s->budget--) { s->failed_pc=0x0c05346eu; return 0; }
r[2]=read(ram,0x0c05353cu,4);
goto P_0c053470;
P_0c053470: /* original 4d0b, guest PC 0x0c053470 */
if(!s->budget--) { s->failed_pc=0x0c053470u; return 0; }
target=r[13];
r[16]=code_base|0x0c053474u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053474u) { target=s->pc; goto dispatch; }
goto P_0c053474;
P_0c053472: /* original 2f26, guest PC 0x0c053472 */
if(!s->budget--) { s->failed_pc=0x0c053472u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053474;
P_0c053474: /* original 7f0c, guest PC 0x0c053474 */
if(!s->budget--) { s->failed_pc=0x0c053474u; return 0; }
r[15]+=0x0000000cu;
goto P_0c053476;
P_0c053476: /* original d032, guest PC 0x0c053476 */
if(!s->budget--) { s->failed_pc=0x0c053476u; return 0; }
r[0]=read(ram,0x0c053540u,4);
goto P_0c053478;
P_0c053478: /* original 5cf1, guest PC 0x0c053478 */
if(!s->budget--) { s->failed_pc=0x0c053478u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c05347a;
P_0c05347a: /* original d332, guest PC 0x0c05347a */
if(!s->budget--) { s->failed_pc=0x0c05347au; return 0; }
r[3]=read(ram,0x0c053544u,4);
goto P_0c05347c;
P_0c05347c: /* original 4c08, guest PC 0x0c05347c */
if(!s->budget--) { s->failed_pc=0x0c05347cu; return 0; }
r[12]<<=2;
goto P_0c05347e;
P_0c05347e: /* original 0cce, guest PC 0x0c05347e */
if(!s->budget--) { s->failed_pc=0x0c05347eu; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c053480;
P_0c053480: /* original 430b, guest PC 0x0c053480 */
if(!s->budget--) { s->failed_pc=0x0c053480u; return 0; }
target=r[3];
r[16]=code_base|0x0c053484u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053484u) { target=s->pc; goto dispatch; }
goto P_0c053484;
P_0c053482: /* original 64c3, guest PC 0x0c053482 */
if(!s->budget--) { s->failed_pc=0x0c053482u; return 0; }
r[4]=r[12];
goto P_0c053484;
P_0c053484: /* original 2f02, guest PC 0x0c053484 */
if(!s->budget--) { s->failed_pc=0x0c053484u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053486;
P_0c053486: /* original d330, guest PC 0x0c053486 */
if(!s->budget--) { s->failed_pc=0x0c053486u; return 0; }
r[3]=read(ram,0x0c053548u,4);
goto P_0c053488;
P_0c053488: /* original 430b, guest PC 0x0c053488 */
if(!s->budget--) { s->failed_pc=0x0c053488u; return 0; }
target=r[3];
r[16]=code_base|0x0c05348cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05348cu) { target=s->pc; goto dispatch; }
goto P_0c05348c;
P_0c05348a: /* original 64c3, guest PC 0x0c05348a */
if(!s->budget--) { s->failed_pc=0x0c05348au; return 0; }
r[4]=r[12];
goto P_0c05348c;
P_0c05348c: /* original 62f2, guest PC 0x0c05348c */
if(!s->budget--) { s->failed_pc=0x0c05348cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05348e;
P_0c05348e: /* original 6403, guest PC 0x0c05348e */
if(!s->budget--) { s->failed_pc=0x0c05348eu; return 0; }
r[4]=r[0];
goto P_0c053490;
P_0c053490: /* original da2f, guest PC 0x0c053490 */
if(!s->budget--) { s->failed_pc=0x0c053490u; return 0; }
r[10]=read(ram,0x0c053550u,4);
goto P_0c053492;
P_0c053492: /* original 6320, guest PC 0x0c053492 */
if(!s->budget--) { s->failed_pc=0x0c053492u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c053494;
P_0c053494: /* original d82d, guest PC 0x0c053494 */
if(!s->budget--) { s->failed_pc=0x0c053494u; return 0; }
r[8]=read(ram,0x0c05354cu,4);
goto P_0c053496;
P_0c053496: /* original 2338, guest PC 0x0c053496 */
if(!s->budget--) { s->failed_pc=0x0c053496u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c053498;
P_0c053498: /* original 8b01, guest PC 0x0c053498 */
if(!s->budget--) { s->failed_pc=0x0c053498u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05349e; }
goto P_0c05349a;
P_0c05349a: /* original a16a, guest PC 0x0c05349a */
if(!s->budget--) { s->failed_pc=0x0c05349au; return 0; }
goto P_0c053772;
P_0c05349c: /* original 0009, guest PC 0x0c05349c */
if(!s->budget--) { s->failed_pc=0x0c05349cu; return 0; }
goto P_0c05349e;
P_0c05349e: /* original 6042, guest PC 0x0c05349e */
if(!s->budget--) { s->failed_pc=0x0c05349eu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0534a0;
P_0c0534a0: /* original c802, guest PC 0x0c0534a0 */
if(!s->budget--) { s->failed_pc=0x0c0534a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0534a2;
P_0c0534a2: /* original 8b01, guest PC 0x0c0534a2 */
if(!s->budget--) { s->failed_pc=0x0c0534a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0534a8; }
goto P_0c0534a4;
P_0c0534a4: /* original a165, guest PC 0x0c0534a4 */
if(!s->budget--) { s->failed_pc=0x0c0534a4u; return 0; }
goto P_0c053772;
P_0c0534a6: /* original 0009, guest PC 0x0c0534a6 */
if(!s->budget--) { s->failed_pc=0x0c0534a6u; return 0; }
goto P_0c0534a8;
P_0c0534a8: /* original d22a, guest PC 0x0c0534a8 */
if(!s->budget--) { s->failed_pc=0x0c0534a8u; return 0; }
r[2]=read(ram,0x0c053554u,4);
goto P_0c0534aa;
P_0c0534aa: /* original 420b, guest PC 0x0c0534aa */
if(!s->budget--) { s->failed_pc=0x0c0534aau; return 0; }
target=r[2];
r[16]=code_base|0x0c0534aeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534aeu) { target=s->pc; goto dispatch; }
goto P_0c0534ae;
P_0c0534ac: /* original 64c3, guest PC 0x0c0534ac */
if(!s->budget--) { s->failed_pc=0x0c0534acu; return 0; }
r[4]=r[12];
goto P_0c0534ae;
P_0c0534ae: /* original db2a, guest PC 0x0c0534ae */
if(!s->budget--) { s->failed_pc=0x0c0534aeu; return 0; }
r[11]=read(ram,0x0c053558u,4);
goto P_0c0534b0;
P_0c0534b0: /* original 2fc6, guest PC 0x0c0534b0 */
if(!s->budget--) { s->failed_pc=0x0c0534b0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534b2;
P_0c0534b2: /* original 4d0b, guest PC 0x0c0534b2 */
if(!s->budget--) { s->failed_pc=0x0c0534b2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0534b6u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534b6u) { target=s->pc; goto dispatch; }
goto P_0c0534b6;
P_0c0534b4: /* original 2fb6, guest PC 0x0c0534b4 */
if(!s->budget--) { s->failed_pc=0x0c0534b4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534b6;
P_0c0534b6: /* original d223, guest PC 0x0c0534b6 */
if(!s->budget--) { s->failed_pc=0x0c0534b6u; return 0; }
r[2]=read(ram,0x0c053544u,4);
goto P_0c0534b8;
P_0c0534b8: /* original 7f08, guest PC 0x0c0534b8 */
if(!s->budget--) { s->failed_pc=0x0c0534b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0534ba;
P_0c0534ba: /* original 420b, guest PC 0x0c0534ba */
if(!s->budget--) { s->failed_pc=0x0c0534bau; return 0; }
target=r[2];
r[16]=code_base|0x0c0534beu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534beu) { target=s->pc; goto dispatch; }
goto P_0c0534be;
P_0c0534bc: /* original 64c3, guest PC 0x0c0534bc */
if(!s->budget--) { s->failed_pc=0x0c0534bcu; return 0; }
r[4]=r[12];
goto P_0c0534be;
P_0c0534be: /* original d327, guest PC 0x0c0534be */
if(!s->budget--) { s->failed_pc=0x0c0534beu; return 0; }
r[3]=read(ram,0x0c05355cu,4);
goto P_0c0534c0;
P_0c0534c0: /* original e502, guest PC 0x0c0534c0 */
if(!s->budget--) { s->failed_pc=0x0c0534c0u; return 0; }
r[5]=0x00000002u;
goto P_0c0534c2;
P_0c0534c2: /* original e600, guest PC 0x0c0534c2 */
if(!s->budget--) { s->failed_pc=0x0c0534c2u; return 0; }
r[6]=0x00000000u;
goto P_0c0534c4;
P_0c0534c4: /* original 430b, guest PC 0x0c0534c4 */
if(!s->budget--) { s->failed_pc=0x0c0534c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0534c8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534c8u) { target=s->pc; goto dispatch; }
goto P_0c0534c8;
P_0c0534c6: /* original 64c3, guest PC 0x0c0534c6 */
if(!s->budget--) { s->failed_pc=0x0c0534c6u; return 0; }
r[4]=r[12];
goto P_0c0534c8;
P_0c0534c8: /* original 6903, guest PC 0x0c0534c8 */
if(!s->budget--) { s->failed_pc=0x0c0534c8u; return 0; }
r[9]=r[0];
goto P_0c0534ca;
P_0c0534ca: /* original 4911, guest PC 0x0c0534ca */
if(!s->budget--) { s->failed_pc=0x0c0534cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c0534cc;
P_0c0534cc: /* original 8905, guest PC 0x0c0534cc */
if(!s->budget--) { s->failed_pc=0x0c0534ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0534da; }
goto P_0c0534ce;
P_0c0534ce: /* original 4d0b, guest PC 0x0c0534ce */
if(!s->budget--) { s->failed_pc=0x0c0534ceu; return 0; }
target=r[13];
r[16]=code_base|0x0c0534d2u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534d2u) { target=s->pc; goto dispatch; }
goto P_0c0534d2;
P_0c0534d0: /* original 2f86, guest PC 0x0c0534d0 */
if(!s->budget--) { s->failed_pc=0x0c0534d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534d2;
P_0c0534d2: /* original 4a0b, guest PC 0x0c0534d2 */
if(!s->budget--) { s->failed_pc=0x0c0534d2u; return 0; }
target=r[10];
r[16]=code_base|0x0c0534d6u;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534d6u) { target=s->pc; goto dispatch; }
goto P_0c0534d6;
P_0c0534d4: /* original 7f04, guest PC 0x0c0534d4 */
if(!s->budget--) { s->failed_pc=0x0c0534d4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0534d6;
P_0c0534d6: /* original afeb, guest PC 0x0c0534d6 */
if(!s->budget--) { s->failed_pc=0x0c0534d6u; return 0; }
goto P_0c0534b0;
P_0c0534d8: /* original 0009, guest PC 0x0c0534d8 */
if(!s->budget--) { s->failed_pc=0x0c0534d8u; return 0; }
goto P_0c0534da;
P_0c0534da: /* original db21, guest PC 0x0c0534da */
if(!s->budget--) { s->failed_pc=0x0c0534dau; return 0; }
r[11]=read(ram,0x0c053560u,4);
goto P_0c0534dc;
P_0c0534dc: /* original 2f96, guest PC 0x0c0534dc */
if(!s->budget--) { s->failed_pc=0x0c0534dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534de;
P_0c0534de: /* original 2fc6, guest PC 0x0c0534de */
if(!s->budget--) { s->failed_pc=0x0c0534deu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534e0;
P_0c0534e0: /* original 4d0b, guest PC 0x0c0534e0 */
if(!s->budget--) { s->failed_pc=0x0c0534e0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0534e4u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534e4u) { target=s->pc; goto dispatch; }
goto P_0c0534e4;
P_0c0534e2: /* original 2fb6, guest PC 0x0c0534e2 */
if(!s->budget--) { s->failed_pc=0x0c0534e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534e4;
P_0c0534e4: /* original d21f, guest PC 0x0c0534e4 */
if(!s->budget--) { s->failed_pc=0x0c0534e4u; return 0; }
r[2]=read(ram,0x0c053564u,4);
goto P_0c0534e6;
P_0c0534e6: /* original 6593, guest PC 0x0c0534e6 */
if(!s->budget--) { s->failed_pc=0x0c0534e6u; return 0; }
r[5]=r[9];
goto P_0c0534e8;
P_0c0534e8: /* original 7f0c, guest PC 0x0c0534e8 */
if(!s->budget--) { s->failed_pc=0x0c0534e8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0534ea;
P_0c0534ea: /* original 420b, guest PC 0x0c0534ea */
if(!s->budget--) { s->failed_pc=0x0c0534eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0534eeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534eeu) { target=s->pc; goto dispatch; }
goto P_0c0534ee;
P_0c0534ec: /* original 64c3, guest PC 0x0c0534ec */
if(!s->budget--) { s->failed_pc=0x0c0534ecu; return 0; }
r[4]=r[12];
goto P_0c0534ee;
P_0c0534ee: /* original 2008, guest PC 0x0c0534ee */
if(!s->budget--) { s->failed_pc=0x0c0534eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0534f0;
P_0c0534f0: /* original 8b05, guest PC 0x0c0534f0 */
if(!s->budget--) { s->failed_pc=0x0c0534f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0534fe; }
goto P_0c0534f2;
P_0c0534f2: /* original 4d0b, guest PC 0x0c0534f2 */
if(!s->budget--) { s->failed_pc=0x0c0534f2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0534f6u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534f6u) { target=s->pc; goto dispatch; }
goto P_0c0534f6;
P_0c0534f4: /* original 2f86, guest PC 0x0c0534f4 */
if(!s->budget--) { s->failed_pc=0x0c0534f4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0534f6;
P_0c0534f6: /* original 4a0b, guest PC 0x0c0534f6 */
if(!s->budget--) { s->failed_pc=0x0c0534f6u; return 0; }
target=r[10];
r[16]=code_base|0x0c0534fau;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0534fau) { target=s->pc; goto dispatch; }
goto P_0c0534fa;
P_0c0534f8: /* original 7f04, guest PC 0x0c0534f8 */
if(!s->budget--) { s->failed_pc=0x0c0534f8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0534fa;
P_0c0534fa: /* original afef, guest PC 0x0c0534fa */
if(!s->budget--) { s->failed_pc=0x0c0534fau; return 0; }
goto P_0c0534dc;
P_0c0534fc: /* original 0009, guest PC 0x0c0534fc */
if(!s->budget--) { s->failed_pc=0x0c0534fcu; return 0; }
goto P_0c0534fe;
P_0c0534fe: /* original d311, guest PC 0x0c0534fe */
if(!s->budget--) { s->failed_pc=0x0c0534feu; return 0; }
r[3]=read(ram,0x0c053544u,4);
goto P_0c053500;
P_0c053500: /* original 430b, guest PC 0x0c053500 */
if(!s->budget--) { s->failed_pc=0x0c053500u; return 0; }
target=r[3];
r[16]=code_base|0x0c053504u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053504u) { target=s->pc; goto dispatch; }
goto P_0c053504;
P_0c053502: /* original 64c3, guest PC 0x0c053502 */
if(!s->budget--) { s->failed_pc=0x0c053502u; return 0; }
r[4]=r[12];
goto P_0c053504;
P_0c053504: /* original 2f02, guest PC 0x0c053504 */
if(!s->budget--) { s->failed_pc=0x0c053504u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053506;
P_0c053506: /* original d318, guest PC 0x0c053506 */
if(!s->budget--) { s->failed_pc=0x0c053506u; return 0; }
r[3]=read(ram,0x0c053568u,4);
goto P_0c053508;
P_0c053508: /* original 430b, guest PC 0x0c053508 */
if(!s->budget--) { s->failed_pc=0x0c053508u; return 0; }
target=r[3];
r[16]=code_base|0x0c05350cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05350cu) { target=s->pc; goto dispatch; }
goto P_0c05350c;
P_0c05350a: /* original 64c3, guest PC 0x0c05350a */
if(!s->budget--) { s->failed_pc=0x0c05350au; return 0; }
r[4]=r[12];
goto P_0c05350c;
P_0c05350c: /* original 2008, guest PC 0x0c05350c */
if(!s->budget--) { s->failed_pc=0x0c05350cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05350e;
P_0c05350e: /* original 8901, guest PC 0x0c05350e */
if(!s->budget--) { s->failed_pc=0x0c05350eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053514; }
goto P_0c053510;
P_0c053510: /* original a12f, guest PC 0x0c053510 */
if(!s->budget--) { s->failed_pc=0x0c053510u; return 0; }
goto P_0c053772;
P_0c053512: /* original 0009, guest PC 0x0c053512 */
if(!s->budget--) { s->failed_pc=0x0c053512u; return 0; }
goto P_0c053514;
P_0c053514: /* original 60f2, guest PC 0x0c053514 */
if(!s->budget--) { s->failed_pc=0x0c053514u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053516;
P_0c053516: /* original 6bf2, guest PC 0x0c053516 */
if(!s->budget--) { s->failed_pc=0x0c053516u; return 0; }
tmp=read(ram,r[15],4);
r[11]=tmp;
goto P_0c053518;
P_0c053518: /* original 8404, guest PC 0x0c053518 */
if(!s->budget--) { s->failed_pc=0x0c053518u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+4,1);
goto P_0c05351a;
P_0c05351a: /* original 5bb2, guest PC 0x0c05351a */
if(!s->budget--) { s->failed_pc=0x0c05351au; return 0; }
r[11]=read(ram,r[11]+8,4);
goto P_0c05351c;
P_0c05351c: /* original 600c, guest PC 0x0c05351c */
if(!s->budget--) { s->failed_pc=0x0c05351cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05351e;
P_0c05351e: /* original 8808, guest PC 0x0c05351e */
if(!s->budget--) { s->failed_pc=0x0c05351eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c053520;
P_0c053520: /* original 8d24, guest PC 0x0c053520 */
if(!s->budget--) { s->failed_pc=0x0c053520u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000008u;
if(cond) { goto P_0c05356c; }
goto P_0c053524;
P_0c053522: /* original 7b08, guest PC 0x0c053522 */
if(!s->budget--) { s->failed_pc=0x0c053522u; return 0; }
r[11]+=0x00000008u;
goto P_0c053524;
P_0c053524: /* original 9103, guest PC 0x0c053524 */
if(!s->budget--) { s->failed_pc=0x0c053524u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05352eu,2);
goto P_0c053526;
P_0c053526: /* original 3010, guest PC 0x0c053526 */
if(!s->budget--) { s->failed_pc=0x0c053526u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c053528;
P_0c053528: /* original 89c1, guest PC 0x0c053528 */
if(!s->budget--) { s->failed_pc=0x0c053528u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0534ae; }
goto P_0c05352a;
P_0c05352a: /* original a126, guest PC 0x0c05352a */
if(!s->budget--) { s->failed_pc=0x0c05352au; return 0; }
goto P_0c05377a;
P_0c05352c: /* original 0009, guest PC 0x0c05352c */
if(!s->budget--) { s->failed_pc=0x0c05352cu; return 0; }
if(!vf3_matrix_family(0x0c05352eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05352eu; return 0; } return 1;
P_0c05356c: /* original d95e, guest PC 0x0c05356c */
if(!s->budget--) { s->failed_pc=0x0c05356cu; return 0; }
r[9]=read(ram,0x0c0536e8u,4);
goto P_0c05356e;
P_0c05356e: /* original e500, guest PC 0x0c05356e */
if(!s->budget--) { s->failed_pc=0x0c05356eu; return 0; }
r[5]=0x00000000u;
goto P_0c053570;
P_0c053570: /* original 6292, guest PC 0x0c053570 */
if(!s->budget--) { s->failed_pc=0x0c053570u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c053572;
P_0c053572: /* original 5323, guest PC 0x0c053572 */
if(!s->budget--) { s->failed_pc=0x0c053572u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c053574;
P_0c053574: /* original 430b, guest PC 0x0c053574 */
if(!s->budget--) { s->failed_pc=0x0c053574u; return 0; }
target=r[3];
r[16]=code_base|0x0c053578u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053578u) { target=s->pc; goto dispatch; }
goto P_0c053578;
P_0c053576: /* original 64b3, guest PC 0x0c053576 */
if(!s->budget--) { s->failed_pc=0x0c053576u; return 0; }
r[4]=r[11];
goto P_0c053578;
P_0c053578: /* original 600d, guest PC 0x0c053578 */
if(!s->budget--) { s->failed_pc=0x0c053578u; return 0; }
r[0]=r[0]&65535u;
goto P_0c05357a;
P_0c05357a: /* original e502, guest PC 0x0c05357a */
if(!s->budget--) { s->failed_pc=0x0c05357au; return 0; }
r[5]=0x00000002u;
goto P_0c05357c;
P_0c05357c: /* original 2e02, guest PC 0x0c05357c */
if(!s->budget--) { s->failed_pc=0x0c05357cu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c05357e;
P_0c05357e: /* original 6292, guest PC 0x0c05357e */
if(!s->budget--) { s->failed_pc=0x0c05357eu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c053580;
P_0c053580: /* original 5323, guest PC 0x0c053580 */
if(!s->budget--) { s->failed_pc=0x0c053580u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c053582;
P_0c053582: /* original 430b, guest PC 0x0c053582 */
if(!s->budget--) { s->failed_pc=0x0c053582u; return 0; }
target=r[3];
r[16]=code_base|0x0c053586u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053586u) { target=s->pc; goto dispatch; }
goto P_0c053586;
P_0c053584: /* original 64b3, guest PC 0x0c053584 */
if(!s->budget--) { s->failed_pc=0x0c053584u; return 0; }
r[4]=r[11];
goto P_0c053586;
P_0c053586: /* original 600d, guest PC 0x0c053586 */
if(!s->budget--) { s->failed_pc=0x0c053586u; return 0; }
r[0]=r[0]&65535u;
goto P_0c053588;
P_0c053588: /* original e504, guest PC 0x0c053588 */
if(!s->budget--) { s->failed_pc=0x0c053588u; return 0; }
r[5]=0x00000004u;
goto P_0c05358a;
P_0c05358a: /* original 1e01, guest PC 0x0c05358a */
if(!s->budget--) { s->failed_pc=0x0c05358au; return 0; }
write(ram,r[14]+4,r[0],4);
goto P_0c05358c;
P_0c05358c: /* original 6292, guest PC 0x0c05358c */
if(!s->budget--) { s->failed_pc=0x0c05358cu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c05358e;
P_0c05358e: /* original 5323, guest PC 0x0c05358e */
if(!s->budget--) { s->failed_pc=0x0c05358eu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c053590;
P_0c053590: /* original 430b, guest PC 0x0c053590 */
if(!s->budget--) { s->failed_pc=0x0c053590u; return 0; }
target=r[3];
r[16]=code_base|0x0c053594u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053594u) { target=s->pc; goto dispatch; }
goto P_0c053594;
P_0c053592: /* original 64b3, guest PC 0x0c053592 */
if(!s->budget--) { s->failed_pc=0x0c053592u; return 0; }
r[4]=r[11];
goto P_0c053594;
P_0c053594: /* original 600d, guest PC 0x0c053594 */
if(!s->budget--) { s->failed_pc=0x0c053594u; return 0; }
r[0]=r[0]&65535u;
goto P_0c053596;
P_0c053596: /* original e506, guest PC 0x0c053596 */
if(!s->budget--) { s->failed_pc=0x0c053596u; return 0; }
r[5]=0x00000006u;
goto P_0c053598;
P_0c053598: /* original 1e02, guest PC 0x0c053598 */
if(!s->budget--) { s->failed_pc=0x0c053598u; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c05359a;
P_0c05359a: /* original 6292, guest PC 0x0c05359a */
if(!s->budget--) { s->failed_pc=0x0c05359au; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c05359c;
P_0c05359c: /* original 5323, guest PC 0x0c05359c */
if(!s->budget--) { s->failed_pc=0x0c05359cu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c05359e;
P_0c05359e: /* original 430b, guest PC 0x0c05359e */
if(!s->budget--) { s->failed_pc=0x0c05359eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0535a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535a2u) { target=s->pc; goto dispatch; }
goto P_0c0535a2;
P_0c0535a0: /* original 64b3, guest PC 0x0c0535a0 */
if(!s->budget--) { s->failed_pc=0x0c0535a0u; return 0; }
r[4]=r[11];
goto P_0c0535a2;
P_0c0535a2: /* original 600d, guest PC 0x0c0535a2 */
if(!s->budget--) { s->failed_pc=0x0c0535a2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535a4;
P_0c0535a4: /* original e508, guest PC 0x0c0535a4 */
if(!s->budget--) { s->failed_pc=0x0c0535a4u; return 0; }
r[5]=0x00000008u;
goto P_0c0535a6;
P_0c0535a6: /* original 1e03, guest PC 0x0c0535a6 */
if(!s->budget--) { s->failed_pc=0x0c0535a6u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c0535a8;
P_0c0535a8: /* original 6292, guest PC 0x0c0535a8 */
if(!s->budget--) { s->failed_pc=0x0c0535a8u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535aa;
P_0c0535aa: /* original 5323, guest PC 0x0c0535aa */
if(!s->budget--) { s->failed_pc=0x0c0535aau; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535ac;
P_0c0535ac: /* original 430b, guest PC 0x0c0535ac */
if(!s->budget--) { s->failed_pc=0x0c0535acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0535b0u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535b0u) { target=s->pc; goto dispatch; }
goto P_0c0535b0;
P_0c0535ae: /* original 64b3, guest PC 0x0c0535ae */
if(!s->budget--) { s->failed_pc=0x0c0535aeu; return 0; }
r[4]=r[11];
goto P_0c0535b0;
P_0c0535b0: /* original 600d, guest PC 0x0c0535b0 */
if(!s->budget--) { s->failed_pc=0x0c0535b0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535b2;
P_0c0535b2: /* original e50a, guest PC 0x0c0535b2 */
if(!s->budget--) { s->failed_pc=0x0c0535b2u; return 0; }
r[5]=0x0000000au;
goto P_0c0535b4;
P_0c0535b4: /* original 1e04, guest PC 0x0c0535b4 */
if(!s->budget--) { s->failed_pc=0x0c0535b4u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0535b6;
P_0c0535b6: /* original 6292, guest PC 0x0c0535b6 */
if(!s->budget--) { s->failed_pc=0x0c0535b6u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535b8;
P_0c0535b8: /* original 5323, guest PC 0x0c0535b8 */
if(!s->budget--) { s->failed_pc=0x0c0535b8u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535ba;
P_0c0535ba: /* original 430b, guest PC 0x0c0535ba */
if(!s->budget--) { s->failed_pc=0x0c0535bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0535beu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535beu) { target=s->pc; goto dispatch; }
goto P_0c0535be;
P_0c0535bc: /* original 64b3, guest PC 0x0c0535bc */
if(!s->budget--) { s->failed_pc=0x0c0535bcu; return 0; }
r[4]=r[11];
goto P_0c0535be;
P_0c0535be: /* original 600d, guest PC 0x0c0535be */
if(!s->budget--) { s->failed_pc=0x0c0535beu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535c0;
P_0c0535c0: /* original e50c, guest PC 0x0c0535c0 */
if(!s->budget--) { s->failed_pc=0x0c0535c0u; return 0; }
r[5]=0x0000000cu;
goto P_0c0535c2;
P_0c0535c2: /* original 1e05, guest PC 0x0c0535c2 */
if(!s->budget--) { s->failed_pc=0x0c0535c2u; return 0; }
write(ram,r[14]+20,r[0],4);
goto P_0c0535c4;
P_0c0535c4: /* original 6292, guest PC 0x0c0535c4 */
if(!s->budget--) { s->failed_pc=0x0c0535c4u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535c6;
P_0c0535c6: /* original 5323, guest PC 0x0c0535c6 */
if(!s->budget--) { s->failed_pc=0x0c0535c6u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535c8;
P_0c0535c8: /* original 430b, guest PC 0x0c0535c8 */
if(!s->budget--) { s->failed_pc=0x0c0535c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0535ccu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535ccu) { target=s->pc; goto dispatch; }
goto P_0c0535cc;
P_0c0535ca: /* original 64b3, guest PC 0x0c0535ca */
if(!s->budget--) { s->failed_pc=0x0c0535cau; return 0; }
r[4]=r[11];
goto P_0c0535cc;
P_0c0535cc: /* original 600d, guest PC 0x0c0535cc */
if(!s->budget--) { s->failed_pc=0x0c0535ccu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535ce;
P_0c0535ce: /* original e510, guest PC 0x0c0535ce */
if(!s->budget--) { s->failed_pc=0x0c0535ceu; return 0; }
r[5]=0x00000010u;
goto P_0c0535d0;
P_0c0535d0: /* original 1e06, guest PC 0x0c0535d0 */
if(!s->budget--) { s->failed_pc=0x0c0535d0u; return 0; }
write(ram,r[14]+24,r[0],4);
goto P_0c0535d2;
P_0c0535d2: /* original 6292, guest PC 0x0c0535d2 */
if(!s->budget--) { s->failed_pc=0x0c0535d2u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535d4;
P_0c0535d4: /* original 5323, guest PC 0x0c0535d4 */
if(!s->budget--) { s->failed_pc=0x0c0535d4u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535d6;
P_0c0535d6: /* original 430b, guest PC 0x0c0535d6 */
if(!s->budget--) { s->failed_pc=0x0c0535d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0535dau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535dau) { target=s->pc; goto dispatch; }
goto P_0c0535da;
P_0c0535d8: /* original 64b3, guest PC 0x0c0535d8 */
if(!s->budget--) { s->failed_pc=0x0c0535d8u; return 0; }
r[4]=r[11];
goto P_0c0535da;
P_0c0535da: /* original 600d, guest PC 0x0c0535da */
if(!s->budget--) { s->failed_pc=0x0c0535dau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535dc;
P_0c0535dc: /* original e512, guest PC 0x0c0535dc */
if(!s->budget--) { s->failed_pc=0x0c0535dcu; return 0; }
r[5]=0x00000012u;
goto P_0c0535de;
P_0c0535de: /* original 1e07, guest PC 0x0c0535de */
if(!s->budget--) { s->failed_pc=0x0c0535deu; return 0; }
write(ram,r[14]+28,r[0],4);
goto P_0c0535e0;
P_0c0535e0: /* original 6292, guest PC 0x0c0535e0 */
if(!s->budget--) { s->failed_pc=0x0c0535e0u; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535e2;
P_0c0535e2: /* original 5323, guest PC 0x0c0535e2 */
if(!s->budget--) { s->failed_pc=0x0c0535e2u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535e4;
P_0c0535e4: /* original 430b, guest PC 0x0c0535e4 */
if(!s->budget--) { s->failed_pc=0x0c0535e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0535e8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535e8u) { target=s->pc; goto dispatch; }
goto P_0c0535e8;
P_0c0535e6: /* original 64b3, guest PC 0x0c0535e6 */
if(!s->budget--) { s->failed_pc=0x0c0535e6u; return 0; }
r[4]=r[11];
goto P_0c0535e8;
P_0c0535e8: /* original 600d, guest PC 0x0c0535e8 */
if(!s->budget--) { s->failed_pc=0x0c0535e8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535ea;
P_0c0535ea: /* original e514, guest PC 0x0c0535ea */
if(!s->budget--) { s->failed_pc=0x0c0535eau; return 0; }
r[5]=0x00000014u;
goto P_0c0535ec;
P_0c0535ec: /* original 1e08, guest PC 0x0c0535ec */
if(!s->budget--) { s->failed_pc=0x0c0535ecu; return 0; }
write(ram,r[14]+32,r[0],4);
goto P_0c0535ee;
P_0c0535ee: /* original 6292, guest PC 0x0c0535ee */
if(!s->budget--) { s->failed_pc=0x0c0535eeu; return 0; }
tmp=read(ram,r[9],4);
r[2]=tmp;
goto P_0c0535f0;
P_0c0535f0: /* original 5323, guest PC 0x0c0535f0 */
if(!s->budget--) { s->failed_pc=0x0c0535f0u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0535f2;
P_0c0535f2: /* original 430b, guest PC 0x0c0535f2 */
if(!s->budget--) { s->failed_pc=0x0c0535f2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0535f6u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0535f6u) { target=s->pc; goto dispatch; }
goto P_0c0535f6;
P_0c0535f4: /* original 64b3, guest PC 0x0c0535f4 */
if(!s->budget--) { s->failed_pc=0x0c0535f4u; return 0; }
r[4]=r[11];
goto P_0c0535f6;
P_0c0535f6: /* original 600d, guest PC 0x0c0535f6 */
if(!s->budget--) { s->failed_pc=0x0c0535f6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0535f8;
P_0c0535f8: /* original 1e0d, guest PC 0x0c0535f8 */
if(!s->budget--) { s->failed_pc=0x0c0535f8u; return 0; }
write(ram,r[14]+52,r[0],4);
goto P_0c0535fa;
P_0c0535fa: /* original 9272, guest PC 0x0c0535fa */
if(!s->budget--) { s->failed_pc=0x0c0535fau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0536e2u,2);
goto P_0c0535fc;
P_0c0535fc: /* original 1e2e, guest PC 0x0c0535fc */
if(!s->budget--) { s->failed_pc=0x0c0535fcu; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0535fe;
P_0c0535fe: /* original 84be, guest PC 0x0c0535fe */
if(!s->budget--) { s->failed_pc=0x0c0535feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+14,1);
goto P_0c053600;
P_0c053600: /* original 600c, guest PC 0x0c053600 */
if(!s->budget--) { s->failed_pc=0x0c053600u; return 0; }
r[0]=r[0]&255u;
goto P_0c053602;
P_0c053602: /* original 1e09, guest PC 0x0c053602 */
if(!s->budget--) { s->failed_pc=0x0c053602u; return 0; }
write(ram,r[14]+36,r[0],4);
goto P_0c053604;
P_0c053604: /* original 84bf, guest PC 0x0c053604 */
if(!s->budget--) { s->failed_pc=0x0c053604u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+15,1);
goto P_0c053606;
P_0c053606: /* original 600c, guest PC 0x0c053606 */
if(!s->budget--) { s->failed_pc=0x0c053606u; return 0; }
r[0]=r[0]&255u;
goto P_0c053608;
P_0c053608: /* original 1e0a, guest PC 0x0c053608 */
if(!s->budget--) { s->failed_pc=0x0c053608u; return 0; }
write(ram,r[14]+40,r[0],4);
goto P_0c05360a;
P_0c05360a: /* original 936b, guest PC 0x0c05360a */
if(!s->budget--) { s->failed_pc=0x0c05360au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0536e4u,2);
goto P_0c05360c;
P_0c05360c: /* original 1e3b, guest PC 0x0c05360c */
if(!s->budget--) { s->failed_pc=0x0c05360cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c05360e;
P_0c05360e: /* original d237, guest PC 0x0c05360e */
if(!s->budget--) { s->failed_pc=0x0c05360eu; return 0; }
r[2]=read(ram,0x0c0536ecu,4);
goto P_0c053610;
P_0c053610: /* original 420b, guest PC 0x0c053610 */
if(!s->budget--) { s->failed_pc=0x0c053610u; return 0; }
target=r[2];
r[16]=code_base|0x0c053614u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053614u) { target=s->pc; goto dispatch; }
goto P_0c053614;
P_0c053612: /* original 64c3, guest PC 0x0c053612 */
if(!s->budget--) { s->failed_pc=0x0c053612u; return 0; }
r[4]=r[12];
goto P_0c053614;
P_0c053614: /* original d336, guest PC 0x0c053614 */
if(!s->budget--) { s->failed_pc=0x0c053614u; return 0; }
r[3]=read(ram,0x0c0536f0u,4);
goto P_0c053616;
P_0c053616: /* original 64f3, guest PC 0x0c053616 */
if(!s->budget--) { s->failed_pc=0x0c053616u; return 0; }
r[4]=r[15];
goto P_0c053618;
P_0c053618: /* original 6503, guest PC 0x0c053618 */
if(!s->budget--) { s->failed_pc=0x0c053618u; return 0; }
r[5]=r[0];
goto P_0c05361a;
P_0c05361a: /* original 430b, guest PC 0x0c05361a */
if(!s->budget--) { s->failed_pc=0x0c05361au; return 0; }
target=r[3];
r[16]=code_base|0x0c05361eu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05361eu) { target=s->pc; goto dispatch; }
goto P_0c05361e;
P_0c05361c: /* original 7408, guest PC 0x0c05361c */
if(!s->budget--) { s->failed_pc=0x0c05361cu; return 0; }
r[4]+=0x00000008u;
goto P_0c05361e;
P_0c05361e: /* original 4011, guest PC 0x0c05361e */
if(!s->budget--) { s->failed_pc=0x0c05361eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c053620;
P_0c053620: /* original 8901, guest PC 0x0c053620 */
if(!s->budget--) { s->failed_pc=0x0c053620u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053626; }
goto P_0c053622;
P_0c053622: /* original a0a6, guest PC 0x0c053622 */
if(!s->budget--) { s->failed_pc=0x0c053622u; return 0; }
goto P_0c053772;
P_0c053624: /* original 0009, guest PC 0x0c053624 */
if(!s->budget--) { s->failed_pc=0x0c053624u; return 0; }
goto P_0c053626;
P_0c053626: /* original 85f7, guest PC 0x0c053626 */
if(!s->budget--) { s->failed_pc=0x0c053626u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+14,2);
goto P_0c053628;
P_0c053628: /* original e140, guest PC 0x0c053628 */
if(!s->budget--) { s->failed_pc=0x0c053628u; return 0; }
r[1]=0x00000040u;
goto P_0c05362a;
P_0c05362a: /* original 31ec, guest PC 0x0c05362a */
if(!s->budget--) { s->failed_pc=0x0c05362au; return 0; }
r[1]+=r[14];
goto P_0c05362c;
P_0c05362c: /* original 600d, guest PC 0x0c05362c */
if(!s->budget--) { s->failed_pc=0x0c05362cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05362e;
P_0c05362e: /* original 1e0f, guest PC 0x0c05362e */
if(!s->budget--) { s->failed_pc=0x0c05362eu; return 0; }
write(ram,r[14]+60,r[0],4);
goto P_0c053630;
P_0c053630: /* original 85f6, guest PC 0x0c053630 */
if(!s->budget--) { s->failed_pc=0x0c053630u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c053632;
P_0c053632: /* original 600d, guest PC 0x0c053632 */
if(!s->budget--) { s->failed_pc=0x0c053632u; return 0; }
r[0]=r[0]&65535u;
goto P_0c053634;
P_0c053634: /* original 2102, guest PC 0x0c053634 */
if(!s->budget--) { s->failed_pc=0x0c053634u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c053636;
P_0c053636: /* original 85f7, guest PC 0x0c053636 */
if(!s->budget--) { s->failed_pc=0x0c053636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+14,2);
goto P_0c053638;
P_0c053638: /* original d32e, guest PC 0x0c053638 */
if(!s->budget--) { s->failed_pc=0x0c053638u; return 0; }
r[3]=read(ram,0x0c0536f4u,4);
goto P_0c05363a;
P_0c05363a: /* original 9454, guest PC 0x0c05363a */
if(!s->budget--) { s->failed_pc=0x0c05363au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0536e6u,2);
goto P_0c05363c;
P_0c05363c: /* original 600d, guest PC 0x0c05363c */
if(!s->budget--) { s->failed_pc=0x0c05363cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05363e;
P_0c05363e: /* original 430b, guest PC 0x0c05363e */
if(!s->budget--) { s->failed_pc=0x0c05363eu; return 0; }
target=r[3];
r[16]=code_base|0x0c053642u;
r[1]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053642u) { target=s->pc; goto dispatch; }
goto P_0c053642;
P_0c053640: /* original 6143, guest PC 0x0c053640 */
if(!s->budget--) { s->failed_pc=0x0c053640u; return 0; }
r[1]=r[4];
goto P_0c053642;
P_0c053642: /* original e144, guest PC 0x0c053642 */
if(!s->budget--) { s->failed_pc=0x0c053642u; return 0; }
r[1]=0x00000044u;
goto P_0c053644;
P_0c053644: /* original 31ec, guest PC 0x0c053644 */
if(!s->budget--) { s->failed_pc=0x0c053644u; return 0; }
r[1]+=r[14];
goto P_0c053646;
P_0c053646: /* original 2102, guest PC 0x0c053646 */
if(!s->budget--) { s->failed_pc=0x0c053646u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c053648;
P_0c053648: /* original 85f6, guest PC 0x0c053648 */
if(!s->budget--) { s->failed_pc=0x0c053648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c05364a;
P_0c05364a: /* original d32a, guest PC 0x0c05364a */
if(!s->budget--) { s->failed_pc=0x0c05364au; return 0; }
r[3]=read(ram,0x0c0536f4u,4);
goto P_0c05364c;
P_0c05364c: /* original 600d, guest PC 0x0c05364c */
if(!s->budget--) { s->failed_pc=0x0c05364cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05364e;
P_0c05364e: /* original 430b, guest PC 0x0c05364e */
if(!s->budget--) { s->failed_pc=0x0c05364eu; return 0; }
target=r[3];
r[16]=code_base|0x0c053652u;
r[1]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053652u) { target=s->pc; goto dispatch; }
goto P_0c053652;
P_0c053650: /* original 6143, guest PC 0x0c053650 */
if(!s->budget--) { s->failed_pc=0x0c053650u; return 0; }
r[1]=r[4];
goto P_0c053652;
P_0c053652: /* original e148, guest PC 0x0c053652 */
if(!s->budget--) { s->failed_pc=0x0c053652u; return 0; }
r[1]=0x00000048u;
goto P_0c053654;
P_0c053654: /* original 31ec, guest PC 0x0c053654 */
if(!s->budget--) { s->failed_pc=0x0c053654u; return 0; }
r[1]+=r[14];
goto P_0c053656;
P_0c053656: /* original 2102, guest PC 0x0c053656 */
if(!s->budget--) { s->failed_pc=0x0c053656u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c053658;
P_0c053658: /* original 53f1, guest PC 0x0c053658 */
if(!s->budget--) { s->failed_pc=0x0c053658u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05365a;
P_0c05365a: /* original 2f36, guest PC 0x0c05365a */
if(!s->budget--) { s->failed_pc=0x0c05365au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05365c;
P_0c05365c: /* original d226, guest PC 0x0c05365c */
if(!s->budget--) { s->failed_pc=0x0c05365cu; return 0; }
r[2]=read(ram,0x0c0536f8u,4);
goto P_0c05365e;
P_0c05365e: /* original 4d0b, guest PC 0x0c05365e */
if(!s->budget--) { s->failed_pc=0x0c05365eu; return 0; }
target=r[13];
r[16]=code_base|0x0c053662u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053662u) { target=s->pc; goto dispatch; }
goto P_0c053662;
P_0c053660: /* original 2f26, guest PC 0x0c053660 */
if(!s->budget--) { s->failed_pc=0x0c053660u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053662;
P_0c053662: /* original 63e2, guest PC 0x0c053662 */
if(!s->budget--) { s->failed_pc=0x0c053662u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c053664;
P_0c053664: /* original 2f36, guest PC 0x0c053664 */
if(!s->budget--) { s->failed_pc=0x0c053664u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053666;
P_0c053666: /* original d225, guest PC 0x0c053666 */
if(!s->budget--) { s->failed_pc=0x0c053666u; return 0; }
r[2]=read(ram,0x0c0536fcu,4);
goto P_0c053668;
P_0c053668: /* original 4d0b, guest PC 0x0c053668 */
if(!s->budget--) { s->failed_pc=0x0c053668u; return 0; }
target=r[13];
r[16]=code_base|0x0c05366cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05366cu) { target=s->pc; goto dispatch; }
goto P_0c05366c;
P_0c05366a: /* original 2f26, guest PC 0x0c05366a */
if(!s->budget--) { s->failed_pc=0x0c05366au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05366c;
P_0c05366c: /* original 53e1, guest PC 0x0c05366c */
if(!s->budget--) { s->failed_pc=0x0c05366cu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c05366e;
P_0c05366e: /* original 2f36, guest PC 0x0c05366e */
if(!s->budget--) { s->failed_pc=0x0c05366eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053670;
P_0c053670: /* original d223, guest PC 0x0c053670 */
if(!s->budget--) { s->failed_pc=0x0c053670u; return 0; }
r[2]=read(ram,0x0c053700u,4);
goto P_0c053672;
P_0c053672: /* original 4d0b, guest PC 0x0c053672 */
if(!s->budget--) { s->failed_pc=0x0c053672u; return 0; }
target=r[13];
r[16]=code_base|0x0c053676u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053676u) { target=s->pc; goto dispatch; }
goto P_0c053676;
P_0c053674: /* original 2f26, guest PC 0x0c053674 */
if(!s->budget--) { s->failed_pc=0x0c053674u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053676;
P_0c053676: /* original 53e2, guest PC 0x0c053676 */
if(!s->budget--) { s->failed_pc=0x0c053676u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c053678;
P_0c053678: /* original 2f36, guest PC 0x0c053678 */
if(!s->budget--) { s->failed_pc=0x0c053678u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05367a;
P_0c05367a: /* original d222, guest PC 0x0c05367a */
if(!s->budget--) { s->failed_pc=0x0c05367au; return 0; }
r[2]=read(ram,0x0c053704u,4);
goto P_0c05367c;
P_0c05367c: /* original 4d0b, guest PC 0x0c05367c */
if(!s->budget--) { s->failed_pc=0x0c05367cu; return 0; }
target=r[13];
r[16]=code_base|0x0c053680u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053680u) { target=s->pc; goto dispatch; }
goto P_0c053680;
P_0c05367e: /* original 2f26, guest PC 0x0c05367e */
if(!s->budget--) { s->failed_pc=0x0c05367eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053680;
P_0c053680: /* original 53e3, guest PC 0x0c053680 */
if(!s->budget--) { s->failed_pc=0x0c053680u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c053682;
P_0c053682: /* original 2f36, guest PC 0x0c053682 */
if(!s->budget--) { s->failed_pc=0x0c053682u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053684;
P_0c053684: /* original d220, guest PC 0x0c053684 */
if(!s->budget--) { s->failed_pc=0x0c053684u; return 0; }
r[2]=read(ram,0x0c053708u,4);
goto P_0c053686;
P_0c053686: /* original 4d0b, guest PC 0x0c053686 */
if(!s->budget--) { s->failed_pc=0x0c053686u; return 0; }
target=r[13];
r[16]=code_base|0x0c05368au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05368au) { target=s->pc; goto dispatch; }
goto P_0c05368a;
P_0c053688: /* original 2f26, guest PC 0x0c053688 */
if(!s->budget--) { s->failed_pc=0x0c053688u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05368a;
P_0c05368a: /* original 53e4, guest PC 0x0c05368a */
if(!s->budget--) { s->failed_pc=0x0c05368au; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c05368c;
P_0c05368c: /* original 2f36, guest PC 0x0c05368c */
if(!s->budget--) { s->failed_pc=0x0c05368cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05368e;
P_0c05368e: /* original d21f, guest PC 0x0c05368e */
if(!s->budget--) { s->failed_pc=0x0c05368eu; return 0; }
r[2]=read(ram,0x0c05370cu,4);
goto P_0c053690;
P_0c053690: /* original 4d0b, guest PC 0x0c053690 */
if(!s->budget--) { s->failed_pc=0x0c053690u; return 0; }
target=r[13];
r[16]=code_base|0x0c053694u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053694u) { target=s->pc; goto dispatch; }
goto P_0c053694;
P_0c053692: /* original 2f26, guest PC 0x0c053692 */
if(!s->budget--) { s->failed_pc=0x0c053692u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053694;
P_0c053694: /* original 53e5, guest PC 0x0c053694 */
if(!s->budget--) { s->failed_pc=0x0c053694u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c053696;
P_0c053696: /* original 2f36, guest PC 0x0c053696 */
if(!s->budget--) { s->failed_pc=0x0c053696u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053698;
P_0c053698: /* original d21d, guest PC 0x0c053698 */
if(!s->budget--) { s->failed_pc=0x0c053698u; return 0; }
r[2]=read(ram,0x0c053710u,4);
goto P_0c05369a;
P_0c05369a: /* original 4d0b, guest PC 0x0c05369a */
if(!s->budget--) { s->failed_pc=0x0c05369au; return 0; }
target=r[13];
r[16]=code_base|0x0c05369eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05369eu) { target=s->pc; goto dispatch; }
goto P_0c05369e;
P_0c05369c: /* original 2f26, guest PC 0x0c05369c */
if(!s->budget--) { s->failed_pc=0x0c05369cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05369e;
P_0c05369e: /* original 53e6, guest PC 0x0c05369e */
if(!s->budget--) { s->failed_pc=0x0c05369eu; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0536a0;
P_0c0536a0: /* original 2f36, guest PC 0x0c0536a0 */
if(!s->budget--) { s->failed_pc=0x0c0536a0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536a2;
P_0c0536a2: /* original d21c, guest PC 0x0c0536a2 */
if(!s->budget--) { s->failed_pc=0x0c0536a2u; return 0; }
r[2]=read(ram,0x0c053714u,4);
goto P_0c0536a4;
P_0c0536a4: /* original 4d0b, guest PC 0x0c0536a4 */
if(!s->budget--) { s->failed_pc=0x0c0536a4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0536a8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536a8u) { target=s->pc; goto dispatch; }
goto P_0c0536a8;
P_0c0536a6: /* original 2f26, guest PC 0x0c0536a6 */
if(!s->budget--) { s->failed_pc=0x0c0536a6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536a8;
P_0c0536a8: /* original 53e7, guest PC 0x0c0536a8 */
if(!s->budget--) { s->failed_pc=0x0c0536a8u; return 0; }
r[3]=read(ram,r[14]+28,4);
goto P_0c0536aa;
P_0c0536aa: /* original 2f36, guest PC 0x0c0536aa */
if(!s->budget--) { s->failed_pc=0x0c0536aau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536ac;
P_0c0536ac: /* original d21a, guest PC 0x0c0536ac */
if(!s->budget--) { s->failed_pc=0x0c0536acu; return 0; }
r[2]=read(ram,0x0c053718u,4);
goto P_0c0536ae;
P_0c0536ae: /* original 4d0b, guest PC 0x0c0536ae */
if(!s->budget--) { s->failed_pc=0x0c0536aeu; return 0; }
target=r[13];
r[16]=code_base|0x0c0536b2u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536b2u) { target=s->pc; goto dispatch; }
goto P_0c0536b2;
P_0c0536b0: /* original 2f26, guest PC 0x0c0536b0 */
if(!s->budget--) { s->failed_pc=0x0c0536b0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536b2;
P_0c0536b2: /* original 53e8, guest PC 0x0c0536b2 */
if(!s->budget--) { s->failed_pc=0x0c0536b2u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0536b4;
P_0c0536b4: /* original 2f36, guest PC 0x0c0536b4 */
if(!s->budget--) { s->failed_pc=0x0c0536b4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536b6;
P_0c0536b6: /* original d219, guest PC 0x0c0536b6 */
if(!s->budget--) { s->failed_pc=0x0c0536b6u; return 0; }
r[2]=read(ram,0x0c05371cu,4);
goto P_0c0536b8;
P_0c0536b8: /* original 4d0b, guest PC 0x0c0536b8 */
if(!s->budget--) { s->failed_pc=0x0c0536b8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0536bcu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536bcu) { target=s->pc; goto dispatch; }
goto P_0c0536bc;
P_0c0536ba: /* original 2f26, guest PC 0x0c0536ba */
if(!s->budget--) { s->failed_pc=0x0c0536bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536bc;
P_0c0536bc: /* original 53ed, guest PC 0x0c0536bc */
if(!s->budget--) { s->failed_pc=0x0c0536bcu; return 0; }
r[3]=read(ram,r[14]+52,4);
goto P_0c0536be;
P_0c0536be: /* original 2f36, guest PC 0x0c0536be */
if(!s->budget--) { s->failed_pc=0x0c0536beu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536c0;
P_0c0536c0: /* original d217, guest PC 0x0c0536c0 */
if(!s->budget--) { s->failed_pc=0x0c0536c0u; return 0; }
r[2]=read(ram,0x0c053720u,4);
goto P_0c0536c2;
P_0c0536c2: /* original 4d0b, guest PC 0x0c0536c2 */
if(!s->budget--) { s->failed_pc=0x0c0536c2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0536c6u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536c6u) { target=s->pc; goto dispatch; }
goto P_0c0536c6;
P_0c0536c4: /* original 2f26, guest PC 0x0c0536c4 */
if(!s->budget--) { s->failed_pc=0x0c0536c4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536c6;
P_0c0536c6: /* original 53ee, guest PC 0x0c0536c6 */
if(!s->budget--) { s->failed_pc=0x0c0536c6u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c0536c8;
P_0c0536c8: /* original 2f36, guest PC 0x0c0536c8 */
if(!s->budget--) { s->failed_pc=0x0c0536c8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536ca;
P_0c0536ca: /* original d216, guest PC 0x0c0536ca */
if(!s->budget--) { s->failed_pc=0x0c0536cau; return 0; }
r[2]=read(ram,0x0c053724u,4);
goto P_0c0536cc;
P_0c0536cc: /* original 4d0b, guest PC 0x0c0536cc */
if(!s->budget--) { s->failed_pc=0x0c0536ccu; return 0; }
target=r[13];
r[16]=code_base|0x0c0536d0u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536d0u) { target=s->pc; goto dispatch; }
goto P_0c0536d0;
P_0c0536ce: /* original 2f26, guest PC 0x0c0536ce */
if(!s->budget--) { s->failed_pc=0x0c0536ceu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536d0;
P_0c0536d0: /* original 53e9, guest PC 0x0c0536d0 */
if(!s->budget--) { s->failed_pc=0x0c0536d0u; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c0536d2;
P_0c0536d2: /* original 2f36, guest PC 0x0c0536d2 */
if(!s->budget--) { s->failed_pc=0x0c0536d2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536d4;
P_0c0536d4: /* original d214, guest PC 0x0c0536d4 */
if(!s->budget--) { s->failed_pc=0x0c0536d4u; return 0; }
r[2]=read(ram,0x0c053728u,4);
goto P_0c0536d6;
P_0c0536d6: /* original 4d0b, guest PC 0x0c0536d6 */
if(!s->budget--) { s->failed_pc=0x0c0536d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0536dau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0536dau) { target=s->pc; goto dispatch; }
goto P_0c0536da;
P_0c0536d8: /* original 2f26, guest PC 0x0c0536d8 */
if(!s->budget--) { s->failed_pc=0x0c0536d8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536da;
P_0c0536da: /* original 53ea, guest PC 0x0c0536da */
if(!s->budget--) { s->failed_pc=0x0c0536dau; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c0536dc;
P_0c0536dc: /* original 2f36, guest PC 0x0c0536dc */
if(!s->budget--) { s->failed_pc=0x0c0536dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0536de;
P_0c0536de: /* original a025, guest PC 0x0c0536de */
if(!s->budget--) { s->failed_pc=0x0c0536deu; return 0; }
goto P_0c05372c;
P_0c0536e0: /* original 0009, guest PC 0x0c0536e0 */
if(!s->budget--) { s->failed_pc=0x0c0536e0u; return 0; }
if(!vf3_matrix_family(0x0c0536e2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0536e2u; return 0; } return 1;
P_0c05372c: /* original d24c, guest PC 0x0c05372c */
if(!s->budget--) { s->failed_pc=0x0c05372cu; return 0; }
r[2]=read(ram,0x0c053860u,4);
goto P_0c05372e;
P_0c05372e: /* original 4d0b, guest PC 0x0c05372e */
if(!s->budget--) { s->failed_pc=0x0c05372eu; return 0; }
target=r[13];
r[16]=code_base|0x0c053732u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053732u) { target=s->pc; goto dispatch; }
goto P_0c053732;
P_0c053730: /* original 2f26, guest PC 0x0c053730 */
if(!s->budget--) { s->failed_pc=0x0c053730u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053732;
P_0c053732: /* original 53eb, guest PC 0x0c053732 */
if(!s->budget--) { s->failed_pc=0x0c053732u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c053734;
P_0c053734: /* original 2f36, guest PC 0x0c053734 */
if(!s->budget--) { s->failed_pc=0x0c053734u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053736;
P_0c053736: /* original d24b, guest PC 0x0c053736 */
if(!s->budget--) { s->failed_pc=0x0c053736u; return 0; }
r[2]=read(ram,0x0c053864u,4);
goto P_0c053738;
P_0c053738: /* original 4d0b, guest PC 0x0c053738 */
if(!s->budget--) { s->failed_pc=0x0c053738u; return 0; }
target=r[13];
r[16]=code_base|0x0c05373cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05373cu) { target=s->pc; goto dispatch; }
goto P_0c05373c;
P_0c05373a: /* original 2f26, guest PC 0x0c05373a */
if(!s->budget--) { s->failed_pc=0x0c05373au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05373c;
P_0c05373c: /* original 53ef, guest PC 0x0c05373c */
if(!s->budget--) { s->failed_pc=0x0c05373cu; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c05373e;
P_0c05373e: /* original 7f78, guest PC 0x0c05373e */
if(!s->budget--) { s->failed_pc=0x0c05373eu; return 0; }
r[15]+=0x00000078u;
goto P_0c053740;
P_0c053740: /* original 2f36, guest PC 0x0c053740 */
if(!s->budget--) { s->failed_pc=0x0c053740u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053742;
P_0c053742: /* original d249, guest PC 0x0c053742 */
if(!s->budget--) { s->failed_pc=0x0c053742u; return 0; }
r[2]=read(ram,0x0c053868u,4);
goto P_0c053744;
P_0c053744: /* original 4d0b, guest PC 0x0c053744 */
if(!s->budget--) { s->failed_pc=0x0c053744u; return 0; }
target=r[13];
r[16]=code_base|0x0c053748u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053748u) { target=s->pc; goto dispatch; }
goto P_0c053748;
P_0c053746: /* original 2f26, guest PC 0x0c053746 */
if(!s->budget--) { s->failed_pc=0x0c053746u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053748;
P_0c053748: /* original e040, guest PC 0x0c053748 */
if(!s->budget--) { s->failed_pc=0x0c053748u; return 0; }
r[0]=0x00000040u;
goto P_0c05374a;
P_0c05374a: /* original 03ee, guest PC 0x0c05374a */
if(!s->budget--) { s->failed_pc=0x0c05374au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05374c;
P_0c05374c: /* original 2f36, guest PC 0x0c05374c */
if(!s->budget--) { s->failed_pc=0x0c05374cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05374e;
P_0c05374e: /* original d247, guest PC 0x0c05374e */
if(!s->budget--) { s->failed_pc=0x0c05374eu; return 0; }
r[2]=read(ram,0x0c05386cu,4);
goto P_0c053750;
P_0c053750: /* original 4d0b, guest PC 0x0c053750 */
if(!s->budget--) { s->failed_pc=0x0c053750u; return 0; }
target=r[13];
r[16]=code_base|0x0c053754u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053754u) { target=s->pc; goto dispatch; }
goto P_0c053754;
P_0c053752: /* original 2f26, guest PC 0x0c053752 */
if(!s->budget--) { s->failed_pc=0x0c053752u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053754;
P_0c053754: /* original e044, guest PC 0x0c053754 */
if(!s->budget--) { s->failed_pc=0x0c053754u; return 0; }
r[0]=0x00000044u;
goto P_0c053756;
P_0c053756: /* original 03ee, guest PC 0x0c053756 */
if(!s->budget--) { s->failed_pc=0x0c053756u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c053758;
P_0c053758: /* original 2f36, guest PC 0x0c053758 */
if(!s->budget--) { s->failed_pc=0x0c053758u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05375a;
P_0c05375a: /* original d245, guest PC 0x0c05375a */
if(!s->budget--) { s->failed_pc=0x0c05375au; return 0; }
r[2]=read(ram,0x0c053870u,4);
goto P_0c05375c;
P_0c05375c: /* original 4d0b, guest PC 0x0c05375c */
if(!s->budget--) { s->failed_pc=0x0c05375cu; return 0; }
target=r[13];
r[16]=code_base|0x0c053760u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053760u) { target=s->pc; goto dispatch; }
goto P_0c053760;
P_0c05375e: /* original 2f26, guest PC 0x0c05375e */
if(!s->budget--) { s->failed_pc=0x0c05375eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053760;
P_0c053760: /* original e048, guest PC 0x0c053760 */
if(!s->budget--) { s->failed_pc=0x0c053760u; return 0; }
r[0]=0x00000048u;
goto P_0c053762;
P_0c053762: /* original 03ee, guest PC 0x0c053762 */
if(!s->budget--) { s->failed_pc=0x0c053762u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c053764;
P_0c053764: /* original 2f36, guest PC 0x0c053764 */
if(!s->budget--) { s->failed_pc=0x0c053764u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053766;
P_0c053766: /* original d243, guest PC 0x0c053766 */
if(!s->budget--) { s->failed_pc=0x0c053766u; return 0; }
r[2]=read(ram,0x0c053874u,4);
goto P_0c053768;
P_0c053768: /* original 4d0b, guest PC 0x0c053768 */
if(!s->budget--) { s->failed_pc=0x0c053768u; return 0; }
target=r[13];
r[16]=code_base|0x0c05376cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05376cu) { target=s->pc; goto dispatch; }
goto P_0c05376c;
P_0c05376a: /* original 2f26, guest PC 0x0c05376a */
if(!s->budget--) { s->failed_pc=0x0c05376au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05376c;
P_0c05376c: /* original 7f20, guest PC 0x0c05376c */
if(!s->budget--) { s->failed_pc=0x0c05376cu; return 0; }
r[15]+=0x00000020u;
goto P_0c05376e;
P_0c05376e: /* original a005, guest PC 0x0c05376e */
if(!s->budget--) { s->failed_pc=0x0c05376eu; return 0; }
r[0]=0x00000000u;
goto P_0c05377c;
P_0c053770: /* original e000, guest PC 0x0c053770 */
if(!s->budget--) { s->failed_pc=0x0c053770u; return 0; }
r[0]=0x00000000u;
goto P_0c053772;
P_0c053772: /* original 4d0b, guest PC 0x0c053772 */
if(!s->budget--) { s->failed_pc=0x0c053772u; return 0; }
target=r[13];
r[16]=code_base|0x0c053776u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053776u) { target=s->pc; goto dispatch; }
goto P_0c053776;
P_0c053774: /* original 2f86, guest PC 0x0c053774 */
if(!s->budget--) { s->failed_pc=0x0c053774u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053776;
P_0c053776: /* original 4a0b, guest PC 0x0c053776 */
if(!s->budget--) { s->failed_pc=0x0c053776u; return 0; }
target=r[10];
r[16]=code_base|0x0c05377au;
r[15]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05377au) { target=s->pc; goto dispatch; }
goto P_0c05377a;
P_0c053778: /* original 7f04, guest PC 0x0c053778 */
if(!s->budget--) { s->failed_pc=0x0c053778u; return 0; }
r[15]+=0x00000004u;
goto P_0c05377a;
P_0c05377a: /* original 906f, guest PC 0x0c05377a */
if(!s->budget--) { s->failed_pc=0x0c05377au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05385cu,2);
goto P_0c05377c;
P_0c05377c: /* original 7f14, guest PC 0x0c05377c */
if(!s->budget--) { s->failed_pc=0x0c05377cu; return 0; }
r[15]+=0x00000014u;
goto P_0c05377e;
P_0c05377e: /* original 4f26, guest PC 0x0c05377e */
if(!s->budget--) { s->failed_pc=0x0c05377eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053780;
P_0c053780: /* original 68f6, guest PC 0x0c053780 */
if(!s->budget--) { s->failed_pc=0x0c053780u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c053782;
P_0c053782: /* original 69f6, guest PC 0x0c053782 */
if(!s->budget--) { s->failed_pc=0x0c053782u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c053784;
P_0c053784: /* original 6af6, guest PC 0x0c053784 */
if(!s->budget--) { s->failed_pc=0x0c053784u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c053786;
P_0c053786: /* original 6bf6, guest PC 0x0c053786 */
if(!s->budget--) { s->failed_pc=0x0c053786u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c053788;
P_0c053788: /* original 6cf6, guest PC 0x0c053788 */
if(!s->budget--) { s->failed_pc=0x0c053788u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05378a;
P_0c05378a: /* original 6df6, guest PC 0x0c05378a */
if(!s->budget--) { s->failed_pc=0x0c05378au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05378c;
P_0c05378c: /* original 000b, guest PC 0x0c05378c */
if(!s->budget--) { s->failed_pc=0x0c05378cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05378e: /* original 6ef6, guest PC 0x0c05378e */
if(!s->budget--) { s->failed_pc=0x0c05378eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053790u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
