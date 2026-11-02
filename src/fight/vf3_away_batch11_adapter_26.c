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
int vf3_away_batch11_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c073850u: goto P_0c073850;
case 0x0c073852u: goto P_0c073852;
case 0x0c073854u: goto P_0c073854;
case 0x0c073856u: goto P_0c073856;
case 0x0c073858u: goto P_0c073858;
case 0x0c07385au: goto P_0c07385a;
case 0x0c07385cu: goto P_0c07385c;
case 0x0c07385eu: goto P_0c07385e;
case 0x0c073860u: goto P_0c073860;
case 0x0c073862u: goto P_0c073862;
case 0x0c073864u: goto P_0c073864;
case 0x0c073866u: goto P_0c073866;
case 0x0c073868u: goto P_0c073868;
case 0x0c07386au: goto P_0c07386a;
case 0x0c07386cu: goto P_0c07386c;
case 0x0c07386eu: goto P_0c07386e;
case 0x0c073870u: goto P_0c073870;
case 0x0c073872u: goto P_0c073872;
case 0x0c073874u: goto P_0c073874;
case 0x0c073876u: goto P_0c073876;
case 0x0c073878u: goto P_0c073878;
case 0x0c07387au: goto P_0c07387a;
case 0x0c07387cu: goto P_0c07387c;
case 0x0c07387eu: goto P_0c07387e;
case 0x0c073880u: goto P_0c073880;
case 0x0c073882u: goto P_0c073882;
case 0x0c073884u: goto P_0c073884;
case 0x0c073886u: goto P_0c073886;
case 0x0c073888u: goto P_0c073888;
case 0x0c07388au: goto P_0c07388a;
case 0x0c07388cu: goto P_0c07388c;
case 0x0c07388eu: goto P_0c07388e;
case 0x0c073890u: goto P_0c073890;
case 0x0c073892u: goto P_0c073892;
case 0x0c073894u: goto P_0c073894;
case 0x0c073896u: goto P_0c073896;
case 0x0c073898u: goto P_0c073898;
case 0x0c07389au: goto P_0c07389a;
case 0x0c07389cu: goto P_0c07389c;
case 0x0c07389eu: goto P_0c07389e;
case 0x0c0738a0u: goto P_0c0738a0;
case 0x0c0738a2u: goto P_0c0738a2;
case 0x0c0738a4u: goto P_0c0738a4;
case 0x0c0738a6u: goto P_0c0738a6;
case 0x0c0738a8u: goto P_0c0738a8;
case 0x0c0738aau: goto P_0c0738aa;
case 0x0c0738acu: goto P_0c0738ac;
case 0x0c0738aeu: goto P_0c0738ae;
case 0x0c0738b0u: goto P_0c0738b0;
case 0x0c0738b2u: goto P_0c0738b2;
case 0x0c0738b4u: goto P_0c0738b4;
case 0x0c0738b6u: goto P_0c0738b6;
case 0x0c0738b8u: goto P_0c0738b8;
case 0x0c0738bau: goto P_0c0738ba;
case 0x0c0738bcu: goto P_0c0738bc;
case 0x0c0738beu: goto P_0c0738be;
case 0x0c0738c0u: goto P_0c0738c0;
case 0x0c0738c2u: goto P_0c0738c2;
case 0x0c0738c4u: goto P_0c0738c4;
case 0x0c0738c6u: goto P_0c0738c6;
case 0x0c0738c8u: goto P_0c0738c8;
case 0x0c0738cau: goto P_0c0738ca;
case 0x0c0738ccu: goto P_0c0738cc;
case 0x0c0738ceu: goto P_0c0738ce;
case 0x0c0738d0u: goto P_0c0738d0;
case 0x0c0738d2u: goto P_0c0738d2;
case 0x0c0738d4u: goto P_0c0738d4;
case 0x0c0738d6u: goto P_0c0738d6;
case 0x0c0738eau: goto P_0c0738ea;
case 0x0c0738ecu: goto P_0c0738ec;
case 0x0c0738eeu: goto P_0c0738ee;
case 0x0c0738f0u: goto P_0c0738f0;
case 0x0c0738f2u: goto P_0c0738f2;
case 0x0c0738f4u: goto P_0c0738f4;
case 0x0c0738f6u: goto P_0c0738f6;
case 0x0c0738f8u: goto P_0c0738f8;
case 0x0c0738fau: goto P_0c0738fa;
case 0x0c0738fcu: goto P_0c0738fc;
case 0x0c0738feu: goto P_0c0738fe;
case 0x0c073900u: goto P_0c073900;
case 0x0c073902u: goto P_0c073902;
case 0x0c073904u: goto P_0c073904;
case 0x0c073906u: goto P_0c073906;
case 0x0c073908u: goto P_0c073908;
case 0x0c07390au: goto P_0c07390a;
case 0x0c07390cu: goto P_0c07390c;
case 0x0c07390eu: goto P_0c07390e;
case 0x0c073910u: goto P_0c073910;
case 0x0c073912u: goto P_0c073912;
case 0x0c073914u: goto P_0c073914;
case 0x0c073916u: goto P_0c073916;
case 0x0c073918u: goto P_0c073918;
case 0x0c07391au: goto P_0c07391a;
case 0x0c07391cu: goto P_0c07391c;
case 0x0c07391eu: goto P_0c07391e;
case 0x0c073920u: goto P_0c073920;
case 0x0c073922u: goto P_0c073922;
case 0x0c073924u: goto P_0c073924;
case 0x0c073926u: goto P_0c073926;
case 0x0c073928u: goto P_0c073928;
case 0x0c07392au: goto P_0c07392a;
case 0x0c07392cu: goto P_0c07392c;
case 0x0c07392eu: goto P_0c07392e;
case 0x0c073930u: goto P_0c073930;
case 0x0c073932u: goto P_0c073932;
case 0x0c073934u: goto P_0c073934;
case 0x0c073936u: goto P_0c073936;
case 0x0c073938u: goto P_0c073938;
case 0x0c07393au: goto P_0c07393a;
case 0x0c07393cu: goto P_0c07393c;
case 0x0c07393eu: goto P_0c07393e;
case 0x0c073940u: goto P_0c073940;
case 0x0c073942u: goto P_0c073942;
case 0x0c073944u: goto P_0c073944;
case 0x0c073946u: goto P_0c073946;
case 0x0c073948u: goto P_0c073948;
case 0x0c07394au: goto P_0c07394a;
case 0x0c07394cu: goto P_0c07394c;
case 0x0c07394eu: goto P_0c07394e;
case 0x0c073984u: goto P_0c073984;
case 0x0c073986u: goto P_0c073986;
case 0x0c073988u: goto P_0c073988;
case 0x0c07398au: goto P_0c07398a;
case 0x0c07398cu: goto P_0c07398c;
case 0x0c07398eu: goto P_0c07398e;
case 0x0c073990u: goto P_0c073990;
case 0x0c073992u: goto P_0c073992;
case 0x0c073994u: goto P_0c073994;
case 0x0c073996u: goto P_0c073996;
case 0x0c073998u: goto P_0c073998;
case 0x0c07399au: goto P_0c07399a;
case 0x0c07399cu: goto P_0c07399c;
case 0x0c07399eu: goto P_0c07399e;
case 0x0c0739a0u: goto P_0c0739a0;
case 0x0c0739a2u: goto P_0c0739a2;
case 0x0c0739a4u: goto P_0c0739a4;
case 0x0c0739a6u: goto P_0c0739a6;
case 0x0c0739a8u: goto P_0c0739a8;
case 0x0c0739aau: goto P_0c0739aa;
case 0x0c0739acu: goto P_0c0739ac;
case 0x0c0739aeu: goto P_0c0739ae;
case 0x0c0739b0u: goto P_0c0739b0;
case 0x0c0739b2u: goto P_0c0739b2;
case 0x0c0739b4u: goto P_0c0739b4;
case 0x0c0739b6u: goto P_0c0739b6;
case 0x0c0739b8u: goto P_0c0739b8;
case 0x0c0739bau: goto P_0c0739ba;
case 0x0c0739bcu: goto P_0c0739bc;
case 0x0c0739beu: goto P_0c0739be;
case 0x0c0739c0u: goto P_0c0739c0;
case 0x0c0739c2u: goto P_0c0739c2;
case 0x0c0739c4u: goto P_0c0739c4;
case 0x0c0739c6u: goto P_0c0739c6;
case 0x0c0739c8u: goto P_0c0739c8;
case 0x0c0739cau: goto P_0c0739ca;
case 0x0c0739ccu: goto P_0c0739cc;
case 0x0c0739ceu: goto P_0c0739ce;
case 0x0c0739d0u: goto P_0c0739d0;
case 0x0c0739d2u: goto P_0c0739d2;
case 0x0c0739d4u: goto P_0c0739d4;
case 0x0c0739d6u: goto P_0c0739d6;
case 0x0c0739d8u: goto P_0c0739d8;
case 0x0c0739dau: goto P_0c0739da;
case 0x0c0739dcu: goto P_0c0739dc;
case 0x0c0739deu: goto P_0c0739de;
case 0x0c0739e0u: goto P_0c0739e0;
case 0x0c0739e2u: goto P_0c0739e2;
case 0x0c0739e4u: goto P_0c0739e4;
case 0x0c0739e6u: goto P_0c0739e6;
case 0x0c0739e8u: goto P_0c0739e8;
case 0x0c0739eau: goto P_0c0739ea;
case 0x0c0739ecu: goto P_0c0739ec;
case 0x0c0739eeu: goto P_0c0739ee;
case 0x0c0739f0u: goto P_0c0739f0;
case 0x0c0739f2u: goto P_0c0739f2;
case 0x0c0739f4u: goto P_0c0739f4;
case 0x0c0739f6u: goto P_0c0739f6;
case 0x0c0739f8u: goto P_0c0739f8;
case 0x0c0739fau: goto P_0c0739fa;
case 0x0c0739fcu: goto P_0c0739fc;
case 0x0c0739feu: goto P_0c0739fe;
case 0x0c073a00u: goto P_0c073a00;
case 0x0c073a02u: goto P_0c073a02;
case 0x0c073a04u: goto P_0c073a04;
case 0x0c073a06u: goto P_0c073a06;
case 0x0c073a08u: goto P_0c073a08;
case 0x0c073a0au: goto P_0c073a0a;
case 0x0c073a0cu: goto P_0c073a0c;
case 0x0c073a0eu: goto P_0c073a0e;
case 0x0c073a10u: goto P_0c073a10;
case 0x0c073a12u: goto P_0c073a12;
case 0x0c073a14u: goto P_0c073a14;
case 0x0c073a16u: goto P_0c073a16;
case 0x0c073a18u: goto P_0c073a18;
case 0x0c073a1au: goto P_0c073a1a;
case 0x0c073a1cu: goto P_0c073a1c;
case 0x0c073a1eu: goto P_0c073a1e;
case 0x0c073a20u: goto P_0c073a20;
case 0x0c073a22u: goto P_0c073a22;
case 0x0c073a24u: goto P_0c073a24;
case 0x0c073a26u: goto P_0c073a26;
case 0x0c073a28u: goto P_0c073a28;
case 0x0c073a2au: goto P_0c073a2a;
case 0x0c073a2cu: goto P_0c073a2c;
case 0x0c073a2eu: goto P_0c073a2e;
case 0x0c073a30u: goto P_0c073a30;
case 0x0c073a32u: goto P_0c073a32;
case 0x0c073a34u: goto P_0c073a34;
case 0x0c073a36u: goto P_0c073a36;
case 0x0c073a38u: goto P_0c073a38;
case 0x0c073a3au: goto P_0c073a3a;
case 0x0c073a3cu: goto P_0c073a3c;
case 0x0c073a3eu: goto P_0c073a3e;
case 0x0c073a40u: goto P_0c073a40;
case 0x0c073a42u: goto P_0c073a42;
case 0x0c073a44u: goto P_0c073a44;
case 0x0c073a46u: goto P_0c073a46;
case 0x0c073a48u: goto P_0c073a48;
case 0x0c073a4au: goto P_0c073a4a;
case 0x0c073a4cu: goto P_0c073a4c;
case 0x0c073a4eu: goto P_0c073a4e;
case 0x0c073a50u: goto P_0c073a50;
case 0x0c073a52u: goto P_0c073a52;
case 0x0c073a54u: goto P_0c073a54;
case 0x0c073a56u: goto P_0c073a56;
case 0x0c073a58u: goto P_0c073a58;
case 0x0c073a5au: goto P_0c073a5a;
case 0x0c073a5cu: goto P_0c073a5c;
case 0x0c073a5eu: goto P_0c073a5e;
case 0x0c073a60u: goto P_0c073a60;
case 0x0c073a62u: goto P_0c073a62;
case 0x0c073a64u: goto P_0c073a64;
case 0x0c073a66u: goto P_0c073a66;
case 0x0c073a68u: goto P_0c073a68;
case 0x0c073a6au: goto P_0c073a6a;
case 0x0c073a6cu: goto P_0c073a6c;
case 0x0c073a6eu: goto P_0c073a6e;
case 0x0c073a70u: goto P_0c073a70;
case 0x0c073a72u: goto P_0c073a72;
case 0x0c073a74u: goto P_0c073a74;
case 0x0c073a76u: goto P_0c073a76;
case 0x0c073a78u: goto P_0c073a78;
case 0x0c073a7au: goto P_0c073a7a;
case 0x0c073a7cu: goto P_0c073a7c;
case 0x0c073a7eu: goto P_0c073a7e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c073850: /* original 2fe6, guest PC 0x0c073850 */
if(!s->budget--) { s->failed_pc=0x0c073850u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073852;
P_0c073852: /* original 2fd6, guest PC 0x0c073852 */
if(!s->budget--) { s->failed_pc=0x0c073852u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073854;
P_0c073854: /* original 2fc6, guest PC 0x0c073854 */
if(!s->budget--) { s->failed_pc=0x0c073854u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073856;
P_0c073856: /* original 6c43, guest PC 0x0c073856 */
if(!s->budget--) { s->failed_pc=0x0c073856u; return 0; }
r[12]=r[4];
goto P_0c073858;
P_0c073858: /* original d141, guest PC 0x0c073858 */
if(!s->budget--) { s->failed_pc=0x0c073858u; return 0; }
r[1]=read(ram,0x0c073960u,4);
goto P_0c07385a;
P_0c07385a: /* original d43f, guest PC 0x0c07385a */
if(!s->budget--) { s->failed_pc=0x0c07385au; return 0; }
r[4]=read(ram,0x0c073958u,4);
goto P_0c07385c;
P_0c07385c: /* original 4f22, guest PC 0x0c07385c */
if(!s->budget--) { s->failed_pc=0x0c07385cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07385e;
P_0c07385e: /* original 6212, guest PC 0x0c07385e */
if(!s->budget--) { s->failed_pc=0x0c07385eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c073860;
P_0c073860: /* original d33e, guest PC 0x0c073860 */
if(!s->budget--) { s->failed_pc=0x0c073860u; return 0; }
r[3]=read(ram,0x0c07395cu,4);
goto P_0c073862;
P_0c073862: /* original 5e44, guest PC 0x0c073862 */
if(!s->budget--) { s->failed_pc=0x0c073862u; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c073864;
P_0c073864: /* original 2238, guest PC 0x0c073864 */
if(!s->budget--) { s->failed_pc=0x0c073864u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073866;
P_0c073866: /* original 8f32, guest PC 0x0c073866 */
if(!s->budget--) { s->failed_pc=0x0c073866u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+20,4);
if(!cond) { goto P_0c0738ce; }
goto P_0c07386a;
P_0c073868: /* original 5d45, guest PC 0x0c073868 */
if(!s->budget--) { s->failed_pc=0x0c073868u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c07386a;
P_0c07386a: /* original 9071, guest PC 0x0c07386a */
if(!s->budget--) { s->failed_pc=0x0c07386au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073950u,2);
goto P_0c07386c;
P_0c07386c: /* original e404, guest PC 0x0c07386c */
if(!s->budget--) { s->failed_pc=0x0c07386cu; return 0; }
r[4]=0x00000004u;
goto P_0c07386e;
P_0c07386e: /* original 65d3, guest PC 0x0c07386e */
if(!s->budget--) { s->failed_pc=0x0c07386eu; return 0; }
r[5]=r[13];
goto P_0c073870;
P_0c073870: /* original 0e46, guest PC 0x0c073870 */
if(!s->budget--) { s->failed_pc=0x0c073870u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c073872;
P_0c073872: /* original 0d46, guest PC 0x0c073872 */
if(!s->budget--) { s->failed_pc=0x0c073872u; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c073874;
P_0c073874: /* original 906d, guest PC 0x0c073874 */
if(!s->budget--) { s->failed_pc=0x0c073874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073952u,2);
goto P_0c073876;
P_0c073876: /* original f48d, guest PC 0x0c073876 */
if(!s->budget--) { s->failed_pc=0x0c073876u; return 0; }
fr[4]=0;
goto P_0c073878;
P_0c073878: /* original fe47, guest PC 0x0c073878 */
if(!s->budget--) { s->failed_pc=0x0c073878u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07387a;
P_0c07387a: /* original 7004, guest PC 0x0c07387a */
if(!s->budget--) { s->failed_pc=0x0c07387au; return 0; }
r[0]+=0x00000004u;
goto P_0c07387c;
P_0c07387c: /* original fe47, guest PC 0x0c07387c */
if(!s->budget--) { s->failed_pc=0x0c07387cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07387e;
P_0c07387e: /* original 7004, guest PC 0x0c07387e */
if(!s->budget--) { s->failed_pc=0x0c07387eu; return 0; }
r[0]+=0x00000004u;
goto P_0c073880;
P_0c073880: /* original fe47, guest PC 0x0c073880 */
if(!s->budget--) { s->failed_pc=0x0c073880u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073882;
P_0c073882: /* original 70f8, guest PC 0x0c073882 */
if(!s->budget--) { s->failed_pc=0x0c073882u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c073884;
P_0c073884: /* original fd47, guest PC 0x0c073884 */
if(!s->budget--) { s->failed_pc=0x0c073884u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c073886;
P_0c073886: /* original 7004, guest PC 0x0c073886 */
if(!s->budget--) { s->failed_pc=0x0c073886u; return 0; }
r[0]+=0x00000004u;
goto P_0c073888;
P_0c073888: /* original fd47, guest PC 0x0c073888 */
if(!s->budget--) { s->failed_pc=0x0c073888u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07388a;
P_0c07388a: /* original 7004, guest PC 0x0c07388a */
if(!s->budget--) { s->failed_pc=0x0c07388au; return 0; }
r[0]+=0x00000004u;
goto P_0c07388c;
P_0c07388c: /* original fd47, guest PC 0x0c07388c */
if(!s->budget--) { s->failed_pc=0x0c07388cu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07388e;
P_0c07388e: /* original 9061, guest PC 0x0c07388e */
if(!s->budget--) { s->failed_pc=0x0c07388eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073954u,2);
goto P_0c073890;
P_0c073890: /* original fe47, guest PC 0x0c073890 */
if(!s->budget--) { s->failed_pc=0x0c073890u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073892;
P_0c073892: /* original 7004, guest PC 0x0c073892 */
if(!s->budget--) { s->failed_pc=0x0c073892u; return 0; }
r[0]+=0x00000004u;
goto P_0c073894;
P_0c073894: /* original fe47, guest PC 0x0c073894 */
if(!s->budget--) { s->failed_pc=0x0c073894u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c073896;
P_0c073896: /* original 7004, guest PC 0x0c073896 */
if(!s->budget--) { s->failed_pc=0x0c073896u; return 0; }
r[0]+=0x00000004u;
goto P_0c073898;
P_0c073898: /* original fe47, guest PC 0x0c073898 */
if(!s->budget--) { s->failed_pc=0x0c073898u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07389a;
P_0c07389a: /* original 70f8, guest PC 0x0c07389a */
if(!s->budget--) { s->failed_pc=0x0c07389au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c07389c;
P_0c07389c: /* original fd47, guest PC 0x0c07389c */
if(!s->budget--) { s->failed_pc=0x0c07389cu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c07389e;
P_0c07389e: /* original 7004, guest PC 0x0c07389e */
if(!s->budget--) { s->failed_pc=0x0c07389eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0738a0;
P_0c0738a0: /* original fd47, guest PC 0x0c0738a0 */
if(!s->budget--) { s->failed_pc=0x0c0738a0u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0738a2;
P_0c0738a2: /* original 7004, guest PC 0x0c0738a2 */
if(!s->budget--) { s->failed_pc=0x0c0738a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0738a4;
P_0c0738a4: /* original fd47, guest PC 0x0c0738a4 */
if(!s->budget--) { s->failed_pc=0x0c0738a4u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0738a6;
P_0c0738a6: /* original d32f, guest PC 0x0c0738a6 */
if(!s->budget--) { s->failed_pc=0x0c0738a6u; return 0; }
r[3]=read(ram,0x0c073964u,4);
goto P_0c0738a8;
P_0c0738a8: /* original 430b, guest PC 0x0c0738a8 */
if(!s->budget--) { s->failed_pc=0x0c0738a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0738acu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0738acu) { target=s->pc; goto dispatch; }
goto P_0c0738ac;
P_0c0738aa: /* original 64e3, guest PC 0x0c0738aa */
if(!s->budget--) { s->failed_pc=0x0c0738aau; return 0; }
r[4]=r[14];
goto P_0c0738ac;
P_0c0738ac: /* original d22e, guest PC 0x0c0738ac */
if(!s->budget--) { s->failed_pc=0x0c0738acu; return 0; }
r[2]=read(ram,0x0c073968u,4);
goto P_0c0738ae;
P_0c0738ae: /* original 65d3, guest PC 0x0c0738ae */
if(!s->budget--) { s->failed_pc=0x0c0738aeu; return 0; }
r[5]=r[13];
goto P_0c0738b0;
P_0c0738b0: /* original 420b, guest PC 0x0c0738b0 */
if(!s->budget--) { s->failed_pc=0x0c0738b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0738b4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0738b4u) { target=s->pc; goto dispatch; }
goto P_0c0738b4;
P_0c0738b2: /* original 64e3, guest PC 0x0c0738b2 */
if(!s->budget--) { s->failed_pc=0x0c0738b2u; return 0; }
r[4]=r[14];
goto P_0c0738b4;
P_0c0738b4: /* original 65d3, guest PC 0x0c0738b4 */
if(!s->budget--) { s->failed_pc=0x0c0738b4u; return 0; }
r[5]=r[13];
goto P_0c0738b6;
P_0c0738b6: /* original b7a3, guest PC 0x0c0738b6 */
if(!s->budget--) { s->failed_pc=0x0c0738b6u; return 0; }
target=code_base|0x0c074800u; r[16]=code_base|0x0c0738bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0738bau) { target=s->pc; goto dispatch; }
goto P_0c0738ba;
P_0c0738b8: /* original 64e3, guest PC 0x0c0738b8 */
if(!s->budget--) { s->failed_pc=0x0c0738b8u; return 0; }
r[4]=r[14];
goto P_0c0738ba;
P_0c0738ba: /* original d22c, guest PC 0x0c0738ba */
if(!s->budget--) { s->failed_pc=0x0c0738bau; return 0; }
r[2]=read(ram,0x0c07396cu,4);
goto P_0c0738bc;
P_0c0738bc: /* original 65d3, guest PC 0x0c0738bc */
if(!s->budget--) { s->failed_pc=0x0c0738bcu; return 0; }
r[5]=r[13];
goto P_0c0738be;
P_0c0738be: /* original 420b, guest PC 0x0c0738be */
if(!s->budget--) { s->failed_pc=0x0c0738beu; return 0; }
target=r[2];
r[16]=code_base|0x0c0738c2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0738c2u) { target=s->pc; goto dispatch; }
goto P_0c0738c2;
P_0c0738c0: /* original 64e3, guest PC 0x0c0738c0 */
if(!s->budget--) { s->failed_pc=0x0c0738c0u; return 0; }
r[4]=r[14];
goto P_0c0738c2;
P_0c0738c2: /* original 65e3, guest PC 0x0c0738c2 */
if(!s->budget--) { s->failed_pc=0x0c0738c2u; return 0; }
r[5]=r[14];
goto P_0c0738c4;
P_0c0738c4: /* original 66d3, guest PC 0x0c0738c4 */
if(!s->budget--) { s->failed_pc=0x0c0738c4u; return 0; }
r[6]=r[13];
goto P_0c0738c6;
P_0c0738c6: /* original b664, guest PC 0x0c0738c6 */
if(!s->budget--) { s->failed_pc=0x0c0738c6u; return 0; }
target=code_base|0x0c074592u; r[16]=code_base|0x0c0738cau;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0738cau) { target=s->pc; goto dispatch; }
goto P_0c0738ca;
P_0c0738c8: /* original 64c3, guest PC 0x0c0738c8 */
if(!s->budget--) { s->failed_pc=0x0c0738c8u; return 0; }
r[4]=r[12];
goto P_0c0738ca;
P_0c0738ca: /* original d229, guest PC 0x0c0738ca */
if(!s->budget--) { s->failed_pc=0x0c0738cau; return 0; }
r[2]=read(ram,0x0c073970u,4);
goto P_0c0738cc;
P_0c0738cc: /* original 1c23, guest PC 0x0c0738cc */
if(!s->budget--) { s->failed_pc=0x0c0738ccu; return 0; }
write(ram,r[12]+12,r[2],4);
goto P_0c0738ce;
P_0c0738ce: /* original 4f26, guest PC 0x0c0738ce */
if(!s->budget--) { s->failed_pc=0x0c0738ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0738d0;
P_0c0738d0: /* original 6cf6, guest PC 0x0c0738d0 */
if(!s->budget--) { s->failed_pc=0x0c0738d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0738d2;
P_0c0738d2: /* original 6df6, guest PC 0x0c0738d2 */
if(!s->budget--) { s->failed_pc=0x0c0738d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0738d4;
P_0c0738d4: /* original 000b, guest PC 0x0c0738d4 */
if(!s->budget--) { s->failed_pc=0x0c0738d4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0738d6: /* original 6ef6, guest PC 0x0c0738d6 */
if(!s->budget--) { s->failed_pc=0x0c0738d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0738d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0738d8u; return 0; } return 1;
P_0c0738ea: /* original 2fe6, guest PC 0x0c0738ea */
if(!s->budget--) { s->failed_pc=0x0c0738eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738ec;
P_0c0738ec: /* original 2fd6, guest PC 0x0c0738ec */
if(!s->budget--) { s->failed_pc=0x0c0738ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738ee;
P_0c0738ee: /* original 2fc6, guest PC 0x0c0738ee */
if(!s->budget--) { s->failed_pc=0x0c0738eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0738f0;
P_0c0738f0: /* original 6c43, guest PC 0x0c0738f0 */
if(!s->budget--) { s->failed_pc=0x0c0738f0u; return 0; }
r[12]=r[4];
goto P_0c0738f2;
P_0c0738f2: /* original fffb, guest PC 0x0c0738f2 */
if(!s->budget--) { s->failed_pc=0x0c0738f2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0738f4;
P_0c0738f4: /* original d11a, guest PC 0x0c0738f4 */
if(!s->budget--) { s->failed_pc=0x0c0738f4u; return 0; }
r[1]=read(ram,0x0c073960u,4);
goto P_0c0738f6;
P_0c0738f6: /* original d418, guest PC 0x0c0738f6 */
if(!s->budget--) { s->failed_pc=0x0c0738f6u; return 0; }
r[4]=read(ram,0x0c073958u,4);
goto P_0c0738f8;
P_0c0738f8: /* original 6212, guest PC 0x0c0738f8 */
if(!s->budget--) { s->failed_pc=0x0c0738f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0738fa;
P_0c0738fa: /* original d318, guest PC 0x0c0738fa */
if(!s->budget--) { s->failed_pc=0x0c0738fau; return 0; }
r[3]=read(ram,0x0c07395cu,4);
goto P_0c0738fc;
P_0c0738fc: /* original 4f22, guest PC 0x0c0738fc */
if(!s->budget--) { s->failed_pc=0x0c0738fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0738fe;
P_0c0738fe: /* original 5e44, guest PC 0x0c0738fe */
if(!s->budget--) { s->failed_pc=0x0c0738feu; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c073900;
P_0c073900: /* original 2238, guest PC 0x0c073900 */
if(!s->budget--) { s->failed_pc=0x0c073900u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073902;
P_0c073902: /* original 8d02, guest PC 0x0c073902 */
if(!s->budget--) { s->failed_pc=0x0c073902u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[4]+20,4);
if(cond) { goto P_0c07390a; }
goto P_0c073906;
P_0c073904: /* original 5d45, guest PC 0x0c073904 */
if(!s->budget--) { s->failed_pc=0x0c073904u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c073906;
P_0c073906: /* original a0b5, guest PC 0x0c073906 */
if(!s->budget--) { s->failed_pc=0x0c073906u; return 0; }
goto P_0c073a74;
P_0c073908: /* original 0009, guest PC 0x0c073908 */
if(!s->budget--) { s->failed_pc=0x0c073908u; return 0; }
goto P_0c07390a;
P_0c07390a: /* original 63e2, guest PC 0x0c07390a */
if(!s->budget--) { s->failed_pc=0x0c07390au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c07390c;
P_0c07390c: /* original 65d3, guest PC 0x0c07390c */
if(!s->budget--) { s->failed_pc=0x0c07390cu; return 0; }
r[5]=r[13];
goto P_0c07390e;
P_0c07390e: /* original d41a, guest PC 0x0c07390e */
if(!s->budget--) { s->failed_pc=0x0c07390eu; return 0; }
r[4]=read(ram,0x0c073978u,4);
goto P_0c073910;
P_0c073910: /* original 2349, guest PC 0x0c073910 */
if(!s->budget--) { s->failed_pc=0x0c073910u; return 0; }
r[3]&=r[4];
goto P_0c073912;
P_0c073912: /* original 2e32, guest PC 0x0c073912 */
if(!s->budget--) { s->failed_pc=0x0c073912u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c073914;
P_0c073914: /* original 62d2, guest PC 0x0c073914 */
if(!s->budget--) { s->failed_pc=0x0c073914u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c073916;
P_0c073916: /* original 2249, guest PC 0x0c073916 */
if(!s->budget--) { s->failed_pc=0x0c073916u; return 0; }
r[2]&=r[4];
goto P_0c073918;
P_0c073918: /* original 2d22, guest PC 0x0c073918 */
if(!s->budget--) { s->failed_pc=0x0c073918u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c07391a;
P_0c07391a: /* original 901a, guest PC 0x0c07391a */
if(!s->budget--) { s->failed_pc=0x0c07391au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073952u,2);
goto P_0c07391c;
P_0c07391c: /* original ff8d, guest PC 0x0c07391c */
if(!s->budget--) { s->failed_pc=0x0c07391cu; return 0; }
fr[15]=0;
goto P_0c07391e;
P_0c07391e: /* original fef7, guest PC 0x0c07391e */
if(!s->budget--) { s->failed_pc=0x0c07391eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073920;
P_0c073920: /* original 7004, guest PC 0x0c073920 */
if(!s->budget--) { s->failed_pc=0x0c073920u; return 0; }
r[0]+=0x00000004u;
goto P_0c073922;
P_0c073922: /* original fef7, guest PC 0x0c073922 */
if(!s->budget--) { s->failed_pc=0x0c073922u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073924;
P_0c073924: /* original 7004, guest PC 0x0c073924 */
if(!s->budget--) { s->failed_pc=0x0c073924u; return 0; }
r[0]+=0x00000004u;
goto P_0c073926;
P_0c073926: /* original fef7, guest PC 0x0c073926 */
if(!s->budget--) { s->failed_pc=0x0c073926u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073928;
P_0c073928: /* original 70f8, guest PC 0x0c073928 */
if(!s->budget--) { s->failed_pc=0x0c073928u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c07392a;
P_0c07392a: /* original fdf7, guest PC 0x0c07392a */
if(!s->budget--) { s->failed_pc=0x0c07392au; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c07392c;
P_0c07392c: /* original 7004, guest PC 0x0c07392c */
if(!s->budget--) { s->failed_pc=0x0c07392cu; return 0; }
r[0]+=0x00000004u;
goto P_0c07392e;
P_0c07392e: /* original fdf7, guest PC 0x0c07392e */
if(!s->budget--) { s->failed_pc=0x0c07392eu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073930;
P_0c073930: /* original 7004, guest PC 0x0c073930 */
if(!s->budget--) { s->failed_pc=0x0c073930u; return 0; }
r[0]+=0x00000004u;
goto P_0c073932;
P_0c073932: /* original fdf7, guest PC 0x0c073932 */
if(!s->budget--) { s->failed_pc=0x0c073932u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073934;
P_0c073934: /* original b325, guest PC 0x0c073934 */
if(!s->budget--) { s->failed_pc=0x0c073934u; return 0; }
target=code_base|0x0c073f82u; r[16]=code_base|0x0c073938u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073938u) { target=s->pc; goto dispatch; }
goto P_0c073938;
P_0c073936: /* original 64e3, guest PC 0x0c073936 */
if(!s->budget--) { s->failed_pc=0x0c073936u; return 0; }
r[4]=r[14];
goto P_0c073938;
P_0c073938: /* original d310, guest PC 0x0c073938 */
if(!s->budget--) { s->failed_pc=0x0c073938u; return 0; }
r[3]=read(ram,0x0c07397cu,4);
goto P_0c07393a;
P_0c07393a: /* original 6030, guest PC 0x0c07393a */
if(!s->budget--) { s->failed_pc=0x0c07393au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c07393c;
P_0c07393c: /* original 600c, guest PC 0x0c07393c */
if(!s->budget--) { s->failed_pc=0x0c07393cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07393e;
P_0c07393e: /* original c90f, guest PC 0x0c07393e */
if(!s->budget--) { s->failed_pc=0x0c07393eu; return 0; }
r[0]&=15u;
goto P_0c073940;
P_0c073940: /* original 880f, guest PC 0x0c073940 */
if(!s->budget--) { s->failed_pc=0x0c073940u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c073942;
P_0c073942: /* original 8b1f, guest PC 0x0c073942 */
if(!s->budget--) { s->failed_pc=0x0c073942u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073984; }
goto P_0c073944;
P_0c073944: /* original d10e, guest PC 0x0c073944 */
if(!s->budget--) { s->failed_pc=0x0c073944u; return 0; }
r[1]=read(ram,0x0c073980u,4);
goto P_0c073946;
P_0c073946: /* original 65d3, guest PC 0x0c073946 */
if(!s->budget--) { s->failed_pc=0x0c073946u; return 0; }
r[5]=r[13];
goto P_0c073948;
P_0c073948: /* original 410b, guest PC 0x0c073948 */
if(!s->budget--) { s->failed_pc=0x0c073948u; return 0; }
target=r[1];
r[16]=code_base|0x0c07394cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07394cu) { target=s->pc; goto dispatch; }
goto P_0c07394c;
P_0c07394a: /* original 64e3, guest PC 0x0c07394a */
if(!s->budget--) { s->failed_pc=0x0c07394au; return 0; }
r[4]=r[14];
goto P_0c07394c;
P_0c07394c: /* original a030, guest PC 0x0c07394c */
if(!s->budget--) { s->failed_pc=0x0c07394cu; return 0; }
goto P_0c0739b0;
P_0c07394e: /* original 0009, guest PC 0x0c07394e */
if(!s->budget--) { s->failed_pc=0x0c07394eu; return 0; }
if(!vf3_matrix_family(0x0c073950u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073950u; return 0; } return 1;
P_0c073984: /* original d241, guest PC 0x0c073984 */
if(!s->budget--) { s->failed_pc=0x0c073984u; return 0; }
r[2]=read(ram,0x0c073a8cu,4);
goto P_0c073986;
P_0c073986: /* original 6022, guest PC 0x0c073986 */
if(!s->budget--) { s->failed_pc=0x0c073986u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c073988;
P_0c073988: /* original c802, guest PC 0x0c073988 */
if(!s->budget--) { s->failed_pc=0x0c073988u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07398a;
P_0c07398a: /* original 8911, guest PC 0x0c07398a */
if(!s->budget--) { s->failed_pc=0x0c07398au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0739b0; }
goto P_0c07398c;
P_0c07398c: /* original d140, guest PC 0x0c07398c */
if(!s->budget--) { s->failed_pc=0x0c07398cu; return 0; }
r[1]=read(ram,0x0c073a90u,4);
goto P_0c07398e;
P_0c07398e: /* original 65e3, guest PC 0x0c07398e */
if(!s->budget--) { s->failed_pc=0x0c07398eu; return 0; }
r[5]=r[14];
goto P_0c073990;
P_0c073990: /* original 66d3, guest PC 0x0c073990 */
if(!s->budget--) { s->failed_pc=0x0c073990u; return 0; }
r[6]=r[13];
goto P_0c073992;
P_0c073992: /* original 410b, guest PC 0x0c073992 */
if(!s->budget--) { s->failed_pc=0x0c073992u; return 0; }
target=r[1];
r[16]=code_base|0x0c073996u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073996u) { target=s->pc; goto dispatch; }
goto P_0c073996;
P_0c073994: /* original 64c3, guest PC 0x0c073994 */
if(!s->budget--) { s->failed_pc=0x0c073994u; return 0; }
r[4]=r[12];
goto P_0c073996;
P_0c073996: /* original 65d3, guest PC 0x0c073996 */
if(!s->budget--) { s->failed_pc=0x0c073996u; return 0; }
r[5]=r[13];
goto P_0c073998;
P_0c073998: /* original b6b3, guest PC 0x0c073998 */
if(!s->budget--) { s->failed_pc=0x0c073998u; return 0; }
target=code_base|0x0c074702u; r[16]=code_base|0x0c07399cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07399cu) { target=s->pc; goto dispatch; }
goto P_0c07399c;
P_0c07399a: /* original 64e3, guest PC 0x0c07399a */
if(!s->budget--) { s->failed_pc=0x0c07399au; return 0; }
r[4]=r[14];
goto P_0c07399c;
P_0c07399c: /* original 65e3, guest PC 0x0c07399c */
if(!s->budget--) { s->failed_pc=0x0c07399cu; return 0; }
r[5]=r[14];
goto P_0c07399e;
P_0c07399e: /* original b6b0, guest PC 0x0c07399e */
if(!s->budget--) { s->failed_pc=0x0c07399eu; return 0; }
target=code_base|0x0c074702u; r[16]=code_base|0x0c0739a2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739a2u) { target=s->pc; goto dispatch; }
goto P_0c0739a2;
P_0c0739a0: /* original 64d3, guest PC 0x0c0739a0 */
if(!s->budget--) { s->failed_pc=0x0c0739a0u; return 0; }
r[4]=r[13];
goto P_0c0739a2;
P_0c0739a2: /* original 65d3, guest PC 0x0c0739a2 */
if(!s->budget--) { s->failed_pc=0x0c0739a2u; return 0; }
r[5]=r[13];
goto P_0c0739a4;
P_0c0739a4: /* original b705, guest PC 0x0c0739a4 */
if(!s->budget--) { s->failed_pc=0x0c0739a4u; return 0; }
target=code_base|0x0c0747b2u; r[16]=code_base|0x0c0739a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739a8u) { target=s->pc; goto dispatch; }
goto P_0c0739a8;
P_0c0739a6: /* original 64e3, guest PC 0x0c0739a6 */
if(!s->budget--) { s->failed_pc=0x0c0739a6u; return 0; }
r[4]=r[14];
goto P_0c0739a8;
P_0c0739a8: /* original d23a, guest PC 0x0c0739a8 */
if(!s->budget--) { s->failed_pc=0x0c0739a8u; return 0; }
r[2]=read(ram,0x0c073a94u,4);
goto P_0c0739aa;
P_0c0739aa: /* original 65d3, guest PC 0x0c0739aa */
if(!s->budget--) { s->failed_pc=0x0c0739aau; return 0; }
r[5]=r[13];
goto P_0c0739ac;
P_0c0739ac: /* original 420b, guest PC 0x0c0739ac */
if(!s->budget--) { s->failed_pc=0x0c0739acu; return 0; }
target=r[2];
r[16]=code_base|0x0c0739b0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739b0u) { target=s->pc; goto dispatch; }
goto P_0c0739b0;
P_0c0739ae: /* original 64e3, guest PC 0x0c0739ae */
if(!s->budget--) { s->failed_pc=0x0c0739aeu; return 0; }
r[4]=r[14];
goto P_0c0739b0;
P_0c0739b0: /* original d339, guest PC 0x0c0739b0 */
if(!s->budget--) { s->failed_pc=0x0c0739b0u; return 0; }
r[3]=read(ram,0x0c073a98u,4);
goto P_0c0739b2;
P_0c0739b2: /* original 65d3, guest PC 0x0c0739b2 */
if(!s->budget--) { s->failed_pc=0x0c0739b2u; return 0; }
r[5]=r[13];
goto P_0c0739b4;
P_0c0739b4: /* original 430b, guest PC 0x0c0739b4 */
if(!s->budget--) { s->failed_pc=0x0c0739b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0739b8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739b8u) { target=s->pc; goto dispatch; }
goto P_0c0739b8;
P_0c0739b6: /* original 64e3, guest PC 0x0c0739b6 */
if(!s->budget--) { s->failed_pc=0x0c0739b6u; return 0; }
r[4]=r[14];
goto P_0c0739b8;
P_0c0739b8: /* original 65d3, guest PC 0x0c0739b8 */
if(!s->budget--) { s->failed_pc=0x0c0739b8u; return 0; }
r[5]=r[13];
goto P_0c0739ba;
P_0c0739ba: /* original b721, guest PC 0x0c0739ba */
if(!s->budget--) { s->failed_pc=0x0c0739bau; return 0; }
target=code_base|0x0c074800u; r[16]=code_base|0x0c0739beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739beu) { target=s->pc; goto dispatch; }
goto P_0c0739be;
P_0c0739bc: /* original 64e3, guest PC 0x0c0739bc */
if(!s->budget--) { s->failed_pc=0x0c0739bcu; return 0; }
r[4]=r[14];
goto P_0c0739be;
P_0c0739be: /* original d337, guest PC 0x0c0739be */
if(!s->budget--) { s->failed_pc=0x0c0739beu; return 0; }
r[3]=read(ram,0x0c073a9cu,4);
goto P_0c0739c0;
P_0c0739c0: /* original 65d3, guest PC 0x0c0739c0 */
if(!s->budget--) { s->failed_pc=0x0c0739c0u; return 0; }
r[5]=r[13];
goto P_0c0739c2;
P_0c0739c2: /* original 430b, guest PC 0x0c0739c2 */
if(!s->budget--) { s->failed_pc=0x0c0739c2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0739c6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739c6u) { target=s->pc; goto dispatch; }
goto P_0c0739c6;
P_0c0739c4: /* original 64e3, guest PC 0x0c0739c4 */
if(!s->budget--) { s->failed_pc=0x0c0739c4u; return 0; }
r[4]=r[14];
goto P_0c0739c6;
P_0c0739c6: /* original 905b, guest PC 0x0c0739c6 */
if(!s->budget--) { s->failed_pc=0x0c0739c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a80u,2);
goto P_0c0739c8;
P_0c0739c8: /* original 65d3, guest PC 0x0c0739c8 */
if(!s->budget--) { s->failed_pc=0x0c0739c8u; return 0; }
r[5]=r[13];
goto P_0c0739ca;
P_0c0739ca: /* original fef7, guest PC 0x0c0739ca */
if(!s->budget--) { s->failed_pc=0x0c0739cau; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739cc;
P_0c0739cc: /* original 7004, guest PC 0x0c0739cc */
if(!s->budget--) { s->failed_pc=0x0c0739ccu; return 0; }
r[0]+=0x00000004u;
goto P_0c0739ce;
P_0c0739ce: /* original fef7, guest PC 0x0c0739ce */
if(!s->budget--) { s->failed_pc=0x0c0739ceu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739d0;
P_0c0739d0: /* original 7004, guest PC 0x0c0739d0 */
if(!s->budget--) { s->failed_pc=0x0c0739d0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0739d2;
P_0c0739d2: /* original fef7, guest PC 0x0c0739d2 */
if(!s->budget--) { s->failed_pc=0x0c0739d2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739d4;
P_0c0739d4: /* original 70f8, guest PC 0x0c0739d4 */
if(!s->budget--) { s->failed_pc=0x0c0739d4u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0739d6;
P_0c0739d6: /* original fdf7, guest PC 0x0c0739d6 */
if(!s->budget--) { s->failed_pc=0x0c0739d6u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739d8;
P_0c0739d8: /* original 7004, guest PC 0x0c0739d8 */
if(!s->budget--) { s->failed_pc=0x0c0739d8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0739da;
P_0c0739da: /* original fdf7, guest PC 0x0c0739da */
if(!s->budget--) { s->failed_pc=0x0c0739dau; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739dc;
P_0c0739dc: /* original 7004, guest PC 0x0c0739dc */
if(!s->budget--) { s->failed_pc=0x0c0739dcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0739de;
P_0c0739de: /* original fdf7, guest PC 0x0c0739de */
if(!s->budget--) { s->failed_pc=0x0c0739deu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739e0;
P_0c0739e0: /* original d32f, guest PC 0x0c0739e0 */
if(!s->budget--) { s->failed_pc=0x0c0739e0u; return 0; }
r[3]=read(ram,0x0c073aa0u,4);
goto P_0c0739e2;
P_0c0739e2: /* original 430b, guest PC 0x0c0739e2 */
if(!s->budget--) { s->failed_pc=0x0c0739e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0739e6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739e6u) { target=s->pc; goto dispatch; }
goto P_0c0739e6;
P_0c0739e4: /* original 64e3, guest PC 0x0c0739e4 */
if(!s->budget--) { s->failed_pc=0x0c0739e4u; return 0; }
r[4]=r[14];
goto P_0c0739e6;
P_0c0739e6: /* original 65d3, guest PC 0x0c0739e6 */
if(!s->budget--) { s->failed_pc=0x0c0739e6u; return 0; }
r[5]=r[13];
goto P_0c0739e8;
P_0c0739e8: /* original b76a, guest PC 0x0c0739e8 */
if(!s->budget--) { s->failed_pc=0x0c0739e8u; return 0; }
target=code_base|0x0c0748c0u; r[16]=code_base|0x0c0739ecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0739ecu) { target=s->pc; goto dispatch; }
goto P_0c0739ec;
P_0c0739ea: /* original 64e3, guest PC 0x0c0739ea */
if(!s->budget--) { s->failed_pc=0x0c0739eau; return 0; }
r[4]=r[14];
goto P_0c0739ec;
P_0c0739ec: /* original 9049, guest PC 0x0c0739ec */
if(!s->budget--) { s->failed_pc=0x0c0739ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a82u,2);
goto P_0c0739ee;
P_0c0739ee: /* original e201, guest PC 0x0c0739ee */
if(!s->budget--) { s->failed_pc=0x0c0739eeu; return 0; }
r[2]=0x00000001u;
goto P_0c0739f0;
P_0c0739f0: /* original fef7, guest PC 0x0c0739f0 */
if(!s->budget--) { s->failed_pc=0x0c0739f0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0739f2;
P_0c0739f2: /* original fdf7, guest PC 0x0c0739f2 */
if(!s->budget--) { s->failed_pc=0x0c0739f2u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c0739f4;
P_0c0739f4: /* original 63d2, guest PC 0x0c0739f4 */
if(!s->budget--) { s->failed_pc=0x0c0739f4u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0739f6;
P_0c0739f6: /* original 64e2, guest PC 0x0c0739f6 */
if(!s->budget--) { s->failed_pc=0x0c0739f6u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0739f8;
P_0c0739f8: /* original 2439, guest PC 0x0c0739f8 */
if(!s->budget--) { s->failed_pc=0x0c0739f8u; return 0; }
r[4]&=r[3];
goto P_0c0739fa;
P_0c0739fa: /* original 2428, guest PC 0x0c0739fa */
if(!s->budget--) { s->failed_pc=0x0c0739fau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0739fc;
P_0c0739fc: /* original 8921, guest PC 0x0c0739fc */
if(!s->budget--) { s->failed_pc=0x0c0739fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073a42; }
goto P_0c0739fe;
P_0c0739fe: /* original c729, guest PC 0x0c0739fe */
if(!s->budget--) { s->failed_pc=0x0c0739feu; return 0; }
r[0]=code_base|0x00073aa4u;
goto P_0c073a00;
P_0c073a00: /* original f308, guest PC 0x0c073a00 */
if(!s->budget--) { s->failed_pc=0x0c073a00u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c073a02;
P_0c073a02: /* original e05c, guest PC 0x0c073a02 */
if(!s->budget--) { s->failed_pc=0x0c073a02u; return 0; }
r[0]=0x0000005cu;
goto P_0c073a04;
P_0c073a04: /* original f2e6, guest PC 0x0c073a04 */
if(!s->budget--) { s->failed_pc=0x0c073a04u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c073a06;
P_0c073a06: /* original f235, guest PC 0x0c073a06 */
if(!s->budget--) { s->failed_pc=0x0c073a06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c073a08;
P_0c073a08: /* original 8b08, guest PC 0x0c073a08 */
if(!s->budget--) { s->failed_pc=0x0c073a08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073a1c; }
goto P_0c073a0a;
P_0c073a0a: /* original 65d3, guest PC 0x0c073a0a */
if(!s->budget--) { s->failed_pc=0x0c073a0au; return 0; }
r[5]=r[13];
goto P_0c073a0c;
P_0c073a0c: /* original b612, guest PC 0x0c073a0c */
if(!s->budget--) { s->failed_pc=0x0c073a0cu; return 0; }
target=code_base|0x0c074634u; r[16]=code_base|0x0c073a10u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a10u) { target=s->pc; goto dispatch; }
goto P_0c073a10;
P_0c073a0e: /* original 64e3, guest PC 0x0c073a0e */
if(!s->budget--) { s->failed_pc=0x0c073a0eu; return 0; }
r[4]=r[14];
goto P_0c073a10;
P_0c073a10: /* original 65e3, guest PC 0x0c073a10 */
if(!s->budget--) { s->failed_pc=0x0c073a10u; return 0; }
r[5]=r[14];
goto P_0c073a12;
P_0c073a12: /* original 66d3, guest PC 0x0c073a12 */
if(!s->budget--) { s->failed_pc=0x0c073a12u; return 0; }
r[6]=r[13];
goto P_0c073a14;
P_0c073a14: /* original b5bd, guest PC 0x0c073a14 */
if(!s->budget--) { s->failed_pc=0x0c073a14u; return 0; }
target=code_base|0x0c074592u; r[16]=code_base|0x0c073a18u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a18u) { target=s->pc; goto dispatch; }
goto P_0c073a18;
P_0c073a16: /* original 64c3, guest PC 0x0c073a16 */
if(!s->budget--) { s->failed_pc=0x0c073a16u; return 0; }
r[4]=r[12];
goto P_0c073a18;
P_0c073a18: /* original a013, guest PC 0x0c073a18 */
if(!s->budget--) { s->failed_pc=0x0c073a18u; return 0; }
goto P_0c073a42;
P_0c073a1a: /* original 0009, guest PC 0x0c073a1a */
if(!s->budget--) { s->failed_pc=0x0c073a1au; return 0; }
goto P_0c073a1c;
P_0c073a1c: /* original 65e3, guest PC 0x0c073a1c */
if(!s->budget--) { s->failed_pc=0x0c073a1cu; return 0; }
r[5]=r[14];
goto P_0c073a1e;
P_0c073a1e: /* original 66d3, guest PC 0x0c073a1e */
if(!s->budget--) { s->failed_pc=0x0c073a1eu; return 0; }
r[6]=r[13];
goto P_0c073a20;
P_0c073a20: /* original b044, guest PC 0x0c073a20 */
if(!s->budget--) { s->failed_pc=0x0c073a20u; return 0; }
target=code_base|0x0c073aacu; r[16]=code_base|0x0c073a24u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a24u) { target=s->pc; goto dispatch; }
goto P_0c073a24;
P_0c073a22: /* original 64c3, guest PC 0x0c073a22 */
if(!s->budget--) { s->failed_pc=0x0c073a22u; return 0; }
r[4]=r[12];
goto P_0c073a24;
P_0c073a24: /* original 65e3, guest PC 0x0c073a24 */
if(!s->budget--) { s->failed_pc=0x0c073a24u; return 0; }
r[5]=r[14];
goto P_0c073a26;
P_0c073a26: /* original 66d3, guest PC 0x0c073a26 */
if(!s->budget--) { s->failed_pc=0x0c073a26u; return 0; }
r[6]=r[13];
goto P_0c073a28;
P_0c073a28: /* original b389, guest PC 0x0c073a28 */
if(!s->budget--) { s->failed_pc=0x0c073a28u; return 0; }
target=code_base|0x0c07413eu; r[16]=code_base|0x0c073a2cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a2cu) { target=s->pc; goto dispatch; }
goto P_0c073a2c;
P_0c073a2a: /* original 64c3, guest PC 0x0c073a2a */
if(!s->budget--) { s->failed_pc=0x0c073a2au; return 0; }
r[4]=r[12];
goto P_0c073a2c;
P_0c073a2c: /* original 65d3, guest PC 0x0c073a2c */
if(!s->budget--) { s->failed_pc=0x0c073a2cu; return 0; }
r[5]=r[13];
goto P_0c073a2e;
P_0c073a2e: /* original b747, guest PC 0x0c073a2e */
if(!s->budget--) { s->failed_pc=0x0c073a2eu; return 0; }
target=code_base|0x0c0748c0u; r[16]=code_base|0x0c073a32u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a32u) { target=s->pc; goto dispatch; }
goto P_0c073a32;
P_0c073a30: /* original 64e3, guest PC 0x0c073a30 */
if(!s->budget--) { s->failed_pc=0x0c073a30u; return 0; }
r[4]=r[14];
goto P_0c073a32;
P_0c073a32: /* original 9027, guest PC 0x0c073a32 */
if(!s->budget--) { s->failed_pc=0x0c073a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a84u,2);
goto P_0c073a34;
P_0c073a34: /* original fef7, guest PC 0x0c073a34 */
if(!s->budget--) { s->failed_pc=0x0c073a34u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073a36;
P_0c073a36: /* original 7008, guest PC 0x0c073a36 */
if(!s->budget--) { s->failed_pc=0x0c073a36u; return 0; }
r[0]+=0x00000008u;
goto P_0c073a38;
P_0c073a38: /* original fef7, guest PC 0x0c073a38 */
if(!s->budget--) { s->failed_pc=0x0c073a38u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c073a3a;
P_0c073a3a: /* original 70f8, guest PC 0x0c073a3a */
if(!s->budget--) { s->failed_pc=0x0c073a3au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c073a3c;
P_0c073a3c: /* original fdf7, guest PC 0x0c073a3c */
if(!s->budget--) { s->failed_pc=0x0c073a3cu; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073a3e;
P_0c073a3e: /* original 7008, guest PC 0x0c073a3e */
if(!s->budget--) { s->failed_pc=0x0c073a3eu; return 0; }
r[0]+=0x00000008u;
goto P_0c073a40;
P_0c073a40: /* original fdf7, guest PC 0x0c073a40 */
if(!s->budget--) { s->failed_pc=0x0c073a40u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c073a42;
P_0c073a42: /* original d312, guest PC 0x0c073a42 */
if(!s->budget--) { s->failed_pc=0x0c073a42u; return 0; }
r[3]=read(ram,0x0c073a8cu,4);
goto P_0c073a44;
P_0c073a44: /* original 6032, guest PC 0x0c073a44 */
if(!s->budget--) { s->failed_pc=0x0c073a44u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c073a46;
P_0c073a46: /* original c802, guest PC 0x0c073a46 */
if(!s->budget--) { s->failed_pc=0x0c073a46u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c073a48;
P_0c073a48: /* original 8904, guest PC 0x0c073a48 */
if(!s->budget--) { s->failed_pc=0x0c073a48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073a54; }
goto P_0c073a4a;
P_0c073a4a: /* original d111, guest PC 0x0c073a4a */
if(!s->budget--) { s->failed_pc=0x0c073a4au; return 0; }
r[1]=read(ram,0x0c073a90u,4);
goto P_0c073a4c;
P_0c073a4c: /* original 65e3, guest PC 0x0c073a4c */
if(!s->budget--) { s->failed_pc=0x0c073a4cu; return 0; }
r[5]=r[14];
goto P_0c073a4e;
P_0c073a4e: /* original 66d3, guest PC 0x0c073a4e */
if(!s->budget--) { s->failed_pc=0x0c073a4eu; return 0; }
r[6]=r[13];
goto P_0c073a50;
P_0c073a50: /* original 410b, guest PC 0x0c073a50 */
if(!s->budget--) { s->failed_pc=0x0c073a50u; return 0; }
target=r[1];
r[16]=code_base|0x0c073a54u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a54u) { target=s->pc; goto dispatch; }
goto P_0c073a54;
P_0c073a52: /* original 64c3, guest PC 0x0c073a52 */
if(!s->budget--) { s->failed_pc=0x0c073a52u; return 0; }
r[4]=r[12];
goto P_0c073a54;
P_0c073a54: /* original 65d3, guest PC 0x0c073a54 */
if(!s->budget--) { s->failed_pc=0x0c073a54u; return 0; }
r[5]=r[13];
goto P_0c073a56;
P_0c073a56: /* original b654, guest PC 0x0c073a56 */
if(!s->budget--) { s->failed_pc=0x0c073a56u; return 0; }
target=code_base|0x0c074702u; r[16]=code_base|0x0c073a5au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a5au) { target=s->pc; goto dispatch; }
goto P_0c073a5a;
P_0c073a58: /* original 64e3, guest PC 0x0c073a58 */
if(!s->budget--) { s->failed_pc=0x0c073a58u; return 0; }
r[4]=r[14];
goto P_0c073a5a;
P_0c073a5a: /* original 65e3, guest PC 0x0c073a5a */
if(!s->budget--) { s->failed_pc=0x0c073a5au; return 0; }
r[5]=r[14];
goto P_0c073a5c;
P_0c073a5c: /* original b651, guest PC 0x0c073a5c */
if(!s->budget--) { s->failed_pc=0x0c073a5cu; return 0; }
target=code_base|0x0c074702u; r[16]=code_base|0x0c073a60u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a60u) { target=s->pc; goto dispatch; }
goto P_0c073a60;
P_0c073a5e: /* original 64d3, guest PC 0x0c073a5e */
if(!s->budget--) { s->failed_pc=0x0c073a5eu; return 0; }
r[4]=r[13];
goto P_0c073a60;
P_0c073a60: /* original 65d3, guest PC 0x0c073a60 */
if(!s->budget--) { s->failed_pc=0x0c073a60u; return 0; }
r[5]=r[13];
goto P_0c073a62;
P_0c073a62: /* original b6e4, guest PC 0x0c073a62 */
if(!s->budget--) { s->failed_pc=0x0c073a62u; return 0; }
target=code_base|0x0c07482eu; r[16]=code_base|0x0c073a66u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a66u) { target=s->pc; goto dispatch; }
goto P_0c073a66;
P_0c073a64: /* original 64e3, guest PC 0x0c073a64 */
if(!s->budget--) { s->failed_pc=0x0c073a64u; return 0; }
r[4]=r[14];
goto P_0c073a66;
P_0c073a66: /* original d210, guest PC 0x0c073a66 */
if(!s->budget--) { s->failed_pc=0x0c073a66u; return 0; }
r[2]=read(ram,0x0c073aa8u,4);
goto P_0c073a68;
P_0c073a68: /* original 420b, guest PC 0x0c073a68 */
if(!s->budget--) { s->failed_pc=0x0c073a68u; return 0; }
target=r[2];
r[16]=code_base|0x0c073a6cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073a6cu) { target=s->pc; goto dispatch; }
goto P_0c073a6c;
P_0c073a6a: /* original 64c3, guest PC 0x0c073a6a */
if(!s->budget--) { s->failed_pc=0x0c073a6au; return 0; }
r[4]=r[12];
goto P_0c073a6c;
P_0c073a6c: /* original 900b, guest PC 0x0c073a6c */
if(!s->budget--) { s->failed_pc=0x0c073a6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a86u,2);
goto P_0c073a6e;
P_0c073a6e: /* original 03ee, guest PC 0x0c073a6e */
if(!s->budget--) { s->failed_pc=0x0c073a6eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c073a70;
P_0c073a70: /* original 900a, guest PC 0x0c073a70 */
if(!s->budget--) { s->failed_pc=0x0c073a70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073a88u,2);
goto P_0c073a72;
P_0c073a72: /* original 0e36, guest PC 0x0c073a72 */
if(!s->budget--) { s->failed_pc=0x0c073a72u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c073a74;
P_0c073a74: /* original 4f26, guest PC 0x0c073a74 */
if(!s->budget--) { s->failed_pc=0x0c073a74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073a76;
P_0c073a76: /* original fff9, guest PC 0x0c073a76 */
if(!s->budget--) { s->failed_pc=0x0c073a76u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073a78;
P_0c073a78: /* original 6cf6, guest PC 0x0c073a78 */
if(!s->budget--) { s->failed_pc=0x0c073a78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c073a7a;
P_0c073a7a: /* original 6df6, guest PC 0x0c073a7a */
if(!s->budget--) { s->failed_pc=0x0c073a7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c073a7c;
P_0c073a7c: /* original 000b, guest PC 0x0c073a7c */
if(!s->budget--) { s->failed_pc=0x0c073a7cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073a7e: /* original 6ef6, guest PC 0x0c073a7e */
if(!s->budget--) { s->failed_pc=0x0c073a7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c073a80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073a80u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
