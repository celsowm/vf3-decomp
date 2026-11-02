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
int vf3_away_batch7_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0655d0u: goto P_0c0655d0;
case 0x0c0655d2u: goto P_0c0655d2;
case 0x0c0655d4u: goto P_0c0655d4;
case 0x0c0655d6u: goto P_0c0655d6;
case 0x0c0655d8u: goto P_0c0655d8;
case 0x0c0655dau: goto P_0c0655da;
case 0x0c0655dcu: goto P_0c0655dc;
case 0x0c0655deu: goto P_0c0655de;
case 0x0c0655e0u: goto P_0c0655e0;
case 0x0c0655e2u: goto P_0c0655e2;
case 0x0c0655e4u: goto P_0c0655e4;
case 0x0c0655e6u: goto P_0c0655e6;
case 0x0c0655e8u: goto P_0c0655e8;
case 0x0c0655eau: goto P_0c0655ea;
case 0x0c0655ecu: goto P_0c0655ec;
case 0x0c0655eeu: goto P_0c0655ee;
case 0x0c0655f0u: goto P_0c0655f0;
case 0x0c0655f2u: goto P_0c0655f2;
case 0x0c0655f4u: goto P_0c0655f4;
case 0x0c0655f6u: goto P_0c0655f6;
case 0x0c0655f8u: goto P_0c0655f8;
case 0x0c0655fau: goto P_0c0655fa;
case 0x0c0655fcu: goto P_0c0655fc;
case 0x0c0655feu: goto P_0c0655fe;
case 0x0c065600u: goto P_0c065600;
case 0x0c065602u: goto P_0c065602;
case 0x0c065604u: goto P_0c065604;
case 0x0c065606u: goto P_0c065606;
case 0x0c065608u: goto P_0c065608;
case 0x0c06560au: goto P_0c06560a;
case 0x0c06560cu: goto P_0c06560c;
case 0x0c06560eu: goto P_0c06560e;
case 0x0c065610u: goto P_0c065610;
case 0x0c065612u: goto P_0c065612;
case 0x0c065614u: goto P_0c065614;
case 0x0c065616u: goto P_0c065616;
case 0x0c065618u: goto P_0c065618;
case 0x0c06561au: goto P_0c06561a;
case 0x0c06561cu: goto P_0c06561c;
case 0x0c06561eu: goto P_0c06561e;
case 0x0c065620u: goto P_0c065620;
case 0x0c065622u: goto P_0c065622;
case 0x0c065624u: goto P_0c065624;
case 0x0c065626u: goto P_0c065626;
case 0x0c065628u: goto P_0c065628;
case 0x0c06562au: goto P_0c06562a;
case 0x0c06562cu: goto P_0c06562c;
case 0x0c06562eu: goto P_0c06562e;
case 0x0c065630u: goto P_0c065630;
case 0x0c065632u: goto P_0c065632;
case 0x0c065634u: goto P_0c065634;
case 0x0c065636u: goto P_0c065636;
case 0x0c065638u: goto P_0c065638;
case 0x0c06563au: goto P_0c06563a;
case 0x0c06563cu: goto P_0c06563c;
case 0x0c06563eu: goto P_0c06563e;
case 0x0c065640u: goto P_0c065640;
case 0x0c065642u: goto P_0c065642;
case 0x0c065644u: goto P_0c065644;
case 0x0c065646u: goto P_0c065646;
case 0x0c065648u: goto P_0c065648;
case 0x0c06564au: goto P_0c06564a;
case 0x0c06564cu: goto P_0c06564c;
case 0x0c06564eu: goto P_0c06564e;
case 0x0c065650u: goto P_0c065650;
case 0x0c065652u: goto P_0c065652;
case 0x0c065654u: goto P_0c065654;
case 0x0c065656u: goto P_0c065656;
case 0x0c065658u: goto P_0c065658;
case 0x0c06565au: goto P_0c06565a;
case 0x0c06565cu: goto P_0c06565c;
case 0x0c06565eu: goto P_0c06565e;
case 0x0c065660u: goto P_0c065660;
case 0x0c065662u: goto P_0c065662;
case 0x0c065664u: goto P_0c065664;
case 0x0c065666u: goto P_0c065666;
case 0x0c065668u: goto P_0c065668;
case 0x0c06566au: goto P_0c06566a;
case 0x0c06566cu: goto P_0c06566c;
case 0x0c06566eu: goto P_0c06566e;
case 0x0c065670u: goto P_0c065670;
case 0x0c065672u: goto P_0c065672;
case 0x0c065674u: goto P_0c065674;
case 0x0c065676u: goto P_0c065676;
case 0x0c065678u: goto P_0c065678;
case 0x0c06567au: goto P_0c06567a;
case 0x0c06567cu: goto P_0c06567c;
case 0x0c06567eu: goto P_0c06567e;
case 0x0c065680u: goto P_0c065680;
case 0x0c065682u: goto P_0c065682;
case 0x0c065684u: goto P_0c065684;
case 0x0c065686u: goto P_0c065686;
case 0x0c065688u: goto P_0c065688;
case 0x0c06568au: goto P_0c06568a;
case 0x0c06568cu: goto P_0c06568c;
case 0x0c06568eu: goto P_0c06568e;
case 0x0c065690u: goto P_0c065690;
case 0x0c065692u: goto P_0c065692;
case 0x0c065694u: goto P_0c065694;
case 0x0c065696u: goto P_0c065696;
case 0x0c065698u: goto P_0c065698;
case 0x0c06569au: goto P_0c06569a;
case 0x0c06569cu: goto P_0c06569c;
case 0x0c06569eu: goto P_0c06569e;
case 0x0c0656a0u: goto P_0c0656a0;
case 0x0c0656a2u: goto P_0c0656a2;
case 0x0c0656a4u: goto P_0c0656a4;
case 0x0c0656a6u: goto P_0c0656a6;
case 0x0c0656a8u: goto P_0c0656a8;
case 0x0c0656aau: goto P_0c0656aa;
case 0x0c0656acu: goto P_0c0656ac;
case 0x0c0656aeu: goto P_0c0656ae;
case 0x0c0656b0u: goto P_0c0656b0;
case 0x0c0656b2u: goto P_0c0656b2;
case 0x0c0656b4u: goto P_0c0656b4;
case 0x0c0656b6u: goto P_0c0656b6;
case 0x0c0656b8u: goto P_0c0656b8;
case 0x0c0656bau: goto P_0c0656ba;
case 0x0c0656bcu: goto P_0c0656bc;
case 0x0c0656beu: goto P_0c0656be;
case 0x0c0656c0u: goto P_0c0656c0;
case 0x0c0656c2u: goto P_0c0656c2;
case 0x0c0656c4u: goto P_0c0656c4;
case 0x0c0656c6u: goto P_0c0656c6;
case 0x0c0656c8u: goto P_0c0656c8;
case 0x0c0656cau: goto P_0c0656ca;
case 0x0c0656ccu: goto P_0c0656cc;
case 0x0c0656ceu: goto P_0c0656ce;
case 0x0c0656d0u: goto P_0c0656d0;
case 0x0c0656d2u: goto P_0c0656d2;
case 0x0c0656d4u: goto P_0c0656d4;
case 0x0c0656d6u: goto P_0c0656d6;
case 0x0c0656d8u: goto P_0c0656d8;
case 0x0c0656dau: goto P_0c0656da;
case 0x0c0656dcu: goto P_0c0656dc;
case 0x0c0656deu: goto P_0c0656de;
case 0x0c0656e0u: goto P_0c0656e0;
case 0x0c0656e2u: goto P_0c0656e2;
case 0x0c0656e4u: goto P_0c0656e4;
case 0x0c0656e6u: goto P_0c0656e6;
case 0x0c0656e8u: goto P_0c0656e8;
case 0x0c0656eau: goto P_0c0656ea;
case 0x0c0656ecu: goto P_0c0656ec;
case 0x0c0656eeu: goto P_0c0656ee;
case 0x0c0656f0u: goto P_0c0656f0;
case 0x0c0656f2u: goto P_0c0656f2;
case 0x0c0656f4u: goto P_0c0656f4;
case 0x0c0656f6u: goto P_0c0656f6;
case 0x0c0656f8u: goto P_0c0656f8;
case 0x0c0656fau: goto P_0c0656fa;
case 0x0c0656fcu: goto P_0c0656fc;
case 0x0c0656feu: goto P_0c0656fe;
case 0x0c065700u: goto P_0c065700;
case 0x0c065702u: goto P_0c065702;
case 0x0c065704u: goto P_0c065704;
case 0x0c065706u: goto P_0c065706;
case 0x0c065708u: goto P_0c065708;
case 0x0c06570au: goto P_0c06570a;
case 0x0c06570cu: goto P_0c06570c;
case 0x0c06570eu: goto P_0c06570e;
case 0x0c065710u: goto P_0c065710;
case 0x0c065712u: goto P_0c065712;
case 0x0c065714u: goto P_0c065714;
case 0x0c065716u: goto P_0c065716;
case 0x0c065718u: goto P_0c065718;
case 0x0c06571au: goto P_0c06571a;
case 0x0c06571cu: goto P_0c06571c;
case 0x0c06571eu: goto P_0c06571e;
case 0x0c065720u: goto P_0c065720;
case 0x0c065722u: goto P_0c065722;
case 0x0c065724u: goto P_0c065724;
case 0x0c065726u: goto P_0c065726;
case 0x0c065728u: goto P_0c065728;
case 0x0c06572au: goto P_0c06572a;
case 0x0c06572cu: goto P_0c06572c;
case 0x0c06572eu: goto P_0c06572e;
case 0x0c065730u: goto P_0c065730;
case 0x0c065732u: goto P_0c065732;
case 0x0c065734u: goto P_0c065734;
case 0x0c065736u: goto P_0c065736;
case 0x0c065738u: goto P_0c065738;
case 0x0c06573au: goto P_0c06573a;
case 0x0c06573cu: goto P_0c06573c;
case 0x0c06573eu: goto P_0c06573e;
case 0x0c065740u: goto P_0c065740;
case 0x0c065742u: goto P_0c065742;
case 0x0c065744u: goto P_0c065744;
case 0x0c065746u: goto P_0c065746;
case 0x0c065748u: goto P_0c065748;
case 0x0c06574au: goto P_0c06574a;
case 0x0c06574cu: goto P_0c06574c;
case 0x0c06574eu: goto P_0c06574e;
case 0x0c065750u: goto P_0c065750;
case 0x0c065752u: goto P_0c065752;
case 0x0c065754u: goto P_0c065754;
case 0x0c065756u: goto P_0c065756;
case 0x0c065758u: goto P_0c065758;
case 0x0c06575au: goto P_0c06575a;
case 0x0c06575cu: goto P_0c06575c;
case 0x0c06575eu: goto P_0c06575e;
case 0x0c065760u: goto P_0c065760;
case 0x0c065762u: goto P_0c065762;
case 0x0c065764u: goto P_0c065764;
case 0x0c065766u: goto P_0c065766;
case 0x0c065768u: goto P_0c065768;
case 0x0c06576au: goto P_0c06576a;
case 0x0c06576cu: goto P_0c06576c;
case 0x0c06576eu: goto P_0c06576e;
case 0x0c065770u: goto P_0c065770;
case 0x0c065772u: goto P_0c065772;
case 0x0c065774u: goto P_0c065774;
case 0x0c065776u: goto P_0c065776;
case 0x0c065778u: goto P_0c065778;
case 0x0c06577au: goto P_0c06577a;
case 0x0c06577cu: goto P_0c06577c;
case 0x0c06577eu: goto P_0c06577e;
case 0x0c065780u: goto P_0c065780;
case 0x0c065782u: goto P_0c065782;
case 0x0c065784u: goto P_0c065784;
case 0x0c065786u: goto P_0c065786;
case 0x0c065788u: goto P_0c065788;
case 0x0c06578au: goto P_0c06578a;
case 0x0c06578cu: goto P_0c06578c;
case 0x0c06578eu: goto P_0c06578e;
case 0x0c065790u: goto P_0c065790;
case 0x0c065792u: goto P_0c065792;
case 0x0c065794u: goto P_0c065794;
case 0x0c065796u: goto P_0c065796;
case 0x0c065798u: goto P_0c065798;
case 0x0c06579au: goto P_0c06579a;
case 0x0c06579cu: goto P_0c06579c;
case 0x0c06579eu: goto P_0c06579e;
case 0x0c0657a0u: goto P_0c0657a0;
case 0x0c0657a2u: goto P_0c0657a2;
case 0x0c0657a4u: goto P_0c0657a4;
case 0x0c0657a6u: goto P_0c0657a6;
case 0x0c0657a8u: goto P_0c0657a8;
case 0x0c0657aau: goto P_0c0657aa;
case 0x0c0657acu: goto P_0c0657ac;
case 0x0c0657aeu: goto P_0c0657ae;
case 0x0c0657b0u: goto P_0c0657b0;
case 0x0c0657b2u: goto P_0c0657b2;
case 0x0c0657b4u: goto P_0c0657b4;
case 0x0c0657b6u: goto P_0c0657b6;
case 0x0c0657b8u: goto P_0c0657b8;
case 0x0c0657bau: goto P_0c0657ba;
case 0x0c0657bcu: goto P_0c0657bc;
case 0x0c0657beu: goto P_0c0657be;
case 0x0c0657c0u: goto P_0c0657c0;
case 0x0c0657c2u: goto P_0c0657c2;
case 0x0c0657c4u: goto P_0c0657c4;
case 0x0c0657c6u: goto P_0c0657c6;
case 0x0c0657c8u: goto P_0c0657c8;
case 0x0c0657cau: goto P_0c0657ca;
case 0x0c0657ccu: goto P_0c0657cc;
case 0x0c0657ceu: goto P_0c0657ce;
case 0x0c0657d0u: goto P_0c0657d0;
case 0x0c0657d2u: goto P_0c0657d2;
case 0x0c0657d4u: goto P_0c0657d4;
case 0x0c0657d6u: goto P_0c0657d6;
case 0x0c0657d8u: goto P_0c0657d8;
case 0x0c0657dau: goto P_0c0657da;
case 0x0c0657dcu: goto P_0c0657dc;
case 0x0c0657deu: goto P_0c0657de;
case 0x0c0657e0u: goto P_0c0657e0;
case 0x0c0657e2u: goto P_0c0657e2;
case 0x0c0657e4u: goto P_0c0657e4;
case 0x0c0657e6u: goto P_0c0657e6;
case 0x0c0657e8u: goto P_0c0657e8;
case 0x0c0657eau: goto P_0c0657ea;
case 0x0c0657ecu: goto P_0c0657ec;
case 0x0c0657eeu: goto P_0c0657ee;
case 0x0c0657f0u: goto P_0c0657f0;
case 0x0c0657f2u: goto P_0c0657f2;
case 0x0c0657f4u: goto P_0c0657f4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0655d0: /* original 2fe6, guest PC 0x0c0655d0 */
if(!s->budget--) { s->failed_pc=0x0c0655d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655d2;
P_0c0655d2: /* original 2fd6, guest PC 0x0c0655d2 */
if(!s->budget--) { s->failed_pc=0x0c0655d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655d4;
P_0c0655d4: /* original 2fc6, guest PC 0x0c0655d4 */
if(!s->budget--) { s->failed_pc=0x0c0655d4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655d6;
P_0c0655d6: /* original ec00, guest PC 0x0c0655d6 */
if(!s->budget--) { s->failed_pc=0x0c0655d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0655d8;
P_0c0655d8: /* original 2fb6, guest PC 0x0c0655d8 */
if(!s->budget--) { s->failed_pc=0x0c0655d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655da;
P_0c0655da: /* original 2fa6, guest PC 0x0c0655da */
if(!s->budget--) { s->failed_pc=0x0c0655dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655dc;
P_0c0655dc: /* original 2f96, guest PC 0x0c0655dc */
if(!s->budget--) { s->failed_pc=0x0c0655dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0655de;
P_0c0655de: /* original fffb, guest PC 0x0c0655de */
if(!s->budget--) { s->failed_pc=0x0c0655deu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0655e0;
P_0c0655e0: /* original 4f22, guest PC 0x0c0655e0 */
if(!s->budget--) { s->failed_pc=0x0c0655e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0655e2;
P_0c0655e2: /* original 7ff4, guest PC 0x0c0655e2 */
if(!s->budget--) { s->failed_pc=0x0c0655e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0655e4;
P_0c0655e4: /* original 6342, guest PC 0x0c0655e4 */
if(!s->budget--) { s->failed_pc=0x0c0655e4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0655e6;
P_0c0655e6: /* original 65f3, guest PC 0x0c0655e6 */
if(!s->budget--) { s->failed_pc=0x0c0655e6u; return 0; }
r[5]=r[15];
goto P_0c0655e8;
P_0c0655e8: /* original 6e53, guest PC 0x0c0655e8 */
if(!s->budget--) { s->failed_pc=0x0c0655e8u; return 0; }
r[14]=r[5];
goto P_0c0655ea;
P_0c0655ea: /* original 6be3, guest PC 0x0c0655ea */
if(!s->budget--) { s->failed_pc=0x0c0655eau; return 0; }
r[11]=r[14];
goto P_0c0655ec;
P_0c0655ec: /* original 2e32, guest PC 0x0c0655ec */
if(!s->budget--) { s->failed_pc=0x0c0655ecu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0655ee;
P_0c0655ee: /* original 6ae3, guest PC 0x0c0655ee */
if(!s->budget--) { s->failed_pc=0x0c0655eeu; return 0; }
r[10]=r[14];
goto P_0c0655f0;
P_0c0655f0: /* original 5241, guest PC 0x0c0655f0 */
if(!s->budget--) { s->failed_pc=0x0c0655f0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0655f2;
P_0c0655f2: /* original 7b04, guest PC 0x0c0655f2 */
if(!s->budget--) { s->failed_pc=0x0c0655f2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0655f4;
P_0c0655f4: /* original 2b22, guest PC 0x0c0655f4 */
if(!s->budget--) { s->failed_pc=0x0c0655f4u; return 0; }
write(ram,r[11],r[2],4);
goto P_0c0655f6;
P_0c0655f6: /* original 7a08, guest PC 0x0c0655f6 */
if(!s->budget--) { s->failed_pc=0x0c0655f6u; return 0; }
r[10]+=0x00000008u;
goto P_0c0655f8;
P_0c0655f8: /* original 5342, guest PC 0x0c0655f8 */
if(!s->budget--) { s->failed_pc=0x0c0655f8u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0655fa;
P_0c0655fa: /* original 2a32, guest PC 0x0c0655fa */
if(!s->budget--) { s->failed_pc=0x0c0655fau; return 0; }
write(ram,r[10],r[3],4);
goto P_0c0655fc;
P_0c0655fc: /* original d2c0, guest PC 0x0c0655fc */
if(!s->budget--) { s->failed_pc=0x0c0655fcu; return 0; }
r[2]=read(ram,0x0c065900u,4);
goto P_0c0655fe;
P_0c0655fe: /* original 6d22, guest PC 0x0c0655fe */
if(!s->budget--) { s->failed_pc=0x0c0655feu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065600;
P_0c065600: /* original d3c0, guest PC 0x0c065600 */
if(!s->budget--) { s->failed_pc=0x0c065600u; return 0; }
r[3]=read(ram,0x0c065904u,4);
goto P_0c065602;
P_0c065602: /* original 6532, guest PC 0x0c065602 */
if(!s->budget--) { s->failed_pc=0x0c065602u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c065604;
P_0c065604: /* original d1c0, guest PC 0x0c065604 */
if(!s->budget--) { s->failed_pc=0x0c065604u; return 0; }
r[1]=read(ram,0x0c065908u,4);
goto P_0c065606;
P_0c065606: /* original 6412, guest PC 0x0c065606 */
if(!s->budget--) { s->failed_pc=0x0c065606u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c065608;
P_0c065608: /* original d0c0, guest PC 0x0c065608 */
if(!s->budget--) { s->failed_pc=0x0c065608u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06560a;
P_0c06560a: /* original 62c3, guest PC 0x0c06560a */
if(!s->budget--) { s->failed_pc=0x0c06560au; return 0; }
r[2]=r[12];
goto P_0c06560c;
P_0c06560c: /* original 7c01, guest PC 0x0c06560c */
if(!s->budget--) { s->failed_pc=0x0c06560cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06560e;
P_0c06560e: /* original 4208, guest PC 0x0c06560e */
if(!s->budget--) { s->failed_pc=0x0c06560eu; return 0; }
r[2]<<=2;
goto P_0c065610;
P_0c065610: /* original 02d6, guest PC 0x0c065610 */
if(!s->budget--) { s->failed_pc=0x0c065610u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065612;
P_0c065612: /* original 63c3, guest PC 0x0c065612 */
if(!s->budget--) { s->failed_pc=0x0c065612u; return 0; }
r[3]=r[12];
goto P_0c065614;
P_0c065614: /* original 7c01, guest PC 0x0c065614 */
if(!s->budget--) { s->failed_pc=0x0c065614u; return 0; }
r[12]+=0x00000001u;
goto P_0c065616;
P_0c065616: /* original 4308, guest PC 0x0c065616 */
if(!s->budget--) { s->failed_pc=0x0c065616u; return 0; }
r[3]<<=2;
goto P_0c065618;
P_0c065618: /* original 0356, guest PC 0x0c065618 */
if(!s->budget--) { s->failed_pc=0x0c065618u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c06561a;
P_0c06561a: /* original 62c3, guest PC 0x0c06561a */
if(!s->budget--) { s->failed_pc=0x0c06561au; return 0; }
r[2]=r[12];
goto P_0c06561c;
P_0c06561c: /* original 7c01, guest PC 0x0c06561c */
if(!s->budget--) { s->failed_pc=0x0c06561cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06561e;
P_0c06561e: /* original 4208, guest PC 0x0c06561e */
if(!s->budget--) { s->failed_pc=0x0c06561eu; return 0; }
r[2]<<=2;
goto P_0c065620;
P_0c065620: /* original 0246, guest PC 0x0c065620 */
if(!s->budget--) { s->failed_pc=0x0c065620u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c065622;
P_0c065622: /* original 63c3, guest PC 0x0c065622 */
if(!s->budget--) { s->failed_pc=0x0c065622u; return 0; }
r[3]=r[12];
goto P_0c065624;
P_0c065624: /* original 62e2, guest PC 0x0c065624 */
if(!s->budget--) { s->failed_pc=0x0c065624u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065626;
P_0c065626: /* original 7c01, guest PC 0x0c065626 */
if(!s->budget--) { s->failed_pc=0x0c065626u; return 0; }
r[12]+=0x00000001u;
goto P_0c065628;
P_0c065628: /* original 5221, guest PC 0x0c065628 */
if(!s->budget--) { s->failed_pc=0x0c065628u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c06562a;
P_0c06562a: /* original 4308, guest PC 0x0c06562a */
if(!s->budget--) { s->failed_pc=0x0c06562au; return 0; }
r[3]<<=2;
goto P_0c06562c;
P_0c06562c: /* original 0326, guest PC 0x0c06562c */
if(!s->budget--) { s->failed_pc=0x0c06562cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06562e;
P_0c06562e: /* original 63c3, guest PC 0x0c06562e */
if(!s->budget--) { s->failed_pc=0x0c06562eu; return 0; }
r[3]=r[12];
goto P_0c065630;
P_0c065630: /* original 62e2, guest PC 0x0c065630 */
if(!s->budget--) { s->failed_pc=0x0c065630u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065632;
P_0c065632: /* original 7c01, guest PC 0x0c065632 */
if(!s->budget--) { s->failed_pc=0x0c065632u; return 0; }
r[12]+=0x00000001u;
goto P_0c065634;
P_0c065634: /* original 5222, guest PC 0x0c065634 */
if(!s->budget--) { s->failed_pc=0x0c065634u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065636;
P_0c065636: /* original 4308, guest PC 0x0c065636 */
if(!s->budget--) { s->failed_pc=0x0c065636u; return 0; }
r[3]<<=2;
goto P_0c065638;
P_0c065638: /* original 0326, guest PC 0x0c065638 */
if(!s->budget--) { s->failed_pc=0x0c065638u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06563a;
P_0c06563a: /* original 63c3, guest PC 0x0c06563a */
if(!s->budget--) { s->failed_pc=0x0c06563au; return 0; }
r[3]=r[12];
goto P_0c06563c;
P_0c06563c: /* original 62e2, guest PC 0x0c06563c */
if(!s->budget--) { s->failed_pc=0x0c06563cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06563e;
P_0c06563e: /* original 7c01, guest PC 0x0c06563e */
if(!s->budget--) { s->failed_pc=0x0c06563eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065640;
P_0c065640: /* original 5223, guest PC 0x0c065640 */
if(!s->budget--) { s->failed_pc=0x0c065640u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065642;
P_0c065642: /* original 4308, guest PC 0x0c065642 */
if(!s->budget--) { s->failed_pc=0x0c065642u; return 0; }
r[3]<<=2;
goto P_0c065644;
P_0c065644: /* original 0326, guest PC 0x0c065644 */
if(!s->budget--) { s->failed_pc=0x0c065644u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065646;
P_0c065646: /* original 65c3, guest PC 0x0c065646 */
if(!s->budget--) { s->failed_pc=0x0c065646u; return 0; }
r[5]=r[12];
goto P_0c065648;
P_0c065648: /* original d3b1, guest PC 0x0c065648 */
if(!s->budget--) { s->failed_pc=0x0c065648u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c06564a;
P_0c06564a: /* original 66e2, guest PC 0x0c06564a */
if(!s->budget--) { s->failed_pc=0x0c06564au; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c06564c;
P_0c06564c: /* original 5664, guest PC 0x0c06564c */
if(!s->budget--) { s->failed_pc=0x0c06564cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c06564e;
P_0c06564e: /* original 430b, guest PC 0x0c06564e */
if(!s->budget--) { s->failed_pc=0x0c06564eu; return 0; }
target=r[3];
r[16]=code_base|0x0c065652u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065652u) { target=s->pc; goto dispatch; }
goto P_0c065652;
P_0c065650: /* original 64d3, guest PC 0x0c065650 */
if(!s->budget--) { s->failed_pc=0x0c065650u; return 0; }
r[4]=r[13];
goto P_0c065652;
P_0c065652: /* original 6903, guest PC 0x0c065652 */
if(!s->budget--) { s->failed_pc=0x0c065652u; return 0; }
r[9]=r[0];
goto P_0c065654;
P_0c065654: /* original 64e2, guest PC 0x0c065654 */
if(!s->budget--) { s->failed_pc=0x0c065654u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c065656;
P_0c065656: /* original e118, guest PC 0x0c065656 */
if(!s->budget--) { s->failed_pc=0x0c065656u; return 0; }
r[1]=0x00000018u;
goto P_0c065658;
P_0c065658: /* original c7ae, guest PC 0x0c065658 */
if(!s->budget--) { s->failed_pc=0x0c065658u; return 0; }
r[0]=code_base|0x00065914u;
goto P_0c06565a;
P_0c06565a: /* original 6393, guest PC 0x0c06565a */
if(!s->budget--) { s->failed_pc=0x0c06565au; return 0; }
r[3]=r[9];
goto P_0c06565c;
P_0c06565c: /* original ff08, guest PC 0x0c06565c */
if(!s->budget--) { s->failed_pc=0x0c06565cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06565e;
P_0c06565e: /* original 314c, guest PC 0x0c06565e */
if(!s->budget--) { s->failed_pc=0x0c06565eu; return 0; }
r[1]+=r[4];
goto P_0c065660;
P_0c065660: /* original d0aa, guest PC 0x0c065660 */
if(!s->budget--) { s->failed_pc=0x0c065660u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c065662;
P_0c065662: /* original 7901, guest PC 0x0c065662 */
if(!s->budget--) { s->failed_pc=0x0c065662u; return 0; }
r[9]+=0x00000001u;
goto P_0c065664;
P_0c065664: /* original f318, guest PC 0x0c065664 */
if(!s->budget--) { s->failed_pc=0x0c065664u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065666;
P_0c065666: /* original 4308, guest PC 0x0c065666 */
if(!s->budget--) { s->failed_pc=0x0c065666u; return 0; }
r[3]<<=2;
goto P_0c065668;
P_0c065668: /* original f3f2, guest PC 0x0c065668 */
if(!s->budget--) { s->failed_pc=0x0c065668u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06566a;
P_0c06566a: /* original f33d, guest PC 0x0c06566a */
if(!s->budget--) { s->failed_pc=0x0c06566au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06566c;
P_0c06566c: /* original 045a, guest PC 0x0c06566c */
if(!s->budget--) { s->failed_pc=0x0c06566cu; return 0; }
r[4]=r[53];
goto P_0c06566e;
P_0c06566e: /* original 6243, guest PC 0x0c06566e */
if(!s->budget--) { s->failed_pc=0x0c06566eu; return 0; }
r[2]=r[4];
goto P_0c065670;
P_0c065670: /* original 4228, guest PC 0x0c065670 */
if(!s->budget--) { s->failed_pc=0x0c065670u; return 0; }
r[2]<<=16;
goto P_0c065672;
P_0c065672: /* original 4218, guest PC 0x0c065672 */
if(!s->budget--) { s->failed_pc=0x0c065672u; return 0; }
r[2]<<=8;
goto P_0c065674;
P_0c065674: /* original 6143, guest PC 0x0c065674 */
if(!s->budget--) { s->failed_pc=0x0c065674u; return 0; }
r[1]=r[4];
goto P_0c065676;
P_0c065676: /* original 4128, guest PC 0x0c065676 */
if(!s->budget--) { s->failed_pc=0x0c065676u; return 0; }
r[1]<<=16;
goto P_0c065678;
P_0c065678: /* original 221b, guest PC 0x0c065678 */
if(!s->budget--) { s->failed_pc=0x0c065678u; return 0; }
r[2]|=r[1];
goto P_0c06567a;
P_0c06567a: /* original 6143, guest PC 0x0c06567a */
if(!s->budget--) { s->failed_pc=0x0c06567au; return 0; }
r[1]=r[4];
goto P_0c06567c;
P_0c06567c: /* original 4118, guest PC 0x0c06567c */
if(!s->budget--) { s->failed_pc=0x0c06567cu; return 0; }
r[1]<<=8;
goto P_0c06567e;
P_0c06567e: /* original 221b, guest PC 0x0c06567e */
if(!s->budget--) { s->failed_pc=0x0c06567eu; return 0; }
r[2]|=r[1];
goto P_0c065680;
P_0c065680: /* original 224b, guest PC 0x0c065680 */
if(!s->budget--) { s->failed_pc=0x0c065680u; return 0; }
r[2]|=r[4];
goto P_0c065682;
P_0c065682: /* original 0326, guest PC 0x0c065682 */
if(!s->budget--) { s->failed_pc=0x0c065682u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065684;
P_0c065684: /* original 6ce2, guest PC 0x0c065684 */
if(!s->budget--) { s->failed_pc=0x0c065684u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c065686;
P_0c065686: /* original e01c, guest PC 0x0c065686 */
if(!s->budget--) { s->failed_pc=0x0c065686u; return 0; }
r[0]=0x0000001cu;
goto P_0c065688;
P_0c065688: /* original f3c6, guest PC 0x0c065688 */
if(!s->budget--) { s->failed_pc=0x0c065688u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06568a;
P_0c06568a: /* original f3f2, guest PC 0x0c06568a */
if(!s->budget--) { s->failed_pc=0x0c06568au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06568c;
P_0c06568c: /* original f33d, guest PC 0x0c06568c */
if(!s->budget--) { s->failed_pc=0x0c06568cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06568e;
P_0c06568e: /* original 0c5a, guest PC 0x0c06568e */
if(!s->budget--) { s->failed_pc=0x0c06568eu; return 0; }
r[12]=r[53];
goto P_0c065690;
P_0c065690: /* original 66c3, guest PC 0x0c065690 */
if(!s->budget--) { s->failed_pc=0x0c065690u; return 0; }
r[6]=r[12];
goto P_0c065692;
P_0c065692: /* original 4628, guest PC 0x0c065692 */
if(!s->budget--) { s->failed_pc=0x0c065692u; return 0; }
r[6]<<=16;
goto P_0c065694;
P_0c065694: /* original 4618, guest PC 0x0c065694 */
if(!s->budget--) { s->failed_pc=0x0c065694u; return 0; }
r[6]<<=8;
goto P_0c065696;
P_0c065696: /* original 63c3, guest PC 0x0c065696 */
if(!s->budget--) { s->failed_pc=0x0c065696u; return 0; }
r[3]=r[12];
goto P_0c065698;
P_0c065698: /* original 4328, guest PC 0x0c065698 */
if(!s->budget--) { s->failed_pc=0x0c065698u; return 0; }
r[3]<<=16;
goto P_0c06569a;
P_0c06569a: /* original 263b, guest PC 0x0c06569a */
if(!s->budget--) { s->failed_pc=0x0c06569au; return 0; }
r[6]|=r[3];
goto P_0c06569c;
P_0c06569c: /* original d39e, guest PC 0x0c06569c */
if(!s->budget--) { s->failed_pc=0x0c06569cu; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c06569e;
P_0c06569e: /* original 62c3, guest PC 0x0c06569e */
if(!s->budget--) { s->failed_pc=0x0c06569eu; return 0; }
r[2]=r[12];
goto P_0c0656a0;
P_0c0656a0: /* original 4218, guest PC 0x0c0656a0 */
if(!s->budget--) { s->failed_pc=0x0c0656a0u; return 0; }
r[2]<<=8;
goto P_0c0656a2;
P_0c0656a2: /* original 262b, guest PC 0x0c0656a2 */
if(!s->budget--) { s->failed_pc=0x0c0656a2u; return 0; }
r[6]|=r[2];
goto P_0c0656a4;
P_0c0656a4: /* original 26cb, guest PC 0x0c0656a4 */
if(!s->budget--) { s->failed_pc=0x0c0656a4u; return 0; }
r[6]|=r[12];
goto P_0c0656a6;
P_0c0656a6: /* original 6593, guest PC 0x0c0656a6 */
if(!s->budget--) { s->failed_pc=0x0c0656a6u; return 0; }
r[5]=r[9];
goto P_0c0656a8;
P_0c0656a8: /* original 430b, guest PC 0x0c0656a8 */
if(!s->budget--) { s->failed_pc=0x0c0656a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0656acu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0656acu) { target=s->pc; goto dispatch; }
goto P_0c0656ac;
P_0c0656aa: /* original 64d3, guest PC 0x0c0656aa */
if(!s->budget--) { s->failed_pc=0x0c0656aau; return 0; }
r[4]=r[13];
goto P_0c0656ac;
P_0c0656ac: /* original 61b2, guest PC 0x0c0656ac */
if(!s->budget--) { s->failed_pc=0x0c0656acu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656ae;
P_0c0656ae: /* original 6c03, guest PC 0x0c0656ae */
if(!s->budget--) { s->failed_pc=0x0c0656aeu; return 0; }
r[12]=r[0];
goto P_0c0656b0;
P_0c0656b0: /* original 5311, guest PC 0x0c0656b0 */
if(!s->budget--) { s->failed_pc=0x0c0656b0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0656b2;
P_0c0656b2: /* original 62c3, guest PC 0x0c0656b2 */
if(!s->budget--) { s->failed_pc=0x0c0656b2u; return 0; }
r[2]=r[12];
goto P_0c0656b4;
P_0c0656b4: /* original d095, guest PC 0x0c0656b4 */
if(!s->budget--) { s->failed_pc=0x0c0656b4u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c0656b6;
P_0c0656b6: /* original 7c01, guest PC 0x0c0656b6 */
if(!s->budget--) { s->failed_pc=0x0c0656b6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0656b8;
P_0c0656b8: /* original 4208, guest PC 0x0c0656b8 */
if(!s->budget--) { s->failed_pc=0x0c0656b8u; return 0; }
r[2]<<=2;
goto P_0c0656ba;
P_0c0656ba: /* original 0236, guest PC 0x0c0656ba */
if(!s->budget--) { s->failed_pc=0x0c0656bau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656bc;
P_0c0656bc: /* original 61b2, guest PC 0x0c0656bc */
if(!s->budget--) { s->failed_pc=0x0c0656bcu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656be;
P_0c0656be: /* original 62c3, guest PC 0x0c0656be */
if(!s->budget--) { s->failed_pc=0x0c0656beu; return 0; }
r[2]=r[12];
goto P_0c0656c0;
P_0c0656c0: /* original 5312, guest PC 0x0c0656c0 */
if(!s->budget--) { s->failed_pc=0x0c0656c0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0656c2;
P_0c0656c2: /* original 7c01, guest PC 0x0c0656c2 */
if(!s->budget--) { s->failed_pc=0x0c0656c2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0656c4;
P_0c0656c4: /* original 4208, guest PC 0x0c0656c4 */
if(!s->budget--) { s->failed_pc=0x0c0656c4u; return 0; }
r[2]<<=2;
goto P_0c0656c6;
P_0c0656c6: /* original 0236, guest PC 0x0c0656c6 */
if(!s->budget--) { s->failed_pc=0x0c0656c6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656c8;
P_0c0656c8: /* original 61b2, guest PC 0x0c0656c8 */
if(!s->budget--) { s->failed_pc=0x0c0656c8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0656ca;
P_0c0656ca: /* original 62c3, guest PC 0x0c0656ca */
if(!s->budget--) { s->failed_pc=0x0c0656cau; return 0; }
r[2]=r[12];
goto P_0c0656cc;
P_0c0656cc: /* original 5313, guest PC 0x0c0656cc */
if(!s->budget--) { s->failed_pc=0x0c0656ccu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0656ce;
P_0c0656ce: /* original 7c01, guest PC 0x0c0656ce */
if(!s->budget--) { s->failed_pc=0x0c0656ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0656d0;
P_0c0656d0: /* original 4208, guest PC 0x0c0656d0 */
if(!s->budget--) { s->failed_pc=0x0c0656d0u; return 0; }
r[2]<<=2;
goto P_0c0656d2;
P_0c0656d2: /* original 0236, guest PC 0x0c0656d2 */
if(!s->budget--) { s->failed_pc=0x0c0656d2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0656d4;
P_0c0656d4: /* original 66e2, guest PC 0x0c0656d4 */
if(!s->budget--) { s->failed_pc=0x0c0656d4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0656d6;
P_0c0656d6: /* original 65c3, guest PC 0x0c0656d6 */
if(!s->budget--) { s->failed_pc=0x0c0656d6u; return 0; }
r[5]=r[12];
goto P_0c0656d8;
P_0c0656d8: /* original d38d, guest PC 0x0c0656d8 */
if(!s->budget--) { s->failed_pc=0x0c0656d8u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c0656da;
P_0c0656da: /* original 5664, guest PC 0x0c0656da */
if(!s->budget--) { s->failed_pc=0x0c0656dau; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0656dc;
P_0c0656dc: /* original 430b, guest PC 0x0c0656dc */
if(!s->budget--) { s->failed_pc=0x0c0656dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0656e0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0656e0u) { target=s->pc; goto dispatch; }
goto P_0c0656e0;
P_0c0656de: /* original 64d3, guest PC 0x0c0656de */
if(!s->budget--) { s->failed_pc=0x0c0656deu; return 0; }
r[4]=r[13];
goto P_0c0656e0;
P_0c0656e0: /* original 64b2, guest PC 0x0c0656e0 */
if(!s->budget--) { s->failed_pc=0x0c0656e0u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0656e2;
P_0c0656e2: /* original e118, guest PC 0x0c0656e2 */
if(!s->budget--) { s->failed_pc=0x0c0656e2u; return 0; }
r[1]=0x00000018u;
goto P_0c0656e4;
P_0c0656e4: /* original 6903, guest PC 0x0c0656e4 */
if(!s->budget--) { s->failed_pc=0x0c0656e4u; return 0; }
r[9]=r[0];
goto P_0c0656e6;
P_0c0656e6: /* original 6293, guest PC 0x0c0656e6 */
if(!s->budget--) { s->failed_pc=0x0c0656e6u; return 0; }
r[2]=r[9];
goto P_0c0656e8;
P_0c0656e8: /* original d088, guest PC 0x0c0656e8 */
if(!s->budget--) { s->failed_pc=0x0c0656e8u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c0656ea;
P_0c0656ea: /* original 314c, guest PC 0x0c0656ea */
if(!s->budget--) { s->failed_pc=0x0c0656eau; return 0; }
r[1]+=r[4];
goto P_0c0656ec;
P_0c0656ec: /* original f318, guest PC 0x0c0656ec */
if(!s->budget--) { s->failed_pc=0x0c0656ecu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0656ee;
P_0c0656ee: /* original 7901, guest PC 0x0c0656ee */
if(!s->budget--) { s->failed_pc=0x0c0656eeu; return 0; }
r[9]+=0x00000001u;
goto P_0c0656f0;
P_0c0656f0: /* original 4208, guest PC 0x0c0656f0 */
if(!s->budget--) { s->failed_pc=0x0c0656f0u; return 0; }
r[2]<<=2;
goto P_0c0656f2;
P_0c0656f2: /* original f3f2, guest PC 0x0c0656f2 */
if(!s->budget--) { s->failed_pc=0x0c0656f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0656f4;
P_0c0656f4: /* original f33d, guest PC 0x0c0656f4 */
if(!s->budget--) { s->failed_pc=0x0c0656f4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0656f6;
P_0c0656f6: /* original 045a, guest PC 0x0c0656f6 */
if(!s->budget--) { s->failed_pc=0x0c0656f6u; return 0; }
r[4]=r[53];
goto P_0c0656f8;
P_0c0656f8: /* original 6343, guest PC 0x0c0656f8 */
if(!s->budget--) { s->failed_pc=0x0c0656f8u; return 0; }
r[3]=r[4];
goto P_0c0656fa;
P_0c0656fa: /* original 4328, guest PC 0x0c0656fa */
if(!s->budget--) { s->failed_pc=0x0c0656fau; return 0; }
r[3]<<=16;
goto P_0c0656fc;
P_0c0656fc: /* original 4318, guest PC 0x0c0656fc */
if(!s->budget--) { s->failed_pc=0x0c0656fcu; return 0; }
r[3]<<=8;
goto P_0c0656fe;
P_0c0656fe: /* original 6143, guest PC 0x0c0656fe */
if(!s->budget--) { s->failed_pc=0x0c0656feu; return 0; }
r[1]=r[4];
goto P_0c065700;
P_0c065700: /* original 4128, guest PC 0x0c065700 */
if(!s->budget--) { s->failed_pc=0x0c065700u; return 0; }
r[1]<<=16;
goto P_0c065702;
P_0c065702: /* original 231b, guest PC 0x0c065702 */
if(!s->budget--) { s->failed_pc=0x0c065702u; return 0; }
r[3]|=r[1];
goto P_0c065704;
P_0c065704: /* original 6143, guest PC 0x0c065704 */
if(!s->budget--) { s->failed_pc=0x0c065704u; return 0; }
r[1]=r[4];
goto P_0c065706;
P_0c065706: /* original 4118, guest PC 0x0c065706 */
if(!s->budget--) { s->failed_pc=0x0c065706u; return 0; }
r[1]<<=8;
goto P_0c065708;
P_0c065708: /* original 231b, guest PC 0x0c065708 */
if(!s->budget--) { s->failed_pc=0x0c065708u; return 0; }
r[3]|=r[1];
goto P_0c06570a;
P_0c06570a: /* original 234b, guest PC 0x0c06570a */
if(!s->budget--) { s->failed_pc=0x0c06570au; return 0; }
r[3]|=r[4];
goto P_0c06570c;
P_0c06570c: /* original 0236, guest PC 0x0c06570c */
if(!s->budget--) { s->failed_pc=0x0c06570cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06570e;
P_0c06570e: /* original e01c, guest PC 0x0c06570e */
if(!s->budget--) { s->failed_pc=0x0c06570eu; return 0; }
r[0]=0x0000001cu;
goto P_0c065710;
P_0c065710: /* original 6cb2, guest PC 0x0c065710 */
if(!s->budget--) { s->failed_pc=0x0c065710u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065712;
P_0c065712: /* original f3c6, guest PC 0x0c065712 */
if(!s->budget--) { s->failed_pc=0x0c065712u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065714;
P_0c065714: /* original f3f2, guest PC 0x0c065714 */
if(!s->budget--) { s->failed_pc=0x0c065714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065716;
P_0c065716: /* original f33d, guest PC 0x0c065716 */
if(!s->budget--) { s->failed_pc=0x0c065716u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065718;
P_0c065718: /* original 0c5a, guest PC 0x0c065718 */
if(!s->budget--) { s->failed_pc=0x0c065718u; return 0; }
r[12]=r[53];
goto P_0c06571a;
P_0c06571a: /* original 66c3, guest PC 0x0c06571a */
if(!s->budget--) { s->failed_pc=0x0c06571au; return 0; }
r[6]=r[12];
goto P_0c06571c;
P_0c06571c: /* original 4628, guest PC 0x0c06571c */
if(!s->budget--) { s->failed_pc=0x0c06571cu; return 0; }
r[6]<<=16;
goto P_0c06571e;
P_0c06571e: /* original 4618, guest PC 0x0c06571e */
if(!s->budget--) { s->failed_pc=0x0c06571eu; return 0; }
r[6]<<=8;
goto P_0c065720;
P_0c065720: /* original 63c3, guest PC 0x0c065720 */
if(!s->budget--) { s->failed_pc=0x0c065720u; return 0; }
r[3]=r[12];
goto P_0c065722;
P_0c065722: /* original 4328, guest PC 0x0c065722 */
if(!s->budget--) { s->failed_pc=0x0c065722u; return 0; }
r[3]<<=16;
goto P_0c065724;
P_0c065724: /* original 263b, guest PC 0x0c065724 */
if(!s->budget--) { s->failed_pc=0x0c065724u; return 0; }
r[6]|=r[3];
goto P_0c065726;
P_0c065726: /* original 62c3, guest PC 0x0c065726 */
if(!s->budget--) { s->failed_pc=0x0c065726u; return 0; }
r[2]=r[12];
goto P_0c065728;
P_0c065728: /* original d37b, guest PC 0x0c065728 */
if(!s->budget--) { s->failed_pc=0x0c065728u; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c06572a;
P_0c06572a: /* original 6593, guest PC 0x0c06572a */
if(!s->budget--) { s->failed_pc=0x0c06572au; return 0; }
r[5]=r[9];
goto P_0c06572c;
P_0c06572c: /* original 4218, guest PC 0x0c06572c */
if(!s->budget--) { s->failed_pc=0x0c06572cu; return 0; }
r[2]<<=8;
goto P_0c06572e;
P_0c06572e: /* original 262b, guest PC 0x0c06572e */
if(!s->budget--) { s->failed_pc=0x0c06572eu; return 0; }
r[6]|=r[2];
goto P_0c065730;
P_0c065730: /* original 26cb, guest PC 0x0c065730 */
if(!s->budget--) { s->failed_pc=0x0c065730u; return 0; }
r[6]|=r[12];
goto P_0c065732;
P_0c065732: /* original 430b, guest PC 0x0c065732 */
if(!s->budget--) { s->failed_pc=0x0c065732u; return 0; }
target=r[3];
r[16]=code_base|0x0c065736u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065736u) { target=s->pc; goto dispatch; }
goto P_0c065736;
P_0c065734: /* original 64d3, guest PC 0x0c065734 */
if(!s->budget--) { s->failed_pc=0x0c065734u; return 0; }
r[4]=r[13];
goto P_0c065736;
P_0c065736: /* original 6c03, guest PC 0x0c065736 */
if(!s->budget--) { s->failed_pc=0x0c065736u; return 0; }
r[12]=r[0];
goto P_0c065738;
P_0c065738: /* original 61a2, guest PC 0x0c065738 */
if(!s->budget--) { s->failed_pc=0x0c065738u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c06573a;
P_0c06573a: /* original 62c3, guest PC 0x0c06573a */
if(!s->budget--) { s->failed_pc=0x0c06573au; return 0; }
r[2]=r[12];
goto P_0c06573c;
P_0c06573c: /* original d073, guest PC 0x0c06573c */
if(!s->budget--) { s->failed_pc=0x0c06573cu; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06573e;
P_0c06573e: /* original 7c01, guest PC 0x0c06573e */
if(!s->budget--) { s->failed_pc=0x0c06573eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065740;
P_0c065740: /* original 5311, guest PC 0x0c065740 */
if(!s->budget--) { s->failed_pc=0x0c065740u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065742;
P_0c065742: /* original 4208, guest PC 0x0c065742 */
if(!s->budget--) { s->failed_pc=0x0c065742u; return 0; }
r[2]<<=2;
goto P_0c065744;
P_0c065744: /* original 0236, guest PC 0x0c065744 */
if(!s->budget--) { s->failed_pc=0x0c065744u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065746;
P_0c065746: /* original 62c3, guest PC 0x0c065746 */
if(!s->budget--) { s->failed_pc=0x0c065746u; return 0; }
r[2]=r[12];
goto P_0c065748;
P_0c065748: /* original 61a2, guest PC 0x0c065748 */
if(!s->budget--) { s->failed_pc=0x0c065748u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c06574a;
P_0c06574a: /* original 7c01, guest PC 0x0c06574a */
if(!s->budget--) { s->failed_pc=0x0c06574au; return 0; }
r[12]+=0x00000001u;
goto P_0c06574c;
P_0c06574c: /* original 5312, guest PC 0x0c06574c */
if(!s->budget--) { s->failed_pc=0x0c06574cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c06574e;
P_0c06574e: /* original 4208, guest PC 0x0c06574e */
if(!s->budget--) { s->failed_pc=0x0c06574eu; return 0; }
r[2]<<=2;
goto P_0c065750;
P_0c065750: /* original 0236, guest PC 0x0c065750 */
if(!s->budget--) { s->failed_pc=0x0c065750u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065752;
P_0c065752: /* original 62c3, guest PC 0x0c065752 */
if(!s->budget--) { s->failed_pc=0x0c065752u; return 0; }
r[2]=r[12];
goto P_0c065754;
P_0c065754: /* original 61a2, guest PC 0x0c065754 */
if(!s->budget--) { s->failed_pc=0x0c065754u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065756;
P_0c065756: /* original 7c01, guest PC 0x0c065756 */
if(!s->budget--) { s->failed_pc=0x0c065756u; return 0; }
r[12]+=0x00000001u;
goto P_0c065758;
P_0c065758: /* original 5313, guest PC 0x0c065758 */
if(!s->budget--) { s->failed_pc=0x0c065758u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06575a;
P_0c06575a: /* original 4208, guest PC 0x0c06575a */
if(!s->budget--) { s->failed_pc=0x0c06575au; return 0; }
r[2]<<=2;
goto P_0c06575c;
P_0c06575c: /* original 0236, guest PC 0x0c06575c */
if(!s->budget--) { s->failed_pc=0x0c06575cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06575e;
P_0c06575e: /* original 65c3, guest PC 0x0c06575e */
if(!s->budget--) { s->failed_pc=0x0c06575eu; return 0; }
r[5]=r[12];
goto P_0c065760;
P_0c065760: /* original d36b, guest PC 0x0c065760 */
if(!s->budget--) { s->failed_pc=0x0c065760u; return 0; }
r[3]=read(ram,0x0c065910u,4);
goto P_0c065762;
P_0c065762: /* original 66e2, guest PC 0x0c065762 */
if(!s->budget--) { s->failed_pc=0x0c065762u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065764;
P_0c065764: /* original 5664, guest PC 0x0c065764 */
if(!s->budget--) { s->failed_pc=0x0c065764u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065766;
P_0c065766: /* original 430b, guest PC 0x0c065766 */
if(!s->budget--) { s->failed_pc=0x0c065766u; return 0; }
target=r[3];
r[16]=code_base|0x0c06576au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06576au) { target=s->pc; goto dispatch; }
goto P_0c06576a;
P_0c065768: /* original 64d3, guest PC 0x0c065768 */
if(!s->budget--) { s->failed_pc=0x0c065768u; return 0; }
r[4]=r[13];
goto P_0c06576a;
P_0c06576a: /* original 6b03, guest PC 0x0c06576a */
if(!s->budget--) { s->failed_pc=0x0c06576au; return 0; }
r[11]=r[0];
goto P_0c06576c;
P_0c06576c: /* original 64a2, guest PC 0x0c06576c */
if(!s->budget--) { s->failed_pc=0x0c06576cu; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c06576e;
P_0c06576e: /* original e118, guest PC 0x0c06576e */
if(!s->budget--) { s->failed_pc=0x0c06576eu; return 0; }
r[1]=0x00000018u;
goto P_0c065770;
P_0c065770: /* original d066, guest PC 0x0c065770 */
if(!s->budget--) { s->failed_pc=0x0c065770u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c065772;
P_0c065772: /* original 62b3, guest PC 0x0c065772 */
if(!s->budget--) { s->failed_pc=0x0c065772u; return 0; }
r[2]=r[11];
goto P_0c065774;
P_0c065774: /* original 7b01, guest PC 0x0c065774 */
if(!s->budget--) { s->failed_pc=0x0c065774u; return 0; }
r[11]+=0x00000001u;
goto P_0c065776;
P_0c065776: /* original 4208, guest PC 0x0c065776 */
if(!s->budget--) { s->failed_pc=0x0c065776u; return 0; }
r[2]<<=2;
goto P_0c065778;
P_0c065778: /* original 314c, guest PC 0x0c065778 */
if(!s->budget--) { s->failed_pc=0x0c065778u; return 0; }
r[1]+=r[4];
goto P_0c06577a;
P_0c06577a: /* original f318, guest PC 0x0c06577a */
if(!s->budget--) { s->failed_pc=0x0c06577au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06577c;
P_0c06577c: /* original f3f2, guest PC 0x0c06577c */
if(!s->budget--) { s->failed_pc=0x0c06577cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06577e;
P_0c06577e: /* original f33d, guest PC 0x0c06577e */
if(!s->budget--) { s->failed_pc=0x0c06577eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065780;
P_0c065780: /* original 045a, guest PC 0x0c065780 */
if(!s->budget--) { s->failed_pc=0x0c065780u; return 0; }
r[4]=r[53];
goto P_0c065782;
P_0c065782: /* original 6343, guest PC 0x0c065782 */
if(!s->budget--) { s->failed_pc=0x0c065782u; return 0; }
r[3]=r[4];
goto P_0c065784;
P_0c065784: /* original 4328, guest PC 0x0c065784 */
if(!s->budget--) { s->failed_pc=0x0c065784u; return 0; }
r[3]<<=16;
goto P_0c065786;
P_0c065786: /* original 4318, guest PC 0x0c065786 */
if(!s->budget--) { s->failed_pc=0x0c065786u; return 0; }
r[3]<<=8;
goto P_0c065788;
P_0c065788: /* original 6143, guest PC 0x0c065788 */
if(!s->budget--) { s->failed_pc=0x0c065788u; return 0; }
r[1]=r[4];
goto P_0c06578a;
P_0c06578a: /* original 4128, guest PC 0x0c06578a */
if(!s->budget--) { s->failed_pc=0x0c06578au; return 0; }
r[1]<<=16;
goto P_0c06578c;
P_0c06578c: /* original 231b, guest PC 0x0c06578c */
if(!s->budget--) { s->failed_pc=0x0c06578cu; return 0; }
r[3]|=r[1];
goto P_0c06578e;
P_0c06578e: /* original 6143, guest PC 0x0c06578e */
if(!s->budget--) { s->failed_pc=0x0c06578eu; return 0; }
r[1]=r[4];
goto P_0c065790;
P_0c065790: /* original 4118, guest PC 0x0c065790 */
if(!s->budget--) { s->failed_pc=0x0c065790u; return 0; }
r[1]<<=8;
goto P_0c065792;
P_0c065792: /* original 231b, guest PC 0x0c065792 */
if(!s->budget--) { s->failed_pc=0x0c065792u; return 0; }
r[3]|=r[1];
goto P_0c065794;
P_0c065794: /* original 234b, guest PC 0x0c065794 */
if(!s->budget--) { s->failed_pc=0x0c065794u; return 0; }
r[3]|=r[4];
goto P_0c065796;
P_0c065796: /* original 0236, guest PC 0x0c065796 */
if(!s->budget--) { s->failed_pc=0x0c065796u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065798;
P_0c065798: /* original 6ca2, guest PC 0x0c065798 */
if(!s->budget--) { s->failed_pc=0x0c065798u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c06579a;
P_0c06579a: /* original e01c, guest PC 0x0c06579a */
if(!s->budget--) { s->failed_pc=0x0c06579au; return 0; }
r[0]=0x0000001cu;
goto P_0c06579c;
P_0c06579c: /* original f3c6, guest PC 0x0c06579c */
if(!s->budget--) { s->failed_pc=0x0c06579cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06579e;
P_0c06579e: /* original f3f2, guest PC 0x0c06579e */
if(!s->budget--) { s->failed_pc=0x0c06579eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0657a0;
P_0c0657a0: /* original f33d, guest PC 0x0c0657a0 */
if(!s->budget--) { s->failed_pc=0x0c0657a0u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0657a2;
P_0c0657a2: /* original 0c5a, guest PC 0x0c0657a2 */
if(!s->budget--) { s->failed_pc=0x0c0657a2u; return 0; }
r[12]=r[53];
goto P_0c0657a4;
P_0c0657a4: /* original 66c3, guest PC 0x0c0657a4 */
if(!s->budget--) { s->failed_pc=0x0c0657a4u; return 0; }
r[6]=r[12];
goto P_0c0657a6;
P_0c0657a6: /* original 4628, guest PC 0x0c0657a6 */
if(!s->budget--) { s->failed_pc=0x0c0657a6u; return 0; }
r[6]<<=16;
goto P_0c0657a8;
P_0c0657a8: /* original 4618, guest PC 0x0c0657a8 */
if(!s->budget--) { s->failed_pc=0x0c0657a8u; return 0; }
r[6]<<=8;
goto P_0c0657aa;
P_0c0657aa: /* original 63c3, guest PC 0x0c0657aa */
if(!s->budget--) { s->failed_pc=0x0c0657aau; return 0; }
r[3]=r[12];
goto P_0c0657ac;
P_0c0657ac: /* original 4328, guest PC 0x0c0657ac */
if(!s->budget--) { s->failed_pc=0x0c0657acu; return 0; }
r[3]<<=16;
goto P_0c0657ae;
P_0c0657ae: /* original 263b, guest PC 0x0c0657ae */
if(!s->budget--) { s->failed_pc=0x0c0657aeu; return 0; }
r[6]|=r[3];
goto P_0c0657b0;
P_0c0657b0: /* original d359, guest PC 0x0c0657b0 */
if(!s->budget--) { s->failed_pc=0x0c0657b0u; return 0; }
r[3]=read(ram,0x0c065918u,4);
goto P_0c0657b2;
P_0c0657b2: /* original 62c3, guest PC 0x0c0657b2 */
if(!s->budget--) { s->failed_pc=0x0c0657b2u; return 0; }
r[2]=r[12];
goto P_0c0657b4;
P_0c0657b4: /* original 4218, guest PC 0x0c0657b4 */
if(!s->budget--) { s->failed_pc=0x0c0657b4u; return 0; }
r[2]<<=8;
goto P_0c0657b6;
P_0c0657b6: /* original 262b, guest PC 0x0c0657b6 */
if(!s->budget--) { s->failed_pc=0x0c0657b6u; return 0; }
r[6]|=r[2];
goto P_0c0657b8;
P_0c0657b8: /* original 26cb, guest PC 0x0c0657b8 */
if(!s->budget--) { s->failed_pc=0x0c0657b8u; return 0; }
r[6]|=r[12];
goto P_0c0657ba;
P_0c0657ba: /* original 65b3, guest PC 0x0c0657ba */
if(!s->budget--) { s->failed_pc=0x0c0657bau; return 0; }
r[5]=r[11];
goto P_0c0657bc;
P_0c0657bc: /* original 430b, guest PC 0x0c0657bc */
if(!s->budget--) { s->failed_pc=0x0c0657bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0657c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0657c0u) { target=s->pc; goto dispatch; }
goto P_0c0657c0;
P_0c0657be: /* original 64d3, guest PC 0x0c0657be */
if(!s->budget--) { s->failed_pc=0x0c0657beu; return 0; }
r[4]=r[13];
goto P_0c0657c0;
P_0c0657c0: /* original d256, guest PC 0x0c0657c0 */
if(!s->budget--) { s->failed_pc=0x0c0657c0u; return 0; }
r[2]=read(ram,0x0c06591cu,4);
goto P_0c0657c2;
P_0c0657c2: /* original 6403, guest PC 0x0c0657c2 */
if(!s->budget--) { s->failed_pc=0x0c0657c2u; return 0; }
r[4]=r[0];
goto P_0c0657c4;
P_0c0657c4: /* original 4408, guest PC 0x0c0657c4 */
if(!s->budget--) { s->failed_pc=0x0c0657c4u; return 0; }
r[4]<<=2;
goto P_0c0657c6;
P_0c0657c6: /* original 2242, guest PC 0x0c0657c6 */
if(!s->budget--) { s->failed_pc=0x0c0657c6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0657c8;
P_0c0657c8: /* original d355, guest PC 0x0c0657c8 */
if(!s->budget--) { s->failed_pc=0x0c0657c8u; return 0; }
r[3]=read(ram,0x0c065920u,4);
goto P_0c0657ca;
P_0c0657ca: /* original 430b, guest PC 0x0c0657ca */
if(!s->budget--) { s->failed_pc=0x0c0657cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0657ceu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0657ceu) { target=s->pc; goto dispatch; }
goto P_0c0657ce;
P_0c0657cc: /* original 64d3, guest PC 0x0c0657cc */
if(!s->budget--) { s->failed_pc=0x0c0657ccu; return 0; }
r[4]=r[13];
goto P_0c0657ce;
P_0c0657ce: /* original 6403, guest PC 0x0c0657ce */
if(!s->budget--) { s->failed_pc=0x0c0657ceu; return 0; }
r[4]=r[0];
goto P_0c0657d0;
P_0c0657d0: /* original d254, guest PC 0x0c0657d0 */
if(!s->budget--) { s->failed_pc=0x0c0657d0u; return 0; }
r[2]=read(ram,0x0c065924u,4);
goto P_0c0657d2;
P_0c0657d2: /* original e500, guest PC 0x0c0657d2 */
if(!s->budget--) { s->failed_pc=0x0c0657d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0657d4;
P_0c0657d4: /* original 420b, guest PC 0x0c0657d4 */
if(!s->budget--) { s->failed_pc=0x0c0657d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0657d8u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0657d8u) { target=s->pc; goto dispatch; }
goto P_0c0657d8;
P_0c0657d6: /* original 6653, guest PC 0x0c0657d6 */
if(!s->budget--) { s->failed_pc=0x0c0657d6u; return 0; }
r[6]=r[5];
goto P_0c0657d8;
P_0c0657d8: /* original 62e2, guest PC 0x0c0657d8 */
if(!s->budget--) { s->failed_pc=0x0c0657d8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0657da;
P_0c0657da: /* original 5323, guest PC 0x0c0657da */
if(!s->budget--) { s->failed_pc=0x0c0657dau; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0657dc;
P_0c0657dc: /* original d152, guest PC 0x0c0657dc */
if(!s->budget--) { s->failed_pc=0x0c0657dcu; return 0; }
r[1]=read(ram,0x0c065928u,4);
goto P_0c0657de;
P_0c0657de: /* original 2132, guest PC 0x0c0657de */
if(!s->budget--) { s->failed_pc=0x0c0657deu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0657e0;
P_0c0657e0: /* original e000, guest PC 0x0c0657e0 */
if(!s->budget--) { s->failed_pc=0x0c0657e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0657e2;
P_0c0657e2: /* original 7f0c, guest PC 0x0c0657e2 */
if(!s->budget--) { s->failed_pc=0x0c0657e2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0657e4;
P_0c0657e4: /* original 4f26, guest PC 0x0c0657e4 */
if(!s->budget--) { s->failed_pc=0x0c0657e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0657e6;
P_0c0657e6: /* original fff9, guest PC 0x0c0657e6 */
if(!s->budget--) { s->failed_pc=0x0c0657e6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0657e8;
P_0c0657e8: /* original 69f6, guest PC 0x0c0657e8 */
if(!s->budget--) { s->failed_pc=0x0c0657e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0657ea;
P_0c0657ea: /* original 6af6, guest PC 0x0c0657ea */
if(!s->budget--) { s->failed_pc=0x0c0657eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0657ec;
P_0c0657ec: /* original 6bf6, guest PC 0x0c0657ec */
if(!s->budget--) { s->failed_pc=0x0c0657ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0657ee;
P_0c0657ee: /* original 6cf6, guest PC 0x0c0657ee */
if(!s->budget--) { s->failed_pc=0x0c0657eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0657f0;
P_0c0657f0: /* original 6df6, guest PC 0x0c0657f0 */
if(!s->budget--) { s->failed_pc=0x0c0657f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0657f2;
P_0c0657f2: /* original 000b, guest PC 0x0c0657f2 */
if(!s->budget--) { s->failed_pc=0x0c0657f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0657f4: /* original 6ef6, guest PC 0x0c0657f4 */
if(!s->budget--) { s->failed_pc=0x0c0657f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0657f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0657f6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
