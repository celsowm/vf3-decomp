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
int vf3_away_batch14_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
default: return vf3_matrix_family(target,s,ram);
}
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
r[16]=code_base|0x0c0877beu;
vf3_matrix_store(s,ram,7,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0877beu) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0877c4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0877c4u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0877cau;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0877cau) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c0877d0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0877d0u) { target=s->pc; goto dispatch; }
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
r[0]=code_base|0x000878d0u;
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
r[0]=code_base|0x000878d4u;
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
r[0]=code_base|0x000878d8u;
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
target=code_base|0x0c087638u; r[16]=code_base|0x0c087836u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087836u) { target=s->pc; goto dispatch; }
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
target=code_base|0x0c0875f0u; r[16]=code_base|0x0c087854u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087854u) { target=s->pc; goto dispatch; }
goto P_0c087854;
P_0c087852: /* original 7440, guest PC 0x0c087852 */
if(!s->budget--) { s->failed_pc=0x0c087852u; return 0; }
r[4]+=0x00000040u;
goto P_0c087854;
P_0c087854: /* original c721, guest PC 0x0c087854 */
if(!s->budget--) { s->failed_pc=0x0c087854u; return 0; }
r[0]=code_base|0x000878dcu;
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
r[16]=code_base|0x0c087870u;
write(ram,r[15]+16,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087870u) { target=s->pc; goto dispatch; }
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
r[16]=code_base|0x0c087878u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087878u) { target=s->pc; goto dispatch; }
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
target=code_base|0x0c0875f0u; r[16]=code_base|0x0c087894u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087894u) { target=s->pc; goto dispatch; }
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
target=code_base|0x0c0875f0u; r[16]=code_base|0x0c0878a4u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0878a4u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0875f0u,s,ram);
P_0c0878c2: /* original 6ef6, guest PC 0x0c0878c2 */
if(!s->budget--) { s->failed_pc=0x0c0878c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0878c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0878c4u; return 0; } return 1;
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
r[0]=code_base|0x00087a30u;
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
r[0]=code_base|0x00087a34u;
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
unsupported: s->failed_pc=target; return 0;
}
