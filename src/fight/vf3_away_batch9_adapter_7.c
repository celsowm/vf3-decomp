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
int vf3_away_batch9_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c068636u: goto P_0c068636;
case 0x0c068638u: goto P_0c068638;
case 0x0c06863au: goto P_0c06863a;
case 0x0c06863cu: goto P_0c06863c;
case 0x0c06863eu: goto P_0c06863e;
case 0x0c068640u: goto P_0c068640;
case 0x0c068642u: goto P_0c068642;
case 0x0c068644u: goto P_0c068644;
case 0x0c068646u: goto P_0c068646;
case 0x0c068648u: goto P_0c068648;
case 0x0c06864au: goto P_0c06864a;
case 0x0c06864cu: goto P_0c06864c;
case 0x0c06864eu: goto P_0c06864e;
case 0x0c068650u: goto P_0c068650;
case 0x0c068652u: goto P_0c068652;
case 0x0c068654u: goto P_0c068654;
case 0x0c068656u: goto P_0c068656;
case 0x0c068658u: goto P_0c068658;
case 0x0c06865au: goto P_0c06865a;
case 0x0c06865cu: goto P_0c06865c;
case 0x0c06865eu: goto P_0c06865e;
case 0x0c068660u: goto P_0c068660;
case 0x0c068662u: goto P_0c068662;
case 0x0c068664u: goto P_0c068664;
case 0x0c068666u: goto P_0c068666;
case 0x0c068668u: goto P_0c068668;
case 0x0c06866au: goto P_0c06866a;
case 0x0c06866cu: goto P_0c06866c;
case 0x0c06866eu: goto P_0c06866e;
case 0x0c068670u: goto P_0c068670;
case 0x0c068672u: goto P_0c068672;
case 0x0c068674u: goto P_0c068674;
case 0x0c068676u: goto P_0c068676;
case 0x0c068678u: goto P_0c068678;
case 0x0c06867au: goto P_0c06867a;
case 0x0c06867cu: goto P_0c06867c;
case 0x0c06867eu: goto P_0c06867e;
case 0x0c068680u: goto P_0c068680;
case 0x0c068682u: goto P_0c068682;
case 0x0c068684u: goto P_0c068684;
case 0x0c068686u: goto P_0c068686;
case 0x0c068688u: goto P_0c068688;
case 0x0c06868au: goto P_0c06868a;
case 0x0c06868cu: goto P_0c06868c;
case 0x0c06868eu: goto P_0c06868e;
case 0x0c068690u: goto P_0c068690;
case 0x0c068692u: goto P_0c068692;
case 0x0c068694u: goto P_0c068694;
case 0x0c068696u: goto P_0c068696;
case 0x0c068698u: goto P_0c068698;
case 0x0c06869au: goto P_0c06869a;
case 0x0c06869cu: goto P_0c06869c;
case 0x0c06869eu: goto P_0c06869e;
case 0x0c0686a0u: goto P_0c0686a0;
case 0x0c0686a2u: goto P_0c0686a2;
case 0x0c0686a4u: goto P_0c0686a4;
case 0x0c0686a6u: goto P_0c0686a6;
case 0x0c0686a8u: goto P_0c0686a8;
case 0x0c0686aau: goto P_0c0686aa;
case 0x0c0686acu: goto P_0c0686ac;
case 0x0c0686aeu: goto P_0c0686ae;
case 0x0c0686b0u: goto P_0c0686b0;
case 0x0c0686b2u: goto P_0c0686b2;
case 0x0c0686b4u: goto P_0c0686b4;
case 0x0c0686b6u: goto P_0c0686b6;
case 0x0c0686b8u: goto P_0c0686b8;
case 0x0c0686bau: goto P_0c0686ba;
case 0x0c0686bcu: goto P_0c0686bc;
case 0x0c0686beu: goto P_0c0686be;
case 0x0c0686c0u: goto P_0c0686c0;
case 0x0c0686ecu: goto P_0c0686ec;
case 0x0c0686eeu: goto P_0c0686ee;
case 0x0c0686f0u: goto P_0c0686f0;
case 0x0c0686f2u: goto P_0c0686f2;
case 0x0c0686f4u: goto P_0c0686f4;
case 0x0c0686f6u: goto P_0c0686f6;
case 0x0c0686f8u: goto P_0c0686f8;
case 0x0c0686fau: goto P_0c0686fa;
case 0x0c0686fcu: goto P_0c0686fc;
case 0x0c0686feu: goto P_0c0686fe;
case 0x0c068700u: goto P_0c068700;
case 0x0c068702u: goto P_0c068702;
case 0x0c068704u: goto P_0c068704;
case 0x0c068706u: goto P_0c068706;
case 0x0c068708u: goto P_0c068708;
case 0x0c06870au: goto P_0c06870a;
case 0x0c06870cu: goto P_0c06870c;
case 0x0c06870eu: goto P_0c06870e;
case 0x0c068710u: goto P_0c068710;
case 0x0c068712u: goto P_0c068712;
case 0x0c068714u: goto P_0c068714;
case 0x0c068716u: goto P_0c068716;
case 0x0c068718u: goto P_0c068718;
case 0x0c06871au: goto P_0c06871a;
case 0x0c06871cu: goto P_0c06871c;
case 0x0c06871eu: goto P_0c06871e;
case 0x0c068720u: goto P_0c068720;
case 0x0c068722u: goto P_0c068722;
case 0x0c068724u: goto P_0c068724;
case 0x0c068726u: goto P_0c068726;
case 0x0c068728u: goto P_0c068728;
case 0x0c06872au: goto P_0c06872a;
case 0x0c06872cu: goto P_0c06872c;
case 0x0c06872eu: goto P_0c06872e;
case 0x0c068730u: goto P_0c068730;
case 0x0c068732u: goto P_0c068732;
case 0x0c068734u: goto P_0c068734;
case 0x0c068736u: goto P_0c068736;
case 0x0c068738u: goto P_0c068738;
case 0x0c06873au: goto P_0c06873a;
case 0x0c06873cu: goto P_0c06873c;
case 0x0c06873eu: goto P_0c06873e;
case 0x0c068740u: goto P_0c068740;
case 0x0c068742u: goto P_0c068742;
case 0x0c068744u: goto P_0c068744;
case 0x0c068746u: goto P_0c068746;
case 0x0c068748u: goto P_0c068748;
case 0x0c06874au: goto P_0c06874a;
case 0x0c06874cu: goto P_0c06874c;
case 0x0c06874eu: goto P_0c06874e;
case 0x0c068750u: goto P_0c068750;
case 0x0c068752u: goto P_0c068752;
case 0x0c068754u: goto P_0c068754;
case 0x0c068756u: goto P_0c068756;
case 0x0c068758u: goto P_0c068758;
case 0x0c06875au: goto P_0c06875a;
case 0x0c06875cu: goto P_0c06875c;
case 0x0c06875eu: goto P_0c06875e;
case 0x0c068760u: goto P_0c068760;
case 0x0c068762u: goto P_0c068762;
case 0x0c068764u: goto P_0c068764;
case 0x0c068766u: goto P_0c068766;
case 0x0c068768u: goto P_0c068768;
case 0x0c06876au: goto P_0c06876a;
case 0x0c06876cu: goto P_0c06876c;
case 0x0c06876eu: goto P_0c06876e;
case 0x0c068770u: goto P_0c068770;
case 0x0c068772u: goto P_0c068772;
case 0x0c068774u: goto P_0c068774;
case 0x0c068776u: goto P_0c068776;
case 0x0c068778u: goto P_0c068778;
case 0x0c06877au: goto P_0c06877a;
case 0x0c06877cu: goto P_0c06877c;
case 0x0c06877eu: goto P_0c06877e;
case 0x0c068780u: goto P_0c068780;
case 0x0c068782u: goto P_0c068782;
case 0x0c068784u: goto P_0c068784;
case 0x0c068786u: goto P_0c068786;
case 0x0c068788u: goto P_0c068788;
case 0x0c06878au: goto P_0c06878a;
case 0x0c06878cu: goto P_0c06878c;
case 0x0c06878eu: goto P_0c06878e;
case 0x0c068790u: goto P_0c068790;
case 0x0c068792u: goto P_0c068792;
case 0x0c068794u: goto P_0c068794;
case 0x0c068796u: goto P_0c068796;
case 0x0c068798u: goto P_0c068798;
case 0x0c06879au: goto P_0c06879a;
case 0x0c06879cu: goto P_0c06879c;
case 0x0c06879eu: goto P_0c06879e;
case 0x0c0687a0u: goto P_0c0687a0;
case 0x0c0687a2u: goto P_0c0687a2;
case 0x0c0687a4u: goto P_0c0687a4;
case 0x0c0687a6u: goto P_0c0687a6;
case 0x0c0687a8u: goto P_0c0687a8;
case 0x0c0687aau: goto P_0c0687aa;
case 0x0c0687acu: goto P_0c0687ac;
case 0x0c0687aeu: goto P_0c0687ae;
case 0x0c0687b0u: goto P_0c0687b0;
case 0x0c0687b2u: goto P_0c0687b2;
case 0x0c0687b4u: goto P_0c0687b4;
case 0x0c0687b6u: goto P_0c0687b6;
case 0x0c0687b8u: goto P_0c0687b8;
case 0x0c0687bau: goto P_0c0687ba;
case 0x0c0687bcu: goto P_0c0687bc;
case 0x0c0687beu: goto P_0c0687be;
case 0x0c0687c0u: goto P_0c0687c0;
case 0x0c0687c2u: goto P_0c0687c2;
case 0x0c0687c4u: goto P_0c0687c4;
case 0x0c0687c6u: goto P_0c0687c6;
case 0x0c0687c8u: goto P_0c0687c8;
case 0x0c0687cau: goto P_0c0687ca;
case 0x0c0687ccu: goto P_0c0687cc;
case 0x0c0687ceu: goto P_0c0687ce;
case 0x0c0687d0u: goto P_0c0687d0;
case 0x0c0687d2u: goto P_0c0687d2;
case 0x0c0687d4u: goto P_0c0687d4;
case 0x0c0687d6u: goto P_0c0687d6;
case 0x0c0687d8u: goto P_0c0687d8;
case 0x0c0687dau: goto P_0c0687da;
case 0x0c0687dcu: goto P_0c0687dc;
case 0x0c0687deu: goto P_0c0687de;
case 0x0c0687e0u: goto P_0c0687e0;
case 0x0c0687e2u: goto P_0c0687e2;
case 0x0c0687eau: goto P_0c0687ea;
case 0x0c0687ecu: goto P_0c0687ec;
case 0x0c0687eeu: goto P_0c0687ee;
case 0x0c0687f0u: goto P_0c0687f0;
case 0x0c0687f2u: goto P_0c0687f2;
case 0x0c0687f4u: goto P_0c0687f4;
case 0x0c0687f6u: goto P_0c0687f6;
case 0x0c0687f8u: goto P_0c0687f8;
case 0x0c0687fau: goto P_0c0687fa;
case 0x0c0687fcu: goto P_0c0687fc;
case 0x0c0687feu: goto P_0c0687fe;
case 0x0c068800u: goto P_0c068800;
case 0x0c068802u: goto P_0c068802;
case 0x0c068804u: goto P_0c068804;
case 0x0c068806u: goto P_0c068806;
case 0x0c068808u: goto P_0c068808;
case 0x0c06880au: goto P_0c06880a;
case 0x0c06880cu: goto P_0c06880c;
case 0x0c06880eu: goto P_0c06880e;
case 0x0c068810u: goto P_0c068810;
case 0x0c068812u: goto P_0c068812;
case 0x0c068814u: goto P_0c068814;
case 0x0c068816u: goto P_0c068816;
case 0x0c068818u: goto P_0c068818;
case 0x0c06881au: goto P_0c06881a;
case 0x0c06881cu: goto P_0c06881c;
case 0x0c06881eu: goto P_0c06881e;
case 0x0c068820u: goto P_0c068820;
case 0x0c068822u: goto P_0c068822;
case 0x0c068824u: goto P_0c068824;
case 0x0c068826u: goto P_0c068826;
case 0x0c068828u: goto P_0c068828;
case 0x0c06882au: goto P_0c06882a;
case 0x0c06882cu: goto P_0c06882c;
case 0x0c06882eu: goto P_0c06882e;
case 0x0c068830u: goto P_0c068830;
case 0x0c068832u: goto P_0c068832;
case 0x0c068834u: goto P_0c068834;
case 0x0c068836u: goto P_0c068836;
case 0x0c068838u: goto P_0c068838;
case 0x0c06883au: goto P_0c06883a;
case 0x0c06883cu: goto P_0c06883c;
case 0x0c06883eu: goto P_0c06883e;
case 0x0c068840u: goto P_0c068840;
case 0x0c068842u: goto P_0c068842;
case 0x0c068844u: goto P_0c068844;
case 0x0c068846u: goto P_0c068846;
case 0x0c068848u: goto P_0c068848;
case 0x0c06884au: goto P_0c06884a;
case 0x0c06884cu: goto P_0c06884c;
case 0x0c06884eu: goto P_0c06884e;
case 0x0c068850u: goto P_0c068850;
case 0x0c068852u: goto P_0c068852;
case 0x0c068854u: goto P_0c068854;
case 0x0c068856u: goto P_0c068856;
case 0x0c068858u: goto P_0c068858;
case 0x0c06885au: goto P_0c06885a;
case 0x0c06885cu: goto P_0c06885c;
case 0x0c06885eu: goto P_0c06885e;
case 0x0c068860u: goto P_0c068860;
case 0x0c068862u: goto P_0c068862;
case 0x0c068864u: goto P_0c068864;
case 0x0c068866u: goto P_0c068866;
case 0x0c068868u: goto P_0c068868;
case 0x0c06886au: goto P_0c06886a;
case 0x0c06886cu: goto P_0c06886c;
case 0x0c06886eu: goto P_0c06886e;
case 0x0c068870u: goto P_0c068870;
case 0x0c068872u: goto P_0c068872;
case 0x0c068874u: goto P_0c068874;
case 0x0c068876u: goto P_0c068876;
case 0x0c068878u: goto P_0c068878;
case 0x0c06887au: goto P_0c06887a;
case 0x0c06887cu: goto P_0c06887c;
case 0x0c06887eu: goto P_0c06887e;
case 0x0c068880u: goto P_0c068880;
case 0x0c068882u: goto P_0c068882;
case 0x0c068884u: goto P_0c068884;
case 0x0c068886u: goto P_0c068886;
case 0x0c068888u: goto P_0c068888;
case 0x0c06888au: goto P_0c06888a;
case 0x0c06888cu: goto P_0c06888c;
case 0x0c06888eu: goto P_0c06888e;
case 0x0c068890u: goto P_0c068890;
case 0x0c068892u: goto P_0c068892;
case 0x0c068894u: goto P_0c068894;
case 0x0c068896u: goto P_0c068896;
case 0x0c068898u: goto P_0c068898;
case 0x0c06889au: goto P_0c06889a;
case 0x0c06889cu: goto P_0c06889c;
case 0x0c06889eu: goto P_0c06889e;
case 0x0c0688a0u: goto P_0c0688a0;
case 0x0c0688a2u: goto P_0c0688a2;
case 0x0c0688a4u: goto P_0c0688a4;
case 0x0c0688a6u: goto P_0c0688a6;
case 0x0c0688a8u: goto P_0c0688a8;
case 0x0c0688aau: goto P_0c0688aa;
case 0x0c0688acu: goto P_0c0688ac;
case 0x0c0688aeu: goto P_0c0688ae;
case 0x0c0688b0u: goto P_0c0688b0;
case 0x0c0688b2u: goto P_0c0688b2;
case 0x0c0688b4u: goto P_0c0688b4;
case 0x0c0688b6u: goto P_0c0688b6;
case 0x0c0688b8u: goto P_0c0688b8;
case 0x0c0688bau: goto P_0c0688ba;
case 0x0c0688bcu: goto P_0c0688bc;
case 0x0c0688beu: goto P_0c0688be;
case 0x0c0688c0u: goto P_0c0688c0;
case 0x0c0688c2u: goto P_0c0688c2;
case 0x0c0688c4u: goto P_0c0688c4;
case 0x0c0688c6u: goto P_0c0688c6;
case 0x0c0688c8u: goto P_0c0688c8;
case 0x0c0688cau: goto P_0c0688ca;
case 0x0c0688ccu: goto P_0c0688cc;
case 0x0c0688ceu: goto P_0c0688ce;
case 0x0c0688d0u: goto P_0c0688d0;
case 0x0c0688d2u: goto P_0c0688d2;
case 0x0c0688d4u: goto P_0c0688d4;
case 0x0c0688d6u: goto P_0c0688d6;
case 0x0c0688d8u: goto P_0c0688d8;
case 0x0c0688dau: goto P_0c0688da;
case 0x0c0688dcu: goto P_0c0688dc;
case 0x0c0688deu: goto P_0c0688de;
case 0x0c0688e0u: goto P_0c0688e0;
case 0x0c0688e2u: goto P_0c0688e2;
case 0x0c0688e4u: goto P_0c0688e4;
case 0x0c0688e6u: goto P_0c0688e6;
case 0x0c0688e8u: goto P_0c0688e8;
case 0x0c0688eau: goto P_0c0688ea;
case 0x0c0688ecu: goto P_0c0688ec;
case 0x0c0688eeu: goto P_0c0688ee;
case 0x0c0688f0u: goto P_0c0688f0;
case 0x0c0688f2u: goto P_0c0688f2;
case 0x0c0688f4u: goto P_0c0688f4;
case 0x0c0688f6u: goto P_0c0688f6;
case 0x0c0688f8u: goto P_0c0688f8;
case 0x0c0688fau: goto P_0c0688fa;
case 0x0c0688fcu: goto P_0c0688fc;
case 0x0c0688feu: goto P_0c0688fe;
case 0x0c068900u: goto P_0c068900;
case 0x0c068902u: goto P_0c068902;
case 0x0c068904u: goto P_0c068904;
case 0x0c068906u: goto P_0c068906;
case 0x0c068908u: goto P_0c068908;
case 0x0c06890au: goto P_0c06890a;
case 0x0c06890cu: goto P_0c06890c;
case 0x0c06890eu: goto P_0c06890e;
case 0x0c068910u: goto P_0c068910;
case 0x0c068912u: goto P_0c068912;
case 0x0c068914u: goto P_0c068914;
case 0x0c068916u: goto P_0c068916;
case 0x0c068918u: goto P_0c068918;
case 0x0c06891au: goto P_0c06891a;
case 0x0c06891cu: goto P_0c06891c;
case 0x0c06891eu: goto P_0c06891e;
case 0x0c068920u: goto P_0c068920;
case 0x0c068922u: goto P_0c068922;
case 0x0c068924u: goto P_0c068924;
case 0x0c068926u: goto P_0c068926;
case 0x0c068928u: goto P_0c068928;
case 0x0c06892au: goto P_0c06892a;
case 0x0c06892cu: goto P_0c06892c;
case 0x0c06892eu: goto P_0c06892e;
case 0x0c068930u: goto P_0c068930;
case 0x0c068932u: goto P_0c068932;
case 0x0c068934u: goto P_0c068934;
case 0x0c068936u: goto P_0c068936;
case 0x0c068938u: goto P_0c068938;
case 0x0c06893au: goto P_0c06893a;
case 0x0c06893cu: goto P_0c06893c;
case 0x0c06893eu: goto P_0c06893e;
case 0x0c068940u: goto P_0c068940;
case 0x0c068942u: goto P_0c068942;
case 0x0c068944u: goto P_0c068944;
case 0x0c068946u: goto P_0c068946;
case 0x0c068948u: goto P_0c068948;
case 0x0c06894au: goto P_0c06894a;
case 0x0c06894cu: goto P_0c06894c;
case 0x0c06894eu: goto P_0c06894e;
case 0x0c068950u: goto P_0c068950;
case 0x0c068952u: goto P_0c068952;
case 0x0c068954u: goto P_0c068954;
case 0x0c068956u: goto P_0c068956;
case 0x0c068958u: goto P_0c068958;
case 0x0c06895au: goto P_0c06895a;
case 0x0c06895cu: goto P_0c06895c;
case 0x0c06895eu: goto P_0c06895e;
case 0x0c068960u: goto P_0c068960;
case 0x0c068962u: goto P_0c068962;
case 0x0c068964u: goto P_0c068964;
case 0x0c068974u: goto P_0c068974;
case 0x0c068976u: goto P_0c068976;
case 0x0c068978u: goto P_0c068978;
case 0x0c06897au: goto P_0c06897a;
case 0x0c06897cu: goto P_0c06897c;
case 0x0c06897eu: goto P_0c06897e;
case 0x0c068980u: goto P_0c068980;
case 0x0c068982u: goto P_0c068982;
case 0x0c068984u: goto P_0c068984;
case 0x0c068986u: goto P_0c068986;
case 0x0c068988u: goto P_0c068988;
case 0x0c06898au: goto P_0c06898a;
case 0x0c06898cu: goto P_0c06898c;
case 0x0c06898eu: goto P_0c06898e;
case 0x0c068992u: goto P_0c068992;
case 0x0c068994u: goto P_0c068994;
case 0x0c068996u: goto P_0c068996;
case 0x0c068998u: goto P_0c068998;
case 0x0c06899au: goto P_0c06899a;
case 0x0c06899cu: goto P_0c06899c;
case 0x0c06899eu: goto P_0c06899e;
case 0x0c0689a0u: goto P_0c0689a0;
case 0x0c0689a2u: goto P_0c0689a2;
case 0x0c0689a4u: goto P_0c0689a4;
case 0x0c0689a6u: goto P_0c0689a6;
case 0x0c0689a8u: goto P_0c0689a8;
case 0x0c0689aau: goto P_0c0689aa;
case 0x0c0689acu: goto P_0c0689ac;
case 0x0c0689aeu: goto P_0c0689ae;
case 0x0c0689b0u: goto P_0c0689b0;
case 0x0c0689b2u: goto P_0c0689b2;
case 0x0c0689b4u: goto P_0c0689b4;
case 0x0c0689b6u: goto P_0c0689b6;
case 0x0c0689b8u: goto P_0c0689b8;
case 0x0c0689bau: goto P_0c0689ba;
case 0x0c0689bcu: goto P_0c0689bc;
case 0x0c0689beu: goto P_0c0689be;
case 0x0c0689c0u: goto P_0c0689c0;
case 0x0c0689c2u: goto P_0c0689c2;
case 0x0c0689c4u: goto P_0c0689c4;
case 0x0c0689c6u: goto P_0c0689c6;
case 0x0c0689c8u: goto P_0c0689c8;
case 0x0c0689cau: goto P_0c0689ca;
case 0x0c0689ccu: goto P_0c0689cc;
case 0x0c0689ceu: goto P_0c0689ce;
case 0x0c0689d0u: goto P_0c0689d0;
case 0x0c0689d2u: goto P_0c0689d2;
case 0x0c0689d4u: goto P_0c0689d4;
case 0x0c0689d6u: goto P_0c0689d6;
case 0x0c0689d8u: goto P_0c0689d8;
case 0x0c0689dau: goto P_0c0689da;
case 0x0c0689dcu: goto P_0c0689dc;
case 0x0c0689deu: goto P_0c0689de;
case 0x0c0689e0u: goto P_0c0689e0;
case 0x0c0689e2u: goto P_0c0689e2;
case 0x0c0689e4u: goto P_0c0689e4;
case 0x0c0689e6u: goto P_0c0689e6;
case 0x0c0689e8u: goto P_0c0689e8;
case 0x0c0689eau: goto P_0c0689ea;
case 0x0c0689ecu: goto P_0c0689ec;
case 0x0c0689eeu: goto P_0c0689ee;
case 0x0c0689f0u: goto P_0c0689f0;
case 0x0c0689f2u: goto P_0c0689f2;
case 0x0c0689f4u: goto P_0c0689f4;
case 0x0c0689f6u: goto P_0c0689f6;
case 0x0c0689f8u: goto P_0c0689f8;
case 0x0c0689fau: goto P_0c0689fa;
case 0x0c0689fcu: goto P_0c0689fc;
case 0x0c0689feu: goto P_0c0689fe;
case 0x0c068a00u: goto P_0c068a00;
case 0x0c068a02u: goto P_0c068a02;
case 0x0c068a04u: goto P_0c068a04;
case 0x0c068a06u: goto P_0c068a06;
case 0x0c068a08u: goto P_0c068a08;
case 0x0c068a0au: goto P_0c068a0a;
case 0x0c068a0cu: goto P_0c068a0c;
case 0x0c068a0eu: goto P_0c068a0e;
case 0x0c068a10u: goto P_0c068a10;
case 0x0c068a12u: goto P_0c068a12;
case 0x0c068a14u: goto P_0c068a14;
case 0x0c068a16u: goto P_0c068a16;
case 0x0c068a18u: goto P_0c068a18;
case 0x0c068a1au: goto P_0c068a1a;
case 0x0c068a1cu: goto P_0c068a1c;
case 0x0c068a1eu: goto P_0c068a1e;
case 0x0c068a20u: goto P_0c068a20;
case 0x0c068a22u: goto P_0c068a22;
case 0x0c068a24u: goto P_0c068a24;
case 0x0c068a26u: goto P_0c068a26;
case 0x0c068a28u: goto P_0c068a28;
case 0x0c068a2au: goto P_0c068a2a;
case 0x0c068a2cu: goto P_0c068a2c;
case 0x0c068a2eu: goto P_0c068a2e;
case 0x0c068a30u: goto P_0c068a30;
case 0x0c068a32u: goto P_0c068a32;
case 0x0c068a34u: goto P_0c068a34;
case 0x0c068a36u: goto P_0c068a36;
case 0x0c068a38u: goto P_0c068a38;
case 0x0c068a3au: goto P_0c068a3a;
case 0x0c068a3cu: goto P_0c068a3c;
case 0x0c068a3eu: goto P_0c068a3e;
case 0x0c068a40u: goto P_0c068a40;
case 0x0c068a42u: goto P_0c068a42;
case 0x0c068a44u: goto P_0c068a44;
case 0x0c068a46u: goto P_0c068a46;
case 0x0c068a48u: goto P_0c068a48;
case 0x0c068a4au: goto P_0c068a4a;
case 0x0c068a4cu: goto P_0c068a4c;
case 0x0c068a4eu: goto P_0c068a4e;
case 0x0c068a50u: goto P_0c068a50;
case 0x0c068a52u: goto P_0c068a52;
case 0x0c068a54u: goto P_0c068a54;
case 0x0c068a56u: goto P_0c068a56;
case 0x0c068a58u: goto P_0c068a58;
case 0x0c068a5au: goto P_0c068a5a;
case 0x0c068a5cu: goto P_0c068a5c;
case 0x0c068a5eu: goto P_0c068a5e;
case 0x0c068a60u: goto P_0c068a60;
case 0x0c068a62u: goto P_0c068a62;
case 0x0c068a64u: goto P_0c068a64;
case 0x0c068a66u: goto P_0c068a66;
case 0x0c068a68u: goto P_0c068a68;
case 0x0c068a6au: goto P_0c068a6a;
case 0x0c068a6cu: goto P_0c068a6c;
case 0x0c068a6eu: goto P_0c068a6e;
case 0x0c068a70u: goto P_0c068a70;
case 0x0c068a72u: goto P_0c068a72;
case 0x0c068a74u: goto P_0c068a74;
case 0x0c068a76u: goto P_0c068a76;
case 0x0c068a78u: goto P_0c068a78;
case 0x0c068a7au: goto P_0c068a7a;
case 0x0c068a7cu: goto P_0c068a7c;
case 0x0c068a7eu: goto P_0c068a7e;
case 0x0c068a80u: goto P_0c068a80;
case 0x0c068a82u: goto P_0c068a82;
case 0x0c068a84u: goto P_0c068a84;
case 0x0c068a86u: goto P_0c068a86;
case 0x0c068a88u: goto P_0c068a88;
case 0x0c068a8au: goto P_0c068a8a;
case 0x0c068a8cu: goto P_0c068a8c;
case 0x0c068a8eu: goto P_0c068a8e;
case 0x0c068a90u: goto P_0c068a90;
case 0x0c068a92u: goto P_0c068a92;
case 0x0c068a94u: goto P_0c068a94;
case 0x0c068a96u: goto P_0c068a96;
case 0x0c068a98u: goto P_0c068a98;
case 0x0c068a9au: goto P_0c068a9a;
case 0x0c068a9cu: goto P_0c068a9c;
case 0x0c068a9eu: goto P_0c068a9e;
case 0x0c068aa0u: goto P_0c068aa0;
case 0x0c068aa2u: goto P_0c068aa2;
case 0x0c068aa4u: goto P_0c068aa4;
case 0x0c068aa6u: goto P_0c068aa6;
case 0x0c068aa8u: goto P_0c068aa8;
case 0x0c068aaau: goto P_0c068aaa;
case 0x0c068aacu: goto P_0c068aac;
case 0x0c068aaeu: goto P_0c068aae;
case 0x0c068ab0u: goto P_0c068ab0;
case 0x0c068ab2u: goto P_0c068ab2;
case 0x0c068ab4u: goto P_0c068ab4;
case 0x0c068ab6u: goto P_0c068ab6;
case 0x0c068ab8u: goto P_0c068ab8;
case 0x0c068abau: goto P_0c068aba;
case 0x0c068abcu: goto P_0c068abc;
case 0x0c068abeu: goto P_0c068abe;
case 0x0c068ac0u: goto P_0c068ac0;
case 0x0c068ac2u: goto P_0c068ac2;
case 0x0c068ac4u: goto P_0c068ac4;
case 0x0c068ac6u: goto P_0c068ac6;
case 0x0c068ac8u: goto P_0c068ac8;
case 0x0c068acau: goto P_0c068aca;
case 0x0c068accu: goto P_0c068acc;
case 0x0c068aceu: goto P_0c068ace;
case 0x0c068ad0u: goto P_0c068ad0;
case 0x0c068ad2u: goto P_0c068ad2;
case 0x0c068ad4u: goto P_0c068ad4;
case 0x0c068ad6u: goto P_0c068ad6;
case 0x0c068ad8u: goto P_0c068ad8;
case 0x0c068adau: goto P_0c068ada;
case 0x0c068adcu: goto P_0c068adc;
case 0x0c068adeu: goto P_0c068ade;
case 0x0c068ae0u: goto P_0c068ae0;
case 0x0c068ae2u: goto P_0c068ae2;
case 0x0c068ae4u: goto P_0c068ae4;
case 0x0c068ae6u: goto P_0c068ae6;
case 0x0c068ae8u: goto P_0c068ae8;
case 0x0c068aeau: goto P_0c068aea;
case 0x0c068aecu: goto P_0c068aec;
case 0x0c068aeeu: goto P_0c068aee;
case 0x0c068af0u: goto P_0c068af0;
case 0x0c068af2u: goto P_0c068af2;
case 0x0c068af4u: goto P_0c068af4;
case 0x0c068af6u: goto P_0c068af6;
case 0x0c068af8u: goto P_0c068af8;
case 0x0c068afau: goto P_0c068afa;
case 0x0c068afcu: goto P_0c068afc;
case 0x0c068afeu: goto P_0c068afe;
case 0x0c068b00u: goto P_0c068b00;
case 0x0c068b02u: goto P_0c068b02;
case 0x0c068b04u: goto P_0c068b04;
case 0x0c068b06u: goto P_0c068b06;
case 0x0c068b08u: goto P_0c068b08;
case 0x0c068b0au: goto P_0c068b0a;
case 0x0c068b0cu: goto P_0c068b0c;
case 0x0c068b0eu: goto P_0c068b0e;
case 0x0c068b10u: goto P_0c068b10;
case 0x0c068b12u: goto P_0c068b12;
case 0x0c068b14u: goto P_0c068b14;
case 0x0c068b16u: goto P_0c068b16;
case 0x0c068b18u: goto P_0c068b18;
case 0x0c068b1au: goto P_0c068b1a;
case 0x0c068b1cu: goto P_0c068b1c;
case 0x0c068b1eu: goto P_0c068b1e;
case 0x0c068b20u: goto P_0c068b20;
case 0x0c068b22u: goto P_0c068b22;
case 0x0c068b24u: goto P_0c068b24;
case 0x0c068b26u: goto P_0c068b26;
case 0x0c068b28u: goto P_0c068b28;
case 0x0c068b2au: goto P_0c068b2a;
case 0x0c068b2cu: goto P_0c068b2c;
case 0x0c068b2eu: goto P_0c068b2e;
case 0x0c068b30u: goto P_0c068b30;
case 0x0c068b32u: goto P_0c068b32;
case 0x0c068b34u: goto P_0c068b34;
case 0x0c068b36u: goto P_0c068b36;
case 0x0c068b38u: goto P_0c068b38;
case 0x0c068b3au: goto P_0c068b3a;
case 0x0c068b3cu: goto P_0c068b3c;
case 0x0c068b3eu: goto P_0c068b3e;
case 0x0c068b40u: goto P_0c068b40;
case 0x0c068b42u: goto P_0c068b42;
case 0x0c068b44u: goto P_0c068b44;
case 0x0c068b46u: goto P_0c068b46;
case 0x0c068b48u: goto P_0c068b48;
case 0x0c068b4au: goto P_0c068b4a;
case 0x0c068b4cu: goto P_0c068b4c;
case 0x0c068b64u: goto P_0c068b64;
case 0x0c068b66u: goto P_0c068b66;
case 0x0c068b68u: goto P_0c068b68;
case 0x0c068b6au: goto P_0c068b6a;
case 0x0c068b6cu: goto P_0c068b6c;
case 0x0c068b6eu: goto P_0c068b6e;
case 0x0c068b70u: goto P_0c068b70;
case 0x0c068b72u: goto P_0c068b72;
case 0x0c068b74u: goto P_0c068b74;
case 0x0c068b76u: goto P_0c068b76;
case 0x0c068b78u: goto P_0c068b78;
case 0x0c068b7au: goto P_0c068b7a;
case 0x0c068b7cu: goto P_0c068b7c;
case 0x0c068b7eu: goto P_0c068b7e;
case 0x0c068b80u: goto P_0c068b80;
case 0x0c068b82u: goto P_0c068b82;
case 0x0c068b84u: goto P_0c068b84;
case 0x0c068b86u: goto P_0c068b86;
case 0x0c068b88u: goto P_0c068b88;
case 0x0c068b8au: goto P_0c068b8a;
case 0x0c068b8cu: goto P_0c068b8c;
case 0x0c068b8eu: goto P_0c068b8e;
case 0x0c068b90u: goto P_0c068b90;
case 0x0c068b92u: goto P_0c068b92;
case 0x0c068b94u: goto P_0c068b94;
case 0x0c068b96u: goto P_0c068b96;
case 0x0c068b98u: goto P_0c068b98;
case 0x0c068b9au: goto P_0c068b9a;
case 0x0c068b9cu: goto P_0c068b9c;
case 0x0c068b9eu: goto P_0c068b9e;
case 0x0c068ba0u: goto P_0c068ba0;
case 0x0c068ba2u: goto P_0c068ba2;
case 0x0c068ba4u: goto P_0c068ba4;
case 0x0c068ba6u: goto P_0c068ba6;
case 0x0c068ba8u: goto P_0c068ba8;
case 0x0c068baau: goto P_0c068baa;
case 0x0c068bacu: goto P_0c068bac;
case 0x0c068baeu: goto P_0c068bae;
case 0x0c068bb0u: goto P_0c068bb0;
case 0x0c068bb2u: goto P_0c068bb2;
case 0x0c068bb4u: goto P_0c068bb4;
case 0x0c068bb6u: goto P_0c068bb6;
case 0x0c068bb8u: goto P_0c068bb8;
case 0x0c068bbau: goto P_0c068bba;
case 0x0c068bbcu: goto P_0c068bbc;
case 0x0c068bbeu: goto P_0c068bbe;
case 0x0c068bc0u: goto P_0c068bc0;
case 0x0c068bc2u: goto P_0c068bc2;
case 0x0c068bc4u: goto P_0c068bc4;
case 0x0c068bc6u: goto P_0c068bc6;
case 0x0c068bc8u: goto P_0c068bc8;
case 0x0c068bcau: goto P_0c068bca;
case 0x0c068bccu: goto P_0c068bcc;
case 0x0c068bceu: goto P_0c068bce;
case 0x0c068bd0u: goto P_0c068bd0;
case 0x0c068bd2u: goto P_0c068bd2;
case 0x0c068bd4u: goto P_0c068bd4;
case 0x0c068bd6u: goto P_0c068bd6;
case 0x0c068bd8u: goto P_0c068bd8;
case 0x0c068bdau: goto P_0c068bda;
case 0x0c068bdcu: goto P_0c068bdc;
case 0x0c068bdeu: goto P_0c068bde;
case 0x0c068be0u: goto P_0c068be0;
case 0x0c068be2u: goto P_0c068be2;
case 0x0c068be4u: goto P_0c068be4;
case 0x0c068be6u: goto P_0c068be6;
case 0x0c068be8u: goto P_0c068be8;
case 0x0c068beau: goto P_0c068bea;
case 0x0c068becu: goto P_0c068bec;
case 0x0c068beeu: goto P_0c068bee;
case 0x0c068bf0u: goto P_0c068bf0;
case 0x0c068bf2u: goto P_0c068bf2;
case 0x0c068bf4u: goto P_0c068bf4;
case 0x0c068bf6u: goto P_0c068bf6;
case 0x0c068bf8u: goto P_0c068bf8;
case 0x0c068bfau: goto P_0c068bfa;
case 0x0c068bfcu: goto P_0c068bfc;
case 0x0c068bfeu: goto P_0c068bfe;
case 0x0c068c00u: goto P_0c068c00;
case 0x0c068c02u: goto P_0c068c02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c068636: /* original 2fe6, guest PC 0x0c068636 */
if(!s->budget--) { s->failed_pc=0x0c068636u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068638;
P_0c068638: /* original 2558, guest PC 0x0c068638 */
if(!s->budget--) { s->failed_pc=0x0c068638u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06863a;
P_0c06863a: /* original 2fd6, guest PC 0x0c06863a */
if(!s->budget--) { s->failed_pc=0x0c06863au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06863c;
P_0c06863c: /* original 6e43, guest PC 0x0c06863c */
if(!s->budget--) { s->failed_pc=0x0c06863cu; return 0; }
r[14]=r[4];
goto P_0c06863e;
P_0c06863e: /* original fffb, guest PC 0x0c06863e */
if(!s->budget--) { s->failed_pc=0x0c06863eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c068640;
P_0c068640: /* original ffeb, guest PC 0x0c068640 */
if(!s->budget--) { s->failed_pc=0x0c068640u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c068642;
P_0c068642: /* original 4f22, guest PC 0x0c068642 */
if(!s->budget--) { s->failed_pc=0x0c068642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068644;
P_0c068644: /* original 7fb0, guest PC 0x0c068644 */
if(!s->budget--) { s->failed_pc=0x0c068644u; return 0; }
r[15]+=0xffffffb0u;
goto P_0c068646;
P_0c068646: /* original 8d06, guest PC 0x0c068646 */
if(!s->budget--) { s->failed_pc=0x0c068646u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068656; }
goto P_0c06864a;
P_0c068648: /* original e400, guest PC 0x0c068648 */
if(!s->budget--) { s->failed_pc=0x0c068648u; return 0; }
r[4]=0x00000000u;
goto P_0c06864a;
P_0c06864a: /* original 903d, guest PC 0x0c06864a */
if(!s->budget--) { s->failed_pc=0x0c06864au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686c8u,2);
goto P_0c06864c;
P_0c06864c: /* original 6543, guest PC 0x0c06864c */
if(!s->budget--) { s->failed_pc=0x0c06864cu; return 0; }
r[5]=r[4];
goto P_0c06864e;
P_0c06864e: /* original 0e54, guest PC 0x0c06864e */
if(!s->budget--) { s->failed_pc=0x0c06864eu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c068650;
P_0c068650: /* original 70dc, guest PC 0x0c068650 */
if(!s->budget--) { s->failed_pc=0x0c068650u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c068652;
P_0c068652: /* original a011, guest PC 0x0c068652 */
if(!s->budget--) { s->failed_pc=0x0c068652u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c068678;
P_0c068654: /* original 04ee, guest PC 0x0c068654 */
if(!s->budget--) { s->failed_pc=0x0c068654u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c068656;
P_0c068656: /* original 9038, guest PC 0x0c068656 */
if(!s->budget--) { s->failed_pc=0x0c068656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686cau,2);
goto P_0c068658;
P_0c068658: /* original 6543, guest PC 0x0c068658 */
if(!s->budget--) { s->failed_pc=0x0c068658u; return 0; }
r[5]=r[4];
goto P_0c06865a;
P_0c06865a: /* original 04ee, guest PC 0x0c06865a */
if(!s->budget--) { s->failed_pc=0x0c06865au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c06865c;
P_0c06865c: /* original 85e3, guest PC 0x0c06865c */
if(!s->budget--) { s->failed_pc=0x0c06865cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c06865e;
P_0c06865e: /* original 670d, guest PC 0x0c06865e */
if(!s->budget--) { s->failed_pc=0x0c06865eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c068660;
P_0c068660: /* original e034, guest PC 0x0c068660 */
if(!s->budget--) { s->failed_pc=0x0c068660u; return 0; }
r[0]=0x00000034u;
goto P_0c068662;
P_0c068662: /* original 064d, guest PC 0x0c068662 */
if(!s->budget--) { s->failed_pc=0x0c068662u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c068664;
P_0c068664: /* original 666d, guest PC 0x0c068664 */
if(!s->budget--) { s->failed_pc=0x0c068664u; return 0; }
r[6]=r[6]&65535u;
goto P_0c068666;
P_0c068666: /* original 3760, guest PC 0x0c068666 */
if(!s->budget--) { s->failed_pc=0x0c068666u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c068668;
P_0c068668: /* original 8b15, guest PC 0x0c068668 */
if(!s->budget--) { s->failed_pc=0x0c068668u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068696; }
goto P_0c06866a;
P_0c06866a: /* original 902e, guest PC 0x0c06866a */
if(!s->budget--) { s->failed_pc=0x0c06866au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0686cau,2);
goto P_0c06866c;
P_0c06866c: /* original 741c, guest PC 0x0c06866c */
if(!s->budget--) { s->failed_pc=0x0c06866cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c06866e;
P_0c06866e: /* original 0e46, guest PC 0x0c06866e */
if(!s->budget--) { s->failed_pc=0x0c06866eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c068670;
P_0c068670: /* original 7024, guest PC 0x0c068670 */
if(!s->budget--) { s->failed_pc=0x0c068670u; return 0; }
r[0]+=0x00000024u;
goto P_0c068672;
P_0c068672: /* original 06ec, guest PC 0x0c068672 */
if(!s->budget--) { s->failed_pc=0x0c068672u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c068674;
P_0c068674: /* original 7601, guest PC 0x0c068674 */
if(!s->budget--) { s->failed_pc=0x0c068674u; return 0; }
r[6]+=0x00000001u;
goto P_0c068676;
P_0c068676: /* original 0e64, guest PC 0x0c068676 */
if(!s->budget--) { s->failed_pc=0x0c068676u; return 0; }
write(ram,r[14]+r[0],r[6],1);
goto P_0c068678;
P_0c068678: /* original e01a, guest PC 0x0c068678 */
if(!s->budget--) { s->failed_pc=0x0c068678u; return 0; }
r[0]=0x0000001au;
goto P_0c06867a;
P_0c06867a: /* original 064c, guest PC 0x0c06867a */
if(!s->budget--) { s->failed_pc=0x0c06867au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06867c;
P_0c06867c: /* original 666c, guest PC 0x0c06867c */
if(!s->budget--) { s->failed_pc=0x0c06867cu; return 0; }
r[6]=r[6]&255u;
goto P_0c06867e;
P_0c06867e: /* original 6063, guest PC 0x0c06867e */
if(!s->budget--) { s->failed_pc=0x0c06867eu; return 0; }
r[0]=r[6];
goto P_0c068680;
P_0c068680: /* original 8800, guest PC 0x0c068680 */
if(!s->budget--) { s->failed_pc=0x0c068680u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c068682;
P_0c068682: /* original 8d33, guest PC 0x0c068682 */
if(!s->budget--) { s->failed_pc=0x0c068682u; return 0; }
cond=r[17]&1u;
fr[5]=0;
if(cond) { goto P_0c0686ec; }
goto P_0c068686;
P_0c068684: /* original f58d, guest PC 0x0c068684 */
if(!s->budget--) { s->failed_pc=0x0c068684u; return 0; }
fr[5]=0;
goto P_0c068686;
P_0c068686: /* original 8801, guest PC 0x0c068686 */
if(!s->budget--) { s->failed_pc=0x0c068686u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c068688;
P_0c068688: /* original 894a, guest PC 0x0c068688 */
if(!s->budget--) { s->failed_pc=0x0c068688u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068720; }
goto P_0c06868a;
P_0c06868a: /* original 8802, guest PC 0x0c06868a */
if(!s->budget--) { s->failed_pc=0x0c06868au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06868c;
P_0c06868c: /* original 8b01, guest PC 0x0c06868c */
if(!s->budget--) { s->failed_pc=0x0c06868cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068692; }
goto P_0c06868e;
P_0c06868e: /* original a0ac, guest PC 0x0c06868e */
if(!s->budget--) { s->failed_pc=0x0c06868eu; return 0; }
goto P_0c0687ea;
P_0c068690: /* original 0009, guest PC 0x0c068690 */
if(!s->budget--) { s->failed_pc=0x0c068690u; return 0; }
goto P_0c068692;
P_0c068692: /* original aff4, guest PC 0x0c068692 */
if(!s->budget--) { s->failed_pc=0x0c068692u; return 0; }
goto P_0c06867e;
P_0c068694: /* original 0009, guest PC 0x0c068694 */
if(!s->budget--) { s->failed_pc=0x0c068694u; return 0; }
goto P_0c068696;
P_0c068696: /* original 85e3, guest PC 0x0c068696 */
if(!s->budget--) { s->failed_pc=0x0c068696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c068698;
P_0c068698: /* original 7001, guest PC 0x0c068698 */
if(!s->budget--) { s->failed_pc=0x0c068698u; return 0; }
r[0]+=0x00000001u;
goto P_0c06869a;
P_0c06869a: /* original 81e3, guest PC 0x0c06869a */
if(!s->budget--) { s->failed_pc=0x0c06869au; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c06869c;
P_0c06869c: /* original e01a, guest PC 0x0c06869c */
if(!s->budget--) { s->failed_pc=0x0c06869cu; return 0; }
r[0]=0x0000001au;
goto P_0c06869e;
P_0c06869e: /* original 064c, guest PC 0x0c06869e */
if(!s->budget--) { s->failed_pc=0x0c06869eu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0686a0;
P_0c0686a0: /* original 666c, guest PC 0x0c0686a0 */
if(!s->budget--) { s->failed_pc=0x0c0686a0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0686a2;
P_0c0686a2: /* original 6063, guest PC 0x0c0686a2 */
if(!s->budget--) { s->failed_pc=0x0c0686a2u; return 0; }
r[0]=r[6];
goto P_0c0686a4;
P_0c0686a4: /* original 8800, guest PC 0x0c0686a4 */
if(!s->budget--) { s->failed_pc=0x0c0686a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0686a6;
P_0c0686a6: /* original f49d, guest PC 0x0c0686a6 */
if(!s->budget--) { s->failed_pc=0x0c0686a6u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0686a8;
P_0c0686a8: /* original 6d43, guest PC 0x0c0686a8 */
if(!s->budget--) { s->failed_pc=0x0c0686a8u; return 0; }
r[13]=r[4];
goto P_0c0686aa;
P_0c0686aa: /* original 8f02, guest PC 0x0c0686aa */
if(!s->budget--) { s->failed_pc=0x0c0686aau; return 0; }
cond=r[17]&1u;
r[13]+=0x0000001cu;
if(!cond) { goto P_0c0686b2; }
goto P_0c0686ae;
P_0c0686ac: /* original 7d1c, guest PC 0x0c0686ac */
if(!s->budget--) { s->failed_pc=0x0c0686acu; return 0; }
r[13]+=0x0000001cu;
goto P_0c0686ae;
P_0c0686ae: /* original a273, guest PC 0x0c0686ae */
if(!s->budget--) { s->failed_pc=0x0c0686aeu; return 0; }
goto P_0c068b98;
P_0c0686b0: /* original 0009, guest PC 0x0c0686b0 */
if(!s->budget--) { s->failed_pc=0x0c0686b0u; return 0; }
goto P_0c0686b2;
P_0c0686b2: /* original 8801, guest PC 0x0c0686b2 */
if(!s->budget--) { s->failed_pc=0x0c0686b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0686b4;
P_0c0686b4: /* original 8944, guest PC 0x0c0686b4 */
if(!s->budget--) { s->failed_pc=0x0c0686b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068740; }
goto P_0c0686b6;
P_0c0686b6: /* original 8802, guest PC 0x0c0686b6 */
if(!s->budget--) { s->failed_pc=0x0c0686b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0686b8;
P_0c0686b8: /* original 8b01, guest PC 0x0c0686b8 */
if(!s->budget--) { s->failed_pc=0x0c0686b8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0686be; }
goto P_0c0686ba;
P_0c0686ba: /* original a16a, guest PC 0x0c0686ba */
if(!s->budget--) { s->failed_pc=0x0c0686bau; return 0; }
goto P_0c068992;
P_0c0686bc: /* original 0009, guest PC 0x0c0686bc */
if(!s->budget--) { s->failed_pc=0x0c0686bcu; return 0; }
goto P_0c0686be;
P_0c0686be: /* original aff0, guest PC 0x0c0686be */
if(!s->budget--) { s->failed_pc=0x0c0686beu; return 0; }
goto P_0c0686a2;
P_0c0686c0: /* original 0009, guest PC 0x0c0686c0 */
if(!s->budget--) { s->failed_pc=0x0c0686c0u; return 0; }
if(!vf3_matrix_family(0x0c0686c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0686c2u; return 0; } return 1;
P_0c0686ec: /* original e004, guest PC 0x0c0686ec */
if(!s->budget--) { s->failed_pc=0x0c0686ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0686ee;
P_0c0686ee: /* original f448, guest PC 0x0c0686ee */
if(!s->budget--) { s->failed_pc=0x0c0686eeu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0686f0;
P_0c0686f0: /* original f946, guest PC 0x0c0686f0 */
if(!s->budget--) { s->failed_pc=0x0c0686f0u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0686f2;
P_0c0686f2: /* original e008, guest PC 0x0c0686f2 */
if(!s->budget--) { s->failed_pc=0x0c0686f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0686f4;
P_0c0686f4: /* original f846, guest PC 0x0c0686f4 */
if(!s->budget--) { s->failed_pc=0x0c0686f4u; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c0686f6;
P_0c0686f6: /* original e00c, guest PC 0x0c0686f6 */
if(!s->budget--) { s->failed_pc=0x0c0686f6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0686f8;
P_0c0686f8: /* original f646, guest PC 0x0c0686f8 */
if(!s->budget--) { s->failed_pc=0x0c0686f8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0686fa;
P_0c0686fa: /* original e010, guest PC 0x0c0686fa */
if(!s->budget--) { s->failed_pc=0x0c0686fau; return 0; }
r[0]=0x00000010u;
goto P_0c0686fc;
P_0c0686fc: /* original f546, guest PC 0x0c0686fc */
if(!s->budget--) { s->failed_pc=0x0c0686fcu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0686fe;
P_0c0686fe: /* original 2558, guest PC 0x0c0686fe */
if(!s->budget--) { s->failed_pc=0x0c0686feu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068700;
P_0c068700: /* original e014, guest PC 0x0c068700 */
if(!s->budget--) { s->failed_pc=0x0c068700u; return 0; }
r[0]=0x00000014u;
goto P_0c068702;
P_0c068702: /* original 8fc8, guest PC 0x0c068702 */
if(!s->budget--) { s->failed_pc=0x0c068702u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[4]+r[0]);
if(!cond) { goto P_0c068696; }
goto P_0c068706;
P_0c068704: /* original f746, guest PC 0x0c068704 */
if(!s->budget--) { s->failed_pc=0x0c068704u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c068706;
P_0c068706: /* original e010, guest PC 0x0c068706 */
if(!s->budget--) { s->failed_pc=0x0c068706u; return 0; }
r[0]=0x00000010u;
goto P_0c068708;
P_0c068708: /* original fe47, guest PC 0x0c068708 */
if(!s->budget--) { s->failed_pc=0x0c068708u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06870a;
P_0c06870a: /* original e014, guest PC 0x0c06870a */
if(!s->budget--) { s->failed_pc=0x0c06870au; return 0; }
r[0]=0x00000014u;
goto P_0c06870c;
P_0c06870c: /* original fe97, guest PC 0x0c06870c */
if(!s->budget--) { s->failed_pc=0x0c06870cu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c06870e;
P_0c06870e: /* original e018, guest PC 0x0c06870e */
if(!s->budget--) { s->failed_pc=0x0c06870eu; return 0; }
r[0]=0x00000018u;
goto P_0c068710;
P_0c068710: /* original fe87, guest PC 0x0c068710 */
if(!s->budget--) { s->failed_pc=0x0c068710u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c068712;
P_0c068712: /* original 9067, guest PC 0x0c068712 */
if(!s->budget--) { s->failed_pc=0x0c068712u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e4u,2);
goto P_0c068714;
P_0c068714: /* original fe67, guest PC 0x0c068714 */
if(!s->budget--) { s->failed_pc=0x0c068714u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068716;
P_0c068716: /* original 7004, guest PC 0x0c068716 */
if(!s->budget--) { s->failed_pc=0x0c068716u; return 0; }
r[0]+=0x00000004u;
goto P_0c068718;
P_0c068718: /* original fe57, guest PC 0x0c068718 */
if(!s->budget--) { s->failed_pc=0x0c068718u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06871a;
P_0c06871a: /* original 7004, guest PC 0x0c06871a */
if(!s->budget--) { s->failed_pc=0x0c06871au; return 0; }
r[0]+=0x00000004u;
goto P_0c06871c;
P_0c06871c: /* original afbb, guest PC 0x0c06871c */
if(!s->budget--) { s->failed_pc=0x0c06871cu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068696;
P_0c06871e: /* original fe77, guest PC 0x0c06871e */
if(!s->budget--) { s->failed_pc=0x0c06871eu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068720;
P_0c068720: /* original e034, guest PC 0x0c068720 */
if(!s->budget--) { s->failed_pc=0x0c068720u; return 0; }
r[0]=0x00000034u;
goto P_0c068722;
P_0c068722: /* original 074d, guest PC 0x0c068722 */
if(!s->budget--) { s->failed_pc=0x0c068722u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c068724;
P_0c068724: /* original 854c, guest PC 0x0c068724 */
if(!s->budget--) { s->failed_pc=0x0c068724u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c068726;
P_0c068726: /* original 677d, guest PC 0x0c068726 */
if(!s->budget--) { s->failed_pc=0x0c068726u; return 0; }
r[7]=r[7]&65535u;
goto P_0c068728;
P_0c068728: /* original 6373, guest PC 0x0c068728 */
if(!s->budget--) { s->failed_pc=0x0c068728u; return 0; }
r[3]=r[7];
goto P_0c06872a;
P_0c06872a: /* original 660d, guest PC 0x0c06872a */
if(!s->budget--) { s->failed_pc=0x0c06872au; return 0; }
r[6]=r[0]&65535u;
goto P_0c06872c;
P_0c06872c: /* original 3368, guest PC 0x0c06872c */
if(!s->budget--) { s->failed_pc=0x0c06872cu; return 0; }
r[3]-=r[6];
goto P_0c06872e;
P_0c06872e: /* original 905a, guest PC 0x0c06872e */
if(!s->budget--) { s->failed_pc=0x0c06872eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e6u,2);
goto P_0c068730;
P_0c068730: /* original 6633, guest PC 0x0c068730 */
if(!s->budget--) { s->failed_pc=0x0c068730u; return 0; }
r[6]=r[3];
goto P_0c068732;
P_0c068732: /* original 465a, guest PC 0x0c068732 */
if(!s->budget--) { s->failed_pc=0x0c068732u; return 0; }
r[53]=r[6];
goto P_0c068734;
P_0c068734: /* original f32d, guest PC 0x0c068734 */
if(!s->budget--) { s->failed_pc=0x0c068734u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068736;
P_0c068736: /* original fe37, guest PC 0x0c068736 */
if(!s->budget--) { s->failed_pc=0x0c068736u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068738;
P_0c068738: /* original 70e4, guest PC 0x0c068738 */
if(!s->budget--) { s->failed_pc=0x0c068738u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06873a;
P_0c06873a: /* original f45c, guest PC 0x0c06873a */
if(!s->budget--) { s->failed_pc=0x0c06873au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06873c;
P_0c06873c: /* original afab, guest PC 0x0c06873c */
if(!s->budget--) { s->failed_pc=0x0c06873cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068696;
P_0c06873e: /* original fe47, guest PC 0x0c06873e */
if(!s->budget--) { s->failed_pc=0x0c06873eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068740;
P_0c068740: /* original f8d8, guest PC 0x0c068740 */
if(!s->budget--) { s->failed_pc=0x0c068740u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c068742;
P_0c068742: /* original f748, guest PC 0x0c068742 */
if(!s->budget--) { s->failed_pc=0x0c068742u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
goto P_0c068744;
P_0c068744: /* original 904f, guest PC 0x0c068744 */
if(!s->budget--) { s->failed_pc=0x0c068744u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e6u,2);
goto P_0c068746;
P_0c068746: /* original f871, guest PC 0x0c068746 */
if(!s->budget--) { s->failed_pc=0x0c068746u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'-');
goto P_0c068748;
P_0c068748: /* original f5e6, guest PC 0x0c068748 */
if(!s->budget--) { s->failed_pc=0x0c068748u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c06874a;
P_0c06874a: /* original 70e4, guest PC 0x0c06874a */
if(!s->budget--) { s->failed_pc=0x0c06874au; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06874c;
P_0c06874c: /* original f6e6, guest PC 0x0c06874c */
if(!s->budget--) { s->failed_pc=0x0c06874cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c06874e;
P_0c06874e: /* original e004, guest PC 0x0c06874e */
if(!s->budget--) { s->failed_pc=0x0c06874eu; return 0; }
r[0]=0x00000004u;
goto P_0c068750;
P_0c068750: /* original f9d6, guest PC 0x0c068750 */
if(!s->budget--) { s->failed_pc=0x0c068750u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c068752;
P_0c068752: /* original f862, guest PC 0x0c068752 */
if(!s->budget--) { s->failed_pc=0x0c068752u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c068754;
P_0c068754: /* original f853, guest PC 0x0c068754 */
if(!s->budget--) { s->failed_pc=0x0c068754u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'/');
goto P_0c068756;
P_0c068756: /* original f870, guest PC 0x0c068756 */
if(!s->budget--) { s->failed_pc=0x0c068756u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'+');
goto P_0c068758;
P_0c068758: /* original f746, guest PC 0x0c068758 */
if(!s->budget--) { s->failed_pc=0x0c068758u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c06875a;
P_0c06875a: /* original e008, guest PC 0x0c06875a */
if(!s->budget--) { s->failed_pc=0x0c06875au; return 0; }
r[0]=0x00000008u;
goto P_0c06875c;
P_0c06875c: /* original f971, guest PC 0x0c06875c */
if(!s->budget--) { s->failed_pc=0x0c06875cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'-');
goto P_0c06875e;
P_0c06875e: /* original f37c, guest PC 0x0c06875e */
if(!s->budget--) { s->failed_pc=0x0c06875eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068760;
P_0c068760: /* original fad6, guest PC 0x0c068760 */
if(!s->budget--) { s->failed_pc=0x0c068760u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068762;
P_0c068762: /* original f962, guest PC 0x0c068762 */
if(!s->budget--) { s->failed_pc=0x0c068762u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'*');
goto P_0c068764;
P_0c068764: /* original f953, guest PC 0x0c068764 */
if(!s->budget--) { s->failed_pc=0x0c068764u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'/');
goto P_0c068766;
P_0c068766: /* original f79c, guest PC 0x0c068766 */
if(!s->budget--) { s->failed_pc=0x0c068766u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c068768;
P_0c068768: /* original f730, guest PC 0x0c068768 */
if(!s->budget--) { s->failed_pc=0x0c068768u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c06876a;
P_0c06876a: /* original f946, guest PC 0x0c06876a */
if(!s->budget--) { s->failed_pc=0x0c06876au; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c06876c;
P_0c06876c: /* original e00c, guest PC 0x0c06876c */
if(!s->budget--) { s->failed_pc=0x0c06876cu; return 0; }
r[0]=0x0000000cu;
goto P_0c06876e;
P_0c06876e: /* original fbd6, guest PC 0x0c06876e */
if(!s->budget--) { s->failed_pc=0x0c06876eu; return 0; }
vf3_matrix_load(s,ram,11,r[13]+r[0]);
goto P_0c068770;
P_0c068770: /* original fa91, guest PC 0x0c068770 */
if(!s->budget--) { s->failed_pc=0x0c068770u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c068772;
P_0c068772: /* original f39c, guest PC 0x0c068772 */
if(!s->budget--) { s->failed_pc=0x0c068772u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068774;
P_0c068774: /* original fa62, guest PC 0x0c068774 */
if(!s->budget--) { s->failed_pc=0x0c068774u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[6],r[18],'*');
goto P_0c068776;
P_0c068776: /* original fa53, guest PC 0x0c068776 */
if(!s->budget--) { s->failed_pc=0x0c068776u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[5],r[18],'/');
goto P_0c068778;
P_0c068778: /* original f9ac, guest PC 0x0c068778 */
if(!s->budget--) { s->failed_pc=0x0c068778u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c06877a;
P_0c06877a: /* original f930, guest PC 0x0c06877a */
if(!s->budget--) { s->failed_pc=0x0c06877au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'+');
goto P_0c06877c;
P_0c06877c: /* original fa46, guest PC 0x0c06877c */
if(!s->budget--) { s->failed_pc=0x0c06877cu; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c06877e;
P_0c06877e: /* original fba1, guest PC 0x0c06877e */
if(!s->budget--) { s->failed_pc=0x0c06877eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'-');
goto P_0c068780;
P_0c068780: /* original fb62, guest PC 0x0c068780 */
if(!s->budget--) { s->failed_pc=0x0c068780u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[6],r[18],'*');
goto P_0c068782;
P_0c068782: /* original e010, guest PC 0x0c068782 */
if(!s->budget--) { s->failed_pc=0x0c068782u; return 0; }
r[0]=0x00000010u;
goto P_0c068784;
P_0c068784: /* original f3d6, guest PC 0x0c068784 */
if(!s->budget--) { s->failed_pc=0x0c068784u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c068786;
P_0c068786: /* original 2558, guest PC 0x0c068786 */
if(!s->budget--) { s->failed_pc=0x0c068786u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068788;
P_0c068788: /* original fb53, guest PC 0x0c068788 */
if(!s->budget--) { s->failed_pc=0x0c068788u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'/');
goto P_0c06878a;
P_0c06878a: /* original fba0, guest PC 0x0c06878a */
if(!s->budget--) { s->failed_pc=0x0c06878au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'+');
goto P_0c06878c;
P_0c06878c: /* original fa46, guest PC 0x0c06878c */
if(!s->budget--) { s->failed_pc=0x0c06878cu; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c06878e;
P_0c06878e: /* original e010, guest PC 0x0c06878e */
if(!s->budget--) { s->failed_pc=0x0c06878eu; return 0; }
r[0]=0x00000010u;
goto P_0c068790;
P_0c068790: /* original ff37, guest PC 0x0c068790 */
if(!s->budget--) { s->failed_pc=0x0c068790u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068792;
P_0c068792: /* original f3a1, guest PC 0x0c068792 */
if(!s->budget--) { s->failed_pc=0x0c068792u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c068794;
P_0c068794: /* original e008, guest PC 0x0c068794 */
if(!s->budget--) { s->failed_pc=0x0c068794u; return 0; }
r[0]=0x00000008u;
goto P_0c068796;
P_0c068796: /* original ff37, guest PC 0x0c068796 */
if(!s->budget--) { s->failed_pc=0x0c068796u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068798;
P_0c068798: /* original e034, guest PC 0x0c068798 */
if(!s->budget--) { s->failed_pc=0x0c068798u; return 0; }
r[0]=0x00000034u;
goto P_0c06879a;
P_0c06879a: /* original ff3c, guest PC 0x0c06879a */
if(!s->budget--) { s->failed_pc=0x0c06879au; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c06879c;
P_0c06879c: /* original ff62, guest PC 0x0c06879c */
if(!s->budget--) { s->failed_pc=0x0c06879cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'*');
goto P_0c06879e;
P_0c06879e: /* original ff53, guest PC 0x0c06879e */
if(!s->budget--) { s->failed_pc=0x0c06879eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'/');
goto P_0c0687a0;
P_0c0687a0: /* original ffa0, guest PC 0x0c0687a0 */
if(!s->budget--) { s->failed_pc=0x0c0687a0u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[10],r[18],'+');
goto P_0c0687a2;
P_0c0687a2: /* original fff7, guest PC 0x0c0687a2 */
if(!s->budget--) { s->failed_pc=0x0c0687a2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0687a4;
P_0c0687a4: /* original e014, guest PC 0x0c0687a4 */
if(!s->budget--) { s->failed_pc=0x0c0687a4u; return 0; }
r[0]=0x00000014u;
goto P_0c0687a6;
P_0c0687a6: /* original f3d6, guest PC 0x0c0687a6 */
if(!s->budget--) { s->failed_pc=0x0c0687a6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0687a8;
P_0c0687a8: /* original fa46, guest PC 0x0c0687a8 */
if(!s->budget--) { s->failed_pc=0x0c0687a8u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c0687aa;
P_0c0687aa: /* original e038, guest PC 0x0c0687aa */
if(!s->budget--) { s->failed_pc=0x0c0687aau; return 0; }
r[0]=0x00000038u;
goto P_0c0687ac;
P_0c0687ac: /* original ff37, guest PC 0x0c0687ac */
if(!s->budget--) { s->failed_pc=0x0c0687acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0687ae;
P_0c0687ae: /* original e040, guest PC 0x0c0687ae */
if(!s->budget--) { s->failed_pc=0x0c0687aeu; return 0; }
r[0]=0x00000040u;
goto P_0c0687b0;
P_0c0687b0: /* original f3a1, guest PC 0x0c0687b0 */
if(!s->budget--) { s->failed_pc=0x0c0687b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c0687b2;
P_0c0687b2: /* original ff37, guest PC 0x0c0687b2 */
if(!s->budget--) { s->failed_pc=0x0c0687b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0687b4;
P_0c0687b4: /* original f26c, guest PC 0x0c0687b4 */
if(!s->budget--) { s->failed_pc=0x0c0687b4u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0687b6;
P_0c0687b6: /* original f63c, guest PC 0x0c0687b6 */
if(!s->budget--) { s->failed_pc=0x0c0687b6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0687b8;
P_0c0687b8: /* original f622, guest PC 0x0c0687b8 */
if(!s->budget--) { s->failed_pc=0x0c0687b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'*');
goto P_0c0687ba;
P_0c0687ba: /* original f653, guest PC 0x0c0687ba */
if(!s->budget--) { s->failed_pc=0x0c0687bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c0687bc;
P_0c0687bc: /* original f56c, guest PC 0x0c0687bc */
if(!s->budget--) { s->failed_pc=0x0c0687bcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0687be;
P_0c0687be: /* original 8d02, guest PC 0x0c0687be */
if(!s->budget--) { s->failed_pc=0x0c0687beu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'+');
if(cond) { goto P_0c0687c6; }
goto P_0c0687c2;
P_0c0687c0: /* original f5a0, guest PC 0x0c0687c0 */
if(!s->budget--) { s->failed_pc=0x0c0687c0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'+');
goto P_0c0687c2;
P_0c0687c2: /* original a1e9, guest PC 0x0c0687c2 */
if(!s->budget--) { s->failed_pc=0x0c0687c2u; return 0; }
goto P_0c068b98;
P_0c0687c4: /* original 0009, guest PC 0x0c0687c4 */
if(!s->budget--) { s->failed_pc=0x0c0687c4u; return 0; }
goto P_0c0687c6;
P_0c0687c6: /* original e010, guest PC 0x0c0687c6 */
if(!s->budget--) { s->failed_pc=0x0c0687c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0687c8;
P_0c0687c8: /* original fe87, guest PC 0x0c0687c8 */
if(!s->budget--) { s->failed_pc=0x0c0687c8u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0687ca;
P_0c0687ca: /* original e014, guest PC 0x0c0687ca */
if(!s->budget--) { s->failed_pc=0x0c0687cau; return 0; }
r[0]=0x00000014u;
goto P_0c0687cc;
P_0c0687cc: /* original fe77, guest PC 0x0c0687cc */
if(!s->budget--) { s->failed_pc=0x0c0687ccu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0687ce;
P_0c0687ce: /* original e018, guest PC 0x0c0687ce */
if(!s->budget--) { s->failed_pc=0x0c0687ceu; return 0; }
r[0]=0x00000018u;
goto P_0c0687d0;
P_0c0687d0: /* original fe97, guest PC 0x0c0687d0 */
if(!s->budget--) { s->failed_pc=0x0c0687d0u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0687d2;
P_0c0687d2: /* original 9007, guest PC 0x0c0687d2 */
if(!s->budget--) { s->failed_pc=0x0c0687d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e4u,2);
goto P_0c0687d4;
P_0c0687d4: /* original feb7, guest PC 0x0c0687d4 */
if(!s->budget--) { s->failed_pc=0x0c0687d4u; return 0; }
vf3_matrix_store(s,ram,11,r[14]+r[0]);
goto P_0c0687d6;
P_0c0687d6: /* original e034, guest PC 0x0c0687d6 */
if(!s->budget--) { s->failed_pc=0x0c0687d6u; return 0; }
r[0]=0x00000034u;
goto P_0c0687d8;
P_0c0687d8: /* original f3f6, guest PC 0x0c0687d8 */
if(!s->budget--) { s->failed_pc=0x0c0687d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0687da;
P_0c0687da: /* original 9005, guest PC 0x0c0687da */
if(!s->budget--) { s->failed_pc=0x0c0687dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0687e8u,2);
goto P_0c0687dc;
P_0c0687dc: /* original fe37, guest PC 0x0c0687dc */
if(!s->budget--) { s->failed_pc=0x0c0687dcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0687de;
P_0c0687de: /* original 7004, guest PC 0x0c0687de */
if(!s->budget--) { s->failed_pc=0x0c0687deu; return 0; }
r[0]+=0x00000004u;
goto P_0c0687e0;
P_0c0687e0: /* original a1da, guest PC 0x0c0687e0 */
if(!s->budget--) { s->failed_pc=0x0c0687e0u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068b98;
P_0c0687e2: /* original fe57, guest PC 0x0c0687e2 */
if(!s->budget--) { s->failed_pc=0x0c0687e2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
if(!vf3_matrix_family(0x0c0687e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0687e4u; return 0; } return 1;
P_0c0687ea: /* original e034, guest PC 0x0c0687ea */
if(!s->budget--) { s->failed_pc=0x0c0687eau; return 0; }
r[0]=0x00000034u;
goto P_0c0687ec;
P_0c0687ec: /* original 024d, guest PC 0x0c0687ec */
if(!s->budget--) { s->failed_pc=0x0c0687ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0687ee;
P_0c0687ee: /* original 854c, guest PC 0x0c0687ee */
if(!s->budget--) { s->failed_pc=0x0c0687eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c0687f0;
P_0c0687f0: /* original 622d, guest PC 0x0c0687f0 */
if(!s->budget--) { s->failed_pc=0x0c0687f0u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0687f2;
P_0c0687f2: /* original 600d, guest PC 0x0c0687f2 */
if(!s->budget--) { s->failed_pc=0x0c0687f2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0687f4;
P_0c0687f4: /* original 3208, guest PC 0x0c0687f4 */
if(!s->budget--) { s->failed_pc=0x0c0687f4u; return 0; }
r[2]-=r[0];
goto P_0c0687f6;
P_0c0687f6: /* original 90b6, guest PC 0x0c0687f6 */
if(!s->budget--) { s->failed_pc=0x0c0687f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068966u,2);
goto P_0c0687f8;
P_0c0687f8: /* original 425a, guest PC 0x0c0687f8 */
if(!s->budget--) { s->failed_pc=0x0c0687f8u; return 0; }
r[53]=r[2];
goto P_0c0687fa;
P_0c0687fa: /* original f32d, guest PC 0x0c0687fa */
if(!s->budget--) { s->failed_pc=0x0c0687fau; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0687fc;
P_0c0687fc: /* original fe37, guest PC 0x0c0687fc */
if(!s->budget--) { s->failed_pc=0x0c0687fcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0687fe;
P_0c0687fe: /* original 70e4, guest PC 0x0c0687fe */
if(!s->budget--) { s->failed_pc=0x0c0687feu; return 0; }
r[0]+=0xffffffe4u;
goto P_0c068800;
P_0c068800: /* original f45c, guest PC 0x0c068800 */
if(!s->budget--) { s->failed_pc=0x0c068800u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c068802;
P_0c068802: /* original fe47, guest PC 0x0c068802 */
if(!s->budget--) { s->failed_pc=0x0c068802u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c068804;
P_0c068804: /* original 7020, guest PC 0x0c068804 */
if(!s->budget--) { s->failed_pc=0x0c068804u; return 0; }
r[0]+=0x00000020u;
goto P_0c068806;
P_0c068806: /* original 06ec, guest PC 0x0c068806 */
if(!s->budget--) { s->failed_pc=0x0c068806u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c068808;
P_0c068808: /* original c759, guest PC 0x0c068808 */
if(!s->budget--) { s->failed_pc=0x0c068808u; return 0; }
r[0]=code_base|0x00068970u;
goto P_0c06880a;
P_0c06880a: /* original 2668, guest PC 0x0c06880a */
if(!s->budget--) { s->failed_pc=0x0c06880au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06880c;
P_0c06880c: /* original 8d51, guest PC 0x0c06880c */
if(!s->budget--) { s->failed_pc=0x0c06880cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(cond) { goto P_0c0688b2; }
goto P_0c068810;
P_0c06880e: /* original f608, guest PC 0x0c06880e */
if(!s->budget--) { s->failed_pc=0x0c06880eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c068810;
P_0c068810: /* original 6d43, guest PC 0x0c068810 */
if(!s->budget--) { s->failed_pc=0x0c068810u; return 0; }
r[13]=r[4];
goto P_0c068812;
P_0c068812: /* original e01a, guest PC 0x0c068812 */
if(!s->budget--) { s->failed_pc=0x0c068812u; return 0; }
r[0]=0x0000001au;
goto P_0c068814;
P_0c068814: /* original 7de4, guest PC 0x0c068814 */
if(!s->budget--) { s->failed_pc=0x0c068814u; return 0; }
r[13]+=0xffffffe4u;
goto P_0c068816;
P_0c068816: /* original 06dc, guest PC 0x0c068816 */
if(!s->budget--) { s->failed_pc=0x0c068816u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c068818;
P_0c068818: /* original 666c, guest PC 0x0c068818 */
if(!s->budget--) { s->failed_pc=0x0c068818u; return 0; }
r[6]=r[6]&255u;
goto P_0c06881a;
P_0c06881a: /* original 2668, guest PC 0x0c06881a */
if(!s->budget--) { s->failed_pc=0x0c06881au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06881c;
P_0c06881c: /* original 8949, guest PC 0x0c06881c */
if(!s->budget--) { s->failed_pc=0x0c06881cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0688b2; }
goto P_0c06881e;
P_0c06881e: /* original 6643, guest PC 0x0c06881e */
if(!s->budget--) { s->failed_pc=0x0c06881eu; return 0; }
r[6]=r[4];
goto P_0c068820;
P_0c068820: /* original 761c, guest PC 0x0c068820 */
if(!s->budget--) { s->failed_pc=0x0c068820u; return 0; }
r[6]+=0x0000001cu;
goto P_0c068822;
P_0c068822: /* original 856c, guest PC 0x0c068822 */
if(!s->budget--) { s->failed_pc=0x0c068822u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c068824;
P_0c068824: /* original f46c, guest PC 0x0c068824 */
if(!s->budget--) { s->failed_pc=0x0c068824u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c068826;
P_0c068826: /* original 630d, guest PC 0x0c068826 */
if(!s->budget--) { s->failed_pc=0x0c068826u; return 0; }
r[3]=r[0]&65535u;
goto P_0c068828;
P_0c068828: /* original 854c, guest PC 0x0c068828 */
if(!s->budget--) { s->failed_pc=0x0c068828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+24,2);
goto P_0c06882a;
P_0c06882a: /* original f848, guest PC 0x0c06882a */
if(!s->budget--) { s->failed_pc=0x0c06882au; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c06882c;
P_0c06882c: /* original 600d, guest PC 0x0c06882c */
if(!s->budget--) { s->failed_pc=0x0c06882cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c06882e;
P_0c06882e: /* original fb68, guest PC 0x0c06882e */
if(!s->budget--) { s->failed_pc=0x0c06882eu; return 0; }
vf3_matrix_load(s,ram,11,r[6]);
goto P_0c068830;
P_0c068830: /* original 3308, guest PC 0x0c068830 */
if(!s->budget--) { s->failed_pc=0x0c068830u; return 0; }
r[3]-=r[0];
goto P_0c068832;
P_0c068832: /* original 435a, guest PC 0x0c068832 */
if(!s->budget--) { s->failed_pc=0x0c068832u; return 0; }
r[53]=r[3];
goto P_0c068834;
P_0c068834: /* original e004, guest PC 0x0c068834 */
if(!s->budget--) { s->failed_pc=0x0c068834u; return 0; }
r[0]=0x00000004u;
goto P_0c068836;
P_0c068836: /* original f946, guest PC 0x0c068836 */
if(!s->budget--) { s->failed_pc=0x0c068836u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c068838;
P_0c068838: /* original e008, guest PC 0x0c068838 */
if(!s->budget--) { s->failed_pc=0x0c068838u; return 0; }
r[0]=0x00000008u;
goto P_0c06883a;
P_0c06883a: /* original f746, guest PC 0x0c06883a */
if(!s->budget--) { s->failed_pc=0x0c06883au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c06883c;
P_0c06883c: /* original e004, guest PC 0x0c06883c */
if(!s->budget--) { s->failed_pc=0x0c06883cu; return 0; }
r[0]=0x00000004u;
goto P_0c06883e;
P_0c06883e: /* original f32d, guest PC 0x0c06883e */
if(!s->budget--) { s->failed_pc=0x0c06883eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068840;
P_0c068840: /* original fa66, guest PC 0x0c068840 */
if(!s->budget--) { s->failed_pc=0x0c068840u; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c068842;
P_0c068842: /* original e008, guest PC 0x0c068842 */
if(!s->budget--) { s->failed_pc=0x0c068842u; return 0; }
r[0]=0x00000008u;
goto P_0c068844;
P_0c068844: /* original f432, guest PC 0x0c068844 */
if(!s->budget--) { s->failed_pc=0x0c068844u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c068846;
P_0c068846: /* original f366, guest PC 0x0c068846 */
if(!s->budget--) { s->failed_pc=0x0c068846u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c068848;
P_0c068848: /* original e020, guest PC 0x0c068848 */
if(!s->budget--) { s->failed_pc=0x0c068848u; return 0; }
r[0]=0x00000020u;
goto P_0c06884a;
P_0c06884a: /* original ff37, guest PC 0x0c06884a */
if(!s->budget--) { s->failed_pc=0x0c06884au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06884c;
P_0c06884c: /* original e020, guest PC 0x0c06884c */
if(!s->budget--) { s->failed_pc=0x0c06884cu; return 0; }
r[0]=0x00000020u;
goto P_0c06884e;
P_0c06884e: /* original f38c, guest PC 0x0c06884e */
if(!s->budget--) { s->failed_pc=0x0c06884eu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c068850;
P_0c068850: /* original f8bc, guest PC 0x0c068850 */
if(!s->budget--) { s->failed_pc=0x0c068850u; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c068852;
P_0c068852: /* original f831, guest PC 0x0c068852 */
if(!s->budget--) { s->failed_pc=0x0c068852u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c068854;
P_0c068854: /* original f39c, guest PC 0x0c068854 */
if(!s->budget--) { s->failed_pc=0x0c068854u; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068856;
P_0c068856: /* original f9ac, guest PC 0x0c068856 */
if(!s->budget--) { s->failed_pc=0x0c068856u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c068858;
P_0c068858: /* original f931, guest PC 0x0c068858 */
if(!s->budget--) { s->failed_pc=0x0c068858u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c06885a;
P_0c06885a: /* original f37c, guest PC 0x0c06885a */
if(!s->budget--) { s->failed_pc=0x0c06885au; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06885c;
P_0c06885c: /* original f7f6, guest PC 0x0c06885c */
if(!s->budget--) { s->failed_pc=0x0c06885cu; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c06885e;
P_0c06885e: /* original f843, guest PC 0x0c06885e */
if(!s->budget--) { s->failed_pc=0x0c06885eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c068860;
P_0c068860: /* original 9082, guest PC 0x0c068860 */
if(!s->budget--) { s->failed_pc=0x0c068860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068968u,2);
goto P_0c068862;
P_0c068862: /* original f731, guest PC 0x0c068862 */
if(!s->budget--) { s->failed_pc=0x0c068862u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068864;
P_0c068864: /* original f943, guest PC 0x0c068864 */
if(!s->budget--) { s->failed_pc=0x0c068864u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'/');
goto P_0c068866;
P_0c068866: /* original f743, guest PC 0x0c068866 */
if(!s->budget--) { s->failed_pc=0x0c068866u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c068868;
P_0c068868: /* original fe87, guest PC 0x0c068868 */
if(!s->budget--) { s->failed_pc=0x0c068868u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c06886a;
P_0c06886a: /* original 7004, guest PC 0x0c06886a */
if(!s->budget--) { s->failed_pc=0x0c06886au; return 0; }
r[0]+=0x00000004u;
goto P_0c06886c;
P_0c06886c: /* original fe97, guest PC 0x0c06886c */
if(!s->budget--) { s->failed_pc=0x0c06886cu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c06886e;
P_0c06886e: /* original 7004, guest PC 0x0c06886e */
if(!s->budget--) { s->failed_pc=0x0c06886eu; return 0; }
r[0]+=0x00000004u;
goto P_0c068870;
P_0c068870: /* original fe77, guest PC 0x0c068870 */
if(!s->budget--) { s->failed_pc=0x0c068870u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c068872;
P_0c068872: /* original e00c, guest PC 0x0c068872 */
if(!s->budget--) { s->failed_pc=0x0c068872u; return 0; }
r[0]=0x0000000cu;
goto P_0c068874;
P_0c068874: /* original f7d6, guest PC 0x0c068874 */
if(!s->budget--) { s->failed_pc=0x0c068874u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c068876;
P_0c068876: /* original e010, guest PC 0x0c068876 */
if(!s->budget--) { s->failed_pc=0x0c068876u; return 0; }
r[0]=0x00000010u;
goto P_0c068878;
P_0c068878: /* original f8d6, guest PC 0x0c068878 */
if(!s->budget--) { s->failed_pc=0x0c068878u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c06887a;
P_0c06887a: /* original e014, guest PC 0x0c06887a */
if(!s->budget--) { s->failed_pc=0x0c06887au; return 0; }
r[0]=0x00000014u;
goto P_0c06887c;
P_0c06887c: /* original f9d6, guest PC 0x0c06887c */
if(!s->budget--) { s->failed_pc=0x0c06887cu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c06887e;
P_0c06887e: /* original e00c, guest PC 0x0c06887e */
if(!s->budget--) { s->failed_pc=0x0c06887eu; return 0; }
r[0]=0x0000000cu;
goto P_0c068880;
P_0c068880: /* original fb66, guest PC 0x0c068880 */
if(!s->budget--) { s->failed_pc=0x0c068880u; return 0; }
vf3_matrix_load(s,ram,11,r[6]+r[0]);
goto P_0c068882;
P_0c068882: /* original e010, guest PC 0x0c068882 */
if(!s->budget--) { s->failed_pc=0x0c068882u; return 0; }
r[0]=0x00000010u;
goto P_0c068884;
P_0c068884: /* original fa66, guest PC 0x0c068884 */
if(!s->budget--) { s->failed_pc=0x0c068884u; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c068886;
P_0c068886: /* original e014, guest PC 0x0c068886 */
if(!s->budget--) { s->failed_pc=0x0c068886u; return 0; }
r[0]=0x00000014u;
goto P_0c068888;
P_0c068888: /* original f366, guest PC 0x0c068888 */
if(!s->budget--) { s->failed_pc=0x0c068888u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c06888a;
P_0c06888a: /* original e00c, guest PC 0x0c06888a */
if(!s->budget--) { s->failed_pc=0x0c06888au; return 0; }
r[0]=0x0000000cu;
goto P_0c06888c;
P_0c06888c: /* original ff37, guest PC 0x0c06888c */
if(!s->budget--) { s->failed_pc=0x0c06888cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06888e;
P_0c06888e: /* original e00c, guest PC 0x0c06888e */
if(!s->budget--) { s->failed_pc=0x0c06888eu; return 0; }
r[0]=0x0000000cu;
goto P_0c068890;
P_0c068890: /* original f37c, guest PC 0x0c068890 */
if(!s->budget--) { s->failed_pc=0x0c068890u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068892;
P_0c068892: /* original f7bc, guest PC 0x0c068892 */
if(!s->budget--) { s->failed_pc=0x0c068892u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c068894;
P_0c068894: /* original f731, guest PC 0x0c068894 */
if(!s->budget--) { s->failed_pc=0x0c068894u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068896;
P_0c068896: /* original f38c, guest PC 0x0c068896 */
if(!s->budget--) { s->failed_pc=0x0c068896u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c068898;
P_0c068898: /* original f8ac, guest PC 0x0c068898 */
if(!s->budget--) { s->failed_pc=0x0c068898u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c06889a;
P_0c06889a: /* original f831, guest PC 0x0c06889a */
if(!s->budget--) { s->failed_pc=0x0c06889au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c06889c;
P_0c06889c: /* original f39c, guest PC 0x0c06889c */
if(!s->budget--) { s->failed_pc=0x0c06889cu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c06889e;
P_0c06889e: /* original f9f6, guest PC 0x0c06889e */
if(!s->budget--) { s->failed_pc=0x0c06889eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0688a0;
P_0c0688a0: /* original f843, guest PC 0x0c0688a0 */
if(!s->budget--) { s->failed_pc=0x0c0688a0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'/');
goto P_0c0688a2;
P_0c0688a2: /* original f743, guest PC 0x0c0688a2 */
if(!s->budget--) { s->failed_pc=0x0c0688a2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0688a4;
P_0c0688a4: /* original 9061, guest PC 0x0c0688a4 */
if(!s->budget--) { s->failed_pc=0x0c0688a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896au,2);
goto P_0c0688a6;
P_0c0688a6: /* original f931, guest PC 0x0c0688a6 */
if(!s->budget--) { s->failed_pc=0x0c0688a6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c0688a8;
P_0c0688a8: /* original f943, guest PC 0x0c0688a8 */
if(!s->budget--) { s->failed_pc=0x0c0688a8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'/');
goto P_0c0688aa;
P_0c0688aa: /* original fe77, guest PC 0x0c0688aa */
if(!s->budget--) { s->failed_pc=0x0c0688aau; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c0688ac;
P_0c0688ac: /* original fe87, guest PC 0x0c0688ac */
if(!s->budget--) { s->failed_pc=0x0c0688acu; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c0688ae;
P_0c0688ae: /* original a00d, guest PC 0x0c0688ae */
if(!s->budget--) { s->failed_pc=0x0c0688aeu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0688cc;
P_0c0688b0: /* original fe97, guest PC 0x0c0688b0 */
if(!s->budget--) { s->failed_pc=0x0c0688b0u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c0688b2;
P_0c0688b2: /* original 9059, guest PC 0x0c0688b2 */
if(!s->budget--) { s->failed_pc=0x0c0688b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068968u,2);
goto P_0c0688b4;
P_0c0688b4: /* original ff5c, guest PC 0x0c0688b4 */
if(!s->budget--) { s->failed_pc=0x0c0688b4u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0688b6;
P_0c0688b6: /* original fef7, guest PC 0x0c0688b6 */
if(!s->budget--) { s->failed_pc=0x0c0688b6u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688b8;
P_0c0688b8: /* original 7004, guest PC 0x0c0688b8 */
if(!s->budget--) { s->failed_pc=0x0c0688b8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688ba;
P_0c0688ba: /* original fef7, guest PC 0x0c0688ba */
if(!s->budget--) { s->failed_pc=0x0c0688bau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688bc;
P_0c0688bc: /* original 7004, guest PC 0x0c0688bc */
if(!s->budget--) { s->failed_pc=0x0c0688bcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0688be;
P_0c0688be: /* original fef7, guest PC 0x0c0688be */
if(!s->budget--) { s->failed_pc=0x0c0688beu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c0;
P_0c0688c0: /* original 7018, guest PC 0x0c0688c0 */
if(!s->budget--) { s->failed_pc=0x0c0688c0u; return 0; }
r[0]+=0x00000018u;
goto P_0c0688c2;
P_0c0688c2: /* original fef7, guest PC 0x0c0688c2 */
if(!s->budget--) { s->failed_pc=0x0c0688c2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c4;
P_0c0688c4: /* original 7004, guest PC 0x0c0688c4 */
if(!s->budget--) { s->failed_pc=0x0c0688c4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688c6;
P_0c0688c6: /* original fef7, guest PC 0x0c0688c6 */
if(!s->budget--) { s->failed_pc=0x0c0688c6u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688c8;
P_0c0688c8: /* original 7004, guest PC 0x0c0688c8 */
if(!s->budget--) { s->failed_pc=0x0c0688c8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0688ca;
P_0c0688ca: /* original fef7, guest PC 0x0c0688ca */
if(!s->budget--) { s->failed_pc=0x0c0688cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0688cc;
P_0c0688cc: /* original e036, guest PC 0x0c0688cc */
if(!s->budget--) { s->failed_pc=0x0c0688ccu; return 0; }
r[0]=0x00000036u;
goto P_0c0688ce;
P_0c0688ce: /* original 064c, guest PC 0x0c0688ce */
if(!s->budget--) { s->failed_pc=0x0c0688ceu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0688d0;
P_0c0688d0: /* original 666c, guest PC 0x0c0688d0 */
if(!s->budget--) { s->failed_pc=0x0c0688d0u; return 0; }
r[6]=r[6]&255u;
goto P_0c0688d2;
P_0c0688d2: /* original 2668, guest PC 0x0c0688d2 */
if(!s->budget--) { s->failed_pc=0x0c0688d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0688d4;
P_0c0688d4: /* original 894e, guest PC 0x0c0688d4 */
if(!s->budget--) { s->failed_pc=0x0c0688d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068974; }
goto P_0c0688d6;
P_0c0688d6: /* original 6743, guest PC 0x0c0688d6 */
if(!s->budget--) { s->failed_pc=0x0c0688d6u; return 0; }
r[7]=r[4];
goto P_0c0688d8;
P_0c0688d8: /* original 771c, guest PC 0x0c0688d8 */
if(!s->budget--) { s->failed_pc=0x0c0688d8u; return 0; }
r[7]+=0x0000001cu;
goto P_0c0688da;
P_0c0688da: /* original 857c, guest PC 0x0c0688da */
if(!s->budget--) { s->failed_pc=0x0c0688dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+24,2);
goto P_0c0688dc;
P_0c0688dc: /* original 6643, guest PC 0x0c0688dc */
if(!s->budget--) { s->failed_pc=0x0c0688dcu; return 0; }
r[6]=r[4];
goto P_0c0688de;
P_0c0688de: /* original 7638, guest PC 0x0c0688de */
if(!s->budget--) { s->failed_pc=0x0c0688deu; return 0; }
r[6]+=0x00000038u;
goto P_0c0688e0;
P_0c0688e0: /* original 6d0d, guest PC 0x0c0688e0 */
if(!s->budget--) { s->failed_pc=0x0c0688e0u; return 0; }
r[13]=r[0]&65535u;
goto P_0c0688e2;
P_0c0688e2: /* original 856c, guest PC 0x0c0688e2 */
if(!s->budget--) { s->failed_pc=0x0c0688e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+24,2);
goto P_0c0688e4;
P_0c0688e4: /* original 600d, guest PC 0x0c0688e4 */
if(!s->budget--) { s->failed_pc=0x0c0688e4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0688e6;
P_0c0688e6: /* original 6303, guest PC 0x0c0688e6 */
if(!s->budget--) { s->failed_pc=0x0c0688e6u; return 0; }
r[3]=r[0];
goto P_0c0688e8;
P_0c0688e8: /* original 33d8, guest PC 0x0c0688e8 */
if(!s->budget--) { s->failed_pc=0x0c0688e8u; return 0; }
r[3]-=r[13];
goto P_0c0688ea;
P_0c0688ea: /* original 6d33, guest PC 0x0c0688ea */
if(!s->budget--) { s->failed_pc=0x0c0688eau; return 0; }
r[13]=r[3];
goto P_0c0688ec;
P_0c0688ec: /* original 2f02, guest PC 0x0c0688ec */
if(!s->budget--) { s->failed_pc=0x0c0688ecu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0688ee;
P_0c0688ee: /* original 4d5a, guest PC 0x0c0688ee */
if(!s->budget--) { s->failed_pc=0x0c0688eeu; return 0; }
r[53]=r[13];
goto P_0c0688f0;
P_0c0688f0: /* original e004, guest PC 0x0c0688f0 */
if(!s->budget--) { s->failed_pc=0x0c0688f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0688f2;
P_0c0688f2: /* original f46c, guest PC 0x0c0688f2 */
if(!s->budget--) { s->failed_pc=0x0c0688f2u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0688f4;
P_0c0688f4: /* original f676, guest PC 0x0c0688f4 */
if(!s->budget--) { s->failed_pc=0x0c0688f4u; return 0; }
vf3_matrix_load(s,ram,6,r[7]+r[0]);
goto P_0c0688f6;
P_0c0688f6: /* original e008, guest PC 0x0c0688f6 */
if(!s->budget--) { s->failed_pc=0x0c0688f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0688f8;
P_0c0688f8: /* original f32d, guest PC 0x0c0688f8 */
if(!s->budget--) { s->failed_pc=0x0c0688f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0688fa;
P_0c0688fa: /* original f568, guest PC 0x0c0688fa */
if(!s->budget--) { s->failed_pc=0x0c0688fau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0688fc;
P_0c0688fc: /* original f776, guest PC 0x0c0688fc */
if(!s->budget--) { s->failed_pc=0x0c0688fcu; return 0; }
vf3_matrix_load(s,ram,7,r[7]+r[0]);
goto P_0c0688fe;
P_0c0688fe: /* original e004, guest PC 0x0c0688fe */
if(!s->budget--) { s->failed_pc=0x0c0688feu; return 0; }
r[0]=0x00000004u;
goto P_0c068900;
P_0c068900: /* original f966, guest PC 0x0c068900 */
if(!s->budget--) { s->failed_pc=0x0c068900u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c068902;
P_0c068902: /* original e008, guest PC 0x0c068902 */
if(!s->budget--) { s->failed_pc=0x0c068902u; return 0; }
r[0]=0x00000008u;
goto P_0c068904;
P_0c068904: /* original f866, guest PC 0x0c068904 */
if(!s->budget--) { s->failed_pc=0x0c068904u; return 0; }
vf3_matrix_load(s,ram,8,r[6]+r[0]);
goto P_0c068906;
P_0c068906: /* original f432, guest PC 0x0c068906 */
if(!s->budget--) { s->failed_pc=0x0c068906u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c068908;
P_0c068908: /* original f378, guest PC 0x0c068908 */
if(!s->budget--) { s->failed_pc=0x0c068908u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c06890a;
P_0c06890a: /* original f531, guest PC 0x0c06890a */
if(!s->budget--) { s->failed_pc=0x0c06890au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06890c;
P_0c06890c: /* original f36c, guest PC 0x0c06890c */
if(!s->budget--) { s->failed_pc=0x0c06890cu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c06890e;
P_0c06890e: /* original f69c, guest PC 0x0c06890e */
if(!s->budget--) { s->failed_pc=0x0c06890eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c068910;
P_0c068910: /* original f631, guest PC 0x0c068910 */
if(!s->budget--) { s->failed_pc=0x0c068910u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c068912;
P_0c068912: /* original f37c, guest PC 0x0c068912 */
if(!s->budget--) { s->failed_pc=0x0c068912u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068914;
P_0c068914: /* original f78c, guest PC 0x0c068914 */
if(!s->budget--) { s->failed_pc=0x0c068914u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c068916;
P_0c068916: /* original f543, guest PC 0x0c068916 */
if(!s->budget--) { s->failed_pc=0x0c068916u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c068918;
P_0c068918: /* original 9028, guest PC 0x0c068918 */
if(!s->budget--) { s->failed_pc=0x0c068918u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896cu,2);
goto P_0c06891a;
P_0c06891a: /* original f731, guest PC 0x0c06891a */
if(!s->budget--) { s->failed_pc=0x0c06891au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c06891c;
P_0c06891c: /* original f643, guest PC 0x0c06891c */
if(!s->budget--) { s->failed_pc=0x0c06891cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c06891e;
P_0c06891e: /* original f743, guest PC 0x0c06891e */
if(!s->budget--) { s->failed_pc=0x0c06891eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c068920;
P_0c068920: /* original fe57, guest PC 0x0c068920 */
if(!s->budget--) { s->failed_pc=0x0c068920u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068922;
P_0c068922: /* original 7004, guest PC 0x0c068922 */
if(!s->budget--) { s->failed_pc=0x0c068922u; return 0; }
r[0]+=0x00000004u;
goto P_0c068924;
P_0c068924: /* original fe67, guest PC 0x0c068924 */
if(!s->budget--) { s->failed_pc=0x0c068924u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068926;
P_0c068926: /* original 7004, guest PC 0x0c068926 */
if(!s->budget--) { s->failed_pc=0x0c068926u; return 0; }
r[0]+=0x00000004u;
goto P_0c068928;
P_0c068928: /* original fe77, guest PC 0x0c068928 */
if(!s->budget--) { s->failed_pc=0x0c068928u; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06892a;
P_0c06892a: /* original e00c, guest PC 0x0c06892a */
if(!s->budget--) { s->failed_pc=0x0c06892au; return 0; }
r[0]=0x0000000cu;
goto P_0c06892c;
P_0c06892c: /* original f346, guest PC 0x0c06892c */
if(!s->budget--) { s->failed_pc=0x0c06892cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06892e;
P_0c06892e: /* original e010, guest PC 0x0c06892e */
if(!s->budget--) { s->failed_pc=0x0c06892eu; return 0; }
r[0]=0x00000010u;
goto P_0c068930;
P_0c068930: /* original f546, guest PC 0x0c068930 */
if(!s->budget--) { s->failed_pc=0x0c068930u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c068932;
P_0c068932: /* original e014, guest PC 0x0c068932 */
if(!s->budget--) { s->failed_pc=0x0c068932u; return 0; }
r[0]=0x00000014u;
goto P_0c068934;
P_0c068934: /* original f646, guest PC 0x0c068934 */
if(!s->budget--) { s->failed_pc=0x0c068934u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c068936;
P_0c068936: /* original e00c, guest PC 0x0c068936 */
if(!s->budget--) { s->failed_pc=0x0c068936u; return 0; }
r[0]=0x0000000cu;
goto P_0c068938;
P_0c068938: /* original f866, guest PC 0x0c068938 */
if(!s->budget--) { s->failed_pc=0x0c068938u; return 0; }
vf3_matrix_load(s,ram,8,r[6]+r[0]);
goto P_0c06893a;
P_0c06893a: /* original e010, guest PC 0x0c06893a */
if(!s->budget--) { s->failed_pc=0x0c06893au; return 0; }
r[0]=0x00000010u;
goto P_0c06893c;
P_0c06893c: /* original f966, guest PC 0x0c06893c */
if(!s->budget--) { s->failed_pc=0x0c06893cu; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c06893e;
P_0c06893e: /* original e014, guest PC 0x0c06893e */
if(!s->budget--) { s->failed_pc=0x0c06893eu; return 0; }
r[0]=0x00000014u;
goto P_0c068940;
P_0c068940: /* original f78c, guest PC 0x0c068940 */
if(!s->budget--) { s->failed_pc=0x0c068940u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c068942;
P_0c068942: /* original f731, guest PC 0x0c068942 */
if(!s->budget--) { s->failed_pc=0x0c068942u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c068944;
P_0c068944: /* original f35c, guest PC 0x0c068944 */
if(!s->budget--) { s->failed_pc=0x0c068944u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068946;
P_0c068946: /* original f59c, guest PC 0x0c068946 */
if(!s->budget--) { s->failed_pc=0x0c068946u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c068948;
P_0c068948: /* original f531, guest PC 0x0c068948 */
if(!s->budget--) { s->failed_pc=0x0c068948u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06894a;
P_0c06894a: /* original fa66, guest PC 0x0c06894a */
if(!s->budget--) { s->failed_pc=0x0c06894au; return 0; }
vf3_matrix_load(s,ram,10,r[6]+r[0]);
goto P_0c06894c;
P_0c06894c: /* original f743, guest PC 0x0c06894c */
if(!s->budget--) { s->failed_pc=0x0c06894cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c06894e;
P_0c06894e: /* original f36c, guest PC 0x0c06894e */
if(!s->budget--) { s->failed_pc=0x0c06894eu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c068950;
P_0c068950: /* original f6ac, guest PC 0x0c068950 */
if(!s->budget--) { s->failed_pc=0x0c068950u; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c068952;
P_0c068952: /* original f631, guest PC 0x0c068952 */
if(!s->budget--) { s->failed_pc=0x0c068952u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c068954;
P_0c068954: /* original f543, guest PC 0x0c068954 */
if(!s->budget--) { s->failed_pc=0x0c068954u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c068956;
P_0c068956: /* original f643, guest PC 0x0c068956 */
if(!s->budget--) { s->failed_pc=0x0c068956u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'/');
goto P_0c068958;
P_0c068958: /* original 9009, guest PC 0x0c068958 */
if(!s->budget--) { s->failed_pc=0x0c068958u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06896eu,2);
goto P_0c06895a;
P_0c06895a: /* original fe77, guest PC 0x0c06895a */
if(!s->budget--) { s->failed_pc=0x0c06895au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c06895c;
P_0c06895c: /* original 7004, guest PC 0x0c06895c */
if(!s->budget--) { s->failed_pc=0x0c06895cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06895e;
P_0c06895e: /* original fe57, guest PC 0x0c06895e */
if(!s->budget--) { s->failed_pc=0x0c06895eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068960;
P_0c068960: /* original 7004, guest PC 0x0c068960 */
if(!s->budget--) { s->failed_pc=0x0c068960u; return 0; }
r[0]+=0x00000004u;
goto P_0c068962;
P_0c068962: /* original ae98, guest PC 0x0c068962 */
if(!s->budget--) { s->failed_pc=0x0c068962u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c068696;
P_0c068964: /* original fe67, guest PC 0x0c068964 */
if(!s->budget--) { s->failed_pc=0x0c068964u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
if(!vf3_matrix_family(0x0c068966u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068966u; return 0; } return 1;
P_0c068974: /* original 900c, guest PC 0x0c068974 */
if(!s->budget--) { s->failed_pc=0x0c068974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068990u,2);
goto P_0c068976;
P_0c068976: /* original ff5c, guest PC 0x0c068976 */
if(!s->budget--) { s->failed_pc=0x0c068976u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c068978;
P_0c068978: /* original fef7, guest PC 0x0c068978 */
if(!s->budget--) { s->failed_pc=0x0c068978u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06897a;
P_0c06897a: /* original 7004, guest PC 0x0c06897a */
if(!s->budget--) { s->failed_pc=0x0c06897au; return 0; }
r[0]+=0x00000004u;
goto P_0c06897c;
P_0c06897c: /* original fef7, guest PC 0x0c06897c */
if(!s->budget--) { s->failed_pc=0x0c06897cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06897e;
P_0c06897e: /* original 7004, guest PC 0x0c06897e */
if(!s->budget--) { s->failed_pc=0x0c06897eu; return 0; }
r[0]+=0x00000004u;
goto P_0c068980;
P_0c068980: /* original fef7, guest PC 0x0c068980 */
if(!s->budget--) { s->failed_pc=0x0c068980u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068982;
P_0c068982: /* original 7018, guest PC 0x0c068982 */
if(!s->budget--) { s->failed_pc=0x0c068982u; return 0; }
r[0]+=0x00000018u;
goto P_0c068984;
P_0c068984: /* original fef7, guest PC 0x0c068984 */
if(!s->budget--) { s->failed_pc=0x0c068984u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068986;
P_0c068986: /* original 7004, guest PC 0x0c068986 */
if(!s->budget--) { s->failed_pc=0x0c068986u; return 0; }
r[0]+=0x00000004u;
goto P_0c068988;
P_0c068988: /* original fef7, guest PC 0x0c068988 */
if(!s->budget--) { s->failed_pc=0x0c068988u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c06898a;
P_0c06898a: /* original 7004, guest PC 0x0c06898a */
if(!s->budget--) { s->failed_pc=0x0c06898au; return 0; }
r[0]+=0x00000004u;
goto P_0c06898c;
P_0c06898c: /* original ae83, guest PC 0x0c06898c */
if(!s->budget--) { s->failed_pc=0x0c06898cu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c068696;
P_0c06898e: /* original fef7, guest PC 0x0c06898e */
if(!s->budget--) { s->failed_pc=0x0c06898eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
if(!vf3_matrix_family(0x0c068990u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068990u; return 0; } return 1;
P_0c068992: /* original 90dc, guest PC 0x0c068992 */
if(!s->budget--) { s->failed_pc=0x0c068992u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b4eu,2);
goto P_0c068994;
P_0c068994: /* original fa4c, guest PC 0x0c068994 */
if(!s->budget--) { s->failed_pc=0x0c068994u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c068996;
P_0c068996: /* original f7e6, guest PC 0x0c068996 */
if(!s->budget--) { s->failed_pc=0x0c068996u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c068998;
P_0c068998: /* original 70e4, guest PC 0x0c068998 */
if(!s->budget--) { s->failed_pc=0x0c068998u; return 0; }
r[0]+=0xffffffe4u;
goto P_0c06899a;
P_0c06899a: /* original f5e6, guest PC 0x0c06899a */
if(!s->budget--) { s->failed_pc=0x0c06899au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c06899c;
P_0c06899c: /* original 7004, guest PC 0x0c06899c */
if(!s->budget--) { s->failed_pc=0x0c06899cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06899e;
P_0c06899e: /* original fbe6, guest PC 0x0c06899e */
if(!s->budget--) { s->failed_pc=0x0c06899eu; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c0689a0;
P_0c0689a0: /* original 700c, guest PC 0x0c0689a0 */
if(!s->budget--) { s->failed_pc=0x0c0689a0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0689a2;
P_0c0689a2: /* original ff5c, guest PC 0x0c0689a2 */
if(!s->budget--) { s->failed_pc=0x0c0689a2u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0689a4;
P_0c0689a4: /* original ff73, guest PC 0x0c0689a4 */
if(!s->budget--) { s->failed_pc=0x0c0689a4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[7],r[18],'/');
goto P_0c0689a6;
P_0c0689a6: /* original f3e6, guest PC 0x0c0689a6 */
if(!s->budget--) { s->failed_pc=0x0c0689a6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689a8;
P_0c0689a8: /* original f8d8, guest PC 0x0c0689a8 */
if(!s->budget--) { s->failed_pc=0x0c0689a8u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c0689aa;
P_0c0689aa: /* original f948, guest PC 0x0c0689aa */
if(!s->budget--) { s->failed_pc=0x0c0689aau; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
goto P_0c0689ac;
P_0c0689ac: /* original f7fc, guest PC 0x0c0689ac */
if(!s->budget--) { s->failed_pc=0x0c0689acu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689ae;
P_0c0689ae: /* original f7a1, guest PC 0x0c0689ae */
if(!s->budget--) { s->failed_pc=0x0c0689aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c0689b0;
P_0c0689b0: /* original f6fc, guest PC 0x0c0689b0 */
if(!s->budget--) { s->failed_pc=0x0c0689b0u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0689b2;
P_0c0689b2: /* original f632, guest PC 0x0c0689b2 */
if(!s->budget--) { s->failed_pc=0x0c0689b2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0689b4;
P_0c0689b4: /* original fb72, guest PC 0x0c0689b4 */
if(!s->budget--) { s->failed_pc=0x0c0689b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c0689b6;
P_0c0689b6: /* original f37c, guest PC 0x0c0689b6 */
if(!s->budget--) { s->failed_pc=0x0c0689b6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689b8;
P_0c0689b8: /* original f6b0, guest PC 0x0c0689b8 */
if(!s->budget--) { s->failed_pc=0x0c0689b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'+');
goto P_0c0689ba;
P_0c0689ba: /* original f672, guest PC 0x0c0689ba */
if(!s->budget--) { s->failed_pc=0x0c0689bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0689bc;
P_0c0689bc: /* original f730, guest PC 0x0c0689bc */
if(!s->budget--) { s->failed_pc=0x0c0689bcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c0689be;
P_0c0689be: /* original f38c, guest PC 0x0c0689be */
if(!s->budget--) { s->failed_pc=0x0c0689beu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0689c0;
P_0c0689c0: /* original f89c, guest PC 0x0c0689c0 */
if(!s->budget--) { s->failed_pc=0x0c0689c0u; return 0; }
vf3_matrix_move(s,8,9);
goto P_0c0689c2;
P_0c0689c2: /* original f831, guest PC 0x0c0689c2 */
if(!s->budget--) { s->failed_pc=0x0c0689c2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0689c4;
P_0c0689c4: /* original f652, guest PC 0x0c0689c4 */
if(!s->budget--) { s->failed_pc=0x0c0689c4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0689c6;
P_0c0689c6: /* original f7a1, guest PC 0x0c0689c6 */
if(!s->budget--) { s->failed_pc=0x0c0689c6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c0689c8;
P_0c0689c8: /* original f690, guest PC 0x0c0689c8 */
if(!s->budget--) { s->failed_pc=0x0c0689c8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'+');
goto P_0c0689ca;
P_0c0689ca: /* original f782, guest PC 0x0c0689ca */
if(!s->budget--) { s->failed_pc=0x0c0689cau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c0689cc;
P_0c0689cc: /* original f37c, guest PC 0x0c0689cc */
if(!s->budget--) { s->failed_pc=0x0c0689ccu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689ce;
P_0c0689ce: /* original f7fc, guest PC 0x0c0689ce */
if(!s->budget--) { s->failed_pc=0x0c0689ceu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689d0;
P_0c0689d0: /* original f732, guest PC 0x0c0689d0 */
if(!s->budget--) { s->failed_pc=0x0c0689d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0689d2;
P_0c0689d2: /* original e004, guest PC 0x0c0689d2 */
if(!s->budget--) { s->failed_pc=0x0c0689d2u; return 0; }
r[0]=0x00000004u;
goto P_0c0689d4;
P_0c0689d4: /* original f37c, guest PC 0x0c0689d4 */
if(!s->budget--) { s->failed_pc=0x0c0689d4u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0689d6;
P_0c0689d6: /* original fa46, guest PC 0x0c0689d6 */
if(!s->budget--) { s->failed_pc=0x0c0689d6u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c0689d8;
P_0c0689d8: /* original f9d6, guest PC 0x0c0689d8 */
if(!s->budget--) { s->failed_pc=0x0c0689d8u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0689da;
P_0c0689da: /* original f7fc, guest PC 0x0c0689da */
if(!s->budget--) { s->failed_pc=0x0c0689dau; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689dc;
P_0c0689dc: /* original f732, guest PC 0x0c0689dc */
if(!s->budget--) { s->failed_pc=0x0c0689dcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0689de;
P_0c0689de: /* original 90b7, guest PC 0x0c0689de */
if(!s->budget--) { s->failed_pc=0x0c0689deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b50u,2);
goto P_0c0689e0;
P_0c0689e0: /* original f86c, guest PC 0x0c0689e0 */
if(!s->budget--) { s->failed_pc=0x0c0689e0u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c0689e2;
P_0c0689e2: /* original f3e6, guest PC 0x0c0689e2 */
if(!s->budget--) { s->failed_pc=0x0c0689e2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689e4;
P_0c0689e4: /* original e018, guest PC 0x0c0689e4 */
if(!s->budget--) { s->failed_pc=0x0c0689e4u; return 0; }
r[0]=0x00000018u;
goto P_0c0689e6;
P_0c0689e6: /* original f870, guest PC 0x0c0689e6 */
if(!s->budget--) { s->failed_pc=0x0c0689e6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'+');
goto P_0c0689e8;
P_0c0689e8: /* original ff37, guest PC 0x0c0689e8 */
if(!s->budget--) { s->failed_pc=0x0c0689e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0689ea;
P_0c0689ea: /* original 90b2, guest PC 0x0c0689ea */
if(!s->budget--) { s->failed_pc=0x0c0689eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b52u,2);
goto P_0c0689ec;
P_0c0689ec: /* original f7fc, guest PC 0x0c0689ec */
if(!s->budget--) { s->failed_pc=0x0c0689ecu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0689ee;
P_0c0689ee: /* original fb4c, guest PC 0x0c0689ee */
if(!s->budget--) { s->failed_pc=0x0c0689eeu; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c0689f0;
P_0c0689f0: /* original f7b1, guest PC 0x0c0689f0 */
if(!s->budget--) { s->failed_pc=0x0c0689f0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c0689f2;
P_0c0689f2: /* original f3e6, guest PC 0x0c0689f2 */
if(!s->budget--) { s->failed_pc=0x0c0689f2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0689f4;
P_0c0689f4: /* original e018, guest PC 0x0c0689f4 */
if(!s->budget--) { s->failed_pc=0x0c0689f4u; return 0; }
r[0]=0x00000018u;
goto P_0c0689f6;
P_0c0689f6: /* original f2f6, guest PC 0x0c0689f6 */
if(!s->budget--) { s->failed_pc=0x0c0689f6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0689f8;
P_0c0689f8: /* original e004, guest PC 0x0c0689f8 */
if(!s->budget--) { s->failed_pc=0x0c0689f8u; return 0; }
r[0]=0x00000004u;
goto P_0c0689fa;
P_0c0689fa: /* original f6fc, guest PC 0x0c0689fa */
if(!s->budget--) { s->failed_pc=0x0c0689fau; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0689fc;
P_0c0689fc: /* original f632, guest PC 0x0c0689fc */
if(!s->budget--) { s->failed_pc=0x0c0689fcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0689fe;
P_0c0689fe: /* original f272, guest PC 0x0c0689fe */
if(!s->budget--) { s->failed_pc=0x0c0689feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a00;
P_0c068a00: /* original f620, guest PC 0x0c068a00 */
if(!s->budget--) { s->failed_pc=0x0c068a00u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a02;
P_0c068a02: /* original ff27, guest PC 0x0c068a02 */
if(!s->budget--) { s->failed_pc=0x0c068a02u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a04;
P_0c068a04: /* original f37c, guest PC 0x0c068a04 */
if(!s->budget--) { s->failed_pc=0x0c068a04u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a06;
P_0c068a06: /* original f672, guest PC 0x0c068a06 */
if(!s->budget--) { s->failed_pc=0x0c068a06u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068a08;
P_0c068a08: /* original f730, guest PC 0x0c068a08 */
if(!s->budget--) { s->failed_pc=0x0c068a08u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068a0a;
P_0c068a0a: /* original f39c, guest PC 0x0c068a0a */
if(!s->budget--) { s->failed_pc=0x0c068a0au; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c068a0c;
P_0c068a0c: /* original f652, guest PC 0x0c068a0c */
if(!s->budget--) { s->failed_pc=0x0c068a0cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068a0e;
P_0c068a0e: /* original f7b1, guest PC 0x0c068a0e */
if(!s->budget--) { s->failed_pc=0x0c068a0eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'-');
goto P_0c068a10;
P_0c068a10: /* original f6a0, guest PC 0x0c068a10 */
if(!s->budget--) { s->failed_pc=0x0c068a10u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[10],r[18],'+');
goto P_0c068a12;
P_0c068a12: /* original f9ac, guest PC 0x0c068a12 */
if(!s->budget--) { s->failed_pc=0x0c068a12u; return 0; }
vf3_matrix_move(s,9,10);
goto P_0c068a14;
P_0c068a14: /* original f931, guest PC 0x0c068a14 */
if(!s->budget--) { s->failed_pc=0x0c068a14u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c068a16;
P_0c068a16: /* original e008, guest PC 0x0c068a16 */
if(!s->budget--) { s->failed_pc=0x0c068a16u; return 0; }
r[0]=0x00000008u;
goto P_0c068a18;
P_0c068a18: /* original fb46, guest PC 0x0c068a18 */
if(!s->budget--) { s->failed_pc=0x0c068a18u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c068a1a;
P_0c068a1a: /* original fad6, guest PC 0x0c068a1a */
if(!s->budget--) { s->failed_pc=0x0c068a1au; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068a1c;
P_0c068a1c: /* original f792, guest PC 0x0c068a1c */
if(!s->budget--) { s->failed_pc=0x0c068a1cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'*');
goto P_0c068a1e;
P_0c068a1e: /* original 9099, guest PC 0x0c068a1e */
if(!s->budget--) { s->failed_pc=0x0c068a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b54u,2);
goto P_0c068a20;
P_0c068a20: /* original f96c, guest PC 0x0c068a20 */
if(!s->budget--) { s->failed_pc=0x0c068a20u; return 0; }
vf3_matrix_move(s,9,6);
goto P_0c068a22;
P_0c068a22: /* original f37c, guest PC 0x0c068a22 */
if(!s->budget--) { s->failed_pc=0x0c068a22u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a24;
P_0c068a24: /* original f7fc, guest PC 0x0c068a24 */
if(!s->budget--) { s->failed_pc=0x0c068a24u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a26;
P_0c068a26: /* original f732, guest PC 0x0c068a26 */
if(!s->budget--) { s->failed_pc=0x0c068a26u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a28;
P_0c068a28: /* original f37c, guest PC 0x0c068a28 */
if(!s->budget--) { s->failed_pc=0x0c068a28u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a2a;
P_0c068a2a: /* original f7fc, guest PC 0x0c068a2a */
if(!s->budget--) { s->failed_pc=0x0c068a2au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a2c;
P_0c068a2c: /* original f732, guest PC 0x0c068a2c */
if(!s->budget--) { s->failed_pc=0x0c068a2cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a2e;
P_0c068a2e: /* original f3e6, guest PC 0x0c068a2e */
if(!s->budget--) { s->failed_pc=0x0c068a2eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a30;
P_0c068a30: /* original e024, guest PC 0x0c068a30 */
if(!s->budget--) { s->failed_pc=0x0c068a30u; return 0; }
r[0]=0x00000024u;
goto P_0c068a32;
P_0c068a32: /* original ff37, guest PC 0x0c068a32 */
if(!s->budget--) { s->failed_pc=0x0c068a32u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068a34;
P_0c068a34: /* original 908f, guest PC 0x0c068a34 */
if(!s->budget--) { s->failed_pc=0x0c068a34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b56u,2);
goto P_0c068a36;
P_0c068a36: /* original f970, guest PC 0x0c068a36 */
if(!s->budget--) { s->failed_pc=0x0c068a36u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'+');
goto P_0c068a38;
P_0c068a38: /* original fe4c, guest PC 0x0c068a38 */
if(!s->budget--) { s->failed_pc=0x0c068a38u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c068a3a;
P_0c068a3a: /* original f7fc, guest PC 0x0c068a3a */
if(!s->budget--) { s->failed_pc=0x0c068a3au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a3c;
P_0c068a3c: /* original f7e1, guest PC 0x0c068a3c */
if(!s->budget--) { s->failed_pc=0x0c068a3cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a3e;
P_0c068a3e: /* original f3e6, guest PC 0x0c068a3e */
if(!s->budget--) { s->failed_pc=0x0c068a3eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a40;
P_0c068a40: /* original e024, guest PC 0x0c068a40 */
if(!s->budget--) { s->failed_pc=0x0c068a40u; return 0; }
r[0]=0x00000024u;
goto P_0c068a42;
P_0c068a42: /* original f2f6, guest PC 0x0c068a42 */
if(!s->budget--) { s->failed_pc=0x0c068a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068a44;
P_0c068a44: /* original e014, guest PC 0x0c068a44 */
if(!s->budget--) { s->failed_pc=0x0c068a44u; return 0; }
r[0]=0x00000014u;
goto P_0c068a46;
P_0c068a46: /* original f6fc, guest PC 0x0c068a46 */
if(!s->budget--) { s->failed_pc=0x0c068a46u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068a48;
P_0c068a48: /* original f632, guest PC 0x0c068a48 */
if(!s->budget--) { s->failed_pc=0x0c068a48u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068a4a;
P_0c068a4a: /* original f272, guest PC 0x0c068a4a */
if(!s->budget--) { s->failed_pc=0x0c068a4au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a4c;
P_0c068a4c: /* original f620, guest PC 0x0c068a4c */
if(!s->budget--) { s->failed_pc=0x0c068a4cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a4e;
P_0c068a4e: /* original ff27, guest PC 0x0c068a4e */
if(!s->budget--) { s->failed_pc=0x0c068a4eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a50;
P_0c068a50: /* original f672, guest PC 0x0c068a50 */
if(!s->budget--) { s->failed_pc=0x0c068a50u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068a52;
P_0c068a52: /* original f37c, guest PC 0x0c068a52 */
if(!s->budget--) { s->failed_pc=0x0c068a52u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a54;
P_0c068a54: /* original f730, guest PC 0x0c068a54 */
if(!s->budget--) { s->failed_pc=0x0c068a54u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068a56;
P_0c068a56: /* original f3ac, guest PC 0x0c068a56 */
if(!s->budget--) { s->failed_pc=0x0c068a56u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068a58;
P_0c068a58: /* original e00c, guest PC 0x0c068a58 */
if(!s->budget--) { s->failed_pc=0x0c068a58u; return 0; }
r[0]=0x0000000cu;
goto P_0c068a5a;
P_0c068a5a: /* original fabc, guest PC 0x0c068a5a */
if(!s->budget--) { s->failed_pc=0x0c068a5au; return 0; }
vf3_matrix_move(s,10,11);
goto P_0c068a5c;
P_0c068a5c: /* original fa31, guest PC 0x0c068a5c */
if(!s->budget--) { s->failed_pc=0x0c068a5cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068a5e;
P_0c068a5e: /* original f652, guest PC 0x0c068a5e */
if(!s->budget--) { s->failed_pc=0x0c068a5eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068a60;
P_0c068a60: /* original f046, guest PC 0x0c068a60 */
if(!s->budget--) { s->failed_pc=0x0c068a60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]+r[0]);
goto P_0c068a62;
P_0c068a62: /* original f7e1, guest PC 0x0c068a62 */
if(!s->budget--) { s->failed_pc=0x0c068a62u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a64;
P_0c068a64: /* original f6b0, guest PC 0x0c068a64 */
if(!s->budget--) { s->failed_pc=0x0c068a64u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'+');
goto P_0c068a66;
P_0c068a66: /* original f7a2, guest PC 0x0c068a66 */
if(!s->budget--) { s->failed_pc=0x0c068a66u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068a68;
P_0c068a68: /* original fad6, guest PC 0x0c068a68 */
if(!s->budget--) { s->failed_pc=0x0c068a68u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068a6a;
P_0c068a6a: /* original 9075, guest PC 0x0c068a6a */
if(!s->budget--) { s->failed_pc=0x0c068a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b58u,2);
goto P_0c068a6c;
P_0c068a6c: /* original fb6c, guest PC 0x0c068a6c */
if(!s->budget--) { s->failed_pc=0x0c068a6cu; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c068a6e;
P_0c068a6e: /* original f37c, guest PC 0x0c068a6e */
if(!s->budget--) { s->failed_pc=0x0c068a6eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a70;
P_0c068a70: /* original f7fc, guest PC 0x0c068a70 */
if(!s->budget--) { s->failed_pc=0x0c068a70u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a72;
P_0c068a72: /* original f732, guest PC 0x0c068a72 */
if(!s->budget--) { s->failed_pc=0x0c068a72u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a74;
P_0c068a74: /* original f37c, guest PC 0x0c068a74 */
if(!s->budget--) { s->failed_pc=0x0c068a74u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a76;
P_0c068a76: /* original f7fc, guest PC 0x0c068a76 */
if(!s->budget--) { s->failed_pc=0x0c068a76u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a78;
P_0c068a78: /* original f732, guest PC 0x0c068a78 */
if(!s->budget--) { s->failed_pc=0x0c068a78u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068a7a;
P_0c068a7a: /* original f3e6, guest PC 0x0c068a7a */
if(!s->budget--) { s->failed_pc=0x0c068a7au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a7c;
P_0c068a7c: /* original e030, guest PC 0x0c068a7c */
if(!s->budget--) { s->failed_pc=0x0c068a7cu; return 0; }
r[0]=0x00000030u;
goto P_0c068a7e;
P_0c068a7e: /* original ff37, guest PC 0x0c068a7e */
if(!s->budget--) { s->failed_pc=0x0c068a7eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068a80;
P_0c068a80: /* original 906b, guest PC 0x0c068a80 */
if(!s->budget--) { s->failed_pc=0x0c068a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5au,2);
goto P_0c068a82;
P_0c068a82: /* original fb70, guest PC 0x0c068a82 */
if(!s->budget--) { s->failed_pc=0x0c068a82u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'+');
goto P_0c068a84;
P_0c068a84: /* original f6fc, guest PC 0x0c068a84 */
if(!s->budget--) { s->failed_pc=0x0c068a84u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068a86;
P_0c068a86: /* original f3e6, guest PC 0x0c068a86 */
if(!s->budget--) { s->failed_pc=0x0c068a86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068a88;
P_0c068a88: /* original e030, guest PC 0x0c068a88 */
if(!s->budget--) { s->failed_pc=0x0c068a88u; return 0; }
r[0]=0x00000030u;
goto P_0c068a8a;
P_0c068a8a: /* original f7fc, guest PC 0x0c068a8a */
if(!s->budget--) { s->failed_pc=0x0c068a8au; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068a8c;
P_0c068a8c: /* original f7e1, guest PC 0x0c068a8c */
if(!s->budget--) { s->failed_pc=0x0c068a8cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068a8e;
P_0c068a8e: /* original f632, guest PC 0x0c068a8e */
if(!s->budget--) { s->failed_pc=0x0c068a8eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068a90;
P_0c068a90: /* original f2f6, guest PC 0x0c068a90 */
if(!s->budget--) { s->failed_pc=0x0c068a90u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068a92;
P_0c068a92: /* original f272, guest PC 0x0c068a92 */
if(!s->budget--) { s->failed_pc=0x0c068a92u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068a94;
P_0c068a94: /* original e01c, guest PC 0x0c068a94 */
if(!s->budget--) { s->failed_pc=0x0c068a94u; return 0; }
r[0]=0x0000001cu;
goto P_0c068a96;
P_0c068a96: /* original f620, guest PC 0x0c068a96 */
if(!s->budget--) { s->failed_pc=0x0c068a96u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068a98;
P_0c068a98: /* original ff27, guest PC 0x0c068a98 */
if(!s->budget--) { s->failed_pc=0x0c068a98u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068a9a;
P_0c068a9a: /* original f37c, guest PC 0x0c068a9a */
if(!s->budget--) { s->failed_pc=0x0c068a9au; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068a9c;
P_0c068a9c: /* original e04c, guest PC 0x0c068a9c */
if(!s->budget--) { s->failed_pc=0x0c068a9cu; return 0; }
r[0]=0x0000004cu;
goto P_0c068a9e;
P_0c068a9e: /* original f672, guest PC 0x0c068a9e */
if(!s->budget--) { s->failed_pc=0x0c068a9eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068aa0;
P_0c068aa0: /* original f730, guest PC 0x0c068aa0 */
if(!s->budget--) { s->failed_pc=0x0c068aa0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068aa2;
P_0c068aa2: /* original f3ac, guest PC 0x0c068aa2 */
if(!s->budget--) { s->failed_pc=0x0c068aa2u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068aa4;
P_0c068aa4: /* original fa0c, guest PC 0x0c068aa4 */
if(!s->budget--) { s->failed_pc=0x0c068aa4u; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c068aa6;
P_0c068aa6: /* original fa31, guest PC 0x0c068aa6 */
if(!s->budget--) { s->failed_pc=0x0c068aa6u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068aa8;
P_0c068aa8: /* original f652, guest PC 0x0c068aa8 */
if(!s->budget--) { s->failed_pc=0x0c068aa8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068aaa;
P_0c068aaa: /* original f7e1, guest PC 0x0c068aaa */
if(!s->budget--) { s->failed_pc=0x0c068aaau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c068aac;
P_0c068aac: /* original f600, guest PC 0x0c068aac */
if(!s->budget--) { s->failed_pc=0x0c068aacu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[0],r[18],'+');
goto P_0c068aae;
P_0c068aae: /* original f7a2, guest PC 0x0c068aae */
if(!s->budget--) { s->failed_pc=0x0c068aaeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068ab0;
P_0c068ab0: /* original f37c, guest PC 0x0c068ab0 */
if(!s->budget--) { s->failed_pc=0x0c068ab0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068ab2;
P_0c068ab2: /* original f7fc, guest PC 0x0c068ab2 */
if(!s->budget--) { s->failed_pc=0x0c068ab2u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068ab4;
P_0c068ab4: /* original f732, guest PC 0x0c068ab4 */
if(!s->budget--) { s->failed_pc=0x0c068ab4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068ab6;
P_0c068ab6: /* original f37c, guest PC 0x0c068ab6 */
if(!s->budget--) { s->failed_pc=0x0c068ab6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068ab8;
P_0c068ab8: /* original f7fc, guest PC 0x0c068ab8 */
if(!s->budget--) { s->failed_pc=0x0c068ab8u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068aba;
P_0c068aba: /* original f732, guest PC 0x0c068aba */
if(!s->budget--) { s->failed_pc=0x0c068abau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068abc;
P_0c068abc: /* original f670, guest PC 0x0c068abc */
if(!s->budget--) { s->failed_pc=0x0c068abcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c068abe;
P_0c068abe: /* original ff67, guest PC 0x0c068abe */
if(!s->budget--) { s->failed_pc=0x0c068abeu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c068ac0;
P_0c068ac0: /* original e010, guest PC 0x0c068ac0 */
if(!s->budget--) { s->failed_pc=0x0c068ac0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ac2;
P_0c068ac2: /* original fad6, guest PC 0x0c068ac2 */
if(!s->budget--) { s->failed_pc=0x0c068ac2u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068ac4;
P_0c068ac4: /* original fe46, guest PC 0x0c068ac4 */
if(!s->budget--) { s->failed_pc=0x0c068ac4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c068ac6;
P_0c068ac6: /* original 9049, guest PC 0x0c068ac6 */
if(!s->budget--) { s->failed_pc=0x0c068ac6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5cu,2);
goto P_0c068ac8;
P_0c068ac8: /* original f3e6, guest PC 0x0c068ac8 */
if(!s->budget--) { s->failed_pc=0x0c068ac8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068aca;
P_0c068aca: /* original e028, guest PC 0x0c068aca */
if(!s->budget--) { s->failed_pc=0x0c068acau; return 0; }
r[0]=0x00000028u;
goto P_0c068acc;
P_0c068acc: /* original ff37, guest PC 0x0c068acc */
if(!s->budget--) { s->failed_pc=0x0c068accu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068ace;
P_0c068ace: /* original 9046, guest PC 0x0c068ace */
if(!s->budget--) { s->failed_pc=0x0c068aceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b5eu,2);
goto P_0c068ad0;
P_0c068ad0: /* original f3e6, guest PC 0x0c068ad0 */
if(!s->budget--) { s->failed_pc=0x0c068ad0u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068ad2;
P_0c068ad2: /* original f7fc, guest PC 0x0c068ad2 */
if(!s->budget--) { s->failed_pc=0x0c068ad2u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068ad4;
P_0c068ad4: /* original e028, guest PC 0x0c068ad4 */
if(!s->budget--) { s->failed_pc=0x0c068ad4u; return 0; }
r[0]=0x00000028u;
goto P_0c068ad6;
P_0c068ad6: /* original f04c, guest PC 0x0c068ad6 */
if(!s->budget--) { s->failed_pc=0x0c068ad6u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c068ad8;
P_0c068ad8: /* original f701, guest PC 0x0c068ad8 */
if(!s->budget--) { s->failed_pc=0x0c068ad8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068ada;
P_0c068ada: /* original f2f6, guest PC 0x0c068ada */
if(!s->budget--) { s->failed_pc=0x0c068adau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068adc;
P_0c068adc: /* original e02c, guest PC 0x0c068adc */
if(!s->budget--) { s->failed_pc=0x0c068adcu; return 0; }
r[0]=0x0000002cu;
goto P_0c068ade;
P_0c068ade: /* original f6fc, guest PC 0x0c068ade */
if(!s->budget--) { s->failed_pc=0x0c068adeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068ae0;
P_0c068ae0: /* original f632, guest PC 0x0c068ae0 */
if(!s->budget--) { s->failed_pc=0x0c068ae0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068ae2;
P_0c068ae2: /* original f272, guest PC 0x0c068ae2 */
if(!s->budget--) { s->failed_pc=0x0c068ae2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068ae4;
P_0c068ae4: /* original f620, guest PC 0x0c068ae4 */
if(!s->budget--) { s->failed_pc=0x0c068ae4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068ae6;
P_0c068ae6: /* original ff27, guest PC 0x0c068ae6 */
if(!s->budget--) { s->failed_pc=0x0c068ae6u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068ae8;
P_0c068ae8: /* original f37c, guest PC 0x0c068ae8 */
if(!s->budget--) { s->failed_pc=0x0c068ae8u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068aea;
P_0c068aea: /* original e03c, guest PC 0x0c068aea */
if(!s->budget--) { s->failed_pc=0x0c068aeau; return 0; }
r[0]=0x0000003cu;
goto P_0c068aec;
P_0c068aec: /* original f672, guest PC 0x0c068aec */
if(!s->budget--) { s->failed_pc=0x0c068aecu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068aee;
P_0c068aee: /* original f730, guest PC 0x0c068aee */
if(!s->budget--) { s->failed_pc=0x0c068aeeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c068af0;
P_0c068af0: /* original f3ac, guest PC 0x0c068af0 */
if(!s->budget--) { s->failed_pc=0x0c068af0u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068af2;
P_0c068af2: /* original faec, guest PC 0x0c068af2 */
if(!s->budget--) { s->failed_pc=0x0c068af2u; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c068af4;
P_0c068af4: /* original fa31, guest PC 0x0c068af4 */
if(!s->budget--) { s->failed_pc=0x0c068af4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068af6;
P_0c068af6: /* original f652, guest PC 0x0c068af6 */
if(!s->budget--) { s->failed_pc=0x0c068af6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068af8;
P_0c068af8: /* original f701, guest PC 0x0c068af8 */
if(!s->budget--) { s->failed_pc=0x0c068af8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068afa;
P_0c068afa: /* original f6e0, guest PC 0x0c068afa */
if(!s->budget--) { s->failed_pc=0x0c068afau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'+');
goto P_0c068afc;
P_0c068afc: /* original f7a2, guest PC 0x0c068afc */
if(!s->budget--) { s->failed_pc=0x0c068afcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'*');
goto P_0c068afe;
P_0c068afe: /* original f37c, guest PC 0x0c068afe */
if(!s->budget--) { s->failed_pc=0x0c068afeu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068b00;
P_0c068b00: /* original f7fc, guest PC 0x0c068b00 */
if(!s->budget--) { s->failed_pc=0x0c068b00u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b02;
P_0c068b02: /* original f732, guest PC 0x0c068b02 */
if(!s->budget--) { s->failed_pc=0x0c068b02u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068b04;
P_0c068b04: /* original f37c, guest PC 0x0c068b04 */
if(!s->budget--) { s->failed_pc=0x0c068b04u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c068b06;
P_0c068b06: /* original f7fc, guest PC 0x0c068b06 */
if(!s->budget--) { s->failed_pc=0x0c068b06u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b08;
P_0c068b08: /* original f732, guest PC 0x0c068b08 */
if(!s->budget--) { s->failed_pc=0x0c068b08u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c068b0a;
P_0c068b0a: /* original f670, guest PC 0x0c068b0a */
if(!s->budget--) { s->failed_pc=0x0c068b0au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c068b0c;
P_0c068b0c: /* original ff67, guest PC 0x0c068b0c */
if(!s->budget--) { s->failed_pc=0x0c068b0cu; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c068b0e;
P_0c068b0e: /* original e014, guest PC 0x0c068b0e */
if(!s->budget--) { s->failed_pc=0x0c068b0eu; return 0; }
r[0]=0x00000014u;
goto P_0c068b10;
P_0c068b10: /* original fe46, guest PC 0x0c068b10 */
if(!s->budget--) { s->failed_pc=0x0c068b10u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c068b12;
P_0c068b12: /* original fad6, guest PC 0x0c068b12 */
if(!s->budget--) { s->failed_pc=0x0c068b12u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c068b14;
P_0c068b14: /* original 9024, guest PC 0x0c068b14 */
if(!s->budget--) { s->failed_pc=0x0c068b14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b60u,2);
goto P_0c068b16;
P_0c068b16: /* original f3e6, guest PC 0x0c068b16 */
if(!s->budget--) { s->failed_pc=0x0c068b16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068b18;
P_0c068b18: /* original e048, guest PC 0x0c068b18 */
if(!s->budget--) { s->failed_pc=0x0c068b18u; return 0; }
r[0]=0x00000048u;
goto P_0c068b1a;
P_0c068b1a: /* original ff37, guest PC 0x0c068b1a */
if(!s->budget--) { s->failed_pc=0x0c068b1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c068b1c;
P_0c068b1c: /* original 9021, guest PC 0x0c068b1c */
if(!s->budget--) { s->failed_pc=0x0c068b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068b62u,2);
goto P_0c068b1e;
P_0c068b1e: /* original f7fc, guest PC 0x0c068b1e */
if(!s->budget--) { s->failed_pc=0x0c068b1eu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c068b20;
P_0c068b20: /* original f701, guest PC 0x0c068b20 */
if(!s->budget--) { s->failed_pc=0x0c068b20u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'-');
goto P_0c068b22;
P_0c068b22: /* original f3e6, guest PC 0x0c068b22 */
if(!s->budget--) { s->failed_pc=0x0c068b22u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c068b24;
P_0c068b24: /* original e048, guest PC 0x0c068b24 */
if(!s->budget--) { s->failed_pc=0x0c068b24u; return 0; }
r[0]=0x00000048u;
goto P_0c068b26;
P_0c068b26: /* original f2f6, guest PC 0x0c068b26 */
if(!s->budget--) { s->failed_pc=0x0c068b26u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c068b28;
P_0c068b28: /* original e044, guest PC 0x0c068b28 */
if(!s->budget--) { s->failed_pc=0x0c068b28u; return 0; }
r[0]=0x00000044u;
goto P_0c068b2a;
P_0c068b2a: /* original f6fc, guest PC 0x0c068b2a */
if(!s->budget--) { s->failed_pc=0x0c068b2au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c068b2c;
P_0c068b2c: /* original f632, guest PC 0x0c068b2c */
if(!s->budget--) { s->failed_pc=0x0c068b2cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c068b2e;
P_0c068b2e: /* original f272, guest PC 0x0c068b2e */
if(!s->budget--) { s->failed_pc=0x0c068b2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c068b30;
P_0c068b30: /* original f620, guest PC 0x0c068b30 */
if(!s->budget--) { s->failed_pc=0x0c068b30u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c068b32;
P_0c068b32: /* original ff27, guest PC 0x0c068b32 */
if(!s->budget--) { s->failed_pc=0x0c068b32u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c068b34;
P_0c068b34: /* original f3ac, guest PC 0x0c068b34 */
if(!s->budget--) { s->failed_pc=0x0c068b34u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c068b36;
P_0c068b36: /* original faec, guest PC 0x0c068b36 */
if(!s->budget--) { s->failed_pc=0x0c068b36u; return 0; }
vf3_matrix_move(s,10,14);
goto P_0c068b38;
P_0c068b38: /* original fa31, guest PC 0x0c068b38 */
if(!s->budget--) { s->failed_pc=0x0c068b38u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'-');
goto P_0c068b3a;
P_0c068b3a: /* original f672, guest PC 0x0c068b3a */
if(!s->budget--) { s->failed_pc=0x0c068b3au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c068b3c;
P_0c068b3c: /* original f652, guest PC 0x0c068b3c */
if(!s->budget--) { s->failed_pc=0x0c068b3cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c068b3e;
P_0c068b3e: /* original f57c, guest PC 0x0c068b3e */
if(!s->budget--) { s->failed_pc=0x0c068b3eu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c068b40;
P_0c068b40: /* original f570, guest PC 0x0c068b40 */
if(!s->budget--) { s->failed_pc=0x0c068b40u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'+');
goto P_0c068b42;
P_0c068b42: /* original f6e0, guest PC 0x0c068b42 */
if(!s->budget--) { s->failed_pc=0x0c068b42u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'+');
goto P_0c068b44;
P_0c068b44: /* original f501, guest PC 0x0c068b44 */
if(!s->budget--) { s->failed_pc=0x0c068b44u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[0],r[18],'-');
goto P_0c068b46;
P_0c068b46: /* original f5a2, guest PC 0x0c068b46 */
if(!s->budget--) { s->failed_pc=0x0c068b46u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c068b48;
P_0c068b48: /* original f35c, guest PC 0x0c068b48 */
if(!s->budget--) { s->failed_pc=0x0c068b48u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b4a;
P_0c068b4a: /* original a00b, guest PC 0x0c068b4a */
if(!s->budget--) { s->failed_pc=0x0c068b4au; return 0; }
goto P_0c068b64;
P_0c068b4c: /* original 0009, guest PC 0x0c068b4c */
if(!s->budget--) { s->failed_pc=0x0c068b4cu; return 0; }
if(!vf3_matrix_family(0x0c068b4eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068b4eu; return 0; } return 1;
P_0c068b64: /* original f5fc, guest PC 0x0c068b64 */
if(!s->budget--) { s->failed_pc=0x0c068b64u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c068b66;
P_0c068b66: /* original f532, guest PC 0x0c068b66 */
if(!s->budget--) { s->failed_pc=0x0c068b66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068b68;
P_0c068b68: /* original 2558, guest PC 0x0c068b68 */
if(!s->budget--) { s->failed_pc=0x0c068b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c068b6a;
P_0c068b6a: /* original f35c, guest PC 0x0c068b6a */
if(!s->budget--) { s->failed_pc=0x0c068b6au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b6c;
P_0c068b6c: /* original f5fc, guest PC 0x0c068b6c */
if(!s->budget--) { s->failed_pc=0x0c068b6cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c068b6e;
P_0c068b6e: /* original f532, guest PC 0x0c068b6e */
if(!s->budget--) { s->failed_pc=0x0c068b6eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068b70;
P_0c068b70: /* original f35c, guest PC 0x0c068b70 */
if(!s->budget--) { s->failed_pc=0x0c068b70u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068b72;
P_0c068b72: /* original f56c, guest PC 0x0c068b72 */
if(!s->budget--) { s->failed_pc=0x0c068b72u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c068b74;
P_0c068b74: /* original 8f10, guest PC 0x0c068b74 */
if(!s->budget--) { s->failed_pc=0x0c068b74u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
if(!cond) { goto P_0c068b98; }
goto P_0c068b78;
P_0c068b76: /* original f530, guest PC 0x0c068b76 */
if(!s->budget--) { s->failed_pc=0x0c068b76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c068b78;
P_0c068b78: /* original e010, guest PC 0x0c068b78 */
if(!s->budget--) { s->failed_pc=0x0c068b78u; return 0; }
r[0]=0x00000010u;
goto P_0c068b7a;
P_0c068b7a: /* original fe87, guest PC 0x0c068b7a */
if(!s->budget--) { s->failed_pc=0x0c068b7au; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c068b7c;
P_0c068b7c: /* original e014, guest PC 0x0c068b7c */
if(!s->budget--) { s->failed_pc=0x0c068b7cu; return 0; }
r[0]=0x00000014u;
goto P_0c068b7e;
P_0c068b7e: /* original fe97, guest PC 0x0c068b7e */
if(!s->budget--) { s->failed_pc=0x0c068b7eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c068b80;
P_0c068b80: /* original e018, guest PC 0x0c068b80 */
if(!s->budget--) { s->failed_pc=0x0c068b80u; return 0; }
r[0]=0x00000018u;
goto P_0c068b82;
P_0c068b82: /* original feb7, guest PC 0x0c068b82 */
if(!s->budget--) { s->failed_pc=0x0c068b82u; return 0; }
vf3_matrix_store(s,ram,11,r[14]+r[0]);
goto P_0c068b84;
P_0c068b84: /* original e04c, guest PC 0x0c068b84 */
if(!s->budget--) { s->failed_pc=0x0c068b84u; return 0; }
r[0]=0x0000004cu;
goto P_0c068b86;
P_0c068b86: /* original f3f6, guest PC 0x0c068b86 */
if(!s->budget--) { s->failed_pc=0x0c068b86u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068b88;
P_0c068b88: /* original 903c, guest PC 0x0c068b88 */
if(!s->budget--) { s->failed_pc=0x0c068b88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c04u,2);
goto P_0c068b8a;
P_0c068b8a: /* original fe37, guest PC 0x0c068b8a */
if(!s->budget--) { s->failed_pc=0x0c068b8au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068b8c;
P_0c068b8c: /* original e03c, guest PC 0x0c068b8c */
if(!s->budget--) { s->failed_pc=0x0c068b8cu; return 0; }
r[0]=0x0000003cu;
goto P_0c068b8e;
P_0c068b8e: /* original f3f6, guest PC 0x0c068b8e */
if(!s->budget--) { s->failed_pc=0x0c068b8eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c068b90;
P_0c068b90: /* original 9039, guest PC 0x0c068b90 */
if(!s->budget--) { s->failed_pc=0x0c068b90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c06u,2);
goto P_0c068b92;
P_0c068b92: /* original fe37, guest PC 0x0c068b92 */
if(!s->budget--) { s->failed_pc=0x0c068b92u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c068b94;
P_0c068b94: /* original 7004, guest PC 0x0c068b94 */
if(!s->budget--) { s->failed_pc=0x0c068b94u; return 0; }
r[0]+=0x00000004u;
goto P_0c068b96;
P_0c068b96: /* original fe57, guest PC 0x0c068b96 */
if(!s->budget--) { s->failed_pc=0x0c068b96u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068b98;
P_0c068b98: /* original 9036, guest PC 0x0c068b98 */
if(!s->budget--) { s->failed_pc=0x0c068b98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c08u,2);
goto P_0c068b9a;
P_0c068b9a: /* original f5e6, guest PC 0x0c068b9a */
if(!s->budget--) { s->failed_pc=0x0c068b9au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c068b9c;
P_0c068b9c: /* original f540, guest PC 0x0c068b9c */
if(!s->budget--) { s->failed_pc=0x0c068b9cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c068b9e;
P_0c068b9e: /* original fe57, guest PC 0x0c068b9e */
if(!s->budget--) { s->failed_pc=0x0c068b9eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c068ba0;
P_0c068ba0: /* original e010, guest PC 0x0c068ba0 */
if(!s->budget--) { s->failed_pc=0x0c068ba0u; return 0; }
r[0]=0x00000010u;
goto P_0c068ba2;
P_0c068ba2: /* original f8e6, guest PC 0x0c068ba2 */
if(!s->budget--) { s->failed_pc=0x0c068ba2u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c068ba4;
P_0c068ba4: /* original e014, guest PC 0x0c068ba4 */
if(!s->budget--) { s->failed_pc=0x0c068ba4u; return 0; }
r[0]=0x00000014u;
goto P_0c068ba6;
P_0c068ba6: /* original f7e6, guest PC 0x0c068ba6 */
if(!s->budget--) { s->failed_pc=0x0c068ba6u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c068ba8;
P_0c068ba8: /* original e018, guest PC 0x0c068ba8 */
if(!s->budget--) { s->failed_pc=0x0c068ba8u; return 0; }
r[0]=0x00000018u;
goto P_0c068baa;
P_0c068baa: /* original f6e6, guest PC 0x0c068baa */
if(!s->budget--) { s->failed_pc=0x0c068baau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c068bac;
P_0c068bac: /* original 902a, guest PC 0x0c068bac */
if(!s->budget--) { s->failed_pc=0x0c068bacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068c04u,2);
goto P_0c068bae;
P_0c068bae: /* original d317, guest PC 0x0c068bae */
if(!s->budget--) { s->failed_pc=0x0c068baeu; return 0; }
r[3]=read(ram,0x0c068c0cu,4);
goto P_0c068bb0;
P_0c068bb0: /* original f9e6, guest PC 0x0c068bb0 */
if(!s->budget--) { s->failed_pc=0x0c068bb0u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c068bb2;
P_0c068bb2: /* original 7004, guest PC 0x0c068bb2 */
if(!s->budget--) { s->failed_pc=0x0c068bb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c068bb4;
P_0c068bb4: /* original f4e6, guest PC 0x0c068bb4 */
if(!s->budget--) { s->failed_pc=0x0c068bb4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c068bb6;
P_0c068bb6: /* original 7004, guest PC 0x0c068bb6 */
if(!s->budget--) { s->failed_pc=0x0c068bb6u; return 0; }
r[0]+=0x00000004u;
goto P_0c068bb8;
P_0c068bb8: /* original fee6, guest PC 0x0c068bb8 */
if(!s->budget--) { s->failed_pc=0x0c068bb8u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c068bba;
P_0c068bba: /* original ff9c, guest PC 0x0c068bba */
if(!s->budget--) { s->failed_pc=0x0c068bbau; return 0; }
vf3_matrix_move(s,15,9);
goto P_0c068bbc;
P_0c068bbc: /* original ff81, guest PC 0x0c068bbc */
if(!s->budget--) { s->failed_pc=0x0c068bbcu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[8],r[18],'-');
goto P_0c068bbe;
P_0c068bbe: /* original fe61, guest PC 0x0c068bbe */
if(!s->budget--) { s->failed_pc=0x0c068bbeu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'-');
goto P_0c068bc0;
P_0c068bc0: /* original f471, guest PC 0x0c068bc0 */
if(!s->budget--) { s->failed_pc=0x0c068bc0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c068bc2;
P_0c068bc2: /* original f0fc, guest PC 0x0c068bc2 */
if(!s->budget--) { s->failed_pc=0x0c068bc2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c068bc4;
P_0c068bc4: /* original f3ec, guest PC 0x0c068bc4 */
if(!s->budget--) { s->failed_pc=0x0c068bc4u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c068bc6;
P_0c068bc6: /* original f3e2, guest PC 0x0c068bc6 */
if(!s->budget--) { s->failed_pc=0x0c068bc6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c068bc8;
P_0c068bc8: /* original f3fe, guest PC 0x0c068bc8 */
if(!s->budget--) { s->failed_pc=0x0c068bc8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c068bca;
P_0c068bca: /* original f36d, guest PC 0x0c068bca */
if(!s->budget--) { s->failed_pc=0x0c068bcau; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c068bcc;
P_0c068bcc: /* original 430b, guest PC 0x0c068bcc */
if(!s->budget--) { s->failed_pc=0x0c068bccu; return 0; }
target=r[3];
r[16]=code_base|0x0c068bd0u;
vf3_matrix_move(s,5,3);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068bd0u) { target=s->pc; goto dispatch; }
goto P_0c068bd0;
P_0c068bce: /* original f53c, guest PC 0x0c068bce */
if(!s->budget--) { s->failed_pc=0x0c068bceu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c068bd0;
P_0c068bd0: /* original 600f, guest PC 0x0c068bd0 */
if(!s->budget--) { s->failed_pc=0x0c068bd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c068bd2;
P_0c068bd2: /* original 2f02, guest PC 0x0c068bd2 */
if(!s->budget--) { s->failed_pc=0x0c068bd2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c068bd4;
P_0c068bd4: /* original f4fc, guest PC 0x0c068bd4 */
if(!s->budget--) { s->failed_pc=0x0c068bd4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c068bd6;
P_0c068bd6: /* original d30d, guest PC 0x0c068bd6 */
if(!s->budget--) { s->failed_pc=0x0c068bd6u; return 0; }
r[3]=read(ram,0x0c068c0cu,4);
goto P_0c068bd8;
P_0c068bd8: /* original f44d, guest PC 0x0c068bd8 */
if(!s->budget--) { s->failed_pc=0x0c068bd8u; return 0; }
fr[4]^=0x80000000u;
goto P_0c068bda;
P_0c068bda: /* original 430b, guest PC 0x0c068bda */
if(!s->budget--) { s->failed_pc=0x0c068bdau; return 0; }
target=r[3];
r[16]=code_base|0x0c068bdeu;
vf3_matrix_move(s,5,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068bdeu) { target=s->pc; goto dispatch; }
goto P_0c068bde;
P_0c068bdc: /* original f5ec, guest PC 0x0c068bdc */
if(!s->budget--) { s->failed_pc=0x0c068bdcu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c068bde;
P_0c068bde: /* original 640f, guest PC 0x0c068bde */
if(!s->budget--) { s->failed_pc=0x0c068bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c068be0;
P_0c068be0: /* original 60f2, guest PC 0x0c068be0 */
if(!s->budget--) { s->failed_pc=0x0c068be0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c068be2;
P_0c068be2: /* original 81ee, guest PC 0x0c068be2 */
if(!s->budget--) { s->failed_pc=0x0c068be2u; return 0; }
write(ram,r[14]+28,r[0],2);
goto P_0c068be4;
P_0c068be4: /* original 6043, guest PC 0x0c068be4 */
if(!s->budget--) { s->failed_pc=0x0c068be4u; return 0; }
r[0]=r[4];
goto P_0c068be6;
P_0c068be6: /* original 81ef, guest PC 0x0c068be6 */
if(!s->budget--) { s->failed_pc=0x0c068be6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c068be8;
P_0c068be8: /* original 85ef, guest PC 0x0c068be8 */
if(!s->budget--) { s->failed_pc=0x0c068be8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c068bea;
P_0c068bea: /* original 640d, guest PC 0x0c068bea */
if(!s->budget--) { s->failed_pc=0x0c068beau; return 0; }
r[4]=r[0]&65535u;
goto P_0c068bec;
P_0c068bec: /* original 2448, guest PC 0x0c068bec */
if(!s->budget--) { s->failed_pc=0x0c068becu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068bee;
P_0c068bee: /* original 8b00, guest PC 0x0c068bee */
if(!s->budget--) { s->failed_pc=0x0c068beeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068bf2; }
goto P_0c068bf0;
P_0c068bf0: /* original e401, guest PC 0x0c068bf0 */
if(!s->budget--) { s->failed_pc=0x0c068bf0u; return 0; }
r[4]=0x00000001u;
goto P_0c068bf2;
P_0c068bf2: /* original 7f50, guest PC 0x0c068bf2 */
if(!s->budget--) { s->failed_pc=0x0c068bf2u; return 0; }
r[15]+=0x00000050u;
goto P_0c068bf4;
P_0c068bf4: /* original 6043, guest PC 0x0c068bf4 */
if(!s->budget--) { s->failed_pc=0x0c068bf4u; return 0; }
r[0]=r[4];
goto P_0c068bf6;
P_0c068bf6: /* original 4f26, guest PC 0x0c068bf6 */
if(!s->budget--) { s->failed_pc=0x0c068bf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068bf8;
P_0c068bf8: /* original 81ef, guest PC 0x0c068bf8 */
if(!s->budget--) { s->failed_pc=0x0c068bf8u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c068bfa;
P_0c068bfa: /* original fef9, guest PC 0x0c068bfa */
if(!s->budget--) { s->failed_pc=0x0c068bfau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c068bfc;
P_0c068bfc: /* original fff9, guest PC 0x0c068bfc */
if(!s->budget--) { s->failed_pc=0x0c068bfcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c068bfe;
P_0c068bfe: /* original 6df6, guest PC 0x0c068bfe */
if(!s->budget--) { s->failed_pc=0x0c068bfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068c00;
P_0c068c00: /* original 000b, guest PC 0x0c068c00 */
if(!s->budget--) { s->failed_pc=0x0c068c00u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068c02: /* original 6ef6, guest PC 0x0c068c02 */
if(!s->budget--) { s->failed_pc=0x0c068c02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c068c04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068c04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
