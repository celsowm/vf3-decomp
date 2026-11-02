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
int vf3_away_batch56_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0558a0u: goto P_0c0558a0;
case 0x0c0558a2u: goto P_0c0558a2;
case 0x0c0558a4u: goto P_0c0558a4;
case 0x0c0558a6u: goto P_0c0558a6;
case 0x0c0558a8u: goto P_0c0558a8;
case 0x0c0558aau: goto P_0c0558aa;
case 0x0c0558acu: goto P_0c0558ac;
case 0x0c0558aeu: goto P_0c0558ae;
case 0x0c0558b0u: goto P_0c0558b0;
case 0x0c0558b2u: goto P_0c0558b2;
case 0x0c0558b4u: goto P_0c0558b4;
case 0x0c0558b6u: goto P_0c0558b6;
case 0x0c0558b8u: goto P_0c0558b8;
case 0x0c0558bau: goto P_0c0558ba;
case 0x0c0558bcu: goto P_0c0558bc;
case 0x0c0558beu: goto P_0c0558be;
case 0x0c0558c0u: goto P_0c0558c0;
case 0x0c0558c2u: goto P_0c0558c2;
case 0x0c0558c4u: goto P_0c0558c4;
case 0x0c0558c6u: goto P_0c0558c6;
case 0x0c0558c8u: goto P_0c0558c8;
case 0x0c0558cau: goto P_0c0558ca;
case 0x0c0558ccu: goto P_0c0558cc;
case 0x0c0558ceu: goto P_0c0558ce;
case 0x0c0558d0u: goto P_0c0558d0;
case 0x0c0558d2u: goto P_0c0558d2;
case 0x0c0558d4u: goto P_0c0558d4;
case 0x0c0558d6u: goto P_0c0558d6;
case 0x0c0558d8u: goto P_0c0558d8;
case 0x0c0558dau: goto P_0c0558da;
case 0x0c0558dcu: goto P_0c0558dc;
case 0x0c0558deu: goto P_0c0558de;
case 0x0c0558e0u: goto P_0c0558e0;
case 0x0c0558e2u: goto P_0c0558e2;
case 0x0c0558e4u: goto P_0c0558e4;
case 0x0c0558e6u: goto P_0c0558e6;
case 0x0c0558e8u: goto P_0c0558e8;
case 0x0c0558eau: goto P_0c0558ea;
case 0x0c0558ecu: goto P_0c0558ec;
case 0x0c0558eeu: goto P_0c0558ee;
case 0x0c0558f0u: goto P_0c0558f0;
case 0x0c0558f2u: goto P_0c0558f2;
case 0x0c0558f4u: goto P_0c0558f4;
case 0x0c0558f6u: goto P_0c0558f6;
case 0x0c0558f8u: goto P_0c0558f8;
case 0x0c0558fau: goto P_0c0558fa;
case 0x0c0558fcu: goto P_0c0558fc;
case 0x0c0558feu: goto P_0c0558fe;
case 0x0c055900u: goto P_0c055900;
case 0x0c055902u: goto P_0c055902;
case 0x0c055904u: goto P_0c055904;
case 0x0c055906u: goto P_0c055906;
case 0x0c055908u: goto P_0c055908;
case 0x0c05590au: goto P_0c05590a;
case 0x0c05590cu: goto P_0c05590c;
case 0x0c05590eu: goto P_0c05590e;
case 0x0c055910u: goto P_0c055910;
case 0x0c055912u: goto P_0c055912;
case 0x0c055914u: goto P_0c055914;
case 0x0c055916u: goto P_0c055916;
case 0x0c055918u: goto P_0c055918;
case 0x0c05591au: goto P_0c05591a;
case 0x0c05591cu: goto P_0c05591c;
case 0x0c05591eu: goto P_0c05591e;
case 0x0c055920u: goto P_0c055920;
case 0x0c055922u: goto P_0c055922;
case 0x0c055924u: goto P_0c055924;
case 0x0c055926u: goto P_0c055926;
case 0x0c055928u: goto P_0c055928;
case 0x0c05592au: goto P_0c05592a;
case 0x0c05592cu: goto P_0c05592c;
case 0x0c05592eu: goto P_0c05592e;
case 0x0c055930u: goto P_0c055930;
case 0x0c055932u: goto P_0c055932;
case 0x0c055934u: goto P_0c055934;
case 0x0c055936u: goto P_0c055936;
case 0x0c055938u: goto P_0c055938;
case 0x0c05593au: goto P_0c05593a;
case 0x0c05593cu: goto P_0c05593c;
case 0x0c05593eu: goto P_0c05593e;
case 0x0c055940u: goto P_0c055940;
case 0x0c055942u: goto P_0c055942;
case 0x0c055944u: goto P_0c055944;
case 0x0c055946u: goto P_0c055946;
case 0x0c055948u: goto P_0c055948;
case 0x0c05594au: goto P_0c05594a;
case 0x0c05594cu: goto P_0c05594c;
case 0x0c05594eu: goto P_0c05594e;
case 0x0c055950u: goto P_0c055950;
case 0x0c055952u: goto P_0c055952;
case 0x0c055954u: goto P_0c055954;
case 0x0c055956u: goto P_0c055956;
case 0x0c055958u: goto P_0c055958;
case 0x0c05595au: goto P_0c05595a;
case 0x0c05595cu: goto P_0c05595c;
case 0x0c05595eu: goto P_0c05595e;
case 0x0c055960u: goto P_0c055960;
case 0x0c055962u: goto P_0c055962;
case 0x0c055964u: goto P_0c055964;
case 0x0c055966u: goto P_0c055966;
case 0x0c055968u: goto P_0c055968;
case 0x0c05596au: goto P_0c05596a;
case 0x0c05596cu: goto P_0c05596c;
case 0x0c05596eu: goto P_0c05596e;
case 0x0c055970u: goto P_0c055970;
case 0x0c055972u: goto P_0c055972;
case 0x0c055974u: goto P_0c055974;
case 0x0c055976u: goto P_0c055976;
case 0x0c055978u: goto P_0c055978;
case 0x0c05597au: goto P_0c05597a;
case 0x0c05597cu: goto P_0c05597c;
case 0x0c05597eu: goto P_0c05597e;
case 0x0c055980u: goto P_0c055980;
case 0x0c055982u: goto P_0c055982;
case 0x0c055984u: goto P_0c055984;
case 0x0c055986u: goto P_0c055986;
case 0x0c055988u: goto P_0c055988;
case 0x0c089764u: goto P_0c089764;
case 0x0c089766u: goto P_0c089766;
case 0x0c089768u: goto P_0c089768;
case 0x0c08976au: goto P_0c08976a;
case 0x0c08976cu: goto P_0c08976c;
case 0x0c08976eu: goto P_0c08976e;
case 0x0c089770u: goto P_0c089770;
case 0x0c089772u: goto P_0c089772;
case 0x0c089774u: goto P_0c089774;
case 0x0c089776u: goto P_0c089776;
case 0x0c089778u: goto P_0c089778;
case 0x0c08977au: goto P_0c08977a;
case 0x0c08977cu: goto P_0c08977c;
case 0x0c08977eu: goto P_0c08977e;
case 0x0c089780u: goto P_0c089780;
case 0x0c089782u: goto P_0c089782;
case 0x0c089784u: goto P_0c089784;
case 0x0c089786u: goto P_0c089786;
case 0x0c089788u: goto P_0c089788;
case 0x0c08978au: goto P_0c08978a;
case 0x0c08978cu: goto P_0c08978c;
case 0x0c08978eu: goto P_0c08978e;
case 0x0c089790u: goto P_0c089790;
case 0x0c089792u: goto P_0c089792;
case 0x0c089794u: goto P_0c089794;
case 0x0c089796u: goto P_0c089796;
case 0x0c089798u: goto P_0c089798;
case 0x0c08979au: goto P_0c08979a;
case 0x0c08979cu: goto P_0c08979c;
case 0x0c08979eu: goto P_0c08979e;
case 0x0c0897a0u: goto P_0c0897a0;
case 0x0c0897a2u: goto P_0c0897a2;
case 0x0c0897a4u: goto P_0c0897a4;
case 0x0c0897a6u: goto P_0c0897a6;
case 0x0c0897a8u: goto P_0c0897a8;
case 0x0c0897aau: goto P_0c0897aa;
case 0x0c0897acu: goto P_0c0897ac;
case 0x0c0897aeu: goto P_0c0897ae;
case 0x0c0897b0u: goto P_0c0897b0;
case 0x0c0897b2u: goto P_0c0897b2;
case 0x0c0897b4u: goto P_0c0897b4;
case 0x0c0897b6u: goto P_0c0897b6;
case 0x0c0897b8u: goto P_0c0897b8;
case 0x0c0897bau: goto P_0c0897ba;
case 0x0c0897bcu: goto P_0c0897bc;
case 0x0c0897beu: goto P_0c0897be;
case 0x0c0897c0u: goto P_0c0897c0;
case 0x0c0897c2u: goto P_0c0897c2;
case 0x0c0897c4u: goto P_0c0897c4;
case 0x0c0897c6u: goto P_0c0897c6;
case 0x0c0897c8u: goto P_0c0897c8;
case 0x0c0897cau: goto P_0c0897ca;
case 0x0c0897ccu: goto P_0c0897cc;
case 0x0c0897ceu: goto P_0c0897ce;
case 0x0c0897d0u: goto P_0c0897d0;
case 0x0c0897d2u: goto P_0c0897d2;
case 0x0c0897d4u: goto P_0c0897d4;
case 0x0c0897d6u: goto P_0c0897d6;
case 0x0c0897d8u: goto P_0c0897d8;
case 0x0c0897dau: goto P_0c0897da;
case 0x0c0897dcu: goto P_0c0897dc;
case 0x0c0897deu: goto P_0c0897de;
case 0x0c0897e0u: goto P_0c0897e0;
case 0x0c0897e2u: goto P_0c0897e2;
case 0x0c0897e4u: goto P_0c0897e4;
case 0x0c0897e6u: goto P_0c0897e6;
case 0x0c0897e8u: goto P_0c0897e8;
case 0x0c0897eau: goto P_0c0897ea;
case 0x0c0897ecu: goto P_0c0897ec;
case 0x0c0897eeu: goto P_0c0897ee;
case 0x0c0897f0u: goto P_0c0897f0;
case 0x0c0897f2u: goto P_0c0897f2;
case 0x0c0897f4u: goto P_0c0897f4;
case 0x0c0897f6u: goto P_0c0897f6;
case 0x0c0897f8u: goto P_0c0897f8;
case 0x0c0897fau: goto P_0c0897fa;
case 0x0c0897fcu: goto P_0c0897fc;
case 0x0c0897feu: goto P_0c0897fe;
case 0x0c089800u: goto P_0c089800;
case 0x0c089802u: goto P_0c089802;
case 0x0c089804u: goto P_0c089804;
case 0x0c089806u: goto P_0c089806;
case 0x0c089808u: goto P_0c089808;
case 0x0c08980au: goto P_0c08980a;
case 0x0c08980cu: goto P_0c08980c;
case 0x0c08980eu: goto P_0c08980e;
case 0x0c089810u: goto P_0c089810;
case 0x0c089812u: goto P_0c089812;
case 0x0c089814u: goto P_0c089814;
case 0x0c089816u: goto P_0c089816;
case 0x0c089818u: goto P_0c089818;
case 0x0c08981au: goto P_0c08981a;
case 0x0c08981cu: goto P_0c08981c;
case 0x0c08981eu: goto P_0c08981e;
case 0x0c089820u: goto P_0c089820;
case 0x0c089822u: goto P_0c089822;
case 0x0c089824u: goto P_0c089824;
case 0x0c089826u: goto P_0c089826;
case 0x0c089828u: goto P_0c089828;
case 0x0c08982au: goto P_0c08982a;
case 0x0c08982cu: goto P_0c08982c;
case 0x0c08982eu: goto P_0c08982e;
case 0x0c089830u: goto P_0c089830;
case 0x0c089832u: goto P_0c089832;
case 0x0c089834u: goto P_0c089834;
case 0x0c089836u: goto P_0c089836;
case 0x0c089838u: goto P_0c089838;
case 0x0c08983au: goto P_0c08983a;
case 0x0c08983cu: goto P_0c08983c;
case 0x0c08983eu: goto P_0c08983e;
case 0x0c089840u: goto P_0c089840;
case 0x0c089842u: goto P_0c089842;
case 0x0c089844u: goto P_0c089844;
case 0x0c089846u: goto P_0c089846;
case 0x0c089848u: goto P_0c089848;
case 0x0c08984au: goto P_0c08984a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0558a0: /* original d03a, guest PC 0x0c0558a0 */
if(!s->budget--) { s->failed_pc=0x0c0558a0u; return 0; }
r[0]=read(ram,0x0c05598cu,4);
goto P_0c0558a2;
P_0c0558a2: /* original e100, guest PC 0x0c0558a2 */
if(!s->budget--) { s->failed_pc=0x0c0558a2u; return 0; }
r[1]=0x00000000u;
goto P_0c0558a4;
P_0c0558a4: /* original 2012, guest PC 0x0c0558a4 */
if(!s->budget--) { s->failed_pc=0x0c0558a4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c0558a6;
P_0c0558a6: /* original d141, guest PC 0x0c0558a6 */
if(!s->budget--) { s->failed_pc=0x0c0558a6u; return 0; }
r[1]=read(ram,0x0c0559acu,4);
goto P_0c0558a8;
P_0c0558a8: /* original fffb, guest PC 0x0c0558a8 */
if(!s->budget--) { s->failed_pc=0x0c0558a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0558aa;
P_0c0558aa: /* original e7e0, guest PC 0x0c0558aa */
if(!s->budget--) { s->failed_pc=0x0c0558aau; return 0; }
r[7]=0xffffffe0u;
goto P_0c0558ac;
P_0c0558ac: /* original ffeb, guest PC 0x0c0558ac */
if(!s->budget--) { s->failed_pc=0x0c0558acu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0558ae;
P_0c0558ae: /* original 4728, guest PC 0x0c0558ae */
if(!s->budget--) { s->failed_pc=0x0c0558aeu; return 0; }
r[7]<<=16;
goto P_0c0558b0;
P_0c0558b0: /* original ffdb, guest PC 0x0c0558b0 */
if(!s->budget--) { s->failed_pc=0x0c0558b0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0558b2;
P_0c0558b2: /* original 4718, guest PC 0x0c0558b2 */
if(!s->budget--) { s->failed_pc=0x0c0558b2u; return 0; }
r[7]<<=8;
goto P_0c0558b4;
P_0c0558b4: /* original ffcb, guest PC 0x0c0558b4 */
if(!s->budget--) { s->failed_pc=0x0c0558b4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0558b6;
P_0c0558b6: /* original 6277, guest PC 0x0c0558b6 */
if(!s->budget--) { s->failed_pc=0x0c0558b6u; return 0; }
r[2]=~r[7];
goto P_0c0558b8;
P_0c0558b8: /* original 6112, guest PC 0x0c0558b8 */
if(!s->budget--) { s->failed_pc=0x0c0558b8u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0558ba;
P_0c0558ba: /* original 4201, guest PC 0x0c0558ba */
if(!s->budget--) { s->failed_pc=0x0c0558bau; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0558bc;
P_0c0558bc: /* original 2fe6, guest PC 0x0c0558bc */
if(!s->budget--) { s->failed_pc=0x0c0558bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558be;
P_0c0558be: /* original 4209, guest PC 0x0c0558be */
if(!s->budget--) { s->failed_pc=0x0c0558beu; return 0; }
r[2]>>=2;
goto P_0c0558c0;
P_0c0558c0: /* original 2fd6, guest PC 0x0c0558c0 */
if(!s->budget--) { s->failed_pc=0x0c0558c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c2;
P_0c0558c2: /* original 2fc6, guest PC 0x0c0558c2 */
if(!s->budget--) { s->failed_pc=0x0c0558c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c4;
P_0c0558c4: /* original 5610, guest PC 0x0c0558c4 */
if(!s->budget--) { s->failed_pc=0x0c0558c4u; return 0; }
r[6]=read(ram,r[1]+0,4);
goto P_0c0558c6;
P_0c0558c6: /* original 5312, guest PC 0x0c0558c6 */
if(!s->budget--) { s->failed_pc=0x0c0558c6u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0558c8;
P_0c0558c8: /* original 2fb6, guest PC 0x0c0558c8 */
if(!s->budget--) { s->failed_pc=0x0c0558c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ca;
P_0c0558ca: /* original c739, guest PC 0x0c0558ca */
if(!s->budget--) { s->failed_pc=0x0c0558cau; return 0; }
r[0]=code_base|0x000559b0u;
goto P_0c0558cc;
P_0c0558cc: /* original 2fa6, guest PC 0x0c0558cc */
if(!s->budget--) { s->failed_pc=0x0c0558ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ce;
P_0c0558ce: /* original 2f96, guest PC 0x0c0558ce */
if(!s->budget--) { s->failed_pc=0x0c0558ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d0;
P_0c0558d0: /* original 2629, guest PC 0x0c0558d0 */
if(!s->budget--) { s->failed_pc=0x0c0558d0u; return 0; }
r[6]&=r[2];
goto P_0c0558d2;
P_0c0558d2: /* original 2f86, guest PC 0x0c0558d2 */
if(!s->budget--) { s->failed_pc=0x0c0558d2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d4;
P_0c0558d4: /* original 5814, guest PC 0x0c0558d4 */
if(!s->budget--) { s->failed_pc=0x0c0558d4u; return 0; }
r[8]=read(ram,r[1]+16,4);
goto P_0c0558d6;
P_0c0558d6: /* original 2329, guest PC 0x0c0558d6 */
if(!s->budget--) { s->failed_pc=0x0c0558d6u; return 0; }
r[3]&=r[2];
goto P_0c0558d8;
P_0c0558d8: /* original 2829, guest PC 0x0c0558d8 */
if(!s->budget--) { s->failed_pc=0x0c0558d8u; return 0; }
r[8]&=r[2];
goto P_0c0558da;
P_0c0558da: /* original 4f22, guest PC 0x0c0558da */
if(!s->budget--) { s->failed_pc=0x0c0558dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558dc;
P_0c0558dc: /* original 4f13, guest PC 0x0c0558dc */
if(!s->budget--) { s->failed_pc=0x0c0558dcu; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c0558de;
P_0c0558de: /* original 4017, guest PC 0x0c0558de */
if(!s->budget--) { s->failed_pc=0x0c0558deu; return 0; }
s->gbr=read(ram,r[0],4); r[0]+=4; s->gbr_known=1;
goto P_0c0558e0;
P_0c0558e0: /* original 402a, guest PC 0x0c0558e0 */
if(!s->budget--) { s->failed_pc=0x0c0558e0u; return 0; }
r[16]=r[0];
goto P_0c0558e2;
P_0c0558e2: /* original 267b, guest PC 0x0c0558e2 */
if(!s->budget--) { s->failed_pc=0x0c0558e2u; return 0; }
r[6]|=r[7];
goto P_0c0558e4;
P_0c0558e4: /* original 237b, guest PC 0x0c0558e4 */
if(!s->budget--) { s->failed_pc=0x0c0558e4u; return 0; }
r[3]|=r[7];
goto P_0c0558e6;
P_0c0558e6: /* original 287b, guest PC 0x0c0558e6 */
if(!s->budget--) { s->failed_pc=0x0c0558e6u; return 0; }
r[8]|=r[7];
goto P_0c0558e8;
P_0c0558e8: /* original 6063, guest PC 0x0c0558e8 */
if(!s->budget--) { s->failed_pc=0x0c0558e8u; return 0; }
r[0]=r[6];
goto P_0c0558ea;
P_0c0558ea: /* original c212, guest PC 0x0c0558ea */
if(!s->budget--) { s->failed_pc=0x0c0558eau; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c0558ec;
P_0c0558ec: /* original 6033, guest PC 0x0c0558ec */
if(!s->budget--) { s->failed_pc=0x0c0558ecu; return 0; }
r[0]=r[3];
goto P_0c0558ee;
P_0c0558ee: /* original c214, guest PC 0x0c0558ee */
if(!s->budget--) { s->failed_pc=0x0c0558eeu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c0558f0;
P_0c0558f0: /* original 6083, guest PC 0x0c0558f0 */
if(!s->budget--) { s->failed_pc=0x0c0558f0u; return 0; }
r[0]=r[8];
goto P_0c0558f2;
P_0c0558f2: /* original c216, guest PC 0x0c0558f2 */
if(!s->budget--) { s->failed_pc=0x0c0558f2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+88,r[0],4);
goto P_0c0558f4;
P_0c0558f4: /* original 5d40, guest PC 0x0c0558f4 */
if(!s->budget--) { s->failed_pc=0x0c0558f4u; return 0; }
r[13]=read(ram,r[4]+0,4);
goto P_0c0558f6;
P_0c0558f6: /* original 6e43, guest PC 0x0c0558f6 */
if(!s->budget--) { s->failed_pc=0x0c0558f6u; return 0; }
r[14]=r[4];
goto P_0c0558f8;
P_0c0558f8: /* original 4f22, guest PC 0x0c0558f8 */
if(!s->budget--) { s->failed_pc=0x0c0558f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558fa;
P_0c0558fa: /* original 60d3, guest PC 0x0c0558fa */
if(!s->budget--) { s->failed_pc=0x0c0558fau; return 0; }
r[0]=r[13];
goto P_0c0558fc;
P_0c0558fc: /* original c83e, guest PC 0x0c0558fc */
if(!s->budget--) { s->failed_pc=0x0c0558fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c0558fe;
P_0c0558fe: /* original 2fd6, guest PC 0x0c0558fe */
if(!s->budget--) { s->failed_pc=0x0c0558feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055900;
P_0c055900: /* original 8927, guest PC 0x0c055900 */
if(!s->budget--) { s->failed_pc=0x0c055900u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c055902;
P_0c055902: /* original d123, guest PC 0x0c055902 */
if(!s->budget--) { s->failed_pc=0x0c055902u; return 0; }
r[1]=read(ram,0x0c055990u,4);
goto P_0c055904;
P_0c055904: /* original 410b, guest PC 0x0c055904 */
if(!s->budget--) { s->failed_pc=0x0c055904u; return 0; }
target=r[1];
r[16]=code_base|0x0c055908u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055908u) { target=s->pc; goto dispatch; }
goto P_0c055908;
P_0c055906: /* original e400, guest PC 0x0c055906 */
if(!s->budget--) { s->failed_pc=0x0c055906u; return 0; }
r[4]=0x00000000u;
goto P_0c055908;
P_0c055908: /* original 60d3, guest PC 0x0c055908 */
if(!s->budget--) { s->failed_pc=0x0c055908u; return 0; }
r[0]=r[13];
goto P_0c05590a;
P_0c05590a: /* original c802, guest PC 0x0c05590a */
if(!s->budget--) { s->failed_pc=0x0c05590au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05590c;
P_0c05590c: /* original d121, guest PC 0x0c05590c */
if(!s->budget--) { s->failed_pc=0x0c05590cu; return 0; }
r[1]=read(ram,0x0c055994u,4);
goto P_0c05590e;
P_0c05590e: /* original 64e3, guest PC 0x0c05590e */
if(!s->budget--) { s->failed_pc=0x0c05590eu; return 0; }
r[4]=r[14];
goto P_0c055910;
P_0c055910: /* original 8d05, guest PC 0x0c055910 */
if(!s->budget--) { s->failed_pc=0x0c055910u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c05591e; }
goto P_0c055914;
P_0c055912: /* original 7408, guest PC 0x0c055912 */
if(!s->budget--) { s->failed_pc=0x0c055912u; return 0; }
r[4]+=0x00000008u;
goto P_0c055914;
P_0c055914: /* original f449, guest PC 0x0c055914 */
if(!s->budget--) { s->failed_pc=0x0c055914u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055916;
P_0c055916: /* original f549, guest PC 0x0c055916 */
if(!s->budget--) { s->failed_pc=0x0c055916u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055918;
P_0c055918: /* original 410b, guest PC 0x0c055918 */
if(!s->budget--) { s->failed_pc=0x0c055918u; return 0; }
target=r[1];
r[16]=code_base|0x0c05591cu;
vf3_matrix_load(s,ram,6,r[4]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05591cu) { target=s->pc; goto dispatch; }
goto P_0c05591c;
P_0c05591a: /* original f648, guest PC 0x0c05591a */
if(!s->budget--) { s->failed_pc=0x0c05591au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c05591c;
P_0c05591c: /* original 60d3, guest PC 0x0c05591c */
if(!s->budget--) { s->failed_pc=0x0c05591cu; return 0; }
r[0]=r[13];
goto P_0c05591e;
P_0c05591e: /* original c838, guest PC 0x0c05591e */
if(!s->budget--) { s->failed_pc=0x0c05591eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&56u)==0)!=0);
goto P_0c055920;
P_0c055920: /* original 8d11, guest PC 0x0c055920 */
if(!s->budget--) { s->failed_pc=0x0c055920u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(cond) { goto P_0c055946; }
goto P_0c055924;
P_0c055922: /* original c820, guest PC 0x0c055922 */
if(!s->budget--) { s->failed_pc=0x0c055922u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c055924;
P_0c055924: /* original d31c, guest PC 0x0c055924 */
if(!s->budget--) { s->failed_pc=0x0c055924u; return 0; }
r[3]=read(ram,0x0c055998u,4);
goto P_0c055926;
P_0c055926: /* original 8902, guest PC 0x0c055926 */
if(!s->budget--) { s->failed_pc=0x0c055926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05592e; }
goto P_0c055928;
P_0c055928: /* original 430b, guest PC 0x0c055928 */
if(!s->budget--) { s->failed_pc=0x0c055928u; return 0; }
target=r[3];
r[16]=code_base|0x0c05592cu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05592cu) { target=s->pc; goto dispatch; }
goto P_0c05592c;
P_0c05592a: /* original 54e7, guest PC 0x0c05592a */
if(!s->budget--) { s->failed_pc=0x0c05592au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05592c;
P_0c05592c: /* original 60d3, guest PC 0x0c05592c */
if(!s->budget--) { s->failed_pc=0x0c05592cu; return 0; }
r[0]=r[13];
goto P_0c05592e;
P_0c05592e: /* original c810, guest PC 0x0c05592e */
if(!s->budget--) { s->failed_pc=0x0c05592eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c055930;
P_0c055930: /* original d21a, guest PC 0x0c055930 */
if(!s->budget--) { s->failed_pc=0x0c055930u; return 0; }
r[2]=read(ram,0x0c05599cu,4);
goto P_0c055932;
P_0c055932: /* original 8902, guest PC 0x0c055932 */
if(!s->budget--) { s->failed_pc=0x0c055932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05593a; }
goto P_0c055934;
P_0c055934: /* original 420b, guest PC 0x0c055934 */
if(!s->budget--) { s->failed_pc=0x0c055934u; return 0; }
target=r[2];
r[16]=code_base|0x0c055938u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055938u) { target=s->pc; goto dispatch; }
goto P_0c055938;
P_0c055936: /* original 54e6, guest PC 0x0c055936 */
if(!s->budget--) { s->failed_pc=0x0c055936u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c055938;
P_0c055938: /* original 60d3, guest PC 0x0c055938 */
if(!s->budget--) { s->failed_pc=0x0c055938u; return 0; }
r[0]=r[13];
goto P_0c05593a;
P_0c05593a: /* original c808, guest PC 0x0c05593a */
if(!s->budget--) { s->failed_pc=0x0c05593au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c05593c;
P_0c05593c: /* original d118, guest PC 0x0c05593c */
if(!s->budget--) { s->failed_pc=0x0c05593cu; return 0; }
r[1]=read(ram,0x0c0559a0u,4);
goto P_0c05593e;
P_0c05593e: /* original 8902, guest PC 0x0c05593e */
if(!s->budget--) { s->failed_pc=0x0c05593eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055946; }
goto P_0c055940;
P_0c055940: /* original 410b, guest PC 0x0c055940 */
if(!s->budget--) { s->failed_pc=0x0c055940u; return 0; }
target=r[1];
r[16]=code_base|0x0c055944u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055944u) { target=s->pc; goto dispatch; }
goto P_0c055944;
P_0c055942: /* original 54e5, guest PC 0x0c055942 */
if(!s->budget--) { s->failed_pc=0x0c055942u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c055944;
P_0c055944: /* original 60d3, guest PC 0x0c055944 */
if(!s->budget--) { s->failed_pc=0x0c055944u; return 0; }
r[0]=r[13];
goto P_0c055946;
P_0c055946: /* original c804, guest PC 0x0c055946 */
if(!s->budget--) { s->failed_pc=0x0c055946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c055948;
P_0c055948: /* original d316, guest PC 0x0c055948 */
if(!s->budget--) { s->failed_pc=0x0c055948u; return 0; }
r[3]=read(ram,0x0c0559a4u,4);
goto P_0c05594a;
P_0c05594a: /* original 8902, guest PC 0x0c05594a */
if(!s->budget--) { s->failed_pc=0x0c05594au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c05594c;
P_0c05594c: /* original 64e3, guest PC 0x0c05594c */
if(!s->budget--) { s->failed_pc=0x0c05594cu; return 0; }
r[4]=r[14];
goto P_0c05594e;
P_0c05594e: /* original 430b, guest PC 0x0c05594e */
if(!s->budget--) { s->failed_pc=0x0c05594eu; return 0; }
target=r[3];
r[16]=code_base|0x0c055952u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055952u) { target=s->pc; goto dispatch; }
goto P_0c055952;
P_0c055950: /* original 7420, guest PC 0x0c055950 */
if(!s->budget--) { s->failed_pc=0x0c055950u; return 0; }
r[4]+=0x00000020u;
goto P_0c055952;
P_0c055952: /* original 54e1, guest PC 0x0c055952 */
if(!s->budget--) { s->failed_pc=0x0c055952u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055954;
P_0c055954: /* original 2448, guest PC 0x0c055954 */
if(!s->budget--) { s->failed_pc=0x0c055954u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055956;
P_0c055956: /* original 2fe6, guest PC 0x0c055956 */
if(!s->budget--) { s->failed_pc=0x0c055956u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055958;
P_0c055958: /* original 8903, guest PC 0x0c055958 */
if(!s->budget--) { s->failed_pc=0x0c055958u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055962; }
goto P_0c05595a;
P_0c05595a: /* original bea1, guest PC 0x0c05595a */
if(!s->budget--) { s->failed_pc=0x0c05595au; return 0; }
target=code_base|0x0c0556a0u; r[16]=code_base|0x0c05595eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05595eu) { target=s->pc; goto dispatch; }
goto P_0c05595e;
P_0c05595c: /* original 0009, guest PC 0x0c05595c */
if(!s->budget--) { s->failed_pc=0x0c05595cu; return 0; }
goto P_0c05595e;
P_0c05595e: /* original 5ef0, guest PC 0x0c05595e */
if(!s->budget--) { s->failed_pc=0x0c05595eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055960;
P_0c055960: /* original 5df1, guest PC 0x0c055960 */
if(!s->budget--) { s->failed_pc=0x0c055960u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c055962;
P_0c055962: /* original 54eb, guest PC 0x0c055962 */
if(!s->budget--) { s->failed_pc=0x0c055962u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c055964;
P_0c055964: /* original 2448, guest PC 0x0c055964 */
if(!s->budget--) { s->failed_pc=0x0c055964u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055966;
P_0c055966: /* original 8903, guest PC 0x0c055966 */
if(!s->budget--) { s->failed_pc=0x0c055966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055970; }
goto P_0c055968;
P_0c055968: /* original bfc4, guest PC 0x0c055968 */
if(!s->budget--) { s->failed_pc=0x0c055968u; return 0; }
target=code_base|0x0c0558f4u; r[16]=code_base|0x0c05596cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05596cu) { target=s->pc; goto dispatch; }
goto P_0c05596c;
P_0c05596a: /* original 0009, guest PC 0x0c05596a */
if(!s->budget--) { s->failed_pc=0x0c05596au; return 0; }
goto P_0c05596c;
P_0c05596c: /* original 5df1, guest PC 0x0c05596c */
if(!s->budget--) { s->failed_pc=0x0c05596cu; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c05596e;
P_0c05596e: /* original 5ef0, guest PC 0x0c05596e */
if(!s->budget--) { s->failed_pc=0x0c05596eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055970;
P_0c055970: /* original 60d3, guest PC 0x0c055970 */
if(!s->budget--) { s->failed_pc=0x0c055970u; return 0; }
r[0]=r[13];
goto P_0c055972;
P_0c055972: /* original c83e, guest PC 0x0c055972 */
if(!s->budget--) { s->failed_pc=0x0c055972u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c055974;
P_0c055974: /* original d10c, guest PC 0x0c055974 */
if(!s->budget--) { s->failed_pc=0x0c055974u; return 0; }
r[1]=read(ram,0x0c0559a8u,4);
goto P_0c055976;
P_0c055976: /* original 7f08, guest PC 0x0c055976 */
if(!s->budget--) { s->failed_pc=0x0c055976u; return 0; }
r[15]+=0x00000008u;
goto P_0c055978;
P_0c055978: /* original 8901, guest PC 0x0c055978 */
if(!s->budget--) { s->failed_pc=0x0c055978u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05597e; }
goto P_0c05597a;
P_0c05597a: /* original 410b, guest PC 0x0c05597a */
if(!s->budget--) { s->failed_pc=0x0c05597au; return 0; }
target=r[1];
r[16]=code_base|0x0c05597eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05597eu) { target=s->pc; goto dispatch; }
goto P_0c05597e;
P_0c05597c: /* original e401, guest PC 0x0c05597c */
if(!s->budget--) { s->failed_pc=0x0c05597cu; return 0; }
r[4]=0x00000001u;
goto P_0c05597e;
P_0c05597e: /* original 54ec, guest PC 0x0c05597e */
if(!s->budget--) { s->failed_pc=0x0c05597eu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c055980;
P_0c055980: /* original 4f26, guest PC 0x0c055980 */
if(!s->budget--) { s->failed_pc=0x0c055980u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055982;
P_0c055982: /* original 2448, guest PC 0x0c055982 */
if(!s->budget--) { s->failed_pc=0x0c055982u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055984;
P_0c055984: /* original 8bb6, guest PC 0x0c055984 */
if(!s->budget--) { s->failed_pc=0x0c055984u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0558f4; }
goto P_0c055986;
P_0c055986: /* original 000b, guest PC 0x0c055986 */
if(!s->budget--) { s->failed_pc=0x0c055986u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055988: /* original 0009, guest PC 0x0c055988 */
if(!s->budget--) { s->failed_pc=0x0c055988u; return 0; }
if(!vf3_matrix_family(0x0c05598au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05598au; return 0; } return 1;
P_0c089764: /* original f571, guest PC 0x0c089764 */
if(!s->budget--) { s->failed_pc=0x0c089764u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c089766;
P_0c089766: /* original 2fe6, guest PC 0x0c089766 */
if(!s->budget--) { s->failed_pc=0x0c089766u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c089768;
P_0c089768: /* original f461, guest PC 0x0c089768 */
if(!s->budget--) { s->failed_pc=0x0c089768u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c08976a;
P_0c08976a: /* original 6e53, guest PC 0x0c08976a */
if(!s->budget--) { s->failed_pc=0x0c08976au; return 0; }
r[14]=r[5];
goto P_0c08976c;
P_0c08976c: /* original 4f22, guest PC 0x0c08976c */
if(!s->budget--) { s->failed_pc=0x0c08976cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08976e;
P_0c08976e: /* original c74b, guest PC 0x0c08976e */
if(!s->budget--) { s->failed_pc=0x0c08976eu; return 0; }
r[0]=code_base|0x0008989cu;
goto P_0c089770;
P_0c089770: /* original 7ffc, guest PC 0x0c089770 */
if(!s->budget--) { s->failed_pc=0x0c089770u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c089772;
P_0c089772: /* original 2f62, guest PC 0x0c089772 */
if(!s->budget--) { s->failed_pc=0x0c089772u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c089774;
P_0c089774: /* original f35c, guest PC 0x0c089774 */
if(!s->budget--) { s->failed_pc=0x0c089774u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c089776;
P_0c089776: /* original f352, guest PC 0x0c089776 */
if(!s->budget--) { s->failed_pc=0x0c089776u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c089778;
P_0c089778: /* original f04c, guest PC 0x0c089778 */
if(!s->budget--) { s->failed_pc=0x0c089778u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08977a;
P_0c08977a: /* original f34e, guest PC 0x0c08977a */
if(!s->budget--) { s->failed_pc=0x0c08977au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c08977c;
P_0c08977c: /* original f53c, guest PC 0x0c08977c */
if(!s->budget--) { s->failed_pc=0x0c08977cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08977e;
P_0c08977e: /* original f585, guest PC 0x0c08977e */
if(!s->budget--) { s->failed_pc=0x0c08977eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[8]))!=0);
goto P_0c089780;
P_0c089780: /* original 8d21, guest PC 0x0c089780 */
if(!s->budget--) { s->failed_pc=0x0c089780u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[0]);
if(cond) { goto P_0c0897c6; }
goto P_0c089784;
P_0c089782: /* original f908, guest PC 0x0c089782 */
if(!s->budget--) { s->failed_pc=0x0c089782u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c089784;
P_0c089784: /* original f892, guest PC 0x0c089784 */
if(!s->budget--) { s->failed_pc=0x0c089784u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[9],r[18],'*');
goto P_0c089786;
P_0c089786: /* original e010, guest PC 0x0c089786 */
if(!s->budget--) { s->failed_pc=0x0c089786u; return 0; }
r[0]=0x00000010u;
goto P_0c089788;
P_0c089788: /* original f487, guest PC 0x0c089788 */
if(!s->budget--) { s->failed_pc=0x0c089788u; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c08978a;
P_0c08978a: /* original 55e9, guest PC 0x0c08978a */
if(!s->budget--) { s->failed_pc=0x0c08978au; return 0; }
r[5]=read(ram,r[14]+36,4);
goto P_0c08978c;
P_0c08978c: /* original 4515, guest PC 0x0c08978c */
if(!s->budget--) { s->failed_pc=0x0c08978cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c08978e;
P_0c08978e: /* original 8914, guest PC 0x0c08978e */
if(!s->budget--) { s->failed_pc=0x0c08978eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0897ba; }
goto P_0c089790;
P_0c089790: /* original e016, guest PC 0x0c089790 */
if(!s->budget--) { s->failed_pc=0x0c089790u; return 0; }
r[0]=0x00000016u;
goto P_0c089792;
P_0c089792: /* original e303, guest PC 0x0c089792 */
if(!s->budget--) { s->failed_pc=0x0c089792u; return 0; }
r[3]=0x00000003u;
goto P_0c089794;
P_0c089794: /* original e2ff, guest PC 0x0c089794 */
if(!s->budget--) { s->failed_pc=0x0c089794u; return 0; }
r[2]=0xffffffffu;
goto P_0c089796;
P_0c089796: /* original 1e29, guest PC 0x0c089796 */
if(!s->budget--) { s->failed_pc=0x0c089796u; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c089798;
P_0c089798: /* original 054c, guest PC 0x0c089798 */
if(!s->budget--) { s->failed_pc=0x0c089798u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08979a;
P_0c08979a: /* original 3533, guest PC 0x0c08979a */
if(!s->budget--) { s->failed_pc=0x0c08979au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c08979c;
P_0c08979c: /* original 890d, guest PC 0x0c08979c */
if(!s->budget--) { s->failed_pc=0x0c08979cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0897ba; }
goto P_0c08979e;
P_0c08979e: /* original 7501, guest PC 0x0c08979e */
if(!s->budget--) { s->failed_pc=0x0c08979eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0897a0;
P_0c0897a0: /* original e20a, guest PC 0x0c0897a0 */
if(!s->budget--) { s->failed_pc=0x0c0897a0u; return 0; }
r[2]=0x0000000au;
goto P_0c0897a2;
P_0c0897a2: /* original 0454, guest PC 0x0c0897a2 */
if(!s->budget--) { s->failed_pc=0x0c0897a2u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0897a4;
P_0c0897a4: /* original d13e, guest PC 0x0c0897a4 */
if(!s->budget--) { s->failed_pc=0x0c0897a4u; return 0; }
r[1]=read(ram,0x0c0898a0u,4);
goto P_0c0897a6;
P_0c0897a6: /* original 410b, guest PC 0x0c0897a6 */
if(!s->budget--) { s->failed_pc=0x0c0897a6u; return 0; }
target=r[1];
r[16]=code_base|0x0c0897aau;
write(ram,r[14]+36,r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0897aau) { target=s->pc; goto dispatch; }
goto P_0c0897aa;
P_0c0897a8: /* original 1e29, guest PC 0x0c0897a8 */
if(!s->budget--) { s->failed_pc=0x0c0897a8u; return 0; }
write(ram,r[14]+36,r[2],4);
goto P_0c0897aa;
P_0c0897aa: /* original e303, guest PC 0x0c0897aa */
if(!s->budget--) { s->failed_pc=0x0c0897aau; return 0; }
r[3]=0x00000003u;
goto P_0c0897ac;
P_0c0897ac: /* original 6403, guest PC 0x0c0897ac */
if(!s->budget--) { s->failed_pc=0x0c0897acu; return 0; }
r[4]=r[0];
goto P_0c0897ae;
P_0c0897ae: /* original d03d, guest PC 0x0c0897ae */
if(!s->budget--) { s->failed_pc=0x0c0897aeu; return 0; }
r[0]=read(ram,0x0c0898a4u,4);
goto P_0c0897b0;
P_0c0897b0: /* original 2439, guest PC 0x0c0897b0 */
if(!s->budget--) { s->failed_pc=0x0c0897b0u; return 0; }
r[4]&=r[3];
goto P_0c0897b2;
P_0c0897b2: /* original d23d, guest PC 0x0c0897b2 */
if(!s->budget--) { s->failed_pc=0x0c0897b2u; return 0; }
r[2]=read(ram,0x0c0898a8u,4);
goto P_0c0897b4;
P_0c0897b4: /* original 4408, guest PC 0x0c0897b4 */
if(!s->budget--) { s->failed_pc=0x0c0897b4u; return 0; }
r[4]<<=2;
goto P_0c0897b6;
P_0c0897b6: /* original 420b, guest PC 0x0c0897b6 */
if(!s->budget--) { s->failed_pc=0x0c0897b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0897bau;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0897bau) { target=s->pc; goto dispatch; }
goto P_0c0897ba;
P_0c0897b8: /* original 044e, guest PC 0x0c0897b8 */
if(!s->budget--) { s->failed_pc=0x0c0897b8u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0897ba;
P_0c0897ba: /* original 63f2, guest PC 0x0c0897ba */
if(!s->budget--) { s->failed_pc=0x0c0897bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0897bc;
P_0c0897bc: /* original e201, guest PC 0x0c0897bc */
if(!s->budget--) { s->failed_pc=0x0c0897bcu; return 0; }
r[2]=0x00000001u;
goto P_0c0897be;
P_0c0897be: /* original 2320, guest PC 0x0c0897be */
if(!s->budget--) { s->failed_pc=0x0c0897beu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0897c0;
P_0c0897c0: /* original 60f2, guest PC 0x0c0897c0 */
if(!s->budget--) { s->failed_pc=0x0c0897c0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0897c2;
P_0c0897c2: /* original 6000, guest PC 0x0c0897c2 */
if(!s->budget--) { s->failed_pc=0x0c0897c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c0897c4;
P_0c0897c4: /* original 80eb, guest PC 0x0c0897c4 */
if(!s->budget--) { s->failed_pc=0x0c0897c4u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0897c6;
P_0c0897c6: /* original 7f04, guest PC 0x0c0897c6 */
if(!s->budget--) { s->failed_pc=0x0c0897c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0897c8;
P_0c0897c8: /* original 4f26, guest PC 0x0c0897c8 */
if(!s->budget--) { s->failed_pc=0x0c0897c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0897ca;
P_0c0897ca: /* original 000b, guest PC 0x0c0897ca */
if(!s->budget--) { s->failed_pc=0x0c0897cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0897cc: /* original 6ef6, guest PC 0x0c0897cc */
if(!s->budget--) { s->failed_pc=0x0c0897ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0897ce;
P_0c0897ce: /* original c738, guest PC 0x0c0897ce */
if(!s->budget--) { s->failed_pc=0x0c0897ceu; return 0; }
r[0]=code_base|0x000898b0u;
goto P_0c0897d0;
P_0c0897d0: /* original 2fe6, guest PC 0x0c0897d0 */
if(!s->budget--) { s->failed_pc=0x0c0897d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d2;
P_0c0897d2: /* original 2fd6, guest PC 0x0c0897d2 */
if(!s->budget--) { s->failed_pc=0x0c0897d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d4;
P_0c0897d4: /* original ed00, guest PC 0x0c0897d4 */
if(!s->budget--) { s->failed_pc=0x0c0897d4u; return 0; }
r[13]=0x00000000u;
goto P_0c0897d6;
P_0c0897d6: /* original 2fc6, guest PC 0x0c0897d6 */
if(!s->budget--) { s->failed_pc=0x0c0897d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897d8;
P_0c0897d8: /* original 6e43, guest PC 0x0c0897d8 */
if(!s->budget--) { s->failed_pc=0x0c0897d8u; return 0; }
r[14]=r[4];
goto P_0c0897da;
P_0c0897da: /* original 2fb6, guest PC 0x0c0897da */
if(!s->budget--) { s->failed_pc=0x0c0897dau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897dc;
P_0c0897dc: /* original eb20, guest PC 0x0c0897dc */
if(!s->budget--) { s->failed_pc=0x0c0897dcu; return 0; }
r[11]=0x00000020u;
goto P_0c0897de;
P_0c0897de: /* original 2fa6, guest PC 0x0c0897de */
if(!s->budget--) { s->failed_pc=0x0c0897deu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e0;
P_0c0897e0: /* original ea7f, guest PC 0x0c0897e0 */
if(!s->budget--) { s->failed_pc=0x0c0897e0u; return 0; }
r[10]=0x0000007fu;
goto P_0c0897e2;
P_0c0897e2: /* original 2f96, guest PC 0x0c0897e2 */
if(!s->budget--) { s->failed_pc=0x0c0897e2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0897e4;
P_0c0897e4: /* original 7e18, guest PC 0x0c0897e4 */
if(!s->budget--) { s->failed_pc=0x0c0897e4u; return 0; }
r[14]+=0x00000018u;
goto P_0c0897e6;
P_0c0897e6: /* original fffb, guest PC 0x0c0897e6 */
if(!s->budget--) { s->failed_pc=0x0c0897e6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0897e8;
P_0c0897e8: /* original f308, guest PC 0x0c0897e8 */
if(!s->budget--) { s->failed_pc=0x0c0897e8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0897ea;
P_0c0897ea: /* original e010, guest PC 0x0c0897ea */
if(!s->budget--) { s->failed_pc=0x0c0897eau; return 0; }
r[0]=0x00000010u;
goto P_0c0897ec;
P_0c0897ec: /* original 4f22, guest PC 0x0c0897ec */
if(!s->budget--) { s->failed_pc=0x0c0897ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0897ee;
P_0c0897ee: /* original dc2f, guest PC 0x0c0897ee */
if(!s->budget--) { s->failed_pc=0x0c0897eeu; return 0; }
r[12]=read(ram,0x0c0898acu,4);
goto P_0c0897f0;
P_0c0897f0: /* original f437, guest PC 0x0c0897f0 */
if(!s->budget--) { s->failed_pc=0x0c0897f0u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0897f2;
P_0c0897f2: /* original 60d3, guest PC 0x0c0897f2 */
if(!s->budget--) { s->failed_pc=0x0c0897f2u; return 0; }
r[0]=r[13];
goto P_0c0897f4;
P_0c0897f4: /* original 814a, guest PC 0x0c0897f4 */
if(!s->budget--) { s->failed_pc=0x0c0897f4u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c0897f6;
P_0c0897f6: /* original e016, guest PC 0x0c0897f6 */
if(!s->budget--) { s->failed_pc=0x0c0897f6u; return 0; }
r[0]=0x00000016u;
goto P_0c0897f8;
P_0c0897f8: /* original 04d4, guest PC 0x0c0897f8 */
if(!s->budget--) { s->failed_pc=0x0c0897f8u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0897fa;
P_0c0897fa: /* original c72e, guest PC 0x0c0897fa */
if(!s->budget--) { s->failed_pc=0x0c0897fau; return 0; }
r[0]=code_base|0x000898b4u;
goto P_0c0897fc;
P_0c0897fc: /* original ff08, guest PC 0x0c0897fc */
if(!s->budget--) { s->failed_pc=0x0c0897fcu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0897fe;
P_0c0897fe: /* original d928, guest PC 0x0c0897fe */
if(!s->budget--) { s->failed_pc=0x0c0897feu; return 0; }
r[9]=read(ram,0x0c0898a0u,4);
goto P_0c089800;
P_0c089800: /* original f3c8, guest PC 0x0c089800 */
if(!s->budget--) { s->failed_pc=0x0c089800u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c089802;
P_0c089802: /* original e00c, guest PC 0x0c089802 */
if(!s->budget--) { s->failed_pc=0x0c089802u; return 0; }
r[0]=0x0000000cu;
goto P_0c089804;
P_0c089804: /* original fe37, guest PC 0x0c089804 */
if(!s->budget--) { s->failed_pc=0x0c089804u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089806;
P_0c089806: /* original e004, guest PC 0x0c089806 */
if(!s->budget--) { s->failed_pc=0x0c089806u; return 0; }
r[0]=0x00000004u;
goto P_0c089808;
P_0c089808: /* original f3c6, guest PC 0x0c089808 */
if(!s->budget--) { s->failed_pc=0x0c089808u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c08980a;
P_0c08980a: /* original e010, guest PC 0x0c08980a */
if(!s->budget--) { s->failed_pc=0x0c08980au; return 0; }
r[0]=0x00000010u;
goto P_0c08980c;
P_0c08980c: /* original fe37, guest PC 0x0c08980c */
if(!s->budget--) { s->failed_pc=0x0c08980cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08980e;
P_0c08980e: /* original e008, guest PC 0x0c08980e */
if(!s->budget--) { s->failed_pc=0x0c08980eu; return 0; }
r[0]=0x00000008u;
goto P_0c089810;
P_0c089810: /* original f3c6, guest PC 0x0c089810 */
if(!s->budget--) { s->failed_pc=0x0c089810u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c089812;
P_0c089812: /* original e014, guest PC 0x0c089812 */
if(!s->budget--) { s->failed_pc=0x0c089812u; return 0; }
r[0]=0x00000014u;
goto P_0c089814;
P_0c089814: /* original fe37, guest PC 0x0c089814 */
if(!s->budget--) { s->failed_pc=0x0c089814u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c089816;
P_0c089816: /* original 84cc, guest PC 0x0c089816 */
if(!s->budget--) { s->failed_pc=0x0c089816u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+12,1);
goto P_0c089818;
P_0c089818: /* original 7c10, guest PC 0x0c089818 */
if(!s->budget--) { s->failed_pc=0x0c089818u; return 0; }
r[12]+=0x00000010u;
goto P_0c08981a;
P_0c08981a: /* original 80ea, guest PC 0x0c08981a */
if(!s->budget--) { s->failed_pc=0x0c08981au; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c08981c;
P_0c08981c: /* original e01c, guest PC 0x0c08981c */
if(!s->budget--) { s->failed_pc=0x0c08981cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08981e;
P_0c08981e: /* original fef7, guest PC 0x0c08981e */
if(!s->budget--) { s->failed_pc=0x0c08981eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c089820;
P_0c089820: /* original 60d3, guest PC 0x0c089820 */
if(!s->budget--) { s->failed_pc=0x0c089820u; return 0; }
r[0]=r[13];
goto P_0c089822;
P_0c089822: /* original 81e3, guest PC 0x0c089822 */
if(!s->budget--) { s->failed_pc=0x0c089822u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089824;
P_0c089824: /* original 80eb, guest PC 0x0c089824 */
if(!s->budget--) { s->failed_pc=0x0c089824u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c089826;
P_0c089826: /* original 1e09, guest PC 0x0c089826 */
if(!s->budget--) { s->failed_pc=0x0c089826u; return 0; }
write(ram,r[14]+36,r[0],4);
goto P_0c089828;
P_0c089828: /* original 490b, guest PC 0x0c089828 */
if(!s->budget--) { s->failed_pc=0x0c089828u; return 0; }
target=r[9];
r[16]=code_base|0x0c08982cu;
write(ram,r[14]+8,r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08982cu) { target=s->pc; goto dispatch; }
goto P_0c08982c;
P_0c08982a: /* original 81e4, guest PC 0x0c08982a */
if(!s->budget--) { s->failed_pc=0x0c08982au; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c08982c;
P_0c08982c: /* original 6403, guest PC 0x0c08982c */
if(!s->budget--) { s->failed_pc=0x0c08982cu; return 0; }
r[4]=r[0];
goto P_0c08982e;
P_0c08982e: /* original 24a9, guest PC 0x0c08982e */
if(!s->budget--) { s->failed_pc=0x0c08982eu; return 0; }
r[4]&=r[10];
goto P_0c089830;
P_0c089830: /* original 4b10, guest PC 0x0c089830 */
if(!s->budget--) { s->failed_pc=0x0c089830u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c089832;
P_0c089832: /* original 81e3, guest PC 0x0c089832 */
if(!s->budget--) { s->failed_pc=0x0c089832u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c089834;
P_0c089834: /* original 2e41, guest PC 0x0c089834 */
if(!s->budget--) { s->failed_pc=0x0c089834u; return 0; }
write(ram,r[14],r[4],2);
goto P_0c089836;
P_0c089836: /* original 8fe3, guest PC 0x0c089836 */
if(!s->budget--) { s->failed_pc=0x0c089836u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000028u;
if(!cond) { goto P_0c089800; }
goto P_0c08983a;
P_0c089838: /* original 7e28, guest PC 0x0c089838 */
if(!s->budget--) { s->failed_pc=0x0c089838u; return 0; }
r[14]+=0x00000028u;
goto P_0c08983a;
P_0c08983a: /* original 4f26, guest PC 0x0c08983a */
if(!s->budget--) { s->failed_pc=0x0c08983au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08983c;
P_0c08983c: /* original fff9, guest PC 0x0c08983c */
if(!s->budget--) { s->failed_pc=0x0c08983cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08983e;
P_0c08983e: /* original 69f6, guest PC 0x0c08983e */
if(!s->budget--) { s->failed_pc=0x0c08983eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c089840;
P_0c089840: /* original 6af6, guest PC 0x0c089840 */
if(!s->budget--) { s->failed_pc=0x0c089840u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c089842;
P_0c089842: /* original 6bf6, guest PC 0x0c089842 */
if(!s->budget--) { s->failed_pc=0x0c089842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c089844;
P_0c089844: /* original 6cf6, guest PC 0x0c089844 */
if(!s->budget--) { s->failed_pc=0x0c089844u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c089846;
P_0c089846: /* original 6df6, guest PC 0x0c089846 */
if(!s->budget--) { s->failed_pc=0x0c089846u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c089848;
P_0c089848: /* original 000b, guest PC 0x0c089848 */
if(!s->budget--) { s->failed_pc=0x0c089848u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08984a: /* original 6ef6, guest PC 0x0c08984a */
if(!s->budget--) { s->failed_pc=0x0c08984au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08984cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
