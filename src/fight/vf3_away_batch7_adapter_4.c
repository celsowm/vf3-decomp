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
int vf3_away_batch7_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c055578u: goto P_0c055578;
case 0x0c05557au: goto P_0c05557a;
case 0x0c05557cu: goto P_0c05557c;
case 0x0c05557eu: goto P_0c05557e;
case 0x0c055580u: goto P_0c055580;
case 0x0c055582u: goto P_0c055582;
case 0x0c055584u: goto P_0c055584;
case 0x0c055586u: goto P_0c055586;
case 0x0c055588u: goto P_0c055588;
case 0x0c05558au: goto P_0c05558a;
case 0x0c05558cu: goto P_0c05558c;
case 0x0c05558eu: goto P_0c05558e;
case 0x0c055590u: goto P_0c055590;
case 0x0c055592u: goto P_0c055592;
case 0x0c055594u: goto P_0c055594;
case 0x0c055596u: goto P_0c055596;
case 0x0c055598u: goto P_0c055598;
case 0x0c05559au: goto P_0c05559a;
case 0x0c05559cu: goto P_0c05559c;
case 0x0c05559eu: goto P_0c05559e;
case 0x0c0555a0u: goto P_0c0555a0;
case 0x0c0555a2u: goto P_0c0555a2;
case 0x0c0555a4u: goto P_0c0555a4;
case 0x0c0555a6u: goto P_0c0555a6;
case 0x0c0555a8u: goto P_0c0555a8;
case 0x0c0555aau: goto P_0c0555aa;
case 0x0c0555acu: goto P_0c0555ac;
case 0x0c0555aeu: goto P_0c0555ae;
case 0x0c0555b0u: goto P_0c0555b0;
case 0x0c0555b2u: goto P_0c0555b2;
case 0x0c0555b4u: goto P_0c0555b4;
case 0x0c0555b6u: goto P_0c0555b6;
case 0x0c0555b8u: goto P_0c0555b8;
case 0x0c0555bau: goto P_0c0555ba;
case 0x0c0555bcu: goto P_0c0555bc;
case 0x0c0555beu: goto P_0c0555be;
case 0x0c059000u: goto P_0c059000;
case 0x0c059002u: goto P_0c059002;
case 0x0c059004u: goto P_0c059004;
case 0x0c059006u: goto P_0c059006;
case 0x0c059008u: goto P_0c059008;
case 0x0c05900au: goto P_0c05900a;
case 0x0c05900cu: goto P_0c05900c;
case 0x0c05900eu: goto P_0c05900e;
case 0x0c059010u: goto P_0c059010;
case 0x0c059012u: goto P_0c059012;
case 0x0c059014u: goto P_0c059014;
case 0x0c059016u: goto P_0c059016;
case 0x0c059018u: goto P_0c059018;
case 0x0c05901au: goto P_0c05901a;
case 0x0c05901cu: goto P_0c05901c;
case 0x0c05901eu: goto P_0c05901e;
case 0x0c059020u: goto P_0c059020;
case 0x0c059022u: goto P_0c059022;
case 0x0c059024u: goto P_0c059024;
case 0x0c059026u: goto P_0c059026;
case 0x0c059028u: goto P_0c059028;
case 0x0c05902au: goto P_0c05902a;
case 0x0c05902cu: goto P_0c05902c;
case 0x0c05902eu: goto P_0c05902e;
case 0x0c059030u: goto P_0c059030;
case 0x0c059032u: goto P_0c059032;
case 0x0c059034u: goto P_0c059034;
case 0x0c059036u: goto P_0c059036;
case 0x0c059038u: goto P_0c059038;
case 0x0c05903au: goto P_0c05903a;
case 0x0c05903cu: goto P_0c05903c;
case 0x0c05903eu: goto P_0c05903e;
case 0x0c059040u: goto P_0c059040;
case 0x0c059042u: goto P_0c059042;
case 0x0c059044u: goto P_0c059044;
case 0x0c059046u: goto P_0c059046;
case 0x0c059048u: goto P_0c059048;
case 0x0c05904au: goto P_0c05904a;
case 0x0c059140u: goto P_0c059140;
case 0x0c059142u: goto P_0c059142;
case 0x0c059144u: goto P_0c059144;
case 0x0c059146u: goto P_0c059146;
case 0x0c059148u: goto P_0c059148;
case 0x0c05914au: goto P_0c05914a;
case 0x0c05914cu: goto P_0c05914c;
case 0x0c05914eu: goto P_0c05914e;
case 0x0c059150u: goto P_0c059150;
case 0x0c059152u: goto P_0c059152;
case 0x0c059154u: goto P_0c059154;
case 0x0c059156u: goto P_0c059156;
case 0x0c059158u: goto P_0c059158;
case 0x0c05915au: goto P_0c05915a;
case 0x0c05915cu: goto P_0c05915c;
case 0x0c05915eu: goto P_0c05915e;
case 0x0c059160u: goto P_0c059160;
case 0x0c059162u: goto P_0c059162;
case 0x0c059164u: goto P_0c059164;
case 0x0c059166u: goto P_0c059166;
case 0x0c059168u: goto P_0c059168;
case 0x0c05916au: goto P_0c05916a;
case 0x0c05916cu: goto P_0c05916c;
case 0x0c05916eu: goto P_0c05916e;
case 0x0c059170u: goto P_0c059170;
case 0x0c059172u: goto P_0c059172;
case 0x0c059174u: goto P_0c059174;
case 0x0c059176u: goto P_0c059176;
case 0x0c059178u: goto P_0c059178;
case 0x0c05917au: goto P_0c05917a;
case 0x0c05917cu: goto P_0c05917c;
case 0x0c05917eu: goto P_0c05917e;
case 0x0c059180u: goto P_0c059180;
case 0x0c059182u: goto P_0c059182;
case 0x0c059184u: goto P_0c059184;
case 0x0c059186u: goto P_0c059186;
case 0x0c059188u: goto P_0c059188;
case 0x0c05918au: goto P_0c05918a;
case 0x0c05918cu: goto P_0c05918c;
case 0x0c05918eu: goto P_0c05918e;
case 0x0c059190u: goto P_0c059190;
case 0x0c059192u: goto P_0c059192;
case 0x0c059194u: goto P_0c059194;
case 0x0c059196u: goto P_0c059196;
case 0x0c059198u: goto P_0c059198;
case 0x0c05919au: goto P_0c05919a;
case 0x0c05919cu: goto P_0c05919c;
case 0x0c05919eu: goto P_0c05919e;
case 0x0c0591a0u: goto P_0c0591a0;
case 0x0c0591a2u: goto P_0c0591a2;
case 0x0c0591a4u: goto P_0c0591a4;
case 0x0c0591a6u: goto P_0c0591a6;
case 0x0c0591a8u: goto P_0c0591a8;
case 0x0c0591aau: goto P_0c0591aa;
case 0x0c0591acu: goto P_0c0591ac;
case 0x0c0591aeu: goto P_0c0591ae;
case 0x0c059840u: goto P_0c059840;
case 0x0c059842u: goto P_0c059842;
case 0x0c059844u: goto P_0c059844;
case 0x0c059846u: goto P_0c059846;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
case 0x0c059896u: goto P_0c059896;
case 0x0c059898u: goto P_0c059898;
case 0x0c05989au: goto P_0c05989a;
case 0x0c05989cu: goto P_0c05989c;
case 0x0c05989eu: goto P_0c05989e;
case 0x0c0598a0u: goto P_0c0598a0;
case 0x0c0598a2u: goto P_0c0598a2;
case 0x0c0598a4u: goto P_0c0598a4;
case 0x0c0598a6u: goto P_0c0598a6;
case 0x0c0598a8u: goto P_0c0598a8;
case 0x0c0598aau: goto P_0c0598aa;
case 0x0c0598acu: goto P_0c0598ac;
case 0x0c0598aeu: goto P_0c0598ae;
case 0x0c0598b0u: goto P_0c0598b0;
case 0x0c0598b2u: goto P_0c0598b2;
case 0x0c0598b4u: goto P_0c0598b4;
case 0x0c0598b6u: goto P_0c0598b6;
case 0x0c0598b8u: goto P_0c0598b8;
case 0x0c0598bau: goto P_0c0598ba;
case 0x0c0598bcu: goto P_0c0598bc;
case 0x0c0598beu: goto P_0c0598be;
case 0x0c0598c0u: goto P_0c0598c0;
case 0x0c0598c2u: goto P_0c0598c2;
case 0x0c0598c4u: goto P_0c0598c4;
case 0x0c0598c6u: goto P_0c0598c6;
case 0x0c0598c8u: goto P_0c0598c8;
case 0x0c0598cau: goto P_0c0598ca;
case 0x0c0598ccu: goto P_0c0598cc;
case 0x0c0598ceu: goto P_0c0598ce;
case 0x0c0598d0u: goto P_0c0598d0;
case 0x0c0598d2u: goto P_0c0598d2;
case 0x0c0598d4u: goto P_0c0598d4;
case 0x0c0598d6u: goto P_0c0598d6;
case 0x0c0598d8u: goto P_0c0598d8;
case 0x0c0598dau: goto P_0c0598da;
case 0x0c0598dcu: goto P_0c0598dc;
case 0x0c0598deu: goto P_0c0598de;
case 0x0c0598e0u: goto P_0c0598e0;
case 0x0c0598e2u: goto P_0c0598e2;
case 0x0c0598e4u: goto P_0c0598e4;
case 0x0c0598e6u: goto P_0c0598e6;
case 0x0c0598e8u: goto P_0c0598e8;
case 0x0c0598eau: goto P_0c0598ea;
case 0x0c0598ecu: goto P_0c0598ec;
case 0x0c0598eeu: goto P_0c0598ee;
case 0x0c059920u: goto P_0c059920;
case 0x0c059922u: goto P_0c059922;
case 0x0c059924u: goto P_0c059924;
case 0x0c059926u: goto P_0c059926;
case 0x0c059928u: goto P_0c059928;
case 0x0c05992au: goto P_0c05992a;
case 0x0c05992cu: goto P_0c05992c;
case 0x0c05992eu: goto P_0c05992e;
case 0x0c059930u: goto P_0c059930;
case 0x0c059932u: goto P_0c059932;
case 0x0c059934u: goto P_0c059934;
case 0x0c059936u: goto P_0c059936;
case 0x0c059938u: goto P_0c059938;
case 0x0c05993au: goto P_0c05993a;
case 0x0c05993cu: goto P_0c05993c;
case 0x0c05993eu: goto P_0c05993e;
case 0x0c059940u: goto P_0c059940;
case 0x0c059942u: goto P_0c059942;
case 0x0c059944u: goto P_0c059944;
case 0x0c059946u: goto P_0c059946;
case 0x0c059948u: goto P_0c059948;
case 0x0c05994au: goto P_0c05994a;
case 0x0c05994cu: goto P_0c05994c;
case 0x0c05994eu: goto P_0c05994e;
case 0x0c059950u: goto P_0c059950;
case 0x0c059952u: goto P_0c059952;
case 0x0c059954u: goto P_0c059954;
case 0x0c059956u: goto P_0c059956;
case 0x0c059958u: goto P_0c059958;
case 0x0c05995au: goto P_0c05995a;
case 0x0c05995cu: goto P_0c05995c;
case 0x0c05995eu: goto P_0c05995e;
case 0x0c059960u: goto P_0c059960;
case 0x0c059962u: goto P_0c059962;
case 0x0c059964u: goto P_0c059964;
case 0x0c059966u: goto P_0c059966;
case 0x0c059968u: goto P_0c059968;
case 0x0c05996au: goto P_0c05996a;
case 0x0c05996cu: goto P_0c05996c;
case 0x0c05996eu: goto P_0c05996e;
case 0x0c059970u: goto P_0c059970;
case 0x0c059972u: goto P_0c059972;
case 0x0c059974u: goto P_0c059974;
case 0x0c059976u: goto P_0c059976;
case 0x0c059978u: goto P_0c059978;
case 0x0c05997au: goto P_0c05997a;
case 0x0c05997cu: goto P_0c05997c;
case 0x0c05997eu: goto P_0c05997e;
case 0x0c059980u: goto P_0c059980;
case 0x0c059982u: goto P_0c059982;
case 0x0c059984u: goto P_0c059984;
case 0x0c059986u: goto P_0c059986;
case 0x0c059988u: goto P_0c059988;
case 0x0c05998au: goto P_0c05998a;
case 0x0c05998cu: goto P_0c05998c;
case 0x0c05998eu: goto P_0c05998e;
case 0x0c059990u: goto P_0c059990;
case 0x0c059992u: goto P_0c059992;
case 0x0c059994u: goto P_0c059994;
case 0x0c059996u: goto P_0c059996;
case 0x0c059998u: goto P_0c059998;
case 0x0c05999au: goto P_0c05999a;
case 0x0c05999cu: goto P_0c05999c;
case 0x0c05999eu: goto P_0c05999e;
case 0x0c0599a0u: goto P_0c0599a0;
case 0x0c0599a2u: goto P_0c0599a2;
case 0x0c0599a4u: goto P_0c0599a4;
case 0x0c0599a6u: goto P_0c0599a6;
case 0x0c0599a8u: goto P_0c0599a8;
case 0x0c0599aau: goto P_0c0599aa;
case 0x0c0599acu: goto P_0c0599ac;
case 0x0c0599aeu: goto P_0c0599ae;
case 0x0c0599b0u: goto P_0c0599b0;
case 0x0c0599b2u: goto P_0c0599b2;
case 0x0c0599b4u: goto P_0c0599b4;
case 0x0c0599b6u: goto P_0c0599b6;
case 0x0c0599b8u: goto P_0c0599b8;
case 0x0c0599bau: goto P_0c0599ba;
case 0x0c0599bcu: goto P_0c0599bc;
case 0x0c0599beu: goto P_0c0599be;
case 0x0c0599c0u: goto P_0c0599c0;
case 0x0c0599c2u: goto P_0c0599c2;
case 0x0c0599c4u: goto P_0c0599c4;
case 0x0c0599c6u: goto P_0c0599c6;
case 0x0c0599c8u: goto P_0c0599c8;
case 0x0c0599cau: goto P_0c0599ca;
case 0x0c0599ccu: goto P_0c0599cc;
case 0x0c0599ceu: goto P_0c0599ce;
case 0x0c0599d0u: goto P_0c0599d0;
case 0x0c0599d2u: goto P_0c0599d2;
case 0x0c0599d4u: goto P_0c0599d4;
case 0x0c0599d6u: goto P_0c0599d6;
case 0x0c0599d8u: goto P_0c0599d8;
case 0x0c0599dau: goto P_0c0599da;
case 0x0c0599dcu: goto P_0c0599dc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c055578: /* original 2fe6, guest PC 0x0c055578 */
if(!s->budget--) { s->failed_pc=0x0c055578u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05557a;
P_0c05557a: /* original e700, guest PC 0x0c05557a */
if(!s->budget--) { s->failed_pc=0x0c05557au; return 0; }
r[7]=0x00000000u;
goto P_0c05557c;
P_0c05557c: /* original 2fd6, guest PC 0x0c05557c */
if(!s->budget--) { s->failed_pc=0x0c05557cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05557e;
P_0c05557e: /* original e600, guest PC 0x0c05557e */
if(!s->budget--) { s->failed_pc=0x0c05557eu; return 0; }
r[6]=0x00000000u;
goto P_0c055580;
P_0c055580: /* original 7ffc, guest PC 0x0c055580 */
if(!s->budget--) { s->failed_pc=0x0c055580u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c055582;
P_0c055582: /* original 6e73, guest PC 0x0c055582 */
if(!s->budget--) { s->failed_pc=0x0c055582u; return 0; }
r[14]=r[7];
goto P_0c055584;
P_0c055584: /* original 364c, guest PC 0x0c055584 */
if(!s->budget--) { s->failed_pc=0x0c055584u; return 0; }
r[6]+=r[4];
goto P_0c055586;
P_0c055586: /* original 6463, guest PC 0x0c055586 */
if(!s->budget--) { s->failed_pc=0x0c055586u; return 0; }
r[4]=r[6];
goto P_0c055588;
P_0c055588: /* original 2f62, guest PC 0x0c055588 */
if(!s->budget--) { s->failed_pc=0x0c055588u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05558a;
P_0c05558a: /* original 4515, guest PC 0x0c05558a */
if(!s->budget--) { s->failed_pc=0x0c05558au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c05558c;
P_0c05558c: /* original 8f12, guest PC 0x0c05558c */
if(!s->budget--) { s->failed_pc=0x0c05558cu; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0555b4; }
goto P_0c055590;
P_0c05558e: /* original ed01, guest PC 0x0c05558e */
if(!s->budget--) { s->failed_pc=0x0c05558eu; return 0; }
r[13]=0x00000001u;
goto P_0c055590;
P_0c055590: /* original 6140, guest PC 0x0c055590 */
if(!s->budget--) { s->failed_pc=0x0c055590u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c055592;
P_0c055592: /* original 611c, guest PC 0x0c055592 */
if(!s->budget--) { s->failed_pc=0x0c055592u; return 0; }
r[1]=r[1]&255u;
goto P_0c055594;
P_0c055594: /* original 6340, guest PC 0x0c055594 */
if(!s->budget--) { s->failed_pc=0x0c055594u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c055596;
P_0c055596: /* original 21d9, guest PC 0x0c055596 */
if(!s->budget--) { s->failed_pc=0x0c055596u; return 0; }
r[1]&=r[13];
goto P_0c055598;
P_0c055598: /* original 633c, guest PC 0x0c055598 */
if(!s->budget--) { s->failed_pc=0x0c055598u; return 0; }
r[3]=r[3]&255u;
goto P_0c05559a;
P_0c05559a: /* original 4301, guest PC 0x0c05559a */
if(!s->budget--) { s->failed_pc=0x0c05559au; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c05559c;
P_0c05559c: /* original 2778, guest PC 0x0c05559c */
if(!s->budget--) { s->failed_pc=0x0c05559cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05559e;
P_0c05559e: /* original 8d03, guest PC 0x0c05559e */
if(!s->budget--) { s->failed_pc=0x0c05559eu; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[3],1);
if(cond) { goto P_0c0555a8; }
goto P_0c0555a2;
P_0c0555a0: /* original 2430, guest PC 0x0c0555a0 */
if(!s->budget--) { s->failed_pc=0x0c0555a0u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0555a2;
P_0c0555a2: /* original 6060, guest PC 0x0c0555a2 */
if(!s->budget--) { s->failed_pc=0x0c0555a2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0555a4;
P_0c0555a4: /* original cb80, guest PC 0x0c0555a4 */
if(!s->budget--) { s->failed_pc=0x0c0555a4u; return 0; }
r[0]|=128u;
goto P_0c0555a6;
P_0c0555a6: /* original 2600, guest PC 0x0c0555a6 */
if(!s->budget--) { s->failed_pc=0x0c0555a6u; return 0; }
write(ram,r[6],r[0],1);
goto P_0c0555a8;
P_0c0555a8: /* original 6713, guest PC 0x0c0555a8 */
if(!s->budget--) { s->failed_pc=0x0c0555a8u; return 0; }
r[7]=r[1];
goto P_0c0555aa;
P_0c0555aa: /* original 7e01, guest PC 0x0c0555aa */
if(!s->budget--) { s->failed_pc=0x0c0555aau; return 0; }
r[14]+=0x00000001u;
goto P_0c0555ac;
P_0c0555ac: /* original 7601, guest PC 0x0c0555ac */
if(!s->budget--) { s->failed_pc=0x0c0555acu; return 0; }
r[6]+=0x00000001u;
goto P_0c0555ae;
P_0c0555ae: /* original 3e53, guest PC 0x0c0555ae */
if(!s->budget--) { s->failed_pc=0x0c0555aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c0555b0;
P_0c0555b0: /* original 8fee, guest PC 0x0c0555b0 */
if(!s->budget--) { s->failed_pc=0x0c0555b0u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c055590; }
goto P_0c0555b4;
P_0c0555b2: /* original 7401, guest PC 0x0c0555b2 */
if(!s->budget--) { s->failed_pc=0x0c0555b2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0555b4;
P_0c0555b4: /* original 6073, guest PC 0x0c0555b4 */
if(!s->budget--) { s->failed_pc=0x0c0555b4u; return 0; }
r[0]=r[7];
goto P_0c0555b6;
P_0c0555b6: /* original 0009, guest PC 0x0c0555b6 */
if(!s->budget--) { s->failed_pc=0x0c0555b6u; return 0; }
goto P_0c0555b8;
P_0c0555b8: /* original 7f04, guest PC 0x0c0555b8 */
if(!s->budget--) { s->failed_pc=0x0c0555b8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0555ba;
P_0c0555ba: /* original 6df6, guest PC 0x0c0555ba */
if(!s->budget--) { s->failed_pc=0x0c0555bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0555bc;
P_0c0555bc: /* original 000b, guest PC 0x0c0555bc */
if(!s->budget--) { s->failed_pc=0x0c0555bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0555be: /* original 6ef6, guest PC 0x0c0555be */
if(!s->budget--) { s->failed_pc=0x0c0555beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0555c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0555c0u; return 0; } return 1;
P_0c059000: /* original 2fe6, guest PC 0x0c059000 */
if(!s->budget--) { s->failed_pc=0x0c059000u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059002;
P_0c059002: /* original 2fd6, guest PC 0x0c059002 */
if(!s->budget--) { s->failed_pc=0x0c059002u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059004;
P_0c059004: /* original 2fc6, guest PC 0x0c059004 */
if(!s->budget--) { s->failed_pc=0x0c059004u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059006;
P_0c059006: /* original 2f66, guest PC 0x0c059006 */
if(!s->budget--) { s->failed_pc=0x0c059006u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059008;
P_0c059008: /* original 6e43, guest PC 0x0c059008 */
if(!s->budget--) { s->failed_pc=0x0c059008u; return 0; }
r[14]=r[4];
goto P_0c05900a;
P_0c05900a: /* original 0c2a, guest PC 0x0c05900a */
if(!s->budget--) { s->failed_pc=0x0c05900au; return 0; }
r[12]=r[16];
goto P_0c05900c;
P_0c05900c: /* original 6473, guest PC 0x0c05900c */
if(!s->budget--) { s->failed_pc=0x0c05900cu; return 0; }
r[4]=r[7];
goto P_0c05900e;
P_0c05900e: /* original d37a, guest PC 0x0c05900e */
if(!s->budget--) { s->failed_pc=0x0c05900eu; return 0; }
r[3]=read(ram,0x0c0591f8u,4);
goto P_0c059010;
P_0c059010: /* original 430b, guest PC 0x0c059010 */
if(!s->budget--) { s->failed_pc=0x0c059010u; return 0; }
target=r[3];
r[16]=code_base|0x0c059014u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059014u) { target=s->pc; goto dispatch; }
goto P_0c059014;
P_0c059012: /* original 7410, guest PC 0x0c059012 */
if(!s->budget--) { s->failed_pc=0x0c059012u; return 0; }
r[4]+=0x00000010u;
goto P_0c059014;
P_0c059014: /* original 6903, guest PC 0x0c059014 */
if(!s->budget--) { s->failed_pc=0x0c059014u; return 0; }
r[9]=r[0];
goto P_0c059016;
P_0c059016: /* original 4c2a, guest PC 0x0c059016 */
if(!s->budget--) { s->failed_pc=0x0c059016u; return 0; }
r[16]=r[12];
goto P_0c059018;
P_0c059018: /* original 64e3, guest PC 0x0c059018 */
if(!s->budget--) { s->failed_pc=0x0c059018u; return 0; }
r[4]=r[14];
goto P_0c05901a;
P_0c05901a: /* original 66f6, guest PC 0x0c05901a */
if(!s->budget--) { s->failed_pc=0x0c05901au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c05901c;
P_0c05901c: /* original d572, guest PC 0x0c05901c */
if(!s->budget--) { s->failed_pc=0x0c05901cu; return 0; }
r[5]=read(ram,0x0c0591e8u,4);
goto P_0c05901e;
P_0c05901e: /* original d873, guest PC 0x0c05901e */
if(!s->budget--) { s->failed_pc=0x0c05901eu; return 0; }
r[8]=read(ram,0x0c0591ecu,4);
goto P_0c059020;
P_0c059020: /* original 6552, guest PC 0x0c059020 */
if(!s->budget--) { s->failed_pc=0x0c059020u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c059022;
P_0c059022: /* original 6882, guest PC 0x0c059022 */
if(!s->budget--) { s->failed_pc=0x0c059022u; return 0; }
tmp=read(ram,r[8],4);
r[8]=tmp;
goto P_0c059024;
P_0c059024: /* original 750c, guest PC 0x0c059024 */
if(!s->budget--) { s->failed_pc=0x0c059024u; return 0; }
r[5]+=0x0000000cu;
goto P_0c059026;
P_0c059026: /* original 7808, guest PC 0x0c059026 */
if(!s->budget--) { s->failed_pc=0x0c059026u; return 0; }
r[8]+=0x00000008u;
goto P_0c059028;
P_0c059028: /* original f049, guest PC 0x0c059028 */
if(!s->budget--) { s->failed_pc=0x0c059028u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c05902a;
P_0c05902a: /* original f149, guest PC 0x0c05902a */
if(!s->budget--) { s->failed_pc=0x0c05902au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c05902c;
P_0c05902c: /* original f249, guest PC 0x0c05902c */
if(!s->budget--) { s->failed_pc=0x0c05902cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c05902e;
P_0c05902e: /* original f39d, guest PC 0x0c05902e */
if(!s->budget--) { s->failed_pc=0x0c05902eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c059030;
P_0c059030: /* original f449, guest PC 0x0c059030 */
if(!s->budget--) { s->failed_pc=0x0c059030u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c059032;
P_0c059032: /* original f549, guest PC 0x0c059032 */
if(!s->budget--) { s->failed_pc=0x0c059032u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c059034;
P_0c059034: /* original f649, guest PC 0x0c059034 */
if(!s->budget--) { s->failed_pc=0x0c059034u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c059036;
P_0c059036: /* original d06a, guest PC 0x0c059036 */
if(!s->budget--) { s->failed_pc=0x0c059036u; return 0; }
r[0]=read(ram,0x0c0591e0u,4);
goto P_0c059038;
P_0c059038: /* original de6a, guest PC 0x0c059038 */
if(!s->budget--) { s->failed_pc=0x0c059038u; return 0; }
r[14]=read(ram,0x0c0591e4u,4);
goto P_0c05903a;
P_0c05903a: /* original 7004, guest PC 0x0c05903a */
if(!s->budget--) { s->failed_pc=0x0c05903au; return 0; }
r[0]+=0x00000004u;
goto P_0c05903c;
P_0c05903c: /* original fc09, guest PC 0x0c05903c */
if(!s->budget--) { s->failed_pc=0x0c05903cu; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c05903e;
P_0c05903e: /* original 6d93, guest PC 0x0c05903e */
if(!s->budget--) { s->failed_pc=0x0c05903eu; return 0; }
r[13]=r[9];
goto P_0c059040;
P_0c059040: /* original fd09, guest PC 0x0c059040 */
if(!s->budget--) { s->failed_pc=0x0c059040u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c059042;
P_0c059042: /* original 2dd8, guest PC 0x0c059042 */
if(!s->budget--) { s->failed_pc=0x0c059042u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c059044;
P_0c059044: /* original fe08, guest PC 0x0c059044 */
if(!s->budget--) { s->failed_pc=0x0c059044u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c059046;
P_0c059046: /* original 8b00, guest PC 0x0c059046 */
if(!s->budget--) { s->failed_pc=0x0c059046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05904a; }
goto P_0c059048;
P_0c059048: /* original a07a, guest PC 0x0c059048 */
if(!s->budget--) { s->failed_pc=0x0c059048u; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c059140;
P_0c05904a: /* original 4d01, guest PC 0x0c05904a */
if(!s->budget--) { s->failed_pc=0x0c05904au; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
if(!vf3_matrix_family(0x0c05904cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05904cu; return 0; } return 1;
P_0c059140: /* original f1fd, guest PC 0x0c059140 */
if(!s->budget--) { s->failed_pc=0x0c059140u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c059142;
P_0c059142: /* original e043, guest PC 0x0c059142 */
if(!s->budget--) { s->failed_pc=0x0c059142u; return 0; }
r[0]=0x00000043u;
goto P_0c059144;
P_0c059144: /* original 4018, guest PC 0x0c059144 */
if(!s->budget--) { s->failed_pc=0x0c059144u; return 0; }
r[0]<<=8;
goto P_0c059146;
P_0c059146: /* original cb7f, guest PC 0x0c059146 */
if(!s->budget--) { s->failed_pc=0x0c059146u; return 0; }
r[0]|=127u;
goto P_0c059148;
P_0c059148: /* original 4028, guest PC 0x0c059148 */
if(!s->budget--) { s->failed_pc=0x0c059148u; return 0; }
r[0]<<=16;
goto P_0c05914a;
P_0c05914a: /* original 405a, guest PC 0x0c05914a */
if(!s->budget--) { s->failed_pc=0x0c05914au; return 0; }
r[53]=r[0];
goto P_0c05914c;
P_0c05914c: /* original eeff, guest PC 0x0c05914c */
if(!s->budget--) { s->failed_pc=0x0c05914cu; return 0; }
r[14]=0xffffffffu;
goto P_0c05914e;
P_0c05914e: /* original ff0d, guest PC 0x0c05914e */
if(!s->budget--) { s->failed_pc=0x0c05914eu; return 0; }
fr[15]=r[53];
goto P_0c059150;
P_0c059150: /* original fcf2, guest PC 0x0c059150 */
if(!s->budget--) { s->failed_pc=0x0c059150u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c059152;
P_0c059152: /* original f29d, guest PC 0x0c059152 */
if(!s->budget--) { s->failed_pc=0x0c059152u; return 0; }
fr[2]=0x3f800000u;
goto P_0c059154;
P_0c059154: /* original fdf2, guest PC 0x0c059154 */
if(!s->budget--) { s->failed_pc=0x0c059154u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c059156;
P_0c059156: /* original f233, guest PC 0x0c059156 */
if(!s->budget--) { s->failed_pc=0x0c059156u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c059158;
P_0c059158: /* original 60ec, guest PC 0x0c059158 */
if(!s->budget--) { s->failed_pc=0x0c059158u; return 0; }
r[0]=r[14]&255u;
goto P_0c05915a;
P_0c05915a: /* original fef2, guest PC 0x0c05915a */
if(!s->budget--) { s->failed_pc=0x0c05915au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c05915c;
P_0c05915c: /* original ee00, guest PC 0x0c05915c */
if(!s->budget--) { s->failed_pc=0x0c05915cu; return 0; }
r[14]=0x00000000u;
goto P_0c05915e;
P_0c05915e: /* original fc3d, guest PC 0x0c05915e */
if(!s->budget--) { s->failed_pc=0x0c05915eu; return 0; }
r[53]=truncate_float(fr[12]);
goto P_0c059160;
P_0c059160: /* original 0b5a, guest PC 0x0c059160 */
if(!s->budget--) { s->failed_pc=0x0c059160u; return 0; }
r[11]=r[53];
goto P_0c059162;
P_0c059162: /* original fd3d, guest PC 0x0c059162 */
if(!s->budget--) { s->failed_pc=0x0c059162u; return 0; }
r[53]=truncate_float(fr[13]);
goto P_0c059164;
P_0c059164: /* original 0c5a, guest PC 0x0c059164 */
if(!s->budget--) { s->failed_pc=0x0c059164u; return 0; }
r[12]=r[53];
goto P_0c059166;
P_0c059166: /* original fe3d, guest PC 0x0c059166 */
if(!s->budget--) { s->failed_pc=0x0c059166u; return 0; }
r[53]=truncate_float(fr[14]);
goto P_0c059168;
P_0c059168: /* original 0d5a, guest PC 0x0c059168 */
if(!s->budget--) { s->failed_pc=0x0c059168u; return 0; }
r[13]=r[53];
goto P_0c05916a;
P_0c05916a: /* original 3b07, guest PC 0x0c05916a */
if(!s->budget--) { s->failed_pc=0x0c05916au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[0])!=0);
goto P_0c05916c;
P_0c05916c: /* original 8b00, guest PC 0x0c05916c */
if(!s->budget--) { s->failed_pc=0x0c05916cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059170; }
goto P_0c05916e;
P_0c05916e: /* original 6b03, guest PC 0x0c05916e */
if(!s->budget--) { s->failed_pc=0x0c05916eu; return 0; }
r[11]=r[0];
goto P_0c059170;
P_0c059170: /* original 4b11, guest PC 0x0c059170 */
if(!s->budget--) { s->failed_pc=0x0c059170u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=0)!=0);
goto P_0c059172;
P_0c059172: /* original 8900, guest PC 0x0c059172 */
if(!s->budget--) { s->failed_pc=0x0c059172u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059176; }
goto P_0c059174;
P_0c059174: /* original eb00, guest PC 0x0c059174 */
if(!s->budget--) { s->failed_pc=0x0c059174u; return 0; }
r[11]=0x00000000u;
goto P_0c059176;
P_0c059176: /* original 3c07, guest PC 0x0c059176 */
if(!s->budget--) { s->failed_pc=0x0c059176u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[0])!=0);
goto P_0c059178;
P_0c059178: /* original 2ebb, guest PC 0x0c059178 */
if(!s->budget--) { s->failed_pc=0x0c059178u; return 0; }
r[14]|=r[11];
goto P_0c05917a;
P_0c05917a: /* original 8b00, guest PC 0x0c05917a */
if(!s->budget--) { s->failed_pc=0x0c05917au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05917e; }
goto P_0c05917c;
P_0c05917c: /* original 6c03, guest PC 0x0c05917c */
if(!s->budget--) { s->failed_pc=0x0c05917cu; return 0; }
r[12]=r[0];
goto P_0c05917e;
P_0c05917e: /* original 4c11, guest PC 0x0c05917e */
if(!s->budget--) { s->failed_pc=0x0c05917eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c059180;
P_0c059180: /* original f52b, guest PC 0x0c059180 */
if(!s->budget--) { s->failed_pc=0x0c059180u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c059182;
P_0c059182: /* original 8900, guest PC 0x0c059182 */
if(!s->budget--) { s->failed_pc=0x0c059182u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059186; }
goto P_0c059184;
P_0c059184: /* original ec00, guest PC 0x0c059184 */
if(!s->budget--) { s->failed_pc=0x0c059184u; return 0; }
r[12]=0x00000000u;
goto P_0c059186;
P_0c059186: /* original 3d07, guest PC 0x0c059186 */
if(!s->budget--) { s->failed_pc=0x0c059186u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[0])!=0);
goto P_0c059188;
P_0c059188: /* original 4c18, guest PC 0x0c059188 */
if(!s->budget--) { s->failed_pc=0x0c059188u; return 0; }
r[12]<<=8;
goto P_0c05918a;
P_0c05918a: /* original 8b00, guest PC 0x0c05918a */
if(!s->budget--) { s->failed_pc=0x0c05918au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05918e; }
goto P_0c05918c;
P_0c05918c: /* original 6d03, guest PC 0x0c05918c */
if(!s->budget--) { s->failed_pc=0x0c05918cu; return 0; }
r[13]=r[0];
goto P_0c05918e;
P_0c05918e: /* original 4d11, guest PC 0x0c05918e */
if(!s->budget--) { s->failed_pc=0x0c05918eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c059190;
P_0c059190: /* original f122, guest PC 0x0c059190 */
if(!s->budget--) { s->failed_pc=0x0c059190u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c059192;
P_0c059192: /* original 8900, guest PC 0x0c059192 */
if(!s->budget--) { s->failed_pc=0x0c059192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059196; }
goto P_0c059194;
P_0c059194: /* original ed00, guest PC 0x0c059194 */
if(!s->budget--) { s->failed_pc=0x0c059194u; return 0; }
r[13]=0x00000000u;
goto P_0c059196;
P_0c059196: /* original 4e28, guest PC 0x0c059196 */
if(!s->budget--) { s->failed_pc=0x0c059196u; return 0; }
r[14]<<=16;
goto P_0c059198;
P_0c059198: /* original f022, guest PC 0x0c059198 */
if(!s->budget--) { s->failed_pc=0x0c059198u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'*');
goto P_0c05919a;
P_0c05919a: /* original 2cdb, guest PC 0x0c05919a */
if(!s->budget--) { s->failed_pc=0x0c05919au; return 0; }
r[12]|=r[13];
goto P_0c05919c;
P_0c05919c: /* original f51b, guest PC 0x0c05919c */
if(!s->budget--) { s->failed_pc=0x0c05919cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[5]);
goto P_0c05919e;
P_0c05919e: /* original 2ecb, guest PC 0x0c05919e */
if(!s->budget--) { s->failed_pc=0x0c05919eu; return 0; }
r[14]|=r[12];
goto P_0c0591a0;
P_0c0591a0: /* original f50b, guest PC 0x0c0591a0 */
if(!s->budget--) { s->failed_pc=0x0c0591a0u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[5]);
goto P_0c0591a2;
P_0c0591a2: /* original 4610, guest PC 0x0c0591a2 */
if(!s->budget--) { s->failed_pc=0x0c0591a2u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0591a4;
P_0c0591a4: /* original 28e6, guest PC 0x0c0591a4 */
if(!s->budget--) { s->failed_pc=0x0c0591a4u; return 0; }
tmp=r[14]; r[8]-=4; write(ram,r[8],tmp,4);
goto P_0c0591a6;
P_0c0591a6: /* original 751c, guest PC 0x0c0591a6 */
if(!s->budget--) { s->failed_pc=0x0c0591a6u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0591a8;
P_0c0591a8: /* original 28e6, guest PC 0x0c0591a8 */
if(!s->budget--) { s->failed_pc=0x0c0591a8u; return 0; }
tmp=r[14]; r[8]-=4; write(ram,r[8],tmp,4);
goto P_0c0591aa;
P_0c0591aa: /* original 8900, guest PC 0x0c0591aa */
if(!s->budget--) { s->failed_pc=0x0c0591aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0591ae; }
goto P_0c0591ac;
P_0c0591ac: /* original af3c, guest PC 0x0c0591ac */
if(!s->budget--) { s->failed_pc=0x0c0591acu; return 0; }
r[8]+=0x00000010u;
goto P_0c059028;
P_0c0591ae: /* original 7810, guest PC 0x0c0591ae */
if(!s->budget--) { s->failed_pc=0x0c0591aeu; return 0; }
r[8]+=0x00000010u;
if(!vf3_matrix_family(0x0c0591b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0591b0u; return 0; } return 1;
P_0c059840: /* original 2fe6, guest PC 0x0c059840 */
if(!s->budget--) { s->failed_pc=0x0c059840u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059842;
P_0c059842: /* original 2fd6, guest PC 0x0c059842 */
if(!s->budget--) { s->failed_pc=0x0c059842u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059844;
P_0c059844: /* original 2fc6, guest PC 0x0c059844 */
if(!s->budget--) { s->failed_pc=0x0c059844u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059846;
P_0c059846: /* original 2fb6, guest PC 0x0c059846 */
if(!s->budget--) { s->failed_pc=0x0c059846u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059848;
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c059896;
P_0c059896: /* original 2fe6, guest PC 0x0c059896 */
if(!s->budget--) { s->failed_pc=0x0c059896u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059898;
P_0c059898: /* original 2fd6, guest PC 0x0c059898 */
if(!s->budget--) { s->failed_pc=0x0c059898u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989a;
P_0c05989a: /* original 6e43, guest PC 0x0c05989a */
if(!s->budget--) { s->failed_pc=0x0c05989au; return 0; }
r[14]=r[4];
goto P_0c05989c;
P_0c05989c: /* original 2fc6, guest PC 0x0c05989c */
if(!s->budget--) { s->failed_pc=0x0c05989cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989e;
P_0c05989e: /* original 2ee8, guest PC 0x0c05989e */
if(!s->budget--) { s->failed_pc=0x0c05989eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0598a0;
P_0c0598a0: /* original 2fb6, guest PC 0x0c0598a0 */
if(!s->budget--) { s->failed_pc=0x0c0598a0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a2;
P_0c0598a2: /* original 6c53, guest PC 0x0c0598a2 */
if(!s->budget--) { s->failed_pc=0x0c0598a2u; return 0; }
r[12]=r[5];
goto P_0c0598a4;
P_0c0598a4: /* original 2fa6, guest PC 0x0c0598a4 */
if(!s->budget--) { s->failed_pc=0x0c0598a4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a6;
P_0c0598a6: /* original 6b63, guest PC 0x0c0598a6 */
if(!s->budget--) { s->failed_pc=0x0c0598a6u; return 0; }
r[11]=r[6];
goto P_0c0598a8;
P_0c0598a8: /* original 4f22, guest PC 0x0c0598a8 */
if(!s->budget--) { s->failed_pc=0x0c0598a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0598aa;
P_0c0598aa: /* original 7ffc, guest PC 0x0c0598aa */
if(!s->budget--) { s->failed_pc=0x0c0598aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0598ac;
P_0c0598ac: /* original 2f72, guest PC 0x0c0598ac */
if(!s->budget--) { s->failed_pc=0x0c0598acu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0598ae;
P_0c0598ae: /* original 8d02, guest PC 0x0c0598ae */
if(!s->budget--) { s->failed_pc=0x0c0598aeu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c0598b6; }
goto P_0c0598b2;
P_0c0598b0: /* original ea00, guest PC 0x0c0598b0 */
if(!s->budget--) { s->failed_pc=0x0c0598b0u; return 0; }
r[10]=0x00000000u;
goto P_0c0598b2;
P_0c0598b2: /* original 2cc8, guest PC 0x0c0598b2 */
if(!s->budget--) { s->failed_pc=0x0c0598b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0598b4;
P_0c0598b4: /* original 8b01, guest PC 0x0c0598b4 */
if(!s->budget--) { s->failed_pc=0x0c0598b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0598ba; }
goto P_0c0598b6;
P_0c0598b6: /* original a08a, guest PC 0x0c0598b6 */
if(!s->budget--) { s->failed_pc=0x0c0598b6u; return 0; }
r[0]=0x0000000eu;
goto P_0c0599ce;
P_0c0598b8: /* original e00e, guest PC 0x0c0598b8 */
if(!s->budget--) { s->failed_pc=0x0c0598b8u; return 0; }
r[0]=0x0000000eu;
goto P_0c0598ba;
P_0c0598ba: /* original e040, guest PC 0x0c0598ba */
if(!s->budget--) { s->failed_pc=0x0c0598bau; return 0; }
r[0]=0x00000040u;
goto P_0c0598bc;
P_0c0598bc: /* original d216, guest PC 0x0c0598bc */
if(!s->budget--) { s->failed_pc=0x0c0598bcu; return 0; }
r[2]=read(ram,0x0c059918u,4);
goto P_0c0598be;
P_0c0598be: /* original dd14, guest PC 0x0c0598be */
if(!s->budget--) { s->failed_pc=0x0c0598beu; return 0; }
r[13]=read(ram,0x0c059910u,4);
goto P_0c0598c0;
P_0c0598c0: /* original 1def, guest PC 0x0c0598c0 */
if(!s->budget--) { s->failed_pc=0x0c0598c0u; return 0; }
write(ram,r[13]+60,r[14],4);
goto P_0c0598c2;
P_0c0598c2: /* original 0dc6, guest PC 0x0c0598c2 */
if(!s->budget--) { s->failed_pc=0x0c0598c2u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c0598c4;
P_0c0598c4: /* original 63f2, guest PC 0x0c0598c4 */
if(!s->budget--) { s->failed_pc=0x0c0598c4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0598c6;
P_0c0598c6: /* original e044, guest PC 0x0c0598c6 */
if(!s->budget--) { s->failed_pc=0x0c0598c6u; return 0; }
r[0]=0x00000044u;
goto P_0c0598c8;
P_0c0598c8: /* original 0d36, guest PC 0x0c0598c8 */
if(!s->budget--) { s->failed_pc=0x0c0598c8u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0598ca;
P_0c0598ca: /* original 1db6, guest PC 0x0c0598ca */
if(!s->budget--) { s->failed_pc=0x0c0598cau; return 0; }
write(ram,r[13]+24,r[11],4);
goto P_0c0598cc;
P_0c0598cc: /* original d311, guest PC 0x0c0598cc */
if(!s->budget--) { s->failed_pc=0x0c0598ccu; return 0; }
r[3]=read(ram,0x0c059914u,4);
goto P_0c0598ce;
P_0c0598ce: /* original 420b, guest PC 0x0c0598ce */
if(!s->budget--) { s->failed_pc=0x0c0598ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c0598d2u;
write(ram,r[3],r[11],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0598d2u) { target=s->pc; goto dispatch; }
goto P_0c0598d2;
P_0c0598d0: /* original 23b2, guest PC 0x0c0598d0 */
if(!s->budget--) { s->failed_pc=0x0c0598d0u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c0598d2;
P_0c0598d2: /* original d112, guest PC 0x0c0598d2 */
if(!s->budget--) { s->failed_pc=0x0c0598d2u; return 0; }
r[1]=read(ram,0x0c05991cu,4);
goto P_0c0598d4;
P_0c0598d4: /* original 3010, guest PC 0x0c0598d4 */
if(!s->budget--) { s->failed_pc=0x0c0598d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0598d6;
P_0c0598d6: /* original 8b68, guest PC 0x0c0598d6 */
if(!s->budget--) { s->failed_pc=0x0c0598d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599aa; }
goto P_0c0598d8;
P_0c0598d8: /* original 52c6, guest PC 0x0c0598d8 */
if(!s->budget--) { s->failed_pc=0x0c0598d8u; return 0; }
r[2]=read(ram,r[12]+24,4);
goto P_0c0598da;
P_0c0598da: /* original 53e6, guest PC 0x0c0598da */
if(!s->budget--) { s->failed_pc=0x0c0598dau; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0598dc;
P_0c0598dc: /* original 3320, guest PC 0x0c0598dc */
if(!s->budget--) { s->failed_pc=0x0c0598dcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0598de;
P_0c0598de: /* original 8901, guest PC 0x0c0598de */
if(!s->budget--) { s->failed_pc=0x0c0598deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0598e4; }
goto P_0c0598e0;
P_0c0598e0: /* original a075, guest PC 0x0c0598e0 */
if(!s->budget--) { s->failed_pc=0x0c0598e0u; return 0; }
r[0]=0x0000000fu;
goto P_0c0599ce;
P_0c0598e2: /* original e00f, guest PC 0x0c0598e2 */
if(!s->budget--) { s->failed_pc=0x0c0598e2u; return 0; }
r[0]=0x0000000fu;
goto P_0c0598e4;
P_0c0598e4: /* original 53c5, guest PC 0x0c0598e4 */
if(!s->budget--) { s->failed_pc=0x0c0598e4u; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c0598e6;
P_0c0598e6: /* original 52e5, guest PC 0x0c0598e6 */
if(!s->budget--) { s->failed_pc=0x0c0598e6u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0598e8;
P_0c0598e8: /* original 3230, guest PC 0x0c0598e8 */
if(!s->budget--) { s->failed_pc=0x0c0598e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0598ea;
P_0c0598ea: /* original 8919, guest PC 0x0c0598ea */
if(!s->budget--) { s->failed_pc=0x0c0598eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059920; }
goto P_0c0598ec;
P_0c0598ec: /* original a06f, guest PC 0x0c0598ec */
if(!s->budget--) { s->failed_pc=0x0c0598ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0599ce;
P_0c0598ee: /* original e010, guest PC 0x0c0598ee */
if(!s->budget--) { s->failed_pc=0x0c0598eeu; return 0; }
r[0]=0x00000010u;
if(!vf3_matrix_family(0x0c0598f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0598f0u; return 0; } return 1;
P_0c059920: /* original d330, guest PC 0x0c059920 */
if(!s->budget--) { s->failed_pc=0x0c059920u; return 0; }
r[3]=read(ram,0x0c0599e4u,4);
goto P_0c059922;
P_0c059922: /* original 52e7, guest PC 0x0c059922 */
if(!s->budget--) { s->failed_pc=0x0c059922u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c059924;
P_0c059924: /* original 2322, guest PC 0x0c059924 */
if(!s->budget--) { s->failed_pc=0x0c059924u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059926;
P_0c059926: /* original e200, guest PC 0x0c059926 */
if(!s->budget--) { s->failed_pc=0x0c059926u; return 0; }
r[2]=0x00000000u;
goto P_0c059928;
P_0c059928: /* original d12f, guest PC 0x0c059928 */
if(!s->budget--) { s->failed_pc=0x0c059928u; return 0; }
r[1]=read(ram,0x0c0599e8u,4);
goto P_0c05992a;
P_0c05992a: /* original 2122, guest PC 0x0c05992a */
if(!s->budget--) { s->failed_pc=0x0c05992au; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05992c;
P_0c05992c: /* original d02f, guest PC 0x0c05992c */
if(!s->budget--) { s->failed_pc=0x0c05992cu; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c05992e;
P_0c05992e: /* original 53c7, guest PC 0x0c05992e */
if(!s->budget--) { s->failed_pc=0x0c05992eu; return 0; }
r[3]=read(ram,r[12]+28,4);
goto P_0c059930;
P_0c059930: /* original 2032, guest PC 0x0c059930 */
if(!s->budget--) { s->failed_pc=0x0c059930u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059932;
P_0c059932: /* original e300, guest PC 0x0c059932 */
if(!s->budget--) { s->failed_pc=0x0c059932u; return 0; }
r[3]=0x00000000u;
goto P_0c059934;
P_0c059934: /* original d22e, guest PC 0x0c059934 */
if(!s->budget--) { s->failed_pc=0x0c059934u; return 0; }
r[2]=read(ram,0x0c0599f0u,4);
goto P_0c059936;
P_0c059936: /* original 2232, guest PC 0x0c059936 */
if(!s->budget--) { s->failed_pc=0x0c059936u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c059938;
P_0c059938: /* original de2e, guest PC 0x0c059938 */
if(!s->budget--) { s->failed_pc=0x0c059938u; return 0; }
r[14]=read(ram,0x0c0599f4u,4);
goto P_0c05993a;
P_0c05993a: /* original 7194, guest PC 0x0c05993a */
if(!s->budget--) { s->failed_pc=0x0c05993au; return 0; }
r[1]+=0xffffff94u;
goto P_0c05993c;
P_0c05993c: /* original 6512, guest PC 0x0c05993c */
if(!s->budget--) { s->failed_pc=0x0c05993cu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05993e;
P_0c05993e: /* original 4e0b, guest PC 0x0c05993e */
if(!s->budget--) { s->failed_pc=0x0c05993eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059942u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059942u) { target=s->pc; goto dispatch; }
goto P_0c059942;
P_0c059940: /* original e450, guest PC 0x0c059940 */
if(!s->budget--) { s->failed_pc=0x0c059940u; return 0; }
r[4]=0x00000050u;
goto P_0c059942;
P_0c059942: /* original d32d, guest PC 0x0c059942 */
if(!s->budget--) { s->failed_pc=0x0c059942u; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c059944;
P_0c059944: /* original 6532, guest PC 0x0c059944 */
if(!s->budget--) { s->failed_pc=0x0c059944u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059946;
P_0c059946: /* original 4e0b, guest PC 0x0c059946 */
if(!s->budget--) { s->failed_pc=0x0c059946u; return 0; }
target=r[14];
r[16]=code_base|0x0c05994au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05994au) { target=s->pc; goto dispatch; }
goto P_0c05994a;
P_0c059948: /* original e454, guest PC 0x0c059948 */
if(!s->budget--) { s->failed_pc=0x0c059948u; return 0; }
r[4]=0x00000054u;
goto P_0c05994a;
P_0c05994a: /* original d526, guest PC 0x0c05994a */
if(!s->budget--) { s->failed_pc=0x0c05994au; return 0; }
r[5]=read(ram,0x0c0599e4u,4);
goto P_0c05994c;
P_0c05994c: /* original 6552, guest PC 0x0c05994c */
if(!s->budget--) { s->failed_pc=0x0c05994cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05994e;
P_0c05994e: /* original 4e0b, guest PC 0x0c05994e */
if(!s->budget--) { s->failed_pc=0x0c05994eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059952u;
r[4]=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059952u) { target=s->pc; goto dispatch; }
goto P_0c059952;
P_0c059950: /* original e460, guest PC 0x0c059950 */
if(!s->budget--) { s->failed_pc=0x0c059950u; return 0; }
r[4]=0x00000060u;
goto P_0c059952;
P_0c059952: /* original d526, guest PC 0x0c059952 */
if(!s->budget--) { s->failed_pc=0x0c059952u; return 0; }
r[5]=read(ram,0x0c0599ecu,4);
goto P_0c059954;
P_0c059954: /* original 6552, guest PC 0x0c059954 */
if(!s->budget--) { s->failed_pc=0x0c059954u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c059956;
P_0c059956: /* original 4e0b, guest PC 0x0c059956 */
if(!s->budget--) { s->failed_pc=0x0c059956u; return 0; }
target=r[14];
r[16]=code_base|0x0c05995au;
r[4]=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05995au) { target=s->pc; goto dispatch; }
goto P_0c05995a;
P_0c059958: /* original e464, guest PC 0x0c059958 */
if(!s->budget--) { s->failed_pc=0x0c059958u; return 0; }
r[4]=0x00000064u;
goto P_0c05995a;
P_0c05995a: /* original d222, guest PC 0x0c05995a */
if(!s->budget--) { s->failed_pc=0x0c05995au; return 0; }
r[2]=read(ram,0x0c0599e4u,4);
goto P_0c05995c;
P_0c05995c: /* original 6322, guest PC 0x0c05995c */
if(!s->budget--) { s->failed_pc=0x0c05995cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05995e;
P_0c05995e: /* original d126, guest PC 0x0c05995e */
if(!s->budget--) { s->failed_pc=0x0c05995eu; return 0; }
r[1]=read(ram,0x0c0599f8u,4);
goto P_0c059960;
P_0c059960: /* original 2132, guest PC 0x0c059960 */
if(!s->budget--) { s->failed_pc=0x0c059960u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059962;
P_0c059962: /* original d022, guest PC 0x0c059962 */
if(!s->budget--) { s->failed_pc=0x0c059962u; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c059964;
P_0c059964: /* original 6302, guest PC 0x0c059964 */
if(!s->budget--) { s->failed_pc=0x0c059964u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059966;
P_0c059966: /* original 72a0, guest PC 0x0c059966 */
if(!s->budget--) { s->failed_pc=0x0c059966u; return 0; }
r[2]+=0xffffffa0u;
goto P_0c059968;
P_0c059968: /* original 2232, guest PC 0x0c059968 */
if(!s->budget--) { s->failed_pc=0x0c059968u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05996a;
P_0c05996a: /* original 60b3, guest PC 0x0c05996a */
if(!s->budget--) { s->failed_pc=0x0c05996au; return 0; }
r[0]=r[11];
goto P_0c05996c;
P_0c05996c: /* original 0009, guest PC 0x0c05996c */
if(!s->budget--) { s->failed_pc=0x0c05996cu; return 0; }
goto P_0c05996e;
P_0c05996e: /* original 8801, guest PC 0x0c05996e */
if(!s->budget--) { s->failed_pc=0x0c05996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059970;
P_0c059970: /* original 8b0b, guest PC 0x0c059970 */
if(!s->budget--) { s->failed_pc=0x0c059970u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05998a; }
goto P_0c059972;
P_0c059972: /* original e400, guest PC 0x0c059972 */
if(!s->budget--) { s->failed_pc=0x0c059972u; return 0; }
r[4]=0x00000000u;
goto P_0c059974;
P_0c059974: /* original d121, guest PC 0x0c059974 */
if(!s->budget--) { s->failed_pc=0x0c059974u; return 0; }
r[1]=read(ram,0x0c0599fcu,4);
goto P_0c059976;
P_0c059976: /* original 2142, guest PC 0x0c059976 */
if(!s->budget--) { s->failed_pc=0x0c059976u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c059978;
P_0c059978: /* original d321, guest PC 0x0c059978 */
if(!s->budget--) { s->failed_pc=0x0c059978u; return 0; }
r[3]=read(ram,0x0c059a00u,4);
goto P_0c05997a;
P_0c05997a: /* original 2342, guest PC 0x0c05997a */
if(!s->budget--) { s->failed_pc=0x0c05997au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05997c;
P_0c05997c: /* original d21e, guest PC 0x0c05997c */
if(!s->budget--) { s->failed_pc=0x0c05997cu; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c05997e;
P_0c05997e: /* original 6522, guest PC 0x0c05997e */
if(!s->budget--) { s->failed_pc=0x0c05997eu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059980;
P_0c059980: /* original 4e0b, guest PC 0x0c059980 */
if(!s->budget--) { s->failed_pc=0x0c059980u; return 0; }
target=r[14];
r[16]=code_base|0x0c059984u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059984u) { target=s->pc; goto dispatch; }
goto P_0c059984;
P_0c059982: /* original e450, guest PC 0x0c059982 */
if(!s->budget--) { s->failed_pc=0x0c059982u; return 0; }
r[4]=0x00000050u;
goto P_0c059984;
P_0c059984: /* original d31f, guest PC 0x0c059984 */
if(!s->budget--) { s->failed_pc=0x0c059984u; return 0; }
r[3]=read(ram,0x0c059a04u,4);
goto P_0c059986;
P_0c059986: /* original a006, guest PC 0x0c059986 */
if(!s->budget--) { s->failed_pc=0x0c059986u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059996;
P_0c059988: /* original 6532, guest PC 0x0c059988 */
if(!s->budget--) { s->failed_pc=0x0c059988u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998a;
P_0c05998a: /* original d31b, guest PC 0x0c05998a */
if(!s->budget--) { s->failed_pc=0x0c05998au; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c05998c;
P_0c05998c: /* original 6532, guest PC 0x0c05998c */
if(!s->budget--) { s->failed_pc=0x0c05998cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998e;
P_0c05998e: /* original 4e0b, guest PC 0x0c05998e */
if(!s->budget--) { s->failed_pc=0x0c05998eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059992u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059992u) { target=s->pc; goto dispatch; }
goto P_0c059992;
P_0c059990: /* original e450, guest PC 0x0c059990 */
if(!s->budget--) { s->failed_pc=0x0c059990u; return 0; }
r[4]=0x00000050u;
goto P_0c059992;
P_0c059992: /* original d219, guest PC 0x0c059992 */
if(!s->budget--) { s->failed_pc=0x0c059992u; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c059994;
P_0c059994: /* original 6522, guest PC 0x0c059994 */
if(!s->budget--) { s->failed_pc=0x0c059994u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059996;
P_0c059996: /* original 4e0b, guest PC 0x0c059996 */
if(!s->budget--) { s->failed_pc=0x0c059996u; return 0; }
target=r[14];
r[16]=code_base|0x0c05999au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05999au) { target=s->pc; goto dispatch; }
goto P_0c05999a;
P_0c059998: /* original e454, guest PC 0x0c059998 */
if(!s->budget--) { s->failed_pc=0x0c059998u; return 0; }
r[4]=0x00000054u;
goto P_0c05999a;
P_0c05999a: /* original e301, guest PC 0x0c05999a */
if(!s->budget--) { s->failed_pc=0x0c05999au; return 0; }
r[3]=0x00000001u;
goto P_0c05999c;
P_0c05999c: /* original d21a, guest PC 0x0c05999c */
if(!s->budget--) { s->failed_pc=0x0c05999cu; return 0; }
r[2]=read(ram,0x0c059a08u,4);
goto P_0c05999e;
P_0c05999e: /* original 2232, guest PC 0x0c05999e */
if(!s->budget--) { s->failed_pc=0x0c05999eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0599a0;
P_0c0599a0: /* original 61f2, guest PC 0x0c0599a0 */
if(!s->budget--) { s->failed_pc=0x0c0599a0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0599a2;
P_0c0599a2: /* original d31a, guest PC 0x0c0599a2 */
if(!s->budget--) { s->failed_pc=0x0c0599a2u; return 0; }
r[3]=read(ram,0x0c059a0cu,4);
goto P_0c0599a4;
P_0c0599a4: /* original 2312, guest PC 0x0c0599a4 */
if(!s->budget--) { s->failed_pc=0x0c0599a4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0599a6;
P_0c0599a6: /* original a010, guest PC 0x0c0599a6 */
if(!s->budget--) { s->failed_pc=0x0c0599a6u; return 0; }
goto P_0c0599ca;
P_0c0599a8: /* original 0009, guest PC 0x0c0599a8 */
if(!s->budget--) { s->failed_pc=0x0c0599a8u; return 0; }
goto P_0c0599aa;
P_0c0599aa: /* original 9418, guest PC 0x0c0599aa */
if(!s->budget--) { s->failed_pc=0x0c0599aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599deu,2);
goto P_0c0599ac;
P_0c0599ac: /* original d318, guest PC 0x0c0599ac */
if(!s->budget--) { s->failed_pc=0x0c0599acu; return 0; }
r[3]=read(ram,0x0c059a10u,4);
goto P_0c0599ae;
P_0c0599ae: /* original 430b, guest PC 0x0c0599ae */
if(!s->budget--) { s->failed_pc=0x0c0599aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0599b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599b2u) { target=s->pc; goto dispatch; }
goto P_0c0599b2;
P_0c0599b0: /* original 0009, guest PC 0x0c0599b0 */
if(!s->budget--) { s->failed_pc=0x0c0599b0u; return 0; }
goto P_0c0599b2;
P_0c0599b2: /* original 9215, guest PC 0x0c0599b2 */
if(!s->budget--) { s->failed_pc=0x0c0599b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599e0u,2);
goto P_0c0599b4;
P_0c0599b4: /* original 3020, guest PC 0x0c0599b4 */
if(!s->budget--) { s->failed_pc=0x0c0599b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c0599b6;
P_0c0599b6: /* original 8b08, guest PC 0x0c0599b6 */
if(!s->budget--) { s->failed_pc=0x0c0599b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599ca; }
goto P_0c0599b8;
P_0c0599b8: /* original d416, guest PC 0x0c0599b8 */
if(!s->budget--) { s->failed_pc=0x0c0599b8u; return 0; }
r[4]=read(ram,0x0c059a14u,4);
goto P_0c0599ba;
P_0c0599ba: /* original d117, guest PC 0x0c0599ba */
if(!s->budget--) { s->failed_pc=0x0c0599bau; return 0; }
r[1]=read(ram,0x0c059a18u,4);
goto P_0c0599bc;
P_0c0599bc: /* original 410b, guest PC 0x0c0599bc */
if(!s->budget--) { s->failed_pc=0x0c0599bcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0599c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c0u) { target=s->pc; goto dispatch; }
goto P_0c0599c0;
P_0c0599be: /* original 0009, guest PC 0x0c0599be */
if(!s->budget--) { s->failed_pc=0x0c0599beu; return 0; }
goto P_0c0599c0;
P_0c0599c0: /* original d316, guest PC 0x0c0599c0 */
if(!s->budget--) { s->failed_pc=0x0c0599c0u; return 0; }
r[3]=read(ram,0x0c059a1cu,4);
goto P_0c0599c2;
P_0c0599c2: /* original e054, guest PC 0x0c0599c2 */
if(!s->budget--) { s->failed_pc=0x0c0599c2u; return 0; }
r[0]=0x00000054u;
goto P_0c0599c4;
P_0c0599c4: /* original 430b, guest PC 0x0c0599c4 */
if(!s->budget--) { s->failed_pc=0x0c0599c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0599c8u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c8u) { target=s->pc; goto dispatch; }
goto P_0c0599c8;
P_0c0599c6: /* original 04de, guest PC 0x0c0599c6 */
if(!s->budget--) { s->failed_pc=0x0c0599c6u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0599c8;
P_0c0599c8: /* original 6a03, guest PC 0x0c0599c8 */
if(!s->budget--) { s->failed_pc=0x0c0599c8u; return 0; }
r[10]=r[0];
goto P_0c0599ca;
P_0c0599ca: /* original 60a3, guest PC 0x0c0599ca */
if(!s->budget--) { s->failed_pc=0x0c0599cau; return 0; }
r[0]=r[10];
goto P_0c0599cc;
P_0c0599cc: /* original 0009, guest PC 0x0c0599cc */
if(!s->budget--) { s->failed_pc=0x0c0599ccu; return 0; }
goto P_0c0599ce;
P_0c0599ce: /* original 7f04, guest PC 0x0c0599ce */
if(!s->budget--) { s->failed_pc=0x0c0599ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0599d0;
P_0c0599d0: /* original 4f26, guest PC 0x0c0599d0 */
if(!s->budget--) { s->failed_pc=0x0c0599d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0599d2;
P_0c0599d2: /* original 6af6, guest PC 0x0c0599d2 */
if(!s->budget--) { s->failed_pc=0x0c0599d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0599d4;
P_0c0599d4: /* original 6bf6, guest PC 0x0c0599d4 */
if(!s->budget--) { s->failed_pc=0x0c0599d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0599d6;
P_0c0599d6: /* original 6cf6, guest PC 0x0c0599d6 */
if(!s->budget--) { s->failed_pc=0x0c0599d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0599d8;
P_0c0599d8: /* original 6df6, guest PC 0x0c0599d8 */
if(!s->budget--) { s->failed_pc=0x0c0599d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0599da;
P_0c0599da: /* original 000b, guest PC 0x0c0599da */
if(!s->budget--) { s->failed_pc=0x0c0599dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0599dc: /* original 6ef6, guest PC 0x0c0599dc */
if(!s->budget--) { s->failed_pc=0x0c0599dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0599deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0599deu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
