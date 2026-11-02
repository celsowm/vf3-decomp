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
int vf3_away_batch102_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c096718u: goto P_0c096718;
case 0x0c09671au: goto P_0c09671a;
case 0x0c09671cu: goto P_0c09671c;
case 0x0c09671eu: goto P_0c09671e;
case 0x0c096720u: goto P_0c096720;
case 0x0c096722u: goto P_0c096722;
case 0x0c096724u: goto P_0c096724;
case 0x0c096726u: goto P_0c096726;
case 0x0c096728u: goto P_0c096728;
case 0x0c09672au: goto P_0c09672a;
case 0x0c09672cu: goto P_0c09672c;
case 0x0c09672eu: goto P_0c09672e;
case 0x0c096730u: goto P_0c096730;
case 0x0c096732u: goto P_0c096732;
case 0x0c096734u: goto P_0c096734;
case 0x0c096736u: goto P_0c096736;
case 0x0c096738u: goto P_0c096738;
case 0x0c09673au: goto P_0c09673a;
case 0x0c09673cu: goto P_0c09673c;
case 0x0c09673eu: goto P_0c09673e;
case 0x0c096740u: goto P_0c096740;
case 0x0c096742u: goto P_0c096742;
case 0x0c096744u: goto P_0c096744;
case 0x0c096746u: goto P_0c096746;
case 0x0c0967e8u: goto P_0c0967e8;
case 0x0c0967eau: goto P_0c0967ea;
case 0x0c0967ecu: goto P_0c0967ec;
case 0x0c0967eeu: goto P_0c0967ee;
case 0x0c0967f0u: goto P_0c0967f0;
case 0x0c0967f2u: goto P_0c0967f2;
case 0x0c0967f4u: goto P_0c0967f4;
case 0x0c0967f6u: goto P_0c0967f6;
case 0x0c0967f8u: goto P_0c0967f8;
case 0x0c0967fau: goto P_0c0967fa;
case 0x0c0967fcu: goto P_0c0967fc;
case 0x0c0967feu: goto P_0c0967fe;
case 0x0c096800u: goto P_0c096800;
case 0x0c096802u: goto P_0c096802;
case 0x0c096804u: goto P_0c096804;
case 0x0c096806u: goto P_0c096806;
case 0x0c096808u: goto P_0c096808;
case 0x0c09680au: goto P_0c09680a;
case 0x0c09680cu: goto P_0c09680c;
case 0x0c09680eu: goto P_0c09680e;
case 0x0c096810u: goto P_0c096810;
case 0x0c096812u: goto P_0c096812;
case 0x0c096814u: goto P_0c096814;
case 0x0c09abc4u: goto P_0c09abc4;
case 0x0c09abc6u: goto P_0c09abc6;
case 0x0c09abc8u: goto P_0c09abc8;
case 0x0c09abcau: goto P_0c09abca;
case 0x0c09abccu: goto P_0c09abcc;
case 0x0c09abceu: goto P_0c09abce;
case 0x0c09abd0u: goto P_0c09abd0;
case 0x0c09abd2u: goto P_0c09abd2;
case 0x0c09abd4u: goto P_0c09abd4;
case 0x0c09abd6u: goto P_0c09abd6;
case 0x0c09abd8u: goto P_0c09abd8;
case 0x0c09abdau: goto P_0c09abda;
case 0x0c09abdcu: goto P_0c09abdc;
case 0x0c09abdeu: goto P_0c09abde;
case 0x0c09abe0u: goto P_0c09abe0;
case 0x0c09abe2u: goto P_0c09abe2;
case 0x0c09abe4u: goto P_0c09abe4;
case 0x0c09abe6u: goto P_0c09abe6;
case 0x0c09abe8u: goto P_0c09abe8;
case 0x0c09abeau: goto P_0c09abea;
case 0x0c09abecu: goto P_0c09abec;
case 0x0c09abeeu: goto P_0c09abee;
case 0x0c09abf0u: goto P_0c09abf0;
case 0x0c09abf2u: goto P_0c09abf2;
case 0x0c09abf4u: goto P_0c09abf4;
case 0x0c09abf6u: goto P_0c09abf6;
case 0x0c09abf8u: goto P_0c09abf8;
case 0x0c09abfau: goto P_0c09abfa;
case 0x0c09abfcu: goto P_0c09abfc;
case 0x0c09abfeu: goto P_0c09abfe;
case 0x0c09ac00u: goto P_0c09ac00;
case 0x0c09ac02u: goto P_0c09ac02;
case 0x0c09ac04u: goto P_0c09ac04;
case 0x0c09fe68u: goto P_0c09fe68;
case 0x0c09fe6au: goto P_0c09fe6a;
case 0x0c09fe6cu: goto P_0c09fe6c;
case 0x0c09fe6eu: goto P_0c09fe6e;
case 0x0c09fe70u: goto P_0c09fe70;
case 0x0c09fe72u: goto P_0c09fe72;
case 0x0c09fe74u: goto P_0c09fe74;
case 0x0c09fe76u: goto P_0c09fe76;
case 0x0c09fe78u: goto P_0c09fe78;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c66d4u: goto P_0c0c66d4;
case 0x0c0c66d6u: goto P_0c0c66d6;
case 0x0c0c66d8u: goto P_0c0c66d8;
case 0x0c0c66dau: goto P_0c0c66da;
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
case 0x0c0c9910u: goto P_0c0c9910;
case 0x0c0c9912u: goto P_0c0c9912;
case 0x0c0c9914u: goto P_0c0c9914;
case 0x0c0c9916u: goto P_0c0c9916;
case 0x0c0c9918u: goto P_0c0c9918;
case 0x0c0c991au: goto P_0c0c991a;
case 0x0c0c991cu: goto P_0c0c991c;
case 0x0c0c991eu: goto P_0c0c991e;
case 0x0c0c9920u: goto P_0c0c9920;
case 0x0c0c9922u: goto P_0c0c9922;
case 0x0c0c9924u: goto P_0c0c9924;
case 0x0c0c9926u: goto P_0c0c9926;
case 0x0c0c9928u: goto P_0c0c9928;
case 0x0c0c992au: goto P_0c0c992a;
case 0x0c0c992cu: goto P_0c0c992c;
case 0x0c0c992eu: goto P_0c0c992e;
case 0x0c0c9930u: goto P_0c0c9930;
case 0x0c0c9932u: goto P_0c0c9932;
case 0x0c0c9934u: goto P_0c0c9934;
case 0x0c0c9936u: goto P_0c0c9936;
case 0x0c0c9938u: goto P_0c0c9938;
case 0x0c0c993au: goto P_0c0c993a;
case 0x0c0c993cu: goto P_0c0c993c;
case 0x0c0c993eu: goto P_0c0c993e;
case 0x0c0c9940u: goto P_0c0c9940;
case 0x0c0c9942u: goto P_0c0c9942;
case 0x0c0c9944u: goto P_0c0c9944;
case 0x0c0c9946u: goto P_0c0c9946;
case 0x0c0c9948u: goto P_0c0c9948;
case 0x0c0c994au: goto P_0c0c994a;
case 0x0c0c994cu: goto P_0c0c994c;
case 0x0c0c994eu: goto P_0c0c994e;
case 0x0c0c9950u: goto P_0c0c9950;
case 0x0c0c9952u: goto P_0c0c9952;
case 0x0c0c9954u: goto P_0c0c9954;
case 0x0c0c9956u: goto P_0c0c9956;
case 0x0c0c9958u: goto P_0c0c9958;
case 0x0c0c995au: goto P_0c0c995a;
case 0x0c0c995cu: goto P_0c0c995c;
case 0x0c0c995eu: goto P_0c0c995e;
case 0x0c0c9960u: goto P_0c0c9960;
case 0x0c0c9962u: goto P_0c0c9962;
case 0x0c0c9964u: goto P_0c0c9964;
case 0x0c0c9966u: goto P_0c0c9966;
case 0x0c0c9968u: goto P_0c0c9968;
case 0x0c0c996au: goto P_0c0c996a;
case 0x0c0c996cu: goto P_0c0c996c;
case 0x0c0c996eu: goto P_0c0c996e;
case 0x0c0c9970u: goto P_0c0c9970;
case 0x0c0c9972u: goto P_0c0c9972;
case 0x0c0c9974u: goto P_0c0c9974;
case 0x0c0c9976u: goto P_0c0c9976;
case 0x0c0c9978u: goto P_0c0c9978;
case 0x0c0c997au: goto P_0c0c997a;
case 0x0c0c997cu: goto P_0c0c997c;
case 0x0c0c997eu: goto P_0c0c997e;
case 0x0c0c9980u: goto P_0c0c9980;
case 0x0c0c9982u: goto P_0c0c9982;
case 0x0c0c9984u: goto P_0c0c9984;
case 0x0c0c9986u: goto P_0c0c9986;
case 0x0c0c9988u: goto P_0c0c9988;
case 0x0c0c998au: goto P_0c0c998a;
case 0x0c0c998cu: goto P_0c0c998c;
case 0x0c0c99bcu: goto P_0c0c99bc;
case 0x0c0c99beu: goto P_0c0c99be;
case 0x0c0c99c0u: goto P_0c0c99c0;
case 0x0c0c99c2u: goto P_0c0c99c2;
case 0x0c0c99c4u: goto P_0c0c99c4;
case 0x0c0c99c6u: goto P_0c0c99c6;
case 0x0c0c99c8u: goto P_0c0c99c8;
case 0x0c0c99eeu: goto P_0c0c99ee;
case 0x0c0c99f0u: goto P_0c0c99f0;
case 0x0c0c99f2u: goto P_0c0c99f2;
case 0x0c0c99f4u: goto P_0c0c99f4;
case 0x0c0c99f6u: goto P_0c0c99f6;
case 0x0c0c99f8u: goto P_0c0c99f8;
case 0x0c0c99fau: goto P_0c0c99fa;
case 0x0c0c99fcu: goto P_0c0c99fc;
case 0x0c0c99feu: goto P_0c0c99fe;
case 0x0c0c9a00u: goto P_0c0c9a00;
case 0x0c0c9a02u: goto P_0c0c9a02;
case 0x0c0c9a04u: goto P_0c0c9a04;
case 0x0c0c9a06u: goto P_0c0c9a06;
case 0x0c0c9a08u: goto P_0c0c9a08;
case 0x0c0c9a0au: goto P_0c0c9a0a;
case 0x0c0c9a0cu: goto P_0c0c9a0c;
case 0x0c0c9a0eu: goto P_0c0c9a0e;
case 0x0c0c9a10u: goto P_0c0c9a10;
case 0x0c0c9a12u: goto P_0c0c9a12;
case 0x0c0c9a14u: goto P_0c0c9a14;
case 0x0c0c9a16u: goto P_0c0c9a16;
case 0x0c0c9a18u: goto P_0c0c9a18;
case 0x0c0c9a1au: goto P_0c0c9a1a;
case 0x0c0c9a1cu: goto P_0c0c9a1c;
case 0x0c0c9a1eu: goto P_0c0c9a1e;
case 0x0c0c9a20u: goto P_0c0c9a20;
case 0x0c0c9a22u: goto P_0c0c9a22;
case 0x0c0c9a24u: goto P_0c0c9a24;
case 0x0c0c9a26u: goto P_0c0c9a26;
case 0x0c0c9a28u: goto P_0c0c9a28;
case 0x0c0c9a2au: goto P_0c0c9a2a;
case 0x0c0c9a2cu: goto P_0c0c9a2c;
case 0x0c0c9a2eu: goto P_0c0c9a2e;
case 0x0c0c9a30u: goto P_0c0c9a30;
case 0x0c0c9a32u: goto P_0c0c9a32;
case 0x0c0c9a34u: goto P_0c0c9a34;
case 0x0c0c9a36u: goto P_0c0c9a36;
case 0x0c0c9a38u: goto P_0c0c9a38;
case 0x0c0c9a3au: goto P_0c0c9a3a;
case 0x0c0c9a3cu: goto P_0c0c9a3c;
case 0x0c0c9a3eu: goto P_0c0c9a3e;
case 0x0c0c9a40u: goto P_0c0c9a40;
case 0x0c0c9a42u: goto P_0c0c9a42;
case 0x0c0c9a44u: goto P_0c0c9a44;
case 0x0c0c9a46u: goto P_0c0c9a46;
case 0x0c0c9a48u: goto P_0c0c9a48;
case 0x0c0c9a4au: goto P_0c0c9a4a;
case 0x0c0c9a4cu: goto P_0c0c9a4c;
case 0x0c0c9a4eu: goto P_0c0c9a4e;
case 0x0c0c9a50u: goto P_0c0c9a50;
case 0x0c0c9a52u: goto P_0c0c9a52;
case 0x0c0c9a54u: goto P_0c0c9a54;
case 0x0c0c9a56u: goto P_0c0c9a56;
case 0x0c0c9a58u: goto P_0c0c9a58;
case 0x0c0c9a5au: goto P_0c0c9a5a;
case 0x0c0c9a5cu: goto P_0c0c9a5c;
case 0x0c0c9a5eu: goto P_0c0c9a5e;
case 0x0c0c9a60u: goto P_0c0c9a60;
case 0x0c0c9a62u: goto P_0c0c9a62;
case 0x0c0c9a64u: goto P_0c0c9a64;
case 0x0c0c9a66u: goto P_0c0c9a66;
case 0x0c0c9a68u: goto P_0c0c9a68;
case 0x0c0c9a6au: goto P_0c0c9a6a;
case 0x0c0c9a6cu: goto P_0c0c9a6c;
case 0x0c0c9a6eu: goto P_0c0c9a6e;
case 0x0c0c9a70u: goto P_0c0c9a70;
case 0x0c0c9a72u: goto P_0c0c9a72;
case 0x0c0c9a74u: goto P_0c0c9a74;
case 0x0c0c9a76u: goto P_0c0c9a76;
case 0x0c0c9a78u: goto P_0c0c9a78;
case 0x0c0c9ad0u: goto P_0c0c9ad0;
case 0x0c0c9ad2u: goto P_0c0c9ad2;
case 0x0c0c9ad4u: goto P_0c0c9ad4;
case 0x0c0c9ad6u: goto P_0c0c9ad6;
case 0x0c0c9ad8u: goto P_0c0c9ad8;
case 0x0c0c9adau: goto P_0c0c9ada;
case 0x0c0c9adcu: goto P_0c0c9adc;
case 0x0c0c9adeu: goto P_0c0c9ade;
case 0x0c0c9ae0u: goto P_0c0c9ae0;
case 0x0c0c9ae2u: goto P_0c0c9ae2;
case 0x0c0c9ae4u: goto P_0c0c9ae4;
case 0x0c0c9ae6u: goto P_0c0c9ae6;
case 0x0c0c9ae8u: goto P_0c0c9ae8;
case 0x0c0c9aeau: goto P_0c0c9aea;
case 0x0c0c9aecu: goto P_0c0c9aec;
case 0x0c0c9aeeu: goto P_0c0c9aee;
case 0x0c0c9af0u: goto P_0c0c9af0;
case 0x0c0c9af2u: goto P_0c0c9af2;
case 0x0c0c9af4u: goto P_0c0c9af4;
case 0x0c0c9af6u: goto P_0c0c9af6;
case 0x0c0c9af8u: goto P_0c0c9af8;
case 0x0c0c9afau: goto P_0c0c9afa;
case 0x0c0c9afcu: goto P_0c0c9afc;
case 0x0c0c9afeu: goto P_0c0c9afe;
case 0x0c0c9b00u: goto P_0c0c9b00;
case 0x0c0c9b02u: goto P_0c0c9b02;
case 0x0c0c9b04u: goto P_0c0c9b04;
case 0x0c0c9b06u: goto P_0c0c9b06;
case 0x0c0c9b08u: goto P_0c0c9b08;
case 0x0c0c9b0au: goto P_0c0c9b0a;
case 0x0c0c9b0cu: goto P_0c0c9b0c;
case 0x0c0c9b0eu: goto P_0c0c9b0e;
case 0x0c0c9b10u: goto P_0c0c9b10;
case 0x0c0c9b12u: goto P_0c0c9b12;
case 0x0c0c9b14u: goto P_0c0c9b14;
case 0x0c0c9b16u: goto P_0c0c9b16;
case 0x0c0c9b18u: goto P_0c0c9b18;
case 0x0c0c9b1au: goto P_0c0c9b1a;
case 0x0c0c9b1cu: goto P_0c0c9b1c;
case 0x0c0c9b1eu: goto P_0c0c9b1e;
case 0x0c0c9b20u: goto P_0c0c9b20;
case 0x0c0c9b22u: goto P_0c0c9b22;
case 0x0c0c9b24u: goto P_0c0c9b24;
case 0x0c0c9b26u: goto P_0c0c9b26;
case 0x0c0c9b28u: goto P_0c0c9b28;
case 0x0c0c9b2au: goto P_0c0c9b2a;
case 0x0c0c9b2cu: goto P_0c0c9b2c;
case 0x0c0c9b40u: goto P_0c0c9b40;
case 0x0c0c9b42u: goto P_0c0c9b42;
case 0x0c0c9b44u: goto P_0c0c9b44;
case 0x0c0c9b46u: goto P_0c0c9b46;
case 0x0c0c9b48u: goto P_0c0c9b48;
case 0x0c0c9b4au: goto P_0c0c9b4a;
case 0x0c0c9b4cu: goto P_0c0c9b4c;
case 0x0c0c9b4eu: goto P_0c0c9b4e;
case 0x0c0c9b50u: goto P_0c0c9b50;
case 0x0c0c9b52u: goto P_0c0c9b52;
case 0x0c0c9b54u: goto P_0c0c9b54;
case 0x0c0c9b56u: goto P_0c0c9b56;
case 0x0c0c9b58u: goto P_0c0c9b58;
case 0x0c0c9b5au: goto P_0c0c9b5a;
case 0x0c0c9b5cu: goto P_0c0c9b5c;
case 0x0c0c9b5eu: goto P_0c0c9b5e;
case 0x0c0c9b60u: goto P_0c0c9b60;
case 0x0c0c9b90u: goto P_0c0c9b90;
case 0x0c0c9b92u: goto P_0c0c9b92;
default: return vf3_matrix_family(target,s,ram);
}
P_0c096718: /* original 4f22, guest PC 0x0c096718 */
if(!s->budget--) { s->failed_pc=0x0c096718u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09671a;
P_0c09671a: /* original d340, guest PC 0x0c09671a */
if(!s->budget--) { s->failed_pc=0x0c09671au; return 0; }
r[3]=read(ram,0x0c09681cu,4);
goto P_0c09671c;
P_0c09671c: /* original 430b, guest PC 0x0c09671c */
if(!s->budget--) { s->failed_pc=0x0c09671cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096720u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096720u) { target=s->pc; goto dispatch; }
goto P_0c096720;
P_0c09671e: /* original 0009, guest PC 0x0c09671e */
if(!s->budget--) { s->failed_pc=0x0c09671eu; return 0; }
goto P_0c096720;
P_0c096720: /* original d23f, guest PC 0x0c096720 */
if(!s->budget--) { s->failed_pc=0x0c096720u; return 0; }
r[2]=read(ram,0x0c096820u,4);
goto P_0c096722;
P_0c096722: /* original 420b, guest PC 0x0c096722 */
if(!s->budget--) { s->failed_pc=0x0c096722u; return 0; }
target=r[2];
r[16]=code_base|0x0c096726u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096726u) { target=s->pc; goto dispatch; }
goto P_0c096726;
P_0c096724: /* original 0009, guest PC 0x0c096724 */
if(!s->budget--) { s->failed_pc=0x0c096724u; return 0; }
goto P_0c096726;
P_0c096726: /* original d33f, guest PC 0x0c096726 */
if(!s->budget--) { s->failed_pc=0x0c096726u; return 0; }
r[3]=read(ram,0x0c096824u,4);
goto P_0c096728;
P_0c096728: /* original 430b, guest PC 0x0c096728 */
if(!s->budget--) { s->failed_pc=0x0c096728u; return 0; }
target=r[3];
r[16]=code_base|0x0c09672cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09672cu) { target=s->pc; goto dispatch; }
goto P_0c09672c;
P_0c09672a: /* original 0009, guest PC 0x0c09672a */
if(!s->budget--) { s->failed_pc=0x0c09672au; return 0; }
goto P_0c09672c;
P_0c09672c: /* original d23e, guest PC 0x0c09672c */
if(!s->budget--) { s->failed_pc=0x0c09672cu; return 0; }
r[2]=read(ram,0x0c096828u,4);
goto P_0c09672e;
P_0c09672e: /* original 420b, guest PC 0x0c09672e */
if(!s->budget--) { s->failed_pc=0x0c09672eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096732u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096732u) { target=s->pc; goto dispatch; }
goto P_0c096732;
P_0c096730: /* original 0009, guest PC 0x0c096730 */
if(!s->budget--) { s->failed_pc=0x0c096730u; return 0; }
goto P_0c096732;
P_0c096732: /* original d33e, guest PC 0x0c096732 */
if(!s->budget--) { s->failed_pc=0x0c096732u; return 0; }
r[3]=read(ram,0x0c09682cu,4);
goto P_0c096734;
P_0c096734: /* original 430b, guest PC 0x0c096734 */
if(!s->budget--) { s->failed_pc=0x0c096734u; return 0; }
target=r[3];
r[16]=code_base|0x0c096738u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096738u) { target=s->pc; goto dispatch; }
goto P_0c096738;
P_0c096736: /* original 0009, guest PC 0x0c096736 */
if(!s->budget--) { s->failed_pc=0x0c096736u; return 0; }
goto P_0c096738;
P_0c096738: /* original d23d, guest PC 0x0c096738 */
if(!s->budget--) { s->failed_pc=0x0c096738u; return 0; }
r[2]=read(ram,0x0c096830u,4);
goto P_0c09673a;
P_0c09673a: /* original 420b, guest PC 0x0c09673a */
if(!s->budget--) { s->failed_pc=0x0c09673au; return 0; }
target=r[2];
r[16]=code_base|0x0c09673eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09673eu) { target=s->pc; goto dispatch; }
goto P_0c09673e;
P_0c09673c: /* original e400, guest PC 0x0c09673c */
if(!s->budget--) { s->failed_pc=0x0c09673cu; return 0; }
r[4]=0x00000000u;
goto P_0c09673e;
P_0c09673e: /* original d33d, guest PC 0x0c09673e */
if(!s->budget--) { s->failed_pc=0x0c09673eu; return 0; }
r[3]=read(ram,0x0c096834u,4);
goto P_0c096740;
P_0c096740: /* original 430b, guest PC 0x0c096740 */
if(!s->budget--) { s->failed_pc=0x0c096740u; return 0; }
target=r[3];
r[16]=code_base|0x0c096744u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096744u) { target=s->pc; goto dispatch; }
goto P_0c096744;
P_0c096742: /* original 0009, guest PC 0x0c096742 */
if(!s->budget--) { s->failed_pc=0x0c096742u; return 0; }
goto P_0c096744;
P_0c096744: /* original a050, guest PC 0x0c096744 */
if(!s->budget--) { s->failed_pc=0x0c096744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0967e8;
P_0c096746: /* original 4f26, guest PC 0x0c096746 */
if(!s->budget--) { s->failed_pc=0x0c096746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c096748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096748u; return 0; } return 1;
P_0c0967e8: /* original 2fe6, guest PC 0x0c0967e8 */
if(!s->budget--) { s->failed_pc=0x0c0967e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ea;
P_0c0967ea: /* original 2fd6, guest PC 0x0c0967ea */
if(!s->budget--) { s->failed_pc=0x0c0967eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ec;
P_0c0967ec: /* original de18, guest PC 0x0c0967ec */
if(!s->budget--) { s->failed_pc=0x0c0967ecu; return 0; }
r[14]=read(ram,0x0c096850u,4);
goto P_0c0967ee;
P_0c0967ee: /* original 4f22, guest PC 0x0c0967ee */
if(!s->budget--) { s->failed_pc=0x0c0967eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0967f0;
P_0c0967f0: /* original dd19, guest PC 0x0c0967f0 */
if(!s->budget--) { s->failed_pc=0x0c0967f0u; return 0; }
r[13]=read(ram,0x0c096858u,4);
goto P_0c0967f2;
P_0c0967f2: /* original 64e3, guest PC 0x0c0967f2 */
if(!s->budget--) { s->failed_pc=0x0c0967f2u; return 0; }
r[4]=r[14];
goto P_0c0967f4;
P_0c0967f4: /* original d517, guest PC 0x0c0967f4 */
if(!s->budget--) { s->failed_pc=0x0c0967f4u; return 0; }
r[5]=read(ram,0x0c096854u,4);
goto P_0c0967f6;
P_0c0967f6: /* original 4d0b, guest PC 0x0c0967f6 */
if(!s->budget--) { s->failed_pc=0x0c0967f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0967fau;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0967fau) { target=s->pc; goto dispatch; }
goto P_0c0967fa;
P_0c0967f8: /* original 742c, guest PC 0x0c0967f8 */
if(!s->budget--) { s->failed_pc=0x0c0967f8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0967fa;
P_0c0967fa: /* original d518, guest PC 0x0c0967fa */
if(!s->budget--) { s->failed_pc=0x0c0967fau; return 0; }
r[5]=read(ram,0x0c09685cu,4);
goto P_0c0967fc;
P_0c0967fc: /* original 64e3, guest PC 0x0c0967fc */
if(!s->budget--) { s->failed_pc=0x0c0967fcu; return 0; }
r[4]=r[14];
goto P_0c0967fe;
P_0c0967fe: /* original 6552, guest PC 0x0c0967fe */
if(!s->budget--) { s->failed_pc=0x0c0967feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c096800;
P_0c096800: /* original 4d0b, guest PC 0x0c096800 */
if(!s->budget--) { s->failed_pc=0x0c096800u; return 0; }
target=r[13];
r[16]=code_base|0x0c096804u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096804u) { target=s->pc; goto dispatch; }
goto P_0c096804;
P_0c096802: /* original 7434, guest PC 0x0c096802 */
if(!s->budget--) { s->failed_pc=0x0c096802u; return 0; }
r[4]+=0x00000034u;
goto P_0c096804;
P_0c096804: /* original d516, guest PC 0x0c096804 */
if(!s->budget--) { s->failed_pc=0x0c096804u; return 0; }
r[5]=read(ram,0x0c096860u,4);
goto P_0c096806;
P_0c096806: /* original 64e3, guest PC 0x0c096806 */
if(!s->budget--) { s->failed_pc=0x0c096806u; return 0; }
r[4]=r[14];
goto P_0c096808;
P_0c096808: /* original 6552, guest PC 0x0c096808 */
if(!s->budget--) { s->failed_pc=0x0c096808u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09680a;
P_0c09680a: /* original 4d0b, guest PC 0x0c09680a */
if(!s->budget--) { s->failed_pc=0x0c09680au; return 0; }
target=r[13];
r[16]=code_base|0x0c09680eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09680eu) { target=s->pc; goto dispatch; }
goto P_0c09680e;
P_0c09680c: /* original 7438, guest PC 0x0c09680c */
if(!s->budget--) { s->failed_pc=0x0c09680cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09680e;
P_0c09680e: /* original 4f26, guest PC 0x0c09680e */
if(!s->budget--) { s->failed_pc=0x0c09680eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096810;
P_0c096810: /* original 6df6, guest PC 0x0c096810 */
if(!s->budget--) { s->failed_pc=0x0c096810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096812;
P_0c096812: /* original 000b, guest PC 0x0c096812 */
if(!s->budget--) { s->failed_pc=0x0c096812u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096814: /* original 6ef6, guest PC 0x0c096814 */
if(!s->budget--) { s->failed_pc=0x0c096814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096816u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096816u; return 0; } return 1;
P_0c09abc4: /* original d512, guest PC 0x0c09abc4 */
if(!s->budget--) { s->failed_pc=0x0c09abc4u; return 0; }
r[5]=read(ram,0x0c09ac10u,4);
goto P_0c09abc6;
P_0c09abc6: /* original e620, guest PC 0x0c09abc6 */
if(!s->budget--) { s->failed_pc=0x0c09abc6u; return 0; }
r[6]=0x00000020u;
goto P_0c09abc8;
P_0c09abc8: /* original 845b, guest PC 0x0c09abc8 */
if(!s->budget--) { s->failed_pc=0x0c09abc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+11,1);
goto P_0c09abca;
P_0c09abca: /* original 640c, guest PC 0x0c09abca */
if(!s->budget--) { s->failed_pc=0x0c09abcau; return 0; }
r[4]=r[0]&255u;
goto P_0c09abcc;
P_0c09abcc: /* original 3463, guest PC 0x0c09abcc */
if(!s->budget--) { s->failed_pc=0x0c09abccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abce;
P_0c09abce: /* original 8b18, guest PC 0x0c09abce */
if(!s->budget--) { s->failed_pc=0x0c09abceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ac02; }
goto P_0c09abd0;
P_0c09abd0: /* original 9019, guest PC 0x0c09abd0 */
if(!s->budget--) { s->failed_pc=0x0c09abd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac06u,2);
goto P_0c09abd2;
P_0c09abd2: /* original 035e, guest PC 0x0c09abd2 */
if(!s->budget--) { s->failed_pc=0x0c09abd2u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09abd4;
P_0c09abd4: /* original 2368, guest PC 0x0c09abd4 */
if(!s->budget--) { s->failed_pc=0x0c09abd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09abd6;
P_0c09abd6: /* original 8914, guest PC 0x0c09abd6 */
if(!s->budget--) { s->failed_pc=0x0c09abd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abd8;
P_0c09abd8: /* original 9017, guest PC 0x0c09abd8 */
if(!s->budget--) { s->failed_pc=0x0c09abd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0au,2);
goto P_0c09abda;
P_0c09abda: /* original 9315, guest PC 0x0c09abda */
if(!s->budget--) { s->failed_pc=0x0c09abdau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac08u,2);
goto P_0c09abdc;
P_0c09abdc: /* original 025e, guest PC 0x0c09abdc */
if(!s->budget--) { s->failed_pc=0x0c09abdcu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abde;
P_0c09abde: /* original 2238, guest PC 0x0c09abde */
if(!s->budget--) { s->failed_pc=0x0c09abdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abe0;
P_0c09abe0: /* original 8f05, guest PC 0x0c09abe0 */
if(!s->budget--) { s->failed_pc=0x0c09abe0u; return 0; }
cond=r[17]&1u;
r[7]=0x00000032u;
if(!cond) { goto P_0c09abee; }
goto P_0c09abe4;
P_0c09abe2: /* original e732, guest PC 0x0c09abe2 */
if(!s->budget--) { s->failed_pc=0x0c09abe2u; return 0; }
r[7]=0x00000032u;
goto P_0c09abe4;
P_0c09abe4: /* original 7401, guest PC 0x0c09abe4 */
if(!s->budget--) { s->failed_pc=0x0c09abe4u; return 0; }
r[4]+=0x00000001u;
goto P_0c09abe6;
P_0c09abe6: /* original 3477, guest PC 0x0c09abe6 */
if(!s->budget--) { s->failed_pc=0x0c09abe6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[7])!=0);
goto P_0c09abe8;
P_0c09abe8: /* original 8b09, guest PC 0x0c09abe8 */
if(!s->budget--) { s->failed_pc=0x0c09abe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09abfe; }
goto P_0c09abea;
P_0c09abea: /* original a008, guest PC 0x0c09abea */
if(!s->budget--) { s->failed_pc=0x0c09abeau; return 0; }
r[4]=r[6];
goto P_0c09abfe;
P_0c09abec: /* original 6463, guest PC 0x0c09abec */
if(!s->budget--) { s->failed_pc=0x0c09abecu; return 0; }
r[4]=r[6];
goto P_0c09abee;
P_0c09abee: /* original 025e, guest PC 0x0c09abee */
if(!s->budget--) { s->failed_pc=0x0c09abeeu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c09abf0;
P_0c09abf0: /* original 930c, guest PC 0x0c09abf0 */
if(!s->budget--) { s->failed_pc=0x0c09abf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ac0cu,2);
goto P_0c09abf2;
P_0c09abf2: /* original 2238, guest PC 0x0c09abf2 */
if(!s->budget--) { s->failed_pc=0x0c09abf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09abf4;
P_0c09abf4: /* original 8905, guest PC 0x0c09abf4 */
if(!s->budget--) { s->failed_pc=0x0c09abf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ac02; }
goto P_0c09abf6;
P_0c09abf6: /* original 74fd, guest PC 0x0c09abf6 */
if(!s->budget--) { s->failed_pc=0x0c09abf6u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c09abf8;
P_0c09abf8: /* original 3463, guest PC 0x0c09abf8 */
if(!s->budget--) { s->failed_pc=0x0c09abf8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c09abfa;
P_0c09abfa: /* original 8900, guest PC 0x0c09abfa */
if(!s->budget--) { s->failed_pc=0x0c09abfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09abfe; }
goto P_0c09abfc;
P_0c09abfc: /* original 6473, guest PC 0x0c09abfc */
if(!s->budget--) { s->failed_pc=0x0c09abfcu; return 0; }
r[4]=r[7];
goto P_0c09abfe;
P_0c09abfe: /* original 6043, guest PC 0x0c09abfe */
if(!s->budget--) { s->failed_pc=0x0c09abfeu; return 0; }
r[0]=r[4];
goto P_0c09ac00;
P_0c09ac00: /* original 805b, guest PC 0x0c09ac00 */
if(!s->budget--) { s->failed_pc=0x0c09ac00u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c09ac02;
P_0c09ac02: /* original 000b, guest PC 0x0c09ac02 */
if(!s->budget--) { s->failed_pc=0x0c09ac02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09ac04: /* original 0009, guest PC 0x0c09ac04 */
if(!s->budget--) { s->failed_pc=0x0c09ac04u; return 0; }
if(!vf3_matrix_family(0x0c09ac06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ac06u; return 0; } return 1;
P_0c09fe68: /* original 2fe6, guest PC 0x0c09fe68 */
if(!s->budget--) { s->failed_pc=0x0c09fe68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6a;
P_0c09fe6a: /* original 2fd6, guest PC 0x0c09fe6a */
if(!s->budget--) { s->failed_pc=0x0c09fe6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6c;
P_0c09fe6c: /* original 2fc6, guest PC 0x0c09fe6c */
if(!s->budget--) { s->failed_pc=0x0c09fe6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6e;
P_0c09fe6e: /* original 2fb6, guest PC 0x0c09fe6e */
if(!s->budget--) { s->failed_pc=0x0c09fe6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe70;
P_0c09fe70: /* original 2fa6, guest PC 0x0c09fe70 */
if(!s->budget--) { s->failed_pc=0x0c09fe70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe72;
P_0c09fe72: /* original 2f96, guest PC 0x0c09fe72 */
if(!s->budget--) { s->failed_pc=0x0c09fe72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe74;
P_0c09fe74: /* original e900, guest PC 0x0c09fe74 */
if(!s->budget--) { s->failed_pc=0x0c09fe74u; return 0; }
r[9]=0x00000000u;
goto P_0c09fe76;
P_0c09fe76: /* original 2f86, guest PC 0x0c09fe76 */
if(!s->budget--) { s->failed_pc=0x0c09fe76u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe78;
P_0c09fe78: /* original e812, guest PC 0x0c09fe78 */
if(!s->budget--) { s->failed_pc=0x0c09fe78u; return 0; }
r[8]=0x00000012u;
goto P_0c09fe7a;
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09fea8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09febau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=code_base|0x0c09feceu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=code_base|0x0c09fedeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fefeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fefeu; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
goto P_0c0c66d4;
P_0c0c66d4: /* original 000b, guest PC 0x0c0c66d4 */
if(!s->budget--) { s->failed_pc=0x0c0c66d4u; return 0; }
target=r[16];
write(ram,r[4],r[5],2);
s->pc=target; return ram->oob==0;
P_0c0c66d6: /* original 2451, guest PC 0x0c0c66d6 */
if(!s->budget--) { s->failed_pc=0x0c0c66d6u; return 0; }
write(ram,r[4],r[5],2);
goto P_0c0c66d8;
P_0c0c66d8: /* original 000b, guest PC 0x0c0c66d8 */
if(!s->budget--) { s->failed_pc=0x0c0c66d8u; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c0c66da: /* original 2452, guest PC 0x0c0c66da */
if(!s->budget--) { s->failed_pc=0x0c0c66dau; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c0c66dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66dcu; return 0; } return 1;
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
P_0c0c9910: /* original 2fe6, guest PC 0x0c0c9910 */
if(!s->budget--) { s->failed_pc=0x0c0c9910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9912;
P_0c0c9912: /* original 903f, guest PC 0x0c0c9912 */
if(!s->budget--) { s->failed_pc=0x0c0c9912u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9994u,2);
goto P_0c0c9914;
P_0c0c9914: /* original de22, guest PC 0x0c0c9914 */
if(!s->budget--) { s->failed_pc=0x0c0c9914u; return 0; }
r[14]=read(ram,0x0c0c99a0u,4);
goto P_0c0c9916;
P_0c0c9916: /* original d623, guest PC 0x0c0c9916 */
if(!s->budget--) { s->failed_pc=0x0c0c9916u; return 0; }
r[6]=read(ram,0x0c0c99a4u,4);
goto P_0c0c9918;
P_0c0c9918: /* original 05ee, guest PC 0x0c0c9918 */
if(!s->budget--) { s->failed_pc=0x0c0c9918u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c991a;
P_0c0c991a: /* original 903a, guest PC 0x0c0c991a */
if(!s->budget--) { s->failed_pc=0x0c0c991au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9992u,2);
goto P_0c0c991c;
P_0c0c991c: /* original d322, guest PC 0x0c0c991c */
if(!s->budget--) { s->failed_pc=0x0c0c991cu; return 0; }
r[3]=read(ram,0x0c0c99a8u,4);
goto P_0c0c991e;
P_0c0c991e: /* original 4f22, guest PC 0x0c0c991e */
if(!s->budget--) { s->failed_pc=0x0c0c991eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9920;
P_0c0c9920: /* original 046c, guest PC 0x0c0c9920 */
if(!s->budget--) { s->failed_pc=0x0c0c9920u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c9922;
P_0c0c9922: /* original 2358, guest PC 0x0c0c9922 */
if(!s->budget--) { s->failed_pc=0x0c0c9922u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c9924;
P_0c0c9924: /* original 8f0f, guest PC 0x0c0c9924 */
if(!s->budget--) { s->failed_pc=0x0c0c9924u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(!cond) { goto P_0c0c9946; }
goto P_0c0c9928;
P_0c0c9926: /* original e701, guest PC 0x0c0c9926 */
if(!s->budget--) { s->failed_pc=0x0c0c9926u; return 0; }
r[7]=0x00000001u;
goto P_0c0c9928;
P_0c0c9928: /* original d220, guest PC 0x0c0c9928 */
if(!s->budget--) { s->failed_pc=0x0c0c9928u; return 0; }
r[2]=read(ram,0x0c0c99acu,4);
goto P_0c0c992a;
P_0c0c992a: /* original 2258, guest PC 0x0c0c992a */
if(!s->budget--) { s->failed_pc=0x0c0c992au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c992c;
P_0c0c992c: /* original 8b03, guest PC 0x0c0c992c */
if(!s->budget--) { s->failed_pc=0x0c0c992cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9936; }
goto P_0c0c992e;
P_0c0c992e: /* original 9332, guest PC 0x0c0c992e */
if(!s->budget--) { s->failed_pc=0x0c0c992eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9996u,2);
goto P_0c0c9930;
P_0c0c9930: /* original 2538, guest PC 0x0c0c9930 */
if(!s->budget--) { s->failed_pc=0x0c0c9930u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c9932;
P_0c0c9932: /* original 8d46, guest PC 0x0c0c9932 */
if(!s->budget--) { s->failed_pc=0x0c0c9932u; return 0; }
cond=r[17]&1u;
r[7]=0xffffffffu;
if(cond) { goto P_0c0c99c2; }
goto P_0c0c9936;
P_0c0c9934: /* original e7ff, guest PC 0x0c0c9934 */
if(!s->budget--) { s->failed_pc=0x0c0c9934u; return 0; }
r[7]=0xffffffffu;
goto P_0c0c9936;
P_0c0c9936: /* original 902f, guest PC 0x0c0c9936 */
if(!s->budget--) { s->failed_pc=0x0c0c9936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9998u,2);
goto P_0c0c9938;
P_0c0c9938: /* original e303, guest PC 0x0c0c9938 */
if(!s->budget--) { s->failed_pc=0x0c0c9938u; return 0; }
r[3]=0x00000003u;
goto P_0c0c993a;
P_0c0c993a: /* original 0644, guest PC 0x0c0c993a */
if(!s->budget--) { s->failed_pc=0x0c0c993au; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c993c;
P_0c0c993c: /* original 347c, guest PC 0x0c0c993c */
if(!s->budget--) { s->failed_pc=0x0c0c993cu; return 0; }
r[4]+=r[7];
goto P_0c0c993e;
P_0c0c993e: /* original 70ff, guest PC 0x0c0c993e */
if(!s->budget--) { s->failed_pc=0x0c0c993eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9940;
P_0c0c9940: /* original 2439, guest PC 0x0c0c9940 */
if(!s->budget--) { s->failed_pc=0x0c0c9940u; return 0; }
r[4]&=r[3];
goto P_0c0c9942;
P_0c0c9942: /* original a03e, guest PC 0x0c0c9942 */
if(!s->budget--) { s->failed_pc=0x0c0c9942u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c99c2;
P_0c0c9944: /* original 0644, guest PC 0x0c0c9944 */
if(!s->budget--) { s->failed_pc=0x0c0c9944u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0c9946;
P_0c0c9946: /* original 3473, guest PC 0x0c0c9946 */
if(!s->budget--) { s->failed_pc=0x0c0c9946u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c0c9948;
P_0c0c9948: /* original 8f0e, guest PC 0x0c0c9948 */
if(!s->budget--) { s->failed_pc=0x0c0c9948u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0c9968; }
goto P_0c0c994c;
P_0c0c994a: /* original e500, guest PC 0x0c0c994a */
if(!s->budget--) { s->failed_pc=0x0c0c994au; return 0; }
r[5]=0x00000000u;
goto P_0c0c994c;
P_0c0c994c: /* original 6043, guest PC 0x0c0c994c */
if(!s->budget--) { s->failed_pc=0x0c0c994cu; return 0; }
r[0]=r[4];
goto P_0c0c994e;
P_0c0c994e: /* original 8801, guest PC 0x0c0c994e */
if(!s->budget--) { s->failed_pc=0x0c0c994eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9950;
P_0c0c9950: /* original 8d0a, guest PC 0x0c0c9950 */
if(!s->budget--) { s->failed_pc=0x0c0c9950u; return 0; }
cond=r[17]&1u;
r[5]=r[7];
if(cond) { goto P_0c0c9968; }
goto P_0c0c9954;
P_0c0c9952: /* original 6573, guest PC 0x0c0c9952 */
if(!s->budget--) { s->failed_pc=0x0c0c9952u; return 0; }
r[5]=r[7];
goto P_0c0c9954;
P_0c0c9954: /* original 6043, guest PC 0x0c0c9954 */
if(!s->budget--) { s->failed_pc=0x0c0c9954u; return 0; }
r[0]=r[4];
goto P_0c0c9956;
P_0c0c9956: /* original 8802, guest PC 0x0c0c9956 */
if(!s->budget--) { s->failed_pc=0x0c0c9956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9958;
P_0c0c9958: /* original 8d06, guest PC 0x0c0c9958 */
if(!s->budget--) { s->failed_pc=0x0c0c9958u; return 0; }
cond=r[17]&1u;
r[5]=0x00000002u;
if(cond) { goto P_0c0c9968; }
goto P_0c0c995c;
P_0c0c995a: /* original e502, guest PC 0x0c0c995a */
if(!s->budget--) { s->failed_pc=0x0c0c995au; return 0; }
r[5]=0x00000002u;
goto P_0c0c995c;
P_0c0c995c: /* original d314, guest PC 0x0c0c995c */
if(!s->budget--) { s->failed_pc=0x0c0c995cu; return 0; }
r[3]=read(ram,0x0c0c99b0u,4);
goto P_0c0c995e;
P_0c0c995e: /* original 430b, guest PC 0x0c0c995e */
if(!s->budget--) { s->failed_pc=0x0c0c995eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9962u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9962u) { target=s->pc; goto dispatch; }
goto P_0c0c9962;
P_0c0c9960: /* original 0009, guest PC 0x0c0c9960 */
if(!s->budget--) { s->failed_pc=0x0c0c9960u; return 0; }
goto P_0c0c9962;
P_0c0c9962: /* original e000, guest PC 0x0c0c9962 */
if(!s->budget--) { s->failed_pc=0x0c0c9962u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9964;
P_0c0c9964: /* original a02d, guest PC 0x0c0c9964 */
if(!s->budget--) { s->failed_pc=0x0c0c9964u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c99c2;
P_0c0c9966: /* original 80eb, guest PC 0x0c0c9966 */
if(!s->budget--) { s->failed_pc=0x0c0c9966u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9968;
P_0c0c9968: /* original 6053, guest PC 0x0c0c9968 */
if(!s->budget--) { s->failed_pc=0x0c0c9968u; return 0; }
r[0]=r[5];
goto P_0c0c996a;
P_0c0c996a: /* original 8800, guest PC 0x0c0c996a */
if(!s->budget--) { s->failed_pc=0x0c0c996au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c996c;
P_0c0c996c: /* original 8905, guest PC 0x0c0c996c */
if(!s->budget--) { s->failed_pc=0x0c0c996cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c997a; }
goto P_0c0c996e;
P_0c0c996e: /* original 8801, guest PC 0x0c0c996e */
if(!s->budget--) { s->failed_pc=0x0c0c996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c9970;
P_0c0c9970: /* original 8908, guest PC 0x0c0c9970 */
if(!s->budget--) { s->failed_pc=0x0c0c9970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9984; }
goto P_0c0c9972;
P_0c0c9972: /* original 8802, guest PC 0x0c0c9972 */
if(!s->budget--) { s->failed_pc=0x0c0c9972u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c9974;
P_0c0c9974: /* original 8922, guest PC 0x0c0c9974 */
if(!s->budget--) { s->failed_pc=0x0c0c9974u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c99bc; }
goto P_0c0c9976;
P_0c0c9976: /* original a024, guest PC 0x0c0c9976 */
if(!s->budget--) { s->failed_pc=0x0c0c9976u; return 0; }
goto P_0c0c99c2;
P_0c0c9978: /* original 0009, guest PC 0x0c0c9978 */
if(!s->budget--) { s->failed_pc=0x0c0c9978u; return 0; }
goto P_0c0c997a;
P_0c0c997a: /* original d20e, guest PC 0x0c0c997a */
if(!s->budget--) { s->failed_pc=0x0c0c997au; return 0; }
r[2]=read(ram,0x0c0c99b4u,4);
goto P_0c0c997c;
P_0c0c997c: /* original 420b, guest PC 0x0c0c997c */
if(!s->budget--) { s->failed_pc=0x0c0c997cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9980u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9980u) { target=s->pc; goto dispatch; }
goto P_0c0c9980;
P_0c0c997e: /* original 0009, guest PC 0x0c0c997e */
if(!s->budget--) { s->failed_pc=0x0c0c997eu; return 0; }
goto P_0c0c9980;
P_0c0c9980: /* original a01f, guest PC 0x0c0c9980 */
if(!s->budget--) { s->failed_pc=0x0c0c9980u; return 0; }
goto P_0c0c99c2;
P_0c0c9982: /* original 0009, guest PC 0x0c0c9982 */
if(!s->budget--) { s->failed_pc=0x0c0c9982u; return 0; }
goto P_0c0c9984;
P_0c0c9984: /* original d20c, guest PC 0x0c0c9984 */
if(!s->budget--) { s->failed_pc=0x0c0c9984u; return 0; }
r[2]=read(ram,0x0c0c99b8u,4);
goto P_0c0c9986;
P_0c0c9986: /* original 420b, guest PC 0x0c0c9986 */
if(!s->budget--) { s->failed_pc=0x0c0c9986u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c998au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c998au) { target=s->pc; goto dispatch; }
goto P_0c0c998a;
P_0c0c9988: /* original 0009, guest PC 0x0c0c9988 */
if(!s->budget--) { s->failed_pc=0x0c0c9988u; return 0; }
goto P_0c0c998a;
P_0c0c998a: /* original a01a, guest PC 0x0c0c998a */
if(!s->budget--) { s->failed_pc=0x0c0c998au; return 0; }
goto P_0c0c99c2;
P_0c0c998c: /* original 0009, guest PC 0x0c0c998c */
if(!s->budget--) { s->failed_pc=0x0c0c998cu; return 0; }
if(!vf3_matrix_family(0x0c0c998eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c998eu; return 0; } return 1;
P_0c0c99bc: /* original d23a, guest PC 0x0c0c99bc */
if(!s->budget--) { s->failed_pc=0x0c0c99bcu; return 0; }
r[2]=read(ram,0x0c0c9aa8u,4);
goto P_0c0c99be;
P_0c0c99be: /* original 420b, guest PC 0x0c0c99be */
if(!s->budget--) { s->failed_pc=0x0c0c99beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c99c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c99c2u) { target=s->pc; goto dispatch; }
goto P_0c0c99c2;
P_0c0c99c0: /* original 0009, guest PC 0x0c0c99c0 */
if(!s->budget--) { s->failed_pc=0x0c0c99c0u; return 0; }
goto P_0c0c99c2;
P_0c0c99c2: /* original 4f26, guest PC 0x0c0c99c2 */
if(!s->budget--) { s->failed_pc=0x0c0c99c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c99c4;
P_0c0c99c4: /* original d239, guest PC 0x0c0c99c4 */
if(!s->budget--) { s->failed_pc=0x0c0c99c4u; return 0; }
r[2]=read(ram,0x0c0c9aacu,4);
goto P_0c0c99c6;
P_0c0c99c6: /* original 422b, guest PC 0x0c0c99c6 */
if(!s->budget--) { s->failed_pc=0x0c0c99c6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: goto P_0c09abc4;
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
P_0c0c99c8: /* original 6ef6, guest PC 0x0c0c99c8 */
if(!s->budget--) { s->failed_pc=0x0c0c99c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c99cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c99cau; return 0; } return 1;
P_0c0c99ee: /* original 2fe6, guest PC 0x0c0c99ee */
if(!s->budget--) { s->failed_pc=0x0c0c99eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f0;
P_0c0c99f0: /* original 2fd6, guest PC 0x0c0c99f0 */
if(!s->budget--) { s->failed_pc=0x0c0c99f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f2;
P_0c0c99f2: /* original ed00, guest PC 0x0c0c99f2 */
if(!s->budget--) { s->failed_pc=0x0c0c99f2u; return 0; }
r[13]=0x00000000u;
goto P_0c0c99f4;
P_0c0c99f4: /* original 2fc6, guest PC 0x0c0c99f4 */
if(!s->budget--) { s->failed_pc=0x0c0c99f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c99f6;
P_0c0c99f6: /* original de2f, guest PC 0x0c0c99f6 */
if(!s->budget--) { s->failed_pc=0x0c0c99f6u; return 0; }
r[14]=read(ram,0x0c0c9ab4u,4);
goto P_0c0c99f8;
P_0c0c99f8: /* original 9052, guest PC 0x0c0c99f8 */
if(!s->budget--) { s->failed_pc=0x0c0c99f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c99fa;
P_0c0c99fa: /* original d52d, guest PC 0x0c0c99fa */
if(!s->budget--) { s->failed_pc=0x0c0c99fau; return 0; }
r[5]=read(ram,0x0c0c9ab0u,4);
goto P_0c0c99fc;
P_0c0c99fc: /* original 03ec, guest PC 0x0c0c99fc */
if(!s->budget--) { s->failed_pc=0x0c0c99fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c99fe;
P_0c0c99fe: /* original 4f22, guest PC 0x0c0c99fe */
if(!s->budget--) { s->failed_pc=0x0c0c99feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9a00;
P_0c0c9a00: /* original dc2d, guest PC 0x0c0c9a00 */
if(!s->budget--) { s->failed_pc=0x0c0c9a00u; return 0; }
r[12]=read(ram,0x0c0c9ab8u,4);
goto P_0c0c9a02;
P_0c0c9a02: /* original 2338, guest PC 0x0c0c9a02 */
if(!s->budget--) { s->failed_pc=0x0c0c9a02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9a04;
P_0c0c9a04: /* original 7ffc, guest PC 0x0c0c9a04 */
if(!s->budget--) { s->failed_pc=0x0c0c9a04u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9a06;
P_0c0c9a06: /* original 2f32, guest PC 0x0c0c9a06 */
if(!s->budget--) { s->failed_pc=0x0c0c9a06u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9a08;
P_0c0c9a08: /* original 904b, guest PC 0x0c0c9a08 */
if(!s->budget--) { s->failed_pc=0x0c0c9a08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa2u,2);
goto P_0c0c9a0a;
P_0c0c9a0a: /* original d62c, guest PC 0x0c0c9a0a */
if(!s->budget--) { s->failed_pc=0x0c0c9a0au; return 0; }
r[6]=read(ram,0x0c0c9abcu,4);
goto P_0c0c9a0c;
P_0c0c9a0c: /* original 075e, guest PC 0x0c0c9a0c */
if(!s->budget--) { s->failed_pc=0x0c0c9a0cu; return 0; }
r[7]=read(ram,r[5]+r[0],4);
goto P_0c0c9a0e;
P_0c0c9a0e: /* original 9046, guest PC 0x0c0c9a0e */
if(!s->budget--) { s->failed_pc=0x0c0c9a0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9a9eu,2);
goto P_0c0c9a10;
P_0c0c9a10: /* original 04ec, guest PC 0x0c0c9a10 */
if(!s->budget--) { s->failed_pc=0x0c0c9a10u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a12;
P_0c0c9a12: /* original 8f27, guest PC 0x0c0c9a12 */
if(!s->budget--) { s->failed_pc=0x0c0c9a12u; return 0; }
cond=r[17]&1u;
r[6]&=r[7];
if(!cond) { goto P_0c0c9a64; }
goto P_0c0c9a16;
P_0c0c9a14: /* original 2679, guest PC 0x0c0c9a14 */
if(!s->budget--) { s->failed_pc=0x0c0c9a14u; return 0; }
r[6]&=r[7];
goto P_0c0c9a16;
P_0c0c9a16: /* original 2668, guest PC 0x0c0c9a16 */
if(!s->budget--) { s->failed_pc=0x0c0c9a16u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a18;
P_0c0c9a18: /* original 8b09, guest PC 0x0c0c9a18 */
if(!s->budget--) { s->failed_pc=0x0c0c9a18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a2e; }
goto P_0c0c9a1a;
P_0c0c9a1a: /* original d229, guest PC 0x0c0c9a1a */
if(!s->budget--) { s->failed_pc=0x0c0c9a1au; return 0; }
r[2]=read(ram,0x0c0c9ac0u,4);
goto P_0c0c9a1c;
P_0c0c9a1c: /* original 2728, guest PC 0x0c0c9a1c */
if(!s->budget--) { s->failed_pc=0x0c0c9a1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0c9a1e;
P_0c0c9a1e: /* original 8925, guest PC 0x0c0c9a1e */
if(!s->budget--) { s->failed_pc=0x0c0c9a1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a20;
P_0c0c9a20: /* original 9040, guest PC 0x0c0c9a20 */
if(!s->budget--) { s->failed_pc=0x0c0c9a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa4u,2);
goto P_0c0c9a22;
P_0c0c9a22: /* original e301, guest PC 0x0c0c9a22 */
if(!s->budget--) { s->failed_pc=0x0c0c9a22u; return 0; }
r[3]=0x00000001u;
goto P_0c0c9a24;
P_0c0c9a24: /* original 0e44, guest PC 0x0c0c9a24 */
if(!s->budget--) { s->failed_pc=0x0c0c9a24u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a26;
P_0c0c9a26: /* original 70ff, guest PC 0x0c0c9a26 */
if(!s->budget--) { s->failed_pc=0x0c0c9a26u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9a28;
P_0c0c9a28: /* original 243a, guest PC 0x0c0c9a28 */
if(!s->budget--) { s->failed_pc=0x0c0c9a28u; return 0; }
r[4]^=r[3];
goto P_0c0c9a2a;
P_0c0c9a2a: /* original a01f, guest PC 0x0c0c9a2a */
if(!s->budget--) { s->failed_pc=0x0c0c9a2au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a6c;
P_0c0c9a2c: /* original 0e44, guest PC 0x0c0c9a2c */
if(!s->budget--) { s->failed_pc=0x0c0c9a2cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9a2e;
P_0c0c9a2e: /* original 2448, guest PC 0x0c0c9a2e */
if(!s->budget--) { s->failed_pc=0x0c0c9a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9a30;
P_0c0c9a30: /* original 8b1a, guest PC 0x0c0c9a30 */
if(!s->budget--) { s->failed_pc=0x0c0c9a30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9a68; }
goto P_0c0c9a32;
P_0c0c9a32: /* original d224, guest PC 0x0c0c9a32 */
if(!s->budget--) { s->failed_pc=0x0c0c9a32u; return 0; }
r[2]=read(ram,0x0c0c9ac4u,4);
goto P_0c0c9a34;
P_0c0c9a34: /* original 420b, guest PC 0x0c0c9a34 */
if(!s->budget--) { s->failed_pc=0x0c0c9a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a38u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a38u) { target=s->pc; goto dispatch; }
goto P_0c0c9a38;
P_0c0c9a36: /* original 0009, guest PC 0x0c0c9a36 */
if(!s->budget--) { s->failed_pc=0x0c0c9a36u; return 0; }
goto P_0c0c9a38;
P_0c0c9a38: /* original d323, guest PC 0x0c0c9a38 */
if(!s->budget--) { s->failed_pc=0x0c0c9a38u; return 0; }
r[3]=read(ram,0x0c0c9ac8u,4);
goto P_0c0c9a3a;
P_0c0c9a3a: /* original 430b, guest PC 0x0c0c9a3a */
if(!s->budget--) { s->failed_pc=0x0c0c9a3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a3eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a3eu) { target=s->pc; goto dispatch; }
goto P_0c0c9a3e;
P_0c0c9a3c: /* original 0009, guest PC 0x0c0c9a3c */
if(!s->budget--) { s->failed_pc=0x0c0c9a3cu; return 0; }
goto P_0c0c9a3e;
P_0c0c9a3e: /* original 9032, guest PC 0x0c0c9a3e */
if(!s->budget--) { s->failed_pc=0x0c0c9a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa6u,2);
goto P_0c0c9a40;
P_0c0c9a40: /* original 64c3, guest PC 0x0c0c9a40 */
if(!s->budget--) { s->failed_pc=0x0c0c9a40u; return 0; }
r[4]=r[12];
goto P_0c0c9a42;
P_0c0c9a42: /* original e500, guest PC 0x0c0c9a42 */
if(!s->budget--) { s->failed_pc=0x0c0c9a42u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a44;
P_0c0c9a44: /* original 0ed4, guest PC 0x0c0c9a44 */
if(!s->budget--) { s->failed_pc=0x0c0c9a44u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a46;
P_0c0c9a46: /* original 7004, guest PC 0x0c0c9a46 */
if(!s->budget--) { s->failed_pc=0x0c0c9a46u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c9a48;
P_0c0c9a48: /* original 0ed4, guest PC 0x0c0c9a48 */
if(!s->budget--) { s->failed_pc=0x0c0c9a48u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c9a4a;
P_0c0c9a4a: /* original d320, guest PC 0x0c0c9a4a */
if(!s->budget--) { s->failed_pc=0x0c0c9a4au; return 0; }
r[3]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a4c;
P_0c0c9a4c: /* original 430b, guest PC 0x0c0c9a4c */
if(!s->budget--) { s->failed_pc=0x0c0c9a4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c9a50u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a50u) { target=s->pc; goto dispatch; }
goto P_0c0c9a50;
P_0c0c9a4e: /* original 7426, guest PC 0x0c0c9a4e */
if(!s->budget--) { s->failed_pc=0x0c0c9a4eu; return 0; }
r[4]+=0x00000026u;
goto P_0c0c9a50;
P_0c0c9a50: /* original d21e, guest PC 0x0c0c9a50 */
if(!s->budget--) { s->failed_pc=0x0c0c9a50u; return 0; }
r[2]=read(ram,0x0c0c9accu,4);
goto P_0c0c9a52;
P_0c0c9a52: /* original 64c3, guest PC 0x0c0c9a52 */
if(!s->budget--) { s->failed_pc=0x0c0c9a52u; return 0; }
r[4]=r[12];
goto P_0c0c9a54;
P_0c0c9a54: /* original e500, guest PC 0x0c0c9a54 */
if(!s->budget--) { s->failed_pc=0x0c0c9a54u; return 0; }
r[5]=0x00000000u;
goto P_0c0c9a56;
P_0c0c9a56: /* original 420b, guest PC 0x0c0c9a56 */
if(!s->budget--) { s->failed_pc=0x0c0c9a56u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9a5au;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9a5au) { target=s->pc; goto dispatch; }
goto P_0c0c9a5a;
P_0c0c9a58: /* original 7429, guest PC 0x0c0c9a58 */
if(!s->budget--) { s->failed_pc=0x0c0c9a58u; return 0; }
r[4]+=0x00000029u;
goto P_0c0c9a5a;
P_0c0c9a5a: /* original 9021, guest PC 0x0c0c9a5a */
if(!s->budget--) { s->failed_pc=0x0c0c9a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9aa0u,2);
goto P_0c0c9a5c;
P_0c0c9a5c: /* original 03ec, guest PC 0x0c0c9a5c */
if(!s->budget--) { s->failed_pc=0x0c0c9a5cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9a5e;
P_0c0c9a5e: /* original 7301, guest PC 0x0c0c9a5e */
if(!s->budget--) { s->failed_pc=0x0c0c9a5eu; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9a60;
P_0c0c9a60: /* original a004, guest PC 0x0c0c9a60 */
if(!s->budget--) { s->failed_pc=0x0c0c9a60u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a6c;
P_0c0c9a62: /* original 0e34, guest PC 0x0c0c9a62 */
if(!s->budget--) { s->failed_pc=0x0c0c9a62u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9a64;
P_0c0c9a64: /* original 2668, guest PC 0x0c0c9a64 */
if(!s->budget--) { s->failed_pc=0x0c0c9a64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9a66;
P_0c0c9a66: /* original 8901, guest PC 0x0c0c9a66 */
if(!s->budget--) { s->failed_pc=0x0c0c9a66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9a6c; }
goto P_0c0c9a68;
P_0c0c9a68: /* original 60d3, guest PC 0x0c0c9a68 */
if(!s->budget--) { s->failed_pc=0x0c0c9a68u; return 0; }
r[0]=r[13];
goto P_0c0c9a6a;
P_0c0c9a6a: /* original 805b, guest PC 0x0c0c9a6a */
if(!s->budget--) { s->failed_pc=0x0c0c9a6au; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9a6c;
P_0c0c9a6c: /* original 7f04, guest PC 0x0c0c9a6c */
if(!s->budget--) { s->failed_pc=0x0c0c9a6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9a6e;
P_0c0c9a6e: /* original d30f, guest PC 0x0c0c9a6e */
if(!s->budget--) { s->failed_pc=0x0c0c9a6eu; return 0; }
r[3]=read(ram,0x0c0c9aacu,4);
goto P_0c0c9a70;
P_0c0c9a70: /* original 4f26, guest PC 0x0c0c9a70 */
if(!s->budget--) { s->failed_pc=0x0c0c9a70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9a72;
P_0c0c9a72: /* original 6cf6, guest PC 0x0c0c9a72 */
if(!s->budget--) { s->failed_pc=0x0c0c9a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9a74;
P_0c0c9a74: /* original 6df6, guest PC 0x0c0c9a74 */
if(!s->budget--) { s->failed_pc=0x0c0c9a74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9a76;
P_0c0c9a76: /* original 432b, guest PC 0x0c0c9a76 */
if(!s->budget--) { s->failed_pc=0x0c0c9a76u; return 0; }
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
P_0c0c9a78: /* original 6ef6, guest PC 0x0c0c9a78 */
if(!s->budget--) { s->failed_pc=0x0c0c9a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9a7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9a7au; return 0; } return 1;
P_0c0c9ad0: /* original 2fe6, guest PC 0x0c0c9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9ad2;
P_0c0c9ad2: /* original 9046, guest PC 0x0c0c9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9ad4;
P_0c0c9ad4: /* original de26, guest PC 0x0c0c9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad4u; return 0; }
r[14]=read(ram,0x0c0c9b70u,4);
goto P_0c0c9ad6;
P_0c0c9ad6: /* original d525, guest PC 0x0c0c9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad6u; return 0; }
r[5]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9ad8;
P_0c0c9ad8: /* original 03ec, guest PC 0x0c0c9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ad8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9ada;
P_0c0c9ada: /* original 4f22, guest PC 0x0c0c9ada */
if(!s->budget--) { s->failed_pc=0x0c0c9adau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9adc;
P_0c0c9adc: /* original 2338, guest PC 0x0c0c9adc */
if(!s->budget--) { s->failed_pc=0x0c0c9adcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9ade;
P_0c0c9ade: /* original 7ffc, guest PC 0x0c0c9ade */
if(!s->budget--) { s->failed_pc=0x0c0c9adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c9ae0;
P_0c0c9ae0: /* original 2f32, guest PC 0x0c0c9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9ae2;
P_0c0c9ae2: /* original 903f, guest PC 0x0c0c9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9ae4;
P_0c0c9ae4: /* original d723, guest PC 0x0c0c9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae4u; return 0; }
r[7]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9ae6;
P_0c0c9ae6: /* original 065e, guest PC 0x0c0c9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae6u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0c9ae8;
P_0c0c9ae8: /* original 903d, guest PC 0x0c0c9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b66u,2);
goto P_0c0c9aea;
P_0c0c9aea: /* original 04ec, guest PC 0x0c0c9aea */
if(!s->budget--) { s->failed_pc=0x0c0c9aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9aec;
P_0c0c9aec: /* original 8f16, guest PC 0x0c0c9aec */
if(!s->budget--) { s->failed_pc=0x0c0c9aecu; return 0; }
cond=r[17]&1u;
r[7]&=r[6];
if(!cond) { goto P_0c0c9b1c; }
goto P_0c0c9af0;
P_0c0c9aee: /* original 2769, guest PC 0x0c0c9aee */
if(!s->budget--) { s->failed_pc=0x0c0c9aeeu; return 0; }
r[7]&=r[6];
goto P_0c0c9af0;
P_0c0c9af0: /* original 2778, guest PC 0x0c0c9af0 */
if(!s->budget--) { s->failed_pc=0x0c0c9af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9af2;
P_0c0c9af2: /* original 8b09, guest PC 0x0c0c9af2 */
if(!s->budget--) { s->failed_pc=0x0c0c9af2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b08; }
goto P_0c0c9af4;
P_0c0c9af4: /* original d220, guest PC 0x0c0c9af4 */
if(!s->budget--) { s->failed_pc=0x0c0c9af4u; return 0; }
r[2]=read(ram,0x0c0c9b78u,4);
goto P_0c0c9af6;
P_0c0c9af6: /* original 2628, guest PC 0x0c0c9af6 */
if(!s->budget--) { s->failed_pc=0x0c0c9af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c9af8;
P_0c0c9af8: /* original 8914, guest PC 0x0c0c9af8 */
if(!s->budget--) { s->failed_pc=0x0c0c9af8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9afa;
P_0c0c9afa: /* original 9035, guest PC 0x0c0c9afa */
if(!s->budget--) { s->failed_pc=0x0c0c9afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b68u,2);
goto P_0c0c9afc;
P_0c0c9afc: /* original e301, guest PC 0x0c0c9afc */
if(!s->budget--) { s->failed_pc=0x0c0c9afcu; return 0; }
r[3]=0x00000001u;
goto P_0c0c9afe;
P_0c0c9afe: /* original 0e44, guest PC 0x0c0c9afe */
if(!s->budget--) { s->failed_pc=0x0c0c9afeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b00;
P_0c0c9b00: /* original 70ff, guest PC 0x0c0c9b00 */
if(!s->budget--) { s->failed_pc=0x0c0c9b00u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c9b02;
P_0c0c9b02: /* original 243a, guest PC 0x0c0c9b02 */
if(!s->budget--) { s->failed_pc=0x0c0c9b02u; return 0; }
r[4]^=r[3];
goto P_0c0c9b04;
P_0c0c9b04: /* original a00e, guest PC 0x0c0c9b04 */
if(!s->budget--) { s->failed_pc=0x0c0c9b04u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b24;
P_0c0c9b06: /* original 0e44, guest PC 0x0c0c9b06 */
if(!s->budget--) { s->failed_pc=0x0c0c9b06u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c9b08;
P_0c0c9b08: /* original 2448, guest PC 0x0c0c9b08 */
if(!s->budget--) { s->failed_pc=0x0c0c9b08u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9b0a;
P_0c0c9b0a: /* original 8b09, guest PC 0x0c0c9b0a */
if(!s->budget--) { s->failed_pc=0x0c0c9b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9b20; }
goto P_0c0c9b0c;
P_0c0c9b0c: /* original d21b, guest PC 0x0c0c9b0c */
if(!s->budget--) { s->failed_pc=0x0c0c9b0cu; return 0; }
r[2]=read(ram,0x0c0c9b7cu,4);
goto P_0c0c9b0e;
P_0c0c9b0e: /* original 420b, guest PC 0x0c0c9b0e */
if(!s->budget--) { s->failed_pc=0x0c0c9b0eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b12u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b12u) { target=s->pc; goto dispatch; }
goto P_0c0c9b12;
P_0c0c9b10: /* original 0009, guest PC 0x0c0c9b10 */
if(!s->budget--) { s->failed_pc=0x0c0c9b10u; return 0; }
goto P_0c0c9b12;
P_0c0c9b12: /* original 9026, guest PC 0x0c0c9b12 */
if(!s->budget--) { s->failed_pc=0x0c0c9b12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b62u,2);
goto P_0c0c9b14;
P_0c0c9b14: /* original 03ec, guest PC 0x0c0c9b14 */
if(!s->budget--) { s->failed_pc=0x0c0c9b14u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c9b16;
P_0c0c9b16: /* original 7301, guest PC 0x0c0c9b16 */
if(!s->budget--) { s->failed_pc=0x0c0c9b16u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c9b18;
P_0c0c9b18: /* original a004, guest PC 0x0c0c9b18 */
if(!s->budget--) { s->failed_pc=0x0c0c9b18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b24;
P_0c0c9b1a: /* original 0e34, guest PC 0x0c0c9b1a */
if(!s->budget--) { s->failed_pc=0x0c0c9b1au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c9b1c;
P_0c0c9b1c: /* original 2778, guest PC 0x0c0c9b1c */
if(!s->budget--) { s->failed_pc=0x0c0c9b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9b1e;
P_0c0c9b1e: /* original 8901, guest PC 0x0c0c9b1e */
if(!s->budget--) { s->failed_pc=0x0c0c9b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b24; }
goto P_0c0c9b20;
P_0c0c9b20: /* original e000, guest PC 0x0c0c9b20 */
if(!s->budget--) { s->failed_pc=0x0c0c9b20u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b22;
P_0c0c9b22: /* original 805b, guest PC 0x0c0c9b22 */
if(!s->budget--) { s->failed_pc=0x0c0c9b22u; return 0; }
write(ram,r[5]+11,r[0],1);
goto P_0c0c9b24;
P_0c0c9b24: /* original 7f04, guest PC 0x0c0c9b24 */
if(!s->budget--) { s->failed_pc=0x0c0c9b24u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c9b26;
P_0c0c9b26: /* original d316, guest PC 0x0c0c9b26 */
if(!s->budget--) { s->failed_pc=0x0c0c9b26u; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b28;
P_0c0c9b28: /* original 4f26, guest PC 0x0c0c9b28 */
if(!s->budget--) { s->failed_pc=0x0c0c9b28u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b2a;
P_0c0c9b2a: /* original 432b, guest PC 0x0c0c9b2a */
if(!s->budget--) { s->failed_pc=0x0c0c9b2au; return 0; }
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
P_0c0c9b2c: /* original 6ef6, guest PC 0x0c0c9b2c */
if(!s->budget--) { s->failed_pc=0x0c0c9b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b2eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b2eu; return 0; } return 1;
P_0c0c9b40: /* original 2fe6, guest PC 0x0c0c9b40 */
if(!s->budget--) { s->failed_pc=0x0c0c9b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c9b42;
P_0c0c9b42: /* original 900f, guest PC 0x0c0c9b42 */
if(!s->budget--) { s->failed_pc=0x0c0c9b42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9b64u,2);
goto P_0c0c9b44;
P_0c0c9b44: /* original de09, guest PC 0x0c0c9b44 */
if(!s->budget--) { s->failed_pc=0x0c0c9b44u; return 0; }
r[14]=read(ram,0x0c0c9b6cu,4);
goto P_0c0c9b46;
P_0c0c9b46: /* original d30b, guest PC 0x0c0c9b46 */
if(!s->budget--) { s->failed_pc=0x0c0c9b46u; return 0; }
r[3]=read(ram,0x0c0c9b74u,4);
goto P_0c0c9b48;
P_0c0c9b48: /* original 04ee, guest PC 0x0c0c9b48 */
if(!s->budget--) { s->failed_pc=0x0c0c9b48u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c9b4a;
P_0c0c9b4a: /* original 4f22, guest PC 0x0c0c9b4a */
if(!s->budget--) { s->failed_pc=0x0c0c9b4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9b4c;
P_0c0c9b4c: /* original 2438, guest PC 0x0c0c9b4c */
if(!s->budget--) { s->failed_pc=0x0c0c9b4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c9b4e;
P_0c0c9b4e: /* original 8904, guest PC 0x0c0c9b4e */
if(!s->budget--) { s->failed_pc=0x0c0c9b4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9b5a; }
goto P_0c0c9b50;
P_0c0c9b50: /* original d20c, guest PC 0x0c0c9b50 */
if(!s->budget--) { s->failed_pc=0x0c0c9b50u; return 0; }
r[2]=read(ram,0x0c0c9b84u,4);
goto P_0c0c9b52;
P_0c0c9b52: /* original 420b, guest PC 0x0c0c9b52 */
if(!s->budget--) { s->failed_pc=0x0c0c9b52u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c9b56u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c9b56u) { target=s->pc; goto dispatch; }
goto P_0c0c9b56;
P_0c0c9b54: /* original 0009, guest PC 0x0c0c9b54 */
if(!s->budget--) { s->failed_pc=0x0c0c9b54u; return 0; }
goto P_0c0c9b56;
P_0c0c9b56: /* original e000, guest PC 0x0c0c9b56 */
if(!s->budget--) { s->failed_pc=0x0c0c9b56u; return 0; }
r[0]=0x00000000u;
goto P_0c0c9b58;
P_0c0c9b58: /* original 80eb, guest PC 0x0c0c9b58 */
if(!s->budget--) { s->failed_pc=0x0c0c9b58u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0c9b5a;
P_0c0c9b5a: /* original 4f26, guest PC 0x0c0c9b5a */
if(!s->budget--) { s->failed_pc=0x0c0c9b5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9b5c;
P_0c0c9b5c: /* original d308, guest PC 0x0c0c9b5c */
if(!s->budget--) { s->failed_pc=0x0c0c9b5cu; return 0; }
r[3]=read(ram,0x0c0c9b80u,4);
goto P_0c0c9b5e;
P_0c0c9b5e: /* original 432b, guest PC 0x0c0c9b5e */
if(!s->budget--) { s->failed_pc=0x0c0c9b5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09abc4u: goto P_0c09abc4;
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
P_0c0c9b60: /* original 6ef6, guest PC 0x0c0c9b60 */
if(!s->budget--) { s->failed_pc=0x0c0c9b60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c9b62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b62u; return 0; } return 1;
P_0c0c9b90: /* original 000b, guest PC 0x0c0c9b90 */
if(!s->budget--) { s->failed_pc=0x0c0c9b90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9b92: /* original 0009, guest PC 0x0c0c9b92 */
if(!s->budget--) { s->failed_pc=0x0c0c9b92u; return 0; }
if(!vf3_matrix_family(0x0c0c9b94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9b94u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
