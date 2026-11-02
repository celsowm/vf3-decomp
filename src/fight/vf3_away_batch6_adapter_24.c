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
int vf3_away_batch6_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c054640u: goto P_0c054640;
case 0x0c054642u: goto P_0c054642;
case 0x0c054644u: goto P_0c054644;
case 0x0c054646u: goto P_0c054646;
case 0x0c054648u: goto P_0c054648;
case 0x0c05464au: goto P_0c05464a;
case 0x0c05464cu: goto P_0c05464c;
case 0x0c05464eu: goto P_0c05464e;
case 0x0c054650u: goto P_0c054650;
case 0x0c054652u: goto P_0c054652;
case 0x0c054654u: goto P_0c054654;
case 0x0c054656u: goto P_0c054656;
case 0x0c054658u: goto P_0c054658;
case 0x0c05465au: goto P_0c05465a;
case 0x0c05465cu: goto P_0c05465c;
case 0x0c05465eu: goto P_0c05465e;
case 0x0c054660u: goto P_0c054660;
case 0x0c054662u: goto P_0c054662;
case 0x0c054664u: goto P_0c054664;
case 0x0c054666u: goto P_0c054666;
case 0x0c054668u: goto P_0c054668;
case 0x0c05466au: goto P_0c05466a;
case 0x0c05466cu: goto P_0c05466c;
case 0x0c05466eu: goto P_0c05466e;
case 0x0c054670u: goto P_0c054670;
case 0x0c054672u: goto P_0c054672;
case 0x0c054674u: goto P_0c054674;
case 0x0c054676u: goto P_0c054676;
case 0x0c054678u: goto P_0c054678;
case 0x0c05467au: goto P_0c05467a;
case 0x0c05467cu: goto P_0c05467c;
case 0x0c05467eu: goto P_0c05467e;
case 0x0c054680u: goto P_0c054680;
case 0x0c054682u: goto P_0c054682;
case 0x0c054684u: goto P_0c054684;
case 0x0c054686u: goto P_0c054686;
case 0x0c054688u: goto P_0c054688;
case 0x0c05468au: goto P_0c05468a;
case 0x0c05468cu: goto P_0c05468c;
case 0x0c05468eu: goto P_0c05468e;
case 0x0c054690u: goto P_0c054690;
case 0x0c054692u: goto P_0c054692;
case 0x0c054694u: goto P_0c054694;
case 0x0c054696u: goto P_0c054696;
case 0x0c054698u: goto P_0c054698;
case 0x0c05469au: goto P_0c05469a;
case 0x0c05469cu: goto P_0c05469c;
case 0x0c05469eu: goto P_0c05469e;
case 0x0c0546a0u: goto P_0c0546a0;
case 0x0c0546a2u: goto P_0c0546a2;
case 0x0c0546a4u: goto P_0c0546a4;
case 0x0c0546a6u: goto P_0c0546a6;
case 0x0c0546a8u: goto P_0c0546a8;
case 0x0c0546aau: goto P_0c0546aa;
case 0x0c0546acu: goto P_0c0546ac;
case 0x0c0546aeu: goto P_0c0546ae;
case 0x0c0546b0u: goto P_0c0546b0;
case 0x0c0546b2u: goto P_0c0546b2;
case 0x0c0546b4u: goto P_0c0546b4;
case 0x0c0546b6u: goto P_0c0546b6;
case 0x0c0546b8u: goto P_0c0546b8;
case 0x0c0546bau: goto P_0c0546ba;
case 0x0c0546bcu: goto P_0c0546bc;
case 0x0c0546beu: goto P_0c0546be;
case 0x0c0546c0u: goto P_0c0546c0;
case 0x0c0546c2u: goto P_0c0546c2;
case 0x0c0546c4u: goto P_0c0546c4;
case 0x0c0546c6u: goto P_0c0546c6;
case 0x0c0546c8u: goto P_0c0546c8;
case 0x0c0546cau: goto P_0c0546ca;
case 0x0c0546ccu: goto P_0c0546cc;
case 0x0c0546ceu: goto P_0c0546ce;
case 0x0c0546d0u: goto P_0c0546d0;
case 0x0c0546d2u: goto P_0c0546d2;
case 0x0c0546d4u: goto P_0c0546d4;
case 0x0c0546d6u: goto P_0c0546d6;
case 0x0c0546d8u: goto P_0c0546d8;
case 0x0c0546dau: goto P_0c0546da;
case 0x0c0546dcu: goto P_0c0546dc;
case 0x0c0546deu: goto P_0c0546de;
case 0x0c0546e0u: goto P_0c0546e0;
case 0x0c0546e2u: goto P_0c0546e2;
case 0x0c0546e4u: goto P_0c0546e4;
case 0x0c0546e6u: goto P_0c0546e6;
case 0x0c0546e8u: goto P_0c0546e8;
case 0x0c054704u: goto P_0c054704;
case 0x0c054706u: goto P_0c054706;
case 0x0c054708u: goto P_0c054708;
case 0x0c05470au: goto P_0c05470a;
case 0x0c05470cu: goto P_0c05470c;
case 0x0c05470eu: goto P_0c05470e;
case 0x0c054710u: goto P_0c054710;
case 0x0c054712u: goto P_0c054712;
case 0x0c054714u: goto P_0c054714;
case 0x0c054716u: goto P_0c054716;
case 0x0c054718u: goto P_0c054718;
case 0x0c05471au: goto P_0c05471a;
case 0x0c05471cu: goto P_0c05471c;
case 0x0c05471eu: goto P_0c05471e;
case 0x0c054720u: goto P_0c054720;
case 0x0c054722u: goto P_0c054722;
case 0x0c054724u: goto P_0c054724;
case 0x0c054726u: goto P_0c054726;
case 0x0c054728u: goto P_0c054728;
case 0x0c05472au: goto P_0c05472a;
case 0x0c05472cu: goto P_0c05472c;
case 0x0c05472eu: goto P_0c05472e;
case 0x0c054730u: goto P_0c054730;
case 0x0c054732u: goto P_0c054732;
case 0x0c054734u: goto P_0c054734;
case 0x0c054736u: goto P_0c054736;
case 0x0c054738u: goto P_0c054738;
case 0x0c05473au: goto P_0c05473a;
case 0x0c05473cu: goto P_0c05473c;
case 0x0c05473eu: goto P_0c05473e;
case 0x0c054740u: goto P_0c054740;
case 0x0c054742u: goto P_0c054742;
case 0x0c054744u: goto P_0c054744;
case 0x0c054746u: goto P_0c054746;
case 0x0c054748u: goto P_0c054748;
case 0x0c05474au: goto P_0c05474a;
case 0x0c05474cu: goto P_0c05474c;
case 0x0c05474eu: goto P_0c05474e;
case 0x0c054750u: goto P_0c054750;
case 0x0c054752u: goto P_0c054752;
case 0x0c054754u: goto P_0c054754;
case 0x0c054756u: goto P_0c054756;
case 0x0c054758u: goto P_0c054758;
case 0x0c05475au: goto P_0c05475a;
case 0x0c05475cu: goto P_0c05475c;
case 0x0c05475eu: goto P_0c05475e;
case 0x0c054760u: goto P_0c054760;
case 0x0c054762u: goto P_0c054762;
case 0x0c054764u: goto P_0c054764;
case 0x0c054766u: goto P_0c054766;
case 0x0c054768u: goto P_0c054768;
case 0x0c05476au: goto P_0c05476a;
case 0x0c05476cu: goto P_0c05476c;
case 0x0c05476eu: goto P_0c05476e;
case 0x0c054770u: goto P_0c054770;
case 0x0c054772u: goto P_0c054772;
case 0x0c054774u: goto P_0c054774;
case 0x0c054776u: goto P_0c054776;
case 0x0c054778u: goto P_0c054778;
case 0x0c05477au: goto P_0c05477a;
case 0x0c05477cu: goto P_0c05477c;
case 0x0c05477eu: goto P_0c05477e;
case 0x0c054780u: goto P_0c054780;
case 0x0c054782u: goto P_0c054782;
case 0x0c054784u: goto P_0c054784;
case 0x0c054786u: goto P_0c054786;
case 0x0c054788u: goto P_0c054788;
case 0x0c05478au: goto P_0c05478a;
case 0x0c05478cu: goto P_0c05478c;
case 0x0c05478eu: goto P_0c05478e;
case 0x0c054790u: goto P_0c054790;
case 0x0c054792u: goto P_0c054792;
case 0x0c054794u: goto P_0c054794;
case 0x0c054796u: goto P_0c054796;
case 0x0c054798u: goto P_0c054798;
case 0x0c05479au: goto P_0c05479a;
case 0x0c05479cu: goto P_0c05479c;
case 0x0c05479eu: goto P_0c05479e;
case 0x0c0547a0u: goto P_0c0547a0;
case 0x0c0547a2u: goto P_0c0547a2;
case 0x0c0547a4u: goto P_0c0547a4;
case 0x0c0547a6u: goto P_0c0547a6;
case 0x0c0547a8u: goto P_0c0547a8;
case 0x0c0547aau: goto P_0c0547aa;
case 0x0c0547acu: goto P_0c0547ac;
case 0x0c0547aeu: goto P_0c0547ae;
case 0x0c0547b0u: goto P_0c0547b0;
case 0x0c0547b2u: goto P_0c0547b2;
case 0x0c0547b4u: goto P_0c0547b4;
case 0x0c0547b6u: goto P_0c0547b6;
case 0x0c0547b8u: goto P_0c0547b8;
case 0x0c0547bau: goto P_0c0547ba;
case 0x0c0547bcu: goto P_0c0547bc;
case 0x0c0547beu: goto P_0c0547be;
case 0x0c0547c0u: goto P_0c0547c0;
case 0x0c0547c2u: goto P_0c0547c2;
case 0x0c0547c4u: goto P_0c0547c4;
case 0x0c0547c6u: goto P_0c0547c6;
case 0x0c0547c8u: goto P_0c0547c8;
case 0x0c0547cau: goto P_0c0547ca;
case 0x0c0547ccu: goto P_0c0547cc;
case 0x0c0547ceu: goto P_0c0547ce;
case 0x0c0547d0u: goto P_0c0547d0;
case 0x0c0547d2u: goto P_0c0547d2;
case 0x0c0547d4u: goto P_0c0547d4;
case 0x0c0547d6u: goto P_0c0547d6;
case 0x0c0547d8u: goto P_0c0547d8;
case 0x0c0547dau: goto P_0c0547da;
case 0x0c0547dcu: goto P_0c0547dc;
case 0x0c0547deu: goto P_0c0547de;
case 0x0c0547e0u: goto P_0c0547e0;
case 0x0c0547e2u: goto P_0c0547e2;
case 0x0c0547e4u: goto P_0c0547e4;
case 0x0c0547e6u: goto P_0c0547e6;
case 0x0c0547e8u: goto P_0c0547e8;
case 0x0c0547eau: goto P_0c0547ea;
case 0x0c0547ecu: goto P_0c0547ec;
case 0x0c0547eeu: goto P_0c0547ee;
case 0x0c0547f0u: goto P_0c0547f0;
case 0x0c0547f2u: goto P_0c0547f2;
case 0x0c0547f4u: goto P_0c0547f4;
case 0x0c0547f6u: goto P_0c0547f6;
case 0x0c0547f8u: goto P_0c0547f8;
case 0x0c0547fau: goto P_0c0547fa;
case 0x0c0547fcu: goto P_0c0547fc;
case 0x0c0547feu: goto P_0c0547fe;
case 0x0c054800u: goto P_0c054800;
case 0x0c054802u: goto P_0c054802;
case 0x0c054804u: goto P_0c054804;
case 0x0c054806u: goto P_0c054806;
default: return vf3_matrix_family(target,s,ram);
}
P_0c054640: /* original 2fe6, guest PC 0x0c054640 */
if(!s->budget--) { s->failed_pc=0x0c054640u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054642;
P_0c054642: /* original 2fd6, guest PC 0x0c054642 */
if(!s->budget--) { s->failed_pc=0x0c054642u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054644;
P_0c054644: /* original 2fc6, guest PC 0x0c054644 */
if(!s->budget--) { s->failed_pc=0x0c054644u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054646;
P_0c054646: /* original 2fb6, guest PC 0x0c054646 */
if(!s->budget--) { s->failed_pc=0x0c054646u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054648;
P_0c054648: /* original 2fa6, guest PC 0x0c054648 */
if(!s->budget--) { s->failed_pc=0x0c054648u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05464a;
P_0c05464a: /* original 6a43, guest PC 0x0c05464a */
if(!s->budget--) { s->failed_pc=0x0c05464au; return 0; }
r[10]=r[4];
goto P_0c05464c;
P_0c05464c: /* original 2f96, guest PC 0x0c05464c */
if(!s->budget--) { s->failed_pc=0x0c05464cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05464e;
P_0c05464e: /* original 2f86, guest PC 0x0c05464e */
if(!s->budget--) { s->failed_pc=0x0c05464eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054650;
P_0c054650: /* original 4f22, guest PC 0x0c054650 */
if(!s->budget--) { s->failed_pc=0x0c054650u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054652;
P_0c054652: /* original 7fc8, guest PC 0x0c054652 */
if(!s->budget--) { s->failed_pc=0x0c054652u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c054654;
P_0c054654: /* original 1f51, guest PC 0x0c054654 */
if(!s->budget--) { s->failed_pc=0x0c054654u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c054656;
P_0c054656: /* original 6063, guest PC 0x0c054656 */
if(!s->budget--) { s->failed_pc=0x0c054656u; return 0; }
r[0]=r[6];
goto P_0c054658;
P_0c054658: /* original 0009, guest PC 0x0c054658 */
if(!s->budget--) { s->failed_pc=0x0c054658u; return 0; }
goto P_0c05465a;
P_0c05465a: /* original 6ef3, guest PC 0x0c05465a */
if(!s->budget--) { s->failed_pc=0x0c05465au; return 0; }
r[14]=r[15];
goto P_0c05465c;
P_0c05465c: /* original 81f4, guest PC 0x0c05465c */
if(!s->budget--) { s->failed_pc=0x0c05465cu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c05465e;
P_0c05465e: /* original e604, guest PC 0x0c05465e */
if(!s->budget--) { s->failed_pc=0x0c05465eu; return 0; }
r[6]=0x00000004u;
goto P_0c054660;
P_0c054660: /* original dc22, guest PC 0x0c054660 */
if(!s->budget--) { s->failed_pc=0x0c054660u; return 0; }
r[12]=read(ram,0x0c0546ecu,4);
goto P_0c054662;
P_0c054662: /* original e500, guest PC 0x0c054662 */
if(!s->budget--) { s->failed_pc=0x0c054662u; return 0; }
r[5]=0x00000000u;
goto P_0c054664;
P_0c054664: /* original 2f72, guest PC 0x0c054664 */
if(!s->budget--) { s->failed_pc=0x0c054664u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c054666;
P_0c054666: /* original 7e2c, guest PC 0x0c054666 */
if(!s->budget--) { s->failed_pc=0x0c054666u; return 0; }
r[14]+=0x0000002cu;
goto P_0c054668;
P_0c054668: /* original 4c0b, guest PC 0x0c054668 */
if(!s->budget--) { s->failed_pc=0x0c054668u; return 0; }
target=r[12];
r[16]=code_base|0x0c05466cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05466cu) { target=s->pc; goto dispatch; }
goto P_0c05466c;
P_0c05466a: /* original 64e3, guest PC 0x0c05466a */
if(!s->budget--) { s->failed_pc=0x0c05466au; return 0; }
r[4]=r[14];
goto P_0c05466c;
P_0c05466c: /* original d820, guest PC 0x0c05466c */
if(!s->budget--) { s->failed_pc=0x0c05466cu; return 0; }
r[8]=read(ram,0x0c0546f0u,4);
goto P_0c05466e;
P_0c05466e: /* original e608, guest PC 0x0c05466e */
if(!s->budget--) { s->failed_pc=0x0c05466eu; return 0; }
r[6]=0x00000008u;
goto P_0c054670;
P_0c054670: /* original 65f2, guest PC 0x0c054670 */
if(!s->budget--) { s->failed_pc=0x0c054670u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c054672;
P_0c054672: /* original 64e3, guest PC 0x0c054672 */
if(!s->budget--) { s->failed_pc=0x0c054672u; return 0; }
r[4]=r[14];
goto P_0c054674;
P_0c054674: /* original 7404, guest PC 0x0c054674 */
if(!s->budget--) { s->failed_pc=0x0c054674u; return 0; }
r[4]+=0x00000004u;
goto P_0c054676;
P_0c054676: /* original 480b, guest PC 0x0c054676 */
if(!s->budget--) { s->failed_pc=0x0c054676u; return 0; }
target=r[8];
r[16]=code_base|0x0c05467au;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05467au) { target=s->pc; goto dispatch; }
goto P_0c05467a;
P_0c054678: /* original 1f43, guest PC 0x0c054678 */
if(!s->budget--) { s->failed_pc=0x0c054678u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c05467a;
P_0c05467a: /* original 6bf3, guest PC 0x0c05467a */
if(!s->budget--) { s->failed_pc=0x0c05467au; return 0; }
r[11]=r[15];
goto P_0c05467c;
P_0c05467c: /* original 7b20, guest PC 0x0c05467c */
if(!s->budget--) { s->failed_pc=0x0c05467cu; return 0; }
r[11]+=0x00000020u;
goto P_0c05467e;
P_0c05467e: /* original e604, guest PC 0x0c05467e */
if(!s->budget--) { s->failed_pc=0x0c05467eu; return 0; }
r[6]=0x00000004u;
goto P_0c054680;
P_0c054680: /* original e500, guest PC 0x0c054680 */
if(!s->budget--) { s->failed_pc=0x0c054680u; return 0; }
r[5]=0x00000000u;
goto P_0c054682;
P_0c054682: /* original 4c0b, guest PC 0x0c054682 */
if(!s->budget--) { s->failed_pc=0x0c054682u; return 0; }
target=r[12];
r[16]=code_base|0x0c054686u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054686u) { target=s->pc; goto dispatch; }
goto P_0c054686;
P_0c054684: /* original 64b3, guest PC 0x0c054684 */
if(!s->budget--) { s->failed_pc=0x0c054684u; return 0; }
r[4]=r[11];
goto P_0c054686;
P_0c054686: /* original e608, guest PC 0x0c054686 */
if(!s->budget--) { s->failed_pc=0x0c054686u; return 0; }
r[6]=0x00000008u;
goto P_0c054688;
P_0c054688: /* original 55f1, guest PC 0x0c054688 */
if(!s->budget--) { s->failed_pc=0x0c054688u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05468a;
P_0c05468a: /* original 64b3, guest PC 0x0c05468a */
if(!s->budget--) { s->failed_pc=0x0c05468au; return 0; }
r[4]=r[11];
goto P_0c05468c;
P_0c05468c: /* original 480b, guest PC 0x0c05468c */
if(!s->budget--) { s->failed_pc=0x0c05468cu; return 0; }
target=r[8];
r[16]=code_base|0x0c054690u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054690u) { target=s->pc; goto dispatch; }
goto P_0c054690;
P_0c05468e: /* original 7404, guest PC 0x0c05468e */
if(!s->budget--) { s->failed_pc=0x0c05468eu; return 0; }
r[4]+=0x00000004u;
goto P_0c054690;
P_0c054690: /* original 6df3, guest PC 0x0c054690 */
if(!s->budget--) { s->failed_pc=0x0c054690u; return 0; }
r[13]=r[15];
goto P_0c054692;
P_0c054692: /* original 7d10, guest PC 0x0c054692 */
if(!s->budget--) { s->failed_pc=0x0c054692u; return 0; }
r[13]+=0x00000010u;
goto P_0c054694;
P_0c054694: /* original e610, guest PC 0x0c054694 */
if(!s->budget--) { s->failed_pc=0x0c054694u; return 0; }
r[6]=0x00000010u;
goto P_0c054696;
P_0c054696: /* original e500, guest PC 0x0c054696 */
if(!s->budget--) { s->failed_pc=0x0c054696u; return 0; }
r[5]=0x00000000u;
goto P_0c054698;
P_0c054698: /* original 4c0b, guest PC 0x0c054698 */
if(!s->budget--) { s->failed_pc=0x0c054698u; return 0; }
target=r[12];
r[16]=code_base|0x0c05469cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05469cu) { target=s->pc; goto dispatch; }
goto P_0c05469c;
P_0c05469a: /* original 64d3, guest PC 0x0c05469a */
if(!s->budget--) { s->failed_pc=0x0c05469au; return 0; }
r[4]=r[13];
goto P_0c05469c;
P_0c05469c: /* original dc15, guest PC 0x0c05469c */
if(!s->budget--) { s->failed_pc=0x0c05469cu; return 0; }
r[12]=read(ram,0x0c0546f4u,4);
goto P_0c05469e;
P_0c05469e: /* original 63d3, guest PC 0x0c05469e */
if(!s->budget--) { s->failed_pc=0x0c05469eu; return 0; }
r[3]=r[13];
goto P_0c0546a0;
P_0c0546a0: /* original 730b, guest PC 0x0c0546a0 */
if(!s->budget--) { s->failed_pc=0x0c0546a0u; return 0; }
r[3]+=0x0000000bu;
goto P_0c0546a2;
P_0c0546a2: /* original 2f32, guest PC 0x0c0546a2 */
if(!s->budget--) { s->failed_pc=0x0c0546a2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0546a4;
P_0c0546a4: /* original a01b, guest PC 0x0c0546a4 */
if(!s->budget--) { s->failed_pc=0x0c0546a4u; return 0; }
r[9]=0x00000042u;
goto P_0c0546de;
P_0c0546a6: /* original e942, guest PC 0x0c0546a6 */
if(!s->budget--) { s->failed_pc=0x0c0546a6u; return 0; }
r[9]=0x00000042u;
goto P_0c0546a8;
P_0c0546a8: /* original e50c, guest PC 0x0c0546a8 */
if(!s->budget--) { s->failed_pc=0x0c0546a8u; return 0; }
r[5]=0x0000000cu;
goto P_0c0546aa;
P_0c0546aa: /* original 4c0b, guest PC 0x0c0546aa */
if(!s->budget--) { s->failed_pc=0x0c0546aau; return 0; }
target=r[12];
r[16]=code_base|0x0c0546aeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0546aeu) { target=s->pc; goto dispatch; }
goto P_0c0546ae;
P_0c0546ac: /* original 64d3, guest PC 0x0c0546ac */
if(!s->budget--) { s->failed_pc=0x0c0546acu; return 0; }
r[4]=r[13];
goto P_0c0546ae;
P_0c0546ae: /* original e70c, guest PC 0x0c0546ae */
if(!s->budget--) { s->failed_pc=0x0c0546aeu; return 0; }
r[7]=0x0000000cu;
goto P_0c0546b0;
P_0c0546b0: /* original d311, guest PC 0x0c0546b0 */
if(!s->budget--) { s->failed_pc=0x0c0546b0u; return 0; }
r[3]=read(ram,0x0c0546f8u,4);
goto P_0c0546b2;
P_0c0546b2: /* original 66b3, guest PC 0x0c0546b2 */
if(!s->budget--) { s->failed_pc=0x0c0546b2u; return 0; }
r[6]=r[11];
goto P_0c0546b4;
P_0c0546b4: /* original 65e3, guest PC 0x0c0546b4 */
if(!s->budget--) { s->failed_pc=0x0c0546b4u; return 0; }
r[5]=r[14];
goto P_0c0546b6;
P_0c0546b6: /* original 430b, guest PC 0x0c0546b6 */
if(!s->budget--) { s->failed_pc=0x0c0546b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0546bau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0546bau) { target=s->pc; goto dispatch; }
goto P_0c0546ba;
P_0c0546b8: /* original e400, guest PC 0x0c0546b8 */
if(!s->budget--) { s->failed_pc=0x0c0546b8u; return 0; }
r[4]=0x00000000u;
goto P_0c0546ba;
P_0c0546ba: /* original 4011, guest PC 0x0c0546ba */
if(!s->budget--) { s->failed_pc=0x0c0546bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0546bc;
P_0c0546bc: /* original 8f06, guest PC 0x0c0546bc */
if(!s->budget--) { s->failed_pc=0x0c0546bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0546cc; }
goto P_0c0546c0;
P_0c0546be: /* original 0009, guest PC 0x0c0546be */
if(!s->budget--) { s->failed_pc=0x0c0546beu; return 0; }
goto P_0c0546c0;
P_0c0546c0: /* original 63f2, guest PC 0x0c0546c0 */
if(!s->budget--) { s->failed_pc=0x0c0546c0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0546c2;
P_0c0546c2: /* original 6230, guest PC 0x0c0546c2 */
if(!s->budget--) { s->failed_pc=0x0c0546c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0546c4;
P_0c0546c4: /* original 7201, guest PC 0x0c0546c4 */
if(!s->budget--) { s->failed_pc=0x0c0546c4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0546c6;
P_0c0546c6: /* original 2320, guest PC 0x0c0546c6 */
if(!s->budget--) { s->failed_pc=0x0c0546c6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0546c8;
P_0c0546c8: /* original a005, guest PC 0x0c0546c8 */
if(!s->budget--) { s->failed_pc=0x0c0546c8u; return 0; }
goto P_0c0546d6;
P_0c0546ca: /* original 0009, guest PC 0x0c0546ca */
if(!s->budget--) { s->failed_pc=0x0c0546cau; return 0; }
goto P_0c0546cc;
P_0c0546cc: /* original d20b, guest PC 0x0c0546cc */
if(!s->budget--) { s->failed_pc=0x0c0546ccu; return 0; }
r[2]=read(ram,0x0c0546fcu,4);
goto P_0c0546ce;
P_0c0546ce: /* original e60c, guest PC 0x0c0546ce */
if(!s->budget--) { s->failed_pc=0x0c0546ceu; return 0; }
r[6]=0x0000000cu;
goto P_0c0546d0;
P_0c0546d0: /* original 65b3, guest PC 0x0c0546d0 */
if(!s->budget--) { s->failed_pc=0x0c0546d0u; return 0; }
r[5]=r[11];
goto P_0c0546d2;
P_0c0546d2: /* original 420b, guest PC 0x0c0546d2 */
if(!s->budget--) { s->failed_pc=0x0c0546d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0546d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0546d6u) { target=s->pc; goto dispatch; }
goto P_0c0546d6;
P_0c0546d4: /* original 64e3, guest PC 0x0c0546d4 */
if(!s->budget--) { s->failed_pc=0x0c0546d4u; return 0; }
r[4]=r[14];
goto P_0c0546d6;
P_0c0546d6: /* original e50c, guest PC 0x0c0546d6 */
if(!s->budget--) { s->failed_pc=0x0c0546d6u; return 0; }
r[5]=0x0000000cu;
goto P_0c0546d8;
P_0c0546d8: /* original 4c0b, guest PC 0x0c0546d8 */
if(!s->budget--) { s->failed_pc=0x0c0546d8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0546dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0546dcu) { target=s->pc; goto dispatch; }
goto P_0c0546dc;
P_0c0546da: /* original 64e3, guest PC 0x0c0546da */
if(!s->budget--) { s->failed_pc=0x0c0546dau; return 0; }
r[4]=r[14];
goto P_0c0546dc;
P_0c0546dc: /* original 79ff, guest PC 0x0c0546dc */
if(!s->budget--) { s->failed_pc=0x0c0546dcu; return 0; }
r[9]+=0xffffffffu;
goto P_0c0546de;
P_0c0546de: /* original 2998, guest PC 0x0c0546de */
if(!s->budget--) { s->failed_pc=0x0c0546deu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0546e0;
P_0c0546e0: /* original 8fe2, guest PC 0x0c0546e0 */
if(!s->budget--) { s->failed_pc=0x0c0546e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0546a8; }
goto P_0c0546e4;
P_0c0546e2: /* original 0009, guest PC 0x0c0546e2 */
if(!s->budget--) { s->failed_pc=0x0c0546e2u; return 0; }
goto P_0c0546e4;
P_0c0546e4: /* original d906, guest PC 0x0c0546e4 */
if(!s->budget--) { s->failed_pc=0x0c0546e4u; return 0; }
r[9]=read(ram,0x0c054700u,4);
goto P_0c0546e6;
P_0c0546e6: /* original a011, guest PC 0x0c0546e6 */
if(!s->budget--) { s->failed_pc=0x0c0546e6u; return 0; }
r[11]=0x00000002u;
goto P_0c05470c;
P_0c0546e8: /* original eb02, guest PC 0x0c0546e8 */
if(!s->budget--) { s->failed_pc=0x0c0546e8u; return 0; }
r[11]=0x00000002u;
if(!vf3_matrix_family(0x0c0546eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0546eau; return 0; } return 1;
P_0c054704: /* original e510, guest PC 0x0c054704 */
if(!s->budget--) { s->failed_pc=0x0c054704u; return 0; }
r[5]=0x00000010u;
goto P_0c054706;
P_0c054706: /* original 490b, guest PC 0x0c054706 */
if(!s->budget--) { s->failed_pc=0x0c054706u; return 0; }
target=r[9];
r[16]=code_base|0x0c05470au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05470au) { target=s->pc; goto dispatch; }
goto P_0c05470a;
P_0c054708: /* original 64d3, guest PC 0x0c054708 */
if(!s->budget--) { s->failed_pc=0x0c054708u; return 0; }
r[4]=r[13];
goto P_0c05470a;
P_0c05470a: /* original 7bff, guest PC 0x0c05470a */
if(!s->budget--) { s->failed_pc=0x0c05470au; return 0; }
r[11]+=0xffffffffu;
goto P_0c05470c;
P_0c05470c: /* original 2bb8, guest PC 0x0c05470c */
if(!s->budget--) { s->failed_pc=0x0c05470cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05470e;
P_0c05470e: /* original 8ff9, guest PC 0x0c05470e */
if(!s->budget--) { s->failed_pc=0x0c05470eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054704; }
goto P_0c054712;
P_0c054710: /* original 0009, guest PC 0x0c054710 */
if(!s->budget--) { s->failed_pc=0x0c054710u; return 0; }
goto P_0c054712;
P_0c054712: /* original 62e0, guest PC 0x0c054712 */
if(!s->budget--) { s->failed_pc=0x0c054712u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[2]=tmp;
goto P_0c054714;
P_0c054714: /* original 2228, guest PC 0x0c054714 */
if(!s->budget--) { s->failed_pc=0x0c054714u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054716;
P_0c054716: /* original 8f2d, guest PC 0x0c054716 */
if(!s->budget--) { s->failed_pc=0x0c054716u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05471a;
P_0c054718: /* original 0009, guest PC 0x0c054718 */
if(!s->budget--) { s->failed_pc=0x0c054718u; return 0; }
goto P_0c05471a;
P_0c05471a: /* original 84e1, guest PC 0x0c05471a */
if(!s->budget--) { s->failed_pc=0x0c05471au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c05471c;
P_0c05471c: /* original 2008, guest PC 0x0c05471c */
if(!s->budget--) { s->failed_pc=0x0c05471cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05471e;
P_0c05471e: /* original 8f29, guest PC 0x0c05471e */
if(!s->budget--) { s->failed_pc=0x0c05471eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054722;
P_0c054720: /* original 0009, guest PC 0x0c054720 */
if(!s->budget--) { s->failed_pc=0x0c054720u; return 0; }
goto P_0c054722;
P_0c054722: /* original 84e2, guest PC 0x0c054722 */
if(!s->budget--) { s->failed_pc=0x0c054722u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c054724;
P_0c054724: /* original 2008, guest PC 0x0c054724 */
if(!s->budget--) { s->failed_pc=0x0c054724u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054726;
P_0c054726: /* original 8f25, guest PC 0x0c054726 */
if(!s->budget--) { s->failed_pc=0x0c054726u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05472a;
P_0c054728: /* original 0009, guest PC 0x0c054728 */
if(!s->budget--) { s->failed_pc=0x0c054728u; return 0; }
goto P_0c05472a;
P_0c05472a: /* original 84e3, guest PC 0x0c05472a */
if(!s->budget--) { s->failed_pc=0x0c05472au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c05472c;
P_0c05472c: /* original 2008, guest PC 0x0c05472c */
if(!s->budget--) { s->failed_pc=0x0c05472cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05472e;
P_0c05472e: /* original 8f21, guest PC 0x0c05472e */
if(!s->budget--) { s->failed_pc=0x0c05472eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054732;
P_0c054730: /* original 0009, guest PC 0x0c054730 */
if(!s->budget--) { s->failed_pc=0x0c054730u; return 0; }
goto P_0c054732;
P_0c054732: /* original 53f3, guest PC 0x0c054732 */
if(!s->budget--) { s->failed_pc=0x0c054732u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c054734;
P_0c054734: /* original 6230, guest PC 0x0c054734 */
if(!s->budget--) { s->failed_pc=0x0c054734u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c054736;
P_0c054736: /* original 2228, guest PC 0x0c054736 */
if(!s->budget--) { s->failed_pc=0x0c054736u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054738;
P_0c054738: /* original 8f1c, guest PC 0x0c054738 */
if(!s->budget--) { s->failed_pc=0x0c054738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05473c;
P_0c05473a: /* original 0009, guest PC 0x0c05473a */
if(!s->budget--) { s->failed_pc=0x0c05473au; return 0; }
goto P_0c05473c;
P_0c05473c: /* original 84e5, guest PC 0x0c05473c */
if(!s->budget--) { s->failed_pc=0x0c05473cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c05473e;
P_0c05473e: /* original 2008, guest PC 0x0c05473e */
if(!s->budget--) { s->failed_pc=0x0c05473eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054740;
P_0c054740: /* original 8f18, guest PC 0x0c054740 */
if(!s->budget--) { s->failed_pc=0x0c054740u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054744;
P_0c054742: /* original 0009, guest PC 0x0c054742 */
if(!s->budget--) { s->failed_pc=0x0c054742u; return 0; }
goto P_0c054744;
P_0c054744: /* original 84e6, guest PC 0x0c054744 */
if(!s->budget--) { s->failed_pc=0x0c054744u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c054746;
P_0c054746: /* original 2008, guest PC 0x0c054746 */
if(!s->budget--) { s->failed_pc=0x0c054746u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054748;
P_0c054748: /* original 8f14, guest PC 0x0c054748 */
if(!s->budget--) { s->failed_pc=0x0c054748u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05474c;
P_0c05474a: /* original 0009, guest PC 0x0c05474a */
if(!s->budget--) { s->failed_pc=0x0c05474au; return 0; }
goto P_0c05474c;
P_0c05474c: /* original 84e7, guest PC 0x0c05474c */
if(!s->budget--) { s->failed_pc=0x0c05474cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c05474e;
P_0c05474e: /* original 2008, guest PC 0x0c05474e */
if(!s->budget--) { s->failed_pc=0x0c05474eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054750;
P_0c054750: /* original 8f10, guest PC 0x0c054750 */
if(!s->budget--) { s->failed_pc=0x0c054750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054754;
P_0c054752: /* original 0009, guest PC 0x0c054752 */
if(!s->budget--) { s->failed_pc=0x0c054752u; return 0; }
goto P_0c054754;
P_0c054754: /* original 84e8, guest PC 0x0c054754 */
if(!s->budget--) { s->failed_pc=0x0c054754u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c054756;
P_0c054756: /* original 2008, guest PC 0x0c054756 */
if(!s->budget--) { s->failed_pc=0x0c054756u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054758;
P_0c054758: /* original 8f0c, guest PC 0x0c054758 */
if(!s->budget--) { s->failed_pc=0x0c054758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05475c;
P_0c05475a: /* original 0009, guest PC 0x0c05475a */
if(!s->budget--) { s->failed_pc=0x0c05475au; return 0; }
goto P_0c05475c;
P_0c05475c: /* original 84e9, guest PC 0x0c05475c */
if(!s->budget--) { s->failed_pc=0x0c05475cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+9,1);
goto P_0c05475e;
P_0c05475e: /* original 2008, guest PC 0x0c05475e */
if(!s->budget--) { s->failed_pc=0x0c05475eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054760;
P_0c054760: /* original 8f08, guest PC 0x0c054760 */
if(!s->budget--) { s->failed_pc=0x0c054760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c054764;
P_0c054762: /* original 0009, guest PC 0x0c054762 */
if(!s->budget--) { s->failed_pc=0x0c054762u; return 0; }
goto P_0c054764;
P_0c054764: /* original 84ea, guest PC 0x0c054764 */
if(!s->budget--) { s->failed_pc=0x0c054764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c054766;
P_0c054766: /* original 2008, guest PC 0x0c054766 */
if(!s->budget--) { s->failed_pc=0x0c054766u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054768;
P_0c054768: /* original 8f04, guest PC 0x0c054768 */
if(!s->budget--) { s->failed_pc=0x0c054768u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054774; }
goto P_0c05476c;
P_0c05476a: /* original 0009, guest PC 0x0c05476a */
if(!s->budget--) { s->failed_pc=0x0c05476au; return 0; }
goto P_0c05476c;
P_0c05476c: /* original 84eb, guest PC 0x0c05476c */
if(!s->budget--) { s->failed_pc=0x0c05476cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c05476e;
P_0c05476e: /* original 2008, guest PC 0x0c05476e */
if(!s->budget--) { s->failed_pc=0x0c05476eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054770;
P_0c054770: /* original 8d03, guest PC 0x0c054770 */
if(!s->budget--) { s->failed_pc=0x0c054770u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05477a; }
goto P_0c054774;
P_0c054772: /* original 0009, guest PC 0x0c054772 */
if(!s->budget--) { s->failed_pc=0x0c054772u; return 0; }
goto P_0c054774;
P_0c054774: /* original 84dc, guest PC 0x0c054774 */
if(!s->budget--) { s->failed_pc=0x0c054774u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+12,1);
goto P_0c054776;
P_0c054776: /* original cb20, guest PC 0x0c054776 */
if(!s->budget--) { s->failed_pc=0x0c054776u; return 0; }
r[0]|=32u;
goto P_0c054778;
P_0c054778: /* original 80dc, guest PC 0x0c054778 */
if(!s->budget--) { s->failed_pc=0x0c054778u; return 0; }
write(ram,r[13]+12,r[0],1);
goto P_0c05477a;
P_0c05477a: /* original 63a1, guest PC 0x0c05477a */
if(!s->budget--) { s->failed_pc=0x0c05477au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[3]=tmp;
goto P_0c05477c;
P_0c05477c: /* original 85f4, guest PC 0x0c05477c */
if(!s->budget--) { s->failed_pc=0x0c05477cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c05477e;
P_0c05477e: /* original 3038, guest PC 0x0c05477e */
if(!s->budget--) { s->failed_pc=0x0c05477eu; return 0; }
r[0]-=r[3];
goto P_0c054780;
P_0c054780: /* original 2a01, guest PC 0x0c054780 */
if(!s->budget--) { s->failed_pc=0x0c054780u; return 0; }
write(ram,r[10],r[0],2);
goto P_0c054782;
P_0c054782: /* original 84d4, guest PC 0x0c054782 */
if(!s->budget--) { s->failed_pc=0x0c054782u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c054784;
P_0c054784: /* original 2008, guest PC 0x0c054784 */
if(!s->budget--) { s->failed_pc=0x0c054784u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054786;
P_0c054786: /* original 8f21, guest PC 0x0c054786 */
if(!s->budget--) { s->failed_pc=0x0c054786u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c05478a;
P_0c054788: /* original 0009, guest PC 0x0c054788 */
if(!s->budget--) { s->failed_pc=0x0c054788u; return 0; }
goto P_0c05478a;
P_0c05478a: /* original 84d5, guest PC 0x0c05478a */
if(!s->budget--) { s->failed_pc=0x0c05478au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+5,1);
goto P_0c05478c;
P_0c05478c: /* original 2008, guest PC 0x0c05478c */
if(!s->budget--) { s->failed_pc=0x0c05478cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05478e;
P_0c05478e: /* original 8f1d, guest PC 0x0c05478e */
if(!s->budget--) { s->failed_pc=0x0c05478eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c054792;
P_0c054790: /* original 0009, guest PC 0x0c054790 */
if(!s->budget--) { s->failed_pc=0x0c054790u; return 0; }
goto P_0c054792;
P_0c054792: /* original 84d6, guest PC 0x0c054792 */
if(!s->budget--) { s->failed_pc=0x0c054792u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+6,1);
goto P_0c054794;
P_0c054794: /* original 2008, guest PC 0x0c054794 */
if(!s->budget--) { s->failed_pc=0x0c054794u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c054796;
P_0c054796: /* original 8f19, guest PC 0x0c054796 */
if(!s->budget--) { s->failed_pc=0x0c054796u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c05479a;
P_0c054798: /* original 0009, guest PC 0x0c054798 */
if(!s->budget--) { s->failed_pc=0x0c054798u; return 0; }
goto P_0c05479a;
P_0c05479a: /* original 84d7, guest PC 0x0c05479a */
if(!s->budget--) { s->failed_pc=0x0c05479au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+7,1);
goto P_0c05479c;
P_0c05479c: /* original 2008, guest PC 0x0c05479c */
if(!s->budget--) { s->failed_pc=0x0c05479cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05479e;
P_0c05479e: /* original 8f15, guest PC 0x0c05479e */
if(!s->budget--) { s->failed_pc=0x0c05479eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547a2;
P_0c0547a0: /* original 0009, guest PC 0x0c0547a0 */
if(!s->budget--) { s->failed_pc=0x0c0547a0u; return 0; }
goto P_0c0547a2;
P_0c0547a2: /* original 84d8, guest PC 0x0c0547a2 */
if(!s->budget--) { s->failed_pc=0x0c0547a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+8,1);
goto P_0c0547a4;
P_0c0547a4: /* original 2008, guest PC 0x0c0547a4 */
if(!s->budget--) { s->failed_pc=0x0c0547a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547a6;
P_0c0547a6: /* original 8f11, guest PC 0x0c0547a6 */
if(!s->budget--) { s->failed_pc=0x0c0547a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547aa;
P_0c0547a8: /* original 0009, guest PC 0x0c0547a8 */
if(!s->budget--) { s->failed_pc=0x0c0547a8u; return 0; }
goto P_0c0547aa;
P_0c0547aa: /* original 84d9, guest PC 0x0c0547aa */
if(!s->budget--) { s->failed_pc=0x0c0547aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+9,1);
goto P_0c0547ac;
P_0c0547ac: /* original 2008, guest PC 0x0c0547ac */
if(!s->budget--) { s->failed_pc=0x0c0547acu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547ae;
P_0c0547ae: /* original 8f0d, guest PC 0x0c0547ae */
if(!s->budget--) { s->failed_pc=0x0c0547aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547b2;
P_0c0547b0: /* original 0009, guest PC 0x0c0547b0 */
if(!s->budget--) { s->failed_pc=0x0c0547b0u; return 0; }
goto P_0c0547b2;
P_0c0547b2: /* original 84da, guest PC 0x0c0547b2 */
if(!s->budget--) { s->failed_pc=0x0c0547b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c0547b4;
P_0c0547b4: /* original 2008, guest PC 0x0c0547b4 */
if(!s->budget--) { s->failed_pc=0x0c0547b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547b6;
P_0c0547b6: /* original 8f09, guest PC 0x0c0547b6 */
if(!s->budget--) { s->failed_pc=0x0c0547b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547ba;
P_0c0547b8: /* original 0009, guest PC 0x0c0547b8 */
if(!s->budget--) { s->failed_pc=0x0c0547b8u; return 0; }
goto P_0c0547ba;
P_0c0547ba: /* original 63f2, guest PC 0x0c0547ba */
if(!s->budget--) { s->failed_pc=0x0c0547bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0547bc;
P_0c0547bc: /* original 6230, guest PC 0x0c0547bc */
if(!s->budget--) { s->failed_pc=0x0c0547bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0547be;
P_0c0547be: /* original 2228, guest PC 0x0c0547be */
if(!s->budget--) { s->failed_pc=0x0c0547beu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0547c0;
P_0c0547c0: /* original 8f04, guest PC 0x0c0547c0 */
if(!s->budget--) { s->failed_pc=0x0c0547c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0547cc; }
goto P_0c0547c4;
P_0c0547c2: /* original 0009, guest PC 0x0c0547c2 */
if(!s->budget--) { s->failed_pc=0x0c0547c2u; return 0; }
goto P_0c0547c4;
P_0c0547c4: /* original 84dc, guest PC 0x0c0547c4 */
if(!s->budget--) { s->failed_pc=0x0c0547c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+12,1);
goto P_0c0547c6;
P_0c0547c6: /* original 2008, guest PC 0x0c0547c6 */
if(!s->budget--) { s->failed_pc=0x0c0547c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0547c8;
P_0c0547c8: /* original 8d0f, guest PC 0x0c0547c8 */
if(!s->budget--) { s->failed_pc=0x0c0547c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0547ea; }
goto P_0c0547cc;
P_0c0547ca: /* original 0009, guest PC 0x0c0547ca */
if(!s->budget--) { s->failed_pc=0x0c0547cau; return 0; }
goto P_0c0547cc;
P_0c0547cc: /* original 9b1c, guest PC 0x0c0547cc */
if(!s->budget--) { s->failed_pc=0x0c0547ccu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054808u,2);
goto P_0c0547ce;
P_0c0547ce: /* original 6ed3, guest PC 0x0c0547ce */
if(!s->budget--) { s->failed_pc=0x0c0547ceu; return 0; }
r[14]=r[13];
goto P_0c0547d0;
P_0c0547d0: /* original a006, guest PC 0x0c0547d0 */
if(!s->budget--) { s->failed_pc=0x0c0547d0u; return 0; }
r[14]+=0x00000004u;
goto P_0c0547e0;
P_0c0547d2: /* original 7e04, guest PC 0x0c0547d2 */
if(!s->budget--) { s->failed_pc=0x0c0547d2u; return 0; }
r[14]+=0x00000004u;
goto P_0c0547d4;
P_0c0547d4: /* original e509, guest PC 0x0c0547d4 */
if(!s->budget--) { s->failed_pc=0x0c0547d4u; return 0; }
r[5]=0x00000009u;
goto P_0c0547d6;
P_0c0547d6: /* original 4c0b, guest PC 0x0c0547d6 */
if(!s->budget--) { s->failed_pc=0x0c0547d6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0547dau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0547dau) { target=s->pc; goto dispatch; }
goto P_0c0547da;
P_0c0547d8: /* original 64e3, guest PC 0x0c0547d8 */
if(!s->budget--) { s->failed_pc=0x0c0547d8u; return 0; }
r[4]=r[14];
goto P_0c0547da;
P_0c0547da: /* original 62a1, guest PC 0x0c0547da */
if(!s->budget--) { s->failed_pc=0x0c0547dau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[2]=tmp;
goto P_0c0547dc;
P_0c0547dc: /* original 72ff, guest PC 0x0c0547dc */
if(!s->budget--) { s->failed_pc=0x0c0547dcu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0547de;
P_0c0547de: /* original 2a21, guest PC 0x0c0547de */
if(!s->budget--) { s->failed_pc=0x0c0547deu; return 0; }
write(ram,r[10],r[2],2);
goto P_0c0547e0;
P_0c0547e0: /* original 63e0, guest PC 0x0c0547e0 */
if(!s->budget--) { s->failed_pc=0x0c0547e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c0547e2;
P_0c0547e2: /* original 633c, guest PC 0x0c0547e2 */
if(!s->budget--) { s->failed_pc=0x0c0547e2u; return 0; }
r[3]=r[3]&255u;
goto P_0c0547e4;
P_0c0547e4: /* original 23b8, guest PC 0x0c0547e4 */
if(!s->budget--) { s->failed_pc=0x0c0547e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0547e6;
P_0c0547e6: /* original 8df5, guest PC 0x0c0547e6 */
if(!s->budget--) { s->failed_pc=0x0c0547e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0547d4; }
goto P_0c0547ea;
P_0c0547e8: /* original 0009, guest PC 0x0c0547e8 */
if(!s->budget--) { s->failed_pc=0x0c0547e8u; return 0; }
goto P_0c0547ea;
P_0c0547ea: /* original e609, guest PC 0x0c0547ea */
if(!s->budget--) { s->failed_pc=0x0c0547eau; return 0; }
r[6]=0x00000009u;
goto P_0c0547ec;
P_0c0547ec: /* original 65d3, guest PC 0x0c0547ec */
if(!s->budget--) { s->failed_pc=0x0c0547ecu; return 0; }
r[5]=r[13];
goto P_0c0547ee;
P_0c0547ee: /* original 7504, guest PC 0x0c0547ee */
if(!s->budget--) { s->failed_pc=0x0c0547eeu; return 0; }
r[5]+=0x00000004u;
goto P_0c0547f0;
P_0c0547f0: /* original 480b, guest PC 0x0c0547f0 */
if(!s->budget--) { s->failed_pc=0x0c0547f0u; return 0; }
target=r[8];
r[16]=code_base|0x0c0547f4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0547f4u) { target=s->pc; goto dispatch; }
goto P_0c0547f4;
P_0c0547f2: /* original 54f1, guest PC 0x0c0547f2 */
if(!s->budget--) { s->failed_pc=0x0c0547f2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0547f4;
P_0c0547f4: /* original 7f38, guest PC 0x0c0547f4 */
if(!s->budget--) { s->failed_pc=0x0c0547f4u; return 0; }
r[15]+=0x00000038u;
goto P_0c0547f6;
P_0c0547f6: /* original 4f26, guest PC 0x0c0547f6 */
if(!s->budget--) { s->failed_pc=0x0c0547f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0547f8;
P_0c0547f8: /* original 68f6, guest PC 0x0c0547f8 */
if(!s->budget--) { s->failed_pc=0x0c0547f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0547fa;
P_0c0547fa: /* original 69f6, guest PC 0x0c0547fa */
if(!s->budget--) { s->failed_pc=0x0c0547fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0547fc;
P_0c0547fc: /* original 6af6, guest PC 0x0c0547fc */
if(!s->budget--) { s->failed_pc=0x0c0547fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0547fe;
P_0c0547fe: /* original 6bf6, guest PC 0x0c0547fe */
if(!s->budget--) { s->failed_pc=0x0c0547feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054800;
P_0c054800: /* original 6cf6, guest PC 0x0c054800 */
if(!s->budget--) { s->failed_pc=0x0c054800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c054802;
P_0c054802: /* original 6df6, guest PC 0x0c054802 */
if(!s->budget--) { s->failed_pc=0x0c054802u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054804;
P_0c054804: /* original 000b, guest PC 0x0c054804 */
if(!s->budget--) { s->failed_pc=0x0c054804u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054806: /* original 6ef6, guest PC 0x0c054806 */
if(!s->budget--) { s->failed_pc=0x0c054806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054808u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054808u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
