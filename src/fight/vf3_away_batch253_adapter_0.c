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
int vf3_away_batch253_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c950cu: goto P_0c0c950c;
case 0x0c0c950eu: goto P_0c0c950e;
case 0x0c0c9510u: goto P_0c0c9510;
case 0x0c0c9512u: goto P_0c0c9512;
case 0x0c0c9514u: goto P_0c0c9514;
case 0x0c0c9516u: goto P_0c0c9516;
case 0x0c0c9518u: goto P_0c0c9518;
case 0x0c0c951au: goto P_0c0c951a;
case 0x0c0c951cu: goto P_0c0c951c;
case 0x0c0c951eu: goto P_0c0c951e;
case 0x0c0c9520u: goto P_0c0c9520;
case 0x0c0c9522u: goto P_0c0c9522;
case 0x0c0c9524u: goto P_0c0c9524;
case 0x0c0c9526u: goto P_0c0c9526;
case 0x0c0c9528u: goto P_0c0c9528;
case 0x0c0c952au: goto P_0c0c952a;
case 0x0c0c952cu: goto P_0c0c952c;
case 0x0c0c952eu: goto P_0c0c952e;
case 0x0c0c9530u: goto P_0c0c9530;
case 0x0c0c9532u: goto P_0c0c9532;
case 0x0c0c9534u: goto P_0c0c9534;
case 0x0c0c9536u: goto P_0c0c9536;
case 0x0c0c9538u: goto P_0c0c9538;
case 0x0c0c953au: goto P_0c0c953a;
case 0x0c0c953cu: goto P_0c0c953c;
case 0x0c0c953eu: goto P_0c0c953e;
case 0x0c0c9540u: goto P_0c0c9540;
case 0x0c0c9542u: goto P_0c0c9542;
case 0x0c0c9544u: goto P_0c0c9544;
case 0x0c0c9546u: goto P_0c0c9546;
case 0x0c0c9548u: goto P_0c0c9548;
case 0x0c0c954au: goto P_0c0c954a;
case 0x0c0c954cu: goto P_0c0c954c;
case 0x0c0c954eu: goto P_0c0c954e;
case 0x0c0c9550u: goto P_0c0c9550;
case 0x0c0c9552u: goto P_0c0c9552;
case 0x0c0c9554u: goto P_0c0c9554;
case 0x0c0c9556u: goto P_0c0c9556;
case 0x0c0c9558u: goto P_0c0c9558;
case 0x0c0c955au: goto P_0c0c955a;
case 0x0c0c955cu: goto P_0c0c955c;
case 0x0c0c955eu: goto P_0c0c955e;
case 0x0c0c9560u: goto P_0c0c9560;
case 0x0c0c9562u: goto P_0c0c9562;
case 0x0c0c9564u: goto P_0c0c9564;
case 0x0c0c9566u: goto P_0c0c9566;
case 0x0c0c9568u: goto P_0c0c9568;
case 0x0c0c956au: goto P_0c0c956a;
case 0x0c0c956cu: goto P_0c0c956c;
case 0x0c0c956eu: goto P_0c0c956e;
case 0x0c0c9570u: goto P_0c0c9570;
case 0x0c0c9572u: goto P_0c0c9572;
case 0x0c0c9574u: goto P_0c0c9574;
case 0x0c0c9576u: goto P_0c0c9576;
case 0x0c0c9578u: goto P_0c0c9578;
case 0x0c0c957au: goto P_0c0c957a;
case 0x0c0c957cu: goto P_0c0c957c;
case 0x0c0c957eu: goto P_0c0c957e;
case 0x0c0c9580u: goto P_0c0c9580;
case 0x0c0c9582u: goto P_0c0c9582;
case 0x0c0c9584u: goto P_0c0c9584;
case 0x0c0c9586u: goto P_0c0c9586;
case 0x0c0c9588u: goto P_0c0c9588;
case 0x0c0c958au: goto P_0c0c958a;
case 0x0c0c958cu: goto P_0c0c958c;
case 0x0c0c958eu: goto P_0c0c958e;
case 0x0c0c9590u: goto P_0c0c9590;
case 0x0c0c9592u: goto P_0c0c9592;
case 0x0c0c9594u: goto P_0c0c9594;
case 0x0c0c9596u: goto P_0c0c9596;
case 0x0c0c9598u: goto P_0c0c9598;
case 0x0c0c959au: goto P_0c0c959a;
case 0x0c0c959cu: goto P_0c0c959c;
case 0x0c0c959eu: goto P_0c0c959e;
case 0x0c0c95f4u: goto P_0c0c95f4;
case 0x0c0c95f6u: goto P_0c0c95f6;
case 0x0c0c95f8u: goto P_0c0c95f8;
case 0x0c0c95fau: goto P_0c0c95fa;
case 0x0c0c95fcu: goto P_0c0c95fc;
case 0x0c0c95feu: goto P_0c0c95fe;
case 0x0c0c9600u: goto P_0c0c9600;
case 0x0c0c9602u: goto P_0c0c9602;
case 0x0c0c9604u: goto P_0c0c9604;
case 0x0c0c9606u: goto P_0c0c9606;
case 0x0c0c9608u: goto P_0c0c9608;
case 0x0c0c960au: goto P_0c0c960a;
case 0x0c0c960cu: goto P_0c0c960c;
case 0x0c0c960eu: goto P_0c0c960e;
case 0x0c0c9610u: goto P_0c0c9610;
case 0x0c0c9612u: goto P_0c0c9612;
case 0x0c0c9614u: goto P_0c0c9614;
case 0x0c0c9616u: goto P_0c0c9616;
case 0x0c0c9618u: goto P_0c0c9618;
case 0x0c0c961au: goto P_0c0c961a;
case 0x0c0c961cu: goto P_0c0c961c;
case 0x0c0c961eu: goto P_0c0c961e;
case 0x0c0c9620u: goto P_0c0c9620;
case 0x0c0c9622u: goto P_0c0c9622;
case 0x0c0c9624u: goto P_0c0c9624;
case 0x0c0c9626u: goto P_0c0c9626;
case 0x0c0c9628u: goto P_0c0c9628;
case 0x0c0c962au: goto P_0c0c962a;
case 0x0c0c962cu: goto P_0c0c962c;
case 0x0c0c962eu: goto P_0c0c962e;
case 0x0c0c9630u: goto P_0c0c9630;
case 0x0c0c9632u: goto P_0c0c9632;
case 0x0c0c9634u: goto P_0c0c9634;
case 0x0c0c9636u: goto P_0c0c9636;
case 0x0c0c9638u: goto P_0c0c9638;
case 0x0c0c963au: goto P_0c0c963a;
case 0x0c0c963cu: goto P_0c0c963c;
case 0x0c0c963eu: goto P_0c0c963e;
case 0x0c0c9640u: goto P_0c0c9640;
case 0x0c0c9642u: goto P_0c0c9642;
case 0x0c0c9644u: goto P_0c0c9644;
case 0x0c0c9646u: goto P_0c0c9646;
case 0x0c0c9648u: goto P_0c0c9648;
case 0x0c0c964au: goto P_0c0c964a;
case 0x0c0c964cu: goto P_0c0c964c;
case 0x0c0c964eu: goto P_0c0c964e;
case 0x0c0c9650u: goto P_0c0c9650;
case 0x0c0c9652u: goto P_0c0c9652;
case 0x0c0c9654u: goto P_0c0c9654;
case 0x0c0c9656u: goto P_0c0c9656;
case 0x0c0c9658u: goto P_0c0c9658;
case 0x0c0c965au: goto P_0c0c965a;
case 0x0c0c965cu: goto P_0c0c965c;
case 0x0c0c965eu: goto P_0c0c965e;
case 0x0c0c9660u: goto P_0c0c9660;
case 0x0c0c9662u: goto P_0c0c9662;
case 0x0c0c9664u: goto P_0c0c9664;
case 0x0c0c9666u: goto P_0c0c9666;
case 0x0c0c9668u: goto P_0c0c9668;
case 0x0c0c966au: goto P_0c0c966a;
case 0x0c0c966cu: goto P_0c0c966c;
case 0x0c0c966eu: goto P_0c0c966e;
case 0x0c0c9670u: goto P_0c0c9670;
case 0x0c0c9672u: goto P_0c0c9672;
case 0x0c0c9674u: goto P_0c0c9674;
case 0x0c0c9676u: goto P_0c0c9676;
case 0x0c0c9678u: goto P_0c0c9678;
case 0x0c0c967au: goto P_0c0c967a;
case 0x0c0c967cu: goto P_0c0c967c;
case 0x0c0c967eu: goto P_0c0c967e;
case 0x0c0c9680u: goto P_0c0c9680;
case 0x0c0c9682u: goto P_0c0c9682;
case 0x0c0c9684u: goto P_0c0c9684;
case 0x0c0c9686u: goto P_0c0c9686;
case 0x0c0c9688u: goto P_0c0c9688;
case 0x0c0c968au: goto P_0c0c968a;
case 0x0c0c968cu: goto P_0c0c968c;
case 0x0c0c968eu: goto P_0c0c968e;
case 0x0c0c9690u: goto P_0c0c9690;
case 0x0c0c9692u: goto P_0c0c9692;
case 0x0c0c9694u: goto P_0c0c9694;
case 0x0c0c9696u: goto P_0c0c9696;
case 0x0c0c9698u: goto P_0c0c9698;
case 0x0c0c969au: goto P_0c0c969a;
case 0x0c0c969cu: goto P_0c0c969c;
case 0x0c0c969eu: goto P_0c0c969e;
case 0x0c0c96a0u: goto P_0c0c96a0;
case 0x0c0c96a2u: goto P_0c0c96a2;
case 0x0c0c96a4u: goto P_0c0c96a4;
case 0x0c0c96a6u: goto P_0c0c96a6;
case 0x0c0c96a8u: goto P_0c0c96a8;
case 0x0c0c96aau: goto P_0c0c96aa;
case 0x0c0c96acu: goto P_0c0c96ac;
case 0x0c0c96aeu: goto P_0c0c96ae;
case 0x0c0c96b0u: goto P_0c0c96b0;
case 0x0c0c96b2u: goto P_0c0c96b2;
case 0x0c0c96b4u: goto P_0c0c96b4;
case 0x0c0c96b6u: goto P_0c0c96b6;
case 0x0c0c96b8u: goto P_0c0c96b8;
case 0x0c0c96bau: goto P_0c0c96ba;
case 0x0c0c96bcu: goto P_0c0c96bc;
case 0x0c0c96beu: goto P_0c0c96be;
case 0x0c0c96c0u: goto P_0c0c96c0;
case 0x0c0c96f0u: goto P_0c0c96f0;
case 0x0c0c96f2u: goto P_0c0c96f2;
case 0x0c0c96f4u: goto P_0c0c96f4;
case 0x0c0c96f6u: goto P_0c0c96f6;
case 0x0c0c96f8u: goto P_0c0c96f8;
case 0x0c0c96fau: goto P_0c0c96fa;
case 0x0c0c96fcu: goto P_0c0c96fc;
case 0x0c0c96feu: goto P_0c0c96fe;
case 0x0c0c9700u: goto P_0c0c9700;
case 0x0c0c9702u: goto P_0c0c9702;
case 0x0c0c9704u: goto P_0c0c9704;
case 0x0c0c9706u: goto P_0c0c9706;
case 0x0c0c9708u: goto P_0c0c9708;
case 0x0c0c970au: goto P_0c0c970a;
case 0x0c0c970cu: goto P_0c0c970c;
case 0x0c0c970eu: goto P_0c0c970e;
case 0x0c0c9710u: goto P_0c0c9710;
case 0x0c0c9712u: goto P_0c0c9712;
case 0x0c0c9714u: goto P_0c0c9714;
case 0x0c0c9716u: goto P_0c0c9716;
case 0x0c0c9718u: goto P_0c0c9718;
case 0x0c0c971au: goto P_0c0c971a;
case 0x0c0c971cu: goto P_0c0c971c;
case 0x0c0c971eu: goto P_0c0c971e;
case 0x0c0c9720u: goto P_0c0c9720;
case 0x0c0c9722u: goto P_0c0c9722;
case 0x0c0c9724u: goto P_0c0c9724;
case 0x0c0c9726u: goto P_0c0c9726;
case 0x0c0c9728u: goto P_0c0c9728;
case 0x0c0c972au: goto P_0c0c972a;
case 0x0c0c972cu: goto P_0c0c972c;
case 0x0c0c972eu: goto P_0c0c972e;
case 0x0c0c9730u: goto P_0c0c9730;
case 0x0c0c9732u: goto P_0c0c9732;
case 0x0c0c9734u: goto P_0c0c9734;
case 0x0c0c9736u: goto P_0c0c9736;
case 0x0c0c9738u: goto P_0c0c9738;
case 0x0c0c973au: goto P_0c0c973a;
case 0x0c0c973cu: goto P_0c0c973c;
case 0x0c0c973eu: goto P_0c0c973e;
case 0x0c0c9740u: goto P_0c0c9740;
case 0x0c0c9742u: goto P_0c0c9742;
case 0x0c0c9744u: goto P_0c0c9744;
case 0x0c0c9746u: goto P_0c0c9746;
case 0x0c0c9748u: goto P_0c0c9748;
case 0x0c0c974au: goto P_0c0c974a;
case 0x0c0c974cu: goto P_0c0c974c;
case 0x0c0c974eu: goto P_0c0c974e;
case 0x0c0c9750u: goto P_0c0c9750;
case 0x0c0c9752u: goto P_0c0c9752;
case 0x0c0c9754u: goto P_0c0c9754;
case 0x0c0c9756u: goto P_0c0c9756;
case 0x0c0c9758u: goto P_0c0c9758;
case 0x0c0c975au: goto P_0c0c975a;
case 0x0c0c975cu: goto P_0c0c975c;
case 0x0c0c975eu: goto P_0c0c975e;
case 0x0c0c9760u: goto P_0c0c9760;
case 0x0c0c9762u: goto P_0c0c9762;
case 0x0c0c9764u: goto P_0c0c9764;
case 0x0c0c9766u: goto P_0c0c9766;
case 0x0c0c9768u: goto P_0c0c9768;
case 0x0c0c976au: goto P_0c0c976a;
case 0x0c0c976cu: goto P_0c0c976c;
case 0x0c0c976eu: goto P_0c0c976e;
case 0x0c0c9770u: goto P_0c0c9770;
case 0x0c0c9772u: goto P_0c0c9772;
case 0x0c0c9774u: goto P_0c0c9774;
case 0x0c0c9776u: goto P_0c0c9776;
case 0x0c0c9778u: goto P_0c0c9778;
case 0x0c0c977au: goto P_0c0c977a;
case 0x0c0c977cu: goto P_0c0c977c;
case 0x0c0c977eu: goto P_0c0c977e;
case 0x0c0c9780u: goto P_0c0c9780;
case 0x0c0c9782u: goto P_0c0c9782;
case 0x0c0c9784u: goto P_0c0c9784;
case 0x0c0c9786u: goto P_0c0c9786;
case 0x0c0c9788u: goto P_0c0c9788;
case 0x0c0c978au: goto P_0c0c978a;
case 0x0c0c978cu: goto P_0c0c978c;
case 0x0c0c978eu: goto P_0c0c978e;
case 0x0c0c9790u: goto P_0c0c9790;
case 0x0c0c9792u: goto P_0c0c9792;
case 0x0c0c9794u: goto P_0c0c9794;
case 0x0c0c9796u: goto P_0c0c9796;
case 0x0c0c9798u: goto P_0c0c9798;
case 0x0c0c979au: goto P_0c0c979a;
case 0x0c0c97b0u: goto P_0c0c97b0;
case 0x0c0c97b2u: goto P_0c0c97b2;
case 0x0c0c97b4u: goto P_0c0c97b4;
case 0x0c0c97b6u: goto P_0c0c97b6;
case 0x0c0c97b8u: goto P_0c0c97b8;
case 0x0c0c97bau: goto P_0c0c97ba;
case 0x0c0c97bcu: goto P_0c0c97bc;
case 0x0c0c97beu: goto P_0c0c97be;
case 0x0c0c97c0u: goto P_0c0c97c0;
case 0x0c0c97c2u: goto P_0c0c97c2;
case 0x0c0c97c4u: goto P_0c0c97c4;
case 0x0c0c97c6u: goto P_0c0c97c6;
case 0x0c0c97c8u: goto P_0c0c97c8;
case 0x0c0c97cau: goto P_0c0c97ca;
case 0x0c0c97ccu: goto P_0c0c97cc;
case 0x0c0c97ceu: goto P_0c0c97ce;
case 0x0c0c97d0u: goto P_0c0c97d0;
case 0x0c0c97d2u: goto P_0c0c97d2;
case 0x0c0c97d4u: goto P_0c0c97d4;
case 0x0c0c97d6u: goto P_0c0c97d6;
case 0x0c0c97d8u: goto P_0c0c97d8;
case 0x0c0c97dau: goto P_0c0c97da;
case 0x0c0c97dcu: goto P_0c0c97dc;
case 0x0c0c97deu: goto P_0c0c97de;
case 0x0c0c97e0u: goto P_0c0c97e0;
case 0x0c0c97e2u: goto P_0c0c97e2;
case 0x0c0c97e4u: goto P_0c0c97e4;
case 0x0c0c97e6u: goto P_0c0c97e6;
case 0x0c0c97e8u: goto P_0c0c97e8;
case 0x0c0c97eau: goto P_0c0c97ea;
case 0x0c0c97ecu: goto P_0c0c97ec;
case 0x0c0c97eeu: goto P_0c0c97ee;
case 0x0c0c97f0u: goto P_0c0c97f0;
case 0x0c0c97f2u: goto P_0c0c97f2;
case 0x0c0c97f4u: goto P_0c0c97f4;
case 0x0c0c97f6u: goto P_0c0c97f6;
case 0x0c0c97f8u: goto P_0c0c97f8;
case 0x0c0c97fau: goto P_0c0c97fa;
case 0x0c0c97fcu: goto P_0c0c97fc;
case 0x0c0c97feu: goto P_0c0c97fe;
case 0x0c0c9800u: goto P_0c0c9800;
case 0x0c0c9802u: goto P_0c0c9802;
case 0x0c0c9804u: goto P_0c0c9804;
case 0x0c0c9806u: goto P_0c0c9806;
case 0x0c0c9808u: goto P_0c0c9808;
case 0x0c0c980au: goto P_0c0c980a;
case 0x0c0c980cu: goto P_0c0c980c;
case 0x0c0c980eu: goto P_0c0c980e;
case 0x0c0c9810u: goto P_0c0c9810;
case 0x0c0c9812u: goto P_0c0c9812;
case 0x0c0c9814u: goto P_0c0c9814;
case 0x0c0c9816u: goto P_0c0c9816;
case 0x0c0c9818u: goto P_0c0c9818;
case 0x0c0c981au: goto P_0c0c981a;
case 0x0c0c981cu: goto P_0c0c981c;
case 0x0c0c981eu: goto P_0c0c981e;
case 0x0c0c9820u: goto P_0c0c9820;
case 0x0c0c9822u: goto P_0c0c9822;
case 0x0c0c9824u: goto P_0c0c9824;
case 0x0c0c9826u: goto P_0c0c9826;
case 0x0c0c9828u: goto P_0c0c9828;
case 0x0c0c982au: goto P_0c0c982a;
case 0x0c0c982cu: goto P_0c0c982c;
case 0x0c0c982eu: goto P_0c0c982e;
case 0x0c0c9830u: goto P_0c0c9830;
case 0x0c0c9832u: goto P_0c0c9832;
case 0x0c0c9834u: goto P_0c0c9834;
case 0x0c0c9836u: goto P_0c0c9836;
case 0x0c0c9838u: goto P_0c0c9838;
case 0x0c0c983au: goto P_0c0c983a;
case 0x0c0c983cu: goto P_0c0c983c;
case 0x0c0c983eu: goto P_0c0c983e;
case 0x0c0c9840u: goto P_0c0c9840;
case 0x0c0c9842u: goto P_0c0c9842;
case 0x0c0c9844u: goto P_0c0c9844;
case 0x0c0c9846u: goto P_0c0c9846;
case 0x0c0c9848u: goto P_0c0c9848;
case 0x0c0c984au: goto P_0c0c984a;
case 0x0c0c984cu: goto P_0c0c984c;
case 0x0c0c984eu: goto P_0c0c984e;
case 0x0c0c9850u: goto P_0c0c9850;
case 0x0c0c9852u: goto P_0c0c9852;
case 0x0c0c9854u: goto P_0c0c9854;
case 0x0c0c9856u: goto P_0c0c9856;
case 0x0c0c9858u: goto P_0c0c9858;
case 0x0c0c985au: goto P_0c0c985a;
case 0x0c0c985cu: goto P_0c0c985c;
case 0x0c0c985eu: goto P_0c0c985e;
case 0x0c0c9860u: goto P_0c0c9860;
case 0x0c0c9862u: goto P_0c0c9862;
case 0x0c0c9864u: goto P_0c0c9864;
case 0x0c0c9866u: goto P_0c0c9866;
case 0x0c0c9868u: goto P_0c0c9868;
case 0x0c0c986au: goto P_0c0c986a;
case 0x0c0c986cu: goto P_0c0c986c;
case 0x0c0c986eu: goto P_0c0c986e;
case 0x0c0c9870u: goto P_0c0c9870;
case 0x0c0c9872u: goto P_0c0c9872;
case 0x0c0c9874u: goto P_0c0c9874;
case 0x0c0c9890u: goto P_0c0c9890;
case 0x0c0c9892u: goto P_0c0c9892;
case 0x0c0c9894u: goto P_0c0c9894;
case 0x0c0c9896u: goto P_0c0c9896;
case 0x0c0c9898u: goto P_0c0c9898;
case 0x0c0c989au: goto P_0c0c989a;
case 0x0c0c989cu: goto P_0c0c989c;
case 0x0c0c989eu: goto P_0c0c989e;
case 0x0c0c98a0u: goto P_0c0c98a0;
case 0x0c0c98a2u: goto P_0c0c98a2;
case 0x0c0c98a4u: goto P_0c0c98a4;
case 0x0c0c98a6u: goto P_0c0c98a6;
case 0x0c0c98a8u: goto P_0c0c98a8;
case 0x0c0c98aau: goto P_0c0c98aa;
case 0x0c0c98acu: goto P_0c0c98ac;
case 0x0c0c98aeu: goto P_0c0c98ae;
case 0x0c0c98b0u: goto P_0c0c98b0;
case 0x0c0c98b2u: goto P_0c0c98b2;
case 0x0c0c98b4u: goto P_0c0c98b4;
case 0x0c0c98b6u: goto P_0c0c98b6;
case 0x0c0c98b8u: goto P_0c0c98b8;
case 0x0c0c98bau: goto P_0c0c98ba;
case 0x0c0c98bcu: goto P_0c0c98bc;
case 0x0c0c98beu: goto P_0c0c98be;
case 0x0c0c98c0u: goto P_0c0c98c0;
case 0x0c0c98c2u: goto P_0c0c98c2;
case 0x0c0c98c4u: goto P_0c0c98c4;
case 0x0c0c98c6u: goto P_0c0c98c6;
case 0x0c0c98c8u: goto P_0c0c98c8;
case 0x0c0c98cau: goto P_0c0c98ca;
case 0x0c0c98ccu: goto P_0c0c98cc;
case 0x0c0c98ceu: goto P_0c0c98ce;
case 0x0c0c98d0u: goto P_0c0c98d0;
case 0x0c0c98d2u: goto P_0c0c98d2;
case 0x0c0c98d4u: goto P_0c0c98d4;
case 0x0c0c98d6u: goto P_0c0c98d6;
case 0x0c0c98d8u: goto P_0c0c98d8;
case 0x0c0c98dau: goto P_0c0c98da;
case 0x0c0c98dcu: goto P_0c0c98dc;
case 0x0c0c98deu: goto P_0c0c98de;
case 0x0c0c98e0u: goto P_0c0c98e0;
case 0x0c0c98e2u: goto P_0c0c98e2;
case 0x0c0c98e4u: goto P_0c0c98e4;
case 0x0c0c98e6u: goto P_0c0c98e6;
case 0x0c0c98e8u: goto P_0c0c98e8;
case 0x0c0c98eau: goto P_0c0c98ea;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c950c: /* original 2fe6, guest PC 0x0c0c950c */
if(!s->budget--) { s->failed_pc=0x0c0c950cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c950e;
P_0c0c950e: /* original 2fd6, guest PC 0x0c0c950e */
if(!s->budget--) { s->failed_pc=0x0c0c950eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9510;
P_0c0c9510: /* original d730, guest PC 0x0c0c9510 */
if(!s->budget--) { s->failed_pc=0x0c0c9510u; return 0; }
r[7]=read(ram,0x0c0c95d4u,4);
goto P_0c0c9512;
P_0c0c9512: /* original 9057, guest PC 0x0c0c9512 */
if(!s->budget--) { s->failed_pc=0x0c0c9512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c4u,2);
goto P_0c0c9514;
P_0c0c9514: /* original de30, guest PC 0x0c0c9514 */
if(!s->budget--) { s->failed_pc=0x0c0c9514u; return 0; }
r[14]=read(ram,0x0c0c95d8u,4);
goto P_0c0c9516;
P_0c0c9516: /* original 067e, guest PC 0x0c0c9516 */
if(!s->budget--) { s->failed_pc=0x0c0c9516u; return 0; }
r[6]=read(ram,r[7]+r[0],4);
goto P_0c0c9518;
P_0c0c9518: /* original 9055, guest PC 0x0c0c9518 */
if(!s->budget--) { s->failed_pc=0x0c0c9518u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c6u,2);
goto P_0c0c951a;
P_0c0c951a: /* original 00ec, guest PC 0x0c0c951a */
if(!s->budget--) { s->failed_pc=0x0c0c951au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c951c;
P_0c0c951c: /* original 8802, guest PC 0x0c0c951c */
if(!s->budget--) { s->failed_pc=0x0c0c951cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c951e;
P_0c0c951e: /* original 8f23, guest PC 0x0c0c951e */
if(!s->budget--) { s->failed_pc=0x0c0c951eu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(!cond) { goto P_0c0c9568; }
goto P_0c0c9522;
P_0c0c9520: /* original 6503, guest PC 0x0c0c9520 */
if(!s->budget--) { s->failed_pc=0x0c0c9520u; return 0; }
r[5]=r[0];
goto P_0c0c9522;
P_0c0c9522: /* original 9051, guest PC 0x0c0c9522 */
if(!s->budget--) { s->failed_pc=0x0c0c9522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c8u,2);
goto P_0c0c9524;
P_0c0c9524: /* original 9351, guest PC 0x0c0c9524 */
if(!s->budget--) { s->failed_pc=0x0c0c9524u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95cau,2);
goto P_0c0c9526;
P_0c0c9526: /* original 04ec, guest PC 0x0c0c9526 */
if(!s->budget--) { s->failed_pc=0x0c0c9526u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9528;
P_0c0c9528: /* original 2368, guest PC 0x0c0c9528 */
if(!s->budget--) { s->failed_pc=0x0c0c9528u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c952a;
P_0c0c952a: /* original 8f12, guest PC 0x0c0c952a */
if(!s->budget--) { s->failed_pc=0x0c0c952au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c0c9552; }
goto P_0c0c952e;
P_0c0c952c: /* original 7401, guest PC 0x0c0c952c */
if(!s->budget--) { s->failed_pc=0x0c0c952cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c952e;
P_0c0c952e: /* original 924d, guest PC 0x0c0c952e */
if(!s->budget--) { s->failed_pc=0x0c0c952eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95ccu,2);
goto P_0c0c9530;
P_0c0c9530: /* original 2268, guest PC 0x0c0c9530 */
if(!s->budget--) { s->failed_pc=0x0c0c9530u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c9532;
P_0c0c9532: /* original 8b0d, guest PC 0x0c0c9532 */
if(!s->budget--) { s->failed_pc=0x0c0c9532u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9550; }
goto P_0c0c9534;
P_0c0c9534: /* original 904b, guest PC 0x0c0c9534 */
if(!s->budget--) { s->failed_pc=0x0c0c9534u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95ceu,2);
goto P_0c0c9536;
P_0c0c9536: /* original e308, guest PC 0x0c0c9536 */
if(!s->budget--) { s->failed_pc=0x0c0c9536u; return 0; }
r[3]=0x00000008u;
goto P_0c0c9538;
P_0c0c9538: /* original 0d7e, guest PC 0x0c0c9538 */
if(!s->budget--) { s->failed_pc=0x0c0c9538u; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c0c953a;
P_0c0c953a: /* original 23d8, guest PC 0x0c0c953a */
if(!s->budget--) { s->failed_pc=0x0c0c953au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c953c;
P_0c0c953c: /* original 8902, guest PC 0x0c0c953c */
if(!s->budget--) { s->failed_pc=0x0c0c953cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9544; }
goto P_0c0c953e;
P_0c0c953e: /* original e204, guest PC 0x0c0c953e */
if(!s->budget--) { s->failed_pc=0x0c0c953eu; return 0; }
r[2]=0x00000004u;
goto P_0c0c9540;
P_0c0c9540: /* original 2268, guest PC 0x0c0c9540 */
if(!s->budget--) { s->failed_pc=0x0c0c9540u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c9542;
P_0c0c9542: /* original 8b06, guest PC 0x0c0c9542 */
if(!s->budget--) { s->failed_pc=0x0c0c9542u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9552; }
goto P_0c0c9544;
P_0c0c9544: /* original d325, guest PC 0x0c0c9544 */
if(!s->budget--) { s->failed_pc=0x0c0c9544u; return 0; }
r[3]=read(ram,0x0c0c95dcu,4);
goto P_0c0c9546;
P_0c0c9546: /* original 2d38, guest PC 0x0c0c9546 */
if(!s->budget--) { s->failed_pc=0x0c0c9546u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c0c9548;
P_0c0c9548: /* original 890e, guest PC 0x0c0c9548 */
if(!s->budget--) { s->failed_pc=0x0c0c9548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9568; }
goto P_0c0c954a;
P_0c0c954a: /* original d225, guest PC 0x0c0c954a */
if(!s->budget--) { s->failed_pc=0x0c0c954au; return 0; }
r[2]=read(ram,0x0c0c95e0u,4);
goto P_0c0c954c;
P_0c0c954c: /* original 2268, guest PC 0x0c0c954c */
if(!s->budget--) { s->failed_pc=0x0c0c954cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c954e;
P_0c0c954e: /* original 890b, guest PC 0x0c0c954e */
if(!s->budget--) { s->failed_pc=0x0c0c954eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9568; }
goto P_0c0c9550;
P_0c0c9550: /* original 74fe, guest PC 0x0c0c9550 */
if(!s->budget--) { s->failed_pc=0x0c0c9550u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c0c9552;
P_0c0c9552: /* original e30c, guest PC 0x0c0c9552 */
if(!s->budget--) { s->failed_pc=0x0c0c9552u; return 0; }
r[3]=0x0000000cu;
goto P_0c0c9554;
P_0c0c9554: /* original 3437, guest PC 0x0c0c9554 */
if(!s->budget--) { s->failed_pc=0x0c0c9554u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c9556;
P_0c0c9556: /* original 8d03, guest PC 0x0c0c9556 */
if(!s->budget--) { s->failed_pc=0x0c0c9556u; return 0; }
cond=r[17]&1u;
r[6]=0xfffffff3u;
if(cond) { goto P_0c0c9560; }
goto P_0c0c955a;
P_0c0c9558: /* original e6f3, guest PC 0x0c0c9558 */
if(!s->budget--) { s->failed_pc=0x0c0c9558u; return 0; }
r[6]=0xfffffff3u;
goto P_0c0c955a;
P_0c0c955a: /* original 4411, guest PC 0x0c0c955a */
if(!s->budget--) { s->failed_pc=0x0c0c955au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c955c;
P_0c0c955c: /* original 8d01, guest PC 0x0c0c955c */
if(!s->budget--) { s->failed_pc=0x0c0c955cu; return 0; }
cond=r[17]&1u;
r[6]=0x0000000du;
if(cond) { goto P_0c0c9562; }
goto P_0c0c9560;
P_0c0c955e: /* original e60d, guest PC 0x0c0c955e */
if(!s->budget--) { s->failed_pc=0x0c0c955eu; return 0; }
r[6]=0x0000000du;
goto P_0c0c9560;
P_0c0c9560: /* original 346c, guest PC 0x0c0c9560 */
if(!s->budget--) { s->failed_pc=0x0c0c9560u; return 0; }
r[4]+=r[6];
goto P_0c0c9562;
P_0c0c9562: /* original 9031, guest PC 0x0c0c9562 */
if(!s->budget--) { s->failed_pc=0x0c0c9562u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c8u,2);
goto P_0c0c9564;
P_0c0c9564: /* original a00f, guest PC 0x0c0c9564 */
if(!s->budget--) { s->failed_pc=0x0c0c9564u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9586;
P_0c0c9566: /* original 0e44, guest PC 0x0c0c9566 */
if(!s->budget--) { s->failed_pc=0x0c0c9566u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9568;
P_0c0c9568: /* original d21e, guest PC 0x0c0c9568 */
if(!s->budget--) { s->failed_pc=0x0c0c9568u; return 0; }
r[2]=read(ram,0x0c0c95e4u,4);
goto P_0c0c956a;
P_0c0c956a: /* original 2268, guest PC 0x0c0c956a */
if(!s->budget--) { s->failed_pc=0x0c0c956au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0c956c;
P_0c0c956c: /* original 8f07, guest PC 0x0c0c956c */
if(!s->budget--) { s->failed_pc=0x0c0c956cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0c957e; }
goto P_0c0c9570;
P_0c0c956e: /* original 7501, guest PC 0x0c0c956e */
if(!s->budget--) { s->failed_pc=0x0c0c956eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9570;
P_0c0c9570: /* original d31d, guest PC 0x0c0c9570 */
if(!s->budget--) { s->failed_pc=0x0c0c9570u; return 0; }
r[3]=read(ram,0x0c0c95e8u,4);
goto P_0c0c9572;
P_0c0c9572: /* original 2368, guest PC 0x0c0c9572 */
if(!s->budget--) { s->failed_pc=0x0c0c9572u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c9574;
P_0c0c9574: /* original 8b0e, guest PC 0x0c0c9574 */
if(!s->budget--) { s->failed_pc=0x0c0c9574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9594; }
goto P_0c0c9576;
P_0c0c9576: /* original 922b, guest PC 0x0c0c9576 */
if(!s->budget--) { s->failed_pc=0x0c0c9576u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95d0u,2);
goto P_0c0c9578;
P_0c0c9578: /* original 2628, guest PC 0x0c0c9578 */
if(!s->budget--) { s->failed_pc=0x0c0c9578u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c957a;
P_0c0c957a: /* original 890d, guest PC 0x0c0c957a */
if(!s->budget--) { s->failed_pc=0x0c0c957au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9598; }
goto P_0c0c957c;
P_0c0c957c: /* original 75fe, guest PC 0x0c0c957c */
if(!s->budget--) { s->failed_pc=0x0c0c957cu; return 0; }
r[5]+=0xfffffffeu;
goto P_0c0c957e;
P_0c0c957e: /* original 9022, guest PC 0x0c0c957e */
if(!s->budget--) { s->failed_pc=0x0c0c957eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c95c6u,2);
goto P_0c0c9580;
P_0c0c9580: /* original e203, guest PC 0x0c0c9580 */
if(!s->budget--) { s->failed_pc=0x0c0c9580u; return 0; }
r[2]=0x00000003u;
goto P_0c0c9582;
P_0c0c9582: /* original 2529, guest PC 0x0c0c9582 */
if(!s->budget--) { s->failed_pc=0x0c0c9582u; return 0; }
r[5]&=r[2];
goto P_0c0c9584;
P_0c0c9584: /* original 0e54, guest PC 0x0c0c9584 */
if(!s->budget--) { s->failed_pc=0x0c0c9584u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9586;
P_0c0c9586: /* original d019, guest PC 0x0c0c9586 */
if(!s->budget--) { s->failed_pc=0x0c0c9586u; return 0; }
r[0]=read(ram,0x0c0c95ecu,4);
goto P_0c0c9588;
P_0c0c9588: /* original e210, guest PC 0x0c0c9588 */
if(!s->budget--) { s->failed_pc=0x0c0c9588u; return 0; }
r[2]=0x00000010u;
goto P_0c0c958a;
P_0c0c958a: /* original 327c, guest PC 0x0c0c958a */
if(!s->budget--) { s->failed_pc=0x0c0c958au; return 0; }
r[2]+=r[7];
goto P_0c0c958c;
P_0c0c958c: /* original 035c, guest PC 0x0c0c958c */
if(!s->budget--) { s->failed_pc=0x0c0c958cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c958e;
P_0c0c958e: /* original 2230, guest PC 0x0c0c958e */
if(!s->budget--) { s->failed_pc=0x0c0c958eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c0c9590;
P_0c0c9590: /* original a002, guest PC 0x0c0c9590 */
if(!s->budget--) { s->failed_pc=0x0c0c9590u; return 0; }
goto P_0c0c9598;
P_0c0c9592: /* original 0009, guest PC 0x0c0c9592 */
if(!s->budget--) { s->failed_pc=0x0c0c9592u; return 0; }
goto P_0c0c9594;
P_0c0c9594: /* original e000, guest PC 0x0c0c9594 */
if(!s->budget--) { s->failed_pc=0x0c0c9594u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9596;
P_0c0c9596: /* original 807b, guest PC 0x0c0c9596 */
if(!s->budget--) { s->failed_pc=0x0c0c9596u; return 0; }
write(ram,r[7]+11,r[0],1);
goto P_0c0c9598;
P_0c0c9598: /* original d315, guest PC 0x0c0c9598 */
if(!s->budget--) { s->failed_pc=0x0c0c9598u; return 0; }
r[3]=read(ram,0x0c0c95f0u,4);
goto P_0c0c959a;
P_0c0c959a: /* original 6df6, guest PC 0x0c0c959a */
if(!s->budget--) { s->failed_pc=0x0c0c959au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c959c;
P_0c0c959c: /* original 432b, guest PC 0x0c0c959c */
if(!s->budget--) { s->failed_pc=0x0c0c959cu; return 0; }
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
P_0c0c959e: /* original 6ef6, guest PC 0x0c0c959e */
if(!s->budget--) { s->failed_pc=0x0c0c959eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c95a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c95a0u; return 0; } return 1;
P_0c0c95f4: /* original 2fe6, guest PC 0x0c0c95f4 */
if(!s->budget--) { s->failed_pc=0x0c0c95f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95f6;
P_0c0c95f6: /* original e701, guest PC 0x0c0c95f6 */
if(!s->budget--) { s->failed_pc=0x0c0c95f6u; return 0; }
r[7]=0x00000001u;
goto P_0c0c95f8;
P_0c0c95f8: /* original 2fd6, guest PC 0x0c0c95f8 */
if(!s->budget--) { s->failed_pc=0x0c0c95f8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95fa;
P_0c0c95fa: /* original e603, guest PC 0x0c0c95fa */
if(!s->budget--) { s->failed_pc=0x0c0c95fau; return 0; }
r[6]=0x00000003u;
goto P_0c0c95fc;
P_0c0c95fc: /* original 2fc6, guest PC 0x0c0c95fc */
if(!s->budget--) { s->failed_pc=0x0c0c95fcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c95fe;
P_0c0c95fe: /* original ec00, guest PC 0x0c0c95fe */
if(!s->budget--) { s->failed_pc=0x0c0c95feu; return 0; }
r[12]=0x00000000u;
goto P_0c0c9600;
P_0c0c9600: /* original 2fb6, guest PC 0x0c0c9600 */
if(!s->budget--) { s->failed_pc=0x0c0c9600u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9602;
P_0c0c9602: /* original 2fa6, guest PC 0x0c0c9602 */
if(!s->budget--) { s->failed_pc=0x0c0c9602u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9604;
P_0c0c9604: /* original 2f96, guest PC 0x0c0c9604 */
if(!s->budget--) { s->failed_pc=0x0c0c9604u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9606;
P_0c0c9606: /* original 905c, guest PC 0x0c0c9606 */
if(!s->budget--) { s->failed_pc=0x0c0c9606u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c2u,2);
goto P_0c0c9608;
P_0c0c9608: /* original dd31, guest PC 0x0c0c9608 */
if(!s->budget--) { s->failed_pc=0x0c0c9608u; return 0; }
r[13]=read(ram,0x0c0c96d0u,4);
goto P_0c0c960a;
P_0c0c960a: /* original de32, guest PC 0x0c0c960a */
if(!s->budget--) { s->failed_pc=0x0c0c960au; return 0; }
r[14]=read(ram,0x0c0c96d4u,4);
goto P_0c0c960c;
P_0c0c960c: /* original 05de, guest PC 0x0c0c960c */
if(!s->budget--) { s->failed_pc=0x0c0c960cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c960e;
P_0c0c960e: /* original 905a, guest PC 0x0c0c960e */
if(!s->budget--) { s->failed_pc=0x0c0c960eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c6u,2);
goto P_0c0c9610;
P_0c0c9610: /* original 4f22, guest PC 0x0c0c9610 */
if(!s->budget--) { s->failed_pc=0x0c0c9610u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9612;
P_0c0c9612: /* original db32, guest PC 0x0c0c9612 */
if(!s->budget--) { s->failed_pc=0x0c0c9612u; return 0; }
r[11]=read(ram,0x0c0c96dcu,4);
goto P_0c0c9614;
P_0c0c9614: /* original d430, guest PC 0x0c0c9614 */
if(!s->budget--) { s->failed_pc=0x0c0c9614u; return 0; }
r[4]=read(ram,0x0c0c96d8u,4);
goto P_0c0c9616;
P_0c0c9616: /* original 00ec, guest PC 0x0c0c9616 */
if(!s->budget--) { s->failed_pc=0x0c0c9616u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9618;
P_0c0c9618: /* original 2b59, guest PC 0x0c0c9618 */
if(!s->budget--) { s->failed_pc=0x0c0c9618u; return 0; }
r[11]&=r[5];
goto P_0c0c961a;
P_0c0c961a: /* original 9a53, guest PC 0x0c0c961a */
if(!s->budget--) { s->failed_pc=0x0c0c961au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c4u,2);
goto P_0c0c961c;
P_0c0c961c: /* original 7ff8, guest PC 0x0c0c961c */
if(!s->budget--) { s->failed_pc=0x0c0c961cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c961e;
P_0c0c961e: /* original 8801, guest PC 0x0c0c961e */
if(!s->budget--) { s->failed_pc=0x0c0c961eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9620;
P_0c0c9620: /* original 2459, guest PC 0x0c0c9620 */
if(!s->budget--) { s->failed_pc=0x0c0c9620u; return 0; }
r[4]&=r[5];
goto P_0c0c9622;
P_0c0c9622: /* original 8d29, guest PC 0x0c0c9622 */
if(!s->budget--) { s->failed_pc=0x0c0c9622u; return 0; }
cond=r[17]&1u;
r[10]&=r[5];
if(cond) { goto P_0c0c9678; }
goto P_0c0c9626;
P_0c0c9624: /* original 2a59, guest PC 0x0c0c9624 */
if(!s->budget--) { s->failed_pc=0x0c0c9624u; return 0; }
r[10]&=r[5];
goto P_0c0c9626;
P_0c0c9626: /* original 8802, guest PC 0x0c0c9626 */
if(!s->budget--) { s->failed_pc=0x0c0c9626u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9628;
P_0c0c9628: /* original 8b01, guest PC 0x0c0c9628 */
if(!s->budget--) { s->failed_pc=0x0c0c9628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c962e; }
goto P_0c0c962a;
P_0c0c962a: /* original a115, guest PC 0x0c0c962a */
if(!s->budget--) { s->failed_pc=0x0c0c962au; return 0; }
goto P_0c0c9858;
P_0c0c962c: /* original 0009, guest PC 0x0c0c962c */
if(!s->budget--) { s->failed_pc=0x0c0c962cu; return 0; }
goto P_0c0c962e;
P_0c0c962e: /* original 8803, guest PC 0x0c0c962e */
if(!s->budget--) { s->failed_pc=0x0c0c962eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9630;
P_0c0c9630: /* original 8b01, guest PC 0x0c0c9630 */
if(!s->budget--) { s->failed_pc=0x0c0c9630u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9636; }
goto P_0c0c9632;
P_0c0c9632: /* original a111, guest PC 0x0c0c9632 */
if(!s->budget--) { s->failed_pc=0x0c0c9632u; return 0; }
goto P_0c0c9858;
P_0c0c9634: /* original 0009, guest PC 0x0c0c9634 */
if(!s->budget--) { s->failed_pc=0x0c0c9634u; return 0; }
goto P_0c0c9636;
P_0c0c9636: /* original 9047, guest PC 0x0c0c9636 */
if(!s->budget--) { s->failed_pc=0x0c0c9636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c8u,2);
goto P_0c0c9638;
P_0c0c9638: /* original 2448, guest PC 0x0c0c9638 */
if(!s->budget--) { s->failed_pc=0x0c0c9638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c963a;
P_0c0c963a: /* original 8f0d, guest PC 0x0c0c963a */
if(!s->budget--) { s->failed_pc=0x0c0c963au; return 0; }
cond=r[17]&1u;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(!cond) { goto P_0c0c9658; }
goto P_0c0c963e;
P_0c0c963c: /* original 05ec, guest PC 0x0c0c963c */
if(!s->budget--) { s->failed_pc=0x0c0c963cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c963e;
P_0c0c963e: /* original 2bb8, guest PC 0x0c0c963e */
if(!s->budget--) { s->failed_pc=0x0c0c963eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c9640;
P_0c0c9640: /* original 8b04, guest PC 0x0c0c9640 */
if(!s->budget--) { s->failed_pc=0x0c0c9640u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c964c; }
goto P_0c0c9642;
P_0c0c9642: /* original 2aa8, guest PC 0x0c0c9642 */
if(!s->budget--) { s->failed_pc=0x0c0c9642u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c9644;
P_0c0c9644: /* original 8f02, guest PC 0x0c0c9644 */
if(!s->budget--) { s->failed_pc=0x0c0c9644u; return 0; }
cond=r[17]&1u;
r[7]=0xffffffffu;
if(!cond) { goto P_0c0c964c; }
goto P_0c0c9648;
P_0c0c9646: /* original e7ff, guest PC 0x0c0c9646 */
if(!s->budget--) { s->failed_pc=0x0c0c9646u; return 0; }
r[7]=0xffffffffu;
goto P_0c0c9648;
P_0c0c9648: /* original a146, guest PC 0x0c0c9648 */
if(!s->budget--) { s->failed_pc=0x0c0c9648u; return 0; }
goto P_0c0c98d8;
P_0c0c964a: /* original 0009, guest PC 0x0c0c964a */
if(!s->budget--) { s->failed_pc=0x0c0c964au; return 0; }
goto P_0c0c964c;
P_0c0c964c: /* original 903d, guest PC 0x0c0c964c */
if(!s->budget--) { s->failed_pc=0x0c0c964cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96cau,2);
goto P_0c0c964e;
P_0c0c964e: /* original 6453, guest PC 0x0c0c964e */
if(!s->budget--) { s->failed_pc=0x0c0c964eu; return 0; }
r[4]=r[5];
goto P_0c0c9650;
P_0c0c9650: /* original 347c, guest PC 0x0c0c9650 */
if(!s->budget--) { s->failed_pc=0x0c0c9650u; return 0; }
r[4]+=r[7];
goto P_0c0c9652;
P_0c0c9652: /* original 0e54, guest PC 0x0c0c9652 */
if(!s->budget--) { s->failed_pc=0x0c0c9652u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9654;
P_0c0c9654: /* original a0bd, guest PC 0x0c0c9654 */
if(!s->budget--) { s->failed_pc=0x0c0c9654u; return 0; }
r[4]&=r[6];
goto P_0c0c97d2;
P_0c0c9656: /* original 2469, guest PC 0x0c0c9656 */
if(!s->budget--) { s->failed_pc=0x0c0c9656u; return 0; }
r[4]&=r[6];
goto P_0c0c9658;
P_0c0c9658: /* original 6053, guest PC 0x0c0c9658 */
if(!s->budget--) { s->failed_pc=0x0c0c9658u; return 0; }
r[0]=r[5];
goto P_0c0c965a;
P_0c0c965a: /* original 8800, guest PC 0x0c0c965a */
if(!s->budget--) { s->failed_pc=0x0c0c965au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c965c;
P_0c0c965c: /* original 8f02, guest PC 0x0c0c965c */
if(!s->budget--) { s->failed_pc=0x0c0c965cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000061u;
if(!cond) { goto P_0c0c9664; }
goto P_0c0c9660;
P_0c0c965e: /* original e461, guest PC 0x0c0c965e */
if(!s->budget--) { s->failed_pc=0x0c0c965eu; return 0; }
r[4]=0x00000061u;
goto P_0c0c9660;
P_0c0c9660: /* original a116, guest PC 0x0c0c9660 */
if(!s->budget--) { s->failed_pc=0x0c0c9660u; return 0; }
goto P_0c0c9890;
P_0c0c9662: /* original 0009, guest PC 0x0c0c9662 */
if(!s->budget--) { s->failed_pc=0x0c0c9662u; return 0; }
goto P_0c0c9664;
P_0c0c9664: /* original 8801, guest PC 0x0c0c9664 */
if(!s->budget--) { s->failed_pc=0x0c0c9664u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9666;
P_0c0c9666: /* original 8b01, guest PC 0x0c0c9666 */
if(!s->budget--) { s->failed_pc=0x0c0c9666u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c966c; }
goto P_0c0c9668;
P_0c0c9668: /* original a128, guest PC 0x0c0c9668 */
if(!s->budget--) { s->failed_pc=0x0c0c9668u; return 0; }
goto P_0c0c98bc;
P_0c0c966a: /* original 0009, guest PC 0x0c0c966a */
if(!s->budget--) { s->failed_pc=0x0c0c966au; return 0; }
goto P_0c0c966c;
P_0c0c966c: /* original 8802, guest PC 0x0c0c966c */
if(!s->budget--) { s->failed_pc=0x0c0c966cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c966e;
P_0c0c966e: /* original 8b01, guest PC 0x0c0c966e */
if(!s->budget--) { s->failed_pc=0x0c0c966eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9674; }
goto P_0c0c9670;
P_0c0c9670: /* original a12a, guest PC 0x0c0c9670 */
if(!s->budget--) { s->failed_pc=0x0c0c9670u; return 0; }
goto P_0c0c98c8;
P_0c0c9672: /* original 0009, guest PC 0x0c0c9672 */
if(!s->budget--) { s->failed_pc=0x0c0c9672u; return 0; }
goto P_0c0c9674;
P_0c0c9674: /* original a12e, guest PC 0x0c0c9674 */
if(!s->budget--) { s->failed_pc=0x0c0c9674u; return 0; }
goto P_0c0c98d4;
P_0c0c9676: /* original 0009, guest PC 0x0c0c9676 */
if(!s->budget--) { s->failed_pc=0x0c0c9676u; return 0; }
goto P_0c0c9678;
P_0c0c9678: /* original e310, guest PC 0x0c0c9678 */
if(!s->budget--) { s->failed_pc=0x0c0c9678u; return 0; }
r[3]=0x00000010u;
goto P_0c0c967a;
P_0c0c967a: /* original 9025, guest PC 0x0c0c967a */
if(!s->budget--) { s->failed_pc=0x0c0c967au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96c8u,2);
goto P_0c0c967c;
P_0c0c967c: /* original 2358, guest PC 0x0c0c967c */
if(!s->budget--) { s->failed_pc=0x0c0c967cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c967e;
P_0c0c967e: /* original 8d02, guest PC 0x0c0c967e */
if(!s->budget--) { s->failed_pc=0x0c0c967eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
if(cond) { goto P_0c0c9686; }
goto P_0c0c9682;
P_0c0c9680: /* original 04ec, guest PC 0x0c0c9680 */
if(!s->budget--) { s->failed_pc=0x0c0c9680u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9682;
P_0c0c9682: /* original a0eb, guest PC 0x0c0c9682 */
if(!s->budget--) { s->failed_pc=0x0c0c9682u; return 0; }
goto P_0c0c985c;
P_0c0c9684: /* original 0009, guest PC 0x0c0c9684 */
if(!s->budget--) { s->failed_pc=0x0c0c9684u; return 0; }
goto P_0c0c9686;
P_0c0c9686: /* original 2bb8, guest PC 0x0c0c9686 */
if(!s->budget--) { s->failed_pc=0x0c0c9686u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c9688;
P_0c0c9688: /* original 8f32, guest PC 0x0c0c9688 */
if(!s->budget--) { s->failed_pc=0x0c0c9688u; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(!cond) { goto P_0c0c96f0; }
goto P_0c0c968c;
P_0c0c968a: /* original 6973, guest PC 0x0c0c968a */
if(!s->budget--) { s->failed_pc=0x0c0c968au; return 0; }
r[9]=r[7];
goto P_0c0c968c;
P_0c0c968c: /* original 2aa8, guest PC 0x0c0c968c */
if(!s->budget--) { s->failed_pc=0x0c0c968cu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c968e;
P_0c0c968e: /* original 8f2f, guest PC 0x0c0c968e */
if(!s->budget--) { s->failed_pc=0x0c0c968eu; return 0; }
cond=r[17]&1u;
r[9]=0xffffffffu;
if(!cond) { goto P_0c0c96f0; }
goto P_0c0c9692;
P_0c0c9690: /* original e9ff, guest PC 0x0c0c9690 */
if(!s->budget--) { s->failed_pc=0x0c0c9690u; return 0; }
r[9]=0xffffffffu;
goto P_0c0c9692;
P_0c0c9692: /* original 901b, guest PC 0x0c0c9692 */
if(!s->budget--) { s->failed_pc=0x0c0c9692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c96ccu,2);
goto P_0c0c9694;
P_0c0c9694: /* original d312, guest PC 0x0c0c9694 */
if(!s->budget--) { s->failed_pc=0x0c0c9694u; return 0; }
r[3]=read(ram,0x0c0c96e0u,4);
goto P_0c0c9696;
P_0c0c9696: /* original 06de, guest PC 0x0c0c9696 */
if(!s->budget--) { s->failed_pc=0x0c0c9696u; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c0c9698;
P_0c0c9698: /* original 2638, guest PC 0x0c0c9698 */
if(!s->budget--) { s->failed_pc=0x0c0c9698u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0c969a;
P_0c0c969a: /* original 8b0b, guest PC 0x0c0c969a */
if(!s->budget--) { s->failed_pc=0x0c0c969au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c96b4; }
goto P_0c0c969c;
P_0c0c969c: /* original d211, guest PC 0x0c0c969c */
if(!s->budget--) { s->failed_pc=0x0c0c969cu; return 0; }
r[2]=read(ram,0x0c0c96e4u,4);
goto P_0c0c969e;
P_0c0c969e: /* original 2258, guest PC 0x0c0c969e */
if(!s->budget--) { s->failed_pc=0x0c0c969eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c96a0;
P_0c0c96a0: /* original 8901, guest PC 0x0c0c96a0 */
if(!s->budget--) { s->failed_pc=0x0c0c96a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96a6; }
goto P_0c0c96a2;
P_0c0c96a2: /* original a099, guest PC 0x0c0c96a2 */
if(!s->budget--) { s->failed_pc=0x0c0c96a2u; return 0; }
goto P_0c0c97d8;
P_0c0c96a4: /* original 0009, guest PC 0x0c0c96a4 */
if(!s->budget--) { s->failed_pc=0x0c0c96a4u; return 0; }
goto P_0c0c96a6;
P_0c0c96a6: /* original d310, guest PC 0x0c0c96a6 */
if(!s->budget--) { s->failed_pc=0x0c0c96a6u; return 0; }
r[3]=read(ram,0x0c0c96e8u,4);
goto P_0c0c96a8;
P_0c0c96a8: /* original 2538, guest PC 0x0c0c96a8 */
if(!s->budget--) { s->failed_pc=0x0c0c96a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c96aa;
P_0c0c96aa: /* original 8901, guest PC 0x0c0c96aa */
if(!s->budget--) { s->failed_pc=0x0c0c96aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96b0; }
goto P_0c0c96ac;
P_0c0c96ac: /* original a08c, guest PC 0x0c0c96ac */
if(!s->budget--) { s->failed_pc=0x0c0c96acu; return 0; }
goto P_0c0c97c8;
P_0c0c96ae: /* original 0009, guest PC 0x0c0c96ae */
if(!s->budget--) { s->failed_pc=0x0c0c96aeu; return 0; }
goto P_0c0c96b0;
P_0c0c96b0: /* original a112, guest PC 0x0c0c96b0 */
if(!s->budget--) { s->failed_pc=0x0c0c96b0u; return 0; }
goto P_0c0c98d8;
P_0c0c96b2: /* original 0009, guest PC 0x0c0c96b2 */
if(!s->budget--) { s->failed_pc=0x0c0c96b2u; return 0; }
goto P_0c0c96b4;
P_0c0c96b4: /* original d10d, guest PC 0x0c0c96b4 */
if(!s->budget--) { s->failed_pc=0x0c0c96b4u; return 0; }
r[1]=read(ram,0x0c0c96ecu,4);
goto P_0c0c96b6;
P_0c0c96b6: /* original 2518, guest PC 0x0c0c96b6 */
if(!s->budget--) { s->failed_pc=0x0c0c96b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c96b8;
P_0c0c96b8: /* original 8901, guest PC 0x0c0c96b8 */
if(!s->budget--) { s->failed_pc=0x0c0c96b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c96be; }
goto P_0c0c96ba;
P_0c0c96ba: /* original a0cf, guest PC 0x0c0c96ba */
if(!s->budget--) { s->failed_pc=0x0c0c96bau; return 0; }
goto P_0c0c985c;
P_0c0c96bc: /* original 0009, guest PC 0x0c0c96bc */
if(!s->budget--) { s->failed_pc=0x0c0c96bcu; return 0; }
goto P_0c0c96be;
P_0c0c96be: /* original a10b, guest PC 0x0c0c96be */
if(!s->budget--) { s->failed_pc=0x0c0c96beu; return 0; }
goto P_0c0c98d8;
P_0c0c96c0: /* original 0009, guest PC 0x0c0c96c0 */
if(!s->budget--) { s->failed_pc=0x0c0c96c0u; return 0; }
if(!vf3_matrix_family(0x0c0c96c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c96c2u; return 0; } return 1;
P_0c0c96f0: /* original 6043, guest PC 0x0c0c96f0 */
if(!s->budget--) { s->failed_pc=0x0c0c96f0u; return 0; }
r[0]=r[4];
goto P_0c0c96f2;
P_0c0c96f2: /* original 8800, guest PC 0x0c0c96f2 */
if(!s->budget--) { s->failed_pc=0x0c0c96f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c96f4;
P_0c0c96f4: /* original 890b, guest PC 0x0c0c96f4 */
if(!s->budget--) { s->failed_pc=0x0c0c96f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c970e; }
goto P_0c0c96f6;
P_0c0c96f6: /* original 8801, guest PC 0x0c0c96f6 */
if(!s->budget--) { s->failed_pc=0x0c0c96f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c96f8;
P_0c0c96f8: /* original 890c, guest PC 0x0c0c96f8 */
if(!s->budget--) { s->failed_pc=0x0c0c96f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9714; }
goto P_0c0c96fa;
P_0c0c96fa: /* original 8802, guest PC 0x0c0c96fa */
if(!s->budget--) { s->failed_pc=0x0c0c96fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c96fc;
P_0c0c96fc: /* original 890d, guest PC 0x0c0c96fc */
if(!s->budget--) { s->failed_pc=0x0c0c96fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c971a; }
goto P_0c0c96fe;
P_0c0c96fe: /* original 8803, guest PC 0x0c0c96fe */
if(!s->budget--) { s->failed_pc=0x0c0c96feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9700;
P_0c0c9700: /* original 890e, guest PC 0x0c0c9700 */
if(!s->budget--) { s->failed_pc=0x0c0c9700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9720; }
goto P_0c0c9702;
P_0c0c9702: /* original 8804, guest PC 0x0c0c9702 */
if(!s->budget--) { s->failed_pc=0x0c0c9702u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9704;
P_0c0c9704: /* original 890f, guest PC 0x0c0c9704 */
if(!s->budget--) { s->failed_pc=0x0c0c9704u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9726; }
goto P_0c0c9706;
P_0c0c9706: /* original 8805, guest PC 0x0c0c9706 */
if(!s->budget--) { s->failed_pc=0x0c0c9706u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c9708;
P_0c0c9708: /* original 8910, guest PC 0x0c0c9708 */
if(!s->budget--) { s->failed_pc=0x0c0c9708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c972c; }
goto P_0c0c970a;
P_0c0c970a: /* original a011, guest PC 0x0c0c970a */
if(!s->budget--) { s->failed_pc=0x0c0c970au; return 0; }
goto P_0c0c9730;
P_0c0c970c: /* original 0009, guest PC 0x0c0c970c */
if(!s->budget--) { s->failed_pc=0x0c0c970cu; return 0; }
goto P_0c0c970e;
P_0c0c970e: /* original 9045, guest PC 0x0c0c970e */
if(!s->budget--) { s->failed_pc=0x0c0c970eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9710;
P_0c0c9710: /* original a00d, guest PC 0x0c0c9710 */
if(!s->budget--) { s->failed_pc=0x0c0c9710u; return 0; }
goto P_0c0c972e;
P_0c0c9712: /* original 0009, guest PC 0x0c0c9712 */
if(!s->budget--) { s->failed_pc=0x0c0c9712u; return 0; }
goto P_0c0c9714;
P_0c0c9714: /* original 9043, guest PC 0x0c0c9714 */
if(!s->budget--) { s->failed_pc=0x0c0c9714u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9716;
P_0c0c9716: /* original a00a, guest PC 0x0c0c9716 */
if(!s->budget--) { s->failed_pc=0x0c0c9716u; return 0; }
goto P_0c0c972e;
P_0c0c9718: /* original 0009, guest PC 0x0c0c9718 */
if(!s->budget--) { s->failed_pc=0x0c0c9718u; return 0; }
goto P_0c0c971a;
P_0c0c971a: /* original 9041, guest PC 0x0c0c971a */
if(!s->budget--) { s->failed_pc=0x0c0c971au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a0u,2);
goto P_0c0c971c;
P_0c0c971c: /* original a007, guest PC 0x0c0c971c */
if(!s->budget--) { s->failed_pc=0x0c0c971cu; return 0; }
goto P_0c0c972e;
P_0c0c971e: /* original 0009, guest PC 0x0c0c971e */
if(!s->budget--) { s->failed_pc=0x0c0c971eu; return 0; }
goto P_0c0c9720;
P_0c0c9720: /* original 903f, guest PC 0x0c0c9720 */
if(!s->budget--) { s->failed_pc=0x0c0c9720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a2u,2);
goto P_0c0c9722;
P_0c0c9722: /* original a004, guest PC 0x0c0c9722 */
if(!s->budget--) { s->failed_pc=0x0c0c9722u; return 0; }
goto P_0c0c972e;
P_0c0c9724: /* original 0009, guest PC 0x0c0c9724 */
if(!s->budget--) { s->failed_pc=0x0c0c9724u; return 0; }
goto P_0c0c9726;
P_0c0c9726: /* original 903d, guest PC 0x0c0c9726 */
if(!s->budget--) { s->failed_pc=0x0c0c9726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a4u,2);
goto P_0c0c9728;
P_0c0c9728: /* original a001, guest PC 0x0c0c9728 */
if(!s->budget--) { s->failed_pc=0x0c0c9728u; return 0; }
goto P_0c0c972e;
P_0c0c972a: /* original 0009, guest PC 0x0c0c972a */
if(!s->budget--) { s->failed_pc=0x0c0c972au; return 0; }
goto P_0c0c972c;
P_0c0c972c: /* original 903b, guest PC 0x0c0c972c */
if(!s->budget--) { s->failed_pc=0x0c0c972cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c97a6u,2);
goto P_0c0c972e;
P_0c0c972e: /* original 05ec, guest PC 0x0c0c972e */
if(!s->budget--) { s->failed_pc=0x0c0c972eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9730;
P_0c0c9730: /* original 6d43, guest PC 0x0c0c9730 */
if(!s->budget--) { s->failed_pc=0x0c0c9730u; return 0; }
r[13]=r[4];
goto P_0c0c9732;
P_0c0c9732: /* original 4d08, guest PC 0x0c0c9732 */
if(!s->budget--) { s->failed_pc=0x0c0c9732u; return 0; }
r[13]<<=2;
goto P_0c0c9734;
P_0c0c9734: /* original 2fd2, guest PC 0x0c0c9734 */
if(!s->budget--) { s->failed_pc=0x0c0c9734u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0c9736;
P_0c0c9736: /* original d01c, guest PC 0x0c0c9736 */
if(!s->budget--) { s->failed_pc=0x0c0c9736u; return 0; }
r[0]=read(ram,0x0c0c97a8u,4);
goto P_0c0c9738;
P_0c0c9738: /* original 0dde, guest PC 0x0c0c9738 */
if(!s->budget--) { s->failed_pc=0x0c0c9738u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0c973a;
P_0c0c973a: /* original 6043, guest PC 0x0c0c973a */
if(!s->budget--) { s->failed_pc=0x0c0c973au; return 0; }
r[0]=r[4];
goto P_0c0c973c;
P_0c0c973c: /* original 8802, guest PC 0x0c0c973c */
if(!s->budget--) { s->failed_pc=0x0c0c973cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c973e;
P_0c0c973e: /* original 8b0c, guest PC 0x0c0c973e */
if(!s->budget--) { s->failed_pc=0x0c0c973eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975a; }
goto P_0c0c9740;
P_0c0c9740: /* original 902d, guest PC 0x0c0c9740 */
if(!s->budget--) { s->failed_pc=0x0c0c9740u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9742;
P_0c0c9742: /* original 00ec, guest PC 0x0c0c9742 */
if(!s->budget--) { s->failed_pc=0x0c0c9742u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9744;
P_0c0c9744: /* original 80f4, guest PC 0x0c0c9744 */
if(!s->budget--) { s->failed_pc=0x0c0c9744u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0c9746;
P_0c0c9746: /* original 07dc, guest PC 0x0c0c9746 */
if(!s->budget--) { s->failed_pc=0x0c0c9746u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0c9748;
P_0c0c9748: /* original 84f4, guest PC 0x0c0c9748 */
if(!s->budget--) { s->failed_pc=0x0c0c9748u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0c974a;
P_0c0c974a: /* original 8802, guest PC 0x0c0c974a */
if(!s->budget--) { s->failed_pc=0x0c0c974au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c974c;
P_0c0c974c: /* original 8b06, guest PC 0x0c0c974c */
if(!s->budget--) { s->failed_pc=0x0c0c974cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975c; }
goto P_0c0c974e;
P_0c0c974e: /* original 9025, guest PC 0x0c0c974e */
if(!s->budget--) { s->failed_pc=0x0c0c974eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9750;
P_0c0c9750: /* original 03ec, guest PC 0x0c0c9750 */
if(!s->budget--) { s->failed_pc=0x0c0c9750u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9752;
P_0c0c9752: /* original 2368, guest PC 0x0c0c9752 */
if(!s->budget--) { s->failed_pc=0x0c0c9752u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c9754;
P_0c0c9754: /* original 8b02, guest PC 0x0c0c9754 */
if(!s->budget--) { s->failed_pc=0x0c0c9754u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c975c; }
goto P_0c0c9756;
P_0c0c9756: /* original a001, guest PC 0x0c0c9756 */
if(!s->budget--) { s->failed_pc=0x0c0c9756u; return 0; }
r[7]+=0x00000001u;
goto P_0c0c975c;
P_0c0c9758: /* original 7701, guest PC 0x0c0c9758 */
if(!s->budget--) { s->failed_pc=0x0c0c9758u; return 0; }
r[7]+=0x00000001u;
goto P_0c0c975a;
P_0c0c975a: /* original 67d0, guest PC 0x0c0c975a */
if(!s->budget--) { s->failed_pc=0x0c0c975au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[7]=tmp;
goto P_0c0c975c;
P_0c0c975c: /* original d013, guest PC 0x0c0c975c */
if(!s->budget--) { s->failed_pc=0x0c0c975cu; return 0; }
r[0]=read(ram,0x0c0c97acu,4);
goto P_0c0c975e;
P_0c0c975e: /* original 359c, guest PC 0x0c0c975e */
if(!s->budget--) { s->failed_pc=0x0c0c975eu; return 0; }
r[5]+=r[9];
goto P_0c0c9760;
P_0c0c9760: /* original 62f2, guest PC 0x0c0c9760 */
if(!s->budget--) { s->failed_pc=0x0c0c9760u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c9762;
P_0c0c9762: /* original 3577, guest PC 0x0c0c9762 */
if(!s->budget--) { s->failed_pc=0x0c0c9762u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[7])!=0);
goto P_0c0c9764;
P_0c0c9764: /* original 062e, guest PC 0x0c0c9764 */
if(!s->budget--) { s->failed_pc=0x0c0c9764u; return 0; }
r[6]=read(ram,r[2]+r[0],4);
goto P_0c0c9766;
P_0c0c9766: /* original 8f01, guest PC 0x0c0c9766 */
if(!s->budget--) { s->failed_pc=0x0c0c9766u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
if(!cond) { goto P_0c0c976c; }
goto P_0c0c976a;
P_0c0c9768: /* original 6660, guest PC 0x0c0c9768 */
if(!s->budget--) { s->failed_pc=0x0c0c9768u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c0c976a;
P_0c0c976a: /* original 6563, guest PC 0x0c0c976a */
if(!s->budget--) { s->failed_pc=0x0c0c976au; return 0; }
r[5]=r[6];
goto P_0c0c976c;
P_0c0c976c: /* original 3563, guest PC 0x0c0c976c */
if(!s->budget--) { s->failed_pc=0x0c0c976cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0c976e;
P_0c0c976e: /* original 8d01, guest PC 0x0c0c976e */
if(!s->budget--) { s->failed_pc=0x0c0c976eu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c0c9774; }
goto P_0c0c9772;
P_0c0c9770: /* original 6043, guest PC 0x0c0c9770 */
if(!s->budget--) { s->failed_pc=0x0c0c9770u; return 0; }
r[0]=r[4];
goto P_0c0c9772;
P_0c0c9772: /* original 6573, guest PC 0x0c0c9772 */
if(!s->budget--) { s->failed_pc=0x0c0c9772u; return 0; }
r[5]=r[7];
goto P_0c0c9774;
P_0c0c9774: /* original 8800, guest PC 0x0c0c9774 */
if(!s->budget--) { s->failed_pc=0x0c0c9774u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c9776;
P_0c0c9776: /* original 890b, guest PC 0x0c0c9776 */
if(!s->budget--) { s->failed_pc=0x0c0c9776u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9790; }
goto P_0c0c9778;
P_0c0c9778: /* original 8801, guest PC 0x0c0c9778 */
if(!s->budget--) { s->failed_pc=0x0c0c9778u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c977a;
P_0c0c977a: /* original 890c, guest PC 0x0c0c977a */
if(!s->budget--) { s->failed_pc=0x0c0c977au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9796; }
goto P_0c0c977c;
P_0c0c977c: /* original 8802, guest PC 0x0c0c977c */
if(!s->budget--) { s->failed_pc=0x0c0c977cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c977e;
P_0c0c977e: /* original 8917, guest PC 0x0c0c977e */
if(!s->budget--) { s->failed_pc=0x0c0c977eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97b0; }
goto P_0c0c9780;
P_0c0c9780: /* original 8803, guest PC 0x0c0c9780 */
if(!s->budget--) { s->failed_pc=0x0c0c9780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9782;
P_0c0c9782: /* original 8918, guest PC 0x0c0c9782 */
if(!s->budget--) { s->failed_pc=0x0c0c9782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97b6; }
goto P_0c0c9784;
P_0c0c9784: /* original 8804, guest PC 0x0c0c9784 */
if(!s->budget--) { s->failed_pc=0x0c0c9784u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9786;
P_0c0c9786: /* original 8919, guest PC 0x0c0c9786 */
if(!s->budget--) { s->failed_pc=0x0c0c9786u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97bc; }
goto P_0c0c9788;
P_0c0c9788: /* original 8805, guest PC 0x0c0c9788 */
if(!s->budget--) { s->failed_pc=0x0c0c9788u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c978a;
P_0c0c978a: /* original 891a, guest PC 0x0c0c978a */
if(!s->budget--) { s->failed_pc=0x0c0c978au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c97c2; }
goto P_0c0c978c;
P_0c0c978c: /* original a0a4, guest PC 0x0c0c978c */
if(!s->budget--) { s->failed_pc=0x0c0c978cu; return 0; }
goto P_0c0c98d8;
P_0c0c978e: /* original 0009, guest PC 0x0c0c978e */
if(!s->budget--) { s->failed_pc=0x0c0c978eu; return 0; }
goto P_0c0c9790;
P_0c0c9790: /* original 9004, guest PC 0x0c0c9790 */
if(!s->budget--) { s->failed_pc=0x0c0c9790u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979cu,2);
goto P_0c0c9792;
P_0c0c9792: /* original a017, guest PC 0x0c0c9792 */
if(!s->budget--) { s->failed_pc=0x0c0c9792u; return 0; }
goto P_0c0c97c4;
P_0c0c9794: /* original 0009, guest PC 0x0c0c9794 */
if(!s->budget--) { s->failed_pc=0x0c0c9794u; return 0; }
goto P_0c0c9796;
P_0c0c9796: /* original 9002, guest PC 0x0c0c9796 */
if(!s->budget--) { s->failed_pc=0x0c0c9796u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c979eu,2);
goto P_0c0c9798;
P_0c0c9798: /* original a014, guest PC 0x0c0c9798 */
if(!s->budget--) { s->failed_pc=0x0c0c9798u; return 0; }
goto P_0c0c97c4;
P_0c0c979a: /* original 0009, guest PC 0x0c0c979a */
if(!s->budget--) { s->failed_pc=0x0c0c979au; return 0; }
if(!vf3_matrix_family(0x0c0c979cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c979cu; return 0; } return 1;
P_0c0c97b0: /* original 9061, guest PC 0x0c0c97b0 */
if(!s->budget--) { s->failed_pc=0x0c0c97b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9876u,2);
goto P_0c0c97b2;
P_0c0c97b2: /* original a007, guest PC 0x0c0c97b2 */
if(!s->budget--) { s->failed_pc=0x0c0c97b2u; return 0; }
goto P_0c0c97c4;
P_0c0c97b4: /* original 0009, guest PC 0x0c0c97b4 */
if(!s->budget--) { s->failed_pc=0x0c0c97b4u; return 0; }
goto P_0c0c97b6;
P_0c0c97b6: /* original 905f, guest PC 0x0c0c97b6 */
if(!s->budget--) { s->failed_pc=0x0c0c97b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9878u,2);
goto P_0c0c97b8;
P_0c0c97b8: /* original a004, guest PC 0x0c0c97b8 */
if(!s->budget--) { s->failed_pc=0x0c0c97b8u; return 0; }
goto P_0c0c97c4;
P_0c0c97ba: /* original 0009, guest PC 0x0c0c97ba */
if(!s->budget--) { s->failed_pc=0x0c0c97bau; return 0; }
goto P_0c0c97bc;
P_0c0c97bc: /* original 905d, guest PC 0x0c0c97bc */
if(!s->budget--) { s->failed_pc=0x0c0c97bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987au,2);
goto P_0c0c97be;
P_0c0c97be: /* original a001, guest PC 0x0c0c97be */
if(!s->budget--) { s->failed_pc=0x0c0c97beu; return 0; }
goto P_0c0c97c4;
P_0c0c97c0: /* original 0009, guest PC 0x0c0c97c0 */
if(!s->budget--) { s->failed_pc=0x0c0c97c0u; return 0; }
goto P_0c0c97c2;
P_0c0c97c2: /* original 905b, guest PC 0x0c0c97c2 */
if(!s->budget--) { s->failed_pc=0x0c0c97c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c97c4;
P_0c0c97c4: /* original a088, guest PC 0x0c0c97c4 */
if(!s->budget--) { s->failed_pc=0x0c0c97c4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c98d8;
P_0c0c97c6: /* original 0e54, guest PC 0x0c0c97c6 */
if(!s->budget--) { s->failed_pc=0x0c0c97c6u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c97c8;
P_0c0c97c8: /* original 9059, guest PC 0x0c0c97c8 */
if(!s->budget--) { s->failed_pc=0x0c0c97c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987eu,2);
goto P_0c0c97ca;
P_0c0c97ca: /* original 4415, guest PC 0x0c0c97ca */
if(!s->budget--) { s->failed_pc=0x0c0c97cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c97cc;
P_0c0c97cc: /* original 8f46, guest PC 0x0c0c97cc */
if(!s->budget--) { s->failed_pc=0x0c0c97ccu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],1);
if(!cond) { goto P_0c0c985c; }
goto P_0c0c97d0;
P_0c0c97ce: /* original 0e44, guest PC 0x0c0c97ce */
if(!s->budget--) { s->failed_pc=0x0c0c97ceu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97d0;
P_0c0c97d0: /* original 74ff, guest PC 0x0c0c97d0 */
if(!s->budget--) { s->failed_pc=0x0c0c97d0u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c97d2;
P_0c0c97d2: /* original 9055, guest PC 0x0c0c97d2 */
if(!s->budget--) { s->failed_pc=0x0c0c97d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9880u,2);
goto P_0c0c97d4;
P_0c0c97d4: /* original a080, guest PC 0x0c0c97d4 */
if(!s->budget--) { s->failed_pc=0x0c0c97d4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c98d8;
P_0c0c97d6: /* original 0e44, guest PC 0x0c0c97d6 */
if(!s->budget--) { s->failed_pc=0x0c0c97d6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97d8;
P_0c0c97d8: /* original e305, guest PC 0x0c0c97d8 */
if(!s->budget--) { s->failed_pc=0x0c0c97d8u; return 0; }
r[3]=0x00000005u;
goto P_0c0c97da;
P_0c0c97da: /* original 9050, guest PC 0x0c0c97da */
if(!s->budget--) { s->failed_pc=0x0c0c97dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987eu,2);
goto P_0c0c97dc;
P_0c0c97dc: /* original 3433, guest PC 0x0c0c97dc */
if(!s->budget--) { s->failed_pc=0x0c0c97dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c97de;
P_0c0c97de: /* original 8d29, guest PC 0x0c0c97de */
if(!s->budget--) { s->failed_pc=0x0c0c97deu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],1);
if(cond) { goto P_0c0c9834; }
goto P_0c0c97e2;
P_0c0c97e0: /* original 0e44, guest PC 0x0c0c97e0 */
if(!s->budget--) { s->failed_pc=0x0c0c97e0u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97e2;
P_0c0c97e2: /* original 904d, guest PC 0x0c0c97e2 */
if(!s->budget--) { s->failed_pc=0x0c0c97e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9880u,2);
goto P_0c0c97e4;
P_0c0c97e4: /* original 7401, guest PC 0x0c0c97e4 */
if(!s->budget--) { s->failed_pc=0x0c0c97e4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c97e6;
P_0c0c97e6: /* original 6543, guest PC 0x0c0c97e6 */
if(!s->budget--) { s->failed_pc=0x0c0c97e6u; return 0; }
r[5]=r[4];
goto P_0c0c97e8;
P_0c0c97e8: /* original 4508, guest PC 0x0c0c97e8 */
if(!s->budget--) { s->failed_pc=0x0c0c97e8u; return 0; }
r[5]<<=2;
goto P_0c0c97ea;
P_0c0c97ea: /* original 0e44, guest PC 0x0c0c97ea */
if(!s->budget--) { s->failed_pc=0x0c0c97eau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c97ec;
P_0c0c97ec: /* original d026, guest PC 0x0c0c97ec */
if(!s->budget--) { s->failed_pc=0x0c0c97ecu; return 0; }
r[0]=read(ram,0x0c0c9888u,4);
goto P_0c0c97ee;
P_0c0c97ee: /* original 055e, guest PC 0x0c0c97ee */
if(!s->budget--) { s->failed_pc=0x0c0c97eeu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c97f0;
P_0c0c97f0: /* original 6043, guest PC 0x0c0c97f0 */
if(!s->budget--) { s->failed_pc=0x0c0c97f0u; return 0; }
r[0]=r[4];
goto P_0c0c97f2;
P_0c0c97f2: /* original 8800, guest PC 0x0c0c97f2 */
if(!s->budget--) { s->failed_pc=0x0c0c97f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c97f4;
P_0c0c97f4: /* original 8d0c, guest PC 0x0c0c97f4 */
if(!s->budget--) { s->failed_pc=0x0c0c97f4u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
if(cond) { goto P_0c0c9810; }
goto P_0c0c97f8;
P_0c0c97f6: /* original 6550, guest PC 0x0c0c97f6 */
if(!s->budget--) { s->failed_pc=0x0c0c97f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0c97f8;
P_0c0c97f8: /* original 8801, guest PC 0x0c0c97f8 */
if(!s->budget--) { s->failed_pc=0x0c0c97f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c97fa;
P_0c0c97fa: /* original 890c, guest PC 0x0c0c97fa */
if(!s->budget--) { s->failed_pc=0x0c0c97fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9816; }
goto P_0c0c97fc;
P_0c0c97fc: /* original 8802, guest PC 0x0c0c97fc */
if(!s->budget--) { s->failed_pc=0x0c0c97fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c97fe;
P_0c0c97fe: /* original 890d, guest PC 0x0c0c97fe */
if(!s->budget--) { s->failed_pc=0x0c0c97feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c981c; }
goto P_0c0c9800;
P_0c0c9800: /* original 8803, guest PC 0x0c0c9800 */
if(!s->budget--) { s->failed_pc=0x0c0c9800u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c9802;
P_0c0c9802: /* original 890e, guest PC 0x0c0c9802 */
if(!s->budget--) { s->failed_pc=0x0c0c9802u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9822; }
goto P_0c0c9804;
P_0c0c9804: /* original 8804, guest PC 0x0c0c9804 */
if(!s->budget--) { s->failed_pc=0x0c0c9804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c9806;
P_0c0c9806: /* original 890f, guest PC 0x0c0c9806 */
if(!s->budget--) { s->failed_pc=0x0c0c9806u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9828; }
goto P_0c0c9808;
P_0c0c9808: /* original 8805, guest PC 0x0c0c9808 */
if(!s->budget--) { s->failed_pc=0x0c0c9808u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c980a;
P_0c0c980a: /* original 8910, guest PC 0x0c0c980a */
if(!s->budget--) { s->failed_pc=0x0c0c980au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c982e; }
goto P_0c0c980c;
P_0c0c980c: /* original a064, guest PC 0x0c0c980c */
if(!s->budget--) { s->failed_pc=0x0c0c980cu; return 0; }
goto P_0c0c98d8;
P_0c0c980e: /* original 0009, guest PC 0x0c0c980e */
if(!s->budget--) { s->failed_pc=0x0c0c980eu; return 0; }
goto P_0c0c9810;
P_0c0c9810: /* original 9037, guest PC 0x0c0c9810 */
if(!s->budget--) { s->failed_pc=0x0c0c9810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9882u,2);
goto P_0c0c9812;
P_0c0c9812: /* original a00d, guest PC 0x0c0c9812 */
if(!s->budget--) { s->failed_pc=0x0c0c9812u; return 0; }
goto P_0c0c9830;
P_0c0c9814: /* original 0009, guest PC 0x0c0c9814 */
if(!s->budget--) { s->failed_pc=0x0c0c9814u; return 0; }
goto P_0c0c9816;
P_0c0c9816: /* original 9035, guest PC 0x0c0c9816 */
if(!s->budget--) { s->failed_pc=0x0c0c9816u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9884u,2);
goto P_0c0c9818;
P_0c0c9818: /* original a00a, guest PC 0x0c0c9818 */
if(!s->budget--) { s->failed_pc=0x0c0c9818u; return 0; }
goto P_0c0c9830;
P_0c0c981a: /* original 0009, guest PC 0x0c0c981a */
if(!s->budget--) { s->failed_pc=0x0c0c981au; return 0; }
goto P_0c0c981c;
P_0c0c981c: /* original 902b, guest PC 0x0c0c981c */
if(!s->budget--) { s->failed_pc=0x0c0c981cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9876u,2);
goto P_0c0c981e;
P_0c0c981e: /* original a007, guest PC 0x0c0c981e */
if(!s->budget--) { s->failed_pc=0x0c0c981eu; return 0; }
goto P_0c0c9830;
P_0c0c9820: /* original 0009, guest PC 0x0c0c9820 */
if(!s->budget--) { s->failed_pc=0x0c0c9820u; return 0; }
goto P_0c0c9822;
P_0c0c9822: /* original 9029, guest PC 0x0c0c9822 */
if(!s->budget--) { s->failed_pc=0x0c0c9822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9878u,2);
goto P_0c0c9824;
P_0c0c9824: /* original a004, guest PC 0x0c0c9824 */
if(!s->budget--) { s->failed_pc=0x0c0c9824u; return 0; }
goto P_0c0c9830;
P_0c0c9826: /* original 0009, guest PC 0x0c0c9826 */
if(!s->budget--) { s->failed_pc=0x0c0c9826u; return 0; }
goto P_0c0c9828;
P_0c0c9828: /* original 9027, guest PC 0x0c0c9828 */
if(!s->budget--) { s->failed_pc=0x0c0c9828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987au,2);
goto P_0c0c982a;
P_0c0c982a: /* original a001, guest PC 0x0c0c982a */
if(!s->budget--) { s->failed_pc=0x0c0c982au; return 0; }
goto P_0c0c9830;
P_0c0c982c: /* original 0009, guest PC 0x0c0c982c */
if(!s->budget--) { s->failed_pc=0x0c0c982cu; return 0; }
goto P_0c0c982e;
P_0c0c982e: /* original 9025, guest PC 0x0c0c982e */
if(!s->budget--) { s->failed_pc=0x0c0c982eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c9830;
P_0c0c9830: /* original a052, guest PC 0x0c0c9830 */
if(!s->budget--) { s->failed_pc=0x0c0c9830u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c98d8;
P_0c0c9832: /* original 0e54, guest PC 0x0c0c9832 */
if(!s->budget--) { s->failed_pc=0x0c0c9832u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0c9834;
P_0c0c9834: /* original 9022, guest PC 0x0c0c9834 */
if(!s->budget--) { s->failed_pc=0x0c0c9834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c987cu,2);
goto P_0c0c9836;
P_0c0c9836: /* original 03ec, guest PC 0x0c0c9836 */
if(!s->budget--) { s->failed_pc=0x0c0c9836u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9838;
P_0c0c9838: /* original 70ff, guest PC 0x0c0c9838 */
if(!s->budget--) { s->failed_pc=0x0c0c9838u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c983a;
P_0c0c983a: /* original 2f36, guest PC 0x0c0c983a */
if(!s->budget--) { s->failed_pc=0x0c0c983au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c983c;
P_0c0c983c: /* original 02ec, guest PC 0x0c0c983c */
if(!s->budget--) { s->failed_pc=0x0c0c983cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c983e;
P_0c0c983e: /* original 70ff, guest PC 0x0c0c983e */
if(!s->budget--) { s->failed_pc=0x0c0c983eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9840;
P_0c0c9840: /* original 2f26, guest PC 0x0c0c9840 */
if(!s->budget--) { s->failed_pc=0x0c0c9840u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9842;
P_0c0c9842: /* original 07ec, guest PC 0x0c0c9842 */
if(!s->budget--) { s->failed_pc=0x0c0c9842u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9844;
P_0c0c9844: /* original 70ff, guest PC 0x0c0c9844 */
if(!s->budget--) { s->failed_pc=0x0c0c9844u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9846;
P_0c0c9846: /* original 06ec, guest PC 0x0c0c9846 */
if(!s->budget--) { s->failed_pc=0x0c0c9846u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9848;
P_0c0c9848: /* original 70ff, guest PC 0x0c0c9848 */
if(!s->budget--) { s->failed_pc=0x0c0c9848u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c984a;
P_0c0c984a: /* original d310, guest PC 0x0c0c984a */
if(!s->budget--) { s->failed_pc=0x0c0c984au; return 0; }
r[3]=read(ram,0x0c0c988cu,4);
goto P_0c0c984c;
P_0c0c984c: /* original 05ec, guest PC 0x0c0c984c */
if(!s->budget--) { s->failed_pc=0x0c0c984cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c984e;
P_0c0c984e: /* original 70ff, guest PC 0x0c0c984e */
if(!s->budget--) { s->failed_pc=0x0c0c984eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9850;
P_0c0c9850: /* original 430b, guest PC 0x0c0c9850 */
if(!s->budget--) { s->failed_pc=0x0c0c9850u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9854u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9854u) { target=s->pc; goto dispatch; }
goto P_0c0c9854;
P_0c0c9852: /* original 04ec, guest PC 0x0c0c9852 */
if(!s->budget--) { s->failed_pc=0x0c0c9852u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9854;
P_0c0c9854: /* original a002, guest PC 0x0c0c9854 */
if(!s->budget--) { s->failed_pc=0x0c0c9854u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c985c;
P_0c0c9856: /* original 7f08, guest PC 0x0c0c9856 */
if(!s->budget--) { s->failed_pc=0x0c0c9856u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c9858;
P_0c0c9858: /* original 2448, guest PC 0x0c0c9858 */
if(!s->budget--) { s->failed_pc=0x0c0c9858u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c985a;
P_0c0c985a: /* original 893d, guest PC 0x0c0c985a */
if(!s->budget--) { s->failed_pc=0x0c0c985au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c98d8; }
goto P_0c0c985c;
P_0c0c985c: /* original 9013, guest PC 0x0c0c985c */
if(!s->budget--) { s->failed_pc=0x0c0c985cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9886u,2);
goto P_0c0c985e;
P_0c0c985e: /* original e35d, guest PC 0x0c0c985e */
if(!s->budget--) { s->failed_pc=0x0c0c985eu; return 0; }
r[3]=0x0000005du;
goto P_0c0c9860;
P_0c0c9860: /* original 04ec, guest PC 0x0c0c9860 */
if(!s->budget--) { s->failed_pc=0x0c0c9860u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9862;
P_0c0c9862: /* original 7002, guest PC 0x0c0c9862 */
if(!s->budget--) { s->failed_pc=0x0c0c9862u; return 0; }
r[0]+=0x00000002u;
goto P_0c0c9864;
P_0c0c9864: /* original 74ff, guest PC 0x0c0c9864 */
if(!s->budget--) { s->failed_pc=0x0c0c9864u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c9866;
P_0c0c9866: /* original 0e44, guest PC 0x0c0c9866 */
if(!s->budget--) { s->failed_pc=0x0c0c9866u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9868;
P_0c0c9868: /* original 7001, guest PC 0x0c0c9868 */
if(!s->budget--) { s->failed_pc=0x0c0c9868u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c986a;
P_0c0c986a: /* original 0e44, guest PC 0x0c0c986a */
if(!s->budget--) { s->failed_pc=0x0c0c986au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c986c;
P_0c0c986c: /* original 70fd, guest PC 0x0c0c986c */
if(!s->budget--) { s->failed_pc=0x0c0c986cu; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c986e;
P_0c0c986e: /* original 0ec4, guest PC 0x0c0c986e */
if(!s->budget--) { s->failed_pc=0x0c0c986eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c9870;
P_0c0c9870: /* original e010, guest PC 0x0c0c9870 */
if(!s->budget--) { s->failed_pc=0x0c0c9870u; return 0; }
r[0]=0x00000010u;
goto P_0c0c9872;
P_0c0c9872: /* original a031, guest PC 0x0c0c9872 */
if(!s->budget--) { s->failed_pc=0x0c0c9872u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c9874: /* original 0d34, guest PC 0x0c0c9874 */
if(!s->budget--) { s->failed_pc=0x0c0c9874u; return 0; }
write(ram,r[13]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c0c9876u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9876u; return 0; } return 1;
P_0c0c9890: /* original 907d, guest PC 0x0c0c9890 */
if(!s->budget--) { s->failed_pc=0x0c0c9890u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c998eu,2);
goto P_0c0c9892;
P_0c0c9892: /* original e35f, guest PC 0x0c0c9892 */
if(!s->budget--) { s->failed_pc=0x0c0c9892u; return 0; }
r[3]=0x0000005fu;
goto P_0c0c9894;
P_0c0c9894: /* original 0e44, guest PC 0x0c0c9894 */
if(!s->budget--) { s->failed_pc=0x0c0c9894u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9896;
P_0c0c9896: /* original 7001, guest PC 0x0c0c9896 */
if(!s->budget--) { s->failed_pc=0x0c0c9896u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c9898;
P_0c0c9898: /* original 0e74, guest PC 0x0c0c9898 */
if(!s->budget--) { s->failed_pc=0x0c0c9898u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c989a;
P_0c0c989a: /* original 7001, guest PC 0x0c0c989a */
if(!s->budget--) { s->failed_pc=0x0c0c989au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c989c;
P_0c0c989c: /* original 0e74, guest PC 0x0c0c989c */
if(!s->budget--) { s->failed_pc=0x0c0c989cu; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c989e;
P_0c0c989e: /* original 7001, guest PC 0x0c0c989e */
if(!s->budget--) { s->failed_pc=0x0c0c989eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a0;
P_0c0c98a0: /* original 0ec4, guest PC 0x0c0c98a0 */
if(!s->budget--) { s->failed_pc=0x0c0c98a0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98a2;
P_0c0c98a2: /* original 7001, guest PC 0x0c0c98a2 */
if(!s->budget--) { s->failed_pc=0x0c0c98a2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a4;
P_0c0c98a4: /* original 0ec4, guest PC 0x0c0c98a4 */
if(!s->budget--) { s->failed_pc=0x0c0c98a4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98a6;
P_0c0c98a6: /* original 7001, guest PC 0x0c0c98a6 */
if(!s->budget--) { s->failed_pc=0x0c0c98a6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98a8;
P_0c0c98a8: /* original 0ec4, guest PC 0x0c0c98a8 */
if(!s->budget--) { s->failed_pc=0x0c0c98a8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98aa;
P_0c0c98aa: /* original 70c1, guest PC 0x0c0c98aa */
if(!s->budget--) { s->failed_pc=0x0c0c98aau; return 0; }
r[0]+=0xffffffc1u;
goto P_0c0c98ac;
P_0c0c98ac: /* original 0ec4, guest PC 0x0c0c98ac */
if(!s->budget--) { s->failed_pc=0x0c0c98acu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98ae;
P_0c0c98ae: /* original 7001, guest PC 0x0c0c98ae */
if(!s->budget--) { s->failed_pc=0x0c0c98aeu; return 0; }
r[0]+=0x00000001u;
goto P_0c0c98b0;
P_0c0c98b0: /* original 0ec4, guest PC 0x0c0c98b0 */
if(!s->budget--) { s->failed_pc=0x0c0c98b0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c98b2;
P_0c0c98b2: /* original 70fd, guest PC 0x0c0c98b2 */
if(!s->budget--) { s->failed_pc=0x0c0c98b2u; return 0; }
r[0]+=0xfffffffdu;
goto P_0c0c98b4;
P_0c0c98b4: /* original 0e74, guest PC 0x0c0c98b4 */
if(!s->budget--) { s->failed_pc=0x0c0c98b4u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c0c98b6;
P_0c0c98b6: /* original e010, guest PC 0x0c0c98b6 */
if(!s->budget--) { s->failed_pc=0x0c0c98b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c98b8;
P_0c0c98b8: /* original a00e, guest PC 0x0c0c98b8 */
if(!s->budget--) { s->failed_pc=0x0c0c98b8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c98ba: /* original 0d34, guest PC 0x0c0c98ba */
if(!s->budget--) { s->failed_pc=0x0c0c98bau; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98bc;
P_0c0c98bc: /* original 9068, guest PC 0x0c0c98bc */
if(!s->budget--) { s->failed_pc=0x0c0c98bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9990u,2);
goto P_0c0c98be;
P_0c0c98be: /* original e102, guest PC 0x0c0c98be */
if(!s->budget--) { s->failed_pc=0x0c0c98beu; return 0; }
r[1]=0x00000002u;
goto P_0c0c98c0;
P_0c0c98c0: /* original 0e14, guest PC 0x0c0c98c0 */
if(!s->budget--) { s->failed_pc=0x0c0c98c0u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0c98c2;
P_0c0c98c2: /* original e010, guest PC 0x0c0c98c2 */
if(!s->budget--) { s->failed_pc=0x0c0c98c2u; return 0; }
r[0]=0x00000010u;
goto P_0c0c98c4;
P_0c0c98c4: /* original a008, guest PC 0x0c0c98c4 */
if(!s->budget--) { s->failed_pc=0x0c0c98c4u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c98d8;
P_0c0c98c6: /* original 0d44, guest PC 0x0c0c98c6 */
if(!s->budget--) { s->failed_pc=0x0c0c98c6u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0c98c8;
P_0c0c98c8: /* original 9062, guest PC 0x0c0c98c8 */
if(!s->budget--) { s->failed_pc=0x0c0c98c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9990u,2);
goto P_0c0c98ca;
P_0c0c98ca: /* original e363, guest PC 0x0c0c98ca */
if(!s->budget--) { s->failed_pc=0x0c0c98cau; return 0; }
r[3]=0x00000063u;
goto P_0c0c98cc;
P_0c0c98cc: /* original 0e64, guest PC 0x0c0c98cc */
if(!s->budget--) { s->failed_pc=0x0c0c98ccu; return 0; }
write(ram,r[14]+r[0],r[6],1);
goto P_0c0c98ce;
P_0c0c98ce: /* original e010, guest PC 0x0c0c98ce */
if(!s->budget--) { s->failed_pc=0x0c0c98ceu; return 0; }
r[0]=0x00000010u;
goto P_0c0c98d0;
P_0c0c98d0: /* original a002, guest PC 0x0c0c98d0 */
if(!s->budget--) { s->failed_pc=0x0c0c98d0u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d8;
P_0c0c98d2: /* original 0d34, guest PC 0x0c0c98d2 */
if(!s->budget--) { s->failed_pc=0x0c0c98d2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c98d4;
P_0c0c98d4: /* original 60c3, guest PC 0x0c0c98d4 */
if(!s->budget--) { s->failed_pc=0x0c0c98d4u; return 0; }
r[0]=r[12];
goto P_0c0c98d6;
P_0c0c98d6: /* original 80db, guest PC 0x0c0c98d6 */
if(!s->budget--) { s->failed_pc=0x0c0c98d6u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c0c98d8;
P_0c0c98d8: /* original 7f08, guest PC 0x0c0c98d8 */
if(!s->budget--) { s->failed_pc=0x0c0c98d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c98da;
P_0c0c98da: /* original d330, guest PC 0x0c0c98da */
if(!s->budget--) { s->failed_pc=0x0c0c98dau; return 0; }
r[3]=read(ram,0x0c0c999cu,4);
goto P_0c0c98dc;
P_0c0c98dc: /* original 4f26, guest PC 0x0c0c98dc */
if(!s->budget--) { s->failed_pc=0x0c0c98dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c98de;
P_0c0c98de: /* original 69f6, guest PC 0x0c0c98de */
if(!s->budget--) { s->failed_pc=0x0c0c98deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c98e0;
P_0c0c98e0: /* original 6af6, guest PC 0x0c0c98e0 */
if(!s->budget--) { s->failed_pc=0x0c0c98e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c98e2;
P_0c0c98e2: /* original 6bf6, guest PC 0x0c0c98e2 */
if(!s->budget--) { s->failed_pc=0x0c0c98e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c98e4;
P_0c0c98e4: /* original 6cf6, guest PC 0x0c0c98e4 */
if(!s->budget--) { s->failed_pc=0x0c0c98e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c98e6;
P_0c0c98e6: /* original 6df6, guest PC 0x0c0c98e6 */
if(!s->budget--) { s->failed_pc=0x0c0c98e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c98e8;
P_0c0c98e8: /* original 432b, guest PC 0x0c0c98e8 */
if(!s->budget--) { s->failed_pc=0x0c0c98e8u; return 0; }
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
P_0c0c98ea: /* original 6ef6, guest PC 0x0c0c98ea */
if(!s->budget--) { s->failed_pc=0x0c0c98eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c98ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c98ecu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
