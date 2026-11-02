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
int vf3_away_batch70_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06149eu: goto P_0c06149e;
case 0x0c0614a0u: goto P_0c0614a0;
case 0x0c0614a2u: goto P_0c0614a2;
case 0x0c0614a4u: goto P_0c0614a4;
case 0x0c0614a6u: goto P_0c0614a6;
case 0x0c0614a8u: goto P_0c0614a8;
case 0x0c0614aau: goto P_0c0614aa;
case 0x0c0614acu: goto P_0c0614ac;
case 0x0c0614aeu: goto P_0c0614ae;
case 0x0c0614b0u: goto P_0c0614b0;
case 0x0c0614b2u: goto P_0c0614b2;
case 0x0c0614b4u: goto P_0c0614b4;
case 0x0c0614b6u: goto P_0c0614b6;
case 0x0c0614b8u: goto P_0c0614b8;
case 0x0c0614bau: goto P_0c0614ba;
case 0x0c0614bcu: goto P_0c0614bc;
case 0x0c0614beu: goto P_0c0614be;
case 0x0c0614c0u: goto P_0c0614c0;
case 0x0c0614c2u: goto P_0c0614c2;
case 0x0c0614c4u: goto P_0c0614c4;
case 0x0c0614c6u: goto P_0c0614c6;
case 0x0c0614c8u: goto P_0c0614c8;
case 0x0c0614cau: goto P_0c0614ca;
case 0x0c0614ccu: goto P_0c0614cc;
case 0x0c0614ceu: goto P_0c0614ce;
case 0x0c0614d0u: goto P_0c0614d0;
case 0x0c0614d2u: goto P_0c0614d2;
case 0x0c0614d4u: goto P_0c0614d4;
case 0x0c0614d6u: goto P_0c0614d6;
case 0x0c0614d8u: goto P_0c0614d8;
case 0x0c0614dau: goto P_0c0614da;
case 0x0c0614dcu: goto P_0c0614dc;
case 0x0c0614deu: goto P_0c0614de;
case 0x0c0614e0u: goto P_0c0614e0;
case 0x0c0614e2u: goto P_0c0614e2;
case 0x0c0614e4u: goto P_0c0614e4;
case 0x0c0614e6u: goto P_0c0614e6;
case 0x0c0614e8u: goto P_0c0614e8;
case 0x0c0614eau: goto P_0c0614ea;
case 0x0c0614ecu: goto P_0c0614ec;
case 0x0c0614eeu: goto P_0c0614ee;
case 0x0c0614f0u: goto P_0c0614f0;
case 0x0c0614f2u: goto P_0c0614f2;
case 0x0c0614f4u: goto P_0c0614f4;
case 0x0c0614f6u: goto P_0c0614f6;
case 0x0c0614f8u: goto P_0c0614f8;
case 0x0c0614fau: goto P_0c0614fa;
case 0x0c0614fcu: goto P_0c0614fc;
case 0x0c0614feu: goto P_0c0614fe;
case 0x0c061500u: goto P_0c061500;
case 0x0c061502u: goto P_0c061502;
case 0x0c061504u: goto P_0c061504;
case 0x0c061506u: goto P_0c061506;
case 0x0c061508u: goto P_0c061508;
case 0x0c06150au: goto P_0c06150a;
case 0x0c06150cu: goto P_0c06150c;
case 0x0c06150eu: goto P_0c06150e;
case 0x0c061510u: goto P_0c061510;
case 0x0c061512u: goto P_0c061512;
case 0x0c061514u: goto P_0c061514;
case 0x0c061516u: goto P_0c061516;
case 0x0c061518u: goto P_0c061518;
case 0x0c06151au: goto P_0c06151a;
case 0x0c06151cu: goto P_0c06151c;
case 0x0c06151eu: goto P_0c06151e;
case 0x0c061520u: goto P_0c061520;
case 0x0c061522u: goto P_0c061522;
case 0x0c061524u: goto P_0c061524;
case 0x0c061526u: goto P_0c061526;
case 0x0c061528u: goto P_0c061528;
case 0x0c06152au: goto P_0c06152a;
case 0x0c06152cu: goto P_0c06152c;
case 0x0c06152eu: goto P_0c06152e;
case 0x0c061530u: goto P_0c061530;
case 0x0c061532u: goto P_0c061532;
case 0x0c061534u: goto P_0c061534;
case 0x0c061536u: goto P_0c061536;
case 0x0c061538u: goto P_0c061538;
case 0x0c06153au: goto P_0c06153a;
case 0x0c06153cu: goto P_0c06153c;
case 0x0c06153eu: goto P_0c06153e;
case 0x0c061540u: goto P_0c061540;
case 0x0c061542u: goto P_0c061542;
case 0x0c061544u: goto P_0c061544;
case 0x0c061546u: goto P_0c061546;
case 0x0c061548u: goto P_0c061548;
case 0x0c06154au: goto P_0c06154a;
case 0x0c06154cu: goto P_0c06154c;
case 0x0c06154eu: goto P_0c06154e;
case 0x0c061550u: goto P_0c061550;
case 0x0c061552u: goto P_0c061552;
case 0x0c061554u: goto P_0c061554;
case 0x0c061556u: goto P_0c061556;
case 0x0c061558u: goto P_0c061558;
case 0x0c06155au: goto P_0c06155a;
case 0x0c06155cu: goto P_0c06155c;
case 0x0c06155eu: goto P_0c06155e;
case 0x0c061560u: goto P_0c061560;
case 0x0c061562u: goto P_0c061562;
case 0x0c061564u: goto P_0c061564;
case 0x0c061566u: goto P_0c061566;
case 0x0c061568u: goto P_0c061568;
case 0x0c06156au: goto P_0c06156a;
case 0x0c06156cu: goto P_0c06156c;
case 0x0c06156eu: goto P_0c06156e;
case 0x0c061570u: goto P_0c061570;
case 0x0c061572u: goto P_0c061572;
case 0x0c061574u: goto P_0c061574;
case 0x0c061576u: goto P_0c061576;
case 0x0c061578u: goto P_0c061578;
case 0x0c06157au: goto P_0c06157a;
case 0x0c06157cu: goto P_0c06157c;
case 0x0c06157eu: goto P_0c06157e;
case 0x0c061580u: goto P_0c061580;
case 0x0c061582u: goto P_0c061582;
case 0x0c061584u: goto P_0c061584;
case 0x0c061586u: goto P_0c061586;
case 0x0c061588u: goto P_0c061588;
case 0x0c06158au: goto P_0c06158a;
case 0x0c06158cu: goto P_0c06158c;
case 0x0c06158eu: goto P_0c06158e;
case 0x0c061590u: goto P_0c061590;
case 0x0c061592u: goto P_0c061592;
case 0x0c061594u: goto P_0c061594;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c06149e: /* original 6543, guest PC 0x0c06149e */
if(!s->budget--) { s->failed_pc=0x0c06149eu; return 0; }
r[5]=r[4];
goto P_0c0614a0;
P_0c0614a0: /* original d352, guest PC 0x0c0614a0 */
if(!s->budget--) { s->failed_pc=0x0c0614a0u; return 0; }
r[3]=read(ram,0x0c0615ecu,4);
goto P_0c0614a2;
P_0c0614a2: /* original 2fe6, guest PC 0x0c0614a2 */
if(!s->budget--) { s->failed_pc=0x0c0614a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a4;
P_0c0614a4: /* original 2fd6, guest PC 0x0c0614a4 */
if(!s->budget--) { s->failed_pc=0x0c0614a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a6;
P_0c0614a6: /* original 2fc6, guest PC 0x0c0614a6 */
if(!s->budget--) { s->failed_pc=0x0c0614a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614a8;
P_0c0614a8: /* original 2fb6, guest PC 0x0c0614a8 */
if(!s->budget--) { s->failed_pc=0x0c0614a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0614aa;
P_0c0614aa: /* original 6b43, guest PC 0x0c0614aa */
if(!s->budget--) { s->failed_pc=0x0c0614aau; return 0; }
r[11]=r[4];
goto P_0c0614ac;
P_0c0614ac: /* original 4f22, guest PC 0x0c0614ac */
if(!s->budget--) { s->failed_pc=0x0c0614acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0614ae;
P_0c0614ae: /* original 7fe4, guest PC 0x0c0614ae */
if(!s->budget--) { s->failed_pc=0x0c0614aeu; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0614b0;
P_0c0614b0: /* original 64f3, guest PC 0x0c0614b0 */
if(!s->budget--) { s->failed_pc=0x0c0614b0u; return 0; }
r[4]=r[15];
goto P_0c0614b2;
P_0c0614b2: /* original 430b, guest PC 0x0c0614b2 */
if(!s->budget--) { s->failed_pc=0x0c0614b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0614b6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0614b6u) { target=s->pc; goto dispatch; }
goto P_0c0614b6;
P_0c0614b4: /* original 7408, guest PC 0x0c0614b4 */
if(!s->budget--) { s->failed_pc=0x0c0614b4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0614b6;
P_0c0614b6: /* original d24e, guest PC 0x0c0614b6 */
if(!s->budget--) { s->failed_pc=0x0c0614b6u; return 0; }
r[2]=read(ram,0x0c0615f0u,4);
goto P_0c0614b8;
P_0c0614b8: /* original 6422, guest PC 0x0c0614b8 */
if(!s->budget--) { s->failed_pc=0x0c0614b8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0614ba;
P_0c0614ba: /* original 2448, guest PC 0x0c0614ba */
if(!s->budget--) { s->failed_pc=0x0c0614bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614bc;
P_0c0614bc: /* original 8d1e, guest PC 0x0c0614bc */
if(!s->budget--) { s->failed_pc=0x0c0614bcu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(cond) { goto P_0c0614fc; }
goto P_0c0614c0;
P_0c0614be: /* original ee00, guest PC 0x0c0614be */
if(!s->budget--) { s->failed_pc=0x0c0614beu; return 0; }
r[14]=0x00000000u;
goto P_0c0614c0;
P_0c0614c0: /* original d74c, guest PC 0x0c0614c0 */
if(!s->budget--) { s->failed_pc=0x0c0614c0u; return 0; }
r[7]=read(ram,0x0c0615f4u,4);
goto P_0c0614c2;
P_0c0614c2: /* original 6241, guest PC 0x0c0614c2 */
if(!s->budget--) { s->failed_pc=0x0c0614c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c0614c4;
P_0c0614c4: /* original 53f2, guest PC 0x0c0614c4 */
if(!s->budget--) { s->failed_pc=0x0c0614c4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0614c6;
P_0c0614c6: /* original 622d, guest PC 0x0c0614c6 */
if(!s->budget--) { s->failed_pc=0x0c0614c6u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0614c8;
P_0c0614c8: /* original 2279, guest PC 0x0c0614c8 */
if(!s->budget--) { s->failed_pc=0x0c0614c8u; return 0; }
r[2]&=r[7];
goto P_0c0614ca;
P_0c0614ca: /* original 3230, guest PC 0x0c0614ca */
if(!s->budget--) { s->failed_pc=0x0c0614cau; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0614cc;
P_0c0614cc: /* original 8b11, guest PC 0x0c0614cc */
if(!s->budget--) { s->failed_pc=0x0c0614ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f2; }
goto P_0c0614ce;
P_0c0614ce: /* original e500, guest PC 0x0c0614ce */
if(!s->budget--) { s->failed_pc=0x0c0614ceu; return 0; }
r[5]=0x00000000u;
goto P_0c0614d0;
P_0c0614d0: /* original a00d, guest PC 0x0c0614d0 */
if(!s->budget--) { s->failed_pc=0x0c0614d0u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614ee;
P_0c0614d2: /* original 56f6, guest PC 0x0c0614d2 */
if(!s->budget--) { s->failed_pc=0x0c0614d2u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c0614d4;
P_0c0614d4: /* original 6253, guest PC 0x0c0614d4 */
if(!s->budget--) { s->failed_pc=0x0c0614d4u; return 0; }
r[2]=r[5];
goto P_0c0614d6;
P_0c0614d6: /* original 4208, guest PC 0x0c0614d6 */
if(!s->budget--) { s->failed_pc=0x0c0614d6u; return 0; }
r[2]<<=2;
goto P_0c0614d8;
P_0c0614d8: /* original 6343, guest PC 0x0c0614d8 */
if(!s->budget--) { s->failed_pc=0x0c0614d8u; return 0; }
r[3]=r[4];
goto P_0c0614da;
P_0c0614da: /* original 730c, guest PC 0x0c0614da */
if(!s->budget--) { s->failed_pc=0x0c0614dau; return 0; }
r[3]+=0x0000000cu;
goto P_0c0614dc;
P_0c0614dc: /* original 323c, guest PC 0x0c0614dc */
if(!s->budget--) { s->failed_pc=0x0c0614dcu; return 0; }
r[2]+=r[3];
goto P_0c0614de;
P_0c0614de: /* original 6122, guest PC 0x0c0614de */
if(!s->budget--) { s->failed_pc=0x0c0614deu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0614e0;
P_0c0614e0: /* original 2118, guest PC 0x0c0614e0 */
if(!s->budget--) { s->failed_pc=0x0c0614e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0614e2;
P_0c0614e2: /* original 8b03, guest PC 0x0c0614e2 */
if(!s->budget--) { s->failed_pc=0x0c0614e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614ec; }
goto P_0c0614e4;
P_0c0614e4: /* original 6e43, guest PC 0x0c0614e4 */
if(!s->budget--) { s->failed_pc=0x0c0614e4u; return 0; }
r[14]=r[4];
goto P_0c0614e6;
P_0c0614e6: /* original 6d53, guest PC 0x0c0614e6 */
if(!s->budget--) { s->failed_pc=0x0c0614e6u; return 0; }
r[13]=r[5];
goto P_0c0614e8;
P_0c0614e8: /* original 6563, guest PC 0x0c0614e8 */
if(!s->budget--) { s->failed_pc=0x0c0614e8u; return 0; }
r[5]=r[6];
goto P_0c0614ea;
P_0c0614ea: /* original e400, guest PC 0x0c0614ea */
if(!s->budget--) { s->failed_pc=0x0c0614eau; return 0; }
r[4]=0x00000000u;
goto P_0c0614ec;
P_0c0614ec: /* original 7501, guest PC 0x0c0614ec */
if(!s->budget--) { s->failed_pc=0x0c0614ecu; return 0; }
r[5]+=0x00000001u;
goto P_0c0614ee;
P_0c0614ee: /* original 3562, guest PC 0x0c0614ee */
if(!s->budget--) { s->failed_pc=0x0c0614eeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[6])!=0);
goto P_0c0614f0;
P_0c0614f0: /* original 8bf0, guest PC 0x0c0614f0 */
if(!s->budget--) { s->failed_pc=0x0c0614f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614d4; }
goto P_0c0614f2;
P_0c0614f2: /* original 2ee8, guest PC 0x0c0614f2 */
if(!s->budget--) { s->failed_pc=0x0c0614f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614f4;
P_0c0614f4: /* original 8b00, guest PC 0x0c0614f4 */
if(!s->budget--) { s->failed_pc=0x0c0614f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614f8; }
goto P_0c0614f6;
P_0c0614f6: /* original 5441, guest PC 0x0c0614f6 */
if(!s->budget--) { s->failed_pc=0x0c0614f6u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0614f8;
P_0c0614f8: /* original 2448, guest PC 0x0c0614f8 */
if(!s->budget--) { s->failed_pc=0x0c0614f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0614fa;
P_0c0614fa: /* original 8be2, guest PC 0x0c0614fa */
if(!s->budget--) { s->failed_pc=0x0c0614fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0614c2; }
goto P_0c0614fc;
P_0c0614fc: /* original 2ee8, guest PC 0x0c0614fc */
if(!s->budget--) { s->failed_pc=0x0c0614fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0614fe;
P_0c0614fe: /* original 8b32, guest PC 0x0c0614fe */
if(!s->budget--) { s->failed_pc=0x0c0614feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061566; }
goto P_0c061500;
P_0c061500: /* original d33d, guest PC 0x0c061500 */
if(!s->budget--) { s->failed_pc=0x0c061500u; return 0; }
r[3]=read(ram,0x0c0615f8u,4);
goto P_0c061502;
P_0c061502: /* original 430b, guest PC 0x0c061502 */
if(!s->budget--) { s->failed_pc=0x0c061502u; return 0; }
target=r[3];
r[16]=code_base|0x0c061506u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061506u) { target=s->pc; goto dispatch; }
goto P_0c061506;
P_0c061504: /* original 0009, guest PC 0x0c061504 */
if(!s->budget--) { s->failed_pc=0x0c061504u; return 0; }
goto P_0c061506;
P_0c061506: /* original 6e03, guest PC 0x0c061506 */
if(!s->budget--) { s->failed_pc=0x0c061506u; return 0; }
r[14]=r[0];
goto P_0c061508;
P_0c061508: /* original 2ee8, guest PC 0x0c061508 */
if(!s->budget--) { s->failed_pc=0x0c061508u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06150a;
P_0c06150a: /* original 892a, guest PC 0x0c06150a */
if(!s->budget--) { s->failed_pc=0x0c06150au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061562; }
goto P_0c06150c;
P_0c06150c: /* original a001, guest PC 0x0c06150c */
if(!s->budget--) { s->failed_pc=0x0c06150cu; return 0; }
r[4]=0x00000010u;
goto P_0c061512;
P_0c06150e: /* original e410, guest PC 0x0c06150e */
if(!s->budget--) { s->failed_pc=0x0c06150eu; return 0; }
r[4]=0x00000010u;
goto P_0c061510;
P_0c061510: /* original 74ff, guest PC 0x0c061510 */
if(!s->budget--) { s->failed_pc=0x0c061510u; return 0; }
r[4]+=0xffffffffu;
goto P_0c061512;
P_0c061512: /* original 2448, guest PC 0x0c061512 */
if(!s->budget--) { s->failed_pc=0x0c061512u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061514;
P_0c061514: /* original 8bfc, guest PC 0x0c061514 */
if(!s->budget--) { s->failed_pc=0x0c061514u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061510; }
goto P_0c061516;
P_0c061516: /* original ed00, guest PC 0x0c061516 */
if(!s->budget--) { s->failed_pc=0x0c061516u; return 0; }
r[13]=0x00000000u;
goto P_0c061518;
P_0c061518: /* original d435, guest PC 0x0c061518 */
if(!s->budget--) { s->failed_pc=0x0c061518u; return 0; }
r[4]=read(ram,0x0c0615f0u,4);
goto P_0c06151a;
P_0c06151a: /* original d238, guest PC 0x0c06151a */
if(!s->budget--) { s->failed_pc=0x0c06151au; return 0; }
r[2]=read(ram,0x0c0615fcu,4);
goto P_0c06151c;
P_0c06151c: /* original 420b, guest PC 0x0c06151c */
if(!s->budget--) { s->failed_pc=0x0c06151cu; return 0; }
target=r[2];
r[16]=code_base|0x0c061520u;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061520u) { target=s->pc; goto dispatch; }
goto P_0c061520;
P_0c06151e: /* original 65e3, guest PC 0x0c06151e */
if(!s->budget--) { s->failed_pc=0x0c06151eu; return 0; }
r[5]=r[14];
goto P_0c061520;
P_0c061520: /* original 53f2, guest PC 0x0c061520 */
if(!s->budget--) { s->failed_pc=0x0c061520u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c061522;
P_0c061522: /* original 62e1, guest PC 0x0c061522 */
if(!s->budget--) { s->failed_pc=0x0c061522u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c061524;
P_0c061524: /* original 223b, guest PC 0x0c061524 */
if(!s->budget--) { s->failed_pc=0x0c061524u; return 0; }
r[2]|=r[3];
goto P_0c061526;
P_0c061526: /* original 2e21, guest PC 0x0c061526 */
if(!s->budget--) { s->failed_pc=0x0c061526u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c061528;
P_0c061528: /* original 5cf5, guest PC 0x0c061528 */
if(!s->budget--) { s->failed_pc=0x0c061528u; return 0; }
r[12]=read(ram,r[15]+20,4);
goto P_0c06152a;
P_0c06152a: /* original d335, guest PC 0x0c06152a */
if(!s->budget--) { s->failed_pc=0x0c06152au; return 0; }
r[3]=read(ram,0x0c061600u,4);
goto P_0c06152c;
P_0c06152c: /* original 6032, guest PC 0x0c06152c */
if(!s->budget--) { s->failed_pc=0x0c06152cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06152e;
P_0c06152e: /* original c804, guest PC 0x0c06152e */
if(!s->budget--) { s->failed_pc=0x0c06152eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c061530;
P_0c061530: /* original 890d, guest PC 0x0c061530 */
if(!s->budget--) { s->failed_pc=0x0c061530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06154e; }
goto P_0c061532;
P_0c061532: /* original 65f3, guest PC 0x0c061532 */
if(!s->budget--) { s->failed_pc=0x0c061532u; return 0; }
r[5]=r[15];
goto P_0c061534;
P_0c061534: /* original 7504, guest PC 0x0c061534 */
if(!s->budget--) { s->failed_pc=0x0c061534u; return 0; }
r[5]+=0x00000004u;
goto P_0c061536;
P_0c061536: /* original b1eb, guest PC 0x0c061536 */
if(!s->budget--) { s->failed_pc=0x0c061536u; return 0; }
target=code_base|0x0c061910u; r[16]=code_base|0x0c06153au;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06153au) { target=s->pc; goto dispatch; }
goto P_0c06153a;
P_0c061538: /* original 64f3, guest PC 0x0c061538 */
if(!s->budget--) { s->failed_pc=0x0c061538u; return 0; }
r[4]=r[15];
goto P_0c06153a;
P_0c06153a: /* original 53f1, guest PC 0x0c06153a */
if(!s->budget--) { s->failed_pc=0x0c06153au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06153c;
P_0c06153c: /* original 62f2, guest PC 0x0c06153c */
if(!s->budget--) { s->failed_pc=0x0c06153cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06153e;
P_0c06153e: /* original 3233, guest PC 0x0c06153e */
if(!s->budget--) { s->failed_pc=0x0c06153eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c061540;
P_0c061540: /* original 8b05, guest PC 0x0c061540 */
if(!s->budget--) { s->failed_pc=0x0c061540u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06154e; }
goto P_0c061542;
P_0c061542: /* original 66e3, guest PC 0x0c061542 */
if(!s->budget--) { s->failed_pc=0x0c061542u; return 0; }
r[6]=r[14];
goto P_0c061544;
P_0c061544: /* original 65c3, guest PC 0x0c061544 */
if(!s->budget--) { s->failed_pc=0x0c061544u; return 0; }
r[5]=r[12];
goto P_0c061546;
P_0c061546: /* original b5cd, guest PC 0x0c061546 */
if(!s->budget--) { s->failed_pc=0x0c061546u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c06154au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06154au) { target=s->pc; goto dispatch; }
goto P_0c06154a;
P_0c061548: /* original e400, guest PC 0x0c061548 */
if(!s->budget--) { s->failed_pc=0x0c061548u; return 0; }
r[4]=0x00000000u;
goto P_0c06154a;
P_0c06154a: /* original a005, guest PC 0x0c06154a */
if(!s->budget--) { s->failed_pc=0x0c06154au; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c06154c: /* original 6403, guest PC 0x0c06154c */
if(!s->budget--) { s->failed_pc=0x0c06154cu; return 0; }
r[4]=r[0];
goto P_0c06154e;
P_0c06154e: /* original 66e3, guest PC 0x0c06154e */
if(!s->budget--) { s->failed_pc=0x0c06154eu; return 0; }
r[6]=r[14];
goto P_0c061550;
P_0c061550: /* original 65c3, guest PC 0x0c061550 */
if(!s->budget--) { s->failed_pc=0x0c061550u; return 0; }
r[5]=r[12];
goto P_0c061552;
P_0c061552: /* original b5c7, guest PC 0x0c061552 */
if(!s->budget--) { s->failed_pc=0x0c061552u; return 0; }
target=code_base|0x0c0620e4u; r[16]=code_base|0x0c061556u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061556u) { target=s->pc; goto dispatch; }
goto P_0c061556;
P_0c061554: /* original e401, guest PC 0x0c061554 */
if(!s->budget--) { s->failed_pc=0x0c061554u; return 0; }
r[4]=0x00000001u;
goto P_0c061556;
P_0c061556: /* original 6403, guest PC 0x0c061556 */
if(!s->budget--) { s->failed_pc=0x0c061556u; return 0; }
r[4]=r[0];
goto P_0c061558;
P_0c061558: /* original 2448, guest PC 0x0c061558 */
if(!s->budget--) { s->failed_pc=0x0c061558u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06155a;
P_0c06155a: /* original 8904, guest PC 0x0c06155a */
if(!s->budget--) { s->failed_pc=0x0c06155au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c061566; }
goto P_0c06155c;
P_0c06155c: /* original d229, guest PC 0x0c06155c */
if(!s->budget--) { s->failed_pc=0x0c06155cu; return 0; }
r[2]=read(ram,0x0c061604u,4);
goto P_0c06155e;
P_0c06155e: /* original 420b, guest PC 0x0c06155e */
if(!s->budget--) { s->failed_pc=0x0c06155eu; return 0; }
target=r[2];
r[16]=code_base|0x0c061562u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c061562u) { target=s->pc; goto dispatch; }
goto P_0c061562;
P_0c061560: /* original 64e3, guest PC 0x0c061560 */
if(!s->budget--) { s->failed_pc=0x0c061560u; return 0; }
r[4]=r[14];
goto P_0c061562;
P_0c061562: /* original a011, guest PC 0x0c061562 */
if(!s->budget--) { s->failed_pc=0x0c061562u; return 0; }
r[0]=0x00000003u;
goto P_0c061588;
P_0c061564: /* original e003, guest PC 0x0c061564 */
if(!s->budget--) { s->failed_pc=0x0c061564u; return 0; }
r[0]=0x00000003u;
goto P_0c061566;
P_0c061566: /* original 53f3, guest PC 0x0c061566 */
if(!s->budget--) { s->failed_pc=0x0c061566u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c061568;
P_0c061568: /* original 52e2, guest PC 0x0c061568 */
if(!s->budget--) { s->failed_pc=0x0c061568u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c06156a;
P_0c06156a: /* original 4309, guest PC 0x0c06156a */
if(!s->budget--) { s->failed_pc=0x0c06156au; return 0; }
r[3]>>=2;
goto P_0c06156c;
P_0c06156c: /* original 0d37, guest PC 0x0c06156c */
if(!s->budget--) { s->failed_pc=0x0c06156cu; return 0; }
r[19]=r[13]*r[3];
goto P_0c06156e;
P_0c06156e: /* original 4d08, guest PC 0x0c06156e */
if(!s->budget--) { s->failed_pc=0x0c06156eu; return 0; }
r[13]<<=2;
goto P_0c061570;
P_0c061570: /* original 031a, guest PC 0x0c061570 */
if(!s->budget--) { s->failed_pc=0x0c061570u; return 0; }
r[3]=r[19];
goto P_0c061572;
P_0c061572: /* original 4308, guest PC 0x0c061572 */
if(!s->budget--) { s->failed_pc=0x0c061572u; return 0; }
r[3]<<=2;
goto P_0c061574;
P_0c061574: /* original 332c, guest PC 0x0c061574 */
if(!s->budget--) { s->failed_pc=0x0c061574u; return 0; }
r[3]+=r[2];
goto P_0c061576;
P_0c061576: /* original 1b37, guest PC 0x0c061576 */
if(!s->budget--) { s->failed_pc=0x0c061576u; return 0; }
write(ram,r[11]+28,r[3],4);
goto P_0c061578;
P_0c061578: /* original 63e3, guest PC 0x0c061578 */
if(!s->budget--) { s->failed_pc=0x0c061578u; return 0; }
r[3]=r[14];
goto P_0c06157a;
P_0c06157a: /* original 730c, guest PC 0x0c06157a */
if(!s->budget--) { s->failed_pc=0x0c06157au; return 0; }
r[3]+=0x0000000cu;
goto P_0c06157c;
P_0c06157c: /* original 3d3c, guest PC 0x0c06157c */
if(!s->budget--) { s->failed_pc=0x0c06157cu; return 0; }
r[13]+=r[3];
goto P_0c06157e;
P_0c06157e: /* original 2db2, guest PC 0x0c06157e */
if(!s->budget--) { s->failed_pc=0x0c06157eu; return 0; }
write(ram,r[13],r[11],4);
goto P_0c061580;
P_0c061580: /* original 60e1, guest PC 0x0c061580 */
if(!s->budget--) { s->failed_pc=0x0c061580u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c061582;
P_0c061582: /* original cb02, guest PC 0x0c061582 */
if(!s->budget--) { s->failed_pc=0x0c061582u; return 0; }
r[0]|=2u;
goto P_0c061584;
P_0c061584: /* original 2e01, guest PC 0x0c061584 */
if(!s->budget--) { s->failed_pc=0x0c061584u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c061586;
P_0c061586: /* original e000, guest PC 0x0c061586 */
if(!s->budget--) { s->failed_pc=0x0c061586u; return 0; }
r[0]=0x00000000u;
goto P_0c061588;
P_0c061588: /* original 7f1c, guest PC 0x0c061588 */
if(!s->budget--) { s->failed_pc=0x0c061588u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06158a;
P_0c06158a: /* original 4f26, guest PC 0x0c06158a */
if(!s->budget--) { s->failed_pc=0x0c06158au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06158c;
P_0c06158c: /* original 6bf6, guest PC 0x0c06158c */
if(!s->budget--) { s->failed_pc=0x0c06158cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06158e;
P_0c06158e: /* original 6cf6, guest PC 0x0c06158e */
if(!s->budget--) { s->failed_pc=0x0c06158eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c061590;
P_0c061590: /* original 6df6, guest PC 0x0c061590 */
if(!s->budget--) { s->failed_pc=0x0c061590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c061592;
P_0c061592: /* original 000b, guest PC 0x0c061592 */
if(!s->budget--) { s->failed_pc=0x0c061592u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061594: /* original 6ef6, guest PC 0x0c061594 */
if(!s->budget--) { s->failed_pc=0x0c061594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c061596;
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
unsupported: s->failed_pc=target; return 0;
}
