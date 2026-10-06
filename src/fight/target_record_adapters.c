/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_target_record_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0370fcu: goto P_0c0370fc;
case 0x0c0370feu: goto P_0c0370fe;
case 0x0c037100u: goto P_0c037100;
case 0x0c037102u: goto P_0c037102;
case 0x0c037104u: goto P_0c037104;
case 0x0c037106u: goto P_0c037106;
case 0x0c037108u: goto P_0c037108;
case 0x0c03710au: goto P_0c03710a;
case 0x0c03710cu: goto P_0c03710c;
case 0x0c03710eu: goto P_0c03710e;
case 0x0c037110u: goto P_0c037110;
case 0x0c037112u: goto P_0c037112;
case 0x0c037114u: goto P_0c037114;
case 0x0c037116u: goto P_0c037116;
case 0x0c037118u: goto P_0c037118;
case 0x0c03711au: goto P_0c03711a;
case 0x0c03711cu: goto P_0c03711c;
case 0x0c03711eu: goto P_0c03711e;
case 0x0c037120u: goto P_0c037120;
case 0x0c037122u: goto P_0c037122;
case 0x0c037124u: goto P_0c037124;
case 0x0c037126u: goto P_0c037126;
case 0x0c037128u: goto P_0c037128;
case 0x0c03712au: goto P_0c03712a;
case 0x0c03712cu: goto P_0c03712c;
case 0x0c03712eu: goto P_0c03712e;
case 0x0c037130u: goto P_0c037130;
case 0x0c037132u: goto P_0c037132;
case 0x0c037134u: goto P_0c037134;
case 0x0c037136u: goto P_0c037136;
case 0x0c037138u: goto P_0c037138;
case 0x0c03713au: goto P_0c03713a;
case 0x0c03713cu: goto P_0c03713c;
case 0x0c03713eu: goto P_0c03713e;
case 0x0c037140u: goto P_0c037140;
case 0x0c037142u: goto P_0c037142;
case 0x0c037144u: goto P_0c037144;
case 0x0c037146u: goto P_0c037146;
case 0x0c037148u: goto P_0c037148;
case 0x0c03714au: goto P_0c03714a;
case 0x0c03714cu: goto P_0c03714c;
case 0x0c03714eu: goto P_0c03714e;
case 0x0c037150u: goto P_0c037150;
case 0x0c037152u: goto P_0c037152;
case 0x0c037154u: goto P_0c037154;
case 0x0c037156u: goto P_0c037156;
case 0x0c037158u: goto P_0c037158;
case 0x0c03715au: goto P_0c03715a;
case 0x0c03715cu: goto P_0c03715c;
case 0x0c03715eu: goto P_0c03715e;
case 0x0c037160u: goto P_0c037160;
case 0x0c037162u: goto P_0c037162;
case 0x0c037164u: goto P_0c037164;
case 0x0c037166u: goto P_0c037166;
case 0x0c037168u: goto P_0c037168;
case 0x0c03716au: goto P_0c03716a;
case 0x0c03716cu: goto P_0c03716c;
case 0x0c03716eu: goto P_0c03716e;
case 0x0c037170u: goto P_0c037170;
case 0x0c037172u: goto P_0c037172;
case 0x0c037174u: goto P_0c037174;
case 0x0c037176u: goto P_0c037176;
case 0x0c037178u: goto P_0c037178;
case 0x0c03717au: goto P_0c03717a;
case 0x0c03717cu: goto P_0c03717c;
case 0x0c03717eu: goto P_0c03717e;
case 0x0c037180u: goto P_0c037180;
case 0x0c037182u: goto P_0c037182;
case 0x0c037184u: goto P_0c037184;
case 0x0c037186u: goto P_0c037186;
case 0x0c037188u: goto P_0c037188;
case 0x0c03718au: goto P_0c03718a;
case 0x0c03718cu: goto P_0c03718c;
case 0x0c03718eu: goto P_0c03718e;
case 0x0c037316u: goto P_0c037316;
case 0x0c037318u: goto P_0c037318;
case 0x0c03731au: goto P_0c03731a;
case 0x0c03731cu: goto P_0c03731c;
case 0x0c03731eu: goto P_0c03731e;
case 0x0c037320u: goto P_0c037320;
case 0x0c037322u: goto P_0c037322;
case 0x0c037324u: goto P_0c037324;
case 0x0c037326u: goto P_0c037326;
case 0x0c037328u: goto P_0c037328;
case 0x0c03732au: goto P_0c03732a;
case 0x0c03732cu: goto P_0c03732c;
case 0x0c03732eu: goto P_0c03732e;
case 0x0c037330u: goto P_0c037330;
case 0x0c037332u: goto P_0c037332;
case 0x0c037334u: goto P_0c037334;
case 0x0c037336u: goto P_0c037336;
case 0x0c037338u: goto P_0c037338;
case 0x0c03733au: goto P_0c03733a;
case 0x0c03733cu: goto P_0c03733c;
case 0x0c03733eu: goto P_0c03733e;
case 0x0c037340u: goto P_0c037340;
case 0x0c037342u: goto P_0c037342;
case 0x0c037344u: goto P_0c037344;
case 0x0c037346u: goto P_0c037346;
case 0x0c037348u: goto P_0c037348;
case 0x0c03734au: goto P_0c03734a;
case 0x0c03734cu: goto P_0c03734c;
case 0x0c03734eu: goto P_0c03734e;
case 0x0c037350u: goto P_0c037350;
case 0x0c0376e0u: goto P_0c0376e0;
case 0x0c0376e2u: goto P_0c0376e2;
case 0x0c0376e4u: goto P_0c0376e4;
case 0x0c0376e6u: goto P_0c0376e6;
case 0x0c0376e8u: goto P_0c0376e8;
case 0x0c0376eau: goto P_0c0376ea;
case 0x0c0376ecu: goto P_0c0376ec;
case 0x0c0376eeu: goto P_0c0376ee;
case 0x0c0376f0u: goto P_0c0376f0;
case 0x0c0376f2u: goto P_0c0376f2;
case 0x0c0376f4u: goto P_0c0376f4;
case 0x0c0376f6u: goto P_0c0376f6;
case 0x0c0376f8u: goto P_0c0376f8;
case 0x0c0376fau: goto P_0c0376fa;
case 0x0c0376fcu: goto P_0c0376fc;
case 0x0c0376feu: goto P_0c0376fe;
case 0x0c037700u: goto P_0c037700;
case 0x0c037702u: goto P_0c037702;
case 0x0c037704u: goto P_0c037704;
case 0x0c037706u: goto P_0c037706;
case 0x0c037708u: goto P_0c037708;
case 0x0c03770au: goto P_0c03770a;
case 0x0c03770cu: goto P_0c03770c;
case 0x0c03770eu: goto P_0c03770e;
case 0x0c037710u: goto P_0c037710;
case 0x0c037712u: goto P_0c037712;
case 0x0c037714u: goto P_0c037714;
case 0x0c037716u: goto P_0c037716;
case 0x0c037718u: goto P_0c037718;
case 0x0c03771au: goto P_0c03771a;
case 0x0c03771cu: goto P_0c03771c;
case 0x0c03771eu: goto P_0c03771e;
case 0x0c037720u: goto P_0c037720;
case 0x0c037722u: goto P_0c037722;
case 0x0c037724u: goto P_0c037724;
case 0x0c037726u: goto P_0c037726;
case 0x0c037728u: goto P_0c037728;
case 0x0c037788u: goto P_0c037788;
case 0x0c03778au: goto P_0c03778a;
case 0x0c03778cu: goto P_0c03778c;
case 0x0c044068u: goto P_0c044068;
case 0x0c04406au: goto P_0c04406a;
case 0x0c04406cu: goto P_0c04406c;
case 0x0c04406eu: goto P_0c04406e;
case 0x0c044070u: goto P_0c044070;
case 0x0c044072u: goto P_0c044072;
case 0x0c044074u: goto P_0c044074;
case 0x0c044076u: goto P_0c044076;
case 0x0c044078u: goto P_0c044078;
case 0x0c04407au: goto P_0c04407a;
case 0x0c04407cu: goto P_0c04407c;
case 0x0c04407eu: goto P_0c04407e;
case 0x0c044080u: goto P_0c044080;
case 0x0c044082u: goto P_0c044082;
case 0x0c044084u: goto P_0c044084;
case 0x0c044086u: goto P_0c044086;
case 0x0c044088u: goto P_0c044088;
case 0x0c04408au: goto P_0c04408a;
case 0x0c04408cu: goto P_0c04408c;
case 0x0c04408eu: goto P_0c04408e;
case 0x0c044090u: goto P_0c044090;
case 0x0c044092u: goto P_0c044092;
case 0x0c044094u: goto P_0c044094;
case 0x0c044096u: goto P_0c044096;
case 0x0c044098u: goto P_0c044098;
case 0x0c04409au: goto P_0c04409a;
case 0x0c045c2au: goto P_0c045c2a;
case 0x0c045c2cu: goto P_0c045c2c;
case 0x0c045c2eu: goto P_0c045c2e;
case 0x0c045c30u: goto P_0c045c30;
case 0x0c045c32u: goto P_0c045c32;
case 0x0c045c34u: goto P_0c045c34;
case 0x0c045c36u: goto P_0c045c36;
case 0x0c045c38u: goto P_0c045c38;
case 0x0c045c3au: goto P_0c045c3a;
case 0x0c045c3cu: goto P_0c045c3c;
case 0x0c045c3eu: goto P_0c045c3e;
case 0x0c045c40u: goto P_0c045c40;
case 0x0c045c42u: goto P_0c045c42;
case 0x0c045c44u: goto P_0c045c44;
case 0x0c045c46u: goto P_0c045c46;
case 0x0c045c48u: goto P_0c045c48;
case 0x0c045c4au: goto P_0c045c4a;
case 0x0c045c4cu: goto P_0c045c4c;
case 0x0c045c4eu: goto P_0c045c4e;
case 0x0c045c50u: goto P_0c045c50;
case 0x0c045c52u: goto P_0c045c52;
case 0x0c045c54u: goto P_0c045c54;
case 0x0c045c56u: goto P_0c045c56;
case 0x0c045c58u: goto P_0c045c58;
case 0x0c045c5au: goto P_0c045c5a;
case 0x0c045c5cu: goto P_0c045c5c;
case 0x0c045c5eu: goto P_0c045c5e;
case 0x0c045c60u: goto P_0c045c60;
case 0x0c045c62u: goto P_0c045c62;
case 0x0c045c80u: goto P_0c045c80;
case 0x0c045c82u: goto P_0c045c82;
case 0x0c04667au: goto P_0c04667a;
case 0x0c04667cu: goto P_0c04667c;
case 0x0c04667eu: goto P_0c04667e;
case 0x0c046680u: goto P_0c046680;
case 0x0c046682u: goto P_0c046682;
case 0x0c046684u: goto P_0c046684;
case 0x0c046686u: goto P_0c046686;
case 0x0c046688u: goto P_0c046688;
case 0x0c04668au: goto P_0c04668a;
case 0x0c04668cu: goto P_0c04668c;
case 0x0c04668eu: goto P_0c04668e;
case 0x0c046690u: goto P_0c046690;
case 0x0c046692u: goto P_0c046692;
case 0x0c046694u: goto P_0c046694;
case 0x0c046696u: goto P_0c046696;
case 0x0c046698u: goto P_0c046698;
case 0x0c04669au: goto P_0c04669a;
case 0x0c04669cu: goto P_0c04669c;
case 0x0c04669eu: goto P_0c04669e;
case 0x0c04708cu: goto P_0c04708c;
case 0x0c04708eu: goto P_0c04708e;
case 0x0c047090u: goto P_0c047090;
case 0x0c047092u: goto P_0c047092;
case 0x0c047094u: goto P_0c047094;
case 0x0c047096u: goto P_0c047096;
case 0x0c047098u: goto P_0c047098;
case 0x0c04709au: goto P_0c04709a;
case 0x0c04709cu: goto P_0c04709c;
case 0x0c04709eu: goto P_0c04709e;
case 0x0c0470a0u: goto P_0c0470a0;
case 0x0c0470a2u: goto P_0c0470a2;
case 0x0c0470a4u: goto P_0c0470a4;
case 0x0c0470a6u: goto P_0c0470a6;
case 0x0c0470a8u: goto P_0c0470a8;
case 0x0c0470aau: goto P_0c0470aa;
case 0x0c0470acu: goto P_0c0470ac;
case 0x0c0470aeu: goto P_0c0470ae;
case 0x0c0470b0u: goto P_0c0470b0;
case 0x0c0470b2u: goto P_0c0470b2;
case 0x0c0470b4u: goto P_0c0470b4;
case 0x0c0470b6u: goto P_0c0470b6;
case 0x0c0470b8u: goto P_0c0470b8;
case 0x0c0470bau: goto P_0c0470ba;
case 0x0c0470bcu: goto P_0c0470bc;
case 0x0c0470beu: goto P_0c0470be;
case 0x0c0470d8u: goto P_0c0470d8;
case 0x0c0470dau: goto P_0c0470da;
case 0x0c0470dcu: goto P_0c0470dc;
case 0x0c0470deu: goto P_0c0470de;
case 0x0c0470e0u: goto P_0c0470e0;
case 0x0c0470e2u: goto P_0c0470e2;
case 0x0c0470e4u: goto P_0c0470e4;
case 0x0c0470e6u: goto P_0c0470e6;
case 0x0c0470e8u: goto P_0c0470e8;
case 0x0c0470eau: goto P_0c0470ea;
case 0x0c0470ecu: goto P_0c0470ec;
case 0x0c0470eeu: goto P_0c0470ee;
case 0x0c0470f0u: goto P_0c0470f0;
case 0x0c0470f2u: goto P_0c0470f2;
case 0x0c0470f4u: goto P_0c0470f4;
case 0x0c0470f6u: goto P_0c0470f6;
case 0x0c0470f8u: goto P_0c0470f8;
case 0x0c0470fau: goto P_0c0470fa;
case 0x0c0470fcu: goto P_0c0470fc;
case 0x0c0470feu: goto P_0c0470fe;
case 0x0c047100u: goto P_0c047100;
case 0x0c047102u: goto P_0c047102;
case 0x0c047104u: goto P_0c047104;
case 0x0c047106u: goto P_0c047106;
case 0x0c047108u: goto P_0c047108;
case 0x0c04710au: goto P_0c04710a;
case 0x0c04710cu: goto P_0c04710c;
case 0x0c04710eu: goto P_0c04710e;
case 0x0c047110u: goto P_0c047110;
case 0x0c047112u: goto P_0c047112;
case 0x0c047114u: goto P_0c047114;
case 0x0c047116u: goto P_0c047116;
case 0x0c047118u: goto P_0c047118;
case 0x0c04711au: goto P_0c04711a;
case 0x0c04711cu: goto P_0c04711c;
case 0x0c04711eu: goto P_0c04711e;
case 0x0c047120u: goto P_0c047120;
case 0x0c047122u: goto P_0c047122;
case 0x0c047124u: goto P_0c047124;
case 0x0c047126u: goto P_0c047126;
case 0x0c047128u: goto P_0c047128;
case 0x0c04712au: goto P_0c04712a;
case 0x0c04712cu: goto P_0c04712c;
case 0x0c04712eu: goto P_0c04712e;
case 0x0c047130u: goto P_0c047130;
case 0x0c047132u: goto P_0c047132;
case 0x0c047134u: goto P_0c047134;
case 0x0c047136u: goto P_0c047136;
case 0x0c047138u: goto P_0c047138;
case 0x0c04713au: goto P_0c04713a;
case 0x0c04713cu: goto P_0c04713c;
case 0x0c04713eu: goto P_0c04713e;
case 0x0c047140u: goto P_0c047140;
case 0x0c047142u: goto P_0c047142;
case 0x0c047144u: goto P_0c047144;
case 0x0c047146u: goto P_0c047146;
case 0x0c047148u: goto P_0c047148;
case 0x0c04714au: goto P_0c04714a;
case 0x0c04714cu: goto P_0c04714c;
case 0x0c04714eu: goto P_0c04714e;
case 0x0c047150u: goto P_0c047150;
case 0x0c047152u: goto P_0c047152;
case 0x0c047154u: goto P_0c047154;
case 0x0c047156u: goto P_0c047156;
case 0x0c047158u: goto P_0c047158;
case 0x0c04715au: goto P_0c04715a;
case 0x0c04715cu: goto P_0c04715c;
case 0x0c04715eu: goto P_0c04715e;
case 0x0c047160u: goto P_0c047160;
case 0x0c047162u: goto P_0c047162;
case 0x0c047164u: goto P_0c047164;
case 0x0c047166u: goto P_0c047166;
case 0x0c047168u: goto P_0c047168;
case 0x0c04716au: goto P_0c04716a;
case 0x0c04716cu: goto P_0c04716c;
case 0x0c04716eu: goto P_0c04716e;
case 0x0c047170u: goto P_0c047170;
case 0x0c047172u: goto P_0c047172;
case 0x0c047174u: goto P_0c047174;
case 0x0c047176u: goto P_0c047176;
case 0x0c047178u: goto P_0c047178;
case 0x0c04717au: goto P_0c04717a;
case 0x0c04717cu: goto P_0c04717c;
case 0x0c04717eu: goto P_0c04717e;
case 0x0c047180u: goto P_0c047180;
case 0x0c047182u: goto P_0c047182;
case 0x0c047184u: goto P_0c047184;
case 0x0c047186u: goto P_0c047186;
case 0x0c047188u: goto P_0c047188;
case 0x0c04718au: goto P_0c04718a;
case 0x0c04718cu: goto P_0c04718c;
case 0x0c04718eu: goto P_0c04718e;
case 0x0c047190u: goto P_0c047190;
case 0x0c047192u: goto P_0c047192;
case 0x0c047194u: goto P_0c047194;
case 0x0c047196u: goto P_0c047196;
case 0x0c047198u: goto P_0c047198;
case 0x0c04719au: goto P_0c04719a;
case 0x0c04719cu: goto P_0c04719c;
case 0x0c04719eu: goto P_0c04719e;
case 0x0c0471a0u: goto P_0c0471a0;
case 0x0c0471a2u: goto P_0c0471a2;
case 0x0c0471a4u: goto P_0c0471a4;
case 0x0c0471a6u: goto P_0c0471a6;
case 0x0c0471a8u: goto P_0c0471a8;
case 0x0c0471aau: goto P_0c0471aa;
case 0x0c0471acu: goto P_0c0471ac;
case 0x0c0471aeu: goto P_0c0471ae;
case 0x0c0471b0u: goto P_0c0471b0;
case 0x0c0471b2u: goto P_0c0471b2;
case 0x0c0471b4u: goto P_0c0471b4;
case 0x0c0471b6u: goto P_0c0471b6;
case 0x0c0471b8u: goto P_0c0471b8;
case 0x0c0471bau: goto P_0c0471ba;
case 0x0c0471bcu: goto P_0c0471bc;
case 0x0c0471beu: goto P_0c0471be;
case 0x0c0471c0u: goto P_0c0471c0;
case 0x0c0471c2u: goto P_0c0471c2;
case 0x0c0471c4u: goto P_0c0471c4;
case 0x0c0471c6u: goto P_0c0471c6;
case 0x0c0471c8u: goto P_0c0471c8;
case 0x0c0471cau: goto P_0c0471ca;
case 0x0c0471ccu: goto P_0c0471cc;
case 0x0c0471ceu: goto P_0c0471ce;
case 0x0c0471d0u: goto P_0c0471d0;
case 0x0c0471d2u: goto P_0c0471d2;
case 0x0c0471d4u: goto P_0c0471d4;
case 0x0c0471d6u: goto P_0c0471d6;
case 0x0c0471d8u: goto P_0c0471d8;
case 0x0c0471dau: goto P_0c0471da;
case 0x0c0471dcu: goto P_0c0471dc;
case 0x0c0471deu: goto P_0c0471de;
case 0x0c0471e0u: goto P_0c0471e0;
case 0x0c0471e2u: goto P_0c0471e2;
case 0x0c0471e4u: goto P_0c0471e4;
case 0x0c0471e6u: goto P_0c0471e6;
case 0x0c0471e8u: goto P_0c0471e8;
case 0x0c0471eau: goto P_0c0471ea;
case 0x0c0471ecu: goto P_0c0471ec;
case 0x0c0471eeu: goto P_0c0471ee;
case 0x0c0471f0u: goto P_0c0471f0;
case 0x0c0471f2u: goto P_0c0471f2;
case 0x0c0471f4u: goto P_0c0471f4;
case 0x0c0471f6u: goto P_0c0471f6;
case 0x0c0471f8u: goto P_0c0471f8;
case 0x0c0471fau: goto P_0c0471fa;
case 0x0c0471fcu: goto P_0c0471fc;
case 0x0c0471feu: goto P_0c0471fe;
case 0x0c047200u: goto P_0c047200;
case 0x0c047202u: goto P_0c047202;
case 0x0c047204u: goto P_0c047204;
case 0x0c047218u: goto P_0c047218;
case 0x0c04721au: goto P_0c04721a;
case 0x0c04721cu: goto P_0c04721c;
case 0x0c04721eu: goto P_0c04721e;
case 0x0c047220u: goto P_0c047220;
case 0x0c047222u: goto P_0c047222;
case 0x0c047224u: goto P_0c047224;
case 0x0c047226u: goto P_0c047226;
case 0x0c047228u: goto P_0c047228;
case 0x0c04722au: goto P_0c04722a;
case 0x0c04722cu: goto P_0c04722c;
case 0x0c0501eau: goto P_0c0501ea;
case 0x0c0501ecu: goto P_0c0501ec;
case 0x0c0501eeu: goto P_0c0501ee;
case 0x0c0501f0u: goto P_0c0501f0;
case 0x0c0501f2u: goto P_0c0501f2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0370fc: /* original 4f22, guest PC 0x0c0370fc */
if(!s->budget--) { s->failed_pc=0x0c0370fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0370fe;
P_0c0370fe: /* original 6c63, guest PC 0x0c0370fe */
if(!s->budget--) { s->failed_pc=0x0c0370feu; return 0; }
r[12]=r[6];
goto P_0c037100;
P_0c037100: /* original 4f12, guest PC 0x0c037100 */
if(!s->budget--) { s->failed_pc=0x0c037100u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c037102;
P_0c037102: /* original 24ef, guest PC 0x0c037102 */
if(!s->budget--) { s->failed_pc=0x0c037102u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c037104;
P_0c037104: /* original 7ffc, guest PC 0x0c037104 */
if(!s->budget--) { s->failed_pc=0x0c037104u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c037106;
P_0c037106: /* original 2f52, guest PC 0x0c037106 */
if(!s->budget--) { s->failed_pc=0x0c037106u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c037108;
P_0c037108: /* original 0e1a, guest PC 0x0c037108 */
if(!s->budget--) { s->failed_pc=0x0c037108u; return 0; }
r[14]=r[19];
goto P_0c03710a;
P_0c03710a: /* original d33d, guest PC 0x0c03710a */
if(!s->budget--) { s->failed_pc=0x0c03710au; return 0; }
r[3]=read(ram,0x0c037200u,4);
goto P_0c03710c;
P_0c03710c: /* original 6eef, guest PC 0x0c03710c */
if(!s->budget--) { s->failed_pc=0x0c03710cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03710e;
P_0c03710e: /* original 3e3c, guest PC 0x0c03710e */
if(!s->budget--) { s->failed_pc=0x0c03710eu; return 0; }
r[14]+=r[3];
goto P_0c037110;
P_0c037110: /* original 8d04, guest PC 0x0c037110 */
if(!s->budget--) { s->failed_pc=0x0c037110u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c03711c; }
goto P_0c037114;
P_0c037112: /* original ed00, guest PC 0x0c037112 */
if(!s->budget--) { s->failed_pc=0x0c037112u; return 0; }
r[13]=0x00000000u;
goto P_0c037114;
P_0c037114: /* original 8802, guest PC 0x0c037114 */
if(!s->budget--) { s->failed_pc=0x0c037114u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c037116;
P_0c037116: /* original 8913, guest PC 0x0c037116 */
if(!s->budget--) { s->failed_pc=0x0c037116u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037140; }
goto P_0c037118;
P_0c037118: /* original a020, guest PC 0x0c037118 */
if(!s->budget--) { s->failed_pc=0x0c037118u; return 0; }
goto P_0c03715c;
P_0c03711a: /* original 0009, guest PC 0x0c03711a */
if(!s->budget--) { s->failed_pc=0x0c03711au; return 0; }
goto P_0c03711c;
P_0c03711c: /* original 2cc8, guest PC 0x0c03711c */
if(!s->budget--) { s->failed_pc=0x0c03711cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c03711e;
P_0c03711e: /* original 8b0b, guest PC 0x0c03711e */
if(!s->budget--) { s->failed_pc=0x0c03711eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037138; }
goto P_0c037120;
P_0c037120: /* original e101, guest PC 0x0c037120 */
if(!s->budget--) { s->failed_pc=0x0c037120u; return 0; }
r[1]=0x00000001u;
goto P_0c037122;
P_0c037122: /* original 65e3, guest PC 0x0c037122 */
if(!s->budget--) { s->failed_pc=0x0c037122u; return 0; }
r[5]=r[14];
goto P_0c037124;
P_0c037124: /* original 2e11, guest PC 0x0c037124 */
if(!s->budget--) { s->failed_pc=0x0c037124u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c037126;
P_0c037126: /* original d237, guest PC 0x0c037126 */
if(!s->budget--) { s->failed_pc=0x0c037126u; return 0; }
r[2]=read(ram,0x0c037204u,4);
goto P_0c037128;
P_0c037128: /* original 420b, guest PC 0x0c037128 */
if(!s->budget--) { s->failed_pc=0x0c037128u; return 0; }
target=r[2];
r[16]=0x0c03712cu;
r[5]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03712cu) { target=s->pc; goto dispatch; }
goto P_0c03712c;
P_0c03712a: /* original 7514, guest PC 0x0c03712a */
if(!s->budget--) { s->failed_pc=0x0c03712au; return 0; }
r[5]+=0x00000014u;
goto P_0c03712c;
P_0c03712c: /* original 6403, guest PC 0x0c03712c */
if(!s->budget--) { s->failed_pc=0x0c03712cu; return 0; }
r[4]=r[0];
goto P_0c03712e;
P_0c03712e: /* original 2448, guest PC 0x0c03712e */
if(!s->budget--) { s->failed_pc=0x0c03712eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c037130;
P_0c037130: /* original 8b01, guest PC 0x0c037130 */
if(!s->budget--) { s->failed_pc=0x0c037130u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037136; }
goto P_0c037132;
P_0c037132: /* original e001, guest PC 0x0c037132 */
if(!s->budget--) { s->failed_pc=0x0c037132u; return 0; }
r[0]=0x00000001u;
goto P_0c037134;
P_0c037134: /* original 81e1, guest PC 0x0c037134 */
if(!s->budget--) { s->failed_pc=0x0c037134u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c037136;
P_0c037136: /* original 1ed1, guest PC 0x0c037136 */
if(!s->budget--) { s->failed_pc=0x0c037136u; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c037138;
P_0c037138: /* original b326, guest PC 0x0c037138 */
if(!s->budget--) { s->failed_pc=0x0c037138u; return 0; }
target=0x0c037788u; r[16]=0x0c03713cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03713cu) { target=s->pc; goto dispatch; }
goto P_0c03713c;
P_0c03713a: /* original 0009, guest PC 0x0c03713a */
if(!s->budget--) { s->failed_pc=0x0c03713au; return 0; }
goto P_0c03713c;
P_0c03713c: /* original a013, guest PC 0x0c03713c */
if(!s->budget--) { s->failed_pc=0x0c03713cu; return 0; }
goto P_0c037166;
P_0c03713e: /* original 0009, guest PC 0x0c03713e */
if(!s->budget--) { s->failed_pc=0x0c03713eu; return 0; }
goto P_0c037140;
P_0c037140: /* original 60d3, guest PC 0x0c037140 */
if(!s->budget--) { s->failed_pc=0x0c037140u; return 0; }
r[0]=r[13];
goto P_0c037142;
P_0c037142: /* original e638, guest PC 0x0c037142 */
if(!s->budget--) { s->failed_pc=0x0c037142u; return 0; }
r[6]=0x00000038u;
goto P_0c037144;
P_0c037144: /* original e500, guest PC 0x0c037144 */
if(!s->budget--) { s->failed_pc=0x0c037144u; return 0; }
r[5]=0x00000000u;
goto P_0c037146;
P_0c037146: /* original 64e3, guest PC 0x0c037146 */
if(!s->budget--) { s->failed_pc=0x0c037146u; return 0; }
r[4]=r[14];
goto P_0c037148;
P_0c037148: /* original 2ed1, guest PC 0x0c037148 */
if(!s->budget--) { s->failed_pc=0x0c037148u; return 0; }
write(ram,r[14],r[13],2);
goto P_0c03714a;
P_0c03714a: /* original 81e1, guest PC 0x0c03714a */
if(!s->budget--) { s->failed_pc=0x0c03714au; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c03714c;
P_0c03714c: /* original 1e02, guest PC 0x0c03714c */
if(!s->budget--) { s->failed_pc=0x0c03714cu; return 0; }
write(ram,r[14]+8,r[0],4);
goto P_0c03714e;
P_0c03714e: /* original 1e03, guest PC 0x0c03714e */
if(!s->budget--) { s->failed_pc=0x0c03714eu; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c037150;
P_0c037150: /* original 1e04, guest PC 0x0c037150 */
if(!s->budget--) { s->failed_pc=0x0c037150u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c037152;
P_0c037152: /* original d22d, guest PC 0x0c037152 */
if(!s->budget--) { s->failed_pc=0x0c037152u; return 0; }
r[2]=read(ram,0x0c037208u,4);
goto P_0c037154;
P_0c037154: /* original 420b, guest PC 0x0c037154 */
if(!s->budget--) { s->failed_pc=0x0c037154u; return 0; }
target=r[2];
r[16]=0x0c037158u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037158u) { target=s->pc; goto dispatch; }
goto P_0c037158;
P_0c037156: /* original 7414, guest PC 0x0c037156 */
if(!s->budget--) { s->failed_pc=0x0c037156u; return 0; }
r[4]+=0x00000014u;
goto P_0c037158;
P_0c037158: /* original a005, guest PC 0x0c037158 */
if(!s->budget--) { s->failed_pc=0x0c037158u; return 0; }
goto P_0c037166;
P_0c03715a: /* original 0009, guest PC 0x0c03715a */
if(!s->budget--) { s->failed_pc=0x0c03715au; return 0; }
goto P_0c03715c;
P_0c03715c: /* original 65e3, guest PC 0x0c03715c */
if(!s->budget--) { s->failed_pc=0x0c03715cu; return 0; }
r[5]=r[14];
goto P_0c03715e;
P_0c03715e: /* original 1ec1, guest PC 0x0c03715e */
if(!s->budget--) { s->failed_pc=0x0c03715eu; return 0; }
write(ram,r[14]+4,r[12],4);
goto P_0c037160;
P_0c037160: /* original d228, guest PC 0x0c037160 */
if(!s->budget--) { s->failed_pc=0x0c037160u; return 0; }
r[2]=read(ram,0x0c037204u,4);
goto P_0c037162;
P_0c037162: /* original 420b, guest PC 0x0c037162 */
if(!s->budget--) { s->failed_pc=0x0c037162u; return 0; }
target=r[2];
r[16]=0x0c037166u;
r[5]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037166u) { target=s->pc; goto dispatch; }
goto P_0c037166;
P_0c037164: /* original 7514, guest PC 0x0c037164 */
if(!s->budget--) { s->failed_pc=0x0c037164u; return 0; }
r[5]+=0x00000014u;
goto P_0c037166;
P_0c037166: /* original 1ed4, guest PC 0x0c037166 */
if(!s->budget--) { s->failed_pc=0x0c037166u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c037168;
P_0c037168: /* original d428, guest PC 0x0c037168 */
if(!s->budget--) { s->failed_pc=0x0c037168u; return 0; }
r[4]=read(ram,0x0c03720cu,4);
goto P_0c03716a;
P_0c03716a: /* original 6342, guest PC 0x0c03716a */
if(!s->budget--) { s->failed_pc=0x0c03716au; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03716c;
P_0c03716c: /* original 2338, guest PC 0x0c03716c */
if(!s->budget--) { s->failed_pc=0x0c03716cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03716e;
P_0c03716e: /* original 8907, guest PC 0x0c03716e */
if(!s->budget--) { s->failed_pc=0x0c03716eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037180; }
goto P_0c037170;
P_0c037170: /* original 60f2, guest PC 0x0c037170 */
if(!s->budget--) { s->failed_pc=0x0c037170u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c037172;
P_0c037172: /* original 880b, guest PC 0x0c037172 */
if(!s->budget--) { s->failed_pc=0x0c037172u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c037174;
P_0c037174: /* original 8b04, guest PC 0x0c037174 */
if(!s->budget--) { s->failed_pc=0x0c037174u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037180; }
goto P_0c037176;
P_0c037176: /* original 2cc8, guest PC 0x0c037176 */
if(!s->budget--) { s->failed_pc=0x0c037176u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c037178;
P_0c037178: /* original 8f02, guest PC 0x0c037178 */
if(!s->budget--) { s->failed_pc=0x0c037178u; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[13],4);
if(!cond) { goto P_0c037180; }
goto P_0c03717c;
P_0c03717a: /* original 24d2, guest PC 0x0c03717a */
if(!s->budget--) { s->failed_pc=0x0c03717au; return 0; }
write(ram,r[4],r[13],4);
goto P_0c03717c;
P_0c03717c: /* original b0cb, guest PC 0x0c03717c */
if(!s->budget--) { s->failed_pc=0x0c03717cu; return 0; }
target=0x0c037316u; r[16]=0x0c037180u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037180u) { target=s->pc; goto dispatch; }
goto P_0c037180;
P_0c03717e: /* original 0009, guest PC 0x0c03717e */
if(!s->budget--) { s->failed_pc=0x0c03717eu; return 0; }
goto P_0c037180;
P_0c037180: /* original 7f04, guest PC 0x0c037180 */
if(!s->budget--) { s->failed_pc=0x0c037180u; return 0; }
r[15]+=0x00000004u;
goto P_0c037182;
P_0c037182: /* original 4f16, guest PC 0x0c037182 */
if(!s->budget--) { s->failed_pc=0x0c037182u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c037184;
P_0c037184: /* original e000, guest PC 0x0c037184 */
if(!s->budget--) { s->failed_pc=0x0c037184u; return 0; }
r[0]=0x00000000u;
goto P_0c037186;
P_0c037186: /* original 4f26, guest PC 0x0c037186 */
if(!s->budget--) { s->failed_pc=0x0c037186u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037188;
P_0c037188: /* original 6cf6, guest PC 0x0c037188 */
if(!s->budget--) { s->failed_pc=0x0c037188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03718a;
P_0c03718a: /* original 6df6, guest PC 0x0c03718a */
if(!s->budget--) { s->failed_pc=0x0c03718au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03718c;
P_0c03718c: /* original 000b, guest PC 0x0c03718c */
if(!s->budget--) { s->failed_pc=0x0c03718cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03718e: /* original 6ef6, guest PC 0x0c03718e */
if(!s->budget--) { s->failed_pc=0x0c03718eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c037190u,s,ram);
P_0c037316: /* original 4f22, guest PC 0x0c037316 */
if(!s->budget--) { s->failed_pc=0x0c037316u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c037318;
P_0c037318: /* original d321, guest PC 0x0c037318 */
if(!s->budget--) { s->failed_pc=0x0c037318u; return 0; }
r[3]=read(ram,0x0c0373a0u,4);
goto P_0c03731a;
P_0c03731a: /* original d519, guest PC 0x0c03731a */
if(!s->budget--) { s->failed_pc=0x0c03731au; return 0; }
r[5]=read(ram,0x0c037380u,4);
goto P_0c03731c;
P_0c03731c: /* original 7f9c, guest PC 0x0c03731c */
if(!s->budget--) { s->failed_pc=0x0c03731cu; return 0; }
r[15]+=0xffffff9cu;
goto P_0c03731e;
P_0c03731e: /* original 64f3, guest PC 0x0c03731e */
if(!s->budget--) { s->failed_pc=0x0c03731eu; return 0; }
r[4]=r[15];
goto P_0c037320;
P_0c037320: /* original 430b, guest PC 0x0c037320 */
if(!s->budget--) { s->failed_pc=0x0c037320u; return 0; }
target=r[3];
r[16]=0x0c037324u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037324u) { target=s->pc; goto dispatch; }
goto P_0c037324;
P_0c037322: /* original 7404, guest PC 0x0c037322 */
if(!s->budget--) { s->failed_pc=0x0c037322u; return 0; }
r[4]+=0x00000004u;
goto P_0c037324;
P_0c037324: /* original 6403, guest PC 0x0c037324 */
if(!s->budget--) { s->failed_pc=0x0c037324u; return 0; }
r[4]=r[0];
goto P_0c037326;
P_0c037326: /* original 2448, guest PC 0x0c037326 */
if(!s->budget--) { s->failed_pc=0x0c037326u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c037328;
P_0c037328: /* original 8903, guest PC 0x0c037328 */
if(!s->budget--) { s->failed_pc=0x0c037328u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037332; }
goto P_0c03732a;
P_0c03732a: /* original 7f64, guest PC 0x0c03732a */
if(!s->budget--) { s->failed_pc=0x0c03732au; return 0; }
r[15]+=0x00000064u;
goto P_0c03732c;
P_0c03732c: /* original 4f26, guest PC 0x0c03732c */
if(!s->budget--) { s->failed_pc=0x0c03732cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03732e;
P_0c03732e: /* original 000b, guest PC 0x0c03732e */
if(!s->budget--) { s->failed_pc=0x0c03732eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c037330: /* original 6043, guest PC 0x0c037330 */
if(!s->budget--) { s->failed_pc=0x0c037330u; return 0; }
r[0]=r[4];
goto P_0c037332;
P_0c037332: /* original d313, guest PC 0x0c037332 */
if(!s->budget--) { s->failed_pc=0x0c037332u; return 0; }
r[3]=read(ram,0x0c037380u,4);
goto P_0c037334;
P_0c037334: /* original 2f32, guest PC 0x0c037334 */
if(!s->budget--) { s->failed_pc=0x0c037334u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c037336;
P_0c037336: /* original 930d, guest PC 0x0c037336 */
if(!s->budget--) { s->failed_pc=0x0c037336u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037354u,2);
goto P_0c037338;
P_0c037338: /* original 65f2, guest PC 0x0c037338 */
if(!s->budget--) { s->failed_pc=0x0c037338u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03733a;
P_0c03733a: /* original d218, guest PC 0x0c03733a */
if(!s->budget--) { s->failed_pc=0x0c03733au; return 0; }
r[2]=read(ram,0x0c03739cu,4);
goto P_0c03733c;
P_0c03733c: /* original 353c, guest PC 0x0c03733c */
if(!s->budget--) { s->failed_pc=0x0c03733cu; return 0; }
r[5]+=r[3];
goto P_0c03733e;
P_0c03733e: /* original d30d, guest PC 0x0c03733e */
if(!s->budget--) { s->failed_pc=0x0c03733eu; return 0; }
r[3]=read(ram,0x0c037374u,4);
goto P_0c037340;
P_0c037340: /* original d115, guest PC 0x0c037340 */
if(!s->budget--) { s->failed_pc=0x0c037340u; return 0; }
r[1]=read(ram,0x0c037398u,4);
goto P_0c037342;
P_0c037342: /* original 6622, guest PC 0x0c037342 */
if(!s->budget--) { s->failed_pc=0x0c037342u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c037344;
P_0c037344: /* original 430b, guest PC 0x0c037344 */
if(!s->budget--) { s->failed_pc=0x0c037344u; return 0; }
target=r[3];
r[16]=0x0c037348u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037348u) { target=s->pc; goto dispatch; }
goto P_0c037348;
P_0c037346: /* original 6412, guest PC 0x0c037346 */
if(!s->budget--) { s->failed_pc=0x0c037346u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c037348;
P_0c037348: /* original e000, guest PC 0x0c037348 */
if(!s->budget--) { s->failed_pc=0x0c037348u; return 0; }
r[0]=0x00000000u;
goto P_0c03734a;
P_0c03734a: /* original 7f64, guest PC 0x0c03734a */
if(!s->budget--) { s->failed_pc=0x0c03734au; return 0; }
r[15]+=0x00000064u;
goto P_0c03734c;
P_0c03734c: /* original 4f26, guest PC 0x0c03734c */
if(!s->budget--) { s->failed_pc=0x0c03734cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03734e;
P_0c03734e: /* original 000b, guest PC 0x0c03734e */
if(!s->budget--) { s->failed_pc=0x0c03734eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037350: /* original 0009, guest PC 0x0c037350 */
if(!s->budget--) { s->failed_pc=0x0c037350u; return 0; }
return vf3_matrix_family(0x0c037352u,s,ram);
P_0c0376e0: /* original 4f22, guest PC 0x0c0376e0 */
if(!s->budget--) { s->failed_pc=0x0c0376e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0376e2;
P_0c0376e2: /* original 7ff8, guest PC 0x0c0376e2 */
if(!s->budget--) { s->failed_pc=0x0c0376e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0376e4;
P_0c0376e4: /* original 2f42, guest PC 0x0c0376e4 */
if(!s->budget--) { s->failed_pc=0x0c0376e4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0376e6;
P_0c0376e6: /* original 1f51, guest PC 0x0c0376e6 */
if(!s->budget--) { s->failed_pc=0x0c0376e6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0376e8;
P_0c0376e8: /* original b01f, guest PC 0x0c0376e8 */
if(!s->budget--) { s->failed_pc=0x0c0376e8u; return 0; }
target=0x0c03772au; r[16]=0x0c0376ecu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0376ecu) { target=s->pc; goto dispatch; }
goto P_0c0376ec;
P_0c0376ea: /* original 64f2, guest PC 0x0c0376ea */
if(!s->budget--) { s->failed_pc=0x0c0376eau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0376ec;
P_0c0376ec: /* original 2008, guest PC 0x0c0376ec */
if(!s->budget--) { s->failed_pc=0x0c0376ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0376ee;
P_0c0376ee: /* original 8b03, guest PC 0x0c0376ee */
if(!s->budget--) { s->failed_pc=0x0c0376eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0376f8; }
goto P_0c0376f0;
P_0c0376f0: /* original 7f08, guest PC 0x0c0376f0 */
if(!s->budget--) { s->failed_pc=0x0c0376f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0376f2;
P_0c0376f2: /* original 4f26, guest PC 0x0c0376f2 */
if(!s->budget--) { s->failed_pc=0x0c0376f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0376f4;
P_0c0376f4: /* original 000b, guest PC 0x0c0376f4 */
if(!s->budget--) { s->failed_pc=0x0c0376f4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0376f6: /* original e0ff, guest PC 0x0c0376f6 */
if(!s->budget--) { s->failed_pc=0x0c0376f6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0376f8;
P_0c0376f8: /* original e330, guest PC 0x0c0376f8 */
if(!s->budget--) { s->failed_pc=0x0c0376f8u; return 0; }
r[3]=0x00000030u;
goto P_0c0376fa;
P_0c0376fa: /* original 2f36, guest PC 0x0c0376fa */
if(!s->budget--) { s->failed_pc=0x0c0376fau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0376fc;
P_0c0376fc: /* original e100, guest PC 0x0c0376fc */
if(!s->budget--) { s->failed_pc=0x0c0376fcu; return 0; }
r[1]=0x00000000u;
goto P_0c0376fe;
P_0c0376fe: /* original 52f2, guest PC 0x0c0376fe */
if(!s->budget--) { s->failed_pc=0x0c0376feu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c037700;
P_0c037700: /* original e504, guest PC 0x0c037700 */
if(!s->budget--) { s->failed_pc=0x0c037700u; return 0; }
r[5]=0x00000004u;
goto P_0c037702;
P_0c037702: /* original 6613, guest PC 0x0c037702 */
if(!s->budget--) { s->failed_pc=0x0c037702u; return 0; }
r[6]=r[1];
goto P_0c037704;
P_0c037704: /* original 6713, guest PC 0x0c037704 */
if(!s->budget--) { s->failed_pc=0x0c037704u; return 0; }
r[7]=r[1];
goto P_0c037706;
P_0c037706: /* original 2f26, guest PC 0x0c037706 */
if(!s->budget--) { s->failed_pc=0x0c037706u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c037708;
P_0c037708: /* original 2f16, guest PC 0x0c037708 */
if(!s->budget--) { s->failed_pc=0x0c037708u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03770a;
P_0c03770a: /* original d223, guest PC 0x0c03770a */
if(!s->budget--) { s->failed_pc=0x0c03770au; return 0; }
r[2]=read(ram,0x0c037798u,4);
goto P_0c03770c;
P_0c03770c: /* original 420b, guest PC 0x0c03770c */
if(!s->budget--) { s->failed_pc=0x0c03770cu; return 0; }
target=r[2];
r[16]=0x0c037710u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037710u) { target=s->pc; goto dispatch; }
goto P_0c037710;
P_0c03770e: /* original 54f3, guest PC 0x0c03770e */
if(!s->budget--) { s->failed_pc=0x0c03770eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c037710;
P_0c037710: /* original 6403, guest PC 0x0c037710 */
if(!s->budget--) { s->failed_pc=0x0c037710u; return 0; }
r[4]=r[0];
goto P_0c037712;
P_0c037712: /* original 4411, guest PC 0x0c037712 */
if(!s->budget--) { s->failed_pc=0x0c037712u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c037714;
P_0c037714: /* original 8d04, guest PC 0x0c037714 */
if(!s->budget--) { s->failed_pc=0x0c037714u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c037720; }
goto P_0c037718;
P_0c037716: /* original 7f0c, guest PC 0x0c037716 */
if(!s->budget--) { s->failed_pc=0x0c037716u; return 0; }
r[15]+=0x0000000cu;
goto P_0c037718;
P_0c037718: /* original 7f08, guest PC 0x0c037718 */
if(!s->budget--) { s->failed_pc=0x0c037718u; return 0; }
r[15]+=0x00000008u;
goto P_0c03771a;
P_0c03771a: /* original 4f26, guest PC 0x0c03771a */
if(!s->budget--) { s->failed_pc=0x0c03771au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03771c;
P_0c03771c: /* original 000b, guest PC 0x0c03771c */
if(!s->budget--) { s->failed_pc=0x0c03771cu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c03771e: /* original 6043, guest PC 0x0c03771e */
if(!s->budget--) { s->failed_pc=0x0c03771eu; return 0; }
r[0]=r[4];
goto P_0c037720;
P_0c037720: /* original e000, guest PC 0x0c037720 */
if(!s->budget--) { s->failed_pc=0x0c037720u; return 0; }
r[0]=0x00000000u;
goto P_0c037722;
P_0c037722: /* original 7f08, guest PC 0x0c037722 */
if(!s->budget--) { s->failed_pc=0x0c037722u; return 0; }
r[15]+=0x00000008u;
goto P_0c037724;
P_0c037724: /* original 4f26, guest PC 0x0c037724 */
if(!s->budget--) { s->failed_pc=0x0c037724u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037726;
P_0c037726: /* original 000b, guest PC 0x0c037726 */
if(!s->budget--) { s->failed_pc=0x0c037726u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037728: /* original 0009, guest PC 0x0c037728 */
if(!s->budget--) { s->failed_pc=0x0c037728u; return 0; }
return vf3_matrix_family(0x0c03772au,s,ram);
P_0c037788: /* original d506, guest PC 0x0c037788 */
if(!s->budget--) { s->failed_pc=0x0c037788u; return 0; }
r[5]=read(ram,0x0c0377a4u,4);
goto P_0c03778a;
P_0c03778a: /* original afa9, guest PC 0x0c03778a */
if(!s->budget--) { s->failed_pc=0x0c03778au; return 0; }
r[4]=0x00000001u;
goto P_0c0376e0;
P_0c03778c: /* original e401, guest PC 0x0c03778c */
if(!s->budget--) { s->failed_pc=0x0c03778cu; return 0; }
r[4]=0x00000001u;
return vf3_matrix_family(0x0c03778eu,s,ram);
P_0c044068: /* original 4f22, guest PC 0x0c044068 */
if(!s->budget--) { s->failed_pc=0x0c044068u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04406a;
P_0c04406a: /* original 7ffc, guest PC 0x0c04406a */
if(!s->budget--) { s->failed_pc=0x0c04406au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04406c;
P_0c04406c: /* original 53f4, guest PC 0x0c04406c */
if(!s->budget--) { s->failed_pc=0x0c04406cu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c04406e;
P_0c04406e: /* original 2f36, guest PC 0x0c04406e */
if(!s->budget--) { s->failed_pc=0x0c04406eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044070;
P_0c044070: /* original 52f4, guest PC 0x0c044070 */
if(!s->budget--) { s->failed_pc=0x0c044070u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c044072;
P_0c044072: /* original 2f26, guest PC 0x0c044072 */
if(!s->budget--) { s->failed_pc=0x0c044072u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044074;
P_0c044074: /* original 53f4, guest PC 0x0c044074 */
if(!s->budget--) { s->failed_pc=0x0c044074u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c044076;
P_0c044076: /* original 2f36, guest PC 0x0c044076 */
if(!s->budget--) { s->failed_pc=0x0c044076u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c044078;
P_0c044078: /* original d332, guest PC 0x0c044078 */
if(!s->budget--) { s->failed_pc=0x0c044078u; return 0; }
r[3]=read(ram,0x0c044144u,4);
goto P_0c04407a;
P_0c04407a: /* original 430b, guest PC 0x0c04407a */
if(!s->budget--) { s->failed_pc=0x0c04407au; return 0; }
target=r[3];
r[16]=0x0c04407eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04407eu) { target=s->pc; goto dispatch; }
goto P_0c04407e;
P_0c04407c: /* original 0009, guest PC 0x0c04407c */
if(!s->budget--) { s->failed_pc=0x0c04407cu; return 0; }
goto P_0c04407e;
P_0c04407e: /* original 7f0c, guest PC 0x0c04407e */
if(!s->budget--) { s->failed_pc=0x0c04407eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c044080;
P_0c044080: /* original 2f02, guest PC 0x0c044080 */
if(!s->budget--) { s->failed_pc=0x0c044080u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c044082;
P_0c044082: /* original d22f, guest PC 0x0c044082 */
if(!s->budget--) { s->failed_pc=0x0c044082u; return 0; }
r[2]=read(ram,0x0c044140u,4);
goto P_0c044084;
P_0c044084: /* original 9059, guest PC 0x0c044084 */
if(!s->budget--) { s->failed_pc=0x0c044084u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04413au,2);
goto P_0c044086;
P_0c044086: /* original 6322, guest PC 0x0c044086 */
if(!s->budget--) { s->failed_pc=0x0c044086u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c044088;
P_0c044088: /* original 013e, guest PC 0x0c044088 */
if(!s->budget--) { s->failed_pc=0x0c044088u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c04408a;
P_0c04408a: /* original 2118, guest PC 0x0c04408a */
if(!s->budget--) { s->failed_pc=0x0c04408au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04408c;
P_0c04408c: /* original 8901, guest PC 0x0c04408c */
if(!s->budget--) { s->failed_pc=0x0c04408cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c044092; }
goto P_0c04408e;
P_0c04408e: /* original be39, guest PC 0x0c04408e */
if(!s->budget--) { s->failed_pc=0x0c04408eu; return 0; }
target=0x0c043d04u; r[16]=0x0c044092u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044092u) { target=s->pc; goto dispatch; }
goto P_0c044092;
P_0c044090: /* original 0009, guest PC 0x0c044090 */
if(!s->budget--) { s->failed_pc=0x0c044090u; return 0; }
goto P_0c044092;
P_0c044092: /* original 60f2, guest PC 0x0c044092 */
if(!s->budget--) { s->failed_pc=0x0c044092u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c044094;
P_0c044094: /* original 7f04, guest PC 0x0c044094 */
if(!s->budget--) { s->failed_pc=0x0c044094u; return 0; }
r[15]+=0x00000004u;
goto P_0c044096;
P_0c044096: /* original 4f26, guest PC 0x0c044096 */
if(!s->budget--) { s->failed_pc=0x0c044096u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044098;
P_0c044098: /* original 000b, guest PC 0x0c044098 */
if(!s->budget--) { s->failed_pc=0x0c044098u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04409a: /* original 0009, guest PC 0x0c04409a */
if(!s->budget--) { s->failed_pc=0x0c04409au; return 0; }
return vf3_matrix_family(0x0c04409cu,s,ram);
P_0c045c2a: /* original d310, guest PC 0x0c045c2a */
if(!s->budget--) { s->failed_pc=0x0c045c2au; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045c2c;
P_0c045c2c: /* original 4f22, guest PC 0x0c045c2c */
if(!s->budget--) { s->failed_pc=0x0c045c2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045c2e;
P_0c045c2e: /* original 6032, guest PC 0x0c045c2e */
if(!s->budget--) { s->failed_pc=0x0c045c2eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045c30;
P_0c045c30: /* original 401b, guest PC 0x0c045c30 */
if(!s->budget--) { s->failed_pc=0x0c045c30u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045c32;
P_0c045c32: /* original 8907, guest PC 0x0c045c32 */
if(!s->budget--) { s->failed_pc=0x0c045c32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045c44; }
goto P_0c045c34;
P_0c045c34: /* original d20c, guest PC 0x0c045c34 */
if(!s->budget--) { s->failed_pc=0x0c045c34u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045c36;
P_0c045c36: /* original d10e, guest PC 0x0c045c36 */
if(!s->budget--) { s->failed_pc=0x0c045c36u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045c38;
P_0c045c38: /* original 420b, guest PC 0x0c045c38 */
if(!s->budget--) { s->failed_pc=0x0c045c38u; return 0; }
target=r[2];
r[16]=0x0c045c3cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045c3cu) { target=s->pc; goto dispatch; }
goto P_0c045c3c;
P_0c045c3a: /* original 2f16, guest PC 0x0c045c3a */
if(!s->budget--) { s->failed_pc=0x0c045c3au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c3c;
P_0c045c3c: /* original 7f04, guest PC 0x0c045c3c */
if(!s->budget--) { s->failed_pc=0x0c045c3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c045c3e;
P_0c045c3e: /* original 4f26, guest PC 0x0c045c3e */
if(!s->budget--) { s->failed_pc=0x0c045c3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045c40;
P_0c045c40: /* original 000b, guest PC 0x0c045c40 */
if(!s->budget--) { s->failed_pc=0x0c045c40u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045c42: /* original e0fe, guest PC 0x0c045c42 */
if(!s->budget--) { s->failed_pc=0x0c045c42u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045c44;
P_0c045c44: /* original 53f3, guest PC 0x0c045c44 */
if(!s->budget--) { s->failed_pc=0x0c045c44u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c045c46;
P_0c045c46: /* original 2f36, guest PC 0x0c045c46 */
if(!s->budget--) { s->failed_pc=0x0c045c46u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c48;
P_0c045c48: /* original 52f3, guest PC 0x0c045c48 */
if(!s->budget--) { s->failed_pc=0x0c045c48u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c045c4a;
P_0c045c4a: /* original 2f26, guest PC 0x0c045c4a */
if(!s->budget--) { s->failed_pc=0x0c045c4au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c4c;
P_0c045c4c: /* original 53f3, guest PC 0x0c045c4c */
if(!s->budget--) { s->failed_pc=0x0c045c4cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c045c4e;
P_0c045c4e: /* original 2f36, guest PC 0x0c045c4e */
if(!s->budget--) { s->failed_pc=0x0c045c4eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c50;
P_0c045c50: /* original b016, guest PC 0x0c045c50 */
if(!s->budget--) { s->failed_pc=0x0c045c50u; return 0; }
target=0x0c045c80u; r[16]=0x0c045c54u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045c54u) { target=s->pc; goto dispatch; }
goto P_0c045c54;
P_0c045c52: /* original 0009, guest PC 0x0c045c52 */
if(!s->budget--) { s->failed_pc=0x0c045c52u; return 0; }
goto P_0c045c54;
P_0c045c54: /* original d305, guest PC 0x0c045c54 */
if(!s->budget--) { s->failed_pc=0x0c045c54u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045c56;
P_0c045c56: /* original e100, guest PC 0x0c045c56 */
if(!s->budget--) { s->failed_pc=0x0c045c56u; return 0; }
r[1]=0x00000000u;
goto P_0c045c58;
P_0c045c58: /* original 7f0c, guest PC 0x0c045c58 */
if(!s->budget--) { s->failed_pc=0x0c045c58u; return 0; }
r[15]+=0x0000000cu;
goto P_0c045c5a;
P_0c045c5a: /* original 6232, guest PC 0x0c045c5a */
if(!s->budget--) { s->failed_pc=0x0c045c5au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045c5c;
P_0c045c5c: /* original 2210, guest PC 0x0c045c5c */
if(!s->budget--) { s->failed_pc=0x0c045c5cu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045c5e;
P_0c045c5e: /* original 4f26, guest PC 0x0c045c5e */
if(!s->budget--) { s->failed_pc=0x0c045c5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045c60;
P_0c045c60: /* original 000b, guest PC 0x0c045c60 */
if(!s->budget--) { s->failed_pc=0x0c045c60u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045c62: /* original 0009, guest PC 0x0c045c62 */
if(!s->budget--) { s->failed_pc=0x0c045c62u; return 0; }
return vf3_matrix_family(0x0c045c64u,s,ram);
P_0c045c80: /* original 2fe6, guest PC 0x0c045c80 */
if(!s->budget--) { s->failed_pc=0x0c045c80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c82;
P_0c045c82: /* original 4628, guest PC 0x0c045c82 */
if(!s->budget--) { s->failed_pc=0x0c045c82u; return 0; }
r[6]<<=16;
return vf3_matrix_family(0x0c045c84u,s,ram);
P_0c04667a: /* original 4f22, guest PC 0x0c04667a */
if(!s->budget--) { s->failed_pc=0x0c04667au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04667c;
P_0c04667c: /* original 7ff8, guest PC 0x0c04667c */
if(!s->budget--) { s->failed_pc=0x0c04667cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04667e;
P_0c04667e: /* original 2f42, guest PC 0x0c04667e */
if(!s->budget--) { s->failed_pc=0x0c04667eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046680;
P_0c046680: /* original 1f51, guest PC 0x0c046680 */
if(!s->budget--) { s->failed_pc=0x0c046680u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046682;
P_0c046682: /* original d322, guest PC 0x0c046682 */
if(!s->budget--) { s->failed_pc=0x0c046682u; return 0; }
r[3]=read(ram,0x0c04670cu,4);
goto P_0c046684;
P_0c046684: /* original 430b, guest PC 0x0c046684 */
if(!s->budget--) { s->failed_pc=0x0c046684u; return 0; }
target=r[3];
r[16]=0x0c046688u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046688u) { target=s->pc; goto dispatch; }
goto P_0c046688;
P_0c046686: /* original 64f2, guest PC 0x0c046686 */
if(!s->budget--) { s->failed_pc=0x0c046686u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046688;
P_0c046688: /* original 2008, guest PC 0x0c046688 */
if(!s->budget--) { s->failed_pc=0x0c046688u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04668a;
P_0c04668a: /* original 8903, guest PC 0x0c04668a */
if(!s->budget--) { s->failed_pc=0x0c04668au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046694; }
goto P_0c04668c;
P_0c04668c: /* original 7f08, guest PC 0x0c04668c */
if(!s->budget--) { s->failed_pc=0x0c04668cu; return 0; }
r[15]+=0x00000008u;
goto P_0c04668e;
P_0c04668e: /* original 4f26, guest PC 0x0c04668e */
if(!s->budget--) { s->failed_pc=0x0c04668eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046690;
P_0c046690: /* original 000b, guest PC 0x0c046690 */
if(!s->budget--) { s->failed_pc=0x0c046690u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046692: /* original e0ff, guest PC 0x0c046692 */
if(!s->budget--) { s->failed_pc=0x0c046692u; return 0; }
r[0]=0xffffffffu;
goto P_0c046694;
P_0c046694: /* original d324, guest PC 0x0c046694 */
if(!s->budget--) { s->failed_pc=0x0c046694u; return 0; }
r[3]=read(ram,0x0c046728u,4);
goto P_0c046696;
P_0c046696: /* original 64f2, guest PC 0x0c046696 */
if(!s->budget--) { s->failed_pc=0x0c046696u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046698;
P_0c046698: /* original 55f1, guest PC 0x0c046698 */
if(!s->budget--) { s->failed_pc=0x0c046698u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04669a;
P_0c04669a: /* original 7f08, guest PC 0x0c04669a */
if(!s->budget--) { s->failed_pc=0x0c04669au; return 0; }
r[15]+=0x00000008u;
goto P_0c04669c;
P_0c04669c: /* original 432b, guest PC 0x0c04669c */
if(!s->budget--) { s->failed_pc=0x0c04669cu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c04669e: /* original 4f26, guest PC 0x0c04669e */
if(!s->budget--) { s->failed_pc=0x0c04669eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0466a0u,s,ram);
P_0c04708c: /* original 2fe6, guest PC 0x0c04708c */
if(!s->budget--) { s->failed_pc=0x0c04708cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04708e;
P_0c04708e: /* original 6e53, guest PC 0x0c04708e */
if(!s->budget--) { s->failed_pc=0x0c04708eu; return 0; }
r[14]=r[5];
goto P_0c047090;
P_0c047090: /* original 2fd6, guest PC 0x0c047090 */
if(!s->budget--) { s->failed_pc=0x0c047090u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047092;
P_0c047092: /* original e040, guest PC 0x0c047092 */
if(!s->budget--) { s->failed_pc=0x0c047092u; return 0; }
r[0]=0x00000040u;
goto P_0c047094;
P_0c047094: /* original 2fc6, guest PC 0x0c047094 */
if(!s->budget--) { s->failed_pc=0x0c047094u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047096;
P_0c047096: /* original 2fb6, guest PC 0x0c047096 */
if(!s->budget--) { s->failed_pc=0x0c047096u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c047098;
P_0c047098: /* original 2fa6, guest PC 0x0c047098 */
if(!s->budget--) { s->failed_pc=0x0c047098u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04709a;
P_0c04709a: /* original 4f22, guest PC 0x0c04709a */
if(!s->budget--) { s->failed_pc=0x0c04709au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04709c;
P_0c04709c: /* original 03ed, guest PC 0x0c04709c */
if(!s->budget--) { s->failed_pc=0x0c04709cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04709e;
P_0c04709e: /* original 2338, guest PC 0x0c04709e */
if(!s->budget--) { s->failed_pc=0x0c04709eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0470a0;
P_0c0470a0: /* original 7ffc, guest PC 0x0c0470a0 */
if(!s->budget--) { s->failed_pc=0x0c0470a0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0470a2;
P_0c0470a2: /* original 8d0a, guest PC 0x0c0470a2 */
if(!s->budget--) { s->failed_pc=0x0c0470a2u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0470ba; }
goto P_0c0470a6;
P_0c0470a4: /* original 6d53, guest PC 0x0c0470a4 */
if(!s->budget--) { s->failed_pc=0x0c0470a4u; return 0; }
r[13]=r[5];
goto P_0c0470a6;
P_0c0470a6: /* original 03ed, guest PC 0x0c0470a6 */
if(!s->budget--) { s->failed_pc=0x0c0470a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470a8;
P_0c0470a8: /* original e503, guest PC 0x0c0470a8 */
if(!s->budget--) { s->failed_pc=0x0c0470a8u; return 0; }
r[5]=0x00000003u;
goto P_0c0470aa;
P_0c0470aa: /* original 633d, guest PC 0x0c0470aa */
if(!s->budget--) { s->failed_pc=0x0c0470aau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0470ac;
P_0c0470ac: /* original 3357, guest PC 0x0c0470ac */
if(!s->budget--) { s->failed_pc=0x0c0470acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0470ae;
P_0c0470ae: /* original 8904, guest PC 0x0c0470ae */
if(!s->budget--) { s->failed_pc=0x0c0470aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0470ba; }
goto P_0c0470b0;
P_0c0470b0: /* original e044, guest PC 0x0c0470b0 */
if(!s->budget--) { s->failed_pc=0x0c0470b0u; return 0; }
r[0]=0x00000044u;
goto P_0c0470b2;
P_0c0470b2: /* original 03ed, guest PC 0x0c0470b2 */
if(!s->budget--) { s->failed_pc=0x0c0470b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470b4;
P_0c0470b4: /* original 633d, guest PC 0x0c0470b4 */
if(!s->budget--) { s->failed_pc=0x0c0470b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0470b6;
P_0c0470b6: /* original 3357, guest PC 0x0c0470b6 */
if(!s->budget--) { s->failed_pc=0x0c0470b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[5])!=0);
goto P_0c0470b8;
P_0c0470b8: /* original 8b0e, guest PC 0x0c0470b8 */
if(!s->budget--) { s->failed_pc=0x0c0470b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0470d8; }
goto P_0c0470ba;
P_0c0470ba: /* original 9005, guest PC 0x0c0470ba */
if(!s->budget--) { s->failed_pc=0x0c0470bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0470c8u,2);
goto P_0c0470bc;
P_0c0470bc: /* original a084, guest PC 0x0c0470bc */
if(!s->budget--) { s->failed_pc=0x0c0470bcu; return 0; }
goto P_0c0471c8;
P_0c0470be: /* original 0009, guest PC 0x0c0470be */
if(!s->budget--) { s->failed_pc=0x0c0470beu; return 0; }
return vf3_matrix_family(0x0c0470c0u,s,ram);
P_0c0470d8: /* original e040, guest PC 0x0c0470d8 */
if(!s->budget--) { s->failed_pc=0x0c0470d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0470da;
P_0c0470da: /* original 9194, guest PC 0x0c0470da */
if(!s->budget--) { s->failed_pc=0x0c0470dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047206u,2);
goto P_0c0470dc;
P_0c0470dc: /* original 0aed, guest PC 0x0c0470dc */
if(!s->budget--) { s->failed_pc=0x0c0470dcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470de;
P_0c0470de: /* original 67e3, guest PC 0x0c0470de */
if(!s->budget--) { s->failed_pc=0x0c0470deu; return 0; }
r[7]=r[14];
goto P_0c0470e0;
P_0c0470e0: /* original d04a, guest PC 0x0c0470e0 */
if(!s->budget--) { s->failed_pc=0x0c0470e0u; return 0; }
r[0]=read(ram,0x0c04720cu,4);
goto P_0c0470e2;
P_0c0470e2: /* original 6643, guest PC 0x0c0470e2 */
if(!s->budget--) { s->failed_pc=0x0c0470e2u; return 0; }
r[6]=r[4];
goto P_0c0470e4;
P_0c0470e4: /* original 6aad, guest PC 0x0c0470e4 */
if(!s->budget--) { s->failed_pc=0x0c0470e4u; return 0; }
r[10]=r[10]&65535u;
goto P_0c0470e6;
P_0c0470e6: /* original 4a08, guest PC 0x0c0470e6 */
if(!s->budget--) { s->failed_pc=0x0c0470e6u; return 0; }
r[10]<<=2;
goto P_0c0470e8;
P_0c0470e8: /* original 0aae, guest PC 0x0c0470e8 */
if(!s->budget--) { s->failed_pc=0x0c0470e8u; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c0470ea;
P_0c0470ea: /* original e044, guest PC 0x0c0470ea */
if(!s->budget--) { s->failed_pc=0x0c0470eau; return 0; }
r[0]=0x00000044u;
goto P_0c0470ec;
P_0c0470ec: /* original 0bed, guest PC 0x0c0470ec */
if(!s->budget--) { s->failed_pc=0x0c0470ecu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0470ee;
P_0c0470ee: /* original d048, guest PC 0x0c0470ee */
if(!s->budget--) { s->failed_pc=0x0c0470eeu; return 0; }
r[0]=read(ram,0x0c047210u,4);
goto P_0c0470f0;
P_0c0470f0: /* original 63a3, guest PC 0x0c0470f0 */
if(!s->budget--) { s->failed_pc=0x0c0470f0u; return 0; }
r[3]=r[10];
goto P_0c0470f2;
P_0c0470f2: /* original 6bbd, guest PC 0x0c0470f2 */
if(!s->budget--) { s->failed_pc=0x0c0470f2u; return 0; }
r[11]=r[11]&65535u;
goto P_0c0470f4;
P_0c0470f4: /* original 4b08, guest PC 0x0c0470f4 */
if(!s->budget--) { s->failed_pc=0x0c0470f4u; return 0; }
r[11]<<=2;
goto P_0c0470f6;
P_0c0470f6: /* original 0bbe, guest PC 0x0c0470f6 */
if(!s->budget--) { s->failed_pc=0x0c0470f6u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c0470f8;
P_0c0470f8: /* original e048, guest PC 0x0c0470f8 */
if(!s->budget--) { s->failed_pc=0x0c0470f8u; return 0; }
r[0]=0x00000048u;
goto P_0c0470fa;
P_0c0470fa: /* original 02ee, guest PC 0x0c0470fa */
if(!s->budget--) { s->failed_pc=0x0c0470fau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0470fc;
P_0c0470fc: /* original 33bc, guest PC 0x0c0470fc */
if(!s->budget--) { s->failed_pc=0x0c0470fcu; return 0; }
r[3]+=r[11];
goto P_0c0470fe;
P_0c0470fe: /* original 332c, guest PC 0x0c0470fe */
if(!s->budget--) { s->failed_pc=0x0c0470feu; return 0; }
r[3]+=r[2];
goto P_0c047100;
P_0c047100: /* original 331c, guest PC 0x0c047100 */
if(!s->budget--) { s->failed_pc=0x0c047100u; return 0; }
r[3]+=r[1];
goto P_0c047102;
P_0c047102: /* original 2f32, guest PC 0x0c047102 */
if(!s->budget--) { s->failed_pc=0x0c047102u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c047104;
P_0c047104: /* original a004, guest PC 0x0c047104 */
if(!s->budget--) { s->failed_pc=0x0c047104u; return 0; }
r[5]=0x00000010u;
goto P_0c047110;
P_0c047106: /* original e510, guest PC 0x0c047106 */
if(!s->budget--) { s->failed_pc=0x0c047106u; return 0; }
r[5]=0x00000010u;
goto P_0c047108;
P_0c047108: /* original 6374, guest PC 0x0c047108 */
if(!s->budget--) { s->failed_pc=0x0c047108u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04710a;
P_0c04710a: /* original 75ff, guest PC 0x0c04710a */
if(!s->budget--) { s->failed_pc=0x0c04710au; return 0; }
r[5]+=0xffffffffu;
goto P_0c04710c;
P_0c04710c: /* original 2630, guest PC 0x0c04710c */
if(!s->budget--) { s->failed_pc=0x0c04710cu; return 0; }
write(ram,r[6],r[3],1);
goto P_0c04710e;
P_0c04710e: /* original 7601, guest PC 0x0c04710e */
if(!s->budget--) { s->failed_pc=0x0c04710eu; return 0; }
r[6]+=0x00000001u;
goto P_0c047110;
P_0c047110: /* original 2558, guest PC 0x0c047110 */
if(!s->budget--) { s->failed_pc=0x0c047110u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c047112;
P_0c047112: /* original 8bf9, guest PC 0x0c047112 */
if(!s->budget--) { s->failed_pc=0x0c047112u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047108; }
goto P_0c047114;
P_0c047114: /* original 6743, guest PC 0x0c047114 */
if(!s->budget--) { s->failed_pc=0x0c047114u; return 0; }
r[7]=r[4];
goto P_0c047116;
P_0c047116: /* original 6ce3, guest PC 0x0c047116 */
if(!s->budget--) { s->failed_pc=0x0c047116u; return 0; }
r[12]=r[14];
goto P_0c047118;
P_0c047118: /* original e500, guest PC 0x0c047118 */
if(!s->budget--) { s->failed_pc=0x0c047118u; return 0; }
r[5]=0x00000000u;
goto P_0c04711a;
P_0c04711a: /* original 7c10, guest PC 0x0c04711a */
if(!s->budget--) { s->failed_pc=0x0c04711au; return 0; }
r[12]+=0x00000010u;
goto P_0c04711c;
P_0c04711c: /* original 2650, guest PC 0x0c04711c */
if(!s->budget--) { s->failed_pc=0x0c04711cu; return 0; }
write(ram,r[6],r[5],1);
goto P_0c04711e;
P_0c04711e: /* original 7712, guest PC 0x0c04711e */
if(!s->budget--) { s->failed_pc=0x0c04711eu; return 0; }
r[7]+=0x00000012u;
goto P_0c047120;
P_0c047120: /* original a004, guest PC 0x0c047120 */
if(!s->budget--) { s->failed_pc=0x0c047120u; return 0; }
r[6]=0x00000020u;
goto P_0c04712c;
P_0c047122: /* original e620, guest PC 0x0c047122 */
if(!s->budget--) { s->failed_pc=0x0c047122u; return 0; }
r[6]=0x00000020u;
goto P_0c047124;
P_0c047124: /* original 63c4, guest PC 0x0c047124 */
if(!s->budget--) { s->failed_pc=0x0c047124u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c047126;
P_0c047126: /* original 76ff, guest PC 0x0c047126 */
if(!s->budget--) { s->failed_pc=0x0c047126u; return 0; }
r[6]+=0xffffffffu;
goto P_0c047128;
P_0c047128: /* original 2730, guest PC 0x0c047128 */
if(!s->budget--) { s->failed_pc=0x0c047128u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c04712a;
P_0c04712a: /* original 7701, guest PC 0x0c04712a */
if(!s->budget--) { s->failed_pc=0x0c04712au; return 0; }
r[7]+=0x00000001u;
goto P_0c04712c;
P_0c04712c: /* original 2668, guest PC 0x0c04712c */
if(!s->budget--) { s->failed_pc=0x0c04712cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c04712e;
P_0c04712e: /* original 8bf9, guest PC 0x0c04712e */
if(!s->budget--) { s->failed_pc=0x0c04712eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c047124; }
goto P_0c047130;
P_0c047130: /* original 2750, guest PC 0x0c047130 */
if(!s->budget--) { s->failed_pc=0x0c047130u; return 0; }
write(ram,r[7],r[5],1);
goto P_0c047132;
P_0c047132: /* original 6ce3, guest PC 0x0c047132 */
if(!s->budget--) { s->failed_pc=0x0c047132u; return 0; }
r[12]=r[14];
goto P_0c047134;
P_0c047134: /* original 6743, guest PC 0x0c047134 */
if(!s->budget--) { s->failed_pc=0x0c047134u; return 0; }
r[7]=r[4];
goto P_0c047136;
P_0c047136: /* original 7c30, guest PC 0x0c047136 */
if(!s->budget--) { s->failed_pc=0x0c047136u; return 0; }
r[12]+=0x00000030u;
goto P_0c047138;
P_0c047138: /* original 7734, guest PC 0x0c047138 */
if(!s->budget--) { s->failed_pc=0x0c047138u; return 0; }
r[7]+=0x00000034u;
goto P_0c04713a;
P_0c04713a: /* original a004, guest PC 0x0c04713a */
if(!s->budget--) { s->failed_pc=0x0c04713au; return 0; }
r[6]=0x00000010u;
goto P_0c047146;
P_0c04713c: /* original e610, guest PC 0x0c04713c */
if(!s->budget--) { s->failed_pc=0x0c04713cu; return 0; }
r[6]=0x00000010u;
goto P_0c04713e;
P_0c04713e: /* original 63c4, guest PC 0x0c04713e */
if(!s->budget--) { s->failed_pc=0x0c04713eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c047140;
P_0c047140: /* original 76ff, guest PC 0x0c047140 */
if(!s->budget--) { s->failed_pc=0x0c047140u; return 0; }
r[6]+=0xffffffffu;
goto P_0c047142;
P_0c047142: /* original 2730, guest PC 0x0c047142 */
if(!s->budget--) { s->failed_pc=0x0c047142u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c047144;
P_0c047144: /* original 7701, guest PC 0x0c047144 */
if(!s->budget--) { s->failed_pc=0x0c047144u; return 0; }
r[7]+=0x00000001u;
goto P_0c047146;
P_0c047146: /* original 2668, guest PC 0x0c047146 */
if(!s->budget--) { s->failed_pc=0x0c047146u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c047148;
P_0c047148: /* original 8bf9, guest PC 0x0c047148 */
if(!s->budget--) { s->failed_pc=0x0c047148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04713e; }
goto P_0c04714a;
P_0c04714a: /* original e042, guest PC 0x0c04714a */
if(!s->budget--) { s->failed_pc=0x0c04714au; return 0; }
r[0]=0x00000042u;
goto P_0c04714c;
P_0c04714c: /* original 66d3, guest PC 0x0c04714c */
if(!s->budget--) { s->failed_pc=0x0c04714cu; return 0; }
r[6]=r[13];
goto P_0c04714e;
P_0c04714e: /* original 2750, guest PC 0x0c04714e */
if(!s->budget--) { s->failed_pc=0x0c04714eu; return 0; }
write(ram,r[7],r[5],1);
goto P_0c047150;
P_0c047150: /* original 03ed, guest PC 0x0c047150 */
if(!s->budget--) { s->failed_pc=0x0c047150u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c047152;
P_0c047152: /* original e04e, guest PC 0x0c047152 */
if(!s->budget--) { s->failed_pc=0x0c047152u; return 0; }
r[0]=0x0000004eu;
goto P_0c047154;
P_0c047154: /* original 0435, guest PC 0x0c047154 */
if(!s->budget--) { s->failed_pc=0x0c047154u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c047156;
P_0c047156: /* original e040, guest PC 0x0c047156 */
if(!s->budget--) { s->failed_pc=0x0c047156u; return 0; }
r[0]=0x00000040u;
goto P_0c047158;
P_0c047158: /* original 02ed, guest PC 0x0c047158 */
if(!s->budget--) { s->failed_pc=0x0c047158u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04715a;
P_0c04715a: /* original e04c, guest PC 0x0c04715a */
if(!s->budget--) { s->failed_pc=0x0c04715au; return 0; }
r[0]=0x0000004cu;
goto P_0c04715c;
P_0c04715c: /* original 63d3, guest PC 0x0c04715c */
if(!s->budget--) { s->failed_pc=0x0c04715cu; return 0; }
r[3]=r[13];
goto P_0c04715e;
P_0c04715e: /* original 7360, guest PC 0x0c04715e */
if(!s->budget--) { s->failed_pc=0x0c04715eu; return 0; }
r[3]+=0x00000060u;
goto P_0c047160;
P_0c047160: /* original 0425, guest PC 0x0c047160 */
if(!s->budget--) { s->failed_pc=0x0c047160u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c047162;
P_0c047162: /* original e044, guest PC 0x0c047162 */
if(!s->budget--) { s->failed_pc=0x0c047162u; return 0; }
r[0]=0x00000044u;
goto P_0c047164;
P_0c047164: /* original 0436, guest PC 0x0c047164 */
if(!s->budget--) { s->failed_pc=0x0c047164u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c047166;
P_0c047166: /* original e048, guest PC 0x0c047166 */
if(!s->budget--) { s->failed_pc=0x0c047166u; return 0; }
r[0]=0x00000048u;
goto P_0c047168;
P_0c047168: /* original 924d, guest PC 0x0c047168 */
if(!s->budget--) { s->failed_pc=0x0c047168u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047206u,2);
goto P_0c04716a;
P_0c04716a: /* original 362c, guest PC 0x0c04716a */
if(!s->budget--) { s->failed_pc=0x0c04716au; return 0; }
r[6]+=r[2];
goto P_0c04716c;
P_0c04716c: /* original 0466, guest PC 0x0c04716c */
if(!s->budget--) { s->failed_pc=0x0c04716cu; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c04716e;
P_0c04716e: /* original e044, guest PC 0x0c04716e */
if(!s->budget--) { s->failed_pc=0x0c04716eu; return 0; }
r[0]=0x00000044u;
goto P_0c047170;
P_0c047170: /* original 03ed, guest PC 0x0c047170 */
if(!s->budget--) { s->failed_pc=0x0c047170u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c047172;
P_0c047172: /* original e054, guest PC 0x0c047172 */
if(!s->budget--) { s->failed_pc=0x0c047172u; return 0; }
r[0]=0x00000054u;
goto P_0c047174;
P_0c047174: /* original 0435, guest PC 0x0c047174 */
if(!s->budget--) { s->failed_pc=0x0c047174u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c047176;
P_0c047176: /* original e044, guest PC 0x0c047176 */
if(!s->budget--) { s->failed_pc=0x0c047176u; return 0; }
r[0]=0x00000044u;
goto P_0c047178;
P_0c047178: /* original 01ed, guest PC 0x0c047178 */
if(!s->budget--) { s->failed_pc=0x0c047178u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04717a;
P_0c04717a: /* original 2118, guest PC 0x0c04717a */
if(!s->budget--) { s->failed_pc=0x0c04717au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04717c;
P_0c04717c: /* original 8f03, guest PC 0x0c04717c */
if(!s->budget--) { s->failed_pc=0x0c04717cu; return 0; }
cond=r[17]&1u;
r[6]+=r[10];
if(!cond) { goto P_0c047186; }
goto P_0c047180;
P_0c04717e: /* original 36ac, guest PC 0x0c04717e */
if(!s->budget--) { s->failed_pc=0x0c04717eu; return 0; }
r[6]+=r[10];
goto P_0c047180;
P_0c047180: /* original e050, guest PC 0x0c047180 */
if(!s->budget--) { s->failed_pc=0x0c047180u; return 0; }
r[0]=0x00000050u;
goto P_0c047182;
P_0c047182: /* original a003, guest PC 0x0c047182 */
if(!s->budget--) { s->failed_pc=0x0c047182u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c04718c;
P_0c047184: /* original 0456, guest PC 0x0c047184 */
if(!s->budget--) { s->failed_pc=0x0c047184u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c047186;
P_0c047186: /* original e050, guest PC 0x0c047186 */
if(!s->budget--) { s->failed_pc=0x0c047186u; return 0; }
r[0]=0x00000050u;
goto P_0c047188;
P_0c047188: /* original 0466, guest PC 0x0c047188 */
if(!s->budget--) { s->failed_pc=0x0c047188u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c04718a;
P_0c04718a: /* original 36bc, guest PC 0x0c04718a */
if(!s->budget--) { s->failed_pc=0x0c04718au; return 0; }
r[6]+=r[11];
goto P_0c04718c;
P_0c04718c: /* original e048, guest PC 0x0c04718c */
if(!s->budget--) { s->failed_pc=0x0c04718cu; return 0; }
r[0]=0x00000048u;
goto P_0c04718e;
P_0c04718e: /* original 03ee, guest PC 0x0c04718e */
if(!s->budget--) { s->failed_pc=0x0c04718eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c047190;
P_0c047190: /* original e05c, guest PC 0x0c047190 */
if(!s->budget--) { s->failed_pc=0x0c047190u; return 0; }
r[0]=0x0000005cu;
goto P_0c047192;
P_0c047192: /* original 0436, guest PC 0x0c047192 */
if(!s->budget--) { s->failed_pc=0x0c047192u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c047194;
P_0c047194: /* original e048, guest PC 0x0c047194 */
if(!s->budget--) { s->failed_pc=0x0c047194u; return 0; }
r[0]=0x00000048u;
goto P_0c047196;
P_0c047196: /* original 02ee, guest PC 0x0c047196 */
if(!s->budget--) { s->failed_pc=0x0c047196u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c047198;
P_0c047198: /* original 2228, guest PC 0x0c047198 */
if(!s->budget--) { s->failed_pc=0x0c047198u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04719a;
P_0c04719a: /* original 8b02, guest PC 0x0c04719a */
if(!s->budget--) { s->failed_pc=0x0c04719au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471a2; }
goto P_0c04719c;
P_0c04719c: /* original e058, guest PC 0x0c04719c */
if(!s->budget--) { s->failed_pc=0x0c04719cu; return 0; }
r[0]=0x00000058u;
goto P_0c04719e;
P_0c04719e: /* original a002, guest PC 0x0c04719e */
if(!s->budget--) { s->failed_pc=0x0c04719eu; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0471a6;
P_0c0471a0: /* original 0456, guest PC 0x0c0471a0 */
if(!s->budget--) { s->failed_pc=0x0c0471a0u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0471a2;
P_0c0471a2: /* original e058, guest PC 0x0c0471a2 */
if(!s->budget--) { s->failed_pc=0x0c0471a2u; return 0; }
r[0]=0x00000058u;
goto P_0c0471a4;
P_0c0471a4: /* original 0466, guest PC 0x0c0471a4 */
if(!s->budget--) { s->failed_pc=0x0c0471a4u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c0471a6;
P_0c0471a6: /* original e046, guest PC 0x0c0471a6 */
if(!s->budget--) { s->failed_pc=0x0c0471a6u; return 0; }
r[0]=0x00000046u;
goto P_0c0471a8;
P_0c0471a8: /* original 0ced, guest PC 0x0c0471a8 */
if(!s->budget--) { s->failed_pc=0x0c0471a8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0471aa;
P_0c0471aa: /* original 0e55, guest PC 0x0c0471aa */
if(!s->budget--) { s->failed_pc=0x0c0471aau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0471ac;
P_0c0471ac: /* original 65f2, guest PC 0x0c0471ac */
if(!s->budget--) { s->failed_pc=0x0c0471acu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0471ae;
P_0c0471ae: /* original b013, guest PC 0x0c0471ae */
if(!s->budget--) { s->failed_pc=0x0c0471aeu; return 0; }
target=0x0c0471d8u; r[16]=0x0c0471b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0471b2u) { target=s->pc; goto dispatch; }
goto P_0c0471b2;
P_0c0471b0: /* original 64d3, guest PC 0x0c0471b0 */
if(!s->budget--) { s->failed_pc=0x0c0471b0u; return 0; }
r[4]=r[13];
goto P_0c0471b2;
P_0c0471b2: /* original 6403, guest PC 0x0c0471b2 */
if(!s->budget--) { s->failed_pc=0x0c0471b2u; return 0; }
r[4]=r[0];
goto P_0c0471b4;
P_0c0471b4: /* original e046, guest PC 0x0c0471b4 */
if(!s->budget--) { s->failed_pc=0x0c0471b4u; return 0; }
r[0]=0x00000046u;
goto P_0c0471b6;
P_0c0471b6: /* original 0ec5, guest PC 0x0c0471b6 */
if(!s->budget--) { s->failed_pc=0x0c0471b6u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0471b8;
P_0c0471b8: /* original 6ccd, guest PC 0x0c0471b8 */
if(!s->budget--) { s->failed_pc=0x0c0471b8u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0471ba;
P_0c0471ba: /* original 644d, guest PC 0x0c0471ba */
if(!s->budget--) { s->failed_pc=0x0c0471bau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0471bc;
P_0c0471bc: /* original 34c0, guest PC 0x0c0471bc */
if(!s->budget--) { s->failed_pc=0x0c0471bcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[12])!=0);
goto P_0c0471be;
P_0c0471be: /* original 8902, guest PC 0x0c0471be */
if(!s->budget--) { s->failed_pc=0x0c0471beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0471c6; }
goto P_0c0471c0;
P_0c0471c0: /* original 9022, guest PC 0x0c0471c0 */
if(!s->budget--) { s->failed_pc=0x0c0471c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c047208u,2);
goto P_0c0471c2;
P_0c0471c2: /* original a001, guest PC 0x0c0471c2 */
if(!s->budget--) { s->failed_pc=0x0c0471c2u; return 0; }
goto P_0c0471c8;
P_0c0471c4: /* original 0009, guest PC 0x0c0471c4 */
if(!s->budget--) { s->failed_pc=0x0c0471c4u; return 0; }
goto P_0c0471c6;
P_0c0471c6: /* original e000, guest PC 0x0c0471c6 */
if(!s->budget--) { s->failed_pc=0x0c0471c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0471c8;
P_0c0471c8: /* original 7f04, guest PC 0x0c0471c8 */
if(!s->budget--) { s->failed_pc=0x0c0471c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0471ca;
P_0c0471ca: /* original 4f26, guest PC 0x0c0471ca */
if(!s->budget--) { s->failed_pc=0x0c0471cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0471cc;
P_0c0471cc: /* original 6af6, guest PC 0x0c0471cc */
if(!s->budget--) { s->failed_pc=0x0c0471ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0471ce;
P_0c0471ce: /* original 6bf6, guest PC 0x0c0471ce */
if(!s->budget--) { s->failed_pc=0x0c0471ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0471d0;
P_0c0471d0: /* original 6cf6, guest PC 0x0c0471d0 */
if(!s->budget--) { s->failed_pc=0x0c0471d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0471d2;
P_0c0471d2: /* original 6df6, guest PC 0x0c0471d2 */
if(!s->budget--) { s->failed_pc=0x0c0471d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0471d4;
P_0c0471d4: /* original 000b, guest PC 0x0c0471d4 */
if(!s->budget--) { s->failed_pc=0x0c0471d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0471d6: /* original 6ef6, guest PC 0x0c0471d6 */
if(!s->budget--) { s->failed_pc=0x0c0471d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0471d8;
P_0c0471d8: /* original 2fc6, guest PC 0x0c0471d8 */
if(!s->budget--) { s->failed_pc=0x0c0471d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471da;
P_0c0471da: /* original e600, guest PC 0x0c0471da */
if(!s->budget--) { s->failed_pc=0x0c0471dau; return 0; }
r[6]=0x00000000u;
goto P_0c0471dc;
P_0c0471dc: /* original 2fb6, guest PC 0x0c0471dc */
if(!s->budget--) { s->failed_pc=0x0c0471dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471de;
P_0c0471de: /* original eb08, guest PC 0x0c0471de */
if(!s->budget--) { s->failed_pc=0x0c0471deu; return 0; }
r[11]=0x00000008u;
goto P_0c0471e0;
P_0c0471e0: /* original 2fa6, guest PC 0x0c0471e0 */
if(!s->budget--) { s->failed_pc=0x0c0471e0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0471e2;
P_0c0471e2: /* original 6a43, guest PC 0x0c0471e2 */
if(!s->budget--) { s->failed_pc=0x0c0471e2u; return 0; }
r[10]=r[4];
goto P_0c0471e4;
P_0c0471e4: /* original 9111, guest PC 0x0c0471e4 */
if(!s->budget--) { s->failed_pc=0x0c0471e4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04720au,2);
goto P_0c0471e6;
P_0c0471e6: /* original 6463, guest PC 0x0c0471e6 */
if(!s->budget--) { s->failed_pc=0x0c0471e6u; return 0; }
r[4]=r[6];
goto P_0c0471e8;
P_0c0471e8: /* original d00a, guest PC 0x0c0471e8 */
if(!s->budget--) { s->failed_pc=0x0c0471e8u; return 0; }
r[0]=read(ram,0x0c047214u,4);
goto P_0c0471ea;
P_0c0471ea: /* original a019, guest PC 0x0c0471ea */
if(!s->budget--) { s->failed_pc=0x0c0471eau; return 0; }
r[12]=r[6];
goto P_0c047220;
P_0c0471ec: /* original 6c63, guest PC 0x0c0471ec */
if(!s->budget--) { s->failed_pc=0x0c0471ecu; return 0; }
r[12]=r[6];
goto P_0c0471ee;
P_0c0471ee: /* original 63a4, guest PC 0x0c0471ee */
if(!s->budget--) { s->failed_pc=0x0c0471eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[10],1);
r[10]+=1;
r[3]=tmp;
goto P_0c0471f0;
P_0c0471f0: /* original 67b3, guest PC 0x0c0471f0 */
if(!s->budget--) { s->failed_pc=0x0c0471f0u; return 0; }
r[7]=r[11];
goto P_0c0471f2;
P_0c0471f2: /* original 4318, guest PC 0x0c0471f2 */
if(!s->budget--) { s->failed_pc=0x0c0471f2u; return 0; }
r[3]<<=8;
goto P_0c0471f4;
P_0c0471f4: /* original 243a, guest PC 0x0c0471f4 */
if(!s->budget--) { s->failed_pc=0x0c0471f4u; return 0; }
r[4]^=r[3];
goto P_0c0471f6;
P_0c0471f6: /* original 6243, guest PC 0x0c0471f6 */
if(!s->budget--) { s->failed_pc=0x0c0471f6u; return 0; }
r[2]=r[4];
goto P_0c0471f8;
P_0c0471f8: /* original 6643, guest PC 0x0c0471f8 */
if(!s->budget--) { s->failed_pc=0x0c0471f8u; return 0; }
r[6]=r[4];
goto P_0c0471fa;
P_0c0471fa: /* original 4600, guest PC 0x0c0471fa */
if(!s->budget--) { s->failed_pc=0x0c0471fau; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0471fc;
P_0c0471fc: /* original 2208, guest PC 0x0c0471fc */
if(!s->budget--) { s->failed_pc=0x0c0471fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[0])==0)!=0);
goto P_0c0471fe;
P_0c0471fe: /* original 890b, guest PC 0x0c0471fe */
if(!s->budget--) { s->failed_pc=0x0c0471feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c047218; }
goto P_0c047200;
P_0c047200: /* original 6463, guest PC 0x0c047200 */
if(!s->budget--) { s->failed_pc=0x0c047200u; return 0; }
r[4]=r[6];
goto P_0c047202;
P_0c047202: /* original a00a, guest PC 0x0c047202 */
if(!s->budget--) { s->failed_pc=0x0c047202u; return 0; }
r[4]^=r[1];
goto P_0c04721a;
P_0c047204: /* original 241a, guest PC 0x0c047204 */
if(!s->budget--) { s->failed_pc=0x0c047204u; return 0; }
r[4]^=r[1];
return vf3_matrix_family(0x0c047206u,s,ram);
P_0c047218: /* original 6463, guest PC 0x0c047218 */
if(!s->budget--) { s->failed_pc=0x0c047218u; return 0; }
r[4]=r[6];
goto P_0c04721a;
P_0c04721a: /* original 4710, guest PC 0x0c04721a */
if(!s->budget--) { s->failed_pc=0x0c04721au; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c04721c;
P_0c04721c: /* original 8beb, guest PC 0x0c04721c */
if(!s->budget--) { s->failed_pc=0x0c04721cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471f6; }
goto P_0c04721e;
P_0c04721e: /* original 7c01, guest PC 0x0c04721e */
if(!s->budget--) { s->failed_pc=0x0c04721eu; return 0; }
r[12]+=0x00000001u;
goto P_0c047220;
P_0c047220: /* original 3c52, guest PC 0x0c047220 */
if(!s->budget--) { s->failed_pc=0x0c047220u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[5])!=0);
goto P_0c047222;
P_0c047222: /* original 8be4, guest PC 0x0c047222 */
if(!s->budget--) { s->failed_pc=0x0c047222u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0471ee; }
goto P_0c047224;
P_0c047224: /* original 6af6, guest PC 0x0c047224 */
if(!s->budget--) { s->failed_pc=0x0c047224u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c047226;
P_0c047226: /* original 6043, guest PC 0x0c047226 */
if(!s->budget--) { s->failed_pc=0x0c047226u; return 0; }
r[0]=r[4];
goto P_0c047228;
P_0c047228: /* original 6bf6, guest PC 0x0c047228 */
if(!s->budget--) { s->failed_pc=0x0c047228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04722a;
P_0c04722a: /* original 000b, guest PC 0x0c04722a */
if(!s->budget--) { s->failed_pc=0x0c04722au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c04722c: /* original 6cf6, guest PC 0x0c04722c */
if(!s->budget--) { s->failed_pc=0x0c04722cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c04722eu,s,ram);
P_0c0501ea: /* original 2fe6, guest PC 0x0c0501ea */
if(!s->budget--) { s->failed_pc=0x0c0501eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0501ec;
P_0c0501ec: /* original 6e53, guest PC 0x0c0501ec */
if(!s->budget--) { s->failed_pc=0x0c0501ecu; return 0; }
r[14]=r[5];
goto P_0c0501ee;
P_0c0501ee: /* original 2fd6, guest PC 0x0c0501ee */
if(!s->budget--) { s->failed_pc=0x0c0501eeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0501f0;
P_0c0501f0: /* original 6d43, guest PC 0x0c0501f0 */
if(!s->budget--) { s->failed_pc=0x0c0501f0u; return 0; }
r[13]=r[4];
goto P_0c0501f2;
P_0c0501f2: /* original 2f86, guest PC 0x0c0501f2 */
if(!s->budget--) { s->failed_pc=0x0c0501f2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c0501f4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0370fcu,0x0c0370feu,0x0c037100u,0x0c037102u,0x0c037104u,0x0c037106u,0x0c037108u,0x0c03710au,0x0c03710cu,0x0c03710eu,0x0c037110u,0x0c037112u,0x0c037114u,0x0c037116u,0x0c037118u,0x0c03711au,
0x0c03711cu,0x0c03711eu,0x0c037120u,0x0c037122u,0x0c037124u,0x0c037126u,0x0c037128u,0x0c03712au,0x0c03712cu,0x0c03712eu,0x0c037130u,0x0c037132u,0x0c037134u,0x0c037136u,0x0c037138u,0x0c03713au,
0x0c03713cu,0x0c03713eu,0x0c037140u,0x0c037142u,0x0c037144u,0x0c037146u,0x0c037148u,0x0c03714au,0x0c03714cu,0x0c03714eu,0x0c037150u,0x0c037152u,0x0c037154u,0x0c037156u,0x0c037158u,0x0c03715au,
0x0c03715cu,0x0c03715eu,0x0c037160u,0x0c037162u,0x0c037164u,0x0c037166u,0x0c037168u,0x0c03716au,0x0c03716cu,0x0c03716eu,0x0c037170u,0x0c037172u,0x0c037174u,0x0c037176u,0x0c037178u,0x0c03717au,
0x0c03717cu,0x0c03717eu,0x0c037180u,0x0c037182u,0x0c037184u,0x0c037186u,0x0c037188u,0x0c03718au,0x0c03718cu,0x0c03718eu,0x0c037316u,0x0c037318u,0x0c03731au,0x0c03731cu,0x0c03731eu,0x0c037320u,
0x0c037322u,0x0c037324u,0x0c037326u,0x0c037328u,0x0c03732au,0x0c03732cu,0x0c03732eu,0x0c037330u,0x0c037332u,0x0c037334u,0x0c037336u,0x0c037338u,0x0c03733au,0x0c03733cu,0x0c03733eu,0x0c037340u,
0x0c037342u,0x0c037344u,0x0c037346u,0x0c037348u,0x0c03734au,0x0c03734cu,0x0c03734eu,0x0c037350u,0x0c0376e0u,0x0c0376e2u,0x0c0376e4u,0x0c0376e6u,0x0c0376e8u,0x0c0376eau,0x0c0376ecu,0x0c0376eeu,
0x0c0376f0u,0x0c0376f2u,0x0c0376f4u,0x0c0376f6u,0x0c0376f8u,0x0c0376fau,0x0c0376fcu,0x0c0376feu,0x0c037700u,0x0c037702u,0x0c037704u,0x0c037706u,0x0c037708u,0x0c03770au,0x0c03770cu,0x0c03770eu,
0x0c037710u,0x0c037712u,0x0c037714u,0x0c037716u,0x0c037718u,0x0c03771au,0x0c03771cu,0x0c03771eu,0x0c037720u,0x0c037722u,0x0c037724u,0x0c037726u,0x0c037728u,0x0c037788u,0x0c03778au,0x0c03778cu,
0x0c044068u,0x0c04406au,0x0c04406cu,0x0c04406eu,0x0c044070u,0x0c044072u,0x0c044074u,0x0c044076u,0x0c044078u,0x0c04407au,0x0c04407cu,0x0c04407eu,0x0c044080u,0x0c044082u,0x0c044084u,0x0c044086u,
0x0c044088u,0x0c04408au,0x0c04408cu,0x0c04408eu,0x0c044090u,0x0c044092u,0x0c044094u,0x0c044096u,0x0c044098u,0x0c04409au,0x0c045c2au,0x0c045c2cu,0x0c045c2eu,0x0c045c30u,0x0c045c32u,0x0c045c34u,
0x0c045c36u,0x0c045c38u,0x0c045c3au,0x0c045c3cu,0x0c045c3eu,0x0c045c40u,0x0c045c42u,0x0c045c44u,0x0c045c46u,0x0c045c48u,0x0c045c4au,0x0c045c4cu,0x0c045c4eu,0x0c045c50u,0x0c045c52u,0x0c045c54u,
0x0c045c56u,0x0c045c58u,0x0c045c5au,0x0c045c5cu,0x0c045c5eu,0x0c045c60u,0x0c045c62u,0x0c045c80u,0x0c045c82u,0x0c04667au,0x0c04667cu,0x0c04667eu,0x0c046680u,0x0c046682u,0x0c046684u,0x0c046686u,
0x0c046688u,0x0c04668au,0x0c04668cu,0x0c04668eu,0x0c046690u,0x0c046692u,0x0c046694u,0x0c046696u,0x0c046698u,0x0c04669au,0x0c04669cu,0x0c04669eu,0x0c04708cu,0x0c04708eu,0x0c047090u,0x0c047092u,
0x0c047094u,0x0c047096u,0x0c047098u,0x0c04709au,0x0c04709cu,0x0c04709eu,0x0c0470a0u,0x0c0470a2u,0x0c0470a4u,0x0c0470a6u,0x0c0470a8u,0x0c0470aau,0x0c0470acu,0x0c0470aeu,0x0c0470b0u,0x0c0470b2u,
0x0c0470b4u,0x0c0470b6u,0x0c0470b8u,0x0c0470bau,0x0c0470bcu,0x0c0470beu,0x0c0470d8u,0x0c0470dau,0x0c0470dcu,0x0c0470deu,0x0c0470e0u,0x0c0470e2u,0x0c0470e4u,0x0c0470e6u,0x0c0470e8u,0x0c0470eau,
0x0c0470ecu,0x0c0470eeu,0x0c0470f0u,0x0c0470f2u,0x0c0470f4u,0x0c0470f6u,0x0c0470f8u,0x0c0470fau,0x0c0470fcu,0x0c0470feu,0x0c047100u,0x0c047102u,0x0c047104u,0x0c047106u,0x0c047108u,0x0c04710au,
0x0c04710cu,0x0c04710eu,0x0c047110u,0x0c047112u,0x0c047114u,0x0c047116u,0x0c047118u,0x0c04711au,0x0c04711cu,0x0c04711eu,0x0c047120u,0x0c047122u,0x0c047124u,0x0c047126u,0x0c047128u,0x0c04712au,
0x0c04712cu,0x0c04712eu,0x0c047130u,0x0c047132u,0x0c047134u,0x0c047136u,0x0c047138u,0x0c04713au,0x0c04713cu,0x0c04713eu,0x0c047140u,0x0c047142u,0x0c047144u,0x0c047146u,0x0c047148u,0x0c04714au,
0x0c04714cu,0x0c04714eu,0x0c047150u,0x0c047152u,0x0c047154u,0x0c047156u,0x0c047158u,0x0c04715au,0x0c04715cu,0x0c04715eu,0x0c047160u,0x0c047162u,0x0c047164u,0x0c047166u,0x0c047168u,0x0c04716au,
0x0c04716cu,0x0c04716eu,0x0c047170u,0x0c047172u,0x0c047174u,0x0c047176u,0x0c047178u,0x0c04717au,0x0c04717cu,0x0c04717eu,0x0c047180u,0x0c047182u,0x0c047184u,0x0c047186u,0x0c047188u,0x0c04718au,
0x0c04718cu,0x0c04718eu,0x0c047190u,0x0c047192u,0x0c047194u,0x0c047196u,0x0c047198u,0x0c04719au,0x0c04719cu,0x0c04719eu,0x0c0471a0u,0x0c0471a2u,0x0c0471a4u,0x0c0471a6u,0x0c0471a8u,0x0c0471aau,
0x0c0471acu,0x0c0471aeu,0x0c0471b0u,0x0c0471b2u,0x0c0471b4u,0x0c0471b6u,0x0c0471b8u,0x0c0471bau,0x0c0471bcu,0x0c0471beu,0x0c0471c0u,0x0c0471c2u,0x0c0471c4u,0x0c0471c6u,0x0c0471c8u,0x0c0471cau,
0x0c0471ccu,0x0c0471ceu,0x0c0471d0u,0x0c0471d2u,0x0c0471d4u,0x0c0471d6u,0x0c0471d8u,0x0c0471dau,0x0c0471dcu,0x0c0471deu,0x0c0471e0u,0x0c0471e2u,0x0c0471e4u,0x0c0471e6u,0x0c0471e8u,0x0c0471eau,
0x0c0471ecu,0x0c0471eeu,0x0c0471f0u,0x0c0471f2u,0x0c0471f4u,0x0c0471f6u,0x0c0471f8u,0x0c0471fau,0x0c0471fcu,0x0c0471feu,0x0c047200u,0x0c047202u,0x0c047204u,0x0c047218u,0x0c04721au,0x0c04721cu,
0x0c04721eu,0x0c047220u,0x0c047222u,0x0c047224u,0x0c047226u,0x0c047228u,0x0c04722au,0x0c04722cu,0x0c0501eau,0x0c0501ecu,0x0c0501eeu,0x0c0501f0u,0x0c0501f2u,
};
int vf3_target_record_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
