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
int vf3_away_batch11_adapter_31(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0747d8u: goto P_0c0747d8;
case 0x0c0747dau: goto P_0c0747da;
case 0x0c0747dcu: goto P_0c0747dc;
case 0x0c0747deu: goto P_0c0747de;
case 0x0c0747e0u: goto P_0c0747e0;
case 0x0c0747e2u: goto P_0c0747e2;
case 0x0c0747e4u: goto P_0c0747e4;
case 0x0c0747e6u: goto P_0c0747e6;
case 0x0c0747e8u: goto P_0c0747e8;
case 0x0c0747eau: goto P_0c0747ea;
case 0x0c0747ecu: goto P_0c0747ec;
case 0x0c0747eeu: goto P_0c0747ee;
case 0x0c0747f0u: goto P_0c0747f0;
case 0x0c0747f2u: goto P_0c0747f2;
case 0x0c0747f4u: goto P_0c0747f4;
case 0x0c0747f6u: goto P_0c0747f6;
case 0x0c0747f8u: goto P_0c0747f8;
case 0x0c0747fau: goto P_0c0747fa;
case 0x0c0747fcu: goto P_0c0747fc;
case 0x0c0747feu: goto P_0c0747fe;
case 0x0c074800u: goto P_0c074800;
case 0x0c074802u: goto P_0c074802;
case 0x0c074804u: goto P_0c074804;
case 0x0c074806u: goto P_0c074806;
case 0x0c074808u: goto P_0c074808;
case 0x0c07480au: goto P_0c07480a;
case 0x0c07480cu: goto P_0c07480c;
case 0x0c07480eu: goto P_0c07480e;
case 0x0c074810u: goto P_0c074810;
case 0x0c074812u: goto P_0c074812;
case 0x0c074814u: goto P_0c074814;
case 0x0c074816u: goto P_0c074816;
case 0x0c074818u: goto P_0c074818;
case 0x0c07481au: goto P_0c07481a;
case 0x0c07481cu: goto P_0c07481c;
case 0x0c07481eu: goto P_0c07481e;
case 0x0c074820u: goto P_0c074820;
case 0x0c074822u: goto P_0c074822;
case 0x0c074824u: goto P_0c074824;
case 0x0c074826u: goto P_0c074826;
case 0x0c074828u: goto P_0c074828;
case 0x0c07482au: goto P_0c07482a;
case 0x0c07482cu: goto P_0c07482c;
case 0x0c07482eu: goto P_0c07482e;
case 0x0c074830u: goto P_0c074830;
case 0x0c074832u: goto P_0c074832;
case 0x0c074834u: goto P_0c074834;
case 0x0c074836u: goto P_0c074836;
case 0x0c074838u: goto P_0c074838;
case 0x0c07483au: goto P_0c07483a;
case 0x0c07483cu: goto P_0c07483c;
case 0x0c07483eu: goto P_0c07483e;
case 0x0c074840u: goto P_0c074840;
case 0x0c074842u: goto P_0c074842;
case 0x0c074844u: goto P_0c074844;
case 0x0c074846u: goto P_0c074846;
case 0x0c074848u: goto P_0c074848;
case 0x0c07484au: goto P_0c07484a;
case 0x0c07484cu: goto P_0c07484c;
case 0x0c07484eu: goto P_0c07484e;
case 0x0c074850u: goto P_0c074850;
case 0x0c074852u: goto P_0c074852;
case 0x0c074854u: goto P_0c074854;
case 0x0c074856u: goto P_0c074856;
case 0x0c074858u: goto P_0c074858;
case 0x0c07485au: goto P_0c07485a;
case 0x0c07485cu: goto P_0c07485c;
case 0x0c07485eu: goto P_0c07485e;
case 0x0c074860u: goto P_0c074860;
case 0x0c074862u: goto P_0c074862;
case 0x0c074864u: goto P_0c074864;
case 0x0c074866u: goto P_0c074866;
case 0x0c074868u: goto P_0c074868;
case 0x0c07486au: goto P_0c07486a;
case 0x0c07486cu: goto P_0c07486c;
case 0x0c07486eu: goto P_0c07486e;
case 0x0c074870u: goto P_0c074870;
case 0x0c074872u: goto P_0c074872;
case 0x0c074874u: goto P_0c074874;
case 0x0c074876u: goto P_0c074876;
case 0x0c074878u: goto P_0c074878;
case 0x0c07487au: goto P_0c07487a;
case 0x0c07487cu: goto P_0c07487c;
case 0x0c07487eu: goto P_0c07487e;
case 0x0c074880u: goto P_0c074880;
case 0x0c074882u: goto P_0c074882;
case 0x0c074884u: goto P_0c074884;
case 0x0c074886u: goto P_0c074886;
case 0x0c074888u: goto P_0c074888;
case 0x0c07488au: goto P_0c07488a;
case 0x0c07488cu: goto P_0c07488c;
case 0x0c07488eu: goto P_0c07488e;
case 0x0c074890u: goto P_0c074890;
case 0x0c074892u: goto P_0c074892;
case 0x0c074894u: goto P_0c074894;
case 0x0c074896u: goto P_0c074896;
case 0x0c074898u: goto P_0c074898;
case 0x0c07489au: goto P_0c07489a;
case 0x0c07489cu: goto P_0c07489c;
case 0x0c07489eu: goto P_0c07489e;
case 0x0c0748a0u: goto P_0c0748a0;
case 0x0c0748a2u: goto P_0c0748a2;
case 0x0c0748a4u: goto P_0c0748a4;
case 0x0c0748a6u: goto P_0c0748a6;
case 0x0c0748c0u: goto P_0c0748c0;
case 0x0c0748c2u: goto P_0c0748c2;
case 0x0c0748c4u: goto P_0c0748c4;
case 0x0c0748c6u: goto P_0c0748c6;
case 0x0c0748c8u: goto P_0c0748c8;
case 0x0c0748cau: goto P_0c0748ca;
case 0x0c0748ccu: goto P_0c0748cc;
case 0x0c0748ceu: goto P_0c0748ce;
case 0x0c0748d0u: goto P_0c0748d0;
case 0x0c0748d2u: goto P_0c0748d2;
case 0x0c0748d4u: goto P_0c0748d4;
case 0x0c0748d6u: goto P_0c0748d6;
case 0x0c0748d8u: goto P_0c0748d8;
case 0x0c0748dau: goto P_0c0748da;
case 0x0c0748dcu: goto P_0c0748dc;
case 0x0c0748deu: goto P_0c0748de;
case 0x0c0748e0u: goto P_0c0748e0;
case 0x0c0748e2u: goto P_0c0748e2;
case 0x0c0748e4u: goto P_0c0748e4;
case 0x0c0748e6u: goto P_0c0748e6;
case 0x0c0748e8u: goto P_0c0748e8;
case 0x0c0748eau: goto P_0c0748ea;
case 0x0c0748ecu: goto P_0c0748ec;
case 0x0c0748eeu: goto P_0c0748ee;
case 0x0c0748f0u: goto P_0c0748f0;
case 0x0c0748f2u: goto P_0c0748f2;
case 0x0c0748f4u: goto P_0c0748f4;
case 0x0c0748f6u: goto P_0c0748f6;
case 0x0c0748f8u: goto P_0c0748f8;
case 0x0c0748fau: goto P_0c0748fa;
case 0x0c0748fcu: goto P_0c0748fc;
case 0x0c0748feu: goto P_0c0748fe;
case 0x0c074900u: goto P_0c074900;
case 0x0c074902u: goto P_0c074902;
case 0x0c074904u: goto P_0c074904;
case 0x0c074906u: goto P_0c074906;
case 0x0c074908u: goto P_0c074908;
case 0x0c07490au: goto P_0c07490a;
case 0x0c07490cu: goto P_0c07490c;
case 0x0c07490eu: goto P_0c07490e;
case 0x0c074910u: goto P_0c074910;
case 0x0c074912u: goto P_0c074912;
case 0x0c074914u: goto P_0c074914;
case 0x0c074916u: goto P_0c074916;
case 0x0c074918u: goto P_0c074918;
case 0x0c07491au: goto P_0c07491a;
case 0x0c07491cu: goto P_0c07491c;
case 0x0c07491eu: goto P_0c07491e;
case 0x0c074920u: goto P_0c074920;
case 0x0c074922u: goto P_0c074922;
case 0x0c074924u: goto P_0c074924;
case 0x0c074926u: goto P_0c074926;
case 0x0c074928u: goto P_0c074928;
case 0x0c07492au: goto P_0c07492a;
case 0x0c07492cu: goto P_0c07492c;
case 0x0c07492eu: goto P_0c07492e;
case 0x0c07a7a8u: goto P_0c07a7a8;
case 0x0c07a7aau: goto P_0c07a7aa;
case 0x0c07a7acu: goto P_0c07a7ac;
case 0x0c07a7aeu: goto P_0c07a7ae;
case 0x0c07a7b0u: goto P_0c07a7b0;
case 0x0c07a7b2u: goto P_0c07a7b2;
case 0x0c07a7b4u: goto P_0c07a7b4;
case 0x0c07a7b6u: goto P_0c07a7b6;
case 0x0c07a7b8u: goto P_0c07a7b8;
case 0x0c07a7bau: goto P_0c07a7ba;
case 0x0c07a7bcu: goto P_0c07a7bc;
case 0x0c07a7beu: goto P_0c07a7be;
case 0x0c07a7c0u: goto P_0c07a7c0;
case 0x0c07a7c2u: goto P_0c07a7c2;
case 0x0c07a7c4u: goto P_0c07a7c4;
case 0x0c07a7c6u: goto P_0c07a7c6;
case 0x0c07a7c8u: goto P_0c07a7c8;
case 0x0c07a7cau: goto P_0c07a7ca;
case 0x0c07a7ccu: goto P_0c07a7cc;
case 0x0c07a7ceu: goto P_0c07a7ce;
case 0x0c07a7d0u: goto P_0c07a7d0;
case 0x0c07a7d2u: goto P_0c07a7d2;
case 0x0c07a7d4u: goto P_0c07a7d4;
case 0x0c07a7d6u: goto P_0c07a7d6;
case 0x0c07a7d8u: goto P_0c07a7d8;
case 0x0c07a7dau: goto P_0c07a7da;
case 0x0c07a7dcu: goto P_0c07a7dc;
case 0x0c07a7deu: goto P_0c07a7de;
case 0x0c07a7e0u: goto P_0c07a7e0;
case 0x0c07a7e2u: goto P_0c07a7e2;
case 0x0c07a7e4u: goto P_0c07a7e4;
case 0x0c07a7e6u: goto P_0c07a7e6;
case 0x0c07a7e8u: goto P_0c07a7e8;
case 0x0c07a7eau: goto P_0c07a7ea;
case 0x0c07a7ecu: goto P_0c07a7ec;
case 0x0c07a7eeu: goto P_0c07a7ee;
case 0x0c07a7f0u: goto P_0c07a7f0;
case 0x0c07a7f2u: goto P_0c07a7f2;
case 0x0c07a7f4u: goto P_0c07a7f4;
case 0x0c07a7f6u: goto P_0c07a7f6;
case 0x0c07a7f8u: goto P_0c07a7f8;
case 0x0c07a7fau: goto P_0c07a7fa;
case 0x0c07a7fcu: goto P_0c07a7fc;
case 0x0c07a7feu: goto P_0c07a7fe;
case 0x0c07a800u: goto P_0c07a800;
case 0x0c07a802u: goto P_0c07a802;
case 0x0c07a804u: goto P_0c07a804;
case 0x0c07a806u: goto P_0c07a806;
case 0x0c07a808u: goto P_0c07a808;
case 0x0c07a80au: goto P_0c07a80a;
case 0x0c07a80cu: goto P_0c07a80c;
case 0x0c07a80eu: goto P_0c07a80e;
case 0x0c07a810u: goto P_0c07a810;
case 0x0c07a812u: goto P_0c07a812;
case 0x0c07a814u: goto P_0c07a814;
case 0x0c07a816u: goto P_0c07a816;
case 0x0c07a818u: goto P_0c07a818;
case 0x0c07a81au: goto P_0c07a81a;
case 0x0c07a81cu: goto P_0c07a81c;
case 0x0c07a81eu: goto P_0c07a81e;
case 0x0c07a820u: goto P_0c07a820;
case 0x0c07a822u: goto P_0c07a822;
case 0x0c07a824u: goto P_0c07a824;
case 0x0c07a826u: goto P_0c07a826;
case 0x0c07a828u: goto P_0c07a828;
case 0x0c07a82au: goto P_0c07a82a;
case 0x0c07a82cu: goto P_0c07a82c;
case 0x0c07a82eu: goto P_0c07a82e;
case 0x0c07a830u: goto P_0c07a830;
case 0x0c07a832u: goto P_0c07a832;
case 0x0c07a834u: goto P_0c07a834;
case 0x0c07a836u: goto P_0c07a836;
case 0x0c07a838u: goto P_0c07a838;
case 0x0c07a83au: goto P_0c07a83a;
case 0x0c07a83cu: goto P_0c07a83c;
case 0x0c07a83eu: goto P_0c07a83e;
case 0x0c07a840u: goto P_0c07a840;
case 0x0c07a842u: goto P_0c07a842;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0747d8: /* original 9169, guest PC 0x0c0747d8 */
if(!s->budget--) { s->failed_pc=0x0c0747d8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748aeu,2);
goto P_0c0747da;
P_0c0747da: /* original e010, guest PC 0x0c0747da */
if(!s->budget--) { s->failed_pc=0x0c0747dau; return 0; }
r[0]=0x00000010u;
goto P_0c0747dc;
P_0c0747dc: /* original f246, guest PC 0x0c0747dc */
if(!s->budget--) { s->failed_pc=0x0c0747dcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0747de;
P_0c0747de: /* original 314c, guest PC 0x0c0747de */
if(!s->budget--) { s->failed_pc=0x0c0747deu; return 0; }
r[1]+=r[4];
goto P_0c0747e0;
P_0c0747e0: /* original f318, guest PC 0x0c0747e0 */
if(!s->budget--) { s->failed_pc=0x0c0747e0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0747e2;
P_0c0747e2: /* original f230, guest PC 0x0c0747e2 */
if(!s->budget--) { s->failed_pc=0x0c0747e2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0747e4;
P_0c0747e4: /* original f427, guest PC 0x0c0747e4 */
if(!s->budget--) { s->failed_pc=0x0c0747e4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0747e6;
P_0c0747e6: /* original e018, guest PC 0x0c0747e6 */
if(!s->budget--) { s->failed_pc=0x0c0747e6u; return 0; }
r[0]=0x00000018u;
goto P_0c0747e8;
P_0c0747e8: /* original 9162, guest PC 0x0c0747e8 */
if(!s->budget--) { s->failed_pc=0x0c0747e8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b0u,2);
goto P_0c0747ea;
P_0c0747ea: /* original f246, guest PC 0x0c0747ea */
if(!s->budget--) { s->failed_pc=0x0c0747eau; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0747ec;
P_0c0747ec: /* original 314c, guest PC 0x0c0747ec */
if(!s->budget--) { s->failed_pc=0x0c0747ecu; return 0; }
r[1]+=r[4];
goto P_0c0747ee;
P_0c0747ee: /* original f318, guest PC 0x0c0747ee */
if(!s->budget--) { s->failed_pc=0x0c0747eeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0747f0;
P_0c0747f0: /* original f230, guest PC 0x0c0747f0 */
if(!s->budget--) { s->failed_pc=0x0c0747f0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0747f2;
P_0c0747f2: /* original f427, guest PC 0x0c0747f2 */
if(!s->budget--) { s->failed_pc=0x0c0747f2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0747f4;
P_0c0747f4: /* original 905d, guest PC 0x0c0747f4 */
if(!s->budget--) { s->failed_pc=0x0c0747f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b2u,2);
goto P_0c0747f6;
P_0c0747f6: /* original f48d, guest PC 0x0c0747f6 */
if(!s->budget--) { s->failed_pc=0x0c0747f6u; return 0; }
fr[4]=0;
goto P_0c0747f8;
P_0c0747f8: /* original f447, guest PC 0x0c0747f8 */
if(!s->budget--) { s->failed_pc=0x0c0747f8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0747fa;
P_0c0747fa: /* original 7008, guest PC 0x0c0747fa */
if(!s->budget--) { s->failed_pc=0x0c0747fau; return 0; }
r[0]+=0x00000008u;
goto P_0c0747fc;
P_0c0747fc: /* original 000b, guest PC 0x0c0747fc */
if(!s->budget--) { s->failed_pc=0x0c0747fcu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0747fe: /* original f447, guest PC 0x0c0747fe */
if(!s->budget--) { s->failed_pc=0x0c0747feu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c074800;
P_0c074800: /* original d12e, guest PC 0x0c074800 */
if(!s->budget--) { s->failed_pc=0x0c074800u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074802;
P_0c074802: /* original d32d, guest PC 0x0c074802 */
if(!s->budget--) { s->failed_pc=0x0c074802u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c074804;
P_0c074804: /* original 6212, guest PC 0x0c074804 */
if(!s->budget--) { s->failed_pc=0x0c074804u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c074806;
P_0c074806: /* original 2238, guest PC 0x0c074806 */
if(!s->budget--) { s->failed_pc=0x0c074806u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074808;
P_0c074808: /* original 8b0f, guest PC 0x0c074808 */
if(!s->budget--) { s->failed_pc=0x0c074808u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07482a; }
goto P_0c07480a;
P_0c07480a: /* original 914d, guest PC 0x0c07480a */
if(!s->budget--) { s->failed_pc=0x0c07480au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07480c;
P_0c07480c: /* original e014, guest PC 0x0c07480c */
if(!s->budget--) { s->failed_pc=0x0c07480cu; return 0; }
r[0]=0x00000014u;
goto P_0c07480e;
P_0c07480e: /* original f246, guest PC 0x0c07480e */
if(!s->budget--) { s->failed_pc=0x0c07480eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074810;
P_0c074810: /* original 314c, guest PC 0x0c074810 */
if(!s->budget--) { s->failed_pc=0x0c074810u; return 0; }
r[1]+=r[4];
goto P_0c074812;
P_0c074812: /* original f318, guest PC 0x0c074812 */
if(!s->budget--) { s->failed_pc=0x0c074812u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074814;
P_0c074814: /* original f230, guest PC 0x0c074814 */
if(!s->budget--) { s->failed_pc=0x0c074814u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074816;
P_0c074816: /* original f427, guest PC 0x0c074816 */
if(!s->budget--) { s->failed_pc=0x0c074816u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074818;
P_0c074818: /* original 9146, guest PC 0x0c074818 */
if(!s->budget--) { s->failed_pc=0x0c074818u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07481a;
P_0c07481a: /* original f256, guest PC 0x0c07481a */
if(!s->budget--) { s->failed_pc=0x0c07481au; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c07481c;
P_0c07481c: /* original 315c, guest PC 0x0c07481c */
if(!s->budget--) { s->failed_pc=0x0c07481cu; return 0; }
r[1]+=r[5];
goto P_0c07481e;
P_0c07481e: /* original f318, guest PC 0x0c07481e */
if(!s->budget--) { s->failed_pc=0x0c07481eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074820;
P_0c074820: /* original f230, guest PC 0x0c074820 */
if(!s->budget--) { s->failed_pc=0x0c074820u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074822;
P_0c074822: /* original f527, guest PC 0x0c074822 */
if(!s->budget--) { s->failed_pc=0x0c074822u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074824;
P_0c074824: /* original 9042, guest PC 0x0c074824 */
if(!s->budget--) { s->failed_pc=0x0c074824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748acu,2);
goto P_0c074826;
P_0c074826: /* original f38d, guest PC 0x0c074826 */
if(!s->budget--) { s->failed_pc=0x0c074826u; return 0; }
fr[3]=0;
goto P_0c074828;
P_0c074828: /* original f437, guest PC 0x0c074828 */
if(!s->budget--) { s->failed_pc=0x0c074828u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07482a;
P_0c07482a: /* original 000b, guest PC 0x0c07482a */
if(!s->budget--) { s->failed_pc=0x0c07482au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07482c: /* original 0009, guest PC 0x0c07482c */
if(!s->budget--) { s->failed_pc=0x0c07482cu; return 0; }
goto P_0c07482e;
P_0c07482e: /* original 4f22, guest PC 0x0c07482e */
if(!s->budget--) { s->failed_pc=0x0c07482eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074830;
P_0c074830: /* original 7ff8, guest PC 0x0c074830 */
if(!s->budget--) { s->failed_pc=0x0c074830u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c074832;
P_0c074832: /* original 2f42, guest PC 0x0c074832 */
if(!s->budget--) { s->failed_pc=0x0c074832u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c074834;
P_0c074834: /* original 1f51, guest PC 0x0c074834 */
if(!s->budget--) { s->failed_pc=0x0c074834u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c074836;
P_0c074836: /* original d121, guest PC 0x0c074836 */
if(!s->budget--) { s->failed_pc=0x0c074836u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074838;
P_0c074838: /* original d31f, guest PC 0x0c074838 */
if(!s->budget--) { s->failed_pc=0x0c074838u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c07483a;
P_0c07483a: /* original 6212, guest PC 0x0c07483a */
if(!s->budget--) { s->failed_pc=0x0c07483au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07483c;
P_0c07483c: /* original 2238, guest PC 0x0c07483c */
if(!s->budget--) { s->failed_pc=0x0c07483cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07483e;
P_0c07483e: /* original 8b05, guest PC 0x0c07483e */
if(!s->budget--) { s->failed_pc=0x0c07483eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07484c; }
goto P_0c074840;
P_0c074840: /* original 55f1, guest PC 0x0c074840 */
if(!s->budget--) { s->failed_pc=0x0c074840u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c074842;
P_0c074842: /* original b007, guest PC 0x0c074842 */
if(!s->budget--) { s->failed_pc=0x0c074842u; return 0; }
target=code_base|0x0c074854u; r[16]=code_base|0x0c074846u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c074846u) { target=s->pc; goto dispatch; }
goto P_0c074846;
P_0c074844: /* original 64f2, guest PC 0x0c074844 */
if(!s->budget--) { s->failed_pc=0x0c074844u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c074846;
P_0c074846: /* original 65f2, guest PC 0x0c074846 */
if(!s->budget--) { s->failed_pc=0x0c074846u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c074848;
P_0c074848: /* original b004, guest PC 0x0c074848 */
if(!s->budget--) { s->failed_pc=0x0c074848u; return 0; }
target=code_base|0x0c074854u; r[16]=code_base|0x0c07484cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07484cu) { target=s->pc; goto dispatch; }
goto P_0c07484c;
P_0c07484a: /* original 54f1, guest PC 0x0c07484a */
if(!s->budget--) { s->failed_pc=0x0c07484au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07484c;
P_0c07484c: /* original 7f08, guest PC 0x0c07484c */
if(!s->budget--) { s->failed_pc=0x0c07484cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07484e;
P_0c07484e: /* original 4f26, guest PC 0x0c07484e */
if(!s->budget--) { s->failed_pc=0x0c07484eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074850;
P_0c074850: /* original 000b, guest PC 0x0c074850 */
if(!s->budget--) { s->failed_pc=0x0c074850u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c074852: /* original 0009, guest PC 0x0c074852 */
if(!s->budget--) { s->failed_pc=0x0c074852u; return 0; }
goto P_0c074854;
P_0c074854: /* original 902d, guest PC 0x0c074854 */
if(!s->budget--) { s->failed_pc=0x0c074854u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b2u,2);
goto P_0c074856;
P_0c074856: /* original 7ff4, guest PC 0x0c074856 */
if(!s->budget--) { s->failed_pc=0x0c074856u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c074858;
P_0c074858: /* original 952c, guest PC 0x0c074858 */
if(!s->budget--) { s->failed_pc=0x0c074858u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b4u,2);
goto P_0c07485a;
P_0c07485a: /* original f446, guest PC 0x0c07485a */
if(!s->budget--) { s->failed_pc=0x0c07485au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c07485c;
P_0c07485c: /* original 7004, guest PC 0x0c07485c */
if(!s->budget--) { s->failed_pc=0x0c07485cu; return 0; }
r[0]+=0x00000004u;
goto P_0c07485e;
P_0c07485e: /* original f546, guest PC 0x0c07485e */
if(!s->budget--) { s->failed_pc=0x0c07485eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c074860;
P_0c074860: /* original 7004, guest PC 0x0c074860 */
if(!s->budget--) { s->failed_pc=0x0c074860u; return 0; }
r[0]+=0x00000004u;
goto P_0c074862;
P_0c074862: /* original f646, guest PC 0x0c074862 */
if(!s->budget--) { s->failed_pc=0x0c074862u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c074864;
P_0c074864: /* original e010, guest PC 0x0c074864 */
if(!s->budget--) { s->failed_pc=0x0c074864u; return 0; }
r[0]=0x00000010u;
goto P_0c074866;
P_0c074866: /* original f346, guest PC 0x0c074866 */
if(!s->budget--) { s->failed_pc=0x0c074866u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074868;
P_0c074868: /* original 354c, guest PC 0x0c074868 */
if(!s->budget--) { s->failed_pc=0x0c074868u; return 0; }
r[5]+=r[4];
goto P_0c07486a;
P_0c07486a: /* original 9624, guest PC 0x0c07486a */
if(!s->budget--) { s->failed_pc=0x0c07486au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b6u,2);
goto P_0c07486c;
P_0c07486c: /* original f340, guest PC 0x0c07486c */
if(!s->budget--) { s->failed_pc=0x0c07486cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07486e;
P_0c07486e: /* original 365c, guest PC 0x0c07486e */
if(!s->budget--) { s->failed_pc=0x0c07486eu; return 0; }
r[6]+=r[5];
goto P_0c074870;
P_0c074870: /* original 3560, guest PC 0x0c074870 */
if(!s->budget--) { s->failed_pc=0x0c074870u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074872;
P_0c074872: /* original f437, guest PC 0x0c074872 */
if(!s->budget--) { s->failed_pc=0x0c074872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074874;
P_0c074874: /* original e014, guest PC 0x0c074874 */
if(!s->budget--) { s->failed_pc=0x0c074874u; return 0; }
r[0]=0x00000014u;
goto P_0c074876;
P_0c074876: /* original f246, guest PC 0x0c074876 */
if(!s->budget--) { s->failed_pc=0x0c074876u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074878;
P_0c074878: /* original f250, guest PC 0x0c074878 */
if(!s->budget--) { s->failed_pc=0x0c074878u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07487a;
P_0c07487a: /* original f427, guest PC 0x0c07487a */
if(!s->budget--) { s->failed_pc=0x0c07487au; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07487c;
P_0c07487c: /* original e018, guest PC 0x0c07487c */
if(!s->budget--) { s->failed_pc=0x0c07487cu; return 0; }
r[0]=0x00000018u;
goto P_0c07487e;
P_0c07487e: /* original f346, guest PC 0x0c07487e */
if(!s->budget--) { s->failed_pc=0x0c07487eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074880;
P_0c074880: /* original f360, guest PC 0x0c074880 */
if(!s->budget--) { s->failed_pc=0x0c074880u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c074882;
P_0c074882: /* original 8d0f, guest PC 0x0c074882 */
if(!s->budget--) { s->failed_pc=0x0c074882u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c0748a4; }
goto P_0c074886;
P_0c074884: /* original f437, guest PC 0x0c074884 */
if(!s->budget--) { s->failed_pc=0x0c074884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074886;
P_0c074886: /* original e030, guest PC 0x0c074886 */
if(!s->budget--) { s->failed_pc=0x0c074886u; return 0; }
r[0]=0x00000030u;
goto P_0c074888;
P_0c074888: /* original f356, guest PC 0x0c074888 */
if(!s->budget--) { s->failed_pc=0x0c074888u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07488a;
P_0c07488a: /* original f340, guest PC 0x0c07488a */
if(!s->budget--) { s->failed_pc=0x0c07488au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07488c;
P_0c07488c: /* original f537, guest PC 0x0c07488c */
if(!s->budget--) { s->failed_pc=0x0c07488cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07488e;
P_0c07488e: /* original e034, guest PC 0x0c07488e */
if(!s->budget--) { s->failed_pc=0x0c07488eu; return 0; }
r[0]=0x00000034u;
goto P_0c074890;
P_0c074890: /* original f256, guest PC 0x0c074890 */
if(!s->budget--) { s->failed_pc=0x0c074890u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c074892;
P_0c074892: /* original f250, guest PC 0x0c074892 */
if(!s->budget--) { s->failed_pc=0x0c074892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074894;
P_0c074894: /* original f527, guest PC 0x0c074894 */
if(!s->budget--) { s->failed_pc=0x0c074894u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074896;
P_0c074896: /* original e038, guest PC 0x0c074896 */
if(!s->budget--) { s->failed_pc=0x0c074896u; return 0; }
r[0]=0x00000038u;
goto P_0c074898;
P_0c074898: /* original f356, guest PC 0x0c074898 */
if(!s->budget--) { s->failed_pc=0x0c074898u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07489a;
P_0c07489a: /* original f360, guest PC 0x0c07489a */
if(!s->budget--) { s->failed_pc=0x0c07489au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c07489c;
P_0c07489c: /* original f537, guest PC 0x0c07489c */
if(!s->budget--) { s->failed_pc=0x0c07489cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07489e;
P_0c07489e: /* original 7540, guest PC 0x0c07489e */
if(!s->budget--) { s->failed_pc=0x0c07489eu; return 0; }
r[5]+=0x00000040u;
goto P_0c0748a0;
P_0c0748a0: /* original 3560, guest PC 0x0c0748a0 */
if(!s->budget--) { s->failed_pc=0x0c0748a0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0748a2;
P_0c0748a2: /* original 8bf0, guest PC 0x0c0748a2 */
if(!s->budget--) { s->failed_pc=0x0c0748a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074886; }
goto P_0c0748a4;
P_0c0748a4: /* original 000b, guest PC 0x0c0748a4 */
if(!s->budget--) { s->failed_pc=0x0c0748a4u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c0748a6: /* original 7f0c, guest PC 0x0c0748a6 */
if(!s->budget--) { s->failed_pc=0x0c0748a6u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c0748a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0748a8u; return 0; } return 1;
P_0c0748c0: /* original 4f22, guest PC 0x0c0748c0 */
if(!s->budget--) { s->failed_pc=0x0c0748c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0748c2;
P_0c0748c2: /* original 7ffc, guest PC 0x0c0748c2 */
if(!s->budget--) { s->failed_pc=0x0c0748c2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0748c4;
P_0c0748c4: /* original 2f52, guest PC 0x0c0748c4 */
if(!s->budget--) { s->failed_pc=0x0c0748c4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0748c6;
P_0c0748c6: /* original d13a, guest PC 0x0c0748c6 */
if(!s->budget--) { s->failed_pc=0x0c0748c6u; return 0; }
r[1]=read(ram,0x0c0749b0u,4);
goto P_0c0748c8;
P_0c0748c8: /* original d338, guest PC 0x0c0748c8 */
if(!s->budget--) { s->failed_pc=0x0c0748c8u; return 0; }
r[3]=read(ram,0x0c0749acu,4);
goto P_0c0748ca;
P_0c0748ca: /* original 6212, guest PC 0x0c0748ca */
if(!s->budget--) { s->failed_pc=0x0c0748cau; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0748cc;
P_0c0748cc: /* original 2238, guest PC 0x0c0748cc */
if(!s->budget--) { s->failed_pc=0x0c0748ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0748ce;
P_0c0748ce: /* original 8b03, guest PC 0x0c0748ce */
if(!s->budget--) { s->failed_pc=0x0c0748ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0748d8; }
goto P_0c0748d0;
P_0c0748d0: /* original b006, guest PC 0x0c0748d0 */
if(!s->budget--) { s->failed_pc=0x0c0748d0u; return 0; }
target=code_base|0x0c0748e0u; r[16]=code_base|0x0c0748d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0748d4u) { target=s->pc; goto dispatch; }
goto P_0c0748d4;
P_0c0748d2: /* original 0009, guest PC 0x0c0748d2 */
if(!s->budget--) { s->failed_pc=0x0c0748d2u; return 0; }
goto P_0c0748d4;
P_0c0748d4: /* original b004, guest PC 0x0c0748d4 */
if(!s->budget--) { s->failed_pc=0x0c0748d4u; return 0; }
target=code_base|0x0c0748e0u; r[16]=code_base|0x0c0748d8u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0748d8u) { target=s->pc; goto dispatch; }
goto P_0c0748d8;
P_0c0748d6: /* original 64f2, guest PC 0x0c0748d6 */
if(!s->budget--) { s->failed_pc=0x0c0748d6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0748d8;
P_0c0748d8: /* original 7f04, guest PC 0x0c0748d8 */
if(!s->budget--) { s->failed_pc=0x0c0748d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0748da;
P_0c0748da: /* original 4f26, guest PC 0x0c0748da */
if(!s->budget--) { s->failed_pc=0x0c0748dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0748dc;
P_0c0748dc: /* original 000b, guest PC 0x0c0748dc */
if(!s->budget--) { s->failed_pc=0x0c0748dcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0748de: /* original 0009, guest PC 0x0c0748de */
if(!s->budget--) { s->failed_pc=0x0c0748deu; return 0; }
goto P_0c0748e0;
P_0c0748e0: /* original 905e, guest PC 0x0c0748e0 */
if(!s->budget--) { s->failed_pc=0x0c0748e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a0u,2);
goto P_0c0748e2;
P_0c0748e2: /* original 965e, guest PC 0x0c0748e2 */
if(!s->budget--) { s->failed_pc=0x0c0748e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a2u,2);
goto P_0c0748e4;
P_0c0748e4: /* original f446, guest PC 0x0c0748e4 */
if(!s->budget--) { s->failed_pc=0x0c0748e4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0748e6;
P_0c0748e6: /* original 7004, guest PC 0x0c0748e6 */
if(!s->budget--) { s->failed_pc=0x0c0748e6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0748e8;
P_0c0748e8: /* original f546, guest PC 0x0c0748e8 */
if(!s->budget--) { s->failed_pc=0x0c0748e8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0748ea;
P_0c0748ea: /* original 7004, guest PC 0x0c0748ea */
if(!s->budget--) { s->failed_pc=0x0c0748eau; return 0; }
r[0]+=0x00000004u;
goto P_0c0748ec;
P_0c0748ec: /* original f646, guest PC 0x0c0748ec */
if(!s->budget--) { s->failed_pc=0x0c0748ecu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0748ee;
P_0c0748ee: /* original 70dc, guest PC 0x0c0748ee */
if(!s->budget--) { s->failed_pc=0x0c0748eeu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c0748f0;
P_0c0748f0: /* original 054e, guest PC 0x0c0748f0 */
if(!s->budget--) { s->failed_pc=0x0c0748f0u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0748f2;
P_0c0748f2: /* original 9057, guest PC 0x0c0748f2 */
if(!s->budget--) { s->failed_pc=0x0c0748f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a4u,2);
goto P_0c0748f4;
P_0c0748f4: /* original 365c, guest PC 0x0c0748f4 */
if(!s->budget--) { s->failed_pc=0x0c0748f4u; return 0; }
r[6]+=r[5];
goto P_0c0748f6;
P_0c0748f6: /* original f346, guest PC 0x0c0748f6 */
if(!s->budget--) { s->failed_pc=0x0c0748f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0748f8;
P_0c0748f8: /* original 3560, guest PC 0x0c0748f8 */
if(!s->budget--) { s->failed_pc=0x0c0748f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0748fa;
P_0c0748fa: /* original f340, guest PC 0x0c0748fa */
if(!s->budget--) { s->failed_pc=0x0c0748fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0748fc;
P_0c0748fc: /* original f437, guest PC 0x0c0748fc */
if(!s->budget--) { s->failed_pc=0x0c0748fcu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0748fe;
P_0c0748fe: /* original 7004, guest PC 0x0c0748fe */
if(!s->budget--) { s->failed_pc=0x0c0748feu; return 0; }
r[0]+=0x00000004u;
goto P_0c074900;
P_0c074900: /* original f246, guest PC 0x0c074900 */
if(!s->budget--) { s->failed_pc=0x0c074900u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074902;
P_0c074902: /* original f250, guest PC 0x0c074902 */
if(!s->budget--) { s->failed_pc=0x0c074902u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074904;
P_0c074904: /* original f427, guest PC 0x0c074904 */
if(!s->budget--) { s->failed_pc=0x0c074904u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074906;
P_0c074906: /* original 7004, guest PC 0x0c074906 */
if(!s->budget--) { s->failed_pc=0x0c074906u; return 0; }
r[0]+=0x00000004u;
goto P_0c074908;
P_0c074908: /* original f346, guest PC 0x0c074908 */
if(!s->budget--) { s->failed_pc=0x0c074908u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c07490a;
P_0c07490a: /* original f360, guest PC 0x0c07490a */
if(!s->budget--) { s->failed_pc=0x0c07490au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c07490c;
P_0c07490c: /* original 8d0e, guest PC 0x0c07490c */
if(!s->budget--) { s->failed_pc=0x0c07490cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c07492c; }
goto P_0c074910;
P_0c07490e: /* original f437, guest PC 0x0c07490e */
if(!s->budget--) { s->failed_pc=0x0c07490eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074910;
P_0c074910: /* original e004, guest PC 0x0c074910 */
if(!s->budget--) { s->failed_pc=0x0c074910u; return 0; }
r[0]=0x00000004u;
goto P_0c074912;
P_0c074912: /* original f358, guest PC 0x0c074912 */
if(!s->budget--) { s->failed_pc=0x0c074912u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c074914;
P_0c074914: /* original f340, guest PC 0x0c074914 */
if(!s->budget--) { s->failed_pc=0x0c074914u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c074916;
P_0c074916: /* original f53a, guest PC 0x0c074916 */
if(!s->budget--) { s->failed_pc=0x0c074916u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c074918;
P_0c074918: /* original f256, guest PC 0x0c074918 */
if(!s->budget--) { s->failed_pc=0x0c074918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c07491a;
P_0c07491a: /* original f250, guest PC 0x0c07491a */
if(!s->budget--) { s->failed_pc=0x0c07491au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07491c;
P_0c07491c: /* original f527, guest PC 0x0c07491c */
if(!s->budget--) { s->failed_pc=0x0c07491cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c07491e;
P_0c07491e: /* original e008, guest PC 0x0c07491e */
if(!s->budget--) { s->failed_pc=0x0c07491eu; return 0; }
r[0]=0x00000008u;
goto P_0c074920;
P_0c074920: /* original f356, guest PC 0x0c074920 */
if(!s->budget--) { s->failed_pc=0x0c074920u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c074922;
P_0c074922: /* original f360, guest PC 0x0c074922 */
if(!s->budget--) { s->failed_pc=0x0c074922u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c074924;
P_0c074924: /* original f537, guest PC 0x0c074924 */
if(!s->budget--) { s->failed_pc=0x0c074924u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c074926;
P_0c074926: /* original 750c, guest PC 0x0c074926 */
if(!s->budget--) { s->failed_pc=0x0c074926u; return 0; }
r[5]+=0x0000000cu;
goto P_0c074928;
P_0c074928: /* original 3560, guest PC 0x0c074928 */
if(!s->budget--) { s->failed_pc=0x0c074928u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c07492a;
P_0c07492a: /* original 8bf1, guest PC 0x0c07492a */
if(!s->budget--) { s->failed_pc=0x0c07492au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074910; }
goto P_0c07492c;
P_0c07492c: /* original 000b, guest PC 0x0c07492c */
if(!s->budget--) { s->failed_pc=0x0c07492cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07492e: /* original 0009, guest PC 0x0c07492e */
if(!s->budget--) { s->failed_pc=0x0c07492eu; return 0; }
if(!vf3_matrix_family(0x0c074930u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c074930u; return 0; } return 1;
P_0c07a7a8: /* original 2fe6, guest PC 0x0c07a7a8 */
if(!s->budget--) { s->failed_pc=0x0c07a7a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7aa;
P_0c07a7aa: /* original 2fd6, guest PC 0x0c07a7aa */
if(!s->budget--) { s->failed_pc=0x0c07a7aau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7ac;
P_0c07a7ac: /* original 2fc6, guest PC 0x0c07a7ac */
if(!s->budget--) { s->failed_pc=0x0c07a7acu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7ae;
P_0c07a7ae: /* original 2fb6, guest PC 0x0c07a7ae */
if(!s->budget--) { s->failed_pc=0x0c07a7aeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7b0;
P_0c07a7b0: /* original 2fa6, guest PC 0x0c07a7b0 */
if(!s->budget--) { s->failed_pc=0x0c07a7b0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7b2;
P_0c07a7b2: /* original 4f22, guest PC 0x0c07a7b2 */
if(!s->budget--) { s->failed_pc=0x0c07a7b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a7b4;
P_0c07a7b4: /* original d27f, guest PC 0x0c07a7b4 */
if(!s->budget--) { s->failed_pc=0x0c07a7b4u; return 0; }
r[2]=read(ram,0x0c07a9b4u,4);
goto P_0c07a7b6;
P_0c07a7b6: /* original d380, guest PC 0x0c07a7b6 */
if(!s->budget--) { s->failed_pc=0x0c07a7b6u; return 0; }
r[3]=read(ram,0x0c07a9b8u,4);
goto P_0c07a7b8;
P_0c07a7b8: /* original 7fe0, guest PC 0x0c07a7b8 */
if(!s->budget--) { s->failed_pc=0x0c07a7b8u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07a7ba;
P_0c07a7ba: /* original 6df3, guest PC 0x0c07a7ba */
if(!s->budget--) { s->failed_pc=0x0c07a7bau; return 0; }
r[13]=r[15];
goto P_0c07a7bc;
P_0c07a7bc: /* original 61f3, guest PC 0x0c07a7bc */
if(!s->budget--) { s->failed_pc=0x0c07a7bcu; return 0; }
r[1]=r[15];
goto P_0c07a7be;
P_0c07a7be: /* original 430b, guest PC 0x0c07a7be */
if(!s->budget--) { s->failed_pc=0x0c07a7beu; return 0; }
target=r[3];
r[16]=code_base|0x0c07a7c2u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7c2u) { target=s->pc; goto dispatch; }
goto P_0c07a7c2;
P_0c07a7c0: /* original e020, guest PC 0x0c07a7c0 */
if(!s->budget--) { s->failed_pc=0x0c07a7c0u; return 0; }
r[0]=0x00000020u;
goto P_0c07a7c2;
P_0c07a7c2: /* original db7f, guest PC 0x0c07a7c2 */
if(!s->budget--) { s->failed_pc=0x0c07a7c2u; return 0; }
r[11]=read(ram,0x0c07a9c0u,4);
goto P_0c07a7c4;
P_0c07a7c4: /* original ee00, guest PC 0x0c07a7c4 */
if(!s->budget--) { s->failed_pc=0x0c07a7c4u; return 0; }
r[14]=0x00000000u;
goto P_0c07a7c6;
P_0c07a7c6: /* original da7d, guest PC 0x0c07a7c6 */
if(!s->budget--) { s->failed_pc=0x0c07a7c6u; return 0; }
r[10]=read(ram,0x0c07a9bcu,4);
goto P_0c07a7c8;
P_0c07a7c8: /* original ec54, guest PC 0x0c07a7c8 */
if(!s->budget--) { s->failed_pc=0x0c07a7c8u; return 0; }
r[12]=0x00000054u;
goto P_0c07a7ca;
P_0c07a7ca: /* original 4b0b, guest PC 0x0c07a7ca */
if(!s->budget--) { s->failed_pc=0x0c07a7cau; return 0; }
target=r[11];
r[16]=code_base|0x0c07a7ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7ceu) { target=s->pc; goto dispatch; }
goto P_0c07a7ce;
P_0c07a7cc: /* original 64e3, guest PC 0x0c07a7cc */
if(!s->budget--) { s->failed_pc=0x0c07a7ccu; return 0; }
r[4]=r[14];
goto P_0c07a7ce;
P_0c07a7ce: /* original 4a0b, guest PC 0x0c07a7ce */
if(!s->budget--) { s->failed_pc=0x0c07a7ceu; return 0; }
target=r[10];
r[16]=code_base|0x0c07a7d2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7d2u) { target=s->pc; goto dispatch; }
goto P_0c07a7d2;
P_0c07a7d0: /* original 64d3, guest PC 0x0c07a7d0 */
if(!s->budget--) { s->failed_pc=0x0c07a7d0u; return 0; }
r[4]=r[13];
goto P_0c07a7d2;
P_0c07a7d2: /* original 7e01, guest PC 0x0c07a7d2 */
if(!s->budget--) { s->failed_pc=0x0c07a7d2u; return 0; }
r[14]+=0x00000001u;
goto P_0c07a7d4;
P_0c07a7d4: /* original 3ec3, guest PC 0x0c07a7d4 */
if(!s->budget--) { s->failed_pc=0x0c07a7d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c07a7d6;
P_0c07a7d6: /* original 8bf8, guest PC 0x0c07a7d6 */
if(!s->budget--) { s->failed_pc=0x0c07a7d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a7ca; }
goto P_0c07a7d8;
P_0c07a7d8: /* original 7f20, guest PC 0x0c07a7d8 */
if(!s->budget--) { s->failed_pc=0x0c07a7d8u; return 0; }
r[15]+=0x00000020u;
goto P_0c07a7da;
P_0c07a7da: /* original 4f26, guest PC 0x0c07a7da */
if(!s->budget--) { s->failed_pc=0x0c07a7dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a7dc;
P_0c07a7dc: /* original 6af6, guest PC 0x0c07a7dc */
if(!s->budget--) { s->failed_pc=0x0c07a7dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07a7de;
P_0c07a7de: /* original 6bf6, guest PC 0x0c07a7de */
if(!s->budget--) { s->failed_pc=0x0c07a7deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07a7e0;
P_0c07a7e0: /* original 6cf6, guest PC 0x0c07a7e0 */
if(!s->budget--) { s->failed_pc=0x0c07a7e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07a7e2;
P_0c07a7e2: /* original 6df6, guest PC 0x0c07a7e2 */
if(!s->budget--) { s->failed_pc=0x0c07a7e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a7e4;
P_0c07a7e4: /* original 000b, guest PC 0x0c07a7e4 */
if(!s->budget--) { s->failed_pc=0x0c07a7e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a7e6: /* original 6ef6, guest PC 0x0c07a7e6 */
if(!s->budget--) { s->failed_pc=0x0c07a7e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07a7e8;
P_0c07a7e8: /* original 6341, guest PC 0x0c07a7e8 */
if(!s->budget--) { s->failed_pc=0x0c07a7e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07a7ea;
P_0c07a7ea: /* original d676, guest PC 0x0c07a7ea */
if(!s->budget--) { s->failed_pc=0x0c07a7eau; return 0; }
r[6]=read(ram,0x0c07a9c4u,4);
goto P_0c07a7ec;
P_0c07a7ec: /* original 2631, guest PC 0x0c07a7ec */
if(!s->budget--) { s->failed_pc=0x0c07a7ecu; return 0; }
write(ram,r[6],r[3],2);
goto P_0c07a7ee;
P_0c07a7ee: /* original 8541, guest PC 0x0c07a7ee */
if(!s->budget--) { s->failed_pc=0x0c07a7eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c07a7f0;
P_0c07a7f0: /* original 8161, guest PC 0x0c07a7f0 */
if(!s->budget--) { s->failed_pc=0x0c07a7f0u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c07a7f2;
P_0c07a7f2: /* original 5341, guest PC 0x0c07a7f2 */
if(!s->budget--) { s->failed_pc=0x0c07a7f2u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07a7f4;
P_0c07a7f4: /* original 1631, guest PC 0x0c07a7f4 */
if(!s->budget--) { s->failed_pc=0x0c07a7f4u; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c07a7f6;
P_0c07a7f6: /* original 5242, guest PC 0x0c07a7f6 */
if(!s->budget--) { s->failed_pc=0x0c07a7f6u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a7f8;
P_0c07a7f8: /* original 352c, guest PC 0x0c07a7f8 */
if(!s->budget--) { s->failed_pc=0x0c07a7f8u; return 0; }
r[5]+=r[2];
goto P_0c07a7fa;
P_0c07a7fa: /* original 1652, guest PC 0x0c07a7fa */
if(!s->budget--) { s->failed_pc=0x0c07a7fau; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c07a7fc;
P_0c07a7fc: /* original 5343, guest PC 0x0c07a7fc */
if(!s->budget--) { s->failed_pc=0x0c07a7fcu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c07a7fe;
P_0c07a7fe: /* original 1633, guest PC 0x0c07a7fe */
if(!s->budget--) { s->failed_pc=0x0c07a7feu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c07a800;
P_0c07a800: /* original d271, guest PC 0x0c07a800 */
if(!s->budget--) { s->failed_pc=0x0c07a800u; return 0; }
r[2]=read(ram,0x0c07a9c8u,4);
goto P_0c07a802;
P_0c07a802: /* original 422b, guest PC 0x0c07a802 */
if(!s->budget--) { s->failed_pc=0x0c07a802u; return 0; }
target=r[2];
r[4]=r[6];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03f5a0u: return vf3_matrix_family(0x0c03f5a0u,s,ram);
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
P_0c07a804: /* original 6463, guest PC 0x0c07a804 */
if(!s->budget--) { s->failed_pc=0x0c07a804u; return 0; }
r[4]=r[6];
goto P_0c07a806;
P_0c07a806: /* original 2fe6, guest PC 0x0c07a806 */
if(!s->budget--) { s->failed_pc=0x0c07a806u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a808;
P_0c07a808: /* original 6e53, guest PC 0x0c07a808 */
if(!s->budget--) { s->failed_pc=0x0c07a808u; return 0; }
r[14]=r[5];
goto P_0c07a80a;
P_0c07a80a: /* original 2fd6, guest PC 0x0c07a80a */
if(!s->budget--) { s->failed_pc=0x0c07a80au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a80c;
P_0c07a80c: /* original 6d43, guest PC 0x0c07a80c */
if(!s->budget--) { s->failed_pc=0x0c07a80cu; return 0; }
r[13]=r[4];
goto P_0c07a80e;
P_0c07a80e: /* original 4f22, guest PC 0x0c07a80e */
if(!s->budget--) { s->failed_pc=0x0c07a80eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a810;
P_0c07a810: /* original 5041, guest PC 0x0c07a810 */
if(!s->budget--) { s->failed_pc=0x0c07a810u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a812;
P_0c07a812: /* original 88ff, guest PC 0x0c07a812 */
if(!s->budget--) { s->failed_pc=0x0c07a812u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a814;
P_0c07a814: /* original 8904, guest PC 0x0c07a814 */
if(!s->budget--) { s->failed_pc=0x0c07a814u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a820; }
goto P_0c07a816;
P_0c07a816: /* original 5242, guest PC 0x0c07a816 */
if(!s->budget--) { s->failed_pc=0x0c07a816u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a818;
P_0c07a818: /* original 32ec, guest PC 0x0c07a818 */
if(!s->budget--) { s->failed_pc=0x0c07a818u; return 0; }
r[2]+=r[14];
goto P_0c07a81a;
P_0c07a81a: /* original 1422, guest PC 0x0c07a81a */
if(!s->budget--) { s->failed_pc=0x0c07a81au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c07a81c;
P_0c07a81c: /* original aff8, guest PC 0x0c07a81c */
if(!s->budget--) { s->failed_pc=0x0c07a81cu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a810;
P_0c07a81e: /* original 7410, guest PC 0x0c07a81e */
if(!s->budget--) { s->failed_pc=0x0c07a81eu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a820;
P_0c07a820: /* original d369, guest PC 0x0c07a820 */
if(!s->budget--) { s->failed_pc=0x0c07a820u; return 0; }
r[3]=read(ram,0x0c07a9c8u,4);
goto P_0c07a822;
P_0c07a822: /* original 430b, guest PC 0x0c07a822 */
if(!s->budget--) { s->failed_pc=0x0c07a822u; return 0; }
target=r[3];
r[16]=code_base|0x0c07a826u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a826u) { target=s->pc; goto dispatch; }
goto P_0c07a826;
P_0c07a824: /* original 64d3, guest PC 0x0c07a824 */
if(!s->budget--) { s->failed_pc=0x0c07a824u; return 0; }
r[4]=r[13];
goto P_0c07a826;
P_0c07a826: /* original 64d3, guest PC 0x0c07a826 */
if(!s->budget--) { s->failed_pc=0x0c07a826u; return 0; }
r[4]=r[13];
goto P_0c07a828;
P_0c07a828: /* original 6503, guest PC 0x0c07a828 */
if(!s->budget--) { s->failed_pc=0x0c07a828u; return 0; }
r[5]=r[0];
goto P_0c07a82a;
P_0c07a82a: /* original 5041, guest PC 0x0c07a82a */
if(!s->budget--) { s->failed_pc=0x0c07a82au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a82c;
P_0c07a82c: /* original 88ff, guest PC 0x0c07a82c */
if(!s->budget--) { s->failed_pc=0x0c07a82cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a82e;
P_0c07a82e: /* original 8904, guest PC 0x0c07a82e */
if(!s->budget--) { s->failed_pc=0x0c07a82eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a83a; }
goto P_0c07a830;
P_0c07a830: /* original 5342, guest PC 0x0c07a830 */
if(!s->budget--) { s->failed_pc=0x0c07a830u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c07a832;
P_0c07a832: /* original 33e8, guest PC 0x0c07a832 */
if(!s->budget--) { s->failed_pc=0x0c07a832u; return 0; }
r[3]-=r[14];
goto P_0c07a834;
P_0c07a834: /* original 1432, guest PC 0x0c07a834 */
if(!s->budget--) { s->failed_pc=0x0c07a834u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c07a836;
P_0c07a836: /* original aff8, guest PC 0x0c07a836 */
if(!s->budget--) { s->failed_pc=0x0c07a836u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a82a;
P_0c07a838: /* original 7410, guest PC 0x0c07a838 */
if(!s->budget--) { s->failed_pc=0x0c07a838u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a83a;
P_0c07a83a: /* original 4f26, guest PC 0x0c07a83a */
if(!s->budget--) { s->failed_pc=0x0c07a83au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a83c;
P_0c07a83c: /* original 6053, guest PC 0x0c07a83c */
if(!s->budget--) { s->failed_pc=0x0c07a83cu; return 0; }
r[0]=r[5];
goto P_0c07a83e;
P_0c07a83e: /* original 6df6, guest PC 0x0c07a83e */
if(!s->budget--) { s->failed_pc=0x0c07a83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a840;
P_0c07a840: /* original 000b, guest PC 0x0c07a840 */
if(!s->budget--) { s->failed_pc=0x0c07a840u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a842: /* original 6ef6, guest PC 0x0c07a842 */
if(!s->budget--) { s->failed_pc=0x0c07a842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07a844u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
