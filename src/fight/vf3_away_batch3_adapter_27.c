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
int vf3_away_batch3_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c061596u: goto P_0c061596;
case 0x0c061598u: goto P_0c061598;
case 0x0c06159au: goto P_0c06159a;
case 0x0c06159cu: goto P_0c06159c;
case 0x0c06159eu: goto P_0c06159e;
case 0x0c0615a0u: goto P_0c0615a0;
case 0x0c0615a2u: goto P_0c0615a2;
case 0x0c0615a4u: goto P_0c0615a4;
case 0x0c0615a6u: goto P_0c0615a6;
case 0x0c0615a8u: goto P_0c0615a8;
case 0x0c0615aau: goto P_0c0615aa;
case 0x0c0615acu: goto P_0c0615ac;
case 0x0c0615aeu: goto P_0c0615ae;
case 0x0c0615b0u: goto P_0c0615b0;
case 0x0c0615b2u: goto P_0c0615b2;
case 0x0c0615b4u: goto P_0c0615b4;
case 0x0c0615b6u: goto P_0c0615b6;
case 0x0c0615b8u: goto P_0c0615b8;
case 0x0c0615bau: goto P_0c0615ba;
case 0x0c0615bcu: goto P_0c0615bc;
case 0x0c0615beu: goto P_0c0615be;
case 0x0c0615c0u: goto P_0c0615c0;
case 0x0c0615c2u: goto P_0c0615c2;
case 0x0c0615c4u: goto P_0c0615c4;
case 0x0c0615c6u: goto P_0c0615c6;
case 0x0c0615c8u: goto P_0c0615c8;
case 0x0c0615cau: goto P_0c0615ca;
case 0x0c0615ccu: goto P_0c0615cc;
case 0x0c0615ceu: goto P_0c0615ce;
case 0x0c0615d0u: goto P_0c0615d0;
case 0x0c0615d2u: goto P_0c0615d2;
case 0x0c0615d4u: goto P_0c0615d4;
case 0x0c0615d6u: goto P_0c0615d6;
case 0x0c0615d8u: goto P_0c0615d8;
case 0x0c0615dau: goto P_0c0615da;
case 0x0c0615dcu: goto P_0c0615dc;
case 0x0c0615deu: goto P_0c0615de;
case 0x0c061608u: goto P_0c061608;
case 0x0c06160au: goto P_0c06160a;
case 0x0c06160cu: goto P_0c06160c;
case 0x0c06160eu: goto P_0c06160e;
case 0x0c061610u: goto P_0c061610;
case 0x0c061612u: goto P_0c061612;
case 0x0c061614u: goto P_0c061614;
case 0x0c061616u: goto P_0c061616;
case 0x0c061618u: goto P_0c061618;
case 0x0c06161au: goto P_0c06161a;
case 0x0c06161cu: goto P_0c06161c;
case 0x0c06161eu: goto P_0c06161e;
case 0x0c061620u: goto P_0c061620;
case 0x0c061622u: goto P_0c061622;
case 0x0c061624u: goto P_0c061624;
case 0x0c061626u: goto P_0c061626;
case 0x0c061628u: goto P_0c061628;
case 0x0c06162au: goto P_0c06162a;
case 0x0c06162cu: goto P_0c06162c;
case 0x0c06162eu: goto P_0c06162e;
case 0x0c061630u: goto P_0c061630;
case 0x0c061632u: goto P_0c061632;
case 0x0c061634u: goto P_0c061634;
case 0x0c061636u: goto P_0c061636;
case 0x0c061638u: goto P_0c061638;
case 0x0c06163au: goto P_0c06163a;
case 0x0c06163cu: goto P_0c06163c;
case 0x0c06163eu: goto P_0c06163e;
case 0x0c061640u: goto P_0c061640;
case 0x0c061642u: goto P_0c061642;
case 0x0c061674u: goto P_0c061674;
case 0x0c061676u: goto P_0c061676;
case 0x0c061678u: goto P_0c061678;
case 0x0c06167au: goto P_0c06167a;
case 0x0c06167cu: goto P_0c06167c;
case 0x0c06167eu: goto P_0c06167e;
case 0x0c061680u: goto P_0c061680;
case 0x0c061682u: goto P_0c061682;
case 0x0c061684u: goto P_0c061684;
case 0x0c061686u: goto P_0c061686;
case 0x0c061688u: goto P_0c061688;
case 0x0c06168au: goto P_0c06168a;
case 0x0c06168cu: goto P_0c06168c;
case 0x0c06168eu: goto P_0c06168e;
case 0x0c061690u: goto P_0c061690;
case 0x0c061692u: goto P_0c061692;
case 0x0c061694u: goto P_0c061694;
case 0x0c061696u: goto P_0c061696;
case 0x0c061698u: goto P_0c061698;
case 0x0c06169au: goto P_0c06169a;
case 0x0c06169cu: goto P_0c06169c;
case 0x0c06169eu: goto P_0c06169e;
case 0x0c0616a0u: goto P_0c0616a0;
case 0x0c0616a2u: goto P_0c0616a2;
case 0x0c0616a4u: goto P_0c0616a4;
case 0x0c0616a6u: goto P_0c0616a6;
case 0x0c0616a8u: goto P_0c0616a8;
case 0x0c0616aau: goto P_0c0616aa;
case 0x0c0616acu: goto P_0c0616ac;
case 0x0c0616aeu: goto P_0c0616ae;
case 0x0c0616b0u: goto P_0c0616b0;
case 0x0c0616b2u: goto P_0c0616b2;
case 0x0c0616b4u: goto P_0c0616b4;
case 0x0c0616b6u: goto P_0c0616b6;
case 0x0c0616b8u: goto P_0c0616b8;
case 0x0c0616bau: goto P_0c0616ba;
case 0x0c0616bcu: goto P_0c0616bc;
case 0x0c0616beu: goto P_0c0616be;
case 0x0c0616c0u: goto P_0c0616c0;
case 0x0c0616c2u: goto P_0c0616c2;
case 0x0c0616c4u: goto P_0c0616c4;
case 0x0c0616c6u: goto P_0c0616c6;
case 0x0c0616c8u: goto P_0c0616c8;
case 0x0c0616cau: goto P_0c0616ca;
case 0x0c0616ccu: goto P_0c0616cc;
case 0x0c0616ceu: goto P_0c0616ce;
case 0x0c0616d0u: goto P_0c0616d0;
case 0x0c0616d2u: goto P_0c0616d2;
case 0x0c0616d4u: goto P_0c0616d4;
case 0x0c0616d6u: goto P_0c0616d6;
case 0x0c0616d8u: goto P_0c0616d8;
case 0x0c0616dau: goto P_0c0616da;
case 0x0c0616dcu: goto P_0c0616dc;
case 0x0c0616deu: goto P_0c0616de;
case 0x0c0616e0u: goto P_0c0616e0;
case 0x0c0616e2u: goto P_0c0616e2;
case 0x0c0616e4u: goto P_0c0616e4;
case 0x0c0616e6u: goto P_0c0616e6;
case 0x0c0616e8u: goto P_0c0616e8;
case 0x0c0616eau: goto P_0c0616ea;
case 0x0c0616ecu: goto P_0c0616ec;
case 0x0c0616eeu: goto P_0c0616ee;
case 0x0c0616f0u: goto P_0c0616f0;
case 0x0c0616f2u: goto P_0c0616f2;
case 0x0c0616f4u: goto P_0c0616f4;
case 0x0c0616f6u: goto P_0c0616f6;
case 0x0c0616f8u: goto P_0c0616f8;
case 0x0c0616fau: goto P_0c0616fa;
case 0x0c0616fcu: goto P_0c0616fc;
case 0x0c0616feu: goto P_0c0616fe;
case 0x0c061700u: goto P_0c061700;
case 0x0c061702u: goto P_0c061702;
case 0x0c061704u: goto P_0c061704;
case 0x0c061706u: goto P_0c061706;
case 0x0c061708u: goto P_0c061708;
case 0x0c06170au: goto P_0c06170a;
case 0x0c06170cu: goto P_0c06170c;
case 0x0c06170eu: goto P_0c06170e;
case 0x0c061710u: goto P_0c061710;
case 0x0c061712u: goto P_0c061712;
case 0x0c061714u: goto P_0c061714;
case 0x0c061716u: goto P_0c061716;
case 0x0c061718u: goto P_0c061718;
case 0x0c06171au: goto P_0c06171a;
case 0x0c06171cu: goto P_0c06171c;
case 0x0c06171eu: goto P_0c06171e;
case 0x0c061720u: goto P_0c061720;
case 0x0c061722u: goto P_0c061722;
case 0x0c061724u: goto P_0c061724;
case 0x0c061726u: goto P_0c061726;
case 0x0c061728u: goto P_0c061728;
case 0x0c06172au: goto P_0c06172a;
case 0x0c06172cu: goto P_0c06172c;
case 0x0c06172eu: goto P_0c06172e;
case 0x0c061730u: goto P_0c061730;
case 0x0c061732u: goto P_0c061732;
case 0x0c061734u: goto P_0c061734;
case 0x0c061736u: goto P_0c061736;
case 0x0c061738u: goto P_0c061738;
case 0x0c06173au: goto P_0c06173a;
case 0x0c06173cu: goto P_0c06173c;
case 0x0c06173eu: goto P_0c06173e;
case 0x0c061740u: goto P_0c061740;
case 0x0c061742u: goto P_0c061742;
case 0x0c061744u: goto P_0c061744;
case 0x0c061746u: goto P_0c061746;
case 0x0c061910u: goto P_0c061910;
case 0x0c061912u: goto P_0c061912;
case 0x0c061914u: goto P_0c061914;
case 0x0c061916u: goto P_0c061916;
case 0x0c061918u: goto P_0c061918;
case 0x0c06191au: goto P_0c06191a;
case 0x0c06191cu: goto P_0c06191c;
case 0x0c06191eu: goto P_0c06191e;
case 0x0c061920u: goto P_0c061920;
case 0x0c061922u: goto P_0c061922;
case 0x0c061924u: goto P_0c061924;
case 0x0c061926u: goto P_0c061926;
case 0x0c061928u: goto P_0c061928;
case 0x0c06192au: goto P_0c06192a;
case 0x0c06192cu: goto P_0c06192c;
case 0x0c06192eu: goto P_0c06192e;
case 0x0c061930u: goto P_0c061930;
case 0x0c061932u: goto P_0c061932;
case 0x0c061934u: goto P_0c061934;
case 0x0c061936u: goto P_0c061936;
case 0x0c061938u: goto P_0c061938;
case 0x0c06193au: goto P_0c06193a;
case 0x0c06193cu: goto P_0c06193c;
case 0x0c06193eu: goto P_0c06193e;
case 0x0c061940u: goto P_0c061940;
case 0x0c061942u: goto P_0c061942;
case 0x0c061944u: goto P_0c061944;
case 0x0c061946u: goto P_0c061946;
case 0x0c061948u: goto P_0c061948;
case 0x0c06194au: goto P_0c06194a;
case 0x0c06194cu: goto P_0c06194c;
case 0x0c06194eu: goto P_0c06194e;
case 0x0c061950u: goto P_0c061950;
case 0x0c061952u: goto P_0c061952;
case 0x0c061954u: goto P_0c061954;
case 0x0c061956u: goto P_0c061956;
case 0x0c061958u: goto P_0c061958;
case 0x0c06195au: goto P_0c06195a;
case 0x0c06195cu: goto P_0c06195c;
case 0x0c06195eu: goto P_0c06195e;
case 0x0c061960u: goto P_0c061960;
case 0x0c061962u: goto P_0c061962;
case 0x0c061964u: goto P_0c061964;
case 0x0c061966u: goto P_0c061966;
case 0x0c061968u: goto P_0c061968;
case 0x0c06196au: goto P_0c06196a;
case 0x0c06196cu: goto P_0c06196c;
case 0x0c06196eu: goto P_0c06196e;
case 0x0c061970u: goto P_0c061970;
case 0x0c061972u: goto P_0c061972;
case 0x0c061974u: goto P_0c061974;
case 0x0c061976u: goto P_0c061976;
case 0x0c061978u: goto P_0c061978;
case 0x0c06197au: goto P_0c06197a;
case 0x0c06197cu: goto P_0c06197c;
case 0x0c06197eu: goto P_0c06197e;
case 0x0c061980u: goto P_0c061980;
case 0x0c061982u: goto P_0c061982;
case 0x0c061984u: goto P_0c061984;
case 0x0c061986u: goto P_0c061986;
case 0x0c061988u: goto P_0c061988;
case 0x0c06198au: goto P_0c06198a;
case 0x0c06198cu: goto P_0c06198c;
case 0x0c06198eu: goto P_0c06198e;
case 0x0c061990u: goto P_0c061990;
case 0x0c061992u: goto P_0c061992;
case 0x0c061994u: goto P_0c061994;
case 0x0c061996u: goto P_0c061996;
default: return vf3_matrix_family(target,s,ram);
}
P_0c061596: /* original 2fe6, guest PC 0x0c061596 */
if(!s->budget--) { s->failed_pc=0x0c061596u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061598;
P_0c061598: /* original 2fd6, guest PC 0x0c061598 */
if(!s->budget--) { s->failed_pc=0x0c061598u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06159a;
P_0c06159a: /* original 6d43, guest PC 0x0c06159a */
if(!s->budget--) { s->failed_pc=0x0c06159au; return 0; }
r[13]=r[4];
goto P_0c06159c;
P_0c06159c: /* original 4f22, guest PC 0x0c06159c */
if(!s->budget--) { s->failed_pc=0x0c06159cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06159e;
P_0c06159e: /* original 7ff8, guest PC 0x0c06159e */
if(!s->budget--) { s->failed_pc=0x0c06159eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0615a0;
P_0c0615a0: /* original b6cd, guest PC 0x0c0615a0 */
if(!s->budget--) { s->failed_pc=0x0c0615a0u; return 0; }
target=code_base|0x0c06233eu; r[16]=code_base|0x0c0615a4u;
r[5]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0615a4u) { target=s->pc; goto dispatch; }
goto P_0c0615a4;
P_0c0615a2: /* original 65f3, guest PC 0x0c0615a2 */
if(!s->budget--) { s->failed_pc=0x0c0615a2u; return 0; }
r[5]=r[15];
goto P_0c0615a4;
P_0c0615a4: /* original 6e03, guest PC 0x0c0615a4 */
if(!s->budget--) { s->failed_pc=0x0c0615a4u; return 0; }
r[14]=r[0];
goto P_0c0615a6;
P_0c0615a6: /* original 2ee8, guest PC 0x0c0615a6 */
if(!s->budget--) { s->failed_pc=0x0c0615a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0615a8;
P_0c0615a8: /* original 8b01, guest PC 0x0c0615a8 */
if(!s->budget--) { s->failed_pc=0x0c0615a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0615ae; }
goto P_0c0615aa;
P_0c0615aa: /* original a046, guest PC 0x0c0615aa */
if(!s->budget--) { s->failed_pc=0x0c0615aau; return 0; }
r[0]=0x00000007u;
goto P_0c06163a;
P_0c0615ac: /* original e007, guest PC 0x0c0615ac */
if(!s->budget--) { s->failed_pc=0x0c0615acu; return 0; }
r[0]=0x00000007u;
goto P_0c0615ae;
P_0c0615ae: /* original 60e1, guest PC 0x0c0615ae */
if(!s->budget--) { s->failed_pc=0x0c0615aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c0615b0;
P_0c0615b0: /* original 600d, guest PC 0x0c0615b0 */
if(!s->budget--) { s->failed_pc=0x0c0615b0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0615b2;
P_0c0615b2: /* original c802, guest PC 0x0c0615b2 */
if(!s->budget--) { s->failed_pc=0x0c0615b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0615b4;
P_0c0615b4: /* original 893b, guest PC 0x0c0615b4 */
if(!s->budget--) { s->failed_pc=0x0c0615b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06162e; }
goto P_0c0615b6;
P_0c0615b6: /* original d20c, guest PC 0x0c0615b6 */
if(!s->budget--) { s->failed_pc=0x0c0615b6u; return 0; }
r[2]=read(ram,0x0c0615e8u,4);
goto P_0c0615b8;
P_0c0615b8: /* original 63f1, guest PC 0x0c0615b8 */
if(!s->budget--) { s->failed_pc=0x0c0615b8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0615ba;
P_0c0615ba: /* original 2338, guest PC 0x0c0615ba */
if(!s->budget--) { s->failed_pc=0x0c0615bau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0615bc;
P_0c0615bc: /* original 8f03, guest PC 0x0c0615bc */
if(!s->budget--) { s->failed_pc=0x0c0615bcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!cond) { goto P_0c0615c6; }
goto P_0c0615c0;
P_0c0615be: /* original 6522, guest PC 0x0c0615be */
if(!s->budget--) { s->failed_pc=0x0c0615beu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0615c0;
P_0c0615c0: /* original 6453, guest PC 0x0c0615c0 */
if(!s->budget--) { s->failed_pc=0x0c0615c0u; return 0; }
r[4]=r[5];
goto P_0c0615c2;
P_0c0615c2: /* original a002, guest PC 0x0c0615c2 */
if(!s->budget--) { s->failed_pc=0x0c0615c2u; return 0; }
r[4]+=r[13];
goto P_0c0615ca;
P_0c0615c4: /* original 34dc, guest PC 0x0c0615c4 */
if(!s->budget--) { s->failed_pc=0x0c0615c4u; return 0; }
r[4]+=r[13];
goto P_0c0615c6;
P_0c0615c6: /* original 64d3, guest PC 0x0c0615c6 */
if(!s->budget--) { s->failed_pc=0x0c0615c6u; return 0; }
r[4]=r[13];
goto P_0c0615c8;
P_0c0615c8: /* original 3458, guest PC 0x0c0615c8 */
if(!s->budget--) { s->failed_pc=0x0c0615c8u; return 0; }
r[4]-=r[5];
goto P_0c0615ca;
P_0c0615ca: /* original 65f3, guest PC 0x0c0615ca */
if(!s->budget--) { s->failed_pc=0x0c0615cau; return 0; }
r[5]=r[15];
goto P_0c0615cc;
P_0c0615cc: /* original b6b7, guest PC 0x0c0615cc */
if(!s->budget--) { s->failed_pc=0x0c0615ccu; return 0; }
target=code_base|0x0c06233eu; r[16]=code_base|0x0c0615d0u;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0615d0u) { target=s->pc; goto dispatch; }
goto P_0c0615d0;
P_0c0615ce: /* original 7504, guest PC 0x0c0615ce */
if(!s->budget--) { s->failed_pc=0x0c0615ceu; return 0; }
r[5]+=0x00000004u;
goto P_0c0615d0;
P_0c0615d0: /* original 6d03, guest PC 0x0c0615d0 */
if(!s->budget--) { s->failed_pc=0x0c0615d0u; return 0; }
r[13]=r[0];
goto P_0c0615d2;
P_0c0615d2: /* original 2dd8, guest PC 0x0c0615d2 */
if(!s->budget--) { s->failed_pc=0x0c0615d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0615d4;
P_0c0615d4: /* original 8b18, guest PC 0x0c0615d4 */
if(!s->budget--) { s->failed_pc=0x0c0615d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061608; }
goto P_0c0615d6;
P_0c0615d6: /* original 65e3, guest PC 0x0c0615d6 */
if(!s->budget--) { s->failed_pc=0x0c0615d6u; return 0; }
r[5]=r[14];
goto P_0c0615d8;
P_0c0615d8: /* original b6da, guest PC 0x0c0615d8 */
if(!s->budget--) { s->failed_pc=0x0c0615d8u; return 0; }
target=code_base|0x0c062390u; r[16]=code_base|0x0c0615dcu;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0615dcu) { target=s->pc; goto dispatch; }
goto P_0c0615dc;
P_0c0615da: /* original 64f1, guest PC 0x0c0615da */
if(!s->budget--) { s->failed_pc=0x0c0615dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c0615dc;
P_0c0615dc: /* original a02d, guest PC 0x0c0615dc */
if(!s->budget--) { s->failed_pc=0x0c0615dcu; return 0; }
r[0]=0x00000000u;
goto P_0c06163a;
P_0c0615de: /* original e000, guest PC 0x0c0615de */
if(!s->budget--) { s->failed_pc=0x0c0615deu; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c0615e0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0615e0u; return 0; } return 1;
P_0c061608: /* original 60d1, guest PC 0x0c061608 */
if(!s->budget--) { s->failed_pc=0x0c061608u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c06160a;
P_0c06160a: /* original 600d, guest PC 0x0c06160a */
if(!s->budget--) { s->failed_pc=0x0c06160au; return 0; }
r[0]=r[0]&65535u;
goto P_0c06160c;
P_0c06160c: /* original c804, guest PC 0x0c06160c */
if(!s->budget--) { s->failed_pc=0x0c06160cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c06160e;
P_0c06160e: /* original 8905, guest PC 0x0c06160e */
if(!s->budget--) { s->failed_pc=0x0c06160eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06161c; }
goto P_0c061610;
P_0c061610: /* original d34d, guest PC 0x0c061610 */
if(!s->budget--) { s->failed_pc=0x0c061610u; return 0; }
r[3]=read(ram,0x0c061748u,4);
goto P_0c061612;
P_0c061612: /* original 62e1, guest PC 0x0c061612 */
if(!s->budget--) { s->failed_pc=0x0c061612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061614;
P_0c061614: /* original 2239, guest PC 0x0c061614 */
if(!s->budget--) { s->failed_pc=0x0c061614u; return 0; }
r[2]&=r[3];
goto P_0c061616;
P_0c061616: /* original 2e21, guest PC 0x0c061616 */
if(!s->budget--) { s->failed_pc=0x0c061616u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061618;
P_0c061618: /* original a00d, guest PC 0x0c061618 */
if(!s->budget--) { s->failed_pc=0x0c061618u; return 0; }
r[4]=0x00000000u;
goto P_0c061636;
P_0c06161a: /* original e400, guest PC 0x0c06161a */
if(!s->budget--) { s->failed_pc=0x0c06161au; return 0; }
r[4]=0x00000000u;
goto P_0c06161c;
P_0c06161c: /* original 65e3, guest PC 0x0c06161c */
if(!s->budget--) { s->failed_pc=0x0c06161cu; return 0; }
r[5]=r[14];
goto P_0c06161e;
P_0c06161e: /* original b6b7, guest PC 0x0c06161e */
if(!s->budget--) { s->failed_pc=0x0c06161eu; return 0; }
target=code_base|0x0c062390u; r[16]=code_base|0x0c061622u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061622u) { target=s->pc; goto dispatch; }
goto P_0c061622;
P_0c061620: /* original 64f1, guest PC 0x0c061620 */
if(!s->budget--) { s->failed_pc=0x0c061620u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c061622;
P_0c061622: /* original 65d3, guest PC 0x0c061622 */
if(!s->budget--) { s->failed_pc=0x0c061622u; return 0; }
r[5]=r[13];
goto P_0c061624;
P_0c061624: /* original 85f2, guest PC 0x0c061624 */
if(!s->budget--) { s->failed_pc=0x0c061624u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c061626;
P_0c061626: /* original b6b3, guest PC 0x0c061626 */
if(!s->budget--) { s->failed_pc=0x0c061626u; return 0; }
target=code_base|0x0c062390u; r[16]=code_base|0x0c06162au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06162au) { target=s->pc; goto dispatch; }
goto P_0c06162a;
P_0c061628: /* original 6403, guest PC 0x0c061628 */
if(!s->budget--) { s->failed_pc=0x0c061628u; return 0; }
r[4]=r[0];
goto P_0c06162a;
P_0c06162a: /* original a004, guest PC 0x0c06162a */
if(!s->budget--) { s->failed_pc=0x0c06162au; return 0; }
r[4]=r[0];
goto P_0c061636;
P_0c06162c: /* original 6403, guest PC 0x0c06162c */
if(!s->budget--) { s->failed_pc=0x0c06162cu; return 0; }
r[4]=r[0];
goto P_0c06162e;
P_0c06162e: /* original 65e3, guest PC 0x0c06162e */
if(!s->budget--) { s->failed_pc=0x0c06162eu; return 0; }
r[5]=r[14];
goto P_0c061630;
P_0c061630: /* original b6ae, guest PC 0x0c061630 */
if(!s->budget--) { s->failed_pc=0x0c061630u; return 0; }
target=code_base|0x0c062390u; r[16]=code_base|0x0c061634u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061634u) { target=s->pc; goto dispatch; }
goto P_0c061634;
P_0c061632: /* original 64f1, guest PC 0x0c061632 */
if(!s->budget--) { s->failed_pc=0x0c061632u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c061634;
P_0c061634: /* original 6403, guest PC 0x0c061634 */
if(!s->budget--) { s->failed_pc=0x0c061634u; return 0; }
r[4]=r[0];
goto P_0c061636;
P_0c061636: /* original 6043, guest PC 0x0c061636 */
if(!s->budget--) { s->failed_pc=0x0c061636u; return 0; }
r[0]=r[4];
goto P_0c061638;
P_0c061638: /* original 0009, guest PC 0x0c061638 */
if(!s->budget--) { s->failed_pc=0x0c061638u; return 0; }
goto P_0c06163a;
P_0c06163a: /* original 7f08, guest PC 0x0c06163a */
if(!s->budget--) { s->failed_pc=0x0c06163au; return 0; }
r[15]+=0x00000008u;
goto P_0c06163c;
P_0c06163c: /* original 4f26, guest PC 0x0c06163c */
if(!s->budget--) { s->failed_pc=0x0c06163cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06163e;
P_0c06163e: /* original 6df6, guest PC 0x0c06163e */
if(!s->budget--) { s->failed_pc=0x0c06163eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061640;
P_0c061640: /* original 000b, guest PC 0x0c061640 */
if(!s->budget--) { s->failed_pc=0x0c061640u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061642: /* original 6ef6, guest PC 0x0c061642 */
if(!s->budget--) { s->failed_pc=0x0c061642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061644u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061644u; return 0; } return 1;
P_0c061674: /* original 2fe6, guest PC 0x0c061674 */
if(!s->budget--) { s->failed_pc=0x0c061674u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061676;
P_0c061676: /* original 6543, guest PC 0x0c061676 */
if(!s->budget--) { s->failed_pc=0x0c061676u; return 0; }
r[5]=r[4];
goto P_0c061678;
P_0c061678: /* original d335, guest PC 0x0c061678 */
if(!s->budget--) { s->failed_pc=0x0c061678u; return 0; }
r[3]=read(ram,0x0c061750u,4);
goto P_0c06167a;
P_0c06167a: /* original 2fd6, guest PC 0x0c06167a */
if(!s->budget--) { s->failed_pc=0x0c06167au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06167c;
P_0c06167c: /* original 2fc6, guest PC 0x0c06167c */
if(!s->budget--) { s->failed_pc=0x0c06167cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06167e;
P_0c06167e: /* original 6d43, guest PC 0x0c06167e */
if(!s->budget--) { s->failed_pc=0x0c06167eu; return 0; }
r[13]=r[4];
goto P_0c061680;
P_0c061680: /* original 2fb6, guest PC 0x0c061680 */
if(!s->budget--) { s->failed_pc=0x0c061680u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061682;
P_0c061682: /* original 4f22, guest PC 0x0c061682 */
if(!s->budget--) { s->failed_pc=0x0c061682u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c061684;
P_0c061684: /* original 7fec, guest PC 0x0c061684 */
if(!s->budget--) { s->failed_pc=0x0c061684u; return 0; }
r[15]+=0xffffffecu;
goto P_0c061686;
P_0c061686: /* original 430b, guest PC 0x0c061686 */
if(!s->budget--) { s->failed_pc=0x0c061686u; return 0; }
target=r[3];
r[16]=code_base|0x0c06168au;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06168au) { target=s->pc; goto dispatch; }
goto P_0c06168a;
P_0c061688: /* original 64f3, guest PC 0x0c061688 */
if(!s->budget--) { s->failed_pc=0x0c061688u; return 0; }
r[4]=r[15];
goto P_0c06168a;
P_0c06168a: /* original ee00, guest PC 0x0c06168a */
if(!s->budget--) { s->failed_pc=0x0c06168au; return 0; }
r[14]=0x00000000u;
goto P_0c06168c;
P_0c06168c: /* original d231, guest PC 0x0c06168c */
if(!s->budget--) { s->failed_pc=0x0c06168cu; return 0; }
r[2]=read(ram,0x0c061754u,4);
goto P_0c06168e;
P_0c06168e: /* original 6422, guest PC 0x0c06168e */
if(!s->budget--) { s->failed_pc=0x0c06168eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c061690;
P_0c061690: /* original 2448, guest PC 0x0c061690 */
if(!s->budget--) { s->failed_pc=0x0c061690u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061692;
P_0c061692: /* original 8d27, guest PC 0x0c061692 */
if(!s->budget--) { s->failed_pc=0x0c061692u; return 0; }
cond=r[17]&1u;
r[6]=read(ram,r[15]+16,4);
if(cond) { goto P_0c0616e4; }
goto P_0c061696;
P_0c061694: /* original 56f4, guest PC 0x0c061694 */
if(!s->budget--) { s->failed_pc=0x0c061694u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c061696;
P_0c061696: /* original db30, guest PC 0x0c061696 */
if(!s->budget--) { s->failed_pc=0x0c061696u; return 0; }
r[11]=read(ram,0x0c061758u,4);
goto P_0c061698;
P_0c061698: /* original 6241, guest PC 0x0c061698 */
if(!s->budget--) { s->failed_pc=0x0c061698u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c06169a;
P_0c06169a: /* original 622d, guest PC 0x0c06169a */
if(!s->budget--) { s->failed_pc=0x0c06169au; return 0; }
r[2]=r[2]&65535u;
goto P_0c06169c;
P_0c06169c: /* original 63f2, guest PC 0x0c06169c */
if(!s->budget--) { s->failed_pc=0x0c06169cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06169e;
P_0c06169e: /* original 22b9, guest PC 0x0c06169e */
if(!s->budget--) { s->failed_pc=0x0c06169eu; return 0; }
r[2]&=r[11];
goto P_0c0616a0;
P_0c0616a0: /* original 3230, guest PC 0x0c0616a0 */
if(!s->budget--) { s->failed_pc=0x0c0616a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0616a2;
P_0c0616a2: /* original 8b1a, guest PC 0x0c0616a2 */
if(!s->budget--) { s->failed_pc=0x0c0616a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616da; }
goto P_0c0616a4;
P_0c0616a4: /* original a017, guest PC 0x0c0616a4 */
if(!s->budget--) { s->failed_pc=0x0c0616a4u; return 0; }
r[5]=0x00000000u;
goto P_0c0616d6;
P_0c0616a6: /* original e500, guest PC 0x0c0616a6 */
if(!s->budget--) { s->failed_pc=0x0c0616a6u; return 0; }
r[5]=0x00000000u;
goto P_0c0616a8;
P_0c0616a8: /* original 6253, guest PC 0x0c0616a8 */
if(!s->budget--) { s->failed_pc=0x0c0616a8u; return 0; }
r[2]=r[5];
goto P_0c0616aa;
P_0c0616aa: /* original 4208, guest PC 0x0c0616aa */
if(!s->budget--) { s->failed_pc=0x0c0616aau; return 0; }
r[2]<<=2;
goto P_0c0616ac;
P_0c0616ac: /* original 6343, guest PC 0x0c0616ac */
if(!s->budget--) { s->failed_pc=0x0c0616acu; return 0; }
r[3]=r[4];
goto P_0c0616ae;
P_0c0616ae: /* original 730c, guest PC 0x0c0616ae */
if(!s->budget--) { s->failed_pc=0x0c0616aeu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0616b0;
P_0c0616b0: /* original 323c, guest PC 0x0c0616b0 */
if(!s->budget--) { s->failed_pc=0x0c0616b0u; return 0; }
r[2]+=r[3];
goto P_0c0616b2;
P_0c0616b2: /* original 6122, guest PC 0x0c0616b2 */
if(!s->budget--) { s->failed_pc=0x0c0616b2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0616b4;
P_0c0616b4: /* original 2118, guest PC 0x0c0616b4 */
if(!s->budget--) { s->failed_pc=0x0c0616b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0616b6;
P_0c0616b6: /* original 890d, guest PC 0x0c0616b6 */
if(!s->budget--) { s->failed_pc=0x0c0616b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0616d4; }
goto P_0c0616b8;
P_0c0616b8: /* original 57f1, guest PC 0x0c0616b8 */
if(!s->budget--) { s->failed_pc=0x0c0616b8u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0616ba;
P_0c0616ba: /* original 4709, guest PC 0x0c0616ba */
if(!s->budget--) { s->failed_pc=0x0c0616bau; return 0; }
r[7]>>=2;
goto P_0c0616bc;
P_0c0616bc: /* original 0577, guest PC 0x0c0616bc */
if(!s->budget--) { s->failed_pc=0x0c0616bcu; return 0; }
r[19]=r[5]*r[7];
goto P_0c0616be;
P_0c0616be: /* original 071a, guest PC 0x0c0616be */
if(!s->budget--) { s->failed_pc=0x0c0616beu; return 0; }
r[7]=r[19];
goto P_0c0616c0;
P_0c0616c0: /* original 5342, guest PC 0x0c0616c0 */
if(!s->budget--) { s->failed_pc=0x0c0616c0u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0616c2;
P_0c0616c2: /* original 4708, guest PC 0x0c0616c2 */
if(!s->budget--) { s->failed_pc=0x0c0616c2u; return 0; }
r[7]<<=2;
goto P_0c0616c4;
P_0c0616c4: /* original 52d7, guest PC 0x0c0616c4 */
if(!s->budget--) { s->failed_pc=0x0c0616c4u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c0616c6;
P_0c0616c6: /* original 373c, guest PC 0x0c0616c6 */
if(!s->budget--) { s->failed_pc=0x0c0616c6u; return 0; }
r[7]+=r[3];
goto P_0c0616c8;
P_0c0616c8: /* original 3720, guest PC 0x0c0616c8 */
if(!s->budget--) { s->failed_pc=0x0c0616c8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0616ca;
P_0c0616ca: /* original 8b03, guest PC 0x0c0616ca */
if(!s->budget--) { s->failed_pc=0x0c0616cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616d4; }
goto P_0c0616cc;
P_0c0616cc: /* original 6e43, guest PC 0x0c0616cc */
if(!s->budget--) { s->failed_pc=0x0c0616ccu; return 0; }
r[14]=r[4];
goto P_0c0616ce;
P_0c0616ce: /* original 6c53, guest PC 0x0c0616ce */
if(!s->budget--) { s->failed_pc=0x0c0616ceu; return 0; }
r[12]=r[5];
goto P_0c0616d0;
P_0c0616d0: /* original 6563, guest PC 0x0c0616d0 */
if(!s->budget--) { s->failed_pc=0x0c0616d0u; return 0; }
r[5]=r[6];
goto P_0c0616d2;
P_0c0616d2: /* original e400, guest PC 0x0c0616d2 */
if(!s->budget--) { s->failed_pc=0x0c0616d2u; return 0; }
r[4]=0x00000000u;
goto P_0c0616d4;
P_0c0616d4: /* original 7501, guest PC 0x0c0616d4 */
if(!s->budget--) { s->failed_pc=0x0c0616d4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0616d6;
P_0c0616d6: /* original 3562, guest PC 0x0c0616d6 */
if(!s->budget--) { s->failed_pc=0x0c0616d6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c0616d8;
P_0c0616d8: /* original 8be6, guest PC 0x0c0616d8 */
if(!s->budget--) { s->failed_pc=0x0c0616d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616a8; }
goto P_0c0616da;
P_0c0616da: /* original 2ee8, guest PC 0x0c0616da */
if(!s->budget--) { s->failed_pc=0x0c0616dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0616dc;
P_0c0616dc: /* original 8b00, guest PC 0x0c0616dc */
if(!s->budget--) { s->failed_pc=0x0c0616dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616e0; }
goto P_0c0616de;
P_0c0616de: /* original 5441, guest PC 0x0c0616de */
if(!s->budget--) { s->failed_pc=0x0c0616deu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0616e0;
P_0c0616e0: /* original 2448, guest PC 0x0c0616e0 */
if(!s->budget--) { s->failed_pc=0x0c0616e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0616e2;
P_0c0616e2: /* original 8bd9, guest PC 0x0c0616e2 */
if(!s->budget--) { s->failed_pc=0x0c0616e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061698; }
goto P_0c0616e4;
P_0c0616e4: /* original 2ee8, guest PC 0x0c0616e4 */
if(!s->budget--) { s->failed_pc=0x0c0616e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0616e6;
P_0c0616e6: /* original 8927, guest PC 0x0c0616e6 */
if(!s->budget--) { s->failed_pc=0x0c0616e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061738; }
goto P_0c0616e8;
P_0c0616e8: /* original 4c08, guest PC 0x0c0616e8 */
if(!s->budget--) { s->failed_pc=0x0c0616e8u; return 0; }
r[12]<<=2;
goto P_0c0616ea;
P_0c0616ea: /* original 62e3, guest PC 0x0c0616ea */
if(!s->budget--) { s->failed_pc=0x0c0616eau; return 0; }
r[2]=r[14];
goto P_0c0616ec;
P_0c0616ec: /* original 720c, guest PC 0x0c0616ec */
if(!s->budget--) { s->failed_pc=0x0c0616ecu; return 0; }
r[2]+=0x0000000cu;
goto P_0c0616ee;
P_0c0616ee: /* original 3c2c, guest PC 0x0c0616ee */
if(!s->budget--) { s->failed_pc=0x0c0616eeu; return 0; }
r[12]+=r[2];
goto P_0c0616f0;
P_0c0616f0: /* original e300, guest PC 0x0c0616f0 */
if(!s->budget--) { s->failed_pc=0x0c0616f0u; return 0; }
r[3]=0x00000000u;
goto P_0c0616f2;
P_0c0616f2: /* original 6533, guest PC 0x0c0616f2 */
if(!s->budget--) { s->failed_pc=0x0c0616f2u; return 0; }
r[5]=r[3];
goto P_0c0616f4;
P_0c0616f4: /* original 2c32, guest PC 0x0c0616f4 */
if(!s->budget--) { s->failed_pc=0x0c0616f4u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c0616f6;
P_0c0616f6: /* original a00a, guest PC 0x0c0616f6 */
if(!s->budget--) { s->failed_pc=0x0c0616f6u; return 0; }
r[4]=r[3];
goto P_0c06170e;
P_0c0616f8: /* original 6433, guest PC 0x0c0616f8 */
if(!s->budget--) { s->failed_pc=0x0c0616f8u; return 0; }
r[4]=r[3];
goto P_0c0616fa;
P_0c0616fa: /* original 6343, guest PC 0x0c0616fa */
if(!s->budget--) { s->failed_pc=0x0c0616fau; return 0; }
r[3]=r[4];
goto P_0c0616fc;
P_0c0616fc: /* original 4308, guest PC 0x0c0616fc */
if(!s->budget--) { s->failed_pc=0x0c0616fcu; return 0; }
r[3]<<=2;
goto P_0c0616fe;
P_0c0616fe: /* original 62e3, guest PC 0x0c0616fe */
if(!s->budget--) { s->failed_pc=0x0c0616feu; return 0; }
r[2]=r[14];
goto P_0c061700;
P_0c061700: /* original 720c, guest PC 0x0c061700 */
if(!s->budget--) { s->failed_pc=0x0c061700u; return 0; }
r[2]+=0x0000000cu;
goto P_0c061702;
P_0c061702: /* original 332c, guest PC 0x0c061702 */
if(!s->budget--) { s->failed_pc=0x0c061702u; return 0; }
r[3]+=r[2];
goto P_0c061704;
P_0c061704: /* original 6132, guest PC 0x0c061704 */
if(!s->budget--) { s->failed_pc=0x0c061704u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c061706;
P_0c061706: /* original 2118, guest PC 0x0c061706 */
if(!s->budget--) { s->failed_pc=0x0c061706u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c061708;
P_0c061708: /* original 8d01, guest PC 0x0c061708 */
if(!s->budget--) { s->failed_pc=0x0c061708u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06170e; }
goto P_0c06170c;
P_0c06170a: /* original 7401, guest PC 0x0c06170a */
if(!s->budget--) { s->failed_pc=0x0c06170au; return 0; }
r[4]+=0x00000001u;
goto P_0c06170c;
P_0c06170c: /* original e501, guest PC 0x0c06170c */
if(!s->budget--) { s->failed_pc=0x0c06170cu; return 0; }
r[5]=0x00000001u;
goto P_0c06170e;
P_0c06170e: /* original 53f4, guest PC 0x0c06170e */
if(!s->budget--) { s->failed_pc=0x0c06170eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c061710;
P_0c061710: /* original 3432, guest PC 0x0c061710 */
if(!s->budget--) { s->failed_pc=0x0c061710u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c061712;
P_0c061712: /* original 8bf2, guest PC 0x0c061712 */
if(!s->budget--) { s->failed_pc=0x0c061712u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0616fa; }
goto P_0c061714;
P_0c061714: /* original 2558, guest PC 0x0c061714 */
if(!s->budget--) { s->failed_pc=0x0c061714u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c061716;
P_0c061716: /* original 8b0d, guest PC 0x0c061716 */
if(!s->budget--) { s->failed_pc=0x0c061716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061734; }
goto P_0c061718;
P_0c061718: /* original bf3d, guest PC 0x0c061718 */
if(!s->budget--) { s->failed_pc=0x0c061718u; return 0; }
target=code_base|0x0c061596u; r[16]=code_base|0x0c06171cu;
r[4]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06171cu) { target=s->pc; goto dispatch; }
goto P_0c06171c;
P_0c06171a: /* original 54e2, guest PC 0x0c06171a */
if(!s->budget--) { s->failed_pc=0x0c06171au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c06171c;
P_0c06171c: /* original 6403, guest PC 0x0c06171c */
if(!s->budget--) { s->failed_pc=0x0c06171cu; return 0; }
r[4]=r[0];
goto P_0c06171e;
P_0c06171e: /* original 2448, guest PC 0x0c06171e */
if(!s->budget--) { s->failed_pc=0x0c06171eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061720;
P_0c061720: /* original 8901, guest PC 0x0c061720 */
if(!s->budget--) { s->failed_pc=0x0c061720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061726; }
goto P_0c061722;
P_0c061722: /* original a00a, guest PC 0x0c061722 */
if(!s->budget--) { s->failed_pc=0x0c061722u; return 0; }
r[0]=r[4];
goto P_0c06173a;
P_0c061724: /* original 6043, guest PC 0x0c061724 */
if(!s->budget--) { s->failed_pc=0x0c061724u; return 0; }
r[0]=r[4];
goto P_0c061726;
P_0c061726: /* original d40b, guest PC 0x0c061726 */
if(!s->budget--) { s->failed_pc=0x0c061726u; return 0; }
r[4]=read(ram,0x0c061754u,4);
goto P_0c061728;
P_0c061728: /* original d30c, guest PC 0x0c061728 */
if(!s->budget--) { s->failed_pc=0x0c061728u; return 0; }
r[3]=read(ram,0x0c06175cu,4);
goto P_0c06172a;
P_0c06172a: /* original 430b, guest PC 0x0c06172a */
if(!s->budget--) { s->failed_pc=0x0c06172au; return 0; }
target=r[3];
r[16]=code_base|0x0c06172eu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06172eu) { target=s->pc; goto dispatch; }
goto P_0c06172e;
P_0c06172c: /* original 65e3, guest PC 0x0c06172c */
if(!s->budget--) { s->failed_pc=0x0c06172cu; return 0; }
r[5]=r[14];
goto P_0c06172e;
P_0c06172e: /* original d20c, guest PC 0x0c06172e */
if(!s->budget--) { s->failed_pc=0x0c06172eu; return 0; }
r[2]=read(ram,0x0c061760u,4);
goto P_0c061730;
P_0c061730: /* original 420b, guest PC 0x0c061730 */
if(!s->budget--) { s->failed_pc=0x0c061730u; return 0; }
target=r[2];
r[16]=code_base|0x0c061734u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061734u) { target=s->pc; goto dispatch; }
goto P_0c061734;
P_0c061732: /* original 64e3, guest PC 0x0c061732 */
if(!s->budget--) { s->failed_pc=0x0c061732u; return 0; }
r[4]=r[14];
goto P_0c061734;
P_0c061734: /* original a001, guest PC 0x0c061734 */
if(!s->budget--) { s->failed_pc=0x0c061734u; return 0; }
r[0]=0x00000000u;
goto P_0c06173a;
P_0c061736: /* original e000, guest PC 0x0c061736 */
if(!s->budget--) { s->failed_pc=0x0c061736u; return 0; }
r[0]=0x00000000u;
goto P_0c061738;
P_0c061738: /* original e007, guest PC 0x0c061738 */
if(!s->budget--) { s->failed_pc=0x0c061738u; return 0; }
r[0]=0x00000007u;
goto P_0c06173a;
P_0c06173a: /* original 7f14, guest PC 0x0c06173a */
if(!s->budget--) { s->failed_pc=0x0c06173au; return 0; }
r[15]+=0x00000014u;
goto P_0c06173c;
P_0c06173c: /* original 4f26, guest PC 0x0c06173c */
if(!s->budget--) { s->failed_pc=0x0c06173cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06173e;
P_0c06173e: /* original 6bf6, guest PC 0x0c06173e */
if(!s->budget--) { s->failed_pc=0x0c06173eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c061740;
P_0c061740: /* original 6cf6, guest PC 0x0c061740 */
if(!s->budget--) { s->failed_pc=0x0c061740u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061742;
P_0c061742: /* original 6df6, guest PC 0x0c061742 */
if(!s->budget--) { s->failed_pc=0x0c061742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061744;
P_0c061744: /* original 000b, guest PC 0x0c061744 */
if(!s->budget--) { s->failed_pc=0x0c061744u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061746: /* original 6ef6, guest PC 0x0c061746 */
if(!s->budget--) { s->failed_pc=0x0c061746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061748u; return 0; } return 1;
P_0c061910: /* original 2fe6, guest PC 0x0c061910 */
if(!s->budget--) { s->failed_pc=0x0c061910u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061912;
P_0c061912: /* original ee00, guest PC 0x0c061912 */
if(!s->budget--) { s->failed_pc=0x0c061912u; return 0; }
r[14]=0x00000000u;
goto P_0c061914;
P_0c061914: /* original 2fd6, guest PC 0x0c061914 */
if(!s->budget--) { s->failed_pc=0x0c061914u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061916;
P_0c061916: /* original 2fc6, guest PC 0x0c061916 */
if(!s->budget--) { s->failed_pc=0x0c061916u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c061918;
P_0c061918: /* original dc3c, guest PC 0x0c061918 */
if(!s->budget--) { s->failed_pc=0x0c061918u; return 0; }
r[12]=read(ram,0x0c061a0cu,4);
goto P_0c06191a;
P_0c06191a: /* original 7ffc, guest PC 0x0c06191a */
if(!s->budget--) { s->failed_pc=0x0c06191au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06191c;
P_0c06191c: /* original 56c2, guest PC 0x0c06191c */
if(!s->budget--) { s->failed_pc=0x0c06191cu; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c06191e;
P_0c06191e: /* original 2668, guest PC 0x0c06191e */
if(!s->budget--) { s->failed_pc=0x0c06191eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061920;
P_0c061920: /* original 8d07, guest PC 0x0c061920 */
if(!s->budget--) { s->failed_pc=0x0c061920u; return 0; }
cond=r[17]&1u;
r[7]=r[14];
if(cond) { goto P_0c061932; }
goto P_0c061924;
P_0c061922: /* original 67e3, guest PC 0x0c061922 */
if(!s->budget--) { s->failed_pc=0x0c061922u; return 0; }
r[7]=r[14];
goto P_0c061924;
P_0c061924: /* original 5264, guest PC 0x0c061924 */
if(!s->budget--) { s->failed_pc=0x0c061924u; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c061926;
P_0c061926: /* original 3277, guest PC 0x0c061926 */
if(!s->budget--) { s->failed_pc=0x0c061926u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[7])!=0);
goto P_0c061928;
P_0c061928: /* original 8b00, guest PC 0x0c061928 */
if(!s->budget--) { s->failed_pc=0x0c061928u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06192c; }
goto P_0c06192a;
P_0c06192a: /* original 5764, guest PC 0x0c06192a */
if(!s->budget--) { s->failed_pc=0x0c06192au; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06192c;
P_0c06192c: /* original 5662, guest PC 0x0c06192c */
if(!s->budget--) { s->failed_pc=0x0c06192cu; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06192e;
P_0c06192e: /* original 2668, guest PC 0x0c06192e */
if(!s->budget--) { s->failed_pc=0x0c06192eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061930;
P_0c061930: /* original 8bf8, guest PC 0x0c061930 */
if(!s->budget--) { s->failed_pc=0x0c061930u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061924; }
goto P_0c061932;
P_0c061932: /* original 66c2, guest PC 0x0c061932 */
if(!s->budget--) { s->failed_pc=0x0c061932u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c061934;
P_0c061934: /* original 2668, guest PC 0x0c061934 */
if(!s->budget--) { s->failed_pc=0x0c061934u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061936;
P_0c061936: /* original 8d0b, guest PC 0x0c061936 */
if(!s->budget--) { s->failed_pc=0x0c061936u; return 0; }
cond=r[17]&1u;
r[13]=0x00000004u;
if(cond) { goto P_0c061950; }
goto P_0c06193a;
P_0c061938: /* original ed04, guest PC 0x0c061938 */
if(!s->budget--) { s->failed_pc=0x0c061938u; return 0; }
r[13]=0x00000004u;
goto P_0c06193a;
P_0c06193a: /* original 6261, guest PC 0x0c06193a */
if(!s->budget--) { s->failed_pc=0x0c06193au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c06193c;
P_0c06193c: /* original 622d, guest PC 0x0c06193c */
if(!s->budget--) { s->failed_pc=0x0c06193cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c06193e;
P_0c06193e: /* original 22d8, guest PC 0x0c06193e */
if(!s->budget--) { s->failed_pc=0x0c06193eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061940;
P_0c061940: /* original 8b03, guest PC 0x0c061940 */
if(!s->budget--) { s->failed_pc=0x0c061940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061942;
P_0c061942: /* original 5164, guest PC 0x0c061942 */
if(!s->budget--) { s->failed_pc=0x0c061942u; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c061944;
P_0c061944: /* original 3177, guest PC 0x0c061944 */
if(!s->budget--) { s->failed_pc=0x0c061944u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[7])!=0);
goto P_0c061946;
P_0c061946: /* original 8b00, guest PC 0x0c061946 */
if(!s->budget--) { s->failed_pc=0x0c061946u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06194a; }
goto P_0c061948;
P_0c061948: /* original 5764, guest PC 0x0c061948 */
if(!s->budget--) { s->failed_pc=0x0c061948u; return 0; }
r[7]=read(ram,r[6]+16,4);
goto P_0c06194a;
P_0c06194a: /* original 5662, guest PC 0x0c06194a */
if(!s->budget--) { s->failed_pc=0x0c06194au; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c06194c;
P_0c06194c: /* original 2668, guest PC 0x0c06194c */
if(!s->budget--) { s->failed_pc=0x0c06194cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06194e;
P_0c06194e: /* original 8bf4, guest PC 0x0c06194e */
if(!s->budget--) { s->failed_pc=0x0c06194eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06193a; }
goto P_0c061950;
P_0c061950: /* original 66c3, guest PC 0x0c061950 */
if(!s->budget--) { s->failed_pc=0x0c061950u; return 0; }
r[6]=r[12];
goto P_0c061952;
P_0c061952: /* original 7614, guest PC 0x0c061952 */
if(!s->budget--) { s->failed_pc=0x0c061952u; return 0; }
r[6]+=0x00000014u;
goto P_0c061954;
P_0c061954: /* original 2f62, guest PC 0x0c061954 */
if(!s->budget--) { s->failed_pc=0x0c061954u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c061956;
P_0c061956: /* original 5662, guest PC 0x0c061956 */
if(!s->budget--) { s->failed_pc=0x0c061956u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061958;
P_0c061958: /* original 2668, guest PC 0x0c061958 */
if(!s->budget--) { s->failed_pc=0x0c061958u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06195a;
P_0c06195a: /* original 8906, guest PC 0x0c06195a */
if(!s->budget--) { s->failed_pc=0x0c06195au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06196a; }
goto P_0c06195c;
P_0c06195c: /* original 5264, guest PC 0x0c06195c */
if(!s->budget--) { s->failed_pc=0x0c06195cu; return 0; }
r[2]=read(ram,r[6]+16,4);
goto P_0c06195e;
P_0c06195e: /* original 32e7, guest PC 0x0c06195e */
if(!s->budget--) { s->failed_pc=0x0c06195eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[14])!=0);
goto P_0c061960;
P_0c061960: /* original 8b00, guest PC 0x0c061960 */
if(!s->budget--) { s->failed_pc=0x0c061960u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061964; }
goto P_0c061962;
P_0c061962: /* original 5e64, guest PC 0x0c061962 */
if(!s->budget--) { s->failed_pc=0x0c061962u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061964;
P_0c061964: /* original 5662, guest PC 0x0c061964 */
if(!s->budget--) { s->failed_pc=0x0c061964u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061966;
P_0c061966: /* original 2668, guest PC 0x0c061966 */
if(!s->budget--) { s->failed_pc=0x0c061966u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061968;
P_0c061968: /* original 8bf8, guest PC 0x0c061968 */
if(!s->budget--) { s->failed_pc=0x0c061968u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06195c; }
goto P_0c06196a;
P_0c06196a: /* original 66f2, guest PC 0x0c06196a */
if(!s->budget--) { s->failed_pc=0x0c06196au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06196c;
P_0c06196c: /* original 6662, guest PC 0x0c06196c */
if(!s->budget--) { s->failed_pc=0x0c06196cu; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c06196e;
P_0c06196e: /* original 2668, guest PC 0x0c06196e */
if(!s->budget--) { s->failed_pc=0x0c06196eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061970;
P_0c061970: /* original 890a, guest PC 0x0c061970 */
if(!s->budget--) { s->failed_pc=0x0c061970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061988; }
goto P_0c061972;
P_0c061972: /* original 6261, guest PC 0x0c061972 */
if(!s->budget--) { s->failed_pc=0x0c061972u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[2]=tmp;
goto P_0c061974;
P_0c061974: /* original 622d, guest PC 0x0c061974 */
if(!s->budget--) { s->failed_pc=0x0c061974u; return 0; }
r[2]=r[2]&65535u;
goto P_0c061976;
P_0c061976: /* original 22d8, guest PC 0x0c061976 */
if(!s->budget--) { s->failed_pc=0x0c061976u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c061978;
P_0c061978: /* original 8b03, guest PC 0x0c061978 */
if(!s->budget--) { s->failed_pc=0x0c061978u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c06197a;
P_0c06197a: /* original 5164, guest PC 0x0c06197a */
if(!s->budget--) { s->failed_pc=0x0c06197au; return 0; }
r[1]=read(ram,r[6]+16,4);
goto P_0c06197c;
P_0c06197c: /* original 31e7, guest PC 0x0c06197c */
if(!s->budget--) { s->failed_pc=0x0c06197cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[14])!=0);
goto P_0c06197e;
P_0c06197e: /* original 8b00, guest PC 0x0c06197e */
if(!s->budget--) { s->failed_pc=0x0c06197eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061982; }
goto P_0c061980;
P_0c061980: /* original 5e64, guest PC 0x0c061980 */
if(!s->budget--) { s->failed_pc=0x0c061980u; return 0; }
r[14]=read(ram,r[6]+16,4);
goto P_0c061982;
P_0c061982: /* original 5662, guest PC 0x0c061982 */
if(!s->budget--) { s->failed_pc=0x0c061982u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c061984;
P_0c061984: /* original 2668, guest PC 0x0c061984 */
if(!s->budget--) { s->failed_pc=0x0c061984u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c061986;
P_0c061986: /* original 8bf4, guest PC 0x0c061986 */
if(!s->budget--) { s->failed_pc=0x0c061986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061972; }
goto P_0c061988;
P_0c061988: /* original 2472, guest PC 0x0c061988 */
if(!s->budget--) { s->failed_pc=0x0c061988u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c06198a;
P_0c06198a: /* original e000, guest PC 0x0c06198a */
if(!s->budget--) { s->failed_pc=0x0c06198au; return 0; }
r[0]=0x00000000u;
goto P_0c06198c;
P_0c06198c: /* original 25e2, guest PC 0x0c06198c */
if(!s->budget--) { s->failed_pc=0x0c06198cu; return 0; }
write(ram,r[5],r[14],4);
goto P_0c06198e;
P_0c06198e: /* original 7f04, guest PC 0x0c06198e */
if(!s->budget--) { s->failed_pc=0x0c06198eu; return 0; }
r[15]+=0x00000004u;
goto P_0c061990;
P_0c061990: /* original 6cf6, guest PC 0x0c061990 */
if(!s->budget--) { s->failed_pc=0x0c061990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061992;
P_0c061992: /* original 6df6, guest PC 0x0c061992 */
if(!s->budget--) { s->failed_pc=0x0c061992u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061994;
P_0c061994: /* original 000b, guest PC 0x0c061994 */
if(!s->budget--) { s->failed_pc=0x0c061994u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061996: /* original 6ef6, guest PC 0x0c061996 */
if(!s->budget--) { s->failed_pc=0x0c061996u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c061998u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c061998u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
