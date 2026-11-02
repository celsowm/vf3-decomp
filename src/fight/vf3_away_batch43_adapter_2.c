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
int vf3_away_batch43_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03b100u: goto P_0c03b100;
case 0x0c03b102u: goto P_0c03b102;
case 0x0c03b104u: goto P_0c03b104;
case 0x0c03b106u: goto P_0c03b106;
case 0x0c03b108u: goto P_0c03b108;
case 0x0c03f5a0u: goto P_0c03f5a0;
case 0x0c03f5a2u: goto P_0c03f5a2;
case 0x0c03f5a4u: goto P_0c03f5a4;
case 0x0c03f5a6u: goto P_0c03f5a6;
case 0x0c03f5a8u: goto P_0c03f5a8;
case 0x0c03f5aau: goto P_0c03f5aa;
case 0x0c03f5acu: goto P_0c03f5ac;
case 0x0c03f5aeu: goto P_0c03f5ae;
case 0x0c03f5b0u: goto P_0c03f5b0;
case 0x0c03f5b2u: goto P_0c03f5b2;
case 0x0c03f5b4u: goto P_0c03f5b4;
case 0x0c03f5b6u: goto P_0c03f5b6;
case 0x0c03f5b8u: goto P_0c03f5b8;
case 0x0c03f5bau: goto P_0c03f5ba;
case 0x0c03f5bcu: goto P_0c03f5bc;
case 0x0c03f5beu: goto P_0c03f5be;
case 0x0c03f5c0u: goto P_0c03f5c0;
case 0x0c03f5c2u: goto P_0c03f5c2;
case 0x0c03f5d0u: goto P_0c03f5d0;
case 0x0c03f5d2u: goto P_0c03f5d2;
case 0x0c03f5d4u: goto P_0c03f5d4;
case 0x0c03f5d6u: goto P_0c03f5d6;
case 0x0c03f5d8u: goto P_0c03f5d8;
case 0x0c03f5dau: goto P_0c03f5da;
case 0x0c03f5dcu: goto P_0c03f5dc;
case 0x0c03f5deu: goto P_0c03f5de;
case 0x0c03f5e0u: goto P_0c03f5e0;
case 0x0c03f5e2u: goto P_0c03f5e2;
case 0x0c03f5e4u: goto P_0c03f5e4;
case 0x0c03f5e6u: goto P_0c03f5e6;
case 0x0c03f5e8u: goto P_0c03f5e8;
case 0x0c03f5eau: goto P_0c03f5ea;
case 0x0c03f5ecu: goto P_0c03f5ec;
case 0x0c03f5eeu: goto P_0c03f5ee;
case 0x0c03f5f0u: goto P_0c03f5f0;
case 0x0c03f5f2u: goto P_0c03f5f2;
case 0x0c03f5f4u: goto P_0c03f5f4;
case 0x0c03f5f6u: goto P_0c03f5f6;
case 0x0c03f5f8u: goto P_0c03f5f8;
case 0x0c03f5fau: goto P_0c03f5fa;
case 0x0c03f5fcu: goto P_0c03f5fc;
case 0x0c03f5feu: goto P_0c03f5fe;
case 0x0c03f600u: goto P_0c03f600;
case 0x0c03f602u: goto P_0c03f602;
case 0x0c03f604u: goto P_0c03f604;
case 0x0c03f606u: goto P_0c03f606;
case 0x0c03f608u: goto P_0c03f608;
case 0x0c03f60au: goto P_0c03f60a;
case 0x0c03f60cu: goto P_0c03f60c;
case 0x0c03f60eu: goto P_0c03f60e;
case 0x0c03f610u: goto P_0c03f610;
case 0x0c03f612u: goto P_0c03f612;
case 0x0c03f614u: goto P_0c03f614;
case 0x0c03f616u: goto P_0c03f616;
case 0x0c03f618u: goto P_0c03f618;
case 0x0c03f61au: goto P_0c03f61a;
case 0x0c03f61cu: goto P_0c03f61c;
case 0x0c03f61eu: goto P_0c03f61e;
case 0x0c03f620u: goto P_0c03f620;
case 0x0c03f622u: goto P_0c03f622;
case 0x0c03f624u: goto P_0c03f624;
case 0x0c03f626u: goto P_0c03f626;
case 0x0c03f628u: goto P_0c03f628;
case 0x0c03f62au: goto P_0c03f62a;
case 0x0c03f62cu: goto P_0c03f62c;
case 0x0c03f62eu: goto P_0c03f62e;
case 0x0c03f630u: goto P_0c03f630;
case 0x0c03f632u: goto P_0c03f632;
case 0x0c03f634u: goto P_0c03f634;
case 0x0c03f636u: goto P_0c03f636;
case 0x0c03f638u: goto P_0c03f638;
case 0x0c03f63au: goto P_0c03f63a;
case 0x0c03f63cu: goto P_0c03f63c;
case 0x0c03f63eu: goto P_0c03f63e;
case 0x0c03f640u: goto P_0c03f640;
case 0x0c03f642u: goto P_0c03f642;
case 0x0c03f644u: goto P_0c03f644;
case 0x0c03f646u: goto P_0c03f646;
case 0x0c03f648u: goto P_0c03f648;
case 0x0c03f64au: goto P_0c03f64a;
case 0x0c03f64cu: goto P_0c03f64c;
case 0x0c03f64eu: goto P_0c03f64e;
case 0x0c03f650u: goto P_0c03f650;
case 0x0c03f652u: goto P_0c03f652;
case 0x0c03f654u: goto P_0c03f654;
case 0x0c03f656u: goto P_0c03f656;
case 0x0c03f658u: goto P_0c03f658;
case 0x0c03f65au: goto P_0c03f65a;
case 0x0c03f65cu: goto P_0c03f65c;
case 0x0c03f65eu: goto P_0c03f65e;
case 0x0c03f660u: goto P_0c03f660;
case 0x0c03f662u: goto P_0c03f662;
case 0x0c03f664u: goto P_0c03f664;
case 0x0c03f666u: goto P_0c03f666;
case 0x0c03f668u: goto P_0c03f668;
case 0x0c03f66au: goto P_0c03f66a;
case 0x0c03f66cu: goto P_0c03f66c;
case 0x0c03f66eu: goto P_0c03f66e;
case 0x0c03f670u: goto P_0c03f670;
case 0x0c03f672u: goto P_0c03f672;
case 0x0c03f674u: goto P_0c03f674;
case 0x0c03f676u: goto P_0c03f676;
case 0x0c03f678u: goto P_0c03f678;
case 0x0c03f67au: goto P_0c03f67a;
case 0x0c03f67cu: goto P_0c03f67c;
case 0x0c03f67eu: goto P_0c03f67e;
case 0x0c03f680u: goto P_0c03f680;
case 0x0c03f682u: goto P_0c03f682;
case 0x0c03f684u: goto P_0c03f684;
case 0x0c03f690u: goto P_0c03f690;
case 0x0c03f692u: goto P_0c03f692;
case 0x0c03f694u: goto P_0c03f694;
case 0x0c03f696u: goto P_0c03f696;
case 0x0c03f698u: goto P_0c03f698;
case 0x0c03f69au: goto P_0c03f69a;
case 0x0c03f69cu: goto P_0c03f69c;
case 0x0c03f69eu: goto P_0c03f69e;
case 0x0c03f6a0u: goto P_0c03f6a0;
case 0x0c03f6a2u: goto P_0c03f6a2;
case 0x0c03f6a4u: goto P_0c03f6a4;
case 0x0c03f6a6u: goto P_0c03f6a6;
case 0x0c03f6a8u: goto P_0c03f6a8;
case 0x0c03f6aau: goto P_0c03f6aa;
case 0x0c03f6acu: goto P_0c03f6ac;
case 0x0c03f6aeu: goto P_0c03f6ae;
case 0x0c03f6b0u: goto P_0c03f6b0;
case 0x0c03f6b2u: goto P_0c03f6b2;
case 0x0c03f6b4u: goto P_0c03f6b4;
case 0x0c03f6b6u: goto P_0c03f6b6;
case 0x0c03f6b8u: goto P_0c03f6b8;
case 0x0c03f6c0u: goto P_0c03f6c0;
case 0x0c03f6c2u: goto P_0c03f6c2;
case 0x0c03f6c4u: goto P_0c03f6c4;
case 0x0c03f6c6u: goto P_0c03f6c6;
case 0x0c03f6c8u: goto P_0c03f6c8;
case 0x0c03f6cau: goto P_0c03f6ca;
case 0x0c03f6ccu: goto P_0c03f6cc;
case 0x0c03f6ceu: goto P_0c03f6ce;
case 0x0c03f6d0u: goto P_0c03f6d0;
case 0x0c03f6d2u: goto P_0c03f6d2;
case 0x0c03f6d4u: goto P_0c03f6d4;
case 0x0c03f6d6u: goto P_0c03f6d6;
case 0x0c03f6d8u: goto P_0c03f6d8;
case 0x0c03f6dau: goto P_0c03f6da;
case 0x0c03f6dcu: goto P_0c03f6dc;
case 0x0c03f6deu: goto P_0c03f6de;
case 0x0c03f6e0u: goto P_0c03f6e0;
case 0x0c03f6e2u: goto P_0c03f6e2;
case 0x0c03f6e4u: goto P_0c03f6e4;
case 0x0c03f6e6u: goto P_0c03f6e6;
case 0x0c03f6e8u: goto P_0c03f6e8;
case 0x0c03f6eau: goto P_0c03f6ea;
case 0x0c03f6ecu: goto P_0c03f6ec;
case 0x0c03f6eeu: goto P_0c03f6ee;
case 0x0c03f6f0u: goto P_0c03f6f0;
case 0x0c03f6f2u: goto P_0c03f6f2;
case 0x0c03f6f4u: goto P_0c03f6f4;
case 0x0c03f6f6u: goto P_0c03f6f6;
case 0x0c03f6f8u: goto P_0c03f6f8;
case 0x0c03f6fau: goto P_0c03f6fa;
case 0x0c03f6fcu: goto P_0c03f6fc;
case 0x0c03f6feu: goto P_0c03f6fe;
case 0x0c03f700u: goto P_0c03f700;
case 0x0c03f702u: goto P_0c03f702;
case 0x0c03f704u: goto P_0c03f704;
case 0x0c03f706u: goto P_0c03f706;
case 0x0c03f708u: goto P_0c03f708;
case 0x0c03f70au: goto P_0c03f70a;
case 0x0c03f70cu: goto P_0c03f70c;
case 0x0c03f70eu: goto P_0c03f70e;
case 0x0c03f710u: goto P_0c03f710;
case 0x0c03f712u: goto P_0c03f712;
case 0x0c03f714u: goto P_0c03f714;
case 0x0c03f716u: goto P_0c03f716;
case 0x0c03f718u: goto P_0c03f718;
case 0x0c03f71au: goto P_0c03f71a;
case 0x0c03f71cu: goto P_0c03f71c;
case 0x0c03f71eu: goto P_0c03f71e;
case 0x0c03f720u: goto P_0c03f720;
case 0x0c03f722u: goto P_0c03f722;
case 0x0c03f724u: goto P_0c03f724;
case 0x0c03f726u: goto P_0c03f726;
case 0x0c03f728u: goto P_0c03f728;
case 0x0c03f72au: goto P_0c03f72a;
case 0x0c03f72cu: goto P_0c03f72c;
case 0x0c03f72eu: goto P_0c03f72e;
case 0x0c03f730u: goto P_0c03f730;
case 0x0c03f732u: goto P_0c03f732;
case 0x0c03f734u: goto P_0c03f734;
case 0x0c03f736u: goto P_0c03f736;
case 0x0c03f738u: goto P_0c03f738;
case 0x0c03f73au: goto P_0c03f73a;
case 0x0c03f73cu: goto P_0c03f73c;
case 0x0c03f73eu: goto P_0c03f73e;
case 0x0c03f740u: goto P_0c03f740;
case 0x0c03f742u: goto P_0c03f742;
case 0x0c03f744u: goto P_0c03f744;
case 0x0c03f746u: goto P_0c03f746;
case 0x0c03f748u: goto P_0c03f748;
case 0x0c03f74au: goto P_0c03f74a;
case 0x0c03f74cu: goto P_0c03f74c;
case 0x0c03f74eu: goto P_0c03f74e;
case 0x0c03f750u: goto P_0c03f750;
case 0x0c03f752u: goto P_0c03f752;
case 0x0c03f754u: goto P_0c03f754;
case 0x0c03f756u: goto P_0c03f756;
case 0x0c03f758u: goto P_0c03f758;
case 0x0c03f75au: goto P_0c03f75a;
case 0x0c03f75cu: goto P_0c03f75c;
case 0x0c03f75eu: goto P_0c03f75e;
case 0x0c03f760u: goto P_0c03f760;
case 0x0c03f762u: goto P_0c03f762;
case 0x0c03f764u: goto P_0c03f764;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c03b100: /* original d163, guest PC 0x0c03b100 */
if(!s->budget--) { s->failed_pc=0x0c03b100u; return 0; }
r[1]=read(ram,0x0c03b290u,4);
goto P_0c03b102;
P_0c03b102: /* original 2142, guest PC 0x0c03b102 */
if(!s->budget--) { s->failed_pc=0x0c03b102u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c03b104;
P_0c03b104: /* original d363, guest PC 0x0c03b104 */
if(!s->budget--) { s->failed_pc=0x0c03b104u; return 0; }
r[3]=read(ram,0x0c03b294u,4);
goto P_0c03b106;
P_0c03b106: /* original 000b, guest PC 0x0c03b106 */
if(!s->budget--) { s->failed_pc=0x0c03b106u; return 0; }
target=r[16];
write(ram,r[3],r[5],4);
s->pc=target; return ram->oob==0;
P_0c03b108: /* original 2352, guest PC 0x0c03b108 */
if(!s->budget--) { s->failed_pc=0x0c03b108u; return 0; }
write(ram,r[3],r[5],4);
if(!vf3_matrix_family(0x0c03b10au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b10au; return 0; } return 1;
P_0c03f5a0: /* original 2fe6, guest PC 0x0c03f5a0 */
if(!s->budget--) { s->failed_pc=0x0c03f5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a2;
P_0c03f5a2: /* original e300, guest PC 0x0c03f5a2 */
if(!s->budget--) { s->failed_pc=0x0c03f5a2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f5a4;
P_0c03f5a4: /* original 2fd6, guest PC 0x0c03f5a4 */
if(!s->budget--) { s->failed_pc=0x0c03f5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a6;
P_0c03f5a6: /* original 2fc6, guest PC 0x0c03f5a6 */
if(!s->budget--) { s->failed_pc=0x0c03f5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a8;
P_0c03f5a8: /* original 6c43, guest PC 0x0c03f5a8 */
if(!s->budget--) { s->failed_pc=0x0c03f5a8u; return 0; }
r[12]=r[4];
goto P_0c03f5aa;
P_0c03f5aa: /* original 2fb6, guest PC 0x0c03f5aa */
if(!s->budget--) { s->failed_pc=0x0c03f5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ac;
P_0c03f5ac: /* original 2fa6, guest PC 0x0c03f5ac */
if(!s->budget--) { s->failed_pc=0x0c03f5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ae;
P_0c03f5ae: /* original 2f96, guest PC 0x0c03f5ae */
if(!s->budget--) { s->failed_pc=0x0c03f5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b0;
P_0c03f5b0: /* original 2f86, guest PC 0x0c03f5b0 */
if(!s->budget--) { s->failed_pc=0x0c03f5b0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b2;
P_0c03f5b2: /* original 4f22, guest PC 0x0c03f5b2 */
if(!s->budget--) { s->failed_pc=0x0c03f5b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f5b4;
P_0c03f5b4: /* original 4f12, guest PC 0x0c03f5b4 */
if(!s->budget--) { s->failed_pc=0x0c03f5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f5b6;
P_0c03f5b6: /* original 7ffc, guest PC 0x0c03f5b6 */
if(!s->budget--) { s->failed_pc=0x0c03f5b6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f5b8;
P_0c03f5b8: /* original 2f32, guest PC 0x0c03f5b8 */
if(!s->budget--) { s->failed_pc=0x0c03f5b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f5ba;
P_0c03f5ba: /* original d37a, guest PC 0x0c03f5ba */
if(!s->budget--) { s->failed_pc=0x0c03f5bau; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f5bc;
P_0c03f5bc: /* original de78, guest PC 0x0c03f5bc */
if(!s->budget--) { s->failed_pc=0x0c03f5bcu; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f5be;
P_0c03f5be: /* original d974, guest PC 0x0c03f5be */
if(!s->budget--) { s->failed_pc=0x0c03f5beu; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f5c0;
P_0c03f5c0: /* original a052, guest PC 0x0c03f5c0 */
if(!s->budget--) { s->failed_pc=0x0c03f5c0u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03f668;
P_0c03f5c2: /* original 6b32, guest PC 0x0c03f5c2 */
if(!s->budget--) { s->failed_pc=0x0c03f5c2u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
if(!vf3_matrix_family(0x0c03f5c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f5c4u; return 0; } return 1;
P_0c03f5d0: /* original 6db3, guest PC 0x0c03f5d0 */
if(!s->budget--) { s->failed_pc=0x0c03f5d0u; return 0; }
r[13]=r[11];
goto P_0c03f5d2;
P_0c03f5d2: /* original 63e2, guest PC 0x0c03f5d2 */
if(!s->budget--) { s->failed_pc=0x0c03f5d2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f5d4;
P_0c03f5d4: /* original 4d08, guest PC 0x0c03f5d4 */
if(!s->budget--) { s->failed_pc=0x0c03f5d4u; return 0; }
r[13]<<=2;
goto P_0c03f5d6;
P_0c03f5d6: /* original 4d00, guest PC 0x0c03f5d6 */
if(!s->budget--) { s->failed_pc=0x0c03f5d6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f5d8;
P_0c03f5d8: /* original 33dc, guest PC 0x0c03f5d8 */
if(!s->budget--) { s->failed_pc=0x0c03f5d8u; return 0; }
r[3]+=r[13];
goto P_0c03f5da;
P_0c03f5da: /* original 6232, guest PC 0x0c03f5da */
if(!s->budget--) { s->failed_pc=0x0c03f5dau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f5dc;
P_0c03f5dc: /* original 2228, guest PC 0x0c03f5dc */
if(!s->budget--) { s->failed_pc=0x0c03f5dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f5de;
P_0c03f5de: /* original 8f09, guest PC 0x0c03f5de */
if(!s->budget--) { s->failed_pc=0x0c03f5deu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c03f5f4; }
goto P_0c03f5e2;
P_0c03f5e0: /* original 64b3, guest PC 0x0c03f5e0 */
if(!s->budget--) { s->failed_pc=0x0c03f5e0u; return 0; }
r[4]=r[11];
goto P_0c03f5e2;
P_0c03f5e2: /* original 62e2, guest PC 0x0c03f5e2 */
if(!s->budget--) { s->failed_pc=0x0c03f5e2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5e4;
P_0c03f5e4: /* original e104, guest PC 0x0c03f5e4 */
if(!s->budget--) { s->failed_pc=0x0c03f5e4u; return 0; }
r[1]=0x00000004u;
goto P_0c03f5e6;
P_0c03f5e6: /* original d370, guest PC 0x0c03f5e6 */
if(!s->budget--) { s->failed_pc=0x0c03f5e6u; return 0; }
r[3]=read(ram,0x0c03f7a8u,4);
goto P_0c03f5e8;
P_0c03f5e8: /* original 32dc, guest PC 0x0c03f5e8 */
if(!s->budget--) { s->failed_pc=0x0c03f5e8u; return 0; }
r[2]+=r[13];
goto P_0c03f5ea;
P_0c03f5ea: /* original 312c, guest PC 0x0c03f5ea */
if(!s->budget--) { s->failed_pc=0x0c03f5eau; return 0; }
r[1]+=r[2];
goto P_0c03f5ec;
P_0c03f5ec: /* original 430b, guest PC 0x0c03f5ec */
if(!s->budget--) { s->failed_pc=0x0c03f5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f5f0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f5f0u) { target=s->pc; goto dispatch; }
goto P_0c03f5f0;
P_0c03f5ee: /* original 2f16, guest PC 0x0c03f5ee */
if(!s->budget--) { s->failed_pc=0x0c03f5eeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5f0;
P_0c03f5f0: /* original 63f6, guest PC 0x0c03f5f0 */
if(!s->budget--) { s->failed_pc=0x0c03f5f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c03f5f2;
P_0c03f5f2: /* original 2302, guest PC 0x0c03f5f2 */
if(!s->budget--) { s->failed_pc=0x0c03f5f2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c03f5f4;
P_0c03f5f4: /* original 62e2, guest PC 0x0c03f5f4 */
if(!s->budget--) { s->failed_pc=0x0c03f5f4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5f6;
P_0c03f5f6: /* original ea3c, guest PC 0x0c03f5f6 */
if(!s->budget--) { s->failed_pc=0x0c03f5f6u; return 0; }
r[10]=0x0000003cu;
goto P_0c03f5f8;
P_0c03f5f8: /* original 68b3, guest PC 0x0c03f5f8 */
if(!s->budget--) { s->failed_pc=0x0c03f5f8u; return 0; }
r[8]=r[11];
goto P_0c03f5fa;
P_0c03f5fa: /* original 4800, guest PC 0x0c03f5fa */
if(!s->budget--) { s->failed_pc=0x0c03f5fau; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c03f5fc;
P_0c03f5fc: /* original 32dc, guest PC 0x0c03f5fc */
if(!s->budget--) { s->failed_pc=0x0c03f5fcu; return 0; }
r[2]+=r[13];
goto P_0c03f5fe;
P_0c03f5fe: /* original 6322, guest PC 0x0c03f5fe */
if(!s->budget--) { s->failed_pc=0x0c03f5feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f600;
P_0c03f600: /* original 7301, guest PC 0x0c03f600 */
if(!s->budget--) { s->failed_pc=0x0c03f600u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f602;
P_0c03f602: /* original 2232, guest PC 0x0c03f602 */
if(!s->budget--) { s->failed_pc=0x0c03f602u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03f604;
P_0c03f604: /* original 62e2, guest PC 0x0c03f604 */
if(!s->budget--) { s->failed_pc=0x0c03f604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f606;
P_0c03f606: /* original 6192, guest PC 0x0c03f606 */
if(!s->budget--) { s->failed_pc=0x0c03f606u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f608;
P_0c03f608: /* original 32dc, guest PC 0x0c03f608 */
if(!s->budget--) { s->failed_pc=0x0c03f608u; return 0; }
r[2]+=r[13];
goto P_0c03f60a;
P_0c03f60a: /* original 5d21, guest PC 0x0c03f60a */
if(!s->budget--) { s->failed_pc=0x0c03f60au; return 0; }
r[13]=read(ram,r[2]+4,4);
goto P_0c03f60c;
P_0c03f60c: /* original 381c, guest PC 0x0c03f60c */
if(!s->budget--) { s->failed_pc=0x0c03f60cu; return 0; }
r[8]+=r[1];
goto P_0c03f60e;
P_0c03f60e: /* original d267, guest PC 0x0c03f60e */
if(!s->budget--) { s->failed_pc=0x0c03f60eu; return 0; }
r[2]=read(ram,0x0c03f7acu,4);
goto P_0c03f610;
P_0c03f610: /* original 0da7, guest PC 0x0c03f610 */
if(!s->budget--) { s->failed_pc=0x0c03f610u; return 0; }
r[19]=r[13]*r[10];
goto P_0c03f612;
P_0c03f612: /* original 6081, guest PC 0x0c03f612 */
if(!s->budget--) { s->failed_pc=0x0c03f612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c03f614;
P_0c03f614: /* original 6322, guest PC 0x0c03f614 */
if(!s->budget--) { s->failed_pc=0x0c03f614u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f616;
P_0c03f616: /* original 88ff, guest PC 0x0c03f616 */
if(!s->budget--) { s->failed_pc=0x0c03f616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f618;
P_0c03f618: /* original 0a1a, guest PC 0x0c03f618 */
if(!s->budget--) { s->failed_pc=0x0c03f618u; return 0; }
r[10]=r[19];
goto P_0c03f61a;
P_0c03f61a: /* original 8f03, guest PC 0x0c03f61a */
if(!s->budget--) { s->failed_pc=0x0c03f61au; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c03f624; }
goto P_0c03f61e;
P_0c03f61c: /* original 3a3c, guest PC 0x0c03f61c */
if(!s->budget--) { s->failed_pc=0x0c03f61cu; return 0; }
r[10]+=r[3];
goto P_0c03f61e;
P_0c03f61e: /* original b367, guest PC 0x0c03f61e */
if(!s->budget--) { s->failed_pc=0x0c03f61eu; return 0; }
target=code_base|0x0c03fcf0u; r[16]=code_base|0x0c03f622u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f622u) { target=s->pc; goto dispatch; }
goto P_0c03f622;
P_0c03f620: /* original 0009, guest PC 0x0c03f620 */
if(!s->budget--) { s->failed_pc=0x0c03f620u; return 0; }
goto P_0c03f622;
P_0c03f622: /* original 2801, guest PC 0x0c03f622 */
if(!s->budget--) { s->failed_pc=0x0c03f622u; return 0; }
write(ram,r[8],r[0],2);
goto P_0c03f624;
P_0c03f624: /* original 60b3, guest PC 0x0c03f624 */
if(!s->budget--) { s->failed_pc=0x0c03f624u; return 0; }
r[0]=r[11];
goto P_0c03f626;
P_0c03f626: /* original 0009, guest PC 0x0c03f626 */
if(!s->budget--) { s->failed_pc=0x0c03f626u; return 0; }
goto P_0c03f628;
P_0c03f628: /* original 6392, guest PC 0x0c03f628 */
if(!s->budget--) { s->failed_pc=0x0c03f628u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f62a;
P_0c03f62a: /* original 4000, guest PC 0x0c03f62a */
if(!s->budget--) { s->failed_pc=0x0c03f62au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f62c;
P_0c03f62c: /* original 083d, guest PC 0x0c03f62c */
if(!s->budget--) { s->failed_pc=0x0c03f62cu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f62e;
P_0c03f62e: /* original 53ab, guest PC 0x0c03f62e */
if(!s->budget--) { s->failed_pc=0x0c03f62eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f630;
P_0c03f630: /* original 2338, guest PC 0x0c03f630 */
if(!s->budget--) { s->failed_pc=0x0c03f630u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f632;
P_0c03f632: /* original 8b0b, guest PC 0x0c03f632 */
if(!s->budget--) { s->failed_pc=0x0c03f632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f64c; }
goto P_0c03f634;
P_0c03f634: /* original d35e, guest PC 0x0c03f634 */
if(!s->budget--) { s->failed_pc=0x0c03f634u; return 0; }
r[3]=read(ram,0x0c03f7b0u,4);
goto P_0c03f636;
P_0c03f636: /* original 65d3, guest PC 0x0c03f636 */
if(!s->budget--) { s->failed_pc=0x0c03f636u; return 0; }
r[5]=r[13];
goto P_0c03f638;
P_0c03f638: /* original 56c2, guest PC 0x0c03f638 */
if(!s->budget--) { s->failed_pc=0x0c03f638u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c03f63a;
P_0c03f63a: /* original 430b, guest PC 0x0c03f63a */
if(!s->budget--) { s->failed_pc=0x0c03f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c03f63eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f63eu) { target=s->pc; goto dispatch; }
goto P_0c03f63e;
P_0c03f63c: /* original 64c3, guest PC 0x0c03f63c */
if(!s->budget--) { s->failed_pc=0x0c03f63cu; return 0; }
r[4]=r[12];
goto P_0c03f63e;
P_0c03f63e: /* original 62f2, guest PC 0x0c03f63e */
if(!s->budget--) { s->failed_pc=0x0c03f63eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03f640;
P_0c03f640: /* original 220b, guest PC 0x0c03f640 */
if(!s->budget--) { s->failed_pc=0x0c03f640u; return 0; }
r[2]|=r[0];
goto P_0c03f642;
P_0c03f642: /* original 2f22, guest PC 0x0c03f642 */
if(!s->budget--) { s->failed_pc=0x0c03f642u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f644;
P_0c03f644: /* original d35b, guest PC 0x0c03f644 */
if(!s->budget--) { s->failed_pc=0x0c03f644u; return 0; }
r[3]=read(ram,0x0c03f7b4u,4);
goto P_0c03f646;
P_0c03f646: /* original 430b, guest PC 0x0c03f646 */
if(!s->budget--) { s->failed_pc=0x0c03f646u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f64au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f64au) { target=s->pc; goto dispatch; }
goto P_0c03f64a;
P_0c03f648: /* original 64d3, guest PC 0x0c03f648 */
if(!s->budget--) { s->failed_pc=0x0c03f648u; return 0; }
r[4]=r[13];
goto P_0c03f64a;
P_0c03f64a: /* original 1ade, guest PC 0x0c03f64a */
if(!s->budget--) { s->failed_pc=0x0c03f64au; return 0; }
write(ram,r[10]+56,r[13],4);
goto P_0c03f64c;
P_0c03f64c: /* original d253, guest PC 0x0c03f64c */
if(!s->budget--) { s->failed_pc=0x0c03f64cu; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f64e;
P_0c03f64e: /* original 6483, guest PC 0x0c03f64e */
if(!s->budget--) { s->failed_pc=0x0c03f64eu; return 0; }
r[4]=r[8];
goto P_0c03f650;
P_0c03f650: /* original 4408, guest PC 0x0c03f650 */
if(!s->budget--) { s->failed_pc=0x0c03f650u; return 0; }
r[4]<<=2;
goto P_0c03f652;
P_0c03f652: /* original 65d3, guest PC 0x0c03f652 */
if(!s->budget--) { s->failed_pc=0x0c03f652u; return 0; }
r[5]=r[13];
goto P_0c03f654;
P_0c03f654: /* original 6322, guest PC 0x0c03f654 */
if(!s->budget--) { s->failed_pc=0x0c03f654u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f656;
P_0c03f656: /* original 4408, guest PC 0x0c03f656 */
if(!s->budget--) { s->failed_pc=0x0c03f656u; return 0; }
r[4]<<=2;
goto P_0c03f658;
P_0c03f658: /* original 4400, guest PC 0x0c03f658 */
if(!s->budget--) { s->failed_pc=0x0c03f658u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f65a;
P_0c03f65a: /* original b319, guest PC 0x0c03f65a */
if(!s->budget--) { s->failed_pc=0x0c03f65au; return 0; }
target=code_base|0x0c03fc90u; r[16]=code_base|0x0c03f65eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f65eu) { target=s->pc; goto dispatch; }
goto P_0c03f65e;
P_0c03f65c: /* original 343c, guest PC 0x0c03f65c */
if(!s->budget--) { s->failed_pc=0x0c03f65cu; return 0; }
r[4]+=r[3];
goto P_0c03f65e;
P_0c03f65e: /* original 53ab, guest PC 0x0c03f65e */
if(!s->budget--) { s->failed_pc=0x0c03f65eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f660;
P_0c03f660: /* original 7b01, guest PC 0x0c03f660 */
if(!s->budget--) { s->failed_pc=0x0c03f660u; return 0; }
r[11]+=0x00000001u;
goto P_0c03f662;
P_0c03f662: /* original 7c10, guest PC 0x0c03f662 */
if(!s->budget--) { s->failed_pc=0x0c03f662u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f664;
P_0c03f664: /* original 7301, guest PC 0x0c03f664 */
if(!s->budget--) { s->failed_pc=0x0c03f664u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f666;
P_0c03f666: /* original 1a3b, guest PC 0x0c03f666 */
if(!s->budget--) { s->failed_pc=0x0c03f666u; return 0; }
write(ram,r[10]+44,r[3],4);
goto P_0c03f668;
P_0c03f668: /* original 50c1, guest PC 0x0c03f668 */
if(!s->budget--) { s->failed_pc=0x0c03f668u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f66a;
P_0c03f66a: /* original 88ff, guest PC 0x0c03f66a */
if(!s->budget--) { s->failed_pc=0x0c03f66au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f66c;
P_0c03f66c: /* original 8bb0, guest PC 0x0c03f66c */
if(!s->budget--) { s->failed_pc=0x0c03f66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f5d0; }
goto P_0c03f66e;
P_0c03f66e: /* original 60f2, guest PC 0x0c03f66e */
if(!s->budget--) { s->failed_pc=0x0c03f66eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f670;
P_0c03f670: /* original 7f04, guest PC 0x0c03f670 */
if(!s->budget--) { s->failed_pc=0x0c03f670u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f672;
P_0c03f672: /* original 4f16, guest PC 0x0c03f672 */
if(!s->budget--) { s->failed_pc=0x0c03f672u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f674;
P_0c03f674: /* original 4f26, guest PC 0x0c03f674 */
if(!s->budget--) { s->failed_pc=0x0c03f674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f676;
P_0c03f676: /* original 68f6, guest PC 0x0c03f676 */
if(!s->budget--) { s->failed_pc=0x0c03f676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f678;
P_0c03f678: /* original 69f6, guest PC 0x0c03f678 */
if(!s->budget--) { s->failed_pc=0x0c03f678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f67a;
P_0c03f67a: /* original 6af6, guest PC 0x0c03f67a */
if(!s->budget--) { s->failed_pc=0x0c03f67au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f67c;
P_0c03f67c: /* original 6bf6, guest PC 0x0c03f67c */
if(!s->budget--) { s->failed_pc=0x0c03f67cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f67e;
P_0c03f67e: /* original 6cf6, guest PC 0x0c03f67e */
if(!s->budget--) { s->failed_pc=0x0c03f67eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f680;
P_0c03f680: /* original 6df6, guest PC 0x0c03f680 */
if(!s->budget--) { s->failed_pc=0x0c03f680u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f682;
P_0c03f682: /* original 000b, guest PC 0x0c03f682 */
if(!s->budget--) { s->failed_pc=0x0c03f682u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f684: /* original 6ef6, guest PC 0x0c03f684 */
if(!s->budget--) { s->failed_pc=0x0c03f684u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f686u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f686u; return 0; } return 1;
P_0c03f690: /* original 2fe6, guest PC 0x0c03f690 */
if(!s->budget--) { s->failed_pc=0x0c03f690u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f692;
P_0c03f692: /* original e300, guest PC 0x0c03f692 */
if(!s->budget--) { s->failed_pc=0x0c03f692u; return 0; }
r[3]=0x00000000u;
goto P_0c03f694;
P_0c03f694: /* original 2fd6, guest PC 0x0c03f694 */
if(!s->budget--) { s->failed_pc=0x0c03f694u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f696;
P_0c03f696: /* original edff, guest PC 0x0c03f696 */
if(!s->budget--) { s->failed_pc=0x0c03f696u; return 0; }
r[13]=0xffffffffu;
goto P_0c03f698;
P_0c03f698: /* original 2fc6, guest PC 0x0c03f698 */
if(!s->budget--) { s->failed_pc=0x0c03f698u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69a;
P_0c03f69a: /* original 2fb6, guest PC 0x0c03f69a */
if(!s->budget--) { s->failed_pc=0x0c03f69au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69c;
P_0c03f69c: /* original 2fa6, guest PC 0x0c03f69c */
if(!s->budget--) { s->failed_pc=0x0c03f69cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f69e;
P_0c03f69e: /* original 2f96, guest PC 0x0c03f69e */
if(!s->budget--) { s->failed_pc=0x0c03f69eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a0;
P_0c03f6a0: /* original 2f86, guest PC 0x0c03f6a0 */
if(!s->budget--) { s->failed_pc=0x0c03f6a0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f6a2;
P_0c03f6a2: /* original 4f22, guest PC 0x0c03f6a2 */
if(!s->budget--) { s->failed_pc=0x0c03f6a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f6a4;
P_0c03f6a4: /* original 4f12, guest PC 0x0c03f6a4 */
if(!s->budget--) { s->failed_pc=0x0c03f6a4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f6a6;
P_0c03f6a6: /* original 7ff0, guest PC 0x0c03f6a6 */
if(!s->budget--) { s->failed_pc=0x0c03f6a6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f6a8;
P_0c03f6a8: /* original 1f33, guest PC 0x0c03f6a8 */
if(!s->budget--) { s->failed_pc=0x0c03f6a8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c03f6aa;
P_0c03f6aa: /* original de3d, guest PC 0x0c03f6aa */
if(!s->budget--) { s->failed_pc=0x0c03f6aau; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f6ac;
P_0c03f6ac: /* original d838, guest PC 0x0c03f6ac */
if(!s->budget--) { s->failed_pc=0x0c03f6acu; return 0; }
r[8]=read(ram,0x0c03f790u,4);
goto P_0c03f6ae;
P_0c03f6ae: /* original dc3f, guest PC 0x0c03f6ae */
if(!s->budget--) { s->failed_pc=0x0c03f6aeu; return 0; }
r[12]=read(ram,0x0c03f7acu,4);
goto P_0c03f6b0;
P_0c03f6b0: /* original 2f42, guest PC 0x0c03f6b0 */
if(!s->budget--) { s->failed_pc=0x0c03f6b0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03f6b2;
P_0c03f6b2: /* original d23c, guest PC 0x0c03f6b2 */
if(!s->budget--) { s->failed_pc=0x0c03f6b2u; return 0; }
r[2]=read(ram,0x0c03f7a4u,4);
goto P_0c03f6b4;
P_0c03f6b4: /* original 6322, guest PC 0x0c03f6b4 */
if(!s->budget--) { s->failed_pc=0x0c03f6b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f6b6;
P_0c03f6b6: /* original a046, guest PC 0x0c03f6b6 */
if(!s->budget--) { s->failed_pc=0x0c03f6b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f746;
P_0c03f6b8: /* original 1f31, guest PC 0x0c03f6b8 */
if(!s->budget--) { s->failed_pc=0x0c03f6b8u; return 0; }
write(ram,r[15]+4,r[3],4);
if(!vf3_matrix_family(0x0c03f6bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f6bau; return 0; } return 1;
P_0c03f6c0: /* original 59f1, guest PC 0x0c03f6c0 */
if(!s->budget--) { s->failed_pc=0x0c03f6c0u; return 0; }
r[9]=read(ram,r[15]+4,4);
goto P_0c03f6c2;
P_0c03f6c2: /* original e200, guest PC 0x0c03f6c2 */
if(!s->budget--) { s->failed_pc=0x0c03f6c2u; return 0; }
r[2]=0x00000000u;
goto P_0c03f6c4;
P_0c03f6c4: /* original 63e2, guest PC 0x0c03f6c4 */
if(!s->budget--) { s->failed_pc=0x0c03f6c4u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6c6;
P_0c03f6c6: /* original 6b93, guest PC 0x0c03f6c6 */
if(!s->budget--) { s->failed_pc=0x0c03f6c6u; return 0; }
r[11]=r[9];
goto P_0c03f6c8;
P_0c03f6c8: /* original 4b08, guest PC 0x0c03f6c8 */
if(!s->budget--) { s->failed_pc=0x0c03f6c8u; return 0; }
r[11]<<=2;
goto P_0c03f6ca;
P_0c03f6ca: /* original 4b00, guest PC 0x0c03f6ca */
if(!s->budget--) { s->failed_pc=0x0c03f6cau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c03f6cc;
P_0c03f6cc: /* original 33bc, guest PC 0x0c03f6cc */
if(!s->budget--) { s->failed_pc=0x0c03f6ccu; return 0; }
r[3]+=r[11];
goto P_0c03f6ce;
P_0c03f6ce: /* original 6132, guest PC 0x0c03f6ce */
if(!s->budget--) { s->failed_pc=0x0c03f6ceu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c03f6d0;
P_0c03f6d0: /* original 3126, guest PC 0x0c03f6d0 */
if(!s->budget--) { s->failed_pc=0x0c03f6d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c03f6d2;
P_0c03f6d2: /* original 8b32, guest PC 0x0c03f6d2 */
if(!s->budget--) { s->failed_pc=0x0c03f6d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6d4;
P_0c03f6d4: /* original 60e2, guest PC 0x0c03f6d4 */
if(!s->budget--) { s->failed_pc=0x0c03f6d4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c03f6d6;
P_0c03f6d6: /* original 30bc, guest PC 0x0c03f6d6 */
if(!s->budget--) { s->failed_pc=0x0c03f6d6u; return 0; }
r[0]+=r[11];
goto P_0c03f6d8;
P_0c03f6d8: /* original 6302, guest PC 0x0c03f6d8 */
if(!s->budget--) { s->failed_pc=0x0c03f6d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c03f6da;
P_0c03f6da: /* original 73ff, guest PC 0x0c03f6da */
if(!s->budget--) { s->failed_pc=0x0c03f6dau; return 0; }
r[3]+=0xffffffffu;
goto P_0c03f6dc;
P_0c03f6dc: /* original 2032, guest PC 0x0c03f6dc */
if(!s->budget--) { s->failed_pc=0x0c03f6dcu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c03f6de;
P_0c03f6de: /* original 61e2, guest PC 0x0c03f6de */
if(!s->budget--) { s->failed_pc=0x0c03f6deu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f6e0;
P_0c03f6e0: /* original 31bc, guest PC 0x0c03f6e0 */
if(!s->budget--) { s->failed_pc=0x0c03f6e0u; return 0; }
r[1]+=r[11];
goto P_0c03f6e2;
P_0c03f6e2: /* original 6312, guest PC 0x0c03f6e2 */
if(!s->budget--) { s->failed_pc=0x0c03f6e2u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03f6e4;
P_0c03f6e4: /* original 2338, guest PC 0x0c03f6e4 */
if(!s->budget--) { s->failed_pc=0x0c03f6e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f6e6;
P_0c03f6e6: /* original 8b28, guest PC 0x0c03f6e6 */
if(!s->budget--) { s->failed_pc=0x0c03f6e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f73a; }
goto P_0c03f6e8;
P_0c03f6e8: /* original 63e2, guest PC 0x0c03f6e8 */
if(!s->budget--) { s->failed_pc=0x0c03f6e8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f6ea;
P_0c03f6ea: /* original 33bc, guest PC 0x0c03f6ea */
if(!s->budget--) { s->failed_pc=0x0c03f6eau; return 0; }
r[3]+=r[11];
goto P_0c03f6ec;
P_0c03f6ec: /* original 5131, guest PC 0x0c03f6ec */
if(!s->budget--) { s->failed_pc=0x0c03f6ecu; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c03f6ee;
P_0c03f6ee: /* original e33c, guest PC 0x0c03f6ee */
if(!s->budget--) { s->failed_pc=0x0c03f6eeu; return 0; }
r[3]=0x0000003cu;
goto P_0c03f6f0;
P_0c03f6f0: /* original 0137, guest PC 0x0c03f6f0 */
if(!s->budget--) { s->failed_pc=0x0c03f6f0u; return 0; }
r[19]=r[1]*r[3];
goto P_0c03f6f2;
P_0c03f6f2: /* original 1f12, guest PC 0x0c03f6f2 */
if(!s->budget--) { s->failed_pc=0x0c03f6f2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c03f6f4;
P_0c03f6f4: /* original 61c2, guest PC 0x0c03f6f4 */
if(!s->budget--) { s->failed_pc=0x0c03f6f4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c03f6f6;
P_0c03f6f6: /* original 0a1a, guest PC 0x0c03f6f6 */
if(!s->budget--) { s->failed_pc=0x0c03f6f6u; return 0; }
r[10]=r[19];
goto P_0c03f6f8;
P_0c03f6f8: /* original 31ac, guest PC 0x0c03f6f8 */
if(!s->budget--) { s->failed_pc=0x0c03f6f8u; return 0; }
r[1]+=r[10];
goto P_0c03f6fa;
P_0c03f6fa: /* original 501a, guest PC 0x0c03f6fa */
if(!s->budget--) { s->failed_pc=0x0c03f6fau; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c03f6fc;
P_0c03f6fc: /* original 2008, guest PC 0x0c03f6fc */
if(!s->budget--) { s->failed_pc=0x0c03f6fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f6fe;
P_0c03f6fe: /* original 8b08, guest PC 0x0c03f6fe */
if(!s->budget--) { s->failed_pc=0x0c03f6feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f712; }
goto P_0c03f700;
P_0c03f700: /* original d12d, guest PC 0x0c03f700 */
if(!s->budget--) { s->failed_pc=0x0c03f700u; return 0; }
r[1]=read(ram,0x0c03f7b8u,4);
goto P_0c03f702;
P_0c03f702: /* original 64c2, guest PC 0x0c03f702 */
if(!s->budget--) { s->failed_pc=0x0c03f702u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c03f704;
P_0c03f704: /* original 410b, guest PC 0x0c03f704 */
if(!s->budget--) { s->failed_pc=0x0c03f704u; return 0; }
target=r[1];
r[16]=code_base|0x0c03f708u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f708u) { target=s->pc; goto dispatch; }
goto P_0c03f708;
P_0c03f706: /* original 34ac, guest PC 0x0c03f706 */
if(!s->budget--) { s->failed_pc=0x0c03f706u; return 0; }
r[4]+=r[10];
goto P_0c03f708;
P_0c03f708: /* original 6403, guest PC 0x0c03f708 */
if(!s->budget--) { s->failed_pc=0x0c03f708u; return 0; }
r[4]=r[0];
goto P_0c03f70a;
P_0c03f70a: /* original 2448, guest PC 0x0c03f70a */
if(!s->budget--) { s->failed_pc=0x0c03f70au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f70c;
P_0c03f70c: /* original 8901, guest PC 0x0c03f70c */
if(!s->budget--) { s->failed_pc=0x0c03f70cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f712; }
goto P_0c03f70e;
P_0c03f70e: /* original e201, guest PC 0x0c03f70e */
if(!s->budget--) { s->failed_pc=0x0c03f70eu; return 0; }
r[2]=0x00000001u;
goto P_0c03f710;
P_0c03f710: /* original 1f23, guest PC 0x0c03f710 */
if(!s->budget--) { s->failed_pc=0x0c03f710u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f712;
P_0c03f712: /* original 63c2, guest PC 0x0c03f712 */
if(!s->budget--) { s->failed_pc=0x0c03f712u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f714;
P_0c03f714: /* original e200, guest PC 0x0c03f714 */
if(!s->budget--) { s->failed_pc=0x0c03f714u; return 0; }
r[2]=0x00000000u;
goto P_0c03f716;
P_0c03f716: /* original 33ac, guest PC 0x0c03f716 */
if(!s->budget--) { s->failed_pc=0x0c03f716u; return 0; }
r[3]+=r[10];
goto P_0c03f718;
P_0c03f718: /* original 132b, guest PC 0x0c03f718 */
if(!s->budget--) { s->failed_pc=0x0c03f718u; return 0; }
write(ram,r[3]+44,r[2],4);
goto P_0c03f71a;
P_0c03f71a: /* original 63c2, guest PC 0x0c03f71a */
if(!s->budget--) { s->failed_pc=0x0c03f71au; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c03f71c;
P_0c03f71c: /* original 33ac, guest PC 0x0c03f71c */
if(!s->budget--) { s->failed_pc=0x0c03f71cu; return 0; }
r[3]+=r[10];
goto P_0c03f71e;
P_0c03f71e: /* original 13de, guest PC 0x0c03f71e */
if(!s->budget--) { s->failed_pc=0x0c03f71eu; return 0; }
write(ram,r[3]+56,r[13],4);
goto P_0c03f720;
P_0c03f720: /* original d326, guest PC 0x0c03f720 */
if(!s->budget--) { s->failed_pc=0x0c03f720u; return 0; }
r[3]=read(ram,0x0c03f7bcu,4);
goto P_0c03f722;
P_0c03f722: /* original 430b, guest PC 0x0c03f722 */
if(!s->budget--) { s->failed_pc=0x0c03f722u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f726u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f726u) { target=s->pc; goto dispatch; }
goto P_0c03f726;
P_0c03f724: /* original 54f2, guest PC 0x0c03f724 */
if(!s->budget--) { s->failed_pc=0x0c03f724u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c03f726;
P_0c03f726: /* original 6082, guest PC 0x0c03f726 */
if(!s->budget--) { s->failed_pc=0x0c03f726u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f728;
P_0c03f728: /* original 6a93, guest PC 0x0c03f728 */
if(!s->budget--) { s->failed_pc=0x0c03f728u; return 0; }
r[10]=r[9];
goto P_0c03f72a;
P_0c03f72a: /* original 4a00, guest PC 0x0c03f72a */
if(!s->budget--) { s->failed_pc=0x0c03f72au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f72c;
P_0c03f72c: /* original b338, guest PC 0x0c03f72c */
if(!s->budget--) { s->failed_pc=0x0c03f72cu; return 0; }
target=code_base|0x0c03fda0u; r[16]=code_base|0x0c03f730u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f730u) { target=s->pc; goto dispatch; }
goto P_0c03f730;
P_0c03f72e: /* original 04ad, guest PC 0x0c03f72e */
if(!s->budget--) { s->failed_pc=0x0c03f72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c03f730;
P_0c03f730: /* original 62e2, guest PC 0x0c03f730 */
if(!s->budget--) { s->failed_pc=0x0c03f730u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f732;
P_0c03f732: /* original 32bc, guest PC 0x0c03f732 */
if(!s->budget--) { s->failed_pc=0x0c03f732u; return 0; }
r[2]+=r[11];
goto P_0c03f734;
P_0c03f734: /* original 12d1, guest PC 0x0c03f734 */
if(!s->budget--) { s->failed_pc=0x0c03f734u; return 0; }
write(ram,r[2]+4,r[13],4);
goto P_0c03f736;
P_0c03f736: /* original 6082, guest PC 0x0c03f736 */
if(!s->budget--) { s->failed_pc=0x0c03f736u; return 0; }
tmp=read(ram,r[8],4);
r[0]=tmp;
goto P_0c03f738;
P_0c03f738: /* original 0ad5, guest PC 0x0c03f738 */
if(!s->budget--) { s->failed_pc=0x0c03f738u; return 0; }
write(ram,r[10]+r[0],r[13],2);
goto P_0c03f73a;
P_0c03f73a: /* original 63f2, guest PC 0x0c03f73a */
if(!s->budget--) { s->failed_pc=0x0c03f73au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c03f73c;
P_0c03f73c: /* original 7310, guest PC 0x0c03f73c */
if(!s->budget--) { s->failed_pc=0x0c03f73cu; return 0; }
r[3]+=0x00000010u;
goto P_0c03f73e;
P_0c03f73e: /* original 2f32, guest PC 0x0c03f73e */
if(!s->budget--) { s->failed_pc=0x0c03f73eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f740;
P_0c03f740: /* original 52f1, guest PC 0x0c03f740 */
if(!s->budget--) { s->failed_pc=0x0c03f740u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f742;
P_0c03f742: /* original 7201, guest PC 0x0c03f742 */
if(!s->budget--) { s->failed_pc=0x0c03f742u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f744;
P_0c03f744: /* original 1f21, guest PC 0x0c03f744 */
if(!s->budget--) { s->failed_pc=0x0c03f744u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f746;
P_0c03f746: /* original 60f2, guest PC 0x0c03f746 */
if(!s->budget--) { s->failed_pc=0x0c03f746u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f748;
P_0c03f748: /* original 5001, guest PC 0x0c03f748 */
if(!s->budget--) { s->failed_pc=0x0c03f748u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c03f74a;
P_0c03f74a: /* original 88ff, guest PC 0x0c03f74a */
if(!s->budget--) { s->failed_pc=0x0c03f74au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f74c;
P_0c03f74c: /* original 8bb8, guest PC 0x0c03f74c */
if(!s->budget--) { s->failed_pc=0x0c03f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f6c0; }
goto P_0c03f74e;
P_0c03f74e: /* original 50f3, guest PC 0x0c03f74e */
if(!s->budget--) { s->failed_pc=0x0c03f74eu; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c03f750;
P_0c03f750: /* original 7f10, guest PC 0x0c03f750 */
if(!s->budget--) { s->failed_pc=0x0c03f750u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f752;
P_0c03f752: /* original 4f16, guest PC 0x0c03f752 */
if(!s->budget--) { s->failed_pc=0x0c03f752u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f754;
P_0c03f754: /* original 4f26, guest PC 0x0c03f754 */
if(!s->budget--) { s->failed_pc=0x0c03f754u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f756;
P_0c03f756: /* original 68f6, guest PC 0x0c03f756 */
if(!s->budget--) { s->failed_pc=0x0c03f756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f758;
P_0c03f758: /* original 69f6, guest PC 0x0c03f758 */
if(!s->budget--) { s->failed_pc=0x0c03f758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f75a;
P_0c03f75a: /* original 6af6, guest PC 0x0c03f75a */
if(!s->budget--) { s->failed_pc=0x0c03f75au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f75c;
P_0c03f75c: /* original 6bf6, guest PC 0x0c03f75c */
if(!s->budget--) { s->failed_pc=0x0c03f75cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f75e;
P_0c03f75e: /* original 6cf6, guest PC 0x0c03f75e */
if(!s->budget--) { s->failed_pc=0x0c03f75eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f760;
P_0c03f760: /* original 6df6, guest PC 0x0c03f760 */
if(!s->budget--) { s->failed_pc=0x0c03f760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f762;
P_0c03f762: /* original 000b, guest PC 0x0c03f762 */
if(!s->budget--) { s->failed_pc=0x0c03f762u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f764: /* original 6ef6, guest PC 0x0c03f764 */
if(!s->budget--) { s->failed_pc=0x0c03f764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f766u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f766u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
