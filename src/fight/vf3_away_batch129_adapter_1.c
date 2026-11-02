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
int vf3_away_batch129_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042460u: goto P_0c042460;
case 0x0c042462u: goto P_0c042462;
case 0x0c042464u: goto P_0c042464;
case 0x0c042466u: goto P_0c042466;
case 0x0c042468u: goto P_0c042468;
case 0x0c04246au: goto P_0c04246a;
case 0x0c04246cu: goto P_0c04246c;
case 0x0c04246eu: goto P_0c04246e;
case 0x0c042490u: goto P_0c042490;
case 0x0c042492u: goto P_0c042492;
case 0x0c042494u: goto P_0c042494;
case 0x0c042496u: goto P_0c042496;
case 0x0c042498u: goto P_0c042498;
case 0x0c04249au: goto P_0c04249a;
case 0x0c04249cu: goto P_0c04249c;
case 0x0c04249eu: goto P_0c04249e;
case 0x0c0424a0u: goto P_0c0424a0;
case 0x0c0424a2u: goto P_0c0424a2;
case 0x0c0424a4u: goto P_0c0424a4;
case 0x0c0424a6u: goto P_0c0424a6;
case 0x0c0424a8u: goto P_0c0424a8;
case 0x0c0424aau: goto P_0c0424aa;
case 0x0c0424acu: goto P_0c0424ac;
case 0x0c0424aeu: goto P_0c0424ae;
case 0x0c0424b0u: goto P_0c0424b0;
case 0x0c0424b2u: goto P_0c0424b2;
case 0x0c0424b4u: goto P_0c0424b4;
case 0x0c0424b6u: goto P_0c0424b6;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c042460: /* original d207, guest PC 0x0c042460 */
if(!s->budget--) { s->failed_pc=0x0c042460u; return 0; }
r[2]=read(ram,0x0c042480u,4);
goto P_0c042462;
P_0c042462: /* original e303, guest PC 0x0c042462 */
if(!s->budget--) { s->failed_pc=0x0c042462u; return 0; }
r[3]=0x00000003u;
goto P_0c042464;
P_0c042464: /* original 2439, guest PC 0x0c042464 */
if(!s->budget--) { s->failed_pc=0x0c042464u; return 0; }
r[4]&=r[3];
goto P_0c042466;
P_0c042466: /* original 2539, guest PC 0x0c042466 */
if(!s->budget--) { s->failed_pc=0x0c042466u; return 0; }
r[5]&=r[3];
goto P_0c042468;
P_0c042468: /* original 2240, guest PC 0x0c042468 */
if(!s->budget--) { s->failed_pc=0x0c042468u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c04246a;
P_0c04246a: /* original d106, guest PC 0x0c04246a */
if(!s->budget--) { s->failed_pc=0x0c04246au; return 0; }
r[1]=read(ram,0x0c042484u,4);
goto P_0c04246c;
P_0c04246c: /* original 000b, guest PC 0x0c04246c */
if(!s->budget--) { s->failed_pc=0x0c04246cu; return 0; }
target=r[16];
write(ram,r[1],r[5],1);
s->pc=target; return ram->oob==0;
P_0c04246e: /* original 2150, guest PC 0x0c04246e */
if(!s->budget--) { s->failed_pc=0x0c04246eu; return 0; }
write(ram,r[1],r[5],1);
if(!vf3_matrix_family(0x0c042470u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042470u; return 0; } return 1;
P_0c042490: /* original d30a, guest PC 0x0c042490 */
if(!s->budget--) { s->failed_pc=0x0c042490u; return 0; }
r[3]=read(ram,0x0c0424bcu,4);
goto P_0c042492;
P_0c042492: /* original d20b, guest PC 0x0c042492 */
if(!s->budget--) { s->failed_pc=0x0c042492u; return 0; }
r[2]=read(ram,0x0c0424c0u,4);
goto P_0c042494;
P_0c042494: /* original 6530, guest PC 0x0c042494 */
if(!s->budget--) { s->failed_pc=0x0c042494u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c042496;
P_0c042496: /* original d10b, guest PC 0x0c042496 */
if(!s->budget--) { s->failed_pc=0x0c042496u; return 0; }
r[1]=read(ram,0x0c0424c4u,4);
goto P_0c042498;
P_0c042498: /* original 4f12, guest PC 0x0c042498 */
if(!s->budget--) { s->failed_pc=0x0c042498u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04249a;
P_0c04249a: /* original 0527, guest PC 0x0c04249a */
if(!s->budget--) { s->failed_pc=0x0c04249au; return 0; }
r[19]=r[5]*r[2];
goto P_0c04249c;
P_0c04249c: /* original 6412, guest PC 0x0c04249c */
if(!s->budget--) { s->failed_pc=0x0c04249cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c04249e;
P_0c04249e: /* original 2448, guest PC 0x0c04249e */
if(!s->budget--) { s->failed_pc=0x0c04249eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0424a0;
P_0c0424a0: /* original 8d08, guest PC 0x0c0424a0 */
if(!s->budget--) { s->failed_pc=0x0c0424a0u; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c0424b4; }
goto P_0c0424a4;
P_0c0424a2: /* original 051a, guest PC 0x0c0424a2 */
if(!s->budget--) { s->failed_pc=0x0c0424a2u; return 0; }
r[5]=r[19];
goto P_0c0424a4;
P_0c0424a4: /* original 9608, guest PC 0x0c0424a4 */
if(!s->budget--) { s->failed_pc=0x0c0424a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0424b8u,2);
goto P_0c0424a6;
P_0c0424a6: /* original 364c, guest PC 0x0c0424a6 */
if(!s->budget--) { s->failed_pc=0x0c0424a6u; return 0; }
r[6]+=r[4];
goto P_0c0424a8;
P_0c0424a8: /* original d407, guest PC 0x0c0424a8 */
if(!s->budget--) { s->failed_pc=0x0c0424a8u; return 0; }
r[4]=read(ram,0x0c0424c8u,4);
goto P_0c0424aa;
P_0c0424aa: /* original 74ff, guest PC 0x0c0424aa */
if(!s->budget--) { s->failed_pc=0x0c0424aau; return 0; }
r[4]+=0xffffffffu;
goto P_0c0424ac;
P_0c0424ac: /* original 2652, guest PC 0x0c0424ac */
if(!s->budget--) { s->failed_pc=0x0c0424acu; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0424ae;
P_0c0424ae: /* original 4411, guest PC 0x0c0424ae */
if(!s->budget--) { s->failed_pc=0x0c0424aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0424b0;
P_0c0424b0: /* original 8dfb, guest PC 0x0c0424b0 */
if(!s->budget--) { s->failed_pc=0x0c0424b0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(cond) { goto P_0c0424aa; }
goto P_0c0424b4;
P_0c0424b2: /* original 7604, guest PC 0x0c0424b2 */
if(!s->budget--) { s->failed_pc=0x0c0424b2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0424b4;
P_0c0424b4: /* original 000b, guest PC 0x0c0424b4 */
if(!s->budget--) { s->failed_pc=0x0c0424b4u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0424b6: /* original 4f16, guest PC 0x0c0424b6 */
if(!s->budget--) { s->failed_pc=0x0c0424b6u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0424b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0424b8u; return 0; } return 1;
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
r[16]=code_base|0x0c04256cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04256cu) { target=s->pc; goto dispatch; }
goto P_0c04256c;
P_0c04256a: /* original 64e3, guest PC 0x0c04256a */
if(!s->budget--) { s->failed_pc=0x0c04256au; return 0; }
r[4]=r[14];
goto P_0c04256c;
P_0c04256c: /* original c72f, guest PC 0x0c04256c */
if(!s->budget--) { s->failed_pc=0x0c04256cu; return 0; }
r[0]=code_base|0x0004262cu;
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
r[0]=code_base|0x00042634u;
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
r[16]=code_base|0x0c0425a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425a2u) { target=s->pc; goto dispatch; }
goto P_0c0425a2;
P_0c0425a0: /* original 64e3, guest PC 0x0c0425a0 */
if(!s->budget--) { s->failed_pc=0x0c0425a0u; return 0; }
r[4]=r[14];
goto P_0c0425a2;
P_0c0425a2: /* original c725, guest PC 0x0c0425a2 */
if(!s->budget--) { s->failed_pc=0x0c0425a2u; return 0; }
r[0]=code_base|0x00042638u;
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
r[0]=code_base|0x0004262cu;
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
r[16]=code_base|0x0c0425d0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0425d0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0425feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0425feu; return 0; } return 1;
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
target=code_base|0x0c042ae0u; r[16]=code_base|0x0c0426a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426a4u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426aeu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c0426bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426bcu; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0426c8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0426c8u; return 0; } return 1;
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0426e2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c042712u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042712u; return 0; } return 1;
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
target=code_base|0x0c0429b0u; r[16]=code_base|0x0c04274cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04274cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c042788u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042788u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
