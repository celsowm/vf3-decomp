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
int vf3_target_dependency_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0875f0u: goto P_0c0875f0;
case 0x0c0875f2u: goto P_0c0875f2;
case 0x0c0875f4u: goto P_0c0875f4;
case 0x0c0875f6u: goto P_0c0875f6;
case 0x0c0875f8u: goto P_0c0875f8;
case 0x0c0875fau: goto P_0c0875fa;
case 0x0c0875fcu: goto P_0c0875fc;
case 0x0c0875feu: goto P_0c0875fe;
case 0x0c087600u: goto P_0c087600;
case 0x0c087602u: goto P_0c087602;
case 0x0c087604u: goto P_0c087604;
case 0x0c087606u: goto P_0c087606;
case 0x0c087608u: goto P_0c087608;
case 0x0c08760au: goto P_0c08760a;
case 0x0c08760cu: goto P_0c08760c;
case 0x0c08760eu: goto P_0c08760e;
case 0x0c087610u: goto P_0c087610;
case 0x0c087612u: goto P_0c087612;
case 0x0c087614u: goto P_0c087614;
case 0x0c087616u: goto P_0c087616;
case 0x0c087618u: goto P_0c087618;
case 0x0c08761au: goto P_0c08761a;
case 0x0c08761cu: goto P_0c08761c;
case 0x0c08761eu: goto P_0c08761e;
case 0x0c087620u: goto P_0c087620;
case 0x0c087622u: goto P_0c087622;
case 0x0c087624u: goto P_0c087624;
case 0x0c087626u: goto P_0c087626;
case 0x0c087628u: goto P_0c087628;
case 0x0c08762au: goto P_0c08762a;
case 0x0c08762cu: goto P_0c08762c;
case 0x0c08762eu: goto P_0c08762e;
case 0x0c087630u: goto P_0c087630;
case 0x0c087632u: goto P_0c087632;
case 0x0c087634u: goto P_0c087634;
case 0x0c087636u: goto P_0c087636;
case 0x0c087638u: goto P_0c087638;
case 0x0c08763au: goto P_0c08763a;
case 0x0c087698u: goto P_0c087698;
case 0x0c08769au: goto P_0c08769a;
case 0x0c08779cu: goto P_0c08779c;
case 0x0c08779eu: goto P_0c08779e;
case 0x0c0877a0u: goto P_0c0877a0;
case 0x0c0877a2u: goto P_0c0877a2;
case 0x0c0877a4u: goto P_0c0877a4;
case 0x0c0877a6u: goto P_0c0877a6;
case 0x0c0877a8u: goto P_0c0877a8;
case 0x0c0877aau: goto P_0c0877aa;
case 0x0c0877acu: goto P_0c0877ac;
case 0x0c0877aeu: goto P_0c0877ae;
case 0x0c0877b0u: goto P_0c0877b0;
case 0x0c0877b2u: goto P_0c0877b2;
case 0x0c0877b4u: goto P_0c0877b4;
case 0x0c0877b6u: goto P_0c0877b6;
case 0x0c0877b8u: goto P_0c0877b8;
case 0x0c0877bau: goto P_0c0877ba;
case 0x0c0877bcu: goto P_0c0877bc;
case 0x0c0877beu: goto P_0c0877be;
case 0x0c0877c0u: goto P_0c0877c0;
case 0x0c0877c2u: goto P_0c0877c2;
case 0x0c0877c4u: goto P_0c0877c4;
case 0x0c0877c6u: goto P_0c0877c6;
case 0x0c0877c8u: goto P_0c0877c8;
case 0x0c0877cau: goto P_0c0877ca;
case 0x0c0877ccu: goto P_0c0877cc;
case 0x0c0877ceu: goto P_0c0877ce;
case 0x0c0877d0u: goto P_0c0877d0;
case 0x0c0877d2u: goto P_0c0877d2;
case 0x0c0877d4u: goto P_0c0877d4;
case 0x0c0877d6u: goto P_0c0877d6;
case 0x0c0877d8u: goto P_0c0877d8;
case 0x0c0877dau: goto P_0c0877da;
case 0x0c0877dcu: goto P_0c0877dc;
case 0x0c0877deu: goto P_0c0877de;
case 0x0c0877e0u: goto P_0c0877e0;
case 0x0c0877e2u: goto P_0c0877e2;
case 0x0c0877e4u: goto P_0c0877e4;
case 0x0c0877e6u: goto P_0c0877e6;
case 0x0c0877e8u: goto P_0c0877e8;
case 0x0c0877eau: goto P_0c0877ea;
case 0x0c0877ecu: goto P_0c0877ec;
case 0x0c0877eeu: goto P_0c0877ee;
case 0x0c0877f0u: goto P_0c0877f0;
case 0x0c0877f2u: goto P_0c0877f2;
case 0x0c0877f4u: goto P_0c0877f4;
case 0x0c0877f6u: goto P_0c0877f6;
case 0x0c0877f8u: goto P_0c0877f8;
case 0x0c0877fau: goto P_0c0877fa;
case 0x0c0877fcu: goto P_0c0877fc;
case 0x0c0877feu: goto P_0c0877fe;
case 0x0c087800u: goto P_0c087800;
case 0x0c087802u: goto P_0c087802;
case 0x0c087804u: goto P_0c087804;
case 0x0c087806u: goto P_0c087806;
case 0x0c087808u: goto P_0c087808;
case 0x0c08780au: goto P_0c08780a;
case 0x0c08780cu: goto P_0c08780c;
case 0x0c08780eu: goto P_0c08780e;
case 0x0c087810u: goto P_0c087810;
case 0x0c087812u: goto P_0c087812;
case 0x0c087814u: goto P_0c087814;
case 0x0c087816u: goto P_0c087816;
case 0x0c087818u: goto P_0c087818;
case 0x0c08781au: goto P_0c08781a;
case 0x0c08781cu: goto P_0c08781c;
case 0x0c08781eu: goto P_0c08781e;
case 0x0c087820u: goto P_0c087820;
case 0x0c087822u: goto P_0c087822;
case 0x0c087824u: goto P_0c087824;
case 0x0c087826u: goto P_0c087826;
case 0x0c087828u: goto P_0c087828;
case 0x0c08782au: goto P_0c08782a;
case 0x0c08782cu: goto P_0c08782c;
case 0x0c08782eu: goto P_0c08782e;
case 0x0c087830u: goto P_0c087830;
case 0x0c087832u: goto P_0c087832;
case 0x0c087834u: goto P_0c087834;
case 0x0c087836u: goto P_0c087836;
case 0x0c087838u: goto P_0c087838;
case 0x0c08783au: goto P_0c08783a;
case 0x0c08783cu: goto P_0c08783c;
case 0x0c08783eu: goto P_0c08783e;
case 0x0c087840u: goto P_0c087840;
case 0x0c087842u: goto P_0c087842;
case 0x0c087844u: goto P_0c087844;
case 0x0c087846u: goto P_0c087846;
case 0x0c087848u: goto P_0c087848;
case 0x0c08784au: goto P_0c08784a;
case 0x0c08784cu: goto P_0c08784c;
case 0x0c08784eu: goto P_0c08784e;
case 0x0c087850u: goto P_0c087850;
case 0x0c087852u: goto P_0c087852;
case 0x0c087854u: goto P_0c087854;
case 0x0c087856u: goto P_0c087856;
case 0x0c087858u: goto P_0c087858;
case 0x0c08785au: goto P_0c08785a;
case 0x0c08785cu: goto P_0c08785c;
case 0x0c08785eu: goto P_0c08785e;
case 0x0c087860u: goto P_0c087860;
case 0x0c087862u: goto P_0c087862;
case 0x0c087864u: goto P_0c087864;
case 0x0c087866u: goto P_0c087866;
case 0x0c087868u: goto P_0c087868;
case 0x0c08786au: goto P_0c08786a;
case 0x0c08786cu: goto P_0c08786c;
case 0x0c08786eu: goto P_0c08786e;
case 0x0c087870u: goto P_0c087870;
case 0x0c087872u: goto P_0c087872;
case 0x0c087874u: goto P_0c087874;
case 0x0c087876u: goto P_0c087876;
case 0x0c087878u: goto P_0c087878;
case 0x0c08787au: goto P_0c08787a;
case 0x0c08787cu: goto P_0c08787c;
case 0x0c08787eu: goto P_0c08787e;
case 0x0c087880u: goto P_0c087880;
case 0x0c087882u: goto P_0c087882;
case 0x0c087884u: goto P_0c087884;
case 0x0c087886u: goto P_0c087886;
case 0x0c087888u: goto P_0c087888;
case 0x0c08788au: goto P_0c08788a;
case 0x0c08788cu: goto P_0c08788c;
case 0x0c08788eu: goto P_0c08788e;
case 0x0c087890u: goto P_0c087890;
case 0x0c087892u: goto P_0c087892;
case 0x0c087894u: goto P_0c087894;
case 0x0c087896u: goto P_0c087896;
case 0x0c087898u: goto P_0c087898;
case 0x0c08789au: goto P_0c08789a;
case 0x0c08789cu: goto P_0c08789c;
case 0x0c08789eu: goto P_0c08789e;
case 0x0c0878a0u: goto P_0c0878a0;
case 0x0c0878a2u: goto P_0c0878a2;
case 0x0c0878a4u: goto P_0c0878a4;
case 0x0c0878a6u: goto P_0c0878a6;
case 0x0c0878a8u: goto P_0c0878a8;
case 0x0c0878aau: goto P_0c0878aa;
case 0x0c0878acu: goto P_0c0878ac;
case 0x0c0878aeu: goto P_0c0878ae;
case 0x0c0878b0u: goto P_0c0878b0;
case 0x0c0878b2u: goto P_0c0878b2;
case 0x0c0878b4u: goto P_0c0878b4;
case 0x0c0878b6u: goto P_0c0878b6;
case 0x0c0878b8u: goto P_0c0878b8;
case 0x0c0878bau: goto P_0c0878ba;
case 0x0c0878bcu: goto P_0c0878bc;
case 0x0c0878beu: goto P_0c0878be;
case 0x0c0878c0u: goto P_0c0878c0;
case 0x0c0878c2u: goto P_0c0878c2;
case 0x0c0878e8u: goto P_0c0878e8;
case 0x0c0878eau: goto P_0c0878ea;
case 0x0c0878ecu: goto P_0c0878ec;
case 0x0c0878eeu: goto P_0c0878ee;
case 0x0c0878f0u: goto P_0c0878f0;
case 0x0c0878f2u: goto P_0c0878f2;
case 0x0c0878f4u: goto P_0c0878f4;
case 0x0c0878f6u: goto P_0c0878f6;
case 0x0c0878f8u: goto P_0c0878f8;
case 0x0c0878fau: goto P_0c0878fa;
case 0x0c0878fcu: goto P_0c0878fc;
case 0x0c0878feu: goto P_0c0878fe;
case 0x0c087900u: goto P_0c087900;
case 0x0c087902u: goto P_0c087902;
case 0x0c087904u: goto P_0c087904;
case 0x0c087906u: goto P_0c087906;
case 0x0c087908u: goto P_0c087908;
case 0x0c08790au: goto P_0c08790a;
case 0x0c08790cu: goto P_0c08790c;
case 0x0c08790eu: goto P_0c08790e;
case 0x0c087910u: goto P_0c087910;
case 0x0c087912u: goto P_0c087912;
case 0x0c087914u: goto P_0c087914;
case 0x0c087916u: goto P_0c087916;
case 0x0c087918u: goto P_0c087918;
case 0x0c08791au: goto P_0c08791a;
case 0x0c08791cu: goto P_0c08791c;
case 0x0c08791eu: goto P_0c08791e;
case 0x0c087920u: goto P_0c087920;
case 0x0c087922u: goto P_0c087922;
case 0x0c087924u: goto P_0c087924;
case 0x0c087926u: goto P_0c087926;
case 0x0c087928u: goto P_0c087928;
case 0x0c08792au: goto P_0c08792a;
case 0x0c08792cu: goto P_0c08792c;
case 0x0c08792eu: goto P_0c08792e;
case 0x0c087930u: goto P_0c087930;
case 0x0c087932u: goto P_0c087932;
case 0x0c087934u: goto P_0c087934;
case 0x0c087936u: goto P_0c087936;
case 0x0c087938u: goto P_0c087938;
case 0x0c08793au: goto P_0c08793a;
case 0x0c08793cu: goto P_0c08793c;
case 0x0c08793eu: goto P_0c08793e;
case 0x0c087940u: goto P_0c087940;
case 0x0c087942u: goto P_0c087942;
case 0x0c087944u: goto P_0c087944;
case 0x0c087946u: goto P_0c087946;
case 0x0c087948u: goto P_0c087948;
case 0x0c08794au: goto P_0c08794a;
case 0x0c08794cu: goto P_0c08794c;
case 0x0c08794eu: goto P_0c08794e;
case 0x0c087950u: goto P_0c087950;
case 0x0c087952u: goto P_0c087952;
case 0x0c087954u: goto P_0c087954;
case 0x0c087956u: goto P_0c087956;
case 0x0c087958u: goto P_0c087958;
case 0x0c08795au: goto P_0c08795a;
case 0x0c08795cu: goto P_0c08795c;
case 0x0c08795eu: goto P_0c08795e;
case 0x0c087960u: goto P_0c087960;
case 0x0c087962u: goto P_0c087962;
case 0x0c087964u: goto P_0c087964;
case 0x0c087966u: goto P_0c087966;
case 0x0c087968u: goto P_0c087968;
case 0x0c08796au: goto P_0c08796a;
case 0x0c08796cu: goto P_0c08796c;
case 0x0c08796eu: goto P_0c08796e;
case 0x0c087970u: goto P_0c087970;
case 0x0c087972u: goto P_0c087972;
case 0x0c087974u: goto P_0c087974;
case 0x0c087976u: goto P_0c087976;
case 0x0c087978u: goto P_0c087978;
case 0x0c08797au: goto P_0c08797a;
case 0x0c08797cu: goto P_0c08797c;
case 0x0c08797eu: goto P_0c08797e;
case 0x0c087980u: goto P_0c087980;
case 0x0c087982u: goto P_0c087982;
case 0x0c087984u: goto P_0c087984;
case 0x0c087986u: goto P_0c087986;
case 0x0c087988u: goto P_0c087988;
case 0x0c08798au: goto P_0c08798a;
case 0x0c08798cu: goto P_0c08798c;
case 0x0c08798eu: goto P_0c08798e;
case 0x0c087990u: goto P_0c087990;
case 0x0c087992u: goto P_0c087992;
case 0x0c087994u: goto P_0c087994;
case 0x0c087996u: goto P_0c087996;
case 0x0c087998u: goto P_0c087998;
case 0x0c08799au: goto P_0c08799a;
case 0x0c08799cu: goto P_0c08799c;
case 0x0c08799eu: goto P_0c08799e;
case 0x0c0879a0u: goto P_0c0879a0;
case 0x0c0879a2u: goto P_0c0879a2;
case 0x0c0879a4u: goto P_0c0879a4;
case 0x0c0879a6u: goto P_0c0879a6;
case 0x0c0879a8u: goto P_0c0879a8;
case 0x0c0879aau: goto P_0c0879aa;
case 0x0c0879acu: goto P_0c0879ac;
case 0x0c0879aeu: goto P_0c0879ae;
case 0x0c0879b0u: goto P_0c0879b0;
case 0x0c0879b2u: goto P_0c0879b2;
case 0x0c0879b4u: goto P_0c0879b4;
case 0x0c0879b6u: goto P_0c0879b6;
case 0x0c0879b8u: goto P_0c0879b8;
case 0x0c0879bau: goto P_0c0879ba;
case 0x0c0879bcu: goto P_0c0879bc;
case 0x0c0879beu: goto P_0c0879be;
case 0x0c0879c0u: goto P_0c0879c0;
case 0x0c0879c2u: goto P_0c0879c2;
case 0x0c0879c4u: goto P_0c0879c4;
case 0x0c0879c6u: goto P_0c0879c6;
case 0x0c0879c8u: goto P_0c0879c8;
case 0x0c0879cau: goto P_0c0879ca;
case 0x0c0879ccu: goto P_0c0879cc;
case 0x0c0879ceu: goto P_0c0879ce;
case 0x0c0879d0u: goto P_0c0879d0;
case 0x0c0879d2u: goto P_0c0879d2;
case 0x0c0879d4u: goto P_0c0879d4;
case 0x0c0879d6u: goto P_0c0879d6;
case 0x0c0879d8u: goto P_0c0879d8;
case 0x0c087b80u: goto P_0c087b80;
case 0x0c087b82u: goto P_0c087b82;
case 0x0c087b84u: goto P_0c087b84;
case 0x0c087b86u: goto P_0c087b86;
case 0x0c087b88u: goto P_0c087b88;
case 0x0c087b8au: goto P_0c087b8a;
case 0x0c087b8cu: goto P_0c087b8c;
case 0x0c087b8eu: goto P_0c087b8e;
case 0x0c087b90u: goto P_0c087b90;
case 0x0c087b92u: goto P_0c087b92;
case 0x0c087b94u: goto P_0c087b94;
case 0x0c087b96u: goto P_0c087b96;
case 0x0c087b98u: goto P_0c087b98;
case 0x0c087b9au: goto P_0c087b9a;
case 0x0c087b9cu: goto P_0c087b9c;
case 0x0c087b9eu: goto P_0c087b9e;
case 0x0c087ba0u: goto P_0c087ba0;
case 0x0c087ba2u: goto P_0c087ba2;
case 0x0c087ba4u: goto P_0c087ba4;
case 0x0c087ba6u: goto P_0c087ba6;
case 0x0c087ba8u: goto P_0c087ba8;
case 0x0c087baau: goto P_0c087baa;
case 0x0c087bacu: goto P_0c087bac;
case 0x0c087baeu: goto P_0c087bae;
case 0x0c087bb0u: goto P_0c087bb0;
case 0x0c087bb2u: goto P_0c087bb2;
case 0x0c087bb4u: goto P_0c087bb4;
case 0x0c087bb6u: goto P_0c087bb6;
case 0x0c087bb8u: goto P_0c087bb8;
case 0x0c087bbau: goto P_0c087bba;
case 0x0c087bbcu: goto P_0c087bbc;
case 0x0c087bbeu: goto P_0c087bbe;
case 0x0c087bc0u: goto P_0c087bc0;
case 0x0c087bc2u: goto P_0c087bc2;
case 0x0c087bc4u: goto P_0c087bc4;
case 0x0c087bc6u: goto P_0c087bc6;
case 0x0c087bc8u: goto P_0c087bc8;
case 0x0c087bcau: goto P_0c087bca;
case 0x0c087bccu: goto P_0c087bcc;
case 0x0c087bceu: goto P_0c087bce;
case 0x0c087bd0u: goto P_0c087bd0;
case 0x0c087bd2u: goto P_0c087bd2;
case 0x0c087bd4u: goto P_0c087bd4;
case 0x0c087bd6u: goto P_0c087bd6;
case 0x0c087bd8u: goto P_0c087bd8;
case 0x0c087bf8u: goto P_0c087bf8;
case 0x0c087bfau: goto P_0c087bfa;
case 0x0c087bfcu: goto P_0c087bfc;
case 0x0c087bfeu: goto P_0c087bfe;
case 0x0c087c00u: goto P_0c087c00;
case 0x0c087c02u: goto P_0c087c02;
case 0x0c087c04u: goto P_0c087c04;
case 0x0c087c06u: goto P_0c087c06;
case 0x0c087c08u: goto P_0c087c08;
case 0x0c087c0au: goto P_0c087c0a;
case 0x0c087c0cu: goto P_0c087c0c;
case 0x0c087c0eu: goto P_0c087c0e;
case 0x0c087c10u: goto P_0c087c10;
case 0x0c087c12u: goto P_0c087c12;
case 0x0c087c14u: goto P_0c087c14;
case 0x0c087c16u: goto P_0c087c16;
case 0x0c087c18u: goto P_0c087c18;
case 0x0c087c1au: goto P_0c087c1a;
case 0x0c087c1cu: goto P_0c087c1c;
case 0x0c087c1eu: goto P_0c087c1e;
case 0x0c087c20u: goto P_0c087c20;
case 0x0c087c22u: goto P_0c087c22;
case 0x0c087c24u: goto P_0c087c24;
case 0x0c087c26u: goto P_0c087c26;
case 0x0c087c28u: goto P_0c087c28;
case 0x0c087c2au: goto P_0c087c2a;
case 0x0c087c2cu: goto P_0c087c2c;
case 0x0c087c2eu: goto P_0c087c2e;
case 0x0c087c30u: goto P_0c087c30;
case 0x0c087c32u: goto P_0c087c32;
case 0x0c087c34u: goto P_0c087c34;
case 0x0c087c36u: goto P_0c087c36;
case 0x0c087c38u: goto P_0c087c38;
case 0x0c087c3au: goto P_0c087c3a;
case 0x0c087c3cu: goto P_0c087c3c;
case 0x0c087c3eu: goto P_0c087c3e;
case 0x0c087c40u: goto P_0c087c40;
case 0x0c087c42u: goto P_0c087c42;
case 0x0c087c44u: goto P_0c087c44;
case 0x0c087c46u: goto P_0c087c46;
case 0x0c087c48u: goto P_0c087c48;
case 0x0c087c4au: goto P_0c087c4a;
case 0x0c087c4cu: goto P_0c087c4c;
case 0x0c087c4eu: goto P_0c087c4e;
case 0x0c087c50u: goto P_0c087c50;
case 0x0c087c52u: goto P_0c087c52;
case 0x0c087c54u: goto P_0c087c54;
case 0x0c087c56u: goto P_0c087c56;
case 0x0c087c58u: goto P_0c087c58;
case 0x0c087c5au: goto P_0c087c5a;
case 0x0c087c5cu: goto P_0c087c5c;
case 0x0c087c5eu: goto P_0c087c5e;
case 0x0c087c60u: goto P_0c087c60;
case 0x0c087c62u: goto P_0c087c62;
case 0x0c087c64u: goto P_0c087c64;
case 0x0c087c66u: goto P_0c087c66;
case 0x0c087c68u: goto P_0c087c68;
case 0x0c087c6au: goto P_0c087c6a;
case 0x0c087c6cu: goto P_0c087c6c;
case 0x0c087c6eu: goto P_0c087c6e;
case 0x0c087c70u: goto P_0c087c70;
case 0x0c087c72u: goto P_0c087c72;
case 0x0c087c74u: goto P_0c087c74;
case 0x0c087c76u: goto P_0c087c76;
case 0x0c087c78u: goto P_0c087c78;
case 0x0c087c7au: goto P_0c087c7a;
case 0x0c087c7cu: goto P_0c087c7c;
case 0x0c087c7eu: goto P_0c087c7e;
case 0x0c087c80u: goto P_0c087c80;
case 0x0c087c82u: goto P_0c087c82;
case 0x0c087c84u: goto P_0c087c84;
case 0x0c087c86u: goto P_0c087c86;
case 0x0c087c88u: goto P_0c087c88;
case 0x0c087c8au: goto P_0c087c8a;
case 0x0c087c8cu: goto P_0c087c8c;
case 0x0c087c8eu: goto P_0c087c8e;
case 0x0c087c90u: goto P_0c087c90;
case 0x0c087c92u: goto P_0c087c92;
case 0x0c087c94u: goto P_0c087c94;
case 0x0c087c96u: goto P_0c087c96;
case 0x0c087c98u: goto P_0c087c98;
case 0x0c087c9au: goto P_0c087c9a;
case 0x0c087c9cu: goto P_0c087c9c;
case 0x0c087c9eu: goto P_0c087c9e;
case 0x0c087ca0u: goto P_0c087ca0;
case 0x0c087ca2u: goto P_0c087ca2;
case 0x0c087ca4u: goto P_0c087ca4;
case 0x0c087ca6u: goto P_0c087ca6;
case 0x0c087ca8u: goto P_0c087ca8;
case 0x0c087caau: goto P_0c087caa;
case 0x0c087cacu: goto P_0c087cac;
case 0x0c087caeu: goto P_0c087cae;
case 0x0c087cb0u: goto P_0c087cb0;
case 0x0c087cb2u: goto P_0c087cb2;
case 0x0c087cb4u: goto P_0c087cb4;
case 0x0c087cb6u: goto P_0c087cb6;
case 0x0c087cb8u: goto P_0c087cb8;
case 0x0c087cbau: goto P_0c087cba;
case 0x0c087cbcu: goto P_0c087cbc;
case 0x0c087cbeu: goto P_0c087cbe;
case 0x0c087cc0u: goto P_0c087cc0;
case 0x0c087cc2u: goto P_0c087cc2;
case 0x0c087cc4u: goto P_0c087cc4;
case 0x0c087e1cu: goto P_0c087e1c;
case 0x0c087e1eu: goto P_0c087e1e;
case 0x0c087e20u: goto P_0c087e20;
case 0x0c087e22u: goto P_0c087e22;
case 0x0c087e24u: goto P_0c087e24;
case 0x0c087e26u: goto P_0c087e26;
case 0x0c087e28u: goto P_0c087e28;
case 0x0c087e2au: goto P_0c087e2a;
case 0x0c087e2cu: goto P_0c087e2c;
case 0x0c087e2eu: goto P_0c087e2e;
case 0x0c087e30u: goto P_0c087e30;
case 0x0c087e32u: goto P_0c087e32;
case 0x0c087e34u: goto P_0c087e34;
case 0x0c087e36u: goto P_0c087e36;
case 0x0c087e38u: goto P_0c087e38;
case 0x0c087e3au: goto P_0c087e3a;
case 0x0c087e3cu: goto P_0c087e3c;
case 0x0c087e3eu: goto P_0c087e3e;
case 0x0c087e40u: goto P_0c087e40;
case 0x0c087e42u: goto P_0c087e42;
case 0x0c087e44u: goto P_0c087e44;
case 0x0c087e46u: goto P_0c087e46;
case 0x0c087e48u: goto P_0c087e48;
case 0x0c087e4au: goto P_0c087e4a;
case 0x0c087e4cu: goto P_0c087e4c;
case 0x0c087e4eu: goto P_0c087e4e;
case 0x0c087e50u: goto P_0c087e50;
case 0x0c087e52u: goto P_0c087e52;
case 0x0c087e54u: goto P_0c087e54;
case 0x0c087e56u: goto P_0c087e56;
case 0x0c087e58u: goto P_0c087e58;
case 0x0c087e5au: goto P_0c087e5a;
case 0x0c087e5cu: goto P_0c087e5c;
case 0x0c087e5eu: goto P_0c087e5e;
case 0x0c087e60u: goto P_0c087e60;
case 0x0c087e62u: goto P_0c087e62;
case 0x0c087e64u: goto P_0c087e64;
case 0x0c087e66u: goto P_0c087e66;
case 0x0c087e68u: goto P_0c087e68;
case 0x0c087e6au: goto P_0c087e6a;
case 0x0c087e6cu: goto P_0c087e6c;
case 0x0c087e6eu: goto P_0c087e6e;
case 0x0c087e70u: goto P_0c087e70;
case 0x0c087e72u: goto P_0c087e72;
case 0x0c087e74u: goto P_0c087e74;
case 0x0c087e76u: goto P_0c087e76;
case 0x0c087e78u: goto P_0c087e78;
case 0x0c087e7au: goto P_0c087e7a;
case 0x0c087e7cu: goto P_0c087e7c;
case 0x0c087e7eu: goto P_0c087e7e;
case 0x0c087e80u: goto P_0c087e80;
case 0x0c087e82u: goto P_0c087e82;
case 0x0c087e84u: goto P_0c087e84;
case 0x0c087e86u: goto P_0c087e86;
case 0x0c087e88u: goto P_0c087e88;
case 0x0c087e8au: goto P_0c087e8a;
case 0x0c087e8cu: goto P_0c087e8c;
case 0x0c087e8eu: goto P_0c087e8e;
case 0x0c087e90u: goto P_0c087e90;
case 0x0c087e92u: goto P_0c087e92;
case 0x0c087e94u: goto P_0c087e94;
case 0x0c087e96u: goto P_0c087e96;
case 0x0c087e98u: goto P_0c087e98;
case 0x0c087e9au: goto P_0c087e9a;
case 0x0c087e9cu: goto P_0c087e9c;
case 0x0c087e9eu: goto P_0c087e9e;
case 0x0c087ea0u: goto P_0c087ea0;
case 0x0c087ebcu: goto P_0c087ebc;
case 0x0c087ebeu: goto P_0c087ebe;
case 0x0c087ec0u: goto P_0c087ec0;
case 0x0c087ec2u: goto P_0c087ec2;
case 0x0c087ec4u: goto P_0c087ec4;
case 0x0c087ec6u: goto P_0c087ec6;
case 0x0c087ec8u: goto P_0c087ec8;
case 0x0c087ecau: goto P_0c087eca;
case 0x0c087eccu: goto P_0c087ecc;
case 0x0c087eceu: goto P_0c087ece;
case 0x0c087ed0u: goto P_0c087ed0;
case 0x0c087ed2u: goto P_0c087ed2;
case 0x0c087ed4u: goto P_0c087ed4;
case 0x0c087ed6u: goto P_0c087ed6;
case 0x0c087ed8u: goto P_0c087ed8;
case 0x0c087edau: goto P_0c087eda;
case 0x0c087edcu: goto P_0c087edc;
case 0x0c087edeu: goto P_0c087ede;
case 0x0c087ee0u: goto P_0c087ee0;
case 0x0c087ee2u: goto P_0c087ee2;
case 0x0c087ee4u: goto P_0c087ee4;
case 0x0c087ee6u: goto P_0c087ee6;
case 0x0c087ee8u: goto P_0c087ee8;
case 0x0c087eeau: goto P_0c087eea;
case 0x0c087eecu: goto P_0c087eec;
case 0x0c087eeeu: goto P_0c087eee;
case 0x0c087ef0u: goto P_0c087ef0;
case 0x0c087ef2u: goto P_0c087ef2;
case 0x0c087ef4u: goto P_0c087ef4;
case 0x0c087ef6u: goto P_0c087ef6;
case 0x0c087ef8u: goto P_0c087ef8;
case 0x0c087efau: goto P_0c087efa;
case 0x0c087efcu: goto P_0c087efc;
case 0x0c087efeu: goto P_0c087efe;
case 0x0c087f00u: goto P_0c087f00;
case 0x0c087f02u: goto P_0c087f02;
case 0x0c087f04u: goto P_0c087f04;
case 0x0c087f06u: goto P_0c087f06;
case 0x0c087f08u: goto P_0c087f08;
case 0x0c087f0au: goto P_0c087f0a;
case 0x0c087f0cu: goto P_0c087f0c;
case 0x0c087f0eu: goto P_0c087f0e;
case 0x0c087f10u: goto P_0c087f10;
case 0x0c087f12u: goto P_0c087f12;
case 0x0c087f14u: goto P_0c087f14;
case 0x0c087f16u: goto P_0c087f16;
case 0x0c087f18u: goto P_0c087f18;
case 0x0c087f1au: goto P_0c087f1a;
case 0x0c087f1cu: goto P_0c087f1c;
case 0x0c087f1eu: goto P_0c087f1e;
case 0x0c087f20u: goto P_0c087f20;
case 0x0c087f22u: goto P_0c087f22;
case 0x0c087f24u: goto P_0c087f24;
case 0x0c087f26u: goto P_0c087f26;
case 0x0c087f28u: goto P_0c087f28;
case 0x0c087f2au: goto P_0c087f2a;
case 0x0c087f2cu: goto P_0c087f2c;
case 0x0c087f2eu: goto P_0c087f2e;
case 0x0c087f30u: goto P_0c087f30;
case 0x0c087f32u: goto P_0c087f32;
case 0x0c087f34u: goto P_0c087f34;
case 0x0c087f36u: goto P_0c087f36;
case 0x0c087f38u: goto P_0c087f38;
case 0x0c087f3au: goto P_0c087f3a;
case 0x0c087f3cu: goto P_0c087f3c;
case 0x0c087f3eu: goto P_0c087f3e;
case 0x0c087f40u: goto P_0c087f40;
case 0x0c087f42u: goto P_0c087f42;
case 0x0c087f44u: goto P_0c087f44;
case 0x0c087f46u: goto P_0c087f46;
case 0x0c087f48u: goto P_0c087f48;
case 0x0c087f4au: goto P_0c087f4a;
case 0x0c087f4cu: goto P_0c087f4c;
case 0x0c087f4eu: goto P_0c087f4e;
case 0x0c087f50u: goto P_0c087f50;
case 0x0c087f52u: goto P_0c087f52;
case 0x0c087f54u: goto P_0c087f54;
case 0x0c087f56u: goto P_0c087f56;
case 0x0c087f58u: goto P_0c087f58;
case 0x0c087f5au: goto P_0c087f5a;
case 0x0c087f5cu: goto P_0c087f5c;
case 0x0c087f5eu: goto P_0c087f5e;
case 0x0c087f60u: goto P_0c087f60;
case 0x0c087f62u: goto P_0c087f62;
case 0x0c087f64u: goto P_0c087f64;
case 0x0c087f66u: goto P_0c087f66;
case 0x0c087f68u: goto P_0c087f68;
case 0x0c087f6au: goto P_0c087f6a;
case 0x0c087f6cu: goto P_0c087f6c;
case 0x0c087f6eu: goto P_0c087f6e;
case 0x0c087f70u: goto P_0c087f70;
case 0x0c087f72u: goto P_0c087f72;
case 0x0c087f74u: goto P_0c087f74;
case 0x0c087f76u: goto P_0c087f76;
case 0x0c087f78u: goto P_0c087f78;
case 0x0c087f7au: goto P_0c087f7a;
case 0x0c087f7cu: goto P_0c087f7c;
case 0x0c087f7eu: goto P_0c087f7e;
case 0x0c087f80u: goto P_0c087f80;
case 0x0c087f82u: goto P_0c087f82;
case 0x0c087f84u: goto P_0c087f84;
case 0x0c087f86u: goto P_0c087f86;
case 0x0c087f88u: goto P_0c087f88;
case 0x0c087f8au: goto P_0c087f8a;
case 0x0c087f8cu: goto P_0c087f8c;
case 0x0c087f8eu: goto P_0c087f8e;
case 0x0c087f90u: goto P_0c087f90;
case 0x0c087f92u: goto P_0c087f92;
case 0x0c087f94u: goto P_0c087f94;
case 0x0c087f96u: goto P_0c087f96;
case 0x0c087f98u: goto P_0c087f98;
case 0x0c087f9au: goto P_0c087f9a;
case 0x0c087f9cu: goto P_0c087f9c;
case 0x0c087f9eu: goto P_0c087f9e;
case 0x0c087fa0u: goto P_0c087fa0;
case 0x0c087fa2u: goto P_0c087fa2;
case 0x0c087fa4u: goto P_0c087fa4;
case 0x0c087fa6u: goto P_0c087fa6;
case 0x0c087fa8u: goto P_0c087fa8;
case 0x0c087faau: goto P_0c087faa;
case 0x0c087facu: goto P_0c087fac;
case 0x0c087faeu: goto P_0c087fae;
case 0x0c087fb0u: goto P_0c087fb0;
case 0x0c087fb2u: goto P_0c087fb2;
case 0x0c087fb4u: goto P_0c087fb4;
case 0x0c087fb6u: goto P_0c087fb6;
case 0x0c087fb8u: goto P_0c087fb8;
case 0x0c087fbau: goto P_0c087fba;
case 0x0c087fbcu: goto P_0c087fbc;
case 0x0c087fbeu: goto P_0c087fbe;
case 0x0c087fc0u: goto P_0c087fc0;
case 0x0c087fc2u: goto P_0c087fc2;
case 0x0c087fc4u: goto P_0c087fc4;
case 0x0c087fc6u: goto P_0c087fc6;
case 0x0c087fc8u: goto P_0c087fc8;
case 0x0c087fcau: goto P_0c087fca;
case 0x0c087fccu: goto P_0c087fcc;
case 0x0c087fceu: goto P_0c087fce;
case 0x0c087fd0u: goto P_0c087fd0;
case 0x0c087fd2u: goto P_0c087fd2;
case 0x0c087fd4u: goto P_0c087fd4;
case 0x0c087fd6u: goto P_0c087fd6;
case 0x0c087fd8u: goto P_0c087fd8;
case 0x0c087fdau: goto P_0c087fda;
case 0x0c087fdcu: goto P_0c087fdc;
case 0x0c087fdeu: goto P_0c087fde;
case 0x0c087fe0u: goto P_0c087fe0;
case 0x0c087fe2u: goto P_0c087fe2;
case 0x0c087fe4u: goto P_0c087fe4;
case 0x0c087fe6u: goto P_0c087fe6;
case 0x0c087fe8u: goto P_0c087fe8;
case 0x0c087feau: goto P_0c087fea;
case 0x0c087fecu: goto P_0c087fec;
case 0x0c087feeu: goto P_0c087fee;
case 0x0c087ff0u: goto P_0c087ff0;
case 0x0c087ff2u: goto P_0c087ff2;
case 0x0c087ff4u: goto P_0c087ff4;
case 0x0c087ff6u: goto P_0c087ff6;
case 0x0c087ff8u: goto P_0c087ff8;
case 0x0c087ffau: goto P_0c087ffa;
case 0x0c087ffcu: goto P_0c087ffc;
case 0x0c087ffeu: goto P_0c087ffe;
case 0x0c088000u: goto P_0c088000;
case 0x0c088002u: goto P_0c088002;
case 0x0c088004u: goto P_0c088004;
case 0x0c088006u: goto P_0c088006;
case 0x0c088008u: goto P_0c088008;
case 0x0c08800au: goto P_0c08800a;
case 0x0c08800cu: goto P_0c08800c;
case 0x0c088024u: goto P_0c088024;
case 0x0c088026u: goto P_0c088026;
case 0x0c088028u: goto P_0c088028;
case 0x0c08802au: goto P_0c08802a;
case 0x0c08802cu: goto P_0c08802c;
case 0x0c08802eu: goto P_0c08802e;
case 0x0c088030u: goto P_0c088030;
case 0x0c088032u: goto P_0c088032;
case 0x0c088034u: goto P_0c088034;
case 0x0c088036u: goto P_0c088036;
case 0x0c088038u: goto P_0c088038;
case 0x0c08803au: goto P_0c08803a;
case 0x0c08803cu: goto P_0c08803c;
case 0x0c08803eu: goto P_0c08803e;
case 0x0c088040u: goto P_0c088040;
case 0x0c088042u: goto P_0c088042;
case 0x0c088044u: goto P_0c088044;
case 0x0c088046u: goto P_0c088046;
case 0x0c088048u: goto P_0c088048;
case 0x0c08804au: goto P_0c08804a;
case 0x0c08804cu: goto P_0c08804c;
case 0x0c08804eu: goto P_0c08804e;
case 0x0c088050u: goto P_0c088050;
case 0x0c088052u: goto P_0c088052;
case 0x0c088054u: goto P_0c088054;
case 0x0c088056u: goto P_0c088056;
case 0x0c088058u: goto P_0c088058;
case 0x0c08805au: goto P_0c08805a;
case 0x0c08805cu: goto P_0c08805c;
case 0x0c08805eu: goto P_0c08805e;
case 0x0c088060u: goto P_0c088060;
case 0x0c088062u: goto P_0c088062;
case 0x0c088064u: goto P_0c088064;
case 0x0c088066u: goto P_0c088066;
case 0x0c088068u: goto P_0c088068;
case 0x0c08806au: goto P_0c08806a;
case 0x0c08806cu: goto P_0c08806c;
case 0x0c08806eu: goto P_0c08806e;
case 0x0c088070u: goto P_0c088070;
case 0x0c088072u: goto P_0c088072;
case 0x0c088074u: goto P_0c088074;
case 0x0c088076u: goto P_0c088076;
case 0x0c088078u: goto P_0c088078;
case 0x0c08807au: goto P_0c08807a;
case 0x0c08807cu: goto P_0c08807c;
case 0x0c08807eu: goto P_0c08807e;
case 0x0c088080u: goto P_0c088080;
case 0x0c088082u: goto P_0c088082;
case 0x0c088084u: goto P_0c088084;
case 0x0c088086u: goto P_0c088086;
case 0x0c088088u: goto P_0c088088;
case 0x0c08808au: goto P_0c08808a;
case 0x0c08808cu: goto P_0c08808c;
case 0x0c08808eu: goto P_0c08808e;
case 0x0c088090u: goto P_0c088090;
case 0x0c088092u: goto P_0c088092;
case 0x0c088094u: goto P_0c088094;
case 0x0c088096u: goto P_0c088096;
case 0x0c088098u: goto P_0c088098;
case 0x0c08809au: goto P_0c08809a;
case 0x0c08809cu: goto P_0c08809c;
case 0x0c08809eu: goto P_0c08809e;
case 0x0c0880a0u: goto P_0c0880a0;
case 0x0c0880a2u: goto P_0c0880a2;
case 0x0c0880a4u: goto P_0c0880a4;
case 0x0c0880a6u: goto P_0c0880a6;
case 0x0c0880a8u: goto P_0c0880a8;
case 0x0c0880aau: goto P_0c0880aa;
case 0x0c0880acu: goto P_0c0880ac;
case 0x0c0880aeu: goto P_0c0880ae;
case 0x0c0880b0u: goto P_0c0880b0;
case 0x0c0880b2u: goto P_0c0880b2;
case 0x0c0880b4u: goto P_0c0880b4;
case 0x0c0880b6u: goto P_0c0880b6;
case 0x0c0880b8u: goto P_0c0880b8;
case 0x0c0880bau: goto P_0c0880ba;
case 0x0c0880bcu: goto P_0c0880bc;
case 0x0c0880beu: goto P_0c0880be;
case 0x0c0880c0u: goto P_0c0880c0;
case 0x0c0880c2u: goto P_0c0880c2;
case 0x0c0880c4u: goto P_0c0880c4;
case 0x0c0880c6u: goto P_0c0880c6;
case 0x0c0880c8u: goto P_0c0880c8;
case 0x0c0880cau: goto P_0c0880ca;
case 0x0c0880ccu: goto P_0c0880cc;
case 0x0c0880ceu: goto P_0c0880ce;
case 0x0c0880d0u: goto P_0c0880d0;
case 0x0c0880d2u: goto P_0c0880d2;
case 0x0c0880d4u: goto P_0c0880d4;
case 0x0c0880d6u: goto P_0c0880d6;
case 0x0c0880d8u: goto P_0c0880d8;
case 0x0c0880dau: goto P_0c0880da;
case 0x0c0880dcu: goto P_0c0880dc;
case 0x0c0880deu: goto P_0c0880de;
case 0x0c0880e0u: goto P_0c0880e0;
case 0x0c0880e2u: goto P_0c0880e2;
case 0x0c0880e4u: goto P_0c0880e4;
case 0x0c0880e6u: goto P_0c0880e6;
case 0x0c0880e8u: goto P_0c0880e8;
case 0x0c0880eau: goto P_0c0880ea;
case 0x0c0880ecu: goto P_0c0880ec;
case 0x0c0880eeu: goto P_0c0880ee;
case 0x0c0880f0u: goto P_0c0880f0;
case 0x0c0880f2u: goto P_0c0880f2;
case 0x0c0880f4u: goto P_0c0880f4;
case 0x0c0880f6u: goto P_0c0880f6;
case 0x0c0880f8u: goto P_0c0880f8;
case 0x0c0880fau: goto P_0c0880fa;
case 0x0c0880fcu: goto P_0c0880fc;
case 0x0c0880feu: goto P_0c0880fe;
case 0x0c088100u: goto P_0c088100;
case 0x0c088102u: goto P_0c088102;
case 0x0c088104u: goto P_0c088104;
case 0x0c088106u: goto P_0c088106;
case 0x0c088108u: goto P_0c088108;
case 0x0c08810au: goto P_0c08810a;
case 0x0c08810cu: goto P_0c08810c;
case 0x0c08810eu: goto P_0c08810e;
case 0x0c088110u: goto P_0c088110;
case 0x0c088112u: goto P_0c088112;
case 0x0c088114u: goto P_0c088114;
case 0x0c088116u: goto P_0c088116;
case 0x0c088118u: goto P_0c088118;
case 0x0c08811au: goto P_0c08811a;
case 0x0c08811cu: goto P_0c08811c;
case 0x0c08811eu: goto P_0c08811e;
case 0x0c088120u: goto P_0c088120;
case 0x0c088122u: goto P_0c088122;
case 0x0c088124u: goto P_0c088124;
case 0x0c088126u: goto P_0c088126;
case 0x0c088128u: goto P_0c088128;
case 0x0c08812au: goto P_0c08812a;
case 0x0c08812cu: goto P_0c08812c;
case 0x0c08812eu: goto P_0c08812e;
case 0x0c088130u: goto P_0c088130;
case 0x0c088132u: goto P_0c088132;
case 0x0c088134u: goto P_0c088134;
case 0x0c088136u: goto P_0c088136;
case 0x0c088138u: goto P_0c088138;
case 0x0c08dbeeu: goto P_0c08dbee;
case 0x0c08dbf0u: goto P_0c08dbf0;
case 0x0c08dbf2u: goto P_0c08dbf2;
case 0x0c08dbf4u: goto P_0c08dbf4;
case 0x0c08dbf6u: goto P_0c08dbf6;
case 0x0c08dbf8u: goto P_0c08dbf8;
case 0x0c08dbfau: goto P_0c08dbfa;
case 0x0c08dbfcu: goto P_0c08dbfc;
case 0x0c08dbfeu: goto P_0c08dbfe;
case 0x0c08dc00u: goto P_0c08dc00;
case 0x0c08dc02u: goto P_0c08dc02;
case 0x0c08dc04u: goto P_0c08dc04;
case 0x0c08dc06u: goto P_0c08dc06;
case 0x0c08dc08u: goto P_0c08dc08;
case 0x0c08dc0au: goto P_0c08dc0a;
case 0x0c08dc0cu: goto P_0c08dc0c;
case 0x0c08dc0eu: goto P_0c08dc0e;
case 0x0c08dc10u: goto P_0c08dc10;
case 0x0c08dc12u: goto P_0c08dc12;
case 0x0c08dc14u: goto P_0c08dc14;
case 0x0c08dc16u: goto P_0c08dc16;
case 0x0c08dc18u: goto P_0c08dc18;
case 0x0c08dc1au: goto P_0c08dc1a;
case 0x0c08dc1cu: goto P_0c08dc1c;
case 0x0c08dc1eu: goto P_0c08dc1e;
case 0x0c08dc20u: goto P_0c08dc20;
case 0x0c08dc22u: goto P_0c08dc22;
case 0x0c08dc24u: goto P_0c08dc24;
case 0x0c08dc26u: goto P_0c08dc26;
case 0x0c08dc28u: goto P_0c08dc28;
case 0x0c08dc2au: goto P_0c08dc2a;
case 0x0c08dc2cu: goto P_0c08dc2c;
case 0x0c08dc2eu: goto P_0c08dc2e;
case 0x0c08dc30u: goto P_0c08dc30;
case 0x0c08dc32u: goto P_0c08dc32;
case 0x0c08dc34u: goto P_0c08dc34;
case 0x0c08dc36u: goto P_0c08dc36;
case 0x0c08dc38u: goto P_0c08dc38;
case 0x0c08dc3au: goto P_0c08dc3a;
case 0x0c08dc3cu: goto P_0c08dc3c;
case 0x0c08dc4cu: goto P_0c08dc4c;
case 0x0c08dc4eu: goto P_0c08dc4e;
case 0x0c08dc50u: goto P_0c08dc50;
case 0x0c08dc52u: goto P_0c08dc52;
case 0x0c08dc54u: goto P_0c08dc54;
case 0x0c08dc56u: goto P_0c08dc56;
case 0x0c08dc58u: goto P_0c08dc58;
case 0x0c08dc5au: goto P_0c08dc5a;
case 0x0c08dc5cu: goto P_0c08dc5c;
case 0x0c08dc5eu: goto P_0c08dc5e;
case 0x0c08dc60u: goto P_0c08dc60;
case 0x0c08dc62u: goto P_0c08dc62;
case 0x0c08dc64u: goto P_0c08dc64;
case 0x0c08dc66u: goto P_0c08dc66;
case 0x0c08dc68u: goto P_0c08dc68;
case 0x0c08dc6au: goto P_0c08dc6a;
case 0x0c08dc6cu: goto P_0c08dc6c;
case 0x0c08dc6eu: goto P_0c08dc6e;
case 0x0c08dc70u: goto P_0c08dc70;
case 0x0c08dc72u: goto P_0c08dc72;
case 0x0c08dc74u: goto P_0c08dc74;
case 0x0c08dc76u: goto P_0c08dc76;
case 0x0c08dc78u: goto P_0c08dc78;
case 0x0c08dc7au: goto P_0c08dc7a;
case 0x0c08dc7cu: goto P_0c08dc7c;
case 0x0c08dc7eu: goto P_0c08dc7e;
case 0x0c08dc80u: goto P_0c08dc80;
case 0x0c08dc82u: goto P_0c08dc82;
case 0x0c08dc84u: goto P_0c08dc84;
case 0x0c08dc86u: goto P_0c08dc86;
case 0x0c08dc88u: goto P_0c08dc88;
case 0x0c08dc8au: goto P_0c08dc8a;
case 0x0c08dc8cu: goto P_0c08dc8c;
case 0x0c08dc8eu: goto P_0c08dc8e;
case 0x0c08dc90u: goto P_0c08dc90;
case 0x0c08dc92u: goto P_0c08dc92;
case 0x0c08dc94u: goto P_0c08dc94;
case 0x0c08dc96u: goto P_0c08dc96;
case 0x0c08dc98u: goto P_0c08dc98;
case 0x0c08dc9au: goto P_0c08dc9a;
case 0x0c08dc9cu: goto P_0c08dc9c;
case 0x0c08dc9eu: goto P_0c08dc9e;
case 0x0c08dca0u: goto P_0c08dca0;
case 0x0c08dca2u: goto P_0c08dca2;
case 0x0c08dca4u: goto P_0c08dca4;
case 0x0c08dca6u: goto P_0c08dca6;
case 0x0c08dca8u: goto P_0c08dca8;
case 0x0c08dcaau: goto P_0c08dcaa;
case 0x0c08dcacu: goto P_0c08dcac;
case 0x0c08dcaeu: goto P_0c08dcae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0875f0: /* original 4f22, guest PC 0x0c0875f0 */
if(!s->budget--) { s->failed_pc=0x0c0875f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0875f2;
P_0c0875f2: /* original 90c6, guest PC 0x0c0875f2 */
if(!s->budget--) { s->failed_pc=0x0c0875f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087782u,2);
goto P_0c0875f4;
P_0c0875f4: /* original 3f0c, guest PC 0x0c0875f4 */
if(!s->budget--) { s->failed_pc=0x0c0875f4u; return 0; }
r[15]+=r[0];
goto P_0c0875f6;
P_0c0875f6: /* original 2f42, guest PC 0x0c0875f6 */
if(!s->budget--) { s->failed_pc=0x0c0875f6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0875f8;
P_0c0875f8: /* original 64f3, guest PC 0x0c0875f8 */
if(!s->budget--) { s->failed_pc=0x0c0875f8u; return 0; }
r[4]=r[15];
goto P_0c0875fa;
P_0c0875fa: /* original d363, guest PC 0x0c0875fa */
if(!s->budget--) { s->failed_pc=0x0c0875fau; return 0; }
r[3]=read(ram,0x0c087788u,4);
goto P_0c0875fc;
P_0c0875fc: /* original 430b, guest PC 0x0c0875fc */
if(!s->budget--) { s->failed_pc=0x0c0875fcu; return 0; }
target=r[3];
r[16]=0x0c087600u;
r[4]+=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087600u) { target=s->pc; goto dispatch; }
goto P_0c087600;
P_0c0875fe: /* original 7444, guest PC 0x0c0875fe */
if(!s->budget--) { s->failed_pc=0x0c0875feu; return 0; }
r[4]+=0x00000044u;
goto P_0c087600;
P_0c087600: /* original d362, guest PC 0x0c087600 */
if(!s->budget--) { s->failed_pc=0x0c087600u; return 0; }
r[3]=read(ram,0x0c08778cu,4);
goto P_0c087602;
P_0c087602: /* original 430b, guest PC 0x0c087602 */
if(!s->budget--) { s->failed_pc=0x0c087602u; return 0; }
target=r[3];
r[16]=0x0c087606u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087606u) { target=s->pc; goto dispatch; }
goto P_0c087606;
P_0c087604: /* original 64f2, guest PC 0x0c087604 */
if(!s->budget--) { s->failed_pc=0x0c087604u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087606;
P_0c087606: /* original d260, guest PC 0x0c087606 */
if(!s->budget--) { s->failed_pc=0x0c087606u; return 0; }
r[2]=read(ram,0x0c087788u,4);
goto P_0c087608;
P_0c087608: /* original 64f3, guest PC 0x0c087608 */
if(!s->budget--) { s->failed_pc=0x0c087608u; return 0; }
r[4]=r[15];
goto P_0c08760a;
P_0c08760a: /* original 420b, guest PC 0x0c08760a */
if(!s->budget--) { s->failed_pc=0x0c08760au; return 0; }
target=r[2];
r[16]=0x0c08760eu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08760eu) { target=s->pc; goto dispatch; }
goto P_0c08760e;
P_0c08760c: /* original 7404, guest PC 0x0c08760c */
if(!s->budget--) { s->failed_pc=0x0c08760cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08760e;
P_0c08760e: /* original e074, guest PC 0x0c08760e */
if(!s->budget--) { s->failed_pc=0x0c08760eu; return 0; }
r[0]=0x00000074u;
goto P_0c087610;
P_0c087610: /* original 64f3, guest PC 0x0c087610 */
if(!s->budget--) { s->failed_pc=0x0c087610u; return 0; }
r[4]=r[15];
goto P_0c087612;
P_0c087612: /* original f3f6, guest PC 0x0c087612 */
if(!s->budget--) { s->failed_pc=0x0c087612u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087614;
P_0c087614: /* original e034, guest PC 0x0c087614 */
if(!s->budget--) { s->failed_pc=0x0c087614u; return 0; }
r[0]=0x00000034u;
goto P_0c087616;
P_0c087616: /* original ff37, guest PC 0x0c087616 */
if(!s->budget--) { s->failed_pc=0x0c087616u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087618;
P_0c087618: /* original e078, guest PC 0x0c087618 */
if(!s->budget--) { s->failed_pc=0x0c087618u; return 0; }
r[0]=0x00000078u;
goto P_0c08761a;
P_0c08761a: /* original f3f6, guest PC 0x0c08761a */
if(!s->budget--) { s->failed_pc=0x0c08761au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08761c;
P_0c08761c: /* original e038, guest PC 0x0c08761c */
if(!s->budget--) { s->failed_pc=0x0c08761cu; return 0; }
r[0]=0x00000038u;
goto P_0c08761e;
P_0c08761e: /* original ff37, guest PC 0x0c08761e */
if(!s->budget--) { s->failed_pc=0x0c08761eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087620;
P_0c087620: /* original e07c, guest PC 0x0c087620 */
if(!s->budget--) { s->failed_pc=0x0c087620u; return 0; }
r[0]=0x0000007cu;
goto P_0c087622;
P_0c087622: /* original f3f6, guest PC 0x0c087622 */
if(!s->budget--) { s->failed_pc=0x0c087622u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087624;
P_0c087624: /* original e03c, guest PC 0x0c087624 */
if(!s->budget--) { s->failed_pc=0x0c087624u; return 0; }
r[0]=0x0000003cu;
goto P_0c087626;
P_0c087626: /* original ff37, guest PC 0x0c087626 */
if(!s->budget--) { s->failed_pc=0x0c087626u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087628;
P_0c087628: /* original d359, guest PC 0x0c087628 */
if(!s->budget--) { s->failed_pc=0x0c087628u; return 0; }
r[3]=read(ram,0x0c087790u,4);
goto P_0c08762a;
P_0c08762a: /* original 430b, guest PC 0x0c08762a */
if(!s->budget--) { s->failed_pc=0x0c08762au; return 0; }
target=r[3];
r[16]=0x0c08762eu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08762eu) { target=s->pc; goto dispatch; }
goto P_0c08762e;
P_0c08762c: /* original 7404, guest PC 0x0c08762c */
if(!s->budget--) { s->failed_pc=0x0c08762cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08762e;
P_0c08762e: /* original 91a9, guest PC 0x0c08762e */
if(!s->budget--) { s->failed_pc=0x0c08762eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087784u,2);
goto P_0c087630;
P_0c087630: /* original 3f1c, guest PC 0x0c087630 */
if(!s->budget--) { s->failed_pc=0x0c087630u; return 0; }
r[15]+=r[1];
goto P_0c087632;
P_0c087632: /* original 4f26, guest PC 0x0c087632 */
if(!s->budget--) { s->failed_pc=0x0c087632u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087634;
P_0c087634: /* original 000b, guest PC 0x0c087634 */
if(!s->budget--) { s->failed_pc=0x0c087634u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087636: /* original 0009, guest PC 0x0c087636 */
if(!s->budget--) { s->failed_pc=0x0c087636u; return 0; }
goto P_0c087638;
P_0c087638: /* original 2fe6, guest PC 0x0c087638 */
if(!s->budget--) { s->failed_pc=0x0c087638u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08763a;
P_0c08763a: /* original 6e43, guest PC 0x0c08763a */
if(!s->budget--) { s->failed_pc=0x0c08763au; return 0; }
r[14]=r[4];
return vf3_matrix_family(0x0c08763cu,s,ram);
P_0c087698: /* original 2fe6, guest PC 0x0c087698 */
if(!s->budget--) { s->failed_pc=0x0c087698u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08769a;
P_0c08769a: /* original 6e43, guest PC 0x0c08769a */
if(!s->budget--) { s->failed_pc=0x0c08769au; return 0; }
r[14]=r[4];
return vf3_matrix_family(0x0c08769cu,s,ram);
P_0c08779c: /* original 2fe6, guest PC 0x0c08779c */
if(!s->budget--) { s->failed_pc=0x0c08779cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08779e;
P_0c08779e: /* original e008, guest PC 0x0c08779e */
if(!s->budget--) { s->failed_pc=0x0c08779eu; return 0; }
r[0]=0x00000008u;
goto P_0c0877a0;
P_0c0877a0: /* original 2fd6, guest PC 0x0c0877a0 */
if(!s->budget--) { s->failed_pc=0x0c0877a0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0877a2;
P_0c0877a2: /* original 6e43, guest PC 0x0c0877a2 */
if(!s->budget--) { s->failed_pc=0x0c0877a2u; return 0; }
r[14]=r[4];
goto P_0c0877a4;
P_0c0877a4: /* original fffb, guest PC 0x0c0877a4 */
if(!s->budget--) { s->failed_pc=0x0c0877a4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0877a6;
P_0c0877a6: /* original ffeb, guest PC 0x0c0877a6 */
if(!s->budget--) { s->failed_pc=0x0c0877a6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0877a8;
P_0c0877a8: /* original ffdb, guest PC 0x0c0877a8 */
if(!s->budget--) { s->failed_pc=0x0c0877a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0877aa;
P_0c0877aa: /* original ffcb, guest PC 0x0c0877aa */
if(!s->budget--) { s->failed_pc=0x0c0877aau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0877ac;
P_0c0877ac: /* original 4f22, guest PC 0x0c0877ac */
if(!s->budget--) { s->failed_pc=0x0c0877acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0877ae;
P_0c0877ae: /* original fc4c, guest PC 0x0c0877ae */
if(!s->budget--) { s->failed_pc=0x0c0877aeu; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0877b0;
P_0c0877b0: /* original fd5c, guest PC 0x0c0877b0 */
if(!s->budget--) { s->failed_pc=0x0c0877b0u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0877b2;
P_0c0877b2: /* original 7fe8, guest PC 0x0c0877b2 */
if(!s->budget--) { s->failed_pc=0x0c0877b2u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0877b4;
P_0c0877b4: /* original ff67, guest PC 0x0c0877b4 */
if(!s->budget--) { s->failed_pc=0x0c0877b4u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0877b6;
P_0c0877b6: /* original e014, guest PC 0x0c0877b6 */
if(!s->budget--) { s->failed_pc=0x0c0877b6u; return 0; }
r[0]=0x00000014u;
goto P_0c0877b8;
P_0c0877b8: /* original d343, guest PC 0x0c0877b8 */
if(!s->budget--) { s->failed_pc=0x0c0877b8u; return 0; }
r[3]=read(ram,0x0c0878c8u,4);
goto P_0c0877ba;
P_0c0877ba: /* original 430b, guest PC 0x0c0877ba */
if(!s->budget--) { s->failed_pc=0x0c0877bau; return 0; }
target=r[3];
r[16]=0x0c0877beu;
vf3_matrix_store(s,ram,7,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0877beu) { target=s->pc; goto dispatch; }
goto P_0c0877be;
P_0c0877bc: /* original ff77, guest PC 0x0c0877bc */
if(!s->budget--) { s->failed_pc=0x0c0877bcu; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c0877be;
P_0c0877be: /* original dd43, guest PC 0x0c0877be */
if(!s->budget--) { s->failed_pc=0x0c0877beu; return 0; }
r[13]=read(ram,0x0c0878ccu,4);
goto P_0c0877c0;
P_0c0877c0: /* original 4d0b, guest PC 0x0c0877c0 */
if(!s->budget--) { s->failed_pc=0x0c0877c0u; return 0; }
target=r[13];
r[16]=0x0c0877c4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0877c4u) { target=s->pc; goto dispatch; }
goto P_0c0877c4;
P_0c0877c2: /* original 64e3, guest PC 0x0c0877c2 */
if(!s->budget--) { s->failed_pc=0x0c0877c2u; return 0; }
r[4]=r[14];
goto P_0c0877c4;
P_0c0877c4: /* original 64e3, guest PC 0x0c0877c4 */
if(!s->budget--) { s->failed_pc=0x0c0877c4u; return 0; }
r[4]=r[14];
goto P_0c0877c6;
P_0c0877c6: /* original 4d0b, guest PC 0x0c0877c6 */
if(!s->budget--) { s->failed_pc=0x0c0877c6u; return 0; }
target=r[13];
r[16]=0x0c0877cau;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0877cau) { target=s->pc; goto dispatch; }
goto P_0c0877ca;
P_0c0877c8: /* original 7440, guest PC 0x0c0877c8 */
if(!s->budget--) { s->failed_pc=0x0c0877c8u; return 0; }
r[4]+=0x00000040u;
goto P_0c0877ca;
P_0c0877ca: /* original 947b, guest PC 0x0c0877ca */
if(!s->budget--) { s->failed_pc=0x0c0877cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0878c4u,2);
goto P_0c0877cc;
P_0c0877cc: /* original 4d0b, guest PC 0x0c0877cc */
if(!s->budget--) { s->failed_pc=0x0c0877ccu; return 0; }
target=r[13];
r[16]=0x0c0877d0u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0877d0u) { target=s->pc; goto dispatch; }
goto P_0c0877d0;
P_0c0877ce: /* original 34ec, guest PC 0x0c0877ce */
if(!s->budget--) { s->failed_pc=0x0c0877ceu; return 0; }
r[4]+=r[14];
goto P_0c0877d0;
P_0c0877d0: /* original f3dc, guest PC 0x0c0877d0 */
if(!s->budget--) { s->failed_pc=0x0c0877d0u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0877d2;
P_0c0877d2: /* original f3d2, guest PC 0x0c0877d2 */
if(!s->budget--) { s->failed_pc=0x0c0877d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c0877d4;
P_0c0877d4: /* original f0cc, guest PC 0x0c0877d4 */
if(!s->budget--) { s->failed_pc=0x0c0877d4u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c0877d6;
P_0c0877d6: /* original c73e, guest PC 0x0c0877d6 */
if(!s->budget--) { s->failed_pc=0x0c0877d6u; return 0; }
r[0]=0x0c0878d0u;
goto P_0c0877d8;
P_0c0877d8: /* original f208, guest PC 0x0c0877d8 */
if(!s->budget--) { s->failed_pc=0x0c0877d8u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0877da;
P_0c0877da: /* original f3ce, guest PC 0x0c0877da */
if(!s->budget--) { s->failed_pc=0x0c0877dau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[12],fr[3],r[18]);
goto P_0c0877dc;
P_0c0877dc: /* original f43c, guest PC 0x0c0877dc */
if(!s->budget--) { s->failed_pc=0x0c0877dcu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0877de;
P_0c0877de: /* original f245, guest PC 0x0c0877de */
if(!s->budget--) { s->failed_pc=0x0c0877deu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0877e0;
P_0c0877e0: /* original 8b0c, guest PC 0x0c0877e0 */
if(!s->budget--) { s->failed_pc=0x0c0877e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0877fc; }
goto P_0c0877e2;
P_0c0877e2: /* original e008, guest PC 0x0c0877e2 */
if(!s->budget--) { s->failed_pc=0x0c0877e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0877e4;
P_0c0877e4: /* original f38d, guest PC 0x0c0877e4 */
if(!s->budget--) { s->failed_pc=0x0c0877e4u; return 0; }
fr[3]=0;
goto P_0c0877e6;
P_0c0877e6: /* original f2f6, guest PC 0x0c0877e6 */
if(!s->budget--) { s->failed_pc=0x0c0877e6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0877e8;
P_0c0877e8: /* original f49d, guest PC 0x0c0877e8 */
if(!s->budget--) { s->failed_pc=0x0c0877e8u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0877ea;
P_0c0877ea: /* original f325, guest PC 0x0c0877ea */
if(!s->budget--) { s->failed_pc=0x0c0877eau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0877ec;
P_0c0877ec: /* original 8f02, guest PC 0x0c0877ec */
if(!s->budget--) { s->failed_pc=0x0c0877ecu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,4);
if(!cond) { goto P_0c0877f4; }
goto P_0c0877f0;
P_0c0877ee: /* original ff4c, guest PC 0x0c0877ee */
if(!s->budget--) { s->failed_pc=0x0c0877eeu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0877f0;
P_0c0877f0: /* original c738, guest PC 0x0c0877f0 */
if(!s->budget--) { s->failed_pc=0x0c0877f0u; return 0; }
r[0]=0x0c0878d4u;
goto P_0c0877f2;
P_0c0877f2: /* original ff08, guest PC 0x0c0877f2 */
if(!s->budget--) { s->failed_pc=0x0c0877f2u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0877f4;
P_0c0877f4: /* original f58d, guest PC 0x0c0877f4 */
if(!s->budget--) { s->failed_pc=0x0c0877f4u; return 0; }
fr[5]=0;
goto P_0c0877f6;
P_0c0877f6: /* original fe5c, guest PC 0x0c0877f6 */
if(!s->budget--) { s->failed_pc=0x0c0877f6u; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c0877f8;
P_0c0877f8: /* original a00e, guest PC 0x0c0877f8 */
if(!s->budget--) { s->failed_pc=0x0c0877f8u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c087818;
P_0c0877fa: /* original fd5c, guest PC 0x0c0877fa */
if(!s->budget--) { s->failed_pc=0x0c0877fau; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0877fc;
P_0c0877fc: /* original c736, guest PC 0x0c0877fc */
if(!s->budget--) { s->failed_pc=0x0c0877fcu; return 0; }
r[0]=0x0c0878d8u;
goto P_0c0877fe;
P_0c0877fe: /* original f308, guest PC 0x0c0877fe */
if(!s->budget--) { s->failed_pc=0x0c0877feu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087800;
P_0c087800: /* original f345, guest PC 0x0c087800 */
if(!s->budget--) { s->failed_pc=0x0c087800u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c087802;
P_0c087802: /* original 8b01, guest PC 0x0c087802 */
if(!s->budget--) { s->failed_pc=0x0c087802u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087808; }
goto P_0c087804;
P_0c087804: /* original a002, guest PC 0x0c087804 */
if(!s->budget--) { s->failed_pc=0x0c087804u; return 0; }
fr[14]=0;
goto P_0c08780c;
P_0c087806: /* original fe8d, guest PC 0x0c087806 */
if(!s->budget--) { s->failed_pc=0x0c087806u; return 0; }
fr[14]=0;
goto P_0c087808;
P_0c087808: /* original fe4c, guest PC 0x0c087808 */
if(!s->budget--) { s->failed_pc=0x0c087808u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c08780a;
P_0c08780a: /* original fe6d, guest PC 0x0c08780a */
if(!s->budget--) { s->failed_pc=0x0c08780au; return 0; }
fr[14]=vf3_fpu_sqrt(fr[14],r[18]);
goto P_0c08780c;
P_0c08780c: /* original f4dc, guest PC 0x0c08780c */
if(!s->budget--) { s->failed_pc=0x0c08780cu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c08780e;
P_0c08780e: /* original f4e3, guest PC 0x0c08780e */
if(!s->budget--) { s->failed_pc=0x0c08780eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'/');
goto P_0c087810;
P_0c087810: /* original fdcc, guest PC 0x0c087810 */
if(!s->budget--) { s->failed_pc=0x0c087810u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c087812;
P_0c087812: /* original fde3, guest PC 0x0c087812 */
if(!s->budget--) { s->failed_pc=0x0c087812u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'/');
goto P_0c087814;
P_0c087814: /* original e008, guest PC 0x0c087814 */
if(!s->budget--) { s->failed_pc=0x0c087814u; return 0; }
r[0]=0x00000008u;
goto P_0c087816;
P_0c087816: /* original fff6, guest PC 0x0c087816 */
if(!s->budget--) { s->failed_pc=0x0c087816u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c087818;
P_0c087818: /* original f3dc, guest PC 0x0c087818 */
if(!s->budget--) { s->failed_pc=0x0c087818u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c08781a;
P_0c08781a: /* original e004, guest PC 0x0c08781a */
if(!s->budget--) { s->failed_pc=0x0c08781au; return 0; }
r[0]=0x00000004u;
goto P_0c08781c;
P_0c08781c: /* original f34d, guest PC 0x0c08781c */
if(!s->budget--) { s->failed_pc=0x0c08781cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c08781e;
P_0c08781e: /* original ff37, guest PC 0x0c08781e */
if(!s->budget--) { s->failed_pc=0x0c08781eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087820;
P_0c087820: /* original e004, guest PC 0x0c087820 */
if(!s->budget--) { s->failed_pc=0x0c087820u; return 0; }
r[0]=0x00000004u;
goto P_0c087822;
P_0c087822: /* original fe4a, guest PC 0x0c087822 */
if(!s->budget--) { s->failed_pc=0x0c087822u; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c087824;
P_0c087824: /* original f3f6, guest PC 0x0c087824 */
if(!s->budget--) { s->failed_pc=0x0c087824u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087826;
P_0c087826: /* original e004, guest PC 0x0c087826 */
if(!s->budget--) { s->failed_pc=0x0c087826u; return 0; }
r[0]=0x00000004u;
goto P_0c087828;
P_0c087828: /* original fe37, guest PC 0x0c087828 */
if(!s->budget--) { s->failed_pc=0x0c087828u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08782a;
P_0c08782a: /* original e010, guest PC 0x0c08782a */
if(!s->budget--) { s->failed_pc=0x0c08782au; return 0; }
r[0]=0x00000010u;
goto P_0c08782c;
P_0c08782c: /* original fed7, guest PC 0x0c08782c */
if(!s->budget--) { s->failed_pc=0x0c08782cu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08782e;
P_0c08782e: /* original e014, guest PC 0x0c08782e */
if(!s->budget--) { s->failed_pc=0x0c08782eu; return 0; }
r[0]=0x00000014u;
goto P_0c087830;
P_0c087830: /* original fe47, guest PC 0x0c087830 */
if(!s->budget--) { s->failed_pc=0x0c087830u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087832;
P_0c087832: /* original bf01, guest PC 0x0c087832 */
if(!s->budget--) { s->failed_pc=0x0c087832u; return 0; }
target=0x0c087638u; r[16]=0x0c087836u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087836u) { target=s->pc; goto dispatch; }
goto P_0c087836;
P_0c087834: /* original 64e3, guest PC 0x0c087834 */
if(!s->budget--) { s->failed_pc=0x0c087834u; return 0; }
r[4]=r[14];
goto P_0c087836;
P_0c087836: /* original e054, guest PC 0x0c087836 */
if(!s->budget--) { s->failed_pc=0x0c087836u; return 0; }
r[0]=0x00000054u;
goto P_0c087838;
P_0c087838: /* original f3fc, guest PC 0x0c087838 */
if(!s->budget--) { s->failed_pc=0x0c087838u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08783a;
P_0c08783a: /* original f34d, guest PC 0x0c08783a */
if(!s->budget--) { s->failed_pc=0x0c08783au; return 0; }
fr[3]^=0x80000000u;
goto P_0c08783c;
P_0c08783c: /* original 64e3, guest PC 0x0c08783c */
if(!s->budget--) { s->failed_pc=0x0c08783cu; return 0; }
r[4]=r[14];
goto P_0c08783e;
P_0c08783e: /* original ff3a, guest PC 0x0c08783e */
if(!s->budget--) { s->failed_pc=0x0c08783eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c087840;
P_0c087840: /* original fee7, guest PC 0x0c087840 */
if(!s->budget--) { s->failed_pc=0x0c087840u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c087842;
P_0c087842: /* original e058, guest PC 0x0c087842 */
if(!s->budget--) { s->failed_pc=0x0c087842u; return 0; }
r[0]=0x00000058u;
goto P_0c087844;
P_0c087844: /* original fef7, guest PC 0x0c087844 */
if(!s->budget--) { s->failed_pc=0x0c087844u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087846;
P_0c087846: /* original e064, guest PC 0x0c087846 */
if(!s->budget--) { s->failed_pc=0x0c087846u; return 0; }
r[0]=0x00000064u;
goto P_0c087848;
P_0c087848: /* original f3f8, guest PC 0x0c087848 */
if(!s->budget--) { s->failed_pc=0x0c087848u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08784a;
P_0c08784a: /* original fe37, guest PC 0x0c08784a */
if(!s->budget--) { s->failed_pc=0x0c08784au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08784c;
P_0c08784c: /* original e068, guest PC 0x0c08784c */
if(!s->budget--) { s->failed_pc=0x0c08784cu; return 0; }
r[0]=0x00000068u;
goto P_0c08784e;
P_0c08784e: /* original fee7, guest PC 0x0c08784e */
if(!s->budget--) { s->failed_pc=0x0c08784eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c087850;
P_0c087850: /* original bece, guest PC 0x0c087850 */
if(!s->budget--) { s->failed_pc=0x0c087850u; return 0; }
target=0x0c0875f0u; r[16]=0x0c087854u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087854u) { target=s->pc; goto dispatch; }
goto P_0c087854;
P_0c087852: /* original 7440, guest PC 0x0c087852 */
if(!s->budget--) { s->failed_pc=0x0c087852u; return 0; }
r[4]+=0x00000040u;
goto P_0c087854;
P_0c087854: /* original c721, guest PC 0x0c087854 */
if(!s->budget--) { s->failed_pc=0x0c087854u; return 0; }
r[0]=0x0c0878dcu;
goto P_0c087856;
P_0c087856: /* original f408, guest PC 0x0c087856 */
if(!s->budget--) { s->failed_pc=0x0c087856u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087858;
P_0c087858: /* original e014, guest PC 0x0c087858 */
if(!s->budget--) { s->failed_pc=0x0c087858u; return 0; }
r[0]=0x00000014u;
goto P_0c08785a;
P_0c08785a: /* original f34c, guest PC 0x0c08785a */
if(!s->budget--) { s->failed_pc=0x0c08785au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08785c;
P_0c08785c: /* original f4f6, guest PC 0x0c08785c */
if(!s->budget--) { s->failed_pc=0x0c08785cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08785e;
P_0c08785e: /* original f432, guest PC 0x0c08785e */
if(!s->budget--) { s->failed_pc=0x0c08785eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087860;
P_0c087860: /* original f43d, guest PC 0x0c087860 */
if(!s->budget--) { s->failed_pc=0x0c087860u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c087862;
P_0c087862: /* original 045a, guest PC 0x0c087862 */
if(!s->budget--) { s->failed_pc=0x0c087862u; return 0; }
r[4]=r[53];
goto P_0c087864;
P_0c087864: /* original 644d, guest PC 0x0c087864 */
if(!s->budget--) { s->failed_pc=0x0c087864u; return 0; }
r[4]=r[4]&65535u;
goto P_0c087866;
P_0c087866: /* original 1f43, guest PC 0x0c087866 */
if(!s->budget--) { s->failed_pc=0x0c087866u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c087868;
P_0c087868: /* original 644f, guest PC 0x0c087868 */
if(!s->budget--) { s->failed_pc=0x0c087868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08786a;
P_0c08786a: /* original d31d, guest PC 0x0c08786a */
if(!s->budget--) { s->failed_pc=0x0c08786au; return 0; }
r[3]=read(ram,0x0c0878e0u,4);
goto P_0c08786c;
P_0c08786c: /* original 430b, guest PC 0x0c08786c */
if(!s->budget--) { s->failed_pc=0x0c08786cu; return 0; }
target=r[3];
r[16]=0x0c087870u;
write(ram,r[15]+16,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087870u) { target=s->pc; goto dispatch; }
goto P_0c087870;
P_0c08786e: /* original 1f44, guest PC 0x0c08786e */
if(!s->budget--) { s->failed_pc=0x0c08786eu; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c087870;
P_0c087870: /* original d31c, guest PC 0x0c087870 */
if(!s->budget--) { s->failed_pc=0x0c087870u; return 0; }
r[3]=read(ram,0x0c0878e4u,4);
goto P_0c087872;
P_0c087872: /* original fe0c, guest PC 0x0c087872 */
if(!s->budget--) { s->failed_pc=0x0c087872u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c087874;
P_0c087874: /* original 430b, guest PC 0x0c087874 */
if(!s->budget--) { s->failed_pc=0x0c087874u; return 0; }
target=r[3];
r[16]=0x0c087878u;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087878u) { target=s->pc; goto dispatch; }
goto P_0c087878;
P_0c087876: /* original 54f4, guest PC 0x0c087876 */
if(!s->budget--) { s->failed_pc=0x0c087876u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c087878;
P_0c087878: /* original 9024, guest PC 0x0c087878 */
if(!s->budget--) { s->failed_pc=0x0c087878u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0878c4u,2);
goto P_0c08787a;
P_0c08787a: /* original f40c, guest PC 0x0c08787a */
if(!s->budget--) { s->failed_pc=0x0c08787au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08787c;
P_0c08787c: /* original f5ec, guest PC 0x0c08787c */
if(!s->budget--) { s->failed_pc=0x0c08787cu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c08787e;
P_0c08787e: /* original f54d, guest PC 0x0c08787e */
if(!s->budget--) { s->failed_pc=0x0c08787eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c087880;
P_0c087880: /* original fe47, guest PC 0x0c087880 */
if(!s->budget--) { s->failed_pc=0x0c087880u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087882;
P_0c087882: /* original 7008, guest PC 0x0c087882 */
if(!s->budget--) { s->failed_pc=0x0c087882u; return 0; }
r[0]+=0x00000008u;
goto P_0c087884;
P_0c087884: /* original fee7, guest PC 0x0c087884 */
if(!s->budget--) { s->failed_pc=0x0c087884u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c087886;
P_0c087886: /* original 7018, guest PC 0x0c087886 */
if(!s->budget--) { s->failed_pc=0x0c087886u; return 0; }
r[0]+=0x00000018u;
goto P_0c087888;
P_0c087888: /* original fe57, guest PC 0x0c087888 */
if(!s->budget--) { s->failed_pc=0x0c087888u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08788a;
P_0c08788a: /* original 7008, guest PC 0x0c08788a */
if(!s->budget--) { s->failed_pc=0x0c08788au; return 0; }
r[0]+=0x00000008u;
goto P_0c08788c;
P_0c08788c: /* original fe47, guest PC 0x0c08788c */
if(!s->budget--) { s->failed_pc=0x0c08788cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08788e;
P_0c08788e: /* original 9419, guest PC 0x0c08788e */
if(!s->budget--) { s->failed_pc=0x0c08788eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0878c4u,2);
goto P_0c087890;
P_0c087890: /* original beae, guest PC 0x0c087890 */
if(!s->budget--) { s->failed_pc=0x0c087890u; return 0; }
target=0x0c0875f0u; r[16]=0x0c087894u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087894u) { target=s->pc; goto dispatch; }
goto P_0c087894;
P_0c087892: /* original 34ec, guest PC 0x0c087892 */
if(!s->budget--) { s->failed_pc=0x0c087892u; return 0; }
r[4]+=r[14];
goto P_0c087894;
P_0c087894: /* original f3f8, guest PC 0x0c087894 */
if(!s->budget--) { s->failed_pc=0x0c087894u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087896;
P_0c087896: /* original e058, guest PC 0x0c087896 */
if(!s->budget--) { s->failed_pc=0x0c087896u; return 0; }
r[0]=0x00000058u;
goto P_0c087898;
P_0c087898: /* original 64e3, guest PC 0x0c087898 */
if(!s->budget--) { s->failed_pc=0x0c087898u; return 0; }
r[4]=r[14];
goto P_0c08789a;
P_0c08789a: /* original fe37, guest PC 0x0c08789a */
if(!s->budget--) { s->failed_pc=0x0c08789au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08789c;
P_0c08789c: /* original e064, guest PC 0x0c08789c */
if(!s->budget--) { s->failed_pc=0x0c08789cu; return 0; }
r[0]=0x00000064u;
goto P_0c08789e;
P_0c08789e: /* original fef7, guest PC 0x0c08789e */
if(!s->budget--) { s->failed_pc=0x0c08789eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0878a0;
P_0c0878a0: /* original bea6, guest PC 0x0c0878a0 */
if(!s->budget--) { s->failed_pc=0x0c0878a0u; return 0; }
target=0x0c0875f0u; r[16]=0x0c0878a4u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0878a4u) { target=s->pc; goto dispatch; }
goto P_0c0878a4;
P_0c0878a2: /* original 7440, guest PC 0x0c0878a2 */
if(!s->budget--) { s->failed_pc=0x0c0878a2u; return 0; }
r[4]+=0x00000040u;
goto P_0c0878a4;
P_0c0878a4: /* original e004, guest PC 0x0c0878a4 */
if(!s->budget--) { s->failed_pc=0x0c0878a4u; return 0; }
r[0]=0x00000004u;
goto P_0c0878a6;
P_0c0878a6: /* original 64e3, guest PC 0x0c0878a6 */
if(!s->budget--) { s->failed_pc=0x0c0878a6u; return 0; }
r[4]=r[14];
goto P_0c0878a8;
P_0c0878a8: /* original fed7, guest PC 0x0c0878a8 */
if(!s->budget--) { s->failed_pc=0x0c0878a8u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c0878aa;
P_0c0878aa: /* original e004, guest PC 0x0c0878aa */
if(!s->budget--) { s->failed_pc=0x0c0878aau; return 0; }
r[0]=0x00000004u;
goto P_0c0878ac;
P_0c0878ac: /* original f3f6, guest PC 0x0c0878ac */
if(!s->budget--) { s->failed_pc=0x0c0878acu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0878ae;
P_0c0878ae: /* original 7f18, guest PC 0x0c0878ae */
if(!s->budget--) { s->failed_pc=0x0c0878aeu; return 0; }
r[15]+=0x00000018u;
goto P_0c0878b0;
P_0c0878b0: /* original 4f26, guest PC 0x0c0878b0 */
if(!s->budget--) { s->failed_pc=0x0c0878b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0878b2;
P_0c0878b2: /* original e010, guest PC 0x0c0878b2 */
if(!s->budget--) { s->failed_pc=0x0c0878b2u; return 0; }
r[0]=0x00000010u;
goto P_0c0878b4;
P_0c0878b4: /* original fe37, guest PC 0x0c0878b4 */
if(!s->budget--) { s->failed_pc=0x0c0878b4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0878b6;
P_0c0878b6: /* original fcf9, guest PC 0x0c0878b6 */
if(!s->budget--) { s->failed_pc=0x0c0878b6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0878b8;
P_0c0878b8: /* original fdf9, guest PC 0x0c0878b8 */
if(!s->budget--) { s->failed_pc=0x0c0878b8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0878ba;
P_0c0878ba: /* original fef9, guest PC 0x0c0878ba */
if(!s->budget--) { s->failed_pc=0x0c0878bau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0878bc;
P_0c0878bc: /* original fff9, guest PC 0x0c0878bc */
if(!s->budget--) { s->failed_pc=0x0c0878bcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0878be;
P_0c0878be: /* original 6df6, guest PC 0x0c0878be */
if(!s->budget--) { s->failed_pc=0x0c0878beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0878c0;
P_0c0878c0: /* original ae96, guest PC 0x0c0878c0 */
if(!s->budget--) { s->failed_pc=0x0c0878c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0875f0;
P_0c0878c2: /* original 6ef6, guest PC 0x0c0878c2 */
if(!s->budget--) { s->failed_pc=0x0c0878c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0878c4u,s,ram);
P_0c0878e8: /* original fffb, guest PC 0x0c0878e8 */
if(!s->budget--) { s->failed_pc=0x0c0878e8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0878ea;
P_0c0878ea: /* original ffeb, guest PC 0x0c0878ea */
if(!s->budget--) { s->failed_pc=0x0c0878eau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0878ec;
P_0c0878ec: /* original ffcb, guest PC 0x0c0878ec */
if(!s->budget--) { s->failed_pc=0x0c0878ecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0878ee;
P_0c0878ee: /* original 9099, guest PC 0x0c0878ee */
if(!s->budget--) { s->failed_pc=0x0c0878eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a24u,2);
goto P_0c0878f0;
P_0c0878f0: /* original 7ffc, guest PC 0x0c0878f0 */
if(!s->budget--) { s->failed_pc=0x0c0878f0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0878f2;
P_0c0878f2: /* original fb9d, guest PC 0x0c0878f2 */
if(!s->budget--) { s->failed_pc=0x0c0878f2u; return 0; }
fr[11]=0x3f800000u;
goto P_0c0878f4;
P_0c0878f4: /* original fa46, guest PC 0x0c0878f4 */
if(!s->budget--) { s->failed_pc=0x0c0878f4u; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c0878f6;
P_0c0878f6: /* original e070, guest PC 0x0c0878f6 */
if(!s->budget--) { s->failed_pc=0x0c0878f6u; return 0; }
r[0]=0x00000070u;
goto P_0c0878f8;
P_0c0878f8: /* original f3ac, guest PC 0x0c0878f8 */
if(!s->budget--) { s->failed_pc=0x0c0878f8u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c0878fa;
P_0c0878fa: /* original fa9d, guest PC 0x0c0878fa */
if(!s->budget--) { s->failed_pc=0x0c0878fau; return 0; }
fr[10]=0x3f800000u;
goto P_0c0878fc;
P_0c0878fc: /* original fa33, guest PC 0x0c0878fc */
if(!s->budget--) { s->failed_pc=0x0c0878fcu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'/');
goto P_0c0878fe;
P_0c0878fe: /* original f346, guest PC 0x0c0878fe */
if(!s->budget--) { s->failed_pc=0x0c0878feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087900;
P_0c087900: /* original e074, guest PC 0x0c087900 */
if(!s->budget--) { s->failed_pc=0x0c087900u; return 0; }
r[0]=0x00000074u;
goto P_0c087902;
P_0c087902: /* original f246, guest PC 0x0c087902 */
if(!s->budget--) { s->failed_pc=0x0c087902u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c087904;
P_0c087904: /* original e078, guest PC 0x0c087904 */
if(!s->budget--) { s->failed_pc=0x0c087904u; return 0; }
r[0]=0x00000078u;
goto P_0c087906;
P_0c087906: /* original ff46, guest PC 0x0c087906 */
if(!s->budget--) { s->failed_pc=0x0c087906u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c087908;
P_0c087908: /* original e070, guest PC 0x0c087908 */
if(!s->budget--) { s->failed_pc=0x0c087908u; return 0; }
r[0]=0x00000070u;
goto P_0c08790a;
P_0c08790a: /* original fab2, guest PC 0x0c08790a */
if(!s->budget--) { s->failed_pc=0x0c08790au; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c08790c;
P_0c08790c: /* original f0ac, guest PC 0x0c08790c */
if(!s->budget--) { s->failed_pc=0x0c08790cu; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c08790e;
P_0c08790e: /* original f37e, guest PC 0x0c08790e */
if(!s->budget--) { s->failed_pc=0x0c08790eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c087910;
P_0c087910: /* original f28e, guest PC 0x0c087910 */
if(!s->budget--) { s->failed_pc=0x0c087910u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c087912;
P_0c087912: /* original fe3c, guest PC 0x0c087912 */
if(!s->budget--) { s->failed_pc=0x0c087912u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c087914;
P_0c087914: /* original f3fc, guest PC 0x0c087914 */
if(!s->budget--) { s->failed_pc=0x0c087914u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c087916;
P_0c087916: /* original f39e, guest PC 0x0c087916 */
if(!s->budget--) { s->failed_pc=0x0c087916u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c087918;
P_0c087918: /* original fb2c, guest PC 0x0c087918 */
if(!s->budget--) { s->failed_pc=0x0c087918u; return 0; }
vf3_matrix_move(s,11,2);
goto P_0c08791a;
P_0c08791a: /* original ff3c, guest PC 0x0c08791a */
if(!s->budget--) { s->failed_pc=0x0c08791au; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c08791c;
P_0c08791c: /* original f4e7, guest PC 0x0c08791c */
if(!s->budget--) { s->failed_pc=0x0c08791cu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c08791e;
P_0c08791e: /* original e074, guest PC 0x0c08791e */
if(!s->budget--) { s->failed_pc=0x0c08791eu; return 0; }
r[0]=0x00000074u;
goto P_0c087920;
P_0c087920: /* original f4b7, guest PC 0x0c087920 */
if(!s->budget--) { s->failed_pc=0x0c087920u; return 0; }
vf3_matrix_store(s,ram,11,r[4]+r[0]);
goto P_0c087922;
P_0c087922: /* original e078, guest PC 0x0c087922 */
if(!s->budget--) { s->failed_pc=0x0c087922u; return 0; }
r[0]=0x00000078u;
goto P_0c087924;
P_0c087924: /* original f4f7, guest PC 0x0c087924 */
if(!s->budget--) { s->failed_pc=0x0c087924u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c087926;
P_0c087926: /* original e030, guest PC 0x0c087926 */
if(!s->budget--) { s->failed_pc=0x0c087926u; return 0; }
r[0]=0x00000030u;
goto P_0c087928;
P_0c087928: /* original ff46, guest PC 0x0c087928 */
if(!s->budget--) { s->failed_pc=0x0c087928u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08792a;
P_0c08792a: /* original e034, guest PC 0x0c08792a */
if(!s->budget--) { s->failed_pc=0x0c08792au; return 0; }
r[0]=0x00000034u;
goto P_0c08792c;
P_0c08792c: /* original fb46, guest PC 0x0c08792c */
if(!s->budget--) { s->failed_pc=0x0c08792cu; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c08792e;
P_0c08792e: /* original e038, guest PC 0x0c08792e */
if(!s->budget--) { s->failed_pc=0x0c08792eu; return 0; }
r[0]=0x00000038u;
goto P_0c087930;
P_0c087930: /* original fe46, guest PC 0x0c087930 */
if(!s->budget--) { s->failed_pc=0x0c087930u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c087932;
P_0c087932: /* original ff41, guest PC 0x0c087932 */
if(!s->budget--) { s->failed_pc=0x0c087932u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c087934;
P_0c087934: /* original fb51, guest PC 0x0c087934 */
if(!s->budget--) { s->failed_pc=0x0c087934u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'-');
goto P_0c087936;
P_0c087936: /* original f19c, guest PC 0x0c087936 */
if(!s->budget--) { s->failed_pc=0x0c087936u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c087938;
P_0c087938: /* original fe61, guest PC 0x0c087938 */
if(!s->budget--) { s->failed_pc=0x0c087938u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[6],r[18],'-');
goto P_0c08793a;
P_0c08793a: /* original f38c, guest PC 0x0c08793a */
if(!s->budget--) { s->failed_pc=0x0c08793au; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c08793c;
P_0c08793c: /* original fc7c, guest PC 0x0c08793c */
if(!s->budget--) { s->failed_pc=0x0c08793cu; return 0; }
vf3_matrix_move(s,12,7);
goto P_0c08793e;
P_0c08793e: /* original e004, guest PC 0x0c08793e */
if(!s->budget--) { s->failed_pc=0x0c08793eu; return 0; }
r[0]=0x00000004u;
goto P_0c087940;
P_0c087940: /* original f1f2, guest PC 0x0c087940 */
if(!s->budget--) { s->failed_pc=0x0c087940u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c087942;
P_0c087942: /* original f9b2, guest PC 0x0c087942 */
if(!s->budget--) { s->failed_pc=0x0c087942u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c087944;
P_0c087944: /* original f3e2, guest PC 0x0c087944 */
if(!s->budget--) { s->failed_pc=0x0c087944u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c087946;
P_0c087946: /* original f7e2, guest PC 0x0c087946 */
if(!s->budget--) { s->failed_pc=0x0c087946u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'*');
goto P_0c087948;
P_0c087948: /* original fcb2, guest PC 0x0c087948 */
if(!s->budget--) { s->failed_pc=0x0c087948u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[11],r[18],'*');
goto P_0c08794a;
P_0c08794a: /* original f8f2, guest PC 0x0c08794a */
if(!s->budget--) { s->failed_pc=0x0c08794au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c08794c;
P_0c08794c: /* original f931, guest PC 0x0c08794c */
if(!s->budget--) { s->failed_pc=0x0c08794cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c08794e;
P_0c08794e: /* original ff9a, guest PC 0x0c08794e */
if(!s->budget--) { s->failed_pc=0x0c08794eu; return 0; }
vf3_matrix_store(s,ram,9,r[15]);
goto P_0c087950;
P_0c087950: /* original f31c, guest PC 0x0c087950 */
if(!s->budget--) { s->failed_pc=0x0c087950u; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c087952;
P_0c087952: /* original f17c, guest PC 0x0c087952 */
if(!s->budget--) { s->failed_pc=0x0c087952u; return 0; }
vf3_matrix_move(s,1,7);
goto P_0c087954;
P_0c087954: /* original f131, guest PC 0x0c087954 */
if(!s->budget--) { s->failed_pc=0x0c087954u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c087956;
P_0c087956: /* original 9566, guest PC 0x0c087956 */
if(!s->budget--) { s->failed_pc=0x0c087956u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a26u,2);
goto P_0c087958;
P_0c087958: /* original f3cc, guest PC 0x0c087958 */
if(!s->budget--) { s->failed_pc=0x0c087958u; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c08795a;
P_0c08795a: /* original 354c, guest PC 0x0c08795a */
if(!s->budget--) { s->failed_pc=0x0c08795au; return 0; }
r[5]+=r[4];
goto P_0c08795c;
P_0c08795c: /* original fc8c, guest PC 0x0c08795c */
if(!s->budget--) { s->failed_pc=0x0c08795cu; return 0; }
vf3_matrix_move(s,12,8);
goto P_0c08795e;
P_0c08795e: /* original f556, guest PC 0x0c08795e */
if(!s->budget--) { s->failed_pc=0x0c08795eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c087960;
P_0c087960: /* original fc31, guest PC 0x0c087960 */
if(!s->budget--) { s->failed_pc=0x0c087960u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c087962;
P_0c087962: /* original e008, guest PC 0x0c087962 */
if(!s->budget--) { s->failed_pc=0x0c087962u; return 0; }
r[0]=0x00000008u;
goto P_0c087964;
P_0c087964: /* original f458, guest PC 0x0c087964 */
if(!s->budget--) { s->failed_pc=0x0c087964u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c087966;
P_0c087966: /* original f656, guest PC 0x0c087966 */
if(!s->budget--) { s->failed_pc=0x0c087966u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c087968;
P_0c087968: /* original e00c, guest PC 0x0c087968 */
if(!s->budget--) { s->failed_pc=0x0c087968u; return 0; }
r[0]=0x0000000cu;
goto P_0c08796a;
P_0c08796a: /* original f29c, guest PC 0x0c08796a */
if(!s->budget--) { s->failed_pc=0x0c08796au; return 0; }
vf3_matrix_move(s,2,9);
goto P_0c08796c;
P_0c08796c: /* original f756, guest PC 0x0c08796c */
if(!s->budget--) { s->failed_pc=0x0c08796cu; return 0; }
vf3_matrix_load(s,ram,7,r[5]+r[0]);
goto P_0c08796e;
P_0c08796e: /* original c730, guest PC 0x0c08796e */
if(!s->budget--) { s->failed_pc=0x0c08796eu; return 0; }
r[0]=0x0c087a30u;
goto P_0c087970;
P_0c087970: /* original f672, guest PC 0x0c087970 */
if(!s->budget--) { s->failed_pc=0x0c087970u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c087972;
P_0c087972: /* original f472, guest PC 0x0c087972 */
if(!s->budget--) { s->failed_pc=0x0c087972u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c087974;
P_0c087974: /* original f572, guest PC 0x0c087974 */
if(!s->budget--) { s->failed_pc=0x0c087974u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c087976;
P_0c087976: /* original f708, guest PC 0x0c087976 */
if(!s->budget--) { s->failed_pc=0x0c087976u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c087978;
P_0c087978: /* original fa72, guest PC 0x0c087978 */
if(!s->budget--) { s->failed_pc=0x0c087978u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c08797a;
P_0c08797a: /* original f34c, guest PC 0x0c08797a */
if(!s->budget--) { s->failed_pc=0x0c08797au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08797c;
P_0c08797c: /* original f0ac, guest PC 0x0c08797c */
if(!s->budget--) { s->failed_pc=0x0c08797cu; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c08797e;
P_0c08797e: /* original f32e, guest PC 0x0c08797e */
if(!s->budget--) { s->failed_pc=0x0c08797eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c087980;
P_0c087980: /* original f26c, guest PC 0x0c087980 */
if(!s->budget--) { s->failed_pc=0x0c087980u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c087982;
P_0c087982: /* original f2ce, guest PC 0x0c087982 */
if(!s->budget--) { s->failed_pc=0x0c087982u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[12],fr[2],r[18]);
goto P_0c087984;
P_0c087984: /* original f43c, guest PC 0x0c087984 */
if(!s->budget--) { s->failed_pc=0x0c087984u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c087986;
P_0c087986: /* original f35c, guest PC 0x0c087986 */
if(!s->budget--) { s->failed_pc=0x0c087986u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c087988;
P_0c087988: /* original f31e, guest PC 0x0c087988 */
if(!s->budget--) { s->failed_pc=0x0c087988u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c08798a;
P_0c08798a: /* original f04c, guest PC 0x0c08798a */
if(!s->budget--) { s->failed_pc=0x0c08798au; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08798c;
P_0c08798c: /* original f62c, guest PC 0x0c08798c */
if(!s->budget--) { s->failed_pc=0x0c08798cu; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c08798e;
P_0c08798e: /* original f53c, guest PC 0x0c08798e */
if(!s->budget--) { s->failed_pc=0x0c08798eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c087990;
P_0c087990: /* original f352, guest PC 0x0c087990 */
if(!s->budget--) { s->failed_pc=0x0c087990u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c087992;
P_0c087992: /* original f34e, guest PC 0x0c087992 */
if(!s->budget--) { s->failed_pc=0x0c087992u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c087994;
P_0c087994: /* original f02c, guest PC 0x0c087994 */
if(!s->budget--) { s->failed_pc=0x0c087994u; return 0; }
vf3_matrix_move(s,0,2);
goto P_0c087996;
P_0c087996: /* original f28d, guest PC 0x0c087996 */
if(!s->budget--) { s->failed_pc=0x0c087996u; return 0; }
fr[2]=0;
goto P_0c087998;
P_0c087998: /* original f36e, guest PC 0x0c087998 */
if(!s->budget--) { s->failed_pc=0x0c087998u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c08799a;
P_0c08799a: /* original f73c, guest PC 0x0c08799a */
if(!s->budget--) { s->failed_pc=0x0c08799au; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c08799c;
P_0c08799c: /* original f724, guest PC 0x0c08799c */
if(!s->budget--) { s->failed_pc=0x0c08799cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])==as_float(fr[2]))!=0);
goto P_0c08799e;
P_0c08799e: /* original 8d0c, guest PC 0x0c08799e */
if(!s->budget--) { s->failed_pc=0x0c08799eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,3);
if(cond) { goto P_0c0879ba; }
goto P_0c0879a2;
P_0c0879a0: /* original f83c, guest PC 0x0c0879a0 */
if(!s->budget--) { s->failed_pc=0x0c0879a0u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c0879a2;
P_0c0879a2: /* original c724, guest PC 0x0c0879a2 */
if(!s->budget--) { s->failed_pc=0x0c0879a2u; return 0; }
r[0]=0x0c087a34u;
goto P_0c0879a4;
P_0c0879a4: /* original f308, guest PC 0x0c0879a4 */
if(!s->budget--) { s->failed_pc=0x0c0879a4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0879a6;
P_0c0879a6: /* original f375, guest PC 0x0c0879a6 */
if(!s->budget--) { s->failed_pc=0x0c0879a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c0879a8;
P_0c0879a8: /* original 8b01, guest PC 0x0c0879a8 */
if(!s->budget--) { s->failed_pc=0x0c0879a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0879ae; }
goto P_0c0879aa;
P_0c0879aa: /* original a001, guest PC 0x0c0879aa */
if(!s->budget--) { s->failed_pc=0x0c0879aau; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0879b0;
P_0c0879ac: /* original f72c, guest PC 0x0c0879ac */
if(!s->budget--) { s->failed_pc=0x0c0879acu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0879ae;
P_0c0879ae: /* original f77d, guest PC 0x0c0879ae */
if(!s->budget--) { s->failed_pc=0x0c0879aeu; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c0879b0;
P_0c0879b0: /* original f672, guest PC 0x0c0879b0 */
if(!s->budget--) { s->failed_pc=0x0c0879b0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0879b2;
P_0c0879b2: /* original f572, guest PC 0x0c0879b2 */
if(!s->budget--) { s->failed_pc=0x0c0879b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0879b4;
P_0c0879b4: /* original f472, guest PC 0x0c0879b4 */
if(!s->budget--) { s->failed_pc=0x0c0879b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c0879b6;
P_0c0879b6: /* original a003, guest PC 0x0c0879b6 */
if(!s->budget--) { s->failed_pc=0x0c0879b6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'*');
goto P_0c0879c0;
P_0c0879b8: /* original f872, guest PC 0x0c0879b8 */
if(!s->budget--) { s->failed_pc=0x0c0879b8u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'*');
goto P_0c0879ba;
P_0c0879ba: /* original f67c, guest PC 0x0c0879ba */
if(!s->budget--) { s->failed_pc=0x0c0879bau; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0879bc;
P_0c0879bc: /* original f57c, guest PC 0x0c0879bc */
if(!s->budget--) { s->failed_pc=0x0c0879bcu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0879be;
P_0c0879be: /* original f47c, guest PC 0x0c0879be */
if(!s->budget--) { s->failed_pc=0x0c0879beu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0879c0;
P_0c0879c0: /* original 9031, guest PC 0x0c0879c0 */
if(!s->budget--) { s->failed_pc=0x0c0879c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a26u,2);
goto P_0c0879c2;
P_0c0879c2: /* original 7f04, guest PC 0x0c0879c2 */
if(!s->budget--) { s->failed_pc=0x0c0879c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0879c4;
P_0c0879c4: /* original f447, guest PC 0x0c0879c4 */
if(!s->budget--) { s->failed_pc=0x0c0879c4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0879c6;
P_0c0879c6: /* original 7004, guest PC 0x0c0879c6 */
if(!s->budget--) { s->failed_pc=0x0c0879c6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0879c8;
P_0c0879c8: /* original f457, guest PC 0x0c0879c8 */
if(!s->budget--) { s->failed_pc=0x0c0879c8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0879ca;
P_0c0879ca: /* original 7004, guest PC 0x0c0879ca */
if(!s->budget--) { s->failed_pc=0x0c0879cau; return 0; }
r[0]+=0x00000004u;
goto P_0c0879cc;
P_0c0879cc: /* original f467, guest PC 0x0c0879cc */
if(!s->budget--) { s->failed_pc=0x0c0879ccu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0879ce;
P_0c0879ce: /* original 7004, guest PC 0x0c0879ce */
if(!s->budget--) { s->failed_pc=0x0c0879ceu; return 0; }
r[0]+=0x00000004u;
goto P_0c0879d0;
P_0c0879d0: /* original f487, guest PC 0x0c0879d0 */
if(!s->budget--) { s->failed_pc=0x0c0879d0u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0879d2;
P_0c0879d2: /* original fcf9, guest PC 0x0c0879d2 */
if(!s->budget--) { s->failed_pc=0x0c0879d2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0879d4;
P_0c0879d4: /* original fef9, guest PC 0x0c0879d4 */
if(!s->budget--) { s->failed_pc=0x0c0879d4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0879d6;
P_0c0879d6: /* original 000b, guest PC 0x0c0879d6 */
if(!s->budget--) { s->failed_pc=0x0c0879d6u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c0879d8: /* original fff9, guest PC 0x0c0879d8 */
if(!s->budget--) { s->failed_pc=0x0c0879d8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c0879dau,s,ram);
P_0c087b80: /* original c718, guest PC 0x0c087b80 */
if(!s->budget--) { s->failed_pc=0x0c087b80u; return 0; }
r[0]=0x0c087be4u;
goto P_0c087b82;
P_0c087b82: /* original d319, guest PC 0x0c087b82 */
if(!s->budget--) { s->failed_pc=0x0c087b82u; return 0; }
r[3]=read(ram,0x0c087be8u,4);
goto P_0c087b84;
P_0c087b84: /* original f608, guest PC 0x0c087b84 */
if(!s->budget--) { s->failed_pc=0x0c087b84u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c087b86;
P_0c087b86: /* original e048, guest PC 0x0c087b86 */
if(!s->budget--) { s->failed_pc=0x0c087b86u; return 0; }
r[0]=0x00000048u;
goto P_0c087b88;
P_0c087b88: /* original 054e, guest PC 0x0c087b88 */
if(!s->budget--) { s->failed_pc=0x0c087b88u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087b8a;
P_0c087b8a: /* original 2358, guest PC 0x0c087b8a */
if(!s->budget--) { s->failed_pc=0x0c087b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c087b8c;
P_0c087b8c: /* original 8d05, guest PC 0x0c087b8c */
if(!s->budget--) { s->failed_pc=0x0c087b8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,6);
if(cond) { goto P_0c087b9a; }
goto P_0c087b90;
P_0c087b8e: /* original f46c, guest PC 0x0c087b8e */
if(!s->budget--) { s->failed_pc=0x0c087b8eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087b90;
P_0c087b90: /* original d116, guest PC 0x0c087b90 */
if(!s->budget--) { s->failed_pc=0x0c087b90u; return 0; }
r[1]=read(ram,0x0c087becu,4);
goto P_0c087b92;
P_0c087b92: /* original 2158, guest PC 0x0c087b92 */
if(!s->budget--) { s->failed_pc=0x0c087b92u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c087b94;
P_0c087b94: /* original 8b01, guest PC 0x0c087b94 */
if(!s->budget--) { s->failed_pc=0x0c087b94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087b9a; }
goto P_0c087b96;
P_0c087b96: /* original c716, guest PC 0x0c087b96 */
if(!s->budget--) { s->failed_pc=0x0c087b96u; return 0; }
r[0]=0x0c087bf0u;
goto P_0c087b98;
P_0c087b98: /* original f408, guest PC 0x0c087b98 */
if(!s->budget--) { s->failed_pc=0x0c087b98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087b9a;
P_0c087b9a: /* original 901e, guest PC 0x0c087b9a */
if(!s->budget--) { s->failed_pc=0x0c087b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdau,2);
goto P_0c087b9c;
P_0c087b9c: /* original 064e, guest PC 0x0c087b9c */
if(!s->budget--) { s->failed_pc=0x0c087b9cu; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c087b9e;
P_0c087b9e: /* original 7004, guest PC 0x0c087b9e */
if(!s->budget--) { s->failed_pc=0x0c087b9eu; return 0; }
r[0]+=0x00000004u;
goto P_0c087ba0;
P_0c087ba0: /* original 2668, guest PC 0x0c087ba0 */
if(!s->budget--) { s->failed_pc=0x0c087ba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087ba2;
P_0c087ba2: /* original 8d09, guest PC 0x0c087ba2 */
if(!s->budget--) { s->failed_pc=0x0c087ba2u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(cond) { goto P_0c087bb8; }
goto P_0c087ba6;
P_0c087ba4: /* original 054e, guest PC 0x0c087ba4 */
if(!s->budget--) { s->failed_pc=0x0c087ba4u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087ba6;
P_0c087ba6: /* original 2558, guest PC 0x0c087ba6 */
if(!s->budget--) { s->failed_pc=0x0c087ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087ba8;
P_0c087ba8: /* original 8b06, guest PC 0x0c087ba8 */
if(!s->budget--) { s->failed_pc=0x0c087ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087bb8; }
goto P_0c087baa;
P_0c087baa: /* original 9017, guest PC 0x0c087baa */
if(!s->budget--) { s->failed_pc=0x0c087baau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdcu,2);
goto P_0c087bac;
P_0c087bac: /* original e303, guest PC 0x0c087bac */
if(!s->budget--) { s->failed_pc=0x0c087bacu; return 0; }
r[3]=0x00000003u;
goto P_0c087bae;
P_0c087bae: /* original f346, guest PC 0x0c087bae */
if(!s->budget--) { s->failed_pc=0x0c087baeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087bb0;
P_0c087bb0: /* original 7004, guest PC 0x0c087bb0 */
if(!s->budget--) { s->failed_pc=0x0c087bb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb2;
P_0c087bb2: /* original f437, guest PC 0x0c087bb2 */
if(!s->budget--) { s->failed_pc=0x0c087bb2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c087bb4;
P_0c087bb4: /* original 7004, guest PC 0x0c087bb4 */
if(!s->budget--) { s->failed_pc=0x0c087bb4u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb6;
P_0c087bb6: /* original 0436, guest PC 0x0c087bb6 */
if(!s->budget--) { s->failed_pc=0x0c087bb6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c087bb8;
P_0c087bb8: /* original 9011, guest PC 0x0c087bb8 */
if(!s->budget--) { s->failed_pc=0x0c087bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdeu,2);
goto P_0c087bba;
P_0c087bba: /* original 054e, guest PC 0x0c087bba */
if(!s->budget--) { s->failed_pc=0x0c087bbau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087bbc;
P_0c087bbc: /* original 2558, guest PC 0x0c087bbc */
if(!s->budget--) { s->failed_pc=0x0c087bbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bbe;
P_0c087bbe: /* original 890a, guest PC 0x0c087bbe */
if(!s->budget--) { s->failed_pc=0x0c087bbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087bd6; }
goto P_0c087bc0;
P_0c087bc0: /* original 75ff, guest PC 0x0c087bc0 */
if(!s->budget--) { s->failed_pc=0x0c087bc0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c087bc2;
P_0c087bc2: /* original 2558, guest PC 0x0c087bc2 */
if(!s->budget--) { s->failed_pc=0x0c087bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bc4;
P_0c087bc4: /* original 625c, guest PC 0x0c087bc4 */
if(!s->budget--) { s->failed_pc=0x0c087bc4u; return 0; }
r[2]=r[5]&255u;
goto P_0c087bc6;
P_0c087bc6: /* original 8f06, guest PC 0x0c087bc6 */
if(!s->budget--) { s->failed_pc=0x0c087bc6u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[2],4);
if(!cond) { goto P_0c087bd6; }
goto P_0c087bca;
P_0c087bc8: /* original 0426, guest PC 0x0c087bc8 */
if(!s->budget--) { s->failed_pc=0x0c087bc8u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c087bca;
P_0c087bca: /* original 9009, guest PC 0x0c087bca */
if(!s->budget--) { s->failed_pc=0x0c087bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087be0u,2);
goto P_0c087bcc;
P_0c087bcc: /* original f546, guest PC 0x0c087bcc */
if(!s->budget--) { s->failed_pc=0x0c087bccu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c087bce;
P_0c087bce: /* original c709, guest PC 0x0c087bce */
if(!s->budget--) { s->failed_pc=0x0c087bceu; return 0; }
r[0]=0x0c087bf4u;
goto P_0c087bd0;
P_0c087bd0: /* original f008, guest PC 0x0c087bd0 */
if(!s->budget--) { s->failed_pc=0x0c087bd0u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c087bd2;
P_0c087bd2: /* original f65e, guest PC 0x0c087bd2 */
if(!s->budget--) { s->failed_pc=0x0c087bd2u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[5],fr[6],r[18]);
goto P_0c087bd4;
P_0c087bd4: /* original f46c, guest PC 0x0c087bd4 */
if(!s->budget--) { s->failed_pc=0x0c087bd4u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087bd6;
P_0c087bd6: /* original 000b, guest PC 0x0c087bd6 */
if(!s->budget--) { s->failed_pc=0x0c087bd6u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c087bd8: /* original f04c, guest PC 0x0c087bd8 */
if(!s->budget--) { s->failed_pc=0x0c087bd8u; return 0; }
vf3_matrix_move(s,0,4);
return vf3_matrix_family(0x0c087bdau,s,ram);
P_0c087bf8: /* original 2fe6, guest PC 0x0c087bf8 */
if(!s->budget--) { s->failed_pc=0x0c087bf8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfa;
P_0c087bfa: /* original 2fd6, guest PC 0x0c087bfa */
if(!s->budget--) { s->failed_pc=0x0c087bfau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfc;
P_0c087bfc: /* original 2fc6, guest PC 0x0c087bfc */
if(!s->budget--) { s->failed_pc=0x0c087bfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfe;
P_0c087bfe: /* original 2fb6, guest PC 0x0c087bfe */
if(!s->budget--) { s->failed_pc=0x0c087bfeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c00;
P_0c087c00: /* original 2fa6, guest PC 0x0c087c00 */
if(!s->budget--) { s->failed_pc=0x0c087c00u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c02;
P_0c087c02: /* original fffb, guest PC 0x0c087c02 */
if(!s->budget--) { s->failed_pc=0x0c087c02u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087c04;
P_0c087c04: /* original ffeb, guest PC 0x0c087c04 */
if(!s->budget--) { s->failed_pc=0x0c087c04u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087c06;
P_0c087c06: /* original ffdb, guest PC 0x0c087c06 */
if(!s->budget--) { s->failed_pc=0x0c087c06u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c087c08;
P_0c087c08: /* original ffcb, guest PC 0x0c087c08 */
if(!s->budget--) { s->failed_pc=0x0c087c08u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c087c0a;
P_0c087c0a: /* original 905c, guest PC 0x0c087c0a */
if(!s->budget--) { s->failed_pc=0x0c087c0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc6u,2);
goto P_0c087c0c;
P_0c087c0c: /* original f38d, guest PC 0x0c087c0c */
if(!s->budget--) { s->failed_pc=0x0c087c0cu; return 0; }
fr[3]=0;
goto P_0c087c0e;
P_0c087c0e: /* original 0c4e, guest PC 0x0c087c0e */
if(!s->budget--) { s->failed_pc=0x0c087c0eu; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c087c10;
P_0c087c10: /* original 905a, guest PC 0x0c087c10 */
if(!s->budget--) { s->failed_pc=0x0c087c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc8u,2);
goto P_0c087c12;
P_0c087c12: /* original 4f22, guest PC 0x0c087c12 */
if(!s->budget--) { s->failed_pc=0x0c087c12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087c14;
P_0c087c14: /* original fe46, guest PC 0x0c087c14 */
if(!s->budget--) { s->failed_pc=0x0c087c14u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c087c16;
P_0c087c16: /* original c72d, guest PC 0x0c087c16 */
if(!s->budget--) { s->failed_pc=0x0c087c16u; return 0; }
r[0]=0x0c087cccu;
goto P_0c087c18;
P_0c087c18: /* original f408, guest PC 0x0c087c18 */
if(!s->budget--) { s->failed_pc=0x0c087c18u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087c1a;
P_0c087c1a: /* original f5ec, guest PC 0x0c087c1a */
if(!s->budget--) { s->failed_pc=0x0c087c1au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c087c1c;
P_0c087c1c: /* original 7ffc, guest PC 0x0c087c1c */
if(!s->budget--) { s->failed_pc=0x0c087c1cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c087c1e;
P_0c087c1e: /* original f541, guest PC 0x0c087c1e */
if(!s->budget--) { s->failed_pc=0x0c087c1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c087c20;
P_0c087c20: /* original f355, guest PC 0x0c087c20 */
if(!s->budget--) { s->failed_pc=0x0c087c20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c087c22;
P_0c087c22: /* original 8900, guest PC 0x0c087c22 */
if(!s->budget--) { s->failed_pc=0x0c087c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087c26; }
goto P_0c087c24;
P_0c087c24: /* original fe4c, guest PC 0x0c087c24 */
if(!s->budget--) { s->failed_pc=0x0c087c24u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c087c26;
P_0c087c26: /* original 9050, guest PC 0x0c087c26 */
if(!s->budget--) { s->failed_pc=0x0c087c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ccau,2);
goto P_0c087c28;
P_0c087c28: /* original 65c3, guest PC 0x0c087c28 */
if(!s->budget--) { s->failed_pc=0x0c087c28u; return 0; }
r[5]=r[12];
goto P_0c087c2a;
P_0c087c2a: /* original dd29, guest PC 0x0c087c2a */
if(!s->budget--) { s->failed_pc=0x0c087c2au; return 0; }
r[13]=read(ram,0x0c087cd0u,4);
goto P_0c087c2c;
P_0c087c2c: /* original e61c, guest PC 0x0c087c2c */
if(!s->budget--) { s->failed_pc=0x0c087c2cu; return 0; }
r[6]=0x0000001cu;
goto P_0c087c2e;
P_0c087c2e: /* original f68d, guest PC 0x0c087c2e */
if(!s->budget--) { s->failed_pc=0x0c087c2eu; return 0; }
fr[6]=0;
goto P_0c087c30;
P_0c087c30: /* original eefe, guest PC 0x0c087c30 */
if(!s->budget--) { s->failed_pc=0x0c087c30u; return 0; }
r[14]=0xfffffffeu;
goto P_0c087c32;
P_0c087c32: /* original 0b4e, guest PC 0x0c087c32 */
if(!s->budget--) { s->failed_pc=0x0c087c32u; return 0; }
r[11]=read(ram,r[4]+r[0],4);
goto P_0c087c34;
P_0c087c34: /* original e700, guest PC 0x0c087c34 */
if(!s->budget--) { s->failed_pc=0x0c087c34u; return 0; }
r[7]=0x00000000u;
goto P_0c087c36;
P_0c087c36: /* original f59d, guest PC 0x0c087c36 */
if(!s->budget--) { s->failed_pc=0x0c087c36u; return 0; }
fr[5]=0x3f800000u;
goto P_0c087c38;
P_0c087c38: /* original fd6c, guest PC 0x0c087c38 */
if(!s->budget--) { s->failed_pc=0x0c087c38u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c087c3a;
P_0c087c3a: /* original f46c, guest PC 0x0c087c3a */
if(!s->budget--) { s->failed_pc=0x0c087c3au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087c3c;
P_0c087c3c: /* original 6353, guest PC 0x0c087c3c */
if(!s->budget--) { s->failed_pc=0x0c087c3cu; return 0; }
r[3]=r[5];
goto P_0c087c3e;
P_0c087c3e: /* original 6a53, guest PC 0x0c087c3e */
if(!s->budget--) { s->failed_pc=0x0c087c3eu; return 0; }
r[10]=r[5];
goto P_0c087c40;
P_0c087c40: /* original 4300, guest PC 0x0c087c40 */
if(!s->budget--) { s->failed_pc=0x0c087c40u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c087c42;
P_0c087c42: /* original 2ad9, guest PC 0x0c087c42 */
if(!s->budget--) { s->failed_pc=0x0c087c42u; return 0; }
r[10]&=r[13];
goto P_0c087c44;
P_0c087c44: /* original 6533, guest PC 0x0c087c44 */
if(!s->budget--) { s->failed_pc=0x0c087c44u; return 0; }
r[5]=r[3];
goto P_0c087c46;
P_0c087c46: /* original 2aa8, guest PC 0x0c087c46 */
if(!s->budget--) { s->failed_pc=0x0c087c46u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c087c48;
P_0c087c48: /* original 8d02, guest PC 0x0c087c48 */
if(!s->budget--) { s->failed_pc=0x0c087c48u; return 0; }
cond=r[17]&1u;
r[5]&=r[14];
if(cond) { goto P_0c087c50; }
goto P_0c087c4c;
P_0c087c4a: /* original 25e9, guest PC 0x0c087c4a */
if(!s->budget--) { s->failed_pc=0x0c087c4au; return 0; }
r[5]&=r[14];
goto P_0c087c4c;
P_0c087c4c: /* original f450, guest PC 0x0c087c4c */
if(!s->budget--) { s->failed_pc=0x0c087c4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c087c4e;
P_0c087c4e: /* original 7701, guest PC 0x0c087c4e */
if(!s->budget--) { s->failed_pc=0x0c087c4eu; return 0; }
r[7]+=0x00000001u;
goto P_0c087c50;
P_0c087c50: /* original 4610, guest PC 0x0c087c50 */
if(!s->budget--) { s->failed_pc=0x0c087c50u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c087c52;
P_0c087c52: /* original 8bf3, guest PC 0x0c087c52 */
if(!s->budget--) { s->failed_pc=0x0c087c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c3c; }
goto P_0c087c54;
P_0c087c54: /* original 2778, guest PC 0x0c087c54 */
if(!s->budget--) { s->failed_pc=0x0c087c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c087c56;
P_0c087c56: /* original 892a, guest PC 0x0c087c56 */
if(!s->budget--) { s->failed_pc=0x0c087c56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087cae; }
goto P_0c087c58;
P_0c087c58: /* original bf92, guest PC 0x0c087c58 */
if(!s->budget--) { s->failed_pc=0x0c087c58u; return 0; }
target=0x0c087b80u; r[16]=0x0c087c5cu;
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087c5cu) { target=s->pc; goto dispatch; }
goto P_0c087c5c;
P_0c087c5a: /* original fe43, guest PC 0x0c087c5a */
if(!s->budget--) { s->failed_pc=0x0c087c5au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c087c5c;
P_0c087c5c: /* original f40c, guest PC 0x0c087c5c */
if(!s->budget--) { s->failed_pc=0x0c087c5cu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087c5e;
P_0c087c5e: /* original fe42, guest PC 0x0c087c5e */
if(!s->budget--) { s->failed_pc=0x0c087c5eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c087c60;
P_0c087c60: /* original ea1c, guest PC 0x0c087c60 */
if(!s->budget--) { s->failed_pc=0x0c087c60u; return 0; }
r[10]=0x0000001cu;
goto P_0c087c62;
P_0c087c62: /* original 62c3, guest PC 0x0c087c62 */
if(!s->budget--) { s->failed_pc=0x0c087c62u; return 0; }
r[2]=r[12];
goto P_0c087c64;
P_0c087c64: /* original 64c3, guest PC 0x0c087c64 */
if(!s->budget--) { s->failed_pc=0x0c087c64u; return 0; }
r[4]=r[12];
goto P_0c087c66;
P_0c087c66: /* original 4200, guest PC 0x0c087c66 */
if(!s->budget--) { s->failed_pc=0x0c087c66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c087c68;
P_0c087c68: /* original 24d9, guest PC 0x0c087c68 */
if(!s->budget--) { s->failed_pc=0x0c087c68u; return 0; }
r[4]&=r[13];
goto P_0c087c6a;
P_0c087c6a: /* original 6c23, guest PC 0x0c087c6a */
if(!s->budget--) { s->failed_pc=0x0c087c6au; return 0; }
r[12]=r[2];
goto P_0c087c6c;
P_0c087c6c: /* original 2448, guest PC 0x0c087c6c */
if(!s->budget--) { s->failed_pc=0x0c087c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c6e;
P_0c087c6e: /* original 8d1c, guest PC 0x0c087c6e */
if(!s->budget--) { s->failed_pc=0x0c087c6eu; return 0; }
cond=r[17]&1u;
r[12]&=r[14];
if(cond) { goto P_0c087caa; }
goto P_0c087c72;
P_0c087c70: /* original 2ce9, guest PC 0x0c087c70 */
if(!s->budget--) { s->failed_pc=0x0c087c70u; return 0; }
r[12]&=r[14];
goto P_0c087c72;
P_0c087c72: /* original fcb9, guest PC 0x0c087c72 */
if(!s->budget--) { s->failed_pc=0x0c087c72u; return 0; }
vf3_matrix_load(s,ram,12,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c74;
P_0c087c74: /* original c717, guest PC 0x0c087c74 */
if(!s->budget--) { s->failed_pc=0x0c087c74u; return 0; }
r[0]=0x0c087cd4u;
goto P_0c087c76;
P_0c087c76: /* original f3b9, guest PC 0x0c087c76 */
if(!s->budget--) { s->failed_pc=0x0c087c76u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c78;
P_0c087c78: /* original ff3a, guest PC 0x0c087c78 */
if(!s->budget--) { s->failed_pc=0x0c087c78u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c087c7a;
P_0c087c7a: /* original f308, guest PC 0x0c087c7a */
if(!s->budget--) { s->failed_pc=0x0c087c7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c7c;
P_0c087c7c: /* original ffb9, guest PC 0x0c087c7c */
if(!s->budget--) { s->failed_pc=0x0c087c7cu; return 0; }
vf3_matrix_load(s,ram,15,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c7e;
P_0c087c7e: /* original ff32, guest PC 0x0c087c7e */
if(!s->budget--) { s->failed_pc=0x0c087c7eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c087c80;
P_0c087c80: /* original f5fc, guest PC 0x0c087c80 */
if(!s->budget--) { s->failed_pc=0x0c087c80u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087c82;
P_0c087c82: /* original bedd, guest PC 0x0c087c82 */
if(!s->budget--) { s->failed_pc=0x0c087c82u; return 0; }
target=0x0c087a40u; r[16]=0x0c087c86u;
vf3_matrix_move(s,4,12);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087c86u) { target=s->pc; goto dispatch; }
goto P_0c087c86;
P_0c087c84: /* original f4cc, guest PC 0x0c087c84 */
if(!s->budget--) { s->failed_pc=0x0c087c84u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087c86;
P_0c087c86: /* original 6403, guest PC 0x0c087c86 */
if(!s->budget--) { s->failed_pc=0x0c087c86u; return 0; }
r[4]=r[0];
goto P_0c087c88;
P_0c087c88: /* original 2448, guest PC 0x0c087c88 */
if(!s->budget--) { s->failed_pc=0x0c087c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c8a;
P_0c087c8a: /* original 890e, guest PC 0x0c087c8a */
if(!s->budget--) { s->failed_pc=0x0c087c8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087caa; }
goto P_0c087c8c;
P_0c087c8c: /* original c712, guest PC 0x0c087c8c */
if(!s->budget--) { s->failed_pc=0x0c087c8cu; return 0; }
r[0]=0x0c087cd8u;
goto P_0c087c8e;
P_0c087c8e: /* original f1fc, guest PC 0x0c087c8e */
if(!s->budget--) { s->failed_pc=0x0c087c8eu; return 0; }
vf3_matrix_move(s,1,15);
goto P_0c087c90;
P_0c087c90: /* original f308, guest PC 0x0c087c90 */
if(!s->budget--) { s->failed_pc=0x0c087c90u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c92;
P_0c087c92: /* original e038, guest PC 0x0c087c92 */
if(!s->budget--) { s->failed_pc=0x0c087c92u; return 0; }
r[0]=0x00000038u;
goto P_0c087c94;
P_0c087c94: /* original f246, guest PC 0x0c087c94 */
if(!s->budget--) { s->failed_pc=0x0c087c94u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c087c96;
P_0c087c96: /* original f5f8, guest PC 0x0c087c96 */
if(!s->budget--) { s->failed_pc=0x0c087c96u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c087c98;
P_0c087c98: /* original f232, guest PC 0x0c087c98 */
if(!s->budget--) { s->failed_pc=0x0c087c98u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c087c9a;
P_0c087c9a: /* original f7dc, guest PC 0x0c087c9a */
if(!s->budget--) { s->failed_pc=0x0c087c9au; return 0; }
vf3_matrix_move(s,7,13);
goto P_0c087c9c;
P_0c087c9c: /* original f9dc, guest PC 0x0c087c9c */
if(!s->budget--) { s->failed_pc=0x0c087c9cu; return 0; }
vf3_matrix_move(s,9,13);
goto P_0c087c9e;
P_0c087c9e: /* original f8ec, guest PC 0x0c087c9e */
if(!s->budget--) { s->failed_pc=0x0c087c9eu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c087ca0;
P_0c087ca0: /* original ff2c, guest PC 0x0c087ca0 */
if(!s->budget--) { s->failed_pc=0x0c087ca0u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c087ca2;
P_0c087ca2: /* original ff11, guest PC 0x0c087ca2 */
if(!s->budget--) { s->failed_pc=0x0c087ca2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'-');
goto P_0c087ca4;
P_0c087ca4: /* original f6fc, guest PC 0x0c087ca4 */
if(!s->budget--) { s->failed_pc=0x0c087ca4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c087ca6;
P_0c087ca6: /* original be1f, guest PC 0x0c087ca6 */
if(!s->budget--) { s->failed_pc=0x0c087ca6u; return 0; }
target=0x0c0878e8u; r[16]=0x0c087caau;
vf3_matrix_move(s,4,12);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087caau) { target=s->pc; goto dispatch; }
goto P_0c087caa;
P_0c087ca8: /* original f4cc, guest PC 0x0c087ca8 */
if(!s->budget--) { s->failed_pc=0x0c087ca8u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087caa;
P_0c087caa: /* original 4a10, guest PC 0x0c087caa */
if(!s->budget--) { s->failed_pc=0x0c087caau; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c087cac;
P_0c087cac: /* original 8bd9, guest PC 0x0c087cac */
if(!s->budget--) { s->failed_pc=0x0c087cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c62; }
goto P_0c087cae;
P_0c087cae: /* original 7f04, guest PC 0x0c087cae */
if(!s->budget--) { s->failed_pc=0x0c087caeu; return 0; }
r[15]+=0x00000004u;
goto P_0c087cb0;
P_0c087cb0: /* original 4f26, guest PC 0x0c087cb0 */
if(!s->budget--) { s->failed_pc=0x0c087cb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087cb2;
P_0c087cb2: /* original fcf9, guest PC 0x0c087cb2 */
if(!s->budget--) { s->failed_pc=0x0c087cb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb4;
P_0c087cb4: /* original fdf9, guest PC 0x0c087cb4 */
if(!s->budget--) { s->failed_pc=0x0c087cb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb6;
P_0c087cb6: /* original fef9, guest PC 0x0c087cb6 */
if(!s->budget--) { s->failed_pc=0x0c087cb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb8;
P_0c087cb8: /* original fff9, guest PC 0x0c087cb8 */
if(!s->budget--) { s->failed_pc=0x0c087cb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cba;
P_0c087cba: /* original 6af6, guest PC 0x0c087cba */
if(!s->budget--) { s->failed_pc=0x0c087cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c087cbc;
P_0c087cbc: /* original 6bf6, guest PC 0x0c087cbc */
if(!s->budget--) { s->failed_pc=0x0c087cbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087cbe;
P_0c087cbe: /* original 6cf6, guest PC 0x0c087cbe */
if(!s->budget--) { s->failed_pc=0x0c087cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087cc0;
P_0c087cc0: /* original 6df6, guest PC 0x0c087cc0 */
if(!s->budget--) { s->failed_pc=0x0c087cc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087cc2;
P_0c087cc2: /* original 000b, guest PC 0x0c087cc2 */
if(!s->budget--) { s->failed_pc=0x0c087cc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087cc4: /* original 6ef6, guest PC 0x0c087cc4 */
if(!s->budget--) { s->failed_pc=0x0c087cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c087cc6u,s,ram);
P_0c087e1c: /* original 4f22, guest PC 0x0c087e1c */
if(!s->budget--) { s->failed_pc=0x0c087e1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087e1e;
P_0c087e1e: /* original d322, guest PC 0x0c087e1e */
if(!s->budget--) { s->failed_pc=0x0c087e1eu; return 0; }
r[3]=read(ram,0x0c087ea8u,4);
goto P_0c087e20;
P_0c087e20: /* original 6212, guest PC 0x0c087e20 */
if(!s->budget--) { s->failed_pc=0x0c087e20u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c087e22;
P_0c087e22: /* original 7f98, guest PC 0x0c087e22 */
if(!s->budget--) { s->failed_pc=0x0c087e22u; return 0; }
r[15]+=0xffffff98u;
goto P_0c087e24;
P_0c087e24: /* original 2238, guest PC 0x0c087e24 */
if(!s->budget--) { s->failed_pc=0x0c087e24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c087e26;
P_0c087e26: /* original 8901, guest PC 0x0c087e26 */
if(!s->budget--) { s->failed_pc=0x0c087e26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087e2c; }
goto P_0c087e28;
P_0c087e28: /* original a179, guest PC 0x0c087e28 */
if(!s->budget--) { s->failed_pc=0x0c087e28u; return 0; }
goto P_0c08811e;
P_0c087e2a: /* original 0009, guest PC 0x0c087e2a */
if(!s->budget--) { s->failed_pc=0x0c087e2au; return 0; }
goto P_0c087e2c;
P_0c087e2c: /* original d320, guest PC 0x0c087e2c */
if(!s->budget--) { s->failed_pc=0x0c087e2cu; return 0; }
r[3]=read(ram,0x0c087eb0u,4);
goto P_0c087e2e;
P_0c087e2e: /* original 6d43, guest PC 0x0c087e2e */
if(!s->budget--) { s->failed_pc=0x0c087e2eu; return 0; }
r[13]=r[4];
goto P_0c087e30;
P_0c087e30: /* original 6e32, guest PC 0x0c087e30 */
if(!s->budget--) { s->failed_pc=0x0c087e30u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c087e32;
P_0c087e32: /* original bee1, guest PC 0x0c087e32 */
if(!s->budget--) { s->failed_pc=0x0c087e32u; return 0; }
target=0x0c087bf8u; r[16]=0x0c087e36u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087e36u) { target=s->pc; goto dispatch; }
goto P_0c087e36;
P_0c087e34: /* original 64e3, guest PC 0x0c087e34 */
if(!s->budget--) { s->failed_pc=0x0c087e34u; return 0; }
r[4]=r[14];
goto P_0c087e36;
P_0c087e36: /* original e028, guest PC 0x0c087e36 */
if(!s->budget--) { s->failed_pc=0x0c087e36u; return 0; }
r[0]=0x00000028u;
goto P_0c087e38;
P_0c087e38: /* original f3e6, guest PC 0x0c087e38 */
if(!s->budget--) { s->failed_pc=0x0c087e38u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087e3a;
P_0c087e3a: /* original 9032, guest PC 0x0c087e3a */
if(!s->budget--) { s->failed_pc=0x0c087e3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea2u,2);
goto P_0c087e3c;
P_0c087e3c: /* original fe37, guest PC 0x0c087e3c */
if(!s->budget--) { s->failed_pc=0x0c087e3cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087e3e;
P_0c087e3e: /* original d31d, guest PC 0x0c087e3e */
if(!s->budget--) { s->failed_pc=0x0c087e3eu; return 0; }
r[3]=read(ram,0x0c087eb4u,4);
goto P_0c087e40;
P_0c087e40: /* original 6e32, guest PC 0x0c087e40 */
if(!s->budget--) { s->failed_pc=0x0c087e40u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c087e42;
P_0c087e42: /* original bed9, guest PC 0x0c087e42 */
if(!s->budget--) { s->failed_pc=0x0c087e42u; return 0; }
target=0x0c087bf8u; r[16]=0x0c087e46u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087e46u) { target=s->pc; goto dispatch; }
goto P_0c087e46;
P_0c087e44: /* original 64e3, guest PC 0x0c087e44 */
if(!s->budget--) { s->failed_pc=0x0c087e44u; return 0; }
r[4]=r[14];
goto P_0c087e46;
P_0c087e46: /* original e028, guest PC 0x0c087e46 */
if(!s->budget--) { s->failed_pc=0x0c087e46u; return 0; }
r[0]=0x00000028u;
goto P_0c087e48;
P_0c087e48: /* original f3e6, guest PC 0x0c087e48 */
if(!s->budget--) { s->failed_pc=0x0c087e48u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087e4a;
P_0c087e4a: /* original 902a, guest PC 0x0c087e4a */
if(!s->budget--) { s->failed_pc=0x0c087e4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea2u,2);
goto P_0c087e4c;
P_0c087e4c: /* original fe37, guest PC 0x0c087e4c */
if(!s->budget--) { s->failed_pc=0x0c087e4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087e4e;
P_0c087e4e: /* original 9e29, guest PC 0x0c087e4e */
if(!s->budget--) { s->failed_pc=0x0c087e4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ea4u,2);
goto P_0c087e50;
P_0c087e50: /* original d319, guest PC 0x0c087e50 */
if(!s->budget--) { s->failed_pc=0x0c087e50u; return 0; }
r[3]=read(ram,0x0c087eb8u,4);
goto P_0c087e52;
P_0c087e52: /* original 3edc, guest PC 0x0c087e52 */
if(!s->budget--) { s->failed_pc=0x0c087e52u; return 0; }
r[14]+=r[13];
goto P_0c087e54;
P_0c087e54: /* original 430b, guest PC 0x0c087e54 */
if(!s->budget--) { s->failed_pc=0x0c087e54u; return 0; }
target=r[3];
r[16]=0x0c087e58u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087e58u) { target=s->pc; goto dispatch; }
goto P_0c087e58;
P_0c087e56: /* original e400, guest PC 0x0c087e56 */
if(!s->budget--) { s->failed_pc=0x0c087e56u; return 0; }
r[4]=0x00000000u;
goto P_0c087e58;
P_0c087e58: /* original 67f3, guest PC 0x0c087e58 */
if(!s->budget--) { s->failed_pc=0x0c087e58u; return 0; }
r[7]=r[15];
goto P_0c087e5a;
P_0c087e5a: /* original 66f3, guest PC 0x0c087e5a */
if(!s->budget--) { s->failed_pc=0x0c087e5au; return 0; }
r[6]=r[15];
goto P_0c087e5c;
P_0c087e5c: /* original 65f3, guest PC 0x0c087e5c */
if(!s->budget--) { s->failed_pc=0x0c087e5cu; return 0; }
r[5]=r[15];
goto P_0c087e5e;
P_0c087e5e: /* original 7544, guest PC 0x0c087e5e */
if(!s->budget--) { s->failed_pc=0x0c087e5eu; return 0; }
r[5]+=0x00000044u;
goto P_0c087e60;
P_0c087e60: /* original 765c, guest PC 0x0c087e60 */
if(!s->budget--) { s->failed_pc=0x0c087e60u; return 0; }
r[6]+=0x0000005cu;
goto P_0c087e62;
P_0c087e62: /* original 64f3, guest PC 0x0c087e62 */
if(!s->budget--) { s->failed_pc=0x0c087e62u; return 0; }
r[4]=r[15];
goto P_0c087e64;
P_0c087e64: /* original 7750, guest PC 0x0c087e64 */
if(!s->budget--) { s->failed_pc=0x0c087e64u; return 0; }
r[7]+=0x00000050u;
goto P_0c087e66;
P_0c087e66: /* original 6153, guest PC 0x0c087e66 */
if(!s->budget--) { s->failed_pc=0x0c087e66u; return 0; }
r[1]=r[5];
goto P_0c087e68;
P_0c087e68: /* original 6263, guest PC 0x0c087e68 */
if(!s->budget--) { s->failed_pc=0x0c087e68u; return 0; }
r[2]=r[6];
goto P_0c087e6a;
P_0c087e6a: /* original 6373, guest PC 0x0c087e6a */
if(!s->budget--) { s->failed_pc=0x0c087e6au; return 0; }
r[3]=r[7];
goto P_0c087e6c;
P_0c087e6c: /* original 7438, guest PC 0x0c087e6c */
if(!s->budget--) { s->failed_pc=0x0c087e6cu; return 0; }
r[4]+=0x00000038u;
goto P_0c087e6e;
P_0c087e6e: /* original 1f25, guest PC 0x0c087e6e */
if(!s->budget--) { s->failed_pc=0x0c087e6eu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c087e70;
P_0c087e70: /* original 1f36, guest PC 0x0c087e70 */
if(!s->budget--) { s->failed_pc=0x0c087e70u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c087e72;
P_0c087e72: /* original 6363, guest PC 0x0c087e72 */
if(!s->budget--) { s->failed_pc=0x0c087e72u; return 0; }
r[3]=r[6];
goto P_0c087e74;
P_0c087e74: /* original 1f19, guest PC 0x0c087e74 */
if(!s->budget--) { s->failed_pc=0x0c087e74u; return 0; }
write(ram,r[15]+36,r[1],4);
goto P_0c087e76;
P_0c087e76: /* original 6173, guest PC 0x0c087e76 */
if(!s->budget--) { s->failed_pc=0x0c087e76u; return 0; }
r[1]=r[7];
goto P_0c087e78;
P_0c087e78: /* original 6243, guest PC 0x0c087e78 */
if(!s->budget--) { s->failed_pc=0x0c087e78u; return 0; }
r[2]=r[4];
goto P_0c087e7a;
P_0c087e7a: /* original 6a23, guest PC 0x0c087e7a */
if(!s->budget--) { s->failed_pc=0x0c087e7au; return 0; }
r[10]=r[2];
goto P_0c087e7c;
P_0c087e7c: /* original 6b53, guest PC 0x0c087e7c */
if(!s->budget--) { s->failed_pc=0x0c087e7cu; return 0; }
r[11]=r[5];
goto P_0c087e7e;
P_0c087e7e: /* original 6873, guest PC 0x0c087e7e */
if(!s->budget--) { s->failed_pc=0x0c087e7eu; return 0; }
r[8]=r[7];
goto P_0c087e80;
P_0c087e80: /* original 6963, guest PC 0x0c087e80 */
if(!s->budget--) { s->failed_pc=0x0c087e80u; return 0; }
r[9]=r[6];
goto P_0c087e82;
P_0c087e82: /* original 7104, guest PC 0x0c087e82 */
if(!s->budget--) { s->failed_pc=0x0c087e82u; return 0; }
r[1]+=0x00000004u;
goto P_0c087e84;
P_0c087e84: /* original 7304, guest PC 0x0c087e84 */
if(!s->budget--) { s->failed_pc=0x0c087e84u; return 0; }
r[3]+=0x00000004u;
goto P_0c087e86;
P_0c087e86: /* original 1f2a, guest PC 0x0c087e86 */
if(!s->budget--) { s->failed_pc=0x0c087e86u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c087e88;
P_0c087e88: /* original 7908, guest PC 0x0c087e88 */
if(!s->budget--) { s->failed_pc=0x0c087e88u; return 0; }
r[9]+=0x00000008u;
goto P_0c087e8a;
P_0c087e8a: /* original 1f3b, guest PC 0x0c087e8a */
if(!s->budget--) { s->failed_pc=0x0c087e8au; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c087e8c;
P_0c087e8c: /* original 7508, guest PC 0x0c087e8c */
if(!s->budget--) { s->failed_pc=0x0c087e8cu; return 0; }
r[5]+=0x00000008u;
goto P_0c087e8e;
P_0c087e8e: /* original 1f1c, guest PC 0x0c087e8e */
if(!s->budget--) { s->failed_pc=0x0c087e8eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c087e90;
P_0c087e90: /* original 7808, guest PC 0x0c087e90 */
if(!s->budget--) { s->failed_pc=0x0c087e90u; return 0; }
r[8]+=0x00000008u;
goto P_0c087e92;
P_0c087e92: /* original ec08, guest PC 0x0c087e92 */
if(!s->budget--) { s->failed_pc=0x0c087e92u; return 0; }
r[12]=0x00000008u;
goto P_0c087e94;
P_0c087e94: /* original 7b04, guest PC 0x0c087e94 */
if(!s->budget--) { s->failed_pc=0x0c087e94u; return 0; }
r[11]+=0x00000004u;
goto P_0c087e96;
P_0c087e96: /* original 7a04, guest PC 0x0c087e96 */
if(!s->budget--) { s->failed_pc=0x0c087e96u; return 0; }
r[10]+=0x00000004u;
goto P_0c087e98;
P_0c087e98: /* original 7408, guest PC 0x0c087e98 */
if(!s->budget--) { s->failed_pc=0x0c087e98u; return 0; }
r[4]+=0x00000008u;
goto P_0c087e9a;
P_0c087e9a: /* original 1f58, guest PC 0x0c087e9a */
if(!s->budget--) { s->failed_pc=0x0c087e9au; return 0; }
write(ram,r[15]+32,r[5],4);
goto P_0c087e9c;
P_0c087e9c: /* original 1f47, guest PC 0x0c087e9c */
if(!s->budget--) { s->failed_pc=0x0c087e9cu; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c087e9e;
P_0c087e9e: /* original a130, guest PC 0x0c087e9e */
if(!s->budget--) { s->failed_pc=0x0c087e9eu; return 0; }
fr[14]=0;
goto P_0c088102;
P_0c087ea0: /* original fe8d, guest PC 0x0c087ea0 */
if(!s->budget--) { s->failed_pc=0x0c087ea0u; return 0; }
fr[14]=0;
return vf3_matrix_family(0x0c087ea2u,s,ram);
P_0c087ebc: /* original d354, guest PC 0x0c087ebc */
if(!s->budget--) { s->failed_pc=0x0c087ebcu; return 0; }
r[3]=read(ram,0x0c088010u,4);
goto P_0c087ebe;
P_0c087ebe: /* original 430b, guest PC 0x0c087ebe */
if(!s->budget--) { s->failed_pc=0x0c087ebeu; return 0; }
target=r[3];
r[16]=0x0c087ec2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087ec2u) { target=s->pc; goto dispatch; }
goto P_0c087ec2;
P_0c087ec0: /* original 64e3, guest PC 0x0c087ec0 */
if(!s->budget--) { s->failed_pc=0x0c087ec0u; return 0; }
r[4]=r[14];
goto P_0c087ec2;
P_0c087ec2: /* original 90a4, guest PC 0x0c087ec2 */
if(!s->budget--) { s->failed_pc=0x0c087ec2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08800eu,2);
goto P_0c087ec4;
P_0c087ec4: /* original ffe6, guest PC 0x0c087ec4 */
if(!s->budget--) { s->failed_pc=0x0c087ec4u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c087ec6;
P_0c087ec6: /* original 70fc, guest PC 0x0c087ec6 */
if(!s->budget--) { s->failed_pc=0x0c087ec6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c087ec8;
P_0c087ec8: /* original fde6, guest PC 0x0c087ec8 */
if(!s->budget--) { s->failed_pc=0x0c087ec8u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c087eca;
P_0c087eca: /* original 7008, guest PC 0x0c087eca */
if(!s->budget--) { s->failed_pc=0x0c087ecau; return 0; }
r[0]+=0x00000008u;
goto P_0c087ecc;
P_0c087ecc: /* original fce6, guest PC 0x0c087ecc */
if(!s->budget--) { s->failed_pc=0x0c087eccu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c087ece;
P_0c087ece: /* original c751, guest PC 0x0c087ece */
if(!s->budget--) { s->failed_pc=0x0c087eceu; return 0; }
r[0]=0x0c088014u;
goto P_0c087ed0;
P_0c087ed0: /* original f308, guest PC 0x0c087ed0 */
if(!s->budget--) { s->failed_pc=0x0c087ed0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087ed2;
P_0c087ed2: /* original e010, guest PC 0x0c087ed2 */
if(!s->budget--) { s->failed_pc=0x0c087ed2u; return 0; }
r[0]=0x00000010u;
goto P_0c087ed4;
P_0c087ed4: /* original ff37, guest PC 0x0c087ed4 */
if(!s->budget--) { s->failed_pc=0x0c087ed4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c087ed6;
P_0c087ed6: /* original e00c, guest PC 0x0c087ed6 */
if(!s->budget--) { s->failed_pc=0x0c087ed6u; return 0; }
r[0]=0x0000000cu;
goto P_0c087ed8;
P_0c087ed8: /* original ffe7, guest PC 0x0c087ed8 */
if(!s->budget--) { s->failed_pc=0x0c087ed8u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c087eda;
P_0c087eda: /* original c74f, guest PC 0x0c087eda */
if(!s->budget--) { s->failed_pc=0x0c087edau; return 0; }
r[0]=0x0c088018u;
goto P_0c087edc;
P_0c087edc: /* original f408, guest PC 0x0c087edc */
if(!s->budget--) { s->failed_pc=0x0c087edcu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087ede;
P_0c087ede: /* original 60c3, guest PC 0x0c087ede */
if(!s->budget--) { s->failed_pc=0x0c087edeu; return 0; }
r[0]=r[12];
goto P_0c087ee0;
P_0c087ee0: /* original 8801, guest PC 0x0c087ee0 */
if(!s->budget--) { s->failed_pc=0x0c087ee0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087ee2;
P_0c087ee2: /* original ff42, guest PC 0x0c087ee2 */
if(!s->budget--) { s->failed_pc=0x0c087ee2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c087ee4;
P_0c087ee4: /* original 8f01, guest PC 0x0c087ee4 */
if(!s->budget--) { s->failed_pc=0x0c087ee4u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
if(!cond) { goto P_0c087eea; }
goto P_0c087ee8;
P_0c087ee6: /* original fc42, guest PC 0x0c087ee6 */
if(!s->budget--) { s->failed_pc=0x0c087ee6u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c087ee8;
P_0c087ee8: /* original fcec, guest PC 0x0c087ee8 */
if(!s->budget--) { s->failed_pc=0x0c087ee8u; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c087eea;
P_0c087eea: /* original 66f3, guest PC 0x0c087eea */
if(!s->budget--) { s->failed_pc=0x0c087eeau; return 0; }
r[6]=r[15];
goto P_0c087eec;
P_0c087eec: /* original 65f3, guest PC 0x0c087eec */
if(!s->budget--) { s->failed_pc=0x0c087eecu; return 0; }
r[5]=r[15];
goto P_0c087eee;
P_0c087eee: /* original f6cc, guest PC 0x0c087eee */
if(!s->budget--) { s->failed_pc=0x0c087eeeu; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087ef0;
P_0c087ef0: /* original 7504, guest PC 0x0c087ef0 */
if(!s->budget--) { s->failed_pc=0x0c087ef0u; return 0; }
r[5]+=0x00000004u;
goto P_0c087ef2;
P_0c087ef2: /* original 7608, guest PC 0x0c087ef2 */
if(!s->budget--) { s->failed_pc=0x0c087ef2u; return 0; }
r[6]+=0x00000008u;
goto P_0c087ef4;
P_0c087ef4: /* original f4fc, guest PC 0x0c087ef4 */
if(!s->budget--) { s->failed_pc=0x0c087ef4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087ef6;
P_0c087ef6: /* original f5dc, guest PC 0x0c087ef6 */
if(!s->budget--) { s->failed_pc=0x0c087ef6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087ef8;
P_0c087ef8: /* original bbfb, guest PC 0x0c087ef8 */
if(!s->budget--) { s->failed_pc=0x0c087ef8u; return 0; }
target=0x0c0876f2u; r[16]=0x0c087efcu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087efcu) { target=s->pc; goto dispatch; }
goto P_0c087efc;
P_0c087efa: /* original 64f3, guest PC 0x0c087efa */
if(!s->budget--) { s->failed_pc=0x0c087efau; return 0; }
r[4]=r[15];
goto P_0c087efc;
P_0c087efc: /* original f4f8, guest PC 0x0c087efc */
if(!s->budget--) { s->failed_pc=0x0c087efcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087efe;
P_0c087efe: /* original bd6c, guest PC 0x0c087efe */
if(!s->budget--) { s->failed_pc=0x0c087efeu; return 0; }
target=0x0c0879dau; r[16]=0x0c087f02u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087f02u) { target=s->pc; goto dispatch; }
goto P_0c087f02;
P_0c087f00: /* original 64d3, guest PC 0x0c087f00 */
if(!s->budget--) { s->failed_pc=0x0c087f00u; return 0; }
r[4]=r[13];
goto P_0c087f02;
P_0c087f02: /* original e004, guest PC 0x0c087f02 */
if(!s->budget--) { s->failed_pc=0x0c087f02u; return 0; }
r[0]=0x00000004u;
goto P_0c087f04;
P_0c087f04: /* original f40c, guest PC 0x0c087f04 */
if(!s->budget--) { s->failed_pc=0x0c087f04u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087f06;
P_0c087f06: /* original f3f6, guest PC 0x0c087f06 */
if(!s->budget--) { s->failed_pc=0x0c087f06u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f08;
P_0c087f08: /* original f28d, guest PC 0x0c087f08 */
if(!s->budget--) { s->failed_pc=0x0c087f08u; return 0; }
fr[2]=0;
goto P_0c087f0a;
P_0c087f0a: /* original f431, guest PC 0x0c087f0a */
if(!s->budget--) { s->failed_pc=0x0c087f0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087f0c;
P_0c087f0c: /* original f245, guest PC 0x0c087f0c */
if(!s->budget--) { s->failed_pc=0x0c087f0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087f0e;
P_0c087f0e: /* original 8b01, guest PC 0x0c087f0e */
if(!s->budget--) { s->failed_pc=0x0c087f0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087f14; }
goto P_0c087f10;
P_0c087f10: /* original e00c, guest PC 0x0c087f10 */
if(!s->budget--) { s->failed_pc=0x0c087f10u; return 0; }
r[0]=0x0000000cu;
goto P_0c087f12;
P_0c087f12: /* original f4f6, guest PC 0x0c087f12 */
if(!s->budget--) { s->failed_pc=0x0c087f12u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f14;
P_0c087f14: /* original e010, guest PC 0x0c087f14 */
if(!s->budget--) { s->failed_pc=0x0c087f14u; return 0; }
r[0]=0x00000010u;
goto P_0c087f16;
P_0c087f16: /* original f34c, guest PC 0x0c087f16 */
if(!s->budget--) { s->failed_pc=0x0c087f16u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087f18;
P_0c087f18: /* original f4f6, guest PC 0x0c087f18 */
if(!s->budget--) { s->failed_pc=0x0c087f18u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f1a;
P_0c087f1a: /* original e004, guest PC 0x0c087f1a */
if(!s->budget--) { s->failed_pc=0x0c087f1au; return 0; }
r[0]=0x00000004u;
goto P_0c087f1c;
P_0c087f1c: /* original 53f5, guest PC 0x0c087f1c */
if(!s->budget--) { s->failed_pc=0x0c087f1cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c087f1e;
P_0c087f1e: /* original f432, guest PC 0x0c087f1e */
if(!s->budget--) { s->failed_pc=0x0c087f1eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087f20;
P_0c087f20: /* original f3f8, guest PC 0x0c087f20 */
if(!s->budget--) { s->failed_pc=0x0c087f20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087f22;
P_0c087f22: /* original f33a, guest PC 0x0c087f22 */
if(!s->budget--) { s->failed_pc=0x0c087f22u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f24;
P_0c087f24: /* original f3f6, guest PC 0x0c087f24 */
if(!s->budget--) { s->failed_pc=0x0c087f24u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f26;
P_0c087f26: /* original e008, guest PC 0x0c087f26 */
if(!s->budget--) { s->failed_pc=0x0c087f26u; return 0; }
r[0]=0x00000008u;
goto P_0c087f28;
P_0c087f28: /* original 53f6, guest PC 0x0c087f28 */
if(!s->budget--) { s->failed_pc=0x0c087f28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c087f2a;
P_0c087f2a: /* original f33a, guest PC 0x0c087f2a */
if(!s->budget--) { s->failed_pc=0x0c087f2au; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f2c;
P_0c087f2c: /* original f3f6, guest PC 0x0c087f2c */
if(!s->budget--) { s->failed_pc=0x0c087f2cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f2e;
P_0c087f2e: /* original 60c3, guest PC 0x0c087f2e */
if(!s->budget--) { s->failed_pc=0x0c087f2eu; return 0; }
r[0]=r[12];
goto P_0c087f30;
P_0c087f30: /* original 53f9, guest PC 0x0c087f30 */
if(!s->budget--) { s->failed_pc=0x0c087f30u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c087f32;
P_0c087f32: /* original 8801, guest PC 0x0c087f32 */
if(!s->budget--) { s->failed_pc=0x0c087f32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087f34;
P_0c087f34: /* original f33a, guest PC 0x0c087f34 */
if(!s->budget--) { s->failed_pc=0x0c087f34u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f36;
P_0c087f36: /* original 53fa, guest PC 0x0c087f36 */
if(!s->budget--) { s->failed_pc=0x0c087f36u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c087f38;
P_0c087f38: /* original f34a, guest PC 0x0c087f38 */
if(!s->budget--) { s->failed_pc=0x0c087f38u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c087f3a;
P_0c087f3a: /* original 8f01, guest PC 0x0c087f3a */
if(!s->budget--) { s->failed_pc=0x0c087f3au; return 0; }
cond=r[17]&1u;
fr[12]^=0x80000000u;
if(!cond) { goto P_0c087f40; }
goto P_0c087f3e;
P_0c087f3c: /* original fc4d, guest PC 0x0c087f3c */
if(!s->budget--) { s->failed_pc=0x0c087f3cu; return 0; }
fr[12]^=0x80000000u;
goto P_0c087f3e;
P_0c087f3e: /* original ff4d, guest PC 0x0c087f3e */
if(!s->budget--) { s->failed_pc=0x0c087f3eu; return 0; }
fr[15]^=0x80000000u;
goto P_0c087f40;
P_0c087f40: /* original 66f3, guest PC 0x0c087f40 */
if(!s->budget--) { s->failed_pc=0x0c087f40u; return 0; }
r[6]=r[15];
goto P_0c087f42;
P_0c087f42: /* original 65f3, guest PC 0x0c087f42 */
if(!s->budget--) { s->failed_pc=0x0c087f42u; return 0; }
r[5]=r[15];
goto P_0c087f44;
P_0c087f44: /* original f6cc, guest PC 0x0c087f44 */
if(!s->budget--) { s->failed_pc=0x0c087f44u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087f46;
P_0c087f46: /* original 7504, guest PC 0x0c087f46 */
if(!s->budget--) { s->failed_pc=0x0c087f46u; return 0; }
r[5]+=0x00000004u;
goto P_0c087f48;
P_0c087f48: /* original 7608, guest PC 0x0c087f48 */
if(!s->budget--) { s->failed_pc=0x0c087f48u; return 0; }
r[6]+=0x00000008u;
goto P_0c087f4a;
P_0c087f4a: /* original f4fc, guest PC 0x0c087f4a */
if(!s->budget--) { s->failed_pc=0x0c087f4au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087f4c;
P_0c087f4c: /* original f5dc, guest PC 0x0c087f4c */
if(!s->budget--) { s->failed_pc=0x0c087f4cu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087f4e;
P_0c087f4e: /* original bbd0, guest PC 0x0c087f4e */
if(!s->budget--) { s->failed_pc=0x0c087f4eu; return 0; }
target=0x0c0876f2u; r[16]=0x0c087f52u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087f52u) { target=s->pc; goto dispatch; }
goto P_0c087f52;
P_0c087f50: /* original 64f3, guest PC 0x0c087f50 */
if(!s->budget--) { s->failed_pc=0x0c087f50u; return 0; }
r[4]=r[15];
goto P_0c087f52;
P_0c087f52: /* original f4f8, guest PC 0x0c087f52 */
if(!s->budget--) { s->failed_pc=0x0c087f52u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087f54;
P_0c087f54: /* original bd41, guest PC 0x0c087f54 */
if(!s->budget--) { s->failed_pc=0x0c087f54u; return 0; }
target=0x0c0879dau; r[16]=0x0c087f58u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087f58u) { target=s->pc; goto dispatch; }
goto P_0c087f58;
P_0c087f56: /* original 64d3, guest PC 0x0c087f56 */
if(!s->budget--) { s->failed_pc=0x0c087f56u; return 0; }
r[4]=r[13];
goto P_0c087f58;
P_0c087f58: /* original e004, guest PC 0x0c087f58 */
if(!s->budget--) { s->failed_pc=0x0c087f58u; return 0; }
r[0]=0x00000004u;
goto P_0c087f5a;
P_0c087f5a: /* original f40c, guest PC 0x0c087f5a */
if(!s->budget--) { s->failed_pc=0x0c087f5au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087f5c;
P_0c087f5c: /* original f3f6, guest PC 0x0c087f5c */
if(!s->budget--) { s->failed_pc=0x0c087f5cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f5e;
P_0c087f5e: /* original f28d, guest PC 0x0c087f5e */
if(!s->budget--) { s->failed_pc=0x0c087f5eu; return 0; }
fr[2]=0;
goto P_0c087f60;
P_0c087f60: /* original f431, guest PC 0x0c087f60 */
if(!s->budget--) { s->failed_pc=0x0c087f60u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087f62;
P_0c087f62: /* original f245, guest PC 0x0c087f62 */
if(!s->budget--) { s->failed_pc=0x0c087f62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087f64;
P_0c087f64: /* original 8f02, guest PC 0x0c087f64 */
if(!s->budget--) { s->failed_pc=0x0c087f64u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,13);
if(!cond) { goto P_0c087f6c; }
goto P_0c087f68;
P_0c087f66: /* original f5dc, guest PC 0x0c087f66 */
if(!s->budget--) { s->failed_pc=0x0c087f66u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087f68;
P_0c087f68: /* original e00c, guest PC 0x0c087f68 */
if(!s->budget--) { s->failed_pc=0x0c087f68u; return 0; }
r[0]=0x0000000cu;
goto P_0c087f6a;
P_0c087f6a: /* original f4f6, guest PC 0x0c087f6a */
if(!s->budget--) { s->failed_pc=0x0c087f6au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f6c;
P_0c087f6c: /* original f54d, guest PC 0x0c087f6c */
if(!s->budget--) { s->failed_pc=0x0c087f6cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c087f6e;
P_0c087f6e: /* original f65c, guest PC 0x0c087f6e */
if(!s->budget--) { s->failed_pc=0x0c087f6eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c087f70;
P_0c087f70: /* original f641, guest PC 0x0c087f70 */
if(!s->budget--) { s->failed_pc=0x0c087f70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c087f72;
P_0c087f72: /* original f38d, guest PC 0x0c087f72 */
if(!s->budget--) { s->failed_pc=0x0c087f72u; return 0; }
fr[3]=0;
goto P_0c087f74;
P_0c087f74: /* original f365, guest PC 0x0c087f74 */
if(!s->budget--) { s->failed_pc=0x0c087f74u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c087f76;
P_0c087f76: /* original 8b00, guest PC 0x0c087f76 */
if(!s->budget--) { s->failed_pc=0x0c087f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087f7a; }
goto P_0c087f78;
P_0c087f78: /* original f45c, guest PC 0x0c087f78 */
if(!s->budget--) { s->failed_pc=0x0c087f78u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c087f7a;
P_0c087f7a: /* original e010, guest PC 0x0c087f7a */
if(!s->budget--) { s->failed_pc=0x0c087f7au; return 0; }
r[0]=0x00000010u;
goto P_0c087f7c;
P_0c087f7c: /* original f34c, guest PC 0x0c087f7c */
if(!s->budget--) { s->failed_pc=0x0c087f7cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087f7e;
P_0c087f7e: /* original f4f6, guest PC 0x0c087f7e */
if(!s->budget--) { s->failed_pc=0x0c087f7eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087f80;
P_0c087f80: /* original e004, guest PC 0x0c087f80 */
if(!s->budget--) { s->failed_pc=0x0c087f80u; return 0; }
r[0]=0x00000004u;
goto P_0c087f82;
P_0c087f82: /* original 53fb, guest PC 0x0c087f82 */
if(!s->budget--) { s->failed_pc=0x0c087f82u; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c087f84;
P_0c087f84: /* original f432, guest PC 0x0c087f84 */
if(!s->budget--) { s->failed_pc=0x0c087f84u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087f86;
P_0c087f86: /* original f3f8, guest PC 0x0c087f86 */
if(!s->budget--) { s->failed_pc=0x0c087f86u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087f88;
P_0c087f88: /* original f33a, guest PC 0x0c087f88 */
if(!s->budget--) { s->failed_pc=0x0c087f88u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f8a;
P_0c087f8a: /* original f3f6, guest PC 0x0c087f8a */
if(!s->budget--) { s->failed_pc=0x0c087f8au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f8c;
P_0c087f8c: /* original e008, guest PC 0x0c087f8c */
if(!s->budget--) { s->failed_pc=0x0c087f8cu; return 0; }
r[0]=0x00000008u;
goto P_0c087f8e;
P_0c087f8e: /* original 53fc, guest PC 0x0c087f8e */
if(!s->budget--) { s->failed_pc=0x0c087f8eu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c087f90;
P_0c087f90: /* original f33a, guest PC 0x0c087f90 */
if(!s->budget--) { s->failed_pc=0x0c087f90u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c087f92;
P_0c087f92: /* original f3f6, guest PC 0x0c087f92 */
if(!s->budget--) { s->failed_pc=0x0c087f92u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087f94;
P_0c087f94: /* original 60c3, guest PC 0x0c087f94 */
if(!s->budget--) { s->failed_pc=0x0c087f94u; return 0; }
r[0]=r[12];
goto P_0c087f96;
P_0c087f96: /* original 8801, guest PC 0x0c087f96 */
if(!s->budget--) { s->failed_pc=0x0c087f96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c087f98;
P_0c087f98: /* original fb3a, guest PC 0x0c087f98 */
if(!s->budget--) { s->failed_pc=0x0c087f98u; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c087f9a;
P_0c087f9a: /* original 8f05, guest PC 0x0c087f9a */
if(!s->budget--) { s->failed_pc=0x0c087f9au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[10]);
if(!cond) { goto P_0c087fa8; }
goto P_0c087f9e;
P_0c087f9c: /* original fa4a, guest PC 0x0c087f9c */
if(!s->budget--) { s->failed_pc=0x0c087f9cu; return 0; }
vf3_matrix_store(s,ram,4,r[10]);
goto P_0c087f9e;
P_0c087f9e: /* original c71f, guest PC 0x0c087f9e */
if(!s->budget--) { s->failed_pc=0x0c087f9eu; return 0; }
r[0]=0x0c08801cu;
goto P_0c087fa0;
P_0c087fa0: /* original ffec, guest PC 0x0c087fa0 */
if(!s->budget--) { s->failed_pc=0x0c087fa0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c087fa2;
P_0c087fa2: /* original fd08, guest PC 0x0c087fa2 */
if(!s->budget--) { s->failed_pc=0x0c087fa2u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c087fa4;
P_0c087fa4: /* original c71e, guest PC 0x0c087fa4 */
if(!s->budget--) { s->failed_pc=0x0c087fa4u; return 0; }
r[0]=0x0c088020u;
goto P_0c087fa6;
P_0c087fa6: /* original fc08, guest PC 0x0c087fa6 */
if(!s->budget--) { s->failed_pc=0x0c087fa6u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c087fa8;
P_0c087fa8: /* original 66f3, guest PC 0x0c087fa8 */
if(!s->budget--) { s->failed_pc=0x0c087fa8u; return 0; }
r[6]=r[15];
goto P_0c087faa;
P_0c087faa: /* original 65f3, guest PC 0x0c087faa */
if(!s->budget--) { s->failed_pc=0x0c087faau; return 0; }
r[5]=r[15];
goto P_0c087fac;
P_0c087fac: /* original ff4d, guest PC 0x0c087fac */
if(!s->budget--) { s->failed_pc=0x0c087facu; return 0; }
fr[15]^=0x80000000u;
goto P_0c087fae;
P_0c087fae: /* original e034, guest PC 0x0c087fae */
if(!s->budget--) { s->failed_pc=0x0c087faeu; return 0; }
r[0]=0x00000034u;
goto P_0c087fb0;
P_0c087fb0: /* original 7608, guest PC 0x0c087fb0 */
if(!s->budget--) { s->failed_pc=0x0c087fb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c087fb2;
P_0c087fb2: /* original fff7, guest PC 0x0c087fb2 */
if(!s->budget--) { s->failed_pc=0x0c087fb2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c087fb4;
P_0c087fb4: /* original 7504, guest PC 0x0c087fb4 */
if(!s->budget--) { s->failed_pc=0x0c087fb4u; return 0; }
r[5]+=0x00000004u;
goto P_0c087fb6;
P_0c087fb6: /* original f6cc, guest PC 0x0c087fb6 */
if(!s->budget--) { s->failed_pc=0x0c087fb6u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c087fb8;
P_0c087fb8: /* original f4fc, guest PC 0x0c087fb8 */
if(!s->budget--) { s->failed_pc=0x0c087fb8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087fba;
P_0c087fba: /* original f5dc, guest PC 0x0c087fba */
if(!s->budget--) { s->failed_pc=0x0c087fbau; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c087fbc;
P_0c087fbc: /* original bb99, guest PC 0x0c087fbc */
if(!s->budget--) { s->failed_pc=0x0c087fbcu; return 0; }
target=0x0c0876f2u; r[16]=0x0c087fc0u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087fc0u) { target=s->pc; goto dispatch; }
goto P_0c087fc0;
P_0c087fbe: /* original 64f3, guest PC 0x0c087fbe */
if(!s->budget--) { s->failed_pc=0x0c087fbeu; return 0; }
r[4]=r[15];
goto P_0c087fc0;
P_0c087fc0: /* original f4f8, guest PC 0x0c087fc0 */
if(!s->budget--) { s->failed_pc=0x0c087fc0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c087fc2;
P_0c087fc2: /* original bd0a, guest PC 0x0c087fc2 */
if(!s->budget--) { s->failed_pc=0x0c087fc2u; return 0; }
target=0x0c0879dau; r[16]=0x0c087fc6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c087fc6u) { target=s->pc; goto dispatch; }
goto P_0c087fc6;
P_0c087fc4: /* original 64d3, guest PC 0x0c087fc4 */
if(!s->budget--) { s->failed_pc=0x0c087fc4u; return 0; }
r[4]=r[13];
goto P_0c087fc6;
P_0c087fc6: /* original e004, guest PC 0x0c087fc6 */
if(!s->budget--) { s->failed_pc=0x0c087fc6u; return 0; }
r[0]=0x00000004u;
goto P_0c087fc8;
P_0c087fc8: /* original f40c, guest PC 0x0c087fc8 */
if(!s->budget--) { s->failed_pc=0x0c087fc8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087fca;
P_0c087fca: /* original f3f6, guest PC 0x0c087fca */
if(!s->budget--) { s->failed_pc=0x0c087fcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087fcc;
P_0c087fcc: /* original f28d, guest PC 0x0c087fcc */
if(!s->budget--) { s->failed_pc=0x0c087fccu; return 0; }
fr[2]=0;
goto P_0c087fce;
P_0c087fce: /* original f431, guest PC 0x0c087fce */
if(!s->budget--) { s->failed_pc=0x0c087fceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c087fd0;
P_0c087fd0: /* original f245, guest PC 0x0c087fd0 */
if(!s->budget--) { s->failed_pc=0x0c087fd0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c087fd2;
P_0c087fd2: /* original 8f02, guest PC 0x0c087fd2 */
if(!s->budget--) { s->failed_pc=0x0c087fd2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,13);
if(!cond) { goto P_0c087fda; }
goto P_0c087fd6;
P_0c087fd4: /* original ffdc, guest PC 0x0c087fd4 */
if(!s->budget--) { s->failed_pc=0x0c087fd4u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c087fd6;
P_0c087fd6: /* original e00c, guest PC 0x0c087fd6 */
if(!s->budget--) { s->failed_pc=0x0c087fd6u; return 0; }
r[0]=0x0000000cu;
goto P_0c087fd8;
P_0c087fd8: /* original f4f6, guest PC 0x0c087fd8 */
if(!s->budget--) { s->failed_pc=0x0c087fd8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087fda;
P_0c087fda: /* original ff4d, guest PC 0x0c087fda */
if(!s->budget--) { s->failed_pc=0x0c087fdau; return 0; }
fr[15]^=0x80000000u;
goto P_0c087fdc;
P_0c087fdc: /* original f5fc, guest PC 0x0c087fdc */
if(!s->budget--) { s->failed_pc=0x0c087fdcu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087fde;
P_0c087fde: /* original f541, guest PC 0x0c087fde */
if(!s->budget--) { s->failed_pc=0x0c087fdeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c087fe0;
P_0c087fe0: /* original f38d, guest PC 0x0c087fe0 */
if(!s->budget--) { s->failed_pc=0x0c087fe0u; return 0; }
fr[3]=0;
goto P_0c087fe2;
P_0c087fe2: /* original f355, guest PC 0x0c087fe2 */
if(!s->budget--) { s->failed_pc=0x0c087fe2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c087fe4;
P_0c087fe4: /* original 8b00, guest PC 0x0c087fe4 */
if(!s->budget--) { s->failed_pc=0x0c087fe4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087fe8; }
goto P_0c087fe6;
P_0c087fe6: /* original f4fc, guest PC 0x0c087fe6 */
if(!s->budget--) { s->failed_pc=0x0c087fe6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c087fe8;
P_0c087fe8: /* original e010, guest PC 0x0c087fe8 */
if(!s->budget--) { s->failed_pc=0x0c087fe8u; return 0; }
r[0]=0x00000010u;
goto P_0c087fea;
P_0c087fea: /* original f34c, guest PC 0x0c087fea */
if(!s->budget--) { s->failed_pc=0x0c087feau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c087fec;
P_0c087fec: /* original f4f6, guest PC 0x0c087fec */
if(!s->budget--) { s->failed_pc=0x0c087fecu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c087fee;
P_0c087fee: /* original e004, guest PC 0x0c087fee */
if(!s->budget--) { s->failed_pc=0x0c087feeu; return 0; }
r[0]=0x00000004u;
goto P_0c087ff0;
P_0c087ff0: /* original f432, guest PC 0x0c087ff0 */
if(!s->budget--) { s->failed_pc=0x0c087ff0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c087ff2;
P_0c087ff2: /* original f3f8, guest PC 0x0c087ff2 */
if(!s->budget--) { s->failed_pc=0x0c087ff2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c087ff4;
P_0c087ff4: /* original f93a, guest PC 0x0c087ff4 */
if(!s->budget--) { s->failed_pc=0x0c087ff4u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c087ff6;
P_0c087ff6: /* original f3f6, guest PC 0x0c087ff6 */
if(!s->budget--) { s->failed_pc=0x0c087ff6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087ff8;
P_0c087ff8: /* original e008, guest PC 0x0c087ff8 */
if(!s->budget--) { s->failed_pc=0x0c087ff8u; return 0; }
r[0]=0x00000008u;
goto P_0c087ffa;
P_0c087ffa: /* original f83a, guest PC 0x0c087ffa */
if(!s->budget--) { s->failed_pc=0x0c087ffau; return 0; }
vf3_matrix_store(s,ram,3,r[8]);
goto P_0c087ffc;
P_0c087ffc: /* original f3f6, guest PC 0x0c087ffc */
if(!s->budget--) { s->failed_pc=0x0c087ffcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087ffe;
P_0c087ffe: /* original 53f8, guest PC 0x0c087ffe */
if(!s->budget--) { s->failed_pc=0x0c087ffeu; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c088000;
P_0c088000: /* original f33a, guest PC 0x0c088000 */
if(!s->budget--) { s->failed_pc=0x0c088000u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c088002;
P_0c088002: /* original 53f7, guest PC 0x0c088002 */
if(!s->budget--) { s->failed_pc=0x0c088002u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c088004;
P_0c088004: /* original f34a, guest PC 0x0c088004 */
if(!s->budget--) { s->failed_pc=0x0c088004u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c088006;
P_0c088006: /* original f6cc, guest PC 0x0c088006 */
if(!s->budget--) { s->failed_pc=0x0c088006u; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c088008;
P_0c088008: /* original f64d, guest PC 0x0c088008 */
if(!s->budget--) { s->failed_pc=0x0c088008u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08800a;
P_0c08800a: /* original a00b, guest PC 0x0c08800a */
if(!s->budget--) { s->failed_pc=0x0c08800au; return 0; }
goto P_0c088024;
P_0c08800c: /* original 0009, guest PC 0x0c08800c */
if(!s->budget--) { s->failed_pc=0x0c08800cu; return 0; }
return vf3_matrix_family(0x0c08800eu,s,ram);
P_0c088024: /* original e034, guest PC 0x0c088024 */
if(!s->budget--) { s->failed_pc=0x0c088024u; return 0; }
r[0]=0x00000034u;
goto P_0c088026;
P_0c088026: /* original 66f3, guest PC 0x0c088026 */
if(!s->budget--) { s->failed_pc=0x0c088026u; return 0; }
r[6]=r[15];
goto P_0c088028;
P_0c088028: /* original 65f3, guest PC 0x0c088028 */
if(!s->budget--) { s->failed_pc=0x0c088028u; return 0; }
r[5]=r[15];
goto P_0c08802a;
P_0c08802a: /* original f4f6, guest PC 0x0c08802a */
if(!s->budget--) { s->failed_pc=0x0c08802au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08802c;
P_0c08802c: /* original 7504, guest PC 0x0c08802c */
if(!s->budget--) { s->failed_pc=0x0c08802cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08802e;
P_0c08802e: /* original f5dc, guest PC 0x0c08802e */
if(!s->budget--) { s->failed_pc=0x0c08802eu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088030;
P_0c088030: /* original 7608, guest PC 0x0c088030 */
if(!s->budget--) { s->failed_pc=0x0c088030u; return 0; }
r[6]+=0x00000008u;
goto P_0c088032;
P_0c088032: /* original bb5e, guest PC 0x0c088032 */
if(!s->budget--) { s->failed_pc=0x0c088032u; return 0; }
target=0x0c0876f2u; r[16]=0x0c088036u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088036u) { target=s->pc; goto dispatch; }
goto P_0c088036;
P_0c088034: /* original 64f3, guest PC 0x0c088034 */
if(!s->budget--) { s->failed_pc=0x0c088034u; return 0; }
r[4]=r[15];
goto P_0c088036;
P_0c088036: /* original f4f8, guest PC 0x0c088036 */
if(!s->budget--) { s->failed_pc=0x0c088036u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c088038;
P_0c088038: /* original bccf, guest PC 0x0c088038 */
if(!s->budget--) { s->failed_pc=0x0c088038u; return 0; }
target=0x0c0879dau; r[16]=0x0c08803cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08803cu) { target=s->pc; goto dispatch; }
goto P_0c08803c;
P_0c08803a: /* original 64d3, guest PC 0x0c08803a */
if(!s->budget--) { s->failed_pc=0x0c08803au; return 0; }
r[4]=r[13];
goto P_0c08803c;
P_0c08803c: /* original e004, guest PC 0x0c08803c */
if(!s->budget--) { s->failed_pc=0x0c08803cu; return 0; }
r[0]=0x00000004u;
goto P_0c08803e;
P_0c08803e: /* original f40c, guest PC 0x0c08803e */
if(!s->budget--) { s->failed_pc=0x0c08803eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088040;
P_0c088040: /* original f3f6, guest PC 0x0c088040 */
if(!s->budget--) { s->failed_pc=0x0c088040u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c088042;
P_0c088042: /* original f28d, guest PC 0x0c088042 */
if(!s->budget--) { s->failed_pc=0x0c088042u; return 0; }
fr[2]=0;
goto P_0c088044;
P_0c088044: /* original f431, guest PC 0x0c088044 */
if(!s->budget--) { s->failed_pc=0x0c088044u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c088046;
P_0c088046: /* original f245, guest PC 0x0c088046 */
if(!s->budget--) { s->failed_pc=0x0c088046u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c088048;
P_0c088048: /* original 8f02, guest PC 0x0c088048 */
if(!s->budget--) { s->failed_pc=0x0c088048u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,15);
if(!cond) { goto P_0c088050; }
goto P_0c08804c;
P_0c08804a: /* original f5fc, guest PC 0x0c08804a */
if(!s->budget--) { s->failed_pc=0x0c08804au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08804c;
P_0c08804c: /* original e00c, guest PC 0x0c08804c */
if(!s->budget--) { s->failed_pc=0x0c08804cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08804e;
P_0c08804e: /* original f4f6, guest PC 0x0c08804e */
if(!s->budget--) { s->failed_pc=0x0c08804eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c088050;
P_0c088050: /* original f541, guest PC 0x0c088050 */
if(!s->budget--) { s->failed_pc=0x0c088050u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c088052;
P_0c088052: /* original f38d, guest PC 0x0c088052 */
if(!s->budget--) { s->failed_pc=0x0c088052u; return 0; }
fr[3]=0;
goto P_0c088054;
P_0c088054: /* original f355, guest PC 0x0c088054 */
if(!s->budget--) { s->failed_pc=0x0c088054u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c088056;
P_0c088056: /* original 8b00, guest PC 0x0c088056 */
if(!s->budget--) { s->failed_pc=0x0c088056u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08805a; }
goto P_0c088058;
P_0c088058: /* original f4fc, guest PC 0x0c088058 */
if(!s->budget--) { s->failed_pc=0x0c088058u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08805a;
P_0c08805a: /* original e010, guest PC 0x0c08805a */
if(!s->budget--) { s->failed_pc=0x0c08805au; return 0; }
r[0]=0x00000010u;
goto P_0c08805c;
P_0c08805c: /* original ffec, guest PC 0x0c08805c */
if(!s->budget--) { s->failed_pc=0x0c08805cu; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c08805e;
P_0c08805e: /* original f8f6, guest PC 0x0c08805e */
if(!s->budget--) { s->failed_pc=0x0c08805eu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c088060;
P_0c088060: /* original e008, guest PC 0x0c088060 */
if(!s->budget--) { s->failed_pc=0x0c088060u; return 0; }
r[0]=0x00000008u;
goto P_0c088062;
P_0c088062: /* original f6f6, guest PC 0x0c088062 */
if(!s->budget--) { s->failed_pc=0x0c088062u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c088064;
P_0c088064: /* original e004, guest PC 0x0c088064 */
if(!s->budget--) { s->failed_pc=0x0c088064u; return 0; }
r[0]=0x00000004u;
goto P_0c088066;
P_0c088066: /* original f842, guest PC 0x0c088066 */
if(!s->budget--) { s->failed_pc=0x0c088066u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c088068;
P_0c088068: /* original f4f8, guest PC 0x0c088068 */
if(!s->budget--) { s->failed_pc=0x0c088068u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c08806a;
P_0c08806a: /* original f5f6, guest PC 0x0c08806a */
if(!s->budget--) { s->failed_pc=0x0c08806au; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08806c;
P_0c08806c: /* original f9ec, guest PC 0x0c08806c */
if(!s->budget--) { s->failed_pc=0x0c08806cu; return 0; }
vf3_matrix_move(s,9,14);
goto P_0c08806e;
P_0c08806e: /* original f7ec, guest PC 0x0c08806e */
if(!s->budget--) { s->failed_pc=0x0c08806eu; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c088070;
P_0c088070: /* original bc3a, guest PC 0x0c088070 */
if(!s->budget--) { s->failed_pc=0x0c088070u; return 0; }
target=0x0c0878e8u; r[16]=0x0c088074u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088074u) { target=s->pc; goto dispatch; }
goto P_0c088074;
P_0c088072: /* original 64e3, guest PC 0x0c088072 */
if(!s->budget--) { s->failed_pc=0x0c088072u; return 0; }
r[4]=r[14];
goto P_0c088074;
P_0c088074: /* original 53f8, guest PC 0x0c088074 */
if(!s->budget--) { s->failed_pc=0x0c088074u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c088076;
P_0c088076: /* original 52f7, guest PC 0x0c088076 */
if(!s->budget--) { s->failed_pc=0x0c088076u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c088078;
P_0c088078: /* original f638, guest PC 0x0c088078 */
if(!s->budget--) { s->failed_pc=0x0c088078u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c08807a;
P_0c08807a: /* original f588, guest PC 0x0c08807a */
if(!s->budget--) { s->failed_pc=0x0c08807au; return 0; }
vf3_matrix_load(s,ram,5,r[8]);
goto P_0c08807c;
P_0c08807c: /* original f498, guest PC 0x0c08807c */
if(!s->budget--) { s->failed_pc=0x0c08807cu; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c08807e;
P_0c08807e: /* original f828, guest PC 0x0c08807e */
if(!s->budget--) { s->failed_pc=0x0c08807eu; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
goto P_0c088080;
P_0c088080: /* original f9fc, guest PC 0x0c088080 */
if(!s->budget--) { s->failed_pc=0x0c088080u; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c088082;
P_0c088082: /* original f7fc, guest PC 0x0c088082 */
if(!s->budget--) { s->failed_pc=0x0c088082u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c088084;
P_0c088084: /* original bc30, guest PC 0x0c088084 */
if(!s->budget--) { s->failed_pc=0x0c088084u; return 0; }
target=0x0c0878e8u; r[16]=0x0c088088u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088088u) { target=s->pc; goto dispatch; }
goto P_0c088088;
P_0c088086: /* original 64e3, guest PC 0x0c088086 */
if(!s->budget--) { s->failed_pc=0x0c088086u; return 0; }
r[4]=r[14];
goto P_0c088088;
P_0c088088: /* original 52fc, guest PC 0x0c088088 */
if(!s->budget--) { s->failed_pc=0x0c088088u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c08808a;
P_0c08808a: /* original 53fb, guest PC 0x0c08808a */
if(!s->budget--) { s->failed_pc=0x0c08808au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c08808c;
P_0c08808c: /* original f528, guest PC 0x0c08808c */
if(!s->budget--) { s->failed_pc=0x0c08808cu; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c08808e;
P_0c08808e: /* original f438, guest PC 0x0c08808e */
if(!s->budget--) { s->failed_pc=0x0c08808eu; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c088090;
P_0c088090: /* original f8a8, guest PC 0x0c088090 */
if(!s->budget--) { s->failed_pc=0x0c088090u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c088092;
P_0c088092: /* original f6b8, guest PC 0x0c088092 */
if(!s->budget--) { s->failed_pc=0x0c088092u; return 0; }
vf3_matrix_load(s,ram,6,r[11]);
goto P_0c088094;
P_0c088094: /* original f9fc, guest PC 0x0c088094 */
if(!s->budget--) { s->failed_pc=0x0c088094u; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c088096;
P_0c088096: /* original f7fc, guest PC 0x0c088096 */
if(!s->budget--) { s->failed_pc=0x0c088096u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c088098;
P_0c088098: /* original bc26, guest PC 0x0c088098 */
if(!s->budget--) { s->failed_pc=0x0c088098u; return 0; }
target=0x0c0878e8u; r[16]=0x0c08809cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08809cu) { target=s->pc; goto dispatch; }
goto P_0c08809c;
P_0c08809a: /* original 64e3, guest PC 0x0c08809a */
if(!s->budget--) { s->failed_pc=0x0c08809au; return 0; }
r[4]=r[14];
goto P_0c08809c;
P_0c08809c: /* original 53f9, guest PC 0x0c08809c */
if(!s->budget--) { s->failed_pc=0x0c08809cu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c08809e;
P_0c08809e: /* original 52fa, guest PC 0x0c08809e */
if(!s->budget--) { s->failed_pc=0x0c08809eu; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c0880a0;
P_0c0880a0: /* original f638, guest PC 0x0c0880a0 */
if(!s->budget--) { s->failed_pc=0x0c0880a0u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c0880a2;
P_0c0880a2: /* original f828, guest PC 0x0c0880a2 */
if(!s->budget--) { s->failed_pc=0x0c0880a2u; return 0; }
vf3_matrix_load(s,ram,8,r[2]);
goto P_0c0880a4;
P_0c0880a4: /* original 52f6, guest PC 0x0c0880a4 */
if(!s->budget--) { s->failed_pc=0x0c0880a4u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0880a6;
P_0c0880a6: /* original 53f5, guest PC 0x0c0880a6 */
if(!s->budget--) { s->failed_pc=0x0c0880a6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0880a8;
P_0c0880a8: /* original f528, guest PC 0x0c0880a8 */
if(!s->budget--) { s->failed_pc=0x0c0880a8u; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c0880aa;
P_0c0880aa: /* original f438, guest PC 0x0c0880aa */
if(!s->budget--) { s->failed_pc=0x0c0880aau; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0880ac;
P_0c0880ac: /* original f9fc, guest PC 0x0c0880ac */
if(!s->budget--) { s->failed_pc=0x0c0880acu; return 0; }
vf3_matrix_move(s,9,15);
goto P_0c0880ae;
P_0c0880ae: /* original f7fc, guest PC 0x0c0880ae */
if(!s->budget--) { s->failed_pc=0x0c0880aeu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0880b0;
P_0c0880b0: /* original bc1a, guest PC 0x0c0880b0 */
if(!s->budget--) { s->failed_pc=0x0c0880b0u; return 0; }
target=0x0c0878e8u; r[16]=0x0c0880b4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0880b4u) { target=s->pc; goto dispatch; }
goto P_0c0880b4;
P_0c0880b2: /* original 64e3, guest PC 0x0c0880b2 */
if(!s->budget--) { s->failed_pc=0x0c0880b2u; return 0; }
r[4]=r[14];
goto P_0c0880b4;
P_0c0880b4: /* original e034, guest PC 0x0c0880b4 */
if(!s->budget--) { s->failed_pc=0x0c0880b4u; return 0; }
r[0]=0x00000034u;
goto P_0c0880b6;
P_0c0880b6: /* original ffe6, guest PC 0x0c0880b6 */
if(!s->budget--) { s->failed_pc=0x0c0880b6u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0880b8;
P_0c0880b8: /* original e074, guest PC 0x0c0880b8 */
if(!s->budget--) { s->failed_pc=0x0c0880b8u; return 0; }
r[0]=0x00000074u;
goto P_0c0880ba;
P_0c0880ba: /* original f4e6, guest PC 0x0c0880ba */
if(!s->budget--) { s->failed_pc=0x0c0880bau; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0880bc;
P_0c0880bc: /* original c720, guest PC 0x0c0880bc */
if(!s->budget--) { s->failed_pc=0x0c0880bcu; return 0; }
r[0]=0x0c088140u;
goto P_0c0880be;
P_0c0880be: /* original f508, guest PC 0x0c0880be */
if(!s->budget--) { s->failed_pc=0x0c0880beu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0880c0;
P_0c0880c0: /* original c720, guest PC 0x0c0880c0 */
if(!s->budget--) { s->failed_pc=0x0c0880c0u; return 0; }
r[0]=0x0c088144u;
goto P_0c0880c2;
P_0c0880c2: /* original f608, guest PC 0x0c0880c2 */
if(!s->budget--) { s->failed_pc=0x0c0880c2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0880c4;
P_0c0880c4: /* original e074, guest PC 0x0c0880c4 */
if(!s->budget--) { s->failed_pc=0x0c0880c4u; return 0; }
r[0]=0x00000074u;
goto P_0c0880c6;
P_0c0880c6: /* original f06c, guest PC 0x0c0880c6 */
if(!s->budget--) { s->failed_pc=0x0c0880c6u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0880c8;
P_0c0880c8: /* original f54e, guest PC 0x0c0880c8 */
if(!s->budget--) { s->failed_pc=0x0c0880c8u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0880ca;
P_0c0880ca: /* original f45c, guest PC 0x0c0880ca */
if(!s->budget--) { s->failed_pc=0x0c0880cau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0880cc;
P_0c0880cc: /* original ff40, guest PC 0x0c0880cc */
if(!s->budget--) { s->failed_pc=0x0c0880ccu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c0880ce;
P_0c0880ce: /* original fe47, guest PC 0x0c0880ce */
if(!s->budget--) { s->failed_pc=0x0c0880ceu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0880d0;
P_0c0880d0: /* original e004, guest PC 0x0c0880d0 */
if(!s->budget--) { s->failed_pc=0x0c0880d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0880d2;
P_0c0880d2: /* original 9432, guest PC 0x0c0880d2 */
if(!s->budget--) { s->failed_pc=0x0c0880d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813au,2);
goto P_0c0880d4;
P_0c0880d4: /* original 34ec, guest PC 0x0c0880d4 */
if(!s->budget--) { s->failed_pc=0x0c0880d4u; return 0; }
r[4]+=r[14];
goto P_0c0880d6;
P_0c0880d6: /* original f546, guest PC 0x0c0880d6 */
if(!s->budget--) { s->failed_pc=0x0c0880d6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0880d8;
P_0c0880d8: /* original e008, guest PC 0x0c0880d8 */
if(!s->budget--) { s->failed_pc=0x0c0880d8u; return 0; }
r[0]=0x00000008u;
goto P_0c0880da;
P_0c0880da: /* original f646, guest PC 0x0c0880da */
if(!s->budget--) { s->failed_pc=0x0c0880dau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0880dc;
P_0c0880dc: /* original 6543, guest PC 0x0c0880dc */
if(!s->budget--) { s->failed_pc=0x0c0880dcu; return 0; }
r[5]=r[4];
goto P_0c0880de;
P_0c0880de: /* original 750c, guest PC 0x0c0880de */
if(!s->budget--) { s->failed_pc=0x0c0880deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0880e0;
P_0c0880e0: /* original f448, guest PC 0x0c0880e0 */
if(!s->budget--) { s->failed_pc=0x0c0880e0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0880e2;
P_0c0880e2: /* original c718, guest PC 0x0c0880e2 */
if(!s->budget--) { s->failed_pc=0x0c0880e2u; return 0; }
r[0]=0x0c088144u;
goto P_0c0880e4;
P_0c0880e4: /* original f758, guest PC 0x0c0880e4 */
if(!s->budget--) { s->failed_pc=0x0c0880e4u; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
goto P_0c0880e6;
P_0c0880e6: /* original f808, guest PC 0x0c0880e6 */
if(!s->budget--) { s->failed_pc=0x0c0880e6u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0880e8;
P_0c0880e8: /* original f782, guest PC 0x0c0880e8 */
if(!s->budget--) { s->failed_pc=0x0c0880e8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c0880ea;
P_0c0880ea: /* original f57a, guest PC 0x0c0880ea */
if(!s->budget--) { s->failed_pc=0x0c0880eau; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c0880ec;
P_0c0880ec: /* original bb56, guest PC 0x0c0880ec */
if(!s->budget--) { s->failed_pc=0x0c0880ecu; return 0; }
target=0x0c08779cu; r[16]=0x0c0880f0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0880f0u) { target=s->pc; goto dispatch; }
goto P_0c0880f0;
P_0c0880ee: /* original 64d3, guest PC 0x0c0880ee */
if(!s->budget--) { s->failed_pc=0x0c0880eeu; return 0; }
r[4]=r[13];
goto P_0c0880f0;
P_0c0880f0: /* original ba7e, guest PC 0x0c0880f0 */
if(!s->budget--) { s->failed_pc=0x0c0880f0u; return 0; }
target=0x0c0875f0u; r[16]=0x0c0880f4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0880f4u) { target=s->pc; goto dispatch; }
goto P_0c0880f4;
P_0c0880f2: /* original 64e3, guest PC 0x0c0880f2 */
if(!s->budget--) { s->failed_pc=0x0c0880f2u; return 0; }
r[4]=r[14];
goto P_0c0880f4;
P_0c0880f4: /* original bad0, guest PC 0x0c0880f4 */
if(!s->budget--) { s->failed_pc=0x0c0880f4u; return 0; }
target=0x0c087698u; r[16]=0x0c0880f8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0880f8u) { target=s->pc; goto dispatch; }
goto P_0c0880f8;
P_0c0880f6: /* original 64e3, guest PC 0x0c0880f6 */
if(!s->budget--) { s->failed_pc=0x0c0880f6u; return 0; }
r[4]=r[14];
goto P_0c0880f8;
P_0c0880f8: /* original e034, guest PC 0x0c0880f8 */
if(!s->budget--) { s->failed_pc=0x0c0880f8u; return 0; }
r[0]=0x00000034u;
goto P_0c0880fa;
P_0c0880fa: /* original fef7, guest PC 0x0c0880fa */
if(!s->budget--) { s->failed_pc=0x0c0880fau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0880fc;
P_0c0880fc: /* original 7cff, guest PC 0x0c0880fc */
if(!s->budget--) { s->failed_pc=0x0c0880fcu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0880fe;
P_0c0880fe: /* original 931d, guest PC 0x0c0880fe */
if(!s->budget--) { s->failed_pc=0x0c0880feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813cu,2);
goto P_0c088100;
P_0c088100: /* original 3e3c, guest PC 0x0c088100 */
if(!s->budget--) { s->failed_pc=0x0c088100u; return 0; }
r[14]+=r[3];
goto P_0c088102;
P_0c088102: /* original 2cc8, guest PC 0x0c088102 */
if(!s->budget--) { s->failed_pc=0x0c088102u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c088104;
P_0c088104: /* original 8901, guest PC 0x0c088104 */
if(!s->budget--) { s->failed_pc=0x0c088104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08810a; }
goto P_0c088106;
P_0c088106: /* original aed9, guest PC 0x0c088106 */
if(!s->budget--) { s->failed_pc=0x0c088106u; return 0; }
goto P_0c087ebc;
P_0c088108: /* original 0009, guest PC 0x0c088108 */
if(!s->budget--) { s->failed_pc=0x0c088108u; return 0; }
goto P_0c08810a;
P_0c08810a: /* original d30f, guest PC 0x0c08810a */
if(!s->budget--) { s->failed_pc=0x0c08810au; return 0; }
r[3]=read(ram,0x0c088148u,4);
goto P_0c08810c;
P_0c08810c: /* original 430b, guest PC 0x0c08810c */
if(!s->budget--) { s->failed_pc=0x0c08810cu; return 0; }
target=r[3];
r[16]=0x0c088110u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c088110u) { target=s->pc; goto dispatch; }
goto P_0c088110;
P_0c08810e: /* original e401, guest PC 0x0c08810e */
if(!s->budget--) { s->failed_pc=0x0c08810eu; return 0; }
r[4]=0x00000001u;
goto P_0c088110;
P_0c088110: /* original 9015, guest PC 0x0c088110 */
if(!s->budget--) { s->failed_pc=0x0c088110u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08813eu,2);
goto P_0c088112;
P_0c088112: /* original 04de, guest PC 0x0c088112 */
if(!s->budget--) { s->failed_pc=0x0c088112u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c088114;
P_0c088114: /* original 70fc, guest PC 0x0c088114 */
if(!s->budget--) { s->failed_pc=0x0c088114u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c088116;
P_0c088116: /* original 05de, guest PC 0x0c088116 */
if(!s->budget--) { s->failed_pc=0x0c088116u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c088118;
P_0c088118: /* original 7004, guest PC 0x0c088118 */
if(!s->budget--) { s->failed_pc=0x0c088118u; return 0; }
r[0]+=0x00000004u;
goto P_0c08811a;
P_0c08811a: /* original 345c, guest PC 0x0c08811a */
if(!s->budget--) { s->failed_pc=0x0c08811au; return 0; }
r[4]+=r[5];
goto P_0c08811c;
P_0c08811c: /* original 0d46, guest PC 0x0c08811c */
if(!s->budget--) { s->failed_pc=0x0c08811cu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c08811e;
P_0c08811e: /* original 7f68, guest PC 0x0c08811e */
if(!s->budget--) { s->failed_pc=0x0c08811eu; return 0; }
r[15]+=0x00000068u;
goto P_0c088120;
P_0c088120: /* original 4f26, guest PC 0x0c088120 */
if(!s->budget--) { s->failed_pc=0x0c088120u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088122;
P_0c088122: /* original fcf9, guest PC 0x0c088122 */
if(!s->budget--) { s->failed_pc=0x0c088122u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088124;
P_0c088124: /* original fdf9, guest PC 0x0c088124 */
if(!s->budget--) { s->failed_pc=0x0c088124u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088126;
P_0c088126: /* original fef9, guest PC 0x0c088126 */
if(!s->budget--) { s->failed_pc=0x0c088126u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088128;
P_0c088128: /* original fff9, guest PC 0x0c088128 */
if(!s->budget--) { s->failed_pc=0x0c088128u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08812a;
P_0c08812a: /* original 68f6, guest PC 0x0c08812a */
if(!s->budget--) { s->failed_pc=0x0c08812au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08812c;
P_0c08812c: /* original 69f6, guest PC 0x0c08812c */
if(!s->budget--) { s->failed_pc=0x0c08812cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08812e;
P_0c08812e: /* original 6af6, guest PC 0x0c08812e */
if(!s->budget--) { s->failed_pc=0x0c08812eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088130;
P_0c088130: /* original 6bf6, guest PC 0x0c088130 */
if(!s->budget--) { s->failed_pc=0x0c088130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088132;
P_0c088132: /* original 6cf6, guest PC 0x0c088132 */
if(!s->budget--) { s->failed_pc=0x0c088132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088134;
P_0c088134: /* original 6df6, guest PC 0x0c088134 */
if(!s->budget--) { s->failed_pc=0x0c088134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088136;
P_0c088136: /* original 000b, guest PC 0x0c088136 */
if(!s->budget--) { s->failed_pc=0x0c088136u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088138: /* original 6ef6, guest PC 0x0c088138 */
if(!s->budget--) { s->failed_pc=0x0c088138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08813au,s,ram);
P_0c08dbee: /* original 4f22, guest PC 0x0c08dbee */
if(!s->budget--) { s->failed_pc=0x0c08dbeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dbf0;
P_0c08dbf0: /* original 06ed, guest PC 0x0c08dbf0 */
if(!s->budget--) { s->failed_pc=0x0c08dbf0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf2;
P_0c08dbf2: /* original 7002, guest PC 0x0c08dbf2 */
if(!s->budget--) { s->failed_pc=0x0c08dbf2u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dbf4;
P_0c08dbf4: /* original 05ed, guest PC 0x0c08dbf4 */
if(!s->budget--) { s->failed_pc=0x0c08dbf4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf6;
P_0c08dbf6: /* original 70fc, guest PC 0x0c08dbf6 */
if(!s->budget--) { s->failed_pc=0x0c08dbf6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dbf8;
P_0c08dbf8: /* original 04ed, guest PC 0x0c08dbf8 */
if(!s->budget--) { s->failed_pc=0x0c08dbf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfa;
P_0c08dbfa: /* original 7006, guest PC 0x0c08dbfa */
if(!s->budget--) { s->failed_pc=0x0c08dbfau; return 0; }
r[0]+=0x00000006u;
goto P_0c08dbfc;
P_0c08dbfc: /* original 0ded, guest PC 0x0c08dbfc */
if(!s->budget--) { s->failed_pc=0x0c08dbfcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfe;
P_0c08dbfe: /* original 7002, guest PC 0x0c08dbfe */
if(!s->budget--) { s->failed_pc=0x0c08dbfeu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc00;
P_0c08dc00: /* original 4410, guest PC 0x0c08dc00 */
if(!s->budget--) { s->failed_pc=0x0c08dc00u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08dc02;
P_0c08dc02: /* original 7ff0, guest PC 0x0c08dc02 */
if(!s->budget--) { s->failed_pc=0x0c08dc02u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08dc04;
P_0c08dc04: /* original 8f22, guest PC 0x0c08dc04 */
if(!s->budget--) { s->failed_pc=0x0c08dc04u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!cond) { goto P_0c08dc4c; }
goto P_0c08dc08;
P_0c08dc06: /* original 0ced, guest PC 0x0c08dc06 */
if(!s->budget--) { s->failed_pc=0x0c08dc06u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dc08;
P_0c08dc08: /* original 901c, guest PC 0x0c08dc08 */
if(!s->budget--) { s->failed_pc=0x0c08dc08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc44u,2);
goto P_0c08dc0a;
P_0c08dc0a: /* original e400, guest PC 0x0c08dc0a */
if(!s->budget--) { s->failed_pc=0x0c08dc0au; return 0; }
r[4]=0x00000000u;
goto P_0c08dc0c;
P_0c08dc0c: /* original 62f3, guest PC 0x0c08dc0c */
if(!s->budget--) { s->failed_pc=0x0c08dc0cu; return 0; }
r[2]=r[15];
goto P_0c08dc0e;
P_0c08dc0e: /* original e301, guest PC 0x0c08dc0e */
if(!s->budget--) { s->failed_pc=0x0c08dc0eu; return 0; }
r[3]=0x00000001u;
goto P_0c08dc10;
P_0c08dc10: /* original 0e45, guest PC 0x0c08dc10 */
if(!s->budget--) { s->failed_pc=0x0c08dc10u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc12;
P_0c08dc12: /* original 7002, guest PC 0x0c08dc12 */
if(!s->budget--) { s->failed_pc=0x0c08dc12u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc14;
P_0c08dc14: /* original 0e45, guest PC 0x0c08dc14 */
if(!s->budget--) { s->failed_pc=0x0c08dc14u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc16;
P_0c08dc16: /* original 70fc, guest PC 0x0c08dc16 */
if(!s->budget--) { s->failed_pc=0x0c08dc16u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dc18;
P_0c08dc18: /* original 0e45, guest PC 0x0c08dc18 */
if(!s->budget--) { s->failed_pc=0x0c08dc18u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc1a;
P_0c08dc1a: /* original 70fe, guest PC 0x0c08dc1a */
if(!s->budget--) { s->failed_pc=0x0c08dc1au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c08dc1c;
P_0c08dc1c: /* original 720c, guest PC 0x0c08dc1c */
if(!s->budget--) { s->failed_pc=0x0c08dc1cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc1e;
P_0c08dc1e: /* original 0e34, guest PC 0x0c08dc1e */
if(!s->budget--) { s->failed_pc=0x0c08dc1eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08dc20;
P_0c08dc20: /* original 2f26, guest PC 0x0c08dc20 */
if(!s->budget--) { s->failed_pc=0x0c08dc20u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc22;
P_0c08dc22: /* original 3d6c, guest PC 0x0c08dc22 */
if(!s->budget--) { s->failed_pc=0x0c08dc22u; return 0; }
r[13]+=r[6];
goto P_0c08dc24;
P_0c08dc24: /* original 63f3, guest PC 0x0c08dc24 */
if(!s->budget--) { s->failed_pc=0x0c08dc24u; return 0; }
r[3]=r[15];
goto P_0c08dc26;
P_0c08dc26: /* original 730c, guest PC 0x0c08dc26 */
if(!s->budget--) { s->failed_pc=0x0c08dc26u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc28;
P_0c08dc28: /* original 2f36, guest PC 0x0c08dc28 */
if(!s->budget--) { s->failed_pc=0x0c08dc28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc2a;
P_0c08dc2a: /* original 3c5c, guest PC 0x0c08dc2a */
if(!s->budget--) { s->failed_pc=0x0c08dc2au; return 0; }
r[12]+=r[5];
goto P_0c08dc2c;
P_0c08dc2c: /* original 66f3, guest PC 0x0c08dc2c */
if(!s->budget--) { s->failed_pc=0x0c08dc2cu; return 0; }
r[6]=r[15];
goto P_0c08dc2e;
P_0c08dc2e: /* original 67f3, guest PC 0x0c08dc2e */
if(!s->budget--) { s->failed_pc=0x0c08dc2eu; return 0; }
r[7]=r[15];
goto P_0c08dc30;
P_0c08dc30: /* original 65c3, guest PC 0x0c08dc30 */
if(!s->budget--) { s->failed_pc=0x0c08dc30u; return 0; }
r[5]=r[12];
goto P_0c08dc32;
P_0c08dc32: /* original 7608, guest PC 0x0c08dc32 */
if(!s->budget--) { s->failed_pc=0x0c08dc32u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc34;
P_0c08dc34: /* original 770c, guest PC 0x0c08dc34 */
if(!s->budget--) { s->failed_pc=0x0c08dc34u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc36;
P_0c08dc36: /* original b03b, guest PC 0x0c08dc36 */
if(!s->budget--) { s->failed_pc=0x0c08dc36u; return 0; }
target=0x0c08dcb0u; r[16]=0x0c08dc3au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dc3au) { target=s->pc; goto dispatch; }
goto P_0c08dc3a;
P_0c08dc38: /* original 64d3, guest PC 0x0c08dc38 */
if(!s->budget--) { s->failed_pc=0x0c08dc38u; return 0; }
r[4]=r[13];
goto P_0c08dc3a;
P_0c08dc3a: /* original a028, guest PC 0x0c08dc3a */
if(!s->budget--) { s->failed_pc=0x0c08dc3au; return 0; }
goto P_0c08dc8e;
P_0c08dc3c: /* original 0009, guest PC 0x0c08dc3c */
if(!s->budget--) { s->failed_pc=0x0c08dc3cu; return 0; }
return vf3_matrix_family(0x0c08dc3eu,s,ram);
P_0c08dc4c: /* original d242, guest PC 0x0c08dc4c */
if(!s->budget--) { s->failed_pc=0x0c08dc4cu; return 0; }
r[2]=read(ram,0x0c08dd58u,4);
goto P_0c08dc4e;
P_0c08dc4e: /* original 6163, guest PC 0x0c08dc4e */
if(!s->budget--) { s->failed_pc=0x0c08dc4eu; return 0; }
r[1]=r[6];
goto P_0c08dc50;
P_0c08dc50: /* original 420b, guest PC 0x0c08dc50 */
if(!s->budget--) { s->failed_pc=0x0c08dc50u; return 0; }
target=r[2];
r[16]=0x0c08dc54u;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dc54u) { target=s->pc; goto dispatch; }
goto P_0c08dc54;
P_0c08dc52: /* original 6043, guest PC 0x0c08dc52 */
if(!s->budget--) { s->failed_pc=0x0c08dc52u; return 0; }
r[0]=r[4];
goto P_0c08dc54;
P_0c08dc54: /* original d340, guest PC 0x0c08dc54 */
if(!s->budget--) { s->failed_pc=0x0c08dc54u; return 0; }
r[3]=read(ram,0x0c08dd58u,4);
goto P_0c08dc56;
P_0c08dc56: /* original 6153, guest PC 0x0c08dc56 */
if(!s->budget--) { s->failed_pc=0x0c08dc56u; return 0; }
r[1]=r[5];
goto P_0c08dc58;
P_0c08dc58: /* original 6703, guest PC 0x0c08dc58 */
if(!s->budget--) { s->failed_pc=0x0c08dc58u; return 0; }
r[7]=r[0];
goto P_0c08dc5a;
P_0c08dc5a: /* original 430b, guest PC 0x0c08dc5a */
if(!s->budget--) { s->failed_pc=0x0c08dc5au; return 0; }
target=r[3];
r[16]=0x0c08dc5eu;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dc5eu) { target=s->pc; goto dispatch; }
goto P_0c08dc5e;
P_0c08dc5c: /* original 6043, guest PC 0x0c08dc5c */
if(!s->budget--) { s->failed_pc=0x0c08dc5cu; return 0; }
r[0]=r[4];
goto P_0c08dc5e;
P_0c08dc5e: /* original 6203, guest PC 0x0c08dc5e */
if(!s->budget--) { s->failed_pc=0x0c08dc5eu; return 0; }
r[2]=r[0];
goto P_0c08dc60;
P_0c08dc60: /* original 9071, guest PC 0x0c08dc60 */
if(!s->budget--) { s->failed_pc=0x0c08dc60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd46u,2);
goto P_0c08dc62;
P_0c08dc62: /* original 63f3, guest PC 0x0c08dc62 */
if(!s->budget--) { s->failed_pc=0x0c08dc62u; return 0; }
r[3]=r[15];
goto P_0c08dc64;
P_0c08dc64: /* original 730c, guest PC 0x0c08dc64 */
if(!s->budget--) { s->failed_pc=0x0c08dc64u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc66;
P_0c08dc66: /* original 0e45, guest PC 0x0c08dc66 */
if(!s->budget--) { s->failed_pc=0x0c08dc66u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc68;
P_0c08dc68: /* original 3528, guest PC 0x0c08dc68 */
if(!s->budget--) { s->failed_pc=0x0c08dc68u; return 0; }
r[5]-=r[2];
goto P_0c08dc6a;
P_0c08dc6a: /* original 3c2c, guest PC 0x0c08dc6a */
if(!s->budget--) { s->failed_pc=0x0c08dc6au; return 0; }
r[12]+=r[2];
goto P_0c08dc6c;
P_0c08dc6c: /* original 3678, guest PC 0x0c08dc6c */
if(!s->budget--) { s->failed_pc=0x0c08dc6cu; return 0; }
r[6]-=r[7];
goto P_0c08dc6e;
P_0c08dc6e: /* original 7002, guest PC 0x0c08dc6e */
if(!s->budget--) { s->failed_pc=0x0c08dc6eu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc70;
P_0c08dc70: /* original 0e65, guest PC 0x0c08dc70 */
if(!s->budget--) { s->failed_pc=0x0c08dc70u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c08dc72;
P_0c08dc72: /* original 3d7c, guest PC 0x0c08dc72 */
if(!s->budget--) { s->failed_pc=0x0c08dc72u; return 0; }
r[13]+=r[7];
goto P_0c08dc74;
P_0c08dc74: /* original 7002, guest PC 0x0c08dc74 */
if(!s->budget--) { s->failed_pc=0x0c08dc74u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc76;
P_0c08dc76: /* original 0e55, guest PC 0x0c08dc76 */
if(!s->budget--) { s->failed_pc=0x0c08dc76u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c08dc78;
P_0c08dc78: /* original 65c3, guest PC 0x0c08dc78 */
if(!s->budget--) { s->failed_pc=0x0c08dc78u; return 0; }
r[5]=r[12];
goto P_0c08dc7a;
P_0c08dc7a: /* original 2f36, guest PC 0x0c08dc7a */
if(!s->budget--) { s->failed_pc=0x0c08dc7au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc7c;
P_0c08dc7c: /* original 62f3, guest PC 0x0c08dc7c */
if(!s->budget--) { s->failed_pc=0x0c08dc7cu; return 0; }
r[2]=r[15];
goto P_0c08dc7e;
P_0c08dc7e: /* original 720c, guest PC 0x0c08dc7e */
if(!s->budget--) { s->failed_pc=0x0c08dc7eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc80;
P_0c08dc80: /* original 2f26, guest PC 0x0c08dc80 */
if(!s->budget--) { s->failed_pc=0x0c08dc80u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc82;
P_0c08dc82: /* original 66f3, guest PC 0x0c08dc82 */
if(!s->budget--) { s->failed_pc=0x0c08dc82u; return 0; }
r[6]=r[15];
goto P_0c08dc84;
P_0c08dc84: /* original 67f3, guest PC 0x0c08dc84 */
if(!s->budget--) { s->failed_pc=0x0c08dc84u; return 0; }
r[7]=r[15];
goto P_0c08dc86;
P_0c08dc86: /* original 7608, guest PC 0x0c08dc86 */
if(!s->budget--) { s->failed_pc=0x0c08dc86u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc88;
P_0c08dc88: /* original 770c, guest PC 0x0c08dc88 */
if(!s->budget--) { s->failed_pc=0x0c08dc88u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc8a;
P_0c08dc8a: /* original b011, guest PC 0x0c08dc8a */
if(!s->budget--) { s->failed_pc=0x0c08dc8au; return 0; }
target=0x0c08dcb0u; r[16]=0x0c08dc8eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dc8eu) { target=s->pc; goto dispatch; }
goto P_0c08dc8e;
P_0c08dc8c: /* original 64d3, guest PC 0x0c08dc8c */
if(!s->budget--) { s->failed_pc=0x0c08dc8cu; return 0; }
r[4]=r[13];
goto P_0c08dc8e;
P_0c08dc8e: /* original 52f5, guest PC 0x0c08dc8e */
if(!s->budget--) { s->failed_pc=0x0c08dc8eu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc90;
P_0c08dc90: /* original 65d3, guest PC 0x0c08dc90 */
if(!s->budget--) { s->failed_pc=0x0c08dc90u; return 0; }
r[5]=r[13];
goto P_0c08dc92;
P_0c08dc92: /* original 66c3, guest PC 0x0c08dc92 */
if(!s->budget--) { s->failed_pc=0x0c08dc92u; return 0; }
r[6]=r[12];
goto P_0c08dc94;
P_0c08dc94: /* original 2f26, guest PC 0x0c08dc94 */
if(!s->budget--) { s->failed_pc=0x0c08dc94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc96;
P_0c08dc96: /* original 53f5, guest PC 0x0c08dc96 */
if(!s->budget--) { s->failed_pc=0x0c08dc96u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08dc98;
P_0c08dc98: /* original 2f36, guest PC 0x0c08dc98 */
if(!s->budget--) { s->failed_pc=0x0c08dc98u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9a;
P_0c08dc9a: /* original 52f5, guest PC 0x0c08dc9a */
if(!s->budget--) { s->failed_pc=0x0c08dc9au; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc9c;
P_0c08dc9c: /* original 2f26, guest PC 0x0c08dc9c */
if(!s->budget--) { s->failed_pc=0x0c08dc9cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9e;
P_0c08dc9e: /* original 57f5, guest PC 0x0c08dc9e */
if(!s->budget--) { s->failed_pc=0x0c08dc9eu; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dca0;
P_0c08dca0: /* original b121, guest PC 0x0c08dca0 */
if(!s->budget--) { s->failed_pc=0x0c08dca0u; return 0; }
target=0x0c08dee6u; r[16]=0x0c08dca4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dca4u) { target=s->pc; goto dispatch; }
goto P_0c08dca4;
P_0c08dca2: /* original 64e3, guest PC 0x0c08dca2 */
if(!s->budget--) { s->failed_pc=0x0c08dca2u; return 0; }
r[4]=r[14];
goto P_0c08dca4;
P_0c08dca4: /* original 7f24, guest PC 0x0c08dca4 */
if(!s->budget--) { s->failed_pc=0x0c08dca4u; return 0; }
r[15]+=0x00000024u;
goto P_0c08dca6;
P_0c08dca6: /* original 4f26, guest PC 0x0c08dca6 */
if(!s->budget--) { s->failed_pc=0x0c08dca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dca8;
P_0c08dca8: /* original 6cf6, guest PC 0x0c08dca8 */
if(!s->budget--) { s->failed_pc=0x0c08dca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08dcaa;
P_0c08dcaa: /* original 6df6, guest PC 0x0c08dcaa */
if(!s->budget--) { s->failed_pc=0x0c08dcaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dcac;
P_0c08dcac: /* original 000b, guest PC 0x0c08dcac */
if(!s->budget--) { s->failed_pc=0x0c08dcacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dcae: /* original 6ef6, guest PC 0x0c08dcae */
if(!s->budget--) { s->failed_pc=0x0c08dcaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dcb0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0875f0u,0x0c0875f2u,0x0c0875f4u,0x0c0875f6u,0x0c0875f8u,0x0c0875fau,0x0c0875fcu,0x0c0875feu,0x0c087600u,0x0c087602u,0x0c087604u,0x0c087606u,0x0c087608u,0x0c08760au,0x0c08760cu,0x0c08760eu,
0x0c087610u,0x0c087612u,0x0c087614u,0x0c087616u,0x0c087618u,0x0c08761au,0x0c08761cu,0x0c08761eu,0x0c087620u,0x0c087622u,0x0c087624u,0x0c087626u,0x0c087628u,0x0c08762au,0x0c08762cu,0x0c08762eu,
0x0c087630u,0x0c087632u,0x0c087634u,0x0c087636u,0x0c087638u,0x0c08763au,0x0c087698u,0x0c08769au,0x0c08779cu,0x0c08779eu,0x0c0877a0u,0x0c0877a2u,0x0c0877a4u,0x0c0877a6u,0x0c0877a8u,0x0c0877aau,
0x0c0877acu,0x0c0877aeu,0x0c0877b0u,0x0c0877b2u,0x0c0877b4u,0x0c0877b6u,0x0c0877b8u,0x0c0877bau,0x0c0877bcu,0x0c0877beu,0x0c0877c0u,0x0c0877c2u,0x0c0877c4u,0x0c0877c6u,0x0c0877c8u,0x0c0877cau,
0x0c0877ccu,0x0c0877ceu,0x0c0877d0u,0x0c0877d2u,0x0c0877d4u,0x0c0877d6u,0x0c0877d8u,0x0c0877dau,0x0c0877dcu,0x0c0877deu,0x0c0877e0u,0x0c0877e2u,0x0c0877e4u,0x0c0877e6u,0x0c0877e8u,0x0c0877eau,
0x0c0877ecu,0x0c0877eeu,0x0c0877f0u,0x0c0877f2u,0x0c0877f4u,0x0c0877f6u,0x0c0877f8u,0x0c0877fau,0x0c0877fcu,0x0c0877feu,0x0c087800u,0x0c087802u,0x0c087804u,0x0c087806u,0x0c087808u,0x0c08780au,
0x0c08780cu,0x0c08780eu,0x0c087810u,0x0c087812u,0x0c087814u,0x0c087816u,0x0c087818u,0x0c08781au,0x0c08781cu,0x0c08781eu,0x0c087820u,0x0c087822u,0x0c087824u,0x0c087826u,0x0c087828u,0x0c08782au,
0x0c08782cu,0x0c08782eu,0x0c087830u,0x0c087832u,0x0c087834u,0x0c087836u,0x0c087838u,0x0c08783au,0x0c08783cu,0x0c08783eu,0x0c087840u,0x0c087842u,0x0c087844u,0x0c087846u,0x0c087848u,0x0c08784au,
0x0c08784cu,0x0c08784eu,0x0c087850u,0x0c087852u,0x0c087854u,0x0c087856u,0x0c087858u,0x0c08785au,0x0c08785cu,0x0c08785eu,0x0c087860u,0x0c087862u,0x0c087864u,0x0c087866u,0x0c087868u,0x0c08786au,
0x0c08786cu,0x0c08786eu,0x0c087870u,0x0c087872u,0x0c087874u,0x0c087876u,0x0c087878u,0x0c08787au,0x0c08787cu,0x0c08787eu,0x0c087880u,0x0c087882u,0x0c087884u,0x0c087886u,0x0c087888u,0x0c08788au,
0x0c08788cu,0x0c08788eu,0x0c087890u,0x0c087892u,0x0c087894u,0x0c087896u,0x0c087898u,0x0c08789au,0x0c08789cu,0x0c08789eu,0x0c0878a0u,0x0c0878a2u,0x0c0878a4u,0x0c0878a6u,0x0c0878a8u,0x0c0878aau,
0x0c0878acu,0x0c0878aeu,0x0c0878b0u,0x0c0878b2u,0x0c0878b4u,0x0c0878b6u,0x0c0878b8u,0x0c0878bau,0x0c0878bcu,0x0c0878beu,0x0c0878c0u,0x0c0878c2u,0x0c0878e8u,0x0c0878eau,0x0c0878ecu,0x0c0878eeu,
0x0c0878f0u,0x0c0878f2u,0x0c0878f4u,0x0c0878f6u,0x0c0878f8u,0x0c0878fau,0x0c0878fcu,0x0c0878feu,0x0c087900u,0x0c087902u,0x0c087904u,0x0c087906u,0x0c087908u,0x0c08790au,0x0c08790cu,0x0c08790eu,
0x0c087910u,0x0c087912u,0x0c087914u,0x0c087916u,0x0c087918u,0x0c08791au,0x0c08791cu,0x0c08791eu,0x0c087920u,0x0c087922u,0x0c087924u,0x0c087926u,0x0c087928u,0x0c08792au,0x0c08792cu,0x0c08792eu,
0x0c087930u,0x0c087932u,0x0c087934u,0x0c087936u,0x0c087938u,0x0c08793au,0x0c08793cu,0x0c08793eu,0x0c087940u,0x0c087942u,0x0c087944u,0x0c087946u,0x0c087948u,0x0c08794au,0x0c08794cu,0x0c08794eu,
0x0c087950u,0x0c087952u,0x0c087954u,0x0c087956u,0x0c087958u,0x0c08795au,0x0c08795cu,0x0c08795eu,0x0c087960u,0x0c087962u,0x0c087964u,0x0c087966u,0x0c087968u,0x0c08796au,0x0c08796cu,0x0c08796eu,
0x0c087970u,0x0c087972u,0x0c087974u,0x0c087976u,0x0c087978u,0x0c08797au,0x0c08797cu,0x0c08797eu,0x0c087980u,0x0c087982u,0x0c087984u,0x0c087986u,0x0c087988u,0x0c08798au,0x0c08798cu,0x0c08798eu,
0x0c087990u,0x0c087992u,0x0c087994u,0x0c087996u,0x0c087998u,0x0c08799au,0x0c08799cu,0x0c08799eu,0x0c0879a0u,0x0c0879a2u,0x0c0879a4u,0x0c0879a6u,0x0c0879a8u,0x0c0879aau,0x0c0879acu,0x0c0879aeu,
0x0c0879b0u,0x0c0879b2u,0x0c0879b4u,0x0c0879b6u,0x0c0879b8u,0x0c0879bau,0x0c0879bcu,0x0c0879beu,0x0c0879c0u,0x0c0879c2u,0x0c0879c4u,0x0c0879c6u,0x0c0879c8u,0x0c0879cau,0x0c0879ccu,0x0c0879ceu,
0x0c0879d0u,0x0c0879d2u,0x0c0879d4u,0x0c0879d6u,0x0c0879d8u,0x0c087b80u,0x0c087b82u,0x0c087b84u,0x0c087b86u,0x0c087b88u,0x0c087b8au,0x0c087b8cu,0x0c087b8eu,0x0c087b90u,0x0c087b92u,0x0c087b94u,
0x0c087b96u,0x0c087b98u,0x0c087b9au,0x0c087b9cu,0x0c087b9eu,0x0c087ba0u,0x0c087ba2u,0x0c087ba4u,0x0c087ba6u,0x0c087ba8u,0x0c087baau,0x0c087bacu,0x0c087baeu,0x0c087bb0u,0x0c087bb2u,0x0c087bb4u,
0x0c087bb6u,0x0c087bb8u,0x0c087bbau,0x0c087bbcu,0x0c087bbeu,0x0c087bc0u,0x0c087bc2u,0x0c087bc4u,0x0c087bc6u,0x0c087bc8u,0x0c087bcau,0x0c087bccu,0x0c087bceu,0x0c087bd0u,0x0c087bd2u,0x0c087bd4u,
0x0c087bd6u,0x0c087bd8u,0x0c087bf8u,0x0c087bfau,0x0c087bfcu,0x0c087bfeu,0x0c087c00u,0x0c087c02u,0x0c087c04u,0x0c087c06u,0x0c087c08u,0x0c087c0au,0x0c087c0cu,0x0c087c0eu,0x0c087c10u,0x0c087c12u,
0x0c087c14u,0x0c087c16u,0x0c087c18u,0x0c087c1au,0x0c087c1cu,0x0c087c1eu,0x0c087c20u,0x0c087c22u,0x0c087c24u,0x0c087c26u,0x0c087c28u,0x0c087c2au,0x0c087c2cu,0x0c087c2eu,0x0c087c30u,0x0c087c32u,
0x0c087c34u,0x0c087c36u,0x0c087c38u,0x0c087c3au,0x0c087c3cu,0x0c087c3eu,0x0c087c40u,0x0c087c42u,0x0c087c44u,0x0c087c46u,0x0c087c48u,0x0c087c4au,0x0c087c4cu,0x0c087c4eu,0x0c087c50u,0x0c087c52u,
0x0c087c54u,0x0c087c56u,0x0c087c58u,0x0c087c5au,0x0c087c5cu,0x0c087c5eu,0x0c087c60u,0x0c087c62u,0x0c087c64u,0x0c087c66u,0x0c087c68u,0x0c087c6au,0x0c087c6cu,0x0c087c6eu,0x0c087c70u,0x0c087c72u,
0x0c087c74u,0x0c087c76u,0x0c087c78u,0x0c087c7au,0x0c087c7cu,0x0c087c7eu,0x0c087c80u,0x0c087c82u,0x0c087c84u,0x0c087c86u,0x0c087c88u,0x0c087c8au,0x0c087c8cu,0x0c087c8eu,0x0c087c90u,0x0c087c92u,
0x0c087c94u,0x0c087c96u,0x0c087c98u,0x0c087c9au,0x0c087c9cu,0x0c087c9eu,0x0c087ca0u,0x0c087ca2u,0x0c087ca4u,0x0c087ca6u,0x0c087ca8u,0x0c087caau,0x0c087cacu,0x0c087caeu,0x0c087cb0u,0x0c087cb2u,
0x0c087cb4u,0x0c087cb6u,0x0c087cb8u,0x0c087cbau,0x0c087cbcu,0x0c087cbeu,0x0c087cc0u,0x0c087cc2u,0x0c087cc4u,0x0c087e1cu,0x0c087e1eu,0x0c087e20u,0x0c087e22u,0x0c087e24u,0x0c087e26u,0x0c087e28u,
0x0c087e2au,0x0c087e2cu,0x0c087e2eu,0x0c087e30u,0x0c087e32u,0x0c087e34u,0x0c087e36u,0x0c087e38u,0x0c087e3au,0x0c087e3cu,0x0c087e3eu,0x0c087e40u,0x0c087e42u,0x0c087e44u,0x0c087e46u,0x0c087e48u,
0x0c087e4au,0x0c087e4cu,0x0c087e4eu,0x0c087e50u,0x0c087e52u,0x0c087e54u,0x0c087e56u,0x0c087e58u,0x0c087e5au,0x0c087e5cu,0x0c087e5eu,0x0c087e60u,0x0c087e62u,0x0c087e64u,0x0c087e66u,0x0c087e68u,
0x0c087e6au,0x0c087e6cu,0x0c087e6eu,0x0c087e70u,0x0c087e72u,0x0c087e74u,0x0c087e76u,0x0c087e78u,0x0c087e7au,0x0c087e7cu,0x0c087e7eu,0x0c087e80u,0x0c087e82u,0x0c087e84u,0x0c087e86u,0x0c087e88u,
0x0c087e8au,0x0c087e8cu,0x0c087e8eu,0x0c087e90u,0x0c087e92u,0x0c087e94u,0x0c087e96u,0x0c087e98u,0x0c087e9au,0x0c087e9cu,0x0c087e9eu,0x0c087ea0u,0x0c087ebcu,0x0c087ebeu,0x0c087ec0u,0x0c087ec2u,
0x0c087ec4u,0x0c087ec6u,0x0c087ec8u,0x0c087ecau,0x0c087eccu,0x0c087eceu,0x0c087ed0u,0x0c087ed2u,0x0c087ed4u,0x0c087ed6u,0x0c087ed8u,0x0c087edau,0x0c087edcu,0x0c087edeu,0x0c087ee0u,0x0c087ee2u,
0x0c087ee4u,0x0c087ee6u,0x0c087ee8u,0x0c087eeau,0x0c087eecu,0x0c087eeeu,0x0c087ef0u,0x0c087ef2u,0x0c087ef4u,0x0c087ef6u,0x0c087ef8u,0x0c087efau,0x0c087efcu,0x0c087efeu,0x0c087f00u,0x0c087f02u,
0x0c087f04u,0x0c087f06u,0x0c087f08u,0x0c087f0au,0x0c087f0cu,0x0c087f0eu,0x0c087f10u,0x0c087f12u,0x0c087f14u,0x0c087f16u,0x0c087f18u,0x0c087f1au,0x0c087f1cu,0x0c087f1eu,0x0c087f20u,0x0c087f22u,
0x0c087f24u,0x0c087f26u,0x0c087f28u,0x0c087f2au,0x0c087f2cu,0x0c087f2eu,0x0c087f30u,0x0c087f32u,0x0c087f34u,0x0c087f36u,0x0c087f38u,0x0c087f3au,0x0c087f3cu,0x0c087f3eu,0x0c087f40u,0x0c087f42u,
0x0c087f44u,0x0c087f46u,0x0c087f48u,0x0c087f4au,0x0c087f4cu,0x0c087f4eu,0x0c087f50u,0x0c087f52u,0x0c087f54u,0x0c087f56u,0x0c087f58u,0x0c087f5au,0x0c087f5cu,0x0c087f5eu,0x0c087f60u,0x0c087f62u,
0x0c087f64u,0x0c087f66u,0x0c087f68u,0x0c087f6au,0x0c087f6cu,0x0c087f6eu,0x0c087f70u,0x0c087f72u,0x0c087f74u,0x0c087f76u,0x0c087f78u,0x0c087f7au,0x0c087f7cu,0x0c087f7eu,0x0c087f80u,0x0c087f82u,
0x0c087f84u,0x0c087f86u,0x0c087f88u,0x0c087f8au,0x0c087f8cu,0x0c087f8eu,0x0c087f90u,0x0c087f92u,0x0c087f94u,0x0c087f96u,0x0c087f98u,0x0c087f9au,0x0c087f9cu,0x0c087f9eu,0x0c087fa0u,0x0c087fa2u,
0x0c087fa4u,0x0c087fa6u,0x0c087fa8u,0x0c087faau,0x0c087facu,0x0c087faeu,0x0c087fb0u,0x0c087fb2u,0x0c087fb4u,0x0c087fb6u,0x0c087fb8u,0x0c087fbau,0x0c087fbcu,0x0c087fbeu,0x0c087fc0u,0x0c087fc2u,
0x0c087fc4u,0x0c087fc6u,0x0c087fc8u,0x0c087fcau,0x0c087fccu,0x0c087fceu,0x0c087fd0u,0x0c087fd2u,0x0c087fd4u,0x0c087fd6u,0x0c087fd8u,0x0c087fdau,0x0c087fdcu,0x0c087fdeu,0x0c087fe0u,0x0c087fe2u,
0x0c087fe4u,0x0c087fe6u,0x0c087fe8u,0x0c087feau,0x0c087fecu,0x0c087feeu,0x0c087ff0u,0x0c087ff2u,0x0c087ff4u,0x0c087ff6u,0x0c087ff8u,0x0c087ffau,0x0c087ffcu,0x0c087ffeu,0x0c088000u,0x0c088002u,
0x0c088004u,0x0c088006u,0x0c088008u,0x0c08800au,0x0c08800cu,0x0c088024u,0x0c088026u,0x0c088028u,0x0c08802au,0x0c08802cu,0x0c08802eu,0x0c088030u,0x0c088032u,0x0c088034u,0x0c088036u,0x0c088038u,
0x0c08803au,0x0c08803cu,0x0c08803eu,0x0c088040u,0x0c088042u,0x0c088044u,0x0c088046u,0x0c088048u,0x0c08804au,0x0c08804cu,0x0c08804eu,0x0c088050u,0x0c088052u,0x0c088054u,0x0c088056u,0x0c088058u,
0x0c08805au,0x0c08805cu,0x0c08805eu,0x0c088060u,0x0c088062u,0x0c088064u,0x0c088066u,0x0c088068u,0x0c08806au,0x0c08806cu,0x0c08806eu,0x0c088070u,0x0c088072u,0x0c088074u,0x0c088076u,0x0c088078u,
0x0c08807au,0x0c08807cu,0x0c08807eu,0x0c088080u,0x0c088082u,0x0c088084u,0x0c088086u,0x0c088088u,0x0c08808au,0x0c08808cu,0x0c08808eu,0x0c088090u,0x0c088092u,0x0c088094u,0x0c088096u,0x0c088098u,
0x0c08809au,0x0c08809cu,0x0c08809eu,0x0c0880a0u,0x0c0880a2u,0x0c0880a4u,0x0c0880a6u,0x0c0880a8u,0x0c0880aau,0x0c0880acu,0x0c0880aeu,0x0c0880b0u,0x0c0880b2u,0x0c0880b4u,0x0c0880b6u,0x0c0880b8u,
0x0c0880bau,0x0c0880bcu,0x0c0880beu,0x0c0880c0u,0x0c0880c2u,0x0c0880c4u,0x0c0880c6u,0x0c0880c8u,0x0c0880cau,0x0c0880ccu,0x0c0880ceu,0x0c0880d0u,0x0c0880d2u,0x0c0880d4u,0x0c0880d6u,0x0c0880d8u,
0x0c0880dau,0x0c0880dcu,0x0c0880deu,0x0c0880e0u,0x0c0880e2u,0x0c0880e4u,0x0c0880e6u,0x0c0880e8u,0x0c0880eau,0x0c0880ecu,0x0c0880eeu,0x0c0880f0u,0x0c0880f2u,0x0c0880f4u,0x0c0880f6u,0x0c0880f8u,
0x0c0880fau,0x0c0880fcu,0x0c0880feu,0x0c088100u,0x0c088102u,0x0c088104u,0x0c088106u,0x0c088108u,0x0c08810au,0x0c08810cu,0x0c08810eu,0x0c088110u,0x0c088112u,0x0c088114u,0x0c088116u,0x0c088118u,
0x0c08811au,0x0c08811cu,0x0c08811eu,0x0c088120u,0x0c088122u,0x0c088124u,0x0c088126u,0x0c088128u,0x0c08812au,0x0c08812cu,0x0c08812eu,0x0c088130u,0x0c088132u,0x0c088134u,0x0c088136u,0x0c088138u,
0x0c08dbeeu,0x0c08dbf0u,0x0c08dbf2u,0x0c08dbf4u,0x0c08dbf6u,0x0c08dbf8u,0x0c08dbfau,0x0c08dbfcu,0x0c08dbfeu,0x0c08dc00u,0x0c08dc02u,0x0c08dc04u,0x0c08dc06u,0x0c08dc08u,0x0c08dc0au,0x0c08dc0cu,
0x0c08dc0eu,0x0c08dc10u,0x0c08dc12u,0x0c08dc14u,0x0c08dc16u,0x0c08dc18u,0x0c08dc1au,0x0c08dc1cu,0x0c08dc1eu,0x0c08dc20u,0x0c08dc22u,0x0c08dc24u,0x0c08dc26u,0x0c08dc28u,0x0c08dc2au,0x0c08dc2cu,
0x0c08dc2eu,0x0c08dc30u,0x0c08dc32u,0x0c08dc34u,0x0c08dc36u,0x0c08dc38u,0x0c08dc3au,0x0c08dc3cu,0x0c08dc4cu,0x0c08dc4eu,0x0c08dc50u,0x0c08dc52u,0x0c08dc54u,0x0c08dc56u,0x0c08dc58u,0x0c08dc5au,
0x0c08dc5cu,0x0c08dc5eu,0x0c08dc60u,0x0c08dc62u,0x0c08dc64u,0x0c08dc66u,0x0c08dc68u,0x0c08dc6au,0x0c08dc6cu,0x0c08dc6eu,0x0c08dc70u,0x0c08dc72u,0x0c08dc74u,0x0c08dc76u,0x0c08dc78u,0x0c08dc7au,
0x0c08dc7cu,0x0c08dc7eu,0x0c08dc80u,0x0c08dc82u,0x0c08dc84u,0x0c08dc86u,0x0c08dc88u,0x0c08dc8au,0x0c08dc8cu,0x0c08dc8eu,0x0c08dc90u,0x0c08dc92u,0x0c08dc94u,0x0c08dc96u,0x0c08dc98u,0x0c08dc9au,
0x0c08dc9cu,0x0c08dc9eu,0x0c08dca0u,0x0c08dca2u,0x0c08dca4u,0x0c08dca6u,0x0c08dca8u,0x0c08dcaau,0x0c08dcacu,0x0c08dcaeu,
};
int vf3_target_dependency_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
