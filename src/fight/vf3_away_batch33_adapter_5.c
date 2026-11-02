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
int vf3_away_batch33_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0671aau: goto P_0c0671aa;
case 0x0c0671acu: goto P_0c0671ac;
case 0x0c0671d8u: goto P_0c0671d8;
case 0x0c0671dau: goto P_0c0671da;
case 0x0c0671dcu: goto P_0c0671dc;
case 0x0c0671deu: goto P_0c0671de;
case 0x0c0671e0u: goto P_0c0671e0;
case 0x0c0671e2u: goto P_0c0671e2;
case 0x0c0671e4u: goto P_0c0671e4;
case 0x0c0671e6u: goto P_0c0671e6;
case 0x0c0671e8u: goto P_0c0671e8;
case 0x0c0671eau: goto P_0c0671ea;
case 0x0c0671ecu: goto P_0c0671ec;
case 0x0c0671eeu: goto P_0c0671ee;
case 0x0c0671f0u: goto P_0c0671f0;
case 0x0c0671f2u: goto P_0c0671f2;
case 0x0c0671f4u: goto P_0c0671f4;
case 0x0c0671f6u: goto P_0c0671f6;
case 0x0c0671f8u: goto P_0c0671f8;
case 0x0c0671fau: goto P_0c0671fa;
case 0x0c0671fcu: goto P_0c0671fc;
case 0x0c0671feu: goto P_0c0671fe;
case 0x0c067200u: goto P_0c067200;
case 0x0c067202u: goto P_0c067202;
case 0x0c067204u: goto P_0c067204;
case 0x0c067206u: goto P_0c067206;
case 0x0c067208u: goto P_0c067208;
case 0x0c06720au: goto P_0c06720a;
case 0x0c06720cu: goto P_0c06720c;
case 0x0c06720eu: goto P_0c06720e;
case 0x0c067210u: goto P_0c067210;
case 0x0c067212u: goto P_0c067212;
case 0x0c067214u: goto P_0c067214;
case 0x0c067216u: goto P_0c067216;
case 0x0c067218u: goto P_0c067218;
case 0x0c06721au: goto P_0c06721a;
case 0x0c06721cu: goto P_0c06721c;
case 0x0c06721eu: goto P_0c06721e;
case 0x0c067220u: goto P_0c067220;
case 0x0c067222u: goto P_0c067222;
case 0x0c067224u: goto P_0c067224;
case 0x0c067226u: goto P_0c067226;
case 0x0c067228u: goto P_0c067228;
case 0x0c06722au: goto P_0c06722a;
case 0x0c06722cu: goto P_0c06722c;
case 0x0c06722eu: goto P_0c06722e;
case 0x0c067230u: goto P_0c067230;
case 0x0c067232u: goto P_0c067232;
case 0x0c067234u: goto P_0c067234;
case 0x0c067236u: goto P_0c067236;
case 0x0c067238u: goto P_0c067238;
case 0x0c06723au: goto P_0c06723a;
case 0x0c06723cu: goto P_0c06723c;
case 0x0c06723eu: goto P_0c06723e;
case 0x0c067240u: goto P_0c067240;
case 0x0c067242u: goto P_0c067242;
case 0x0c067244u: goto P_0c067244;
case 0x0c067246u: goto P_0c067246;
case 0x0c067248u: goto P_0c067248;
case 0x0c06724au: goto P_0c06724a;
case 0x0c06724cu: goto P_0c06724c;
case 0x0c06724eu: goto P_0c06724e;
case 0x0c067250u: goto P_0c067250;
case 0x0c067252u: goto P_0c067252;
case 0x0c067254u: goto P_0c067254;
case 0x0c067256u: goto P_0c067256;
case 0x0c067258u: goto P_0c067258;
case 0x0c06725au: goto P_0c06725a;
case 0x0c06725cu: goto P_0c06725c;
case 0x0c06725eu: goto P_0c06725e;
case 0x0c067260u: goto P_0c067260;
case 0x0c067262u: goto P_0c067262;
case 0x0c067264u: goto P_0c067264;
case 0x0c067266u: goto P_0c067266;
case 0x0c067268u: goto P_0c067268;
case 0x0c06726au: goto P_0c06726a;
case 0x0c06726cu: goto P_0c06726c;
case 0x0c06726eu: goto P_0c06726e;
case 0x0c067270u: goto P_0c067270;
case 0x0c067272u: goto P_0c067272;
case 0x0c067274u: goto P_0c067274;
case 0x0c067276u: goto P_0c067276;
case 0x0c067278u: goto P_0c067278;
case 0x0c06727au: goto P_0c06727a;
case 0x0c06727cu: goto P_0c06727c;
case 0x0c06727eu: goto P_0c06727e;
case 0x0c067280u: goto P_0c067280;
case 0x0c067282u: goto P_0c067282;
case 0x0c067284u: goto P_0c067284;
case 0x0c067286u: goto P_0c067286;
case 0x0c067288u: goto P_0c067288;
case 0x0c06728au: goto P_0c06728a;
case 0x0c06728cu: goto P_0c06728c;
case 0x0c06728eu: goto P_0c06728e;
case 0x0c067290u: goto P_0c067290;
case 0x0c067292u: goto P_0c067292;
case 0x0c067294u: goto P_0c067294;
case 0x0c067296u: goto P_0c067296;
case 0x0c067298u: goto P_0c067298;
case 0x0c06729au: goto P_0c06729a;
case 0x0c06729cu: goto P_0c06729c;
case 0x0c06729eu: goto P_0c06729e;
case 0x0c0672a0u: goto P_0c0672a0;
case 0x0c0672a2u: goto P_0c0672a2;
case 0x0c0672c0u: goto P_0c0672c0;
case 0x0c0672c2u: goto P_0c0672c2;
case 0x0c0672c4u: goto P_0c0672c4;
case 0x0c0672c6u: goto P_0c0672c6;
case 0x0c0672c8u: goto P_0c0672c8;
case 0x0c0672cau: goto P_0c0672ca;
case 0x0c0672ccu: goto P_0c0672cc;
case 0x0c0672ceu: goto P_0c0672ce;
case 0x0c0672d0u: goto P_0c0672d0;
case 0x0c0672d2u: goto P_0c0672d2;
case 0x0c0672d4u: goto P_0c0672d4;
case 0x0c0672d6u: goto P_0c0672d6;
case 0x0c0672d8u: goto P_0c0672d8;
case 0x0c0672dau: goto P_0c0672da;
case 0x0c0672dcu: goto P_0c0672dc;
case 0x0c0672deu: goto P_0c0672de;
case 0x0c0672e0u: goto P_0c0672e0;
case 0x0c0672e2u: goto P_0c0672e2;
case 0x0c0672e4u: goto P_0c0672e4;
case 0x0c0672e6u: goto P_0c0672e6;
case 0x0c0672e8u: goto P_0c0672e8;
case 0x0c0672eau: goto P_0c0672ea;
case 0x0c0672ecu: goto P_0c0672ec;
case 0x0c0672eeu: goto P_0c0672ee;
case 0x0c0672f0u: goto P_0c0672f0;
case 0x0c0672f2u: goto P_0c0672f2;
case 0x0c0672f4u: goto P_0c0672f4;
case 0x0c0672f6u: goto P_0c0672f6;
case 0x0c0672f8u: goto P_0c0672f8;
case 0x0c0672fau: goto P_0c0672fa;
case 0x0c0672fcu: goto P_0c0672fc;
case 0x0c0672feu: goto P_0c0672fe;
case 0x0c067300u: goto P_0c067300;
case 0x0c067302u: goto P_0c067302;
case 0x0c067304u: goto P_0c067304;
case 0x0c067306u: goto P_0c067306;
case 0x0c067308u: goto P_0c067308;
case 0x0c06730au: goto P_0c06730a;
case 0x0c06730cu: goto P_0c06730c;
case 0x0c06730eu: goto P_0c06730e;
case 0x0c067310u: goto P_0c067310;
case 0x0c067312u: goto P_0c067312;
case 0x0c067314u: goto P_0c067314;
case 0x0c067316u: goto P_0c067316;
case 0x0c067318u: goto P_0c067318;
case 0x0c06731au: goto P_0c06731a;
case 0x0c06731cu: goto P_0c06731c;
case 0x0c06731eu: goto P_0c06731e;
case 0x0c067320u: goto P_0c067320;
case 0x0c067322u: goto P_0c067322;
case 0x0c067324u: goto P_0c067324;
case 0x0c067326u: goto P_0c067326;
case 0x0c067328u: goto P_0c067328;
case 0x0c06732au: goto P_0c06732a;
case 0x0c06732cu: goto P_0c06732c;
case 0x0c06732eu: goto P_0c06732e;
case 0x0c067330u: goto P_0c067330;
case 0x0c067332u: goto P_0c067332;
case 0x0c067334u: goto P_0c067334;
case 0x0c067336u: goto P_0c067336;
case 0x0c067338u: goto P_0c067338;
case 0x0c06733au: goto P_0c06733a;
case 0x0c06733cu: goto P_0c06733c;
case 0x0c06733eu: goto P_0c06733e;
case 0x0c067340u: goto P_0c067340;
case 0x0c067342u: goto P_0c067342;
case 0x0c067344u: goto P_0c067344;
case 0x0c067346u: goto P_0c067346;
case 0x0c067348u: goto P_0c067348;
case 0x0c06734au: goto P_0c06734a;
case 0x0c06734cu: goto P_0c06734c;
case 0x0c06734eu: goto P_0c06734e;
case 0x0c067350u: goto P_0c067350;
case 0x0c067352u: goto P_0c067352;
case 0x0c067354u: goto P_0c067354;
case 0x0c067356u: goto P_0c067356;
case 0x0c067358u: goto P_0c067358;
case 0x0c06735au: goto P_0c06735a;
case 0x0c06735cu: goto P_0c06735c;
case 0x0c06735eu: goto P_0c06735e;
case 0x0c067360u: goto P_0c067360;
case 0x0c067362u: goto P_0c067362;
case 0x0c067364u: goto P_0c067364;
case 0x0c067366u: goto P_0c067366;
case 0x0c067368u: goto P_0c067368;
case 0x0c06736au: goto P_0c06736a;
case 0x0c06736cu: goto P_0c06736c;
case 0x0c06736eu: goto P_0c06736e;
case 0x0c067370u: goto P_0c067370;
case 0x0c067372u: goto P_0c067372;
case 0x0c067374u: goto P_0c067374;
case 0x0c067376u: goto P_0c067376;
case 0x0c067378u: goto P_0c067378;
case 0x0c06737au: goto P_0c06737a;
case 0x0c0673a8u: goto P_0c0673a8;
case 0x0c0673aau: goto P_0c0673aa;
case 0x0c0673acu: goto P_0c0673ac;
case 0x0c0673aeu: goto P_0c0673ae;
case 0x0c0673b0u: goto P_0c0673b0;
case 0x0c0673b2u: goto P_0c0673b2;
case 0x0c0673b4u: goto P_0c0673b4;
case 0x0c0673b6u: goto P_0c0673b6;
case 0x0c0673b8u: goto P_0c0673b8;
case 0x0c0673bau: goto P_0c0673ba;
case 0x0c0673bcu: goto P_0c0673bc;
case 0x0c0673beu: goto P_0c0673be;
case 0x0c0673c0u: goto P_0c0673c0;
case 0x0c0673c2u: goto P_0c0673c2;
case 0x0c0673c4u: goto P_0c0673c4;
case 0x0c0673c6u: goto P_0c0673c6;
case 0x0c0673c8u: goto P_0c0673c8;
case 0x0c0673cau: goto P_0c0673ca;
case 0x0c0673ccu: goto P_0c0673cc;
case 0x0c0673ceu: goto P_0c0673ce;
case 0x0c0673d0u: goto P_0c0673d0;
case 0x0c0673d2u: goto P_0c0673d2;
case 0x0c0673d4u: goto P_0c0673d4;
case 0x0c0673d6u: goto P_0c0673d6;
case 0x0c0673d8u: goto P_0c0673d8;
case 0x0c0673dau: goto P_0c0673da;
case 0x0c0673dcu: goto P_0c0673dc;
case 0x0c0673deu: goto P_0c0673de;
case 0x0c0673e0u: goto P_0c0673e0;
case 0x0c0673e2u: goto P_0c0673e2;
case 0x0c0673e4u: goto P_0c0673e4;
case 0x0c0673e6u: goto P_0c0673e6;
case 0x0c0673e8u: goto P_0c0673e8;
case 0x0c0673eau: goto P_0c0673ea;
case 0x0c0673ecu: goto P_0c0673ec;
case 0x0c0673eeu: goto P_0c0673ee;
case 0x0c0673f0u: goto P_0c0673f0;
case 0x0c0673f2u: goto P_0c0673f2;
case 0x0c0673f4u: goto P_0c0673f4;
case 0x0c0673f6u: goto P_0c0673f6;
case 0x0c0673f8u: goto P_0c0673f8;
case 0x0c0673fau: goto P_0c0673fa;
case 0x0c0673fcu: goto P_0c0673fc;
case 0x0c0673feu: goto P_0c0673fe;
case 0x0c067400u: goto P_0c067400;
case 0x0c067402u: goto P_0c067402;
case 0x0c067404u: goto P_0c067404;
case 0x0c067406u: goto P_0c067406;
case 0x0c067408u: goto P_0c067408;
case 0x0c06740au: goto P_0c06740a;
case 0x0c06740cu: goto P_0c06740c;
case 0x0c06740eu: goto P_0c06740e;
case 0x0c067410u: goto P_0c067410;
case 0x0c067412u: goto P_0c067412;
case 0x0c067414u: goto P_0c067414;
case 0x0c067416u: goto P_0c067416;
case 0x0c067418u: goto P_0c067418;
case 0x0c06741au: goto P_0c06741a;
case 0x0c06741cu: goto P_0c06741c;
case 0x0c06741eu: goto P_0c06741e;
case 0x0c067420u: goto P_0c067420;
case 0x0c067422u: goto P_0c067422;
case 0x0c067424u: goto P_0c067424;
case 0x0c067426u: goto P_0c067426;
case 0x0c067428u: goto P_0c067428;
case 0x0c06742au: goto P_0c06742a;
case 0x0c06742cu: goto P_0c06742c;
case 0x0c06742eu: goto P_0c06742e;
case 0x0c067430u: goto P_0c067430;
case 0x0c067432u: goto P_0c067432;
case 0x0c067434u: goto P_0c067434;
case 0x0c067436u: goto P_0c067436;
case 0x0c067438u: goto P_0c067438;
case 0x0c06743au: goto P_0c06743a;
case 0x0c06743cu: goto P_0c06743c;
case 0x0c06743eu: goto P_0c06743e;
case 0x0c067440u: goto P_0c067440;
case 0x0c067468u: goto P_0c067468;
case 0x0c06746au: goto P_0c06746a;
case 0x0c06746cu: goto P_0c06746c;
case 0x0c06746eu: goto P_0c06746e;
case 0x0c067470u: goto P_0c067470;
case 0x0c067472u: goto P_0c067472;
case 0x0c067474u: goto P_0c067474;
case 0x0c067476u: goto P_0c067476;
case 0x0c067478u: goto P_0c067478;
case 0x0c06747au: goto P_0c06747a;
case 0x0c06747cu: goto P_0c06747c;
case 0x0c06747eu: goto P_0c06747e;
case 0x0c067480u: goto P_0c067480;
case 0x0c067482u: goto P_0c067482;
case 0x0c067484u: goto P_0c067484;
case 0x0c067486u: goto P_0c067486;
case 0x0c067488u: goto P_0c067488;
case 0x0c06748au: goto P_0c06748a;
case 0x0c06748cu: goto P_0c06748c;
case 0x0c06748eu: goto P_0c06748e;
case 0x0c067490u: goto P_0c067490;
case 0x0c067492u: goto P_0c067492;
case 0x0c067494u: goto P_0c067494;
case 0x0c067496u: goto P_0c067496;
case 0x0c067498u: goto P_0c067498;
case 0x0c06749au: goto P_0c06749a;
case 0x0c06749cu: goto P_0c06749c;
case 0x0c06749eu: goto P_0c06749e;
case 0x0c0674a0u: goto P_0c0674a0;
case 0x0c0674a2u: goto P_0c0674a2;
case 0x0c0674a4u: goto P_0c0674a4;
case 0x0c0674a6u: goto P_0c0674a6;
case 0x0c0674a8u: goto P_0c0674a8;
case 0x0c0674aau: goto P_0c0674aa;
case 0x0c0674acu: goto P_0c0674ac;
case 0x0c0674aeu: goto P_0c0674ae;
case 0x0c0674b0u: goto P_0c0674b0;
case 0x0c0674b2u: goto P_0c0674b2;
case 0x0c0674b4u: goto P_0c0674b4;
case 0x0c0674b6u: goto P_0c0674b6;
case 0x0c0674b8u: goto P_0c0674b8;
case 0x0c0674bau: goto P_0c0674ba;
case 0x0c0674bcu: goto P_0c0674bc;
case 0x0c0674beu: goto P_0c0674be;
case 0x0c0674c0u: goto P_0c0674c0;
case 0x0c0674c2u: goto P_0c0674c2;
case 0x0c0674c4u: goto P_0c0674c4;
case 0x0c0674c6u: goto P_0c0674c6;
case 0x0c0674c8u: goto P_0c0674c8;
case 0x0c0674cau: goto P_0c0674ca;
case 0x0c0674ccu: goto P_0c0674cc;
case 0x0c0674ceu: goto P_0c0674ce;
case 0x0c0674d0u: goto P_0c0674d0;
case 0x0c0674d2u: goto P_0c0674d2;
case 0x0c0674d4u: goto P_0c0674d4;
case 0x0c0674d6u: goto P_0c0674d6;
case 0x0c0674d8u: goto P_0c0674d8;
case 0x0c0674dau: goto P_0c0674da;
case 0x0c0674dcu: goto P_0c0674dc;
case 0x0c0674deu: goto P_0c0674de;
case 0x0c0674e0u: goto P_0c0674e0;
case 0x0c0674e2u: goto P_0c0674e2;
case 0x0c0674e4u: goto P_0c0674e4;
case 0x0c0674e6u: goto P_0c0674e6;
case 0x0c0674e8u: goto P_0c0674e8;
case 0x0c0674eau: goto P_0c0674ea;
case 0x0c0674ecu: goto P_0c0674ec;
case 0x0c0674eeu: goto P_0c0674ee;
case 0x0c0674f0u: goto P_0c0674f0;
case 0x0c0674f2u: goto P_0c0674f2;
case 0x0c0674f4u: goto P_0c0674f4;
case 0x0c0674f6u: goto P_0c0674f6;
case 0x0c0674f8u: goto P_0c0674f8;
case 0x0c0674fau: goto P_0c0674fa;
case 0x0c0674fcu: goto P_0c0674fc;
case 0x0c0674feu: goto P_0c0674fe;
case 0x0c0675fcu: goto P_0c0675fc;
case 0x0c0675feu: goto P_0c0675fe;
case 0x0c067600u: goto P_0c067600;
case 0x0c067602u: goto P_0c067602;
case 0x0c067604u: goto P_0c067604;
case 0x0c067606u: goto P_0c067606;
case 0x0c067608u: goto P_0c067608;
case 0x0c06760au: goto P_0c06760a;
case 0x0c06760cu: goto P_0c06760c;
case 0x0c06760eu: goto P_0c06760e;
case 0x0c067610u: goto P_0c067610;
case 0x0c06862au: goto P_0c06862a;
case 0x0c06862cu: goto P_0c06862c;
case 0x0c06862eu: goto P_0c06862e;
case 0x0c068630u: goto P_0c068630;
case 0x0c068632u: goto P_0c068632;
case 0x0c068634u: goto P_0c068634;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0671aa: /* original 000b, guest PC 0x0c0671aa */
if(!s->budget--) { s->failed_pc=0x0c0671aau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0671ac: /* original 0009, guest PC 0x0c0671ac */
if(!s->budget--) { s->failed_pc=0x0c0671acu; return 0; }
if(!vf3_matrix_family(0x0c0671aeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0671aeu; return 0; } return 1;
P_0c0671d8: /* original 9064, guest PC 0x0c0671d8 */
if(!s->budget--) { s->failed_pc=0x0c0671d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a4u,2);
goto P_0c0671da;
P_0c0671da: /* original 4f22, guest PC 0x0c0671da */
if(!s->budget--) { s->failed_pc=0x0c0671dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0671dc;
P_0c0671dc: /* original 064c, guest PC 0x0c0671dc */
if(!s->budget--) { s->failed_pc=0x0c0671dcu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0671de;
P_0c0671de: /* original 2668, guest PC 0x0c0671de */
if(!s->budget--) { s->failed_pc=0x0c0671deu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0671e0;
P_0c0671e0: /* original 6563, guest PC 0x0c0671e0 */
if(!s->budget--) { s->failed_pc=0x0c0671e0u; return 0; }
r[5]=r[6];
goto P_0c0671e2;
P_0c0671e2: /* original 7ff4, guest PC 0x0c0671e2 */
if(!s->budget--) { s->failed_pc=0x0c0671e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0671e4;
P_0c0671e4: /* original 8d5a, guest PC 0x0c0671e4 */
if(!s->budget--) { s->failed_pc=0x0c0671e4u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c06729c; }
goto P_0c0671e8;
P_0c0671e6: /* original 75ff, guest PC 0x0c0671e6 */
if(!s->budget--) { s->failed_pc=0x0c0671e6u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0671e8;
P_0c0671e8: /* original 0454, guest PC 0x0c0671e8 */
if(!s->budget--) { s->failed_pc=0x0c0671e8u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0671ea;
P_0c0671ea: /* original 702c, guest PC 0x0c0671ea */
if(!s->budget--) { s->failed_pc=0x0c0671eau; return 0; }
r[0]+=0x0000002cu;
goto P_0c0671ec;
P_0c0671ec: /* original f446, guest PC 0x0c0671ec */
if(!s->budget--) { s->failed_pc=0x0c0671ecu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0671ee;
P_0c0671ee: /* original 70e4, guest PC 0x0c0671ee */
if(!s->budget--) { s->failed_pc=0x0c0671eeu; return 0; }
r[0]+=0xffffffe4u;
goto P_0c0671f0;
P_0c0671f0: /* original f846, guest PC 0x0c0671f0 */
if(!s->budget--) { s->failed_pc=0x0c0671f0u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0671f2;
P_0c0671f2: /* original 9058, guest PC 0x0c0671f2 */
if(!s->budget--) { s->failed_pc=0x0c0671f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a6u,2);
goto P_0c0671f4;
P_0c0671f4: /* original f546, guest PC 0x0c0671f4 */
if(!s->budget--) { s->failed_pc=0x0c0671f4u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0671f6;
P_0c0671f6: /* original 7004, guest PC 0x0c0671f6 */
if(!s->budget--) { s->failed_pc=0x0c0671f6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0671f8;
P_0c0671f8: /* original f746, guest PC 0x0c0671f8 */
if(!s->budget--) { s->failed_pc=0x0c0671f8u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0671fa;
P_0c0671fa: /* original 700c, guest PC 0x0c0671fa */
if(!s->budget--) { s->failed_pc=0x0c0671fau; return 0; }
r[0]+=0x0000000cu;
goto P_0c0671fc;
P_0c0671fc: /* original f646, guest PC 0x0c0671fc */
if(!s->budget--) { s->failed_pc=0x0c0671fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0671fe;
P_0c0671fe: /* original 9053, guest PC 0x0c0671fe */
if(!s->budget--) { s->failed_pc=0x0c0671feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a8u,2);
goto P_0c067200;
P_0c067200: /* original fb46, guest PC 0x0c067200 */
if(!s->budget--) { s->failed_pc=0x0c067200u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c067202;
P_0c067202: /* original 7004, guest PC 0x0c067202 */
if(!s->budget--) { s->failed_pc=0x0c067202u; return 0; }
r[0]+=0x00000004u;
goto P_0c067204;
P_0c067204: /* original f346, guest PC 0x0c067204 */
if(!s->budget--) { s->failed_pc=0x0c067204u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c067206;
P_0c067206: /* original e008, guest PC 0x0c067206 */
if(!s->budget--) { s->failed_pc=0x0c067206u; return 0; }
r[0]=0x00000008u;
goto P_0c067208;
P_0c067208: /* original ff37, guest PC 0x0c067208 */
if(!s->budget--) { s->failed_pc=0x0c067208u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06720a;
P_0c06720a: /* original 904e, guest PC 0x0c06720a */
if(!s->budget--) { s->failed_pc=0x0c06720au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672aau,2);
goto P_0c06720c;
P_0c06720c: /* original f946, guest PC 0x0c06720c */
if(!s->budget--) { s->failed_pc=0x0c06720cu; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c06720e;
P_0c06720e: /* original 7004, guest PC 0x0c06720e */
if(!s->budget--) { s->failed_pc=0x0c06720eu; return 0; }
r[0]+=0x00000004u;
goto P_0c067210;
P_0c067210: /* original 034c, guest PC 0x0c067210 */
if(!s->budget--) { s->failed_pc=0x0c067210u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067212;
P_0c067212: /* original 7002, guest PC 0x0c067212 */
if(!s->budget--) { s->failed_pc=0x0c067212u; return 0; }
r[0]+=0x00000002u;
goto P_0c067214;
P_0c067214: /* original 024c, guest PC 0x0c067214 */
if(!s->budget--) { s->failed_pc=0x0c067214u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067216;
P_0c067216: /* original 3327, guest PC 0x0c067216 */
if(!s->budget--) { s->failed_pc=0x0c067216u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c067218;
P_0c067218: /* original 891b, guest PC 0x0c067218 */
if(!s->budget--) { s->failed_pc=0x0c067218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067252; }
goto P_0c06721a;
P_0c06721a: /* original d327, guest PC 0x0c06721a */
if(!s->budget--) { s->failed_pc=0x0c06721au; return 0; }
r[3]=read(ram,0x0c0672b8u,4);
goto P_0c06721c;
P_0c06721c: /* original f480, guest PC 0x0c06721c */
if(!s->budget--) { s->failed_pc=0x0c06721cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c06721e;
P_0c06721e: /* original 6630, guest PC 0x0c06721e */
if(!s->budget--) { s->failed_pc=0x0c06721eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[6]=tmp;
goto P_0c067220;
P_0c067220: /* original 666c, guest PC 0x0c067220 */
if(!s->budget--) { s->failed_pc=0x0c067220u; return 0; }
r[6]=r[6]&255u;
goto P_0c067222;
P_0c067222: /* original 6063, guest PC 0x0c067222 */
if(!s->budget--) { s->failed_pc=0x0c067222u; return 0; }
r[0]=r[6];
goto P_0c067224;
P_0c067224: /* original 8806, guest PC 0x0c067224 */
if(!s->budget--) { s->failed_pc=0x0c067224u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c067226;
P_0c067226: /* original 8f02, guest PC 0x0c067226 */
if(!s->budget--) { s->failed_pc=0x0c067226u; return 0; }
cond=r[17]&1u;
fr[8]=0;
if(!cond) { goto P_0c06722e; }
goto P_0c06722a;
P_0c067228: /* original f88d, guest PC 0x0c067228 */
if(!s->budget--) { s->failed_pc=0x0c067228u; return 0; }
fr[8]=0;
goto P_0c06722a;
P_0c06722a: /* original 903f, guest PC 0x0c06722a */
if(!s->budget--) { s->failed_pc=0x0c06722au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672acu,2);
goto P_0c06722c;
P_0c06722c: /* original f846, guest PC 0x0c06722c */
if(!s->budget--) { s->failed_pc=0x0c06722cu; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c06722e;
P_0c06722e: /* original f34c, guest PC 0x0c06722e */
if(!s->budget--) { s->failed_pc=0x0c06722eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c067230;
P_0c067230: /* original f381, guest PC 0x0c067230 */
if(!s->budget--) { s->failed_pc=0x0c067230u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'-');
goto P_0c067232;
P_0c067232: /* original f28d, guest PC 0x0c067232 */
if(!s->budget--) { s->failed_pc=0x0c067232u; return 0; }
fr[2]=0;
goto P_0c067234;
P_0c067234: /* original fa9d, guest PC 0x0c067234 */
if(!s->budget--) { s->failed_pc=0x0c067234u; return 0; }
fr[10]=0x3f800000u;
goto P_0c067236;
P_0c067236: /* original f235, guest PC 0x0c067236 */
if(!s->budget--) { s->failed_pc=0x0c067236u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c067238;
P_0c067238: /* original 8d01, guest PC 0x0c067238 */
if(!s->budget--) { s->failed_pc=0x0c067238u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c06723e; }
goto P_0c06723c;
P_0c06723a: /* original ff3a, guest PC 0x0c06723a */
if(!s->budget--) { s->failed_pc=0x0c06723au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06723c;
P_0c06723c: /* original f84c, guest PC 0x0c06723c */
if(!s->budget--) { s->failed_pc=0x0c06723cu; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c06723e;
P_0c06723e: /* original f38c, guest PC 0x0c06723e */
if(!s->budget--) { s->failed_pc=0x0c06723eu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c067240;
P_0c067240: /* original f3a1, guest PC 0x0c067240 */
if(!s->budget--) { s->failed_pc=0x0c067240u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c067242;
P_0c067242: /* original f28d, guest PC 0x0c067242 */
if(!s->budget--) { s->failed_pc=0x0c067242u; return 0; }
fr[2]=0;
goto P_0c067244;
P_0c067244: /* original e004, guest PC 0x0c067244 */
if(!s->budget--) { s->failed_pc=0x0c067244u; return 0; }
r[0]=0x00000004u;
goto P_0c067246;
P_0c067246: /* original f235, guest PC 0x0c067246 */
if(!s->budget--) { s->failed_pc=0x0c067246u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c067248;
P_0c067248: /* original 8d02, guest PC 0x0c067248 */
if(!s->budget--) { s->failed_pc=0x0c067248u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(cond) { goto P_0c067250; }
goto P_0c06724c;
P_0c06724a: /* original ff37, guest PC 0x0c06724a */
if(!s->budget--) { s->failed_pc=0x0c06724au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06724c;
P_0c06724c: /* original a001, guest PC 0x0c06724c */
if(!s->budget--) { s->failed_pc=0x0c06724cu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c067252;
P_0c06724e: /* original f4ac, guest PC 0x0c06724e */
if(!s->budget--) { s->failed_pc=0x0c06724eu; return 0; }
vf3_matrix_move(s,4,10);
goto P_0c067250;
P_0c067250: /* original f48c, guest PC 0x0c067250 */
if(!s->budget--) { s->failed_pc=0x0c067250u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c067252;
P_0c067252: /* original e008, guest PC 0x0c067252 */
if(!s->budget--) { s->failed_pc=0x0c067252u; return 0; }
r[0]=0x00000008u;
goto P_0c067254;
P_0c067254: /* original f5b0, guest PC 0x0c067254 */
if(!s->budget--) { s->failed_pc=0x0c067254u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c067256;
P_0c067256: /* original f3f6, guest PC 0x0c067256 */
if(!s->budget--) { s->failed_pc=0x0c067256u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c067258;
P_0c067258: /* original f690, guest PC 0x0c067258 */
if(!s->budget--) { s->failed_pc=0x0c067258u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'+');
goto P_0c06725a;
P_0c06725a: /* original 9024, guest PC 0x0c06725a */
if(!s->budget--) { s->failed_pc=0x0c06725au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672a6u,2);
goto P_0c06725c;
P_0c06725c: /* original 4515, guest PC 0x0c06725c */
if(!s->budget--) { s->failed_pc=0x0c06725cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c06725e;
P_0c06725e: /* original f730, guest PC 0x0c06725e */
if(!s->budget--) { s->failed_pc=0x0c06725eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c067260;
P_0c067260: /* original f457, guest PC 0x0c067260 */
if(!s->budget--) { s->failed_pc=0x0c067260u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c067262;
P_0c067262: /* original 7004, guest PC 0x0c067262 */
if(!s->budget--) { s->failed_pc=0x0c067262u; return 0; }
r[0]+=0x00000004u;
goto P_0c067264;
P_0c067264: /* original f477, guest PC 0x0c067264 */
if(!s->budget--) { s->failed_pc=0x0c067264u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c067266;
P_0c067266: /* original 700c, guest PC 0x0c067266 */
if(!s->budget--) { s->failed_pc=0x0c067266u; return 0; }
r[0]+=0x0000000cu;
goto P_0c067268;
P_0c067268: /* original f467, guest PC 0x0c067268 */
if(!s->budget--) { s->failed_pc=0x0c067268u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c06726a;
P_0c06726a: /* original 9020, guest PC 0x0c06726a */
if(!s->budget--) { s->failed_pc=0x0c06726au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672aeu,2);
goto P_0c06726c;
P_0c06726c: /* original f447, guest PC 0x0c06726c */
if(!s->budget--) { s->failed_pc=0x0c06726cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c06726e;
P_0c06726e: /* original 7004, guest PC 0x0c06726e */
if(!s->budget--) { s->failed_pc=0x0c06726eu; return 0; }
r[0]+=0x00000004u;
goto P_0c067270;
P_0c067270: /* original 961e, guest PC 0x0c067270 */
if(!s->budget--) { s->failed_pc=0x0c067270u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b0u,2);
goto P_0c067272;
P_0c067272: /* original 0464, guest PC 0x0c067272 */
if(!s->budget--) { s->failed_pc=0x0c067272u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c067274;
P_0c067274: /* original 7001, guest PC 0x0c067274 */
if(!s->budget--) { s->failed_pc=0x0c067274u; return 0; }
r[0]+=0x00000001u;
goto P_0c067276;
P_0c067276: /* original 0464, guest PC 0x0c067276 */
if(!s->budget--) { s->failed_pc=0x0c067276u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c067278;
P_0c067278: /* original 7001, guest PC 0x0c067278 */
if(!s->budget--) { s->failed_pc=0x0c067278u; return 0; }
r[0]+=0x00000001u;
goto P_0c06727a;
P_0c06727a: /* original 8d0c, guest PC 0x0c06727a */
if(!s->budget--) { s->failed_pc=0x0c06727au; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[6],1);
if(cond) { goto P_0c067296; }
goto P_0c06727e;
P_0c06727c: /* original 0464, guest PC 0x0c06727c */
if(!s->budget--) { s->failed_pc=0x0c06727cu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06727e;
P_0c06727e: /* original 9018, guest PC 0x0c06727e */
if(!s->budget--) { s->failed_pc=0x0c06727eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b2u,2);
goto P_0c067280;
P_0c067280: /* original 064c, guest PC 0x0c067280 */
if(!s->budget--) { s->failed_pc=0x0c067280u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067282;
P_0c067282: /* original 7001, guest PC 0x0c067282 */
if(!s->budget--) { s->failed_pc=0x0c067282u; return 0; }
r[0]+=0x00000001u;
goto P_0c067284;
P_0c067284: /* original 074c, guest PC 0x0c067284 */
if(!s->budget--) { s->failed_pc=0x0c067284u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067286;
P_0c067286: /* original 7001, guest PC 0x0c067286 */
if(!s->budget--) { s->failed_pc=0x0c067286u; return 0; }
r[0]+=0x00000001u;
goto P_0c067288;
P_0c067288: /* original 054c, guest PC 0x0c067288 */
if(!s->budget--) { s->failed_pc=0x0c067288u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06728a;
P_0c06728a: /* original 9013, guest PC 0x0c06728a */
if(!s->budget--) { s->failed_pc=0x0c06728au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0672b4u,2);
goto P_0c06728c;
P_0c06728c: /* original 0464, guest PC 0x0c06728c */
if(!s->budget--) { s->failed_pc=0x0c06728cu; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c06728e;
P_0c06728e: /* original 7001, guest PC 0x0c06728e */
if(!s->budget--) { s->failed_pc=0x0c06728eu; return 0; }
r[0]+=0x00000001u;
goto P_0c067290;
P_0c067290: /* original 0474, guest PC 0x0c067290 */
if(!s->budget--) { s->failed_pc=0x0c067290u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c067292;
P_0c067292: /* original 7001, guest PC 0x0c067292 */
if(!s->budget--) { s->failed_pc=0x0c067292u; return 0; }
r[0]+=0x00000001u;
goto P_0c067294;
P_0c067294: /* original 0454, guest PC 0x0c067294 */
if(!s->budget--) { s->failed_pc=0x0c067294u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c067296;
P_0c067296: /* original d309, guest PC 0x0c067296 */
if(!s->budget--) { s->failed_pc=0x0c067296u; return 0; }
r[3]=read(ram,0x0c0672bcu,4);
goto P_0c067298;
P_0c067298: /* original 430b, guest PC 0x0c067298 */
if(!s->budget--) { s->failed_pc=0x0c067298u; return 0; }
target=r[3];
r[16]=code_base|0x0c06729cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06729cu) { target=s->pc; goto dispatch; }
goto P_0c06729c;
P_0c06729a: /* original 0009, guest PC 0x0c06729a */
if(!s->budget--) { s->failed_pc=0x0c06729au; return 0; }
goto P_0c06729c;
P_0c06729c: /* original 7f0c, guest PC 0x0c06729c */
if(!s->budget--) { s->failed_pc=0x0c06729cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06729e;
P_0c06729e: /* original 4f26, guest PC 0x0c06729e */
if(!s->budget--) { s->failed_pc=0x0c06729eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0672a0;
P_0c0672a0: /* original 000b, guest PC 0x0c0672a0 */
if(!s->budget--) { s->failed_pc=0x0c0672a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0672a2: /* original 0009, guest PC 0x0c0672a2 */
if(!s->budget--) { s->failed_pc=0x0c0672a2u; return 0; }
if(!vf3_matrix_family(0x0c0672a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0672a4u; return 0; } return 1;
P_0c0672c0: /* original 2fe6, guest PC 0x0c0672c0 */
if(!s->budget--) { s->failed_pc=0x0c0672c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0672c2;
P_0c0672c2: /* original 905b, guest PC 0x0c0672c2 */
if(!s->budget--) { s->failed_pc=0x0c0672c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06737cu,2);
goto P_0c0672c4;
P_0c0672c4: /* original 4f22, guest PC 0x0c0672c4 */
if(!s->budget--) { s->failed_pc=0x0c0672c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0672c6;
P_0c0672c6: /* original 054c, guest PC 0x0c0672c6 */
if(!s->budget--) { s->failed_pc=0x0c0672c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0672c8;
P_0c0672c8: /* original 655c, guest PC 0x0c0672c8 */
if(!s->budget--) { s->failed_pc=0x0c0672c8u; return 0; }
r[5]=r[5]&255u;
goto P_0c0672ca;
P_0c0672ca: /* original 2558, guest PC 0x0c0672ca */
if(!s->budget--) { s->failed_pc=0x0c0672cau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0672cc;
P_0c0672cc: /* original 893b, guest PC 0x0c0672cc */
if(!s->budget--) { s->failed_pc=0x0c0672ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067346; }
goto P_0c0672ce;
P_0c0672ce: /* original 75ff, guest PC 0x0c0672ce */
if(!s->budget--) { s->failed_pc=0x0c0672ceu; return 0; }
r[5]+=0xffffffffu;
goto P_0c0672d0;
P_0c0672d0: /* original 0454, guest PC 0x0c0672d0 */
if(!s->budget--) { s->failed_pc=0x0c0672d0u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0672d2;
P_0c0672d2: /* original 70ff, guest PC 0x0c0672d2 */
if(!s->budget--) { s->failed_pc=0x0c0672d2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0672d4;
P_0c0672d4: /* original 064c, guest PC 0x0c0672d4 */
if(!s->budget--) { s->failed_pc=0x0c0672d4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0672d6;
P_0c0672d6: /* original 606c, guest PC 0x0c0672d6 */
if(!s->budget--) { s->failed_pc=0x0c0672d6u; return 0; }
r[0]=r[6]&255u;
goto P_0c0672d8;
P_0c0672d8: /* original 8802, guest PC 0x0c0672d8 */
if(!s->budget--) { s->failed_pc=0x0c0672d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0672da;
P_0c0672da: /* original 8d0e, guest PC 0x0c0672da */
if(!s->budget--) { s->failed_pc=0x0c0672dau; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c0672fa; }
goto P_0c0672de;
P_0c0672dc: /* original 6603, guest PC 0x0c0672dc */
if(!s->budget--) { s->failed_pc=0x0c0672dcu; return 0; }
r[6]=r[0];
goto P_0c0672de;
P_0c0672de: /* original 6063, guest PC 0x0c0672de */
if(!s->budget--) { s->failed_pc=0x0c0672deu; return 0; }
r[0]=r[6];
goto P_0c0672e0;
P_0c0672e0: /* original 8805, guest PC 0x0c0672e0 */
if(!s->budget--) { s->failed_pc=0x0c0672e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0672e2;
P_0c0672e2: /* original 890a, guest PC 0x0c0672e2 */
if(!s->budget--) { s->failed_pc=0x0c0672e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0672fa; }
goto P_0c0672e4;
P_0c0672e4: /* original e61f, guest PC 0x0c0672e4 */
if(!s->budget--) { s->failed_pc=0x0c0672e4u; return 0; }
r[6]=0x0000001fu;
goto P_0c0672e6;
P_0c0672e6: /* original 6363, guest PC 0x0c0672e6 */
if(!s->budget--) { s->failed_pc=0x0c0672e6u; return 0; }
r[3]=r[6];
goto P_0c0672e8;
P_0c0672e8: /* original 3358, guest PC 0x0c0672e8 */
if(!s->budget--) { s->failed_pc=0x0c0672e8u; return 0; }
r[3]-=r[5];
goto P_0c0672ea;
P_0c0672ea: /* original 6033, guest PC 0x0c0672ea */
if(!s->budget--) { s->failed_pc=0x0c0672eau; return 0; }
r[0]=r[3];
goto P_0c0672ec;
P_0c0672ec: /* original 881d, guest PC 0x0c0672ec */
if(!s->budget--) { s->failed_pc=0x0c0672ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0672ee;
P_0c0672ee: /* original 8f04, guest PC 0x0c0672ee */
if(!s->budget--) { s->failed_pc=0x0c0672eeu; return 0; }
cond=r[17]&1u;
r[5]=r[3];
if(!cond) { goto P_0c0672fa; }
goto P_0c0672f2;
P_0c0672f0: /* original 6533, guest PC 0x0c0672f0 */
if(!s->budget--) { s->failed_pc=0x0c0672f0u; return 0; }
r[5]=r[3];
goto P_0c0672f2;
P_0c0672f2: /* original 6242, guest PC 0x0c0672f2 */
if(!s->budget--) { s->failed_pc=0x0c0672f2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0672f4;
P_0c0672f4: /* original 9343, guest PC 0x0c0672f4 */
if(!s->budget--) { s->failed_pc=0x0c0672f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06737eu,2);
goto P_0c0672f6;
P_0c0672f6: /* original 2239, guest PC 0x0c0672f6 */
if(!s->budget--) { s->failed_pc=0x0c0672f6u; return 0; }
r[2]&=r[3];
goto P_0c0672f8;
P_0c0672f8: /* original 2422, guest PC 0x0c0672f8 */
if(!s->budget--) { s->failed_pc=0x0c0672f8u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0672fa;
P_0c0672fa: /* original 6753, guest PC 0x0c0672fa */
if(!s->budget--) { s->failed_pc=0x0c0672fau; return 0; }
r[7]=r[5];
goto P_0c0672fc;
P_0c0672fc: /* original 6053, guest PC 0x0c0672fc */
if(!s->budget--) { s->failed_pc=0x0c0672fcu; return 0; }
r[0]=r[5];
goto P_0c0672fe;
P_0c0672fe: /* original 6653, guest PC 0x0c0672fe */
if(!s->budget--) { s->failed_pc=0x0c0672feu; return 0; }
r[6]=r[5];
goto P_0c067300;
P_0c067300: /* original 943e, guest PC 0x0c067300 */
if(!s->budget--) { s->failed_pc=0x0c067300u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067380u,2);
goto P_0c067302;
P_0c067302: /* original d223, guest PC 0x0c067302 */
if(!s->budget--) { s->failed_pc=0x0c067302u; return 0; }
r[2]=read(ram,0x0c067390u,4);
goto P_0c067304;
P_0c067304: /* original 4008, guest PC 0x0c067304 */
if(!s->budget--) { s->failed_pc=0x0c067304u; return 0; }
r[0]<<=2;
goto P_0c067306;
P_0c067306: /* original 4718, guest PC 0x0c067306 */
if(!s->budget--) { s->failed_pc=0x0c067306u; return 0; }
r[7]<<=8;
goto P_0c067308;
P_0c067308: /* original d320, guest PC 0x0c067308 */
if(!s->budget--) { s->failed_pc=0x0c067308u; return 0; }
r[3]=read(ram,0x0c06738cu,4);
goto P_0c06730a;
P_0c06730a: /* original 4628, guest PC 0x0c06730a */
if(!s->budget--) { s->failed_pc=0x0c06730au; return 0; }
r[6]<<=16;
goto P_0c06730c;
P_0c06730c: /* original de21, guest PC 0x0c06730c */
if(!s->budget--) { s->failed_pc=0x0c06730cu; return 0; }
r[14]=read(ram,0x0c067394u,4);
goto P_0c06730e;
P_0c06730e: /* original 4708, guest PC 0x0c06730e */
if(!s->budget--) { s->failed_pc=0x0c06730eu; return 0; }
r[7]<<=2;
goto P_0c067310;
P_0c067310: /* original 2409, guest PC 0x0c067310 */
if(!s->budget--) { s->failed_pc=0x0c067310u; return 0; }
r[4]&=r[0];
goto P_0c067312;
P_0c067312: /* original 6053, guest PC 0x0c067312 */
if(!s->budget--) { s->failed_pc=0x0c067312u; return 0; }
r[0]=r[5];
goto P_0c067314;
P_0c067314: /* original 4608, guest PC 0x0c067314 */
if(!s->budget--) { s->failed_pc=0x0c067314u; return 0; }
r[6]<<=2;
goto P_0c067316;
P_0c067316: /* original 881f, guest PC 0x0c067316 */
if(!s->budget--) { s->failed_pc=0x0c067316u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c067318;
P_0c067318: /* original 2639, guest PC 0x0c067318 */
if(!s->budget--) { s->failed_pc=0x0c067318u; return 0; }
r[6]&=r[3];
goto P_0c06731a;
P_0c06731a: /* original 2729, guest PC 0x0c06731a */
if(!s->budget--) { s->failed_pc=0x0c06731au; return 0; }
r[7]&=r[2];
goto P_0c06731c;
P_0c06731c: /* original 267b, guest PC 0x0c06731c */
if(!s->budget--) { s->failed_pc=0x0c06731cu; return 0; }
r[6]|=r[7];
goto P_0c06731e;
P_0c06731e: /* original 8f0e, guest PC 0x0c06731e */
if(!s->budget--) { s->failed_pc=0x0c06731eu; return 0; }
cond=r[17]&1u;
r[4]|=r[6];
if(!cond) { goto P_0c06733e; }
goto P_0c067322;
P_0c067320: /* original 246b, guest PC 0x0c067320 */
if(!s->budget--) { s->failed_pc=0x0c067320u; return 0; }
r[4]|=r[6];
goto P_0c067322;
P_0c067322: /* original d31d, guest PC 0x0c067322 */
if(!s->budget--) { s->failed_pc=0x0c067322u; return 0; }
r[3]=read(ram,0x0c067398u,4);
goto P_0c067324;
P_0c067324: /* original 430b, guest PC 0x0c067324 */
if(!s->budget--) { s->failed_pc=0x0c067324u; return 0; }
target=r[3];
r[16]=code_base|0x0c067328u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c067328u) { target=s->pc; goto dispatch; }
goto P_0c067328;
P_0c067326: /* original 64e3, guest PC 0x0c067326 */
if(!s->budget--) { s->failed_pc=0x0c067326u; return 0; }
r[4]=r[14];
goto P_0c067328;
P_0c067328: /* original d21b, guest PC 0x0c067328 */
if(!s->budget--) { s->failed_pc=0x0c067328u; return 0; }
r[2]=read(ram,0x0c067398u,4);
goto P_0c06732a;
P_0c06732a: /* original 64e3, guest PC 0x0c06732a */
if(!s->budget--) { s->failed_pc=0x0c06732au; return 0; }
r[4]=r[14];
goto P_0c06732c;
P_0c06732c: /* original 420b, guest PC 0x0c06732c */
if(!s->budget--) { s->failed_pc=0x0c06732cu; return 0; }
target=r[2];
r[16]=code_base|0x0c067330u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c067330u) { target=s->pc; goto dispatch; }
goto P_0c067330;
P_0c06732e: /* original 742c, guest PC 0x0c06732e */
if(!s->budget--) { s->failed_pc=0x0c06732eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c067330;
P_0c067330: /* original 9627, guest PC 0x0c067330 */
if(!s->budget--) { s->failed_pc=0x0c067330u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067382u,2);
goto P_0c067332;
P_0c067332: /* original 9427, guest PC 0x0c067332 */
if(!s->budget--) { s->failed_pc=0x0c067332u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067384u,2);
goto P_0c067334;
P_0c067334: /* original d319, guest PC 0x0c067334 */
if(!s->budget--) { s->failed_pc=0x0c067334u; return 0; }
r[3]=read(ram,0x0c06739cu,4);
goto P_0c067336;
P_0c067336: /* original 36ec, guest PC 0x0c067336 */
if(!s->budget--) { s->failed_pc=0x0c067336u; return 0; }
r[6]+=r[14];
goto P_0c067338;
P_0c067338: /* original 430b, guest PC 0x0c067338 */
if(!s->budget--) { s->failed_pc=0x0c067338u; return 0; }
target=r[3];
r[16]=code_base|0x0c06733cu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06733cu) { target=s->pc; goto dispatch; }
goto P_0c06733c;
P_0c06733a: /* original 65e3, guest PC 0x0c06733a */
if(!s->budget--) { s->failed_pc=0x0c06733au; return 0; }
r[5]=r[14];
goto P_0c06733c;
P_0c06733c: /* original e400, guest PC 0x0c06733c */
if(!s->budget--) { s->failed_pc=0x0c06733cu; return 0; }
r[4]=0x00000000u;
goto P_0c06733e;
P_0c06733e: /* original 9022, guest PC 0x0c06733e */
if(!s->budget--) { s->failed_pc=0x0c06733eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067386u,2);
goto P_0c067340;
P_0c067340: /* original 0e46, guest PC 0x0c067340 */
if(!s->budget--) { s->failed_pc=0x0c067340u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067342;
P_0c067342: /* original 7004, guest PC 0x0c067342 */
if(!s->budget--) { s->failed_pc=0x0c067342u; return 0; }
r[0]+=0x00000004u;
goto P_0c067344;
P_0c067344: /* original 0e46, guest PC 0x0c067344 */
if(!s->budget--) { s->failed_pc=0x0c067344u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067346;
P_0c067346: /* original 4f26, guest PC 0x0c067346 */
if(!s->budget--) { s->failed_pc=0x0c067346u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c067348;
P_0c067348: /* original 000b, guest PC 0x0c067348 */
if(!s->budget--) { s->failed_pc=0x0c067348u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06734a: /* original 6ef6, guest PC 0x0c06734a */
if(!s->budget--) { s->failed_pc=0x0c06734au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06734c;
P_0c06734c: /* original 000b, guest PC 0x0c06734c */
if(!s->budget--) { s->failed_pc=0x0c06734cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06734e: /* original 0009, guest PC 0x0c06734e */
if(!s->budget--) { s->failed_pc=0x0c06734eu; return 0; }
goto P_0c067350;
P_0c067350: /* original 901a, guest PC 0x0c067350 */
if(!s->budget--) { s->failed_pc=0x0c067350u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067388u,2);
goto P_0c067352;
P_0c067352: /* original 034c, guest PC 0x0c067352 */
if(!s->budget--) { s->failed_pc=0x0c067352u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c067354;
P_0c067354: /* original 2338, guest PC 0x0c067354 */
if(!s->budget--) { s->failed_pc=0x0c067354u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c067356;
P_0c067356: /* original 8905, guest PC 0x0c067356 */
if(!s->budget--) { s->failed_pc=0x0c067356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067364; }
goto P_0c067358;
P_0c067358: /* original d311, guest PC 0x0c067358 */
if(!s->budget--) { s->failed_pc=0x0c067358u; return 0; }
r[3]=read(ram,0x0c0673a0u,4);
goto P_0c06735a;
P_0c06735a: /* original 014c, guest PC 0x0c06735a */
if(!s->budget--) { s->failed_pc=0x0c06735au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06735c;
P_0c06735c: /* original 6231, guest PC 0x0c06735c */
if(!s->budget--) { s->failed_pc=0x0c06735cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c06735e;
P_0c06735e: /* original 611c, guest PC 0x0c06735e */
if(!s->budget--) { s->failed_pc=0x0c06735eu; return 0; }
r[1]=r[1]&255u;
goto P_0c067360;
P_0c067360: /* original 3218, guest PC 0x0c067360 */
if(!s->budget--) { s->failed_pc=0x0c067360u; return 0; }
r[2]-=r[1];
goto P_0c067362;
P_0c067362: /* original 2321, guest PC 0x0c067362 */
if(!s->budget--) { s->failed_pc=0x0c067362u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c067364;
P_0c067364: /* original 000b, guest PC 0x0c067364 */
if(!s->budget--) { s->failed_pc=0x0c067364u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c067366: /* original 0009, guest PC 0x0c067366 */
if(!s->budget--) { s->failed_pc=0x0c067366u; return 0; }
goto P_0c067368;
P_0c067368: /* original d50e, guest PC 0x0c067368 */
if(!s->budget--) { s->failed_pc=0x0c067368u; return 0; }
r[5]=read(ram,0x0c0673a4u,4);
goto P_0c06736a;
P_0c06736a: /* original e004, guest PC 0x0c06736a */
if(!s->budget--) { s->failed_pc=0x0c06736au; return 0; }
r[0]=0x00000004u;
goto P_0c06736c;
P_0c06736c: /* original f456, guest PC 0x0c06736c */
if(!s->budget--) { s->failed_pc=0x0c06736cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c06736e;
P_0c06736e: /* original e014, guest PC 0x0c06736e */
if(!s->budget--) { s->failed_pc=0x0c06736eu; return 0; }
r[0]=0x00000014u;
goto P_0c067370;
P_0c067370: /* original f556, guest PC 0x0c067370 */
if(!s->budget--) { s->failed_pc=0x0c067370u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c067372;
P_0c067372: /* original 900a, guest PC 0x0c067372 */
if(!s->budget--) { s->failed_pc=0x0c067372u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06738au,2);
goto P_0c067374;
P_0c067374: /* original f447, guest PC 0x0c067374 */
if(!s->budget--) { s->failed_pc=0x0c067374u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c067376;
P_0c067376: /* original 70fc, guest PC 0x0c067376 */
if(!s->budget--) { s->failed_pc=0x0c067376u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c067378;
P_0c067378: /* original 000b, guest PC 0x0c067378 */
if(!s->budget--) { s->failed_pc=0x0c067378u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c06737a: /* original f457, guest PC 0x0c06737a */
if(!s->budget--) { s->failed_pc=0x0c06737au; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
if(!vf3_matrix_family(0x0c06737cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06737cu; return 0; } return 1;
P_0c0673a8: /* original 4f22, guest PC 0x0c0673a8 */
if(!s->budget--) { s->failed_pc=0x0c0673a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0673aa;
P_0c0673aa: /* original 904a, guest PC 0x0c0673aa */
if(!s->budget--) { s->failed_pc=0x0c0673aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067442u,2);
goto P_0c0673ac;
P_0c0673ac: /* original 6243, guest PC 0x0c0673ac */
if(!s->budget--) { s->failed_pc=0x0c0673acu; return 0; }
r[2]=r[4];
goto P_0c0673ae;
P_0c0673ae: /* original 9349, guest PC 0x0c0673ae */
if(!s->budget--) { s->failed_pc=0x0c0673aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067444u,2);
goto P_0c0673b0;
P_0c0673b0: /* original 4f12, guest PC 0x0c0673b0 */
if(!s->budget--) { s->failed_pc=0x0c0673b0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0673b2;
P_0c0673b2: /* original 3f0c, guest PC 0x0c0673b2 */
if(!s->budget--) { s->failed_pc=0x0c0673b2u; return 0; }
r[15]+=r[0];
goto P_0c0673b4;
P_0c0673b4: /* original 33fc, guest PC 0x0c0673b4 */
if(!s->budget--) { s->failed_pc=0x0c0673b4u; return 0; }
r[3]+=r[15];
goto P_0c0673b6;
P_0c0673b6: /* original 2342, guest PC 0x0c0673b6 */
if(!s->budget--) { s->failed_pc=0x0c0673b6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0673b8;
P_0c0673b8: /* original 9045, guest PC 0x0c0673b8 */
if(!s->budget--) { s->failed_pc=0x0c0673b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067446u,2);
goto P_0c0673ba;
P_0c0673ba: /* original 032e, guest PC 0x0c0673ba */
if(!s->budget--) { s->failed_pc=0x0c0673bau; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0673bc;
P_0c0673bc: /* original 9044, guest PC 0x0c0673bc */
if(!s->budget--) { s->failed_pc=0x0c0673bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067448u,2);
goto P_0c0673be;
P_0c0673be: /* original 0f36, guest PC 0x0c0673be */
if(!s->budget--) { s->failed_pc=0x0c0673beu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0673c0;
P_0c0673c0: /* original 9040, guest PC 0x0c0673c0 */
if(!s->budget--) { s->failed_pc=0x0c0673c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067444u,2);
goto P_0c0673c2;
P_0c0673c2: /* original 9142, guest PC 0x0c0673c2 */
if(!s->budget--) { s->failed_pc=0x0c0673c2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744au,2);
goto P_0c0673c4;
P_0c0673c4: /* original 02fe, guest PC 0x0c0673c4 */
if(!s->budget--) { s->failed_pc=0x0c0673c4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0673c6;
P_0c0673c6: /* original 31fc, guest PC 0x0c0673c6 */
if(!s->budget--) { s->failed_pc=0x0c0673c6u; return 0; }
r[1]+=r[15];
goto P_0c0673c8;
P_0c0673c8: /* original 8523, guest PC 0x0c0673c8 */
if(!s->budget--) { s->failed_pc=0x0c0673c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+6,2);
goto P_0c0673ca;
P_0c0673ca: /* original 600d, guest PC 0x0c0673ca */
if(!s->budget--) { s->failed_pc=0x0c0673cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0673cc;
P_0c0673cc: /* original 2102, guest PC 0x0c0673cc */
if(!s->budget--) { s->failed_pc=0x0c0673ccu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0673ce;
P_0c0673ce: /* original d123, guest PC 0x0c0673ce */
if(!s->budget--) { s->failed_pc=0x0c0673ceu; return 0; }
r[1]=read(ram,0x0c06745cu,4);
goto P_0c0673d0;
P_0c0673d0: /* original e320, guest PC 0x0c0673d0 */
if(!s->budget--) { s->failed_pc=0x0c0673d0u; return 0; }
r[3]=0x00000020u;
goto P_0c0673d2;
P_0c0673d2: /* original 6212, guest PC 0x0c0673d2 */
if(!s->budget--) { s->failed_pc=0x0c0673d2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0673d4;
P_0c0673d4: /* original 3237, guest PC 0x0c0673d4 */
if(!s->budget--) { s->failed_pc=0x0c0673d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0673d6;
P_0c0673d6: /* original 8b74, guest PC 0x0c0673d6 */
if(!s->budget--) { s->failed_pc=0x0c0673d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0674c2; }
goto P_0c0673d8;
P_0c0673d8: /* original d020, guest PC 0x0c0673d8 */
if(!s->budget--) { s->failed_pc=0x0c0673d8u; return 0; }
r[0]=read(ram,0x0c06745cu,4);
goto P_0c0673da;
P_0c0673da: /* original 6102, guest PC 0x0c0673da */
if(!s->budget--) { s->failed_pc=0x0c0673dau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0673dc;
P_0c0673dc: /* original 9036, guest PC 0x0c0673dc */
if(!s->budget--) { s->failed_pc=0x0c0673dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744cu,2);
goto P_0c0673de;
P_0c0673de: /* original 71e0, guest PC 0x0c0673de */
if(!s->budget--) { s->failed_pc=0x0c0673deu; return 0; }
r[1]+=0xffffffe0u;
goto P_0c0673e0;
P_0c0673e0: /* original 0f16, guest PC 0x0c0673e0 */
if(!s->budget--) { s->failed_pc=0x0c0673e0u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0673e2;
P_0c0673e2: /* original d01f, guest PC 0x0c0673e2 */
if(!s->budget--) { s->failed_pc=0x0c0673e2u; return 0; }
r[0]=read(ram,0x0c067460u,4);
goto P_0c0673e4;
P_0c0673e4: /* original 6202, guest PC 0x0c0673e4 */
if(!s->budget--) { s->failed_pc=0x0c0673e4u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c0673e6;
P_0c0673e6: /* original 9032, guest PC 0x0c0673e6 */
if(!s->budget--) { s->failed_pc=0x0c0673e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744eu,2);
goto P_0c0673e8;
P_0c0673e8: /* original 0f26, guest PC 0x0c0673e8 */
if(!s->budget--) { s->failed_pc=0x0c0673e8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0673ea;
P_0c0673ea: /* original 9031, guest PC 0x0c0673ea */
if(!s->budget--) { s->failed_pc=0x0c0673eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067450u,2);
goto P_0c0673ec;
P_0c0673ec: /* original d31d, guest PC 0x0c0673ec */
if(!s->budget--) { s->failed_pc=0x0c0673ecu; return 0; }
r[3]=read(ram,0x0c067464u,4);
goto P_0c0673ee;
P_0c0673ee: /* original 0f36, guest PC 0x0c0673ee */
if(!s->budget--) { s->failed_pc=0x0c0673eeu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0673f0;
P_0c0673f0: /* original 6013, guest PC 0x0c0673f0 */
if(!s->budget--) { s->failed_pc=0x0c0673f0u; return 0; }
r[0]=r[1];
goto P_0c0673f2;
P_0c0673f2: /* original 8806, guest PC 0x0c0673f2 */
if(!s->budget--) { s->failed_pc=0x0c0673f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0673f4;
P_0c0673f4: /* original 8938, guest PC 0x0c0673f4 */
if(!s->budget--) { s->failed_pc=0x0c0673f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c067468; }
goto P_0c0673f6;
P_0c0673f6: /* original e2fd, guest PC 0x0c0673f6 */
if(!s->budget--) { s->failed_pc=0x0c0673f6u; return 0; }
r[2]=0xfffffffdu;
goto P_0c0673f8;
P_0c0673f8: /* original 902b, guest PC 0x0c0673f8 */
if(!s->budget--) { s->failed_pc=0x0c0673f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c0673fa;
P_0c0673fa: /* original 0127, guest PC 0x0c0673fa */
if(!s->budget--) { s->failed_pc=0x0c0673fau; return 0; }
r[19]=r[1]*r[2];
goto P_0c0673fc;
P_0c0673fc: /* original 011a, guest PC 0x0c0673fc */
if(!s->budget--) { s->failed_pc=0x0c0673fcu; return 0; }
r[1]=r[19];
goto P_0c0673fe;
P_0c0673fe: /* original 0f16, guest PC 0x0c0673fe */
if(!s->budget--) { s->failed_pc=0x0c0673feu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c067400;
P_0c067400: /* original e107, guest PC 0x0c067400 */
if(!s->budget--) { s->failed_pc=0x0c067400u; return 0; }
r[1]=0x00000007u;
goto P_0c067402;
P_0c067402: /* original 9023, guest PC 0x0c067402 */
if(!s->budget--) { s->failed_pc=0x0c067402u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06744cu,2);
goto P_0c067404;
P_0c067404: /* original 03fe, guest PC 0x0c067404 */
if(!s->budget--) { s->failed_pc=0x0c067404u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c067406;
P_0c067406: /* original 9025, guest PC 0x0c067406 */
if(!s->budget--) { s->failed_pc=0x0c067406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067454u,2);
goto P_0c067408;
P_0c067408: /* original 6233, guest PC 0x0c067408 */
if(!s->budget--) { s->failed_pc=0x0c067408u; return 0; }
r[2]=r[3];
goto P_0c06740a;
P_0c06740a: /* original 4208, guest PC 0x0c06740a */
if(!s->budget--) { s->failed_pc=0x0c06740au; return 0; }
r[2]<<=2;
goto P_0c06740c;
P_0c06740c: /* original 4300, guest PC 0x0c06740c */
if(!s->budget--) { s->failed_pc=0x0c06740cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06740e;
P_0c06740e: /* original 332c, guest PC 0x0c06740e */
if(!s->budget--) { s->failed_pc=0x0c06740eu; return 0; }
r[3]+=r[2];
goto P_0c067410;
P_0c067410: /* original 0f36, guest PC 0x0c067410 */
if(!s->budget--) { s->failed_pc=0x0c067410u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c067412;
P_0c067412: /* original 901e, guest PC 0x0c067412 */
if(!s->budget--) { s->failed_pc=0x0c067412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067414;
P_0c067414: /* original 02fe, guest PC 0x0c067414 */
if(!s->budget--) { s->failed_pc=0x0c067414u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067416;
P_0c067416: /* original 901c, guest PC 0x0c067416 */
if(!s->budget--) { s->failed_pc=0x0c067416u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067418;
P_0c067418: /* original 7218, guest PC 0x0c067418 */
if(!s->budget--) { s->failed_pc=0x0c067418u; return 0; }
r[2]+=0x00000018u;
goto P_0c06741a;
P_0c06741a: /* original 0f26, guest PC 0x0c06741a */
if(!s->budget--) { s->failed_pc=0x0c06741au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06741c;
P_0c06741c: /* original e060, guest PC 0x0c06741c */
if(!s->budget--) { s->failed_pc=0x0c06741cu; return 0; }
r[0]=0x00000060u;
goto P_0c06741e;
P_0c06741e: /* original 421d, guest PC 0x0c06741e */
if(!s->budget--) { s->failed_pc=0x0c06741eu; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?r[2]>>((-r[1])&31u):0):r[2]<<(r[1]&31u);
goto P_0c067420;
P_0c067420: /* original 0f26, guest PC 0x0c067420 */
if(!s->budget--) { s->failed_pc=0x0c067420u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067422;
P_0c067422: /* original 9016, guest PC 0x0c067422 */
if(!s->budget--) { s->failed_pc=0x0c067422u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067424;
P_0c067424: /* original 01fe, guest PC 0x0c067424 */
if(!s->budget--) { s->failed_pc=0x0c067424u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c067426;
P_0c067426: /* original 9014, guest PC 0x0c067426 */
if(!s->budget--) { s->failed_pc=0x0c067426u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067428;
P_0c067428: /* original 4128, guest PC 0x0c067428 */
if(!s->budget--) { s->failed_pc=0x0c067428u; return 0; }
r[1]<<=16;
goto P_0c06742a;
P_0c06742a: /* original 0f16, guest PC 0x0c06742a */
if(!s->budget--) { s->failed_pc=0x0c06742au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c06742c;
P_0c06742c: /* original 231b, guest PC 0x0c06742c */
if(!s->budget--) { s->failed_pc=0x0c06742cu; return 0; }
r[3]|=r[1];
goto P_0c06742e;
P_0c06742e: /* original 9013, guest PC 0x0c06742e */
if(!s->budget--) { s->failed_pc=0x0c06742eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067458u,2);
goto P_0c067430;
P_0c067430: /* original 9211, guest PC 0x0c067430 */
if(!s->budget--) { s->failed_pc=0x0c067430u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067456u,2);
goto P_0c067432;
P_0c067432: /* original 232b, guest PC 0x0c067432 */
if(!s->budget--) { s->failed_pc=0x0c067432u; return 0; }
r[3]|=r[2];
goto P_0c067434;
P_0c067434: /* original 0f26, guest PC 0x0c067434 */
if(!s->budget--) { s->failed_pc=0x0c067434u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067436;
P_0c067436: /* original 900c, guest PC 0x0c067436 */
if(!s->budget--) { s->failed_pc=0x0c067436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067452u,2);
goto P_0c067438;
P_0c067438: /* original e200, guest PC 0x0c067438 */
if(!s->budget--) { s->failed_pc=0x0c067438u; return 0; }
r[2]=0x00000000u;
goto P_0c06743a;
P_0c06743a: /* original 0f36, guest PC 0x0c06743a */
if(!s->budget--) { s->failed_pc=0x0c06743au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06743c;
P_0c06743c: /* original 900d, guest PC 0x0c06743c */
if(!s->budget--) { s->failed_pc=0x0c06743cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06745au,2);
goto P_0c06743e;
P_0c06743e: /* original a020, guest PC 0x0c06743e */
if(!s->budget--) { s->failed_pc=0x0c06743eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067482;
P_0c067440: /* original 0f26, guest PC 0x0c067440 */
if(!s->budget--) { s->failed_pc=0x0c067440u; return 0; }
write(ram,r[15]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c067442u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c067442u; return 0; } return 1;
P_0c067468: /* original e060, guest PC 0x0c067468 */
if(!s->budget--) { s->failed_pc=0x0c067468u; return 0; }
r[0]=0x00000060u;
goto P_0c06746a;
P_0c06746a: /* original e300, guest PC 0x0c06746a */
if(!s->budget--) { s->failed_pc=0x0c06746au; return 0; }
r[3]=0x00000000u;
goto P_0c06746c;
P_0c06746c: /* original 0f36, guest PC 0x0c06746c */
if(!s->budget--) { s->failed_pc=0x0c06746cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06746e;
P_0c06746e: /* original d329, guest PC 0x0c06746e */
if(!s->budget--) { s->failed_pc=0x0c06746eu; return 0; }
r[3]=read(ram,0x0c067514u,4);
goto P_0c067470;
P_0c067470: /* original 9046, guest PC 0x0c067470 */
if(!s->budget--) { s->failed_pc=0x0c067470u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067500u,2);
goto P_0c067472;
P_0c067472: /* original 430b, guest PC 0x0c067472 */
if(!s->budget--) { s->failed_pc=0x0c067472u; return 0; }
target=r[3];
r[16]=code_base|0x0c067476u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c067476u) { target=s->pc; goto dispatch; }
goto P_0c067476;
P_0c067474: /* original 04fe, guest PC 0x0c067474 */
if(!s->budget--) { s->failed_pc=0x0c067474u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c067476;
P_0c067476: /* original 9044, guest PC 0x0c067476 */
if(!s->budget--) { s->failed_pc=0x0c067476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067502u,2);
goto P_0c067478;
P_0c067478: /* original e200, guest PC 0x0c067478 */
if(!s->budget--) { s->failed_pc=0x0c067478u; return 0; }
r[2]=0x00000000u;
goto P_0c06747a;
P_0c06747a: /* original e302, guest PC 0x0c06747a */
if(!s->budget--) { s->failed_pc=0x0c06747au; return 0; }
r[3]=0x00000002u;
goto P_0c06747c;
P_0c06747c: /* original 0f26, guest PC 0x0c06747c */
if(!s->budget--) { s->failed_pc=0x0c06747cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06747e;
P_0c06747e: /* original 9041, guest PC 0x0c06747e */
if(!s->budget--) { s->failed_pc=0x0c06747eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067504u,2);
goto P_0c067480;
P_0c067480: /* original 0f36, guest PC 0x0c067480 */
if(!s->budget--) { s->failed_pc=0x0c067480u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c067482;
P_0c067482: /* original 913f, guest PC 0x0c067482 */
if(!s->budget--) { s->failed_pc=0x0c067482u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067504u,2);
goto P_0c067484;
P_0c067484: /* original 31fc, guest PC 0x0c067484 */
if(!s->budget--) { s->failed_pc=0x0c067484u; return 0; }
r[1]+=r[15];
goto P_0c067486;
P_0c067486: /* original 6012, guest PC 0x0c067486 */
if(!s->budget--) { s->failed_pc=0x0c067486u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c067488;
P_0c067488: /* original cb01, guest PC 0x0c067488 */
if(!s->budget--) { s->failed_pc=0x0c067488u; return 0; }
r[0]|=1u;
goto P_0c06748a;
P_0c06748a: /* original 2f06, guest PC 0x0c06748a */
if(!s->budget--) { s->failed_pc=0x0c06748au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06748c;
P_0c06748c: /* original 9038, guest PC 0x0c06748c */
if(!s->budget--) { s->failed_pc=0x0c06748cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067500u,2);
goto P_0c06748e;
P_0c06748e: /* original d322, guest PC 0x0c06748e */
if(!s->budget--) { s->failed_pc=0x0c06748eu; return 0; }
r[3]=read(ram,0x0c067518u,4);
goto P_0c067490;
P_0c067490: /* original 07fe, guest PC 0x0c067490 */
if(!s->budget--) { s->failed_pc=0x0c067490u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c067492;
P_0c067492: /* original 9038, guest PC 0x0c067492 */
if(!s->budget--) { s->failed_pc=0x0c067492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067506u,2);
goto P_0c067494;
P_0c067494: /* original 06fe, guest PC 0x0c067494 */
if(!s->budget--) { s->failed_pc=0x0c067494u; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c067496;
P_0c067496: /* original 9037, guest PC 0x0c067496 */
if(!s->budget--) { s->failed_pc=0x0c067496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067508u,2);
goto P_0c067498;
P_0c067498: /* original 05fe, guest PC 0x0c067498 */
if(!s->budget--) { s->failed_pc=0x0c067498u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c06749a;
P_0c06749a: /* original e064, guest PC 0x0c06749a */
if(!s->budget--) { s->failed_pc=0x0c06749au; return 0; }
r[0]=0x00000064u;
goto P_0c06749c;
P_0c06749c: /* original 430b, guest PC 0x0c06749c */
if(!s->budget--) { s->failed_pc=0x0c06749cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0674a0u;
r[4]=read(ram,r[15]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0674a0u) { target=s->pc; goto dispatch; }
goto P_0c0674a0;
P_0c06749e: /* original 04fe, guest PC 0x0c06749e */
if(!s->budget--) { s->failed_pc=0x0c06749eu; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c0674a0;
P_0c0674a0: /* original 9033, guest PC 0x0c0674a0 */
if(!s->budget--) { s->failed_pc=0x0c0674a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674a2;
P_0c0674a2: /* original 7f04, guest PC 0x0c0674a2 */
if(!s->budget--) { s->failed_pc=0x0c0674a2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0674a4;
P_0c0674a4: /* original e327, guest PC 0x0c0674a4 */
if(!s->budget--) { s->failed_pc=0x0c0674a4u; return 0; }
r[3]=0x00000027u;
goto P_0c0674a6;
P_0c0674a6: /* original 02fe, guest PC 0x0c0674a6 */
if(!s->budget--) { s->failed_pc=0x0c0674a6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0674a8;
P_0c0674a8: /* original 902f, guest PC 0x0c0674a8 */
if(!s->budget--) { s->failed_pc=0x0c0674a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674aa;
P_0c0674aa: /* original 7221, guest PC 0x0c0674aa */
if(!s->budget--) { s->failed_pc=0x0c0674aau; return 0; }
r[2]+=0x00000021u;
goto P_0c0674ac;
P_0c0674ac: /* original 3232, guest PC 0x0c0674ac */
if(!s->budget--) { s->failed_pc=0x0c0674acu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0674ae;
P_0c0674ae: /* original 8f04, guest PC 0x0c0674ae */
if(!s->budget--) { s->failed_pc=0x0c0674aeu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[2],4);
if(!cond) { goto P_0c0674ba; }
goto P_0c0674b2;
P_0c0674b0: /* original 0f26, guest PC 0x0c0674b0 */
if(!s->budget--) { s->failed_pc=0x0c0674b0u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0674b2;
P_0c0674b2: /* original 912a, guest PC 0x0c0674b2 */
if(!s->budget--) { s->failed_pc=0x0c0674b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674b4;
P_0c0674b4: /* original e0ff, guest PC 0x0c0674b4 */
if(!s->budget--) { s->failed_pc=0x0c0674b4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0674b6;
P_0c0674b6: /* original 31fc, guest PC 0x0c0674b6 */
if(!s->budget--) { s->failed_pc=0x0c0674b6u; return 0; }
r[1]+=r[15];
goto P_0c0674b8;
P_0c0674b8: /* original 2102, guest PC 0x0c0674b8 */
if(!s->budget--) { s->failed_pc=0x0c0674b8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0674ba;
P_0c0674ba: /* original 9026, guest PC 0x0c0674ba */
if(!s->budget--) { s->failed_pc=0x0c0674bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750au,2);
goto P_0c0674bc;
P_0c0674bc: /* original d217, guest PC 0x0c0674bc */
if(!s->budget--) { s->failed_pc=0x0c0674bcu; return 0; }
r[2]=read(ram,0x0c06751cu,4);
goto P_0c0674be;
P_0c0674be: /* original 03fe, guest PC 0x0c0674be */
if(!s->budget--) { s->failed_pc=0x0c0674beu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0674c0;
P_0c0674c0: /* original 2232, guest PC 0x0c0674c0 */
if(!s->budget--) { s->failed_pc=0x0c0674c0u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0674c2;
P_0c0674c2: /* original 9023, guest PC 0x0c0674c2 */
if(!s->budget--) { s->failed_pc=0x0c0674c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750cu,2);
goto P_0c0674c4;
P_0c0674c4: /* original 01fe, guest PC 0x0c0674c4 */
if(!s->budget--) { s->failed_pc=0x0c0674c4u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0674c6;
P_0c0674c6: /* original 9022, guest PC 0x0c0674c6 */
if(!s->budget--) { s->failed_pc=0x0c0674c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750eu,2);
goto P_0c0674c8;
P_0c0674c8: /* original 6311, guest PC 0x0c0674c8 */
if(!s->budget--) { s->failed_pc=0x0c0674c8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[1],2);
r[3]=tmp;
goto P_0c0674ca;
P_0c0674ca: /* original 633d, guest PC 0x0c0674ca */
if(!s->budget--) { s->failed_pc=0x0c0674cau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0674cc;
P_0c0674cc: /* original 0f36, guest PC 0x0c0674cc */
if(!s->budget--) { s->failed_pc=0x0c0674ccu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0674ce;
P_0c0674ce: /* original 901f, guest PC 0x0c0674ce */
if(!s->budget--) { s->failed_pc=0x0c0674ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067510u,2);
goto P_0c0674d0;
P_0c0674d0: /* original 02fe, guest PC 0x0c0674d0 */
if(!s->budget--) { s->failed_pc=0x0c0674d0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0674d2;
P_0c0674d2: /* original 3232, guest PC 0x0c0674d2 */
if(!s->budget--) { s->failed_pc=0x0c0674d2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0674d4;
P_0c0674d4: /* original 8902, guest PC 0x0c0674d4 */
if(!s->budget--) { s->failed_pc=0x0c0674d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0674dc; }
goto P_0c0674d6;
P_0c0674d6: /* original d112, guest PC 0x0c0674d6 */
if(!s->budget--) { s->failed_pc=0x0c0674d6u; return 0; }
r[1]=read(ram,0x0c067520u,4);
goto P_0c0674d8;
P_0c0674d8: /* original 412b, guest PC 0x0c0674d8 */
if(!s->budget--) { s->failed_pc=0x0c0674d8u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c06862au: goto P_0c06862a;
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
P_0c0674da: /* original 0009, guest PC 0x0c0674da */
if(!s->budget--) { s->failed_pc=0x0c0674dau; return 0; }
goto P_0c0674dc;
P_0c0674dc: /* original 9016, guest PC 0x0c0674dc */
if(!s->budget--) { s->failed_pc=0x0c0674dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750cu,2);
goto P_0c0674de;
P_0c0674de: /* original 9116, guest PC 0x0c0674de */
if(!s->budget--) { s->failed_pc=0x0c0674deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06750eu,2);
goto P_0c0674e0;
P_0c0674e0: /* original 03fe, guest PC 0x0c0674e0 */
if(!s->budget--) { s->failed_pc=0x0c0674e0u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0674e2;
P_0c0674e2: /* original 31fc, guest PC 0x0c0674e2 */
if(!s->budget--) { s->failed_pc=0x0c0674e2u; return 0; }
r[1]+=r[15];
goto P_0c0674e4;
P_0c0674e4: /* original 8432, guest PC 0x0c0674e4 */
if(!s->budget--) { s->failed_pc=0x0c0674e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0674e6;
P_0c0674e6: /* original 600c, guest PC 0x0c0674e6 */
if(!s->budget--) { s->failed_pc=0x0c0674e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0674e8;
P_0c0674e8: /* original 2102, guest PC 0x0c0674e8 */
if(!s->budget--) { s->failed_pc=0x0c0674e8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0674ea;
P_0c0674ea: /* original e11f, guest PC 0x0c0674ea */
if(!s->budget--) { s->failed_pc=0x0c0674eau; return 0; }
r[1]=0x0000001fu;
goto P_0c0674ec;
P_0c0674ec: /* original 3012, guest PC 0x0c0674ec */
if(!s->budget--) { s->failed_pc=0x0c0674ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c0674ee;
P_0c0674ee: /* original 8b01, guest PC 0x0c0674ee */
if(!s->budget--) { s->failed_pc=0x0c0674eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0674f4; }
goto P_0c0674f0;
P_0c0674f0: /* original a084, guest PC 0x0c0674f0 */
if(!s->budget--) { s->failed_pc=0x0c0674f0u; return 0; }
goto P_0c0675fc;
P_0c0674f2: /* original 0009, guest PC 0x0c0674f2 */
if(!s->budget--) { s->failed_pc=0x0c0674f2u; return 0; }
goto P_0c0674f4;
P_0c0674f4: /* original 4000, guest PC 0x0c0674f4 */
if(!s->budget--) { s->failed_pc=0x0c0674f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0674f6;
P_0c0674f6: /* original 6103, guest PC 0x0c0674f6 */
if(!s->budget--) { s->failed_pc=0x0c0674f6u; return 0; }
r[1]=r[0];
goto P_0c0674f8;
P_0c0674f8: /* original c70a, guest PC 0x0c0674f8 */
if(!s->budget--) { s->failed_pc=0x0c0674f8u; return 0; }
r[0]=code_base|0x00067524u;
goto P_0c0674fa;
P_0c0674fa: /* original 001d, guest PC 0x0c0674fa */
if(!s->budget--) { s->failed_pc=0x0c0674fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0674fc;
P_0c0674fc: /* original 0023, guest PC 0x0c0674fc */
if(!s->budget--) { s->failed_pc=0x0c0674fcu; return 0; }
target=r[0]+0x0c067500u;
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
P_0c0674fe: /* original 0009, guest PC 0x0c0674fe */
if(!s->budget--) { s->failed_pc=0x0c0674feu; return 0; }
if(!vf3_matrix_family(0x0c067500u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c067500u; return 0; } return 1;
P_0c0675fc: /* original 9009, guest PC 0x0c0675fc */
if(!s->budget--) { s->failed_pc=0x0c0675fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067612u,2);
goto P_0c0675fe;
P_0c0675fe: /* original 02fe, guest PC 0x0c0675fe */
if(!s->budget--) { s->failed_pc=0x0c0675feu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c067600;
P_0c067600: /* original 9007, guest PC 0x0c067600 */
if(!s->budget--) { s->failed_pc=0x0c067600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067612u,2);
goto P_0c067602;
P_0c067602: /* original 7206, guest PC 0x0c067602 */
if(!s->budget--) { s->failed_pc=0x0c067602u; return 0; }
r[2]+=0x00000006u;
goto P_0c067604;
P_0c067604: /* original 0f26, guest PC 0x0c067604 */
if(!s->budget--) { s->failed_pc=0x0c067604u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c067606;
P_0c067606: /* original 9006, guest PC 0x0c067606 */
if(!s->budget--) { s->failed_pc=0x0c067606u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067616u,2);
goto P_0c067608;
P_0c067608: /* original 03fe, guest PC 0x0c067608 */
if(!s->budget--) { s->failed_pc=0x0c067608u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06760a;
P_0c06760a: /* original 9005, guest PC 0x0c06760a */
if(!s->budget--) { s->failed_pc=0x0c06760au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c067618u,2);
goto P_0c06760c;
P_0c06760c: /* original 0326, guest PC 0x0c06760c */
if(!s->budget--) { s->failed_pc=0x0c06760cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06760e;
P_0c06760e: /* original aede, guest PC 0x0c06760e */
if(!s->budget--) { s->failed_pc=0x0c06760eu; return 0; }
goto P_0c0673ce;
P_0c067610: /* original 0009, guest PC 0x0c067610 */
if(!s->budget--) { s->failed_pc=0x0c067610u; return 0; }
if(!vf3_matrix_family(0x0c067612u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c067612u; return 0; } return 1;
P_0c06862a: /* original 914c, guest PC 0x0c06862a */
if(!s->budget--) { s->failed_pc=0x0c06862au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c6u,2);
goto P_0c06862c;
P_0c06862c: /* original 3f1c, guest PC 0x0c06862c */
if(!s->budget--) { s->failed_pc=0x0c06862cu; return 0; }
r[15]+=r[1];
goto P_0c06862e;
P_0c06862e: /* original 4f16, guest PC 0x0c06862e */
if(!s->budget--) { s->failed_pc=0x0c06862eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c068630;
P_0c068630: /* original 4f26, guest PC 0x0c068630 */
if(!s->budget--) { s->failed_pc=0x0c068630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068632;
P_0c068632: /* original 000b, guest PC 0x0c068632 */
if(!s->budget--) { s->failed_pc=0x0c068632u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068634: /* original 0009, guest PC 0x0c068634 */
if(!s->budget--) { s->failed_pc=0x0c068634u; return 0; }
return vf3_matrix_family(0x0c068636u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
