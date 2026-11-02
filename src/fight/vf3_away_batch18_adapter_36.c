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
int vf3_away_batch18_adapter_36(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0996f4u: goto P_0c0996f4;
case 0x0c0996f6u: goto P_0c0996f6;
case 0x0c0996f8u: goto P_0c0996f8;
case 0x0c0996fau: goto P_0c0996fa;
case 0x0c0996fcu: goto P_0c0996fc;
case 0x0c0996feu: goto P_0c0996fe;
case 0x0c099700u: goto P_0c099700;
case 0x0c099702u: goto P_0c099702;
case 0x0c099704u: goto P_0c099704;
case 0x0c099706u: goto P_0c099706;
case 0x0c099708u: goto P_0c099708;
case 0x0c09970au: goto P_0c09970a;
case 0x0c09970cu: goto P_0c09970c;
case 0x0c09970eu: goto P_0c09970e;
case 0x0c099710u: goto P_0c099710;
case 0x0c099712u: goto P_0c099712;
case 0x0c099714u: goto P_0c099714;
case 0x0c099716u: goto P_0c099716;
case 0x0c099718u: goto P_0c099718;
case 0x0c09971au: goto P_0c09971a;
case 0x0c09971cu: goto P_0c09971c;
case 0x0c09971eu: goto P_0c09971e;
case 0x0c099720u: goto P_0c099720;
case 0x0c099722u: goto P_0c099722;
case 0x0c099724u: goto P_0c099724;
case 0x0c099726u: goto P_0c099726;
case 0x0c099728u: goto P_0c099728;
case 0x0c09972au: goto P_0c09972a;
case 0x0c09972cu: goto P_0c09972c;
case 0x0c09972eu: goto P_0c09972e;
case 0x0c099730u: goto P_0c099730;
case 0x0c099732u: goto P_0c099732;
case 0x0c099734u: goto P_0c099734;
case 0x0c099736u: goto P_0c099736;
case 0x0c099738u: goto P_0c099738;
case 0x0c09973au: goto P_0c09973a;
case 0x0c09973cu: goto P_0c09973c;
case 0x0c09973eu: goto P_0c09973e;
case 0x0c099740u: goto P_0c099740;
case 0x0c099742u: goto P_0c099742;
case 0x0c099744u: goto P_0c099744;
case 0x0c099746u: goto P_0c099746;
case 0x0c099748u: goto P_0c099748;
case 0x0c09974au: goto P_0c09974a;
case 0x0c09974cu: goto P_0c09974c;
case 0x0c09974eu: goto P_0c09974e;
case 0x0c099750u: goto P_0c099750;
case 0x0c099752u: goto P_0c099752;
case 0x0c099754u: goto P_0c099754;
case 0x0c099756u: goto P_0c099756;
case 0x0c099758u: goto P_0c099758;
case 0x0c09975au: goto P_0c09975a;
case 0x0c09975cu: goto P_0c09975c;
case 0x0c09975eu: goto P_0c09975e;
case 0x0c099760u: goto P_0c099760;
case 0x0c099762u: goto P_0c099762;
case 0x0c099764u: goto P_0c099764;
case 0x0c099766u: goto P_0c099766;
case 0x0c099768u: goto P_0c099768;
case 0x0c099784u: goto P_0c099784;
case 0x0c099786u: goto P_0c099786;
case 0x0c099788u: goto P_0c099788;
case 0x0c09978au: goto P_0c09978a;
case 0x0c09978cu: goto P_0c09978c;
case 0x0c09978eu: goto P_0c09978e;
case 0x0c099790u: goto P_0c099790;
case 0x0c099792u: goto P_0c099792;
case 0x0c099794u: goto P_0c099794;
case 0x0c099796u: goto P_0c099796;
case 0x0c099798u: goto P_0c099798;
case 0x0c09979au: goto P_0c09979a;
case 0x0c09979cu: goto P_0c09979c;
case 0x0c09979eu: goto P_0c09979e;
case 0x0c0997a0u: goto P_0c0997a0;
case 0x0c0997a2u: goto P_0c0997a2;
case 0x0c0997a4u: goto P_0c0997a4;
case 0x0c0997a6u: goto P_0c0997a6;
case 0x0c0997a8u: goto P_0c0997a8;
case 0x0c0997aau: goto P_0c0997aa;
case 0x0c0997acu: goto P_0c0997ac;
case 0x0c0997aeu: goto P_0c0997ae;
case 0x0c0997b0u: goto P_0c0997b0;
case 0x0c0997b2u: goto P_0c0997b2;
case 0x0c0997b4u: goto P_0c0997b4;
case 0x0c0997b6u: goto P_0c0997b6;
case 0x0c0997b8u: goto P_0c0997b8;
case 0x0c0997bau: goto P_0c0997ba;
case 0x0c0997bcu: goto P_0c0997bc;
case 0x0c0997beu: goto P_0c0997be;
case 0x0c0997c0u: goto P_0c0997c0;
case 0x0c0997c2u: goto P_0c0997c2;
case 0x0c0997c4u: goto P_0c0997c4;
case 0x0c0997c6u: goto P_0c0997c6;
case 0x0c0997c8u: goto P_0c0997c8;
case 0x0c0997cau: goto P_0c0997ca;
case 0x0c0997ccu: goto P_0c0997cc;
case 0x0c0997ceu: goto P_0c0997ce;
case 0x0c0997d0u: goto P_0c0997d0;
case 0x0c0997d2u: goto P_0c0997d2;
case 0x0c0997d4u: goto P_0c0997d4;
case 0x0c0997d6u: goto P_0c0997d6;
case 0x0c0997d8u: goto P_0c0997d8;
case 0x0c0997dau: goto P_0c0997da;
case 0x0c0997dcu: goto P_0c0997dc;
case 0x0c0997deu: goto P_0c0997de;
case 0x0c0997e0u: goto P_0c0997e0;
case 0x0c0997e2u: goto P_0c0997e2;
case 0x0c0997e4u: goto P_0c0997e4;
case 0x0c0997e6u: goto P_0c0997e6;
case 0x0c0997e8u: goto P_0c0997e8;
case 0x0c0997eau: goto P_0c0997ea;
case 0x0c0997ecu: goto P_0c0997ec;
case 0x0c0997eeu: goto P_0c0997ee;
case 0x0c0997f0u: goto P_0c0997f0;
case 0x0c0997f2u: goto P_0c0997f2;
case 0x0c0997f4u: goto P_0c0997f4;
case 0x0c0997f6u: goto P_0c0997f6;
case 0x0c0997f8u: goto P_0c0997f8;
case 0x0c0997fau: goto P_0c0997fa;
case 0x0c0997fcu: goto P_0c0997fc;
case 0x0c0997feu: goto P_0c0997fe;
case 0x0c099800u: goto P_0c099800;
case 0x0c099802u: goto P_0c099802;
case 0x0c099804u: goto P_0c099804;
case 0x0c099806u: goto P_0c099806;
case 0x0c099808u: goto P_0c099808;
case 0x0c09980au: goto P_0c09980a;
case 0x0c09980cu: goto P_0c09980c;
case 0x0c09980eu: goto P_0c09980e;
case 0x0c099810u: goto P_0c099810;
case 0x0c099812u: goto P_0c099812;
case 0x0c099814u: goto P_0c099814;
case 0x0c099816u: goto P_0c099816;
case 0x0c099818u: goto P_0c099818;
case 0x0c09981au: goto P_0c09981a;
case 0x0c09981cu: goto P_0c09981c;
case 0x0c09981eu: goto P_0c09981e;
case 0x0c099820u: goto P_0c099820;
case 0x0c099822u: goto P_0c099822;
case 0x0c099824u: goto P_0c099824;
case 0x0c099826u: goto P_0c099826;
case 0x0c099828u: goto P_0c099828;
case 0x0c09982au: goto P_0c09982a;
case 0x0c09982cu: goto P_0c09982c;
case 0x0c09982eu: goto P_0c09982e;
case 0x0c099830u: goto P_0c099830;
case 0x0c099832u: goto P_0c099832;
case 0x0c099834u: goto P_0c099834;
case 0x0c099836u: goto P_0c099836;
case 0x0c099838u: goto P_0c099838;
case 0x0c09983au: goto P_0c09983a;
case 0x0c09983cu: goto P_0c09983c;
case 0x0c09983eu: goto P_0c09983e;
case 0x0c099840u: goto P_0c099840;
case 0x0c099842u: goto P_0c099842;
case 0x0c099844u: goto P_0c099844;
case 0x0c099846u: goto P_0c099846;
case 0x0c099848u: goto P_0c099848;
case 0x0c09984au: goto P_0c09984a;
case 0x0c09984cu: goto P_0c09984c;
case 0x0c09984eu: goto P_0c09984e;
case 0x0c099850u: goto P_0c099850;
case 0x0c099852u: goto P_0c099852;
case 0x0c099854u: goto P_0c099854;
case 0x0c099856u: goto P_0c099856;
case 0x0c099858u: goto P_0c099858;
case 0x0c09985au: goto P_0c09985a;
case 0x0c09985cu: goto P_0c09985c;
case 0x0c09985eu: goto P_0c09985e;
case 0x0c099860u: goto P_0c099860;
case 0x0c099862u: goto P_0c099862;
case 0x0c099864u: goto P_0c099864;
case 0x0c099866u: goto P_0c099866;
case 0x0c099868u: goto P_0c099868;
case 0x0c09986au: goto P_0c09986a;
case 0x0c09986cu: goto P_0c09986c;
case 0x0c09986eu: goto P_0c09986e;
case 0x0c099870u: goto P_0c099870;
case 0x0c099872u: goto P_0c099872;
case 0x0c099874u: goto P_0c099874;
case 0x0c099876u: goto P_0c099876;
case 0x0c099878u: goto P_0c099878;
case 0x0c09987au: goto P_0c09987a;
case 0x0c09987cu: goto P_0c09987c;
case 0x0c09987eu: goto P_0c09987e;
case 0x0c099880u: goto P_0c099880;
case 0x0c099882u: goto P_0c099882;
case 0x0c099884u: goto P_0c099884;
case 0x0c099886u: goto P_0c099886;
case 0x0c099888u: goto P_0c099888;
case 0x0c09988au: goto P_0c09988a;
case 0x0c09988cu: goto P_0c09988c;
case 0x0c09988eu: goto P_0c09988e;
case 0x0c099890u: goto P_0c099890;
case 0x0c099892u: goto P_0c099892;
case 0x0c099894u: goto P_0c099894;
case 0x0c099896u: goto P_0c099896;
case 0x0c099898u: goto P_0c099898;
case 0x0c09989au: goto P_0c09989a;
case 0x0c09989cu: goto P_0c09989c;
case 0x0c09989eu: goto P_0c09989e;
case 0x0c0998a0u: goto P_0c0998a0;
case 0x0c0998a2u: goto P_0c0998a2;
case 0x0c0998a4u: goto P_0c0998a4;
case 0x0c0998a6u: goto P_0c0998a6;
case 0x0c0998a8u: goto P_0c0998a8;
case 0x0c0998aau: goto P_0c0998aa;
case 0x0c0998acu: goto P_0c0998ac;
case 0x0c0998aeu: goto P_0c0998ae;
case 0x0c0998b0u: goto P_0c0998b0;
case 0x0c0998b2u: goto P_0c0998b2;
case 0x0c0998b4u: goto P_0c0998b4;
case 0x0c0998b6u: goto P_0c0998b6;
case 0x0c0998b8u: goto P_0c0998b8;
case 0x0c0998bau: goto P_0c0998ba;
case 0x0c0998bcu: goto P_0c0998bc;
case 0x0c0998beu: goto P_0c0998be;
case 0x0c0998c0u: goto P_0c0998c0;
case 0x0c0998c2u: goto P_0c0998c2;
case 0x0c0998c4u: goto P_0c0998c4;
case 0x0c0998c6u: goto P_0c0998c6;
case 0x0c0998c8u: goto P_0c0998c8;
case 0x0c0998cau: goto P_0c0998ca;
case 0x0c099910u: goto P_0c099910;
case 0x0c099912u: goto P_0c099912;
case 0x0c099914u: goto P_0c099914;
case 0x0c099916u: goto P_0c099916;
case 0x0c099918u: goto P_0c099918;
case 0x0c09991au: goto P_0c09991a;
case 0x0c09991cu: goto P_0c09991c;
case 0x0c09991eu: goto P_0c09991e;
case 0x0c099920u: goto P_0c099920;
case 0x0c099922u: goto P_0c099922;
case 0x0c099924u: goto P_0c099924;
case 0x0c099926u: goto P_0c099926;
case 0x0c099928u: goto P_0c099928;
case 0x0c09992au: goto P_0c09992a;
case 0x0c09992cu: goto P_0c09992c;
case 0x0c09992eu: goto P_0c09992e;
case 0x0c099930u: goto P_0c099930;
case 0x0c099932u: goto P_0c099932;
case 0x0c099934u: goto P_0c099934;
case 0x0c099936u: goto P_0c099936;
case 0x0c099938u: goto P_0c099938;
case 0x0c09993au: goto P_0c09993a;
case 0x0c09993cu: goto P_0c09993c;
case 0x0c09993eu: goto P_0c09993e;
case 0x0c099940u: goto P_0c099940;
case 0x0c099942u: goto P_0c099942;
case 0x0c099944u: goto P_0c099944;
case 0x0c099946u: goto P_0c099946;
case 0x0c099948u: goto P_0c099948;
case 0x0c09994au: goto P_0c09994a;
case 0x0c09994cu: goto P_0c09994c;
case 0x0c09994eu: goto P_0c09994e;
case 0x0c099950u: goto P_0c099950;
case 0x0c099952u: goto P_0c099952;
case 0x0c099954u: goto P_0c099954;
case 0x0c099956u: goto P_0c099956;
case 0x0c099958u: goto P_0c099958;
case 0x0c09995au: goto P_0c09995a;
case 0x0c09995cu: goto P_0c09995c;
case 0x0c09995eu: goto P_0c09995e;
case 0x0c099960u: goto P_0c099960;
case 0x0c099962u: goto P_0c099962;
case 0x0c099964u: goto P_0c099964;
case 0x0c099966u: goto P_0c099966;
case 0x0c099968u: goto P_0c099968;
case 0x0c09996au: goto P_0c09996a;
case 0x0c09996cu: goto P_0c09996c;
case 0x0c09996eu: goto P_0c09996e;
case 0x0c099970u: goto P_0c099970;
case 0x0c099972u: goto P_0c099972;
case 0x0c099974u: goto P_0c099974;
case 0x0c099976u: goto P_0c099976;
case 0x0c099978u: goto P_0c099978;
case 0x0c09997au: goto P_0c09997a;
case 0x0c09997cu: goto P_0c09997c;
case 0x0c09997eu: goto P_0c09997e;
case 0x0c099980u: goto P_0c099980;
case 0x0c099982u: goto P_0c099982;
case 0x0c099984u: goto P_0c099984;
case 0x0c099986u: goto P_0c099986;
case 0x0c099988u: goto P_0c099988;
case 0x0c09998au: goto P_0c09998a;
case 0x0c09998cu: goto P_0c09998c;
case 0x0c09998eu: goto P_0c09998e;
case 0x0c099990u: goto P_0c099990;
case 0x0c099992u: goto P_0c099992;
case 0x0c099994u: goto P_0c099994;
case 0x0c099996u: goto P_0c099996;
case 0x0c099998u: goto P_0c099998;
case 0x0c09999au: goto P_0c09999a;
case 0x0c09999cu: goto P_0c09999c;
case 0x0c09999eu: goto P_0c09999e;
case 0x0c0999a0u: goto P_0c0999a0;
case 0x0c0999a2u: goto P_0c0999a2;
case 0x0c0999a4u: goto P_0c0999a4;
case 0x0c0999a6u: goto P_0c0999a6;
case 0x0c0999a8u: goto P_0c0999a8;
case 0x0c0999aau: goto P_0c0999aa;
case 0x0c0999acu: goto P_0c0999ac;
case 0x0c0999aeu: goto P_0c0999ae;
case 0x0c0999b0u: goto P_0c0999b0;
case 0x0c0999b2u: goto P_0c0999b2;
case 0x0c0999b4u: goto P_0c0999b4;
case 0x0c0999b6u: goto P_0c0999b6;
case 0x0c0999b8u: goto P_0c0999b8;
case 0x0c0999bau: goto P_0c0999ba;
case 0x0c0999bcu: goto P_0c0999bc;
case 0x0c0999beu: goto P_0c0999be;
case 0x0c0999c0u: goto P_0c0999c0;
case 0x0c0999c2u: goto P_0c0999c2;
case 0x0c0999c4u: goto P_0c0999c4;
case 0x0c0999c6u: goto P_0c0999c6;
case 0x0c0999c8u: goto P_0c0999c8;
case 0x0c0999cau: goto P_0c0999ca;
case 0x0c0999ccu: goto P_0c0999cc;
case 0x0c0999ceu: goto P_0c0999ce;
case 0x0c0999d0u: goto P_0c0999d0;
case 0x0c0999d2u: goto P_0c0999d2;
case 0x0c0999d4u: goto P_0c0999d4;
case 0x0c0999d6u: goto P_0c0999d6;
case 0x0c0999d8u: goto P_0c0999d8;
case 0x0c0999dau: goto P_0c0999da;
case 0x0c0999dcu: goto P_0c0999dc;
case 0x0c0999deu: goto P_0c0999de;
case 0x0c0999e0u: goto P_0c0999e0;
case 0x0c0999e2u: goto P_0c0999e2;
case 0x0c0999e4u: goto P_0c0999e4;
case 0x0c0999e6u: goto P_0c0999e6;
case 0x0c0999e8u: goto P_0c0999e8;
case 0x0c0999eau: goto P_0c0999ea;
case 0x0c0999ecu: goto P_0c0999ec;
case 0x0c0999eeu: goto P_0c0999ee;
case 0x0c0999f0u: goto P_0c0999f0;
case 0x0c0999f2u: goto P_0c0999f2;
case 0x0c0999f4u: goto P_0c0999f4;
case 0x0c0999f6u: goto P_0c0999f6;
case 0x0c0999f8u: goto P_0c0999f8;
case 0x0c0999fau: goto P_0c0999fa;
case 0x0c099a18u: goto P_0c099a18;
case 0x0c099a1au: goto P_0c099a1a;
case 0x0c099a1cu: goto P_0c099a1c;
case 0x0c099a1eu: goto P_0c099a1e;
case 0x0c099a20u: goto P_0c099a20;
case 0x0c099a22u: goto P_0c099a22;
case 0x0c099a24u: goto P_0c099a24;
case 0x0c099a26u: goto P_0c099a26;
case 0x0c099a28u: goto P_0c099a28;
case 0x0c099a2au: goto P_0c099a2a;
case 0x0c099a2cu: goto P_0c099a2c;
case 0x0c099a2eu: goto P_0c099a2e;
case 0x0c099a30u: goto P_0c099a30;
case 0x0c099a32u: goto P_0c099a32;
case 0x0c099a34u: goto P_0c099a34;
case 0x0c099a36u: goto P_0c099a36;
case 0x0c099a38u: goto P_0c099a38;
case 0x0c099a3au: goto P_0c099a3a;
case 0x0c099a3cu: goto P_0c099a3c;
case 0x0c099a3eu: goto P_0c099a3e;
case 0x0c099a40u: goto P_0c099a40;
case 0x0c099a42u: goto P_0c099a42;
case 0x0c099a44u: goto P_0c099a44;
case 0x0c099a46u: goto P_0c099a46;
case 0x0c099a48u: goto P_0c099a48;
case 0x0c099a4au: goto P_0c099a4a;
case 0x0c099a4cu: goto P_0c099a4c;
case 0x0c099a4eu: goto P_0c099a4e;
case 0x0c099a50u: goto P_0c099a50;
case 0x0c099a52u: goto P_0c099a52;
case 0x0c099a54u: goto P_0c099a54;
case 0x0c099a56u: goto P_0c099a56;
case 0x0c099a58u: goto P_0c099a58;
case 0x0c099a5au: goto P_0c099a5a;
case 0x0c099a5cu: goto P_0c099a5c;
case 0x0c099a5eu: goto P_0c099a5e;
case 0x0c099a60u: goto P_0c099a60;
case 0x0c099a62u: goto P_0c099a62;
case 0x0c099a64u: goto P_0c099a64;
case 0x0c099a66u: goto P_0c099a66;
case 0x0c099a68u: goto P_0c099a68;
case 0x0c099a6au: goto P_0c099a6a;
case 0x0c099a6cu: goto P_0c099a6c;
case 0x0c099a6eu: goto P_0c099a6e;
case 0x0c099a70u: goto P_0c099a70;
case 0x0c099a72u: goto P_0c099a72;
case 0x0c099a74u: goto P_0c099a74;
case 0x0c099a76u: goto P_0c099a76;
case 0x0c099a78u: goto P_0c099a78;
case 0x0c099a7au: goto P_0c099a7a;
case 0x0c099a7cu: goto P_0c099a7c;
case 0x0c099a7eu: goto P_0c099a7e;
case 0x0c099a80u: goto P_0c099a80;
case 0x0c099a82u: goto P_0c099a82;
case 0x0c099a84u: goto P_0c099a84;
case 0x0c099a86u: goto P_0c099a86;
case 0x0c099a88u: goto P_0c099a88;
case 0x0c099a8au: goto P_0c099a8a;
case 0x0c099a8cu: goto P_0c099a8c;
case 0x0c099a8eu: goto P_0c099a8e;
case 0x0c099a90u: goto P_0c099a90;
case 0x0c099a92u: goto P_0c099a92;
case 0x0c099a94u: goto P_0c099a94;
case 0x0c099a96u: goto P_0c099a96;
case 0x0c099a98u: goto P_0c099a98;
case 0x0c099a9au: goto P_0c099a9a;
case 0x0c099a9cu: goto P_0c099a9c;
case 0x0c099a9eu: goto P_0c099a9e;
case 0x0c099aa0u: goto P_0c099aa0;
case 0x0c099aa2u: goto P_0c099aa2;
case 0x0c099aa4u: goto P_0c099aa4;
case 0x0c099aa6u: goto P_0c099aa6;
case 0x0c099aa8u: goto P_0c099aa8;
case 0x0c099aaau: goto P_0c099aaa;
case 0x0c099aacu: goto P_0c099aac;
case 0x0c099aaeu: goto P_0c099aae;
case 0x0c099ab0u: goto P_0c099ab0;
case 0x0c099ab2u: goto P_0c099ab2;
case 0x0c099ab4u: goto P_0c099ab4;
case 0x0c099ab6u: goto P_0c099ab6;
case 0x0c099ab8u: goto P_0c099ab8;
case 0x0c099abau: goto P_0c099aba;
case 0x0c099abcu: goto P_0c099abc;
case 0x0c099abeu: goto P_0c099abe;
case 0x0c099ac0u: goto P_0c099ac0;
case 0x0c099ac2u: goto P_0c099ac2;
case 0x0c099ac4u: goto P_0c099ac4;
case 0x0c099ac6u: goto P_0c099ac6;
case 0x0c099ac8u: goto P_0c099ac8;
case 0x0c099acau: goto P_0c099aca;
case 0x0c099accu: goto P_0c099acc;
case 0x0c099aceu: goto P_0c099ace;
case 0x0c099ad0u: goto P_0c099ad0;
case 0x0c099ad2u: goto P_0c099ad2;
case 0x0c099ad4u: goto P_0c099ad4;
case 0x0c099ad6u: goto P_0c099ad6;
case 0x0c099ad8u: goto P_0c099ad8;
case 0x0c099adau: goto P_0c099ada;
case 0x0c099adcu: goto P_0c099adc;
case 0x0c099adeu: goto P_0c099ade;
case 0x0c099ae0u: goto P_0c099ae0;
case 0x0c099ae2u: goto P_0c099ae2;
case 0x0c099ae4u: goto P_0c099ae4;
case 0x0c099ae6u: goto P_0c099ae6;
case 0x0c099ae8u: goto P_0c099ae8;
case 0x0c099aeau: goto P_0c099aea;
case 0x0c099aecu: goto P_0c099aec;
case 0x0c099aeeu: goto P_0c099aee;
case 0x0c099af0u: goto P_0c099af0;
case 0x0c099af2u: goto P_0c099af2;
case 0x0c099af4u: goto P_0c099af4;
case 0x0c099af6u: goto P_0c099af6;
case 0x0c099af8u: goto P_0c099af8;
case 0x0c099afau: goto P_0c099afa;
case 0x0c099afcu: goto P_0c099afc;
case 0x0c099afeu: goto P_0c099afe;
case 0x0c099b00u: goto P_0c099b00;
case 0x0c099b02u: goto P_0c099b02;
case 0x0c099b04u: goto P_0c099b04;
case 0x0c099b06u: goto P_0c099b06;
case 0x0c099b08u: goto P_0c099b08;
case 0x0c099b0au: goto P_0c099b0a;
case 0x0c099b0cu: goto P_0c099b0c;
case 0x0c099b0eu: goto P_0c099b0e;
case 0x0c099b10u: goto P_0c099b10;
case 0x0c099b12u: goto P_0c099b12;
case 0x0c099b14u: goto P_0c099b14;
case 0x0c099b16u: goto P_0c099b16;
case 0x0c099b18u: goto P_0c099b18;
case 0x0c099b1au: goto P_0c099b1a;
case 0x0c099b1cu: goto P_0c099b1c;
case 0x0c099b1eu: goto P_0c099b1e;
case 0x0c099b20u: goto P_0c099b20;
case 0x0c099b22u: goto P_0c099b22;
case 0x0c099b24u: goto P_0c099b24;
case 0x0c099b26u: goto P_0c099b26;
case 0x0c099b28u: goto P_0c099b28;
case 0x0c099b2au: goto P_0c099b2a;
case 0x0c099b2cu: goto P_0c099b2c;
case 0x0c099b2eu: goto P_0c099b2e;
case 0x0c099b30u: goto P_0c099b30;
case 0x0c099b32u: goto P_0c099b32;
case 0x0c099b34u: goto P_0c099b34;
case 0x0c099b36u: goto P_0c099b36;
case 0x0c099b38u: goto P_0c099b38;
case 0x0c099b3au: goto P_0c099b3a;
case 0x0c099b3cu: goto P_0c099b3c;
case 0x0c099b3eu: goto P_0c099b3e;
case 0x0c099b40u: goto P_0c099b40;
case 0x0c099b42u: goto P_0c099b42;
case 0x0c099b44u: goto P_0c099b44;
case 0x0c099b46u: goto P_0c099b46;
case 0x0c099b48u: goto P_0c099b48;
case 0x0c099b4au: goto P_0c099b4a;
case 0x0c099b4cu: goto P_0c099b4c;
case 0x0c099b4eu: goto P_0c099b4e;
case 0x0c099b50u: goto P_0c099b50;
case 0x0c099b52u: goto P_0c099b52;
case 0x0c099b54u: goto P_0c099b54;
case 0x0c099b56u: goto P_0c099b56;
case 0x0c099b58u: goto P_0c099b58;
case 0x0c099b5au: goto P_0c099b5a;
case 0x0c099b5cu: goto P_0c099b5c;
case 0x0c099b5eu: goto P_0c099b5e;
case 0x0c099b60u: goto P_0c099b60;
case 0x0c099b62u: goto P_0c099b62;
case 0x0c099b64u: goto P_0c099b64;
case 0x0c099b66u: goto P_0c099b66;
case 0x0c099b68u: goto P_0c099b68;
case 0x0c099b6au: goto P_0c099b6a;
case 0x0c099b6cu: goto P_0c099b6c;
case 0x0c099b6eu: goto P_0c099b6e;
case 0x0c099b70u: goto P_0c099b70;
case 0x0c099b9cu: goto P_0c099b9c;
case 0x0c099b9eu: goto P_0c099b9e;
case 0x0c099ba0u: goto P_0c099ba0;
case 0x0c099ba2u: goto P_0c099ba2;
case 0x0c099ba4u: goto P_0c099ba4;
case 0x0c099ba6u: goto P_0c099ba6;
case 0x0c099ba8u: goto P_0c099ba8;
case 0x0c099baau: goto P_0c099baa;
case 0x0c099bacu: goto P_0c099bac;
case 0x0c099baeu: goto P_0c099bae;
case 0x0c099bb0u: goto P_0c099bb0;
case 0x0c099bb2u: goto P_0c099bb2;
case 0x0c099bb4u: goto P_0c099bb4;
case 0x0c099bb6u: goto P_0c099bb6;
case 0x0c099bb8u: goto P_0c099bb8;
case 0x0c099bbau: goto P_0c099bba;
case 0x0c099bbcu: goto P_0c099bbc;
case 0x0c099bbeu: goto P_0c099bbe;
case 0x0c099bc0u: goto P_0c099bc0;
case 0x0c099bc2u: goto P_0c099bc2;
case 0x0c099bc4u: goto P_0c099bc4;
case 0x0c099bc6u: goto P_0c099bc6;
case 0x0c099bc8u: goto P_0c099bc8;
case 0x0c099bcau: goto P_0c099bca;
case 0x0c099bccu: goto P_0c099bcc;
case 0x0c099bceu: goto P_0c099bce;
case 0x0c099bd0u: goto P_0c099bd0;
case 0x0c099bd2u: goto P_0c099bd2;
case 0x0c099bd4u: goto P_0c099bd4;
case 0x0c099bd6u: goto P_0c099bd6;
case 0x0c099bd8u: goto P_0c099bd8;
case 0x0c099bdau: goto P_0c099bda;
case 0x0c099bdcu: goto P_0c099bdc;
case 0x0c099bdeu: goto P_0c099bde;
case 0x0c099be0u: goto P_0c099be0;
case 0x0c099be2u: goto P_0c099be2;
case 0x0c099be4u: goto P_0c099be4;
case 0x0c099be6u: goto P_0c099be6;
case 0x0c099be8u: goto P_0c099be8;
case 0x0c099beau: goto P_0c099bea;
case 0x0c099becu: goto P_0c099bec;
case 0x0c099beeu: goto P_0c099bee;
case 0x0c099bf0u: goto P_0c099bf0;
case 0x0c099bf2u: goto P_0c099bf2;
case 0x0c099bf4u: goto P_0c099bf4;
case 0x0c099bf6u: goto P_0c099bf6;
case 0x0c099bf8u: goto P_0c099bf8;
case 0x0c099bfau: goto P_0c099bfa;
case 0x0c099bfcu: goto P_0c099bfc;
case 0x0c099bfeu: goto P_0c099bfe;
case 0x0c099c00u: goto P_0c099c00;
case 0x0c099c02u: goto P_0c099c02;
case 0x0c099c04u: goto P_0c099c04;
case 0x0c099c06u: goto P_0c099c06;
case 0x0c099c08u: goto P_0c099c08;
case 0x0c099c0au: goto P_0c099c0a;
case 0x0c099c0cu: goto P_0c099c0c;
case 0x0c099c0eu: goto P_0c099c0e;
case 0x0c099c10u: goto P_0c099c10;
case 0x0c099c12u: goto P_0c099c12;
case 0x0c099c14u: goto P_0c099c14;
case 0x0c099c16u: goto P_0c099c16;
case 0x0c099c18u: goto P_0c099c18;
case 0x0c099c1au: goto P_0c099c1a;
case 0x0c099c1cu: goto P_0c099c1c;
case 0x0c099c1eu: goto P_0c099c1e;
case 0x0c099c20u: goto P_0c099c20;
case 0x0c099c22u: goto P_0c099c22;
case 0x0c099c24u: goto P_0c099c24;
case 0x0c099c26u: goto P_0c099c26;
case 0x0c099c28u: goto P_0c099c28;
case 0x0c099c2au: goto P_0c099c2a;
case 0x0c099c2cu: goto P_0c099c2c;
case 0x0c099c2eu: goto P_0c099c2e;
case 0x0c099c30u: goto P_0c099c30;
case 0x0c099c32u: goto P_0c099c32;
case 0x0c099c34u: goto P_0c099c34;
case 0x0c099c36u: goto P_0c099c36;
case 0x0c099c38u: goto P_0c099c38;
case 0x0c099c3au: goto P_0c099c3a;
case 0x0c099c3cu: goto P_0c099c3c;
case 0x0c099c3eu: goto P_0c099c3e;
case 0x0c099c40u: goto P_0c099c40;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0996f4: /* original 2fe6, guest PC 0x0c0996f4 */
if(!s->budget--) { s->failed_pc=0x0c0996f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0996f6;
P_0c0996f6: /* original 2fd6, guest PC 0x0c0996f6 */
if(!s->budget--) { s->failed_pc=0x0c0996f6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0996f8;
P_0c0996f8: /* original 2fc6, guest PC 0x0c0996f8 */
if(!s->budget--) { s->failed_pc=0x0c0996f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0996fa;
P_0c0996fa: /* original 2fb6, guest PC 0x0c0996fa */
if(!s->budget--) { s->failed_pc=0x0c0996fau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0996fc;
P_0c0996fc: /* original 2fa6, guest PC 0x0c0996fc */
if(!s->budget--) { s->failed_pc=0x0c0996fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0996fe;
P_0c0996fe: /* original ea00, guest PC 0x0c0996fe */
if(!s->budget--) { s->failed_pc=0x0c0996feu; return 0; }
r[10]=0x00000000u;
goto P_0c099700;
P_0c099700: /* original 2f96, guest PC 0x0c099700 */
if(!s->budget--) { s->failed_pc=0x0c099700u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099702;
P_0c099702: /* original e908, guest PC 0x0c099702 */
if(!s->budget--) { s->failed_pc=0x0c099702u; return 0; }
r[9]=0x00000008u;
goto P_0c099704;
P_0c099704: /* original 2f86, guest PC 0x0c099704 */
if(!s->budget--) { s->failed_pc=0x0c099704u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099706;
P_0c099706: /* original fffb, guest PC 0x0c099706 */
if(!s->budget--) { s->failed_pc=0x0c099706u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c099708;
P_0c099708: /* original ffeb, guest PC 0x0c099708 */
if(!s->budget--) { s->failed_pc=0x0c099708u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09970a;
P_0c09970a: /* original 4f22, guest PC 0x0c09970a */
if(!s->budget--) { s->failed_pc=0x0c09970au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09970c;
P_0c09970c: /* original d31b, guest PC 0x0c09970c */
if(!s->budget--) { s->failed_pc=0x0c09970cu; return 0; }
r[3]=read(ram,0x0c09977cu,4);
goto P_0c09970e;
P_0c09970e: /* original dd18, guest PC 0x0c09970e */
if(!s->budget--) { s->failed_pc=0x0c09970eu; return 0; }
r[13]=read(ram,0x0c099770u,4);
goto P_0c099710;
P_0c099710: /* original 7fec, guest PC 0x0c099710 */
if(!s->budget--) { s->failed_pc=0x0c099710u; return 0; }
r[15]+=0xffffffecu;
goto P_0c099712;
P_0c099712: /* original de18, guest PC 0x0c099712 */
if(!s->budget--) { s->failed_pc=0x0c099712u; return 0; }
r[14]=read(ram,0x0c099774u,4);
goto P_0c099714;
P_0c099714: /* original d815, guest PC 0x0c099714 */
if(!s->budget--) { s->failed_pc=0x0c099714u; return 0; }
r[8]=read(ram,0x0c09976cu,4);
goto P_0c099716;
P_0c099716: /* original db18, guest PC 0x0c099716 */
if(!s->budget--) { s->failed_pc=0x0c099716u; return 0; }
r[11]=read(ram,0x0c099778u,4);
goto P_0c099718;
P_0c099718: /* original ff8d, guest PC 0x0c099718 */
if(!s->budget--) { s->failed_pc=0x0c099718u; return 0; }
fr[15]=0;
goto P_0c09971a;
P_0c09971a: /* original 1f34, guest PC 0x0c09971a */
if(!s->budget--) { s->failed_pc=0x0c09971au; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c09971c;
P_0c09971c: /* original 53d5, guest PC 0x0c09971c */
if(!s->budget--) { s->failed_pc=0x0c09971cu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c09971e;
P_0c09971e: /* original 5cd4, guest PC 0x0c09971e */
if(!s->budget--) { s->failed_pc=0x0c09971eu; return 0; }
r[12]=read(ram,r[13]+16,4);
goto P_0c099720;
P_0c099720: /* original 1f32, guest PC 0x0c099720 */
if(!s->budget--) { s->failed_pc=0x0c099720u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c099722;
P_0c099722: /* original 9022, guest PC 0x0c099722 */
if(!s->budget--) { s->failed_pc=0x0c099722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09976au,2);
goto P_0c099724;
P_0c099724: /* original 0ea4, guest PC 0x0c099724 */
if(!s->budget--) { s->failed_pc=0x0c099724u; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c099726;
P_0c099726: /* original 53e2, guest PC 0x0c099726 */
if(!s->budget--) { s->failed_pc=0x0c099726u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099728;
P_0c099728: /* original 1f33, guest PC 0x0c099728 */
if(!s->budget--) { s->failed_pc=0x0c099728u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c09972a;
P_0c09972a: /* original d315, guest PC 0x0c09972a */
if(!s->budget--) { s->failed_pc=0x0c09972au; return 0; }
r[3]=read(ram,0x0c099780u,4);
goto P_0c09972c;
P_0c09972c: /* original 54f4, guest PC 0x0c09972c */
if(!s->budget--) { s->failed_pc=0x0c09972cu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c09972e;
P_0c09972e: /* original 430b, guest PC 0x0c09972e */
if(!s->budget--) { s->failed_pc=0x0c09972eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099732u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099732u) { target=s->pc; goto dispatch; }
goto P_0c099732;
P_0c099730: /* original 7413, guest PC 0x0c099730 */
if(!s->budget--) { s->failed_pc=0x0c099730u; return 0; }
r[4]+=0x00000013u;
goto P_0c099732;
P_0c099732: /* original 600c, guest PC 0x0c099732 */
if(!s->budget--) { s->failed_pc=0x0c099732u; return 0; }
r[0]=r[0]&255u;
goto P_0c099734;
P_0c099734: /* original 1f01, guest PC 0x0c099734 */
if(!s->budget--) { s->failed_pc=0x0c099734u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c099736;
P_0c099736: /* original e029, guest PC 0x0c099736 */
if(!s->budget--) { s->failed_pc=0x0c099736u; return 0; }
r[0]=0x00000029u;
goto P_0c099738;
P_0c099738: /* original 00ec, guest PC 0x0c099738 */
if(!s->budget--) { s->failed_pc=0x0c099738u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09973a;
P_0c09973a: /* original 600c, guest PC 0x0c09973a */
if(!s->budget--) { s->failed_pc=0x0c09973au; return 0; }
r[0]=r[0]&255u;
goto P_0c09973c;
P_0c09973c: /* original 8803, guest PC 0x0c09973c */
if(!s->budget--) { s->failed_pc=0x0c09973cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09973e;
P_0c09973e: /* original 8b21, guest PC 0x0c09973e */
if(!s->budget--) { s->failed_pc=0x0c09973eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c099740;
P_0c099740: /* original 53f1, guest PC 0x0c099740 */
if(!s->budget--) { s->failed_pc=0x0c099740u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c099742;
P_0c099742: /* original 2338, guest PC 0x0c099742 */
if(!s->budget--) { s->failed_pc=0x0c099742u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099744;
P_0c099744: /* original 891e, guest PC 0x0c099744 */
if(!s->budget--) { s->failed_pc=0x0c099744u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099784; }
goto P_0c099746;
P_0c099746: /* original 52f3, guest PC 0x0c099746 */
if(!s->budget--) { s->failed_pc=0x0c099746u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c099748;
P_0c099748: /* original 2288, guest PC 0x0c099748 */
if(!s->budget--) { s->failed_pc=0x0c099748u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c09974a;
P_0c09974a: /* original 8b1b, guest PC 0x0c09974a */
if(!s->budget--) { s->failed_pc=0x0c09974au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c09974c;
P_0c09974c: /* original 50f3, guest PC 0x0c09974c */
if(!s->budget--) { s->failed_pc=0x0c09974cu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c09974e;
P_0c09974e: /* original c804, guest PC 0x0c09974e */
if(!s->budget--) { s->failed_pc=0x0c09974eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c099750;
P_0c099750: /* original 8b18, guest PC 0x0c099750 */
if(!s->budget--) { s->failed_pc=0x0c099750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c099752;
P_0c099752: /* original e019, guest PC 0x0c099752 */
if(!s->budget--) { s->failed_pc=0x0c099752u; return 0; }
r[0]=0x00000019u;
goto P_0c099754;
P_0c099754: /* original 00ec, guest PC 0x0c099754 */
if(!s->budget--) { s->failed_pc=0x0c099754u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099756;
P_0c099756: /* original 600c, guest PC 0x0c099756 */
if(!s->budget--) { s->failed_pc=0x0c099756u; return 0; }
r[0]=r[0]&255u;
goto P_0c099758;
P_0c099758: /* original 8802, guest PC 0x0c099758 */
if(!s->budget--) { s->failed_pc=0x0c099758u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09975a;
P_0c09975a: /* original 8b13, guest PC 0x0c09975a */
if(!s->budget--) { s->failed_pc=0x0c09975au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099784; }
goto P_0c09975c;
P_0c09975c: /* original 84bb, guest PC 0x0c09975c */
if(!s->budget--) { s->failed_pc=0x0c09975cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+11,1);
goto P_0c09975e;
P_0c09975e: /* original 7001, guest PC 0x0c09975e */
if(!s->budget--) { s->failed_pc=0x0c09975eu; return 0; }
r[0]+=0x00000001u;
goto P_0c099760;
P_0c099760: /* original 80bb, guest PC 0x0c099760 */
if(!s->budget--) { s->failed_pc=0x0c099760u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c099762;
P_0c099762: /* original b2d4, guest PC 0x0c099762 */
if(!s->budget--) { s->failed_pc=0x0c099762u; return 0; }
target=code_base|0x0c099d0eu; r[16]=code_base|0x0c099766u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099766u) { target=s->pc; goto dispatch; }
goto P_0c099766;
P_0c099764: /* original 64c3, guest PC 0x0c099764 */
if(!s->budget--) { s->failed_pc=0x0c099764u; return 0; }
r[4]=r[12];
goto P_0c099766;
P_0c099766: /* original a260, guest PC 0x0c099766 */
if(!s->budget--) { s->failed_pc=0x0c099766u; return 0; }
goto P_0c099c2a;
P_0c099768: /* original 0009, guest PC 0x0c099768 */
if(!s->budget--) { s->failed_pc=0x0c099768u; return 0; }
if(!vf3_matrix_family(0x0c09976au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09976au; return 0; } return 1;
P_0c099784: /* original 54d8, guest PC 0x0c099784 */
if(!s->budget--) { s->failed_pc=0x0c099784u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c099786;
P_0c099786: /* original d35b, guest PC 0x0c099786 */
if(!s->budget--) { s->failed_pc=0x0c099786u; return 0; }
r[3]=read(ram,0x0c0998f4u,4);
goto P_0c099788;
P_0c099788: /* original 6142, guest PC 0x0c099788 */
if(!s->budget--) { s->failed_pc=0x0c099788u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c09978a;
P_0c09978a: /* original 2139, guest PC 0x0c09978a */
if(!s->budget--) { s->failed_pc=0x0c09978au; return 0; }
r[1]&=r[3];
goto P_0c09978c;
P_0c09978c: /* original 2f12, guest PC 0x0c09978c */
if(!s->budget--) { s->failed_pc=0x0c09978cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09978e;
P_0c09978e: /* original 6213, guest PC 0x0c09978e */
if(!s->budget--) { s->failed_pc=0x0c09978eu; return 0; }
r[2]=r[1];
goto P_0c099790;
P_0c099790: /* original 2412, guest PC 0x0c099790 */
if(!s->budget--) { s->failed_pc=0x0c099790u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c099792;
P_0c099792: /* original 909b, guest PC 0x0c099792 */
if(!s->budget--) { s->failed_pc=0x0c099792u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ccu,2);
goto P_0c099794;
P_0c099794: /* original 04a4, guest PC 0x0c099794 */
if(!s->budget--) { s->failed_pc=0x0c099794u; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099796;
P_0c099796: /* original d259, guest PC 0x0c099796 */
if(!s->budget--) { s->failed_pc=0x0c099796u; return 0; }
r[2]=read(ram,0x0c0998fcu,4);
goto P_0c099798;
P_0c099798: /* original d457, guest PC 0x0c099798 */
if(!s->budget--) { s->failed_pc=0x0c099798u; return 0; }
r[4]=read(ram,0x0c0998f8u,4);
goto P_0c09979a;
P_0c09979a: /* original 420b, guest PC 0x0c09979a */
if(!s->budget--) { s->failed_pc=0x0c09979au; return 0; }
target=r[2];
r[16]=code_base|0x0c09979eu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09979eu) { target=s->pc; goto dispatch; }
goto P_0c09979e;
P_0c09979c: /* original e500, guest PC 0x0c09979c */
if(!s->budget--) { s->failed_pc=0x0c09979cu; return 0; }
r[5]=0x00000000u;
goto P_0c09979e;
P_0c09979e: /* original d358, guest PC 0x0c09979e */
if(!s->budget--) { s->failed_pc=0x0c09979eu; return 0; }
r[3]=read(ram,0x0c099900u,4);
goto P_0c0997a0;
P_0c0997a0: /* original 430b, guest PC 0x0c0997a0 */
if(!s->budget--) { s->failed_pc=0x0c0997a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0997a4u;
r[4]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0997a4u) { target=s->pc; goto dispatch; }
goto P_0c0997a4;
P_0c0997a2: /* original 54d4, guest PC 0x0c0997a2 */
if(!s->budget--) { s->failed_pc=0x0c0997a2u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c0997a4;
P_0c0997a4: /* original d256, guest PC 0x0c0997a4 */
if(!s->budget--) { s->failed_pc=0x0c0997a4u; return 0; }
r[2]=read(ram,0x0c099900u,4);
goto P_0c0997a6;
P_0c0997a6: /* original 420b, guest PC 0x0c0997a6 */
if(!s->budget--) { s->failed_pc=0x0c0997a6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0997aau;
r[4]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0997aau) { target=s->pc; goto dispatch; }
goto P_0c0997aa;
P_0c0997a8: /* original 54d5, guest PC 0x0c0997a8 */
if(!s->budget--) { s->failed_pc=0x0c0997a8u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0997aa;
P_0c0997aa: /* original c756, guest PC 0x0c0997aa */
if(!s->budget--) { s->failed_pc=0x0c0997aau; return 0; }
r[0]=code_base|0x00099904u;
goto P_0c0997ac;
P_0c0997ac: /* original f308, guest PC 0x0c0997ac */
if(!s->budget--) { s->failed_pc=0x0c0997acu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0997ae;
P_0c0997ae: /* original e042, guest PC 0x0c0997ae */
if(!s->budget--) { s->failed_pc=0x0c0997aeu; return 0; }
r[0]=0x00000042u;
goto P_0c0997b0;
P_0c0997b0: /* original fe3a, guest PC 0x0c0997b0 */
if(!s->budget--) { s->failed_pc=0x0c0997b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0997b2;
P_0c0997b2: /* original 938c, guest PC 0x0c0997b2 */
if(!s->budget--) { s->failed_pc=0x0c0997b2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ceu,2);
goto P_0c0997b4;
P_0c0997b4: /* original 52e2, guest PC 0x0c0997b4 */
if(!s->budget--) { s->failed_pc=0x0c0997b4u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0997b6;
P_0c0997b6: /* original 2239, guest PC 0x0c0997b6 */
if(!s->budget--) { s->failed_pc=0x0c0997b6u; return 0; }
r[2]&=r[3];
goto P_0c0997b8;
P_0c0997b8: /* original 1e22, guest PC 0x0c0997b8 */
if(!s->budget--) { s->failed_pc=0x0c0997b8u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0997ba;
P_0c0997ba: /* original 51f2, guest PC 0x0c0997ba */
if(!s->budget--) { s->failed_pc=0x0c0997bau; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0997bc;
P_0c0997bc: /* original 9288, guest PC 0x0c0997bc */
if(!s->budget--) { s->failed_pc=0x0c0997bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d0u,2);
goto P_0c0997be;
P_0c0997be: /* original 0125, guest PC 0x0c0997be */
if(!s->budget--) { s->failed_pc=0x0c0997beu; return 0; }
write(ram,r[1]+r[0],r[2],2);
goto P_0c0997c0;
P_0c0997c0: /* original 0c25, guest PC 0x0c0997c0 */
if(!s->budget--) { s->failed_pc=0x0c0997c0u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c0997c2;
P_0c0997c2: /* original 9086, guest PC 0x0c0997c2 */
if(!s->budget--) { s->failed_pc=0x0c0997c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d2u,2);
goto P_0c0997c4;
P_0c0997c4: /* original 01ed, guest PC 0x0c0997c4 */
if(!s->budget--) { s->failed_pc=0x0c0997c4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0997c6;
P_0c0997c6: /* original e046, guest PC 0x0c0997c6 */
if(!s->budget--) { s->failed_pc=0x0c0997c6u; return 0; }
r[0]=0x00000046u;
goto P_0c0997c8;
P_0c0997c8: /* original 0c15, guest PC 0x0c0997c8 */
if(!s->budget--) { s->failed_pc=0x0c0997c8u; return 0; }
write(ram,r[12]+r[0],r[1],2);
goto P_0c0997ca;
P_0c0997ca: /* original 9083, guest PC 0x0c0997ca */
if(!s->budget--) { s->failed_pc=0x0c0997cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d4u,2);
goto P_0c0997cc;
P_0c0997cc: /* original 52f2, guest PC 0x0c0997cc */
if(!s->budget--) { s->failed_pc=0x0c0997ccu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0997ce;
P_0c0997ce: /* original 01ed, guest PC 0x0c0997ce */
if(!s->budget--) { s->failed_pc=0x0c0997ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0997d0;
P_0c0997d0: /* original e046, guest PC 0x0c0997d0 */
if(!s->budget--) { s->failed_pc=0x0c0997d0u; return 0; }
r[0]=0x00000046u;
goto P_0c0997d2;
P_0c0997d2: /* original 0215, guest PC 0x0c0997d2 */
if(!s->budget--) { s->failed_pc=0x0c0997d2u; return 0; }
write(ram,r[2]+r[0],r[1],2);
goto P_0c0997d4;
P_0c0997d4: /* original 907f, guest PC 0x0c0997d4 */
if(!s->budget--) { s->failed_pc=0x0c0997d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d6u,2);
goto P_0c0997d6;
P_0c0997d6: /* original 02ec, guest PC 0x0c0997d6 */
if(!s->budget--) { s->failed_pc=0x0c0997d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0997d8;
P_0c0997d8: /* original 907e, guest PC 0x0c0997d8 */
if(!s->budget--) { s->failed_pc=0x0c0997d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d8u,2);
goto P_0c0997da;
P_0c0997da: /* original 0c24, guest PC 0x0c0997da */
if(!s->budget--) { s->failed_pc=0x0c0997dau; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c0997dc;
P_0c0997dc: /* original 907d, guest PC 0x0c0997dc */
if(!s->budget--) { s->failed_pc=0x0c0997dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998dau,2);
goto P_0c0997de;
P_0c0997de: /* original 51f2, guest PC 0x0c0997de */
if(!s->budget--) { s->failed_pc=0x0c0997deu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0997e0;
P_0c0997e0: /* original 02ec, guest PC 0x0c0997e0 */
if(!s->budget--) { s->failed_pc=0x0c0997e0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0997e2;
P_0c0997e2: /* original 9079, guest PC 0x0c0997e2 */
if(!s->budget--) { s->failed_pc=0x0c0997e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998d8u,2);
goto P_0c0997e4;
P_0c0997e4: /* original 0124, guest PC 0x0c0997e4 */
if(!s->budget--) { s->failed_pc=0x0c0997e4u; return 0; }
write(ram,r[1]+r[0],r[2],1);
goto P_0c0997e6;
P_0c0997e6: /* original d248, guest PC 0x0c0997e6 */
if(!s->budget--) { s->failed_pc=0x0c0997e6u; return 0; }
r[2]=read(ram,0x0c099908u,4);
goto P_0c0997e8;
P_0c0997e8: /* original 420b, guest PC 0x0c0997e8 */
if(!s->budget--) { s->failed_pc=0x0c0997e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0997ecu;
r[4]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0997ecu) { target=s->pc; goto dispatch; }
goto P_0c0997ec;
P_0c0997ea: /* original 54d6, guest PC 0x0c0997ea */
if(!s->budget--) { s->failed_pc=0x0c0997eau; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0997ec;
P_0c0997ec: /* original 9076, guest PC 0x0c0997ec */
if(!s->budget--) { s->failed_pc=0x0c0997ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998dcu,2);
goto P_0c0997ee;
P_0c0997ee: /* original 04ee, guest PC 0x0c0997ee */
if(!s->budget--) { s->failed_pc=0x0c0997eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0997f0;
P_0c0997f0: /* original e024, guest PC 0x0c0997f0 */
if(!s->budget--) { s->failed_pc=0x0c0997f0u; return 0; }
r[0]=0x00000024u;
goto P_0c0997f2;
P_0c0997f2: /* original f4f7, guest PC 0x0c0997f2 */
if(!s->budget--) { s->failed_pc=0x0c0997f2u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997f4;
P_0c0997f4: /* original e028, guest PC 0x0c0997f4 */
if(!s->budget--) { s->failed_pc=0x0c0997f4u; return 0; }
r[0]=0x00000028u;
goto P_0c0997f6;
P_0c0997f6: /* original f4f7, guest PC 0x0c0997f6 */
if(!s->budget--) { s->failed_pc=0x0c0997f6u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997f8;
P_0c0997f8: /* original e02c, guest PC 0x0c0997f8 */
if(!s->budget--) { s->failed_pc=0x0c0997f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0997fa;
P_0c0997fa: /* original f4f7, guest PC 0x0c0997fa */
if(!s->budget--) { s->failed_pc=0x0c0997fau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c0997fc;
P_0c0997fc: /* original 906f, guest PC 0x0c0997fc */
if(!s->budget--) { s->failed_pc=0x0c0997fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998deu,2);
goto P_0c0997fe;
P_0c0997fe: /* original f4f7, guest PC 0x0c0997fe */
if(!s->budget--) { s->failed_pc=0x0c0997feu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099800;
P_0c099800: /* original 7004, guest PC 0x0c099800 */
if(!s->budget--) { s->failed_pc=0x0c099800u; return 0; }
r[0]+=0x00000004u;
goto P_0c099802;
P_0c099802: /* original f4f7, guest PC 0x0c099802 */
if(!s->budget--) { s->failed_pc=0x0c099802u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099804;
P_0c099804: /* original 906c, guest PC 0x0c099804 */
if(!s->budget--) { s->failed_pc=0x0c099804u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e0u,2);
goto P_0c099806;
P_0c099806: /* original f4f7, guest PC 0x0c099806 */
if(!s->budget--) { s->failed_pc=0x0c099806u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099808;
P_0c099808: /* original 7004, guest PC 0x0c099808 */
if(!s->budget--) { s->failed_pc=0x0c099808u; return 0; }
r[0]+=0x00000004u;
goto P_0c09980a;
P_0c09980a: /* original f4f7, guest PC 0x0c09980a */
if(!s->budget--) { s->failed_pc=0x0c09980au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09980c;
P_0c09980c: /* original 7004, guest PC 0x0c09980c */
if(!s->budget--) { s->failed_pc=0x0c09980cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09980e;
P_0c09980e: /* original f4f7, guest PC 0x0c09980e */
if(!s->budget--) { s->failed_pc=0x0c09980eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099810;
P_0c099810: /* original 9067, guest PC 0x0c099810 */
if(!s->budget--) { s->failed_pc=0x0c099810u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e2u,2);
goto P_0c099812;
P_0c099812: /* original 04ee, guest PC 0x0c099812 */
if(!s->budget--) { s->failed_pc=0x0c099812u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099814;
P_0c099814: /* original e024, guest PC 0x0c099814 */
if(!s->budget--) { s->failed_pc=0x0c099814u; return 0; }
r[0]=0x00000024u;
goto P_0c099816;
P_0c099816: /* original f4f7, guest PC 0x0c099816 */
if(!s->budget--) { s->failed_pc=0x0c099816u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099818;
P_0c099818: /* original e028, guest PC 0x0c099818 */
if(!s->budget--) { s->failed_pc=0x0c099818u; return 0; }
r[0]=0x00000028u;
goto P_0c09981a;
P_0c09981a: /* original f4f7, guest PC 0x0c09981a */
if(!s->budget--) { s->failed_pc=0x0c09981au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09981c;
P_0c09981c: /* original e02c, guest PC 0x0c09981c */
if(!s->budget--) { s->failed_pc=0x0c09981cu; return 0; }
r[0]=0x0000002cu;
goto P_0c09981e;
P_0c09981e: /* original f4f7, guest PC 0x0c09981e */
if(!s->budget--) { s->failed_pc=0x0c09981eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099820;
P_0c099820: /* original 905d, guest PC 0x0c099820 */
if(!s->budget--) { s->failed_pc=0x0c099820u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998deu,2);
goto P_0c099822;
P_0c099822: /* original f4f7, guest PC 0x0c099822 */
if(!s->budget--) { s->failed_pc=0x0c099822u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099824;
P_0c099824: /* original 7004, guest PC 0x0c099824 */
if(!s->budget--) { s->failed_pc=0x0c099824u; return 0; }
r[0]+=0x00000004u;
goto P_0c099826;
P_0c099826: /* original f4f7, guest PC 0x0c099826 */
if(!s->budget--) { s->failed_pc=0x0c099826u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099828;
P_0c099828: /* original 905a, guest PC 0x0c099828 */
if(!s->budget--) { s->failed_pc=0x0c099828u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e0u,2);
goto P_0c09982a;
P_0c09982a: /* original f4f7, guest PC 0x0c09982a */
if(!s->budget--) { s->failed_pc=0x0c09982au; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c09982c;
P_0c09982c: /* original 7004, guest PC 0x0c09982c */
if(!s->budget--) { s->failed_pc=0x0c09982cu; return 0; }
r[0]+=0x00000004u;
goto P_0c09982e;
P_0c09982e: /* original f4f7, guest PC 0x0c09982e */
if(!s->budget--) { s->failed_pc=0x0c09982eu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099830;
P_0c099830: /* original 7004, guest PC 0x0c099830 */
if(!s->budget--) { s->failed_pc=0x0c099830u; return 0; }
r[0]+=0x00000004u;
goto P_0c099832;
P_0c099832: /* original f4f7, guest PC 0x0c099832 */
if(!s->budget--) { s->failed_pc=0x0c099832u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c099834;
P_0c099834: /* original 9055, guest PC 0x0c099834 */
if(!s->budget--) { s->failed_pc=0x0c099834u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e2u,2);
goto P_0c099836;
P_0c099836: /* original 0cee, guest PC 0x0c099836 */
if(!s->budget--) { s->failed_pc=0x0c099836u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099838;
P_0c099838: /* original 9054, guest PC 0x0c099838 */
if(!s->budget--) { s->failed_pc=0x0c099838u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e4u,2);
goto P_0c09983a;
P_0c09983a: /* original 03cd, guest PC 0x0c09983a */
if(!s->budget--) { s->failed_pc=0x0c09983au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09983c;
P_0c09983c: /* original e03c, guest PC 0x0c09983c */
if(!s->budget--) { s->failed_pc=0x0c09983cu; return 0; }
r[0]=0x0000003cu;
goto P_0c09983e;
P_0c09983e: /* original 623d, guest PC 0x0c09983e */
if(!s->budget--) { s->failed_pc=0x0c09983eu; return 0; }
r[2]=r[3]&65535u;
goto P_0c099840;
P_0c099840: /* original 7263, guest PC 0x0c099840 */
if(!s->budget--) { s->failed_pc=0x0c099840u; return 0; }
r[2]+=0x00000063u;
goto P_0c099842;
P_0c099842: /* original 2f22, guest PC 0x0c099842 */
if(!s->budget--) { s->failed_pc=0x0c099842u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099844;
P_0c099844: /* original 6323, guest PC 0x0c099844 */
if(!s->budget--) { s->failed_pc=0x0c099844u; return 0; }
r[3]=r[2];
goto P_0c099846;
P_0c099846: /* original 1b23, guest PC 0x0c099846 */
if(!s->budget--) { s->failed_pc=0x0c099846u; return 0; }
write(ram,r[11]+12,r[2],4);
goto P_0c099848;
P_0c099848: /* original 02cd, guest PC 0x0c099848 */
if(!s->budget--) { s->failed_pc=0x0c099848u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09984a;
P_0c09984a: /* original 934c, guest PC 0x0c09984a */
if(!s->budget--) { s->failed_pc=0x0c09984au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e6u,2);
goto P_0c09984c;
P_0c09984c: /* original 622d, guest PC 0x0c09984c */
if(!s->budget--) { s->failed_pc=0x0c09984cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c09984e;
P_0c09984e: /* original 3230, guest PC 0x0c09984e */
if(!s->budget--) { s->failed_pc=0x0c09984eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099850;
P_0c099850: /* original 8b2f, guest PC 0x0c099850 */
if(!s->budget--) { s->failed_pc=0x0c099850u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099852;
P_0c099852: /* original 9049, guest PC 0x0c099852 */
if(!s->budget--) { s->failed_pc=0x0c099852u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e8u,2);
goto P_0c099854;
P_0c099854: /* original 00ec, guest PC 0x0c099854 */
if(!s->budget--) { s->failed_pc=0x0c099854u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099856;
P_0c099856: /* original 600c, guest PC 0x0c099856 */
if(!s->budget--) { s->failed_pc=0x0c099856u; return 0; }
r[0]=r[0]&255u;
goto P_0c099858;
P_0c099858: /* original 8802, guest PC 0x0c099858 */
if(!s->budget--) { s->failed_pc=0x0c099858u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09985a;
P_0c09985a: /* original 8b2a, guest PC 0x0c09985a */
if(!s->budget--) { s->failed_pc=0x0c09985au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c09985c;
P_0c09985c: /* original e01c, guest PC 0x0c09985c */
if(!s->budget--) { s->failed_pc=0x0c09985cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09985e;
P_0c09985e: /* original 00bc, guest PC 0x0c09985e */
if(!s->budget--) { s->failed_pc=0x0c09985eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099860;
P_0c099860: /* original 600c, guest PC 0x0c099860 */
if(!s->budget--) { s->failed_pc=0x0c099860u; return 0; }
r[0]=r[0]&255u;
goto P_0c099862;
P_0c099862: /* original c90f, guest PC 0x0c099862 */
if(!s->budget--) { s->failed_pc=0x0c099862u; return 0; }
r[0]&=15u;
goto P_0c099864;
P_0c099864: /* original 880e, guest PC 0x0c099864 */
if(!s->budget--) { s->failed_pc=0x0c099864u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c099866;
P_0c099866: /* original 8b24, guest PC 0x0c099866 */
if(!s->budget--) { s->failed_pc=0x0c099866u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099868;
P_0c099868: /* original e060, guest PC 0x0c099868 */
if(!s->budget--) { s->failed_pc=0x0c099868u; return 0; }
r[0]=0x00000060u;
goto P_0c09986a;
P_0c09986a: /* original 00cc, guest PC 0x0c09986a */
if(!s->budget--) { s->failed_pc=0x0c09986au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c09986c;
P_0c09986c: /* original 600c, guest PC 0x0c09986c */
if(!s->budget--) { s->failed_pc=0x0c09986cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09986e;
P_0c09986e: /* original 8810, guest PC 0x0c09986e */
if(!s->budget--) { s->failed_pc=0x0c09986eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c099870;
P_0c099870: /* original 8b1f, guest PC 0x0c099870 */
if(!s->budget--) { s->failed_pc=0x0c099870u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099872;
P_0c099872: /* original e019, guest PC 0x0c099872 */
if(!s->budget--) { s->failed_pc=0x0c099872u; return 0; }
r[0]=0x00000019u;
goto P_0c099874;
P_0c099874: /* original 00ec, guest PC 0x0c099874 */
if(!s->budget--) { s->failed_pc=0x0c099874u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099876;
P_0c099876: /* original 600c, guest PC 0x0c099876 */
if(!s->budget--) { s->failed_pc=0x0c099876u; return 0; }
r[0]=r[0]&255u;
goto P_0c099878;
P_0c099878: /* original 8802, guest PC 0x0c099878 */
if(!s->budget--) { s->failed_pc=0x0c099878u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09987a;
P_0c09987a: /* original 891a, guest PC 0x0c09987a */
if(!s->budget--) { s->failed_pc=0x0c09987au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0998b2; }
goto P_0c09987c;
P_0c09987c: /* original e018, guest PC 0x0c09987c */
if(!s->budget--) { s->failed_pc=0x0c09987cu; return 0; }
r[0]=0x00000018u;
goto P_0c09987e;
P_0c09987e: /* original 03ec, guest PC 0x0c09987e */
if(!s->budget--) { s->failed_pc=0x0c09987eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099880;
P_0c099880: /* original 2338, guest PC 0x0c099880 */
if(!s->budget--) { s->failed_pc=0x0c099880u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099882;
P_0c099882: /* original 8b16, guest PC 0x0c099882 */
if(!s->budget--) { s->failed_pc=0x0c099882u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099884;
P_0c099884: /* original e046, guest PC 0x0c099884 */
if(!s->budget--) { s->failed_pc=0x0c099884u; return 0; }
r[0]=0x00000046u;
goto P_0c099886;
P_0c099886: /* original 02cd, guest PC 0x0c099886 */
if(!s->budget--) { s->failed_pc=0x0c099886u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c099888;
P_0c099888: /* original 902f, guest PC 0x0c099888 */
if(!s->budget--) { s->failed_pc=0x0c099888u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998eau,2);
goto P_0c09988a;
P_0c09988a: /* original 622d, guest PC 0x0c09988a */
if(!s->budget--) { s->failed_pc=0x0c09988au; return 0; }
r[2]=r[2]&65535u;
goto P_0c09988c;
P_0c09988c: /* original 03cd, guest PC 0x0c09988c */
if(!s->budget--) { s->failed_pc=0x0c09988cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09988e;
P_0c09988e: /* original 3230, guest PC 0x0c09988e */
if(!s->budget--) { s->failed_pc=0x0c09988eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099890;
P_0c099890: /* original 8b0f, guest PC 0x0c099890 */
if(!s->budget--) { s->failed_pc=0x0c099890u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0998b2; }
goto P_0c099892;
P_0c099892: /* original 902b, guest PC 0x0c099892 */
if(!s->budget--) { s->failed_pc=0x0c099892u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ecu,2);
goto P_0c099894;
P_0c099894: /* original 03ce, guest PC 0x0c099894 */
if(!s->budget--) { s->failed_pc=0x0c099894u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c099896;
P_0c099896: /* original 1f91, guest PC 0x0c099896 */
if(!s->budget--) { s->failed_pc=0x0c099896u; return 0; }
write(ram,r[15]+4,r[9],4);
goto P_0c099898;
P_0c099898: /* original 9028, guest PC 0x0c099898 */
if(!s->budget--) { s->failed_pc=0x0c099898u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998ecu,2);
goto P_0c09989a;
P_0c09989a: /* original 0c96, guest PC 0x0c09989a */
if(!s->budget--) { s->failed_pc=0x0c09989au; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c09989c;
P_0c09989c: /* original 9022, guest PC 0x0c09989c */
if(!s->budget--) { s->failed_pc=0x0c09989cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998e4u,2);
goto P_0c09989e;
P_0c09989e: /* original 9226, guest PC 0x0c09989e */
if(!s->budget--) { s->failed_pc=0x0c09989eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998eeu,2);
goto P_0c0998a0;
P_0c0998a0: /* original 03cd, guest PC 0x0c0998a0 */
if(!s->budget--) { s->failed_pc=0x0c0998a0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0998a2;
P_0c0998a2: /* original 613d, guest PC 0x0c0998a2 */
if(!s->budget--) { s->failed_pc=0x0c0998a2u; return 0; }
r[1]=r[3]&65535u;
goto P_0c0998a4;
P_0c0998a4: /* original 312c, guest PC 0x0c0998a4 */
if(!s->budget--) { s->failed_pc=0x0c0998a4u; return 0; }
r[1]+=r[2];
goto P_0c0998a6;
P_0c0998a6: /* original 6313, guest PC 0x0c0998a6 */
if(!s->budget--) { s->failed_pc=0x0c0998a6u; return 0; }
r[3]=r[1];
goto P_0c0998a8;
P_0c0998a8: /* original 2f12, guest PC 0x0c0998a8 */
if(!s->budget--) { s->failed_pc=0x0c0998a8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0998aa;
P_0c0998aa: /* original 1b13, guest PC 0x0c0998aa */
if(!s->budget--) { s->failed_pc=0x0c0998aau; return 0; }
write(ram,r[11]+12,r[1],4);
goto P_0c0998ac;
P_0c0998ac: /* original d117, guest PC 0x0c0998ac */
if(!s->budget--) { s->failed_pc=0x0c0998acu; return 0; }
r[1]=read(ram,0x0c09990cu,4);
goto P_0c0998ae;
P_0c0998ae: /* original 410b, guest PC 0x0c0998ae */
if(!s->budget--) { s->failed_pc=0x0c0998aeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0998b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0998b2u) { target=s->pc; goto dispatch; }
goto P_0c0998b2;
P_0c0998b0: /* original 0009, guest PC 0x0c0998b0 */
if(!s->budget--) { s->failed_pc=0x0c0998b0u; return 0; }
goto P_0c0998b2;
P_0c0998b2: /* original e054, guest PC 0x0c0998b2 */
if(!s->budget--) { s->failed_pc=0x0c0998b2u; return 0; }
r[0]=0x00000054u;
goto P_0c0998b4;
P_0c0998b4: /* original 02ce, guest PC 0x0c0998b4 */
if(!s->budget--) { s->failed_pc=0x0c0998b4u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0998b6;
P_0c0998b6: /* original e022, guest PC 0x0c0998b6 */
if(!s->budget--) { s->failed_pc=0x0c0998b6u; return 0; }
r[0]=0x00000022u;
goto P_0c0998b8;
P_0c0998b8: /* original 6323, guest PC 0x0c0998b8 */
if(!s->budget--) { s->failed_pc=0x0c0998b8u; return 0; }
r[3]=r[2];
goto P_0c0998ba;
P_0c0998ba: /* original 1f22, guest PC 0x0c0998ba */
if(!s->budget--) { s->failed_pc=0x0c0998bau; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0998bc;
P_0c0998bc: /* original 023d, guest PC 0x0c0998bc */
if(!s->budget--) { s->failed_pc=0x0c0998bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0998be;
P_0c0998be: /* original 9017, guest PC 0x0c0998be */
if(!s->budget--) { s->failed_pc=0x0c0998beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0998f0u,2);
goto P_0c0998c0;
P_0c0998c0: /* original 7208, guest PC 0x0c0998c0 */
if(!s->budget--) { s->failed_pc=0x0c0998c0u; return 0; }
r[2]+=0x00000008u;
goto P_0c0998c2;
P_0c0998c2: /* original 0c25, guest PC 0x0c0998c2 */
if(!s->budget--) { s->failed_pc=0x0c0998c2u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c0998c4;
P_0c0998c4: /* original 84c4, guest PC 0x0c0998c4 */
if(!s->budget--) { s->failed_pc=0x0c0998c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+4,1);
goto P_0c0998c6;
P_0c0998c6: /* original 2008, guest PC 0x0c0998c6 */
if(!s->budget--) { s->failed_pc=0x0c0998c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0998c8;
P_0c0998c8: /* original a022, guest PC 0x0c0998c8 */
if(!s->budget--) { s->failed_pc=0x0c0998c8u; return 0; }
goto P_0c099910;
P_0c0998ca: /* original 0009, guest PC 0x0c0998ca */
if(!s->budget--) { s->failed_pc=0x0c0998cau; return 0; }
if(!vf3_matrix_family(0x0c0998ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0998ccu; return 0; } return 1;
P_0c099910: /* original 8b07, guest PC 0x0c099910 */
if(!s->budget--) { s->failed_pc=0x0c099910u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099922; }
goto P_0c099912;
P_0c099912: /* original d33c, guest PC 0x0c099912 */
if(!s->budget--) { s->failed_pc=0x0c099912u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099914;
P_0c099914: /* original e060, guest PC 0x0c099914 */
if(!s->budget--) { s->failed_pc=0x0c099914u; return 0; }
r[0]=0x00000060u;
goto P_0c099916;
P_0c099916: /* original d53a, guest PC 0x0c099916 */
if(!s->budget--) { s->failed_pc=0x0c099916u; return 0; }
r[5]=read(ram,0x0c099a00u,4);
goto P_0c099918;
P_0c099918: /* original 430b, guest PC 0x0c099918 */
if(!s->budget--) { s->failed_pc=0x0c099918u; return 0; }
target=r[3];
r[16]=code_base|0x0c09991cu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09991cu) { target=s->pc; goto dispatch; }
goto P_0c09991c;
P_0c09991a: /* original 04de, guest PC 0x0c09991a */
if(!s->budget--) { s->failed_pc=0x0c09991au; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09991c;
P_0c09991c: /* original d53a, guest PC 0x0c09991c */
if(!s->budget--) { s->failed_pc=0x0c09991cu; return 0; }
r[5]=read(ram,0x0c099a08u,4);
goto P_0c09991e;
P_0c09991e: /* original a007, guest PC 0x0c09991e */
if(!s->budget--) { s->failed_pc=0x0c09991eu; return 0; }
r[0]=0x00000068u;
goto P_0c099930;
P_0c099920: /* original e068, guest PC 0x0c099920 */
if(!s->budget--) { s->failed_pc=0x0c099920u; return 0; }
r[0]=0x00000068u;
goto P_0c099922;
P_0c099922: /* original d338, guest PC 0x0c099922 */
if(!s->budget--) { s->failed_pc=0x0c099922u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099924;
P_0c099924: /* original e064, guest PC 0x0c099924 */
if(!s->budget--) { s->failed_pc=0x0c099924u; return 0; }
r[0]=0x00000064u;
goto P_0c099926;
P_0c099926: /* original d536, guest PC 0x0c099926 */
if(!s->budget--) { s->failed_pc=0x0c099926u; return 0; }
r[5]=read(ram,0x0c099a00u,4);
goto P_0c099928;
P_0c099928: /* original 430b, guest PC 0x0c099928 */
if(!s->budget--) { s->failed_pc=0x0c099928u; return 0; }
target=r[3];
r[16]=code_base|0x0c09992cu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09992cu) { target=s->pc; goto dispatch; }
goto P_0c09992c;
P_0c09992a: /* original 04de, guest PC 0x0c09992a */
if(!s->budget--) { s->failed_pc=0x0c09992au; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09992c;
P_0c09992c: /* original d536, guest PC 0x0c09992c */
if(!s->budget--) { s->failed_pc=0x0c09992cu; return 0; }
r[5]=read(ram,0x0c099a08u,4);
goto P_0c09992e;
P_0c09992e: /* original e06c, guest PC 0x0c09992e */
if(!s->budget--) { s->failed_pc=0x0c09992eu; return 0; }
r[0]=0x0000006cu;
goto P_0c099930;
P_0c099930: /* original d334, guest PC 0x0c099930 */
if(!s->budget--) { s->failed_pc=0x0c099930u; return 0; }
r[3]=read(ram,0x0c099a04u,4);
goto P_0c099932;
P_0c099932: /* original 430b, guest PC 0x0c099932 */
if(!s->budget--) { s->failed_pc=0x0c099932u; return 0; }
target=r[3];
r[16]=code_base|0x0c099936u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099936u) { target=s->pc; goto dispatch; }
goto P_0c099936;
P_0c099934: /* original 04de, guest PC 0x0c099934 */
if(!s->budget--) { s->failed_pc=0x0c099934u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099936;
P_0c099936: /* original 9061, guest PC 0x0c099936 */
if(!s->budget--) { s->failed_pc=0x0c099936u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999fcu,2);
goto P_0c099938;
P_0c099938: /* original d634, guest PC 0x0c099938 */
if(!s->budget--) { s->failed_pc=0x0c099938u; return 0; }
r[6]=read(ram,0x0c099a0cu,4);
goto P_0c09993a;
P_0c09993a: /* original 04cd, guest PC 0x0c09993a */
if(!s->budget--) { s->failed_pc=0x0c09993au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c09993c;
P_0c09993c: /* original 6543, guest PC 0x0c09993c */
if(!s->budget--) { s->failed_pc=0x0c09993cu; return 0; }
r[5]=r[4];
goto P_0c09993e;
P_0c09993e: /* original 75f9, guest PC 0x0c09993e */
if(!s->budget--) { s->failed_pc=0x0c09993eu; return 0; }
r[5]+=0xfffffff9u;
goto P_0c099940;
P_0c099940: /* original 6053, guest PC 0x0c099940 */
if(!s->budget--) { s->failed_pc=0x0c099940u; return 0; }
r[0]=r[5];
goto P_0c099942;
P_0c099942: /* original 4008, guest PC 0x0c099942 */
if(!s->budget--) { s->failed_pc=0x0c099942u; return 0; }
r[0]<<=2;
goto P_0c099944;
P_0c099944: /* original 056e, guest PC 0x0c099944 */
if(!s->budget--) { s->failed_pc=0x0c099944u; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c099946;
P_0c099946: /* original 6043, guest PC 0x0c099946 */
if(!s->budget--) { s->failed_pc=0x0c099946u; return 0; }
r[0]=r[4];
goto P_0c099948;
P_0c099948: /* original 4008, guest PC 0x0c099948 */
if(!s->budget--) { s->failed_pc=0x0c099948u; return 0; }
r[0]<<=2;
goto P_0c09994a;
P_0c09994a: /* original 2558, guest PC 0x0c09994a */
if(!s->budget--) { s->failed_pc=0x0c09994au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09994c;
P_0c09994c: /* original 8d08, guest PC 0x0c09994c */
if(!s->budget--) { s->failed_pc=0x0c09994cu; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[6]+r[0],4);
if(cond) { goto P_0c099960; }
goto P_0c099950;
P_0c09994e: /* original 046e, guest PC 0x0c09994e */
if(!s->budget--) { s->failed_pc=0x0c09994eu; return 0; }
r[4]=read(ram,r[6]+r[0],4);
goto P_0c099950;
P_0c099950: /* original 5551, guest PC 0x0c099950 */
if(!s->budget--) { s->failed_pc=0x0c099950u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c099952;
P_0c099952: /* original 2558, guest PC 0x0c099952 */
if(!s->budget--) { s->failed_pc=0x0c099952u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c099954;
P_0c099954: /* original 8904, guest PC 0x0c099954 */
if(!s->budget--) { s->failed_pc=0x0c099954u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099960; }
goto P_0c099956;
P_0c099956: /* original 5652, guest PC 0x0c099956 */
if(!s->budget--) { s->failed_pc=0x0c099956u; return 0; }
r[6]=read(ram,r[5]+8,4);
goto P_0c099958;
P_0c099958: /* original 2448, guest PC 0x0c099958 */
if(!s->budget--) { s->failed_pc=0x0c099958u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09995a;
P_0c09995a: /* original 8901, guest PC 0x0c09995a */
if(!s->budget--) { s->failed_pc=0x0c09995au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099960; }
goto P_0c09995c;
P_0c09995c: /* original a00e, guest PC 0x0c09995c */
if(!s->budget--) { s->failed_pc=0x0c09995cu; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c09997c;
P_0c09995e: /* original 5741, guest PC 0x0c09995e */
if(!s->budget--) { s->failed_pc=0x0c09995eu; return 0; }
r[7]=read(ram,r[4]+4,4);
goto P_0c099960;
P_0c099960: /* original d32b, guest PC 0x0c099960 */
if(!s->budget--) { s->failed_pc=0x0c099960u; return 0; }
r[3]=read(ram,0x0c099a10u,4);
goto P_0c099962;
P_0c099962: /* original e060, guest PC 0x0c099962 */
if(!s->budget--) { s->failed_pc=0x0c099962u; return 0; }
r[0]=0x00000060u;
goto P_0c099964;
P_0c099964: /* original 430b, guest PC 0x0c099964 */
if(!s->budget--) { s->failed_pc=0x0c099964u; return 0; }
target=r[3];
r[16]=code_base|0x0c099968u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099968u) { target=s->pc; goto dispatch; }
goto P_0c099968;
P_0c099966: /* original 04de, guest PC 0x0c099966 */
if(!s->budget--) { s->failed_pc=0x0c099966u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099968;
P_0c099968: /* original d329, guest PC 0x0c099968 */
if(!s->budget--) { s->failed_pc=0x0c099968u; return 0; }
r[3]=read(ram,0x0c099a10u,4);
goto P_0c09996a;
P_0c09996a: /* original e064, guest PC 0x0c09996a */
if(!s->budget--) { s->failed_pc=0x0c09996au; return 0; }
r[0]=0x00000064u;
goto P_0c09996c;
P_0c09996c: /* original 430b, guest PC 0x0c09996c */
if(!s->budget--) { s->failed_pc=0x0c09996cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099970u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099970u) { target=s->pc; goto dispatch; }
goto P_0c099970;
P_0c09996e: /* original 04de, guest PC 0x0c09996e */
if(!s->budget--) { s->failed_pc=0x0c09996eu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099970;
P_0c099970: /* original 52f2, guest PC 0x0c099970 */
if(!s->budget--) { s->failed_pc=0x0c099970u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c099972;
P_0c099972: /* original e022, guest PC 0x0c099972 */
if(!s->budget--) { s->failed_pc=0x0c099972u; return 0; }
r[0]=0x00000022u;
goto P_0c099974;
P_0c099974: /* original 032d, guest PC 0x0c099974 */
if(!s->budget--) { s->failed_pc=0x0c099974u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c099976;
P_0c099976: /* original 9041, guest PC 0x0c099976 */
if(!s->budget--) { s->failed_pc=0x0c099976u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999fcu,2);
goto P_0c099978;
P_0c099978: /* original a019, guest PC 0x0c099978 */
if(!s->budget--) { s->failed_pc=0x0c099978u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c0999ae;
P_0c09997a: /* original 0c35, guest PC 0x0c09997a */
if(!s->budget--) { s->failed_pc=0x0c09997au; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c09997c;
P_0c09997c: /* original 5451, guest PC 0x0c09997c */
if(!s->budget--) { s->failed_pc=0x0c09997cu; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c09997e;
P_0c09997e: /* original 4615, guest PC 0x0c09997e */
if(!s->budget--) { s->failed_pc=0x0c09997eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c099980;
P_0c099980: /* original 8f15, guest PC 0x0c099980 */
if(!s->budget--) { s->failed_pc=0x0c099980u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[7]+4,4);
if(!cond) { goto P_0c0999ae; }
goto P_0c099984;
P_0c099982: /* original 5571, guest PC 0x0c099982 */
if(!s->budget--) { s->failed_pc=0x0c099982u; return 0; }
r[5]=read(ram,r[7]+4,4);
goto P_0c099984;
P_0c099984: /* original f349, guest PC 0x0c099984 */
if(!s->budget--) { s->failed_pc=0x0c099984u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099986;
P_0c099986: /* original 76ff, guest PC 0x0c099986 */
if(!s->budget--) { s->failed_pc=0x0c099986u; return 0; }
r[6]+=0xffffffffu;
goto P_0c099988;
P_0c099988: /* original 4615, guest PC 0x0c099988 */
if(!s->budget--) { s->failed_pc=0x0c099988u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c09998a;
P_0c09998a: /* original f53a, guest PC 0x0c09998a */
if(!s->budget--) { s->failed_pc=0x0c09998au; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c09998c;
P_0c09998c: /* original 7504, guest PC 0x0c09998c */
if(!s->budget--) { s->failed_pc=0x0c09998cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09998e;
P_0c09998e: /* original f349, guest PC 0x0c09998e */
if(!s->budget--) { s->failed_pc=0x0c09998eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099990;
P_0c099990: /* original f53a, guest PC 0x0c099990 */
if(!s->budget--) { s->failed_pc=0x0c099990u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c099992;
P_0c099992: /* original 7504, guest PC 0x0c099992 */
if(!s->budget--) { s->failed_pc=0x0c099992u; return 0; }
r[5]+=0x00000004u;
goto P_0c099994;
P_0c099994: /* original f349, guest PC 0x0c099994 */
if(!s->budget--) { s->failed_pc=0x0c099994u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c099996;
P_0c099996: /* original f53a, guest PC 0x0c099996 */
if(!s->budget--) { s->failed_pc=0x0c099996u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c099998;
P_0c099998: /* original 7504, guest PC 0x0c099998 */
if(!s->budget--) { s->failed_pc=0x0c099998u; return 0; }
r[5]+=0x00000004u;
goto P_0c09999a;
P_0c09999a: /* original f349, guest PC 0x0c09999a */
if(!s->budget--) { s->failed_pc=0x0c09999au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09999c;
P_0c09999c: /* original f53a, guest PC 0x0c09999c */
if(!s->budget--) { s->failed_pc=0x0c09999cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c09999e;
P_0c09999e: /* original 7504, guest PC 0x0c09999e */
if(!s->budget--) { s->failed_pc=0x0c09999eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0999a0;
P_0c0999a0: /* original f349, guest PC 0x0c0999a0 */
if(!s->budget--) { s->failed_pc=0x0c0999a0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0999a2;
P_0c0999a2: /* original f53a, guest PC 0x0c0999a2 */
if(!s->budget--) { s->failed_pc=0x0c0999a2u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0999a4;
P_0c0999a4: /* original 7504, guest PC 0x0c0999a4 */
if(!s->budget--) { s->failed_pc=0x0c0999a4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0999a6;
P_0c0999a6: /* original f349, guest PC 0x0c0999a6 */
if(!s->budget--) { s->failed_pc=0x0c0999a6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0999a8;
P_0c0999a8: /* original f53a, guest PC 0x0c0999a8 */
if(!s->budget--) { s->failed_pc=0x0c0999a8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0999aa;
P_0c0999aa: /* original 8deb, guest PC 0x0c0999aa */
if(!s->budget--) { s->failed_pc=0x0c0999aau; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c099984; }
goto P_0c0999ae;
P_0c0999ac: /* original 7504, guest PC 0x0c0999ac */
if(!s->budget--) { s->failed_pc=0x0c0999acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0999ae;
P_0c0999ae: /* original e010, guest PC 0x0c0999ae */
if(!s->budget--) { s->failed_pc=0x0c0999aeu; return 0; }
r[0]=0x00000010u;
goto P_0c0999b0;
P_0c0999b0: /* original e221, guest PC 0x0c0999b0 */
if(!s->budget--) { s->failed_pc=0x0c0999b0u; return 0; }
r[2]=0x00000021u;
goto P_0c0999b2;
P_0c0999b2: /* original 0b24, guest PC 0x0c0999b2 */
if(!s->budget--) { s->failed_pc=0x0c0999b2u; return 0; }
write(ram,r[11]+r[0],r[2],1);
goto P_0c0999b4;
P_0c0999b4: /* original 9023, guest PC 0x0c0999b4 */
if(!s->budget--) { s->failed_pc=0x0c0999b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0999feu,2);
goto P_0c0999b6;
P_0c0999b6: /* original 54d8, guest PC 0x0c0999b6 */
if(!s->budget--) { s->failed_pc=0x0c0999b6u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c0999b8;
P_0c0999b8: /* original 0494, guest PC 0x0c0999b8 */
if(!s->budget--) { s->failed_pc=0x0c0999b8u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0999ba;
P_0c0999ba: /* original 53e2, guest PC 0x0c0999ba */
if(!s->budget--) { s->failed_pc=0x0c0999bau; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0999bc;
P_0c0999bc: /* original 2388, guest PC 0x0c0999bc */
if(!s->budget--) { s->failed_pc=0x0c0999bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0999be;
P_0c0999be: /* original 8903, guest PC 0x0c0999be */
if(!s->budget--) { s->failed_pc=0x0c0999beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0999c8; }
goto P_0c0999c0;
P_0c0999c0: /* original 0494, guest PC 0x0c0999c0 */
if(!s->budget--) { s->failed_pc=0x0c0999c0u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0999c2;
P_0c0999c2: /* original d314, guest PC 0x0c0999c2 */
if(!s->budget--) { s->failed_pc=0x0c0999c2u; return 0; }
r[3]=read(ram,0x0c099a14u,4);
goto P_0c0999c4;
P_0c0999c4: /* original 430b, guest PC 0x0c0999c4 */
if(!s->budget--) { s->failed_pc=0x0c0999c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0999c8u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0999c8u) { target=s->pc; goto dispatch; }
goto P_0c0999c8;
P_0c0999c6: /* original e408, guest PC 0x0c0999c6 */
if(!s->budget--) { s->failed_pc=0x0c0999c6u; return 0; }
r[4]=0x00000008u;
goto P_0c0999c8;
P_0c0999c8: /* original e029, guest PC 0x0c0999c8 */
if(!s->budget--) { s->failed_pc=0x0c0999c8u; return 0; }
r[0]=0x00000029u;
goto P_0c0999ca;
P_0c0999ca: /* original 00ec, guest PC 0x0c0999ca */
if(!s->budget--) { s->failed_pc=0x0c0999cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999cc;
P_0c0999cc: /* original 600c, guest PC 0x0c0999cc */
if(!s->budget--) { s->failed_pc=0x0c0999ccu; return 0; }
r[0]=r[0]&255u;
goto P_0c0999ce;
P_0c0999ce: /* original 8803, guest PC 0x0c0999ce */
if(!s->budget--) { s->failed_pc=0x0c0999ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0999d0;
P_0c0999d0: /* original 8b01, guest PC 0x0c0999d0 */
if(!s->budget--) { s->failed_pc=0x0c0999d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999d6; }
goto P_0c0999d2;
P_0c0999d2: /* original a0fe, guest PC 0x0c0999d2 */
if(!s->budget--) { s->failed_pc=0x0c0999d2u; return 0; }
goto P_0c099bd2;
P_0c0999d4: /* original 0009, guest PC 0x0c0999d4 */
if(!s->budget--) { s->failed_pc=0x0c0999d4u; return 0; }
goto P_0c0999d6;
P_0c0999d6: /* original 53e2, guest PC 0x0c0999d6 */
if(!s->budget--) { s->failed_pc=0x0c0999d6u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0999d8;
P_0c0999d8: /* original 2388, guest PC 0x0c0999d8 */
if(!s->budget--) { s->failed_pc=0x0c0999d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0999da;
P_0c0999da: /* original 8b01, guest PC 0x0c0999da */
if(!s->budget--) { s->failed_pc=0x0c0999dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999e0; }
goto P_0c0999dc;
P_0c0999dc: /* original a0f9, guest PC 0x0c0999dc */
if(!s->budget--) { s->failed_pc=0x0c0999dcu; return 0; }
goto P_0c099bd2;
P_0c0999de: /* original 0009, guest PC 0x0c0999de */
if(!s->budget--) { s->failed_pc=0x0c0999deu; return 0; }
goto P_0c0999e0;
P_0c0999e0: /* original e029, guest PC 0x0c0999e0 */
if(!s->budget--) { s->failed_pc=0x0c0999e0u; return 0; }
r[0]=0x00000029u;
goto P_0c0999e2;
P_0c0999e2: /* original 00ec, guest PC 0x0c0999e2 */
if(!s->budget--) { s->failed_pc=0x0c0999e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999e4;
P_0c0999e4: /* original 600c, guest PC 0x0c0999e4 */
if(!s->budget--) { s->failed_pc=0x0c0999e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0999e6;
P_0c0999e6: /* original 8801, guest PC 0x0c0999e6 */
if(!s->budget--) { s->failed_pc=0x0c0999e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0999e8;
P_0c0999e8: /* original 8916, guest PC 0x0c0999e8 */
if(!s->budget--) { s->failed_pc=0x0c0999e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099a18; }
goto P_0c0999ea;
P_0c0999ea: /* original e01d, guest PC 0x0c0999ea */
if(!s->budget--) { s->failed_pc=0x0c0999eau; return 0; }
r[0]=0x0000001du;
goto P_0c0999ec;
P_0c0999ec: /* original 00ec, guest PC 0x0c0999ec */
if(!s->budget--) { s->failed_pc=0x0c0999ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0999ee;
P_0c0999ee: /* original 600c, guest PC 0x0c0999ee */
if(!s->budget--) { s->failed_pc=0x0c0999eeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0999f0;
P_0c0999f0: /* original 8801, guest PC 0x0c0999f0 */
if(!s->budget--) { s->failed_pc=0x0c0999f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0999f2;
P_0c0999f2: /* original 8b01, guest PC 0x0c0999f2 */
if(!s->budget--) { s->failed_pc=0x0c0999f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0999f8; }
goto P_0c0999f4;
P_0c0999f4: /* original a0ed, guest PC 0x0c0999f4 */
if(!s->budget--) { s->failed_pc=0x0c0999f4u; return 0; }
goto P_0c099bd2;
P_0c0999f6: /* original 0009, guest PC 0x0c0999f6 */
if(!s->budget--) { s->failed_pc=0x0c0999f6u; return 0; }
goto P_0c0999f8;
P_0c0999f8: /* original a014, guest PC 0x0c0999f8 */
if(!s->budget--) { s->failed_pc=0x0c0999f8u; return 0; }
goto P_0c099a24;
P_0c0999fa: /* original 0009, guest PC 0x0c0999fa */
if(!s->budget--) { s->failed_pc=0x0c0999fau; return 0; }
if(!vf3_matrix_family(0x0c0999fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0999fcu; return 0; } return 1;
P_0c099a18: /* original e01d, guest PC 0x0c099a18 */
if(!s->budget--) { s->failed_pc=0x0c099a18u; return 0; }
r[0]=0x0000001du;
goto P_0c099a1a;
P_0c099a1a: /* original 02ec, guest PC 0x0c099a1a */
if(!s->budget--) { s->failed_pc=0x0c099a1au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099a1c;
P_0c099a1c: /* original 2228, guest PC 0x0c099a1c */
if(!s->budget--) { s->failed_pc=0x0c099a1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099a1e;
P_0c099a1e: /* original 8b01, guest PC 0x0c099a1e */
if(!s->budget--) { s->failed_pc=0x0c099a1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099a24; }
goto P_0c099a20;
P_0c099a20: /* original a0d7, guest PC 0x0c099a20 */
if(!s->budget--) { s->failed_pc=0x0c099a20u; return 0; }
goto P_0c099bd2;
P_0c099a22: /* original 0009, guest PC 0x0c099a22 */
if(!s->budget--) { s->failed_pc=0x0c099a22u; return 0; }
goto P_0c099a24;
P_0c099a24: /* original 90a5, guest PC 0x0c099a24 */
if(!s->budget--) { s->failed_pc=0x0c099a24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b72u,2);
goto P_0c099a26;
P_0c099a26: /* original 0cee, guest PC 0x0c099a26 */
if(!s->budget--) { s->failed_pc=0x0c099a26u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099a28;
P_0c099a28: /* original e018, guest PC 0x0c099a28 */
if(!s->budget--) { s->failed_pc=0x0c099a28u; return 0; }
r[0]=0x00000018u;
goto P_0c099a2a;
P_0c099a2a: /* original 00ec, guest PC 0x0c099a2a */
if(!s->budget--) { s->failed_pc=0x0c099a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099a2c;
P_0c099a2c: /* original 600c, guest PC 0x0c099a2c */
if(!s->budget--) { s->failed_pc=0x0c099a2cu; return 0; }
r[0]=r[0]&255u;
goto P_0c099a2e;
P_0c099a2e: /* original 8802, guest PC 0x0c099a2e */
if(!s->budget--) { s->failed_pc=0x0c099a2eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099a30;
P_0c099a30: /* original 8926, guest PC 0x0c099a30 */
if(!s->budget--) { s->failed_pc=0x0c099a30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099a80; }
goto P_0c099a32;
P_0c099a32: /* original e046, guest PC 0x0c099a32 */
if(!s->budget--) { s->failed_pc=0x0c099a32u; return 0; }
r[0]=0x00000046u;
goto P_0c099a34;
P_0c099a34: /* original 0ca5, guest PC 0x0c099a34 */
if(!s->budget--) { s->failed_pc=0x0c099a34u; return 0; }
write(ram,r[12]+r[0],r[10],2);
goto P_0c099a36;
P_0c099a36: /* original e024, guest PC 0x0c099a36 */
if(!s->budget--) { s->failed_pc=0x0c099a36u; return 0; }
r[0]=0x00000024u;
goto P_0c099a38;
P_0c099a38: /* original fcf7, guest PC 0x0c099a38 */
if(!s->budget--) { s->failed_pc=0x0c099a38u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a3a;
P_0c099a3a: /* original e02c, guest PC 0x0c099a3a */
if(!s->budget--) { s->failed_pc=0x0c099a3au; return 0; }
r[0]=0x0000002cu;
goto P_0c099a3c;
P_0c099a3c: /* original fcf7, guest PC 0x0c099a3c */
if(!s->budget--) { s->failed_pc=0x0c099a3cu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a3e;
P_0c099a3e: /* original 9099, guest PC 0x0c099a3e */
if(!s->budget--) { s->failed_pc=0x0c099a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b74u,2);
goto P_0c099a40;
P_0c099a40: /* original fcf7, guest PC 0x0c099a40 */
if(!s->budget--) { s->failed_pc=0x0c099a40u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a42;
P_0c099a42: /* original 7004, guest PC 0x0c099a42 */
if(!s->budget--) { s->failed_pc=0x0c099a42u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a44;
P_0c099a44: /* original fcf7, guest PC 0x0c099a44 */
if(!s->budget--) { s->failed_pc=0x0c099a44u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a46;
P_0c099a46: /* original 7004, guest PC 0x0c099a46 */
if(!s->budget--) { s->failed_pc=0x0c099a46u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a48;
P_0c099a48: /* original fcf7, guest PC 0x0c099a48 */
if(!s->budget--) { s->failed_pc=0x0c099a48u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099a4a;
P_0c099a4a: /* original e058, guest PC 0x0c099a4a */
if(!s->budget--) { s->failed_pc=0x0c099a4au; return 0; }
r[0]=0x00000058u;
goto P_0c099a4c;
P_0c099a4c: /* original 63c2, guest PC 0x0c099a4c */
if(!s->budget--) { s->failed_pc=0x0c099a4cu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c099a4e;
P_0c099a4e: /* original 1f31, guest PC 0x0c099a4e */
if(!s->budget--) { s->failed_pc=0x0c099a4eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099a50;
P_0c099a50: /* original 52f1, guest PC 0x0c099a50 */
if(!s->budget--) { s->failed_pc=0x0c099a50u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099a52;
P_0c099a52: /* original d34c, guest PC 0x0c099a52 */
if(!s->budget--) { s->failed_pc=0x0c099a52u; return 0; }
r[3]=read(ram,0x0c099b84u,4);
goto P_0c099a54;
P_0c099a54: /* original 223b, guest PC 0x0c099a54 */
if(!s->budget--) { s->failed_pc=0x0c099a54u; return 0; }
r[2]|=r[3];
goto P_0c099a56;
P_0c099a56: /* original 1f21, guest PC 0x0c099a56 */
if(!s->budget--) { s->failed_pc=0x0c099a56u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c099a58;
P_0c099a58: /* original 6123, guest PC 0x0c099a58 */
if(!s->budget--) { s->failed_pc=0x0c099a58u; return 0; }
r[1]=r[2];
goto P_0c099a5a;
P_0c099a5a: /* original 2c22, guest PC 0x0c099a5a */
if(!s->budget--) { s->failed_pc=0x0c099a5au; return 0; }
write(ram,r[12],r[2],4);
goto P_0c099a5c;
P_0c099a5c: /* original 04ce, guest PC 0x0c099a5c */
if(!s->budget--) { s->failed_pc=0x0c099a5cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099a5e;
P_0c099a5e: /* original e048, guest PC 0x0c099a5e */
if(!s->budget--) { s->failed_pc=0x0c099a5eu; return 0; }
r[0]=0x00000048u;
goto P_0c099a60;
P_0c099a60: /* original 01ce, guest PC 0x0c099a60 */
if(!s->budget--) { s->failed_pc=0x0c099a60u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c099a62;
P_0c099a62: /* original d249, guest PC 0x0c099a62 */
if(!s->budget--) { s->failed_pc=0x0c099a62u; return 0; }
r[2]=read(ram,0x0c099b88u,4);
goto P_0c099a64;
P_0c099a64: /* original 7452, guest PC 0x0c099a64 */
if(!s->budget--) { s->failed_pc=0x0c099a64u; return 0; }
r[4]+=0x00000052u;
goto P_0c099a66;
P_0c099a66: /* original 2128, guest PC 0x0c099a66 */
if(!s->budget--) { s->failed_pc=0x0c099a66u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c099a68;
P_0c099a68: /* original 8d04, guest PC 0x0c099a68 */
if(!s->budget--) { s->failed_pc=0x0c099a68u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
if(cond) { goto P_0c099a74; }
goto P_0c099a6c;
P_0c099a6a: /* original 6441, guest PC 0x0c099a6a */
if(!s->budget--) { s->failed_pc=0x0c099a6au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c099a6c;
P_0c099a6c: /* original e058, guest PC 0x0c099a6c */
if(!s->budget--) { s->failed_pc=0x0c099a6cu; return 0; }
r[0]=0x00000058u;
goto P_0c099a6e;
P_0c099a6e: /* original 04ce, guest PC 0x0c099a6e */
if(!s->budget--) { s->failed_pc=0x0c099a6eu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099a70;
P_0c099a70: /* original 7454, guest PC 0x0c099a70 */
if(!s->budget--) { s->failed_pc=0x0c099a70u; return 0; }
r[4]+=0x00000054u;
goto P_0c099a72;
P_0c099a72: /* original 6441, guest PC 0x0c099a72 */
if(!s->budget--) { s->failed_pc=0x0c099a72u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c099a74;
P_0c099a74: /* original e03c, guest PC 0x0c099a74 */
if(!s->budget--) { s->failed_pc=0x0c099a74u; return 0; }
r[0]=0x0000003cu;
goto P_0c099a76;
P_0c099a76: /* original 0c45, guest PC 0x0c099a76 */
if(!s->budget--) { s->failed_pc=0x0c099a76u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c099a78;
P_0c099a78: /* original e301, guest PC 0x0c099a78 */
if(!s->budget--) { s->failed_pc=0x0c099a78u; return 0; }
r[3]=0x00000001u;
goto P_0c099a7a;
P_0c099a7a: /* original e03e, guest PC 0x0c099a7a */
if(!s->budget--) { s->failed_pc=0x0c099a7au; return 0; }
r[0]=0x0000003eu;
goto P_0c099a7c;
P_0c099a7c: /* original 1c4d, guest PC 0x0c099a7c */
if(!s->budget--) { s->failed_pc=0x0c099a7cu; return 0; }
write(ram,r[12]+52,r[4],4);
goto P_0c099a7e;
P_0c099a7e: /* original 0c35, guest PC 0x0c099a7e */
if(!s->budget--) { s->failed_pc=0x0c099a7eu; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c099a80;
P_0c099a80: /* original 9079, guest PC 0x0c099a80 */
if(!s->budget--) { s->failed_pc=0x0c099a80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b76u,2);
goto P_0c099a82;
P_0c099a82: /* original f4e6, guest PC 0x0c099a82 */
if(!s->budget--) { s->failed_pc=0x0c099a82u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c099a84;
P_0c099a84: /* original 7004, guest PC 0x0c099a84 */
if(!s->budget--) { s->failed_pc=0x0c099a84u; return 0; }
r[0]+=0x00000004u;
goto P_0c099a86;
P_0c099a86: /* original fee6, guest PC 0x0c099a86 */
if(!s->budget--) { s->failed_pc=0x0c099a86u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c099a88;
P_0c099a88: /* original e010, guest PC 0x0c099a88 */
if(!s->budget--) { s->failed_pc=0x0c099a88u; return 0; }
r[0]=0x00000010u;
goto P_0c099a8a;
P_0c099a8a: /* original fc47, guest PC 0x0c099a8a */
if(!s->budget--) { s->failed_pc=0x0c099a8au; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099a8c;
P_0c099a8c: /* original e018, guest PC 0x0c099a8c */
if(!s->budget--) { s->failed_pc=0x0c099a8cu; return 0; }
r[0]=0x00000018u;
goto P_0c099a8e;
P_0c099a8e: /* original fce7, guest PC 0x0c099a8e */
if(!s->budget--) { s->failed_pc=0x0c099a8eu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c099a90;
P_0c099a90: /* original 9072, guest PC 0x0c099a90 */
if(!s->budget--) { s->failed_pc=0x0c099a90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099a92;
P_0c099a92: /* original fc47, guest PC 0x0c099a92 */
if(!s->budget--) { s->failed_pc=0x0c099a92u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099a94;
P_0c099a94: /* original 7008, guest PC 0x0c099a94 */
if(!s->budget--) { s->failed_pc=0x0c099a94u; return 0; }
r[0]+=0x00000008u;
goto P_0c099a96;
P_0c099a96: /* original fce7, guest PC 0x0c099a96 */
if(!s->budget--) { s->failed_pc=0x0c099a96u; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c099a98;
P_0c099a98: /* original d33c, guest PC 0x0c099a98 */
if(!s->budget--) { s->failed_pc=0x0c099a98u; return 0; }
r[3]=read(ram,0x0c099b8cu,4);
goto P_0c099a9a;
P_0c099a9a: /* original f5ec, guest PC 0x0c099a9a */
if(!s->budget--) { s->failed_pc=0x0c099a9au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c099a9c;
P_0c099a9c: /* original 430b, guest PC 0x0c099a9c */
if(!s->budget--) { s->failed_pc=0x0c099a9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099aa0u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099aa0u) { target=s->pc; goto dispatch; }
goto P_0c099aa0;
P_0c099a9e: /* original f54d, guest PC 0x0c099a9e */
if(!s->budget--) { s->failed_pc=0x0c099a9eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c099aa0;
P_0c099aa0: /* original e014, guest PC 0x0c099aa0 */
if(!s->budget--) { s->failed_pc=0x0c099aa0u; return 0; }
r[0]=0x00000014u;
goto P_0c099aa2;
P_0c099aa2: /* original f40c, guest PC 0x0c099aa2 */
if(!s->budget--) { s->failed_pc=0x0c099aa2u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c099aa4;
P_0c099aa4: /* original fc47, guest PC 0x0c099aa4 */
if(!s->budget--) { s->failed_pc=0x0c099aa4u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099aa6;
P_0c099aa6: /* original 9068, guest PC 0x0c099aa6 */
if(!s->budget--) { s->failed_pc=0x0c099aa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7au,2);
goto P_0c099aa8;
P_0c099aa8: /* original fc47, guest PC 0x0c099aa8 */
if(!s->budget--) { s->failed_pc=0x0c099aa8u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099aaa;
P_0c099aaa: /* original e01c, guest PC 0x0c099aaa */
if(!s->budget--) { s->failed_pc=0x0c099aaau; return 0; }
r[0]=0x0000001cu;
goto P_0c099aac;
P_0c099aac: /* original 00bc, guest PC 0x0c099aac */
if(!s->budget--) { s->failed_pc=0x0c099aacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c099aae;
P_0c099aae: /* original 600c, guest PC 0x0c099aae */
if(!s->budget--) { s->failed_pc=0x0c099aaeu; return 0; }
r[0]=r[0]&255u;
goto P_0c099ab0;
P_0c099ab0: /* original c90f, guest PC 0x0c099ab0 */
if(!s->budget--) { s->failed_pc=0x0c099ab0u; return 0; }
r[0]&=15u;
goto P_0c099ab2;
P_0c099ab2: /* original 8807, guest PC 0x0c099ab2 */
if(!s->budget--) { s->failed_pc=0x0c099ab2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c099ab4;
P_0c099ab4: /* original 8b4f, guest PC 0x0c099ab4 */
if(!s->budget--) { s->failed_pc=0x0c099ab4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099b56; }
goto P_0c099ab6;
P_0c099ab6: /* original 905c, guest PC 0x0c099ab6 */
if(!s->budget--) { s->failed_pc=0x0c099ab6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b72u,2);
goto P_0c099ab8;
P_0c099ab8: /* original d335, guest PC 0x0c099ab8 */
if(!s->budget--) { s->failed_pc=0x0c099ab8u; return 0; }
r[3]=read(ram,0x0c099b90u,4);
goto P_0c099aba;
P_0c099aba: /* original 0cee, guest PC 0x0c099aba */
if(!s->budget--) { s->failed_pc=0x0c099abau; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c099abc;
P_0c099abc: /* original 62c2, guest PC 0x0c099abc */
if(!s->budget--) { s->failed_pc=0x0c099abcu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c099abe;
P_0c099abe: /* original 2238, guest PC 0x0c099abe */
if(!s->budget--) { s->failed_pc=0x0c099abeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099ac0;
P_0c099ac0: /* original 8949, guest PC 0x0c099ac0 */
if(!s->budget--) { s->failed_pc=0x0c099ac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099b56; }
goto P_0c099ac2;
P_0c099ac2: /* original e048, guest PC 0x0c099ac2 */
if(!s->budget--) { s->failed_pc=0x0c099ac2u; return 0; }
r[0]=0x00000048u;
goto P_0c099ac4;
P_0c099ac4: /* original 61c2, guest PC 0x0c099ac4 */
if(!s->budget--) { s->failed_pc=0x0c099ac4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c099ac6;
P_0c099ac6: /* original 65f3, guest PC 0x0c099ac6 */
if(!s->budget--) { s->failed_pc=0x0c099ac6u; return 0; }
r[5]=r[15];
goto P_0c099ac8;
P_0c099ac8: /* original 7504, guest PC 0x0c099ac8 */
if(!s->budget--) { s->failed_pc=0x0c099ac8u; return 0; }
r[5]+=0x00000004u;
goto P_0c099aca;
P_0c099aca: /* original 1f11, guest PC 0x0c099aca */
if(!s->budget--) { s->failed_pc=0x0c099acau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c099acc;
P_0c099acc: /* original 66f3, guest PC 0x0c099acc */
if(!s->budget--) { s->failed_pc=0x0c099accu; return 0; }
r[6]=r[15];
goto P_0c099ace;
P_0c099ace: /* original 03ce, guest PC 0x0c099ace */
if(!s->budget--) { s->failed_pc=0x0c099aceu; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c099ad0;
P_0c099ad0: /* original 2f32, guest PC 0x0c099ad0 */
if(!s->budget--) { s->failed_pc=0x0c099ad0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099ad2;
P_0c099ad2: /* original d330, guest PC 0x0c099ad2 */
if(!s->budget--) { s->failed_pc=0x0c099ad2u; return 0; }
r[3]=read(ram,0x0c099b94u,4);
goto P_0c099ad4;
P_0c099ad4: /* original 430b, guest PC 0x0c099ad4 */
if(!s->budget--) { s->failed_pc=0x0c099ad4u; return 0; }
target=r[3];
r[16]=code_base|0x0c099ad8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099ad8u) { target=s->pc; goto dispatch; }
goto P_0c099ad8;
P_0c099ad6: /* original 64c3, guest PC 0x0c099ad6 */
if(!s->budget--) { s->failed_pc=0x0c099ad6u; return 0; }
r[4]=r[12];
goto P_0c099ad8;
P_0c099ad8: /* original e048, guest PC 0x0c099ad8 */
if(!s->budget--) { s->failed_pc=0x0c099ad8u; return 0; }
r[0]=0x00000048u;
goto P_0c099ada;
P_0c099ada: /* original 52f1, guest PC 0x0c099ada */
if(!s->budget--) { s->failed_pc=0x0c099adau; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099adc;
P_0c099adc: /* original 2c22, guest PC 0x0c099adc */
if(!s->budget--) { s->failed_pc=0x0c099adcu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c099ade;
P_0c099ade: /* original e26d, guest PC 0x0c099ade */
if(!s->budget--) { s->failed_pc=0x0c099adeu; return 0; }
r[2]=0x0000006du;
goto P_0c099ae0;
P_0c099ae0: /* original 63f2, guest PC 0x0c099ae0 */
if(!s->budget--) { s->failed_pc=0x0c099ae0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099ae2;
P_0c099ae2: /* original 0c36, guest PC 0x0c099ae2 */
if(!s->budget--) { s->failed_pc=0x0c099ae2u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c099ae4;
P_0c099ae4: /* original e061, guest PC 0x0c099ae4 */
if(!s->budget--) { s->failed_pc=0x0c099ae4u; return 0; }
r[0]=0x00000061u;
goto P_0c099ae6;
P_0c099ae6: /* original 2f22, guest PC 0x0c099ae6 */
if(!s->budget--) { s->failed_pc=0x0c099ae6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099ae8;
P_0c099ae8: /* original 00cc, guest PC 0x0c099ae8 */
if(!s->budget--) { s->failed_pc=0x0c099ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c099aea;
P_0c099aea: /* original 600c, guest PC 0x0c099aea */
if(!s->budget--) { s->failed_pc=0x0c099aeau; return 0; }
r[0]=r[0]&255u;
goto P_0c099aec;
P_0c099aec: /* original 880c, guest PC 0x0c099aec */
if(!s->budget--) { s->failed_pc=0x0c099aecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c099aee;
P_0c099aee: /* original 8b01, guest PC 0x0c099aee */
if(!s->budget--) { s->failed_pc=0x0c099aeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099af4; }
goto P_0c099af0;
P_0c099af0: /* original 9344, guest PC 0x0c099af0 */
if(!s->budget--) { s->failed_pc=0x0c099af0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7cu,2);
goto P_0c099af2;
P_0c099af2: /* original 2f32, guest PC 0x0c099af2 */
if(!s->budget--) { s->failed_pc=0x0c099af2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099af4;
P_0c099af4: /* original 62f2, guest PC 0x0c099af4 */
if(!s->budget--) { s->failed_pc=0x0c099af4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c099af6;
P_0c099af6: /* original e03c, guest PC 0x0c099af6 */
if(!s->budget--) { s->failed_pc=0x0c099af6u; return 0; }
r[0]=0x0000003cu;
goto P_0c099af8;
P_0c099af8: /* original 0c25, guest PC 0x0c099af8 */
if(!s->budget--) { s->failed_pc=0x0c099af8u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c099afa;
P_0c099afa: /* original e201, guest PC 0x0c099afa */
if(!s->budget--) { s->failed_pc=0x0c099afau; return 0; }
r[2]=0x00000001u;
goto P_0c099afc;
P_0c099afc: /* original e03e, guest PC 0x0c099afc */
if(!s->budget--) { s->failed_pc=0x0c099afcu; return 0; }
r[0]=0x0000003eu;
goto P_0c099afe;
P_0c099afe: /* original 63f2, guest PC 0x0c099afe */
if(!s->budget--) { s->failed_pc=0x0c099afeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099b00;
P_0c099b00: /* original 1c3d, guest PC 0x0c099b00 */
if(!s->budget--) { s->failed_pc=0x0c099b00u; return 0; }
write(ram,r[12]+52,r[3],4);
goto P_0c099b02;
P_0c099b02: /* original 0c25, guest PC 0x0c099b02 */
if(!s->budget--) { s->failed_pc=0x0c099b02u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c099b04;
P_0c099b04: /* original e010, guest PC 0x0c099b04 */
if(!s->budget--) { s->failed_pc=0x0c099b04u; return 0; }
r[0]=0x00000010u;
goto P_0c099b06;
P_0c099b06: /* original fcf7, guest PC 0x0c099b06 */
if(!s->budget--) { s->failed_pc=0x0c099b06u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b08;
P_0c099b08: /* original e018, guest PC 0x0c099b08 */
if(!s->budget--) { s->failed_pc=0x0c099b08u; return 0; }
r[0]=0x00000018u;
goto P_0c099b0a;
P_0c099b0a: /* original fcf7, guest PC 0x0c099b0a */
if(!s->budget--) { s->failed_pc=0x0c099b0au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b0c;
P_0c099b0c: /* original e024, guest PC 0x0c099b0c */
if(!s->budget--) { s->failed_pc=0x0c099b0cu; return 0; }
r[0]=0x00000024u;
goto P_0c099b0e;
P_0c099b0e: /* original fcf7, guest PC 0x0c099b0e */
if(!s->budget--) { s->failed_pc=0x0c099b0eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b10;
P_0c099b10: /* original e02c, guest PC 0x0c099b10 */
if(!s->budget--) { s->failed_pc=0x0c099b10u; return 0; }
r[0]=0x0000002cu;
goto P_0c099b12;
P_0c099b12: /* original fcf7, guest PC 0x0c099b12 */
if(!s->budget--) { s->failed_pc=0x0c099b12u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b14;
P_0c099b14: /* original 9033, guest PC 0x0c099b14 */
if(!s->budget--) { s->failed_pc=0x0c099b14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7eu,2);
goto P_0c099b16;
P_0c099b16: /* original fcf7, guest PC 0x0c099b16 */
if(!s->budget--) { s->failed_pc=0x0c099b16u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b18;
P_0c099b18: /* original 7004, guest PC 0x0c099b18 */
if(!s->budget--) { s->failed_pc=0x0c099b18u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b1a;
P_0c099b1a: /* original fcf7, guest PC 0x0c099b1a */
if(!s->budget--) { s->failed_pc=0x0c099b1au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b1c;
P_0c099b1c: /* original 902a, guest PC 0x0c099b1c */
if(!s->budget--) { s->failed_pc=0x0c099b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b74u,2);
goto P_0c099b1e;
P_0c099b1e: /* original fcf7, guest PC 0x0c099b1e */
if(!s->budget--) { s->failed_pc=0x0c099b1eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b20;
P_0c099b20: /* original 7004, guest PC 0x0c099b20 */
if(!s->budget--) { s->failed_pc=0x0c099b20u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b22;
P_0c099b22: /* original fcf7, guest PC 0x0c099b22 */
if(!s->budget--) { s->failed_pc=0x0c099b22u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b24;
P_0c099b24: /* original 7004, guest PC 0x0c099b24 */
if(!s->budget--) { s->failed_pc=0x0c099b24u; return 0; }
r[0]+=0x00000004u;
goto P_0c099b26;
P_0c099b26: /* original fcf7, guest PC 0x0c099b26 */
if(!s->budget--) { s->failed_pc=0x0c099b26u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b28;
P_0c099b28: /* original 9026, guest PC 0x0c099b28 */
if(!s->budget--) { s->failed_pc=0x0c099b28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099b2a;
P_0c099b2a: /* original fcf7, guest PC 0x0c099b2a */
if(!s->budget--) { s->failed_pc=0x0c099b2au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b2c;
P_0c099b2c: /* original 7008, guest PC 0x0c099b2c */
if(!s->budget--) { s->failed_pc=0x0c099b2cu; return 0; }
r[0]+=0x00000008u;
goto P_0c099b2e;
P_0c099b2e: /* original fcf7, guest PC 0x0c099b2e */
if(!s->budget--) { s->failed_pc=0x0c099b2eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b30;
P_0c099b30: /* original 9026, guest PC 0x0c099b30 */
if(!s->budget--) { s->failed_pc=0x0c099b30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b80u,2);
goto P_0c099b32;
P_0c099b32: /* original fcf7, guest PC 0x0c099b32 */
if(!s->budget--) { s->failed_pc=0x0c099b32u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b34;
P_0c099b34: /* original 7008, guest PC 0x0c099b34 */
if(!s->budget--) { s->failed_pc=0x0c099b34u; return 0; }
r[0]+=0x00000008u;
goto P_0c099b36;
P_0c099b36: /* original fcf7, guest PC 0x0c099b36 */
if(!s->budget--) { s->failed_pc=0x0c099b36u; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b38;
P_0c099b38: /* original 901e, guest PC 0x0c099b38 */
if(!s->budget--) { s->failed_pc=0x0c099b38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b78u,2);
goto P_0c099b3a;
P_0c099b3a: /* original fcf7, guest PC 0x0c099b3a */
if(!s->budget--) { s->failed_pc=0x0c099b3au; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b3c;
P_0c099b3c: /* original 7008, guest PC 0x0c099b3c */
if(!s->budget--) { s->failed_pc=0x0c099b3cu; return 0; }
r[0]+=0x00000008u;
goto P_0c099b3e;
P_0c099b3e: /* original fcf7, guest PC 0x0c099b3e */
if(!s->budget--) { s->failed_pc=0x0c099b3eu; return 0; }
vf3_matrix_store(s,ram,15,r[12]+r[0]);
goto P_0c099b40;
P_0c099b40: /* original e010, guest PC 0x0c099b40 */
if(!s->budget--) { s->failed_pc=0x0c099b40u; return 0; }
r[0]=0x00000010u;
goto P_0c099b42;
P_0c099b42: /* original d312, guest PC 0x0c099b42 */
if(!s->budget--) { s->failed_pc=0x0c099b42u; return 0; }
r[3]=read(ram,0x0c099b8cu,4);
goto P_0c099b44;
P_0c099b44: /* original f4c6, guest PC 0x0c099b44 */
if(!s->budget--) { s->failed_pc=0x0c099b44u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c099b46;
P_0c099b46: /* original e018, guest PC 0x0c099b46 */
if(!s->budget--) { s->failed_pc=0x0c099b46u; return 0; }
r[0]=0x00000018u;
goto P_0c099b48;
P_0c099b48: /* original 430b, guest PC 0x0c099b48 */
if(!s->budget--) { s->failed_pc=0x0c099b48u; return 0; }
target=r[3];
r[16]=code_base|0x0c099b4cu;
vf3_matrix_load(s,ram,5,r[12]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099b4cu) { target=s->pc; goto dispatch; }
goto P_0c099b4c;
P_0c099b4a: /* original f5c6, guest PC 0x0c099b4a */
if(!s->budget--) { s->failed_pc=0x0c099b4au; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c099b4c;
P_0c099b4c: /* original e014, guest PC 0x0c099b4c */
if(!s->budget--) { s->failed_pc=0x0c099b4cu; return 0; }
r[0]=0x00000014u;
goto P_0c099b4e;
P_0c099b4e: /* original f40c, guest PC 0x0c099b4e */
if(!s->budget--) { s->failed_pc=0x0c099b4eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c099b50;
P_0c099b50: /* original fc47, guest PC 0x0c099b50 */
if(!s->budget--) { s->failed_pc=0x0c099b50u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099b52;
P_0c099b52: /* original 9012, guest PC 0x0c099b52 */
if(!s->budget--) { s->failed_pc=0x0c099b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b7au,2);
goto P_0c099b54;
P_0c099b54: /* original fc47, guest PC 0x0c099b54 */
if(!s->budget--) { s->failed_pc=0x0c099b54u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c099b56;
P_0c099b56: /* original 9014, guest PC 0x0c099b56 */
if(!s->budget--) { s->failed_pc=0x0c099b56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099b82u,2);
goto P_0c099b58;
P_0c099b58: /* original 53d4, guest PC 0x0c099b58 */
if(!s->budget--) { s->failed_pc=0x0c099b58u; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c099b5a;
P_0c099b5a: /* original 02ee, guest PC 0x0c099b5a */
if(!s->budget--) { s->failed_pc=0x0c099b5au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c099b5c;
P_0c099b5c: /* original 3230, guest PC 0x0c099b5c */
if(!s->budget--) { s->failed_pc=0x0c099b5cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c099b5e;
P_0c099b5e: /* original 891d, guest PC 0x0c099b5e */
if(!s->budget--) { s->failed_pc=0x0c099b5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099b9c; }
goto P_0c099b60;
P_0c099b60: /* original d20d, guest PC 0x0c099b60 */
if(!s->budget--) { s->failed_pc=0x0c099b60u; return 0; }
r[2]=read(ram,0x0c099b98u,4);
goto P_0c099b62;
P_0c099b62: /* original 420b, guest PC 0x0c099b62 */
if(!s->budget--) { s->failed_pc=0x0c099b62u; return 0; }
target=r[2];
r[16]=code_base|0x0c099b66u;
r[4]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099b66u) { target=s->pc; goto dispatch; }
goto P_0c099b66;
P_0c099b64: /* original 54d5, guest PC 0x0c099b64 */
if(!s->budget--) { s->failed_pc=0x0c099b64u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099b66;
P_0c099b66: /* original d30c, guest PC 0x0c099b66 */
if(!s->budget--) { s->failed_pc=0x0c099b66u; return 0; }
r[3]=read(ram,0x0c099b98u,4);
goto P_0c099b68;
P_0c099b68: /* original e05c, guest PC 0x0c099b68 */
if(!s->budget--) { s->failed_pc=0x0c099b68u; return 0; }
r[0]=0x0000005cu;
goto P_0c099b6a;
P_0c099b6a: /* original 430b, guest PC 0x0c099b6a */
if(!s->budget--) { s->failed_pc=0x0c099b6au; return 0; }
target=r[3];
r[16]=code_base|0x0c099b6eu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099b6eu) { target=s->pc; goto dispatch; }
goto P_0c099b6e;
P_0c099b6c: /* original 04de, guest PC 0x0c099b6c */
if(!s->budget--) { s->failed_pc=0x0c099b6cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099b6e;
P_0c099b6e: /* original a01d, guest PC 0x0c099b6e */
if(!s->budget--) { s->failed_pc=0x0c099b6eu; return 0; }
r[0]=0x00000064u;
goto P_0c099bac;
P_0c099b70: /* original e064, guest PC 0x0c099b70 */
if(!s->budget--) { s->failed_pc=0x0c099b70u; return 0; }
r[0]=0x00000064u;
if(!vf3_matrix_family(0x0c099b72u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099b72u; return 0; } return 1;
P_0c099b9c: /* original d33c, guest PC 0x0c099b9c */
if(!s->budget--) { s->failed_pc=0x0c099b9cu; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099b9e;
P_0c099b9e: /* original 430b, guest PC 0x0c099b9e */
if(!s->budget--) { s->failed_pc=0x0c099b9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099ba2u;
r[4]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099ba2u) { target=s->pc; goto dispatch; }
goto P_0c099ba2;
P_0c099ba0: /* original 54d4, guest PC 0x0c099ba0 */
if(!s->budget--) { s->failed_pc=0x0c099ba0u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099ba2;
P_0c099ba2: /* original d33b, guest PC 0x0c099ba2 */
if(!s->budget--) { s->failed_pc=0x0c099ba2u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099ba4;
P_0c099ba4: /* original e048, guest PC 0x0c099ba4 */
if(!s->budget--) { s->failed_pc=0x0c099ba4u; return 0; }
r[0]=0x00000048u;
goto P_0c099ba6;
P_0c099ba6: /* original 430b, guest PC 0x0c099ba6 */
if(!s->budget--) { s->failed_pc=0x0c099ba6u; return 0; }
target=r[3];
r[16]=code_base|0x0c099baau;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099baau) { target=s->pc; goto dispatch; }
goto P_0c099baa;
P_0c099ba8: /* original 04de, guest PC 0x0c099ba8 */
if(!s->budget--) { s->failed_pc=0x0c099ba8u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099baa;
P_0c099baa: /* original e060, guest PC 0x0c099baa */
if(!s->budget--) { s->failed_pc=0x0c099baau; return 0; }
r[0]=0x00000060u;
goto P_0c099bac;
P_0c099bac: /* original d338, guest PC 0x0c099bac */
if(!s->budget--) { s->failed_pc=0x0c099bacu; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bae;
P_0c099bae: /* original 430b, guest PC 0x0c099bae */
if(!s->budget--) { s->failed_pc=0x0c099baeu; return 0; }
target=r[3];
r[16]=code_base|0x0c099bb2u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099bb2u) { target=s->pc; goto dispatch; }
goto P_0c099bb2;
P_0c099bb0: /* original 04de, guest PC 0x0c099bb0 */
if(!s->budget--) { s->failed_pc=0x0c099bb0u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099bb2;
P_0c099bb2: /* original 9067, guest PC 0x0c099bb2 */
if(!s->budget--) { s->failed_pc=0x0c099bb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099bb4;
P_0c099bb4: /* original e30a, guest PC 0x0c099bb4 */
if(!s->budget--) { s->failed_pc=0x0c099bb4u; return 0; }
r[3]=0x0000000au;
goto P_0c099bb6;
P_0c099bb6: /* original 55d8, guest PC 0x0c099bb6 */
if(!s->budget--) { s->failed_pc=0x0c099bb6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c099bb8;
P_0c099bb8: /* original 04ee, guest PC 0x0c099bb8 */
if(!s->budget--) { s->failed_pc=0x0c099bb8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099bba;
P_0c099bba: /* original e048, guest PC 0x0c099bba */
if(!s->budget--) { s->failed_pc=0x0c099bbau; return 0; }
r[0]=0x00000048u;
goto P_0c099bbc;
P_0c099bbc: /* original 2f32, guest PC 0x0c099bbc */
if(!s->budget--) { s->failed_pc=0x0c099bbcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099bbe;
P_0c099bbe: /* original 024e, guest PC 0x0c099bbe */
if(!s->budget--) { s->failed_pc=0x0c099bbeu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099bc0;
P_0c099bc0: /* original d334, guest PC 0x0c099bc0 */
if(!s->budget--) { s->failed_pc=0x0c099bc0u; return 0; }
r[3]=read(ram,0x0c099c94u,4);
goto P_0c099bc2;
P_0c099bc2: /* original 2238, guest PC 0x0c099bc2 */
if(!s->budget--) { s->failed_pc=0x0c099bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099bc4;
P_0c099bc4: /* original 8901, guest PC 0x0c099bc4 */
if(!s->budget--) { s->failed_pc=0x0c099bc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099bca; }
goto P_0c099bc6;
P_0c099bc6: /* original e10c, guest PC 0x0c099bc6 */
if(!s->budget--) { s->failed_pc=0x0c099bc6u; return 0; }
r[1]=0x0000000cu;
goto P_0c099bc8;
P_0c099bc8: /* original 2f12, guest PC 0x0c099bc8 */
if(!s->budget--) { s->failed_pc=0x0c099bc8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c099bca;
P_0c099bca: /* original 905c, guest PC 0x0c099bca */
if(!s->budget--) { s->failed_pc=0x0c099bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c86u,2);
goto P_0c099bcc;
P_0c099bcc: /* original 63f2, guest PC 0x0c099bcc */
if(!s->budget--) { s->failed_pc=0x0c099bccu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c099bce;
P_0c099bce: /* original a023, guest PC 0x0c099bce */
if(!s->budget--) { s->failed_pc=0x0c099bceu; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c099c18;
P_0c099bd0: /* original 0534, guest PC 0x0c099bd0 */
if(!s->budget--) { s->failed_pc=0x0c099bd0u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c099bd2;
P_0c099bd2: /* original 9057, guest PC 0x0c099bd2 */
if(!s->budget--) { s->failed_pc=0x0c099bd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099bd4;
P_0c099bd4: /* original 04ee, guest PC 0x0c099bd4 */
if(!s->budget--) { s->failed_pc=0x0c099bd4u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099bd6;
P_0c099bd6: /* original e048, guest PC 0x0c099bd6 */
if(!s->budget--) { s->failed_pc=0x0c099bd6u; return 0; }
r[0]=0x00000048u;
goto P_0c099bd8;
P_0c099bd8: /* original 034e, guest PC 0x0c099bd8 */
if(!s->budget--) { s->failed_pc=0x0c099bd8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c099bda;
P_0c099bda: /* original e048, guest PC 0x0c099bda */
if(!s->budget--) { s->failed_pc=0x0c099bdau; return 0; }
r[0]=0x00000048u;
goto P_0c099bdc;
P_0c099bdc: /* original 2f32, guest PC 0x0c099bdc */
if(!s->budget--) { s->failed_pc=0x0c099bdcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099bde;
P_0c099bde: /* original 024e, guest PC 0x0c099bde */
if(!s->budget--) { s->failed_pc=0x0c099bdeu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099be0;
P_0c099be0: /* original d32d, guest PC 0x0c099be0 */
if(!s->budget--) { s->failed_pc=0x0c099be0u; return 0; }
r[3]=read(ram,0x0c099c98u,4);
goto P_0c099be2;
P_0c099be2: /* original 2239, guest PC 0x0c099be2 */
if(!s->budget--) { s->failed_pc=0x0c099be2u; return 0; }
r[2]&=r[3];
goto P_0c099be4;
P_0c099be4: /* original 0426, guest PC 0x0c099be4 */
if(!s->budget--) { s->failed_pc=0x0c099be4u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c099be6;
P_0c099be6: /* original 904d, guest PC 0x0c099be6 */
if(!s->budget--) { s->failed_pc=0x0c099be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c84u,2);
goto P_0c099be8;
P_0c099be8: /* original 51d4, guest PC 0x0c099be8 */
if(!s->budget--) { s->failed_pc=0x0c099be8u; return 0; }
r[1]=read(ram,r[13]+16,4);
goto P_0c099bea;
P_0c099bea: /* original 00ee, guest PC 0x0c099bea */
if(!s->budget--) { s->failed_pc=0x0c099beau; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c099bec;
P_0c099bec: /* original 3010, guest PC 0x0c099bec */
if(!s->budget--) { s->failed_pc=0x0c099becu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c099bee;
P_0c099bee: /* original 8908, guest PC 0x0c099bee */
if(!s->budget--) { s->failed_pc=0x0c099beeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099c02; }
goto P_0c099bf0;
P_0c099bf0: /* original d327, guest PC 0x0c099bf0 */
if(!s->budget--) { s->failed_pc=0x0c099bf0u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bf2;
P_0c099bf2: /* original 430b, guest PC 0x0c099bf2 */
if(!s->budget--) { s->failed_pc=0x0c099bf2u; return 0; }
target=r[3];
r[16]=code_base|0x0c099bf6u;
r[4]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099bf6u) { target=s->pc; goto dispatch; }
goto P_0c099bf6;
P_0c099bf4: /* original 54d5, guest PC 0x0c099bf4 */
if(!s->budget--) { s->failed_pc=0x0c099bf4u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099bf6;
P_0c099bf6: /* original d326, guest PC 0x0c099bf6 */
if(!s->budget--) { s->failed_pc=0x0c099bf6u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099bf8;
P_0c099bf8: /* original e05c, guest PC 0x0c099bf8 */
if(!s->budget--) { s->failed_pc=0x0c099bf8u; return 0; }
r[0]=0x0000005cu;
goto P_0c099bfa;
P_0c099bfa: /* original 430b, guest PC 0x0c099bfa */
if(!s->budget--) { s->failed_pc=0x0c099bfau; return 0; }
target=r[3];
r[16]=code_base|0x0c099bfeu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099bfeu) { target=s->pc; goto dispatch; }
goto P_0c099bfe;
P_0c099bfc: /* original 04de, guest PC 0x0c099bfc */
if(!s->budget--) { s->failed_pc=0x0c099bfcu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099bfe;
P_0c099bfe: /* original a008, guest PC 0x0c099bfe */
if(!s->budget--) { s->failed_pc=0x0c099bfeu; return 0; }
r[0]=0x00000064u;
goto P_0c099c12;
P_0c099c00: /* original e064, guest PC 0x0c099c00 */
if(!s->budget--) { s->failed_pc=0x0c099c00u; return 0; }
r[0]=0x00000064u;
goto P_0c099c02;
P_0c099c02: /* original d323, guest PC 0x0c099c02 */
if(!s->budget--) { s->failed_pc=0x0c099c02u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c04;
P_0c099c04: /* original 430b, guest PC 0x0c099c04 */
if(!s->budget--) { s->failed_pc=0x0c099c04u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c08u;
r[4]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c08u) { target=s->pc; goto dispatch; }
goto P_0c099c08;
P_0c099c06: /* original 54d4, guest PC 0x0c099c06 */
if(!s->budget--) { s->failed_pc=0x0c099c06u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099c08;
P_0c099c08: /* original d321, guest PC 0x0c099c08 */
if(!s->budget--) { s->failed_pc=0x0c099c08u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c0a;
P_0c099c0a: /* original e048, guest PC 0x0c099c0a */
if(!s->budget--) { s->failed_pc=0x0c099c0au; return 0; }
r[0]=0x00000048u;
goto P_0c099c0c;
P_0c099c0c: /* original 430b, guest PC 0x0c099c0c */
if(!s->budget--) { s->failed_pc=0x0c099c0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099c10u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c10u) { target=s->pc; goto dispatch; }
goto P_0c099c10;
P_0c099c0e: /* original 04de, guest PC 0x0c099c0e */
if(!s->budget--) { s->failed_pc=0x0c099c0eu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099c10;
P_0c099c10: /* original e060, guest PC 0x0c099c10 */
if(!s->budget--) { s->failed_pc=0x0c099c10u; return 0; }
r[0]=0x00000060u;
goto P_0c099c12;
P_0c099c12: /* original d31f, guest PC 0x0c099c12 */
if(!s->budget--) { s->failed_pc=0x0c099c12u; return 0; }
r[3]=read(ram,0x0c099c90u,4);
goto P_0c099c14;
P_0c099c14: /* original 430b, guest PC 0x0c099c14 */
if(!s->budget--) { s->failed_pc=0x0c099c14u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c18u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c18u) { target=s->pc; goto dispatch; }
goto P_0c099c18;
P_0c099c16: /* original 04de, guest PC 0x0c099c16 */
if(!s->budget--) { s->failed_pc=0x0c099c16u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099c18;
P_0c099c18: /* original 9036, guest PC 0x0c099c18 */
if(!s->budget--) { s->failed_pc=0x0c099c18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c88u,2);
goto P_0c099c1a;
P_0c099c1a: /* original 54d4, guest PC 0x0c099c1a */
if(!s->budget--) { s->failed_pc=0x0c099c1au; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c099c1c;
P_0c099c1c: /* original 04a4, guest PC 0x0c099c1c */
if(!s->budget--) { s->failed_pc=0x0c099c1cu; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099c1e;
P_0c099c1e: /* original 54d5, guest PC 0x0c099c1e */
if(!s->budget--) { s->failed_pc=0x0c099c1eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099c20;
P_0c099c20: /* original 04a4, guest PC 0x0c099c20 */
if(!s->budget--) { s->failed_pc=0x0c099c20u; return 0; }
write(ram,r[4]+r[0],r[10],1);
goto P_0c099c22;
P_0c099c22: /* original 84bb, guest PC 0x0c099c22 */
if(!s->budget--) { s->failed_pc=0x0c099c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+11,1);
goto P_0c099c24;
P_0c099c24: /* original 7001, guest PC 0x0c099c24 */
if(!s->budget--) { s->failed_pc=0x0c099c24u; return 0; }
r[0]+=0x00000001u;
goto P_0c099c26;
P_0c099c26: /* original b00c, guest PC 0x0c099c26 */
if(!s->budget--) { s->failed_pc=0x0c099c26u; return 0; }
target=code_base|0x0c099c42u; r[16]=code_base|0x0c099c2au;
write(ram,r[11]+11,r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c2au) { target=s->pc; goto dispatch; }
goto P_0c099c2a;
P_0c099c28: /* original 80bb, guest PC 0x0c099c28 */
if(!s->budget--) { s->failed_pc=0x0c099c28u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c099c2a;
P_0c099c2a: /* original 7f14, guest PC 0x0c099c2a */
if(!s->budget--) { s->failed_pc=0x0c099c2au; return 0; }
r[15]+=0x00000014u;
goto P_0c099c2c;
P_0c099c2c: /* original 4f26, guest PC 0x0c099c2c */
if(!s->budget--) { s->failed_pc=0x0c099c2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099c2e;
P_0c099c2e: /* original fef9, guest PC 0x0c099c2e */
if(!s->budget--) { s->failed_pc=0x0c099c2eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c099c30;
P_0c099c30: /* original fff9, guest PC 0x0c099c30 */
if(!s->budget--) { s->failed_pc=0x0c099c30u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c099c32;
P_0c099c32: /* original 68f6, guest PC 0x0c099c32 */
if(!s->budget--) { s->failed_pc=0x0c099c32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c099c34;
P_0c099c34: /* original 69f6, guest PC 0x0c099c34 */
if(!s->budget--) { s->failed_pc=0x0c099c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c099c36;
P_0c099c36: /* original 6af6, guest PC 0x0c099c36 */
if(!s->budget--) { s->failed_pc=0x0c099c36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c099c38;
P_0c099c38: /* original 6bf6, guest PC 0x0c099c38 */
if(!s->budget--) { s->failed_pc=0x0c099c38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099c3a;
P_0c099c3a: /* original 6cf6, guest PC 0x0c099c3a */
if(!s->budget--) { s->failed_pc=0x0c099c3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099c3c;
P_0c099c3c: /* original 6df6, guest PC 0x0c099c3c */
if(!s->budget--) { s->failed_pc=0x0c099c3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099c3e;
P_0c099c3e: /* original 000b, guest PC 0x0c099c3e */
if(!s->budget--) { s->failed_pc=0x0c099c3eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c099c40: /* original 6ef6, guest PC 0x0c099c40 */
if(!s->budget--) { s->failed_pc=0x0c099c40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c099c42u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
