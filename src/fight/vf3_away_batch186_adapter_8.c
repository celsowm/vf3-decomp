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
int vf3_away_batch186_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
unsupported: s->failed_pc=target; return 0;
}
