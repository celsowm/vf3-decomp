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
int vf3_away_batch19_adapter_38(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a058cu: goto P_0c0a058c;
case 0x0c0a058eu: goto P_0c0a058e;
case 0x0c0a0590u: goto P_0c0a0590;
case 0x0c0a0592u: goto P_0c0a0592;
case 0x0c0a0594u: goto P_0c0a0594;
case 0x0c0a0596u: goto P_0c0a0596;
case 0x0c0a0598u: goto P_0c0a0598;
case 0x0c0a059au: goto P_0c0a059a;
case 0x0c0a059cu: goto P_0c0a059c;
case 0x0c0a059eu: goto P_0c0a059e;
case 0x0c0a05a0u: goto P_0c0a05a0;
case 0x0c0a05a2u: goto P_0c0a05a2;
case 0x0c0a05a4u: goto P_0c0a05a4;
case 0x0c0a05a6u: goto P_0c0a05a6;
case 0x0c0a05a8u: goto P_0c0a05a8;
case 0x0c0a05aau: goto P_0c0a05aa;
case 0x0c0a05acu: goto P_0c0a05ac;
case 0x0c0a05aeu: goto P_0c0a05ae;
case 0x0c0a05b0u: goto P_0c0a05b0;
case 0x0c0a05b2u: goto P_0c0a05b2;
case 0x0c0a05b4u: goto P_0c0a05b4;
case 0x0c0a05b6u: goto P_0c0a05b6;
case 0x0c0a05b8u: goto P_0c0a05b8;
case 0x0c0a05bau: goto P_0c0a05ba;
case 0x0c0a05bcu: goto P_0c0a05bc;
case 0x0c0a05beu: goto P_0c0a05be;
case 0x0c0a05c0u: goto P_0c0a05c0;
case 0x0c0a05c2u: goto P_0c0a05c2;
case 0x0c0a05c4u: goto P_0c0a05c4;
case 0x0c0a05c6u: goto P_0c0a05c6;
case 0x0c0a05c8u: goto P_0c0a05c8;
case 0x0c0a05cau: goto P_0c0a05ca;
case 0x0c0a05ccu: goto P_0c0a05cc;
case 0x0c0a05fcu: goto P_0c0a05fc;
case 0x0c0a05feu: goto P_0c0a05fe;
case 0x0c0a0600u: goto P_0c0a0600;
case 0x0c0a0602u: goto P_0c0a0602;
case 0x0c0a0604u: goto P_0c0a0604;
case 0x0c0a0606u: goto P_0c0a0606;
case 0x0c0a0608u: goto P_0c0a0608;
case 0x0c0a060au: goto P_0c0a060a;
case 0x0c0a060cu: goto P_0c0a060c;
case 0x0c0a060eu: goto P_0c0a060e;
case 0x0c0a0610u: goto P_0c0a0610;
case 0x0c0a0612u: goto P_0c0a0612;
case 0x0c0a0614u: goto P_0c0a0614;
case 0x0c0a0616u: goto P_0c0a0616;
case 0x0c0a0618u: goto P_0c0a0618;
case 0x0c0a061au: goto P_0c0a061a;
case 0x0c0a061cu: goto P_0c0a061c;
case 0x0c0a061eu: goto P_0c0a061e;
case 0x0c0a0620u: goto P_0c0a0620;
case 0x0c0a0622u: goto P_0c0a0622;
case 0x0c0a0624u: goto P_0c0a0624;
case 0x0c0a0626u: goto P_0c0a0626;
case 0x0c0a0628u: goto P_0c0a0628;
case 0x0c0a062au: goto P_0c0a062a;
case 0x0c0a062cu: goto P_0c0a062c;
case 0x0c0a062eu: goto P_0c0a062e;
case 0x0c0a0630u: goto P_0c0a0630;
case 0x0c0a0632u: goto P_0c0a0632;
case 0x0c0a0634u: goto P_0c0a0634;
case 0x0c0a0636u: goto P_0c0a0636;
case 0x0c0a0638u: goto P_0c0a0638;
case 0x0c0a063au: goto P_0c0a063a;
case 0x0c0a063cu: goto P_0c0a063c;
case 0x0c0a063eu: goto P_0c0a063e;
case 0x0c0a0640u: goto P_0c0a0640;
case 0x0c0a0642u: goto P_0c0a0642;
case 0x0c0a0644u: goto P_0c0a0644;
case 0x0c0a0646u: goto P_0c0a0646;
case 0x0c0a0648u: goto P_0c0a0648;
case 0x0c0a064au: goto P_0c0a064a;
case 0x0c0a064cu: goto P_0c0a064c;
case 0x0c0a064eu: goto P_0c0a064e;
case 0x0c0a0650u: goto P_0c0a0650;
case 0x0c0a0652u: goto P_0c0a0652;
case 0x0c0a0654u: goto P_0c0a0654;
case 0x0c0a0656u: goto P_0c0a0656;
case 0x0c0a0658u: goto P_0c0a0658;
case 0x0c0a065au: goto P_0c0a065a;
case 0x0c0a065cu: goto P_0c0a065c;
case 0x0c0a065eu: goto P_0c0a065e;
case 0x0c0a0660u: goto P_0c0a0660;
case 0x0c0a0662u: goto P_0c0a0662;
case 0x0c0a0664u: goto P_0c0a0664;
case 0x0c0a0666u: goto P_0c0a0666;
case 0x0c0a0668u: goto P_0c0a0668;
case 0x0c0a066au: goto P_0c0a066a;
case 0x0c0a066cu: goto P_0c0a066c;
case 0x0c0a066eu: goto P_0c0a066e;
case 0x0c0a0670u: goto P_0c0a0670;
case 0x0c0a0672u: goto P_0c0a0672;
case 0x0c0a0674u: goto P_0c0a0674;
case 0x0c0a0676u: goto P_0c0a0676;
case 0x0c0a0678u: goto P_0c0a0678;
case 0x0c0a067au: goto P_0c0a067a;
case 0x0c0a067cu: goto P_0c0a067c;
case 0x0c0a067eu: goto P_0c0a067e;
case 0x0c0a0680u: goto P_0c0a0680;
case 0x0c0a0682u: goto P_0c0a0682;
case 0x0c0a0684u: goto P_0c0a0684;
case 0x0c0a0686u: goto P_0c0a0686;
case 0x0c0a0688u: goto P_0c0a0688;
case 0x0c0a068au: goto P_0c0a068a;
case 0x0c0a068cu: goto P_0c0a068c;
case 0x0c0a068eu: goto P_0c0a068e;
case 0x0c0a0690u: goto P_0c0a0690;
case 0x0c0a0692u: goto P_0c0a0692;
case 0x0c0a0694u: goto P_0c0a0694;
case 0x0c0a0696u: goto P_0c0a0696;
case 0x0c0a0698u: goto P_0c0a0698;
case 0x0c0a069au: goto P_0c0a069a;
case 0x0c0a069cu: goto P_0c0a069c;
case 0x0c0a069eu: goto P_0c0a069e;
case 0x0c0a06a0u: goto P_0c0a06a0;
case 0x0c0a06a2u: goto P_0c0a06a2;
case 0x0c0a06a4u: goto P_0c0a06a4;
case 0x0c0a06a6u: goto P_0c0a06a6;
case 0x0c0a06a8u: goto P_0c0a06a8;
case 0x0c0a06aau: goto P_0c0a06aa;
case 0x0c0a06acu: goto P_0c0a06ac;
case 0x0c0a06aeu: goto P_0c0a06ae;
case 0x0c0a06b0u: goto P_0c0a06b0;
case 0x0c0a06b2u: goto P_0c0a06b2;
case 0x0c0a06b4u: goto P_0c0a06b4;
case 0x0c0a06b6u: goto P_0c0a06b6;
case 0x0c0a06b8u: goto P_0c0a06b8;
case 0x0c0a06bau: goto P_0c0a06ba;
case 0x0c0a06bcu: goto P_0c0a06bc;
case 0x0c0a06beu: goto P_0c0a06be;
case 0x0c0a06c0u: goto P_0c0a06c0;
case 0x0c0a06c2u: goto P_0c0a06c2;
case 0x0c0a06c4u: goto P_0c0a06c4;
case 0x0c0a06c6u: goto P_0c0a06c6;
case 0x0c0a06c8u: goto P_0c0a06c8;
case 0x0c0a06cau: goto P_0c0a06ca;
case 0x0c0a06ccu: goto P_0c0a06cc;
case 0x0c0a06ceu: goto P_0c0a06ce;
case 0x0c0a06d0u: goto P_0c0a06d0;
case 0x0c0a06d2u: goto P_0c0a06d2;
case 0x0c0a06d4u: goto P_0c0a06d4;
case 0x0c0a06d6u: goto P_0c0a06d6;
case 0x0c0a06d8u: goto P_0c0a06d8;
case 0x0c0a06dau: goto P_0c0a06da;
case 0x0c0a06dcu: goto P_0c0a06dc;
case 0x0c0a06deu: goto P_0c0a06de;
case 0x0c0a06e0u: goto P_0c0a06e0;
case 0x0c0a06e2u: goto P_0c0a06e2;
case 0x0c0a06e4u: goto P_0c0a06e4;
case 0x0c0a06e6u: goto P_0c0a06e6;
case 0x0c0a06e8u: goto P_0c0a06e8;
case 0x0c0a06eau: goto P_0c0a06ea;
case 0x0c0a06ecu: goto P_0c0a06ec;
case 0x0c0a06eeu: goto P_0c0a06ee;
case 0x0c0a06f0u: goto P_0c0a06f0;
case 0x0c0a06f2u: goto P_0c0a06f2;
case 0x0c0a0718u: goto P_0c0a0718;
case 0x0c0a071au: goto P_0c0a071a;
case 0x0c0a071cu: goto P_0c0a071c;
case 0x0c0a071eu: goto P_0c0a071e;
case 0x0c0a0720u: goto P_0c0a0720;
case 0x0c0a0722u: goto P_0c0a0722;
case 0x0c0a0724u: goto P_0c0a0724;
case 0x0c0a0726u: goto P_0c0a0726;
case 0x0c0a0728u: goto P_0c0a0728;
case 0x0c0a072au: goto P_0c0a072a;
case 0x0c0a072cu: goto P_0c0a072c;
case 0x0c0a072eu: goto P_0c0a072e;
case 0x0c0a0730u: goto P_0c0a0730;
case 0x0c0a0732u: goto P_0c0a0732;
case 0x0c0a0734u: goto P_0c0a0734;
case 0x0c0a0736u: goto P_0c0a0736;
case 0x0c0a0738u: goto P_0c0a0738;
case 0x0c0a073au: goto P_0c0a073a;
case 0x0c0a073cu: goto P_0c0a073c;
case 0x0c0a073eu: goto P_0c0a073e;
case 0x0c0a0740u: goto P_0c0a0740;
case 0x0c0a0742u: goto P_0c0a0742;
case 0x0c0a0744u: goto P_0c0a0744;
case 0x0c0a0746u: goto P_0c0a0746;
case 0x0c0a0748u: goto P_0c0a0748;
case 0x0c0a074au: goto P_0c0a074a;
case 0x0c0a074cu: goto P_0c0a074c;
case 0x0c0a074eu: goto P_0c0a074e;
case 0x0c0a0750u: goto P_0c0a0750;
case 0x0c0a0752u: goto P_0c0a0752;
case 0x0c0a0754u: goto P_0c0a0754;
case 0x0c0a0756u: goto P_0c0a0756;
case 0x0c0a0758u: goto P_0c0a0758;
case 0x0c0a075au: goto P_0c0a075a;
case 0x0c0a075cu: goto P_0c0a075c;
case 0x0c0a075eu: goto P_0c0a075e;
case 0x0c0a0760u: goto P_0c0a0760;
case 0x0c0a0762u: goto P_0c0a0762;
case 0x0c0a0764u: goto P_0c0a0764;
case 0x0c0a0766u: goto P_0c0a0766;
case 0x0c0a0768u: goto P_0c0a0768;
case 0x0c0a076au: goto P_0c0a076a;
case 0x0c0a076cu: goto P_0c0a076c;
case 0x0c0a076eu: goto P_0c0a076e;
case 0x0c0a0770u: goto P_0c0a0770;
case 0x0c0a0772u: goto P_0c0a0772;
case 0x0c0a0774u: goto P_0c0a0774;
case 0x0c0a0776u: goto P_0c0a0776;
case 0x0c0a0778u: goto P_0c0a0778;
case 0x0c0a077au: goto P_0c0a077a;
case 0x0c0a077cu: goto P_0c0a077c;
case 0x0c0a077eu: goto P_0c0a077e;
case 0x0c0a0780u: goto P_0c0a0780;
case 0x0c0a0782u: goto P_0c0a0782;
case 0x0c0a0784u: goto P_0c0a0784;
case 0x0c0a0786u: goto P_0c0a0786;
case 0x0c0a0788u: goto P_0c0a0788;
case 0x0c0a078au: goto P_0c0a078a;
case 0x0c0a078cu: goto P_0c0a078c;
case 0x0c0a078eu: goto P_0c0a078e;
case 0x0c0a0790u: goto P_0c0a0790;
case 0x0c0a0792u: goto P_0c0a0792;
case 0x0c0a0794u: goto P_0c0a0794;
case 0x0c0a0796u: goto P_0c0a0796;
case 0x0c0a0798u: goto P_0c0a0798;
case 0x0c0a079au: goto P_0c0a079a;
case 0x0c0a079cu: goto P_0c0a079c;
case 0x0c0a079eu: goto P_0c0a079e;
case 0x0c0a07a0u: goto P_0c0a07a0;
case 0x0c0a07a2u: goto P_0c0a07a2;
case 0x0c0a07a4u: goto P_0c0a07a4;
case 0x0c0a07a6u: goto P_0c0a07a6;
case 0x0c0a07a8u: goto P_0c0a07a8;
case 0x0c0a07aau: goto P_0c0a07aa;
case 0x0c0a07acu: goto P_0c0a07ac;
case 0x0c0a07aeu: goto P_0c0a07ae;
case 0x0c0a07b0u: goto P_0c0a07b0;
case 0x0c0a07b2u: goto P_0c0a07b2;
case 0x0c0a07b4u: goto P_0c0a07b4;
case 0x0c0a07b6u: goto P_0c0a07b6;
case 0x0c0a07b8u: goto P_0c0a07b8;
case 0x0c0a07bau: goto P_0c0a07ba;
case 0x0c0a07bcu: goto P_0c0a07bc;
case 0x0c0a07beu: goto P_0c0a07be;
case 0x0c0a07c0u: goto P_0c0a07c0;
case 0x0c0a07c2u: goto P_0c0a07c2;
case 0x0c0a07c4u: goto P_0c0a07c4;
case 0x0c0a07c6u: goto P_0c0a07c6;
case 0x0c0a07c8u: goto P_0c0a07c8;
case 0x0c0a07cau: goto P_0c0a07ca;
case 0x0c0a07ccu: goto P_0c0a07cc;
case 0x0c0a07ceu: goto P_0c0a07ce;
case 0x0c0a07d0u: goto P_0c0a07d0;
case 0x0c0a07d2u: goto P_0c0a07d2;
case 0x0c0a07d4u: goto P_0c0a07d4;
case 0x0c0a07d6u: goto P_0c0a07d6;
case 0x0c0a07d8u: goto P_0c0a07d8;
case 0x0c0a07dau: goto P_0c0a07da;
case 0x0c0a07dcu: goto P_0c0a07dc;
case 0x0c0a07deu: goto P_0c0a07de;
case 0x0c0a07e0u: goto P_0c0a07e0;
case 0x0c0a07e2u: goto P_0c0a07e2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a058c: /* original 2fe6, guest PC 0x0c0a058c */
if(!s->budget--) { s->failed_pc=0x0c0a058cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a058e;
P_0c0a058e: /* original 4f22, guest PC 0x0c0a058e */
if(!s->budget--) { s->failed_pc=0x0c0a058eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0590;
P_0c0a0590: /* original 7ff8, guest PC 0x0c0a0590 */
if(!s->budget--) { s->failed_pc=0x0c0a0590u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0592;
P_0c0a0592: /* original 2f42, guest PC 0x0c0a0592 */
if(!s->budget--) { s->failed_pc=0x0c0a0592u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a0594;
P_0c0a0594: /* original 1f61, guest PC 0x0c0a0594 */
if(!s->budget--) { s->failed_pc=0x0c0a0594u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a0596;
P_0c0a0596: /* original d312, guest PC 0x0c0a0596 */
if(!s->budget--) { s->failed_pc=0x0c0a0596u; return 0; }
r[3]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0598;
P_0c0a0598: /* original 430b, guest PC 0x0c0a0598 */
if(!s->budget--) { s->failed_pc=0x0c0a0598u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a059cu;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a059cu) { target=s->pc; goto dispatch; }
goto P_0c0a059c;
P_0c0a059a: /* original 6463, guest PC 0x0c0a059a */
if(!s->budget--) { s->failed_pc=0x0c0a059au; return 0; }
r[4]=r[6];
goto P_0c0a059c;
P_0c0a059c: /* original d215, guest PC 0x0c0a059c */
if(!s->budget--) { s->failed_pc=0x0c0a059cu; return 0; }
r[2]=read(ram,0x0c0a05f4u,4);
goto P_0c0a059e;
P_0c0a059e: /* original e40d, guest PC 0x0c0a059e */
if(!s->budget--) { s->failed_pc=0x0c0a059eu; return 0; }
r[4]=0x0000000du;
goto P_0c0a05a0;
P_0c0a05a0: /* original 610c, guest PC 0x0c0a05a0 */
if(!s->budget--) { s->failed_pc=0x0c0a05a0u; return 0; }
r[1]=r[0]&255u;
goto P_0c0a05a2;
P_0c0a05a2: /* original 420b, guest PC 0x0c0a05a2 */
if(!s->budget--) { s->failed_pc=0x0c0a05a2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a05a6u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a05a6u) { target=s->pc; goto dispatch; }
goto P_0c0a05a6;
P_0c0a05a4: /* original 6043, guest PC 0x0c0a05a4 */
if(!s->budget--) { s->failed_pc=0x0c0a05a4u; return 0; }
r[0]=r[4];
goto P_0c0a05a6;
P_0c0a05a6: /* original 64f2, guest PC 0x0c0a05a6 */
if(!s->budget--) { s->failed_pc=0x0c0a05a6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a05a8;
P_0c0a05a8: /* original e307, guest PC 0x0c0a05a8 */
if(!s->budget--) { s->failed_pc=0x0c0a05a8u; return 0; }
r[3]=0x00000007u;
goto P_0c0a05aa;
P_0c0a05aa: /* original 6503, guest PC 0x0c0a05aa */
if(!s->budget--) { s->failed_pc=0x0c0a05aau; return 0; }
r[5]=r[0];
goto P_0c0a05ac;
P_0c0a05ac: /* original 6053, guest PC 0x0c0a05ac */
if(!s->budget--) { s->failed_pc=0x0c0a05acu; return 0; }
r[0]=r[5];
goto P_0c0a05ae;
P_0c0a05ae: /* original 740c, guest PC 0x0c0a05ae */
if(!s->budget--) { s->failed_pc=0x0c0a05aeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a05b0;
P_0c0a05b0: /* original 8809, guest PC 0x0c0a05b0 */
if(!s->budget--) { s->failed_pc=0x0c0a05b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a05b2;
P_0c0a05b2: /* original e254, guest PC 0x0c0a05b2 */
if(!s->budget--) { s->failed_pc=0x0c0a05b2u; return 0; }
r[2]=0x00000054u;
goto P_0c0a05b4;
P_0c0a05b4: /* original 6e53, guest PC 0x0c0a05b4 */
if(!s->budget--) { s->failed_pc=0x0c0a05b4u; return 0; }
r[14]=r[5];
goto P_0c0a05b6;
P_0c0a05b6: /* original 443c, guest PC 0x0c0a05b6 */
if(!s->budget--) { s->failed_pc=0x0c0a05b6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a05b8;
P_0c0a05b8: /* original 242b, guest PC 0x0c0a05b8 */
if(!s->budget--) { s->failed_pc=0x0c0a05b8u; return 0; }
r[4]|=r[2];
goto P_0c0a05ba;
P_0c0a05ba: /* original 8f1f, guest PC 0x0c0a05ba */
if(!s->budget--) { s->failed_pc=0x0c0a05bau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0a05fc; }
goto P_0c0a05be;
P_0c0a05bc: /* original 4e08, guest PC 0x0c0a05bc */
if(!s->budget--) { s->failed_pc=0x0c0a05bcu; return 0; }
r[14]<<=2;
goto P_0c0a05be;
P_0c0a05be: /* original 7f08, guest PC 0x0c0a05be */
if(!s->budget--) { s->failed_pc=0x0c0a05beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a05c0;
P_0c0a05c0: /* original d00d, guest PC 0x0c0a05c0 */
if(!s->budget--) { s->failed_pc=0x0c0a05c0u; return 0; }
r[0]=read(ram,0x0c0a05f8u,4);
goto P_0c0a05c2;
P_0c0a05c2: /* original 4f26, guest PC 0x0c0a05c2 */
if(!s->budget--) { s->failed_pc=0x0c0a05c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a05c4;
P_0c0a05c4: /* original d307, guest PC 0x0c0a05c4 */
if(!s->budget--) { s->failed_pc=0x0c0a05c4u; return 0; }
r[3]=read(ram,0x0c0a05e4u,4);
goto P_0c0a05c6;
P_0c0a05c6: /* original e601, guest PC 0x0c0a05c6 */
if(!s->budget--) { s->failed_pc=0x0c0a05c6u; return 0; }
r[6]=0x00000001u;
goto P_0c0a05c8;
P_0c0a05c8: /* original 05ee, guest PC 0x0c0a05c8 */
if(!s->budget--) { s->failed_pc=0x0c0a05c8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a05ca;
P_0c0a05ca: /* original 432b, guest PC 0x0c0a05ca */
if(!s->budget--) { s->failed_pc=0x0c0a05cau; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
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
P_0c0a05cc: /* original 6ef6, guest PC 0x0c0a05cc */
if(!s->budget--) { s->failed_pc=0x0c0a05ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a05ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a05ceu; return 0; } return 1;
P_0c0a05fc: /* original d63f, guest PC 0x0c0a05fc */
if(!s->budget--) { s->failed_pc=0x0c0a05fcu; return 0; }
r[6]=read(ram,0x0c0a06fcu,4);
goto P_0c0a05fe;
P_0c0a05fe: /* original e100, guest PC 0x0c0a05fe */
if(!s->budget--) { s->failed_pc=0x0c0a05feu; return 0; }
r[1]=0x00000000u;
goto P_0c0a0600;
P_0c0a0600: /* original 2f16, guest PC 0x0c0a0600 */
if(!s->budget--) { s->failed_pc=0x0c0a0600u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0602;
P_0c0a0602: /* original 6713, guest PC 0x0c0a0602 */
if(!s->budget--) { s->failed_pc=0x0c0a0602u; return 0; }
r[7]=r[1];
goto P_0c0a0604;
P_0c0a0604: /* original d33f, guest PC 0x0c0a0604 */
if(!s->budget--) { s->failed_pc=0x0c0a0604u; return 0; }
r[3]=read(ram,0x0c0a0704u,4);
goto P_0c0a0606;
P_0c0a0606: /* original d03e, guest PC 0x0c0a0606 */
if(!s->budget--) { s->failed_pc=0x0c0a0606u; return 0; }
r[0]=read(ram,0x0c0a0700u,4);
goto P_0c0a0608;
P_0c0a0608: /* original 430b, guest PC 0x0c0a0608 */
if(!s->budget--) { s->failed_pc=0x0c0a0608u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a060cu;
r[5]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a060cu) { target=s->pc; goto dispatch; }
goto P_0c0a060c;
P_0c0a060a: /* original 05ee, guest PC 0x0c0a060a */
if(!s->budget--) { s->failed_pc=0x0c0a060au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a060c;
P_0c0a060c: /* original 7f0c, guest PC 0x0c0a060c */
if(!s->budget--) { s->failed_pc=0x0c0a060cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a060e;
P_0c0a060e: /* original 4f26, guest PC 0x0c0a060e */
if(!s->budget--) { s->failed_pc=0x0c0a060eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0610;
P_0c0a0610: /* original 000b, guest PC 0x0c0a0610 */
if(!s->budget--) { s->failed_pc=0x0c0a0610u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a0612: /* original 6ef6, guest PC 0x0c0a0612 */
if(!s->budget--) { s->failed_pc=0x0c0a0612u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a0614;
P_0c0a0614: /* original 2fe6, guest PC 0x0c0a0614 */
if(!s->budget--) { s->failed_pc=0x0c0a0614u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0616;
P_0c0a0616: /* original 2fd6, guest PC 0x0c0a0616 */
if(!s->budget--) { s->failed_pc=0x0c0a0616u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0618;
P_0c0a0618: /* original ed08, guest PC 0x0c0a0618 */
if(!s->budget--) { s->failed_pc=0x0c0a0618u; return 0; }
r[13]=0x00000008u;
goto P_0c0a061a;
P_0c0a061a: /* original 2fc6, guest PC 0x0c0a061a */
if(!s->budget--) { s->failed_pc=0x0c0a061au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a061c;
P_0c0a061c: /* original 2fb6, guest PC 0x0c0a061c */
if(!s->budget--) { s->failed_pc=0x0c0a061cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a061e;
P_0c0a061e: /* original eb00, guest PC 0x0c0a061e */
if(!s->budget--) { s->failed_pc=0x0c0a061eu; return 0; }
r[11]=0x00000000u;
goto P_0c0a0620;
P_0c0a0620: /* original 2fa6, guest PC 0x0c0a0620 */
if(!s->budget--) { s->failed_pc=0x0c0a0620u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0622;
P_0c0a0622: /* original ea18, guest PC 0x0c0a0622 */
if(!s->budget--) { s->failed_pc=0x0c0a0622u; return 0; }
r[10]=0x00000018u;
goto P_0c0a0624;
P_0c0a0624: /* original 2f96, guest PC 0x0c0a0624 */
if(!s->budget--) { s->failed_pc=0x0c0a0624u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0626;
P_0c0a0626: /* original 6eb3, guest PC 0x0c0a0626 */
if(!s->budget--) { s->failed_pc=0x0c0a0626u; return 0; }
r[14]=r[11];
goto P_0c0a0628;
P_0c0a0628: /* original 2f86, guest PC 0x0c0a0628 */
if(!s->budget--) { s->failed_pc=0x0c0a0628u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a062a;
P_0c0a062a: /* original e811, guest PC 0x0c0a062a */
if(!s->budget--) { s->failed_pc=0x0c0a062au; return 0; }
r[8]=0x00000011u;
goto P_0c0a062c;
P_0c0a062c: /* original 4f22, guest PC 0x0c0a062c */
if(!s->budget--) { s->failed_pc=0x0c0a062cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a062e;
P_0c0a062e: /* original d336, guest PC 0x0c0a062e */
if(!s->budget--) { s->failed_pc=0x0c0a062eu; return 0; }
r[3]=read(ram,0x0c0a0708u,4);
goto P_0c0a0630;
P_0c0a0630: /* original e904, guest PC 0x0c0a0630 */
if(!s->budget--) { s->failed_pc=0x0c0a0630u; return 0; }
r[9]=0x00000004u;
goto P_0c0a0632;
P_0c0a0632: /* original 7ff0, guest PC 0x0c0a0632 */
if(!s->budget--) { s->failed_pc=0x0c0a0632u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a0634;
P_0c0a0634: /* original 1f33, guest PC 0x0c0a0634 */
if(!s->budget--) { s->failed_pc=0x0c0a0634u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a0636;
P_0c0a0636: /* original d332, guest PC 0x0c0a0636 */
if(!s->budget--) { s->failed_pc=0x0c0a0636u; return 0; }
r[3]=read(ram,0x0c0a0700u,4);
goto P_0c0a0638;
P_0c0a0638: /* original dc30, guest PC 0x0c0a0638 */
if(!s->budget--) { s->failed_pc=0x0c0a0638u; return 0; }
r[12]=read(ram,0x0c0a06fcu,4);
goto P_0c0a063a;
P_0c0a063a: /* original 1f31, guest PC 0x0c0a063a */
if(!s->budget--) { s->failed_pc=0x0c0a063au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a063c;
P_0c0a063c: /* original e30d, guest PC 0x0c0a063c */
if(!s->budget--) { s->failed_pc=0x0c0a063cu; return 0; }
r[3]=0x0000000du;
goto P_0c0a063e;
P_0c0a063e: /* original 3e33, guest PC 0x0c0a063e */
if(!s->budget--) { s->failed_pc=0x0c0a063eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0a0640;
P_0c0a0640: /* original 894e, guest PC 0x0c0a0640 */
if(!s->budget--) { s->failed_pc=0x0c0a0640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a06e0; }
goto P_0c0a0642;
P_0c0a0642: /* original e206, guest PC 0x0c0a0642 */
if(!s->budget--) { s->failed_pc=0x0c0a0642u; return 0; }
r[2]=0x00000006u;
goto P_0c0a0644;
P_0c0a0644: /* original 3e23, guest PC 0x0c0a0644 */
if(!s->budget--) { s->failed_pc=0x0c0a0644u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0a0646;
P_0c0a0646: /* original 8b09, guest PC 0x0c0a0646 */
if(!s->budget--) { s->failed_pc=0x0c0a0646u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a065c; }
goto P_0c0a0648;
P_0c0a0648: /* original 60e3, guest PC 0x0c0a0648 */
if(!s->budget--) { s->failed_pc=0x0c0a0648u; return 0; }
r[0]=r[14];
goto P_0c0a064a;
P_0c0a064a: /* original 8806, guest PC 0x0c0a064a */
if(!s->budget--) { s->failed_pc=0x0c0a064au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a064c;
P_0c0a064c: /* original 8f04, guest PC 0x0c0a064c */
if(!s->budget--) { s->failed_pc=0x0c0a064cu; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0a0658; }
goto P_0c0a0650;
P_0c0a064e: /* original 60e3, guest PC 0x0c0a064e */
if(!s->budget--) { s->failed_pc=0x0c0a064eu; return 0; }
r[0]=r[14];
goto P_0c0a0650;
P_0c0a0650: /* original ea32, guest PC 0x0c0a0650 */
if(!s->budget--) { s->failed_pc=0x0c0a0650u; return 0; }
r[10]=0x00000032u;
goto P_0c0a0652;
P_0c0a0652: /* original ed08, guest PC 0x0c0a0652 */
if(!s->budget--) { s->failed_pc=0x0c0a0652u; return 0; }
r[13]=0x00000008u;
goto P_0c0a0654;
P_0c0a0654: /* original e922, guest PC 0x0c0a0654 */
if(!s->budget--) { s->failed_pc=0x0c0a0654u; return 0; }
r[9]=0x00000022u;
goto P_0c0a0656;
P_0c0a0656: /* original e82b, guest PC 0x0c0a0656 */
if(!s->budget--) { s->failed_pc=0x0c0a0656u; return 0; }
r[8]=0x0000002bu;
goto P_0c0a0658;
P_0c0a0658: /* original 8809, guest PC 0x0c0a0658 */
if(!s->budget--) { s->failed_pc=0x0c0a0658u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a065a;
P_0c0a065a: /* original 893c, guest PC 0x0c0a065a */
if(!s->budget--) { s->failed_pc=0x0c0a065au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a06d6; }
goto P_0c0a065c;
P_0c0a065c: /* original 7d04, guest PC 0x0c0a065c */
if(!s->budget--) { s->failed_pc=0x0c0a065cu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a065e;
P_0c0a065e: /* original 6493, guest PC 0x0c0a065e */
if(!s->budget--) { s->failed_pc=0x0c0a065eu; return 0; }
r[4]=r[9];
goto P_0c0a0660;
P_0c0a0660: /* original e307, guest PC 0x0c0a0660 */
if(!s->budget--) { s->failed_pc=0x0c0a0660u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0662;
P_0c0a0662: /* original 62d3, guest PC 0x0c0a0662 */
if(!s->budget--) { s->failed_pc=0x0c0a0662u; return 0; }
r[2]=r[13];
goto P_0c0a0664;
P_0c0a0664: /* original 423c, guest PC 0x0c0a0664 */
if(!s->budget--) { s->failed_pc=0x0c0a0664u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0666;
P_0c0a0666: /* original 66c3, guest PC 0x0c0a0666 */
if(!s->budget--) { s->failed_pc=0x0c0a0666u; return 0; }
r[6]=r[12];
goto P_0c0a0668;
P_0c0a0668: /* original 2f22, guest PC 0x0c0a0668 */
if(!s->budget--) { s->failed_pc=0x0c0a0668u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a066a;
P_0c0a066a: /* original 4400, guest PC 0x0c0a066a */
if(!s->budget--) { s->failed_pc=0x0c0a066au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a066c;
P_0c0a066c: /* original 2fb6, guest PC 0x0c0a066c */
if(!s->budget--) { s->failed_pc=0x0c0a066cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a066e;
P_0c0a066e: /* original 242b, guest PC 0x0c0a066e */
if(!s->budget--) { s->failed_pc=0x0c0a066eu; return 0; }
r[4]|=r[2];
goto P_0c0a0670;
P_0c0a0670: /* original 55f2, guest PC 0x0c0a0670 */
if(!s->budget--) { s->failed_pc=0x0c0a0670u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0a0672;
P_0c0a0672: /* original e700, guest PC 0x0c0a0672 */
if(!s->budget--) { s->failed_pc=0x0c0a0672u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0674;
P_0c0a0674: /* original d123, guest PC 0x0c0a0674 */
if(!s->budget--) { s->failed_pc=0x0c0a0674u; return 0; }
r[1]=read(ram,0x0c0a0704u,4);
goto P_0c0a0676;
P_0c0a0676: /* original 410b, guest PC 0x0c0a0676 */
if(!s->budget--) { s->failed_pc=0x0c0a0676u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a067au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a067au) { target=s->pc; goto dispatch; }
goto P_0c0a067a;
P_0c0a0678: /* original 6552, guest PC 0x0c0a0678 */
if(!s->budget--) { s->failed_pc=0x0c0a0678u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0a067a;
P_0c0a067a: /* original 923b, guest PC 0x0c0a067a */
if(!s->budget--) { s->failed_pc=0x0c0a067au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f4u,2);
goto P_0c0a067c;
P_0c0a067c: /* original 63e3, guest PC 0x0c0a067c */
if(!s->budget--) { s->failed_pc=0x0c0a067cu; return 0; }
r[3]=r[14];
goto P_0c0a067e;
P_0c0a067e: /* original 54f4, guest PC 0x0c0a067e */
if(!s->budget--) { s->failed_pc=0x0c0a067eu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0a0680;
P_0c0a0680: /* original 4308, guest PC 0x0c0a0680 */
if(!s->budget--) { s->failed_pc=0x0c0a0680u; return 0; }
r[3]<<=2;
goto P_0c0a0682;
P_0c0a0682: /* original 342c, guest PC 0x0c0a0682 */
if(!s->budget--) { s->failed_pc=0x0c0a0682u; return 0; }
r[4]+=r[2];
goto P_0c0a0684;
P_0c0a0684: /* original 343c, guest PC 0x0c0a0684 */
if(!s->budget--) { s->failed_pc=0x0c0a0684u; return 0; }
r[4]+=r[3];
goto P_0c0a0686;
P_0c0a0686: /* original d321, guest PC 0x0c0a0686 */
if(!s->budget--) { s->failed_pc=0x0c0a0686u; return 0; }
r[3]=read(ram,0x0c0a070cu,4);
goto P_0c0a0688;
P_0c0a0688: /* original 430b, guest PC 0x0c0a0688 */
if(!s->budget--) { s->failed_pc=0x0c0a0688u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a068cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a068cu) { target=s->pc; goto dispatch; }
goto P_0c0a068c;
P_0c0a068a: /* original 0009, guest PC 0x0c0a068a */
if(!s->budget--) { s->failed_pc=0x0c0a068au; return 0; }
goto P_0c0a068c;
P_0c0a068c: /* original 1f03, guest PC 0x0c0a068c */
if(!s->budget--) { s->failed_pc=0x0c0a068cu; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c0a068e;
P_0c0a068e: /* original 6483, guest PC 0x0c0a068e */
if(!s->budget--) { s->failed_pc=0x0c0a068eu; return 0; }
r[4]=r[8];
goto P_0c0a0690;
P_0c0a0690: /* original 52f3, guest PC 0x0c0a0690 */
if(!s->budget--) { s->failed_pc=0x0c0a0690u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a0692;
P_0c0a0692: /* original 4400, guest PC 0x0c0a0692 */
if(!s->budget--) { s->failed_pc=0x0c0a0692u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0694;
P_0c0a0694: /* original 53f1, guest PC 0x0c0a0694 */
if(!s->budget--) { s->failed_pc=0x0c0a0694u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a0696;
P_0c0a0696: /* original 2f26, guest PC 0x0c0a0696 */
if(!s->budget--) { s->failed_pc=0x0c0a0696u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0698;
P_0c0a0698: /* original d11d, guest PC 0x0c0a0698 */
if(!s->budget--) { s->failed_pc=0x0c0a0698u; return 0; }
r[1]=read(ram,0x0c0a0710u,4);
goto P_0c0a069a;
P_0c0a069a: /* original 243b, guest PC 0x0c0a069a */
if(!s->budget--) { s->failed_pc=0x0c0a069au; return 0; }
r[4]|=r[3];
goto P_0c0a069c;
P_0c0a069c: /* original d21d, guest PC 0x0c0a069c */
if(!s->budget--) { s->failed_pc=0x0c0a069cu; return 0; }
r[2]=read(ram,0x0c0a0714u,4);
goto P_0c0a069e;
P_0c0a069e: /* original 420b, guest PC 0x0c0a069e */
if(!s->budget--) { s->failed_pc=0x0c0a069eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a06a2u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a06a2u) { target=s->pc; goto dispatch; }
goto P_0c0a06a2;
P_0c0a06a0: /* original 2f16, guest PC 0x0c0a06a0 */
if(!s->budget--) { s->failed_pc=0x0c0a06a0u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a06a2;
P_0c0a06a2: /* original 7f0c, guest PC 0x0c0a06a2 */
if(!s->budget--) { s->failed_pc=0x0c0a06a2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a06a4;
P_0c0a06a4: /* original 52f2, guest PC 0x0c0a06a4 */
if(!s->budget--) { s->failed_pc=0x0c0a06a4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a06a6;
P_0c0a06a6: /* original e301, guest PC 0x0c0a06a6 */
if(!s->budget--) { s->failed_pc=0x0c0a06a6u; return 0; }
r[3]=0x00000001u;
goto P_0c0a06a8;
P_0c0a06a8: /* original 3237, guest PC 0x0c0a06a8 */
if(!s->budget--) { s->failed_pc=0x0c0a06a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0a06aa;
P_0c0a06aa: /* original 8b08, guest PC 0x0c0a06aa */
if(!s->budget--) { s->failed_pc=0x0c0a06aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a06be; }
goto P_0c0a06ac;
P_0c0a06ac: /* original 63f2, guest PC 0x0c0a06ac */
if(!s->budget--) { s->failed_pc=0x0c0a06acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a06ae;
P_0c0a06ae: /* original 64a3, guest PC 0x0c0a06ae */
if(!s->budget--) { s->failed_pc=0x0c0a06aeu; return 0; }
r[4]=r[10];
goto P_0c0a06b0;
P_0c0a06b0: /* original 4400, guest PC 0x0c0a06b0 */
if(!s->budget--) { s->failed_pc=0x0c0a06b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a06b2;
P_0c0a06b2: /* original 2fb6, guest PC 0x0c0a06b2 */
if(!s->budget--) { s->failed_pc=0x0c0a06b2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a06b4;
P_0c0a06b4: /* original 951f, guest PC 0x0c0a06b4 */
if(!s->budget--) { s->failed_pc=0x0c0a06b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f6u,2);
goto P_0c0a06b6;
P_0c0a06b6: /* original e700, guest PC 0x0c0a06b6 */
if(!s->budget--) { s->failed_pc=0x0c0a06b6u; return 0; }
r[7]=0x00000000u;
goto P_0c0a06b8;
P_0c0a06b8: /* original 243b, guest PC 0x0c0a06b8 */
if(!s->budget--) { s->failed_pc=0x0c0a06b8u; return 0; }
r[4]|=r[3];
goto P_0c0a06ba;
P_0c0a06ba: /* original a008, guest PC 0x0c0a06ba */
if(!s->budget--) { s->failed_pc=0x0c0a06bau; return 0; }
r[6]=r[12];
goto P_0c0a06ce;
P_0c0a06bc: /* original 66c3, guest PC 0x0c0a06bc */
if(!s->budget--) { s->failed_pc=0x0c0a06bcu; return 0; }
r[6]=r[12];
goto P_0c0a06be;
P_0c0a06be: /* original 63f2, guest PC 0x0c0a06be */
if(!s->budget--) { s->failed_pc=0x0c0a06beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a06c0;
P_0c0a06c0: /* original 64a3, guest PC 0x0c0a06c0 */
if(!s->budget--) { s->failed_pc=0x0c0a06c0u; return 0; }
r[4]=r[10];
goto P_0c0a06c2;
P_0c0a06c2: /* original 4400, guest PC 0x0c0a06c2 */
if(!s->budget--) { s->failed_pc=0x0c0a06c2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a06c4;
P_0c0a06c4: /* original 66c3, guest PC 0x0c0a06c4 */
if(!s->budget--) { s->failed_pc=0x0c0a06c4u; return 0; }
r[6]=r[12];
goto P_0c0a06c6;
P_0c0a06c6: /* original e700, guest PC 0x0c0a06c6 */
if(!s->budget--) { s->failed_pc=0x0c0a06c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0a06c8;
P_0c0a06c8: /* original 2fb6, guest PC 0x0c0a06c8 */
if(!s->budget--) { s->failed_pc=0x0c0a06c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a06ca;
P_0c0a06ca: /* original 9515, guest PC 0x0c0a06ca */
if(!s->budget--) { s->failed_pc=0x0c0a06cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f8u,2);
goto P_0c0a06cc;
P_0c0a06cc: /* original 243b, guest PC 0x0c0a06cc */
if(!s->budget--) { s->failed_pc=0x0c0a06ccu; return 0; }
r[4]|=r[3];
goto P_0c0a06ce;
P_0c0a06ce: /* original d20d, guest PC 0x0c0a06ce */
if(!s->budget--) { s->failed_pc=0x0c0a06ceu; return 0; }
r[2]=read(ram,0x0c0a0704u,4);
goto P_0c0a06d0;
P_0c0a06d0: /* original 420b, guest PC 0x0c0a06d0 */
if(!s->budget--) { s->failed_pc=0x0c0a06d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a06d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a06d4u) { target=s->pc; goto dispatch; }
goto P_0c0a06d4;
P_0c0a06d2: /* original 0009, guest PC 0x0c0a06d2 */
if(!s->budget--) { s->failed_pc=0x0c0a06d2u; return 0; }
goto P_0c0a06d4;
P_0c0a06d4: /* original 7f04, guest PC 0x0c0a06d4 */
if(!s->budget--) { s->failed_pc=0x0c0a06d4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a06d6;
P_0c0a06d6: /* original 53f1, guest PC 0x0c0a06d6 */
if(!s->budget--) { s->failed_pc=0x0c0a06d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a06d8;
P_0c0a06d8: /* original 7304, guest PC 0x0c0a06d8 */
if(!s->budget--) { s->failed_pc=0x0c0a06d8u; return 0; }
r[3]+=0x00000004u;
goto P_0c0a06da;
P_0c0a06da: /* original 1f31, guest PC 0x0c0a06da */
if(!s->budget--) { s->failed_pc=0x0c0a06dau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a06dc;
P_0c0a06dc: /* original afae, guest PC 0x0c0a06dc */
if(!s->budget--) { s->failed_pc=0x0c0a06dcu; return 0; }
r[14]+=0x00000001u;
goto P_0c0a063c;
P_0c0a06de: /* original 7e01, guest PC 0x0c0a06de */
if(!s->budget--) { s->failed_pc=0x0c0a06deu; return 0; }
r[14]+=0x00000001u;
goto P_0c0a06e0;
P_0c0a06e0: /* original 7f10, guest PC 0x0c0a06e0 */
if(!s->budget--) { s->failed_pc=0x0c0a06e0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a06e2;
P_0c0a06e2: /* original 4f26, guest PC 0x0c0a06e2 */
if(!s->budget--) { s->failed_pc=0x0c0a06e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a06e4;
P_0c0a06e4: /* original 68f6, guest PC 0x0c0a06e4 */
if(!s->budget--) { s->failed_pc=0x0c0a06e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a06e6;
P_0c0a06e6: /* original 69f6, guest PC 0x0c0a06e6 */
if(!s->budget--) { s->failed_pc=0x0c0a06e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a06e8;
P_0c0a06e8: /* original 6af6, guest PC 0x0c0a06e8 */
if(!s->budget--) { s->failed_pc=0x0c0a06e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a06ea;
P_0c0a06ea: /* original 6bf6, guest PC 0x0c0a06ea */
if(!s->budget--) { s->failed_pc=0x0c0a06eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a06ec;
P_0c0a06ec: /* original 6cf6, guest PC 0x0c0a06ec */
if(!s->budget--) { s->failed_pc=0x0c0a06ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a06ee;
P_0c0a06ee: /* original 6df6, guest PC 0x0c0a06ee */
if(!s->budget--) { s->failed_pc=0x0c0a06eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a06f0;
P_0c0a06f0: /* original 000b, guest PC 0x0c0a06f0 */
if(!s->budget--) { s->failed_pc=0x0c0a06f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a06f2: /* original 6ef6, guest PC 0x0c0a06f2 */
if(!s->budget--) { s->failed_pc=0x0c0a06f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a06f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a06f4u; return 0; } return 1;
P_0c0a0718: /* original 2fe6, guest PC 0x0c0a0718 */
if(!s->budget--) { s->failed_pc=0x0c0a0718u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a071a;
P_0c0a071a: /* original ee00, guest PC 0x0c0a071a */
if(!s->budget--) { s->failed_pc=0x0c0a071au; return 0; }
r[14]=0x00000000u;
goto P_0c0a071c;
P_0c0a071c: /* original d54a, guest PC 0x0c0a071c */
if(!s->budget--) { s->failed_pc=0x0c0a071cu; return 0; }
r[5]=read(ram,0x0c0a0848u,4);
goto P_0c0a071e;
P_0c0a071e: /* original 7fd4, guest PC 0x0c0a071e */
if(!s->budget--) { s->failed_pc=0x0c0a071eu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c0a0720;
P_0c0a0720: /* original 64f3, guest PC 0x0c0a0720 */
if(!s->budget--) { s->failed_pc=0x0c0a0720u; return 0; }
r[4]=r[15];
goto P_0c0a0722;
P_0c0a0722: /* original 7420, guest PC 0x0c0a0722 */
if(!s->budget--) { s->failed_pc=0x0c0a0722u; return 0; }
r[4]+=0x00000020u;
goto P_0c0a0724;
P_0c0a0724: /* original 6343, guest PC 0x0c0a0724 */
if(!s->budget--) { s->failed_pc=0x0c0a0724u; return 0; }
r[3]=r[4];
goto P_0c0a0726;
P_0c0a0726: /* original 1f31, guest PC 0x0c0a0726 */
if(!s->budget--) { s->failed_pc=0x0c0a0726u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0728;
P_0c0a0728: /* original 9086, guest PC 0x0c0a0728 */
if(!s->budget--) { s->failed_pc=0x0c0a0728u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a072a;
P_0c0a072a: /* original 7402, guest PC 0x0c0a072a */
if(!s->budget--) { s->failed_pc=0x0c0a072au; return 0; }
r[4]+=0x00000002u;
goto P_0c0a072c;
P_0c0a072c: /* original 025c, guest PC 0x0c0a072c */
if(!s->budget--) { s->failed_pc=0x0c0a072cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a072e;
P_0c0a072e: /* original 2320, guest PC 0x0c0a072e */
if(!s->budget--) { s->failed_pc=0x0c0a072eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0730;
P_0c0a0730: /* original 7301, guest PC 0x0c0a0730 */
if(!s->budget--) { s->failed_pc=0x0c0a0730u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0732;
P_0c0a0732: /* original 1f36, guest PC 0x0c0a0732 */
if(!s->budget--) { s->failed_pc=0x0c0a0732u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0a0734;
P_0c0a0734: /* original 9081, guest PC 0x0c0a0734 */
if(!s->budget--) { s->failed_pc=0x0c0a0734u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a0736;
P_0c0a0736: /* original 025c, guest PC 0x0c0a0736 */
if(!s->budget--) { s->failed_pc=0x0c0a0736u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0738;
P_0c0a0738: /* original 2320, guest PC 0x0c0a0738 */
if(!s->budget--) { s->failed_pc=0x0c0a0738u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a073a;
P_0c0a073a: /* original 1f44, guest PC 0x0c0a073a */
if(!s->budget--) { s->failed_pc=0x0c0a073au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0a073c;
P_0c0a073c: /* original 907e, guest PC 0x0c0a073c */
if(!s->budget--) { s->failed_pc=0x0c0a073cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a073e;
P_0c0a073e: /* original 035c, guest PC 0x0c0a073e */
if(!s->budget--) { s->failed_pc=0x0c0a073eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0740;
P_0c0a0740: /* original 2430, guest PC 0x0c0a0740 */
if(!s->budget--) { s->failed_pc=0x0c0a0740u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a0742;
P_0c0a0742: /* original d242, guest PC 0x0c0a0742 */
if(!s->budget--) { s->failed_pc=0x0c0a0742u; return 0; }
r[2]=read(ram,0x0c0a084cu,4);
goto P_0c0a0744;
P_0c0a0744: /* original 1f27, guest PC 0x0c0a0744 */
if(!s->budget--) { s->failed_pc=0x0c0a0744u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0a0746;
P_0c0a0746: /* original d342, guest PC 0x0c0a0746 */
if(!s->budget--) { s->failed_pc=0x0c0a0746u; return 0; }
r[3]=read(ram,0x0c0a0850u,4);
goto P_0c0a0748;
P_0c0a0748: /* original 2f32, guest PC 0x0c0a0748 */
if(!s->budget--) { s->failed_pc=0x0c0a0748u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a074a;
P_0c0a074a: /* original e30b, guest PC 0x0c0a074a */
if(!s->budget--) { s->failed_pc=0x0c0a074au; return 0; }
r[3]=0x0000000bu;
goto P_0c0a074c;
P_0c0a074c: /* original 3e33, guest PC 0x0c0a074c */
if(!s->budget--) { s->failed_pc=0x0c0a074cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0a074e;
P_0c0a074e: /* original 8946, guest PC 0x0c0a074e */
if(!s->budget--) { s->failed_pc=0x0c0a074eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a07de; }
goto P_0c0a0750;
P_0c0a0750: /* original 54f7, guest PC 0x0c0a0750 */
if(!s->budget--) { s->failed_pc=0x0c0a0750u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0a0752;
P_0c0a0752: /* original 67f3, guest PC 0x0c0a0752 */
if(!s->budget--) { s->failed_pc=0x0c0a0752u; return 0; }
r[7]=r[15];
goto P_0c0a0754;
P_0c0a0754: /* original 7728, guest PC 0x0c0a0754 */
if(!s->budget--) { s->failed_pc=0x0c0a0754u; return 0; }
r[7]+=0x00000028u;
goto P_0c0a0756;
P_0c0a0756: /* original 7404, guest PC 0x0c0a0756 */
if(!s->budget--) { s->failed_pc=0x0c0a0756u; return 0; }
r[4]+=0x00000004u;
goto P_0c0a0758;
P_0c0a0758: /* original 6373, guest PC 0x0c0a0758 */
if(!s->budget--) { s->failed_pc=0x0c0a0758u; return 0; }
r[3]=r[7];
goto P_0c0a075a;
P_0c0a075a: /* original 1f47, guest PC 0x0c0a075a */
if(!s->budget--) { s->failed_pc=0x0c0a075au; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0a075c;
P_0c0a075c: /* original 74fc, guest PC 0x0c0a075c */
if(!s->budget--) { s->failed_pc=0x0c0a075cu; return 0; }
r[4]+=0xfffffffcu;
goto P_0c0a075e;
P_0c0a075e: /* original 6442, guest PC 0x0c0a075e */
if(!s->budget--) { s->failed_pc=0x0c0a075eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0a0760;
P_0c0a0760: /* original 66f2, guest PC 0x0c0a0760 */
if(!s->budget--) { s->failed_pc=0x0c0a0760u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0a0762;
P_0c0a0762: /* original 7604, guest PC 0x0c0a0762 */
if(!s->budget--) { s->failed_pc=0x0c0a0762u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a0764;
P_0c0a0764: /* original 2f62, guest PC 0x0c0a0764 */
if(!s->budget--) { s->failed_pc=0x0c0a0764u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a0766;
P_0c0a0766: /* original 76fc, guest PC 0x0c0a0766 */
if(!s->budget--) { s->failed_pc=0x0c0a0766u; return 0; }
r[6]+=0xfffffffcu;
goto P_0c0a0768;
P_0c0a0768: /* original 6662, guest PC 0x0c0a0768 */
if(!s->budget--) { s->failed_pc=0x0c0a0768u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0a076a;
P_0c0a076a: /* original 1f32, guest PC 0x0c0a076a */
if(!s->budget--) { s->failed_pc=0x0c0a076au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a076c;
P_0c0a076c: /* original 6244, guest PC 0x0c0a076c */
if(!s->budget--) { s->failed_pc=0x0c0a076cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a076e;
P_0c0a076e: /* original 2320, guest PC 0x0c0a076e */
if(!s->budget--) { s->failed_pc=0x0c0a076eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0770;
P_0c0a0770: /* original 7301, guest PC 0x0c0a0770 */
if(!s->budget--) { s->failed_pc=0x0c0a0770u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0772;
P_0c0a0772: /* original 1f35, guest PC 0x0c0a0772 */
if(!s->budget--) { s->failed_pc=0x0c0a0772u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0a0774;
P_0c0a0774: /* original 6244, guest PC 0x0c0a0774 */
if(!s->budget--) { s->failed_pc=0x0c0a0774u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0776;
P_0c0a0776: /* original 2320, guest PC 0x0c0a0776 */
if(!s->budget--) { s->failed_pc=0x0c0a0776u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0778;
P_0c0a0778: /* original 6373, guest PC 0x0c0a0778 */
if(!s->budget--) { s->failed_pc=0x0c0a0778u; return 0; }
r[3]=r[7];
goto P_0c0a077a;
P_0c0a077a: /* original 7302, guest PC 0x0c0a077a */
if(!s->budget--) { s->failed_pc=0x0c0a077au; return 0; }
r[3]+=0x00000002u;
goto P_0c0a077c;
P_0c0a077c: /* original 1f33, guest PC 0x0c0a077c */
if(!s->budget--) { s->failed_pc=0x0c0a077cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a077e;
P_0c0a077e: /* original 6244, guest PC 0x0c0a077e */
if(!s->budget--) { s->failed_pc=0x0c0a077eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0780;
P_0c0a0780: /* original 2320, guest PC 0x0c0a0780 */
if(!s->budget--) { s->failed_pc=0x0c0a0780u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0782;
P_0c0a0782: /* original 6040, guest PC 0x0c0a0782 */
if(!s->budget--) { s->failed_pc=0x0c0a0782u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0a0784;
P_0c0a0784: /* original 64f3, guest PC 0x0c0a0784 */
if(!s->budget--) { s->failed_pc=0x0c0a0784u; return 0; }
r[4]=r[15];
goto P_0c0a0786;
P_0c0a0786: /* original 7424, guest PC 0x0c0a0786 */
if(!s->budget--) { s->failed_pc=0x0c0a0786u; return 0; }
r[4]+=0x00000024u;
goto P_0c0a0788;
P_0c0a0788: /* original 8073, guest PC 0x0c0a0788 */
if(!s->budget--) { s->failed_pc=0x0c0a0788u; return 0; }
write(ram,r[7]+3,r[0],1);
goto P_0c0a078a;
P_0c0a078a: /* original 6364, guest PC 0x0c0a078a */
if(!s->budget--) { s->failed_pc=0x0c0a078au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c0a078c;
P_0c0a078c: /* original 2430, guest PC 0x0c0a078c */
if(!s->budget--) { s->failed_pc=0x0c0a078cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a078e;
P_0c0a078e: /* original 6064, guest PC 0x0c0a078e */
if(!s->budget--) { s->failed_pc=0x0c0a078eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0790;
P_0c0a0790: /* original 8041, guest PC 0x0c0a0790 */
if(!s->budget--) { s->failed_pc=0x0c0a0790u; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c0a0792;
P_0c0a0792: /* original 6064, guest PC 0x0c0a0792 */
if(!s->budget--) { s->failed_pc=0x0c0a0792u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0794;
P_0c0a0794: /* original 8042, guest PC 0x0c0a0794 */
if(!s->budget--) { s->failed_pc=0x0c0a0794u; return 0; }
write(ram,r[4]+2,r[0],1);
goto P_0c0a0796;
P_0c0a0796: /* original 6060, guest PC 0x0c0a0796 */
if(!s->budget--) { s->failed_pc=0x0c0a0796u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0a0798;
P_0c0a0798: /* original 8043, guest PC 0x0c0a0798 */
if(!s->budget--) { s->failed_pc=0x0c0a0798u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c0a079a;
P_0c0a079a: /* original 53f1, guest PC 0x0c0a079a */
if(!s->budget--) { s->failed_pc=0x0c0a079au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a079c;
P_0c0a079c: /* original 6230, guest PC 0x0c0a079c */
if(!s->budget--) { s->failed_pc=0x0c0a079cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a079e;
P_0c0a079e: /* original 53f2, guest PC 0x0c0a079e */
if(!s->budget--) { s->failed_pc=0x0c0a079eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a07a0;
P_0c0a07a0: /* original 6130, guest PC 0x0c0a07a0 */
if(!s->budget--) { s->failed_pc=0x0c0a07a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c0a07a2;
P_0c0a07a2: /* original 3210, guest PC 0x0c0a07a2 */
if(!s->budget--) { s->failed_pc=0x0c0a07a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a07a4;
P_0c0a07a4: /* original 8fd1, guest PC 0x0c0a07a4 */
if(!s->budget--) { s->failed_pc=0x0c0a07a4u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07a8;
P_0c0a07a6: /* original 7e01, guest PC 0x0c0a07a6 */
if(!s->budget--) { s->failed_pc=0x0c0a07a6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0a07a8;
P_0c0a07a8: /* original 52f6, guest PC 0x0c0a07a8 */
if(!s->budget--) { s->failed_pc=0x0c0a07a8u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0a07aa;
P_0c0a07aa: /* original 6320, guest PC 0x0c0a07aa */
if(!s->budget--) { s->failed_pc=0x0c0a07aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07ac;
P_0c0a07ac: /* original 52f5, guest PC 0x0c0a07ac */
if(!s->budget--) { s->failed_pc=0x0c0a07acu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0a07ae;
P_0c0a07ae: /* original 6120, guest PC 0x0c0a07ae */
if(!s->budget--) { s->failed_pc=0x0c0a07aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07b0;
P_0c0a07b0: /* original 3310, guest PC 0x0c0a07b0 */
if(!s->budget--) { s->failed_pc=0x0c0a07b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07b2;
P_0c0a07b2: /* original 8bca, guest PC 0x0c0a07b2 */
if(!s->budget--) { s->failed_pc=0x0c0a07b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07b4;
P_0c0a07b4: /* original 52f4, guest PC 0x0c0a07b4 */
if(!s->budget--) { s->failed_pc=0x0c0a07b4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0a07b6;
P_0c0a07b6: /* original 6320, guest PC 0x0c0a07b6 */
if(!s->budget--) { s->failed_pc=0x0c0a07b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07b8;
P_0c0a07b8: /* original 52f3, guest PC 0x0c0a07b8 */
if(!s->budget--) { s->failed_pc=0x0c0a07b8u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a07ba;
P_0c0a07ba: /* original 6120, guest PC 0x0c0a07ba */
if(!s->budget--) { s->failed_pc=0x0c0a07bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07bc;
P_0c0a07bc: /* original 3310, guest PC 0x0c0a07bc */
if(!s->budget--) { s->failed_pc=0x0c0a07bcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07be;
P_0c0a07be: /* original 8bc4, guest PC 0x0c0a07be */
if(!s->budget--) { s->failed_pc=0x0c0a07beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07c0;
P_0c0a07c0: /* original 903a, guest PC 0x0c0a07c0 */
if(!s->budget--) { s->failed_pc=0x0c0a07c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a07c2;
P_0c0a07c2: /* original 6340, guest PC 0x0c0a07c2 */
if(!s->budget--) { s->failed_pc=0x0c0a07c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0a07c4;
P_0c0a07c4: /* original 0534, guest PC 0x0c0a07c4 */
if(!s->budget--) { s->failed_pc=0x0c0a07c4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0a07c6;
P_0c0a07c6: /* original 9138, guest PC 0x0c0a07c6 */
if(!s->budget--) { s->failed_pc=0x0c0a07c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a07c8;
P_0c0a07c8: /* original 8441, guest PC 0x0c0a07c8 */
if(!s->budget--) { s->failed_pc=0x0c0a07c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a07ca;
P_0c0a07ca: /* original 315c, guest PC 0x0c0a07ca */
if(!s->budget--) { s->failed_pc=0x0c0a07cau; return 0; }
r[1]+=r[5];
goto P_0c0a07cc;
P_0c0a07cc: /* original 2100, guest PC 0x0c0a07cc */
if(!s->budget--) { s->failed_pc=0x0c0a07ccu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07ce;
P_0c0a07ce: /* original 9235, guest PC 0x0c0a07ce */
if(!s->budget--) { s->failed_pc=0x0c0a07ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a07d0;
P_0c0a07d0: /* original 8442, guest PC 0x0c0a07d0 */
if(!s->budget--) { s->failed_pc=0x0c0a07d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a07d2;
P_0c0a07d2: /* original 325c, guest PC 0x0c0a07d2 */
if(!s->budget--) { s->failed_pc=0x0c0a07d2u; return 0; }
r[2]+=r[5];
goto P_0c0a07d4;
P_0c0a07d4: /* original 2200, guest PC 0x0c0a07d4 */
if(!s->budget--) { s->failed_pc=0x0c0a07d4u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0a07d6;
P_0c0a07d6: /* original 9132, guest PC 0x0c0a07d6 */
if(!s->budget--) { s->failed_pc=0x0c0a07d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083eu,2);
goto P_0c0a07d8;
P_0c0a07d8: /* original 8443, guest PC 0x0c0a07d8 */
if(!s->budget--) { s->failed_pc=0x0c0a07d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a07da;
P_0c0a07da: /* original 315c, guest PC 0x0c0a07da */
if(!s->budget--) { s->failed_pc=0x0c0a07dau; return 0; }
r[1]+=r[5];
goto P_0c0a07dc;
P_0c0a07dc: /* original 2100, guest PC 0x0c0a07dc */
if(!s->budget--) { s->failed_pc=0x0c0a07dcu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07de;
P_0c0a07de: /* original 7f2c, guest PC 0x0c0a07de */
if(!s->budget--) { s->failed_pc=0x0c0a07deu; return 0; }
r[15]+=0x0000002cu;
goto P_0c0a07e0;
P_0c0a07e0: /* original 000b, guest PC 0x0c0a07e0 */
if(!s->budget--) { s->failed_pc=0x0c0a07e0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a07e2: /* original 6ef6, guest PC 0x0c0a07e2 */
if(!s->budget--) { s->failed_pc=0x0c0a07e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a07e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a07e4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
