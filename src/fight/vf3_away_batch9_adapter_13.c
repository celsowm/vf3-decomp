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
int vf3_away_batch9_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06a5e4u: goto P_0c06a5e4;
case 0x0c06a5e6u: goto P_0c06a5e6;
case 0x0c06a5e8u: goto P_0c06a5e8;
case 0x0c06a5eau: goto P_0c06a5ea;
case 0x0c06a5ecu: goto P_0c06a5ec;
case 0x0c06a5eeu: goto P_0c06a5ee;
case 0x0c06a5f0u: goto P_0c06a5f0;
case 0x0c06a5f2u: goto P_0c06a5f2;
case 0x0c06a5f4u: goto P_0c06a5f4;
case 0x0c06a5f6u: goto P_0c06a5f6;
case 0x0c06a5f8u: goto P_0c06a5f8;
case 0x0c06a5fau: goto P_0c06a5fa;
case 0x0c06a5fcu: goto P_0c06a5fc;
case 0x0c06a5feu: goto P_0c06a5fe;
case 0x0c06a600u: goto P_0c06a600;
case 0x0c06a602u: goto P_0c06a602;
case 0x0c06a604u: goto P_0c06a604;
case 0x0c06a606u: goto P_0c06a606;
case 0x0c06a608u: goto P_0c06a608;
case 0x0c06a60au: goto P_0c06a60a;
case 0x0c06a60cu: goto P_0c06a60c;
case 0x0c06a60eu: goto P_0c06a60e;
case 0x0c06a610u: goto P_0c06a610;
case 0x0c06a612u: goto P_0c06a612;
case 0x0c06a614u: goto P_0c06a614;
case 0x0c06a616u: goto P_0c06a616;
case 0x0c06a618u: goto P_0c06a618;
case 0x0c06a61au: goto P_0c06a61a;
case 0x0c06a61cu: goto P_0c06a61c;
case 0x0c06a61eu: goto P_0c06a61e;
case 0x0c06a620u: goto P_0c06a620;
case 0x0c06a622u: goto P_0c06a622;
case 0x0c06a624u: goto P_0c06a624;
case 0x0c06a626u: goto P_0c06a626;
case 0x0c06a628u: goto P_0c06a628;
case 0x0c06a62au: goto P_0c06a62a;
case 0x0c06a62cu: goto P_0c06a62c;
case 0x0c06a62eu: goto P_0c06a62e;
case 0x0c06a630u: goto P_0c06a630;
case 0x0c06a632u: goto P_0c06a632;
case 0x0c06a634u: goto P_0c06a634;
case 0x0c06a636u: goto P_0c06a636;
case 0x0c06a638u: goto P_0c06a638;
case 0x0c06a63au: goto P_0c06a63a;
case 0x0c06a63cu: goto P_0c06a63c;
case 0x0c06a63eu: goto P_0c06a63e;
case 0x0c06a640u: goto P_0c06a640;
case 0x0c06a642u: goto P_0c06a642;
case 0x0c06a644u: goto P_0c06a644;
case 0x0c06a646u: goto P_0c06a646;
case 0x0c06a648u: goto P_0c06a648;
case 0x0c06a64au: goto P_0c06a64a;
case 0x0c06a64cu: goto P_0c06a64c;
case 0x0c06a64eu: goto P_0c06a64e;
case 0x0c06a650u: goto P_0c06a650;
case 0x0c06a652u: goto P_0c06a652;
case 0x0c06a654u: goto P_0c06a654;
case 0x0c06a656u: goto P_0c06a656;
case 0x0c06a658u: goto P_0c06a658;
case 0x0c06a65au: goto P_0c06a65a;
case 0x0c06a65cu: goto P_0c06a65c;
case 0x0c06a65eu: goto P_0c06a65e;
case 0x0c06a660u: goto P_0c06a660;
case 0x0c06a662u: goto P_0c06a662;
case 0x0c06a664u: goto P_0c06a664;
case 0x0c06a666u: goto P_0c06a666;
case 0x0c06a668u: goto P_0c06a668;
case 0x0c06a66au: goto P_0c06a66a;
case 0x0c06a680u: goto P_0c06a680;
case 0x0c06a682u: goto P_0c06a682;
case 0x0c06a684u: goto P_0c06a684;
case 0x0c06a686u: goto P_0c06a686;
case 0x0c06a688u: goto P_0c06a688;
case 0x0c06a68au: goto P_0c06a68a;
case 0x0c06a68cu: goto P_0c06a68c;
case 0x0c06a68eu: goto P_0c06a68e;
case 0x0c06a690u: goto P_0c06a690;
case 0x0c06a692u: goto P_0c06a692;
case 0x0c06a694u: goto P_0c06a694;
case 0x0c06a696u: goto P_0c06a696;
case 0x0c06a698u: goto P_0c06a698;
case 0x0c06a69au: goto P_0c06a69a;
case 0x0c06a69cu: goto P_0c06a69c;
case 0x0c06a69eu: goto P_0c06a69e;
case 0x0c06a6a0u: goto P_0c06a6a0;
case 0x0c06a6a2u: goto P_0c06a6a2;
case 0x0c06a6a4u: goto P_0c06a6a4;
case 0x0c06a6a6u: goto P_0c06a6a6;
case 0x0c06a6a8u: goto P_0c06a6a8;
case 0x0c06a6aau: goto P_0c06a6aa;
case 0x0c06a6acu: goto P_0c06a6ac;
case 0x0c06a6aeu: goto P_0c06a6ae;
case 0x0c06a6b0u: goto P_0c06a6b0;
case 0x0c06a6b2u: goto P_0c06a6b2;
case 0x0c06a6b4u: goto P_0c06a6b4;
case 0x0c06a6b6u: goto P_0c06a6b6;
case 0x0c06a6b8u: goto P_0c06a6b8;
case 0x0c06a6bau: goto P_0c06a6ba;
case 0x0c06a6bcu: goto P_0c06a6bc;
case 0x0c06a6beu: goto P_0c06a6be;
case 0x0c06a6c0u: goto P_0c06a6c0;
case 0x0c06a6c2u: goto P_0c06a6c2;
case 0x0c06a6c4u: goto P_0c06a6c4;
case 0x0c06a6c6u: goto P_0c06a6c6;
case 0x0c06a6c8u: goto P_0c06a6c8;
case 0x0c06a6cau: goto P_0c06a6ca;
case 0x0c06a6ccu: goto P_0c06a6cc;
case 0x0c06a6ceu: goto P_0c06a6ce;
case 0x0c06a6d0u: goto P_0c06a6d0;
case 0x0c06a6d2u: goto P_0c06a6d2;
case 0x0c06a6d4u: goto P_0c06a6d4;
case 0x0c06a6d6u: goto P_0c06a6d6;
case 0x0c06a6d8u: goto P_0c06a6d8;
case 0x0c06a6dau: goto P_0c06a6da;
case 0x0c06a6dcu: goto P_0c06a6dc;
case 0x0c06a6deu: goto P_0c06a6de;
case 0x0c06a6e0u: goto P_0c06a6e0;
case 0x0c06a6e2u: goto P_0c06a6e2;
case 0x0c06a6e4u: goto P_0c06a6e4;
case 0x0c06a6e6u: goto P_0c06a6e6;
case 0x0c06a6e8u: goto P_0c06a6e8;
case 0x0c06a6eau: goto P_0c06a6ea;
case 0x0c06a6ecu: goto P_0c06a6ec;
case 0x0c06a6eeu: goto P_0c06a6ee;
case 0x0c06a6f0u: goto P_0c06a6f0;
case 0x0c06a6f2u: goto P_0c06a6f2;
case 0x0c06a6f4u: goto P_0c06a6f4;
case 0x0c06a6f6u: goto P_0c06a6f6;
case 0x0c06a6f8u: goto P_0c06a6f8;
case 0x0c06a6fau: goto P_0c06a6fa;
case 0x0c06a6fcu: goto P_0c06a6fc;
case 0x0c06a6feu: goto P_0c06a6fe;
case 0x0c06a700u: goto P_0c06a700;
case 0x0c06a702u: goto P_0c06a702;
case 0x0c06a704u: goto P_0c06a704;
case 0x0c06a706u: goto P_0c06a706;
case 0x0c06a708u: goto P_0c06a708;
case 0x0c06a70au: goto P_0c06a70a;
case 0x0c06a70cu: goto P_0c06a70c;
case 0x0c06a70eu: goto P_0c06a70e;
case 0x0c06a710u: goto P_0c06a710;
case 0x0c06a712u: goto P_0c06a712;
case 0x0c06a714u: goto P_0c06a714;
case 0x0c06a716u: goto P_0c06a716;
case 0x0c06a718u: goto P_0c06a718;
case 0x0c06a71au: goto P_0c06a71a;
case 0x0c06a71cu: goto P_0c06a71c;
case 0x0c06a71eu: goto P_0c06a71e;
case 0x0c06a720u: goto P_0c06a720;
case 0x0c06a722u: goto P_0c06a722;
case 0x0c06a724u: goto P_0c06a724;
case 0x0c06a726u: goto P_0c06a726;
case 0x0c06a728u: goto P_0c06a728;
case 0x0c06a72au: goto P_0c06a72a;
case 0x0c06a72cu: goto P_0c06a72c;
case 0x0c06a72eu: goto P_0c06a72e;
case 0x0c06a730u: goto P_0c06a730;
case 0x0c06a732u: goto P_0c06a732;
case 0x0c06a734u: goto P_0c06a734;
case 0x0c06a736u: goto P_0c06a736;
case 0x0c06a738u: goto P_0c06a738;
case 0x0c06a73au: goto P_0c06a73a;
case 0x0c06a73cu: goto P_0c06a73c;
case 0x0c06a73eu: goto P_0c06a73e;
case 0x0c06a740u: goto P_0c06a740;
case 0x0c06a742u: goto P_0c06a742;
case 0x0c06a744u: goto P_0c06a744;
case 0x0c06a746u: goto P_0c06a746;
case 0x0c06a748u: goto P_0c06a748;
case 0x0c06a74au: goto P_0c06a74a;
case 0x0c06a74cu: goto P_0c06a74c;
case 0x0c06a74eu: goto P_0c06a74e;
case 0x0c06a750u: goto P_0c06a750;
case 0x0c06a752u: goto P_0c06a752;
case 0x0c06a754u: goto P_0c06a754;
case 0x0c06a756u: goto P_0c06a756;
case 0x0c06a758u: goto P_0c06a758;
case 0x0c06a75au: goto P_0c06a75a;
case 0x0c06a75cu: goto P_0c06a75c;
case 0x0c06a75eu: goto P_0c06a75e;
case 0x0c06a760u: goto P_0c06a760;
case 0x0c06a762u: goto P_0c06a762;
case 0x0c06a764u: goto P_0c06a764;
case 0x0c06a766u: goto P_0c06a766;
case 0x0c06a768u: goto P_0c06a768;
case 0x0c06a76au: goto P_0c06a76a;
case 0x0c06a76cu: goto P_0c06a76c;
case 0x0c06a76eu: goto P_0c06a76e;
case 0x0c06a770u: goto P_0c06a770;
case 0x0c06a772u: goto P_0c06a772;
case 0x0c06a774u: goto P_0c06a774;
case 0x0c06a776u: goto P_0c06a776;
case 0x0c06a778u: goto P_0c06a778;
case 0x0c06a77au: goto P_0c06a77a;
case 0x0c06a77cu: goto P_0c06a77c;
case 0x0c06a77eu: goto P_0c06a77e;
case 0x0c06a780u: goto P_0c06a780;
case 0x0c06a782u: goto P_0c06a782;
case 0x0c06a784u: goto P_0c06a784;
case 0x0c06a786u: goto P_0c06a786;
case 0x0c06a788u: goto P_0c06a788;
case 0x0c06a78au: goto P_0c06a78a;
case 0x0c06a78cu: goto P_0c06a78c;
case 0x0c06a78eu: goto P_0c06a78e;
case 0x0c06a790u: goto P_0c06a790;
case 0x0c06a792u: goto P_0c06a792;
case 0x0c06a794u: goto P_0c06a794;
case 0x0c06a796u: goto P_0c06a796;
case 0x0c06a798u: goto P_0c06a798;
case 0x0c06a79au: goto P_0c06a79a;
case 0x0c06a79cu: goto P_0c06a79c;
case 0x0c06a79eu: goto P_0c06a79e;
case 0x0c06a7a0u: goto P_0c06a7a0;
case 0x0c06a7a2u: goto P_0c06a7a2;
case 0x0c06a7a4u: goto P_0c06a7a4;
case 0x0c06a7a6u: goto P_0c06a7a6;
case 0x0c06a7a8u: goto P_0c06a7a8;
case 0x0c06a7aau: goto P_0c06a7aa;
case 0x0c06a7d0u: goto P_0c06a7d0;
case 0x0c06a7d2u: goto P_0c06a7d2;
case 0x0c06a7d4u: goto P_0c06a7d4;
case 0x0c06a7d6u: goto P_0c06a7d6;
case 0x0c06a7d8u: goto P_0c06a7d8;
case 0x0c06a7dau: goto P_0c06a7da;
case 0x0c06a7dcu: goto P_0c06a7dc;
case 0x0c06a7deu: goto P_0c06a7de;
case 0x0c06a7e0u: goto P_0c06a7e0;
case 0x0c06a7e2u: goto P_0c06a7e2;
case 0x0c06a7e4u: goto P_0c06a7e4;
case 0x0c06a7e6u: goto P_0c06a7e6;
case 0x0c06a7e8u: goto P_0c06a7e8;
case 0x0c06a7eau: goto P_0c06a7ea;
case 0x0c06a7ecu: goto P_0c06a7ec;
case 0x0c06a7eeu: goto P_0c06a7ee;
case 0x0c06a7f0u: goto P_0c06a7f0;
case 0x0c06a7f2u: goto P_0c06a7f2;
case 0x0c06a7f4u: goto P_0c06a7f4;
case 0x0c06a7f6u: goto P_0c06a7f6;
case 0x0c06a7f8u: goto P_0c06a7f8;
case 0x0c06a7fau: goto P_0c06a7fa;
case 0x0c06a7fcu: goto P_0c06a7fc;
case 0x0c06a7feu: goto P_0c06a7fe;
case 0x0c06a800u: goto P_0c06a800;
case 0x0c06a802u: goto P_0c06a802;
case 0x0c06a804u: goto P_0c06a804;
case 0x0c06a806u: goto P_0c06a806;
case 0x0c06a808u: goto P_0c06a808;
case 0x0c06a80au: goto P_0c06a80a;
case 0x0c06a80cu: goto P_0c06a80c;
case 0x0c06a80eu: goto P_0c06a80e;
case 0x0c06a810u: goto P_0c06a810;
case 0x0c06a812u: goto P_0c06a812;
case 0x0c06a814u: goto P_0c06a814;
case 0x0c06a816u: goto P_0c06a816;
case 0x0c06a818u: goto P_0c06a818;
case 0x0c06a81au: goto P_0c06a81a;
case 0x0c06a81cu: goto P_0c06a81c;
case 0x0c06a81eu: goto P_0c06a81e;
case 0x0c06a820u: goto P_0c06a820;
case 0x0c06a822u: goto P_0c06a822;
case 0x0c06a824u: goto P_0c06a824;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06a5e4: /* original 2fe6, guest PC 0x0c06a5e4 */
if(!s->budget--) { s->failed_pc=0x0c06a5e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a5e6;
P_0c06a5e6: /* original 2fd6, guest PC 0x0c06a5e6 */
if(!s->budget--) { s->failed_pc=0x0c06a5e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a5e8;
P_0c06a5e8: /* original 2fc6, guest PC 0x0c06a5e8 */
if(!s->budget--) { s->failed_pc=0x0c06a5e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a5ea;
P_0c06a5ea: /* original 2fb6, guest PC 0x0c06a5ea */
if(!s->budget--) { s->failed_pc=0x0c06a5eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a5ec;
P_0c06a5ec: /* original 2fa6, guest PC 0x0c06a5ec */
if(!s->budget--) { s->failed_pc=0x0c06a5ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a5ee;
P_0c06a5ee: /* original 4f22, guest PC 0x0c06a5ee */
if(!s->budget--) { s->failed_pc=0x0c06a5eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a5f0;
P_0c06a5f0: /* original de1f, guest PC 0x0c06a5f0 */
if(!s->budget--) { s->failed_pc=0x0c06a5f0u; return 0; }
r[14]=read(ram,0x0c06a670u,4);
goto P_0c06a5f2;
P_0c06a5f2: /* original da20, guest PC 0x0c06a5f2 */
if(!s->budget--) { s->failed_pc=0x0c06a5f2u; return 0; }
r[10]=read(ram,0x0c06a674u,4);
goto P_0c06a5f4;
P_0c06a5f4: /* original 64e3, guest PC 0x0c06a5f4 */
if(!s->budget--) { s->failed_pc=0x0c06a5f4u; return 0; }
r[4]=r[14];
goto P_0c06a5f6;
P_0c06a5f6: /* original 7ffc, guest PC 0x0c06a5f6 */
if(!s->budget--) { s->failed_pc=0x0c06a5f6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06a5f8;
P_0c06a5f8: /* original 4a0b, guest PC 0x0c06a5f8 */
if(!s->budget--) { s->failed_pc=0x0c06a5f8u; return 0; }
target=r[10];
r[16]=code_base|0x0c06a5fcu;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a5fcu) { target=s->pc; goto dispatch; }
goto P_0c06a5fc;
P_0c06a5fa: /* original 741c, guest PC 0x0c06a5fa */
if(!s->budget--) { s->failed_pc=0x0c06a5fau; return 0; }
r[4]+=0x0000001cu;
goto P_0c06a5fc;
P_0c06a5fc: /* original db1e, guest PC 0x0c06a5fc */
if(!s->budget--) { s->failed_pc=0x0c06a5fcu; return 0; }
r[11]=read(ram,0x0c06a678u,4);
goto P_0c06a5fe;
P_0c06a5fe: /* original 64e3, guest PC 0x0c06a5fe */
if(!s->budget--) { s->failed_pc=0x0c06a5feu; return 0; }
r[4]=r[14];
goto P_0c06a600;
P_0c06a600: /* original 6503, guest PC 0x0c06a600 */
if(!s->budget--) { s->failed_pc=0x0c06a600u; return 0; }
r[5]=r[0];
goto P_0c06a602;
P_0c06a602: /* original 6d03, guest PC 0x0c06a602 */
if(!s->budget--) { s->failed_pc=0x0c06a602u; return 0; }
r[13]=r[0];
goto P_0c06a604;
P_0c06a604: /* original 4b0b, guest PC 0x0c06a604 */
if(!s->budget--) { s->failed_pc=0x0c06a604u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a608u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a608u) { target=s->pc; goto dispatch; }
goto P_0c06a608;
P_0c06a606: /* original 7420, guest PC 0x0c06a606 */
if(!s->budget--) { s->failed_pc=0x0c06a606u; return 0; }
r[4]+=0x00000020u;
goto P_0c06a608;
P_0c06a608: /* original 9430, guest PC 0x0c06a608 */
if(!s->budget--) { s->failed_pc=0x0c06a608u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a66cu,2);
goto P_0c06a60a;
P_0c06a60a: /* original 4a0b, guest PC 0x0c06a60a */
if(!s->budget--) { s->failed_pc=0x0c06a60au; return 0; }
target=r[10];
r[16]=code_base|0x0c06a60eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a60eu) { target=s->pc; goto dispatch; }
goto P_0c06a60e;
P_0c06a60c: /* original 34ec, guest PC 0x0c06a60c */
if(!s->budget--) { s->failed_pc=0x0c06a60cu; return 0; }
r[4]+=r[14];
goto P_0c06a60e;
P_0c06a60e: /* original e500, guest PC 0x0c06a60e */
if(!s->budget--) { s->failed_pc=0x0c06a60eu; return 0; }
r[5]=0x00000000u;
goto P_0c06a610;
P_0c06a610: /* original 2f02, guest PC 0x0c06a610 */
if(!s->budget--) { s->failed_pc=0x0c06a610u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a612;
P_0c06a612: /* original 942b, guest PC 0x0c06a612 */
if(!s->budget--) { s->failed_pc=0x0c06a612u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a66cu,2);
goto P_0c06a614;
P_0c06a614: /* original 4b0b, guest PC 0x0c06a614 */
if(!s->budget--) { s->failed_pc=0x0c06a614u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a618u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a618u) { target=s->pc; goto dispatch; }
goto P_0c06a618;
P_0c06a616: /* original 34ec, guest PC 0x0c06a616 */
if(!s->budget--) { s->failed_pc=0x0c06a616u; return 0; }
r[4]+=r[14];
goto P_0c06a618;
P_0c06a618: /* original 64e3, guest PC 0x0c06a618 */
if(!s->budget--) { s->failed_pc=0x0c06a618u; return 0; }
r[4]=r[14];
goto P_0c06a61a;
P_0c06a61a: /* original 4a0b, guest PC 0x0c06a61a */
if(!s->budget--) { s->failed_pc=0x0c06a61au; return 0; }
target=r[10];
r[16]=code_base|0x0c06a61eu;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a61eu) { target=s->pc; goto dispatch; }
goto P_0c06a61e;
P_0c06a61c: /* original 7434, guest PC 0x0c06a61c */
if(!s->budget--) { s->failed_pc=0x0c06a61cu; return 0; }
r[4]+=0x00000034u;
goto P_0c06a61e;
P_0c06a61e: /* original 63f2, guest PC 0x0c06a61e */
if(!s->budget--) { s->failed_pc=0x0c06a61eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a620;
P_0c06a620: /* original 6c03, guest PC 0x0c06a620 */
if(!s->budget--) { s->failed_pc=0x0c06a620u; return 0; }
r[12]=r[0];
goto P_0c06a622;
P_0c06a622: /* original 64e3, guest PC 0x0c06a622 */
if(!s->budget--) { s->failed_pc=0x0c06a622u; return 0; }
r[4]=r[14];
goto P_0c06a624;
P_0c06a624: /* original 3c3c, guest PC 0x0c06a624 */
if(!s->budget--) { s->failed_pc=0x0c06a624u; return 0; }
r[12]+=r[3];
goto P_0c06a626;
P_0c06a626: /* original 65c3, guest PC 0x0c06a626 */
if(!s->budget--) { s->failed_pc=0x0c06a626u; return 0; }
r[5]=r[12];
goto P_0c06a628;
P_0c06a628: /* original 4b0b, guest PC 0x0c06a628 */
if(!s->budget--) { s->failed_pc=0x0c06a628u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a62cu;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a62cu) { target=s->pc; goto dispatch; }
goto P_0c06a62c;
P_0c06a62a: /* original 7434, guest PC 0x0c06a62a */
if(!s->budget--) { s->failed_pc=0x0c06a62au; return 0; }
r[4]+=0x00000034u;
goto P_0c06a62c;
P_0c06a62c: /* original 64e3, guest PC 0x0c06a62c */
if(!s->budget--) { s->failed_pc=0x0c06a62cu; return 0; }
r[4]=r[14];
goto P_0c06a62e;
P_0c06a62e: /* original 65c3, guest PC 0x0c06a62e */
if(!s->budget--) { s->failed_pc=0x0c06a62eu; return 0; }
r[5]=r[12];
goto P_0c06a630;
P_0c06a630: /* original 4b0b, guest PC 0x0c06a630 */
if(!s->budget--) { s->failed_pc=0x0c06a630u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a634u;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a634u) { target=s->pc; goto dispatch; }
goto P_0c06a634;
P_0c06a632: /* original 7438, guest PC 0x0c06a632 */
if(!s->budget--) { s->failed_pc=0x0c06a632u; return 0; }
r[4]+=0x00000038u;
goto P_0c06a634;
P_0c06a634: /* original 64e3, guest PC 0x0c06a634 */
if(!s->budget--) { s->failed_pc=0x0c06a634u; return 0; }
r[4]=r[14];
goto P_0c06a636;
P_0c06a636: /* original 3dc8, guest PC 0x0c06a636 */
if(!s->budget--) { s->failed_pc=0x0c06a636u; return 0; }
r[13]-=r[12];
goto P_0c06a638;
P_0c06a638: /* original 4a0b, guest PC 0x0c06a638 */
if(!s->budget--) { s->failed_pc=0x0c06a638u; return 0; }
target=r[10];
r[16]=code_base|0x0c06a63cu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a63cu) { target=s->pc; goto dispatch; }
goto P_0c06a63c;
P_0c06a63a: /* original 7424, guest PC 0x0c06a63a */
if(!s->budget--) { s->failed_pc=0x0c06a63au; return 0; }
r[4]+=0x00000024u;
goto P_0c06a63c;
P_0c06a63c: /* original 4d5a, guest PC 0x0c06a63c */
if(!s->budget--) { s->failed_pc=0x0c06a63cu; return 0; }
r[53]=r[13];
goto P_0c06a63e;
P_0c06a63e: /* original 6403, guest PC 0x0c06a63e */
if(!s->budget--) { s->failed_pc=0x0c06a63eu; return 0; }
r[4]=r[0];
goto P_0c06a640;
P_0c06a640: /* original c70e, guest PC 0x0c06a640 */
if(!s->budget--) { s->failed_pc=0x0c06a640u; return 0; }
r[0]=code_base|0x0006a67cu;
goto P_0c06a642;
P_0c06a642: /* original f508, guest PC 0x0c06a642 */
if(!s->budget--) { s->failed_pc=0x0c06a642u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06a644;
P_0c06a644: /* original f32d, guest PC 0x0c06a644 */
if(!s->budget--) { s->failed_pc=0x0c06a644u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a646;
P_0c06a646: /* original 445a, guest PC 0x0c06a646 */
if(!s->budget--) { s->failed_pc=0x0c06a646u; return 0; }
r[53]=r[4];
goto P_0c06a648;
P_0c06a648: /* original 64e3, guest PC 0x0c06a648 */
if(!s->budget--) { s->failed_pc=0x0c06a648u; return 0; }
r[4]=r[14];
goto P_0c06a64a;
P_0c06a64a: /* original f22d, guest PC 0x0c06a64a */
if(!s->budget--) { s->failed_pc=0x0c06a64au; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a64c;
P_0c06a64c: /* original f63c, guest PC 0x0c06a64c */
if(!s->budget--) { s->failed_pc=0x0c06a64cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06a64e;
P_0c06a64e: /* original f42c, guest PC 0x0c06a64e */
if(!s->budget--) { s->failed_pc=0x0c06a64eu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06a650;
P_0c06a650: /* original f452, guest PC 0x0c06a650 */
if(!s->budget--) { s->failed_pc=0x0c06a650u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06a652;
P_0c06a652: /* original f463, guest PC 0x0c06a652 */
if(!s->budget--) { s->failed_pc=0x0c06a652u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c06a654;
P_0c06a654: /* original f43d, guest PC 0x0c06a654 */
if(!s->budget--) { s->failed_pc=0x0c06a654u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06a656;
P_0c06a656: /* original 055a, guest PC 0x0c06a656 */
if(!s->budget--) { s->failed_pc=0x0c06a656u; return 0; }
r[5]=r[53];
goto P_0c06a658;
P_0c06a658: /* original 4b0b, guest PC 0x0c06a658 */
if(!s->budget--) { s->failed_pc=0x0c06a658u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a65cu;
r[4]+=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a65cu) { target=s->pc; goto dispatch; }
goto P_0c06a65c;
P_0c06a65a: /* original 743c, guest PC 0x0c06a65a */
if(!s->budget--) { s->failed_pc=0x0c06a65au; return 0; }
r[4]+=0x0000003cu;
goto P_0c06a65c;
P_0c06a65c: /* original 7f04, guest PC 0x0c06a65c */
if(!s->budget--) { s->failed_pc=0x0c06a65cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06a65e;
P_0c06a65e: /* original 4f26, guest PC 0x0c06a65e */
if(!s->budget--) { s->failed_pc=0x0c06a65eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a660;
P_0c06a660: /* original 6af6, guest PC 0x0c06a660 */
if(!s->budget--) { s->failed_pc=0x0c06a660u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a662;
P_0c06a662: /* original 6bf6, guest PC 0x0c06a662 */
if(!s->budget--) { s->failed_pc=0x0c06a662u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a664;
P_0c06a664: /* original 6cf6, guest PC 0x0c06a664 */
if(!s->budget--) { s->failed_pc=0x0c06a664u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a666;
P_0c06a666: /* original 6df6, guest PC 0x0c06a666 */
if(!s->budget--) { s->failed_pc=0x0c06a666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a668;
P_0c06a668: /* original 000b, guest PC 0x0c06a668 */
if(!s->budget--) { s->failed_pc=0x0c06a668u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a66a: /* original 6ef6, guest PC 0x0c06a66a */
if(!s->budget--) { s->failed_pc=0x0c06a66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06a66cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a66cu; return 0; } return 1;
P_0c06a680: /* original 2fe6, guest PC 0x0c06a680 */
if(!s->budget--) { s->failed_pc=0x0c06a680u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a682;
P_0c06a682: /* original 2fd6, guest PC 0x0c06a682 */
if(!s->budget--) { s->failed_pc=0x0c06a682u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a684;
P_0c06a684: /* original 2fc6, guest PC 0x0c06a684 */
if(!s->budget--) { s->failed_pc=0x0c06a684u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a686;
P_0c06a686: /* original 2fb6, guest PC 0x0c06a686 */
if(!s->budget--) { s->failed_pc=0x0c06a686u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a688;
P_0c06a688: /* original 2fa6, guest PC 0x0c06a688 */
if(!s->budget--) { s->failed_pc=0x0c06a688u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a68a;
P_0c06a68a: /* original 2f96, guest PC 0x0c06a68a */
if(!s->budget--) { s->failed_pc=0x0c06a68au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a68c;
P_0c06a68c: /* original 2f86, guest PC 0x0c06a68c */
if(!s->budget--) { s->failed_pc=0x0c06a68cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a68e;
P_0c06a68e: /* original 4f22, guest PC 0x0c06a68e */
if(!s->budget--) { s->failed_pc=0x0c06a68eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a690;
P_0c06a690: /* original d549, guest PC 0x0c06a690 */
if(!s->budget--) { s->failed_pc=0x0c06a690u; return 0; }
r[5]=read(ram,0x0c06a7b8u,4);
goto P_0c06a692;
P_0c06a692: /* original 948b, guest PC 0x0c06a692 */
if(!s->budget--) { s->failed_pc=0x0c06a692u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a7acu,2);
goto P_0c06a694;
P_0c06a694: /* original db47, guest PC 0x0c06a694 */
if(!s->budget--) { s->failed_pc=0x0c06a694u; return 0; }
r[11]=read(ram,0x0c06a7b4u,4);
goto P_0c06a696;
P_0c06a696: /* original 7fe8, guest PC 0x0c06a696 */
if(!s->budget--) { s->failed_pc=0x0c06a696u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c06a698;
P_0c06a698: /* original de45, guest PC 0x0c06a698 */
if(!s->budget--) { s->failed_pc=0x0c06a698u; return 0; }
r[14]=read(ram,0x0c06a7b0u,4);
goto P_0c06a69a;
P_0c06a69a: /* original 4b0b, guest PC 0x0c06a69a */
if(!s->budget--) { s->failed_pc=0x0c06a69au; return 0; }
target=r[11];
r[16]=code_base|0x0c06a69eu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a69eu) { target=s->pc; goto dispatch; }
goto P_0c06a69e;
P_0c06a69c: /* original e601, guest PC 0x0c06a69c */
if(!s->budget--) { s->failed_pc=0x0c06a69cu; return 0; }
r[6]=0x00000001u;
goto P_0c06a69e;
P_0c06a69e: /* original dd47, guest PC 0x0c06a69e */
if(!s->budget--) { s->failed_pc=0x0c06a69eu; return 0; }
r[13]=read(ram,0x0c06a7bcu,4);
goto P_0c06a6a0;
P_0c06a6a0: /* original 64e3, guest PC 0x0c06a6a0 */
if(!s->budget--) { s->failed_pc=0x0c06a6a0u; return 0; }
r[4]=r[14];
goto P_0c06a6a2;
P_0c06a6a2: /* original 4d0b, guest PC 0x0c06a6a2 */
if(!s->budget--) { s->failed_pc=0x0c06a6a2u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6a6u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6a6u) { target=s->pc; goto dispatch; }
goto P_0c06a6a6;
P_0c06a6a4: /* original 7418, guest PC 0x0c06a6a4 */
if(!s->budget--) { s->failed_pc=0x0c06a6a4u; return 0; }
r[4]+=0x00000018u;
goto P_0c06a6a6;
P_0c06a6a6: /* original 64e3, guest PC 0x0c06a6a6 */
if(!s->budget--) { s->failed_pc=0x0c06a6a6u; return 0; }
r[4]=r[14];
goto P_0c06a6a8;
P_0c06a6a8: /* original 2f02, guest PC 0x0c06a6a8 */
if(!s->budget--) { s->failed_pc=0x0c06a6a8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a6aa;
P_0c06a6aa: /* original 4d0b, guest PC 0x0c06a6aa */
if(!s->budget--) { s->failed_pc=0x0c06a6aau; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6aeu;
r[4]+=0x00000014u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6aeu) { target=s->pc; goto dispatch; }
goto P_0c06a6ae;
P_0c06a6ac: /* original 7414, guest PC 0x0c06a6ac */
if(!s->budget--) { s->failed_pc=0x0c06a6acu; return 0; }
r[4]+=0x00000014u;
goto P_0c06a6ae;
P_0c06a6ae: /* original 64e3, guest PC 0x0c06a6ae */
if(!s->budget--) { s->failed_pc=0x0c06a6aeu; return 0; }
r[4]=r[14];
goto P_0c06a6b0;
P_0c06a6b0: /* original 1f01, guest PC 0x0c06a6b0 */
if(!s->budget--) { s->failed_pc=0x0c06a6b0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a6b2;
P_0c06a6b2: /* original 4d0b, guest PC 0x0c06a6b2 */
if(!s->budget--) { s->failed_pc=0x0c06a6b2u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6b6u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6b6u) { target=s->pc; goto dispatch; }
goto P_0c06a6b6;
P_0c06a6b4: /* original 7410, guest PC 0x0c06a6b4 */
if(!s->budget--) { s->failed_pc=0x0c06a6b4u; return 0; }
r[4]+=0x00000010u;
goto P_0c06a6b6;
P_0c06a6b6: /* original 64e3, guest PC 0x0c06a6b6 */
if(!s->budget--) { s->failed_pc=0x0c06a6b6u; return 0; }
r[4]=r[14];
goto P_0c06a6b8;
P_0c06a6b8: /* original 1f05, guest PC 0x0c06a6b8 */
if(!s->budget--) { s->failed_pc=0x0c06a6b8u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c06a6ba;
P_0c06a6ba: /* original 4d0b, guest PC 0x0c06a6ba */
if(!s->budget--) { s->failed_pc=0x0c06a6bau; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6beu;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6beu) { target=s->pc; goto dispatch; }
goto P_0c06a6be;
P_0c06a6bc: /* original 740c, guest PC 0x0c06a6bc */
if(!s->budget--) { s->failed_pc=0x0c06a6bcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06a6be;
P_0c06a6be: /* original 64e3, guest PC 0x0c06a6be */
if(!s->budget--) { s->failed_pc=0x0c06a6beu; return 0; }
r[4]=r[14];
goto P_0c06a6c0;
P_0c06a6c0: /* original 1f04, guest PC 0x0c06a6c0 */
if(!s->budget--) { s->failed_pc=0x0c06a6c0u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c06a6c2;
P_0c06a6c2: /* original 4d0b, guest PC 0x0c06a6c2 */
if(!s->budget--) { s->failed_pc=0x0c06a6c2u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6c6u;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6c6u) { target=s->pc; goto dispatch; }
goto P_0c06a6c6;
P_0c06a6c4: /* original 7408, guest PC 0x0c06a6c4 */
if(!s->budget--) { s->failed_pc=0x0c06a6c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c06a6c6;
P_0c06a6c6: /* original 64e3, guest PC 0x0c06a6c6 */
if(!s->budget--) { s->failed_pc=0x0c06a6c6u; return 0; }
r[4]=r[14];
goto P_0c06a6c8;
P_0c06a6c8: /* original 1f03, guest PC 0x0c06a6c8 */
if(!s->budget--) { s->failed_pc=0x0c06a6c8u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06a6ca;
P_0c06a6ca: /* original 4d0b, guest PC 0x0c06a6ca */
if(!s->budget--) { s->failed_pc=0x0c06a6cau; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6ceu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6ceu) { target=s->pc; goto dispatch; }
goto P_0c06a6ce;
P_0c06a6cc: /* original 7404, guest PC 0x0c06a6cc */
if(!s->budget--) { s->failed_pc=0x0c06a6ccu; return 0; }
r[4]+=0x00000004u;
goto P_0c06a6ce;
P_0c06a6ce: /* original 1f02, guest PC 0x0c06a6ce */
if(!s->budget--) { s->failed_pc=0x0c06a6ceu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06a6d0;
P_0c06a6d0: /* original 4d0b, guest PC 0x0c06a6d0 */
if(!s->budget--) { s->failed_pc=0x0c06a6d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a6d4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6d4u) { target=s->pc; goto dispatch; }
goto P_0c06a6d4;
P_0c06a6d2: /* original 64e3, guest PC 0x0c06a6d2 */
if(!s->budget--) { s->failed_pc=0x0c06a6d2u; return 0; }
r[4]=r[14];
goto P_0c06a6d4;
P_0c06a6d4: /* original 63f2, guest PC 0x0c06a6d4 */
if(!s->budget--) { s->failed_pc=0x0c06a6d4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a6d6;
P_0c06a6d6: /* original 6503, guest PC 0x0c06a6d6 */
if(!s->budget--) { s->failed_pc=0x0c06a6d6u; return 0; }
r[5]=r[0];
goto P_0c06a6d8;
P_0c06a6d8: /* original dc39, guest PC 0x0c06a6d8 */
if(!s->budget--) { s->failed_pc=0x0c06a6d8u; return 0; }
r[12]=read(ram,0x0c06a7c0u,4);
goto P_0c06a6da;
P_0c06a6da: /* original 2f36, guest PC 0x0c06a6da */
if(!s->budget--) { s->failed_pc=0x0c06a6dau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6dc;
P_0c06a6dc: /* original 52f2, guest PC 0x0c06a6dc */
if(!s->budget--) { s->failed_pc=0x0c06a6dcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06a6de;
P_0c06a6de: /* original 2f26, guest PC 0x0c06a6de */
if(!s->budget--) { s->failed_pc=0x0c06a6deu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6e0;
P_0c06a6e0: /* original 53f7, guest PC 0x0c06a6e0 */
if(!s->budget--) { s->failed_pc=0x0c06a6e0u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06a6e2;
P_0c06a6e2: /* original 2f36, guest PC 0x0c06a6e2 */
if(!s->budget--) { s->failed_pc=0x0c06a6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6e4;
P_0c06a6e4: /* original 52f7, guest PC 0x0c06a6e4 */
if(!s->budget--) { s->failed_pc=0x0c06a6e4u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06a6e6;
P_0c06a6e6: /* original 2f26, guest PC 0x0c06a6e6 */
if(!s->budget--) { s->failed_pc=0x0c06a6e6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6e8;
P_0c06a6e8: /* original 53f7, guest PC 0x0c06a6e8 */
if(!s->budget--) { s->failed_pc=0x0c06a6e8u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06a6ea;
P_0c06a6ea: /* original 2f36, guest PC 0x0c06a6ea */
if(!s->budget--) { s->failed_pc=0x0c06a6eau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6ec;
P_0c06a6ec: /* original 52f7, guest PC 0x0c06a6ec */
if(!s->budget--) { s->failed_pc=0x0c06a6ecu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06a6ee;
P_0c06a6ee: /* original 2f26, guest PC 0x0c06a6ee */
if(!s->budget--) { s->failed_pc=0x0c06a6eeu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6f0;
P_0c06a6f0: /* original 2f56, guest PC 0x0c06a6f0 */
if(!s->budget--) { s->failed_pc=0x0c06a6f0u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6f2;
P_0c06a6f2: /* original d334, guest PC 0x0c06a6f2 */
if(!s->budget--) { s->failed_pc=0x0c06a6f2u; return 0; }
r[3]=read(ram,0x0c06a7c4u,4);
goto P_0c06a6f4;
P_0c06a6f4: /* original 945b, guest PC 0x0c06a6f4 */
if(!s->budget--) { s->failed_pc=0x0c06a6f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a7aeu,2);
goto P_0c06a6f6;
P_0c06a6f6: /* original 4c0b, guest PC 0x0c06a6f6 */
if(!s->budget--) { s->failed_pc=0x0c06a6f6u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a6fau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a6fau) { target=s->pc; goto dispatch; }
goto P_0c06a6fa;
P_0c06a6f8: /* original 2f36, guest PC 0x0c06a6f8 */
if(!s->budget--) { s->failed_pc=0x0c06a6f8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a6fa;
P_0c06a6fa: /* original 7f20, guest PC 0x0c06a6fa */
if(!s->budget--) { s->failed_pc=0x0c06a6fau; return 0; }
r[15]+=0x00000020u;
goto P_0c06a6fc;
P_0c06a6fc: /* original 64e3, guest PC 0x0c06a6fc */
if(!s->budget--) { s->failed_pc=0x0c06a6fcu; return 0; }
r[4]=r[14];
goto P_0c06a6fe;
P_0c06a6fe: /* original 1f01, guest PC 0x0c06a6fe */
if(!s->budget--) { s->failed_pc=0x0c06a6feu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a700;
P_0c06a700: /* original 4d0b, guest PC 0x0c06a700 */
if(!s->budget--) { s->failed_pc=0x0c06a700u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a704u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a704u) { target=s->pc; goto dispatch; }
goto P_0c06a704;
P_0c06a702: /* original 7420, guest PC 0x0c06a702 */
if(!s->budget--) { s->failed_pc=0x0c06a702u; return 0; }
r[4]+=0x00000020u;
goto P_0c06a704;
P_0c06a704: /* original 6503, guest PC 0x0c06a704 */
if(!s->budget--) { s->failed_pc=0x0c06a704u; return 0; }
r[5]=r[0];
goto P_0c06a706;
P_0c06a706: /* original 2f02, guest PC 0x0c06a706 */
if(!s->budget--) { s->failed_pc=0x0c06a706u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a708;
P_0c06a708: /* original b2b2, guest PC 0x0c06a708 */
if(!s->budget--) { s->failed_pc=0x0c06a708u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a70cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a70cu) { target=s->pc; goto dispatch; }
goto P_0c06a70c;
P_0c06a70a: /* original 54f1, guest PC 0x0c06a70a */
if(!s->budget--) { s->failed_pc=0x0c06a70au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a70c;
P_0c06a70c: /* original e601, guest PC 0x0c06a70c */
if(!s->budget--) { s->failed_pc=0x0c06a70cu; return 0; }
r[6]=0x00000001u;
goto P_0c06a70e;
P_0c06a70e: /* original 2f02, guest PC 0x0c06a70e */
if(!s->budget--) { s->failed_pc=0x0c06a70eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a710;
P_0c06a710: /* original d52d, guest PC 0x0c06a710 */
if(!s->budget--) { s->failed_pc=0x0c06a710u; return 0; }
r[5]=read(ram,0x0c06a7c8u,4);
goto P_0c06a712;
P_0c06a712: /* original 4b0b, guest PC 0x0c06a712 */
if(!s->budget--) { s->failed_pc=0x0c06a712u; return 0; }
target=r[11];
r[16]=code_base|0x0c06a716u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a716u) { target=s->pc; goto dispatch; }
goto P_0c06a716;
P_0c06a714: /* original 6403, guest PC 0x0c06a714 */
if(!s->budget--) { s->failed_pc=0x0c06a714u; return 0; }
r[4]=r[0];
goto P_0c06a716;
P_0c06a716: /* original 64e3, guest PC 0x0c06a716 */
if(!s->budget--) { s->failed_pc=0x0c06a716u; return 0; }
r[4]=r[14];
goto P_0c06a718;
P_0c06a718: /* original 1f01, guest PC 0x0c06a718 */
if(!s->budget--) { s->failed_pc=0x0c06a718u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a71a;
P_0c06a71a: /* original 4d0b, guest PC 0x0c06a71a */
if(!s->budget--) { s->failed_pc=0x0c06a71au; return 0; }
target=r[13];
r[16]=code_base|0x0c06a71eu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a71eu) { target=s->pc; goto dispatch; }
goto P_0c06a71e;
P_0c06a71c: /* original 7424, guest PC 0x0c06a71c */
if(!s->budget--) { s->failed_pc=0x0c06a71cu; return 0; }
r[4]+=0x00000024u;
goto P_0c06a71e;
P_0c06a71e: /* original 6503, guest PC 0x0c06a71e */
if(!s->budget--) { s->failed_pc=0x0c06a71eu; return 0; }
r[5]=r[0];
goto P_0c06a720;
P_0c06a720: /* original 2f02, guest PC 0x0c06a720 */
if(!s->budget--) { s->failed_pc=0x0c06a720u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a722;
P_0c06a722: /* original b2a5, guest PC 0x0c06a722 */
if(!s->budget--) { s->failed_pc=0x0c06a722u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a726u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a726u) { target=s->pc; goto dispatch; }
goto P_0c06a726;
P_0c06a724: /* original 54f1, guest PC 0x0c06a724 */
if(!s->budget--) { s->failed_pc=0x0c06a724u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a726;
P_0c06a726: /* original 64e3, guest PC 0x0c06a726 */
if(!s->budget--) { s->failed_pc=0x0c06a726u; return 0; }
r[4]=r[14];
goto P_0c06a728;
P_0c06a728: /* original 2f02, guest PC 0x0c06a728 */
if(!s->budget--) { s->failed_pc=0x0c06a728u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a72a;
P_0c06a72a: /* original 4d0b, guest PC 0x0c06a72a */
if(!s->budget--) { s->failed_pc=0x0c06a72au; return 0; }
target=r[13];
r[16]=code_base|0x0c06a72eu;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a72eu) { target=s->pc; goto dispatch; }
goto P_0c06a72e;
P_0c06a72c: /* original 7428, guest PC 0x0c06a72c */
if(!s->budget--) { s->failed_pc=0x0c06a72cu; return 0; }
r[4]+=0x00000028u;
goto P_0c06a72e;
P_0c06a72e: /* original 6503, guest PC 0x0c06a72e */
if(!s->budget--) { s->failed_pc=0x0c06a72eu; return 0; }
r[5]=r[0];
goto P_0c06a730;
P_0c06a730: /* original 1f01, guest PC 0x0c06a730 */
if(!s->budget--) { s->failed_pc=0x0c06a730u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a732;
P_0c06a732: /* original b29d, guest PC 0x0c06a732 */
if(!s->budget--) { s->failed_pc=0x0c06a732u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a736u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a736u) { target=s->pc; goto dispatch; }
goto P_0c06a736;
P_0c06a734: /* original 64f2, guest PC 0x0c06a734 */
if(!s->budget--) { s->failed_pc=0x0c06a734u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a736;
P_0c06a736: /* original 64e3, guest PC 0x0c06a736 */
if(!s->budget--) { s->failed_pc=0x0c06a736u; return 0; }
r[4]=r[14];
goto P_0c06a738;
P_0c06a738: /* original 2f02, guest PC 0x0c06a738 */
if(!s->budget--) { s->failed_pc=0x0c06a738u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a73a;
P_0c06a73a: /* original 4d0b, guest PC 0x0c06a73a */
if(!s->budget--) { s->failed_pc=0x0c06a73au; return 0; }
target=r[13];
r[16]=code_base|0x0c06a73eu;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a73eu) { target=s->pc; goto dispatch; }
goto P_0c06a73e;
P_0c06a73c: /* original 742c, guest PC 0x0c06a73c */
if(!s->budget--) { s->failed_pc=0x0c06a73cu; return 0; }
r[4]+=0x0000002cu;
goto P_0c06a73e;
P_0c06a73e: /* original 6503, guest PC 0x0c06a73e */
if(!s->budget--) { s->failed_pc=0x0c06a73eu; return 0; }
r[5]=r[0];
goto P_0c06a740;
P_0c06a740: /* original 1f01, guest PC 0x0c06a740 */
if(!s->budget--) { s->failed_pc=0x0c06a740u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a742;
P_0c06a742: /* original b295, guest PC 0x0c06a742 */
if(!s->budget--) { s->failed_pc=0x0c06a742u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a746u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a746u) { target=s->pc; goto dispatch; }
goto P_0c06a746;
P_0c06a744: /* original 64f2, guest PC 0x0c06a744 */
if(!s->budget--) { s->failed_pc=0x0c06a744u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a746;
P_0c06a746: /* original 64e3, guest PC 0x0c06a746 */
if(!s->budget--) { s->failed_pc=0x0c06a746u; return 0; }
r[4]=r[14];
goto P_0c06a748;
P_0c06a748: /* original 2f02, guest PC 0x0c06a748 */
if(!s->budget--) { s->failed_pc=0x0c06a748u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a74a;
P_0c06a74a: /* original 4d0b, guest PC 0x0c06a74a */
if(!s->budget--) { s->failed_pc=0x0c06a74au; return 0; }
target=r[13];
r[16]=code_base|0x0c06a74eu;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a74eu) { target=s->pc; goto dispatch; }
goto P_0c06a74e;
P_0c06a74c: /* original 7430, guest PC 0x0c06a74c */
if(!s->budget--) { s->failed_pc=0x0c06a74cu; return 0; }
r[4]+=0x00000030u;
goto P_0c06a74e;
P_0c06a74e: /* original 6503, guest PC 0x0c06a74e */
if(!s->budget--) { s->failed_pc=0x0c06a74eu; return 0; }
r[5]=r[0];
goto P_0c06a750;
P_0c06a750: /* original 1f01, guest PC 0x0c06a750 */
if(!s->budget--) { s->failed_pc=0x0c06a750u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a752;
P_0c06a752: /* original b28d, guest PC 0x0c06a752 */
if(!s->budget--) { s->failed_pc=0x0c06a752u; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a756u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a756u) { target=s->pc; goto dispatch; }
goto P_0c06a756;
P_0c06a754: /* original 64f2, guest PC 0x0c06a754 */
if(!s->budget--) { s->failed_pc=0x0c06a754u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a756;
P_0c06a756: /* original e601, guest PC 0x0c06a756 */
if(!s->budget--) { s->failed_pc=0x0c06a756u; return 0; }
r[6]=0x00000001u;
goto P_0c06a758;
P_0c06a758: /* original 2f02, guest PC 0x0c06a758 */
if(!s->budget--) { s->failed_pc=0x0c06a758u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a75a;
P_0c06a75a: /* original d51b, guest PC 0x0c06a75a */
if(!s->budget--) { s->failed_pc=0x0c06a75au; return 0; }
r[5]=read(ram,0x0c06a7c8u,4);
goto P_0c06a75c;
P_0c06a75c: /* original 4b0b, guest PC 0x0c06a75c */
if(!s->budget--) { s->failed_pc=0x0c06a75cu; return 0; }
target=r[11];
r[16]=code_base|0x0c06a760u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a760u) { target=s->pc; goto dispatch; }
goto P_0c06a760;
P_0c06a75e: /* original 6403, guest PC 0x0c06a75e */
if(!s->budget--) { s->failed_pc=0x0c06a75eu; return 0; }
r[4]=r[0];
goto P_0c06a760;
P_0c06a760: /* original 64e3, guest PC 0x0c06a760 */
if(!s->budget--) { s->failed_pc=0x0c06a760u; return 0; }
r[4]=r[14];
goto P_0c06a762;
P_0c06a762: /* original 1f01, guest PC 0x0c06a762 */
if(!s->budget--) { s->failed_pc=0x0c06a762u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a764;
P_0c06a764: /* original 4d0b, guest PC 0x0c06a764 */
if(!s->budget--) { s->failed_pc=0x0c06a764u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a768u;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a768u) { target=s->pc; goto dispatch; }
goto P_0c06a768;
P_0c06a766: /* original 7438, guest PC 0x0c06a766 */
if(!s->budget--) { s->failed_pc=0x0c06a766u; return 0; }
r[4]+=0x00000038u;
goto P_0c06a768;
P_0c06a768: /* original 6503, guest PC 0x0c06a768 */
if(!s->budget--) { s->failed_pc=0x0c06a768u; return 0; }
r[5]=r[0];
goto P_0c06a76a;
P_0c06a76a: /* original 2f02, guest PC 0x0c06a76a */
if(!s->budget--) { s->failed_pc=0x0c06a76au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a76c;
P_0c06a76c: /* original b280, guest PC 0x0c06a76c */
if(!s->budget--) { s->failed_pc=0x0c06a76cu; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06a770u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a770u) { target=s->pc; goto dispatch; }
goto P_0c06a770;
P_0c06a76e: /* original 54f1, guest PC 0x0c06a76e */
if(!s->budget--) { s->failed_pc=0x0c06a76eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a770;
P_0c06a770: /* original 64e3, guest PC 0x0c06a770 */
if(!s->budget--) { s->failed_pc=0x0c06a770u; return 0; }
r[4]=r[14];
goto P_0c06a772;
P_0c06a772: /* original 6903, guest PC 0x0c06a772 */
if(!s->budget--) { s->failed_pc=0x0c06a772u; return 0; }
r[9]=r[0];
goto P_0c06a774;
P_0c06a774: /* original 4d0b, guest PC 0x0c06a774 */
if(!s->budget--) { s->failed_pc=0x0c06a774u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a778u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a778u) { target=s->pc; goto dispatch; }
goto P_0c06a778;
P_0c06a776: /* original 7448, guest PC 0x0c06a776 */
if(!s->budget--) { s->failed_pc=0x0c06a776u; return 0; }
r[4]+=0x00000048u;
goto P_0c06a778;
P_0c06a778: /* original 64e3, guest PC 0x0c06a778 */
if(!s->budget--) { s->failed_pc=0x0c06a778u; return 0; }
r[4]=r[14];
goto P_0c06a77a;
P_0c06a77a: /* original 6803, guest PC 0x0c06a77a */
if(!s->budget--) { s->failed_pc=0x0c06a77au; return 0; }
r[8]=r[0];
goto P_0c06a77c;
P_0c06a77c: /* original 4d0b, guest PC 0x0c06a77c */
if(!s->budget--) { s->failed_pc=0x0c06a77cu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a780u;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a780u) { target=s->pc; goto dispatch; }
goto P_0c06a780;
P_0c06a77e: /* original 7444, guest PC 0x0c06a77e */
if(!s->budget--) { s->failed_pc=0x0c06a77eu; return 0; }
r[4]+=0x00000044u;
goto P_0c06a780;
P_0c06a780: /* original 64e3, guest PC 0x0c06a780 */
if(!s->budget--) { s->failed_pc=0x0c06a780u; return 0; }
r[4]=r[14];
goto P_0c06a782;
P_0c06a782: /* original 2f02, guest PC 0x0c06a782 */
if(!s->budget--) { s->failed_pc=0x0c06a782u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a784;
P_0c06a784: /* original 4d0b, guest PC 0x0c06a784 */
if(!s->budget--) { s->failed_pc=0x0c06a784u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a788u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a788u) { target=s->pc; goto dispatch; }
goto P_0c06a788;
P_0c06a786: /* original 7440, guest PC 0x0c06a786 */
if(!s->budget--) { s->failed_pc=0x0c06a786u; return 0; }
r[4]+=0x00000040u;
goto P_0c06a788;
P_0c06a788: /* original 64e3, guest PC 0x0c06a788 */
if(!s->budget--) { s->failed_pc=0x0c06a788u; return 0; }
r[4]=r[14];
goto P_0c06a78a;
P_0c06a78a: /* original 6a03, guest PC 0x0c06a78a */
if(!s->budget--) { s->failed_pc=0x0c06a78au; return 0; }
r[10]=r[0];
goto P_0c06a78c;
P_0c06a78c: /* original 4d0b, guest PC 0x0c06a78c */
if(!s->budget--) { s->failed_pc=0x0c06a78cu; return 0; }
target=r[13];
r[16]=code_base|0x0c06a790u;
r[4]+=0x0000003cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a790u) { target=s->pc; goto dispatch; }
goto P_0c06a790;
P_0c06a78e: /* original 743c, guest PC 0x0c06a78e */
if(!s->budget--) { s->failed_pc=0x0c06a78eu; return 0; }
r[4]+=0x0000003cu;
goto P_0c06a790;
P_0c06a790: /* original 2aa8, guest PC 0x0c06a790 */
if(!s->budget--) { s->failed_pc=0x0c06a790u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c06a792;
P_0c06a792: /* original 8d1d, guest PC 0x0c06a792 */
if(!s->budget--) { s->failed_pc=0x0c06a792u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06a7d0; }
goto P_0c06a796;
P_0c06a794: /* original 6503, guest PC 0x0c06a794 */
if(!s->budget--) { s->failed_pc=0x0c06a794u; return 0; }
r[5]=r[0];
goto P_0c06a796;
P_0c06a796: /* original 2f86, guest PC 0x0c06a796 */
if(!s->budget--) { s->failed_pc=0x0c06a796u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a798;
P_0c06a798: /* original 52f1, guest PC 0x0c06a798 */
if(!s->budget--) { s->failed_pc=0x0c06a798u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06a79a;
P_0c06a79a: /* original 2f26, guest PC 0x0c06a79a */
if(!s->budget--) { s->failed_pc=0x0c06a79au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a79c;
P_0c06a79c: /* original 2fa6, guest PC 0x0c06a79c */
if(!s->budget--) { s->failed_pc=0x0c06a79cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a79e;
P_0c06a79e: /* original 2f56, guest PC 0x0c06a79e */
if(!s->budget--) { s->failed_pc=0x0c06a79eu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7a0;
P_0c06a7a0: /* original d30a, guest PC 0x0c06a7a0 */
if(!s->budget--) { s->failed_pc=0x0c06a7a0u; return 0; }
r[3]=read(ram,0x0c06a7ccu,4);
goto P_0c06a7a2;
P_0c06a7a2: /* original 2f36, guest PC 0x0c06a7a2 */
if(!s->budget--) { s->failed_pc=0x0c06a7a2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7a4;
P_0c06a7a4: /* original 4c0b, guest PC 0x0c06a7a4 */
if(!s->budget--) { s->failed_pc=0x0c06a7a4u; return 0; }
target=r[12];
r[16]=code_base|0x0c06a7a8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a7a8u) { target=s->pc; goto dispatch; }
goto P_0c06a7a8;
P_0c06a7a6: /* original 6493, guest PC 0x0c06a7a6 */
if(!s->budget--) { s->failed_pc=0x0c06a7a6u; return 0; }
r[4]=r[9];
goto P_0c06a7a8;
P_0c06a7a8: /* original a01b, guest PC 0x0c06a7a8 */
if(!s->budget--) { s->failed_pc=0x0c06a7a8u; return 0; }
r[15]+=0x00000014u;
goto P_0c06a7e2;
P_0c06a7aa: /* original 7f14, guest PC 0x0c06a7aa */
if(!s->budget--) { s->failed_pc=0x0c06a7aau; return 0; }
r[15]+=0x00000014u;
if(!vf3_matrix_family(0x0c06a7acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06a7acu; return 0; } return 1;
P_0c06a7d0: /* original 2f86, guest PC 0x0c06a7d0 */
if(!s->budget--) { s->failed_pc=0x0c06a7d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7d2;
P_0c06a7d2: /* original 53f1, guest PC 0x0c06a7d2 */
if(!s->budget--) { s->failed_pc=0x0c06a7d2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06a7d4;
P_0c06a7d4: /* original 2f36, guest PC 0x0c06a7d4 */
if(!s->budget--) { s->failed_pc=0x0c06a7d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7d6;
P_0c06a7d6: /* original 2fa6, guest PC 0x0c06a7d6 */
if(!s->budget--) { s->failed_pc=0x0c06a7d6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7d8;
P_0c06a7d8: /* original d357, guest PC 0x0c06a7d8 */
if(!s->budget--) { s->failed_pc=0x0c06a7d8u; return 0; }
r[3]=read(ram,0x0c06a938u,4);
goto P_0c06a7da;
P_0c06a7da: /* original 2f36, guest PC 0x0c06a7da */
if(!s->budget--) { s->failed_pc=0x0c06a7dau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a7dc;
P_0c06a7dc: /* original 4c0b, guest PC 0x0c06a7dc */
if(!s->budget--) { s->failed_pc=0x0c06a7dcu; return 0; }
target=r[12];
r[16]=code_base|0x0c06a7e0u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a7e0u) { target=s->pc; goto dispatch; }
goto P_0c06a7e0;
P_0c06a7de: /* original 6493, guest PC 0x0c06a7de */
if(!s->budget--) { s->failed_pc=0x0c06a7deu; return 0; }
r[4]=r[9];
goto P_0c06a7e0;
P_0c06a7e0: /* original 7f10, guest PC 0x0c06a7e0 */
if(!s->budget--) { s->failed_pc=0x0c06a7e0u; return 0; }
r[15]+=0x00000010u;
goto P_0c06a7e2;
P_0c06a7e2: /* original 64e3, guest PC 0x0c06a7e2 */
if(!s->budget--) { s->failed_pc=0x0c06a7e2u; return 0; }
r[4]=r[14];
goto P_0c06a7e4;
P_0c06a7e4: /* original 6b03, guest PC 0x0c06a7e4 */
if(!s->budget--) { s->failed_pc=0x0c06a7e4u; return 0; }
r[11]=r[0];
goto P_0c06a7e6;
P_0c06a7e6: /* original 4d0b, guest PC 0x0c06a7e6 */
if(!s->budget--) { s->failed_pc=0x0c06a7e6u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a7eau;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a7eau) { target=s->pc; goto dispatch; }
goto P_0c06a7ea;
P_0c06a7e8: /* original 744c, guest PC 0x0c06a7e8 */
if(!s->budget--) { s->failed_pc=0x0c06a7e8u; return 0; }
r[4]+=0x0000004cu;
goto P_0c06a7ea;
P_0c06a7ea: /* original 6503, guest PC 0x0c06a7ea */
if(!s->budget--) { s->failed_pc=0x0c06a7eau; return 0; }
r[5]=r[0];
goto P_0c06a7ec;
P_0c06a7ec: /* original 2f02, guest PC 0x0c06a7ec */
if(!s->budget--) { s->failed_pc=0x0c06a7ecu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a7ee;
P_0c06a7ee: /* original b295, guest PC 0x0c06a7ee */
if(!s->budget--) { s->failed_pc=0x0c06a7eeu; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a7f2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a7f2u) { target=s->pc; goto dispatch; }
goto P_0c06a7f2;
P_0c06a7f0: /* original 64b3, guest PC 0x0c06a7f0 */
if(!s->budget--) { s->failed_pc=0x0c06a7f0u; return 0; }
r[4]=r[11];
goto P_0c06a7f2;
P_0c06a7f2: /* original 64e3, guest PC 0x0c06a7f2 */
if(!s->budget--) { s->failed_pc=0x0c06a7f2u; return 0; }
r[4]=r[14];
goto P_0c06a7f4;
P_0c06a7f4: /* original 2f02, guest PC 0x0c06a7f4 */
if(!s->budget--) { s->failed_pc=0x0c06a7f4u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a7f6;
P_0c06a7f6: /* original 4d0b, guest PC 0x0c06a7f6 */
if(!s->budget--) { s->failed_pc=0x0c06a7f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a7fau;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a7fau) { target=s->pc; goto dispatch; }
goto P_0c06a7fa;
P_0c06a7f8: /* original 7450, guest PC 0x0c06a7f8 */
if(!s->budget--) { s->failed_pc=0x0c06a7f8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06a7fa;
P_0c06a7fa: /* original 6503, guest PC 0x0c06a7fa */
if(!s->budget--) { s->failed_pc=0x0c06a7fau; return 0; }
r[5]=r[0];
goto P_0c06a7fc;
P_0c06a7fc: /* original 1f01, guest PC 0x0c06a7fc */
if(!s->budget--) { s->failed_pc=0x0c06a7fcu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a7fe;
P_0c06a7fe: /* original b28d, guest PC 0x0c06a7fe */
if(!s->budget--) { s->failed_pc=0x0c06a7feu; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a802u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a802u) { target=s->pc; goto dispatch; }
goto P_0c06a802;
P_0c06a800: /* original 64f2, guest PC 0x0c06a800 */
if(!s->budget--) { s->failed_pc=0x0c06a800u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a802;
P_0c06a802: /* original 64e3, guest PC 0x0c06a802 */
if(!s->budget--) { s->failed_pc=0x0c06a802u; return 0; }
r[4]=r[14];
goto P_0c06a804;
P_0c06a804: /* original 1f01, guest PC 0x0c06a804 */
if(!s->budget--) { s->failed_pc=0x0c06a804u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06a806;
P_0c06a806: /* original 4d0b, guest PC 0x0c06a806 */
if(!s->budget--) { s->failed_pc=0x0c06a806u; return 0; }
target=r[13];
r[16]=code_base|0x0c06a80au;
r[4]+=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a80au) { target=s->pc; goto dispatch; }
goto P_0c06a80a;
P_0c06a808: /* original 7454, guest PC 0x0c06a808 */
if(!s->budget--) { s->failed_pc=0x0c06a808u; return 0; }
r[4]+=0x00000054u;
goto P_0c06a80a;
P_0c06a80a: /* original 6503, guest PC 0x0c06a80a */
if(!s->budget--) { s->failed_pc=0x0c06a80au; return 0; }
r[5]=r[0];
goto P_0c06a80c;
P_0c06a80c: /* original 2f02, guest PC 0x0c06a80c */
if(!s->budget--) { s->failed_pc=0x0c06a80cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a80e;
P_0c06a80e: /* original b285, guest PC 0x0c06a80e */
if(!s->budget--) { s->failed_pc=0x0c06a80eu; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06a812u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06a812u) { target=s->pc; goto dispatch; }
goto P_0c06a812;
P_0c06a810: /* original 54f1, guest PC 0x0c06a810 */
if(!s->budget--) { s->failed_pc=0x0c06a810u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06a812;
P_0c06a812: /* original 7f18, guest PC 0x0c06a812 */
if(!s->budget--) { s->failed_pc=0x0c06a812u; return 0; }
r[15]+=0x00000018u;
goto P_0c06a814;
P_0c06a814: /* original 4f26, guest PC 0x0c06a814 */
if(!s->budget--) { s->failed_pc=0x0c06a814u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a816;
P_0c06a816: /* original 68f6, guest PC 0x0c06a816 */
if(!s->budget--) { s->failed_pc=0x0c06a816u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06a818;
P_0c06a818: /* original 69f6, guest PC 0x0c06a818 */
if(!s->budget--) { s->failed_pc=0x0c06a818u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06a81a;
P_0c06a81a: /* original 6af6, guest PC 0x0c06a81a */
if(!s->budget--) { s->failed_pc=0x0c06a81au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a81c;
P_0c06a81c: /* original 6bf6, guest PC 0x0c06a81c */
if(!s->budget--) { s->failed_pc=0x0c06a81cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a81e;
P_0c06a81e: /* original 6cf6, guest PC 0x0c06a81e */
if(!s->budget--) { s->failed_pc=0x0c06a81eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a820;
P_0c06a820: /* original 6df6, guest PC 0x0c06a820 */
if(!s->budget--) { s->failed_pc=0x0c06a820u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a822;
P_0c06a822: /* original 000b, guest PC 0x0c06a822 */
if(!s->budget--) { s->failed_pc=0x0c06a822u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a824: /* original 6ef6, guest PC 0x0c06a824 */
if(!s->budget--) { s->failed_pc=0x0c06a824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06a826u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
