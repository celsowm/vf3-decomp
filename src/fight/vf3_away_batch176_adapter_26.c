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
int vf3_away_batch176_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c098040u: goto P_0c098040;
case 0x0c098042u: goto P_0c098042;
case 0x0c098044u: goto P_0c098044;
case 0x0c098046u: goto P_0c098046;
case 0x0c098048u: goto P_0c098048;
case 0x0c09804au: goto P_0c09804a;
case 0x0c09804cu: goto P_0c09804c;
case 0x0c09804eu: goto P_0c09804e;
case 0x0c098050u: goto P_0c098050;
case 0x0c098052u: goto P_0c098052;
case 0x0c098054u: goto P_0c098054;
case 0x0c098056u: goto P_0c098056;
case 0x0c098058u: goto P_0c098058;
case 0x0c09805au: goto P_0c09805a;
case 0x0c09805cu: goto P_0c09805c;
case 0x0c09805eu: goto P_0c09805e;
case 0x0c098060u: goto P_0c098060;
case 0x0c098062u: goto P_0c098062;
case 0x0c098064u: goto P_0c098064;
case 0x0c098066u: goto P_0c098066;
case 0x0c098068u: goto P_0c098068;
case 0x0c09806au: goto P_0c09806a;
case 0x0c09806cu: goto P_0c09806c;
case 0x0c09806eu: goto P_0c09806e;
case 0x0c098070u: goto P_0c098070;
case 0x0c098072u: goto P_0c098072;
case 0x0c098074u: goto P_0c098074;
case 0x0c098076u: goto P_0c098076;
case 0x0c098078u: goto P_0c098078;
case 0x0c09807au: goto P_0c09807a;
case 0x0c09807cu: goto P_0c09807c;
case 0x0c09807eu: goto P_0c09807e;
case 0x0c098080u: goto P_0c098080;
case 0x0c098082u: goto P_0c098082;
case 0x0c098084u: goto P_0c098084;
case 0x0c098086u: goto P_0c098086;
case 0x0c098088u: goto P_0c098088;
case 0x0c09845cu: goto P_0c09845c;
case 0x0c09845eu: goto P_0c09845e;
case 0x0c098460u: goto P_0c098460;
case 0x0c098462u: goto P_0c098462;
case 0x0c098464u: goto P_0c098464;
case 0x0c098466u: goto P_0c098466;
case 0x0c098468u: goto P_0c098468;
case 0x0c09846au: goto P_0c09846a;
case 0x0c09846cu: goto P_0c09846c;
case 0x0c09846eu: goto P_0c09846e;
case 0x0c098470u: goto P_0c098470;
case 0x0c098472u: goto P_0c098472;
case 0x0c098474u: goto P_0c098474;
case 0x0c098476u: goto P_0c098476;
case 0x0c098478u: goto P_0c098478;
case 0x0c09847au: goto P_0c09847a;
case 0x0c09847cu: goto P_0c09847c;
case 0x0c09847eu: goto P_0c09847e;
case 0x0c098480u: goto P_0c098480;
case 0x0c098482u: goto P_0c098482;
case 0x0c098484u: goto P_0c098484;
case 0x0c098486u: goto P_0c098486;
case 0x0c098488u: goto P_0c098488;
case 0x0c09848au: goto P_0c09848a;
case 0x0c09848cu: goto P_0c09848c;
case 0x0c09848eu: goto P_0c09848e;
case 0x0c098490u: goto P_0c098490;
case 0x0c098492u: goto P_0c098492;
case 0x0c098494u: goto P_0c098494;
case 0x0c098496u: goto P_0c098496;
case 0x0c098498u: goto P_0c098498;
case 0x0c09849au: goto P_0c09849a;
case 0x0c09849cu: goto P_0c09849c;
case 0x0c09849eu: goto P_0c09849e;
case 0x0c0984a0u: goto P_0c0984a0;
case 0x0c0984a2u: goto P_0c0984a2;
case 0x0c0984a4u: goto P_0c0984a4;
case 0x0c0984a6u: goto P_0c0984a6;
case 0x0c0984a8u: goto P_0c0984a8;
case 0x0c0984aau: goto P_0c0984aa;
case 0x0c0984acu: goto P_0c0984ac;
case 0x0c0984aeu: goto P_0c0984ae;
case 0x0c0984b0u: goto P_0c0984b0;
case 0x0c0984b2u: goto P_0c0984b2;
case 0x0c0984b4u: goto P_0c0984b4;
case 0x0c0984b6u: goto P_0c0984b6;
case 0x0c0984b8u: goto P_0c0984b8;
case 0x0c0984bau: goto P_0c0984ba;
case 0x0c0984bcu: goto P_0c0984bc;
case 0x0c0984beu: goto P_0c0984be;
case 0x0c0984c0u: goto P_0c0984c0;
case 0x0c0984c2u: goto P_0c0984c2;
case 0x0c0984c4u: goto P_0c0984c4;
case 0x0c0984c6u: goto P_0c0984c6;
case 0x0c0984c8u: goto P_0c0984c8;
case 0x0c0984cau: goto P_0c0984ca;
case 0x0c0984ccu: goto P_0c0984cc;
case 0x0c0984ceu: goto P_0c0984ce;
case 0x0c0984d0u: goto P_0c0984d0;
case 0x0c0984d2u: goto P_0c0984d2;
case 0x0c0984d4u: goto P_0c0984d4;
case 0x0c0984d6u: goto P_0c0984d6;
case 0x0c0984d8u: goto P_0c0984d8;
case 0x0c0984dau: goto P_0c0984da;
case 0x0c0984dcu: goto P_0c0984dc;
case 0x0c0984deu: goto P_0c0984de;
case 0x0c0984e0u: goto P_0c0984e0;
case 0x0c0984e2u: goto P_0c0984e2;
case 0x0c0984e4u: goto P_0c0984e4;
case 0x0c0984e6u: goto P_0c0984e6;
case 0x0c0984e8u: goto P_0c0984e8;
case 0x0c0984eau: goto P_0c0984ea;
case 0x0c0984ecu: goto P_0c0984ec;
case 0x0c0984eeu: goto P_0c0984ee;
case 0x0c0984f0u: goto P_0c0984f0;
case 0x0c0984f2u: goto P_0c0984f2;
case 0x0c0984f4u: goto P_0c0984f4;
case 0x0c0984f6u: goto P_0c0984f6;
case 0x0c0984f8u: goto P_0c0984f8;
case 0x0c0984fau: goto P_0c0984fa;
case 0x0c0984fcu: goto P_0c0984fc;
case 0x0c0984feu: goto P_0c0984fe;
case 0x0c098500u: goto P_0c098500;
case 0x0c098502u: goto P_0c098502;
case 0x0c098504u: goto P_0c098504;
case 0x0c098506u: goto P_0c098506;
case 0x0c098508u: goto P_0c098508;
case 0x0c09850au: goto P_0c09850a;
case 0x0c09850cu: goto P_0c09850c;
case 0x0c09850eu: goto P_0c09850e;
case 0x0c098510u: goto P_0c098510;
case 0x0c098512u: goto P_0c098512;
case 0x0c098514u: goto P_0c098514;
case 0x0c098516u: goto P_0c098516;
case 0x0c098518u: goto P_0c098518;
case 0x0c09851au: goto P_0c09851a;
case 0x0c09851cu: goto P_0c09851c;
case 0x0c09851eu: goto P_0c09851e;
case 0x0c098520u: goto P_0c098520;
case 0x0c098522u: goto P_0c098522;
case 0x0c098524u: goto P_0c098524;
case 0x0c098526u: goto P_0c098526;
case 0x0c098528u: goto P_0c098528;
case 0x0c09852au: goto P_0c09852a;
case 0x0c09852cu: goto P_0c09852c;
case 0x0c09852eu: goto P_0c09852e;
case 0x0c098530u: goto P_0c098530;
case 0x0c098532u: goto P_0c098532;
case 0x0c098534u: goto P_0c098534;
case 0x0c098536u: goto P_0c098536;
case 0x0c098538u: goto P_0c098538;
case 0x0c09853au: goto P_0c09853a;
case 0x0c09853cu: goto P_0c09853c;
case 0x0c09853eu: goto P_0c09853e;
case 0x0c098540u: goto P_0c098540;
case 0x0c098542u: goto P_0c098542;
case 0x0c098544u: goto P_0c098544;
case 0x0c098546u: goto P_0c098546;
case 0x0c098548u: goto P_0c098548;
case 0x0c09854au: goto P_0c09854a;
case 0x0c09877cu: goto P_0c09877c;
case 0x0c09877eu: goto P_0c09877e;
case 0x0c098780u: goto P_0c098780;
case 0x0c098782u: goto P_0c098782;
case 0x0c098784u: goto P_0c098784;
case 0x0c098786u: goto P_0c098786;
case 0x0c098788u: goto P_0c098788;
case 0x0c09878au: goto P_0c09878a;
case 0x0c09878cu: goto P_0c09878c;
case 0x0c09878eu: goto P_0c09878e;
case 0x0c098790u: goto P_0c098790;
case 0x0c098792u: goto P_0c098792;
case 0x0c098794u: goto P_0c098794;
case 0x0c098796u: goto P_0c098796;
case 0x0c098798u: goto P_0c098798;
case 0x0c09879au: goto P_0c09879a;
case 0x0c09879cu: goto P_0c09879c;
case 0x0c09879eu: goto P_0c09879e;
case 0x0c0987a0u: goto P_0c0987a0;
case 0x0c0987a2u: goto P_0c0987a2;
case 0x0c0987a4u: goto P_0c0987a4;
case 0x0c0987a6u: goto P_0c0987a6;
case 0x0c0987a8u: goto P_0c0987a8;
case 0x0c0987aau: goto P_0c0987aa;
case 0x0c0987acu: goto P_0c0987ac;
case 0x0c0987aeu: goto P_0c0987ae;
case 0x0c0987b0u: goto P_0c0987b0;
case 0x0c0987b2u: goto P_0c0987b2;
case 0x0c0987b4u: goto P_0c0987b4;
case 0x0c0987b6u: goto P_0c0987b6;
case 0x0c0987b8u: goto P_0c0987b8;
case 0x0c0987bau: goto P_0c0987ba;
case 0x0c0987bcu: goto P_0c0987bc;
case 0x0c0987beu: goto P_0c0987be;
case 0x0c0987c0u: goto P_0c0987c0;
case 0x0c0987c2u: goto P_0c0987c2;
case 0x0c0987c4u: goto P_0c0987c4;
case 0x0c0987c6u: goto P_0c0987c6;
case 0x0c0987c8u: goto P_0c0987c8;
case 0x0c0987cau: goto P_0c0987ca;
case 0x0c0987ccu: goto P_0c0987cc;
case 0x0c0987ceu: goto P_0c0987ce;
case 0x0c0987d0u: goto P_0c0987d0;
case 0x0c0987d2u: goto P_0c0987d2;
case 0x0c0987d4u: goto P_0c0987d4;
case 0x0c0987d6u: goto P_0c0987d6;
case 0x0c0987d8u: goto P_0c0987d8;
case 0x0c0987dau: goto P_0c0987da;
case 0x0c0987dcu: goto P_0c0987dc;
case 0x0c0987deu: goto P_0c0987de;
case 0x0c0987e0u: goto P_0c0987e0;
case 0x0c0987e2u: goto P_0c0987e2;
case 0x0c0987e4u: goto P_0c0987e4;
case 0x0c0987e6u: goto P_0c0987e6;
case 0x0c0987e8u: goto P_0c0987e8;
case 0x0c0987eau: goto P_0c0987ea;
case 0x0c0987ecu: goto P_0c0987ec;
case 0x0c0987eeu: goto P_0c0987ee;
case 0x0c0987f0u: goto P_0c0987f0;
case 0x0c0987f2u: goto P_0c0987f2;
case 0x0c0987f4u: goto P_0c0987f4;
case 0x0c0987f6u: goto P_0c0987f6;
case 0x0c0987f8u: goto P_0c0987f8;
case 0x0c0987fau: goto P_0c0987fa;
case 0x0c0987fcu: goto P_0c0987fc;
case 0x0c0987feu: goto P_0c0987fe;
case 0x0c098800u: goto P_0c098800;
case 0x0c098802u: goto P_0c098802;
case 0x0c098804u: goto P_0c098804;
case 0x0c098806u: goto P_0c098806;
case 0x0c098808u: goto P_0c098808;
case 0x0c09880au: goto P_0c09880a;
case 0x0c09880cu: goto P_0c09880c;
case 0x0c09880eu: goto P_0c09880e;
case 0x0c098810u: goto P_0c098810;
case 0x0c098812u: goto P_0c098812;
case 0x0c098814u: goto P_0c098814;
case 0x0c098816u: goto P_0c098816;
case 0x0c098818u: goto P_0c098818;
case 0x0c09881au: goto P_0c09881a;
case 0x0c09881cu: goto P_0c09881c;
case 0x0c09881eu: goto P_0c09881e;
case 0x0c098820u: goto P_0c098820;
case 0x0c098822u: goto P_0c098822;
case 0x0c098824u: goto P_0c098824;
case 0x0c098826u: goto P_0c098826;
case 0x0c098828u: goto P_0c098828;
case 0x0c09882au: goto P_0c09882a;
case 0x0c09882cu: goto P_0c09882c;
case 0x0c09882eu: goto P_0c09882e;
case 0x0c098830u: goto P_0c098830;
case 0x0c098832u: goto P_0c098832;
case 0x0c098834u: goto P_0c098834;
case 0x0c098836u: goto P_0c098836;
case 0x0c098838u: goto P_0c098838;
case 0x0c09883au: goto P_0c09883a;
case 0x0c09883cu: goto P_0c09883c;
case 0x0c09883eu: goto P_0c09883e;
case 0x0c098840u: goto P_0c098840;
case 0x0c098842u: goto P_0c098842;
case 0x0c098844u: goto P_0c098844;
case 0x0c098846u: goto P_0c098846;
case 0x0c098848u: goto P_0c098848;
case 0x0c09884au: goto P_0c09884a;
case 0x0c0988b0u: goto P_0c0988b0;
case 0x0c0988b2u: goto P_0c0988b2;
case 0x0c0988b4u: goto P_0c0988b4;
case 0x0c0988b6u: goto P_0c0988b6;
case 0x0c0988b8u: goto P_0c0988b8;
case 0x0c0988bau: goto P_0c0988ba;
case 0x0c0988bcu: goto P_0c0988bc;
case 0x0c0988beu: goto P_0c0988be;
case 0x0c0988c0u: goto P_0c0988c0;
case 0x0c0988c2u: goto P_0c0988c2;
case 0x0c0988c4u: goto P_0c0988c4;
case 0x0c0988c6u: goto P_0c0988c6;
case 0x0c0988c8u: goto P_0c0988c8;
case 0x0c0988cau: goto P_0c0988ca;
case 0x0c0988ccu: goto P_0c0988cc;
case 0x0c0988ceu: goto P_0c0988ce;
case 0x0c0988d0u: goto P_0c0988d0;
case 0x0c0988d2u: goto P_0c0988d2;
case 0x0c0988d4u: goto P_0c0988d4;
case 0x0c0988d6u: goto P_0c0988d6;
case 0x0c0988d8u: goto P_0c0988d8;
case 0x0c0988dau: goto P_0c0988da;
case 0x0c0988dcu: goto P_0c0988dc;
case 0x0c0988deu: goto P_0c0988de;
case 0x0c0988e0u: goto P_0c0988e0;
case 0x0c0988e2u: goto P_0c0988e2;
case 0x0c0988e4u: goto P_0c0988e4;
case 0x0c0988e6u: goto P_0c0988e6;
case 0x0c0988e8u: goto P_0c0988e8;
case 0x0c0988eau: goto P_0c0988ea;
case 0x0c0988ecu: goto P_0c0988ec;
case 0x0c0988eeu: goto P_0c0988ee;
case 0x0c0988f0u: goto P_0c0988f0;
case 0x0c0988f2u: goto P_0c0988f2;
case 0x0c0988f4u: goto P_0c0988f4;
case 0x0c0988f6u: goto P_0c0988f6;
case 0x0c0988f8u: goto P_0c0988f8;
case 0x0c0988fau: goto P_0c0988fa;
case 0x0c0988fcu: goto P_0c0988fc;
case 0x0c0988feu: goto P_0c0988fe;
case 0x0c098900u: goto P_0c098900;
case 0x0c098902u: goto P_0c098902;
case 0x0c098904u: goto P_0c098904;
case 0x0c098906u: goto P_0c098906;
case 0x0c098908u: goto P_0c098908;
case 0x0c09890au: goto P_0c09890a;
case 0x0c09890cu: goto P_0c09890c;
case 0x0c09890eu: goto P_0c09890e;
case 0x0c098910u: goto P_0c098910;
case 0x0c098912u: goto P_0c098912;
case 0x0c098914u: goto P_0c098914;
case 0x0c098916u: goto P_0c098916;
case 0x0c098918u: goto P_0c098918;
case 0x0c09891au: goto P_0c09891a;
case 0x0c09891cu: goto P_0c09891c;
case 0x0c09891eu: goto P_0c09891e;
case 0x0c098920u: goto P_0c098920;
case 0x0c098922u: goto P_0c098922;
case 0x0c098924u: goto P_0c098924;
case 0x0c098926u: goto P_0c098926;
case 0x0c098928u: goto P_0c098928;
case 0x0c09892au: goto P_0c09892a;
case 0x0c09892cu: goto P_0c09892c;
case 0x0c09892eu: goto P_0c09892e;
case 0x0c098930u: goto P_0c098930;
case 0x0c098932u: goto P_0c098932;
case 0x0c098934u: goto P_0c098934;
case 0x0c098936u: goto P_0c098936;
case 0x0c098938u: goto P_0c098938;
case 0x0c09893au: goto P_0c09893a;
case 0x0c09893cu: goto P_0c09893c;
case 0x0c09893eu: goto P_0c09893e;
case 0x0c098940u: goto P_0c098940;
case 0x0c098942u: goto P_0c098942;
case 0x0c098944u: goto P_0c098944;
case 0x0c098946u: goto P_0c098946;
case 0x0c098948u: goto P_0c098948;
case 0x0c09894au: goto P_0c09894a;
case 0x0c09894cu: goto P_0c09894c;
case 0x0c09894eu: goto P_0c09894e;
case 0x0c098950u: goto P_0c098950;
case 0x0c098952u: goto P_0c098952;
case 0x0c098954u: goto P_0c098954;
case 0x0c098956u: goto P_0c098956;
case 0x0c098958u: goto P_0c098958;
case 0x0c09895au: goto P_0c09895a;
case 0x0c09895cu: goto P_0c09895c;
case 0x0c09895eu: goto P_0c09895e;
case 0x0c098960u: goto P_0c098960;
case 0x0c098962u: goto P_0c098962;
case 0x0c098964u: goto P_0c098964;
case 0x0c098966u: goto P_0c098966;
case 0x0c098968u: goto P_0c098968;
case 0x0c09896au: goto P_0c09896a;
case 0x0c09896cu: goto P_0c09896c;
case 0x0c09896eu: goto P_0c09896e;
case 0x0c098970u: goto P_0c098970;
case 0x0c098972u: goto P_0c098972;
case 0x0c098974u: goto P_0c098974;
case 0x0c098976u: goto P_0c098976;
case 0x0c098978u: goto P_0c098978;
case 0x0c09897au: goto P_0c09897a;
case 0x0c09897cu: goto P_0c09897c;
case 0x0c09897eu: goto P_0c09897e;
case 0x0c098980u: goto P_0c098980;
case 0x0c098982u: goto P_0c098982;
case 0x0c09efceu: goto P_0c09efce;
case 0x0c09efd0u: goto P_0c09efd0;
case 0x0c09efd2u: goto P_0c09efd2;
case 0x0c09efd4u: goto P_0c09efd4;
case 0x0c09efd6u: goto P_0c09efd6;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c098040: /* original 2fe6, guest PC 0x0c098040 */
if(!s->budget--) { s->failed_pc=0x0c098040u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098042;
P_0c098042: /* original 4f22, guest PC 0x0c098042 */
if(!s->budget--) { s->failed_pc=0x0c098042u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098044;
P_0c098044: /* original d31a, guest PC 0x0c098044 */
if(!s->budget--) { s->failed_pc=0x0c098044u; return 0; }
r[3]=read(ram,0x0c0980b0u,4);
goto P_0c098046;
P_0c098046: /* original d419, guest PC 0x0c098046 */
if(!s->budget--) { s->failed_pc=0x0c098046u; return 0; }
r[4]=read(ram,0x0c0980acu,4);
goto P_0c098048;
P_0c098048: /* original 430b, guest PC 0x0c098048 */
if(!s->budget--) { s->failed_pc=0x0c098048u; return 0; }
target=r[3];
r[16]=code_base|0x0c09804cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09804cu) { target=s->pc; goto dispatch; }
goto P_0c09804c;
P_0c09804a: /* original e500, guest PC 0x0c09804a */
if(!s->budget--) { s->failed_pc=0x0c09804au; return 0; }
r[5]=0x00000000u;
goto P_0c09804c;
P_0c09804c: /* original d21a, guest PC 0x0c09804c */
if(!s->budget--) { s->failed_pc=0x0c09804cu; return 0; }
r[2]=read(ram,0x0c0980b8u,4);
goto P_0c09804e;
P_0c09804e: /* original de19, guest PC 0x0c09804e */
if(!s->budget--) { s->failed_pc=0x0c09804eu; return 0; }
r[14]=read(ram,0x0c0980b4u,4);
goto P_0c098050;
P_0c098050: /* original 420b, guest PC 0x0c098050 */
if(!s->budget--) { s->failed_pc=0x0c098050u; return 0; }
target=r[2];
r[16]=code_base|0x0c098054u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098054u) { target=s->pc; goto dispatch; }
goto P_0c098054;
P_0c098052: /* original 54e4, guest PC 0x0c098052 */
if(!s->budget--) { s->failed_pc=0x0c098052u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098054;
P_0c098054: /* original d318, guest PC 0x0c098054 */
if(!s->budget--) { s->failed_pc=0x0c098054u; return 0; }
r[3]=read(ram,0x0c0980b8u,4);
goto P_0c098056;
P_0c098056: /* original 430b, guest PC 0x0c098056 */
if(!s->budget--) { s->failed_pc=0x0c098056u; return 0; }
target=r[3];
r[16]=code_base|0x0c09805au;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09805au) { target=s->pc; goto dispatch; }
goto P_0c09805a;
P_0c098058: /* original 54e5, guest PC 0x0c098058 */
if(!s->budget--) { s->failed_pc=0x0c098058u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09805a;
P_0c09805a: /* original d218, guest PC 0x0c09805a */
if(!s->budget--) { s->failed_pc=0x0c09805au; return 0; }
r[2]=read(ram,0x0c0980bcu,4);
goto P_0c09805c;
P_0c09805c: /* original 420b, guest PC 0x0c09805c */
if(!s->budget--) { s->failed_pc=0x0c09805cu; return 0; }
target=r[2];
r[16]=code_base|0x0c098060u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098060u) { target=s->pc; goto dispatch; }
goto P_0c098060;
P_0c09805e: /* original 54e4, guest PC 0x0c09805e */
if(!s->budget--) { s->failed_pc=0x0c09805eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098060;
P_0c098060: /* original d316, guest PC 0x0c098060 */
if(!s->budget--) { s->failed_pc=0x0c098060u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098062;
P_0c098062: /* original 430b, guest PC 0x0c098062 */
if(!s->budget--) { s->failed_pc=0x0c098062u; return 0; }
target=r[3];
r[16]=code_base|0x0c098066u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098066u) { target=s->pc; goto dispatch; }
goto P_0c098066;
P_0c098064: /* original 54e5, guest PC 0x0c098064 */
if(!s->budget--) { s->failed_pc=0x0c098064u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c098066;
P_0c098066: /* original d315, guest PC 0x0c098066 */
if(!s->budget--) { s->failed_pc=0x0c098066u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098068;
P_0c098068: /* original e048, guest PC 0x0c098068 */
if(!s->budget--) { s->failed_pc=0x0c098068u; return 0; }
r[0]=0x00000048u;
goto P_0c09806a;
P_0c09806a: /* original 430b, guest PC 0x0c09806a */
if(!s->budget--) { s->failed_pc=0x0c09806au; return 0; }
target=r[3];
r[16]=code_base|0x0c09806eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09806eu) { target=s->pc; goto dispatch; }
goto P_0c09806e;
P_0c09806c: /* original 04ee, guest PC 0x0c09806c */
if(!s->budget--) { s->failed_pc=0x0c09806cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09806e;
P_0c09806e: /* original d313, guest PC 0x0c09806e */
if(!s->budget--) { s->failed_pc=0x0c09806eu; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098070;
P_0c098070: /* original e05c, guest PC 0x0c098070 */
if(!s->budget--) { s->failed_pc=0x0c098070u; return 0; }
r[0]=0x0000005cu;
goto P_0c098072;
P_0c098072: /* original 430b, guest PC 0x0c098072 */
if(!s->budget--) { s->failed_pc=0x0c098072u; return 0; }
target=r[3];
r[16]=code_base|0x0c098076u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098076u) { target=s->pc; goto dispatch; }
goto P_0c098076;
P_0c098074: /* original 04ee, guest PC 0x0c098074 */
if(!s->budget--) { s->failed_pc=0x0c098074u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098076;
P_0c098076: /* original d311, guest PC 0x0c098076 */
if(!s->budget--) { s->failed_pc=0x0c098076u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098078;
P_0c098078: /* original e060, guest PC 0x0c098078 */
if(!s->budget--) { s->failed_pc=0x0c098078u; return 0; }
r[0]=0x00000060u;
goto P_0c09807a;
P_0c09807a: /* original 430b, guest PC 0x0c09807a */
if(!s->budget--) { s->failed_pc=0x0c09807au; return 0; }
target=r[3];
r[16]=code_base|0x0c09807eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09807eu) { target=s->pc; goto dispatch; }
goto P_0c09807e;
P_0c09807c: /* original 04ee, guest PC 0x0c09807c */
if(!s->budget--) { s->failed_pc=0x0c09807cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09807e;
P_0c09807e: /* original 4f26, guest PC 0x0c09807e */
if(!s->budget--) { s->failed_pc=0x0c09807eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098080;
P_0c098080: /* original e064, guest PC 0x0c098080 */
if(!s->budget--) { s->failed_pc=0x0c098080u; return 0; }
r[0]=0x00000064u;
goto P_0c098082;
P_0c098082: /* original d30e, guest PC 0x0c098082 */
if(!s->budget--) { s->failed_pc=0x0c098082u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098084;
P_0c098084: /* original 04ee, guest PC 0x0c098084 */
if(!s->budget--) { s->failed_pc=0x0c098084u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098086;
P_0c098086: /* original 432b, guest PC 0x0c098086 */
if(!s->budget--) { s->failed_pc=0x0c098086u; return 0; }
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
P_0c098088: /* original 6ef6, guest PC 0x0c098088 */
if(!s->budget--) { s->failed_pc=0x0c098088u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09808au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09808au; return 0; } return 1;
P_0c09845c: /* original 2fe6, guest PC 0x0c09845c */
if(!s->budget--) { s->failed_pc=0x0c09845cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09845e;
P_0c09845e: /* original e600, guest PC 0x0c09845e */
if(!s->budget--) { s->failed_pc=0x0c09845eu; return 0; }
r[6]=0x00000000u;
goto P_0c098460;
P_0c098460: /* original 2fd6, guest PC 0x0c098460 */
if(!s->budget--) { s->failed_pc=0x0c098460u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098462;
P_0c098462: /* original 6563, guest PC 0x0c098462 */
if(!s->budget--) { s->failed_pc=0x0c098462u; return 0; }
r[5]=r[6];
goto P_0c098464;
P_0c098464: /* original 2fc6, guest PC 0x0c098464 */
if(!s->budget--) { s->failed_pc=0x0c098464u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098466;
P_0c098466: /* original 2fb6, guest PC 0x0c098466 */
if(!s->budget--) { s->failed_pc=0x0c098466u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098468;
P_0c098468: /* original fffb, guest PC 0x0c098468 */
if(!s->budget--) { s->failed_pc=0x0c098468u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09846a;
P_0c09846a: /* original 4f22, guest PC 0x0c09846a */
if(!s->budget--) { s->failed_pc=0x0c09846au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09846c;
P_0c09846c: /* original d33c, guest PC 0x0c09846c */
if(!s->budget--) { s->failed_pc=0x0c09846cu; return 0; }
r[3]=read(ram,0x0c098560u,4);
goto P_0c09846e;
P_0c09846e: /* original de3a, guest PC 0x0c09846e */
if(!s->budget--) { s->failed_pc=0x0c09846eu; return 0; }
r[14]=read(ram,0x0c098558u,4);
goto P_0c098470;
P_0c098470: /* original dd3a, guest PC 0x0c098470 */
if(!s->budget--) { s->failed_pc=0x0c098470u; return 0; }
r[13]=read(ram,0x0c09855cu,4);
goto P_0c098472;
P_0c098472: /* original 430b, guest PC 0x0c098472 */
if(!s->budget--) { s->failed_pc=0x0c098472u; return 0; }
target=r[3];
r[16]=code_base|0x0c098476u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098476u) { target=s->pc; goto dispatch; }
goto P_0c098476;
P_0c098474: /* original 6463, guest PC 0x0c098474 */
if(!s->budget--) { s->failed_pc=0x0c098474u; return 0; }
r[4]=r[6];
goto P_0c098476;
P_0c098476: /* original e600, guest PC 0x0c098476 */
if(!s->budget--) { s->failed_pc=0x0c098476u; return 0; }
r[6]=0x00000000u;
goto P_0c098478;
P_0c098478: /* original d23a, guest PC 0x0c098478 */
if(!s->budget--) { s->failed_pc=0x0c098478u; return 0; }
r[2]=read(ram,0x0c098564u,4);
goto P_0c09847a;
P_0c09847a: /* original ff8d, guest PC 0x0c09847a */
if(!s->budget--) { s->failed_pc=0x0c09847au; return 0; }
fr[15]=0;
goto P_0c09847c;
P_0c09847c: /* original 6563, guest PC 0x0c09847c */
if(!s->budget--) { s->failed_pc=0x0c09847cu; return 0; }
r[5]=r[6];
goto P_0c09847e;
P_0c09847e: /* original f5fc, guest PC 0x0c09847e */
if(!s->budget--) { s->failed_pc=0x0c09847eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098480;
P_0c098480: /* original f4fc, guest PC 0x0c098480 */
if(!s->budget--) { s->failed_pc=0x0c098480u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098482;
P_0c098482: /* original 420b, guest PC 0x0c098482 */
if(!s->budget--) { s->failed_pc=0x0c098482u; return 0; }
target=r[2];
r[16]=code_base|0x0c098486u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098486u) { target=s->pc; goto dispatch; }
goto P_0c098486;
P_0c098484: /* original 6463, guest PC 0x0c098484 */
if(!s->budget--) { s->failed_pc=0x0c098484u; return 0; }
r[4]=r[6];
goto P_0c098486;
P_0c098486: /* original d338, guest PC 0x0c098486 */
if(!s->budget--) { s->failed_pc=0x0c098486u; return 0; }
r[3]=read(ram,0x0c098568u,4);
goto P_0c098488;
P_0c098488: /* original 430b, guest PC 0x0c098488 */
if(!s->budget--) { s->failed_pc=0x0c098488u; return 0; }
target=r[3];
r[16]=code_base|0x0c09848cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09848cu) { target=s->pc; goto dispatch; }
goto P_0c09848c;
P_0c09848a: /* original 0009, guest PC 0x0c09848a */
if(!s->budget--) { s->failed_pc=0x0c09848au; return 0; }
goto P_0c09848c;
P_0c09848c: /* original bdd8, guest PC 0x0c09848c */
if(!s->budget--) { s->failed_pc=0x0c09848cu; return 0; }
target=code_base|0x0c098040u; r[16]=code_base|0x0c098490u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098490u) { target=s->pc; goto dispatch; }
goto P_0c098490;
P_0c09848e: /* original 0009, guest PC 0x0c09848e */
if(!s->budget--) { s->failed_pc=0x0c09848eu; return 0; }
goto P_0c098490;
P_0c098490: /* original 905c, guest PC 0x0c098490 */
if(!s->budget--) { s->failed_pc=0x0c098490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09854cu,2);
goto P_0c098492;
P_0c098492: /* original e201, guest PC 0x0c098492 */
if(!s->budget--) { s->failed_pc=0x0c098492u; return 0; }
r[2]=0x00000001u;
goto P_0c098494;
P_0c098494: /* original 53e5, guest PC 0x0c098494 */
if(!s->budget--) { s->failed_pc=0x0c098494u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c098496;
P_0c098496: /* original 0e36, guest PC 0x0c098496 */
if(!s->budget--) { s->failed_pc=0x0c098496u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c098498;
P_0c098498: /* original e01b, guest PC 0x0c098498 */
if(!s->budget--) { s->failed_pc=0x0c098498u; return 0; }
r[0]=0x0000001bu;
goto P_0c09849a;
P_0c09849a: /* original 1d23, guest PC 0x0c09849a */
if(!s->budget--) { s->failed_pc=0x0c09849au; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c09849c;
P_0c09849c: /* original e20d, guest PC 0x0c09849c */
if(!s->budget--) { s->failed_pc=0x0c09849cu; return 0; }
r[2]=0x0000000du;
goto P_0c09849e;
P_0c09849e: /* original 9356, guest PC 0x0c09849e */
if(!s->budget--) { s->failed_pc=0x0c09849eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09854eu,2);
goto P_0c0984a0;
P_0c0984a0: /* original 04ec, guest PC 0x0c0984a0 */
if(!s->budget--) { s->failed_pc=0x0c0984a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0984a2;
P_0c0984a2: /* original e01a, guest PC 0x0c0984a2 */
if(!s->budget--) { s->failed_pc=0x0c0984a2u; return 0; }
r[0]=0x0000001au;
goto P_0c0984a4;
P_0c0984a4: /* original 33ec, guest PC 0x0c0984a4 */
if(!s->budget--) { s->failed_pc=0x0c0984a4u; return 0; }
r[3]+=r[14];
goto P_0c0984a6;
P_0c0984a6: /* original 05ec, guest PC 0x0c0984a6 */
if(!s->budget--) { s->failed_pc=0x0c0984a6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0984a8;
P_0c0984a8: /* original 644c, guest PC 0x0c0984a8 */
if(!s->budget--) { s->failed_pc=0x0c0984a8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0984aa;
P_0c0984aa: /* original dc30, guest PC 0x0c0984aa */
if(!s->budget--) { s->failed_pc=0x0c0984aau; return 0; }
r[12]=read(ram,0x0c09856cu,4);
goto P_0c0984ac;
P_0c0984ac: /* original 343c, guest PC 0x0c0984ac */
if(!s->budget--) { s->failed_pc=0x0c0984acu; return 0; }
r[4]+=r[3];
goto P_0c0984ae;
P_0c0984ae: /* original 934f, guest PC 0x0c0984ae */
if(!s->budget--) { s->failed_pc=0x0c0984aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098550u,2);
goto P_0c0984b0;
P_0c0984b0: /* original 655c, guest PC 0x0c0984b0 */
if(!s->budget--) { s->failed_pc=0x0c0984b0u; return 0; }
r[5]=r[5]&255u;
goto P_0c0984b2;
P_0c0984b2: /* original 6440, guest PC 0x0c0984b2 */
if(!s->budget--) { s->failed_pc=0x0c0984b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0984b4;
P_0c0984b4: /* original 33ec, guest PC 0x0c0984b4 */
if(!s->budget--) { s->failed_pc=0x0c0984b4u; return 0; }
r[3]+=r[14];
goto P_0c0984b6;
P_0c0984b6: /* original 56c4, guest PC 0x0c0984b6 */
if(!s->budget--) { s->failed_pc=0x0c0984b6u; return 0; }
r[6]=read(ram,r[12]+16,4);
goto P_0c0984b8;
P_0c0984b8: /* original 353c, guest PC 0x0c0984b8 */
if(!s->budget--) { s->failed_pc=0x0c0984b8u; return 0; }
r[5]+=r[3];
goto P_0c0984ba;
P_0c0984ba: /* original 5bc5, guest PC 0x0c0984ba */
if(!s->budget--) { s->failed_pc=0x0c0984bau; return 0; }
r[11]=read(ram,r[12]+20,4);
goto P_0c0984bc;
P_0c0984bc: /* original 6550, guest PC 0x0c0984bc */
if(!s->budget--) { s->failed_pc=0x0c0984bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0984be;
P_0c0984be: /* original 644c, guest PC 0x0c0984be */
if(!s->budget--) { s->failed_pc=0x0c0984beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0984c0;
P_0c0984c0: /* original 3423, guest PC 0x0c0984c0 */
if(!s->budget--) { s->failed_pc=0x0c0984c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0984c2;
P_0c0984c2: /* original 6143, guest PC 0x0c0984c2 */
if(!s->budget--) { s->failed_pc=0x0c0984c2u; return 0; }
r[1]=r[4];
goto P_0c0984c4;
P_0c0984c4: /* original 655c, guest PC 0x0c0984c4 */
if(!s->budget--) { s->failed_pc=0x0c0984c4u; return 0; }
r[5]=r[5]&255u;
goto P_0c0984c6;
P_0c0984c6: /* original 8f02, guest PC 0x0c0984c6 */
if(!s->budget--) { s->failed_pc=0x0c0984c6u; return 0; }
cond=r[17]&1u;
r[7]=r[5];
if(!cond) { goto P_0c0984ce; }
goto P_0c0984ca;
P_0c0984c8: /* original 6753, guest PC 0x0c0984c8 */
if(!s->budget--) { s->failed_pc=0x0c0984c8u; return 0; }
r[7]=r[5];
goto P_0c0984ca;
P_0c0984ca: /* original 6143, guest PC 0x0c0984ca */
if(!s->budget--) { s->failed_pc=0x0c0984cau; return 0; }
r[1]=r[4];
goto P_0c0984cc;
P_0c0984cc: /* original 71f3, guest PC 0x0c0984cc */
if(!s->budget--) { s->failed_pc=0x0c0984ccu; return 0; }
r[1]+=0xfffffff3u;
goto P_0c0984ce;
P_0c0984ce: /* original e20d, guest PC 0x0c0984ce */
if(!s->budget--) { s->failed_pc=0x0c0984ceu; return 0; }
r[2]=0x0000000du;
goto P_0c0984d0;
P_0c0984d0: /* original 3523, guest PC 0x0c0984d0 */
if(!s->budget--) { s->failed_pc=0x0c0984d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[2])!=0);
goto P_0c0984d2;
P_0c0984d2: /* original 8f02, guest PC 0x0c0984d2 */
if(!s->budget--) { s->failed_pc=0x0c0984d2u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0984da; }
goto P_0c0984d6;
P_0c0984d4: /* original e061, guest PC 0x0c0984d4 */
if(!s->budget--) { s->failed_pc=0x0c0984d4u; return 0; }
r[0]=0x00000061u;
goto P_0c0984d6;
P_0c0984d6: /* original 6753, guest PC 0x0c0984d6 */
if(!s->budget--) { s->failed_pc=0x0c0984d6u; return 0; }
r[7]=r[5];
goto P_0c0984d8;
P_0c0984d8: /* original 77f3, guest PC 0x0c0984d8 */
if(!s->budget--) { s->failed_pc=0x0c0984d8u; return 0; }
r[7]+=0xfffffff3u;
goto P_0c0984da;
P_0c0984da: /* original 0614, guest PC 0x0c0984da */
if(!s->budget--) { s->failed_pc=0x0c0984dau; return 0; }
write(ram,r[6]+r[0],r[1],1);
goto P_0c0984dc;
P_0c0984dc: /* original 0b74, guest PC 0x0c0984dc */
if(!s->budget--) { s->failed_pc=0x0c0984dcu; return 0; }
write(ram,r[11]+r[0],r[7],1);
goto P_0c0984de;
P_0c0984de: /* original e060, guest PC 0x0c0984de */
if(!s->budget--) { s->failed_pc=0x0c0984deu; return 0; }
r[0]=0x00000060u;
goto P_0c0984e0;
P_0c0984e0: /* original 0644, guest PC 0x0c0984e0 */
if(!s->budget--) { s->failed_pc=0x0c0984e0u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0984e2;
P_0c0984e2: /* original 0b54, guest PC 0x0c0984e2 */
if(!s->budget--) { s->failed_pc=0x0c0984e2u; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c0984e4;
P_0c0984e4: /* original 9035, guest PC 0x0c0984e4 */
if(!s->budget--) { s->failed_pc=0x0c0984e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098552u,2);
goto P_0c0984e6;
P_0c0984e6: /* original 04ee, guest PC 0x0c0984e6 */
if(!s->budget--) { s->failed_pc=0x0c0984e6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0984e8;
P_0c0984e8: /* original e061, guest PC 0x0c0984e8 */
if(!s->budget--) { s->failed_pc=0x0c0984e8u; return 0; }
r[0]=0x00000061u;
goto P_0c0984ea;
P_0c0984ea: /* original 004c, guest PC 0x0c0984ea */
if(!s->budget--) { s->failed_pc=0x0c0984eau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0984ec;
P_0c0984ec: /* original 600c, guest PC 0x0c0984ec */
if(!s->budget--) { s->failed_pc=0x0c0984ecu; return 0; }
r[0]=r[0]&255u;
goto P_0c0984ee;
P_0c0984ee: /* original 8808, guest PC 0x0c0984ee */
if(!s->budget--) { s->failed_pc=0x0c0984eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0984f0;
P_0c0984f0: /* original 8f01, guest PC 0x0c0984f0 */
if(!s->budget--) { s->failed_pc=0x0c0984f0u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0984f6; }
goto P_0c0984f4;
P_0c0984f2: /* original e500, guest PC 0x0c0984f2 */
if(!s->budget--) { s->failed_pc=0x0c0984f2u; return 0; }
r[5]=0x00000000u;
goto P_0c0984f4;
P_0c0984f4: /* original e505, guest PC 0x0c0984f4 */
if(!s->budget--) { s->failed_pc=0x0c0984f4u; return 0; }
r[5]=0x00000005u;
goto P_0c0984f6;
P_0c0984f6: /* original d31e, guest PC 0x0c0984f6 */
if(!s->budget--) { s->failed_pc=0x0c0984f6u; return 0; }
r[3]=read(ram,0x0c098570u,4);
goto P_0c0984f8;
P_0c0984f8: /* original 902c, guest PC 0x0c0984f8 */
if(!s->budget--) { s->failed_pc=0x0c0984f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098554u,2);
goto P_0c0984fa;
P_0c0984fa: /* original 430b, guest PC 0x0c0984fa */
if(!s->budget--) { s->failed_pc=0x0c0984fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0984feu;
write(ram,r[4]+r[0],r[5],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0984feu) { target=s->pc; goto dispatch; }
goto P_0c0984fe;
P_0c0984fc: /* original 0454, guest PC 0x0c0984fc */
if(!s->budget--) { s->failed_pc=0x0c0984fcu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0984fe;
P_0c0984fe: /* original e010, guest PC 0x0c0984fe */
if(!s->budget--) { s->failed_pc=0x0c0984feu; return 0; }
r[0]=0x00000010u;
goto P_0c098500;
P_0c098500: /* original e215, guest PC 0x0c098500 */
if(!s->budget--) { s->failed_pc=0x0c098500u; return 0; }
r[2]=0x00000015u;
goto P_0c098502;
P_0c098502: /* original 0d24, guest PC 0x0c098502 */
if(!s->budget--) { s->failed_pc=0x0c098502u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c098504;
P_0c098504: /* original 9327, guest PC 0x0c098504 */
if(!s->budget--) { s->failed_pc=0x0c098504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098556u,2);
goto P_0c098506;
P_0c098506: /* original 1d33, guest PC 0x0c098506 */
if(!s->budget--) { s->failed_pc=0x0c098506u; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c098508;
P_0c098508: /* original 84db, guest PC 0x0c098508 */
if(!s->budget--) { s->failed_pc=0x0c098508u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c09850a;
P_0c09850a: /* original 7001, guest PC 0x0c09850a */
if(!s->budget--) { s->failed_pc=0x0c09850au; return 0; }
r[0]+=0x00000001u;
goto P_0c09850c;
P_0c09850c: /* original 80db, guest PC 0x0c09850c */
if(!s->budget--) { s->failed_pc=0x0c09850cu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09850e;
P_0c09850e: /* original d319, guest PC 0x0c09850e */
if(!s->budget--) { s->failed_pc=0x0c09850eu; return 0; }
r[3]=read(ram,0x0c098574u,4);
goto P_0c098510;
P_0c098510: /* original 430b, guest PC 0x0c098510 */
if(!s->budget--) { s->failed_pc=0x0c098510u; return 0; }
target=r[3];
r[16]=code_base|0x0c098514u;
r[4]=read(ram,r[12]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098514u) { target=s->pc; goto dispatch; }
goto P_0c098514;
P_0c098512: /* original 54c8, guest PC 0x0c098512 */
if(!s->budget--) { s->failed_pc=0x0c098512u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c098514;
P_0c098514: /* original d317, guest PC 0x0c098514 */
if(!s->budget--) { s->failed_pc=0x0c098514u; return 0; }
r[3]=read(ram,0x0c098574u,4);
goto P_0c098516;
P_0c098516: /* original e044, guest PC 0x0c098516 */
if(!s->budget--) { s->failed_pc=0x0c098516u; return 0; }
r[0]=0x00000044u;
goto P_0c098518;
P_0c098518: /* original 430b, guest PC 0x0c098518 */
if(!s->budget--) { s->failed_pc=0x0c098518u; return 0; }
target=r[3];
r[16]=code_base|0x0c09851cu;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09851cu) { target=s->pc; goto dispatch; }
goto P_0c09851c;
P_0c09851a: /* original 04ce, guest PC 0x0c09851a */
if(!s->budget--) { s->failed_pc=0x0c09851au; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c09851c;
P_0c09851c: /* original d216, guest PC 0x0c09851c */
if(!s->budget--) { s->failed_pc=0x0c09851cu; return 0; }
r[2]=read(ram,0x0c098578u,4);
goto P_0c09851e;
P_0c09851e: /* original 420b, guest PC 0x0c09851e */
if(!s->budget--) { s->failed_pc=0x0c09851eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098522u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098522u) { target=s->pc; goto dispatch; }
goto P_0c098522;
P_0c098520: /* original 0009, guest PC 0x0c098520 */
if(!s->budget--) { s->failed_pc=0x0c098520u; return 0; }
goto P_0c098522;
P_0c098522: /* original d316, guest PC 0x0c098522 */
if(!s->budget--) { s->failed_pc=0x0c098522u; return 0; }
r[3]=read(ram,0x0c09857cu,4);
goto P_0c098524;
P_0c098524: /* original e500, guest PC 0x0c098524 */
if(!s->budget--) { s->failed_pc=0x0c098524u; return 0; }
r[5]=0x00000000u;
goto P_0c098526;
P_0c098526: /* original f4fc, guest PC 0x0c098526 */
if(!s->budget--) { s->failed_pc=0x0c098526u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098528;
P_0c098528: /* original f5fc, guest PC 0x0c098528 */
if(!s->budget--) { s->failed_pc=0x0c098528u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09852a;
P_0c09852a: /* original f6fc, guest PC 0x0c09852a */
if(!s->budget--) { s->failed_pc=0x0c09852au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09852c;
P_0c09852c: /* original 430b, guest PC 0x0c09852c */
if(!s->budget--) { s->failed_pc=0x0c09852cu; return 0; }
target=r[3];
r[16]=code_base|0x0c098530u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098530u) { target=s->pc; goto dispatch; }
goto P_0c098530;
P_0c09852e: /* original 6453, guest PC 0x0c09852e */
if(!s->budget--) { s->failed_pc=0x0c09852eu; return 0; }
r[4]=r[5];
goto P_0c098530;
P_0c098530: /* original d212, guest PC 0x0c098530 */
if(!s->budget--) { s->failed_pc=0x0c098530u; return 0; }
r[2]=read(ram,0x0c09857cu,4);
goto P_0c098532;
P_0c098532: /* original e500, guest PC 0x0c098532 */
if(!s->budget--) { s->failed_pc=0x0c098532u; return 0; }
r[5]=0x00000000u;
goto P_0c098534;
P_0c098534: /* original f4fc, guest PC 0x0c098534 */
if(!s->budget--) { s->failed_pc=0x0c098534u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098536;
P_0c098536: /* original f5fc, guest PC 0x0c098536 */
if(!s->budget--) { s->failed_pc=0x0c098536u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098538;
P_0c098538: /* original f6fc, guest PC 0x0c098538 */
if(!s->budget--) { s->failed_pc=0x0c098538u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09853a;
P_0c09853a: /* original 420b, guest PC 0x0c09853a */
if(!s->budget--) { s->failed_pc=0x0c09853au; return 0; }
target=r[2];
r[16]=code_base|0x0c09853eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09853eu) { target=s->pc; goto dispatch; }
goto P_0c09853e;
P_0c09853c: /* original e401, guest PC 0x0c09853c */
if(!s->budget--) { s->failed_pc=0x0c09853cu; return 0; }
r[4]=0x00000001u;
goto P_0c09853e;
P_0c09853e: /* original 4f26, guest PC 0x0c09853e */
if(!s->budget--) { s->failed_pc=0x0c09853eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098540;
P_0c098540: /* original fff9, guest PC 0x0c098540 */
if(!s->budget--) { s->failed_pc=0x0c098540u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c098542;
P_0c098542: /* original 6bf6, guest PC 0x0c098542 */
if(!s->budget--) { s->failed_pc=0x0c098542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c098544;
P_0c098544: /* original 6cf6, guest PC 0x0c098544 */
if(!s->budget--) { s->failed_pc=0x0c098544u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c098546;
P_0c098546: /* original 6df6, guest PC 0x0c098546 */
if(!s->budget--) { s->failed_pc=0x0c098546u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098548;
P_0c098548: /* original ad54, guest PC 0x0c098548 */
if(!s->budget--) { s->failed_pc=0x0c098548u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097ff4u,s,ram);
P_0c09854a: /* original 6ef6, guest PC 0x0c09854a */
if(!s->budget--) { s->failed_pc=0x0c09854au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09854cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09854cu; return 0; } return 1;
P_0c09877c: /* original 2fe6, guest PC 0x0c09877c */
if(!s->budget--) { s->failed_pc=0x0c09877cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09877e;
P_0c09877e: /* original 2fd6, guest PC 0x0c09877e */
if(!s->budget--) { s->failed_pc=0x0c09877eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098780;
P_0c098780: /* original 2fc6, guest PC 0x0c098780 */
if(!s->budget--) { s->failed_pc=0x0c098780u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098782;
P_0c098782: /* original 2fb6, guest PC 0x0c098782 */
if(!s->budget--) { s->failed_pc=0x0c098782u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098784;
P_0c098784: /* original 2fa6, guest PC 0x0c098784 */
if(!s->budget--) { s->failed_pc=0x0c098784u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098786;
P_0c098786: /* original fffb, guest PC 0x0c098786 */
if(!s->budget--) { s->failed_pc=0x0c098786u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c098788;
P_0c098788: /* original 4f22, guest PC 0x0c098788 */
if(!s->budget--) { s->failed_pc=0x0c098788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09878a;
P_0c09878a: /* original da35, guest PC 0x0c09878a */
if(!s->budget--) { s->failed_pc=0x0c09878au; return 0; }
r[10]=read(ram,0x0c098860u,4);
goto P_0c09878c;
P_0c09878c: /* original d335, guest PC 0x0c09878c */
if(!s->budget--) { s->failed_pc=0x0c09878cu; return 0; }
r[3]=read(ram,0x0c098864u,4);
goto P_0c09878e;
P_0c09878e: /* original dd32, guest PC 0x0c09878e */
if(!s->budget--) { s->failed_pc=0x0c09878eu; return 0; }
r[13]=read(ram,0x0c098858u,4);
goto P_0c098790;
P_0c098790: /* original dc32, guest PC 0x0c098790 */
if(!s->budget--) { s->failed_pc=0x0c098790u; return 0; }
r[12]=read(ram,0x0c09885cu,4);
goto P_0c098792;
P_0c098792: /* original 430b, guest PC 0x0c098792 */
if(!s->budget--) { s->failed_pc=0x0c098792u; return 0; }
target=r[3];
r[16]=code_base|0x0c098796u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098796u) { target=s->pc; goto dispatch; }
goto P_0c098796;
P_0c098794: /* original 0009, guest PC 0x0c098794 */
if(!s->budget--) { s->failed_pc=0x0c098794u; return 0; }
goto P_0c098796;
P_0c098796: /* original d234, guest PC 0x0c098796 */
if(!s->budget--) { s->failed_pc=0x0c098796u; return 0; }
r[2]=read(ram,0x0c098868u,4);
goto P_0c098798;
P_0c098798: /* original 420b, guest PC 0x0c098798 */
if(!s->budget--) { s->failed_pc=0x0c098798u; return 0; }
target=r[2];
r[16]=code_base|0x0c09879cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09879cu) { target=s->pc; goto dispatch; }
goto P_0c09879c;
P_0c09879a: /* original 0009, guest PC 0x0c09879a */
if(!s->budget--) { s->failed_pc=0x0c09879au; return 0; }
goto P_0c09879c;
P_0c09879c: /* original c733, guest PC 0x0c09879c */
if(!s->budget--) { s->failed_pc=0x0c09879cu; return 0; }
r[0]=code_base|0x0009886cu;
goto P_0c09879e;
P_0c09879e: /* original f308, guest PC 0x0c09879e */
if(!s->budget--) { s->failed_pc=0x0c09879eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0987a0;
P_0c0987a0: /* original e057, guest PC 0x0c0987a0 */
if(!s->budget--) { s->failed_pc=0x0c0987a0u; return 0; }
r[0]=0x00000057u;
goto P_0c0987a2;
P_0c0987a2: /* original eb00, guest PC 0x0c0987a2 */
if(!s->budget--) { s->failed_pc=0x0c0987a2u; return 0; }
r[11]=0x00000000u;
goto P_0c0987a4;
P_0c0987a4: /* original fd3a, guest PC 0x0c0987a4 */
if(!s->budget--) { s->failed_pc=0x0c0987a4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0987a6;
P_0c0987a6: /* original de32, guest PC 0x0c0987a6 */
if(!s->budget--) { s->failed_pc=0x0c0987a6u; return 0; }
r[14]=read(ram,0x0c098870u,4);
goto P_0c0987a8;
P_0c0987a8: /* original 53ea, guest PC 0x0c0987a8 */
if(!s->budget--) { s->failed_pc=0x0c0987a8u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c0987aa;
P_0c0987aa: /* original 03b4, guest PC 0x0c0987aa */
if(!s->budget--) { s->failed_pc=0x0c0987aau; return 0; }
write(ram,r[3]+r[0],r[11],1);
goto P_0c0987ac;
P_0c0987ac: /* original 53eb, guest PC 0x0c0987ac */
if(!s->budget--) { s->failed_pc=0x0c0987acu; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0987ae;
P_0c0987ae: /* original 03b4, guest PC 0x0c0987ae */
if(!s->budget--) { s->failed_pc=0x0c0987aeu; return 0; }
write(ram,r[3]+r[0],r[11],1);
goto P_0c0987b0;
P_0c0987b0: /* original 7049, guest PC 0x0c0987b0 */
if(!s->budget--) { s->failed_pc=0x0c0987b0u; return 0; }
r[0]+=0x00000049u;
goto P_0c0987b2;
P_0c0987b2: /* original 0cb6, guest PC 0x0c0987b2 */
if(!s->budget--) { s->failed_pc=0x0c0987b2u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c0987b4;
P_0c0987b4: /* original 904a, guest PC 0x0c0987b4 */
if(!s->budget--) { s->failed_pc=0x0c0987b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09884cu,2);
goto P_0c0987b6;
P_0c0987b6: /* original 0cb6, guest PC 0x0c0987b6 */
if(!s->budget--) { s->failed_pc=0x0c0987b6u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c0987b8;
P_0c0987b8: /* original 9349, guest PC 0x0c0987b8 */
if(!s->budget--) { s->failed_pc=0x0c0987b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09884eu,2);
goto P_0c0987ba;
P_0c0987ba: /* original 52d2, guest PC 0x0c0987ba */
if(!s->budget--) { s->failed_pc=0x0c0987bau; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0987bc;
P_0c0987bc: /* original 2239, guest PC 0x0c0987bc */
if(!s->budget--) { s->failed_pc=0x0c0987bcu; return 0; }
r[2]&=r[3];
goto P_0c0987be;
P_0c0987be: /* original 1d22, guest PC 0x0c0987be */
if(!s->budget--) { s->failed_pc=0x0c0987beu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0987c0;
P_0c0987c0: /* original d42c, guest PC 0x0c0987c0 */
if(!s->budget--) { s->failed_pc=0x0c0987c0u; return 0; }
r[4]=read(ram,0x0c098874u,4);
goto P_0c0987c2;
P_0c0987c2: /* original d12d, guest PC 0x0c0987c2 */
if(!s->budget--) { s->failed_pc=0x0c0987c2u; return 0; }
r[1]=read(ram,0x0c098878u,4);
goto P_0c0987c4;
P_0c0987c4: /* original 410b, guest PC 0x0c0987c4 */
if(!s->budget--) { s->failed_pc=0x0c0987c4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0987c8u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987c8u) { target=s->pc; goto dispatch; }
goto P_0c0987c8;
P_0c0987c6: /* original 65b3, guest PC 0x0c0987c6 */
if(!s->budget--) { s->failed_pc=0x0c0987c6u; return 0; }
r[5]=r[11];
goto P_0c0987c8;
P_0c0987c8: /* original d32c, guest PC 0x0c0987c8 */
if(!s->budget--) { s->failed_pc=0x0c0987c8u; return 0; }
r[3]=read(ram,0x0c09887cu,4);
goto P_0c0987ca;
P_0c0987ca: /* original 430b, guest PC 0x0c0987ca */
if(!s->budget--) { s->failed_pc=0x0c0987cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0987ceu;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987ceu) { target=s->pc; goto dispatch; }
goto P_0c0987ce;
P_0c0987cc: /* original 54e4, guest PC 0x0c0987cc */
if(!s->budget--) { s->failed_pc=0x0c0987ccu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0987ce;
P_0c0987ce: /* original d22b, guest PC 0x0c0987ce */
if(!s->budget--) { s->failed_pc=0x0c0987ceu; return 0; }
r[2]=read(ram,0x0c09887cu,4);
goto P_0c0987d0;
P_0c0987d0: /* original 420b, guest PC 0x0c0987d0 */
if(!s->budget--) { s->failed_pc=0x0c0987d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987d4u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987d4u) { target=s->pc; goto dispatch; }
goto P_0c0987d4;
P_0c0987d2: /* original 54e5, guest PC 0x0c0987d2 */
if(!s->budget--) { s->failed_pc=0x0c0987d2u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0987d4;
P_0c0987d4: /* original d32b, guest PC 0x0c0987d4 */
if(!s->budget--) { s->failed_pc=0x0c0987d4u; return 0; }
r[3]=read(ram,0x0c098884u,4);
goto P_0c0987d6;
P_0c0987d6: /* original d52a, guest PC 0x0c0987d6 */
if(!s->budget--) { s->failed_pc=0x0c0987d6u; return 0; }
r[5]=read(ram,0x0c098880u,4);
goto P_0c0987d8;
P_0c0987d8: /* original 430b, guest PC 0x0c0987d8 */
if(!s->budget--) { s->failed_pc=0x0c0987d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0987dcu;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987dcu) { target=s->pc; goto dispatch; }
goto P_0c0987dc;
P_0c0987da: /* original 54e6, guest PC 0x0c0987da */
if(!s->budget--) { s->failed_pc=0x0c0987dau; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0987dc;
P_0c0987dc: /* original d229, guest PC 0x0c0987dc */
if(!s->budget--) { s->failed_pc=0x0c0987dcu; return 0; }
r[2]=read(ram,0x0c098884u,4);
goto P_0c0987de;
P_0c0987de: /* original d52a, guest PC 0x0c0987de */
if(!s->budget--) { s->failed_pc=0x0c0987deu; return 0; }
r[5]=read(ram,0x0c098888u,4);
goto P_0c0987e0;
P_0c0987e0: /* original 420b, guest PC 0x0c0987e0 */
if(!s->budget--) { s->failed_pc=0x0c0987e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987e4u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987e4u) { target=s->pc; goto dispatch; }
goto P_0c0987e4;
P_0c0987e2: /* original 54e7, guest PC 0x0c0987e2 */
if(!s->budget--) { s->failed_pc=0x0c0987e2u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c0987e4;
P_0c0987e4: /* original d327, guest PC 0x0c0987e4 */
if(!s->budget--) { s->failed_pc=0x0c0987e4u; return 0; }
r[3]=read(ram,0x0c098884u,4);
goto P_0c0987e6;
P_0c0987e6: /* original d529, guest PC 0x0c0987e6 */
if(!s->budget--) { s->failed_pc=0x0c0987e6u; return 0; }
r[5]=read(ram,0x0c09888cu,4);
goto P_0c0987e8;
P_0c0987e8: /* original 430b, guest PC 0x0c0987e8 */
if(!s->budget--) { s->failed_pc=0x0c0987e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0987ecu;
r[4]=read(ram,r[14]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987ecu) { target=s->pc; goto dispatch; }
goto P_0c0987ec;
P_0c0987ea: /* original 54ed, guest PC 0x0c0987ea */
if(!s->budget--) { s->failed_pc=0x0c0987eau; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c0987ec;
P_0c0987ec: /* original d225, guest PC 0x0c0987ec */
if(!s->budget--) { s->failed_pc=0x0c0987ecu; return 0; }
r[2]=read(ram,0x0c098884u,4);
goto P_0c0987ee;
P_0c0987ee: /* original d528, guest PC 0x0c0987ee */
if(!s->budget--) { s->failed_pc=0x0c0987eeu; return 0; }
r[5]=read(ram,0x0c098890u,4);
goto P_0c0987f0;
P_0c0987f0: /* original 420b, guest PC 0x0c0987f0 */
if(!s->budget--) { s->failed_pc=0x0c0987f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987f4u;
r[4]=read(ram,r[14]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987f4u) { target=s->pc; goto dispatch; }
goto P_0c0987f4;
P_0c0987f2: /* original 54ee, guest PC 0x0c0987f2 */
if(!s->budget--) { s->failed_pc=0x0c0987f2u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c0987f4;
P_0c0987f4: /* original 902c, guest PC 0x0c0987f4 */
if(!s->budget--) { s->failed_pc=0x0c0987f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098850u,2);
goto P_0c0987f6;
P_0c0987f6: /* original d327, guest PC 0x0c0987f6 */
if(!s->budget--) { s->failed_pc=0x0c0987f6u; return 0; }
r[3]=read(ram,0x0c098894u,4);
goto P_0c0987f8;
P_0c0987f8: /* original 54ec, guest PC 0x0c0987f8 */
if(!s->budget--) { s->failed_pc=0x0c0987f8u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0987fa;
P_0c0987fa: /* original 0436, guest PC 0x0c0987fa */
if(!s->budget--) { s->failed_pc=0x0c0987fau; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0987fc;
P_0c0987fc: /* original 7098, guest PC 0x0c0987fc */
if(!s->budget--) { s->failed_pc=0x0c0987fcu; return 0; }
r[0]+=0xffffff98u;
goto P_0c0987fe;
P_0c0987fe: /* original 0cb4, guest PC 0x0c0987fe */
if(!s->budget--) { s->failed_pc=0x0c0987feu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c098800;
P_0c098800: /* original 9027, guest PC 0x0c098800 */
if(!s->budget--) { s->failed_pc=0x0c098800u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098852u,2);
goto P_0c098802;
P_0c098802: /* original 0db4, guest PC 0x0c098802 */
if(!s->budget--) { s->failed_pc=0x0c098802u; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c098804;
P_0c098804: /* original c725, guest PC 0x0c098804 */
if(!s->budget--) { s->failed_pc=0x0c098804u; return 0; }
r[0]=code_base|0x0009889cu;
goto P_0c098806;
P_0c098806: /* original f408, guest PC 0x0c098806 */
if(!s->budget--) { s->failed_pc=0x0c098806u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c098808;
P_0c098808: /* original d325, guest PC 0x0c098808 */
if(!s->budget--) { s->failed_pc=0x0c098808u; return 0; }
r[3]=read(ram,0x0c0988a0u,4);
goto P_0c09880a;
P_0c09880a: /* original ff8d, guest PC 0x0c09880a */
if(!s->budget--) { s->failed_pc=0x0c09880au; return 0; }
fr[15]=0;
goto P_0c09880c;
P_0c09880c: /* original d522, guest PC 0x0c09880c */
if(!s->budget--) { s->failed_pc=0x0c09880cu; return 0; }
r[5]=read(ram,0x0c098898u,4);
goto P_0c09880e;
P_0c09880e: /* original f6fc, guest PC 0x0c09880e */
if(!s->budget--) { s->failed_pc=0x0c09880eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c098810;
P_0c098810: /* original f5fc, guest PC 0x0c098810 */
if(!s->budget--) { s->failed_pc=0x0c098810u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098812;
P_0c098812: /* original 430b, guest PC 0x0c098812 */
if(!s->budget--) { s->failed_pc=0x0c098812u; return 0; }
target=r[3];
r[16]=code_base|0x0c098816u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098816u) { target=s->pc; goto dispatch; }
goto P_0c098816;
P_0c098814: /* original 64b3, guest PC 0x0c098814 */
if(!s->budget--) { s->failed_pc=0x0c098814u; return 0; }
r[4]=r[11];
goto P_0c098816;
P_0c098816: /* original d222, guest PC 0x0c098816 */
if(!s->budget--) { s->failed_pc=0x0c098816u; return 0; }
r[2]=read(ram,0x0c0988a0u,4);
goto P_0c098818;
P_0c098818: /* original 951c, guest PC 0x0c098818 */
if(!s->budget--) { s->failed_pc=0x0c098818u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098854u,2);
goto P_0c09881a;
P_0c09881a: /* original f49d, guest PC 0x0c09881a */
if(!s->budget--) { s->failed_pc=0x0c09881au; return 0; }
fr[4]=0x3f800000u;
goto P_0c09881c;
P_0c09881c: /* original f6fc, guest PC 0x0c09881c */
if(!s->budget--) { s->failed_pc=0x0c09881cu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09881e;
P_0c09881e: /* original f5fc, guest PC 0x0c09881e */
if(!s->budget--) { s->failed_pc=0x0c09881eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098820;
P_0c098820: /* original 420b, guest PC 0x0c098820 */
if(!s->budget--) { s->failed_pc=0x0c098820u; return 0; }
target=r[2];
r[16]=code_base|0x0c098824u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098824u) { target=s->pc; goto dispatch; }
goto P_0c098824;
P_0c098822: /* original e401, guest PC 0x0c098822 */
if(!s->budget--) { s->failed_pc=0x0c098822u; return 0; }
r[4]=0x00000001u;
goto P_0c098824;
P_0c098824: /* original 9017, guest PC 0x0c098824 */
if(!s->budget--) { s->failed_pc=0x0c098824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098856u,2);
goto P_0c098826;
P_0c098826: /* original e319, guest PC 0x0c098826 */
if(!s->budget--) { s->failed_pc=0x0c098826u; return 0; }
r[3]=0x00000019u;
goto P_0c098828;
P_0c098828: /* original 54e8, guest PC 0x0c098828 */
if(!s->budget--) { s->failed_pc=0x0c098828u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09882a;
P_0c09882a: /* original 04b4, guest PC 0x0c09882a */
if(!s->budget--) { s->failed_pc=0x0c09882au; return 0; }
write(ram,r[4]+r[0],r[11],1);
goto P_0c09882c;
P_0c09882c: /* original e010, guest PC 0x0c09882c */
if(!s->budget--) { s->failed_pc=0x0c09882cu; return 0; }
r[0]=0x00000010u;
goto P_0c09882e;
P_0c09882e: /* original 0c34, guest PC 0x0c09882e */
if(!s->budget--) { s->failed_pc=0x0c09882eu; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c098830;
P_0c098830: /* original d31c, guest PC 0x0c098830 */
if(!s->budget--) { s->failed_pc=0x0c098830u; return 0; }
r[3]=read(ram,0x0c0988a4u,4);
goto P_0c098832;
P_0c098832: /* original 430b, guest PC 0x0c098832 */
if(!s->budget--) { s->failed_pc=0x0c098832u; return 0; }
target=r[3];
r[16]=code_base|0x0c098836u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098836u) { target=s->pc; goto dispatch; }
goto P_0c098836;
P_0c098834: /* original 54e4, guest PC 0x0c098834 */
if(!s->budget--) { s->failed_pc=0x0c098834u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098836;
P_0c098836: /* original d21b, guest PC 0x0c098836 */
if(!s->budget--) { s->failed_pc=0x0c098836u; return 0; }
r[2]=read(ram,0x0c0988a4u,4);
goto P_0c098838;
P_0c098838: /* original 420b, guest PC 0x0c098838 */
if(!s->budget--) { s->failed_pc=0x0c098838u; return 0; }
target=r[2];
r[16]=code_base|0x0c09883cu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09883cu) { target=s->pc; goto dispatch; }
goto P_0c09883c;
P_0c09883a: /* original 54e5, guest PC 0x0c09883a */
if(!s->budget--) { s->failed_pc=0x0c09883au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09883c;
P_0c09883c: /* original 52d2, guest PC 0x0c09883c */
if(!s->budget--) { s->failed_pc=0x0c09883cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c09883e;
P_0c09883e: /* original d31b, guest PC 0x0c09883e */
if(!s->budget--) { s->failed_pc=0x0c09883eu; return 0; }
r[3]=read(ram,0x0c0988acu,4);
goto P_0c098840;
P_0c098840: /* original de19, guest PC 0x0c098840 */
if(!s->budget--) { s->failed_pc=0x0c098840u; return 0; }
r[14]=read(ram,0x0c0988a8u,4);
goto P_0c098842;
P_0c098842: /* original 2238, guest PC 0x0c098842 */
if(!s->budget--) { s->failed_pc=0x0c098842u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098844;
P_0c098844: /* original 8d34, guest PC 0x0c098844 */
if(!s->budget--) { s->failed_pc=0x0c098844u; return 0; }
cond=r[17]&1u;
r[11]=0x0000002fu;
if(cond) { goto P_0c0988b0; }
goto P_0c098848;
P_0c098846: /* original eb2f, guest PC 0x0c098846 */
if(!s->budget--) { s->failed_pc=0x0c098846u; return 0; }
r[11]=0x0000002fu;
goto P_0c098848;
P_0c098848: /* original a03a, guest PC 0x0c098848 */
if(!s->budget--) { s->failed_pc=0x0c098848u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0988c0;
P_0c09884a: /* original 54e3, guest PC 0x0c09884a */
if(!s->budget--) { s->failed_pc=0x0c09884au; return 0; }
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(0x0c09884cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09884cu; return 0; } return 1;
P_0c0988b0: /* original d145, guest PC 0x0c0988b0 */
if(!s->budget--) { s->failed_pc=0x0c0988b0u; return 0; }
r[1]=read(ram,0x0c0989c8u,4);
goto P_0c0988b2;
P_0c0988b2: /* original 64a3, guest PC 0x0c0988b2 */
if(!s->budget--) { s->failed_pc=0x0c0988b2u; return 0; }
r[4]=r[10];
goto P_0c0988b4;
P_0c0988b4: /* original 410b, guest PC 0x0c0988b4 */
if(!s->budget--) { s->failed_pc=0x0c0988b4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0988b8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988b8u) { target=s->pc; goto dispatch; }
goto P_0c0988b8;
P_0c0988b6: /* original 740a, guest PC 0x0c0988b6 */
if(!s->budget--) { s->failed_pc=0x0c0988b6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0988b8;
P_0c0988b8: /* original 600d, guest PC 0x0c0988b8 */
if(!s->budget--) { s->failed_pc=0x0c0988b8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0988ba;
P_0c0988ba: /* original 4008, guest PC 0x0c0988ba */
if(!s->budget--) { s->failed_pc=0x0c0988bau; return 0; }
r[0]<<=2;
goto P_0c0988bc;
P_0c0988bc: /* original 03ee, guest PC 0x0c0988bc */
if(!s->budget--) { s->failed_pc=0x0c0988bcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0988be;
P_0c0988be: /* original 6433, guest PC 0x0c0988be */
if(!s->budget--) { s->failed_pc=0x0c0988beu; return 0; }
r[4]=r[3];
goto P_0c0988c0;
P_0c0988c0: /* original 5ed2, guest PC 0x0c0988c0 */
if(!s->budget--) { s->failed_pc=0x0c0988c0u; return 0; }
r[14]=read(ram,r[13]+8,4);
goto P_0c0988c2;
P_0c0988c2: /* original 4408, guest PC 0x0c0988c2 */
if(!s->budget--) { s->failed_pc=0x0c0988c2u; return 0; }
r[4]<<=2;
goto P_0c0988c4;
P_0c0988c4: /* original d241, guest PC 0x0c0988c4 */
if(!s->budget--) { s->failed_pc=0x0c0988c4u; return 0; }
r[2]=read(ram,0x0c0989ccu,4);
goto P_0c0988c6;
P_0c0988c6: /* original 4408, guest PC 0x0c0988c6 */
if(!s->budget--) { s->failed_pc=0x0c0988c6u; return 0; }
r[4]<<=2;
goto P_0c0988c8;
P_0c0988c8: /* original 22e8, guest PC 0x0c0988c8 */
if(!s->budget--) { s->failed_pc=0x0c0988c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0988ca;
P_0c0988ca: /* original 8d0e, guest PC 0x0c0988ca */
if(!s->budget--) { s->failed_pc=0x0c0988cau; return 0; }
cond=r[17]&1u;
r[4]<<=2;
if(cond) { goto P_0c0988ea; }
goto P_0c0988ce;
P_0c0988cc: /* original 4408, guest PC 0x0c0988cc */
if(!s->budget--) { s->failed_pc=0x0c0988ccu; return 0; }
r[4]<<=2;
goto P_0c0988ce;
P_0c0988ce: /* original d33e, guest PC 0x0c0988ce */
if(!s->budget--) { s->failed_pc=0x0c0988ceu; return 0; }
r[3]=read(ram,0x0c0989c8u,4);
goto P_0c0988d0;
P_0c0988d0: /* original 64a3, guest PC 0x0c0988d0 */
if(!s->budget--) { s->failed_pc=0x0c0988d0u; return 0; }
r[4]=r[10];
goto P_0c0988d2;
P_0c0988d2: /* original eb36, guest PC 0x0c0988d2 */
if(!s->budget--) { s->failed_pc=0x0c0988d2u; return 0; }
r[11]=0x00000036u;
goto P_0c0988d4;
P_0c0988d4: /* original 430b, guest PC 0x0c0988d4 */
if(!s->budget--) { s->failed_pc=0x0c0988d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0988d8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988d8u) { target=s->pc; goto dispatch; }
goto P_0c0988d8;
P_0c0988d6: /* original 740a, guest PC 0x0c0988d6 */
if(!s->budget--) { s->failed_pc=0x0c0988d6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0988d8;
P_0c0988d8: /* original d13d, guest PC 0x0c0988d8 */
if(!s->budget--) { s->failed_pc=0x0c0988d8u; return 0; }
r[1]=read(ram,0x0c0989d0u,4);
goto P_0c0988da;
P_0c0988da: /* original 600d, guest PC 0x0c0988da */
if(!s->budget--) { s->failed_pc=0x0c0988dau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0988dc;
P_0c0988dc: /* original 4008, guest PC 0x0c0988dc */
if(!s->budget--) { s->failed_pc=0x0c0988dcu; return 0; }
r[0]<<=2;
goto P_0c0988de;
P_0c0988de: /* original 021e, guest PC 0x0c0988de */
if(!s->budget--) { s->failed_pc=0x0c0988deu; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0988e0;
P_0c0988e0: /* original 4221, guest PC 0x0c0988e0 */
if(!s->budget--) { s->failed_pc=0x0c0988e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0988e2;
P_0c0988e2: /* original 6423, guest PC 0x0c0988e2 */
if(!s->budget--) { s->failed_pc=0x0c0988e2u; return 0; }
r[4]=r[2];
goto P_0c0988e4;
P_0c0988e4: /* original 4408, guest PC 0x0c0988e4 */
if(!s->budget--) { s->failed_pc=0x0c0988e4u; return 0; }
r[4]<<=2;
goto P_0c0988e6;
P_0c0988e6: /* original 4408, guest PC 0x0c0988e6 */
if(!s->budget--) { s->failed_pc=0x0c0988e6u; return 0; }
r[4]<<=2;
goto P_0c0988e8;
P_0c0988e8: /* original 4408, guest PC 0x0c0988e8 */
if(!s->budget--) { s->failed_pc=0x0c0988e8u; return 0; }
r[4]<<=2;
goto P_0c0988ea;
P_0c0988ea: /* original e340, guest PC 0x0c0988ea */
if(!s->budget--) { s->failed_pc=0x0c0988eau; return 0; }
r[3]=0x00000040u;
goto P_0c0988ec;
P_0c0988ec: /* original 1d45, guest PC 0x0c0988ec */
if(!s->budget--) { s->failed_pc=0x0c0988ecu; return 0; }
write(ram,r[13]+20,r[4],4);
goto P_0c0988ee;
P_0c0988ee: /* original 1c33, guest PC 0x0c0988ee */
if(!s->budget--) { s->failed_pc=0x0c0988eeu; return 0; }
write(ram,r[12]+12,r[3],4);
goto P_0c0988f0;
P_0c0988f0: /* original d238, guest PC 0x0c0988f0 */
if(!s->budget--) { s->failed_pc=0x0c0988f0u; return 0; }
r[2]=read(ram,0x0c0989d4u,4);
goto P_0c0988f2;
P_0c0988f2: /* original 2e29, guest PC 0x0c0988f2 */
if(!s->budget--) { s->failed_pc=0x0c0988f2u; return 0; }
r[14]&=r[2];
goto P_0c0988f4;
P_0c0988f4: /* original 1de2, guest PC 0x0c0988f4 */
if(!s->budget--) { s->failed_pc=0x0c0988f4u; return 0; }
write(ram,r[13]+8,r[14],4);
goto P_0c0988f6;
P_0c0988f6: /* original d338, guest PC 0x0c0988f6 */
if(!s->budget--) { s->failed_pc=0x0c0988f6u; return 0; }
r[3]=read(ram,0x0c0989d8u,4);
goto P_0c0988f8;
P_0c0988f8: /* original 430b, guest PC 0x0c0988f8 */
if(!s->budget--) { s->failed_pc=0x0c0988f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0988fcu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988fcu) { target=s->pc; goto dispatch; }
goto P_0c0988fc;
P_0c0988fa: /* original 64b3, guest PC 0x0c0988fa */
if(!s->budget--) { s->failed_pc=0x0c0988fau; return 0; }
r[4]=r[11];
goto P_0c0988fc;
P_0c0988fc: /* original d237, guest PC 0x0c0988fc */
if(!s->budget--) { s->failed_pc=0x0c0988fcu; return 0; }
r[2]=read(ram,0x0c0989dcu,4);
goto P_0c0988fe;
P_0c0988fe: /* original 420b, guest PC 0x0c0988fe */
if(!s->budget--) { s->failed_pc=0x0c0988feu; return 0; }
target=r[2];
r[16]=code_base|0x0c098902u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098902u) { target=s->pc; goto dispatch; }
goto P_0c098902;
P_0c098900: /* original 0009, guest PC 0x0c098900 */
if(!s->budget--) { s->failed_pc=0x0c098900u; return 0; }
goto P_0c098902;
P_0c098902: /* original 4f26, guest PC 0x0c098902 */
if(!s->budget--) { s->failed_pc=0x0c098902u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098904;
P_0c098904: /* original 84cb, guest PC 0x0c098904 */
if(!s->budget--) { s->failed_pc=0x0c098904u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+11,1);
goto P_0c098906;
P_0c098906: /* original 7001, guest PC 0x0c098906 */
if(!s->budget--) { s->failed_pc=0x0c098906u; return 0; }
r[0]+=0x00000001u;
goto P_0c098908;
P_0c098908: /* original 80cb, guest PC 0x0c098908 */
if(!s->budget--) { s->failed_pc=0x0c098908u; return 0; }
write(ram,r[12]+11,r[0],1);
goto P_0c09890a;
P_0c09890a: /* original fff9, guest PC 0x0c09890a */
if(!s->budget--) { s->failed_pc=0x0c09890au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09890c;
P_0c09890c: /* original 6af6, guest PC 0x0c09890c */
if(!s->budget--) { s->failed_pc=0x0c09890cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09890e;
P_0c09890e: /* original 6bf6, guest PC 0x0c09890e */
if(!s->budget--) { s->failed_pc=0x0c09890eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c098910;
P_0c098910: /* original 6cf6, guest PC 0x0c098910 */
if(!s->budget--) { s->failed_pc=0x0c098910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c098912;
P_0c098912: /* original 6df6, guest PC 0x0c098912 */
if(!s->budget--) { s->failed_pc=0x0c098912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098914;
P_0c098914: /* original a000, guest PC 0x0c098914 */
if(!s->budget--) { s->failed_pc=0x0c098914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098918;
P_0c098916: /* original 6ef6, guest PC 0x0c098916 */
if(!s->budget--) { s->failed_pc=0x0c098916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098918;
P_0c098918: /* original 2fe6, guest PC 0x0c098918 */
if(!s->budget--) { s->failed_pc=0x0c098918u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891a;
P_0c09891a: /* original 2fd6, guest PC 0x0c09891a */
if(!s->budget--) { s->failed_pc=0x0c09891au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891c;
P_0c09891c: /* original dd31, guest PC 0x0c09891c */
if(!s->budget--) { s->failed_pc=0x0c09891cu; return 0; }
r[13]=read(ram,0x0c0989e4u,4);
goto P_0c09891e;
P_0c09891e: /* original d430, guest PC 0x0c09891e */
if(!s->budget--) { s->failed_pc=0x0c09891eu; return 0; }
r[4]=read(ram,0x0c0989e0u,4);
goto P_0c098920;
P_0c098920: /* original d331, guest PC 0x0c098920 */
if(!s->budget--) { s->failed_pc=0x0c098920u; return 0; }
r[3]=read(ram,0x0c0989e8u,4);
goto P_0c098922;
P_0c098922: /* original 5242, guest PC 0x0c098922 */
if(!s->budget--) { s->failed_pc=0x0c098922u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098924;
P_0c098924: /* original 4f22, guest PC 0x0c098924 */
if(!s->budget--) { s->failed_pc=0x0c098924u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098926;
P_0c098926: /* original 50d3, guest PC 0x0c098926 */
if(!s->budget--) { s->failed_pc=0x0c098926u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c098928;
P_0c098928: /* original 883e, guest PC 0x0c098928 */
if(!s->budget--) { s->failed_pc=0x0c098928u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000003eu)!=0);
goto P_0c09892a;
P_0c09892a: /* original 2238, guest PC 0x0c09892a */
if(!s->budget--) { s->failed_pc=0x0c09892au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09892c;
P_0c09892c: /* original 8d0a, guest PC 0x0c09892c */
if(!s->budget--) { s->failed_pc=0x0c09892cu; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c098944; }
goto P_0c098930;
P_0c09892e: /* original 6e03, guest PC 0x0c09892e */
if(!s->budget--) { s->failed_pc=0x0c09892eu; return 0; }
r[14]=r[0];
goto P_0c098930;
P_0c098930: /* original d02e, guest PC 0x0c098930 */
if(!s->budget--) { s->failed_pc=0x0c098930u; return 0; }
r[0]=read(ram,0x0c0989ecu,4);
goto P_0c098932;
P_0c098932: /* original e300, guest PC 0x0c098932 */
if(!s->budget--) { s->failed_pc=0x0c098932u; return 0; }
r[3]=0x00000000u;
goto P_0c098934;
P_0c098934: /* original d22e, guest PC 0x0c098934 */
if(!s->budget--) { s->failed_pc=0x0c098934u; return 0; }
r[2]=read(ram,0x0c0989f0u,4);
goto P_0c098936;
P_0c098936: /* original 6502, guest PC 0x0c098936 */
if(!s->budget--) { s->failed_pc=0x0c098936u; return 0; }
tmp=read(ram,r[0],4);
r[5]=tmp;
goto P_0c098938;
P_0c098938: /* original e01c, guest PC 0x0c098938 */
if(!s->budget--) { s->failed_pc=0x0c098938u; return 0; }
r[0]=0x0000001cu;
goto P_0c09893a;
P_0c09893a: /* original 6152, guest PC 0x0c09893a */
if(!s->budget--) { s->failed_pc=0x0c09893au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c09893c;
P_0c09893c: /* original 2129, guest PC 0x0c09893c */
if(!s->budget--) { s->failed_pc=0x0c09893cu; return 0; }
r[1]&=r[2];
goto P_0c09893e;
P_0c09893e: /* original 2512, guest PC 0x0c09893e */
if(!s->budget--) { s->failed_pc=0x0c09893eu; return 0; }
write(ram,r[5],r[1],4);
goto P_0c098940;
P_0c098940: /* original a017, guest PC 0x0c098940 */
if(!s->budget--) { s->failed_pc=0x0c098940u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098972;
P_0c098942: /* original 0434, guest PC 0x0c098942 */
if(!s->budget--) { s->failed_pc=0x0c098942u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098944;
P_0c098944: /* original 5242, guest PC 0x0c098944 */
if(!s->budget--) { s->failed_pc=0x0c098944u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098946;
P_0c098946: /* original d321, guest PC 0x0c098946 */
if(!s->budget--) { s->failed_pc=0x0c098946u; return 0; }
r[3]=read(ram,0x0c0989ccu,4);
goto P_0c098948;
P_0c098948: /* original 2238, guest PC 0x0c098948 */
if(!s->budget--) { s->failed_pc=0x0c098948u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09894a;
P_0c09894a: /* original 8b12, guest PC 0x0c09894a */
if(!s->budget--) { s->failed_pc=0x0c09894au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09894c;
P_0c09894c: /* original e01c, guest PC 0x0c09894c */
if(!s->budget--) { s->failed_pc=0x0c09894cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09894e;
P_0c09894e: /* original 044c, guest PC 0x0c09894e */
if(!s->budget--) { s->failed_pc=0x0c09894eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098950;
P_0c098950: /* original 644c, guest PC 0x0c098950 */
if(!s->budget--) { s->failed_pc=0x0c098950u; return 0; }
r[4]=r[4]&255u;
goto P_0c098952;
P_0c098952: /* original 4410, guest PC 0x0c098952 */
if(!s->budget--) { s->failed_pc=0x0c098952u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c098954;
P_0c098954: /* original 8b04, guest PC 0x0c098954 */
if(!s->budget--) { s->failed_pc=0x0c098954u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098960; }
goto P_0c098956;
P_0c098956: /* original 60e3, guest PC 0x0c098956 */
if(!s->budget--) { s->failed_pc=0x0c098956u; return 0; }
r[0]=r[14];
goto P_0c098958;
P_0c098958: /* original 881b, guest PC 0x0c098958 */
if(!s->budget--) { s->failed_pc=0x0c098958u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c09895a;
P_0c09895a: /* original 8b0a, guest PC 0x0c09895a */
if(!s->budget--) { s->failed_pc=0x0c09895au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09895c;
P_0c09895c: /* original a003, guest PC 0x0c09895c */
if(!s->budget--) { s->failed_pc=0x0c09895cu; return 0; }
goto P_0c098966;
P_0c09895e: /* original 0009, guest PC 0x0c09895e */
if(!s->budget--) { s->failed_pc=0x0c09895eu; return 0; }
goto P_0c098960;
P_0c098960: /* original 60e3, guest PC 0x0c098960 */
if(!s->budget--) { s->failed_pc=0x0c098960u; return 0; }
r[0]=r[14];
goto P_0c098962;
P_0c098962: /* original 881b, guest PC 0x0c098962 */
if(!s->budget--) { s->failed_pc=0x0c098962u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c098964;
P_0c098964: /* original 8b05, guest PC 0x0c098964 */
if(!s->budget--) { s->failed_pc=0x0c098964u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c098966;
P_0c098966: /* original d023, guest PC 0x0c098966 */
if(!s->budget--) { s->failed_pc=0x0c098966u; return 0; }
r[0]=read(ram,0x0c0989f4u,4);
goto P_0c098968;
P_0c098968: /* original 7401, guest PC 0x0c098968 */
if(!s->budget--) { s->failed_pc=0x0c098968u; return 0; }
r[4]+=0x00000001u;
goto P_0c09896a;
P_0c09896a: /* original d21b, guest PC 0x0c09896a */
if(!s->budget--) { s->failed_pc=0x0c09896au; return 0; }
r[2]=read(ram,0x0c0989d8u,4);
goto P_0c09896c;
P_0c09896c: /* original 4408, guest PC 0x0c09896c */
if(!s->budget--) { s->failed_pc=0x0c09896cu; return 0; }
r[4]<<=2;
goto P_0c09896e;
P_0c09896e: /* original 420b, guest PC 0x0c09896e */
if(!s->budget--) { s->failed_pc=0x0c09896eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098972u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098972u) { target=s->pc; goto dispatch; }
goto P_0c098972;
P_0c098970: /* original 044e, guest PC 0x0c098970 */
if(!s->budget--) { s->failed_pc=0x0c098970u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c098972;
P_0c098972: /* original 2ee8, guest PC 0x0c098972 */
if(!s->budget--) { s->failed_pc=0x0c098972u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c098974;
P_0c098974: /* original 8b02, guest PC 0x0c098974 */
if(!s->budget--) { s->failed_pc=0x0c098974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09897c; }
goto P_0c098976;
P_0c098976: /* original 84db, guest PC 0x0c098976 */
if(!s->budget--) { s->failed_pc=0x0c098976u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c098978;
P_0c098978: /* original 7001, guest PC 0x0c098978 */
if(!s->budget--) { s->failed_pc=0x0c098978u; return 0; }
r[0]+=0x00000001u;
goto P_0c09897a;
P_0c09897a: /* original 80db, guest PC 0x0c09897a */
if(!s->budget--) { s->failed_pc=0x0c09897au; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09897c;
P_0c09897c: /* original 4f26, guest PC 0x0c09897c */
if(!s->budget--) { s->failed_pc=0x0c09897cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09897e;
P_0c09897e: /* original 6df6, guest PC 0x0c09897e */
if(!s->budget--) { s->failed_pc=0x0c09897eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098980;
P_0c098980: /* original ab38, guest PC 0x0c098980 */
if(!s->budget--) { s->failed_pc=0x0c098980u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097ff4u,s,ram);
P_0c098982: /* original 6ef6, guest PC 0x0c098982 */
if(!s->budget--) { s->failed_pc=0x0c098982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c098984u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098984u; return 0; } return 1;
P_0c09efce: /* original 933f, guest PC 0x0c09efce */
if(!s->budget--) { s->failed_pc=0x0c09efceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09efd0;
P_0c09efd0: /* original e042, guest PC 0x0c09efd0 */
if(!s->budget--) { s->failed_pc=0x0c09efd0u; return 0; }
r[0]=0x00000042u;
goto P_0c09efd2;
P_0c09efd2: /* original 0435, guest PC 0x0c09efd2 */
if(!s->budget--) { s->failed_pc=0x0c09efd2u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efd4;
P_0c09efd4: /* original a000, guest PC 0x0c09efd4 */
if(!s->budget--) { s->failed_pc=0x0c09efd4u; return 0; }
goto P_0c09efd8;
P_0c09efd6: /* original 0009, guest PC 0x0c09efd6 */
if(!s->budget--) { s->failed_pc=0x0c09efd6u; return 0; }
goto P_0c09efd8;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c09efe6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09efe6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
