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
int vf3_away_batch29_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0663d8u: goto P_0c0663d8;
case 0x0c0663dau: goto P_0c0663da;
case 0x0c0663dcu: goto P_0c0663dc;
case 0x0c0663deu: goto P_0c0663de;
case 0x0c0663e0u: goto P_0c0663e0;
case 0x0c0663e2u: goto P_0c0663e2;
case 0x0c0663e4u: goto P_0c0663e4;
case 0x0c0663e6u: goto P_0c0663e6;
case 0x0c0663e8u: goto P_0c0663e8;
case 0x0c0663eau: goto P_0c0663ea;
case 0x0c0663ecu: goto P_0c0663ec;
case 0x0c0663eeu: goto P_0c0663ee;
case 0x0c0663f0u: goto P_0c0663f0;
case 0x0c0663f2u: goto P_0c0663f2;
case 0x0c0663f4u: goto P_0c0663f4;
case 0x0c0663f6u: goto P_0c0663f6;
case 0x0c0663f8u: goto P_0c0663f8;
case 0x0c0663fau: goto P_0c0663fa;
case 0x0c0663fcu: goto P_0c0663fc;
case 0x0c0663feu: goto P_0c0663fe;
case 0x0c066400u: goto P_0c066400;
case 0x0c066402u: goto P_0c066402;
case 0x0c066404u: goto P_0c066404;
case 0x0c066406u: goto P_0c066406;
case 0x0c066408u: goto P_0c066408;
case 0x0c06640au: goto P_0c06640a;
case 0x0c06640cu: goto P_0c06640c;
case 0x0c06640eu: goto P_0c06640e;
case 0x0c066410u: goto P_0c066410;
case 0x0c066412u: goto P_0c066412;
case 0x0c066414u: goto P_0c066414;
case 0x0c066416u: goto P_0c066416;
case 0x0c066418u: goto P_0c066418;
case 0x0c06641au: goto P_0c06641a;
case 0x0c06641cu: goto P_0c06641c;
case 0x0c06641eu: goto P_0c06641e;
case 0x0c066420u: goto P_0c066420;
case 0x0c066422u: goto P_0c066422;
case 0x0c066424u: goto P_0c066424;
case 0x0c066426u: goto P_0c066426;
case 0x0c066428u: goto P_0c066428;
case 0x0c06642au: goto P_0c06642a;
case 0x0c06642cu: goto P_0c06642c;
case 0x0c06642eu: goto P_0c06642e;
case 0x0c066430u: goto P_0c066430;
case 0x0c066432u: goto P_0c066432;
case 0x0c066434u: goto P_0c066434;
case 0x0c066436u: goto P_0c066436;
case 0x0c066438u: goto P_0c066438;
case 0x0c06643au: goto P_0c06643a;
case 0x0c06643cu: goto P_0c06643c;
case 0x0c06643eu: goto P_0c06643e;
case 0x0c066440u: goto P_0c066440;
case 0x0c066442u: goto P_0c066442;
case 0x0c066444u: goto P_0c066444;
case 0x0c066446u: goto P_0c066446;
case 0x0c066448u: goto P_0c066448;
case 0x0c06644au: goto P_0c06644a;
case 0x0c06644cu: goto P_0c06644c;
case 0x0c06644eu: goto P_0c06644e;
case 0x0c066450u: goto P_0c066450;
case 0x0c066452u: goto P_0c066452;
case 0x0c066454u: goto P_0c066454;
case 0x0c066456u: goto P_0c066456;
case 0x0c066458u: goto P_0c066458;
case 0x0c06645au: goto P_0c06645a;
case 0x0c06645cu: goto P_0c06645c;
case 0x0c06645eu: goto P_0c06645e;
case 0x0c066460u: goto P_0c066460;
case 0x0c066462u: goto P_0c066462;
case 0x0c066464u: goto P_0c066464;
case 0x0c066466u: goto P_0c066466;
case 0x0c066468u: goto P_0c066468;
case 0x0c06646au: goto P_0c06646a;
case 0x0c06646cu: goto P_0c06646c;
case 0x0c06646eu: goto P_0c06646e;
case 0x0c066470u: goto P_0c066470;
case 0x0c066472u: goto P_0c066472;
case 0x0c066474u: goto P_0c066474;
case 0x0c066476u: goto P_0c066476;
case 0x0c066478u: goto P_0c066478;
case 0x0c06647au: goto P_0c06647a;
case 0x0c06647cu: goto P_0c06647c;
case 0x0c06647eu: goto P_0c06647e;
case 0x0c066480u: goto P_0c066480;
case 0x0c066482u: goto P_0c066482;
case 0x0c066484u: goto P_0c066484;
case 0x0c066486u: goto P_0c066486;
case 0x0c066488u: goto P_0c066488;
case 0x0c06648au: goto P_0c06648a;
case 0x0c06648cu: goto P_0c06648c;
case 0x0c06648eu: goto P_0c06648e;
case 0x0c066490u: goto P_0c066490;
case 0x0c066492u: goto P_0c066492;
case 0x0c066494u: goto P_0c066494;
case 0x0c066496u: goto P_0c066496;
case 0x0c066498u: goto P_0c066498;
case 0x0c06649au: goto P_0c06649a;
case 0x0c06649cu: goto P_0c06649c;
case 0x0c06649eu: goto P_0c06649e;
case 0x0c0664a0u: goto P_0c0664a0;
case 0x0c0664a2u: goto P_0c0664a2;
case 0x0c0664a4u: goto P_0c0664a4;
case 0x0c0664a6u: goto P_0c0664a6;
case 0x0c0664a8u: goto P_0c0664a8;
case 0x0c0664aau: goto P_0c0664aa;
case 0x0c0664acu: goto P_0c0664ac;
case 0x0c0664aeu: goto P_0c0664ae;
case 0x0c0664b0u: goto P_0c0664b0;
case 0x0c0664b2u: goto P_0c0664b2;
case 0x0c0664b4u: goto P_0c0664b4;
case 0x0c0664b6u: goto P_0c0664b6;
case 0x0c0664b8u: goto P_0c0664b8;
case 0x0c0664bau: goto P_0c0664ba;
case 0x0c0664bcu: goto P_0c0664bc;
case 0x0c0664beu: goto P_0c0664be;
case 0x0c0664c0u: goto P_0c0664c0;
case 0x0c0664c2u: goto P_0c0664c2;
case 0x0c0664c4u: goto P_0c0664c4;
case 0x0c0664c6u: goto P_0c0664c6;
case 0x0c0664c8u: goto P_0c0664c8;
case 0x0c0664cau: goto P_0c0664ca;
case 0x0c0664ccu: goto P_0c0664cc;
case 0x0c0664ceu: goto P_0c0664ce;
case 0x0c0664d0u: goto P_0c0664d0;
case 0x0c0664d2u: goto P_0c0664d2;
case 0x0c0664d4u: goto P_0c0664d4;
case 0x0c0664d6u: goto P_0c0664d6;
case 0x0c0664d8u: goto P_0c0664d8;
case 0x0c0664dau: goto P_0c0664da;
case 0x0c0664dcu: goto P_0c0664dc;
case 0x0c0664deu: goto P_0c0664de;
case 0x0c066530u: goto P_0c066530;
case 0x0c066532u: goto P_0c066532;
case 0x0c066534u: goto P_0c066534;
case 0x0c066536u: goto P_0c066536;
case 0x0c066538u: goto P_0c066538;
case 0x0c06653au: goto P_0c06653a;
case 0x0c06653cu: goto P_0c06653c;
case 0x0c06653eu: goto P_0c06653e;
case 0x0c066540u: goto P_0c066540;
case 0x0c066542u: goto P_0c066542;
case 0x0c066544u: goto P_0c066544;
case 0x0c066546u: goto P_0c066546;
case 0x0c066548u: goto P_0c066548;
case 0x0c06654au: goto P_0c06654a;
case 0x0c06654cu: goto P_0c06654c;
case 0x0c06654eu: goto P_0c06654e;
case 0x0c066550u: goto P_0c066550;
case 0x0c066552u: goto P_0c066552;
case 0x0c066554u: goto P_0c066554;
case 0x0c066556u: goto P_0c066556;
case 0x0c066558u: goto P_0c066558;
case 0x0c06655au: goto P_0c06655a;
case 0x0c06655cu: goto P_0c06655c;
case 0x0c06655eu: goto P_0c06655e;
case 0x0c066560u: goto P_0c066560;
case 0x0c066562u: goto P_0c066562;
case 0x0c066564u: goto P_0c066564;
case 0x0c066566u: goto P_0c066566;
case 0x0c066568u: goto P_0c066568;
case 0x0c06656au: goto P_0c06656a;
case 0x0c06656cu: goto P_0c06656c;
case 0x0c06656eu: goto P_0c06656e;
case 0x0c066570u: goto P_0c066570;
case 0x0c066572u: goto P_0c066572;
case 0x0c066574u: goto P_0c066574;
case 0x0c066576u: goto P_0c066576;
case 0x0c066578u: goto P_0c066578;
case 0x0c06657au: goto P_0c06657a;
case 0x0c06657cu: goto P_0c06657c;
case 0x0c06657eu: goto P_0c06657e;
case 0x0c066580u: goto P_0c066580;
case 0x0c066582u: goto P_0c066582;
case 0x0c066584u: goto P_0c066584;
case 0x0c066586u: goto P_0c066586;
case 0x0c066588u: goto P_0c066588;
case 0x0c06658au: goto P_0c06658a;
case 0x0c06658cu: goto P_0c06658c;
case 0x0c06658eu: goto P_0c06658e;
case 0x0c066590u: goto P_0c066590;
case 0x0c066592u: goto P_0c066592;
case 0x0c066594u: goto P_0c066594;
case 0x0c066596u: goto P_0c066596;
case 0x0c066598u: goto P_0c066598;
case 0x0c06659au: goto P_0c06659a;
case 0x0c06659cu: goto P_0c06659c;
case 0x0c06659eu: goto P_0c06659e;
case 0x0c0665a0u: goto P_0c0665a0;
case 0x0c0665a2u: goto P_0c0665a2;
case 0x0c0665a4u: goto P_0c0665a4;
case 0x0c0665a6u: goto P_0c0665a6;
case 0x0c0665a8u: goto P_0c0665a8;
case 0x0c0665aau: goto P_0c0665aa;
case 0x0c0665acu: goto P_0c0665ac;
case 0x0c0665aeu: goto P_0c0665ae;
case 0x0c0665b0u: goto P_0c0665b0;
case 0x0c0665b2u: goto P_0c0665b2;
case 0x0c0665b4u: goto P_0c0665b4;
case 0x0c0665b6u: goto P_0c0665b6;
case 0x0c0665b8u: goto P_0c0665b8;
case 0x0c0665bau: goto P_0c0665ba;
case 0x0c0665bcu: goto P_0c0665bc;
case 0x0c0665beu: goto P_0c0665be;
case 0x0c0665c0u: goto P_0c0665c0;
case 0x0c0665c2u: goto P_0c0665c2;
case 0x0c0665c4u: goto P_0c0665c4;
case 0x0c0665c6u: goto P_0c0665c6;
case 0x0c0665c8u: goto P_0c0665c8;
case 0x0c0665cau: goto P_0c0665ca;
case 0x0c0665ccu: goto P_0c0665cc;
case 0x0c0665ceu: goto P_0c0665ce;
case 0x0c0665d0u: goto P_0c0665d0;
case 0x0c0665d2u: goto P_0c0665d2;
case 0x0c0665d4u: goto P_0c0665d4;
case 0x0c0665d6u: goto P_0c0665d6;
case 0x0c0665d8u: goto P_0c0665d8;
case 0x0c0665dau: goto P_0c0665da;
case 0x0c0665dcu: goto P_0c0665dc;
case 0x0c0665deu: goto P_0c0665de;
case 0x0c0665e0u: goto P_0c0665e0;
case 0x0c0665e2u: goto P_0c0665e2;
case 0x0c0665e4u: goto P_0c0665e4;
case 0x0c0665e6u: goto P_0c0665e6;
case 0x0c0665e8u: goto P_0c0665e8;
case 0x0c0665eau: goto P_0c0665ea;
case 0x0c0665ecu: goto P_0c0665ec;
case 0x0c0665eeu: goto P_0c0665ee;
case 0x0c0665f0u: goto P_0c0665f0;
case 0x0c0665f2u: goto P_0c0665f2;
case 0x0c0665f4u: goto P_0c0665f4;
case 0x0c0665f6u: goto P_0c0665f6;
case 0x0c0665f8u: goto P_0c0665f8;
case 0x0c0665fau: goto P_0c0665fa;
case 0x0c0665fcu: goto P_0c0665fc;
case 0x0c0665feu: goto P_0c0665fe;
case 0x0c066600u: goto P_0c066600;
case 0x0c066602u: goto P_0c066602;
case 0x0c066604u: goto P_0c066604;
case 0x0c066606u: goto P_0c066606;
case 0x0c066608u: goto P_0c066608;
case 0x0c06660au: goto P_0c06660a;
case 0x0c06660cu: goto P_0c06660c;
case 0x0c06660eu: goto P_0c06660e;
case 0x0c066610u: goto P_0c066610;
case 0x0c066612u: goto P_0c066612;
case 0x0c066614u: goto P_0c066614;
case 0x0c066616u: goto P_0c066616;
case 0x0c066618u: goto P_0c066618;
case 0x0c06661au: goto P_0c06661a;
case 0x0c06661cu: goto P_0c06661c;
case 0x0c06661eu: goto P_0c06661e;
case 0x0c066620u: goto P_0c066620;
case 0x0c066622u: goto P_0c066622;
case 0x0c066624u: goto P_0c066624;
case 0x0c066626u: goto P_0c066626;
case 0x0c066628u: goto P_0c066628;
case 0x0c06662au: goto P_0c06662a;
case 0x0c06662cu: goto P_0c06662c;
case 0x0c06662eu: goto P_0c06662e;
case 0x0c066630u: goto P_0c066630;
case 0x0c066632u: goto P_0c066632;
case 0x0c066634u: goto P_0c066634;
case 0x0c066636u: goto P_0c066636;
case 0x0c066638u: goto P_0c066638;
case 0x0c06663au: goto P_0c06663a;
case 0x0c06663cu: goto P_0c06663c;
case 0x0c06663eu: goto P_0c06663e;
case 0x0c066640u: goto P_0c066640;
case 0x0c066642u: goto P_0c066642;
case 0x0c066644u: goto P_0c066644;
case 0x0c066646u: goto P_0c066646;
case 0x0c066648u: goto P_0c066648;
case 0x0c06664au: goto P_0c06664a;
case 0x0c06664cu: goto P_0c06664c;
case 0x0c06664eu: goto P_0c06664e;
case 0x0c066680u: goto P_0c066680;
case 0x0c066682u: goto P_0c066682;
case 0x0c066684u: goto P_0c066684;
case 0x0c066686u: goto P_0c066686;
case 0x0c066688u: goto P_0c066688;
case 0x0c06668au: goto P_0c06668a;
case 0x0c06668cu: goto P_0c06668c;
case 0x0c06668eu: goto P_0c06668e;
case 0x0c066690u: goto P_0c066690;
case 0x0c066692u: goto P_0c066692;
case 0x0c066694u: goto P_0c066694;
case 0x0c066696u: goto P_0c066696;
case 0x0c066698u: goto P_0c066698;
case 0x0c06669au: goto P_0c06669a;
case 0x0c06669cu: goto P_0c06669c;
case 0x0c06669eu: goto P_0c06669e;
case 0x0c0666a0u: goto P_0c0666a0;
case 0x0c0666a2u: goto P_0c0666a2;
case 0x0c0666a4u: goto P_0c0666a4;
case 0x0c0666a6u: goto P_0c0666a6;
case 0x0c0666a8u: goto P_0c0666a8;
case 0x0c0666aau: goto P_0c0666aa;
case 0x0c0666acu: goto P_0c0666ac;
case 0x0c0666aeu: goto P_0c0666ae;
case 0x0c0666b0u: goto P_0c0666b0;
case 0x0c0666b2u: goto P_0c0666b2;
case 0x0c0666b4u: goto P_0c0666b4;
case 0x0c0666b6u: goto P_0c0666b6;
case 0x0c0666b8u: goto P_0c0666b8;
case 0x0c0666bau: goto P_0c0666ba;
case 0x0c0666bcu: goto P_0c0666bc;
case 0x0c0666beu: goto P_0c0666be;
case 0x0c0666c0u: goto P_0c0666c0;
case 0x0c0666c2u: goto P_0c0666c2;
case 0x0c0666c4u: goto P_0c0666c4;
case 0x0c0666c6u: goto P_0c0666c6;
case 0x0c0666c8u: goto P_0c0666c8;
case 0x0c0666cau: goto P_0c0666ca;
case 0x0c0666ccu: goto P_0c0666cc;
case 0x0c0666ceu: goto P_0c0666ce;
case 0x0c0666d0u: goto P_0c0666d0;
case 0x0c0666d2u: goto P_0c0666d2;
case 0x0c0666d4u: goto P_0c0666d4;
case 0x0c0666d6u: goto P_0c0666d6;
case 0x0c0666d8u: goto P_0c0666d8;
case 0x0c0666dau: goto P_0c0666da;
case 0x0c0666dcu: goto P_0c0666dc;
case 0x0c0666deu: goto P_0c0666de;
case 0x0c0666e0u: goto P_0c0666e0;
case 0x0c0666e2u: goto P_0c0666e2;
case 0x0c0666e4u: goto P_0c0666e4;
case 0x0c0666e6u: goto P_0c0666e6;
case 0x0c0666e8u: goto P_0c0666e8;
case 0x0c0666eau: goto P_0c0666ea;
case 0x0c0666ecu: goto P_0c0666ec;
case 0x0c0666eeu: goto P_0c0666ee;
case 0x0c0666f0u: goto P_0c0666f0;
case 0x0c0666f2u: goto P_0c0666f2;
case 0x0c0666f4u: goto P_0c0666f4;
case 0x0c0666f6u: goto P_0c0666f6;
case 0x0c0666f8u: goto P_0c0666f8;
case 0x0c0666fau: goto P_0c0666fa;
case 0x0c0666fcu: goto P_0c0666fc;
case 0x0c0666feu: goto P_0c0666fe;
case 0x0c066700u: goto P_0c066700;
case 0x0c066702u: goto P_0c066702;
case 0x0c066704u: goto P_0c066704;
case 0x0c066706u: goto P_0c066706;
case 0x0c066708u: goto P_0c066708;
case 0x0c06670au: goto P_0c06670a;
case 0x0c06670cu: goto P_0c06670c;
case 0x0c06670eu: goto P_0c06670e;
case 0x0c066710u: goto P_0c066710;
case 0x0c066712u: goto P_0c066712;
case 0x0c066714u: goto P_0c066714;
case 0x0c066716u: goto P_0c066716;
case 0x0c066718u: goto P_0c066718;
case 0x0c06671au: goto P_0c06671a;
case 0x0c06671cu: goto P_0c06671c;
case 0x0c06671eu: goto P_0c06671e;
case 0x0c066720u: goto P_0c066720;
case 0x0c066722u: goto P_0c066722;
case 0x0c066724u: goto P_0c066724;
case 0x0c066726u: goto P_0c066726;
case 0x0c066728u: goto P_0c066728;
case 0x0c06672au: goto P_0c06672a;
case 0x0c06672cu: goto P_0c06672c;
case 0x0c06672eu: goto P_0c06672e;
case 0x0c066730u: goto P_0c066730;
case 0x0c066732u: goto P_0c066732;
case 0x0c066734u: goto P_0c066734;
case 0x0c066736u: goto P_0c066736;
case 0x0c066738u: goto P_0c066738;
case 0x0c06673au: goto P_0c06673a;
case 0x0c06673cu: goto P_0c06673c;
case 0x0c06673eu: goto P_0c06673e;
case 0x0c066740u: goto P_0c066740;
case 0x0c066742u: goto P_0c066742;
case 0x0c066744u: goto P_0c066744;
case 0x0c066746u: goto P_0c066746;
case 0x0c066748u: goto P_0c066748;
case 0x0c06674au: goto P_0c06674a;
case 0x0c06674cu: goto P_0c06674c;
case 0x0c06674eu: goto P_0c06674e;
case 0x0c066750u: goto P_0c066750;
case 0x0c066752u: goto P_0c066752;
case 0x0c066754u: goto P_0c066754;
case 0x0c066756u: goto P_0c066756;
case 0x0c066758u: goto P_0c066758;
case 0x0c06675au: goto P_0c06675a;
case 0x0c06675cu: goto P_0c06675c;
case 0x0c06675eu: goto P_0c06675e;
case 0x0c066760u: goto P_0c066760;
case 0x0c066762u: goto P_0c066762;
case 0x0c066764u: goto P_0c066764;
case 0x0c066766u: goto P_0c066766;
case 0x0c066768u: goto P_0c066768;
case 0x0c06676au: goto P_0c06676a;
case 0x0c06676cu: goto P_0c06676c;
case 0x0c06676eu: goto P_0c06676e;
case 0x0c066770u: goto P_0c066770;
case 0x0c066772u: goto P_0c066772;
case 0x0c066774u: goto P_0c066774;
case 0x0c066776u: goto P_0c066776;
case 0x0c066778u: goto P_0c066778;
case 0x0c06677au: goto P_0c06677a;
case 0x0c06677cu: goto P_0c06677c;
case 0x0c0667b0u: goto P_0c0667b0;
case 0x0c0667b2u: goto P_0c0667b2;
case 0x0c0667b4u: goto P_0c0667b4;
case 0x0c0667b6u: goto P_0c0667b6;
case 0x0c0667b8u: goto P_0c0667b8;
case 0x0c0667bau: goto P_0c0667ba;
case 0x0c0667bcu: goto P_0c0667bc;
case 0x0c0667beu: goto P_0c0667be;
case 0x0c0667c0u: goto P_0c0667c0;
case 0x0c0667c2u: goto P_0c0667c2;
case 0x0c0667c4u: goto P_0c0667c4;
case 0x0c0667c6u: goto P_0c0667c6;
case 0x0c0667c8u: goto P_0c0667c8;
case 0x0c0667cau: goto P_0c0667ca;
case 0x0c0667ccu: goto P_0c0667cc;
case 0x0c0667ceu: goto P_0c0667ce;
case 0x0c0667d0u: goto P_0c0667d0;
case 0x0c0667d2u: goto P_0c0667d2;
case 0x0c0667d4u: goto P_0c0667d4;
case 0x0c0667d6u: goto P_0c0667d6;
case 0x0c0667d8u: goto P_0c0667d8;
case 0x0c0667dau: goto P_0c0667da;
case 0x0c0667dcu: goto P_0c0667dc;
case 0x0c0667deu: goto P_0c0667de;
case 0x0c0667e0u: goto P_0c0667e0;
case 0x0c0667e2u: goto P_0c0667e2;
case 0x0c0667e4u: goto P_0c0667e4;
case 0x0c0667f4u: goto P_0c0667f4;
case 0x0c0667f6u: goto P_0c0667f6;
case 0x0c0667f8u: goto P_0c0667f8;
case 0x0c0667fau: goto P_0c0667fa;
case 0x0c0667fcu: goto P_0c0667fc;
case 0x0c0667feu: goto P_0c0667fe;
case 0x0c066800u: goto P_0c066800;
case 0x0c066802u: goto P_0c066802;
case 0x0c066804u: goto P_0c066804;
case 0x0c066806u: goto P_0c066806;
case 0x0c066808u: goto P_0c066808;
case 0x0c06680au: goto P_0c06680a;
case 0x0c06680cu: goto P_0c06680c;
case 0x0c06680eu: goto P_0c06680e;
case 0x0c066810u: goto P_0c066810;
case 0x0c066812u: goto P_0c066812;
case 0x0c066814u: goto P_0c066814;
case 0x0c066816u: goto P_0c066816;
case 0x0c066818u: goto P_0c066818;
case 0x0c06681au: goto P_0c06681a;
case 0x0c06681cu: goto P_0c06681c;
case 0x0c06681eu: goto P_0c06681e;
case 0x0c066820u: goto P_0c066820;
case 0x0c066822u: goto P_0c066822;
case 0x0c066824u: goto P_0c066824;
case 0x0c066826u: goto P_0c066826;
case 0x0c066828u: goto P_0c066828;
case 0x0c06682au: goto P_0c06682a;
case 0x0c06682cu: goto P_0c06682c;
case 0x0c06682eu: goto P_0c06682e;
case 0x0c066830u: goto P_0c066830;
case 0x0c066832u: goto P_0c066832;
case 0x0c066834u: goto P_0c066834;
case 0x0c066836u: goto P_0c066836;
case 0x0c066838u: goto P_0c066838;
case 0x0c06683au: goto P_0c06683a;
case 0x0c06683cu: goto P_0c06683c;
case 0x0c06683eu: goto P_0c06683e;
case 0x0c066840u: goto P_0c066840;
case 0x0c066842u: goto P_0c066842;
case 0x0c066844u: goto P_0c066844;
case 0x0c066846u: goto P_0c066846;
case 0x0c066848u: goto P_0c066848;
case 0x0c06684au: goto P_0c06684a;
case 0x0c06684cu: goto P_0c06684c;
case 0x0c06684eu: goto P_0c06684e;
case 0x0c066850u: goto P_0c066850;
case 0x0c066852u: goto P_0c066852;
case 0x0c066854u: goto P_0c066854;
case 0x0c066856u: goto P_0c066856;
case 0x0c066858u: goto P_0c066858;
case 0x0c06685au: goto P_0c06685a;
case 0x0c06685cu: goto P_0c06685c;
case 0x0c06685eu: goto P_0c06685e;
case 0x0c066860u: goto P_0c066860;
case 0x0c066862u: goto P_0c066862;
case 0x0c066864u: goto P_0c066864;
case 0x0c066866u: goto P_0c066866;
case 0x0c066868u: goto P_0c066868;
case 0x0c06686au: goto P_0c06686a;
case 0x0c06686cu: goto P_0c06686c;
case 0x0c06686eu: goto P_0c06686e;
case 0x0c066870u: goto P_0c066870;
case 0x0c066872u: goto P_0c066872;
case 0x0c066874u: goto P_0c066874;
case 0x0c066876u: goto P_0c066876;
case 0x0c066878u: goto P_0c066878;
case 0x0c06687au: goto P_0c06687a;
case 0x0c06687cu: goto P_0c06687c;
case 0x0c06687eu: goto P_0c06687e;
case 0x0c066880u: goto P_0c066880;
case 0x0c066882u: goto P_0c066882;
case 0x0c066884u: goto P_0c066884;
case 0x0c066886u: goto P_0c066886;
case 0x0c066888u: goto P_0c066888;
case 0x0c06688au: goto P_0c06688a;
case 0x0c06688cu: goto P_0c06688c;
case 0x0c06688eu: goto P_0c06688e;
case 0x0c066890u: goto P_0c066890;
case 0x0c066892u: goto P_0c066892;
case 0x0c066894u: goto P_0c066894;
case 0x0c066896u: goto P_0c066896;
case 0x0c066898u: goto P_0c066898;
case 0x0c06689au: goto P_0c06689a;
case 0x0c06689cu: goto P_0c06689c;
case 0x0c06689eu: goto P_0c06689e;
case 0x0c0668a0u: goto P_0c0668a0;
case 0x0c0668a2u: goto P_0c0668a2;
case 0x0c0668a4u: goto P_0c0668a4;
case 0x0c0668a6u: goto P_0c0668a6;
case 0x0c0668a8u: goto P_0c0668a8;
case 0x0c0668aau: goto P_0c0668aa;
case 0x0c0668acu: goto P_0c0668ac;
case 0x0c0668aeu: goto P_0c0668ae;
case 0x0c0668b0u: goto P_0c0668b0;
case 0x0c0668b2u: goto P_0c0668b2;
case 0x0c0668b4u: goto P_0c0668b4;
case 0x0c0668b6u: goto P_0c0668b6;
case 0x0c0668b8u: goto P_0c0668b8;
case 0x0c0668bau: goto P_0c0668ba;
case 0x0c0668bcu: goto P_0c0668bc;
case 0x0c0668beu: goto P_0c0668be;
case 0x0c0668c0u: goto P_0c0668c0;
case 0x0c0668c2u: goto P_0c0668c2;
case 0x0c0668c4u: goto P_0c0668c4;
case 0x0c0668c6u: goto P_0c0668c6;
case 0x0c0668c8u: goto P_0c0668c8;
case 0x0c0668cau: goto P_0c0668ca;
case 0x0c0668ccu: goto P_0c0668cc;
case 0x0c0668ceu: goto P_0c0668ce;
case 0x0c0668d0u: goto P_0c0668d0;
case 0x0c0668d2u: goto P_0c0668d2;
case 0x0c0668d4u: goto P_0c0668d4;
case 0x0c0668d6u: goto P_0c0668d6;
case 0x0c0668d8u: goto P_0c0668d8;
case 0x0c0668dau: goto P_0c0668da;
case 0x0c0668dcu: goto P_0c0668dc;
case 0x0c0668deu: goto P_0c0668de;
case 0x0c0668e0u: goto P_0c0668e0;
case 0x0c0668e2u: goto P_0c0668e2;
case 0x0c0668e4u: goto P_0c0668e4;
case 0x0c0668e6u: goto P_0c0668e6;
case 0x0c0668e8u: goto P_0c0668e8;
case 0x0c0668eau: goto P_0c0668ea;
case 0x0c0668ecu: goto P_0c0668ec;
case 0x0c0668eeu: goto P_0c0668ee;
case 0x0c0668f0u: goto P_0c0668f0;
case 0x0c0668f2u: goto P_0c0668f2;
case 0x0c0668f4u: goto P_0c0668f4;
case 0x0c0668f6u: goto P_0c0668f6;
case 0x0c0668f8u: goto P_0c0668f8;
case 0x0c0668fau: goto P_0c0668fa;
case 0x0c0668fcu: goto P_0c0668fc;
case 0x0c0668feu: goto P_0c0668fe;
case 0x0c066900u: goto P_0c066900;
case 0x0c066902u: goto P_0c066902;
case 0x0c066904u: goto P_0c066904;
case 0x0c066906u: goto P_0c066906;
case 0x0c066908u: goto P_0c066908;
case 0x0c06690au: goto P_0c06690a;
case 0x0c06690cu: goto P_0c06690c;
case 0x0c06690eu: goto P_0c06690e;
case 0x0c066910u: goto P_0c066910;
case 0x0c066912u: goto P_0c066912;
case 0x0c066914u: goto P_0c066914;
case 0x0c066916u: goto P_0c066916;
case 0x0c066918u: goto P_0c066918;
case 0x0c06691au: goto P_0c06691a;
case 0x0c06691cu: goto P_0c06691c;
case 0x0c06691eu: goto P_0c06691e;
case 0x0c066920u: goto P_0c066920;
case 0x0c066922u: goto P_0c066922;
case 0x0c066924u: goto P_0c066924;
case 0x0c066926u: goto P_0c066926;
case 0x0c066928u: goto P_0c066928;
case 0x0c06692au: goto P_0c06692a;
case 0x0c06692cu: goto P_0c06692c;
case 0x0c06692eu: goto P_0c06692e;
case 0x0c066930u: goto P_0c066930;
case 0x0c066932u: goto P_0c066932;
case 0x0c066934u: goto P_0c066934;
case 0x0c066936u: goto P_0c066936;
case 0x0c066938u: goto P_0c066938;
case 0x0c06693au: goto P_0c06693a;
case 0x0c06693cu: goto P_0c06693c;
case 0x0c06693eu: goto P_0c06693e;
case 0x0c066940u: goto P_0c066940;
case 0x0c066942u: goto P_0c066942;
case 0x0c066944u: goto P_0c066944;
case 0x0c066978u: goto P_0c066978;
case 0x0c06697au: goto P_0c06697a;
case 0x0c06697cu: goto P_0c06697c;
case 0x0c06697eu: goto P_0c06697e;
case 0x0c066980u: goto P_0c066980;
case 0x0c066982u: goto P_0c066982;
case 0x0c066984u: goto P_0c066984;
case 0x0c066986u: goto P_0c066986;
case 0x0c066988u: goto P_0c066988;
case 0x0c06698au: goto P_0c06698a;
case 0x0c06698cu: goto P_0c06698c;
case 0x0c06698eu: goto P_0c06698e;
case 0x0c066990u: goto P_0c066990;
case 0x0c066992u: goto P_0c066992;
case 0x0c066994u: goto P_0c066994;
case 0x0c066996u: goto P_0c066996;
case 0x0c066998u: goto P_0c066998;
case 0x0c06699au: goto P_0c06699a;
case 0x0c06699cu: goto P_0c06699c;
case 0x0c06699eu: goto P_0c06699e;
case 0x0c0669a0u: goto P_0c0669a0;
case 0x0c0669a2u: goto P_0c0669a2;
case 0x0c0669a4u: goto P_0c0669a4;
case 0x0c0669a6u: goto P_0c0669a6;
case 0x0c0669a8u: goto P_0c0669a8;
case 0x0c0669aau: goto P_0c0669aa;
case 0x0c0669acu: goto P_0c0669ac;
case 0x0c0669aeu: goto P_0c0669ae;
case 0x0c0669b0u: goto P_0c0669b0;
case 0x0c0669b2u: goto P_0c0669b2;
case 0x0c0669b4u: goto P_0c0669b4;
case 0x0c0669b6u: goto P_0c0669b6;
case 0x0c0669b8u: goto P_0c0669b8;
case 0x0c0669bau: goto P_0c0669ba;
case 0x0c0669bcu: goto P_0c0669bc;
case 0x0c0669beu: goto P_0c0669be;
case 0x0c0669c0u: goto P_0c0669c0;
case 0x0c0669c2u: goto P_0c0669c2;
case 0x0c0669c4u: goto P_0c0669c4;
case 0x0c0669c6u: goto P_0c0669c6;
case 0x0c0669c8u: goto P_0c0669c8;
case 0x0c0669cau: goto P_0c0669ca;
case 0x0c0669ccu: goto P_0c0669cc;
case 0x0c0669ceu: goto P_0c0669ce;
case 0x0c0669d0u: goto P_0c0669d0;
case 0x0c0669d2u: goto P_0c0669d2;
case 0x0c0669d4u: goto P_0c0669d4;
case 0x0c0669d6u: goto P_0c0669d6;
case 0x0c0669d8u: goto P_0c0669d8;
case 0x0c0669dau: goto P_0c0669da;
case 0x0c0669dcu: goto P_0c0669dc;
case 0x0c0669deu: goto P_0c0669de;
case 0x0c0669e0u: goto P_0c0669e0;
case 0x0c0669e2u: goto P_0c0669e2;
case 0x0c0669e4u: goto P_0c0669e4;
case 0x0c0669e6u: goto P_0c0669e6;
case 0x0c0669e8u: goto P_0c0669e8;
case 0x0c0669eau: goto P_0c0669ea;
case 0x0c0669ecu: goto P_0c0669ec;
case 0x0c0669eeu: goto P_0c0669ee;
case 0x0c0669f0u: goto P_0c0669f0;
case 0x0c0669f2u: goto P_0c0669f2;
case 0x0c0669f4u: goto P_0c0669f4;
case 0x0c0669f6u: goto P_0c0669f6;
case 0x0c0669f8u: goto P_0c0669f8;
case 0x0c0669fau: goto P_0c0669fa;
case 0x0c0669fcu: goto P_0c0669fc;
case 0x0c0669feu: goto P_0c0669fe;
case 0x0c066a00u: goto P_0c066a00;
case 0x0c066a02u: goto P_0c066a02;
case 0x0c066a04u: goto P_0c066a04;
case 0x0c066a06u: goto P_0c066a06;
case 0x0c066a08u: goto P_0c066a08;
case 0x0c066a0au: goto P_0c066a0a;
case 0x0c066a0cu: goto P_0c066a0c;
case 0x0c066a0eu: goto P_0c066a0e;
case 0x0c066a10u: goto P_0c066a10;
case 0x0c066a12u: goto P_0c066a12;
case 0x0c066a14u: goto P_0c066a14;
case 0x0c066a16u: goto P_0c066a16;
case 0x0c066a18u: goto P_0c066a18;
case 0x0c066a1au: goto P_0c066a1a;
case 0x0c066a1cu: goto P_0c066a1c;
case 0x0c066a1eu: goto P_0c066a1e;
case 0x0c066a20u: goto P_0c066a20;
case 0x0c066a22u: goto P_0c066a22;
case 0x0c066a24u: goto P_0c066a24;
case 0x0c066a26u: goto P_0c066a26;
case 0x0c066a28u: goto P_0c066a28;
case 0x0c066a2au: goto P_0c066a2a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0663d8: /* original d642, guest PC 0x0c0663d8 */
if(!s->budget--) { s->failed_pc=0x0c0663d8u; return 0; }
r[6]=read(ram,0x0c0664e4u,4);
goto P_0c0663da;
P_0c0663da: /* original 6343, guest PC 0x0c0663da */
if(!s->budget--) { s->failed_pc=0x0c0663dau; return 0; }
r[3]=r[4];
goto P_0c0663dc;
P_0c0663dc: /* original d242, guest PC 0x0c0663dc */
if(!s->budget--) { s->failed_pc=0x0c0663dcu; return 0; }
r[2]=read(ram,0x0c0664e8u,4);
goto P_0c0663de;
P_0c0663de: /* original f48d, guest PC 0x0c0663de */
if(!s->budget--) { s->failed_pc=0x0c0663deu; return 0; }
fr[4]=0;
goto P_0c0663e0;
P_0c0663e0: /* original d142, guest PC 0x0c0663e0 */
if(!s->budget--) { s->failed_pc=0x0c0663e0u; return 0; }
r[1]=read(ram,0x0c0664ecu,4);
goto P_0c0663e2;
P_0c0663e2: /* original e00c, guest PC 0x0c0663e2 */
if(!s->budget--) { s->failed_pc=0x0c0663e2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0663e4;
P_0c0663e4: /* original 264b, guest PC 0x0c0663e4 */
if(!s->budget--) { s->failed_pc=0x0c0663e4u; return 0; }
r[6]|=r[4];
goto P_0c0663e6;
P_0c0663e6: /* original 3358, guest PC 0x0c0663e6 */
if(!s->budget--) { s->failed_pc=0x0c0663e6u; return 0; }
r[3]-=r[5];
goto P_0c0663e8;
P_0c0663e8: /* original 4309, guest PC 0x0c0663e8 */
if(!s->budget--) { s->failed_pc=0x0c0663e8u; return 0; }
r[3]>>=2;
goto P_0c0663ea;
P_0c0663ea: /* original 7302, guest PC 0x0c0663ea */
if(!s->budget--) { s->failed_pc=0x0c0663eau; return 0; }
r[3]+=0x00000002u;
goto P_0c0663ec;
P_0c0663ec: /* original 232b, guest PC 0x0c0663ec */
if(!s->budget--) { s->failed_pc=0x0c0663ecu; return 0; }
r[3]|=r[2];
goto P_0c0663ee;
P_0c0663ee: /* original 2632, guest PC 0x0c0663ee */
if(!s->budget--) { s->failed_pc=0x0c0663eeu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0663f0;
P_0c0663f0: /* original 1611, guest PC 0x0c0663f0 */
if(!s->budget--) { s->failed_pc=0x0c0663f0u; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c0663f2;
P_0c0663f2: /* original 7608, guest PC 0x0c0663f2 */
if(!s->budget--) { s->failed_pc=0x0c0663f2u; return 0; }
r[6]+=0x00000008u;
goto P_0c0663f4;
P_0c0663f4: /* original d33e, guest PC 0x0c0663f4 */
if(!s->budget--) { s->failed_pc=0x0c0663f4u; return 0; }
r[3]=read(ram,0x0c0664f0u,4);
goto P_0c0663f6;
P_0c0663f6: /* original 2632, guest PC 0x0c0663f6 */
if(!s->budget--) { s->failed_pc=0x0c0663f6u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0663f8;
P_0c0663f8: /* original d13e, guest PC 0x0c0663f8 */
if(!s->budget--) { s->failed_pc=0x0c0663f8u; return 0; }
r[1]=read(ram,0x0c0664f4u,4);
goto P_0c0663fa;
P_0c0663fa: /* original e300, guest PC 0x0c0663fa */
if(!s->budget--) { s->failed_pc=0x0c0663fau; return 0; }
r[3]=0x00000000u;
goto P_0c0663fc;
P_0c0663fc: /* original 1611, guest PC 0x0c0663fc */
if(!s->budget--) { s->failed_pc=0x0c0663fcu; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c0663fe;
P_0c0663fe: /* original 1632, guest PC 0x0c0663fe */
if(!s->budget--) { s->failed_pc=0x0c0663feu; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c066400;
P_0c066400: /* original f647, guest PC 0x0c066400 */
if(!s->budget--) { s->failed_pc=0x0c066400u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066402;
P_0c066402: /* original e010, guest PC 0x0c066402 */
if(!s->budget--) { s->failed_pc=0x0c066402u; return 0; }
r[0]=0x00000010u;
goto P_0c066404;
P_0c066404: /* original d33d, guest PC 0x0c066404 */
if(!s->budget--) { s->failed_pc=0x0c066404u; return 0; }
r[3]=read(ram,0x0c0664fcu,4);
goto P_0c066406;
P_0c066406: /* original f647, guest PC 0x0c066406 */
if(!s->budget--) { s->failed_pc=0x0c066406u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066408;
P_0c066408: /* original c73b, guest PC 0x0c066408 */
if(!s->budget--) { s->failed_pc=0x0c066408u; return 0; }
r[0]=code_base|0x000664f8u;
goto P_0c06640a;
P_0c06640a: /* original f508, guest PC 0x0c06640a */
if(!s->budget--) { s->failed_pc=0x0c06640au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06640c;
P_0c06640c: /* original e014, guest PC 0x0c06640c */
if(!s->budget--) { s->failed_pc=0x0c06640cu; return 0; }
r[0]=0x00000014u;
goto P_0c06640e;
P_0c06640e: /* original f657, guest PC 0x0c06640e */
if(!s->budget--) { s->failed_pc=0x0c06640eu; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066410;
P_0c066410: /* original 1636, guest PC 0x0c066410 */
if(!s->budget--) { s->failed_pc=0x0c066410u; return 0; }
write(ram,r[6]+24,r[3],4);
goto P_0c066412;
P_0c066412: /* original e01c, guest PC 0x0c066412 */
if(!s->budget--) { s->failed_pc=0x0c066412u; return 0; }
r[0]=0x0000001cu;
goto P_0c066414;
P_0c066414: /* original f647, guest PC 0x0c066414 */
if(!s->budget--) { s->failed_pc=0x0c066414u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066416;
P_0c066416: /* original c73a, guest PC 0x0c066416 */
if(!s->budget--) { s->failed_pc=0x0c066416u; return 0; }
r[0]=code_base|0x00066500u;
goto P_0c066418;
P_0c066418: /* original d33a, guest PC 0x0c066418 */
if(!s->budget--) { s->failed_pc=0x0c066418u; return 0; }
r[3]=read(ram,0x0c066504u,4);
goto P_0c06641a;
P_0c06641a: /* original f308, guest PC 0x0c06641a */
if(!s->budget--) { s->failed_pc=0x0c06641au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06641c;
P_0c06641c: /* original e020, guest PC 0x0c06641c */
if(!s->budget--) { s->failed_pc=0x0c06641cu; return 0; }
r[0]=0x00000020u;
goto P_0c06641e;
P_0c06641e: /* original f637, guest PC 0x0c06641e */
if(!s->budget--) { s->failed_pc=0x0c06641eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c066420;
P_0c066420: /* original e024, guest PC 0x0c066420 */
if(!s->budget--) { s->failed_pc=0x0c066420u; return 0; }
r[0]=0x00000024u;
goto P_0c066422;
P_0c066422: /* original f657, guest PC 0x0c066422 */
if(!s->budget--) { s->failed_pc=0x0c066422u; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066424;
P_0c066424: /* original 163a, guest PC 0x0c066424 */
if(!s->budget--) { s->failed_pc=0x0c066424u; return 0; }
write(ram,r[6]+40,r[3],4);
goto P_0c066426;
P_0c066426: /* original c738, guest PC 0x0c066426 */
if(!s->budget--) { s->failed_pc=0x0c066426u; return 0; }
r[0]=code_base|0x00066508u;
goto P_0c066428;
P_0c066428: /* original d338, guest PC 0x0c066428 */
if(!s->budget--) { s->failed_pc=0x0c066428u; return 0; }
r[3]=read(ram,0x0c06650cu,4);
goto P_0c06642a;
P_0c06642a: /* original f308, guest PC 0x0c06642a */
if(!s->budget--) { s->failed_pc=0x0c06642au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06642c;
P_0c06642c: /* original e02c, guest PC 0x0c06642c */
if(!s->budget--) { s->failed_pc=0x0c06642cu; return 0; }
r[0]=0x0000002cu;
goto P_0c06642e;
P_0c06642e: /* original f637, guest PC 0x0c06642e */
if(!s->budget--) { s->failed_pc=0x0c06642eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c066430;
P_0c066430: /* original e030, guest PC 0x0c066430 */
if(!s->budget--) { s->failed_pc=0x0c066430u; return 0; }
r[0]=0x00000030u;
goto P_0c066432;
P_0c066432: /* original f647, guest PC 0x0c066432 */
if(!s->budget--) { s->failed_pc=0x0c066432u; return 0; }
vf3_matrix_store(s,ram,4,r[6]+r[0]);
goto P_0c066434;
P_0c066434: /* original e034, guest PC 0x0c066434 */
if(!s->budget--) { s->failed_pc=0x0c066434u; return 0; }
r[0]=0x00000034u;
goto P_0c066436;
P_0c066436: /* original f657, guest PC 0x0c066436 */
if(!s->budget--) { s->failed_pc=0x0c066436u; return 0; }
vf3_matrix_store(s,ram,5,r[6]+r[0]);
goto P_0c066438;
P_0c066438: /* original 163e, guest PC 0x0c066438 */
if(!s->budget--) { s->failed_pc=0x0c066438u; return 0; }
write(ram,r[6]+56,r[3],4);
goto P_0c06643a;
P_0c06643a: /* original 000b, guest PC 0x0c06643a */
if(!s->budget--) { s->failed_pc=0x0c06643au; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c06643c: /* original 6043, guest PC 0x0c06643c */
if(!s->budget--) { s->failed_pc=0x0c06643cu; return 0; }
r[0]=r[4];
goto P_0c06643e;
P_0c06643e: /* original e300, guest PC 0x0c06643e */
if(!s->budget--) { s->failed_pc=0x0c06643eu; return 0; }
r[3]=0x00000000u;
goto P_0c066440;
P_0c066440: /* original d233, guest PC 0x0c066440 */
if(!s->budget--) { s->failed_pc=0x0c066440u; return 0; }
r[2]=read(ram,0x0c066510u,4);
goto P_0c066442;
P_0c066442: /* original 2fe6, guest PC 0x0c066442 */
if(!s->budget--) { s->failed_pc=0x0c066442u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066444;
P_0c066444: /* original 2fd6, guest PC 0x0c066444 */
if(!s->budget--) { s->failed_pc=0x0c066444u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066446;
P_0c066446: /* original 2fc6, guest PC 0x0c066446 */
if(!s->budget--) { s->failed_pc=0x0c066446u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066448;
P_0c066448: /* original 2fb6, guest PC 0x0c066448 */
if(!s->budget--) { s->failed_pc=0x0c066448u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06644a;
P_0c06644a: /* original 2fa6, guest PC 0x0c06644a */
if(!s->budget--) { s->failed_pc=0x0c06644au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06644c;
P_0c06644c: /* original 2f96, guest PC 0x0c06644c */
if(!s->budget--) { s->failed_pc=0x0c06644cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06644e;
P_0c06644e: /* original 2f86, guest PC 0x0c06644e */
if(!s->budget--) { s->failed_pc=0x0c06644eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066450;
P_0c066450: /* original 4f22, guest PC 0x0c066450 */
if(!s->budget--) { s->failed_pc=0x0c066450u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066452;
P_0c066452: /* original 9045, guest PC 0x0c066452 */
if(!s->budget--) { s->failed_pc=0x0c066452u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0664e0u,2);
goto P_0c066454;
P_0c066454: /* original 3f0c, guest PC 0x0c066454 */
if(!s->budget--) { s->failed_pc=0x0c066454u; return 0; }
r[15]+=r[0];
goto P_0c066456;
P_0c066456: /* original e058, guest PC 0x0c066456 */
if(!s->budget--) { s->failed_pc=0x0c066456u; return 0; }
r[0]=0x00000058u;
goto P_0c066458;
P_0c066458: /* original 2f42, guest PC 0x0c066458 */
if(!s->budget--) { s->failed_pc=0x0c066458u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06645a;
P_0c06645a: /* original 1f51, guest PC 0x0c06645a */
if(!s->budget--) { s->failed_pc=0x0c06645au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06645c;
P_0c06645c: /* original 1f63, guest PC 0x0c06645c */
if(!s->budget--) { s->failed_pc=0x0c06645cu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c06645e;
P_0c06645e: /* original 0f36, guest PC 0x0c06645e */
if(!s->budget--) { s->failed_pc=0x0c06645eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066460;
P_0c066460: /* original 6022, guest PC 0x0c066460 */
if(!s->budget--) { s->failed_pc=0x0c066460u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c066462;
P_0c066462: /* original 8801, guest PC 0x0c066462 */
if(!s->budget--) { s->failed_pc=0x0c066462u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c066464;
P_0c066464: /* original d22b, guest PC 0x0c066464 */
if(!s->budget--) { s->failed_pc=0x0c066464u; return 0; }
r[2]=read(ram,0x0c066514u,4);
goto P_0c066466;
P_0c066466: /* original 0e29, guest PC 0x0c066466 */
if(!s->budget--) { s->failed_pc=0x0c066466u; return 0; }
r[14]=r[17]&1u;
goto P_0c066468;
P_0c066468: /* original 6322, guest PC 0x0c066468 */
if(!s->budget--) { s->failed_pc=0x0c066468u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06646a;
P_0c06646a: /* original 2338, guest PC 0x0c06646a */
if(!s->budget--) { s->failed_pc=0x0c06646au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06646c;
P_0c06646c: /* original 8b04, guest PC 0x0c06646c */
if(!s->budget--) { s->failed_pc=0x0c06646cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066478; }
goto P_0c06646e;
P_0c06646e: /* original 9038, guest PC 0x0c06646e */
if(!s->budget--) { s->failed_pc=0x0c06646eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0664e2u,2);
goto P_0c066470;
P_0c066470: /* original 55f1, guest PC 0x0c066470 */
if(!s->budget--) { s->failed_pc=0x0c066470u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c066472;
P_0c066472: /* original 06fe, guest PC 0x0c066472 */
if(!s->budget--) { s->failed_pc=0x0c066472u; return 0; }
r[6]=read(ram,r[15]+r[0],4);
goto P_0c066474;
P_0c066474: /* original bf30, guest PC 0x0c066474 */
if(!s->budget--) { s->failed_pc=0x0c066474u; return 0; }
target=code_base|0x0c0662d8u; r[16]=code_base|0x0c066478u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066478u) { target=s->pc; goto dispatch; }
goto P_0c066478;
P_0c066476: /* original 64f2, guest PC 0x0c066476 */
if(!s->budget--) { s->failed_pc=0x0c066476u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c066478;
P_0c066478: /* original 53f1, guest PC 0x0c066478 */
if(!s->budget--) { s->failed_pc=0x0c066478u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06647a;
P_0c06647a: /* original 62f2, guest PC 0x0c06647a */
if(!s->budget--) { s->failed_pc=0x0c06647au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06647c;
P_0c06647c: /* original 9031, guest PC 0x0c06647c */
if(!s->budget--) { s->failed_pc=0x0c06647cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0664e2u,2);
goto P_0c06647e;
P_0c06647e: /* original 0237, guest PC 0x0c06647e */
if(!s->budget--) { s->failed_pc=0x0c06647eu; return 0; }
r[19]=r[2]*r[3];
goto P_0c066480;
P_0c066480: /* original 031a, guest PC 0x0c066480 */
if(!s->budget--) { s->failed_pc=0x0c066480u; return 0; }
r[3]=r[19];
goto P_0c066482;
P_0c066482: /* original 6d33, guest PC 0x0c066482 */
if(!s->budget--) { s->failed_pc=0x0c066482u; return 0; }
r[13]=r[3];
goto P_0c066484;
P_0c066484: /* original 1f32, guest PC 0x0c066484 */
if(!s->budget--) { s->failed_pc=0x0c066484u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c066486;
P_0c066486: /* original 6133, guest PC 0x0c066486 */
if(!s->budget--) { s->failed_pc=0x0c066486u; return 0; }
r[1]=r[3];
goto P_0c066488;
P_0c066488: /* original 0cfe, guest PC 0x0c066488 */
if(!s->budget--) { s->failed_pc=0x0c066488u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c06648a;
P_0c06648a: /* original 4d00, guest PC 0x0c06648a */
if(!s->budget--) { s->failed_pc=0x0c06648au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c06648c;
P_0c06648c: /* original 53f3, guest PC 0x0c06648c */
if(!s->budget--) { s->failed_pc=0x0c06648cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06648e;
P_0c06648e: /* original 4c08, guest PC 0x0c06648e */
if(!s->budget--) { s->failed_pc=0x0c06648eu; return 0; }
r[12]<<=2;
goto P_0c066490;
P_0c066490: /* original d021, guest PC 0x0c066490 */
if(!s->budget--) { s->failed_pc=0x0c066490u; return 0; }
r[0]=read(ram,0x0c066518u,4);
goto P_0c066492;
P_0c066492: /* original 3d1c, guest PC 0x0c066492 */
if(!s->budget--) { s->failed_pc=0x0c066492u; return 0; }
r[13]+=r[1];
goto P_0c066494;
P_0c066494: /* original 4d08, guest PC 0x0c066494 */
if(!s->budget--) { s->failed_pc=0x0c066494u; return 0; }
r[13]<<=2;
goto P_0c066496;
P_0c066496: /* original 4d00, guest PC 0x0c066496 */
if(!s->budget--) { s->failed_pc=0x0c066496u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c066498;
P_0c066498: /* original 03d7, guest PC 0x0c066498 */
if(!s->budget--) { s->failed_pc=0x0c066498u; return 0; }
r[19]=r[3]*r[13];
goto P_0c06649a;
P_0c06649a: /* original 4c08, guest PC 0x0c06649a */
if(!s->budget--) { s->failed_pc=0x0c06649au; return 0; }
r[12]<<=2;
goto P_0c06649c;
P_0c06649c: /* original 4c00, guest PC 0x0c06649c */
if(!s->budget--) { s->failed_pc=0x0c06649cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c06649e;
P_0c06649e: /* original 031a, guest PC 0x0c06649e */
if(!s->budget--) { s->failed_pc=0x0c06649eu; return 0; }
r[3]=r[19];
goto P_0c0664a0;
P_0c0664a0: /* original 02ce, guest PC 0x0c0664a0 */
if(!s->budget--) { s->failed_pc=0x0c0664a0u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0664a2;
P_0c0664a2: /* original 332c, guest PC 0x0c0664a2 */
if(!s->budget--) { s->failed_pc=0x0c0664a2u; return 0; }
r[3]+=r[2];
goto P_0c0664a4;
P_0c0664a4: /* original 1f33, guest PC 0x0c0664a4 */
if(!s->budget--) { s->failed_pc=0x0c0664a4u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0664a6;
P_0c0664a6: /* original d21d, guest PC 0x0c0664a6 */
if(!s->budget--) { s->failed_pc=0x0c0664a6u; return 0; }
r[2]=read(ram,0x0c06651cu,4);
goto P_0c0664a8;
P_0c0664a8: /* original 6022, guest PC 0x0c0664a8 */
if(!s->budget--) { s->failed_pc=0x0c0664a8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0664aa;
P_0c0664aa: /* original c820, guest PC 0x0c0664aa */
if(!s->budget--) { s->failed_pc=0x0c0664aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0664ac;
P_0c0664ac: /* original 8943, guest PC 0x0c0664ac */
if(!s->budget--) { s->failed_pc=0x0c0664acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066536; }
goto P_0c0664ae;
P_0c0664ae: /* original d01c, guest PC 0x0c0664ae */
if(!s->budget--) { s->failed_pc=0x0c0664aeu; return 0; }
r[0]=read(ram,0x0c066520u,4);
goto P_0c0664b0;
P_0c0664b0: /* original 6102, guest PC 0x0c0664b0 */
if(!s->budget--) { s->failed_pc=0x0c0664b0u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0664b2;
P_0c0664b2: /* original 2118, guest PC 0x0c0664b2 */
if(!s->budget--) { s->failed_pc=0x0c0664b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0664b4;
P_0c0664b4: /* original 893f, guest PC 0x0c0664b4 */
if(!s->budget--) { s->failed_pc=0x0c0664b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066536; }
goto P_0c0664b6;
P_0c0664b6: /* original d01b, guest PC 0x0c0664b6 */
if(!s->budget--) { s->failed_pc=0x0c0664b6u; return 0; }
r[0]=read(ram,0x0c066524u,4);
goto P_0c0664b8;
P_0c0664b8: /* original 05ce, guest PC 0x0c0664b8 */
if(!s->budget--) { s->failed_pc=0x0c0664b8u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0664ba;
P_0c0664ba: /* original 6403, guest PC 0x0c0664ba */
if(!s->budget--) { s->failed_pc=0x0c0664bau; return 0; }
r[4]=r[0];
goto P_0c0664bc;
P_0c0664bc: /* original 34cc, guest PC 0x0c0664bc */
if(!s->budget--) { s->failed_pc=0x0c0664bcu; return 0; }
r[4]+=r[12];
goto P_0c0664be;
P_0c0664be: /* original 4d08, guest PC 0x0c0664be */
if(!s->budget--) { s->failed_pc=0x0c0664beu; return 0; }
r[13]<<=2;
goto P_0c0664c0;
P_0c0664c0: /* original 5441, guest PC 0x0c0664c0 */
if(!s->budget--) { s->failed_pc=0x0c0664c0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0664c2;
P_0c0664c2: /* original bf89, guest PC 0x0c0664c2 */
if(!s->budget--) { s->failed_pc=0x0c0664c2u; return 0; }
target=code_base|0x0c0663d8u; r[16]=code_base|0x0c0664c6u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0664c6u) { target=s->pc; goto dispatch; }
goto P_0c0664c6;
P_0c0664c4: /* original 34dc, guest PC 0x0c0664c4 */
if(!s->budget--) { s->failed_pc=0x0c0664c4u; return 0; }
r[4]+=r[13];
goto P_0c0664c6;
P_0c0664c6: /* original 1f04, guest PC 0x0c0664c6 */
if(!s->budget--) { s->failed_pc=0x0c0664c6u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0664c8;
P_0c0664c8: /* original d217, guest PC 0x0c0664c8 */
if(!s->budget--) { s->failed_pc=0x0c0664c8u; return 0; }
r[2]=read(ram,0x0c066528u,4);
goto P_0c0664ca;
P_0c0664ca: /* original 6322, guest PC 0x0c0664ca */
if(!s->budget--) { s->failed_pc=0x0c0664cau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0664cc;
P_0c0664cc: /* original 2338, guest PC 0x0c0664cc */
if(!s->budget--) { s->failed_pc=0x0c0664ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0664ce;
P_0c0664ce: /* original 8b2f, guest PC 0x0c0664ce */
if(!s->budget--) { s->failed_pc=0x0c0664ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066530; }
goto P_0c0664d0;
P_0c0664d0: /* original d116, guest PC 0x0c0664d0 */
if(!s->budget--) { s->failed_pc=0x0c0664d0u; return 0; }
r[1]=read(ram,0x0c06652cu,4);
goto P_0c0664d2;
P_0c0664d2: /* original 6312, guest PC 0x0c0664d2 */
if(!s->budget--) { s->failed_pc=0x0c0664d2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0664d4;
P_0c0664d4: /* original 2338, guest PC 0x0c0664d4 */
if(!s->budget--) { s->failed_pc=0x0c0664d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0664d6;
P_0c0664d6: /* original 892b, guest PC 0x0c0664d6 */
if(!s->budget--) { s->failed_pc=0x0c0664d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066530; }
goto P_0c0664d8;
P_0c0664d8: /* original 2ee8, guest PC 0x0c0664d8 */
if(!s->budget--) { s->failed_pc=0x0c0664d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0664da;
P_0c0664da: /* original 8929, guest PC 0x0c0664da */
if(!s->budget--) { s->failed_pc=0x0c0664dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066530; }
goto P_0c0664dc;
P_0c0664dc: /* original a029, guest PC 0x0c0664dc */
if(!s->budget--) { s->failed_pc=0x0c0664dcu; return 0; }
r[2]=0x00000001u;
goto P_0c066532;
P_0c0664de: /* original e201, guest PC 0x0c0664de */
if(!s->budget--) { s->failed_pc=0x0c0664deu; return 0; }
r[2]=0x00000001u;
if(!vf3_matrix_family(0x0c0664e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0664e0u; return 0; } return 1;
P_0c066530: /* original e200, guest PC 0x0c066530 */
if(!s->budget--) { s->failed_pc=0x0c066530u; return 0; }
r[2]=0x00000000u;
goto P_0c066532;
P_0c066532: /* original e058, guest PC 0x0c066532 */
if(!s->budget--) { s->failed_pc=0x0c066532u; return 0; }
r[0]=0x00000058u;
goto P_0c066534;
P_0c066534: /* original 0f26, guest PC 0x0c066534 */
if(!s->budget--) { s->failed_pc=0x0c066534u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066536;
P_0c066536: /* original d146, guest PC 0x0c066536 */
if(!s->budget--) { s->failed_pc=0x0c066536u; return 0; }
r[1]=read(ram,0x0c066650u,4);
goto P_0c066538;
P_0c066538: /* original 6312, guest PC 0x0c066538 */
if(!s->budget--) { s->failed_pc=0x0c066538u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c06653a;
P_0c06653a: /* original 2338, guest PC 0x0c06653a */
if(!s->budget--) { s->failed_pc=0x0c06653au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06653c;
P_0c06653c: /* original 8b02, guest PC 0x0c06653c */
if(!s->budget--) { s->failed_pc=0x0c06653cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066544; }
goto P_0c06653e;
P_0c06653e: /* original d345, guest PC 0x0c06653e */
if(!s->budget--) { s->failed_pc=0x0c06653eu; return 0; }
r[3]=read(ram,0x0c066654u,4);
goto P_0c066540;
P_0c066540: /* original a001, guest PC 0x0c066540 */
if(!s->budget--) { s->failed_pc=0x0c066540u; return 0; }
goto P_0c066546;
P_0c066542: /* original 0009, guest PC 0x0c066542 */
if(!s->budget--) { s->failed_pc=0x0c066542u; return 0; }
goto P_0c066544;
P_0c066544: /* original e300, guest PC 0x0c066544 */
if(!s->budget--) { s->failed_pc=0x0c066544u; return 0; }
r[3]=0x00000000u;
goto P_0c066546;
P_0c066546: /* original e044, guest PC 0x0c066546 */
if(!s->budget--) { s->failed_pc=0x0c066546u; return 0; }
r[0]=0x00000044u;
goto P_0c066548;
P_0c066548: /* original d143, guest PC 0x0c066548 */
if(!s->budget--) { s->failed_pc=0x0c066548u; return 0; }
r[1]=read(ram,0x0c066658u,4);
goto P_0c06654a;
P_0c06654a: /* original 0f36, guest PC 0x0c06654a */
if(!s->budget--) { s->failed_pc=0x0c06654au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06654c;
P_0c06654c: /* original 6212, guest PC 0x0c06654c */
if(!s->budget--) { s->failed_pc=0x0c06654cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06654e;
P_0c06654e: /* original 2228, guest PC 0x0c06654e */
if(!s->budget--) { s->failed_pc=0x0c06654eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066550;
P_0c066550: /* original 8b03, guest PC 0x0c066550 */
if(!s->budget--) { s->failed_pc=0x0c066550u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06655a; }
goto P_0c066552;
P_0c066552: /* original e054, guest PC 0x0c066552 */
if(!s->budget--) { s->failed_pc=0x0c066552u; return 0; }
r[0]=0x00000054u;
goto P_0c066554;
P_0c066554: /* original d23f, guest PC 0x0c066554 */
if(!s->budget--) { s->failed_pc=0x0c066554u; return 0; }
r[2]=read(ram,0x0c066654u,4);
goto P_0c066556;
P_0c066556: /* original a003, guest PC 0x0c066556 */
if(!s->budget--) { s->failed_pc=0x0c066556u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066560;
P_0c066558: /* original 0f26, guest PC 0x0c066558 */
if(!s->budget--) { s->failed_pc=0x0c066558u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06655a;
P_0c06655a: /* original e300, guest PC 0x0c06655a */
if(!s->budget--) { s->failed_pc=0x0c06655au; return 0; }
r[3]=0x00000000u;
goto P_0c06655c;
P_0c06655c: /* original e054, guest PC 0x0c06655c */
if(!s->budget--) { s->failed_pc=0x0c06655cu; return 0; }
r[0]=0x00000054u;
goto P_0c06655e;
P_0c06655e: /* original 0f36, guest PC 0x0c06655e */
if(!s->budget--) { s->failed_pc=0x0c06655eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066560;
P_0c066560: /* original d13e, guest PC 0x0c066560 */
if(!s->budget--) { s->failed_pc=0x0c066560u; return 0; }
r[1]=read(ram,0x0c06665cu,4);
goto P_0c066562;
P_0c066562: /* original 6212, guest PC 0x0c066562 */
if(!s->budget--) { s->failed_pc=0x0c066562u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066564;
P_0c066564: /* original 2228, guest PC 0x0c066564 */
if(!s->budget--) { s->failed_pc=0x0c066564u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066566;
P_0c066566: /* original 8b03, guest PC 0x0c066566 */
if(!s->budget--) { s->failed_pc=0x0c066566u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066570; }
goto P_0c066568;
P_0c066568: /* original d23a, guest PC 0x0c066568 */
if(!s->budget--) { s->failed_pc=0x0c066568u; return 0; }
r[2]=read(ram,0x0c066654u,4);
goto P_0c06656a;
P_0c06656a: /* original e048, guest PC 0x0c06656a */
if(!s->budget--) { s->failed_pc=0x0c06656au; return 0; }
r[0]=0x00000048u;
goto P_0c06656c;
P_0c06656c: /* original a003, guest PC 0x0c06656c */
if(!s->budget--) { s->failed_pc=0x0c06656cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066576;
P_0c06656e: /* original 0f26, guest PC 0x0c06656e */
if(!s->budget--) { s->failed_pc=0x0c06656eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066570;
P_0c066570: /* original e300, guest PC 0x0c066570 */
if(!s->budget--) { s->failed_pc=0x0c066570u; return 0; }
r[3]=0x00000000u;
goto P_0c066572;
P_0c066572: /* original e048, guest PC 0x0c066572 */
if(!s->budget--) { s->failed_pc=0x0c066572u; return 0; }
r[0]=0x00000048u;
goto P_0c066574;
P_0c066574: /* original 0f36, guest PC 0x0c066574 */
if(!s->budget--) { s->failed_pc=0x0c066574u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066576;
P_0c066576: /* original d13a, guest PC 0x0c066576 */
if(!s->budget--) { s->failed_pc=0x0c066576u; return 0; }
r[1]=read(ram,0x0c066660u,4);
goto P_0c066578;
P_0c066578: /* original 6212, guest PC 0x0c066578 */
if(!s->budget--) { s->failed_pc=0x0c066578u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06657a;
P_0c06657a: /* original 2228, guest PC 0x0c06657a */
if(!s->budget--) { s->failed_pc=0x0c06657au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c06657c;
P_0c06657c: /* original 8b03, guest PC 0x0c06657c */
if(!s->budget--) { s->failed_pc=0x0c06657cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066586; }
goto P_0c06657e;
P_0c06657e: /* original e04c, guest PC 0x0c06657e */
if(!s->budget--) { s->failed_pc=0x0c06657eu; return 0; }
r[0]=0x0000004cu;
goto P_0c066580;
P_0c066580: /* original d234, guest PC 0x0c066580 */
if(!s->budget--) { s->failed_pc=0x0c066580u; return 0; }
r[2]=read(ram,0x0c066654u,4);
goto P_0c066582;
P_0c066582: /* original a003, guest PC 0x0c066582 */
if(!s->budget--) { s->failed_pc=0x0c066582u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06658c;
P_0c066584: /* original 0f26, guest PC 0x0c066584 */
if(!s->budget--) { s->failed_pc=0x0c066584u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066586;
P_0c066586: /* original e300, guest PC 0x0c066586 */
if(!s->budget--) { s->failed_pc=0x0c066586u; return 0; }
r[3]=0x00000000u;
goto P_0c066588;
P_0c066588: /* original e04c, guest PC 0x0c066588 */
if(!s->budget--) { s->failed_pc=0x0c066588u; return 0; }
r[0]=0x0000004cu;
goto P_0c06658a;
P_0c06658a: /* original 0f36, guest PC 0x0c06658a */
if(!s->budget--) { s->failed_pc=0x0c06658au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06658c;
P_0c06658c: /* original d135, guest PC 0x0c06658c */
if(!s->budget--) { s->failed_pc=0x0c06658cu; return 0; }
r[1]=read(ram,0x0c066664u,4);
goto P_0c06658e;
P_0c06658e: /* original 6212, guest PC 0x0c06658e */
if(!s->budget--) { s->failed_pc=0x0c06658eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066590;
P_0c066590: /* original 2228, guest PC 0x0c066590 */
if(!s->budget--) { s->failed_pc=0x0c066590u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066592;
P_0c066592: /* original 8b03, guest PC 0x0c066592 */
if(!s->budget--) { s->failed_pc=0x0c066592u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06659c; }
goto P_0c066594;
P_0c066594: /* original d22f, guest PC 0x0c066594 */
if(!s->budget--) { s->failed_pc=0x0c066594u; return 0; }
r[2]=read(ram,0x0c066654u,4);
goto P_0c066596;
P_0c066596: /* original e050, guest PC 0x0c066596 */
if(!s->budget--) { s->failed_pc=0x0c066596u; return 0; }
r[0]=0x00000050u;
goto P_0c066598;
P_0c066598: /* original a003, guest PC 0x0c066598 */
if(!s->budget--) { s->failed_pc=0x0c066598u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0665a2;
P_0c06659a: /* original 0f26, guest PC 0x0c06659a */
if(!s->budget--) { s->failed_pc=0x0c06659au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06659c;
P_0c06659c: /* original e300, guest PC 0x0c06659c */
if(!s->budget--) { s->failed_pc=0x0c06659cu; return 0; }
r[3]=0x00000000u;
goto P_0c06659e;
P_0c06659e: /* original e050, guest PC 0x0c06659e */
if(!s->budget--) { s->failed_pc=0x0c06659eu; return 0; }
r[0]=0x00000050u;
goto P_0c0665a0;
P_0c0665a0: /* original 0f36, guest PC 0x0c0665a0 */
if(!s->budget--) { s->failed_pc=0x0c0665a0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0665a2;
P_0c0665a2: /* original d431, guest PC 0x0c0665a2 */
if(!s->budget--) { s->failed_pc=0x0c0665a2u; return 0; }
r[4]=read(ram,0x0c066668u,4);
goto P_0c0665a4;
P_0c0665a4: /* original d32a, guest PC 0x0c0665a4 */
if(!s->budget--) { s->failed_pc=0x0c0665a4u; return 0; }
r[3]=read(ram,0x0c066650u,4);
goto P_0c0665a6;
P_0c0665a6: /* original 6032, guest PC 0x0c0665a6 */
if(!s->budget--) { s->failed_pc=0x0c0665a6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0665a8;
P_0c0665a8: /* original 4008, guest PC 0x0c0665a8 */
if(!s->budget--) { s->failed_pc=0x0c0665a8u; return 0; }
r[0]<<=2;
goto P_0c0665aa;
P_0c0665aa: /* original 024e, guest PC 0x0c0665aa */
if(!s->budget--) { s->failed_pc=0x0c0665aau; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0665ac;
P_0c0665ac: /* original d12a, guest PC 0x0c0665ac */
if(!s->budget--) { s->failed_pc=0x0c0665acu; return 0; }
r[1]=read(ram,0x0c066658u,4);
goto P_0c0665ae;
P_0c0665ae: /* original 4208, guest PC 0x0c0665ae */
if(!s->budget--) { s->failed_pc=0x0c0665aeu; return 0; }
r[2]<<=2;
goto P_0c0665b0;
P_0c0665b0: /* original 1f2b, guest PC 0x0c0665b0 */
if(!s->budget--) { s->failed_pc=0x0c0665b0u; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c0665b2;
P_0c0665b2: /* original 6012, guest PC 0x0c0665b2 */
if(!s->budget--) { s->failed_pc=0x0c0665b2u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0665b4;
P_0c0665b4: /* original 4008, guest PC 0x0c0665b4 */
if(!s->budget--) { s->failed_pc=0x0c0665b4u; return 0; }
r[0]<<=2;
goto P_0c0665b6;
P_0c0665b6: /* original 034e, guest PC 0x0c0665b6 */
if(!s->budget--) { s->failed_pc=0x0c0665b6u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0665b8;
P_0c0665b8: /* original d228, guest PC 0x0c0665b8 */
if(!s->budget--) { s->failed_pc=0x0c0665b8u; return 0; }
r[2]=read(ram,0x0c06665cu,4);
goto P_0c0665ba;
P_0c0665ba: /* original 4308, guest PC 0x0c0665ba */
if(!s->budget--) { s->failed_pc=0x0c0665bau; return 0; }
r[3]<<=2;
goto P_0c0665bc;
P_0c0665bc: /* original 1f3c, guest PC 0x0c0665bc */
if(!s->budget--) { s->failed_pc=0x0c0665bcu; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c0665be;
P_0c0665be: /* original 6022, guest PC 0x0c0665be */
if(!s->budget--) { s->failed_pc=0x0c0665beu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0665c0;
P_0c0665c0: /* original 4008, guest PC 0x0c0665c0 */
if(!s->budget--) { s->failed_pc=0x0c0665c0u; return 0; }
r[0]<<=2;
goto P_0c0665c2;
P_0c0665c2: /* original 034e, guest PC 0x0c0665c2 */
if(!s->budget--) { s->failed_pc=0x0c0665c2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0665c4;
P_0c0665c4: /* original 4308, guest PC 0x0c0665c4 */
if(!s->budget--) { s->failed_pc=0x0c0665c4u; return 0; }
r[3]<<=2;
goto P_0c0665c6;
P_0c0665c6: /* original 1f3d, guest PC 0x0c0665c6 */
if(!s->budget--) { s->failed_pc=0x0c0665c6u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c0665c8;
P_0c0665c8: /* original 5012, guest PC 0x0c0665c8 */
if(!s->budget--) { s->failed_pc=0x0c0665c8u; return 0; }
r[0]=read(ram,r[1]+8,4);
goto P_0c0665ca;
P_0c0665ca: /* original 4008, guest PC 0x0c0665ca */
if(!s->budget--) { s->failed_pc=0x0c0665cau; return 0; }
r[0]<<=2;
goto P_0c0665cc;
P_0c0665cc: /* original 034e, guest PC 0x0c0665cc */
if(!s->budget--) { s->failed_pc=0x0c0665ccu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0665ce;
P_0c0665ce: /* original 7208, guest PC 0x0c0665ce */
if(!s->budget--) { s->failed_pc=0x0c0665ceu; return 0; }
r[2]+=0x00000008u;
goto P_0c0665d0;
P_0c0665d0: /* original 4308, guest PC 0x0c0665d0 */
if(!s->budget--) { s->failed_pc=0x0c0665d0u; return 0; }
r[3]<<=2;
goto P_0c0665d2;
P_0c0665d2: /* original 1f3e, guest PC 0x0c0665d2 */
if(!s->budget--) { s->failed_pc=0x0c0665d2u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0665d4;
P_0c0665d4: /* original 6022, guest PC 0x0c0665d4 */
if(!s->budget--) { s->failed_pc=0x0c0665d4u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0665d6;
P_0c0665d6: /* original 4008, guest PC 0x0c0665d6 */
if(!s->budget--) { s->failed_pc=0x0c0665d6u; return 0; }
r[0]<<=2;
goto P_0c0665d8;
P_0c0665d8: /* original 034e, guest PC 0x0c0665d8 */
if(!s->budget--) { s->failed_pc=0x0c0665d8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0665da;
P_0c0665da: /* original 4308, guest PC 0x0c0665da */
if(!s->budget--) { s->failed_pc=0x0c0665dau; return 0; }
r[3]<<=2;
goto P_0c0665dc;
P_0c0665dc: /* original 1f3f, guest PC 0x0c0665dc */
if(!s->budget--) { s->failed_pc=0x0c0665dcu; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0665de;
P_0c0665de: /* original d023, guest PC 0x0c0665de */
if(!s->budget--) { s->failed_pc=0x0c0665deu; return 0; }
r[0]=read(ram,0x0c06666cu,4);
goto P_0c0665e0;
P_0c0665e0: /* original 01ce, guest PC 0x0c0665e0 */
if(!s->budget--) { s->failed_pc=0x0c0665e0u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c0665e2;
P_0c0665e2: /* original 1f18, guest PC 0x0c0665e2 */
if(!s->budget--) { s->failed_pc=0x0c0665e2u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c0665e4;
P_0c0665e4: /* original d31a, guest PC 0x0c0665e4 */
if(!s->budget--) { s->failed_pc=0x0c0665e4u; return 0; }
r[3]=read(ram,0x0c066650u,4);
goto P_0c0665e6;
P_0c0665e6: /* original 6032, guest PC 0x0c0665e6 */
if(!s->budget--) { s->failed_pc=0x0c0665e6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0665e8;
P_0c0665e8: /* original 4008, guest PC 0x0c0665e8 */
if(!s->budget--) { s->failed_pc=0x0c0665e8u; return 0; }
r[0]<<=2;
goto P_0c0665ea;
P_0c0665ea: /* original 72f4, guest PC 0x0c0665ea */
if(!s->budget--) { s->failed_pc=0x0c0665eau; return 0; }
r[2]+=0xfffffff4u;
goto P_0c0665ec;
P_0c0665ec: /* original 014e, guest PC 0x0c0665ec */
if(!s->budget--) { s->failed_pc=0x0c0665ecu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0665ee;
P_0c0665ee: /* original 55f2, guest PC 0x0c0665ee */
if(!s->budget--) { s->failed_pc=0x0c0665eeu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0665f0;
P_0c0665f0: /* original 50f8, guest PC 0x0c0665f0 */
if(!s->budget--) { s->failed_pc=0x0c0665f0u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c0665f2;
P_0c0665f2: /* original 0157, guest PC 0x0c0665f2 */
if(!s->budget--) { s->failed_pc=0x0c0665f2u; return 0; }
r[19]=r[1]*r[5];
goto P_0c0665f4;
P_0c0665f4: /* original 011a, guest PC 0x0c0665f4 */
if(!s->budget--) { s->failed_pc=0x0c0665f4u; return 0; }
r[1]=r[19];
goto P_0c0665f6;
P_0c0665f6: /* original 4108, guest PC 0x0c0665f6 */
if(!s->budget--) { s->failed_pc=0x0c0665f6u; return 0; }
r[1]<<=2;
goto P_0c0665f8;
P_0c0665f8: /* original 310c, guest PC 0x0c0665f8 */
if(!s->budget--) { s->failed_pc=0x0c0665f8u; return 0; }
r[1]+=r[0];
goto P_0c0665fa;
P_0c0665fa: /* original 1f17, guest PC 0x0c0665fa */
if(!s->budget--) { s->failed_pc=0x0c0665fau; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c0665fc;
P_0c0665fc: /* original 6022, guest PC 0x0c0665fc */
if(!s->budget--) { s->failed_pc=0x0c0665fcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0665fe;
P_0c0665fe: /* original 4008, guest PC 0x0c0665fe */
if(!s->budget--) { s->failed_pc=0x0c0665feu; return 0; }
r[0]<<=2;
goto P_0c066600;
P_0c066600: /* original 024e, guest PC 0x0c066600 */
if(!s->budget--) { s->failed_pc=0x0c066600u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c066602;
P_0c066602: /* original 0257, guest PC 0x0c066602 */
if(!s->budget--) { s->failed_pc=0x0c066602u; return 0; }
r[19]=r[2]*r[5];
goto P_0c066604;
P_0c066604: /* original 021a, guest PC 0x0c066604 */
if(!s->budget--) { s->failed_pc=0x0c066604u; return 0; }
r[2]=r[19];
goto P_0c066606;
P_0c066606: /* original 4208, guest PC 0x0c066606 */
if(!s->budget--) { s->failed_pc=0x0c066606u; return 0; }
r[2]<<=2;
goto P_0c066608;
P_0c066608: /* original 312c, guest PC 0x0c066608 */
if(!s->budget--) { s->failed_pc=0x0c066608u; return 0; }
r[1]+=r[2];
goto P_0c06660a;
P_0c06660a: /* original 1f16, guest PC 0x0c06660a */
if(!s->budget--) { s->failed_pc=0x0c06660au; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c06660c;
P_0c06660c: /* original d213, guest PC 0x0c06660c */
if(!s->budget--) { s->failed_pc=0x0c06660cu; return 0; }
r[2]=read(ram,0x0c06665cu,4);
goto P_0c06660e;
P_0c06660e: /* original 6022, guest PC 0x0c06660e */
if(!s->budget--) { s->failed_pc=0x0c06660eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c066610;
P_0c066610: /* original 4008, guest PC 0x0c066610 */
if(!s->budget--) { s->failed_pc=0x0c066610u; return 0; }
r[0]<<=2;
goto P_0c066612;
P_0c066612: /* original 014e, guest PC 0x0c066612 */
if(!s->budget--) { s->failed_pc=0x0c066612u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c066614;
P_0c066614: /* original 50f6, guest PC 0x0c066614 */
if(!s->budget--) { s->failed_pc=0x0c066614u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c066616;
P_0c066616: /* original 0157, guest PC 0x0c066616 */
if(!s->budget--) { s->failed_pc=0x0c066616u; return 0; }
r[19]=r[1]*r[5];
goto P_0c066618;
P_0c066618: /* original 011a, guest PC 0x0c066618 */
if(!s->budget--) { s->failed_pc=0x0c066618u; return 0; }
r[1]=r[19];
goto P_0c06661a;
P_0c06661a: /* original 4108, guest PC 0x0c06661a */
if(!s->budget--) { s->failed_pc=0x0c06661au; return 0; }
r[1]<<=2;
goto P_0c06661c;
P_0c06661c: /* original 310c, guest PC 0x0c06661c */
if(!s->budget--) { s->failed_pc=0x0c06661cu; return 0; }
r[1]+=r[0];
goto P_0c06661e;
P_0c06661e: /* original 1f15, guest PC 0x0c06661e */
if(!s->budget--) { s->failed_pc=0x0c06661eu; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c066620;
P_0c066620: /* original 5033, guest PC 0x0c066620 */
if(!s->budget--) { s->failed_pc=0x0c066620u; return 0; }
r[0]=read(ram,r[3]+12,4);
goto P_0c066622;
P_0c066622: /* original 4008, guest PC 0x0c066622 */
if(!s->budget--) { s->failed_pc=0x0c066622u; return 0; }
r[0]<<=2;
goto P_0c066624;
P_0c066624: /* original 034e, guest PC 0x0c066624 */
if(!s->budget--) { s->failed_pc=0x0c066624u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c066626;
P_0c066626: /* original e21d, guest PC 0x0c066626 */
if(!s->budget--) { s->failed_pc=0x0c066626u; return 0; }
r[2]=0x0000001du;
goto P_0c066628;
P_0c066628: /* original d911, guest PC 0x0c066628 */
if(!s->budget--) { s->failed_pc=0x0c066628u; return 0; }
r[9]=read(ram,0x0c066670u,4);
goto P_0c06662a;
P_0c06662a: /* original e040, guest PC 0x0c06662a */
if(!s->budget--) { s->failed_pc=0x0c06662au; return 0; }
r[0]=0x00000040u;
goto P_0c06662c;
P_0c06662c: /* original da11, guest PC 0x0c06662c */
if(!s->budget--) { s->failed_pc=0x0c06662cu; return 0; }
r[10]=read(ram,0x0c066674u,4);
goto P_0c06662e;
P_0c06662e: /* original 0357, guest PC 0x0c06662e */
if(!s->budget--) { s->failed_pc=0x0c06662eu; return 0; }
r[19]=r[3]*r[5];
goto P_0c066630;
P_0c066630: /* original db11, guest PC 0x0c066630 */
if(!s->budget--) { s->failed_pc=0x0c066630u; return 0; }
r[11]=read(ram,0x0c066678u,4);
goto P_0c066632;
P_0c066632: /* original 031a, guest PC 0x0c066632 */
if(!s->budget--) { s->failed_pc=0x0c066632u; return 0; }
r[3]=r[19];
goto P_0c066634;
P_0c066634: /* original dc11, guest PC 0x0c066634 */
if(!s->budget--) { s->failed_pc=0x0c066634u; return 0; }
r[12]=read(ram,0x0c06667cu,4);
goto P_0c066636;
P_0c066636: /* original 4308, guest PC 0x0c066636 */
if(!s->budget--) { s->failed_pc=0x0c066636u; return 0; }
r[3]<<=2;
goto P_0c066638;
P_0c066638: /* original 313c, guest PC 0x0c066638 */
if(!s->budget--) { s->failed_pc=0x0c066638u; return 0; }
r[1]+=r[3];
goto P_0c06663a;
P_0c06663a: /* original 6353, guest PC 0x0c06663a */
if(!s->budget--) { s->failed_pc=0x0c06663au; return 0; }
r[3]=r[5];
goto P_0c06663c;
P_0c06663c: /* original 0f16, guest PC 0x0c06663c */
if(!s->budget--) { s->failed_pc=0x0c06663cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c06663e;
P_0c06663e: /* original 73ff, guest PC 0x0c06663e */
if(!s->budget--) { s->failed_pc=0x0c06663eu; return 0; }
r[3]+=0xffffffffu;
goto P_0c066640;
P_0c066640: /* original 1f39, guest PC 0x0c066640 */
if(!s->budget--) { s->failed_pc=0x0c066640u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c066642;
P_0c066642: /* original e101, guest PC 0x0c066642 */
if(!s->budget--) { s->failed_pc=0x0c066642u; return 0; }
r[1]=0x00000001u;
goto P_0c066644;
P_0c066644: /* original 2e19, guest PC 0x0c066644 */
if(!s->budget--) { s->failed_pc=0x0c066644u; return 0; }
r[14]&=r[1];
goto P_0c066646;
P_0c066646: /* original 4e2d, guest PC 0x0c066646 */
if(!s->budget--) { s->failed_pc=0x0c066646u; return 0; }
r[14]=(r[2]&0x80000000u)?((r[2]&31u)?r[14]>>((-r[2])&31u):0):r[14]<<(r[2]&31u);
goto P_0c066648;
P_0c066648: /* original 1fea, guest PC 0x0c066648 */
if(!s->budget--) { s->failed_pc=0x0c066648u; return 0; }
write(ram,r[15]+40,r[14],4);
goto P_0c06664a;
P_0c06664a: /* original de02, guest PC 0x0c06664a */
if(!s->budget--) { s->failed_pc=0x0c06664au; return 0; }
r[14]=read(ram,0x0c066654u,4);
goto P_0c06664c;
P_0c06664c: /* original a1de, guest PC 0x0c06664c */
if(!s->budget--) { s->failed_pc=0x0c06664cu; return 0; }
r[13]=0x00000000u;
goto P_0c066a0c;
P_0c06664e: /* original ed00, guest PC 0x0c06664e */
if(!s->budget--) { s->failed_pc=0x0c06664eu; return 0; }
r[13]=0x00000000u;
if(!vf3_matrix_family(0x0c066650u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066650u; return 0; } return 1;
P_0c066680: /* original 907d, guest PC 0x0c066680 */
if(!s->budget--) { s->failed_pc=0x0c066680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06677eu,2);
goto P_0c066682;
P_0c066682: /* original 00fe, guest PC 0x0c066682 */
if(!s->budget--) { s->failed_pc=0x0c066682u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066684;
P_0c066684: /* original 8800, guest PC 0x0c066684 */
if(!s->budget--) { s->failed_pc=0x0c066684u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c066686;
P_0c066686: /* original 8d04, guest PC 0x0c066686 */
if(!s->budget--) { s->failed_pc=0x0c066686u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c066692; }
goto P_0c06668a;
P_0c066688: /* original e400, guest PC 0x0c066688 */
if(!s->budget--) { s->failed_pc=0x0c066688u; return 0; }
r[4]=0x00000000u;
goto P_0c06668a;
P_0c06668a: /* original 8801, guest PC 0x0c06668a */
if(!s->budget--) { s->failed_pc=0x0c06668au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06668c;
P_0c06668c: /* original 890e, guest PC 0x0c06668c */
if(!s->budget--) { s->failed_pc=0x0c06668cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0666ac; }
goto P_0c06668e;
P_0c06668e: /* original a019, guest PC 0x0c06668e */
if(!s->budget--) { s->failed_pc=0x0c06668eu; return 0; }
goto P_0c0666c4;
P_0c066690: /* original 0009, guest PC 0x0c066690 */
if(!s->budget--) { s->failed_pc=0x0c066690u; return 0; }
goto P_0c066692;
P_0c066692: /* original 61d3, guest PC 0x0c066692 */
if(!s->budget--) { s->failed_pc=0x0c066692u; return 0; }
r[1]=r[13];
goto P_0c066694;
P_0c066694: /* original d23d, guest PC 0x0c066694 */
if(!s->budget--) { s->failed_pc=0x0c066694u; return 0; }
r[2]=read(ram,0x0c06678cu,4);
goto P_0c066696;
P_0c066696: /* original d33e, guest PC 0x0c066696 */
if(!s->budget--) { s->failed_pc=0x0c066696u; return 0; }
r[3]=read(ram,0x0c066790u,4);
goto P_0c066698;
P_0c066698: /* original 430b, guest PC 0x0c066698 */
if(!s->budget--) { s->failed_pc=0x0c066698u; return 0; }
target=r[3];
r[16]=code_base|0x0c06669cu;
tmp=read(ram,r[2],4);
r[0]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06669cu) { target=s->pc; goto dispatch; }
goto P_0c06669c;
P_0c06669a: /* original 6022, guest PC 0x0c06669a */
if(!s->budget--) { s->failed_pc=0x0c06669au; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c06669c;
P_0c06669c: /* original 6803, guest PC 0x0c06669c */
if(!s->budget--) { s->failed_pc=0x0c06669cu; return 0; }
r[8]=r[0];
goto P_0c06669e;
P_0c06669e: /* original 6323, guest PC 0x0c06669e */
if(!s->budget--) { s->failed_pc=0x0c06669eu; return 0; }
r[3]=r[2];
goto P_0c0666a0;
P_0c0666a0: /* original 6032, guest PC 0x0c0666a0 */
if(!s->budget--) { s->failed_pc=0x0c0666a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0666a2;
P_0c0666a2: /* original d33c, guest PC 0x0c0666a2 */
if(!s->budget--) { s->failed_pc=0x0c0666a2u; return 0; }
r[3]=read(ram,0x0c066794u,4);
goto P_0c0666a4;
P_0c0666a4: /* original 430b, guest PC 0x0c0666a4 */
if(!s->budget--) { s->failed_pc=0x0c0666a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0666a8u;
r[1]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0666a8u) { target=s->pc; goto dispatch; }
goto P_0c0666a8;
P_0c0666a6: /* original 61d3, guest PC 0x0c0666a6 */
if(!s->budget--) { s->failed_pc=0x0c0666a6u; return 0; }
r[1]=r[13];
goto P_0c0666a8;
P_0c0666a8: /* original a00b, guest PC 0x0c0666a8 */
if(!s->budget--) { s->failed_pc=0x0c0666a8u; return 0; }
goto P_0c0666c2;
P_0c0666aa: /* original 0009, guest PC 0x0c0666aa */
if(!s->budget--) { s->failed_pc=0x0c0666aau; return 0; }
goto P_0c0666ac;
P_0c0666ac: /* original d33a, guest PC 0x0c0666ac */
if(!s->budget--) { s->failed_pc=0x0c0666acu; return 0; }
r[3]=read(ram,0x0c066798u,4);
goto P_0c0666ae;
P_0c0666ae: /* original 61d3, guest PC 0x0c0666ae */
if(!s->budget--) { s->failed_pc=0x0c0666aeu; return 0; }
r[1]=r[13];
goto P_0c0666b0;
P_0c0666b0: /* original d238, guest PC 0x0c0666b0 */
if(!s->budget--) { s->failed_pc=0x0c0666b0u; return 0; }
r[2]=read(ram,0x0c066794u,4);
goto P_0c0666b2;
P_0c0666b2: /* original 420b, guest PC 0x0c0666b2 */
if(!s->budget--) { s->failed_pc=0x0c0666b2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0666b6u;
tmp=read(ram,r[3],4);
r[0]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0666b6u) { target=s->pc; goto dispatch; }
goto P_0c0666b6;
P_0c0666b4: /* original 6032, guest PC 0x0c0666b4 */
if(!s->budget--) { s->failed_pc=0x0c0666b4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0666b6;
P_0c0666b6: /* original 6803, guest PC 0x0c0666b6 */
if(!s->budget--) { s->failed_pc=0x0c0666b6u; return 0; }
r[8]=r[0];
goto P_0c0666b8;
P_0c0666b8: /* original 6233, guest PC 0x0c0666b8 */
if(!s->budget--) { s->failed_pc=0x0c0666b8u; return 0; }
r[2]=r[3];
goto P_0c0666ba;
P_0c0666ba: /* original 6022, guest PC 0x0c0666ba */
if(!s->budget--) { s->failed_pc=0x0c0666bau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0666bc;
P_0c0666bc: /* original d234, guest PC 0x0c0666bc */
if(!s->budget--) { s->failed_pc=0x0c0666bcu; return 0; }
r[2]=read(ram,0x0c066790u,4);
goto P_0c0666be;
P_0c0666be: /* original 420b, guest PC 0x0c0666be */
if(!s->budget--) { s->failed_pc=0x0c0666beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0666c2u;
r[1]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0666c2u) { target=s->pc; goto dispatch; }
goto P_0c0666c2;
P_0c0666c0: /* original 61d3, guest PC 0x0c0666c0 */
if(!s->budget--) { s->failed_pc=0x0c0666c0u; return 0; }
r[1]=r[13];
goto P_0c0666c2;
P_0c0666c2: /* original 1f01, guest PC 0x0c0666c2 */
if(!s->budget--) { s->failed_pc=0x0c0666c2u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0666c4;
P_0c0666c4: /* original d335, guest PC 0x0c0666c4 */
if(!s->budget--) { s->failed_pc=0x0c0666c4u; return 0; }
r[3]=read(ram,0x0c06679cu,4);
goto P_0c0666c6;
P_0c0666c6: /* original 6032, guest PC 0x0c0666c6 */
if(!s->budget--) { s->failed_pc=0x0c0666c6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0666c8;
P_0c0666c8: /* original 8801, guest PC 0x0c0666c8 */
if(!s->budget--) { s->failed_pc=0x0c0666c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0666ca;
P_0c0666ca: /* original 8b09, guest PC 0x0c0666ca */
if(!s->budget--) { s->failed_pc=0x0c0666cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0666e0; }
goto P_0c0666cc;
P_0c0666cc: /* original d234, guest PC 0x0c0666cc */
if(!s->budget--) { s->failed_pc=0x0c0666ccu; return 0; }
r[2]=read(ram,0x0c0667a0u,4);
goto P_0c0666ce;
P_0c0666ce: /* original 6122, guest PC 0x0c0666ce */
if(!s->budget--) { s->failed_pc=0x0c0666ceu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0666d0;
P_0c0666d0: /* original 3182, guest PC 0x0c0666d0 */
if(!s->budget--) { s->failed_pc=0x0c0666d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[8])!=0);
goto P_0c0666d2;
P_0c0666d2: /* original 8b04, guest PC 0x0c0666d2 */
if(!s->budget--) { s->failed_pc=0x0c0666d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0666de; }
goto P_0c0666d4;
P_0c0666d4: /* original 51f1, guest PC 0x0c0666d4 */
if(!s->budget--) { s->failed_pc=0x0c0666d4u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0666d6;
P_0c0666d6: /* original d333, guest PC 0x0c0666d6 */
if(!s->budget--) { s->failed_pc=0x0c0666d6u; return 0; }
r[3]=read(ram,0x0c0667a4u,4);
goto P_0c0666d8;
P_0c0666d8: /* original 6032, guest PC 0x0c0666d8 */
if(!s->budget--) { s->failed_pc=0x0c0666d8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0666da;
P_0c0666da: /* original 3012, guest PC 0x0c0666da */
if(!s->budget--) { s->failed_pc=0x0c0666dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[1])!=0);
goto P_0c0666dc;
P_0c0666dc: /* original 8900, guest PC 0x0c0666dc */
if(!s->budget--) { s->failed_pc=0x0c0666dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0666e0; }
goto P_0c0666de;
P_0c0666de: /* original d432, guest PC 0x0c0666de */
if(!s->budget--) { s->failed_pc=0x0c0666deu; return 0; }
r[4]=read(ram,0x0c0667a8u,4);
goto P_0c0666e0;
P_0c0666e0: /* original d22d, guest PC 0x0c0666e0 */
if(!s->budget--) { s->failed_pc=0x0c0666e0u; return 0; }
r[2]=read(ram,0x0c066798u,4);
goto P_0c0666e2;
P_0c0666e2: /* original 6322, guest PC 0x0c0666e2 */
if(!s->budget--) { s->failed_pc=0x0c0666e2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0666e4;
P_0c0666e4: /* original 52f1, guest PC 0x0c0666e4 */
if(!s->budget--) { s->failed_pc=0x0c0666e4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0666e6;
P_0c0666e6: /* original 0237, guest PC 0x0c0666e6 */
if(!s->budget--) { s->failed_pc=0x0c0666e6u; return 0; }
r[19]=r[2]*r[3];
goto P_0c0666e8;
P_0c0666e8: /* original 53f9, guest PC 0x0c0666e8 */
if(!s->budget--) { s->failed_pc=0x0c0666e8u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0666ea;
P_0c0666ea: /* original 051a, guest PC 0x0c0666ea */
if(!s->budget--) { s->failed_pc=0x0c0666eau; return 0; }
r[5]=r[19];
goto P_0c0666ec;
P_0c0666ec: /* original 358c, guest PC 0x0c0666ec */
if(!s->budget--) { s->failed_pc=0x0c0666ecu; return 0; }
r[5]+=r[8];
goto P_0c0666ee;
P_0c0666ee: /* original 3d30, guest PC 0x0c0666ee */
if(!s->budget--) { s->failed_pc=0x0c0666eeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0666f0;
P_0c0666f0: /* original 0029, guest PC 0x0c0666f0 */
if(!s->budget--) { s->failed_pc=0x0c0666f0u; return 0; }
r[0]=r[17]&1u;
goto P_0c0666f2;
P_0c0666f2: /* original c901, guest PC 0x0c0666f2 */
if(!s->budget--) { s->failed_pc=0x0c0666f2u; return 0; }
r[0]&=1u;
goto P_0c0666f4;
P_0c0666f4: /* original 4005, guest PC 0x0c0666f4 */
if(!s->budget--) { s->failed_pc=0x0c0666f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c0666f6;
P_0c0666f6: /* original 6303, guest PC 0x0c0666f6 */
if(!s->budget--) { s->failed_pc=0x0c0666f6u; return 0; }
r[3]=r[0];
goto P_0c0666f8;
P_0c0666f8: /* original 6023, guest PC 0x0c0666f8 */
if(!s->budget--) { s->failed_pc=0x0c0666f8u; return 0; }
r[0]=r[2];
goto P_0c0666fa;
P_0c0666fa: /* original 0009, guest PC 0x0c0666fa */
if(!s->budget--) { s->failed_pc=0x0c0666fau; return 0; }
goto P_0c0666fc;
P_0c0666fc: /* original 51fa, guest PC 0x0c0666fc */
if(!s->budget--) { s->failed_pc=0x0c0666fcu; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0666fe;
P_0c0666fe: /* original c93f, guest PC 0x0c0666fe */
if(!s->budget--) { s->failed_pc=0x0c0666feu; return 0; }
r[0]&=63u;
goto P_0c066700;
P_0c066700: /* original 4018, guest PC 0x0c066700 */
if(!s->budget--) { s->failed_pc=0x0c066700u; return 0; }
r[0]<<=8;
goto P_0c066702;
P_0c066702: /* original 230b, guest PC 0x0c066702 */
if(!s->budget--) { s->failed_pc=0x0c066702u; return 0; }
r[3]|=r[0];
goto P_0c066704;
P_0c066704: /* original 903c, guest PC 0x0c066704 */
if(!s->budget--) { s->failed_pc=0x0c066704u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066780u,2);
goto P_0c066706;
P_0c066706: /* original e23f, guest PC 0x0c066706 */
if(!s->budget--) { s->failed_pc=0x0c066706u; return 0; }
r[2]=0x0000003fu;
goto P_0c066708;
P_0c066708: /* original 2289, guest PC 0x0c066708 */
if(!s->budget--) { s->failed_pc=0x0c066708u; return 0; }
r[2]&=r[8];
goto P_0c06670a;
P_0c06670a: /* original 4208, guest PC 0x0c06670a */
if(!s->budget--) { s->failed_pc=0x0c06670au; return 0; }
r[2]<<=2;
goto P_0c06670c;
P_0c06670c: /* original 232b, guest PC 0x0c06670c */
if(!s->budget--) { s->failed_pc=0x0c06670cu; return 0; }
r[3]|=r[2];
goto P_0c06670e;
P_0c06670e: /* original 231b, guest PC 0x0c06670e */
if(!s->budget--) { s->failed_pc=0x0c06670eu; return 0; }
r[3]|=r[1];
goto P_0c066710;
P_0c066710: /* original 0f36, guest PC 0x0c066710 */
if(!s->budget--) { s->failed_pc=0x0c066710u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066712;
P_0c066712: /* original e044, guest PC 0x0c066712 */
if(!s->budget--) { s->failed_pc=0x0c066712u; return 0; }
r[0]=0x00000044u;
goto P_0c066714;
P_0c066714: /* original 52fb, guest PC 0x0c066714 */
if(!s->budget--) { s->failed_pc=0x0c066714u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c066716;
P_0c066716: /* original 0257, guest PC 0x0c066716 */
if(!s->budget--) { s->failed_pc=0x0c066716u; return 0; }
r[19]=r[2]*r[5];
goto P_0c066718;
P_0c066718: /* original 53f8, guest PC 0x0c066718 */
if(!s->budget--) { s->failed_pc=0x0c066718u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c06671a;
P_0c06671a: /* original 021a, guest PC 0x0c06671a */
if(!s->budget--) { s->failed_pc=0x0c06671au; return 0; }
r[2]=r[19];
goto P_0c06671c;
P_0c06671c: /* original 323c, guest PC 0x0c06671c */
if(!s->budget--) { s->failed_pc=0x0c06671cu; return 0; }
r[2]+=r[3];
goto P_0c06671e;
P_0c06671e: /* original 00fe, guest PC 0x0c06671e */
if(!s->budget--) { s->failed_pc=0x0c06671eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066720;
P_0c066720: /* original 220b, guest PC 0x0c066720 */
if(!s->budget--) { s->failed_pc=0x0c066720u; return 0; }
r[2]|=r[0];
goto P_0c066722;
P_0c066722: /* original 224b, guest PC 0x0c066722 */
if(!s->budget--) { s->failed_pc=0x0c066722u; return 0; }
r[2]|=r[4];
goto P_0c066724;
P_0c066724: /* original 902d, guest PC 0x0c066724 */
if(!s->budget--) { s->failed_pc=0x0c066724u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066782u,2);
goto P_0c066726;
P_0c066726: /* original 0f26, guest PC 0x0c066726 */
if(!s->budget--) { s->failed_pc=0x0c066726u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066728;
P_0c066728: /* original 51fc, guest PC 0x0c066728 */
if(!s->budget--) { s->failed_pc=0x0c066728u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c06672a;
P_0c06672a: /* original e054, guest PC 0x0c06672a */
if(!s->budget--) { s->failed_pc=0x0c06672au; return 0; }
r[0]=0x00000054u;
goto P_0c06672c;
P_0c06672c: /* original 52f7, guest PC 0x0c06672c */
if(!s->budget--) { s->failed_pc=0x0c06672cu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06672e;
P_0c06672e: /* original 0157, guest PC 0x0c06672e */
if(!s->budget--) { s->failed_pc=0x0c06672eu; return 0; }
r[19]=r[1]*r[5];
goto P_0c066730;
P_0c066730: /* original 00fe, guest PC 0x0c066730 */
if(!s->budget--) { s->failed_pc=0x0c066730u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066732;
P_0c066732: /* original 011a, guest PC 0x0c066732 */
if(!s->budget--) { s->failed_pc=0x0c066732u; return 0; }
r[1]=r[19];
goto P_0c066734;
P_0c066734: /* original 312c, guest PC 0x0c066734 */
if(!s->budget--) { s->failed_pc=0x0c066734u; return 0; }
r[1]+=r[2];
goto P_0c066736;
P_0c066736: /* original 210b, guest PC 0x0c066736 */
if(!s->budget--) { s->failed_pc=0x0c066736u; return 0; }
r[1]|=r[0];
goto P_0c066738;
P_0c066738: /* original 9024, guest PC 0x0c066738 */
if(!s->budget--) { s->failed_pc=0x0c066738u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066784u,2);
goto P_0c06673a;
P_0c06673a: /* original 214b, guest PC 0x0c06673a */
if(!s->budget--) { s->failed_pc=0x0c06673au; return 0; }
r[1]|=r[4];
goto P_0c06673c;
P_0c06673c: /* original 0f16, guest PC 0x0c06673c */
if(!s->budget--) { s->failed_pc=0x0c06673cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c06673e;
P_0c06673e: /* original e048, guest PC 0x0c06673e */
if(!s->budget--) { s->failed_pc=0x0c06673eu; return 0; }
r[0]=0x00000048u;
goto P_0c066740;
P_0c066740: /* original 53fd, guest PC 0x0c066740 */
if(!s->budget--) { s->failed_pc=0x0c066740u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c066742;
P_0c066742: /* original 0357, guest PC 0x0c066742 */
if(!s->budget--) { s->failed_pc=0x0c066742u; return 0; }
r[19]=r[3]*r[5];
goto P_0c066744;
P_0c066744: /* original 51f6, guest PC 0x0c066744 */
if(!s->budget--) { s->failed_pc=0x0c066744u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c066746;
P_0c066746: /* original 031a, guest PC 0x0c066746 */
if(!s->budget--) { s->failed_pc=0x0c066746u; return 0; }
r[3]=r[19];
goto P_0c066748;
P_0c066748: /* original 00fe, guest PC 0x0c066748 */
if(!s->budget--) { s->failed_pc=0x0c066748u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c06674a;
P_0c06674a: /* original 331c, guest PC 0x0c06674a */
if(!s->budget--) { s->failed_pc=0x0c06674au; return 0; }
r[3]+=r[1];
goto P_0c06674c;
P_0c06674c: /* original 230b, guest PC 0x0c06674c */
if(!s->budget--) { s->failed_pc=0x0c06674cu; return 0; }
r[3]|=r[0];
goto P_0c06674e;
P_0c06674e: /* original 234b, guest PC 0x0c06674e */
if(!s->budget--) { s->failed_pc=0x0c06674eu; return 0; }
r[3]|=r[4];
goto P_0c066750;
P_0c066750: /* original 9019, guest PC 0x0c066750 */
if(!s->budget--) { s->failed_pc=0x0c066750u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066786u,2);
goto P_0c066752;
P_0c066752: /* original 0f36, guest PC 0x0c066752 */
if(!s->budget--) { s->failed_pc=0x0c066752u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066754;
P_0c066754: /* original 52fe, guest PC 0x0c066754 */
if(!s->budget--) { s->failed_pc=0x0c066754u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c066756;
P_0c066756: /* original 0257, guest PC 0x0c066756 */
if(!s->budget--) { s->failed_pc=0x0c066756u; return 0; }
r[19]=r[2]*r[5];
goto P_0c066758;
P_0c066758: /* original 53f5, guest PC 0x0c066758 */
if(!s->budget--) { s->failed_pc=0x0c066758u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06675a;
P_0c06675a: /* original 021a, guest PC 0x0c06675a */
if(!s->budget--) { s->failed_pc=0x0c06675au; return 0; }
r[2]=r[19];
goto P_0c06675c;
P_0c06675c: /* original 323c, guest PC 0x0c06675c */
if(!s->budget--) { s->failed_pc=0x0c06675cu; return 0; }
r[2]+=r[3];
goto P_0c06675e;
P_0c06675e: /* original e04c, guest PC 0x0c06675e */
if(!s->budget--) { s->failed_pc=0x0c06675eu; return 0; }
r[0]=0x0000004cu;
goto P_0c066760;
P_0c066760: /* original 00fe, guest PC 0x0c066760 */
if(!s->budget--) { s->failed_pc=0x0c066760u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066762;
P_0c066762: /* original 220b, guest PC 0x0c066762 */
if(!s->budget--) { s->failed_pc=0x0c066762u; return 0; }
r[2]|=r[0];
goto P_0c066764;
P_0c066764: /* original 9010, guest PC 0x0c066764 */
if(!s->budget--) { s->failed_pc=0x0c066764u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066788u,2);
goto P_0c066766;
P_0c066766: /* original 224b, guest PC 0x0c066766 */
if(!s->budget--) { s->failed_pc=0x0c066766u; return 0; }
r[2]|=r[4];
goto P_0c066768;
P_0c066768: /* original 0f26, guest PC 0x0c066768 */
if(!s->budget--) { s->failed_pc=0x0c066768u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06676a;
P_0c06676a: /* original d210, guest PC 0x0c06676a */
if(!s->budget--) { s->failed_pc=0x0c06676au; return 0; }
r[2]=read(ram,0x0c0667acu,4);
goto P_0c06676c;
P_0c06676c: /* original 6122, guest PC 0x0c06676c */
if(!s->budget--) { s->failed_pc=0x0c06676cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c06676e;
P_0c06676e: /* original 2118, guest PC 0x0c06676e */
if(!s->budget--) { s->failed_pc=0x0c06676eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c066770;
P_0c066770: /* original 891e, guest PC 0x0c066770 */
if(!s->budget--) { s->failed_pc=0x0c066770u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0667b0; }
goto P_0c066772;
P_0c066772: /* original 9008, guest PC 0x0c066772 */
if(!s->budget--) { s->failed_pc=0x0c066772u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066786u,2);
goto P_0c066774;
P_0c066774: /* original 01fe, guest PC 0x0c066774 */
if(!s->budget--) { s->failed_pc=0x0c066774u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c066776;
P_0c066776: /* original 9008, guest PC 0x0c066776 */
if(!s->budget--) { s->failed_pc=0x0c066776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06678au,2);
goto P_0c066778;
P_0c066778: /* original 0f16, guest PC 0x0c066778 */
if(!s->budget--) { s->failed_pc=0x0c066778u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c06677a;
P_0c06677a: /* original a025, guest PC 0x0c06677a */
if(!s->budget--) { s->failed_pc=0x0c06677au; return 0; }
goto P_0c0667c8;
P_0c06677c: /* original 0009, guest PC 0x0c06677c */
if(!s->budget--) { s->failed_pc=0x0c06677cu; return 0; }
if(!vf3_matrix_family(0x0c06677eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06677eu; return 0; } return 1;
P_0c0667b0: /* original 51ff, guest PC 0x0c0667b0 */
if(!s->budget--) { s->failed_pc=0x0c0667b0u; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c0667b2;
P_0c0667b2: /* original e040, guest PC 0x0c0667b2 */
if(!s->budget--) { s->failed_pc=0x0c0667b2u; return 0; }
r[0]=0x00000040u;
goto P_0c0667b4;
P_0c0667b4: /* original 0157, guest PC 0x0c0667b4 */
if(!s->budget--) { s->failed_pc=0x0c0667b4u; return 0; }
r[19]=r[1]*r[5];
goto P_0c0667b6;
P_0c0667b6: /* original 051a, guest PC 0x0c0667b6 */
if(!s->budget--) { s->failed_pc=0x0c0667b6u; return 0; }
r[5]=r[19];
goto P_0c0667b8;
P_0c0667b8: /* original 03fe, guest PC 0x0c0667b8 */
if(!s->budget--) { s->failed_pc=0x0c0667b8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0667ba;
P_0c0667ba: /* original e050, guest PC 0x0c0667ba */
if(!s->budget--) { s->failed_pc=0x0c0667bau; return 0; }
r[0]=0x00000050u;
goto P_0c0667bc;
P_0c0667bc: /* original 02fe, guest PC 0x0c0667bc */
if(!s->budget--) { s->failed_pc=0x0c0667bcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0667be;
P_0c0667be: /* original 353c, guest PC 0x0c0667be */
if(!s->budget--) { s->failed_pc=0x0c0667beu; return 0; }
r[5]+=r[3];
goto P_0c0667c0;
P_0c0667c0: /* original 9011, guest PC 0x0c0667c0 */
if(!s->budget--) { s->failed_pc=0x0c0667c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0667e6u,2);
goto P_0c0667c2;
P_0c0667c2: /* original 252b, guest PC 0x0c0667c2 */
if(!s->budget--) { s->failed_pc=0x0c0667c2u; return 0; }
r[5]|=r[2];
goto P_0c0667c4;
P_0c0667c4: /* original 254b, guest PC 0x0c0667c4 */
if(!s->budget--) { s->failed_pc=0x0c0667c4u; return 0; }
r[5]|=r[4];
goto P_0c0667c6;
P_0c0667c6: /* original 0f56, guest PC 0x0c0667c6 */
if(!s->budget--) { s->failed_pc=0x0c0667c6u; return 0; }
write(ram,r[15]+r[0],r[5],4);
goto P_0c0667c8;
P_0c0667c8: /* original d208, guest PC 0x0c0667c8 */
if(!s->budget--) { s->failed_pc=0x0c0667c8u; return 0; }
r[2]=read(ram,0x0c0667ecu,4);
goto P_0c0667ca;
P_0c0667ca: /* original 6322, guest PC 0x0c0667ca */
if(!s->budget--) { s->failed_pc=0x0c0667cau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0667cc;
P_0c0667cc: /* original 2338, guest PC 0x0c0667cc */
if(!s->budget--) { s->failed_pc=0x0c0667ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0667ce;
P_0c0667ce: /* original 8915, guest PC 0x0c0667ce */
if(!s->budget--) { s->failed_pc=0x0c0667ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0667fc; }
goto P_0c0667d0;
P_0c0667d0: /* original d307, guest PC 0x0c0667d0 */
if(!s->budget--) { s->failed_pc=0x0c0667d0u; return 0; }
r[3]=read(ram,0x0c0667f0u,4);
goto P_0c0667d2;
P_0c0667d2: /* original 6032, guest PC 0x0c0667d2 */
if(!s->budget--) { s->failed_pc=0x0c0667d2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0667d4;
P_0c0667d4: /* original 8801, guest PC 0x0c0667d4 */
if(!s->budget--) { s->failed_pc=0x0c0667d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0667d6;
P_0c0667d6: /* original 8b0d, guest PC 0x0c0667d6 */
if(!s->budget--) { s->failed_pc=0x0c0667d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0667f4; }
goto P_0c0667d8;
P_0c0667d8: /* original 9006, guest PC 0x0c0667d8 */
if(!s->budget--) { s->failed_pc=0x0c0667d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0667e8u,2);
goto P_0c0667da;
P_0c0667da: /* original 00fe, guest PC 0x0c0667da */
if(!s->budget--) { s->failed_pc=0x0c0667dau; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0667dc;
P_0c0667dc: /* original 9105, guest PC 0x0c0667dc */
if(!s->budget--) { s->failed_pc=0x0c0667dcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0667eau,2);
goto P_0c0667de;
P_0c0667de: /* original 31fc, guest PC 0x0c0667de */
if(!s->budget--) { s->failed_pc=0x0c0667deu; return 0; }
r[1]+=r[15];
goto P_0c0667e0;
P_0c0667e0: /* original 2102, guest PC 0x0c0667e0 */
if(!s->budget--) { s->failed_pc=0x0c0667e0u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0667e2;
P_0c0667e2: /* original a00b, guest PC 0x0c0667e2 */
if(!s->budget--) { s->failed_pc=0x0c0667e2u; return 0; }
goto P_0c0667fc;
P_0c0667e4: /* original 0009, guest PC 0x0c0667e4 */
if(!s->budget--) { s->failed_pc=0x0c0667e4u; return 0; }
if(!vf3_matrix_family(0x0c0667e6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0667e6u; return 0; } return 1;
P_0c0667f4: /* original 90a7, guest PC 0x0c0667f4 */
if(!s->budget--) { s->failed_pc=0x0c0667f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066946u,2);
goto P_0c0667f6;
P_0c0667f6: /* original 01fe, guest PC 0x0c0667f6 */
if(!s->budget--) { s->failed_pc=0x0c0667f6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0667f8;
P_0c0667f8: /* original 90a6, guest PC 0x0c0667f8 */
if(!s->budget--) { s->failed_pc=0x0c0667f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066948u,2);
goto P_0c0667fa;
P_0c0667fa: /* original 0f16, guest PC 0x0c0667fa */
if(!s->budget--) { s->failed_pc=0x0c0667fau; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0667fc;
P_0c0667fc: /* original d359, guest PC 0x0c0667fc */
if(!s->budget--) { s->failed_pc=0x0c0667fcu; return 0; }
r[3]=read(ram,0x0c066964u,4);
goto P_0c0667fe;
P_0c0667fe: /* original 6032, guest PC 0x0c0667fe */
if(!s->budget--) { s->failed_pc=0x0c0667feu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c066800;
P_0c066800: /* original c820, guest PC 0x0c066800 */
if(!s->budget--) { s->failed_pc=0x0c066800u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c066802;
P_0c066802: /* original 8b01, guest PC 0x0c066802 */
if(!s->budget--) { s->failed_pc=0x0c066802u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066808; }
goto P_0c066804;
P_0c066804: /* original a0f5, guest PC 0x0c066804 */
if(!s->budget--) { s->failed_pc=0x0c066804u; return 0; }
goto P_0c0669f2;
P_0c066806: /* original 0009, guest PC 0x0c066806 */
if(!s->budget--) { s->failed_pc=0x0c066806u; return 0; }
goto P_0c066808;
P_0c066808: /* original 909f, guest PC 0x0c066808 */
if(!s->budget--) { s->failed_pc=0x0c066808u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c06680a;
P_0c06680a: /* original d157, guest PC 0x0c06680a */
if(!s->budget--) { s->failed_pc=0x0c06680au; return 0; }
r[1]=read(ram,0x0c066968u,4);
goto P_0c06680c;
P_0c06680c: /* original 6212, guest PC 0x0c06680c */
if(!s->budget--) { s->failed_pc=0x0c06680cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06680e;
P_0c06680e: /* original 2228, guest PC 0x0c06680e */
if(!s->budget--) { s->failed_pc=0x0c06680eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066810;
P_0c066810: /* original 8f02, guest PC 0x0c066810 */
if(!s->budget--) { s->failed_pc=0x0c066810u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[15]+r[0],4);
if(!cond) { goto P_0c066818; }
goto P_0c066814;
P_0c066812: /* original 04fe, guest PC 0x0c066812 */
if(!s->budget--) { s->failed_pc=0x0c066812u; return 0; }
r[4]=read(ram,r[15]+r[0],4);
goto P_0c066814;
P_0c066814: /* original a0b0, guest PC 0x0c066814 */
if(!s->budget--) { s->failed_pc=0x0c066814u; return 0; }
goto P_0c066978;
P_0c066816: /* original 0009, guest PC 0x0c066816 */
if(!s->budget--) { s->failed_pc=0x0c066816u; return 0; }
goto P_0c066818;
P_0c066818: /* original 9098, guest PC 0x0c066818 */
if(!s->budget--) { s->failed_pc=0x0c066818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c06681a;
P_0c06681a: /* original 0f46, guest PC 0x0c06681a */
if(!s->budget--) { s->failed_pc=0x0c06681au; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c06681c;
P_0c06681c: /* original 9395, guest PC 0x0c06681c */
if(!s->budget--) { s->failed_pc=0x0c06681cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c06681e;
P_0c06681e: /* original e074, guest PC 0x0c06681e */
if(!s->budget--) { s->failed_pc=0x0c06681eu; return 0; }
r[0]=0x00000074u;
goto P_0c066820;
P_0c066820: /* original 0f46, guest PC 0x0c066820 */
if(!s->budget--) { s->failed_pc=0x0c066820u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c066822;
P_0c066822: /* original 33fc, guest PC 0x0c066822 */
if(!s->budget--) { s->failed_pc=0x0c066822u; return 0; }
r[3]+=r[15];
goto P_0c066824;
P_0c066824: /* original e05c, guest PC 0x0c066824 */
if(!s->budget--) { s->failed_pc=0x0c066824u; return 0; }
r[0]=0x0000005cu;
goto P_0c066826;
P_0c066826: /* original 0f46, guest PC 0x0c066826 */
if(!s->budget--) { s->failed_pc=0x0c066826u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c066828;
P_0c066828: /* original 908f, guest PC 0x0c066828 */
if(!s->budget--) { s->failed_pc=0x0c066828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c06682a;
P_0c06682a: /* original 02fe, guest PC 0x0c06682a */
if(!s->budget--) { s->failed_pc=0x0c06682au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c06682c;
P_0c06682c: /* original 908d, guest PC 0x0c06682c */
if(!s->budget--) { s->failed_pc=0x0c06682cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c06682e;
P_0c06682e: /* original 22a9, guest PC 0x0c06682e */
if(!s->budget--) { s->failed_pc=0x0c06682eu; return 0; }
r[2]&=r[10];
goto P_0c066830;
P_0c066830: /* original 0f26, guest PC 0x0c066830 */
if(!s->budget--) { s->failed_pc=0x0c066830u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066832;
P_0c066832: /* original 908b, guest PC 0x0c066832 */
if(!s->budget--) { s->failed_pc=0x0c066832u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c066834;
P_0c066834: /* original 02fe, guest PC 0x0c066834 */
if(!s->budget--) { s->failed_pc=0x0c066834u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c066836;
P_0c066836: /* original 22a9, guest PC 0x0c066836 */
if(!s->budget--) { s->failed_pc=0x0c066836u; return 0; }
r[2]&=r[10];
goto P_0c066838;
P_0c066838: /* original 9088, guest PC 0x0c066838 */
if(!s->budget--) { s->failed_pc=0x0c066838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c06683a;
P_0c06683a: /* original 0f26, guest PC 0x0c06683a */
if(!s->budget--) { s->failed_pc=0x0c06683au; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c06683c;
P_0c06683c: /* original e074, guest PC 0x0c06683c */
if(!s->budget--) { s->failed_pc=0x0c06683cu; return 0; }
r[0]=0x00000074u;
goto P_0c06683e;
P_0c06683e: /* original 02fe, guest PC 0x0c06683e */
if(!s->budget--) { s->failed_pc=0x0c06683eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c066840;
P_0c066840: /* original 22a9, guest PC 0x0c066840 */
if(!s->budget--) { s->failed_pc=0x0c066840u; return 0; }
r[2]&=r[10];
goto P_0c066842;
P_0c066842: /* original e074, guest PC 0x0c066842 */
if(!s->budget--) { s->failed_pc=0x0c066842u; return 0; }
r[0]=0x00000074u;
goto P_0c066844;
P_0c066844: /* original 0f26, guest PC 0x0c066844 */
if(!s->budget--) { s->failed_pc=0x0c066844u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066846;
P_0c066846: /* original d249, guest PC 0x0c066846 */
if(!s->budget--) { s->failed_pc=0x0c066846u; return 0; }
r[2]=read(ram,0x0c06696cu,4);
goto P_0c066848;
P_0c066848: /* original 907f, guest PC 0x0c066848 */
if(!s->budget--) { s->failed_pc=0x0c066848u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c06684a;
P_0c06684a: /* original 00fe, guest PC 0x0c06684a */
if(!s->budget--) { s->failed_pc=0x0c06684au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c06684c;
P_0c06684c: /* original 2029, guest PC 0x0c06684c */
if(!s->budget--) { s->failed_pc=0x0c06684cu; return 0; }
r[0]&=r[2];
goto P_0c06684e;
P_0c06684e: /* original 2302, guest PC 0x0c06684e */
if(!s->budget--) { s->failed_pc=0x0c06684eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c066850;
P_0c066850: /* original 907c, guest PC 0x0c066850 */
if(!s->budget--) { s->failed_pc=0x0c066850u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c066852;
P_0c066852: /* original 03fe, guest PC 0x0c066852 */
if(!s->budget--) { s->failed_pc=0x0c066852u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c066854;
P_0c066854: /* original 239b, guest PC 0x0c066854 */
if(!s->budget--) { s->failed_pc=0x0c066854u; return 0; }
r[3]|=r[9];
goto P_0c066856;
P_0c066856: /* original 61f3, guest PC 0x0c066856 */
if(!s->budget--) { s->failed_pc=0x0c066856u; return 0; }
r[1]=r[15];
goto P_0c066858;
P_0c066858: /* original 9078, guest PC 0x0c066858 */
if(!s->budget--) { s->failed_pc=0x0c066858u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c06685a;
P_0c06685a: /* original 0f36, guest PC 0x0c06685a */
if(!s->budget--) { s->failed_pc=0x0c06685au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06685c;
P_0c06685c: /* original e074, guest PC 0x0c06685c */
if(!s->budget--) { s->failed_pc=0x0c06685cu; return 0; }
r[0]=0x00000074u;
goto P_0c06685e;
P_0c06685e: /* original 03fe, guest PC 0x0c06685e */
if(!s->budget--) { s->failed_pc=0x0c06685eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c066860;
P_0c066860: /* original 239b, guest PC 0x0c066860 */
if(!s->budget--) { s->failed_pc=0x0c066860u; return 0; }
r[3]|=r[9];
goto P_0c066862;
P_0c066862: /* original e074, guest PC 0x0c066862 */
if(!s->budget--) { s->failed_pc=0x0c066862u; return 0; }
r[0]=0x00000074u;
goto P_0c066864;
P_0c066864: /* original 0f36, guest PC 0x0c066864 */
if(!s->budget--) { s->failed_pc=0x0c066864u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066866;
P_0c066866: /* original e05c, guest PC 0x0c066866 */
if(!s->budget--) { s->failed_pc=0x0c066866u; return 0; }
r[0]=0x0000005cu;
goto P_0c066868;
P_0c066868: /* original 03fe, guest PC 0x0c066868 */
if(!s->budget--) { s->failed_pc=0x0c066868u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06686a;
P_0c06686a: /* original e05c, guest PC 0x0c06686a */
if(!s->budget--) { s->failed_pc=0x0c06686au; return 0; }
r[0]=0x0000005cu;
goto P_0c06686c;
P_0c06686c: /* original 239b, guest PC 0x0c06686c */
if(!s->budget--) { s->failed_pc=0x0c06686cu; return 0; }
r[3]|=r[9];
goto P_0c06686e;
P_0c06686e: /* original 0f36, guest PC 0x0c06686e */
if(!s->budget--) { s->failed_pc=0x0c06686eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066870;
P_0c066870: /* original 906b, guest PC 0x0c066870 */
if(!s->budget--) { s->failed_pc=0x0c066870u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c066872;
P_0c066872: /* original 03fe, guest PC 0x0c066872 */
if(!s->budget--) { s->failed_pc=0x0c066872u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c066874;
P_0c066874: /* original 9069, guest PC 0x0c066874 */
if(!s->budget--) { s->failed_pc=0x0c066874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c066876;
P_0c066876: /* original 23bb, guest PC 0x0c066876 */
if(!s->budget--) { s->failed_pc=0x0c066876u; return 0; }
r[3]|=r[11];
goto P_0c066878;
P_0c066878: /* original 0f36, guest PC 0x0c066878 */
if(!s->budget--) { s->failed_pc=0x0c066878u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06687a;
P_0c06687a: /* original 9067, guest PC 0x0c06687a */
if(!s->budget--) { s->failed_pc=0x0c06687au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c06687c;
P_0c06687c: /* original 03fe, guest PC 0x0c06687c */
if(!s->budget--) { s->failed_pc=0x0c06687cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06687e;
P_0c06687e: /* original 23bb, guest PC 0x0c06687e */
if(!s->budget--) { s->failed_pc=0x0c06687eu; return 0; }
r[3]|=r[11];
goto P_0c066880;
P_0c066880: /* original 9064, guest PC 0x0c066880 */
if(!s->budget--) { s->failed_pc=0x0c066880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c066882;
P_0c066882: /* original 0f36, guest PC 0x0c066882 */
if(!s->budget--) { s->failed_pc=0x0c066882u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c066884;
P_0c066884: /* original e074, guest PC 0x0c066884 */
if(!s->budget--) { s->failed_pc=0x0c066884u; return 0; }
r[0]=0x00000074u;
goto P_0c066886;
P_0c066886: /* original 03fe, guest PC 0x0c066886 */
if(!s->budget--) { s->failed_pc=0x0c066886u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c066888;
P_0c066888: /* original 23bb, guest PC 0x0c066888 */
if(!s->budget--) { s->failed_pc=0x0c066888u; return 0; }
r[3]|=r[11];
goto P_0c06688a;
P_0c06688a: /* original e074, guest PC 0x0c06688a */
if(!s->budget--) { s->failed_pc=0x0c06688au; return 0; }
r[0]=0x00000074u;
goto P_0c06688c;
P_0c06688c: /* original 0f36, guest PC 0x0c06688c */
if(!s->budget--) { s->failed_pc=0x0c06688cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06688e;
P_0c06688e: /* original e05c, guest PC 0x0c06688e */
if(!s->budget--) { s->failed_pc=0x0c06688eu; return 0; }
r[0]=0x0000005cu;
goto P_0c066890;
P_0c066890: /* original d337, guest PC 0x0c066890 */
if(!s->budget--) { s->failed_pc=0x0c066890u; return 0; }
r[3]=read(ram,0x0c066970u,4);
goto P_0c066892;
P_0c066892: /* original 00fe, guest PC 0x0c066892 */
if(!s->budget--) { s->failed_pc=0x0c066892u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066894;
P_0c066894: /* original 2039, guest PC 0x0c066894 */
if(!s->budget--) { s->failed_pc=0x0c066894u; return 0; }
r[0]&=r[3];
goto P_0c066896;
P_0c066896: /* original 715c, guest PC 0x0c066896 */
if(!s->budget--) { s->failed_pc=0x0c066896u; return 0; }
r[1]+=0x0000005cu;
goto P_0c066898;
P_0c066898: /* original 9258, guest PC 0x0c066898 */
if(!s->budget--) { s->failed_pc=0x0c066898u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c06689a;
P_0c06689a: /* original 2102, guest PC 0x0c06689a */
if(!s->budget--) { s->failed_pc=0x0c06689au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c06689c;
P_0c06689c: /* original d135, guest PC 0x0c06689c */
if(!s->budget--) { s->failed_pc=0x0c06689cu; return 0; }
r[1]=read(ram,0x0c066974u,4);
goto P_0c06689e;
P_0c06689e: /* original 32fc, guest PC 0x0c06689e */
if(!s->budget--) { s->failed_pc=0x0c06689eu; return 0; }
r[2]+=r[15];
goto P_0c0668a0;
P_0c0668a0: /* original 9054, guest PC 0x0c0668a0 */
if(!s->budget--) { s->failed_pc=0x0c0668a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c0668a2;
P_0c0668a2: /* original 00fe, guest PC 0x0c0668a2 */
if(!s->budget--) { s->failed_pc=0x0c0668a2u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0668a4;
P_0c0668a4: /* original 2019, guest PC 0x0c0668a4 */
if(!s->budget--) { s->failed_pc=0x0c0668a4u; return 0; }
r[0]&=r[1];
goto P_0c0668a6;
P_0c0668a6: /* original 2202, guest PC 0x0c0668a6 */
if(!s->budget--) { s->failed_pc=0x0c0668a6u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0668a8;
P_0c0668a8: /* original e058, guest PC 0x0c0668a8 */
if(!s->budget--) { s->failed_pc=0x0c0668a8u; return 0; }
r[0]=0x00000058u;
goto P_0c0668aa;
P_0c0668aa: /* original 02fe, guest PC 0x0c0668aa */
if(!s->budget--) { s->failed_pc=0x0c0668aau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0668ac;
P_0c0668ac: /* original 2228, guest PC 0x0c0668ac */
if(!s->budget--) { s->failed_pc=0x0c0668acu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0668ae;
P_0c0668ae: /* original 8902, guest PC 0x0c0668ae */
if(!s->budget--) { s->failed_pc=0x0c0668aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0668b6; }
goto P_0c0668b0;
P_0c0668b0: /* original 52f4, guest PC 0x0c0668b0 */
if(!s->budget--) { s->failed_pc=0x0c0668b0u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0668b2;
P_0c0668b2: /* original 904c, guest PC 0x0c0668b2 */
if(!s->budget--) { s->failed_pc=0x0c0668b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694eu,2);
goto P_0c0668b4;
P_0c0668b4: /* original 0f26, guest PC 0x0c0668b4 */
if(!s->budget--) { s->failed_pc=0x0c0668b4u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0668b6;
P_0c0668b6: /* original 904b, guest PC 0x0c0668b6 */
if(!s->budget--) { s->failed_pc=0x0c0668b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066950u,2);
goto P_0c0668b8;
P_0c0668b8: /* original 0fe6, guest PC 0x0c0668b8 */
if(!s->budget--) { s->failed_pc=0x0c0668b8u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668ba;
P_0c0668ba: /* original 904a, guest PC 0x0c0668ba */
if(!s->budget--) { s->failed_pc=0x0c0668bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066952u,2);
goto P_0c0668bc;
P_0c0668bc: /* original 0fe6, guest PC 0x0c0668bc */
if(!s->budget--) { s->failed_pc=0x0c0668bcu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668be;
P_0c0668be: /* original 53f4, guest PC 0x0c0668be */
if(!s->budget--) { s->failed_pc=0x0c0668beu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0668c0;
P_0c0668c0: /* original 9048, guest PC 0x0c0668c0 */
if(!s->budget--) { s->failed_pc=0x0c0668c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066954u,2);
goto P_0c0668c2;
P_0c0668c2: /* original 0f36, guest PC 0x0c0668c2 */
if(!s->budget--) { s->failed_pc=0x0c0668c2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0668c4;
P_0c0668c4: /* original 9047, guest PC 0x0c0668c4 */
if(!s->budget--) { s->failed_pc=0x0c0668c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066956u,2);
goto P_0c0668c6;
P_0c0668c6: /* original 0fe6, guest PC 0x0c0668c6 */
if(!s->budget--) { s->failed_pc=0x0c0668c6u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668c8;
P_0c0668c8: /* original 9046, guest PC 0x0c0668c8 */
if(!s->budget--) { s->failed_pc=0x0c0668c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066958u,2);
goto P_0c0668ca;
P_0c0668ca: /* original 0fe6, guest PC 0x0c0668ca */
if(!s->budget--) { s->failed_pc=0x0c0668cau; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668cc;
P_0c0668cc: /* original e078, guest PC 0x0c0668cc */
if(!s->budget--) { s->failed_pc=0x0c0668ccu; return 0; }
r[0]=0x00000078u;
goto P_0c0668ce;
P_0c0668ce: /* original 0fe6, guest PC 0x0c0668ce */
if(!s->budget--) { s->failed_pc=0x0c0668ceu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668d0;
P_0c0668d0: /* original e07c, guest PC 0x0c0668d0 */
if(!s->budget--) { s->failed_pc=0x0c0668d0u; return 0; }
r[0]=0x0000007cu;
goto P_0c0668d2;
P_0c0668d2: /* original 0fe6, guest PC 0x0c0668d2 */
if(!s->budget--) { s->failed_pc=0x0c0668d2u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668d4;
P_0c0668d4: /* original 9041, guest PC 0x0c0668d4 */
if(!s->budget--) { s->failed_pc=0x0c0668d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06695au,2);
goto P_0c0668d6;
P_0c0668d6: /* original 03fe, guest PC 0x0c0668d6 */
if(!s->budget--) { s->failed_pc=0x0c0668d6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0668d8;
P_0c0668d8: /* original 9040, guest PC 0x0c0668d8 */
if(!s->budget--) { s->failed_pc=0x0c0668d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06695cu,2);
goto P_0c0668da;
P_0c0668da: /* original 0f36, guest PC 0x0c0668da */
if(!s->budget--) { s->failed_pc=0x0c0668dau; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0668dc;
P_0c0668dc: /* original 9033, guest PC 0x0c0668dc */
if(!s->budget--) { s->failed_pc=0x0c0668dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066946u,2);
goto P_0c0668de;
P_0c0668de: /* original 02fe, guest PC 0x0c0668de */
if(!s->budget--) { s->failed_pc=0x0c0668deu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0668e0;
P_0c0668e0: /* original 903d, guest PC 0x0c0668e0 */
if(!s->budget--) { s->failed_pc=0x0c0668e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06695eu,2);
goto P_0c0668e2;
P_0c0668e2: /* original 0f26, guest PC 0x0c0668e2 */
if(!s->budget--) { s->failed_pc=0x0c0668e2u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0668e4;
P_0c0668e4: /* original 903c, guest PC 0x0c0668e4 */
if(!s->budget--) { s->failed_pc=0x0c0668e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066960u,2);
goto P_0c0668e6;
P_0c0668e6: /* original 0fe6, guest PC 0x0c0668e6 */
if(!s->budget--) { s->failed_pc=0x0c0668e6u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668e8;
P_0c0668e8: /* original 9037, guest PC 0x0c0668e8 */
if(!s->budget--) { s->failed_pc=0x0c0668e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06695au,2);
goto P_0c0668ea;
P_0c0668ea: /* original 0fe6, guest PC 0x0c0668ea */
if(!s->budget--) { s->failed_pc=0x0c0668eau; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668ec;
P_0c0668ec: /* original 902b, guest PC 0x0c0668ec */
if(!s->budget--) { s->failed_pc=0x0c0668ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066946u,2);
goto P_0c0668ee;
P_0c0668ee: /* original 0fe6, guest PC 0x0c0668ee */
if(!s->budget--) { s->failed_pc=0x0c0668eeu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668f0;
P_0c0668f0: /* original e060, guest PC 0x0c0668f0 */
if(!s->budget--) { s->failed_pc=0x0c0668f0u; return 0; }
r[0]=0x00000060u;
goto P_0c0668f2;
P_0c0668f2: /* original 0fe6, guest PC 0x0c0668f2 */
if(!s->budget--) { s->failed_pc=0x0c0668f2u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668f4;
P_0c0668f4: /* original 9529, guest PC 0x0c0668f4 */
if(!s->budget--) { s->failed_pc=0x0c0668f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694au,2);
goto P_0c0668f6;
P_0c0668f6: /* original e064, guest PC 0x0c0668f6 */
if(!s->budget--) { s->failed_pc=0x0c0668f6u; return 0; }
r[0]=0x00000064u;
goto P_0c0668f8;
P_0c0668f8: /* original 0fe6, guest PC 0x0c0668f8 */
if(!s->budget--) { s->failed_pc=0x0c0668f8u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0668fa;
P_0c0668fa: /* original 63d3, guest PC 0x0c0668fa */
if(!s->budget--) { s->failed_pc=0x0c0668fau; return 0; }
r[3]=r[13];
goto P_0c0668fc;
P_0c0668fc: /* original e068, guest PC 0x0c0668fc */
if(!s->budget--) { s->failed_pc=0x0c0668fcu; return 0; }
r[0]=0x00000068u;
goto P_0c0668fe;
P_0c0668fe: /* original 62d3, guest PC 0x0c0668fe */
if(!s->budget--) { s->failed_pc=0x0c0668feu; return 0; }
r[2]=r[13];
goto P_0c066900;
P_0c066900: /* original 0fe6, guest PC 0x0c066900 */
if(!s->budget--) { s->failed_pc=0x0c066900u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c066902;
P_0c066902: /* original 4300, guest PC 0x0c066902 */
if(!s->budget--) { s->failed_pc=0x0c066902u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c066904;
P_0c066904: /* original e06c, guest PC 0x0c066904 */
if(!s->budget--) { s->failed_pc=0x0c066904u; return 0; }
r[0]=0x0000006cu;
goto P_0c066906;
P_0c066906: /* original 332c, guest PC 0x0c066906 */
if(!s->budget--) { s->failed_pc=0x0c066906u; return 0; }
r[3]+=r[2];
goto P_0c066908;
P_0c066908: /* original 0fe6, guest PC 0x0c066908 */
if(!s->budget--) { s->failed_pc=0x0c066908u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c06690a;
P_0c06690a: /* original e618, guest PC 0x0c06690a */
if(!s->budget--) { s->failed_pc=0x0c06690au; return 0; }
r[6]=0x00000018u;
goto P_0c06690c;
P_0c06690c: /* original e070, guest PC 0x0c06690c */
if(!s->budget--) { s->failed_pc=0x0c06690cu; return 0; }
r[0]=0x00000070u;
goto P_0c06690e;
P_0c06690e: /* original 4308, guest PC 0x0c06690e */
if(!s->budget--) { s->failed_pc=0x0c06690eu; return 0; }
r[3]<<=2;
goto P_0c066910;
P_0c066910: /* original 0fe6, guest PC 0x0c066910 */
if(!s->budget--) { s->failed_pc=0x0c066910u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c066912;
P_0c066912: /* original 35fc, guest PC 0x0c066912 */
if(!s->budget--) { s->failed_pc=0x0c066912u; return 0; }
r[5]+=r[15];
goto P_0c066914;
P_0c066914: /* original 51f3, guest PC 0x0c066914 */
if(!s->budget--) { s->failed_pc=0x0c066914u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c066916;
P_0c066916: /* original 4308, guest PC 0x0c066916 */
if(!s->budget--) { s->failed_pc=0x0c066916u; return 0; }
r[3]<<=2;
goto P_0c066918;
P_0c066918: /* original 4300, guest PC 0x0c066918 */
if(!s->budget--) { s->failed_pc=0x0c066918u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06691a;
P_0c06691a: /* original 331c, guest PC 0x0c06691a */
if(!s->budget--) { s->failed_pc=0x0c06691au; return 0; }
r[3]+=r[1];
goto P_0c06691c;
P_0c06691c: /* original 2f32, guest PC 0x0c06691c */
if(!s->budget--) { s->failed_pc=0x0c06691cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06691e;
P_0c06691e: /* original 4c0b, guest PC 0x0c06691e */
if(!s->budget--) { s->failed_pc=0x0c06691eu; return 0; }
target=r[12];
r[16]=code_base|0x0c066922u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066922u) { target=s->pc; goto dispatch; }
goto P_0c066922;
P_0c066920: /* original 6433, guest PC 0x0c066920 */
if(!s->budget--) { s->failed_pc=0x0c066920u; return 0; }
r[4]=r[3];
goto P_0c066922;
P_0c066922: /* original e618, guest PC 0x0c066922 */
if(!s->budget--) { s->failed_pc=0x0c066922u; return 0; }
r[6]=0x00000018u;
goto P_0c066924;
P_0c066924: /* original 9512, guest PC 0x0c066924 */
if(!s->budget--) { s->failed_pc=0x0c066924u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06694cu,2);
goto P_0c066926;
P_0c066926: /* original 35fc, guest PC 0x0c066926 */
if(!s->budget--) { s->failed_pc=0x0c066926u; return 0; }
r[5]+=r[15];
goto P_0c066928;
P_0c066928: /* original 64f2, guest PC 0x0c066928 */
if(!s->budget--) { s->failed_pc=0x0c066928u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06692a;
P_0c06692a: /* original 4c0b, guest PC 0x0c06692a */
if(!s->budget--) { s->failed_pc=0x0c06692au; return 0; }
target=r[12];
r[16]=code_base|0x0c06692eu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06692eu) { target=s->pc; goto dispatch; }
goto P_0c06692e;
P_0c06692c: /* original 7418, guest PC 0x0c06692c */
if(!s->budget--) { s->failed_pc=0x0c06692cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06692e;
P_0c06692e: /* original e618, guest PC 0x0c06692e */
if(!s->budget--) { s->failed_pc=0x0c06692eu; return 0; }
r[6]=0x00000018u;
goto P_0c066930;
P_0c066930: /* original 64f2, guest PC 0x0c066930 */
if(!s->budget--) { s->failed_pc=0x0c066930u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c066932;
P_0c066932: /* original 65f3, guest PC 0x0c066932 */
if(!s->budget--) { s->failed_pc=0x0c066932u; return 0; }
r[5]=r[15];
goto P_0c066934;
P_0c066934: /* original 7574, guest PC 0x0c066934 */
if(!s->budget--) { s->failed_pc=0x0c066934u; return 0; }
r[5]+=0x00000074u;
goto P_0c066936;
P_0c066936: /* original 4c0b, guest PC 0x0c066936 */
if(!s->budget--) { s->failed_pc=0x0c066936u; return 0; }
target=r[12];
r[16]=code_base|0x0c06693au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06693au) { target=s->pc; goto dispatch; }
goto P_0c06693a;
P_0c066938: /* original 7430, guest PC 0x0c066938 */
if(!s->budget--) { s->failed_pc=0x0c066938u; return 0; }
r[4]+=0x00000030u;
goto P_0c06693a;
P_0c06693a: /* original e618, guest PC 0x0c06693a */
if(!s->budget--) { s->failed_pc=0x0c06693au; return 0; }
r[6]=0x00000018u;
goto P_0c06693c;
P_0c06693c: /* original 64f2, guest PC 0x0c06693c */
if(!s->budget--) { s->failed_pc=0x0c06693cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06693e;
P_0c06693e: /* original 65f3, guest PC 0x0c06693e */
if(!s->budget--) { s->failed_pc=0x0c06693eu; return 0; }
r[5]=r[15];
goto P_0c066940;
P_0c066940: /* original 755c, guest PC 0x0c066940 */
if(!s->budget--) { s->failed_pc=0x0c066940u; return 0; }
r[5]+=0x0000005cu;
goto P_0c066942;
P_0c066942: /* original a052, guest PC 0x0c066942 */
if(!s->budget--) { s->failed_pc=0x0c066942u; return 0; }
r[4]+=0x00000048u;
goto P_0c0669ea;
P_0c066944: /* original 7448, guest PC 0x0c066944 */
if(!s->budget--) { s->failed_pc=0x0c066944u; return 0; }
r[4]+=0x00000048u;
if(!vf3_matrix_family(0x0c066946u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066946u; return 0; } return 1;
P_0c066978: /* original 9087, guest PC 0x0c066978 */
if(!s->budget--) { s->failed_pc=0x0c066978u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c06697a;
P_0c06697a: /* original 0f46, guest PC 0x0c06697a */
if(!s->budget--) { s->failed_pc=0x0c06697au; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c06697c;
P_0c06697c: /* original 9086, guest PC 0x0c06697c */
if(!s->budget--) { s->failed_pc=0x0c06697cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c06697e;
P_0c06697e: /* original 02fe, guest PC 0x0c06697e */
if(!s->budget--) { s->failed_pc=0x0c06697eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c066980;
P_0c066980: /* original 9084, guest PC 0x0c066980 */
if(!s->budget--) { s->failed_pc=0x0c066980u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c066982;
P_0c066982: /* original 22a9, guest PC 0x0c066982 */
if(!s->budget--) { s->failed_pc=0x0c066982u; return 0; }
r[2]&=r[10];
goto P_0c066984;
P_0c066984: /* original 9181, guest PC 0x0c066984 */
if(!s->budget--) { s->failed_pc=0x0c066984u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c066986;
P_0c066986: /* original 0f26, guest PC 0x0c066986 */
if(!s->budget--) { s->failed_pc=0x0c066986u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c066988;
P_0c066988: /* original d244, guest PC 0x0c066988 */
if(!s->budget--) { s->failed_pc=0x0c066988u; return 0; }
r[2]=read(ram,0x0c066a9cu,4);
goto P_0c06698a;
P_0c06698a: /* original 31fc, guest PC 0x0c06698a */
if(!s->budget--) { s->failed_pc=0x0c06698au; return 0; }
r[1]+=r[15];
goto P_0c06698c;
P_0c06698c: /* original 907e, guest PC 0x0c06698c */
if(!s->budget--) { s->failed_pc=0x0c06698cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c06698e;
P_0c06698e: /* original 00fe, guest PC 0x0c06698e */
if(!s->budget--) { s->failed_pc=0x0c06698eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c066990;
P_0c066990: /* original 2029, guest PC 0x0c066990 */
if(!s->budget--) { s->failed_pc=0x0c066990u; return 0; }
r[0]&=r[2];
goto P_0c066992;
P_0c066992: /* original 6303, guest PC 0x0c066992 */
if(!s->budget--) { s->failed_pc=0x0c066992u; return 0; }
r[3]=r[0];
goto P_0c066994;
P_0c066994: /* original 907a, guest PC 0x0c066994 */
if(!s->budget--) { s->failed_pc=0x0c066994u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c066996;
P_0c066996: /* original 23bb, guest PC 0x0c066996 */
if(!s->budget--) { s->failed_pc=0x0c066996u; return 0; }
r[3]|=r[11];
goto P_0c066998;
P_0c066998: /* original 0f36, guest PC 0x0c066998 */
if(!s->budget--) { s->failed_pc=0x0c066998u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c06699a;
P_0c06699a: /* original 9076, guest PC 0x0c06699a */
if(!s->budget--) { s->failed_pc=0x0c06699au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c06699c;
P_0c06699c: /* original 03fe, guest PC 0x0c06699c */
if(!s->budget--) { s->failed_pc=0x0c06699cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06699e;
P_0c06699e: /* original 239b, guest PC 0x0c06699e */
if(!s->budget--) { s->failed_pc=0x0c06699eu; return 0; }
r[3]|=r[9];
goto P_0c0669a0;
P_0c0669a0: /* original 9073, guest PC 0x0c0669a0 */
if(!s->budget--) { s->failed_pc=0x0c0669a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c0669a2;
P_0c0669a2: /* original 0f36, guest PC 0x0c0669a2 */
if(!s->budget--) { s->failed_pc=0x0c0669a2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0669a4;
P_0c0669a4: /* original d33e, guest PC 0x0c0669a4 */
if(!s->budget--) { s->failed_pc=0x0c0669a4u; return 0; }
r[3]=read(ram,0x0c066aa0u,4);
goto P_0c0669a6;
P_0c0669a6: /* original 9070, guest PC 0x0c0669a6 */
if(!s->budget--) { s->failed_pc=0x0c0669a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c0669a8;
P_0c0669a8: /* original 00fe, guest PC 0x0c0669a8 */
if(!s->budget--) { s->failed_pc=0x0c0669a8u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0669aa;
P_0c0669aa: /* original 2039, guest PC 0x0c0669aa */
if(!s->budget--) { s->failed_pc=0x0c0669aau; return 0; }
r[0]&=r[3];
goto P_0c0669ac;
P_0c0669ac: /* original 2102, guest PC 0x0c0669ac */
if(!s->budget--) { s->failed_pc=0x0c0669acu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0669ae;
P_0c0669ae: /* original 906e, guest PC 0x0c0669ae */
if(!s->budget--) { s->failed_pc=0x0c0669aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8eu,2);
goto P_0c0669b0;
P_0c0669b0: /* original 0fe6, guest PC 0x0c0669b0 */
if(!s->budget--) { s->failed_pc=0x0c0669b0u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0669b2;
P_0c0669b2: /* original 906d, guest PC 0x0c0669b2 */
if(!s->budget--) { s->failed_pc=0x0c0669b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a90u,2);
goto P_0c0669b4;
P_0c0669b4: /* original 0fe6, guest PC 0x0c0669b4 */
if(!s->budget--) { s->failed_pc=0x0c0669b4u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0669b6;
P_0c0669b6: /* original 61d3, guest PC 0x0c0669b6 */
if(!s->budget--) { s->failed_pc=0x0c0669b6u; return 0; }
r[1]=r[13];
goto P_0c0669b8;
P_0c0669b8: /* original 906b, guest PC 0x0c0669b8 */
if(!s->budget--) { s->failed_pc=0x0c0669b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a92u,2);
goto P_0c0669ba;
P_0c0669ba: /* original 0fe6, guest PC 0x0c0669ba */
if(!s->budget--) { s->failed_pc=0x0c0669bau; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0669bc;
P_0c0669bc: /* original 906a, guest PC 0x0c0669bc */
if(!s->budget--) { s->failed_pc=0x0c0669bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a94u,2);
goto P_0c0669be;
P_0c0669be: /* original 0fe6, guest PC 0x0c0669be */
if(!s->budget--) { s->failed_pc=0x0c0669beu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0669c0;
P_0c0669c0: /* original 9069, guest PC 0x0c0669c0 */
if(!s->budget--) { s->failed_pc=0x0c0669c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a96u,2);
goto P_0c0669c2;
P_0c0669c2: /* original 0fe6, guest PC 0x0c0669c2 */
if(!s->budget--) { s->failed_pc=0x0c0669c2u; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c0669c4;
P_0c0669c4: /* original 60d3, guest PC 0x0c0669c4 */
if(!s->budget--) { s->failed_pc=0x0c0669c4u; return 0; }
r[0]=r[13];
goto P_0c0669c6;
P_0c0669c6: /* original 0009, guest PC 0x0c0669c6 */
if(!s->budget--) { s->failed_pc=0x0c0669c6u; return 0; }
goto P_0c0669c8;
P_0c0669c8: /* original 9560, guest PC 0x0c0669c8 */
if(!s->budget--) { s->failed_pc=0x0c0669c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c0669ca;
P_0c0669ca: /* original 4100, guest PC 0x0c0669ca */
if(!s->budget--) { s->failed_pc=0x0c0669cau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0669cc;
P_0c0669cc: /* original 310c, guest PC 0x0c0669cc */
if(!s->budget--) { s->failed_pc=0x0c0669ccu; return 0; }
r[1]+=r[0];
goto P_0c0669ce;
P_0c0669ce: /* original 4108, guest PC 0x0c0669ce */
if(!s->budget--) { s->failed_pc=0x0c0669ceu; return 0; }
r[1]<<=2;
goto P_0c0669d0;
P_0c0669d0: /* original 50f3, guest PC 0x0c0669d0 */
if(!s->budget--) { s->failed_pc=0x0c0669d0u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0669d2;
P_0c0669d2: /* original e618, guest PC 0x0c0669d2 */
if(!s->budget--) { s->failed_pc=0x0c0669d2u; return 0; }
r[6]=0x00000018u;
goto P_0c0669d4;
P_0c0669d4: /* original 4108, guest PC 0x0c0669d4 */
if(!s->budget--) { s->failed_pc=0x0c0669d4u; return 0; }
r[1]<<=2;
goto P_0c0669d6;
P_0c0669d6: /* original 310c, guest PC 0x0c0669d6 */
if(!s->budget--) { s->failed_pc=0x0c0669d6u; return 0; }
r[1]+=r[0];
goto P_0c0669d8;
P_0c0669d8: /* original 2f12, guest PC 0x0c0669d8 */
if(!s->budget--) { s->failed_pc=0x0c0669d8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0669da;
P_0c0669da: /* original 35fc, guest PC 0x0c0669da */
if(!s->budget--) { s->failed_pc=0x0c0669dau; return 0; }
r[5]+=r[15];
goto P_0c0669dc;
P_0c0669dc: /* original 4c0b, guest PC 0x0c0669dc */
if(!s->budget--) { s->failed_pc=0x0c0669dcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0669e0u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0669e0u) { target=s->pc; goto dispatch; }
goto P_0c0669e0;
P_0c0669de: /* original 6413, guest PC 0x0c0669de */
if(!s->budget--) { s->failed_pc=0x0c0669deu; return 0; }
r[4]=r[1];
goto P_0c0669e0;
P_0c0669e0: /* original 9553, guest PC 0x0c0669e0 */
if(!s->budget--) { s->failed_pc=0x0c0669e0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8au,2);
goto P_0c0669e2;
P_0c0669e2: /* original e618, guest PC 0x0c0669e2 */
if(!s->budget--) { s->failed_pc=0x0c0669e2u; return 0; }
r[6]=0x00000018u;
goto P_0c0669e4;
P_0c0669e4: /* original 64f2, guest PC 0x0c0669e4 */
if(!s->budget--) { s->failed_pc=0x0c0669e4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0669e6;
P_0c0669e6: /* original 35fc, guest PC 0x0c0669e6 */
if(!s->budget--) { s->failed_pc=0x0c0669e6u; return 0; }
r[5]+=r[15];
goto P_0c0669e8;
P_0c0669e8: /* original 7418, guest PC 0x0c0669e8 */
if(!s->budget--) { s->failed_pc=0x0c0669e8u; return 0; }
r[4]+=0x00000018u;
goto P_0c0669ea;
P_0c0669ea: /* original 4c0b, guest PC 0x0c0669ea */
if(!s->budget--) { s->failed_pc=0x0c0669eau; return 0; }
target=r[12];
r[16]=code_base|0x0c0669eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0669eeu) { target=s->pc; goto dispatch; }
goto P_0c0669ee;
P_0c0669ec: /* original 0009, guest PC 0x0c0669ec */
if(!s->budget--) { s->failed_pc=0x0c0669ecu; return 0; }
goto P_0c0669ee;
P_0c0669ee: /* original a00c, guest PC 0x0c0669ee */
if(!s->budget--) { s->failed_pc=0x0c0669eeu; return 0; }
goto P_0c066a0a;
P_0c0669f0: /* original 0009, guest PC 0x0c0669f0 */
if(!s->budget--) { s->failed_pc=0x0c0669f0u; return 0; }
goto P_0c0669f2;
P_0c0669f2: /* original 64d3, guest PC 0x0c0669f2 */
if(!s->budget--) { s->failed_pc=0x0c0669f2u; return 0; }
r[4]=r[13];
goto P_0c0669f4;
P_0c0669f4: /* original 51f3, guest PC 0x0c0669f4 */
if(!s->budget--) { s->failed_pc=0x0c0669f4u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0669f6;
P_0c0669f6: /* original e618, guest PC 0x0c0669f6 */
if(!s->budget--) { s->failed_pc=0x0c0669f6u; return 0; }
r[6]=0x00000018u;
goto P_0c0669f8;
P_0c0669f8: /* original 9548, guest PC 0x0c0669f8 */
if(!s->budget--) { s->failed_pc=0x0c0669f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a8cu,2);
goto P_0c0669fa;
P_0c0669fa: /* original 62d3, guest PC 0x0c0669fa */
if(!s->budget--) { s->failed_pc=0x0c0669fau; return 0; }
r[2]=r[13];
goto P_0c0669fc;
P_0c0669fc: /* original 4400, guest PC 0x0c0669fc */
if(!s->budget--) { s->failed_pc=0x0c0669fcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0669fe;
P_0c0669fe: /* original 342c, guest PC 0x0c0669fe */
if(!s->budget--) { s->failed_pc=0x0c0669feu; return 0; }
r[4]+=r[2];
goto P_0c066a00;
P_0c066a00: /* original 4408, guest PC 0x0c066a00 */
if(!s->budget--) { s->failed_pc=0x0c066a00u; return 0; }
r[4]<<=2;
goto P_0c066a02;
P_0c066a02: /* original 4400, guest PC 0x0c066a02 */
if(!s->budget--) { s->failed_pc=0x0c066a02u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c066a04;
P_0c066a04: /* original 341c, guest PC 0x0c066a04 */
if(!s->budget--) { s->failed_pc=0x0c066a04u; return 0; }
r[4]+=r[1];
goto P_0c066a06;
P_0c066a06: /* original 4c0b, guest PC 0x0c066a06 */
if(!s->budget--) { s->failed_pc=0x0c066a06u; return 0; }
target=r[12];
r[16]=code_base|0x0c066a0au;
r[5]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066a0au) { target=s->pc; goto dispatch; }
goto P_0c066a0a;
P_0c066a08: /* original 35fc, guest PC 0x0c066a08 */
if(!s->budget--) { s->failed_pc=0x0c066a08u; return 0; }
r[5]+=r[15];
goto P_0c066a0a;
P_0c066a0a: /* original 7d01, guest PC 0x0c066a0a */
if(!s->budget--) { s->failed_pc=0x0c066a0au; return 0; }
r[13]+=0x00000001u;
goto P_0c066a0c;
P_0c066a0c: /* original 53f2, guest PC 0x0c066a0c */
if(!s->budget--) { s->failed_pc=0x0c066a0cu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c066a0e;
P_0c066a0e: /* original 3d32, guest PC 0x0c066a0e */
if(!s->budget--) { s->failed_pc=0x0c066a0eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[3])!=0);
goto P_0c066a10;
P_0c066a10: /* original 8901, guest PC 0x0c066a10 */
if(!s->budget--) { s->failed_pc=0x0c066a10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066a16; }
goto P_0c066a12;
P_0c066a12: /* original ae35, guest PC 0x0c066a12 */
if(!s->budget--) { s->failed_pc=0x0c066a12u; return 0; }
goto P_0c066680;
P_0c066a14: /* original 0009, guest PC 0x0c066a14 */
if(!s->budget--) { s->failed_pc=0x0c066a14u; return 0; }
goto P_0c066a16;
P_0c066a16: /* original 913f, guest PC 0x0c066a16 */
if(!s->budget--) { s->failed_pc=0x0c066a16u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066a98u,2);
goto P_0c066a18;
P_0c066a18: /* original 3f1c, guest PC 0x0c066a18 */
if(!s->budget--) { s->failed_pc=0x0c066a18u; return 0; }
r[15]+=r[1];
goto P_0c066a1a;
P_0c066a1a: /* original 4f26, guest PC 0x0c066a1a */
if(!s->budget--) { s->failed_pc=0x0c066a1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066a1c;
P_0c066a1c: /* original 68f6, guest PC 0x0c066a1c */
if(!s->budget--) { s->failed_pc=0x0c066a1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c066a1e;
P_0c066a1e: /* original 69f6, guest PC 0x0c066a1e */
if(!s->budget--) { s->failed_pc=0x0c066a1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066a20;
P_0c066a20: /* original 6af6, guest PC 0x0c066a20 */
if(!s->budget--) { s->failed_pc=0x0c066a20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066a22;
P_0c066a22: /* original 6bf6, guest PC 0x0c066a22 */
if(!s->budget--) { s->failed_pc=0x0c066a22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066a24;
P_0c066a24: /* original 6cf6, guest PC 0x0c066a24 */
if(!s->budget--) { s->failed_pc=0x0c066a24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066a26;
P_0c066a26: /* original 6df6, guest PC 0x0c066a26 */
if(!s->budget--) { s->failed_pc=0x0c066a26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066a28;
P_0c066a28: /* original 000b, guest PC 0x0c066a28 */
if(!s->budget--) { s->failed_pc=0x0c066a28u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066a2a: /* original 6ef6, guest PC 0x0c066a2a */
if(!s->budget--) { s->failed_pc=0x0c066a2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066a2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066a2cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
