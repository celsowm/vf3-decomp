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
int vf3_away_batch199_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f5f8u: goto P_0c09f5f8;
case 0x0c09f5fau: goto P_0c09f5fa;
case 0x0c09f5fcu: goto P_0c09f5fc;
case 0x0c09f5feu: goto P_0c09f5fe;
case 0x0c09f600u: goto P_0c09f600;
case 0x0c09f602u: goto P_0c09f602;
case 0x0c09f604u: goto P_0c09f604;
case 0x0c09f606u: goto P_0c09f606;
case 0x0c09f608u: goto P_0c09f608;
case 0x0c09f60au: goto P_0c09f60a;
case 0x0c09f60cu: goto P_0c09f60c;
case 0x0c09f60eu: goto P_0c09f60e;
case 0x0c09f610u: goto P_0c09f610;
case 0x0c09f612u: goto P_0c09f612;
case 0x0c09f614u: goto P_0c09f614;
case 0x0c09f616u: goto P_0c09f616;
case 0x0c09f618u: goto P_0c09f618;
case 0x0c09f61au: goto P_0c09f61a;
case 0x0c09f61cu: goto P_0c09f61c;
case 0x0c09f61eu: goto P_0c09f61e;
case 0x0c09f620u: goto P_0c09f620;
case 0x0c09f622u: goto P_0c09f622;
case 0x0c09f624u: goto P_0c09f624;
case 0x0c09f626u: goto P_0c09f626;
case 0x0c09f628u: goto P_0c09f628;
case 0x0c09f62au: goto P_0c09f62a;
case 0x0c09f62cu: goto P_0c09f62c;
case 0x0c09f62eu: goto P_0c09f62e;
case 0x0c09f630u: goto P_0c09f630;
case 0x0c09f632u: goto P_0c09f632;
case 0x0c09f634u: goto P_0c09f634;
case 0x0c09f636u: goto P_0c09f636;
case 0x0c09f638u: goto P_0c09f638;
case 0x0c09f63au: goto P_0c09f63a;
case 0x0c09f63cu: goto P_0c09f63c;
case 0x0c09f63eu: goto P_0c09f63e;
case 0x0c09f640u: goto P_0c09f640;
case 0x0c09f642u: goto P_0c09f642;
case 0x0c09f644u: goto P_0c09f644;
case 0x0c09f646u: goto P_0c09f646;
case 0x0c09f648u: goto P_0c09f648;
case 0x0c09f64au: goto P_0c09f64a;
case 0x0c09f64cu: goto P_0c09f64c;
case 0x0c09f64eu: goto P_0c09f64e;
case 0x0c09f650u: goto P_0c09f650;
case 0x0c09f652u: goto P_0c09f652;
case 0x0c09f654u: goto P_0c09f654;
case 0x0c09f656u: goto P_0c09f656;
case 0x0c09f658u: goto P_0c09f658;
case 0x0c09f65au: goto P_0c09f65a;
case 0x0c09f65cu: goto P_0c09f65c;
case 0x0c09f65eu: goto P_0c09f65e;
case 0x0c09f660u: goto P_0c09f660;
case 0x0c09f662u: goto P_0c09f662;
case 0x0c09f664u: goto P_0c09f664;
case 0x0c09f666u: goto P_0c09f666;
case 0x0c09f668u: goto P_0c09f668;
case 0x0c09f66au: goto P_0c09f66a;
case 0x0c09f66cu: goto P_0c09f66c;
case 0x0c09f66eu: goto P_0c09f66e;
case 0x0c09f670u: goto P_0c09f670;
case 0x0c09f672u: goto P_0c09f672;
case 0x0c09f674u: goto P_0c09f674;
case 0x0c09f676u: goto P_0c09f676;
case 0x0c09f678u: goto P_0c09f678;
case 0x0c09f67au: goto P_0c09f67a;
case 0x0c09f67cu: goto P_0c09f67c;
case 0x0c09f67eu: goto P_0c09f67e;
case 0x0c09f680u: goto P_0c09f680;
case 0x0c09f682u: goto P_0c09f682;
case 0x0c09f684u: goto P_0c09f684;
case 0x0c09f686u: goto P_0c09f686;
case 0x0c09f688u: goto P_0c09f688;
case 0x0c09f68au: goto P_0c09f68a;
case 0x0c09f68cu: goto P_0c09f68c;
case 0x0c09f68eu: goto P_0c09f68e;
case 0x0c09f690u: goto P_0c09f690;
case 0x0c09f692u: goto P_0c09f692;
case 0x0c09f694u: goto P_0c09f694;
case 0x0c09f696u: goto P_0c09f696;
case 0x0c09f698u: goto P_0c09f698;
case 0x0c09f69au: goto P_0c09f69a;
case 0x0c09f69cu: goto P_0c09f69c;
case 0x0c09f69eu: goto P_0c09f69e;
case 0x0c09f6a0u: goto P_0c09f6a0;
case 0x0c09f6a2u: goto P_0c09f6a2;
case 0x0c09f6a4u: goto P_0c09f6a4;
case 0x0c09f6a6u: goto P_0c09f6a6;
case 0x0c09f6a8u: goto P_0c09f6a8;
case 0x0c09f6aau: goto P_0c09f6aa;
case 0x0c09f6acu: goto P_0c09f6ac;
case 0x0c09f6aeu: goto P_0c09f6ae;
case 0x0c09f6b0u: goto P_0c09f6b0;
case 0x0c09f6b2u: goto P_0c09f6b2;
case 0x0c09f6b4u: goto P_0c09f6b4;
case 0x0c09f6b6u: goto P_0c09f6b6;
case 0x0c09f6b8u: goto P_0c09f6b8;
case 0x0c09f6bau: goto P_0c09f6ba;
case 0x0c09f6bcu: goto P_0c09f6bc;
case 0x0c09f6beu: goto P_0c09f6be;
case 0x0c09f6d0u: goto P_0c09f6d0;
case 0x0c09f6d2u: goto P_0c09f6d2;
case 0x0c09f6d4u: goto P_0c09f6d4;
case 0x0c09f6d6u: goto P_0c09f6d6;
case 0x0c09f6d8u: goto P_0c09f6d8;
case 0x0c09f6dau: goto P_0c09f6da;
case 0x0c09f6dcu: goto P_0c09f6dc;
case 0x0c09f6deu: goto P_0c09f6de;
case 0x0c09f6e0u: goto P_0c09f6e0;
case 0x0c09f6e2u: goto P_0c09f6e2;
case 0x0c09f6e4u: goto P_0c09f6e4;
case 0x0c09f6e6u: goto P_0c09f6e6;
case 0x0c09f6e8u: goto P_0c09f6e8;
case 0x0c09f6eau: goto P_0c09f6ea;
case 0x0c09f6ecu: goto P_0c09f6ec;
case 0x0c09f6eeu: goto P_0c09f6ee;
case 0x0c09f6f0u: goto P_0c09f6f0;
case 0x0c09f6f2u: goto P_0c09f6f2;
case 0x0c09f6f4u: goto P_0c09f6f4;
case 0x0c09f6f6u: goto P_0c09f6f6;
case 0x0c09f6f8u: goto P_0c09f6f8;
case 0x0c09f6fau: goto P_0c09f6fa;
case 0x0c09f6fcu: goto P_0c09f6fc;
case 0x0c09f6feu: goto P_0c09f6fe;
case 0x0c09f700u: goto P_0c09f700;
case 0x0c09f702u: goto P_0c09f702;
case 0x0c09f704u: goto P_0c09f704;
case 0x0c09f706u: goto P_0c09f706;
case 0x0c09f708u: goto P_0c09f708;
case 0x0c09f70au: goto P_0c09f70a;
case 0x0c09f70cu: goto P_0c09f70c;
case 0x0c09f70eu: goto P_0c09f70e;
case 0x0c09f710u: goto P_0c09f710;
case 0x0c09f712u: goto P_0c09f712;
case 0x0c09f714u: goto P_0c09f714;
case 0x0c09f716u: goto P_0c09f716;
case 0x0c09f718u: goto P_0c09f718;
case 0x0c09f71au: goto P_0c09f71a;
case 0x0c09f71cu: goto P_0c09f71c;
case 0x0c09f71eu: goto P_0c09f71e;
case 0x0c09f720u: goto P_0c09f720;
case 0x0c09f722u: goto P_0c09f722;
case 0x0c09f724u: goto P_0c09f724;
case 0x0c09f726u: goto P_0c09f726;
case 0x0c09f728u: goto P_0c09f728;
case 0x0c09f72au: goto P_0c09f72a;
case 0x0c09f72cu: goto P_0c09f72c;
case 0x0c09f72eu: goto P_0c09f72e;
case 0x0c09f730u: goto P_0c09f730;
case 0x0c09f732u: goto P_0c09f732;
case 0x0c09f734u: goto P_0c09f734;
case 0x0c09f736u: goto P_0c09f736;
case 0x0c09f738u: goto P_0c09f738;
case 0x0c09f73au: goto P_0c09f73a;
case 0x0c09f73cu: goto P_0c09f73c;
case 0x0c09f73eu: goto P_0c09f73e;
case 0x0c09f740u: goto P_0c09f740;
case 0x0c09f742u: goto P_0c09f742;
case 0x0c09f744u: goto P_0c09f744;
case 0x0c09f746u: goto P_0c09f746;
case 0x0c09f748u: goto P_0c09f748;
case 0x0c09f74au: goto P_0c09f74a;
case 0x0c09f74cu: goto P_0c09f74c;
case 0x0c09f74eu: goto P_0c09f74e;
case 0x0c09f750u: goto P_0c09f750;
case 0x0c09f752u: goto P_0c09f752;
case 0x0c09f754u: goto P_0c09f754;
case 0x0c09f756u: goto P_0c09f756;
case 0x0c09f758u: goto P_0c09f758;
case 0x0c09f75au: goto P_0c09f75a;
case 0x0c09f75cu: goto P_0c09f75c;
case 0x0c09f75eu: goto P_0c09f75e;
case 0x0c09f760u: goto P_0c09f760;
case 0x0c09f762u: goto P_0c09f762;
case 0x0c09f764u: goto P_0c09f764;
case 0x0c09f766u: goto P_0c09f766;
case 0x0c09f768u: goto P_0c09f768;
case 0x0c09f76au: goto P_0c09f76a;
case 0x0c09f76cu: goto P_0c09f76c;
case 0x0c09f76eu: goto P_0c09f76e;
case 0x0c09f770u: goto P_0c09f770;
case 0x0c09f772u: goto P_0c09f772;
case 0x0c09f774u: goto P_0c09f774;
case 0x0c09f776u: goto P_0c09f776;
case 0x0c09f778u: goto P_0c09f778;
case 0x0c09f77au: goto P_0c09f77a;
case 0x0c09f77cu: goto P_0c09f77c;
case 0x0c09f77eu: goto P_0c09f77e;
case 0x0c09f780u: goto P_0c09f780;
case 0x0c09f782u: goto P_0c09f782;
case 0x0c09f784u: goto P_0c09f784;
case 0x0c09f786u: goto P_0c09f786;
case 0x0c09f788u: goto P_0c09f788;
case 0x0c09f78au: goto P_0c09f78a;
case 0x0c09f78cu: goto P_0c09f78c;
case 0x0c09f78eu: goto P_0c09f78e;
case 0x0c09f790u: goto P_0c09f790;
case 0x0c09f792u: goto P_0c09f792;
case 0x0c09f794u: goto P_0c09f794;
case 0x0c09f796u: goto P_0c09f796;
case 0x0c09f798u: goto P_0c09f798;
case 0x0c09f79au: goto P_0c09f79a;
case 0x0c09f79cu: goto P_0c09f79c;
case 0x0c09f79eu: goto P_0c09f79e;
case 0x0c09f7a0u: goto P_0c09f7a0;
case 0x0c09f7a2u: goto P_0c09f7a2;
case 0x0c09f7a4u: goto P_0c09f7a4;
case 0x0c09f7a6u: goto P_0c09f7a6;
case 0x0c09f7a8u: goto P_0c09f7a8;
case 0x0c09f7aau: goto P_0c09f7aa;
case 0x0c09f7acu: goto P_0c09f7ac;
case 0x0c09f7aeu: goto P_0c09f7ae;
case 0x0c09f7b0u: goto P_0c09f7b0;
case 0x0c09f7b2u: goto P_0c09f7b2;
case 0x0c09f7d4u: goto P_0c09f7d4;
case 0x0c09f7d6u: goto P_0c09f7d6;
case 0x0c09f7d8u: goto P_0c09f7d8;
case 0x0c09f7dau: goto P_0c09f7da;
case 0x0c09f7dcu: goto P_0c09f7dc;
case 0x0c09f7deu: goto P_0c09f7de;
case 0x0c09f7e0u: goto P_0c09f7e0;
case 0x0c09f7e2u: goto P_0c09f7e2;
case 0x0c09f7e4u: goto P_0c09f7e4;
case 0x0c09f7e6u: goto P_0c09f7e6;
case 0x0c09f7e8u: goto P_0c09f7e8;
case 0x0c09f7eau: goto P_0c09f7ea;
case 0x0c09f7ecu: goto P_0c09f7ec;
case 0x0c09f7eeu: goto P_0c09f7ee;
case 0x0c09f7f0u: goto P_0c09f7f0;
case 0x0c09f7f2u: goto P_0c09f7f2;
case 0x0c09f7f4u: goto P_0c09f7f4;
case 0x0c09f7f6u: goto P_0c09f7f6;
case 0x0c09f7f8u: goto P_0c09f7f8;
case 0x0c09f7fau: goto P_0c09f7fa;
case 0x0c09f7fcu: goto P_0c09f7fc;
case 0x0c09f7feu: goto P_0c09f7fe;
case 0x0c09f800u: goto P_0c09f800;
case 0x0c09f802u: goto P_0c09f802;
case 0x0c09f804u: goto P_0c09f804;
case 0x0c09f806u: goto P_0c09f806;
case 0x0c09f808u: goto P_0c09f808;
case 0x0c09f80au: goto P_0c09f80a;
case 0x0c09f80cu: goto P_0c09f80c;
case 0x0c09f80eu: goto P_0c09f80e;
case 0x0c09f810u: goto P_0c09f810;
case 0x0c09f812u: goto P_0c09f812;
case 0x0c09f814u: goto P_0c09f814;
case 0x0c09f816u: goto P_0c09f816;
case 0x0c09f818u: goto P_0c09f818;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f5f8: /* original d531, guest PC 0x0c09f5f8 */
if(!s->budget--) { s->failed_pc=0x0c09f5f8u; return 0; }
r[5]=read(ram,0x0c09f6c0u,4);
goto P_0c09f5fa;
P_0c09f5fa: /* original 7ff8, guest PC 0x0c09f5fa */
if(!s->budget--) { s->failed_pc=0x0c09f5fau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09f5fc;
P_0c09f5fc: /* original d331, guest PC 0x0c09f5fc */
if(!s->budget--) { s->failed_pc=0x0c09f5fcu; return 0; }
r[3]=read(ram,0x0c09f6c4u,4);
goto P_0c09f5fe;
P_0c09f5fe: /* original 6252, guest PC 0x0c09f5fe */
if(!s->budget--) { s->failed_pc=0x0c09f5feu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c09f600;
P_0c09f600: /* original 2238, guest PC 0x0c09f600 */
if(!s->budget--) { s->failed_pc=0x0c09f600u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09f602;
P_0c09f602: /* original 8b5a, guest PC 0x0c09f602 */
if(!s->budget--) { s->failed_pc=0x0c09f602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f6ba; }
goto P_0c09f604;
P_0c09f604: /* original c730, guest PC 0x0c09f604 */
if(!s->budget--) { s->failed_pc=0x0c09f604u; return 0; }
r[0]=code_base|0x0009f6c8u;
goto P_0c09f606;
P_0c09f606: /* original fa48, guest PC 0x0c09f606 */
if(!s->budget--) { s->failed_pc=0x0c09f606u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
goto P_0c09f608;
P_0c09f608: /* original f108, guest PC 0x0c09f608 */
if(!s->budget--) { s->failed_pc=0x0c09f608u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f60a;
P_0c09f60a: /* original 6643, guest PC 0x0c09f60a */
if(!s->budget--) { s->failed_pc=0x0c09f60au; return 0; }
r[6]=r[4];
goto P_0c09f60c;
P_0c09f60c: /* original 6543, guest PC 0x0c09f60c */
if(!s->budget--) { s->failed_pc=0x0c09f60cu; return 0; }
r[5]=r[4];
goto P_0c09f60e;
P_0c09f60e: /* original 7608, guest PC 0x0c09f60e */
if(!s->budget--) { s->failed_pc=0x0c09f60eu; return 0; }
r[6]+=0x00000008u;
goto P_0c09f610;
P_0c09f610: /* original fa15, guest PC 0x0c09f610 */
if(!s->budget--) { s->failed_pc=0x0c09f610u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[1]))!=0);
goto P_0c09f612;
P_0c09f612: /* original 7504, guest PC 0x0c09f612 */
if(!s->budget--) { s->failed_pc=0x0c09f612u; return 0; }
r[5]+=0x00000004u;
goto P_0c09f614;
P_0c09f614: /* original f258, guest PC 0x0c09f614 */
if(!s->budget--) { s->failed_pc=0x0c09f614u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c09f616;
P_0c09f616: /* original c72d, guest PC 0x0c09f616 */
if(!s->budget--) { s->failed_pc=0x0c09f616u; return 0; }
r[0]=code_base|0x0009f6ccu;
goto P_0c09f618;
P_0c09f618: /* original fb68, guest PC 0x0c09f618 */
if(!s->budget--) { s->failed_pc=0x0c09f618u; return 0; }
vf3_matrix_load(s,ram,11,r[6]);
goto P_0c09f61a;
P_0c09f61a: /* original 8d06, guest PC 0x0c09f61a */
if(!s->budget--) { s->failed_pc=0x0c09f61au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,0,r[0]);
if(cond) { goto P_0c09f62a; }
goto P_0c09f61e;
P_0c09f61c: /* original f008, guest PC 0x0c09f61c */
if(!s->budget--) { s->failed_pc=0x0c09f61cu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c09f61e;
P_0c09f61e: /* original f0a5, guest PC 0x0c09f61e */
if(!s->budget--) { s->failed_pc=0x0c09f61eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[10]))!=0);
goto P_0c09f620;
P_0c09f620: /* original 8905, guest PC 0x0c09f620 */
if(!s->budget--) { s->failed_pc=0x0c09f620u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f62e; }
goto P_0c09f622;
P_0c09f622: /* original fa15, guest PC 0x0c09f622 */
if(!s->budget--) { s->failed_pc=0x0c09f622u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[1]))!=0);
goto P_0c09f624;
P_0c09f624: /* original 8901, guest PC 0x0c09f624 */
if(!s->budget--) { s->failed_pc=0x0c09f624u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f62a; }
goto P_0c09f626;
P_0c09f626: /* original f0a5, guest PC 0x0c09f626 */
if(!s->budget--) { s->failed_pc=0x0c09f626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[10]))!=0);
goto P_0c09f628;
P_0c09f628: /* original 8b02, guest PC 0x0c09f628 */
if(!s->budget--) { s->failed_pc=0x0c09f628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f630; }
goto P_0c09f62a;
P_0c09f62a: /* original a001, guest PC 0x0c09f62a */
if(!s->budget--) { s->failed_pc=0x0c09f62au; return 0; }
vf3_matrix_move(s,10,1);
goto P_0c09f630;
P_0c09f62c: /* original fa1c, guest PC 0x0c09f62c */
if(!s->budget--) { s->failed_pc=0x0c09f62cu; return 0; }
vf3_matrix_move(s,10,1);
goto P_0c09f62e;
P_0c09f62e: /* original fa0c, guest PC 0x0c09f62e */
if(!s->budget--) { s->failed_pc=0x0c09f62eu; return 0; }
vf3_matrix_move(s,10,0);
goto P_0c09f630;
P_0c09f630: /* original fb15, guest PC 0x0c09f630 */
if(!s->budget--) { s->failed_pc=0x0c09f630u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[1]))!=0);
goto P_0c09f632;
P_0c09f632: /* original 8905, guest PC 0x0c09f632 */
if(!s->budget--) { s->failed_pc=0x0c09f632u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f640; }
goto P_0c09f634;
P_0c09f634: /* original f0b5, guest PC 0x0c09f634 */
if(!s->budget--) { s->failed_pc=0x0c09f634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[11]))!=0);
goto P_0c09f636;
P_0c09f636: /* original 8905, guest PC 0x0c09f636 */
if(!s->budget--) { s->failed_pc=0x0c09f636u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f644; }
goto P_0c09f638;
P_0c09f638: /* original fb15, guest PC 0x0c09f638 */
if(!s->budget--) { s->failed_pc=0x0c09f638u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[1]))!=0);
goto P_0c09f63a;
P_0c09f63a: /* original 8901, guest PC 0x0c09f63a */
if(!s->budget--) { s->failed_pc=0x0c09f63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f640; }
goto P_0c09f63c;
P_0c09f63c: /* original f0b5, guest PC 0x0c09f63c */
if(!s->budget--) { s->failed_pc=0x0c09f63cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[11]))!=0);
goto P_0c09f63e;
P_0c09f63e: /* original 8b02, guest PC 0x0c09f63e */
if(!s->budget--) { s->failed_pc=0x0c09f63eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f646; }
goto P_0c09f640;
P_0c09f640: /* original a001, guest PC 0x0c09f640 */
if(!s->budget--) { s->failed_pc=0x0c09f640u; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c09f646;
P_0c09f642: /* original fb1c, guest PC 0x0c09f642 */
if(!s->budget--) { s->failed_pc=0x0c09f642u; return 0; }
vf3_matrix_move(s,11,1);
goto P_0c09f644;
P_0c09f644: /* original fb0c, guest PC 0x0c09f644 */
if(!s->budget--) { s->failed_pc=0x0c09f644u; return 0; }
vf3_matrix_move(s,11,0);
goto P_0c09f646;
P_0c09f646: /* original f215, guest PC 0x0c09f646 */
if(!s->budget--) { s->failed_pc=0x0c09f646u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c09f648;
P_0c09f648: /* original 8905, guest PC 0x0c09f648 */
if(!s->budget--) { s->failed_pc=0x0c09f648u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f656; }
goto P_0c09f64a;
P_0c09f64a: /* original f025, guest PC 0x0c09f64a */
if(!s->budget--) { s->failed_pc=0x0c09f64au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[2]))!=0);
goto P_0c09f64c;
P_0c09f64c: /* original 8905, guest PC 0x0c09f64c */
if(!s->budget--) { s->failed_pc=0x0c09f64cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f65a; }
goto P_0c09f64e;
P_0c09f64e: /* original f215, guest PC 0x0c09f64e */
if(!s->budget--) { s->failed_pc=0x0c09f64eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[1]))!=0);
goto P_0c09f650;
P_0c09f650: /* original 8901, guest PC 0x0c09f650 */
if(!s->budget--) { s->failed_pc=0x0c09f650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f656; }
goto P_0c09f652;
P_0c09f652: /* original f025, guest PC 0x0c09f652 */
if(!s->budget--) { s->failed_pc=0x0c09f652u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[2]))!=0);
goto P_0c09f654;
P_0c09f654: /* original 8b02, guest PC 0x0c09f654 */
if(!s->budget--) { s->failed_pc=0x0c09f654u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f65c; }
goto P_0c09f656;
P_0c09f656: /* original a001, guest PC 0x0c09f656 */
if(!s->budget--) { s->failed_pc=0x0c09f656u; return 0; }
vf3_matrix_move(s,2,1);
goto P_0c09f65c;
P_0c09f658: /* original f21c, guest PC 0x0c09f658 */
if(!s->budget--) { s->failed_pc=0x0c09f658u; return 0; }
vf3_matrix_move(s,2,1);
goto P_0c09f65a;
P_0c09f65a: /* original f20c, guest PC 0x0c09f65a */
if(!s->budget--) { s->failed_pc=0x0c09f65au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c09f65c;
P_0c09f65c: /* original f8a5, guest PC 0x0c09f65c */
if(!s->budget--) { s->failed_pc=0x0c09f65cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[10]))!=0);
goto P_0c09f65e;
P_0c09f65e: /* original 8903, guest PC 0x0c09f65e */
if(!s->budget--) { s->failed_pc=0x0c09f65eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f668; }
goto P_0c09f660;
P_0c09f660: /* original fa45, guest PC 0x0c09f660 */
if(!s->budget--) { s->failed_pc=0x0c09f660u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[4]))!=0);
goto P_0c09f662;
P_0c09f662: /* original 8b07, guest PC 0x0c09f662 */
if(!s->budget--) { s->failed_pc=0x0c09f662u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f674; }
goto P_0c09f664;
P_0c09f664: /* original affa, guest PC 0x0c09f664 */
if(!s->budget--) { s->failed_pc=0x0c09f664u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c09f65c;
P_0c09f666: /* original fa91, guest PC 0x0c09f666 */
if(!s->budget--) { s->failed_pc=0x0c09f666u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'-');
goto P_0c09f668;
P_0c09f668: /* original fa65, guest PC 0x0c09f668 */
if(!s->budget--) { s->failed_pc=0x0c09f668u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c09f66a;
P_0c09f66a: /* original 8903, guest PC 0x0c09f66a */
if(!s->budget--) { s->failed_pc=0x0c09f66au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f674; }
goto P_0c09f66c;
P_0c09f66c: /* original f3ac, guest PC 0x0c09f66c */
if(!s->budget--) { s->failed_pc=0x0c09f66cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09f66e;
P_0c09f66e: /* original fa9c, guest PC 0x0c09f66e */
if(!s->budget--) { s->failed_pc=0x0c09f66eu; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c09f670;
P_0c09f670: /* original aff4, guest PC 0x0c09f670 */
if(!s->budget--) { s->failed_pc=0x0c09f670u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c09f65c;
P_0c09f672: /* original fa30, guest PC 0x0c09f672 */
if(!s->budget--) { s->failed_pc=0x0c09f672u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'+');
goto P_0c09f674;
P_0c09f674: /* original f8b5, guest PC 0x0c09f674 */
if(!s->budget--) { s->failed_pc=0x0c09f674u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[11]))!=0);
goto P_0c09f676;
P_0c09f676: /* original 8903, guest PC 0x0c09f676 */
if(!s->budget--) { s->failed_pc=0x0c09f676u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f680; }
goto P_0c09f678;
P_0c09f678: /* original fb45, guest PC 0x0c09f678 */
if(!s->budget--) { s->failed_pc=0x0c09f678u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[4]))!=0);
goto P_0c09f67a;
P_0c09f67a: /* original 8b07, guest PC 0x0c09f67a */
if(!s->budget--) { s->failed_pc=0x0c09f67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f68c; }
goto P_0c09f67c;
P_0c09f67c: /* original affa, guest PC 0x0c09f67c */
if(!s->budget--) { s->failed_pc=0x0c09f67cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'-');
goto P_0c09f674;
P_0c09f67e: /* original fb91, guest PC 0x0c09f67e */
if(!s->budget--) { s->failed_pc=0x0c09f67eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'-');
goto P_0c09f680;
P_0c09f680: /* original fb65, guest PC 0x0c09f680 */
if(!s->budget--) { s->failed_pc=0x0c09f680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[6]))!=0);
goto P_0c09f682;
P_0c09f682: /* original 8903, guest PC 0x0c09f682 */
if(!s->budget--) { s->failed_pc=0x0c09f682u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f68c; }
goto P_0c09f684;
P_0c09f684: /* original f3bc, guest PC 0x0c09f684 */
if(!s->budget--) { s->failed_pc=0x0c09f684u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c09f686;
P_0c09f686: /* original fb9c, guest PC 0x0c09f686 */
if(!s->budget--) { s->failed_pc=0x0c09f686u; return 0; }
vf3_matrix_move(s,11,9);
goto P_0c09f688;
P_0c09f688: /* original aff4, guest PC 0x0c09f688 */
if(!s->budget--) { s->failed_pc=0x0c09f688u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09f674;
P_0c09f68a: /* original fb30, guest PC 0x0c09f68a */
if(!s->budget--) { s->failed_pc=0x0c09f68au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'+');
goto P_0c09f68c;
P_0c09f68c: /* original f3ac, guest PC 0x0c09f68c */
if(!s->budget--) { s->failed_pc=0x0c09f68cu; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c09f68e;
P_0c09f68e: /* original e004, guest PC 0x0c09f68e */
if(!s->budget--) { s->failed_pc=0x0c09f68eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f690;
P_0c09f690: /* original f35d, guest PC 0x0c09f690 */
if(!s->budget--) { s->failed_pc=0x0c09f690u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c09f692;
P_0c09f692: /* original f735, guest PC 0x0c09f692 */
if(!s->budget--) { s->failed_pc=0x0c09f692u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c09f694;
P_0c09f694: /* original 8d0d, guest PC 0x0c09f694 */
if(!s->budget--) { s->failed_pc=0x0c09f694u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(cond) { goto P_0c09f6b2; }
goto P_0c09f698;
P_0c09f696: /* original ff37, guest PC 0x0c09f696 */
if(!s->budget--) { s->failed_pc=0x0c09f696u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f698;
P_0c09f698: /* original f3bc, guest PC 0x0c09f698 */
if(!s->budget--) { s->failed_pc=0x0c09f698u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c09f69a;
P_0c09f69a: /* original f35d, guest PC 0x0c09f69a */
if(!s->budget--) { s->failed_pc=0x0c09f69au; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c09f69c;
P_0c09f69c: /* original f735, guest PC 0x0c09f69c */
if(!s->budget--) { s->failed_pc=0x0c09f69cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c09f69e;
P_0c09f69e: /* original 8d08, guest PC 0x0c09f69e */
if(!s->budget--) { s->failed_pc=0x0c09f69eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]);
if(cond) { goto P_0c09f6b2; }
goto P_0c09f6a2;
P_0c09f6a0: /* original ff3a, guest PC 0x0c09f6a0 */
if(!s->budget--) { s->failed_pc=0x0c09f6a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f6a2;
P_0c09f6a2: /* original f251, guest PC 0x0c09f6a2 */
if(!s->budget--) { s->failed_pc=0x0c09f6a2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c09f6a4;
P_0c09f6a4: /* original fa41, guest PC 0x0c09f6a4 */
if(!s->budget--) { s->failed_pc=0x0c09f6a4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c09f6a6;
P_0c09f6a6: /* original fb41, guest PC 0x0c09f6a6 */
if(!s->budget--) { s->failed_pc=0x0c09f6a6u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[4],r[18],'-');
goto P_0c09f6a8;
P_0c09f6a8: /* original f24d, guest PC 0x0c09f6a8 */
if(!s->budget--) { s->failed_pc=0x0c09f6a8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c09f6aa;
P_0c09f6aa: /* original f32c, guest PC 0x0c09f6aa */
if(!s->budget--) { s->failed_pc=0x0c09f6aau; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c09f6ac;
P_0c09f6ac: /* original f25c, guest PC 0x0c09f6ac */
if(!s->budget--) { s->failed_pc=0x0c09f6acu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09f6ae;
P_0c09f6ae: /* original afd5, guest PC 0x0c09f6ae */
if(!s->budget--) { s->failed_pc=0x0c09f6aeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09f65c;
P_0c09f6b0: /* original f230, guest PC 0x0c09f6b0 */
if(!s->budget--) { s->failed_pc=0x0c09f6b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09f6b2;
P_0c09f6b2: /* original f4aa, guest PC 0x0c09f6b2 */
if(!s->budget--) { s->failed_pc=0x0c09f6b2u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c09f6b4;
P_0c09f6b4: /* original 740c, guest PC 0x0c09f6b4 */
if(!s->budget--) { s->failed_pc=0x0c09f6b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f6b6;
P_0c09f6b6: /* original f52a, guest PC 0x0c09f6b6 */
if(!s->budget--) { s->failed_pc=0x0c09f6b6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f6b8;
P_0c09f6b8: /* original f6ba, guest PC 0x0c09f6b8 */
if(!s->budget--) { s->failed_pc=0x0c09f6b8u; return 0; }
vf3_matrix_store(s,ram,11,r[6]);
goto P_0c09f6ba;
P_0c09f6ba: /* original 6043, guest PC 0x0c09f6ba */
if(!s->budget--) { s->failed_pc=0x0c09f6bau; return 0; }
r[0]=r[4];
goto P_0c09f6bc;
P_0c09f6bc: /* original 000b, guest PC 0x0c09f6bc */
if(!s->budget--) { s->failed_pc=0x0c09f6bcu; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09f6be: /* original 7f08, guest PC 0x0c09f6be */
if(!s->budget--) { s->failed_pc=0x0c09f6beu; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c09f6c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f6c0u; return 0; } return 1;
P_0c09f6d0: /* original 2fe6, guest PC 0x0c09f6d0 */
if(!s->budget--) { s->failed_pc=0x0c09f6d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d2;
P_0c09f6d2: /* original 2fd6, guest PC 0x0c09f6d2 */
if(!s->budget--) { s->failed_pc=0x0c09f6d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d4;
P_0c09f6d4: /* original ed0e, guest PC 0x0c09f6d4 */
if(!s->budget--) { s->failed_pc=0x0c09f6d4u; return 0; }
r[13]=0x0000000eu;
goto P_0c09f6d6;
P_0c09f6d6: /* original 2fc6, guest PC 0x0c09f6d6 */
if(!s->budget--) { s->failed_pc=0x0c09f6d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d8;
P_0c09f6d8: /* original 9c6d, guest PC 0x0c09f6d8 */
if(!s->budget--) { s->failed_pc=0x0c09f6d8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b6u,2);
goto P_0c09f6da;
P_0c09f6da: /* original 9e6b, guest PC 0x0c09f6da */
if(!s->budget--) { s->failed_pc=0x0c09f6dau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b4u,2);
goto P_0c09f6dc;
P_0c09f6dc: /* original 4f22, guest PC 0x0c09f6dc */
if(!s->budget--) { s->failed_pc=0x0c09f6dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f6de;
P_0c09f6de: /* original 3c4c, guest PC 0x0c09f6de */
if(!s->budget--) { s->failed_pc=0x0c09f6deu; return 0; }
r[12]+=r[4];
goto P_0c09f6e0;
P_0c09f6e0: /* original 3e4c, guest PC 0x0c09f6e0 */
if(!s->budget--) { s->failed_pc=0x0c09f6e0u; return 0; }
r[14]+=r[4];
goto P_0c09f6e2;
P_0c09f6e2: /* original 65c3, guest PC 0x0c09f6e2 */
if(!s->budget--) { s->failed_pc=0x0c09f6e2u; return 0; }
r[5]=r[12];
goto P_0c09f6e4;
P_0c09f6e4: /* original b00a, guest PC 0x0c09f6e4 */
if(!s->budget--) { s->failed_pc=0x0c09f6e4u; return 0; }
target=code_base|0x0c09f6fcu; r[16]=code_base|0x0c09f6e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f6e8u) { target=s->pc; goto dispatch; }
goto P_0c09f6e8;
P_0c09f6e6: /* original 64e3, guest PC 0x0c09f6e6 */
if(!s->budget--) { s->failed_pc=0x0c09f6e6u; return 0; }
r[4]=r[14];
goto P_0c09f6e8;
P_0c09f6e8: /* original 7dff, guest PC 0x0c09f6e8 */
if(!s->budget--) { s->failed_pc=0x0c09f6e8u; return 0; }
r[13]+=0xffffffffu;
goto P_0c09f6ea;
P_0c09f6ea: /* original 4d15, guest PC 0x0c09f6ea */
if(!s->budget--) { s->failed_pc=0x0c09f6eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c09f6ec;
P_0c09f6ec: /* original 7e0c, guest PC 0x0c09f6ec */
if(!s->budget--) { s->failed_pc=0x0c09f6ecu; return 0; }
r[14]+=0x0000000cu;
goto P_0c09f6ee;
P_0c09f6ee: /* original 8df8, guest PC 0x0c09f6ee */
if(!s->budget--) { s->failed_pc=0x0c09f6eeu; return 0; }
cond=r[17]&1u;
r[12]+=0x0000000cu;
if(cond) { goto P_0c09f6e2; }
goto P_0c09f6f2;
P_0c09f6f0: /* original 7c0c, guest PC 0x0c09f6f0 */
if(!s->budget--) { s->failed_pc=0x0c09f6f0u; return 0; }
r[12]+=0x0000000cu;
goto P_0c09f6f2;
P_0c09f6f2: /* original 4f26, guest PC 0x0c09f6f2 */
if(!s->budget--) { s->failed_pc=0x0c09f6f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f6f4;
P_0c09f6f4: /* original 6cf6, guest PC 0x0c09f6f4 */
if(!s->budget--) { s->failed_pc=0x0c09f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f6f6;
P_0c09f6f6: /* original 6df6, guest PC 0x0c09f6f6 */
if(!s->budget--) { s->failed_pc=0x0c09f6f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f6f8;
P_0c09f6f8: /* original 000b, guest PC 0x0c09f6f8 */
if(!s->budget--) { s->failed_pc=0x0c09f6f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f6fa: /* original 6ef6, guest PC 0x0c09f6fa */
if(!s->budget--) { s->failed_pc=0x0c09f6fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09f6fc;
P_0c09f6fc: /* original c72e, guest PC 0x0c09f6fc */
if(!s->budget--) { s->failed_pc=0x0c09f6fcu; return 0; }
r[0]=code_base|0x0009f7b8u;
goto P_0c09f6fe;
P_0c09f6fe: /* original ffdb, guest PC 0x0c09f6fe */
if(!s->budget--) { s->failed_pc=0x0c09f6feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f700;
P_0c09f700: /* original f908, guest PC 0x0c09f700 */
if(!s->budget--) { s->failed_pc=0x0c09f700u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c09f702;
P_0c09f702: /* original c72e, guest PC 0x0c09f702 */
if(!s->budget--) { s->failed_pc=0x0c09f702u; return 0; }
r[0]=code_base|0x0009f7bcu;
goto P_0c09f704;
P_0c09f704: /* original fa08, guest PC 0x0c09f704 */
if(!s->budget--) { s->failed_pc=0x0c09f704u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09f706;
P_0c09f706: /* original c72e, guest PC 0x0c09f706 */
if(!s->budget--) { s->failed_pc=0x0c09f706u; return 0; }
r[0]=code_base|0x0009f7c0u;
goto P_0c09f708;
P_0c09f708: /* original fb08, guest PC 0x0c09f708 */
if(!s->budget--) { s->failed_pc=0x0c09f708u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c09f70a;
P_0c09f70a: /* original c72e, guest PC 0x0c09f70a */
if(!s->budget--) { s->failed_pc=0x0c09f70au; return 0; }
r[0]=code_base|0x0009f7c4u;
goto P_0c09f70c;
P_0c09f70c: /* original f808, guest PC 0x0c09f70c */
if(!s->budget--) { s->failed_pc=0x0c09f70cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c09f70e;
P_0c09f70e: /* original c72e, guest PC 0x0c09f70e */
if(!s->budget--) { s->failed_pc=0x0c09f70eu; return 0; }
r[0]=code_base|0x0009f7c8u;
goto P_0c09f710;
P_0c09f710: /* original f708, guest PC 0x0c09f710 */
if(!s->budget--) { s->failed_pc=0x0c09f710u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09f712;
P_0c09f712: /* original e004, guest PC 0x0c09f712 */
if(!s->budget--) { s->failed_pc=0x0c09f712u; return 0; }
r[0]=0x00000004u;
goto P_0c09f714;
P_0c09f714: /* original f348, guest PC 0x0c09f714 */
if(!s->budget--) { s->failed_pc=0x0c09f714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09f716;
P_0c09f716: /* original 7ff4, guest PC 0x0c09f716 */
if(!s->budget--) { s->failed_pc=0x0c09f716u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f718;
P_0c09f718: /* original 6653, guest PC 0x0c09f718 */
if(!s->budget--) { s->failed_pc=0x0c09f718u; return 0; }
r[6]=r[5];
goto P_0c09f71a;
P_0c09f71a: /* original 7604, guest PC 0x0c09f71a */
if(!s->budget--) { s->failed_pc=0x0c09f71au; return 0; }
r[6]+=0x00000004u;
goto P_0c09f71c;
P_0c09f71c: /* original ff37, guest PC 0x0c09f71c */
if(!s->budget--) { s->failed_pc=0x0c09f71cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f71e;
P_0c09f71e: /* original e004, guest PC 0x0c09f71e */
if(!s->budget--) { s->failed_pc=0x0c09f71eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f720;
P_0c09f720: /* original f346, guest PC 0x0c09f720 */
if(!s->budget--) { s->failed_pc=0x0c09f720u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f722;
P_0c09f722: /* original e008, guest PC 0x0c09f722 */
if(!s->budget--) { s->failed_pc=0x0c09f722u; return 0; }
r[0]=0x00000008u;
goto P_0c09f724;
P_0c09f724: /* original f558, guest PC 0x0c09f724 */
if(!s->budget--) { s->failed_pc=0x0c09f724u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09f726;
P_0c09f726: /* original ff3a, guest PC 0x0c09f726 */
if(!s->budget--) { s->failed_pc=0x0c09f726u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f728;
P_0c09f728: /* original f346, guest PC 0x0c09f728 */
if(!s->budget--) { s->failed_pc=0x0c09f728u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f72a;
P_0c09f72a: /* original 6453, guest PC 0x0c09f72a */
if(!s->budget--) { s->failed_pc=0x0c09f72au; return 0; }
r[4]=r[5];
goto P_0c09f72c;
P_0c09f72c: /* original 7408, guest PC 0x0c09f72c */
if(!s->budget--) { s->failed_pc=0x0c09f72cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09f72e;
P_0c09f72e: /* original f668, guest PC 0x0c09f72e */
if(!s->budget--) { s->failed_pc=0x0c09f72eu; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c09f730;
P_0c09f730: /* original e008, guest PC 0x0c09f730 */
if(!s->budget--) { s->failed_pc=0x0c09f730u; return 0; }
r[0]=0x00000008u;
goto P_0c09f732;
P_0c09f732: /* original ff37, guest PC 0x0c09f732 */
if(!s->budget--) { s->failed_pc=0x0c09f732u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f734;
P_0c09f734: /* original f448, guest PC 0x0c09f734 */
if(!s->budget--) { s->failed_pc=0x0c09f734u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09f736;
P_0c09f736: /* original e004, guest PC 0x0c09f736 */
if(!s->budget--) { s->failed_pc=0x0c09f736u; return 0; }
r[0]=0x00000004u;
goto P_0c09f738;
P_0c09f738: /* original f28d, guest PC 0x0c09f738 */
if(!s->budget--) { s->failed_pc=0x0c09f738u; return 0; }
fr[2]=0;
goto P_0c09f73a;
P_0c09f73a: /* original f1f6, guest PC 0x0c09f73a */
if(!s->budget--) { s->failed_pc=0x0c09f73au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c09f73c;
P_0c09f73c: /* original c723, guest PC 0x0c09f73c */
if(!s->budget--) { s->failed_pc=0x0c09f73cu; return 0; }
r[0]=code_base|0x0009f7ccu;
goto P_0c09f73e;
P_0c09f73e: /* original f151, guest PC 0x0c09f73e */
if(!s->budget--) { s->failed_pc=0x0c09f73eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09f740;
P_0c09f740: /* original f01c, guest PC 0x0c09f740 */
if(!s->budget--) { s->failed_pc=0x0c09f740u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c09f742;
P_0c09f742: /* original f05d, guest PC 0x0c09f742 */
if(!s->budget--) { s->failed_pc=0x0c09f742u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c09f744;
P_0c09f744: /* original f705, guest PC 0x0c09f744 */
if(!s->budget--) { s->failed_pc=0x0c09f744u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[0]))!=0);
goto P_0c09f746;
P_0c09f746: /* original 8f17, guest PC 0x0c09f746 */
if(!s->budget--) { s->failed_pc=0x0c09f746u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[0]);
if(!cond) { goto P_0c09f778; }
goto P_0c09f74a;
P_0c09f748: /* original fd08, guest PC 0x0c09f748 */
if(!s->budget--) { s->failed_pc=0x0c09f748u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09f74a;
P_0c09f74a: /* original f805, guest PC 0x0c09f74a */
if(!s->budget--) { s->failed_pc=0x0c09f74au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c09f74c;
P_0c09f74c: /* original 8b08, guest PC 0x0c09f74c */
if(!s->budget--) { s->failed_pc=0x0c09f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f760; }
goto P_0c09f74e;
P_0c09f74e: /* original f905, guest PC 0x0c09f74e */
if(!s->budget--) { s->failed_pc=0x0c09f74eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[0]))!=0);
goto P_0c09f750;
P_0c09f750: /* original 8913, guest PC 0x0c09f750 */
if(!s->budget--) { s->failed_pc=0x0c09f750u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f77a; }
goto P_0c09f752;
P_0c09f752: /* original f38d, guest PC 0x0c09f752 */
if(!s->budget--) { s->failed_pc=0x0c09f752u; return 0; }
fr[3]=0;
goto P_0c09f754;
P_0c09f754: /* original f315, guest PC 0x0c09f754 */
if(!s->budget--) { s->failed_pc=0x0c09f754u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f756;
P_0c09f756: /* original 8901, guest PC 0x0c09f756 */
if(!s->budget--) { s->failed_pc=0x0c09f756u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f75c; }
goto P_0c09f758;
P_0c09f758: /* original a009, guest PC 0x0c09f758 */
if(!s->budget--) { s->failed_pc=0x0c09f758u; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f76e;
P_0c09f75a: /* original f1ac, guest PC 0x0c09f75a */
if(!s->budget--) { s->failed_pc=0x0c09f75au; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f75c;
P_0c09f75c: /* original a007, guest PC 0x0c09f75c */
if(!s->budget--) { s->failed_pc=0x0c09f75cu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f76e;
P_0c09f75e: /* original f1dc, guest PC 0x0c09f75e */
if(!s->budget--) { s->failed_pc=0x0c09f75eu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f760;
P_0c09f760: /* original f38d, guest PC 0x0c09f760 */
if(!s->budget--) { s->failed_pc=0x0c09f760u; return 0; }
fr[3]=0;
goto P_0c09f762;
P_0c09f762: /* original f315, guest PC 0x0c09f762 */
if(!s->budget--) { s->failed_pc=0x0c09f762u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f764;
P_0c09f764: /* original 8901, guest PC 0x0c09f764 */
if(!s->budget--) { s->failed_pc=0x0c09f764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f76a; }
goto P_0c09f766;
P_0c09f766: /* original a002, guest PC 0x0c09f766 */
if(!s->budget--) { s->failed_pc=0x0c09f766u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76e;
P_0c09f768: /* original f1bc, guest PC 0x0c09f768 */
if(!s->budget--) { s->failed_pc=0x0c09f768u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76a;
P_0c09f76a: /* original c719, guest PC 0x0c09f76a */
if(!s->budget--) { s->failed_pc=0x0c09f76au; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f76c;
P_0c09f76c: /* original f108, guest PC 0x0c09f76c */
if(!s->budget--) { s->failed_pc=0x0c09f76cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f76e;
P_0c09f76e: /* original f35c, guest PC 0x0c09f76e */
if(!s->budget--) { s->failed_pc=0x0c09f76eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09f770;
P_0c09f770: /* original f51c, guest PC 0x0c09f770 */
if(!s->budget--) { s->failed_pc=0x0c09f770u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c09f772;
P_0c09f772: /* original f530, guest PC 0x0c09f772 */
if(!s->budget--) { s->failed_pc=0x0c09f772u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c09f774;
P_0c09f774: /* original afdf, guest PC 0x0c09f774 */
if(!s->budget--) { s->failed_pc=0x0c09f774u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f736;
P_0c09f776: /* original f55a, guest PC 0x0c09f776 */
if(!s->budget--) { s->failed_pc=0x0c09f776u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f778;
P_0c09f778: /* original f52a, guest PC 0x0c09f778 */
if(!s->budget--) { s->failed_pc=0x0c09f778u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f77a;
P_0c09f77a: /* original f5f8, guest PC 0x0c09f77a */
if(!s->budget--) { s->failed_pc=0x0c09f77au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f77c;
P_0c09f77c: /* original f561, guest PC 0x0c09f77c */
if(!s->budget--) { s->failed_pc=0x0c09f77cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c09f77e;
P_0c09f77e: /* original f15c, guest PC 0x0c09f77e */
if(!s->budget--) { s->failed_pc=0x0c09f77eu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c09f780;
P_0c09f780: /* original f15d, guest PC 0x0c09f780 */
if(!s->budget--) { s->failed_pc=0x0c09f780u; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c09f782;
P_0c09f782: /* original f715, guest PC 0x0c09f782 */
if(!s->budget--) { s->failed_pc=0x0c09f782u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c09f784;
P_0c09f784: /* original 8b26, guest PC 0x0c09f784 */
if(!s->budget--) { s->failed_pc=0x0c09f784u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7d4; }
goto P_0c09f786;
P_0c09f786: /* original f815, guest PC 0x0c09f786 */
if(!s->budget--) { s->failed_pc=0x0c09f786u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c09f788;
P_0c09f788: /* original 8b08, guest PC 0x0c09f788 */
if(!s->budget--) { s->failed_pc=0x0c09f788u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f79c; }
goto P_0c09f78a;
P_0c09f78a: /* original f915, guest PC 0x0c09f78a */
if(!s->budget--) { s->failed_pc=0x0c09f78au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c09f78c;
P_0c09f78c: /* original 8923, guest PC 0x0c09f78c */
if(!s->budget--) { s->failed_pc=0x0c09f78cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7d6; }
goto P_0c09f78e;
P_0c09f78e: /* original f38d, guest PC 0x0c09f78e */
if(!s->budget--) { s->failed_pc=0x0c09f78eu; return 0; }
fr[3]=0;
goto P_0c09f790;
P_0c09f790: /* original f355, guest PC 0x0c09f790 */
if(!s->budget--) { s->failed_pc=0x0c09f790u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f792;
P_0c09f792: /* original 8901, guest PC 0x0c09f792 */
if(!s->budget--) { s->failed_pc=0x0c09f792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f798; }
goto P_0c09f794;
P_0c09f794: /* original a009, guest PC 0x0c09f794 */
if(!s->budget--) { s->failed_pc=0x0c09f794u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7aa;
P_0c09f796: /* original f5ac, guest PC 0x0c09f796 */
if(!s->budget--) { s->failed_pc=0x0c09f796u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f798;
P_0c09f798: /* original a007, guest PC 0x0c09f798 */
if(!s->budget--) { s->failed_pc=0x0c09f798u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7aa;
P_0c09f79a: /* original f5dc, guest PC 0x0c09f79a */
if(!s->budget--) { s->failed_pc=0x0c09f79au; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f79c;
P_0c09f79c: /* original f38d, guest PC 0x0c09f79c */
if(!s->budget--) { s->failed_pc=0x0c09f79cu; return 0; }
fr[3]=0;
goto P_0c09f79e;
P_0c09f79e: /* original f355, guest PC 0x0c09f79e */
if(!s->budget--) { s->failed_pc=0x0c09f79eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f7a0;
P_0c09f7a0: /* original 8901, guest PC 0x0c09f7a0 */
if(!s->budget--) { s->failed_pc=0x0c09f7a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7a6; }
goto P_0c09f7a2;
P_0c09f7a2: /* original a002, guest PC 0x0c09f7a2 */
if(!s->budget--) { s->failed_pc=0x0c09f7a2u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7aa;
P_0c09f7a4: /* original f5bc, guest PC 0x0c09f7a4 */
if(!s->budget--) { s->failed_pc=0x0c09f7a4u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7a6;
P_0c09f7a6: /* original c70a, guest PC 0x0c09f7a6 */
if(!s->budget--) { s->failed_pc=0x0c09f7a6u; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f7a8;
P_0c09f7a8: /* original f508, guest PC 0x0c09f7a8 */
if(!s->budget--) { s->failed_pc=0x0c09f7a8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f7aa;
P_0c09f7aa: /* original f36c, guest PC 0x0c09f7aa */
if(!s->budget--) { s->failed_pc=0x0c09f7aau; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09f7ac;
P_0c09f7ac: /* original f65c, guest PC 0x0c09f7ac */
if(!s->budget--) { s->failed_pc=0x0c09f7acu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09f7ae;
P_0c09f7ae: /* original f630, guest PC 0x0c09f7ae */
if(!s->budget--) { s->failed_pc=0x0c09f7aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c09f7b0;
P_0c09f7b0: /* original afe3, guest PC 0x0c09f7b0 */
if(!s->budget--) { s->failed_pc=0x0c09f7b0u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c09f77a;
P_0c09f7b2: /* original f66a, guest PC 0x0c09f7b2 */
if(!s->budget--) { s->failed_pc=0x0c09f7b2u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
if(!vf3_matrix_family(0x0c09f7b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f7b4u; return 0; } return 1;
P_0c09f7d4: /* original f62a, guest PC 0x0c09f7d4 */
if(!s->budget--) { s->failed_pc=0x0c09f7d4u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c09f7d6;
P_0c09f7d6: /* original e008, guest PC 0x0c09f7d6 */
if(!s->budget--) { s->failed_pc=0x0c09f7d6u; return 0; }
r[0]=0x00000008u;
goto P_0c09f7d8;
P_0c09f7d8: /* original f6f6, guest PC 0x0c09f7d8 */
if(!s->budget--) { s->failed_pc=0x0c09f7d8u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f7da;
P_0c09f7da: /* original f641, guest PC 0x0c09f7da */
if(!s->budget--) { s->failed_pc=0x0c09f7dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c09f7dc;
P_0c09f7dc: /* original f56c, guest PC 0x0c09f7dc */
if(!s->budget--) { s->failed_pc=0x0c09f7dcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09f7de;
P_0c09f7de: /* original f55d, guest PC 0x0c09f7de */
if(!s->budget--) { s->failed_pc=0x0c09f7deu; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c09f7e0;
P_0c09f7e0: /* original f755, guest PC 0x0c09f7e0 */
if(!s->budget--) { s->failed_pc=0x0c09f7e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09f7e2;
P_0c09f7e2: /* original 8b16, guest PC 0x0c09f7e2 */
if(!s->budget--) { s->failed_pc=0x0c09f7e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f812; }
goto P_0c09f7e4;
P_0c09f7e4: /* original f855, guest PC 0x0c09f7e4 */
if(!s->budget--) { s->failed_pc=0x0c09f7e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c09f7e6;
P_0c09f7e6: /* original 8b08, guest PC 0x0c09f7e6 */
if(!s->budget--) { s->failed_pc=0x0c09f7e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7fa; }
goto P_0c09f7e8;
P_0c09f7e8: /* original f955, guest PC 0x0c09f7e8 */
if(!s->budget--) { s->failed_pc=0x0c09f7e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c09f7ea;
P_0c09f7ea: /* original 8913, guest PC 0x0c09f7ea */
if(!s->budget--) { s->failed_pc=0x0c09f7eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f814; }
goto P_0c09f7ec;
P_0c09f7ec: /* original f38d, guest PC 0x0c09f7ec */
if(!s->budget--) { s->failed_pc=0x0c09f7ecu; return 0; }
fr[3]=0;
goto P_0c09f7ee;
P_0c09f7ee: /* original f365, guest PC 0x0c09f7ee */
if(!s->budget--) { s->failed_pc=0x0c09f7eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7f0;
P_0c09f7f0: /* original 8901, guest PC 0x0c09f7f0 */
if(!s->budget--) { s->failed_pc=0x0c09f7f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7f6; }
goto P_0c09f7f2;
P_0c09f7f2: /* original a009, guest PC 0x0c09f7f2 */
if(!s->budget--) { s->failed_pc=0x0c09f7f2u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f808;
P_0c09f7f4: /* original f5ac, guest PC 0x0c09f7f4 */
if(!s->budget--) { s->failed_pc=0x0c09f7f4u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7f6;
P_0c09f7f6: /* original a007, guest PC 0x0c09f7f6 */
if(!s->budget--) { s->failed_pc=0x0c09f7f6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f808;
P_0c09f7f8: /* original f5dc, guest PC 0x0c09f7f8 */
if(!s->budget--) { s->failed_pc=0x0c09f7f8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7fa;
P_0c09f7fa: /* original f38d, guest PC 0x0c09f7fa */
if(!s->budget--) { s->failed_pc=0x0c09f7fau; return 0; }
fr[3]=0;
goto P_0c09f7fc;
P_0c09f7fc: /* original f365, guest PC 0x0c09f7fc */
if(!s->budget--) { s->failed_pc=0x0c09f7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7fe;
P_0c09f7fe: /* original 8901, guest PC 0x0c09f7fe */
if(!s->budget--) { s->failed_pc=0x0c09f7feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f804; }
goto P_0c09f800;
P_0c09f800: /* original a002, guest PC 0x0c09f800 */
if(!s->budget--) { s->failed_pc=0x0c09f800u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f808;
P_0c09f802: /* original f5bc, guest PC 0x0c09f802 */
if(!s->budget--) { s->failed_pc=0x0c09f802u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f804;
P_0c09f804: /* original c733, guest PC 0x0c09f804 */
if(!s->budget--) { s->failed_pc=0x0c09f804u; return 0; }
r[0]=code_base|0x0009f8d4u;
goto P_0c09f806;
P_0c09f806: /* original f508, guest PC 0x0c09f806 */
if(!s->budget--) { s->failed_pc=0x0c09f806u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f808;
P_0c09f808: /* original f34c, guest PC 0x0c09f808 */
if(!s->budget--) { s->failed_pc=0x0c09f808u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09f80a;
P_0c09f80a: /* original f45c, guest PC 0x0c09f80a */
if(!s->budget--) { s->failed_pc=0x0c09f80au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09f80c;
P_0c09f80c: /* original f430, guest PC 0x0c09f80c */
if(!s->budget--) { s->failed_pc=0x0c09f80cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c09f80e;
P_0c09f80e: /* original afe2, guest PC 0x0c09f80e */
if(!s->budget--) { s->failed_pc=0x0c09f80eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f7d6;
P_0c09f810: /* original f44a, guest PC 0x0c09f810 */
if(!s->budget--) { s->failed_pc=0x0c09f810u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f812;
P_0c09f812: /* original f42a, guest PC 0x0c09f812 */
if(!s->budget--) { s->failed_pc=0x0c09f812u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09f814;
P_0c09f814: /* original 7f0c, guest PC 0x0c09f814 */
if(!s->budget--) { s->failed_pc=0x0c09f814u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f816;
P_0c09f816: /* original 000b, guest PC 0x0c09f816 */
if(!s->budget--) { s->failed_pc=0x0c09f816u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c09f818: /* original fdf9, guest PC 0x0c09f818 */
if(!s->budget--) { s->failed_pc=0x0c09f818u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c09f81au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f81au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
