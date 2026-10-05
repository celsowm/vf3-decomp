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
int vf3_target_family_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0371f8u: goto P_0c0371f8;
case 0x0c0371fau: goto P_0c0371fa;
case 0x0c0371fcu: goto P_0c0371fc;
case 0x0c037240u: goto P_0c037240;
case 0x0c037242u: goto P_0c037242;
case 0x0c037244u: goto P_0c037244;
case 0x0c037246u: goto P_0c037246;
case 0x0c03c720u: goto P_0c03c720;
case 0x0c03c722u: goto P_0c03c722;
case 0x0c03c724u: goto P_0c03c724;
case 0x0c03c726u: goto P_0c03c726;
case 0x0c03c728u: goto P_0c03c728;
case 0x0c03c72au: goto P_0c03c72a;
case 0x0c03c72cu: goto P_0c03c72c;
case 0x0c03c72eu: goto P_0c03c72e;
case 0x0c03c730u: goto P_0c03c730;
case 0x0c03c732u: goto P_0c03c732;
case 0x0c03c734u: goto P_0c03c734;
case 0x0c03c736u: goto P_0c03c736;
case 0x0c03c738u: goto P_0c03c738;
case 0x0c03c73au: goto P_0c03c73a;
case 0x0c03c73cu: goto P_0c03c73c;
case 0x0c03c73eu: goto P_0c03c73e;
case 0x0c03c740u: goto P_0c03c740;
case 0x0c03c750u: goto P_0c03c750;
case 0x0c03c752u: goto P_0c03c752;
case 0x0c03c754u: goto P_0c03c754;
case 0x0c03c756u: goto P_0c03c756;
case 0x0c03c758u: goto P_0c03c758;
case 0x0c03c75au: goto P_0c03c75a;
case 0x0c03c75cu: goto P_0c03c75c;
case 0x0c03c75eu: goto P_0c03c75e;
case 0x0c03c760u: goto P_0c03c760;
case 0x0c03c762u: goto P_0c03c762;
case 0x0c03c764u: goto P_0c03c764;
case 0x0c03c766u: goto P_0c03c766;
case 0x0c03c768u: goto P_0c03c768;
case 0x0c03c76au: goto P_0c03c76a;
case 0x0c03c76cu: goto P_0c03c76c;
case 0x0c03c76eu: goto P_0c03c76e;
case 0x0c03c770u: goto P_0c03c770;
case 0x0c03c772u: goto P_0c03c772;
case 0x0c03c774u: goto P_0c03c774;
case 0x0c03c776u: goto P_0c03c776;
case 0x0c03c778u: goto P_0c03c778;
case 0x0c03c77au: goto P_0c03c77a;
case 0x0c03c77cu: goto P_0c03c77c;
case 0x0c03c77eu: goto P_0c03c77e;
case 0x0c03c780u: goto P_0c03c780;
case 0x0c03c782u: goto P_0c03c782;
case 0x0c03c784u: goto P_0c03c784;
case 0x0c03c786u: goto P_0c03c786;
case 0x0c03c788u: goto P_0c03c788;
case 0x0c03c78au: goto P_0c03c78a;
case 0x0c03c78cu: goto P_0c03c78c;
case 0x0c03c78eu: goto P_0c03c78e;
case 0x0c03c790u: goto P_0c03c790;
case 0x0c03c792u: goto P_0c03c792;
case 0x0c03c794u: goto P_0c03c794;
case 0x0c03c796u: goto P_0c03c796;
case 0x0c03c798u: goto P_0c03c798;
case 0x0c03c79au: goto P_0c03c79a;
case 0x0c03c79cu: goto P_0c03c79c;
case 0x0c03c79eu: goto P_0c03c79e;
case 0x0c03c7a0u: goto P_0c03c7a0;
case 0x0c03c7a2u: goto P_0c03c7a2;
case 0x0c03c7a4u: goto P_0c03c7a4;
case 0x0c03c7a6u: goto P_0c03c7a6;
case 0x0c03c7a8u: goto P_0c03c7a8;
case 0x0c03c7aau: goto P_0c03c7aa;
case 0x0c03c7acu: goto P_0c03c7ac;
case 0x0c03c7aeu: goto P_0c03c7ae;
case 0x0c03c7b0u: goto P_0c03c7b0;
case 0x0c03c7b2u: goto P_0c03c7b2;
case 0x0c03c7b4u: goto P_0c03c7b4;
case 0x0c03c7b6u: goto P_0c03c7b6;
case 0x0c03c7b8u: goto P_0c03c7b8;
case 0x0c03c7bau: goto P_0c03c7ba;
case 0x0c03c7bcu: goto P_0c03c7bc;
case 0x0c03c7beu: goto P_0c03c7be;
case 0x0c03c7c0u: goto P_0c03c7c0;
case 0x0c03c7c2u: goto P_0c03c7c2;
case 0x0c03c7c4u: goto P_0c03c7c4;
case 0x0c03c7c6u: goto P_0c03c7c6;
case 0x0c03c7c8u: goto P_0c03c7c8;
case 0x0c03c7cau: goto P_0c03c7ca;
case 0x0c03c7ccu: goto P_0c03c7cc;
case 0x0c03c7ceu: goto P_0c03c7ce;
case 0x0c03c7d0u: goto P_0c03c7d0;
case 0x0c03c7d2u: goto P_0c03c7d2;
case 0x0c03c7d4u: goto P_0c03c7d4;
case 0x0c03c7d6u: goto P_0c03c7d6;
case 0x0c03c7d8u: goto P_0c03c7d8;
case 0x0c03c7dau: goto P_0c03c7da;
case 0x0c03c7dcu: goto P_0c03c7dc;
case 0x0c03c7deu: goto P_0c03c7de;
case 0x0c03c7e0u: goto P_0c03c7e0;
case 0x0c03c7e2u: goto P_0c03c7e2;
case 0x0c03c7e4u: goto P_0c03c7e4;
case 0x0c03c7e6u: goto P_0c03c7e6;
case 0x0c03c7e8u: goto P_0c03c7e8;
case 0x0c03c7eau: goto P_0c03c7ea;
case 0x0c03c7ecu: goto P_0c03c7ec;
case 0x0c03c7eeu: goto P_0c03c7ee;
case 0x0c03c7f0u: goto P_0c03c7f0;
case 0x0c03c7f2u: goto P_0c03c7f2;
case 0x0c03c7f4u: goto P_0c03c7f4;
case 0x0c03c7f6u: goto P_0c03c7f6;
case 0x0c03c7f8u: goto P_0c03c7f8;
case 0x0c03c7fau: goto P_0c03c7fa;
case 0x0c03c7fcu: goto P_0c03c7fc;
case 0x0c03c7feu: goto P_0c03c7fe;
case 0x0c03c800u: goto P_0c03c800;
case 0x0c03c802u: goto P_0c03c802;
case 0x0c03c804u: goto P_0c03c804;
case 0x0c03c806u: goto P_0c03c806;
case 0x0c03c808u: goto P_0c03c808;
case 0x0c03c80au: goto P_0c03c80a;
case 0x0c03c80cu: goto P_0c03c80c;
case 0x0c03c80eu: goto P_0c03c80e;
case 0x0c03c810u: goto P_0c03c810;
case 0x0c03c812u: goto P_0c03c812;
case 0x0c0424d0u: goto P_0c0424d0;
case 0x0c0424d2u: goto P_0c0424d2;
case 0x0c0424d4u: goto P_0c0424d4;
case 0x0c0424d6u: goto P_0c0424d6;
case 0x0c0424d8u: goto P_0c0424d8;
case 0x0c0424dau: goto P_0c0424da;
case 0x0c0424dcu: goto P_0c0424dc;
case 0x0c0424deu: goto P_0c0424de;
case 0x0c0424e0u: goto P_0c0424e0;
case 0x0c0424e2u: goto P_0c0424e2;
case 0x0c0424e4u: goto P_0c0424e4;
case 0x0c0424e6u: goto P_0c0424e6;
case 0x0c0424e8u: goto P_0c0424e8;
case 0x0c0424eau: goto P_0c0424ea;
case 0x0c0424ecu: goto P_0c0424ec;
case 0x0c0424eeu: goto P_0c0424ee;
case 0x0c0424f0u: goto P_0c0424f0;
case 0x0c0424f2u: goto P_0c0424f2;
case 0x0c0424f4u: goto P_0c0424f4;
case 0x0c0424f6u: goto P_0c0424f6;
case 0x0c0424f8u: goto P_0c0424f8;
case 0x0c0424fau: goto P_0c0424fa;
case 0x0c0424fcu: goto P_0c0424fc;
case 0x0c0424feu: goto P_0c0424fe;
case 0x0c042500u: goto P_0c042500;
case 0x0c042502u: goto P_0c042502;
case 0x0c042504u: goto P_0c042504;
case 0x0c042506u: goto P_0c042506;
case 0x0c042508u: goto P_0c042508;
case 0x0c04250au: goto P_0c04250a;
case 0x0c04250cu: goto P_0c04250c;
case 0x0c04250eu: goto P_0c04250e;
case 0x0c042510u: goto P_0c042510;
case 0x0c042512u: goto P_0c042512;
case 0x0c042514u: goto P_0c042514;
case 0x0c042516u: goto P_0c042516;
case 0x0c042518u: goto P_0c042518;
case 0x0c04251au: goto P_0c04251a;
case 0x0c04251cu: goto P_0c04251c;
case 0x0c04251eu: goto P_0c04251e;
case 0x0c042520u: goto P_0c042520;
case 0x0c042522u: goto P_0c042522;
case 0x0c042524u: goto P_0c042524;
case 0x0c042526u: goto P_0c042526;
case 0x0c042528u: goto P_0c042528;
case 0x0c04252au: goto P_0c04252a;
case 0x0c04252cu: goto P_0c04252c;
case 0x0c04252eu: goto P_0c04252e;
case 0x0c042530u: goto P_0c042530;
case 0x0c042532u: goto P_0c042532;
case 0x0c042534u: goto P_0c042534;
case 0x0c042536u: goto P_0c042536;
case 0x0c042538u: goto P_0c042538;
case 0x0c04253au: goto P_0c04253a;
case 0x0c04253cu: goto P_0c04253c;
case 0x0c04253eu: goto P_0c04253e;
case 0x0c042540u: goto P_0c042540;
case 0x0c042542u: goto P_0c042542;
case 0x0c042544u: goto P_0c042544;
case 0x0c042546u: goto P_0c042546;
case 0x0c042548u: goto P_0c042548;
case 0x0c04254au: goto P_0c04254a;
case 0x0c04254cu: goto P_0c04254c;
case 0x0c04254eu: goto P_0c04254e;
case 0x0c042550u: goto P_0c042550;
case 0x0c042552u: goto P_0c042552;
case 0x0c042554u: goto P_0c042554;
case 0x0c042556u: goto P_0c042556;
case 0x0c042558u: goto P_0c042558;
case 0x0c04255au: goto P_0c04255a;
case 0x0c04255cu: goto P_0c04255c;
case 0x0c04255eu: goto P_0c04255e;
case 0x0c042560u: goto P_0c042560;
case 0x0c042562u: goto P_0c042562;
case 0x0c042564u: goto P_0c042564;
case 0x0c042566u: goto P_0c042566;
case 0x0c042568u: goto P_0c042568;
case 0x0c04256au: goto P_0c04256a;
case 0x0c04256cu: goto P_0c04256c;
case 0x0c04256eu: goto P_0c04256e;
case 0x0c042570u: goto P_0c042570;
case 0x0c042572u: goto P_0c042572;
case 0x0c042574u: goto P_0c042574;
case 0x0c042576u: goto P_0c042576;
case 0x0c042578u: goto P_0c042578;
case 0x0c04257au: goto P_0c04257a;
case 0x0c04257cu: goto P_0c04257c;
case 0x0c04257eu: goto P_0c04257e;
case 0x0c042580u: goto P_0c042580;
case 0x0c042582u: goto P_0c042582;
case 0x0c042584u: goto P_0c042584;
case 0x0c042586u: goto P_0c042586;
case 0x0c042588u: goto P_0c042588;
case 0x0c04258au: goto P_0c04258a;
case 0x0c04258cu: goto P_0c04258c;
case 0x0c04258eu: goto P_0c04258e;
case 0x0c042590u: goto P_0c042590;
case 0x0c042592u: goto P_0c042592;
case 0x0c042594u: goto P_0c042594;
case 0x0c042596u: goto P_0c042596;
case 0x0c042598u: goto P_0c042598;
case 0x0c04259au: goto P_0c04259a;
case 0x0c04259cu: goto P_0c04259c;
case 0x0c04259eu: goto P_0c04259e;
case 0x0c0425a0u: goto P_0c0425a0;
case 0x0c0425a2u: goto P_0c0425a2;
case 0x0c0425a4u: goto P_0c0425a4;
case 0x0c0425a6u: goto P_0c0425a6;
case 0x0c0425a8u: goto P_0c0425a8;
case 0x0c0425aau: goto P_0c0425aa;
case 0x0c0425acu: goto P_0c0425ac;
case 0x0c0425aeu: goto P_0c0425ae;
case 0x0c0425b0u: goto P_0c0425b0;
case 0x0c0425b2u: goto P_0c0425b2;
case 0x0c0425b4u: goto P_0c0425b4;
case 0x0c0425b6u: goto P_0c0425b6;
case 0x0c0425b8u: goto P_0c0425b8;
case 0x0c0425bau: goto P_0c0425ba;
case 0x0c0425bcu: goto P_0c0425bc;
case 0x0c0425beu: goto P_0c0425be;
case 0x0c0425c0u: goto P_0c0425c0;
case 0x0c0425c2u: goto P_0c0425c2;
case 0x0c0425c4u: goto P_0c0425c4;
case 0x0c0425c6u: goto P_0c0425c6;
case 0x0c0425c8u: goto P_0c0425c8;
case 0x0c0425cau: goto P_0c0425ca;
case 0x0c0425ccu: goto P_0c0425cc;
case 0x0c0425ceu: goto P_0c0425ce;
case 0x0c0425d0u: goto P_0c0425d0;
case 0x0c0425d2u: goto P_0c0425d2;
case 0x0c0425d4u: goto P_0c0425d4;
case 0x0c0425d6u: goto P_0c0425d6;
case 0x0c0425d8u: goto P_0c0425d8;
case 0x0c0425dau: goto P_0c0425da;
case 0x0c0425dcu: goto P_0c0425dc;
case 0x0c0425deu: goto P_0c0425de;
case 0x0c0425e0u: goto P_0c0425e0;
case 0x0c0425e2u: goto P_0c0425e2;
case 0x0c0425e4u: goto P_0c0425e4;
case 0x0c0425e6u: goto P_0c0425e6;
case 0x0c0425e8u: goto P_0c0425e8;
case 0x0c0425eau: goto P_0c0425ea;
case 0x0c0425ecu: goto P_0c0425ec;
case 0x0c0425eeu: goto P_0c0425ee;
case 0x0c0425f0u: goto P_0c0425f0;
case 0x0c0425f2u: goto P_0c0425f2;
case 0x0c0425f4u: goto P_0c0425f4;
case 0x0c0425f6u: goto P_0c0425f6;
case 0x0c0425f8u: goto P_0c0425f8;
case 0x0c0425fau: goto P_0c0425fa;
case 0x0c0425fcu: goto P_0c0425fc;
case 0x0c042660u: goto P_0c042660;
case 0x0c042662u: goto P_0c042662;
case 0x0c042664u: goto P_0c042664;
case 0x0c042666u: goto P_0c042666;
case 0x0c042668u: goto P_0c042668;
case 0x0c04266au: goto P_0c04266a;
case 0x0c04266cu: goto P_0c04266c;
case 0x0c04266eu: goto P_0c04266e;
case 0x0c042670u: goto P_0c042670;
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
case 0x0c042790u: goto P_0c042790;
case 0x0c042792u: goto P_0c042792;
case 0x0c042794u: goto P_0c042794;
case 0x0c042796u: goto P_0c042796;
case 0x0c042798u: goto P_0c042798;
case 0x0c04279au: goto P_0c04279a;
case 0x0c04279cu: goto P_0c04279c;
case 0x0c04279eu: goto P_0c04279e;
case 0x0c0427a0u: goto P_0c0427a0;
case 0x0c0427a2u: goto P_0c0427a2;
case 0x0c0427b0u: goto P_0c0427b0;
case 0x0c0427b2u: goto P_0c0427b2;
case 0x0c0427b4u: goto P_0c0427b4;
case 0x0c0427b6u: goto P_0c0427b6;
case 0x0c0427b8u: goto P_0c0427b8;
case 0x0c0427bau: goto P_0c0427ba;
case 0x0c0427bcu: goto P_0c0427bc;
case 0x0c0427beu: goto P_0c0427be;
case 0x0c0427c0u: goto P_0c0427c0;
case 0x0c0427c2u: goto P_0c0427c2;
case 0x0c0427c4u: goto P_0c0427c4;
case 0x0c0427c6u: goto P_0c0427c6;
case 0x0c0427c8u: goto P_0c0427c8;
case 0x0c0427d0u: goto P_0c0427d0;
case 0x0c0427d2u: goto P_0c0427d2;
case 0x0c0427d4u: goto P_0c0427d4;
case 0x0c0427d6u: goto P_0c0427d6;
case 0x0c0427e0u: goto P_0c0427e0;
case 0x0c0427e2u: goto P_0c0427e2;
case 0x0c0427e4u: goto P_0c0427e4;
case 0x0c0427e6u: goto P_0c0427e6;
case 0x0c0427e8u: goto P_0c0427e8;
case 0x0c0427eau: goto P_0c0427ea;
case 0x0c0427ecu: goto P_0c0427ec;
case 0x0c0427eeu: goto P_0c0427ee;
case 0x0c0427f0u: goto P_0c0427f0;
case 0x0c042800u: goto P_0c042800;
case 0x0c042802u: goto P_0c042802;
case 0x0c042804u: goto P_0c042804;
case 0x0c042806u: goto P_0c042806;
case 0x0c042810u: goto P_0c042810;
case 0x0c042812u: goto P_0c042812;
case 0x0c042814u: goto P_0c042814;
case 0x0c042816u: goto P_0c042816;
case 0x0c042818u: goto P_0c042818;
case 0x0c04281au: goto P_0c04281a;
case 0x0c04281cu: goto P_0c04281c;
case 0x0c04281eu: goto P_0c04281e;
case 0x0c042820u: goto P_0c042820;
case 0x0c042822u: goto P_0c042822;
case 0x0c042824u: goto P_0c042824;
case 0x0c042840u: goto P_0c042840;
case 0x0c042842u: goto P_0c042842;
case 0x0c042844u: goto P_0c042844;
case 0x0c042846u: goto P_0c042846;
case 0x0c042848u: goto P_0c042848;
case 0x0c04284au: goto P_0c04284a;
case 0x0c04284cu: goto P_0c04284c;
case 0x0c04284eu: goto P_0c04284e;
case 0x0c042850u: goto P_0c042850;
case 0x0c042852u: goto P_0c042852;
case 0x0c042854u: goto P_0c042854;
case 0x0c042856u: goto P_0c042856;
case 0x0c042858u: goto P_0c042858;
case 0x0c04285au: goto P_0c04285a;
case 0x0c04285cu: goto P_0c04285c;
case 0x0c04285eu: goto P_0c04285e;
case 0x0c042860u: goto P_0c042860;
case 0x0c042862u: goto P_0c042862;
case 0x0c042864u: goto P_0c042864;
case 0x0c042866u: goto P_0c042866;
case 0x0c042868u: goto P_0c042868;
case 0x0c04286au: goto P_0c04286a;
case 0x0c04286cu: goto P_0c04286c;
case 0x0c04286eu: goto P_0c04286e;
case 0x0c042870u: goto P_0c042870;
case 0x0c042872u: goto P_0c042872;
case 0x0c042874u: goto P_0c042874;
case 0x0c042876u: goto P_0c042876;
case 0x0c042878u: goto P_0c042878;
case 0x0c04287au: goto P_0c04287a;
case 0x0c04287cu: goto P_0c04287c;
case 0x0c042880u: goto P_0c042880;
case 0x0c042882u: goto P_0c042882;
case 0x0c042884u: goto P_0c042884;
case 0x0c042886u: goto P_0c042886;
case 0x0c042888u: goto P_0c042888;
case 0x0c04288au: goto P_0c04288a;
case 0x0c04288cu: goto P_0c04288c;
case 0x0c04288eu: goto P_0c04288e;
case 0x0c042890u: goto P_0c042890;
case 0x0c042892u: goto P_0c042892;
case 0x0c042894u: goto P_0c042894;
case 0x0c042896u: goto P_0c042896;
case 0x0c042898u: goto P_0c042898;
case 0x0c04289au: goto P_0c04289a;
case 0x0c04289cu: goto P_0c04289c;
case 0x0c04289eu: goto P_0c04289e;
case 0x0c0428a0u: goto P_0c0428a0;
case 0x0c0428a2u: goto P_0c0428a2;
case 0x0c0428a4u: goto P_0c0428a4;
case 0x0c0428a6u: goto P_0c0428a6;
case 0x0c0428a8u: goto P_0c0428a8;
case 0x0c0428aau: goto P_0c0428aa;
case 0x0c0428acu: goto P_0c0428ac;
case 0x0c0428aeu: goto P_0c0428ae;
case 0x0c0428b0u: goto P_0c0428b0;
case 0x0c0428b2u: goto P_0c0428b2;
case 0x0c0428b4u: goto P_0c0428b4;
case 0x0c0428b6u: goto P_0c0428b6;
case 0x0c0428b8u: goto P_0c0428b8;
case 0x0c0428bau: goto P_0c0428ba;
case 0x0c0428bcu: goto P_0c0428bc;
case 0x0c0428beu: goto P_0c0428be;
case 0x0c0428c0u: goto P_0c0428c0;
case 0x0c0428d0u: goto P_0c0428d0;
case 0x0c0428d2u: goto P_0c0428d2;
case 0x0c0428d4u: goto P_0c0428d4;
case 0x0c0428d6u: goto P_0c0428d6;
case 0x0c0428d8u: goto P_0c0428d8;
case 0x0c0428dau: goto P_0c0428da;
case 0x0c0428dcu: goto P_0c0428dc;
case 0x0c0428deu: goto P_0c0428de;
case 0x0c0428e0u: goto P_0c0428e0;
case 0x0c0428e2u: goto P_0c0428e2;
case 0x0c0428e4u: goto P_0c0428e4;
case 0x0c0428e6u: goto P_0c0428e6;
case 0x0c0428e8u: goto P_0c0428e8;
case 0x0c0428eau: goto P_0c0428ea;
case 0x0c0428ecu: goto P_0c0428ec;
case 0x0c0428eeu: goto P_0c0428ee;
case 0x0c0428f0u: goto P_0c0428f0;
case 0x0c0428f2u: goto P_0c0428f2;
case 0x0c042900u: goto P_0c042900;
case 0x0c042902u: goto P_0c042902;
case 0x0c042904u: goto P_0c042904;
case 0x0c042906u: goto P_0c042906;
case 0x0c042908u: goto P_0c042908;
case 0x0c04290au: goto P_0c04290a;
case 0x0c04290cu: goto P_0c04290c;
case 0x0c04290eu: goto P_0c04290e;
case 0x0c042910u: goto P_0c042910;
case 0x0c042912u: goto P_0c042912;
case 0x0c042914u: goto P_0c042914;
case 0x0c042930u: goto P_0c042930;
case 0x0c042932u: goto P_0c042932;
case 0x0c042934u: goto P_0c042934;
case 0x0c042936u: goto P_0c042936;
case 0x0c042938u: goto P_0c042938;
case 0x0c04293au: goto P_0c04293a;
case 0x0c04293cu: goto P_0c04293c;
case 0x0c04293eu: goto P_0c04293e;
case 0x0c042940u: goto P_0c042940;
case 0x0c042942u: goto P_0c042942;
case 0x0c042944u: goto P_0c042944;
case 0x0c042946u: goto P_0c042946;
case 0x0c042948u: goto P_0c042948;
case 0x0c04294au: goto P_0c04294a;
case 0x0c042960u: goto P_0c042960;
case 0x0c042962u: goto P_0c042962;
case 0x0c042964u: goto P_0c042964;
case 0x0c042970u: goto P_0c042970;
case 0x0c042972u: goto P_0c042972;
case 0x0c042974u: goto P_0c042974;
case 0x0c0429b0u: goto P_0c0429b0;
case 0x0c0429b2u: goto P_0c0429b2;
case 0x0c0429b4u: goto P_0c0429b4;
case 0x0c0429b6u: goto P_0c0429b6;
case 0x0c0429b8u: goto P_0c0429b8;
case 0x0c0429bau: goto P_0c0429ba;
case 0x0c0429bcu: goto P_0c0429bc;
case 0x0c0429beu: goto P_0c0429be;
case 0x0c0429c0u: goto P_0c0429c0;
case 0x0c0429c2u: goto P_0c0429c2;
case 0x0c0429c4u: goto P_0c0429c4;
case 0x0c0429c6u: goto P_0c0429c6;
case 0x0c0429c8u: goto P_0c0429c8;
case 0x0c0429cau: goto P_0c0429ca;
case 0x0c0429ccu: goto P_0c0429cc;
case 0x0c0429ceu: goto P_0c0429ce;
case 0x0c0429d0u: goto P_0c0429d0;
case 0x0c0429d2u: goto P_0c0429d2;
case 0x0c0429d4u: goto P_0c0429d4;
case 0x0c0429d6u: goto P_0c0429d6;
case 0x0c0429d8u: goto P_0c0429d8;
case 0x0c0429dau: goto P_0c0429da;
case 0x0c0429dcu: goto P_0c0429dc;
case 0x0c0429deu: goto P_0c0429de;
case 0x0c0429e0u: goto P_0c0429e0;
case 0x0c0429e2u: goto P_0c0429e2;
case 0x0c0429e4u: goto P_0c0429e4;
case 0x0c0429e6u: goto P_0c0429e6;
case 0x0c0429e8u: goto P_0c0429e8;
case 0x0c0429eau: goto P_0c0429ea;
case 0x0c0429ecu: goto P_0c0429ec;
case 0x0c0429eeu: goto P_0c0429ee;
case 0x0c0429f0u: goto P_0c0429f0;
case 0x0c0429f2u: goto P_0c0429f2;
case 0x0c0429f4u: goto P_0c0429f4;
case 0x0c0429f6u: goto P_0c0429f6;
case 0x0c0429f8u: goto P_0c0429f8;
case 0x0c0429fau: goto P_0c0429fa;
case 0x0c0429fcu: goto P_0c0429fc;
case 0x0c0429feu: goto P_0c0429fe;
case 0x0c042a00u: goto P_0c042a00;
case 0x0c042a02u: goto P_0c042a02;
case 0x0c042a04u: goto P_0c042a04;
case 0x0c042a06u: goto P_0c042a06;
case 0x0c042a08u: goto P_0c042a08;
case 0x0c042a0au: goto P_0c042a0a;
case 0x0c042a0cu: goto P_0c042a0c;
case 0x0c042a0eu: goto P_0c042a0e;
case 0x0c042a10u: goto P_0c042a10;
case 0x0c042a12u: goto P_0c042a12;
case 0x0c042a14u: goto P_0c042a14;
case 0x0c042a16u: goto P_0c042a16;
case 0x0c042a18u: goto P_0c042a18;
case 0x0c042a1au: goto P_0c042a1a;
case 0x0c042a1cu: goto P_0c042a1c;
case 0x0c042a1eu: goto P_0c042a1e;
case 0x0c042a20u: goto P_0c042a20;
case 0x0c042a22u: goto P_0c042a22;
case 0x0c042a24u: goto P_0c042a24;
case 0x0c042a26u: goto P_0c042a26;
case 0x0c042a28u: goto P_0c042a28;
case 0x0c042a2au: goto P_0c042a2a;
case 0x0c042a2cu: goto P_0c042a2c;
case 0x0c042a2eu: goto P_0c042a2e;
case 0x0c042a30u: goto P_0c042a30;
case 0x0c042a32u: goto P_0c042a32;
case 0x0c042a34u: goto P_0c042a34;
case 0x0c042a36u: goto P_0c042a36;
case 0x0c042a38u: goto P_0c042a38;
case 0x0c042a3au: goto P_0c042a3a;
case 0x0c042a3cu: goto P_0c042a3c;
case 0x0c042a3eu: goto P_0c042a3e;
case 0x0c042ae0u: goto P_0c042ae0;
case 0x0c042ae2u: goto P_0c042ae2;
case 0x0c042ae4u: goto P_0c042ae4;
case 0x0c042ae6u: goto P_0c042ae6;
case 0x0c042ae8u: goto P_0c042ae8;
case 0x0c042aeau: goto P_0c042aea;
case 0x0c042aecu: goto P_0c042aec;
case 0x0c042aeeu: goto P_0c042aee;
case 0x0c042af0u: goto P_0c042af0;
case 0x0c042af2u: goto P_0c042af2;
case 0x0c042af4u: goto P_0c042af4;
case 0x0c042af6u: goto P_0c042af6;
case 0x0c042af8u: goto P_0c042af8;
case 0x0c042afau: goto P_0c042afa;
case 0x0c042afcu: goto P_0c042afc;
case 0x0c042afeu: goto P_0c042afe;
case 0x0c042b00u: goto P_0c042b00;
case 0x0c042b02u: goto P_0c042b02;
case 0x0c042b04u: goto P_0c042b04;
case 0x0c042b06u: goto P_0c042b06;
case 0x0c042b10u: goto P_0c042b10;
case 0x0c042b12u: goto P_0c042b12;
case 0x0c042b14u: goto P_0c042b14;
case 0x0c042b16u: goto P_0c042b16;
case 0x0c042b18u: goto P_0c042b18;
case 0x0c042b1au: goto P_0c042b1a;
case 0x0c042b1cu: goto P_0c042b1c;
case 0x0c042b1eu: goto P_0c042b1e;
case 0x0c042b20u: goto P_0c042b20;
case 0x0c042b22u: goto P_0c042b22;
case 0x0c042b24u: goto P_0c042b24;
case 0x0c042b26u: goto P_0c042b26;
case 0x0c042b30u: goto P_0c042b30;
case 0x0c042b32u: goto P_0c042b32;
case 0x0c042b34u: goto P_0c042b34;
case 0x0c042b36u: goto P_0c042b36;
case 0x0c042b38u: goto P_0c042b38;
case 0x0c042b3au: goto P_0c042b3a;
case 0x0c042b40u: goto P_0c042b40;
case 0x0c042b42u: goto P_0c042b42;
case 0x0c042b44u: goto P_0c042b44;
case 0x0c042b46u: goto P_0c042b46;
case 0x0c042b48u: goto P_0c042b48;
case 0x0c042b4au: goto P_0c042b4a;
case 0x0c042b4cu: goto P_0c042b4c;
case 0x0c042b4eu: goto P_0c042b4e;
case 0x0c042b50u: goto P_0c042b50;
case 0x0c042b52u: goto P_0c042b52;
case 0x0c042b54u: goto P_0c042b54;
case 0x0c042b56u: goto P_0c042b56;
case 0x0c042b58u: goto P_0c042b58;
case 0x0c042b5au: goto P_0c042b5a;
case 0x0c042b5cu: goto P_0c042b5c;
case 0x0c042b5eu: goto P_0c042b5e;
case 0x0c042b60u: goto P_0c042b60;
case 0x0c042b62u: goto P_0c042b62;
case 0x0c042b64u: goto P_0c042b64;
case 0x0c042b70u: goto P_0c042b70;
case 0x0c042b72u: goto P_0c042b72;
case 0x0c042b74u: goto P_0c042b74;
case 0x0c042b76u: goto P_0c042b76;
case 0x0c042b78u: goto P_0c042b78;
case 0x0c042b7au: goto P_0c042b7a;
case 0x0c042b7cu: goto P_0c042b7c;
case 0x0c042b7eu: goto P_0c042b7e;
case 0x0c042b80u: goto P_0c042b80;
case 0x0c042b82u: goto P_0c042b82;
case 0x0c042b84u: goto P_0c042b84;
case 0x0c042b86u: goto P_0c042b86;
case 0x0c042b88u: goto P_0c042b88;
case 0x0c042b8au: goto P_0c042b8a;
case 0x0c042b8cu: goto P_0c042b8c;
case 0x0c042bb0u: goto P_0c042bb0;
case 0x0c042bb2u: goto P_0c042bb2;
case 0x0c042bb4u: goto P_0c042bb4;
case 0x0c042bb6u: goto P_0c042bb6;
case 0x0c042bb8u: goto P_0c042bb8;
case 0x0c042bbau: goto P_0c042bba;
case 0x0c042bbcu: goto P_0c042bbc;
case 0x0c042bbeu: goto P_0c042bbe;
case 0x0c042bc0u: goto P_0c042bc0;
case 0x0c042bc2u: goto P_0c042bc2;
case 0x0c042bc4u: goto P_0c042bc4;
case 0x0c042bc6u: goto P_0c042bc6;
case 0x0c042bc8u: goto P_0c042bc8;
case 0x0c042bcau: goto P_0c042bca;
case 0x0c042bccu: goto P_0c042bcc;
case 0x0c042bceu: goto P_0c042bce;
case 0x0c042bd0u: goto P_0c042bd0;
case 0x0c042be0u: goto P_0c042be0;
case 0x0c042be2u: goto P_0c042be2;
case 0x0c042be4u: goto P_0c042be4;
case 0x0c042be6u: goto P_0c042be6;
case 0x0c042be8u: goto P_0c042be8;
case 0x0c042beau: goto P_0c042bea;
case 0x0c042becu: goto P_0c042bec;
case 0x0c042beeu: goto P_0c042bee;
case 0x0c042bf0u: goto P_0c042bf0;
case 0x0c042bf2u: goto P_0c042bf2;
case 0x0c042bf4u: goto P_0c042bf4;
case 0x0c042bf6u: goto P_0c042bf6;
case 0x0c042bf8u: goto P_0c042bf8;
case 0x0c042bfau: goto P_0c042bfa;
case 0x0c042c00u: goto P_0c042c00;
case 0x0c042c02u: goto P_0c042c02;
case 0x0c042c04u: goto P_0c042c04;
case 0x0c0475aau: goto P_0c0475aa;
case 0x0c0475acu: goto P_0c0475ac;
case 0x0c07fca4u: goto P_0c07fca4;
case 0x0c07fca6u: goto P_0c07fca6;
case 0x0c07fca8u: goto P_0c07fca8;
case 0x0c07fcaau: goto P_0c07fcaa;
case 0x0c07fcacu: goto P_0c07fcac;
case 0x0c07fcaeu: goto P_0c07fcae;
case 0x0c07fcb0u: goto P_0c07fcb0;
case 0x0c07fcb2u: goto P_0c07fcb2;
case 0x0c07fcb4u: goto P_0c07fcb4;
case 0x0c07fcb6u: goto P_0c07fcb6;
case 0x0c07fcb8u: goto P_0c07fcb8;
case 0x0c07fcbau: goto P_0c07fcba;
case 0x0c07fcbcu: goto P_0c07fcbc;
case 0x0c07fcbeu: goto P_0c07fcbe;
case 0x0c07fcc0u: goto P_0c07fcc0;
case 0x0c07fcc2u: goto P_0c07fcc2;
case 0x0c07fcc4u: goto P_0c07fcc4;
case 0x0c07fcc6u: goto P_0c07fcc6;
case 0x0c07fcc8u: goto P_0c07fcc8;
case 0x0c0858f2u: goto P_0c0858f2;
case 0x0c0858f4u: goto P_0c0858f4;
case 0x0c0858f6u: goto P_0c0858f6;
case 0x0c0858f8u: goto P_0c0858f8;
case 0x0c0858fau: goto P_0c0858fa;
case 0x0c0858fcu: goto P_0c0858fc;
case 0x0c0858feu: goto P_0c0858fe;
case 0x0c085900u: goto P_0c085900;
case 0x0c085902u: goto P_0c085902;
case 0x0c085904u: goto P_0c085904;
case 0x0c085906u: goto P_0c085906;
case 0x0c085908u: goto P_0c085908;
case 0x0c08590au: goto P_0c08590a;
case 0x0c08590cu: goto P_0c08590c;
case 0x0c08590eu: goto P_0c08590e;
case 0x0c085910u: goto P_0c085910;
case 0x0c085912u: goto P_0c085912;
case 0x0c085914u: goto P_0c085914;
case 0x0c085916u: goto P_0c085916;
case 0x0c085918u: goto P_0c085918;
case 0x0c08591au: goto P_0c08591a;
case 0x0c08591cu: goto P_0c08591c;
case 0x0c08591eu: goto P_0c08591e;
case 0x0c085920u: goto P_0c085920;
case 0x0c085922u: goto P_0c085922;
case 0x0c085924u: goto P_0c085924;
case 0x0c085926u: goto P_0c085926;
case 0x0c085928u: goto P_0c085928;
case 0x0c08592au: goto P_0c08592a;
case 0x0c08592cu: goto P_0c08592c;
case 0x0c08592eu: goto P_0c08592e;
case 0x0c085930u: goto P_0c085930;
case 0x0c085932u: goto P_0c085932;
case 0x0c085934u: goto P_0c085934;
case 0x0c085936u: goto P_0c085936;
case 0x0c085938u: goto P_0c085938;
case 0x0c08593au: goto P_0c08593a;
case 0x0c08593cu: goto P_0c08593c;
case 0x0c08593eu: goto P_0c08593e;
case 0x0c085940u: goto P_0c085940;
case 0x0c085942u: goto P_0c085942;
case 0x0c085944u: goto P_0c085944;
case 0x0c085946u: goto P_0c085946;
case 0x0c085948u: goto P_0c085948;
case 0x0c08594au: goto P_0c08594a;
case 0x0c08594cu: goto P_0c08594c;
case 0x0c08594eu: goto P_0c08594e;
case 0x0c085950u: goto P_0c085950;
case 0x0c085952u: goto P_0c085952;
case 0x0c085954u: goto P_0c085954;
case 0x0c085956u: goto P_0c085956;
case 0x0c085958u: goto P_0c085958;
case 0x0c08595au: goto P_0c08595a;
case 0x0c08595cu: goto P_0c08595c;
case 0x0c08595eu: goto P_0c08595e;
case 0x0c085960u: goto P_0c085960;
case 0x0c085962u: goto P_0c085962;
case 0x0c085964u: goto P_0c085964;
case 0x0c085966u: goto P_0c085966;
case 0x0c085968u: goto P_0c085968;
case 0x0c08596au: goto P_0c08596a;
case 0x0c08596cu: goto P_0c08596c;
case 0x0c08596eu: goto P_0c08596e;
case 0x0c085970u: goto P_0c085970;
case 0x0c085972u: goto P_0c085972;
case 0x0c085974u: goto P_0c085974;
case 0x0c085976u: goto P_0c085976;
case 0x0c085978u: goto P_0c085978;
case 0x0c08597au: goto P_0c08597a;
case 0x0c08597cu: goto P_0c08597c;
case 0x0c08597eu: goto P_0c08597e;
case 0x0c085980u: goto P_0c085980;
case 0x0c085982u: goto P_0c085982;
case 0x0c085984u: goto P_0c085984;
case 0x0c085986u: goto P_0c085986;
case 0x0c085988u: goto P_0c085988;
case 0x0c08598au: goto P_0c08598a;
case 0x0c08598cu: goto P_0c08598c;
case 0x0c08598eu: goto P_0c08598e;
case 0x0c085990u: goto P_0c085990;
case 0x0c085992u: goto P_0c085992;
case 0x0c085994u: goto P_0c085994;
case 0x0c085996u: goto P_0c085996;
case 0x0c085998u: goto P_0c085998;
case 0x0c08599au: goto P_0c08599a;
case 0x0c08599cu: goto P_0c08599c;
case 0x0c08599eu: goto P_0c08599e;
case 0x0c0859a0u: goto P_0c0859a0;
case 0x0c0859a2u: goto P_0c0859a2;
case 0x0c0859a4u: goto P_0c0859a4;
case 0x0c0859a6u: goto P_0c0859a6;
case 0x0c0859a8u: goto P_0c0859a8;
case 0x0c0859aau: goto P_0c0859aa;
case 0x0c0859acu: goto P_0c0859ac;
case 0x0c0859aeu: goto P_0c0859ae;
case 0x0c0859b0u: goto P_0c0859b0;
case 0x0c0859b2u: goto P_0c0859b2;
case 0x0c0859b4u: goto P_0c0859b4;
case 0x0c0859b6u: goto P_0c0859b6;
case 0x0c0859b8u: goto P_0c0859b8;
case 0x0c0859bau: goto P_0c0859ba;
case 0x0c0859bcu: goto P_0c0859bc;
case 0x0c0859beu: goto P_0c0859be;
case 0x0c0859c0u: goto P_0c0859c0;
case 0x0c0859c2u: goto P_0c0859c2;
case 0x0c0859c4u: goto P_0c0859c4;
case 0x0c0859c6u: goto P_0c0859c6;
case 0x0c0859c8u: goto P_0c0859c8;
case 0x0c0859cau: goto P_0c0859ca;
case 0x0c0859ccu: goto P_0c0859cc;
case 0x0c0859ceu: goto P_0c0859ce;
case 0x0c0859d0u: goto P_0c0859d0;
case 0x0c0859d2u: goto P_0c0859d2;
case 0x0c08a076u: goto P_0c08a076;
case 0x0c08a078u: goto P_0c08a078;
case 0x0c08a07au: goto P_0c08a07a;
case 0x0c08a07cu: goto P_0c08a07c;
case 0x0c08a07eu: goto P_0c08a07e;
case 0x0c08a080u: goto P_0c08a080;
case 0x0c08a082u: goto P_0c08a082;
case 0x0c08a084u: goto P_0c08a084;
case 0x0c08a086u: goto P_0c08a086;
case 0x0c08a088u: goto P_0c08a088;
case 0x0c08a08au: goto P_0c08a08a;
case 0x0c08a08cu: goto P_0c08a08c;
case 0x0c08a08eu: goto P_0c08a08e;
case 0x0c08a090u: goto P_0c08a090;
case 0x0c08a092u: goto P_0c08a092;
case 0x0c08a094u: goto P_0c08a094;
case 0x0c08a096u: goto P_0c08a096;
case 0x0c08a098u: goto P_0c08a098;
case 0x0c08a09au: goto P_0c08a09a;
case 0x0c08a09cu: goto P_0c08a09c;
case 0x0c08a09eu: goto P_0c08a09e;
case 0x0c08a0a0u: goto P_0c08a0a0;
case 0x0c08a0a2u: goto P_0c08a0a2;
case 0x0c08a0a4u: goto P_0c08a0a4;
case 0x0c08a0a6u: goto P_0c08a0a6;
case 0x0c08a0a8u: goto P_0c08a0a8;
case 0x0c08a0aau: goto P_0c08a0aa;
case 0x0c08a0acu: goto P_0c08a0ac;
case 0x0c08a0aeu: goto P_0c08a0ae;
case 0x0c08a0b0u: goto P_0c08a0b0;
case 0x0c08a0b2u: goto P_0c08a0b2;
case 0x0c08a0b4u: goto P_0c08a0b4;
case 0x0c08a0b6u: goto P_0c08a0b6;
case 0x0c08a0b8u: goto P_0c08a0b8;
case 0x0c08a0bau: goto P_0c08a0ba;
case 0x0c08a0bcu: goto P_0c08a0bc;
case 0x0c08a0beu: goto P_0c08a0be;
case 0x0c08a0c0u: goto P_0c08a0c0;
case 0x0c08a0c2u: goto P_0c08a0c2;
case 0x0c08a0c4u: goto P_0c08a0c4;
case 0x0c08a0c6u: goto P_0c08a0c6;
case 0x0c08a0c8u: goto P_0c08a0c8;
case 0x0c08a0cau: goto P_0c08a0ca;
case 0x0c08a0ccu: goto P_0c08a0cc;
case 0x0c08a0ceu: goto P_0c08a0ce;
case 0x0c08a0d0u: goto P_0c08a0d0;
case 0x0c08a0d2u: goto P_0c08a0d2;
case 0x0c08a0d4u: goto P_0c08a0d4;
case 0x0c08a0d6u: goto P_0c08a0d6;
case 0x0c08a0d8u: goto P_0c08a0d8;
case 0x0c08a0dau: goto P_0c08a0da;
case 0x0c08a0dcu: goto P_0c08a0dc;
case 0x0c08a0deu: goto P_0c08a0de;
case 0x0c08a0e0u: goto P_0c08a0e0;
case 0x0c08a0e2u: goto P_0c08a0e2;
case 0x0c08a0e4u: goto P_0c08a0e4;
case 0x0c08a0e6u: goto P_0c08a0e6;
case 0x0c08a0e8u: goto P_0c08a0e8;
case 0x0c08a0eau: goto P_0c08a0ea;
case 0x0c08a0ecu: goto P_0c08a0ec;
case 0x0c08a0eeu: goto P_0c08a0ee;
case 0x0c08a0f0u: goto P_0c08a0f0;
case 0x0c08a0f2u: goto P_0c08a0f2;
case 0x0c08a0f4u: goto P_0c08a0f4;
case 0x0c08a0f6u: goto P_0c08a0f6;
case 0x0c08a0f8u: goto P_0c08a0f8;
case 0x0c08a0fau: goto P_0c08a0fa;
case 0x0c08a0fcu: goto P_0c08a0fc;
case 0x0c08a0feu: goto P_0c08a0fe;
case 0x0c08a100u: goto P_0c08a100;
case 0x0c08a102u: goto P_0c08a102;
case 0x0c08a104u: goto P_0c08a104;
case 0x0c08a106u: goto P_0c08a106;
case 0x0c08a108u: goto P_0c08a108;
case 0x0c08a10au: goto P_0c08a10a;
case 0x0c08a10cu: goto P_0c08a10c;
case 0x0c08a10eu: goto P_0c08a10e;
case 0x0c08a110u: goto P_0c08a110;
case 0x0c08a112u: goto P_0c08a112;
case 0x0c08a114u: goto P_0c08a114;
case 0x0c08a116u: goto P_0c08a116;
case 0x0c08a118u: goto P_0c08a118;
case 0x0c08a11au: goto P_0c08a11a;
case 0x0c08a11cu: goto P_0c08a11c;
case 0x0c08a11eu: goto P_0c08a11e;
case 0x0c08a120u: goto P_0c08a120;
case 0x0c08a122u: goto P_0c08a122;
case 0x0c08a124u: goto P_0c08a124;
case 0x0c08a126u: goto P_0c08a126;
case 0x0c08a128u: goto P_0c08a128;
case 0x0c08a12au: goto P_0c08a12a;
case 0x0c08a12cu: goto P_0c08a12c;
case 0x0c08a12eu: goto P_0c08a12e;
case 0x0c08a130u: goto P_0c08a130;
case 0x0c08a132u: goto P_0c08a132;
case 0x0c08a134u: goto P_0c08a134;
case 0x0c08a136u: goto P_0c08a136;
case 0x0c08a138u: goto P_0c08a138;
case 0x0c08a13au: goto P_0c08a13a;
case 0x0c08a13cu: goto P_0c08a13c;
case 0x0c08a13eu: goto P_0c08a13e;
case 0x0c08a140u: goto P_0c08a140;
case 0x0c08a142u: goto P_0c08a142;
case 0x0c08a144u: goto P_0c08a144;
case 0x0c08a146u: goto P_0c08a146;
case 0x0c08a148u: goto P_0c08a148;
case 0x0c08a14au: goto P_0c08a14a;
case 0x0c08a14cu: goto P_0c08a14c;
case 0x0c08a14eu: goto P_0c08a14e;
case 0x0c08a150u: goto P_0c08a150;
case 0x0c08a152u: goto P_0c08a152;
case 0x0c08a154u: goto P_0c08a154;
case 0x0c08a156u: goto P_0c08a156;
case 0x0c08a158u: goto P_0c08a158;
case 0x0c08a15au: goto P_0c08a15a;
case 0x0c08a15cu: goto P_0c08a15c;
case 0x0c08a15eu: goto P_0c08a15e;
case 0x0c08a160u: goto P_0c08a160;
case 0x0c08a162u: goto P_0c08a162;
case 0x0c08a164u: goto P_0c08a164;
case 0x0c08a166u: goto P_0c08a166;
case 0x0c08a168u: goto P_0c08a168;
case 0x0c08a16au: goto P_0c08a16a;
case 0x0c08a16cu: goto P_0c08a16c;
case 0x0c08a16eu: goto P_0c08a16e;
case 0x0c08a170u: goto P_0c08a170;
case 0x0c08a172u: goto P_0c08a172;
case 0x0c08a174u: goto P_0c08a174;
case 0x0c08a176u: goto P_0c08a176;
case 0x0c08a178u: goto P_0c08a178;
case 0x0c08a17au: goto P_0c08a17a;
case 0x0c08a17cu: goto P_0c08a17c;
case 0x0c08a17eu: goto P_0c08a17e;
case 0x0c08a180u: goto P_0c08a180;
case 0x0c08a182u: goto P_0c08a182;
case 0x0c08a184u: goto P_0c08a184;
case 0x0c08a186u: goto P_0c08a186;
case 0x0c08a188u: goto P_0c08a188;
case 0x0c08a18au: goto P_0c08a18a;
case 0x0c08a18cu: goto P_0c08a18c;
case 0x0c08a18eu: goto P_0c08a18e;
case 0x0c08a190u: goto P_0c08a190;
case 0x0c08a192u: goto P_0c08a192;
case 0x0c08a194u: goto P_0c08a194;
case 0x0c08a196u: goto P_0c08a196;
case 0x0c08a198u: goto P_0c08a198;
case 0x0c08a19au: goto P_0c08a19a;
case 0x0c08a19cu: goto P_0c08a19c;
case 0x0c08a19eu: goto P_0c08a19e;
case 0x0c08a1a0u: goto P_0c08a1a0;
case 0x0c08a1a2u: goto P_0c08a1a2;
case 0x0c08a1a4u: goto P_0c08a1a4;
case 0x0c08a1a6u: goto P_0c08a1a6;
case 0x0c08a1a8u: goto P_0c08a1a8;
case 0x0c08a1aau: goto P_0c08a1aa;
case 0x0c08a1acu: goto P_0c08a1ac;
case 0x0c08a1aeu: goto P_0c08a1ae;
case 0x0c08a1b0u: goto P_0c08a1b0;
case 0x0c08a1b2u: goto P_0c08a1b2;
case 0x0c08a1b4u: goto P_0c08a1b4;
case 0x0c08a1b6u: goto P_0c08a1b6;
case 0x0c08a1b8u: goto P_0c08a1b8;
case 0x0c08a1bau: goto P_0c08a1ba;
case 0x0c08a1bcu: goto P_0c08a1bc;
case 0x0c08a1beu: goto P_0c08a1be;
case 0x0c08a1c0u: goto P_0c08a1c0;
case 0x0c08a1c2u: goto P_0c08a1c2;
case 0x0c08a1c4u: goto P_0c08a1c4;
case 0x0c08a1c6u: goto P_0c08a1c6;
case 0x0c08a1c8u: goto P_0c08a1c8;
case 0x0c08a1cau: goto P_0c08a1ca;
case 0x0c08a1ccu: goto P_0c08a1cc;
case 0x0c08a1ceu: goto P_0c08a1ce;
case 0x0c08a1d0u: goto P_0c08a1d0;
case 0x0c08a1d2u: goto P_0c08a1d2;
case 0x0c08a1d4u: goto P_0c08a1d4;
case 0x0c08a1d6u: goto P_0c08a1d6;
case 0x0c08a1d8u: goto P_0c08a1d8;
case 0x0c08a1dau: goto P_0c08a1da;
case 0x0c08a1dcu: goto P_0c08a1dc;
case 0x0c08a23cu: goto P_0c08a23c;
case 0x0c08a23eu: goto P_0c08a23e;
case 0x0c08a240u: goto P_0c08a240;
case 0x0c08a242u: goto P_0c08a242;
case 0x0c08a244u: goto P_0c08a244;
case 0x0c08a246u: goto P_0c08a246;
case 0x0c08a248u: goto P_0c08a248;
case 0x0c08a24au: goto P_0c08a24a;
case 0x0c08a24cu: goto P_0c08a24c;
case 0x0c08a24eu: goto P_0c08a24e;
case 0x0c08a250u: goto P_0c08a250;
case 0x0c08a252u: goto P_0c08a252;
case 0x0c08a254u: goto P_0c08a254;
case 0x0c08a256u: goto P_0c08a256;
case 0x0c08a258u: goto P_0c08a258;
case 0x0c08a25au: goto P_0c08a25a;
case 0x0c08a25cu: goto P_0c08a25c;
case 0x0c08a25eu: goto P_0c08a25e;
case 0x0c08a260u: goto P_0c08a260;
case 0x0c08a262u: goto P_0c08a262;
case 0x0c08a264u: goto P_0c08a264;
case 0x0c08a266u: goto P_0c08a266;
case 0x0c08a268u: goto P_0c08a268;
case 0x0c08a26au: goto P_0c08a26a;
case 0x0c08a26cu: goto P_0c08a26c;
case 0x0c08a26eu: goto P_0c08a26e;
case 0x0c08a270u: goto P_0c08a270;
case 0x0c08a272u: goto P_0c08a272;
case 0x0c08a274u: goto P_0c08a274;
case 0x0c08a276u: goto P_0c08a276;
case 0x0c08a278u: goto P_0c08a278;
case 0x0c08a27au: goto P_0c08a27a;
case 0x0c08a27cu: goto P_0c08a27c;
case 0x0c08a27eu: goto P_0c08a27e;
case 0x0c08a280u: goto P_0c08a280;
case 0x0c08a282u: goto P_0c08a282;
case 0x0c08a284u: goto P_0c08a284;
case 0x0c08a286u: goto P_0c08a286;
case 0x0c08a288u: goto P_0c08a288;
case 0x0c08a28au: goto P_0c08a28a;
case 0x0c08a28cu: goto P_0c08a28c;
case 0x0c08a28eu: goto P_0c08a28e;
case 0x0c08a290u: goto P_0c08a290;
case 0x0c08a292u: goto P_0c08a292;
case 0x0c08a294u: goto P_0c08a294;
case 0x0c08a296u: goto P_0c08a296;
case 0x0c08a298u: goto P_0c08a298;
case 0x0c08a29au: goto P_0c08a29a;
case 0x0c08a29cu: goto P_0c08a29c;
case 0x0c08a29eu: goto P_0c08a29e;
case 0x0c08a2a0u: goto P_0c08a2a0;
case 0x0c08a2a2u: goto P_0c08a2a2;
case 0x0c08a2a4u: goto P_0c08a2a4;
case 0x0c08a2a6u: goto P_0c08a2a6;
case 0x0c08a2a8u: goto P_0c08a2a8;
case 0x0c08a2aau: goto P_0c08a2aa;
case 0x0c08a2acu: goto P_0c08a2ac;
case 0x0c08a2aeu: goto P_0c08a2ae;
case 0x0c08a2b0u: goto P_0c08a2b0;
case 0x0c08a2b2u: goto P_0c08a2b2;
case 0x0c08a2b4u: goto P_0c08a2b4;
case 0x0c08a2b6u: goto P_0c08a2b6;
case 0x0c08a2b8u: goto P_0c08a2b8;
case 0x0c08a2bau: goto P_0c08a2ba;
case 0x0c08a2bcu: goto P_0c08a2bc;
case 0x0c08a2beu: goto P_0c08a2be;
case 0x0c08a2c0u: goto P_0c08a2c0;
case 0x0c08a2c2u: goto P_0c08a2c2;
case 0x0c08a2c4u: goto P_0c08a2c4;
case 0x0c08a2c6u: goto P_0c08a2c6;
case 0x0c08a2c8u: goto P_0c08a2c8;
case 0x0c08a2cau: goto P_0c08a2ca;
case 0x0c08c90eu: goto P_0c08c90e;
case 0x0c08c910u: goto P_0c08c910;
case 0x0c08c912u: goto P_0c08c912;
case 0x0c08c914u: goto P_0c08c914;
case 0x0c08c916u: goto P_0c08c916;
case 0x0c08c918u: goto P_0c08c918;
case 0x0c08c91au: goto P_0c08c91a;
case 0x0c08c91cu: goto P_0c08c91c;
case 0x0c08c91eu: goto P_0c08c91e;
case 0x0c08c920u: goto P_0c08c920;
case 0x0c08c922u: goto P_0c08c922;
case 0x0c08c924u: goto P_0c08c924;
case 0x0c08c926u: goto P_0c08c926;
case 0x0c08c928u: goto P_0c08c928;
case 0x0c08c92au: goto P_0c08c92a;
case 0x0c08c92cu: goto P_0c08c92c;
case 0x0c08c92eu: goto P_0c08c92e;
case 0x0c08c930u: goto P_0c08c930;
case 0x0c08c932u: goto P_0c08c932;
case 0x0c08c934u: goto P_0c08c934;
case 0x0c08c936u: goto P_0c08c936;
case 0x0c08c938u: goto P_0c08c938;
case 0x0c08c93au: goto P_0c08c93a;
case 0x0c08c93cu: goto P_0c08c93c;
case 0x0c08c93eu: goto P_0c08c93e;
case 0x0c08c940u: goto P_0c08c940;
case 0x0c08c942u: goto P_0c08c942;
case 0x0c08c944u: goto P_0c08c944;
case 0x0c08c946u: goto P_0c08c946;
case 0x0c08c948u: goto P_0c08c948;
case 0x0c08c94au: goto P_0c08c94a;
case 0x0c08c94cu: goto P_0c08c94c;
case 0x0c08c94eu: goto P_0c08c94e;
case 0x0c08c950u: goto P_0c08c950;
case 0x0c08c952u: goto P_0c08c952;
case 0x0c08c954u: goto P_0c08c954;
case 0x0c08c956u: goto P_0c08c956;
case 0x0c08c958u: goto P_0c08c958;
case 0x0c08c95au: goto P_0c08c95a;
case 0x0c08c95cu: goto P_0c08c95c;
case 0x0c08c95eu: goto P_0c08c95e;
case 0x0c08c960u: goto P_0c08c960;
case 0x0c08c962u: goto P_0c08c962;
case 0x0c08c964u: goto P_0c08c964;
case 0x0c08c966u: goto P_0c08c966;
case 0x0c08c968u: goto P_0c08c968;
case 0x0c08c96au: goto P_0c08c96a;
case 0x0c08c96cu: goto P_0c08c96c;
case 0x0c08c96eu: goto P_0c08c96e;
case 0x0c08c970u: goto P_0c08c970;
case 0x0c08c972u: goto P_0c08c972;
case 0x0c08c974u: goto P_0c08c974;
case 0x0c08c976u: goto P_0c08c976;
case 0x0c09b69eu: goto P_0c09b69e;
case 0x0c09b6a0u: goto P_0c09b6a0;
case 0x0c09b6a2u: goto P_0c09b6a2;
case 0x0c09b6a4u: goto P_0c09b6a4;
case 0x0c09b6a6u: goto P_0c09b6a6;
case 0x0c09b6a8u: goto P_0c09b6a8;
case 0x0c09b6aau: goto P_0c09b6aa;
case 0x0c09b6acu: goto P_0c09b6ac;
case 0x0c09b6aeu: goto P_0c09b6ae;
case 0x0c09b6b0u: goto P_0c09b6b0;
case 0x0c09b6b2u: goto P_0c09b6b2;
case 0x0c09b6b4u: goto P_0c09b6b4;
case 0x0c09b6b6u: goto P_0c09b6b6;
case 0x0c09b6b8u: goto P_0c09b6b8;
case 0x0c09b6bau: goto P_0c09b6ba;
case 0x0c09b6bcu: goto P_0c09b6bc;
case 0x0c09b6beu: goto P_0c09b6be;
case 0x0c09b6c0u: goto P_0c09b6c0;
case 0x0c09b6c2u: goto P_0c09b6c2;
case 0x0c09b6c4u: goto P_0c09b6c4;
case 0x0c09b6c6u: goto P_0c09b6c6;
case 0x0c09b6c8u: goto P_0c09b6c8;
case 0x0c09b6cau: goto P_0c09b6ca;
case 0x0c09b6ccu: goto P_0c09b6cc;
case 0x0c09b6ceu: goto P_0c09b6ce;
case 0x0c09b6d0u: goto P_0c09b6d0;
case 0x0c09b6d2u: goto P_0c09b6d2;
case 0x0c09b6d4u: goto P_0c09b6d4;
case 0x0c09b6d6u: goto P_0c09b6d6;
case 0x0c09b6d8u: goto P_0c09b6d8;
case 0x0c09b6dau: goto P_0c09b6da;
case 0x0c09b6dcu: goto P_0c09b6dc;
case 0x0c09b6deu: goto P_0c09b6de;
case 0x0c09b6e0u: goto P_0c09b6e0;
case 0x0c09b6e2u: goto P_0c09b6e2;
case 0x0c09b6e4u: goto P_0c09b6e4;
case 0x0c09b6e6u: goto P_0c09b6e6;
case 0x0c09b6e8u: goto P_0c09b6e8;
case 0x0c09b6eau: goto P_0c09b6ea;
case 0x0c09b6ecu: goto P_0c09b6ec;
case 0x0c09b6eeu: goto P_0c09b6ee;
case 0x0c09b6f0u: goto P_0c09b6f0;
case 0x0c09b6f2u: goto P_0c09b6f2;
case 0x0c09b6f4u: goto P_0c09b6f4;
case 0x0c09b6f6u: goto P_0c09b6f6;
case 0x0c09b6f8u: goto P_0c09b6f8;
case 0x0c09b6fau: goto P_0c09b6fa;
case 0x0c09b6fcu: goto P_0c09b6fc;
case 0x0c09b6feu: goto P_0c09b6fe;
case 0x0c09b700u: goto P_0c09b700;
case 0x0c09b702u: goto P_0c09b702;
case 0x0c09b704u: goto P_0c09b704;
case 0x0c09b706u: goto P_0c09b706;
case 0x0c09b708u: goto P_0c09b708;
case 0x0c09b70au: goto P_0c09b70a;
case 0x0c09b70cu: goto P_0c09b70c;
case 0x0c09b70eu: goto P_0c09b70e;
case 0x0c09b710u: goto P_0c09b710;
case 0x0c09b730u: goto P_0c09b730;
case 0x0c09b732u: goto P_0c09b732;
case 0x0c09b734u: goto P_0c09b734;
case 0x0c09b736u: goto P_0c09b736;
case 0x0c09b738u: goto P_0c09b738;
case 0x0c09b73au: goto P_0c09b73a;
case 0x0c09b73cu: goto P_0c09b73c;
case 0x0c09b73eu: goto P_0c09b73e;
case 0x0c09b740u: goto P_0c09b740;
case 0x0c09b742u: goto P_0c09b742;
case 0x0c09b744u: goto P_0c09b744;
case 0x0c09b746u: goto P_0c09b746;
case 0x0c09b748u: goto P_0c09b748;
case 0x0c09b74au: goto P_0c09b74a;
case 0x0c09b74cu: goto P_0c09b74c;
case 0x0c09b74eu: goto P_0c09b74e;
case 0x0c09b750u: goto P_0c09b750;
case 0x0c09b752u: goto P_0c09b752;
case 0x0c09b754u: goto P_0c09b754;
case 0x0c09b756u: goto P_0c09b756;
case 0x0c09b758u: goto P_0c09b758;
case 0x0c09b75au: goto P_0c09b75a;
case 0x0c09b75cu: goto P_0c09b75c;
case 0x0c09b75eu: goto P_0c09b75e;
case 0x0c09b760u: goto P_0c09b760;
case 0x0c09b762u: goto P_0c09b762;
case 0x0c09b764u: goto P_0c09b764;
case 0x0c09b766u: goto P_0c09b766;
case 0x0c09b768u: goto P_0c09b768;
case 0x0c09b76au: goto P_0c09b76a;
case 0x0c09b76cu: goto P_0c09b76c;
case 0x0c09b76eu: goto P_0c09b76e;
case 0x0c09b770u: goto P_0c09b770;
case 0x0c09b772u: goto P_0c09b772;
case 0x0c09b774u: goto P_0c09b774;
case 0x0c09b776u: goto P_0c09b776;
case 0x0c09b778u: goto P_0c09b778;
case 0x0c09b77au: goto P_0c09b77a;
case 0x0c09b77cu: goto P_0c09b77c;
case 0x0c09b77eu: goto P_0c09b77e;
case 0x0c09b780u: goto P_0c09b780;
case 0x0c09b782u: goto P_0c09b782;
case 0x0c09b784u: goto P_0c09b784;
case 0x0c09b786u: goto P_0c09b786;
case 0x0c09b788u: goto P_0c09b788;
case 0x0c09b78au: goto P_0c09b78a;
case 0x0c09b78cu: goto P_0c09b78c;
case 0x0c09b78eu: goto P_0c09b78e;
case 0x0c09b790u: goto P_0c09b790;
case 0x0c09b792u: goto P_0c09b792;
case 0x0c09b794u: goto P_0c09b794;
case 0x0c09b796u: goto P_0c09b796;
case 0x0c09b798u: goto P_0c09b798;
case 0x0c09b79au: goto P_0c09b79a;
case 0x0c09b79cu: goto P_0c09b79c;
case 0x0c09b79eu: goto P_0c09b79e;
case 0x0c09b7b0u: goto P_0c09b7b0;
case 0x0c09b7b2u: goto P_0c09b7b2;
case 0x0c09b7b4u: goto P_0c09b7b4;
case 0x0c09b7b6u: goto P_0c09b7b6;
case 0x0c09b7b8u: goto P_0c09b7b8;
case 0x0c09b7bau: goto P_0c09b7ba;
case 0x0c09b7bcu: goto P_0c09b7bc;
case 0x0c09b7beu: goto P_0c09b7be;
case 0x0c09b7c0u: goto P_0c09b7c0;
case 0x0c09b7c2u: goto P_0c09b7c2;
case 0x0c09b7c4u: goto P_0c09b7c4;
case 0x0c09b7c6u: goto P_0c09b7c6;
case 0x0c09b7c8u: goto P_0c09b7c8;
case 0x0c09b7cau: goto P_0c09b7ca;
case 0x0c09b7ccu: goto P_0c09b7cc;
case 0x0c09b7ceu: goto P_0c09b7ce;
case 0x0c09b7d0u: goto P_0c09b7d0;
case 0x0c09b7d2u: goto P_0c09b7d2;
case 0x0c09b7d4u: goto P_0c09b7d4;
case 0x0c09b7d6u: goto P_0c09b7d6;
case 0x0c09b7d8u: goto P_0c09b7d8;
case 0x0c09b7dau: goto P_0c09b7da;
case 0x0c09b7dcu: goto P_0c09b7dc;
case 0x0c09b7deu: goto P_0c09b7de;
case 0x0c09b7e0u: goto P_0c09b7e0;
case 0x0c09b7e2u: goto P_0c09b7e2;
case 0x0c09b7e4u: goto P_0c09b7e4;
case 0x0c09b7e6u: goto P_0c09b7e6;
case 0x0c09b7e8u: goto P_0c09b7e8;
case 0x0c09b7eau: goto P_0c09b7ea;
case 0x0c09b7ecu: goto P_0c09b7ec;
case 0x0c09b7eeu: goto P_0c09b7ee;
case 0x0c09b7f0u: goto P_0c09b7f0;
case 0x0c09b7f2u: goto P_0c09b7f2;
case 0x0c09b7f4u: goto P_0c09b7f4;
case 0x0c09b7f6u: goto P_0c09b7f6;
case 0x0c09b7f8u: goto P_0c09b7f8;
case 0x0c09b7fau: goto P_0c09b7fa;
case 0x0c09b7fcu: goto P_0c09b7fc;
case 0x0c09b7feu: goto P_0c09b7fe;
case 0x0c09b800u: goto P_0c09b800;
case 0x0c09b802u: goto P_0c09b802;
case 0x0c09b804u: goto P_0c09b804;
case 0x0c09b806u: goto P_0c09b806;
case 0x0c09b808u: goto P_0c09b808;
case 0x0c09b80au: goto P_0c09b80a;
case 0x0c09b80cu: goto P_0c09b80c;
case 0x0c09b80eu: goto P_0c09b80e;
case 0x0c09b810u: goto P_0c09b810;
case 0x0c09b812u: goto P_0c09b812;
case 0x0c09b814u: goto P_0c09b814;
case 0x0c09b816u: goto P_0c09b816;
case 0x0c09b818u: goto P_0c09b818;
case 0x0c09b81au: goto P_0c09b81a;
case 0x0c09b81cu: goto P_0c09b81c;
case 0x0c09b81eu: goto P_0c09b81e;
case 0x0c09b820u: goto P_0c09b820;
case 0x0c09b822u: goto P_0c09b822;
case 0x0c09b824u: goto P_0c09b824;
case 0x0c09b826u: goto P_0c09b826;
case 0x0c09b828u: goto P_0c09b828;
case 0x0c09b82au: goto P_0c09b82a;
case 0x0c09b82cu: goto P_0c09b82c;
case 0x0c09b82eu: goto P_0c09b82e;
case 0x0c09b830u: goto P_0c09b830;
case 0x0c09b832u: goto P_0c09b832;
case 0x0c09b834u: goto P_0c09b834;
case 0x0c09b836u: goto P_0c09b836;
case 0x0c09b838u: goto P_0c09b838;
case 0x0c09b83au: goto P_0c09b83a;
case 0x0c09b83cu: goto P_0c09b83c;
case 0x0c09b83eu: goto P_0c09b83e;
case 0x0c09b840u: goto P_0c09b840;
case 0x0c09b842u: goto P_0c09b842;
case 0x0c09b844u: goto P_0c09b844;
case 0x0c09b846u: goto P_0c09b846;
case 0x0c09b848u: goto P_0c09b848;
case 0x0c09b84au: goto P_0c09b84a;
case 0x0c09b84cu: goto P_0c09b84c;
case 0x0c09b84eu: goto P_0c09b84e;
case 0x0c09b850u: goto P_0c09b850;
case 0x0c09b852u: goto P_0c09b852;
case 0x0c09b854u: goto P_0c09b854;
case 0x0c09b856u: goto P_0c09b856;
case 0x0c09b858u: goto P_0c09b858;
case 0x0c09b85au: goto P_0c09b85a;
case 0x0c09b85cu: goto P_0c09b85c;
case 0x0c09b85eu: goto P_0c09b85e;
case 0x0c09b860u: goto P_0c09b860;
case 0x0c09b862u: goto P_0c09b862;
case 0x0c09b864u: goto P_0c09b864;
case 0x0c09b866u: goto P_0c09b866;
case 0x0c09b868u: goto P_0c09b868;
case 0x0c09b86au: goto P_0c09b86a;
case 0x0c09b86cu: goto P_0c09b86c;
case 0x0c09b86eu: goto P_0c09b86e;
case 0x0c09b870u: goto P_0c09b870;
case 0x0c09b872u: goto P_0c09b872;
case 0x0c09b874u: goto P_0c09b874;
case 0x0c09b876u: goto P_0c09b876;
case 0x0c09b878u: goto P_0c09b878;
case 0x0c09b87au: goto P_0c09b87a;
case 0x0c09b87cu: goto P_0c09b87c;
case 0x0c09b87eu: goto P_0c09b87e;
case 0x0c09b880u: goto P_0c09b880;
case 0x0c09b882u: goto P_0c09b882;
case 0x0c09b884u: goto P_0c09b884;
case 0x0c09b886u: goto P_0c09b886;
case 0x0c09b888u: goto P_0c09b888;
case 0x0c09b88au: goto P_0c09b88a;
case 0x0c09b88cu: goto P_0c09b88c;
case 0x0c09b88eu: goto P_0c09b88e;
case 0x0c09b8b8u: goto P_0c09b8b8;
case 0x0c09b8bau: goto P_0c09b8ba;
case 0x0c09b8bcu: goto P_0c09b8bc;
case 0x0c09b8beu: goto P_0c09b8be;
case 0x0c09b8c0u: goto P_0c09b8c0;
case 0x0c09b8c2u: goto P_0c09b8c2;
case 0x0c09b8c4u: goto P_0c09b8c4;
case 0x0c09b8c6u: goto P_0c09b8c6;
case 0x0c09b8c8u: goto P_0c09b8c8;
case 0x0c09b8cau: goto P_0c09b8ca;
case 0x0c09b8ccu: goto P_0c09b8cc;
case 0x0c09b8ceu: goto P_0c09b8ce;
case 0x0c09b8d0u: goto P_0c09b8d0;
case 0x0c09b8d2u: goto P_0c09b8d2;
case 0x0c09b8d4u: goto P_0c09b8d4;
case 0x0c09b8d6u: goto P_0c09b8d6;
case 0x0c09b8d8u: goto P_0c09b8d8;
case 0x0c09b8dau: goto P_0c09b8da;
case 0x0c09b8dcu: goto P_0c09b8dc;
case 0x0c09b8deu: goto P_0c09b8de;
case 0x0c09b8e0u: goto P_0c09b8e0;
case 0x0c09b8e2u: goto P_0c09b8e2;
case 0x0c09b8e4u: goto P_0c09b8e4;
case 0x0c09b8e6u: goto P_0c09b8e6;
case 0x0c09b8e8u: goto P_0c09b8e8;
case 0x0c09b8eau: goto P_0c09b8ea;
case 0x0c09b8ecu: goto P_0c09b8ec;
case 0x0c09b8eeu: goto P_0c09b8ee;
case 0x0c09b8f0u: goto P_0c09b8f0;
case 0x0c09b8f2u: goto P_0c09b8f2;
case 0x0c09b8f4u: goto P_0c09b8f4;
case 0x0c09b8f6u: goto P_0c09b8f6;
case 0x0c09b8f8u: goto P_0c09b8f8;
case 0x0c09b8fau: goto P_0c09b8fa;
case 0x0c09b8fcu: goto P_0c09b8fc;
case 0x0c09b8feu: goto P_0c09b8fe;
case 0x0c09b900u: goto P_0c09b900;
case 0x0c09b902u: goto P_0c09b902;
case 0x0c09b904u: goto P_0c09b904;
case 0x0c09b906u: goto P_0c09b906;
case 0x0c09b908u: goto P_0c09b908;
case 0x0c09b90au: goto P_0c09b90a;
case 0x0c09b90cu: goto P_0c09b90c;
case 0x0c09b90eu: goto P_0c09b90e;
case 0x0c09b910u: goto P_0c09b910;
case 0x0c09b912u: goto P_0c09b912;
case 0x0c09b914u: goto P_0c09b914;
case 0x0c09b916u: goto P_0c09b916;
case 0x0c09b918u: goto P_0c09b918;
case 0x0c09b91au: goto P_0c09b91a;
case 0x0c09b91cu: goto P_0c09b91c;
case 0x0c09b91eu: goto P_0c09b91e;
case 0x0c09b920u: goto P_0c09b920;
case 0x0c09b922u: goto P_0c09b922;
case 0x0c09ba8cu: goto P_0c09ba8c;
case 0x0c09ba8eu: goto P_0c09ba8e;
case 0x0c09ba90u: goto P_0c09ba90;
case 0x0c09ba92u: goto P_0c09ba92;
case 0x0c09ba94u: goto P_0c09ba94;
case 0x0c09ba96u: goto P_0c09ba96;
case 0x0c09ba98u: goto P_0c09ba98;
case 0x0c09ba9au: goto P_0c09ba9a;
case 0x0c09ba9cu: goto P_0c09ba9c;
case 0x0c09ba9eu: goto P_0c09ba9e;
case 0x0c09baa0u: goto P_0c09baa0;
case 0x0c09baa2u: goto P_0c09baa2;
case 0x0c09baa4u: goto P_0c09baa4;
case 0x0c09baa6u: goto P_0c09baa6;
case 0x0c09baa8u: goto P_0c09baa8;
case 0x0c09baaau: goto P_0c09baaa;
case 0x0c09baacu: goto P_0c09baac;
case 0x0c09baaeu: goto P_0c09baae;
case 0x0c09bab0u: goto P_0c09bab0;
case 0x0c09bab2u: goto P_0c09bab2;
case 0x0c09bab4u: goto P_0c09bab4;
case 0x0c09bab6u: goto P_0c09bab6;
case 0x0c09bab8u: goto P_0c09bab8;
case 0x0c09babau: goto P_0c09baba;
case 0x0c09babcu: goto P_0c09babc;
case 0x0c09babeu: goto P_0c09babe;
case 0x0c09bac0u: goto P_0c09bac0;
case 0x0c09bac2u: goto P_0c09bac2;
case 0x0c09bac4u: goto P_0c09bac4;
case 0x0c09bac6u: goto P_0c09bac6;
case 0x0c09bac8u: goto P_0c09bac8;
case 0x0c09bacau: goto P_0c09baca;
case 0x0c09baccu: goto P_0c09bacc;
case 0x0c09baceu: goto P_0c09bace;
case 0x0c09bad0u: goto P_0c09bad0;
case 0x0c09bad2u: goto P_0c09bad2;
case 0x0c09bad4u: goto P_0c09bad4;
case 0x0c09bad6u: goto P_0c09bad6;
case 0x0c09bad8u: goto P_0c09bad8;
case 0x0c09badau: goto P_0c09bada;
case 0x0c09badcu: goto P_0c09badc;
case 0x0c09bc1cu: goto P_0c09bc1c;
case 0x0c09bc1eu: goto P_0c09bc1e;
case 0x0c09bc20u: goto P_0c09bc20;
case 0x0c09bc22u: goto P_0c09bc22;
case 0x0c09bc24u: goto P_0c09bc24;
case 0x0c09bc26u: goto P_0c09bc26;
case 0x0c09bc28u: goto P_0c09bc28;
case 0x0c09bc2au: goto P_0c09bc2a;
case 0x0c09bc2cu: goto P_0c09bc2c;
case 0x0c09bc2eu: goto P_0c09bc2e;
case 0x0c09bc30u: goto P_0c09bc30;
case 0x0c09bc32u: goto P_0c09bc32;
case 0x0c09bc34u: goto P_0c09bc34;
case 0x0c09bc36u: goto P_0c09bc36;
case 0x0c09bc38u: goto P_0c09bc38;
case 0x0c09bc3au: goto P_0c09bc3a;
case 0x0c09bc3cu: goto P_0c09bc3c;
case 0x0c09bc3eu: goto P_0c09bc3e;
case 0x0c09bc40u: goto P_0c09bc40;
case 0x0c09bc42u: goto P_0c09bc42;
case 0x0c09bc44u: goto P_0c09bc44;
case 0x0c09bc46u: goto P_0c09bc46;
case 0x0c09bc48u: goto P_0c09bc48;
case 0x0c09bc4au: goto P_0c09bc4a;
case 0x0c09bc4cu: goto P_0c09bc4c;
case 0x0c09bc4eu: goto P_0c09bc4e;
case 0x0c09bc50u: goto P_0c09bc50;
case 0x0c09bc52u: goto P_0c09bc52;
case 0x0c09bc54u: goto P_0c09bc54;
case 0x0c09bc56u: goto P_0c09bc56;
case 0x0c09bc58u: goto P_0c09bc58;
case 0x0c09bc5au: goto P_0c09bc5a;
case 0x0c09bc5cu: goto P_0c09bc5c;
case 0x0c09bc5eu: goto P_0c09bc5e;
case 0x0c09bc60u: goto P_0c09bc60;
case 0x0c09bc62u: goto P_0c09bc62;
case 0x0c09bc64u: goto P_0c09bc64;
case 0x0c09bc66u: goto P_0c09bc66;
case 0x0c09bc68u: goto P_0c09bc68;
case 0x0c09bc6au: goto P_0c09bc6a;
case 0x0c09bc6cu: goto P_0c09bc6c;
case 0x0c09bc6eu: goto P_0c09bc6e;
case 0x0c09bc70u: goto P_0c09bc70;
case 0x0c09bc72u: goto P_0c09bc72;
case 0x0c09bc74u: goto P_0c09bc74;
case 0x0c09bc76u: goto P_0c09bc76;
case 0x0c09bc78u: goto P_0c09bc78;
case 0x0c09bc7au: goto P_0c09bc7a;
case 0x0c09bc7cu: goto P_0c09bc7c;
case 0x0c09bc7eu: goto P_0c09bc7e;
case 0x0c09bc80u: goto P_0c09bc80;
case 0x0c09bc82u: goto P_0c09bc82;
case 0x0c09bc84u: goto P_0c09bc84;
case 0x0c09bc86u: goto P_0c09bc86;
case 0x0c09bc88u: goto P_0c09bc88;
case 0x0c09bc8au: goto P_0c09bc8a;
case 0x0c09bc8cu: goto P_0c09bc8c;
case 0x0c09bc8eu: goto P_0c09bc8e;
case 0x0c09bc90u: goto P_0c09bc90;
case 0x0c09bc92u: goto P_0c09bc92;
case 0x0c09bc94u: goto P_0c09bc94;
case 0x0c09bc96u: goto P_0c09bc96;
case 0x0c09bc98u: goto P_0c09bc98;
case 0x0c09bc9au: goto P_0c09bc9a;
case 0x0c09bc9cu: goto P_0c09bc9c;
case 0x0c09bc9eu: goto P_0c09bc9e;
case 0x0c09bca0u: goto P_0c09bca0;
case 0x0c09bca2u: goto P_0c09bca2;
case 0x0c09bca4u: goto P_0c09bca4;
case 0x0c09bca6u: goto P_0c09bca6;
case 0x0c09bca8u: goto P_0c09bca8;
case 0x0c09bcaau: goto P_0c09bcaa;
case 0x0c09bcacu: goto P_0c09bcac;
case 0x0c09bcaeu: goto P_0c09bcae;
case 0x0c09bcb0u: goto P_0c09bcb0;
case 0x0c09bcb2u: goto P_0c09bcb2;
case 0x0c09bcb4u: goto P_0c09bcb4;
case 0x0c09bcb6u: goto P_0c09bcb6;
case 0x0c09bcb8u: goto P_0c09bcb8;
case 0x0c09bcbau: goto P_0c09bcba;
case 0x0c09bcbcu: goto P_0c09bcbc;
case 0x0c09bcbeu: goto P_0c09bcbe;
case 0x0c09bcc0u: goto P_0c09bcc0;
case 0x0c09bcc2u: goto P_0c09bcc2;
case 0x0c09bcc4u: goto P_0c09bcc4;
case 0x0c09bcc6u: goto P_0c09bcc6;
case 0x0c09bcc8u: goto P_0c09bcc8;
case 0x0c09bccau: goto P_0c09bcca;
case 0x0c09bcccu: goto P_0c09bccc;
case 0x0c09bcceu: goto P_0c09bcce;
case 0x0c09bcd0u: goto P_0c09bcd0;
case 0x0c09bcd2u: goto P_0c09bcd2;
case 0x0c09bcd4u: goto P_0c09bcd4;
case 0x0c09bcd6u: goto P_0c09bcd6;
case 0x0c09bcd8u: goto P_0c09bcd8;
case 0x0c09bcdau: goto P_0c09bcda;
case 0x0c09bcdcu: goto P_0c09bcdc;
case 0x0c09bcdeu: goto P_0c09bcde;
case 0x0c09bce0u: goto P_0c09bce0;
case 0x0c09bce2u: goto P_0c09bce2;
case 0x0c09bce4u: goto P_0c09bce4;
case 0x0c09bce6u: goto P_0c09bce6;
case 0x0c09bce8u: goto P_0c09bce8;
case 0x0c09bceau: goto P_0c09bcea;
case 0x0c09bcecu: goto P_0c09bcec;
case 0x0c09bceeu: goto P_0c09bcee;
case 0x0c09bcf0u: goto P_0c09bcf0;
case 0x0c09bcf2u: goto P_0c09bcf2;
case 0x0c09bcf4u: goto P_0c09bcf4;
case 0x0c09bcf6u: goto P_0c09bcf6;
case 0x0c09bd0cu: goto P_0c09bd0c;
case 0x0c09bd0eu: goto P_0c09bd0e;
case 0x0c09bd10u: goto P_0c09bd10;
case 0x0c09bd12u: goto P_0c09bd12;
case 0x0c09bd14u: goto P_0c09bd14;
case 0x0c09bd16u: goto P_0c09bd16;
case 0x0c09bd18u: goto P_0c09bd18;
case 0x0c09bd1au: goto P_0c09bd1a;
case 0x0c09bd1cu: goto P_0c09bd1c;
case 0x0c09bd1eu: goto P_0c09bd1e;
case 0x0c09bd20u: goto P_0c09bd20;
case 0x0c09bd22u: goto P_0c09bd22;
case 0x0c09bd24u: goto P_0c09bd24;
case 0x0c09bd26u: goto P_0c09bd26;
case 0x0c09bd28u: goto P_0c09bd28;
case 0x0c09bd2au: goto P_0c09bd2a;
case 0x0c09bd2cu: goto P_0c09bd2c;
case 0x0c09bd2eu: goto P_0c09bd2e;
case 0x0c09bd30u: goto P_0c09bd30;
case 0x0c09bd32u: goto P_0c09bd32;
case 0x0c09bd34u: goto P_0c09bd34;
case 0x0c09bd36u: goto P_0c09bd36;
case 0x0c09bd38u: goto P_0c09bd38;
case 0x0c09bd3au: goto P_0c09bd3a;
case 0x0c09bd3cu: goto P_0c09bd3c;
case 0x0c09bd3eu: goto P_0c09bd3e;
case 0x0c09bd40u: goto P_0c09bd40;
case 0x0c09bd42u: goto P_0c09bd42;
case 0x0c09bd44u: goto P_0c09bd44;
case 0x0c09bd46u: goto P_0c09bd46;
case 0x0c09bd48u: goto P_0c09bd48;
case 0x0c09bd4au: goto P_0c09bd4a;
case 0x0c09bd4cu: goto P_0c09bd4c;
case 0x0c09bd4eu: goto P_0c09bd4e;
case 0x0c09bd50u: goto P_0c09bd50;
case 0x0c09bd52u: goto P_0c09bd52;
case 0x0c09bd54u: goto P_0c09bd54;
case 0x0c09bd56u: goto P_0c09bd56;
case 0x0c09bd58u: goto P_0c09bd58;
case 0x0c09bd5au: goto P_0c09bd5a;
case 0x0c09bd5cu: goto P_0c09bd5c;
case 0x0c09bd5eu: goto P_0c09bd5e;
case 0x0c09bd60u: goto P_0c09bd60;
case 0x0c09bd62u: goto P_0c09bd62;
case 0x0c09bd64u: goto P_0c09bd64;
case 0x0c09bd66u: goto P_0c09bd66;
case 0x0c09bd68u: goto P_0c09bd68;
case 0x0c09bd6au: goto P_0c09bd6a;
case 0x0c09bd6cu: goto P_0c09bd6c;
case 0x0c09bd6eu: goto P_0c09bd6e;
case 0x0c09bd70u: goto P_0c09bd70;
case 0x0c09bd72u: goto P_0c09bd72;
case 0x0c09bd74u: goto P_0c09bd74;
case 0x0c09bd76u: goto P_0c09bd76;
case 0x0c09bd78u: goto P_0c09bd78;
case 0x0c09bd7au: goto P_0c09bd7a;
case 0x0c09bd7cu: goto P_0c09bd7c;
case 0x0c09bd7eu: goto P_0c09bd7e;
case 0x0c09bd80u: goto P_0c09bd80;
case 0x0c09bd82u: goto P_0c09bd82;
case 0x0c09bd84u: goto P_0c09bd84;
case 0x0c09bd86u: goto P_0c09bd86;
case 0x0c09bd88u: goto P_0c09bd88;
case 0x0c09bd8au: goto P_0c09bd8a;
case 0x0c09bd8cu: goto P_0c09bd8c;
case 0x0c09bd8eu: goto P_0c09bd8e;
case 0x0c09bd90u: goto P_0c09bd90;
case 0x0c09bd92u: goto P_0c09bd92;
case 0x0c09bd94u: goto P_0c09bd94;
case 0x0c09bd96u: goto P_0c09bd96;
case 0x0c09bd98u: goto P_0c09bd98;
case 0x0c09bd9au: goto P_0c09bd9a;
case 0x0c09bd9cu: goto P_0c09bd9c;
case 0x0c09bd9eu: goto P_0c09bd9e;
case 0x0c09bda0u: goto P_0c09bda0;
case 0x0c09bda2u: goto P_0c09bda2;
case 0x0c09bda4u: goto P_0c09bda4;
case 0x0c09bda6u: goto P_0c09bda6;
case 0x0c09bda8u: goto P_0c09bda8;
case 0x0c09bdaau: goto P_0c09bdaa;
case 0x0c09bdacu: goto P_0c09bdac;
case 0x0c09bdaeu: goto P_0c09bdae;
case 0x0c09bdb0u: goto P_0c09bdb0;
case 0x0c09bdb2u: goto P_0c09bdb2;
case 0x0c09bdb4u: goto P_0c09bdb4;
case 0x0c09bdb6u: goto P_0c09bdb6;
case 0x0c09bdb8u: goto P_0c09bdb8;
case 0x0c09bdbau: goto P_0c09bdba;
case 0x0c09bdbcu: goto P_0c09bdbc;
case 0x0c09bdbeu: goto P_0c09bdbe;
case 0x0c09bdc0u: goto P_0c09bdc0;
case 0x0c09bdc2u: goto P_0c09bdc2;
case 0x0c09bdc4u: goto P_0c09bdc4;
case 0x0c09bdc6u: goto P_0c09bdc6;
case 0x0c09bdc8u: goto P_0c09bdc8;
case 0x0c09bdcau: goto P_0c09bdca;
case 0x0c09bdccu: goto P_0c09bdcc;
case 0x0c09bdceu: goto P_0c09bdce;
case 0x0c09bddau: goto P_0c09bdda;
case 0x0c09bddcu: goto P_0c09bddc;
case 0x0c09bddeu: goto P_0c09bdde;
case 0x0c09bde0u: goto P_0c09bde0;
case 0x0c09bde2u: goto P_0c09bde2;
case 0x0c09bde4u: goto P_0c09bde4;
case 0x0c09bde6u: goto P_0c09bde6;
case 0x0c09bde8u: goto P_0c09bde8;
case 0x0c09bdeau: goto P_0c09bdea;
case 0x0c09bdecu: goto P_0c09bdec;
case 0x0c09bdeeu: goto P_0c09bdee;
case 0x0c09bdf0u: goto P_0c09bdf0;
case 0x0c09bdf2u: goto P_0c09bdf2;
case 0x0c09bdf4u: goto P_0c09bdf4;
case 0x0c09bdf6u: goto P_0c09bdf6;
case 0x0c09bdf8u: goto P_0c09bdf8;
case 0x0c09bdfau: goto P_0c09bdfa;
case 0x0c09bdfcu: goto P_0c09bdfc;
case 0x0c09bdfeu: goto P_0c09bdfe;
case 0x0c09be00u: goto P_0c09be00;
case 0x0c09be02u: goto P_0c09be02;
case 0x0c09be04u: goto P_0c09be04;
case 0x0c09be06u: goto P_0c09be06;
case 0x0c09be08u: goto P_0c09be08;
case 0x0c09be0au: goto P_0c09be0a;
case 0x0c09be0cu: goto P_0c09be0c;
case 0x0c09be0eu: goto P_0c09be0e;
case 0x0c09be10u: goto P_0c09be10;
case 0x0c09be12u: goto P_0c09be12;
case 0x0c09be14u: goto P_0c09be14;
case 0x0c09be16u: goto P_0c09be16;
case 0x0c09be18u: goto P_0c09be18;
case 0x0c09be1au: goto P_0c09be1a;
case 0x0c09be1cu: goto P_0c09be1c;
case 0x0c09be1eu: goto P_0c09be1e;
case 0x0c09be20u: goto P_0c09be20;
case 0x0c09be22u: goto P_0c09be22;
case 0x0c09be24u: goto P_0c09be24;
case 0x0c09be26u: goto P_0c09be26;
case 0x0c09be28u: goto P_0c09be28;
case 0x0c09be2au: goto P_0c09be2a;
case 0x0c09be2cu: goto P_0c09be2c;
case 0x0c09be2eu: goto P_0c09be2e;
case 0x0c09be30u: goto P_0c09be30;
case 0x0c09be32u: goto P_0c09be32;
case 0x0c09be34u: goto P_0c09be34;
case 0x0c09be36u: goto P_0c09be36;
case 0x0c09be38u: goto P_0c09be38;
case 0x0c09be3au: goto P_0c09be3a;
case 0x0c09be3cu: goto P_0c09be3c;
case 0x0c09be3eu: goto P_0c09be3e;
case 0x0c09be40u: goto P_0c09be40;
case 0x0c09be42u: goto P_0c09be42;
case 0x0c09be44u: goto P_0c09be44;
case 0x0c09be46u: goto P_0c09be46;
case 0x0c09be48u: goto P_0c09be48;
case 0x0c09be4au: goto P_0c09be4a;
case 0x0c09be4cu: goto P_0c09be4c;
case 0x0c09be4eu: goto P_0c09be4e;
case 0x0c09be50u: goto P_0c09be50;
case 0x0c09be52u: goto P_0c09be52;
case 0x0c09be54u: goto P_0c09be54;
case 0x0c09be56u: goto P_0c09be56;
case 0x0c09be58u: goto P_0c09be58;
case 0x0c09be5au: goto P_0c09be5a;
case 0x0c09be5cu: goto P_0c09be5c;
case 0x0c09be5eu: goto P_0c09be5e;
case 0x0c09be60u: goto P_0c09be60;
case 0x0c09be62u: goto P_0c09be62;
case 0x0c09be64u: goto P_0c09be64;
case 0x0c09be66u: goto P_0c09be66;
case 0x0c09be68u: goto P_0c09be68;
case 0x0c09be6au: goto P_0c09be6a;
case 0x0c09be6cu: goto P_0c09be6c;
case 0x0c09be6eu: goto P_0c09be6e;
case 0x0c09be70u: goto P_0c09be70;
case 0x0c09be72u: goto P_0c09be72;
case 0x0c09be74u: goto P_0c09be74;
case 0x0c09be76u: goto P_0c09be76;
case 0x0c09be78u: goto P_0c09be78;
case 0x0c09be7au: goto P_0c09be7a;
case 0x0c09be7cu: goto P_0c09be7c;
case 0x0c09be7eu: goto P_0c09be7e;
case 0x0c09be80u: goto P_0c09be80;
case 0x0c09be82u: goto P_0c09be82;
case 0x0c09be84u: goto P_0c09be84;
case 0x0c09be86u: goto P_0c09be86;
case 0x0c09be88u: goto P_0c09be88;
case 0x0c09be8au: goto P_0c09be8a;
case 0x0c09be8cu: goto P_0c09be8c;
case 0x0c09be8eu: goto P_0c09be8e;
case 0x0c09be90u: goto P_0c09be90;
case 0x0c09be92u: goto P_0c09be92;
case 0x0c09be94u: goto P_0c09be94;
case 0x0c09be96u: goto P_0c09be96;
case 0x0c09be98u: goto P_0c09be98;
case 0x0c09be9au: goto P_0c09be9a;
case 0x0c09be9cu: goto P_0c09be9c;
case 0x0c09be9eu: goto P_0c09be9e;
case 0x0c09bea0u: goto P_0c09bea0;
case 0x0c09bea2u: goto P_0c09bea2;
case 0x0c09bea4u: goto P_0c09bea4;
case 0x0c09bea6u: goto P_0c09bea6;
case 0x0c09bea8u: goto P_0c09bea8;
case 0x0c09beaau: goto P_0c09beaa;
case 0x0c09beacu: goto P_0c09beac;
case 0x0c09beaeu: goto P_0c09beae;
case 0x0c09beb0u: goto P_0c09beb0;
case 0x0c09beb2u: goto P_0c09beb2;
case 0x0c09beb4u: goto P_0c09beb4;
case 0x0c09beb6u: goto P_0c09beb6;
case 0x0c09bed0u: goto P_0c09bed0;
case 0x0c09bed2u: goto P_0c09bed2;
case 0x0c09bed4u: goto P_0c09bed4;
case 0x0c09bed6u: goto P_0c09bed6;
case 0x0c09bed8u: goto P_0c09bed8;
case 0x0c09bedau: goto P_0c09beda;
case 0x0c09bedcu: goto P_0c09bedc;
case 0x0c09bedeu: goto P_0c09bede;
case 0x0c09bee0u: goto P_0c09bee0;
case 0x0c09bee2u: goto P_0c09bee2;
case 0x0c09bee4u: goto P_0c09bee4;
case 0x0c09bee6u: goto P_0c09bee6;
case 0x0c09bee8u: goto P_0c09bee8;
case 0x0c09beeau: goto P_0c09beea;
case 0x0c09beecu: goto P_0c09beec;
case 0x0c09beeeu: goto P_0c09beee;
case 0x0c09bef0u: goto P_0c09bef0;
case 0x0c09bef2u: goto P_0c09bef2;
case 0x0c09bef4u: goto P_0c09bef4;
case 0x0c09bef6u: goto P_0c09bef6;
case 0x0c09bef8u: goto P_0c09bef8;
case 0x0c09befau: goto P_0c09befa;
case 0x0c09ca8eu: goto P_0c09ca8e;
case 0x0c09ca90u: goto P_0c09ca90;
case 0x0c09ca92u: goto P_0c09ca92;
case 0x0c09ca94u: goto P_0c09ca94;
case 0x0c09ca96u: goto P_0c09ca96;
case 0x0c09ca98u: goto P_0c09ca98;
case 0x0c09ca9au: goto P_0c09ca9a;
case 0x0c09ca9cu: goto P_0c09ca9c;
case 0x0c09ca9eu: goto P_0c09ca9e;
case 0x0c09caa0u: goto P_0c09caa0;
case 0x0c09caa2u: goto P_0c09caa2;
case 0x0c09caa4u: goto P_0c09caa4;
case 0x0c09caa6u: goto P_0c09caa6;
case 0x0c09caa8u: goto P_0c09caa8;
case 0x0c09caaau: goto P_0c09caaa;
case 0x0c09caacu: goto P_0c09caac;
case 0x0c09caaeu: goto P_0c09caae;
case 0x0c09cab0u: goto P_0c09cab0;
case 0x0c09cab2u: goto P_0c09cab2;
case 0x0c09cab4u: goto P_0c09cab4;
case 0x0c09cab6u: goto P_0c09cab6;
case 0x0c09cab8u: goto P_0c09cab8;
case 0x0c09cabau: goto P_0c09caba;
case 0x0c09cabcu: goto P_0c09cabc;
case 0x0c09cabeu: goto P_0c09cabe;
case 0x0c09cac0u: goto P_0c09cac0;
case 0x0c09cac2u: goto P_0c09cac2;
case 0x0c09cac4u: goto P_0c09cac4;
case 0x0c09cac6u: goto P_0c09cac6;
case 0x0c09cac8u: goto P_0c09cac8;
case 0x0c09cacau: goto P_0c09caca;
case 0x0c09caccu: goto P_0c09cacc;
case 0x0c09caceu: goto P_0c09cace;
case 0x0c09cad0u: goto P_0c09cad0;
case 0x0c09cad2u: goto P_0c09cad2;
case 0x0c09cad4u: goto P_0c09cad4;
case 0x0c09cad6u: goto P_0c09cad6;
case 0x0c09cad8u: goto P_0c09cad8;
case 0x0c09cadau: goto P_0c09cada;
case 0x0c09cadcu: goto P_0c09cadc;
case 0x0c09cadeu: goto P_0c09cade;
case 0x0c09cae0u: goto P_0c09cae0;
case 0x0c09cae2u: goto P_0c09cae2;
case 0x0c09cae4u: goto P_0c09cae4;
case 0x0c09cae6u: goto P_0c09cae6;
case 0x0c09cae8u: goto P_0c09cae8;
case 0x0c09caeau: goto P_0c09caea;
case 0x0c09caecu: goto P_0c09caec;
case 0x0c09caeeu: goto P_0c09caee;
case 0x0c09caf0u: goto P_0c09caf0;
case 0x0c09caf2u: goto P_0c09caf2;
case 0x0c09caf4u: goto P_0c09caf4;
case 0x0c09caf6u: goto P_0c09caf6;
case 0x0c09caf8u: goto P_0c09caf8;
case 0x0c09cafau: goto P_0c09cafa;
case 0x0c09cafcu: goto P_0c09cafc;
case 0x0c09cafeu: goto P_0c09cafe;
case 0x0c09cb00u: goto P_0c09cb00;
case 0x0c09cb02u: goto P_0c09cb02;
case 0x0c09cb04u: goto P_0c09cb04;
case 0x0c09cb06u: goto P_0c09cb06;
case 0x0c09cb08u: goto P_0c09cb08;
case 0x0c09cb0au: goto P_0c09cb0a;
case 0x0c09cb0cu: goto P_0c09cb0c;
case 0x0c09cb0eu: goto P_0c09cb0e;
case 0x0c09cb10u: goto P_0c09cb10;
case 0x0c09cb12u: goto P_0c09cb12;
case 0x0c09cb14u: goto P_0c09cb14;
case 0x0c09cb16u: goto P_0c09cb16;
case 0x0c09cb18u: goto P_0c09cb18;
case 0x0c09cb1au: goto P_0c09cb1a;
case 0x0c09cb1cu: goto P_0c09cb1c;
case 0x0c09cb1eu: goto P_0c09cb1e;
case 0x0c09cb20u: goto P_0c09cb20;
case 0x0c09cb22u: goto P_0c09cb22;
case 0x0c09cb24u: goto P_0c09cb24;
case 0x0c09cb26u: goto P_0c09cb26;
case 0x0c09cb28u: goto P_0c09cb28;
case 0x0c09cb2au: goto P_0c09cb2a;
case 0x0c09cb2cu: goto P_0c09cb2c;
case 0x0c09cb2eu: goto P_0c09cb2e;
case 0x0c09cb30u: goto P_0c09cb30;
case 0x0c09cb32u: goto P_0c09cb32;
case 0x0c09cb34u: goto P_0c09cb34;
case 0x0c09cb36u: goto P_0c09cb36;
case 0x0c09cb38u: goto P_0c09cb38;
case 0x0c09cb50u: goto P_0c09cb50;
case 0x0c09cb52u: goto P_0c09cb52;
case 0x0c09cb54u: goto P_0c09cb54;
case 0x0c09cb56u: goto P_0c09cb56;
case 0x0c09cb58u: goto P_0c09cb58;
case 0x0c09cb5au: goto P_0c09cb5a;
case 0x0c09cb5cu: goto P_0c09cb5c;
case 0x0c09cb5eu: goto P_0c09cb5e;
case 0x0c09cb60u: goto P_0c09cb60;
case 0x0c09cb62u: goto P_0c09cb62;
case 0x0c09cb64u: goto P_0c09cb64;
case 0x0c09cb66u: goto P_0c09cb66;
case 0x0c09cb68u: goto P_0c09cb68;
case 0x0c09cb6au: goto P_0c09cb6a;
case 0x0c09cb6cu: goto P_0c09cb6c;
case 0x0c09cb6eu: goto P_0c09cb6e;
case 0x0c09cb70u: goto P_0c09cb70;
case 0x0c09cb72u: goto P_0c09cb72;
case 0x0c09cb74u: goto P_0c09cb74;
case 0x0c09cb76u: goto P_0c09cb76;
case 0x0c09cb78u: goto P_0c09cb78;
case 0x0c09cb7au: goto P_0c09cb7a;
case 0x0c09cb7cu: goto P_0c09cb7c;
case 0x0c09cb7eu: goto P_0c09cb7e;
case 0x0c09cb80u: goto P_0c09cb80;
case 0x0c09cb82u: goto P_0c09cb82;
case 0x0c09cb84u: goto P_0c09cb84;
case 0x0c09cb86u: goto P_0c09cb86;
case 0x0c09cb88u: goto P_0c09cb88;
case 0x0c09cb8au: goto P_0c09cb8a;
case 0x0c09cb8cu: goto P_0c09cb8c;
case 0x0c09cb8eu: goto P_0c09cb8e;
case 0x0c09cb90u: goto P_0c09cb90;
case 0x0c09cb92u: goto P_0c09cb92;
case 0x0c09cb94u: goto P_0c09cb94;
case 0x0c09cb96u: goto P_0c09cb96;
case 0x0c09cb98u: goto P_0c09cb98;
case 0x0c09cb9au: goto P_0c09cb9a;
case 0x0c09cb9cu: goto P_0c09cb9c;
case 0x0c09cb9eu: goto P_0c09cb9e;
case 0x0c09cba0u: goto P_0c09cba0;
case 0x0c09cba2u: goto P_0c09cba2;
case 0x0c09cba4u: goto P_0c09cba4;
case 0x0c09cba6u: goto P_0c09cba6;
case 0x0c09cba8u: goto P_0c09cba8;
case 0x0c09cbaau: goto P_0c09cbaa;
case 0x0c09cbacu: goto P_0c09cbac;
case 0x0c09cbaeu: goto P_0c09cbae;
case 0x0c09cbb0u: goto P_0c09cbb0;
case 0x0c09cbb2u: goto P_0c09cbb2;
case 0x0c09cbb4u: goto P_0c09cbb4;
case 0x0c09cbb6u: goto P_0c09cbb6;
case 0x0c09cbb8u: goto P_0c09cbb8;
case 0x0c09cbbau: goto P_0c09cbba;
case 0x0c09cbbcu: goto P_0c09cbbc;
case 0x0c09cbbeu: goto P_0c09cbbe;
case 0x0c09cbc0u: goto P_0c09cbc0;
case 0x0c09cbc2u: goto P_0c09cbc2;
case 0x0c09cbc4u: goto P_0c09cbc4;
case 0x0c09cbc6u: goto P_0c09cbc6;
case 0x0c09cbc8u: goto P_0c09cbc8;
case 0x0c09cbcau: goto P_0c09cbca;
case 0x0c09cbccu: goto P_0c09cbcc;
case 0x0c09cbceu: goto P_0c09cbce;
case 0x0c09cbd0u: goto P_0c09cbd0;
case 0x0c09cbd2u: goto P_0c09cbd2;
case 0x0c09cbd4u: goto P_0c09cbd4;
case 0x0c09cbd6u: goto P_0c09cbd6;
case 0x0c09cbd8u: goto P_0c09cbd8;
case 0x0c09cbdau: goto P_0c09cbda;
case 0x0c09cbdcu: goto P_0c09cbdc;
case 0x0c09cbdeu: goto P_0c09cbde;
case 0x0c09cbe0u: goto P_0c09cbe0;
case 0x0c09cbe2u: goto P_0c09cbe2;
case 0x0c09cbe4u: goto P_0c09cbe4;
case 0x0c09cbe6u: goto P_0c09cbe6;
case 0x0c09cbe8u: goto P_0c09cbe8;
case 0x0c09cbeau: goto P_0c09cbea;
case 0x0c09cbecu: goto P_0c09cbec;
case 0x0c09cbeeu: goto P_0c09cbee;
case 0x0c09cbf0u: goto P_0c09cbf0;
case 0x0c09cbf2u: goto P_0c09cbf2;
case 0x0c09cbf4u: goto P_0c09cbf4;
case 0x0c09cbf6u: goto P_0c09cbf6;
case 0x0c09cbf8u: goto P_0c09cbf8;
case 0x0c09cbfau: goto P_0c09cbfa;
case 0x0c09cbfcu: goto P_0c09cbfc;
case 0x0c09cbfeu: goto P_0c09cbfe;
case 0x0c09cc00u: goto P_0c09cc00;
case 0x0c09cc02u: goto P_0c09cc02;
case 0x0c09cc04u: goto P_0c09cc04;
case 0x0c09cc06u: goto P_0c09cc06;
case 0x0c09cc08u: goto P_0c09cc08;
case 0x0c09cc0au: goto P_0c09cc0a;
case 0x0c09cc0cu: goto P_0c09cc0c;
case 0x0c09cc0eu: goto P_0c09cc0e;
case 0x0c09cc10u: goto P_0c09cc10;
case 0x0c09cc12u: goto P_0c09cc12;
case 0x0c09cc14u: goto P_0c09cc14;
case 0x0c09cc16u: goto P_0c09cc16;
case 0x0c09cc18u: goto P_0c09cc18;
case 0x0c09cc1au: goto P_0c09cc1a;
case 0x0c09cc1cu: goto P_0c09cc1c;
case 0x0c09cc1eu: goto P_0c09cc1e;
case 0x0c09cc30u: goto P_0c09cc30;
case 0x0c09cc32u: goto P_0c09cc32;
case 0x0c09cc34u: goto P_0c09cc34;
case 0x0c09cc36u: goto P_0c09cc36;
case 0x0c09cc38u: goto P_0c09cc38;
case 0x0c09cc3au: goto P_0c09cc3a;
case 0x0c09cc3cu: goto P_0c09cc3c;
case 0x0c09cc3eu: goto P_0c09cc3e;
case 0x0c09cc40u: goto P_0c09cc40;
case 0x0c09cc42u: goto P_0c09cc42;
case 0x0c09cc44u: goto P_0c09cc44;
case 0x0c09cc46u: goto P_0c09cc46;
case 0x0c09cc48u: goto P_0c09cc48;
case 0x0c09cc4au: goto P_0c09cc4a;
case 0x0c09cc4cu: goto P_0c09cc4c;
case 0x0c09cc4eu: goto P_0c09cc4e;
case 0x0c09cc50u: goto P_0c09cc50;
case 0x0c09cc52u: goto P_0c09cc52;
case 0x0c09cc54u: goto P_0c09cc54;
case 0x0c09cc56u: goto P_0c09cc56;
case 0x0c09cc58u: goto P_0c09cc58;
case 0x0c09cc5au: goto P_0c09cc5a;
case 0x0c09cc5cu: goto P_0c09cc5c;
case 0x0c09cc5eu: goto P_0c09cc5e;
case 0x0c09cc60u: goto P_0c09cc60;
case 0x0c09cc62u: goto P_0c09cc62;
case 0x0c09cc64u: goto P_0c09cc64;
case 0x0c09cc66u: goto P_0c09cc66;
case 0x0c09cc68u: goto P_0c09cc68;
case 0x0c09cc6au: goto P_0c09cc6a;
case 0x0c09cc6cu: goto P_0c09cc6c;
case 0x0c09cc6eu: goto P_0c09cc6e;
case 0x0c09cc70u: goto P_0c09cc70;
case 0x0c09cc72u: goto P_0c09cc72;
case 0x0c09cc74u: goto P_0c09cc74;
case 0x0c09cc76u: goto P_0c09cc76;
case 0x0c09cc78u: goto P_0c09cc78;
case 0x0c09cc7au: goto P_0c09cc7a;
case 0x0c09cc7cu: goto P_0c09cc7c;
case 0x0c09cc7eu: goto P_0c09cc7e;
case 0x0c09cc80u: goto P_0c09cc80;
case 0x0c09cc82u: goto P_0c09cc82;
case 0x0c09cc84u: goto P_0c09cc84;
case 0x0c09cc86u: goto P_0c09cc86;
case 0x0c09cc88u: goto P_0c09cc88;
case 0x0c09cc8au: goto P_0c09cc8a;
case 0x0c09cc8cu: goto P_0c09cc8c;
case 0x0c09cc8eu: goto P_0c09cc8e;
case 0x0c09cc90u: goto P_0c09cc90;
case 0x0c09cc92u: goto P_0c09cc92;
case 0x0c09cc94u: goto P_0c09cc94;
case 0x0c09cc96u: goto P_0c09cc96;
case 0x0c09cc98u: goto P_0c09cc98;
case 0x0c09cc9au: goto P_0c09cc9a;
case 0x0c09cc9cu: goto P_0c09cc9c;
case 0x0c09cc9eu: goto P_0c09cc9e;
case 0x0c09cca0u: goto P_0c09cca0;
case 0x0c09cca2u: goto P_0c09cca2;
case 0x0c09cca4u: goto P_0c09cca4;
case 0x0c09cca6u: goto P_0c09cca6;
case 0x0c09cca8u: goto P_0c09cca8;
case 0x0c09ccaau: goto P_0c09ccaa;
case 0x0c09ccacu: goto P_0c09ccac;
case 0x0c09ccaeu: goto P_0c09ccae;
case 0x0c09ccb0u: goto P_0c09ccb0;
case 0x0c09ccb2u: goto P_0c09ccb2;
case 0x0c09ccb4u: goto P_0c09ccb4;
case 0x0c09ccb6u: goto P_0c09ccb6;
case 0x0c09ccb8u: goto P_0c09ccb8;
case 0x0c09ccbau: goto P_0c09ccba;
case 0x0c09ccbcu: goto P_0c09ccbc;
case 0x0c09ccbeu: goto P_0c09ccbe;
case 0x0c09ccc0u: goto P_0c09ccc0;
case 0x0c09ccc2u: goto P_0c09ccc2;
case 0x0c09ccc4u: goto P_0c09ccc4;
case 0x0c09ccc6u: goto P_0c09ccc6;
case 0x0c09ccc8u: goto P_0c09ccc8;
case 0x0c09cccau: goto P_0c09ccca;
case 0x0c09ccccu: goto P_0c09cccc;
case 0x0c09ccceu: goto P_0c09ccce;
case 0x0c09ccd0u: goto P_0c09ccd0;
case 0x0c09ccd2u: goto P_0c09ccd2;
case 0x0c09ccd4u: goto P_0c09ccd4;
case 0x0c09ccd6u: goto P_0c09ccd6;
case 0x0c09ccd8u: goto P_0c09ccd8;
case 0x0c09ccdau: goto P_0c09ccda;
case 0x0c09ccdcu: goto P_0c09ccdc;
case 0x0c09ccdeu: goto P_0c09ccde;
case 0x0c09cce0u: goto P_0c09cce0;
case 0x0c09cce2u: goto P_0c09cce2;
case 0x0c09cce4u: goto P_0c09cce4;
case 0x0c09cce6u: goto P_0c09cce6;
case 0x0c09cce8u: goto P_0c09cce8;
case 0x0c09cceau: goto P_0c09ccea;
case 0x0c09ccecu: goto P_0c09ccec;
case 0x0c09cceeu: goto P_0c09ccee;
case 0x0c09ccf0u: goto P_0c09ccf0;
case 0x0c09ccf2u: goto P_0c09ccf2;
case 0x0c09ccf4u: goto P_0c09ccf4;
case 0x0c09ccf6u: goto P_0c09ccf6;
case 0x0c09ccf8u: goto P_0c09ccf8;
case 0x0c09ccfau: goto P_0c09ccfa;
case 0x0c09ccfcu: goto P_0c09ccfc;
case 0x0c09ccfeu: goto P_0c09ccfe;
case 0x0c09cd00u: goto P_0c09cd00;
case 0x0c09cd02u: goto P_0c09cd02;
case 0x0c09cd04u: goto P_0c09cd04;
case 0x0c09cd06u: goto P_0c09cd06;
case 0x0c09cd08u: goto P_0c09cd08;
case 0x0c09cd0au: goto P_0c09cd0a;
case 0x0c09cd0cu: goto P_0c09cd0c;
case 0x0c09cd0eu: goto P_0c09cd0e;
case 0x0c09cd10u: goto P_0c09cd10;
case 0x0c09cd12u: goto P_0c09cd12;
case 0x0c09cd38u: goto P_0c09cd38;
case 0x0c09cd3au: goto P_0c09cd3a;
case 0x0c09cd3cu: goto P_0c09cd3c;
case 0x0c09cd3eu: goto P_0c09cd3e;
case 0x0c09cd40u: goto P_0c09cd40;
case 0x0c09cd42u: goto P_0c09cd42;
case 0x0c09cd44u: goto P_0c09cd44;
case 0x0c09cd46u: goto P_0c09cd46;
case 0x0c09cd48u: goto P_0c09cd48;
case 0x0c09cd4au: goto P_0c09cd4a;
case 0x0c09cd4cu: goto P_0c09cd4c;
case 0x0c09cd4eu: goto P_0c09cd4e;
case 0x0c09cd50u: goto P_0c09cd50;
case 0x0c09cd52u: goto P_0c09cd52;
case 0x0c09cd54u: goto P_0c09cd54;
case 0x0c09cd56u: goto P_0c09cd56;
case 0x0c09cd58u: goto P_0c09cd58;
case 0x0c09cd5au: goto P_0c09cd5a;
case 0x0c09cd5cu: goto P_0c09cd5c;
case 0x0c09cd5eu: goto P_0c09cd5e;
case 0x0c09cd60u: goto P_0c09cd60;
case 0x0c09cd62u: goto P_0c09cd62;
case 0x0c09cd64u: goto P_0c09cd64;
case 0x0c09cd66u: goto P_0c09cd66;
case 0x0c09cd68u: goto P_0c09cd68;
case 0x0c09cd6au: goto P_0c09cd6a;
case 0x0c09cd6cu: goto P_0c09cd6c;
case 0x0c09cd6eu: goto P_0c09cd6e;
case 0x0c09cd70u: goto P_0c09cd70;
case 0x0c09cd72u: goto P_0c09cd72;
case 0x0c09cd74u: goto P_0c09cd74;
case 0x0c09cd76u: goto P_0c09cd76;
case 0x0c09cd78u: goto P_0c09cd78;
case 0x0c09cd7au: goto P_0c09cd7a;
case 0x0c09cd7cu: goto P_0c09cd7c;
case 0x0c09cd7eu: goto P_0c09cd7e;
case 0x0c09cd80u: goto P_0c09cd80;
case 0x0c09cd82u: goto P_0c09cd82;
case 0x0c09cd84u: goto P_0c09cd84;
case 0x0c09cd86u: goto P_0c09cd86;
case 0x0c09cd88u: goto P_0c09cd88;
case 0x0c09cd8au: goto P_0c09cd8a;
case 0x0c09cd8cu: goto P_0c09cd8c;
case 0x0c09cd8eu: goto P_0c09cd8e;
case 0x0c09cd90u: goto P_0c09cd90;
case 0x0c09cd92u: goto P_0c09cd92;
case 0x0c09cd94u: goto P_0c09cd94;
case 0x0c09cd96u: goto P_0c09cd96;
case 0x0c09cd98u: goto P_0c09cd98;
case 0x0c09cd9au: goto P_0c09cd9a;
case 0x0c09cd9cu: goto P_0c09cd9c;
case 0x0c09cd9eu: goto P_0c09cd9e;
case 0x0c09cda0u: goto P_0c09cda0;
case 0x0c09cda2u: goto P_0c09cda2;
case 0x0c09cda4u: goto P_0c09cda4;
case 0x0c09cda6u: goto P_0c09cda6;
case 0x0c09cda8u: goto P_0c09cda8;
case 0x0c09cdaau: goto P_0c09cdaa;
case 0x0c09cdacu: goto P_0c09cdac;
case 0x0c09cdaeu: goto P_0c09cdae;
case 0x0c09cdb0u: goto P_0c09cdb0;
case 0x0c09cdb2u: goto P_0c09cdb2;
case 0x0c09cdb4u: goto P_0c09cdb4;
case 0x0c09cdb6u: goto P_0c09cdb6;
case 0x0c09cdb8u: goto P_0c09cdb8;
case 0x0c09cdbau: goto P_0c09cdba;
case 0x0c09cdbcu: goto P_0c09cdbc;
case 0x0c09cdbeu: goto P_0c09cdbe;
case 0x0c09cdc0u: goto P_0c09cdc0;
case 0x0c09cdecu: goto P_0c09cdec;
case 0x0c09cdeeu: goto P_0c09cdee;
case 0x0c09cdf0u: goto P_0c09cdf0;
case 0x0c09cdf2u: goto P_0c09cdf2;
case 0x0c09cdf4u: goto P_0c09cdf4;
case 0x0c09cdf6u: goto P_0c09cdf6;
case 0x0c09cdf8u: goto P_0c09cdf8;
case 0x0c09cdfau: goto P_0c09cdfa;
case 0x0c09cdfcu: goto P_0c09cdfc;
case 0x0c09cdfeu: goto P_0c09cdfe;
case 0x0c09ce00u: goto P_0c09ce00;
case 0x0c09ce02u: goto P_0c09ce02;
case 0x0c09ce04u: goto P_0c09ce04;
case 0x0c09ce06u: goto P_0c09ce06;
case 0x0c09ce08u: goto P_0c09ce08;
case 0x0c09ce0au: goto P_0c09ce0a;
case 0x0c09ce0cu: goto P_0c09ce0c;
case 0x0c09ce0eu: goto P_0c09ce0e;
case 0x0c09ce10u: goto P_0c09ce10;
case 0x0c09ce12u: goto P_0c09ce12;
case 0x0c09ce14u: goto P_0c09ce14;
case 0x0c09ce16u: goto P_0c09ce16;
case 0x0c09ce18u: goto P_0c09ce18;
case 0x0c09ce1au: goto P_0c09ce1a;
case 0x0c09ce1cu: goto P_0c09ce1c;
case 0x0c09ce1eu: goto P_0c09ce1e;
case 0x0c09ce20u: goto P_0c09ce20;
case 0x0c09ce22u: goto P_0c09ce22;
case 0x0c09ce24u: goto P_0c09ce24;
case 0x0c09ce26u: goto P_0c09ce26;
case 0x0c09ce28u: goto P_0c09ce28;
case 0x0c09ce2au: goto P_0c09ce2a;
case 0x0c09ce2cu: goto P_0c09ce2c;
case 0x0c09ce2eu: goto P_0c09ce2e;
case 0x0c09ce30u: goto P_0c09ce30;
case 0x0c09ce32u: goto P_0c09ce32;
case 0x0c09ce34u: goto P_0c09ce34;
case 0x0c09ce36u: goto P_0c09ce36;
case 0x0c09ce38u: goto P_0c09ce38;
case 0x0c09ce3au: goto P_0c09ce3a;
case 0x0c09ce3cu: goto P_0c09ce3c;
case 0x0c09ce3eu: goto P_0c09ce3e;
case 0x0c09ce40u: goto P_0c09ce40;
case 0x0c09ce42u: goto P_0c09ce42;
case 0x0c09ce44u: goto P_0c09ce44;
case 0x0c09ce46u: goto P_0c09ce46;
case 0x0c09ce48u: goto P_0c09ce48;
case 0x0c0a1f50u: goto P_0c0a1f50;
case 0x0c0a1f52u: goto P_0c0a1f52;
case 0x0c0a1f54u: goto P_0c0a1f54;
case 0x0c0a1f56u: goto P_0c0a1f56;
case 0x0c0a1f58u: goto P_0c0a1f58;
case 0x0c0a1f5au: goto P_0c0a1f5a;
case 0x0c0a1f5cu: goto P_0c0a1f5c;
case 0x0c0a1f5eu: goto P_0c0a1f5e;
case 0x0c0a1f60u: goto P_0c0a1f60;
case 0x0c0a1f62u: goto P_0c0a1f62;
case 0x0c0a1f64u: goto P_0c0a1f64;
case 0x0c0a1f66u: goto P_0c0a1f66;
case 0x0c0a1f68u: goto P_0c0a1f68;
case 0x0c0a1f6au: goto P_0c0a1f6a;
case 0x0c0a1f6cu: goto P_0c0a1f6c;
case 0x0c0a1f6eu: goto P_0c0a1f6e;
case 0x0c0a1f70u: goto P_0c0a1f70;
case 0x0c0a1f72u: goto P_0c0a1f72;
case 0x0c0a1f74u: goto P_0c0a1f74;
case 0x0c0a1f76u: goto P_0c0a1f76;
case 0x0c0a1f78u: goto P_0c0a1f78;
case 0x0c0a1f7au: goto P_0c0a1f7a;
case 0x0c0a1f7cu: goto P_0c0a1f7c;
case 0x0c0a1f7eu: goto P_0c0a1f7e;
case 0x0c0a1f80u: goto P_0c0a1f80;
case 0x0c0a1f82u: goto P_0c0a1f82;
case 0x0c0a1f84u: goto P_0c0a1f84;
case 0x0c0a1f86u: goto P_0c0a1f86;
case 0x0c0a1f88u: goto P_0c0a1f88;
case 0x0c0a1f8au: goto P_0c0a1f8a;
case 0x0c0a1f8cu: goto P_0c0a1f8c;
case 0x0c0a1f8eu: goto P_0c0a1f8e;
case 0x0c0a1f90u: goto P_0c0a1f90;
case 0x0c0a1f92u: goto P_0c0a1f92;
case 0x0c0a1f94u: goto P_0c0a1f94;
case 0x0c0a1f96u: goto P_0c0a1f96;
case 0x0c0a1f98u: goto P_0c0a1f98;
case 0x0c0a1f9au: goto P_0c0a1f9a;
case 0x0c0a1f9cu: goto P_0c0a1f9c;
case 0x0c0a1f9eu: goto P_0c0a1f9e;
case 0x0c0a1fa0u: goto P_0c0a1fa0;
case 0x0c0a1fa2u: goto P_0c0a1fa2;
case 0x0c0a1fa4u: goto P_0c0a1fa4;
case 0x0c0a1fa6u: goto P_0c0a1fa6;
case 0x0c0a1fa8u: goto P_0c0a1fa8;
case 0x0c0a1faau: goto P_0c0a1faa;
case 0x0c0a1facu: goto P_0c0a1fac;
case 0x0c0a1faeu: goto P_0c0a1fae;
case 0x0c0a1fb0u: goto P_0c0a1fb0;
case 0x0c0a1fb2u: goto P_0c0a1fb2;
case 0x0c0a1fb4u: goto P_0c0a1fb4;
case 0x0c0a1fb6u: goto P_0c0a1fb6;
case 0x0c0a1fb8u: goto P_0c0a1fb8;
case 0x0c0a1fbau: goto P_0c0a1fba;
case 0x0c0a1fbcu: goto P_0c0a1fbc;
case 0x0c0a1fbeu: goto P_0c0a1fbe;
case 0x0c0a1fc0u: goto P_0c0a1fc0;
case 0x0c0a1fc2u: goto P_0c0a1fc2;
case 0x0c0a1fc4u: goto P_0c0a1fc4;
case 0x0c0a1fc6u: goto P_0c0a1fc6;
case 0x0c0a1fc8u: goto P_0c0a1fc8;
case 0x0c0a1fcau: goto P_0c0a1fca;
case 0x0c0a1fccu: goto P_0c0a1fcc;
case 0x0c0a1fceu: goto P_0c0a1fce;
case 0x0c0a1fd0u: goto P_0c0a1fd0;
case 0x0c0a1fd2u: goto P_0c0a1fd2;
case 0x0c0a1fd4u: goto P_0c0a1fd4;
case 0x0c0a1fd6u: goto P_0c0a1fd6;
case 0x0c0a1fd8u: goto P_0c0a1fd8;
case 0x0c0a1fdau: goto P_0c0a1fda;
case 0x0c0a1fdcu: goto P_0c0a1fdc;
case 0x0c0a1fdeu: goto P_0c0a1fde;
case 0x0c0a1fe0u: goto P_0c0a1fe0;
case 0x0c0a1fe2u: goto P_0c0a1fe2;
case 0x0c0a1fe4u: goto P_0c0a1fe4;
case 0x0c0a1fe6u: goto P_0c0a1fe6;
case 0x0c0a1fe8u: goto P_0c0a1fe8;
case 0x0c0a1feau: goto P_0c0a1fea;
case 0x0c0a1fecu: goto P_0c0a1fec;
case 0x0c0a1feeu: goto P_0c0a1fee;
case 0x0c0a1ff0u: goto P_0c0a1ff0;
case 0x0c0a1ff2u: goto P_0c0a1ff2;
case 0x0c0a1ff4u: goto P_0c0a1ff4;
case 0x0c0a22c4u: goto P_0c0a22c4;
case 0x0c0a22c6u: goto P_0c0a22c6;
case 0x0c0a22c8u: goto P_0c0a22c8;
case 0x0c0a22cau: goto P_0c0a22ca;
case 0x0c0a22ccu: goto P_0c0a22cc;
case 0x0c0a22ceu: goto P_0c0a22ce;
case 0x0c0a22d0u: goto P_0c0a22d0;
case 0x0c0a22d2u: goto P_0c0a22d2;
case 0x0c0a22d4u: goto P_0c0a22d4;
case 0x0c0a22d6u: goto P_0c0a22d6;
case 0x0c0a22d8u: goto P_0c0a22d8;
case 0x0c0a22dau: goto P_0c0a22da;
case 0x0c0a22dcu: goto P_0c0a22dc;
case 0x0c0a22deu: goto P_0c0a22de;
case 0x0c0a22e0u: goto P_0c0a22e0;
case 0x0c0a22e2u: goto P_0c0a22e2;
case 0x0c0a22e4u: goto P_0c0a22e4;
case 0x0c0a22e6u: goto P_0c0a22e6;
case 0x0c0a22e8u: goto P_0c0a22e8;
case 0x0c0a22eau: goto P_0c0a22ea;
case 0x0c0a22ecu: goto P_0c0a22ec;
case 0x0c0a22eeu: goto P_0c0a22ee;
case 0x0c0a22f0u: goto P_0c0a22f0;
case 0x0c0a22f2u: goto P_0c0a22f2;
case 0x0c0a22f4u: goto P_0c0a22f4;
case 0x0c0a22f6u: goto P_0c0a22f6;
case 0x0c0a22f8u: goto P_0c0a22f8;
case 0x0c0a22fau: goto P_0c0a22fa;
case 0x0c0a22fcu: goto P_0c0a22fc;
case 0x0c0a22feu: goto P_0c0a22fe;
case 0x0c0a2300u: goto P_0c0a2300;
case 0x0c0a2302u: goto P_0c0a2302;
case 0x0c0a2304u: goto P_0c0a2304;
case 0x0c0a2306u: goto P_0c0a2306;
case 0x0c0a2308u: goto P_0c0a2308;
case 0x0c0a230au: goto P_0c0a230a;
case 0x0c0a230cu: goto P_0c0a230c;
case 0x0c0a230eu: goto P_0c0a230e;
case 0x0c0a2310u: goto P_0c0a2310;
case 0x0c0a2312u: goto P_0c0a2312;
case 0x0c0a2314u: goto P_0c0a2314;
case 0x0c0a2316u: goto P_0c0a2316;
case 0x0c0a2318u: goto P_0c0a2318;
case 0x0c0a231au: goto P_0c0a231a;
case 0x0c0a231cu: goto P_0c0a231c;
case 0x0c0a231eu: goto P_0c0a231e;
case 0x0c0a2320u: goto P_0c0a2320;
case 0x0c0a2322u: goto P_0c0a2322;
case 0x0c0a2324u: goto P_0c0a2324;
case 0x0c0a2326u: goto P_0c0a2326;
case 0x0c0a2328u: goto P_0c0a2328;
case 0x0c0a232au: goto P_0c0a232a;
case 0x0c0a232cu: goto P_0c0a232c;
case 0x0c0a232eu: goto P_0c0a232e;
case 0x0c0a2330u: goto P_0c0a2330;
case 0x0c0a2332u: goto P_0c0a2332;
case 0x0c0a2334u: goto P_0c0a2334;
case 0x0c0a2336u: goto P_0c0a2336;
case 0x0c0a2338u: goto P_0c0a2338;
case 0x0c0a233au: goto P_0c0a233a;
case 0x0c0a233cu: goto P_0c0a233c;
case 0x0c0a233eu: goto P_0c0a233e;
case 0x0c0a2340u: goto P_0c0a2340;
case 0x0c0a2342u: goto P_0c0a2342;
case 0x0c0a2344u: goto P_0c0a2344;
case 0x0c0a2346u: goto P_0c0a2346;
case 0x0c0a2348u: goto P_0c0a2348;
case 0x0c0a234au: goto P_0c0a234a;
case 0x0c0a234cu: goto P_0c0a234c;
case 0x0c0a234eu: goto P_0c0a234e;
case 0x0c0a2350u: goto P_0c0a2350;
case 0x0c0a2352u: goto P_0c0a2352;
case 0x0c0a2354u: goto P_0c0a2354;
case 0x0c0a2356u: goto P_0c0a2356;
case 0x0c0a2358u: goto P_0c0a2358;
case 0x0c0a235au: goto P_0c0a235a;
case 0x0c0a235cu: goto P_0c0a235c;
case 0x0c0a235eu: goto P_0c0a235e;
case 0x0c0a2360u: goto P_0c0a2360;
case 0x0c0a2362u: goto P_0c0a2362;
case 0x0c0a2364u: goto P_0c0a2364;
case 0x0c0a2366u: goto P_0c0a2366;
case 0x0c0a2368u: goto P_0c0a2368;
case 0x0c0a236au: goto P_0c0a236a;
case 0x0c0a236cu: goto P_0c0a236c;
case 0x0c0a236eu: goto P_0c0a236e;
case 0x0c0a2370u: goto P_0c0a2370;
case 0x0c0a2372u: goto P_0c0a2372;
case 0x0c0a2374u: goto P_0c0a2374;
case 0x0c0a2376u: goto P_0c0a2376;
case 0x0c0a2378u: goto P_0c0a2378;
case 0x0c0a237au: goto P_0c0a237a;
case 0x0c0a237cu: goto P_0c0a237c;
case 0x0c0a237eu: goto P_0c0a237e;
case 0x0c0a2380u: goto P_0c0a2380;
case 0x0c0a2382u: goto P_0c0a2382;
case 0x0c0a2384u: goto P_0c0a2384;
case 0x0c0a2386u: goto P_0c0a2386;
case 0x0c0a2388u: goto P_0c0a2388;
case 0x0c0a238au: goto P_0c0a238a;
case 0x0c0a238cu: goto P_0c0a238c;
case 0x0c0a238eu: goto P_0c0a238e;
case 0x0c0a2390u: goto P_0c0a2390;
case 0x0c0a2392u: goto P_0c0a2392;
case 0x0c0a2394u: goto P_0c0a2394;
case 0x0c0a2396u: goto P_0c0a2396;
case 0x0c0a2398u: goto P_0c0a2398;
case 0x0c0a239au: goto P_0c0a239a;
case 0x0c0a239cu: goto P_0c0a239c;
case 0x0c0a239eu: goto P_0c0a239e;
case 0x0c0a23a0u: goto P_0c0a23a0;
case 0x0c0a23a2u: goto P_0c0a23a2;
case 0x0c0a23a4u: goto P_0c0a23a4;
case 0x0c0a23a6u: goto P_0c0a23a6;
case 0x0c0a23a8u: goto P_0c0a23a8;
case 0x0c0a23aau: goto P_0c0a23aa;
case 0x0c0a23acu: goto P_0c0a23ac;
case 0x0c0a23aeu: goto P_0c0a23ae;
case 0x0c0a23b0u: goto P_0c0a23b0;
case 0x0c0a23b2u: goto P_0c0a23b2;
case 0x0c0a23b4u: goto P_0c0a23b4;
case 0x0c0a23b6u: goto P_0c0a23b6;
case 0x0c0a23b8u: goto P_0c0a23b8;
case 0x0c0a23bau: goto P_0c0a23ba;
case 0x0c0a23bcu: goto P_0c0a23bc;
case 0x0c0a240cu: goto P_0c0a240c;
case 0x0c0a240eu: goto P_0c0a240e;
case 0x0c0a2410u: goto P_0c0a2410;
case 0x0c0a2412u: goto P_0c0a2412;
case 0x0c0a2414u: goto P_0c0a2414;
case 0x0c0a2416u: goto P_0c0a2416;
case 0x0c0a2418u: goto P_0c0a2418;
case 0x0c0a241au: goto P_0c0a241a;
case 0x0c0a241cu: goto P_0c0a241c;
case 0x0c0a241eu: goto P_0c0a241e;
case 0x0c0a2420u: goto P_0c0a2420;
case 0x0c0a2422u: goto P_0c0a2422;
case 0x0c0a2424u: goto P_0c0a2424;
case 0x0c0a2426u: goto P_0c0a2426;
case 0x0c0a2428u: goto P_0c0a2428;
case 0x0c0a242au: goto P_0c0a242a;
case 0x0c0a242cu: goto P_0c0a242c;
case 0x0c0a242eu: goto P_0c0a242e;
case 0x0c0a2430u: goto P_0c0a2430;
case 0x0c0a2432u: goto P_0c0a2432;
case 0x0c0a2434u: goto P_0c0a2434;
case 0x0c0a2436u: goto P_0c0a2436;
case 0x0c0a2438u: goto P_0c0a2438;
case 0x0c0a243au: goto P_0c0a243a;
case 0x0c0a243cu: goto P_0c0a243c;
case 0x0c0a243eu: goto P_0c0a243e;
case 0x0c0a2440u: goto P_0c0a2440;
case 0x0c0a2442u: goto P_0c0a2442;
case 0x0c0a2444u: goto P_0c0a2444;
case 0x0c0a2446u: goto P_0c0a2446;
case 0x0c0a2448u: goto P_0c0a2448;
case 0x0c0a244au: goto P_0c0a244a;
case 0x0c0a244cu: goto P_0c0a244c;
case 0x0c0a244eu: goto P_0c0a244e;
case 0x0c0a2450u: goto P_0c0a2450;
case 0x0c0a2452u: goto P_0c0a2452;
case 0x0c0a2454u: goto P_0c0a2454;
case 0x0c0a2456u: goto P_0c0a2456;
case 0x0c0a2458u: goto P_0c0a2458;
case 0x0c0a245au: goto P_0c0a245a;
case 0x0c0a245cu: goto P_0c0a245c;
case 0x0c0a245eu: goto P_0c0a245e;
case 0x0c0a2460u: goto P_0c0a2460;
case 0x0c0a2462u: goto P_0c0a2462;
case 0x0c0a2464u: goto P_0c0a2464;
case 0x0c0a2466u: goto P_0c0a2466;
case 0x0c0a2468u: goto P_0c0a2468;
case 0x0c0a246au: goto P_0c0a246a;
case 0x0c0a246cu: goto P_0c0a246c;
case 0x0c0a246eu: goto P_0c0a246e;
case 0x0c0a2470u: goto P_0c0a2470;
case 0x0c0a2472u: goto P_0c0a2472;
case 0x0c0a2474u: goto P_0c0a2474;
case 0x0c0a2476u: goto P_0c0a2476;
case 0x0c0a2478u: goto P_0c0a2478;
case 0x0c0a247au: goto P_0c0a247a;
case 0x0c0a247cu: goto P_0c0a247c;
case 0x0c0a247eu: goto P_0c0a247e;
case 0x0c0a2480u: goto P_0c0a2480;
case 0x0c0a2482u: goto P_0c0a2482;
case 0x0c0a2484u: goto P_0c0a2484;
case 0x0c0a2486u: goto P_0c0a2486;
case 0x0c0a2488u: goto P_0c0a2488;
case 0x0c0a248au: goto P_0c0a248a;
case 0x0c0a248cu: goto P_0c0a248c;
case 0x0c0a248eu: goto P_0c0a248e;
case 0x0c0a2490u: goto P_0c0a2490;
case 0x0c0a2492u: goto P_0c0a2492;
case 0x0c0a2494u: goto P_0c0a2494;
case 0x0c0a2496u: goto P_0c0a2496;
case 0x0c0a2498u: goto P_0c0a2498;
case 0x0c0a249au: goto P_0c0a249a;
case 0x0c0a249cu: goto P_0c0a249c;
case 0x0c0a249eu: goto P_0c0a249e;
case 0x0c0a24a0u: goto P_0c0a24a0;
case 0x0c0a24a2u: goto P_0c0a24a2;
case 0x0c0a24a4u: goto P_0c0a24a4;
case 0x0c0a6494u: goto P_0c0a6494;
case 0x0c0a6496u: goto P_0c0a6496;
case 0x0c0a6498u: goto P_0c0a6498;
case 0x0c0a649au: goto P_0c0a649a;
case 0x0c0a649cu: goto P_0c0a649c;
case 0x0c0a649eu: goto P_0c0a649e;
case 0x0c0a64a0u: goto P_0c0a64a0;
case 0x0c0a64a2u: goto P_0c0a64a2;
case 0x0c0a64a4u: goto P_0c0a64a4;
case 0x0c0a64a6u: goto P_0c0a64a6;
case 0x0c0a64a8u: goto P_0c0a64a8;
case 0x0c0a64aau: goto P_0c0a64aa;
case 0x0c0a64acu: goto P_0c0a64ac;
case 0x0c0a64aeu: goto P_0c0a64ae;
case 0x0c0a64b0u: goto P_0c0a64b0;
case 0x0c0a64b2u: goto P_0c0a64b2;
case 0x0c0a64b4u: goto P_0c0a64b4;
case 0x0c0a64b6u: goto P_0c0a64b6;
case 0x0c0a64b8u: goto P_0c0a64b8;
case 0x0c0a64bau: goto P_0c0a64ba;
case 0x0c0a64bcu: goto P_0c0a64bc;
case 0x0c0a64beu: goto P_0c0a64be;
case 0x0c0a64c0u: goto P_0c0a64c0;
case 0x0c0a64c2u: goto P_0c0a64c2;
case 0x0c0a64c4u: goto P_0c0a64c4;
case 0x0c0a64c6u: goto P_0c0a64c6;
case 0x0c0a64c8u: goto P_0c0a64c8;
case 0x0c0a64cau: goto P_0c0a64ca;
case 0x0c0a64ccu: goto P_0c0a64cc;
case 0x0c0a64ceu: goto P_0c0a64ce;
case 0x0c0a64d0u: goto P_0c0a64d0;
case 0x0c0a64d2u: goto P_0c0a64d2;
case 0x0c0a64d4u: goto P_0c0a64d4;
case 0x0c0a64d6u: goto P_0c0a64d6;
case 0x0c0a64d8u: goto P_0c0a64d8;
case 0x0c0a64dau: goto P_0c0a64da;
case 0x0c0a64dcu: goto P_0c0a64dc;
case 0x0c0a64deu: goto P_0c0a64de;
case 0x0c0a64e0u: goto P_0c0a64e0;
case 0x0c0a64e2u: goto P_0c0a64e2;
case 0x0c0a64e4u: goto P_0c0a64e4;
case 0x0c0a64e6u: goto P_0c0a64e6;
case 0x0c0a64e8u: goto P_0c0a64e8;
case 0x0c0a64eau: goto P_0c0a64ea;
case 0x0c0a64ecu: goto P_0c0a64ec;
case 0x0c0a64eeu: goto P_0c0a64ee;
case 0x0c0a64f0u: goto P_0c0a64f0;
case 0x0c0a64f2u: goto P_0c0a64f2;
case 0x0c0a64f4u: goto P_0c0a64f4;
case 0x0c0a64f6u: goto P_0c0a64f6;
case 0x0c0a64f8u: goto P_0c0a64f8;
case 0x0c0a64fau: goto P_0c0a64fa;
case 0x0c0a64fcu: goto P_0c0a64fc;
case 0x0c0a64feu: goto P_0c0a64fe;
case 0x0c0a6500u: goto P_0c0a6500;
case 0x0c0a6502u: goto P_0c0a6502;
case 0x0c0a6504u: goto P_0c0a6504;
case 0x0c0a6506u: goto P_0c0a6506;
case 0x0c0a6508u: goto P_0c0a6508;
case 0x0c0a650au: goto P_0c0a650a;
case 0x0c0a650cu: goto P_0c0a650c;
case 0x0c0a650eu: goto P_0c0a650e;
case 0x0c0a6510u: goto P_0c0a6510;
case 0x0c0a6512u: goto P_0c0a6512;
case 0x0c0a6514u: goto P_0c0a6514;
case 0x0c0a6516u: goto P_0c0a6516;
case 0x0c0a6518u: goto P_0c0a6518;
case 0x0c0a651au: goto P_0c0a651a;
case 0x0c0a651cu: goto P_0c0a651c;
case 0x0c0a651eu: goto P_0c0a651e;
case 0x0c0a6520u: goto P_0c0a6520;
case 0x0c0a6522u: goto P_0c0a6522;
case 0x0c0a6524u: goto P_0c0a6524;
case 0x0c0a6526u: goto P_0c0a6526;
case 0x0c0a6528u: goto P_0c0a6528;
case 0x0c0a652au: goto P_0c0a652a;
case 0x0c0a652cu: goto P_0c0a652c;
case 0x0c0a652eu: goto P_0c0a652e;
case 0x0c0a6530u: goto P_0c0a6530;
case 0x0c0a6532u: goto P_0c0a6532;
case 0x0c0a6534u: goto P_0c0a6534;
case 0x0c0a6536u: goto P_0c0a6536;
case 0x0c0a6538u: goto P_0c0a6538;
case 0x0c0a653au: goto P_0c0a653a;
case 0x0c0a653cu: goto P_0c0a653c;
case 0x0c0a653eu: goto P_0c0a653e;
case 0x0c0a6540u: goto P_0c0a6540;
case 0x0c0a6542u: goto P_0c0a6542;
case 0x0c0a6544u: goto P_0c0a6544;
case 0x0c0a6546u: goto P_0c0a6546;
case 0x0c0a6548u: goto P_0c0a6548;
case 0x0c0a654au: goto P_0c0a654a;
case 0x0c0a654cu: goto P_0c0a654c;
case 0x0c0a654eu: goto P_0c0a654e;
case 0x0c0a6550u: goto P_0c0a6550;
case 0x0c0a6552u: goto P_0c0a6552;
case 0x0c0a6554u: goto P_0c0a6554;
case 0x0c0a6556u: goto P_0c0a6556;
case 0x0c0a6558u: goto P_0c0a6558;
case 0x0c0a655au: goto P_0c0a655a;
case 0x0c0a655cu: goto P_0c0a655c;
case 0x0c0a655eu: goto P_0c0a655e;
case 0x0c0a6560u: goto P_0c0a6560;
case 0x0c0a6562u: goto P_0c0a6562;
case 0x0c0a6564u: goto P_0c0a6564;
case 0x0c0a6566u: goto P_0c0a6566;
case 0x0c0a6568u: goto P_0c0a6568;
case 0x0c0a656au: goto P_0c0a656a;
case 0x0c0a656cu: goto P_0c0a656c;
case 0x0c0a656eu: goto P_0c0a656e;
case 0x0c0a6570u: goto P_0c0a6570;
case 0x0c0a6572u: goto P_0c0a6572;
case 0x0c0a6574u: goto P_0c0a6574;
case 0x0c0a6576u: goto P_0c0a6576;
case 0x0c0a6578u: goto P_0c0a6578;
case 0x0c0a657au: goto P_0c0a657a;
case 0x0c0a657cu: goto P_0c0a657c;
case 0x0c0a657eu: goto P_0c0a657e;
case 0x0c0a6580u: goto P_0c0a6580;
case 0x0c0a6582u: goto P_0c0a6582;
case 0x0c0a6584u: goto P_0c0a6584;
case 0x0c0a6586u: goto P_0c0a6586;
case 0x0c0a6588u: goto P_0c0a6588;
case 0x0c0a658au: goto P_0c0a658a;
case 0x0c0a658cu: goto P_0c0a658c;
case 0x0c0a658eu: goto P_0c0a658e;
case 0x0c0a6590u: goto P_0c0a6590;
case 0x0c0a6592u: goto P_0c0a6592;
case 0x0c0a6594u: goto P_0c0a6594;
case 0x0c0a6596u: goto P_0c0a6596;
case 0x0c0a6598u: goto P_0c0a6598;
case 0x0c0a659au: goto P_0c0a659a;
case 0x0c0a659cu: goto P_0c0a659c;
case 0x0c0a659eu: goto P_0c0a659e;
case 0x0c0a65a0u: goto P_0c0a65a0;
case 0x0c0a65a2u: goto P_0c0a65a2;
case 0x0c0a65a4u: goto P_0c0a65a4;
case 0x0c0a65a6u: goto P_0c0a65a6;
case 0x0c0a65a8u: goto P_0c0a65a8;
case 0x0c0a65aau: goto P_0c0a65aa;
case 0x0c0a65acu: goto P_0c0a65ac;
case 0x0c0a65aeu: goto P_0c0a65ae;
case 0x0c0a65b0u: goto P_0c0a65b0;
case 0x0c0a65b2u: goto P_0c0a65b2;
case 0x0c0a65b4u: goto P_0c0a65b4;
case 0x0c0a65b6u: goto P_0c0a65b6;
case 0x0c0a65b8u: goto P_0c0a65b8;
case 0x0c0a65bau: goto P_0c0a65ba;
case 0x0c0a65bcu: goto P_0c0a65bc;
case 0x0c0a65beu: goto P_0c0a65be;
case 0x0c0a65c0u: goto P_0c0a65c0;
case 0x0c0a65c2u: goto P_0c0a65c2;
case 0x0c0a65c4u: goto P_0c0a65c4;
case 0x0c0a65c6u: goto P_0c0a65c6;
case 0x0c0c5f8eu: goto P_0c0c5f8e;
case 0x0c0c5f90u: goto P_0c0c5f90;
case 0x0c0c5f92u: goto P_0c0c5f92;
case 0x0c0c5f94u: goto P_0c0c5f94;
case 0x0c0c5f96u: goto P_0c0c5f96;
case 0x0c0c5f98u: goto P_0c0c5f98;
case 0x0c0c5f9au: goto P_0c0c5f9a;
case 0x0c0c5f9cu: goto P_0c0c5f9c;
case 0x0c0c5f9eu: goto P_0c0c5f9e;
case 0x0c0c5fa0u: goto P_0c0c5fa0;
case 0x0c0c5fa2u: goto P_0c0c5fa2;
case 0x0c0c5fa4u: goto P_0c0c5fa4;
case 0x0c0c5fa6u: goto P_0c0c5fa6;
case 0x0c0c5fa8u: goto P_0c0c5fa8;
case 0x0c0c5faau: goto P_0c0c5faa;
case 0x0c0c5facu: goto P_0c0c5fac;
case 0x0c0c5faeu: goto P_0c0c5fae;
case 0x0c0c5fb0u: goto P_0c0c5fb0;
case 0x0c0c5fb2u: goto P_0c0c5fb2;
case 0x0c0c5fb4u: goto P_0c0c5fb4;
case 0x0c0c5fb6u: goto P_0c0c5fb6;
case 0x0c0c5fb8u: goto P_0c0c5fb8;
case 0x0c0c5fbau: goto P_0c0c5fba;
case 0x0c0c5fbcu: goto P_0c0c5fbc;
case 0x0c0c5fbeu: goto P_0c0c5fbe;
case 0x0c0c5fc0u: goto P_0c0c5fc0;
case 0x0c0c5fc2u: goto P_0c0c5fc2;
case 0x0c0c5fc4u: goto P_0c0c5fc4;
case 0x0c0c5fc6u: goto P_0c0c5fc6;
case 0x0c0c5fc8u: goto P_0c0c5fc8;
case 0x0c0c5fcau: goto P_0c0c5fca;
case 0x0c0c5fccu: goto P_0c0c5fcc;
case 0x0c0c5fceu: goto P_0c0c5fce;
case 0x0c0c5fd0u: goto P_0c0c5fd0;
case 0x0c0c5fd2u: goto P_0c0c5fd2;
case 0x0c0c8d60u: goto P_0c0c8d60;
case 0x0c0c8d62u: goto P_0c0c8d62;
case 0x0c0c8d64u: goto P_0c0c8d64;
case 0x0c0c8d66u: goto P_0c0c8d66;
case 0x0c0c8d68u: goto P_0c0c8d68;
case 0x0c0c8d6au: goto P_0c0c8d6a;
case 0x0c0c8d6cu: goto P_0c0c8d6c;
case 0x0c0c8d6eu: goto P_0c0c8d6e;
case 0x0c0c8d70u: goto P_0c0c8d70;
case 0x0c0c8d72u: goto P_0c0c8d72;
case 0x0c0c8d74u: goto P_0c0c8d74;
case 0x0c0c8d76u: goto P_0c0c8d76;
case 0x0c0c8d78u: goto P_0c0c8d78;
case 0x0c0c8d7au: goto P_0c0c8d7a;
case 0x0c0c8d7cu: goto P_0c0c8d7c;
case 0x0c0c8d7eu: goto P_0c0c8d7e;
case 0x0c0c8d80u: goto P_0c0c8d80;
case 0x0c0c8d82u: goto P_0c0c8d82;
case 0x0c0c8d84u: goto P_0c0c8d84;
case 0x0c0c8d86u: goto P_0c0c8d86;
case 0x0c0c8d88u: goto P_0c0c8d88;
case 0x0c0c8d8au: goto P_0c0c8d8a;
case 0x0c0c8d8cu: goto P_0c0c8d8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0371f8: /* original d001, guest PC 0x0c0371f8 */
if(!s->budget--) { s->failed_pc=0x0c0371f8u; return 0; }
r[0]=read(ram,0x0c037200u,4);
goto P_0c0371fa;
P_0c0371fa: /* original 000b, guest PC 0x0c0371fa */
if(!s->budget--) { s->failed_pc=0x0c0371fau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0371fc: /* original 0009, guest PC 0x0c0371fc */
if(!s->budget--) { s->failed_pc=0x0c0371fcu; return 0; }
return vf3_matrix_family(0x0c0371feu,s,ram);
P_0c037240: /* original d346, guest PC 0x0c037240 */
if(!s->budget--) { s->failed_pc=0x0c037240u; return 0; }
r[3]=read(ram,0x0c03735cu,4);
goto P_0c037242;
P_0c037242: /* original d545, guest PC 0x0c037242 */
if(!s->budget--) { s->failed_pc=0x0c037242u; return 0; }
r[5]=read(ram,0x0c037358u,4);
goto P_0c037244;
P_0c037244: /* original 432b, guest PC 0x0c037244 */
if(!s->budget--) { s->failed_pc=0x0c037244u; return 0; }
target=r[3];
r[4]=0x00000000u;
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
P_0c037246: /* original e400, guest PC 0x0c037246 */
if(!s->budget--) { s->failed_pc=0x0c037246u; return 0; }
r[4]=0x00000000u;
return vf3_matrix_family(0x0c037248u,s,ram);
P_0c03c720: /* original 4f22, guest PC 0x0c03c720 */
if(!s->budget--) { s->failed_pc=0x0c03c720u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c722;
P_0c03c722: /* original 7ff8, guest PC 0x0c03c722 */
if(!s->budget--) { s->failed_pc=0x0c03c722u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03c724;
P_0c03c724: /* original 1f41, guest PC 0x0c03c724 */
if(!s->budget--) { s->failed_pc=0x0c03c724u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c03c726;
P_0c03c726: /* original 2f52, guest PC 0x0c03c726 */
if(!s->budget--) { s->failed_pc=0x0c03c726u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03c728;
P_0c03c728: /* original d33a, guest PC 0x0c03c728 */
if(!s->budget--) { s->failed_pc=0x0c03c728u; return 0; }
r[3]=read(ram,0x0c03c814u,4);
goto P_0c03c72a;
P_0c03c72a: /* original 430b, guest PC 0x0c03c72a */
if(!s->budget--) { s->failed_pc=0x0c03c72au; return 0; }
target=r[3];
r[16]=0x0c03c72eu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c72eu) { target=s->pc; goto dispatch; }
goto P_0c03c72e;
P_0c03c72c: /* original 6453, guest PC 0x0c03c72c */
if(!s->budget--) { s->failed_pc=0x0c03c72cu; return 0; }
r[4]=r[5];
goto P_0c03c72e;
P_0c03c72e: /* original ff0b, guest PC 0x0c03c72e */
if(!s->budget--) { s->failed_pc=0x0c03c72eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c03c730;
P_0c03c730: /* original d339, guest PC 0x0c03c730 */
if(!s->budget--) { s->failed_pc=0x0c03c730u; return 0; }
r[3]=read(ram,0x0c03c818u,4);
goto P_0c03c732;
P_0c03c732: /* original 430b, guest PC 0x0c03c732 */
if(!s->budget--) { s->failed_pc=0x0c03c732u; return 0; }
target=r[3];
r[16]=0x0c03c736u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c736u) { target=s->pc; goto dispatch; }
goto P_0c03c736;
P_0c03c734: /* original 54f1, guest PC 0x0c03c734 */
if(!s->budget--) { s->failed_pc=0x0c03c734u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c03c736;
P_0c03c736: /* original 54f2, guest PC 0x0c03c736 */
if(!s->budget--) { s->failed_pc=0x0c03c736u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03c738;
P_0c03c738: /* original f5f9, guest PC 0x0c03c738 */
if(!s->budget--) { s->failed_pc=0x0c03c738u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c73a;
P_0c03c73a: /* original f40c, guest PC 0x0c03c73a */
if(!s->budget--) { s->failed_pc=0x0c03c73au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c03c73c;
P_0c03c73c: /* original 7f08, guest PC 0x0c03c73c */
if(!s->budget--) { s->failed_pc=0x0c03c73cu; return 0; }
r[15]+=0x00000008u;
goto P_0c03c73e;
P_0c03c73e: /* original a007, guest PC 0x0c03c73e */
if(!s->budget--) { s->failed_pc=0x0c03c73eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c750;
P_0c03c740: /* original 4f26, guest PC 0x0c03c740 */
if(!s->budget--) { s->failed_pc=0x0c03c740u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03c742u,s,ram);
P_0c03c750: /* original e004, guest PC 0x0c03c750 */
if(!s->budget--) { s->failed_pc=0x0c03c750u; return 0; }
r[0]=0x00000004u;
goto P_0c03c752;
P_0c03c752: /* original fffb, guest PC 0x0c03c752 */
if(!s->budget--) { s->failed_pc=0x0c03c752u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03c754;
P_0c03c754: /* original ffeb, guest PC 0x0c03c754 */
if(!s->budget--) { s->failed_pc=0x0c03c754u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03c756;
P_0c03c756: /* original ffdb, guest PC 0x0c03c756 */
if(!s->budget--) { s->failed_pc=0x0c03c756u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03c758;
P_0c03c758: /* original f99d, guest PC 0x0c03c758 */
if(!s->budget--) { s->failed_pc=0x0c03c758u; return 0; }
fr[9]=0x3f800000u;
goto P_0c03c75a;
P_0c03c75a: /* original fa9c, guest PC 0x0c03c75a */
if(!s->budget--) { s->failed_pc=0x0c03c75au; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c03c75c;
P_0c03c75c: /* original fa51, guest PC 0x0c03c75c */
if(!s->budget--) { s->failed_pc=0x0c03c75cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'-');
goto P_0c03c75e;
P_0c03c75e: /* original f746, guest PC 0x0c03c75e */
if(!s->budget--) { s->failed_pc=0x0c03c75eu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c03c760;
P_0c03c760: /* original e008, guest PC 0x0c03c760 */
if(!s->budget--) { s->failed_pc=0x0c03c760u; return 0; }
r[0]=0x00000008u;
goto P_0c03c762;
P_0c03c762: /* original f848, guest PC 0x0c03c762 */
if(!s->budget--) { s->failed_pc=0x0c03c762u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c03c764;
P_0c03c764: /* original f646, guest PC 0x0c03c764 */
if(!s->budget--) { s->failed_pc=0x0c03c764u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c03c766;
P_0c03c766: /* original f3ac, guest PC 0x0c03c766 */
if(!s->budget--) { s->failed_pc=0x0c03c766u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c03c768;
P_0c03c768: /* original fa72, guest PC 0x0c03c768 */
if(!s->budget--) { s->failed_pc=0x0c03c768u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c03c76a;
P_0c03c76a: /* original f382, guest PC 0x0c03c76a */
if(!s->budget--) { s->failed_pc=0x0c03c76au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c03c76c;
P_0c03c76c: /* original 4f22, guest PC 0x0c03c76c */
if(!s->budget--) { s->failed_pc=0x0c03c76cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c76e;
P_0c03c76e: /* original 7fbc, guest PC 0x0c03c76e */
if(!s->budget--) { s->failed_pc=0x0c03c76eu; return 0; }
r[15]+=0xffffffbcu;
goto P_0c03c770;
P_0c03c770: /* original ff3a, guest PC 0x0c03c770 */
if(!s->budget--) { s->failed_pc=0x0c03c770u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c03c772;
P_0c03c772: /* original fdac, guest PC 0x0c03c772 */
if(!s->budget--) { s->failed_pc=0x0c03c772u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c03c774;
P_0c03c774: /* original fd62, guest PC 0x0c03c774 */
if(!s->budget--) { s->failed_pc=0x0c03c774u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[6],r[18],'*');
goto P_0c03c776;
P_0c03c776: /* original fa3c, guest PC 0x0c03c776 */
if(!s->budget--) { s->failed_pc=0x0c03c776u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c03c778;
P_0c03c778: /* original fa62, guest PC 0x0c03c778 */
if(!s->budget--) { s->failed_pc=0x0c03c778u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c03c77a;
P_0c03c77a: /* original fe4c, guest PC 0x0c03c77a */
if(!s->budget--) { s->failed_pc=0x0c03c77au; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03c77c;
P_0c03c77c: /* original fe82, guest PC 0x0c03c77c */
if(!s->budget--) { s->failed_pc=0x0c03c77cu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[8],r[18],'*');
goto P_0c03c77e;
P_0c03c77e: /* original ff4c, guest PC 0x0c03c77e */
if(!s->budget--) { s->failed_pc=0x0c03c77eu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c03c780;
P_0c03c780: /* original f462, guest PC 0x0c03c780 */
if(!s->budget--) { s->failed_pc=0x0c03c780u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c03c782;
P_0c03c782: /* original fb3c, guest PC 0x0c03c782 */
if(!s->budget--) { s->failed_pc=0x0c03c782u; return 0; }
vf3_matrix_move(s,11,3);
goto P_0c03c784;
P_0c03c784: /* original ff72, guest PC 0x0c03c784 */
if(!s->budget--) { s->failed_pc=0x0c03c784u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[7],r[18],'*');
goto P_0c03c786;
P_0c03c786: /* original fb72, guest PC 0x0c03c786 */
if(!s->budget--) { s->failed_pc=0x0c03c786u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c03c788;
P_0c03c788: /* original f29c, guest PC 0x0c03c788 */
if(!s->budget--) { s->failed_pc=0x0c03c788u; return 0; }
vf3_matrix_move(s,2,9);
goto P_0c03c78a;
P_0c03c78a: /* original f882, guest PC 0x0c03c78a */
if(!s->budget--) { s->failed_pc=0x0c03c78au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[8],r[18],'*');
goto P_0c03c78c;
P_0c03c78c: /* original f772, guest PC 0x0c03c78c */
if(!s->budget--) { s->failed_pc=0x0c03c78cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c03c78e;
P_0c03c78e: /* original f662, guest PC 0x0c03c78e */
if(!s->budget--) { s->failed_pc=0x0c03c78eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[6],r[18],'*');
goto P_0c03c790;
P_0c03c790: /* original f281, guest PC 0x0c03c790 */
if(!s->budget--) { s->failed_pc=0x0c03c790u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'-');
goto P_0c03c792;
P_0c03c792: /* original f05c, guest PC 0x0c03c792 */
if(!s->budget--) { s->failed_pc=0x0c03c792u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03c794;
P_0c03c794: /* original f18c, guest PC 0x0c03c794 */
if(!s->budget--) { s->failed_pc=0x0c03c794u; return 0; }
vf3_matrix_move(s,1,8);
goto P_0c03c796;
P_0c03c796: /* original e004, guest PC 0x0c03c796 */
if(!s->budget--) { s->failed_pc=0x0c03c796u; return 0; }
r[0]=0x00000004u;
goto P_0c03c798;
P_0c03c798: /* original f12e, guest PC 0x0c03c798 */
if(!s->budget--) { s->failed_pc=0x0c03c798u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[2],fr[1],r[18]);
goto P_0c03c79a;
P_0c03c79a: /* original ff17, guest PC 0x0c03c79a */
if(!s->budget--) { s->failed_pc=0x0c03c79au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c03c79c;
P_0c03c79c: /* original e008, guest PC 0x0c03c79c */
if(!s->budget--) { s->failed_pc=0x0c03c79cu; return 0; }
r[0]=0x00000008u;
goto P_0c03c79e;
P_0c03c79e: /* original f34c, guest PC 0x0c03c79e */
if(!s->budget--) { s->failed_pc=0x0c03c79eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03c7a0;
P_0c03c7a0: /* original f3b0, guest PC 0x0c03c7a0 */
if(!s->budget--) { s->failed_pc=0x0c03c7a0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
goto P_0c03c7a2;
P_0c03c7a2: /* original fb41, guest PC 0x0c03c7a2 */
if(!s->budget--) { s->failed_pc=0x0c03c7a2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c03c7a4;
P_0c03c7a4: /* original ff37, guest PC 0x0c03c7a4 */
if(!s->budget--) { s->failed_pc=0x0c03c7a4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7a6;
P_0c03c7a6: /* original e00c, guest PC 0x0c03c7a6 */
if(!s->budget--) { s->failed_pc=0x0c03c7a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c7a8;
P_0c03c7a8: /* original f3ac, guest PC 0x0c03c7a8 */
if(!s->budget--) { s->failed_pc=0x0c03c7a8u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c03c7aa;
P_0c03c7aa: /* original f3f1, guest PC 0x0c03c7aa */
if(!s->budget--) { s->failed_pc=0x0c03c7aau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c03c7ac;
P_0c03c7ac: /* original ffa0, guest PC 0x0c03c7ac */
if(!s->budget--) { s->failed_pc=0x0c03c7acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[10],r[18],'+');
goto P_0c03c7ae;
P_0c03c7ae: /* original ff37, guest PC 0x0c03c7ae */
if(!s->budget--) { s->failed_pc=0x0c03c7aeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7b0;
P_0c03c7b0: /* original e014, guest PC 0x0c03c7b0 */
if(!s->budget--) { s->failed_pc=0x0c03c7b0u; return 0; }
r[0]=0x00000014u;
goto P_0c03c7b2;
P_0c03c7b2: /* original ffb7, guest PC 0x0c03c7b2 */
if(!s->budget--) { s->failed_pc=0x0c03c7b2u; return 0; }
vf3_matrix_store(s,ram,11,r[15]+r[0]);
goto P_0c03c7b4;
P_0c03c7b4: /* original e018, guest PC 0x0c03c7b4 */
if(!s->budget--) { s->failed_pc=0x0c03c7b4u; return 0; }
r[0]=0x00000018u;
goto P_0c03c7b6;
P_0c03c7b6: /* original f39c, guest PC 0x0c03c7b6 */
if(!s->budget--) { s->failed_pc=0x0c03c7b6u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c03c7b8;
P_0c03c7b8: /* original f371, guest PC 0x0c03c7b8 */
if(!s->budget--) { s->failed_pc=0x0c03c7b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'-');
goto P_0c03c7ba;
P_0c03c7ba: /* original f27c, guest PC 0x0c03c7ba */
if(!s->budget--) { s->failed_pc=0x0c03c7bau; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c03c7bc;
P_0c03c7bc: /* original f23e, guest PC 0x0c03c7bc */
if(!s->budget--) { s->failed_pc=0x0c03c7bcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c03c7be;
P_0c03c7be: /* original ff27, guest PC 0x0c03c7be */
if(!s->budget--) { s->failed_pc=0x0c03c7beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c7c0;
P_0c03c7c0: /* original e01c, guest PC 0x0c03c7c0 */
if(!s->budget--) { s->failed_pc=0x0c03c7c0u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c7c2;
P_0c03c7c2: /* original f3ec, guest PC 0x0c03c7c2 */
if(!s->budget--) { s->failed_pc=0x0c03c7c2u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03c7c4;
P_0c03c7c4: /* original f3d0, guest PC 0x0c03c7c4 */
if(!s->budget--) { s->failed_pc=0x0c03c7c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c03c7c6;
P_0c03c7c6: /* original fde1, guest PC 0x0c03c7c6 */
if(!s->budget--) { s->failed_pc=0x0c03c7c6u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c03c7c8;
P_0c03c7c8: /* original ff37, guest PC 0x0c03c7c8 */
if(!s->budget--) { s->failed_pc=0x0c03c7c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03c7ca;
P_0c03c7ca: /* original e024, guest PC 0x0c03c7ca */
if(!s->budget--) { s->failed_pc=0x0c03c7cau; return 0; }
r[0]=0x00000024u;
goto P_0c03c7cc;
P_0c03c7cc: /* original fff7, guest PC 0x0c03c7cc */
if(!s->budget--) { s->failed_pc=0x0c03c7ccu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c03c7ce;
P_0c03c7ce: /* original e028, guest PC 0x0c03c7ce */
if(!s->budget--) { s->failed_pc=0x0c03c7ceu; return 0; }
r[0]=0x00000028u;
goto P_0c03c7d0;
P_0c03c7d0: /* original ffd7, guest PC 0x0c03c7d0 */
if(!s->budget--) { s->failed_pc=0x0c03c7d0u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c03c7d2;
P_0c03c7d2: /* original e02c, guest PC 0x0c03c7d2 */
if(!s->budget--) { s->failed_pc=0x0c03c7d2u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c7d4;
P_0c03c7d4: /* original f39c, guest PC 0x0c03c7d4 */
if(!s->budget--) { s->failed_pc=0x0c03c7d4u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c03c7d6;
P_0c03c7d6: /* original f361, guest PC 0x0c03c7d6 */
if(!s->budget--) { s->failed_pc=0x0c03c7d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c03c7d8;
P_0c03c7d8: /* original f26c, guest PC 0x0c03c7d8 */
if(!s->budget--) { s->failed_pc=0x0c03c7d8u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c03c7da;
P_0c03c7da: /* original 64f3, guest PC 0x0c03c7da */
if(!s->budget--) { s->failed_pc=0x0c03c7dau; return 0; }
r[4]=r[15];
goto P_0c03c7dc;
P_0c03c7dc: /* original 7404, guest PC 0x0c03c7dc */
if(!s->budget--) { s->failed_pc=0x0c03c7dcu; return 0; }
r[4]+=0x00000004u;
goto P_0c03c7de;
P_0c03c7de: /* original f23e, guest PC 0x0c03c7de */
if(!s->budget--) { s->failed_pc=0x0c03c7deu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c03c7e0;
P_0c03c7e0: /* original ff27, guest PC 0x0c03c7e0 */
if(!s->budget--) { s->failed_pc=0x0c03c7e0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c03c7e2;
P_0c03c7e2: /* original e038, guest PC 0x0c03c7e2 */
if(!s->budget--) { s->failed_pc=0x0c03c7e2u; return 0; }
r[0]=0x00000038u;
goto P_0c03c7e4;
P_0c03c7e4: /* original f38d, guest PC 0x0c03c7e4 */
if(!s->budget--) { s->failed_pc=0x0c03c7e4u; return 0; }
fr[3]=0;
goto P_0c03c7e6;
P_0c03c7e6: /* original f437, guest PC 0x0c03c7e6 */
if(!s->budget--) { s->failed_pc=0x0c03c7e6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7e8;
P_0c03c7e8: /* original e034, guest PC 0x0c03c7e8 */
if(!s->budget--) { s->failed_pc=0x0c03c7e8u; return 0; }
r[0]=0x00000034u;
goto P_0c03c7ea;
P_0c03c7ea: /* original f437, guest PC 0x0c03c7ea */
if(!s->budget--) { s->failed_pc=0x0c03c7eau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7ec;
P_0c03c7ec: /* original e030, guest PC 0x0c03c7ec */
if(!s->budget--) { s->failed_pc=0x0c03c7ecu; return 0; }
r[0]=0x00000030u;
goto P_0c03c7ee;
P_0c03c7ee: /* original f437, guest PC 0x0c03c7ee */
if(!s->budget--) { s->failed_pc=0x0c03c7eeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f0;
P_0c03c7f0: /* original e02c, guest PC 0x0c03c7f0 */
if(!s->budget--) { s->failed_pc=0x0c03c7f0u; return 0; }
r[0]=0x0000002cu;
goto P_0c03c7f2;
P_0c03c7f2: /* original f437, guest PC 0x0c03c7f2 */
if(!s->budget--) { s->failed_pc=0x0c03c7f2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f4;
P_0c03c7f4: /* original e01c, guest PC 0x0c03c7f4 */
if(!s->budget--) { s->failed_pc=0x0c03c7f4u; return 0; }
r[0]=0x0000001cu;
goto P_0c03c7f6;
P_0c03c7f6: /* original f437, guest PC 0x0c03c7f6 */
if(!s->budget--) { s->failed_pc=0x0c03c7f6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7f8;
P_0c03c7f8: /* original e00c, guest PC 0x0c03c7f8 */
if(!s->budget--) { s->failed_pc=0x0c03c7f8u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c7fa;
P_0c03c7fa: /* original f437, guest PC 0x0c03c7fa */
if(!s->budget--) { s->failed_pc=0x0c03c7fau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03c7fc;
P_0c03c7fc: /* original e040, guest PC 0x0c03c7fc */
if(!s->budget--) { s->failed_pc=0x0c03c7fcu; return 0; }
r[0]=0x00000040u;
goto P_0c03c7fe;
P_0c03c7fe: /* original 64f3, guest PC 0x0c03c7fe */
if(!s->budget--) { s->failed_pc=0x0c03c7feu; return 0; }
r[4]=r[15];
goto P_0c03c800;
P_0c03c800: /* original ff97, guest PC 0x0c03c800 */
if(!s->budget--) { s->failed_pc=0x0c03c800u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c03c802;
P_0c03c802: /* original d306, guest PC 0x0c03c802 */
if(!s->budget--) { s->failed_pc=0x0c03c802u; return 0; }
r[3]=read(ram,0x0c03c81cu,4);
goto P_0c03c804;
P_0c03c804: /* original 430b, guest PC 0x0c03c804 */
if(!s->budget--) { s->failed_pc=0x0c03c804u; return 0; }
target=r[3];
r[16]=0x0c03c808u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c808u) { target=s->pc; goto dispatch; }
goto P_0c03c808;
P_0c03c806: /* original 7404, guest PC 0x0c03c806 */
if(!s->budget--) { s->failed_pc=0x0c03c806u; return 0; }
r[4]+=0x00000004u;
goto P_0c03c808;
P_0c03c808: /* original 7f44, guest PC 0x0c03c808 */
if(!s->budget--) { s->failed_pc=0x0c03c808u; return 0; }
r[15]+=0x00000044u;
goto P_0c03c80a;
P_0c03c80a: /* original 4f26, guest PC 0x0c03c80a */
if(!s->budget--) { s->failed_pc=0x0c03c80au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c80c;
P_0c03c80c: /* original fdf9, guest PC 0x0c03c80c */
if(!s->budget--) { s->failed_pc=0x0c03c80cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c80e;
P_0c03c80e: /* original fef9, guest PC 0x0c03c80e */
if(!s->budget--) { s->failed_pc=0x0c03c80eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c810;
P_0c03c810: /* original 000b, guest PC 0x0c03c810 */
if(!s->budget--) { s->failed_pc=0x0c03c810u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c03c812: /* original fff9, guest PC 0x0c03c812 */
if(!s->budget--) { s->failed_pc=0x0c03c812u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c03c814u,s,ram);
P_0c0424d0: /* original 2fe6, guest PC 0x0c0424d0 */
if(!s->budget--) { s->failed_pc=0x0c0424d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d2;
P_0c0424d2: /* original 2fd6, guest PC 0x0c0424d2 */
if(!s->budget--) { s->failed_pc=0x0c0424d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d4;
P_0c0424d4: /* original 2fc6, guest PC 0x0c0424d4 */
if(!s->budget--) { s->failed_pc=0x0c0424d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0424d6;
P_0c0424d6: /* original d24a, guest PC 0x0c0424d6 */
if(!s->budget--) { s->failed_pc=0x0c0424d6u; return 0; }
r[2]=read(ram,0x0c042600u,4);
goto P_0c0424d8;
P_0c0424d8: /* original 4f22, guest PC 0x0c0424d8 */
if(!s->budget--) { s->failed_pc=0x0c0424d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0424da;
P_0c0424da: /* original 6322, guest PC 0x0c0424da */
if(!s->budget--) { s->failed_pc=0x0c0424dau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0424dc;
P_0c0424dc: /* original 2338, guest PC 0x0c0424dc */
if(!s->budget--) { s->failed_pc=0x0c0424dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0424de;
P_0c0424de: /* original 8b01, guest PC 0x0c0424de */
if(!s->budget--) { s->failed_pc=0x0c0424deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0424e4; }
goto P_0c0424e0;
P_0c0424e0: /* original a081, guest PC 0x0c0424e0 */
if(!s->budget--) { s->failed_pc=0x0c0424e0u; return 0; }
goto P_0c0425e6;
P_0c0424e2: /* original 0009, guest PC 0x0c0424e2 */
if(!s->budget--) { s->failed_pc=0x0c0424e2u; return 0; }
goto P_0c0424e4;
P_0c0424e4: /* original d049, guest PC 0x0c0424e4 */
if(!s->budget--) { s->failed_pc=0x0c0424e4u; return 0; }
r[0]=read(ram,0x0c04260cu,4);
goto P_0c0424e6;
P_0c0424e6: /* original d148, guest PC 0x0c0424e6 */
if(!s->budget--) { s->failed_pc=0x0c0424e6u; return 0; }
r[1]=read(ram,0x0c042608u,4);
goto P_0c0424e8;
P_0c0424e8: /* original 6700, guest PC 0x0c0424e8 */
if(!s->budget--) { s->failed_pc=0x0c0424e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[7]=tmp;
goto P_0c0424ea;
P_0c0424ea: /* original e001, guest PC 0x0c0424ea */
if(!s->budget--) { s->failed_pc=0x0c0424eau; return 0; }
r[0]=0x00000001u;
goto P_0c0424ec;
P_0c0424ec: /* original 6312, guest PC 0x0c0424ec */
if(!s->budget--) { s->failed_pc=0x0c0424ecu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0424ee;
P_0c0424ee: /* original e11b, guest PC 0x0c0424ee */
if(!s->budget--) { s->failed_pc=0x0c0424eeu; return 0; }
r[1]=0x0000001bu;
goto P_0c0424f0;
P_0c0424f0: /* original 6273, guest PC 0x0c0424f0 */
if(!s->budget--) { s->failed_pc=0x0c0424f0u; return 0; }
r[2]=r[7];
goto P_0c0424f2;
P_0c0424f2: /* original 4708, guest PC 0x0c0424f2 */
if(!s->budget--) { s->failed_pc=0x0c0424f2u; return 0; }
r[7]<<=2;
goto P_0c0424f4;
P_0c0424f4: /* original 372c, guest PC 0x0c0424f4 */
if(!s->budget--) { s->failed_pc=0x0c0424f4u; return 0; }
r[7]+=r[2];
goto P_0c0424f6;
P_0c0424f6: /* original 5632, guest PC 0x0c0424f6 */
if(!s->budget--) { s->failed_pc=0x0c0424f6u; return 0; }
r[6]=read(ram,r[3]+8,4);
goto P_0c0424f8;
P_0c0424f8: /* original 4708, guest PC 0x0c0424f8 */
if(!s->budget--) { s->failed_pc=0x0c0424f8u; return 0; }
r[7]<<=2;
goto P_0c0424fa;
P_0c0424fa: /* original d345, guest PC 0x0c0424fa */
if(!s->budget--) { s->failed_pc=0x0c0424fau; return 0; }
r[3]=read(ram,0x0c042610u,4);
goto P_0c0424fc;
P_0c0424fc: /* original 4700, guest PC 0x0c0424fc */
if(!s->budget--) { s->failed_pc=0x0c0424fcu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0424fe;
P_0c0424fe: /* original d441, guest PC 0x0c0424fe */
if(!s->budget--) { s->failed_pc=0x0c0424feu; return 0; }
r[4]=read(ram,0x0c042604u,4);
goto P_0c042500;
P_0c042500: /* original 677e, guest PC 0x0c042500 */
if(!s->budget--) { s->failed_pc=0x0c042500u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c042502;
P_0c042502: /* original 373c, guest PC 0x0c042502 */
if(!s->budget--) { s->failed_pc=0x0c042502u; return 0; }
r[7]+=r[3];
goto P_0c042504;
P_0c042504: /* original 5576, guest PC 0x0c042504 */
if(!s->budget--) { s->failed_pc=0x0c042504u; return 0; }
r[5]=read(ram,r[7]+24,4);
goto P_0c042506;
P_0c042506: /* original e208, guest PC 0x0c042506 */
if(!s->budget--) { s->failed_pc=0x0c042506u; return 0; }
r[2]=0x00000008u;
goto P_0c042508;
P_0c042508: /* original 5372, guest PC 0x0c042508 */
if(!s->budget--) { s->failed_pc=0x0c042508u; return 0; }
r[3]=read(ram,r[7]+8,4);
goto P_0c04250a;
P_0c04250a: /* original 2059, guest PC 0x0c04250a */
if(!s->budget--) { s->failed_pc=0x0c04250au; return 0; }
r[0]&=r[5];
goto P_0c04250c;
P_0c04250c: /* original 2259, guest PC 0x0c04250c */
if(!s->budget--) { s->failed_pc=0x0c04250cu; return 0; }
r[2]&=r[5];
goto P_0c04250e;
P_0c04250e: /* original c901, guest PC 0x0c04250e */
if(!s->budget--) { s->failed_pc=0x0c04250eu; return 0; }
r[0]&=1u;
goto P_0c042510;
P_0c042510: /* original 421d, guest PC 0x0c042510 */
if(!s->budget--) { s->failed_pc=0x0c042510u; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?r[2]>>((-r[1])&31u):0):r[2]<<(r[1]&31u);
goto P_0c042512;
P_0c042512: /* original 4005, guest PC 0x0c042512 */
if(!s->budget--) { s->failed_pc=0x0c042512u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1u)!=0);
r[0]=(r[0]>>1)|(r[0]<<31);
goto P_0c042514;
P_0c042514: /* original 202b, guest PC 0x0c042514 */
if(!s->budget--) { s->failed_pc=0x0c042514u; return 0; }
r[0]|=r[2];
goto P_0c042516;
P_0c042516: /* original d23f, guest PC 0x0c042516 */
if(!s->budget--) { s->failed_pc=0x0c042516u; return 0; }
r[2]=read(ram,0x0c042614u,4);
goto P_0c042518;
P_0c042518: /* original 2329, guest PC 0x0c042518 */
if(!s->budget--) { s->failed_pc=0x0c042518u; return 0; }
r[3]&=r[2];
goto P_0c04251a;
P_0c04251a: /* original 203b, guest PC 0x0c04251a */
if(!s->budget--) { s->failed_pc=0x0c04251au; return 0; }
r[0]|=r[3];
goto P_0c04251c;
P_0c04251c: /* original 6303, guest PC 0x0c04251c */
if(!s->budget--) { s->failed_pc=0x0c04251cu; return 0; }
r[3]=r[0];
goto P_0c04251e;
P_0c04251e: /* original 6057, guest PC 0x0c04251e */
if(!s->budget--) { s->failed_pc=0x0c04251eu; return 0; }
r[0]=~r[5];
goto P_0c042520;
P_0c042520: /* original c904, guest PC 0x0c042520 */
if(!s->budget--) { s->failed_pc=0x0c042520u; return 0; }
r[0]&=4u;
goto P_0c042522;
P_0c042522: /* original 4028, guest PC 0x0c042522 */
if(!s->budget--) { s->failed_pc=0x0c042522u; return 0; }
r[0]<<=16;
goto P_0c042524;
P_0c042524: /* original 4018, guest PC 0x0c042524 */
if(!s->budget--) { s->failed_pc=0x0c042524u; return 0; }
r[0]<<=8;
goto P_0c042526;
P_0c042526: /* original 230b, guest PC 0x0c042526 */
if(!s->budget--) { s->failed_pc=0x0c042526u; return 0; }
r[3]|=r[0];
goto P_0c042528;
P_0c042528: /* original e010, guest PC 0x0c042528 */
if(!s->budget--) { s->failed_pc=0x0c042528u; return 0; }
r[0]=0x00000010u;
goto P_0c04252a;
P_0c04252a: /* original e215, guest PC 0x0c04252a */
if(!s->budget--) { s->failed_pc=0x0c04252au; return 0; }
r[2]=0x00000015u;
goto P_0c04252c;
P_0c04252c: /* original 2059, guest PC 0x0c04252c */
if(!s->budget--) { s->failed_pc=0x0c04252cu; return 0; }
r[0]&=r[5];
goto P_0c04252e;
P_0c04252e: /* original 402d, guest PC 0x0c04252e */
if(!s->budget--) { s->failed_pc=0x0c04252eu; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?r[0]>>((-r[2])&31u):0):r[0]<<(r[2]&31u);
goto P_0c042530;
P_0c042530: /* original 230b, guest PC 0x0c042530 */
if(!s->budget--) { s->failed_pc=0x0c042530u; return 0; }
r[3]|=r[0];
goto P_0c042532;
P_0c042532: /* original 5077, guest PC 0x0c042532 */
if(!s->budget--) { s->failed_pc=0x0c042532u; return 0; }
r[0]=read(ram,r[7]+28,4);
goto P_0c042534;
P_0c042534: /* original 4009, guest PC 0x0c042534 */
if(!s->budget--) { s->failed_pc=0x0c042534u; return 0; }
r[0]>>=2;
goto P_0c042536;
P_0c042536: /* original 4001, guest PC 0x0c042536 */
if(!s->budget--) { s->failed_pc=0x0c042536u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c042538;
P_0c042538: /* original 230b, guest PC 0x0c042538 */
if(!s->budget--) { s->failed_pc=0x0c042538u; return 0; }
r[3]|=r[0];
goto P_0c04253a;
P_0c04253a: /* original 1433, guest PC 0x0c04253a */
if(!s->budget--) { s->failed_pc=0x0c04253au; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c04253c;
P_0c04253c: /* original 6363, guest PC 0x0c04253c */
if(!s->budget--) { s->failed_pc=0x0c04253cu; return 0; }
r[3]=r[6];
goto P_0c04253e;
P_0c04253e: /* original d036, guest PC 0x0c04253e */
if(!s->budget--) { s->failed_pc=0x0c04253eu; return 0; }
r[0]=read(ram,0x0c042618u,4);
goto P_0c042540;
P_0c042540: /* original 4329, guest PC 0x0c042540 */
if(!s->budget--) { s->failed_pc=0x0c042540u; return 0; }
r[3]>>=16;
goto P_0c042542;
P_0c042542: /* original 4319, guest PC 0x0c042542 */
if(!s->budget--) { s->failed_pc=0x0c042542u; return 0; }
r[3]>>=8;
goto P_0c042544;
P_0c042544: /* original 2032, guest PC 0x0c042544 */
if(!s->budget--) { s->failed_pc=0x0c042544u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c042546;
P_0c042546: /* original d235, guest PC 0x0c042546 */
if(!s->budget--) { s->failed_pc=0x0c042546u; return 0; }
r[2]=read(ram,0x0c04261cu,4);
goto P_0c042548;
P_0c042548: /* original 2232, guest PC 0x0c042548 */
if(!s->budget--) { s->failed_pc=0x0c042548u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c04254a;
P_0c04254a: /* original de35, guest PC 0x0c04254a */
if(!s->budget--) { s->failed_pc=0x0c04254au; return 0; }
r[14]=read(ram,0x0c042620u,4);
goto P_0c04254c;
P_0c04254c: /* original d335, guest PC 0x0c04254c */
if(!s->budget--) { s->failed_pc=0x0c04254cu; return 0; }
r[3]=read(ram,0x0c042624u,4);
goto P_0c04254e;
P_0c04254e: /* original 6242, guest PC 0x0c04254e */
if(!s->budget--) { s->failed_pc=0x0c04254eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c042550;
P_0c042550: /* original 2e69, guest PC 0x0c042550 */
if(!s->budget--) { s->failed_pc=0x0c042550u; return 0; }
r[14]&=r[6];
goto P_0c042552;
P_0c042552: /* original 2e3b, guest PC 0x0c042552 */
if(!s->budget--) { s->failed_pc=0x0c042552u; return 0; }
r[14]|=r[3];
goto P_0c042554;
P_0c042554: /* original 2e22, guest PC 0x0c042554 */
if(!s->budget--) { s->failed_pc=0x0c042554u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c042556;
P_0c042556: /* original 5141, guest PC 0x0c042556 */
if(!s->budget--) { s->failed_pc=0x0c042556u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c042558;
P_0c042558: /* original 1e11, guest PC 0x0c042558 */
if(!s->budget--) { s->failed_pc=0x0c042558u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c04255a;
P_0c04255a: /* original 5242, guest PC 0x0c04255a */
if(!s->budget--) { s->failed_pc=0x0c04255au; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c04255c;
P_0c04255c: /* original 1e22, guest PC 0x0c04255c */
if(!s->budget--) { s->failed_pc=0x0c04255cu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c04255e;
P_0c04255e: /* original 5143, guest PC 0x0c04255e */
if(!s->budget--) { s->failed_pc=0x0c04255eu; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c042560;
P_0c042560: /* original 1e13, guest PC 0x0c042560 */
if(!s->budget--) { s->failed_pc=0x0c042560u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c042562;
P_0c042562: /* original 5244, guest PC 0x0c042562 */
if(!s->budget--) { s->failed_pc=0x0c042562u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c042564;
P_0c042564: /* original 1e24, guest PC 0x0c042564 */
if(!s->budget--) { s->failed_pc=0x0c042564u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c042566;
P_0c042566: /* original dd30, guest PC 0x0c042566 */
if(!s->budget--) { s->failed_pc=0x0c042566u; return 0; }
r[13]=read(ram,0x0c042628u,4);
goto P_0c042568;
P_0c042568: /* original 4d0b, guest PC 0x0c042568 */
if(!s->budget--) { s->failed_pc=0x0c042568u; return 0; }
target=r[13];
r[16]=0x0c04256cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04256cu) { target=s->pc; goto dispatch; }
goto P_0c04256c;
P_0c04256a: /* original 64e3, guest PC 0x0c04256a */
if(!s->budget--) { s->failed_pc=0x0c04256au; return 0; }
r[4]=r[14];
goto P_0c04256c;
P_0c04256c: /* original c72f, guest PC 0x0c04256c */
if(!s->budget--) { s->failed_pc=0x0c04256cu; return 0; }
r[0]=0x0c04262cu;
goto P_0c04256e;
P_0c04256e: /* original 7e20, guest PC 0x0c04256e */
if(!s->budget--) { s->failed_pc=0x0c04256eu; return 0; }
r[14]+=0x00000020u;
goto P_0c042570;
P_0c042570: /* original e3ff, guest PC 0x0c042570 */
if(!s->budget--) { s->failed_pc=0x0c042570u; return 0; }
r[3]=0xffffffffu;
goto P_0c042572;
P_0c042572: /* original 2e32, guest PC 0x0c042572 */
if(!s->budget--) { s->failed_pc=0x0c042572u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c042574;
P_0c042574: /* original f308, guest PC 0x0c042574 */
if(!s->budget--) { s->failed_pc=0x0c042574u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c042576;
P_0c042576: /* original e004, guest PC 0x0c042576 */
if(!s->budget--) { s->failed_pc=0x0c042576u; return 0; }
r[0]=0x00000004u;
goto P_0c042578;
P_0c042578: /* original fe37, guest PC 0x0c042578 */
if(!s->budget--) { s->failed_pc=0x0c042578u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04257a;
P_0c04257a: /* original e008, guest PC 0x0c04257a */
if(!s->budget--) { s->failed_pc=0x0c04257au; return 0; }
r[0]=0x00000008u;
goto P_0c04257c;
P_0c04257c: /* original f48d, guest PC 0x0c04257c */
if(!s->budget--) { s->failed_pc=0x0c04257cu; return 0; }
fr[4]=0;
goto P_0c04257e;
P_0c04257e: /* original fe47, guest PC 0x0c04257e */
if(!s->budget--) { s->failed_pc=0x0c04257eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042580;
P_0c042580: /* original e00c, guest PC 0x0c042580 */
if(!s->budget--) { s->failed_pc=0x0c042580u; return 0; }
r[0]=0x0000000cu;
goto P_0c042582;
P_0c042582: /* original dc2b, guest PC 0x0c042582 */
if(!s->budget--) { s->failed_pc=0x0c042582u; return 0; }
r[12]=read(ram,0x0c042630u,4);
goto P_0c042584;
P_0c042584: /* original f3c8, guest PC 0x0c042584 */
if(!s->budget--) { s->failed_pc=0x0c042584u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042586;
P_0c042586: /* original fe37, guest PC 0x0c042586 */
if(!s->budget--) { s->failed_pc=0x0c042586u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c042588;
P_0c042588: /* original c72a, guest PC 0x0c042588 */
if(!s->budget--) { s->failed_pc=0x0c042588u; return 0; }
r[0]=0x0c042634u;
goto P_0c04258a;
P_0c04258a: /* original f508, guest PC 0x0c04258a */
if(!s->budget--) { s->failed_pc=0x0c04258au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c04258c;
P_0c04258c: /* original e010, guest PC 0x0c04258c */
if(!s->budget--) { s->failed_pc=0x0c04258cu; return 0; }
r[0]=0x00000010u;
goto P_0c04258e;
P_0c04258e: /* original fe57, guest PC 0x0c04258e */
if(!s->budget--) { s->failed_pc=0x0c04258eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c042590;
P_0c042590: /* original e014, guest PC 0x0c042590 */
if(!s->budget--) { s->failed_pc=0x0c042590u; return 0; }
r[0]=0x00000014u;
goto P_0c042592;
P_0c042592: /* original fe47, guest PC 0x0c042592 */
if(!s->budget--) { s->failed_pc=0x0c042592u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c042594;
P_0c042594: /* original e018, guest PC 0x0c042594 */
if(!s->budget--) { s->failed_pc=0x0c042594u; return 0; }
r[0]=0x00000018u;
goto P_0c042596;
P_0c042596: /* original f3c8, guest PC 0x0c042596 */
if(!s->budget--) { s->failed_pc=0x0c042596u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c042598;
P_0c042598: /* original fe37, guest PC 0x0c042598 */
if(!s->budget--) { s->failed_pc=0x0c042598u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c04259a;
P_0c04259a: /* original e01c, guest PC 0x0c04259a */
if(!s->budget--) { s->failed_pc=0x0c04259au; return 0; }
r[0]=0x0000001cu;
goto P_0c04259c;
P_0c04259c: /* original fe57, guest PC 0x0c04259c */
if(!s->budget--) { s->failed_pc=0x0c04259cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c04259e;
P_0c04259e: /* original 4d0b, guest PC 0x0c04259e */
if(!s->budget--) { s->failed_pc=0x0c04259eu; return 0; }
target=r[13];
r[16]=0x0c0425a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0425a2u) { target=s->pc; goto dispatch; }
goto P_0c0425a2;
P_0c0425a0: /* original 64e3, guest PC 0x0c0425a0 */
if(!s->budget--) { s->failed_pc=0x0c0425a0u; return 0; }
r[4]=r[14];
goto P_0c0425a2;
P_0c0425a2: /* original c725, guest PC 0x0c0425a2 */
if(!s->budget--) { s->failed_pc=0x0c0425a2u; return 0; }
r[0]=0x0c042638u;
goto P_0c0425a4;
P_0c0425a4: /* original f408, guest PC 0x0c0425a4 */
if(!s->budget--) { s->failed_pc=0x0c0425a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0425a6;
P_0c0425a6: /* original e004, guest PC 0x0c0425a6 */
if(!s->budget--) { s->failed_pc=0x0c0425a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0425a8;
P_0c0425a8: /* original 7e20, guest PC 0x0c0425a8 */
if(!s->budget--) { s->failed_pc=0x0c0425a8u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425aa;
P_0c0425aa: /* original e200, guest PC 0x0c0425aa */
if(!s->budget--) { s->failed_pc=0x0c0425aau; return 0; }
r[2]=0x00000000u;
goto P_0c0425ac;
P_0c0425ac: /* original fe4a, guest PC 0x0c0425ac */
if(!s->budget--) { s->failed_pc=0x0c0425acu; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c0425ae;
P_0c0425ae: /* original f3c8, guest PC 0x0c0425ae */
if(!s->budget--) { s->failed_pc=0x0c0425aeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c0425b0;
P_0c0425b0: /* original fe37, guest PC 0x0c0425b0 */
if(!s->budget--) { s->failed_pc=0x0c0425b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425b2;
P_0c0425b2: /* original c71e, guest PC 0x0c0425b2 */
if(!s->budget--) { s->failed_pc=0x0c0425b2u; return 0; }
r[0]=0x0c04262cu;
goto P_0c0425b4;
P_0c0425b4: /* original f308, guest PC 0x0c0425b4 */
if(!s->budget--) { s->failed_pc=0x0c0425b4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0425b6;
P_0c0425b6: /* original e008, guest PC 0x0c0425b6 */
if(!s->budget--) { s->failed_pc=0x0c0425b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0425b8;
P_0c0425b8: /* original fe37, guest PC 0x0c0425b8 */
if(!s->budget--) { s->failed_pc=0x0c0425b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0425ba;
P_0c0425ba: /* original e00c, guest PC 0x0c0425ba */
if(!s->budget--) { s->failed_pc=0x0c0425bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0425bc;
P_0c0425bc: /* original fe47, guest PC 0x0c0425bc */
if(!s->budget--) { s->failed_pc=0x0c0425bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0425be;
P_0c0425be: /* original d31f, guest PC 0x0c0425be */
if(!s->budget--) { s->failed_pc=0x0c0425beu; return 0; }
r[3]=read(ram,0x0c04263cu,4);
goto P_0c0425c0;
P_0c0425c0: /* original 1e34, guest PC 0x0c0425c0 */
if(!s->budget--) { s->failed_pc=0x0c0425c0u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0425c2;
P_0c0425c2: /* original 1e25, guest PC 0x0c0425c2 */
if(!s->budget--) { s->failed_pc=0x0c0425c2u; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c0425c4;
P_0c0425c4: /* original d31e, guest PC 0x0c0425c4 */
if(!s->budget--) { s->failed_pc=0x0c0425c4u; return 0; }
r[3]=read(ram,0x0c042640u,4);
goto P_0c0425c6;
P_0c0425c6: /* original 1e36, guest PC 0x0c0425c6 */
if(!s->budget--) { s->failed_pc=0x0c0425c6u; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c0425c8;
P_0c0425c8: /* original d21e, guest PC 0x0c0425c8 */
if(!s->budget--) { s->failed_pc=0x0c0425c8u; return 0; }
r[2]=read(ram,0x0c042644u,4);
goto P_0c0425ca;
P_0c0425ca: /* original 1e27, guest PC 0x0c0425ca */
if(!s->budget--) { s->failed_pc=0x0c0425cau; return 0; }
write(ram,r[14]+28,r[2],4);
goto P_0c0425cc;
P_0c0425cc: /* original 4d0b, guest PC 0x0c0425cc */
if(!s->budget--) { s->failed_pc=0x0c0425ccu; return 0; }
target=r[13];
r[16]=0x0c0425d0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0425d0u) { target=s->pc; goto dispatch; }
goto P_0c0425d0;
P_0c0425ce: /* original 64e3, guest PC 0x0c0425ce */
if(!s->budget--) { s->failed_pc=0x0c0425ceu; return 0; }
r[4]=r[14];
goto P_0c0425d0;
P_0c0425d0: /* original d30d, guest PC 0x0c0425d0 */
if(!s->budget--) { s->failed_pc=0x0c0425d0u; return 0; }
r[3]=read(ram,0x0c042608u,4);
goto P_0c0425d2;
P_0c0425d2: /* original 7e20, guest PC 0x0c0425d2 */
if(!s->budget--) { s->failed_pc=0x0c0425d2u; return 0; }
r[14]+=0x00000020u;
goto P_0c0425d4;
P_0c0425d4: /* original d012, guest PC 0x0c0425d4 */
if(!s->budget--) { s->failed_pc=0x0c0425d4u; return 0; }
r[0]=read(ram,0x0c042620u,4);
goto P_0c0425d6;
P_0c0425d6: /* original 6432, guest PC 0x0c0425d6 */
if(!s->budget--) { s->failed_pc=0x0c0425d6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0425d8;
P_0c0425d8: /* original d21b, guest PC 0x0c0425d8 */
if(!s->budget--) { s->failed_pc=0x0c0425d8u; return 0; }
r[2]=read(ram,0x0c042648u,4);
goto P_0c0425da;
P_0c0425da: /* original 2e09, guest PC 0x0c0425da */
if(!s->budget--) { s->failed_pc=0x0c0425dau; return 0; }
r[14]&=r[0];
goto P_0c0425dc;
P_0c0425dc: /* original 7408, guest PC 0x0c0425dc */
if(!s->budget--) { s->failed_pc=0x0c0425dcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0425de;
P_0c0425de: /* original 6142, guest PC 0x0c0425de */
if(!s->budget--) { s->failed_pc=0x0c0425deu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c0425e0;
P_0c0425e0: /* original 2129, guest PC 0x0c0425e0 */
if(!s->budget--) { s->failed_pc=0x0c0425e0u; return 0; }
r[1]&=r[2];
goto P_0c0425e2;
P_0c0425e2: /* original 21eb, guest PC 0x0c0425e2 */
if(!s->budget--) { s->failed_pc=0x0c0425e2u; return 0; }
r[1]|=r[14];
goto P_0c0425e4;
P_0c0425e4: /* original 2412, guest PC 0x0c0425e4 */
if(!s->budget--) { s->failed_pc=0x0c0425e4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0425e6;
P_0c0425e6: /* original 4f26, guest PC 0x0c0425e6 */
if(!s->budget--) { s->failed_pc=0x0c0425e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0425e8;
P_0c0425e8: /* original 6cf6, guest PC 0x0c0425e8 */
if(!s->budget--) { s->failed_pc=0x0c0425e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0425ea;
P_0c0425ea: /* original 6df6, guest PC 0x0c0425ea */
if(!s->budget--) { s->failed_pc=0x0c0425eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0425ec;
P_0c0425ec: /* original 000b, guest PC 0x0c0425ec */
if(!s->budget--) { s->failed_pc=0x0c0425ecu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0425ee: /* original 6ef6, guest PC 0x0c0425ee */
if(!s->budget--) { s->failed_pc=0x0c0425eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0425f0;
P_0c0425f0: /* original d316, guest PC 0x0c0425f0 */
if(!s->budget--) { s->failed_pc=0x0c0425f0u; return 0; }
r[3]=read(ram,0x0c04264cu,4);
goto P_0c0425f2;
P_0c0425f2: /* original 2342, guest PC 0x0c0425f2 */
if(!s->budget--) { s->failed_pc=0x0c0425f2u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0425f4;
P_0c0425f4: /* original d216, guest PC 0x0c0425f4 */
if(!s->budget--) { s->failed_pc=0x0c0425f4u; return 0; }
r[2]=read(ram,0x0c042650u,4);
goto P_0c0425f6;
P_0c0425f6: /* original 2242, guest PC 0x0c0425f6 */
if(!s->budget--) { s->failed_pc=0x0c0425f6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0425f8;
P_0c0425f8: /* original d116, guest PC 0x0c0425f8 */
if(!s->budget--) { s->failed_pc=0x0c0425f8u; return 0; }
r[1]=read(ram,0x0c042654u,4);
goto P_0c0425fa;
P_0c0425fa: /* original 000b, guest PC 0x0c0425fa */
if(!s->budget--) { s->failed_pc=0x0c0425fau; return 0; }
target=r[16];
write(ram,r[1],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0425fc: /* original 2152, guest PC 0x0c0425fc */
if(!s->budget--) { s->failed_pc=0x0c0425fcu; return 0; }
write(ram,r[1],r[5],4);
return vf3_matrix_family(0x0c0425feu,s,ram);
P_0c042660: /* original 2fe6, guest PC 0x0c042660 */
if(!s->budget--) { s->failed_pc=0x0c042660u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042662;
P_0c042662: /* original 6e43, guest PC 0x0c042662 */
if(!s->budget--) { s->failed_pc=0x0c042662u; return 0; }
r[14]=r[4];
goto P_0c042664;
P_0c042664: /* original 2fd6, guest PC 0x0c042664 */
if(!s->budget--) { s->failed_pc=0x0c042664u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042666;
P_0c042666: /* original e418, guest PC 0x0c042666 */
if(!s->budget--) { s->failed_pc=0x0c042666u; return 0; }
r[4]=0x00000018u;
goto P_0c042668;
P_0c042668: /* original 2fc6, guest PC 0x0c042668 */
if(!s->budget--) { s->failed_pc=0x0c042668u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266a;
P_0c04266a: /* original 2fb6, guest PC 0x0c04266a */
if(!s->budget--) { s->failed_pc=0x0c04266au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266c;
P_0c04266c: /* original 2fa6, guest PC 0x0c04266c */
if(!s->budget--) { s->failed_pc=0x0c04266cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04266e;
P_0c04266e: /* original 2f96, guest PC 0x0c04266e */
if(!s->budget--) { s->failed_pc=0x0c04266eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042670;
P_0c042670: /* original 2f86, guest PC 0x0c042670 */
if(!s->budget--) { s->failed_pc=0x0c042670u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042672;
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
target=0x0c042ae0u; r[16]=0x0c0426a4u;
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
r[16]=0x0c0426aeu;
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
r[16]=0x0c0426e2u;
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
target=0x0c0429b0u; r[16]=0x0c04274cu;
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
P_0c042790: /* original 2fe6, guest PC 0x0c042790 */
if(!s->budget--) { s->failed_pc=0x0c042790u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042792;
P_0c042792: /* original 2fd6, guest PC 0x0c042792 */
if(!s->budget--) { s->failed_pc=0x0c042792u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042794;
P_0c042794: /* original 2fc6, guest PC 0x0c042794 */
if(!s->budget--) { s->failed_pc=0x0c042794u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042796;
P_0c042796: /* original 2fb6, guest PC 0x0c042796 */
if(!s->budget--) { s->failed_pc=0x0c042796u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042798;
P_0c042798: /* original 2fa6, guest PC 0x0c042798 */
if(!s->budget--) { s->failed_pc=0x0c042798u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04279a;
P_0c04279a: /* original 2f96, guest PC 0x0c04279a */
if(!s->budget--) { s->failed_pc=0x0c04279au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04279c;
P_0c04279c: /* original 4f22, guest PC 0x0c04279c */
if(!s->budget--) { s->failed_pc=0x0c04279cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04279e;
P_0c04279e: /* original 4f12, guest PC 0x0c04279e */
if(!s->budget--) { s->failed_pc=0x0c04279eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0427a0;
P_0c0427a0: /* original a099, guest PC 0x0c0427a0 */
if(!s->budget--) { s->failed_pc=0x0c0427a0u; return 0; }
r[13]=r[4];
goto P_0c0428d6;
P_0c0427a2: /* original 6d43, guest PC 0x0c0427a2 */
if(!s->budget--) { s->failed_pc=0x0c0427a2u; return 0; }
r[13]=r[4];
return vf3_matrix_family(0x0c0427a4u,s,ram);
P_0c0427b0: /* original d41e, guest PC 0x0c0427b0 */
if(!s->budget--) { s->failed_pc=0x0c0427b0u; return 0; }
r[4]=read(ram,0x0c04282cu,4);
goto P_0c0427b2;
P_0c0427b2: /* original d61f, guest PC 0x0c0427b2 */
if(!s->budget--) { s->failed_pc=0x0c0427b2u; return 0; }
r[6]=read(ram,0x0c042830u,4);
goto P_0c0427b4;
P_0c0427b4: /* original 60e3, guest PC 0x0c0427b4 */
if(!s->budget--) { s->failed_pc=0x0c0427b4u; return 0; }
r[0]=r[14];
goto P_0c0427b6;
P_0c0427b6: /* original 0009, guest PC 0x0c0427b6 */
if(!s->budget--) { s->failed_pc=0x0c0427b6u; return 0; }
goto P_0c0427b8;
P_0c0427b8: /* original 880a, guest PC 0x0c0427b8 */
if(!s->budget--) { s->failed_pc=0x0c0427b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0427ba;
P_0c0427ba: /* original 8f09, guest PC 0x0c0427ba */
if(!s->budget--) { s->failed_pc=0x0c0427bau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[5]=tmp;
if(!cond) { goto P_0c0427d0; }
goto P_0c0427be;
P_0c0427bc: /* original 6562, guest PC 0x0c0427bc */
if(!s->budget--) { s->failed_pc=0x0c0427bcu; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c0427be;
P_0c0427be: /* original 2452, guest PC 0x0c0427be */
if(!s->budget--) { s->failed_pc=0x0c0427beu; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0427c0;
P_0c0427c0: /* original d41c, guest PC 0x0c0427c0 */
if(!s->budget--) { s->failed_pc=0x0c0427c0u; return 0; }
r[4]=read(ram,0x0c042834u,4);
goto P_0c0427c2;
P_0c0427c2: /* original 6342, guest PC 0x0c0427c2 */
if(!s->budget--) { s->failed_pc=0x0c0427c2u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0427c4;
P_0c0427c4: /* original 7318, guest PC 0x0c0427c4 */
if(!s->budget--) { s->failed_pc=0x0c0427c4u; return 0; }
r[3]+=0x00000018u;
goto P_0c0427c6;
P_0c0427c6: /* original a086, guest PC 0x0c0427c6 */
if(!s->budget--) { s->failed_pc=0x0c0427c6u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0428d6;
P_0c0427c8: /* original 2432, guest PC 0x0c0427c8 */
if(!s->budget--) { s->failed_pc=0x0c0427c8u; return 0; }
write(ram,r[4],r[3],4);
return vf3_matrix_family(0x0c0427cau,s,ram);
P_0c0427d0: /* original 880d, guest PC 0x0c0427d0 */
if(!s->budget--) { s->failed_pc=0x0c0427d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0427d2;
P_0c0427d2: /* original 8b05, guest PC 0x0c0427d2 */
if(!s->budget--) { s->failed_pc=0x0c0427d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0427e0; }
goto P_0c0427d4;
P_0c0427d4: /* original a07f, guest PC 0x0c0427d4 */
if(!s->budget--) { s->failed_pc=0x0c0427d4u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c0428d6;
P_0c0427d6: /* original 2452, guest PC 0x0c0427d6 */
if(!s->budget--) { s->failed_pc=0x0c0427d6u; return 0; }
write(ram,r[4],r[5],4);
return vf3_matrix_family(0x0c0427d8u,s,ram);
P_0c0427e0: /* original d515, guest PC 0x0c0427e0 */
if(!s->budget--) { s->failed_pc=0x0c0427e0u; return 0; }
r[5]=read(ram,0x0c042838u,4);
goto P_0c0427e2;
P_0c0427e2: /* original 9420, guest PC 0x0c0427e2 */
if(!s->budget--) { s->failed_pc=0x0c0427e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042826u,2);
goto P_0c0427e4;
P_0c0427e4: /* original 6050, guest PC 0x0c0427e4 */
if(!s->budget--) { s->failed_pc=0x0c0427e4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0427e6;
P_0c0427e6: /* original 8800, guest PC 0x0c0427e6 */
if(!s->budget--) { s->failed_pc=0x0c0427e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0427e8;
P_0c0427e8: /* original 890a, guest PC 0x0c0427e8 */
if(!s->budget--) { s->failed_pc=0x0c0427e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042800; }
goto P_0c0427ea;
P_0c0427ea: /* original 8801, guest PC 0x0c0427ea */
if(!s->budget--) { s->failed_pc=0x0c0427eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0427ec;
P_0c0427ec: /* original 8910, guest PC 0x0c0427ec */
if(!s->budget--) { s->failed_pc=0x0c0427ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042810; }
goto P_0c0427ee;
P_0c0427ee: /* original a047, guest PC 0x0c0427ee */
if(!s->budget--) { s->failed_pc=0x0c0427eeu; return 0; }
goto P_0c042880;
P_0c0427f0: /* original 0009, guest PC 0x0c0427f0 */
if(!s->budget--) { s->failed_pc=0x0c0427f0u; return 0; }
return vf3_matrix_family(0x0c0427f2u,s,ram);
P_0c042800: /* original bf2e, guest PC 0x0c042800 */
if(!s->budget--) { s->failed_pc=0x0c042800u; return 0; }
target=0x0c042660u; r[16]=0x0c042804u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c042804u) { target=s->pc; goto dispatch; }
goto P_0c042804;
P_0c042802: /* original 64e3, guest PC 0x0c042802 */
if(!s->budget--) { s->failed_pc=0x0c042802u; return 0; }
r[4]=r[14];
goto P_0c042804;
P_0c042804: /* original a067, guest PC 0x0c042804 */
if(!s->budget--) { s->failed_pc=0x0c042804u; return 0; }
goto P_0c0428d6;
P_0c042806: /* original 0009, guest PC 0x0c042806 */
if(!s->budget--) { s->failed_pc=0x0c042806u; return 0; }
return vf3_matrix_family(0x0c042808u,s,ram);
P_0c042810: /* original 3e43, guest PC 0x0c042810 */
if(!s->budget--) { s->failed_pc=0x0c042810u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[4])!=0);
goto P_0c042812;
P_0c042812: /* original 8b5d, guest PC 0x0c042812 */
if(!s->budget--) { s->failed_pc=0x0c042812u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428d0; }
goto P_0c042814;
P_0c042814: /* original 9408, guest PC 0x0c042814 */
if(!s->budget--) { s->failed_pc=0x0c042814u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042828u,2);
goto P_0c042816;
P_0c042816: /* original 3e40, guest PC 0x0c042816 */
if(!s->budget--) { s->failed_pc=0x0c042816u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c042818;
P_0c042818: /* original 8b12, guest PC 0x0c042818 */
if(!s->budget--) { s->failed_pc=0x0c042818u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042840; }
goto P_0c04281a;
P_0c04281a: /* original 6ed4, guest PC 0x0c04281a */
if(!s->budget--) { s->failed_pc=0x0c04281au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[14]=tmp;
goto P_0c04281c;
P_0c04281c: /* original 6eec, guest PC 0x0c04281c */
if(!s->budget--) { s->failed_pc=0x0c04281cu; return 0; }
r[14]=r[14]&255u;
goto P_0c04281e;
P_0c04281e: /* original 2ee8, guest PC 0x0c04281e */
if(!s->budget--) { s->failed_pc=0x0c04281eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c042820;
P_0c042820: /* original 895f, guest PC 0x0c042820 */
if(!s->budget--) { s->failed_pc=0x0c042820u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042822;
P_0c042822: /* original a055, guest PC 0x0c042822 */
if(!s->budget--) { s->failed_pc=0x0c042822u; return 0; }
goto P_0c0428d0;
P_0c042824: /* original 0009, guest PC 0x0c042824 */
if(!s->budget--) { s->failed_pc=0x0c042824u; return 0; }
return vf3_matrix_family(0x0c042826u,s,ram);
P_0c042840: /* original 9469, guest PC 0x0c042840 */
if(!s->budget--) { s->failed_pc=0x0c042840u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042916u,2);
goto P_0c042842;
P_0c042842: /* original 3e40, guest PC 0x0c042842 */
if(!s->budget--) { s->failed_pc=0x0c042842u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c042844;
P_0c042844: /* original 8b0c, guest PC 0x0c042844 */
if(!s->budget--) { s->failed_pc=0x0c042844u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042860; }
goto P_0c042846;
P_0c042846: /* original 64d4, guest PC 0x0c042846 */
if(!s->budget--) { s->failed_pc=0x0c042846u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[4]=tmp;
goto P_0c042848;
P_0c042848: /* original 644c, guest PC 0x0c042848 */
if(!s->budget--) { s->failed_pc=0x0c042848u; return 0; }
r[4]=r[4]&255u;
goto P_0c04284a;
P_0c04284a: /* original 2448, guest PC 0x0c04284a */
if(!s->budget--) { s->failed_pc=0x0c04284au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04284c;
P_0c04284c: /* original 8949, guest PC 0x0c04284c */
if(!s->budget--) { s->failed_pc=0x0c04284cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c04284e;
P_0c04284e: /* original 64d4, guest PC 0x0c04284e */
if(!s->budget--) { s->failed_pc=0x0c04284eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[4]=tmp;
goto P_0c042850;
P_0c042850: /* original 644c, guest PC 0x0c042850 */
if(!s->budget--) { s->failed_pc=0x0c042850u; return 0; }
r[4]=r[4]&255u;
goto P_0c042852;
P_0c042852: /* original 2448, guest PC 0x0c042852 */
if(!s->budget--) { s->failed_pc=0x0c042852u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c042854;
P_0c042854: /* original 8945, guest PC 0x0c042854 */
if(!s->budget--) { s->failed_pc=0x0c042854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042856;
P_0c042856: /* original 9e5f, guest PC 0x0c042856 */
if(!s->budget--) { s->failed_pc=0x0c042856u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042918u,2);
goto P_0c042858;
P_0c042858: /* original bf02, guest PC 0x0c042858 */
if(!s->budget--) { s->failed_pc=0x0c042858u; return 0; }
target=0x0c042660u; r[16]=0x0c04285cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04285cu) { target=s->pc; goto dispatch; }
goto P_0c04285c;
P_0c04285a: /* original 64e3, guest PC 0x0c04285a */
if(!s->budget--) { s->failed_pc=0x0c04285au; return 0; }
r[4]=r[14];
goto P_0c04285c;
P_0c04285c: /* original a03b, guest PC 0x0c04285c */
if(!s->budget--) { s->failed_pc=0x0c04285cu; return 0; }
goto P_0c0428d6;
P_0c04285e: /* original 0009, guest PC 0x0c04285e */
if(!s->budget--) { s->failed_pc=0x0c04285eu; return 0; }
goto P_0c042860;
P_0c042860: /* original 6cd4, guest PC 0x0c042860 */
if(!s->budget--) { s->failed_pc=0x0c042860u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[12]=tmp;
goto P_0c042862;
P_0c042862: /* original 6ccc, guest PC 0x0c042862 */
if(!s->budget--) { s->failed_pc=0x0c042862u; return 0; }
r[12]=r[12]&255u;
goto P_0c042864;
P_0c042864: /* original 2cc8, guest PC 0x0c042864 */
if(!s->budget--) { s->failed_pc=0x0c042864u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c042866;
P_0c042866: /* original 893c, guest PC 0x0c042866 */
if(!s->budget--) { s->failed_pc=0x0c042866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c042868;
P_0c042868: /* original 9b57, guest PC 0x0c042868 */
if(!s->budget--) { s->failed_pc=0x0c042868u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291au,2);
goto P_0c04286a;
P_0c04286a: /* original 64e3, guest PC 0x0c04286a */
if(!s->budget--) { s->failed_pc=0x0c04286au; return 0; }
r[4]=r[14];
goto P_0c04286c;
P_0c04286c: /* original ea5e, guest PC 0x0c04286c */
if(!s->budget--) { s->failed_pc=0x0c04286cu; return 0; }
r[10]=0x0000005eu;
goto P_0c04286e;
P_0c04286e: /* original 34bc, guest PC 0x0c04286e */
if(!s->budget--) { s->failed_pc=0x0c04286eu; return 0; }
r[4]+=r[11];
goto P_0c042870;
P_0c042870: /* original 04a7, guest PC 0x0c042870 */
if(!s->budget--) { s->failed_pc=0x0c042870u; return 0; }
r[19]=r[4]*r[10];
goto P_0c042872;
P_0c042872: /* original 041a, guest PC 0x0c042872 */
if(!s->budget--) { s->failed_pc=0x0c042872u; return 0; }
r[4]=r[19];
goto P_0c042874;
P_0c042874: /* original 34cc, guest PC 0x0c042874 */
if(!s->budget--) { s->failed_pc=0x0c042874u; return 0; }
r[4]+=r[12];
goto P_0c042876;
P_0c042876: /* original bef3, guest PC 0x0c042876 */
if(!s->budget--) { s->failed_pc=0x0c042876u; return 0; }
target=0x0c042660u; r[16]=0x0c04287au;
r[4]+=0x0000005fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04287au) { target=s->pc; goto dispatch; }
goto P_0c04287a;
P_0c042878: /* original 745f, guest PC 0x0c042878 */
if(!s->budget--) { s->failed_pc=0x0c042878u; return 0; }
r[4]+=0x0000005fu;
goto P_0c04287a;
P_0c04287a: /* original a02c, guest PC 0x0c04287a */
if(!s->budget--) { s->failed_pc=0x0c04287au; return 0; }
goto P_0c0428d6;
P_0c04287c: /* original 0009, guest PC 0x0c04287c */
if(!s->budget--) { s->failed_pc=0x0c04287cu; return 0; }
return vf3_matrix_family(0x0c04287eu,s,ram);
P_0c042880: /* original 954c, guest PC 0x0c042880 */
if(!s->budget--) { s->failed_pc=0x0c042880u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291cu,2);
goto P_0c042882;
P_0c042882: /* original 3e53, guest PC 0x0c042882 */
if(!s->budget--) { s->failed_pc=0x0c042882u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c042884;
P_0c042884: /* original 8b02, guest PC 0x0c042884 */
if(!s->budget--) { s->failed_pc=0x0c042884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04288c; }
goto P_0c042886;
P_0c042886: /* original 924a, guest PC 0x0c042886 */
if(!s->budget--) { s->failed_pc=0x0c042886u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04291eu,2);
goto P_0c042888;
P_0c042888: /* original 3e27, guest PC 0x0c042888 */
if(!s->budget--) { s->failed_pc=0x0c042888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[2])!=0);
goto P_0c04288a;
P_0c04288a: /* original 8b05, guest PC 0x0c04288a */
if(!s->budget--) { s->failed_pc=0x0c04288au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042898; }
goto P_0c04288c;
P_0c04288c: /* original 9148, guest PC 0x0c04288c */
if(!s->budget--) { s->failed_pc=0x0c04288cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042920u,2);
goto P_0c04288e;
P_0c04288e: /* original 3e13, guest PC 0x0c04288e */
if(!s->budget--) { s->failed_pc=0x0c04288eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[1])!=0);
goto P_0c042890;
P_0c042890: /* original 8b1e, guest PC 0x0c042890 */
if(!s->budget--) { s->failed_pc=0x0c042890u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428d0; }
goto P_0c042892;
P_0c042892: /* original 9246, guest PC 0x0c042892 */
if(!s->budget--) { s->failed_pc=0x0c042892u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042922u,2);
goto P_0c042894;
P_0c042894: /* original 3e27, guest PC 0x0c042894 */
if(!s->budget--) { s->failed_pc=0x0c042894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[2])!=0);
goto P_0c042896;
P_0c042896: /* original 891b, guest PC 0x0c042896 */
if(!s->budget--) { s->failed_pc=0x0c042896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428d0; }
goto P_0c042898;
P_0c042898: /* original 6cd4, guest PC 0x0c042898 */
if(!s->budget--) { s->failed_pc=0x0c042898u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[12]=tmp;
goto P_0c04289a;
P_0c04289a: /* original 6ccc, guest PC 0x0c04289a */
if(!s->budget--) { s->failed_pc=0x0c04289au; return 0; }
r[12]=r[12]&255u;
goto P_0c04289c;
P_0c04289c: /* original 2cc8, guest PC 0x0c04289c */
if(!s->budget--) { s->failed_pc=0x0c04289cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04289e;
P_0c04289e: /* original 8920, guest PC 0x0c04289e */
if(!s->budget--) { s->failed_pc=0x0c04289eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c0428a0;
P_0c0428a0: /* original 953e, guest PC 0x0c0428a0 */
if(!s->budget--) { s->failed_pc=0x0c0428a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042920u,2);
goto P_0c0428a2;
P_0c0428a2: /* original 3e53, guest PC 0x0c0428a2 */
if(!s->budget--) { s->failed_pc=0x0c0428a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c0428a4;
P_0c0428a4: /* original 8b00, guest PC 0x0c0428a4 */
if(!s->budget--) { s->failed_pc=0x0c0428a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428a8; }
goto P_0c0428a6;
P_0c0428a6: /* original 7ec0, guest PC 0x0c0428a6 */
if(!s->budget--) { s->failed_pc=0x0c0428a6u; return 0; }
r[14]+=0xffffffc0u;
goto P_0c0428a8;
P_0c0428a8: /* original 3c43, guest PC 0x0c0428a8 */
if(!s->budget--) { s->failed_pc=0x0c0428a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c0428aa;
P_0c0428aa: /* original 8b00, guest PC 0x0c0428aa */
if(!s->budget--) { s->failed_pc=0x0c0428aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0428ae; }
goto P_0c0428ac;
P_0c0428ac: /* original 7cff, guest PC 0x0c0428ac */
if(!s->budget--) { s->failed_pc=0x0c0428acu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0428ae;
P_0c0428ae: /* original 9a3a, guest PC 0x0c0428ae */
if(!s->budget--) { s->failed_pc=0x0c0428aeu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042926u,2);
goto P_0c0428b0;
P_0c0428b0: /* original 64e3, guest PC 0x0c0428b0 */
if(!s->budget--) { s->failed_pc=0x0c0428b0u; return 0; }
r[4]=r[14];
goto P_0c0428b2;
P_0c0428b2: /* original 9b39, guest PC 0x0c0428b2 */
if(!s->budget--) { s->failed_pc=0x0c0428b2u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042928u,2);
goto P_0c0428b4;
P_0c0428b4: /* original 34ac, guest PC 0x0c0428b4 */
if(!s->budget--) { s->failed_pc=0x0c0428b4u; return 0; }
r[4]+=r[10];
goto P_0c0428b6;
P_0c0428b6: /* original 9935, guest PC 0x0c0428b6 */
if(!s->budget--) { s->failed_pc=0x0c0428b6u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042924u,2);
goto P_0c0428b8;
P_0c0428b8: /* original 04b7, guest PC 0x0c0428b8 */
if(!s->budget--) { s->failed_pc=0x0c0428b8u; return 0; }
r[19]=r[4]*r[11];
goto P_0c0428ba;
P_0c0428ba: /* original 041a, guest PC 0x0c0428ba */
if(!s->budget--) { s->failed_pc=0x0c0428bau; return 0; }
r[4]=r[19];
goto P_0c0428bc;
P_0c0428bc: /* original 34cc, guest PC 0x0c0428bc */
if(!s->budget--) { s->failed_pc=0x0c0428bcu; return 0; }
r[4]+=r[12];
goto P_0c0428be;
P_0c0428be: /* original a008, guest PC 0x0c0428be */
if(!s->budget--) { s->failed_pc=0x0c0428beu; return 0; }
r[4]+=r[9];
goto P_0c0428d2;
P_0c0428c0: /* original 349c, guest PC 0x0c0428c0 */
if(!s->budget--) { s->failed_pc=0x0c0428c0u; return 0; }
r[4]+=r[9];
return vf3_matrix_family(0x0c0428c2u,s,ram);
P_0c0428d0: /* original 64e3, guest PC 0x0c0428d0 */
if(!s->budget--) { s->failed_pc=0x0c0428d0u; return 0; }
r[4]=r[14];
goto P_0c0428d2;
P_0c0428d2: /* original bec5, guest PC 0x0c0428d2 */
if(!s->budget--) { s->failed_pc=0x0c0428d2u; return 0; }
target=0x0c042660u; r[16]=0x0c0428d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0428d6u) { target=s->pc; goto dispatch; }
goto P_0c0428d6;
P_0c0428d4: /* original 0009, guest PC 0x0c0428d4 */
if(!s->budget--) { s->failed_pc=0x0c0428d4u; return 0; }
goto P_0c0428d6;
P_0c0428d6: /* original 6ed4, guest PC 0x0c0428d6 */
if(!s->budget--) { s->failed_pc=0x0c0428d6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[14]=tmp;
goto P_0c0428d8;
P_0c0428d8: /* original 6eec, guest PC 0x0c0428d8 */
if(!s->budget--) { s->failed_pc=0x0c0428d8u; return 0; }
r[14]=r[14]&255u;
goto P_0c0428da;
P_0c0428da: /* original 2ee8, guest PC 0x0c0428da */
if(!s->budget--) { s->failed_pc=0x0c0428dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0428dc;
P_0c0428dc: /* original 8901, guest PC 0x0c0428dc */
if(!s->budget--) { s->failed_pc=0x0c0428dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0428e2; }
goto P_0c0428de;
P_0c0428de: /* original af67, guest PC 0x0c0428de */
if(!s->budget--) { s->failed_pc=0x0c0428deu; return 0; }
goto P_0c0427b0;
P_0c0428e0: /* original 0009, guest PC 0x0c0428e0 */
if(!s->budget--) { s->failed_pc=0x0c0428e0u; return 0; }
goto P_0c0428e2;
P_0c0428e2: /* original 4f16, guest PC 0x0c0428e2 */
if(!s->budget--) { s->failed_pc=0x0c0428e2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0428e4;
P_0c0428e4: /* original 4f26, guest PC 0x0c0428e4 */
if(!s->budget--) { s->failed_pc=0x0c0428e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0428e6;
P_0c0428e6: /* original 69f6, guest PC 0x0c0428e6 */
if(!s->budget--) { s->failed_pc=0x0c0428e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0428e8;
P_0c0428e8: /* original 6af6, guest PC 0x0c0428e8 */
if(!s->budget--) { s->failed_pc=0x0c0428e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0428ea;
P_0c0428ea: /* original 6bf6, guest PC 0x0c0428ea */
if(!s->budget--) { s->failed_pc=0x0c0428eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0428ec;
P_0c0428ec: /* original 6cf6, guest PC 0x0c0428ec */
if(!s->budget--) { s->failed_pc=0x0c0428ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0428ee;
P_0c0428ee: /* original 6df6, guest PC 0x0c0428ee */
if(!s->budget--) { s->failed_pc=0x0c0428eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0428f0;
P_0c0428f0: /* original 000b, guest PC 0x0c0428f0 */
if(!s->budget--) { s->failed_pc=0x0c0428f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0428f2: /* original 6ef6, guest PC 0x0c0428f2 */
if(!s->budget--) { s->failed_pc=0x0c0428f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0428f4u,s,ram);
P_0c042900: /* original 4f22, guest PC 0x0c042900 */
if(!s->budget--) { s->failed_pc=0x0c042900u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042902;
P_0c042902: /* original e503, guest PC 0x0c042902 */
if(!s->budget--) { s->failed_pc=0x0c042902u; return 0; }
r[5]=0x00000003u;
goto P_0c042904;
P_0c042904: /* original 60f3, guest PC 0x0c042904 */
if(!s->budget--) { s->failed_pc=0x0c042904u; return 0; }
r[0]=r[15];
goto P_0c042906;
P_0c042906: /* original 7004, guest PC 0x0c042906 */
if(!s->budget--) { s->failed_pc=0x0c042906u; return 0; }
r[0]+=0x00000004u;
goto P_0c042908;
P_0c042908: /* original 7004, guest PC 0x0c042908 */
if(!s->budget--) { s->failed_pc=0x0c042908u; return 0; }
r[0]+=0x00000004u;
goto P_0c04290a;
P_0c04290a: /* original 2508, guest PC 0x0c04290a */
if(!s->budget--) { s->failed_pc=0x0c04290au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c04290c;
P_0c04290c: /* original 8910, guest PC 0x0c04290c */
if(!s->budget--) { s->failed_pc=0x0c04290cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042930; }
goto P_0c04290e;
P_0c04290e: /* original 65f3, guest PC 0x0c04290e */
if(!s->budget--) { s->failed_pc=0x0c04290eu; return 0; }
r[5]=r[15];
goto P_0c042910;
P_0c042910: /* original 7504, guest PC 0x0c042910 */
if(!s->budget--) { s->failed_pc=0x0c042910u; return 0; }
r[5]+=0x00000004u;
goto P_0c042912;
P_0c042912: /* original a010, guest PC 0x0c042912 */
if(!s->budget--) { s->failed_pc=0x0c042912u; return 0; }
r[5]+=0x00000008u;
goto P_0c042936;
P_0c042914: /* original 7508, guest PC 0x0c042914 */
if(!s->budget--) { s->failed_pc=0x0c042914u; return 0; }
r[5]+=0x00000008u;
return vf3_matrix_family(0x0c042916u,s,ram);
P_0c042930: /* original 65f3, guest PC 0x0c042930 */
if(!s->budget--) { s->failed_pc=0x0c042930u; return 0; }
r[5]=r[15];
goto P_0c042932;
P_0c042932: /* original 7504, guest PC 0x0c042932 */
if(!s->budget--) { s->failed_pc=0x0c042932u; return 0; }
r[5]+=0x00000004u;
goto P_0c042934;
P_0c042934: /* original 7504, guest PC 0x0c042934 */
if(!s->budget--) { s->failed_pc=0x0c042934u; return 0; }
r[5]+=0x00000004u;
goto P_0c042936;
P_0c042936: /* original d318, guest PC 0x0c042936 */
if(!s->budget--) { s->failed_pc=0x0c042936u; return 0; }
r[3]=read(ram,0x0c042998u,4);
goto P_0c042938;
P_0c042938: /* original 6653, guest PC 0x0c042938 */
if(!s->budget--) { s->failed_pc=0x0c042938u; return 0; }
r[6]=r[5];
goto P_0c04293a;
P_0c04293a: /* original d416, guest PC 0x0c04293a */
if(!s->budget--) { s->failed_pc=0x0c04293au; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c04293c;
P_0c04293c: /* original 430b, guest PC 0x0c04293c */
if(!s->budget--) { s->failed_pc=0x0c04293cu; return 0; }
target=r[3];
r[16]=0x0c042940u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c042940u) { target=s->pc; goto dispatch; }
goto P_0c042940;
P_0c04293e: /* original 55f1, guest PC 0x0c04293e */
if(!s->budget--) { s->failed_pc=0x0c04293eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c042940;
P_0c042940: /* original d414, guest PC 0x0c042940 */
if(!s->budget--) { s->failed_pc=0x0c042940u; return 0; }
r[4]=read(ram,0x0c042994u,4);
goto P_0c042942;
P_0c042942: /* original bf25, guest PC 0x0c042942 */
if(!s->budget--) { s->failed_pc=0x0c042942u; return 0; }
target=0x0c042790u; r[16]=0x0c042946u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c042946u) { target=s->pc; goto dispatch; }
goto P_0c042946;
P_0c042944: /* original 0009, guest PC 0x0c042944 */
if(!s->budget--) { s->failed_pc=0x0c042944u; return 0; }
goto P_0c042946;
P_0c042946: /* original 4f26, guest PC 0x0c042946 */
if(!s->budget--) { s->failed_pc=0x0c042946u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042948;
P_0c042948: /* original 000b, guest PC 0x0c042948 */
if(!s->budget--) { s->failed_pc=0x0c042948u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04294a: /* original e000, guest PC 0x0c04294a */
if(!s->budget--) { s->failed_pc=0x0c04294au; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c04294cu,s,ram);
P_0c042960: /* original d20f, guest PC 0x0c042960 */
if(!s->budget--) { s->failed_pc=0x0c042960u; return 0; }
r[2]=read(ram,0x0c0429a0u,4);
goto P_0c042962;
P_0c042962: /* original 000b, guest PC 0x0c042962 */
if(!s->budget--) { s->failed_pc=0x0c042962u; return 0; }
target=r[16];
write(ram,r[2],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042964: /* original 2240, guest PC 0x0c042964 */
if(!s->budget--) { s->failed_pc=0x0c042964u; return 0; }
write(ram,r[2],r[4],1);
return vf3_matrix_family(0x0c042966u,s,ram);
P_0c042970: /* original d30c, guest PC 0x0c042970 */
if(!s->budget--) { s->failed_pc=0x0c042970u; return 0; }
r[3]=read(ram,0x0c0429a4u,4);
goto P_0c042972;
P_0c042972: /* original 000b, guest PC 0x0c042972 */
if(!s->budget--) { s->failed_pc=0x0c042972u; return 0; }
target=r[16];
write(ram,r[3],r[4],1);
s->pc=target; return ram->oob==0;
P_0c042974: /* original 2340, guest PC 0x0c042974 */
if(!s->budget--) { s->failed_pc=0x0c042974u; return 0; }
write(ram,r[3],r[4],1);
return vf3_matrix_family(0x0c042976u,s,ram);
P_0c0429b0: /* original 2fe6, guest PC 0x0c0429b0 */
if(!s->budget--) { s->failed_pc=0x0c0429b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b2;
P_0c0429b2: /* original 2fb6, guest PC 0x0c0429b2 */
if(!s->budget--) { s->failed_pc=0x0c0429b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b4;
P_0c0429b4: /* original 2fa6, guest PC 0x0c0429b4 */
if(!s->budget--) { s->failed_pc=0x0c0429b4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b6;
P_0c0429b6: /* original 2f96, guest PC 0x0c0429b6 */
if(!s->budget--) { s->failed_pc=0x0c0429b6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0429b8;
P_0c0429b8: /* original d233, guest PC 0x0c0429b8 */
if(!s->budget--) { s->failed_pc=0x0c0429b8u; return 0; }
r[2]=read(ram,0x0c042a88u,4);
goto P_0c0429ba;
P_0c0429ba: /* original 6922, guest PC 0x0c0429ba */
if(!s->budget--) { s->failed_pc=0x0c0429bau; return 0; }
tmp=read(ram,r[2],4);
r[9]=tmp;
goto P_0c0429bc;
P_0c0429bc: /* original 2998, guest PC 0x0c0429bc */
if(!s->budget--) { s->failed_pc=0x0c0429bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0429be;
P_0c0429be: /* original 893a, guest PC 0x0c0429be */
if(!s->budget--) { s->failed_pc=0x0c0429beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429c0;
P_0c0429c0: /* original 4611, guest PC 0x0c0429c0 */
if(!s->budget--) { s->failed_pc=0x0c0429c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0429c2;
P_0c0429c2: /* original 8b38, guest PC 0x0c0429c2 */
if(!s->budget--) { s->failed_pc=0x0c0429c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042a36; }
goto P_0c0429c4;
P_0c0429c4: /* original 975c, guest PC 0x0c0429c4 */
if(!s->budget--) { s->failed_pc=0x0c0429c4u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a80u,2);
goto P_0c0429c6;
P_0c0429c6: /* original 3472, guest PC 0x0c0429c6 */
if(!s->budget--) { s->failed_pc=0x0c0429c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[7])!=0);
goto P_0c0429c8;
P_0c0429c8: /* original 8935, guest PC 0x0c0429c8 */
if(!s->budget--) { s->failed_pc=0x0c0429c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ca;
P_0c0429ca: /* original 3572, guest PC 0x0c0429ca */
if(!s->budget--) { s->failed_pc=0x0c0429cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[7])!=0);
goto P_0c0429cc;
P_0c0429cc: /* original 8933, guest PC 0x0c0429cc */
if(!s->budget--) { s->failed_pc=0x0c0429ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a36; }
goto P_0c0429ce;
P_0c0429ce: /* original 6343, guest PC 0x0c0429ce */
if(!s->budget--) { s->failed_pc=0x0c0429ceu; return 0; }
r[3]=r[4];
goto P_0c0429d0;
P_0c0429d0: /* original e701, guest PC 0x0c0429d0 */
if(!s->budget--) { s->failed_pc=0x0c0429d0u; return 0; }
r[7]=0x00000001u;
goto P_0c0429d2;
P_0c0429d2: /* original 2378, guest PC 0x0c0429d2 */
if(!s->budget--) { s->failed_pc=0x0c0429d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429d4;
P_0c0429d4: /* original 8d03, guest PC 0x0c0429d4 */
if(!s->budget--) { s->failed_pc=0x0c0429d4u; return 0; }
cond=r[17]&1u;
r[10]=0x00000003u;
if(cond) { goto P_0c0429de; }
goto P_0c0429d8;
P_0c0429d6: /* original ea03, guest PC 0x0c0429d6 */
if(!s->budget--) { s->failed_pc=0x0c0429d6u; return 0; }
r[10]=0x00000003u;
goto P_0c0429d8;
P_0c0429d8: /* original 4608, guest PC 0x0c0429d8 */
if(!s->budget--) { s->failed_pc=0x0c0429d8u; return 0; }
r[6]<<=2;
goto P_0c0429da;
P_0c0429da: /* original 4608, guest PC 0x0c0429da */
if(!s->budget--) { s->failed_pc=0x0c0429dau; return 0; }
r[6]<<=2;
goto P_0c0429dc;
P_0c0429dc: /* original ea30, guest PC 0x0c0429dc */
if(!s->budget--) { s->failed_pc=0x0c0429dcu; return 0; }
r[10]=0x00000030u;
goto P_0c0429de;
P_0c0429de: /* original 6353, guest PC 0x0c0429de */
if(!s->budget--) { s->failed_pc=0x0c0429deu; return 0; }
r[3]=r[5];
goto P_0c0429e0;
P_0c0429e0: /* original 2378, guest PC 0x0c0429e0 */
if(!s->budget--) { s->failed_pc=0x0c0429e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0429e2;
P_0c0429e2: /* original 8901, guest PC 0x0c0429e2 */
if(!s->budget--) { s->failed_pc=0x0c0429e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0429e8; }
goto P_0c0429e4;
P_0c0429e4: /* original 4608, guest PC 0x0c0429e4 */
if(!s->budget--) { s->failed_pc=0x0c0429e4u; return 0; }
r[6]<<=2;
goto P_0c0429e6;
P_0c0429e6: /* original 4a08, guest PC 0x0c0429e6 */
if(!s->budget--) { s->failed_pc=0x0c0429e6u; return 0; }
r[10]<<=2;
goto P_0c0429e8;
P_0c0429e8: /* original 934b, guest PC 0x0c0429e8 */
if(!s->budget--) { s->failed_pc=0x0c0429e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a82u,2);
goto P_0c0429ea;
P_0c0429ea: /* original 6e73, guest PC 0x0c0429ea */
if(!s->budget--) { s->failed_pc=0x0c0429eau; return 0; }
r[14]=r[7];
goto P_0c0429ec;
P_0c0429ec: /* original 914a, guest PC 0x0c0429ec */
if(!s->budget--) { s->failed_pc=0x0c0429ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429ee;
P_0c0429ee: /* original eb00, guest PC 0x0c0429ee */
if(!s->budget--) { s->failed_pc=0x0c0429eeu; return 0; }
r[11]=0x00000000u;
goto P_0c0429f0;
P_0c0429f0: /* original 9048, guest PC 0x0c0429f0 */
if(!s->budget--) { s->failed_pc=0x0c0429f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a84u,2);
goto P_0c0429f2;
P_0c0429f2: /* original 33a8, guest PC 0x0c0429f2 */
if(!s->budget--) { s->failed_pc=0x0c0429f2u; return 0; }
r[3]-=r[10];
goto P_0c0429f4;
P_0c0429f4: /* original 6a33, guest PC 0x0c0429f4 */
if(!s->budget--) { s->failed_pc=0x0c0429f4u; return 0; }
r[10]=r[3];
goto P_0c0429f6;
P_0c0429f6: /* original 4401, guest PC 0x0c0429f6 */
if(!s->budget--) { s->failed_pc=0x0c0429f6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0429f8;
P_0c0429f8: /* original 4501, guest PC 0x0c0429f8 */
if(!s->budget--) { s->failed_pc=0x0c0429f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0429fa;
P_0c0429fa: /* original 2008, guest PC 0x0c0429fa */
if(!s->budget--) { s->failed_pc=0x0c0429fau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0429fc;
P_0c0429fc: /* original 8906, guest PC 0x0c0429fc */
if(!s->budget--) { s->failed_pc=0x0c0429fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a0c; }
goto P_0c0429fe;
P_0c0429fe: /* original 6353, guest PC 0x0c0429fe */
if(!s->budget--) { s->failed_pc=0x0c0429feu; return 0; }
r[3]=r[5];
goto P_0c042a00;
P_0c042a00: /* original 2378, guest PC 0x0c042a00 */
if(!s->budget--) { s->failed_pc=0x0c042a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c042a02;
P_0c042a02: /* original 8900, guest PC 0x0c042a02 */
if(!s->budget--) { s->failed_pc=0x0c042a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a06; }
goto P_0c042a04;
P_0c042a04: /* original 2beb, guest PC 0x0c042a04 */
if(!s->budget--) { s->failed_pc=0x0c042a04u; return 0; }
r[11]|=r[14];
goto P_0c042a06;
P_0c042a06: /* original 4e00, guest PC 0x0c042a06 */
if(!s->budget--) { s->failed_pc=0x0c042a06u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a08;
P_0c042a08: /* original 4501, guest PC 0x0c042a08 */
if(!s->budget--) { s->failed_pc=0x0c042a08u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c042a0a;
P_0c042a0a: /* original 4021, guest PC 0x0c042a0a */
if(!s->budget--) { s->failed_pc=0x0c042a0au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c042a0c;
P_0c042a0c: /* original 2118, guest PC 0x0c042a0c */
if(!s->budget--) { s->failed_pc=0x0c042a0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c042a0e;
P_0c042a0e: /* original 8906, guest PC 0x0c042a0e */
if(!s->budget--) { s->failed_pc=0x0c042a0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a1e; }
goto P_0c042a10;
P_0c042a10: /* original 6243, guest PC 0x0c042a10 */
if(!s->budget--) { s->failed_pc=0x0c042a10u; return 0; }
r[2]=r[4];
goto P_0c042a12;
P_0c042a12: /* original 2278, guest PC 0x0c042a12 */
if(!s->budget--) { s->failed_pc=0x0c042a12u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c042a14;
P_0c042a14: /* original 8900, guest PC 0x0c042a14 */
if(!s->budget--) { s->failed_pc=0x0c042a14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a18; }
goto P_0c042a16;
P_0c042a16: /* original 2beb, guest PC 0x0c042a16 */
if(!s->budget--) { s->failed_pc=0x0c042a16u; return 0; }
r[11]|=r[14];
goto P_0c042a18;
P_0c042a18: /* original 4e00, guest PC 0x0c042a18 */
if(!s->budget--) { s->failed_pc=0x0c042a18u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c042a1a;
P_0c042a1a: /* original 4401, guest PC 0x0c042a1a */
if(!s->budget--) { s->failed_pc=0x0c042a1au; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c042a1c;
P_0c042a1c: /* original 4121, guest PC 0x0c042a1c */
if(!s->budget--) { s->failed_pc=0x0c042a1cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]=(uint32_t)((int32_t)r[1]>>1);
goto P_0c042a1e;
P_0c042a1e: /* original 6213, guest PC 0x0c042a1e */
if(!s->budget--) { s->failed_pc=0x0c042a1eu; return 0; }
r[2]=r[1];
goto P_0c042a20;
P_0c042a20: /* original 220b, guest PC 0x0c042a20 */
if(!s->budget--) { s->failed_pc=0x0c042a20u; return 0; }
r[2]|=r[0];
goto P_0c042a22;
P_0c042a22: /* original 2228, guest PC 0x0c042a22 */
if(!s->budget--) { s->failed_pc=0x0c042a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042a24;
P_0c042a24: /* original 8be9, guest PC 0x0c042a24 */
if(!s->budget--) { s->failed_pc=0x0c042a24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0429fa; }
goto P_0c042a26;
P_0c042a26: /* original 932e, guest PC 0x0c042a26 */
if(!s->budget--) { s->failed_pc=0x0c042a26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a86u,2);
goto P_0c042a28;
P_0c042a28: /* original 64b3, guest PC 0x0c042a28 */
if(!s->budget--) { s->failed_pc=0x0c042a28u; return 0; }
r[4]=r[11];
goto P_0c042a2a;
P_0c042a2a: /* original 349c, guest PC 0x0c042a2a */
if(!s->budget--) { s->failed_pc=0x0c042a2au; return 0; }
r[4]+=r[9];
goto P_0c042a2c;
P_0c042a2c: /* original 343c, guest PC 0x0c042a2c */
if(!s->budget--) { s->failed_pc=0x0c042a2cu; return 0; }
r[4]+=r[3];
goto P_0c042a2e;
P_0c042a2e: /* original 6240, guest PC 0x0c042a2e */
if(!s->budget--) { s->failed_pc=0x0c042a2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c042a30;
P_0c042a30: /* original 2a29, guest PC 0x0c042a30 */
if(!s->budget--) { s->failed_pc=0x0c042a30u; return 0; }
r[10]&=r[2];
goto P_0c042a32;
P_0c042a32: /* original 2a6b, guest PC 0x0c042a32 */
if(!s->budget--) { s->failed_pc=0x0c042a32u; return 0; }
r[10]|=r[6];
goto P_0c042a34;
P_0c042a34: /* original 24a0, guest PC 0x0c042a34 */
if(!s->budget--) { s->failed_pc=0x0c042a34u; return 0; }
write(ram,r[4],r[10],1);
goto P_0c042a36;
P_0c042a36: /* original 69f6, guest PC 0x0c042a36 */
if(!s->budget--) { s->failed_pc=0x0c042a36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042a38;
P_0c042a38: /* original 6af6, guest PC 0x0c042a38 */
if(!s->budget--) { s->failed_pc=0x0c042a38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042a3a;
P_0c042a3a: /* original 6bf6, guest PC 0x0c042a3a */
if(!s->budget--) { s->failed_pc=0x0c042a3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c042a3c;
P_0c042a3c: /* original 000b, guest PC 0x0c042a3c */
if(!s->budget--) { s->failed_pc=0x0c042a3cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042a3e: /* original 6ef6, guest PC 0x0c042a3e */
if(!s->budget--) { s->failed_pc=0x0c042a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c042a40u,s,ram);
P_0c042ae0: /* original e620, guest PC 0x0c042ae0 */
if(!s->budget--) { s->failed_pc=0x0c042ae0u; return 0; }
r[6]=0x00000020u;
goto P_0c042ae2;
P_0c042ae2: /* original 3467, guest PC 0x0c042ae2 */
if(!s->budget--) { s->failed_pc=0x0c042ae2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c042ae4;
P_0c042ae4: /* original 8b27, guest PC 0x0c042ae4 */
if(!s->budget--) { s->failed_pc=0x0c042ae4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b36; }
goto P_0c042ae6;
P_0c042ae6: /* original 6043, guest PC 0x0c042ae6 */
if(!s->budget--) { s->failed_pc=0x0c042ae6u; return 0; }
r[0]=r[4];
goto P_0c042ae8;
P_0c042ae8: /* original 0009, guest PC 0x0c042ae8 */
if(!s->budget--) { s->failed_pc=0x0c042ae8u; return 0; }
goto P_0c042aea;
P_0c042aea: /* original 887f, guest PC 0x0c042aea */
if(!s->budget--) { s->failed_pc=0x0c042aeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007fu)!=0);
goto P_0c042aec;
P_0c042aec: /* original 8923, guest PC 0x0c042aec */
if(!s->budget--) { s->failed_pc=0x0c042aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b36; }
goto P_0c042aee;
P_0c042aee: /* original d52d, guest PC 0x0c042aee */
if(!s->budget--) { s->failed_pc=0x0c042aeeu; return 0; }
r[5]=read(ram,0x0c042ba4u,4);
goto P_0c042af0;
P_0c042af0: /* original e77f, guest PC 0x0c042af0 */
if(!s->budget--) { s->failed_pc=0x0c042af0u; return 0; }
r[7]=0x0000007fu;
goto P_0c042af2;
P_0c042af2: /* original 3473, guest PC 0x0c042af2 */
if(!s->budget--) { s->failed_pc=0x0c042af2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c042af4;
P_0c042af4: /* original 891c, guest PC 0x0c042af4 */
if(!s->budget--) { s->failed_pc=0x0c042af4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b30; }
goto P_0c042af6;
P_0c042af6: /* original 6350, guest PC 0x0c042af6 */
if(!s->budget--) { s->failed_pc=0x0c042af6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c042af8;
P_0c042af8: /* original 2338, guest PC 0x0c042af8 */
if(!s->budget--) { s->failed_pc=0x0c042af8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c042afa;
P_0c042afa: /* original 890c, guest PC 0x0c042afa */
if(!s->budget--) { s->failed_pc=0x0c042afau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b16; }
goto P_0c042afc;
P_0c042afc: /* original 6043, guest PC 0x0c042afc */
if(!s->budget--) { s->failed_pc=0x0c042afcu; return 0; }
r[0]=r[4];
goto P_0c042afe;
P_0c042afe: /* original 0009, guest PC 0x0c042afe */
if(!s->budget--) { s->failed_pc=0x0c042afeu; return 0; }
goto P_0c042b00;
P_0c042b00: /* original 885c, guest PC 0x0c042b00 */
if(!s->budget--) { s->failed_pc=0x0c042b00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005cu)!=0);
goto P_0c042b02;
P_0c042b02: /* original 8b05, guest PC 0x0c042b02 */
if(!s->budget--) { s->failed_pc=0x0c042b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b10; }
goto P_0c042b04;
P_0c042b04: /* original a007, guest PC 0x0c042b04 */
if(!s->budget--) { s->failed_pc=0x0c042b04u; return 0; }
r[4]=r[7];
goto P_0c042b16;
P_0c042b06: /* original 6473, guest PC 0x0c042b06 */
if(!s->budget--) { s->failed_pc=0x0c042b06u; return 0; }
r[4]=r[7];
return vf3_matrix_family(0x0c042b08u,s,ram);
P_0c042b10: /* original 887e, guest PC 0x0c042b10 */
if(!s->budget--) { s->failed_pc=0x0c042b10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007eu)!=0);
goto P_0c042b12;
P_0c042b12: /* original 8b00, guest PC 0x0c042b12 */
if(!s->budget--) { s->failed_pc=0x0c042b12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b16; }
goto P_0c042b14;
P_0c042b14: /* original 6463, guest PC 0x0c042b14 */
if(!s->budget--) { s->failed_pc=0x0c042b14u; return 0; }
r[4]=r[6];
goto P_0c042b16;
P_0c042b16: /* original 6043, guest PC 0x0c042b16 */
if(!s->budget--) { s->failed_pc=0x0c042b16u; return 0; }
r[0]=r[4];
goto P_0c042b18;
P_0c042b18: /* original 0009, guest PC 0x0c042b18 */
if(!s->budget--) { s->failed_pc=0x0c042b18u; return 0; }
goto P_0c042b1a;
P_0c042b1a: /* original 70e0, guest PC 0x0c042b1a */
if(!s->budget--) { s->failed_pc=0x0c042b1au; return 0; }
r[0]+=0xffffffe0u;
goto P_0c042b1c;
P_0c042b1c: /* original 6303, guest PC 0x0c042b1c */
if(!s->budget--) { s->failed_pc=0x0c042b1cu; return 0; }
r[3]=r[0];
goto P_0c042b1e;
P_0c042b1e: /* original 4008, guest PC 0x0c042b1e */
if(!s->budget--) { s->failed_pc=0x0c042b1eu; return 0; }
r[0]<<=2;
goto P_0c042b20;
P_0c042b20: /* original 4000, guest PC 0x0c042b20 */
if(!s->budget--) { s->failed_pc=0x0c042b20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b22;
P_0c042b22: /* original 303c, guest PC 0x0c042b22 */
if(!s->budget--) { s->failed_pc=0x0c042b22u; return 0; }
r[0]+=r[3];
goto P_0c042b24;
P_0c042b24: /* original 000b, guest PC 0x0c042b24 */
if(!s->budget--) { s->failed_pc=0x0c042b24u; return 0; }
target=r[16];
r[0]<<=2;
s->pc=target; return ram->oob==0;
P_0c042b26: /* original 4008, guest PC 0x0c042b26 */
if(!s->budget--) { s->failed_pc=0x0c042b26u; return 0; }
r[0]<<=2;
return vf3_matrix_family(0x0c042b28u,s,ram);
P_0c042b30: /* original 922d, guest PC 0x0c042b30 */
if(!s->budget--) { s->failed_pc=0x0c042b30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b8eu,2);
goto P_0c042b32;
P_0c042b32: /* original 3423, guest PC 0x0c042b32 */
if(!s->budget--) { s->failed_pc=0x0c042b32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b34;
P_0c042b34: /* original 8904, guest PC 0x0c042b34 */
if(!s->budget--) { s->failed_pc=0x0c042b34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b40; }
goto P_0c042b36;
P_0c042b36: /* original 902b, guest PC 0x0c042b36 */
if(!s->budget--) { s->failed_pc=0x0c042b36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b90u,2);
goto P_0c042b38;
P_0c042b38: /* original 000b, guest PC 0x0c042b38 */
if(!s->budget--) { s->failed_pc=0x0c042b38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042b3a: /* original 0009, guest PC 0x0c042b3a */
if(!s->budget--) { s->failed_pc=0x0c042b3au; return 0; }
return vf3_matrix_family(0x0c042b3cu,s,ram);
P_0c042b40: /* original 9627, guest PC 0x0c042b40 */
if(!s->budget--) { s->failed_pc=0x0c042b40u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b92u,2);
goto P_0c042b42;
P_0c042b42: /* original 3463, guest PC 0x0c042b42 */
if(!s->budget--) { s->failed_pc=0x0c042b42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c042b44;
P_0c042b44: /* original 8914, guest PC 0x0c042b44 */
if(!s->budget--) { s->failed_pc=0x0c042b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b70; }
goto P_0c042b46;
P_0c042b46: /* original 9625, guest PC 0x0c042b46 */
if(!s->budget--) { s->failed_pc=0x0c042b46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b94u,2);
goto P_0c042b48;
P_0c042b48: /* original 6250, guest PC 0x0c042b48 */
if(!s->budget--) { s->failed_pc=0x0c042b48u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c042b4a;
P_0c042b4a: /* original 364c, guest PC 0x0c042b4a */
if(!s->budget--) { s->failed_pc=0x0c042b4au; return 0; }
r[6]+=r[4];
goto P_0c042b4c;
P_0c042b4c: /* original 6363, guest PC 0x0c042b4c */
if(!s->budget--) { s->failed_pc=0x0c042b4cu; return 0; }
r[3]=r[6];
goto P_0c042b4e;
P_0c042b4e: /* original 4608, guest PC 0x0c042b4e */
if(!s->budget--) { s->failed_pc=0x0c042b4eu; return 0; }
r[6]<<=2;
goto P_0c042b50;
P_0c042b50: /* original 4600, guest PC 0x0c042b50 */
if(!s->budget--) { s->failed_pc=0x0c042b50u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c042b52;
P_0c042b52: /* original 2228, guest PC 0x0c042b52 */
if(!s->budget--) { s->failed_pc=0x0c042b52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042b54;
P_0c042b54: /* original 363c, guest PC 0x0c042b54 */
if(!s->budget--) { s->failed_pc=0x0c042b54u; return 0; }
r[6]+=r[3];
goto P_0c042b56;
P_0c042b56: /* original 8d03, guest PC 0x0c042b56 */
if(!s->budget--) { s->failed_pc=0x0c042b56u; return 0; }
cond=r[17]&1u;
r[6]<<=2;
if(cond) { goto P_0c042b60; }
goto P_0c042b5a;
P_0c042b58: /* original 4608, guest PC 0x0c042b58 */
if(!s->budget--) { s->failed_pc=0x0c042b58u; return 0; }
r[6]<<=2;
goto P_0c042b5a;
P_0c042b5a: /* original 901c, guest PC 0x0c042b5a */
if(!s->budget--) { s->failed_pc=0x0c042b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b96u,2);
goto P_0c042b5c;
P_0c042b5c: /* original a001, guest PC 0x0c042b5c */
if(!s->budget--) { s->failed_pc=0x0c042b5cu; return 0; }
goto P_0c042b62;
P_0c042b5e: /* original 0009, guest PC 0x0c042b5e */
if(!s->budget--) { s->failed_pc=0x0c042b5eu; return 0; }
goto P_0c042b60;
P_0c042b60: /* original 9016, guest PC 0x0c042b60 */
if(!s->budget--) { s->failed_pc=0x0c042b60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b90u,2);
goto P_0c042b62;
P_0c042b62: /* original 000b, guest PC 0x0c042b62 */
if(!s->budget--) { s->failed_pc=0x0c042b62u; return 0; }
target=r[16];
r[0]+=r[6];
s->pc=target; return ram->oob==0;
P_0c042b64: /* original 306c, guest PC 0x0c042b64 */
if(!s->budget--) { s->failed_pc=0x0c042b64u; return 0; }
r[0]+=r[6];
return vf3_matrix_family(0x0c042b66u,s,ram);
P_0c042b70: /* original 9212, guest PC 0x0c042b70 */
if(!s->budget--) { s->failed_pc=0x0c042b70u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b98u,2);
goto P_0c042b72;
P_0c042b72: /* original 3468, guest PC 0x0c042b72 */
if(!s->budget--) { s->failed_pc=0x0c042b72u; return 0; }
r[4]-=r[6];
goto P_0c042b74;
P_0c042b74: /* original 3423, guest PC 0x0c042b74 */
if(!s->budget--) { s->failed_pc=0x0c042b74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b76;
P_0c042b76: /* original 891b, guest PC 0x0c042b76 */
if(!s->budget--) { s->failed_pc=0x0c042b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042bb0; }
goto P_0c042b78;
P_0c042b78: /* original 6043, guest PC 0x0c042b78 */
if(!s->budget--) { s->failed_pc=0x0c042b78u; return 0; }
r[0]=r[4];
goto P_0c042b7a;
P_0c042b7a: /* original 0009, guest PC 0x0c042b7a */
if(!s->budget--) { s->failed_pc=0x0c042b7au; return 0; }
goto P_0c042b7c;
P_0c042b7c: /* original 4008, guest PC 0x0c042b7c */
if(!s->budget--) { s->failed_pc=0x0c042b7cu; return 0; }
r[0]<<=2;
goto P_0c042b7e;
P_0c042b7e: /* original 6343, guest PC 0x0c042b7e */
if(!s->budget--) { s->failed_pc=0x0c042b7eu; return 0; }
r[3]=r[4];
goto P_0c042b80;
P_0c042b80: /* original 4000, guest PC 0x0c042b80 */
if(!s->budget--) { s->failed_pc=0x0c042b80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b82;
P_0c042b82: /* original 910a, guest PC 0x0c042b82 */
if(!s->budget--) { s->failed_pc=0x0c042b82u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b9au,2);
goto P_0c042b84;
P_0c042b84: /* original 303c, guest PC 0x0c042b84 */
if(!s->budget--) { s->failed_pc=0x0c042b84u; return 0; }
r[0]+=r[3];
goto P_0c042b86;
P_0c042b86: /* original 4008, guest PC 0x0c042b86 */
if(!s->budget--) { s->failed_pc=0x0c042b86u; return 0; }
r[0]<<=2;
goto P_0c042b88;
P_0c042b88: /* original 4000, guest PC 0x0c042b88 */
if(!s->budget--) { s->failed_pc=0x0c042b88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b8a;
P_0c042b8a: /* original 000b, guest PC 0x0c042b8a */
if(!s->budget--) { s->failed_pc=0x0c042b8au; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042b8c: /* original 301c, guest PC 0x0c042b8c */
if(!s->budget--) { s->failed_pc=0x0c042b8cu; return 0; }
r[0]+=r[1];
return vf3_matrix_family(0x0c042b8eu,s,ram);
P_0c042bb0: /* original 9329, guest PC 0x0c042bb0 */
if(!s->budget--) { s->failed_pc=0x0c042bb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c06u,2);
goto P_0c042bb2;
P_0c042bb2: /* original 3433, guest PC 0x0c042bb2 */
if(!s->budget--) { s->failed_pc=0x0c042bb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bb4;
P_0c042bb4: /* original 8b24, guest PC 0x0c042bb4 */
if(!s->budget--) { s->failed_pc=0x0c042bb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042c00; }
goto P_0c042bb6;
P_0c042bb6: /* original 9327, guest PC 0x0c042bb6 */
if(!s->budget--) { s->failed_pc=0x0c042bb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c08u,2);
goto P_0c042bb8;
P_0c042bb8: /* original 3433, guest PC 0x0c042bb8 */
if(!s->budget--) { s->failed_pc=0x0c042bb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bba;
P_0c042bba: /* original 8911, guest PC 0x0c042bba */
if(!s->budget--) { s->failed_pc=0x0c042bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042be0; }
goto P_0c042bbc;
P_0c042bbc: /* original 9025, guest PC 0x0c042bbc */
if(!s->budget--) { s->failed_pc=0x0c042bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0au,2);
goto P_0c042bbe;
P_0c042bbe: /* original d115, guest PC 0x0c042bbe */
if(!s->budget--) { s->failed_pc=0x0c042bbeu; return 0; }
r[1]=read(ram,0x0c042c14u,4);
goto P_0c042bc0;
P_0c042bc0: /* original 304c, guest PC 0x0c042bc0 */
if(!s->budget--) { s->failed_pc=0x0c042bc0u; return 0; }
r[0]+=r[4];
goto P_0c042bc2;
P_0c042bc2: /* original 6203, guest PC 0x0c042bc2 */
if(!s->budget--) { s->failed_pc=0x0c042bc2u; return 0; }
r[2]=r[0];
goto P_0c042bc4;
P_0c042bc4: /* original 4008, guest PC 0x0c042bc4 */
if(!s->budget--) { s->failed_pc=0x0c042bc4u; return 0; }
r[0]<<=2;
goto P_0c042bc6;
P_0c042bc6: /* original 4000, guest PC 0x0c042bc6 */
if(!s->budget--) { s->failed_pc=0x0c042bc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bc8;
P_0c042bc8: /* original 302c, guest PC 0x0c042bc8 */
if(!s->budget--) { s->failed_pc=0x0c042bc8u; return 0; }
r[0]+=r[2];
goto P_0c042bca;
P_0c042bca: /* original 4008, guest PC 0x0c042bca */
if(!s->budget--) { s->failed_pc=0x0c042bcau; return 0; }
r[0]<<=2;
goto P_0c042bcc;
P_0c042bcc: /* original 4000, guest PC 0x0c042bcc */
if(!s->budget--) { s->failed_pc=0x0c042bccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bce;
P_0c042bce: /* original 000b, guest PC 0x0c042bce */
if(!s->budget--) { s->failed_pc=0x0c042bceu; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bd0: /* original 301c, guest PC 0x0c042bd0 */
if(!s->budget--) { s->failed_pc=0x0c042bd0u; return 0; }
r[0]+=r[1];
return vf3_matrix_family(0x0c042bd2u,s,ram);
P_0c042be0: /* original 9314, guest PC 0x0c042be0 */
if(!s->budget--) { s->failed_pc=0x0c042be0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0cu,2);
goto P_0c042be2;
P_0c042be2: /* original 3433, guest PC 0x0c042be2 */
if(!s->budget--) { s->failed_pc=0x0c042be2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042be4;
P_0c042be4: /* original 890c, guest PC 0x0c042be4 */
if(!s->budget--) { s->failed_pc=0x0c042be4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042c00; }
goto P_0c042be6;
P_0c042be6: /* original 9012, guest PC 0x0c042be6 */
if(!s->budget--) { s->failed_pc=0x0c042be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0eu,2);
goto P_0c042be8;
P_0c042be8: /* original d10b, guest PC 0x0c042be8 */
if(!s->budget--) { s->failed_pc=0x0c042be8u; return 0; }
r[1]=read(ram,0x0c042c18u,4);
goto P_0c042bea;
P_0c042bea: /* original 304c, guest PC 0x0c042bea */
if(!s->budget--) { s->failed_pc=0x0c042beau; return 0; }
r[0]+=r[4];
goto P_0c042bec;
P_0c042bec: /* original 6203, guest PC 0x0c042bec */
if(!s->budget--) { s->failed_pc=0x0c042becu; return 0; }
r[2]=r[0];
goto P_0c042bee;
P_0c042bee: /* original 4008, guest PC 0x0c042bee */
if(!s->budget--) { s->failed_pc=0x0c042beeu; return 0; }
r[0]<<=2;
goto P_0c042bf0;
P_0c042bf0: /* original 4000, guest PC 0x0c042bf0 */
if(!s->budget--) { s->failed_pc=0x0c042bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf2;
P_0c042bf2: /* original 302c, guest PC 0x0c042bf2 */
if(!s->budget--) { s->failed_pc=0x0c042bf2u; return 0; }
r[0]+=r[2];
goto P_0c042bf4;
P_0c042bf4: /* original 4008, guest PC 0x0c042bf4 */
if(!s->budget--) { s->failed_pc=0x0c042bf4u; return 0; }
r[0]<<=2;
goto P_0c042bf6;
P_0c042bf6: /* original 4000, guest PC 0x0c042bf6 */
if(!s->budget--) { s->failed_pc=0x0c042bf6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf8;
P_0c042bf8: /* original 000b, guest PC 0x0c042bf8 */
if(!s->budget--) { s->failed_pc=0x0c042bf8u; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bfa: /* original 301c, guest PC 0x0c042bfa */
if(!s->budget--) { s->failed_pc=0x0c042bfau; return 0; }
r[0]+=r[1];
return vf3_matrix_family(0x0c042bfcu,s,ram);
P_0c042c00: /* original 9006, guest PC 0x0c042c00 */
if(!s->budget--) { s->failed_pc=0x0c042c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c10u,2);
goto P_0c042c02;
P_0c042c02: /* original 000b, guest PC 0x0c042c02 */
if(!s->budget--) { s->failed_pc=0x0c042c02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042c04: /* original 0009, guest PC 0x0c042c04 */
if(!s->budget--) { s->failed_pc=0x0c042c04u; return 0; }
return vf3_matrix_family(0x0c042c06u,s,ram);
P_0c0475aa: /* original 000b, guest PC 0x0c0475aa */
if(!s->budget--) { s->failed_pc=0x0c0475aau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0475ac: /* original 0483, guest PC 0x0c0475ac */
if(!s->budget--) { s->failed_pc=0x0c0475acu; return 0; }
return vf3_matrix_family(0x0c0475aeu,s,ram);
P_0c07fca4: /* original 4f22, guest PC 0x0c07fca4 */
if(!s->budget--) { s->failed_pc=0x0c07fca4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07fca6;
P_0c07fca6: /* original 7ff8, guest PC 0x0c07fca6 */
if(!s->budget--) { s->failed_pc=0x0c07fca6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07fca8;
P_0c07fca8: /* original 2f42, guest PC 0x0c07fca8 */
if(!s->budget--) { s->failed_pc=0x0c07fca8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07fcaa;
P_0c07fcaa: /* original 1f51, guest PC 0x0c07fcaa */
if(!s->budget--) { s->failed_pc=0x0c07fcaau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07fcac;
P_0c07fcac: /* original d444, guest PC 0x0c07fcac */
if(!s->budget--) { s->failed_pc=0x0c07fcacu; return 0; }
r[4]=read(ram,0x0c07fdc0u,4);
goto P_0c07fcae;
P_0c07fcae: /* original d345, guest PC 0x0c07fcae */
if(!s->budget--) { s->failed_pc=0x0c07fcaeu; return 0; }
r[3]=read(ram,0x0c07fdc4u,4);
goto P_0c07fcb0;
P_0c07fcb0: /* original 5241, guest PC 0x0c07fcb0 */
if(!s->budget--) { s->failed_pc=0x0c07fcb0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c07fcb2;
P_0c07fcb2: /* original 2238, guest PC 0x0c07fcb2 */
if(!s->budget--) { s->failed_pc=0x0c07fcb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07fcb4;
P_0c07fcb4: /* original 8903, guest PC 0x0c07fcb4 */
if(!s->budget--) { s->failed_pc=0x0c07fcb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07fcbe; }
goto P_0c07fcb6;
P_0c07fcb6: /* original d245, guest PC 0x0c07fcb6 */
if(!s->budget--) { s->failed_pc=0x0c07fcb6u; return 0; }
r[2]=read(ram,0x0c07fdccu,4);
goto P_0c07fcb8;
P_0c07fcb8: /* original d443, guest PC 0x0c07fcb8 */
if(!s->budget--) { s->failed_pc=0x0c07fcb8u; return 0; }
r[4]=read(ram,0x0c07fdc8u,4);
goto P_0c07fcba;
P_0c07fcba: /* original 420b, guest PC 0x0c07fcba */
if(!s->budget--) { s->failed_pc=0x0c07fcbau; return 0; }
target=r[2];
r[16]=0x0c07fcbeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07fcbeu) { target=s->pc; goto dispatch; }
goto P_0c07fcbe;
P_0c07fcbc: /* original 0009, guest PC 0x0c07fcbc */
if(!s->budget--) { s->failed_pc=0x0c07fcbcu; return 0; }
goto P_0c07fcbe;
P_0c07fcbe: /* original d344, guest PC 0x0c07fcbe */
if(!s->budget--) { s->failed_pc=0x0c07fcbeu; return 0; }
r[3]=read(ram,0x0c07fdd0u,4);
goto P_0c07fcc0;
P_0c07fcc0: /* original 64f2, guest PC 0x0c07fcc0 */
if(!s->budget--) { s->failed_pc=0x0c07fcc0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07fcc2;
P_0c07fcc2: /* original 55f1, guest PC 0x0c07fcc2 */
if(!s->budget--) { s->failed_pc=0x0c07fcc2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07fcc4;
P_0c07fcc4: /* original 7f08, guest PC 0x0c07fcc4 */
if(!s->budget--) { s->failed_pc=0x0c07fcc4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07fcc6;
P_0c07fcc6: /* original 432b, guest PC 0x0c07fcc6 */
if(!s->budget--) { s->failed_pc=0x0c07fcc6u; return 0; }
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
P_0c07fcc8: /* original 4f26, guest PC 0x0c07fcc8 */
if(!s->budget--) { s->failed_pc=0x0c07fcc8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07fccau,s,ram);
P_0c0858f2: /* original 4f22, guest PC 0x0c0858f2 */
if(!s->budget--) { s->failed_pc=0x0c0858f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0858f4;
P_0c0858f4: /* original 00ed, guest PC 0x0c0858f4 */
if(!s->budget--) { s->failed_pc=0x0c0858f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0858f6;
P_0c0858f6: /* original 7fec, guest PC 0x0c0858f6 */
if(!s->budget--) { s->failed_pc=0x0c0858f6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0858f8;
P_0c0858f8: /* original 81f2, guest PC 0x0c0858f8 */
if(!s->budget--) { s->failed_pc=0x0c0858f8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0858fa;
P_0c0858fa: /* original c73b, guest PC 0x0c0858fa */
if(!s->budget--) { s->failed_pc=0x0c0858fau; return 0; }
r[0]=0x0c0859e8u;
goto P_0c0858fc;
P_0c0858fc: /* original f308, guest PC 0x0c0858fc */
if(!s->budget--) { s->failed_pc=0x0c0858fcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0858fe;
P_0c0858fe: /* original e008, guest PC 0x0c0858fe */
if(!s->budget--) { s->failed_pc=0x0c0858feu; return 0; }
r[0]=0x00000008u;
goto P_0c085900;
P_0c085900: /* original ff37, guest PC 0x0c085900 */
if(!s->budget--) { s->failed_pc=0x0c085900u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085902;
P_0c085902: /* original 85f2, guest PC 0x0c085902 */
if(!s->budget--) { s->failed_pc=0x0c085902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c085904;
P_0c085904: /* original dd39, guest PC 0x0c085904 */
if(!s->budget--) { s->failed_pc=0x0c085904u; return 0; }
r[13]=read(ram,0x0c0859ecu,4);
goto P_0c085906;
P_0c085906: /* original 4d0b, guest PC 0x0c085906 */
if(!s->budget--) { s->failed_pc=0x0c085906u; return 0; }
target=r[13];
r[16]=0x0c08590au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08590au) { target=s->pc; goto dispatch; }
goto P_0c08590a;
P_0c085908: /* original 6403, guest PC 0x0c085908 */
if(!s->budget--) { s->failed_pc=0x0c085908u; return 0; }
r[4]=r[0];
goto P_0c08590a;
P_0c08590a: /* original e008, guest PC 0x0c08590a */
if(!s->budget--) { s->failed_pc=0x0c08590au; return 0; }
r[0]=0x00000008u;
goto P_0c08590c;
P_0c08590c: /* original f4f6, guest PC 0x0c08590c */
if(!s->budget--) { s->failed_pc=0x0c08590cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08590e;
P_0c08590e: /* original 9062, guest PC 0x0c08590e */
if(!s->budget--) { s->failed_pc=0x0c08590eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d6u,2);
goto P_0c085910;
P_0c085910: /* original f402, guest PC 0x0c085910 */
if(!s->budget--) { s->failed_pc=0x0c085910u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085912;
P_0c085912: /* original f43d, guest PC 0x0c085912 */
if(!s->budget--) { s->failed_pc=0x0c085912u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c085914;
P_0c085914: /* original 035a, guest PC 0x0c085914 */
if(!s->budget--) { s->failed_pc=0x0c085914u; return 0; }
r[3]=r[53];
goto P_0c085916;
P_0c085916: /* original 0e35, guest PC 0x0c085916 */
if(!s->budget--) { s->failed_pc=0x0c085916u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c085918;
P_0c085918: /* original 70f8, guest PC 0x0c085918 */
if(!s->budget--) { s->failed_pc=0x0c085918u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c08591a;
P_0c08591a: /* original 00ed, guest PC 0x0c08591a */
if(!s->budget--) { s->failed_pc=0x0c08591au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08591c;
P_0c08591c: /* original 81f6, guest PC 0x0c08591c */
if(!s->budget--) { s->failed_pc=0x0c08591cu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c08591e;
P_0c08591e: /* original 905b, guest PC 0x0c08591e */
if(!s->budget--) { s->failed_pc=0x0c08591eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d8u,2);
goto P_0c085920;
P_0c085920: /* original 00ed, guest PC 0x0c085920 */
if(!s->budget--) { s->failed_pc=0x0c085920u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085922;
P_0c085922: /* original 81f2, guest PC 0x0c085922 */
if(!s->budget--) { s->failed_pc=0x0c085922u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c085924;
P_0c085924: /* original c732, guest PC 0x0c085924 */
if(!s->budget--) { s->failed_pc=0x0c085924u; return 0; }
r[0]=0x0c0859f0u;
goto P_0c085926;
P_0c085926: /* original ff08, guest PC 0x0c085926 */
if(!s->budget--) { s->failed_pc=0x0c085926u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085928;
P_0c085928: /* original 85f6, guest PC 0x0c085928 */
if(!s->budget--) { s->failed_pc=0x0c085928u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c08592a;
P_0c08592a: /* original 4d0b, guest PC 0x0c08592a */
if(!s->budget--) { s->failed_pc=0x0c08592au; return 0; }
target=r[13];
r[16]=0x0c08592eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08592eu) { target=s->pc; goto dispatch; }
goto P_0c08592e;
P_0c08592c: /* original 6403, guest PC 0x0c08592c */
if(!s->budget--) { s->failed_pc=0x0c08592cu; return 0; }
r[4]=r[0];
goto P_0c08592e;
P_0c08592e: /* original f3fc, guest PC 0x0c08592e */
if(!s->budget--) { s->failed_pc=0x0c08592eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085930;
P_0c085930: /* original f302, guest PC 0x0c085930 */
if(!s->budget--) { s->failed_pc=0x0c085930u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c085932;
P_0c085932: /* original e010, guest PC 0x0c085932 */
if(!s->budget--) { s->failed_pc=0x0c085932u; return 0; }
r[0]=0x00000010u;
goto P_0c085934;
P_0c085934: /* original ff37, guest PC 0x0c085934 */
if(!s->budget--) { s->failed_pc=0x0c085934u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085936;
P_0c085936: /* original d32f, guest PC 0x0c085936 */
if(!s->budget--) { s->failed_pc=0x0c085936u; return 0; }
r[3]=read(ram,0x0c0859f4u,4);
goto P_0c085938;
P_0c085938: /* original 85f2, guest PC 0x0c085938 */
if(!s->budget--) { s->failed_pc=0x0c085938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08593a;
P_0c08593a: /* original 430b, guest PC 0x0c08593a */
if(!s->budget--) { s->failed_pc=0x0c08593au; return 0; }
target=r[3];
r[16]=0x0c08593eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08593eu) { target=s->pc; goto dispatch; }
goto P_0c08593e;
P_0c08593c: /* original 6403, guest PC 0x0c08593c */
if(!s->budget--) { s->failed_pc=0x0c08593cu; return 0; }
r[4]=r[0];
goto P_0c08593e;
P_0c08593e: /* original f4fc, guest PC 0x0c08593e */
if(!s->budget--) { s->failed_pc=0x0c08593eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085940;
P_0c085940: /* original f402, guest PC 0x0c085940 */
if(!s->budget--) { s->failed_pc=0x0c085940u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085942;
P_0c085942: /* original e010, guest PC 0x0c085942 */
if(!s->budget--) { s->failed_pc=0x0c085942u; return 0; }
r[0]=0x00000010u;
goto P_0c085944;
P_0c085944: /* original f34c, guest PC 0x0c085944 */
if(!s->budget--) { s->failed_pc=0x0c085944u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085946;
P_0c085946: /* original f4f6, guest PC 0x0c085946 */
if(!s->budget--) { s->failed_pc=0x0c085946u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c085948;
P_0c085948: /* original f430, guest PC 0x0c085948 */
if(!s->budget--) { s->failed_pc=0x0c085948u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c08594a;
P_0c08594a: /* original f43d, guest PC 0x0c08594a */
if(!s->budget--) { s->failed_pc=0x0c08594au; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c08594c;
P_0c08594c: /* original 035a, guest PC 0x0c08594c */
if(!s->budget--) { s->failed_pc=0x0c08594cu; return 0; }
r[3]=r[53];
goto P_0c08594e;
P_0c08594e: /* original 633f, guest PC 0x0c08594e */
if(!s->budget--) { s->failed_pc=0x0c08594eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c085950;
P_0c085950: /* original 6233, guest PC 0x0c085950 */
if(!s->budget--) { s->failed_pc=0x0c085950u; return 0; }
r[2]=r[3];
goto P_0c085952;
P_0c085952: /* original 2f32, guest PC 0x0c085952 */
if(!s->budget--) { s->failed_pc=0x0c085952u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085954;
P_0c085954: /* original 9041, guest PC 0x0c085954 */
if(!s->budget--) { s->failed_pc=0x0c085954u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dau,2);
goto P_0c085956;
P_0c085956: /* original 0e25, guest PC 0x0c085956 */
if(!s->budget--) { s->failed_pc=0x0c085956u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085958;
P_0c085958: /* original c727, guest PC 0x0c085958 */
if(!s->budget--) { s->failed_pc=0x0c085958u; return 0; }
r[0]=0x0c0859f8u;
goto P_0c08595a;
P_0c08595a: /* original f308, guest PC 0x0c08595a */
if(!s->budget--) { s->failed_pc=0x0c08595au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08595c;
P_0c08595c: /* original 903e, guest PC 0x0c08595c */
if(!s->budget--) { s->failed_pc=0x0c08595cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dcu,2);
goto P_0c08595e;
P_0c08595e: /* original fe37, guest PC 0x0c08595e */
if(!s->budget--) { s->failed_pc=0x0c08595eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085960;
P_0c085960: /* original 903d, guest PC 0x0c085960 */
if(!s->budget--) { s->failed_pc=0x0c085960u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085962;
P_0c085962: /* original 03ed, guest PC 0x0c085962 */
if(!s->budget--) { s->failed_pc=0x0c085962u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085964;
P_0c085964: /* original 2f32, guest PC 0x0c085964 */
if(!s->budget--) { s->failed_pc=0x0c085964u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085966;
P_0c085966: /* original d126, guest PC 0x0c085966 */
if(!s->budget--) { s->failed_pc=0x0c085966u; return 0; }
r[1]=read(ram,0x0c085a00u,4);
goto P_0c085968;
P_0c085968: /* original 903a, guest PC 0x0c085968 */
if(!s->budget--) { s->failed_pc=0x0c085968u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e0u,2);
goto P_0c08596a;
P_0c08596a: /* original 6212, guest PC 0x0c08596a */
if(!s->budget--) { s->failed_pc=0x0c08596au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08596c;
P_0c08596c: /* original d323, guest PC 0x0c08596c */
if(!s->budget--) { s->failed_pc=0x0c08596cu; return 0; }
r[3]=read(ram,0x0c0859fcu,4);
goto P_0c08596e;
P_0c08596e: /* original 04ed, guest PC 0x0c08596e */
if(!s->budget--) { s->failed_pc=0x0c08596eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085970;
P_0c085970: /* original 2238, guest PC 0x0c085970 */
if(!s->budget--) { s->failed_pc=0x0c085970u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085972;
P_0c085972: /* original 8b0f, guest PC 0x0c085972 */
if(!s->budget--) { s->failed_pc=0x0c085972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085994; }
goto P_0c085974;
P_0c085974: /* original 9035, guest PC 0x0c085974 */
if(!s->budget--) { s->failed_pc=0x0c085974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e2u,2);
goto P_0c085976;
P_0c085976: /* original 05ed, guest PC 0x0c085976 */
if(!s->budget--) { s->failed_pc=0x0c085976u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085978;
P_0c085978: /* original 2558, guest PC 0x0c085978 */
if(!s->budget--) { s->failed_pc=0x0c085978u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08597a;
P_0c08597a: /* original 8904, guest PC 0x0c08597a */
if(!s->budget--) { s->failed_pc=0x0c08597au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085986; }
goto P_0c08597c;
P_0c08597c: /* original 65f3, guest PC 0x0c08597c */
if(!s->budget--) { s->failed_pc=0x0c08597cu; return 0; }
r[5]=r[15];
goto P_0c08597e;
P_0c08597e: /* original b103, guest PC 0x0c08597e */
if(!s->budget--) { s->failed_pc=0x0c08597eu; return 0; }
target=0x0c085b88u; r[16]=0x0c085982u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085982u) { target=s->pc; goto dispatch; }
goto P_0c085982;
P_0c085980: /* original 64e3, guest PC 0x0c085980 */
if(!s->budget--) { s->failed_pc=0x0c085980u; return 0; }
r[4]=r[14];
goto P_0c085982;
P_0c085982: /* original a007, guest PC 0x0c085982 */
if(!s->budget--) { s->failed_pc=0x0c085982u; return 0; }
goto P_0c085994;
P_0c085984: /* original 0009, guest PC 0x0c085984 */
if(!s->budget--) { s->failed_pc=0x0c085984u; return 0; }
goto P_0c085986;
P_0c085986: /* original 63f2, guest PC 0x0c085986 */
if(!s->budget--) { s->failed_pc=0x0c085986u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085988;
P_0c085988: /* original 644f, guest PC 0x0c085988 */
if(!s->budget--) { s->failed_pc=0x0c085988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08598a;
P_0c08598a: /* original 334c, guest PC 0x0c08598a */
if(!s->budget--) { s->failed_pc=0x0c08598au; return 0; }
r[3]+=r[4];
goto P_0c08598c;
P_0c08598c: /* original 6233, guest PC 0x0c08598c */
if(!s->budget--) { s->failed_pc=0x0c08598cu; return 0; }
r[2]=r[3];
goto P_0c08598e;
P_0c08598e: /* original 2f32, guest PC 0x0c08598e */
if(!s->budget--) { s->failed_pc=0x0c08598eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085990;
P_0c085990: /* original 9025, guest PC 0x0c085990 */
if(!s->budget--) { s->failed_pc=0x0c085990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085992;
P_0c085992: /* original 0e25, guest PC 0x0c085992 */
if(!s->budget--) { s->failed_pc=0x0c085992u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085994;
P_0c085994: /* original 63f2, guest PC 0x0c085994 */
if(!s->budget--) { s->failed_pc=0x0c085994u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085996;
P_0c085996: /* original 4311, guest PC 0x0c085996 */
if(!s->budget--) { s->failed_pc=0x0c085996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c085998;
P_0c085998: /* original 8b02, guest PC 0x0c085998 */
if(!s->budget--) { s->failed_pc=0x0c085998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859a0; }
goto P_0c08599a;
P_0c08599a: /* original 65f3, guest PC 0x0c08599a */
if(!s->budget--) { s->failed_pc=0x0c08599au; return 0; }
r[5]=r[15];
goto P_0c08599c;
P_0c08599c: /* original b0f4, guest PC 0x0c08599c */
if(!s->budget--) { s->failed_pc=0x0c08599cu; return 0; }
target=0x0c085b88u; r[16]=0x0c0859a0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0859a0u) { target=s->pc; goto dispatch; }
goto P_0c0859a0;
P_0c08599e: /* original 64e3, guest PC 0x0c08599e */
if(!s->budget--) { s->failed_pc=0x0c08599eu; return 0; }
r[4]=r[14];
goto P_0c0859a0;
P_0c0859a0: /* original 64f2, guest PC 0x0c0859a0 */
if(!s->budget--) { s->failed_pc=0x0c0859a0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0859a2;
P_0c0859a2: /* original 4d0b, guest PC 0x0c0859a2 */
if(!s->budget--) { s->failed_pc=0x0c0859a2u; return 0; }
target=r[13];
r[16]=0x0c0859a6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0859a6u) { target=s->pc; goto dispatch; }
goto P_0c0859a6;
P_0c0859a4: /* original 644f, guest PC 0x0c0859a4 */
if(!s->budget--) { s->failed_pc=0x0c0859a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0859a6;
P_0c0859a6: /* original c717, guest PC 0x0c0859a6 */
if(!s->budget--) { s->failed_pc=0x0c0859a6u; return 0; }
r[0]=0x0c085a04u;
goto P_0c0859a8;
P_0c0859a8: /* original f40c, guest PC 0x0c0859a8 */
if(!s->budget--) { s->failed_pc=0x0c0859a8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0859aa;
P_0c0859aa: /* original f308, guest PC 0x0c0859aa */
if(!s->budget--) { s->failed_pc=0x0c0859aau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859ac;
P_0c0859ac: /* original f28d, guest PC 0x0c0859ac */
if(!s->budget--) { s->failed_pc=0x0c0859acu; return 0; }
fr[2]=0;
goto P_0c0859ae;
P_0c0859ae: /* original f432, guest PC 0x0c0859ae */
if(!s->budget--) { s->failed_pc=0x0c0859aeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0859b0;
P_0c0859b0: /* original f245, guest PC 0x0c0859b0 */
if(!s->budget--) { s->failed_pc=0x0c0859b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0859b2;
P_0c0859b2: /* original 8b04, guest PC 0x0c0859b2 */
if(!s->budget--) { s->failed_pc=0x0c0859b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859be; }
goto P_0c0859b4;
P_0c0859b4: /* original f14c, guest PC 0x0c0859b4 */
if(!s->budget--) { s->failed_pc=0x0c0859b4u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0859b6;
P_0c0859b6: /* original f29d, guest PC 0x0c0859b6 */
if(!s->budget--) { s->failed_pc=0x0c0859b6u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0859b8;
P_0c0859b8: /* original f122, guest PC 0x0c0859b8 */
if(!s->budget--) { s->failed_pc=0x0c0859b8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0859ba;
P_0c0859ba: /* original f41c, guest PC 0x0c0859ba */
if(!s->budget--) { s->failed_pc=0x0c0859bau; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c0859bc;
P_0c0859bc: /* original f44d, guest PC 0x0c0859bc */
if(!s->budget--) { s->failed_pc=0x0c0859bcu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0859be;
P_0c0859be: /* original 7f14, guest PC 0x0c0859be */
if(!s->budget--) { s->failed_pc=0x0c0859beu; return 0; }
r[15]+=0x00000014u;
goto P_0c0859c0;
P_0c0859c0: /* original c711, guest PC 0x0c0859c0 */
if(!s->budget--) { s->failed_pc=0x0c0859c0u; return 0; }
r[0]=0x0c085a08u;
goto P_0c0859c2;
P_0c0859c2: /* original 4f26, guest PC 0x0c0859c2 */
if(!s->budget--) { s->failed_pc=0x0c0859c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0859c4;
P_0c0859c4: /* original f308, guest PC 0x0c0859c4 */
if(!s->budget--) { s->failed_pc=0x0c0859c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859c6;
P_0c0859c6: /* original 900d, guest PC 0x0c0859c6 */
if(!s->budget--) { s->failed_pc=0x0c0859c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e4u,2);
goto P_0c0859c8;
P_0c0859c8: /* original f430, guest PC 0x0c0859c8 */
if(!s->budget--) { s->failed_pc=0x0c0859c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0859ca;
P_0c0859ca: /* original fe47, guest PC 0x0c0859ca */
if(!s->budget--) { s->failed_pc=0x0c0859cau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0859cc;
P_0c0859cc: /* original fff9, guest PC 0x0c0859cc */
if(!s->budget--) { s->failed_pc=0x0c0859ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0859ce;
P_0c0859ce: /* original 6df6, guest PC 0x0c0859ce */
if(!s->budget--) { s->failed_pc=0x0c0859ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0859d0;
P_0c0859d0: /* original 000b, guest PC 0x0c0859d0 */
if(!s->budget--) { s->failed_pc=0x0c0859d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0859d2: /* original 6ef6, guest PC 0x0c0859d2 */
if(!s->budget--) { s->failed_pc=0x0c0859d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0859d4u,s,ram);
P_0c08a076: /* original 4f22, guest PC 0x0c08a076 */
if(!s->budget--) { s->failed_pc=0x0c08a076u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a078;
P_0c08a078: /* original 6432, guest PC 0x0c08a078 */
if(!s->budget--) { s->failed_pc=0x0c08a078u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08a07a;
P_0c08a07a: /* original dd5d, guest PC 0x0c08a07a */
if(!s->budget--) { s->failed_pc=0x0c08a07au; return 0; }
r[13]=read(ram,0x0c08a1f0u,4);
goto P_0c08a07c;
P_0c08a07c: /* original 1425, guest PC 0x0c08a07c */
if(!s->budget--) { s->failed_pc=0x0c08a07cu; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c08a07e;
P_0c08a07e: /* original 7fc0, guest PC 0x0c08a07e */
if(!s->budget--) { s->failed_pc=0x0c08a07eu; return 0; }
r[15]+=0xffffffc0u;
goto P_0c08a080;
P_0c08a080: /* original d15d, guest PC 0x0c08a080 */
if(!s->budget--) { s->failed_pc=0x0c08a080u; return 0; }
r[1]=read(ram,0x0c08a1f8u,4);
goto P_0c08a082;
P_0c08a082: /* original 410b, guest PC 0x0c08a082 */
if(!s->budget--) { s->failed_pc=0x0c08a082u; return 0; }
target=r[1];
r[16]=0x0c08a086u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a086u) { target=s->pc; goto dispatch; }
goto P_0c08a086;
P_0c08a084: /* original 6423, guest PC 0x0c08a084 */
if(!s->budget--) { s->failed_pc=0x0c08a084u; return 0; }
r[4]=r[2];
goto P_0c08a086;
P_0c08a086: /* original 90aa, guest PC 0x0c08a086 */
if(!s->budget--) { s->failed_pc=0x0c08a086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1deu,2);
goto P_0c08a088;
P_0c08a088: /* original e302, guest PC 0x0c08a088 */
if(!s->budget--) { s->failed_pc=0x0c08a088u; return 0; }
r[3]=0x00000002u;
goto P_0c08a08a;
P_0c08a08a: /* original 0d34, guest PC 0x0c08a08a */
if(!s->budget--) { s->failed_pc=0x0c08a08au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08a08c;
P_0c08a08c: /* original d25b, guest PC 0x0c08a08c */
if(!s->budget--) { s->failed_pc=0x0c08a08cu; return 0; }
r[2]=read(ram,0x0c08a1fcu,4);
goto P_0c08a08e;
P_0c08a08e: /* original 90a7, guest PC 0x0c08a08e */
if(!s->budget--) { s->failed_pc=0x0c08a08eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e0u,2);
goto P_0c08a090;
P_0c08a090: /* original 6422, guest PC 0x0c08a090 */
if(!s->budget--) { s->failed_pc=0x0c08a090u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a092;
P_0c08a092: /* original 95a8, guest PC 0x0c08a092 */
if(!s->budget--) { s->failed_pc=0x0c08a092u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e6u,2);
goto P_0c08a094;
P_0c08a094: /* original 044e, guest PC 0x0c08a094 */
if(!s->budget--) { s->failed_pc=0x0c08a094u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08a096;
P_0c08a096: /* original 90a5, guest PC 0x0c08a096 */
if(!s->budget--) { s->failed_pc=0x0c08a096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e4u,2);
goto P_0c08a098;
P_0c08a098: /* original 9ea3, guest PC 0x0c08a098 */
if(!s->budget--) { s->failed_pc=0x0c08a098u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e2u,2);
goto P_0c08a09a;
P_0c08a09a: /* original 6c43, guest PC 0x0c08a09a */
if(!s->budget--) { s->failed_pc=0x0c08a09au; return 0; }
r[12]=r[4];
goto P_0c08a09c;
P_0c08a09c: /* original 0bde, guest PC 0x0c08a09c */
if(!s->budget--) { s->failed_pc=0x0c08a09cu; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c08a09e;
P_0c08a09e: /* original d358, guest PC 0x0c08a09e */
if(!s->budget--) { s->failed_pc=0x0c08a09eu; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0a0;
P_0c08a0a0: /* original 3e4c, guest PC 0x0c08a0a0 */
if(!s->budget--) { s->failed_pc=0x0c08a0a0u; return 0; }
r[14]+=r[4];
goto P_0c08a0a2;
P_0c08a0a2: /* original 35bc, guest PC 0x0c08a0a2 */
if(!s->budget--) { s->failed_pc=0x0c08a0a2u; return 0; }
r[5]+=r[11];
goto P_0c08a0a4;
P_0c08a0a4: /* original 430b, guest PC 0x0c08a0a4 */
if(!s->budget--) { s->failed_pc=0x0c08a0a4u; return 0; }
target=r[3];
r[16]=0x0c08a0a8u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a0a8u) { target=s->pc; goto dispatch; }
goto P_0c08a0a8;
P_0c08a0a6: /* original 64f3, guest PC 0x0c08a0a6 */
if(!s->budget--) { s->failed_pc=0x0c08a0a6u; return 0; }
r[4]=r[15];
goto P_0c08a0a8;
P_0c08a0a8: /* original c756, guest PC 0x0c08a0a8 */
if(!s->budget--) { s->failed_pc=0x0c08a0a8u; return 0; }
r[0]=0x0c08a204u;
goto P_0c08a0aa;
P_0c08a0aa: /* original 64e3, guest PC 0x0c08a0aa */
if(!s->budget--) { s->failed_pc=0x0c08a0aau; return 0; }
r[4]=r[14];
goto P_0c08a0ac;
P_0c08a0ac: /* original f408, guest PC 0x0c08a0ac */
if(!s->budget--) { s->failed_pc=0x0c08a0acu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a0ae;
P_0c08a0ae: /* original 65f3, guest PC 0x0c08a0ae */
if(!s->budget--) { s->failed_pc=0x0c08a0aeu; return 0; }
r[5]=r[15];
goto P_0c08a0b0;
P_0c08a0b0: /* original 909a, guest PC 0x0c08a0b0 */
if(!s->budget--) { s->failed_pc=0x0c08a0b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e8u,2);
goto P_0c08a0b2;
P_0c08a0b2: /* original f3b6, guest PC 0x0c08a0b2 */
if(!s->budget--) { s->failed_pc=0x0c08a0b2u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c08a0b4;
P_0c08a0b4: /* original e034, guest PC 0x0c08a0b4 */
if(!s->budget--) { s->failed_pc=0x0c08a0b4u; return 0; }
r[0]=0x00000034u;
goto P_0c08a0b6;
P_0c08a0b6: /* original f340, guest PC 0x0c08a0b6 */
if(!s->budget--) { s->failed_pc=0x0c08a0b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a0b8;
P_0c08a0b8: /* original ff37, guest PC 0x0c08a0b8 */
if(!s->budget--) { s->failed_pc=0x0c08a0b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a0ba;
P_0c08a0ba: /* original e004, guest PC 0x0c08a0ba */
if(!s->budget--) { s->failed_pc=0x0c08a0bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a0bc;
P_0c08a0bc: /* original f49d, guest PC 0x0c08a0bc */
if(!s->budget--) { s->failed_pc=0x0c08a0bcu; return 0; }
fr[4]=0x3f800000u;
goto P_0c08a0be;
P_0c08a0be: /* original ff4a, guest PC 0x0c08a0be */
if(!s->budget--) { s->failed_pc=0x0c08a0beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c08a0c0;
P_0c08a0c0: /* original ff8d, guest PC 0x0c08a0c0 */
if(!s->budget--) { s->failed_pc=0x0c08a0c0u; return 0; }
fr[15]=0;
goto P_0c08a0c2;
P_0c08a0c2: /* original fff7, guest PC 0x0c08a0c2 */
if(!s->budget--) { s->failed_pc=0x0c08a0c2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c4;
P_0c08a0c4: /* original e008, guest PC 0x0c08a0c4 */
if(!s->budget--) { s->failed_pc=0x0c08a0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c08a0c6;
P_0c08a0c6: /* original fff7, guest PC 0x0c08a0c6 */
if(!s->budget--) { s->failed_pc=0x0c08a0c6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c8;
P_0c08a0c8: /* original e010, guest PC 0x0c08a0c8 */
if(!s->budget--) { s->failed_pc=0x0c08a0c8u; return 0; }
r[0]=0x00000010u;
goto P_0c08a0ca;
P_0c08a0ca: /* original fff7, guest PC 0x0c08a0ca */
if(!s->budget--) { s->failed_pc=0x0c08a0cau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0cc;
P_0c08a0cc: /* original e014, guest PC 0x0c08a0cc */
if(!s->budget--) { s->failed_pc=0x0c08a0ccu; return 0; }
r[0]=0x00000014u;
goto P_0c08a0ce;
P_0c08a0ce: /* original ff47, guest PC 0x0c08a0ce */
if(!s->budget--) { s->failed_pc=0x0c08a0ceu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0d0;
P_0c08a0d0: /* original e018, guest PC 0x0c08a0d0 */
if(!s->budget--) { s->failed_pc=0x0c08a0d0u; return 0; }
r[0]=0x00000018u;
goto P_0c08a0d2;
P_0c08a0d2: /* original fff7, guest PC 0x0c08a0d2 */
if(!s->budget--) { s->failed_pc=0x0c08a0d2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d4;
P_0c08a0d4: /* original e020, guest PC 0x0c08a0d4 */
if(!s->budget--) { s->failed_pc=0x0c08a0d4u; return 0; }
r[0]=0x00000020u;
goto P_0c08a0d6;
P_0c08a0d6: /* original fff7, guest PC 0x0c08a0d6 */
if(!s->budget--) { s->failed_pc=0x0c08a0d6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d8;
P_0c08a0d8: /* original e024, guest PC 0x0c08a0d8 */
if(!s->budget--) { s->failed_pc=0x0c08a0d8u; return 0; }
r[0]=0x00000024u;
goto P_0c08a0da;
P_0c08a0da: /* original fff7, guest PC 0x0c08a0da */
if(!s->budget--) { s->failed_pc=0x0c08a0dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0dc;
P_0c08a0dc: /* original e028, guest PC 0x0c08a0dc */
if(!s->budget--) { s->failed_pc=0x0c08a0dcu; return 0; }
r[0]=0x00000028u;
goto P_0c08a0de;
P_0c08a0de: /* original ff47, guest PC 0x0c08a0de */
if(!s->budget--) { s->failed_pc=0x0c08a0deu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0e0;
P_0c08a0e0: /* original d347, guest PC 0x0c08a0e0 */
if(!s->budget--) { s->failed_pc=0x0c08a0e0u; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0e2;
P_0c08a0e2: /* original 430b, guest PC 0x0c08a0e2 */
if(!s->budget--) { s->failed_pc=0x0c08a0e2u; return 0; }
target=r[3];
r[16]=0x0c08a0e6u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a0e6u) { target=s->pc; goto dispatch; }
goto P_0c08a0e6;
P_0c08a0e4: /* original 7410, guest PC 0x0c08a0e4 */
if(!s->budget--) { s->failed_pc=0x0c08a0e4u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a0e6;
P_0c08a0e6: /* original c748, guest PC 0x0c08a0e6 */
if(!s->budget--) { s->failed_pc=0x0c08a0e6u; return 0; }
r[0]=0x0c08a208u;
goto P_0c08a0e8;
P_0c08a0e8: /* original f5d8, guest PC 0x0c08a0e8 */
if(!s->budget--) { s->failed_pc=0x0c08a0e8u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c08a0ea;
P_0c08a0ea: /* original f708, guest PC 0x0c08a0ea */
if(!s->budget--) { s->failed_pc=0x0c08a0eau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a0ec;
P_0c08a0ec: /* original c747, guest PC 0x0c08a0ec */
if(!s->budget--) { s->failed_pc=0x0c08a0ecu; return 0; }
r[0]=0x0c08a20cu;
goto P_0c08a0ee;
P_0c08a0ee: /* original fb08, guest PC 0x0c08a0ee */
if(!s->budget--) { s->failed_pc=0x0c08a0eeu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c08a0f0;
P_0c08a0f0: /* original c747, guest PC 0x0c08a0f0 */
if(!s->budget--) { s->failed_pc=0x0c08a0f0u; return 0; }
r[0]=0x0c08a210u;
goto P_0c08a0f2;
P_0c08a0f2: /* original f808, guest PC 0x0c08a0f2 */
if(!s->budget--) { s->failed_pc=0x0c08a0f2u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a0f4;
P_0c08a0f4: /* original c747, guest PC 0x0c08a0f4 */
if(!s->budget--) { s->failed_pc=0x0c08a0f4u; return 0; }
r[0]=0x0c08a214u;
goto P_0c08a0f6;
P_0c08a0f6: /* original f908, guest PC 0x0c08a0f6 */
if(!s->budget--) { s->failed_pc=0x0c08a0f6u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a0f8;
P_0c08a0f8: /* original e300, guest PC 0x0c08a0f8 */
if(!s->budget--) { s->failed_pc=0x0c08a0f8u; return 0; }
r[3]=0x00000000u;
goto P_0c08a0fa;
P_0c08a0fa: /* original 9076, guest PC 0x0c08a0fa */
if(!s->budget--) { s->failed_pc=0x0c08a0fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1eau,2);
goto P_0c08a0fc;
P_0c08a0fc: /* original fa8c, guest PC 0x0c08a0fc */
if(!s->budget--) { s->failed_pc=0x0c08a0fcu; return 0; }
vf3_matrix_move(s,10,8);
goto P_0c08a0fe;
P_0c08a0fe: /* original f4fc, guest PC 0x0c08a0fe */
if(!s->budget--) { s->failed_pc=0x0c08a0feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08a100;
P_0c08a100: /* original f54d, guest PC 0x0c08a100 */
if(!s->budget--) { s->failed_pc=0x0c08a100u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08a102;
P_0c08a102: /* original f67c, guest PC 0x0c08a102 */
if(!s->budget--) { s->failed_pc=0x0c08a102u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08a104;
P_0c08a104: /* original 0e35, guest PC 0x0c08a104 */
if(!s->budget--) { s->failed_pc=0x0c08a104u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08a106;
P_0c08a106: /* original e004, guest PC 0x0c08a106 */
if(!s->budget--) { s->failed_pc=0x0c08a106u; return 0; }
r[0]=0x00000004u;
goto P_0c08a108;
P_0c08a108: /* original feba, guest PC 0x0c08a108 */
if(!s->budget--) { s->failed_pc=0x0c08a108u; return 0; }
vf3_matrix_store(s,ram,11,r[14]);
goto P_0c08a10a;
P_0c08a10a: /* original fea7, guest PC 0x0c08a10a */
if(!s->budget--) { s->failed_pc=0x0c08a10au; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a10c;
P_0c08a10c: /* original e008, guest PC 0x0c08a10c */
if(!s->budget--) { s->failed_pc=0x0c08a10cu; return 0; }
r[0]=0x00000008u;
goto P_0c08a10e;
P_0c08a10e: /* original fe97, guest PC 0x0c08a10e */
if(!s->budget--) { s->failed_pc=0x0c08a10eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c08a110;
P_0c08a110: /* original e00c, guest PC 0x0c08a110 */
if(!s->budget--) { s->failed_pc=0x0c08a110u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a112;
P_0c08a112: /* original fea7, guest PC 0x0c08a112 */
if(!s->budget--) { s->failed_pc=0x0c08a112u; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a114;
P_0c08a114: /* original e068, guest PC 0x0c08a114 */
if(!s->budget--) { s->failed_pc=0x0c08a114u; return 0; }
r[0]=0x00000068u;
goto P_0c08a116;
P_0c08a116: /* original fe47, guest PC 0x0c08a116 */
if(!s->budget--) { s->failed_pc=0x0c08a116u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a118;
P_0c08a118: /* original e06c, guest PC 0x0c08a118 */
if(!s->budget--) { s->failed_pc=0x0c08a118u; return 0; }
r[0]=0x0000006cu;
goto P_0c08a11a;
P_0c08a11a: /* original fe57, guest PC 0x0c08a11a */
if(!s->budget--) { s->failed_pc=0x0c08a11au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a11c;
P_0c08a11c: /* original e070, guest PC 0x0c08a11c */
if(!s->budget--) { s->failed_pc=0x0c08a11cu; return 0; }
r[0]=0x00000070u;
goto P_0c08a11e;
P_0c08a11e: /* original fe47, guest PC 0x0c08a11e */
if(!s->budget--) { s->failed_pc=0x0c08a11eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a120;
P_0c08a120: /* original e074, guest PC 0x0c08a120 */
if(!s->budget--) { s->failed_pc=0x0c08a120u; return 0; }
r[0]=0x00000074u;
goto P_0c08a122;
P_0c08a122: /* original fe67, guest PC 0x0c08a122 */
if(!s->budget--) { s->failed_pc=0x0c08a122u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a124;
P_0c08a124: /* original e078, guest PC 0x0c08a124 */
if(!s->budget--) { s->failed_pc=0x0c08a124u; return 0; }
r[0]=0x00000078u;
goto P_0c08a126;
P_0c08a126: /* original fe67, guest PC 0x0c08a126 */
if(!s->budget--) { s->failed_pc=0x0c08a126u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a128;
P_0c08a128: /* original c73b, guest PC 0x0c08a128 */
if(!s->budget--) { s->failed_pc=0x0c08a128u; return 0; }
r[0]=0x0c08a218u;
goto P_0c08a12a;
P_0c08a12a: /* original f508, guest PC 0x0c08a12a */
if(!s->budget--) { s->failed_pc=0x0c08a12au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a12c;
P_0c08a12c: /* original c73b, guest PC 0x0c08a12c */
if(!s->budget--) { s->failed_pc=0x0c08a12cu; return 0; }
r[0]=0x0c08a21cu;
goto P_0c08a12e;
P_0c08a12e: /* original f608, guest PC 0x0c08a12e */
if(!s->budget--) { s->failed_pc=0x0c08a12eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a130;
P_0c08a130: /* original c73b, guest PC 0x0c08a130 */
if(!s->budget--) { s->failed_pc=0x0c08a130u; return 0; }
r[0]=0x0c08a220u;
goto P_0c08a132;
P_0c08a132: /* original f708, guest PC 0x0c08a132 */
if(!s->budget--) { s->failed_pc=0x0c08a132u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a134;
P_0c08a134: /* original e05c, guest PC 0x0c08a134 */
if(!s->budget--) { s->failed_pc=0x0c08a134u; return 0; }
r[0]=0x0000005cu;
goto P_0c08a136;
P_0c08a136: /* original fe47, guest PC 0x0c08a136 */
if(!s->budget--) { s->failed_pc=0x0c08a136u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a138;
P_0c08a138: /* original e060, guest PC 0x0c08a138 */
if(!s->budget--) { s->failed_pc=0x0c08a138u; return 0; }
r[0]=0x00000060u;
goto P_0c08a13a;
P_0c08a13a: /* original fe47, guest PC 0x0c08a13a */
if(!s->budget--) { s->failed_pc=0x0c08a13au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a13c;
P_0c08a13c: /* original e064, guest PC 0x0c08a13c */
if(!s->budget--) { s->failed_pc=0x0c08a13cu; return 0; }
r[0]=0x00000064u;
goto P_0c08a13e;
P_0c08a13e: /* original fe47, guest PC 0x0c08a13e */
if(!s->budget--) { s->failed_pc=0x0c08a13eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a140;
P_0c08a140: /* original e050, guest PC 0x0c08a140 */
if(!s->budget--) { s->failed_pc=0x0c08a140u; return 0; }
r[0]=0x00000050u;
goto P_0c08a142;
P_0c08a142: /* original fe57, guest PC 0x0c08a142 */
if(!s->budget--) { s->failed_pc=0x0c08a142u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a144;
P_0c08a144: /* original e054, guest PC 0x0c08a144 */
if(!s->budget--) { s->failed_pc=0x0c08a144u; return 0; }
r[0]=0x00000054u;
goto P_0c08a146;
P_0c08a146: /* original fe67, guest PC 0x0c08a146 */
if(!s->budget--) { s->failed_pc=0x0c08a146u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a148;
P_0c08a148: /* original e058, guest PC 0x0c08a148 */
if(!s->budget--) { s->failed_pc=0x0c08a148u; return 0; }
r[0]=0x00000058u;
goto P_0c08a14a;
P_0c08a14a: /* original fe77, guest PC 0x0c08a14a */
if(!s->budget--) { s->failed_pc=0x0c08a14au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08a14c;
P_0c08a14c: /* original e07c, guest PC 0x0c08a14c */
if(!s->budget--) { s->failed_pc=0x0c08a14cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08a14e;
P_0c08a14e: /* original fe47, guest PC 0x0c08a14e */
if(!s->budget--) { s->failed_pc=0x0c08a14eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a150;
P_0c08a150: /* original 7004, guest PC 0x0c08a150 */
if(!s->budget--) { s->failed_pc=0x0c08a150u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a152;
P_0c08a152: /* original fe47, guest PC 0x0c08a152 */
if(!s->budget--) { s->failed_pc=0x0c08a152u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a154;
P_0c08a154: /* original 7004, guest PC 0x0c08a154 */
if(!s->budget--) { s->failed_pc=0x0c08a154u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a156;
P_0c08a156: /* original fe47, guest PC 0x0c08a156 */
if(!s->budget--) { s->failed_pc=0x0c08a156u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a158;
P_0c08a158: /* original 7004, guest PC 0x0c08a158 */
if(!s->budget--) { s->failed_pc=0x0c08a158u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a15a;
P_0c08a15a: /* original fe47, guest PC 0x0c08a15a */
if(!s->budget--) { s->failed_pc=0x0c08a15au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a15c;
P_0c08a15c: /* original c731, guest PC 0x0c08a15c */
if(!s->budget--) { s->failed_pc=0x0c08a15cu; return 0; }
r[0]=0x0c08a224u;
goto P_0c08a15e;
P_0c08a15e: /* original f808, guest PC 0x0c08a15e */
if(!s->budget--) { s->failed_pc=0x0c08a15eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a160;
P_0c08a160: /* original 9044, guest PC 0x0c08a160 */
if(!s->budget--) { s->failed_pc=0x0c08a160u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1ecu,2);
goto P_0c08a162;
P_0c08a162: /* original fe87, guest PC 0x0c08a162 */
if(!s->budget--) { s->failed_pc=0x0c08a162u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c08a164;
P_0c08a164: /* original 7004, guest PC 0x0c08a164 */
if(!s->budget--) { s->failed_pc=0x0c08a164u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a166;
P_0c08a166: /* original fe47, guest PC 0x0c08a166 */
if(!s->budget--) { s->failed_pc=0x0c08a166u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a168;
P_0c08a168: /* original c72f, guest PC 0x0c08a168 */
if(!s->budget--) { s->failed_pc=0x0c08a168u; return 0; }
r[0]=0x0c08a228u;
goto P_0c08a16a;
P_0c08a16a: /* original 64c3, guest PC 0x0c08a16a */
if(!s->budget--) { s->failed_pc=0x0c08a16au; return 0; }
r[4]=r[12];
goto P_0c08a16c;
P_0c08a16c: /* original 7404, guest PC 0x0c08a16c */
if(!s->budget--) { s->failed_pc=0x0c08a16cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a16e;
P_0c08a16e: /* original e310, guest PC 0x0c08a16e */
if(!s->budget--) { s->failed_pc=0x0c08a16eu; return 0; }
r[3]=0x00000010u;
goto P_0c08a170;
P_0c08a170: /* original 2c32, guest PC 0x0c08a170 */
if(!s->budget--) { s->failed_pc=0x0c08a170u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c08a172;
P_0c08a172: /* original f908, guest PC 0x0c08a172 */
if(!s->budget--) { s->failed_pc=0x0c08a172u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a174;
P_0c08a174: /* original c72d, guest PC 0x0c08a174 */
if(!s->budget--) { s->failed_pc=0x0c08a174u; return 0; }
r[0]=0x0c08a22cu;
goto P_0c08a176;
P_0c08a176: /* original fa08, guest PC 0x0c08a176 */
if(!s->budget--) { s->failed_pc=0x0c08a176u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a178;
P_0c08a178: /* original c72d, guest PC 0x0c08a178 */
if(!s->budget--) { s->failed_pc=0x0c08a178u; return 0; }
r[0]=0x0c08a230u;
goto P_0c08a17a;
P_0c08a17a: /* original f608, guest PC 0x0c08a17a */
if(!s->budget--) { s->failed_pc=0x0c08a17au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a17c;
P_0c08a17c: /* original c72d, guest PC 0x0c08a17c */
if(!s->budget--) { s->failed_pc=0x0c08a17cu; return 0; }
r[0]=0x0c08a234u;
goto P_0c08a17e;
P_0c08a17e: /* original f708, guest PC 0x0c08a17e */
if(!s->budget--) { s->failed_pc=0x0c08a17eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a180;
P_0c08a180: /* original c72d, guest PC 0x0c08a180 */
if(!s->budget--) { s->failed_pc=0x0c08a180u; return 0; }
r[0]=0x0c08a238u;
goto P_0c08a182;
P_0c08a182: /* original f508, guest PC 0x0c08a182 */
if(!s->budget--) { s->failed_pc=0x0c08a182u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a184;
P_0c08a184: /* original e004, guest PC 0x0c08a184 */
if(!s->budget--) { s->failed_pc=0x0c08a184u; return 0; }
r[0]=0x00000004u;
goto P_0c08a186;
P_0c08a186: /* original f49a, guest PC 0x0c08a186 */
if(!s->budget--) { s->failed_pc=0x0c08a186u; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a188;
P_0c08a188: /* original f457, guest PC 0x0c08a188 */
if(!s->budget--) { s->failed_pc=0x0c08a188u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a18a;
P_0c08a18a: /* original e008, guest PC 0x0c08a18a */
if(!s->budget--) { s->failed_pc=0x0c08a18au; return 0; }
r[0]=0x00000008u;
goto P_0c08a18c;
P_0c08a18c: /* original f447, guest PC 0x0c08a18c */
if(!s->budget--) { s->failed_pc=0x0c08a18cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a18e;
P_0c08a18e: /* original 740c, guest PC 0x0c08a18e */
if(!s->budget--) { s->failed_pc=0x0c08a18eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a190;
P_0c08a190: /* original e004, guest PC 0x0c08a190 */
if(!s->budget--) { s->failed_pc=0x0c08a190u; return 0; }
r[0]=0x00000004u;
goto P_0c08a192;
P_0c08a192: /* original f46a, guest PC 0x0c08a192 */
if(!s->budget--) { s->failed_pc=0x0c08a192u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a194;
P_0c08a194: /* original f457, guest PC 0x0c08a194 */
if(!s->budget--) { s->failed_pc=0x0c08a194u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a196;
P_0c08a196: /* original e008, guest PC 0x0c08a196 */
if(!s->budget--) { s->failed_pc=0x0c08a196u; return 0; }
r[0]=0x00000008u;
goto P_0c08a198;
P_0c08a198: /* original f467, guest PC 0x0c08a198 */
if(!s->budget--) { s->failed_pc=0x0c08a198u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a19a;
P_0c08a19a: /* original 740c, guest PC 0x0c08a19a */
if(!s->budget--) { s->failed_pc=0x0c08a19au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a19c;
P_0c08a19c: /* original e004, guest PC 0x0c08a19c */
if(!s->budget--) { s->failed_pc=0x0c08a19cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a19e;
P_0c08a19e: /* original f44a, guest PC 0x0c08a19e */
if(!s->budget--) { s->failed_pc=0x0c08a19eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1a0;
P_0c08a1a0: /* original f457, guest PC 0x0c08a1a0 */
if(!s->budget--) { s->failed_pc=0x0c08a1a0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1a2;
P_0c08a1a2: /* original e008, guest PC 0x0c08a1a2 */
if(!s->budget--) { s->failed_pc=0x0c08a1a2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1a4;
P_0c08a1a4: /* original f497, guest PC 0x0c08a1a4 */
if(!s->budget--) { s->failed_pc=0x0c08a1a4u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a1a6;
P_0c08a1a6: /* original e004, guest PC 0x0c08a1a6 */
if(!s->budget--) { s->failed_pc=0x0c08a1a6u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1a8;
P_0c08a1a8: /* original 740c, guest PC 0x0c08a1a8 */
if(!s->budget--) { s->failed_pc=0x0c08a1a8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1aa;
P_0c08a1aa: /* original f47a, guest PC 0x0c08a1aa */
if(!s->budget--) { s->failed_pc=0x0c08a1aau; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1ac;
P_0c08a1ac: /* original f457, guest PC 0x0c08a1ac */
if(!s->budget--) { s->failed_pc=0x0c08a1acu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ae;
P_0c08a1ae: /* original e008, guest PC 0x0c08a1ae */
if(!s->budget--) { s->failed_pc=0x0c08a1aeu; return 0; }
r[0]=0x00000008u;
goto P_0c08a1b0;
P_0c08a1b0: /* original f467, guest PC 0x0c08a1b0 */
if(!s->budget--) { s->failed_pc=0x0c08a1b0u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a1b2;
P_0c08a1b2: /* original e004, guest PC 0x0c08a1b2 */
if(!s->budget--) { s->failed_pc=0x0c08a1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1b4;
P_0c08a1b4: /* original 740c, guest PC 0x0c08a1b4 */
if(!s->budget--) { s->failed_pc=0x0c08a1b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1b6;
P_0c08a1b6: /* original f4aa, guest PC 0x0c08a1b6 */
if(!s->budget--) { s->failed_pc=0x0c08a1b6u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a1b8;
P_0c08a1b8: /* original f457, guest PC 0x0c08a1b8 */
if(!s->budget--) { s->failed_pc=0x0c08a1b8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ba;
P_0c08a1ba: /* original e008, guest PC 0x0c08a1ba */
if(!s->budget--) { s->failed_pc=0x0c08a1bau; return 0; }
r[0]=0x00000008u;
goto P_0c08a1bc;
P_0c08a1bc: /* original f447, guest PC 0x0c08a1bc */
if(!s->budget--) { s->failed_pc=0x0c08a1bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a1be;
P_0c08a1be: /* original e004, guest PC 0x0c08a1be */
if(!s->budget--) { s->failed_pc=0x0c08a1beu; return 0; }
r[0]=0x00000004u;
goto P_0c08a1c0;
P_0c08a1c0: /* original 740c, guest PC 0x0c08a1c0 */
if(!s->budget--) { s->failed_pc=0x0c08a1c0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1c2;
P_0c08a1c2: /* original f47a, guest PC 0x0c08a1c2 */
if(!s->budget--) { s->failed_pc=0x0c08a1c2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1c4;
P_0c08a1c4: /* original f457, guest PC 0x0c08a1c4 */
if(!s->budget--) { s->failed_pc=0x0c08a1c4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1c6;
P_0c08a1c6: /* original e008, guest PC 0x0c08a1c6 */
if(!s->budget--) { s->failed_pc=0x0c08a1c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1c8;
P_0c08a1c8: /* original f477, guest PC 0x0c08a1c8 */
if(!s->budget--) { s->failed_pc=0x0c08a1c8u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a1ca;
P_0c08a1ca: /* original e004, guest PC 0x0c08a1ca */
if(!s->budget--) { s->failed_pc=0x0c08a1cau; return 0; }
r[0]=0x00000004u;
goto P_0c08a1cc;
P_0c08a1cc: /* original 740c, guest PC 0x0c08a1cc */
if(!s->budget--) { s->failed_pc=0x0c08a1ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1ce;
P_0c08a1ce: /* original f44a, guest PC 0x0c08a1ce */
if(!s->budget--) { s->failed_pc=0x0c08a1ceu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1d0;
P_0c08a1d0: /* original f457, guest PC 0x0c08a1d0 */
if(!s->budget--) { s->failed_pc=0x0c08a1d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1d2;
P_0c08a1d2: /* original e008, guest PC 0x0c08a1d2 */
if(!s->budget--) { s->failed_pc=0x0c08a1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1d4;
P_0c08a1d4: /* original f4a7, guest PC 0x0c08a1d4 */
if(!s->budget--) { s->failed_pc=0x0c08a1d4u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a1d6;
P_0c08a1d6: /* original 740c, guest PC 0x0c08a1d6 */
if(!s->budget--) { s->failed_pc=0x0c08a1d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1d8;
P_0c08a1d8: /* original f46a, guest PC 0x0c08a1d8 */
if(!s->budget--) { s->failed_pc=0x0c08a1d8u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a1da;
P_0c08a1da: /* original a02f, guest PC 0x0c08a1da */
if(!s->budget--) { s->failed_pc=0x0c08a1dau; return 0; }
goto P_0c08a23c;
P_0c08a1dc: /* original 0009, guest PC 0x0c08a1dc */
if(!s->budget--) { s->failed_pc=0x0c08a1dcu; return 0; }
return vf3_matrix_family(0x0c08a1deu,s,ram);
P_0c08a23c: /* original e004, guest PC 0x0c08a23c */
if(!s->budget--) { s->failed_pc=0x0c08a23cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a23e;
P_0c08a23e: /* original f457, guest PC 0x0c08a23e */
if(!s->budget--) { s->failed_pc=0x0c08a23eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a240;
P_0c08a240: /* original e008, guest PC 0x0c08a240 */
if(!s->budget--) { s->failed_pc=0x0c08a240u; return 0; }
r[0]=0x00000008u;
goto P_0c08a242;
P_0c08a242: /* original f477, guest PC 0x0c08a242 */
if(!s->budget--) { s->failed_pc=0x0c08a242u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a244;
P_0c08a244: /* original c751, guest PC 0x0c08a244 */
if(!s->budget--) { s->failed_pc=0x0c08a244u; return 0; }
r[0]=0x0c08a38cu;
goto P_0c08a246;
P_0c08a246: /* original fa08, guest PC 0x0c08a246 */
if(!s->budget--) { s->failed_pc=0x0c08a246u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a248;
P_0c08a248: /* original c751, guest PC 0x0c08a248 */
if(!s->budget--) { s->failed_pc=0x0c08a248u; return 0; }
r[0]=0x0c08a390u;
goto P_0c08a24a;
P_0c08a24a: /* original f908, guest PC 0x0c08a24a */
if(!s->budget--) { s->failed_pc=0x0c08a24au; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a24c;
P_0c08a24c: /* original c751, guest PC 0x0c08a24c */
if(!s->budget--) { s->failed_pc=0x0c08a24cu; return 0; }
r[0]=0x0c08a394u;
goto P_0c08a24e;
P_0c08a24e: /* original f708, guest PC 0x0c08a24e */
if(!s->budget--) { s->failed_pc=0x0c08a24eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a250;
P_0c08a250: /* original c751, guest PC 0x0c08a250 */
if(!s->budget--) { s->failed_pc=0x0c08a250u; return 0; }
r[0]=0x0c08a398u;
goto P_0c08a252;
P_0c08a252: /* original f608, guest PC 0x0c08a252 */
if(!s->budget--) { s->failed_pc=0x0c08a252u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a254;
P_0c08a254: /* original e004, guest PC 0x0c08a254 */
if(!s->budget--) { s->failed_pc=0x0c08a254u; return 0; }
r[0]=0x00000004u;
goto P_0c08a256;
P_0c08a256: /* original 740c, guest PC 0x0c08a256 */
if(!s->budget--) { s->failed_pc=0x0c08a256u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a258;
P_0c08a258: /* original f58c, guest PC 0x0c08a258 */
if(!s->budget--) { s->failed_pc=0x0c08a258u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c08a25a;
P_0c08a25a: /* original f4aa, guest PC 0x0c08a25a */
if(!s->budget--) { s->failed_pc=0x0c08a25au; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a25c;
P_0c08a25c: /* original f457, guest PC 0x0c08a25c */
if(!s->budget--) { s->failed_pc=0x0c08a25cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a25e;
P_0c08a25e: /* original e008, guest PC 0x0c08a25e */
if(!s->budget--) { s->failed_pc=0x0c08a25eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a260;
P_0c08a260: /* original f447, guest PC 0x0c08a260 */
if(!s->budget--) { s->failed_pc=0x0c08a260u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a262;
P_0c08a262: /* original e004, guest PC 0x0c08a262 */
if(!s->budget--) { s->failed_pc=0x0c08a262u; return 0; }
r[0]=0x00000004u;
goto P_0c08a264;
P_0c08a264: /* original 740c, guest PC 0x0c08a264 */
if(!s->budget--) { s->failed_pc=0x0c08a264u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a266;
P_0c08a266: /* original f47a, guest PC 0x0c08a266 */
if(!s->budget--) { s->failed_pc=0x0c08a266u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a268;
P_0c08a268: /* original f457, guest PC 0x0c08a268 */
if(!s->budget--) { s->failed_pc=0x0c08a268u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a26a;
P_0c08a26a: /* original e008, guest PC 0x0c08a26a */
if(!s->budget--) { s->failed_pc=0x0c08a26au; return 0; }
r[0]=0x00000008u;
goto P_0c08a26c;
P_0c08a26c: /* original f477, guest PC 0x0c08a26c */
if(!s->budget--) { s->failed_pc=0x0c08a26cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a26e;
P_0c08a26e: /* original e004, guest PC 0x0c08a26e */
if(!s->budget--) { s->failed_pc=0x0c08a26eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a270;
P_0c08a270: /* original 740c, guest PC 0x0c08a270 */
if(!s->budget--) { s->failed_pc=0x0c08a270u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a272;
P_0c08a272: /* original f44a, guest PC 0x0c08a272 */
if(!s->budget--) { s->failed_pc=0x0c08a272u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a274;
P_0c08a274: /* original f457, guest PC 0x0c08a274 */
if(!s->budget--) { s->failed_pc=0x0c08a274u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a276;
P_0c08a276: /* original e008, guest PC 0x0c08a276 */
if(!s->budget--) { s->failed_pc=0x0c08a276u; return 0; }
r[0]=0x00000008u;
goto P_0c08a278;
P_0c08a278: /* original f4a7, guest PC 0x0c08a278 */
if(!s->budget--) { s->failed_pc=0x0c08a278u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a27a;
P_0c08a27a: /* original 740c, guest PC 0x0c08a27a */
if(!s->budget--) { s->failed_pc=0x0c08a27au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a27c;
P_0c08a27c: /* original e004, guest PC 0x0c08a27c */
if(!s->budget--) { s->failed_pc=0x0c08a27cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a27e;
P_0c08a27e: /* original f46a, guest PC 0x0c08a27e */
if(!s->budget--) { s->failed_pc=0x0c08a27eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a280;
P_0c08a280: /* original f457, guest PC 0x0c08a280 */
if(!s->budget--) { s->failed_pc=0x0c08a280u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a282;
P_0c08a282: /* original e008, guest PC 0x0c08a282 */
if(!s->budget--) { s->failed_pc=0x0c08a282u; return 0; }
r[0]=0x00000008u;
goto P_0c08a284;
P_0c08a284: /* original f477, guest PC 0x0c08a284 */
if(!s->budget--) { s->failed_pc=0x0c08a284u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a286;
P_0c08a286: /* original e004, guest PC 0x0c08a286 */
if(!s->budget--) { s->failed_pc=0x0c08a286u; return 0; }
r[0]=0x00000004u;
goto P_0c08a288;
P_0c08a288: /* original 740c, guest PC 0x0c08a288 */
if(!s->budget--) { s->failed_pc=0x0c08a288u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a28a;
P_0c08a28a: /* original f49a, guest PC 0x0c08a28a */
if(!s->budget--) { s->failed_pc=0x0c08a28au; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a28c;
P_0c08a28c: /* original f457, guest PC 0x0c08a28c */
if(!s->budget--) { s->failed_pc=0x0c08a28cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a28e;
P_0c08a28e: /* original e008, guest PC 0x0c08a28e */
if(!s->budget--) { s->failed_pc=0x0c08a28eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a290;
P_0c08a290: /* original f447, guest PC 0x0c08a290 */
if(!s->budget--) { s->failed_pc=0x0c08a290u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a292;
P_0c08a292: /* original e004, guest PC 0x0c08a292 */
if(!s->budget--) { s->failed_pc=0x0c08a292u; return 0; }
r[0]=0x00000004u;
goto P_0c08a294;
P_0c08a294: /* original 740c, guest PC 0x0c08a294 */
if(!s->budget--) { s->failed_pc=0x0c08a294u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a296;
P_0c08a296: /* original f46a, guest PC 0x0c08a296 */
if(!s->budget--) { s->failed_pc=0x0c08a296u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a298;
P_0c08a298: /* original f457, guest PC 0x0c08a298 */
if(!s->budget--) { s->failed_pc=0x0c08a298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a29a;
P_0c08a29a: /* original e008, guest PC 0x0c08a29a */
if(!s->budget--) { s->failed_pc=0x0c08a29au; return 0; }
r[0]=0x00000008u;
goto P_0c08a29c;
P_0c08a29c: /* original f467, guest PC 0x0c08a29c */
if(!s->budget--) { s->failed_pc=0x0c08a29cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a29e;
P_0c08a29e: /* original e004, guest PC 0x0c08a29e */
if(!s->budget--) { s->failed_pc=0x0c08a29eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a2a0;
P_0c08a2a0: /* original 740c, guest PC 0x0c08a2a0 */
if(!s->budget--) { s->failed_pc=0x0c08a2a0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2a2;
P_0c08a2a2: /* original f44a, guest PC 0x0c08a2a2 */
if(!s->budget--) { s->failed_pc=0x0c08a2a2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a2a4;
P_0c08a2a4: /* original f457, guest PC 0x0c08a2a4 */
if(!s->budget--) { s->failed_pc=0x0c08a2a4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2a6;
P_0c08a2a6: /* original e008, guest PC 0x0c08a2a6 */
if(!s->budget--) { s->failed_pc=0x0c08a2a6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2a8;
P_0c08a2a8: /* original f497, guest PC 0x0c08a2a8 */
if(!s->budget--) { s->failed_pc=0x0c08a2a8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a2aa;
P_0c08a2aa: /* original e004, guest PC 0x0c08a2aa */
if(!s->budget--) { s->failed_pc=0x0c08a2aau; return 0; }
r[0]=0x00000004u;
goto P_0c08a2ac;
P_0c08a2ac: /* original 740c, guest PC 0x0c08a2ac */
if(!s->budget--) { s->failed_pc=0x0c08a2acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2ae;
P_0c08a2ae: /* original f47a, guest PC 0x0c08a2ae */
if(!s->budget--) { s->failed_pc=0x0c08a2aeu; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a2b0;
P_0c08a2b0: /* original f457, guest PC 0x0c08a2b0 */
if(!s->budget--) { s->failed_pc=0x0c08a2b0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2b2;
P_0c08a2b2: /* original e008, guest PC 0x0c08a2b2 */
if(!s->budget--) { s->failed_pc=0x0c08a2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2b4;
P_0c08a2b4: /* original f467, guest PC 0x0c08a2b4 */
if(!s->budget--) { s->failed_pc=0x0c08a2b4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a2b6;
P_0c08a2b6: /* original d339, guest PC 0x0c08a2b6 */
if(!s->budget--) { s->failed_pc=0x0c08a2b6u; return 0; }
r[3]=read(ram,0x0c08a39cu,4);
goto P_0c08a2b8;
P_0c08a2b8: /* original 430b, guest PC 0x0c08a2b8 */
if(!s->budget--) { s->failed_pc=0x0c08a2b8u; return 0; }
target=r[3];
r[16]=0x0c08a2bcu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08a2bcu) { target=s->pc; goto dispatch; }
goto P_0c08a2bc;
P_0c08a2ba: /* original e401, guest PC 0x0c08a2ba */
if(!s->budget--) { s->failed_pc=0x0c08a2bau; return 0; }
r[4]=0x00000001u;
goto P_0c08a2bc;
P_0c08a2bc: /* original 7f40, guest PC 0x0c08a2bc */
if(!s->budget--) { s->failed_pc=0x0c08a2bcu; return 0; }
r[15]+=0x00000040u;
goto P_0c08a2be;
P_0c08a2be: /* original 4f26, guest PC 0x0c08a2be */
if(!s->budget--) { s->failed_pc=0x0c08a2beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a2c0;
P_0c08a2c0: /* original fff9, guest PC 0x0c08a2c0 */
if(!s->budget--) { s->failed_pc=0x0c08a2c0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a2c2;
P_0c08a2c2: /* original 6bf6, guest PC 0x0c08a2c2 */
if(!s->budget--) { s->failed_pc=0x0c08a2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a2c4;
P_0c08a2c4: /* original 6cf6, guest PC 0x0c08a2c4 */
if(!s->budget--) { s->failed_pc=0x0c08a2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a2c6;
P_0c08a2c6: /* original 6df6, guest PC 0x0c08a2c6 */
if(!s->budget--) { s->failed_pc=0x0c08a2c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a2c8;
P_0c08a2c8: /* original 000b, guest PC 0x0c08a2c8 */
if(!s->budget--) { s->failed_pc=0x0c08a2c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a2ca: /* original 6ef6, guest PC 0x0c08a2ca */
if(!s->budget--) { s->failed_pc=0x0c08a2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08a2ccu,s,ram);
P_0c08c90e: /* original 4f22, guest PC 0x0c08c90e */
if(!s->budget--) { s->failed_pc=0x0c08c90eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c910;
P_0c08c910: /* original 8801, guest PC 0x0c08c910 */
if(!s->budget--) { s->failed_pc=0x0c08c910u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c912;
P_0c08c912: /* original 8d2c, guest PC 0x0c08c912 */
if(!s->budget--) { s->failed_pc=0x0c08c912u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08c96e; }
goto P_0c08c916;
P_0c08c914: /* original 6e53, guest PC 0x0c08c914 */
if(!s->budget--) { s->failed_pc=0x0c08c914u; return 0; }
r[14]=r[5];
goto P_0c08c916;
P_0c08c916: /* original 60e2, guest PC 0x0c08c916 */
if(!s->budget--) { s->failed_pc=0x0c08c916u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08c918;
P_0c08c918: /* original cb01, guest PC 0x0c08c918 */
if(!s->budget--) { s->failed_pc=0x0c08c918u; return 0; }
r[0]|=1u;
goto P_0c08c91a;
P_0c08c91a: /* original 2e02, guest PC 0x0c08c91a */
if(!s->budget--) { s->failed_pc=0x0c08c91au; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08c91c;
P_0c08c91c: /* original 84e8, guest PC 0x0c08c91c */
if(!s->budget--) { s->failed_pc=0x0c08c91cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08c91e;
P_0c08c91e: /* original d11a, guest PC 0x0c08c91e */
if(!s->budget--) { s->failed_pc=0x0c08c91eu; return 0; }
r[1]=read(ram,0x0c08c988u,4);
goto P_0c08c920;
P_0c08c920: /* original 600c, guest PC 0x0c08c920 */
if(!s->budget--) { s->failed_pc=0x0c08c920u; return 0; }
r[0]=r[0]&255u;
goto P_0c08c922;
P_0c08c922: /* original d317, guest PC 0x0c08c922 */
if(!s->budget--) { s->failed_pc=0x0c08c922u; return 0; }
r[3]=read(ram,0x0c08c980u,4);
goto P_0c08c924;
P_0c08c924: /* original 0c1c, guest PC 0x0c08c924 */
if(!s->budget--) { s->failed_pc=0x0c08c924u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08c926;
P_0c08c926: /* original 430b, guest PC 0x0c08c926 */
if(!s->budget--) { s->failed_pc=0x0c08c926u; return 0; }
target=r[3];
r[16]=0x0c08c92au;
r[12]=r[12]&255u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c92au) { target=s->pc; goto dispatch; }
goto P_0c08c92a;
P_0c08c928: /* original 6ccc, guest PC 0x0c08c928 */
if(!s->budget--) { s->failed_pc=0x0c08c928u; return 0; }
r[12]=r[12]&255u;
goto P_0c08c92a;
P_0c08c92a: /* original d216, guest PC 0x0c08c92a */
if(!s->budget--) { s->failed_pc=0x0c08c92au; return 0; }
r[2]=read(ram,0x0c08c984u,4);
goto P_0c08c92c;
P_0c08c92c: /* original 6103, guest PC 0x0c08c92c */
if(!s->budget--) { s->failed_pc=0x0c08c92cu; return 0; }
r[1]=r[0];
goto P_0c08c92e;
P_0c08c92e: /* original 420b, guest PC 0x0c08c92e */
if(!s->budget--) { s->failed_pc=0x0c08c92eu; return 0; }
target=r[2];
r[16]=0x0c08c932u;
r[0]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c932u) { target=s->pc; goto dispatch; }
goto P_0c08c932;
P_0c08c930: /* original 60c3, guest PC 0x0c08c930 */
if(!s->budget--) { s->failed_pc=0x0c08c930u; return 0; }
r[0]=r[12];
goto P_0c08c932;
P_0c08c932: /* original 6403, guest PC 0x0c08c932 */
if(!s->budget--) { s->failed_pc=0x0c08c932u; return 0; }
r[4]=r[0];
goto P_0c08c934;
P_0c08c934: /* original 84e8, guest PC 0x0c08c934 */
if(!s->budget--) { s->failed_pc=0x0c08c934u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08c936;
P_0c08c936: /* original d115, guest PC 0x0c08c936 */
if(!s->budget--) { s->failed_pc=0x0c08c936u; return 0; }
r[1]=read(ram,0x0c08c98cu,4);
goto P_0c08c938;
P_0c08c938: /* original 4400, guest PC 0x0c08c938 */
if(!s->budget--) { s->failed_pc=0x0c08c938u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08c93a;
P_0c08c93a: /* original 600c, guest PC 0x0c08c93a */
if(!s->budget--) { s->failed_pc=0x0c08c93au; return 0; }
r[0]=r[0]&255u;
goto P_0c08c93c;
P_0c08c93c: /* original 4008, guest PC 0x0c08c93c */
if(!s->budget--) { s->failed_pc=0x0c08c93cu; return 0; }
r[0]<<=2;
goto P_0c08c93e;
P_0c08c93e: /* original 001e, guest PC 0x0c08c93e */
if(!s->budget--) { s->failed_pc=0x0c08c93eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08c940;
P_0c08c940: /* original e500, guest PC 0x0c08c940 */
if(!s->budget--) { s->failed_pc=0x0c08c940u; return 0; }
r[5]=0x00000000u;
goto P_0c08c942;
P_0c08c942: /* original 044d, guest PC 0x0c08c942 */
if(!s->budget--) { s->failed_pc=0x0c08c942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08c944;
P_0c08c944: /* original e028, guest PC 0x0c08c944 */
if(!s->budget--) { s->failed_pc=0x0c08c944u; return 0; }
r[0]=0x00000028u;
goto P_0c08c946;
P_0c08c946: /* original 644d, guest PC 0x0c08c946 */
if(!s->budget--) { s->failed_pc=0x0c08c946u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c948;
P_0c08c948: /* original 0d45, guest PC 0x0c08c948 */
if(!s->budget--) { s->failed_pc=0x0c08c948u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08c94a;
P_0c08c94a: /* original e040, guest PC 0x0c08c94a */
if(!s->budget--) { s->failed_pc=0x0c08c94au; return 0; }
r[0]=0x00000040u;
goto P_0c08c94c;
P_0c08c94c: /* original 1e4d, guest PC 0x0c08c94c */
if(!s->budget--) { s->failed_pc=0x0c08c94cu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08c94e;
P_0c08c94e: /* original 0e56, guest PC 0x0c08c94e */
if(!s->budget--) { s->failed_pc=0x0c08c94eu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08c950;
P_0c08c950: /* original b402, guest PC 0x0c08c950 */
if(!s->budget--) { s->failed_pc=0x0c08c950u; return 0; }
target=0x0c08d158u; r[16]=0x0c08c954u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c954u) { target=s->pc; goto dispatch; }
goto P_0c08c954;
P_0c08c952: /* original 64e3, guest PC 0x0c08c952 */
if(!s->budget--) { s->failed_pc=0x0c08c952u; return 0; }
r[4]=r[14];
goto P_0c08c954;
P_0c08c954: /* original e200, guest PC 0x0c08c954 */
if(!s->budget--) { s->failed_pc=0x0c08c954u; return 0; }
r[2]=0x00000000u;
goto P_0c08c956;
P_0c08c956: /* original 55ee, guest PC 0x0c08c956 */
if(!s->budget--) { s->failed_pc=0x0c08c956u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08c958;
P_0c08c958: /* original e02c, guest PC 0x0c08c958 */
if(!s->budget--) { s->failed_pc=0x0c08c958u; return 0; }
r[0]=0x0000002cu;
goto P_0c08c95a;
P_0c08c95a: /* original 54ef, guest PC 0x0c08c95a */
if(!s->budget--) { s->failed_pc=0x0c08c95au; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08c95c;
P_0c08c95c: /* original 0d24, guest PC 0x0c08c95c */
if(!s->budget--) { s->failed_pc=0x0c08c95cu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08c95e;
P_0c08c95e: /* original e02d, guest PC 0x0c08c95e */
if(!s->budget--) { s->failed_pc=0x0c08c95eu; return 0; }
r[0]=0x0000002du;
goto P_0c08c960;
P_0c08c960: /* original 0d54, guest PC 0x0c08c960 */
if(!s->budget--) { s->failed_pc=0x0c08c960u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08c962;
P_0c08c962: /* original 6043, guest PC 0x0c08c962 */
if(!s->budget--) { s->failed_pc=0x0c08c962u; return 0; }
r[0]=r[4];
goto P_0c08c964;
P_0c08c964: /* original 81da, guest PC 0x0c08c964 */
if(!s->budget--) { s->failed_pc=0x0c08c964u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08c966;
P_0c08c966: /* original e048, guest PC 0x0c08c966 */
if(!s->budget--) { s->failed_pc=0x0c08c966u; return 0; }
r[0]=0x00000048u;
goto P_0c08c968;
P_0c08c968: /* original 03dc, guest PC 0x0c08c968 */
if(!s->budget--) { s->failed_pc=0x0c08c968u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08c96a;
P_0c08c96a: /* original 7301, guest PC 0x0c08c96a */
if(!s->budget--) { s->failed_pc=0x0c08c96au; return 0; }
r[3]+=0x00000001u;
goto P_0c08c96c;
P_0c08c96c: /* original 0d34, guest PC 0x0c08c96c */
if(!s->budget--) { s->failed_pc=0x0c08c96cu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08c96e;
P_0c08c96e: /* original 4f26, guest PC 0x0c08c96e */
if(!s->budget--) { s->failed_pc=0x0c08c96eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08c970;
P_0c08c970: /* original 6cf6, guest PC 0x0c08c970 */
if(!s->budget--) { s->failed_pc=0x0c08c970u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08c972;
P_0c08c972: /* original 6df6, guest PC 0x0c08c972 */
if(!s->budget--) { s->failed_pc=0x0c08c972u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08c974;
P_0c08c974: /* original 000b, guest PC 0x0c08c974 */
if(!s->budget--) { s->failed_pc=0x0c08c974u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08c976: /* original 6ef6, guest PC 0x0c08c976 */
if(!s->budget--) { s->failed_pc=0x0c08c976u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08c978u,s,ram);
P_0c09b69e: /* original 4f22, guest PC 0x0c09b69e */
if(!s->budget--) { s->failed_pc=0x0c09b69eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b6a0;
P_0c09b6a0: /* original de1f, guest PC 0x0c09b6a0 */
if(!s->budget--) { s->failed_pc=0x0c09b6a0u; return 0; }
r[14]=read(ram,0x0c09b720u,4);
goto P_0c09b6a2;
P_0c09b6a2: /* original bc63, guest PC 0x0c09b6a2 */
if(!s->budget--) { s->failed_pc=0x0c09b6a2u; return 0; }
target=0x0c09af6cu; r[16]=0x0c09b6a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b6a6u) { target=s->pc; goto dispatch; }
goto P_0c09b6a6;
P_0c09b6a4: /* original 0009, guest PC 0x0c09b6a4 */
if(!s->budget--) { s->failed_pc=0x0c09b6a4u; return 0; }
goto P_0c09b6a6;
P_0c09b6a6: /* original d21f, guest PC 0x0c09b6a6 */
if(!s->budget--) { s->failed_pc=0x0c09b6a6u; return 0; }
r[2]=read(ram,0x0c09b724u,4);
goto P_0c09b6a8;
P_0c09b6a8: /* original 420b, guest PC 0x0c09b6a8 */
if(!s->budget--) { s->failed_pc=0x0c09b6a8u; return 0; }
target=r[2];
r[16]=0x0c09b6acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b6acu) { target=s->pc; goto dispatch; }
goto P_0c09b6ac;
P_0c09b6aa: /* original 0009, guest PC 0x0c09b6aa */
if(!s->budget--) { s->failed_pc=0x0c09b6aau; return 0; }
goto P_0c09b6ac;
P_0c09b6ac: /* original e400, guest PC 0x0c09b6ac */
if(!s->budget--) { s->failed_pc=0x0c09b6acu; return 0; }
r[4]=0x00000000u;
goto P_0c09b6ae;
P_0c09b6ae: /* original e07d, guest PC 0x0c09b6ae */
if(!s->budget--) { s->failed_pc=0x0c09b6aeu; return 0; }
r[0]=0x0000007du;
goto P_0c09b6b0;
P_0c09b6b0: /* original e340, guest PC 0x0c09b6b0 */
if(!s->budget--) { s->failed_pc=0x0c09b6b0u; return 0; }
r[3]=0x00000040u;
goto P_0c09b6b2;
P_0c09b6b2: /* original 1e33, guest PC 0x0c09b6b2 */
if(!s->budget--) { s->failed_pc=0x0c09b6b2u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c09b6b4;
P_0c09b6b4: /* original e302, guest PC 0x0c09b6b4 */
if(!s->budget--) { s->failed_pc=0x0c09b6b4u; return 0; }
r[3]=0x00000002u;
goto P_0c09b6b6;
P_0c09b6b6: /* original 4f26, guest PC 0x0c09b6b6 */
if(!s->budget--) { s->failed_pc=0x0c09b6b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b6b8;
P_0c09b6b8: /* original 1e46, guest PC 0x0c09b6b8 */
if(!s->budget--) { s->failed_pc=0x0c09b6b8u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c09b6ba;
P_0c09b6ba: /* original 0e44, guest PC 0x0c09b6ba */
if(!s->budget--) { s->failed_pc=0x0c09b6bau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09b6bc;
P_0c09b6bc: /* original 1e45, guest PC 0x0c09b6bc */
if(!s->budget--) { s->failed_pc=0x0c09b6bcu; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c09b6be;
P_0c09b6be: /* original 902c, guest PC 0x0c09b6be */
if(!s->budget--) { s->failed_pc=0x0c09b6beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b71au,2);
goto P_0c09b6c0;
P_0c09b6c0: /* original 0e46, guest PC 0x0c09b6c0 */
if(!s->budget--) { s->failed_pc=0x0c09b6c0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b6c2;
P_0c09b6c2: /* original 7004, guest PC 0x0c09b6c2 */
if(!s->budget--) { s->failed_pc=0x0c09b6c2u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b6c4;
P_0c09b6c4: /* original 0e36, guest PC 0x0c09b6c4 */
if(!s->budget--) { s->failed_pc=0x0c09b6c4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b6c6;
P_0c09b6c6: /* original e374, guest PC 0x0c09b6c6 */
if(!s->budget--) { s->failed_pc=0x0c09b6c6u; return 0; }
r[3]=0x00000074u;
goto P_0c09b6c8;
P_0c09b6c8: /* original 84eb, guest PC 0x0c09b6c8 */
if(!s->budget--) { s->failed_pc=0x0c09b6c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09b6ca;
P_0c09b6ca: /* original 7001, guest PC 0x0c09b6ca */
if(!s->budget--) { s->failed_pc=0x0c09b6cau; return 0; }
r[0]+=0x00000001u;
goto P_0c09b6cc;
P_0c09b6cc: /* original 80eb, guest PC 0x0c09b6cc */
if(!s->budget--) { s->failed_pc=0x0c09b6ccu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b6ce;
P_0c09b6ce: /* original e010, guest PC 0x0c09b6ce */
if(!s->budget--) { s->failed_pc=0x0c09b6ceu; return 0; }
r[0]=0x00000010u;
goto P_0c09b6d0;
P_0c09b6d0: /* original 0e34, guest PC 0x0c09b6d0 */
if(!s->budget--) { s->failed_pc=0x0c09b6d0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09b6d2;
P_0c09b6d2: /* original a000, guest PC 0x0c09b6d2 */
if(!s->budget--) { s->failed_pc=0x0c09b6d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b6d6;
P_0c09b6d4: /* original 6ef6, guest PC 0x0c09b6d4 */
if(!s->budget--) { s->failed_pc=0x0c09b6d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b6d6;
P_0c09b6d6: /* original 2fe6, guest PC 0x0c09b6d6 */
if(!s->budget--) { s->failed_pc=0x0c09b6d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6d8;
P_0c09b6d8: /* original 2fd6, guest PC 0x0c09b6d8 */
if(!s->budget--) { s->failed_pc=0x0c09b6d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6da;
P_0c09b6da: /* original 2fc6, guest PC 0x0c09b6da */
if(!s->budget--) { s->failed_pc=0x0c09b6dau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6dc;
P_0c09b6dc: /* original 2fb6, guest PC 0x0c09b6dc */
if(!s->budget--) { s->failed_pc=0x0c09b6dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6de;
P_0c09b6de: /* original 2fa6, guest PC 0x0c09b6de */
if(!s->budget--) { s->failed_pc=0x0c09b6deu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6e0;
P_0c09b6e0: /* original 2f96, guest PC 0x0c09b6e0 */
if(!s->budget--) { s->failed_pc=0x0c09b6e0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6e2;
P_0c09b6e2: /* original 2f86, guest PC 0x0c09b6e2 */
if(!s->budget--) { s->failed_pc=0x0c09b6e2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b6e4;
P_0c09b6e4: /* original 4f22, guest PC 0x0c09b6e4 */
if(!s->budget--) { s->failed_pc=0x0c09b6e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b6e6;
P_0c09b6e6: /* original de0e, guest PC 0x0c09b6e6 */
if(!s->budget--) { s->failed_pc=0x0c09b6e6u; return 0; }
r[14]=read(ram,0x0c09b720u,4);
goto P_0c09b6e8;
P_0c09b6e8: /* original d80f, guest PC 0x0c09b6e8 */
if(!s->budget--) { s->failed_pc=0x0c09b6e8u; return 0; }
r[8]=read(ram,0x0c09b728u,4);
goto P_0c09b6ea;
P_0c09b6ea: /* original 7ff8, guest PC 0x0c09b6ea */
if(!s->budget--) { s->failed_pc=0x0c09b6eau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09b6ec;
P_0c09b6ec: /* original bc3e, guest PC 0x0c09b6ec */
if(!s->budget--) { s->failed_pc=0x0c09b6ecu; return 0; }
target=0x0c09af6cu; r[16]=0x0c09b6f0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b6f0u) { target=s->pc; goto dispatch; }
goto P_0c09b6f0;
P_0c09b6ee: /* original 0009, guest PC 0x0c09b6ee */
if(!s->budget--) { s->failed_pc=0x0c09b6eeu; return 0; }
goto P_0c09b6f0;
P_0c09b6f0: /* original d20c, guest PC 0x0c09b6f0 */
if(!s->budget--) { s->failed_pc=0x0c09b6f0u; return 0; }
r[2]=read(ram,0x0c09b724u,4);
goto P_0c09b6f2;
P_0c09b6f2: /* original 420b, guest PC 0x0c09b6f2 */
if(!s->budget--) { s->failed_pc=0x0c09b6f2u; return 0; }
target=r[2];
r[16]=0x0c09b6f6u;
r[13]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b6f6u) { target=s->pc; goto dispatch; }
goto P_0c09b6f6;
P_0c09b6f4: /* original 6d03, guest PC 0x0c09b6f4 */
if(!s->budget--) { s->failed_pc=0x0c09b6f4u; return 0; }
r[13]=r[0];
goto P_0c09b6f6;
P_0c09b6f6: /* original d30d, guest PC 0x0c09b6f6 */
if(!s->budget--) { s->failed_pc=0x0c09b6f6u; return 0; }
r[3]=read(ram,0x0c09b72cu,4);
goto P_0c09b6f8;
P_0c09b6f8: /* original 430b, guest PC 0x0c09b6f8 */
if(!s->budget--) { s->failed_pc=0x0c09b6f8u; return 0; }
target=r[3];
r[16]=0x0c09b6fcu;
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b6fcu) { target=s->pc; goto dispatch; }
goto P_0c09b6fc;
P_0c09b6fa: /* original 2f02, guest PC 0x0c09b6fa */
if(!s->budget--) { s->failed_pc=0x0c09b6fau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09b6fc;
P_0c09b6fc: /* original 6403, guest PC 0x0c09b6fc */
if(!s->budget--) { s->failed_pc=0x0c09b6fcu; return 0; }
r[4]=r[0];
goto P_0c09b6fe;
P_0c09b6fe: /* original e03a, guest PC 0x0c09b6fe */
if(!s->budget--) { s->failed_pc=0x0c09b6feu; return 0; }
r[0]=0x0000003au;
goto P_0c09b700;
P_0c09b700: /* original 024d, guest PC 0x0c09b700 */
if(!s->budget--) { s->failed_pc=0x0c09b700u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09b702;
P_0c09b702: /* original e30c, guest PC 0x0c09b702 */
if(!s->budget--) { s->failed_pc=0x0c09b702u; return 0; }
r[3]=0x0000000cu;
goto P_0c09b704;
P_0c09b704: /* original e900, guest PC 0x0c09b704 */
if(!s->budget--) { s->failed_pc=0x0c09b704u; return 0; }
r[9]=0x00000000u;
goto P_0c09b706;
P_0c09b706: /* original 622d, guest PC 0x0c09b706 */
if(!s->budget--) { s->failed_pc=0x0c09b706u; return 0; }
r[2]=r[2]&65535u;
goto P_0c09b708;
P_0c09b708: /* original 3233, guest PC 0x0c09b708 */
if(!s->budget--) { s->failed_pc=0x0c09b708u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c09b70a;
P_0c09b70a: /* original 8f11, guest PC 0x0c09b70a */
if(!s->budget--) { s->failed_pc=0x0c09b70au; return 0; }
cond=r[17]&1u;
r[11]=0x00000001u;
if(!cond) { goto P_0c09b730; }
goto P_0c09b70e;
P_0c09b70c: /* original eb01, guest PC 0x0c09b70c */
if(!s->budget--) { s->failed_pc=0x0c09b70cu; return 0; }
r[11]=0x00000001u;
goto P_0c09b70e;
P_0c09b70e: /* original a010, guest PC 0x0c09b70e */
if(!s->budget--) { s->failed_pc=0x0c09b70eu; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c09b732;
P_0c09b710: /* original 1fb1, guest PC 0x0c09b710 */
if(!s->budget--) { s->failed_pc=0x0c09b710u; return 0; }
write(ram,r[15]+4,r[11],4);
return vf3_matrix_family(0x0c09b712u,s,ram);
P_0c09b730: /* original 1f91, guest PC 0x0c09b730 */
if(!s->budget--) { s->failed_pc=0x0c09b730u; return 0; }
write(ram,r[15]+4,r[9],4);
goto P_0c09b732;
P_0c09b732: /* original e340, guest PC 0x0c09b732 */
if(!s->budget--) { s->failed_pc=0x0c09b732u; return 0; }
r[3]=0x00000040u;
goto P_0c09b734;
P_0c09b734: /* original 1e33, guest PC 0x0c09b734 */
if(!s->budget--) { s->failed_pc=0x0c09b734u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c09b736;
P_0c09b736: /* original e07d, guest PC 0x0c09b736 */
if(!s->budget--) { s->failed_pc=0x0c09b736u; return 0; }
r[0]=0x0000007du;
goto P_0c09b738;
P_0c09b738: /* original 1e96, guest PC 0x0c09b738 */
if(!s->budget--) { s->failed_pc=0x0c09b738u; return 0; }
write(ram,r[14]+24,r[9],4);
goto P_0c09b73a;
P_0c09b73a: /* original 0e94, guest PC 0x0c09b73a */
if(!s->budget--) { s->failed_pc=0x0c09b73au; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c09b73c;
P_0c09b73c: /* original 1e95, guest PC 0x0c09b73c */
if(!s->budget--) { s->failed_pc=0x0c09b73cu; return 0; }
write(ram,r[14]+20,r[9],4);
goto P_0c09b73e;
P_0c09b73e: /* original 63f2, guest PC 0x0c09b73e */
if(!s->budget--) { s->failed_pc=0x0c09b73eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09b740;
P_0c09b740: /* original dc19, guest PC 0x0c09b740 */
if(!s->budget--) { s->failed_pc=0x0c09b740u; return 0; }
r[12]=read(ram,0x0c09b7a8u,4);
goto P_0c09b742;
P_0c09b742: /* original 2338, guest PC 0x0c09b742 */
if(!s->budget--) { s->failed_pc=0x0c09b742u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09b744;
P_0c09b744: /* original 8f0b, guest PC 0x0c09b744 */
if(!s->budget--) { s->failed_pc=0x0c09b744u; return 0; }
cond=r[17]&1u;
r[10]=0x00000002u;
if(!cond) { goto P_0c09b75e; }
goto P_0c09b748;
P_0c09b746: /* original ea02, guest PC 0x0c09b746 */
if(!s->budget--) { s->failed_pc=0x0c09b746u; return 0; }
r[10]=0x00000002u;
goto P_0c09b748;
P_0c09b748: /* original 902a, guest PC 0x0c09b748 */
if(!s->budget--) { s->failed_pc=0x0c09b748u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a0u,2);
goto P_0c09b74a;
P_0c09b74a: /* original 02ee, guest PC 0x0c09b74a */
if(!s->budget--) { s->failed_pc=0x0c09b74au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b74c;
P_0c09b74c: /* original 2228, guest PC 0x0c09b74c */
if(!s->budget--) { s->failed_pc=0x0c09b74cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b74e;
P_0c09b74e: /* original 8b06, guest PC 0x0c09b74e */
if(!s->budget--) { s->failed_pc=0x0c09b74eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b75e; }
goto P_0c09b750;
P_0c09b750: /* original 9027, guest PC 0x0c09b750 */
if(!s->budget--) { s->failed_pc=0x0c09b750u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a2u,2);
goto P_0c09b752;
P_0c09b752: /* original 00ee, guest PC 0x0c09b752 */
if(!s->budget--) { s->failed_pc=0x0c09b752u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b754;
P_0c09b754: /* original 8802, guest PC 0x0c09b754 */
if(!s->budget--) { s->failed_pc=0x0c09b754u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b756;
P_0c09b756: /* original 8902, guest PC 0x0c09b756 */
if(!s->budget--) { s->failed_pc=0x0c09b756u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b75e; }
goto P_0c09b758;
P_0c09b758: /* original 9023, guest PC 0x0c09b758 */
if(!s->budget--) { s->failed_pc=0x0c09b758u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a2u,2);
goto P_0c09b75a;
P_0c09b75a: /* original a041, guest PC 0x0c09b75a */
if(!s->budget--) { s->failed_pc=0x0c09b75au; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09b7e0;
P_0c09b75c: /* original 0ea6, guest PC 0x0c09b75c */
if(!s->budget--) { s->failed_pc=0x0c09b75cu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09b75e;
P_0c09b75e: /* original e210, guest PC 0x0c09b75e */
if(!s->budget--) { s->failed_pc=0x0c09b75eu; return 0; }
r[2]=0x00000010u;
goto P_0c09b760;
P_0c09b760: /* original 22d8, guest PC 0x0c09b760 */
if(!s->budget--) { s->failed_pc=0x0c09b760u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09b762;
P_0c09b762: /* original 892a, guest PC 0x0c09b762 */
if(!s->budget--) { s->failed_pc=0x0c09b762u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7ba; }
goto P_0c09b764;
P_0c09b764: /* original 901c, guest PC 0x0c09b764 */
if(!s->budget--) { s->failed_pc=0x0c09b764u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a0u,2);
goto P_0c09b766;
P_0c09b766: /* original 01ee, guest PC 0x0c09b766 */
if(!s->budget--) { s->failed_pc=0x0c09b766u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b768;
P_0c09b768: /* original 2118, guest PC 0x0c09b768 */
if(!s->budget--) { s->failed_pc=0x0c09b768u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09b76a;
P_0c09b76a: /* original 8b26, guest PC 0x0c09b76a */
if(!s->budget--) { s->failed_pc=0x0c09b76au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b7ba; }
goto P_0c09b76c;
P_0c09b76c: /* original 941a, guest PC 0x0c09b76c */
if(!s->budget--) { s->failed_pc=0x0c09b76cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a4u,2);
goto P_0c09b76e;
P_0c09b76e: /* original 4c0b, guest PC 0x0c09b76e */
if(!s->budget--) { s->failed_pc=0x0c09b76eu; return 0; }
target=r[12];
r[16]=0x0c09b772u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b772u) { target=s->pc; goto dispatch; }
goto P_0c09b772;
P_0c09b770: /* original 0009, guest PC 0x0c09b770 */
if(!s->budget--) { s->failed_pc=0x0c09b770u; return 0; }
goto P_0c09b772;
P_0c09b772: /* original 9016, guest PC 0x0c09b772 */
if(!s->budget--) { s->failed_pc=0x0c09b772u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a2u,2);
goto P_0c09b774;
P_0c09b774: /* original d20d, guest PC 0x0c09b774 */
if(!s->budget--) { s->failed_pc=0x0c09b774u; return 0; }
r[2]=read(ram,0x0c09b7acu,4);
goto P_0c09b776;
P_0c09b776: /* original 03ee, guest PC 0x0c09b776 */
if(!s->budget--) { s->failed_pc=0x0c09b776u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b778;
P_0c09b778: /* original 73ff, guest PC 0x0c09b778 */
if(!s->budget--) { s->failed_pc=0x0c09b778u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b77a;
P_0c09b77a: /* original 420b, guest PC 0x0c09b77a */
if(!s->budget--) { s->failed_pc=0x0c09b77au; return 0; }
target=r[2];
r[16]=0x0c09b77eu;
write(ram,r[14]+r[0],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b77eu) { target=s->pc; goto dispatch; }
goto P_0c09b77e;
P_0c09b77c: /* original 0e36, guest PC 0x0c09b77c */
if(!s->budget--) { s->failed_pc=0x0c09b77cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b77e;
P_0c09b77e: /* original 2008, guest PC 0x0c09b77e */
if(!s->budget--) { s->failed_pc=0x0c09b77eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09b780;
P_0c09b780: /* original 8b05, guest PC 0x0c09b780 */
if(!s->budget--) { s->failed_pc=0x0c09b780u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b78e; }
goto P_0c09b782;
P_0c09b782: /* original 900e, guest PC 0x0c09b782 */
if(!s->budget--) { s->failed_pc=0x0c09b782u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a2u,2);
goto P_0c09b784;
P_0c09b784: /* original 02ee, guest PC 0x0c09b784 */
if(!s->budget--) { s->failed_pc=0x0c09b784u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b786;
P_0c09b786: /* original 4211, guest PC 0x0c09b786 */
if(!s->budget--) { s->failed_pc=0x0c09b786u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b788;
P_0c09b788: /* original 8917, guest PC 0x0c09b788 */
if(!s->budget--) { s->failed_pc=0x0c09b788u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7ba; }
goto P_0c09b78a;
P_0c09b78a: /* original a016, guest PC 0x0c09b78a */
if(!s->budget--) { s->failed_pc=0x0c09b78au; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09b7ba;
P_0c09b78c: /* original 0e96, guest PC 0x0c09b78c */
if(!s->budget--) { s->failed_pc=0x0c09b78cu; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09b78e;
P_0c09b78e: /* original 52f1, guest PC 0x0c09b78e */
if(!s->budget--) { s->failed_pc=0x0c09b78eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c09b790;
P_0c09b790: /* original 2228, guest PC 0x0c09b790 */
if(!s->budget--) { s->failed_pc=0x0c09b790u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b792;
P_0c09b792: /* original 890d, guest PC 0x0c09b792 */
if(!s->budget--) { s->failed_pc=0x0c09b792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7b0; }
goto P_0c09b794;
P_0c09b794: /* original 9005, guest PC 0x0c09b794 */
if(!s->budget--) { s->failed_pc=0x0c09b794u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b7a2u,2);
goto P_0c09b796;
P_0c09b796: /* original 03ee, guest PC 0x0c09b796 */
if(!s->budget--) { s->failed_pc=0x0c09b796u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b798;
P_0c09b798: /* original 33b3, guest PC 0x0c09b798 */
if(!s->budget--) { s->failed_pc=0x0c09b798u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[11])!=0);
goto P_0c09b79a;
P_0c09b79a: /* original 890e, guest PC 0x0c09b79a */
if(!s->budget--) { s->failed_pc=0x0c09b79au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7ba; }
goto P_0c09b79c;
P_0c09b79c: /* original a00d, guest PC 0x0c09b79c */
if(!s->budget--) { s->failed_pc=0x0c09b79cu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b7ba;
P_0c09b79e: /* original 0eb6, guest PC 0x0c09b79e */
if(!s->budget--) { s->failed_pc=0x0c09b79eu; return 0; }
write(ram,r[14]+r[0],r[11],4);
return vf3_matrix_family(0x0c09b7a0u,s,ram);
P_0c09b7b0: /* original 906e, guest PC 0x0c09b7b0 */
if(!s->budget--) { s->failed_pc=0x0c09b7b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b890u,2);
goto P_0c09b7b2;
P_0c09b7b2: /* original 02ee, guest PC 0x0c09b7b2 */
if(!s->budget--) { s->failed_pc=0x0c09b7b2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b7b4;
P_0c09b7b4: /* original 32a3, guest PC 0x0c09b7b4 */
if(!s->budget--) { s->failed_pc=0x0c09b7b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[10])!=0);
goto P_0c09b7b6;
P_0c09b7b6: /* original 8900, guest PC 0x0c09b7b6 */
if(!s->budget--) { s->failed_pc=0x0c09b7b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7ba; }
goto P_0c09b7b8;
P_0c09b7b8: /* original 0ea6, guest PC 0x0c09b7b8 */
if(!s->budget--) { s->failed_pc=0x0c09b7b8u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09b7ba;
P_0c09b7ba: /* original e320, guest PC 0x0c09b7ba */
if(!s->budget--) { s->failed_pc=0x0c09b7bau; return 0; }
r[3]=0x00000020u;
goto P_0c09b7bc;
P_0c09b7bc: /* original 23d8, guest PC 0x0c09b7bc */
if(!s->budget--) { s->failed_pc=0x0c09b7bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b7be;
P_0c09b7be: /* original 890f, guest PC 0x0c09b7be */
if(!s->budget--) { s->failed_pc=0x0c09b7beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7e0; }
goto P_0c09b7c0;
P_0c09b7c0: /* original 9067, guest PC 0x0c09b7c0 */
if(!s->budget--) { s->failed_pc=0x0c09b7c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b892u,2);
goto P_0c09b7c2;
P_0c09b7c2: /* original 01ee, guest PC 0x0c09b7c2 */
if(!s->budget--) { s->failed_pc=0x0c09b7c2u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b7c4;
P_0c09b7c4: /* original 2118, guest PC 0x0c09b7c4 */
if(!s->budget--) { s->failed_pc=0x0c09b7c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09b7c6;
P_0c09b7c6: /* original 8b0b, guest PC 0x0c09b7c6 */
if(!s->budget--) { s->failed_pc=0x0c09b7c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b7e0; }
goto P_0c09b7c8;
P_0c09b7c8: /* original 9464, guest PC 0x0c09b7c8 */
if(!s->budget--) { s->failed_pc=0x0c09b7c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b894u,2);
goto P_0c09b7ca;
P_0c09b7ca: /* original 4c0b, guest PC 0x0c09b7ca */
if(!s->budget--) { s->failed_pc=0x0c09b7cau; return 0; }
target=r[12];
r[16]=0x0c09b7ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b7ceu) { target=s->pc; goto dispatch; }
goto P_0c09b7ce;
P_0c09b7cc: /* original 0009, guest PC 0x0c09b7cc */
if(!s->budget--) { s->failed_pc=0x0c09b7ccu; return 0; }
goto P_0c09b7ce;
P_0c09b7ce: /* original 905f, guest PC 0x0c09b7ce */
if(!s->budget--) { s->failed_pc=0x0c09b7ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b890u,2);
goto P_0c09b7d0;
P_0c09b7d0: /* original e203, guest PC 0x0c09b7d0 */
if(!s->budget--) { s->failed_pc=0x0c09b7d0u; return 0; }
r[2]=0x00000003u;
goto P_0c09b7d2;
P_0c09b7d2: /* original 03ee, guest PC 0x0c09b7d2 */
if(!s->budget--) { s->failed_pc=0x0c09b7d2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b7d4;
P_0c09b7d4: /* original 7301, guest PC 0x0c09b7d4 */
if(!s->budget--) { s->failed_pc=0x0c09b7d4u; return 0; }
r[3]+=0x00000001u;
goto P_0c09b7d6;
P_0c09b7d6: /* original 0e36, guest PC 0x0c09b7d6 */
if(!s->budget--) { s->failed_pc=0x0c09b7d6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b7d8;
P_0c09b7d8: /* original 01ee, guest PC 0x0c09b7d8 */
if(!s->budget--) { s->failed_pc=0x0c09b7d8u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b7da;
P_0c09b7da: /* original 3123, guest PC 0x0c09b7da */
if(!s->budget--) { s->failed_pc=0x0c09b7dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09b7dc;
P_0c09b7dc: /* original 8b00, guest PC 0x0c09b7dc */
if(!s->budget--) { s->failed_pc=0x0c09b7dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b7e0; }
goto P_0c09b7de;
P_0c09b7de: /* original 0ea6, guest PC 0x0c09b7de */
if(!s->budget--) { s->failed_pc=0x0c09b7deu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09b7e0;
P_0c09b7e0: /* original e340, guest PC 0x0c09b7e0 */
if(!s->budget--) { s->failed_pc=0x0c09b7e0u; return 0; }
r[3]=0x00000040u;
goto P_0c09b7e2;
P_0c09b7e2: /* original 23d8, guest PC 0x0c09b7e2 */
if(!s->budget--) { s->failed_pc=0x0c09b7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b7e4;
P_0c09b7e4: /* original 890b, guest PC 0x0c09b7e4 */
if(!s->budget--) { s->failed_pc=0x0c09b7e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7fe; }
goto P_0c09b7e6;
P_0c09b7e6: /* original 9455, guest PC 0x0c09b7e6 */
if(!s->budget--) { s->failed_pc=0x0c09b7e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b894u,2);
goto P_0c09b7e8;
P_0c09b7e8: /* original 4c0b, guest PC 0x0c09b7e8 */
if(!s->budget--) { s->failed_pc=0x0c09b7e8u; return 0; }
target=r[12];
r[16]=0x0c09b7ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b7ecu) { target=s->pc; goto dispatch; }
goto P_0c09b7ec;
P_0c09b7ea: /* original 0009, guest PC 0x0c09b7ea */
if(!s->budget--) { s->failed_pc=0x0c09b7eau; return 0; }
goto P_0c09b7ec;
P_0c09b7ec: /* original 9051, guest PC 0x0c09b7ec */
if(!s->budget--) { s->failed_pc=0x0c09b7ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b892u,2);
goto P_0c09b7ee;
P_0c09b7ee: /* original 03ee, guest PC 0x0c09b7ee */
if(!s->budget--) { s->failed_pc=0x0c09b7eeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b7f0;
P_0c09b7f0: /* original 73ff, guest PC 0x0c09b7f0 */
if(!s->budget--) { s->failed_pc=0x0c09b7f0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b7f2;
P_0c09b7f2: /* original 0e36, guest PC 0x0c09b7f2 */
if(!s->budget--) { s->failed_pc=0x0c09b7f2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b7f4;
P_0c09b7f4: /* original 02ee, guest PC 0x0c09b7f4 */
if(!s->budget--) { s->failed_pc=0x0c09b7f4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b7f6;
P_0c09b7f6: /* original 4211, guest PC 0x0c09b7f6 */
if(!s->budget--) { s->failed_pc=0x0c09b7f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b7f8;
P_0c09b7f8: /* original 8901, guest PC 0x0c09b7f8 */
if(!s->budget--) { s->failed_pc=0x0c09b7f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b7fe; }
goto P_0c09b7fa;
P_0c09b7fa: /* original e110, guest PC 0x0c09b7fa */
if(!s->budget--) { s->failed_pc=0x0c09b7fau; return 0; }
r[1]=0x00000010u;
goto P_0c09b7fc;
P_0c09b7fc: /* original 0e16, guest PC 0x0c09b7fc */
if(!s->budget--) { s->failed_pc=0x0c09b7fcu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b7fe;
P_0c09b7fe: /* original 934a, guest PC 0x0c09b7fe */
if(!s->budget--) { s->failed_pc=0x0c09b7feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b896u,2);
goto P_0c09b800;
P_0c09b800: /* original 23d8, guest PC 0x0c09b800 */
if(!s->budget--) { s->failed_pc=0x0c09b800u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b802;
P_0c09b802: /* original 890b, guest PC 0x0c09b802 */
if(!s->budget--) { s->failed_pc=0x0c09b802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b81c; }
goto P_0c09b804;
P_0c09b804: /* original 9446, guest PC 0x0c09b804 */
if(!s->budget--) { s->failed_pc=0x0c09b804u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b894u,2);
goto P_0c09b806;
P_0c09b806: /* original 4c0b, guest PC 0x0c09b806 */
if(!s->budget--) { s->failed_pc=0x0c09b806u; return 0; }
target=r[12];
r[16]=0x0c09b80au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b80au) { target=s->pc; goto dispatch; }
goto P_0c09b80a;
P_0c09b808: /* original 0009, guest PC 0x0c09b808 */
if(!s->budget--) { s->failed_pc=0x0c09b808u; return 0; }
goto P_0c09b80a;
P_0c09b80a: /* original 9042, guest PC 0x0c09b80a */
if(!s->budget--) { s->failed_pc=0x0c09b80au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b892u,2);
goto P_0c09b80c;
P_0c09b80c: /* original e211, guest PC 0x0c09b80c */
if(!s->budget--) { s->failed_pc=0x0c09b80cu; return 0; }
r[2]=0x00000011u;
goto P_0c09b80e;
P_0c09b80e: /* original 03ee, guest PC 0x0c09b80e */
if(!s->budget--) { s->failed_pc=0x0c09b80eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b810;
P_0c09b810: /* original 7301, guest PC 0x0c09b810 */
if(!s->budget--) { s->failed_pc=0x0c09b810u; return 0; }
r[3]+=0x00000001u;
goto P_0c09b812;
P_0c09b812: /* original 0e36, guest PC 0x0c09b812 */
if(!s->budget--) { s->failed_pc=0x0c09b812u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b814;
P_0c09b814: /* original 01ee, guest PC 0x0c09b814 */
if(!s->budget--) { s->failed_pc=0x0c09b814u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b816;
P_0c09b816: /* original 3123, guest PC 0x0c09b816 */
if(!s->budget--) { s->failed_pc=0x0c09b816u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09b818;
P_0c09b818: /* original 8b00, guest PC 0x0c09b818 */
if(!s->budget--) { s->failed_pc=0x0c09b818u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b81c; }
goto P_0c09b81a;
P_0c09b81a: /* original 0e96, guest PC 0x0c09b81a */
if(!s->budget--) { s->failed_pc=0x0c09b81au; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09b81c;
P_0c09b81c: /* original e304, guest PC 0x0c09b81c */
if(!s->budget--) { s->failed_pc=0x0c09b81cu; return 0; }
r[3]=0x00000004u;
goto P_0c09b81e;
P_0c09b81e: /* original 23d8, guest PC 0x0c09b81e */
if(!s->budget--) { s->failed_pc=0x0c09b81eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b820;
P_0c09b820: /* original 8961, guest PC 0x0c09b820 */
if(!s->budget--) { s->failed_pc=0x0c09b820u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b8e6; }
goto P_0c09b822;
P_0c09b822: /* original 9036, guest PC 0x0c09b822 */
if(!s->budget--) { s->failed_pc=0x0c09b822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b892u,2);
goto P_0c09b824;
P_0c09b824: /* original 01ee, guest PC 0x0c09b824 */
if(!s->budget--) { s->failed_pc=0x0c09b824u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b826;
P_0c09b826: /* original 2118, guest PC 0x0c09b826 */
if(!s->budget--) { s->failed_pc=0x0c09b826u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09b828;
P_0c09b828: /* original 8b5d, guest PC 0x0c09b828 */
if(!s->budget--) { s->failed_pc=0x0c09b828u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b8e6; }
goto P_0c09b82a;
P_0c09b82a: /* original 9435, guest PC 0x0c09b82a */
if(!s->budget--) { s->failed_pc=0x0c09b82au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b898u,2);
goto P_0c09b82c;
P_0c09b82c: /* original 4c0b, guest PC 0x0c09b82c */
if(!s->budget--) { s->failed_pc=0x0c09b82cu; return 0; }
target=r[12];
r[16]=0x0c09b830u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b830u) { target=s->pc; goto dispatch; }
goto P_0c09b830;
P_0c09b82e: /* original 0009, guest PC 0x0c09b82e */
if(!s->budget--) { s->failed_pc=0x0c09b82eu; return 0; }
goto P_0c09b830;
P_0c09b830: /* original 902e, guest PC 0x0c09b830 */
if(!s->budget--) { s->failed_pc=0x0c09b830u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b890u,2);
goto P_0c09b832;
P_0c09b832: /* original 00ee, guest PC 0x0c09b832 */
if(!s->budget--) { s->failed_pc=0x0c09b832u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b834;
P_0c09b834: /* original 8800, guest PC 0x0c09b834 */
if(!s->budget--) { s->failed_pc=0x0c09b834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09b836;
P_0c09b836: /* original 8905, guest PC 0x0c09b836 */
if(!s->budget--) { s->failed_pc=0x0c09b836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b844; }
goto P_0c09b838;
P_0c09b838: /* original 8801, guest PC 0x0c09b838 */
if(!s->budget--) { s->failed_pc=0x0c09b838u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b83a;
P_0c09b83a: /* original 893d, guest PC 0x0c09b83a */
if(!s->budget--) { s->failed_pc=0x0c09b83au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b8b8; }
goto P_0c09b83c;
P_0c09b83c: /* original 8802, guest PC 0x0c09b83c */
if(!s->budget--) { s->failed_pc=0x0c09b83cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b83e;
P_0c09b83e: /* original 8962, guest PC 0x0c09b83e */
if(!s->budget--) { s->failed_pc=0x0c09b83eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b906; }
goto P_0c09b840;
P_0c09b840: /* original a051, guest PC 0x0c09b840 */
if(!s->budget--) { s->failed_pc=0x0c09b840u; return 0; }
goto P_0c09b8e6;
P_0c09b842: /* original 0009, guest PC 0x0c09b842 */
if(!s->budget--) { s->failed_pc=0x0c09b842u; return 0; }
goto P_0c09b844;
P_0c09b844: /* original d317, guest PC 0x0c09b844 */
if(!s->budget--) { s->failed_pc=0x0c09b844u; return 0; }
r[3]=read(ram,0x0c09b8a4u,4);
goto P_0c09b846;
P_0c09b846: /* original d416, guest PC 0x0c09b846 */
if(!s->budget--) { s->failed_pc=0x0c09b846u; return 0; }
r[4]=read(ram,0x0c09b8a0u,4);
goto P_0c09b848;
P_0c09b848: /* original 9527, guest PC 0x0c09b848 */
if(!s->budget--) { s->failed_pc=0x0c09b848u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b89au,2);
goto P_0c09b84a;
P_0c09b84a: /* original 430b, guest PC 0x0c09b84a */
if(!s->budget--) { s->failed_pc=0x0c09b84au; return 0; }
target=r[3];
r[16]=0x0c09b84eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b84eu) { target=s->pc; goto dispatch; }
goto P_0c09b84e;
P_0c09b84c: /* original 0009, guest PC 0x0c09b84c */
if(!s->budget--) { s->failed_pc=0x0c09b84cu; return 0; }
goto P_0c09b84e;
P_0c09b84e: /* original 6503, guest PC 0x0c09b84e */
if(!s->budget--) { s->failed_pc=0x0c09b84eu; return 0; }
r[5]=r[0];
goto P_0c09b850;
P_0c09b850: /* original 2558, guest PC 0x0c09b850 */
if(!s->budget--) { s->failed_pc=0x0c09b850u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09b852;
P_0c09b852: /* original 8902, guest PC 0x0c09b852 */
if(!s->budget--) { s->failed_pc=0x0c09b852u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b85a; }
goto P_0c09b854;
P_0c09b854: /* original d314, guest PC 0x0c09b854 */
if(!s->budget--) { s->failed_pc=0x0c09b854u; return 0; }
r[3]=read(ram,0x0c09b8a8u,4);
goto P_0c09b856;
P_0c09b856: /* original 430b, guest PC 0x0c09b856 */
if(!s->budget--) { s->failed_pc=0x0c09b856u; return 0; }
target=r[3];
r[16]=0x0c09b85au;
r[4]=0x0000000bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b85au) { target=s->pc; goto dispatch; }
goto P_0c09b85a;
P_0c09b858: /* original e40b, guest PC 0x0c09b858 */
if(!s->budget--) { s->failed_pc=0x0c09b858u; return 0; }
r[4]=0x0000000bu;
goto P_0c09b85a;
P_0c09b85a: /* original d214, guest PC 0x0c09b85a */
if(!s->budget--) { s->failed_pc=0x0c09b85au; return 0; }
r[2]=read(ram,0x0c09b8acu,4);
goto P_0c09b85c;
P_0c09b85c: /* original 420b, guest PC 0x0c09b85c */
if(!s->budget--) { s->failed_pc=0x0c09b85cu; return 0; }
target=r[2];
r[16]=0x0c09b860u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b860u) { target=s->pc; goto dispatch; }
goto P_0c09b860;
P_0c09b85e: /* original 0009, guest PC 0x0c09b85e */
if(!s->budget--) { s->failed_pc=0x0c09b85eu; return 0; }
goto P_0c09b860;
P_0c09b860: /* original d913, guest PC 0x0c09b860 */
if(!s->budget--) { s->failed_pc=0x0c09b860u; return 0; }
r[9]=read(ram,0x0c09b8b0u,4);
goto P_0c09b862;
P_0c09b862: /* original d314, guest PC 0x0c09b862 */
if(!s->budget--) { s->failed_pc=0x0c09b862u; return 0; }
r[3]=read(ram,0x0c09b8b4u,4);
goto P_0c09b864;
P_0c09b864: /* original 6493, guest PC 0x0c09b864 */
if(!s->budget--) { s->failed_pc=0x0c09b864u; return 0; }
r[4]=r[9];
goto P_0c09b866;
P_0c09b866: /* original 430b, guest PC 0x0c09b866 */
if(!s->budget--) { s->failed_pc=0x0c09b866u; return 0; }
target=r[3];
r[16]=0x0c09b86au;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b86au) { target=s->pc; goto dispatch; }
goto P_0c09b86a;
P_0c09b868: /* original 7401, guest PC 0x0c09b868 */
if(!s->budget--) { s->failed_pc=0x0c09b868u; return 0; }
r[4]+=0x00000001u;
goto P_0c09b86a;
P_0c09b86a: /* original 9117, guest PC 0x0c09b86a */
if(!s->budget--) { s->failed_pc=0x0c09b86au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b89cu,2);
goto P_0c09b86c;
P_0c09b86c: /* original 6493, guest PC 0x0c09b86c */
if(!s->budget--) { s->failed_pc=0x0c09b86cu; return 0; }
r[4]=r[9];
goto P_0c09b86e;
P_0c09b86e: /* original 318c, guest PC 0x0c09b86e */
if(!s->budget--) { s->failed_pc=0x0c09b86eu; return 0; }
r[1]+=r[8];
goto P_0c09b870;
P_0c09b870: /* original 2100, guest PC 0x0c09b870 */
if(!s->budget--) { s->failed_pc=0x0c09b870u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09b872;
P_0c09b872: /* original d310, guest PC 0x0c09b872 */
if(!s->budget--) { s->failed_pc=0x0c09b872u; return 0; }
r[3]=read(ram,0x0c09b8b4u,4);
goto P_0c09b874;
P_0c09b874: /* original 430b, guest PC 0x0c09b874 */
if(!s->budget--) { s->failed_pc=0x0c09b874u; return 0; }
target=r[3];
r[16]=0x0c09b878u;
r[4]+=0x0000000eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b878u) { target=s->pc; goto dispatch; }
goto P_0c09b878;
P_0c09b876: /* original 740e, guest PC 0x0c09b876 */
if(!s->budget--) { s->failed_pc=0x0c09b876u; return 0; }
r[4]+=0x0000000eu;
goto P_0c09b878;
P_0c09b878: /* original 600c, guest PC 0x0c09b878 */
if(!s->budget--) { s->failed_pc=0x0c09b878u; return 0; }
r[0]=r[0]&255u;
goto P_0c09b87a;
P_0c09b87a: /* original 2008, guest PC 0x0c09b87a */
if(!s->budget--) { s->failed_pc=0x0c09b87au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09b87c;
P_0c09b87c: /* original 8b03, guest PC 0x0c09b87c */
if(!s->budget--) { s->failed_pc=0x0c09b87cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b886; }
goto P_0c09b87e;
P_0c09b87e: /* original 5082, guest PC 0x0c09b87e */
if(!s->budget--) { s->failed_pc=0x0c09b87eu; return 0; }
r[0]=read(ram,r[8]+8,4);
goto P_0c09b880;
P_0c09b880: /* original cb08, guest PC 0x0c09b880 */
if(!s->budget--) { s->failed_pc=0x0c09b880u; return 0; }
r[0]|=8u;
goto P_0c09b882;
P_0c09b882: /* original a030, guest PC 0x0c09b882 */
if(!s->budget--) { s->failed_pc=0x0c09b882u; return 0; }
write(ram,r[8]+8,r[0],4);
goto P_0c09b8e6;
P_0c09b884: /* original 1802, guest PC 0x0c09b884 */
if(!s->budget--) { s->failed_pc=0x0c09b884u; return 0; }
write(ram,r[8]+8,r[0],4);
goto P_0c09b886;
P_0c09b886: /* original 5282, guest PC 0x0c09b886 */
if(!s->budget--) { s->failed_pc=0x0c09b886u; return 0; }
r[2]=read(ram,r[8]+8,4);
goto P_0c09b888;
P_0c09b888: /* original e3f7, guest PC 0x0c09b888 */
if(!s->budget--) { s->failed_pc=0x0c09b888u; return 0; }
r[3]=0xfffffff7u;
goto P_0c09b88a;
P_0c09b88a: /* original 2239, guest PC 0x0c09b88a */
if(!s->budget--) { s->failed_pc=0x0c09b88au; return 0; }
r[2]&=r[3];
goto P_0c09b88c;
P_0c09b88c: /* original a02b, guest PC 0x0c09b88c */
if(!s->budget--) { s->failed_pc=0x0c09b88cu; return 0; }
write(ram,r[8]+8,r[2],4);
goto P_0c09b8e6;
P_0c09b88e: /* original 1822, guest PC 0x0c09b88e */
if(!s->budget--) { s->failed_pc=0x0c09b88eu; return 0; }
write(ram,r[8]+8,r[2],4);
return vf3_matrix_family(0x0c09b890u,s,ram);
P_0c09b8b8: /* original d328, guest PC 0x0c09b8b8 */
if(!s->budget--) { s->failed_pc=0x0c09b8b8u; return 0; }
r[3]=read(ram,0x0c09b95cu,4);
goto P_0c09b8ba;
P_0c09b8ba: /* original 430b, guest PC 0x0c09b8ba */
if(!s->budget--) { s->failed_pc=0x0c09b8bau; return 0; }
target=r[3];
r[16]=0x0c09b8beu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8beu) { target=s->pc; goto dispatch; }
goto P_0c09b8be;
P_0c09b8bc: /* original e401, guest PC 0x0c09b8bc */
if(!s->budget--) { s->failed_pc=0x0c09b8bcu; return 0; }
r[4]=0x00000001u;
goto P_0c09b8be;
P_0c09b8be: /* original 8810, guest PC 0x0c09b8be */
if(!s->budget--) { s->failed_pc=0x0c09b8beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c09b8c0;
P_0c09b8c0: /* original 8b04, guest PC 0x0c09b8c0 */
if(!s->budget--) { s->failed_pc=0x0c09b8c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b8cc; }
goto P_0c09b8c2;
P_0c09b8c2: /* original d327, guest PC 0x0c09b8c2 */
if(!s->budget--) { s->failed_pc=0x0c09b8c2u; return 0; }
r[3]=read(ram,0x0c09b960u,4);
goto P_0c09b8c4;
P_0c09b8c4: /* original 430b, guest PC 0x0c09b8c4 */
if(!s->budget--) { s->failed_pc=0x0c09b8c4u; return 0; }
target=r[3];
r[16]=0x0c09b8c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8c8u) { target=s->pc; goto dispatch; }
goto P_0c09b8c8;
P_0c09b8c6: /* original 0009, guest PC 0x0c09b8c6 */
if(!s->budget--) { s->failed_pc=0x0c09b8c6u; return 0; }
goto P_0c09b8c8;
P_0c09b8c8: /* original 2008, guest PC 0x0c09b8c8 */
if(!s->budget--) { s->failed_pc=0x0c09b8c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09b8ca;
P_0c09b8ca: /* original 890c, guest PC 0x0c09b8ca */
if(!s->budget--) { s->failed_pc=0x0c09b8cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b8e6; }
goto P_0c09b8cc;
P_0c09b8cc: /* original d226, guest PC 0x0c09b8cc */
if(!s->budget--) { s->failed_pc=0x0c09b8ccu; return 0; }
r[2]=read(ram,0x0c09b968u,4);
goto P_0c09b8ce;
P_0c09b8ce: /* original d425, guest PC 0x0c09b8ce */
if(!s->budget--) { s->failed_pc=0x0c09b8ceu; return 0; }
r[4]=read(ram,0x0c09b964u,4);
goto P_0c09b8d0;
P_0c09b8d0: /* original 420b, guest PC 0x0c09b8d0 */
if(!s->budget--) { s->failed_pc=0x0c09b8d0u; return 0; }
target=r[2];
r[16]=0x0c09b8d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8d4u) { target=s->pc; goto dispatch; }
goto P_0c09b8d4;
P_0c09b8d2: /* original 0009, guest PC 0x0c09b8d2 */
if(!s->budget--) { s->failed_pc=0x0c09b8d2u; return 0; }
goto P_0c09b8d4;
P_0c09b8d4: /* original 6503, guest PC 0x0c09b8d4 */
if(!s->budget--) { s->failed_pc=0x0c09b8d4u; return 0; }
r[5]=r[0];
goto P_0c09b8d6;
P_0c09b8d6: /* original 2558, guest PC 0x0c09b8d6 */
if(!s->budget--) { s->failed_pc=0x0c09b8d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09b8d8;
P_0c09b8d8: /* original 8902, guest PC 0x0c09b8d8 */
if(!s->budget--) { s->failed_pc=0x0c09b8d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b8e0; }
goto P_0c09b8da;
P_0c09b8da: /* original d224, guest PC 0x0c09b8da */
if(!s->budget--) { s->failed_pc=0x0c09b8dau; return 0; }
r[2]=read(ram,0x0c09b96cu,4);
goto P_0c09b8dc;
P_0c09b8dc: /* original 420b, guest PC 0x0c09b8dc */
if(!s->budget--) { s->failed_pc=0x0c09b8dcu; return 0; }
target=r[2];
r[16]=0x0c09b8e0u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8e0u) { target=s->pc; goto dispatch; }
goto P_0c09b8e0;
P_0c09b8de: /* original e40c, guest PC 0x0c09b8de */
if(!s->budget--) { s->failed_pc=0x0c09b8deu; return 0; }
r[4]=0x0000000cu;
goto P_0c09b8e0;
P_0c09b8e0: /* original d323, guest PC 0x0c09b8e0 */
if(!s->budget--) { s->failed_pc=0x0c09b8e0u; return 0; }
r[3]=read(ram,0x0c09b970u,4);
goto P_0c09b8e2;
P_0c09b8e2: /* original 430b, guest PC 0x0c09b8e2 */
if(!s->budget--) { s->failed_pc=0x0c09b8e2u; return 0; }
target=r[3];
r[16]=0x0c09b8e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8e6u) { target=s->pc; goto dispatch; }
goto P_0c09b8e6;
P_0c09b8e4: /* original 0009, guest PC 0x0c09b8e4 */
if(!s->budget--) { s->failed_pc=0x0c09b8e4u; return 0; }
goto P_0c09b8e6;
P_0c09b8e6: /* original e308, guest PC 0x0c09b8e6 */
if(!s->budget--) { s->failed_pc=0x0c09b8e6u; return 0; }
r[3]=0x00000008u;
goto P_0c09b8e8;
P_0c09b8e8: /* original 23d8, guest PC 0x0c09b8e8 */
if(!s->budget--) { s->failed_pc=0x0c09b8e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09b8ea;
P_0c09b8ea: /* original 8907, guest PC 0x0c09b8ea */
if(!s->budget--) { s->failed_pc=0x0c09b8eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b8fc; }
goto P_0c09b8ec;
P_0c09b8ec: /* original 9433, guest PC 0x0c09b8ec */
if(!s->budget--) { s->failed_pc=0x0c09b8ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b956u,2);
goto P_0c09b8ee;
P_0c09b8ee: /* original 4c0b, guest PC 0x0c09b8ee */
if(!s->budget--) { s->failed_pc=0x0c09b8eeu; return 0; }
target=r[12];
r[16]=0x0c09b8f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b8f2u) { target=s->pc; goto dispatch; }
goto P_0c09b8f2;
P_0c09b8f0: /* original 0009, guest PC 0x0c09b8f0 */
if(!s->budget--) { s->failed_pc=0x0c09b8f0u; return 0; }
goto P_0c09b8f2;
P_0c09b8f2: /* original 60b3, guest PC 0x0c09b8f2 */
if(!s->budget--) { s->failed_pc=0x0c09b8f2u; return 0; }
r[0]=r[11];
goto P_0c09b8f4;
P_0c09b8f4: /* original 80eb, guest PC 0x0c09b8f4 */
if(!s->budget--) { s->failed_pc=0x0c09b8f4u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b8f6;
P_0c09b8f6: /* original e010, guest PC 0x0c09b8f6 */
if(!s->budget--) { s->failed_pc=0x0c09b8f6u; return 0; }
r[0]=0x00000010u;
goto P_0c09b8f8;
P_0c09b8f8: /* original e372, guest PC 0x0c09b8f8 */
if(!s->budget--) { s->failed_pc=0x0c09b8f8u; return 0; }
r[3]=0x00000072u;
goto P_0c09b8fa;
P_0c09b8fa: /* original 0e34, guest PC 0x0c09b8fa */
if(!s->budget--) { s->failed_pc=0x0c09b8fau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09b8fc;
P_0c09b8fc: /* original 2da8, guest PC 0x0c09b8fc */
if(!s->budget--) { s->failed_pc=0x0c09b8fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[10])==0)!=0);
goto P_0c09b8fe;
P_0c09b8fe: /* original 8907, guest PC 0x0c09b8fe */
if(!s->budget--) { s->failed_pc=0x0c09b8feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b910; }
goto P_0c09b900;
P_0c09b900: /* original 942a, guest PC 0x0c09b900 */
if(!s->budget--) { s->failed_pc=0x0c09b900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b958u,2);
goto P_0c09b902;
P_0c09b902: /* original 4c0b, guest PC 0x0c09b902 */
if(!s->budget--) { s->failed_pc=0x0c09b902u; return 0; }
target=r[12];
r[16]=0x0c09b906u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b906u) { target=s->pc; goto dispatch; }
goto P_0c09b906;
P_0c09b904: /* original 0009, guest PC 0x0c09b904 */
if(!s->budget--) { s->failed_pc=0x0c09b904u; return 0; }
goto P_0c09b906;
P_0c09b906: /* original 60b3, guest PC 0x0c09b906 */
if(!s->budget--) { s->failed_pc=0x0c09b906u; return 0; }
r[0]=r[11];
goto P_0c09b908;
P_0c09b908: /* original 80eb, guest PC 0x0c09b908 */
if(!s->budget--) { s->failed_pc=0x0c09b908u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b90a;
P_0c09b90a: /* original e010, guest PC 0x0c09b90a */
if(!s->budget--) { s->failed_pc=0x0c09b90au; return 0; }
r[0]=0x00000010u;
goto P_0c09b90c;
P_0c09b90c: /* original e372, guest PC 0x0c09b90c */
if(!s->budget--) { s->failed_pc=0x0c09b90cu; return 0; }
r[3]=0x00000072u;
goto P_0c09b90e;
P_0c09b90e: /* original 0e34, guest PC 0x0c09b90e */
if(!s->budget--) { s->failed_pc=0x0c09b90eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09b910;
P_0c09b910: /* original 7f08, guest PC 0x0c09b910 */
if(!s->budget--) { s->failed_pc=0x0c09b910u; return 0; }
r[15]+=0x00000008u;
goto P_0c09b912;
P_0c09b912: /* original 4f26, guest PC 0x0c09b912 */
if(!s->budget--) { s->failed_pc=0x0c09b912u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b914;
P_0c09b914: /* original 68f6, guest PC 0x0c09b914 */
if(!s->budget--) { s->failed_pc=0x0c09b914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b916;
P_0c09b916: /* original 69f6, guest PC 0x0c09b916 */
if(!s->budget--) { s->failed_pc=0x0c09b916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b918;
P_0c09b918: /* original 6af6, guest PC 0x0c09b918 */
if(!s->budget--) { s->failed_pc=0x0c09b918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b91a;
P_0c09b91a: /* original 6bf6, guest PC 0x0c09b91a */
if(!s->budget--) { s->failed_pc=0x0c09b91au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b91c;
P_0c09b91c: /* original 6cf6, guest PC 0x0c09b91c */
if(!s->budget--) { s->failed_pc=0x0c09b91cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b91e;
P_0c09b91e: /* original 6df6, guest PC 0x0c09b91e */
if(!s->budget--) { s->failed_pc=0x0c09b91eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b920;
P_0c09b920: /* original 000b, guest PC 0x0c09b920 */
if(!s->budget--) { s->failed_pc=0x0c09b920u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09b922: /* original 6ef6, guest PC 0x0c09b922 */
if(!s->budget--) { s->failed_pc=0x0c09b922u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09b924u,s,ram);
P_0c09ba8c: /* original 4f22, guest PC 0x0c09ba8c */
if(!s->budget--) { s->failed_pc=0x0c09ba8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ba8e;
P_0c09ba8e: /* original d335, guest PC 0x0c09ba8e */
if(!s->budget--) { s->failed_pc=0x0c09ba8eu; return 0; }
r[3]=read(ram,0x0c09bb64u,4);
goto P_0c09ba90;
P_0c09ba90: /* original de33, guest PC 0x0c09ba90 */
if(!s->budget--) { s->failed_pc=0x0c09ba90u; return 0; }
r[14]=read(ram,0x0c09bb60u,4);
goto P_0c09ba92;
P_0c09ba92: /* original 7ffc, guest PC 0x0c09ba92 */
if(!s->budget--) { s->failed_pc=0x0c09ba92u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09ba94;
P_0c09ba94: /* original ba6a, guest PC 0x0c09ba94 */
if(!s->budget--) { s->failed_pc=0x0c09ba94u; return 0; }
target=0x0c09af6cu; r[16]=0x0c09ba98u;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ba98u) { target=s->pc; goto dispatch; }
goto P_0c09ba98;
P_0c09ba96: /* original 2f32, guest PC 0x0c09ba96 */
if(!s->budget--) { s->failed_pc=0x0c09ba96u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ba98;
P_0c09ba98: /* original e07d, guest PC 0x0c09ba98 */
if(!s->budget--) { s->failed_pc=0x0c09ba98u; return 0; }
r[0]=0x0000007du;
goto P_0c09ba9a;
P_0c09ba9a: /* original ed00, guest PC 0x0c09ba9a */
if(!s->budget--) { s->failed_pc=0x0c09ba9au; return 0; }
r[13]=0x00000000u;
goto P_0c09ba9c;
P_0c09ba9c: /* original e140, guest PC 0x0c09ba9c */
if(!s->budget--) { s->failed_pc=0x0c09ba9cu; return 0; }
r[1]=0x00000040u;
goto P_0c09ba9e;
P_0c09ba9e: /* original 1e13, guest PC 0x0c09ba9e */
if(!s->budget--) { s->failed_pc=0x0c09ba9eu; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c09baa0;
P_0c09baa0: /* original 1ed6, guest PC 0x0c09baa0 */
if(!s->budget--) { s->failed_pc=0x0c09baa0u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c09baa2;
P_0c09baa2: /* original 0ed4, guest PC 0x0c09baa2 */
if(!s->budget--) { s->failed_pc=0x0c09baa2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09baa4;
P_0c09baa4: /* original 1ed5, guest PC 0x0c09baa4 */
if(!s->budget--) { s->failed_pc=0x0c09baa4u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c09baa6;
P_0c09baa6: /* original 64f2, guest PC 0x0c09baa6 */
if(!s->budget--) { s->failed_pc=0x0c09baa6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09baa8;
P_0c09baa8: /* original d32f, guest PC 0x0c09baa8 */
if(!s->budget--) { s->failed_pc=0x0c09baa8u; return 0; }
r[3]=read(ram,0x0c09bb68u,4);
goto P_0c09baaa;
P_0c09baaa: /* original 430b, guest PC 0x0c09baaa */
if(!s->budget--) { s->failed_pc=0x0c09baaau; return 0; }
target=r[3];
r[16]=0x0c09baaeu;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09baaeu) { target=s->pc; goto dispatch; }
goto P_0c09baae;
P_0c09baac: /* original 7401, guest PC 0x0c09baac */
if(!s->budget--) { s->failed_pc=0x0c09baacu; return 0; }
r[4]+=0x00000001u;
goto P_0c09baae;
P_0c09baae: /* original 9154, guest PC 0x0c09baae */
if(!s->budget--) { s->failed_pc=0x0c09baaeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bb5au,2);
goto P_0c09bab0;
P_0c09bab0: /* original 600c, guest PC 0x0c09bab0 */
if(!s->budget--) { s->failed_pc=0x0c09bab0u; return 0; }
r[0]=r[0]&255u;
goto P_0c09bab2;
P_0c09bab2: /* original 7f04, guest PC 0x0c09bab2 */
if(!s->budget--) { s->failed_pc=0x0c09bab2u; return 0; }
r[15]+=0x00000004u;
goto P_0c09bab4;
P_0c09bab4: /* original 31ec, guest PC 0x0c09bab4 */
if(!s->budget--) { s->failed_pc=0x0c09bab4u; return 0; }
r[1]+=r[14];
goto P_0c09bab6;
P_0c09bab6: /* original 2102, guest PC 0x0c09bab6 */
if(!s->budget--) { s->failed_pc=0x0c09bab6u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c09bab8;
P_0c09bab8: /* original e376, guest PC 0x0c09bab8 */
if(!s->budget--) { s->failed_pc=0x0c09bab8u; return 0; }
r[3]=0x00000076u;
goto P_0c09baba;
P_0c09baba: /* original 904f, guest PC 0x0c09baba */
if(!s->budget--) { s->failed_pc=0x0c09babau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bb5cu,2);
goto P_0c09babc;
P_0c09babc: /* original 4f26, guest PC 0x0c09babc */
if(!s->budget--) { s->failed_pc=0x0c09babcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09babe;
P_0c09babe: /* original 0ed6, guest PC 0x0c09babe */
if(!s->budget--) { s->failed_pc=0x0c09babeu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09bac0;
P_0c09bac0: /* original 84eb, guest PC 0x0c09bac0 */
if(!s->budget--) { s->failed_pc=0x0c09bac0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09bac2;
P_0c09bac2: /* original 7001, guest PC 0x0c09bac2 */
if(!s->budget--) { s->failed_pc=0x0c09bac2u; return 0; }
r[0]+=0x00000001u;
goto P_0c09bac4;
P_0c09bac4: /* original 80eb, guest PC 0x0c09bac4 */
if(!s->budget--) { s->failed_pc=0x0c09bac4u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09bac6;
P_0c09bac6: /* original e010, guest PC 0x0c09bac6 */
if(!s->budget--) { s->failed_pc=0x0c09bac6u; return 0; }
r[0]=0x00000010u;
goto P_0c09bac8;
P_0c09bac8: /* original 0e34, guest PC 0x0c09bac8 */
if(!s->budget--) { s->failed_pc=0x0c09bac8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09baca;
P_0c09baca: /* original 6df6, guest PC 0x0c09baca */
if(!s->budget--) { s->failed_pc=0x0c09bacau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09bacc;
P_0c09bacc: /* original a0a6, guest PC 0x0c09bacc */
if(!s->budget--) { s->failed_pc=0x0c09baccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09bc1c;
P_0c09bace: /* original 6ef6, guest PC 0x0c09bace */
if(!s->budget--) { s->failed_pc=0x0c09baceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09bad0;
P_0c09bad0: /* original 2fe6, guest PC 0x0c09bad0 */
if(!s->budget--) { s->failed_pc=0x0c09bad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bad2;
P_0c09bad2: /* original 6043, guest PC 0x0c09bad2 */
if(!s->budget--) { s->failed_pc=0x0c09bad2u; return 0; }
r[0]=r[4];
goto P_0c09bad4;
P_0c09bad4: /* original 2fd6, guest PC 0x0c09bad4 */
if(!s->budget--) { s->failed_pc=0x0c09bad4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bad6;
P_0c09bad6: /* original 8800, guest PC 0x0c09bad6 */
if(!s->budget--) { s->failed_pc=0x0c09bad6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09bad8;
P_0c09bad8: /* original 2fc6, guest PC 0x0c09bad8 */
if(!s->budget--) { s->failed_pc=0x0c09bad8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bada;
P_0c09bada: /* original 2fb6, guest PC 0x0c09bada */
if(!s->budget--) { s->failed_pc=0x0c09badau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09badc;
P_0c09badc: /* original 2fa6, guest PC 0x0c09badc */
if(!s->budget--) { s->failed_pc=0x0c09badcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c09badeu,s,ram);
P_0c09bc1c: /* original 2fe6, guest PC 0x0c09bc1c */
if(!s->budget--) { s->failed_pc=0x0c09bc1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc1e;
P_0c09bc1e: /* original 2fd6, guest PC 0x0c09bc1e */
if(!s->budget--) { s->failed_pc=0x0c09bc1eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc20;
P_0c09bc20: /* original 2fc6, guest PC 0x0c09bc20 */
if(!s->budget--) { s->failed_pc=0x0c09bc20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc22;
P_0c09bc22: /* original 2fb6, guest PC 0x0c09bc22 */
if(!s->budget--) { s->failed_pc=0x0c09bc22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc24;
P_0c09bc24: /* original 2fa6, guest PC 0x0c09bc24 */
if(!s->budget--) { s->failed_pc=0x0c09bc24u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc26;
P_0c09bc26: /* original ea00, guest PC 0x0c09bc26 */
if(!s->budget--) { s->failed_pc=0x0c09bc26u; return 0; }
r[10]=0x00000000u;
goto P_0c09bc28;
P_0c09bc28: /* original 2f96, guest PC 0x0c09bc28 */
if(!s->budget--) { s->failed_pc=0x0c09bc28u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc2a;
P_0c09bc2a: /* original e902, guest PC 0x0c09bc2a */
if(!s->budget--) { s->failed_pc=0x0c09bc2au; return 0; }
r[9]=0x00000002u;
goto P_0c09bc2c;
P_0c09bc2c: /* original 2f86, guest PC 0x0c09bc2c */
if(!s->budget--) { s->failed_pc=0x0c09bc2cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09bc2e;
P_0c09bc2e: /* original 4f22, guest PC 0x0c09bc2e */
if(!s->budget--) { s->failed_pc=0x0c09bc2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09bc30;
P_0c09bc30: /* original dc33, guest PC 0x0c09bc30 */
if(!s->budget--) { s->failed_pc=0x0c09bc30u; return 0; }
r[12]=read(ram,0x0c09bd00u,4);
goto P_0c09bc32;
P_0c09bc32: /* original de34, guest PC 0x0c09bc32 */
if(!s->budget--) { s->failed_pc=0x0c09bc32u; return 0; }
r[14]=read(ram,0x0c09bd04u,4);
goto P_0c09bc34;
P_0c09bc34: /* original d834, guest PC 0x0c09bc34 */
if(!s->budget--) { s->failed_pc=0x0c09bc34u; return 0; }
r[8]=read(ram,0x0c09bd08u,4);
goto P_0c09bc36;
P_0c09bc36: /* original 7ffc, guest PC 0x0c09bc36 */
if(!s->budget--) { s->failed_pc=0x0c09bc36u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09bc38;
P_0c09bc38: /* original b998, guest PC 0x0c09bc38 */
if(!s->budget--) { s->failed_pc=0x0c09bc38u; return 0; }
target=0x0c09af6cu; r[16]=0x0c09bc3cu;
r[11]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bc3cu) { target=s->pc; goto dispatch; }
goto P_0c09bc3c;
P_0c09bc3a: /* original eb01, guest PC 0x0c09bc3a */
if(!s->budget--) { s->failed_pc=0x0c09bc3au; return 0; }
r[11]=0x00000001u;
goto P_0c09bc3c;
P_0c09bc3c: /* original 6d03, guest PC 0x0c09bc3c */
if(!s->budget--) { s->failed_pc=0x0c09bc3cu; return 0; }
r[13]=r[0];
goto P_0c09bc3e;
P_0c09bc3e: /* original e07d, guest PC 0x0c09bc3e */
if(!s->budget--) { s->failed_pc=0x0c09bc3eu; return 0; }
r[0]=0x0000007du;
goto P_0c09bc40;
P_0c09bc40: /* original e240, guest PC 0x0c09bc40 */
if(!s->budget--) { s->failed_pc=0x0c09bc40u; return 0; }
r[2]=0x00000040u;
goto P_0c09bc42;
P_0c09bc42: /* original 1e23, guest PC 0x0c09bc42 */
if(!s->budget--) { s->failed_pc=0x0c09bc42u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09bc44;
P_0c09bc44: /* original e210, guest PC 0x0c09bc44 */
if(!s->budget--) { s->failed_pc=0x0c09bc44u; return 0; }
r[2]=0x00000010u;
goto P_0c09bc46;
P_0c09bc46: /* original 22d8, guest PC 0x0c09bc46 */
if(!s->budget--) { s->failed_pc=0x0c09bc46u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09bc48;
P_0c09bc48: /* original 1ea6, guest PC 0x0c09bc48 */
if(!s->budget--) { s->failed_pc=0x0c09bc48u; return 0; }
write(ram,r[14]+24,r[10],4);
goto P_0c09bc4a;
P_0c09bc4a: /* original 0ea4, guest PC 0x0c09bc4a */
if(!s->budget--) { s->failed_pc=0x0c09bc4au; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c09bc4c;
P_0c09bc4c: /* original 1ea5, guest PC 0x0c09bc4c */
if(!s->budget--) { s->failed_pc=0x0c09bc4cu; return 0; }
write(ram,r[14]+20,r[10],4);
goto P_0c09bc4e;
P_0c09bc4e: /* original 9053, guest PC 0x0c09bc4e */
if(!s->budget--) { s->failed_pc=0x0c09bc4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcf8u,2);
goto P_0c09bc50;
P_0c09bc50: /* original 03ee, guest PC 0x0c09bc50 */
if(!s->budget--) { s->failed_pc=0x0c09bc50u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bc52;
P_0c09bc52: /* original 2f32, guest PC 0x0c09bc52 */
if(!s->budget--) { s->failed_pc=0x0c09bc52u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09bc54;
P_0c09bc54: /* original 890b, guest PC 0x0c09bc54 */
if(!s->budget--) { s->failed_pc=0x0c09bc54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bc6e; }
goto P_0c09bc56;
P_0c09bc56: /* original 9450, guest PC 0x0c09bc56 */
if(!s->budget--) { s->failed_pc=0x0c09bc56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcfau,2);
goto P_0c09bc58;
P_0c09bc58: /* original 4c0b, guest PC 0x0c09bc58 */
if(!s->budget--) { s->failed_pc=0x0c09bc58u; return 0; }
target=r[12];
r[16]=0x0c09bc5cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bc5cu) { target=s->pc; goto dispatch; }
goto P_0c09bc5c;
P_0c09bc5a: /* original 0009, guest PC 0x0c09bc5a */
if(!s->budget--) { s->failed_pc=0x0c09bc5au; return 0; }
goto P_0c09bc5c;
P_0c09bc5c: /* original 904c, guest PC 0x0c09bc5c */
if(!s->budget--) { s->failed_pc=0x0c09bc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcf8u,2);
goto P_0c09bc5e;
P_0c09bc5e: /* original 02ee, guest PC 0x0c09bc5e */
if(!s->budget--) { s->failed_pc=0x0c09bc5eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bc60;
P_0c09bc60: /* original 72ff, guest PC 0x0c09bc60 */
if(!s->budget--) { s->failed_pc=0x0c09bc60u; return 0; }
r[2]+=0xffffffffu;
goto P_0c09bc62;
P_0c09bc62: /* original 0e26, guest PC 0x0c09bc62 */
if(!s->budget--) { s->failed_pc=0x0c09bc62u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bc64;
P_0c09bc64: /* original 03ee, guest PC 0x0c09bc64 */
if(!s->budget--) { s->failed_pc=0x0c09bc64u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bc66;
P_0c09bc66: /* original 4311, guest PC 0x0c09bc66 */
if(!s->budget--) { s->failed_pc=0x0c09bc66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c09bc68;
P_0c09bc68: /* original 8901, guest PC 0x0c09bc68 */
if(!s->budget--) { s->failed_pc=0x0c09bc68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bc6e; }
goto P_0c09bc6a;
P_0c09bc6a: /* original e10b, guest PC 0x0c09bc6a */
if(!s->budget--) { s->failed_pc=0x0c09bc6au; return 0; }
r[1]=0x0000000bu;
goto P_0c09bc6c;
P_0c09bc6c: /* original 0e16, guest PC 0x0c09bc6c */
if(!s->budget--) { s->failed_pc=0x0c09bc6cu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09bc6e;
P_0c09bc6e: /* original e320, guest PC 0x0c09bc6e */
if(!s->budget--) { s->failed_pc=0x0c09bc6eu; return 0; }
r[3]=0x00000020u;
goto P_0c09bc70;
P_0c09bc70: /* original 23d8, guest PC 0x0c09bc70 */
if(!s->budget--) { s->failed_pc=0x0c09bc70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09bc72;
P_0c09bc72: /* original 890b, guest PC 0x0c09bc72 */
if(!s->budget--) { s->failed_pc=0x0c09bc72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bc8c; }
goto P_0c09bc74;
P_0c09bc74: /* original 9441, guest PC 0x0c09bc74 */
if(!s->budget--) { s->failed_pc=0x0c09bc74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcfau,2);
goto P_0c09bc76;
P_0c09bc76: /* original 4c0b, guest PC 0x0c09bc76 */
if(!s->budget--) { s->failed_pc=0x0c09bc76u; return 0; }
target=r[12];
r[16]=0x0c09bc7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bc7au) { target=s->pc; goto dispatch; }
goto P_0c09bc7a;
P_0c09bc78: /* original 0009, guest PC 0x0c09bc78 */
if(!s->budget--) { s->failed_pc=0x0c09bc78u; return 0; }
goto P_0c09bc7a;
P_0c09bc7a: /* original 903d, guest PC 0x0c09bc7a */
if(!s->budget--) { s->failed_pc=0x0c09bc7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcf8u,2);
goto P_0c09bc7c;
P_0c09bc7c: /* original e20c, guest PC 0x0c09bc7c */
if(!s->budget--) { s->failed_pc=0x0c09bc7cu; return 0; }
r[2]=0x0000000cu;
goto P_0c09bc7e;
P_0c09bc7e: /* original 03ee, guest PC 0x0c09bc7e */
if(!s->budget--) { s->failed_pc=0x0c09bc7eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bc80;
P_0c09bc80: /* original 7301, guest PC 0x0c09bc80 */
if(!s->budget--) { s->failed_pc=0x0c09bc80u; return 0; }
r[3]+=0x00000001u;
goto P_0c09bc82;
P_0c09bc82: /* original 0e36, guest PC 0x0c09bc82 */
if(!s->budget--) { s->failed_pc=0x0c09bc82u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09bc84;
P_0c09bc84: /* original 01ee, guest PC 0x0c09bc84 */
if(!s->budget--) { s->failed_pc=0x0c09bc84u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bc86;
P_0c09bc86: /* original 3123, guest PC 0x0c09bc86 */
if(!s->budget--) { s->failed_pc=0x0c09bc86u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09bc88;
P_0c09bc88: /* original 8b00, guest PC 0x0c09bc88 */
if(!s->budget--) { s->failed_pc=0x0c09bc88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09bc8c; }
goto P_0c09bc8a;
P_0c09bc8a: /* original 0ea6, guest PC 0x0c09bc8a */
if(!s->budget--) { s->failed_pc=0x0c09bc8au; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09bc8c;
P_0c09bc8c: /* original 9034, guest PC 0x0c09bc8c */
if(!s->budget--) { s->failed_pc=0x0c09bc8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcf8u,2);
goto P_0c09bc8e;
P_0c09bc8e: /* original 62f2, guest PC 0x0c09bc8e */
if(!s->budget--) { s->failed_pc=0x0c09bc8eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09bc90;
P_0c09bc90: /* original 03ee, guest PC 0x0c09bc90 */
if(!s->budget--) { s->failed_pc=0x0c09bc90u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bc92;
P_0c09bc92: /* original 3230, guest PC 0x0c09bc92 */
if(!s->budget--) { s->failed_pc=0x0c09bc92u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c09bc94;
P_0c09bc94: /* original 8903, guest PC 0x0c09bc94 */
if(!s->budget--) { s->failed_pc=0x0c09bc94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bc9e; }
goto P_0c09bc96;
P_0c09bc96: /* original 9031, guest PC 0x0c09bc96 */
if(!s->budget--) { s->failed_pc=0x0c09bc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcfcu,2);
goto P_0c09bc98;
P_0c09bc98: /* original 05ee, guest PC 0x0c09bc98 */
if(!s->budget--) { s->failed_pc=0x0c09bc98u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c09bc9a;
P_0c09bc9a: /* original bf19, guest PC 0x0c09bc9a */
if(!s->budget--) { s->failed_pc=0x0c09bc9au; return 0; }
target=0x0c09bad0u; r[16]=0x0c09bc9eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bc9eu) { target=s->pc; goto dispatch; }
goto P_0c09bc9e;
P_0c09bc9c: /* original 64f2, guest PC 0x0c09bc9c */
if(!s->budget--) { s->failed_pc=0x0c09bc9cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09bc9e;
P_0c09bc9e: /* original e240, guest PC 0x0c09bc9e */
if(!s->budget--) { s->failed_pc=0x0c09bc9eu; return 0; }
r[2]=0x00000040u;
goto P_0c09bca0;
P_0c09bca0: /* original 22d8, guest PC 0x0c09bca0 */
if(!s->budget--) { s->failed_pc=0x0c09bca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09bca2;
P_0c09bca2: /* original 895e, guest PC 0x0c09bca2 */
if(!s->budget--) { s->failed_pc=0x0c09bca2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd62; }
goto P_0c09bca4;
P_0c09bca4: /* original 4c0b, guest PC 0x0c09bca4 */
if(!s->budget--) { s->failed_pc=0x0c09bca4u; return 0; }
target=r[12];
r[16]=0x0c09bca8u;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bca8u) { target=s->pc; goto dispatch; }
goto P_0c09bca8;
P_0c09bca6: /* original e47f, guest PC 0x0c09bca6 */
if(!s->budget--) { s->failed_pc=0x0c09bca6u; return 0; }
r[4]=0x0000007fu;
goto P_0c09bca8;
P_0c09bca8: /* original 9026, guest PC 0x0c09bca8 */
if(!s->budget--) { s->failed_pc=0x0c09bca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcf8u,2);
goto P_0c09bcaa;
P_0c09bcaa: /* original 00ee, guest PC 0x0c09bcaa */
if(!s->budget--) { s->failed_pc=0x0c09bcaau; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09bcac;
P_0c09bcac: /* original 8800, guest PC 0x0c09bcac */
if(!s->budget--) { s->failed_pc=0x0c09bcacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09bcae;
P_0c09bcae: /* original 890f, guest PC 0x0c09bcae */
if(!s->budget--) { s->failed_pc=0x0c09bcaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bcd0; }
goto P_0c09bcb0;
P_0c09bcb0: /* original 8801, guest PC 0x0c09bcb0 */
if(!s->budget--) { s->failed_pc=0x0c09bcb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09bcb2;
P_0c09bcb2: /* original 8917, guest PC 0x0c09bcb2 */
if(!s->budget--) { s->failed_pc=0x0c09bcb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bce4; }
goto P_0c09bcb4;
P_0c09bcb4: /* original 8802, guest PC 0x0c09bcb4 */
if(!s->budget--) { s->failed_pc=0x0c09bcb4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09bcb6;
P_0c09bcb6: /* original 8915, guest PC 0x0c09bcb6 */
if(!s->budget--) { s->failed_pc=0x0c09bcb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bce4; }
goto P_0c09bcb8;
P_0c09bcb8: /* original 8803, guest PC 0x0c09bcb8 */
if(!s->budget--) { s->failed_pc=0x0c09bcb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09bcba;
P_0c09bcba: /* original 8927, guest PC 0x0c09bcba */
if(!s->budget--) { s->failed_pc=0x0c09bcbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd0c; }
goto P_0c09bcbc;
P_0c09bcbc: /* original 8804, guest PC 0x0c09bcbc */
if(!s->budget--) { s->failed_pc=0x0c09bcbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09bcbe;
P_0c09bcbe: /* original 8925, guest PC 0x0c09bcbe */
if(!s->budget--) { s->failed_pc=0x0c09bcbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd0c; }
goto P_0c09bcc0;
P_0c09bcc0: /* original 8805, guest PC 0x0c09bcc0 */
if(!s->budget--) { s->failed_pc=0x0c09bcc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09bcc2;
P_0c09bcc2: /* original 892e, guest PC 0x0c09bcc2 */
if(!s->budget--) { s->failed_pc=0x0c09bcc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd22; }
goto P_0c09bcc4;
P_0c09bcc4: /* original 8806, guest PC 0x0c09bcc4 */
if(!s->budget--) { s->failed_pc=0x0c09bcc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09bcc6;
P_0c09bcc6: /* original 8935, guest PC 0x0c09bcc6 */
if(!s->budget--) { s->failed_pc=0x0c09bcc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd34; }
goto P_0c09bcc8;
P_0c09bcc8: /* original 8807, guest PC 0x0c09bcc8 */
if(!s->budget--) { s->failed_pc=0x0c09bcc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09bcca;
P_0c09bcca: /* original 893c, guest PC 0x0c09bcca */
if(!s->budget--) { s->failed_pc=0x0c09bccau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd46; }
goto P_0c09bccc;
P_0c09bccc: /* original a044, guest PC 0x0c09bccc */
if(!s->budget--) { s->failed_pc=0x0c09bcccu; return 0; }
goto P_0c09bd58;
P_0c09bcce: /* original 0009, guest PC 0x0c09bcce */
if(!s->budget--) { s->failed_pc=0x0c09bcceu; return 0; }
goto P_0c09bcd0;
P_0c09bcd0: /* original 9014, guest PC 0x0c09bcd0 */
if(!s->budget--) { s->failed_pc=0x0c09bcd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcfcu,2);
goto P_0c09bcd2;
P_0c09bcd2: /* original 03ee, guest PC 0x0c09bcd2 */
if(!s->budget--) { s->failed_pc=0x0c09bcd2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bcd4;
P_0c09bcd4: /* original 73ff, guest PC 0x0c09bcd4 */
if(!s->budget--) { s->failed_pc=0x0c09bcd4u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09bcd6;
P_0c09bcd6: /* original 0e36, guest PC 0x0c09bcd6 */
if(!s->budget--) { s->failed_pc=0x0c09bcd6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09bcd8;
P_0c09bcd8: /* original 02ee, guest PC 0x0c09bcd8 */
if(!s->budget--) { s->failed_pc=0x0c09bcd8u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bcda;
P_0c09bcda: /* original 3293, guest PC 0x0c09bcda */
if(!s->budget--) { s->failed_pc=0x0c09bcdau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[9])!=0);
goto P_0c09bcdc;
P_0c09bcdc: /* original 893c, guest PC 0x0c09bcdc */
if(!s->budget--) { s->failed_pc=0x0c09bcdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd58; }
goto P_0c09bcde;
P_0c09bcde: /* original e105, guest PC 0x0c09bcde */
if(!s->budget--) { s->failed_pc=0x0c09bcdeu; return 0; }
r[1]=0x00000005u;
goto P_0c09bce0;
P_0c09bce0: /* original a03a, guest PC 0x0c09bce0 */
if(!s->budget--) { s->failed_pc=0x0c09bce0u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09bd58;
P_0c09bce2: /* original 0e16, guest PC 0x0c09bce2 */
if(!s->budget--) { s->failed_pc=0x0c09bce2u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09bce4;
P_0c09bce4: /* original 900a, guest PC 0x0c09bce4 */
if(!s->budget--) { s->failed_pc=0x0c09bce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bcfcu,2);
goto P_0c09bce6;
P_0c09bce6: /* original 02ee, guest PC 0x0c09bce6 */
if(!s->budget--) { s->failed_pc=0x0c09bce6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bce8;
P_0c09bce8: /* original 72ff, guest PC 0x0c09bce8 */
if(!s->budget--) { s->failed_pc=0x0c09bce8u; return 0; }
r[2]+=0xffffffffu;
goto P_0c09bcea;
P_0c09bcea: /* original 0e26, guest PC 0x0c09bcea */
if(!s->budget--) { s->failed_pc=0x0c09bceau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bcec;
P_0c09bcec: /* original 03ee, guest PC 0x0c09bcec */
if(!s->budget--) { s->failed_pc=0x0c09bcecu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bcee;
P_0c09bcee: /* original 4311, guest PC 0x0c09bcee */
if(!s->budget--) { s->failed_pc=0x0c09bceeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c09bcf0;
P_0c09bcf0: /* original 8932, guest PC 0x0c09bcf0 */
if(!s->budget--) { s->failed_pc=0x0c09bcf0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd58; }
goto P_0c09bcf2;
P_0c09bcf2: /* original e103, guest PC 0x0c09bcf2 */
if(!s->budget--) { s->failed_pc=0x0c09bcf2u; return 0; }
r[1]=0x00000003u;
goto P_0c09bcf4;
P_0c09bcf4: /* original a030, guest PC 0x0c09bcf4 */
if(!s->budget--) { s->failed_pc=0x0c09bcf4u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09bd58;
P_0c09bcf6: /* original 0e16, guest PC 0x0c09bcf6 */
if(!s->budget--) { s->failed_pc=0x0c09bcf6u; return 0; }
write(ram,r[14]+r[0],r[1],4);
return vf3_matrix_family(0x0c09bcf8u,s,ram);
P_0c09bd0c: /* original 9060, guest PC 0x0c09bd0c */
if(!s->budget--) { s->failed_pc=0x0c09bd0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd0e;
P_0c09bd0e: /* original 02ee, guest PC 0x0c09bd0e */
if(!s->budget--) { s->failed_pc=0x0c09bd0eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bd10;
P_0c09bd10: /* original 72ec, guest PC 0x0c09bd10 */
if(!s->budget--) { s->failed_pc=0x0c09bd10u; return 0; }
r[2]+=0xffffffecu;
goto P_0c09bd12;
P_0c09bd12: /* original 0e26, guest PC 0x0c09bd12 */
if(!s->budget--) { s->failed_pc=0x0c09bd12u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bd14;
P_0c09bd14: /* original 935d, guest PC 0x0c09bd14 */
if(!s->budget--) { s->failed_pc=0x0c09bd14u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd2u,2);
goto P_0c09bd16;
P_0c09bd16: /* original 01ee, guest PC 0x0c09bd16 */
if(!s->budget--) { s->failed_pc=0x0c09bd16u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bd18;
P_0c09bd18: /* original 3133, guest PC 0x0c09bd18 */
if(!s->budget--) { s->failed_pc=0x0c09bd18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c09bd1a;
P_0c09bd1a: /* original 891d, guest PC 0x0c09bd1a */
if(!s->budget--) { s->failed_pc=0x0c09bd1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd58; }
goto P_0c09bd1c;
P_0c09bd1c: /* original 925a, guest PC 0x0c09bd1c */
if(!s->budget--) { s->failed_pc=0x0c09bd1cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd4u,2);
goto P_0c09bd1e;
P_0c09bd1e: /* original a01b, guest PC 0x0c09bd1e */
if(!s->budget--) { s->failed_pc=0x0c09bd1eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bd58;
P_0c09bd20: /* original 0e26, guest PC 0x0c09bd20 */
if(!s->budget--) { s->failed_pc=0x0c09bd20u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bd22;
P_0c09bd22: /* original 9055, guest PC 0x0c09bd22 */
if(!s->budget--) { s->failed_pc=0x0c09bd22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd24;
P_0c09bd24: /* original 02ee, guest PC 0x0c09bd24 */
if(!s->budget--) { s->failed_pc=0x0c09bd24u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bd26;
P_0c09bd26: /* original 72ff, guest PC 0x0c09bd26 */
if(!s->budget--) { s->failed_pc=0x0c09bd26u; return 0; }
r[2]+=0xffffffffu;
goto P_0c09bd28;
P_0c09bd28: /* original 0e26, guest PC 0x0c09bd28 */
if(!s->budget--) { s->failed_pc=0x0c09bd28u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bd2a;
P_0c09bd2a: /* original 03ee, guest PC 0x0c09bd2a */
if(!s->budget--) { s->failed_pc=0x0c09bd2au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bd2c;
P_0c09bd2c: /* original 4311, guest PC 0x0c09bd2c */
if(!s->budget--) { s->failed_pc=0x0c09bd2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c09bd2e;
P_0c09bd2e: /* original 8b11, guest PC 0x0c09bd2e */
if(!s->budget--) { s->failed_pc=0x0c09bd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09bd54; }
goto P_0c09bd30;
P_0c09bd30: /* original a012, guest PC 0x0c09bd30 */
if(!s->budget--) { s->failed_pc=0x0c09bd30u; return 0; }
goto P_0c09bd58;
P_0c09bd32: /* original 0009, guest PC 0x0c09bd32 */
if(!s->budget--) { s->failed_pc=0x0c09bd32u; return 0; }
goto P_0c09bd34;
P_0c09bd34: /* original 904c, guest PC 0x0c09bd34 */
if(!s->budget--) { s->failed_pc=0x0c09bd34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd36;
P_0c09bd36: /* original 03ee, guest PC 0x0c09bd36 */
if(!s->budget--) { s->failed_pc=0x0c09bd36u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bd38;
P_0c09bd38: /* original 73ff, guest PC 0x0c09bd38 */
if(!s->budget--) { s->failed_pc=0x0c09bd38u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09bd3a;
P_0c09bd3a: /* original 0e36, guest PC 0x0c09bd3a */
if(!s->budget--) { s->failed_pc=0x0c09bd3au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09bd3c;
P_0c09bd3c: /* original 02ee, guest PC 0x0c09bd3c */
if(!s->budget--) { s->failed_pc=0x0c09bd3cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bd3e;
P_0c09bd3e: /* original 4211, guest PC 0x0c09bd3e */
if(!s->budget--) { s->failed_pc=0x0c09bd3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09bd40;
P_0c09bd40: /* original 890a, guest PC 0x0c09bd40 */
if(!s->budget--) { s->failed_pc=0x0c09bd40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd58; }
goto P_0c09bd42;
P_0c09bd42: /* original a009, guest PC 0x0c09bd42 */
if(!s->budget--) { s->failed_pc=0x0c09bd42u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09bd58;
P_0c09bd44: /* original 0e96, guest PC 0x0c09bd44 */
if(!s->budget--) { s->failed_pc=0x0c09bd44u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09bd46;
P_0c09bd46: /* original 9043, guest PC 0x0c09bd46 */
if(!s->budget--) { s->failed_pc=0x0c09bd46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd48;
P_0c09bd48: /* original 02ee, guest PC 0x0c09bd48 */
if(!s->budget--) { s->failed_pc=0x0c09bd48u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bd4a;
P_0c09bd4a: /* original 72ff, guest PC 0x0c09bd4a */
if(!s->budget--) { s->failed_pc=0x0c09bd4au; return 0; }
r[2]+=0xffffffffu;
goto P_0c09bd4c;
P_0c09bd4c: /* original 0e26, guest PC 0x0c09bd4c */
if(!s->budget--) { s->failed_pc=0x0c09bd4cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bd4e;
P_0c09bd4e: /* original 03ee, guest PC 0x0c09bd4e */
if(!s->budget--) { s->failed_pc=0x0c09bd4eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bd50;
P_0c09bd50: /* original 4311, guest PC 0x0c09bd50 */
if(!s->budget--) { s->failed_pc=0x0c09bd50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c09bd52;
P_0c09bd52: /* original 8901, guest PC 0x0c09bd52 */
if(!s->budget--) { s->failed_pc=0x0c09bd52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd58; }
goto P_0c09bd54;
P_0c09bd54: /* original 903c, guest PC 0x0c09bd54 */
if(!s->budget--) { s->failed_pc=0x0c09bd54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd56;
P_0c09bd56: /* original 0eb6, guest PC 0x0c09bd56 */
if(!s->budget--) { s->failed_pc=0x0c09bd56u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09bd58;
P_0c09bd58: /* original 903a, guest PC 0x0c09bd58 */
if(!s->budget--) { s->failed_pc=0x0c09bd58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd5a;
P_0c09bd5a: /* original 05ee, guest PC 0x0c09bd5a */
if(!s->budget--) { s->failed_pc=0x0c09bd5au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c09bd5c;
P_0c09bd5c: /* original 7004, guest PC 0x0c09bd5c */
if(!s->budget--) { s->failed_pc=0x0c09bd5cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09bd5e;
P_0c09bd5e: /* original beb7, guest PC 0x0c09bd5e */
if(!s->budget--) { s->failed_pc=0x0c09bd5eu; return 0; }
target=0x0c09bad0u; r[16]=0x0c09bd62u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bd62u) { target=s->pc; goto dispatch; }
goto P_0c09bd62;
P_0c09bd60: /* original 04ee, guest PC 0x0c09bd60 */
if(!s->budget--) { s->failed_pc=0x0c09bd60u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09bd62;
P_0c09bd62: /* original 9238, guest PC 0x0c09bd62 */
if(!s->budget--) { s->failed_pc=0x0c09bd62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd6u,2);
goto P_0c09bd64;
P_0c09bd64: /* original 22d8, guest PC 0x0c09bd64 */
if(!s->budget--) { s->failed_pc=0x0c09bd64u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09bd66;
P_0c09bd66: /* original 8963, guest PC 0x0c09bd66 */
if(!s->budget--) { s->failed_pc=0x0c09bd66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be30; }
goto P_0c09bd68;
P_0c09bd68: /* original 4c0b, guest PC 0x0c09bd68 */
if(!s->budget--) { s->failed_pc=0x0c09bd68u; return 0; }
target=r[12];
r[16]=0x0c09bd6cu;
r[4]=0x0000007fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bd6cu) { target=s->pc; goto dispatch; }
goto P_0c09bd6c;
P_0c09bd6a: /* original e47f, guest PC 0x0c09bd6a */
if(!s->budget--) { s->failed_pc=0x0c09bd6au; return 0; }
r[4]=0x0000007fu;
goto P_0c09bd6c;
P_0c09bd6c: /* original 9034, guest PC 0x0c09bd6c */
if(!s->budget--) { s->failed_pc=0x0c09bd6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd8u,2);
goto P_0c09bd6e;
P_0c09bd6e: /* original 00ee, guest PC 0x0c09bd6e */
if(!s->budget--) { s->failed_pc=0x0c09bd6eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09bd70;
P_0c09bd70: /* original 8800, guest PC 0x0c09bd70 */
if(!s->budget--) { s->failed_pc=0x0c09bd70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09bd72;
P_0c09bd72: /* original 890f, guest PC 0x0c09bd72 */
if(!s->budget--) { s->failed_pc=0x0c09bd72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bd94; }
goto P_0c09bd74;
P_0c09bd74: /* original 8801, guest PC 0x0c09bd74 */
if(!s->budget--) { s->failed_pc=0x0c09bd74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09bd76;
P_0c09bd76: /* original 8917, guest PC 0x0c09bd76 */
if(!s->budget--) { s->failed_pc=0x0c09bd76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bda8; }
goto P_0c09bd78;
P_0c09bd78: /* original 8802, guest PC 0x0c09bd78 */
if(!s->budget--) { s->failed_pc=0x0c09bd78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09bd7a;
P_0c09bd7a: /* original 891f, guest PC 0x0c09bd7a */
if(!s->budget--) { s->failed_pc=0x0c09bd7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bdbc; }
goto P_0c09bd7c;
P_0c09bd7c: /* original 8803, guest PC 0x0c09bd7c */
if(!s->budget--) { s->failed_pc=0x0c09bd7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09bd7e;
P_0c09bd7e: /* original 892c, guest PC 0x0c09bd7e */
if(!s->budget--) { s->failed_pc=0x0c09bd7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bdda; }
goto P_0c09bd80;
P_0c09bd80: /* original 8804, guest PC 0x0c09bd80 */
if(!s->budget--) { s->failed_pc=0x0c09bd80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09bd82;
P_0c09bd82: /* original 892a, guest PC 0x0c09bd82 */
if(!s->budget--) { s->failed_pc=0x0c09bd82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bdda; }
goto P_0c09bd84;
P_0c09bd84: /* original 8805, guest PC 0x0c09bd84 */
if(!s->budget--) { s->failed_pc=0x0c09bd84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09bd86;
P_0c09bd86: /* original 8933, guest PC 0x0c09bd86 */
if(!s->budget--) { s->failed_pc=0x0c09bd86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bdf0; }
goto P_0c09bd88;
P_0c09bd88: /* original 8806, guest PC 0x0c09bd88 */
if(!s->budget--) { s->failed_pc=0x0c09bd88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09bd8a;
P_0c09bd8a: /* original 893a, guest PC 0x0c09bd8a */
if(!s->budget--) { s->failed_pc=0x0c09bd8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be02; }
goto P_0c09bd8c;
P_0c09bd8c: /* original 8807, guest PC 0x0c09bd8c */
if(!s->budget--) { s->failed_pc=0x0c09bd8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09bd8e;
P_0c09bd8e: /* original 8941, guest PC 0x0c09bd8e */
if(!s->budget--) { s->failed_pc=0x0c09bd8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be14; }
goto P_0c09bd90;
P_0c09bd90: /* original a049, guest PC 0x0c09bd90 */
if(!s->budget--) { s->failed_pc=0x0c09bd90u; return 0; }
goto P_0c09be26;
P_0c09bd92: /* original 0009, guest PC 0x0c09bd92 */
if(!s->budget--) { s->failed_pc=0x0c09bd92u; return 0; }
goto P_0c09bd94;
P_0c09bd94: /* original 901c, guest PC 0x0c09bd94 */
if(!s->budget--) { s->failed_pc=0x0c09bd94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bd96;
P_0c09bd96: /* original e205, guest PC 0x0c09bd96 */
if(!s->budget--) { s->failed_pc=0x0c09bd96u; return 0; }
r[2]=0x00000005u;
goto P_0c09bd98;
P_0c09bd98: /* original 03ee, guest PC 0x0c09bd98 */
if(!s->budget--) { s->failed_pc=0x0c09bd98u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bd9a;
P_0c09bd9a: /* original 7301, guest PC 0x0c09bd9a */
if(!s->budget--) { s->failed_pc=0x0c09bd9au; return 0; }
r[3]+=0x00000001u;
goto P_0c09bd9c;
P_0c09bd9c: /* original 0e36, guest PC 0x0c09bd9c */
if(!s->budget--) { s->failed_pc=0x0c09bd9cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09bd9e;
P_0c09bd9e: /* original 01ee, guest PC 0x0c09bd9e */
if(!s->budget--) { s->failed_pc=0x0c09bd9eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bda0;
P_0c09bda0: /* original 3127, guest PC 0x0c09bda0 */
if(!s->budget--) { s->failed_pc=0x0c09bda0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c09bda2;
P_0c09bda2: /* original 8b40, guest PC 0x0c09bda2 */
if(!s->budget--) { s->failed_pc=0x0c09bda2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09bda4;
P_0c09bda4: /* original a03f, guest PC 0x0c09bda4 */
if(!s->budget--) { s->failed_pc=0x0c09bda4u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09be26;
P_0c09bda6: /* original 0e96, guest PC 0x0c09bda6 */
if(!s->budget--) { s->failed_pc=0x0c09bda6u; return 0; }
write(ram,r[14]+r[0],r[9],4);
goto P_0c09bda8;
P_0c09bda8: /* original 9012, guest PC 0x0c09bda8 */
if(!s->budget--) { s->failed_pc=0x0c09bda8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bdaa;
P_0c09bdaa: /* original e303, guest PC 0x0c09bdaa */
if(!s->budget--) { s->failed_pc=0x0c09bdaau; return 0; }
r[3]=0x00000003u;
goto P_0c09bdac;
P_0c09bdac: /* original 02ee, guest PC 0x0c09bdac */
if(!s->budget--) { s->failed_pc=0x0c09bdacu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bdae;
P_0c09bdae: /* original 7201, guest PC 0x0c09bdae */
if(!s->budget--) { s->failed_pc=0x0c09bdaeu; return 0; }
r[2]+=0x00000001u;
goto P_0c09bdb0;
P_0c09bdb0: /* original 0e26, guest PC 0x0c09bdb0 */
if(!s->budget--) { s->failed_pc=0x0c09bdb0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bdb2;
P_0c09bdb2: /* original 01ee, guest PC 0x0c09bdb2 */
if(!s->budget--) { s->failed_pc=0x0c09bdb2u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bdb4;
P_0c09bdb4: /* original 3137, guest PC 0x0c09bdb4 */
if(!s->budget--) { s->failed_pc=0x0c09bdb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09bdb6;
P_0c09bdb6: /* original 8934, guest PC 0x0c09bdb6 */
if(!s->budget--) { s->failed_pc=0x0c09bdb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be22; }
goto P_0c09bdb8;
P_0c09bdb8: /* original a035, guest PC 0x0c09bdb8 */
if(!s->budget--) { s->failed_pc=0x0c09bdb8u; return 0; }
goto P_0c09be26;
P_0c09bdba: /* original 0009, guest PC 0x0c09bdba */
if(!s->budget--) { s->failed_pc=0x0c09bdbau; return 0; }
goto P_0c09bdbc;
P_0c09bdbc: /* original 9008, guest PC 0x0c09bdbc */
if(!s->budget--) { s->failed_pc=0x0c09bdbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bdd0u,2);
goto P_0c09bdbe;
P_0c09bdbe: /* original e203, guest PC 0x0c09bdbe */
if(!s->budget--) { s->failed_pc=0x0c09bdbeu; return 0; }
r[2]=0x00000003u;
goto P_0c09bdc0;
P_0c09bdc0: /* original 03ee, guest PC 0x0c09bdc0 */
if(!s->budget--) { s->failed_pc=0x0c09bdc0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bdc2;
P_0c09bdc2: /* original 7301, guest PC 0x0c09bdc2 */
if(!s->budget--) { s->failed_pc=0x0c09bdc2u; return 0; }
r[3]+=0x00000001u;
goto P_0c09bdc4;
P_0c09bdc4: /* original 0e36, guest PC 0x0c09bdc4 */
if(!s->budget--) { s->failed_pc=0x0c09bdc4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09bdc6;
P_0c09bdc6: /* original 01ee, guest PC 0x0c09bdc6 */
if(!s->budget--) { s->failed_pc=0x0c09bdc6u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bdc8;
P_0c09bdc8: /* original 3127, guest PC 0x0c09bdc8 */
if(!s->budget--) { s->failed_pc=0x0c09bdc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c09bdca;
P_0c09bdca: /* original 8b2c, guest PC 0x0c09bdca */
if(!s->budget--) { s->failed_pc=0x0c09bdcau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09bdcc;
P_0c09bdcc: /* original a029, guest PC 0x0c09bdcc */
if(!s->budget--) { s->failed_pc=0x0c09bdccu; return 0; }
goto P_0c09be22;
P_0c09bdce: /* original 0009, guest PC 0x0c09bdce */
if(!s->budget--) { s->failed_pc=0x0c09bdceu; return 0; }
return vf3_matrix_family(0x0c09bdd0u,s,ram);
P_0c09bdda: /* original 906d, guest PC 0x0c09bdda */
if(!s->budget--) { s->failed_pc=0x0c09bddau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09bddc;
P_0c09bddc: /* original 02ee, guest PC 0x0c09bddc */
if(!s->budget--) { s->failed_pc=0x0c09bddcu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bdde;
P_0c09bdde: /* original 7214, guest PC 0x0c09bdde */
if(!s->budget--) { s->failed_pc=0x0c09bddeu; return 0; }
r[2]+=0x00000014u;
goto P_0c09bde0;
P_0c09bde0: /* original 0e26, guest PC 0x0c09bde0 */
if(!s->budget--) { s->failed_pc=0x0c09bde0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bde2;
P_0c09bde2: /* original 936a, guest PC 0x0c09bde2 */
if(!s->budget--) { s->failed_pc=0x0c09bde2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bebau,2);
goto P_0c09bde4;
P_0c09bde4: /* original 01ee, guest PC 0x0c09bde4 */
if(!s->budget--) { s->failed_pc=0x0c09bde4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09bde6;
P_0c09bde6: /* original 3137, guest PC 0x0c09bde6 */
if(!s->budget--) { s->failed_pc=0x0c09bde6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09bde8;
P_0c09bde8: /* original 8b1d, guest PC 0x0c09bde8 */
if(!s->budget--) { s->failed_pc=0x0c09bde8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09bdea;
P_0c09bdea: /* original 9267, guest PC 0x0c09bdea */
if(!s->budget--) { s->failed_pc=0x0c09bdeau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bebcu,2);
goto P_0c09bdec;
P_0c09bdec: /* original a01b, guest PC 0x0c09bdec */
if(!s->budget--) { s->failed_pc=0x0c09bdecu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09be26;
P_0c09bdee: /* original 0e26, guest PC 0x0c09bdee */
if(!s->budget--) { s->failed_pc=0x0c09bdeeu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bdf0;
P_0c09bdf0: /* original 9062, guest PC 0x0c09bdf0 */
if(!s->budget--) { s->failed_pc=0x0c09bdf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09bdf2;
P_0c09bdf2: /* original 02ee, guest PC 0x0c09bdf2 */
if(!s->budget--) { s->failed_pc=0x0c09bdf2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09bdf4;
P_0c09bdf4: /* original 7201, guest PC 0x0c09bdf4 */
if(!s->budget--) { s->failed_pc=0x0c09bdf4u; return 0; }
r[2]+=0x00000001u;
goto P_0c09bdf6;
P_0c09bdf6: /* original 0e26, guest PC 0x0c09bdf6 */
if(!s->budget--) { s->failed_pc=0x0c09bdf6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09bdf8;
P_0c09bdf8: /* original 03ee, guest PC 0x0c09bdf8 */
if(!s->budget--) { s->failed_pc=0x0c09bdf8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09bdfa;
P_0c09bdfa: /* original 33b7, guest PC 0x0c09bdfa */
if(!s->budget--) { s->failed_pc=0x0c09bdfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c09bdfc;
P_0c09bdfc: /* original 8b13, guest PC 0x0c09bdfc */
if(!s->budget--) { s->failed_pc=0x0c09bdfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09bdfe;
P_0c09bdfe: /* original a010, guest PC 0x0c09bdfe */
if(!s->budget--) { s->failed_pc=0x0c09bdfeu; return 0; }
goto P_0c09be22;
P_0c09be00: /* original 0009, guest PC 0x0c09be00 */
if(!s->budget--) { s->failed_pc=0x0c09be00u; return 0; }
goto P_0c09be02;
P_0c09be02: /* original 9059, guest PC 0x0c09be02 */
if(!s->budget--) { s->failed_pc=0x0c09be02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09be04;
P_0c09be04: /* original 03ee, guest PC 0x0c09be04 */
if(!s->budget--) { s->failed_pc=0x0c09be04u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09be06;
P_0c09be06: /* original 7301, guest PC 0x0c09be06 */
if(!s->budget--) { s->failed_pc=0x0c09be06u; return 0; }
r[3]+=0x00000001u;
goto P_0c09be08;
P_0c09be08: /* original 0e36, guest PC 0x0c09be08 */
if(!s->budget--) { s->failed_pc=0x0c09be08u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09be0a;
P_0c09be0a: /* original 02ee, guest PC 0x0c09be0a */
if(!s->budget--) { s->failed_pc=0x0c09be0au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09be0c;
P_0c09be0c: /* original 3297, guest PC 0x0c09be0c */
if(!s->budget--) { s->failed_pc=0x0c09be0cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c09be0e;
P_0c09be0e: /* original 8b0a, guest PC 0x0c09be0e */
if(!s->budget--) { s->failed_pc=0x0c09be0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09be10;
P_0c09be10: /* original a007, guest PC 0x0c09be10 */
if(!s->budget--) { s->failed_pc=0x0c09be10u; return 0; }
goto P_0c09be22;
P_0c09be12: /* original 0009, guest PC 0x0c09be12 */
if(!s->budget--) { s->failed_pc=0x0c09be12u; return 0; }
goto P_0c09be14;
P_0c09be14: /* original 9050, guest PC 0x0c09be14 */
if(!s->budget--) { s->failed_pc=0x0c09be14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09be16;
P_0c09be16: /* original 02ee, guest PC 0x0c09be16 */
if(!s->budget--) { s->failed_pc=0x0c09be16u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09be18;
P_0c09be18: /* original 7201, guest PC 0x0c09be18 */
if(!s->budget--) { s->failed_pc=0x0c09be18u; return 0; }
r[2]+=0x00000001u;
goto P_0c09be1a;
P_0c09be1a: /* original 0e26, guest PC 0x0c09be1a */
if(!s->budget--) { s->failed_pc=0x0c09be1au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09be1c;
P_0c09be1c: /* original 03ee, guest PC 0x0c09be1c */
if(!s->budget--) { s->failed_pc=0x0c09be1cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09be1e;
P_0c09be1e: /* original 33b7, guest PC 0x0c09be1e */
if(!s->budget--) { s->failed_pc=0x0c09be1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c09be20;
P_0c09be20: /* original 8b01, guest PC 0x0c09be20 */
if(!s->budget--) { s->failed_pc=0x0c09be20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be26; }
goto P_0c09be22;
P_0c09be22: /* original 9049, guest PC 0x0c09be22 */
if(!s->budget--) { s->failed_pc=0x0c09be22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09be24;
P_0c09be24: /* original 0ea6, guest PC 0x0c09be24 */
if(!s->budget--) { s->failed_pc=0x0c09be24u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09be26;
P_0c09be26: /* original 9047, guest PC 0x0c09be26 */
if(!s->budget--) { s->failed_pc=0x0c09be26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09beb8u,2);
goto P_0c09be28;
P_0c09be28: /* original 05ee, guest PC 0x0c09be28 */
if(!s->budget--) { s->failed_pc=0x0c09be28u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c09be2a;
P_0c09be2a: /* original 7004, guest PC 0x0c09be2a */
if(!s->budget--) { s->failed_pc=0x0c09be2au; return 0; }
r[0]+=0x00000004u;
goto P_0c09be2c;
P_0c09be2c: /* original be50, guest PC 0x0c09be2c */
if(!s->budget--) { s->failed_pc=0x0c09be2cu; return 0; }
target=0x0c09bad0u; r[16]=0x0c09be30u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09be30u) { target=s->pc; goto dispatch; }
goto P_0c09be30;
P_0c09be2e: /* original 04ee, guest PC 0x0c09be2e */
if(!s->budget--) { s->failed_pc=0x0c09be2eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09be30;
P_0c09be30: /* original e204, guest PC 0x0c09be30 */
if(!s->budget--) { s->failed_pc=0x0c09be30u; return 0; }
r[2]=0x00000004u;
goto P_0c09be32;
P_0c09be32: /* original 22d8, guest PC 0x0c09be32 */
if(!s->budget--) { s->failed_pc=0x0c09be32u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09be34;
P_0c09be34: /* original 8937, guest PC 0x0c09be34 */
if(!s->budget--) { s->failed_pc=0x0c09be34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bea6; }
goto P_0c09be36;
P_0c09be36: /* original 9442, guest PC 0x0c09be36 */
if(!s->budget--) { s->failed_pc=0x0c09be36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bebeu,2);
goto P_0c09be38;
P_0c09be38: /* original 4c0b, guest PC 0x0c09be38 */
if(!s->budget--) { s->failed_pc=0x0c09be38u; return 0; }
target=r[12];
r[16]=0x0c09be3cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09be3cu) { target=s->pc; goto dispatch; }
goto P_0c09be3c;
P_0c09be3a: /* original 0009, guest PC 0x0c09be3a */
if(!s->budget--) { s->failed_pc=0x0c09be3au; return 0; }
goto P_0c09be3c;
P_0c09be3c: /* original 9040, guest PC 0x0c09be3c */
if(!s->budget--) { s->failed_pc=0x0c09be3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bec0u,2);
goto P_0c09be3e;
P_0c09be3e: /* original 00ee, guest PC 0x0c09be3e */
if(!s->budget--) { s->failed_pc=0x0c09be3eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09be40;
P_0c09be40: /* original 8808, guest PC 0x0c09be40 */
if(!s->budget--) { s->failed_pc=0x0c09be40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c09be42;
P_0c09be42: /* original 8907, guest PC 0x0c09be42 */
if(!s->budget--) { s->failed_pc=0x0c09be42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be54; }
goto P_0c09be44;
P_0c09be44: /* original 8809, guest PC 0x0c09be44 */
if(!s->budget--) { s->failed_pc=0x0c09be44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c09be46;
P_0c09be46: /* original 8909, guest PC 0x0c09be46 */
if(!s->budget--) { s->failed_pc=0x0c09be46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be5c; }
goto P_0c09be48;
P_0c09be48: /* original 880a, guest PC 0x0c09be48 */
if(!s->budget--) { s->failed_pc=0x0c09be48u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c09be4a;
P_0c09be4a: /* original 890b, guest PC 0x0c09be4a */
if(!s->budget--) { s->failed_pc=0x0c09be4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be64; }
goto P_0c09be4c;
P_0c09be4c: /* original 880b, guest PC 0x0c09be4c */
if(!s->budget--) { s->failed_pc=0x0c09be4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c09be4e;
P_0c09be4e: /* original 8925, guest PC 0x0c09be4e */
if(!s->budget--) { s->failed_pc=0x0c09be4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09be9c; }
goto P_0c09be50;
P_0c09be50: /* original a029, guest PC 0x0c09be50 */
if(!s->budget--) { s->failed_pc=0x0c09be50u; return 0; }
goto P_0c09bea6;
P_0c09be52: /* original 0009, guest PC 0x0c09be52 */
if(!s->budget--) { s->failed_pc=0x0c09be52u; return 0; }
goto P_0c09be54;
P_0c09be54: /* original e00a, guest PC 0x0c09be54 */
if(!s->budget--) { s->failed_pc=0x0c09be54u; return 0; }
r[0]=0x0000000au;
goto P_0c09be56;
P_0c09be56: /* original 80eb, guest PC 0x0c09be56 */
if(!s->budget--) { s->failed_pc=0x0c09be56u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09be58;
P_0c09be58: /* original a023, guest PC 0x0c09be58 */
if(!s->budget--) { s->failed_pc=0x0c09be58u; return 0; }
r[3]=0x00000077u;
goto P_0c09bea2;
P_0c09be5a: /* original e377, guest PC 0x0c09be5a */
if(!s->budget--) { s->failed_pc=0x0c09be5au; return 0; }
r[3]=0x00000077u;
goto P_0c09be5c;
P_0c09be5c: /* original e00c, guest PC 0x0c09be5c */
if(!s->budget--) { s->failed_pc=0x0c09be5cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09be5e;
P_0c09be5e: /* original 80eb, guest PC 0x0c09be5e */
if(!s->budget--) { s->failed_pc=0x0c09be5eu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09be60;
P_0c09be60: /* original a01f, guest PC 0x0c09be60 */
if(!s->budget--) { s->failed_pc=0x0c09be60u; return 0; }
r[3]=0x00000078u;
goto P_0c09bea2;
P_0c09be62: /* original e378, guest PC 0x0c09be62 */
if(!s->budget--) { s->failed_pc=0x0c09be62u; return 0; }
r[3]=0x00000078u;
goto P_0c09be64;
P_0c09be64: /* original d317, guest PC 0x0c09be64 */
if(!s->budget--) { s->failed_pc=0x0c09be64u; return 0; }
r[3]=read(ram,0x0c09bec4u,4);
goto P_0c09be66;
P_0c09be66: /* original 430b, guest PC 0x0c09be66 */
if(!s->budget--) { s->failed_pc=0x0c09be66u; return 0; }
target=r[3];
r[16]=0x0c09be6au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09be6au) { target=s->pc; goto dispatch; }
goto P_0c09be6a;
P_0c09be68: /* original e400, guest PC 0x0c09be68 */
if(!s->budget--) { s->failed_pc=0x0c09be68u; return 0; }
r[4]=0x00000000u;
goto P_0c09be6a;
P_0c09be6a: /* original d217, guest PC 0x0c09be6a */
if(!s->budget--) { s->failed_pc=0x0c09be6au; return 0; }
r[2]=read(ram,0x0c09bec8u,4);
goto P_0c09be6c;
P_0c09be6c: /* original 6423, guest PC 0x0c09be6c */
if(!s->budget--) { s->failed_pc=0x0c09be6cu; return 0; }
r[4]=r[2];
goto P_0c09be6e;
P_0c09be6e: /* original 2f22, guest PC 0x0c09be6e */
if(!s->budget--) { s->failed_pc=0x0c09be6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09be70;
P_0c09be70: /* original d316, guest PC 0x0c09be70 */
if(!s->budget--) { s->failed_pc=0x0c09be70u; return 0; }
r[3]=read(ram,0x0c09beccu,4);
goto P_0c09be72;
P_0c09be72: /* original 430b, guest PC 0x0c09be72 */
if(!s->budget--) { s->failed_pc=0x0c09be72u; return 0; }
target=r[3];
r[16]=0x0c09be76u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09be76u) { target=s->pc; goto dispatch; }
goto P_0c09be76;
P_0c09be74: /* original 7401, guest PC 0x0c09be74 */
if(!s->budget--) { s->failed_pc=0x0c09be74u; return 0; }
r[4]+=0x00000001u;
goto P_0c09be76;
P_0c09be76: /* original 9124, guest PC 0x0c09be76 */
if(!s->budget--) { s->failed_pc=0x0c09be76u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bec2u,2);
goto P_0c09be78;
P_0c09be78: /* original 318c, guest PC 0x0c09be78 */
if(!s->budget--) { s->failed_pc=0x0c09be78u; return 0; }
r[1]+=r[8];
goto P_0c09be7a;
P_0c09be7a: /* original 2100, guest PC 0x0c09be7a */
if(!s->budget--) { s->failed_pc=0x0c09be7au; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09be7c;
P_0c09be7c: /* original 64f2, guest PC 0x0c09be7c */
if(!s->budget--) { s->failed_pc=0x0c09be7cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09be7e;
P_0c09be7e: /* original d313, guest PC 0x0c09be7e */
if(!s->budget--) { s->failed_pc=0x0c09be7eu; return 0; }
r[3]=read(ram,0x0c09beccu,4);
goto P_0c09be80;
P_0c09be80: /* original 430b, guest PC 0x0c09be80 */
if(!s->budget--) { s->failed_pc=0x0c09be80u; return 0; }
target=r[3];
r[16]=0x0c09be84u;
r[4]+=0x0000000eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09be84u) { target=s->pc; goto dispatch; }
goto P_0c09be84;
P_0c09be82: /* original 740e, guest PC 0x0c09be82 */
if(!s->budget--) { s->failed_pc=0x0c09be82u; return 0; }
r[4]+=0x0000000eu;
goto P_0c09be84;
P_0c09be84: /* original 600c, guest PC 0x0c09be84 */
if(!s->budget--) { s->failed_pc=0x0c09be84u; return 0; }
r[0]=r[0]&255u;
goto P_0c09be86;
P_0c09be86: /* original 2008, guest PC 0x0c09be86 */
if(!s->budget--) { s->failed_pc=0x0c09be86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09be88;
P_0c09be88: /* original 8b03, guest PC 0x0c09be88 */
if(!s->budget--) { s->failed_pc=0x0c09be88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09be92; }
goto P_0c09be8a;
P_0c09be8a: /* original 5082, guest PC 0x0c09be8a */
if(!s->budget--) { s->failed_pc=0x0c09be8au; return 0; }
r[0]=read(ram,r[8]+8,4);
goto P_0c09be8c;
P_0c09be8c: /* original cb08, guest PC 0x0c09be8c */
if(!s->budget--) { s->failed_pc=0x0c09be8cu; return 0; }
r[0]|=8u;
goto P_0c09be8e;
P_0c09be8e: /* original a00a, guest PC 0x0c09be8e */
if(!s->budget--) { s->failed_pc=0x0c09be8eu; return 0; }
write(ram,r[8]+8,r[0],4);
goto P_0c09bea6;
P_0c09be90: /* original 1802, guest PC 0x0c09be90 */
if(!s->budget--) { s->failed_pc=0x0c09be90u; return 0; }
write(ram,r[8]+8,r[0],4);
goto P_0c09be92;
P_0c09be92: /* original 5282, guest PC 0x0c09be92 */
if(!s->budget--) { s->failed_pc=0x0c09be92u; return 0; }
r[2]=read(ram,r[8]+8,4);
goto P_0c09be94;
P_0c09be94: /* original e3f7, guest PC 0x0c09be94 */
if(!s->budget--) { s->failed_pc=0x0c09be94u; return 0; }
r[3]=0xfffffff7u;
goto P_0c09be96;
P_0c09be96: /* original 2239, guest PC 0x0c09be96 */
if(!s->budget--) { s->failed_pc=0x0c09be96u; return 0; }
r[2]&=r[3];
goto P_0c09be98;
P_0c09be98: /* original a005, guest PC 0x0c09be98 */
if(!s->budget--) { s->failed_pc=0x0c09be98u; return 0; }
write(ram,r[8]+8,r[2],4);
goto P_0c09bea6;
P_0c09be9a: /* original 1822, guest PC 0x0c09be9a */
if(!s->budget--) { s->failed_pc=0x0c09be9au; return 0; }
write(ram,r[8]+8,r[2],4);
goto P_0c09be9c;
P_0c09be9c: /* original 60b3, guest PC 0x0c09be9c */
if(!s->budget--) { s->failed_pc=0x0c09be9cu; return 0; }
r[0]=r[11];
goto P_0c09be9e;
P_0c09be9e: /* original e372, guest PC 0x0c09be9e */
if(!s->budget--) { s->failed_pc=0x0c09be9eu; return 0; }
r[3]=0x00000072u;
goto P_0c09bea0;
P_0c09bea0: /* original 80eb, guest PC 0x0c09bea0 */
if(!s->budget--) { s->failed_pc=0x0c09bea0u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09bea2;
P_0c09bea2: /* original e010, guest PC 0x0c09bea2 */
if(!s->budget--) { s->failed_pc=0x0c09bea2u; return 0; }
r[0]=0x00000010u;
goto P_0c09bea4;
P_0c09bea4: /* original 0e34, guest PC 0x0c09bea4 */
if(!s->budget--) { s->failed_pc=0x0c09bea4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09bea6;
P_0c09bea6: /* original e10a, guest PC 0x0c09bea6 */
if(!s->budget--) { s->failed_pc=0x0c09bea6u; return 0; }
r[1]=0x0000000au;
goto P_0c09bea8;
P_0c09bea8: /* original 21d8, guest PC 0x0c09bea8 */
if(!s->budget--) { s->failed_pc=0x0c09bea8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c09beaa;
P_0c09beaa: /* original 891d, guest PC 0x0c09beaa */
if(!s->budget--) { s->failed_pc=0x0c09beaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bee8; }
goto P_0c09beac;
P_0c09beac: /* original e208, guest PC 0x0c09beac */
if(!s->budget--) { s->failed_pc=0x0c09beacu; return 0; }
r[2]=0x00000008u;
goto P_0c09beae;
P_0c09beae: /* original 2d28, guest PC 0x0c09beae */
if(!s->budget--) { s->failed_pc=0x0c09beaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c09beb0;
P_0c09beb0: /* original 890e, guest PC 0x0c09beb0 */
if(!s->budget--) { s->failed_pc=0x0c09beb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bed0; }
goto P_0c09beb2;
P_0c09beb2: /* original 9404, guest PC 0x0c09beb2 */
if(!s->budget--) { s->failed_pc=0x0c09beb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bebeu,2);
goto P_0c09beb4;
P_0c09beb4: /* original a00d, guest PC 0x0c09beb4 */
if(!s->budget--) { s->failed_pc=0x0c09beb4u; return 0; }
goto P_0c09bed2;
P_0c09beb6: /* original 0009, guest PC 0x0c09beb6 */
if(!s->budget--) { s->failed_pc=0x0c09beb6u; return 0; }
return vf3_matrix_family(0x0c09beb8u,s,ram);
P_0c09bed0: /* original 9460, guest PC 0x0c09bed0 */
if(!s->budget--) { s->failed_pc=0x0c09bed0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf94u,2);
goto P_0c09bed2;
P_0c09bed2: /* original 4c0b, guest PC 0x0c09bed2 */
if(!s->budget--) { s->failed_pc=0x0c09bed2u; return 0; }
target=r[12];
r[16]=0x0c09bed6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bed6u) { target=s->pc; goto dispatch; }
goto P_0c09bed6;
P_0c09bed4: /* original 0009, guest PC 0x0c09bed4 */
if(!s->budget--) { s->failed_pc=0x0c09bed4u; return 0; }
goto P_0c09bed6;
P_0c09bed6: /* original d333, guest PC 0x0c09bed6 */
if(!s->budget--) { s->failed_pc=0x0c09bed6u; return 0; }
r[3]=read(ram,0x0c09bfa4u,4);
goto P_0c09bed8;
P_0c09bed8: /* original d431, guest PC 0x0c09bed8 */
if(!s->budget--) { s->failed_pc=0x0c09bed8u; return 0; }
r[4]=read(ram,0x0c09bfa0u,4);
goto P_0c09beda;
P_0c09beda: /* original 430b, guest PC 0x0c09beda */
if(!s->budget--) { s->failed_pc=0x0c09bedau; return 0; }
target=r[3];
r[16]=0x0c09bedeu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09bedeu) { target=s->pc; goto dispatch; }
goto P_0c09bede;
P_0c09bedc: /* original e500, guest PC 0x0c09bedc */
if(!s->budget--) { s->failed_pc=0x0c09bedcu; return 0; }
r[5]=0x00000000u;
goto P_0c09bede;
P_0c09bede: /* original 60b3, guest PC 0x0c09bede */
if(!s->budget--) { s->failed_pc=0x0c09bedeu; return 0; }
r[0]=r[11];
goto P_0c09bee0;
P_0c09bee0: /* original 80eb, guest PC 0x0c09bee0 */
if(!s->budget--) { s->failed_pc=0x0c09bee0u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09bee2;
P_0c09bee2: /* original e010, guest PC 0x0c09bee2 */
if(!s->budget--) { s->failed_pc=0x0c09bee2u; return 0; }
r[0]=0x00000010u;
goto P_0c09bee4;
P_0c09bee4: /* original e372, guest PC 0x0c09bee4 */
if(!s->budget--) { s->failed_pc=0x0c09bee4u; return 0; }
r[3]=0x00000072u;
goto P_0c09bee6;
P_0c09bee6: /* original 0e34, guest PC 0x0c09bee6 */
if(!s->budget--) { s->failed_pc=0x0c09bee6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09bee8;
P_0c09bee8: /* original 7f04, guest PC 0x0c09bee8 */
if(!s->budget--) { s->failed_pc=0x0c09bee8u; return 0; }
r[15]+=0x00000004u;
goto P_0c09beea;
P_0c09beea: /* original 4f26, guest PC 0x0c09beea */
if(!s->budget--) { s->failed_pc=0x0c09beeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09beec;
P_0c09beec: /* original 68f6, guest PC 0x0c09beec */
if(!s->budget--) { s->failed_pc=0x0c09beecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09beee;
P_0c09beee: /* original 69f6, guest PC 0x0c09beee */
if(!s->budget--) { s->failed_pc=0x0c09beeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09bef0;
P_0c09bef0: /* original 6af6, guest PC 0x0c09bef0 */
if(!s->budget--) { s->failed_pc=0x0c09bef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09bef2;
P_0c09bef2: /* original 6bf6, guest PC 0x0c09bef2 */
if(!s->budget--) { s->failed_pc=0x0c09bef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09bef4;
P_0c09bef4: /* original 6cf6, guest PC 0x0c09bef4 */
if(!s->budget--) { s->failed_pc=0x0c09bef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09bef6;
P_0c09bef6: /* original 6df6, guest PC 0x0c09bef6 */
if(!s->budget--) { s->failed_pc=0x0c09bef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09bef8;
P_0c09bef8: /* original 000b, guest PC 0x0c09bef8 */
if(!s->budget--) { s->failed_pc=0x0c09bef8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09befa: /* original 6ef6, guest PC 0x0c09befa */
if(!s->budget--) { s->failed_pc=0x0c09befau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09befcu,s,ram);
P_0c09ca8e: /* original 4f22, guest PC 0x0c09ca8e */
if(!s->budget--) { s->failed_pc=0x0c09ca8eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ca90;
P_0c09ca90: /* original d32d, guest PC 0x0c09ca90 */
if(!s->budget--) { s->failed_pc=0x0c09ca90u; return 0; }
r[3]=read(ram,0x0c09cb48u,4);
goto P_0c09ca92;
P_0c09ca92: /* original de2c, guest PC 0x0c09ca92 */
if(!s->budget--) { s->failed_pc=0x0c09ca92u; return 0; }
r[14]=read(ram,0x0c09cb44u,4);
goto P_0c09ca94;
P_0c09ca94: /* original 430b, guest PC 0x0c09ca94 */
if(!s->budget--) { s->failed_pc=0x0c09ca94u; return 0; }
target=r[3];
r[16]=0x0c09ca98u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ca98u) { target=s->pc; goto dispatch; }
goto P_0c09ca98;
P_0c09ca96: /* original 0009, guest PC 0x0c09ca96 */
if(!s->budget--) { s->failed_pc=0x0c09ca96u; return 0; }
goto P_0c09ca98;
P_0c09ca98: /* original e400, guest PC 0x0c09ca98 */
if(!s->budget--) { s->failed_pc=0x0c09ca98u; return 0; }
r[4]=0x00000000u;
goto P_0c09ca9a;
P_0c09ca9a: /* original e07d, guest PC 0x0c09ca9a */
if(!s->budget--) { s->failed_pc=0x0c09ca9au; return 0; }
r[0]=0x0000007du;
goto P_0c09ca9c;
P_0c09ca9c: /* original 4f26, guest PC 0x0c09ca9c */
if(!s->budget--) { s->failed_pc=0x0c09ca9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ca9e;
P_0c09ca9e: /* original e378, guest PC 0x0c09ca9e */
if(!s->budget--) { s->failed_pc=0x0c09ca9eu; return 0; }
r[3]=0x00000078u;
goto P_0c09caa0;
P_0c09caa0: /* original e240, guest PC 0x0c09caa0 */
if(!s->budget--) { s->failed_pc=0x0c09caa0u; return 0; }
r[2]=0x00000040u;
goto P_0c09caa2;
P_0c09caa2: /* original 1e23, guest PC 0x0c09caa2 */
if(!s->budget--) { s->failed_pc=0x0c09caa2u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09caa4;
P_0c09caa4: /* original 1e46, guest PC 0x0c09caa4 */
if(!s->budget--) { s->failed_pc=0x0c09caa4u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c09caa6;
P_0c09caa6: /* original 0e44, guest PC 0x0c09caa6 */
if(!s->budget--) { s->failed_pc=0x0c09caa6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09caa8;
P_0c09caa8: /* original 1e45, guest PC 0x0c09caa8 */
if(!s->budget--) { s->failed_pc=0x0c09caa8u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c09caaa;
P_0c09caaa: /* original 9047, guest PC 0x0c09caaa */
if(!s->budget--) { s->failed_pc=0x0c09caaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3cu,2);
goto P_0c09caac;
P_0c09caac: /* original 0e46, guest PC 0x0c09caac */
if(!s->budget--) { s->failed_pc=0x0c09caacu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09caae;
P_0c09caae: /* original 70fc, guest PC 0x0c09caae */
if(!s->budget--) { s->failed_pc=0x0c09caaeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09cab0;
P_0c09cab0: /* original 0e46, guest PC 0x0c09cab0 */
if(!s->budget--) { s->failed_pc=0x0c09cab0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cab2;
P_0c09cab2: /* original 7008, guest PC 0x0c09cab2 */
if(!s->budget--) { s->failed_pc=0x0c09cab2u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cab4;
P_0c09cab4: /* original 0e46, guest PC 0x0c09cab4 */
if(!s->budget--) { s->failed_pc=0x0c09cab4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cab6;
P_0c09cab6: /* original 7004, guest PC 0x0c09cab6 */
if(!s->budget--) { s->failed_pc=0x0c09cab6u; return 0; }
r[0]+=0x00000004u;
goto P_0c09cab8;
P_0c09cab8: /* original 0e46, guest PC 0x0c09cab8 */
if(!s->budget--) { s->failed_pc=0x0c09cab8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09caba;
P_0c09caba: /* original 7004, guest PC 0x0c09caba */
if(!s->budget--) { s->failed_pc=0x0c09cabau; return 0; }
r[0]+=0x00000004u;
goto P_0c09cabc;
P_0c09cabc: /* original 0e46, guest PC 0x0c09cabc */
if(!s->budget--) { s->failed_pc=0x0c09cabcu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cabe;
P_0c09cabe: /* original 84eb, guest PC 0x0c09cabe */
if(!s->budget--) { s->failed_pc=0x0c09cabeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c09cac0;
P_0c09cac0: /* original 7001, guest PC 0x0c09cac0 */
if(!s->budget--) { s->failed_pc=0x0c09cac0u; return 0; }
r[0]+=0x00000001u;
goto P_0c09cac2;
P_0c09cac2: /* original 80eb, guest PC 0x0c09cac2 */
if(!s->budget--) { s->failed_pc=0x0c09cac2u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cac4;
P_0c09cac4: /* original e010, guest PC 0x0c09cac4 */
if(!s->budget--) { s->failed_pc=0x0c09cac4u; return 0; }
r[0]=0x00000010u;
goto P_0c09cac6;
P_0c09cac6: /* original 0e34, guest PC 0x0c09cac6 */
if(!s->budget--) { s->failed_pc=0x0c09cac6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cac8;
P_0c09cac8: /* original a000, guest PC 0x0c09cac8 */
if(!s->budget--) { s->failed_pc=0x0c09cac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09cacc;
P_0c09caca: /* original 6ef6, guest PC 0x0c09caca */
if(!s->budget--) { s->failed_pc=0x0c09cacau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09cacc;
P_0c09cacc: /* original 2fe6, guest PC 0x0c09cacc */
if(!s->budget--) { s->failed_pc=0x0c09caccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cace;
P_0c09cace: /* original 2fd6, guest PC 0x0c09cace */
if(!s->budget--) { s->failed_pc=0x0c09caceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad0;
P_0c09cad0: /* original 2fc6, guest PC 0x0c09cad0 */
if(!s->budget--) { s->failed_pc=0x0c09cad0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad2;
P_0c09cad2: /* original 2fb6, guest PC 0x0c09cad2 */
if(!s->budget--) { s->failed_pc=0x0c09cad2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad4;
P_0c09cad4: /* original 2fa6, guest PC 0x0c09cad4 */
if(!s->budget--) { s->failed_pc=0x0c09cad4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad6;
P_0c09cad6: /* original 2f96, guest PC 0x0c09cad6 */
if(!s->budget--) { s->failed_pc=0x0c09cad6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cad8;
P_0c09cad8: /* original 2f86, guest PC 0x0c09cad8 */
if(!s->budget--) { s->failed_pc=0x0c09cad8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cada;
P_0c09cada: /* original 4f22, guest PC 0x0c09cada */
if(!s->budget--) { s->failed_pc=0x0c09cadau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09cadc;
P_0c09cadc: /* original d31a, guest PC 0x0c09cadc */
if(!s->budget--) { s->failed_pc=0x0c09cadcu; return 0; }
r[3]=read(ram,0x0c09cb48u,4);
goto P_0c09cade;
P_0c09cade: /* original de19, guest PC 0x0c09cade */
if(!s->budget--) { s->failed_pc=0x0c09cadeu; return 0; }
r[14]=read(ram,0x0c09cb44u,4);
goto P_0c09cae0;
P_0c09cae0: /* original 430b, guest PC 0x0c09cae0 */
if(!s->budget--) { s->failed_pc=0x0c09cae0u; return 0; }
target=r[3];
r[16]=0x0c09cae4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cae4u) { target=s->pc; goto dispatch; }
goto P_0c09cae4;
P_0c09cae2: /* original 0009, guest PC 0x0c09cae2 */
if(!s->budget--) { s->failed_pc=0x0c09cae2u; return 0; }
goto P_0c09cae4;
P_0c09cae4: /* original 6d03, guest PC 0x0c09cae4 */
if(!s->budget--) { s->failed_pc=0x0c09cae4u; return 0; }
r[13]=r[0];
goto P_0c09cae6;
P_0c09cae6: /* original e07d, guest PC 0x0c09cae6 */
if(!s->budget--) { s->failed_pc=0x0c09cae6u; return 0; }
r[0]=0x0000007du;
goto P_0c09cae8;
P_0c09cae8: /* original e310, guest PC 0x0c09cae8 */
if(!s->budget--) { s->failed_pc=0x0c09cae8u; return 0; }
r[3]=0x00000010u;
goto P_0c09caea;
P_0c09caea: /* original e240, guest PC 0x0c09caea */
if(!s->budget--) { s->failed_pc=0x0c09caeau; return 0; }
r[2]=0x00000040u;
goto P_0c09caec;
P_0c09caec: /* original ec00, guest PC 0x0c09caec */
if(!s->budget--) { s->failed_pc=0x0c09caecu; return 0; }
r[12]=0x00000000u;
goto P_0c09caee;
P_0c09caee: /* original 1e23, guest PC 0x0c09caee */
if(!s->budget--) { s->failed_pc=0x0c09caeeu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09caf0;
P_0c09caf0: /* original 23d8, guest PC 0x0c09caf0 */
if(!s->budget--) { s->failed_pc=0x0c09caf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09caf2;
P_0c09caf2: /* original 1ec6, guest PC 0x0c09caf2 */
if(!s->budget--) { s->failed_pc=0x0c09caf2u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c09caf4;
P_0c09caf4: /* original 0ec4, guest PC 0x0c09caf4 */
if(!s->budget--) { s->failed_pc=0x0c09caf4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c09caf6;
P_0c09caf6: /* original 1ec5, guest PC 0x0c09caf6 */
if(!s->budget--) { s->failed_pc=0x0c09caf6u; return 0; }
write(ram,r[14]+20,r[12],4);
goto P_0c09caf8;
P_0c09caf8: /* original db14, guest PC 0x0c09caf8 */
if(!s->budget--) { s->failed_pc=0x0c09caf8u; return 0; }
r[11]=read(ram,0x0c09cb4cu,4);
goto P_0c09cafa;
P_0c09cafa: /* original 8d2d, guest PC 0x0c09cafa */
if(!s->budget--) { s->failed_pc=0x0c09cafau; return 0; }
cond=r[17]&1u;
r[10]=0x00000003u;
if(cond) { goto P_0c09cb58; }
goto P_0c09cafe;
P_0c09cafc: /* original ea03, guest PC 0x0c09cafc */
if(!s->budget--) { s->failed_pc=0x0c09cafcu; return 0; }
r[10]=0x00000003u;
goto P_0c09cafe;
P_0c09cafe: /* original 941e, guest PC 0x0c09cafe */
if(!s->budget--) { s->failed_pc=0x0c09cafeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3eu,2);
goto P_0c09cb00;
P_0c09cb00: /* original 4b0b, guest PC 0x0c09cb00 */
if(!s->budget--) { s->failed_pc=0x0c09cb00u; return 0; }
target=r[11];
r[16]=0x0c09cb04u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cb04u) { target=s->pc; goto dispatch; }
goto P_0c09cb04;
P_0c09cb02: /* original 0009, guest PC 0x0c09cb02 */
if(!s->budget--) { s->failed_pc=0x0c09cb02u; return 0; }
goto P_0c09cb04;
P_0c09cb04: /* original 901a, guest PC 0x0c09cb04 */
if(!s->budget--) { s->failed_pc=0x0c09cb04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb3cu,2);
goto P_0c09cb06;
P_0c09cb06: /* original 03ee, guest PC 0x0c09cb06 */
if(!s->budget--) { s->failed_pc=0x0c09cb06u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb08;
P_0c09cb08: /* original 73ff, guest PC 0x0c09cb08 */
if(!s->budget--) { s->failed_pc=0x0c09cb08u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cb0a;
P_0c09cb0a: /* original 0e36, guest PC 0x0c09cb0a */
if(!s->budget--) { s->failed_pc=0x0c09cb0au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb0c;
P_0c09cb0c: /* original 02ee, guest PC 0x0c09cb0c */
if(!s->budget--) { s->failed_pc=0x0c09cb0cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb0e;
P_0c09cb0e: /* original 4211, guest PC 0x0c09cb0e */
if(!s->budget--) { s->failed_pc=0x0c09cb0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cb10;
P_0c09cb10: /* original 8900, guest PC 0x0c09cb10 */
if(!s->budget--) { s->failed_pc=0x0c09cb10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb14; }
goto P_0c09cb12;
P_0c09cb12: /* original 0ea6, guest PC 0x0c09cb12 */
if(!s->budget--) { s->failed_pc=0x0c09cb12u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c09cb14;
P_0c09cb14: /* original 00ee, guest PC 0x0c09cb14 */
if(!s->budget--) { s->failed_pc=0x0c09cb14u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cb16;
P_0c09cb16: /* original 8800, guest PC 0x0c09cb16 */
if(!s->budget--) { s->failed_pc=0x0c09cb16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cb18;
P_0c09cb18: /* original 8905, guest PC 0x0c09cb18 */
if(!s->budget--) { s->failed_pc=0x0c09cb18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb26; }
goto P_0c09cb1a;
P_0c09cb1a: /* original 8801, guest PC 0x0c09cb1a */
if(!s->budget--) { s->failed_pc=0x0c09cb1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cb1c;
P_0c09cb1c: /* original 8908, guest PC 0x0c09cb1c */
if(!s->budget--) { s->failed_pc=0x0c09cb1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb30; }
goto P_0c09cb1e;
P_0c09cb1e: /* original 8802, guest PC 0x0c09cb1e */
if(!s->budget--) { s->failed_pc=0x0c09cb1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cb20;
P_0c09cb20: /* original 8916, guest PC 0x0c09cb20 */
if(!s->budget--) { s->failed_pc=0x0c09cb20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb50; }
goto P_0c09cb22;
P_0c09cb22: /* original a019, guest PC 0x0c09cb22 */
if(!s->budget--) { s->failed_pc=0x0c09cb22u; return 0; }
goto P_0c09cb58;
P_0c09cb24: /* original 0009, guest PC 0x0c09cb24 */
if(!s->budget--) { s->failed_pc=0x0c09cb24u; return 0; }
goto P_0c09cb26;
P_0c09cb26: /* original 900b, guest PC 0x0c09cb26 */
if(!s->budget--) { s->failed_pc=0x0c09cb26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb40u,2);
goto P_0c09cb28;
P_0c09cb28: /* original 03ee, guest PC 0x0c09cb28 */
if(!s->budget--) { s->failed_pc=0x0c09cb28u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb2a;
P_0c09cb2a: /* original 70f8, guest PC 0x0c09cb2a */
if(!s->budget--) { s->failed_pc=0x0c09cb2au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c09cb2c;
P_0c09cb2c: /* original a014, guest PC 0x0c09cb2c */
if(!s->budget--) { s->failed_pc=0x0c09cb2cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb58;
P_0c09cb2e: /* original 0e36, guest PC 0x0c09cb2e */
if(!s->budget--) { s->failed_pc=0x0c09cb2eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb30;
P_0c09cb30: /* original 9007, guest PC 0x0c09cb30 */
if(!s->budget--) { s->failed_pc=0x0c09cb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cb42u,2);
goto P_0c09cb32;
P_0c09cb32: /* original 01ee, guest PC 0x0c09cb32 */
if(!s->budget--) { s->failed_pc=0x0c09cb32u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cb34;
P_0c09cb34: /* original 70f4, guest PC 0x0c09cb34 */
if(!s->budget--) { s->failed_pc=0x0c09cb34u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c09cb36;
P_0c09cb36: /* original a00f, guest PC 0x0c09cb36 */
if(!s->budget--) { s->failed_pc=0x0c09cb36u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cb58;
P_0c09cb38: /* original 0e16, guest PC 0x0c09cb38 */
if(!s->budget--) { s->failed_pc=0x0c09cb38u; return 0; }
write(ram,r[14]+r[0],r[1],4);
return vf3_matrix_family(0x0c09cb3au,s,ram);
P_0c09cb50: /* original 9066, guest PC 0x0c09cb50 */
if(!s->budget--) { s->failed_pc=0x0c09cb50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cb52;
P_0c09cb52: /* original 02ee, guest PC 0x0c09cb52 */
if(!s->budget--) { s->failed_pc=0x0c09cb52u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb54;
P_0c09cb54: /* original 70f0, guest PC 0x0c09cb54 */
if(!s->budget--) { s->failed_pc=0x0c09cb54u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09cb56;
P_0c09cb56: /* original 0e26, guest PC 0x0c09cb56 */
if(!s->budget--) { s->failed_pc=0x0c09cb56u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cb58;
P_0c09cb58: /* original e120, guest PC 0x0c09cb58 */
if(!s->budget--) { s->failed_pc=0x0c09cb58u; return 0; }
r[1]=0x00000020u;
goto P_0c09cb5a;
P_0c09cb5a: /* original 21d8, guest PC 0x0c09cb5a */
if(!s->budget--) { s->failed_pc=0x0c09cb5au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c09cb5c;
P_0c09cb5c: /* original 8921, guest PC 0x0c09cb5c */
if(!s->budget--) { s->failed_pc=0x0c09cb5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cba2; }
goto P_0c09cb5e;
P_0c09cb5e: /* original 9460, guest PC 0x0c09cb5e */
if(!s->budget--) { s->failed_pc=0x0c09cb5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc22u,2);
goto P_0c09cb60;
P_0c09cb60: /* original 4b0b, guest PC 0x0c09cb60 */
if(!s->budget--) { s->failed_pc=0x0c09cb60u; return 0; }
target=r[11];
r[16]=0x0c09cb64u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cb64u) { target=s->pc; goto dispatch; }
goto P_0c09cb64;
P_0c09cb62: /* original 0009, guest PC 0x0c09cb62 */
if(!s->budget--) { s->failed_pc=0x0c09cb62u; return 0; }
goto P_0c09cb64;
P_0c09cb64: /* original 905e, guest PC 0x0c09cb64 */
if(!s->budget--) { s->failed_pc=0x0c09cb64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cb66;
P_0c09cb66: /* original 02ee, guest PC 0x0c09cb66 */
if(!s->budget--) { s->failed_pc=0x0c09cb66u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb68;
P_0c09cb68: /* original 7201, guest PC 0x0c09cb68 */
if(!s->budget--) { s->failed_pc=0x0c09cb68u; return 0; }
r[2]+=0x00000001u;
goto P_0c09cb6a;
P_0c09cb6a: /* original 0e26, guest PC 0x0c09cb6a */
if(!s->budget--) { s->failed_pc=0x0c09cb6au; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cb6c;
P_0c09cb6c: /* original 03ee, guest PC 0x0c09cb6c */
if(!s->budget--) { s->failed_pc=0x0c09cb6cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb6e;
P_0c09cb6e: /* original 33a7, guest PC 0x0c09cb6e */
if(!s->budget--) { s->failed_pc=0x0c09cb6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[10])!=0);
goto P_0c09cb70;
P_0c09cb70: /* original 8b00, guest PC 0x0c09cb70 */
if(!s->budget--) { s->failed_pc=0x0c09cb70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cb74; }
goto P_0c09cb72;
P_0c09cb72: /* original 0ec6, guest PC 0x0c09cb72 */
if(!s->budget--) { s->failed_pc=0x0c09cb72u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cb74;
P_0c09cb74: /* original 00ee, guest PC 0x0c09cb74 */
if(!s->budget--) { s->failed_pc=0x0c09cb74u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cb76;
P_0c09cb76: /* original 8800, guest PC 0x0c09cb76 */
if(!s->budget--) { s->failed_pc=0x0c09cb76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cb78;
P_0c09cb78: /* original 8905, guest PC 0x0c09cb78 */
if(!s->budget--) { s->failed_pc=0x0c09cb78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb86; }
goto P_0c09cb7a;
P_0c09cb7a: /* original 8801, guest PC 0x0c09cb7a */
if(!s->budget--) { s->failed_pc=0x0c09cb7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cb7c;
P_0c09cb7c: /* original 8908, guest PC 0x0c09cb7c */
if(!s->budget--) { s->failed_pc=0x0c09cb7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb90; }
goto P_0c09cb7e;
P_0c09cb7e: /* original 8802, guest PC 0x0c09cb7e */
if(!s->budget--) { s->failed_pc=0x0c09cb7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cb80;
P_0c09cb80: /* original 890b, guest PC 0x0c09cb80 */
if(!s->budget--) { s->failed_pc=0x0c09cb80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cb9a; }
goto P_0c09cb82;
P_0c09cb82: /* original a00e, guest PC 0x0c09cb82 */
if(!s->budget--) { s->failed_pc=0x0c09cb82u; return 0; }
goto P_0c09cba2;
P_0c09cb84: /* original 0009, guest PC 0x0c09cb84 */
if(!s->budget--) { s->failed_pc=0x0c09cb84u; return 0; }
goto P_0c09cb86;
P_0c09cb86: /* original 904e, guest PC 0x0c09cb86 */
if(!s->budget--) { s->failed_pc=0x0c09cb86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc26u,2);
goto P_0c09cb88;
P_0c09cb88: /* original 03ee, guest PC 0x0c09cb88 */
if(!s->budget--) { s->failed_pc=0x0c09cb88u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cb8a;
P_0c09cb8a: /* original 70f8, guest PC 0x0c09cb8a */
if(!s->budget--) { s->failed_pc=0x0c09cb8au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c09cb8c;
P_0c09cb8c: /* original a009, guest PC 0x0c09cb8c */
if(!s->budget--) { s->failed_pc=0x0c09cb8cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cba2;
P_0c09cb8e: /* original 0e36, guest PC 0x0c09cb8e */
if(!s->budget--) { s->failed_pc=0x0c09cb8eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cb90;
P_0c09cb90: /* original 904a, guest PC 0x0c09cb90 */
if(!s->budget--) { s->failed_pc=0x0c09cb90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc28u,2);
goto P_0c09cb92;
P_0c09cb92: /* original 01ee, guest PC 0x0c09cb92 */
if(!s->budget--) { s->failed_pc=0x0c09cb92u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cb94;
P_0c09cb94: /* original 70f4, guest PC 0x0c09cb94 */
if(!s->budget--) { s->failed_pc=0x0c09cb94u; return 0; }
r[0]+=0xfffffff4u;
goto P_0c09cb96;
P_0c09cb96: /* original a004, guest PC 0x0c09cb96 */
if(!s->budget--) { s->failed_pc=0x0c09cb96u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cba2;
P_0c09cb98: /* original 0e16, guest PC 0x0c09cb98 */
if(!s->budget--) { s->failed_pc=0x0c09cb98u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cb9a;
P_0c09cb9a: /* original 9041, guest PC 0x0c09cb9a */
if(!s->budget--) { s->failed_pc=0x0c09cb9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cb9c;
P_0c09cb9c: /* original 02ee, guest PC 0x0c09cb9c */
if(!s->budget--) { s->failed_pc=0x0c09cb9cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cb9e;
P_0c09cb9e: /* original 70f0, guest PC 0x0c09cb9e */
if(!s->budget--) { s->failed_pc=0x0c09cb9eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c09cba0;
P_0c09cba0: /* original 0e26, guest PC 0x0c09cba0 */
if(!s->budget--) { s->failed_pc=0x0c09cba0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09cba2;
P_0c09cba2: /* original 9642, guest PC 0x0c09cba2 */
if(!s->budget--) { s->failed_pc=0x0c09cba2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2au,2);
goto P_0c09cba4;
P_0c09cba4: /* original e240, guest PC 0x0c09cba4 */
if(!s->budget--) { s->failed_pc=0x0c09cba4u; return 0; }
r[2]=0x00000040u;
goto P_0c09cba6;
P_0c09cba6: /* original 22d8, guest PC 0x0c09cba6 */
if(!s->budget--) { s->failed_pc=0x0c09cba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09cba8;
P_0c09cba8: /* original 6563, guest PC 0x0c09cba8 */
if(!s->budget--) { s->failed_pc=0x0c09cba8u; return 0; }
r[5]=r[6];
goto P_0c09cbaa;
P_0c09cbaa: /* original 75d0, guest PC 0x0c09cbaa */
if(!s->budget--) { s->failed_pc=0x0c09cbaau; return 0; }
r[5]+=0xffffffd0u;
goto P_0c09cbac;
P_0c09cbac: /* original 8d2b, guest PC 0x0c09cbac */
if(!s->budget--) { s->failed_pc=0x0c09cbacu; return 0; }
cond=r[17]&1u;
r[4]=0x0000001eu;
if(cond) { goto P_0c09cc06; }
goto P_0c09cbb0;
P_0c09cbae: /* original e41e, guest PC 0x0c09cbae */
if(!s->budget--) { s->failed_pc=0x0c09cbaeu; return 0; }
r[4]=0x0000001eu;
goto P_0c09cbb0;
P_0c09cbb0: /* original 9038, guest PC 0x0c09cbb0 */
if(!s->budget--) { s->failed_pc=0x0c09cbb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cbb2;
P_0c09cbb2: /* original 00ee, guest PC 0x0c09cbb2 */
if(!s->budget--) { s->failed_pc=0x0c09cbb2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cbb4;
P_0c09cbb4: /* original 8800, guest PC 0x0c09cbb4 */
if(!s->budget--) { s->failed_pc=0x0c09cbb4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cbb6;
P_0c09cbb6: /* original 8905, guest PC 0x0c09cbb6 */
if(!s->budget--) { s->failed_pc=0x0c09cbb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbc4; }
goto P_0c09cbb8;
P_0c09cbb8: /* original 8801, guest PC 0x0c09cbb8 */
if(!s->budget--) { s->failed_pc=0x0c09cbb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cbba;
P_0c09cbba: /* original 890e, guest PC 0x0c09cbba */
if(!s->budget--) { s->failed_pc=0x0c09cbbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbda; }
goto P_0c09cbbc;
P_0c09cbbc: /* original 8802, guest PC 0x0c09cbbc */
if(!s->budget--) { s->failed_pc=0x0c09cbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cbbe;
P_0c09cbbe: /* original 8917, guest PC 0x0c09cbbe */
if(!s->budget--) { s->failed_pc=0x0c09cbbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbf0; }
goto P_0c09cbc0;
P_0c09cbc0: /* original a021, guest PC 0x0c09cbc0 */
if(!s->budget--) { s->failed_pc=0x0c09cbc0u; return 0; }
goto P_0c09cc06;
P_0c09cbc2: /* original 0009, guest PC 0x0c09cbc2 */
if(!s->budget--) { s->failed_pc=0x0c09cbc2u; return 0; }
goto P_0c09cbc4;
P_0c09cbc4: /* original 9032, guest PC 0x0c09cbc4 */
if(!s->budget--) { s->failed_pc=0x0c09cbc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbc6;
P_0c09cbc6: /* original 03ee, guest PC 0x0c09cbc6 */
if(!s->budget--) { s->failed_pc=0x0c09cbc6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbc8;
P_0c09cbc8: /* original 73ff, guest PC 0x0c09cbc8 */
if(!s->budget--) { s->failed_pc=0x0c09cbc8u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbca;
P_0c09cbca: /* original 0e36, guest PC 0x0c09cbca */
if(!s->budget--) { s->failed_pc=0x0c09cbcau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbcc;
P_0c09cbcc: /* original 02ee, guest PC 0x0c09cbcc */
if(!s->budget--) { s->failed_pc=0x0c09cbccu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbce;
P_0c09cbce: /* original 4211, guest PC 0x0c09cbce */
if(!s->budget--) { s->failed_pc=0x0c09cbceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbd0;
P_0c09cbd0: /* original 8900, guest PC 0x0c09cbd0 */
if(!s->budget--) { s->failed_pc=0x0c09cbd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbd4; }
goto P_0c09cbd2;
P_0c09cbd2: /* original 0e56, guest PC 0x0c09cbd2 */
if(!s->budget--) { s->failed_pc=0x0c09cbd2u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09cbd4;
P_0c09cbd4: /* original 03ee, guest PC 0x0c09cbd4 */
if(!s->budget--) { s->failed_pc=0x0c09cbd4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbd6;
P_0c09cbd6: /* original a015, guest PC 0x0c09cbd6 */
if(!s->budget--) { s->failed_pc=0x0c09cbd6u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc04;
P_0c09cbd8: /* original 7008, guest PC 0x0c09cbd8 */
if(!s->budget--) { s->failed_pc=0x0c09cbd8u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cbda;
P_0c09cbda: /* original 9027, guest PC 0x0c09cbda */
if(!s->budget--) { s->failed_pc=0x0c09cbdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbdc;
P_0c09cbdc: /* original 03ee, guest PC 0x0c09cbdc */
if(!s->budget--) { s->failed_pc=0x0c09cbdcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbde;
P_0c09cbde: /* original 73ff, guest PC 0x0c09cbde */
if(!s->budget--) { s->failed_pc=0x0c09cbdeu; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbe0;
P_0c09cbe0: /* original 0e36, guest PC 0x0c09cbe0 */
if(!s->budget--) { s->failed_pc=0x0c09cbe0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbe2;
P_0c09cbe2: /* original 02ee, guest PC 0x0c09cbe2 */
if(!s->budget--) { s->failed_pc=0x0c09cbe2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbe4;
P_0c09cbe4: /* original 4211, guest PC 0x0c09cbe4 */
if(!s->budget--) { s->failed_pc=0x0c09cbe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbe6;
P_0c09cbe6: /* original 8900, guest PC 0x0c09cbe6 */
if(!s->budget--) { s->failed_pc=0x0c09cbe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cbea; }
goto P_0c09cbe8;
P_0c09cbe8: /* original 0e66, guest PC 0x0c09cbe8 */
if(!s->budget--) { s->failed_pc=0x0c09cbe8u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c09cbea;
P_0c09cbea: /* original 03ee, guest PC 0x0c09cbea */
if(!s->budget--) { s->failed_pc=0x0c09cbeau; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbec;
P_0c09cbec: /* original a00a, guest PC 0x0c09cbec */
if(!s->budget--) { s->failed_pc=0x0c09cbecu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc04;
P_0c09cbee: /* original 700c, guest PC 0x0c09cbee */
if(!s->budget--) { s->failed_pc=0x0c09cbeeu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cbf0;
P_0c09cbf0: /* original 901c, guest PC 0x0c09cbf0 */
if(!s->budget--) { s->failed_pc=0x0c09cbf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2cu,2);
goto P_0c09cbf2;
P_0c09cbf2: /* original 03ee, guest PC 0x0c09cbf2 */
if(!s->budget--) { s->failed_pc=0x0c09cbf2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cbf4;
P_0c09cbf4: /* original 73ff, guest PC 0x0c09cbf4 */
if(!s->budget--) { s->failed_pc=0x0c09cbf4u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cbf6;
P_0c09cbf6: /* original 0e36, guest PC 0x0c09cbf6 */
if(!s->budget--) { s->failed_pc=0x0c09cbf6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cbf8;
P_0c09cbf8: /* original 02ee, guest PC 0x0c09cbf8 */
if(!s->budget--) { s->failed_pc=0x0c09cbf8u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cbfa;
P_0c09cbfa: /* original 4211, guest PC 0x0c09cbfa */
if(!s->budget--) { s->failed_pc=0x0c09cbfau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cbfc;
P_0c09cbfc: /* original 8900, guest PC 0x0c09cbfc */
if(!s->budget--) { s->failed_pc=0x0c09cbfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc00; }
goto P_0c09cbfe;
P_0c09cbfe: /* original 0e46, guest PC 0x0c09cbfe */
if(!s->budget--) { s->failed_pc=0x0c09cbfeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cc00;
P_0c09cc00: /* original 03ee, guest PC 0x0c09cc00 */
if(!s->budget--) { s->failed_pc=0x0c09cc00u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc02;
P_0c09cc02: /* original 900d, guest PC 0x0c09cc02 */
if(!s->budget--) { s->failed_pc=0x0c09cc02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc20u,2);
goto P_0c09cc04;
P_0c09cc04: /* original 0e36, guest PC 0x0c09cc04 */
if(!s->budget--) { s->failed_pc=0x0c09cc04u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc06;
P_0c09cc06: /* original 9112, guest PC 0x0c09cc06 */
if(!s->budget--) { s->failed_pc=0x0c09cc06u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc2eu,2);
goto P_0c09cc08;
P_0c09cc08: /* original 21d8, guest PC 0x0c09cc08 */
if(!s->budget--) { s->failed_pc=0x0c09cc08u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c09cc0a;
P_0c09cc0a: /* original 8932, guest PC 0x0c09cc0a */
if(!s->budget--) { s->failed_pc=0x0c09cc0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc72; }
goto P_0c09cc0c;
P_0c09cc0c: /* original 900a, guest PC 0x0c09cc0c */
if(!s->budget--) { s->failed_pc=0x0c09cc0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cc24u,2);
goto P_0c09cc0e;
P_0c09cc0e: /* original 00ee, guest PC 0x0c09cc0e */
if(!s->budget--) { s->failed_pc=0x0c09cc0eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cc10;
P_0c09cc10: /* original 8800, guest PC 0x0c09cc10 */
if(!s->budget--) { s->failed_pc=0x0c09cc10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cc12;
P_0c09cc12: /* original 890d, guest PC 0x0c09cc12 */
if(!s->budget--) { s->failed_pc=0x0c09cc12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc30; }
goto P_0c09cc14;
P_0c09cc14: /* original 8801, guest PC 0x0c09cc14 */
if(!s->budget--) { s->failed_pc=0x0c09cc14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cc16;
P_0c09cc16: /* original 8916, guest PC 0x0c09cc16 */
if(!s->budget--) { s->failed_pc=0x0c09cc16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc46; }
goto P_0c09cc18;
P_0c09cc18: /* original 8802, guest PC 0x0c09cc18 */
if(!s->budget--) { s->failed_pc=0x0c09cc18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cc1a;
P_0c09cc1a: /* original 891f, guest PC 0x0c09cc1a */
if(!s->budget--) { s->failed_pc=0x0c09cc1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cc5c; }
goto P_0c09cc1c;
P_0c09cc1c: /* original a029, guest PC 0x0c09cc1c */
if(!s->budget--) { s->failed_pc=0x0c09cc1cu; return 0; }
goto P_0c09cc72;
P_0c09cc1e: /* original 0009, guest PC 0x0c09cc1e */
if(!s->budget--) { s->failed_pc=0x0c09cc1eu; return 0; }
return vf3_matrix_family(0x0c09cc20u,s,ram);
P_0c09cc30: /* original 9070, guest PC 0x0c09cc30 */
if(!s->budget--) { s->failed_pc=0x0c09cc30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc32;
P_0c09cc32: /* original 03ee, guest PC 0x0c09cc32 */
if(!s->budget--) { s->failed_pc=0x0c09cc32u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc34;
P_0c09cc34: /* original 7301, guest PC 0x0c09cc34 */
if(!s->budget--) { s->failed_pc=0x0c09cc34u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc36;
P_0c09cc36: /* original 0e36, guest PC 0x0c09cc36 */
if(!s->budget--) { s->failed_pc=0x0c09cc36u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc38;
P_0c09cc38: /* original 02ee, guest PC 0x0c09cc38 */
if(!s->budget--) { s->failed_pc=0x0c09cc38u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc3a;
P_0c09cc3a: /* original 3257, guest PC 0x0c09cc3a */
if(!s->budget--) { s->failed_pc=0x0c09cc3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[5])!=0);
goto P_0c09cc3c;
P_0c09cc3c: /* original 8b00, guest PC 0x0c09cc3c */
if(!s->budget--) { s->failed_pc=0x0c09cc3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc40; }
goto P_0c09cc3e;
P_0c09cc3e: /* original 0ec6, guest PC 0x0c09cc3e */
if(!s->budget--) { s->failed_pc=0x0c09cc3eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc40;
P_0c09cc40: /* original 03ee, guest PC 0x0c09cc40 */
if(!s->budget--) { s->failed_pc=0x0c09cc40u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc42;
P_0c09cc42: /* original a015, guest PC 0x0c09cc42 */
if(!s->budget--) { s->failed_pc=0x0c09cc42u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc70;
P_0c09cc44: /* original 7008, guest PC 0x0c09cc44 */
if(!s->budget--) { s->failed_pc=0x0c09cc44u; return 0; }
r[0]+=0x00000008u;
goto P_0c09cc46;
P_0c09cc46: /* original 9065, guest PC 0x0c09cc46 */
if(!s->budget--) { s->failed_pc=0x0c09cc46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc48;
P_0c09cc48: /* original 03ee, guest PC 0x0c09cc48 */
if(!s->budget--) { s->failed_pc=0x0c09cc48u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc4a;
P_0c09cc4a: /* original 7301, guest PC 0x0c09cc4a */
if(!s->budget--) { s->failed_pc=0x0c09cc4au; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc4c;
P_0c09cc4c: /* original 0e36, guest PC 0x0c09cc4c */
if(!s->budget--) { s->failed_pc=0x0c09cc4cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc4e;
P_0c09cc4e: /* original 02ee, guest PC 0x0c09cc4e */
if(!s->budget--) { s->failed_pc=0x0c09cc4eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc50;
P_0c09cc50: /* original 3267, guest PC 0x0c09cc50 */
if(!s->budget--) { s->failed_pc=0x0c09cc50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[6])!=0);
goto P_0c09cc52;
P_0c09cc52: /* original 8b00, guest PC 0x0c09cc52 */
if(!s->budget--) { s->failed_pc=0x0c09cc52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc56; }
goto P_0c09cc54;
P_0c09cc54: /* original 0ec6, guest PC 0x0c09cc54 */
if(!s->budget--) { s->failed_pc=0x0c09cc54u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc56;
P_0c09cc56: /* original 03ee, guest PC 0x0c09cc56 */
if(!s->budget--) { s->failed_pc=0x0c09cc56u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc58;
P_0c09cc58: /* original a00a, guest PC 0x0c09cc58 */
if(!s->budget--) { s->failed_pc=0x0c09cc58u; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc70;
P_0c09cc5a: /* original 700c, guest PC 0x0c09cc5a */
if(!s->budget--) { s->failed_pc=0x0c09cc5au; return 0; }
r[0]+=0x0000000cu;
goto P_0c09cc5c;
P_0c09cc5c: /* original 905a, guest PC 0x0c09cc5c */
if(!s->budget--) { s->failed_pc=0x0c09cc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd14u,2);
goto P_0c09cc5e;
P_0c09cc5e: /* original 03ee, guest PC 0x0c09cc5e */
if(!s->budget--) { s->failed_pc=0x0c09cc5eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc60;
P_0c09cc60: /* original 7301, guest PC 0x0c09cc60 */
if(!s->budget--) { s->failed_pc=0x0c09cc60u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cc62;
P_0c09cc62: /* original 0e36, guest PC 0x0c09cc62 */
if(!s->budget--) { s->failed_pc=0x0c09cc62u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc64;
P_0c09cc64: /* original 02ee, guest PC 0x0c09cc64 */
if(!s->budget--) { s->failed_pc=0x0c09cc64u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cc66;
P_0c09cc66: /* original 3247, guest PC 0x0c09cc66 */
if(!s->budget--) { s->failed_pc=0x0c09cc66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[4])!=0);
goto P_0c09cc68;
P_0c09cc68: /* original 8b00, guest PC 0x0c09cc68 */
if(!s->budget--) { s->failed_pc=0x0c09cc68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc6c; }
goto P_0c09cc6a;
P_0c09cc6a: /* original 0ec6, guest PC 0x0c09cc6a */
if(!s->budget--) { s->failed_pc=0x0c09cc6au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c09cc6c;
P_0c09cc6c: /* original 03ee, guest PC 0x0c09cc6c */
if(!s->budget--) { s->failed_pc=0x0c09cc6cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cc6e;
P_0c09cc6e: /* original 9052, guest PC 0x0c09cc6e */
if(!s->budget--) { s->failed_pc=0x0c09cc6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd16u,2);
goto P_0c09cc70;
P_0c09cc70: /* original 0e36, guest PC 0x0c09cc70 */
if(!s->budget--) { s->failed_pc=0x0c09cc70u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cc72;
P_0c09cc72: /* original d92d, guest PC 0x0c09cc72 */
if(!s->budget--) { s->failed_pc=0x0c09cc72u; return 0; }
r[9]=read(ram,0x0c09cd28u,4);
goto P_0c09cc74;
P_0c09cc74: /* original 63d3, guest PC 0x0c09cc74 */
if(!s->budget--) { s->failed_pc=0x0c09cc74u; return 0; }
r[3]=r[13];
goto P_0c09cc76;
P_0c09cc76: /* original e604, guest PC 0x0c09cc76 */
if(!s->budget--) { s->failed_pc=0x0c09cc76u; return 0; }
r[6]=0x00000004u;
goto P_0c09cc78;
P_0c09cc78: /* original d82a, guest PC 0x0c09cc78 */
if(!s->budget--) { s->failed_pc=0x0c09cc78u; return 0; }
r[8]=read(ram,0x0c09cd24u,4);
goto P_0c09cc7a;
P_0c09cc7a: /* original 2368, guest PC 0x0c09cc7a */
if(!s->budget--) { s->failed_pc=0x0c09cc7au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09cc7c;
P_0c09cc7c: /* original 8b01, guest PC 0x0c09cc7c */
if(!s->budget--) { s->failed_pc=0x0c09cc7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc82; }
goto P_0c09cc7e;
P_0c09cc7e: /* original a0c0, guest PC 0x0c09cc7e */
if(!s->budget--) { s->failed_pc=0x0c09cc7eu; return 0; }
goto P_0c09ce02;
P_0c09cc80: /* original 0009, guest PC 0x0c09cc80 */
if(!s->budget--) { s->failed_pc=0x0c09cc80u; return 0; }
goto P_0c09cc82;
P_0c09cc82: /* original 9049, guest PC 0x0c09cc82 */
if(!s->budget--) { s->failed_pc=0x0c09cc82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd18u,2);
goto P_0c09cc84;
P_0c09cc84: /* original 00ee, guest PC 0x0c09cc84 */
if(!s->budget--) { s->failed_pc=0x0c09cc84u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09cc86;
P_0c09cc86: /* original 8800, guest PC 0x0c09cc86 */
if(!s->budget--) { s->failed_pc=0x0c09cc86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09cc88;
P_0c09cc88: /* original 890b, guest PC 0x0c09cc88 */
if(!s->budget--) { s->failed_pc=0x0c09cc88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cca2; }
goto P_0c09cc8a;
P_0c09cc8a: /* original 8801, guest PC 0x0c09cc8a */
if(!s->budget--) { s->failed_pc=0x0c09cc8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09cc8c;
P_0c09cc8c: /* original 8928, guest PC 0x0c09cc8c */
if(!s->budget--) { s->failed_pc=0x0c09cc8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cce0; }
goto P_0c09cc8e;
P_0c09cc8e: /* original 8802, guest PC 0x0c09cc8e */
if(!s->budget--) { s->failed_pc=0x0c09cc8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09cc90;
P_0c09cc90: /* original 8b01, guest PC 0x0c09cc90 */
if(!s->budget--) { s->failed_pc=0x0c09cc90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc96; }
goto P_0c09cc92;
P_0c09cc92: /* original a08c, guest PC 0x0c09cc92 */
if(!s->budget--) { s->failed_pc=0x0c09cc92u; return 0; }
goto P_0c09cdae;
P_0c09cc94: /* original 0009, guest PC 0x0c09cc94 */
if(!s->budget--) { s->failed_pc=0x0c09cc94u; return 0; }
goto P_0c09cc96;
P_0c09cc96: /* original 8803, guest PC 0x0c09cc96 */
if(!s->budget--) { s->failed_pc=0x0c09cc96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09cc98;
P_0c09cc98: /* original 8b01, guest PC 0x0c09cc98 */
if(!s->budget--) { s->failed_pc=0x0c09cc98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cc9e; }
goto P_0c09cc9a;
P_0c09cc9a: /* original a0a7, guest PC 0x0c09cc9a */
if(!s->budget--) { s->failed_pc=0x0c09cc9au; return 0; }
goto P_0c09cdec;
P_0c09cc9c: /* original 0009, guest PC 0x0c09cc9c */
if(!s->budget--) { s->failed_pc=0x0c09cc9cu; return 0; }
goto P_0c09cc9e;
P_0c09cc9e: /* original a0b0, guest PC 0x0c09cc9e */
if(!s->budget--) { s->failed_pc=0x0c09cc9eu; return 0; }
goto P_0c09ce02;
P_0c09cca0: /* original 0009, guest PC 0x0c09cca0 */
if(!s->budget--) { s->failed_pc=0x0c09cca0u; return 0; }
goto P_0c09cca2;
P_0c09cca2: /* original 903a, guest PC 0x0c09cca2 */
if(!s->budget--) { s->failed_pc=0x0c09cca2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1au,2);
goto P_0c09cca4;
P_0c09cca4: /* original dc21, guest PC 0x0c09cca4 */
if(!s->budget--) { s->failed_pc=0x0c09cca4u; return 0; }
r[12]=read(ram,0x0c09cd2cu,4);
goto P_0c09cca6;
P_0c09cca6: /* original 03ed, guest PC 0x0c09cca6 */
if(!s->budget--) { s->failed_pc=0x0c09cca6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09cca8;
P_0c09cca8: /* original 6233, guest PC 0x0c09cca8 */
if(!s->budget--) { s->failed_pc=0x0c09cca8u; return 0; }
r[2]=r[3];
goto P_0c09ccaa;
P_0c09ccaa: /* original 4300, guest PC 0x0c09ccaa */
if(!s->budget--) { s->failed_pc=0x0c09ccaau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c09ccac;
P_0c09ccac: /* original 332c, guest PC 0x0c09ccac */
if(!s->budget--) { s->failed_pc=0x0c09ccacu; return 0; }
r[3]+=r[2];
goto P_0c09ccae;
P_0c09ccae: /* original 4308, guest PC 0x0c09ccae */
if(!s->budget--) { s->failed_pc=0x0c09ccaeu; return 0; }
r[3]<<=2;
goto P_0c09ccb0;
P_0c09ccb0: /* original 633f, guest PC 0x0c09ccb0 */
if(!s->budget--) { s->failed_pc=0x0c09ccb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c09ccb2;
P_0c09ccb2: /* original 33cc, guest PC 0x0c09ccb2 */
if(!s->budget--) { s->failed_pc=0x0c09ccb2u; return 0; }
r[3]+=r[12];
goto P_0c09ccb4;
P_0c09ccb4: /* original 5232, guest PC 0x0c09ccb4 */
if(!s->budget--) { s->failed_pc=0x0c09ccb4u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c09ccb6;
P_0c09ccb6: /* original 2228, guest PC 0x0c09ccb6 */
if(!s->budget--) { s->failed_pc=0x0c09ccb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09ccb8;
P_0c09ccb8: /* original 8909, guest PC 0x0c09ccb8 */
if(!s->budget--) { s->failed_pc=0x0c09ccb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ccce; }
goto P_0c09ccba;
P_0c09ccba: /* original 04ed, guest PC 0x0c09ccba */
if(!s->budget--) { s->failed_pc=0x0c09ccbau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ccbc;
P_0c09ccbc: /* original 6343, guest PC 0x0c09ccbc */
if(!s->budget--) { s->failed_pc=0x0c09ccbcu; return 0; }
r[3]=r[4];
goto P_0c09ccbe;
P_0c09ccbe: /* original 4400, guest PC 0x0c09ccbe */
if(!s->budget--) { s->failed_pc=0x0c09ccbeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccc0;
P_0c09ccc0: /* original 343c, guest PC 0x0c09ccc0 */
if(!s->budget--) { s->failed_pc=0x0c09ccc0u; return 0; }
r[4]+=r[3];
goto P_0c09ccc2;
P_0c09ccc2: /* original d31b, guest PC 0x0c09ccc2 */
if(!s->budget--) { s->failed_pc=0x0c09ccc2u; return 0; }
r[3]=read(ram,0x0c09cd30u,4);
goto P_0c09ccc4;
P_0c09ccc4: /* original 4408, guest PC 0x0c09ccc4 */
if(!s->budget--) { s->failed_pc=0x0c09ccc4u; return 0; }
r[4]<<=2;
goto P_0c09ccc6;
P_0c09ccc6: /* original 644f, guest PC 0x0c09ccc6 */
if(!s->budget--) { s->failed_pc=0x0c09ccc6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09ccc8;
P_0c09ccc8: /* original 34cc, guest PC 0x0c09ccc8 */
if(!s->budget--) { s->failed_pc=0x0c09ccc8u; return 0; }
r[4]+=r[12];
goto P_0c09ccca;
P_0c09ccca: /* original 430b, guest PC 0x0c09ccca */
if(!s->budget--) { s->failed_pc=0x0c09cccau; return 0; }
target=r[3];
r[16]=0x0c09ccceu;
r[4]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ccceu) { target=s->pc; goto dispatch; }
goto P_0c09ccce;
P_0c09cccc: /* original 5442, guest PC 0x0c09cccc */
if(!s->budget--) { s->failed_pc=0x0c09ccccu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c09ccce;
P_0c09ccce: /* original 9024, guest PC 0x0c09ccce */
if(!s->budget--) { s->failed_pc=0x0c09ccceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1au,2);
goto P_0c09ccd0;
P_0c09ccd0: /* original 04ed, guest PC 0x0c09ccd0 */
if(!s->budget--) { s->failed_pc=0x0c09ccd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ccd2;
P_0c09ccd2: /* original d016, guest PC 0x0c09ccd2 */
if(!s->budget--) { s->failed_pc=0x0c09ccd2u; return 0; }
r[0]=read(ram,0x0c09cd2cu,4);
goto P_0c09ccd4;
P_0c09ccd4: /* original 6343, guest PC 0x0c09ccd4 */
if(!s->budget--) { s->failed_pc=0x0c09ccd4u; return 0; }
r[3]=r[4];
goto P_0c09ccd6;
P_0c09ccd6: /* original 4400, guest PC 0x0c09ccd6 */
if(!s->budget--) { s->failed_pc=0x0c09ccd6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccd8;
P_0c09ccd8: /* original 343c, guest PC 0x0c09ccd8 */
if(!s->budget--) { s->failed_pc=0x0c09ccd8u; return 0; }
r[4]+=r[3];
goto P_0c09ccda;
P_0c09ccda: /* original 4408, guest PC 0x0c09ccda */
if(!s->budget--) { s->failed_pc=0x0c09ccdau; return 0; }
r[4]<<=2;
goto P_0c09ccdc;
P_0c09ccdc: /* original a065, guest PC 0x0c09ccdc */
if(!s->budget--) { s->failed_pc=0x0c09ccdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09cdaa;
P_0c09ccde: /* original 644f, guest PC 0x0c09ccde */
if(!s->budget--) { s->failed_pc=0x0c09ccdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09cce0;
P_0c09cce0: /* original 901c, guest PC 0x0c09cce0 */
if(!s->budget--) { s->failed_pc=0x0c09cce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1cu,2);
goto P_0c09cce2;
P_0c09cce2: /* original 04ee, guest PC 0x0c09cce2 */
if(!s->budget--) { s->failed_pc=0x0c09cce2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cce4;
P_0c09cce4: /* original d013, guest PC 0x0c09cce4 */
if(!s->budget--) { s->failed_pc=0x0c09cce4u; return 0; }
r[0]=read(ram,0x0c09cd34u,4);
goto P_0c09cce6;
P_0c09cce6: /* original 4408, guest PC 0x0c09cce6 */
if(!s->budget--) { s->failed_pc=0x0c09cce6u; return 0; }
r[4]<<=2;
goto P_0c09cce8;
P_0c09cce8: /* original 4400, guest PC 0x0c09cce8 */
if(!s->budget--) { s->failed_pc=0x0c09cce8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09ccea;
P_0c09ccea: /* original 044e, guest PC 0x0c09ccea */
if(!s->budget--) { s->failed_pc=0x0c09cceau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09ccec;
P_0c09ccec: /* original 6340, guest PC 0x0c09ccec */
if(!s->budget--) { s->failed_pc=0x0c09ccecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c09ccee;
P_0c09ccee: /* original 8441, guest PC 0x0c09ccee */
if(!s->budget--) { s->failed_pc=0x0c09cceeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c09ccf0;
P_0c09ccf0: /* original 4318, guest PC 0x0c09ccf0 */
if(!s->budget--) { s->failed_pc=0x0c09ccf0u; return 0; }
r[3]<<=8;
goto P_0c09ccf2;
P_0c09ccf2: /* original 6433, guest PC 0x0c09ccf2 */
if(!s->budget--) { s->failed_pc=0x0c09ccf2u; return 0; }
r[4]=r[3];
goto P_0c09ccf4;
P_0c09ccf4: /* original 9313, guest PC 0x0c09ccf4 */
if(!s->budget--) { s->failed_pc=0x0c09ccf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd1eu,2);
goto P_0c09ccf6;
P_0c09ccf6: /* original 240b, guest PC 0x0c09ccf6 */
if(!s->budget--) { s->failed_pc=0x0c09ccf6u; return 0; }
r[4]|=r[0];
goto P_0c09ccf8;
P_0c09ccf8: /* original 3430, guest PC 0x0c09ccf8 */
if(!s->budget--) { s->failed_pc=0x0c09ccf8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09ccfa;
P_0c09ccfa: /* original 8b01, guest PC 0x0c09ccfa */
if(!s->budget--) { s->failed_pc=0x0c09ccfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd00; }
goto P_0c09ccfc;
P_0c09ccfc: /* original a04d, guest PC 0x0c09ccfc */
if(!s->budget--) { s->failed_pc=0x0c09ccfcu; return 0; }
r[5]=r[12];
goto P_0c09cd9a;
P_0c09ccfe: /* original 65c3, guest PC 0x0c09ccfe */
if(!s->budget--) { s->failed_pc=0x0c09ccfeu; return 0; }
r[5]=r[12];
goto P_0c09cd00;
P_0c09cd00: /* original 920e, guest PC 0x0c09cd00 */
if(!s->budget--) { s->failed_pc=0x0c09cd00u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd20u,2);
goto P_0c09cd02;
P_0c09cd02: /* original 3420, guest PC 0x0c09cd02 */
if(!s->budget--) { s->failed_pc=0x0c09cd02u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd04;
P_0c09cd04: /* original 8b01, guest PC 0x0c09cd04 */
if(!s->budget--) { s->failed_pc=0x0c09cd04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd0a; }
goto P_0c09cd06;
P_0c09cd06: /* original a048, guest PC 0x0c09cd06 */
if(!s->budget--) { s->failed_pc=0x0c09cd06u; return 0; }
r[5]=0x00000001u;
goto P_0c09cd9a;
P_0c09cd08: /* original e501, guest PC 0x0c09cd08 */
if(!s->budget--) { s->failed_pc=0x0c09cd08u; return 0; }
r[5]=0x00000001u;
goto P_0c09cd0a;
P_0c09cd0a: /* original 910a, guest PC 0x0c09cd0a */
if(!s->budget--) { s->failed_pc=0x0c09cd0au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cd22u,2);
goto P_0c09cd0c;
P_0c09cd0c: /* original 3410, guest PC 0x0c09cd0c */
if(!s->budget--) { s->failed_pc=0x0c09cd0cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd0e;
P_0c09cd0e: /* original 8b13, guest PC 0x0c09cd0e */
if(!s->budget--) { s->failed_pc=0x0c09cd0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd38; }
goto P_0c09cd10;
P_0c09cd10: /* original a043, guest PC 0x0c09cd10 */
if(!s->budget--) { s->failed_pc=0x0c09cd10u; return 0; }
r[5]=0x00000005u;
goto P_0c09cd9a;
P_0c09cd12: /* original e505, guest PC 0x0c09cd12 */
if(!s->budget--) { s->failed_pc=0x0c09cd12u; return 0; }
r[5]=0x00000005u;
return vf3_matrix_family(0x0c09cd14u,s,ram);
P_0c09cd38: /* original 9343, guest PC 0x0c09cd38 */
if(!s->budget--) { s->failed_pc=0x0c09cd38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc2u,2);
goto P_0c09cd3a;
P_0c09cd3a: /* original 3430, guest PC 0x0c09cd3a */
if(!s->budget--) { s->failed_pc=0x0c09cd3au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd3c;
P_0c09cd3c: /* original 8b01, guest PC 0x0c09cd3c */
if(!s->budget--) { s->failed_pc=0x0c09cd3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd42; }
goto P_0c09cd3e;
P_0c09cd3e: /* original a02c, guest PC 0x0c09cd3e */
if(!s->budget--) { s->failed_pc=0x0c09cd3eu; return 0; }
r[5]=r[10];
goto P_0c09cd9a;
P_0c09cd40: /* original 65a3, guest PC 0x0c09cd40 */
if(!s->budget--) { s->failed_pc=0x0c09cd40u; return 0; }
r[5]=r[10];
goto P_0c09cd42;
P_0c09cd42: /* original 923f, guest PC 0x0c09cd42 */
if(!s->budget--) { s->failed_pc=0x0c09cd42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc4u,2);
goto P_0c09cd44;
P_0c09cd44: /* original 3420, guest PC 0x0c09cd44 */
if(!s->budget--) { s->failed_pc=0x0c09cd44u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd46;
P_0c09cd46: /* original 8b01, guest PC 0x0c09cd46 */
if(!s->budget--) { s->failed_pc=0x0c09cd46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd4c; }
goto P_0c09cd48;
P_0c09cd48: /* original a027, guest PC 0x0c09cd48 */
if(!s->budget--) { s->failed_pc=0x0c09cd48u; return 0; }
r[5]=r[6];
goto P_0c09cd9a;
P_0c09cd4a: /* original 6563, guest PC 0x0c09cd4a */
if(!s->budget--) { s->failed_pc=0x0c09cd4au; return 0; }
r[5]=r[6];
goto P_0c09cd4c;
P_0c09cd4c: /* original 913b, guest PC 0x0c09cd4c */
if(!s->budget--) { s->failed_pc=0x0c09cd4cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc6u,2);
goto P_0c09cd4e;
P_0c09cd4e: /* original 3410, guest PC 0x0c09cd4e */
if(!s->budget--) { s->failed_pc=0x0c09cd4eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd50;
P_0c09cd50: /* original 8b01, guest PC 0x0c09cd50 */
if(!s->budget--) { s->failed_pc=0x0c09cd50u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd56; }
goto P_0c09cd52;
P_0c09cd52: /* original a022, guest PC 0x0c09cd52 */
if(!s->budget--) { s->failed_pc=0x0c09cd52u; return 0; }
r[5]=0x0000000au;
goto P_0c09cd9a;
P_0c09cd54: /* original e50a, guest PC 0x0c09cd54 */
if(!s->budget--) { s->failed_pc=0x0c09cd54u; return 0; }
r[5]=0x0000000au;
goto P_0c09cd56;
P_0c09cd56: /* original 9337, guest PC 0x0c09cd56 */
if(!s->budget--) { s->failed_pc=0x0c09cd56u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdc8u,2);
goto P_0c09cd58;
P_0c09cd58: /* original 3430, guest PC 0x0c09cd58 */
if(!s->budget--) { s->failed_pc=0x0c09cd58u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd5a;
P_0c09cd5a: /* original 8b01, guest PC 0x0c09cd5a */
if(!s->budget--) { s->failed_pc=0x0c09cd5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd60; }
goto P_0c09cd5c;
P_0c09cd5c: /* original a01d, guest PC 0x0c09cd5c */
if(!s->budget--) { s->failed_pc=0x0c09cd5cu; return 0; }
r[5]=0x00000006u;
goto P_0c09cd9a;
P_0c09cd5e: /* original e506, guest PC 0x0c09cd5e */
if(!s->budget--) { s->failed_pc=0x0c09cd5eu; return 0; }
r[5]=0x00000006u;
goto P_0c09cd60;
P_0c09cd60: /* original 9233, guest PC 0x0c09cd60 */
if(!s->budget--) { s->failed_pc=0x0c09cd60u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdcau,2);
goto P_0c09cd62;
P_0c09cd62: /* original 3420, guest PC 0x0c09cd62 */
if(!s->budget--) { s->failed_pc=0x0c09cd62u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd64;
P_0c09cd64: /* original 8b01, guest PC 0x0c09cd64 */
if(!s->budget--) { s->failed_pc=0x0c09cd64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd6a; }
goto P_0c09cd66;
P_0c09cd66: /* original a018, guest PC 0x0c09cd66 */
if(!s->budget--) { s->failed_pc=0x0c09cd66u; return 0; }
r[5]=0x00000002u;
goto P_0c09cd9a;
P_0c09cd68: /* original e502, guest PC 0x0c09cd68 */
if(!s->budget--) { s->failed_pc=0x0c09cd68u; return 0; }
r[5]=0x00000002u;
goto P_0c09cd6a;
P_0c09cd6a: /* original 912f, guest PC 0x0c09cd6a */
if(!s->budget--) { s->failed_pc=0x0c09cd6au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdccu,2);
goto P_0c09cd6c;
P_0c09cd6c: /* original 3410, guest PC 0x0c09cd6c */
if(!s->budget--) { s->failed_pc=0x0c09cd6cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd6e;
P_0c09cd6e: /* original 8b01, guest PC 0x0c09cd6e */
if(!s->budget--) { s->failed_pc=0x0c09cd6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd74; }
goto P_0c09cd70;
P_0c09cd70: /* original a013, guest PC 0x0c09cd70 */
if(!s->budget--) { s->failed_pc=0x0c09cd70u; return 0; }
r[5]=0x00000008u;
goto P_0c09cd9a;
P_0c09cd72: /* original e508, guest PC 0x0c09cd72 */
if(!s->budget--) { s->failed_pc=0x0c09cd72u; return 0; }
r[5]=0x00000008u;
goto P_0c09cd74;
P_0c09cd74: /* original 932b, guest PC 0x0c09cd74 */
if(!s->budget--) { s->failed_pc=0x0c09cd74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdceu,2);
goto P_0c09cd76;
P_0c09cd76: /* original 3430, guest PC 0x0c09cd76 */
if(!s->budget--) { s->failed_pc=0x0c09cd76u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd78;
P_0c09cd78: /* original 8b01, guest PC 0x0c09cd78 */
if(!s->budget--) { s->failed_pc=0x0c09cd78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd7e; }
goto P_0c09cd7a;
P_0c09cd7a: /* original a00e, guest PC 0x0c09cd7a */
if(!s->budget--) { s->failed_pc=0x0c09cd7au; return 0; }
r[5]=0x00000007u;
goto P_0c09cd9a;
P_0c09cd7c: /* original e507, guest PC 0x0c09cd7c */
if(!s->budget--) { s->failed_pc=0x0c09cd7cu; return 0; }
r[5]=0x00000007u;
goto P_0c09cd7e;
P_0c09cd7e: /* original 9227, guest PC 0x0c09cd7e */
if(!s->budget--) { s->failed_pc=0x0c09cd7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd0u,2);
goto P_0c09cd80;
P_0c09cd80: /* original 3420, guest PC 0x0c09cd80 */
if(!s->budget--) { s->failed_pc=0x0c09cd80u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c09cd82;
P_0c09cd82: /* original 8b01, guest PC 0x0c09cd82 */
if(!s->budget--) { s->failed_pc=0x0c09cd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd88; }
goto P_0c09cd84;
P_0c09cd84: /* original a009, guest PC 0x0c09cd84 */
if(!s->budget--) { s->failed_pc=0x0c09cd84u; return 0; }
r[5]=0x0000000bu;
goto P_0c09cd9a;
P_0c09cd86: /* original e50b, guest PC 0x0c09cd86 */
if(!s->budget--) { s->failed_pc=0x0c09cd86u; return 0; }
r[5]=0x0000000bu;
goto P_0c09cd88;
P_0c09cd88: /* original 9123, guest PC 0x0c09cd88 */
if(!s->budget--) { s->failed_pc=0x0c09cd88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd2u,2);
goto P_0c09cd8a;
P_0c09cd8a: /* original 3410, guest PC 0x0c09cd8a */
if(!s->budget--) { s->failed_pc=0x0c09cd8au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c09cd8c;
P_0c09cd8c: /* original 8b01, guest PC 0x0c09cd8c */
if(!s->budget--) { s->failed_pc=0x0c09cd8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cd92; }
goto P_0c09cd8e;
P_0c09cd8e: /* original a004, guest PC 0x0c09cd8e */
if(!s->budget--) { s->failed_pc=0x0c09cd8eu; return 0; }
r[5]=0x0000000cu;
goto P_0c09cd9a;
P_0c09cd90: /* original e50c, guest PC 0x0c09cd90 */
if(!s->budget--) { s->failed_pc=0x0c09cd90u; return 0; }
r[5]=0x0000000cu;
goto P_0c09cd92;
P_0c09cd92: /* original 931f, guest PC 0x0c09cd92 */
if(!s->budget--) { s->failed_pc=0x0c09cd92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd4u,2);
goto P_0c09cd94;
P_0c09cd94: /* original 3430, guest PC 0x0c09cd94 */
if(!s->budget--) { s->failed_pc=0x0c09cd94u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c09cd96;
P_0c09cd96: /* original 8b34, guest PC 0x0c09cd96 */
if(!s->budget--) { s->failed_pc=0x0c09cd96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ce02; }
goto P_0c09cd98;
P_0c09cd98: /* original e51f, guest PC 0x0c09cd98 */
if(!s->budget--) { s->failed_pc=0x0c09cd98u; return 0; }
r[5]=0x0000001fu;
goto P_0c09cd9a;
P_0c09cd9a: /* original d310, guest PC 0x0c09cd9a */
if(!s->budget--) { s->failed_pc=0x0c09cd9au; return 0; }
r[3]=read(ram,0x0c09cddcu,4);
goto P_0c09cd9c;
P_0c09cd9c: /* original 430b, guest PC 0x0c09cd9c */
if(!s->budget--) { s->failed_pc=0x0c09cd9cu; return 0; }
target=r[3];
r[16]=0x0c09cda0u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cda0u) { target=s->pc; goto dispatch; }
goto P_0c09cda0;
P_0c09cd9e: /* original e400, guest PC 0x0c09cd9e */
if(!s->budget--) { s->failed_pc=0x0c09cd9eu; return 0; }
r[4]=0x00000000u;
goto P_0c09cda0;
P_0c09cda0: /* original 9019, guest PC 0x0c09cda0 */
if(!s->budget--) { s->failed_pc=0x0c09cda0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd6u,2);
goto P_0c09cda2;
P_0c09cda2: /* original 04ee, guest PC 0x0c09cda2 */
if(!s->budget--) { s->failed_pc=0x0c09cda2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cda4;
P_0c09cda4: /* original d00e, guest PC 0x0c09cda4 */
if(!s->budget--) { s->failed_pc=0x0c09cda4u; return 0; }
r[0]=read(ram,0x0c09cde0u,4);
goto P_0c09cda6;
P_0c09cda6: /* original 4408, guest PC 0x0c09cda6 */
if(!s->budget--) { s->failed_pc=0x0c09cda6u; return 0; }
r[4]<<=2;
goto P_0c09cda8;
P_0c09cda8: /* original 4400, guest PC 0x0c09cda8 */
if(!s->budget--) { s->failed_pc=0x0c09cda8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09cdaa;
P_0c09cdaa: /* original a028, guest PC 0x0c09cdaa */
if(!s->budget--) { s->failed_pc=0x0c09cdaau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdfe;
P_0c09cdac: /* original 044e, guest PC 0x0c09cdac */
if(!s->budget--) { s->failed_pc=0x0c09cdacu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdae;
P_0c09cdae: /* original 9013, guest PC 0x0c09cdae */
if(!s->budget--) { s->failed_pc=0x0c09cdaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cdd8u,2);
goto P_0c09cdb0;
P_0c09cdb0: /* original d30d, guest PC 0x0c09cdb0 */
if(!s->budget--) { s->failed_pc=0x0c09cdb0u; return 0; }
r[3]=read(ram,0x0c09cde8u,4);
goto P_0c09cdb2;
P_0c09cdb2: /* original 04ee, guest PC 0x0c09cdb2 */
if(!s->budget--) { s->failed_pc=0x0c09cdb2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09cdb4;
P_0c09cdb4: /* original d00b, guest PC 0x0c09cdb4 */
if(!s->budget--) { s->failed_pc=0x0c09cdb4u; return 0; }
r[0]=read(ram,0x0c09cde4u,4);
goto P_0c09cdb6;
P_0c09cdb6: /* original 4408, guest PC 0x0c09cdb6 */
if(!s->budget--) { s->failed_pc=0x0c09cdb6u; return 0; }
r[4]<<=2;
goto P_0c09cdb8;
P_0c09cdb8: /* original 4400, guest PC 0x0c09cdb8 */
if(!s->budget--) { s->failed_pc=0x0c09cdb8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09cdba;
P_0c09cdba: /* original 430b, guest PC 0x0c09cdba */
if(!s->budget--) { s->failed_pc=0x0c09cdbau; return 0; }
target=r[3];
r[16]=0x0c09cdbeu;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cdbeu) { target=s->pc; goto dispatch; }
goto P_0c09cdbe;
P_0c09cdbc: /* original 044e, guest PC 0x0c09cdbc */
if(!s->budget--) { s->failed_pc=0x0c09cdbcu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09cdbe;
P_0c09cdbe: /* original a020, guest PC 0x0c09cdbe */
if(!s->budget--) { s->failed_pc=0x0c09cdbeu; return 0; }
goto P_0c09ce02;
P_0c09cdc0: /* original 0009, guest PC 0x0c09cdc0 */
if(!s->budget--) { s->failed_pc=0x0c09cdc0u; return 0; }
return vf3_matrix_family(0x0c09cdc2u,s,ram);
P_0c09cdec: /* original e009, guest PC 0x0c09cdec */
if(!s->budget--) { s->failed_pc=0x0c09cdecu; return 0; }
r[0]=0x00000009u;
goto P_0c09cdee;
P_0c09cdee: /* original 80eb, guest PC 0x0c09cdee */
if(!s->budget--) { s->failed_pc=0x0c09cdeeu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cdf0;
P_0c09cdf0: /* original e010, guest PC 0x0c09cdf0 */
if(!s->budget--) { s->failed_pc=0x0c09cdf0u; return 0; }
r[0]=0x00000010u;
goto P_0c09cdf2;
P_0c09cdf2: /* original e376, guest PC 0x0c09cdf2 */
if(!s->budget--) { s->failed_pc=0x0c09cdf2u; return 0; }
r[3]=0x00000076u;
goto P_0c09cdf4;
P_0c09cdf4: /* original e500, guest PC 0x0c09cdf4 */
if(!s->budget--) { s->failed_pc=0x0c09cdf4u; return 0; }
r[5]=0x00000000u;
goto P_0c09cdf6;
P_0c09cdf6: /* original 0e34, guest PC 0x0c09cdf6 */
if(!s->budget--) { s->failed_pc=0x0c09cdf6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cdf8;
P_0c09cdf8: /* original 490b, guest PC 0x0c09cdf8 */
if(!s->budget--) { s->failed_pc=0x0c09cdf8u; return 0; }
target=r[9];
r[16]=0x0c09cdfcu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09cdfcu) { target=s->pc; goto dispatch; }
goto P_0c09cdfc;
P_0c09cdfa: /* original 6483, guest PC 0x0c09cdfa */
if(!s->budget--) { s->failed_pc=0x0c09cdfau; return 0; }
r[4]=r[8];
goto P_0c09cdfc;
P_0c09cdfc: /* original 943f, guest PC 0x0c09cdfc */
if(!s->budget--) { s->failed_pc=0x0c09cdfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce7eu,2);
goto P_0c09cdfe;
P_0c09cdfe: /* original 4b0b, guest PC 0x0c09cdfe */
if(!s->budget--) { s->failed_pc=0x0c09cdfeu; return 0; }
target=r[11];
r[16]=0x0c09ce02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce02u) { target=s->pc; goto dispatch; }
goto P_0c09ce02;
P_0c09ce00: /* original 0009, guest PC 0x0c09ce00 */
if(!s->budget--) { s->failed_pc=0x0c09ce00u; return 0; }
goto P_0c09ce02;
P_0c09ce02: /* original e208, guest PC 0x0c09ce02 */
if(!s->budget--) { s->failed_pc=0x0c09ce02u; return 0; }
r[2]=0x00000008u;
goto P_0c09ce04;
P_0c09ce04: /* original 22d8, guest PC 0x0c09ce04 */
if(!s->budget--) { s->failed_pc=0x0c09ce04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09ce06;
P_0c09ce06: /* original 890a, guest PC 0x0c09ce06 */
if(!s->budget--) { s->failed_pc=0x0c09ce06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ce1e; }
goto P_0c09ce08;
P_0c09ce08: /* original e001, guest PC 0x0c09ce08 */
if(!s->budget--) { s->failed_pc=0x0c09ce08u; return 0; }
r[0]=0x00000001u;
goto P_0c09ce0a;
P_0c09ce0a: /* original 80eb, guest PC 0x0c09ce0a */
if(!s->budget--) { s->failed_pc=0x0c09ce0au; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ce0c;
P_0c09ce0c: /* original e010, guest PC 0x0c09ce0c */
if(!s->budget--) { s->failed_pc=0x0c09ce0cu; return 0; }
r[0]=0x00000010u;
goto P_0c09ce0e;
P_0c09ce0e: /* original e372, guest PC 0x0c09ce0e */
if(!s->budget--) { s->failed_pc=0x0c09ce0eu; return 0; }
r[3]=0x00000072u;
goto P_0c09ce10;
P_0c09ce10: /* original e500, guest PC 0x0c09ce10 */
if(!s->budget--) { s->failed_pc=0x0c09ce10u; return 0; }
r[5]=0x00000000u;
goto P_0c09ce12;
P_0c09ce12: /* original 0e34, guest PC 0x0c09ce12 */
if(!s->budget--) { s->failed_pc=0x0c09ce12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09ce14;
P_0c09ce14: /* original 490b, guest PC 0x0c09ce14 */
if(!s->budget--) { s->failed_pc=0x0c09ce14u; return 0; }
target=r[9];
r[16]=0x0c09ce18u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce18u) { target=s->pc; goto dispatch; }
goto P_0c09ce18;
P_0c09ce16: /* original 6483, guest PC 0x0c09ce16 */
if(!s->budget--) { s->failed_pc=0x0c09ce16u; return 0; }
r[4]=r[8];
goto P_0c09ce18;
P_0c09ce18: /* original 9431, guest PC 0x0c09ce18 */
if(!s->budget--) { s->failed_pc=0x0c09ce18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce7eu,2);
goto P_0c09ce1a;
P_0c09ce1a: /* original 4b0b, guest PC 0x0c09ce1a */
if(!s->budget--) { s->failed_pc=0x0c09ce1au; return 0; }
target=r[11];
r[16]=0x0c09ce1eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce1eu) { target=s->pc; goto dispatch; }
goto P_0c09ce1e;
P_0c09ce1c: /* original 0009, guest PC 0x0c09ce1c */
if(!s->budget--) { s->failed_pc=0x0c09ce1cu; return 0; }
goto P_0c09ce1e;
P_0c09ce1e: /* original e302, guest PC 0x0c09ce1e */
if(!s->budget--) { s->failed_pc=0x0c09ce1eu; return 0; }
r[3]=0x00000002u;
goto P_0c09ce20;
P_0c09ce20: /* original 2d38, guest PC 0x0c09ce20 */
if(!s->budget--) { s->failed_pc=0x0c09ce20u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c09ce22;
P_0c09ce22: /* original 8909, guest PC 0x0c09ce22 */
if(!s->budget--) { s->failed_pc=0x0c09ce22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ce38; }
goto P_0c09ce24;
P_0c09ce24: /* original e009, guest PC 0x0c09ce24 */
if(!s->budget--) { s->failed_pc=0x0c09ce24u; return 0; }
r[0]=0x00000009u;
goto P_0c09ce26;
P_0c09ce26: /* original 80eb, guest PC 0x0c09ce26 */
if(!s->budget--) { s->failed_pc=0x0c09ce26u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09ce28;
P_0c09ce28: /* original e010, guest PC 0x0c09ce28 */
if(!s->budget--) { s->failed_pc=0x0c09ce28u; return 0; }
r[0]=0x00000010u;
goto P_0c09ce2a;
P_0c09ce2a: /* original 9429, guest PC 0x0c09ce2a */
if(!s->budget--) { s->failed_pc=0x0c09ce2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ce80u,2);
goto P_0c09ce2c;
P_0c09ce2c: /* original e276, guest PC 0x0c09ce2c */
if(!s->budget--) { s->failed_pc=0x0c09ce2cu; return 0; }
r[2]=0x00000076u;
goto P_0c09ce2e;
P_0c09ce2e: /* original 4b0b, guest PC 0x0c09ce2e */
if(!s->budget--) { s->failed_pc=0x0c09ce2eu; return 0; }
target=r[11];
r[16]=0x0c09ce32u;
write(ram,r[14]+r[0],r[2],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce32u) { target=s->pc; goto dispatch; }
goto P_0c09ce32;
P_0c09ce30: /* original 0e24, guest PC 0x0c09ce30 */
if(!s->budget--) { s->failed_pc=0x0c09ce30u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ce32;
P_0c09ce32: /* original e500, guest PC 0x0c09ce32 */
if(!s->budget--) { s->failed_pc=0x0c09ce32u; return 0; }
r[5]=0x00000000u;
goto P_0c09ce34;
P_0c09ce34: /* original 490b, guest PC 0x0c09ce34 */
if(!s->budget--) { s->failed_pc=0x0c09ce34u; return 0; }
target=r[9];
r[16]=0x0c09ce38u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09ce38u) { target=s->pc; goto dispatch; }
goto P_0c09ce38;
P_0c09ce36: /* original 6483, guest PC 0x0c09ce36 */
if(!s->budget--) { s->failed_pc=0x0c09ce36u; return 0; }
r[4]=r[8];
goto P_0c09ce38;
P_0c09ce38: /* original 4f26, guest PC 0x0c09ce38 */
if(!s->budget--) { s->failed_pc=0x0c09ce38u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ce3a;
P_0c09ce3a: /* original 68f6, guest PC 0x0c09ce3a */
if(!s->budget--) { s->failed_pc=0x0c09ce3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09ce3c;
P_0c09ce3c: /* original 69f6, guest PC 0x0c09ce3c */
if(!s->budget--) { s->failed_pc=0x0c09ce3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ce3e;
P_0c09ce3e: /* original 6af6, guest PC 0x0c09ce3e */
if(!s->budget--) { s->failed_pc=0x0c09ce3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ce40;
P_0c09ce40: /* original 6bf6, guest PC 0x0c09ce40 */
if(!s->budget--) { s->failed_pc=0x0c09ce40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ce42;
P_0c09ce42: /* original 6cf6, guest PC 0x0c09ce42 */
if(!s->budget--) { s->failed_pc=0x0c09ce42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ce44;
P_0c09ce44: /* original 6df6, guest PC 0x0c09ce44 */
if(!s->budget--) { s->failed_pc=0x0c09ce44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ce46;
P_0c09ce46: /* original 000b, guest PC 0x0c09ce46 */
if(!s->budget--) { s->failed_pc=0x0c09ce46u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09ce48: /* original 6ef6, guest PC 0x0c09ce48 */
if(!s->budget--) { s->failed_pc=0x0c09ce48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09ce4au,s,ram);
P_0c0a1f50: /* original 2fe6, guest PC 0x0c0a1f50 */
if(!s->budget--) { s->failed_pc=0x0c0a1f50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1f52;
P_0c0a1f52: /* original 2fd6, guest PC 0x0c0a1f52 */
if(!s->budget--) { s->failed_pc=0x0c0a1f52u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a1f54;
P_0c0a1f54: /* original 4f22, guest PC 0x0c0a1f54 */
if(!s->budget--) { s->failed_pc=0x0c0a1f54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1f56;
P_0c0a1f56: /* original d328, guest PC 0x0c0a1f56 */
if(!s->budget--) { s->failed_pc=0x0c0a1f56u; return 0; }
r[3]=read(ram,0x0c0a1ff8u,4);
goto P_0c0a1f58;
P_0c0a1f58: /* original 430b, guest PC 0x0c0a1f58 */
if(!s->budget--) { s->failed_pc=0x0c0a1f58u; return 0; }
target=r[3];
r[16]=0x0c0a1f5cu;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a1f5cu) { target=s->pc; goto dispatch; }
goto P_0c0a1f5c;
P_0c0a1f5a: /* original 6e43, guest PC 0x0c0a1f5a */
if(!s->budget--) { s->failed_pc=0x0c0a1f5au; return 0; }
r[14]=r[4];
goto P_0c0a1f5c;
P_0c0a1f5c: /* original 6d03, guest PC 0x0c0a1f5c */
if(!s->budget--) { s->failed_pc=0x0c0a1f5cu; return 0; }
r[13]=r[0];
goto P_0c0a1f5e;
P_0c0a1f5e: /* original 62d1, guest PC 0x0c0a1f5e */
if(!s->budget--) { s->failed_pc=0x0c0a1f5eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c0a1f60;
P_0c0a1f60: /* original 2228, guest PC 0x0c0a1f60 */
if(!s->budget--) { s->failed_pc=0x0c0a1f60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a1f62;
P_0c0a1f62: /* original 8931, guest PC 0x0c0a1f62 */
if(!s->budget--) { s->failed_pc=0x0c0a1f62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc8; }
goto P_0c0a1f64;
P_0c0a1f64: /* original 85d1, guest PC 0x0c0a1f64 */
if(!s->budget--) { s->failed_pc=0x0c0a1f64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c0a1f66;
P_0c0a1f66: /* original 2008, guest PC 0x0c0a1f66 */
if(!s->budget--) { s->failed_pc=0x0c0a1f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1f68;
P_0c0a1f68: /* original 892c, guest PC 0x0c0a1f68 */
if(!s->budget--) { s->failed_pc=0x0c0a1f68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc4; }
goto P_0c0a1f6a;
P_0c0a1f6a: /* original d324, guest PC 0x0c0a1f6a */
if(!s->budget--) { s->failed_pc=0x0c0a1f6au; return 0; }
r[3]=read(ram,0x0c0a1ffcu,4);
goto P_0c0a1f6c;
P_0c0a1f6c: /* original 430b, guest PC 0x0c0a1f6c */
if(!s->budget--) { s->failed_pc=0x0c0a1f6cu; return 0; }
target=r[3];
r[16]=0x0c0a1f70u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a1f70u) { target=s->pc; goto dispatch; }
goto P_0c0a1f70;
P_0c0a1f6e: /* original 0009, guest PC 0x0c0a1f6e */
if(!s->budget--) { s->failed_pc=0x0c0a1f6eu; return 0; }
goto P_0c0a1f70;
P_0c0a1f70: /* original 2008, guest PC 0x0c0a1f70 */
if(!s->budget--) { s->failed_pc=0x0c0a1f70u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1f72;
P_0c0a1f72: /* original 8b0b, guest PC 0x0c0a1f72 */
if(!s->budget--) { s->failed_pc=0x0c0a1f72u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1f8c; }
goto P_0c0a1f74;
P_0c0a1f74: /* original 60e3, guest PC 0x0c0a1f74 */
if(!s->budget--) { s->failed_pc=0x0c0a1f74u; return 0; }
r[0]=r[14];
goto P_0c0a1f76;
P_0c0a1f76: /* original 8801, guest PC 0x0c0a1f76 */
if(!s->budget--) { s->failed_pc=0x0c0a1f76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1f78;
P_0c0a1f78: /* original 8b01, guest PC 0x0c0a1f78 */
if(!s->budget--) { s->failed_pc=0x0c0a1f78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1f7e; }
goto P_0c0a1f7a;
P_0c0a1f7a: /* original a026, guest PC 0x0c0a1f7a */
if(!s->budget--) { s->failed_pc=0x0c0a1f7au; return 0; }
r[0]=0x00000010u;
goto P_0c0a1fca;
P_0c0a1f7c: /* original e010, guest PC 0x0c0a1f7c */
if(!s->budget--) { s->failed_pc=0x0c0a1f7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0a1f7e;
P_0c0a1f7e: /* original 8802, guest PC 0x0c0a1f7e */
if(!s->budget--) { s->failed_pc=0x0c0a1f7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1f80;
P_0c0a1f80: /* original 8902, guest PC 0x0c0a1f80 */
if(!s->budget--) { s->failed_pc=0x0c0a1f80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1f88; }
goto P_0c0a1f82;
P_0c0a1f82: /* original 60e3, guest PC 0x0c0a1f82 */
if(!s->budget--) { s->failed_pc=0x0c0a1f82u; return 0; }
r[0]=r[14];
goto P_0c0a1f84;
P_0c0a1f84: /* original 8803, guest PC 0x0c0a1f84 */
if(!s->budget--) { s->failed_pc=0x0c0a1f84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1f86;
P_0c0a1f86: /* original 8b1f, guest PC 0x0c0a1f86 */
if(!s->budget--) { s->failed_pc=0x0c0a1f86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1f88;
P_0c0a1f88: /* original a01f, guest PC 0x0c0a1f88 */
if(!s->budget--) { s->failed_pc=0x0c0a1f88u; return 0; }
r[0]=0x00000000u;
goto P_0c0a1fca;
P_0c0a1f8a: /* original e000, guest PC 0x0c0a1f8a */
if(!s->budget--) { s->failed_pc=0x0c0a1f8au; return 0; }
r[0]=0x00000000u;
goto P_0c0a1f8c;
P_0c0a1f8c: /* original e038, guest PC 0x0c0a1f8c */
if(!s->budget--) { s->failed_pc=0x0c0a1f8cu; return 0; }
r[0]=0x00000038u;
goto P_0c0a1f8e;
P_0c0a1f8e: /* original 02dd, guest PC 0x0c0a1f8e */
if(!s->budget--) { s->failed_pc=0x0c0a1f8eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a1f90;
P_0c0a1f90: /* original e30c, guest PC 0x0c0a1f90 */
if(!s->budget--) { s->failed_pc=0x0c0a1f90u; return 0; }
r[3]=0x0000000cu;
goto P_0c0a1f92;
P_0c0a1f92: /* original 622d, guest PC 0x0c0a1f92 */
if(!s->budget--) { s->failed_pc=0x0c0a1f92u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a1f94;
P_0c0a1f94: /* original 3233, guest PC 0x0c0a1f94 */
if(!s->budget--) { s->failed_pc=0x0c0a1f94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0a1f96;
P_0c0a1f96: /* original 890a, guest PC 0x0c0a1f96 */
if(!s->budget--) { s->failed_pc=0x0c0a1f96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fae; }
goto P_0c0a1f98;
P_0c0a1f98: /* original 60e3, guest PC 0x0c0a1f98 */
if(!s->budget--) { s->failed_pc=0x0c0a1f98u; return 0; }
r[0]=r[14];
goto P_0c0a1f9a;
P_0c0a1f9a: /* original 8801, guest PC 0x0c0a1f9a */
if(!s->budget--) { s->failed_pc=0x0c0a1f9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1f9c;
P_0c0a1f9c: /* original 8905, guest PC 0x0c0a1f9c */
if(!s->budget--) { s->failed_pc=0x0c0a1f9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1faa; }
goto P_0c0a1f9e;
P_0c0a1f9e: /* original 60e3, guest PC 0x0c0a1f9e */
if(!s->budget--) { s->failed_pc=0x0c0a1f9eu; return 0; }
r[0]=r[14];
goto P_0c0a1fa0;
P_0c0a1fa0: /* original 8802, guest PC 0x0c0a1fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1fa2;
P_0c0a1fa2: /* original 890d, guest PC 0x0c0a1fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fa4;
P_0c0a1fa4: /* original 60e3, guest PC 0x0c0a1fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa4u; return 0; }
r[0]=r[14];
goto P_0c0a1fa6;
P_0c0a1fa6: /* original 8803, guest PC 0x0c0a1fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1fa8;
P_0c0a1fa8: /* original 8b0e, guest PC 0x0c0a1fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1faa;
P_0c0a1faa: /* original a00e, guest PC 0x0c0a1faa */
if(!s->budget--) { s->failed_pc=0x0c0a1faau; return 0; }
r[0]=0x00000008u;
goto P_0c0a1fca;
P_0c0a1fac: /* original e008, guest PC 0x0c0a1fac */
if(!s->budget--) { s->failed_pc=0x0c0a1facu; return 0; }
r[0]=0x00000008u;
goto P_0c0a1fae;
P_0c0a1fae: /* original 60e3, guest PC 0x0c0a1fae */
if(!s->budget--) { s->failed_pc=0x0c0a1faeu; return 0; }
r[0]=r[14];
goto P_0c0a1fb0;
P_0c0a1fb0: /* original 8801, guest PC 0x0c0a1fb0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a1fb2;
P_0c0a1fb2: /* original 8905, guest PC 0x0c0a1fb2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fb4;
P_0c0a1fb4: /* original 60e3, guest PC 0x0c0a1fb4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb4u; return 0; }
r[0]=r[14];
goto P_0c0a1fb6;
P_0c0a1fb6: /* original 8802, guest PC 0x0c0a1fb6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a1fb8;
P_0c0a1fb8: /* original 8902, guest PC 0x0c0a1fb8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fc0; }
goto P_0c0a1fba;
P_0c0a1fba: /* original 60e3, guest PC 0x0c0a1fba */
if(!s->budget--) { s->failed_pc=0x0c0a1fbau; return 0; }
r[0]=r[14];
goto P_0c0a1fbc;
P_0c0a1fbc: /* original 8803, guest PC 0x0c0a1fbc */
if(!s->budget--) { s->failed_pc=0x0c0a1fbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a1fbe;
P_0c0a1fbe: /* original 8b03, guest PC 0x0c0a1fbe */
if(!s->budget--) { s->failed_pc=0x0c0a1fbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1fc8; }
goto P_0c0a1fc0;
P_0c0a1fc0: /* original a003, guest PC 0x0c0a1fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc0u; return 0; }
r[0]=0x00000011u;
goto P_0c0a1fca;
P_0c0a1fc2: /* original e011, guest PC 0x0c0a1fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc2u; return 0; }
r[0]=0x00000011u;
goto P_0c0a1fc4;
P_0c0a1fc4: /* original a001, guest PC 0x0c0a1fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc4u; return 0; }
r[0]=0x00000002u;
goto P_0c0a1fca;
P_0c0a1fc6: /* original e002, guest PC 0x0c0a1fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc6u; return 0; }
r[0]=0x00000002u;
goto P_0c0a1fc8;
P_0c0a1fc8: /* original e004, guest PC 0x0c0a1fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fc8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a1fca;
P_0c0a1fca: /* original 4f26, guest PC 0x0c0a1fca */
if(!s->budget--) { s->failed_pc=0x0c0a1fcau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1fcc;
P_0c0a1fcc: /* original 6df6, guest PC 0x0c0a1fcc */
if(!s->budget--) { s->failed_pc=0x0c0a1fccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a1fce;
P_0c0a1fce: /* original 000b, guest PC 0x0c0a1fce */
if(!s->budget--) { s->failed_pc=0x0c0a1fceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a1fd0: /* original 6ef6, guest PC 0x0c0a1fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a1fd2;
P_0c0a1fd2: /* original 4f22, guest PC 0x0c0a1fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1fd4;
P_0c0a1fd4: /* original d308, guest PC 0x0c0a1fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd4u; return 0; }
r[3]=read(ram,0x0c0a1ff8u,4);
goto P_0c0a1fd6;
P_0c0a1fd6: /* original 430b, guest PC 0x0c0a1fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd6u; return 0; }
target=r[3];
r[16]=0x0c0a1fdau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a1fdau) { target=s->pc; goto dispatch; }
goto P_0c0a1fda;
P_0c0a1fd8: /* original 0009, guest PC 0x0c0a1fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd8u; return 0; }
goto P_0c0a1fda;
P_0c0a1fda: /* original 6403, guest PC 0x0c0a1fda */
if(!s->budget--) { s->failed_pc=0x0c0a1fdau; return 0; }
r[4]=r[0];
goto P_0c0a1fdc;
P_0c0a1fdc: /* original 6241, guest PC 0x0c0a1fdc */
if(!s->budget--) { s->failed_pc=0x0c0a1fdcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c0a1fde;
P_0c0a1fde: /* original 2228, guest PC 0x0c0a1fde */
if(!s->budget--) { s->failed_pc=0x0c0a1fdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a1fe0;
P_0c0a1fe0: /* original 8905, guest PC 0x0c0a1fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fee; }
goto P_0c0a1fe2;
P_0c0a1fe2: /* original 8541, guest PC 0x0c0a1fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0a1fe4;
P_0c0a1fe4: /* original 2008, guest PC 0x0c0a1fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1fe6;
P_0c0a1fe6: /* original 8902, guest PC 0x0c0a1fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fee; }
goto P_0c0a1fe8;
P_0c0a1fe8: /* original 4f26, guest PC 0x0c0a1fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1fea;
P_0c0a1fea: /* original 000b, guest PC 0x0c0a1fea */
if(!s->budget--) { s->failed_pc=0x0c0a1feau; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c0a1fec: /* original e001, guest PC 0x0c0a1fec */
if(!s->budget--) { s->failed_pc=0x0c0a1fecu; return 0; }
r[0]=0x00000001u;
goto P_0c0a1fee;
P_0c0a1fee: /* original e000, guest PC 0x0c0a1fee */
if(!s->budget--) { s->failed_pc=0x0c0a1feeu; return 0; }
r[0]=0x00000000u;
goto P_0c0a1ff0;
P_0c0a1ff0: /* original 4f26, guest PC 0x0c0a1ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1ff2;
P_0c0a1ff2: /* original 000b, guest PC 0x0c0a1ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a1ff4: /* original 0009, guest PC 0x0c0a1ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff4u; return 0; }
return vf3_matrix_family(0x0c0a1ff6u,s,ram);
P_0c0a22c4: /* original 2fe6, guest PC 0x0c0a22c4 */
if(!s->budget--) { s->failed_pc=0x0c0a22c4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22c6;
P_0c0a22c6: /* original 2fd6, guest PC 0x0c0a22c6 */
if(!s->budget--) { s->failed_pc=0x0c0a22c6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22c8;
P_0c0a22c8: /* original 2fc6, guest PC 0x0c0a22c8 */
if(!s->budget--) { s->failed_pc=0x0c0a22c8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22ca;
P_0c0a22ca: /* original 2fb6, guest PC 0x0c0a22ca */
if(!s->budget--) { s->failed_pc=0x0c0a22cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22cc;
P_0c0a22cc: /* original 2fa6, guest PC 0x0c0a22cc */
if(!s->budget--) { s->failed_pc=0x0c0a22ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22ce;
P_0c0a22ce: /* original 2f96, guest PC 0x0c0a22ce */
if(!s->budget--) { s->failed_pc=0x0c0a22ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a22d0;
P_0c0a22d0: /* original 4f22, guest PC 0x0c0a22d0 */
if(!s->budget--) { s->failed_pc=0x0c0a22d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a22d2;
P_0c0a22d2: /* original db3f, guest PC 0x0c0a22d2 */
if(!s->budget--) { s->failed_pc=0x0c0a22d2u; return 0; }
r[11]=read(ram,0x0c0a23d0u,4);
goto P_0c0a22d4;
P_0c0a22d4: /* original 4b0b, guest PC 0x0c0a22d4 */
if(!s->budget--) { s->failed_pc=0x0c0a22d4u; return 0; }
target=r[11];
r[16]=0x0c0a22d8u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a22d8u) { target=s->pc; goto dispatch; }
goto P_0c0a22d8;
P_0c0a22d6: /* original e400, guest PC 0x0c0a22d6 */
if(!s->budget--) { s->failed_pc=0x0c0a22d6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a22d8;
P_0c0a22d8: /* original d33e, guest PC 0x0c0a22d8 */
if(!s->budget--) { s->failed_pc=0x0c0a22d8u; return 0; }
r[3]=read(ram,0x0c0a23d4u,4);
goto P_0c0a22da;
P_0c0a22da: /* original 430b, guest PC 0x0c0a22da */
if(!s->budget--) { s->failed_pc=0x0c0a22dau; return 0; }
target=r[3];
r[16]=0x0c0a22deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a22deu) { target=s->pc; goto dispatch; }
goto P_0c0a22de;
P_0c0a22dc: /* original 0009, guest PC 0x0c0a22dc */
if(!s->budget--) { s->failed_pc=0x0c0a22dcu; return 0; }
goto P_0c0a22de;
P_0c0a22de: /* original d43e, guest PC 0x0c0a22de */
if(!s->budget--) { s->failed_pc=0x0c0a22deu; return 0; }
r[4]=read(ram,0x0c0a23d8u,4);
goto P_0c0a22e0;
P_0c0a22e0: /* original 6a43, guest PC 0x0c0a22e0 */
if(!s->budget--) { s->failed_pc=0x0c0a22e0u; return 0; }
r[10]=r[4];
goto P_0c0a22e2;
P_0c0a22e2: /* original 7a10, guest PC 0x0c0a22e2 */
if(!s->budget--) { s->failed_pc=0x0c0a22e2u; return 0; }
r[10]+=0x00000010u;
goto P_0c0a22e4;
P_0c0a22e4: /* original 6c43, guest PC 0x0c0a22e4 */
if(!s->budget--) { s->failed_pc=0x0c0a22e4u; return 0; }
r[12]=r[4];
goto P_0c0a22e6;
P_0c0a22e6: /* original de3d, guest PC 0x0c0a22e6 */
if(!s->budget--) { s->failed_pc=0x0c0a22e6u; return 0; }
r[14]=read(ram,0x0c0a23dcu,4);
goto P_0c0a22e8;
P_0c0a22e8: /* original 4e0b, guest PC 0x0c0a22e8 */
if(!s->budget--) { s->failed_pc=0x0c0a22e8u; return 0; }
target=r[14];
r[16]=0x0c0a22ecu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a22ecu) { target=s->pc; goto dispatch; }
goto P_0c0a22ec;
P_0c0a22ea: /* original e400, guest PC 0x0c0a22ea */
if(!s->budget--) { s->failed_pc=0x0c0a22eau; return 0; }
r[4]=0x00000000u;
goto P_0c0a22ec;
P_0c0a22ec: /* original de3c, guest PC 0x0c0a22ec */
if(!s->budget--) { s->failed_pc=0x0c0a22ecu; return 0; }
r[14]=read(ram,0x0c0a23e0u,4);
goto P_0c0a22ee;
P_0c0a22ee: /* original 4e0b, guest PC 0x0c0a22ee */
if(!s->budget--) { s->failed_pc=0x0c0a22eeu; return 0; }
target=r[14];
r[16]=0x0c0a22f2u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a22f2u) { target=s->pc; goto dispatch; }
goto P_0c0a22f2;
P_0c0a22f0: /* original e401, guest PC 0x0c0a22f0 */
if(!s->budget--) { s->failed_pc=0x0c0a22f0u; return 0; }
r[4]=0x00000001u;
goto P_0c0a22f2;
P_0c0a22f2: /* original de3c, guest PC 0x0c0a22f2 */
if(!s->budget--) { s->failed_pc=0x0c0a22f2u; return 0; }
r[14]=read(ram,0x0c0a23e4u,4);
goto P_0c0a22f4;
P_0c0a22f4: /* original 4e0b, guest PC 0x0c0a22f4 */
if(!s->budget--) { s->failed_pc=0x0c0a22f4u; return 0; }
target=r[14];
r[16]=0x0c0a22f8u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a22f8u) { target=s->pc; goto dispatch; }
goto P_0c0a22f8;
P_0c0a22f6: /* original e400, guest PC 0x0c0a22f6 */
if(!s->budget--) { s->failed_pc=0x0c0a22f6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a22f8;
P_0c0a22f8: /* original de3b, guest PC 0x0c0a22f8 */
if(!s->budget--) { s->failed_pc=0x0c0a22f8u; return 0; }
r[14]=read(ram,0x0c0a23e8u,4);
goto P_0c0a22fa;
P_0c0a22fa: /* original e500, guest PC 0x0c0a22fa */
if(!s->budget--) { s->failed_pc=0x0c0a22fau; return 0; }
r[5]=0x00000000u;
goto P_0c0a22fc;
P_0c0a22fc: /* original 4e0b, guest PC 0x0c0a22fc */
if(!s->budget--) { s->failed_pc=0x0c0a22fcu; return 0; }
target=r[14];
r[16]=0x0c0a2300u;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2300u) { target=s->pc; goto dispatch; }
goto P_0c0a2300;
P_0c0a22fe: /* original e403, guest PC 0x0c0a22fe */
if(!s->budget--) { s->failed_pc=0x0c0a22feu; return 0; }
r[4]=0x00000003u;
goto P_0c0a2300;
P_0c0a2300: /* original de3a, guest PC 0x0c0a2300 */
if(!s->budget--) { s->failed_pc=0x0c0a2300u; return 0; }
r[14]=read(ram,0x0c0a23ecu,4);
goto P_0c0a2302;
P_0c0a2302: /* original e560, guest PC 0x0c0a2302 */
if(!s->budget--) { s->failed_pc=0x0c0a2302u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2304;
P_0c0a2304: /* original 4e0b, guest PC 0x0c0a2304 */
if(!s->budget--) { s->failed_pc=0x0c0a2304u; return 0; }
target=r[14];
r[16]=0x0c0a2308u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2308u) { target=s->pc; goto dispatch; }
goto P_0c0a2308;
P_0c0a2306: /* original e40c, guest PC 0x0c0a2306 */
if(!s->budget--) { s->failed_pc=0x0c0a2306u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2308;
P_0c0a2308: /* original dd3a, guest PC 0x0c0a2308 */
if(!s->budget--) { s->failed_pc=0x0c0a2308u; return 0; }
r[13]=read(ram,0x0c0a23f4u,4);
goto P_0c0a230a;
P_0c0a230a: /* original d939, guest PC 0x0c0a230a */
if(!s->budget--) { s->failed_pc=0x0c0a230au; return 0; }
r[9]=read(ram,0x0c0a23f0u,4);
goto P_0c0a230c;
P_0c0a230c: /* original 4d0b, guest PC 0x0c0a230c */
if(!s->budget--) { s->failed_pc=0x0c0a230cu; return 0; }
target=r[13];
r[16]=0x0c0a2310u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2310u) { target=s->pc; goto dispatch; }
goto P_0c0a2310;
P_0c0a230e: /* original 2f96, guest PC 0x0c0a230e */
if(!s->budget--) { s->failed_pc=0x0c0a230eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2310;
P_0c0a2310: /* original 9555, guest PC 0x0c0a2310 */
if(!s->budget--) { s->failed_pc=0x0c0a2310u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23beu,2);
goto P_0c0a2312;
P_0c0a2312: /* original 4e0b, guest PC 0x0c0a2312 */
if(!s->budget--) { s->failed_pc=0x0c0a2312u; return 0; }
target=r[14];
r[16]=0x0c0a2316u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2316u) { target=s->pc; goto dispatch; }
goto P_0c0a2316;
P_0c0a2314: /* original e40c, guest PC 0x0c0a2314 */
if(!s->budget--) { s->failed_pc=0x0c0a2314u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2316;
P_0c0a2316: /* original d938, guest PC 0x0c0a2316 */
if(!s->budget--) { s->failed_pc=0x0c0a2316u; return 0; }
r[9]=read(ram,0x0c0a23f8u,4);
goto P_0c0a2318;
P_0c0a2318: /* original 4d0b, guest PC 0x0c0a2318 */
if(!s->budget--) { s->failed_pc=0x0c0a2318u; return 0; }
target=r[13];
r[16]=0x0c0a231cu;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a231cu) { target=s->pc; goto dispatch; }
goto P_0c0a231c;
P_0c0a231a: /* original 2f96, guest PC 0x0c0a231a */
if(!s->budget--) { s->failed_pc=0x0c0a231au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a231c;
P_0c0a231c: /* original 9550, guest PC 0x0c0a231c */
if(!s->budget--) { s->failed_pc=0x0c0a231cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c0u,2);
goto P_0c0a231e;
P_0c0a231e: /* original 4e0b, guest PC 0x0c0a231e */
if(!s->budget--) { s->failed_pc=0x0c0a231eu; return 0; }
target=r[14];
r[16]=0x0c0a2322u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2322u) { target=s->pc; goto dispatch; }
goto P_0c0a2322;
P_0c0a2320: /* original e40c, guest PC 0x0c0a2320 */
if(!s->budget--) { s->failed_pc=0x0c0a2320u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2322;
P_0c0a2322: /* original d936, guest PC 0x0c0a2322 */
if(!s->budget--) { s->failed_pc=0x0c0a2322u; return 0; }
r[9]=read(ram,0x0c0a23fcu,4);
goto P_0c0a2324;
P_0c0a2324: /* original 4d0b, guest PC 0x0c0a2324 */
if(!s->budget--) { s->failed_pc=0x0c0a2324u; return 0; }
target=r[13];
r[16]=0x0c0a2328u;
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2328u) { target=s->pc; goto dispatch; }
goto P_0c0a2328;
P_0c0a2326: /* original 2f96, guest PC 0x0c0a2326 */
if(!s->budget--) { s->failed_pc=0x0c0a2326u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2328;
P_0c0a2328: /* original 994b, guest PC 0x0c0a2328 */
if(!s->budget--) { s->failed_pc=0x0c0a2328u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c2u,2);
goto P_0c0a232a;
P_0c0a232a: /* original 6593, guest PC 0x0c0a232a */
if(!s->budget--) { s->failed_pc=0x0c0a232au; return 0; }
r[5]=r[9];
goto P_0c0a232c;
P_0c0a232c: /* original 4e0b, guest PC 0x0c0a232c */
if(!s->budget--) { s->failed_pc=0x0c0a232cu; return 0; }
target=r[14];
r[16]=0x0c0a2330u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2330u) { target=s->pc; goto dispatch; }
goto P_0c0a2330;
P_0c0a232e: /* original e40c, guest PC 0x0c0a232e */
if(!s->budget--) { s->failed_pc=0x0c0a232eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2330;
P_0c0a2330: /* original de33, guest PC 0x0c0a2330 */
if(!s->budget--) { s->failed_pc=0x0c0a2330u; return 0; }
r[14]=read(ram,0x0c0a2400u,4);
goto P_0c0a2332;
P_0c0a2332: /* original 4d0b, guest PC 0x0c0a2332 */
if(!s->budget--) { s->failed_pc=0x0c0a2332u; return 0; }
target=r[13];
r[16]=0x0c0a2336u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2336u) { target=s->pc; goto dispatch; }
goto P_0c0a2336;
P_0c0a2334: /* original 2fe6, guest PC 0x0c0a2334 */
if(!s->budget--) { s->failed_pc=0x0c0a2334u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2336;
P_0c0a2336: /* original de33, guest PC 0x0c0a2336 */
if(!s->budget--) { s->failed_pc=0x0c0a2336u; return 0; }
r[14]=read(ram,0x0c0a2404u,4);
goto P_0c0a2338;
P_0c0a2338: /* original 7f10, guest PC 0x0c0a2338 */
if(!s->budget--) { s->failed_pc=0x0c0a2338u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a233a;
P_0c0a233a: /* original 4e0b, guest PC 0x0c0a233a */
if(!s->budget--) { s->failed_pc=0x0c0a233au; return 0; }
target=r[14];
r[16]=0x0c0a233eu;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a233eu) { target=s->pc; goto dispatch; }
goto P_0c0a233e;
P_0c0a233c: /* original e403, guest PC 0x0c0a233c */
if(!s->budget--) { s->failed_pc=0x0c0a233cu; return 0; }
r[4]=0x00000003u;
goto P_0c0a233e;
P_0c0a233e: /* original de32, guest PC 0x0c0a233e */
if(!s->budget--) { s->failed_pc=0x0c0a233eu; return 0; }
r[14]=read(ram,0x0c0a2408u,4);
goto P_0c0a2340;
P_0c0a2340: /* original 4e0b, guest PC 0x0c0a2340 */
if(!s->budget--) { s->failed_pc=0x0c0a2340u; return 0; }
target=r[14];
r[16]=0x0c0a2344u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2344u) { target=s->pc; goto dispatch; }
goto P_0c0a2344;
P_0c0a2342: /* original 0009, guest PC 0x0c0a2342 */
if(!s->budget--) { s->failed_pc=0x0c0a2342u; return 0; }
goto P_0c0a2344;
P_0c0a2344: /* original 85c3, guest PC 0x0c0a2344 */
if(!s->budget--) { s->failed_pc=0x0c0a2344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c0a2346;
P_0c0a2346: /* original 943d, guest PC 0x0c0a2346 */
if(!s->budget--) { s->failed_pc=0x0c0a2346u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c4u,2);
goto P_0c0a2348;
P_0c0a2348: /* original 630d, guest PC 0x0c0a2348 */
if(!s->budget--) { s->failed_pc=0x0c0a2348u; return 0; }
r[3]=r[0]&65535u;
goto P_0c0a234a;
P_0c0a234a: /* original 85a3, guest PC 0x0c0a234a */
if(!s->budget--) { s->failed_pc=0x0c0a234au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+6,2);
goto P_0c0a234c;
P_0c0a234c: /* original 600d, guest PC 0x0c0a234c */
if(!s->budget--) { s->failed_pc=0x0c0a234cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a234e;
P_0c0a234e: /* original 230b, guest PC 0x0c0a234e */
if(!s->budget--) { s->failed_pc=0x0c0a234eu; return 0; }
r[3]|=r[0];
goto P_0c0a2350;
P_0c0a2350: /* original 2348, guest PC 0x0c0a2350 */
if(!s->budget--) { s->failed_pc=0x0c0a2350u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a2352;
P_0c0a2352: /* original 8901, guest PC 0x0c0a2352 */
if(!s->budget--) { s->failed_pc=0x0c0a2352u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2358; }
goto P_0c0a2354;
P_0c0a2354: /* original a00f, guest PC 0x0c0a2354 */
if(!s->budget--) { s->failed_pc=0x0c0a2354u; return 0; }
r[0]=0x00000001u;
goto P_0c0a2376;
P_0c0a2356: /* original e001, guest PC 0x0c0a2356 */
if(!s->budget--) { s->failed_pc=0x0c0a2356u; return 0; }
r[0]=0x00000001u;
goto P_0c0a2358;
P_0c0a2358: /* original 85c3, guest PC 0x0c0a2358 */
if(!s->budget--) { s->failed_pc=0x0c0a2358u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+6,2);
goto P_0c0a235a;
P_0c0a235a: /* original 9434, guest PC 0x0c0a235a */
if(!s->budget--) { s->failed_pc=0x0c0a235au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c6u,2);
goto P_0c0a235c;
P_0c0a235c: /* original 630d, guest PC 0x0c0a235c */
if(!s->budget--) { s->failed_pc=0x0c0a235cu; return 0; }
r[3]=r[0]&65535u;
goto P_0c0a235e;
P_0c0a235e: /* original 85a3, guest PC 0x0c0a235e */
if(!s->budget--) { s->failed_pc=0x0c0a235eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+6,2);
goto P_0c0a2360;
P_0c0a2360: /* original 600d, guest PC 0x0c0a2360 */
if(!s->budget--) { s->failed_pc=0x0c0a2360u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2362;
P_0c0a2362: /* original 230b, guest PC 0x0c0a2362 */
if(!s->budget--) { s->failed_pc=0x0c0a2362u; return 0; }
r[3]|=r[0];
goto P_0c0a2364;
P_0c0a2364: /* original 2348, guest PC 0x0c0a2364 */
if(!s->budget--) { s->failed_pc=0x0c0a2364u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a2366;
P_0c0a2366: /* original 8b05, guest PC 0x0c0a2366 */
if(!s->budget--) { s->failed_pc=0x0c0a2366u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2374; }
goto P_0c0a2368;
P_0c0a2368: /* original 4b0b, guest PC 0x0c0a2368 */
if(!s->budget--) { s->failed_pc=0x0c0a2368u; return 0; }
target=r[11];
r[16]=0x0c0a236cu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a236cu) { target=s->pc; goto dispatch; }
goto P_0c0a236c;
P_0c0a236a: /* original e400, guest PC 0x0c0a236a */
if(!s->budget--) { s->failed_pc=0x0c0a236au; return 0; }
r[4]=0x00000000u;
goto P_0c0a236c;
P_0c0a236c: /* original bdf0, guest PC 0x0c0a236c */
if(!s->budget--) { s->failed_pc=0x0c0a236cu; return 0; }
target=0x0c0a1f50u; r[16]=0x0c0a2370u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2370u) { target=s->pc; goto dispatch; }
goto P_0c0a2370;
P_0c0a236e: /* original e401, guest PC 0x0c0a236e */
if(!s->budget--) { s->failed_pc=0x0c0a236eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a2370;
P_0c0a2370: /* original 8810, guest PC 0x0c0a2370 */
if(!s->budget--) { s->failed_pc=0x0c0a2370u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0a2372;
P_0c0a2372: /* original 89b8, guest PC 0x0c0a2372 */
if(!s->budget--) { s->failed_pc=0x0c0a2372u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a22e6; }
goto P_0c0a2374;
P_0c0a2374: /* original e000, guest PC 0x0c0a2374 */
if(!s->budget--) { s->failed_pc=0x0c0a2374u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2376;
P_0c0a2376: /* original 4f26, guest PC 0x0c0a2376 */
if(!s->budget--) { s->failed_pc=0x0c0a2376u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2378;
P_0c0a2378: /* original 69f6, guest PC 0x0c0a2378 */
if(!s->budget--) { s->failed_pc=0x0c0a2378u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a237a;
P_0c0a237a: /* original 6af6, guest PC 0x0c0a237a */
if(!s->budget--) { s->failed_pc=0x0c0a237au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a237c;
P_0c0a237c: /* original 6bf6, guest PC 0x0c0a237c */
if(!s->budget--) { s->failed_pc=0x0c0a237cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a237e;
P_0c0a237e: /* original 6cf6, guest PC 0x0c0a237e */
if(!s->budget--) { s->failed_pc=0x0c0a237eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2380;
P_0c0a2380: /* original 6df6, guest PC 0x0c0a2380 */
if(!s->budget--) { s->failed_pc=0x0c0a2380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2382;
P_0c0a2382: /* original 000b, guest PC 0x0c0a2382 */
if(!s->budget--) { s->failed_pc=0x0c0a2382u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2384: /* original 6ef6, guest PC 0x0c0a2384 */
if(!s->budget--) { s->failed_pc=0x0c0a2384u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2386;
P_0c0a2386: /* original 2fe6, guest PC 0x0c0a2386 */
if(!s->budget--) { s->failed_pc=0x0c0a2386u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2388;
P_0c0a2388: /* original 2fd6, guest PC 0x0c0a2388 */
if(!s->budget--) { s->failed_pc=0x0c0a2388u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238a;
P_0c0a238a: /* original 2fc6, guest PC 0x0c0a238a */
if(!s->budget--) { s->failed_pc=0x0c0a238au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238c;
P_0c0a238c: /* original 2fb6, guest PC 0x0c0a238c */
if(!s->budget--) { s->failed_pc=0x0c0a238cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a238e;
P_0c0a238e: /* original 2fa6, guest PC 0x0c0a238e */
if(!s->budget--) { s->failed_pc=0x0c0a238eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2390;
P_0c0a2390: /* original 2f96, guest PC 0x0c0a2390 */
if(!s->budget--) { s->failed_pc=0x0c0a2390u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2392;
P_0c0a2392: /* original 2f86, guest PC 0x0c0a2392 */
if(!s->budget--) { s->failed_pc=0x0c0a2392u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2394;
P_0c0a2394: /* original 4f22, guest PC 0x0c0a2394 */
if(!s->budget--) { s->failed_pc=0x0c0a2394u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2396;
P_0c0a2396: /* original 7ff4, guest PC 0x0c0a2396 */
if(!s->budget--) { s->failed_pc=0x0c0a2396u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2398;
P_0c0a2398: /* original 2f42, guest PC 0x0c0a2398 */
if(!s->budget--) { s->failed_pc=0x0c0a2398u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a239a;
P_0c0a239a: /* original 9a15, guest PC 0x0c0a239a */
if(!s->budget--) { s->failed_pc=0x0c0a239au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23c8u,2);
goto P_0c0a239c;
P_0c0a239c: /* original d80c, guest PC 0x0c0a239c */
if(!s->budget--) { s->failed_pc=0x0c0a239cu; return 0; }
r[8]=read(ram,0x0c0a23d0u,4);
goto P_0c0a239e;
P_0c0a239e: /* original 480b, guest PC 0x0c0a239e */
if(!s->budget--) { s->failed_pc=0x0c0a239eu; return 0; }
target=r[8];
r[16]=0x0c0a23a2u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a23a2u) { target=s->pc; goto dispatch; }
goto P_0c0a23a2;
P_0c0a23a0: /* original e400, guest PC 0x0c0a23a0 */
if(!s->budget--) { s->failed_pc=0x0c0a23a0u; return 0; }
r[4]=0x00000000u;
goto P_0c0a23a2;
P_0c0a23a2: /* original d30c, guest PC 0x0c0a23a2 */
if(!s->budget--) { s->failed_pc=0x0c0a23a2u; return 0; }
r[3]=read(ram,0x0c0a23d4u,4);
goto P_0c0a23a4;
P_0c0a23a4: /* original 430b, guest PC 0x0c0a23a4 */
if(!s->budget--) { s->failed_pc=0x0c0a23a4u; return 0; }
target=r[3];
r[16]=0x0c0a23a8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a23a8u) { target=s->pc; goto dispatch; }
goto P_0c0a23a8;
P_0c0a23a6: /* original 0009, guest PC 0x0c0a23a6 */
if(!s->budget--) { s->failed_pc=0x0c0a23a6u; return 0; }
goto P_0c0a23a8;
P_0c0a23a8: /* original d40b, guest PC 0x0c0a23a8 */
if(!s->budget--) { s->failed_pc=0x0c0a23a8u; return 0; }
r[4]=read(ram,0x0c0a23d8u,4);
goto P_0c0a23aa;
P_0c0a23aa: /* original 6243, guest PC 0x0c0a23aa */
if(!s->budget--) { s->failed_pc=0x0c0a23aau; return 0; }
r[2]=r[4];
goto P_0c0a23ac;
P_0c0a23ac: /* original 7410, guest PC 0x0c0a23ac */
if(!s->budget--) { s->failed_pc=0x0c0a23acu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a23ae;
P_0c0a23ae: /* original 1f21, guest PC 0x0c0a23ae */
if(!s->budget--) { s->failed_pc=0x0c0a23aeu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a23b0;
P_0c0a23b0: /* original 9c0c, guest PC 0x0c0a23b0 */
if(!s->budget--) { s->failed_pc=0x0c0a23b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23ccu,2);
goto P_0c0a23b2;
P_0c0a23b2: /* original dd0e, guest PC 0x0c0a23b2 */
if(!s->budget--) { s->failed_pc=0x0c0a23b2u; return 0; }
r[13]=read(ram,0x0c0a23ecu,4);
goto P_0c0a23b4;
P_0c0a23b4: /* original de0f, guest PC 0x0c0a23b4 */
if(!s->budget--) { s->failed_pc=0x0c0a23b4u; return 0; }
r[14]=read(ram,0x0c0a23f4u,4);
goto P_0c0a23b6;
P_0c0a23b6: /* original 9b02, guest PC 0x0c0a23b6 */
if(!s->budget--) { s->failed_pc=0x0c0a23b6u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23beu,2);
goto P_0c0a23b8;
P_0c0a23b8: /* original 9907, guest PC 0x0c0a23b8 */
if(!s->budget--) { s->failed_pc=0x0c0a23b8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a23cau,2);
goto P_0c0a23ba;
P_0c0a23ba: /* original a067, guest PC 0x0c0a23ba */
if(!s->budget--) { s->failed_pc=0x0c0a23bau; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0a248c;
P_0c0a23bc: /* original 1f42, guest PC 0x0c0a23bc */
if(!s->budget--) { s->failed_pc=0x0c0a23bcu; return 0; }
write(ram,r[15]+8,r[4],4);
return vf3_matrix_family(0x0c0a23beu,s,ram);
P_0c0a240c: /* original d237, guest PC 0x0c0a240c */
if(!s->budget--) { s->failed_pc=0x0c0a240cu; return 0; }
r[2]=read(ram,0x0c0a24ecu,4);
goto P_0c0a240e;
P_0c0a240e: /* original 420b, guest PC 0x0c0a240e */
if(!s->budget--) { s->failed_pc=0x0c0a240eu; return 0; }
target=r[2];
r[16]=0x0c0a2412u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2412u) { target=s->pc; goto dispatch; }
goto P_0c0a2412;
P_0c0a2410: /* original e400, guest PC 0x0c0a2410 */
if(!s->budget--) { s->failed_pc=0x0c0a2410u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2412;
P_0c0a2412: /* original d337, guest PC 0x0c0a2412 */
if(!s->budget--) { s->failed_pc=0x0c0a2412u; return 0; }
r[3]=read(ram,0x0c0a24f0u,4);
goto P_0c0a2414;
P_0c0a2414: /* original 430b, guest PC 0x0c0a2414 */
if(!s->budget--) { s->failed_pc=0x0c0a2414u; return 0; }
target=r[3];
r[16]=0x0c0a2418u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2418u) { target=s->pc; goto dispatch; }
goto P_0c0a2418;
P_0c0a2416: /* original e401, guest PC 0x0c0a2416 */
if(!s->budget--) { s->failed_pc=0x0c0a2416u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2418;
P_0c0a2418: /* original d236, guest PC 0x0c0a2418 */
if(!s->budget--) { s->failed_pc=0x0c0a2418u; return 0; }
r[2]=read(ram,0x0c0a24f4u,4);
goto P_0c0a241a;
P_0c0a241a: /* original 420b, guest PC 0x0c0a241a */
if(!s->budget--) { s->failed_pc=0x0c0a241au; return 0; }
target=r[2];
r[16]=0x0c0a241eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a241eu) { target=s->pc; goto dispatch; }
goto P_0c0a241e;
P_0c0a241c: /* original e400, guest PC 0x0c0a241c */
if(!s->budget--) { s->failed_pc=0x0c0a241cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a241e;
P_0c0a241e: /* original d336, guest PC 0x0c0a241e */
if(!s->budget--) { s->failed_pc=0x0c0a241eu; return 0; }
r[3]=read(ram,0x0c0a24f8u,4);
goto P_0c0a2420;
P_0c0a2420: /* original e500, guest PC 0x0c0a2420 */
if(!s->budget--) { s->failed_pc=0x0c0a2420u; return 0; }
r[5]=0x00000000u;
goto P_0c0a2422;
P_0c0a2422: /* original 430b, guest PC 0x0c0a2422 */
if(!s->budget--) { s->failed_pc=0x0c0a2422u; return 0; }
target=r[3];
r[16]=0x0c0a2426u;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2426u) { target=s->pc; goto dispatch; }
goto P_0c0a2426;
P_0c0a2424: /* original e403, guest PC 0x0c0a2424 */
if(!s->budget--) { s->failed_pc=0x0c0a2424u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2426;
P_0c0a2426: /* original e560, guest PC 0x0c0a2426 */
if(!s->budget--) { s->failed_pc=0x0c0a2426u; return 0; }
r[5]=0x00000060u;
goto P_0c0a2428;
P_0c0a2428: /* original 4d0b, guest PC 0x0c0a2428 */
if(!s->budget--) { s->failed_pc=0x0c0a2428u; return 0; }
target=r[13];
r[16]=0x0c0a242cu;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a242cu) { target=s->pc; goto dispatch; }
goto P_0c0a242c;
P_0c0a242a: /* original e40c, guest PC 0x0c0a242a */
if(!s->budget--) { s->failed_pc=0x0c0a242au; return 0; }
r[4]=0x0000000cu;
goto P_0c0a242c;
P_0c0a242c: /* original d233, guest PC 0x0c0a242c */
if(!s->budget--) { s->failed_pc=0x0c0a242cu; return 0; }
r[2]=read(ram,0x0c0a24fcu,4);
goto P_0c0a242e;
P_0c0a242e: /* original 4e0b, guest PC 0x0c0a242e */
if(!s->budget--) { s->failed_pc=0x0c0a242eu; return 0; }
target=r[14];
r[16]=0x0c0a2432u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2432u) { target=s->pc; goto dispatch; }
goto P_0c0a2432;
P_0c0a2430: /* original 2f26, guest PC 0x0c0a2430 */
if(!s->budget--) { s->failed_pc=0x0c0a2430u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2432;
P_0c0a2432: /* original 7f04, guest PC 0x0c0a2432 */
if(!s->budget--) { s->failed_pc=0x0c0a2432u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2434;
P_0c0a2434: /* original 60f2, guest PC 0x0c0a2434 */
if(!s->budget--) { s->failed_pc=0x0c0a2434u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a2436;
P_0c0a2436: /* original 880b, guest PC 0x0c0a2436 */
if(!s->budget--) { s->failed_pc=0x0c0a2436u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a2438;
P_0c0a2438: /* original 8b05, guest PC 0x0c0a2438 */
if(!s->budget--) { s->failed_pc=0x0c0a2438u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2446; }
goto P_0c0a243a;
P_0c0a243a: /* original 65b3, guest PC 0x0c0a243a */
if(!s->budget--) { s->failed_pc=0x0c0a243au; return 0; }
r[5]=r[11];
goto P_0c0a243c;
P_0c0a243c: /* original 4d0b, guest PC 0x0c0a243c */
if(!s->budget--) { s->failed_pc=0x0c0a243cu; return 0; }
target=r[13];
r[16]=0x0c0a2440u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2440u) { target=s->pc; goto dispatch; }
goto P_0c0a2440;
P_0c0a243e: /* original e40c, guest PC 0x0c0a243e */
if(!s->budget--) { s->failed_pc=0x0c0a243eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2440;
P_0c0a2440: /* original d22f, guest PC 0x0c0a2440 */
if(!s->budget--) { s->failed_pc=0x0c0a2440u; return 0; }
r[2]=read(ram,0x0c0a2500u,4);
goto P_0c0a2442;
P_0c0a2442: /* original a004, guest PC 0x0c0a2442 */
if(!s->budget--) { s->failed_pc=0x0c0a2442u; return 0; }
goto P_0c0a244e;
P_0c0a2444: /* original 0009, guest PC 0x0c0a2444 */
if(!s->budget--) { s->failed_pc=0x0c0a2444u; return 0; }
goto P_0c0a2446;
P_0c0a2446: /* original 65b3, guest PC 0x0c0a2446 */
if(!s->budget--) { s->failed_pc=0x0c0a2446u; return 0; }
r[5]=r[11];
goto P_0c0a2448;
P_0c0a2448: /* original 4d0b, guest PC 0x0c0a2448 */
if(!s->budget--) { s->failed_pc=0x0c0a2448u; return 0; }
target=r[13];
r[16]=0x0c0a244cu;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a244cu) { target=s->pc; goto dispatch; }
goto P_0c0a244c;
P_0c0a244a: /* original e40c, guest PC 0x0c0a244a */
if(!s->budget--) { s->failed_pc=0x0c0a244au; return 0; }
r[4]=0x0000000cu;
goto P_0c0a244c;
P_0c0a244c: /* original d22d, guest PC 0x0c0a244c */
if(!s->budget--) { s->failed_pc=0x0c0a244cu; return 0; }
r[2]=read(ram,0x0c0a2504u,4);
goto P_0c0a244e;
P_0c0a244e: /* original 4e0b, guest PC 0x0c0a244e */
if(!s->budget--) { s->failed_pc=0x0c0a244eu; return 0; }
target=r[14];
r[16]=0x0c0a2452u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2452u) { target=s->pc; goto dispatch; }
goto P_0c0a2452;
P_0c0a2450: /* original 2f26, guest PC 0x0c0a2450 */
if(!s->budget--) { s->failed_pc=0x0c0a2450u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2452;
P_0c0a2452: /* original 9349, guest PC 0x0c0a2452 */
if(!s->budget--) { s->failed_pc=0x0c0a2452u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a24e8u,2);
goto P_0c0a2454;
P_0c0a2454: /* original 3a33, guest PC 0x0c0a2454 */
if(!s->budget--) { s->failed_pc=0x0c0a2454u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a2456;
P_0c0a2456: /* original 8d07, guest PC 0x0c0a2456 */
if(!s->budget--) { s->failed_pc=0x0c0a2456u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c0a2468; }
goto P_0c0a245a;
P_0c0a2458: /* original 7f04, guest PC 0x0c0a2458 */
if(!s->budget--) { s->failed_pc=0x0c0a2458u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a245a;
P_0c0a245a: /* original 6593, guest PC 0x0c0a245a */
if(!s->budget--) { s->failed_pc=0x0c0a245au; return 0; }
r[5]=r[9];
goto P_0c0a245c;
P_0c0a245c: /* original 4d0b, guest PC 0x0c0a245c */
if(!s->budget--) { s->failed_pc=0x0c0a245cu; return 0; }
target=r[13];
r[16]=0x0c0a2460u;
r[4]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2460u) { target=s->pc; goto dispatch; }
goto P_0c0a2460;
P_0c0a245e: /* original e40c, guest PC 0x0c0a245e */
if(!s->budget--) { s->failed_pc=0x0c0a245eu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a2460;
P_0c0a2460: /* original d329, guest PC 0x0c0a2460 */
if(!s->budget--) { s->failed_pc=0x0c0a2460u; return 0; }
r[3]=read(ram,0x0c0a2508u,4);
goto P_0c0a2462;
P_0c0a2462: /* original 4e0b, guest PC 0x0c0a2462 */
if(!s->budget--) { s->failed_pc=0x0c0a2462u; return 0; }
target=r[14];
r[16]=0x0c0a2466u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2466u) { target=s->pc; goto dispatch; }
goto P_0c0a2466;
P_0c0a2464: /* original 2f36, guest PC 0x0c0a2464 */
if(!s->budget--) { s->failed_pc=0x0c0a2464u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2466;
P_0c0a2466: /* original 7f04, guest PC 0x0c0a2466 */
if(!s->budget--) { s->failed_pc=0x0c0a2466u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a2468;
P_0c0a2468: /* original 52f1, guest PC 0x0c0a2468 */
if(!s->budget--) { s->failed_pc=0x0c0a2468u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0a246a;
P_0c0a246a: /* original 8523, guest PC 0x0c0a246a */
if(!s->budget--) { s->failed_pc=0x0c0a246au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+6,2);
goto P_0c0a246c;
P_0c0a246c: /* original 600d, guest PC 0x0c0a246c */
if(!s->budget--) { s->failed_pc=0x0c0a246cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a246e;
P_0c0a246e: /* original 20c8, guest PC 0x0c0a246e */
if(!s->budget--) { s->failed_pc=0x0c0a246eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0a2470;
P_0c0a2470: /* original 8b0f, guest PC 0x0c0a2470 */
if(!s->budget--) { s->failed_pc=0x0c0a2470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2492; }
goto P_0c0a2472;
P_0c0a2472: /* original 53f2, guest PC 0x0c0a2472 */
if(!s->budget--) { s->failed_pc=0x0c0a2472u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a2474;
P_0c0a2474: /* original 8533, guest PC 0x0c0a2474 */
if(!s->budget--) { s->failed_pc=0x0c0a2474u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+6,2);
goto P_0c0a2476;
P_0c0a2476: /* original 600d, guest PC 0x0c0a2476 */
if(!s->budget--) { s->failed_pc=0x0c0a2476u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2478;
P_0c0a2478: /* original 20c8, guest PC 0x0c0a2478 */
if(!s->budget--) { s->failed_pc=0x0c0a2478u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0a247a;
P_0c0a247a: /* original 8b0a, guest PC 0x0c0a247a */
if(!s->budget--) { s->failed_pc=0x0c0a247au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2492; }
goto P_0c0a247c;
P_0c0a247c: /* original d323, guest PC 0x0c0a247c */
if(!s->budget--) { s->failed_pc=0x0c0a247cu; return 0; }
r[3]=read(ram,0x0c0a250cu,4);
goto P_0c0a247e;
P_0c0a247e: /* original 430b, guest PC 0x0c0a247e */
if(!s->budget--) { s->failed_pc=0x0c0a247eu; return 0; }
target=r[3];
r[16]=0x0c0a2482u;
r[4]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2482u) { target=s->pc; goto dispatch; }
goto P_0c0a2482;
P_0c0a2480: /* original e403, guest PC 0x0c0a2480 */
if(!s->budget--) { s->failed_pc=0x0c0a2480u; return 0; }
r[4]=0x00000003u;
goto P_0c0a2482;
P_0c0a2482: /* original d223, guest PC 0x0c0a2482 */
if(!s->budget--) { s->failed_pc=0x0c0a2482u; return 0; }
r[2]=read(ram,0x0c0a2510u,4);
goto P_0c0a2484;
P_0c0a2484: /* original 420b, guest PC 0x0c0a2484 */
if(!s->budget--) { s->failed_pc=0x0c0a2484u; return 0; }
target=r[2];
r[16]=0x0c0a2488u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2488u) { target=s->pc; goto dispatch; }
goto P_0c0a2488;
P_0c0a2486: /* original 0009, guest PC 0x0c0a2486 */
if(!s->budget--) { s->failed_pc=0x0c0a2486u; return 0; }
goto P_0c0a2488;
P_0c0a2488: /* original 480b, guest PC 0x0c0a2488 */
if(!s->budget--) { s->failed_pc=0x0c0a2488u; return 0; }
target=r[8];
r[16]=0x0c0a248cu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a248cu) { target=s->pc; goto dispatch; }
goto P_0c0a248c;
P_0c0a248a: /* original e400, guest PC 0x0c0a248a */
if(!s->budget--) { s->failed_pc=0x0c0a248au; return 0; }
r[4]=0x00000000u;
goto P_0c0a248c;
P_0c0a248c: /* original 2aa8, guest PC 0x0c0a248c */
if(!s->budget--) { s->failed_pc=0x0c0a248cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0a248e;
P_0c0a248e: /* original 8fbd, guest PC 0x0c0a248e */
if(!s->budget--) { s->failed_pc=0x0c0a248eu; return 0; }
cond=r[17]&1u;
r[10]+=0xffffffffu;
if(!cond) { goto P_0c0a240c; }
goto P_0c0a2492;
P_0c0a2490: /* original 7aff, guest PC 0x0c0a2490 */
if(!s->budget--) { s->failed_pc=0x0c0a2490u; return 0; }
r[10]+=0xffffffffu;
goto P_0c0a2492;
P_0c0a2492: /* original 7f0c, guest PC 0x0c0a2492 */
if(!s->budget--) { s->failed_pc=0x0c0a2492u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2494;
P_0c0a2494: /* original 4f26, guest PC 0x0c0a2494 */
if(!s->budget--) { s->failed_pc=0x0c0a2494u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2496;
P_0c0a2496: /* original 68f6, guest PC 0x0c0a2496 */
if(!s->budget--) { s->failed_pc=0x0c0a2496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2498;
P_0c0a2498: /* original 69f6, guest PC 0x0c0a2498 */
if(!s->budget--) { s->failed_pc=0x0c0a2498u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a249a;
P_0c0a249a: /* original 6af6, guest PC 0x0c0a249a */
if(!s->budget--) { s->failed_pc=0x0c0a249au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a249c;
P_0c0a249c: /* original 6bf6, guest PC 0x0c0a249c */
if(!s->budget--) { s->failed_pc=0x0c0a249cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a249e;
P_0c0a249e: /* original 6cf6, guest PC 0x0c0a249e */
if(!s->budget--) { s->failed_pc=0x0c0a249eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a24a0;
P_0c0a24a0: /* original 6df6, guest PC 0x0c0a24a0 */
if(!s->budget--) { s->failed_pc=0x0c0a24a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a24a2;
P_0c0a24a2: /* original 000b, guest PC 0x0c0a24a2 */
if(!s->budget--) { s->failed_pc=0x0c0a24a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a24a4: /* original 6ef6, guest PC 0x0c0a24a4 */
if(!s->budget--) { s->failed_pc=0x0c0a24a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a24a6u,s,ram);
P_0c0a6494: /* original 4f22, guest PC 0x0c0a6494 */
if(!s->budget--) { s->failed_pc=0x0c0a6494u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a6496;
P_0c0a6496: /* original 7fb8, guest PC 0x0c0a6496 */
if(!s->budget--) { s->failed_pc=0x0c0a6496u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c0a6498;
P_0c0a6498: /* original 2f42, guest PC 0x0c0a6498 */
if(!s->budget--) { s->failed_pc=0x0c0a6498u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a649a;
P_0c0a649a: /* original 1f52, guest PC 0x0c0a649a */
if(!s->budget--) { s->failed_pc=0x0c0a649au; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a649c;
P_0c0a649c: /* original 1f61, guest PC 0x0c0a649c */
if(!s->budget--) { s->failed_pc=0x0c0a649cu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a649e;
P_0c0a649e: /* original d35d, guest PC 0x0c0a649e */
if(!s->budget--) { s->failed_pc=0x0c0a649eu; return 0; }
r[3]=read(ram,0x0c0a6614u,4);
goto P_0c0a64a0;
P_0c0a64a0: /* original 430b, guest PC 0x0c0a64a0 */
if(!s->budget--) { s->failed_pc=0x0c0a64a0u; return 0; }
target=r[3];
r[16]=0x0c0a64a4u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a64a4u) { target=s->pc; goto dispatch; }
goto P_0c0a64a4;
P_0c0a64a2: /* original e400, guest PC 0x0c0a64a2 */
if(!s->budget--) { s->failed_pc=0x0c0a64a2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a64a4;
P_0c0a64a4: /* original 5cf1, guest PC 0x0c0a64a4 */
if(!s->budget--) { s->failed_pc=0x0c0a64a4u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c0a64a6;
P_0c0a64a6: /* original 6df2, guest PC 0x0c0a64a6 */
if(!s->budget--) { s->failed_pc=0x0c0a64a6u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0a64a8;
P_0c0a64a8: /* original 64c2, guest PC 0x0c0a64a8 */
if(!s->budget--) { s->failed_pc=0x0c0a64a8u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a64aa;
P_0c0a64aa: /* original 5ef2, guest PC 0x0c0a64aa */
if(!s->budget--) { s->failed_pc=0x0c0a64aau; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0a64ac;
P_0c0a64ac: /* original 684c, guest PC 0x0c0a64ac */
if(!s->budget--) { s->failed_pc=0x0c0a64acu; return 0; }
r[8]=r[4]&255u;
goto P_0c0a64ae;
P_0c0a64ae: /* original 6b83, guest PC 0x0c0a64ae */
if(!s->budget--) { s->failed_pc=0x0c0a64aeu; return 0; }
r[11]=r[8];
goto P_0c0a64b0;
P_0c0a64b0: /* original 6383, guest PC 0x0c0a64b0 */
if(!s->budget--) { s->failed_pc=0x0c0a64b0u; return 0; }
r[3]=r[8];
goto P_0c0a64b2;
P_0c0a64b2: /* original 4b00, guest PC 0x0c0a64b2 */
if(!s->budget--) { s->failed_pc=0x0c0a64b2u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0a64b4;
P_0c0a64b4: /* original 3b3c, guest PC 0x0c0a64b4 */
if(!s->budget--) { s->failed_pc=0x0c0a64b4u; return 0; }
r[11]+=r[3];
goto P_0c0a64b6;
P_0c0a64b6: /* original 4b08, guest PC 0x0c0a64b6 */
if(!s->budget--) { s->failed_pc=0x0c0a64b6u; return 0; }
r[11]<<=2;
goto P_0c0a64b8;
P_0c0a64b8: /* original 7b04, guest PC 0x0c0a64b8 */
if(!s->budget--) { s->failed_pc=0x0c0a64b8u; return 0; }
r[11]+=0x00000004u;
goto P_0c0a64ba;
P_0c0a64ba: /* original bfdf, guest PC 0x0c0a64ba */
if(!s->budget--) { s->failed_pc=0x0c0a64bau; return 0; }
target=0x0c0a647cu; r[16]=0x0c0a64beu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a64beu) { target=s->pc; goto dispatch; }
goto P_0c0a64be;
P_0c0a64bc: /* original 64b3, guest PC 0x0c0a64bc */
if(!s->budget--) { s->failed_pc=0x0c0a64bcu; return 0; }
r[4]=r[11];
goto P_0c0a64be;
P_0c0a64be: /* original 65c3, guest PC 0x0c0a64be */
if(!s->budget--) { s->failed_pc=0x0c0a64beu; return 0; }
r[5]=r[12];
goto P_0c0a64c0;
P_0c0a64c0: /* original 6603, guest PC 0x0c0a64c0 */
if(!s->budget--) { s->failed_pc=0x0c0a64c0u; return 0; }
r[6]=r[0];
goto P_0c0a64c2;
P_0c0a64c2: /* original 6b03, guest PC 0x0c0a64c2 */
if(!s->budget--) { s->failed_pc=0x0c0a64c2u; return 0; }
r[11]=r[0];
goto P_0c0a64c4;
P_0c0a64c4: /* original b080, guest PC 0x0c0a64c4 */
if(!s->budget--) { s->failed_pc=0x0c0a64c4u; return 0; }
target=0x0c0a65c8u; r[16]=0x0c0a64c8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a64c8u) { target=s->pc; goto dispatch; }
goto P_0c0a64c8;
P_0c0a64c6: /* original 64d3, guest PC 0x0c0a64c6 */
if(!s->budget--) { s->failed_pc=0x0c0a64c6u; return 0; }
r[4]=r[13];
goto P_0c0a64c8;
P_0c0a64c8: /* original f3e8, guest PC 0x0c0a64c8 */
if(!s->budget--) { s->failed_pc=0x0c0a64c8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0a64ca;
P_0c0a64ca: /* original e03c, guest PC 0x0c0a64ca */
if(!s->budget--) { s->failed_pc=0x0c0a64cau; return 0; }
r[0]=0x0000003cu;
goto P_0c0a64cc;
P_0c0a64cc: /* original f48d, guest PC 0x0c0a64cc */
if(!s->budget--) { s->failed_pc=0x0c0a64ccu; return 0; }
fr[4]=0;
goto P_0c0a64ce;
P_0c0a64ce: /* original ea00, guest PC 0x0c0a64ce */
if(!s->budget--) { s->failed_pc=0x0c0a64ceu; return 0; }
r[10]=0x00000000u;
goto P_0c0a64d0;
P_0c0a64d0: /* original ff4c, guest PC 0x0c0a64d0 */
if(!s->budget--) { s->failed_pc=0x0c0a64d0u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0a64d2;
P_0c0a64d2: /* original ff37, guest PC 0x0c0a64d2 */
if(!s->budget--) { s->failed_pc=0x0c0a64d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64d4;
P_0c0a64d4: /* original e004, guest PC 0x0c0a64d4 */
if(!s->budget--) { s->failed_pc=0x0c0a64d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0a64d6;
P_0c0a64d6: /* original f3e6, guest PC 0x0c0a64d6 */
if(!s->budget--) { s->failed_pc=0x0c0a64d6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64d8;
P_0c0a64d8: /* original e040, guest PC 0x0c0a64d8 */
if(!s->budget--) { s->failed_pc=0x0c0a64d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0a64da;
P_0c0a64da: /* original ff37, guest PC 0x0c0a64da */
if(!s->budget--) { s->failed_pc=0x0c0a64dau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64dc;
P_0c0a64dc: /* original e008, guest PC 0x0c0a64dc */
if(!s->budget--) { s->failed_pc=0x0c0a64dcu; return 0; }
r[0]=0x00000008u;
goto P_0c0a64de;
P_0c0a64de: /* original f3e6, guest PC 0x0c0a64de */
if(!s->budget--) { s->failed_pc=0x0c0a64deu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64e0;
P_0c0a64e0: /* original e044, guest PC 0x0c0a64e0 */
if(!s->budget--) { s->failed_pc=0x0c0a64e0u; return 0; }
r[0]=0x00000044u;
goto P_0c0a64e2;
P_0c0a64e2: /* original ff37, guest PC 0x0c0a64e2 */
if(!s->budget--) { s->failed_pc=0x0c0a64e2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64e4;
P_0c0a64e4: /* original e00c, guest PC 0x0c0a64e4 */
if(!s->budget--) { s->failed_pc=0x0c0a64e4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a64e6;
P_0c0a64e6: /* original f3e6, guest PC 0x0c0a64e6 */
if(!s->budget--) { s->failed_pc=0x0c0a64e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64e8;
P_0c0a64e8: /* original e030, guest PC 0x0c0a64e8 */
if(!s->budget--) { s->failed_pc=0x0c0a64e8u; return 0; }
r[0]=0x00000030u;
goto P_0c0a64ea;
P_0c0a64ea: /* original ff37, guest PC 0x0c0a64ea */
if(!s->budget--) { s->failed_pc=0x0c0a64eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64ec;
P_0c0a64ec: /* original e010, guest PC 0x0c0a64ec */
if(!s->budget--) { s->failed_pc=0x0c0a64ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0a64ee;
P_0c0a64ee: /* original f3e6, guest PC 0x0c0a64ee */
if(!s->budget--) { s->failed_pc=0x0c0a64eeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64f0;
P_0c0a64f0: /* original e034, guest PC 0x0c0a64f0 */
if(!s->budget--) { s->failed_pc=0x0c0a64f0u; return 0; }
r[0]=0x00000034u;
goto P_0c0a64f2;
P_0c0a64f2: /* original ff37, guest PC 0x0c0a64f2 */
if(!s->budget--) { s->failed_pc=0x0c0a64f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64f4;
P_0c0a64f4: /* original e014, guest PC 0x0c0a64f4 */
if(!s->budget--) { s->failed_pc=0x0c0a64f4u; return 0; }
r[0]=0x00000014u;
goto P_0c0a64f6;
P_0c0a64f6: /* original f3e6, guest PC 0x0c0a64f6 */
if(!s->budget--) { s->failed_pc=0x0c0a64f6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a64f8;
P_0c0a64f8: /* original e038, guest PC 0x0c0a64f8 */
if(!s->budget--) { s->failed_pc=0x0c0a64f8u; return 0; }
r[0]=0x00000038u;
goto P_0c0a64fa;
P_0c0a64fa: /* original ff37, guest PC 0x0c0a64fa */
if(!s->budget--) { s->failed_pc=0x0c0a64fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a64fc;
P_0c0a64fc: /* original e018, guest PC 0x0c0a64fc */
if(!s->budget--) { s->failed_pc=0x0c0a64fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0a64fe;
P_0c0a64fe: /* original f3e6, guest PC 0x0c0a64fe */
if(!s->budget--) { s->failed_pc=0x0c0a64feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6500;
P_0c0a6500: /* original e024, guest PC 0x0c0a6500 */
if(!s->budget--) { s->failed_pc=0x0c0a6500u; return 0; }
r[0]=0x00000024u;
goto P_0c0a6502;
P_0c0a6502: /* original ff37, guest PC 0x0c0a6502 */
if(!s->budget--) { s->failed_pc=0x0c0a6502u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a6504;
P_0c0a6504: /* original e01c, guest PC 0x0c0a6504 */
if(!s->budget--) { s->failed_pc=0x0c0a6504u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a6506;
P_0c0a6506: /* original f3e6, guest PC 0x0c0a6506 */
if(!s->budget--) { s->failed_pc=0x0c0a6506u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6508;
P_0c0a6508: /* original e028, guest PC 0x0c0a6508 */
if(!s->budget--) { s->failed_pc=0x0c0a6508u; return 0; }
r[0]=0x00000028u;
goto P_0c0a650a;
P_0c0a650a: /* original 69a3, guest PC 0x0c0a650a */
if(!s->budget--) { s->failed_pc=0x0c0a650au; return 0; }
r[9]=r[10];
goto P_0c0a650c;
P_0c0a650c: /* original ff37, guest PC 0x0c0a650c */
if(!s->budget--) { s->failed_pc=0x0c0a650cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a650e;
P_0c0a650e: /* original e020, guest PC 0x0c0a650e */
if(!s->budget--) { s->failed_pc=0x0c0a650eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a6510;
P_0c0a6510: /* original f3e6, guest PC 0x0c0a6510 */
if(!s->budget--) { s->failed_pc=0x0c0a6510u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0a6512;
P_0c0a6512: /* original 6eb3, guest PC 0x0c0a6512 */
if(!s->budget--) { s->failed_pc=0x0c0a6512u; return 0; }
r[14]=r[11];
goto P_0c0a6514;
P_0c0a6514: /* original e02c, guest PC 0x0c0a6514 */
if(!s->budget--) { s->failed_pc=0x0c0a6514u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a6516;
P_0c0a6516: /* original 7e04, guest PC 0x0c0a6516 */
if(!s->budget--) { s->failed_pc=0x0c0a6516u; return 0; }
r[14]+=0x00000004u;
goto P_0c0a6518;
P_0c0a6518: /* original ff37, guest PC 0x0c0a6518 */
if(!s->budget--) { s->failed_pc=0x0c0a6518u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a651a;
P_0c0a651a: /* original a029, guest PC 0x0c0a651a */
if(!s->budget--) { s->failed_pc=0x0c0a651au; return 0; }
r[11]=r[10];
goto P_0c0a6570;
P_0c0a651c: /* original 6ba3, guest PC 0x0c0a651c */
if(!s->budget--) { s->failed_pc=0x0c0a651cu; return 0; }
r[11]=r[10];
goto P_0c0a651e;
P_0c0a651e: /* original 66f3, guest PC 0x0c0a651e */
if(!s->budget--) { s->failed_pc=0x0c0a651eu; return 0; }
r[6]=r[15];
goto P_0c0a6520;
P_0c0a6520: /* original dc3d, guest PC 0x0c0a6520 */
if(!s->budget--) { s->failed_pc=0x0c0a6520u; return 0; }
r[12]=read(ram,0x0c0a6618u,4);
goto P_0c0a6522;
P_0c0a6522: /* original 64f3, guest PC 0x0c0a6522 */
if(!s->budget--) { s->failed_pc=0x0c0a6522u; return 0; }
r[4]=r[15];
goto P_0c0a6524;
P_0c0a6524: /* original 65e3, guest PC 0x0c0a6524 */
if(!s->budget--) { s->failed_pc=0x0c0a6524u; return 0; }
r[5]=r[14];
goto P_0c0a6526;
P_0c0a6526: /* original 7630, guest PC 0x0c0a6526 */
if(!s->budget--) { s->failed_pc=0x0c0a6526u; return 0; }
r[6]+=0x00000030u;
goto P_0c0a6528;
P_0c0a6528: /* original 4c0b, guest PC 0x0c0a6528 */
if(!s->budget--) { s->failed_pc=0x0c0a6528u; return 0; }
target=r[12];
r[16]=0x0c0a652cu;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a652cu) { target=s->pc; goto dispatch; }
goto P_0c0a652c;
P_0c0a652a: /* original 7418, guest PC 0x0c0a652a */
if(!s->budget--) { s->failed_pc=0x0c0a652au; return 0; }
r[4]+=0x00000018u;
goto P_0c0a652c;
P_0c0a652c: /* original 66f3, guest PC 0x0c0a652c */
if(!s->budget--) { s->failed_pc=0x0c0a652cu; return 0; }
r[6]=r[15];
goto P_0c0a652e;
P_0c0a652e: /* original 64f3, guest PC 0x0c0a652e */
if(!s->budget--) { s->failed_pc=0x0c0a652eu; return 0; }
r[4]=r[15];
goto P_0c0a6530;
P_0c0a6530: /* original 65e3, guest PC 0x0c0a6530 */
if(!s->budget--) { s->failed_pc=0x0c0a6530u; return 0; }
r[5]=r[14];
goto P_0c0a6532;
P_0c0a6532: /* original 7624, guest PC 0x0c0a6532 */
if(!s->budget--) { s->failed_pc=0x0c0a6532u; return 0; }
r[6]+=0x00000024u;
goto P_0c0a6534;
P_0c0a6534: /* original 4c0b, guest PC 0x0c0a6534 */
if(!s->budget--) { s->failed_pc=0x0c0a6534u; return 0; }
target=r[12];
r[16]=0x0c0a6538u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6538u) { target=s->pc; goto dispatch; }
goto P_0c0a6538;
P_0c0a6536: /* original 740c, guest PC 0x0c0a6536 */
if(!s->budget--) { s->failed_pc=0x0c0a6536u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a6538;
P_0c0a6538: /* original 65f3, guest PC 0x0c0a6538 */
if(!s->budget--) { s->failed_pc=0x0c0a6538u; return 0; }
r[5]=r[15];
goto P_0c0a653a;
P_0c0a653a: /* original dc38, guest PC 0x0c0a653a */
if(!s->budget--) { s->failed_pc=0x0c0a653au; return 0; }
r[12]=read(ram,0x0c0a661cu,4);
goto P_0c0a653c;
P_0c0a653c: /* original 64f3, guest PC 0x0c0a653c */
if(!s->budget--) { s->failed_pc=0x0c0a653cu; return 0; }
r[4]=r[15];
goto P_0c0a653e;
P_0c0a653e: /* original 753c, guest PC 0x0c0a653e */
if(!s->budget--) { s->failed_pc=0x0c0a653eu; return 0; }
r[5]+=0x0000003cu;
goto P_0c0a6540;
P_0c0a6540: /* original 7e0c, guest PC 0x0c0a6540 */
if(!s->budget--) { s->failed_pc=0x0c0a6540u; return 0; }
r[14]+=0x0000000cu;
goto P_0c0a6542;
P_0c0a6542: /* original 4c0b, guest PC 0x0c0a6542 */
if(!s->budget--) { s->failed_pc=0x0c0a6542u; return 0; }
target=r[12];
r[16]=0x0c0a6546u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6546u) { target=s->pc; goto dispatch; }
goto P_0c0a6546;
P_0c0a6544: /* original 7418, guest PC 0x0c0a6544 */
if(!s->budget--) { s->failed_pc=0x0c0a6544u; return 0; }
r[4]+=0x00000018u;
goto P_0c0a6546;
P_0c0a6546: /* original 65f3, guest PC 0x0c0a6546 */
if(!s->budget--) { s->failed_pc=0x0c0a6546u; return 0; }
r[5]=r[15];
goto P_0c0a6548;
P_0c0a6548: /* original 64f3, guest PC 0x0c0a6548 */
if(!s->budget--) { s->failed_pc=0x0c0a6548u; return 0; }
r[4]=r[15];
goto P_0c0a654a;
P_0c0a654a: /* original 753c, guest PC 0x0c0a654a */
if(!s->budget--) { s->failed_pc=0x0c0a654au; return 0; }
r[5]+=0x0000003cu;
goto P_0c0a654c;
P_0c0a654c: /* original fe0c, guest PC 0x0c0a654c */
if(!s->budget--) { s->failed_pc=0x0c0a654cu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c0a654e;
P_0c0a654e: /* original 4c0b, guest PC 0x0c0a654e */
if(!s->budget--) { s->failed_pc=0x0c0a654eu; return 0; }
target=r[12];
r[16]=0x0c0a6552u;
r[4]+=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a6552u) { target=s->pc; goto dispatch; }
goto P_0c0a6552;
P_0c0a6550: /* original 740c, guest PC 0x0c0a6550 */
if(!s->budget--) { s->failed_pc=0x0c0a6550u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a6552;
P_0c0a6552: /* original f38d, guest PC 0x0c0a6552 */
if(!s->budget--) { s->failed_pc=0x0c0a6552u; return 0; }
fr[3]=0;
goto P_0c0a6554;
P_0c0a6554: /* original f3e5, guest PC 0x0c0a6554 */
if(!s->budget--) { s->failed_pc=0x0c0a6554u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0a6556;
P_0c0a6556: /* original 8f03, guest PC 0x0c0a6556 */
if(!s->budget--) { s->failed_pc=0x0c0a6556u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(!cond) { goto P_0c0a6560; }
goto P_0c0a655a;
P_0c0a6558: /* original f40c, guest PC 0x0c0a6558 */
if(!s->budget--) { s->failed_pc=0x0c0a6558u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a655a;
P_0c0a655a: /* original e501, guest PC 0x0c0a655a */
if(!s->budget--) { s->failed_pc=0x0c0a655au; return 0; }
r[5]=0x00000001u;
goto P_0c0a655c;
P_0c0a655c: /* original a001, guest PC 0x0c0a655c */
if(!s->budget--) { s->failed_pc=0x0c0a655cu; return 0; }
r[4]=r[5];
goto P_0c0a6562;
P_0c0a655e: /* original 6453, guest PC 0x0c0a655e */
if(!s->budget--) { s->failed_pc=0x0c0a655eu; return 0; }
r[4]=r[5];
goto P_0c0a6560;
P_0c0a6560: /* original 6493, guest PC 0x0c0a6560 */
if(!s->budget--) { s->failed_pc=0x0c0a6560u; return 0; }
r[4]=r[9];
goto P_0c0a6562;
P_0c0a6562: /* original ff45, guest PC 0x0c0a6562 */
if(!s->budget--) { s->failed_pc=0x0c0a6562u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c0a6564;
P_0c0a6564: /* original 63bb, guest PC 0x0c0a6564 */
if(!s->budget--) { s->failed_pc=0x0c0a6564u; return 0; }
r[3]=0u-r[11];
goto P_0c0a6566;
P_0c0a6566: /* original 443d, guest PC 0x0c0a6566 */
if(!s->budget--) { s->failed_pc=0x0c0a6566u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0a6568;
P_0c0a6568: /* original 8f01, guest PC 0x0c0a6568 */
if(!s->budget--) { s->failed_pc=0x0c0a6568u; return 0; }
cond=r[17]&1u;
r[10]|=r[4];
if(!cond) { goto P_0c0a656e; }
goto P_0c0a656c;
P_0c0a656a: /* original 2a4b, guest PC 0x0c0a656a */
if(!s->budget--) { s->failed_pc=0x0c0a656au; return 0; }
r[10]|=r[4];
goto P_0c0a656c;
P_0c0a656c: /* original ff4c, guest PC 0x0c0a656c */
if(!s->budget--) { s->failed_pc=0x0c0a656cu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0a656e;
P_0c0a656e: /* original 7b01, guest PC 0x0c0a656e */
if(!s->budget--) { s->failed_pc=0x0c0a656eu; return 0; }
r[11]+=0x00000001u;
goto P_0c0a6570;
P_0c0a6570: /* original 3b83, guest PC 0x0c0a6570 */
if(!s->budget--) { s->failed_pc=0x0c0a6570u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c0a6572;
P_0c0a6572: /* original 8bd4, guest PC 0x0c0a6572 */
if(!s->budget--) { s->failed_pc=0x0c0a6572u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a651e; }
goto P_0c0a6574;
P_0c0a6574: /* original e040, guest PC 0x0c0a6574 */
if(!s->budget--) { s->failed_pc=0x0c0a6574u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6576;
P_0c0a6576: /* original ff5d, guest PC 0x0c0a6576 */
if(!s->budget--) { s->failed_pc=0x0c0a6576u; return 0; }
fr[15]&=0x7fffffffu;
goto P_0c0a6578;
P_0c0a6578: /* original f5d6, guest PC 0x0c0a6578 */
if(!s->budget--) { s->failed_pc=0x0c0a6578u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c0a657a;
P_0c0a657a: /* original e03c, guest PC 0x0c0a657a */
if(!s->budget--) { s->failed_pc=0x0c0a657au; return 0; }
r[0]=0x0000003cu;
goto P_0c0a657c;
P_0c0a657c: /* original f3f6, guest PC 0x0c0a657c */
if(!s->budget--) { s->failed_pc=0x0c0a657cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a657e;
P_0c0a657e: /* original e044, guest PC 0x0c0a657e */
if(!s->budget--) { s->failed_pc=0x0c0a657eu; return 0; }
r[0]=0x00000044u;
goto P_0c0a6580;
P_0c0a6580: /* original f6d6, guest PC 0x0c0a6580 */
if(!s->budget--) { s->failed_pc=0x0c0a6580u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c0a6582;
P_0c0a6582: /* original e040, guest PC 0x0c0a6582 */
if(!s->budget--) { s->failed_pc=0x0c0a6582u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6584;
P_0c0a6584: /* original f0fc, guest PC 0x0c0a6584 */
if(!s->budget--) { s->failed_pc=0x0c0a6584u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0a6586;
P_0c0a6586: /* original f53e, guest PC 0x0c0a6586 */
if(!s->budget--) { s->failed_pc=0x0c0a6586u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[3],fr[5],r[18]);
goto P_0c0a6588;
P_0c0a6588: /* original f3f6, guest PC 0x0c0a6588 */
if(!s->budget--) { s->failed_pc=0x0c0a6588u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a658a;
P_0c0a658a: /* original e048, guest PC 0x0c0a658a */
if(!s->budget--) { s->failed_pc=0x0c0a658au; return 0; }
r[0]=0x00000048u;
goto P_0c0a658c;
P_0c0a658c: /* original f4fc, guest PC 0x0c0a658c */
if(!s->budget--) { s->failed_pc=0x0c0a658cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a658e;
P_0c0a658e: /* original f63e, guest PC 0x0c0a658e */
if(!s->budget--) { s->failed_pc=0x0c0a658eu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[3],fr[6],r[18]);
goto P_0c0a6590;
P_0c0a6590: /* original f3d6, guest PC 0x0c0a6590 */
if(!s->budget--) { s->failed_pc=0x0c0a6590u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0a6592;
P_0c0a6592: /* original e044, guest PC 0x0c0a6592 */
if(!s->budget--) { s->failed_pc=0x0c0a6592u; return 0; }
r[0]=0x00000044u;
goto P_0c0a6594;
P_0c0a6594: /* original f2f6, guest PC 0x0c0a6594 */
if(!s->budget--) { s->failed_pc=0x0c0a6594u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0a6596;
P_0c0a6596: /* original e040, guest PC 0x0c0a6596 */
if(!s->budget--) { s->failed_pc=0x0c0a6596u; return 0; }
r[0]=0x00000040u;
goto P_0c0a6598;
P_0c0a6598: /* original f32e, guest PC 0x0c0a6598 */
if(!s->budget--) { s->failed_pc=0x0c0a6598u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0a659a;
P_0c0a659a: /* original f43c, guest PC 0x0c0a659a */
if(!s->budget--) { s->failed_pc=0x0c0a659au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a659c;
P_0c0a659c: /* original fd57, guest PC 0x0c0a659c */
if(!s->budget--) { s->failed_pc=0x0c0a659cu; return 0; }
vf3_matrix_store(s,ram,5,r[13]+r[0]);
goto P_0c0a659e;
P_0c0a659e: /* original e044, guest PC 0x0c0a659e */
if(!s->budget--) { s->failed_pc=0x0c0a659eu; return 0; }
r[0]=0x00000044u;
goto P_0c0a65a0;
P_0c0a65a0: /* original fd67, guest PC 0x0c0a65a0 */
if(!s->budget--) { s->failed_pc=0x0c0a65a0u; return 0; }
vf3_matrix_store(s,ram,6,r[13]+r[0]);
goto P_0c0a65a2;
P_0c0a65a2: /* original e048, guest PC 0x0c0a65a2 */
if(!s->budget--) { s->failed_pc=0x0c0a65a2u; return 0; }
r[0]=0x00000048u;
goto P_0c0a65a4;
P_0c0a65a4: /* original fd47, guest PC 0x0c0a65a4 */
if(!s->budget--) { s->failed_pc=0x0c0a65a4u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a65a6;
P_0c0a65a6: /* original 2fa2, guest PC 0x0c0a65a6 */
if(!s->budget--) { s->failed_pc=0x0c0a65a6u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c0a65a8;
P_0c0a65a8: /* original d31d, guest PC 0x0c0a65a8 */
if(!s->budget--) { s->failed_pc=0x0c0a65a8u; return 0; }
r[3]=read(ram,0x0c0a6620u,4);
goto P_0c0a65aa;
P_0c0a65aa: /* original 430b, guest PC 0x0c0a65aa */
if(!s->budget--) { s->failed_pc=0x0c0a65aau; return 0; }
target=r[3];
r[16]=0x0c0a65aeu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a65aeu) { target=s->pc; goto dispatch; }
goto P_0c0a65ae;
P_0c0a65ac: /* original e401, guest PC 0x0c0a65ac */
if(!s->budget--) { s->failed_pc=0x0c0a65acu; return 0; }
r[4]=0x00000001u;
goto P_0c0a65ae;
P_0c0a65ae: /* original 60f2, guest PC 0x0c0a65ae */
if(!s->budget--) { s->failed_pc=0x0c0a65aeu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0a65b0;
P_0c0a65b0: /* original 7f48, guest PC 0x0c0a65b0 */
if(!s->budget--) { s->failed_pc=0x0c0a65b0u; return 0; }
r[15]+=0x00000048u;
goto P_0c0a65b2;
P_0c0a65b2: /* original 4f26, guest PC 0x0c0a65b2 */
if(!s->budget--) { s->failed_pc=0x0c0a65b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a65b4;
P_0c0a65b4: /* original fef9, guest PC 0x0c0a65b4 */
if(!s->budget--) { s->failed_pc=0x0c0a65b4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a65b6;
P_0c0a65b6: /* original fff9, guest PC 0x0c0a65b6 */
if(!s->budget--) { s->failed_pc=0x0c0a65b6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a65b8;
P_0c0a65b8: /* original 68f6, guest PC 0x0c0a65b8 */
if(!s->budget--) { s->failed_pc=0x0c0a65b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a65ba;
P_0c0a65ba: /* original 69f6, guest PC 0x0c0a65ba */
if(!s->budget--) { s->failed_pc=0x0c0a65bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a65bc;
P_0c0a65bc: /* original 6af6, guest PC 0x0c0a65bc */
if(!s->budget--) { s->failed_pc=0x0c0a65bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a65be;
P_0c0a65be: /* original 6bf6, guest PC 0x0c0a65be */
if(!s->budget--) { s->failed_pc=0x0c0a65beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a65c0;
P_0c0a65c0: /* original 6cf6, guest PC 0x0c0a65c0 */
if(!s->budget--) { s->failed_pc=0x0c0a65c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a65c2;
P_0c0a65c2: /* original 6df6, guest PC 0x0c0a65c2 */
if(!s->budget--) { s->failed_pc=0x0c0a65c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a65c4;
P_0c0a65c4: /* original 000b, guest PC 0x0c0a65c4 */
if(!s->budget--) { s->failed_pc=0x0c0a65c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a65c6: /* original 6ef6, guest PC 0x0c0a65c6 */
if(!s->budget--) { s->failed_pc=0x0c0a65c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a65c8u,s,ram);
P_0c0c5f8e: /* original 2fe6, guest PC 0x0c0c5f8e */
if(!s->budget--) { s->failed_pc=0x0c0c5f8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5f90;
P_0c0c5f90: /* original 6e43, guest PC 0x0c0c5f90 */
if(!s->budget--) { s->failed_pc=0x0c0c5f90u; return 0; }
r[14]=r[4];
goto P_0c0c5f92;
P_0c0c5f92: /* original d319, guest PC 0x0c0c5f92 */
if(!s->budget--) { s->failed_pc=0x0c0c5f92u; return 0; }
r[3]=read(ram,0x0c0c5ff8u,4);
goto P_0c0c5f94;
P_0c0c5f94: /* original 4f22, guest PC 0x0c0c5f94 */
if(!s->budget--) { s->failed_pc=0x0c0c5f94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5f96;
P_0c0c5f96: /* original 6232, guest PC 0x0c0c5f96 */
if(!s->budget--) { s->failed_pc=0x0c0c5f96u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0c5f98;
P_0c0c5f98: /* original 32e0, guest PC 0x0c0c5f98 */
if(!s->budget--) { s->failed_pc=0x0c0c5f98u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c0c5f9a;
P_0c0c5f9a: /* original 8918, guest PC 0x0c0c5f9a */
if(!s->budget--) { s->failed_pc=0x0c0c5f9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5fce; }
goto P_0c0c5f9c;
P_0c0c5f9c: /* original d114, guest PC 0x0c0c5f9c */
if(!s->budget--) { s->failed_pc=0x0c0c5f9cu; return 0; }
r[1]=read(ram,0x0c0c5ff0u,4);
goto P_0c0c5f9e;
P_0c0c5f9e: /* original d213, guest PC 0x0c0c5f9e */
if(!s->budget--) { s->failed_pc=0x0c0c5f9eu; return 0; }
r[2]=read(ram,0x0c0c5fecu,4);
goto P_0c0c5fa0;
P_0c0c5fa0: /* original 6512, guest PC 0x0c0c5fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c5fa0u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c0c5fa2;
P_0c0c5fa2: /* original d316, guest PC 0x0c0c5fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c5fa2u; return 0; }
r[3]=read(ram,0x0c0c5ffcu,4);
goto P_0c0c5fa4;
P_0c0c5fa4: /* original 352c, guest PC 0x0c0c5fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c5fa4u; return 0; }
r[5]+=r[2];
goto P_0c0c5fa6;
P_0c0c5fa6: /* original 430b, guest PC 0x0c0c5fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c5fa6u; return 0; }
target=r[3];
r[16]=0x0c0c5faau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5faau) { target=s->pc; goto dispatch; }
goto P_0c0c5faa;
P_0c0c5fa8: /* original 64e3, guest PC 0x0c0c5fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c5fa8u; return 0; }
r[4]=r[14];
goto P_0c0c5faa;
P_0c0c5faa: /* original d215, guest PC 0x0c0c5faa */
if(!s->budget--) { s->failed_pc=0x0c0c5faau; return 0; }
r[2]=read(ram,0x0c0c6000u,4);
goto P_0c0c5fac;
P_0c0c5fac: /* original 420b, guest PC 0x0c0c5fac */
if(!s->budget--) { s->failed_pc=0x0c0c5facu; return 0; }
target=r[2];
r[16]=0x0c0c5fb0u;
r[4]=0x00000006u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5fb0u) { target=s->pc; goto dispatch; }
goto P_0c0c5fb0;
P_0c0c5fae: /* original e406, guest PC 0x0c0c5fae */
if(!s->budget--) { s->failed_pc=0x0c0c5faeu; return 0; }
r[4]=0x00000006u;
goto P_0c0c5fb0;
P_0c0c5fb0: /* original d20f, guest PC 0x0c0c5fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5fb0u; return 0; }
r[2]=read(ram,0x0c0c5ff0u,4);
goto P_0c0c5fb2;
P_0c0c5fb2: /* original e506, guest PC 0x0c0c5fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5fb2u; return 0; }
r[5]=0x00000006u;
goto P_0c0c5fb4;
P_0c0c5fb4: /* original d113, guest PC 0x0c0c5fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5fb4u; return 0; }
r[1]=read(ram,0x0c0c6004u,4);
goto P_0c0c5fb6;
P_0c0c5fb6: /* original 6422, guest PC 0x0c0c5fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5fb6u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5fb8;
P_0c0c5fb8: /* original d30c, guest PC 0x0c0c5fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5fb8u; return 0; }
r[3]=read(ram,0x0c0c5fecu,4);
goto P_0c0c5fba;
P_0c0c5fba: /* original 410b, guest PC 0x0c0c5fba */
if(!s->budget--) { s->failed_pc=0x0c0c5fbau; return 0; }
target=r[1];
r[16]=0x0c0c5fbeu;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5fbeu) { target=s->pc; goto dispatch; }
goto P_0c0c5fbe;
P_0c0c5fbc: /* original 343c, guest PC 0x0c0c5fbc */
if(!s->budget--) { s->failed_pc=0x0c0c5fbcu; return 0; }
r[4]+=r[3];
goto P_0c0c5fbe;
P_0c0c5fbe: /* original 2008, guest PC 0x0c0c5fbe */
if(!s->budget--) { s->failed_pc=0x0c0c5fbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5fc0;
P_0c0c5fc0: /* original 8903, guest PC 0x0c0c5fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5fc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5fca; }
goto P_0c0c5fc2;
P_0c0c5fc2: /* original d211, guest PC 0x0c0c5fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5fc2u; return 0; }
r[2]=read(ram,0x0c0c6008u,4);
goto P_0c0c5fc4;
P_0c0c5fc4: /* original 9507, guest PC 0x0c0c5fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5fc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5fd6u,2);
goto P_0c0c5fc6;
P_0c0c5fc6: /* original 420b, guest PC 0x0c0c5fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5fc6u; return 0; }
target=r[2];
r[16]=0x0c0c5fcau;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5fcau) { target=s->pc; goto dispatch; }
goto P_0c0c5fca;
P_0c0c5fc8: /* original e401, guest PC 0x0c0c5fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5fc8u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5fca;
P_0c0c5fca: /* original d30b, guest PC 0x0c0c5fca */
if(!s->budget--) { s->failed_pc=0x0c0c5fcau; return 0; }
r[3]=read(ram,0x0c0c5ff8u,4);
goto P_0c0c5fcc;
P_0c0c5fcc: /* original 23e2, guest PC 0x0c0c5fcc */
if(!s->budget--) { s->failed_pc=0x0c0c5fccu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c0c5fce;
P_0c0c5fce: /* original 4f26, guest PC 0x0c0c5fce */
if(!s->budget--) { s->failed_pc=0x0c0c5fceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5fd0;
P_0c0c5fd0: /* original 000b, guest PC 0x0c0c5fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5fd0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5fd2: /* original 6ef6, guest PC 0x0c0c5fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5fd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5fd4u,s,ram);
P_0c0c8d60: /* original 2fe6, guest PC 0x0c0c8d60 */
if(!s->budget--) { s->failed_pc=0x0c0c8d60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8d62;
P_0c0c8d62: /* original 2fd6, guest PC 0x0c0c8d62 */
if(!s->budget--) { s->failed_pc=0x0c0c8d62u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8d64;
P_0c0c8d64: /* original 4f22, guest PC 0x0c0c8d64 */
if(!s->budget--) { s->failed_pc=0x0c0c8d64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8d66;
P_0c0c8d66: /* original dd36, guest PC 0x0c0c8d66 */
if(!s->budget--) { s->failed_pc=0x0c0c8d66u; return 0; }
r[13]=read(ram,0x0c0c8e40u,4);
goto P_0c0c8d68;
P_0c0c8d68: /* original a00a, guest PC 0x0c0c8d68 */
if(!s->budget--) { s->failed_pc=0x0c0c8d68u; return 0; }
r[14]=r[4];
goto P_0c0c8d80;
P_0c0c8d6a: /* original 6e43, guest PC 0x0c0c8d6a */
if(!s->budget--) { s->failed_pc=0x0c0c8d6au; return 0; }
r[14]=r[4];
goto P_0c0c8d6c;
P_0c0c8d6c: /* original 85e1, guest PC 0x0c0c8d6c */
if(!s->budget--) { s->failed_pc=0x0c0c8d6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c8d6e;
P_0c0c8d6e: /* original e307, guest PC 0x0c0c8d6e */
if(!s->budget--) { s->failed_pc=0x0c0c8d6eu; return 0; }
r[3]=0x00000007u;
goto P_0c0c8d70;
P_0c0c8d70: /* original 64e1, guest PC 0x0c0c8d70 */
if(!s->budget--) { s->failed_pc=0x0c0c8d70u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c0c8d72;
P_0c0c8d72: /* original e601, guest PC 0x0c0c8d72 */
if(!s->budget--) { s->failed_pc=0x0c0c8d72u; return 0; }
r[6]=0x00000001u;
goto P_0c0c8d74;
P_0c0c8d74: /* original 403c, guest PC 0x0c0c8d74 */
if(!s->budget--) { s->failed_pc=0x0c0c8d74u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0c8d76;
P_0c0c8d76: /* original 4400, guest PC 0x0c0c8d76 */
if(!s->budget--) { s->failed_pc=0x0c0c8d76u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c8d78;
P_0c0c8d78: /* original 240b, guest PC 0x0c0c8d78 */
if(!s->budget--) { s->failed_pc=0x0c0c8d78u; return 0; }
r[4]|=r[0];
goto P_0c0c8d7a;
P_0c0c8d7a: /* original 4d0b, guest PC 0x0c0c8d7a */
if(!s->budget--) { s->failed_pc=0x0c0c8d7au; return 0; }
target=r[13];
r[16]=0x0c0c8d7eu;
r[5]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8d7eu) { target=s->pc; goto dispatch; }
goto P_0c0c8d7e;
P_0c0c8d7c: /* original 55e1, guest PC 0x0c0c8d7c */
if(!s->budget--) { s->failed_pc=0x0c0c8d7cu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0c8d7e;
P_0c0c8d7e: /* original 7e08, guest PC 0x0c0c8d7e */
if(!s->budget--) { s->failed_pc=0x0c0c8d7eu; return 0; }
r[14]+=0x00000008u;
goto P_0c0c8d80;
P_0c0c8d80: /* original 62e1, guest PC 0x0c0c8d80 */
if(!s->budget--) { s->failed_pc=0x0c0c8d80u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c8d82;
P_0c0c8d82: /* original 4211, guest PC 0x0c0c8d82 */
if(!s->budget--) { s->failed_pc=0x0c0c8d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c8d84;
P_0c0c8d84: /* original 89f2, guest PC 0x0c0c8d84 */
if(!s->budget--) { s->failed_pc=0x0c0c8d84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8d6c; }
goto P_0c0c8d86;
P_0c0c8d86: /* original 4f26, guest PC 0x0c0c8d86 */
if(!s->budget--) { s->failed_pc=0x0c0c8d86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8d88;
P_0c0c8d88: /* original 6df6, guest PC 0x0c0c8d88 */
if(!s->budget--) { s->failed_pc=0x0c0c8d88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c8d8a;
P_0c0c8d8a: /* original 000b, guest PC 0x0c0c8d8a */
if(!s->budget--) { s->failed_pc=0x0c0c8d8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c8d8c: /* original 6ef6, guest PC 0x0c0c8d8c */
if(!s->budget--) { s->failed_pc=0x0c0c8d8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8d8eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0371f8u,0x0c0371fau,0x0c0371fcu,0x0c037240u,0x0c037242u,0x0c037244u,0x0c037246u,0x0c03c720u,0x0c03c722u,0x0c03c724u,0x0c03c726u,0x0c03c728u,0x0c03c72au,0x0c03c72cu,0x0c03c72eu,0x0c03c730u,
0x0c03c732u,0x0c03c734u,0x0c03c736u,0x0c03c738u,0x0c03c73au,0x0c03c73cu,0x0c03c73eu,0x0c03c740u,0x0c03c750u,0x0c03c752u,0x0c03c754u,0x0c03c756u,0x0c03c758u,0x0c03c75au,0x0c03c75cu,0x0c03c75eu,
0x0c03c760u,0x0c03c762u,0x0c03c764u,0x0c03c766u,0x0c03c768u,0x0c03c76au,0x0c03c76cu,0x0c03c76eu,0x0c03c770u,0x0c03c772u,0x0c03c774u,0x0c03c776u,0x0c03c778u,0x0c03c77au,0x0c03c77cu,0x0c03c77eu,
0x0c03c780u,0x0c03c782u,0x0c03c784u,0x0c03c786u,0x0c03c788u,0x0c03c78au,0x0c03c78cu,0x0c03c78eu,0x0c03c790u,0x0c03c792u,0x0c03c794u,0x0c03c796u,0x0c03c798u,0x0c03c79au,0x0c03c79cu,0x0c03c79eu,
0x0c03c7a0u,0x0c03c7a2u,0x0c03c7a4u,0x0c03c7a6u,0x0c03c7a8u,0x0c03c7aau,0x0c03c7acu,0x0c03c7aeu,0x0c03c7b0u,0x0c03c7b2u,0x0c03c7b4u,0x0c03c7b6u,0x0c03c7b8u,0x0c03c7bau,0x0c03c7bcu,0x0c03c7beu,
0x0c03c7c0u,0x0c03c7c2u,0x0c03c7c4u,0x0c03c7c6u,0x0c03c7c8u,0x0c03c7cau,0x0c03c7ccu,0x0c03c7ceu,0x0c03c7d0u,0x0c03c7d2u,0x0c03c7d4u,0x0c03c7d6u,0x0c03c7d8u,0x0c03c7dau,0x0c03c7dcu,0x0c03c7deu,
0x0c03c7e0u,0x0c03c7e2u,0x0c03c7e4u,0x0c03c7e6u,0x0c03c7e8u,0x0c03c7eau,0x0c03c7ecu,0x0c03c7eeu,0x0c03c7f0u,0x0c03c7f2u,0x0c03c7f4u,0x0c03c7f6u,0x0c03c7f8u,0x0c03c7fau,0x0c03c7fcu,0x0c03c7feu,
0x0c03c800u,0x0c03c802u,0x0c03c804u,0x0c03c806u,0x0c03c808u,0x0c03c80au,0x0c03c80cu,0x0c03c80eu,0x0c03c810u,0x0c03c812u,0x0c0424d0u,0x0c0424d2u,0x0c0424d4u,0x0c0424d6u,0x0c0424d8u,0x0c0424dau,
0x0c0424dcu,0x0c0424deu,0x0c0424e0u,0x0c0424e2u,0x0c0424e4u,0x0c0424e6u,0x0c0424e8u,0x0c0424eau,0x0c0424ecu,0x0c0424eeu,0x0c0424f0u,0x0c0424f2u,0x0c0424f4u,0x0c0424f6u,0x0c0424f8u,0x0c0424fau,
0x0c0424fcu,0x0c0424feu,0x0c042500u,0x0c042502u,0x0c042504u,0x0c042506u,0x0c042508u,0x0c04250au,0x0c04250cu,0x0c04250eu,0x0c042510u,0x0c042512u,0x0c042514u,0x0c042516u,0x0c042518u,0x0c04251au,
0x0c04251cu,0x0c04251eu,0x0c042520u,0x0c042522u,0x0c042524u,0x0c042526u,0x0c042528u,0x0c04252au,0x0c04252cu,0x0c04252eu,0x0c042530u,0x0c042532u,0x0c042534u,0x0c042536u,0x0c042538u,0x0c04253au,
0x0c04253cu,0x0c04253eu,0x0c042540u,0x0c042542u,0x0c042544u,0x0c042546u,0x0c042548u,0x0c04254au,0x0c04254cu,0x0c04254eu,0x0c042550u,0x0c042552u,0x0c042554u,0x0c042556u,0x0c042558u,0x0c04255au,
0x0c04255cu,0x0c04255eu,0x0c042560u,0x0c042562u,0x0c042564u,0x0c042566u,0x0c042568u,0x0c04256au,0x0c04256cu,0x0c04256eu,0x0c042570u,0x0c042572u,0x0c042574u,0x0c042576u,0x0c042578u,0x0c04257au,
0x0c04257cu,0x0c04257eu,0x0c042580u,0x0c042582u,0x0c042584u,0x0c042586u,0x0c042588u,0x0c04258au,0x0c04258cu,0x0c04258eu,0x0c042590u,0x0c042592u,0x0c042594u,0x0c042596u,0x0c042598u,0x0c04259au,
0x0c04259cu,0x0c04259eu,0x0c0425a0u,0x0c0425a2u,0x0c0425a4u,0x0c0425a6u,0x0c0425a8u,0x0c0425aau,0x0c0425acu,0x0c0425aeu,0x0c0425b0u,0x0c0425b2u,0x0c0425b4u,0x0c0425b6u,0x0c0425b8u,0x0c0425bau,
0x0c0425bcu,0x0c0425beu,0x0c0425c0u,0x0c0425c2u,0x0c0425c4u,0x0c0425c6u,0x0c0425c8u,0x0c0425cau,0x0c0425ccu,0x0c0425ceu,0x0c0425d0u,0x0c0425d2u,0x0c0425d4u,0x0c0425d6u,0x0c0425d8u,0x0c0425dau,
0x0c0425dcu,0x0c0425deu,0x0c0425e0u,0x0c0425e2u,0x0c0425e4u,0x0c0425e6u,0x0c0425e8u,0x0c0425eau,0x0c0425ecu,0x0c0425eeu,0x0c0425f0u,0x0c0425f2u,0x0c0425f4u,0x0c0425f6u,0x0c0425f8u,0x0c0425fau,
0x0c0425fcu,0x0c042660u,0x0c042662u,0x0c042664u,0x0c042666u,0x0c042668u,0x0c04266au,0x0c04266cu,0x0c04266eu,0x0c042670u,0x0c042672u,0x0c042674u,0x0c042676u,0x0c042678u,0x0c04267au,0x0c04267cu,
0x0c04267eu,0x0c042680u,0x0c042682u,0x0c042684u,0x0c042686u,0x0c042688u,0x0c04268au,0x0c04268cu,0x0c04268eu,0x0c042690u,0x0c042692u,0x0c042694u,0x0c042696u,0x0c042698u,0x0c04269au,0x0c04269cu,
0x0c04269eu,0x0c0426a0u,0x0c0426a2u,0x0c0426a4u,0x0c0426a6u,0x0c0426a8u,0x0c0426aau,0x0c0426acu,0x0c0426aeu,0x0c0426b0u,0x0c0426b2u,0x0c0426b4u,0x0c0426b6u,0x0c0426b8u,0x0c0426bau,0x0c0426c0u,
0x0c0426c2u,0x0c0426c4u,0x0c0426c6u,0x0c0426d0u,0x0c0426d2u,0x0c0426d4u,0x0c0426d6u,0x0c0426d8u,0x0c0426dau,0x0c0426dcu,0x0c0426deu,0x0c0426e0u,0x0c0426e2u,0x0c0426e4u,0x0c0426e6u,0x0c0426e8u,
0x0c0426eau,0x0c0426ecu,0x0c0426eeu,0x0c0426f0u,0x0c0426f2u,0x0c0426f4u,0x0c0426f6u,0x0c0426f8u,0x0c0426fau,0x0c0426fcu,0x0c0426feu,0x0c042700u,0x0c042702u,0x0c042704u,0x0c042706u,0x0c042708u,
0x0c04270au,0x0c04270cu,0x0c04270eu,0x0c042710u,0x0c042740u,0x0c042742u,0x0c042744u,0x0c042746u,0x0c042748u,0x0c04274au,0x0c04274cu,0x0c04274eu,0x0c042750u,0x0c042752u,0x0c042754u,0x0c042756u,
0x0c042758u,0x0c04275au,0x0c04275cu,0x0c04275eu,0x0c042760u,0x0c042762u,0x0c042764u,0x0c042766u,0x0c042768u,0x0c04276au,0x0c04276cu,0x0c04276eu,0x0c042770u,0x0c042772u,0x0c042774u,0x0c042776u,
0x0c042778u,0x0c04277au,0x0c04277cu,0x0c04277eu,0x0c042780u,0x0c042782u,0x0c042784u,0x0c042786u,0x0c042790u,0x0c042792u,0x0c042794u,0x0c042796u,0x0c042798u,0x0c04279au,0x0c04279cu,0x0c04279eu,
0x0c0427a0u,0x0c0427a2u,0x0c0427b0u,0x0c0427b2u,0x0c0427b4u,0x0c0427b6u,0x0c0427b8u,0x0c0427bau,0x0c0427bcu,0x0c0427beu,0x0c0427c0u,0x0c0427c2u,0x0c0427c4u,0x0c0427c6u,0x0c0427c8u,0x0c0427d0u,
0x0c0427d2u,0x0c0427d4u,0x0c0427d6u,0x0c0427e0u,0x0c0427e2u,0x0c0427e4u,0x0c0427e6u,0x0c0427e8u,0x0c0427eau,0x0c0427ecu,0x0c0427eeu,0x0c0427f0u,0x0c042800u,0x0c042802u,0x0c042804u,0x0c042806u,
0x0c042810u,0x0c042812u,0x0c042814u,0x0c042816u,0x0c042818u,0x0c04281au,0x0c04281cu,0x0c04281eu,0x0c042820u,0x0c042822u,0x0c042824u,0x0c042840u,0x0c042842u,0x0c042844u,0x0c042846u,0x0c042848u,
0x0c04284au,0x0c04284cu,0x0c04284eu,0x0c042850u,0x0c042852u,0x0c042854u,0x0c042856u,0x0c042858u,0x0c04285au,0x0c04285cu,0x0c04285eu,0x0c042860u,0x0c042862u,0x0c042864u,0x0c042866u,0x0c042868u,
0x0c04286au,0x0c04286cu,0x0c04286eu,0x0c042870u,0x0c042872u,0x0c042874u,0x0c042876u,0x0c042878u,0x0c04287au,0x0c04287cu,0x0c042880u,0x0c042882u,0x0c042884u,0x0c042886u,0x0c042888u,0x0c04288au,
0x0c04288cu,0x0c04288eu,0x0c042890u,0x0c042892u,0x0c042894u,0x0c042896u,0x0c042898u,0x0c04289au,0x0c04289cu,0x0c04289eu,0x0c0428a0u,0x0c0428a2u,0x0c0428a4u,0x0c0428a6u,0x0c0428a8u,0x0c0428aau,
0x0c0428acu,0x0c0428aeu,0x0c0428b0u,0x0c0428b2u,0x0c0428b4u,0x0c0428b6u,0x0c0428b8u,0x0c0428bau,0x0c0428bcu,0x0c0428beu,0x0c0428c0u,0x0c0428d0u,0x0c0428d2u,0x0c0428d4u,0x0c0428d6u,0x0c0428d8u,
0x0c0428dau,0x0c0428dcu,0x0c0428deu,0x0c0428e0u,0x0c0428e2u,0x0c0428e4u,0x0c0428e6u,0x0c0428e8u,0x0c0428eau,0x0c0428ecu,0x0c0428eeu,0x0c0428f0u,0x0c0428f2u,0x0c042900u,0x0c042902u,0x0c042904u,
0x0c042906u,0x0c042908u,0x0c04290au,0x0c04290cu,0x0c04290eu,0x0c042910u,0x0c042912u,0x0c042914u,0x0c042930u,0x0c042932u,0x0c042934u,0x0c042936u,0x0c042938u,0x0c04293au,0x0c04293cu,0x0c04293eu,
0x0c042940u,0x0c042942u,0x0c042944u,0x0c042946u,0x0c042948u,0x0c04294au,0x0c042960u,0x0c042962u,0x0c042964u,0x0c042970u,0x0c042972u,0x0c042974u,0x0c0429b0u,0x0c0429b2u,0x0c0429b4u,0x0c0429b6u,
0x0c0429b8u,0x0c0429bau,0x0c0429bcu,0x0c0429beu,0x0c0429c0u,0x0c0429c2u,0x0c0429c4u,0x0c0429c6u,0x0c0429c8u,0x0c0429cau,0x0c0429ccu,0x0c0429ceu,0x0c0429d0u,0x0c0429d2u,0x0c0429d4u,0x0c0429d6u,
0x0c0429d8u,0x0c0429dau,0x0c0429dcu,0x0c0429deu,0x0c0429e0u,0x0c0429e2u,0x0c0429e4u,0x0c0429e6u,0x0c0429e8u,0x0c0429eau,0x0c0429ecu,0x0c0429eeu,0x0c0429f0u,0x0c0429f2u,0x0c0429f4u,0x0c0429f6u,
0x0c0429f8u,0x0c0429fau,0x0c0429fcu,0x0c0429feu,0x0c042a00u,0x0c042a02u,0x0c042a04u,0x0c042a06u,0x0c042a08u,0x0c042a0au,0x0c042a0cu,0x0c042a0eu,0x0c042a10u,0x0c042a12u,0x0c042a14u,0x0c042a16u,
0x0c042a18u,0x0c042a1au,0x0c042a1cu,0x0c042a1eu,0x0c042a20u,0x0c042a22u,0x0c042a24u,0x0c042a26u,0x0c042a28u,0x0c042a2au,0x0c042a2cu,0x0c042a2eu,0x0c042a30u,0x0c042a32u,0x0c042a34u,0x0c042a36u,
0x0c042a38u,0x0c042a3au,0x0c042a3cu,0x0c042a3eu,0x0c042ae0u,0x0c042ae2u,0x0c042ae4u,0x0c042ae6u,0x0c042ae8u,0x0c042aeau,0x0c042aecu,0x0c042aeeu,0x0c042af0u,0x0c042af2u,0x0c042af4u,0x0c042af6u,
0x0c042af8u,0x0c042afau,0x0c042afcu,0x0c042afeu,0x0c042b00u,0x0c042b02u,0x0c042b04u,0x0c042b06u,0x0c042b10u,0x0c042b12u,0x0c042b14u,0x0c042b16u,0x0c042b18u,0x0c042b1au,0x0c042b1cu,0x0c042b1eu,
0x0c042b20u,0x0c042b22u,0x0c042b24u,0x0c042b26u,0x0c042b30u,0x0c042b32u,0x0c042b34u,0x0c042b36u,0x0c042b38u,0x0c042b3au,0x0c042b40u,0x0c042b42u,0x0c042b44u,0x0c042b46u,0x0c042b48u,0x0c042b4au,
0x0c042b4cu,0x0c042b4eu,0x0c042b50u,0x0c042b52u,0x0c042b54u,0x0c042b56u,0x0c042b58u,0x0c042b5au,0x0c042b5cu,0x0c042b5eu,0x0c042b60u,0x0c042b62u,0x0c042b64u,0x0c042b70u,0x0c042b72u,0x0c042b74u,
0x0c042b76u,0x0c042b78u,0x0c042b7au,0x0c042b7cu,0x0c042b7eu,0x0c042b80u,0x0c042b82u,0x0c042b84u,0x0c042b86u,0x0c042b88u,0x0c042b8au,0x0c042b8cu,0x0c042bb0u,0x0c042bb2u,0x0c042bb4u,0x0c042bb6u,
0x0c042bb8u,0x0c042bbau,0x0c042bbcu,0x0c042bbeu,0x0c042bc0u,0x0c042bc2u,0x0c042bc4u,0x0c042bc6u,0x0c042bc8u,0x0c042bcau,0x0c042bccu,0x0c042bceu,0x0c042bd0u,0x0c042be0u,0x0c042be2u,0x0c042be4u,
0x0c042be6u,0x0c042be8u,0x0c042beau,0x0c042becu,0x0c042beeu,0x0c042bf0u,0x0c042bf2u,0x0c042bf4u,0x0c042bf6u,0x0c042bf8u,0x0c042bfau,0x0c042c00u,0x0c042c02u,0x0c042c04u,0x0c0475aau,0x0c0475acu,
0x0c07fca4u,0x0c07fca6u,0x0c07fca8u,0x0c07fcaau,0x0c07fcacu,0x0c07fcaeu,0x0c07fcb0u,0x0c07fcb2u,0x0c07fcb4u,0x0c07fcb6u,0x0c07fcb8u,0x0c07fcbau,0x0c07fcbcu,0x0c07fcbeu,0x0c07fcc0u,0x0c07fcc2u,
0x0c07fcc4u,0x0c07fcc6u,0x0c07fcc8u,0x0c0858f2u,0x0c0858f4u,0x0c0858f6u,0x0c0858f8u,0x0c0858fau,0x0c0858fcu,0x0c0858feu,0x0c085900u,0x0c085902u,0x0c085904u,0x0c085906u,0x0c085908u,0x0c08590au,
0x0c08590cu,0x0c08590eu,0x0c085910u,0x0c085912u,0x0c085914u,0x0c085916u,0x0c085918u,0x0c08591au,0x0c08591cu,0x0c08591eu,0x0c085920u,0x0c085922u,0x0c085924u,0x0c085926u,0x0c085928u,0x0c08592au,
0x0c08592cu,0x0c08592eu,0x0c085930u,0x0c085932u,0x0c085934u,0x0c085936u,0x0c085938u,0x0c08593au,0x0c08593cu,0x0c08593eu,0x0c085940u,0x0c085942u,0x0c085944u,0x0c085946u,0x0c085948u,0x0c08594au,
0x0c08594cu,0x0c08594eu,0x0c085950u,0x0c085952u,0x0c085954u,0x0c085956u,0x0c085958u,0x0c08595au,0x0c08595cu,0x0c08595eu,0x0c085960u,0x0c085962u,0x0c085964u,0x0c085966u,0x0c085968u,0x0c08596au,
0x0c08596cu,0x0c08596eu,0x0c085970u,0x0c085972u,0x0c085974u,0x0c085976u,0x0c085978u,0x0c08597au,0x0c08597cu,0x0c08597eu,0x0c085980u,0x0c085982u,0x0c085984u,0x0c085986u,0x0c085988u,0x0c08598au,
0x0c08598cu,0x0c08598eu,0x0c085990u,0x0c085992u,0x0c085994u,0x0c085996u,0x0c085998u,0x0c08599au,0x0c08599cu,0x0c08599eu,0x0c0859a0u,0x0c0859a2u,0x0c0859a4u,0x0c0859a6u,0x0c0859a8u,0x0c0859aau,
0x0c0859acu,0x0c0859aeu,0x0c0859b0u,0x0c0859b2u,0x0c0859b4u,0x0c0859b6u,0x0c0859b8u,0x0c0859bau,0x0c0859bcu,0x0c0859beu,0x0c0859c0u,0x0c0859c2u,0x0c0859c4u,0x0c0859c6u,0x0c0859c8u,0x0c0859cau,
0x0c0859ccu,0x0c0859ceu,0x0c0859d0u,0x0c0859d2u,0x0c08a076u,0x0c08a078u,0x0c08a07au,0x0c08a07cu,0x0c08a07eu,0x0c08a080u,0x0c08a082u,0x0c08a084u,0x0c08a086u,0x0c08a088u,0x0c08a08au,0x0c08a08cu,
0x0c08a08eu,0x0c08a090u,0x0c08a092u,0x0c08a094u,0x0c08a096u,0x0c08a098u,0x0c08a09au,0x0c08a09cu,0x0c08a09eu,0x0c08a0a0u,0x0c08a0a2u,0x0c08a0a4u,0x0c08a0a6u,0x0c08a0a8u,0x0c08a0aau,0x0c08a0acu,
0x0c08a0aeu,0x0c08a0b0u,0x0c08a0b2u,0x0c08a0b4u,0x0c08a0b6u,0x0c08a0b8u,0x0c08a0bau,0x0c08a0bcu,0x0c08a0beu,0x0c08a0c0u,0x0c08a0c2u,0x0c08a0c4u,0x0c08a0c6u,0x0c08a0c8u,0x0c08a0cau,0x0c08a0ccu,
0x0c08a0ceu,0x0c08a0d0u,0x0c08a0d2u,0x0c08a0d4u,0x0c08a0d6u,0x0c08a0d8u,0x0c08a0dau,0x0c08a0dcu,0x0c08a0deu,0x0c08a0e0u,0x0c08a0e2u,0x0c08a0e4u,0x0c08a0e6u,0x0c08a0e8u,0x0c08a0eau,0x0c08a0ecu,
0x0c08a0eeu,0x0c08a0f0u,0x0c08a0f2u,0x0c08a0f4u,0x0c08a0f6u,0x0c08a0f8u,0x0c08a0fau,0x0c08a0fcu,0x0c08a0feu,0x0c08a100u,0x0c08a102u,0x0c08a104u,0x0c08a106u,0x0c08a108u,0x0c08a10au,0x0c08a10cu,
0x0c08a10eu,0x0c08a110u,0x0c08a112u,0x0c08a114u,0x0c08a116u,0x0c08a118u,0x0c08a11au,0x0c08a11cu,0x0c08a11eu,0x0c08a120u,0x0c08a122u,0x0c08a124u,0x0c08a126u,0x0c08a128u,0x0c08a12au,0x0c08a12cu,
0x0c08a12eu,0x0c08a130u,0x0c08a132u,0x0c08a134u,0x0c08a136u,0x0c08a138u,0x0c08a13au,0x0c08a13cu,0x0c08a13eu,0x0c08a140u,0x0c08a142u,0x0c08a144u,0x0c08a146u,0x0c08a148u,0x0c08a14au,0x0c08a14cu,
0x0c08a14eu,0x0c08a150u,0x0c08a152u,0x0c08a154u,0x0c08a156u,0x0c08a158u,0x0c08a15au,0x0c08a15cu,0x0c08a15eu,0x0c08a160u,0x0c08a162u,0x0c08a164u,0x0c08a166u,0x0c08a168u,0x0c08a16au,0x0c08a16cu,
0x0c08a16eu,0x0c08a170u,0x0c08a172u,0x0c08a174u,0x0c08a176u,0x0c08a178u,0x0c08a17au,0x0c08a17cu,0x0c08a17eu,0x0c08a180u,0x0c08a182u,0x0c08a184u,0x0c08a186u,0x0c08a188u,0x0c08a18au,0x0c08a18cu,
0x0c08a18eu,0x0c08a190u,0x0c08a192u,0x0c08a194u,0x0c08a196u,0x0c08a198u,0x0c08a19au,0x0c08a19cu,0x0c08a19eu,0x0c08a1a0u,0x0c08a1a2u,0x0c08a1a4u,0x0c08a1a6u,0x0c08a1a8u,0x0c08a1aau,0x0c08a1acu,
0x0c08a1aeu,0x0c08a1b0u,0x0c08a1b2u,0x0c08a1b4u,0x0c08a1b6u,0x0c08a1b8u,0x0c08a1bau,0x0c08a1bcu,0x0c08a1beu,0x0c08a1c0u,0x0c08a1c2u,0x0c08a1c4u,0x0c08a1c6u,0x0c08a1c8u,0x0c08a1cau,0x0c08a1ccu,
0x0c08a1ceu,0x0c08a1d0u,0x0c08a1d2u,0x0c08a1d4u,0x0c08a1d6u,0x0c08a1d8u,0x0c08a1dau,0x0c08a1dcu,0x0c08a23cu,0x0c08a23eu,0x0c08a240u,0x0c08a242u,0x0c08a244u,0x0c08a246u,0x0c08a248u,0x0c08a24au,
0x0c08a24cu,0x0c08a24eu,0x0c08a250u,0x0c08a252u,0x0c08a254u,0x0c08a256u,0x0c08a258u,0x0c08a25au,0x0c08a25cu,0x0c08a25eu,0x0c08a260u,0x0c08a262u,0x0c08a264u,0x0c08a266u,0x0c08a268u,0x0c08a26au,
0x0c08a26cu,0x0c08a26eu,0x0c08a270u,0x0c08a272u,0x0c08a274u,0x0c08a276u,0x0c08a278u,0x0c08a27au,0x0c08a27cu,0x0c08a27eu,0x0c08a280u,0x0c08a282u,0x0c08a284u,0x0c08a286u,0x0c08a288u,0x0c08a28au,
0x0c08a28cu,0x0c08a28eu,0x0c08a290u,0x0c08a292u,0x0c08a294u,0x0c08a296u,0x0c08a298u,0x0c08a29au,0x0c08a29cu,0x0c08a29eu,0x0c08a2a0u,0x0c08a2a2u,0x0c08a2a4u,0x0c08a2a6u,0x0c08a2a8u,0x0c08a2aau,
0x0c08a2acu,0x0c08a2aeu,0x0c08a2b0u,0x0c08a2b2u,0x0c08a2b4u,0x0c08a2b6u,0x0c08a2b8u,0x0c08a2bau,0x0c08a2bcu,0x0c08a2beu,0x0c08a2c0u,0x0c08a2c2u,0x0c08a2c4u,0x0c08a2c6u,0x0c08a2c8u,0x0c08a2cau,
0x0c08c90eu,0x0c08c910u,0x0c08c912u,0x0c08c914u,0x0c08c916u,0x0c08c918u,0x0c08c91au,0x0c08c91cu,0x0c08c91eu,0x0c08c920u,0x0c08c922u,0x0c08c924u,0x0c08c926u,0x0c08c928u,0x0c08c92au,0x0c08c92cu,
0x0c08c92eu,0x0c08c930u,0x0c08c932u,0x0c08c934u,0x0c08c936u,0x0c08c938u,0x0c08c93au,0x0c08c93cu,0x0c08c93eu,0x0c08c940u,0x0c08c942u,0x0c08c944u,0x0c08c946u,0x0c08c948u,0x0c08c94au,0x0c08c94cu,
0x0c08c94eu,0x0c08c950u,0x0c08c952u,0x0c08c954u,0x0c08c956u,0x0c08c958u,0x0c08c95au,0x0c08c95cu,0x0c08c95eu,0x0c08c960u,0x0c08c962u,0x0c08c964u,0x0c08c966u,0x0c08c968u,0x0c08c96au,0x0c08c96cu,
0x0c08c96eu,0x0c08c970u,0x0c08c972u,0x0c08c974u,0x0c08c976u,0x0c09b69eu,0x0c09b6a0u,0x0c09b6a2u,0x0c09b6a4u,0x0c09b6a6u,0x0c09b6a8u,0x0c09b6aau,0x0c09b6acu,0x0c09b6aeu,0x0c09b6b0u,0x0c09b6b2u,
0x0c09b6b4u,0x0c09b6b6u,0x0c09b6b8u,0x0c09b6bau,0x0c09b6bcu,0x0c09b6beu,0x0c09b6c0u,0x0c09b6c2u,0x0c09b6c4u,0x0c09b6c6u,0x0c09b6c8u,0x0c09b6cau,0x0c09b6ccu,0x0c09b6ceu,0x0c09b6d0u,0x0c09b6d2u,
0x0c09b6d4u,0x0c09b6d6u,0x0c09b6d8u,0x0c09b6dau,0x0c09b6dcu,0x0c09b6deu,0x0c09b6e0u,0x0c09b6e2u,0x0c09b6e4u,0x0c09b6e6u,0x0c09b6e8u,0x0c09b6eau,0x0c09b6ecu,0x0c09b6eeu,0x0c09b6f0u,0x0c09b6f2u,
0x0c09b6f4u,0x0c09b6f6u,0x0c09b6f8u,0x0c09b6fau,0x0c09b6fcu,0x0c09b6feu,0x0c09b700u,0x0c09b702u,0x0c09b704u,0x0c09b706u,0x0c09b708u,0x0c09b70au,0x0c09b70cu,0x0c09b70eu,0x0c09b710u,0x0c09b730u,
0x0c09b732u,0x0c09b734u,0x0c09b736u,0x0c09b738u,0x0c09b73au,0x0c09b73cu,0x0c09b73eu,0x0c09b740u,0x0c09b742u,0x0c09b744u,0x0c09b746u,0x0c09b748u,0x0c09b74au,0x0c09b74cu,0x0c09b74eu,0x0c09b750u,
0x0c09b752u,0x0c09b754u,0x0c09b756u,0x0c09b758u,0x0c09b75au,0x0c09b75cu,0x0c09b75eu,0x0c09b760u,0x0c09b762u,0x0c09b764u,0x0c09b766u,0x0c09b768u,0x0c09b76au,0x0c09b76cu,0x0c09b76eu,0x0c09b770u,
0x0c09b772u,0x0c09b774u,0x0c09b776u,0x0c09b778u,0x0c09b77au,0x0c09b77cu,0x0c09b77eu,0x0c09b780u,0x0c09b782u,0x0c09b784u,0x0c09b786u,0x0c09b788u,0x0c09b78au,0x0c09b78cu,0x0c09b78eu,0x0c09b790u,
0x0c09b792u,0x0c09b794u,0x0c09b796u,0x0c09b798u,0x0c09b79au,0x0c09b79cu,0x0c09b79eu,0x0c09b7b0u,0x0c09b7b2u,0x0c09b7b4u,0x0c09b7b6u,0x0c09b7b8u,0x0c09b7bau,0x0c09b7bcu,0x0c09b7beu,0x0c09b7c0u,
0x0c09b7c2u,0x0c09b7c4u,0x0c09b7c6u,0x0c09b7c8u,0x0c09b7cau,0x0c09b7ccu,0x0c09b7ceu,0x0c09b7d0u,0x0c09b7d2u,0x0c09b7d4u,0x0c09b7d6u,0x0c09b7d8u,0x0c09b7dau,0x0c09b7dcu,0x0c09b7deu,0x0c09b7e0u,
0x0c09b7e2u,0x0c09b7e4u,0x0c09b7e6u,0x0c09b7e8u,0x0c09b7eau,0x0c09b7ecu,0x0c09b7eeu,0x0c09b7f0u,0x0c09b7f2u,0x0c09b7f4u,0x0c09b7f6u,0x0c09b7f8u,0x0c09b7fau,0x0c09b7fcu,0x0c09b7feu,0x0c09b800u,
0x0c09b802u,0x0c09b804u,0x0c09b806u,0x0c09b808u,0x0c09b80au,0x0c09b80cu,0x0c09b80eu,0x0c09b810u,0x0c09b812u,0x0c09b814u,0x0c09b816u,0x0c09b818u,0x0c09b81au,0x0c09b81cu,0x0c09b81eu,0x0c09b820u,
0x0c09b822u,0x0c09b824u,0x0c09b826u,0x0c09b828u,0x0c09b82au,0x0c09b82cu,0x0c09b82eu,0x0c09b830u,0x0c09b832u,0x0c09b834u,0x0c09b836u,0x0c09b838u,0x0c09b83au,0x0c09b83cu,0x0c09b83eu,0x0c09b840u,
0x0c09b842u,0x0c09b844u,0x0c09b846u,0x0c09b848u,0x0c09b84au,0x0c09b84cu,0x0c09b84eu,0x0c09b850u,0x0c09b852u,0x0c09b854u,0x0c09b856u,0x0c09b858u,0x0c09b85au,0x0c09b85cu,0x0c09b85eu,0x0c09b860u,
0x0c09b862u,0x0c09b864u,0x0c09b866u,0x0c09b868u,0x0c09b86au,0x0c09b86cu,0x0c09b86eu,0x0c09b870u,0x0c09b872u,0x0c09b874u,0x0c09b876u,0x0c09b878u,0x0c09b87au,0x0c09b87cu,0x0c09b87eu,0x0c09b880u,
0x0c09b882u,0x0c09b884u,0x0c09b886u,0x0c09b888u,0x0c09b88au,0x0c09b88cu,0x0c09b88eu,0x0c09b8b8u,0x0c09b8bau,0x0c09b8bcu,0x0c09b8beu,0x0c09b8c0u,0x0c09b8c2u,0x0c09b8c4u,0x0c09b8c6u,0x0c09b8c8u,
0x0c09b8cau,0x0c09b8ccu,0x0c09b8ceu,0x0c09b8d0u,0x0c09b8d2u,0x0c09b8d4u,0x0c09b8d6u,0x0c09b8d8u,0x0c09b8dau,0x0c09b8dcu,0x0c09b8deu,0x0c09b8e0u,0x0c09b8e2u,0x0c09b8e4u,0x0c09b8e6u,0x0c09b8e8u,
0x0c09b8eau,0x0c09b8ecu,0x0c09b8eeu,0x0c09b8f0u,0x0c09b8f2u,0x0c09b8f4u,0x0c09b8f6u,0x0c09b8f8u,0x0c09b8fau,0x0c09b8fcu,0x0c09b8feu,0x0c09b900u,0x0c09b902u,0x0c09b904u,0x0c09b906u,0x0c09b908u,
0x0c09b90au,0x0c09b90cu,0x0c09b90eu,0x0c09b910u,0x0c09b912u,0x0c09b914u,0x0c09b916u,0x0c09b918u,0x0c09b91au,0x0c09b91cu,0x0c09b91eu,0x0c09b920u,0x0c09b922u,0x0c09ba8cu,0x0c09ba8eu,0x0c09ba90u,
0x0c09ba92u,0x0c09ba94u,0x0c09ba96u,0x0c09ba98u,0x0c09ba9au,0x0c09ba9cu,0x0c09ba9eu,0x0c09baa0u,0x0c09baa2u,0x0c09baa4u,0x0c09baa6u,0x0c09baa8u,0x0c09baaau,0x0c09baacu,0x0c09baaeu,0x0c09bab0u,
0x0c09bab2u,0x0c09bab4u,0x0c09bab6u,0x0c09bab8u,0x0c09babau,0x0c09babcu,0x0c09babeu,0x0c09bac0u,0x0c09bac2u,0x0c09bac4u,0x0c09bac6u,0x0c09bac8u,0x0c09bacau,0x0c09baccu,0x0c09baceu,0x0c09bad0u,
0x0c09bad2u,0x0c09bad4u,0x0c09bad6u,0x0c09bad8u,0x0c09badau,0x0c09badcu,0x0c09bc1cu,0x0c09bc1eu,0x0c09bc20u,0x0c09bc22u,0x0c09bc24u,0x0c09bc26u,0x0c09bc28u,0x0c09bc2au,0x0c09bc2cu,0x0c09bc2eu,
0x0c09bc30u,0x0c09bc32u,0x0c09bc34u,0x0c09bc36u,0x0c09bc38u,0x0c09bc3au,0x0c09bc3cu,0x0c09bc3eu,0x0c09bc40u,0x0c09bc42u,0x0c09bc44u,0x0c09bc46u,0x0c09bc48u,0x0c09bc4au,0x0c09bc4cu,0x0c09bc4eu,
0x0c09bc50u,0x0c09bc52u,0x0c09bc54u,0x0c09bc56u,0x0c09bc58u,0x0c09bc5au,0x0c09bc5cu,0x0c09bc5eu,0x0c09bc60u,0x0c09bc62u,0x0c09bc64u,0x0c09bc66u,0x0c09bc68u,0x0c09bc6au,0x0c09bc6cu,0x0c09bc6eu,
0x0c09bc70u,0x0c09bc72u,0x0c09bc74u,0x0c09bc76u,0x0c09bc78u,0x0c09bc7au,0x0c09bc7cu,0x0c09bc7eu,0x0c09bc80u,0x0c09bc82u,0x0c09bc84u,0x0c09bc86u,0x0c09bc88u,0x0c09bc8au,0x0c09bc8cu,0x0c09bc8eu,
0x0c09bc90u,0x0c09bc92u,0x0c09bc94u,0x0c09bc96u,0x0c09bc98u,0x0c09bc9au,0x0c09bc9cu,0x0c09bc9eu,0x0c09bca0u,0x0c09bca2u,0x0c09bca4u,0x0c09bca6u,0x0c09bca8u,0x0c09bcaau,0x0c09bcacu,0x0c09bcaeu,
0x0c09bcb0u,0x0c09bcb2u,0x0c09bcb4u,0x0c09bcb6u,0x0c09bcb8u,0x0c09bcbau,0x0c09bcbcu,0x0c09bcbeu,0x0c09bcc0u,0x0c09bcc2u,0x0c09bcc4u,0x0c09bcc6u,0x0c09bcc8u,0x0c09bccau,0x0c09bcccu,0x0c09bcceu,
0x0c09bcd0u,0x0c09bcd2u,0x0c09bcd4u,0x0c09bcd6u,0x0c09bcd8u,0x0c09bcdau,0x0c09bcdcu,0x0c09bcdeu,0x0c09bce0u,0x0c09bce2u,0x0c09bce4u,0x0c09bce6u,0x0c09bce8u,0x0c09bceau,0x0c09bcecu,0x0c09bceeu,
0x0c09bcf0u,0x0c09bcf2u,0x0c09bcf4u,0x0c09bcf6u,0x0c09bd0cu,0x0c09bd0eu,0x0c09bd10u,0x0c09bd12u,0x0c09bd14u,0x0c09bd16u,0x0c09bd18u,0x0c09bd1au,0x0c09bd1cu,0x0c09bd1eu,0x0c09bd20u,0x0c09bd22u,
0x0c09bd24u,0x0c09bd26u,0x0c09bd28u,0x0c09bd2au,0x0c09bd2cu,0x0c09bd2eu,0x0c09bd30u,0x0c09bd32u,0x0c09bd34u,0x0c09bd36u,0x0c09bd38u,0x0c09bd3au,0x0c09bd3cu,0x0c09bd3eu,0x0c09bd40u,0x0c09bd42u,
0x0c09bd44u,0x0c09bd46u,0x0c09bd48u,0x0c09bd4au,0x0c09bd4cu,0x0c09bd4eu,0x0c09bd50u,0x0c09bd52u,0x0c09bd54u,0x0c09bd56u,0x0c09bd58u,0x0c09bd5au,0x0c09bd5cu,0x0c09bd5eu,0x0c09bd60u,0x0c09bd62u,
0x0c09bd64u,0x0c09bd66u,0x0c09bd68u,0x0c09bd6au,0x0c09bd6cu,0x0c09bd6eu,0x0c09bd70u,0x0c09bd72u,0x0c09bd74u,0x0c09bd76u,0x0c09bd78u,0x0c09bd7au,0x0c09bd7cu,0x0c09bd7eu,0x0c09bd80u,0x0c09bd82u,
0x0c09bd84u,0x0c09bd86u,0x0c09bd88u,0x0c09bd8au,0x0c09bd8cu,0x0c09bd8eu,0x0c09bd90u,0x0c09bd92u,0x0c09bd94u,0x0c09bd96u,0x0c09bd98u,0x0c09bd9au,0x0c09bd9cu,0x0c09bd9eu,0x0c09bda0u,0x0c09bda2u,
0x0c09bda4u,0x0c09bda6u,0x0c09bda8u,0x0c09bdaau,0x0c09bdacu,0x0c09bdaeu,0x0c09bdb0u,0x0c09bdb2u,0x0c09bdb4u,0x0c09bdb6u,0x0c09bdb8u,0x0c09bdbau,0x0c09bdbcu,0x0c09bdbeu,0x0c09bdc0u,0x0c09bdc2u,
0x0c09bdc4u,0x0c09bdc6u,0x0c09bdc8u,0x0c09bdcau,0x0c09bdccu,0x0c09bdceu,0x0c09bddau,0x0c09bddcu,0x0c09bddeu,0x0c09bde0u,0x0c09bde2u,0x0c09bde4u,0x0c09bde6u,0x0c09bde8u,0x0c09bdeau,0x0c09bdecu,
0x0c09bdeeu,0x0c09bdf0u,0x0c09bdf2u,0x0c09bdf4u,0x0c09bdf6u,0x0c09bdf8u,0x0c09bdfau,0x0c09bdfcu,0x0c09bdfeu,0x0c09be00u,0x0c09be02u,0x0c09be04u,0x0c09be06u,0x0c09be08u,0x0c09be0au,0x0c09be0cu,
0x0c09be0eu,0x0c09be10u,0x0c09be12u,0x0c09be14u,0x0c09be16u,0x0c09be18u,0x0c09be1au,0x0c09be1cu,0x0c09be1eu,0x0c09be20u,0x0c09be22u,0x0c09be24u,0x0c09be26u,0x0c09be28u,0x0c09be2au,0x0c09be2cu,
0x0c09be2eu,0x0c09be30u,0x0c09be32u,0x0c09be34u,0x0c09be36u,0x0c09be38u,0x0c09be3au,0x0c09be3cu,0x0c09be3eu,0x0c09be40u,0x0c09be42u,0x0c09be44u,0x0c09be46u,0x0c09be48u,0x0c09be4au,0x0c09be4cu,
0x0c09be4eu,0x0c09be50u,0x0c09be52u,0x0c09be54u,0x0c09be56u,0x0c09be58u,0x0c09be5au,0x0c09be5cu,0x0c09be5eu,0x0c09be60u,0x0c09be62u,0x0c09be64u,0x0c09be66u,0x0c09be68u,0x0c09be6au,0x0c09be6cu,
0x0c09be6eu,0x0c09be70u,0x0c09be72u,0x0c09be74u,0x0c09be76u,0x0c09be78u,0x0c09be7au,0x0c09be7cu,0x0c09be7eu,0x0c09be80u,0x0c09be82u,0x0c09be84u,0x0c09be86u,0x0c09be88u,0x0c09be8au,0x0c09be8cu,
0x0c09be8eu,0x0c09be90u,0x0c09be92u,0x0c09be94u,0x0c09be96u,0x0c09be98u,0x0c09be9au,0x0c09be9cu,0x0c09be9eu,0x0c09bea0u,0x0c09bea2u,0x0c09bea4u,0x0c09bea6u,0x0c09bea8u,0x0c09beaau,0x0c09beacu,
0x0c09beaeu,0x0c09beb0u,0x0c09beb2u,0x0c09beb4u,0x0c09beb6u,0x0c09bed0u,0x0c09bed2u,0x0c09bed4u,0x0c09bed6u,0x0c09bed8u,0x0c09bedau,0x0c09bedcu,0x0c09bedeu,0x0c09bee0u,0x0c09bee2u,0x0c09bee4u,
0x0c09bee6u,0x0c09bee8u,0x0c09beeau,0x0c09beecu,0x0c09beeeu,0x0c09bef0u,0x0c09bef2u,0x0c09bef4u,0x0c09bef6u,0x0c09bef8u,0x0c09befau,0x0c09ca8eu,0x0c09ca90u,0x0c09ca92u,0x0c09ca94u,0x0c09ca96u,
0x0c09ca98u,0x0c09ca9au,0x0c09ca9cu,0x0c09ca9eu,0x0c09caa0u,0x0c09caa2u,0x0c09caa4u,0x0c09caa6u,0x0c09caa8u,0x0c09caaau,0x0c09caacu,0x0c09caaeu,0x0c09cab0u,0x0c09cab2u,0x0c09cab4u,0x0c09cab6u,
0x0c09cab8u,0x0c09cabau,0x0c09cabcu,0x0c09cabeu,0x0c09cac0u,0x0c09cac2u,0x0c09cac4u,0x0c09cac6u,0x0c09cac8u,0x0c09cacau,0x0c09caccu,0x0c09caceu,0x0c09cad0u,0x0c09cad2u,0x0c09cad4u,0x0c09cad6u,
0x0c09cad8u,0x0c09cadau,0x0c09cadcu,0x0c09cadeu,0x0c09cae0u,0x0c09cae2u,0x0c09cae4u,0x0c09cae6u,0x0c09cae8u,0x0c09caeau,0x0c09caecu,0x0c09caeeu,0x0c09caf0u,0x0c09caf2u,0x0c09caf4u,0x0c09caf6u,
0x0c09caf8u,0x0c09cafau,0x0c09cafcu,0x0c09cafeu,0x0c09cb00u,0x0c09cb02u,0x0c09cb04u,0x0c09cb06u,0x0c09cb08u,0x0c09cb0au,0x0c09cb0cu,0x0c09cb0eu,0x0c09cb10u,0x0c09cb12u,0x0c09cb14u,0x0c09cb16u,
0x0c09cb18u,0x0c09cb1au,0x0c09cb1cu,0x0c09cb1eu,0x0c09cb20u,0x0c09cb22u,0x0c09cb24u,0x0c09cb26u,0x0c09cb28u,0x0c09cb2au,0x0c09cb2cu,0x0c09cb2eu,0x0c09cb30u,0x0c09cb32u,0x0c09cb34u,0x0c09cb36u,
0x0c09cb38u,0x0c09cb50u,0x0c09cb52u,0x0c09cb54u,0x0c09cb56u,0x0c09cb58u,0x0c09cb5au,0x0c09cb5cu,0x0c09cb5eu,0x0c09cb60u,0x0c09cb62u,0x0c09cb64u,0x0c09cb66u,0x0c09cb68u,0x0c09cb6au,0x0c09cb6cu,
0x0c09cb6eu,0x0c09cb70u,0x0c09cb72u,0x0c09cb74u,0x0c09cb76u,0x0c09cb78u,0x0c09cb7au,0x0c09cb7cu,0x0c09cb7eu,0x0c09cb80u,0x0c09cb82u,0x0c09cb84u,0x0c09cb86u,0x0c09cb88u,0x0c09cb8au,0x0c09cb8cu,
0x0c09cb8eu,0x0c09cb90u,0x0c09cb92u,0x0c09cb94u,0x0c09cb96u,0x0c09cb98u,0x0c09cb9au,0x0c09cb9cu,0x0c09cb9eu,0x0c09cba0u,0x0c09cba2u,0x0c09cba4u,0x0c09cba6u,0x0c09cba8u,0x0c09cbaau,0x0c09cbacu,
0x0c09cbaeu,0x0c09cbb0u,0x0c09cbb2u,0x0c09cbb4u,0x0c09cbb6u,0x0c09cbb8u,0x0c09cbbau,0x0c09cbbcu,0x0c09cbbeu,0x0c09cbc0u,0x0c09cbc2u,0x0c09cbc4u,0x0c09cbc6u,0x0c09cbc8u,0x0c09cbcau,0x0c09cbccu,
0x0c09cbceu,0x0c09cbd0u,0x0c09cbd2u,0x0c09cbd4u,0x0c09cbd6u,0x0c09cbd8u,0x0c09cbdau,0x0c09cbdcu,0x0c09cbdeu,0x0c09cbe0u,0x0c09cbe2u,0x0c09cbe4u,0x0c09cbe6u,0x0c09cbe8u,0x0c09cbeau,0x0c09cbecu,
0x0c09cbeeu,0x0c09cbf0u,0x0c09cbf2u,0x0c09cbf4u,0x0c09cbf6u,0x0c09cbf8u,0x0c09cbfau,0x0c09cbfcu,0x0c09cbfeu,0x0c09cc00u,0x0c09cc02u,0x0c09cc04u,0x0c09cc06u,0x0c09cc08u,0x0c09cc0au,0x0c09cc0cu,
0x0c09cc0eu,0x0c09cc10u,0x0c09cc12u,0x0c09cc14u,0x0c09cc16u,0x0c09cc18u,0x0c09cc1au,0x0c09cc1cu,0x0c09cc1eu,0x0c09cc30u,0x0c09cc32u,0x0c09cc34u,0x0c09cc36u,0x0c09cc38u,0x0c09cc3au,0x0c09cc3cu,
0x0c09cc3eu,0x0c09cc40u,0x0c09cc42u,0x0c09cc44u,0x0c09cc46u,0x0c09cc48u,0x0c09cc4au,0x0c09cc4cu,0x0c09cc4eu,0x0c09cc50u,0x0c09cc52u,0x0c09cc54u,0x0c09cc56u,0x0c09cc58u,0x0c09cc5au,0x0c09cc5cu,
0x0c09cc5eu,0x0c09cc60u,0x0c09cc62u,0x0c09cc64u,0x0c09cc66u,0x0c09cc68u,0x0c09cc6au,0x0c09cc6cu,0x0c09cc6eu,0x0c09cc70u,0x0c09cc72u,0x0c09cc74u,0x0c09cc76u,0x0c09cc78u,0x0c09cc7au,0x0c09cc7cu,
0x0c09cc7eu,0x0c09cc80u,0x0c09cc82u,0x0c09cc84u,0x0c09cc86u,0x0c09cc88u,0x0c09cc8au,0x0c09cc8cu,0x0c09cc8eu,0x0c09cc90u,0x0c09cc92u,0x0c09cc94u,0x0c09cc96u,0x0c09cc98u,0x0c09cc9au,0x0c09cc9cu,
0x0c09cc9eu,0x0c09cca0u,0x0c09cca2u,0x0c09cca4u,0x0c09cca6u,0x0c09cca8u,0x0c09ccaau,0x0c09ccacu,0x0c09ccaeu,0x0c09ccb0u,0x0c09ccb2u,0x0c09ccb4u,0x0c09ccb6u,0x0c09ccb8u,0x0c09ccbau,0x0c09ccbcu,
0x0c09ccbeu,0x0c09ccc0u,0x0c09ccc2u,0x0c09ccc4u,0x0c09ccc6u,0x0c09ccc8u,0x0c09cccau,0x0c09ccccu,0x0c09ccceu,0x0c09ccd0u,0x0c09ccd2u,0x0c09ccd4u,0x0c09ccd6u,0x0c09ccd8u,0x0c09ccdau,0x0c09ccdcu,
0x0c09ccdeu,0x0c09cce0u,0x0c09cce2u,0x0c09cce4u,0x0c09cce6u,0x0c09cce8u,0x0c09cceau,0x0c09ccecu,0x0c09cceeu,0x0c09ccf0u,0x0c09ccf2u,0x0c09ccf4u,0x0c09ccf6u,0x0c09ccf8u,0x0c09ccfau,0x0c09ccfcu,
0x0c09ccfeu,0x0c09cd00u,0x0c09cd02u,0x0c09cd04u,0x0c09cd06u,0x0c09cd08u,0x0c09cd0au,0x0c09cd0cu,0x0c09cd0eu,0x0c09cd10u,0x0c09cd12u,0x0c09cd38u,0x0c09cd3au,0x0c09cd3cu,0x0c09cd3eu,0x0c09cd40u,
0x0c09cd42u,0x0c09cd44u,0x0c09cd46u,0x0c09cd48u,0x0c09cd4au,0x0c09cd4cu,0x0c09cd4eu,0x0c09cd50u,0x0c09cd52u,0x0c09cd54u,0x0c09cd56u,0x0c09cd58u,0x0c09cd5au,0x0c09cd5cu,0x0c09cd5eu,0x0c09cd60u,
0x0c09cd62u,0x0c09cd64u,0x0c09cd66u,0x0c09cd68u,0x0c09cd6au,0x0c09cd6cu,0x0c09cd6eu,0x0c09cd70u,0x0c09cd72u,0x0c09cd74u,0x0c09cd76u,0x0c09cd78u,0x0c09cd7au,0x0c09cd7cu,0x0c09cd7eu,0x0c09cd80u,
0x0c09cd82u,0x0c09cd84u,0x0c09cd86u,0x0c09cd88u,0x0c09cd8au,0x0c09cd8cu,0x0c09cd8eu,0x0c09cd90u,0x0c09cd92u,0x0c09cd94u,0x0c09cd96u,0x0c09cd98u,0x0c09cd9au,0x0c09cd9cu,0x0c09cd9eu,0x0c09cda0u,
0x0c09cda2u,0x0c09cda4u,0x0c09cda6u,0x0c09cda8u,0x0c09cdaau,0x0c09cdacu,0x0c09cdaeu,0x0c09cdb0u,0x0c09cdb2u,0x0c09cdb4u,0x0c09cdb6u,0x0c09cdb8u,0x0c09cdbau,0x0c09cdbcu,0x0c09cdbeu,0x0c09cdc0u,
0x0c09cdecu,0x0c09cdeeu,0x0c09cdf0u,0x0c09cdf2u,0x0c09cdf4u,0x0c09cdf6u,0x0c09cdf8u,0x0c09cdfau,0x0c09cdfcu,0x0c09cdfeu,0x0c09ce00u,0x0c09ce02u,0x0c09ce04u,0x0c09ce06u,0x0c09ce08u,0x0c09ce0au,
0x0c09ce0cu,0x0c09ce0eu,0x0c09ce10u,0x0c09ce12u,0x0c09ce14u,0x0c09ce16u,0x0c09ce18u,0x0c09ce1au,0x0c09ce1cu,0x0c09ce1eu,0x0c09ce20u,0x0c09ce22u,0x0c09ce24u,0x0c09ce26u,0x0c09ce28u,0x0c09ce2au,
0x0c09ce2cu,0x0c09ce2eu,0x0c09ce30u,0x0c09ce32u,0x0c09ce34u,0x0c09ce36u,0x0c09ce38u,0x0c09ce3au,0x0c09ce3cu,0x0c09ce3eu,0x0c09ce40u,0x0c09ce42u,0x0c09ce44u,0x0c09ce46u,0x0c09ce48u,0x0c0a1f50u,
0x0c0a1f52u,0x0c0a1f54u,0x0c0a1f56u,0x0c0a1f58u,0x0c0a1f5au,0x0c0a1f5cu,0x0c0a1f5eu,0x0c0a1f60u,0x0c0a1f62u,0x0c0a1f64u,0x0c0a1f66u,0x0c0a1f68u,0x0c0a1f6au,0x0c0a1f6cu,0x0c0a1f6eu,0x0c0a1f70u,
0x0c0a1f72u,0x0c0a1f74u,0x0c0a1f76u,0x0c0a1f78u,0x0c0a1f7au,0x0c0a1f7cu,0x0c0a1f7eu,0x0c0a1f80u,0x0c0a1f82u,0x0c0a1f84u,0x0c0a1f86u,0x0c0a1f88u,0x0c0a1f8au,0x0c0a1f8cu,0x0c0a1f8eu,0x0c0a1f90u,
0x0c0a1f92u,0x0c0a1f94u,0x0c0a1f96u,0x0c0a1f98u,0x0c0a1f9au,0x0c0a1f9cu,0x0c0a1f9eu,0x0c0a1fa0u,0x0c0a1fa2u,0x0c0a1fa4u,0x0c0a1fa6u,0x0c0a1fa8u,0x0c0a1faau,0x0c0a1facu,0x0c0a1faeu,0x0c0a1fb0u,
0x0c0a1fb2u,0x0c0a1fb4u,0x0c0a1fb6u,0x0c0a1fb8u,0x0c0a1fbau,0x0c0a1fbcu,0x0c0a1fbeu,0x0c0a1fc0u,0x0c0a1fc2u,0x0c0a1fc4u,0x0c0a1fc6u,0x0c0a1fc8u,0x0c0a1fcau,0x0c0a1fccu,0x0c0a1fceu,0x0c0a1fd0u,
0x0c0a1fd2u,0x0c0a1fd4u,0x0c0a1fd6u,0x0c0a1fd8u,0x0c0a1fdau,0x0c0a1fdcu,0x0c0a1fdeu,0x0c0a1fe0u,0x0c0a1fe2u,0x0c0a1fe4u,0x0c0a1fe6u,0x0c0a1fe8u,0x0c0a1feau,0x0c0a1fecu,0x0c0a1feeu,0x0c0a1ff0u,
0x0c0a1ff2u,0x0c0a1ff4u,0x0c0a22c4u,0x0c0a22c6u,0x0c0a22c8u,0x0c0a22cau,0x0c0a22ccu,0x0c0a22ceu,0x0c0a22d0u,0x0c0a22d2u,0x0c0a22d4u,0x0c0a22d6u,0x0c0a22d8u,0x0c0a22dau,0x0c0a22dcu,0x0c0a22deu,
0x0c0a22e0u,0x0c0a22e2u,0x0c0a22e4u,0x0c0a22e6u,0x0c0a22e8u,0x0c0a22eau,0x0c0a22ecu,0x0c0a22eeu,0x0c0a22f0u,0x0c0a22f2u,0x0c0a22f4u,0x0c0a22f6u,0x0c0a22f8u,0x0c0a22fau,0x0c0a22fcu,0x0c0a22feu,
0x0c0a2300u,0x0c0a2302u,0x0c0a2304u,0x0c0a2306u,0x0c0a2308u,0x0c0a230au,0x0c0a230cu,0x0c0a230eu,0x0c0a2310u,0x0c0a2312u,0x0c0a2314u,0x0c0a2316u,0x0c0a2318u,0x0c0a231au,0x0c0a231cu,0x0c0a231eu,
0x0c0a2320u,0x0c0a2322u,0x0c0a2324u,0x0c0a2326u,0x0c0a2328u,0x0c0a232au,0x0c0a232cu,0x0c0a232eu,0x0c0a2330u,0x0c0a2332u,0x0c0a2334u,0x0c0a2336u,0x0c0a2338u,0x0c0a233au,0x0c0a233cu,0x0c0a233eu,
0x0c0a2340u,0x0c0a2342u,0x0c0a2344u,0x0c0a2346u,0x0c0a2348u,0x0c0a234au,0x0c0a234cu,0x0c0a234eu,0x0c0a2350u,0x0c0a2352u,0x0c0a2354u,0x0c0a2356u,0x0c0a2358u,0x0c0a235au,0x0c0a235cu,0x0c0a235eu,
0x0c0a2360u,0x0c0a2362u,0x0c0a2364u,0x0c0a2366u,0x0c0a2368u,0x0c0a236au,0x0c0a236cu,0x0c0a236eu,0x0c0a2370u,0x0c0a2372u,0x0c0a2374u,0x0c0a2376u,0x0c0a2378u,0x0c0a237au,0x0c0a237cu,0x0c0a237eu,
0x0c0a2380u,0x0c0a2382u,0x0c0a2384u,0x0c0a2386u,0x0c0a2388u,0x0c0a238au,0x0c0a238cu,0x0c0a238eu,0x0c0a2390u,0x0c0a2392u,0x0c0a2394u,0x0c0a2396u,0x0c0a2398u,0x0c0a239au,0x0c0a239cu,0x0c0a239eu,
0x0c0a23a0u,0x0c0a23a2u,0x0c0a23a4u,0x0c0a23a6u,0x0c0a23a8u,0x0c0a23aau,0x0c0a23acu,0x0c0a23aeu,0x0c0a23b0u,0x0c0a23b2u,0x0c0a23b4u,0x0c0a23b6u,0x0c0a23b8u,0x0c0a23bau,0x0c0a23bcu,0x0c0a240cu,
0x0c0a240eu,0x0c0a2410u,0x0c0a2412u,0x0c0a2414u,0x0c0a2416u,0x0c0a2418u,0x0c0a241au,0x0c0a241cu,0x0c0a241eu,0x0c0a2420u,0x0c0a2422u,0x0c0a2424u,0x0c0a2426u,0x0c0a2428u,0x0c0a242au,0x0c0a242cu,
0x0c0a242eu,0x0c0a2430u,0x0c0a2432u,0x0c0a2434u,0x0c0a2436u,0x0c0a2438u,0x0c0a243au,0x0c0a243cu,0x0c0a243eu,0x0c0a2440u,0x0c0a2442u,0x0c0a2444u,0x0c0a2446u,0x0c0a2448u,0x0c0a244au,0x0c0a244cu,
0x0c0a244eu,0x0c0a2450u,0x0c0a2452u,0x0c0a2454u,0x0c0a2456u,0x0c0a2458u,0x0c0a245au,0x0c0a245cu,0x0c0a245eu,0x0c0a2460u,0x0c0a2462u,0x0c0a2464u,0x0c0a2466u,0x0c0a2468u,0x0c0a246au,0x0c0a246cu,
0x0c0a246eu,0x0c0a2470u,0x0c0a2472u,0x0c0a2474u,0x0c0a2476u,0x0c0a2478u,0x0c0a247au,0x0c0a247cu,0x0c0a247eu,0x0c0a2480u,0x0c0a2482u,0x0c0a2484u,0x0c0a2486u,0x0c0a2488u,0x0c0a248au,0x0c0a248cu,
0x0c0a248eu,0x0c0a2490u,0x0c0a2492u,0x0c0a2494u,0x0c0a2496u,0x0c0a2498u,0x0c0a249au,0x0c0a249cu,0x0c0a249eu,0x0c0a24a0u,0x0c0a24a2u,0x0c0a24a4u,0x0c0a6494u,0x0c0a6496u,0x0c0a6498u,0x0c0a649au,
0x0c0a649cu,0x0c0a649eu,0x0c0a64a0u,0x0c0a64a2u,0x0c0a64a4u,0x0c0a64a6u,0x0c0a64a8u,0x0c0a64aau,0x0c0a64acu,0x0c0a64aeu,0x0c0a64b0u,0x0c0a64b2u,0x0c0a64b4u,0x0c0a64b6u,0x0c0a64b8u,0x0c0a64bau,
0x0c0a64bcu,0x0c0a64beu,0x0c0a64c0u,0x0c0a64c2u,0x0c0a64c4u,0x0c0a64c6u,0x0c0a64c8u,0x0c0a64cau,0x0c0a64ccu,0x0c0a64ceu,0x0c0a64d0u,0x0c0a64d2u,0x0c0a64d4u,0x0c0a64d6u,0x0c0a64d8u,0x0c0a64dau,
0x0c0a64dcu,0x0c0a64deu,0x0c0a64e0u,0x0c0a64e2u,0x0c0a64e4u,0x0c0a64e6u,0x0c0a64e8u,0x0c0a64eau,0x0c0a64ecu,0x0c0a64eeu,0x0c0a64f0u,0x0c0a64f2u,0x0c0a64f4u,0x0c0a64f6u,0x0c0a64f8u,0x0c0a64fau,
0x0c0a64fcu,0x0c0a64feu,0x0c0a6500u,0x0c0a6502u,0x0c0a6504u,0x0c0a6506u,0x0c0a6508u,0x0c0a650au,0x0c0a650cu,0x0c0a650eu,0x0c0a6510u,0x0c0a6512u,0x0c0a6514u,0x0c0a6516u,0x0c0a6518u,0x0c0a651au,
0x0c0a651cu,0x0c0a651eu,0x0c0a6520u,0x0c0a6522u,0x0c0a6524u,0x0c0a6526u,0x0c0a6528u,0x0c0a652au,0x0c0a652cu,0x0c0a652eu,0x0c0a6530u,0x0c0a6532u,0x0c0a6534u,0x0c0a6536u,0x0c0a6538u,0x0c0a653au,
0x0c0a653cu,0x0c0a653eu,0x0c0a6540u,0x0c0a6542u,0x0c0a6544u,0x0c0a6546u,0x0c0a6548u,0x0c0a654au,0x0c0a654cu,0x0c0a654eu,0x0c0a6550u,0x0c0a6552u,0x0c0a6554u,0x0c0a6556u,0x0c0a6558u,0x0c0a655au,
0x0c0a655cu,0x0c0a655eu,0x0c0a6560u,0x0c0a6562u,0x0c0a6564u,0x0c0a6566u,0x0c0a6568u,0x0c0a656au,0x0c0a656cu,0x0c0a656eu,0x0c0a6570u,0x0c0a6572u,0x0c0a6574u,0x0c0a6576u,0x0c0a6578u,0x0c0a657au,
0x0c0a657cu,0x0c0a657eu,0x0c0a6580u,0x0c0a6582u,0x0c0a6584u,0x0c0a6586u,0x0c0a6588u,0x0c0a658au,0x0c0a658cu,0x0c0a658eu,0x0c0a6590u,0x0c0a6592u,0x0c0a6594u,0x0c0a6596u,0x0c0a6598u,0x0c0a659au,
0x0c0a659cu,0x0c0a659eu,0x0c0a65a0u,0x0c0a65a2u,0x0c0a65a4u,0x0c0a65a6u,0x0c0a65a8u,0x0c0a65aau,0x0c0a65acu,0x0c0a65aeu,0x0c0a65b0u,0x0c0a65b2u,0x0c0a65b4u,0x0c0a65b6u,0x0c0a65b8u,0x0c0a65bau,
0x0c0a65bcu,0x0c0a65beu,0x0c0a65c0u,0x0c0a65c2u,0x0c0a65c4u,0x0c0a65c6u,0x0c0c5f8eu,0x0c0c5f90u,0x0c0c5f92u,0x0c0c5f94u,0x0c0c5f96u,0x0c0c5f98u,0x0c0c5f9au,0x0c0c5f9cu,0x0c0c5f9eu,0x0c0c5fa0u,
0x0c0c5fa2u,0x0c0c5fa4u,0x0c0c5fa6u,0x0c0c5fa8u,0x0c0c5faau,0x0c0c5facu,0x0c0c5faeu,0x0c0c5fb0u,0x0c0c5fb2u,0x0c0c5fb4u,0x0c0c5fb6u,0x0c0c5fb8u,0x0c0c5fbau,0x0c0c5fbcu,0x0c0c5fbeu,0x0c0c5fc0u,
0x0c0c5fc2u,0x0c0c5fc4u,0x0c0c5fc6u,0x0c0c5fc8u,0x0c0c5fcau,0x0c0c5fccu,0x0c0c5fceu,0x0c0c5fd0u,0x0c0c5fd2u,0x0c0c8d60u,0x0c0c8d62u,0x0c0c8d64u,0x0c0c8d66u,0x0c0c8d68u,0x0c0c8d6au,0x0c0c8d6cu,
0x0c0c8d6eu,0x0c0c8d70u,0x0c0c8d72u,0x0c0c8d74u,0x0c0c8d76u,0x0c0c8d78u,0x0c0c8d7au,0x0c0c8d7cu,0x0c0c8d7eu,0x0c0c8d80u,0x0c0c8d82u,0x0c0c8d84u,0x0c0c8d86u,0x0c0c8d88u,0x0c0c8d8au,0x0c0c8d8cu,
};
int vf3_target_family_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
